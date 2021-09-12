/*
File Name:   scInitialDraw.h
//
Compiler:    gcc
Author:      Artic42
Description: Header file for screen
Tested on:   Windows Subsystem for Linux
*/

#ifndef SC_INITIAL_DRAW_H
#define SC_INITIAL_DRAW_H

#include "lib/Artic42.h"
#include "poolChess.h"

/************************************************
*	Public function prototype                    *
************************************************/

void scInitialDraw (void);

/***********************************************
*	Public structures                          *
***********************************************/



/***********************************************
*	Public macros                              *
***********************************************/



/***********************************************
*	Public constants                           *
***********************************************/

#define SCREEN_HEIGHT 29
#define SCREEN_WIDTH 66

#define SQUARE_HEIGHT 3
#define SQUARE_WIDTH 4

#define BOARD_MARGIN_X 4
#define BOARD_MARGIN_Y 3

#define COLUMN_POS_Y 2
#define LINE_POS_X 2

//AucWindow
#define AUX_POS_Y 10
#define AUX_POS_X 37
#define AUX_HEIGHT 11
#define AUX_WIDTH 28

//OrderWindow
#define ORDER_POS_Y 21
#define ORDER_POS_X 37
#define ORDER_HEIGHT 7
#define ORDER_WIDTH 28

/***********************************************
*	Public variables                           *
***********************************************/

#endif