/*
File Name:   scOrder.h
//
Compiler:    gcc
Author:      Artic42
Description: Header file for order manager
Tested on:   Windows Subsystem for Linux
*/

#ifndef SC_ORDER_H
#define SC_ORDER_H

/************************************************
*	Public function prototype                    *
************************************************/

void makeMove (void);
void writeMessageOrderBox (string message, int8b mode);
void deleteMessageOrderBox (void);
void getStringOrderBox (char *order, int orderLength);

/***********************************************
*	Public structures                          *
***********************************************/



/***********************************************
*	Public macros                              *
***********************************************/



/***********************************************
*	Public constants                           *
***********************************************/

#define ALARM 1
#define WARNING 2
#define MESSAGE 3

#define MESSAGE_Y 2
#define MESSAGE_X 2

/***********************************************
*	Public variables                           *
***********************************************/



#endif