// File Line: 59
// RVA: 0x29D280
void __fastcall PlayEffectTrack::~PlayEffectTrack(PlayEffectTrack *this)
{
  PlayEffectTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PlayEffectTrack::`vftable';
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

// File Line: 61
// RVA: 0x2C1EA0
const char *__fastcall PlayEffectTrack::GetClassname(PlayEffectTrack *this)
{
  return PlayEffectTrack::sClassName;
}

// File Line: 117
// RVA: 0x3FE260
void __fastcall RumbleTrack::~RumbleTrack(RumbleTrack *this)
{
  RumbleTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RumbleTrack::`vftable';
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

// File Line: 119
// RVA: 0x31FF70
void __fastcall RumbleTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "MemberMap::RumbleTrack", 0i64, 1u);
  if ( v0 )
    RumbleTrack::RumbleTrack((RumbleTrack *)v0);
}

// File Line: 156
// RVA: 0x29B8F0
void __fastcall FootStepLeftEffectTrack::~FootStepLeftEffectTrack(FootStepLeftEffectTrack *this)
{
  FootStepLeftEffectTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&FootStepLeftEffectTrack::`vftable';
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

// File Line: 158
// RVA: 0x3197C0
void __fastcall FootStepLeftEffectTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::FootStepLeftEffectTrack", 0i64, 1u);
  if ( v0 )
    FootStepLeftEffectTrack::FootStepLeftEffectTrack((FootStepLeftEffectTrack *)v0);
}

// File Line: 181
// RVA: 0x29B960
void __fastcall FootStepRightEffectTrack::~FootStepRightEffectTrack(FootStepRightEffectTrack *this)
{
  FootStepRightEffectTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&FootStepRightEffectTrack::`vftable';
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

// File Line: 183
// RVA: 0x319860
void __fastcall FootStepRightEffectTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::FootStepRightEffectTrack", 0i64, 1u);
  if ( v0 )
    FootStepRightEffectTrack::FootStepRightEffectTrack((FootStepRightEffectTrack *)v0);
}

// File Line: 206
// RVA: 0x29AFB0
void __fastcall CollisionEffectTrack::~CollisionEffectTrack(CollisionEffectTrack *this)
{
  CollisionEffectTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CollisionEffectTrack::`vftable';
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
// RVA: 0x2BE1F0
__int64 __fastcall CollisionEffectTrack::GetClassNameUID(CollisionEffectTrack *this)
{
  return CollisionEffectTrack::sClassNameUID;
}

// File Line: 239
// RVA: 0x29B5B0
void __fastcall EffectSurfaceCollisionTrack::~EffectSurfaceCollisionTrack(EffectSurfaceCollisionTrack *this)
{
  EffectSurfaceCollisionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&EffectSurfaceCollisionTrack::`vftable';
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
// RVA: 0x2BE570
__int64 __fastcall EffectSurfaceCollisionTrack::GetClassNameUID(EffectSurfaceCollisionTrack *this)
{
  return EffectSurfaceCollisionTrack::sClassNameUID;
}

// File Line: 283
// RVA: 0x29F880
void __fastcall VisualTreatmentTrack::~VisualTreatmentTrack(VisualTreatmentTrack *this)
{
  VisualTreatmentTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&VisualTreatmentTrack::`vftable';
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

// File Line: 285
// RVA: 0x3262D0
void __fastcall VisualTreatmentTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::VisualTreatmentTrack", 0i64, 1u);
  if ( v0 )
    VisualTreatmentTrack::VisualTreatmentTrack((VisualTreatmentTrack *)v0);
}

// File Line: 328
// RVA: 0x29B250
void __fastcall DamageEffectTrack::~DamageEffectTrack(DamageEffectTrack *this)
{
  DamageEffectTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DamageEffectTrack::`vftable';
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

// File Line: 330
// RVA: 0x2BE340
__int64 __fastcall DamageEffectTrack::GetClassNameUID(DamageEffectTrack *this)
{
  return DamageEffectTrack::sClassNameUID;
}

// File Line: 348
// RVA: 0x29D9C0
void __fastcall RimLightTargetTrack::~RimLightTargetTrack(RimLightTargetTrack *this)
{
  RimLightTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RimLightTargetTrack::`vftable';
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

// File Line: 351
// RVA: 0x2BF5B0
__int64 __fastcall RimLightTargetTrack::GetClassNameUID(RimLightTargetTrack *this)
{
  return RimLightTargetTrack::sClassNameUID;
}

// File Line: 368
// RVA: 0x29DA30
void __fastcall RimLightTrack::~RimLightTrack(RimLightTrack *this)
{
  RimLightTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RimLightTrack::`vftable';
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

// File Line: 371
// RVA: 0x2C2260
const char *__fastcall RimLightTrack::GetClassname(RimLightTrack *this)
{
  return RimLightTrack::sClassName;
}

// File Line: 384
// RVA: 0x299C10
void __fastcall ApplyWetnessOrSweatTrack::~ApplyWetnessOrSweatTrack(ApplyWetnessOrSweatTrack *this)
{
  ApplyWetnessOrSweatTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ApplyWetnessOrSweatTrack::`vftable';
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

// File Line: 387
// RVA: 0x315360
ApplyWetnessOrSweatTrack *__fastcall ApplyWetnessOrSweatTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::ApplyWetnessOrSweatTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, ApplyWetnessOrSweatTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<ApplyWetnessOrSweatTask>::`vftable';
  *(_QWORD *)v1 = &ApplyWetnessOrSweatTrack::`vftable';
  *((_DWORD *)v1 + 14) = -1082130432;
  *((_DWORD *)v1 + 15) = -1082130432;
  return (ApplyWetnessOrSweatTrack *)v1;
}

// File Line: 410
// RVA: 0x29C230
void __fastcall LightingRimBoostTrack::~LightingRimBoostTrack(LightingRimBoostTrack *this)
{
  LightingRimBoostTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&LightingRimBoostTrack::`vftable';
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

// File Line: 412
// RVA: 0x2BED20
__int64 __fastcall LightingRimBoostTrack::GetClassNameUID(LightingRimBoostTrack *this)
{
  return LightingRimBoostTrack::sClassNameUID;
}

// File Line: 430
// RVA: 0x29DCD0
void __fastcall SetHighlightingModeTrack::~SetHighlightingModeTrack(SetHighlightingModeTrack *this)
{
  SetHighlightingModeTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SetHighlightingModeTrack::`vftable';
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

// File Line: 432
// RVA: 0x2BF6C0
__int64 __fastcall SetHighlightingModeTrack::GetClassNameUID(SetHighlightingModeTrack *this)
{
  return SetHighlightingModeTrack::sClassNameUID;
}

