//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Ball.h
//!
//! @summary	ボールに関するヘッダファイル
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
#include "../GameMain.h"
#include "../Scenes/PlayScene.h"


// 定数の定義 ==============================================================
// ボールの横幅
#define BALL_WIDTH (8.0f)
// ボールの高さ
#define BALL_HEIGHT (8.0f)

// ボールの初期位置 X
#define BALL_START_POSITION_X (SCREEN_CENTER_X)
// ボールの初期位置 Y
#define BALL_START_POSITION_Y (SCREEN_CENTER_Y)

// ボールの速さ
#define BALL_SPEED (5.0f)


// 構造体の定義 ============================================================
struct Tag_Ball
{
	GameObject gameObject;
	// 描画
	PrimitiveBox primitiveBox;
	// 衝突判定
	BoxCollider boxCollider;
};
typedef struct Tag_Ball Ball;



// 関数の宣言 ==============================================================
//--------------------------------------------------------------------
//! @summary   ボールの初期化処理
//!
//! @parameter [ball] 初期化するボール
//! @parameter [position] 座標
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializeBall(Ball* ball, const Vector2* position);



//--------------------------------------------------------------------
//! @summary   ボールの更新処理
//!
//! @parameter [ball] 更新するボール
//!
//! @return    なし
//--------------------------------------------------------------------
void UpdateBall(Ball* ball);



//--------------------------------------------------------------------
//! @summary   ボールの描画処理
//!
//! @parameter [ball] 描画するボール
//!
//! @return    なし
//--------------------------------------------------------------------
void RenderBall(Ball* ball);



//--------------------------------------------------------------------
//! @summary   ボールの削除処理
//!
//! @parameter [ball] 削除するボール
//!
//! @return    なし
//--------------------------------------------------------------------
void DestroyBall(Ball* ball);



//--------------------------------------------------------------------
//! @summary   ボールのリセット処理
//!
//! @parameter [ball] リセットするボール
//!
//! @return    なし
//--------------------------------------------------------------------
void ResetBall(Ball* ball);



//--------------------------------------------------------------------
//! @summary   ボールが画面のどちらから出たか
//!
//! @parameter [ball] 調べるボール
//!
//! @return    出た方向の値
//--------------------------------------------------------------------
SideID GetOutSide(const Ball* ball);
