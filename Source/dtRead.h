/*
File Name:   dtRead.h
//
Compiler:    gcc
Author:      Artic42
Description: Header file for data read
Tested on:   Windows Subsystem for Linux
*/

#ifndef DT_READ_H
#define DT_READ_H

#include "lib/Artic42.h"
#include "poolChess.h"

/************************************************
*	Public function prototype                    *
************************************************/

int8b getIDFromPos (struct s_coordinate pos);
boolean isPosEmpty (struct s_coordinate pos);
int8b moveColor (void);
int8b getSquareColor (int8b col, int8b row);
int8b getTypeFromID (int ID);
struct s_coordinate getPosFromID (int ID);
int8b getColorFromID (int ID);
void setPiece2Eaten (int ID);
void setPiecePosition (int ID, struct s_coordinate destination);

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