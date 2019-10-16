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
#include "../Controllers/InputPaddleController.h"


// �֐��̒�` ==============================================================
// �����̔��菈��
void JudgeGame(PlaySceneObject* playSceneObject);
// �Փ˔���
void DetectCollisionPlayScene(PlaySceneObject* playSceneObject);


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   �v���C�V�[���̏���������
//!
//! @parameter [playSceneObject] �v���C�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializePlayScene(PlaySceneObject* playSceneObject)
{
	// ���p�h���̏���������
	InitializePaddle(&playSceneObject->leftPaddle, &CreateVector2(LEFT_PADDLE_START_POSITION_X, LEFT_PADDLE_START_POSITION_Y));
	// �E�p�h���̏���������
	InitializePaddle(&playSceneObject->rightPaddle, &CreateVector2(RIGHT_PADDLE_START_POSITION_X, RIGHT_PADDLE_START_POSITION_Y));
	// �{�[���̏���������
	InitializeBall(&playSceneObject->ball, &CreateVector2(BALL_START_POSITION_X, BALL_START_POSITION_Y));
}



//--------------------------------------------------------------------
//! @summary   �v���C�V�[���̍X�V����
//!
//! @parameter [playSceneObject] �v���C�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void UpdatePlayScene(PlaySceneObject* playSceneObject)
{
	// �E�p�h���̓��͐���
	ControlRightPaddle(&playSceneObject->rightPaddle);

	// �Փ˔���
	DetectCollisionPlayScene(playSceneObject);

	// ���p�h���̍X�V����
	UpdatePaddle(&playSceneObject->leftPaddle);
	// �E�p�h���̍X�V����
	UpdatePaddle(&playSceneObject->rightPaddle);
	// �{�[���̍X�V����
	UpdateBall(&playSceneObject->ball);

	// �����̔��菈��
	JudgeGame(playSceneObject);
}



//--------------------------------------------------------------------
//! @summary   �v���C�V�[���̕`�揈��
//!
//! @parameter [playSceneObject] �v���C�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void RenderPlayScene(PlaySceneObject* playSceneObject)
{
	// ���p�h���̕`�揈��
	RenderPaddle(&playSceneObject->leftPaddle);
	// �E�p�h���̕`�揈��
	RenderPaddle(&playSceneObject->rightPaddle);
	// �{�[���̏���������
	RenderBall(&playSceneObject->ball);
}



//--------------------------------------------------------------------
//! @summary   �v���C�V�[���̏I������
//!
//! @parameter [playSceneObject] �v���C�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void FinalizePlayScene(PlaySceneObject* playSceneObject)
{
	// ���p�h���̍폜
	DestroyPaddle(&playSceneObject->leftPaddle);
	// �E�p�h���̍폜
	DestroyPaddle(&playSceneObject->rightPaddle);
	// �{�[���̍폜
	DestroyBall(&playSceneObject->ball);
}



//--------------------------------------------------------------------
//! @summary   �����̔��菈��
//!
//! @parameter [playSceneObject] �v���C�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void JudgeGame(PlaySceneObject* playSceneObject)
{
	// ���_�̔���
	if (GetOutSide(&playSceneObject->ball) == SIDE_LEFT)	// ��
	{
		// �{�[�������̈ʒu�ɖ߂�
		ResetBall(&playSceneObject->ball);
	}
	else if (GetOutSide(&playSceneObject->ball) == SIDE_RIGHT)	// �E
	{
		// �{�[�������̈ʒu�ɖ߂�
		ResetBall(&playSceneObject->ball);
	}
}



//--------------------------------------------------------------------
//! @summary   �Փ˔���
//!
//! @parameter [playSceneObject] �v���C�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void DetectCollisionPlayScene(PlaySceneObject* playSceneGameObject)
{
	// ���p�h���ƃ{�[��
	if (IsCollideAABB(&playSceneGameObject->leftPaddle.boxCollider, &playSceneGameObject->ball.boxCollider))
	{
		// �A�����]�h�~
		if (playSceneGameObject->leftPaddle.boxCollider.position.x <= playSceneGameObject->ball.boxCollider.position.x)
		{
			// �{�[���̌����𔽓]������
			TurnOverVector2X(&playSceneGameObject->ball.gameObject.velocity);
		}
	}

	// �E�p�h���ƃ{�[��
	if (IsCollideAABB(&playSceneGameObject->rightPaddle.boxCollider, &playSceneGameObject->ball.boxCollider))
	{
		// �A�����]�h�~
		if (playSceneGameObject->rightPaddle.boxCollider.position.x >= playSceneGameObject->ball.boxCollider.position.x)
		{
			// �{�[���̌����𔽓]������
			TurnOverVector2X(&playSceneGameObject->ball.gameObject.velocity);
		}
	}
}