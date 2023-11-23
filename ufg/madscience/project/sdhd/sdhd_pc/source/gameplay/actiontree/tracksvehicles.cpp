// File Line: 19
// RVA: 0x1496A30
__int64 dynamic_initializer_for__VehicleSetDoorsLockedTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleSetDoorsLockedTrack", 0xFFFFFFFF);
  VehicleSetDoorsLockedTrack::sClassNameUID = result;
  return result;
}

// File Line: 27
// RVA: 0x2E2820
void __fastcall VehicleSetDoorsLockedTrack::VehicleSetDoorsLockedTrack(VehicleSetDoorsLockedTrack *this)
{
  ITrack::ITrack(this, VehicleSetDoorsLockedTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleSetDoorsLockedTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleSetDoorsLockedTrack::`vftable;
  this->m_Locked = 1;
}

// File Line: 39
// RVA: 0x1496890
__int64 dynamic_initializer_for__VehicleDestroyTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleDestroyTrack", 0xFFFFFFFF);
  VehicleDestroyTrack::sClassNameUID = result;
  return result;
}

// File Line: 52
// RVA: 0x149BB40
__int64 dynamic_initializer_for__VehicleStateEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&VehicleStateEnum, gVehicleStateStringList, 5, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__VehicleStateEnum__);
}

// File Line: 54
// RVA: 0x1496A70
__int64 dynamic_initializer_for__VehicleStateTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleStateTrack", 0xFFFFFFFF);
  VehicleStateTrack::sClassNameUID = result;
  return result;
}

// File Line: 63
// RVA: 0x2E28E0
void __fastcall VehicleStateTrack::VehicleStateTrack(VehicleStateTrack *this)
{
  ITrack::ITrack(this, VehicleStateTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleStateTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleStateTrack::`vftable;
  this->mState.mValue = 1;
  this->mMaster = 1;
}

// File Line: 68
// RVA: 0x2E5F20
void __fastcall VehicleStateTrack::~VehicleStateTrack(VehicleStateTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleStateTrack::`vftable;
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

// File Line: 86
// RVA: 0x14968F0
__int64 dynamic_initializer_for__VehicleFlipTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleFlipTrack", 0xFFFFFFFF);
  VehicleFlipTrack::sClassNameUID = result;
  return result;
}

// File Line: 112
// RVA: 0x2E24A0
void __fastcall VehicleFlipTrack::VehicleFlipTrack(VehicleFlipTrack *this)
{
  ITrack::ITrack(this, VehicleFlipTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleFlipTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleFlipTrack::`vftable;
  this->mRotationAboutXMultiplier = 10.0;
  this->mRotationAboutYMultiplier = 10.0;
  *(_QWORD *)&this->mRotationAboutZMultiplier = 1092616192i64;
  *(_QWORD *)&this->mRotationAboutYAdditive = 0i64;
  this->mMinAngularSpeed = 0.0;
  this->mMaxAngularSpeed = -1.0;
  this->mMinLinearSpeedMPS = 0.0;
  this->mMaxLinearSpeedMPS = -1.0;
  this->mMaster = 0;
}

// File Line: 117
// RVA: 0x2E5B30
void __fastcall VehicleFlipTrack::~VehicleFlipTrack(VehicleFlipTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleFlipTrack::`vftable;
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

// File Line: 143
// RVA: 0x1496AF0
__int64 dynamic_initializer_for__VehicleTripRollTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleTripRollTrack", 0xFFFFFFFF);
  VehicleTripRollTrack::sClassNameUID = result;
  return result;
}

// File Line: 157
// RVA: 0x2E2AD0
void __fastcall VehicleTripRollTrack::VehicleTripRollTrack(VehicleTripRollTrack *this)
{
  ITrack::ITrack(this, VehicleTripRollTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleTripRollTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleTripRollTrack::`vftable;
  this->mTorqueImpulseFactor = 6.0;
  *(_QWORD *)&this->mLinearVelocityScale = 1065353216i64;
  this->mMaxLinearSpeedMPS = -1.0;
  this->mMaster = 0;
}

// File Line: 162
// RVA: 0x2E6200
void __fastcall VehicleTripRollTrack::~VehicleTripRollTrack(VehicleTripRollTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleTripRollTrack::`vftable;
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

// File Line: 182
// RVA: 0x1496A50
__int64 dynamic_initializer_for__VehicleSpinOutTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleSpinOutTrack", 0xFFFFFFFF);
  VehicleSpinOutTrack::sClassNameUID = result;
  return result;
}

// File Line: 200
// RVA: 0x2E2870
void __fastcall VehicleSpinOutTrack::VehicleSpinOutTrack(VehicleSpinOutTrack *this)
{
  ITrack::ITrack(this, VehicleSpinOutTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleSpinOutTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleSpinOutTrack::`vftable;
  this->mAngularVelocityScale = 1.0;
  *(_QWORD *)&this->mLinearVelocityScale = 1065353216i64;
  this->mMaxAngularSpeed = -1.0;
  this->mMinLinearSpeedMPS = 0.0;
  this->mMaxLinearSpeedMPS = -1.0;
  this->mMaster = 0;
}

// File Line: 205
// RVA: 0x2E5EB0
void __fastcall VehicleSpinOutTrack::~VehicleSpinOutTrack(VehicleSpinOutTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleSpinOutTrack::`vftable;
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

// File Line: 224
// RVA: 0x1496850
__int64 dynamic_initializer_for__VehicleAddSpeedTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleAddSpeedTrack", 0xFFFFFFFF);
  VehicleAddSpeedTrack::sClassNameUID = result;
  return result;
}

// File Line: 238
// RVA: 0x2E2320
void __fastcall VehicleAddSpeedTrack::VehicleAddSpeedTrack(VehicleAddSpeedTrack *this)
{
  ITrack::ITrack(this, VehicleAddSpeedTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleAddSpeedTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleAddSpeedTrack::`vftable;
  this->mMinSpeed = 0.0;
  this->mMaxSpeed = -1.0;
  this->mAddSpeed = 0.0;
  this->mIsSpeedBoostRewardFromVehicleTakedown = 0;
  this->mMaster = 0;
}

// File Line: 243
// RVA: 0x2E5970
void __fastcall VehicleAddSpeedTrack::~VehicleAddSpeedTrack(VehicleAddSpeedTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleAddSpeedTrack::`vftable;
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

// File Line: 267
// RVA: 0x14969F0
__int64 dynamic_initializer_for__VehicleRamTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleRamTrack", 0xFFFFFFFF);
  VehicleRamTrack::sClassNameUID = result;
  return result;
}

// File Line: 303
// RVA: 0x2E2740
void __fastcall VehicleRamTrack::VehicleRamTrack(VehicleRamTrack *this)
{
  ITrack::ITrack(this, VehicleRamTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleRamTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleRamTrack::`vftable;
  this->mMinForwardSpeedKPH = 0.0;
  *(_QWORD *)&this->mMaxForwardSpeedKPH = 1123024896i64;
  *(_QWORD *)&this->mMaxAddSpeedKPH = 1123024896i64;
  this->mForwardSpeedPenaltyPercent = 0.2;
  this->mForwardSpeedPenaltyDecelKPHPS = 60.0;
  this->mNoTargetModifier = 0.5;
  this->mCounterSwerveModifier = -0.26499999;
  this->mSwerveImpulse = 4.7750001;
  this->mTargetMaxDistance = 6.0;
  this->mTargetForwardsVelocityModifier = 4.0;
  this->mTargetAngle = 0.85000002;
  this->mMaster = 1;
}

// File Line: 308
// RVA: 0x2E5DD0
void __fastcall VehicleRamTrack::~VehicleRamTrack(VehicleRamTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleRamTrack::`vftable;
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

// File Line: 339
// RVA: 0x14969B0
__int64 dynamic_initializer_for__VehicleOverrideWheelFrictionMultiplierTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleOverrideWheelFrictionMultiplierTrack", 0xFFFFFFFF);
  VehicleOverrideWheelFrictionMultiplierTrack::sClassNameUID = result;
  return result;
}

// File Line: 349
// RVA: 0x2E26A0
void __fastcall VehicleOverrideWheelFrictionMultiplierTrack::VehicleOverrideWheelFrictionMultiplierTrack(
        VehicleOverrideWheelFrictionMultiplierTrack *this)
{
  ITrack::ITrack(this, VehicleOverrideWheelFrictionMultiplierTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleOverrideWheelFrictionMultiplierTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleOverrideWheelFrictionMultiplierTrack::`vftable;
  this->mWheelFrictionMultiplier = 1.0;
  this->mMaster = 1;
}

// File Line: 354
// RVA: 0x2E5CF0
void __fastcall VehicleOverrideWheelFrictionMultiplierTrack::~VehicleOverrideWheelFrictionMultiplierTrack(
        VehicleOverrideWheelFrictionMultiplierTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleOverrideWheelFrictionMultiplierTrack::`vftable;
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

// File Line: 368
// RVA: 0x1496A10
__int64 dynamic_initializer_for__VehicleSetCollisionShouldTriggerExplosionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleSetCollisionShouldTriggerExplosionTrack", 0xFFFFFFFF);
  VehicleSetCollisionShouldTriggerExplosionTrack::sClassNameUID = result;
  return result;
}

// File Line: 379
// RVA: 0x2E27D0
void __fastcall VehicleSetCollisionShouldTriggerExplosionTrack::VehicleSetCollisionShouldTriggerExplosionTrack(
        VehicleSetCollisionShouldTriggerExplosionTrack *this)
{
  ITrack::ITrack(this, VehicleSetCollisionShouldTriggerExplosionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleSetCollisionShouldTriggerExplosionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleSetCollisionShouldTriggerExplosionTrack::`vftable;
  *(_WORD *)&this->mBeginAction.mValue = 256;
}

// File Line: 383
// RVA: 0x2E5E40
void __fastcall VehicleSetCollisionShouldTriggerExplosionTrack::~VehicleSetCollisionShouldTriggerExplosionTrack(
        VehicleSetCollisionShouldTriggerExplosionTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleSetCollisionShouldTriggerExplosionTrack::`vftable;
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

// File Line: 397
// RVA: 0x1496950
__int64 dynamic_initializer_for__VehicleLockHighLODTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleLockHighLODTrack", 0xFFFFFFFF);
  VehicleLockHighLODTrack::sClassNameUID = result;
  return result;
}

// File Line: 405
// RVA: 0x2E25C0
void __fastcall VehicleLockHighLODTrack::VehicleLockHighLODTrack(VehicleLockHighLODTrack *this)
{
  ITrack::ITrack(this, VehicleLockHighLODTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleLockHighLODTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleLockHighLODTrack::`vftable;
  this->mMaster = 0;
}

// File Line: 410
// RVA: 0x2E5C10
void __fastcall VehicleLockHighLODTrack::~VehicleLockHighLODTrack(VehicleLockHighLODTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleLockHighLODTrack::`vftable;
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

// File Line: 425
// RVA: 0x149CA70
__int64 dynamic_initializer_for__gVLTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gVLTypeEnum, gVLTypeStrings, 2, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gVLTypeEnum__);
}

// File Line: 427
// RVA: 0x1496930
__int64 dynamic_initializer_for__VehicleLightTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleLightTrack", 0xFFFFFFFF);
  VehicleLightTrack::sClassNameUID = result;
  return result;
}

// File Line: 436
// RVA: 0x2E2570
void __fastcall VehicleLightTrack::VehicleLightTrack(VehicleLightTrack *this)
{
  ITrack::ITrack(this, VehicleLightTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleLightTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleLightTrack::`vftable;
  this->m_bStart = 0;
  this->m_Type = 0;
}

// File Line: 440
// RVA: 0x2E5BA0
void __fastcall VehicleLightTrack::~VehicleLightTrack(VehicleLightTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleLightTrack::`vftable;
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

// File Line: 454
// RVA: 0x1496AB0
__int64 dynamic_initializer_for__VehicleStopTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleStopTrack", 0xFFFFFFFF);
  VehicleStopTrack::sClassNameUID = result;
  return result;
}

// File Line: 465
// RVA: 0x2E2A40
void __fastcall VehicleStopTrack::VehicleStopTrack(VehicleStopTrack *this)
{
  ITrack::ITrack(this, VehicleStopTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleStopTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleStopTrack::`vftable;
  this->mSwerveEnabled = 1;
}

// File Line: 469
// RVA: 0x2E6120
void __fastcall VehicleStopTrack::~VehicleStopTrack(VehicleStopTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleStopTrack::`vftable;
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

// File Line: 482
// RVA: 0x1496A90
__int64 dynamic_initializer_for__VehicleSteerTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleSteerTrack", 0xFFFFFFFF);
  VehicleSteerTrack::sClassNameUID = result;
  return result;
}

// File Line: 492
// RVA: 0x2E2990
void __fastcall VehicleSteerTrack::VehicleSteerTrack(VehicleSteerTrack *this)
{
  ITrack::ITrack(this, VehicleSteerTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleSteerTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleSteerTrack::`vftable;
  this->mSteeringInput = 0.0;
}

// File Line: 496
// RVA: 0x2E6020
void __fastcall VehicleSteerTrack::~VehicleSteerTrack(VehicleSteerTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleSteerTrack::`vftable;
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

// File Line: 508
// RVA: 0x14968D0
__int64 dynamic_initializer_for__VehicleEngineAutoDeteriorateTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleEngineAutoDeteriorateTrack", 0xFFFFFFFF);
  VehicleEngineAutoDeteriorateTrack::sClassNameUID = result;
  return result;
}

// File Line: 514
// RVA: 0x2E2460
void __fastcall VehicleEngineAutoDeteriorateTrack::VehicleEngineAutoDeteriorateTrack(
        VehicleEngineAutoDeteriorateTrack *this)
{
  ITrack::ITrack(this, VehicleEngineAutoDeteriorateTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleEngineAutoDeteriorateTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleEngineAutoDeteriorateTrack::`vftable;
}

// File Line: 517
// RVA: 0x2E5AC0
void __fastcall VehicleEngineAutoDeteriorateTrack::~VehicleEngineAutoDeteriorateTrack(
        VehicleEngineAutoDeteriorateTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleEngineAutoDeteriorateTrack::`vftable;
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

// File Line: 527
// RVA: 0x1496AD0
__int64 dynamic_initializer_for__VehicleTriggerExplosionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleTriggerExplosionTrack", 0xFFFFFFFF);
  VehicleTriggerExplosionTrack::sClassNameUID = result;
  return result;
}

// File Line: 533
// RVA: 0x2E2A90
void __fastcall VehicleTriggerExplosionTrack::VehicleTriggerExplosionTrack(VehicleTriggerExplosionTrack *this)
{
  ITrack::ITrack(this, VehicleTriggerExplosionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleTriggerExplosionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleTriggerExplosionTrack::`vftable;
}

// File Line: 536
// RVA: 0x2E6190
void __fastcall VehicleTriggerExplosionTrack::~VehicleTriggerExplosionTrack(VehicleTriggerExplosionTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleTriggerExplosionTrack::`vftable;
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

// File Line: 547
// RVA: 0x1496B10
__int64 dynamic_initializer_for__VehicleTurnOnDisabledEffectTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleTurnOnDisabledEffectTrack", 0xFFFFFFFF);
  VehicleTurnOnDisabledEffectTrack::sClassNameUID = result;
  return result;
}

// File Line: 553
// RVA: 0x2E2B30
void __fastcall VehicleTurnOnDisabledEffectTrack::VehicleTurnOnDisabledEffectTrack(
        VehicleTurnOnDisabledEffectTrack *this)
{
  ITrack::ITrack(this, VehicleTurnOnDisabledEffectTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleTurnOnDisabledEffectTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleTurnOnDisabledEffectTrack::`vftable;
}

// File Line: 556
// RVA: 0x2E6270
void __fastcall VehicleTurnOnDisabledEffectTrack::~VehicleTurnOnDisabledEffectTrack(
        VehicleTurnOnDisabledEffectTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleTurnOnDisabledEffectTrack::`vftable;
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

// File Line: 566
// RVA: 0x1494D50
__int64 dynamic_initializer_for__BikePhysicsEnableConstraintTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BikePhysicsEnableConstraintTrack", 0xFFFFFFFF);
  BikePhysicsEnableConstraintTrack::sClassNameUID = result;
  return result;
}

// File Line: 578
// RVA: 0x2DE160
void __fastcall BikePhysicsEnableConstraintTrack::BikePhysicsEnableConstraintTrack(
        BikePhysicsEnableConstraintTrack *this)
{
  ITrack::ITrack(this, BikePhysicsEnableConstraintTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<BikePhysicsEnableConstraintTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&BikePhysicsEnableConstraintTrack::`vftable;
  *(_WORD *)&this->mBeginAction.mValue = 1;
}

// File Line: 582
// RVA: 0x2E35C0
void __fastcall BikePhysicsEnableConstraintTrack::~BikePhysicsEnableConstraintTrack(
        BikePhysicsEnableConstraintTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&BikePhysicsEnableConstraintTrack::`vftable;
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

// File Line: 596
// RVA: 0x14958D0
__int64 dynamic_initializer_for__MotorBikeStandUpTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MotorBikeStandUpTrack", 0xFFFFFFFF);
  MotorBikeStandUpTrack::sClassNameUID = result;
  return result;
}

// File Line: 607
// RVA: 0x14968B0
__int64 dynamic_initializer_for__VehicleDoorPhysicsTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleDoorPhysicsTrack", 0xFFFFFFFF);
  VehicleDoorPhysicsTrack::sClassNameUID = result;
  return result;
}

// File Line: 621
// RVA: 0x2E2410
void __fastcall VehicleDoorPhysicsTrack::VehicleDoorPhysicsTrack(VehicleDoorPhysicsTrack *this)
{
  ITrack::ITrack(this, VehicleDoorPhysicsTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleDoorPhysicsTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleDoorPhysicsTrack::`vftable;
  *(_WORD *)&this->m_AttachmentID.mValue = 256;
  this->m_AttachmentEndState.mValue = 1;
}

// File Line: 625
// RVA: 0x2E5A50
void __fastcall VehicleDoorPhysicsTrack::~VehicleDoorPhysicsTrack(VehicleDoorPhysicsTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleDoorPhysicsTrack::`vftable;
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

// File Line: 640
// RVA: 0x14969D0
__int64 dynamic_initializer_for__VehiclePreventWheelieTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehiclePreventWheelieTrack", 0xFFFFFFFF);
  VehiclePreventWheelieTrack::sClassNameUID = result;
  return result;
}

// File Line: 648
// RVA: 0x2E26F0
void __fastcall VehiclePreventWheelieTrack::VehiclePreventWheelieTrack(VehiclePreventWheelieTrack *this)
{
  ITrack::ITrack(this, VehiclePreventWheelieTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehiclePreventWheelieTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehiclePreventWheelieTrack::`vftable;
  this->mMaster = 0;
}

// File Line: 653
// RVA: 0x2E5D60
void __fastcall VehiclePreventWheelieTrack::~VehiclePreventWheelieTrack(VehiclePreventWheelieTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehiclePreventWheelieTrack::`vftable;
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

// File Line: 665
// RVA: 0x1496870
__int64 dynamic_initializer_for__VehicleCruiseControlTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleCruiseControlTrack", 0xFFFFFFFF);
  VehicleCruiseControlTrack::sClassNameUID = result;
  return result;
}

// File Line: 671
// RVA: 0x2E2380
void __fastcall VehicleCruiseControlTrack::VehicleCruiseControlTrack(VehicleCruiseControlTrack *this)
{
  ITrack::ITrack(this, VehicleCruiseControlTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleCruiseControlTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleCruiseControlTrack::`vftable;
}

// File Line: 675
// RVA: 0x2E59E0
void __fastcall VehicleCruiseControlTrack::~VehicleCruiseControlTrack(VehicleCruiseControlTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleCruiseControlTrack::`vftable;
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

// File Line: 687
// RVA: 0x1496970
__int64 dynamic_initializer_for__VehicleMassScaleForCollisionsTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleMassScaleForCollisionsTrack", 0xFFFFFFFF);
  VehicleMassScaleForCollisionsTrack::sClassNameUID = result;
  return result;
}

// File Line: 695
// RVA: 0x2E2610
void __fastcall VehicleMassScaleForCollisionsTrack::VehicleMassScaleForCollisionsTrack(
        VehicleMassScaleForCollisionsTrack *this)
{
  ITrack::ITrack(this, VehicleMassScaleForCollisionsTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleMassScaleForCollisionsTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleMassScaleForCollisionsTrack::`vftable;
  this->mMassScale = 4.0;
}

// File Line: 699
// RVA: 0x2E5C80
void __fastcall VehicleMassScaleForCollisionsTrack::~VehicleMassScaleForCollisionsTrack(
        VehicleMassScaleForCollisionsTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleMassScaleForCollisionsTrack::`vftable;
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

// File Line: 712
// RVA: 0x1496910
__int64 dynamic_initializer_for__VehicleInteractTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleInteractTrack", 0xFFFFFFFF);
  VehicleInteractTrack::sClassNameUID = result;
  return result;
}

// File Line: 730
// RVA: 0x2E2520
void __fastcall VehicleInteractTrack::VehicleInteractTrack(VehicleInteractTrack *this)
{
  ITrack::ITrack(this, VehicleInteractTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleInteractTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleInteractTrack::`vftable;
  *(_DWORD *)&this->m_eTargetType.mValue = 16777476;
  this->m_bDispatchNonCameraEvents = 1;
}

// File Line: 748
// RVA: 0x1496990
__int64 dynamic_initializer_for__VehicleNISModeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleNISModeTrack", 0xFFFFFFFF);
  VehicleNISModeTrack::sClassNameUID = result;
  return result;
}

// File Line: 755
// RVA: 0x2E2660
void __fastcall VehicleNISModeTrack::VehicleNISModeTrack(VehicleNISModeTrack *this)
{
  ITrack::ITrack(this, VehicleNISModeTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<VehicleNISModeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleNISModeTrack::`vftable;
}

// File Line: 766
// RVA: 0x1494B70
__int64 dynamic_initializer_for__AiDriverSteeringWobbleTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AiDriverSteeringWobbleTrack", 0xFFFFFFFF);
  AiDriverSteeringWobbleTrack::sClassNameUID = result;
  return result;
}

// File Line: 784
// RVA: 0x1494B50
__int64 dynamic_initializer_for__AiDriverSteeringLockTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AiDriverSteeringLockTrack", 0xFFFFFFFF);
  AiDriverSteeringLockTrack::sClassNameUID = result;
  return result;
}

// File Line: 803
// RVA: 0x1494B30
__int64 dynamic_initializer_for__AiDriverGasBrakeLockTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AiDriverGasBrakeLockTrack", 0xFFFFFFFF);
  AiDriverGasBrakeLockTrack::sClassNameUID = result;
  return result;
}

