//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  ゲーム関連のソースファイル
//!
//! @date   日付
//!
//! @author 制作者名
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"




// グローバル変数の定義 ====================================================

//タイトル
int g_selectJudg;
bool g_titleFlag;
bool g_pushUpFlag;
bool g_pushDownFlag;


//ボールの座標
float g_ballPosX;
float g_ballPosY;
//ボールの速度
float g_ballVelX;
float g_ballVelY;

//パドルの座標
//左パドル
float g_paddleLeftPosX;
float g_paddleLeftPosY;
//右パドル
float g_paddleRightPosX;
float g_paddleRightPosY;

//キー入力
int g_inputState;

//マウス入力
int g_mousePosX;
int g_mousePosY;

//ボールの回転
float g_gyration;

//スコア
int g_scoreL;
int g_scoreR;

//ゲージ
int g_gaugeL;
int g_gaugeR;

//サーブ権
bool g_serveLeftFlag;
bool g_serveRightFlag;

//サーブチャージ
bool g_chargeFlagL;
bool g_chargeFlagR;


//サウンド
int g_sound;
int g_bgm;
int g_volume;

//終了
bool g_finishFlag;

//時間のカウント
int g_countTimer;
int g_finishCountTimer;

//関数の宣言
void DrawPaddle(float x, float y);
void DetectCollisionLeft(float ballX, float ballY, float paddleX, float paddleY, float paddleVel);
void DetectCollisionRight(float ballX, float ballY, float paddleX, float paddleY, float paddleVel);

// 関数の定義 ==============================================================
//----------------------------------------------------------------------
//! @brief ゲームの初期化処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void InitializeGame(void)
{
	//タイトル
	g_selectJudg = 0;
	g_titleFlag = TRUE;
	g_pushUpFlag = FALSE;
	g_pushDownFlag = FALSE;

	//ボールの座標
	g_ballPosX = SCREEN_CENTER_X;
	g_ballPosY = SCREEN_CENTER_Y;
	//ボールの速度
	g_ballVelX = 0.0f;
	g_ballVelY = 0.0f;

	//パドルの座標
	//左パドル
	g_paddleLeftPosX = 64.0f - PADDLE_WIDTH / 2.0f;
	g_paddleLeftPosY = SCREEN_CENTER_Y;
	//右パドル
	g_paddleRightPosX = SCREEN_WIDTH - (64.0f + PADDLE_WIDTH / 2.0f);
	g_paddleRightPosY = SCREEN_CENTER_Y;

	//マウス
	SetMouseDispFlag(FALSE);

	//ボールの回転
	g_gyration = 0;

	//スコア
	SetFontSize(40);
	g_scoreL = 0;
	g_scoreR = 0;

	//ゲージ
	g_gaugeL = 0;
	g_gaugeR = 0;

	//サーブ権
	g_serveLeftFlag = FALSE;
	g_serveRightFlag = FALSE;
	//サーブチャージ
	g_chargeFlagL = FALSE;
	g_chargeFlagR = FALSE;

	//サウンド
	g_sound = LoadSoundMem("Resources/Sounds/se_maoudamashii_retro16.mp3");
	g_bgm = LoadSoundMem("Resources/Sounds/ニコニコメドレー 摩天楼.mp3");
	g_volume = 200;

	//終了
	g_finishFlag = FALSE;

	//時間のカウント
	g_countTimer = 200;
	g_finishCountTimer = 200;

}



