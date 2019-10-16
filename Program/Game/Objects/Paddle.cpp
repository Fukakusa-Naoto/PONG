//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Paddle.cpp
//!
//! @summary	�p�h���Ɋւ���\�[�X�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "Paddle.h"
#include "../GameMain.h"


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   �p�h���̏���������
//!
//! @parameter [paddle] ����������p�h��
//! @parameter [position] ���W
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializePaddle(Paddle* paddle, Vector2* position)
{
	// �Q�[���I�u�W�F�N�g�̏���������
	InitializeGameObject(&paddle->gameObject, position, &GetVector2Zero(), 1);

	// �p�h���T�C�Y�̍쐬
	Vector2 size = CreateVector2(PADDLE_WIDTH, PADDLE_HEIGHT);

	// �`��̏���������
	InitializePrimitiveBox(&paddle->primitiveBox, &paddle->gameObject.position, &size, COLOR_WHITE, TRUE);

	// �R���C�_�[�̏���������
	InitializeBoxCollider(&paddle->boxCollider, &paddle->gameObject.position, &size);
}



//--------------------------------------------------------------------
//! @summary   �p�h���̍X�V����
//!
//! @parameter [paddle] �X�V����p�h��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void UpdatePaddle(Paddle* paddle)
{
	// �p�h���̈ړ�����
	MoveGameObject(&paddle->gameObject);

	// �p�h���̈ړ�����
	LinitAreaPaddle(paddle);

	// �ʒu����
	SetPositionPrimitiveBox(&paddle->primitiveBox, &paddle->gameObject.position);
	SetPositionBoxCollider(&paddle->boxCollider, &paddle->gameObject.position);
}



//--------------------------------------------------------------------
//! @summary   �p�h���̕`�揈��
//!
//! @parameter [paddle] �`�悷��p�h��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void RenderPaddle(Paddle* paddle)
{
	DrawPrimitiveBox(&paddle->primitiveBox);
}



//--------------------------------------------------------------------
//! @summary   �p�h���̍폜����
//!
//! @parameter [paddle] �폜����p�h��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void DestroyPaddle(Paddle* paddle)
{
	ZeroMemory(paddle, sizeof(Paddle));
}



//--------------------------------------------------------------------
//! @summary   �p�h���̈ړ�����
//!
//! @parameter [paddle] ����������p�h��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void LinitAreaPaddle(Paddle* paddle)
{
	// ��
	if (paddle->gameObject.position.y <= PADDLE_LIMIT_AREA_Y)
	{
		paddle->gameObject.position.y = PADDLE_LIMIT_AREA_Y;
	}

	// ��
	if (paddle->gameObject.position.y >= SCREEN_HEIGHT - PADDLE_LIMIT_AREA_Y)
	{
		paddle->gameObject.position.y = SCREEN_HEIGHT - PADDLE_LIMIT_AREA_Y;
	}
}