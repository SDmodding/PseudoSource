// File Line: 25
// RVA: 0x2BE400
__int64 __fastcall DestructionSetDefinitionTrack::GetClassNameUID(DestructionSetDefinitionTrack *this)
{
  return DestructionSetDefinitionTrack::sClassNameUID;
}

// File Line: 69
// RVA: 0x2BE3C0
__int64 __fastcall DestructionEventTrack::GetClassNameUID(DestructionEventTrack *this)
{
  return DestructionEventTrack::sClassNameUID;
}

// File Line: 172
// RVA: 0x2BE3B0
__int64 __fastcall DestructionEnableRiggedGeoTrack::GetClassNameUID(DestructionEnableRiggedGeoTrack *this)
{
  return DestructionEnableRiggedGeoTrack::sClassNameUID;
}

// File Line: 204
// RVA: 0x3187F0
void __fastcall DestructionSpawnPropertySetTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x78ui64,
         "MemberMap::DestructionSpawnPropertySetTrack",
         0i64,
         1u);
  if ( v0 )
    DestructionSpawnPropertySetTrack::DestructionSpawnPropertySetTrack((DestructionSpawnPropertySetTrack *)v0);
}

// File Line: 278
// RVA: 0x2BE410
__int64 __fastcall DestructionSpawnPhantomVolumeTrack::GetClassNameUID(DestructionSpawnPhantomVolumeTrack *this)
{
  return DestructionSpawnPhantomVolumeTrack::sClassNameUID;
}

// File Line: 334
// RVA: 0x2BE3D0
__int64 __fastcall DestructionExplosionTrack::GetClassNameUID(DestructionExplosionTrack *this)
{
  return DestructionExplosionTrack::sClassNameUID;
}

// File Line: 381
// RVA: 0x2C1040
const char *__fastcall DestructionEnableFractureElementTrack::GetClassname(DestructionEnableFractureElementTrack *this)
{
  return DestructionEnableFractureElementTrack::sClassName;
}

// File Line: 451
// RVA: 0x2C1090
const char *__fastcall DestructionSetDamageTrack::GetClassname(DestructionSetDamageTrack *this)
{
  return DestructionSetDamageTrack::sClassName;
}

// File Line: 484
// RVA: 0x2C1030
const char *__fastcall DestructionDeleteConstraintTrack::GetClassname(DestructionDeleteConstraintTrack *this)
{
  return DestructionDeleteConstraintTrack::sClassName;
}

// File Line: 516
// RVA: 0x318890
void __fastcall DestructionThrusterTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x58ui64, "MemberMap::DestructionThrusterTrack", 0i64, 1u);
  if ( v0 )
    DestructionThrusterTrack::DestructionThrusterTrack((DestructionThrusterTrack *)v0);
}

// File Line: 565
// RVA: 0x2BE3E0
__int64 __fastcall DestructionHingeConstraintTrack::GetClassNameUID(DestructionHingeConstraintTrack *this)
{
  return DestructionHingeConstraintTrack::sClassNameUID;
}

// File Line: 623
// RVA: 0x2BE430
__int64 __fastcall DestructionStiffSpringConstraintTrack::GetClassNameUID(DestructionStiffSpringConstraintTrack *this)
{
  return DestructionStiffSpringConstraintTrack::sClassNameUID;
}

// File Line: 671
// RVA: 0x2C1020
const char *__fastcall DestructionBallAndSocketConstraintTrack::GetClassname(
        DestructionBallAndSocketConstraintTrack *this)
{
  return DestructionBallAndSocketConstraintTrack::sClassName;
}

