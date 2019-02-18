//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  �Q�[���֘A�̃\�[�X�t�@�C��
//!
//! @date   ���t
//!
//! @author ����Җ�
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"




// �O���[�o���ϐ��̒�` ====================================================

//�^�C�g��
int g_selectJudg;
bool g_titleFlag;
bool g_pushUpFlag;
bool g_pushDownFlag;


//�{�[���̍��W
float g_ballPosX;
float g_ballPosY;
//�{�[���̑��x
float g_ballVelX;
float g_ballVelY;

//�p�h���̍��W
//���p�h��
float g_paddleLeftPosX;
float g_paddleLeftPosY;
//�E�p�h��
float g_paddleRightPosX;
float g_paddleRightPosY;

//�L�[����
int g_inputState;

//�}�E�X����
int g_mousePosX;
int g_mousePosY;

//�{�[���̉�]
float g_gyration;

//�X�R�A
int g_scoreL;
int g_scoreR;

//�Q�[�W
int g_gaugeL;
int g_gaugeR;

//�T�[�u��
bool g_serveLeftFlag;
bool g_serveRightFlag;

//�T�[�u�`���[�W
bool g_chargeFlagL;
bool g_chargeFlagR;


//�T�E���h
int g_sound;
int g_bgm;
int g_volume;

//�I��
bool g_finishFlag;

//���Ԃ̃J�E���g
int g_countTimer;
int g_finishCountTimer;

//�֐��̐錾
void DrawPaddle(float x, float y);
void DetectCollisionLeft(float ballX, float ballY, float paddleX, float paddleY, float paddleVel);
void DetectCollisionRight(float ballX, float ballY, float paddleX, float paddleY, float paddleVel);

// �֐��̒�` ==============================================================
//----------------------------------------------------------------------
//! @brief �Q�[���̏���������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void InitializeGame(void)
{
	//�^�C�g��
	g_selectJudg = 0;
	g_titleFlag = TRUE;
	g_pushUpFlag = FALSE;
	g_pushDownFlag = FALSE;

	//�{�[���̍��W
	g_ballPosX = SCREEN_CENTER_X;
	g_ballPosY = SCREEN_CENTER_Y;
	//�{�[���̑��x
	g_ballVelX = 0.0f;
	g_ballVelY = 0.0f;

	//�p�h���̍��W
	//���p�h��
	g_paddleLeftPosX = 64.0f - PADDLE_WIDTH / 2.0f;
	g_paddleLeftPosY = SCREEN_CENTER_Y;
	//�E�p�h��
	g_paddleRightPosX = SCREEN_WIDTH - (64.0f + PADDLE_WIDTH / 2.0f);
	g_paddleRightPosY = SCREEN_CENTER_Y;

	//�}�E�X
	SetMouseDispFlag(FALSE);

	//�{�[���̉�]
	g_gyration = 0;

	//�X�R�A
	SetFontSize(40);
	g_scoreL = 0;
	g_scoreR = 0;

	//�Q�[�W
	g_gaugeL = 0;
	g_gaugeR = 0;

	//�T�[�u��
	g_serveLeftFlag = FALSE;
	g_serveRightFlag = FALSE;
	//�T�[�u�`���[�W
	g_chargeFlagL = FALSE;
	g_chargeFlagR = FALSE;

	//�T�E���h
	g_sound = LoadSoundMem("Resources/Sounds/se_maoudamashii_retro16.mp3");
	g_bgm = LoadSoundMem("Resources/Sounds/�j�R�j�R���h���[ ���V�O.mp3");
	g_volume = 200;

	//�I��
	g_finishFlag = FALSE;

	//���Ԃ̃J�E���g
	g_countTimer = 200;
	g_finishCountTimer = 200;

}



