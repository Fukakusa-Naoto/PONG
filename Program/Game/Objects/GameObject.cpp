//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		GameObject.cpp
//!
//! @summary	ゲームオブジェクトに関するソースファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "GameObject.h"


// 関数の定義 ==============================================================
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
void InitializeGameObject(GameObject* gameObject, Vector2* position, Vector2* velocity, unsigned int state)
{
	gameObject->position = CreateVector2(position->x, position->y);
	gameObject->velocity = CreateVector2(velocity->x, velocity->y);
	gameObject->state = state;
}



//--------------------------------------------------------------------
//! @summary   オブジェクトの移動処理
//!
//! @parameter [gameObject] 移動させるオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void MoveGameObject(GameObject* gameObject)
{
	gameObject->position = AddVector2(&gameObject->position, &gameObject->velocity);
}