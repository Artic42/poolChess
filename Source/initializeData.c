/*
File Name:   initializeData.c
//
Compiler:    gcc
Author:      Artic42
Description: Functions that take care of the initializations of the necesary global variable of poolChees
Tested on:   Windows Subsystem for Linux
*/

/************************************************
*   Include                                     *
************************************************/

#include "Artic42.h"
#include "initializeData.h"
#include "poolChess.h"

/************************************************
*	Private Function Prtotype                   *
************************************************/

void initWhitesNewGame (void);
void initBlacksNewGame (void);
void initColorsNewGame (void);
void initHistoryNewGame (void);
void createPiece (int ID, int8b type, int8b color, int8b row, char column);

/***********************************************
*	Private Structures                         *
***********************************************/
/***********************************************
*	Private Constants                          *
***********************************************/
/***********************************************
*	Private Variables                          *
***********************************************/
/***********************************************
*	Code                                       *
***********************************************/

void dataInitializeNewGame (void)
{
    initWhitesNewGame ();
    initBlacksNewGame ();
    initColorsNewGame ();
    initHistoryNewGame ();
}

void initWhitesNewGames (void)
{
    for (int i=0; i<=7; i++)
    {
        createPiece (i, PAWN, WHITE, 2,'A' + i);
    }

    createPiece ( 8, ROOK,   WHITE, 1, 'A');
    createPiece ( 9, KNIGHT, WHITE, 1, 'B');
    createPiece (10, BISHOP, WHITE, 1, 'C');
    createPiece (11, QUEEN,  WHITE, 1, 'D');
    createPiece (12, KING,   WHITE, 1, 'E');
    createPiece (13, BISHOP, WHITE, 1, 'F');
    createPiece (14, KNIGHT, WHITE, 1, 'G');
    createPiece (15, ROOK,   WHITE, 1, 'H');
}

void initBlacksNewGames (void)
{
    for (int i=16; i<=23; i++)
    {
        createPiece (i, PAWN, BLACK, 7,'A' + i - 16);
    }

    createPiece (24, ROOK,   BLACK, 8, 'A');
    createPiece (25, KNIGHT, BLACK, 8, 'B');
    createPiece (26, BISHOP, BLACK, 8, 'C');
    createPiece (27, QUEEN,  BLACK, 8, 'D');
    createPiece (28, KING,   BLACK, 8, 'E');
    createPiece (29, BISHOP, BLACK, 8, 'F');
    createPiece (30, KNIGHT, BLACK, 8, 'G');
    createPiece (31, ROOK,   BLACK, 1, 'H');
}

void initColorsNewGame (void)
{
    g_s_white.isHuman = BTRUE;
    g_s_black.isHuman = BTRUE;
}

void initHistoryNewGame (void);
{
    g_s_moves.moveAmount = 0;
    g_s_moves.firstMove = NULL;
    g_s_moves.lastMove = NULL;
}

void createPiece (int ID, int8b type, int8b color, int8b row, char column)
{
    g_s_pieces [ID].type = type;
    g_s_pieces [ID].color = color;
    g_s_pieces [ID].Position.row = row;
    g_s_pieces [ID].Position.column = column;
    g_s_pieces [ID].Moved = BFALSE;
    g_s_pieces [ID].inBoard = BTRUE:
}