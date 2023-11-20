// File Line: 29
// RVA: 0x14D1780
__int64 dynamic_initializer_for__PlayerIsInVehicleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerIsInVehicleCondition", 0xFFFFFFFF);
  PlayerIsInVehicleCondition::sClassNameUID = result;
  return result;
}

// File Line: 32
// RVA: 0x3E89D0
void __fastcall PlayerIsInVehicleCondition::PlayerIsInVehicleCondition(PlayerIsInVehicleCondition *this)
{
  PlayerIsInVehicleCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsInVehicleCondition::`vftable';
}

// File Line: 36
// RVA: 0x3E95C0
bool __fastcall PlayerIsInVehicleCondition::Match(PlayerIsInVehicleCondition *this, ActionContext *pContext)
{
  return UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsDriver
      || UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsPassenger;
}

// File Line: 57
// RVA: 0x14D17A0
__int64 dynamic_initializer_for__PlayerIsInVehicleTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerIsInVehicleTypeCondition", 0xFFFFFFFF);
  PlayerIsInVehicleTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 65
// RVA: 0x3E8A00
void __fastcall PlayerIsInVehicleTypeCondition::PlayerIsInVehicleTypeCondition(PlayerIsInVehicleTypeCondition *this)
{
  PlayerIsInVehicleTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsInVehicleTypeCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
}

// File Line: 69
// RVA: 0x3E95E0
bool __fastcall PlayerIsInVehicleTypeCondition::Match(PlayerIsInVehicleTypeCondition *this, ActionContext *pContext)
{
  signed __int64 v2; // rax
  signed __int64 v3; // rdx
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v4; // rcx

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  if ( (_DWORD)v2 == 3 )
  {
    v3 = (unsigned __int8)this->m_eSimObjectBoatType.mValue;
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerBoatInfo;
  }
  else
  {
    v3 = v2;
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerVehicleInfo;
  }
  return v4[v3].m_bIsDriver || v4[v3].m_bIsPassenger;
}

// File Line: 96
// RVA: 0x14D1740
__int64 dynamic_initializer_for__PlayerIsDriverInVehicleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerIsDriverInVehicleCondition", 0xFFFFFFFF);
  PlayerIsDriverInVehicleCondition::sClassNameUID = result;
  return result;
}

// File Line: 99
// RVA: 0x3E8960
void __fastcall PlayerIsDriverInVehicleCondition::PlayerIsDriverInVehicleCondition(PlayerIsDriverInVehicleCondition *this)
{
  PlayerIsDriverInVehicleCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsDriverInVehicleCondition::`vftable';
}

// File Line: 103
// RVA: 0x3E9570
_BOOL8 __fastcall PlayerIsDriverInVehicleCondition::Match(PlayerIsDriverInVehicleCondition *this, ActionContext *pContext)
{
  return UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsDriver;
}

// File Line: 124
// RVA: 0x14D1760
__int64 dynamic_initializer_for__PlayerIsDriverInVehicleTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerIsDriverInVehicleTypeCondition", 0xFFFFFFFF);
  PlayerIsDriverInVehicleTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 132
// RVA: 0x3E8990
void __fastcall PlayerIsDriverInVehicleTypeCondition::PlayerIsDriverInVehicleTypeCondition(PlayerIsDriverInVehicleTypeCondition *this)
{
  PlayerIsDriverInVehicleTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsDriverInVehicleTypeCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
}

// File Line: 136
// RVA: 0x3E9580
_BOOL8 __fastcall PlayerIsDriverInVehicleTypeCondition::Match(PlayerIsDriverInVehicleTypeCondition *this, ActionContext *pContext)
{
  __int64 v2; // rax
  _BOOL8 result; // rax

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  if ( (_DWORD)v2 == 3 )
    result = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerBoatInfo[(unsigned __int8)this->m_eSimObjectBoatType.mValue].m_bIsDriver;
  else
    result = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerVehicleInfo[v2].m_bIsDriver;
  return result;
}

// File Line: 163
// RVA: 0x14D17C0
__int64 dynamic_initializer_for__PlayerIsPassengerInVehicleCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerIsPassengerInVehicleCondition", 0xFFFFFFFF);
  PlayerIsPassengerInVehicleCondition::sClassNameUID = result;
  return result;
}

