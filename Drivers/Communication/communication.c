/*
 * communication.c
 *
 *  Created on: Dec 8, 2023
 *      Author: yvenv
 */

#include "communication.h"
#include "jsmn.h"
#include "skins.h"
#include "dhcp.h"

uint8_t u8Socket = 2;
uint8_t bufSize[] = {2, 2, 2, 2};
/*wiz_NetInfo netInfo = { .mac 	= {0x00, 0xaa, 0xcc, 0xcc, 0xcd, 0xff},	// Mac address
						.ip 	= {192, 168, 1, 190},					// IP address
						.sn 	= {255, 255, 255, 0},					// Subnet mask
						.gw 	= {192, 168, 1, 1}};					// Gateway address
						*/
wiz_NetInfo netInfo = { .mac 	= {0x00, 0xaa, 0xcc, 0xcc, 0xcd, 0xaa},	// Mac address
						.ip 	= {0, 0, 0, 0},					// IP address
						.sn 	= {255, 255, 0, 0},					// Subnet mask
						.gw 	= {141, 79, 207, 254},				// Gateway address
						.dhcp   = NETINFO_DHCP
};

uint8_t u8ServerIP[4] = {141,79,71,207};
//uint8_t u8ServerIP[4] = {192,168,1,100};
uint8_t u8ReturnLAN = 0;
uint16_t u16Received_Len = 0;
uint16_t RSR_Len = 0;
uint8_t u8Data_Buffer[512];
uint8_t u8Close = 0;

uint8_t u8Connection_Loop()
{
	if(getSn_SR(u8Socket) == SOCK_ESTABLISHED)
	{
	  u8Pull_Request();
	  u8Waiting_For_Reply();
	}
	else
	{
	  if (u8New_TCP_Socket() == 1)
	  {
		  u8New_TCP_Connetion();
		  u8Pull_Request();
		  u8Waiting_For_Reply();
	  }
	  else
	  {
		  HAL_Delay(2000);
	  }
	}
	return 0;
}

static int jsoneq(const char* json, jsmntok_t* tok, const char* s)
{
    if (tok->type == JSMN_STRING && (int)strlen(s) == tok->end - tok->start && strncmp(json + tok->start, s, tok->end - tok->start) == 0)
    {
        return 0;
    }
    return -1;
}

void cs_sel()
{
	HAL_GPIO_WritePin(CS_ETH_GPIO_Port, CS_ETH_Pin, GPIO_PIN_RESET);
}

void cs_desel()
{
	HAL_GPIO_WritePin(CS_ETH_GPIO_Port, CS_ETH_Pin, GPIO_PIN_SET);
}

uint8_t spi_rb()
{
	uint8_t rbuf;
	HAL_SPI_Receive(&hspi3, &rbuf, 1, 0xFFFFFFFF);
	return rbuf;
}
void spi_wb(uint8_t b)
{
	HAL_SPI_Transmit(&hspi3, &b, 1, 0xFFFFFFFF);
}

void check_phy_link(void)
{
    uint8_t phycfgr = getPHYCFGR();  // PHY-Konfigurationsregister auslesen
    if (phycfgr & PHYCFGR_LNK_ON)
    {
        printf("PHY link is up\n");
    } else
    {
        printf("PHY link is down\n");
    }
}

uint8_t dhcp_process(void)
{
    uint8_t dhcp_status;

    // Starte den DHCP-Prozess
    dhcp_status = DHCP_run();

    if (dhcp_status == DHCP_IP_LEASED)
    {
        printf("DHCP Success: IP leased\n");
        wizchip_getnetinfo(&netInfo); // Netzwerkinformationen holen
        printf("IP: %d.%d.%d.%d\n", netInfo.ip[0], netInfo.ip[1], netInfo.ip[2], netInfo.ip[3]);
    }
    else if (dhcp_status == DHCP_FAILED)
    {
        printf("DHCP failed\n");
    }
    else if (dhcp_status == DHCP_RUNNING)
    {
        printf("DHCP still running...\n");
    }

    return dhcp_status;
}

