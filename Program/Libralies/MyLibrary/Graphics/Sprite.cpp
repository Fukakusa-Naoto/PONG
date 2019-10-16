//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Sprite.cpp
//!
//! @summary	�摜�`��Ɋւ���\�[�X�t�@�C��
//!
//! @date		2019.10.11
//!
//! @author		�[�����l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� =================================================
// <����w�b�_�t�@�C��>
#include "Sprite.h"


// �֐��̒�` ==============================================================
//--------------------------------------------------------------------
//! @summary   �摜�̕`��
//!
//! @parameter [sprite] �`�悷��X�v���C�g�f�[�^
//!
//! @return    �Ȃ�
//--------------------------------------------------------------------
void DrawSprite(Sprite* sprite)
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