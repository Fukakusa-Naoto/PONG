//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Sprite.h
//!
//! @summary	Sprite�Ɋւ���w�b�_�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ===================================================
#pragma once


// �\���̂̒�` ============================================================
struct Tag_Sprite
{
	// �摜�̃n���h��
	HGRP handle;
	// �`�悷��摜�̒��S���W
	Vector2 position;
	// �`�悷��̈��uv���W�ix:u, y:v�j
	Vector2Int uv;
	// �`�悷��̈�̕��ƍ����ix:��, y:�����j
	Vector2Int size;
	// �g�嗦
	float scale;
	// ��]�p
	float angle;
	// �����x��L���ɂ��邩�ǂ����iTRUE:�L���ɂ���, FALSE:�����ɂ���j
	BOOL transFlag;
	// ���E���]���s�����iFALSE:�ʏ�`��, TRUE:���]�j
	BOOL turnFlag;
};
typedef struct Tag_Sprite Sprite;



// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   �摜�̕`��
//!
//! @parameter [sprite] �`�悷��X�v���C�g�f�[�^
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
static void DrawSprite(const Sprite* sprite)
{
	DrawRectRotaGraphF(
		sprite->position.x, sprite->position.y,
		sprite->uv.x, sprite->uv.y,
		sprite->size.x, sprite->size.y,
		sprite->scale,
		sprite->angle, sprite->handle,
		sprite->transFlag,
		sprite->turnFlag);
}