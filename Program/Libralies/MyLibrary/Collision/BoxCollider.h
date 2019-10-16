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



// 関数の宣言 ==============================================================
//--------------------------------------------------------------------
//! @summary   BoxColliderの初期化処理
//!
//! @parameter [collider] 初期化するコライダー
//! @parameter [position] 座標
//! @parameter [size] サイズ
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializeBoxCollider(BoxCollider* collider, Vector2* position, Vector2* size);



//--------------------------------------------------------------------
//! @summary   BoxColliderの座標の設定
//!
//! @parameter [collider] 設定するコライダー
//! @parameter [position] 座標
//!
//! @return    なし
//--------------------------------------------------------------------
void SetPositionBoxCollider(BoxCollider* collider, Vector2* position);



//--------------------------------------------------------------------
//! @summary   BoxColliderのデバッグ表示
//!
//! @parameter [collider] 表示するコライダーデータ
//! @parameter [color] 表示する色
//! @parameter [fillFlag] 塗りつぶしフラグ（TRUE:塗りつぶす, FALSE:塗りつぶさない）
//!
//! @return    なし
//--------------------------------------------------------------------
void DispleyBoxCollider(BoxCollider* collider, unsigned int color, BOOL fillFlag);