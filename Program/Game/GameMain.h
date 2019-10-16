//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		GameMain.h
//!
//! @summary	�Q�[���֘A�̃w�b�_�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ===================================================
#pragma once


// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "Scenes/PlayScene.h"
#include "Scenes/LogoScene.h"
#include "Scenes/TitleScene.h"


// �萔�̒�` ==============================================================
// �Q�[���^�C�g��
#define GAME_TITLE     "PONG"

// �Q�[�����
#define SCREEN_WIDTH   640    // ��[pixel]
#define SCREEN_HEIGHT  480    // ����[pixel]

#define SCREEN_CENTER_X (SCREEN_WIDTH  / 2)    // ��ʂ̒���(X���W)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT / 2)    // ��ʂ̒���(Y���W)

// �\���̂̒�` ============================================================
struct Tag_GameMainObject
{
	// �v���C�V�[���Ŏg�p����I�u�W�F�N�g
	PlaySceneObject playSceneObject;
	// �^�C�g���V�[���Ŏg�p����I�u�W�F�N�g
	TitleSceneObject titleSceneObject;
};
typedef struct Tag_GameMainObject GameMainObject;


// �֐��̐錾 ==============================================================
//--------------------------------------------------------------------
//! @summary   �Q�[���̏���������
//!
//! @parameter [gameMainObject] �Q�[����Ŏg�p����S�ẴI�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializeGame(GameMainObject* gameMainObject);



//--------------------------------------------------------------------
//! @summary   �Q�[���̍X�V����
//!
//! @parameter [gameMainObject] �Q�[����Ŏg�p����S�ẴI�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void UpdateGame(GameMainObject* gameMainObject);



//--------------------------------------------------------------------
//! @summary   �Q�[���̕`�揈��
//!
//! @parameter [gameMainObject] �Q�[����Ŏg�p����S�ẴI�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void RenderGame(GameMainObject* gameMainObject);



//--------------------------------------------------------------------
//! @summary   �Q�[���̏I������
//!
//! @parameter [gameMainObject] �Q�[����Ŏg�p����S�ẴI�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void FinalizeGame(GameMainObject* gameMainObject);
