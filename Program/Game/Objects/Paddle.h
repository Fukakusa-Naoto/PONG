//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Paddle.h
//!
//! @summary	�p�h���Ɋւ���w�b�_�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ===================================================
#pragma once


// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "GameObject.h"


// �萔�̒�` ==============================================================
// �p�h���̉���
#define PADDLE_WIDTH (8.0f)
// �p�h���̍���
#define PADDLE_HEIGHT (28.0f)

// �p�h���̈ړ������̃G���A X
#define PADDLE_LIMIT_AREA_X (64.0f)
// �p�h���̈ړ������̃G���A Y
#define PADDLE_LIMIT_AREA_Y (PADDLE_HEIGHT)

// ���p�h���̏����ʒu X
#define LEFT_PADDLE_START_POSITION_X (PADDLE_LIMIT_AREA_X)
// ���p�h���̏����ʒu Y
#define LEFT_PADDLE_START_POSITION_Y (SCREEN_CENTER_Y)

// �E�p�h���̏����ʒu X
#define RIGHT_PADDLE_START_POSITION_X (SCREEN_WIDTH - PADDLE_LIMIT_AREA_X)
// ���p�h���̏����ʒu Y
#define RIGHT_PADDLE_START_POSITION_Y (SCREEN_CENTER_Y)


// �\���̂̒�` ============================================================
struct Tag_Paddle
{
	GameObject gameObject;
	// �`��
	PrimitiveBox primitiveBox;
	// �Փ˔���
	BoxCollider boxCollider;
};
typedef struct Tag_Paddle Paddle;



// �֐��̐錾 ==============================================================
//--------------------------------------------------------------------
//! @summary   �p�h���̏���������
//!
//! @parameter [paddle] ����������p�h��
//! @parameter [position] ���W
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void InitializePaddle(Paddle* paddle, Vector2* position);



//--------------------------------------------------------------------
//! @summary   �p�h���̍X�V����
//!
//! @parameter [paddle] �X�V����p�h��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void UpdatePaddle(Paddle* paddle);



//--------------------------------------------------------------------
//! @summary   �p�h���̕`�揈��
//!
//! @parameter [paddle] �`�悷��p�h��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void RenderPaddle(Paddle* paddle);



//--------------------------------------------------------------------
//! @summary   �p�h���̍폜����
//!
//! @parameter [paddle] �폜����p�h��
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void DestroyPaddle(Paddle* paddle);
