//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		CollisionManager.cpp
//!
//! @summary	衝突判定にソースファイル
//!
//! @date		2019.10.11
//!
//! @author		深草直斗
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み =================================================
// <自作ヘッダファイル>
#include "CollisionManager.h"


// 関数の定義 ==============================================================
//--------------------------------------------------------------------
//! @summary   BoxCollider同士の衝突判定
//!
//! @parameter [collider1] 判定を行うBoxCollider1
//! @parameter [collider2] 判定を行うBoxCollider2
//!
//! @return    TRUE :当たっている
//! @return    FALSE:当たっていない
//--------------------------------------------------------------------
BOOL IsCollideAABB(const BoxCollider* collider1, const BoxCollider* collider2)
{
	float top1 = collider1->position.y - (collider1->size.y * 0.5f);
	float bottom1 = collider1->position.y + (collider1->size.y * 0.5f);
	float left1 = collider1->position.x - (collider1->size.x * 0.5f);
	float right1 = collider1->position.x + (collider1->size.x * 0.5f);

	float top2 = collider2->position.y - (collider2->size.y * 0.5f);
	float bottom2 = collider2->position.y + (collider2->size.y * 0.5f);
	float left2 = collider2->position.x - (collider2->size.x * 0.5f);
	float right2 = collider2->position.x + (collider2->size.x * 0.5f);

	if ((top1 <= bottom2) && (bottom1 >= top2) && (left1 <= right2) && (right1 >= left2)) return TRUE;
	else return FALSE;
}