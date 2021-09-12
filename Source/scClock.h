/*
File Name:   scOrder.h
//
Compiler:    gcc
Author:      Artic42
Description: Header file for order manager
Tested on:   Windows Subsystem for Linux
*/

#ifndef SC_CLOCK_H
#define SC_CLOCK_H

/************************************************
*	Public function prototype                    *
************************************************/

void drawClocks (void);
void drawTurn (void);
void drawTime (int8b color);

/***********************************************
*	Public structures                          *
***********************************************/



/***********************************************
*	Public macros                              *
***********************************************/

//ClockWindow
#define CLOCK_POS_Y 2
#define CLOCK_POS_X 37
#define CLOCK_HEIGHT 8
#define CLOCK_WIDTH 28

#define CLOCK_MARGIN_X 3
#define CLOCK_MARGIN_Y 1
#define CLOCK_MARGIN_Y_2ND 3
#define CLOCK_MARGIN_Y_3RD 5

#define CLOCK_MARGIN_BLACK_X 11

/***********************************************
*	Public constants                           *
***********************************************/



/***********************************************
*	Public variables                           *
***********************************************/

#endif