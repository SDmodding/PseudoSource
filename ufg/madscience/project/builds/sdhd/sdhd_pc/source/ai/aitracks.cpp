// File Line: 25
// RVA: 0x14B6E50
__int64 dynamic_initializer_for__movementTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&movementTypeEnum, UFG::MoveTypeNames, 4, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__movementTypeEnum__);
}

// File Line: 26
// RVA: 0x14B8F80
__int64 dynamic_initializer_for__refineGoalModifierEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&refineGoalModifierEnum, UFG::RefineGoalModifierNames, 3, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__refineGoalModifierEnum__);
}

// File Line: 35
// RVA: 0x14AE520
__int64 dynamic_initializer_for__PerformScriptCommandTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PerformScriptCommandTrack", 0xFFFFFFFF);
  PerformScriptCommandTrack::sClassNameUID = result;
  return result;
}

// File Line: 40
// RVA: 0x3314E0
void __fastcall PerformScriptCommandTrack::PerformScriptCommandTrack(PerformScriptCommandTrack *this)
{
  ITrack::ITrack(this, PerformScriptCommandTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<PerformScriptCommandTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&PerformScriptCommandTrack::`vftable;
}

// File Line: 45
// RVA: 0x33A310
void __fastcall PerformScriptCommandTrack::~PerformScriptCommandTrack(PerformScriptCommandTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&PerformScriptCommandTrack::`vftable;
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

// File Line: 60
// RVA: 0x14AE960
__int64 dynamic_initializer_for__WanderTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("WanderTrack", 0xFFFFFFFF);
  WanderTrack::sClassNameUID = result;
  return result;
}

// File Line: 66
// RVA: 0x332B60
void __fastcall WanderTrack::WanderTrack(WanderTrack *this)
{
  ITrack::ITrack(this, WanderTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<WanderTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&WanderTrack::`vftable;
  this->m_DefaultConstraintRadius = 500.0;
}

// File Line: 71
// RVA: 0x33BA50
void __fastcall WanderTrack::~WanderTrack(WanderTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&WanderTrack::`vftable;
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

// File Line: 112
// RVA: 0x14B6E20
__int64 dynamic_initializer_for__interiorExteriorModeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &interiorExteriorModeEnum,
    FleeTrackInteriorExteriorModeNames,
    3,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__interiorExteriorModeEnum__);
}

// File Line: 114
// RVA: 0x14ADE60
__int64 dynamic_initializer_for__FleeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FleeTrack", 0xFFFFFFFF);
  FleeTrack::sClassNameUID = result;
  return result;
}

