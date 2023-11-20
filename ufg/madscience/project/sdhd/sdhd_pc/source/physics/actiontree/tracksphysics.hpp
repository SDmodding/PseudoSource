// File Line: 25
// RVA: 0x29BB20
void __fastcall GravityTrack::~GravityTrack(GravityTrack *this)
{
  GravityTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&GravityTrack::`vftable;
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

// File Line: 27
// RVA: 0x319BF0
void __fastcall GravityTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::GravityTrack", 0i64, 1u);
  if ( v0 )
    GravityTrack::GravityTrack((GravityTrack *)v0);
}

// File Line: 48
// RVA: 0x29B460
void __fastcall DisableCollisionTrack::~DisableCollisionTrack(DisableCollisionTrack *this)
{
  DisableCollisionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DisableCollisionTrack::`vftable;
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

// File Line: 50
// RVA: 0x2C1130
const char *__fastcall DisableCollisionTrack::GetClassname(DisableCollisionTrack *this)
{
  return DisableCollisionTrack::sClassName;
}

// File Line: 68
// RVA: 0x31E670
void __fastcall PhysicsMotionTypeTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::PhysicsMotionTypeTrack", 0i64, 1u);
  if ( v0 )
    PhysicsMotionTypeTrack::PhysicsMotionTypeTrack((PhysicsMotionTypeTrack *)v0);
}

// File Line: 75
// RVA: 0x301ED0
UFG::qSymbol *__fastcall PhysicsMotionTypeTrack::GetCollisionGeoNameSymbol(PhysicsMotionTypeTrack *this, UFG::qSymbol *result)
{
  result->mUID = (unsigned int)this->mCollisionGeoName;
  return result;
}

// File Line: 92
// RVA: 0x2BE130
__int64 __fastcall CharacterPhysicsTrack::GetClassNameUID(CharacterPhysicsTrack *this)
{
  return CharacterPhysicsTrack::sClassNameUID;
}

// File Line: 111
// RVA: 0x2C0DC0
const char *__fastcall CharacterPhysicsSuperMassiveTrack::GetClassname(CharacterPhysicsSuperMassiveTrack *this)
{
  return CharacterPhysicsSuperMassiveTrack::sClassName;
}

// File Line: 122
// RVA: 0x29B3F0
void __fastcall DetailedOnGroundTrack::~DetailedOnGroundTrack(DetailedOnGroundTrack *this)
{
  DetailedOnGroundTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&DetailedOnGroundTrack::`vftable;
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

// File Line: 124
// RVA: 0x3188E0
void __fastcall DetailedOnGroundTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::DetailedOnGroundTrack", 0i64, 1u);
  if ( v0 )
    DetailedOnGroundTrack::DetailedOnGroundTrack((DetailedOnGroundTrack *)v0);
}

// File Line: 137
// RVA: 0x29F810
void __fastcall VelocitySlopeModeTrack::~VelocitySlopeModeTrack(VelocitySlopeModeTrack *this)
{
  VelocitySlopeModeTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&VelocitySlopeModeTrack::`vftable;
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

// File Line: 139
// RVA: 0x2C3010
const char *__fastcall VelocitySlopeModeTrack::GetClassname(VelocitySlopeModeTrack *this)
{
  return VelocitySlopeModeTrack::sClassName;
}

// File Line: 157
// RVA: 0x29DF40
void __fastcall SlopeLocomotionFixupTrack::~SlopeLocomotionFixupTrack(SlopeLocomotionFixupTrack *this)
{
  SlopeLocomotionFixupTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SlopeLocomotionFixupTrack::`vftable;
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

// File Line: 159
// RVA: 0x3209C0
SlopeLocomotionFixupTrack *__fastcall SlopeLocomotionFixupTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::SlopeLocomotionFixupTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, SlopeLocomotionFixupTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<SlopeLocomotionFixupTask>::`vftable;
  *(_QWORD *)v1 = &SlopeLocomotionFixupTrack::`vftable;
  *((_DWORD *)v1 + 14) = 1060437492;
  v1[60] = 1;
  return (SlopeLocomotionFixupTrack *)v1;
}

// File Line: 180
// RVA: 0x29B730
void __fastcall ExplosionTrack::~ExplosionTrack(ExplosionTrack *this)
{
  ExplosionTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ExplosionTrack::`vftable;
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

// File Line: 182
// RVA: 0x319120
void __fastcall ExplosionTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::ExplosionTrack", 0i64, 1u);
  if ( v0 )
    ExplosionTrack::ExplosionTrack((ExplosionTrack *)v0);
}

// File Line: 210
// RVA: 0x31E620
void __fastcall PhysicalDamageTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "MemberMap::PhysicalDamageTrack", 0i64, 1u);
  if ( v0 )
    PhysicalDamageTrack::PhysicalDamageTrack((PhysicalDamageTrack *)v0);
}

// File Line: 242
// RVA: 0x2BF630
__int64 __fastcall SensorComponentTrack::GetClassNameUID(SensorComponentTrack *this)
{
  return SensorComponentTrack::sClassNameUID;
}

// File Line: 260
// RVA: 0x2BF0D0
__int64 __fastcall PairedGrappleTrack::GetClassNameUID(PairedGrappleTrack *this)
{
  return PairedGrappleTrack::sClassNameUID;
}

// File Line: 274
// RVA: 0x29AF40
void __fastcall CollisionDisableAgainstTargetTrack::~CollisionDisableAgainstTargetTrack(CollisionDisableAgainstTargetTrack *this)
{
  CollisionDisableAgainstTargetTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CollisionDisableAgainstTargetTrack::`vftable;
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

// File Line: 276
// RVA: 0x3177B0
CollisionDisableAgainstTargetTrack *__fastcall CollisionDisableAgainstTargetTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x40ui64,
         "MemberMap::CollisionDisableAgainstTargetTrack",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, CollisionDisableAgainstTargetTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<CollisionDisableAgainstTargetTask>::`vftable;
  *(_QWORD *)v1 = &CollisionDisableAgainstTargetTrack::`vftable;
  *((_DWORD *)v1 + 14) = 0;
  return (CollisionDisableAgainstTargetTrack *)v1;
}

