/*
 * skins.h
 *
 *  Created on: Dec 8, 2023
 *      Author: yvenv
 */

#ifndef DISPLAY_SKINS_H_
#define DISPLAY_SKINS_H_

#include "main.h"
#include "EPD_7in5_V2.h"
#include "GUI_Paint.h"
#include "../../Fonts/fonts.h"
#include "communication.h"


void vStringNr(uint8_t u8StringNr, uint8_t* pu8String_Src, uint8_t* pu8String_Des);

void vPrint_Skin_Office(struct sCommunication* Com);
void vPrint_Skin_Lecture_Room(struct sCommunication* Com);


#endif /* DISPLAY_SKINS_H_ */
