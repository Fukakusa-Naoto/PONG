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
#include "PlayScene.h"
#include "LogoScene.h"
#include "TitleScene.h"


// �O���[�o���ϐ��̐錾 =====================================================
// ���݂̃V�[��ID
static SceneID g_currentSceneID;
// ���̃V�[��ID
static SceneID g_nextSceneID;


// �֐��̐錾 ==============================================================
// �V�[���̐؂�ւ�����
void SwitchScene(void);


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
//! @parameter [void] �Ȃ�
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializeScene(void)
{
	// �V�[���ʂ̏���������
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// �v���C
		InitializePlayScene();
		break;
	case SCENE_LOGO:	// ���S
		InitializeLogoScene();
		break;
	case SCENE_TITLE:	// �^�C�g��
		InitializeTitleScene();
		break;
	default:
		// �������Ȃ�
		break;
	}
}



//--------------------------------------------------------------------
//! @summary   �V�[���̍X�V����
//!
//! @parameter [void] �Ȃ�
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void UpdateScene(void)
{
	// �V�[���̐؂�ւ�
	SwitchScene();

	// �V�[���ʂ̍X�V����
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// �v���C
		UpdatePlayScene();
		break;
	case SCENE_LOGO:	// ���S
		UpdateLogoScene();
		break;
	case SCENE_TITLE:	// �^�C�g��
		UpdateTitleScene();
		break;
	default:
		// �������Ȃ�
		break;
	}
}



//--------------------------------------------------------------------
//! @summary   �V�[���̕`�揈��
//!
//! @parameter [void] �Ȃ�
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void RenderScene(void)
{
	// �V�[���ʂ̕`�揈��
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// �v���C
		RenderPlayScene();
		break;
	case SCENE_LOGO:	// ���S
		RenderLogoScene();
		break;
	case SCENE_TITLE:	// �^�C�g��
		RenderTitleScene();
		break;
	default:
		// �������Ȃ�
		break;
	}
}



//--------------------------------------------------------------------
//! @summary   �V�[���̏I������
//!
//! @parameter [void] �Ȃ�
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void FinalizeScene(void)
{
	// �V�[���ʂ̏I������
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// �v���C
		FinalizePlayScene();
		break;
	case SCENE_LOGO:	// ���S
		FinalizeLogoScene();
		break;
	case SCENE_TITLE:	// �^�C�g��
		FinalizeTitleScene();
		break;
	default:
		// �������Ȃ�
		break;
	}

}



//--------------------------------------------------------------------
//! @summary   �V�[���̐؂�ւ�����
//!
//! @parameter [void] �Ȃ�
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void SwitchScene(void)
{
	// �V�[���̕ύX���������ꍇ
	if (g_nextSceneID != g_currentSceneID)
	{
		// ���݂̃V�[���̏I������
		FinalizeScene();
		// �V�[��ID��V��������
		g_currentSceneID = g_nextSceneID;
		// �V�����V�[���̏���������
		InitializeScene();
	}
}
