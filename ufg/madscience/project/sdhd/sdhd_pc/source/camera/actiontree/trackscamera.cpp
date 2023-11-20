// File Line: 25
// RVA: 0x149BC30
__int64 dynamic_initializer_for__cameraChangeTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&cameraChangeTypeEnum, gCameraTypeStringList, 2, 0i64);
  return atexit(dynamic_atexit_destructor_for__cameraChangeTypeEnum__);
}

// File Line: 27
// RVA: 0x1494D90
__int64 dynamic_initializer_for__CameraChangeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CameraChangeTrack", 0xFFFFFFFF);
  CameraChangeTrack::sClassNameUID = result;
  return result;
}

// File Line: 41
// RVA: 0x1494ED0
__int64 dynamic_initializer_for__CameraShakeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CameraShakeTrack", 0xFFFFFFFF);
  CameraShakeTrack::sClassNameUID = result;
  return result;
}

// File Line: 55
// RVA: 0x1494E90
__int64 dynamic_initializer_for__CameraResetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CameraResetTrack", 0xFFFFFFFF);
  CameraResetTrack::sClassNameUID = result;
  return result;
}

// File Line: 74
// RVA: 0x1494E70
__int64 dynamic_initializer_for__CameraRecoilTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CameraRecoilTrack", 0xFFFFFFFF);
  CameraRecoilTrack::sClassNameUID = result;
  return result;
}

// File Line: 93
// RVA: 0x1494DB0
__int64 dynamic_initializer_for__CameraCollisionGotoAngleTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CameraCollisionGotoAngleTrack", 0xFFFFFFFF);
  CameraCollisionGotoAngleTrack::sClassNameUID = result;
  return result;
}

// File Line: 108
// RVA: 0x1494DD0
__int64 dynamic_initializer_for__CameraConstrainYawTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CameraConstrainYawTrack", 0xFFFFFFFF);
  CameraConstrainYawTrack::sClassNameUID = result;
  return result;
}

// File Line: 129
// RVA: 0x1494E50
__int64 dynamic_initializer_for__CameraIgnoreCollisionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CameraIgnoreCollisionTrack", 0xFFFFFFFF);
  CameraIgnoreCollisionTrack::sClassNameUID = result;
  return result;
}

// File Line: 150
// RVA: 0x149BC00
__int64 dynamic_initializer_for__cameraAnimationEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &cameraAnimationEnum,
    gCameraAnimationPlayModeStringList,
    3,
    0i64);
  return atexit(dynamic_atexit_destructor_for__cameraAnimationEnum__);
}

// File Line: 152
// RVA: 0x1494D70
__int64 dynamic_initializer_for__CameraAnimationTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CameraAnimationTrack", 0xFFFFFFFF);
  CameraAnimationTrack::sClassNameUID = result;
  return result;
}

// File Line: 217
// RVA: 0x2DE2D0
void __fastcall CameraAnimationTrack::CameraAnimationTrack(CameraAnimationTrack *this)
{
  CameraAnimationTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CameraAnimationTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CameraAnimationTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CameraAnimationTrack::`vftable;
  v1->mAnimationPlayMode.mValue = 0;
  v1->mStartFrame = 0.0;
  v1->mEndFrame = 1.0;
  v1->mFov = 55.0;
  v1->mFocalDistance = 5.0;
  v1->mInFocusRange = 100.0;
  *(_QWORD *)&v1->mNearRange = 1084227584i64;
  *(_QWORD *)&v1->mFarRange = 1084227584i64;
  v1->mExitRateEyeMin = 0.5;
  v1->mExitRateEyeMax = 0.5;
  v1->mExitRateOrientMin = 0.5;
  *(_QWORD *)&v1->mExitRateOrientMax = 1056964608i64;
  v1->mExitGotoRise = 0.0;
  v1->mAnimationName.mUID = -1;
  *(_QWORD *)&v1->mPreserveMotion = 1i64;
  *(_WORD *)&v1->mSmoothExitGoto = 0;
  v1->mMaster = 1;
  v1->mAnimationName.mUID = gStaticSymbolUC_none.mUID;
}

// File Line: 223
// RVA: 0x2E3740
void __fastcall CameraAnimationTrack::~CameraAnimationTrack(CameraAnimationTrack *this)
{
  CameraAnimationTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CameraAnimationTrack::`vftable;
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

// File Line: 303
// RVA: 0x1494DF0
__int64 dynamic_initializer_for__CameraDOFTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CameraDOFTrack", 0xFFFFFFFF);
  CameraDOFTrack::sClassNameUID = result;
  return result;
}

