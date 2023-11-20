// File Line: 33
// RVA: 0x149ED60
__int64 dynamic_initializer_for__ragdollTrackEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&ragdollTrackEnum, gRaddollModeStringList, 4, 0i64);
  return atexit(dynamic_atexit_destructor_for__ragdollTrackEnum__);
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
  RagdollTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollTrack::`vftable;
  *(_QWORD *)&v1->mRagdollMode.mValue = 0i64;
  *(_WORD *)&v1->mActivate = 1;
  v1->mApplyHitImpulseScale = 0.0;
  v1->mMaster = 1;
}

// File Line: 59
// RVA: 0x2E4C20
void __fastcall RagdollTrack::~RagdollTrack(RagdollTrack *this)
{
  RagdollTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  RagdollCollisionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollCollisionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollCollisionTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollCollisionTrack::`vftable;
}

// File Line: 87
// RVA: 0x2E4980
void __fastcall RagdollCollisionTrack::~RagdollCollisionTrack(RagdollCollisionTrack *this)
{
  RagdollCollisionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollCollisionTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  RagdollImpulseTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollImpulseTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollImpulseTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollImpulseTrack::`vftable;
  *(_QWORD *)&v1->mDirection = 0i64;
  v1->mElevation = 0.0;
  v1->mHitLimbName = UFG::gNullQSymbolUC;
}

// File Line: 117
// RVA: 0x2E4A60
void __fastcall RagdollImpulseTrack::~RagdollImpulseTrack(RagdollImpulseTrack *this)
{
  RagdollImpulseTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollImpulseTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  RagdollAngularImpulseTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollAngularImpulseTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollAngularImpulseTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollAngularImpulseTrack::`vftable;
  *(_QWORD *)&v1->mRoll = 0i64;
  *(_QWORD *)&v1->mScrew = 0i64;
  v1->mConnectionTransfer = 1.0;
  v1->mHitLimbName = UFG::gNullQSymbolUC;
  v1->mUseVelocityFrame = 0;
}

// File Line: 157
// RVA: 0x2E4590
void __fastcall RagdollAngularImpulseTrack::~RagdollAngularImpulseTrack(RagdollAngularImpulseTrack *this)
{
  RagdollAngularImpulseTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollAngularImpulseTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  RagdollMotorTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollMotorTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollMotorTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollMotorTrack::`vftable;
  v1->mMaxForce = 800.0;
  v1->mLimbName = UFG::gNullQSymbolUC;
  v1->mMaster = 1;
}

// File Line: 194
// RVA: 0x2E4AD0
void __fastcall RagdollMotorTrack::~RagdollMotorTrack(RagdollMotorTrack *this)
{
  RagdollMotorTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollMotorTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  RagdollBlendMotorTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollBlendMotorTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollBlendMotorTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollBlendMotorTrack::`vftable;
  *(_QWORD *)&v1->mTargetStrength = 1145569280i64;
  v1->mMaster = 1;
}

// File Line: 224
// RVA: 0x2E4670
void __fastcall RagdollBlendMotorTrack::~RagdollBlendMotorTrack(RagdollBlendMotorTrack *this)
{
  RagdollBlendMotorTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollBlendMotorTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  RagdollAquireTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollAquireTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollAquireTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollAquireTrack::`vftable;
  v1->mRagdollMode.mValue = 0;
  v1->mVelocityTrackingStrength = 1.0;
  v1->mMotorStrength = 1000.0;
  *(_QWORD *)&v1->mBlendWeight = 1065353216i64;
  v1->mAngularLimitStrength = 1.0;
}

// File Line: 259
// RVA: 0x2E4600
void __fastcall RagdollAquireTrack::~RagdollAquireTrack(RagdollAquireTrack *this)
{
  RagdollAquireTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollAquireTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  RagdollReleaseTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollReleaseTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollReleaseTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollReleaseTrack::`vftable;
  v1->mForceRelease = 0;
}

// File Line: 288
// RVA: 0x2E4B40
void __fastcall RagdollReleaseTrack::~RagdollReleaseTrack(RagdollReleaseTrack *this)
{
  RagdollReleaseTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollReleaseTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  RagdollChangeModeTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollChangeModeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollChangeModeTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeModeTrack::`vftable;
  v1->mRagdollMode.mValue = 0;
}

// File Line: 312
// RVA: 0x2E47C0
void __fastcall RagdollChangeModeTrack::~RagdollChangeModeTrack(RagdollChangeModeTrack *this)
{
  RagdollChangeModeTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeModeTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  RagdollSetFrictionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollSetFrictionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollSetFrictionTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollSetFrictionTrack::`vftable;
  v1->mMu = 0.69999999;
}

