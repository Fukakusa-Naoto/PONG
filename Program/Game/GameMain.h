//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		GameMain.h
//!
//! @summary	ゲーム関連のヘッダファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ===================================================
#pragma once


// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "Scenes/PlayScene.h"
#include "Scenes/LogoScene.h"
#include "Scenes/TitleScene.h"


// 定数の定義 ==============================================================
// ゲームタイトル
#define GAME_TITLE     "PONG"

// ゲーム画面
#define SCREEN_WIDTH   640    // 幅[pixel]
#define SCREEN_HEIGHT  480    // 高さ[pixel]

#define SCREEN_CENTER_X (SCREEN_WIDTH  / 2)    // 画面の中央(X座標)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT / 2)    // 画面の中央(Y座標)

// 構造体の定義 ============================================================
struct Tag_GameMainObject
{
	// プレイシーンで使用するオブジェクト
	PlaySceneObject playSceneObject;
	// タイトルシーンで使用するオブジェクト
	TitleSceneObject titleSceneObject;
};
typedef struct Tag_GameMainObject GameMainObject;


// 関数の宣言 ==============================================================
//--------------------------------------------------------------------
//! @summary   ゲームの初期化処理
//!
//! @parameter [gameMainObject] ゲーム上で使用する全てのオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializeGame(GameMainObject* gameMainObject);



//--------------------------------------------------------------------
//! @summary   ゲームの更新処理
//!
//! @parameter [gameMainObject] ゲーム上で使用する全てのオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void UpdateGame(GameMainObject* gameMainObject);



//--------------------------------------------------------------------
//! @summary   ゲームの描画処理
//!
//! @parameter [gameMainObject] ゲーム上で使用する全てのオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void RenderGame(GameMainObject* gameMainObject);



//--------------------------------------------------------------------
//! @summary   ゲームの終了処理
//!
//! @parameter [gameMainObject] ゲーム上で使用する全てのオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void FinalizeGame(GameMainObject* gameMainObject);
