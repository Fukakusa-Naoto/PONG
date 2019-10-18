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


// 関数の宣言 ==============================================================
//--------------------------------------------------------------------
//! @summary   Vector2を作成する
//!
//! @parameter [x] xの値
//! @parameter [y] yの値
//!
//! @return    x,yを元に作られたVector2
//--------------------------------------------------------------------
Vector2 CreateVector2(float x, float y);
Vector2Int CreateVector2Int(int x, int y);



//--------------------------------------------------------------------
//! @summary   Vector2のx,yの値が0のVector2を返す
//!
//! @parameter [void] なし
//!
//! @return    x,yが0のVector2
//--------------------------------------------------------------------
Vector2 GetVector2Zero();
Vector2Int GetVector2IntZero();



//--------------------------------------------------------------------
//! @summary   Vector2のx,yの値が1のVector2を返す
//!
//! @parameter [void] なし
//!
//! @return    x,yが1のVector2
//--------------------------------------------------------------------
Vector2 GetVector2One();
Vector2Int GetVector2IntOne();



//--------------------------------------------------------------------
//! @summary   Vector2の足し算
//!
//! @parameter [v1] 足し算を行うVector2の値1
//! @parameter [v2] 足し算を行うVector2の値2
//!
//! @return    v1とv2を足した後のVector2
//--------------------------------------------------------------------
Vector2 AddVector2(Vector2* v1, Vector2* v2);
Vector2Int AddVector2Int(Vector2Int* v1, Vector2Int* v2);



//--------------------------------------------------------------------
//! @summary   Vector2の引き算
//!
//! @parameter [v1] 引き算を行うVector2の値1
//! @parameter [v2] 引き算を行うVector2の値2
//!
//! @return    v1からv2を引いた後のVector2
//--------------------------------------------------------------------
Vector2 SubVector2(Vector2* v1, Vector2* v2);
Vector2Int SubVector2(Vector2Int* v1, Vector2Int* v2);



//--------------------------------------------------------------------
//! @summary   Vector2のスケール計算
//!
//! @parameter [vector2] 元のVector2
//! @parameter [scale] 比率
//!
//! @return    vector2のx,yにscaleのx,yを掛けた値
//--------------------------------------------------------------------
Vector2 SceleVector2(Vector2* vector2, Vector2* scale);



//--------------------------------------------------------------------
//! @summary   ベクトルのX成分を反転させる
//!
//! @parameter [vector2] 反転させるvector2
//!
//! @return    なし
//--------------------------------------------------------------------
void TurnOverVector2X(Vector2* vector2);
void TurnOverVector2IntX(Vector2Int* vector2);



//--------------------------------------------------------------------
//! @summary   ベクトルのY成分を反転させる
//!
//! @parameter [vector2] 反転させるvector2
//!
//! @return    なし
//--------------------------------------------------------------------
void TurnOverVector2Y(Vector2* vector2);
void TurnOverVector2IntY(Vector2Int* vector2);



//--------------------------------------------------------------------
//! @summary   ベクトルの正規化
//!
//! @parameter [vector] 正規化するベクトル
//!
//! @return    なし
//--------------------------------------------------------------------
void NormalizeVector2(Vector2* vector);



//--------------------------------------------------------------------
//! @summary   方向と速さから速度を作成する
//!
//! @parameter [direction] 方向ベクトル
//! @parameter [speed] 速さ
//!
//! @return    作成された速度
//--------------------------------------------------------------------
Vector2 CreateVelocity(Vector2* direction, float speed);