//----------------------------------------------------------------------
//! @brief ゲームの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void UpdateGame(void)
{
	float paddleLeftSpeed;
	float paddleLeftVel;

	float paddleRightSpeed;
	float paddleRightVel;

	//タイトル画面の処理
	if (g_titleFlag == TRUE)
	{
		g_inputState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if ((g_inputState & PAD_INPUT_UP) != 0 && g_pushUpFlag == FALSE)
		{
			g_selectJudg--;
			g_pushUpFlag = TRUE;
		}
		else if ((g_inputState & PAD_INPUT_UP) == 0 && g_pushUpFlag == TRUE)
		{
			g_pushUpFlag = FALSE;
		}
		if ((g_inputState & PAD_INPUT_DOWN) != 0 && g_pushDownFlag == FALSE)
		{
			g_selectJudg++;
			g_pushDownFlag = TRUE;
		}
		else if ((g_inputState & PAD_INPUT_DOWN) == 0 && g_pushDownFlag == TRUE)
		{
			g_pushDownFlag = FALSE;
		}

		if (g_selectJudg > 2)
		{
			g_selectJudg = 0;
		}
		if (g_selectJudg < 0)
		{
			g_selectJudg = 2;
		}

		if ((g_inputState & PAD_INPUT_M) != 0)
		{
			g_titleFlag = FALSE;
			g_ballPosX = SCREEN_CENTER_X;
			g_ballPosY = SCREEN_CENTER_Y;
			g_ballVelY = 0.0f;
			g_finishCountTimer = 200;
			g_finishFlag = FALSE;
			g_scoreL = 0;
			g_scoreR = 0;
			g_volume = 200;
			PlaySoundMem(g_bgm, DX_PLAYTYPE_LOOP, TRUE);
		}

	}

	//一人プレイの処理
	if (g_titleFlag == FALSE && g_selectJudg == 0)
	{
		//ボールの制御
		if ((g_inputState & PAD_INPUT_M) != 0 && g_titleFlag == FALSE)
		{
			g_ballVelX = 5.0f;
		}

		if (g_ballPosY < 65 || g_ballPosY > SCREEN_HEIGHT - 4)
		{
			g_ballVelY *= -1;
		}
		g_ballPosX += g_ballVelX;
		g_ballPosY += g_ballVelY;

		//パドルの操作
		//左パドル
		paddleLeftSpeed = 10.0f;
		g_inputState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		paddleLeftVel = 0.0f;	//左パドルの速度の初期化

		if ((g_inputState & PAD_INPUT_UP) != 0)		//上キーで上に進む
		{
			paddleLeftVel = -paddleLeftSpeed;
		}
		if ((g_inputState & PAD_INPUT_DOWN) != 0)	//下キーで下に進む
		{
			paddleLeftVel = paddleLeftSpeed;
		}
		g_paddleLeftPosY += paddleLeftVel;

		//右パドル
		paddleRightSpeed = 4.0f;
		paddleRightVel = 0.0f;

		if (g_ballPosX > 0 && g_ballPosX < SCREEN_WIDTH)
		{
			if (g_ballPosY > g_paddleRightPosY)
			{
				paddleRightVel = paddleRightSpeed;
			}
			if (g_ballPosY < g_paddleRightPosY)
			{
				paddleRightVel = -paddleRightSpeed;
			}
		}
		g_paddleRightPosY += paddleRightVel;

		//パドルの画面制限
		//左パドル
		if (g_paddleLeftPosY < PADDLE_HEIGHT + 65)
		{
			g_paddleLeftPosY = PADDLE_HEIGHT + 65;
		}
		if (g_paddleLeftPosY > SCREEN_HEIGHT - PADDLE_HEIGHT)
		{
			g_paddleLeftPosY = SCREEN_HEIGHT - PADDLE_HEIGHT;
		}
		//右パドル
		if (g_paddleRightPosY < PADDLE_HEIGHT + 65)
		{
			g_paddleRightPosY = PADDLE_HEIGHT + 65;
		}
		if (g_paddleRightPosY > SCREEN_HEIGHT - PADDLE_HEIGHT)
		{
			g_paddleRightPosY = SCREEN_HEIGHT - PADDLE_HEIGHT;
		}

		//当たり判定
		//左パドル
		if (g_ballVelX < 0)
		{
			DetectCollisionLeft(g_ballPosX, g_ballPosY, g_paddleLeftPosX, g_paddleLeftPosY, paddleLeftVel);

		}

		//右パドル
		if (g_ballVelX > 0)
		{
			DetectCollisionRight(g_ballPosX, g_ballPosY, g_paddleRightPosX, g_paddleRightPosY, paddleRightVel);
		}
		g_ballVelY += g_gyration;

		//スコアの処理
		//左スコア
		if (g_ballPosX > SCREEN_WIDTH - 4)
		{
			g_scoreL++;
			g_ballVelX = 0.0f;
			g_ballVelY = 0.0f;
			g_gyration = 0.0f;
			g_serveRightFlag = TRUE;
		}
		//右スコア
		if (g_ballPosX < 4)
		{
			g_scoreR++;
			g_ballVelX = 0.0f;
			g_ballVelY = 0.0f;
			g_gyration = 0.0f;
			g_serveLeftFlag = TRUE;
		}

		//サーブ
		//左パドル
		if (g_serveLeftFlag == TRUE)
		{
			g_ballPosX = g_paddleLeftPosX + (PADDLE_WIDTH / 2 + 5);
			g_ballPosY = g_paddleLeftPosY;
			if ((g_inputState & PAD_INPUT_M) != 0)
			{
				g_gaugeL += 5;
				g_chargeFlagL = TRUE;
			}
		}
		if (g_chargeFlagL == TRUE && (g_inputState & PAD_INPUT_M) == 0)
		{
			g_ballVelX = g_gaugeL / 20;
			if (g_ballVelX < 5)
			{
				g_ballVelX = 4.0f;
			}
			g_chargeFlagL = FALSE;
			g_serveLeftFlag = FALSE;
		}
		if (g_gaugeL > 200)
		{
			g_gaugeL = 0;
		}

		//右パドル
		if (g_serveRightFlag == TRUE)
		{
			g_ballPosX = g_paddleRightPosX - (PADDLE_WIDTH / 2 + 5);
			g_ballPosY = g_paddleRightPosY;
			g_gaugeR += 5;
			g_chargeFlagR = TRUE;
			g_countTimer--;
		}
		if (g_chargeFlagR == TRUE && g_countTimer <= 0)
		{
			g_ballVelX = -g_gaugeR / 20;
			if (g_ballVelX > -5)
			{
				g_ballVelX = -4.0f;
			}
			g_chargeFlagR = FALSE;
			g_serveRightFlag = FALSE;
			g_countTimer = GetRand(200);
		}
		if (g_gaugeR > 200)
		{
			g_gaugeR = 0;
		}

		//サーブゲージ
		g_gaugeL--;
		g_gaugeR--;
		if (g_gaugeL < 0)
		{
			g_gaugeL = 0;
		}
		if (g_gaugeR < 0)
		{
			g_gaugeR = 0;
		}

		//終了処理
		if (g_scoreL == 15 || g_scoreR == 15)
		{
			g_finishFlag = TRUE;
			g_volume--;
			ChangeVolumeSoundMem(g_volume, g_bgm);
		}

		//タイトルに戻る
		if (g_finishFlag == TRUE)
		{
			if (g_finishCountTimer == 0)
			{
				g_selectJudg = 2;
			}
			g_finishCountTimer--;
		}

	}

	//二人プレイの処理
	if (g_titleFlag == FALSE && g_selectJudg == 1)
	{
		int ballSpeedX;

		//初期化
		ballSpeedX = 5;

		//ボールが画面端に当たった時の処理
		if (g_ballPosY > SCREEN_HEIGHT - 4 || g_ballPosY < 65)
		{
			g_ballVelY *= -1;
		}
		//ボールの移動処理
		if ((g_inputState & PAD_INPUT_M) != 0)
		{
			g_ballVelX = ballSpeedX;
		}

		g_ballPosX += g_ballVelX;
		g_ballPosY += g_ballVelY;

		//パドル操作の処理
		//左パドル(マウス操作)
		paddleLeftVel = 0.0f;
		GetMousePoint(&g_mousePosX, &g_mousePosY);
		g_paddleLeftPosY = g_mousePosY;

		//右パドル(キー操作)
		//パドルの速さ
		paddleRightSpeed = 10;
		g_inputState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		paddleRightVel = 0;	//右パドルの速度の初期化

		if ((g_inputState & PAD_INPUT_UP) != 0)		//上キーで上に進む
		{
			paddleRightVel = -paddleRightSpeed;
		}
		if ((g_inputState & PAD_INPUT_DOWN) != 0)	//下キーで下に進む
		{
			paddleRightVel = paddleRightSpeed;
		}
		g_paddleRightPosY += paddleRightVel;

		//パドルの画面制限の処理
		//左パドル
		if (g_paddleLeftPosY < 65 + PADDLE_HEIGHT / 2)	//画面上
		{
			g_paddleLeftPosY = 65 + PADDLE_HEIGHT / 2;
		}
		if (g_paddleLeftPosY > SCREEN_HEIGHT - (PADDLE_HEIGHT / 2 + 5))	//画面下
		{
			g_paddleLeftPosY = SCREEN_HEIGHT - (PADDLE_HEIGHT / 2 + 5);
		}
		//右パドル
		if (g_paddleRightPosY < 65 + PADDLE_HEIGHT / 2)	//画面上
		{
			g_paddleRightPosY = 65 + PADDLE_HEIGHT / 2;
		}
		if (g_paddleRightPosY > SCREEN_HEIGHT - (PADDLE_HEIGHT / 2 + 5))	//画面下
		{
			g_paddleRightPosY = SCREEN_HEIGHT - (PADDLE_HEIGHT / 2 + 5);
		}

		//当たり判定の処理
		//左パドル
		if (g_ballVelX < 0)
		{
			DetectCollisionLeft(g_ballPosX, g_ballPosY, g_paddleLeftPosX, g_paddleLeftPosY, paddleLeftVel);
		}

		//右パドル
		if (g_ballVelX > 0)
		{
			DetectCollisionRight(g_ballPosX, g_ballPosY, g_paddleRightPosX, g_paddleRightPosY, paddleRightVel);
		}
		g_ballVelY += g_gyration;

		//スコアの処理
		//左スコア
		if (g_ballPosX > SCREEN_WIDTH - 4)
		{
			g_scoreL++;
			g_ballVelX = 0.0f;
			g_ballVelY = 0.0f;
			g_gyration = 0.0f;
			g_serveRightFlag = TRUE;
		}
		//右スコア
		if (g_ballPosX < 4)
		{
			g_scoreR++;
			g_ballVelX = 0.0f;
			g_ballVelY = 0.0f;
			g_gyration = 0.0f;
			g_serveLeftFlag = TRUE;
		}

		//サーブ
		//左パドル
		if (g_serveLeftFlag == TRUE)
		{
			g_ballPosX = g_paddleLeftPosX + (PADDLE_WIDTH / 2 + 4);
			g_ballPosY = g_paddleLeftPosY;
			if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
			{
				g_gaugeL += 5;
				g_chargeFlagL = TRUE;
			}
		}
		if (g_chargeFlagL == TRUE && (GetMouseInput() & MOUSE_INPUT_LEFT) == 0)
		{
			g_ballVelX = g_gaugeL / 20;
			if (g_ballVelX < 5)
			{
				g_ballVelX = 4;
			}
			g_chargeFlagL = FALSE;
			g_serveLeftFlag = FALSE;
		}
		if (g_gaugeL > 200)
		{
			g_gaugeL = 0;
		}


		//右パドル
		if (g_serveRightFlag == TRUE)
		{
			g_ballPosX = g_paddleRightPosX - (PADDLE_WIDTH / 2 + 4);
			g_ballPosY = g_paddleRightPosY;
			if ((g_inputState & PAD_INPUT_M) != 0)
			{
				g_gaugeR += 5;
				g_chargeFlagR = TRUE;
			}
		}
		if (g_chargeFlagR == TRUE && (g_inputState & PAD_INPUT_M) == 0)
		{
			g_ballVelX = -g_gaugeR / 20;
			if (g_ballVelX > -5)
			{
				g_ballVelX = -4;
			}

			g_chargeFlagR = FALSE;
			g_serveRightFlag = FALSE;
		}
		if (g_gaugeR > 200)
		{
			g_gaugeR = 0;
		}

		//サーブゲージ
		g_gaugeL--;
		g_gaugeR--;
		if (g_gaugeL < 0)
		{
			g_gaugeL = 0;
		}
		if (g_gaugeR < 0)
		{
			g_gaugeR = 0;
		}

		//終了処理
		if (g_scoreL == 15 || g_scoreR == 15)
		{
			g_finishFlag = TRUE;
			g_volume--;
			ChangeVolumeSoundMem(g_volume, g_bgm);
		}

		//タイトルに戻る
		if (g_finishFlag == TRUE)
		{
			if (g_finishCountTimer == 0)
			{
				g_selectJudg = 2;
			}
			g_finishCountTimer--;
		}

	}

	//終わりの処理
	if (g_titleFlag == FALSE && g_selectJudg == 2)
	{
		//g_inputState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		////(g_inputState & PAD_INPUT_START) = 1;
		//CheckHitKey(EXIT_KEY) != 1;
		exit(true);

	}

}



