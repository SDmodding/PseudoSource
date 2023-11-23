// File Line: 25
// RVA: 0x149BC30
__int64 dynamic_initializer_for__cameraChangeTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&cameraChangeTypeEnum, gCameraTypeStringList, 2, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__cameraChangeTypeEnum__);
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__cameraAnimationEnum__);
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
  ITrack::ITrack(this, CameraAnimationTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CameraAnimationTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CameraAnimationTrack::`vftable;
  this->mAnimationPlayMode.mValue = 0;
  this->mStartFrame = 0.0;
  this->mEndFrame = 1.0;
  this->mFov = 55.0;
  this->mFocalDistance = 5.0;
  this->mInFocusRange = 100.0;
  *(_QWORD *)&this->mNearRange = 1084227584i64;
  *(_QWORD *)&this->mFarRange = 1084227584i64;
  this->mExitRateEyeMin = 0.5;
  this->mExitRateEyeMax = 0.5;
  this->mExitRateOrientMin = 0.5;
  *(_QWORD *)&this->mExitRateOrientMax = 1056964608i64;
  this->mExitGotoRise = 0.0;
  this->mAnimationName.mUID = -1;
  *(_QWORD *)&this->mPreserveMotion = 1i64;
  *(_WORD *)&this->mSmoothExitGoto = 0;
  this->mMaster = 1;
  this->mAnimationName.mUID = gStaticSymbolUC_none.mUID;
}

// File Line: 223
// RVA: 0x2E3740
void __fastcall CameraAnimationTrack::~CameraAnimationTrack(CameraAnimationTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&CameraAnimationTrack::`vftable;
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
  ITrack::ITrack(this, CameraDOFTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CameraDOFTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CameraDOFTrack::`vftable;
  this->rFocalRange = 10.0;
  this->rNearRange = 1.0;
  this->rFarRange = 10.0;
  this->rNearBlur = 0.2;
  this->rFarBlur = 0.2;
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
void __fastcall SubjectFollowOverrideChooseTrack::SubjectFollowOverrideChooseTrack(
        SubjectFollowOverrideChooseTrack *this)
{
  ITrack::ITrack(this, SubjectFollowOverrideChooseTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<SubjectFollowOverrideChooseTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&SubjectFollowOverrideChooseTrack::`vftable;
  this->mFollowContextLeftOverride.mOffset = 1i64;
  BinString::Set(&this->mFollowContextLeftOverride, &customCaption);
  this->mFollowContextRightOverride.mOffset = 1i64;
  BinString::Set(&this->mFollowContextRightOverride, &customCaption);
  this->mOriginPrimary.mOffset = 1i64;
  BinString::Set(&this->mOriginPrimary, "hip");
  this->mOriginSecondary.mOffset = 1i64;
  BinString::Set(&this->mOriginSecondary, "pip");
  this->mFollowCameraType = 0;
  *(_WORD *)&this->bFollowCameraTypesAll = 256;
}

// File Line: 413
// RVA: 0x2E12B0
void __fastcall SubjectFollowOverrideChooseTrack::SubjectFollowOverrideChooseTrack(
        SubjectFollowOverrideChooseTrack *this,
        MemImageLoadFlag flag)
{
  ITrack::ITrack(this, flag);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<SubjectFollowOverrideChooseTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&SubjectFollowOverrideChooseTrack::`vftable;
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
  ITrack::ITrack(this, CameraFollowGotoTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CameraFollowGotoTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CameraFollowGotoTrack::`vftable;
  this->rGotoRise = 1.0;
  this->rGotoRiseRate = 2.5;
  this->rGotoRisePatience = 1.0;
  this->rGotoRadius = 3.0;
  this->rGotoRadiusRate = 5.0;
  *(_QWORD *)&this->rGotoRadiusPatience = 1065353216i64;
  this->rGotoAngleRate = 2.0;
  *(_QWORD *)&this->rGotoAnglePatience = 1065353216i64;
  *(_DWORD *)&this->bGotoRise = 0;
  *(_DWORD *)&this->bGotoAngleWorldSpace = 0x10000;
  *(_WORD *)&this->bGotoAngleFarthest = 0;
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
  ITrack::ITrack(this, CameraFollowTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CameraFollowTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CameraFollowTargetTrack::`vftable;
  this->m_TargetType = 1;
  this->mFollowBoneName.mUID = -1;
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
  ITrack::ITrack(this, CameraSetSniperModeTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CameraSetSniperModeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CameraSetSniperModeTrack::`vftable;
  this->m_Enabled = 0;
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

