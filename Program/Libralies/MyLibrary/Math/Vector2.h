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


// �֐��̐錾 ==============================================================
//--------------------------------------------------------------------
//! @summary   Vector2���쐬����
//!
//! @parameter [x] x�̒l
//! @parameter [y] y�̒l
//!
//! @return    x,y�����ɍ��ꂽVector2
//--------------------------------------------------------------------
Vector2 CreateVector2(float x, float y);
Vector2Int CreateVector2Int(int x, int y);



//--------------------------------------------------------------------
//! @summary   Vector2��x,y�̒l��0��Vector2��Ԃ�
//!
//! @parameter [void] �Ȃ�
//!
//! @return    x,y��0��Vector2
//--------------------------------------------------------------------
Vector2 GetVector2Zero();
Vector2Int GetVector2IntZero();



//--------------------------------------------------------------------
//! @summary   Vector2��x,y�̒l��1��Vector2��Ԃ�
//!
//! @parameter [void] �Ȃ�
//!
//! @return    x,y��1��Vector2
//--------------------------------------------------------------------
Vector2 GetVector2One();
Vector2Int GetVector2IntOne();



//--------------------------------------------------------------------
//! @summary   Vector2�̑����Z
//!
//! @parameter [v1] �����Z���s��Vector2�̒l1
//! @parameter [v2] �����Z���s��Vector2�̒l2
//!
//! @return    v1��v2�𑫂������Vector2
//--------------------------------------------------------------------
Vector2 AddVector2(Vector2* v1, Vector2* v2);
Vector2Int AddVector2Int(Vector2Int* v1, Vector2Int* v2);



//--------------------------------------------------------------------
//! @summary   Vector2�̈����Z
//!
//! @parameter [v1] �����Z���s��Vector2�̒l1
//! @parameter [v2] �����Z���s��Vector2�̒l2
//!
//! @return    v1����v2�����������Vector2
//--------------------------------------------------------------------
Vector2 SubVector2(Vector2* v1, Vector2* v2);
Vector2Int SubVector2(Vector2Int* v1, Vector2Int* v2);



//--------------------------------------------------------------------
//! @summary   Vector2�̃X�P�[���v�Z
//!
//! @parameter [vector2] ����Vector2
//! @parameter [scale] �䗦
//!
//! @return    vector2��x,y��scale��x,y���|�����l
//--------------------------------------------------------------------
Vector2 SceleVector2(Vector2* vector2, Vector2* scale);



//--------------------------------------------------------------------
//! @summary   �x�N�g����X�����𔽓]������
//!
//! @parameter [vector2] ���]������vector2
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void TurnOverVector2X(Vector2* vector2);
void TurnOverVector2IntX(Vector2Int* vector2);



//--------------------------------------------------------------------
//! @summary   �x�N�g����Y�����𔽓]������
//!
//! @parameter [vector2] ���]������vector2
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void TurnOverVector2Y(Vector2* vector2);
void TurnOverVector2IntY(Vector2Int* vector2);



//--------------------------------------------------------------------
//! @summary   �x�N�g���̐��K��
//!
//! @parameter [vector] ���K������x�N�g��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void NormalizeVector2(Vector2* vector);



//--------------------------------------------------------------------
//! @summary   �����Ƒ������瑬�x���쐬����
//!
//! @parameter [direction] �����x�N�g��
//! @parameter [speed] ����
//!
//! @return    �쐬���ꂽ���x
//--------------------------------------------------------------------
Vector2 CreateVelocity(Vector2* direction, float speed);