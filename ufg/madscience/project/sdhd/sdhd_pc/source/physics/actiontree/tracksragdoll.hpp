// File Line: 25
// RVA: 0x2BF4D0
__int64 __fastcall RagdollTrack::GetClassNameUID(RagdollTrack *this)
{
  return RagdollTrack::sClassNameUID;
}

// File Line: 61
// RVA: 0x2BF470
__int64 __fastcall RagdollCollisionTrack::GetClassNameUID(RagdollCollisionTrack *this)
{
  return RagdollCollisionTrack::sClassNameUID;
}

// File Line: 76
// RVA: 0x2C2130
const char *__fastcall RagdollImpulseTrack::GetClassname(RagdollImpulseTrack *this)
{
  return RagdollImpulseTrack::sClassName;
}

// File Line: 110
// RVA: 0x2BF3E0
__int64 __fastcall RagdollAngularImpulseTrack::GetClassNameUID(RagdollAngularImpulseTrack *this)
{
  return RagdollAngularImpulseTrack::sClassNameUID;
}

// File Line: 156
// RVA: 0x2BF4A0
__int64 __fastcall RagdollMotorTrack::GetClassNameUID(RagdollMotorTrack *this)
{
  return RagdollMotorTrack::sClassNameUID;
}

// File Line: 181
// RVA: 0x31F630
void __fastcall RagdollBlendMotorTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::RagdollBlendMotorTrack", 0i64, 1u);
  if ( v0 )
    RagdollBlendMotorTrack::RagdollBlendMotorTrack((RagdollBlendMotorTrack *)v0);
}

// File Line: 205
// RVA: 0x2BF3F0
__int64 __fastcall RagdollAquireTrack::GetClassNameUID(RagdollAquireTrack *this)
{
  return RagdollAquireTrack::sClassNameUID;
}

// File Line: 243
// RVA: 0x31F9F0
void __fastcall RagdollReleaseTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::RagdollReleaseTrack", 0i64, 1u);
  if ( v0 )
    RagdollReleaseTrack::RagdollReleaseTrack((RagdollReleaseTrack *)v0);
}

// File Line: 261
// RVA: 0x2BF430
__int64 __fastcall RagdollChangeModeTrack::GetClassNameUID(RagdollChangeModeTrack *this)
{
  return RagdollChangeModeTrack::sClassNameUID;
}

// File Line: 280
// RVA: 0x31FA40
void __fastcall RagdollSetFrictionTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::RagdollSetFrictionTrack", 0i64, 1u);
  if ( v0 )
    RagdollSetFrictionTrack::RagdollSetFrictionTrack((RagdollSetFrictionTrack *)v0);
}

// File Line: 299
// RVA: 0x2C2070
const char *__fastcall RagdollAdjustMassTrack::GetClassname(RagdollAdjustMassTrack *this)
{
  return RagdollAdjustMassTrack::sClassName;
}

// File Line: 318
// RVA: 0x2C20E0
const char *__fastcall RagdollChangeMotorTrack::GetClassname(RagdollChangeMotorTrack *this)
{
  return RagdollChangeMotorTrack::sClassName;
}

// File Line: 337
// RVA: 0x2BF420
__int64 __fastcall RagdollChangeBlendWeightTrack::GetClassNameUID(RagdollChangeBlendWeightTrack *this)
{
  return RagdollChangeBlendWeightTrack::sClassNameUID;
}

// File Line: 356
// RVA: 0x31F810
void __fastcall RagdollChangeVelocityTrackingStrTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x40ui64,
         "MemberMap::RagdollChangeVelocityTrackingStrTrack",
         0i64,
         1u);
  if ( v0 )
    RagdollChangeVelocityTrackingStrTrack::RagdollChangeVelocityTrackingStrTrack((RagdollChangeVelocityTrackingStrTrack *)v0);
}

// File Line: 381
// RVA: 0x2C20F0
const char *__fastcall RagdollChangeVelocityTrackingParamsRawTrack::GetClassname(RagdollChangeVelocityTrackingParamsRawTrack *this)
{
  return RagdollChangeVelocityTrackingParamsRawTrack::sClassName;
}

// File Line: 417
// RVA: 0x2BF410
__int64 __fastcall RagdollChangeAngularLimitStrTrack::GetClassNameUID(RagdollChangeAngularLimitStrTrack *this)
{
  return RagdollChangeAngularLimitStrTrack::sClassNameUID;
}

// File Line: 437
// RVA: 0x31F8B0
void __fastcall RagdollDeathImpulseTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::RagdollDeathImpulseTrack", 0i64, 1u);
  if ( v0 )
    RagdollDeathImpulseTrack::RagdollDeathImpulseTrack((RagdollDeathImpulseTrack *)v0);
}

