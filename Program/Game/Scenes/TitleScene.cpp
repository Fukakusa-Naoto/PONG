//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		TitleScene.cpp
//!
//! @summary	�^�C�g���V�[���V�[���֘A�̃\�[�X�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "TitleScene.h"
#include "SceneManager.h"


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   �^�C�g���V�[���̏���������
//!
//! @parameter [titleSceneObject] �^�C�g���V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializeTitleScene(TitleSceneObject* titleSceneObject)
{
}



//--------------------------------------------------------------------
//! @summary   �^�C�g���V�[���̍X�V����
//!
//! @parameter [titleSceneObject] �^�C�g���V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void UpdateTitleScene(TitleSceneObject* titleSceneObject)
{
	// �X�y�[�X�L�[�����͂����
	if (IsButtonPressed(PAD_INPUT_10))
	{
		// �v���C�V�[���֑J�ڂ���
		ChangeScene(SCENE_PLAY);
	}
}



//--------------------------------------------------------------------
//! @summary   �^�C�g���V�[���̕`�揈��
//!
//! @parameter [titleSceneObject] �^�C�g���V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void RenderTitleScene(TitleSceneObject* titleSceneObject)
{
	DrawString(0, 0, "Title", COLOR_WHITE);
}



//--------------------------------------------------------------------
//! @summary   �^�C�g���V�[���̏I������
//!
//! @parameter [titleSceneObject] �^�C�g���V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void FinalizeTitleScene(TitleSceneObject* titleSceneObject)
{

}
