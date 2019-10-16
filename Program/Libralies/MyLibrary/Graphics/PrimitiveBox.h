//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		PrimitiveBox.h
//!
//! @summary	矩形の描画に関するヘッダファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ===================================================
#pragma once


// 構造体の定義 ============================================================
struct Tag_PrimitiveBox
{
	// 描画する中心座標
	Vector2 position;
	// 描画する幅と高さ（x:幅, y:高さ）
	Vector2 size;
	// 色
	unsigned int color;
	// 塗りつぶしフラグ（TRUE:塗りつぶす, FALSE:塗りつぶさない）
	BOOL fillFlag;
};
typedef struct Tag_PrimitiveBox PrimitiveBox;



// 関数の宣言 ==============================================================
//--------------------------------------------------------------------
//! @summary   矩形の初期化処理
//!
//! @parameter [box] 初期化する矩形データ
//! @parameter [position] 座標
//! @parameter [size] サイズ
//! @parameter [color] 色
//! @parameter [fillFlag] 塗りつぶしフラグ（TRUE:塗りつぶす, FALSE:塗りつぶさない）
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializePrimitiveBox(PrimitiveBox* box, Vector2* position, Vector2* size, unsigned int color, BOOL fillFlag);



//--------------------------------------------------------------------
//! @summary   矩形の座標の設定
//!
//! @parameter [box] 設定する矩形データ
//! @parameter [position] 座標
//!
//! @return    なし
//--------------------------------------------------------------------
void SetPositionPrimitiveBox(PrimitiveBox* box, Vector2* position);



//--------------------------------------------------------------------
//! @summary   矩形の描画
//!
//! @parameter [box] 描画する矩形データ
//!
//! @return    なし
//--------------------------------------------------------------------
void DrawPrimitiveBox(PrimitiveBox* box);
