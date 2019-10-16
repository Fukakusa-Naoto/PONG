//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		GameObject.h
//!
//! @summary	ゲームオブジェクトに関するヘッダファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ===================================================
#pragma once


// 構造体の定義 ============================================================
struct Tag_GameObject
{
	// 座標
	Vector2 position;
	// 速度
	Vector2 velocity;
	// 状態
	unsigned int state;
};
typedef struct Tag_GameObject GameObject;


// 関数の宣言 ==============================================================
//--------------------------------------------------------------------
//! @summary   オブジェクトの初期化処理
//!
//! @parameter [gameObject] 初期化するオブジェクト
//! @parameter [position] 座標
//! @parameter [velocity] 速度
//! @parameter [state] 状態
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializeGameObject(GameObject* gameObject, Vector2* position, Vector2* velocity, unsigned int state);



//--------------------------------------------------------------------
//! @summary   オブジェクトの移動処理
//!
//! @parameter [gameObject] 移動させるオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void MoveGameObject(GameObject* gameObject);