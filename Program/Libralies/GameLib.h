//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLib.h
//!
//! @brief  ゲーム制作用ライブラリのヘッダファイル
//!
//! @date   2017/3/27
//!
//! @author S.Takaki
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once



// ヘッダファイルの読み込み ================================================
#include <DxLib.h>

#include "DxLibHelper/GameLibGraphics.h"
#include "DxLibHelper/GameLibInput.h"
#include "DxLibHelper/GameLibMath.h"
#include "DxLibHelper/GameLibSystem.h"
#include "DxLibHelper/GameLibTime.h"

#include "Utilities/MemoryLeakDetector.h"

// 型の定義 ================================================================
// <ハンドル> ----------------------------------------------------------
typedef int HGRP;    // グラフィックハンドル
typedef int HSND;    // サウンドハンドル
typedef int HFNT;    // フォントハンドル
typedef int HNET;    // ネットワークハンドル
