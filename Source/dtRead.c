/*
File Name:   dtRead.c
//
Compiler:    gcc
Author:      Artic42
Description: Functions needed to read data
Tested on:    Windows Subsystem for Linux
*/

/************************************************
*   Include                                     *
************************************************/

#include "lib/Artic42.h"
#include "poolChess.h"
#include "dtRead.h"

/************************************************
*	Private Function Prtotype                   *
************************************************/

boolean coordinateEqual (struct s_coordinate coor1, struct s_coordinate coor2);

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

int8b getIDFromPos (struct s_coordinate pos)
{
    for (int i=0; i<=31; i++)
    {
        if (coordinateEqual(pos, g_s_pieces[i].Position)) { return i; }
    }
    return EMPTY_SQUARE;
}

boolean isPosEmpty (struct s_coordinate pos)
{
    return EMPTY_SQUARE == getIDFromPos (pos);
}

int8b getSquareColor (int8b col, int8b row)
{
    if (col%2 == row%2) { return BLACK; }
    else                { return WHITE; }
}

int8b getTypeFromID (int ID)
{
    return g_s_pieces[ID].type;
}

struct s_coordinate getPosFromID (int ID)
{
    return g_s_pieces[ID].Position;
}

int8b getColorFromID (int ID)
{
    return g_s_pieces[ID].color;
}

boolean coordinateEqual (struct s_coordinate coor1, struct s_coordinate coor2)
{
    return (coor1.row == coor2.row) && (coor1.column && coor2.column);
}