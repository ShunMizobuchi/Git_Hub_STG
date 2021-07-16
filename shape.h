#pragma once



#pragma once


#include "game.h"



struct iPOINT
{
	int x = -1;	//
	int y = -1;	//
};


//
struct MARU
{
	iPOINT center;		//
	int radius;			//
};


extern BOOL CheckCollRectToRect(RECT a, RECT b);								//
extern BOOL CheckColliPOINTToRect(iPOINT pt, RECT r);							//
extern BOOL CheckColliPOINTToMaru(iPOINT pt, MARU m);							//
extern BOOL CheckCollMaruToMaru(MARU maru1, MARU maru2);						//

extern RECT GetRect(int left, int top, int right, int bottom);					//
extern void DrawRect(RECT r, unsigned int color, bool b);						//
extern void DrawMaru(MARU c, unsigned int color, bool b, int thick);			//