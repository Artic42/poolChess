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
boolean coordinateEqual (struct s_coordinate coor1, struct s_coordinate coor2);
int8b getMoveDirection (struct s_coordinate start, struct s_coordinate destination);
int getMoveModule (struct s_coordinate start, struct s_coordinate destination);

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
#define KNIGHT_MOVE 15

/***********************************************
*	Public variables                           *
***********************************************/


#endif