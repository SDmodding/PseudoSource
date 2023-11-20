// File Line: 25
// RVA: 0x2C1F60
const char *__fastcall PlayerIsInVehicleCondition::GetClassname(PlayerIsInVehicleCondition *this)
{
  return PlayerIsInVehicleCondition::sClassName;
}

// File Line: 42
// RVA: 0x2BF2D0
__int64 __fastcall PlayerIsInVehicleTypeCondition::GetClassNameUID(PlayerIsInVehicleTypeCondition *this)
{
  return PlayerIsInVehicleTypeCondition::sClassNameUID;
}

// File Line: 70
// RVA: 0x2BF2A0
__int64 __fastcall PlayerIsDriverInVehicleCondition::GetClassNameUID(PlayerIsDriverInVehicleCondition *this)
{
  return PlayerIsDriverInVehicleCondition::sClassNameUID;
}

// File Line: 87
// RVA: 0x31EC00
void __fastcall PlayerIsDriverInVehicleTypeCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::PlayerIsDriverInVehicleTypeCondition",
         0i64,
         1u);
  if ( v0 )
    PlayerIsDriverInVehicleTypeCondition::PlayerIsDriverInVehicleTypeCondition((PlayerIsDriverInVehicleTypeCondition *)v0);
}

// File Line: 113
// RVA: 0x2C1F80
const char *__fastcall PlayerIsPassengerInVehicleCondition::GetClassname(PlayerIsPassengerInVehicleCondition *this)
{
  return PlayerIsPassengerInVehicleCondition::sClassName;
}

// File Line: 130
// RVA: 0x2C1F90
const char *__fastcall PlayerIsPassengerInVehicleTypeCondition::GetClassname(PlayerIsPassengerInVehicleTypeCondition *this)
{
  return PlayerIsPassengerInVehicleTypeCondition::sClassName;
}

// File Line: 159
// RVA: 0x2C1F30
const char *__fastcall PlayerIsCloseToVehicleTypeCondition::GetClassname(PlayerIsCloseToVehicleTypeCondition *this)
{
  return PlayerIsCloseToVehicleTypeCondition::sClassName;
}

// File Line: 187
// RVA: 0x31EAC0
void __fastcall PlayerIsCloseToDriverSideOfVehicleTypeCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::PlayerIsCloseToDriverSideOfVehicleTypeCondition",
         0i64,
         1u);
  if ( v0 )
    PlayerIsCloseToDriverSideOfVehicleTypeCondition::PlayerIsCloseToDriverSideOfVehicleTypeCondition((PlayerIsCloseToDriverSideOfVehicleTypeCondition *)v0);
}

// File Line: 215
// RVA: 0x2BF280
__int64 __fastcall PlayerIsCloseToPassengerSideOfVehicleTypeCondition::GetClassNameUID(PlayerIsCloseToPassengerSideOfVehicleTypeCondition *this)
{
  return PlayerIsCloseToPassengerSideOfVehicleTypeCondition::sClassNameUID;
}

// File Line: 243
// RVA: 0x2BF260
__int64 __fastcall PlayerHasOwnedWeaponTypeCondition::GetClassNameUID(PlayerHasOwnedWeaponTypeCondition *this)
{
  return PlayerHasOwnedWeaponTypeCondition::sClassNameUID;
}

// File Line: 267
// RVA: 0x31E800
void __fastcall PlayerCloseToWeaponTypeCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::PlayerCloseToWeaponTypeCondition",
         0i64,
         1u);
  if ( v0 )
    PlayerCloseToWeaponTypeCondition::PlayerCloseToWeaponTypeCondition((PlayerCloseToWeaponTypeCondition *)v0);
}

// File Line: 292
// RVA: 0x2C03D0
__int64 __fastcall WeaponIsOwnedCondition::GetClassNameUID(WeaponIsOwnedCondition *this)
{
  return WeaponIsOwnedCondition::sClassNameUID;
}

