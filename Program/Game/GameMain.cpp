//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		GameMain.cpp
//!
//! @summary	ゲーム関連のソースファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "GameMain.h"
#include "Scenes/SceneManager.h"


// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   ゲームの初期化処理
//!
//! @parameter [gameMainObject] ゲーム上で使用する全てのオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializeGame(GameMainObject* gameMainObject)
{
	// 最初のシーンを設定
	SetStartScene(SCENE_PLAY);

	// シーンの初期化処理
	InitializeScene(gameMainObject);
}



//--------------------------------------------------------------------
//! @summary   ゲームの更新処理
//!
//! @parameter [gameMainObject] ゲーム上で使用する全てのオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void UpdateGame(GameMainObject* gameMainObject)
{
	// シーンの更新処理
	UpdateScene(gameMainObject);
}



//--------------------------------------------------------------------
//! @summary   ゲームの描画処理
//!
//! @parameter [gameMainObject] ゲーム上で使用する全てのオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void RenderGame(GameMainObject* gameMainObject)
{
	// シーンの描画処理
	RenderScene(gameMainObject);
}



//--------------------------------------------------------------------
//! @summary   ゲームの終了処理
//!
//! @parameter [gameMainObject] ゲーム上で使用する全てのオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void FinalizeGame(GameMainObject* gameMainObject)
{
	// シーンの終了処理
	FinalizeScene(gameMainObject);
}