// File Line: 166
// RVA: 0x3E8A40
void __fastcall PlayerIsPassengerInVehicleCondition::PlayerIsPassengerInVehicleCondition(PlayerIsPassengerInVehicleCondition *this)
{
  PlayerIsPassengerInVehicleCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsPassengerInVehicleCondition::`vftable';
}

// File Line: 170
// RVA: 0x3E9630
_BOOL8 __fastcall PlayerIsPassengerInVehicleCondition::Match(PlayerIsPassengerInVehicleCondition *this, ActionContext *pContext)
{
  return UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsPassenger;
}

// File Line: 191
// RVA: 0x14D17E0
__int64 dynamic_initializer_for__PlayerIsPassengerInVehicleTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerIsPassengerInVehicleTypeCondition", 0xFFFFFFFF);
  PlayerIsPassengerInVehicleTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 199
// RVA: 0x3E8A70
void __fastcall PlayerIsPassengerInVehicleTypeCondition::PlayerIsPassengerInVehicleTypeCondition(PlayerIsPassengerInVehicleTypeCondition *this)
{
  PlayerIsPassengerInVehicleTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsPassengerInVehicleTypeCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
}

// File Line: 203
// RVA: 0x3E9640
_BOOL8 __fastcall PlayerIsPassengerInVehicleTypeCondition::Match(PlayerIsPassengerInVehicleTypeCondition *this, ActionContext *pContext)
{
  __int64 v2; // rax
  _BOOL8 result; // rax

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  if ( (_DWORD)v2 == 3 )
    result = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerBoatInfo[(unsigned __int8)this->m_eSimObjectBoatType.mValue].m_bIsPassenger;
  else
    result = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerVehicleInfo[v2].m_bIsPassenger;
  return result;
}

// File Line: 230
// RVA: 0x14D1720
__int64 dynamic_initializer_for__PlayerIsCloseToVehicleTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerIsCloseToVehicleTypeCondition", 0xFFFFFFFF);
  PlayerIsCloseToVehicleTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 238
// RVA: 0x3E8920
void __fastcall PlayerIsCloseToVehicleTypeCondition::PlayerIsCloseToVehicleTypeCondition(PlayerIsCloseToVehicleTypeCondition *this)
{
  PlayerIsCloseToVehicleTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsCloseToVehicleTypeCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
}

// File Line: 242
// RVA: 0x3E9520
bool __fastcall PlayerIsCloseToVehicleTypeCondition::Match(PlayerIsCloseToVehicleTypeCondition *this, ActionContext *pContext)
{
  signed __int64 v2; // rax
  signed __int64 v3; // rdx
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v4; // rcx
  float v5; // xmm1_4

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  if ( (_DWORD)v2 == 3 )
  {
    v3 = (unsigned __int8)this->m_eSimObjectBoatType.mValue;
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerBoatInfo;
  }
  else
  {
    v3 = v2;
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerVehicleInfo;
  }
  v5 = v4[v3].m_fDistanceToDriverSide;
  if ( v5 >= v4[v3].m_fDistanceToPassengerSide )
    v5 = v4[v3].m_fDistanceToPassengerSide;
  return s_fCloseToVehicleDistanceSquared >= v5;
}

// File Line: 270
// RVA: 0x14D16E0
__int64 dynamic_initializer_for__PlayerIsCloseToDriverSideOfVehicleTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerIsCloseToDriverSideOfVehicleTypeCondition", 0xFFFFFFFF);
  PlayerIsCloseToDriverSideOfVehicleTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 278
// RVA: 0x3E88A0
void __fastcall PlayerIsCloseToDriverSideOfVehicleTypeCondition::PlayerIsCloseToDriverSideOfVehicleTypeCondition(PlayerIsCloseToDriverSideOfVehicleTypeCondition *this)
{
  PlayerIsCloseToDriverSideOfVehicleTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsCloseToDriverSideOfVehicleTypeCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
}

// File Line: 282
// RVA: 0x3E9480
bool __fastcall PlayerIsCloseToDriverSideOfVehicleTypeCondition::Match(PlayerIsCloseToDriverSideOfVehicleTypeCondition *this, ActionContext *pContext)
{
  signed __int64 v2; // rax
  signed __int64 v3; // rdx
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v4; // rcx

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  if ( (_DWORD)v2 == 3 )
  {
    v3 = (unsigned __int8)this->m_eSimObjectBoatType.mValue;
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerBoatInfo;
  }
  else
  {
    v3 = v2;
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerVehicleInfo;
  }
  return s_fCloseToVehicleDistanceSquared >= v4[v3].m_fDistanceToDriverSide;
}

// File Line: 310
// RVA: 0x14D1700
__int64 dynamic_initializer_for__PlayerIsCloseToPassengerSideOfVehicleTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerIsCloseToPassengerSideOfVehicleTypeCondition", 0xFFFFFFFF);
  PlayerIsCloseToPassengerSideOfVehicleTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 318
// RVA: 0x3E88E0
void __fastcall PlayerIsCloseToPassengerSideOfVehicleTypeCondition::PlayerIsCloseToPassengerSideOfVehicleTypeCondition(PlayerIsCloseToPassengerSideOfVehicleTypeCondition *this)
{
  PlayerIsCloseToPassengerSideOfVehicleTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerIsCloseToPassengerSideOfVehicleTypeCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
}

// File Line: 322
// RVA: 0x3E94D0
bool __fastcall PlayerIsCloseToPassengerSideOfVehicleTypeCondition::Match(PlayerIsCloseToPassengerSideOfVehicleTypeCondition *this, ActionContext *pContext)
{
  signed __int64 v2; // rax
  signed __int64 v3; // rdx
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v4; // rcx

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  if ( (_DWORD)v2 == 3 )
  {
    v3 = (unsigned __int8)this->m_eSimObjectBoatType.mValue;
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerBoatInfo;
  }
  else
  {
    v3 = v2;
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerVehicleInfo;
  }
  return s_fCloseToVehicleDistanceSquared >= v4[v3].m_fDistanceToPassengerSide;
}

// File Line: 350
// RVA: 0x14D16C0
__int64 dynamic_initializer_for__PlayerHasOwnedWeaponTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerHasOwnedWeaponTypeCondition", 0xFFFFFFFF);
  PlayerHasOwnedWeaponTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 356
// RVA: 0x3E8860
void __fastcall PlayerHasOwnedWeaponTypeCondition::PlayerHasOwnedWeaponTypeCondition(PlayerHasOwnedWeaponTypeCondition *this)
{
  PlayerHasOwnedWeaponTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerHasOwnedWeaponTypeCondition::`vftable';
  v1->m_eSimObjectWeaponType = 0;
}

