//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		LogoScene.cpp
//!
//! @summary	ロゴシーンシーン関連のソースファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "LogoScene.h"
#include "SceneManager.h"


// 定数の定義 ==============================================================
// シーン変更までの時間
#define CHANGE_SCENE_TIME (3.0f)


// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   ロゴシーンの初期化処理
//!
//! @parameter [logoSceneObject] ロゴシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializeLogoScene(LogoSceneObject* logoSceneObject)
{
	// カウントの初期化
	logoSceneObject->timeCount = 0.0f;
}



//--------------------------------------------------------------------
//! @summary   ロゴシーンの更新処理
//!
//! @parameter [logoSceneObject] ロゴシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void UpdateLogoScene(LogoSceneObject* logoSceneObject)
{
	// カウントの更新
	logoSceneObject->timeCount += GetFrameDeltaTime();

	// 3秒が経過する
	if (logoSceneObject->timeCount >= CHANGE_SCENE_TIME)
	{
		// タイトルシーンへ遷移する
		ChangeScene(SCENE_TITLE);
	}
}



//--------------------------------------------------------------------
//! @summary   ロゴシーンの描画処理
//!
//! @parameter [logoSceneObject] ロゴシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void RenderLogoScene(LogoSceneObject* logoSceneObject)
{
	DrawString(0, 0, "LOGO", COLOR_WHITE);
}



//--------------------------------------------------------------------
//! @summary   ロゴシーンの終了処理
//!
//! @parameter [logoSceneObject] ロゴシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void FinalizeLogoScene(LogoSceneObject* logoSceneObject)
{

}
