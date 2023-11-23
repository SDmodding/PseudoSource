// File Line: 17
// RVA: 0x2C0C90
const char *__fastcall CarModeCondition::GetClassname(CarModeCondition *this)
{
  return CarModeCondition::sClassName;
}

// File Line: 35
// RVA: 0x2BDEE0
__int64 __fastcall CarEscortMode::GetClassNameUID(CarEscortMode *this)
{
  return CarEscortMode::sClassNameUID;
}

// File Line: 54
// RVA: 0x2C0B30
const char *__fastcall CarAtOffset::GetClassname(CarAtOffset *this)
{
  return CarAtOffset::sClassName;
}

// File Line: 81
// RVA: 0x2C0B40
const char *__fastcall CarAttackStat::GetClassname(CarAttackStat *this)
{
  return CarAttackStat::sClassName;
}

// File Line: 101
// RVA: 0x2BDFD0
__int64 __fastcall CarLastAttack::GetClassNameUID(CarLastAttack *this)
{
  return CarLastAttack::sClassNameUID;
}

// File Line: 120
// RVA: 0x2BDF20
__int64 __fastcall CarFormationAttackStat::GetClassNameUID(CarFormationAttackStat *this)
{
  return CarFormationAttackStat::sClassNameUID;
}

// File Line: 141
// RVA: 0x2C0B70
const char *__fastcall CarDistanceToEscortEnemy::GetClassname(CarDistanceToEscortEnemy *this)
{
  return CarDistanceToEscortEnemy::sClassName;
}

// File Line: 162
// RVA: 0x2C0C80
const char *__fastcall CarLastFormationAttack::GetClassname(CarLastFormationAttack *this)
{
  return CarLastFormationAttack::sClassName;
}

// File Line: 181
// RVA: 0x2C0DB0
const char *__fastcall CarWithinRange::GetClassname(CarWithinRange *this)
{
  return CarWithinRange::sClassName;
}

// File Line: 196
// RVA: 0x3166B0
void __fastcall CarFormationAvailable::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::CarFormationAvailable", 0i64, 1u);
  if ( v0 )
    CarFormationAvailable::CarFormationAvailable((CarFormationAvailable *)v0);
}

// File Line: 211
// RVA: 0x2C0BB0
const char *__fastcall CarFormationAssignedPosition::GetClassname(CarFormationAssignedPosition *this)
{
  return CarFormationAssignedPosition::sClassName;
}

// File Line: 228
// RVA: 0x2C0B20
const char *__fastcall CarAtFormation::GetClassname(CarAtFormation *this)
{
  return CarAtFormation::sClassName;
}

// File Line: 245
// RVA: 0x2C0C30
const char *__fastcall CarFormationTimeout::GetClassname(CarFormationTimeout *this)
{
  return CarFormationTimeout::sClassName;
}

// File Line: 262
// RVA: 0x2C0C10
const char *__fastcall CarFormationNumChasers::GetClassname(CarFormationNumChasers *this)
{
  return CarFormationNumChasers::sClassName;
}

// File Line: 283
// RVA: 0x2BDF80
__int64 __fastcall CarFormationNumChasersInRange::GetClassNameUID(CarFormationNumChasersInRange *this)
{
  return CarFormationNumChasersInRange::sClassNameUID;
}

// File Line: 308
// RVA: 0x316750
CarFormationIsCustom *__fastcall CarFormationIsCustom::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::CarFormationIsCustom", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &CarFormationIsCustom::`vftable;
  return (CarFormationIsCustom *)v1;
}

// File Line: 319
// RVA: 0x2C0CC0
const char *__fastcall CarOccupantHasGun::GetClassname(CarOccupantHasGun *this)
{
  return CarOccupantHasGun::sClassName;
}

// File Line: 335
// RVA: 0x316C10
CarOccupantHasTarget *__fastcall CarOccupantHasTarget::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::CarOccupantHasTarget", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &CarOccupantHasTarget::`vftable;
  v1[24] = 4;
  return (CarOccupantHasTarget *)v1;
}

// File Line: 358
// RVA: 0x3136B0
void __fastcall CarOccupantTargetInFrustum::CarOccupantTargetInFrustum(CarOccupantTargetInFrustum *this)
{
  Condition::Condition(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&CarOccupantTargetInFrustum::`vftable;
  this->m_eTargetType.mValue = 4;
  this->m_fNearDistance = 0.0;
  this->m_fFarDistance = 10.0;
  this->m_fAngleStartCW = 4.712389;
  this->m_fAngleEndCW = 1.5707964;
  this->m_sAimingJointName.mOffset = 1i64;
  BinString::Set(&this->m_sAimingJointName, &customCaption);
  *(_WORD *)&this->m_bTestLOS = 0;
}

// File Line: 361
// RVA: 0x2BE060
__int64 __fastcall CarOccupantTargetInFrustum::GetClassNameUID(CarOccupantTargetInFrustum *this)
{
  return CarOccupantTargetInFrustum::sClassNameUID;
}

// File Line: 409
// RVA: 0x2BDFC0
__int64 __fastcall CarIsRacing::GetClassNameUID(CarIsRacing *this)
{
  return CarIsRacing::sClassNameUID;
}

// File Line: 421
// RVA: 0x2C0B60
const char *__fastcall CarCanShoveCargo::GetClassname(CarCanShoveCargo *this)
{
  return CarCanShoveCargo::sClassName;
}

// File Line: 433
// RVA: 0x2C0D40
const char *__fastcall CarRacingLongerThan::GetClassname(CarRacingLongerThan *this)
{
  return CarRacingLongerThan::sClassName;
}

// File Line: 450
// RVA: 0x2BE0B0
__int64 __fastcall CarRoleCondition::GetClassNameUID(CarRoleCondition *this)
{
  return CarRoleCondition::sClassNameUID;
}

// File Line: 469
// RVA: 0x3252C0
void __fastcall VehicleInTrafficJamCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::VehicleInTrafficJamCondition",
         0i64,
         1u);
  if ( v0 )
    VehicleInTrafficJamCondition::VehicleInTrafficJamCondition((VehicleInTrafficJamCondition *)v0);
}

// File Line: 481
// RVA: 0x325360
void __fastcall VehicleIsAvoidingCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::VehicleIsAvoidingCondition", 0i64, 1u);
  if ( v0 )
    VehicleIsAvoidingCondition::VehicleIsAvoidingCondition((VehicleIsAvoidingCondition *)v0);
}

// File Line: 498
// RVA: 0x2C2DD0
const char *__fastcall VehicleIsParkedCondition::GetClassname(VehicleIsParkedCondition *this)
{
  return VehicleIsParkedCondition::sClassName;
}

// File Line: 509
// RVA: 0x2C0140
__int64 __fastcall VehicleIsParkedWithDriverCondition::GetClassNameUID(VehicleIsParkedWithDriverCondition *this)
{
  return VehicleIsParkedWithDriverCondition::sClassNameUID;
}

// File Line: 518
// RVA: 0x2C2E30
const char *__fastcall VehicleNumberOfPassengersCondition::GetClassname(VehicleNumberOfPassengersCondition *this)
{
  return VehicleNumberOfPassengersCondition::sClassName;
}

// File Line: 538
// RVA: 0x323F50
void __fastcall TransitDistanceToGoalLocationCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::TransitDistanceToGoalLocationCondition",
         0i64,
         1u);
  if ( v0 )
    TransitDistanceToGoalLocationCondition::TransitDistanceToGoalLocationCondition((TransitDistanceToGoalLocationCondition *)v0);
}

