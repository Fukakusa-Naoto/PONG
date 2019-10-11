//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		Vector2.h
//!
//! @summary	Vector2‚ÉŠÖ‚·‚éƒwƒbƒ_ƒtƒ@ƒCƒ‹
//!
//! @date		2019.10.11
//!
//! @author		[‘’¼“l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ‘½dƒCƒ“ƒNƒ‹[ƒh‚Ì–h~ ===================================================
#pragma once


// \‘¢‘Ì‚Ì’è‹` ============================================================
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


// ŠÖ”‚Ì’è‹` ==============================================================
//--------------------------------------------------------------------
//! @summary   Vector2‚Ìx,y‚Ì’l‚ª0‚ÌVector2‚ğ•Ô‚·
//!
//! @parameter [void] ‚È‚µ
//!
//! @return    x,y‚ª0‚ÌVector2
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
//! @summary   Vector2‚Ìx,y‚Ì’l‚ª1‚ÌVector2‚ğ•Ô‚·
//!
//! @parameter [void] ‚È‚µ
//!
//! @return    x,y‚ª1‚ÌVector2
//--------------------------------------------------------------------
static Vector2 GetVector2One()
{
	Vector2 zero = { 1.0f, 1.0f };
	return zero;
}



static Vector2Int GetVector2IntOne()
{
	Vector2Int zero = { 1, 1 };
	return zero;
}



//--------------------------------------------------------------------
//! @summary   Vector2‚Ì‘«‚µZ
//!
//! @parameter [v1] ‘«‚µZ‚ğs‚¤Vector2‚Ì’l1
//! @parameter [v2] ‘«‚µZ‚ğs‚¤Vector2‚Ì’l2
//!
//! @return    v1‚Æv2‚ğ‘«‚µ‚½Œã‚ÌVector2
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
//! @summary   Vector2‚Ìˆø‚«Z
//!
//! @parameter [v1] ˆø‚«Z‚ğs‚¤Vector2‚Ì’l1
//! @parameter [v2] ˆø‚«Z‚ğs‚¤Vector2‚Ì’l2
//!
//! @return    v1‚©‚çv2‚ğˆø‚¢‚½Œã‚ÌVector2
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
//! @summary   Vector2‚ÌƒXƒP[ƒ‹ŒvZ
//!
//! @parameter [vector2] Œ³‚ÌVector2
//! @parameter [scale] ”ä—¦
//!
//! @return    vector2‚Ìx,y‚Éscale‚Ìx,y‚ğŠ|‚¯‚½’l
//--------------------------------------------------------------------
static Vector2 SceleVector2(const Vector2* vector2, const Vector2* scale)
{
	Vector2 answer;
	answer.x = vector2->x * scale->x;
	answer.y = vector2->y * scale->y;
	return answer;
}