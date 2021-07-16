#pragma once

//�}�E�X�����̃w�b�_�[�t�@�C��
//�}�E�X�����̃w�b�_�[�t�@�C��


//�Q�[���̃��C���w�b�_�[�t�@�C��
#include"game.h"
#include"shape.h"

//�}�E�X�̃{�^��
#define MOUSE_BUTTON_CODE	129		//0�~0000�`0�~0080�܂�

//�}�E�X�̍\����

struct MOUSE 
{
	int InputValue = 0;		//GetMouseInput������
	int WheelValue = 0;		//�}�E�X�z�C�[���̉�]��

	iPOINT Point;			//�}�E�X�̍��W������
	iPOINT Oldpoint;		//�}�E�X�̍��W�i���O�j���͂���@

	int OldButton[MOUSE_BUTTON_CODE];		//�}�E�X�{�^���̓��́i���O�j������
	int Button[MOUSE_BUTTON_CODE];			//�}�E�X�̃{�^��������
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
