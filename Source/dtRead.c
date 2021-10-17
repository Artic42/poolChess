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

int8b getDiagonalDirection (int diffCol, int diffRow);
int8b getStraightDirection (int diffCol, int diffRow);

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

int8b moveColor (void)
{
    if (g_s_moves.moveAmount % 2 == 0)  { return WHITE; }
    else                                { return BLACK; }
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

void setPiece2Eaten (int ID)
{
    g_s_pieces[ID].inBoard = BFALSE;
}

void setPiecePosition (int ID, struct s_coordinate destination)
{
    g_s_pieces[ID].Position = destination;
}

boolean coordinateEqual (struct s_coordinate coor1, struct s_coordinate coor2)
{
    return (coor1.row == coor2.row) && (coor1.column == coor2.column);
}

//GetMoveDirection

int8b getMoveDirection (struct s_coordinate start, struct s_coordinate destination)
{
    int diffCol, diffRow, absDiffCol, absDiffRow;

    diffCol = destination.column - start.column;
    diffRow = destination.row - start.row;
    absDiffCol = calculateAbsolute (diffCol);
    absDiffRow = calculateAbsolute (diffRow);

    if (diffCol == 0 && diffRow == 0)
    {
        return NO_MOVE;
    }

    if ((absDiffCol == 2 || absDiffRow == 2) && (absDiffCol == 1 || absDiffRow == 1)) 
    {
        return KNIGHT_MOVE;
    }

    if (absDiffCol == absDiffRow)
    {
        return getDiagonalDirection (diffCol, diffRow);
    }

    if (absDiffCol == 0 || absDiffRow == 0)
    {
        return getStraightDirection (diffCol, diffRow);
    }
    return NO_MOVE;
}

int8b getDiagonalDirection (int diffCol, int diffRow)
{
    if (isNumberPositive (diffCol) && isNumberPositive(diffRow)) { return DIAGONAL_FRONT_RIGHT; }
    if (isNumberNegative (diffCol) && isNumberPositive(diffRow)) { return DIAGONAL_FRONT_LEFT; }
    if (isNumberPositive (diffCol) && isNumberNegative(diffRow)) { return DIAGONAL_REAR_RIGHT; }
    if (isNumberNegative (diffCol) && isNumberNegative(diffRow)) { return DIAGONAL_REAR_LEFT; }
    return NO_MOVE;
}

int8b getStraightDirection (int diffCol, int diffRow)
{
    if (isNumberZero (diffCol))
    {
        if (isNumberPositive (diffRow)) { return STRAIGHT_FRONT; }
        else                            { return STRAIGHT_REAR;  }
    }

    if (isNumberZero (diffRow))
    {
        if (isNumberPositive (diffCol)) { return STRAIGHT_RIGHT; }
        else                            { return STRAIGHT_LEFT;  }
    }
    return NO_MOVE;
}

//GetMoveModule

int getMoveModule (struct s_coordinate start, struct s_coordinate destination)
{
    int absDiffCol = calculateAbsolute (start.column - destination.column);
    int absDiffRow = calculateAbsolute (start.row - destination.row);
    return returnHigher (absDiffCol, absDiffRow);
}