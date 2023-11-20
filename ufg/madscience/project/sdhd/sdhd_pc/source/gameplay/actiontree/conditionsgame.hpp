// File Line: 87
// RVA: 0x27C8B0
__int64 __fastcall UELExpressionCondition::GetClassNameUID(UELExpressionCondition *this)
{
  return UELExpressionCondition::sClassNameUID;
}

// File Line: 106
// RVA: 0x2C03C0
__int64 __fastcall WasBittenCondition::GetClassNameUID(WasBittenCondition *this)
{
  return WasBittenCondition::sClassNameUID;
}

// File Line: 123
// RVA: 0x2BDA50
__int64 __fastcall ActiveProgressionFlowCondition::GetClassNameUID(ActiveProgressionFlowCondition *this)
{
  return ActiveProgressionFlowCondition::sClassNameUID;
}

// File Line: 150
// RVA: 0x3193A0
void __fastcall FacialRequestCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::FacialRequestCondition", 0i64, 1u);
  if ( v0 )
    FacialRequestCondition::FacialRequestCondition((FacialRequestCondition *)v0);
}

// File Line: 180
// RVA: 0x314940
void __fastcall ActionRequestCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::ActionRequestCondition", 0i64, 1u);
  if ( v0 )
    ActionRequestCondition::ActionRequestCondition((ActionRequestCondition *)v0);
}

// File Line: 192
// RVA: 0x27DCF0
signed __int64 __fastcall ActionRequestCondition::GetSignalMask(ActionRequestCondition *this)
{
  return 1i64 << (this->mActionRequest & 0x3F);
}

// File Line: 212
// RVA: 0x27BEB0
__int64 __fastcall ClothingPurchaseCondition::GetClassNameUID(ClothingPurchaseCondition *this)
{
  return ClothingPurchaseCondition::sClassNameUID;
}

// File Line: 238
// RVA: 0x2C1890
const char *__fastcall IsPlayingCondition::GetClassname(IsPlayingCondition *this)
{
  return IsPlayingCondition::sClassName;
}

// File Line: 263
// RVA: 0x31C350
IsPlayingThisCondition *__fastcall IsPlayingThisCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::IsPlayingThisCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &IsPlayingThisCondition::`vftable';
  *((_QWORD *)v1 + 3) = 0i64;
  return (IsPlayingThisCondition *)v1;
}

// File Line: 279
// RVA: 0x31C3C0
IsPlayingThisInPathCondition *__fastcall IsPlayingThisInPathCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::IsPlayingThisInPathCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &IsPlayingThisInPathCondition::`vftable';
  *((_QWORD *)v1 + 3) = 0i64;
  return (IsPlayingThisInPathCondition *)v1;
}

// File Line: 295
// RVA: 0x27CEE0
const char *__fastcall IsPlayingNodeCondition::GetClassname(IsPlayingNodeCondition *this)
{
  return IsPlayingNodeCondition::sClassName;
}

// File Line: 322
// RVA: 0x2BEC20
__int64 __fastcall IsPlayingPreviousCondition::GetClassNameUID(IsPlayingPreviousCondition *this)
{
  return IsPlayingPreviousCondition::sClassNameUID;
}

// File Line: 346
// RVA: 0x27C2D0
__int64 __fastcall IsPlayingNodePreviousCondition::GetClassNameUID(IsPlayingNodePreviousCondition *this)
{
  return IsPlayingNodePreviousCondition::sClassNameUID;
}

// File Line: 373
// RVA: 0x2BEC10
__int64 __fastcall IsPlayingNextCondition::GetClassNameUID(IsPlayingNextCondition *this)
{
  return IsPlayingNextCondition::sClassNameUID;
}

// File Line: 394
// RVA: 0x2BFAE0
__int64 __fastcall TargetIsPlayingCondition::GetClassNameUID(TargetIsPlayingCondition *this)
{
  return TargetIsPlayingCondition::sClassNameUID;
}

// File Line: 423
// RVA: 0x2BFB00
__int64 __fastcall TargetIsSubTargetValid::GetClassNameUID(TargetIsSubTargetValid *this)
{
  return TargetIsSubTargetValid::sClassNameUID;
}

// File Line: 436
// RVA: 0x27DD00
UFG::qSymbol *__fastcall TargetIsSubTargetValid::GetSubTargetName(TargetIsSubTargetValid *this, UFG::qSymbol *result)
{
  result->mUID = (unsigned int)this->m_SubTargetName;
  return result;
}

// File Line: 477
// RVA: 0x31B940
IsHostCondition *__fastcall IsHostCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::IsHostCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &IsHostCondition::`vftable';
  return (IsHostCondition *)v1;
}

// File Line: 500
// RVA: 0x2BEBB0
__int64 __fastcall IsPlayerCondition::GetClassNameUID(IsPlayerCondition *this)
{
  return IsPlayerCondition::sClassNameUID;
}

// File Line: 523
// RVA: 0x31BFC0
IsPlayerInClothingStore *__fastcall IsPlayerInClothingStore::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::IsPlayerInClothingStore", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &IsPlayerInClothingStore::`vftable';
  return (IsPlayerInClothingStore *)v1;
}

// File Line: 541
// RVA: 0x2BEAB0
__int64 __fastcall IsFemaleCondition::GetClassNameUID(IsFemaleCondition *this)
{
  return IsFemaleCondition::sClassNameUID;
}

// File Line: 553
// RVA: 0x27D2D0
const char *__fastcall TargetIsFemaleCondition::GetClassname(TargetIsFemaleCondition *this)
{
  return TargetIsFemaleCondition::sClassName;
}

// File Line: 571
// RVA: 0x31C660
IsTakingDamageCondition *__fastcall IsTakingDamageCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::IsTakingDamageCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &IsTakingDamageCondition::`vftable';
  return (IsTakingDamageCondition *)v1;
}

// File Line: 586
// RVA: 0x2C1790
const char *__fastcall IsInvulnerableCondition::GetClassname(IsInvulnerableCondition *this)
{
  return IsInvulnerableCondition::sClassName;
}

// File Line: 603
// RVA: 0x2BE840
__int64 __fastcall HasRagdollCondition::GetClassNameUID(HasRagdollCondition *this)
{
  return HasRagdollCondition::sClassNameUID;
}

// File Line: 627
// RVA: 0x27D160
const char *__fastcall RagdollHasConstraintsCondition::GetClassname(RagdollHasConstraintsCondition *this)
{
  return RagdollHasConstraintsCondition::sClassName;
}

// File Line: 651
// RVA: 0x31CCE0
MinigameSuccessCondition *__fastcall MinigameSuccessCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::MinigameSuccessCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &MinigameSuccessCondition::`vftable';
  *((_DWORD *)v1 + 6) = 0;
  return (MinigameSuccessCondition *)v1;
}

// File Line: 689
// RVA: 0x27CF60
const char *__fastcall MotionIntentionDirection::GetClassname(MotionIntentionDirection *this)
{
  return MotionIntentionDirection::sClassName;
}

// File Line: 732
// RVA: 0x27CF70
const char *__fastcall MotionIntentionDirectionRaw::GetClassname(MotionIntentionDirectionRaw *this)
{
  return MotionIntentionDirectionRaw::sClassName;
}

// File Line: 769
// RVA: 0x27CF80
const char *__fastcall MotionIntentionDirectionRel::GetClassname(MotionIntentionDirectionRel *this)
{
  return MotionIntentionDirectionRel::sClassName;
}

// File Line: 807
// RVA: 0x27CF90
const char *__fastcall MotionIntentionDirectionRelTarget::GetClassname(MotionIntentionDirectionRelTarget *this)
{
  return MotionIntentionDirectionRelTarget::sClassName;
}

// File Line: 865
// RVA: 0x27CC50
const char *__fastcall FacingIntentionDirection::GetClassname(FacingIntentionDirection *this)
{
  return FacingIntentionDirection::sClassName;
}

// File Line: 890
// RVA: 0x27C040
__int64 __fastcall FacingPelvisDirection::GetClassNameUID(FacingPelvisDirection *this)
{
  return FacingPelvisDirection::sClassNameUID;
}

// File Line: 922
// RVA: 0x31D290
void __fastcall MotionIntentionSpeed::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::MotionIntentionSpeed", 0i64, 1u);
  if ( v0 )
    MotionIntentionSpeed::MotionIntentionSpeed((MotionIntentionSpeed *)v0);
}

// File Line: 954
// RVA: 0x31D2E0
void __fastcall MotionIntentionSpeedRaw::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::MotionIntentionSpeedRaw", 0i64, 1u);
  if ( v0 )
    MotionIntentionSpeedRaw::MotionIntentionSpeedRaw((MotionIntentionSpeedRaw *)v0);
}

// File Line: 984
// RVA: 0x27C9E0
const char *__fastcall AimIntentionRangeCondition::GetClassname(AimIntentionRangeCondition *this)
{
  return AimIntentionRangeCondition::sClassName;
}

// File Line: 1012
// RVA: 0x314E00
void __fastcall AimIntentionAngleCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::AimIntentionAngleCondition", 0i64, 1u);
  if ( v0 )
    AimIntentionAngleCondition::AimIntentionAngleCondition((AimIntentionAngleCondition *)v0);
}

// File Line: 1039
// RVA: 0x27C9F0
const char *__fastcall AimIntentionSpeedCondition::GetClassname(AimIntentionSpeedCondition *this)
{
  return AimIntentionSpeedCondition::sClassName;
}

// File Line: 1065
// RVA: 0x27C3B0
__int64 __fastcall MotionVelocityMagnitude::GetClassNameUID(MotionVelocityMagnitude *this)
{
  return MotionVelocityMagnitude::sClassNameUID;
}

// File Line: 1093
// RVA: 0x27C330
__int64 __fastcall MotionAngularVelocityMagnitude::GetClassNameUID(MotionAngularVelocityMagnitude *this)
{
  return MotionAngularVelocityMagnitude::sClassNameUID;
}

// File Line: 1122
// RVA: 0x31D380
void __fastcall MotionRotationSignal::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::MotionRotationSignal", 0i64, 1u);
  if ( v0 )
    MotionRotationSignal::MotionRotationSignal((MotionRotationSignal *)v0);
}

// File Line: 1150
// RVA: 0x27CCC0
const char *__fastcall HealthCondition::GetClassname(HealthCondition *this)
{
  return HealthCondition::sClassName;
}

// File Line: 1183
// RVA: 0x27CCB0
const char *__fastcall HealthClampedToMinimumCondition::GetClassname(HealthClampedToMinimumCondition *this)
{
  return HealthClampedToMinimumCondition::sClassName;
}