//----------------------------------------------------------------------
//! @brief ゲームの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void RenderGame(void)
{
	//タイトル画面の描画
	if (g_titleFlag == TRUE)
	{
		//文字
		SetFontSize(30);
		if (g_selectJudg == 0)
		{
			DrawFormatString(240, 280, COLOR_RED, "一人で遊ぶ");
			DrawFormatString(240, 320, COLOR_WHITE, "二人で遊ぶ");
			DrawFormatString(270, 360, COLOR_WHITE, "終わる");
		}
		if (g_selectJudg == 1)
		{
			DrawFormatString(240, 280, COLOR_WHITE, "一人で遊ぶ");
			DrawFormatString(240, 320, COLOR_RED, "二人で遊ぶ");
			DrawFormatString(270, 360, COLOR_WHITE, "終わる");
		}
		if (g_selectJudg == 2)
		{
			DrawFormatString(240, 280, COLOR_WHITE, "一人で遊ぶ");
			DrawFormatString(240, 320, COLOR_WHITE, "二人で遊ぶ");
			DrawFormatString(270, 360, COLOR_RED, "終わる");
		}

	}

	//プレイ画面の描画
	if (g_titleFlag == FALSE && (g_selectJudg == 0 || g_selectJudg == 1))
	{
		//センターライン
		DrawDashedLine(320, 0, 320, 480, COLOR_WHITE, 10, 5);

		DrawLine(0, 60, SCREEN_WIDTH, 60, COLOR_WHITE, 5);
		DrawLine(0, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_WHITE, 10);

		//ボール
		DrawCircleAA(g_ballPosX, g_ballPosY, 4.0f, 32, COLOR_WHITE, TRUE);

		//パドル
		//左パドル
		DrawPaddle(g_paddleLeftPosX, g_paddleLeftPosY);
		//右パドル
		DrawPaddle(g_paddleRightPosX, g_paddleRightPosY);

		//スコア
		DrawFormatString(270, 10, COLOR_YELLOW, "%d", g_scoreL);		//左スコア
		DrawFormatString(350, 10, COLOR_YELLOW, "%d", g_scoreR);		//右スコア

																		//サーブゲージ
																		//左ゲージ
		DrawBox(10, 10, 10 + g_gaugeL, 50, COLOR_GREEN, TRUE);
		DrawBox(10, 10, 200, 50, COLOR_WHITE, FALSE);

		//右ゲージ
		DrawBox(SCREEN_WIDTH - 10 - g_gaugeR, 10, SCREEN_WIDTH - 10, 50, COLOR_GREEN, TRUE);
		DrawBox(SCREEN_WIDTH - 200, 10, SCREEN_WIDTH - 10, 50, COLOR_WHITE, FALSE);

		//結果
		if (g_scoreL == 15)
		{
			DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BLACK, TRUE);
			DrawString(100, 230, "WIN", COLOR_WHITE);
			DrawString(540, 230, "LOST", COLOR_WHITE);
		}
		if (g_scoreR == 15)
		{
			DrawBox(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BLACK, TRUE);
			DrawString(540, 230, "WIN", COLOR_WHITE);
			DrawString(100, 230, "LOST", COLOR_WHITE);
		}
	}

	//終了画面の描画
	if (g_titleFlag == FALSE && g_selectJudg == 2)
	{
		DrawFormatString(140, 240, COLOR_WHITE, "ESCキーを押してください");
	}


}