// File Line: 317
// RVA: 0x326520
void __fastcall WeaponIsTargetedForInteractionCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::WeaponIsTargetedForInteractionCondition",
         0i64,
         1u);
  if ( v0 )
    WeaponIsTargetedForInteractionCondition::WeaponIsTargetedForInteractionCondition((WeaponIsTargetedForInteractionCondition *)v0);
}

// File Line: 342
// RVA: 0x2C2D40
const char *__fastcall VehicleHasDriverCondition::GetClassname(VehicleHasDriverCondition *this)
{
  return VehicleHasDriverCondition::sClassName;
}

// File Line: 370
// RVA: 0x2C00C0
__int64 __fastcall VehicleHasDriverWithWeaponCondition::GetClassNameUID(VehicleHasDriverWithWeaponCondition *this)
{
  return VehicleHasDriverWithWeaponCondition::sClassNameUID;
}

// File Line: 404
// RVA: 0x2C2D70
const char *__fastcall VehicleHasPassengerCondition::GetClassname(VehicleHasPassengerCondition *this)
{
  return VehicleHasPassengerCondition::sClassName;
}

// File Line: 431
// RVA: 0x2C00E0
__int64 __fastcall VehicleHasPassengerWithWeaponCondition::GetClassNameUID(VehicleHasPassengerWithWeaponCondition *this)
{
  return VehicleHasPassengerWithWeaponCondition::sClassNameUID;
}

// File Line: 465
// RVA: 0x2C02D0
__int64 __fastcall VehicleTargetedForInteractionOnFootDriverSideCondition::GetClassNameUID(VehicleTargetedForInteractionOnFootDriverSideCondition *this)
{
  return VehicleTargetedForInteractionOnFootDriverSideCondition::sClassNameUID;
}

// File Line: 493
// RVA: 0x325E80
void __fastcall VehicleTargetedForInteractionOnFootPassengerSideCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::VehicleTargetedForInteractionOnFootPassengerSideCondition",
         0i64,
         1u);
  if ( v0 )
    VehicleTargetedForInteractionOnFootPassengerSideCondition::VehicleTargetedForInteractionOnFootPassengerSideCondition((VehicleTargetedForInteractionOnFootPassengerSideCondition *)v0);
}

// File Line: 561
// RVA: 0x325ED0
void __fastcall VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition",
         0i64,
         1u);
  if ( v0 )
    VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition::VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition((VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition *)v0);
}

// File Line: 595
// RVA: 0x325F20
void __fastcall VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition",
         0i64,
         1u);
  if ( v0 )
    VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition::VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition((VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition *)v0);
}

// File Line: 629
// RVA: 0x2BE190
__int64 __fastcall CharacterTypeHasWeaponTypeCondition::GetClassNameUID(CharacterTypeHasWeaponTypeCondition *this)
{
  return CharacterTypeHasWeaponTypeCondition::sClassNameUID;
}

// File Line: 659
// RVA: 0x31F0E0
void __fastcall PredictiveVehicleDriverPotentialInteractionCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::PredictiveVehicleDriverPotentialInteractionCondition",
         0i64,
         1u);
  if ( v0 )
    PredictiveVehicleDriverPotentialInteractionCondition::PredictiveVehicleDriverPotentialInteractionCondition((PredictiveVehicleDriverPotentialInteractionCondition *)v0);
}

// File Line: 687
// RVA: 0x2BF370
__int64 __fastcall PredictiveVehiclePassengerPotentialInteractionCondition::GetClassNameUID(PredictiveVehiclePassengerPotentialInteractionCondition *this)
{
  return PredictiveVehiclePassengerPotentialInteractionCondition::sClassNameUID;
}

// File Line: 715
// RVA: 0x2C2020
const char *__fastcall PredictiveVehiclePlayerPotentialInteractionCondition::GetClassname(PredictiveVehiclePlayerPotentialInteractionCondition *this)
{
  return PredictiveVehiclePlayerPotentialInteractionCondition::sClassName;
}

// File Line: 743
// RVA: 0x2C2030
const char *__fastcall PredictiveWeaponPotentialInteractionCondition::GetClassname(PredictiveWeaponPotentialInteractionCondition *this)
{
  return PredictiveWeaponPotentialInteractionCondition::sClassName;
}

