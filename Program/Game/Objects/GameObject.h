//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		GameObject.h
//!
//! @summary	�Q�[���I�u�W�F�N�g�Ɋւ���w�b�_�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ===================================================
#pragma once


// �\���̂̒�` ============================================================
struct Tag_GameObject
{
	// ���W
	Vector2 position;
	// ���x
	Vector2 velocity;
	// ���
	unsigned int state;
};
typedef struct Tag_GameObject GameObject;


// �֐��̐錾 ==============================================================
//--------------------------------------------------------------------
//! @summary   �I�u�W�F�N�g�̏���������
//!
//! @parameter [gameObject] ����������I�u�W�F�N�g
//! @parameter [position] ���W
//! @parameter [velocity] ���x
//! @parameter [state] ���
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializeGameObject(GameObject* gameObject, Vector2* position, Vector2* velocity, unsigned int state);



//--------------------------------------------------------------------
//! @summary   �I�u�W�F�N�g�̈ړ�����
//!
//! @parameter [gameObject] �ړ�������I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void MoveGameObject(GameObject* gameObject);