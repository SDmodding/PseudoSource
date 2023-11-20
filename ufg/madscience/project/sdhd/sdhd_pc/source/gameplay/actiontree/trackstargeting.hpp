// File Line: 26
// RVA: 0x29E8A0
void __fastcall TargetJumpTrack::~TargetJumpTrack(TargetJumpTrack *this)
{
  TargetJumpTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetJumpTrack::`vftable;
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
  TargetPlayEffectTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetPlayEffectTrack::`vftable;
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
  TargetDamageTrack *v1; // rdi

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetDamageTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetDamageTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetDamageTrack::`vftable;
  v1->mDamage.text.mOffset = 1i64;
  BinString::Set(&v1->mDamage.text, &customWorldMapCaption);
  v1->mDamage.expression.mOffset = 0i64;
  v1->mDamage.value = 0;
  v1->mTargetType = 0;
}

// File Line: 137
// RVA: 0x29E580
void __fastcall TargetDamageTrack::~TargetDamageTrack(TargetDamageTrack *this)
{
  TargetDamageTrack *v1; // rbx
  ExpressionParameterInt *v2; // rcx
  char *v3; // rcx
  ExpressionParameterFloat *v4; // rcx
  char *v5; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetDamageTrack::`vftable;
  v2 = &this->mDamage;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v4 = &v1->mMasterRate;
  if ( !(~LOBYTE(v1->mMasterRate.text.mOffset) & 1) )
  {
    if ( v4->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v5 = (char *)v4 + (v4->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v5 != BinString::sEmptyString )
        operator delete[](v5);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  TargetPlayTrack *v1; // rdi
  TargetPlayHoldTrack *v2; // rbx

  v1 = this;
  NodeRefTrack<TargetPlayTask>::NodeRefTrack<TargetPlayTask>(
    (NodeRefTrack<TargetPlayTask> *)&this->vfptr,
    TargetPlayTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetPlayTrack::`vftable;
  v2 = &v1->mHoldTrack;
  ITrack::ITrack((ITrack *)&v1->mHoldTrack.vfptr, TargetPlayHoldTrack::sClassNameUID);
  v2->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPlayHoldTask>::`vftable;
  v2->vfptr = (Expression::IMemberMapVtbl *)&TargetPlayHoldTrack::`vftable;
  v1->mHoldTrack.mMaster = 1;
  v1->mTargetType = 0;
  *(_DWORD *)&v1->mPlayTracksOnly = 16843008;
  v1->mBeginEndTimesOffsetPlayTime = 0;
}

// File Line: 180
// RVA: 0x298A70
void __fastcall TargetPlayTrack::TargetPlayTrack(TargetPlayTrack *this, MemImageLoadFlag flag)
{
  TargetPlayTrack *v2; // rdi
  TargetPlayHoldTrack *v3; // rbx
  unsigned int flaga; // [rsp+48h] [rbp+10h]

  flaga = flag.flag;
  v2 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, flag);
  v2->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPlayTask>::`vftable;
  v2->vfptr = (Expression::IMemberMapVtbl *)&NodeRefTrack<TargetPlayTask>::`vftable;
  v2->vfptr = (Expression::IMemberMapVtbl *)&TargetPlayTrack::`vftable;
  v3 = &v2->mHoldTrack;
  ITrack::ITrack((ITrack *)&v2->mHoldTrack.vfptr, (MemImageLoadFlag)flaga);
  v3->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetPlayHoldTask>::`vftable;
  v3->vfptr = (Expression::IMemberMapVtbl *)&TargetPlayHoldTrack::`vftable;
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
  TargetSpawnTrack *v2; // rdi
  SpawnTrack *v3; // rbx
  unsigned int flaga; // [rsp+48h] [rbp+10h]

  flaga = flag.flag;
  v2 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, flag);
  v2->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetSpawnTask>::`vftable;
  v2->vfptr = (Expression::IMemberMapVtbl *)&TargetSpawnTrack::`vftable;
  v3 = &v2->m_SpawnTrack;
  ITrack::ITrack((ITrack *)&v2->m_SpawnTrack.vfptr, (MemImageLoadFlag)flaga);
  v3->vfptr = (Expression::IMemberMapVtbl *)&Track<SpawnTask>::`vftable;
  v3->vfptr = (Expression::IMemberMapVtbl *)&NodeRefTrack<SpawnTask>::`vftable;
  v3->vfptr = (Expression::IMemberMapVtbl *)&SpawnTrack::`vftable;
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
  TargetSteerToTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetSteerToTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetSteerToTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetSteerToTrack::`vftable;
  v1->mSteerRate = 9.424778;
  *(_QWORD *)&v1->mTargetMaxSteerDistance = 0x40000000i64;
  v1->mTargetAttachment.mUID = -1;
  *(_DWORD *)&v1->m_bSteerWithNoTarget = 0x1000000;
  v1->mTargetType = 0;
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
const char *__fastcall TargetAssignMyTargetToTargetsTargetTrack::GetClassname(TargetAssignMyTargetToTargetsTargetTrack *this)
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
  TargetWeaponAmmoConsumeTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetWeaponAmmoConsumeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetWeaponAmmoConsumeTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetWeaponAmmoConsumeTrack::`vftable;
  v1->m_iTargetType = 0;
  *(_WORD *)&v1->m_bDestroyTarget = 0;
  UFG::qSymbolUC::create_from_string(&v1->mVictimDetachJointName, "none");
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
  TargetVehicleBreakWindowTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetVehicleBreakWindowTrack::`vftable;
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
  TargetFocusOverrideTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetFocusOverrideTrack::`vftable;
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
  TargetHitReactionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetHitReactionTrack::`vftable;
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
  TargetWeaponModeChangeTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetWeaponModeChangeTrack::`vftable;
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
  TargetAssignSubTargetTrack *v1; // rbx
  char *v2; // rcx
  ExpressionParameterFloat *v3; // rcx
  char *v4; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetAssignSubTargetTrack::`vftable;
  if ( !(~LOBYTE(this->m_SubTargetName.mOffset) & 1) )
  {
    if ( this->m_SubTargetName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v2 = (char *)&this->m_SubTargetName + (this->m_SubTargetName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v2 != BinString::sEmptyString )
        operator delete[](v2);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  v3 = &v1->mMasterRate;
  if ( !(~LOBYTE(v1->mMasterRate.text.mOffset) & 1) )
  {
    if ( v3->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v4 = (char *)v3 + (v3->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v4 != BinString::sEmptyString )
        operator delete[](v4);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  TargetingProfileSelectTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetingProfileSelectTrack::`vftable;
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

