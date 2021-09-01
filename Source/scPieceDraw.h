/*
File Name:   scPieceDraw.h
//
Compiler:    gcc
Author:      Artic42
Description: Header file for piece draw
Tested on:   Windows Subsystem for Linux
*/

#ifndef SC_PIECE_DRAW_H
#define SC_PIECE_DRAW_H

#include "lib/Artic42.h"
#include "poolChess.h"

/************************************************
*	Public function prototype                    *
************************************************/

void drawAllPieces (void);
void removePiece (struct s_coordinate pos);
void drawPiece (struct s_coordinate pos, int8b type, int8b color);

/***********************************************
*	Public structures                          *
***********************************************/



/***********************************************
*	Public macros                              *
***********************************************/



/***********************************************
*	Public constants                           *
***********************************************/



/***********************************************
*	Public variables                           *
***********************************************/


#endif