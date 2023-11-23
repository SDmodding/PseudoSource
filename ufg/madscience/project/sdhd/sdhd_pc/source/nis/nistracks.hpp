// File Line: 59
// RVA: 0x29E440
void __fastcall SubtitleTrack::~SubtitleTrack(SubtitleTrack *this)
{
  char *v2; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v4; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&SubtitleTrack::`vftable;
  if ( (this->mSubtitle.mOffset & 1) != 0 && (this->mSubtitle.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v2 = (char *)&this->mSubtitle + (this->mSubtitle.mOffset & 0xFFFFFFFFFFFFFFFEui64);
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

// File Line: 61
// RVA: 0x2C25A0
const char *__fastcall SubtitleTrack::GetClassname(SubtitleTrack *this)
{
  return SubtitleTrack::sClassName;
}

// File Line: 89
// RVA: 0x29E3A0
void __fastcall SubtitleGroupTrack::~SubtitleGroupTrack(SubtitleGroupTrack *this)
{
  char *v2; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v4; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&SubtitleGroupTrack::`vftable;
  if ( (this->mSubtitle.mOffset & 1) != 0 && (this->mSubtitle.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v2 = (char *)&this->mSubtitle + (this->mSubtitle.mOffset & 0xFFFFFFFFFFFFFFFEui64);
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

// File Line: 91
// RVA: 0x2C2590
const char *__fastcall SubtitleGroupTrack::GetClassname(SubtitleGroupTrack *this)
{
  return SubtitleGroupTrack::sClassName;
}

// File Line: 131
// RVA: 0x29B1E0
void __fastcall CurtainShowTrack::~CurtainShowTrack(CurtainShowTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&CurtainShowTrack::`vftable;
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

// File Line: 133
// RVA: 0x2BE330
__int64 __fastcall CurtainShowTrack::GetClassNameUID(CurtainShowTrack *this)
{
  return CurtainShowTrack::sClassNameUID;
}

// File Line: 185
// RVA: 0x29B880
void __fastcall FastCurtainShowTrack::~FastCurtainShowTrack(FastCurtainShowTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&FastCurtainShowTrack::`vftable;
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

// File Line: 187
// RVA: 0x2C12C0
const char *__fastcall FastCurtainShowTrack::GetClassname(FastCurtainShowTrack *this)
{
  return FastCurtainShowTrack::sClassName;
}

// File Line: 236
// RVA: 0x299E70
void __fastcall AudioTrackNIS::~AudioTrackNIS(AudioTrackNIS *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AudioTrackNIS::`vftable;
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

// File Line: 238
// RVA: 0x2BDCC0
__int64 __fastcall AudioTrackNIS::GetClassNameUID(AudioTrackNIS *this)
{
  return AudioTrackNIS::sClassNameUID;
}

// File Line: 288
// RVA: 0x29C8E0
void __fastcall NISFadeOutTrack::~NISFadeOutTrack(NISFadeOutTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&NISFadeOutTrack::`vftable;
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

// File Line: 290
// RVA: 0x2C1B70
const char *__fastcall NISFadeOutTrack::GetClassname(NISFadeOutTrack *this)
{
  return NISFadeOutTrack::sClassName;
}

// File Line: 344
// RVA: 0x29C9F0
void __fastcall NISShadowCascadeTrack::~NISShadowCascadeTrack(NISShadowCascadeTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&NISShadowCascadeTrack::`vftable;
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

// File Line: 346
// RVA: 0x2C1BB0
const char *__fastcall NISShadowCascadeTrack::GetClassname(NISShadowCascadeTrack *this)
{
  return NISShadowCascadeTrack::sClassName;
}

// File Line: 418
// RVA: 0x299670
void __fastcall ActorAttachTrack::~ActorAttachTrack(ActorAttachTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&ActorAttachTrack::`vftable;
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

// File Line: 420
// RVA: 0x314A50
void __fastcall ActorAttachTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::ActorAttachTrack", 0i64, 1u);
  if ( v0 )
    ActorAttachTrack::ActorAttachTrack((ActorAttachTrack *)v0);
}

// File Line: 474
// RVA: 0x2996E0
void __fastcall ActorDetachTrack::~ActorDetachTrack(ActorDetachTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&ActorDetachTrack::`vftable;
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

// File Line: 476
// RVA: 0x314AA0
void __fastcall ActorDetachTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::ActorDetachTrack", 0i64, 1u);
  if ( v0 )
    ActorDetachTrack::ActorDetachTrack((ActorDetachTrack *)v0);
}

// File Line: 521
// RVA: 0x2C1B80
const char *__fastcall NISLightGroupAnimationTrack::GetClassname(NISLightGroupAnimationTrack *this)
{
  return NISLightGroupAnimationTrack::sClassName;
}

// File Line: 556
// RVA: 0x29C950
void __fastcall NISPlayMovieTrack::~NISPlayMovieTrack(NISPlayMovieTrack *this)
{
  char *v2; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v4; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&NISPlayMovieTrack::`vftable;
  if ( (this->mMovieFilename.mOffset & 1) != 0 && (this->mMovieFilename.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v2 = (char *)&this->mMovieFilename + (this->mMovieFilename.mOffset & 0xFFFFFFFFFFFFFFFEui64);
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

// File Line: 558
// RVA: 0x2BEF00
__int64 __fastcall NISPlayMovieTrack::GetClassNameUID(NISPlayMovieTrack *this)
{
  return NISPlayMovieTrack::sClassNameUID;
}

// File Line: 596
// RVA: 0x29C870
void __fastcall NISAllowPlayerControlTrack::~NISAllowPlayerControlTrack(NISAllowPlayerControlTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&NISAllowPlayerControlTrack::`vftable;
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

// File Line: 598
// RVA: 0x2C1B60
const char *__fastcall NISAllowPlayerControlTrack::GetClassname(NISAllowPlayerControlTrack *this)
{
  return NISAllowPlayerControlTrack::sClassName;
}

