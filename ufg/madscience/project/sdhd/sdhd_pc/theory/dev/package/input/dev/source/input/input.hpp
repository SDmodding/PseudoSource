// File Line: 832
// RVA: 0x1B6B20
void __fastcall UFG::JoyInputHistory::JoyInputHistory(UFG::JoyInputHistory *this)
{
  UFG::JoyInputHistory *v1; // rbx

  v1 = this;
  this->mPrev = (UFG::qNode<UFG::JoyInputHistory,UFG::JoyInputHistory> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::JoyInputHistory,UFG::JoyInputHistory> *)&this->mPrev;
  UFG::qMemSet(this->mR, 0, 0x100u);
  UFG::qMemSet(v1->mTheta, 0, 0x100u);
  UFG::qMemSet(v1->mOctantHistory, -1, 0x40u);
  *(_QWORD *)&v1->mIndex = 0i64;
  *(_QWORD *)&v1->mEndTrim = 0i64;
  v1->mLocked = 0;
  v1->mOctantIndex = 0;
}

// File Line: 1029
// RVA: 0x1452500
__int64 UFG::_dynamic_initializer_for__UI_HASH_ACTIVE_CONTROLLER_DISCONNECTED__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ACTIVE_CONTROLLER_DISCONNECTED", 0xFFFFFFFF);
  UI_HASH_ACTIVE_CONTROLLER_DISCONNECTED = result;
  return result;
}

// File Line: 1030
// RVA: 0x1452520
__int64 UFG::_dynamic_initializer_for__UI_HASH_ACTIVE_CONTROLLER_RECONNECTED__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("ACTIVE_CONTROLLER_RECONNECTED", 0xFFFFFFFF);
  UI_HASH_ACTIVE_CONTROLLER_RECONNECTED = result;
  return result;
}

