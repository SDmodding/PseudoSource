// File Line: 27
// RVA: 0x14957B0
__int64 dynamic_initializer_for__LocomotionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("LocomotionTrack", 0xFFFFFFFF);
  LocomotionTrack::sClassNameUID = result;
  return result;
}

// File Line: 39
// RVA: 0x2DFDB0
void __fastcall LocomotionTrack::LocomotionTrack(LocomotionTrack *this)
{
  ITrack::ITrack(this, LocomotionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<LocomotionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&LocomotionTrack::`vftable;
  this->mTurnRate = 0.034906585;
  this->mActiveRange = 3.1415927;
  this->mMaster = 1;
}

// File Line: 44
// RVA: 0x2E4190
void __fastcall LocomotionTrack::~LocomotionTrack(LocomotionTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&LocomotionTrack::`vftable;
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

// File Line: 57
// RVA: 0x1495770
__int64 dynamic_initializer_for__Locomotion2Track::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Locomotion2Track", 0xFFFFFFFF);
  Locomotion2Track::sClassNameUID = result;
  return result;
}

// File Line: 77
// RVA: 0x2DFCE0
void __fastcall Locomotion2Track::Locomotion2Track(Locomotion2Track *this)
{
  ITrack::ITrack(this, Locomotion2Track::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<Locomotion2Task>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Locomotion2Track::`vftable;
  this->mActiveRange = 3.1415927;
  this->mMaxAngularVel = 0.034906585;
  this->mPositionGain = 50.0;
  this->mVelocityGain = 10.0;
  *(_WORD *)&this->mPreserveLeanParam = 0;
  this->mMaster = 1;
}

// File Line: 82
// RVA: 0x2E40B0
void __fastcall Locomotion2Track::~Locomotion2Track(Locomotion2Track *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&Locomotion2Track::`vftable;
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

// File Line: 102
// RVA: 0x1495790
__int64 dynamic_initializer_for__LocomotionParamTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("LocomotionParamTrack", 0xFFFFFFFF);
  LocomotionParamTrack::sClassNameUID = result;
  return result;
}

// File Line: 116
// RVA: 0x2DFD50
void __fastcall LocomotionParamTrack::LocomotionParamTrack(LocomotionParamTrack *this)
{
  ITrack::ITrack(this, LocomotionParamTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<LocomotionParamTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&LocomotionParamTrack::`vftable;
  *(_QWORD *)&this->mRotationInput = 0i64;
  *(_QWORD *)&this->mRotationAccel = 0i64;
  this->mMaster = 0;
  this->mTimeEnd = -1.0;
}

// File Line: 122
// RVA: 0x2E4120
void __fastcall LocomotionParamTrack::~LocomotionParamTrack(LocomotionParamTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&LocomotionParamTrack::`vftable;
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
// RVA: 0x1495750
__int64 dynamic_initializer_for__JumpTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("JumpTrack", 0xFFFFFFFF);
  JumpTrack::sClassNameUID = result;
  return result;
}

// File Line: 157
// RVA: 0x1496710
__int64 dynamic_initializer_for__TimeWarpTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TimeWarpTrack", 0xFFFFFFFF);
  TimeWarpTrack::sClassNameUID = result;
  return result;
}

// File Line: 173
// RVA: 0x2E2110
void __fastcall TimeWarpTrack::TimeWarpTrack(TimeWarpTrack *this)
{
  ITrack::ITrack(this, TimeWarpTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TimeWarpTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TimeWarpTrack::`vftable;
  this->mWarpFactor = 1.0;
  this->mCheckPlayerOnly = 1;
  *(_QWORD *)&this->mBlendTime = 0i64;
  *(_QWORD *)&this->m_audioTagId[1] = 0i64;
  this->m_audioTagUID[1] = 0;
}

// File Line: 295
// RVA: 0x14950F0
__int64 dynamic_initializer_for__DamageTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DamageTrack", 0xFFFFFFFF);
  DamageTrack::sClassNameUID = result;
  return result;
}

// File Line: 319
// RVA: 0x1495550
__int64 dynamic_initializer_for__HandleDamageTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HandleDamageTrack", 0xFFFFFFFF);
  HandleDamageTrack::sClassNameUID = result;
  return result;
}

// File Line: 328
// RVA: 0x2DF7D0
void __fastcall HandleDamageTrack::HandleDamageTrack(HandleDamageTrack *this)
{
  ITrack::ITrack(this, HandleDamageTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<HandleDamageTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&HandleDamageTrack::`vftable;
  this->mDamageMultiplyer.text.mOffset = 1i64;
  BinString::Set(&this->mDamageMultiplyer.text, &customCaption);
  this->mDamageMultiplyer.expression.mOffset = 0i64;
  this->mDamageMultiplyer.value = 100;
  this->mFaceAttacker = 1;
}

// File Line: 349
// RVA: 0x1496070
__int64 dynamic_initializer_for__StimulusTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("StimulusTrack", 0xFFFFFFFF);
  StimulusTrack::sClassNameUID = result;
  return result;
}

// File Line: 371
// RVA: 0x2E1170
void __fastcall StimulusTrack::StimulusTrack(StimulusTrack *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  ITrack::ITrack(this, StimulusTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<StimulusTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&StimulusTrack::`vftable;
  this->mActivationType.mValue = 0;
  this->mSourceTargetType = 1;
  this->mMaxDuration = -1.0;
  this->mTargetType = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mOffset.x = UFG::qVector3::msZero.x;
  this->mOffset.y = y;
  this->mOffset.z = z;
  this->mStimulusType.mValue = 0;
  this->mIsTargeted = 0;
}

// File Line: 376
// RVA: 0x2E5430
void __fastcall StimulusTrack::~StimulusTrack(StimulusTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&StimulusTrack::`vftable;
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

// File Line: 399
// RVA: 0x14955D0
__int64 dynamic_initializer_for__HealthSetPercentageTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HealthSetPercentageTrack", 0xFFFFFFFF);
  HealthSetPercentageTrack::sClassNameUID = result;
  return result;
}

// File Line: 405
// RVA: 0x2DF940
void __fastcall HealthSetPercentageTrack::HealthSetPercentageTrack(HealthSetPercentageTrack *this)
{
  ITrack::ITrack(this, HealthSetPercentageTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<HealthSetPercentageTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&HealthSetPercentageTrack::`vftable;
  this->m_fHealthPercentage = 100.0;
}

// File Line: 419
// RVA: 0x1495930
__int64 dynamic_initializer_for__ObjectReferenceTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ObjectReferenceTrack", 0xFFFFFFFF);
  ObjectReferenceTrack::sClassNameUID = result;
  return result;
}

// File Line: 428
// RVA: 0x2DFF50
void __fastcall ObjectReferenceTrack::ObjectReferenceTrack(ObjectReferenceTrack *this)
{
  ITrack::ITrack(this, ObjectReferenceTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<ObjectReferenceTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ObjectReferenceTrack::`vftable;
  this->m_PropertySetName = UFG::gNullQSymbol;
}

// File Line: 441
// RVA: 0x1495910
__int64 dynamic_initializer_for__ObjectCreateTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ObjectCreateTrack", 0xFFFFFFFF);
  ObjectCreateTrack::sClassNameUID = result;
  return result;
}

// File Line: 450
// RVA: 0x2DFF00
void __fastcall ObjectCreateTrack::ObjectCreateTrack(ObjectCreateTrack *this)
{
  ITrack::ITrack(this, ObjectCreateTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<ObjectCreateTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ObjectCreateTrack::`vftable;
  this->m_PropertySetName = UFG::gNullQSymbol;
}

// File Line: 463
// RVA: 0x14958F0
__int64 dynamic_initializer_for__ObjectCreateFromPropertiesTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ObjectCreateFromPropertiesTrack", 0xFFFFFFFF);
  ObjectCreateFromPropertiesTrack::sClassNameUID = result;
  return result;
}

// File Line: 476
// RVA: 0x2DFEA0
void __fastcall ObjectCreateFromPropertiesTrack::ObjectCreateFromPropertiesTrack(ObjectCreateFromPropertiesTrack *this)
{
  ITrack::ITrack(this, ObjectCreateFromPropertiesTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<ObjectCreateFromPropertiesTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ObjectCreateFromPropertiesTrack::`vftable;
  this->m_PropertyName = UFG::gNullQSymbol;
  this->m_SpawnAtBone = 0;
  this->m_BoneName = UFG::gNullQSymbolUC;
}

// File Line: 498
// RVA: 0x14955F0
__int64 dynamic_initializer_for__HideTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HideTrack", 0xFFFFFFFF);
  HideTrack::sClassNameUID = result;
  return result;
}

// File Line: 504
// RVA: 0x2DF990
void __fastcall HideTrack::HideTrack(HideTrack *this)
{
  ITrack::ITrack(this, HideTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<HideTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&HideTrack::`vftable;
}

// File Line: 516
// RVA: 0x1496790
__int64 dynamic_initializer_for__UnhideTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UnhideTrack", 0xFFFFFFFF);
  UnhideTrack::sClassNameUID = result;
  return result;
}

// File Line: 522
// RVA: 0x2E22E0
void __fastcall UnhideTrack::UnhideTrack(UnhideTrack *this)
{
  ITrack::ITrack(this, UnhideTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<UnhideTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&UnhideTrack::`vftable;
}

// File Line: 537
// RVA: 0x1495650
__int64 dynamic_initializer_for__InputSignalFilterTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InputSignalFilterTrack", 0xFFFFFFFF);
  InputSignalFilterTrack::sClassNameUID = result;
  return result;
}

// File Line: 569
// RVA: 0x2DFA70
void __fastcall InputSignalFilterTrack::InputSignalFilterTrack(InputSignalFilterTrack *this)
{
  ITrack::ITrack(this, InputSignalFilterTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<InputSignalFilterTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&InputSignalFilterTrack::`vftable;
  *(_WORD *)&this->mFloatInputSignal.mValue = 0;
  this->mInputTargetType.mValue = 1;
  *(_QWORD *)&this->mOutputTargetType.mValue = 1i64;
  this->mAmplify = 1.0;
  *(_QWORD *)&this->mGain = 1045220557i64;
  *(_QWORD *)&this->mSignalMaxValue = 1065353216i64;
  *(_WORD *)&this->mInitializeValue = 1;
}

// File Line: 597
// RVA: 0x1495670
__int64 dynamic_initializer_for__InputSignalLerpFilterTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InputSignalLerpFilterTrack", 0xFFFFFFFF);
  InputSignalLerpFilterTrack::sClassNameUID = result;
  return result;
}

// File Line: 627
// RVA: 0x2DFAF0
void __fastcall InputSignalLerpFilterTrack::InputSignalLerpFilterTrack(InputSignalLerpFilterTrack *this)
{
  ITrack::ITrack(this, InputSignalLerpFilterTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<InputSignalLerpFilterTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&InputSignalLerpFilterTrack::`vftable;
  *(_WORD *)&this->mFloatInputSignal.mValue = 0;
  this->mInputTargetType.mValue = 1;
  this->mOutputTargetType.mValue = 1;
  *(_QWORD *)&this->mGain = 1045220557i64;
  *(_QWORD *)&this->mSignalMaxInputValue = 1065353216i64;
  *(_QWORD *)&this->mSignalMaxValue = 1065353216i64;
  this->mInitializeValue = 1;
}

// File Line: 653
// RVA: 0x1495630
__int64 dynamic_initializer_for__InputEnableMappingTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InputEnableMappingTrack", 0xFFFFFFFF);
  InputEnableMappingTrack::sClassNameUID = result;
  return result;
}

// File Line: 662
// RVA: 0x2DFA20
void __fastcall InputEnableMappingTrack::InputEnableMappingTrack(InputEnableMappingTrack *this)
{
  ITrack::ITrack(this, InputEnableMappingTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<InputEnableMappingTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&InputEnableMappingTrack::`vftable;
  *(_WORD *)&this->m_bOnFoot = 257;
}

// File Line: 680
// RVA: 0x1495DD0
__int64 dynamic_initializer_for__ReadControllerInputTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ReadControllerInputTrack", 0xFFFFFFFF);
  ReadControllerInputTrack::sClassNameUID = result;
  return result;
}

// File Line: 683
// RVA: 0x2E0C20
void __fastcall ReadControllerInputTrack::ReadControllerInputTrack(ReadControllerInputTrack *this)
{
  ITrack::ITrack(this, ReadControllerInputTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<ReadControllerInputTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ReadControllerInputTrack::`vftable;
}

// File Line: 700
// RVA: 0x2DF850
void __fastcall HealthRegenRateTrack::HealthRegenRateTrack(HealthRegenRateTrack *this)
{
  ITrack::ITrack(this, HealthRegenRateTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<HealthRegenRateTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&HealthRegenRateTrack::`vftable;
  this->m_PlayerOnly = 1;
  this->m_RegenRate = 16.0;
}

// File Line: 703
// RVA: 0x1495570
__int64 dynamic_initializer_for__HealthRegenRateTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HealthRegenRateTrack", 0xFFFFFFFF);
  HealthRegenRateTrack::sClassNameUID = result;
  return result;
}

// File Line: 725
// RVA: 0x2DF8A0
void __fastcall HealthRegenerateTrack::HealthRegenerateTrack(HealthRegenerateTrack *this)
{
  ITrack::ITrack(this, HealthRegenerateTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<HealthRegenerateTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&HealthRegenerateTrack::`vftable;
  this->m_PlayerOnly = 1;
  this->m_RegenRate = 16.0;
}

// File Line: 728
// RVA: 0x1495590
__int64 dynamic_initializer_for__HealthRegenerateTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HealthRegenerateTrack", 0xFFFFFFFF);
  HealthRegenerateTrack::sClassNameUID = result;
  return result;
}

// File Line: 749
// RVA: 0x2DF8F0
void __fastcall HealthReplenishInstantTrack::HealthReplenishInstantTrack(HealthReplenishInstantTrack *this)
{
  ITrack::ITrack(this, HealthReplenishInstantTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<HealthReplenishInstantTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&HealthReplenishInstantTrack::`vftable;
  this->m_PlayerOnly = 1;
}

// File Line: 752
// RVA: 0x14955B0
__int64 dynamic_initializer_for__HealthReplenishInstantTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HealthReplenishInstantTrack", 0xFFFFFFFF);
  HealthReplenishInstantTrack::sClassNameUID = result;
  return result;
}

// File Line: 769
// RVA: 0x1495ED0
__int64 dynamic_initializer_for__SetOpeningBranchTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SetOpeningBranchTrack", 0xFFFFFFFF);
  SetOpeningBranchTrack::sClassNameUID = result;
  return result;
}

// File Line: 776
// RVA: 0x2E0DF0
void __fastcall SetOpeningBranchTrack::SetOpeningBranchTrack(SetOpeningBranchTrack *this)
{
  NodeRefTrack<SetOpeningBranchTask>::NodeRefTrack<SetOpeningBranchTask>(this, SetOpeningBranchTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&SetOpeningBranchTrack::`vftable;
  this->m_bUseRootContext = 0;
}

