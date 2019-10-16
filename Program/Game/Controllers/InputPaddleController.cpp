//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		InputPaddleController.cpp
//!
//! @summary	入力によるパドル制御に関するソースファイル
//!
//! @date		2019.10.16
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "InputPaddleController.h"


// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   右パドルの入力制御処理
//!
//! @parameter [paddle] 制御するパドル
//!
//! @return    なし
//--------------------------------------------------------------------
void ControlRightPaddle(Paddle* paddle)
{
	// 上キーが入力された
	if (IsButtonDown(PAD_INPUT_UP))
	{
		paddle->gameObject.velocity.y = -RIGHT_PADDLE_MOVE_SPEED;
	}
	// 下キーが入力された
	else if (IsButtonDown(PAD_INPUT_DOWN))
	{
		paddle->gameObject.velocity.y = RIGHT_PADDLE_MOVE_SPEED;
	}
	// 何も入力されていない
	else
	{
		paddle->gameObject.velocity.y = 0.0f;
	}
}