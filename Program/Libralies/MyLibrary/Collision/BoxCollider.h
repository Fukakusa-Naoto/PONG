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