//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		PrimitiveBox.cpp
//!
//! @summary	矩形の描画に関するソースファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "PrimitiveBox.h"


// 関数の定義 ==============================================================
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
void InitializePrimitiveBox(PrimitiveBox* box, Vector2* position, Vector2* size, unsigned int color, BOOL fillFlag)
{
	box->position = CreateVector2(position->x, position->y);
	box->size = CreateVector2(size->x, size->y);
	box->color = color;
	box->fillFlag = fillFlag;
}



//--------------------------------------------------------------------
//! @summary   矩形の座標の設定
//!
//! @parameter [box] 設定する矩形データ
//! @parameter [position] 座標
//!
//! @return    なし
//--------------------------------------------------------------------
void SetPositionPrimitiveBox(PrimitiveBox* box, Vector2* position)
{
	box->position = CreateVector2(position->x, position->y);
}



//--------------------------------------------------------------------
//! @summary   矩形の描画
//!
//! @parameter [box] 描画する矩形データ
//!
//! @return    なし
//--------------------------------------------------------------------
void DrawPrimitiveBox(PrimitiveBox* box)
{
	// 左上、右下の計算
	float top = box->position.y - (box->size.y * 0.5f);
	float bottom = box->position.y + (box->size.y * 0.5f);
	float right = box->position.x + (box->size.x * 0.5f);
	float left = box->position.x - (box->size.x * 0.5f);

	// 描画
	DrawBoxAA(left, top, right, bottom, box->color, box->fillFlag);
}