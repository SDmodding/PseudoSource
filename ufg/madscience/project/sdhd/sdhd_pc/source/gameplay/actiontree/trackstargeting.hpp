// File Line: 26
// RVA: 0x29E8A0
void __fastcall TargetJumpTrack::~TargetJumpTrack(TargetJumpTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TargetJumpTrack::`vftable;
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

// File Line: 28
// RVA: 0x2C27B0
const char *__fastcall TargetJumpTrack::GetClassname(TargetJumpTrack *this)
{
  return TargetJumpTrack::sClassName;
}

// File Line: 72
// RVA: 0x29E910
void __fastcall TargetPlayEffectTrack::~TargetPlayEffectTrack(TargetPlayEffectTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPlayEffectTrack::`vftable;
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

// File Line: 74
// RVA: 0x322CD0
void __fastcall TargetPlayEffectTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xA8ui64, "MemberMap::TargetPlayEffectTrack", 0i64, 1u);
  if ( v0 )
    TargetPlayEffectTrack::TargetPlayEffectTrack((TargetPlayEffectTrack *)v0);
}

// File Line: 132
// RVA: 0x313960
void __fastcall TargetDamageTrack::TargetDamageTrack(TargetDamageTrack *this)
{
  ITrack::ITrack(this, TargetDamageTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetDamageTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetDamageTrack::`vftable;
  this->mDamage.text.mOffset = 1i64;
  BinString::Set(&this->mDamage.text, &customCaption);
  this->mDamage.expression.mOffset = 0i64;
  this->mDamage.value = 0;
  this->mTargetType = 0;
}

// File Line: 137
// RVA: 0x29E580
void __fastcall TargetDamageTrack::~TargetDamageTrack(TargetDamageTrack *this)
{
  ExpressionParameterInt *p_mDamage; // rcx
  char *v3; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v5; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TargetDamageTrack::`vftable;
  p_mDamage = &this->mDamage;
  if ( (p_mDamage->text.mOffset & 1) != 0 && (p_mDamage->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mDamage + (p_mDamage->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (this->mMasterRate.text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v5 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v5 != BinString::sEmptyString )
      operator delete[](v5);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 139
// RVA: 0x2BF9D0
__int64 __fastcall TargetDamageTrack::GetClassNameUID(TargetDamageTrack *this)
{
  return TargetDamageTrack::sClassNameUID;
}

// File Line: 160
// RVA: 0x2C2880
const char *__fastcall TargetPlayHoldTrack::GetClassname(TargetPlayHoldTrack *this)
{
  return TargetPlayHoldTrack::sClassName;
}

// File Line: 177
// RVA: 0x2E1E00
void __fastcall TargetPlayTrack::TargetPlayTrack(TargetPlayTrack *this)
{
  NodeRefTrack<TargetPlayTask>::NodeRefTrack<TargetPlayTask>(this, TargetPlayTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPlayTrack::`vftable;
  ITrack::ITrack(&this->mHoldTrack, TargetPlayHoldTrack::sClassNameUID);
  this->mHoldTrack.vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPlayHoldTask>::`vftable;
  this->mHoldTrack.vfptr = (Expression::IMemberMapVtbl *)&TargetPlayHoldTrack::`vftable;
  this->mHoldTrack.mMaster = 1;
  this->mTargetType = 0;
  *(_DWORD *)&this->mPlayTracksOnly = 16843008;
  this->mBeginEndTimesOffsetPlayTime = 0;
}

// File Line: 180
// RVA: 0x298A70
void __fastcall TargetPlayTrack::TargetPlayTrack(TargetPlayTrack *this, MemImageLoadFlag flag)
{
  ITrack::ITrack(this, flag);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPlayTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRefTrack<TargetPlayTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPlayTrack::`vftable;
  ITrack::ITrack(&this->mHoldTrack, flag);
  this->mHoldTrack.vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPlayHoldTask>::`vftable;
  this->mHoldTrack.vfptr = (Expression::IMemberMapVtbl *)&TargetPlayHoldTrack::`vftable;
}

// File Line: 182
// RVA: 0x2C2890
const char *__fastcall TargetPlayTrack::GetClassname(TargetPlayTrack *this)
{
  return TargetPlayTrack::sClassName;
}

// File Line: 247
// RVA: 0x2C2860
const char *__fastcall TargetPlayAITrack::GetClassname(TargetPlayAITrack *this)
{
  return TargetPlayAITrack::sClassName;
}

// File Line: 278
// RVA: 0x298AF0
void __fastcall TargetSpawnTrack::TargetSpawnTrack(TargetSpawnTrack *this, MemImageLoadFlag flag)
{
  ITrack::ITrack(this, flag);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetSpawnTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSpawnTrack::`vftable;
  ITrack::ITrack(&this->m_SpawnTrack, flag);
  this->m_SpawnTrack.vfptr = (Expression::IMemberMapVtbl *)&Track<SpawnTask>::`vftable;
  this->m_SpawnTrack.vfptr = (Expression::IMemberMapVtbl *)&NodeRefTrack<SpawnTask>::`vftable;
  this->m_SpawnTrack.vfptr = (Expression::IMemberMapVtbl *)&SpawnTrack::`vftable;
}

// File Line: 280
// RVA: 0x2BFC80
__int64 __fastcall TargetSpawnTrack::GetClassNameUID(TargetSpawnTrack *this)
{
  return TargetSpawnTrack::sClassNameUID;
}

// File Line: 322
// RVA: 0x2BFA80
__int64 __fastcall TargetGrappleReleaseTrack::GetClassNameUID(TargetGrappleReleaseTrack *this)
{
  return TargetGrappleReleaseTrack::sClassNameUID;
}

// File Line: 336
// RVA: 0x2C27E0
const char *__fastcall TargetLockTrack::GetClassname(TargetLockTrack *this)
{
  return TargetLockTrack::sClassName;
}

// File Line: 361
// RVA: 0x323240
TargetReleaseTrack *__fastcall TargetReleaseTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::TargetReleaseTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, TargetReleaseTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<TargetReleaseTask>::`vftable;
  *(_QWORD *)v1 = &TargetReleaseTrack::`vftable;
  *((_DWORD *)v1 + 14) = 0;
  *((_WORD *)v1 + 30) = 1;
  v1[62] = 1;
  return (TargetReleaseTrack *)v1;
}

// File Line: 398
// RVA: 0x3139E0
void __fastcall TargetSteerToTrack::TargetSteerToTrack(TargetSteerToTrack *this)
{
  ITrack::ITrack(this, TargetSteerToTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetSteerToTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetSteerToTrack::`vftable;
  this->mSteerRate = 9.424778;
  *(_QWORD *)&this->mTargetMaxSteerDistance = 0x40000000i64;
  this->mTargetAttachment.mUID = -1;
  *(_DWORD *)&this->m_bSteerWithNoTarget = 0x1000000;
  this->mTargetType = 0;
}

// File Line: 405
// RVA: 0x2C2940
const char *__fastcall TargetSteerToTrack::GetClassname(TargetSteerToTrack *this)
{
  return TargetSteerToTrack::sClassName;
}

// File Line: 458
// RVA: 0x3237F0
void __fastcall TargetSyncPositionTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::TargetSyncPositionTrack", 0i64, 1u);
  if ( v0 )
    TargetSyncPositionTrack::TargetSyncPositionTrack((TargetSyncPositionTrack *)v0);
}

// File Line: 508
// RVA: 0x2C2640
const char *__fastcall TargetAttachTrack::GetClassname(TargetAttachTrack *this)
{
  return TargetAttachTrack::sClassName;
}

// File Line: 578
// RVA: 0x2C26C0
const char *__fastcall TargetDetachTrack::GetClassname(TargetDetachTrack *this)
{
  return TargetDetachTrack::sClassName;
}

// File Line: 651
// RVA: 0x321A10
void __fastcall TargetAttachEffectorTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::TargetAttachEffectorTrack", 0i64, 1u);
  if ( v0 )
    TargetAttachEffectorTrack::TargetAttachEffectorTrack((TargetAttachEffectorTrack *)v0);
}

// File Line: 701
// RVA: 0x321D60
void __fastcall TargetDetachEffectorTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::TargetDetachEffectorTrack", 0i64, 1u);
  if ( v0 )
    TargetDetachEffectorTrack::TargetDetachEffectorTrack((TargetDetachEffectorTrack *)v0);
}

// File Line: 748
// RVA: 0x2BF980
__int64 __fastcall TargetAttachEXTrack::GetClassNameUID(TargetAttachEXTrack *this)
{
  return TargetAttachEXTrack::sClassNameUID;
}

// File Line: 824
// RVA: 0x2BFA00
__int64 __fastcall TargetDetachEXTrack::GetClassNameUID(TargetDetachEXTrack *this)
{
  return TargetDetachEXTrack::sClassNameUID;
}

// File Line: 902
// RVA: 0x2BFC90
__int64 __fastcall TargetStealAttachedItemTrack::GetClassNameUID(TargetStealAttachedItemTrack *this)
{
  return TargetStealAttachedItemTrack::sClassNameUID;
}

// File Line: 960
// RVA: 0x2BFC00
__int64 __fastcall TargetPropInteractTrack::GetClassNameUID(TargetPropInteractTrack *this)
{
  return TargetPropInteractTrack::sClassNameUID;
}

// File Line: 976
// RVA: 0x2BF960
__int64 __fastcall TargetAssignTrack::GetClassNameUID(TargetAssignTrack *this)
{
  return TargetAssignTrack::sClassNameUID;
}

// File Line: 1012
// RVA: 0x3218D0
void __fastcall TargetAssignTargetsTargetToMyTargetTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x48ui64,
         "MemberMap::TargetAssignTargetsTargetToMyTargetTrack",
         0i64,
         1u);
  if ( v0 )
    TargetAssignTargetsTargetToMyTargetTrack::TargetAssignTargetsTargetToMyTargetTrack((TargetAssignTargetsTargetToMyTargetTrack *)v0);
}

// File Line: 1049
// RVA: 0x2C25D0
const char *__fastcall TargetAssignMyTargetToTargetsTargetTrack::GetClassname(
        TargetAssignMyTargetToTargetsTargetTrack *this)
{
  return TargetAssignMyTargetToTargetsTargetTrack::sClassName;
}

// File Line: 1081
// RVA: 0x2BF9E0
__int64 __fastcall TargetDestroyTrack::GetClassNameUID(TargetDestroyTrack *this)
{
  return TargetDestroyTrack::sClassNameUID;
}

// File Line: 1099
// RVA: 0x313A40
void __fastcall TargetWeaponAmmoConsumeTrack::TargetWeaponAmmoConsumeTrack(TargetWeaponAmmoConsumeTrack *this)
{
  ITrack::ITrack(this, TargetWeaponAmmoConsumeTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetWeaponAmmoConsumeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetWeaponAmmoConsumeTrack::`vftable;
  this->m_iTargetType = 0;
  *(_WORD *)&this->m_bDestroyTarget = 0;
  UFG::qSymbolUC::create_from_string(&this->mVictimDetachJointName, "none");
}

// File Line: 1102
// RVA: 0x2C29D0
const char *__fastcall TargetWeaponAmmoConsumeTrack::GetClassname(TargetWeaponAmmoConsumeTrack *this)
{
  return TargetWeaponAmmoConsumeTrack::sClassName;
}

// File Line: 1138
// RVA: 0x2BF920
__int64 __fastcall TargetAddToInventoryTrack::GetClassNameUID(TargetAddToInventoryTrack *this)
{
  return TargetAddToInventoryTrack::sClassNameUID;
}

// File Line: 1158
// RVA: 0x2C2910
const char *__fastcall TargetRemoveFromInventoryTrack::GetClassname(TargetRemoveFromInventoryTrack *this)
{
  return TargetRemoveFromInventoryTrack::sClassName;
}

// File Line: 1178
// RVA: 0x3230E0
TargetPurchaseItemTrack *__fastcall TargetPurchaseItemTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::TargetPurchaseItemTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, TargetPurchaseItemTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<TargetPurchaseItemTask>::`vftable;
  *(_QWORD *)v1 = &TargetPurchaseItemTrack::`vftable;
  *((_DWORD *)v1 + 14) = 0;
  return (TargetPurchaseItemTrack *)v1;
}

// File Line: 1201
// RVA: 0x29EBF0
void __fastcall TargetVehicleBreakWindowTrack::~TargetVehicleBreakWindowTrack(TargetVehicleBreakWindowTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TargetVehicleBreakWindowTrack::`vftable;
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

// File Line: 1203
// RVA: 0x2C2960
const char *__fastcall TargetVehicleBreakWindowTrack::GetClassname(TargetVehicleBreakWindowTrack *this)
{
  return TargetVehicleBreakWindowTrack::sClassName;
}

// File Line: 1228
// RVA: 0x29E620
void __fastcall TargetFocusOverrideTrack::~TargetFocusOverrideTrack(TargetFocusOverrideTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TargetFocusOverrideTrack::`vftable;
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

// File Line: 1230
// RVA: 0x2C26F0
const char *__fastcall TargetFocusOverrideTrack::GetClassname(TargetFocusOverrideTrack *this)
{
  return TargetFocusOverrideTrack::sClassName;
}

// File Line: 1252
// RVA: 0x29E720
void __fastcall TargetHitReactionTrack::~TargetHitReactionTrack(TargetHitReactionTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TargetHitReactionTrack::`vftable;
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

// File Line: 1254
// RVA: 0x2BFAA0
__int64 __fastcall TargetHitReactionTrack::GetClassNameUID(TargetHitReactionTrack *this)
{
  return TargetHitReactionTrack::sClassNameUID;
}

// File Line: 1278
// RVA: 0x2C2610
const char *__fastcall TargetAttachConstraintTrack::GetClassname(TargetAttachConstraintTrack *this)
{
  return TargetAttachConstraintTrack::sClassName;
}

// File Line: 1338
// RVA: 0x2C2690
const char *__fastcall TargetDetachConstraintTrack::GetClassname(TargetDetachConstraintTrack *this)
{
  return TargetDetachConstraintTrack::sClassName;
}

// File Line: 1427
// RVA: 0x321F90
void __fastcall TargetFractureTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x58ui64, "MemberMap::TargetFractureTrack", 0i64, 1u);
  if ( v0 )
    TargetFractureTrack::TargetFractureTrack((TargetFractureTrack *)v0);
}

// File Line: 1454
// RVA: 0x2C2700
const char *__fastcall TargetFractureStrengthTrack::GetClassname(TargetFractureStrengthTrack *this)
{
  return TargetFractureStrengthTrack::sClassName;
}

// File Line: 1469
// RVA: 0x29EC60
void __fastcall TargetWeaponModeChangeTrack::~TargetWeaponModeChangeTrack(TargetWeaponModeChangeTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TargetWeaponModeChangeTrack::`vftable;
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

// File Line: 1471
// RVA: 0x323C00
void __fastcall TargetWeaponModeChangeTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::TargetWeaponModeChangeTrack", 0i64, 1u);
  if ( v0 )
    TargetWeaponModeChangeTrack::TargetWeaponModeChangeTrack((TargetWeaponModeChangeTrack *)v0);
}

// File Line: 1489
// RVA: 0x29E4E0
void __fastcall TargetAssignSubTargetTrack::~TargetAssignSubTargetTrack(TargetAssignSubTargetTrack *this)
{
  char *v2; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v4; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAssignSubTargetTrack::`vftable;
  if ( (this->m_SubTargetName.mOffset & 1) != 0 && (this->m_SubTargetName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v2 = (char *)&this->m_SubTargetName + (this->m_SubTargetName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v2 != BinString::sEmptyString )
      operator delete[](v2);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (this->mMasterRate.text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v4 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v4 != BinString::sEmptyString )
      operator delete[](v4);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 1491
// RVA: 0x321880
void __fastcall TargetAssignSubTargetTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::TargetAssignSubTargetTrack", 0i64, 1u);
  if ( v0 )
    TargetAssignSubTargetTrack::TargetAssignSubTargetTrack((TargetAssignSubTargetTrack *)v0);
}

// File Line: 1528
// RVA: 0x29ECD0
void __fastcall TargetingProfileSelectTrack::~TargetingProfileSelectTrack(TargetingProfileSelectTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TargetingProfileSelectTrack::`vftable;
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

// File Line: 1530
// RVA: 0x2C2A00
const char *__fastcall TargetingProfileSelectTrack::GetClassname(TargetingProfileSelectTrack *this)
{
  return TargetingProfileSelectTrack::sClassName;
}

// File Line: 1554
// RVA: 0x2BFBA0
__int64 __fastcall TargetPhysicalDamageTrack::GetClassNameUID(TargetPhysicalDamageTrack *this)
{
  return TargetPhysicalDamageTrack::sClassNameUID;
}

// File Line: 1584
// RVA: 0x2C2730
const char *__fastcall TargetGunSetAmmoForAIDeathTrack::GetClassname(TargetGunSetAmmoForAIDeathTrack *this)
{
  return TargetGunSetAmmoForAIDeathTrack::sClassName;
}

// File Line: 1603
// RVA: 0x322990
void __fastcall TargetPhysicalAttackTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::TargetPhysicalAttackTrack", 0i64, 1u);
  if ( v0 )
    TargetPhysicalAttackTrack::TargetPhysicalAttackTrack((TargetPhysicalAttackTrack *)v0);
}

// File Line: 1639
// RVA: 0x2BFBB0
__int64 __fastcall TargetPhysicalImpulseTrack::GetClassNameUID(TargetPhysicalImpulseTrack *this)
{
  return TargetPhysicalImpulseTrack::sClassNameUID;
}

// File Line: 1687
// RVA: 0x2BF9B0
__int64 __fastcall TargetAttackRightsTrack::GetClassNameUID(TargetAttackRightsTrack *this)
{
  return TargetAttackRightsTrack::sClassNameUID;
}

// File Line: 1714
// RVA: 0x2BFB30
__int64 __fastcall TargetLatchParkourHandleTrack::GetClassNameUID(TargetLatchParkourHandleTrack *this)
{
  return TargetLatchParkourHandleTrack::sClassNameUID;
}

// File Line: 1735
// RVA: 0x31F430
void __fastcall ProxyTargetSphereCastTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x70ui64, "MemberMap::ProxyTargetSphereCastTrack", 0i64, 1u);
  if ( v0 )
    ProxyTargetSphereCastTrack::ProxyTargetSphereCastTrack((ProxyTargetSphereCastTrack *)v0);
}

