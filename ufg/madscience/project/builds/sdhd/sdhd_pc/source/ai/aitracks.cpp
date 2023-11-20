// File Line: 25
// RVA: 0x14B6E50
__int64 dynamic_initializer_for__movementTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&movementTypeEnum, UFG::MoveTypeNames, 4, 0i64);
  return atexit(dynamic_atexit_destructor_for__movementTypeEnum__);
}

// File Line: 26
// RVA: 0x14B8F80
__int64 dynamic_initializer_for__refineGoalModifierEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&refineGoalModifierEnum, UFG::RefineGoalModifierNames, 3, 0i64);
  return atexit(dynamic_atexit_destructor_for__refineGoalModifierEnum__);
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
  PerformScriptCommandTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, PerformScriptCommandTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<PerformScriptCommandTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&PerformScriptCommandTrack::`vftable';
}

// File Line: 45
// RVA: 0x33A310
void __fastcall PerformScriptCommandTrack::~PerformScriptCommandTrack(PerformScriptCommandTrack *this)
{
  PerformScriptCommandTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PerformScriptCommandTrack::`vftable';
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
  WanderTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, WanderTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<WanderTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&WanderTrack::`vftable';
  v1->m_DefaultConstraintRadius = 500.0;
}

// File Line: 71
// RVA: 0x33BA50
void __fastcall WanderTrack::~WanderTrack(WanderTrack *this)
{
  WanderTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&WanderTrack::`vftable';
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

