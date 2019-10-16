//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		PlayScene.h
//!
//! @summary	プレイシーン関連のヘッダファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ===================================================
#pragma once



// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "../Objects/Paddle.h"
#include "../Objects/Ball.h"


// 列挙型の定義 ============================================================
enum Tag_SideID
{
	SIDE_LEFT,		// 左
	SIDE_RIGHT,		// 右
	SIDE_NONE,		// なし
};
typedef enum Tag_SideID SideID;


// 構造体の定義 ============================================================
struct Tag_PlaySceneObject
{
	// 左パドル
	Paddle leftPaddle;
	// 右パドル
	Paddle rightPaddle;
	// ボール
	Ball ball;
};
typedef struct Tag_PlaySceneObject PlaySceneObject;



// 関数の宣言 ==============================================================
//--------------------------------------------------------------------
//! @summary   プレイシーンの初期化処理
//!
//! @parameter [playSceneObject] プレイシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void InitializePlayScene(PlaySceneObject* playSceneObject);



//--------------------------------------------------------------------
//! @summary   プレイシーンの更新処理
//!
//! @parameter [playSceneObject] プレイシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void UpdatePlayScene(PlaySceneObject* playSceneObject);



//--------------------------------------------------------------------
//! @summary   プレイシーンの描画処理
//!
//! @parameter [playSceneObject] プレイシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void RenderPlayScene(PlaySceneObject* playSceneObject);



//--------------------------------------------------------------------
//! @summary   プレイシーンの終了処理
//!
//! @parameter [playSceneObject] プレイシーンで使用するオブジェクト
//!
//! @return    なし
//--------------------------------------------------------------------
void FinalizePlayScene(PlaySceneObject* playSceneObject);
