// File Line: 33
// RVA: 0x149ED60
__int64 dynamic_initializer_for__ragdollTrackEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&ragdollTrackEnum, gRaddollModeStringList, 4, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__ragdollTrackEnum__);
}

// File Line: 35
// RVA: 0x1495DB0
__int64 dynamic_initializer_for__RagdollTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollTrack", 0xFFFFFFFF);
  RagdollTrack::sClassNameUID = result;
  return result;
}

// File Line: 54
// RVA: 0x2E0B20
void __fastcall RagdollTrack::RagdollTrack(RagdollTrack *this)
{
  ITrack::ITrack(this, RagdollTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollTrack::`vftable;
  *(_QWORD *)&this->mRagdollMode.mValue = 0i64;
  *(_WORD *)&this->mActivate = 1;
  this->mApplyHitImpulseScale = 0.0;
  this->mMaster = 1;
}

// File Line: 59
// RVA: 0x2E4C20
void __fastcall RagdollTrack::~RagdollTrack(RagdollTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 76
// RVA: 0x1495CF0
__int64 dynamic_initializer_for__RagdollCollisionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollCollisionTrack", 0xFFFFFFFF);
  RagdollCollisionTrack::sClassNameUID = result;
  return result;
}

// File Line: 83
// RVA: 0x2E0930
void __fastcall RagdollCollisionTrack::RagdollCollisionTrack(RagdollCollisionTrack *this)
{
  ITrack::ITrack(this, RagdollCollisionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollCollisionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollCollisionTrack::`vftable;
}

// File Line: 87
// RVA: 0x2E4980
void __fastcall RagdollCollisionTrack::~RagdollCollisionTrack(RagdollCollisionTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollCollisionTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 98
// RVA: 0x1495D30
__int64 dynamic_initializer_for__RagdollImpulseTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollImpulseTrack", 0xFFFFFFFF);
  RagdollImpulseTrack::sClassNameUID = result;
  return result;
}

// File Line: 113
// RVA: 0x2E09C0
void __fastcall RagdollImpulseTrack::RagdollImpulseTrack(RagdollImpulseTrack *this)
{
  ITrack::ITrack(this, RagdollImpulseTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollImpulseTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollImpulseTrack::`vftable;
  *(_QWORD *)&this->mDirection = 0i64;
  this->mElevation = 0.0;
  this->mHitLimbName = UFG::gNullQSymbolUC;
}

// File Line: 117
// RVA: 0x2E4A60
void __fastcall RagdollImpulseTrack::~RagdollImpulseTrack(RagdollImpulseTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollImpulseTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 132
// RVA: 0x1495BD0
__int64 dynamic_initializer_for__RagdollAngularImpulseTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollAngularImpulseTrack", 0xFFFFFFFF);
  RagdollAngularImpulseTrack::sClassNameUID = result;
  return result;
}

// File Line: 153
// RVA: 0x2E05E0
void __fastcall RagdollAngularImpulseTrack::RagdollAngularImpulseTrack(RagdollAngularImpulseTrack *this)
{
  ITrack::ITrack(this, RagdollAngularImpulseTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollAngularImpulseTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollAngularImpulseTrack::`vftable;
  *(_QWORD *)&this->mRoll = 0i64;
  *(_QWORD *)&this->mScrew = 0i64;
  this->mConnectionTransfer = 1.0;
  this->mHitLimbName = UFG::gNullQSymbolUC;
  this->mUseVelocityFrame = 0;
}

// File Line: 157
// RVA: 0x2E4590
void __fastcall RagdollAngularImpulseTrack::~RagdollAngularImpulseTrack(RagdollAngularImpulseTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollAngularImpulseTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 175
// RVA: 0x1495D50
__int64 dynamic_initializer_for__RagdollMotorTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollMotorTrack", 0xFFFFFFFF);
  RagdollMotorTrack::sClassNameUID = result;
  return result;
}

// File Line: 189
// RVA: 0x2E0A20
void __fastcall RagdollMotorTrack::RagdollMotorTrack(RagdollMotorTrack *this)
{
  ITrack::ITrack(this, RagdollMotorTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollMotorTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollMotorTrack::`vftable;
  this->mMaxForce = 800.0;
  this->mLimbName = UFG::gNullQSymbolUC;
  this->mMaster = 1;
}

// File Line: 194
// RVA: 0x2E4AD0
void __fastcall RagdollMotorTrack::~RagdollMotorTrack(RagdollMotorTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollMotorTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 207
// RVA: 0x1495C10
__int64 dynamic_initializer_for__RagdollBlendMotorTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollBlendMotorTrack", 0xFFFFFFFF);
  RagdollBlendMotorTrack::sClassNameUID = result;
  return result;
}

// File Line: 219
// RVA: 0x2E06B0
void __fastcall RagdollBlendMotorTrack::RagdollBlendMotorTrack(RagdollBlendMotorTrack *this)
{
  ITrack::ITrack(this, RagdollBlendMotorTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollBlendMotorTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollBlendMotorTrack::`vftable;
  *(_QWORD *)&this->mTargetStrength = 1145569280i64;
  this->mMaster = 1;
}

// File Line: 224
// RVA: 0x2E4670
void __fastcall RagdollBlendMotorTrack::~RagdollBlendMotorTrack(RagdollBlendMotorTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollBlendMotorTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 237
// RVA: 0x1495BF0
__int64 dynamic_initializer_for__RagdollAquireTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollAquireTrack", 0xFFFFFFFF);
  RagdollAquireTrack::sClassNameUID = result;
  return result;
}

// File Line: 255
// RVA: 0x2E0640
void __fastcall RagdollAquireTrack::RagdollAquireTrack(RagdollAquireTrack *this)
{
  ITrack::ITrack(this, RagdollAquireTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollAquireTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollAquireTrack::`vftable;
  this->mRagdollMode.mValue = 0;
  this->mVelocityTrackingStrength = 1.0;
  this->mMotorStrength = 1000.0;
  *(_QWORD *)&this->mBlendWeight = 1065353216i64;
  this->mAngularLimitStrength = 1.0;
}

// File Line: 259
// RVA: 0x2E4600
void __fastcall RagdollAquireTrack::~RagdollAquireTrack(RagdollAquireTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollAquireTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 276
// RVA: 0x1495D70
__int64 dynamic_initializer_for__RagdollReleaseTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollReleaseTrack", 0xFFFFFFFF);
  RagdollReleaseTrack::sClassNameUID = result;
  return result;
}

// File Line: 284
// RVA: 0x2E0A80
void __fastcall RagdollReleaseTrack::RagdollReleaseTrack(RagdollReleaseTrack *this)
{
  ITrack::ITrack(this, RagdollReleaseTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollReleaseTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollReleaseTrack::`vftable;
  this->mForceRelease = 0;
}

// File Line: 288
// RVA: 0x2E4B40
void __fastcall RagdollReleaseTrack::~RagdollReleaseTrack(RagdollReleaseTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollReleaseTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 300
// RVA: 0x1495C70
__int64 dynamic_initializer_for__RagdollChangeModeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollChangeModeTrack", 0xFFFFFFFF);
  RagdollChangeModeTrack::sClassNameUID = result;
  return result;
}

// File Line: 308
// RVA: 0x2E07A0
void __fastcall RagdollChangeModeTrack::RagdollChangeModeTrack(RagdollChangeModeTrack *this)
{
  ITrack::ITrack(this, RagdollChangeModeTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollChangeModeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeModeTrack::`vftable;
  this->mRagdollMode.mValue = 0;
}

// File Line: 312
// RVA: 0x2E47C0
void __fastcall RagdollChangeModeTrack::~RagdollChangeModeTrack(RagdollChangeModeTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeModeTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 324
// RVA: 0x1495D90
__int64 dynamic_initializer_for__RagdollSetFrictionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollSetFrictionTrack", 0xFFFFFFFF);
  RagdollSetFrictionTrack::sClassNameUID = result;
  return result;
}

// File Line: 333
// RVA: 0x2E0AD0
void __fastcall RagdollSetFrictionTrack::RagdollSetFrictionTrack(RagdollSetFrictionTrack *this)
{
  ITrack::ITrack(this, RagdollSetFrictionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollSetFrictionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollSetFrictionTrack::`vftable;
  this->mMu = 0.69999999;
}

// File Line: 337
// RVA: 0x2E4BB0
void __fastcall RagdollSetFrictionTrack::~RagdollSetFrictionTrack(RagdollSetFrictionTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollSetFrictionTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 349
// RVA: 0x1495BB0
__int64 dynamic_initializer_for__RagdollAdjustMassTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollAdjustMassTrack", 0xFFFFFFFF);
  RagdollAdjustMassTrack::sClassNameUID = result;
  return result;
}

// File Line: 358
// RVA: 0x2E0590
void __fastcall RagdollAdjustMassTrack::RagdollAdjustMassTrack(RagdollAdjustMassTrack *this)
{
  ITrack::ITrack(this, RagdollAdjustMassTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollAdjustMassTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollAdjustMassTrack::`vftable;
  this->mMu = 0.69999999;
}

// File Line: 362
// RVA: 0x2E4520
void __fastcall RagdollAdjustMassTrack::~RagdollAdjustMassTrack(RagdollAdjustMassTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollAdjustMassTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 374
// RVA: 0x1495C90
__int64 dynamic_initializer_for__RagdollChangeMotorTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollChangeMotorTrack", 0xFFFFFFFF);
  RagdollChangeMotorTrack::sClassNameUID = result;
  return result;
}

// File Line: 384
// RVA: 0x2E07F0
void __fastcall RagdollChangeMotorTrack::RagdollChangeMotorTrack(RagdollChangeMotorTrack *this)
{
  ITrack::ITrack(this, RagdollChangeMotorTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollChangeMotorTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeMotorTrack::`vftable;
  this->mTargetStrength = 1000.0;
}

// File Line: 388
// RVA: 0x2E4830
void __fastcall RagdollChangeMotorTrack::~RagdollChangeMotorTrack(RagdollChangeMotorTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeMotorTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 400
// RVA: 0x1495C50
__int64 dynamic_initializer_for__RagdollChangeBlendWeightTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollChangeBlendWeightTrack", 0xFFFFFFFF);
  RagdollChangeBlendWeightTrack::sClassNameUID = result;
  return result;
}

// File Line: 410
// RVA: 0x2E0750
void __fastcall RagdollChangeBlendWeightTrack::RagdollChangeBlendWeightTrack(RagdollChangeBlendWeightTrack *this)
{
  ITrack::ITrack(this, RagdollChangeBlendWeightTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollChangeBlendWeightTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeBlendWeightTrack::`vftable;
  this->mTargetStrength = 1.0;
}

// File Line: 414
// RVA: 0x2E4750
void __fastcall RagdollChangeBlendWeightTrack::~RagdollChangeBlendWeightTrack(RagdollChangeBlendWeightTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeBlendWeightTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 426
// RVA: 0x1495CD0
__int64 dynamic_initializer_for__RagdollChangeVelocityTrackingStrTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollChangeVelocityTrackingStrTrack", 0xFFFFFFFF);
  RagdollChangeVelocityTrackingStrTrack::sClassNameUID = result;
  return result;
}

// File Line: 438
// RVA: 0x2E08E0
void __fastcall RagdollChangeVelocityTrackingStrTrack::RagdollChangeVelocityTrackingStrTrack(
        RagdollChangeVelocityTrackingStrTrack *this)
{
  ITrack::ITrack(this, RagdollChangeVelocityTrackingStrTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollChangeVelocityTrackingStrTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeVelocityTrackingStrTrack::`vftable;
  this->mTargetStrength = 1.0;
  this->mLimbName = UFG::gNullQSymbolUC;
}

// File Line: 442
// RVA: 0x2E4910
void __fastcall RagdollChangeVelocityTrackingStrTrack::~RagdollChangeVelocityTrackingStrTrack(
        RagdollChangeVelocityTrackingStrTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeVelocityTrackingStrTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 583
// RVA: 0x1495CB0
__int64 dynamic_initializer_for__RagdollChangeVelocityTrackingParamsRawTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollChangeVelocityTrackingParamsRawTrack", 0xFFFFFFFF);
  RagdollChangeVelocityTrackingParamsRawTrack::sClassNameUID = result;
  return result;
}

// File Line: 632
// RVA: 0x2E0840
void __fastcall RagdollChangeVelocityTrackingParamsRawTrack::RagdollChangeVelocityTrackingParamsRawTrack(
        RagdollChangeVelocityTrackingParamsRawTrack *this)
{
  ITrack::ITrack(this, RagdollChangeVelocityTrackingParamsRawTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollChangeVelocityTrackingParamsRawTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeVelocityTrackingParamsRawTrack::`vftable;
  this->mLimbName = UFG::gNullQSymbolUC;
  *(_QWORD *)&this->mHierarchyGain = 1043207291i64;
  this->mAccelerationGain = 1.0;
  this->mVelocityGain = 0.60000002;
  this->mPositionGain = 0.050000001;
  this->mPositionMaxLinearVelocity = 1.4;
  this->mPositionMaxAngularVelocity = 1.8;
  this->mSnapGain = 0.1;
  this->mSnapMaxLinearVelocity = 0.30000001;
  this->mSnapMaxAngularVelocity = 0.30000001;
  this->mSnapMaxLinearDistance = 0.029999999;
  this->mSnapMaxAngularDistance = 0.1;
}

// File Line: 637
// RVA: 0x2E48A0
void __fastcall RagdollChangeVelocityTrackingParamsRawTrack::~RagdollChangeVelocityTrackingParamsRawTrack(
        RagdollChangeVelocityTrackingParamsRawTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeVelocityTrackingParamsRawTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 662
// RVA: 0x1495C30
__int64 dynamic_initializer_for__RagdollChangeAngularLimitStrTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollChangeAngularLimitStrTrack", 0xFFFFFFFF);
  RagdollChangeAngularLimitStrTrack::sClassNameUID = result;
  return result;
}

// File Line: 672
// RVA: 0x2E0700
void __fastcall RagdollChangeAngularLimitStrTrack::RagdollChangeAngularLimitStrTrack(
        RagdollChangeAngularLimitStrTrack *this)
{
  ITrack::ITrack(this, RagdollChangeAngularLimitStrTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollChangeAngularLimitStrTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeAngularLimitStrTrack::`vftable;
  this->mTargetStrength = 1.0;
}

// File Line: 676
// RVA: 0x2E46E0
void __fastcall RagdollChangeAngularLimitStrTrack::~RagdollChangeAngularLimitStrTrack(
        RagdollChangeAngularLimitStrTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeAngularLimitStrTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 688
// RVA: 0x1495D10
__int64 dynamic_initializer_for__RagdollDeathImpulseTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RagdollDeathImpulseTrack", 0xFFFFFFFF);
  RagdollDeathImpulseTrack::sClassNameUID = result;
  return result;
}

// File Line: 697
// RVA: 0x2E0970
void __fastcall RagdollDeathImpulseTrack::RagdollDeathImpulseTrack(RagdollDeathImpulseTrack *this)
{
  ITrack::ITrack(this, RagdollDeathImpulseTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollDeathImpulseTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollDeathImpulseTrack::`vftable;
  this->mApplyHitImpulseScale = 1.0;
}

// File Line: 701
// RVA: 0x2E49F0
void __fastcall RagdollDeathImpulseTrack::~RagdollDeathImpulseTrack(RagdollDeathImpulseTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollDeathImpulseTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (p_mMasterRate->text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

