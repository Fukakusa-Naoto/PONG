//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		BoxCollider.h
//!
//! @summary	衝突判定に使用する矩形データのヘッダファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ===================================================
#pragma once


// 構造体の定義 ============================================================
struct Tag_BoxCollider
{
	// 座標
	Vector2 position;
	// サイズ
	Vector2 size;
};
typedef struct Tag_BoxCollider BoxCollider;



// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   BoxColliderの初期化処理
//!
//! @parameter [collider] 初期化するコライダー
//! @parameter [position] 座標
//! @parameter [size] サイズ
//!
//! @return    なし
//--------------------------------------------------------------------
static void InitializeBoxCollider(BoxCollider* collider, const Vector2* position, const Vector2* size)
{
	collider->position = CreateVector2(position->x, position->y);
	collider->size = CreateVector2(size->x, size->y);
}



//--------------------------------------------------------------------
//! @summary   BoxColliderの座標の設定
//!
//! @parameter [collider] 設定するコライダー
//! @parameter [position] 座標
//!
//! @return    なし
//--------------------------------------------------------------------
static void SetPositionBoxCollider(BoxCollider* collider, const Vector2* position)
{
	collider->position = CreateVector2(position->x, position->y);
}



//--------------------------------------------------------------------
//! @summary   BoxColliderのデバッグ表示
//!
//! @parameter [collider] 表示するコライダーデータ
//! @parameter [color] 表示する色
//! @parameter [fillFlag] 塗りつぶしフラグ（TRUE:塗りつぶす, FALSE:塗りつぶさない）
//!
//! @return    なし
//--------------------------------------------------------------------
static void DispleyBoxCollider(const BoxCollider* collider, unsigned int color, BOOL fillFlag)
{
	// 左上、右下の計算
	float top = collider->position.y - (collider->size.y * 0.5f);
	float bottom = collider->position.y + (collider->size.y * 0.5f);
	float right = collider->position.x + (collider->size.x * 0.5f);
	float left = collider->position.x - (collider->size.x * 0.5f);

	// 描画
	DrawBoxAA(left, top, right, bottom, color, fillFlag);
}