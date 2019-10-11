//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Ball.cpp
//!
//! @summary	ボールに関するソースファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "Ball.h"


// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   ボールの初期化処理
//!
//! @parameter [ball] 初期化するボール
//! @parameter [position] 座標
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializeBall(Ball* ball, const Vector2* position)
{
	// ゲームオブジェクトの初期化処理
	InitializeGameObject(&ball->gameObject, position, &GetVector2Zero(), 1);

	// パドルサイズの作成
	Vector2 size = CreateVector2(BALL_WIDTH, BALL_HEIGHT);

	// 描画の初期化処理
	InitializePrimitiveBox(&ball->primitiveBox, &ball->gameObject.position, &size, COLOR_WHITE, TRUE);

	// コライダーの初期化処理
	InitializeBoxCollider(&ball->boxCollider, &ball->gameObject.position, &size);
}



//--------------------------------------------------------------------
//! @summary   ボールの更新処理
//!
//! @parameter [ball] 更新するボール
//!
//! @return    なし
//--------------------------------------------------------------------
void UpdateBall(Ball* ball)
{
	// 位置同期
	SetPositionPrimitiveBox(&ball->primitiveBox, &ball->gameObject.position);
	SetPositionBoxCollider(&ball->boxCollider, &ball->gameObject.position);
}



//--------------------------------------------------------------------
//! @summary   ボールの描画処理
//!
//! @parameter [ball] 描画するボール
//!
//! @return    なし
//--------------------------------------------------------------------
void RenderBall(Ball* ball)
{
	DrawPrimitiveBox(&ball->primitiveBox);
}



//--------------------------------------------------------------------
//! @summary   ボールの削除処理
//!
//! @parameter [ball] 削除するボール
//!
//! @return    なし
//--------------------------------------------------------------------
void DestroyBall(Ball* ball)
{
	ZeroMemory(ball, sizeof(Ball));
}