// File Line: 320
// RVA: 0x2DE390
void __fastcall CameraDOFTrack::CameraDOFTrack(CameraDOFTrack *this)
{
  CameraDOFTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CameraDOFTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CameraDOFTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CameraDOFTrack::`vftable;
  v1->rFocalRange = 10.0;
  v1->rNearRange = 1.0;
  v1->rFarRange = 10.0;
  v1->rNearBlur = 0.2;
  v1->rFarBlur = 0.2;
}

// File Line: 337
// RVA: 0x1496150
__int64 dynamic_initializer_for__SubjectFollowOverrideTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SubjectFollowOverrideTrack", 0xFFFFFFFF);
  SubjectFollowOverrideTrack::sClassNameUID = result;
  return result;
}

// File Line: 359
// RVA: 0x1496130
__int64 dynamic_initializer_for__SubjectFollowOverridePOITrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SubjectFollowOverridePOITrack", 0xFFFFFFFF);
  SubjectFollowOverridePOITrack::sClassNameUID = result;
  return result;
}

// File Line: 383
// RVA: 0x1496110
__int64 dynamic_initializer_for__SubjectFollowOverrideChooseTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SubjectFollowOverrideChooseTrack", 0xFFFFFFFF);
  SubjectFollowOverrideChooseTrack::sClassNameUID = result;
  return result;
}

// File Line: 404
// RVA: 0x2E12F0
void __fastcall SubjectFollowOverrideChooseTrack::SubjectFollowOverrideChooseTrack(SubjectFollowOverrideChooseTrack *this)
{
  SubjectFollowOverrideChooseTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, SubjectFollowOverrideChooseTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<SubjectFollowOverrideChooseTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&SubjectFollowOverrideChooseTrack::`vftable;
  v1->mFollowContextLeftOverride.mOffset = 1i64;
  BinString::Set(&v1->mFollowContextLeftOverride, &customWorldMapCaption);
  v1->mFollowContextRightOverride.mOffset = 1i64;
  BinString::Set(&v1->mFollowContextRightOverride, &customWorldMapCaption);
  v1->mOriginPrimary.mOffset = 1i64;
  BinString::Set(&v1->mOriginPrimary, "hip");
  v1->mOriginSecondary.mOffset = 1i64;
  BinString::Set(&v1->mOriginSecondary, "pip");
  v1->mFollowCameraType = 0;
  *(_WORD *)&v1->bFollowCameraTypesAll = 256;
}

// File Line: 413
// RVA: 0x2E12B0
void __fastcall SubjectFollowOverrideChooseTrack::SubjectFollowOverrideChooseTrack(SubjectFollowOverrideChooseTrack *this, MemImageLoadFlag flag)
{
  SubjectFollowOverrideChooseTrack *v2; // rbx

  v2 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, flag);
  v2->vfptr = (Expression::IMemberMapVtbl *)&Track<SubjectFollowOverrideChooseTask>::`vftable;
  v2->vfptr = (Expression::IMemberMapVtbl *)&SubjectFollowOverrideChooseTrack::`vftable;
}

// File Line: 432
// RVA: 0x1494E10
__int64 dynamic_initializer_for__CameraFollowGotoTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CameraFollowGotoTrack", 0xFFFFFFFF);
  CameraFollowGotoTrack::sClassNameUID = result;
  return result;
}

// File Line: 478
// RVA: 0x2DE400
void __fastcall CameraFollowGotoTrack::CameraFollowGotoTrack(CameraFollowGotoTrack *this)
{
  CameraFollowGotoTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CameraFollowGotoTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CameraFollowGotoTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CameraFollowGotoTrack::`vftable;
  v1->rGotoRise = 1.0;
  v1->rGotoRiseRate = 2.5;
  v1->rGotoRisePatience = 1.0;
  v1->rGotoRadius = 3.0;
  v1->rGotoRadiusRate = 5.0;
  *(_QWORD *)&v1->rGotoRadiusPatience = 1065353216i64;
  v1->rGotoAngleRate = 2.0;
  *(_QWORD *)&v1->rGotoAnglePatience = 1065353216i64;
  *(_DWORD *)&v1->bGotoRise = 0;
  *(_DWORD *)&v1->bGotoAngleWorldSpace = 0x10000;
  *(_WORD *)&v1->bGotoAngleFarthest = 0;
}

// File Line: 514
// RVA: 0x1494E30
__int64 dynamic_initializer_for__CameraFollowTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CameraFollowTargetTrack", 0xFFFFFFFF);
  CameraFollowTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 523
// RVA: 0x2DE490
void __fastcall CameraFollowTargetTrack::CameraFollowTargetTrack(CameraFollowTargetTrack *this)
{
  CameraFollowTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CameraFollowTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CameraFollowTargetTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CameraFollowTargetTrack::`vftable;
  v1->m_TargetType = 1;
  v1->mFollowBoneName.mUID = -1;
}

// File Line: 535
// RVA: 0x1494EB0
__int64 dynamic_initializer_for__CameraSetSniperModeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CameraSetSniperModeTrack", 0xFFFFFFFF);
  CameraSetSniperModeTrack::sClassNameUID = result;
  return result;
}

// File Line: 544
// RVA: 0x2DE4E0
void __fastcall CameraSetSniperModeTrack::CameraSetSniperModeTrack(CameraSetSniperModeTrack *this)
{
  CameraSetSniperModeTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CameraSetSniperModeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CameraSetSniperModeTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CameraSetSniperModeTrack::`vftable;
  v1->m_Enabled = 0;
}

// File Line: 557
// RVA: 0x1496170
__int64 dynamic_initializer_for__SubjectSprintTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SubjectSprintTrack", 0xFFFFFFFF);
  SubjectSprintTrack::sClassNameUID = result;
  return result;
}

// File Line: 572
// RVA: 0x14960D0
__int64 dynamic_initializer_for__SubjectElevationTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SubjectElevationTrack", 0xFFFFFFFF);
  SubjectElevationTrack::sClassNameUID = result;
  return result;
}

// File Line: 587
// RVA: 0x14960F0
__int64 dynamic_initializer_for__SubjectFallingAttackTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SubjectFallingAttackTrack", 0xFFFFFFFF);
  SubjectFallingAttackTrack::sClassNameUID = result;
  return result;
}

