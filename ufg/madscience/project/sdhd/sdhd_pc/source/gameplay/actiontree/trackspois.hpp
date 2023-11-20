// File Line: 28
// RVA: 0x29CC20
void __fastcall POIBehaviourActiveTrack::~POIBehaviourActiveTrack(POIBehaviourActiveTrack *this)
{
  POIBehaviourActiveTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&POIBehaviourActiveTrack::`vftable;
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
  POIManagementTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&POIManagementTrack::`vftable;
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
  POIDisableSelfTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&POIDisableSelfTrack::`vftable;
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
  POIEnableChildTrack *v1; // rbx
  char *v2; // rcx
  ExpressionParameterFloat *v3; // rcx
  char *v4; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&POIEnableChildTrack::`vftable;
  if ( !(~LOBYTE(this->m_ChildName.mOffset) & 1) )
  {
    if ( this->m_ChildName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v2 = (char *)&this->m_ChildName + (this->m_ChildName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
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

