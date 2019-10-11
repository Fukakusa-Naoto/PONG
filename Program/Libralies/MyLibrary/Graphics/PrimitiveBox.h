//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		PrimitiveBox.h
//!
//! @summary	��`�̕`��Ɋւ���w�b�_�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ===================================================
#pragma once


// �\���̂̒�` ============================================================
struct Tag_PrimitiveBox
{
	// �`�悷�钆�S���W
	Vector2 position;
	// �`�悷�镝�ƍ����ix:��, y:�����j
	Vector2 size;
	// �F
	unsigned int color;
	// �h��Ԃ��t���O�iTRUE:�h��Ԃ�, FALSE:�h��Ԃ��Ȃ��j
	BOOL fillFlag;
};
typedef struct Tag_PrimitiveBox PrimitiveBox;



// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   ��`�̕`��
//!
//! @parameter [box] �`�悷���`�f�[�^
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
static void DrawBox(const PrimitiveBox* box)
{
	// ����A�E���̌v�Z
	float top = box->position.y - (box->size.y * 0.5f);
	float bottom = box->position.y + (box->size.y * 0.5f);
	float right = box->position.x + (box->size.x * 0.5f);
	float left = box->position.x - (box->size.x * 0.5f);

	// �`��
	DrawBoxAA(left, top, right, bottom, box->color, box->fillFlag);
}