//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		TitleScene.h
//!
//! @summary	�^�C�g���V�[���֘A�̃w�b�_�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ===================================================
#pragma once


// �\���̂̒�` ============================================================
struct Tag_TitleSceneObject
{

};
typedef struct Tag_TitleSceneObject TitleSceneObject;


// �֐��̐錾 ==============================================================
//--------------------------------------------------------------------
//! @summary   �^�C�g���V�[���̏���������
//!
//! @parameter [titleSceneObject] �^�C�g���V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializeTitleScene(TitleSceneObject* titleSceneObject);



//--------------------------------------------------------------------
//! @summary   �^�C�g���V�[���̍X�V����
//!
//! @parameter [titleSceneObject] �^�C�g���V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void UpdateTitleScene(TitleSceneObject* titleSceneObject);



//--------------------------------------------------------------------
//! @summary   �^�C�g���V�[���̕`�揈��
//!
//! @parameter [titleSceneObject] �^�C�g���V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void RenderTitleScene(TitleSceneObject* titleSceneObject);



//--------------------------------------------------------------------
//! @summary   �^�C�g���V�[���̏I������
//!
//! @parameter [titleSceneObject] �^�C�g���V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void FinalizeTitleScene(TitleSceneObject* titleSceneObject);
