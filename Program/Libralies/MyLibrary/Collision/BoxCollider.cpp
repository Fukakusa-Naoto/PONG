//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		BoxCollider.cpp
//!
//! @summary	�Փ˔���Ɏg�p�����`�f�[�^�̃\�[�X�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "BoxCollider.h"


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   BoxCollider�̏���������
//!
//! @parameter [collider] ����������R���C�_�[
//! @parameter [position] ���W
//! @parameter [size] �T�C�Y
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializeBoxCollider(BoxCollider* collider, Vector2* position, Vector2* size)
{
	collider->position = CreateVector2(position->x, position->y);
	collider->size = CreateVector2(size->x, size->y);
}



//--------------------------------------------------------------------
//! @summary   BoxCollider�̍��W�̐ݒ�
//!
//! @parameter [collider] �ݒ肷��R���C�_�[
//! @parameter [position] ���W
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void SetPositionBoxCollider(BoxCollider* collider, Vector2* position)
{
	collider->position = CreateVector2(position->x, position->y);
}



//--------------------------------------------------------------------
//! @summary   BoxCollider�̃f�o�b�O�\��
//!
//! @parameter [collider] �\������R���C�_�[�f�[�^
//! @parameter [color] �\������F
//! @parameter [fillFlag] �h��Ԃ��t���O�iTRUE:�h��Ԃ�, FALSE:�h��Ԃ��Ȃ��j
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
 void DispleyBoxCollider(BoxCollider* collider, unsigned int color, BOOL fillFlag)
{
	// ����A�E���̌v�Z
	float top = collider->position.y - (collider->size.y * 0.5f);
	float bottom = collider->position.y + (collider->size.y * 0.5f);
	float right = collider->position.x + (collider->size.x * 0.5f);
	float left = collider->position.x - (collider->size.x * 0.5f);

	// �`��
	DrawBoxAA(left, top, right, bottom, color, fillFlag);
}