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

int8b getColorFromID (int ID);
int8b getColorFromPos (struct s_coordinate);
int8b getIDFromPos (struct s_coordinate);

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