// File Line: 1212
// RVA: 0x321E00
void __fastcall TargetDistance::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "MemberMap::TargetDistance", 0i64, 1u);
  if ( v0 )
    TargetDistance::TargetDistance((TargetDistance *)v0);
}

// File Line: 1295
// RVA: 0x321B50
void __fastcall TargetCloserThanTargetCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::TargetCloserThanTargetCondition",
         0i64,
         1u);
  if ( v0 )
    TargetCloserThanTargetCondition::TargetCloserThanTargetCondition((TargetCloserThanTargetCondition *)v0);
}

// File Line: 1336
// RVA: 0x319C40
void __fastcall GroundDistance::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::GroundDistance", 0i64, 1u);
  if ( v0 )
    GroundDistance::GroundDistance((GroundDistance *)v0);
}

// File Line: 1361
// RVA: 0x27C7C0
__int64 __fastcall TargetRelativePosition::GetClassNameUID(TargetRelativePosition *this)
{
  return TargetRelativePosition::sClassNameUID;
}

// File Line: 1407
// RVA: 0x321BA0
void __fastcall TargetConditionGroup::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x28ui64, "MemberMap::TargetConditionGroup", 0i64, 1u);
  if ( v0 )
    TargetConditionGroup::TargetConditionGroup((TargetConditionGroup *)v0);
}

// File Line: 1428
// RVA: 0x27D5B0
ConditionGroup *__fastcall TargetConditionGroup::GetConditionGroup2(TargetConditionGroup *this)
{
  ConditionGroup *result; // rax

  result = (ConditionGroup *)this->mConditions.mOffset;
  if ( result )
    result = (ConditionGroup *)((char *)result + (_QWORD)this + 24);
  return result;
}

// File Line: 1430
// RVA: 0x294300
void __fastcall TargetConditionGroup::SetConditionGroup2(TargetConditionGroup *this, Expression::IMemberMap *conditions)
{
  UFG::qOffset64<ConditionGroup *> *v2; // rcx

  v2 = &this->mConditions;
  if ( conditions )
    v2->mOffset = (char *)conditions - (char *)v2;
  else
    v2->mOffset = 0i64;
}

// File Line: 1456
// RVA: 0x31E1C0
void __fastcall ParkourHandleCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x68ui64, "MemberMap::ParkourHandleCondition", 0i64, 1u);
  if ( v0 )
    ParkourHandleCondition::ParkourHandleCondition((ParkourHandleCondition *)v0);
}

// File Line: 1463
// RVA: 0x294010
void __fastcall ParkourHandleCondition::ResolveReferences(ParkourHandleCondition *this, ActionNode *parentNode)
{
  UFG::qOffset64<ActionNode *> *v2; // rcx

  v2 = &this->mParentNode;
  if ( parentNode )
    v2->mOffset = (char *)parentNode - (char *)v2;
  else
    v2->mOffset = 0i64;
}

// File Line: 1631
// RVA: 0x27C420
__int64 __fastcall ParkourHandleLatchedCloseToEdgeCondition::GetClassNameUID(ParkourHandleLatchedCloseToEdgeCondition *this)
{
  return ParkourHandleLatchedCloseToEdgeCondition::sClassNameUID;
}

// File Line: 1661
// RVA: 0x27D030
const char *__fastcall ParkourHandleInfoCondition::GetClassname(ParkourHandleInfoCondition *this)
{
  return ParkourHandleInfoCondition::sClassName;
}

// File Line: 1688
// RVA: 0x27D050
const char *__fastcall ParkourHandleOwnerIsCondition::GetClassname(ParkourHandleOwnerIsCondition *this)
{
  return ParkourHandleOwnerIsCondition::sClassName;
}

// File Line: 1705
// RVA: 0x27C440
__int64 __fastcall ParkourHandleSpeedCondition::GetClassNameUID(ParkourHandleSpeedCondition *this)
{
  return ParkourHandleSpeedCondition::sClassNameUID;
}

// File Line: 1731
// RVA: 0x27C450
__int64 __fastcall ParkourSphereCastCondition::GetClassNameUID(ParkourSphereCastCondition *this)
{
  return ParkourSphereCastCondition::sClassNameUID;
}

// File Line: 1793
// RVA: 0x27C620
__int64 __fastcall SphereCastCondition::GetClassNameUID(SphereCastCondition *this)
{
  return SphereCastCondition::sClassNameUID;
}

// File Line: 1882
// RVA: 0x27CA90
const char *__fastcall BrokenVehicleGlassSphereCastCondition::GetClassname(BrokenVehicleGlassSphereCastCondition *this)
{
  return BrokenVehicleGlassSphereCastCondition::sClassName;
}

// File Line: 1963
// RVA: 0x27D320
const char *__fastcall TargetParkourHandleCondition::GetClassname(TargetParkourHandleCondition *this)
{
  return TargetParkourHandleCondition::sClassName;
}

// File Line: 2006
// RVA: 0x318EA0
void __fastcall DropoffCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::DropoffCondition", 0i64, 1u);
  if ( v0 )
    DropoffCondition::DropoffCondition((DropoffCondition *)v0);
}

// File Line: 2038
// RVA: 0x2C1C50
const char *__fastcall OnGround::GetClassname(OnGround *this)
{
  return OnGround::sClassName;
}

// File Line: 2080
// RVA: 0x2C1C70
const char *__fastcall OnGroundSurfaceType::GetClassname(OnGroundSurfaceType *this)
{
  return OnGroundSurfaceType::sClassName;
}

// File Line: 2101
// RVA: 0x31DAE0
OnGroundSurfaceGrade *__fastcall OnGroundSurfaceGrade::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::OnGroundSurfaceGrade", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &OnGroundSurfaceGrade::`vftable';
  *((_DWORD *)v1 + 6) = 0;
  *((_DWORD *)v1 + 7) = 1070141403;
  return (OnGroundSurfaceGrade *)v1;
}

// File Line: 2130
// RVA: 0x27CD40
const char *__fastcall HitTime::GetClassname(HitTime *this)
{
  return HitTime::sClassName;
}

// File Line: 2156
// RVA: 0x27BE60
__int64 __fastcall AttackType::GetClassNameUID(AttackType *this)
{
  return AttackType::sClassNameUID;
}

// File Line: 2174
// RVA: 0x3155C0
void __fastcall AttackLocationLateral::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::AttackLocationLateral", 0i64, 1u);
  if ( v0 )
    AttackLocationLateral::AttackLocationLateral((AttackLocationLateral *)v0);
}

// File Line: 2192
// RVA: 0x315570
void __fastcall AttackLocationHorizontal::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::AttackLocationHorizontal", 0i64, 1u);
  if ( v0 )
    AttackLocationHorizontal::AttackLocationHorizontal((AttackLocationHorizontal *)v0);
}

// File Line: 2210
// RVA: 0x27BE30
__int64 __fastcall AttackLocationRagdoll::GetClassNameUID(AttackLocationRagdoll *this)
{
  return AttackLocationRagdoll::sClassNameUID;
}

// File Line: 2229
// RVA: 0x315520
void __fastcall AttackIntensityCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::AttackIntensityCondition", 0i64, 1u);
  if ( v0 )
    AttackIntensityCondition::AttackIntensityCondition((AttackIntensityCondition *)v0);
}

// File Line: 2251
// RVA: 0x27BDE0
__int64 __fastcall AttackDamageCondition::GetClassNameUID(AttackDamageCondition *this)
{
  return AttackDamageCondition::sClassNameUID;
}

// File Line: 2275
// RVA: 0x27CB30
const char *__fastcall CollisionTime::GetClassname(CollisionTime *this)
{
  return CollisionTime::sClassName;
}

// File Line: 2301
// RVA: 0x27BEE0
__int64 __fastcall CollisionLayer::GetClassNameUID(CollisionLayer *this)
{
  return CollisionLayer::sClassNameUID;
}

// File Line: 2323
// RVA: 0x27BF00
__int64 __fastcall CollisionSpeed::GetClassNameUID(CollisionSpeed *this)
{
  return CollisionSpeed::sClassNameUID;
}

// File Line: 2353
// RVA: 0x27CAF0
const char *__fastcall CollisionEstimatedImpulseMagnitude::GetClassname(CollisionEstimatedImpulseMagnitude *this)
{
  return CollisionEstimatedImpulseMagnitude::sClassName;
}

// File Line: 2379
// RVA: 0x3178D0
void __fastcall CollisionMass::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::CollisionMass", 0i64, 1u);
  if ( v0 )
    CollisionMass::CollisionMass((CollisionMass *)v0);
}

// File Line: 2405
// RVA: 0x27BE50
__int64 __fastcall AttackTimerCondition::GetClassNameUID(AttackTimerCondition *this)
{
  return AttackTimerCondition::sClassNameUID;
}

// File Line: 2434
// RVA: 0x27BE40
__int64 __fastcall AttackPhaseCondition::GetClassNameUID(AttackPhaseCondition *this)
{
  return AttackPhaseCondition::sClassNameUID;
}

// File Line: 2454
// RVA: 0x3154D0
void __fastcall AttackInfoNumberHitsCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::AttackInfoNumberHitsCondition",
         0i64,
         1u);
  if ( v0 )
    AttackInfoNumberHitsCondition::AttackInfoNumberHitsCondition((AttackInfoNumberHitsCondition *)v0);
}

// File Line: 2482
// RVA: 0x31B2F0
void __fastcall InventoryQuantityCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x28ui64, "MemberMap::InventoryQuantityCondition", 0i64, 1u);
  if ( v0 )
    InventoryQuantityCondition::InventoryQuantityCondition((InventoryQuantityCondition *)v0);
}

// File Line: 2512
// RVA: 0x27C1F0
__int64 __fastcall InventoryIsItemEquipped::GetClassNameUID(InventoryIsItemEquipped *this)
{
  return InventoryIsItemEquipped::sClassNameUID;
}

// File Line: 2538
// RVA: 0x31B1E0
void __fastcall InventoryCanDrop::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::InventoryCanDrop", 0i64, 1u);
  if ( v0 )
    InventoryCanDrop::InventoryCanDrop((InventoryCanDrop *)v0);
}

// File Line: 2562
// RVA: 0x31FAE0
void __fastcall RandomCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::RandomCondition", 0i64, 1u);
  if ( v0 )
    RandomCondition::RandomCondition((RandomCondition *)v0);
}

// File Line: 2571
// RVA: 0x27DF80
IWeightedCondition *__fastcall Scaleform::Event::GetAcquireInterface(RandomCondition *this)
{
  IWeightedCondition *result; // rax

  if ( this )
    result = (IWeightedCondition *)&this->vfptr;
  else
    result = 0i64;
  return result;
}

