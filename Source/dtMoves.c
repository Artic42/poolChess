/*
File Name:   dtMoves.c
//
Compiler:    gcc
Author:      Artic42
Description: Functions needed to move the piece and update data
Tested on:    Windows Subsystem for Linux
*/

/************************************************
*   Include                                     *
************************************************/

#include "lib/Artic42.h"
#include "poolChess.h"
#include "dtRead.h"
#include "dtMoves.h"
#include "scPieceDraw.h"

/************************************************
*	Private Function Prtotype                   *
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

void movePiece (struct s_move *move)
{
    int ID = getIDFromPos (move->start);
    if (ID == EMPTY_SQUARE)
    {
        int eatenID = getIDFromPos (move->destination);
        setPiece2Eaten (eatenID);
    }
    setPiecePosition (ID, move->destination);
    scMovePiece (move->start, move->destination, getTypeFromID(ID), getColorFromID(ID));
    //Store the piece
}