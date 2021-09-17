/*
File Name:   dtValidMove.h
//
Compiler:    gcc
Author:      Artic42
Description: Header file for valid move
Tested on:   Windows Subsystem for Linux
*/

#ifndef DT_VALID_MOVE_H
#define DT_VALID_MOVE_H

#include "lib/Artic42.h"
#include "poolChess.h"

/************************************************
*	Public function prototype                    *
************************************************/

boolean validMove (struct s_move *move);

/***********************************************
*	Public structures                          *
***********************************************/



/***********************************************
*	Public macros                              *
***********************************************/



/***********************************************
*	Public constants                           *
***********************************************/

//Movement direction
#define NO_MOVE 0
#define DIAGONAL_FRONT_RIGHT 1
#define DIAGONAL_FRONT_LEFT 2
#define DIAGONAL_REAR_RIGHT 3
#define DIAGONAL_REAR_LEFT 4
#define STRAIGHT_FRONT 11
#define STRAIGHT_REAR 12
#define STRAIGHT_LEFT 13
#define STRAIGHT_RIGHT 14
#define KNIGHT  15

/***********************************************
*	Public variables                           *
***********************************************/


#endif