// File Line: 2577
// RVA: 0x294320
void __fastcall RandomCondition::SetWeight(RandomCondition *this, float weight)
{
  *(float *)&this->mPad0 = weight;
}

// File Line: 2581
// RVA: 0x2942F0
void __fastcall RandomCondition::SetBalancedWeight(RandomCondition *this, float weight)
{
  *(float *)&this->mPad1 = weight;
}

// File Line: 2605
// RVA: 0x31E5D0
void __fastcall PersonalityTypeCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x30ui64, "MemberMap::PersonalityTypeCondition", 0i64, 1u);
  if ( v0 )
    PersonalityTypeCondition::PersonalityTypeCondition((PersonalityTypeCondition *)v0);
}

// File Line: 2638
// RVA: 0x27BD80
__int64 __fastcall AiBehaviourCondition::GetClassNameUID(AiBehaviourCondition *this)
{
  return AiBehaviourCondition::sClassNameUID;
}

// File Line: 2663
// RVA: 0x27BD90
__int64 __fastcall AiBehaviourTreeTypeCondition::GetClassNameUID(AiBehaviourTreeTypeCondition *this)
{
  return AiBehaviourTreeTypeCondition::sClassNameUID;
}

// File Line: 2683
// RVA: 0x314DB0
void __fastcall AiEmotionCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::AiEmotionCondition", 0i64, 1u);
  if ( v0 )
    AiEmotionCondition::AiEmotionCondition((AiEmotionCondition *)v0);
}

// File Line: 2703
// RVA: 0x27CC30
const char *__fastcall FacialEmotionCondition::GetClassname(FacialEmotionCondition *this)
{
  return FacialEmotionCondition::sClassName;
}

// File Line: 2724
// RVA: 0x2C21D0
const char *__fastcall RelativeOrientationCondition::GetClassname(RelativeOrientationCondition *this)
{
  return RelativeOrientationCondition::sClassName;
}

// File Line: 2725
// RVA: 0x29D790
void __fastcall RelativeOrientationCondition::~RelativeOrientationCondition(RelativeOrientationCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&RelativeOrientationCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 2757
// RVA: 0x2BFC50
__int64 __fastcall TargetRelativeOrientationCondition::GetClassNameUID(TargetRelativeOrientationCondition *this)
{
  return TargetRelativeOrientationCondition::sClassNameUID;
}

// File Line: 2784
// RVA: 0x29D7D0
void __fastcall RelativePositionCondition::~RelativePositionCondition(RelativePositionCondition *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&RelativePositionCondition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 2786
// RVA: 0x2C21E0
const char *__fastcall RelativePositionCondition::GetClassname(RelativePositionCondition *this)
{
  return RelativePositionCondition::sClassName;
}

// File Line: 2816
// RVA: 0x2C15C0
const char *__fastcall HitLocation::GetClassname(HitLocation *this)
{
  return HitLocation::sClassName;
}

// File Line: 2833
// RVA: 0x2C15B0
const char *__fastcall HitImpulse::GetClassname(HitImpulse *this)
{
  return HitImpulse::sClassName;
}

// File Line: 2852
// RVA: 0x322DF0
void __fastcall TargetPropInteractAvailableCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::TargetPropInteractAvailableCondition",
         0i64,
         1u);
  if ( v0 )
    TargetPropInteractAvailableCondition::TargetPropInteractAvailableCondition((TargetPropInteractAvailableCondition *)v0);
}

// File Line: 2869
// RVA: 0x322E40
void __fastcall TargetPropInteractOrientationCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::TargetPropInteractOrientationCondition",
         0i64,
         1u);
  if ( v0 )
    TargetPropInteractOrientationCondition::TargetPropInteractOrientationCondition((TargetPropInteractOrientationCondition *)v0);
}

// File Line: 2901
// RVA: 0x2C2770
const char *__fastcall TargetIsLockedCondition::GetClassname(TargetIsLockedCondition *this)
{
  return TargetIsLockedCondition::sClassName;
}

// File Line: 2922
// RVA: 0x2BFD00
__int64 __fastcall TargetVelocityRelativeToCollisionCondition::GetClassNameUID(TargetVelocityRelativeToCollisionCondition *this)
{
  return TargetVelocityRelativeToCollisionCondition::sClassNameUID;
}

// File Line: 2944
// RVA: 0x31A5D0
HitCollisionVelocityRelativeToNormal *__fastcall HitCollisionVelocityRelativeToNormal::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::HitCollisionVelocityRelativeToNormal",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &RelativeOrientationCondition::`vftable';
  *((_DWORD *)v1 + 6) = 0;
  *((_DWORD *)v1 + 7) = 1061752795;
  *(_QWORD *)v1 = &HitCollisionVelocityRelativeToNormal::`vftable';
  return (HitCollisionVelocityRelativeToNormal *)v1;
}

// File Line: 2964
// RVA: 0x27C0D0
__int64 __fastcall HitLocationTargettedCondition::GetClassNameUID(HitLocationTargettedCondition *this)
{
  return HitLocationTargettedCondition::sClassNameUID;
}

// File Line: 2981
// RVA: 0x27CD10
const char *__fastcall HitProjectileReactionCondition::GetClassname(HitProjectileReactionCondition *this)
{
  return HitProjectileReactionCondition::sClassName;
}

// File Line: 3004
// RVA: 0x27C0E0
__int64 __fastcall HitProjectileIsExplosiveCondition::GetClassNameUID(HitProjectileIsExplosiveCondition *this)
{
  return HitProjectileIsExplosiveCondition::sClassNameUID;
}

// File Line: 3021
// RVA: 0x31A930
void __fastcall HitProjectileWeaponTypeCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::HitProjectileWeaponTypeCondition",
         0i64,
         1u);
  if ( v0 )
    HitProjectileWeaponTypeCondition::HitProjectileWeaponTypeCondition((HitProjectileWeaponTypeCondition *)v0);
}

// File Line: 3045
// RVA: 0x31A8E0
void __fastcall HitProjectileWeaponInventoryTypeCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::HitProjectileWeaponInventoryTypeCondition",
         0i64,
         1u);
  if ( v0 )
    HitProjectileWeaponInventoryTypeCondition::HitProjectileWeaponInventoryTypeCondition((HitProjectileWeaponInventoryTypeCondition *)v0);
}

// File Line: 3068
// RVA: 0x31A650
void __fastcall HitDistanceFromExplosionCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::HitDistanceFromExplosionCondition",
         0i64,
         1u);
  if ( v0 )
    HitDistanceFromExplosionCondition::HitDistanceFromExplosionCondition((HitDistanceFromExplosionCondition *)v0);
}

// File Line: 3098
// RVA: 0x27CCE0
const char *__fastcall HitExplosionCanTriggerVehicleExplosion::GetClassname(HitExplosionCanTriggerVehicleExplosion *this)
{
  return HitExplosionCanTriggerVehicleExplosion::sClassName;
}

// File Line: 3115
// RVA: 0x321270
void __fastcall SpeedCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::SpeedCondition", 0i64, 1u);
  if ( v0 )
    SpeedCondition::SpeedCondition((SpeedCondition *)v0);
}

// File Line: 3147
// RVA: 0x27C760
__int64 __fastcall TargetPhysicalMassCondition::GetClassNameUID(TargetPhysicalMassCondition *this)
{
  return TargetPhysicalMassCondition::sClassNameUID;
}

// File Line: 3184
// RVA: 0x27C730
__int64 __fastcall TargetPhysicalCollisionLayerCondition::GetClassNameUID(TargetPhysicalCollisionLayerCondition *this)
{
  return TargetPhysicalCollisionLayerCondition::sClassNameUID;
}

// File Line: 3216
// RVA: 0x27C710
__int64 __fastcall TargetPhysicalAttackShootComboCondition::GetClassNameUID(TargetPhysicalAttackShootComboCondition *this)
{
  return TargetPhysicalAttackShootComboCondition::sClassNameUID;
}

// File Line: 3244
// RVA: 0x3229E0
void __fastcall TargetPhysicalAttackVelocityCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::TargetPhysicalAttackVelocityCondition",
         0i64,
         1u);
  if ( v0 )
    TargetPhysicalAttackVelocityCondition::TargetPhysicalAttackVelocityCondition((TargetPhysicalAttackVelocityCondition *)v0);
}

// File Line: 3280
// RVA: 0x322A80
void __fastcall TargetPhysicalDamageMultiplierCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::TargetPhysicalDamageMultiplierCondition",
         0i64,
         1u);
  if ( v0 )
    TargetPhysicalDamageMultiplierCondition::TargetPhysicalDamageMultiplierCondition((TargetPhysicalDamageMultiplierCondition *)v0);
}

// File Line: 3321
// RVA: 0x322B20
void __fastcall TargetPhysicalDodgeableCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::TargetPhysicalDodgeableCondition",
         0i64,
         1u);
  if ( v0 )
    TargetPhysicalDodgeableCondition::TargetPhysicalDodgeableCondition((TargetPhysicalDodgeableCondition *)v0);
}

// File Line: 3349
// RVA: 0x27C770
__int64 __fastcall TargetPhysicalMeleeAttackableCondition::GetClassNameUID(TargetPhysicalMeleeAttackableCondition *this)
{
  return TargetPhysicalMeleeAttackableCondition::sClassNameUID;
}

// File Line: 3384
// RVA: 0x326160
void __fastcall VehicleWheelSurfaceCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::VehicleWheelSurfaceCondition",
         0i64,
         1u);
  if ( v0 )
    VehicleWheelSurfaceCondition::VehicleWheelSurfaceCondition((VehicleWheelSurfaceCondition *)v0);
}

// File Line: 3415
// RVA: 0x3174C0
void __fastcall CharacterSurfaceCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::CharacterSurfaceCondition", 0i64, 1u);
  if ( v0 )
    CharacterSurfaceCondition::CharacterSurfaceCondition((CharacterSurfaceCondition *)v0);
}

// File Line: 3439
// RVA: 0x325CA0
void __fastcall VehicleSpeedCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::VehicleSpeedCondition", 0i64, 1u);
  if ( v0 )
    VehicleSpeedCondition::VehicleSpeedCondition((VehicleSpeedCondition *)v0);
}

// File Line: 3470
// RVA: 0x3249B0
void __fastcall VehicleCollisionShouldTriggerExplosion::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::VehicleCollisionShouldTriggerExplosion",
         0i64,
         1u);
  if ( v0 )
    VehicleCollisionShouldTriggerExplosion::VehicleCollisionShouldTriggerExplosion((VehicleCollisionShouldTriggerExplosion *)v0);
}

// File Line: 3483
// RVA: 0x325470
void __fastcall VehicleIsRammingCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::VehicleIsRammingCondition", 0i64, 1u);
  if ( v0 )
    VehicleIsRammingCondition::VehicleIsRammingCondition((VehicleIsRammingCondition *)v0);
}

// File Line: 3495
// RVA: 0x27C950
__int64 __fastcall VehicleTrunkTypeCondition::GetClassNameUID(VehicleTrunkTypeCondition *this)
{
  return VehicleTrunkTypeCondition::sClassNameUID;
}

// File Line: 3514
// RVA: 0x27C920
__int64 __fastcall VehicleIsWreckedCondition::GetClassNameUID(VehicleIsWreckedCondition *this)
{
  return VehicleIsWreckedCondition::sClassNameUID;
}

// File Line: 3527
// RVA: 0x3246D0
void __fastcall VehicleAngularSpeedCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::VehicleAngularSpeedCondition",
         0i64,
         1u);
  if ( v0 )
    VehicleAngularSpeedCondition::VehicleAngularSpeedCondition((VehicleAngularSpeedCondition *)v0);
}

// File Line: 3558
// RVA: 0x326110
void __fastcall VehicleVectorCompareCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::VehicleVectorCompareCondition",
         0i64,
         1u);
  if ( v0 )
    VehicleVectorCompareCondition::VehicleVectorCompareCondition((VehicleVectorCompareCondition *)v0);
}

// File Line: 3613
// RVA: 0x324DD0
void __fastcall VehicleDoorAngleCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x28ui64, "MemberMap::VehicleDoorAngleCondition", 0i64, 1u);
  if ( v0 )
    VehicleDoorAngleCondition::VehicleDoorAngleCondition((VehicleDoorAngleCondition *)v0);
}

// File Line: 3644
// RVA: 0x3258F0
VehicleOffGroundCondition *__fastcall VehicleOffGroundCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::VehicleOffGroundCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &VehicleOffGroundCondition::`vftable';
  return (VehicleOffGroundCondition *)v1;
}

