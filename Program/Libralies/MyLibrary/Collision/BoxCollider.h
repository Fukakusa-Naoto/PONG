//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		BoxCollider.h
//!
//! @summary	�Փ˔���Ɏg�p�����`�f�[�^�̃w�b�_�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ===================================================
#pragma once


// �\���̂̒�` ============================================================
struct Tag_BoxCollider
{
	// ���W
	Vector2 position;
	// �T�C�Y
	Vector2 size;
};
typedef struct Tag_BoxCollider BoxCollider;



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
static void InitializeBoxCollider(BoxCollider* collider, const Vector2* position, const Vector2* size)
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
static void SetPositionBoxCollider(BoxCollider* collider, const Vector2* position)
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
static void DispleyBoxCollider(const BoxCollider* collider, unsigned int color, BOOL fillFlag)
{
	// ����A�E���̌v�Z
	float top = collider->position.y - (collider->size.y * 0.5f);
	float bottom = collider->position.y + (collider->size.y * 0.5f);
	float right = collider->position.x + (collider->size.x * 0.5f);
	float left = collider->position.x - (collider->size.x * 0.5f);

	// �`��
	DrawBoxAA(left, top, right, bottom, color, fillFlag);
}