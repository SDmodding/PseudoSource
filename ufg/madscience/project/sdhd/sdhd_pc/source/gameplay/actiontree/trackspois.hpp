// File Line: 28
// RVA: 0x29CC20
void __fastcall POIBehaviourActiveTrack::~POIBehaviourActiveTrack(POIBehaviourActiveTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&POIBehaviourActiveTrack::`vftable;
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

// File Line: 31
// RVA: 0x2C1CE0
const char *__fastcall POIBehaviourActiveTrack::GetClassname(POIBehaviourActiveTrack *this)
{
  return POIBehaviourActiveTrack::sClassName;
}

// File Line: 40
// RVA: 0x29CE30
void __fastcall POIManagementTrack::~POIManagementTrack(POIManagementTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&POIManagementTrack::`vftable;
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

// File Line: 42
// RVA: 0x2BF090
__int64 __fastcall POIManagementTrack::GetClassNameUID(POIManagementTrack *this)
{
  return POIManagementTrack::sClassNameUID;
}

// File Line: 52
// RVA: 0x29CC90
void __fastcall POIDisableSelfTrack::~POIDisableSelfTrack(POIDisableSelfTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&POIDisableSelfTrack::`vftable;
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

// File Line: 54
// RVA: 0x2C1CF0
const char *__fastcall POIDisableSelfTrack::GetClassname(POIDisableSelfTrack *this)
{
  return POIDisableSelfTrack::sClassName;
}

// File Line: 74
// RVA: 0x29CD00
void __fastcall POIEnableChildTrack::~POIEnableChildTrack(POIEnableChildTrack *this)
{
  char *v2; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v4; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&POIEnableChildTrack::`vftable;
  if ( (this->m_ChildName.mOffset & 1) != 0 && (this->m_ChildName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v2 = (char *)&this->m_ChildName + (this->m_ChildName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
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

// File Line: 76
// RVA: 0x2C1D00
const char *__fastcall POIEnableChildTrack::GetClassname(POIEnableChildTrack *this)
{
  return POIEnableChildTrack::sClassName;
}

// File Line: 108
// RVA: 0x31AFB0
void __fastcall InteractionPointInteractWithBestTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x38ui64,
         "MemberMap::InteractionPointInteractWithBestTrack",
         0i64,
         1u);
  if ( v0 )
    InteractionPointInteractWithBestTrack::InteractionPointInteractWithBestTrack((InteractionPointInteractWithBestTrack *)v0);
}

// File Line: 122
// RVA: 0x2BE9F0
__int64 __fastcall InteractionPointSetupTrack::GetClassNameUID(InteractionPointSetupTrack *this)
{
  return InteractionPointSetupTrack::sClassNameUID;
}

// File Line: 164
// RVA: 0x31AEC0
void __fastcall InteractionPointActivateTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x40ui64,
         "MemberMap::InteractionPointActivateTrack",
         0i64,
         1u);
  if ( v0 )
    InteractionPointActivateTrack::InteractionPointActivateTrack((InteractionPointActivateTrack *)v0);
}

// File Line: 189
// RVA: 0x2C1670
const char *__fastcall InteractionPointDeactivateTrack::GetClassname(InteractionPointDeactivateTrack *this)
{
  return InteractionPointDeactivateTrack::sClassName;
}