// File Line: 360
// RVA: 0x3E9460
_BOOL8 __fastcall PlayerHasOwnedWeaponTypeCondition::Match(PlayerHasOwnedWeaponTypeCondition *this, ActionContext *pContext)
{
  return UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerWeaponInfo[this->m_eSimObjectWeaponType].m_bOwned;
}

// File Line: 382
// RVA: 0x14D16A0
__int64 dynamic_initializer_for__PlayerCloseToWeaponTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PlayerCloseToWeaponTypeCondition", 0xFFFFFFFF);
  PlayerCloseToWeaponTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 388
// RVA: 0x3E8820
void __fastcall PlayerCloseToWeaponTypeCondition::PlayerCloseToWeaponTypeCondition(PlayerCloseToWeaponTypeCondition *this)
{
  PlayerCloseToWeaponTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&PlayerCloseToWeaponTypeCondition::`vftable';
  v1->m_eSimObjectWeaponType = 0;
}

// File Line: 392
// RVA: 0x3E9440
bool __fastcall PlayerCloseToWeaponTypeCondition::Match(PlayerCloseToWeaponTypeCondition *this, ActionContext *pContext)
{
  return s_fCloseToWeaponDistanceSquared >= UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerWeaponInfo[this->m_eSimObjectWeaponType].m_fDistanceSquared;
}

// File Line: 415
// RVA: 0x14D19A0
__int64 dynamic_initializer_for__WeaponIsOwnedCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("WeaponIsOwnedCondition", 0xFFFFFFFF);
  WeaponIsOwnedCondition::sClassNameUID = result;
  return result;
}

// File Line: 421
// RVA: 0x3E8F40
void __fastcall WeaponIsOwnedCondition::WeaponIsOwnedCondition(WeaponIsOwnedCondition *this)
{
  WeaponIsOwnedCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&WeaponIsOwnedCondition::`vftable';
  v1->m_eSimObjectWeaponType = 0;
}

// File Line: 425
// RVA: 0x3E9D30
_BOOL8 __fastcall WeaponIsOwnedCondition::Match(WeaponIsOwnedCondition *this, ActionContext *pContext)
{
  return UFG::PredictiveStreamingStats::ms_pInstance->m_WeaponInfo[this->m_eSimObjectWeaponType].m_bOwned;
}

// File Line: 447
// RVA: 0x14D19C0
__int64 dynamic_initializer_for__WeaponIsTargetedForInteractionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("WeaponIsTargetedForInteractionCondition", 0xFFFFFFFF);
  WeaponIsTargetedForInteractionCondition::sClassNameUID = result;
  return result;
}

