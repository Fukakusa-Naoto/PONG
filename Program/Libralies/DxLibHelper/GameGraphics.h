//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameGraphics.h
//!
//! @brief  DxLibの図形描画関連のヘルパー関数のヘッダファイル
//!
//! @date   2017/3/27
//!
//! @author 高木 晋
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once




// 定数の定義 ==============================================================

// 色名(標準カラー16色) 
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




// 関数の宣言 ==============================================================

// 破線を描画
int DrawDashedLine(int x1, int y1, int x2, int y2, unsigned int color, int length, int thickness);

// 破線を描画(アンチエイリアス効果付き)
int DrawDashedLineAA(float x1, float y1, float x2, float y2, unsigned int color, float length, float thickness);
