//ヘッダーファイルを読み込み
#include "game.h"
#include "shape.h"
#include "math.h"



/// <summary>
/// 短形領域同士の当たり判定をする関数
/// </summary>
/// <param name="a">領域A</param>
/// <param name="b">領域B</param>
/// <returns></returns>
BOOL CheckCollRectToRect(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;		//当たっている
	}
	
	return FALSE;		//当たっていない
	
}


/// <summary>
/// 四角と点の当たり判定
/// </summary>
/// <param name="pt">iPOINT型の点</param>
/// <param name="r">短形領域</param>
/// <returns></returns>
BOOL CheckColliPOINTToRect(iPOINT pt, RECT r)
{
	if (
		pt.x > r.left && pt.x < r.right		//点のX位置が四角の左右の間にいて
		&& pt.y > r.top && pt.y < r.bottom	//点のY位置が四角の上下の間にいるとき
		)
	{
		return TRUE;
	}

	return FALSE;
}


/// <summary>
/// 円と点の当たり判定
/// </summary>
/// <param name="pt">型の点</param>
/// <param name="m">円領域</param>
/// <returns></returns>
BOOL CheckColliPOINTToMaru(iPOINT pt, MARU m)
{
	//三角形を求める
	float a = pt.x - m.center.x;
	float b = pt.y - m.center.y;
	float c = sqrtf(a * a + b * b);

	//斜辺の長さが、円の半径よりも短いならば、円の中にいる
	if (c <= m.radius)
	{
		return TRUE;
	}

	return FALSE;
}



/// <summary>
/// 円と円の当たり判定
/// </summary>
/// <param name="maru1">円領域１</param>
/// <param name="maru2">円領域２</param>
/// <returns></returns>
BOOL CheckCollMaruToMaru(MARU maru1, MARU maru2)
{

	//三角形を求める
	float a = maru1.center.x - maru2.center.x;
	float b = maru1.center.y - maru2.center.y;
	float c = sqrtf(a * a + b * b);

	//斜辺の長さが、円の半径�@＋円の半径�Aよりも短いならば、円の中にいる
	if (c <= maru1.radius + maru2.radius)
	{
		return TRUE;
	}

	return FALSE;

}


/// <summary>
/// RECT型を一時的に返す
/// </summary>
/// <param name="left">左</param>
/// <param name="top">上</param>
/// <param name="right">右</param>
/// <param name="bottom">下</param>
/// <returns></returns>
RECT GetRect(int left, int top, int right, int bottom)
{
	//一時的にRECT型の変数を作って
	RECT rect = { left ,top ,right ,bottom };

	//RECT型を返す
	return rect;
}


/// <summary>
/// RECTを利用して四角を描画
/// </summary>
/// <param name="r">RECT構造体</param>
/// <param name="color">描画する色</param>
/// <param name="b">中を塗りつぶさないならFALSE/塗りつぶすならTRUE</param>
VOID DrawRect(RECT r, unsigned int color, bool b)
{
	//引数を基に描画
	DrawBox(r.left, r.top, r.right, r.bottom, color, b);
	return;
}


/// <summary>
/// MARUを利用して四角を描画
/// </summary>
/// <param name="c">MARU構造体</param>
/// <param name="color">描画する色</param>
/// <param name="b">中を塗りつぶさないならFALSE/塗りつぶすならTRUE</param>
/// <param name="thick">先の太さ</param>
VOID DrawMaru(MARU c, unsigned int color, bool b, int thick = 1)
{
	//引数をもとに描画
	DrawCircle(c.center.x, c.center.y, c.radius, color, b, thick);
	return;
}