// File Line: 453
// RVA: 0x3E8F80
void __fastcall WeaponIsTargetedForInteractionCondition::WeaponIsTargetedForInteractionCondition(WeaponIsTargetedForInteractionCondition *this)
{
  WeaponIsTargetedForInteractionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&WeaponIsTargetedForInteractionCondition::`vftable';
  v1->m_eSimObjectWeaponType = 0;
}

// File Line: 457
// RVA: 0x3E9D50
_BOOL8 __fastcall WeaponIsTargetedForInteractionCondition::Match(WeaponIsTargetedForInteractionCondition *this, ActionContext *pContext)
{
  return UFG::PredictiveStreamingStats::ms_pInstance->m_WeaponInfo[this->m_eSimObjectWeaponType].m_bTargetedForInteractionOnFoot;
}

// File Line: 479
// RVA: 0x14D18A0
__int64 dynamic_initializer_for__VehicleHasDriverCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleHasDriverCondition", 0xFFFFFFFF);
  VehicleHasDriverCondition::sClassNameUID = result;
  return result;
}

// File Line: 487
// RVA: 0x3E8D00
void __fastcall VehicleHasDriverCondition::VehicleHasDriverCondition(VehicleHasDriverCondition *this)
{
  VehicleHasDriverCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleHasDriverCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
}

// File Line: 491
// RVA: 0x3E99D0
__int64 __fastcall VehicleHasDriverCondition::Match(VehicleHasDriverCondition *this, ActionContext *pContext)
{
  unsigned __int8 v2; // al
  __int64 result; // rax

  v2 = this->m_eSimObjectVehicleType.mValue;
  if ( v2 == 3 )
    result = *((unsigned __int8 *)&UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsDriver
             + 40 * ((unsigned __int8)this->m_eSimObjectBoatType.mValue + 11i64));
  else
    result = *((unsigned __int8 *)&UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsDriver
             + 40 * (v2 + 1i64));
  return result;
}

// File Line: 517
// RVA: 0x14D18C0
__int64 dynamic_initializer_for__VehicleHasDriverWithWeaponCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleHasDriverWithWeaponCondition", 0xFFFFFFFF);
  VehicleHasDriverWithWeaponCondition::sClassNameUID = result;
  return result;
}

// File Line: 527
// RVA: 0x3E8D40
void __fastcall VehicleHasDriverWithWeaponCondition::VehicleHasDriverWithWeaponCondition(VehicleHasDriverWithWeaponCondition *this)
{
  VehicleHasDriverWithWeaponCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleHasDriverWithWeaponCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
  v1->m_eSimObjectWeaponType = 0;
}

// File Line: 531
// RVA: 0x3E9A10
_BOOL8 __fastcall VehicleHasDriverWithWeaponCondition::Match(VehicleHasDriverWithWeaponCondition *this, ActionContext *pContext)
{
  __int64 v2; // rax
  __int64 v3; // rdx
  bool *v4; // rcx

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  v3 = this->m_eSimObjectWeaponType;
  if ( (_DWORD)v2 == 3 )
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_BoatInfo[(unsigned __int8)this->m_eSimObjectBoatType.mValue].m_bHasDriverByWeaponType;
  else
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_VehicleInfo[v2].m_bHasDriverByWeaponType;
  return v4[v3];
}

// File Line: 562
// RVA: 0x14D18E0
__int64 dynamic_initializer_for__VehicleHasPassengerCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleHasPassengerCondition", 0xFFFFFFFF);
  VehicleHasPassengerCondition::sClassNameUID = result;
  return result;
}

// File Line: 570
// RVA: 0x3E8D80
void __fastcall VehicleHasPassengerCondition::VehicleHasPassengerCondition(VehicleHasPassengerCondition *this)
{
  VehicleHasPassengerCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleHasPassengerCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
}

// File Line: 574
// RVA: 0x3E9A50
_BOOL8 __fastcall VehicleHasPassengerCondition::Match(VehicleHasPassengerCondition *this, ActionContext *pContext)
{
  __int64 v2; // rax
  _BOOL8 result; // rax

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  if ( (_DWORD)v2 == 3 )
    result = UFG::PredictiveStreamingStats::ms_pInstance->m_BoatInfo[(unsigned __int8)this->m_eSimObjectBoatType.mValue].m_bHasPassenger;
  else
    result = UFG::PredictiveStreamingStats::ms_pInstance->m_VehicleInfo[v2].m_bHasPassenger;
  return result;
}

// File Line: 601
// RVA: 0x14D1900
__int64 dynamic_initializer_for__VehicleHasPassengerWithWeaponCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleHasPassengerWithWeaponCondition", 0xFFFFFFFF);
  VehicleHasPassengerWithWeaponCondition::sClassNameUID = result;
  return result;
}

// File Line: 611
// RVA: 0x3E8DC0
void __fastcall VehicleHasPassengerWithWeaponCondition::VehicleHasPassengerWithWeaponCondition(VehicleHasPassengerWithWeaponCondition *this)
{
  VehicleHasPassengerWithWeaponCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleHasPassengerWithWeaponCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
  v1->m_eSimObjectWeaponType = 0;
}

// File Line: 615
// RVA: 0x3E9A90
_BOOL8 __fastcall VehicleHasPassengerWithWeaponCondition::Match(VehicleHasPassengerWithWeaponCondition *this, ActionContext *pContext)
{
  __int64 v2; // rax
  __int64 v3; // rdx
  bool *v4; // rcx

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  v3 = this->m_eSimObjectWeaponType;
  if ( (_DWORD)v2 == 3 )
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_BoatInfo[(unsigned __int8)this->m_eSimObjectBoatType.mValue].m_bHasPassengerByWeaponType;
  else
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_VehicleInfo[v2].m_bHasPassengerByWeaponType;
  return v4[v3];
}

// File Line: 644
// RVA: 0x14D1920
__int64 dynamic_initializer_for__VehicleTargetedForInteractionOnFootDriverSideCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleTargetedForInteractionOnFootDriverSideCondition", 0xFFFFFFFF);
  VehicleTargetedForInteractionOnFootDriverSideCondition::sClassNameUID = result;
  return result;
}

// File Line: 652
// RVA: 0x3E8E00
void __fastcall VehicleTargetedForInteractionOnFootDriverSideCondition::VehicleTargetedForInteractionOnFootDriverSideCondition(VehicleTargetedForInteractionOnFootDriverSideCondition *this)
{
  VehicleTargetedForInteractionOnFootDriverSideCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleTargetedForInteractionOnFootDriverSideCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
}

// File Line: 656
// RVA: 0x3E9AD0
_BOOL8 __fastcall VehicleTargetedForInteractionOnFootDriverSideCondition::Match(VehicleTargetedForInteractionOnFootDriverSideCondition *this, ActionContext *pContext)
{
  __int64 v2; // rax
  _BOOL8 result; // rax

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  if ( (_DWORD)v2 == 3 )
    result = UFG::PredictiveStreamingStats::ms_pInstance->m_BoatInfo[(unsigned __int8)this->m_eSimObjectBoatType.mValue].m_bTargetedForInteractionOnFootDriverSide;
  else
    result = UFG::PredictiveStreamingStats::ms_pInstance->m_VehicleInfo[v2].m_bTargetedForInteractionOnFootDriverSide;
  return result;
}

// File Line: 683
// RVA: 0x14D1940
__int64 dynamic_initializer_for__VehicleTargetedForInteractionOnFootPassengerSideCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleTargetedForInteractionOnFootPassengerSideCondition", 0xFFFFFFFF);
  VehicleTargetedForInteractionOnFootPassengerSideCondition::sClassNameUID = result;
  return result;
}

// File Line: 691
// RVA: 0x3E8E40
void __fastcall VehicleTargetedForInteractionOnFootPassengerSideCondition::VehicleTargetedForInteractionOnFootPassengerSideCondition(VehicleTargetedForInteractionOnFootPassengerSideCondition *this)
{
  VehicleTargetedForInteractionOnFootPassengerSideCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleTargetedForInteractionOnFootPassengerSideCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
}

// File Line: 695
// RVA: 0x3E9B10
_BOOL8 __fastcall VehicleTargetedForInteractionOnFootPassengerSideCondition::Match(VehicleTargetedForInteractionOnFootPassengerSideCondition *this, ActionContext *pContext)
{
  __int64 v2; // rax
  _BOOL8 result; // rax

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  if ( (_DWORD)v2 == 3 )
    result = UFG::PredictiveStreamingStats::ms_pInstance->m_BoatInfo[(unsigned __int8)this->m_eSimObjectBoatType.mValue].m_bTargetedForInteractionOnFootPassengerSide;
  else
    result = UFG::PredictiveStreamingStats::ms_pInstance->m_VehicleInfo[v2].m_bTargetedForInteractionOnFootPassengerSide;
  return result;
}

// File Line: 722
// RVA: 0x14D1960
__int64 dynamic_initializer_for__VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition", 0xFFFFFFFF);
  VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition::sClassNameUID = result;
  return result;
}

// File Line: 732
// RVA: 0x3E8E80
void __fastcall VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition::VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition(VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition *this)
{
  VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SubPriorityModifierCondition::`vftable';
  v1->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
  v1->m_uSubPriority = -1;
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
  v1->m_eSimObjectWeaponType = 0;
}