// File Line: 3658
// RVA: 0x3260B0
VehicleUntargetableCondition *__fastcall VehicleUntargetableCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::VehicleUntargetableCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &VehicleUntargetableCondition::`vftable';
  return (VehicleUntargetableCondition *)v1;
}

// File Line: 3672
// RVA: 0x2C2D90
const char *__fastcall VehicleInDeepWaterCondition::GetClassname(VehicleInDeepWaterCondition *this)
{
  return VehicleInDeepWaterCondition::sClassName;
}

// File Line: 3686
// RVA: 0x324820
VehicleBurnoutCondition *__fastcall VehicleBurnoutCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::VehicleBurnoutCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &VehicleBurnoutCondition::`vftable';
  return (VehicleBurnoutCondition *)v1;
}

// File Line: 3700
// RVA: 0x3261B0
VehicleWheelieCondition *__fastcall VehicleWheelieCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::VehicleWheelieCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &VehicleWheelieCondition::`vftable';
  return (VehicleWheelieCondition *)v1;
}

// File Line: 3714
// RVA: 0x2C0210
__int64 __fastcall VehicleOneEightyCondition::GetClassNameUID(VehicleOneEightyCondition *this)
{
  return VehicleOneEightyCondition::sClassNameUID;
}

// File Line: 3728
// RVA: 0x2C0090
__int64 __fastcall VehicleHandbrakeCondition::GetClassNameUID(VehicleHandbrakeCondition *this)
{
  return VehicleHandbrakeCondition::sClassNameUID;
}

// File Line: 3743
// RVA: 0x2C01B0
__int64 __fastcall VehicleOccupantHasActiveRoleCondition::GetClassNameUID(VehicleOccupantHasActiveRoleCondition *this)
{
  return VehicleOccupantHasActiveRoleCondition::sClassNameUID;
}

// File Line: 3759
// RVA: 0x2C2E80
const char *__fastcall VehicleOccupantIsPassengerCondition::GetClassname(VehicleOccupantIsPassengerCondition *this)
{
  return VehicleOccupantIsPassengerCondition::sClassName;
}

// File Line: 3775
// RVA: 0x325780
VehicleOccupantIsInBoatCondition *__fastcall VehicleOccupantIsInBoatCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::VehicleOccupantIsInBoatCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &VehicleOccupantIsInBoatCondition::`vftable';
  return (VehicleOccupantIsInBoatCondition *)v1;
}

// File Line: 3790
// RVA: 0x3257E0
VehicleOccupantIsInSinkingBoatCondition *__fastcall VehicleOccupantIsInSinkingBoatCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::VehicleOccupantIsInSinkingBoatCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &VehicleOccupantIsInSinkingBoatCondition::`vftable';
  return (VehicleOccupantIsInSinkingBoatCondition *)v1;
}

// File Line: 3805
// RVA: 0x27D550
const char *__fastcall VehicleOccupantTypeCondition::GetClassname(VehicleOccupantTypeCondition *this)
{
  return VehicleOccupantTypeCondition::sClassName;
}

// File Line: 3829
// RVA: 0x27C2A0
__int64 __fastcall IsOccupantOfTargetVehicleCondition::GetClassNameUID(IsOccupantOfTargetVehicleCondition *this)
{
  return IsOccupantOfTargetVehicleCondition::sClassNameUID;
}

// File Line: 3856
// RVA: 0x27CE30
const char *__fastcall IsBoatInsideWorldCondition::GetClassname(IsBoatInsideWorldCondition *this)
{
  return IsBoatInsideWorldCondition::sClassName;
}

// File Line: 3874
// RVA: 0x2C2EC0
const char *__fastcall VehicleOrientationCondition::GetClassname(VehicleOrientationCondition *this)
{
  return VehicleOrientationCondition::sClassName;
}

// File Line: 3896
// RVA: 0x2C2980
const char *__fastcall TargetVehicleOrientationCondition::GetClassname(TargetVehicleOrientationCondition *this)
{
  return TargetVehicleOrientationCondition::sClassName;
}

// File Line: 3929
// RVA: 0x3238E0
TargetVehicleDoorsLockedCondition *__fastcall TargetVehicleDoorsLockedCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::TargetVehicleDoorsLockedCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &TargetVehicleDoorsLockedCondition::`vftable';
  v1[24] = 28;
  return (TargetVehicleDoorsLockedCondition *)v1;
}

// File Line: 3956
// RVA: 0x326210
VehicleWindowBrokenCondition *__fastcall VehicleWindowBrokenCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::VehicleWindowBrokenCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &VehicleWindowBrokenCondition::`vftable';
  *((_DWORD *)v1 + 6) = 3;
  return (VehicleWindowBrokenCondition *)v1;
}

// File Line: 3985
// RVA: 0x3239D0
TargetVehicleWindowBrokenCondition *__fastcall TargetVehicleWindowBrokenCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::TargetVehicleWindowBrokenCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &TargetVehicleWindowBrokenCondition::`vftable';
  v1[24] = 28;
  *((_DWORD *)v1 + 7) = 3;
  return (TargetVehicleWindowBrokenCondition *)v1;
}

// File Line: 4011
// RVA: 0x3256A0
VehicleNumberOfTiresDamagedCondition *__fastcall VehicleNumberOfTiresDamagedCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::VehicleNumberOfTiresDamagedCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &VehicleNumberOfTiresDamagedCondition::`vftable';
  *((_DWORD *)v1 + 6) = 0;
  v1[28] = 3;
  *((_DWORD *)v1 + 8) = 1;
  v1[36] = 3;
  return (VehicleNumberOfTiresDamagedCondition *)v1;
}

// File Line: 4042
// RVA: 0x2C0070
__int64 __fastcall VehicleEngineRipeForTakedownCondition::GetClassNameUID(VehicleEngineRipeForTakedownCondition *this)
{
  return VehicleEngineRipeForTakedownCondition::sClassNameUID;
}

// File Line: 4059
// RVA: 0x2BFFB0
__int64 __fastcall VehicleDamageCondition::GetClassNameUID(VehicleDamageCondition *this)
{
  return VehicleDamageCondition::sClassNameUID;
}

// File Line: 4088
// RVA: 0x2C00B0
__int64 __fastcall VehicleHasDriverOrPassengerOccupantCondition::GetClassNameUID(VehicleHasDriverOrPassengerOccupantCondition *this)
{
  return VehicleHasDriverOrPassengerOccupantCondition::sClassNameUID;
}

// File Line: 4103
// RVA: 0x2C2C60
const char *__fastcall VehicleDeniesAllyDriverCondition::GetClassname(VehicleDeniesAllyDriverCondition *this)
{
  return VehicleDeniesAllyDriverCondition::sClassName;
}

// File Line: 4126
// RVA: 0x324B30
VehicleDeniesAllyPassengerCondition *__fastcall VehicleDeniesAllyPassengerCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::VehicleDeniesAllyPassengerCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &VehicleDeniesAllyPassengerCondition::`vftable';
  v1[24] = 28;
  return (VehicleDeniesAllyPassengerCondition *)v1;
}

// File Line: 4148
// RVA: 0x2BFFF0
__int64 __fastcall VehicleDeniesGetInPassengerSideCondition::GetClassNameUID(VehicleDeniesGetInPassengerSideCondition *this)
{
  return VehicleDeniesGetInPassengerSideCondition::sClassNameUID;
}

// File Line: 4171
// RVA: 0x2BFFE0
__int64 __fastcall VehicleDeniesGetInDriverSideCondition::GetClassNameUID(VehicleDeniesGetInDriverSideCondition *this)
{
  return VehicleDeniesGetInDriverSideCondition::sClassNameUID;
}

// File Line: 4194
// RVA: 0x324C80
VehicleDeniesHijackCondition *__fastcall VehicleDeniesHijackCondition::Create()
{
  char *v0; // rax
  VehicleDeniesHijackCondition *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::VehicleDeniesHijackCondition",
         0i64,
         1u);
  v1 = (VehicleDeniesHijackCondition *)v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  v1->vfptr = (Expression::IMemberMapVtbl *)&VehicleDeniesHijackCondition::`vftable';
  v1->mTargetType.mValue = eTARGET_TYPE_VEHICLE;
  return v1;
}

// File Line: 4217
// RVA: 0x2C2BE0
const char *__fastcall VehicleAimingShotBlockedCondition::GetClassname(VehicleAimingShotBlockedCondition *this)
{
  return VehicleAimingShotBlockedCondition::sClassName;
}

// File Line: 4240
// RVA: 0x3248F0
Condition *__fastcall VehicleCanActionHijackCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::VehicleCanActionHijackCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &VehicleCanActionHijackCondition::`vftable';
  v1[24] = 44;
  return (Condition *)v1;
}

