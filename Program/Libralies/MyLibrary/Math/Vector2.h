//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Vector2.h
//!
//! @summary	Vector2�Ɋւ���w�b�_�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ===================================================
#pragma once


// �\���̂̒�` ============================================================
struct Tag_Vector2
{
	float x;
	float y;
};
typedef struct Tag_Vector2 Vector2;

struct Tag_Vector2Int
{
	int x;
	int y;
};
typedef struct Tag_Vector2Int Vector2Int;


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   Vector2��x,y�̒l��0��Vector2��Ԃ�
//!
//! @parameter [void] �Ȃ�
//!
//! @return    x,y��0��Vector2
//--------------------------------------------------------------------
static Vector2 GetVector2Zero()
{
	Vector2 zero;
	ZeroMemory(&zero, sizeof(Vector2));
	return zero;
}



static Vector2Int GetVector2IntZero()
{
	Vector2Int zero;
	ZeroMemory(&zero, sizeof(Vector2Int));
	return zero;
}



//--------------------------------------------------------------------
//! @summary   Vector2��x,y�̒l��1��Vector2��Ԃ�
//!
//! @parameter [void] �Ȃ�
//!
//! @return    x,y��1��Vector2
//--------------------------------------------------------------------
static Vector2 GetVector2One()
{
	Vector2 zero = { 1.0f, 1.0f };
	return zero;
}



static Vector2Int GetVector2IntOne()
{
	Vector2Int zero = { 1, 1 };
	return zero;
}



//--------------------------------------------------------------------
//! @summary   Vector2�̑����Z
//!
//! @parameter [v1] �����Z���s��Vector2�̒l1
//! @parameter [v2] �����Z���s��Vector2�̒l2
//!
//! @return    v1��v2�𑫂������Vector2
//--------------------------------------------------------------------
static Vector2 AddVector2(const Vector2* v1, const Vector2* v2)
{
	Vector2 answer;
	answer.x = v1->x + v2->x;
	answer.y = v1->y + v2->y;
	return answer;
}



static Vector2Int AddVector2Int(const Vector2Int* v1, const Vector2Int* v2)
{
	Vector2Int answer;
	answer.x = v1->x + v2->x;
	answer.y = v1->y + v2->y;
	return answer;
}



//--------------------------------------------------------------------
//! @summary   Vector2�̈����Z
//!
//! @parameter [v1] �����Z���s��Vector2�̒l1
//! @parameter [v2] �����Z���s��Vector2�̒l2
//!
//! @return    v1����v2�����������Vector2
//--------------------------------------------------------------------
static Vector2 SubVector2(const Vector2* v1, const Vector2* v2)
{
	Vector2 answer;
	answer.x = v1->x - v2->x;
	answer.y = v1->y - v2->y;
	return answer;
}



static Vector2Int SubVector2(const Vector2Int* v1, const Vector2Int* v2)
{
	Vector2Int answer;
	answer.x = v1->x - v2->x;
	answer.y = v1->y - v2->y;
	return answer;
}



//--------------------------------------------------------------------
//! @summary   Vector2�̃X�P�[���v�Z
//!
//! @parameter [vector2] ����Vector2
//! @parameter [scale] �䗦
//!
//! @return    vector2��x,y��scale��x,y���|�����l
//--------------------------------------------------------------------
static Vector2 SceleVector2(const Vector2* vector2, const Vector2* scale)
{
	Vector2 answer;
	answer.x = vector2->x * scale->x;
	answer.y = vector2->y * scale->y;
	return answer;
}