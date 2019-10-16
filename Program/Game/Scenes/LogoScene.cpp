//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		LogoScene.cpp
//!
//! @summary	���S�V�[���V�[���֘A�̃\�[�X�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "LogoScene.h"
#include "SceneManager.h"


// �萔�̒�` ==============================================================
// �V�[���ύX�܂ł̎���
#define CHANGE_SCENE_TIME (3.0f)


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   ���S�V�[���̏���������
//!
//! @parameter [logoSceneObject] ���S�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializeLogoScene(LogoSceneObject* logoSceneObject)
{
	// �J�E���g�̏�����
	logoSceneObject->timeCount = 0.0f;
}



//--------------------------------------------------------------------
//! @summary   ���S�V�[���̍X�V����
//!
//! @parameter [logoSceneObject] ���S�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void UpdateLogoScene(LogoSceneObject* logoSceneObject)
{
	// �J�E���g�̍X�V
	logoSceneObject->timeCount += GetFrameDeltaTime();

	// 3�b���o�߂���
	if (logoSceneObject->timeCount >= CHANGE_SCENE_TIME)
	{
		// �^�C�g���V�[���֑J�ڂ���
		ChangeScene(SCENE_TITLE);
	}
}



//--------------------------------------------------------------------
//! @summary   ���S�V�[���̕`�揈��
//!
//! @parameter [logoSceneObject] ���S�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void RenderLogoScene(LogoSceneObject* logoSceneObject)
{
	DrawString(0, 0, "LOGO", COLOR_WHITE);
}



//--------------------------------------------------------------------
//! @summary   ���S�V�[���̏I������
//!
//! @parameter [logoSceneObject] ���S�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void FinalizeLogoScene(LogoSceneObject* logoSceneObject)
{

}