// File Line: 4263
// RVA: 0x324880
VehicleCanActionHijackClimbCondition *__fastcall VehicleCanActionHijackClimbCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::VehicleCanActionHijackClimbCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &VehicleCanActionHijackClimbCondition::`vftable';
  v1[24] = 44;
  return (VehicleCanActionHijackClimbCondition *)v1;
}

// File Line: 4287
// RVA: 0x27D500
const char *__fastcall VehicleCanOpenDoorCondition::GetClassname(VehicleCanOpenDoorCondition *this)
{
  return VehicleCanOpenDoorCondition::sClassName;
}

// File Line: 4310
// RVA: 0x2C2C00
const char *__fastcall VehicleBoxSideCondition::GetClassname(VehicleBoxSideCondition *this)
{
  return VehicleBoxSideCondition::sClassName;
}

// File Line: 4337
// RVA: 0x2C0020
__int64 __fastcall VehicleDirectlyBehindCondition::GetClassNameUID(VehicleDirectlyBehindCondition *this)
{
  return VehicleDirectlyBehindCondition::sClassNameUID;
}

// File Line: 4368
// RVA: 0x2C11D0
const char *__fastcall DriverProfileTypeCondition::GetClassname(DriverProfileTypeCondition *this)
{
  return DriverProfileTypeCondition::sClassName;
}

// File Line: 4395
// RVA: 0x2BE180
__int64 __fastcall CharacterTypeCondition::GetClassNameUID(CharacterTypeCondition *this)
{
  return CharacterTypeCondition::sClassNameUID;
}

// File Line: 4418
// RVA: 0x2C12D0
const char *__fastcall FightingClassCondition::GetClassname(FightingClassCondition *this)
{
  return FightingClassCondition::sClassName;
}

// File Line: 4532
// RVA: 0x2BF3A0
__int64 __fastcall PropertyBooleanCondition::GetClassNameUID(PropertyBooleanCondition *this)
{
  return PropertyBooleanCondition::sClassNameUID;
}

// File Line: 4548
// RVA: 0x2BFC10
__int64 __fastcall TargetPropertyBooleanCondition::GetClassNameUID(TargetPropertyBooleanCondition *this)
{
  return TargetPropertyBooleanCondition::sClassNameUID;
}

// File Line: 4563
// RVA: 0x31F370
void __fastcall PropertyIntegerCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "MemberMap::PropertyIntegerCondition", 0i64, 1u);
  if ( v0 )
    PropertyIntegerCondition::PropertyIntegerCondition((PropertyIntegerCondition *)v0);
}

// File Line: 4587
// RVA: 0x322FB0
void __fastcall TargetPropertyIntegerCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x58ui64,
         "MemberMap::TargetPropertyIntegerCondition",
         0i64,
         1u);
  if ( v0 )
    TargetPropertyIntegerCondition::TargetPropertyIntegerCondition((TargetPropertyIntegerCondition *)v0);
}

// File Line: 4612
// RVA: 0x31F320
void __fastcall PropertyFloatCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "MemberMap::PropertyFloatCondition", 0i64, 1u);
  if ( v0 )
    PropertyFloatCondition::PropertyFloatCondition((PropertyFloatCondition *)v0);
}

// File Line: 4636
// RVA: 0x27C7A0
__int64 __fastcall TargetPropertyFloatCondition::GetClassNameUID(TargetPropertyFloatCondition *this)
{
  return TargetPropertyFloatCondition::sClassNameUID;
}

// File Line: 4661
// RVA: 0x2BF3B0
__int64 __fastcall PropertySymbolCondition::GetClassNameUID(PropertySymbolCondition *this)
{
  return PropertySymbolCondition::sClassNameUID;
}

// File Line: 4681
// RVA: 0x2BFC20
__int64 __fastcall TargetPropertySymbolCondition::GetClassNameUID(TargetPropertySymbolCondition *this)
{
  return TargetPropertySymbolCondition::sClassNameUID;
}

// File Line: 4707
// RVA: 0x320920
void __fastcall SkookumCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x30ui64, "MemberMap::SkookumCondition", 0i64, 1u);
  if ( v0 )
    SkookumCondition::SkookumCondition((SkookumCondition *)v0);
}

// File Line: 4741
// RVA: 0x27BFE0
__int64 __fastcall FaceActionRequestCondition::GetClassNameUID(FaceActionRequestCondition *this)
{
  return FaceActionRequestCondition::sClassNameUID;
}

// File Line: 4765
// RVA: 0x27BFD0
__int64 __fastcall FaceActionAvailableCondition::GetClassNameUID(FaceActionAvailableCondition *this)
{
  return FaceActionAvailableCondition::sClassNameUID;
}

// File Line: 4789
// RVA: 0x27C000
__int64 __fastcall FaceMeterCondition::GetClassNameUID(FaceMeterCondition *this)
{
  return FaceMeterCondition::sClassNameUID;
}

// File Line: 4815
// RVA: 0x27BFF0
__int64 __fastcall FaceMeterActivatedCondition::GetClassNameUID(FaceMeterActivatedCondition *this)
{
  return FaceMeterActivatedCondition::sClassNameUID;
}

// File Line: 4830
// RVA: 0x27D090
const char *__fastcall PipLevelCondition::GetClassname(PipLevelCondition *this)
{
  return PipLevelCondition::sClassName;
}

// File Line: 4855
// RVA: 0x27CE60
const char *__fastcall IsExcludedFromScoring::GetClassname(IsExcludedFromScoring *this)
{
  return IsExcludedFromScoring::sClassName;
}

// File Line: 4876
// RVA: 0x27C2F0
__int64 __fastcall IsTargetingStandingCondition::GetClassNameUID(IsTargetingStandingCondition *this)
{
  return IsTargetingStandingCondition::sClassNameUID;
}

// File Line: 4900
// RVA: 0x27C250
__int64 __fastcall IsFactionStandingCondition::GetClassNameUID(IsFactionStandingCondition *this)
{
  return IsFactionStandingCondition::sClassNameUID;
}

// File Line: 4925
// RVA: 0x27CF20
const char *__fastcall IsTargetsTargetFactionStandingCondition::GetClassname(IsTargetsTargetFactionStandingCondition *this)
{
  return IsTargetsTargetFactionStandingCondition::sClassName;
}

// File Line: 4956
// RVA: 0x2C2A50
const char *__fastcall TimeWarpCondition::GetClassname(TimeWarpCondition *this)
{
  return TimeWarpCondition::sClassName;
}

// File Line: 4972
// RVA: 0x323840
void __fastcall TargetValidCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::TargetValidCondition", 0i64, 1u);
  if ( v0 )
    TargetValidCondition::TargetValidCondition((TargetValidCondition *)v0);
}

// File Line: 5001
// RVA: 0x27D2C0
const char *__fastcall TargetIsEqualCondition::GetClassname(TargetIsEqualCondition *this)
{
  return TargetIsEqualCondition::sClassName;
}

// File Line: 5029
// RVA: 0x27D2B0
const char *__fastcall TargetInventoryItemCondition::GetClassname(TargetInventoryItemCondition *this)
{
  return TargetInventoryItemCondition::sClassName;
}

// File Line: 5050
// RVA: 0x323430
void __fastcall TargetSimObjectTypeCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::TargetSimObjectTypeCondition",
         0i64,
         1u);
  if ( v0 )
    TargetSimObjectTypeCondition::TargetSimObjectTypeCondition((TargetSimObjectTypeCondition *)v0);
}

// File Line: 5073
// RVA: 0x27C880
__int64 __fastcall TargetSimObjectWeaponTypeCondition::GetClassNameUID(TargetSimObjectWeaponTypeCondition *this)
{
  return TargetSimObjectWeaponTypeCondition::sClassNameUID;
}

// File Line: 5096
// RVA: 0x27D450
const char *__fastcall TargetSimObjectWeaponAmmoInventoryItemCondition::GetClassname(TargetSimObjectWeaponAmmoInventoryItemCondition *this)
{
  return TargetSimObjectWeaponAmmoInventoryItemCondition::sClassName;
}

// File Line: 5118
// RVA: 0x323390
void __fastcall TargetSimObjectBooleanCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::TargetSimObjectBooleanCondition",
         0i64,
         1u);
  if ( v0 )
    TargetSimObjectBooleanCondition::TargetSimObjectBooleanCondition((TargetSimObjectBooleanCondition *)v0);
}

// File Line: 5146
// RVA: 0x323570
void __fastcall TargetSimObjectWeaponBooleanCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::TargetSimObjectWeaponBooleanCondition",
         0i64,
         1u);
  if ( v0 )
    TargetSimObjectWeaponBooleanCondition::TargetSimObjectWeaponBooleanCondition((TargetSimObjectWeaponBooleanCondition *)v0);
}

// File Line: 5174
// RVA: 0x27D440
const char *__fastcall TargetSimObjectWeaponAmmoCondition::GetClassname(TargetSimObjectWeaponAmmoCondition *this)
{
  return TargetSimObjectWeaponAmmoCondition::sClassName;
}

// File Line: 5214
// RVA: 0x27C8A0
__int64 __fastcall TargetWeaponAmmoCompatibleCondition::GetClassNameUID(TargetWeaponAmmoCompatibleCondition *this)
{
  return TargetWeaponAmmoCompatibleCondition::sClassNameUID;
}

// File Line: 5238
// RVA: 0x27D470
const char *__fastcall TargetSimObjectWeaponCanFireCondition::GetClassname(TargetSimObjectWeaponCanFireCondition *this)
{
  return TargetSimObjectWeaponCanFireCondition::sClassName;
}

// File Line: 5258
// RVA: 0x27C870
__int64 __fastcall TargetSimObjectWeaponIsAutomaticCondition::GetClassNameUID(TargetSimObjectWeaponIsAutomaticCondition *this)
{
  return TargetSimObjectWeaponIsAutomaticCondition::sClassNameUID;
}

// File Line: 5277
// RVA: 0x27D480
const char *__fastcall TargetSimObjectWeaponCanReloadCondition::GetClassname(TargetSimObjectWeaponCanReloadCondition *this)
{
  return TargetSimObjectWeaponCanReloadCondition::sClassName;
}

// File Line: 5296
// RVA: 0x27D430
const char *__fastcall TargetSimObjectVehicleTypeCondition::GetClassname(TargetSimObjectVehicleTypeCondition *this)
{
  return TargetSimObjectVehicleTypeCondition::sClassName;
}

// File Line: 5320
// RVA: 0x27C590
__int64 __fastcall SimObjectVehicleTypeCondition::GetClassNameUID(SimObjectVehicleTypeCondition *this)
{
  return SimObjectVehicleTypeCondition::sClassNameUID;
}

// File Line: 5340
// RVA: 0x27D3F0
const char *__fastcall TargetSimObjectBoatTypeCondition::GetClassname(TargetSimObjectBoatTypeCondition *this)
{
  return TargetSimObjectBoatTypeCondition::sClassName;
}

// File Line: 5364
// RVA: 0x27D180
const char *__fastcall SimObjectBoatTypeCondition::GetClassname(SimObjectBoatTypeCondition *this)
{
  return SimObjectBoatTypeCondition::sClassName;
}

// File Line: 5384
// RVA: 0x27D410
const char *__fastcall TargetSimObjectCharacterBooleanCondition::GetClassname(TargetSimObjectCharacterBooleanCondition *this)
{
  return TargetSimObjectCharacterBooleanCondition::sClassName;
}

// File Line: 5411
// RVA: 0x27D190
const char *__fastcall SimObjectCharacterBooleanCondition::GetClassname(SimObjectCharacterBooleanCondition *this)
{
  return SimObjectCharacterBooleanCondition::sClassName;
}

// File Line: 5434
// RVA: 0x27C3D0
__int64 __fastcall NumCharactersDeadCondition::GetClassNameUID(NumCharactersDeadCondition *this)
{
  return NumCharactersDeadCondition::sClassNameUID;
}

// File Line: 5452
// RVA: 0x3171F0
void __fastcall CharacterIsAliveCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::CharacterIsAliveCondition", 0i64, 1u);
  if ( v0 )
    CharacterIsAliveCondition::CharacterIsAliveCondition((CharacterIsAliveCondition *)v0);
}

// File Line: 5473
// RVA: 0x31AC20
void __fastcall IncomingAttackPhaseCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::IncomingAttackPhaseCondition",
         0i64,
         1u);
  if ( v0 )
    IncomingAttackPhaseCondition::IncomingAttackPhaseCondition((IncomingAttackPhaseCondition *)v0);
}

// File Line: 5496
// RVA: 0x27CD90
const char *__fastcall IncomingAttackTypeCondition::GetClassname(IncomingAttackTypeCondition *this)
{
  return IncomingAttackTypeCondition::sClassName;
}

// File Line: 5519
// RVA: 0x27C150
__int64 __fastcall IncomingAttackLocationLateralCondition::GetClassNameUID(IncomingAttackLocationLateralCondition *this)
{
  return IncomingAttackLocationLateralCondition::sClassNameUID;
}

// File Line: 5542
// RVA: 0x31AB80
void __fastcall IncomingAttackLocationHorizontalCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::IncomingAttackLocationHorizontalCondition",
         0i64,
         1u);
  if ( v0 )
    IncomingAttackLocationHorizontalCondition::IncomingAttackLocationHorizontalCondition((IncomingAttackLocationHorizontalCondition *)v0);
}

// File Line: 5661
// RVA: 0x31EED0
void __fastcall PlayerMeleeUpgradeCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::PlayerMeleeUpgradeCondition", 0i64, 1u);
  if ( v0 )
    PlayerMeleeUpgradeCondition::PlayerMeleeUpgradeCondition((PlayerMeleeUpgradeCondition *)v0);
}

// File Line: 5687
// RVA: 0x27D0B0
const char *__fastcall PlayerGunplayUpgradeCondition::GetClassname(PlayerGunplayUpgradeCondition *this)
{
  return PlayerGunplayUpgradeCondition::sClassName;
}

// File Line: 5708
// RVA: 0x27D0A0
const char *__fastcall PlayerCopUpgradeCondition::GetClassname(PlayerCopUpgradeCondition *this)
{
  return PlayerCopUpgradeCondition::sClassName;
}

// File Line: 5734
// RVA: 0x31EF20
void __fastcall PlayerTriadUpgradeCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::PlayerTriadUpgradeCondition", 0i64, 1u);
  if ( v0 )
    PlayerTriadUpgradeCondition::PlayerTriadUpgradeCondition((PlayerTriadUpgradeCondition *)v0);
}

// File Line: 5763
// RVA: 0x27C640
__int64 __fastcall StruggleCondition::GetClassNameUID(StruggleCondition *this)
{
  return StruggleCondition::sClassNameUID;
}

// File Line: 5805
// RVA: 0x31AD10
void __fastcall InputSignalCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::InputSignalCondition", 0i64, 1u);
  if ( v0 )
    InputSignalCondition::InputSignalCondition((InputSignalCondition *)v0);
}

// File Line: 5836
// RVA: 0x3263C0
WantToUsePOICondition *__fastcall WantToUsePOICondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::WantToUsePOICondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &WantToUsePOICondition::`vftable';
  return (WantToUsePOICondition *)v1;
}

