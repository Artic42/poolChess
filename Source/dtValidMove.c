/*
File Name:   dtValidMove.c
//
Compiler:    gcc
Author:      Artic42
Description: Functions needed to know if a move is legal
Tested on:    Windows Subsystem for Linux
*/

/************************************************
*   Include                                     *
************************************************/

#include "lib/Artic42.h"
#include "poolChess.h"
#include "dtValidMove.h"


/************************************************
*	Private Function Prototype                   *
************************************************/



/***********************************************
*	Private Constants                          *
***********************************************/



/***********************************************
*	Private Structures                         *
***********************************************/



/***********************************************
*	Private Variables                          *
***********************************************/



/***********************************************
*	Code                                       *
***********************************************/

boolean validMove (struct s_move *move)
{
    return BTRUE;
}

void determineMoveDirection (struct s_move *move)
{
    int diffColumn = move->destination.column - move->start.column;
    int diffRow = move->destination.row - move->start.row;

    move->direction=NO_MOVE;

    if (intAbsolute(diffColumn) == intAbsolute(diffRow))
    {
        if (diffColumn > 0 && diffRow > 0) { move->direction=DIAGONAL_FRONT_RIGHT; }
        if (diffColumn < 0 && diffRow > 0) { move->direction=DIAGONAL_FRONT_LEFT; }
        if (diffColumn > 0 && diffRow < 0) { move->direction=DIAGONAL_REAR_RIGHT; }
        if (diffColumn < 0 && diffRow < 0) { move->direction=DIAGONAL_REAR_LEFT; }
    }

    if (diffColumn == 0 && diffRow > 0) { move->direction=STRAIGHT_FRONT; }
    if (diffColumn == 0 && diffRow < 0) { move->direction=STRAIGHT_REAR; }
    if (diffColumn > 0 && diffRow == 0) { move->direction=STRAIGHT_RIGHT; }
    if (diffColumn < 0 && diffRow == 0) { move->direction=STRAIGHT_LEFT; }

    if (diffColumn == 1 || diffRow == 1 && diffColumn == 2 || diffRow == 2) { move->direction=KNIGHT; }
}

void determineMoveDistance (struct s_move *move)
{
    int diffColumn = intAbsolute (move->destination.column - move->start.column);
    int diffRow = intAbsolute (move->destination.row - move->start.row);
    return intGiveMax (diffColumn, diffRow);
}