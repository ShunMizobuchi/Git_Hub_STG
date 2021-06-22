//キーボードのソースファイル

//ヘッダファイルの読み込み
#include"Keyboard.h"

//グローバル変数
KEYBOARD keyboard;

//関数

/// <summary>
/// キーの入力状態を更新する
/// </summary>
VOID AllKeyUpdate(VOID)
{
	//直前のキーの入力を取っておく
	for (int i = 0; i < KEY_KIND_MAX; i++)
	{
		keyboard.OldAllKeyState[i] = keyboard.AllKeyState[i];
	}

	//全てのキーの入力状態を得る
	GetHitKeyStateAll(keyboard.TempKeyState);

	//押されているキーの時間を更新する
	for (int i = 0; i < KEY_KIND_MAX; i++)
	{
		//キーコードを押しているとき
		if (keyboard.TempKeyState[i] != 0)
		{
			keyboard.AllKeyState[i]++;		//押している時間を加算
		}
		else
		{
			keyboard.AllKeyState[i] = 0;	//押している時間を0に戻す
		}
	}


	return;
}

/// <sumary>
/// キーを押しているか、キーコードで判断する
/// <sumary>
/// <param name="KEY_INPUT_">キーコード</param>
/// <returns>押していたらTRUE</retrns>
BOOL KeyDown(int KEY_INPUT_)
{
	if (
		keyboard.AllKeyState[KEY_INPUT_] != 0			//以前は押していた
		)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

	/// <sumary>
	/// キーを押上げているか、キーコードで判断する
	/// <sumary>
	/// <param name="KEY_INPUT_">キーコード</param>
	/// <returns>上げていたらTRUE</retrns>
	BOOL KeyUp(int KEY_INPUT_)
	{
		if (
			keyboard.OldAllKeyState[KEY_INPUT_] != 0			//以前は押していた
			&& keyboard.AllKeyState[KEY_INPUT_] == 0		//現在は押していない
			)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}

	/// <sumary>
/// キーをクリックしたかどうかで、キーコードで判断する
/// <sumary>
/// <param name="KEY_INPUT_">キーコード</param>
/// <returns>上げていたらTRUE</retrns>
	BOOL KeyClick(int KEY_INPUT_)
	{
		if (
			keyboard.OldAllKeyState[KEY_INPUT_] != 0			//以前は押していた
			&& keyboard.AllKeyState[KEY_INPUT_] == 0		//現在は押していない
			)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}

/// <sumary>
/// キーを押し続けているか、キーコードで判断する
/// <sumary>
/// <param name="KEY_INPUT_">キーコード</param>
/// <param nmae="MIlliTime">キーを押し続けて入りうミリ秒</param>
/// <returns>押していたらTRUE</retrns>
		BOOL KeyDownKeep(int KEY_INPUT_, int MilliTime)
		{
			//1秒は1000ミリ秒
			float MilliSec = 1000.0f;

			//押し続けている時間は、ミリ秒×FPS値
			//)例　1500ミリ秒押す/1000ミリ・→・1.5秒×60FPS = 90
			int UpdateTime = (MilliTime / MilliSec) * 60;

			if (keyboard.AllKeyState[KEY_INPUT_] > UpdateTime)
			{
				return TRUE;		//押し続けている
			}
			else
			{
				return FALSE;		//押し続けていない
			}

		}
