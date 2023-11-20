// File Line: 23
// RVA: 0x14B07D0
__int64 UFG::_dynamic_initializer_for__UI_HASH_FADEOUTCOMPLETE___1()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("FADEOUTCOMPLETE", 0xFFFFFFFF);
  UI_HASH_FADEOUTCOMPLETE_1 = result;
  return result;
}

// File Line: 24
// RVA: 0x14B07B0
__int64 UFG::_dynamic_initializer_for__UI_HASH_FADEINCOMPLETE___1()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("FADEINCOMPLETE", 0xFFFFFFFF);
  UI_HASH_FADEINCOMPLETE_1 = result;
  return result;
}

// File Line: 25
// RVA: 0x14AFAD0
__int64 UFG::_dynamic_initializer_for__UI_HASH_ADD_SUBTITLE_MSG___1()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ADD_SUBTITLE_MSG", 0xFFFFFFFF);
  UI_HASH_ADD_SUBTITLE_MSG_1 = result;
  return result;
}

// File Line: 26
// RVA: 0x14AFAB0
__int64 UFG::_dynamic_initializer_for__UI_HASH_ADD_MISSION_OBJ_MSG___1()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ADD_MISSION_OBJ_MSG", 0xFFFFFFFF);
  UI_HASH_ADD_MISSION_OBJ_MSG_1 = result;
  return result;
}

// File Line: 27
// RVA: 0x14AFA90
__int64 UFG::_dynamic_initializer_for__UI_HASH_ADD_FREETEXT_MSG___1()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ADD_FREETEXT_MSG", 0xFFFFFFFF);
  UI_HASH_ADD_FREETEXT_MSG_1 = result;
  return result;
}

// File Line: 68
// RVA: 0x3E0660
void __fastcall UFG::UISubtitleMessage::UISubtitleMessage(UFG::UISubtitleMessage *this, UFG::UISubtitleMessage::eSUBTITLE_MESSAGE_TYPE type, const char *text, const char *icon)
{
  const char *v4; // rdi
  const char *v5; // rsi
  UFG::UISubtitleMessage::eSUBTITLE_MESSAGE_TYPE v6; // ebx
  UFG::UISubtitleMessage *v7; // r14

  v4 = icon;
  v5 = text;
  v6 = type;
  v7 = this;
  this->mPrev = (UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::UISubtitleMessage,UFG::UISubtitleMessage> *)&this->mPrev;
  *(_QWORD *)&this->id = 0i64;
  *(_QWORD *)&this->lifetime = 0x40800000i64;
  *(_QWORD *)&this->xPos = 0i64;
  UFG::qString::qString(&this->color, "FFFFFF");
  UFG::qString::qString(&v7->title);
  v7->state = 4;
  v7->type = v6;
  UFG::qString::qString(&v7->mIcon, v4);
  UFG::qString::qString(&v7->mText, v5);
}

