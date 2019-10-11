//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		PlayScene.cpp
//!
//! @summary	プレイシーン関連のソースファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "PlayScene.h"
#include "SceneManager.h"
#include "../Objects/Paddle.h"
#include "../Objects/Ball.h"


// グローバル変数の定義 =====================================================
// 左パドル
Paddle g_leftPaddle;
// 右パドル
Paddle g_rightPaddle;
// ボール
Ball g_ball;


// 関数の定義 ==============================================================
// 試合の判定処理
void JudgeGame(void);


// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   プレイシーンの初期化処理
//!
//! @parameter [void] なし
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializePlayScene(void)
{
	// 左パドルの初期化処理
	InitializePaddle(&g_leftPaddle, &CreateVector2(LEFT_PADDLE_START_POSITION_X, LEFT_PADDLE_START_POSITION_Y));
	// 右パドルの初期化処理
	InitializePaddle(&g_rightPaddle, &CreateVector2(RIGHT_PADDLE_START_POSITION_X, RIGHT_PADDLE_START_POSITION_Y));
	// ボールの初期化処理
	InitializeBall(&g_ball, &CreateVector2(BALL_START_POSITION_X, BALL_START_POSITION_Y));
}



//--------------------------------------------------------------------
//! @summary   プレイシーンの更新処理
//!
//! @parameter [void] なし
//!
//! @return    なし
//--------------------------------------------------------------------
void UpdatePlayScene(void)
{
	// 左パドルの更新処理
	UpdatePaddle(&g_leftPaddle);
	// 右パドルの更新処理
	UpdatePaddle(&g_rightPaddle);
	// ボールの更新処理
	UpdateBall(&g_ball);

	// 試合の判定処理
	JudgeGame();
}



//--------------------------------------------------------------------
//! @summary   プレイシーンの描画処理
//!
//! @parameter [void] なし
//!
//! @return    なし
//--------------------------------------------------------------------
void RenderPlayScene(void)
{
	// 左パドルの描画処理
	RenderPaddle(&g_leftPaddle);
	// 右パドルの描画処理
	RenderPaddle(&g_rightPaddle);
	// ボールの初期化処理
	RenderBall(&g_ball);
}



//--------------------------------------------------------------------
//! @summary   プレイシーンの終了処理
//!
//! @parameter [void] なし
//!
//! @return    なし
//--------------------------------------------------------------------
void FinalizePlayScene(void)
{
	// 左パドルの削除
	DestroyPaddle(&g_leftPaddle);
	// 右パドルの削除
	DestroyPaddle(&g_rightPaddle);
	// ボールの削除
	DestroyBall(&g_ball);
}



//--------------------------------------------------------------------
//! @summary   試合の判定処理
//!
//! @parameter [void] なし
//!
//! @return    なし
//--------------------------------------------------------------------
void JudgeGame(void)
{
	// 得点の判定
	if (GetOutSide(&g_ball) == SIDE_LEFT)	// 左
	{
		// ボールを元の位置に戻す
		ResetBall(&g_ball);
	}
	else if (GetOutSide(&g_ball) == SIDE_RIGHT)	// 右
	{
		// ボールを元の位置に戻す
		ResetBall(&g_ball);
	}
}
