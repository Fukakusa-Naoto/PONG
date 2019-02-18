//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameGraphics.h
//!
//! @brief  DxLib�̐}�`�`��֘A�̃w���p�[�֐��̃w�b�_�t�@�C��
//!
//! @date   2017/3/27
//!
//! @author ���� �W
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once




// �萔�̒�` ==============================================================

// �F��(�W���J���[16�F) 
enum ColorName : unsigned int
{
	COLOR_BLACK   = 0xFF000000,
	COLOR_NAVY    = 0xFF000080,
	COLOR_GREEN   = 0xFF008000,
	COLOR_TEAL    = 0xFF008080,
	COLOR_MAROON  = 0xFF800000,
	COLOR_PURPLE  = 0xFF800080,
	COLOR_OLIVE   = 0xFF808000,
	COLOR_GRAY    = 0xFF808080,
	COLOR_SILVER  = 0xFFC0C0C0,
	COLOR_BLUE    = 0xFF0000FF,
	COLOR_LIME    = 0xFF00FF00,
	COLOR_AQUA    = 0xFF00FFFF,
	COLOR_RED     = 0xFFFF0000,
	COLOR_FUCHSIA = 0xFFFF00FF,
	COLOR_YELLOW  = 0xFFFFFF00,
	COLOR_WHITE   = 0xFFFFFFFF,
};




// �֐��̐錾 ==============================================================

// �j����`��
int DrawDashedLine(int x1, int y1, int x2, int y2, unsigned int color, int length, int thickness);

// �j����`��(�A���`�G�C���A�X���ʕt��)
int DrawDashedLineAA(float x1, float y1, float x2, float y2, unsigned int color, float length, float thickness);