/*
uint8_t u8Init_Ethernet()
{
	HAL_GPIO_WritePin(RST_ETH_GPIO_Port, RST_ETH_Pin, 1);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(RST_ETH_GPIO_Port, RST_ETH_Pin, 0);
	HAL_Delay(100);
	HAL_GPIO_WritePin(RST_ETH_GPIO_Port, RST_ETH_Pin, 1);
	HAL_Delay(100);
	reg_wizchip_cs_cbfunc(cs_sel, cs_desel);
	reg_wizchip_spi_cbfunc(spi_rb, spi_wb);

	wizchip_init(bufSize, bufSize);

	wizchip_setnetinfo(&netInfo);
	wizchip_getnetinfo(&netInfo);

	return 0;
}*/


uint8_t u8Init_Ethernet()
{
    // Setze den Ethernet-Reset-Pin
    HAL_GPIO_WritePin(RST_ETH_GPIO_Port, RST_ETH_Pin, 1);
    HAL_Delay(1000);
    HAL_GPIO_WritePin(RST_ETH_GPIO_Port, RST_ETH_Pin, 0);
    HAL_Delay(100);
    HAL_GPIO_WritePin(RST_ETH_GPIO_Port, RST_ETH_Pin, 1);
    HAL_Delay(100);

    // Initialisiere CS- und SPI-Funktionen für W5500
    reg_wizchip_cs_cbfunc(cs_sel, cs_desel);
    reg_wizchip_spi_cbfunc(spi_rb, spi_wb);

    // Initialisiere den W5500-Chip
    if (wizchip_init(bufSize, bufSize) != 0)
    {
        printf("W5500 initialization failed\n");
        //return 1;
    }
    HAL_Delay(4000);

    // Setze Netzwerkinformationen (MAC, IP auf 0, DHCP aktivieren)
    wizchip_setnetinfo(&netInfo);
    wizchip_getnetinfo(&netInfo);


    // Initialisiere den DHCP-Prozess
    uint8_t dhcp_buffer[548];
    DHCP_init(0, dhcp_buffer);
    uint8_t dhcp_status = DHCP_FAILED;
    int iFail = 0;
    // DHCP-Prozess-Schleife
    while(dhcp_status != DHCP_IP_LEASED)
    {
    	if(iFail > 10)
    	{
    		  HAL_SuspendTick();
    		  HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 0, RTC_WAKEUPCLOCK_CK_SPRE_16BITS);
    		  __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
    		  HAL_PWR_EnterSTANDBYMode();
    	}
        check_phy_link();  // PHY-Link prüfen
        dhcp_status = dhcp_process();
        HAL_Delay(1000);
        iFail++;
    }

    return 0;
}

uint8_t u8New_TCP_Socket()
{
	int8_t  u8Return = 0;
	if (socket(u8Socket, Sn_MR_TCP, 1234, SF_TCP_NODELAY) == u8Socket)
	{
		u8Return = 1;
	}
	return u8Return;
}

uint8_t u8Close_TCP_Socket()
{
	while(u8Close != SOCK_OK)
	{
	  u8Close = close(u8Socket);
	}
	u8Close = 0;

	HAL_Delay(2000);
	return 0;
}

uint8_t u8New_TCP_Connetion()
{
	while(u8ReturnLAN != SOCK_OK)
	{
	  u8ReturnLAN =  connect(u8Socket, u8ServerIP, 1234);
	}
	u8ReturnLAN = 0;
	return 0;
}

uint8_t u8Waiting_For_Reply()
{
	uint8_t u8Counter = 0;
	uint8_t u8Sock_Established = 1;
	while((u16Received_Len == 0)&&(u8Sock_Established == 1))
	{

		if((RSR_Len = getSn_RX_RSR(u8Socket)) > 0)
		{
		  u16Received_Len = recv(u8Socket, u8Data_Buffer, RSR_Len);
		  u8Use_Data(u8Data_Buffer);
		}
		if (u8Counter > 19)
		{
			if(getSn_SR(u8Socket) != SOCK_ESTABLISHED)
			{
				u8Sock_Established = 0;
				u8Close_TCP_Socket();
			}
			u8Counter = 0;
		}
		HAL_Delay(50);
	    u8Counter++;
	}
	//
	u16Received_Len = 0;
	return 0;
}

uint8_t  u8Pull_Request()
{
	uint8_t cSendString [256] = {0x7d};
	sprintf ((char *)cSendString, (const char *)"{\n \"version\": 1,\n \"msg_type\": 2,\n \"data\": {\n   \"name\": \"%s\",\n   \"nr\": \"%ld\",\n   \"domain\": \"%s\",\n   \"os_version\": \"0.20\",\n   \"type\": \"PoE\",\n   \"volt\": \"V\",\n   \"status\": \"ok\"\n }\n}\n","PoE_Beta", HAL_GetUIDw0(), "aa94229c-e0f8-4a73-9461-a295d0390b7c");
	send(u8Socket,(uint8_t *)cSendString, strlen(cSendString));
	return 0;
}

