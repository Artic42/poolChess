/*
File Name:   scOrder.c
//
Compiler:    gcc
Author:      Artic42
Description: Functions needed to get the movement orders
Tested on:    Windows Subsystem for Linux
*/

/************************************************
*   Include                                     *
************************************************/

#include "lib/Artic42.h"

#include "dtRead.h"
#include "dtValidMove.h"
#include "dtMoves.h"
#include "scOrder.h"
#include "scColors.h"
#include "scInitialDraw.h"
#include "poolChess.h"

/***********************************************
*	Private Constants                          *
***********************************************/

#define ORDER_LENGTH 2
#define ORDER_ARRAY ORDER_LENGTH+1

/***********************************************
*	Private Structures                         *
***********************************************/



/***********************************************
*	Private Variables                          *
***********************************************/


/************************************************
*	Private Function Prtotype                   *
************************************************/

void getStartPosition (struct s_move *move);
boolean getDestinationPosition (struct s_move *move);
boolean checkValidStart (struct s_coordinate start);
boolean checkValidDestination (struct s_coordinate destinaiton);
void convertStringToCoordinate (struct s_coordinate *start, char order [ORDER_ARRAY]);
boolean isStringCoordinate (char order [ORDER_ARRAY]);
void storeStart (struct s_move *move, struct s_coordinate *start);
void storeDestination (struct s_move *move, struct s_coordinate *destination);

/***********************************************
*	Code                                       *
***********************************************/

void getStartPosition (struct s_move *move)
{
    boolean validStart = BFALSE;
    struct s_coordinate start;
    char order [ORDER_ARRAY];

    writeMessageOrderBox ("Give start position", MESSAGE);
    while (!validStart)
    {
        getStringOrderBox (&order[0], ORDER_LENGTH);
        if (isStringCoordinate (&order[0]))
        {
            convertStringToCoordinate (&start, order);
            validStart = checkValidStart (start);
        }
        if (!validStart) { writeMessageOrderBox ("START NOT VALID!", ALARM); }
    }
    
    storeStart (move, &start);
    move->ID = getIDFromPos (start);
    move->movedPieceType = getTypeFromID (move->ID);
}

boolean getDestinationPosition (struct s_move *move)
{
    struct s_coordinate destination;
    char order [ORDER_ARRAY];

    writeMessageOrderBox ("Give destination position", MESSAGE);
    getStringOrderBox (&order[0], ORDER_LENGTH);
    if (isStringCoordinate (&order[0]))
    {
        convertStringToCoordinate (&destination, order);
        if (!checkValidDestination(destination)) { return BFALSE; }
    }
    move->eatenID = getIDFromPos (move->destination);
    determineMoveDirection (&move);
    determineMoveDistance (&move);
    if (!validMove (move)) { return BFALSE; }
    storeDestination (move, &destination);
    return BTRUE;
}

boolean checkValidStart (struct s_coordinate start)
{
    int pieceID;
    pieceID = getIDFromPos (start);
    if (pieceID == EMPTY_SQUARE)                { return BFALSE; }
    if (getColorFromID (pieceID) != moveColor())  { return BFALSE; }
    return BTRUE;
}

boolean checkValidDestination (struct s_coordinate destination)
{
    return !checkValidStart (destination);
}

void convertStringToCoordinate (struct s_coordinate *start, char order [ORDER_ARRAY])
{
    start->column = makeUpperCase ( order [0]);
    start->row = makeCharInt (order [1]);
}

boolean isStringCoordinate (char order [ORDER_ARRAY])
{
    return characterIsLetter (order [0]) && characterIsNumber (order[1]);
}

void storeStart (struct s_move *move, struct s_coordinate *start)
{
    move->start = *start;
}

void storeDestination (struct s_move *move, struct s_coordinate *destination)
{
    move->destination = *destination;
}

void makeMove (void)
{
    boolean validOrder = BFALSE;
    struct s_move move;

    while (!validOrder)
    {
        getStartPosition (&move);
        validOrder = getDestinationPosition(&move);
    }
    movePiece (&move);
}

void writeMessageOrderBox (string message, int8b mode)
{
    deleteMessageOrderBox ();
    switch (mode)
    {
        case ALARM:
            wattr_set (orderWindow, 0, ALARM_PAIR, NULL);
            break;
        case WARNING:
            wattr_set (orderWindow, 0, WARNING_PAIR, NULL);
            break;
        case MESSAGE:
            wattr_set (orderWindow, 0, MAIN, NULL);
            break;
        default:
            return;
    }
    mvwprintw (orderWindow, MESSAGE_Y, MESSAGE_X, message);
    wrefresh (orderWindow);
}

void deleteMessageOrderBox (void)
{
    wattr_set (orderWindow, 0, MAIN, NULL);
    for (int i=-1; i<ORDER_WIDTH-3; i++)
    {
        mvwprintw (orderWindow, MESSAGE_Y, MESSAGE_X+i, " ");
    }
    wrefresh (orderWindow);
}

void getStringOrderBox (char *order, int orderLength)
{
    curs_set (SHOW_CURSOR);
    wattr_set (orderWindow, 0, MAIN, NULL);
    mvwgetnstr (orderWindow, MESSAGE_Y + 2, MESSAGE_X, order, orderLength);
    mvwprintw (orderWindow, MESSAGE_Y + 2, MESSAGE_X, "  ");
    curs_set (HIDDEN_CURSOR);
    wrefresh (orderWindow);
}