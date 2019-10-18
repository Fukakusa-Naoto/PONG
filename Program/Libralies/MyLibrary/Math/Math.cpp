//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Math.cpp
//!
//! @summary	���w�Ɋւ���\�[�X�t�@�C��
//!
//! @date		2019.10.18
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <�W���w�b�_�t�@�C��>
#include <math.h>
#include <float.h>

// <����w�b�_�t�@�C��>
#include "Math.h"


// �֐��̐錾 ==============================================================
//--------------------------------------------------------------------
//! @summary   float�l�̔�r
//!
//! @parameter [valueA] ��r���s��float�lA
//! @parameter [valueB] ��r���s��float�lB
//!
//! @return    TRUE :������
//! @return    FALSE:�������Ȃ�
//--------------------------------------------------------------------
BOOL Approximately(float valueA, float valueB)
{
	// �����v�Z����
	float difference = (float)fabs((float)(valueA - valueB));
	valueA = (float)fabs((float)valueA);
	valueB = (float)fabs((float)valueB);

	// �ő�̂��̂�������
	float largest = (valueB > valueA) ? valueB : valueA;

	if (difference <= largest * FLT_EPSILON) return TRUE;
	else return FALSE;
}

