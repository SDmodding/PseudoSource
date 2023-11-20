// File Line: 25
// RVA: 0x29F020
void __fastcall UIEventTrack::~UIEventTrack(UIEventTrack *this)
{
  UIEventTrack *v1; // rbx
  char *v2; // rcx
  ExpressionParameterFloat *v3; // rcx
  char *v4; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&UIEventTrack::`vftable;
  if ( !(~LOBYTE(this->mEventName.mOffset) & 1) )
  {
    if ( this->mEventName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v2 = (char *)&this->mEventName + (this->mEventName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
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

// File Line: 27
// RVA: 0x3240F0
void __fastcall UIEventTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::UIEventTrack", 0i64, 1u);
  if ( v0 )
    UIEventTrack::UIEventTrack((UIEventTrack *)v0);
}

// File Line: 45
// RVA: 0x29F0C0
void __fastcall UIScreenTrack::~UIScreenTrack(UIScreenTrack *this)
{
  UIScreenTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&UIScreenTrack::`vftable;
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

// File Line: 47
// RVA: 0x3241F0
void __fastcall UIScreenTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::UIScreenTrack", 0i64, 1u);
  if ( v0 )
    UIScreenTrack::UIScreenTrack((UIScreenTrack *)v0);
}

// File Line: 98
// RVA: 0x29BC70
void __fastcall HUDSocialActionChargeTrack::~HUDSocialActionChargeTrack(HUDSocialActionChargeTrack *this)
{
  HUDSocialActionChargeTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&HUDSocialActionChargeTrack::`vftable;
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

// File Line: 100
// RVA: 0x2BE7B0
__int64 __fastcall HUDSocialActionChargeTrack::GetClassNameUID(HUDSocialActionChargeTrack *this)
{
  return HUDSocialActionChargeTrack::sClassNameUID;
}

// File Line: 121
// RVA: 0x29BC00
void __fastcall HUDSocialActionActivateTrack::~HUDSocialActionActivateTrack(HUDSocialActionActivateTrack *this)
{
  HUDSocialActionActivateTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&HUDSocialActionActivateTrack::`vftable;
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

// File Line: 123
// RVA: 0x2BE7A0
__int64 __fastcall HUDSocialActionActivateTrack::GetClassNameUID(HUDSocialActionActivateTrack *this)
{
  return HUDSocialActionActivateTrack::sClassNameUID;
}

// File Line: 134
// RVA: 0x29BCE0
void __fastcall HUDSocialActionEnableTrack::~HUDSocialActionEnableTrack(HUDSocialActionEnableTrack *this)
{
  HUDSocialActionEnableTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&HUDSocialActionEnableTrack::`vftable;
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

// File Line: 136
// RVA: 0x2C1460
const char *__fastcall HUDSocialActionEnableTrack::GetClassname(HUDSocialActionEnableTrack *this)
{
  return HUDSocialActionEnableTrack::sClassName;
}

