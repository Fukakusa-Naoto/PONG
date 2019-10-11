//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		CollisionManager.cpp
//!
//! @summary	�Փ˔���Ƀ\�[�X�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "CollisionManager.h"


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   BoxCollider���m�̏Փ˔���
//!
//! @parameter [collider1] ������s��BoxCollider1
//! @parameter [collider2] ������s��BoxCollider2
//!
//! @return    TRUE :�������Ă���
//! @return    FALSE:�������Ă��Ȃ�
//--------------------------------------------------------------------
BOOL IsCollideAABB(const BoxCollider* collider1, const BoxCollider* collider2)
{
	float top1 = collider1->position.y - (collider1->size.y * 0.5f);
	float bottom1 = collider1->position.y + (collider1->size.y * 0.5f);
	float left1 = collider1->position.x - (collider1->size.x * 0.5f);
	float right1 = collider1->position.x + (collider1->size.x * 0.5f);

	float top2 = collider2->position.y - (collider2->size.y * 0.5f);
	float bottom2 = collider2->position.y + (collider2->size.y * 0.5f);
	float left2 = collider2->position.x - (collider2->size.x * 0.5f);
	float right2 = collider2->position.x + (collider2->size.x * 0.5f);

	if ((top1 <= bottom2) && (bottom1 >= top2) && (left1 <= right2) && (right1 >= left2)) return TRUE;
	else return FALSE;
}