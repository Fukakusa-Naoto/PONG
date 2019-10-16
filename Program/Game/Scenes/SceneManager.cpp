//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		SceneManager.cpp
//!
//! @summary	シーン管理に関するソースファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "SceneManager.h"


// グローバル変数の宣言 =====================================================
// 現在のシーンID
static SceneID g_currentSceneID;
// 次のシーンID
static SceneID g_nextSceneID;


// 関数の宣言 ==============================================================
// シーンの切り替え処理
void SwitchScene(GameMainObject* gameMainObject);


// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   シーンの切り替え処理
//!
//! @parameter [nextSceneID] 次のシーンのID
//!
//! @return    なし
//--------------------------------------------------------------------
void ChangeScene(SceneID nextSceneID)
{
	// 次のシーンを予約
	g_nextSceneID = nextSceneID;
}



//--------------------------------------------------------------------
//! @summary   最初のシーンの設定
//!
//! @parameter [startSceneID] 最初のシーンのID
//!
//! @return    なし
//--------------------------------------------------------------------
void SetStartScene(SceneID startSceneID)
{
	// シーンIDの初期化
	g_currentSceneID = SCENE_NONE;
	g_nextSceneID = startSceneID;
}



//--------------------------------------------------------------------
//! @summary   シーンの初期化処理
//!
//! @parameter [gameMainObject] ゲーム上で使用する全てのオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializeScene(GameMainObject* gameMainObject)
{
	// シーン別の初期化処理
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// プレイ
		InitializePlayScene(&gameMainObject->playSceneObject);
		break;
	case SCENE_LOGO:	// ロゴ
		InitializeLogoScene();
		break;
	case SCENE_TITLE:	// タイトル
		InitializeTitleScene(&gameMainObject->titleSceneObject);
		break;
	default:
		// 何もしない
		break;
	}
}



//--------------------------------------------------------------------
//! @summary   シーンの更新処理
//!
//! @parameter [gameMainObject] ゲーム上で使用する全てのオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void UpdateScene(GameMainObject* gameMainObject)
{
	// シーンの切り替え
	SwitchScene(gameMainObject);

	// シーン別の更新処理
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// プレイ
		UpdatePlayScene(&gameMainObject->playSceneObject);
		break;
	case SCENE_LOGO:	// ロゴ
		UpdateLogoScene();
		break;
	case SCENE_TITLE:	// タイトル
		UpdateTitleScene(&gameMainObject->titleSceneObject);
		break;
	default:
		// 何もしない
		break;
	}
}



//--------------------------------------------------------------------
//! @summary   シーンの描画処理
//!
//! @parameter [gameMainObject] ゲーム上で使用する全てのオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void RenderScene(GameMainObject* gameMainObject)
{
	// シーン別の描画処理
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// プレイ
		RenderPlayScene(&gameMainObject->playSceneObject);
		break;
	case SCENE_LOGO:	// ロゴ
		RenderLogoScene();
		break;
	case SCENE_TITLE:	// タイトル
		RenderTitleScene(&gameMainObject->titleSceneObject);
		break;
	default:
		// 何もしない
		break;
	}
}



//--------------------------------------------------------------------
//! @summary   シーンの終了処理
//!
//! @parameter [gameMainObject] ゲーム上で使用する全てのオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void FinalizeScene(GameMainObject* gameMainObject)
{
	// シーン別の終了処理
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// プレイ
		FinalizePlayScene(&gameMainObject->playSceneObject);
		break;
	case SCENE_LOGO:	// ロゴ
		FinalizeLogoScene();
		break;
	case SCENE_TITLE:	// タイトル
		FinalizeTitleScene(&gameMainObject->titleSceneObject);
		break;
	default:
		// 何もしない
		break;
	}

}



//--------------------------------------------------------------------
//! @summary   シーンの切り替え処理
//!
//! @parameter [gameMainObject] ゲーム上で使用する全てのオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void SwitchScene(GameMainObject* gameMainObject)
{
	// シーンの変更があった場合
	if (g_nextSceneID != g_currentSceneID)
	{
		// 現在のシーンの終了処理
		FinalizeScene(gameMainObject);
		// シーンIDを新しくする
		g_currentSceneID = g_nextSceneID;
		// 新しいシーンの初期化処理
		InitializeScene(gameMainObject);
	}
}
