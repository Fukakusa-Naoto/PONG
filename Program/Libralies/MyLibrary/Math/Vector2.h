//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Vector2.h
//!
//! @summary	Vector2に関するヘッダファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ===================================================
#pragma once


// 構造体の定義 ============================================================
struct Tag_Vector2
{
	float x;
	float y;
};
typedef struct Tag_Vector2 Vector2;

struct Tag_Vector2Int
{
	int x;
	int y;
};
typedef struct Tag_Vector2Int Vector2Int;


// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   Vector2を作成する
//!
//! @parameter [x] xの値
//! @parameter [y] yの値
//!
//! @return    x,yを元に作られたVector2
//--------------------------------------------------------------------
static Vector2 CreateVector2(float x, float y)
{
	Vector2 v = { x, y };
	return v;
}



static Vector2Int CreateVector2Int(int x, int y)
{
	Vector2Int v = { x, y };
	return v;
}



//--------------------------------------------------------------------
//! @summary   Vector2のx,yの値が0のVector2を返す
//!
//! @parameter [void] なし
//!
//! @return    x,yが0のVector2
//--------------------------------------------------------------------
static Vector2 GetVector2Zero()
{
	Vector2 zero;
	ZeroMemory(&zero, sizeof(Vector2));
	return zero;
}



static Vector2Int GetVector2IntZero()
{
	Vector2Int zero;
	ZeroMemory(&zero, sizeof(Vector2Int));
	return zero;
}



//--------------------------------------------------------------------
//! @summary   Vector2のx,yの値が1のVector2を返す
//!
//! @parameter [void] なし
//!
//! @return    x,yが1のVector2
//--------------------------------------------------------------------
static Vector2 GetVector2One()
{
	Vector2 zero = CreateVector2(1.0f, 1.0f);
	return zero;
}



static Vector2Int GetVector2IntOne()
{
	Vector2Int zero = CreateVector2Int(1, 1);
	return zero;
}



//--------------------------------------------------------------------
//! @summary   Vector2の足し算
//!
//! @parameter [v1] 足し算を行うVector2の値1
//! @parameter [v2] 足し算を行うVector2の値2
//!
//! @return    v1とv2を足した後のVector2
//--------------------------------------------------------------------
static Vector2 AddVector2(const Vector2* v1, const Vector2* v2)
{
	Vector2 answer;
	answer.x = v1->x + v2->x;
	answer.y = v1->y + v2->y;
	return answer;
}



static Vector2Int AddVector2Int(const Vector2Int* v1, const Vector2Int* v2)
{
	Vector2Int answer;
	answer.x = v1->x + v2->x;
	answer.y = v1->y + v2->y;
	return answer;
}



//--------------------------------------------------------------------
//! @summary   Vector2の引き算
//!
//! @parameter [v1] 引き算を行うVector2の値1
//! @parameter [v2] 引き算を行うVector2の値2
//!
//! @return    v1からv2を引いた後のVector2
//--------------------------------------------------------------------
static Vector2 SubVector2(const Vector2* v1, const Vector2* v2)
{
	Vector2 answer;
	answer.x = v1->x - v2->x;
	answer.y = v1->y - v2->y;
	return answer;
}



static Vector2Int SubVector2(const Vector2Int* v1, const Vector2Int* v2)
{
	Vector2Int answer;
	answer.x = v1->x - v2->x;
	answer.y = v1->y - v2->y;
	return answer;
}



//--------------------------------------------------------------------
//! @summary   Vector2のスケール計算
//!
//! @parameter [vector2] 元のVector2
//! @parameter [scale] 比率
//!
//! @return    vector2のx,yにscaleのx,yを掛けた値
//--------------------------------------------------------------------
static Vector2 SceleVector2(const Vector2* vector2, const Vector2* scale)
{
	Vector2 answer;
	answer.x = vector2->x * scale->x;
	answer.y = vector2->y * scale->y;
	return answer;
}