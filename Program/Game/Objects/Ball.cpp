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
// ��ʂ̏㉺�ł̈ړ�����
void LimitScreen(Ball* ball);


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   �{�[���̏���������
//!
//! @parameter [ball] ����������{�[��
//! @parameter [position] ���W
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializeBall(Ball* ball, Vector2* position)
{
	// �Q�[���I�u�W�F�N�g�̏���������
	InitializeGameObject(&ball->gameObject, position, &CreateVector2(BALL_SPEED, BALL_SPEED), 1);

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
	// �{�[���̈ړ�
	MoveGameObject(&ball->gameObject);

	// �ړ�����
	LimitScreen(ball);

	// �ʒu����
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
	// �`��O�Ɉʒu�������s��
	SetPositionPrimitiveBox(&ball->primitiveBox, &ball->gameObject.position);

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



//--------------------------------------------------------------------
//! @summary   �{�[���̃��Z�b�g����
//!
//! @parameter [ball] ���Z�b�g����{�[��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void ResetBall(Ball* ball)
{
	// �����ʒu�ɖ߂�
	ball->gameObject.position = CreateVector2(BALL_START_POSITION_X, BALL_START_POSITION_Y);

	// �ʒu����
	SetPositionBoxCollider(&ball->boxCollider, &ball->gameObject.position);
}



//--------------------------------------------------------------------
//! @summary   �{�[������ʂ̂ǂ��炩��o����
//!
//! @parameter [ball] ���ׂ�{�[��
//!
//! @return    �o�������̒l
//--------------------------------------------------------------------
SideID GetOutSide(Ball* ball)
{
	if (ball->gameObject.position.x <= 0) return SIDE_LEFT;
	else if (ball->gameObject.position.x >= SCREEN_WIDTH) return SIDE_RIGHT;
	else return SIDE_NONE;
}



//--------------------------------------------------------------------
//! @summary   ��ʂ̏㉺�ł̈ړ�����
//!
//! @parameter [ball] ������������{�[��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void LimitScreen(Ball* ball)
{
	// �Փ˔���̈ʒu�������s��
	SetPositionBoxCollider(&ball->boxCollider, &ball->gameObject.position);

	if ((ball->boxCollider.position.y - (ball->boxCollider.size.y * 0.5f) <= 0)
		|| ((ball->boxCollider.position.y + (ball->boxCollider.size.y * 0.5f) >= SCREEN_HEIGHT)))
	{
		// ���]������
		TurnOverVector2Y(&ball->gameObject.velocity);
	}
}