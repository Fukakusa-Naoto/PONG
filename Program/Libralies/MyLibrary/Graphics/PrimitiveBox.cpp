//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		PrimitiveBox.cpp
//!
//! @summary	��`�̕`��Ɋւ���\�[�X�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "PrimitiveBox.h"


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   ��`�̏���������
//!
//! @parameter [box] �����������`�f�[�^
//! @parameter [position] ���W
//! @parameter [size] �T�C�Y
//! @parameter [color] �F
//! @parameter [fillFlag] �h��Ԃ��t���O�iTRUE:�h��Ԃ�, FALSE:�h��Ԃ��Ȃ��j
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializePrimitiveBox(PrimitiveBox* box, Vector2* position, Vector2* size, unsigned int color, BOOL fillFlag)
{
	box->position = CreateVector2(position->x, position->y);
	box->size = CreateVector2(size->x, size->y);
	box->color = color;
	box->fillFlag = fillFlag;
}



//--------------------------------------------------------------------
//! @summary   ��`�̍��W�̐ݒ�
//!
//! @parameter [box] �ݒ肷���`�f�[�^
//! @parameter [position] ���W
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void SetPositionPrimitiveBox(PrimitiveBox* box, Vector2* position)
{
	box->position = CreateVector2(position->x, position->y);
}



//--------------------------------------------------------------------
//! @summary   ��`�̕`��
//!
//! @parameter [box] �`�悷���`�f�[�^
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void DrawPrimitiveBox(PrimitiveBox* box)
{
	// ����A�E���̌v�Z
	float top = box->position.y - (box->size.y * 0.5f);
	float bottom = box->position.y + (box->size.y * 0.5f);
	float right = box->position.x + (box->size.x * 0.5f);
	float left = box->position.x - (box->size.x * 0.5f);

	// �`��
	DrawBoxAA(left, top, right, bottom, box->color, box->fillFlag);
}