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
#include "scOrder.h"
#include "scColors.h"
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
boolean checkValidStart (struct s_coordinate start);
void convertStringToCoordinate (struct s_coordinate *start, char order [ORDER_ARRAY]);
boolean isStringCoordinate (char order [ORDER_ARRAY]);
void storeStart (struct s_move *move, struct s_coordinate *start);

/***********************************************
*	Code                                       *
***********************************************/

void getStartPosition (struct s_move *move)
{
    boolean validOrder = BFALSE;
    struct s_coordinate start;
    char order [ORDER_ARRAY];

    writeMessageOrderBox ("Give start position", MESSAGE);
    while (!validOrder)
    {
        getStringOrderBox (&order[0], ORDER_LENGTH);
        if (isStringCoordinate (&order[0]))
        {
            convertStringToCoordinate (&start, order);
            validOrder = checkValidStart (start);
        }
        if (!validOrder) { writeMessageOrderBox ("START NOT VALID! Give new", ALARM); }
    }
    
    storeStart (move, &start);
    move->ID = getIDFromPos (start);
}

boolean checkValidStart (struct s_coordinate start)
{
    int pieceID;
    pieceID = getIDFromPos (start);
    if (pieceID == EMPTY_SQUARE)                { return BFALSE; }
    if (getColorFromID (pieceID) != moveColor())  { return BFALSE; }
    return BTRUE;
}

void convertStringToCoordinate (struct s_coordinate *start, char order [ORDER_ARRAY])
{
    order [0] = makeUpperCase ( order [0]);

    start->column = order [0];
    start->row = order [1] - 48;
}

boolean isStringCoordinate (char order [ORDER_ARRAY])
{
    return characterIsLetter (order [0]) && characterIsNumber (order[1]);
}

void storeStart (struct s_move *move, struct s_coordinate *start)
{
    move->start = *start;
}

void getOrder (void)
{
    struct s_move move;
    getStartPosition (&move);
}

void writeMessageOrderBox (string message, int8b mode)
{
    switch (mode)
    {
        case ALARM:
            wattr_set (orderWindow, 0, ALARM, NULL);
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

void getStringOrderBox (char *order, int orderLength)
{
    wattr_set (orderWindow, 0, MAIN, NULL);
    mvwgetnstr (orderWindow, MESSAGE_Y + 2, MESSAGE_X, order, orderLength);
    mvwprintw (orderWindow, MESSAGE_Y + 2, MESSAGE_X, "  ");
    wrefresh (orderWindow);
}