//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Sprite.h
//!
//! @summary	Spriteに関するヘッダファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ===================================================
#pragma once


// 構造体の定義 ============================================================
struct Tag_Sprite
{
	// 画像のハンドル
	HGRP handle;
	// 描画する画像の中心座標
	Vector2 position;
	// 描画する領域のuv座標（x:u, y:v）
	Vector2Int uv;
	// 描画する領域の幅と高さ（x:幅, y:高さ）
	Vector2Int size;
	// 拡大率
	float scale;
	// 回転角
	float angle;
	// 透明度を有効にするかどうか（TRUE:有効にする, FALSE:無効にする）
	BOOL transFlag;
	// 左右反転を行うか（FALSE:通常描画, TRUE:反転）
	BOOL turnFlag;
};
typedef struct Tag_Sprite Sprite;



// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   画像の描画
//!
//! @parameter [sprite] 描画するスプライトデータ
//!
//! @return    なし
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