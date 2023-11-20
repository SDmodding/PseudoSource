// File Line: 31
// RVA: 0x149C4A0
__int64 dynamic_initializer_for__gDamageTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &gDamageTypeEnum,
    gDamageTypeStrings,
    gDamageTypeStringsCount,
    0i64);
  return atexit(dynamic_atexit_destructor_for__gDamageTypeEnum__);
}

// File Line: 50
// RVA: 0x14954B0
__int64 dynamic_initializer_for__GravityTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("GravityTrack", 0xFFFFFFFF);
  GravityTrack::sClassNameUID = result;
  return result;
}

// File Line: 60
// RVA: 0x2DF650
void __fastcall GravityTrack::GravityTrack(GravityTrack *this)
{
  GravityTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, GravityTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<GravityTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&GravityTrack::`vftable;
  v1->mGravity = -9.8100004;
  v1->mBallisticMode = 0;
}

// File Line: 74
// RVA: 0x1495330
__int64 dynamic_initializer_for__DisableCollisionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DisableCollisionTrack", 0xFFFFFFFF);
  DisableCollisionTrack::sClassNameUID = result;
  return result;
}

// File Line: 81
// RVA: 0x2DF2E0
void __fastcall DisableCollisionTrack::DisableCollisionTrack(DisableCollisionTrack *this)
{
  DisableCollisionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DisableCollisionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DisableCollisionTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&DisableCollisionTrack::`vftable;
}

// File Line: 95
// RVA: 0x149EDB0
__int64 dynamic_initializer_for__simulatedModeTrackEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&simulatedModeTrackEnum, gSimulatedModeStringList, 2, 0i64);
  return atexit(dynamic_atexit_destructor_for__simulatedModeTrackEnum__);
}

// File Line: 97
// RVA: 0x1495AB0
__int64 dynamic_initializer_for__PhysicsMotionTypeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PhysicsMotionTypeTrack", 0xFFFFFFFF);
  PhysicsMotionTypeTrack::sClassNameUID = result;
  return result;
}

// File Line: 108
// RVA: 0x2E02B0
void __fastcall PhysicsMotionTypeTrack::PhysicsMotionTypeTrack(PhysicsMotionTypeTrack *this)
{
  PhysicsMotionTypeTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, PhysicsMotionTypeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<PhysicsMotionTypeTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&PhysicsMotionTypeTrack::`vftable;
  v1->mMode.mValue = 0;
  v1->mCollisionGeoName.mUID = -1;
}

// File Line: 112
// RVA: 0x2E42C0
void __fastcall PhysicsMotionTypeTrack::~PhysicsMotionTypeTrack(PhysicsMotionTypeTrack *this)
{
  PhysicsMotionTypeTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PhysicsMotionTypeTrack::`vftable;
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

// File Line: 128
// RVA: 0x149BC60
__int64 dynamic_initializer_for__characterPhysicsTrackEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(
    &characterPhysicsTrackEnum,
    gCharacterPhysicsModeStringList,
    14,
    0i64);
  return atexit(dynamic_atexit_destructor_for__characterPhysicsTrackEnum__);
}

// File Line: 130
// RVA: 0x1494F10
__int64 dynamic_initializer_for__CharacterPhysicsTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CharacterPhysicsTrack", 0xFFFFFFFF);
  CharacterPhysicsTrack::sClassNameUID = result;
  return result;
}

// File Line: 139
// RVA: 0x2DE580
void __fastcall CharacterPhysicsTrack::CharacterPhysicsTrack(CharacterPhysicsTrack *this)
{
  CharacterPhysicsTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CharacterPhysicsTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CharacterPhysicsTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CharacterPhysicsTrack::`vftable;
  v1->mMode.mValue = 1;
  v1->mMaster = 0;
}

// File Line: 144
// RVA: 0x2E3820
void __fastcall CharacterPhysicsTrack::~CharacterPhysicsTrack(CharacterPhysicsTrack *this)
{
  CharacterPhysicsTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CharacterPhysicsTrack::`vftable;
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

// File Line: 157
// RVA: 0x1494EF0
__int64 dynamic_initializer_for__CharacterPhysicsSuperMassiveTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CharacterPhysicsSuperMassiveTrack", 0xFFFFFFFF);
  CharacterPhysicsSuperMassiveTrack::sClassNameUID = result;
  return result;
}

// File Line: 164
// RVA: 0x2DE530
void __fastcall CharacterPhysicsSuperMassiveTrack::CharacterPhysicsSuperMassiveTrack(CharacterPhysicsSuperMassiveTrack *this)
{
  CharacterPhysicsSuperMassiveTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, CharacterPhysicsSuperMassiveTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<CharacterPhysicsSuperMassiveTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&CharacterPhysicsSuperMassiveTrack::`vftable;
  v1->mMaster = 0;
}

// File Line: 169
// RVA: 0x2E37B0
void __fastcall CharacterPhysicsSuperMassiveTrack::~CharacterPhysicsSuperMassiveTrack(CharacterPhysicsSuperMassiveTrack *this)
{
  CharacterPhysicsSuperMassiveTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&CharacterPhysicsSuperMassiveTrack::`vftable;
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

// File Line: 180
// RVA: 0x14952B0
__int64 dynamic_initializer_for__DetailedOnGroundTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("DetailedOnGroundTrack", 0xFFFFFFFF);
  DetailedOnGroundTrack::sClassNameUID = result;
  return result;
}

