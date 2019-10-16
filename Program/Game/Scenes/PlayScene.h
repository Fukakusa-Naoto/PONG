//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		PlayScene.h
//!
//! @summary	�v���C�V�[���֘A�̃w�b�_�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ===================================================
#pragma once



// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "../Objects/Paddle.h"
#include "../Objects/Ball.h"


// �񋓌^�̒�` ============================================================
enum Tag_SideID
{
	SIDE_LEFT,		// ��
	SIDE_RIGHT,		// �E
	SIDE_NONE,		// �Ȃ�
};
typedef enum Tag_SideID SideID;


// �\���̂̒�` ============================================================
struct Tag_PlaySceneObject
{
	// ���p�h��
	Paddle leftPaddle;
	// �E�p�h��
	Paddle rightPaddle;
	// �{�[��
	Ball ball;
};
typedef struct Tag_PlaySceneObject PlaySceneObject;



// �֐��̐錾 ==============================================================
//--------------------------------------------------------------------
//! @summary   �v���C�V�[���̏���������
//!
//! @parameter [playSceneObject] �v���C�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializePlayScene(PlaySceneObject* playSceneObject);



//--------------------------------------------------------------------
//! @summary   �v���C�V�[���̍X�V����
//!
//! @parameter [playSceneObject] �v���C�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void UpdatePlayScene(PlaySceneObject* playSceneObject);



//--------------------------------------------------------------------
//! @summary   �v���C�V�[���̕`�揈��
//!
//! @parameter [playSceneObject] �v���C�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void RenderPlayScene(PlaySceneObject* playSceneObject);



//--------------------------------------------------------------------
//! @summary   �v���C�V�[���̏I������
//!
//! @parameter [playSceneObject] �v���C�V�[���Ŏg�p����I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void FinalizePlayScene(PlaySceneObject* playSceneObject);