// File Line: 5847
// RVA: 0x2BF0A0
__int64 __fastcall POIParentObjectHasOwner::GetClassNameUID(POIParentObjectHasOwner *this)
{
  return POIParentObjectHasOwner::sClassNameUID;
}

// File Line: 5858
// RVA: 0x31E0C0
POIWeatherFilterOnWithIsRainingCondition *__fastcall POIWeatherFilterOnWithIsRainingCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::POIWeatherFilterOnWithIsRainingCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &POIWeatherFilterOnWithIsRainingCondition::`vftable';
  return (POIWeatherFilterOnWithIsRainingCondition *)v1;
}

// File Line: 5869
// RVA: 0x2C1D10
const char *__fastcall POIIgnoreStimuliCondition::GetClassname(POIIgnoreStimuliCondition *this)
{
  return POIIgnoreStimuliCondition::sClassName;
}

// File Line: 5882
// RVA: 0x2BF080
__int64 __fastcall POIIsTimingOut::GetClassNameUID(POIIsTimingOut *this)
{
  return POIIsTimingOut::sClassNameUID;
}

// File Line: 5892
// RVA: 0x31EA20
void __fastcall PlayerHeatLevelCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::PlayerHeatLevelCondition", 0i64, 1u);
  if ( v0 )
    PlayerHeatLevelCondition::PlayerHeatLevelCondition((PlayerHeatLevelCondition *)v0);
}

// File Line: 5914
// RVA: 0x27C4B0
__int64 __fastcall PlayerHeatLevelTimerCondition::GetClassNameUID(PlayerHeatLevelTimerCondition *this)
{
  return PlayerHeatLevelTimerCondition::sClassNameUID;
}

// File Line: 5936
// RVA: 0x27CC90
const char *__fastcall HasAIAttackerCondition::GetClassname(HasAIAttackerCondition *this)
{
  return HasAIAttackerCondition::sClassName;
}

// File Line: 5954
// RVA: 0x27CFE0
const char *__fastcall NumAIAttackersCondition::GetClassname(NumAIAttackersCondition *this)
{
  return NumAIAttackersCondition::sClassName;
}

// File Line: 5987
// RVA: 0x27C4C0
__int64 __fastcall PlayerIsInCombatCondition::GetClassNameUID(PlayerIsInCombatCondition *this)
{
  return PlayerIsInCombatCondition::sClassNameUID;
}

// File Line: 6004
// RVA: 0x27C4D0
__int64 __fastcall PlayerIsInCombatConditionTU::GetClassNameUID(PlayerIsInCombatConditionTU *this)
{
  return PlayerIsInCombatConditionTU::sClassNameUID;
}

// File Line: 6026
// RVA: 0x27C310
__int64 __fastcall IsTiredCondition::GetClassNameUID(IsTiredCondition *this)
{
  return IsTiredCondition::sClassNameUID;
}

// File Line: 6037
// RVA: 0x27C4E0
__int64 __fastcall PlayerIsInCombatWithNumEnemiesCondition::GetClassNameUID(PlayerIsInCombatWithNumEnemiesCondition *this)
{
  return PlayerIsInCombatWithNumEnemiesCondition::sClassNameUID;
}

// File Line: 6067
// RVA: 0x2C17A0
const char *__fastcall IsMultiplayerActiveCondition::GetClassname(IsMultiplayerActiveCondition *this)
{
  return IsMultiplayerActiveCondition::sClassName;
}

// File Line: 6082
// RVA: 0x2BE150
__int64 __fastcall CharacterStatIntCondition::GetClassNameUID(CharacterStatIntCondition *this)
{
  return CharacterStatIntCondition::sClassNameUID;
}

// File Line: 6113
// RVA: 0x2BEC00
__int64 __fastcall IsPlayingDialogueCondition::GetClassNameUID(IsPlayingDialogueCondition *this)
{
  return IsPlayingDialogueCondition::sClassNameUID;
}

// File Line: 6130
// RVA: 0x27BF60
__int64 __fastcall CoverIsInCoverZoneCondition::GetClassNameUID(CoverIsInCoverZoneCondition *this)
{
  return CoverIsInCoverZoneCondition::sClassNameUID;
}

// File Line: 6147
// RVA: 0x318070
void __fastcall CoverPositionsEquivalentCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::CoverPositionsEquivalentCondition",
         0i64,
         1u);
  if ( v0 )
    CoverPositionsEquivalentCondition::CoverPositionsEquivalentCondition((CoverPositionsEquivalentCondition *)v0);
}

// File Line: 6174
// RVA: 0x27CBA0
const char *__fastcall CoverProbeForCoverZoneCondition::GetClassname(CoverProbeForCoverZoneCondition *this)
{
  return CoverProbeForCoverZoneCondition::sClassName;
}

// File Line: 6248
// RVA: 0x317F30
void __fastcall CoverDirectionCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x28ui64, "MemberMap::CoverDirectionCondition", 0i64, 1u);
  if ( v0 )
    CoverDirectionCondition::CoverDirectionCondition((CoverDirectionCondition *)v0);
}

// File Line: 6299
// RVA: 0x27CB70
const char *__fastcall CoverHeightCondition::GetClassname(CoverHeightCondition *this)
{
  return CoverHeightCondition::sClassName;
}

// File Line: 6328
// RVA: 0x318250
void __fastcall CoverTypeCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::CoverTypeCondition", 0i64, 1u);
  if ( v0 )
    CoverTypeCondition::CoverTypeCondition((CoverTypeCondition *)v0);
}

// File Line: 6363
// RVA: 0x317EE0
void __fastcall CoverCanTraverseInDirectionCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::CoverCanTraverseInDirectionCondition",
         0i64,
         1u);
  if ( v0 )
    CoverCanTraverseInDirectionCondition::CoverCanTraverseInDirectionCondition((CoverCanTraverseInDirectionCondition *)v0);
}

// File Line: 6389
// RVA: 0x27D5A0
const char *__fastcall WaterDepth::GetClassname(WaterDepth *this)
{
  return WaterDepth::sClassName;
}

// File Line: 6420
// RVA: 0x2C29F0
const char *__fastcall TargetedByTypeCondition::GetClassname(TargetedByTypeCondition *this)
{
  return TargetedByTypeCondition::sClassName;
}

// File Line: 6448
// RVA: 0x31C710
IsTargetsTargetCondition *__fastcall IsTargetsTargetCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::IsTargetsTargetCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &IsTargetsTargetCondition::`vftable';
  *((_WORD *)v1 + 12) = 0;
  return (IsTargetsTargetCondition *)v1;
}