// File Line: 736
// RVA: 0x3E9B50
char __fastcall VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition::Match(VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition *this, ActionContext *pContext)
{
  signed __int64 v2; // r10
  VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition *v3; // rdx
  __int64 v4; // rcx
  bool *v5; // rax
  char result; // al
  signed __int64 v7; // rcx
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v8; // rax
  float v9; // xmm1_4
  bool v10; // bl

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  v3 = this;
  this->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
  this->m_uSubPriority = -1;
  v4 = this->m_eSimObjectWeaponType;
  if ( (_DWORD)v2 == 3 )
    v5 = UFG::PredictiveStreamingStats::ms_pInstance->m_BoatInfo[(unsigned __int8)v3->m_eSimObjectBoatType.mValue].m_bTargetedForInteractionDriverSideOnFootByWeaponType;
  else
    v5 = UFG::PredictiveStreamingStats::ms_pInstance->m_VehicleInfo[(signed int)v2].m_bTargetedForInteractionDriverSideOnFootByWeaponType;
  if ( v5[v4] )
  {
    v3->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_eRequiredReferencedPriority;
    v3->m_uSubPriority = SubPriorityModifierCondition::ms_uTargetedInteractionPriorityLevel;
    result = 1;
  }
  else if ( UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsDriver
         || UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsPassenger
         || !UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerWeaponInfo[v4].m_bOwned )
  {
    result = 0;
  }
  else
  {
    if ( (_DWORD)v2 == 3 )
    {
      v7 = (unsigned __int8)v3->m_eSimObjectBoatType.mValue;
      v8 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerBoatInfo;
    }
    else
    {
      v8 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerVehicleInfo;
      v7 = v2;
    }
    v9 = v8[v7].m_fDistanceToDriverSide;
    v10 = s_fCloseToVehicleDistanceSquared >= v9;
    SubPriorityModifierCondition::UpdatePriorityForPlayerByDistance(
      (SubPriorityModifierCondition *)&v3->vfptr,
      v9,
      s_fCloseToVehicleDistanceSquared,
      s_fCloseToVehicleRequiredDistanceSquared);
    result = v10;
  }
  return result;
}

// File Line: 806
// RVA: 0x14D1980
__int64 dynamic_initializer_for__VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition", 0xFFFFFFFF);
  VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition::sClassNameUID = result;
  return result;
}

