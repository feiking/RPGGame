#ifndef _SHOW_ALL_DISPLAY_FUNC_H_
#define _SHOW_ALL_DISPLAY_FUNC_H_

/* 1. All head file */
#include <ncurses.h>


/* 2. All Micro  */

   /* map Micro */
#define COL_MAP_ARRAY   18
#define ROW_MAP_ARRAY   24


#define PLAYER_IN_MAP    1

#define BARRIER_IN_MAP 2

#define WALL_IN_MAP      3

#define BOSS_IN_MAP      4


#define MAP_1 1

#define MAP_2 2

#define MAP_3 3

#define MAP_4 4

#define MAP_5 5


/* 3. All typdef */


/* 4.global variety */



/* 5.. All function */




/***  login UI ***/


EUserLogChoice Show_OpenLoginGameSelectUI();//选择界面

void Show_RegisterIDUI(U8* userID,U8* userPasswd);//注册界面

EProfession Show_ProfessionSelectUI(); //职业选择界面


void Show_LoginUI(U8* userID,U8* userPasswd);


EModeSelect Show_ModeSelectUI();



/*** display map ***/

void Show_DisplayMap(U32 currentMap);


#endif
