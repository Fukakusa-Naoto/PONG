//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		CPUPaddleController.cpp
//!
//! @summary	CPU�ɂ��p�h������Ɋւ���\�[�X�t�@�C��
//!
//! @date		2019.10.16
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "CPUPaddleController.h"


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   CPU�p�h���̐��䏈��
//!
//! @parameter [paddle] ���䂷��p�h��
//! @parameter [ball] �Q�Ƃ���{�[�����
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void ControlCPUPaddle(Paddle* paddle, Ball* ball)
{
	// �{�[�������g���ゾ�����ꍇ
	if (paddle->gameObject.position.y >= ball->gameObject.position.y)
	{
		paddle->gameObject.velocity.y = -CPU_PADDLE_MOVE_SPEED;
	}
	// �{�[�������g��艺�������ꍇ
	else if (paddle->gameObject.position.y <= ball->gameObject.position.y)
	{
		paddle->gameObject.velocity.y = CPU_PADDLE_MOVE_SPEED;
	}
}