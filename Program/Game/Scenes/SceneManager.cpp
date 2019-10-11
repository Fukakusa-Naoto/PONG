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
#include "PlayScene.h"
#include "LogoScene.h"
#include "TitleScene.h"


// グローバル変数の宣言 =====================================================
// 現在のシーンID
static SceneID g_currentSceneID;
// 次のシーンID
static SceneID g_nextSceneID;


// 関数の宣言 ==============================================================
// シーンの切り替え処理
void SwitchScene(void);


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
//! @parameter [void] なし
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializeScene(void)
{
	// シーン別の初期化処理
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// プレイ
		InitializePlayScene();
		break;
	case SCENE_LOGO:	// ロゴ
		InitializeLogoScene();
		break;
	case SCENE_TITLE:	// タイトル
		InitializeTitleScene();
		break;
	default:
		// 何もしない
		break;
	}
}



//--------------------------------------------------------------------
//! @summary   シーンの更新処理
//!
//! @parameter [void] なし
//!
//! @return    なし
//--------------------------------------------------------------------
void UpdateScene(void)
{
	// シーンの切り替え
	SwitchScene();

	// シーン別の更新処理
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// プレイ
		UpdatePlayScene();
		break;
	case SCENE_LOGO:	// ロゴ
		UpdateLogoScene();
		break;
	case SCENE_TITLE:	// タイトル
		UpdateTitleScene();
		break;
	default:
		// 何もしない
		break;
	}
}



//--------------------------------------------------------------------
//! @summary   シーンの描画処理
//!
//! @parameter [void] なし
//!
//! @return    なし
//--------------------------------------------------------------------
void RenderScene(void)
{
	// シーン別の描画処理
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// プレイ
		RenderPlayScene();
		break;
	case SCENE_LOGO:	// ロゴ
		RenderLogoScene();
		break;
	case SCENE_TITLE:	// タイトル
		RenderTitleScene();
		break;
	default:
		// 何もしない
		break;
	}
}



//--------------------------------------------------------------------
//! @summary   シーンの終了処理
//!
//! @parameter [void] なし
//!
//! @return    なし
//--------------------------------------------------------------------
void FinalizeScene(void)
{
	// シーン別の終了処理
	switch (g_currentSceneID)
	{
	case SCENE_PLAY:	// プレイ
		FinalizePlayScene();
		break;
	case SCENE_LOGO:	// ロゴ
		FinalizeLogoScene();
		break;
	case SCENE_TITLE:	// タイトル
		FinalizeTitleScene();
		break;
	default:
		// 何もしない
		break;
	}

}



//--------------------------------------------------------------------
//! @summary   シーンの切り替え処理
//!
//! @parameter [void] なし
//!
//! @return    なし
//--------------------------------------------------------------------
void SwitchScene(void)
{
	// シーンの変更があった場合
	if (g_nextSceneID != g_currentSceneID)
	{
		// 現在のシーンの終了処理
		FinalizeScene();
		// シーンIDを新しくする
		g_currentSceneID = g_nextSceneID;
		// 新しいシーンの初期化処理
		InitializeScene();
	}
}
