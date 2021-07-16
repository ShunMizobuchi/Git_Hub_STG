#pragma once

//マウス処理のヘッダーファイル
//マウス処理のヘッダーファイル


//ゲームのメインヘッダーファイル
#include"game.h"
#include"shape.h"

//マウスのボタン
#define MOUSE_BUTTON_CODE	129		//0×0000～0×0080まで

//マウスの構造体

struct MOUSE 
{
	int InputValue = 0;		//GetMouseInputが入る
	int WheelValue = 0;		//マウスホイールの回転量

	iPOINT Point;			//マウスの座標が入る
	iPOINT Oldpoint;		//マウスの座標（直前）がはいる　

	int OldButton[MOUSE_BUTTON_CODE];		//マウスボタンの入力（直前）が入る
	int Button[MOUSE_BUTTON_CODE];			//マウスのボタンが入る
};


//
extern MOUSE mouse;

extern VOID MouseUpdate(VOID);									//
extern BOOL MouseDown(int MOUSE_INPUT_);						//	
extern BOOL MouseUp(int MOUSE_INPUT_);							//
extern BOOL MouseDownKeep(int MOUSE_INPUT_, int milliTime);		//
extern BOOL MouseClick(int MOUSE_INPUT_);						//
extern VOID MouseDraw(VOID);									//

extern BOOL MouseRectClick(RECT rect, int MOUSE_INPUT_);		//
extern BOOL MouseMaruClick(MARU rect, int MOUSE_INPUT_);		//