uint8_t u8Use_Data(uint8_t* u8Data)
{
	HAL_TIM_Base_Stop_IT(&htim2);

	struct sCommunication Com = {0};
    int i;
    int r;
    jsmn_parser p;
    jsmntok_t t[128]; /* We expect no more than 128 tokens */
    jsmn_init(&p);
    r = jsmn_parse(&p, (const char*)u8Data, (const size_t)strlen((const char *)u8Data), t, (const unsigned int)sizeof(t)/sizeof(t[0]));
    for (i = 1; i < r; i++)
    {
        if (jsoneq((const char*)u8Data, &t[i], "msg_type") == 0)
        {
        	uint8_t u8Cache[30] = {0};
        	sprintf((char*)u8Cache,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
        	Com.u8MSG_Type = atoi((const char *)u8Cache);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "sleep_time") == 0)
        {
        	uint8_t u8Cache[30] = {0};
        	sprintf((char*)u8Cache,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);

			uint8_t u8CacheHou[10] = {0};
			uint8_t u8CacheMin[5] = {0};
			uint8_t u8CacheSec[5] = {0};
			sscanf((const char *)u8Cache, "%9[0-9]:%2[0-9]:%2[0-9]", u8CacheHou, u8CacheMin, u8CacheSec);
			Com.u32Sleep_Time = (uint32_t)atoi((const char *)u8CacheSec)+(uint32_t)atoi((const char *)u8CacheMin)*60+(uint32_t)atoi((const char *)u8CacheHou)*3600;
			i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "version") == 0)
        {
        	uint8_t u8Cache[30] = {0};
        	sprintf((char*)u8Cache,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
        	Com.u8Version = (uint8_t)atoi((const char *)u8Cache);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "type") == 0)
        {
        	uint8_t u8Cache[30] = {0};
        	sprintf((char*)u8Cache,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
        	Com.u8Type = (uint8_t)atoi((const char *)u8Cache);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l1") == 0)
        {
        	sprintf((char*)Com.u8L1,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l2") == 0)
        {
        	sprintf((char*)Com.u8L2,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l3") == 0)
        {
        	sprintf((char*)Com.u8L3,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l4") == 0)
        {
        	sprintf((char*)Com.u8L4,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l5") == 0)
        {
        	sprintf((char*)Com.u8L5,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l6") == 0)
        {
        	sprintf((char*)Com.u8L6,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l7") == 0)
        {
        	sprintf((char*)Com.u8L7,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l8") == 0)
        {
        	sprintf((char*)Com.u8L8,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l9") == 0)
        {
        	sprintf((char*)Com.u8L9,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "l10") == 0)
        {
        	sprintf((char*)Com.u8L10,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
            i++;
        }
        else if (jsoneq((const char*)u8Data, &t[i], "g_id") == 0)
        {
        	uint8_t u8Cache[30] = {0};
        	sprintf((char*)u8Cache,"%.*s", t[i + 1].end - t[i + 1].start, u8Data + t[i + 1].start);
        	Com.u8G_ID = (uint8_t)atoi((const char *)u8Cache);
            i++;
        }
    }
    if((Com.u8MSG_Type == 3) && (Com.u8Type == 1))
    {
    	HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 1);
    	HAL_Delay(100);
    	DEV_Module_Init();
    	HAL_Delay(100);
    	EPD_7IN5_V2_Init();
    	vPrint_Skin_Office(&Com);
    	HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 0);
    	DEV_Module_Exit();
    }
    if((Com.u8MSG_Type == 3) && (Com.u8Type == 2))
    {
    	HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 1);
    	HAL_Delay(100);
    	DEV_Module_Init();
    	HAL_Delay(100);
    	EPD_7IN5_V2_Init();
    	vPrint_Skin_Lecture_Room(&Com);
    	HAL_GPIO_WritePin(DISPLAY_POWER_GPIO_Port, DISPLAY_POWER_Pin, 0);
    	DEV_Module_Exit();
    }

    //sleep mode
    if(Com.u8MSG_Type == 3)
    {
    	StandbyStart(Com.u32Sleep_Time);
    }

	return 0;
}
