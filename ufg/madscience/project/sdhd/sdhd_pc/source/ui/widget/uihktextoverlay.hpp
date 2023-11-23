// File Line: 23
// RVA: 0x1481720
__int64 UFG::_dynamic_initializer_for__UI_HASH_FADEOUTCOMPLETE__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("FADEOUTCOMPLETE", -1);
  UI_HASH_FADEOUTCOMPLETE = result;
  return result;
}

// File Line: 24
// RVA: 0x1481700
__int64 UFG::_dynamic_initializer_for__UI_HASH_FADEINCOMPLETE__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("FADEINCOMPLETE", -1);
  UI_HASH_FADEINCOMPLETE = result;
  return result;
}

// File Line: 25
// RVA: 0x1480A20
__int64 UFG::_dynamic_initializer_for__UI_HASH_ADD_SUBTITLE_MSG__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ADD_SUBTITLE_MSG", -1);
  UI_HASH_ADD_SUBTITLE_MSG = result;
  return result;
}

// File Line: 26
// RVA: 0x1480A00
__int64 UFG::_dynamic_initializer_for__UI_HASH_ADD_MISSION_OBJ_MSG__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ADD_MISSION_OBJ_MSG", -1);
  UI_HASH_ADD_MISSION_OBJ_MSG = result;
  return result;
}

// File Line: 27
// RVA: 0x14809E0
__int64 UFG::_dynamic_initializer_for__UI_HASH_ADD_FREETEXT_MSG__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ADD_FREETEXT_MSG", -1);
  UI_HASH_ADD_FREETEXT_MSG = result;
  return result;
}

// File Line: 82
// RVA: 0x593700
void __fastcall UFG::UISubtitleMessage::UISubtitleMessage(
        UFG::UISubtitleMessage *this,
        UFG::UISubtitleMessage::eSUBTITLE_MESSAGE_TYPE type,
        unsigned int tagHash,
        const char *icon)
{
  this->mPrev = this;
  this->mNext = this;
  this->id = 0;
  this->mTagHash = tagHash;
  *(_QWORD *)&this->lifetime = 1082130432i64;
  *(_QWORD *)&this->xPos = 0i64;
  UFG::qString::qString(&this->color, "FFFFFF");
  UFG::qString::qString(&this->title);
  this->state = STATE_DONE;
  this->type = type;
  UFG::qString::qString(&this->mIcon, icon);
  UFG::qString::qString(&this->mText, &customCaption);
}