//----------------------------------------------------------------------
//! @brief ゲームの終了処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void FinalizeGame(void)
{

}

//関数の処理
//パドルの描画
void DrawPaddle(float x, float y)
{
	float x1, y1;
	float x2, y2;

	x1 = x - PADDLE_WIDTH / 2;
	y1 = y - PADDLE_HEIGHT / 2;
	x2 = x + PADDLE_WIDTH / 2;
	y2 = y + PADDLE_HEIGHT / 2;

	DrawBoxAA(x1, y1, x2, y2, COLOR_RED, TRUE);
}

//当たり判定
//左
void DetectCollisionLeft(float ballX, float ballY, float paddleX, float paddleY, float paddleVel)
{
	float ballL, ballR;
	float ballT, ballB;

	float paddleL, paddleR;
	float paddleT, paddleB;

	float length;

	ballL = ballX - 4;
	ballR = ballX + 4;
	ballT = ballY - 4;
	ballB = ballY + 4;

	paddleL = paddleX - PADDLE_WIDTH / 2;
	paddleR = paddleX + PADDLE_WIDTH / 2;
	paddleT = paddleY - PADDLE_HEIGHT / 2;
	paddleB = paddleY + PADDLE_HEIGHT / 2;

	length = (ballY - paddleY) / 4.0f;

	if ((ballL < paddleR) && (ballR > paddleL) && (ballB > paddleT) && (ballT < paddleB))
	{
		g_ballVelX = 5.0f;
		g_ballVelY = length;
		g_gyration = 0;
		if (paddleVel < 0)
		{
			g_gyration = 0.02f;
		}
		if (paddleVel > 0)
		{
			g_gyration = -0.02f;
		}

		if (g_serveLeftFlag == FALSE)
		{
			PlaySoundMem(g_sound, DX_PLAYTYPE_BACK);
		}

	}
}

//右
void DetectCollisionRight(float ballX, float ballY, float paddleX, float paddleY, float paddleVel)
{
	float ballL, ballR;
	float ballT, ballB;

	float paddleL, paddleR;
	float paddleT, paddleB;

	float length;

	ballL = ballX - 4;
	ballR = ballX + 4;
	ballT = ballY - 4;
	ballB = ballY + 4;

	paddleL = paddleX - PADDLE_WIDTH / 2;
	paddleR = paddleX + PADDLE_WIDTH / 2;
	paddleT = paddleY - PADDLE_HEIGHT / 2;
	paddleB = paddleY + PADDLE_HEIGHT / 2;

	length = (ballY - paddleY) / 4.0f;

	if ((ballL < paddleR) && (ballR > paddleL) && (ballB > paddleT) && (ballT < paddleB))
	{
		g_ballVelX = -5.0f;
		g_ballVelY = length;
		g_gyration = 0;
		if (paddleVel < 0)
		{
			g_gyration = 0.02f;
		}
		if (paddleVel > 0)
		{
			g_gyration = -0.02f;
		}

		if (g_serveRightFlag == FALSE)
		{
			PlaySoundMem(g_sound, DX_PLAYTYPE_BACK);
		}

	}
}

