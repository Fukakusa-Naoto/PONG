//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Vector2.cpp
//!
//! @summary	Vector2�Ɋւ���\�[�X�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "Vector2.h"


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   Vector2���쐬����
//!
//! @parameter [x] x�̒l
//! @parameter [y] y�̒l
//!
//! @return    x,y�����ɍ��ꂽVector2
//--------------------------------------------------------------------
Vector2 CreateVector2(float x, float y)
{
	Vector2 v = { x, y };
	return v;
}



Vector2Int CreateVector2Int(int x, int y)
{
	Vector2Int v = { x, y };
	return v;
}



//--------------------------------------------------------------------
//! @summary   Vector2��x,y�̒l��0��Vector2��Ԃ�
//!
//! @parameter [void] �Ȃ�
//!
//! @return    x,y��0��Vector2
//--------------------------------------------------------------------
Vector2 GetVector2Zero()
{
	Vector2 zero;
	ZeroMemory(&zero, sizeof(Vector2));
	return zero;
}



Vector2Int GetVector2IntZero()
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
Vector2 GetVector2One()
{
	Vector2 zero = CreateVector2(1.0f, 1.0f);
	return zero;
}



Vector2Int GetVector2IntOne()
{
	Vector2Int zero = CreateVector2Int(1, 1);
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
Vector2 AddVector2(Vector2* v1, Vector2* v2)
{
	Vector2 answer;

	answer.x = v1->x + v2->x;
	answer.y = v1->y + v2->y;
	return answer;
}



Vector2Int AddVector2Int(Vector2Int* v1, Vector2Int* v2)
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
Vector2 SubVector2(Vector2* v1, Vector2* v2)
{
	Vector2 answer;
	answer.x = v1->x - v2->x;
	answer.y = v1->y - v2->y;
	return answer;
}



Vector2Int SubVector2(Vector2Int* v1, Vector2Int* v2)
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
Vector2 SceleVector2(Vector2* vector2, Vector2* scale)
{
	Vector2 answer;
	answer.x = vector2->x * scale->x;
	answer.y = vector2->y * scale->y;
	return answer;
}


//--------------------------------------------------------------------
//! @summary   �x�N�g����X�����𔽓]������
//!
//! @parameter [vector2] ���]������vector2
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void TurnOverVector2X(Vector2* vector2)
{
	vector2->x *= -1.0f;
}



void TurnOverVector2IntX(Vector2Int* vector2)
{
	vector2->x *= -1;
}



//--------------------------------------------------------------------
//! @summary   �x�N�g����Y�����𔽓]������
//!
//! @parameter [vector2] ���]������vector2
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void TurnOverVector2Y(Vector2* vector2)
{
	vector2->y *= -1.0f;
}



void TurnOverVector2IntY(Vector2Int* vector2)
{
	vector2->y *= -1;
}
