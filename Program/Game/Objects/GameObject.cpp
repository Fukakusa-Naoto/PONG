//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		GameObject.cpp
//!
//! @summary	�Q�[���I�u�W�F�N�g�Ɋւ���\�[�X�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "GameObject.h"


// �֐��̒�` ==============================================================
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
void InitializeGameObject(GameObject* gameObject, Vector2* position, Vector2* velocity, unsigned int state)
{
	gameObject->position = CreateVector2(position->x, position->y);
	gameObject->velocity = CreateVector2(velocity->x, velocity->y);
	gameObject->state = state;
}



//--------------------------------------------------------------------
//! @summary   �I�u�W�F�N�g�̈ړ�����
//!
//! @parameter [gameObject] �ړ�������I�u�W�F�N�g
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void MoveGameObject(GameObject* gameObject)
{
	gameObject->position = AddVector2(&gameObject->position, &gameObject->velocity);
}