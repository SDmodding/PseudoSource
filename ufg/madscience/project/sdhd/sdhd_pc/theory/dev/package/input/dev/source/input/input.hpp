// File Line: 832
// RVA: 0x1B6B20
void __fastcall UFG::JoyInputHistory::JoyInputHistory(UFG::JoyInputHistory *this)
{
  this->mPrev = this;
  this->mNext = this;
  UFG::qMemSet(this->mR, 0, 0x100u);
  UFG::qMemSet(this->mTheta, 0, 0x100u);
  UFG::qMemSet(this->mOctantHistory, -1, 0x40u);
  *(_QWORD *)&this->mIndex = 0i64;
  *(_QWORD *)&this->mEndTrim = 0i64;
  this->mLocked = 0;
  this->mOctantIndex = 0;
}

// File Line: 1029
// RVA: 0x1452500
__int64 UFG::_dynamic_initializer_for__UI_HASH_ACTIVE_CONTROLLER_DISCONNECTED__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ACTIVE_CONTROLLER_DISCONNECTED", -1);
  UI_HASH_ACTIVE_CONTROLLER_DISCONNECTED = result;
  return result;
}

// File Line: 1030
// RVA: 0x1452520
__int64 UFG::_dynamic_initializer_for__UI_HASH_ACTIVE_CONTROLLER_RECONNECTED__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ACTIVE_CONTROLLER_RECONNECTED", -1);
  UI_HASH_ACTIVE_CONTROLLER_RECONNECTED = result;
  return result;
}