// File Line: 124
// RVA: 0x32E640
void __fastcall FleeTrack::FleeTrack(FleeTrack *this)
{
  ITrack::ITrack(this, FleeTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<FleeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&FleeTrack::`vftable;
  this->m_MoveType.mValue = 3;
  this->m_ActionPath.mPath.mCount = 0;
  this->m_ActionPath.mPath.mData.mOffset = 0i64;
  this->m_InteriorExteriorMode.mValue = 0;
  this->mMaster = 1;
  this->m_ActionRequestForWhenStill = gActionRequest_Cower.m_EnumValue;
  this->m_MaxDistance = 15.0;
  this->m_AllowedOnRoads = 0;
}

// File Line: 134
// RVA: 0x336C70
void __fastcall FleeTrack::~FleeTrack(FleeTrack *this)
{
  ActionPath *p_m_ActionPath; // rdi
  __int64 mOffset; // rax
  __int64 v4; // rax
  char *v5; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v7; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&FleeTrack::`vftable;
  p_m_ActionPath = &this->m_ActionPath;
  if ( this->m_ActionPath.mPath.mCount >= 0 )
  {
    mOffset = this->m_ActionPath.mPath.mData.mOffset;
    if ( mOffset && (UFG::qOffset64<ActionID *> *)((char *)&p_m_ActionPath->mPath.mData + mOffset) )
    {
      v4 = this->m_ActionPath.mPath.mData.mOffset;
      if ( v4 )
        v5 = (char *)&this->m_ActionPath.mPath.mData + v4;
      else
        v5 = 0i64;
      operator delete[](v5);
    }
    p_m_ActionPath->mPath.mData.mOffset = 0i64;
    p_m_ActionPath->mPath.mCount &= 0x80000000;
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (this->mMasterRate.text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v7 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v7 != BinString::sEmptyString )
      operator delete[](v7);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 161
// RVA: 0x14ADF80
__int64 dynamic_initializer_for__HangOutTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HangOutTrack", 0xFFFFFFFF);
  HangOutTrack::sClassNameUID = result;
  return result;
}

// File Line: 166
// RVA: 0x32F6D0
void __fastcall HangOutTrack::HangOutTrack(HangOutTrack *this)
{
  ITrack::ITrack(this, HangOutTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<HangOutTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&HangOutTrack::`vftable;
}

// File Line: 171
// RVA: 0x3380E0
void __fastcall HangOutTrack::~HangOutTrack(HangOutTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&HangOutTrack::`vftable;
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

// File Line: 185
// RVA: 0x14AE100
__int64 dynamic_initializer_for__IdleTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("IdleTrack", 0xFFFFFFFF);
  IdleTrack::sClassNameUID = result;
  return result;
}

// File Line: 190
// RVA: 0x32FCB0
void __fastcall IdleTrack::IdleTrack(IdleTrack *this)
{
  ITrack::ITrack(this, IdleTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<IdleTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&IdleTrack::`vftable;
}

// File Line: 195
// RVA: 0x338860
void __fastcall IdleTrack::~IdleTrack(IdleTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&IdleTrack::`vftable;
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

// File Line: 208
// RVA: 0x14ADE00
__int64 dynamic_initializer_for__FacialRequestTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FacialRequestTrack", 0xFFFFFFFF);
  FacialRequestTrack::sClassNameUID = result;
  return result;
}

// File Line: 220
// RVA: 0x32E160
void __fastcall FacialRequestTrack::FacialRequestTrack(FacialRequestTrack *this)
{
  ITrack::ITrack(this, FacialRequestTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<FacialRequestTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&FacialRequestTrack::`vftable;
  *(_DWORD *)&this->m_FacialRequest.mValue = 0;
  this->m_PressEveryFrame = 1;
}

// File Line: 224
// RVA: 0x336760
void __fastcall FacialRequestTrack::~FacialRequestTrack(FacialRequestTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&FacialRequestTrack::`vftable;
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

// File Line: 241
// RVA: 0x14AD9A0
__int64 dynamic_initializer_for__ActionRequestTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActionRequestTrack", 0xFFFFFFFF);
  ActionRequestTrack::sClassNameUID = result;
  return result;
}

// File Line: 253
// RVA: 0x32C2F0
void __fastcall ActionRequestTrack::ActionRequestTrack(ActionRequestTrack *this)
{
  ITrack::ITrack(this, ActionRequestTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<ActionRequestTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestTrack::`vftable;
  this->m_ActionRequest.mValue = gActionRequest_Action.m_EnumValue;
  this->m_RequestState.mValue = 0;
  this->m_PressEveryFrame = 1;
}

// File Line: 257
// RVA: 0x334F80
void __fastcall ActionRequestTrack::~ActionRequestTrack(ActionRequestTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestTrack::`vftable;
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

// File Line: 275
// RVA: 0x14AD980
__int64 dynamic_initializer_for__ActionRequestClearTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActionRequestClearTrack", 0xFFFFFFFF);
  ActionRequestClearTrack::sClassNameUID = result;
  return result;
}

// File Line: 283
// RVA: 0x32C220
void __fastcall ActionRequestClearTrack::ActionRequestClearTrack(ActionRequestClearTrack *this)
{
  ITrack::ITrack(this, ActionRequestClearTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<ActionRequestClearTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestClearTrack::`vftable;
  this->m_ActionRequest.mValue = gActionRequest_Action.m_EnumValue;
}

// File Line: 287
// RVA: 0x334E80
void __fastcall ActionRequestClearTrack::~ActionRequestClearTrack(ActionRequestClearTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestClearTrack::`vftable;
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

// File Line: 305
// RVA: 0x14AD880
__int64 dynamic_initializer_for__AIObjectiveTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIObjectiveTrack", 0xFFFFFFFF);
  AIObjectiveTrack::sClassNameUID = result;
  return result;
}

// File Line: 311
// RVA: 0x32B8A0
void __fastcall AIObjectiveTrack::AIObjectiveTrack(AIObjectiveTrack *this)
{
  ITrack::ITrack(this, AIObjectiveTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AIObjectiveTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AIObjectiveTrack::`vftable;
  this->m_AIObjective.mValue = 0;
  this->mTimeBegin = -1.0;
}

// File Line: 318
// RVA: 0x3344A0
void __fastcall AIObjectiveTrack::~AIObjectiveTrack(AIObjectiveTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AIObjectiveTrack::`vftable;
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

// File Line: 332
// RVA: 0x14AE920
__int64 dynamic_initializer_for__UsePOITrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UsePOITrack", 0xFFFFFFFF);
  UsePOITrack::sClassNameUID = result;
  return result;
}

// File Line: 339
// RVA: 0x332920
void __fastcall UsePOITrack::UsePOITrack(UsePOITrack *this)
{
  ITrack::ITrack(this, UsePOITrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<UsePOITask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&UsePOITrack::`vftable;
  this->m_LatchTimeout = 10.0;
}

// File Line: 344
// RVA: 0x33B830
void __fastcall UsePOITrack::~UsePOITrack(UsePOITrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&UsePOITrack::`vftable;
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

// File Line: 359
// RVA: 0x14AE480
__int64 dynamic_initializer_for__POIBeginTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("POIBeginTrack", 0xFFFFFFFF);
  POIBeginTrack::sClassNameUID = result;
  return result;
}

// File Line: 362
// RVA: 0x330D00
void __fastcall POIBeginTrack::POIBeginTrack(POIBeginTrack *this)
{
  ITrack::ITrack(this, POIBeginTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<POIBeginTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&POIBeginTrack::`vftable;
}

// File Line: 366
// RVA: 0x339960
void __fastcall POIBeginTrack::~POIBeginTrack(POIBeginTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&POIBeginTrack::`vftable;
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

// File Line: 379
// RVA: 0x14B2DA0
__int64 dynamic_initializer_for__collisionAvoidanceEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &collisionAvoidanceEnum,
    UFG::CollisionAvoidanceTypeNames,
    9,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__collisionAvoidanceEnum__);
}

// File Line: 380
// RVA: 0x14B6DE0
__int64 dynamic_initializer_for__gotoModifierEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gotoModifierEnum, UFG::GotoModifierNames, 2, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gotoModifierEnum__);
}

// File Line: 381
// RVA: 0x14B2DD0
__int64 dynamic_initializer_for__computeTargetPointModifierEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &computeTargetPointModifierEnum,
    UFG::ComputeTargetPointModifierNames,
    5,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__computeTargetPointModifierEnum__);
}

// File Line: 383
// RVA: 0x14ADB40
__int64 dynamic_initializer_for__CollisionAvoidanceTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CollisionAvoidanceTrack", 0xFFFFFFFF);
  CollisionAvoidanceTrack::sClassNameUID = result;
  return result;
}

// File Line: 406
// RVA: 0x32D390
void __fastcall CollisionAvoidanceTrack::CollisionAvoidanceTrack(CollisionAvoidanceTrack *this)
{
  ITrack::ITrack(this, CollisionAvoidanceTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CollisionAvoidanceTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CollisionAvoidanceTrack::`vftable;
  *(_DWORD *)&this->m_CollisionAvoidanceType.mValue = 16908288;
  this->m_Courtesy = 1.0;
  this->m_QueuingDelay = 5.0;
  this->m_ExtraGap = 0.1;
}

// File Line: 413
// RVA: 0x335BF0
void __fastcall CollisionAvoidanceTrack::~CollisionAvoidanceTrack(CollisionAvoidanceTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&CollisionAvoidanceTrack::`vftable;
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

// File Line: 434
// RVA: 0x14AE500
__int64 dynamic_initializer_for__Pathing_OverrideCollisionAvoidanceTypeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("Pathing_OverrideCollisionAvoidanceTypeTrack", 0xFFFFFFFF);
  Pathing_OverrideCollisionAvoidanceTypeTrack::sClassNameUID = result;
  return result;
}

// File Line: 440
// RVA: 0x331040
void __fastcall Pathing_OverrideCollisionAvoidanceTypeTrack::Pathing_OverrideCollisionAvoidanceTypeTrack(
        Pathing_OverrideCollisionAvoidanceTypeTrack *this)
{
  ITrack::ITrack(this, Pathing_OverrideCollisionAvoidanceTypeTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<Pathing_OverrideCollisionAvoidanceTypeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&Pathing_OverrideCollisionAvoidanceTypeTrack::`vftable;
  this->m_CollisionAvoidanceType.mValue = 0;
}

// File Line: 445
// RVA: 0x339E50
void __fastcall Pathing_OverrideCollisionAvoidanceTypeTrack::~Pathing_OverrideCollisionAvoidanceTypeTrack(
        Pathing_OverrideCollisionAvoidanceTypeTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&Pathing_OverrideCollisionAvoidanceTypeTrack::`vftable;
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

// File Line: 460
// RVA: 0x14AE4E0
__int64 dynamic_initializer_for__PathfindToTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PathfindToTargetTrack", 0xFFFFFFFF);
  PathfindToTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 479
// RVA: 0x330F60
void __fastcall PathfindToTargetTrack::PathfindToTargetTrack(PathfindToTargetTrack *this)
{
  ITrack::ITrack(this, PathfindToTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<PathfindToTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&PathfindToTargetTrack::`vftable;
  *(_DWORD *)&this->m_TargetType.mValue = 16843030;
  this->m_ConstrainToSidewalks.mValue = 1;
  this->m_SuppressFreerunning = 0;
  *(_QWORD *)&this->m_TargetOffSet.x = 0i64;
  this->m_TargetOffSet.z = 0.0;
  this->m_GoalReachedThreshold = 0.5;
}

// File Line: 485
// RVA: 0x339D50
void __fastcall PathfindToTargetTrack::~PathfindToTargetTrack(PathfindToTargetTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&PathfindToTargetTrack::`vftable;
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

// File Line: 507
// RVA: 0x14AE4C0
__int64 dynamic_initializer_for__PathfindAwayFromTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PathfindAwayFromTargetTrack", 0xFFFFFFFF);
  PathfindAwayFromTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 520
// RVA: 0x330E40
void __fastcall PathfindAwayFromTargetTrack::PathfindAwayFromTargetTrack(PathfindAwayFromTargetTrack *this)
{
  ITrack::ITrack(this, PathfindAwayFromTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<PathfindAwayFromTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&PathfindAwayFromTargetTrack::`vftable;
  this->m_TargetType.mValue = 22;
  this->m_MoveType.mValue = 3;
  this->m_ActionPath.mPath.mCount = 0;
  this->m_ActionPath.mPath.mData.mOffset = 0i64;
  this->mMaster = 1;
  this->m_ActionRequestForWhenStill = gActionRequest_Cower.m_EnumValue;
  this->m_MaxDistance = 15.0;
  this->m_AllowedOnRoads = 0;
}

// File Line: 530
// RVA: 0x339B50
void __fastcall PathfindAwayFromTargetTrack::~PathfindAwayFromTargetTrack(PathfindAwayFromTargetTrack *this)
{
  ActionPath *p_m_ActionPath; // rdi
  __int64 mOffset; // rax
  __int64 v4; // rax
  char *v5; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v7; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&PathfindAwayFromTargetTrack::`vftable;
  p_m_ActionPath = &this->m_ActionPath;
  if ( this->m_ActionPath.mPath.mCount >= 0 )
  {
    mOffset = this->m_ActionPath.mPath.mData.mOffset;
    if ( mOffset && (UFG::qOffset64<ActionID *> *)((char *)&p_m_ActionPath->mPath.mData + mOffset) )
    {
      v4 = this->m_ActionPath.mPath.mData.mOffset;
      if ( v4 )
        v5 = (char *)&this->m_ActionPath.mPath.mData + v4;
      else
        v5 = 0i64;
      operator delete[](v5);
    }
    p_m_ActionPath->mPath.mData.mOffset = 0i64;
    p_m_ActionPath->mPath.mCount &= 0x80000000;
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (this->mMasterRate.text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v7 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v7 != BinString::sEmptyString )
      operator delete[](v7);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 557
// RVA: 0x14AE320
__int64 dynamic_initializer_for__MoveDirectlyToTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MoveDirectlyToTargetTrack", 0xFFFFFFFF);
  MoveDirectlyToTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 571
// RVA: 0x3306E0
void __fastcall MoveDirectlyToTargetTrack::MoveDirectlyToTargetTrack(MoveDirectlyToTargetTrack *this)
{
  ITrack::ITrack(this, MoveDirectlyToTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<MoveDirectlyToTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&MoveDirectlyToTargetTrack::`vftable;
  *(_DWORD *)&this->m_TargetType.mValue = 16843030;
  this->m_GoalReachedThresholdXY = 0.5;
  this->m_GoalReachedThresholdZ = 1.5;
}

// File Line: 578
// RVA: 0x339390
void __fastcall MoveDirectlyToTargetTrack::~MoveDirectlyToTargetTrack(MoveDirectlyToTargetTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&MoveDirectlyToTargetTrack::`vftable;
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

// File Line: 599
// RVA: 0x14ADE80
__int64 dynamic_initializer_for__FollowTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FollowTargetTrack", 0xFFFFFFFF);
  FollowTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 620
// RVA: 0x32E7E0
void __fastcall FollowTargetTrack::FollowTargetTrack(FollowTargetTrack *this)
{
  ITrack::ITrack(this, FollowTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<FollowTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&FollowTargetTrack::`vftable;
  *(_WORD *)&this->m_TargetType.mValue = -227;
  this->m_ConstrainToSidewalks.mValue = 1;
  this->mMaster = 1;
  this->m_StopAtRadius = 3.0;
  this->m_StopAtZDifference = 1.5;
  this->m_GoAtRadius = 6.0;
  this->m_GoAtZDifference = 3.0;
  this->m_FollowOffset = 2.0;
  this->m_StopAtTarget = 1;
  this->m_MinReactionTime = 0.1;
  this->m_MaxReactionTime = 1.0;
  this->m_DistanceToTeleportAt = 20.0;
  this->m_DistanceToTeleportTo = 5.0;
}

// File Line: 637
// RVA: 0x336F90
void __fastcall FollowTargetTrack::~FollowTargetTrack(FollowTargetTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&FollowTargetTrack::`vftable;
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

// File Line: 664
// RVA: 0x14ADB00
__int64 dynamic_initializer_for__CircleAroundCombatantsTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CircleAroundCombatantsTrack", 0xFFFFFFFF);
  CircleAroundCombatantsTrack::sClassNameUID = result;
  return result;
}

// File Line: 683
// RVA: 0x32D250
void __fastcall CircleAroundCombatantsTrack::CircleAroundCombatantsTrack(CircleAroundCombatantsTrack *this)
{
  ITrack::ITrack(this, CircleAroundCombatantsTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CircleAroundCombatantsTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CircleAroundCombatantsTrack::`vftable;
  this->m_TargetType.mValue = 33;
  *(_WORD *)&this->m_StopAtDesiredPosition = 257;
  this->m_ConstrainToSidewalks.mValue = 1;
  this->m_MinDistanceFromCentre = 3.0;
  this->m_DesiredDistanceFromCentre = 5.0;
  this->m_MaxDistanceFromCentre = 10.0;
  this->m_Hysteresis = 2.0;
  this->m_CloseEnoughToDesiredPosition = 1.0;
  this->m_ReservationRadius = 3.0;
  this->m_ReservationRadiusSquared = 9.0;
  this->m_ActionRequestForWhenStill = gActionRequest_INVALID.m_EnumValue;
}

// File Line: 698
// RVA: 0x335AF0
void __fastcall CircleAroundCombatantsTrack::~CircleAroundCombatantsTrack(CircleAroundCombatantsTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&CircleAroundCombatantsTrack::`vftable;
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

// File Line: 734
// RVA: 0x14B2D70
__int64 dynamic_initializer_for__beginOrDonePlayingEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&beginOrDonePlayingEnum, gBeginOrDonePlayingStrings, 4, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__beginOrDonePlayingEnum__);
}

// File Line: 738
// RVA: 0x14AD960
__int64 dynamic_initializer_for__ActionRequestAndWaitUntilPlayingTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ActionRequestAndWaitUntilPlayingTrack", 0xFFFFFFFF);
  ActionRequestAndWaitUntilPlayingTrack::sClassNameUID = result;
  return result;
}

// File Line: 749
// RVA: 0x32C160
void __fastcall ActionRequestAndWaitUntilPlayingTrack::ActionRequestAndWaitUntilPlayingTrack(
        ActionRequestAndWaitUntilPlayingTrack *this)
{
  ITrack::ITrack(this, ActionRequestAndWaitUntilPlayingTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<ActionRequestAndWaitUntilPlayingTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestAndWaitUntilPlayingTrack::`vftable;
  this->m_BeginOrDonePlaying.mValue = 2;
  this->m_ActionRequest = gActionRequest_Action.m_EnumValue;
  this->m_CheckSpawns = 0;
  this->m_Timeout = -1.0;
}

// File Line: 757
// RVA: 0x334D80
void __fastcall ActionRequestAndWaitUntilPlayingTrack::~ActionRequestAndWaitUntilPlayingTrack(
        ActionRequestAndWaitUntilPlayingTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestAndWaitUntilPlayingTrack::`vftable;
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

// File Line: 776
// RVA: 0x14AE400
__int64 dynamic_initializer_for__NodeRequestTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NodeRequestTrack", 0xFFFFFFFF);
  NodeRequestTrack::sClassNameUID = result;
  return result;
}

// File Line: 783
// RVA: 0x330B60
void __fastcall NodeRequestTrack::NodeRequestTrack(NodeRequestTrack *this)
{
  ITrack::ITrack(this, NodeRequestTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<NodeRequestTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestTrack::`vftable;
  this->m_NodeName.mUID = -1;
}

// File Line: 788
// RVA: 0x339840
void __fastcall NodeRequestTrack::~NodeRequestTrack(NodeRequestTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestTrack::`vftable;
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

// File Line: 803
// RVA: 0x14AE3A0
__int64 dynamic_initializer_for__NodeRequestAndWaitUntilPlayingTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("NodeRequestAndWaitUntilPlayingTrack", 0xFFFFFFFF);
  NodeRequestAndWaitUntilPlayingTrack::sClassNameUID = result;
  return result;
}

// File Line: 813
// RVA: 0x330AA0
void __fastcall NodeRequestAndWaitUntilPlayingTrack::NodeRequestAndWaitUntilPlayingTrack(
        NodeRequestAndWaitUntilPlayingTrack *this)
{
  ITrack::ITrack(this, NodeRequestAndWaitUntilPlayingTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<NodeRequestAndWaitUntilPlayingTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestAndWaitUntilPlayingTrack::`vftable;
  *(_WORD *)&this->m_CheckSpawns = 512;
  this->m_Timeout = -1.0;
}

// File Line: 820
// RVA: 0x339750
void __fastcall NodeRequestAndWaitUntilPlayingTrack::~NodeRequestAndWaitUntilPlayingTrack(
        NodeRequestAndWaitUntilPlayingTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestAndWaitUntilPlayingTrack::`vftable;
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

// File Line: 838
// RVA: 0x14B2E00
__int64 dynamic_initializer_for__emotionEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&emotionEnum, UFG::AIEmotionNames, 13, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__emotionEnum__);
}

// File Line: 840
// RVA: 0x14AE680
__int64 dynamic_initializer_for__SetCurrentEmotionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SetCurrentEmotionTrack", 0xFFFFFFFF);
  SetCurrentEmotionTrack::sClassNameUID = result;
  return result;
}

// File Line: 846
// RVA: 0x331BD0
void __fastcall SetCurrentEmotionTrack::SetCurrentEmotionTrack(SetCurrentEmotionTrack *this)
{
  ITrack::ITrack(this, SetCurrentEmotionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<SetCurrentEmotionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetCurrentEmotionTrack::`vftable;
  this->m_CurrentEmotion.mValue = 0;
}

// File Line: 851
// RVA: 0x33AC30
void __fastcall SetCurrentEmotionTrack::~SetCurrentEmotionTrack(SetCurrentEmotionTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&SetCurrentEmotionTrack::`vftable;
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

// File Line: 867
// RVA: 0x14AE6C0
__int64 dynamic_initializer_for__SetFacialEmotionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SetFacialEmotionTrack", 0xFFFFFFFF);
  SetFacialEmotionTrack::sClassNameUID = result;
  return result;
}

// File Line: 873
// RVA: 0x331D60
void __fastcall SetFacialEmotionTrack::SetFacialEmotionTrack(SetFacialEmotionTrack *this)
{
  ITrack::ITrack(this, SetFacialEmotionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<SetFacialEmotionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetFacialEmotionTrack::`vftable;
  this->m_FacialEmotion.mValue = 0;
}

// File Line: 878
// RVA: 0x33ADC0
void __fastcall SetFacialEmotionTrack::~SetFacialEmotionTrack(SetFacialEmotionTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&SetFacialEmotionTrack::`vftable;
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

// File Line: 893
// RVA: 0x14AE8E0
__int64 dynamic_initializer_for__TurnToFaceTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TurnToFaceTargetTrack", 0xFFFFFFFF);
  TurnToFaceTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 900
// RVA: 0x332830
void __fastcall TurnToFaceTargetTrack::TurnToFaceTargetTrack(TurnToFaceTargetTrack *this)
{
  ITrack::ITrack(this, TurnToFaceTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TurnToFaceTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TurnToFaceTargetTrack::`vftable;
  this->m_TargetType.mValue = 33;
  this->m_FacingClosenessRadians = 0.17453294;
}

// File Line: 906
// RVA: 0x33B730
void __fastcall TurnToFaceTargetTrack::~TurnToFaceTargetTrack(TurnToFaceTargetTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&TurnToFaceTargetTrack::`vftable;
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

// File Line: 921
// RVA: 0x14AE0E0
__int64 dynamic_initializer_for__HeadTrackTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HeadTrackTargetTrack", 0xFFFFFFFF);
  HeadTrackTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 929
// RVA: 0x32FBB0
void __fastcall HeadTrackTargetTrack::HeadTrackTargetTrack(HeadTrackTargetTrack *this)
{
  float y; // xmm1_4
  float z; // xmm2_4

  ITrack::ITrack(this, HeadTrackTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<HeadTrackTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&HeadTrackTargetTrack::`vftable;
  this->m_TargetType.mValue = 22;
  this->m_MaxHorizontalHalfAngle = 3.1415927;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_Offset.x = UFG::qVector3::msZero.x;
  this->m_Offset.y = y;
  this->m_Offset.z = z;
}

// File Line: 936
// RVA: 0x338760
void __fastcall HeadTrackTargetTrack::~HeadTrackTargetTrack(HeadTrackTargetTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&HeadTrackTargetTrack::`vftable;
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

// File Line: 952
// RVA: 0x14AE300
__int64 dynamic_initializer_for__MinimumDurationTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MinimumDurationTrack", 0xFFFFFFFF);
  MinimumDurationTrack::sClassNameUID = result;
  return result;
}

// File Line: 964
// RVA: 0x330580
void __fastcall MinimumDurationTrack::MinimumDurationTrack(MinimumDurationTrack *this)
{
  ITrack::ITrack(this, MinimumDurationTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<MinimumDurationTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&MinimumDurationTrack::`vftable;
  this->mMinLength.text.mOffset = 1i64;
  BinString::Set(&this->mMinLength.text, &customCaption);
  this->mMinLength.expression.mOffset = 0i64;
  this->mMinLength.value = 0.0;
  this->mMaxLength.text.mOffset = 1i64;
  BinString::Set(&this->mMaxLength.text, &customCaption);
  this->mMaxLength.expression.mOffset = 0i64;
  this->mMaxLength.value = 0.0;
  this->mMultiplier.text.mOffset = 1i64;
  BinString::Set(&this->mMultiplier.text, &customCaption);
  this->mMultiplier.expression.mOffset = 0i64;
  this->mMultiplier.value = 1.0;
  this->mMaster = 1;
}

// File Line: 969
// RVA: 0x339190
void __fastcall MinimumDurationTrack::~MinimumDurationTrack(MinimumDurationTrack *this)
{
  ExpressionParameterFloat *p_mMultiplier; // rcx
  char *v3; // rcx
  ExpressionParameterFloat *p_mMaxLength; // rcx
  char *v5; // rcx
  ExpressionParameterFloat *p_mMinLength; // rcx
  char *v7; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v9; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&MinimumDurationTrack::`vftable;
  p_mMultiplier = &this->mMultiplier;
  if ( (p_mMultiplier->text.mOffset & 1) != 0 && (p_mMultiplier->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mMultiplier + (p_mMultiplier->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  p_mMaxLength = &this->mMaxLength;
  if ( (this->mMaxLength.text.mOffset & 1) != 0 && (p_mMaxLength->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v5 = (char *)p_mMaxLength + (p_mMaxLength->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v5 != BinString::sEmptyString )
      operator delete[](v5);
  }
  p_mMinLength = &this->mMinLength;
  if ( (this->mMinLength.text.mOffset & 1) != 0 && (p_mMinLength->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v7 = (char *)p_mMinLength + (p_mMinLength->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v7 != BinString::sEmptyString )
      operator delete[](v7);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (this->mMasterRate.text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v9 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v9 != BinString::sEmptyString )
      operator delete[](v9);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 995
// RVA: 0x14ADCA0
__int64 dynamic_initializer_for__DebugDrawMyPositionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DebugDrawMyPositionTrack", 0xFFFFFFFF);
  DebugDrawMyPositionTrack::sClassNameUID = result;
  return result;
}

// File Line: 1009
// RVA: 0x3360D0
void __fastcall DebugDrawMyPositionTrack::~DebugDrawMyPositionTrack(DebugDrawMyPositionTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DebugDrawMyPositionTrack::`vftable;
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

// File Line: 1025
// RVA: 0x14ADCC0
__int64 dynamic_initializer_for__DebugDrawMyTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DebugDrawMyTargetTrack", 0xFFFFFFFF);
  DebugDrawMyTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 1042
// RVA: 0x336210
void __fastcall DebugDrawMyTargetTrack::~DebugDrawMyTargetTrack(DebugDrawMyTargetTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&DebugDrawMyTargetTrack::`vftable;
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

// File Line: 1059
// RVA: 0x14AE5E0
__int64 dynamic_initializer_for__RunLaterallyFromTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RunLaterallyFromTargetTrack", 0xFFFFFFFF);
  RunLaterallyFromTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 1076
// RVA: 0x3318A0
void __fastcall RunLaterallyFromTargetTrack::RunLaterallyFromTargetTrack(RunLaterallyFromTargetTrack *this)
{
  ITrack::ITrack(this, RunLaterallyFromTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RunLaterallyFromTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RunLaterallyFromTargetTrack::`vftable;
  *(_DWORD *)&this->m_TargetType.mValue = 66337;
  this->m_DistanceToRun = 5.0;
  this->m_MaxLateralDistanceToDive = 2.0;
  this->m_MaxTimeToImpactToDive = 0.60000002;
  this->m_MinTimeToImpactToDive = 0.40000001;
  this->m_ActionRequestForPressAgainstWall = gActionRequest_Cower.m_EnumValue;
  this->m_DistanceFromLastValidPositionToPressAgainstWall = 0.25;
}

// File Line: 1089
// RVA: 0x33A8D0
void __fastcall RunLaterallyFromTargetTrack::~RunLaterallyFromTargetTrack(RunLaterallyFromTargetTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RunLaterallyFromTargetTrack::`vftable;
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

// File Line: 1114
// RVA: 0x14AD920
__int64 dynamic_initializer_for__AITargetingParametersTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AITargetingParametersTrack", 0xFFFFFFFF);
  AITargetingParametersTrack::sClassNameUID = result;
  return result;
}

// File Line: 1122
// RVA: 0x32C000
void __fastcall AITargetingParametersTrack::AITargetingParametersTrack(AITargetingParametersTrack *this)
{
  ITrack::ITrack(this, AITargetingParametersTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AITargetingParametersTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AITargetingParametersTrack::`vftable;
  this->m_OtherTargetType.mValue = 29;
  this->m_MaxDistanceFromOtherTarget = 5.0;
  this->m_DistanceFromOtherTargetHysteresis = 2.0;
}

// File Line: 1129
// RVA: 0x334C00
void __fastcall AITargetingParametersTrack::~AITargetingParametersTrack(AITargetingParametersTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AITargetingParametersTrack::`vftable;
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

// File Line: 1146
// RVA: 0x14AD4A0
__int64 dynamic_initializer_for__AIAddSupplementaryAttackTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIAddSupplementaryAttackTargetTrack", 0xFFFFFFFF);
  AIAddSupplementaryAttackTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 1152
// RVA: 0x32A8D0
void __fastcall AIAddSupplementaryAttackTargetTrack::AIAddSupplementaryAttackTargetTrack(
        AIAddSupplementaryAttackTargetTrack *this)
{
  ITrack::ITrack(this, AIAddSupplementaryAttackTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AIAddSupplementaryAttackTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AIAddSupplementaryAttackTargetTrack::`vftable;
  this->m_TargetType.mValue = eTARGET_TYPE_ATTACKER;
}

// File Line: 1157
// RVA: 0x333A30
void __fastcall AIAddSupplementaryAttackTargetTrack::~AIAddSupplementaryAttackTargetTrack(
        AIAddSupplementaryAttackTargetTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AIAddSupplementaryAttackTargetTrack::`vftable;
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

// File Line: 1173
// RVA: 0x14AD900
__int64 dynamic_initializer_for__AIRemoveSupplementaryAttackTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIRemoveSupplementaryAttackTargetTrack", 0xFFFFFFFF);
  AIRemoveSupplementaryAttackTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 1179
// RVA: 0x32BCF0
void __fastcall AIRemoveSupplementaryAttackTargetTrack::AIRemoveSupplementaryAttackTargetTrack(
        AIRemoveSupplementaryAttackTargetTrack *this)
{
  ITrack::ITrack(this, AIRemoveSupplementaryAttackTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AIRemoveSupplementaryAttackTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AIRemoveSupplementaryAttackTargetTrack::`vftable;
  this->m_TargetType.mValue = 2;
}

// File Line: 1184
// RVA: 0x3349A0
void __fastcall AIRemoveSupplementaryAttackTargetTrack::~AIRemoveSupplementaryAttackTargetTrack(
        AIRemoveSupplementaryAttackTargetTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AIRemoveSupplementaryAttackTargetTrack::`vftable;
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

// File Line: 1199
// RVA: 0x14ADEE0
__int64 dynamic_initializer_for__GetInFormationTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("GetInFormationTrack", 0xFFFFFFFF);
  GetInFormationTrack::sClassNameUID = result;
  return result;
}

// File Line: 1202
// RVA: 0x32EEC0
void __fastcall GetInFormationTrack::GetInFormationTrack(GetInFormationTrack *this)
{
  ITrack::ITrack(this, GetInFormationTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<GetInFormationTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&GetInFormationTrack::`vftable;
  this->m_pGetInFormationCondition = 0i64;
}

// File Line: 1207
// RVA: 0x3377B0
void __fastcall GetInFormationTrack::~GetInFormationTrack(GetInFormationTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&GetInFormationTrack::`vftable;
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

// File Line: 1212
// RVA: 0x383190
void __fastcall GetInFormationTrack::ResolveReferences(GetInFormationTrack *this, ActionNode *action_node)
{
  const char *v3; // rax
  const char *v4; // rsi
  __int64 v5; // rbx
  const char *v6; // r14
  GetInFormationCondition *v7; // rdi

  v3 = action_node->vfptr[3].GetClassname(action_node);
  v4 = v3;
  if ( v3 )
  {
    v5 = 0i64;
    v6 = &v3[*((_QWORD *)v3 + 5) + 40];
    if ( (*((_DWORD *)v3 + 8) & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v7 = (GetInFormationCondition *)&v6[8 * v5 + *(_QWORD *)&v6[8 * v5]];
        if ( v7->Condition::Expression::IMemberMap::vfptr->GetClassNameUID(v7) == GetInFormationCondition::sClassNameUID )
          this->m_pGetInFormationCondition = v7;
        v5 = (unsigned int)(v5 + 1);
      }
      while ( (unsigned int)v5 < (*((_DWORD *)v4 + 8) & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 1246
// RVA: 0x14ADF20
__int64 dynamic_initializer_for__GetInPedFormationTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("GetInPedFormationTrack", 0xFFFFFFFF);
  GetInPedFormationTrack::sClassNameUID = result;
  return result;
}

// File Line: 1249
// RVA: 0x32F270
void __fastcall GetInPedFormationTrack::GetInPedFormationTrack(GetInPedFormationTrack *this)
{
  ITrack::ITrack(this, GetInPedFormationTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<GetInPedFormationTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&GetInPedFormationTrack::`vftable;
  this->m_pGetInPedFormationCondition = 0i64;
}

// File Line: 1254
// RVA: 0x337C80
void __fastcall GetInPedFormationTrack::~GetInPedFormationTrack(GetInPedFormationTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&GetInPedFormationTrack::`vftable;
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

// File Line: 1259
// RVA: 0x3832A0
void __fastcall GetInPedFormationTrack::ResolveReferences(GetInPedFormationTrack *this, ActionNode *action_node)
{
  const char *v3; // rax
  const char *v4; // rsi
  __int64 v5; // rbx
  const char *v6; // r14
  GetInPedFormationCondition *v7; // rdi

  v3 = action_node->vfptr[3].GetClassname(action_node);
  v4 = v3;
  if ( v3 )
  {
    v5 = 0i64;
    v6 = &v3[*((_QWORD *)v3 + 5) + 40];
    if ( (*((_DWORD *)v3 + 8) & 0x7FFFFFFF) != 0 )
    {
      do
      {
        v7 = (GetInPedFormationCondition *)&v6[8 * v5 + *(_QWORD *)&v6[8 * v5]];
        if ( v7->Condition::Expression::IMemberMap::vfptr->GetClassNameUID(v7) == GetInPedFormationCondition::sClassNameUID )
          this->m_pGetInPedFormationCondition = v7;
        v5 = (unsigned int)(v5 + 1);
      }
      while ( (unsigned int)v5 < (*((_DWORD *)v4 + 8) & 0x7FFFFFFFu) );
    }
  }
}

// File Line: 1296
// RVA: 0x14AE140
__int64 dynamic_initializer_for__InvalidateFormationPositionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InvalidateFormationPositionTrack", 0xFFFFFFFF);
  InvalidateFormationPositionTrack::sClassNameUID = result;
  return result;
}

// File Line: 1303
// RVA: 0x330030
void __fastcall InvalidateFormationPositionTrack::InvalidateFormationPositionTrack(
        InvalidateFormationPositionTrack *this)
{
  ITrack::ITrack(this, InvalidateFormationPositionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<InvalidateFormationPositionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&InvalidateFormationPositionTrack::`vftable;
  this->m_TargetType.mValue = 22;
}

// File Line: 1308
// RVA: 0x338D70
void __fastcall InvalidateFormationPositionTrack::~InvalidateFormationPositionTrack(
        InvalidateFormationPositionTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&InvalidateFormationPositionTrack::`vftable;
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

// File Line: 1322
// RVA: 0x14AE260
__int64 dynamic_initializer_for__JustPerformedRunningAttackTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("JustPerformedRunningAttackTrack", 0xFFFFFFFF);
  JustPerformedRunningAttackTrack::sClassNameUID = result;
  return result;
}

// File Line: 1329
// RVA: 0x330310
void __fastcall JustPerformedRunningAttackTrack::JustPerformedRunningAttackTrack(JustPerformedRunningAttackTrack *this)
{
  ITrack::ITrack(this, JustPerformedRunningAttackTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<JustPerformedRunningAttackTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&JustPerformedRunningAttackTrack::`vftable;
  this->m_TargetType.mValue = 22;
  this->mTimeBegin = -1.0;
}

// File Line: 1336
// RVA: 0x339010
void __fastcall JustPerformedRunningAttackTrack::~JustPerformedRunningAttackTrack(
        JustPerformedRunningAttackTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&JustPerformedRunningAttackTrack::`vftable;
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

// File Line: 1351
// RVA: 0x14B2E30
__int64 dynamic_initializer_for__formationFacingTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&formationFacingTypeEnum, UFG::FormationFacingTypeNames, 2, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__formationFacingTypeEnum__);
}

// File Line: 1352
// RVA: 0x14B2E60
__int64 dynamic_initializer_for__formationMovementDirectionEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &formationMovementDirectionEnum,
    UFG::FormationMovementDirectionNames,
    4,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__formationMovementDirectionEnum__);
}

// File Line: 1354
// RVA: 0x14AE5C0
__int64 dynamic_initializer_for__RequestFormationPositionChangeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RequestFormationPositionChangeTrack", 0xFFFFFFFF);
  RequestFormationPositionChangeTrack::sClassNameUID = result;
  return result;
}

// File Line: 1367
// RVA: 0x331760
void __fastcall RequestFormationPositionChangeTrack::RequestFormationPositionChangeTrack(
        RequestFormationPositionChangeTrack *this)
{
  ITrack::ITrack(this, RequestFormationPositionChangeTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<RequestFormationPositionChangeTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&RequestFormationPositionChangeTrack::`vftable;
  *(_DWORD *)&this->m_TargetType.mValue = 33620758;
  this->m_AbsolutePosition = 0;
}

// File Line: 1376
// RVA: 0x33A750
void __fastcall RequestFormationPositionChangeTrack::~RequestFormationPositionChangeTrack(
        RequestFormationPositionChangeTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&RequestFormationPositionChangeTrack::`vftable;
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

// File Line: 1397
// RVA: 0x14AE2A0
__int64 dynamic_initializer_for__LeaveGroupTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("LeaveGroupTrack", 0xFFFFFFFF);
  LeaveGroupTrack::sClassNameUID = result;
  return result;
}

// File Line: 1400
// RVA: 0x3303E0
void __fastcall LeaveGroupTrack::LeaveGroupTrack(LeaveGroupTrack *this)
{
  ITrack::ITrack(this, LeaveGroupTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<LeaveGroupTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&LeaveGroupTrack::`vftable;
}

// File Line: 1404
// RVA: 0x339120
void __fastcall LeaveGroupTrack::~LeaveGroupTrack(LeaveGroupTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&LeaveGroupTrack::`vftable;
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

// File Line: 1417
// RVA: 0x14AE660
__int64 dynamic_initializer_for__SelectSuitableVehicleTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SelectSuitableVehicleTrack", 0xFFFFFFFF);
  SelectSuitableVehicleTrack::sClassNameUID = result;
  return result;
}

// File Line: 1427
// RVA: 0x331AF0
void __fastcall SelectSuitableVehicleTrack::SelectSuitableVehicleTrack(SelectSuitableVehicleTrack *this)
{
  ITrack::ITrack(this, SelectSuitableVehicleTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<SelectSuitableVehicleTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&SelectSuitableVehicleTrack::`vftable;
  this->m_MaxSearchRadius = 3.0;
  this->m_IgnoreMeshTest = 0;
  this->m_FilterClassSymbol.mUID = -1;
}

// File Line: 1431
// RVA: 0x33AB30
void __fastcall SelectSuitableVehicleTrack::~SelectSuitableVehicleTrack(SelectSuitableVehicleTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&SelectSuitableVehicleTrack::`vftable;
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

// File Line: 1452
// RVA: 0x14ADE40
__int64 dynamic_initializer_for__FireWeaponTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("FireWeaponTrack", 0xFFFFFFFF);
  FireWeaponTrack::sClassNameUID = result;
  return result;
}

// File Line: 1477
// RVA: 0x32E360
void __fastcall FireWeaponTrack::FireWeaponTrack(FireWeaponTrack *this)
{
  ITrack::ITrack(this, FireWeaponTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<FireWeaponTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&FireWeaponTrack::`vftable;
  this->mMinNumShots.text.mOffset = 1i64;
  BinString::Set(&this->mMinNumShots.text, &customCaption);
  this->mMinNumShots.expression.mOffset = 0i64;
  this->mMinNumShots.value = 0;
  this->mMaxNumShots.text.mOffset = 1i64;
  BinString::Set(&this->mMaxNumShots.text, &customCaption);
  this->mMaxNumShots.expression.mOffset = 0i64;
  this->mMaxNumShots.value = 0;
  this->mMinTimeBetweenShots.text.mOffset = 1i64;
  BinString::Set(&this->mMinTimeBetweenShots.text, &customCaption);
  this->mMinTimeBetweenShots.expression.mOffset = 0i64;
  this->mMinTimeBetweenShots.value = -1.0;
  this->mMaxTimeBetweenShots.text.mOffset = 1i64;
  BinString::Set(&this->mMaxTimeBetweenShots.text, &customCaption);
  this->mMaxTimeBetweenShots.expression.mOffset = 0i64;
  this->mMaxTimeBetweenShots.value = -1.0;
  this->mMinTimeToHoldTrigger.text.mOffset = 1i64;
  BinString::Set(&this->mMinTimeToHoldTrigger.text, &customCaption);
  this->mMinTimeToHoldTrigger.expression.mOffset = 0i64;
  this->mMinTimeToHoldTrigger.value = 0.0;
  this->mMaxTimeToHoldTrigger.text.mOffset = 1i64;
  BinString::Set(&this->mMaxTimeToHoldTrigger.text, &customCaption);
  this->mMaxTimeToHoldTrigger.expression.mOffset = 0i64;
  this->mMaxTimeToHoldTrigger.value = 0.0;
  this->mTimeMultiplierBetween.text.mOffset = 1i64;
  BinString::Set(&this->mTimeMultiplierBetween.text, &customCaption);
  this->mTimeMultiplierBetween.expression.mOffset = 0i64;
  this->mTimeMultiplierBetween.value = 1.0;
  this->mTimeMultiplierHold.text.mOffset = 1i64;
  BinString::Set(&this->mTimeMultiplierHold.text, &customCaption);
  this->mTimeMultiplierHold.expression.mOffset = 0i64;
  this->mTimeMultiplierHold.value = 1.0;
  this->m_HoldTrigger = 0;
  this->mMaster = 1;
  this->m_ActionRequest = gActionRequest_Fire.m_EnumValue;
}

// File Line: 1484
// RVA: 0x336940
void __fastcall FireWeaponTrack::~FireWeaponTrack(FireWeaponTrack *this)
{
  ExpressionParameterFloat *p_mTimeMultiplierHold; // rcx
  char *v3; // rcx
  ExpressionParameterFloat *p_mTimeMultiplierBetween; // rcx
  char *v5; // rcx
  ExpressionParameterFloat *p_mMaxTimeToHoldTrigger; // rcx
  char *v7; // rcx
  ExpressionParameterFloat *p_mMinTimeToHoldTrigger; // rcx
  char *v9; // rcx
  ExpressionParameterFloat *p_mMaxTimeBetweenShots; // rcx
  char *v11; // rcx
  ExpressionParameterFloat *p_mMinTimeBetweenShots; // rcx
  char *v13; // rcx
  ExpressionParameterInt *p_mMaxNumShots; // rcx
  char *v15; // rcx
  ExpressionParameterInt *p_mMinNumShots; // rcx
  char *v17; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v19; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&FireWeaponTrack::`vftable;
  p_mTimeMultiplierHold = &this->mTimeMultiplierHold;
  if ( (p_mTimeMultiplierHold->text.mOffset & 1) != 0
    && (p_mTimeMultiplierHold->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v3 = (char *)p_mTimeMultiplierHold + (p_mTimeMultiplierHold->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v3 != BinString::sEmptyString )
      operator delete[](v3);
  }
  p_mTimeMultiplierBetween = &this->mTimeMultiplierBetween;
  if ( (this->mTimeMultiplierBetween.text.mOffset & 1) != 0
    && (p_mTimeMultiplierBetween->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v5 = (char *)p_mTimeMultiplierBetween + (p_mTimeMultiplierBetween->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v5 != BinString::sEmptyString )
      operator delete[](v5);
  }
  p_mMaxTimeToHoldTrigger = &this->mMaxTimeToHoldTrigger;
  if ( (this->mMaxTimeToHoldTrigger.text.mOffset & 1) != 0
    && (p_mMaxTimeToHoldTrigger->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v7 = (char *)p_mMaxTimeToHoldTrigger + (p_mMaxTimeToHoldTrigger->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v7 != BinString::sEmptyString )
      operator delete[](v7);
  }
  p_mMinTimeToHoldTrigger = &this->mMinTimeToHoldTrigger;
  if ( (this->mMinTimeToHoldTrigger.text.mOffset & 1) != 0
    && (p_mMinTimeToHoldTrigger->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v9 = (char *)p_mMinTimeToHoldTrigger + (p_mMinTimeToHoldTrigger->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v9 != BinString::sEmptyString )
      operator delete[](v9);
  }
  p_mMaxTimeBetweenShots = &this->mMaxTimeBetweenShots;
  if ( (this->mMaxTimeBetweenShots.text.mOffset & 1) != 0
    && (p_mMaxTimeBetweenShots->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v11 = (char *)p_mMaxTimeBetweenShots + (p_mMaxTimeBetweenShots->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v11 != BinString::sEmptyString )
      operator delete[](v11);
  }
  p_mMinTimeBetweenShots = &this->mMinTimeBetweenShots;
  if ( (this->mMinTimeBetweenShots.text.mOffset & 1) != 0
    && (p_mMinTimeBetweenShots->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v13 = (char *)p_mMinTimeBetweenShots + (p_mMinTimeBetweenShots->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v13 != BinString::sEmptyString )
      operator delete[](v13);
  }
  p_mMaxNumShots = &this->mMaxNumShots;
  if ( (this->mMaxNumShots.text.mOffset & 1) != 0 && (p_mMaxNumShots->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v15 = (char *)p_mMaxNumShots + (p_mMaxNumShots->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v15 != BinString::sEmptyString )
      operator delete[](v15);
  }
  p_mMinNumShots = &this->mMinNumShots;
  if ( (this->mMinNumShots.text.mOffset & 1) != 0 && (p_mMinNumShots->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v17 = (char *)p_mMinNumShots + (p_mMinNumShots->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v17 != BinString::sEmptyString )
      operator delete[](v17);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (this->mMasterRate.text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v19 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v19 != BinString::sEmptyString )
      operator delete[](v19);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 1525
// RVA: 0x14AD740
__int64 dynamic_initializer_for__AICoverSearchTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICoverSearchTrack", 0xFFFFFFFF);
  AICoverSearchTrack::sClassNameUID = result;
  return result;
}

// File Line: 1571
// RVA: 0x32B2F0
void __fastcall AICoverSearchTrack::AICoverSearchTrack(AICoverSearchTrack *this)
{
  ITrack::ITrack(this, AICoverSearchTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AICoverSearchTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverSearchTrack::`vftable;
  this->m_eTargetType.mValue = 0;
  this->m_fMaxDistance = 10.0;
  this->m_fDistanceWeight = 1.0;
  this->m_fDistanceToTargetWeight = 1.0;
  this->m_fMinDistanceToTarget = 5.0;
  this->m_fMaxDistanceToTarget = 15.0;
  this->m_fSweetSpotWeight = 1.0;
  *(_QWORD *)&this->m_fMaxAngleFromSweetSpot = 1057360530i64;
  this->m_fDistanceFromAlliesWeight = 8.0;
  this->m_fRadialSpreadFromAlliesWeight = 8.0;
  this->m_fLineOfSightWeight = 1.0;
  this->m_bLineOfSightRequired = 0;
  this->m_fDirectLineOfSightWeight = -1.0;
  *(_DWORD *)&this->m_bSkipPathfind = 0;
  this->m_fMinimumPriority = -1.0;
  this->m_fPathWeight = 0.2;
}

// File Line: 1575
// RVA: 0x334210
void __fastcall AICoverSearchTrack::~AICoverSearchTrack(AICoverSearchTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverSearchTrack::`vftable;
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

// File Line: 1619
// RVA: 0x14AD6C0
__int64 dynamic_initializer_for__AICoverFaceCoverObjectTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICoverFaceCoverObjectTrack", 0xFFFFFFFF);
  AICoverFaceCoverObjectTrack::sClassNameUID = result;
  return result;
}

// File Line: 1623
// RVA: 0x32B000
void __fastcall AICoverFaceCoverObjectTrack::AICoverFaceCoverObjectTrack(AICoverFaceCoverObjectTrack *this)
{
  ITrack::ITrack(this, AICoverFaceCoverObjectTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AICoverFaceCoverObjectTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverFaceCoverObjectTrack::`vftable;
}

// File Line: 1627
// RVA: 0x333DC0
void __fastcall AICoverFaceCoverObjectTrack::~AICoverFaceCoverObjectTrack(AICoverFaceCoverObjectTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverFaceCoverObjectTrack::`vftable;
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

// File Line: 1643
// RVA: 0x14AD6A0
__int64 dynamic_initializer_for__AICoverClearCoverObjectTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICoverClearCoverObjectTrack", 0xFFFFFFFF);
  AICoverClearCoverObjectTrack::sClassNameUID = result;
  return result;
}

// File Line: 1650
// RVA: 0x32AEB0
void __fastcall AICoverClearCoverObjectTrack::AICoverClearCoverObjectTrack(AICoverClearCoverObjectTrack *this)
{
  ITrack::ITrack(this, AICoverClearCoverObjectTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AICoverClearCoverObjectTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverClearCoverObjectTrack::`vftable;
}

// File Line: 1654
// RVA: 0x333C40
void __fastcall AICoverClearCoverObjectTrack::~AICoverClearCoverObjectTrack(AICoverClearCoverObjectTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverClearCoverObjectTrack::`vftable;
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

// File Line: 1668
// RVA: 0x14AD720
__int64 dynamic_initializer_for__AICoverLatchTargetedObjectTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICoverLatchTargetedObjectTrack", 0xFFFFFFFF);
  AICoverLatchTargetedObjectTrack::sClassNameUID = result;
  return result;
}

// File Line: 1677
// RVA: 0x32B120
void __fastcall AICoverLatchTargetedObjectTrack::AICoverLatchTargetedObjectTrack(AICoverLatchTargetedObjectTrack *this)
{
  ITrack::ITrack(this, AICoverLatchTargetedObjectTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AICoverLatchTargetedObjectTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverLatchTargetedObjectTrack::`vftable;
  this->m_eCoverComponentObject.mValue = 3;
}

// File Line: 1681
// RVA: 0x333EB0
void __fastcall AICoverLatchTargetedObjectTrack::~AICoverLatchTargetedObjectTrack(
        AICoverLatchTargetedObjectTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverLatchTargetedObjectTrack::`vftable;
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

// File Line: 1697
// RVA: 0x14AD660
__int64 dynamic_initializer_for__AICopReleaseArrestRightTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICopReleaseArrestRightTrack", 0xFFFFFFFF);
  AICopReleaseArrestRightTrack::sClassNameUID = result;
  return result;
}

// File Line: 1704
// RVA: 0x32AD80
void __fastcall AICopReleaseArrestRightTrack::AICopReleaseArrestRightTrack(AICopReleaseArrestRightTrack *this)
{
  ITrack::ITrack(this, AICopReleaseArrestRightTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AICopReleaseArrestRightTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopReleaseArrestRightTrack::`vftable;
}

// File Line: 1708
// RVA: 0x333B60
void __fastcall AICopReleaseArrestRightTrack::~AICopReleaseArrestRightTrack(AICopReleaseArrestRightTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AICopReleaseArrestRightTrack::`vftable;
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

// File Line: 1721
// RVA: 0x14AD680
__int64 dynamic_initializer_for__AICopReportInfractionTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICopReportInfractionTargetTrack", 0xFFFFFFFF);
  AICopReportInfractionTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 1730
// RVA: 0x32AE10
void __fastcall AICopReportInfractionTargetTrack::AICopReportInfractionTargetTrack(
        AICopReportInfractionTargetTrack *this)
{
  ITrack::ITrack(this, AICopReportInfractionTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AICopReportInfractionTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopReportInfractionTargetTrack::`vftable;
  this->m_TargetType.mValue = 0;
}

// File Line: 1734
// RVA: 0x333BD0
void __fastcall AICopReportInfractionTargetTrack::~AICopReportInfractionTargetTrack(
        AICopReportInfractionTargetTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AICopReportInfractionTargetTrack::`vftable;
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

// File Line: 1750
// RVA: 0x14AD540
__int64 dynamic_initializer_for__AICopApplyReducedRadiusTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AICopApplyReducedRadiusTrack", 0xFFFFFFFF);
  AICopApplyReducedRadiusTrack::sClassNameUID = result;
  return result;
}

// File Line: 1762
// RVA: 0x14AD8C0
__int64 dynamic_initializer_for__AIOverrideAvoidanceRadiusTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIOverrideAvoidanceRadiusTrack", 0xFFFFFFFF);
  AIOverrideAvoidanceRadiusTrack::sClassNameUID = result;
  return result;
}

// File Line: 1772
// RVA: 0x32BB00
void __fastcall AIOverrideAvoidanceRadiusTrack::AIOverrideAvoidanceRadiusTrack(AIOverrideAvoidanceRadiusTrack *this)
{
  ITrack::ITrack(this, AIOverrideAvoidanceRadiusTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AIOverrideAvoidanceRadiusTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AIOverrideAvoidanceRadiusTrack::`vftable;
  this->m_Radius = 1.0;
  this->m_AdjustToNavGoal = 0;
}

// File Line: 1776
// RVA: 0x334770
void __fastcall AIOverrideAvoidanceRadiusTrack::~AIOverrideAvoidanceRadiusTrack(AIOverrideAvoidanceRadiusTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AIOverrideAvoidanceRadiusTrack::`vftable;
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

// File Line: 1793
// RVA: 0x14ADF60
__int64 dynamic_initializer_for__GroupStimulusTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("GroupStimulusTrack", 0xFFFFFFFF);
  GroupStimulusTrack::sClassNameUID = result;
  return result;
}

// File Line: 1805
// RVA: 0x32F5E0
void __fastcall GroupStimulusTrack::GroupStimulusTrack(GroupStimulusTrack *this)
{
  ITrack::ITrack(this, GroupStimulusTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<GroupStimulusTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&GroupStimulusTrack::`vftable;
  this->m_StimulusType.mValue = 0;
  this->m_FactionStanding.mValue = 2;
  *(_QWORD *)&this->m_TotalPointsPropertySymbol.mUID = -1i64;
  this->m_MaxRange = 0.0;
  this->m_TotalPointsPropertySymbol = UFG::gNullQSymbol;
  this->m_CostPerCharacterPropertySymbol = UFG::gNullQSymbol;
}

// File Line: 1814
// RVA: 0x337FE0
void __fastcall GroupStimulusTrack::~GroupStimulusTrack(GroupStimulusTrack *this)
{
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v3; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&GroupStimulusTrack::`vftable;
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

// File Line: 1845
// RVA: 0x14ADA80
__int64 dynamic_initializer_for__AttackRightsScoreBonusTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackRightsScoreBonusTrack", 0xFFFFFFFF);
  AttackRightsScoreBonusTrack::sClassNameUID = result;
  return result;
}

// File Line: 1852
// RVA: 0x32CD00
void __fastcall AttackRightsScoreBonusTrack::AttackRightsScoreBonusTrack(AttackRightsScoreBonusTrack *this)
{
  ITrack::ITrack(this, AttackRightsScoreBonusTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AttackRightsScoreBonusTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsScoreBonusTrack::`vftable;
  this->m_ActionPath.mPath.mCount = 0;
  this->m_ActionPath.mPath.mData.mOffset = 0i64;
  this->m_ScoreBonus = 0.0;
}

// File Line: 1857
// RVA: 0x335580
void __fastcall AttackRightsScoreBonusTrack::~AttackRightsScoreBonusTrack(AttackRightsScoreBonusTrack *this)
{
  ActionPath *p_m_ActionPath; // rdi
  __int64 mOffset; // rax
  __int64 v4; // rax
  char *v5; // rcx
  ExpressionParameterFloat *p_mMasterRate; // rcx
  char *v7; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsScoreBonusTrack::`vftable;
  p_m_ActionPath = &this->m_ActionPath;
  if ( this->m_ActionPath.mPath.mCount >= 0 )
  {
    mOffset = this->m_ActionPath.mPath.mData.mOffset;
    if ( mOffset && (UFG::qOffset64<ActionID *> *)((char *)&p_m_ActionPath->mPath.mData + mOffset) )
    {
      v4 = this->m_ActionPath.mPath.mData.mOffset;
      if ( v4 )
        v5 = (char *)&this->m_ActionPath.mPath.mData + v4;
      else
        v5 = 0i64;
      operator delete[](v5);
    }
    p_m_ActionPath->mPath.mData.mOffset = 0i64;
    p_m_ActionPath->mPath.mCount &= 0x80000000;
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable;
  p_mMasterRate = &this->mMasterRate;
  if ( (this->mMasterRate.text.mOffset & 1) != 0 && (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v7 = (char *)p_mMasterRate + (p_mMasterRate->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v7 != BinString::sEmptyString )
      operator delete[](v7);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 1884
// RVA: 0x3324B0
void __fastcall TargetActionRequestTrack::TargetActionRequestTrack(TargetActionRequestTrack *this)
{
  ITrack::ITrack(this, TargetActionRequestTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetActionRequestTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&TargetActionRequestTrack::`vftable;
  *(_QWORD *)&this->mActionRequest = gActionRequest_Action.m_EnumValue;
}

// File Line: 1887
// RVA: 0x14AE700
__int64 dynamic_initializer_for__TargetActionRequestTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TargetActionRequestTrack", 0xFFFFFFFF);
  TargetActionRequestTrack::sClassNameUID = result;
  return result;
}

// File Line: 1906
// RVA: 0x14AE2C0
__int64 dynamic_initializer_for__LockFormationPositionToCurrentPositionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("LockFormationPositionToCurrentPositionTrack", 0xFFFFFFFF);
  LockFormationPositionToCurrentPositionTrack::sClassNameUID = result;
  return result;
}

// File Line: 1910
// RVA: 0x3304F0
void __fastcall LockFormationPositionToCurrentPositionTrack::LockFormationPositionToCurrentPositionTrack(
        LockFormationPositionToCurrentPositionTrack *this)
{
  ITrack::ITrack(this, LockFormationPositionToCurrentPositionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<LockFormationPositionToCurrentPositionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&LockFormationPositionToCurrentPositionTrack::`vftable;
}

// File Line: 1923
// RVA: 0x14ADEA0
__int64 dynamic_initializer_for__ForceUpdateTargetingTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ForceUpdateTargetingTrack", 0xFFFFFFFF);
  ForceUpdateTargetingTrack::sClassNameUID = result;
  return result;
}

// File Line: 1935
// RVA: 0x14AD9C0
__int64 dynamic_initializer_for__AddTargetAsDangerousEntityTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AddTargetAsDangerousEntityTrack", 0xFFFFFFFF);
  AddTargetAsDangerousEntityTrack::sClassNameUID = result;
  return result;
}

// File Line: 1943
// RVA: 0x32C6E0
void __fastcall AddTargetAsDangerousEntityTrack::AddTargetAsDangerousEntityTrack(AddTargetAsDangerousEntityTrack *this)
{
  ITrack::ITrack(this, AddTargetAsDangerousEntityTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AddTargetAsDangerousEntityTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AddTargetAsDangerousEntityTrack::`vftable;
  this->m_TargetType.mValue = 33;
  this->m_DangerRadius = 20.0;
}

// File Line: 1960
// RVA: 0x14AE6A0
__int64 dynamic_initializer_for__SetDriverFlagsTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SetDriverFlagsTrack", 0xFFFFFFFF);
  SetDriverFlagsTrack::sClassNameUID = result;
  return result;
}

// File Line: 1971
// RVA: 0x331C90
void __fastcall SetDriverFlagsTrack::SetDriverFlagsTrack(SetDriverFlagsTrack *this)
{
  ITrack::ITrack(this, SetDriverFlagsTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<SetDriverFlagsTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetDriverFlagsTrack::`vftable;
  *(_DWORD *)&this->m_AvoidPeds = 0;
}

// File Line: 1993
// RVA: 0x14ADAA0
__int64 dynamic_initializer_for__AttackRightsSetTimeUntilNextAttackTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackRightsSetTimeUntilNextAttackTrack", 0xFFFFFFFF);
  AttackRightsSetTimeUntilNextAttackTrack::sClassNameUID = result;
  return result;
}

// File Line: 2007
// RVA: 0x32CDB0
void __fastcall AttackRightsSetTimeUntilNextAttackTrack::AttackRightsSetTimeUntilNextAttackTrack(
        AttackRightsSetTimeUntilNextAttackTrack *this)
{
  ITrack::ITrack(this, AttackRightsSetTimeUntilNextAttackTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AttackRightsSetTimeUntilNextAttackTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsSetTimeUntilNextAttackTrack::`vftable;
  this->m_TargetType.mValue = 22;
  this->m_AttackType.mValue = 0;
  this->m_ActionPath.mPath.mCount = 0;
  this->m_ActionPath.mPath.mData.mOffset = 0i64;
  *(_QWORD *)&this->m_MinTime = 0i64;
}

// File Line: 2035
// RVA: 0x14ADA20
__int64 dynamic_initializer_for__AttackRightsClearPreviousBestAttackerTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackRightsClearPreviousBestAttackerTrack", 0xFFFFFFFF);
  AttackRightsClearPreviousBestAttackerTrack::sClassNameUID = result;
  return result;
}

// File Line: 2046
// RVA: 0x32C8B0
void __fastcall AttackRightsClearPreviousBestAttackerTrack::AttackRightsClearPreviousBestAttackerTrack(
        AttackRightsClearPreviousBestAttackerTrack *this)
{
  ITrack::ITrack(this, AttackRightsClearPreviousBestAttackerTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AttackRightsClearPreviousBestAttackerTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsClearPreviousBestAttackerTrack::`vftable;
  *(_WORD *)&this->m_TargetType.mValue = 22;
}

// File Line: 2063
// RVA: 0x14ADA60
__int64 dynamic_initializer_for__AttackRightsReSortListTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackRightsReSortListTrack", 0xFFFFFFFF);
  AttackRightsReSortListTrack::sClassNameUID = result;
  return result;
}

// File Line: 2074
// RVA: 0x32CC60
void __fastcall AttackRightsReSortListTrack::AttackRightsReSortListTrack(AttackRightsReSortListTrack *this)
{
  ITrack::ITrack(this, AttackRightsReSortListTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AttackRightsReSortListTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsReSortListTrack::`vftable;
  *(_WORD *)&this->m_TargetType.mValue = 22;
}

// File Line: 2090
// RVA: 0x14ADA00
__int64 dynamic_initializer_for__AttackRightsCancelAnyIncomingAttackTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackRightsCancelAnyIncomingAttackTrack", 0xFFFFFFFF);
  AttackRightsCancelAnyIncomingAttackTrack::sClassNameUID = result;
  return result;
}

// File Line: 2102
// RVA: 0x32C810
void __fastcall AttackRightsCancelAnyIncomingAttackTrack::AttackRightsCancelAnyIncomingAttackTrack(
        AttackRightsCancelAnyIncomingAttackTrack *this)
{
  ITrack::ITrack(this, AttackRightsCancelAnyIncomingAttackTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AttackRightsCancelAnyIncomingAttackTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsCancelAnyIncomingAttackTrack::`vftable;
  *(_WORD *)&this->m_TargetType.mValue = 22;
  this->m_DurationToCancelFor = 0.5;
}

// File Line: 2120
// RVA: 0x14ADA40
__int64 dynamic_initializer_for__AttackRightsFormationManagerFreezeRangeSwitchesTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AttackRightsFormationManagerFreezeRangeSwitchesTrack", 0xFFFFFFFF);
  AttackRightsFormationManagerFreezeRangeSwitchesTrack::sClassNameUID = result;
  return result;
}

// File Line: 2129
// RVA: 0x32CBC0
void __fastcall AttackRightsFormationManagerFreezeRangeSwitchesTrack::AttackRightsFormationManagerFreezeRangeSwitchesTrack(
        AttackRightsFormationManagerFreezeRangeSwitchesTrack *this)
{
  ITrack::ITrack(this, AttackRightsFormationManagerFreezeRangeSwitchesTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<AttackRightsFormationManagerFreezeRangeSwitchesTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsFormationManagerFreezeRangeSwitchesTrack::`vftable;
  this->m_TargetType.mValue = 22;
}

// File Line: 2144
// RVA: 0x14ADBA0
__int64 dynamic_initializer_for__CombatRegionMoveToTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CombatRegionMoveToTrack", 0xFFFFFFFF);
  CombatRegionMoveToTrack::sClassNameUID = result;
  return result;
}

// File Line: 2155
// RVA: 0x32D4D0
void __fastcall CombatRegionMoveToTrack::CombatRegionMoveToTrack(CombatRegionMoveToTrack *this)
{
  ITrack::ITrack(this, CombatRegionMoveToTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<CombatRegionMoveToTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionMoveToTrack::`vftable;
  *(_WORD *)&this->m_MoveType.mValue = 257;
  this->m_StopAtTarget = 1;
}

// File Line: 2172
// RVA: 0x14AE900
__int64 dynamic_initializer_for__UpdateHijackableVehicleTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UpdateHijackableVehicleTargetTrack", 0xFFFFFFFF);
  UpdateHijackableVehicleTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 2177
// RVA: 0x332880
void __fastcall UpdateHijackableVehicleTargetTrack::UpdateHijackableVehicleTargetTrack(
        UpdateHijackableVehicleTargetTrack *this)
{
  ITrack::ITrack(this, UpdateHijackableVehicleTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<UpdateHijackableVehicleTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&UpdateHijackableVehicleTargetTrack::`vftable;
}

// File Line: 2190
// RVA: 0x14AE340
__int64 dynamic_initializer_for__MoveToBetterAttackPositionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MoveToBetterAttackPositionTrack", 0xFFFFFFFF);
  MoveToBetterAttackPositionTrack::sClassNameUID = result;
  return result;
}

// File Line: 2204
// RVA: 0x330810
void __fastcall MoveToBetterAttackPositionTrack::MoveToBetterAttackPositionTrack(MoveToBetterAttackPositionTrack *this)
{
  ITrack::ITrack(this, MoveToBetterAttackPositionTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<MoveToBetterAttackPositionTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&MoveToBetterAttackPositionTrack::`vftable;
  this->m_TargetType.mValue = 22;
  this->m_fMinDistance = 1.0;
  this->m_fMaxDistance = 3.0;
  this->m_NumDirectionsToTest = 6;
}

// File Line: 2223
// RVA: 0x14AE360
__int64 dynamic_initializer_for__MoveToFindLineOfSightTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MoveToFindLineOfSightTrack", 0xFFFFFFFF);
  MoveToFindLineOfSightTrack::sClassNameUID = result;
  return result;
}

// File Line: 2239
// RVA: 0x330940
void __fastcall MoveToFindLineOfSightTrack::MoveToFindLineOfSightTrack(MoveToFindLineOfSightTrack *this)
{
  ITrack::ITrack(this, MoveToFindLineOfSightTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<MoveToFindLineOfSightTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&MoveToFindLineOfSightTrack::`vftable;
  *(_WORD *)&this->m_TargetType.mValue = 534;
  this->m_fMinDistance = 1.0;
  this->m_fMaxDistance = 3.0;
  this->m_NumDirectionsToTest = 6;
}

// File Line: 2257
// RVA: 0x14AE940
__int64 dynamic_initializer_for__WaitUntilAbleToPathToTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("WaitUntilAbleToPathToTargetTrack", 0xFFFFFFFF);
  WaitUntilAbleToPathToTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 2267
// RVA: 0x332A50
void __fastcall WaitUntilAbleToPathToTargetTrack::WaitUntilAbleToPathToTargetTrack(
        WaitUntilAbleToPathToTargetTrack *this)
{
  ITrack::ITrack(this, WaitUntilAbleToPathToTargetTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<WaitUntilAbleToPathToTargetTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&WaitUntilAbleToPathToTargetTrack::`vftable;
  *(_WORD *)&this->m_TargetType.mValue = 22;
}

// File Line: 2282
// RVA: 0x14AE120
__int64 dynamic_initializer_for__InteractingWithVehicleHeuristicTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InteractingWithVehicleHeuristicTrack", 0xFFFFFFFF);
  InteractingWithVehicleHeuristicTrack::sClassNameUID = result;
  return result;
}

// File Line: 2289
// RVA: 0x32FD40
void __fastcall InteractingWithVehicleHeuristicTrack::InteractingWithVehicleHeuristicTrack(
        InteractingWithVehicleHeuristicTrack *this)
{
  ITrack::ITrack(this, InteractingWithVehicleHeuristicTrack::sClassNameUID);
  this->vfptr = (Expression::IMemberMapVtbl *)&Track<InteractingWithVehicleHeuristicTask>::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&InteractingWithVehicleHeuristicTrack::`vftable;
}

// File Line: 2301
// RVA: 0x14AD500
__int64 dynamic_initializer_for__AIAwarenessEnableTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIAwarenessEnableTrack", 0xFFFFFFFF);
  AIAwarenessEnableTrack::sClassNameUID = result;
  return result;
}

// File Line: 2317
// RVA: 0x14B30A0
__int64 dynamic_initializer_for__gTargetPriorityEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &gTargetPriorityEnum,
    UFG::AIAwareness::gTargetPriorityStringList,
    3,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gTargetPriorityEnum__);
}

// File Line: 2319
// RVA: 0x14AD4E0
__int64 dynamic_initializer_for__AIAwarenessAddTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("AIAwarenessAddTargetTrack", 0xFFFFFFFF);
  AIAwarenessAddTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 2337
// RVA: 0x14AE2E0
__int64 dynamic_initializer_for__LookAtTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("LookAtTrack", 0xFFFFFFFF);
  LookAtTrack::sClassNameUID = result;
  return result;
}

// File Line: 2354
// RVA: 0x14AE880
__int64 dynamic_initializer_for__TestPathToTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("TestPathToTargetTrack", 0xFFFFFFFF);
  TestPathToTargetTrack::sClassNameUID = result;
  return result;
}

// File Line: 2377
// RVA: 0x14B2FE0
__int64 dynamic_initializer_for__gInvokeBehaviourModeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gInvokeBehaviourModeEnum, gInvokeBehaviourControlNames, 2, 0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gInvokeBehaviourModeEnum__);
}

// File Line: 2388
// RVA: 0x14B3010
__int64 dynamic_initializer_for__gInvokeBehaviourPriorityModeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &gInvokeBehaviourPriorityModeEnum,
    gInvokeBehaviourPriorityModeNames,
    5,
    0i64);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gInvokeBehaviourPriorityModeEnum__);
}

// File Line: 2391
// RVA: 0x14AE160
__int64 dynamic_initializer_for__InvokeBehaviourTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("InvokeBehaviourTrack", 0xFFFFFFFF);
  InvokeBehaviourTrack::sClassNameUID = result;
  return result;
}

// File Line: 2408
// RVA: 0x330140
void __fastcall InvokeBehaviourTrack::InvokeBehaviourTrack(InvokeBehaviourTrack *this)
{
  SpawnTrack::SpawnTrack(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&InvokeBehaviourTrack::`vftable;
  this->m_Priority = 0;
  *(_WORD *)&this->m_PriorityMode.mValue = 0;
  this->m_MaxWaitTime = -1.0;
  this->m_MaxLifeTime = -1.0;
}

