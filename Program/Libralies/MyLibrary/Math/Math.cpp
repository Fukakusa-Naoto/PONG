//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Math.cpp
//!
//! @summary	数学に関するソースファイル
//!
//! @date		2019.10.18
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み =================================================
// <標準ヘッダファイル>
#include <math.h>
#include <float.h>

// <自作ヘッダファイル>
#include "Math.h"


// 関数の宣言 ==============================================================
//--------------------------------------------------------------------
//! @summary   float値の比較
//!
//! @parameter [valueA] 比較を行うfloat値A
//! @parameter [valueB] 比較を行うfloat値B
//!
//! @return    TRUE :等しい
//! @return    FALSE:等しくない
//--------------------------------------------------------------------
BOOL Approximately(float valueA, float valueB)
{
	// 差を計算する
	float difference = (float)fabs((float)(valueA - valueB));
	valueA = (float)fabs((float)valueA);
	valueB = (float)fabs((float)valueB);

	// 最大のものを見つける
	float largest = (valueB > valueA) ? valueB : valueA;

	if (difference <= largest * FLT_EPSILON) return TRUE;
	else return FALSE;
}

