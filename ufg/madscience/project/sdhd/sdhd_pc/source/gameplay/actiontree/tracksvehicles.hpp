// File Line: 29
// RVA: 0x325C50
void __fastcall VehicleSetDoorsLockedTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::VehicleSetDoorsLockedTrack", 0i64, 1u);
  if ( v0 )
    VehicleSetDoorsLockedTrack::VehicleSetDoorsLockedTrack((VehicleSetDoorsLockedTrack *)v0);
}

// File Line: 45
// RVA: 0x2C0180
__int64 __fastcall VehicleNISModeTrack::GetClassNameUID(VehicleNISModeTrack *this)
{
  return VehicleNISModeTrack::sClassNameUID;
}

// File Line: 56
// RVA: 0x29F3D0
void __fastcall VehicleDestroyTrack::~VehicleDestroyTrack(VehicleDestroyTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleDestroyTrack::`vftable;
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

// File Line: 59
// RVA: 0x2C2CB0
const char *__fastcall VehicleDestroyTrack::GetClassname(VehicleDestroyTrack *this)
{
  return VehicleDestroyTrack::sClassName;
}

// File Line: 75
// RVA: 0x2C02A0
__int64 __fastcall VehicleStateTrack::GetClassNameUID(VehicleStateTrack *this)
{
  return VehicleStateTrack::sClassNameUID;
}

// File Line: 123
// RVA: 0x325010
void __fastcall VehicleFlipTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x60ui64, "MemberMap::VehicleFlipTrack", 0i64, 1u);
  if ( v0 )
    VehicleFlipTrack::VehicleFlipTrack((VehicleFlipTrack *)v0);
}

// File Line: 164
// RVA: 0x325FC0
void __fastcall VehicleTripRollTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "MemberMap::VehicleTripRollTrack", 0i64, 1u);
  if ( v0 )
    VehicleTripRollTrack::VehicleTripRollTrack((VehicleTripRollTrack *)v0);
}

// File Line: 203
// RVA: 0x325CF0
void __fastcall VehicleSpinOutTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::VehicleSpinOutTrack", 0i64, 1u);
  if ( v0 )
    VehicleSpinOutTrack::VehicleSpinOutTrack((VehicleSpinOutTrack *)v0);
}

// File Line: 238
// RVA: 0x324610
void __fastcall VehicleAddSpeedTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "MemberMap::VehicleAddSpeedTrack", 0i64, 1u);
  if ( v0 )
    VehicleAddSpeedTrack::VehicleAddSpeedTrack((VehicleAddSpeedTrack *)v0);
}

// File Line: 289
// RVA: 0x2C0260
__int64 __fastcall VehicleRamTrack::GetClassNameUID(VehicleRamTrack *this)
{
  return VehicleRamTrack::sClassNameUID;
}

// File Line: 323
// RVA: 0x2C2ED0
const char *__fastcall VehicleOverrideWheelFrictionMultiplierTrack::GetClassname(
        VehicleOverrideWheelFrictionMultiplierTrack *this)
{
  return VehicleOverrideWheelFrictionMultiplierTrack::sClassName;
}

// File Line: 344
// RVA: 0x325C00
void __fastcall VehicleSetCollisionShouldTriggerExplosionTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x40ui64,
         "MemberMap::VehicleSetCollisionShouldTriggerExplosionTrack",
         0i64,
         1u);
  if ( v0 )
    VehicleSetCollisionShouldTriggerExplosionTrack::VehicleSetCollisionShouldTriggerExplosionTrack((VehicleSetCollisionShouldTriggerExplosionTrack *)v0);
}

// File Line: 368
// RVA: 0x325560
void __fastcall VehicleLockHighLODTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::VehicleLockHighLODTrack", 0i64, 1u);
  if ( v0 )
    VehicleLockHighLODTrack::VehicleLockHighLODTrack((VehicleLockHighLODTrack *)v0);
}

// File Line: 380
// RVA: 0x325DE0
void __fastcall VehicleStopTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::VehicleStopTrack", 0i64, 1u);
  if ( v0 )
    VehicleStopTrack::VehicleStopTrack((VehicleStopTrack *)v0);
}

// File Line: 398
// RVA: 0x2C02B0
__int64 __fastcall VehicleSteerTrack::GetClassNameUID(VehicleSteerTrack *this)
{
  return VehicleSteerTrack::sClassNameUID;
}

// File Line: 413
// RVA: 0x2C0060
__int64 __fastcall VehicleEngineAutoDeteriorateTrack::GetClassNameUID(VehicleEngineAutoDeteriorateTrack *this)
{
  return VehicleEngineAutoDeteriorateTrack::sClassNameUID;
}

// File Line: 427
// RVA: 0x325F70
void __fastcall VehicleTriggerExplosionTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x38ui64,
         "MemberMap::VehicleTriggerExplosionTrack",
         0i64,
         1u);
  if ( v0 )
    VehicleTriggerExplosionTrack::VehicleTriggerExplosionTrack((VehicleTriggerExplosionTrack *)v0);
}

// File Line: 441
// RVA: 0x326060
void __fastcall VehicleTurnOnDisabledEffectTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x38ui64,
         "MemberMap::VehicleTurnOnDisabledEffectTrack",
         0i64,
         1u);
  if ( v0 )
    VehicleTurnOnDisabledEffectTrack::VehicleTurnOnDisabledEffectTrack((VehicleTurnOnDisabledEffectTrack *)v0);
}

// File Line: 455
// RVA: 0x315BE0
void __fastcall BikePhysicsEnableConstraintTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x40ui64,
         "MemberMap::BikePhysicsEnableConstraintTrack",
         0i64,
         1u);
  if ( v0 )
    BikePhysicsEnableConstraintTrack::BikePhysicsEnableConstraintTrack((BikePhysicsEnableConstraintTrack *)v0);
}

// File Line: 477
// RVA: 0x29C650
void __fastcall MotorBikeStandUpTrack::~MotorBikeStandUpTrack(MotorBikeStandUpTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&MotorBikeStandUpTrack::`vftable;
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

// File Line: 479
// RVA: 0x2BEE70
__int64 __fastcall MotorBikeStandUpTrack::GetClassNameUID(MotorBikeStandUpTrack *this)
{
  return MotorBikeStandUpTrack::sClassNameUID;
}

// File Line: 492
// RVA: 0x324E20
void __fastcall VehicleDoorPhysicsTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::VehicleDoorPhysicsTrack", 0i64, 1u);
  if ( v0 )
    VehicleDoorPhysicsTrack::VehicleDoorPhysicsTrack((VehicleDoorPhysicsTrack *)v0);
}

