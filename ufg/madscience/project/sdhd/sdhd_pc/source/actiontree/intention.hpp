// File Line: 277
// RVA: 0x15E190
void __fastcall Intention::Set(Intention *this, unsigned int action_request, float chargeTime)
{
  signed __int64 v3; // r9
  float v4; // xmm1_4

  v3 = 1i64 << (action_request & 0x3F);
  this->mActionRequests.mBits[(signed __int64)(signed int)action_request >> 6] |= v3;
  v4 = (float)(signed int)(float)(chargeTime * 60.0);
  if ( v4 >= 255.0 )
    v4 = FLOAT_255_0;
  this->mActionRequestChargeTimes[action_request] = (signed int)v4;
  this->mSignals |= v3;
}

// File Line: 290
// RVA: 0x15E0E0
void __fastcall Intention::Set(Intention *this, UFG::qStaticBitField<548> *bitfield)
{
  this->mActionRequests.mBits[0] |= bitfield->mBits[0];
  this->mActionRequests.mBits[1] |= bitfield->mBits[1];
  this->mActionRequests.mBits[2] |= bitfield->mBits[2];
  this->mActionRequests.mBits[3] |= bitfield->mBits[3];
  this->mActionRequests.mBits[4] |= bitfield->mBits[4];
  this->mActionRequests.mBits[5] |= bitfield->mBits[5];
  this->mActionRequests.mBits[6] |= bitfield->mBits[6];
  this->mActionRequests.mBits[7] |= bitfield->mBits[7];
  this->mActionRequests.mBits[8] |= bitfield->mBits[8];
  this->mSignals = this->mActionRequests.mBits[0] | this->mActionRequests.mBits[1] | this->mActionRequests.mBits[2] | this->mActionRequests.mBits[3] | this->mActionRequests.mBits[4] | this->mActionRequests.mBits[5] | this->mActionRequests.mBits[6] | this->mActionRequests.mBits[7] | this->mActionRequests.mBits[8];
}

// File Line: 356
// RVA: 0x26E300
__int64 __fastcall ActionRequestDebug::GetClassNameUID(ActionRequestDebug *this)
{
  return ActionRequestDebug::sClassNameUID;
}

// File Line: 376
// RVA: 0x2C1640
const char *__fastcall IntentionDebug::GetClassname(IntentionDebug *this)
{
  return IntentionDebug::sClassName;
}

