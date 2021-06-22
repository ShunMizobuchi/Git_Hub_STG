//�L�[�{�[�h�̃\�[�X�t�@�C��

//�w�b�_�t�@�C���̓ǂݍ���
#include"Keyboard.h"

//�O���[�o���ϐ�
KEYBOARD keyboard;

//�֐�

/// <summary>
/// �L�[�̓��͏�Ԃ��X�V����
/// </summary>
VOID AllKeyUpdate(VOID)
{
	//���O�̃L�[�̓��͂�����Ă���
	for (int i = 0; i < KEY_KIND_MAX; i++)
	{
		keyboard.OldAllKeyState[i] = keyboard.AllKeyState[i];
	}

	//�S�ẴL�[�̓��͏�Ԃ𓾂�
	GetHitKeyStateAll(keyboard.TempKeyState);

	//������Ă���L�[�̎��Ԃ��X�V����
	for (int i = 0; i < KEY_KIND_MAX; i++)
	{
		//�L�[�R�[�h�������Ă���Ƃ�
		if (keyboard.TempKeyState[i] != 0)
		{
			keyboard.AllKeyState[i]++;		//�����Ă��鎞�Ԃ����Z
		}
		else
		{
			keyboard.AllKeyState[i] = 0;	//�����Ă��鎞�Ԃ�0�ɖ߂�
		}
	}


	return;
}

/// <sumary>
/// �L�[�������Ă��邩�A�L�[�R�[�h�Ŕ��f����
/// <sumary>
/// <param name="KEY_INPUT_">�L�[�R�[�h</param>
/// <returns>�����Ă�����TRUE</retrns>
BOOL KeyDown(int KEY_INPUT_)
{
	if (
		keyboard.AllKeyState[KEY_INPUT_] != 0			//�ȑO�͉����Ă���
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
	/// �L�[�����グ�Ă��邩�A�L�[�R�[�h�Ŕ��f����
	/// <sumary>
	/// <param name="KEY_INPUT_">�L�[�R�[�h</param>
	/// <returns>�グ�Ă�����TRUE</retrns>
	BOOL KeyUp(int KEY_INPUT_)
	{
		if (
			keyboard.OldAllKeyState[KEY_INPUT_] != 0			//�ȑO�͉����Ă���
			&& keyboard.AllKeyState[KEY_INPUT_] == 0		//���݂͉����Ă��Ȃ�
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
/// �L�[���N���b�N�������ǂ����ŁA�L�[�R�[�h�Ŕ��f����
/// <sumary>
/// <param name="KEY_INPUT_">�L�[�R�[�h</param>
/// <returns>�グ�Ă�����TRUE</retrns>
	BOOL KeyClick(int KEY_INPUT_)
	{
		if (
			keyboard.OldAllKeyState[KEY_INPUT_] != 0			//�ȑO�͉����Ă���
			&& keyboard.AllKeyState[KEY_INPUT_] == 0		//���݂͉����Ă��Ȃ�
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
/// �L�[�����������Ă��邩�A�L�[�R�[�h�Ŕ��f����
/// <sumary>
/// <param name="KEY_INPUT_">�L�[�R�[�h</param>
/// <param nmae="MIlliTime">�L�[�����������ē��肤�~���b</param>
/// <returns>�����Ă�����TRUE</retrns>
		BOOL KeyDownKeep(int KEY_INPUT_, int MilliTime)
		{
			//1�b��1000�~���b
			float MilliSec = 1000.0f;

			//���������Ă��鎞�Ԃ́A�~���b�~FPS�l
			//)��@1500�~���b����/1000�~���E���E1.5�b�~60FPS = 90
			int UpdateTime = (MilliTime / MilliSec) * 60;

			if (keyboard.AllKeyState[KEY_INPUT_] > UpdateTime)
			{
				return TRUE;		//���������Ă���
			}
			else
			{
				return FALSE;		//���������Ă��Ȃ�
			}

		}
