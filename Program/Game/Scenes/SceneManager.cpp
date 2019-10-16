//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		SceneManager.cpp
//!
//! @summary	�V�[���Ǘ��Ɋւ���\�[�X�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "SceneManager.h"


// �O���[�o���ϐ��̐錾 =====================================================
// ���݂̃V�[��ID
static SceneID g_currentSceneID;
// ���̃V�[��ID
static SceneID g_nextSceneID;


// �֐��̐錾 ==============================================================
// �V�[���̐؂�ւ�����
void SwitchScene(GameMainObject* gameMainObject);


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   �V�[���̐؂�ւ�����
//!
//! @parameter [nextSceneID] ���̃V�[����ID
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void ChangeScene(SceneID nextSceneID)
{
	// ���̃V�[����\��
	g_nextSceneID = nextSceneID;
}



//--------------------------------------------------------------------
//! @summary   �ŏ��̃V�[���̐ݒ�
//!
//! @parameter [startSceneID] �ŏ��̃V�[����ID
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void SetStartScene(SceneID startSceneID)
{
	// �V�[��ID�̏�����
	g_currentSceneID = SCENE_NONE;
	g_nextSceneID = startSceneID;
}



//--------------------------------------------------------------------
//! @summary   �V�[���̏���������
//!
//! @parameter [gameMainObject] �Q�[����Ŏg�p����S�ẴI�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializeScene(GameMainObject* gameMainObject)
{
	// �V�[���ʂ̏���������
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// �v���C
		InitializePlayScene(&gameMainObject->playSceneObject);
		break;
	case SCENE_LOGO:	// ���S
		InitializeLogoScene();
		break;
	case SCENE_TITLE:	// �^�C�g��
		InitializeTitleScene(&gameMainObject->titleSceneObject);
		break;
	default:
		// �������Ȃ�
		break;
	}
}



//--------------------------------------------------------------------
//! @summary   �V�[���̍X�V����
//!
//! @parameter [gameMainObject] �Q�[����Ŏg�p����S�ẴI�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void UpdateScene(GameMainObject* gameMainObject)
{
	// �V�[���̐؂�ւ�
	SwitchScene(gameMainObject);

	// �V�[���ʂ̍X�V����
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// �v���C
		UpdatePlayScene(&gameMainObject->playSceneObject);
		break;
	case SCENE_LOGO:	// ���S
		UpdateLogoScene();
		break;
	case SCENE_TITLE:	// �^�C�g��
		UpdateTitleScene(&gameMainObject->titleSceneObject);
		break;
	default:
		// �������Ȃ�
		break;
	}
}



//--------------------------------------------------------------------
//! @summary   �V�[���̕`�揈��
//!
//! @parameter [gameMainObject] �Q�[����Ŏg�p����S�ẴI�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void RenderScene(GameMainObject* gameMainObject)
{
	// �V�[���ʂ̕`�揈��
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// �v���C
		RenderPlayScene(&gameMainObject->playSceneObject);
		break;
	case SCENE_LOGO:	// ���S
		RenderLogoScene();
		break;
	case SCENE_TITLE:	// �^�C�g��
		RenderTitleScene(&gameMainObject->titleSceneObject);
		break;
	default:
		// �������Ȃ�
		break;
	}
}



//--------------------------------------------------------------------
//! @summary   �V�[���̏I������
//!
//! @parameter [gameMainObject] �Q�[����Ŏg�p����S�ẴI�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void FinalizeScene(GameMainObject* gameMainObject)
{
	// �V�[���ʂ̏I������
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// �v���C
		FinalizePlayScene(&gameMainObject->playSceneObject);
		break;
	case SCENE_LOGO:	// ���S
		FinalizeLogoScene();
		break;
	case SCENE_TITLE:	// �^�C�g��
		FinalizeTitleScene(&gameMainObject->titleSceneObject);
		break;
	default:
		// �������Ȃ�
		break;
	}

}



//--------------------------------------------------------------------
//! @summary   �V�[���̐؂�ւ�����
//!
//! @parameter [gameMainObject] �Q�[����Ŏg�p����S�ẴI�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void SwitchScene(GameMainObject* gameMainObject)
{
	// �V�[���̕ύX���������ꍇ
	if (g_nextSceneID != g_currentSceneID)
	{
		// ���݂̃V�[���̏I������
		FinalizeScene(gameMainObject);
		// �V�[��ID��V��������
		g_currentSceneID = g_nextSceneID;
		// �V�����V�[���̏���������
		InitializeScene(gameMainObject);
	}
}