// File Line: 187
// RVA: 0x2DEFE0
void __fastcall DetailedOnGroundTrack::DetailedOnGroundTrack(DetailedOnGroundTrack *this)
{
  DetailedOnGroundTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, DetailedOnGroundTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<DetailedOnGroundTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&DetailedOnGroundTrack::`vftable;
}

// File Line: 199
// RVA: 0x1496B30
__int64 dynamic_initializer_for__VelocitySlopeModeTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VelocitySlopeModeTrack", 0xFFFFFFFF);
  VelocitySlopeModeTrack::sClassNameUID = result;
  return result;
}

// File Line: 207
// RVA: 0x2E2B70
void __fastcall VelocitySlopeModeTrack::VelocitySlopeModeTrack(VelocitySlopeModeTrack *this)
{
  VelocitySlopeModeTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, VelocitySlopeModeTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<VelocitySlopeModeTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&VelocitySlopeModeTrack::`vftable;
  v1->mVelocityMode = 0;
}

// File Line: 219
// RVA: 0x1495FD0
__int64 dynamic_initializer_for__SlopeLocomotionFixupTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SlopeLocomotionFixupTrack", 0xFFFFFFFF);
  SlopeLocomotionFixupTrack::sClassNameUID = result;
  return result;
}

// File Line: 237
// RVA: 0x149C5A0
__int64 dynamic_initializer_for__gExplosionTypeEnum__()
{
  TracksEnum<unsigned long>::TracksEnum<unsigned long>(&gExplosionTypeEnum, "Global/Act/ExplosionTypes.xml");
  return atexit(dynamic_atexit_destructor_for__gExplosionTypeEnum__);
}

// File Line: 238
// RVA: 0x14953F0
__int64 dynamic_initializer_for__ExplosionTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("ExplosionTrack", 0xFFFFFFFF);
  ExplosionTrack::sClassNameUID = result;
  return result;
}

// File Line: 248
// RVA: 0x2DF430
void __fastcall ExplosionTrack::ExplosionTrack(ExplosionTrack *this)
{
  ExplosionTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, ExplosionTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<ExplosionTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&ExplosionTrack::`vftable;
  *(_QWORD *)&v1->m_AttachTo.mUID = UFG::gNullQSymbolUC.mUID;
}

// File Line: 265
// RVA: 0x2E0250
void __fastcall PhysicalDamageTrack::PhysicalDamageTrack(PhysicalDamageTrack *this)
{
  PhysicalDamageTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, PhysicalDamageTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<PhysicalDamageTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&PhysicalDamageTrack::`vftable;
  v1->mDamageType = 0;
  v1->mDamage = 1.0;
  v1->mRigidBodyModelName.mUID = -1;
  UFG::qSymbolUC::set_null(&v1->mRigidBodyModelName);
}

// File Line: 269
// RVA: 0x1495A90
__int64 dynamic_initializer_for__PhysicalDamageTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PhysicalDamageTrack", 0xFFFFFFFF);
  PhysicalDamageTrack::sClassNameUID = result;
  return result;
}

// File Line: 288
// RVA: 0x1495E30
__int64 dynamic_initializer_for__SensorComponentTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SensorComponentTrack", 0xFFFFFFFF);
  SensorComponentTrack::sClassNameUID = result;
  return result;
}

// File Line: 296
// RVA: 0x2E0DA0
void __fastcall SensorComponentTrack::SensorComponentTrack(SensorComponentTrack *this)
{
  SensorComponentTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, SensorComponentTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<SensorComponentTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&SensorComponentTrack::`vftable;
  v1->mMaster = 0;
}

// File Line: 301
// RVA: 0x2E4E40
void __fastcall SensorComponentTrack::~SensorComponentTrack(SensorComponentTrack *this)
{
  SensorComponentTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&SensorComponentTrack::`vftable;
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

// File Line: 314
// RVA: 0x14959F0
__int64 dynamic_initializer_for__PairedGrappleTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PairedGrappleTrack", 0xFFFFFFFF);
  PairedGrappleTrack::sClassNameUID = result;
  return result;
}

// File Line: 324
// RVA: 0x2E0060
void __fastcall PairedGrappleTrack::PairedGrappleTrack(PairedGrappleTrack *this)
{
  PairedGrappleTrack *v1; // rbx

  v1 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, PairedGrappleTrack::sClassNameUID);
  v1->vfptr = (Expression::IMemberMapVtbl *)&Track<PairedGrappleTask>::`vftable;
  v1->vfptr = (Expression::IMemberMapVtbl *)&PairedGrappleTrack::`vftable;
  v1->mUseSmallGrapple = 0;
  v1->mMaster = 0;
}

// File Line: 329
// RVA: 0x2E4250
void __fastcall PairedGrappleTrack::~PairedGrappleTrack(PairedGrappleTrack *this)
{
  PairedGrappleTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&PairedGrappleTrack::`vftable;
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

// File Line: 341
// RVA: 0x1494FB0
__int64 dynamic_initializer_for__CollisionDisableAgainstTargetTrack::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CollisionDisableAgainstTargetTrack", 0xFFFFFFFF);
  CollisionDisableAgainstTargetTrack::sClassNameUID = result;
  return result;
}