// File Line: 6474
// RVA: 0x31B230
InventoryCheckPropertyCondition *__fastcall InventoryCheckPropertyCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::InventoryCheckPropertyCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &InventoryCheckPropertyCondition::`vftable';
  *((_WORD *)v1 + 12) = 0;
  return (InventoryCheckPropertyCondition *)v1;
}

// File Line: 6501
// RVA: 0x2BFAB0
__int64 __fastcall TargetInventoryCheckPropertyCondition::GetClassNameUID(TargetInventoryCheckPropertyCondition *this)
{
  return TargetInventoryCheckPropertyCondition::sClassNameUID;
}

// File Line: 6528
// RVA: 0x2BF760
__int64 __fastcall SocialABKsLoadedCondition::GetClassNameUID(SocialABKsLoadedCondition *this)
{
  return SocialABKsLoadedCondition::sClassNameUID;
}

// File Line: 6548
// RVA: 0x2C24C0
const char *__fastcall SocialSetEvaluatedCondition::GetClassname(SocialSetEvaluatedCondition *this)
{
  return SocialSetEvaluatedCondition::sClassName;
}

// File Line: 6569
// RVA: 0x316240
CanWanderCondition *__fastcall CanWanderCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::CanWanderCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &CanWanderCondition::`vftable';
  return (CanWanderCondition *)v1;
}

// File Line: 6590
// RVA: 0x2C28D0
const char *__fastcall TargetPurchaseItemFailCondition::GetClassname(TargetPurchaseItemFailCondition *this)
{
  return TargetPurchaseItemFailCondition::sClassName;
}

// File Line: 6614
// RVA: 0x27C630
__int64 __fastcall StateFlagCondition::GetClassNameUID(StateFlagCondition *this)
{
  return StateFlagCondition::sClassNameUID;
}

// File Line: 6636
// RVA: 0x27C580
__int64 __fastcall SimObjectFlagCondition::GetClassNameUID(SimObjectFlagCondition *this)
{
  return SimObjectFlagCondition::sClassNameUID;
}

// File Line: 6658
// RVA: 0x2BEC60
__int64 __fastcall IsRainingCondition::GetClassNameUID(IsRainingCondition *this)
{
  return IsRainingCondition::sClassNameUID;
}

// File Line: 6673
// RVA: 0x2BEAE0
__int64 __fastcall IsIndoorsCondition::GetClassNameUID(IsIndoorsCondition *this)
{
  return IsIndoorsCondition::sClassNameUID;
}

// File Line: 6698
// RVA: 0x31ED40
void __fastcall PlayerIsInSpecificInterior::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::PlayerIsInSpecificInterior", 0i64, 1u);
  if ( v0 )
    PlayerIsInSpecificInterior::PlayerIsInSpecificInterior((PlayerIsInSpecificInterior *)v0);
}

// File Line: 6719
// RVA: 0x2BEA90
__int64 __fastcall IsCriticalPriorityCondition::GetClassNameUID(IsCriticalPriorityCondition *this)
{
  return IsCriticalPriorityCondition::sClassNameUID;
}

// File Line: 6733
// RVA: 0x2C1920
const char *__fastcall IsSpawningCondition::GetClassname(IsSpawningCondition *this)
{
  return IsSpawningCondition::sClassName;
}

// File Line: 6746
// RVA: 0x2C1910
const char *__fastcall IsSkippingIntoPOICondition::GetClassname(IsSkippingIntoPOICondition *this)
{
  return IsSkippingIntoPOICondition::sClassName;
}

// File Line: 6759
// RVA: 0x314840
Condition *__fastcall ActionDefLeanBackCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::ActionDefLeanBackCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &ActionDefLeanBackCondition::`vftable';
  return (Condition *)v1;
}

// File Line: 6773
// RVA: 0x27C290
__int64 __fastcall IsLockboxContainingCondition::GetClassNameUID(IsLockboxContainingCondition *this)
{
  return IsLockboxContainingCondition::sClassNameUID;
}

// File Line: 6792
// RVA: 0x27C270
__int64 __fastcall IsGroupLeaderCondition::GetClassNameUID(IsGroupLeaderCondition *this)
{
  return IsGroupLeaderCondition::sClassNameUID;
}

// File Line: 6804
// RVA: 0x3222F0
void __fastcall TargetIsGroupLeaderCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::TargetIsGroupLeaderCondition",
         0i64,
         1u);
  if ( v0 )
    TargetIsGroupLeaderCondition::TargetIsGroupLeaderCondition((TargetIsGroupLeaderCondition *)v0);
}

// File Line: 6822
// RVA: 0x31B850
void __fastcall IsGroupFollowerCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::IsGroupFollowerCondition", 0i64, 1u);
  if ( v0 )
    IsGroupFollowerCondition::IsGroupFollowerCondition((IsGroupFollowerCondition *)v0);
}

// File Line: 6834
// RVA: 0x3222A0
void __fastcall TargetIsGroupFollowerCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::TargetIsGroupFollowerCondition",
         0i64,
         1u);
  if ( v0 )
    TargetIsGroupFollowerCondition::TargetIsGroupFollowerCondition((TargetIsGroupFollowerCondition *)v0);
}

// File Line: 6852
// RVA: 0x27CEA0
const char *__fastcall IsGroupMemberCondition::GetClassname(IsGroupMemberCondition *this)
{
  return IsGroupMemberCondition::sClassName;
}

// File Line: 6864
// RVA: 0x27D300
const char *__fastcall TargetIsGroupMemberCondition::GetClassname(TargetIsGroupMemberCondition *this)
{
  return TargetIsGroupMemberCondition::sClassName;
}

// File Line: 6882
// RVA: 0x27C6F0
__int64 __fastcall TargetIsInMyGroupCondition::GetClassNameUID(TargetIsInMyGroupCondition *this)
{
  return TargetIsInMyGroupCondition::sClassNameUID;
}

// File Line: 6900
// RVA: 0x27C3F0
__int64 __fastcall NumGroupMemberAliveCondition::GetClassNameUID(NumGroupMemberAliveCondition *this)
{
  return NumGroupMemberAliveCondition::sClassNameUID;
}

// File Line: 6925
// RVA: 0x31BF60
IsPlayerInBerserkModeCondition *__fastcall IsPlayerInBerserkModeCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::IsPlayerInBerserkModeCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &IsPlayerInBerserkModeCondition::`vftable';
  return (IsPlayerInBerserkModeCondition *)v1;
}

// File Line: 6940
// RVA: 0x31C020
IsPlayerInCombatBuffModeCondition *__fastcall IsPlayerInCombatBuffModeCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::IsPlayerInCombatBuffModeCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &IsPlayerInCombatBuffModeCondition::`vftable';
  return (IsPlayerInCombatBuffModeCondition *)v1;
}

// File Line: 6956
// RVA: 0x31A9E0
HitRecordProcessingCondition *__fastcall HitRecordProcessingCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::HitRecordProcessingCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &HitRecordProcessingCondition::`vftable';
  return (HitRecordProcessingCondition *)v1;
}

// File Line: 6974
// RVA: 0x31A980
HitRecordBerserkAttackFlagCondition *__fastcall HitRecordBerserkAttackFlagCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::HitRecordBerserkAttackFlagCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &HitRecordBerserkAttackFlagCondition::`vftable';
  return (HitRecordBerserkAttackFlagCondition *)v1;
}

// File Line: 6989
// RVA: 0x2C2B00
const char *__fastcall UICameraOverlayExistsCondition::GetClassname(UICameraOverlayExistsCondition *this)
{
  return UICameraOverlayExistsCondition::sClassName;
}

// File Line: 7016
// RVA: 0x31FD60
ResourceIsAvailableCondition *__fastcall ResourceIsAvailableCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::ResourceIsAvailableCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &ResourceIsAvailableCondition::`vftable';
  *((_QWORD *)v1 + 3) = 1i64;
  BinString::Set((BinString *)v1 + 3, &customWorldMapCaption);
  *((_WORD *)v1 + 16) = 0;
  v1[34] = 0;
  return (ResourceIsAvailableCondition *)v1;
}

// File Line: 7043
// RVA: 0x2BEF90
__int64 __fastcall ObjectIsAvailableCondition::GetClassNameUID(ObjectIsAvailableCondition *this)
{
  return ObjectIsAvailableCondition::sClassNameUID;
}

// File Line: 7068
// RVA: 0x2C2060
const char *__fastcall PurchasableItemAvailableCondition::GetClassname(PurchasableItemAvailableCondition *this)
{
  return PurchasableItemAvailableCondition::sClassName;
}

// File Line: 7081
// RVA: 0x2BEA80
__int64 __fastcall IsCopCondition::GetClassNameUID(IsCopCondition *this)
{
  return IsCopCondition::sClassNameUID;
}

