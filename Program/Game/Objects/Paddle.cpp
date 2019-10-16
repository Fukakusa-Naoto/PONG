//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Paddle.cpp
//!
//! @summary	パドルに関するソースファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "Paddle.h"
#include "../GameMain.h"


// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   パドルの初期化処理
//!
//! @parameter [paddle] 初期化するパドル
//! @parameter [position] 座標
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializePaddle(Paddle* paddle, Vector2* position)
{
	// ゲームオブジェクトの初期化処理
	InitializeGameObject(&paddle->gameObject, position, &GetVector2Zero(), 1);

	// パドルサイズの作成
	Vector2 size = CreateVector2(PADDLE_WIDTH, PADDLE_HEIGHT);

	// 描画の初期化処理
	InitializePrimitiveBox(&paddle->primitiveBox, &paddle->gameObject.position, &size, COLOR_WHITE, TRUE);

	// コライダーの初期化処理
	InitializeBoxCollider(&paddle->boxCollider, &paddle->gameObject.position, &size);
}



//--------------------------------------------------------------------
//! @summary   パドルの更新処理
//!
//! @parameter [paddle] 更新するパドル
//!
//! @return    なし
//--------------------------------------------------------------------
void UpdatePaddle(Paddle* paddle)
{
	// パドルの移動処理
	MoveGameObject(&paddle->gameObject);

	// パドルの移動制限
	LinitAreaPaddle(paddle);

	// 位置同期
	SetPositionPrimitiveBox(&paddle->primitiveBox, &paddle->gameObject.position);
	SetPositionBoxCollider(&paddle->boxCollider, &paddle->gameObject.position);
}



//--------------------------------------------------------------------
//! @summary   パドルの描画処理
//!
//! @parameter [paddle] 描画するパドル
//!
//! @return    なし
//--------------------------------------------------------------------
void RenderPaddle(Paddle* paddle)
{
	DrawPrimitiveBox(&paddle->primitiveBox);
}



//--------------------------------------------------------------------
//! @summary   パドルの削除処理
//!
//! @parameter [paddle] 削除するパドル
//!
//! @return    なし
//--------------------------------------------------------------------
void DestroyPaddle(Paddle* paddle)
{
	ZeroMemory(paddle, sizeof(Paddle));
}



//--------------------------------------------------------------------
//! @summary   パドルの移動制限
//!
//! @parameter [paddle] 制限をするパドル
//!
//! @return    なし
//--------------------------------------------------------------------
void LinitAreaPaddle(Paddle* paddle)
{
	// 上
	if (paddle->gameObject.position.y <= PADDLE_LIMIT_AREA_Y)
	{
		paddle->gameObject.position.y = PADDLE_LIMIT_AREA_Y;
	}

	// 下
	if (paddle->gameObject.position.y >= SCREEN_HEIGHT - PADDLE_LIMIT_AREA_Y)
	{
		paddle->gameObject.position.y = SCREEN_HEIGHT - PADDLE_LIMIT_AREA_Y;
	}
}