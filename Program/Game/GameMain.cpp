//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		GameMain.cpp
//!
//! @summary	�Q�[���֘A�̃\�[�X�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "GameMain.h"
#include "Scenes/SceneManager.h"


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   �Q�[���̏���������
//!
//! @parameter [gameMainObject] �Q�[����Ŏg�p����S�ẴI�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializeGame(GameMainObject* gameMainObject)
{
	// �ŏ��̃V�[����ݒ�
	SetStartScene(SCENE_PLAY);

	// �V�[���̏���������
	InitializeScene(gameMainObject);
}



//--------------------------------------------------------------------
//! @summary   �Q�[���̍X�V����
//!
//! @parameter [gameMainObject] �Q�[����Ŏg�p����S�ẴI�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void UpdateGame(GameMainObject* gameMainObject)
{
	// �V�[���̍X�V����
	UpdateScene(gameMainObject);
}



//--------------------------------------------------------------------
//! @summary   �Q�[���̕`�揈��
//!
//! @parameter [gameMainObject] �Q�[����Ŏg�p����S�ẴI�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void RenderGame(GameMainObject* gameMainObject)
{
	// �V�[���̕`�揈��
	RenderScene(gameMainObject);
}



//--------------------------------------------------------------------
//! @summary   �Q�[���̏I������
//!
//! @parameter [gameMainObject] �Q�[����Ŏg�p����S�ẴI�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void FinalizeGame(GameMainObject* gameMainObject)
{
	// �V�[���̏I������
	FinalizeScene(gameMainObject);
}
