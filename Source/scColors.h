/*
File Name:   scColors.h
//
Compiler:    gcc
Author:      Artic42
Description: Header file to define all the necessary color values for ncurses
Tested on:   Windows Subsystem for Linux
*/

#ifndef SC_COLORS_H
#define SC_COLORS_H

/************************************************
*	White pieces                                *
************************************************/

#define WH_P_R 607 //155
#define WH_P_B 901 //230
#define WH_P_G 760 //194

/************************************************
*	Black pieces                                *
************************************************/

#define BK_P_R 929 //237
#define BK_P_B 192 //049
#define BK_P_G 490 //125

/************************************************
*	White square                                *
************************************************/

#define WH_S_R 949 //242
#define WH_S_B 949 //242
#define WH_S_G 949 //242

/************************************************
*	Black square                                *
************************************************/

#define BK_S_R 458 //117
#define BK_S_B 458 //117
#define BK_S_G 458 //117

/************************************************
*	Define colors                               *
************************************************/

#define BACKGROUND 15
#define WH_P 10
#define BK_P 11
#define WH_S 12
#define BK_S 13
#define FOREGROUND 14

/************************************************
*	Color pairs                                 *
************************************************/

#define MAIN 10
#define INVERSE 11
#define WH_P_WH_S 12
#define WH_P_BK_S 13
#define BK_P_WH_S 14
#define BK_P_BK_S 15
#define ALARM_PAIR 16
#define WARNING_PAIR 17

#define SHOW_CURSOR 1
#define HIDDEN_CURSOR 0

#endif