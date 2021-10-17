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
