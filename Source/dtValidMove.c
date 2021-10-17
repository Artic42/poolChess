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
#include "dtRead.h"
#include "poolChess.h"
#include "dtValidMove.h"


/************************************************
*	Private Function Prtotype                   *
************************************************/

boolean isDirectionDiagonal (int8b direction);
boolean isDirectionStraight (int8b direction);
boolean isPieceInTheWay (struct s_coordinate start, struct s_coordinate destination, int8b direction);
struct s_coordinate calculateNextCheckingPosition (struct s_coordinate position, int8b direction);
boolean checkPawnValidMove (struct s_move *move);



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

boolean isDirectionDiagonal (int8b direction)
{
    if (direction >= DIAGONAL_FRONT_RIGHT || direction <= DIAGONAL_REAR_LEFT) { return BTRUE; }
    else { return BFALSE; }
}

boolean isDirectionStraight (int8b direction)
{
    if (direction >= STRAIGHT_FRONT || direction <= STRAIGHT_RIGHT) { return BTRUE; }
    else { return BFALSE; }
}

//isPieceInTheWay

boolean isPieceInTheWay (struct s_coordinate start, struct s_coordinate destination, int8b direction)
{
    if (direction == NO_MOVE || direction == KNIGHT_MOVE) { return BTRUE; }

    struct s_coordinate checkingPosition;
    checkingPosition = calculateNextCheckingPosition (start, direction);
    while (!coordinateEqual(checkingPosition, destination))
    {
        if (!isPosEmpty (checkingPosition)) { return BFALSE; }
        checkingPosition = calculateNextCheckingPosition (checkingPosition, direction);
    }
    return BTRUE;
}

struct s_coordinate calculateNextCheckingPosition (struct s_coordinate position, int8b direction)
{ 
    switch (direction)
    {
    case DIAGONAL_FRONT_LEFT:
        position.column--;
        position.row++;
        break;

    case DIAGONAL_FRONT_RIGHT:
        position.column++;
        position.row++;
        break;
    
    case DIAGONAL_REAR_LEFT:
        position.column--;
        position.row--;
        break;

    case DIAGONAL_REAR_RIGHT:
        position.column++;
        position.row--;
        break;

    case STRAIGHT_LEFT:
        position.column--;
        break;

    case STRAIGHT_RIGHT:
        position.column++;
        break;

    case STRAIGHT_FRONT:
        position.row++;
        break;

    case STRAIGHT_REAR:
        position.row--;
        break;
    }
    return position;
}

//ValidMove

boolean validMove (struct s_move *move)
{
    if (move->direction == NO_MOVE) { return BFALSE; }

    switch (move->movedPieceType)
    {
        case PAWN:
            return checkPawnValidMove (move);
        case KNIGHT:
            if (move->direction == KNIGHT_MOVE) { return BTRUE; }
            else                                { return BFALSE;}
        case BISHOP:
            if (isDirectionDiagonal (move->direction) && isPieceInTheWay (move->start, move->destination, move->direction))
            {
                return BTRUE;
            }
            else
            {
                return BFALSE;
            }
        case ROOK:
            if (isDirectionStraight (move->direction) && isPieceInTheWay (move->start, move->destination, move->direction))
            {
                return BTRUE;
            }
            else
            {
                return BFALSE;
            }
        case QUEEN:
            if ((isDirectionDiagonal (move->direction) || isDirectionStraight (move->direction)) && isPieceInTheWay (move->start, move->destination, move->direction))
            {
                return BTRUE;
            }
            else
            {
                return BFALSE;
            }
        case KING:
            if (move->module == 1) { return BTRUE; }
            else                   { return BFALSE;}
    }
    return BTRUE;
}

boolean checkPawnValidMove (struct s_move *move)
{
    if (move->eatenID == EMPTY_SQUARE && isDirectionStraight (move->direction))
    {
        if (move->module == 1) { return BTRUE; }
        if (move->module >= 3) { return BFALSE;}
        if (move->movedPieceColor == WHITE && move->destination.row == 4) {return BTRUE; }
        if (move->movedPieceColor == BLACK && move->destination.row == 5) {return BTRUE; }
    }
    return BFALSE;
}