// File Line: 521
// RVA: 0x325AE0
void __fastcall VehiclePreventWheelieTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::VehiclePreventWheelieTrack", 0i64, 1u);
  if ( v0 )
    VehiclePreventWheelieTrack::VehiclePreventWheelieTrack((VehiclePreventWheelieTrack *)v0);
}

// File Line: 541
// RVA: 0x2C2DF0
const char *__fastcall VehicleLightTrack::GetClassname(VehicleLightTrack *this)
{
  return VehicleLightTrack::sClassName;
}

// File Line: 556
// RVA: 0x29F4D0
void __fastcall VehicleInteractTrack::~VehicleInteractTrack(VehicleInteractTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&VehicleInteractTrack::`vftable;
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

// File Line: 558
// RVA: 0x2C2DB0
const char *__fastcall VehicleInteractTrack::GetClassname(VehicleInteractTrack *this)
{
  return VehicleInteractTrack::sClassName;
}

// File Line: 595
// RVA: 0x2BFFA0
__int64 __fastcall VehicleCruiseControlTrack::GetClassNameUID(VehicleCruiseControlTrack *this)
{
  return VehicleCruiseControlTrack::sClassNameUID;
}

// File Line: 610
// RVA: 0x2C2E10
const char *__fastcall VehicleMassScaleForCollisionsTrack::GetClassname(VehicleMassScaleForCollisionsTrack *this)
{
  return VehicleMassScaleForCollisionsTrack::sClassName;
}

// File Line: 629
// RVA: 0x2C0760
const char *__fastcall AiDriverSteeringWobbleTrack::GetClassname(AiDriverSteeringWobbleTrack *this)
{
  return AiDriverSteeringWobbleTrack::sClassName;
}

// File Line: 656
// RVA: 0x2BDAB0
__int64 __fastcall AiDriverSteeringLockTrack::GetClassNameUID(AiDriverSteeringLockTrack *this)
{
  return AiDriverSteeringLockTrack::sClassNameUID;
}

// File Line: 683
// RVA: 0x2C0740
const char *__fastcall AiDriverGasBrakeLockTrack::GetClassname(AiDriverGasBrakeLockTrack *this)
{
  return AiDriverGasBrakeLockTrack::sClassName;
}

