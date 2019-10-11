//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Ball.cpp
//!
//! @summary	�{�[���Ɋւ���\�[�X�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "Ball.h"


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   �{�[���̏���������
//!
//! @parameter [ball] ����������{�[��
//! @parameter [position] ���W
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializeBall(Ball* ball, const Vector2* position)
{
	// �Q�[���I�u�W�F�N�g�̏���������
	InitializeGameObject(&ball->gameObject, position, &GetVector2Zero(), 1);

	// �p�h���T�C�Y�̍쐬
	Vector2 size = CreateVector2(BALL_WIDTH, BALL_HEIGHT);

	// �`��̏���������
	InitializePrimitiveBox(&ball->primitiveBox, &ball->gameObject.position, &size, COLOR_WHITE, TRUE);

	// �R���C�_�[�̏���������
	InitializeBoxCollider(&ball->boxCollider, &ball->gameObject.position, &size);
}



//--------------------------------------------------------------------
//! @summary   �{�[���̍X�V����
//!
//! @parameter [ball] �X�V����{�[��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void UpdateBall(Ball* ball)
{
	// �ʒu����
	SetPositionPrimitiveBox(&ball->primitiveBox, &ball->gameObject.position);
	SetPositionBoxCollider(&ball->boxCollider, &ball->gameObject.position);
}



//--------------------------------------------------------------------
//! @summary   �{�[���̕`�揈��
//!
//! @parameter [ball] �`�悷��{�[��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void RenderBall(Ball* ball)
{
	DrawPrimitiveBox(&ball->primitiveBox);
}



//--------------------------------------------------------------------
//! @summary   �{�[���̍폜����
//!
//! @parameter [ball] �폜����{�[��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void DestroyBall(Ball* ball)
{
	ZeroMemory(ball, sizeof(Ball));
}