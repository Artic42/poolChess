/*
File Name:   scPieceDraw.c
//
Compiler:    gcc
Author:      Artic42
Description: Functions needed to draw the pieces on the board
Tested on:    Windows Subsystem for Linux
*/

/************************************************
*   Include                                     *
************************************************/

#include "lib/Artic42.h"
#include "poolChess.h"
#include "dtRead.h"
#include "scPieceDraw.h"
#include "scInitialDraw.h"
#include "scColors.h"

/************************************************
*	Private Function Prtotype                   *
************************************************/

void drawPieceWithID (int ID);
void setSquareColor (struct s_coordinate pos, int8b color);
int getPosX (char column);
int getPosY (int8b row);

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

void drawAllPieces (void)
{
    for (int i = 0; i <= 31 ; i++) { drawPieceWithID (i); }
}

void removePiece (struct s_coordinate pos)
{
    int posX = getPosX (pos.column);
    int posY = getPosY (pos.row);
    setSquareColor (pos, WHITE);
    mvwprintw (mainWindow, posY, posX, " ");
    wrefresh (mainWindow);
}

void drawPiece (struct s_coordinate pos, int8b type, int8b color)
{
    int posX = getPosX (pos.column);
    int posY = getPosY (pos.row);
    setSquareColor (pos, color);
    mvwprintw (mainWindow, posY, posX, "%c", type);
    wrefresh (mainWindow);
}

void setSquareColor (struct s_coordinate pos, int8b color)
{
    if ((color == WHITE) && (getSquareColor (pos.column, pos.row) == WHITE))
    {
        wattr_set (mainWindow, 0, WH_P_WH_S, NULL);
    }
    if ((color == WHITE) && (getSquareColor (pos.column, pos.row) == BLACK))
    {
        wattr_set (mainWindow, 0, WH_P_BK_S, NULL);
    }
    if ((color == BLACK) && (getSquareColor (pos.column, pos.row) == WHITE))
    {
        wattr_set (mainWindow, 0, BK_P_WH_S, NULL);
    }
    if ((color == BLACK) && (getSquareColor (pos.column, pos.row) == BLACK))
    {
        wattr_set (mainWindow, 0, BK_P_BK_S, NULL);
    }
}

void drawPieceWithID (int ID)
{
    drawPiece (getPosFromID (ID), getTypeFromID (ID), getColorFromID (ID));
}

int getPosX (char column)
{
    return BOARD_MARGIN_X + ((column - 'A') * SQUARE_WIDTH) + 1;
}

int getPosY (int8b row)
{
    return BOARD_MARGIN_Y + ((8 - row) * SQUARE_HEIGHT) + 1;
}