// File Line: 7094
// RVA: 0x31B480
IsCameraCollidingCondition *__fastcall IsCameraCollidingCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::IsCameraCollidingCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &IsCameraCollidingCondition::`vftable';
  return (IsCameraCollidingCondition *)v1;
}

// File Line: 7106
// RVA: 0x27C220
__int64 __fastcall IsCameraTypeCondition::GetClassNameUID(IsCameraTypeCondition *this)
{
  return IsCameraTypeCondition::sClassNameUID;
}

// File Line: 7121
// RVA: 0x31B530
void __fastcall IsClassTypeCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::IsClassTypeCondition", 0i64, 1u);
  if ( v0 )
    IsClassTypeCondition::IsClassTypeCondition((IsClassTypeCondition *)v0);
}

// File Line: 7169
// RVA: 0x27C190
__int64 __fastcall InteractionPointFindBestCondition::GetClassNameUID(InteractionPointFindBestCondition *this)
{
  return InteractionPointFindBestCondition::sClassNameUID;
}

// File Line: 7206
// RVA: 0x31B140
void __fastcall InteractionPointValidCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::InteractionPointValidCondition",
         0i64,
         1u);
  if ( v0 )
    InteractionPointValidCondition::InteractionPointValidCondition((InteractionPointValidCondition *)v0);
}

// File Line: 7232
// RVA: 0x31B000
void __fastcall InteractionPointIsAccessable::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::InteractionPointIsAccessable",
         0i64,
         1u);
  if ( v0 )
    InteractionPointIsAccessable::InteractionPointIsAccessable((InteractionPointIsAccessable *)v0);
}

// File Line: 7255
// RVA: 0x27CDE0
const char *__fastcall InteractionPointIsBestOfTypeCondition::GetClassname(InteractionPointIsBestOfTypeCondition *this)
{
  return InteractionPointIsBestOfTypeCondition::sClassName;
}

// File Line: 7275
// RVA: 0x31B050
void __fastcall InteractionPointIsBestBusyCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::InteractionPointIsBestBusyCondition",
         0i64,
         1u);
  if ( v0 )
    InteractionPointIsBestBusyCondition::InteractionPointIsBestBusyCondition((InteractionPointIsBestBusyCondition *)v0);
}

// File Line: 7291
// RVA: 0x27C130
__int64 __fastcall IfTargetsInteractionPointNotBusySetBestCondition::GetClassNameUID(IfTargetsInteractionPointNotBusySetBestCondition *this)
{
  return IfTargetsInteractionPointNotBusySetBestCondition::sClassNameUID;
}

// File Line: 7322
// RVA: 0x2C2A20
const char *__fastcall TimeOfDayCondition::GetClassname(TimeOfDayCondition *this)
{
  return TimeOfDayCondition::sClassName;
}

// File Line: 7350
// RVA: 0x27CAB0
const char *__fastcall CharacterPhysicsCondition::GetClassname(CharacterPhysicsCondition *this)
{
  return CharacterPhysicsCondition::sClassName;
}

// File Line: 7374
// RVA: 0x27C5F0
__int64 __fastcall SocialGreetSuccessfulCondition::GetClassNameUID(SocialGreetSuccessfulCondition *this)
{
  return SocialGreetSuccessfulCondition::sClassNameUID;
}

// File Line: 7391
// RVA: 0x2C24A0
const char *__fastcall SocialRequiresInteractionPointSyncCondition::GetClassname(SocialRequiresInteractionPointSyncCondition *this)
{
  return SocialRequiresInteractionPointSyncCondition::sClassName;
}

// File Line: 7408
// RVA: 0x320FA0
SocialRequiresInteractionAreaCheckCondition *__fastcall SocialRequiresInteractionAreaCheckCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::SocialRequiresInteractionAreaCheckCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &SocialRequiresInteractionAreaCheckCondition::`vftable';
  return (SocialRequiresInteractionAreaCheckCondition *)v1;
}

// File Line: 7425
// RVA: 0x320AA0
void __fastcall SocialChargeSuccessfulCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::SocialChargeSuccessfulCondition",
         0i64,
         1u);
  if ( v0 )
    SocialChargeSuccessfulCondition::SocialChargeSuccessfulCondition((SocialChargeSuccessfulCondition *)v0);
}

// File Line: 7442
// RVA: 0x27D220
const char *__fastcall SocialRequiresFastTalkCondition::GetClassname(SocialRequiresFastTalkCondition *this)
{
  return SocialRequiresFastTalkCondition::sClassName;
}

// File Line: 7459
// RVA: 0x27D200
const char *__fastcall SocialFastTalkOccurredCondition::GetClassname(SocialFastTalkOccurredCondition *this)
{
  return SocialFastTalkOccurredCondition::sClassName;
}

// File Line: 7493
// RVA: 0x27C5C0
__int64 __fastcall SocialCombatFastTalkSucceededCondition::GetClassNameUID(SocialCombatFastTalkSucceededCondition *this)
{
  return SocialCombatFastTalkSucceededCondition::sClassNameUID;
}

// File Line: 7510
// RVA: 0x27C050
__int64 __fastcall GameSliceIsActiveCondition::GetClassNameUID(GameSliceIsActiveCondition *this)
{
  return GameSliceIsActiveCondition::sClassNameUID;
}

// File Line: 7533
// RVA: 0x31C960
void __fastcall LastCompletedMissionCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::LastCompletedMissionCondition",
         0i64,
         1u);
  if ( v0 )
    LastCompletedMissionCondition::LastCompletedMissionCondition((LastCompletedMissionCondition *)v0);
}

// File Line: 7556
// RVA: 0x27D4E0
const char *__fastcall UIPDAStateCondition::GetClassname(UIPDAStateCondition *this)
{
  return UIPDAStateCondition::sClassName;
}

// File Line: 7579
// RVA: 0x324140
UIPDAIsActiveCondition *__fastcall UIPDAIsActiveCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::UIPDAIsActiveCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &UIPDAIsActiveCondition::`vftable';
  return (UIPDAIsActiveCondition *)v1;
}

// File Line: 7597
// RVA: 0x31C080
void __fastcall IsPlayerUsingKeyboardCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::IsPlayerUsingKeyboardCondition",
         0i64,
         1u);
  if ( v0 )
    IsPlayerUsingKeyboardCondition::IsPlayerUsingKeyboardCondition((IsPlayerUsingKeyboardCondition *)v0);
}

// File Line: 7612
// RVA: 0x27CAE0
const char *__fastcall CollectibleIsCollectedCondition::GetClassname(CollectibleIsCollectedCondition *this)
{
  return CollectibleIsCollectedCondition::sClassName;
}

// File Line: 7635
// RVA: 0x27CCA0
const char *__fastcall HasClothingBuffCondition::GetClassname(HasClothingBuffCondition *this)
{
  return HasClothingBuffCondition::sClassName;
}

// File Line: 7658
// RVA: 0x317E90
void __fastcall CouldShootSomeoneUnintendedCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::CouldShootSomeoneUnintendedCondition",
         0i64,
         1u);
  if ( v0 )
    CouldShootSomeoneUnintendedCondition::CouldShootSomeoneUnintendedCondition((CouldShootSomeoneUnintendedCondition *)v0);
}

// File Line: 7684
// RVA: 0x27CF00
const char *__fastcall IsSocialConversationActiveCondition::GetClassname(IsSocialConversationActiveCondition *this)
{
  return IsSocialConversationActiveCondition::sClassName;
}

// File Line: 7704
// RVA: 0x320B40
void __fastcall SocialConversationHasActionRequestsCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::SocialConversationHasActionRequestsCondition",
         0i64,
         1u);
  if ( v0 )
    SocialConversationHasActionRequestsCondition::SocialConversationHasActionRequestsCondition((SocialConversationHasActionRequestsCondition *)v0);
}

// File Line: 7727
// RVA: 0x2BF7C0
__int64 __fastcall SocialFaceActionStateCondition::GetClassNameUID(SocialFaceActionStateCondition *this)
{
  return SocialFaceActionStateCondition::sClassNameUID;
}

// File Line: 7748
// RVA: 0x2C2470
const char *__fastcall SocialFaceActionUseConfirmationDialogCondition::GetClassname(SocialFaceActionUseConfirmationDialogCondition *this)
{
  return SocialFaceActionUseConfirmationDialogCondition::sClassName;
}

// File Line: 7765
// RVA: 0x320CC0
SocialFaceActionGetConfirmationDialogConfirmedCondition *__fastcall SocialFaceActionGetConfirmationDialogConfirmedCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::SocialFaceActionGetConfirmationDialogConfirmedCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &SocialFaceActionGetConfirmationDialogConfirmedCondition::`vftable';
  return (SocialFaceActionGetConfirmationDialogConfirmedCondition *)v1;
}

// File Line: 7782
// RVA: 0x2BF7B0
__int64 __fastcall SocialFaceActionRequiresGreetCondition::GetClassNameUID(SocialFaceActionRequiresGreetCondition *this)
{
  return SocialFaceActionRequiresGreetCondition::sClassNameUID;
}

// File Line: 7799
// RVA: 0x2C2410
const char *__fastcall SocialFaceActionAutoChargeCondition::GetClassname(SocialFaceActionAutoChargeCondition *this)
{
  return SocialFaceActionAutoChargeCondition::sClassName;
}

// File Line: 7816
// RVA: 0x2C2480
const char *__fastcall SocialIsTargetStandingSufficientCondition::GetClassname(SocialIsTargetStandingSufficientCondition *this)
{
  return SocialIsTargetStandingSufficientCondition::sClassName;
}

// File Line: 7833
// RVA: 0x2BE5F0
__int64 __fastcall FactionClassCondition::GetClassNameUID(FactionClassCondition *this)
{
  return FactionClassCondition::sClassNameUID;
}

// File Line: 7855
// RVA: 0x320C60
SocialFaceActionEnabledCondition *__fastcall SocialFaceActionEnabledCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::SocialFaceActionEnabledCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &SocialFaceActionEnabledCondition::`vftable';
  return (SocialFaceActionEnabledCondition *)v1;
}

// File Line: 7871
// RVA: 0x2C2B40
const char *__fastcall UISocialChargeHappenedCondition::GetClassname(UISocialChargeHappenedCondition *this)
{
  return UISocialChargeHappenedCondition::sClassName;
}

// File Line: 7885
// RVA: 0x2BEB90
__int64 __fastcall IsOnFireCondition::GetClassNameUID(IsOnFireCondition *this)
{
  return IsOnFireCondition::sClassNameUID;
}

// File Line: 7903
// RVA: 0x2BFAF0
__int64 __fastcall TargetIsSittingConversationCondition::GetClassNameUID(TargetIsSittingConversationCondition *this)
{
  return TargetIsSittingConversationCondition::sClassNameUID;
}

// File Line: 7941
// RVA: 0x2C1740
const char *__fastcall IsDLCMoveUnlockedCondition::GetClassname(IsDLCMoveUnlockedCondition *this)
{
  return IsDLCMoveUnlockedCondition::sClassName;
}

// File Line: 7961
// RVA: 0x31C430
IsPossessedPedModeEnabledCondition *__fastcall IsPossessedPedModeEnabledCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::IsPossessedPedModeEnabledCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &IsPossessedPedModeEnabledCondition::`vftable';
  return (IsPossessedPedModeEnabledCondition *)v1;
}

// File Line: 7980
// RVA: 0x2BDB40
__int64 __fastcall AmIPossessedCondition::GetClassNameUID(AmIPossessedCondition *this)
{
  return AmIPossessedCondition::sClassNameUID;
}

// File Line: 7999
// RVA: 0x2C1810
const char *__fastcall IsNavigationControlledCondition::GetClassname(IsNavigationControlledCondition *this)
{
  return IsNavigationControlledCondition::sClassName;
}

// File Line: 8015
// RVA: 0x27C3E0
__int64 __fastcall NumCollectiblesCollectedCondition::GetClassNameUID(NumCollectiblesCollectedCondition *this)
{
  return NumCollectiblesCollectedCondition::sClassNameUID;
}

// File Line: 8049
// RVA: 0x27D270
const char *__fastcall TargetAimingDirectionCondition::GetClassname(TargetAimingDirectionCondition *this)
{
  return TargetAimingDirectionCondition::sClassName;
}