// File Line: 112
// RVA: 0x14B6E20
__int64 dynamic_initializer_for__interiorExteriorModeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &interiorExteriorModeEnum,
    FleeTrackInteriorExteriorModeNames,
    3,
    0i64);
  return atexit(dynamic_atexit_destructor_for__interiorExteriorModeEnum__);
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
  FleeTrack *v1; // rbx
  signed __int64 v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, FleeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<FleeTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&FleeTrack::`vftable';
  v1->m_MoveType.mValue = 3;
  v2 = (signed __int64)&v1->m_ActionPath;
  *(_DWORD *)v2 = 0;
  *(_QWORD *)(v2 + 8) = 0i64;
  v1->m_InteriorExteriorMode.mValue = 0;
  v1->mMaster = 1;
  v1->m_ActionRequestForWhenStill = gActionRequest_Cower.m_EnumValue;
  v1->m_MaxDistance = 15.0;
  v1->m_AllowedOnRoads = 0;
}

// File Line: 134
// RVA: 0x336C70
void __fastcall FleeTrack::~FleeTrack(FleeTrack *this)
{
  FleeTrack *v1; // rbx
  ActionPath *v2; // rdi
  __int64 v3; // rax
  __int64 v4; // rax
  char *v5; // rcx
  ExpressionParameterFloat *v6; // rcx
  char *v7; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&FleeTrack::`vftable';
  v2 = &this->m_ActionPath;
  if ( this->m_ActionPath.mPath.mCount >= 0 )
  {
    v3 = this->m_ActionPath.mPath.mData.mOffset;
    if ( v3 && (UFG::qOffset64<ActionID *> *)((char *)&v2->mPath.mData + v3) )
    {
      v4 = this->m_ActionPath.mPath.mData.mOffset;
      if ( v4 )
        v5 = (char *)&this->m_ActionPath.mPath.mData + v4;
      else
        v5 = 0i64;
      operator delete[](v5);
    }
    v2->mPath.mData.mOffset = 0i64;
    v2->mPath.mCount &= 0x80000000;
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v6 = &v1->mMasterRate;
  if ( !(~LOBYTE(v1->mMasterRate.text.mOffset) & 1) )
  {
    if ( v6->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v7 = (char *)v6 + (v6->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v7 != BinString::sEmptyString )
        operator delete[](v7);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  HangOutTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, HangOutTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<HangOutTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&HangOutTrack::`vftable';
}

// File Line: 171
// RVA: 0x3380E0
void __fastcall HangOutTrack::~HangOutTrack(HangOutTrack *this)
{
  HangOutTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&HangOutTrack::`vftable';
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
  IdleTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, IdleTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<IdleTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&IdleTrack::`vftable';
}

// File Line: 195
// RVA: 0x338860
void __fastcall IdleTrack::~IdleTrack(IdleTrack *this)
{
  IdleTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&IdleTrack::`vftable';
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
  FacialRequestTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, FacialRequestTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<FacialRequestTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&FacialRequestTrack::`vftable';
  *(_DWORD *)&v1->m_FacialRequest.mValue = 0;
  v1->m_PressEveryFrame = 1;
}

// File Line: 224
// RVA: 0x336760
void __fastcall FacialRequestTrack::~FacialRequestTrack(FacialRequestTrack *this)
{
  FacialRequestTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&FacialRequestTrack::`vftable';
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
  ActionRequestTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ActionRequestTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ActionRequestTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestTrack::`vftable';
  v1->m_ActionRequest.mValue = gActionRequest_Action.m_EnumValue;
  v1->m_RequestState.mValue = 0;
  v1->m_PressEveryFrame = 1;
}

// File Line: 257
// RVA: 0x334F80
void __fastcall ActionRequestTrack::~ActionRequestTrack(ActionRequestTrack *this)
{
  ActionRequestTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestTrack::`vftable';
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
  ActionRequestClearTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ActionRequestClearTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ActionRequestClearTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestClearTrack::`vftable';
  v1->m_ActionRequest.mValue = gActionRequest_Action.m_EnumValue;
}

// File Line: 287
// RVA: 0x334E80
void __fastcall ActionRequestClearTrack::~ActionRequestClearTrack(ActionRequestClearTrack *this)
{
  ActionRequestClearTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestClearTrack::`vftable';
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
  AIObjectiveTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AIObjectiveTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AIObjectiveTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIObjectiveTrack::`vftable';
  v1->m_AIObjective.mValue = 0;
  v1->mTimeBegin = -1.0;
}

// File Line: 318
// RVA: 0x3344A0
void __fastcall AIObjectiveTrack::~AIObjectiveTrack(AIObjectiveTrack *this)
{
  AIObjectiveTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AIObjectiveTrack::`vftable';
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
  UsePOITrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, UsePOITrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<UsePOITask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&UsePOITrack::`vftable';
  v1->m_LatchTimeout = 10.0;
}

// File Line: 344
// RVA: 0x33B830
void __fastcall UsePOITrack::~UsePOITrack(UsePOITrack *this)
{
  UsePOITrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&UsePOITrack::`vftable';
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
  POIBeginTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, POIBeginTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<POIBeginTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&POIBeginTrack::`vftable';
}

// File Line: 366
// RVA: 0x339960
void __fastcall POIBeginTrack::~POIBeginTrack(POIBeginTrack *this)
{
  POIBeginTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&POIBeginTrack::`vftable';
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

// File Line: 379
// RVA: 0x14B2DA0
__int64 dynamic_initializer_for__collisionAvoidanceEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &collisionAvoidanceEnum,
    UFG::CollisionAvoidanceTypeNames,
    9,
    0i64);
  return atexit(dynamic_atexit_destructor_for__collisionAvoidanceEnum__);
}

// File Line: 380
// RVA: 0x14B6DE0
__int64 dynamic_initializer_for__gotoModifierEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gotoModifierEnum, UFG::GotoModifierNames, 2, 0i64);
  return atexit(dynamic_atexit_destructor_for__gotoModifierEnum__);
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
  return atexit(dynamic_atexit_destructor_for__computeTargetPointModifierEnum__);
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
  CollisionAvoidanceTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CollisionAvoidanceTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CollisionAvoidanceTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&CollisionAvoidanceTrack::`vftable';
  *(_DWORD *)&v1->m_CollisionAvoidanceType.mValue = 16908288;
  v1->m_Courtesy = 1.0;
  v1->m_QueuingDelay = 5.0;
  v1->m_ExtraGap = 0.1;
}

// File Line: 413
// RVA: 0x335BF0
void __fastcall CollisionAvoidanceTrack::~CollisionAvoidanceTrack(CollisionAvoidanceTrack *this)
{
  CollisionAvoidanceTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CollisionAvoidanceTrack::`vftable';
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
void __fastcall Pathing_OverrideCollisionAvoidanceTypeTrack::Pathing_OverrideCollisionAvoidanceTypeTrack(Pathing_OverrideCollisionAvoidanceTypeTrack *this)
{
  Pathing_OverrideCollisionAvoidanceTypeTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, Pathing_OverrideCollisionAvoidanceTypeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<Pathing_OverrideCollisionAvoidanceTypeTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&Pathing_OverrideCollisionAvoidanceTypeTrack::`vftable';
  v1->m_CollisionAvoidanceType.mValue = 0;
}

// File Line: 445
// RVA: 0x339E50
void __fastcall Pathing_OverrideCollisionAvoidanceTypeTrack::~Pathing_OverrideCollisionAvoidanceTypeTrack(Pathing_OverrideCollisionAvoidanceTypeTrack *this)
{
  Pathing_OverrideCollisionAvoidanceTypeTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Pathing_OverrideCollisionAvoidanceTypeTrack::`vftable';
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
  PathfindToTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, PathfindToTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<PathfindToTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&PathfindToTargetTrack::`vftable';
  *(_DWORD *)&v1->m_TargetType.mValue = 16843030;
  v1->m_ConstrainToSidewalks.mValue = 1;
  v1->m_SuppressFreerunning = 0;
  *(_QWORD *)&v1->m_TargetOffSet.x = 0i64;
  v1->m_TargetOffSet.z = 0.0;
  v1->m_GoalReachedThreshold = 0.5;
}

// File Line: 485
// RVA: 0x339D50
void __fastcall PathfindToTargetTrack::~PathfindToTargetTrack(PathfindToTargetTrack *this)
{
  PathfindToTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PathfindToTargetTrack::`vftable';
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
  PathfindAwayFromTargetTrack *v1; // rbx
  signed __int64 v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, PathfindAwayFromTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<PathfindAwayFromTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&PathfindAwayFromTargetTrack::`vftable';
  v1->m_TargetType.mValue = 22;
  v1->m_MoveType.mValue = 3;
  v2 = (signed __int64)&v1->m_ActionPath;
  *(_DWORD *)v2 = 0;
  *(_QWORD *)(v2 + 8) = 0i64;
  v1->mMaster = 1;
  v1->m_ActionRequestForWhenStill = gActionRequest_Cower.m_EnumValue;
  v1->m_MaxDistance = 15.0;
  v1->m_AllowedOnRoads = 0;
}

// File Line: 530
// RVA: 0x339B50
void __fastcall PathfindAwayFromTargetTrack::~PathfindAwayFromTargetTrack(PathfindAwayFromTargetTrack *this)
{
  PathfindAwayFromTargetTrack *v1; // rbx
  ActionPath *v2; // rdi
  __int64 v3; // rax
  __int64 v4; // rax
  char *v5; // rcx
  ExpressionParameterFloat *v6; // rcx
  char *v7; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PathfindAwayFromTargetTrack::`vftable';
  v2 = &this->m_ActionPath;
  if ( this->m_ActionPath.mPath.mCount >= 0 )
  {
    v3 = this->m_ActionPath.mPath.mData.mOffset;
    if ( v3 && (UFG::qOffset64<ActionID *> *)((char *)&v2->mPath.mData + v3) )
    {
      v4 = this->m_ActionPath.mPath.mData.mOffset;
      if ( v4 )
        v5 = (char *)&this->m_ActionPath.mPath.mData + v4;
      else
        v5 = 0i64;
      operator delete[](v5);
    }
    v2->mPath.mData.mOffset = 0i64;
    v2->mPath.mCount &= 0x80000000;
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v6 = &v1->mMasterRate;
  if ( !(~LOBYTE(v1->mMasterRate.text.mOffset) & 1) )
  {
    if ( v6->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v7 = (char *)v6 + (v6->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v7 != BinString::sEmptyString )
        operator delete[](v7);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  MoveDirectlyToTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, MoveDirectlyToTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<MoveDirectlyToTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&MoveDirectlyToTargetTrack::`vftable';
  *(_DWORD *)&v1->m_TargetType.mValue = 16843030;
  v1->m_GoalReachedThresholdXY = 0.5;
  v1->m_GoalReachedThresholdZ = 1.5;
}

// File Line: 578
// RVA: 0x339390
void __fastcall MoveDirectlyToTargetTrack::~MoveDirectlyToTargetTrack(MoveDirectlyToTargetTrack *this)
{
  MoveDirectlyToTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&MoveDirectlyToTargetTrack::`vftable';
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
  FollowTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, FollowTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<FollowTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&FollowTargetTrack::`vftable';
  *(_WORD *)&v1->m_TargetType.mValue = -227;
  v1->m_ConstrainToSidewalks.mValue = 1;
  v1->mMaster = 1;
  v1->m_StopAtRadius = 3.0;
  v1->m_StopAtZDifference = 1.5;
  v1->m_GoAtRadius = 6.0;
  v1->m_GoAtZDifference = 3.0;
  v1->m_FollowOffset = 2.0;
  v1->m_StopAtTarget = 1;
  v1->m_MinReactionTime = 0.1;
  v1->m_MaxReactionTime = 1.0;
  v1->m_DistanceToTeleportAt = 20.0;
  v1->m_DistanceToTeleportTo = 5.0;
}

// File Line: 637
// RVA: 0x336F90
void __fastcall FollowTargetTrack::~FollowTargetTrack(FollowTargetTrack *this)
{
  FollowTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&FollowTargetTrack::`vftable';
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
  CircleAroundCombatantsTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CircleAroundCombatantsTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CircleAroundCombatantsTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&CircleAroundCombatantsTrack::`vftable';
  v1->m_TargetType.mValue = 33;
  *(_WORD *)&v1->m_StopAtDesiredPosition = 257;
  v1->m_ConstrainToSidewalks.mValue = 1;
  v1->m_MinDistanceFromCentre = 3.0;
  v1->m_DesiredDistanceFromCentre = 5.0;
  v1->m_MaxDistanceFromCentre = 10.0;
  v1->m_Hysteresis = 2.0;
  v1->m_CloseEnoughToDesiredPosition = 1.0;
  v1->m_ReservationRadius = 3.0;
  v1->m_ReservationRadiusSquared = 9.0;
  v1->m_ActionRequestForWhenStill = gActionRequest_INVALID.m_EnumValue;
}

// File Line: 698
// RVA: 0x335AF0
void __fastcall CircleAroundCombatantsTrack::~CircleAroundCombatantsTrack(CircleAroundCombatantsTrack *this)
{
  CircleAroundCombatantsTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CircleAroundCombatantsTrack::`vftable';
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

// File Line: 734
// RVA: 0x14B2D70
__int64 dynamic_initializer_for__beginOrDonePlayingEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&beginOrDonePlayingEnum, gBeginOrDonePlayingStrings, 4, 0i64);
  return atexit(dynamic_atexit_destructor_for__beginOrDonePlayingEnum__);
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
void __fastcall ActionRequestAndWaitUntilPlayingTrack::ActionRequestAndWaitUntilPlayingTrack(ActionRequestAndWaitUntilPlayingTrack *this)
{
  ActionRequestAndWaitUntilPlayingTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ActionRequestAndWaitUntilPlayingTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ActionRequestAndWaitUntilPlayingTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestAndWaitUntilPlayingTrack::`vftable';
  v1->m_BeginOrDonePlaying.mValue = 2;
  v1->m_ActionRequest = gActionRequest_Action.m_EnumValue;
  v1->m_CheckSpawns = 0;
  v1->m_Timeout = -1.0;
}

// File Line: 757
// RVA: 0x334D80
void __fastcall ActionRequestAndWaitUntilPlayingTrack::~ActionRequestAndWaitUntilPlayingTrack(ActionRequestAndWaitUntilPlayingTrack *this)
{
  ActionRequestAndWaitUntilPlayingTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ActionRequestAndWaitUntilPlayingTrack::`vftable';
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
  NodeRequestTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, NodeRequestTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<NodeRequestTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestTrack::`vftable';
  v1->m_NodeName.mUID = -1;
}

// File Line: 788
// RVA: 0x339840
void __fastcall NodeRequestTrack::~NodeRequestTrack(NodeRequestTrack *this)
{
  NodeRequestTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestTrack::`vftable';
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
void __fastcall NodeRequestAndWaitUntilPlayingTrack::NodeRequestAndWaitUntilPlayingTrack(NodeRequestAndWaitUntilPlayingTrack *this)
{
  NodeRequestAndWaitUntilPlayingTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, NodeRequestAndWaitUntilPlayingTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<NodeRequestAndWaitUntilPlayingTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestAndWaitUntilPlayingTrack::`vftable';
  *(_WORD *)&v1->m_CheckSpawns = 512;
  v1->m_Timeout = -1.0;
}

// File Line: 820
// RVA: 0x339750
void __fastcall NodeRequestAndWaitUntilPlayingTrack::~NodeRequestAndWaitUntilPlayingTrack(NodeRequestAndWaitUntilPlayingTrack *this)
{
  NodeRequestAndWaitUntilPlayingTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&NodeRequestAndWaitUntilPlayingTrack::`vftable';
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

// File Line: 838
// RVA: 0x14B2E00
__int64 dynamic_initializer_for__emotionEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&emotionEnum, UFG::AIEmotionNames, 13, 0i64);
  return atexit(dynamic_atexit_destructor_for__emotionEnum__);
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
  SetCurrentEmotionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, SetCurrentEmotionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<SetCurrentEmotionTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&SetCurrentEmotionTrack::`vftable';
  v1->m_CurrentEmotion.mValue = 0;
}

// File Line: 851
// RVA: 0x33AC30
void __fastcall SetCurrentEmotionTrack::~SetCurrentEmotionTrack(SetCurrentEmotionTrack *this)
{
  SetCurrentEmotionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetCurrentEmotionTrack::`vftable';
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
  SetFacialEmotionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, SetFacialEmotionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<SetFacialEmotionTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&SetFacialEmotionTrack::`vftable';
  v1->m_FacialEmotion.mValue = 0;
}

// File Line: 878
// RVA: 0x33ADC0
void __fastcall SetFacialEmotionTrack::~SetFacialEmotionTrack(SetFacialEmotionTrack *this)
{
  SetFacialEmotionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetFacialEmotionTrack::`vftable';
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
  TurnToFaceTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TurnToFaceTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TurnToFaceTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TurnToFaceTargetTrack::`vftable';
  v1->m_TargetType.mValue = 33;
  v1->m_FacingClosenessRadians = 0.17453294;
}

// File Line: 906
// RVA: 0x33B730
void __fastcall TurnToFaceTargetTrack::~TurnToFaceTargetTrack(TurnToFaceTargetTrack *this)
{
  TurnToFaceTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TurnToFaceTargetTrack::`vftable';
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
  HeadTrackTargetTrack *v1; // rbx
  float v2; // xmm1_4
  float v3; // xmm2_4

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, HeadTrackTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<HeadTrackTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&HeadTrackTargetTrack::`vftable';
  v1->m_TargetType.mValue = 22;
  v1->m_MaxHorizontalHalfAngle = 3.1415927;
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->m_Offset.x = UFG::qVector3::msZero.x;
  v1->m_Offset.y = v2;
  v1->m_Offset.z = v3;
}

// File Line: 936
// RVA: 0x338760
void __fastcall HeadTrackTargetTrack::~HeadTrackTargetTrack(HeadTrackTargetTrack *this)
{
  HeadTrackTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&HeadTrackTargetTrack::`vftable';
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
  MinimumDurationTrack *v1; // rdi

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, MinimumDurationTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<MinimumDurationTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&MinimumDurationTrack::`vftable';
  v1->mMinLength.text.mOffset = 1i64;
  BinString::Set(&v1->mMinLength.text, &customWorldMapCaption);
  v1->mMinLength.expression.mOffset = 0i64;
  v1->mMinLength.value = 0.0;
  v1->mMaxLength.text.mOffset = 1i64;
  BinString::Set(&v1->mMaxLength.text, &customWorldMapCaption);
  v1->mMaxLength.expression.mOffset = 0i64;
  v1->mMaxLength.value = 0.0;
  v1->mMultiplier.text.mOffset = 1i64;
  BinString::Set(&v1->mMultiplier.text, &customWorldMapCaption);
  v1->mMultiplier.expression.mOffset = 0i64;
  v1->mMultiplier.value = 1.0;
  v1->mMaster = 1;
}

// File Line: 969
// RVA: 0x339190
void __fastcall MinimumDurationTrack::~MinimumDurationTrack(MinimumDurationTrack *this)
{
  MinimumDurationTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx
  ExpressionParameterFloat *v4; // rcx
  char *v5; // rcx
  ExpressionParameterFloat *v6; // rcx
  char *v7; // rcx
  ExpressionParameterFloat *v8; // rcx
  char *v9; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&MinimumDurationTrack::`vftable';
  v2 = &this->mMultiplier;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v4 = &v1->mMaxLength;
  if ( !(~LOBYTE(v1->mMaxLength.text.mOffset) & 1) )
  {
    if ( v4->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v5 = (char *)v4 + (v4->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v5 != BinString::sEmptyString )
        operator delete[](v5);
    }
  }
  v6 = &v1->mMinLength;
  if ( !(~LOBYTE(v1->mMinLength.text.mOffset) & 1) )
  {
    if ( v6->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v7 = (char *)v6 + (v6->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v7 != BinString::sEmptyString )
        operator delete[](v7);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v8 = &v1->mMasterRate;
  if ( !(~LOBYTE(v1->mMasterRate.text.mOffset) & 1) )
  {
    if ( v8->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v9 = (char *)v8 + (v8->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v9 != BinString::sEmptyString )
        operator delete[](v9);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  DebugDrawMyPositionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DebugDrawMyPositionTrack::`vftable';
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
  DebugDrawMyTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DebugDrawMyTargetTrack::`vftable';
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
  RunLaterallyFromTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RunLaterallyFromTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RunLaterallyFromTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&RunLaterallyFromTargetTrack::`vftable';
  *(_DWORD *)&v1->m_TargetType.mValue = 66337;
  v1->m_DistanceToRun = 5.0;
  v1->m_MaxLateralDistanceToDive = 2.0;
  v1->m_MaxTimeToImpactToDive = 0.60000002;
  v1->m_MinTimeToImpactToDive = 0.40000001;
  v1->m_ActionRequestForPressAgainstWall = gActionRequest_Cower.m_EnumValue;
  v1->m_DistanceFromLastValidPositionToPressAgainstWall = 0.25;
}

// File Line: 1089
// RVA: 0x33A8D0
void __fastcall RunLaterallyFromTargetTrack::~RunLaterallyFromTargetTrack(RunLaterallyFromTargetTrack *this)
{
  RunLaterallyFromTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RunLaterallyFromTargetTrack::`vftable';
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
  AITargetingParametersTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AITargetingParametersTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AITargetingParametersTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AITargetingParametersTrack::`vftable';
  v1->m_OtherTargetType.mValue = 29;
  v1->m_MaxDistanceFromOtherTarget = 5.0;
  v1->m_DistanceFromOtherTargetHysteresis = 2.0;
}

// File Line: 1129
// RVA: 0x334C00
void __fastcall AITargetingParametersTrack::~AITargetingParametersTrack(AITargetingParametersTrack *this)
{
  AITargetingParametersTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AITargetingParametersTrack::`vftable';
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
void __fastcall AIAddSupplementaryAttackTargetTrack::AIAddSupplementaryAttackTargetTrack(AIAddSupplementaryAttackTargetTrack *this)
{
  AIAddSupplementaryAttackTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AIAddSupplementaryAttackTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AIAddSupplementaryAttackTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIAddSupplementaryAttackTargetTrack::`vftable';
  v1->m_TargetType.mValue = eTARGET_TYPE_ATTACKER;
}

// File Line: 1157
// RVA: 0x333A30
void __fastcall AIAddSupplementaryAttackTargetTrack::~AIAddSupplementaryAttackTargetTrack(AIAddSupplementaryAttackTargetTrack *this)
{
  AIAddSupplementaryAttackTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AIAddSupplementaryAttackTargetTrack::`vftable';
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
void __fastcall AIRemoveSupplementaryAttackTargetTrack::AIRemoveSupplementaryAttackTargetTrack(AIRemoveSupplementaryAttackTargetTrack *this)
{
  AIRemoveSupplementaryAttackTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AIRemoveSupplementaryAttackTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AIRemoveSupplementaryAttackTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIRemoveSupplementaryAttackTargetTrack::`vftable';
  v1->m_TargetType.mValue = 2;
}

// File Line: 1184
// RVA: 0x3349A0
void __fastcall AIRemoveSupplementaryAttackTargetTrack::~AIRemoveSupplementaryAttackTargetTrack(AIRemoveSupplementaryAttackTargetTrack *this)
{
  AIRemoveSupplementaryAttackTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AIRemoveSupplementaryAttackTargetTrack::`vftable';
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
  GetInFormationTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, GetInFormationTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<GetInFormationTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&GetInFormationTrack::`vftable';
  v1->m_pGetInFormationCondition = 0i64;
}

// File Line: 1207
// RVA: 0x3377B0
void __fastcall GetInFormationTrack::~GetInFormationTrack(GetInFormationTrack *this)
{
  GetInFormationTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&GetInFormationTrack::`vftable';
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

// File Line: 1212
// RVA: 0x383190
void __fastcall GetInFormationTrack::ResolveReferences(GetInFormationTrack *this, ActionNode *action_node)
{
  GetInFormationTrack *v2; // rbp
  const char *v3; // rax
  const char *v4; // rsi
  __int64 v5; // rbx
  signed __int64 v6; // r14
  signed __int64 v7; // rdi

  v2 = this;
  v3 = action_node->vfptr[3].GetClassname((Expression::IMemberMap *)action_node);
  v4 = v3;
  if ( v3 )
  {
    v5 = 0i64;
    v6 = (signed __int64)&v3[*((_QWORD *)v3 + 5) + 40];
    if ( *((_DWORD *)v3 + 8) & 0x7FFFFFFF )
    {
      do
      {
        v7 = v6 + 8 * v5 + *(_QWORD *)(v6 + 8 * v5);
        if ( (*(unsigned int (__fastcall **)(signed __int64))(*(_QWORD *)v7 + 40i64))(v7) == GetInFormationCondition::sClassNameUID )
          v2->m_pGetInFormationCondition = (GetInFormationCondition *)v7;
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
  GetInPedFormationTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, GetInPedFormationTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<GetInPedFormationTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&GetInPedFormationTrack::`vftable';
  v1->m_pGetInPedFormationCondition = 0i64;
}

// File Line: 1254
// RVA: 0x337C80
void __fastcall GetInPedFormationTrack::~GetInPedFormationTrack(GetInPedFormationTrack *this)
{
  GetInPedFormationTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&GetInPedFormationTrack::`vftable';
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

// File Line: 1259
// RVA: 0x3832A0
void __fastcall GetInPedFormationTrack::ResolveReferences(GetInPedFormationTrack *this, ActionNode *action_node)
{
  GetInPedFormationTrack *v2; // rbp
  const char *v3; // rax
  const char *v4; // rsi
  __int64 v5; // rbx
  signed __int64 v6; // r14
  signed __int64 v7; // rdi

  v2 = this;
  v3 = action_node->vfptr[3].GetClassname((Expression::IMemberMap *)action_node);
  v4 = v3;
  if ( v3 )
  {
    v5 = 0i64;
    v6 = (signed __int64)&v3[*((_QWORD *)v3 + 5) + 40];
    if ( *((_DWORD *)v3 + 8) & 0x7FFFFFFF )
    {
      do
      {
        v7 = v6 + 8 * v5 + *(_QWORD *)(v6 + 8 * v5);
        if ( (*(unsigned int (__fastcall **)(signed __int64))(*(_QWORD *)v7 + 40i64))(v7) == GetInPedFormationCondition::sClassNameUID )
          v2->m_pGetInPedFormationCondition = (GetInPedFormationCondition *)v7;
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
void __fastcall InvalidateFormationPositionTrack::InvalidateFormationPositionTrack(InvalidateFormationPositionTrack *this)
{
  InvalidateFormationPositionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, InvalidateFormationPositionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<InvalidateFormationPositionTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&InvalidateFormationPositionTrack::`vftable';
  v1->m_TargetType.mValue = 22;
}

// File Line: 1308
// RVA: 0x338D70
void __fastcall InvalidateFormationPositionTrack::~InvalidateFormationPositionTrack(InvalidateFormationPositionTrack *this)
{
  InvalidateFormationPositionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&InvalidateFormationPositionTrack::`vftable';
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
  JustPerformedRunningAttackTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, JustPerformedRunningAttackTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<JustPerformedRunningAttackTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&JustPerformedRunningAttackTrack::`vftable';
  v1->m_TargetType.mValue = 22;
  v1->mTimeBegin = -1.0;
}

// File Line: 1336
// RVA: 0x339010
void __fastcall JustPerformedRunningAttackTrack::~JustPerformedRunningAttackTrack(JustPerformedRunningAttackTrack *this)
{
  JustPerformedRunningAttackTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&JustPerformedRunningAttackTrack::`vftable';
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

// File Line: 1351
// RVA: 0x14B2E30
__int64 dynamic_initializer_for__formationFacingTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&formationFacingTypeEnum, UFG::FormationFacingTypeNames, 2, 0i64);
  return atexit(dynamic_atexit_destructor_for__formationFacingTypeEnum__);
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
  return atexit(dynamic_atexit_destructor_for__formationMovementDirectionEnum__);
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
void __fastcall RequestFormationPositionChangeTrack::RequestFormationPositionChangeTrack(RequestFormationPositionChangeTrack *this)
{
  RequestFormationPositionChangeTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, RequestFormationPositionChangeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<RequestFormationPositionChangeTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&RequestFormationPositionChangeTrack::`vftable';
  *(_DWORD *)&v1->m_TargetType.mValue = 33620758;
  v1->m_AbsolutePosition = 0;
}

// File Line: 1376
// RVA: 0x33A750
void __fastcall RequestFormationPositionChangeTrack::~RequestFormationPositionChangeTrack(RequestFormationPositionChangeTrack *this)
{
  RequestFormationPositionChangeTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RequestFormationPositionChangeTrack::`vftable';
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
  LeaveGroupTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, LeaveGroupTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<LeaveGroupTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&LeaveGroupTrack::`vftable';
}

// File Line: 1404
// RVA: 0x339120
void __fastcall LeaveGroupTrack::~LeaveGroupTrack(LeaveGroupTrack *this)
{
  LeaveGroupTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&LeaveGroupTrack::`vftable';
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
  SelectSuitableVehicleTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, SelectSuitableVehicleTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<SelectSuitableVehicleTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&SelectSuitableVehicleTrack::`vftable';
  v1->m_MaxSearchRadius = 3.0;
  v1->m_IgnoreMeshTest = 0;
  v1->m_FilterClassSymbol.mUID = -1;
}

// File Line: 1431
// RVA: 0x33AB30
void __fastcall SelectSuitableVehicleTrack::~SelectSuitableVehicleTrack(SelectSuitableVehicleTrack *this)
{
  SelectSuitableVehicleTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SelectSuitableVehicleTrack::`vftable';
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
  FireWeaponTrack *v1; // rdi

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, FireWeaponTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<FireWeaponTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&FireWeaponTrack::`vftable';
  v1->mMinNumShots.text.mOffset = 1i64;
  BinString::Set(&v1->mMinNumShots.text, &customWorldMapCaption);
  v1->mMinNumShots.expression.mOffset = 0i64;
  v1->mMinNumShots.value = 0;
  v1->mMaxNumShots.text.mOffset = 1i64;
  BinString::Set(&v1->mMaxNumShots.text, &customWorldMapCaption);
  v1->mMaxNumShots.expression.mOffset = 0i64;
  v1->mMaxNumShots.value = 0;
  v1->mMinTimeBetweenShots.text.mOffset = 1i64;
  BinString::Set(&v1->mMinTimeBetweenShots.text, &customWorldMapCaption);
  v1->mMinTimeBetweenShots.expression.mOffset = 0i64;
  v1->mMinTimeBetweenShots.value = -1.0;
  v1->mMaxTimeBetweenShots.text.mOffset = 1i64;
  BinString::Set(&v1->mMaxTimeBetweenShots.text, &customWorldMapCaption);
  v1->mMaxTimeBetweenShots.expression.mOffset = 0i64;
  v1->mMaxTimeBetweenShots.value = -1.0;
  v1->mMinTimeToHoldTrigger.text.mOffset = 1i64;
  BinString::Set(&v1->mMinTimeToHoldTrigger.text, &customWorldMapCaption);
  v1->mMinTimeToHoldTrigger.expression.mOffset = 0i64;
  v1->mMinTimeToHoldTrigger.value = 0.0;
  v1->mMaxTimeToHoldTrigger.text.mOffset = 1i64;
  BinString::Set(&v1->mMaxTimeToHoldTrigger.text, &customWorldMapCaption);
  v1->mMaxTimeToHoldTrigger.expression.mOffset = 0i64;
  v1->mMaxTimeToHoldTrigger.value = 0.0;
  v1->mTimeMultiplierBetween.text.mOffset = 1i64;
  BinString::Set(&v1->mTimeMultiplierBetween.text, &customWorldMapCaption);
  v1->mTimeMultiplierBetween.expression.mOffset = 0i64;
  v1->mTimeMultiplierBetween.value = 1.0;
  v1->mTimeMultiplierHold.text.mOffset = 1i64;
  BinString::Set(&v1->mTimeMultiplierHold.text, &customWorldMapCaption);
  v1->mTimeMultiplierHold.expression.mOffset = 0i64;
  v1->mTimeMultiplierHold.value = 1.0;
  v1->m_HoldTrigger = 0;
  v1->mMaster = 1;
  v1->m_ActionRequest = gActionRequest_Fire.m_EnumValue;
}

// File Line: 1484
// RVA: 0x336940
void __fastcall FireWeaponTrack::~FireWeaponTrack(FireWeaponTrack *this)
{
  FireWeaponTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx
  ExpressionParameterFloat *v4; // rcx
  char *v5; // rcx
  ExpressionParameterFloat *v6; // rcx
  char *v7; // rcx
  ExpressionParameterFloat *v8; // rcx
  char *v9; // rcx
  ExpressionParameterFloat *v10; // rcx
  char *v11; // rcx
  ExpressionParameterFloat *v12; // rcx
  char *v13; // rcx
  ExpressionParameterInt *v14; // rcx
  char *v15; // rcx
  ExpressionParameterInt *v16; // rcx
  char *v17; // rcx
  ExpressionParameterFloat *v18; // rcx
  char *v19; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&FireWeaponTrack::`vftable';
  v2 = &this->mTimeMultiplierHold;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v4 = &v1->mTimeMultiplierBetween;
  if ( !(~LOBYTE(v1->mTimeMultiplierBetween.text.mOffset) & 1) )
  {
    if ( v4->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v5 = (char *)v4 + (v4->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v5 != BinString::sEmptyString )
        operator delete[](v5);
    }
  }
  v6 = &v1->mMaxTimeToHoldTrigger;
  if ( !(~LOBYTE(v1->mMaxTimeToHoldTrigger.text.mOffset) & 1) )
  {
    if ( v6->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v7 = (char *)v6 + (v6->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v7 != BinString::sEmptyString )
        operator delete[](v7);
    }
  }
  v8 = &v1->mMinTimeToHoldTrigger;
  if ( !(~LOBYTE(v1->mMinTimeToHoldTrigger.text.mOffset) & 1) )
  {
    if ( v8->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v9 = (char *)v8 + (v8->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v9 != BinString::sEmptyString )
        operator delete[](v9);
    }
  }
  v10 = &v1->mMaxTimeBetweenShots;
  if ( !(~LOBYTE(v1->mMaxTimeBetweenShots.text.mOffset) & 1) )
  {
    if ( v10->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v11 = (char *)v10 + (v10->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v11 != BinString::sEmptyString )
        operator delete[](v11);
    }
  }
  v12 = &v1->mMinTimeBetweenShots;
  if ( !(~LOBYTE(v1->mMinTimeBetweenShots.text.mOffset) & 1) )
  {
    if ( v12->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v13 = (char *)v12 + (v12->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v13 != BinString::sEmptyString )
        operator delete[](v13);
    }
  }
  v14 = &v1->mMaxNumShots;
  if ( !(~LOBYTE(v1->mMaxNumShots.text.mOffset) & 1) )
  {
    if ( v14->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v15 = (char *)v14 + (v14->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v15 != BinString::sEmptyString )
        operator delete[](v15);
    }
  }
  v16 = &v1->mMinNumShots;
  if ( !(~LOBYTE(v1->mMinNumShots.text.mOffset) & 1) )
  {
    if ( v16->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v17 = (char *)v16 + (v16->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v17 != BinString::sEmptyString )
        operator delete[](v17);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v18 = &v1->mMasterRate;
  if ( !(~LOBYTE(v1->mMasterRate.text.mOffset) & 1) )
  {
    if ( v18->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v19 = (char *)v18 + (v18->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v19 != BinString::sEmptyString )
        operator delete[](v19);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
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
  AICoverSearchTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AICoverSearchTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AICoverSearchTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICoverSearchTrack::`vftable';
  v1->m_eTargetType.mValue = 0;
  v1->m_fMaxDistance = 10.0;
  v1->m_fDistanceWeight = 1.0;
  v1->m_fDistanceToTargetWeight = 1.0;
  v1->m_fMinDistanceToTarget = 5.0;
  v1->m_fMaxDistanceToTarget = 15.0;
  v1->m_fSweetSpotWeight = 1.0;
  *(_QWORD *)&v1->m_fMaxAngleFromSweetSpot = 1057360530i64;
  v1->m_fDistanceFromAlliesWeight = 8.0;
  v1->m_fRadialSpreadFromAlliesWeight = 8.0;
  v1->m_fLineOfSightWeight = 1.0;
  v1->m_bLineOfSightRequired = 0;
  v1->m_fDirectLineOfSightWeight = -1.0;
  *(_DWORD *)&v1->m_bSkipPathfind = 0;
  v1->m_fMinimumPriority = -1.0;
  v1->m_fPathWeight = 0.2;
}

// File Line: 1575
// RVA: 0x334210
void __fastcall AICoverSearchTrack::~AICoverSearchTrack(AICoverSearchTrack *this)
{
  AICoverSearchTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverSearchTrack::`vftable';
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
  AICoverFaceCoverObjectTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AICoverFaceCoverObjectTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AICoverFaceCoverObjectTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICoverFaceCoverObjectTrack::`vftable';
}

// File Line: 1627
// RVA: 0x333DC0
void __fastcall AICoverFaceCoverObjectTrack::~AICoverFaceCoverObjectTrack(AICoverFaceCoverObjectTrack *this)
{
  AICoverFaceCoverObjectTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverFaceCoverObjectTrack::`vftable';
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
  AICoverClearCoverObjectTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AICoverClearCoverObjectTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AICoverClearCoverObjectTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICoverClearCoverObjectTrack::`vftable';
}

// File Line: 1654
// RVA: 0x333C40
void __fastcall AICoverClearCoverObjectTrack::~AICoverClearCoverObjectTrack(AICoverClearCoverObjectTrack *this)
{
  AICoverClearCoverObjectTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverClearCoverObjectTrack::`vftable';
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
  AICoverLatchTargetedObjectTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AICoverLatchTargetedObjectTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AICoverLatchTargetedObjectTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICoverLatchTargetedObjectTrack::`vftable';
  v1->m_eCoverComponentObject.mValue = 3;
}

// File Line: 1681
// RVA: 0x333EB0
void __fastcall AICoverLatchTargetedObjectTrack::~AICoverLatchTargetedObjectTrack(AICoverLatchTargetedObjectTrack *this)
{
  AICoverLatchTargetedObjectTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AICoverLatchTargetedObjectTrack::`vftable';
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
  AICopReleaseArrestRightTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AICopReleaseArrestRightTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AICopReleaseArrestRightTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICopReleaseArrestRightTrack::`vftable';
}

// File Line: 1708
// RVA: 0x333B60
void __fastcall AICopReleaseArrestRightTrack::~AICopReleaseArrestRightTrack(AICopReleaseArrestRightTrack *this)
{
  AICopReleaseArrestRightTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopReleaseArrestRightTrack::`vftable';
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
void __fastcall AICopReportInfractionTargetTrack::AICopReportInfractionTargetTrack(AICopReportInfractionTargetTrack *this)
{
  AICopReportInfractionTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AICopReportInfractionTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AICopReportInfractionTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AICopReportInfractionTargetTrack::`vftable';
  v1->m_TargetType.mValue = 0;
}

// File Line: 1734
// RVA: 0x333BD0
void __fastcall AICopReportInfractionTargetTrack::~AICopReportInfractionTargetTrack(AICopReportInfractionTargetTrack *this)
{
  AICopReportInfractionTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopReportInfractionTargetTrack::`vftable';
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
  AIOverrideAvoidanceRadiusTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AIOverrideAvoidanceRadiusTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AIOverrideAvoidanceRadiusTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AIOverrideAvoidanceRadiusTrack::`vftable';
  v1->m_Radius = 1.0;
  v1->m_AdjustToNavGoal = 0;
}

// File Line: 1776
// RVA: 0x334770
void __fastcall AIOverrideAvoidanceRadiusTrack::~AIOverrideAvoidanceRadiusTrack(AIOverrideAvoidanceRadiusTrack *this)
{
  AIOverrideAvoidanceRadiusTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AIOverrideAvoidanceRadiusTrack::`vftable';
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
  GroupStimulusTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, GroupStimulusTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<GroupStimulusTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&GroupStimulusTrack::`vftable';
  v1->m_StimulusType.mValue = 0;
  v1->m_FactionStanding.mValue = 2;
  *(_QWORD *)&v1->m_TotalPointsPropertySymbol.mUID = -1i64;
  v1->m_MaxRange = 0.0;
  v1->m_TotalPointsPropertySymbol = UFG::gNullQSymbol;
  v1->m_CostPerCharacterPropertySymbol = UFG::gNullQSymbol;
}

// File Line: 1814
// RVA: 0x337FE0
void __fastcall GroupStimulusTrack::~GroupStimulusTrack(GroupStimulusTrack *this)
{
  GroupStimulusTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&GroupStimulusTrack::`vftable';
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
  AttackRightsScoreBonusTrack *v1; // rbx
  signed __int64 v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AttackRightsScoreBonusTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AttackRightsScoreBonusTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsScoreBonusTrack::`vftable';
  v2 = (signed __int64)&v1->m_ActionPath;
  *(_DWORD *)v2 = 0;
  *(_QWORD *)(v2 + 8) = 0i64;
  v1->m_ScoreBonus = 0.0;
}

// File Line: 1857
// RVA: 0x335580
void __fastcall AttackRightsScoreBonusTrack::~AttackRightsScoreBonusTrack(AttackRightsScoreBonusTrack *this)
{
  AttackRightsScoreBonusTrack *v1; // rbx
  ActionPath *v2; // rdi
  __int64 v3; // rax
  __int64 v4; // rax
  char *v5; // rcx
  ExpressionParameterFloat *v6; // rcx
  char *v7; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsScoreBonusTrack::`vftable';
  v2 = &this->m_ActionPath;
  if ( this->m_ActionPath.mPath.mCount >= 0 )
  {
    v3 = this->m_ActionPath.mPath.mData.mOffset;
    if ( v3 && (UFG::qOffset64<ActionID *> *)((char *)&v2->mPath.mData + v3) )
    {
      v4 = this->m_ActionPath.mPath.mData.mOffset;
      if ( v4 )
        v5 = (char *)&this->m_ActionPath.mPath.mData + v4;
      else
        v5 = 0i64;
      operator delete[](v5);
    }
    v2->mPath.mData.mOffset = 0i64;
    v2->mPath.mCount &= 0x80000000;
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
  v6 = &v1->mMasterRate;
  if ( !(~LOBYTE(v1->mMasterRate.text.mOffset) & 1) )
  {
    if ( v6->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v7 = (char *)v6 + (v6->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v7 != BinString::sEmptyString )
        operator delete[](v7);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 1884
// RVA: 0x3324B0
void __fastcall TargetActionRequestTrack::TargetActionRequestTrack(TargetActionRequestTrack *this)
{
  TargetActionRequestTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, TargetActionRequestTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<TargetActionRequestTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&TargetActionRequestTrack::`vftable';
  *(_QWORD *)&v1->mActionRequest = gActionRequest_Action.m_EnumValue;
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
void __fastcall LockFormationPositionToCurrentPositionTrack::LockFormationPositionToCurrentPositionTrack(LockFormationPositionToCurrentPositionTrack *this)
{
  LockFormationPositionToCurrentPositionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, LockFormationPositionToCurrentPositionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<LockFormationPositionToCurrentPositionTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&LockFormationPositionToCurrentPositionTrack::`vftable';
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
  AddTargetAsDangerousEntityTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AddTargetAsDangerousEntityTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AddTargetAsDangerousEntityTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AddTargetAsDangerousEntityTrack::`vftable';
  v1->m_TargetType.mValue = 33;
  v1->m_DangerRadius = 20.0;
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
  SetDriverFlagsTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, SetDriverFlagsTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<SetDriverFlagsTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&SetDriverFlagsTrack::`vftable';
  *(_DWORD *)&v1->m_AvoidPeds = 0;
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
void __fastcall AttackRightsSetTimeUntilNextAttackTrack::AttackRightsSetTimeUntilNextAttackTrack(AttackRightsSetTimeUntilNextAttackTrack *this)
{
  AttackRightsSetTimeUntilNextAttackTrack *v1; // rbx
  signed __int64 v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AttackRightsSetTimeUntilNextAttackTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AttackRightsSetTimeUntilNextAttackTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsSetTimeUntilNextAttackTrack::`vftable';
  v1->m_TargetType.mValue = 22;
  v1->m_AttackType.mValue = 0;
  v2 = (signed __int64)&v1->m_ActionPath;
  *(_DWORD *)v2 = 0;
  *(_QWORD *)(v2 + 8) = 0i64;
  *(_QWORD *)&v1->m_MinTime = 0i64;
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
void __fastcall AttackRightsClearPreviousBestAttackerTrack::AttackRightsClearPreviousBestAttackerTrack(AttackRightsClearPreviousBestAttackerTrack *this)
{
  AttackRightsClearPreviousBestAttackerTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AttackRightsClearPreviousBestAttackerTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AttackRightsClearPreviousBestAttackerTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsClearPreviousBestAttackerTrack::`vftable';
  *(_WORD *)&v1->m_TargetType.mValue = 22;
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
  AttackRightsReSortListTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AttackRightsReSortListTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AttackRightsReSortListTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsReSortListTrack::`vftable';
  *(_WORD *)&v1->m_TargetType.mValue = 22;
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
void __fastcall AttackRightsCancelAnyIncomingAttackTrack::AttackRightsCancelAnyIncomingAttackTrack(AttackRightsCancelAnyIncomingAttackTrack *this)
{
  AttackRightsCancelAnyIncomingAttackTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AttackRightsCancelAnyIncomingAttackTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AttackRightsCancelAnyIncomingAttackTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsCancelAnyIncomingAttackTrack::`vftable';
  *(_WORD *)&v1->m_TargetType.mValue = 22;
  v1->m_DurationToCancelFor = 0.5;
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
void __fastcall AttackRightsFormationManagerFreezeRangeSwitchesTrack::AttackRightsFormationManagerFreezeRangeSwitchesTrack(AttackRightsFormationManagerFreezeRangeSwitchesTrack *this)
{
  AttackRightsFormationManagerFreezeRangeSwitchesTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, AttackRightsFormationManagerFreezeRangeSwitchesTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<AttackRightsFormationManagerFreezeRangeSwitchesTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&AttackRightsFormationManagerFreezeRangeSwitchesTrack::`vftable';
  v1->m_TargetType.mValue = 22;
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
  CombatRegionMoveToTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CombatRegionMoveToTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CombatRegionMoveToTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&CombatRegionMoveToTrack::`vftable';
  *(_WORD *)&v1->m_MoveType.mValue = 257;
  v1->m_StopAtTarget = 1;
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
void __fastcall UpdateHijackableVehicleTargetTrack::UpdateHijackableVehicleTargetTrack(UpdateHijackableVehicleTargetTrack *this)
{
  UpdateHijackableVehicleTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, UpdateHijackableVehicleTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<UpdateHijackableVehicleTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&UpdateHijackableVehicleTargetTrack::`vftable';
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
  MoveToBetterAttackPositionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, MoveToBetterAttackPositionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<MoveToBetterAttackPositionTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&MoveToBetterAttackPositionTrack::`vftable';
  v1->m_TargetType.mValue = 22;
  v1->m_fMinDistance = 1.0;
  v1->m_fMaxDistance = 3.0;
  v1->m_NumDirectionsToTest = 6;
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
  MoveToFindLineOfSightTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, MoveToFindLineOfSightTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<MoveToFindLineOfSightTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&MoveToFindLineOfSightTrack::`vftable';
  *(_WORD *)&v1->m_TargetType.mValue = 534;
  v1->m_fMinDistance = 1.0;
  v1->m_fMaxDistance = 3.0;
  v1->m_NumDirectionsToTest = 6;
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
void __fastcall WaitUntilAbleToPathToTargetTrack::WaitUntilAbleToPathToTargetTrack(WaitUntilAbleToPathToTargetTrack *this)
{
  WaitUntilAbleToPathToTargetTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, WaitUntilAbleToPathToTargetTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<WaitUntilAbleToPathToTargetTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&WaitUntilAbleToPathToTargetTrack::`vftable';
  *(_WORD *)&v1->m_TargetType.mValue = 22;
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
void __fastcall InteractingWithVehicleHeuristicTrack::InteractingWithVehicleHeuristicTrack(InteractingWithVehicleHeuristicTrack *this)
{
  InteractingWithVehicleHeuristicTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, InteractingWithVehicleHeuristicTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<InteractingWithVehicleHeuristicTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&InteractingWithVehicleHeuristicTrack::`vftable';
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
  return atexit(dynamic_atexit_destructor_for__gTargetPriorityEnum__);
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
  return atexit(dynamic_atexit_destructor_for__gInvokeBehaviourModeEnum__);
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
  return atexit(dynamic_atexit_destructor_for__gInvokeBehaviourPriorityModeEnum__);
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
  InvokeBehaviourTrack *v1; // rbx

  v1 = this;
  SpawnTrack::SpawnTrack((SpawnTrack *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&InvokeBehaviourTrack::`vftable';
  v1->m_Priority = 0;
  *(_WORD *)&v1->m_PriorityMode.mValue = 0;
  v1->m_MaxWaitTime = -1.0;
  v1->m_MaxLifeTime = -1.0;
}