//----------------------------------------------------------------------
//! @brief �Q�[���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void UpdateGame(void)
{
	float paddleLeftSpeed;
	float paddleLeftVel;

	float paddleRightSpeed;
	float paddleRightVel;

	//�^�C�g����ʂ̏���
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

	//��l�v���C�̏���
	if (g_titleFlag == FALSE && g_selectJudg == 0)
	{
		//�{�[���̐���
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

		//�p�h���̑���
		//���p�h��
		paddleLeftSpeed = 10.0f;
		g_inputState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		paddleLeftVel = 0.0f;	//���p�h���̑��x�̏�����

		if ((g_inputState & PAD_INPUT_UP) != 0)		//��L�[�ŏ�ɐi��
		{
			paddleLeftVel = -paddleLeftSpeed;
		}
		if ((g_inputState & PAD_INPUT_DOWN) != 0)	//���L�[�ŉ��ɐi��
		{
			paddleLeftVel = paddleLeftSpeed;
		}
		g_paddleLeftPosY += paddleLeftVel;

		//�E�p�h��
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

		//�p�h���̉�ʐ���
		//���p�h��
		if (g_paddleLeftPosY < PADDLE_HEIGHT + 65)
		{
			g_paddleLeftPosY = PADDLE_HEIGHT + 65;
		}
		if (g_paddleLeftPosY > SCREEN_HEIGHT - PADDLE_HEIGHT)
		{
			g_paddleLeftPosY = SCREEN_HEIGHT - PADDLE_HEIGHT;
		}
		//�E�p�h��
		if (g_paddleRightPosY < PADDLE_HEIGHT + 65)
		{
			g_paddleRightPosY = PADDLE_HEIGHT + 65;
		}
		if (g_paddleRightPosY > SCREEN_HEIGHT - PADDLE_HEIGHT)
		{
			g_paddleRightPosY = SCREEN_HEIGHT - PADDLE_HEIGHT;
		}

		//�����蔻��
		//���p�h��
		if (g_ballVelX < 0)
		{
			DetectCollisionLeft(g_ballPosX, g_ballPosY, g_paddleLeftPosX, g_paddleLeftPosY, paddleLeftVel);

		}

		//�E�p�h��
		if (g_ballVelX > 0)
		{
			DetectCollisionRight(g_ballPosX, g_ballPosY, g_paddleRightPosX, g_paddleRightPosY, paddleRightVel);
		}
		g_ballVelY += g_gyration;

		//�X�R�A�̏���
		//���X�R�A
		if (g_ballPosX > SCREEN_WIDTH - 4)
		{
			g_scoreL++;
			g_ballVelX = 0.0f;
			g_ballVelY = 0.0f;
			g_gyration = 0.0f;
			g_serveRightFlag = TRUE;
		}
		//�E�X�R�A
		if (g_ballPosX < 4)
		{
			g_scoreR++;
			g_ballVelX = 0.0f;
			g_ballVelY = 0.0f;
			g_gyration = 0.0f;
			g_serveLeftFlag = TRUE;
		}

		//�T�[�u
		//���p�h��
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

		//�E�p�h��
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

		//�T�[�u�Q�[�W
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

		//�I������
		if (g_scoreL == 15 || g_scoreR == 15)
		{
			g_finishFlag = TRUE;
			g_volume--;
			ChangeVolumeSoundMem(g_volume, g_bgm);
		}

		//�^�C�g���ɖ߂�
		if (g_finishFlag == TRUE)
		{
			if (g_finishCountTimer == 0)
			{
				g_selectJudg = 2;
			}
			g_finishCountTimer--;
		}

	}

	//��l�v���C�̏���
	if (g_titleFlag == FALSE && g_selectJudg == 1)
	{
		int ballSpeedX;

		//������
		ballSpeedX = 5;

		//�{�[������ʒ[�ɓ����������̏���
		if (g_ballPosY > SCREEN_HEIGHT - 4 || g_ballPosY < 65)
		{
			g_ballVelY *= -1;
		}
		//�{�[���̈ړ�����
		if ((g_inputState & PAD_INPUT_M) != 0)
		{
			g_ballVelX = ballSpeedX;
		}

		g_ballPosX += g_ballVelX;
		g_ballPosY += g_ballVelY;

		//�p�h������̏���
		//���p�h��(�}�E�X����)
		paddleLeftVel = 0.0f;
		GetMousePoint(&g_mousePosX, &g_mousePosY);
		g_paddleLeftPosY = g_mousePosY;

		//�E�p�h��(�L�[����)
		//�p�h���̑���
		paddleRightSpeed = 10;
		g_inputState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		paddleRightVel = 0;	//�E�p�h���̑��x�̏�����

		if ((g_inputState & PAD_INPUT_UP) != 0)		//��L�[�ŏ�ɐi��
		{
			paddleRightVel = -paddleRightSpeed;
		}
		if ((g_inputState & PAD_INPUT_DOWN) != 0)	//���L�[�ŉ��ɐi��
		{
			paddleRightVel = paddleRightSpeed;
		}
		g_paddleRightPosY += paddleRightVel;

		//�p�h���̉�ʐ����̏���
		//���p�h��
		if (g_paddleLeftPosY < 65 + PADDLE_HEIGHT / 2)	//��ʏ�
		{
			g_paddleLeftPosY = 65 + PADDLE_HEIGHT / 2;
		}
		if (g_paddleLeftPosY > SCREEN_HEIGHT - (PADDLE_HEIGHT / 2 + 5))	//��ʉ�
		{
			g_paddleLeftPosY = SCREEN_HEIGHT - (PADDLE_HEIGHT / 2 + 5);
		}
		//�E�p�h��
		if (g_paddleRightPosY < 65 + PADDLE_HEIGHT / 2)	//��ʏ�
		{
			g_paddleRightPosY = 65 + PADDLE_HEIGHT / 2;
		}
		if (g_paddleRightPosY > SCREEN_HEIGHT - (PADDLE_HEIGHT / 2 + 5))	//��ʉ�
		{
			g_paddleRightPosY = SCREEN_HEIGHT - (PADDLE_HEIGHT / 2 + 5);
		}

		//�����蔻��̏���
		//���p�h��
		if (g_ballVelX < 0)
		{
			DetectCollisionLeft(g_ballPosX, g_ballPosY, g_paddleLeftPosX, g_paddleLeftPosY, paddleLeftVel);
		}

		//�E�p�h��
		if (g_ballVelX > 0)
		{
			DetectCollisionRight(g_ballPosX, g_ballPosY, g_paddleRightPosX, g_paddleRightPosY, paddleRightVel);
		}
		g_ballVelY += g_gyration;

		//�X�R�A�̏���
		//���X�R�A
		if (g_ballPosX > SCREEN_WIDTH - 4)
		{
			g_scoreL++;
			g_ballVelX = 0.0f;
			g_ballVelY = 0.0f;
			g_gyration = 0.0f;
			g_serveRightFlag = TRUE;
		}
		//�E�X�R�A
		if (g_ballPosX < 4)
		{
			g_scoreR++;
			g_ballVelX = 0.0f;
			g_ballVelY = 0.0f;
			g_gyration = 0.0f;
			g_serveLeftFlag = TRUE;
		}

		//�T�[�u
		//���p�h��
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


		//�E�p�h��
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

		//�T�[�u�Q�[�W
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

		//�I������
		if (g_scoreL == 15 || g_scoreR == 15)
		{
			g_finishFlag = TRUE;
			g_volume--;
			ChangeVolumeSoundMem(g_volume, g_bgm);
		}

		//�^�C�g���ɖ߂�
		if (g_finishFlag == TRUE)
		{
			if (g_finishCountTimer == 0)
			{
				g_selectJudg = 2;
			}
			g_finishCountTimer--;
		}

	}

	//�I���̏���
	if (g_titleFlag == FALSE && g_selectJudg == 2)
	{
		//g_inputState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

		////(g_inputState & PAD_INPUT_START) = 1;
		//CheckHitKey(EXIT_KEY) != 1;
		exit(true);

	}

}



