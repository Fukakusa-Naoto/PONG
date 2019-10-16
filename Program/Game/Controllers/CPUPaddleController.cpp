//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		CPUPaddleController.cpp
//!
//! @summary	CPUによるパドル制御に関するソースファイル
//!
//! @date		2019.10.16
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "CPUPaddleController.h"


// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   CPUパドルの制御処理
//!
//! @parameter [paddle] 制御するパドル
//! @parameter [ball] 参照するボール情報
//!
//! @return    なし
//--------------------------------------------------------------------
void ControlCPUPaddle(Paddle* paddle, Ball* ball)
{
	// ボールが自身より上だった場合
	if (paddle->gameObject.position.y >= ball->gameObject.position.y)
	{
		paddle->gameObject.velocity.y = -CPU_PADDLE_MOVE_SPEED;
	}
	// ボールが自身より下だった場合
	else if (paddle->gameObject.position.y <= ball->gameObject.position.y)
	{
		paddle->gameObject.velocity.y = CPU_PADDLE_MOVE_SPEED;
	}
}