// File Line: 816
// RVA: 0x3E8EE0
void __fastcall VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition::VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition(VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition *this)
{
  VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SubPriorityModifierCondition::`vftable';
  v1->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
  v1->m_uSubPriority = -1;
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
  v1->m_eSimObjectWeaponType = 0;
}

// File Line: 820
// RVA: 0x3E9C40
char __fastcall VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition::Match(VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition *this, ActionContext *pContext)
{
  signed __int64 v2; // r10
  VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition *v3; // rdx
  __int64 v4; // rcx
  bool *v5; // rax
  char result; // al
  signed __int64 v7; // rcx
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v8; // rax
  float v9; // xmm1_4
  bool v10; // bl

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  v3 = this;
  this->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
  this->m_uSubPriority = -1;
  v4 = this->m_eSimObjectWeaponType;
  if ( (_DWORD)v2 == 3 )
    v5 = UFG::PredictiveStreamingStats::ms_pInstance->m_BoatInfo[(unsigned __int8)v3->m_eSimObjectBoatType.mValue].m_bTargetedForInteractionPassengerSideOnFootByWeaponType;
  else
    v5 = UFG::PredictiveStreamingStats::ms_pInstance->m_VehicleInfo[(signed int)v2].m_bTargetedForInteractionPassengerSideOnFootByWeaponType;
  if ( v5[v4] )
  {
    v3->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_eRequiredReferencedPriority;
    v3->m_uSubPriority = SubPriorityModifierCondition::ms_uTargetedInteractionPriorityLevel;
    result = 1;
  }
  else if ( UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsDriver
         || UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsPassenger
         || !UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerWeaponInfo[v4].m_bOwned )
  {
    result = 0;
  }
  else
  {
    if ( (_DWORD)v2 == 3 )
    {
      v7 = (unsigned __int8)v3->m_eSimObjectBoatType.mValue;
      v8 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerBoatInfo;
    }
    else
    {
      v8 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerVehicleInfo;
      v7 = v2;
    }
    v9 = v8[v7].m_fDistanceToPassengerSide;
    v10 = s_fCloseToVehicleDistanceSquared >= v9;
    SubPriorityModifierCondition::UpdatePriorityForPlayerByDistance(
      (SubPriorityModifierCondition *)&v3->vfptr,
      v9,
      s_fCloseToVehicleDistanceSquared,
      s_fCloseToVehicleRequiredDistanceSquared);
    result = v10;
  }
  return result;
}

// File Line: 889
// RVA: 0x14D1680
__int64 dynamic_initializer_for__CharacterTypeHasWeaponTypeCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("CharacterTypeHasWeaponTypeCondition", 0xFFFFFFFF);
  CharacterTypeHasWeaponTypeCondition::sClassNameUID = result;
  return result;
}

// File Line: 897
// RVA: 0x3E87E0
void __fastcall CharacterTypeHasWeaponTypeCondition::CharacterTypeHasWeaponTypeCondition(CharacterTypeHasWeaponTypeCondition *this)
{
  CharacterTypeHasWeaponTypeCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&CharacterTypeHasWeaponTypeCondition::`vftable';
  v1->m_eCharacterType.mValue = 0;
  v1->m_eSimObjectWeaponType = 0;
}

// File Line: 901
// RVA: 0x3E9420
_BOOL8 __fastcall CharacterTypeHasWeaponTypeCondition::Match(CharacterTypeHasWeaponTypeCondition *this, ActionContext *pContext)
{
  return UFG::PredictiveStreamingStats::ms_pInstance->m_CharacterInfo[(unsigned __int8)this->m_eCharacterType.mValue].m_bHasWeaponTypeEquipped[this->m_eSimObjectWeaponType];
}

// File Line: 936
// RVA: 0x3EB230
void __fastcall SubPriorityModifierCondition::UpdatePriorityForPlayerByDistance(SubPriorityModifierCondition *this, const float fDistanceSquared, const float fMaxDistanceSquared, const float fRequiredDistanceSquared)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4

  if ( fDistanceSquared >= fRequiredDistanceSquared )
  {
    v4 = fDistanceSquared - fRequiredDistanceSquared;
    v5 = 0.0;
    this->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
    if ( v4 < 0.0 )
      v4 = 0.0;
    v6 = fsqrt(v4 / fMaxDistanceSquared);
    if ( (float)(1.0 - v6) >= 0.0 )
      v5 = 1.0 - v6;
    this->m_uSubPriority = (signed int)(float)((float)(v5 * v5)
                                             * (float)SubPriorityModifierCondition::ms_uNumPriorityLevels);
  }
  else
  {
    this->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_eRequiredReferencedPriority;
    this->m_uSubPriority = SubPriorityModifierCondition::ms_uTargetedInteractionPriorityLevel;
  }
}

// File Line: 972
// RVA: 0x14D1820
__int64 dynamic_initializer_for__PredictiveVehicleDriverPotentialInteractionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PredictiveVehicleDriverPotentialInteractionCondition", 0xFFFFFFFF);
  PredictiveVehicleDriverPotentialInteractionCondition::sClassNameUID = result;
  return result;
}

