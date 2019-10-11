//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file		PrimitiveBox.h
//!
//! @summary	‹éŒ`‚Ì•`‰æ‚ÉŠÖ‚·‚éƒwƒbƒ_ƒtƒ@ƒCƒ‹
//!
//! @date		2019.10.11
//!
//! @author		[‘’¼“l
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ‘½dƒCƒ“ƒNƒ‹[ƒh‚Ì–hŽ~ ===================================================
#pragma once


// \‘¢‘Ì‚Ì’è‹` ============================================================
struct Tag_PrimitiveBox
{
	// •`‰æ‚·‚é’†SÀ•W
	Vector2 position;
	// •`‰æ‚·‚é•‚Æ‚‚³ix:•, y:‚‚³j
	Vector2 size;
	// F
	unsigned int color;
	// “h‚è‚Â‚Ô‚µƒtƒ‰ƒOiTRUE:“h‚è‚Â‚Ô‚·, FALSE:“h‚è‚Â‚Ô‚³‚È‚¢j
	BOOL fillFlag;
};
typedef struct Tag_PrimitiveBox PrimitiveBox;



// ŠÖ”‚Ì’è‹` ==============================================================
//--------------------------------------------------------------------
//! @summary   ‹éŒ`‚Ì•`‰æ
//!
//! @parameter [box] •`‰æ‚·‚é‹éŒ`ƒf[ƒ^
//!
//! @return    ‚È‚µ
//--------------------------------------------------------------------
static void DrawBox(const PrimitiveBox* box)
{
	// ¶ãA‰E‰º‚ÌŒvŽZ
	float top = box->position.y - (box->size.y * 0.5f);
	float bottom = box->position.y + (box->size.y * 0.5f);
	float right = box->position.x + (box->size.x * 0.5f);
	float left = box->position.x - (box->size.x * 0.5f);

	// •`‰æ
	DrawBoxAA(left, top, right, bottom, box->color, box->fillFlag);
}