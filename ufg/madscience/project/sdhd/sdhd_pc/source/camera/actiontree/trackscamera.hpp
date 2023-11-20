// File Line: 26
// RVA: 0x2BDDA0
__int64 __fastcall CameraChangeTrack::GetClassNameUID(CameraChangeTrack *this)
{
  return CameraChangeTrack::sClassNameUID;
}

// File Line: 45
// RVA: 0x2BDE40
__int64 __fastcall CameraShakeTrack::GetClassNameUID(CameraShakeTrack *this)
{
  return CameraShakeTrack::sClassNameUID;
}

// File Line: 63
// RVA: 0x2BDE20
__int64 __fastcall CameraResetTrack::GetClassNameUID(CameraResetTrack *this)
{
  return CameraResetTrack::sClassNameUID;
}

// File Line: 84
// RVA: 0x2BDE10
__int64 __fastcall CameraRecoilTrack::GetClassNameUID(CameraRecoilTrack *this)
{
  return CameraRecoilTrack::sClassNameUID;
}

// File Line: 105
// RVA: 0x2BDDB0
__int64 __fastcall CameraCollisionGotoAngleTrack::GetClassNameUID(CameraCollisionGotoAngleTrack *this)
{
  return CameraCollisionGotoAngleTrack::sClassNameUID;
}

// File Line: 120
// RVA: 0x2BDDC0
__int64 __fastcall CameraConstrainYawTrack::GetClassNameUID(CameraConstrainYawTrack *this)
{
  return CameraConstrainYawTrack::sClassNameUID;
}

// File Line: 141
// RVA: 0x2C0AA0
const char *__fastcall CameraIgnoreCollisionTrack::GetClassname(CameraIgnoreCollisionTrack *this)
{
  return CameraIgnoreCollisionTrack::sClassName;
}

// File Line: 162
// RVA: 0x2BDD90
__int64 __fastcall CameraAnimationTrack::GetClassNameUID(CameraAnimationTrack *this)
{
  return CameraAnimationTrack::sClassNameUID;
}

// File Line: 295
// RVA: 0x315EA0
void __fastcall CameraDOFTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::CameraDOFTrack", 0i64, 1u);
  if ( v0 )
    CameraDOFTrack::CameraDOFTrack((CameraDOFTrack *)v0);
}

// File Line: 320
// RVA: 0x3138F0
void __fastcall SubjectFollowOverrideTrack::SubjectFollowOverrideTrack(SubjectFollowOverrideTrack *this)
{
  SubjectFollowOverrideTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, SubjectFollowOverrideTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<SubjectFollowOverrideTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&SubjectFollowOverrideTrack::`vftable;
  v1->mFollowContextOverride.mOffset = 1i64;
  BinString::Set(&v1->mFollowContextOverride, &customWorldMapCaption);
  v1->mFollowCameraType = 0;
  *(_WORD *)&v1->bFollowCameraTypesAll = 256;
}

// File Line: 322
// RVA: 0x2C2570
const char *__fastcall SubjectFollowOverrideTrack::GetClassname(SubjectFollowOverrideTrack *this)
{
  return SubjectFollowOverrideTrack::sClassName;
}

// File Line: 347
// RVA: 0x313870
void __fastcall SubjectFollowOverridePOITrack::SubjectFollowOverridePOITrack(SubjectFollowOverridePOITrack *this)
{
  SubjectFollowOverridePOITrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, SubjectFollowOverridePOITrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<SubjectFollowOverridePOITask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&SubjectFollowOverridePOITrack::`vftable;
  v1->mFollowContextLeftOverride.mOffset = 1i64;
  BinString::Set(&v1->mFollowContextLeftOverride, &customWorldMapCaption);
  v1->mFollowContextRightOverride.mOffset = 1i64;
  BinString::Set(&v1->mFollowContextRightOverride, &customWorldMapCaption);
  v1->mFollowCameraType = 0;
  *(_WORD *)&v1->bFollowCameraTypesAll = 256;
}

// File Line: 349
// RVA: 0x2BF8C0
__int64 __fastcall SubjectFollowOverridePOITrack::GetClassNameUID(SubjectFollowOverridePOITrack *this)
{
  return SubjectFollowOverridePOITrack::sClassNameUID;
}

// File Line: 379
// RVA: 0x3215A0
void __fastcall SubjectFollowOverrideChooseTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x60ui64,
         "MemberMap::SubjectFollowOverrideChooseTrack",
         0i64,
         1u);
  if ( v0 )
    SubjectFollowOverrideChooseTrack::SubjectFollowOverrideChooseTrack((SubjectFollowOverrideChooseTrack *)v0);
}

// File Line: 418
// RVA: 0x315EF0
void __fastcall CameraFollowGotoTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x70ui64, "MemberMap::CameraFollowGotoTrack", 0i64, 1u);
  if ( v0 )
    CameraFollowGotoTrack::CameraFollowGotoTrack((CameraFollowGotoTrack *)v0);
}

// File Line: 499
// RVA: 0x2C0A90
const char *__fastcall CameraFollowTargetTrack::GetClassname(CameraFollowTargetTrack *this)
{
  return CameraFollowTargetTrack::sClassName;
}

// File Line: 522
// RVA: 0x299FA0
void __fastcall CameraSetSniperModeTrack::~CameraSetSniperModeTrack(CameraSetSniperModeTrack *this)
{
  CameraSetSniperModeTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CameraSetSniperModeTrack::`vftable;
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

// File Line: 524
// RVA: 0x2C0AD0
const char *__fastcall CameraSetSniperModeTrack::GetClassname(CameraSetSniperModeTrack *this)
{
  return CameraSetSniperModeTrack::sClassName;
}

// File Line: 542
// RVA: 0x321690
ITrack *__fastcall SubjectSprintTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::SubjectSprintTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, SubjectSprintTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<SubjectSprintTask>::`vftable;
  *(_QWORD *)v1 = &SubjectSprintTrack::`vftable;
  v1[56] = 0;
  return (ITrack *)v1;
}

// File Line: 562
// RVA: 0x2BF8A0
__int64 __fastcall SubjectElevationTrack::GetClassNameUID(SubjectElevationTrack *this)
{
  return SubjectElevationTrack::sClassNameUID;
}

// File Line: 582
// RVA: 0x2BF8B0
__int64 __fastcall SubjectFallingAttackTrack::GetClassNameUID(SubjectFallingAttackTrack *this)
{
  return SubjectFallingAttackTrack::sClassNameUID;
}

