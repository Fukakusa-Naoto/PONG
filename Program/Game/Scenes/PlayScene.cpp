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
#include "../Controllers/InputPaddleController.h"


// 関数の定義 ==============================================================
// 試合の判定処理
void JudgeGame(PlaySceneObject* playSceneObject);
// 衝突判定
void DetectCollisionPlayScene(PlaySceneObject* playSceneObject);


// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   プレイシーンの初期化処理
//!
//! @parameter [playSceneObject] プレイシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializePlayScene(PlaySceneObject* playSceneObject)
{
	// 左パドルの初期化処理
	InitializePaddle(&playSceneObject->leftPaddle, &CreateVector2(LEFT_PADDLE_START_POSITION_X, LEFT_PADDLE_START_POSITION_Y));
	// 右パドルの初期化処理
	InitializePaddle(&playSceneObject->rightPaddle, &CreateVector2(RIGHT_PADDLE_START_POSITION_X, RIGHT_PADDLE_START_POSITION_Y));
	// ボールの初期化処理
	InitializeBall(&playSceneObject->ball, &CreateVector2(BALL_START_POSITION_X, BALL_START_POSITION_Y));
}



//--------------------------------------------------------------------
//! @summary   プレイシーンの更新処理
//!
//! @parameter [playSceneObject] プレイシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void UpdatePlayScene(PlaySceneObject* playSceneObject)
{
	// 右パドルの入力制御
	ControlRightPaddle(&playSceneObject->rightPaddle);

	// 衝突判定
	DetectCollisionPlayScene(playSceneObject);

	// 左パドルの更新処理
	UpdatePaddle(&playSceneObject->leftPaddle);
	// 右パドルの更新処理
	UpdatePaddle(&playSceneObject->rightPaddle);
	// ボールの更新処理
	UpdateBall(&playSceneObject->ball);

	// 試合の判定処理
	JudgeGame(playSceneObject);
}



//--------------------------------------------------------------------
//! @summary   プレイシーンの描画処理
//!
//! @parameter [playSceneObject] プレイシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void RenderPlayScene(PlaySceneObject* playSceneObject)
{
	// 左パドルの描画処理
	RenderPaddle(&playSceneObject->leftPaddle);
	// 右パドルの描画処理
	RenderPaddle(&playSceneObject->rightPaddle);
	// ボールの初期化処理
	RenderBall(&playSceneObject->ball);
}



//--------------------------------------------------------------------
//! @summary   プレイシーンの終了処理
//!
//! @parameter [playSceneObject] プレイシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void FinalizePlayScene(PlaySceneObject* playSceneObject)
{
	// 左パドルの削除
	DestroyPaddle(&playSceneObject->leftPaddle);
	// 右パドルの削除
	DestroyPaddle(&playSceneObject->rightPaddle);
	// ボールの削除
	DestroyBall(&playSceneObject->ball);
}



//--------------------------------------------------------------------
//! @summary   試合の判定処理
//!
//! @parameter [playSceneObject] プレイシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void JudgeGame(PlaySceneObject* playSceneObject)
{
	// 得点の判定
	if (GetOutSide(&playSceneObject->ball) == SIDE_LEFT)	// 左
	{
		// ボールを元の位置に戻す
		ResetBall(&playSceneObject->ball);
	}
	else if (GetOutSide(&playSceneObject->ball) == SIDE_RIGHT)	// 右
	{
		// ボールを元の位置に戻す
		ResetBall(&playSceneObject->ball);
	}
}



//--------------------------------------------------------------------
//! @summary   衝突判定
//!
//! @parameter [playSceneObject] プレイシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void DetectCollisionPlayScene(PlaySceneObject* playSceneGameObject)
{
	// 左パドルとボール
	if (IsCollideAABB(&playSceneGameObject->leftPaddle.boxCollider, &playSceneGameObject->ball.boxCollider))
	{
		// 連続反転防止
		if (playSceneGameObject->leftPaddle.boxCollider.position.x <= playSceneGameObject->ball.boxCollider.position.x)
		{
			// ボールの向きを反転させる
			TurnOverVector2X(&playSceneGameObject->ball.gameObject.velocity);
		}
	}

	// 右パドルとボール
	if (IsCollideAABB(&playSceneGameObject->rightPaddle.boxCollider, &playSceneGameObject->ball.boxCollider))
	{
		// 連続反転防止
		if (playSceneGameObject->rightPaddle.boxCollider.position.x >= playSceneGameObject->ball.boxCollider.position.x)
		{
			// ボールの向きを反転させる
			TurnOverVector2X(&playSceneGameObject->ball.gameObject.velocity);
		}
	}
}