// File Line: 980
// RVA: 0x3E8B80
void __fastcall PredictiveVehicleDriverPotentialInteractionCondition::PredictiveVehicleDriverPotentialInteractionCondition(PredictiveVehicleDriverPotentialInteractionCondition *this)
{
  PredictiveVehicleDriverPotentialInteractionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SubPriorityModifierCondition::`vftable';
  v1->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
  v1->m_uSubPriority = -1;
  v1->vfptr = (Expression::IMemberMapVtbl *)&PredictiveVehicleDriverPotentialInteractionCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
}

// File Line: 984
// RVA: 0x3E9680
bool __fastcall PredictiveVehicleDriverPotentialInteractionCondition::Match(PredictiveVehicleDriverPotentialInteractionCondition *this, ActionContext *pContext)
{
  signed __int64 v2; // r10
  PredictiveVehicleDriverPotentialInteractionCondition *v3; // rdx
  bool v4; // al
  bool result; // al
  signed __int64 v6; // rcx
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v7; // rax
  float v8; // xmm1_4
  bool v9; // bl

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  v3 = this;
  this->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
  this->m_uSubPriority = -1;
  if ( (_DWORD)v2 == 3 )
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_BoatInfo[(unsigned __int8)this->m_eSimObjectBoatType.mValue].m_bTargetedForInteractionOnFootDriverSide;
  else
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_VehicleInfo[(signed int)v2].m_bTargetedForInteractionOnFootDriverSide;
  if ( v4 )
  {
    this->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_eRequiredReferencedPriority;
    this->m_uSubPriority = SubPriorityModifierCondition::ms_uTargetedInteractionPriorityLevel;
    result = 1;
  }
  else if ( UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsDriver
         || UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsPassenger )
  {
    result = 0;
  }
  else
  {
    if ( (_DWORD)v2 == 3 )
    {
      v6 = (unsigned __int8)this->m_eSimObjectBoatType.mValue;
      v7 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerBoatInfo;
    }
    else
    {
      v7 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerVehicleInfo;
      v6 = v2;
    }
    v8 = v7[v6].m_fDistanceToDriverSide;
    v9 = s_fCloseToVehicleDistanceSquared >= v8;
    SubPriorityModifierCondition::UpdatePriorityForPlayerByDistance(
      (SubPriorityModifierCondition *)&v3->vfptr,
      v8,
      s_fCloseToVehicleDistanceSquared,
      s_fCloseToVehicleRequiredDistanceSquared);
    result = v9;
  }
  return result;
}

// File Line: 1049
// RVA: 0x14D1840
__int64 dynamic_initializer_for__PredictiveVehiclePassengerPotentialInteractionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PredictiveVehiclePassengerPotentialInteractionCondition", 0xFFFFFFFF);
  PredictiveVehiclePassengerPotentialInteractionCondition::sClassNameUID = result;
  return result;
}

// File Line: 1057
// RVA: 0x3E8BE0
void __fastcall PredictiveVehiclePassengerPotentialInteractionCondition::PredictiveVehiclePassengerPotentialInteractionCondition(PredictiveVehiclePassengerPotentialInteractionCondition *this)
{
  PredictiveVehiclePassengerPotentialInteractionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SubPriorityModifierCondition::`vftable';
  v1->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
  v1->m_uSubPriority = -1;
  v1->vfptr = (Expression::IMemberMapVtbl *)&PredictiveVehiclePassengerPotentialInteractionCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
}

// File Line: 1061
// RVA: 0x3E9760
bool __fastcall PredictiveVehiclePassengerPotentialInteractionCondition::Match(PredictiveVehiclePassengerPotentialInteractionCondition *this, ActionContext *pContext)
{
  signed __int64 v2; // r10
  PredictiveVehiclePassengerPotentialInteractionCondition *v3; // rdx
  bool v4; // al
  bool result; // al
  signed __int64 v6; // rcx
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v7; // rax
  float v8; // xmm1_4
  bool v9; // bl

  v2 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  v3 = this;
  this->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
  this->m_uSubPriority = -1;
  if ( (_DWORD)v2 == 3 )
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_BoatInfo[(unsigned __int8)this->m_eSimObjectBoatType.mValue].m_bTargetedForInteractionOnFootPassengerSide;
  else
    v4 = UFG::PredictiveStreamingStats::ms_pInstance->m_VehicleInfo[(signed int)v2].m_bTargetedForInteractionOnFootPassengerSide;
  if ( v4 )
  {
    this->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_eRequiredReferencedPriority;
    this->m_uSubPriority = SubPriorityModifierCondition::ms_uTargetedInteractionPriorityLevel;
    result = 1;
  }
  else if ( UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsDriver
         || UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_bIsPassenger )
  {
    result = 0;
  }
  else
  {
    if ( (_DWORD)v2 == 3 )
    {
      v6 = (unsigned __int8)this->m_eSimObjectBoatType.mValue;
      v7 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerBoatInfo;
    }
    else
    {
      v7 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerVehicleInfo;
      v6 = v2;
    }
    v8 = v7[v6].m_fDistanceToPassengerSide;
    v9 = s_fCloseToVehicleDistanceSquared >= v8;
    SubPriorityModifierCondition::UpdatePriorityForPlayerByDistance(
      (SubPriorityModifierCondition *)&v3->vfptr,
      v8,
      s_fCloseToVehicleDistanceSquared,
      s_fCloseToVehicleRequiredDistanceSquared);
    result = v9;
  }
  return result;
}

// File Line: 1126
// RVA: 0x14D1860
__int64 dynamic_initializer_for__PredictiveVehiclePlayerPotentialInteractionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PredictiveVehiclePlayerPotentialInteractionCondition", 0xFFFFFFFF);
  PredictiveVehiclePlayerPotentialInteractionCondition::sClassNameUID = result;
  return result;
}

// File Line: 1134
// RVA: 0x3E8C40
void __fastcall PredictiveVehiclePlayerPotentialInteractionCondition::PredictiveVehiclePlayerPotentialInteractionCondition(PredictiveVehiclePlayerPotentialInteractionCondition *this)
{
  PredictiveVehiclePlayerPotentialInteractionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SubPriorityModifierCondition::`vftable';
  v1->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
  v1->m_uSubPriority = -1;
  v1->vfptr = (Expression::IMemberMapVtbl *)&PredictiveVehiclePlayerPotentialInteractionCondition::`vftable';
  *(_WORD *)&v1->m_eSimObjectVehicleType.mValue = 0;
}

