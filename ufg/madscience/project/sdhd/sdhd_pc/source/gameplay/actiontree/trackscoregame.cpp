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
  LocomotionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, LocomotionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<LocomotionTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&LocomotionTrack::`vftable';
  v1->mTurnRate = 0.034906585;
  v1->mActiveRange = 3.1415927;
  v1->mMaster = 1;
}

// File Line: 44
// RVA: 0x2E4190
void __fastcall LocomotionTrack::~LocomotionTrack(LocomotionTrack *this)
{
  LocomotionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&LocomotionTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
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
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  Locomotion2Track *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, Locomotion2Track::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<Locomotion2Task>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&Locomotion2Track::`vftable';
  v1->mActiveRange = 3.1415927;
  v1->mMaxAngularVel = 0.034906585;
  v1->mPositionGain = 50.0;
  v1->mVelocityGain = 10.0;
  *(_WORD *)&v1->mPreserveLeanParam = 0;
  v1->mMaster = 1;
}

// File Line: 82
// RVA: 0x2E40B0
void __fastcall Locomotion2Track::~Locomotion2Track(Locomotion2Track *this)
{
  Locomotion2Track *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Locomotion2Track::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
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
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  LocomotionParamTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, LocomotionParamTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<LocomotionParamTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&LocomotionParamTrack::`vftable';
  *(_QWORD *)&v1->mRotationInput = 0i64;
  *(_QWORD *)&v1->mRotationAccel = 0i64;
  v1->mMaster = 0;
  v1->mTimeEnd = -1.0;
}

// File Line: 122
// RVA: 0x2E4120
void __fastcall LocomotionParamTrack::~LocomotionParamTrack(LocomotionParamTrack *this)
{
  LocomotionParamTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&LocomotionParamTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
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
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  TimeWarpTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TimeWarpTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TimeWarpTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TimeWarpTrack::`vftable';
  v1->mWarpFactor = 1.0;
  v1->mCheckPlayerOnly = 1;
  *(_QWORD *)&v1->mBlendTime = 0i64;
  *(_QWORD *)&v1->m_audioTagId[1] = 0i64;
  v1->m_audioTagUID[1] = 0;
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
  HandleDamageTrack *v1; // rdi

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, HandleDamageTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<HandleDamageTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&HandleDamageTrack::`vftable';
  v1->mDamageMultiplyer.text.mOffset = 1i64;
  BinString::Set(&v1->mDamageMultiplyer.text, &customWorldMapCaption);
  v1->mDamageMultiplyer.expression.mOffset = 0i64;
  v1->mDamageMultiplyer.value = 100;
  v1->mFaceAttacker = 1;
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
  StimulusTrack *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, StimulusTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<StimulusTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&StimulusTrack::`vftable';
  v1->mActivationType.mValue = 0;
  v1->mSourceTargetType = 1;
  v1->mMaxDuration = -1.0;
  v1->mTargetType = 0;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mOffset.x = UFG::qVector3::msZero.x;
  v1->mOffset.y = v2;
  v1->mOffset.z = v3;
  v1->mStimulusType.mValue = 0;
  v1->mIsTargeted = 0;
}

// File Line: 376
// RVA: 0x2E5430
void __fastcall StimulusTrack::~StimulusTrack(StimulusTrack *this)
{
  StimulusTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&StimulusTrack::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
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
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  HealthSetPercentageTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, HealthSetPercentageTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<HealthSetPercentageTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&HealthSetPercentageTrack::`vftable';
  v1->m_fHealthPercentage = 100.0;
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
  ObjectReferenceTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ObjectReferenceTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ObjectReferenceTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ObjectReferenceTrack::`vftable';
  v1->m_PropertySetName = UFG::gNullQSymbol;
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
  ObjectCreateTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ObjectCreateTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ObjectCreateTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ObjectCreateTrack::`vftable';
  v1->m_PropertySetName = UFG::gNullQSymbol;
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
  ObjectCreateFromPropertiesTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ObjectCreateFromPropertiesTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ObjectCreateFromPropertiesTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ObjectCreateFromPropertiesTrack::`vftable';
  v1->m_PropertyName = UFG::gNullQSymbol;
  v1->m_SpawnAtBone = 0;
  v1->m_BoneName = UFG::gNullQSymbolUC;
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
  HideTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, HideTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<HideTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&HideTrack::`vftable';
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
  UnhideTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, UnhideTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<UnhideTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&UnhideTrack::`vftable';
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
  InputSignalFilterTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, InputSignalFilterTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<InputSignalFilterTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&InputSignalFilterTrack::`vftable';
  *(_WORD *)&v1->mFloatInputSignal.mValue = 0;
  v1->mInputTargetType.mValue = 1;
  *(_QWORD *)&v1->mOutputTargetType.mValue = 1i64;
  v1->mAmplify = 1.0;
  *(_QWORD *)&v1->mGain = 1045220557i64;
  *(_QWORD *)&v1->mSignalMaxValue = 1065353216i64;
  *(_WORD *)&v1->mInitializeValue = 1;
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
  InputSignalLerpFilterTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, InputSignalLerpFilterTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<InputSignalLerpFilterTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&InputSignalLerpFilterTrack::`vftable';
  *(_WORD *)&v1->mFloatInputSignal.mValue = 0;
  v1->mInputTargetType.mValue = 1;
  v1->mOutputTargetType.mValue = 1;
  *(_QWORD *)&v1->mGain = 1045220557i64;
  *(_QWORD *)&v1->mSignalMaxInputValue = 1065353216i64;
  *(_QWORD *)&v1->mSignalMaxValue = 1065353216i64;
  v1->mInitializeValue = 1;
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
  InputEnableMappingTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, InputEnableMappingTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<InputEnableMappingTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&InputEnableMappingTrack::`vftable';
  *(_WORD *)&v1->m_bOnFoot = 257;
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
  ReadControllerInputTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ReadControllerInputTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ReadControllerInputTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ReadControllerInputTrack::`vftable';
}

// File Line: 700
// RVA: 0x2DF850
void __fastcall HealthRegenRateTrack::HealthRegenRateTrack(HealthRegenRateTrack *this)
{
  HealthRegenRateTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, HealthRegenRateTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<HealthRegenRateTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&HealthRegenRateTrack::`vftable';
  v1->m_PlayerOnly = 1;
  v1->m_RegenRate = 16.0;
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
  HealthRegenerateTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, HealthRegenerateTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<HealthRegenerateTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&HealthRegenerateTrack::`vftable';
  v1->m_PlayerOnly = 1;
  v1->m_RegenRate = 16.0;
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
  HealthReplenishInstantTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, HealthReplenishInstantTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<HealthReplenishInstantTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&HealthReplenishInstantTrack::`vftable';
  v1->m_PlayerOnly = 1;
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
  SetOpeningBranchTrack *v1; // rbx

  v1 = this;
  NodeRefTrack<SetOpeningBranchTask>::NodeRefTrack<SetOpeningBranchTask>(
    (NodeRefTrack<SetOpeningBranchTask> *)&this->vfptr,
    SetOpeningBranchTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SetOpeningBranchTrack::`vftable';
  v1->m_bUseRootContext = 0;
}

