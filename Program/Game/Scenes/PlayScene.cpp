//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		PlayScene.cpp
//!
//! @summary	�v���C�V�[���֘A�̃\�[�X�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "PlayScene.h"
#include "SceneManager.h"
#include "../Objects/Paddle.h"
#include "../Objects/Ball.h"


// �O���[�o���ϐ��̒�` =====================================================
// ���p�h��
Paddle g_leftPaddle;
// �E�p�h��
Paddle g_rightPaddle;
// �{�[��
Ball g_ball;


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   �v���C�V�[���̏���������
//!
//! @parameter [void] �Ȃ�
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializePlayScene(void)
{
	// ���p�h���̏���������
	InitializePaddle(&g_leftPaddle, &CreateVector2(LEFT_PADDLE_START_POSITION_X, LEFT_PADDLE_START_POSITION_Y));
	// �E�p�h���̏���������
	InitializePaddle(&g_rightPaddle, &CreateVector2(RIGHT_PADDLE_START_POSITION_X, RIGHT_PADDLE_START_POSITION_Y));
	// �{�[���̏���������
	InitializeBall(&g_ball, &CreateVector2(BALL_START_POSITION_X, BALL_START_POSITION_Y));
}



//--------------------------------------------------------------------
//! @summary   �v���C�V�[���̍X�V����
//!
//! @parameter [void] �Ȃ�
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void UpdatePlayScene(void)
{
	// ���p�h���̍X�V����
	UpdatePaddle(&g_leftPaddle);
	// �E�p�h���̍X�V����
	UpdatePaddle(&g_rightPaddle);
	// �{�[���̍X�V����
	UpdateBall(&g_ball);
}



//--------------------------------------------------------------------
//! @summary   �v���C�V�[���̕`�揈��
//!
//! @parameter [void] �Ȃ�
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void RenderPlayScene(void)
{
	// ���p�h���̕`�揈��
	RenderPaddle(&g_leftPaddle);
	// �E�p�h���̕`�揈��
	RenderPaddle(&g_rightPaddle);
	// �{�[���̏���������
	RenderBall(&g_ball);
}



//--------------------------------------------------------------------
//! @summary   �v���C�V�[���̏I������
//!
//! @parameter [void] �Ȃ�
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void FinalizePlayScene(void)
{
	// ���p�h���̍폜
	DestroyPaddle(&g_leftPaddle);
	// �E�p�h���̍폜
	DestroyPaddle(&g_rightPaddle);
	// �{�[���̍폜
	DestroyBall(&g_ball);
}