// File Line: 1138
// RVA: 0x3E9840
_BOOL8 __fastcall PredictiveVehiclePlayerPotentialInteractionCondition::Match(PredictiveVehiclePlayerPotentialInteractionCondition *this, ActionContext *pContext)
{
  PredictiveVehiclePlayerPotentialInteractionCondition *v2; // r9
  __int64 v3; // rax
  signed __int64 v4; // r8
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v5; // rcx
  __m128 v6; // xmm0
  __m128 v7; // xmm1
  UFG::PredictiveStreamingStats::PlayerVehicleInfo *v8; // rcx
  float v9; // xmm2_4
  bool v10; // dl
  _BOOL8 result; // rax
  float v12; // xmm1_4
  float v13; // xmm0_4

  v2 = this;
  this->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
  this->m_uSubPriority = -1;
  v3 = (unsigned __int8)this->m_eSimObjectVehicleType.mValue;
  if ( (_DWORD)v3 == 3 )
  {
    v4 = (unsigned __int8)this->m_eSimObjectBoatType.mValue;
    v5 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerBoatInfo;
    v6 = (__m128)LODWORD(v5[v4].m_fDistanceToDriverSide);
    v7 = (__m128)LODWORD(v5[v4].m_fDistanceToPassengerSide);
  }
  else
  {
    v8 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerVehicleInfo;
    v6 = (__m128)LODWORD(v8[v3].m_fDistanceToDriverSide);
    v7 = (__m128)LODWORD(v8[v3].m_fDistanceToPassengerSide);
  }
  if ( v6.m128_f32[0] >= v7.m128_f32[0] )
    v6 = v7;
  v9 = s_fCloseToVehicleActionHijackDistanceSquared;
  v10 = s_fCloseToVehicleActionHijackDistanceSquared >= v6.m128_f32[0];
  if ( v6.m128_f32[0] >= s_fCloseToVehicleActionHijackDistanceSquared )
  {
    v6.m128_f32[0] = v6.m128_f32[0] - s_fCloseToVehicleActionHijackDistanceSquared;
    v12 = 0.0;
    v2->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
    if ( v6.m128_f32[0] < 0.0 )
      v6 = 0i64;
    v6.m128_f32[0] = v6.m128_f32[0] / v9;
    LODWORD(v13) = (unsigned __int128)_mm_sqrt_ps(v6);
    if ( (float)(1.0 - v13) >= 0.0 )
      v12 = 1.0 - v13;
    v2->m_uSubPriority = (signed int)(float)((float)(v12 * v12)
                                           * (float)SubPriorityModifierCondition::ms_uNumPriorityLevels);
    result = v10;
  }
  else
  {
    result = v10;
    v2->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_eRequiredReferencedPriority;
    v2->m_uSubPriority = SubPriorityModifierCondition::ms_uTargetedInteractionPriorityLevel;
  }
  return result;
}

// File Line: 1179
// RVA: 0x14D1880
__int64 dynamic_initializer_for__PredictiveWeaponPotentialInteractionCondition::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("PredictiveWeaponPotentialInteractionCondition", 0xFFFFFFFF);
  PredictiveWeaponPotentialInteractionCondition::sClassNameUID = result;
  return result;
}

// File Line: 1185
// RVA: 0x3E8CA0
void __fastcall PredictiveWeaponPotentialInteractionCondition::PredictiveWeaponPotentialInteractionCondition(PredictiveWeaponPotentialInteractionCondition *this)
{
  PredictiveWeaponPotentialInteractionCondition *v1; // rbx

  v1 = this;
  Condition::Condition((Condition *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&SubPriorityModifierCondition::`vftable';
  v1->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
  v1->m_uSubPriority = -1;
  v1->vfptr = (Expression::IMemberMapVtbl *)&PredictiveWeaponPotentialInteractionCondition::`vftable';
  v1->m_eSimObjectWeaponType = 0;
}

// File Line: 1189
// RVA: 0x3E9930
bool __fastcall PredictiveWeaponPotentialInteractionCondition::Match(PredictiveWeaponPotentialInteractionCondition *this, ActionContext *pContext)
{
  __int64 v2; // rdx
  UFG::PredictiveStreamingStats::WeaponInfo *v3; // rax
  float v4; // xmm6_4
  float v5; // xmm7_4
  bool result; // al

  v2 = this->m_eSimObjectWeaponType;
  this->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_ePredictivePriority;
  this->m_uSubPriority = -1;
  v3 = UFG::PredictiveStreamingStats::ms_pInstance->m_WeaponInfo;
  if ( v3[v2].m_bOwned || v3[v2].m_bTargetedForInteractionOnFoot )
  {
    this->m_eAnimationPriority.mValue = SubPriorityModifierCondition::ms_eRequiredReferencedPriority;
    this->m_uSubPriority = SubPriorityModifierCondition::ms_uTargetedInteractionPriorityLevel;
    result = 1;
  }
  else
  {
    v4 = s_fCloseToWeaponDistanceSquared;
    v5 = UFG::PredictiveStreamingStats::ms_pInstance->m_PlayerInfo.m_PlayerWeaponInfo[v2].m_fDistanceSquared;
    SubPriorityModifierCondition::UpdatePriorityForPlayerByDistance(
      (SubPriorityModifierCondition *)&this->vfptr,
      v5,
      s_fCloseToWeaponDistanceSquared,
      s_fCloseToWeaponRequiredDistanceSquared);
    result = v4 >= v5;
  }
  return result;
}

