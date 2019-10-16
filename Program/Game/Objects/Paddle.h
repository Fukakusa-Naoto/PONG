//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Paddle.h
//!
//! @summary	パドルに関するヘッダファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ===================================================
#pragma once


// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "GameObject.h"


// 定数の定義 ==============================================================
// パドルの横幅
#define PADDLE_WIDTH (8.0f)
// パドルの高さ
#define PADDLE_HEIGHT (28.0f)

// パドルの移動制限のエリア X
#define PADDLE_LIMIT_AREA_X (64.0f)
// パドルの移動制限のエリア Y
#define PADDLE_LIMIT_AREA_Y (PADDLE_HEIGHT)

// 左パドルの初期位置 X
#define LEFT_PADDLE_START_POSITION_X (PADDLE_LIMIT_AREA_X)
// 左パドルの初期位置 Y
#define LEFT_PADDLE_START_POSITION_Y (SCREEN_CENTER_Y)

// 右パドルの初期位置 X
#define RIGHT_PADDLE_START_POSITION_X (SCREEN_WIDTH - PADDLE_LIMIT_AREA_X)
// 左パドルの初期位置 Y
#define RIGHT_PADDLE_START_POSITION_Y (SCREEN_CENTER_Y)


// 構造体の定義 ============================================================
struct Tag_Paddle
{
	GameObject gameObject;
	// 描画
	PrimitiveBox primitiveBox;
	// 衝突判定
	BoxCollider boxCollider;
};
typedef struct Tag_Paddle Paddle;



// 関数の宣言 ==============================================================
//--------------------------------------------------------------------
//! @summary   パドルの初期化処理
//!
//! @parameter [paddle] 初期化するパドル
//! @parameter [position] 座標
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializePaddle(Paddle* paddle, Vector2* position);



//--------------------------------------------------------------------
//! @summary   パドルの更新処理
//!
//! @parameter [paddle] 更新するパドル
//!
//! @return    なし
//--------------------------------------------------------------------
void UpdatePaddle(Paddle* paddle);



//--------------------------------------------------------------------
//! @summary   パドルの描画処理
//!
//! @parameter [paddle] 描画するパドル
//!
//! @return    なし
//--------------------------------------------------------------------
void RenderPaddle(Paddle* paddle);



//--------------------------------------------------------------------
//! @summary   パドルの削除処理
//!
//! @parameter [paddle] 削除するパドル
//!
//! @return    なし
//--------------------------------------------------------------------
void DestroyPaddle(Paddle* paddle);
