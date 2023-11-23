// File Line: 39
// RVA: 0x31CB90
void __fastcall LocomotionTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::LocomotionTrack", 0i64, 1u);
  if ( v0 )
    LocomotionTrack::LocomotionTrack((LocomotionTrack *)v0);
}

// File Line: 66
// RVA: 0x2BED40
__int64 __fastcall Locomotion2Track::GetClassNameUID(Locomotion2Track *this)
{
  return Locomotion2Track::sClassNameUID;
}

// File Line: 107
// RVA: 0x2BED50
__int64 __fastcall LocomotionParamTrack::GetClassNameUID(LocomotionParamTrack *this)
{
  return LocomotionParamTrack::sClassNameUID;
}

// File Line: 137
// RVA: 0x29C1C0
void __fastcall JumpTrack::~JumpTrack(JumpTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&JumpTrack::`vftable;
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

// File Line: 139
// RVA: 0x2BECE0
__int64 __fastcall JumpTrack::GetClassNameUID(JumpTrack *this)
{
  return JumpTrack::sClassNameUID;
}

// File Line: 171
// RVA: 0x29EE00
void __fastcall TimeWarpTrack::~TimeWarpTrack(TimeWarpTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TimeWarpTrack::`vftable;
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

// File Line: 173
// RVA: 0x2BFDC0
__int64 __fastcall TimeWarpTrack::GetClassNameUID(TimeWarpTrack *this)
{
  return TimeWarpTrack::sClassNameUID;
}

// File Line: 218
// RVA: 0x313720
void __fastcall DamageTrack::DamageTrack(DamageTrack *this)
{
  ITrack::ITrack(this, DamageTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<DamageTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&DamageTrack::`vftable;
  this->mDamage.text.mOffset = 1i64;
  BinString::Set(&this->mDamage.text, &customCaption);
  this->mDamage.expression.mOffset = 0i64;
  this->mDamage.value = 0;
  this->mTargetType = 0;
}

// File Line: 223
// RVA: 0x29B350
void __fastcall DamageTrack::~DamageTrack(DamageTrack *this)
{
  ExpressionParameterInt *p_mDamage; // rcx
  char *v3; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v5; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DamageTrack::`vftable;
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

// File Line: 225
// RVA: 0x2BE350
__int64 __fastcall DamageTrack::GetClassNameUID(DamageTrack *this)
{
  return DamageTrack::sClassNameUID;
}

// File Line: 249
// RVA: 0x29BD50
void __fastcall HandleDamageTrack::~HandleDamageTrack(HandleDamageTrack *this)
{
  ExpressionParameterInt *p_mDamageMultiplyer; // rcx
  char *v3; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v5; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&HandleDamageTrack::`vftable;
  p_mDamageMultiplyer = &this->mDamageMultiplyer;
  if ( (p_mDamageMultiplyer->text.mOffset & 1) != 0 && (p_mDamageMultiplyer->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mDamageMultiplyer + (p_mDamageMultiplyer->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
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

// File Line: 251
// RVA: 0x2BE7D0
__int64 __fastcall HandleDamageTrack::GetClassNameUID(HandleDamageTrack *this)
{
  return HandleDamageTrack::sClassNameUID;
}

// File Line: 272
// RVA: 0x29BDF0
void __fastcall HealthSetPercentageTrack::~HealthSetPercentageTrack(HealthSetPercentageTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&HealthSetPercentageTrack::`vftable;
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

// File Line: 274
// RVA: 0x2C1580
const char *__fastcall HealthSetPercentageTrack::GetClassname(HealthSetPercentageTrack *this)
{
  return HealthSetPercentageTrack::sClassName;
}

// File Line: 292
// RVA: 0x29CB40
void __fastcall ObjectReferenceTrack::~ObjectReferenceTrack(ObjectReferenceTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&ObjectReferenceTrack::`vftable;
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

// File Line: 294
// RVA: 0x31DA20
void __fastcall ObjectReferenceTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::ObjectReferenceTrack", 0i64, 1u);
  if ( v0 )
    ObjectReferenceTrack::ObjectReferenceTrack((ObjectReferenceTrack *)v0);
}

// File Line: 314
// RVA: 0x29CAD0
void __fastcall ObjectCreateTrack::~ObjectCreateTrack(ObjectCreateTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&ObjectCreateTrack::`vftable;
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

// File Line: 316
// RVA: 0x2BEF80
__int64 __fastcall ObjectCreateTrack::GetClassNameUID(ObjectCreateTrack *this)
{
  return ObjectCreateTrack::sClassNameUID;
}

// File Line: 336
// RVA: 0x29CA60
void __fastcall ObjectCreateFromPropertiesTrack::~ObjectCreateFromPropertiesTrack(
        ObjectCreateFromPropertiesTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&ObjectCreateFromPropertiesTrack::`vftable;
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

// File Line: 338
// RVA: 0x2C1C10
const char *__fastcall ObjectCreateFromPropertiesTrack::GetClassname(ObjectCreateFromPropertiesTrack *this)
{
  return ObjectCreateFromPropertiesTrack::sClassName;
}

// File Line: 370
// RVA: 0x29BE60
void __fastcall HideTrack::~HideTrack(HideTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&HideTrack::`vftable;
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

// File Line: 372
// RVA: 0x2C1590
const char *__fastcall HideTrack::GetClassname(HideTrack *this)
{
  return HideTrack::sClassName;
}

// File Line: 384
// RVA: 0x29F130
void __fastcall UnhideTrack::~UnhideTrack(UnhideTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&UnhideTrack::`vftable;
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

// File Line: 386
// RVA: 0x3242A0
void __fastcall UnhideTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::UnhideTrack", 0i64, 1u);
  if ( v0 )
    UnhideTrack::UnhideTrack((UnhideTrack *)v0);
}

// File Line: 404
// RVA: 0x29BFE0
void __fastcall InputSignalFilterTrack::~InputSignalFilterTrack(InputSignalFilterTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&InputSignalFilterTrack::`vftable;
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

// File Line: 406
// RVA: 0x2BE980
__int64 __fastcall InputSignalFilterTrack::GetClassNameUID(InputSignalFilterTrack *this)
{
  return InputSignalFilterTrack::sClassNameUID;
}

// File Line: 477
// RVA: 0x29C050
void __fastcall InputSignalLerpFilterTrack::~InputSignalLerpFilterTrack(InputSignalLerpFilterTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&InputSignalLerpFilterTrack::`vftable;
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
// RVA: 0x2BE990
__int64 __fastcall InputSignalLerpFilterTrack::GetClassNameUID(InputSignalLerpFilterTrack *this)
{
  return InputSignalLerpFilterTrack::sClassNameUID;
}

// File Line: 541
// RVA: 0x29BF70
void __fastcall InputEnableMappingTrack::~InputEnableMappingTrack(InputEnableMappingTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&InputEnableMappingTrack::`vftable;
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

// File Line: 543
// RVA: 0x2C1610
const char *__fastcall InputEnableMappingTrack::GetClassname(InputEnableMappingTrack *this)
{
  return InputEnableMappingTrack::sClassName;
}

// File Line: 572
// RVA: 0x29D720
void __fastcall ReadControllerInputTrack::~ReadControllerInputTrack(ReadControllerInputTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&ReadControllerInputTrack::`vftable;
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

// File Line: 574
// RVA: 0x2C2190
const char *__fastcall ReadControllerInputTrack::GetClassname(ReadControllerInputTrack *this)
{
  return ReadControllerInputTrack::sClassName;
}

// File Line: 593
// RVA: 0x31A440
void __fastcall HealthRegenRateTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::HealthRegenRateTrack", 0i64, 1u);
  if ( v0 )
    HealthRegenRateTrack::HealthRegenRateTrack((HealthRegenRateTrack *)v0);
}

// File Line: 618
// RVA: 0x31A490
void __fastcall HealthRegenerateTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::HealthRegenerateTrack", 0i64, 1u);
  if ( v0 )
    HealthRegenerateTrack::HealthRegenerateTrack((HealthRegenerateTrack *)v0);
}

// File Line: 643
// RVA: 0x2C1570
const char *__fastcall HealthReplenishInstantTrack::GetClassname(HealthReplenishInstantTrack *this)
{
  return HealthReplenishInstantTrack::sClassName;
}

// File Line: 664
// RVA: 0x2C2510
const char *__fastcall StimulusTrack::GetClassname(StimulusTrack *this)
{
  return StimulusTrack::sClassName;
}

// File Line: 714
// RVA: 0x2C2370
const char *__fastcall SetOpeningBranchTrack::GetClassname(SetOpeningBranchTrack *this)
{
  return SetOpeningBranchTrack::sClassName;
}

// File Line: 716
// RVA: 0x2DC8E0
void __fastcall NodeRefTrack<ExecuteTrackLibraryTask>::ResolveReferences(
        NodeRefTrack<SpawnTask> *this,
        ActionNode *parent)
{
  ((void (__fastcall *)(NodeRefTrack<SpawnTask> *))this->vfptr[2].FindWithOldPath)(this);
  ((void (__fastcall *)(NodeRefTrack<SpawnTask> *, ActionNode *))this->vfptr[1].GetResourceOwner)(this, parent);
}

