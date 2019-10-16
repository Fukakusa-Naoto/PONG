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
// 画面の上下での移動制限
void LimitScreen(Ball* ball);


// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   ボールの初期化処理
//!
//! @parameter [ball] 初期化するボール
//! @parameter [position] 座標
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializeBall(Ball* ball, Vector2* position)
{
	// ゲームオブジェクトの初期化処理
	InitializeGameObject(&ball->gameObject, position, &CreateVector2(BALL_SPEED, BALL_SPEED), 1);

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
	// ボールの移動
	MoveGameObject(&ball->gameObject);

	// 移動制限
	LimitScreen(ball);

	// 位置同期
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
	// 描画前に位置同期を行う
	SetPositionPrimitiveBox(&ball->primitiveBox, &ball->gameObject.position);

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



//--------------------------------------------------------------------
//! @summary   ボールのリセット処理
//!
//! @parameter [ball] リセットするボール
//!
//! @return    なし
//--------------------------------------------------------------------
void ResetBall(Ball* ball)
{
	// 初期位置に戻す
	ball->gameObject.position = CreateVector2(BALL_START_POSITION_X, BALL_START_POSITION_Y);

	// 位置同期
	SetPositionBoxCollider(&ball->boxCollider, &ball->gameObject.position);
}



//--------------------------------------------------------------------
//! @summary   ボールが画面のどちらから出たか
//!
//! @parameter [ball] 調べるボール
//!
//! @return    出た方向の値
//--------------------------------------------------------------------
SideID GetOutSide(Ball* ball)
{
	if (ball->gameObject.position.x <= 0) return SIDE_LEFT;
	else if (ball->gameObject.position.x >= SCREEN_WIDTH) return SIDE_RIGHT;
	else return SIDE_NONE;
}



//--------------------------------------------------------------------
//! @summary   画面の上下での移動制限
//!
//! @parameter [ball] 制限をかけるボール
//!
//! @return    なし
//--------------------------------------------------------------------
void LimitScreen(Ball* ball)
{
	// 衝突判定の位置同期を行う
	SetPositionBoxCollider(&ball->boxCollider, &ball->gameObject.position);

	if ((ball->boxCollider.position.y - (ball->boxCollider.size.y * 0.5f) <= 0)
		|| ((ball->boxCollider.position.y + (ball->boxCollider.size.y * 0.5f) >= SCREEN_HEIGHT)))
	{
		// 反転させる
		TurnOverVector2Y(&ball->gameObject.velocity);
	}
}