//----------------------------------------------------------------------
//! @brief �Q�[���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void RenderGame(void)
{
	//�^�C�g����ʂ̕`��
	if (g_titleFlag == TRUE)
	{
		//����
		SetFontSize(30);
		if (g_selectJudg == 0)
		{
			DrawFormatString(240, 280, COLOR_RED, "��l�ŗV��");
			DrawFormatString(240, 320, COLOR_WHITE, "��l�ŗV��");
			DrawFormatString(270, 360, COLOR_WHITE, "�I���");
		}
		if (g_selectJudg == 1)
		{
			DrawFormatString(240, 280, COLOR_WHITE, "��l�ŗV��");
			DrawFormatString(240, 320, COLOR_RED, "��l�ŗV��");
			DrawFormatString(270, 360, COLOR_WHITE, "�I���");
		}
		if (g_selectJudg == 2)
		{
			DrawFormatString(240, 280, COLOR_WHITE, "��l�ŗV��");
			DrawFormatString(240, 320, COLOR_WHITE, "��l�ŗV��");
			DrawFormatString(270, 360, COLOR_RED, "�I���");
		}

	}

	//�v���C��ʂ̕`��
	if (g_titleFlag == FALSE && (g_selectJudg == 0 || g_selectJudg == 1))
	{
		//�Z���^�[���C��
		DrawDashedLine(320, 0, 320, 480, COLOR_WHITE, 10, 5);

		DrawLine(0, 60, SCREEN_WIDTH, 60, COLOR_WHITE, 5);
		DrawLine(0, SCREEN_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_WHITE, 10);

		//�{�[��
		DrawCircleAA(g_ballPosX, g_ballPosY, 4.0f, 32, COLOR_WHITE, TRUE);

		//�p�h��
		//���p�h��
		DrawPaddle(g_paddleLeftPosX, g_paddleLeftPosY);
		//�E�p�h��
		DrawPaddle(g_paddleRightPosX, g_paddleRightPosY);

		//�X�R�A
		DrawFormatString(270, 10, COLOR_YELLOW, "%d", g_scoreL);		//���X�R�A
		DrawFormatString(350, 10, COLOR_YELLOW, "%d", g_scoreR);		//�E�X�R�A

																		//�T�[�u�Q�[�W
																		//���Q�[�W
		DrawBox(10, 10, 10 + g_gaugeL, 50, COLOR_GREEN, TRUE);
		DrawBox(10, 10, 200, 50, COLOR_WHITE, FALSE);

		//�E�Q�[�W
		DrawBox(SCREEN_WIDTH - 10 - g_gaugeR, 10, SCREEN_WIDTH - 10, 50, COLOR_GREEN, TRUE);
		DrawBox(SCREEN_WIDTH - 200, 10, SCREEN_WIDTH - 10, 50, COLOR_WHITE, FALSE);

		//����
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

	//�I����ʂ̕`��
	if (g_titleFlag == FALSE && g_selectJudg == 2)
	{
		DrawFormatString(140, 240, COLOR_WHITE, "ESC�L�[�������Ă�������");
	}


}



//----------------------------------------------------------------------
//! @brief �Q�[���̏I������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void FinalizeGame(void)
{

}

//�֐��̏���
//�p�h���̕`��
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

//�����蔻��
//��
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

//�E
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

