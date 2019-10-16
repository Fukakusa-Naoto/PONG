//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		InputPaddleController.cpp
//!
//! @summary	���͂ɂ��p�h������Ɋւ���\�[�X�t�@�C��
//!
//! @date		2019.10.16
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "InputPaddleController.h"


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   �E�p�h���̓��͐��䏈��
//!
//! @parameter [paddle] ���䂷��p�h��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void ControlRightPaddle(Paddle* paddle)
{
	// ��L�[�����͂��ꂽ
	if (IsButtonDown(PAD_INPUT_UP))
	{
		paddle->gameObject.velocity.y = -RIGHT_PADDLE_MOVE_SPEED;
	}
	// ���L�[�����͂��ꂽ
	else if (IsButtonDown(PAD_INPUT_DOWN))
	{
		paddle->gameObject.velocity.y = RIGHT_PADDLE_MOVE_SPEED;
	}
	// �������͂���Ă��Ȃ�
	else
	{
		paddle->gameObject.velocity.y = 0.0f;
	}
}