// File Line: 337
// RVA: 0x2E4BB0
void __fastcall RagdollSetFrictionTrack::~RagdollSetFrictionTrack(RagdollSetFrictionTrack *this)
{
  RagdollSetFrictionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollSetFrictionTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  RagdollAdjustMassTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollAdjustMassTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollAdjustMassTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollAdjustMassTrack::`vftable;
  v1->mMu = 0.69999999;
}

// File Line: 362
// RVA: 0x2E4520
void __fastcall RagdollAdjustMassTrack::~RagdollAdjustMassTrack(RagdollAdjustMassTrack *this)
{
  RagdollAdjustMassTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollAdjustMassTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  RagdollChangeMotorTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollChangeMotorTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollChangeMotorTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeMotorTrack::`vftable;
  v1->mTargetStrength = 1000.0;
}

// File Line: 388
// RVA: 0x2E4830
void __fastcall RagdollChangeMotorTrack::~RagdollChangeMotorTrack(RagdollChangeMotorTrack *this)
{
  RagdollChangeMotorTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeMotorTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  RagdollChangeBlendWeightTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollChangeBlendWeightTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollChangeBlendWeightTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeBlendWeightTrack::`vftable;
  v1->mTargetStrength = 1.0;
}

// File Line: 414
// RVA: 0x2E4750
void __fastcall RagdollChangeBlendWeightTrack::~RagdollChangeBlendWeightTrack(RagdollChangeBlendWeightTrack *this)
{
  RagdollChangeBlendWeightTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeBlendWeightTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
void __fastcall RagdollChangeVelocityTrackingStrTrack::RagdollChangeVelocityTrackingStrTrack(RagdollChangeVelocityTrackingStrTrack *this)
{
  RagdollChangeVelocityTrackingStrTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollChangeVelocityTrackingStrTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollChangeVelocityTrackingStrTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeVelocityTrackingStrTrack::`vftable;
  v1->mTargetStrength = 1.0;
  v1->mLimbName = UFG::gNullQSymbolUC;
}

// File Line: 442
// RVA: 0x2E4910
void __fastcall RagdollChangeVelocityTrackingStrTrack::~RagdollChangeVelocityTrackingStrTrack(RagdollChangeVelocityTrackingStrTrack *this)
{
  RagdollChangeVelocityTrackingStrTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeVelocityTrackingStrTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
void __fastcall RagdollChangeVelocityTrackingParamsRawTrack::RagdollChangeVelocityTrackingParamsRawTrack(RagdollChangeVelocityTrackingParamsRawTrack *this)
{
  RagdollChangeVelocityTrackingParamsRawTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollChangeVelocityTrackingParamsRawTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollChangeVelocityTrackingParamsRawTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeVelocityTrackingParamsRawTrack::`vftable;
  v1->mLimbName = UFG::gNullQSymbolUC;
  *(_QWORD *)&v1->mHierarchyGain = 1043207291i64;
  v1->mAccelerationGain = 1.0;
  v1->mVelocityGain = 0.60000002;
  v1->mPositionGain = 0.050000001;
  v1->mPositionMaxLinearVelocity = 1.4;
  v1->mPositionMaxAngularVelocity = 1.8;
  v1->mSnapGain = 0.1;
  v1->mSnapMaxLinearVelocity = 0.30000001;
  v1->mSnapMaxAngularVelocity = 0.30000001;
  v1->mSnapMaxLinearDistance = 0.029999999;
  v1->mSnapMaxAngularDistance = 0.1;
}

// File Line: 637
// RVA: 0x2E48A0
void __fastcall RagdollChangeVelocityTrackingParamsRawTrack::~RagdollChangeVelocityTrackingParamsRawTrack(RagdollChangeVelocityTrackingParamsRawTrack *this)
{
  RagdollChangeVelocityTrackingParamsRawTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeVelocityTrackingParamsRawTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
void __fastcall RagdollChangeAngularLimitStrTrack::RagdollChangeAngularLimitStrTrack(RagdollChangeAngularLimitStrTrack *this)
{
  RagdollChangeAngularLimitStrTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollChangeAngularLimitStrTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollChangeAngularLimitStrTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeAngularLimitStrTrack::`vftable;
  v1->mTargetStrength = 1.0;
}

// File Line: 676
// RVA: 0x2E46E0
void __fastcall RagdollChangeAngularLimitStrTrack::~RagdollChangeAngularLimitStrTrack(RagdollChangeAngularLimitStrTrack *this)
{
  RagdollChangeAngularLimitStrTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollChangeAngularLimitStrTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  RagdollDeathImpulseTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RagdollDeathImpulseTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RagdollDeathImpulseTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&RagdollDeathImpulseTrack::`vftable;
  v1->mApplyHitImpulseScale = 1.0;
}

// File Line: 701
// RVA: 0x2E49F0
void __fastcall RagdollDeathImpulseTrack::~RagdollDeathImpulseTrack(RagdollDeathImpulseTrack *this)
{
  RagdollDeathImpulseTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RagdollDeathImpulseTrack::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v2 = &this->mMasterRate;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

