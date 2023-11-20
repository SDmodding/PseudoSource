// File Line: 61
// RVA: 0x2BF640
__int64 __fastcall SetBittenTrack::GetClassNameUID(SetBittenTrack *this)
{
  return SetBittenTrack::sClassNameUID;
}

// File Line: 70
// RVA: 0x29DAA0
void __fastcall SetBittenTrack::~SetBittenTrack(SetBittenTrack *this)
{
  SetBittenTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetBittenTrack::`vftable';
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

// File Line: 85
// RVA: 0x3243C0
UpdateStatAwardWithIntegerTrack *__fastcall UpdateStatAwardWithIntegerTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x40ui64,
         "MemberMap::UpdateStatAwardWithIntegerTrack",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, UpdateStatAwardWithIntegerTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<UpdateStatAwardWithIntegerTask>::`vftable';
  *(_QWORD *)v1 = &UpdateStatAwardWithIntegerTrack::`vftable';
  *((_DWORD *)v1 + 14) = -1;
  *((_DWORD *)v1 + 15) = 0;
  return (UpdateStatAwardWithIntegerTrack *)v1;
}

// File Line: 95
// RVA: 0x29F210
void __fastcall UpdateStatAwardWithIntegerTrack::~UpdateStatAwardWithIntegerTrack(UpdateStatAwardWithIntegerTrack *this)
{
  UpdateStatAwardWithIntegerTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&UpdateStatAwardWithIntegerTrack::`vftable';
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

// File Line: 114
// RVA: 0x2BFED0
__int64 __fastcall UpdateStatAwardWithFloatTrack::GetClassNameUID(UpdateStatAwardWithFloatTrack *this)
{
  return UpdateStatAwardWithFloatTrack::sClassNameUID;
}

// File Line: 124
// RVA: 0x29F1A0
void __fastcall UpdateStatAwardWithFloatTrack::~UpdateStatAwardWithFloatTrack(UpdateStatAwardWithFloatTrack *this)
{
  UpdateStatAwardWithFloatTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&UpdateStatAwardWithFloatTrack::`vftable';
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

// File Line: 143
// RVA: 0x2BE580
__int64 __fastcall EndStatGameTrack::GetClassNameUID(EndStatGameTrack *this)
{
  return EndStatGameTrack::sClassNameUID;
}

// File Line: 152
// RVA: 0x29B620
void __fastcall EndStatGameTrack::~EndStatGameTrack(EndStatGameTrack *this)
{
  EndStatGameTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&EndStatGameTrack::`vftable';
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

// File Line: 168
// RVA: 0x2C2BA0
const char *__fastcall UpdateStatGameWithIntegerTrack::GetClassname(UpdateStatGameWithIntegerTrack *this)
{
  return UpdateStatGameWithIntegerTrack::sClassName;
}

// File Line: 179
// RVA: 0x29F2F0
void __fastcall UpdateStatGameWithIntegerTrack::~UpdateStatGameWithIntegerTrack(UpdateStatGameWithIntegerTrack *this)
{
  UpdateStatGameWithIntegerTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&UpdateStatGameWithIntegerTrack::`vftable';
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

// File Line: 202
// RVA: 0x2C2B90
const char *__fastcall UpdateStatGameWithFloatTrack::GetClassname(UpdateStatGameWithFloatTrack *this)
{
  return UpdateStatGameWithFloatTrack::sClassName;
}

// File Line: 213
// RVA: 0x29F280
void __fastcall UpdateStatGameWithFloatTrack::~UpdateStatGameWithFloatTrack(UpdateStatGameWithFloatTrack *this)
{
  UpdateStatGameWithFloatTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&UpdateStatGameWithFloatTrack::`vftable';
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

// File Line: 236
// RVA: 0x324540
UpdateStatGameWithUpdateTimeTrack *__fastcall UpdateStatGameWithUpdateTimeTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x40ui64,
         "MemberMap::UpdateStatGameWithUpdateTimeTrack",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, UpdateStatGameWithUpdateTimeTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<UpdateStatGameWithUpdateTimeTask>::`vftable';
  *(_QWORD *)v1 = &UpdateStatGameWithUpdateTimeTrack::`vftable';
  *((_DWORD *)v1 + 14) = -1;
  return (UpdateStatGameWithUpdateTimeTrack *)v1;
}

// File Line: 245
// RVA: 0x29F360
void __fastcall UpdateStatGameWithUpdateTimeTrack::~UpdateStatGameWithUpdateTimeTrack(UpdateStatGameWithUpdateTimeTrack *this)
{
  UpdateStatGameWithUpdateTimeTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&UpdateStatGameWithUpdateTimeTrack::`vftable';
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

// File Line: 258
// RVA: 0x313800
void __fastcall ShootTrackTU::ShootTrackTU(ShootTrackTU *this)
{
  ShootTrackTU *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ShootTrackTU::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ShootTaskTU>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ShootTrackTU::`vftable';
  v1->mFireOriginTarget.mValue = 1;
  v1->mFireOrigin.mOffset = 1i64;
  BinString::Set(&v1->mFireOrigin, &customWorldMapCaption);
  *(_WORD *)&v1->mTraceBullet = 257;
  v1->mUseAimDirection = 1;
}

// File Line: 261
// RVA: 0x320740
void __fastcall ShootTrackTU::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::ShootTrackTU", 0i64, 1u);
  if ( v0 )
    ShootTrackTU::ShootTrackTU((ShootTrackTU *)v0);
}

// File Line: 293
// RVA: 0x2BE140
__int64 __fastcall CharacterSetVisualDamageTrack::GetClassNameUID(CharacterSetVisualDamageTrack *this)
{
  return CharacterSetVisualDamageTrack::sClassNameUID;
}

// File Line: 302
// RVA: 0x29ADF0
void __fastcall CharacterSetVisualDamageTrack::~CharacterSetVisualDamageTrack(CharacterSetVisualDamageTrack *this)
{
  CharacterSetVisualDamageTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CharacterSetVisualDamageTrack::`vftable';
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

// File Line: 331
// RVA: 0x2C1150
const char *__fastcall DoorStateTrack::GetClassname(DoorStateTrack *this)
{
  return DoorStateTrack::sClassName;
}

// File Line: 341
// RVA: 0x29B540
void __fastcall DoorStateTrack::~DoorStateTrack(DoorStateTrack *this)
{
  DoorStateTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DoorStateTrack::`vftable';
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

// File Line: 368
// RVA: 0x29C4D0
void __fastcall MotionIntentionFilterTrack::~MotionIntentionFilterTrack(MotionIntentionFilterTrack *this)
{
  MotionIntentionFilterTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionFilterTrack::`vftable';
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

// File Line: 370
// RVA: 0x2C1AA0
const char *__fastcall MotionIntentionFilterTrack::GetClassname(MotionIntentionFilterTrack *this)
{
  return MotionIntentionFilterTrack::sClassName;
}

// File Line: 383
// RVA: 0x29C460
void __fastcall MotionIntentionCOMTrack::~MotionIntentionCOMTrack(MotionIntentionCOMTrack *this)
{
  MotionIntentionCOMTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionCOMTrack::`vftable';
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

// File Line: 385
// RVA: 0x2C1A90
const char *__fastcall MotionIntentionCOMTrack::GetClassname(MotionIntentionCOMTrack *this)
{
  return MotionIntentionCOMTrack::sClassName;
}

// File Line: 411
// RVA: 0x29C2A0
void __fastcall MinimumDistanceTrack::~MinimumDistanceTrack(MinimumDistanceTrack *this)
{
  MinimumDistanceTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&MinimumDistanceTrack::`vftable';
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

// File Line: 413
// RVA: 0x31CD50
MinimumDistanceTrack *__fastcall MinimumDistanceTrack::Create()
{
  MinimumDistanceTrack *result; // rax
  MinimumDistanceTrack *v1; // rbx

  result = (MinimumDistanceTrack *)UFG::qMemoryPool2::Allocate(
                                     &gActionTreeMemoryPool,
                                     0x48ui64,
                                     "MemberMap::MinimumDistanceTrack",
                                     0i64,
                                     1u);
  v1 = result;
  if ( result )
  {
    ITrack::ITrack((ITrack *)&result->vfptr, MinimumDistanceTrack::sClassNameUID);
    v1->vfptr = (Expression::IMemberMapVtbl *)&Track<MinimumDistanceTask>::`vftable';
    v1->vfptr = (Expression::IMemberMapVtbl *)&MinimumDistanceTrack::`vftable';
    *(_QWORD *)&v1->mTargetType.mValue = 0i64;
    v1->mTimetoMinDistance = 0.0;
    v1->mTargetMovment = 0.5;
    result = v1;
  }
  return result;
}

// File Line: 454
// RVA: 0x299C80
void __fastcall AttackCollisionTrack::~AttackCollisionTrack(AttackCollisionTrack *this)
{
  AttackCollisionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx
  ExpressionParameterInt *v4; // rcx
  char *v5; // rcx
  ExpressionParameterInt *v6; // rcx
  char *v7; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackCollisionTrack::`vftable';
  v2 = &this->mWeaponDamage;
  if ( !(~LOBYTE(v2->text.mOffset) & 1) )
  {
    if ( v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v3 = (char *)v2 + (v2->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v3 != BinString::sEmptyString )
        operator delete[](v3);
    }
  }
  v4 = &v1->mPropDamage;
  if ( !(~LOBYTE(v1->mPropDamage.text.mOffset) & 1) )
  {
    if ( v4->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v5 = (char *)v4 + (v4->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v5 != BinString::sEmptyString )
        operator delete[](v5);
    }
  }
  v6 = &v1->mDamage;
  if ( !(~LOBYTE(v1->mDamage.text.mOffset) & 1) )
  {
    if ( v6->text.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v7 = (char *)v6 + (v6->text.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v7 != BinString::sEmptyString )
        operator delete[](v7);
    }
  }
  NodeRefTrack<AttackCollisionTask>::~NodeRefTrack<AttackCollisionTask>((NodeRefTrack<AttackCollisionTask> *)&v1->vfptr);
}

// File Line: 456
// RVA: 0x315430
void __fastcall AttackCollisionTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0xC8ui64, "MemberMap::AttackCollisionTrack", 0i64, 1u);
  if ( v0 )
    AttackCollisionTrack::AttackCollisionTrack((AttackCollisionTrack *)v0);
}

// File Line: 576
// RVA: 0x299E00
void __fastcall AttackTimerTrack::~AttackTimerTrack(AttackTimerTrack *this)
{
  AttackTimerTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AttackTimerTrack::`vftable';
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

// File Line: 578
// RVA: 0x2BDC90
__int64 __fastcall AttackTimerTrack::GetClassNameUID(AttackTimerTrack *this)
{
  return AttackTimerTrack::sClassNameUID;
}

// File Line: 600
// RVA: 0x29DC60
void __fastcall SetEngineDamageTrack::~SetEngineDamageTrack(SetEngineDamageTrack *this)
{
  SetEngineDamageTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetEngineDamageTrack::`vftable';
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

// File Line: 602
// RVA: 0x320490
SetEngineDamageTrack *__fastcall SetEngineDamageTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::SetEngineDamageTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, SetEngineDamageTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<SetEngineDamageTask>::`vftable';
  *(_QWORD *)v1 = &SetEngineDamageTrack::`vftable';
  *((_DWORD *)v1 + 14) = 0;
  return (SetEngineDamageTrack *)v1;
}

// File Line: 630
// RVA: 0x29CBB0
void __fastcall OverrideDesiredFocusModeTrack::~OverrideDesiredFocusModeTrack(OverrideDesiredFocusModeTrack *this)
{
  OverrideDesiredFocusModeTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&OverrideDesiredFocusModeTrack::`vftable';
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

// File Line: 632
// RVA: 0x2BF020
__int64 __fastcall OverrideDesiredFocusModeTrack::GetClassNameUID(OverrideDesiredFocusModeTrack *this)
{
  return OverrideDesiredFocusModeTrack::sClassNameUID;
}

// File Line: 661
// RVA: 0x31E440
void __fastcall ParkourSyncPositionTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x58ui64, "MemberMap::ParkourSyncPositionTrack", 0i64, 1u);
  if ( v0 )
    ParkourSyncPositionTrack::ParkourSyncPositionTrack((ParkourSyncPositionTrack *)v0);
}

// File Line: 727
// RVA: 0x31E3A0
void __fastcall ParkourNeighborAdvanceTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::ParkourNeighborAdvanceTrack", 0i64, 1u);
  if ( v0 )
    ParkourNeighborAdvanceTrack::ParkourNeighborAdvanceTrack((ParkourNeighborAdvanceTrack *)v0);
}

// File Line: 745
// RVA: 0x2C0FB0
const char *__fastcall CoverSyncPositionTrack::GetClassname(CoverSyncPositionTrack *this)
{
  return CoverSyncPositionTrack::sClassName;
}

// File Line: 780
// RVA: 0x2BF0E0
__int64 __fastcall ParkourConstrainTrack::GetClassNameUID(ParkourConstrainTrack *this)
{
  return ParkourConstrainTrack::sClassNameUID;
}

// File Line: 847
// RVA: 0x2BE2D0
__int64 __fastcall CoverHoldPositionTrack::GetClassNameUID(CoverHoldPositionTrack *this)
{
  return CoverHoldPositionTrack::sClassNameUID;
}

// File Line: 866
// RVA: 0x2C0F90
const char *__fastcall CoverProbeForwardAndLatchTrack::GetClassname(CoverProbeForwardAndLatchTrack *this)
{
  return CoverProbeForwardAndLatchTrack::sClassName;
}

// File Line: 889
// RVA: 0x2BE2E0
__int64 __fastcall CoverProbeAndLatchTrack::GetClassNameUID(CoverProbeAndLatchTrack *this)
{
  return CoverProbeAndLatchTrack::sClassNameUID;
}

// File Line: 912
// RVA: 0x2C0FA0
const char *__fastcall CoverSetPopoutSideTrack::GetClassname(CoverSetPopoutSideTrack *this)
{
  return CoverSetPopoutSideTrack::sClassName;
}

// File Line: 931
// RVA: 0x2BE560
__int64 __fastcall DynamicWallHandleTrack::GetClassNameUID(DynamicWallHandleTrack *this)
{
  return DynamicWallHandleTrack::sClassNameUID;
}

// File Line: 960
// RVA: 0x29B690
void __fastcall EventTrack::~EventTrack(EventTrack *this)
{
  EventTrack *v1; // rbx
  char *v2; // rcx
  ExpressionParameterFloat *v3; // rcx
  char *v4; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&EventTrack::`vftable';
  if ( !(~LOBYTE(this->mEventName.mOffset) & 1) )
  {
    if ( this->mEventName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v2 = (char *)&this->mEventName + (this->mEventName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v2 != BinString::sEmptyString )
        operator delete[](v2);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&ITrack::`vftable';
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
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 962
// RVA: 0x2BE590
__int64 __fastcall EventTrack::GetClassNameUID(EventTrack *this)
{
  return EventTrack::sClassNameUID;
}

// File Line: 983
// RVA: 0x2BDBD0
__int64 __fastcall ApplyStimulusEmitterToTargetTrack::GetClassNameUID(ApplyStimulusEmitterToTargetTrack *this)
{
  return ApplyStimulusEmitterToTargetTrack::sClassNameUID;
}

// File Line: 1022
// RVA: 0x320970
void __fastcall SkookumTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::SkookumTrack", 0i64, 1u);
  if ( v0 )
    SkookumTrack::SkookumTrack((SkookumTrack *)v0);
}

// File Line: 1054
// RVA: 0x2C0920
const char *__fastcall AttackRightsTrack::GetClassname(AttackRightsTrack *this)
{
  return AttackRightsTrack::sClassName;
}

// File Line: 1072
// RVA: 0x3137A0
void __fastcall ShootTrack::ShootTrack(ShootTrack *this)
{
  ShootTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ShootTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ShootTask>::`vftable';
  v1->vfptr = (Expression::IMemberMapVtbl *)&ShootTrack::`vftable';
  v1->mFireOrigin.mOffset = 1i64;
  BinString::Set(&v1->mFireOrigin, &customWorldMapCaption);
  *(_WORD *)&v1->mTraceBullet = 257;
}

// File Line: 1075
// RVA: 0x2C23B0
const char *__fastcall ShootTrack::GetClassname(ShootTrack *this)
{
  return ShootTrack::sClassName;
}

// File Line: 1101
// RVA: 0x31FCC0
void __fastcall ReloadGunTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::ReloadGunTrack", 0i64, 1u);
  if ( v0 )
    ReloadGunTrack::ReloadGunTrack((ReloadGunTrack *)v0);
}

// File Line: 1130
// RVA: 0x29C310
void __fastcall MissionFailTriggerTrack::~MissionFailTriggerTrack(MissionFailTriggerTrack *this)
{
  MissionFailTriggerTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&MissionFailTriggerTrack::`vftable';
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

// File Line: 1133
// RVA: 0x2C1A60
const char *__fastcall MissionFailTriggerTrack::GetClassname(MissionFailTriggerTrack *this)
{
  return MissionFailTriggerTrack::sClassName;
}

// File Line: 1156
// RVA: 0x2997C0
void __fastcall AimingFreeAimIntentionResetTrack::~AimingFreeAimIntentionResetTrack(AimingFreeAimIntentionResetTrack *this)
{
  AimingFreeAimIntentionResetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AimingFreeAimIntentionResetTrack::`vftable';
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

// File Line: 1158
// RVA: 0x314F40
void __fastcall AimingFreeAimIntentionResetTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x38ui64,
         "MemberMap::AimingFreeAimIntentionResetTrack",
         0i64,
         1u);
  if ( v0 )
    AimingFreeAimIntentionResetTrack::AimingFreeAimIntentionResetTrack((AimingFreeAimIntentionResetTrack *)v0);
}

// File Line: 1170
// RVA: 0x2998A0
void __fastcall AimingSoftLockTrack::~AimingSoftLockTrack(AimingSoftLockTrack *this)
{
  AimingSoftLockTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AimingSoftLockTrack::`vftable';
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

// File Line: 1172
// RVA: 0x2C07D0
const char *__fastcall AimingSoftLockTrack::GetClassname(AimingSoftLockTrack *this)
{
  return AimingSoftLockTrack::sClassName;
}

// File Line: 1184
// RVA: 0x299830
void __fastcall AimingSoftLockDisableTrack::~AimingSoftLockDisableTrack(AimingSoftLockDisableTrack *this)
{
  AimingSoftLockDisableTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AimingSoftLockDisableTrack::`vftable';
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

// File Line: 1186
// RVA: 0x2BDB20
__int64 __fastcall AimingSoftLockDisableTrack::GetClassNameUID(AimingSoftLockDisableTrack *this)
{
  return AimingSoftLockDisableTrack::sClassNameUID;
}

// File Line: 1198
// RVA: 0x299750
void __fastcall AimingFreeAimConeClampTrack::~AimingFreeAimConeClampTrack(AimingFreeAimConeClampTrack *this)
{
  AimingFreeAimConeClampTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AimingFreeAimConeClampTrack::`vftable';
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

// File Line: 1200
// RVA: 0x2BDB00
__int64 __fastcall AimingFreeAimConeClampTrack::GetClassNameUID(AimingFreeAimConeClampTrack *this)
{
  return AimingFreeAimConeClampTrack::sClassNameUID;
}

// File Line: 1219
// RVA: 0x29D620
void __fastcall PowerManagementSuspendPermanentlyTrack::~PowerManagementSuspendPermanentlyTrack(PowerManagementSuspendPermanentlyTrack *this)
{
  PowerManagementSuspendPermanentlyTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PowerManagementSuspendPermanentlyTrack::`vftable';
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

// File Line: 1221
// RVA: 0x31F040
void __fastcall PowerManagementSuspendPermanentlyTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x38ui64,
         "MemberMap::PowerManagementSuspendPermanentlyTrack",
         0i64,
         1u);
  if ( v0 )
    PowerManagementSuspendPermanentlyTrack::PowerManagementSuspendPermanentlyTrack((PowerManagementSuspendPermanentlyTrack *)v0);
}

// File Line: 1233
// RVA: 0x29C540
void __fastcall MotionIntentionHoldTrack::~MotionIntentionHoldTrack(MotionIntentionHoldTrack *this)
{
  MotionIntentionHoldTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionHoldTrack::`vftable';
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

// File Line: 1235
// RVA: 0x31D1F0
void __fastcall MotionIntentionHoldTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::MotionIntentionHoldTrack", 0i64, 1u);
  if ( v0 )
    MotionIntentionHoldTrack::MotionIntentionHoldTrack((MotionIntentionHoldTrack *)v0);
}

// File Line: 1253
// RVA: 0x2C0890
const char *__fastcall AttachmentTransferTrack::GetClassname(AttachmentTransferTrack *this)
{
  return AttachmentTransferTrack::sClassName;
}

// File Line: 1283
// RVA: 0x29D2F0
void __fastcall PlaybackSpeedModifierEnabledTrack::~PlaybackSpeedModifierEnabledTrack(PlaybackSpeedModifierEnabledTrack *this)
{
  PlaybackSpeedModifierEnabledTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PlaybackSpeedModifierEnabledTrack::`vftable';
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

// File Line: 1285
// RVA: 0x2C1EB0
const char *__fastcall PlaybackSpeedModifierEnabledTrack::GetClassname(PlaybackSpeedModifierEnabledTrack *this)
{
  return PlaybackSpeedModifierEnabledTrack::sClassName;
}

// File Line: 1299
// RVA: 0x29AED0
void __fastcall CharacterStatModifyTrack::~CharacterStatModifyTrack(CharacterStatModifyTrack *this)
{
  CharacterStatModifyTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CharacterStatModifyTrack::`vftable';
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

// File Line: 1301
// RVA: 0x2C0E10
const char *__fastcall CharacterStatModifyTrack::GetClassname(CharacterStatModifyTrack *this)
{
  return CharacterStatModifyTrack::sClassName;
}

// File Line: 1326
// RVA: 0x29DD40
void __fastcall SetOutOfFightTrack::~SetOutOfFightTrack(SetOutOfFightTrack *this)
{
  SetOutOfFightTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetOutOfFightTrack::`vftable';
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

// File Line: 1331
// RVA: 0x2BF6E0
__int64 __fastcall SetOutOfFightTrack::GetClassNameUID(SetOutOfFightTrack *this)
{
  return SetOutOfFightTrack::sClassNameUID;
}

// File Line: 1347
// RVA: 0x29D440
void __fastcall PlayerGrappleTrack::~PlayerGrappleTrack(PlayerGrappleTrack *this)
{
  PlayerGrappleTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayerGrappleTrack::`vftable';
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

// File Line: 1350
// RVA: 0x2BF250
__int64 __fastcall PlayerGrappleTrack::GetClassNameUID(PlayerGrappleTrack *this)
{
  return PlayerGrappleTrack::sClassNameUID;
}

// File Line: 1362
// RVA: 0x29E1E0
void __fastcall StruggleTrack::~StruggleTrack(StruggleTrack *this)
{
  StruggleTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&StruggleTrack::`vftable';
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

// File Line: 1364
// RVA: 0x321450
void __fastcall StruggleTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::StruggleTrack", 0i64, 1u);
  if ( v0 )
    StruggleTrack::StruggleTrack((StruggleTrack *)v0);
}

// File Line: 1390
// RVA: 0x29E170
void __fastcall Struggle2Track::~Struggle2Track(Struggle2Track *this)
{
  Struggle2Track *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Struggle2Track::`vftable';
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

// File Line: 1392
// RVA: 0x2BF880
__int64 __fastcall Struggle2Track::GetClassNameUID(Struggle2Track *this)
{
  return Struggle2Track::sClassNameUID;
}

// File Line: 1421
// RVA: 0x2C0720
const char *__fastcall ActorStateCounterTrack::GetClassname(ActorStateCounterTrack *this)
{
  return ActorStateCounterTrack::sClassName;
}

// File Line: 1443
// RVA: 0x2BE700
__int64 __fastcall GameStatEventTrack::GetClassNameUID(GameStatEventTrack *this)
{
  return GameStatEventTrack::sClassNameUID;
}

// File Line: 1466
// RVA: 0x29BA40
void __fastcall GameStatDistanceTrack::~GameStatDistanceTrack(GameStatDistanceTrack *this)
{
  GameStatDistanceTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&GameStatDistanceTrack::`vftable';
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

// File Line: 1468
// RVA: 0x319970
void __fastcall GameStatDistanceTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::GameStatDistanceTrack", 0i64, 1u);
  if ( v0 )
    GameStatDistanceTrack::GameStatDistanceTrack((GameStatDistanceTrack *)v0);
}

// File Line: 1486
// RVA: 0x29BAB0
void __fastcall GameStatSpecialMoveTrack::~GameStatSpecialMoveTrack(GameStatSpecialMoveTrack *this)
{
  GameStatSpecialMoveTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&GameStatSpecialMoveTrack::`vftable';
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

// File Line: 1488
// RVA: 0x319A10
void __fastcall GameStatSpecialMoveTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::GameStatSpecialMoveTrack", 0i64, 1u);
  if ( v0 )
    GameStatSpecialMoveTrack::GameStatSpecialMoveTrack((GameStatSpecialMoveTrack *)v0);
}

// File Line: 1506
// RVA: 0x299600
void __fastcall AccuracyOverrideTrack::~AccuracyOverrideTrack(AccuracyOverrideTrack *this)
{
  AccuracyOverrideTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AccuracyOverrideTrack::`vftable';
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

// File Line: 1508
// RVA: 0x2C06A0
const char *__fastcall AccuracyOverrideTrack::GetClassname(AccuracyOverrideTrack *this)
{
  return AccuracyOverrideTrack::sClassName;
}

// File Line: 1531
// RVA: 0x299590
void __fastcall AccuracyEnsureMissTrack::~AccuracyEnsureMissTrack(AccuracyEnsureMissTrack *this)
{
  AccuracyEnsureMissTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AccuracyEnsureMissTrack::`vftable';
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

// File Line: 1533
// RVA: 0x314750
void __fastcall AccuracyEnsureMissTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::AccuracyEnsureMissTrack", 0i64, 1u);
  if ( v0 )
    AccuracyEnsureMissTrack::AccuracyEnsureMissTrack((AccuracyEnsureMissTrack *)v0);
}

// File Line: 1545
// RVA: 0x29D8A0
void __fastcall ReticleSizeOverrideTrack::~ReticleSizeOverrideTrack(ReticleSizeOverrideTrack *this)
{
  ReticleSizeOverrideTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ReticleSizeOverrideTrack::`vftable';
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

// File Line: 1547
// RVA: 0x2BF590
__int64 __fastcall ReticleSizeOverrideTrack::GetClassNameUID(ReticleSizeOverrideTrack *this)
{
  return ReticleSizeOverrideTrack::sClassNameUID;
}

// File Line: 1582
// RVA: 0x29AE60
void __fastcall CharacterStatModifyIntTrack::~CharacterStatModifyIntTrack(CharacterStatModifyIntTrack *this)
{
  CharacterStatModifyIntTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CharacterStatModifyIntTrack::`vftable';
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

// File Line: 1584
// RVA: 0x2C0E00
const char *__fastcall CharacterStatModifyIntTrack::GetClassname(CharacterStatModifyIntTrack *this)
{
  return CharacterStatModifyIntTrack::sClassName;
}

// File Line: 1609
// RVA: 0x29C5B0
void __fastcall MotionIntentionSetRelativeToPlayerTrack::~MotionIntentionSetRelativeToPlayerTrack(MotionIntentionSetRelativeToPlayerTrack *this)
{
  MotionIntentionSetRelativeToPlayerTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&MotionIntentionSetRelativeToPlayerTrack::`vftable';
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

// File Line: 1611
// RVA: 0x2BEE20
__int64 __fastcall MotionIntentionSetRelativeToPlayerTrack::GetClassNameUID(MotionIntentionSetRelativeToPlayerTrack *this)
{
  return MotionIntentionSetRelativeToPlayerTrack::sClassNameUID;
}

// File Line: 1628
// RVA: 0x29BB90
void __fastcall GunConsumeAmmoTrack::~GunConsumeAmmoTrack(GunConsumeAmmoTrack *this)
{
  GunConsumeAmmoTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&GunConsumeAmmoTrack::`vftable';
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

// File Line: 1630
// RVA: 0x2C1430
const char *__fastcall GunConsumeAmmoTrack::GetClassname(GunConsumeAmmoTrack *this)
{
  return GunConsumeAmmoTrack::sClassName;
}

// File Line: 1650
// RVA: 0x29DE40
void __fastcall SetStateFlagTrack::~SetStateFlagTrack(SetStateFlagTrack *this)
{
  SetStateFlagTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetStateFlagTrack::`vftable';
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

// File Line: 1652
// RVA: 0x3206A0
void __fastcall SetStateFlagTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::SetStateFlagTrack", 0i64, 1u);
  if ( v0 )
    SetStateFlagTrack::SetStateFlagTrack((SetStateFlagTrack *)v0);
}

// File Line: 1671
// RVA: 0x29BED0
void __fastcall HitRecordSetBerserkAttackFlagTrack::~HitRecordSetBerserkAttackFlagTrack(HitRecordSetBerserkAttackFlagTrack *this)
{
  HitRecordSetBerserkAttackFlagTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&HitRecordSetBerserkAttackFlagTrack::`vftable';
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

// File Line: 1673
// RVA: 0x2BE950
__int64 __fastcall HitRecordSetBerserkAttackFlagTrack::GetClassNameUID(HitRecordSetBerserkAttackFlagTrack *this)
{
  return HitRecordSetBerserkAttackFlagTrack::sClassNameUID;
}

// File Line: 1690
// RVA: 0x29D360
void __fastcall PlayerBuffActivateTrack::~PlayerBuffActivateTrack(PlayerBuffActivateTrack *this)
{
  PlayerBuffActivateTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayerBuffActivateTrack::`vftable';
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

// File Line: 1692
// RVA: 0x31E7B0
void __fastcall PlayerBuffActivateTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::PlayerBuffActivateTrack", 0i64, 1u);
  if ( v0 )
    PlayerBuffActivateTrack::PlayerBuffActivateTrack((PlayerBuffActivateTrack *)v0);
}

// File Line: 1709
// RVA: 0x29C380
void __fastcall MoneyDropTrack::~MoneyDropTrack(MoneyDropTrack *this)
{
  MoneyDropTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&MoneyDropTrack::`vftable';
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

// File Line: 1712
// RVA: 0x2BEDD0
__int64 __fastcall MoneyDropTrack::GetClassNameUID(MoneyDropTrack *this)
{
  return MoneyDropTrack::sClassNameUID;
}

// File Line: 1723
// RVA: 0x29C3F0
void __fastcall MoneyPickupTrack::~MoneyPickupTrack(MoneyPickupTrack *this)
{
  MoneyPickupTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&MoneyPickupTrack::`vftable';
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

// File Line: 1726
// RVA: 0x31CF10
MoneyPickupTrack *__fastcall MoneyPickupTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::MoneyPickupTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, MoneyPickupTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<MoneyPickupTask>::`vftable';
  *(_QWORD *)v1 = &MoneyPickupTrack::`vftable';
  return (MoneyPickupTrack *)v1;
}

// File Line: 1737
// RVA: 0x29C130
void __fastcall ItemPickupTrack::~ItemPickupTrack(ItemPickupTrack *this)
{
  ItemPickupTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ItemPickupTrack::`vftable';
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

// File Line: 1740
// RVA: 0x31C820
ItemPickupTrack *__fastcall ItemPickupTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::ItemPickupTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, ItemPickupTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<ItemPickupTask>::`vftable';
  *(_QWORD *)v1 = &ItemPickupTrack::`vftable';
  return (ItemPickupTrack *)v1;
}

// File Line: 1751
// RVA: 0x29B810
void __fastcall FaceMeterActivateTrack::~FaceMeterActivateTrack(FaceMeterActivateTrack *this)
{
  FaceMeterActivateTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&FaceMeterActivateTrack::`vftable';
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

// File Line: 1753
// RVA: 0x2BE5D0
__int64 __fastcall FaceMeterActivateTrack::GetClassNameUID(FaceMeterActivateTrack *this)
{
  return FaceMeterActivateTrack::sClassNameUID;
}

// File Line: 1765
// RVA: 0x29B7A0
void __fastcall FaceInteractionResultSetTrack::~FaceInteractionResultSetTrack(FaceInteractionResultSetTrack *this)
{
  FaceInteractionResultSetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&FaceInteractionResultSetTrack::`vftable';
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

// File Line: 1767
// RVA: 0x2BE5C0
__int64 __fastcall FaceInteractionResultSetTrack::GetClassNameUID(FaceInteractionResultSetTrack *this)
{
  return FaceInteractionResultSetTrack::sClassNameUID;
}

// File Line: 1789
// RVA: 0x29CFC0
void __fastcall ParkourHandleTrack::~ParkourHandleTrack(ParkourHandleTrack *this)
{
  ParkourHandleTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ParkourHandleTrack::`vftable';
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

// File Line: 1791
// RVA: 0x2C1D90
const char *__fastcall ParkourHandleTrack::GetClassname(ParkourHandleTrack *this)
{
  return ParkourHandleTrack::sClassName;
}

// File Line: 1814
// RVA: 0x29C0C0
void __fastcall InvulnerableTrack::~InvulnerableTrack(InvulnerableTrack *this)
{
  InvulnerableTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&InvulnerableTrack::`vftable';
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

// File Line: 1816
// RVA: 0x2BEA30
__int64 __fastcall InvulnerableTrack::GetClassNameUID(InvulnerableTrack *this)
{
  return InvulnerableTrack::sClassNameUID;
}

// File Line: 1828
// RVA: 0x29E020
void __fastcall SocialSetEnabledTrack::~SocialSetEnabledTrack(SocialSetEnabledTrack *this)
{
  SocialSetEnabledTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SocialSetEnabledTrack::`vftable';
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

// File Line: 1830
// RVA: 0x321060
void __fastcall SocialSetEnabledTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::SocialSetEnabledTrack", 0i64, 1u);
  if ( v0 )
    SocialSetEnabledTrack::SocialSetEnabledTrack((SocialSetEnabledTrack *)v0);
}

// File Line: 1853
// RVA: 0x29E090
void __fastcall SocialSetFaceActionStateTrack::~SocialSetFaceActionStateTrack(SocialSetFaceActionStateTrack *this)
{
  SocialSetFaceActionStateTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SocialSetFaceActionStateTrack::`vftable';
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

// File Line: 1855
// RVA: 0x2C24D0
const char *__fastcall SocialSetFaceActionStateTrack::GetClassname(SocialSetFaceActionStateTrack *this)
{
  return SocialSetFaceActionStateTrack::sClassName;
}

// File Line: 1876
// RVA: 0x29E100
void __fastcall SocialSetFastTalkSuccessTrack::~SocialSetFastTalkSuccessTrack(SocialSetFastTalkSuccessTrack *this)
{
  SocialSetFastTalkSuccessTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SocialSetFastTalkSuccessTrack::`vftable';
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

// File Line: 1878
// RVA: 0x2C24E0
const char *__fastcall SocialSetFastTalkSuccessTrack::GetClassname(SocialSetFastTalkSuccessTrack *this)
{
  return SocialSetFastTalkSuccessTrack::sClassName;
}

// File Line: 1898
// RVA: 0x29DFB0
void __fastcall SocialFaceActionDisplayConfirmationDialogTrack::~SocialFaceActionDisplayConfirmationDialogTrack(SocialFaceActionDisplayConfirmationDialogTrack *this)
{
  SocialFaceActionDisplayConfirmationDialogTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SocialFaceActionDisplayConfirmationDialogTrack::`vftable';
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

// File Line: 1900
// RVA: 0x320BF0
SocialFaceActionDisplayConfirmationDialogTrack *__fastcall SocialFaceActionDisplayConfirmationDialogTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x38ui64,
         "MemberMap::SocialFaceActionDisplayConfirmationDialogTrack",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, SocialFaceActionDisplayConfirmationDialogTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<SocialFaceActionDisplayConfirmationDialogTask>::`vftable';
  *(_QWORD *)v1 = &SocialFaceActionDisplayConfirmationDialogTrack::`vftable';
  return (SocialFaceActionDisplayConfirmationDialogTrack *)v1;
}

// File Line: 1911
// RVA: 0x29EE70
void __fastcall TriggerRecoilPostEffectTrack::~TriggerRecoilPostEffectTrack(TriggerRecoilPostEffectTrack *this)
{
  TriggerRecoilPostEffectTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&TriggerRecoilPostEffectTrack::`vftable';
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

// File Line: 1913
// RVA: 0x2C2A90
const char *__fastcall TriggerRecoilPostEffectTrack::GetClassname(TriggerRecoilPostEffectTrack *this)
{
  return TriggerRecoilPostEffectTrack::sClassName;
}

// File Line: 1942
// RVA: 0x3147A0
void __fastcall AccuracyModifierTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x68ui64, "MemberMap::AccuracyModifierTrack", 0i64, 1u);
  if ( v0 )
    AccuracyModifierTrack::AccuracyModifierTrack((AccuracyModifierTrack *)v0);
}

// File Line: 1973
// RVA: 0x314570
void __fastcall AIOutlineActivateTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::AIOutlineActivateTrack", 0i64, 1u);
  if ( v0 )
    AIOutlineActivateTrack::AIOutlineActivateTrack((AIOutlineActivateTrack *)v0);
}

// File Line: 1993
// RVA: 0x317670
void __fastcall CollectibleCollectTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::CollectibleCollectTrack", 0i64, 1u);
  if ( v0 )
    CollectibleCollectTrack::CollectibleCollectTrack((CollectibleCollectTrack *)v0);
}

// File Line: 2018
// RVA: 0x2BF730
__int64 __fastcall SimObjectFlagSetTrack::GetClassNameUID(SimObjectFlagSetTrack *this)
{
  return SimObjectFlagSetTrack::sClassNameUID;
}

// File Line: 2069
// RVA: 0x320650
void __fastcall SetRollStabilityTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::SetRollStabilityTrack", 0i64, 1u);
  if ( v0 )
    SetRollStabilityTrack::SetRollStabilityTrack((SetRollStabilityTrack *)v0);
}

// File Line: 2087
// RVA: 0x29DBF0
void __fastcall SetCharacterOnFireTrack::~SetCharacterOnFireTrack(SetCharacterOnFireTrack *this)
{
  SetCharacterOnFireTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetCharacterOnFireTrack::`vftable';
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

// File Line: 2089
// RVA: 0x2C2310
const char *__fastcall SetCharacterOnFireTrack::GetClassname(SetCharacterOnFireTrack *this)
{
  return SetCharacterOnFireTrack::sClassName;
}

// File Line: 2103
// RVA: 0x29DB80
void __fastcall SetCharacterInvulnerableToFireTrack::~SetCharacterInvulnerableToFireTrack(SetCharacterInvulnerableToFireTrack *this)
{
  SetCharacterInvulnerableToFireTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetCharacterInvulnerableToFireTrack::`vftable';
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

// File Line: 2105
// RVA: 0x320310
SetCharacterInvulnerableToFireTrack *__fastcall SetCharacterInvulnerableToFireTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x38ui64,
         "MemberMap::SetCharacterInvulnerableToFireTrack",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, SetCharacterInvulnerableToFireTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<SetCharacterInvulnerableToFireTask>::`vftable';
  *(_QWORD *)v1 = &SetCharacterInvulnerableToFireTrack::`vftable';
  return (SetCharacterInvulnerableToFireTrack *)v1;
}

// File Line: 2119
// RVA: 0x29B4D0
void __fastcall DisableSelfIlluminationTrack::~DisableSelfIlluminationTrack(DisableSelfIlluminationTrack *this)
{
  DisableSelfIlluminationTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DisableSelfIlluminationTrack::`vftable';
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

// File Line: 2121
// RVA: 0x318A70
DisableSelfIlluminationTrack *__fastcall DisableSelfIlluminationTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x38ui64,
         "MemberMap::DisableSelfIlluminationTrack",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, DisableSelfIlluminationTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<DisableSelfIlluminationTask>::`vftable';
  *(_QWORD *)v1 = &DisableSelfIlluminationTrack::`vftable';
  return (DisableSelfIlluminationTrack *)v1;
}

// File Line: 2135
// RVA: 0x29D3D0
void __fastcall PlayerGainHealthBasedOnActiveBuffTrack::~PlayerGainHealthBasedOnActiveBuffTrack(PlayerGainHealthBasedOnActiveBuffTrack *this)
{
  PlayerGainHealthBasedOnActiveBuffTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayerGainHealthBasedOnActiveBuffTrack::`vftable';
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

// File Line: 2137
// RVA: 0x2BF240
__int64 __fastcall PlayerGainHealthBasedOnActiveBuffTrack::GetClassNameUID(PlayerGainHealthBasedOnActiveBuffTrack *this)
{
  return PlayerGainHealthBasedOnActiveBuffTrack::sClassNameUID;
}

