//ƒwƒbƒ_[ƒtƒ@ƒCƒ‹‚ğ“Ç‚İ‚İ
#include "game.h"
#include "shape.h"
#include "math.h"



/// <summary>
/// ’ZŒ`—Ìˆæ“¯m‚Ì“–‚½‚è”»’è‚ğ‚·‚éŠÖ”
/// </summary>
/// <param name="a">—ÌˆæA</param>
/// <param name="b">—ÌˆæB</param>
/// <returns></returns>
BOOL CheckCollRectToRect(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;		//“–‚½‚Á‚Ä‚¢‚é
	}
	
	return FALSE;		//“–‚½‚Á‚Ä‚¢‚È‚¢
	
}


/// <summary>
/// lŠp‚Æ“_‚Ì“–‚½‚è”»’è
/// </summary>
/// <param name="pt">iPOINTŒ^‚Ì“_</param>
/// <param name="r">’ZŒ`—Ìˆæ</param>
/// <returns></returns>
BOOL CheckColliPOINTToRect(iPOINT pt, RECT r)
{
	if (
		pt.x > r.left && pt.x < r.right		//“_‚ÌXˆÊ’u‚ªlŠp‚Ì¶‰E‚ÌŠÔ‚É‚¢‚Ä
		&& pt.y > r.top && pt.y < r.bottom	//“_‚ÌYˆÊ’u‚ªlŠp‚Ìã‰º‚ÌŠÔ‚É‚¢‚é‚Æ‚«
		)
	{
		return TRUE;
	}

	return FALSE;
}


/// <summary>
/// ‰~‚Æ“_‚Ì“–‚½‚è”»’è
/// </summary>
/// <param name="pt">Œ^‚Ì“_</param>
/// <param name="m">‰~—Ìˆæ</param>
/// <returns></returns>
BOOL CheckColliPOINTToMaru(iPOINT pt, MARU m)
{
	//OŠpŒ`‚ğ‹‚ß‚é
	float a = pt.x - m.center.x;
	float b = pt.y - m.center.y;
	float c = sqrtf(a * a + b * b);

	//Î•Ó‚Ì’·‚³‚ªA‰~‚Ì”¼Œa‚æ‚è‚à’Z‚¢‚È‚ç‚ÎA‰~‚Ì’†‚É‚¢‚é
	if (c <= m.radius)
	{
		return TRUE;
	}

	return FALSE;
}



/// <summary>
/// ‰~‚Æ‰~‚Ì“–‚½‚è”»’è
/// </summary>
/// <param name="maru1">‰~—Ìˆæ‚P</param>
/// <param name="maru2">‰~—Ìˆæ‚Q</param>
/// <returns></returns>
BOOL CheckCollMaruToMaru(MARU maru1, MARU maru2)
{

	//OŠpŒ`‚ğ‹‚ß‚é
	float a = maru1.center.x - maru2.center.x;
	float b = maru1.center.y - maru2.center.y;
	float c = sqrtf(a * a + b * b);

	//Î•Ó‚Ì’·‚³‚ªA‰~‚Ì”¼Œa‡@{‰~‚Ì”¼Œa‡A‚æ‚è‚à’Z‚¢‚È‚ç‚ÎA‰~‚Ì’†‚É‚¢‚é
	if (c <= maru1.radius + maru2.radius)
	{
		return TRUE;
	}

	return FALSE;

}


/// <summary>
/// RECTŒ^‚ğˆê“I‚É•Ô‚·
/// </summary>
/// <param name="left">¶</param>
/// <param name="top">ã</param>
/// <param name="right">‰E</param>
/// <param name="bottom">‰º</param>
/// <returns></returns>
RECT GetRect(int left, int top, int right, int bottom)
{
	//ˆê“I‚ÉRECTŒ^‚Ì•Ï”‚ğì‚Á‚Ä
	RECT rect = { left ,top ,right ,bottom };

	//RECTŒ^‚ğ•Ô‚·
	return rect;
}


/// <summary>
/// RECT‚ğ—˜—p‚µ‚ÄlŠp‚ğ•`‰æ
/// </summary>
/// <param name="r">RECT\‘¢‘Ì</param>
/// <param name="color">•`‰æ‚·‚éF</param>
/// <param name="b">’†‚ğ“h‚è‚Â‚Ô‚³‚È‚¢‚È‚çFALSE/“h‚è‚Â‚Ô‚·‚È‚çTRUE</param>
VOID DrawRect(RECT r, unsigned int color, bool b)
{
	//ˆø”‚ğŠî‚É•`‰æ
	DrawBox(r.left, r.top, r.right, r.bottom, color, b);
	return;
}


/// <summary>
/// MARU‚ğ—˜—p‚µ‚ÄlŠp‚ğ•`‰æ
/// </summary>
/// <param name="c">MARU\‘¢‘Ì</param>
/// <param name="color">•`‰æ‚·‚éF</param>
/// <param name="b">’†‚ğ“h‚è‚Â‚Ô‚³‚È‚¢‚È‚çFALSE/“h‚è‚Â‚Ô‚·‚È‚çTRUE</param>
/// <param name="thick">æ‚Ì‘¾‚³</param>
VOID DrawMaru(MARU c, unsigned int color, bool b, int thick = 1)
{
	//ˆø”‚ğ‚à‚Æ‚É•`‰æ
	DrawCircle(c.center.x, c.center.y, c.radius, color, b, thick);
	return;
}