// File Line: 40
// RVA: 0x31E580
void __fastcall PerformScriptCommandTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::PerformScriptCommandTrack", 0i64, 1u);
  if ( v0 )
    PerformScriptCommandTrack::PerformScriptCommandTrack((PerformScriptCommandTrack *)v0);
}

// File Line: 57
// RVA: 0x2C03A0
__int64 __fastcall WanderTrack::GetClassNameUID(WanderTrack *this)
{
  return WanderTrack::sClassNameUID;
}

// File Line: 89
// RVA: 0x3196D0
void __fastcall FleeTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x60ui64, "MemberMap::FleeTrack", 0i64, 1u);
  if ( v0 )
    FleeTrack::FleeTrack((FleeTrack *)v0);
}

// File Line: 134
// RVA: 0x319E70
void __fastcall HangOutTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::HangOutTrack", 0i64, 1u);
  if ( v0 )
    HangOutTrack::HangOutTrack((HangOutTrack *)v0);
}

// File Line: 151
// RVA: 0x2BE960
__int64 __fastcall IdleTrack::GetClassNameUID(IdleTrack *this)
{
  return IdleTrack::sClassNameUID;
}

// File Line: 168
// RVA: 0x2C1280
const char *__fastcall FacialRequestTrack::GetClassname(FacialRequestTrack *this)
{
  return FacialRequestTrack::sClassName;
}

// File Line: 200
// RVA: 0x2C06E0
const char *__fastcall ActionRequestTrack::GetClassname(ActionRequestTrack *this)
{
  return ActionRequestTrack::sClassName;
}

// File Line: 233
// RVA: 0x2C06D0
const char *__fastcall ActionRequestClearTrack::GetClassname(ActionRequestClearTrack *this)
{
  return ActionRequestClearTrack::sClassName;
}

// File Line: 255
// RVA: 0x2C2BC0
const char *__fastcall UsePOITrack::GetClassname(UsePOITrack *this)
{
  return UsePOITrack::sClassName;
}

// File Line: 275
// RVA: 0x2C1CD0
const char *__fastcall POIBeginTrack::GetClassname(POIBeginTrack *this)
{
  return POIBeginTrack::sClassName;
}

// File Line: 291
// RVA: 0x3144D0
void __fastcall AIObjectiveTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::AIObjectiveTrack", 0i64, 1u);
  if ( v0 )
    AIObjectiveTrack::AIObjectiveTrack((AIObjectiveTrack *)v0);
}

// File Line: 323
// RVA: 0x2BDA20
__int64 __fastcall ActionRequestAndWaitUntilPlayingTrack::GetClassNameUID(ActionRequestAndWaitUntilPlayingTrack *this)
{
  return ActionRequestAndWaitUntilPlayingTrack::sClassNameUID;
}

// File Line: 359
// RVA: 0x31D6C0
void __fastcall NodeRequestTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::NodeRequestTrack", 0i64, 1u);
  if ( v0 )
    NodeRequestTrack::NodeRequestTrack((NodeRequestTrack *)v0);
}

// File Line: 384
// RVA: 0x31D5D0
void __fastcall NodeRequestAndWaitUntilPlayingTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x48ui64,
         "MemberMap::NodeRequestAndWaitUntilPlayingTrack",
         0i64,
         1u);
  if ( v0 )
    NodeRequestAndWaitUntilPlayingTrack::NodeRequestAndWaitUntilPlayingTrack((NodeRequestAndWaitUntilPlayingTrack *)v0);
}

// File Line: 420
// RVA: 0x2BF680
__int64 __fastcall SetCurrentEmotionTrack::GetClassNameUID(SetCurrentEmotionTrack *this)
{
  return SetCurrentEmotionTrack::sClassNameUID;
}

// File Line: 442
// RVA: 0x2BF6B0
__int64 __fastcall SetFacialEmotionTrack::GetClassNameUID(SetFacialEmotionTrack *this)
{
  return SetFacialEmotionTrack::sClassNameUID;
}

// File Line: 464
// RVA: 0x323FF0
void __fastcall TurnToFaceTargetTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::TurnToFaceTargetTrack", 0i64, 1u);
  if ( v0 )
    TurnToFaceTargetTrack::TurnToFaceTargetTrack((TurnToFaceTargetTrack *)v0);
}

// File Line: 490
// RVA: 0x31A350
void __fastcall HeadTrackTargetTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::HeadTrackTargetTrack", 0i64, 1u);
  if ( v0 )
    HeadTrackTargetTrack::HeadTrackTargetTrack((HeadTrackTargetTrack *)v0);
}

// File Line: 524
// RVA: 0x2BEDB0
__int64 __fastcall MinimumDurationTrack::GetClassNameUID(MinimumDurationTrack *this)
{
  return MinimumDurationTrack::sClassNameUID;
}

// File Line: 547
// RVA: 0x2BE360
__int64 __fastcall DebugDrawMyPositionTrack::GetClassNameUID(DebugDrawMyPositionTrack *this)
{
  return DebugDrawMyPositionTrack::sClassNameUID;
}

// File Line: 580
// RVA: 0x2C1010
const char *__fastcall DebugDrawMyTargetTrack::GetClassname(DebugDrawMyTargetTrack *this)
{
  return DebugDrawMyTargetTrack::sClassName;
}

// File Line: 618
// RVA: 0x2BF5E0
__int64 __fastcall RunLaterallyFromTargetTrack::GetClassNameUID(RunLaterallyFromTargetTrack *this)
{
  return RunLaterallyFromTargetTrack::sClassNameUID;
}

// File Line: 677
// RVA: 0x2BE1D0
__int64 __fastcall CollisionAvoidanceTrack::GetClassNameUID(CollisionAvoidanceTrack *this)
{
  return CollisionAvoidanceTrack::sClassNameUID;
}

// File Line: 736
// RVA: 0x31E530
void __fastcall Pathing_OverrideCollisionAvoidanceTypeTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x40ui64,
         "MemberMap::Pathing_OverrideCollisionAvoidanceTypeTrack",
         0i64,
         1u);
  if ( v0 )
    Pathing_OverrideCollisionAvoidanceTypeTrack::Pathing_OverrideCollisionAvoidanceTypeTrack((Pathing_OverrideCollisionAvoidanceTypeTrack *)v0);
}

// File Line: 752
// RVA: 0x2BF130
__int64 __fastcall PathfindToTargetTrack::GetClassNameUID(PathfindToTargetTrack *this)
{
  return PathfindToTargetTrack::sClassNameUID;
}

// File Line: 805
// RVA: 0x2BF120
__int64 __fastcall PathfindAwayFromTargetTrack::GetClassNameUID(PathfindAwayFromTargetTrack *this)
{
  return PathfindAwayFromTargetTrack::sClassNameUID;
}

// File Line: 850
// RVA: 0x2BEE80
__int64 __fastcall MoveDirectlyToTargetTrack::GetClassNameUID(MoveDirectlyToTargetTrack *this)
{
  return MoveDirectlyToTargetTrack::sClassNameUID;
}

// File Line: 894
// RVA: 0x2BE690
__int64 __fastcall FollowTargetTrack::GetClassNameUID(FollowTargetTrack *this)
{
  return FollowTargetTrack::sClassNameUID;
}

// File Line: 962
// RVA: 0x2C0E40
const char *__fastcall CircleAroundCombatantsTrack::GetClassname(CircleAroundCombatantsTrack *this)
{
  return CircleAroundCombatantsTrack::sClassName;
}

// File Line: 1030
// RVA: 0x2BD9C0
__int64 __fastcall AITargetingParametersTrack::GetClassNameUID(AITargetingParametersTrack *this)
{
  return AITargetingParametersTrack::sClassNameUID;
}

// File Line: 1059
// RVA: 0x2C3280
__int64 __fastcall TargetVisibleInAIDataCondition::CreateClone(hkResourceHandle *this)
{
  return 0i64;
}

// File Line: 1079
// RVA: 0x2BD9B0
__int64 __fastcall AIRemoveSupplementaryAttackTargetTrack::GetClassNameUID(AIRemoveSupplementaryAttackTargetTrack *this)
{
  return AIRemoveSupplementaryAttackTargetTrack::sClassNameUID;
}

// File Line: 1099
// RVA: 0x2C13D0
const char *__fastcall GetInFormationTrack::GetClassname(GetInFormationTrack *this)
{
  return GetInFormationTrack::sClassName;
}

// File Line: 1122
// RVA: 0x2BE750
__int64 __fastcall GetInPedFormationTrack::GetClassNameUID(GetInPedFormationTrack *this)
{
  return GetInPedFormationTrack::sClassNameUID;
}

// File Line: 1146
// RVA: 0x2BEA00
__int64 __fastcall InvalidateFormationPositionTrack::GetClassNameUID(InvalidateFormationPositionTrack *this)
{
  return InvalidateFormationPositionTrack::sClassNameUID;
}

// File Line: 1166
// RVA: 0x31C910
void __fastcall JustPerformedRunningAttackTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x40ui64,
         "MemberMap::JustPerformedRunningAttackTrack",
         0i64,
         1u);
  if ( v0 )
    JustPerformedRunningAttackTrack::JustPerformedRunningAttackTrack((JustPerformedRunningAttackTrack *)v0);
}

// File Line: 1187
// RVA: 0x31FD10
void __fastcall RequestFormationPositionChangeTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x40ui64,
         "MemberMap::RequestFormationPositionChangeTrack",
         0i64,
         1u);
  if ( v0 )
    RequestFormationPositionChangeTrack::RequestFormationPositionChangeTrack((RequestFormationPositionChangeTrack *)v0);
}

// File Line: 1230
// RVA: 0x31CA00
void __fastcall LeaveGroupTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::LeaveGroupTrack", 0i64, 1u);
  if ( v0 )
    LeaveGroupTrack::LeaveGroupTrack((LeaveGroupTrack *)v0);
}

// File Line: 1244
// RVA: 0x320100
void __fastcall SelectSuitableVehicleTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "MemberMap::SelectSuitableVehicleTrack", 0i64, 1u);
  if ( v0 )
    SelectSuitableVehicleTrack::SelectSuitableVehicleTrack((SelectSuitableVehicleTrack *)v0);
}

// File Line: 1276
// RVA: 0x2C12E0
const char *__fastcall FireWeaponTrack::GetClassname(FireWeaponTrack *this)
{
  return FireWeaponTrack::sClassName;
}

// File Line: 1288
// RVA: 0x298630
void __fastcall FireWeaponTrack::FireWeaponTrack(FireWeaponTrack *this, MemImageLoadFlag flag)
{
  FireWeaponTrack *v2; // rbx

  v2 = this;
  ITrack::ITrack((ITrack *)&this->vfptr, flag);
  v2->vfptr = (Expression::IMemberMapVtbl *)&Track<FireWeaponTask>::`vftable';
  v2->vfptr = (Expression::IMemberMapVtbl *)&FireWeaponTrack::`vftable';
}

// File Line: 1319
// RVA: 0x3141B0
void __fastcall AICoverSearchTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x80ui64, "MemberMap::AICoverSearchTrack", 0i64, 1u);
  if ( v0 )
    AICoverSearchTrack::AICoverSearchTrack((AICoverSearchTrack *)v0);
}

// File Line: 1431
// RVA: 0x314070
void __fastcall AICoverFaceCoverObjectTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x38ui64, "MemberMap::AICoverFaceCoverObjectTrack", 0i64, 1u);
  if ( v0 )
    AICoverFaceCoverObjectTrack::AICoverFaceCoverObjectTrack((AICoverFaceCoverObjectTrack *)v0);
}

// File Line: 1449
// RVA: 0x2BD870
__int64 __fastcall AICoverClearCoverObjectTrack::GetClassNameUID(AICoverClearCoverObjectTrack *this)
{
  return AICoverClearCoverObjectTrack::sClassNameUID;
}

// File Line: 1466
// RVA: 0x2C0550
const char *__fastcall AICoverLatchTargetedObjectTrack::GetClassname(AICoverLatchTargetedObjectTrack *this)
{
  return AICoverLatchTargetedObjectTrack::sClassName;
}

// File Line: 1490
// RVA: 0x2C04F0
const char *__fastcall AICopReleaseArrestRightTrack::GetClassname(AICopReleaseArrestRightTrack *this)
{
  return AICopReleaseArrestRightTrack::sClassName;
}

// File Line: 1504
// RVA: 0x2C0500
const char *__fastcall AICopReportInfractionTargetTrack::GetClassname(AICopReportInfractionTargetTrack *this)
{
  return AICopReportInfractionTargetTrack::sClassName;
}

// File Line: 1523
// RVA: 0x299520
void __fastcall AICopApplyReducedRadiusTrack::~AICopApplyReducedRadiusTrack(AICopApplyReducedRadiusTrack *this)
{
  AICopApplyReducedRadiusTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&AICopApplyReducedRadiusTrack::`vftable';
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

// File Line: 1525
// RVA: 0x2C0460
const char *__fastcall AICopApplyReducedRadiusTrack::GetClassname(AICopApplyReducedRadiusTrack *this)
{
  return AICopApplyReducedRadiusTrack::sClassName;
}

// File Line: 1539
// RVA: 0x2C0630
const char *__fastcall AIOverrideAvoidanceRadiusTrack::GetClassname(AIOverrideAvoidanceRadiusTrack *this)
{
  return AIOverrideAvoidanceRadiusTrack::sClassName;
}

// File Line: 1564
// RVA: 0x2BE780
__int64 __fastcall GroupStimulusTrack::GetClassNameUID(GroupStimulusTrack *this)
{
  return GroupStimulusTrack::sClassNameUID;
}

// File Line: 1608
// RVA: 0x315840
void __fastcall AttackRightsScoreBonusTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x50ui64, "MemberMap::AttackRightsScoreBonusTrack", 0i64, 1u);
  if ( v0 )
    AttackRightsScoreBonusTrack::AttackRightsScoreBonusTrack((AttackRightsScoreBonusTrack *)v0);
}

// File Line: 1637
// RVA: 0x2C25B0
const char *__fastcall TargetActionRequestTrack::GetClassname(TargetActionRequestTrack *this)
{
  return TargetActionRequestTrack::sClassName;
}

// File Line: 1664
// RVA: 0x31CAA0
void __fastcall LockFormationPositionToCurrentPositionTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x38ui64,
         "MemberMap::LockFormationPositionToCurrentPositionTrack",
         0i64,
         1u);
  if ( v0 )
    LockFormationPositionToCurrentPositionTrack::LockFormationPositionToCurrentPositionTrack((LockFormationPositionToCurrentPositionTrack *)v0);
}

// File Line: 1683
// RVA: 0x29B9D0
void __fastcall ForceUpdateTargetingTrack::~ForceUpdateTargetingTrack(ForceUpdateTargetingTrack *this)
{
  ForceUpdateTargetingTrack *v1; // rbx
  ExpressionParameterFloat *v2; // rcx
  char *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&ForceUpdateTargetingTrack::`vftable';
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

// File Line: 1685
// RVA: 0x2BE6E0
__int64 __fastcall ForceUpdateTargetingTrack::GetClassNameUID(ForceUpdateTargetingTrack *this)
{
  return ForceUpdateTargetingTrack::sClassNameUID;
}

// File Line: 1701
// RVA: 0x314B40
void __fastcall AddTargetAsDangerousEntityTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x40ui64,
         "MemberMap::AddTargetAsDangerousEntityTrack",
         0i64,
         1u);
  if ( v0 )
    AddTargetAsDangerousEntityTrack::AddTargetAsDangerousEntityTrack((AddTargetAsDangerousEntityTrack *)v0);
}

// File Line: 1730
// RVA: 0x2C2330
const char *__fastcall SetDriverFlagsTrack::GetClassname(SetDriverFlagsTrack *this)
{
  return SetDriverFlagsTrack::sClassName;
}

// File Line: 1765
// RVA: 0x2C0910
const char *__fastcall AttackRightsSetTimeUntilNextAttackTrack::GetClassname(AttackRightsSetTimeUntilNextAttackTrack *this)
{
  return AttackRightsSetTimeUntilNextAttackTrack::sClassName;
}

// File Line: 1809
// RVA: 0x2BDC30
__int64 __fastcall AttackRightsClearPreviousBestAttackerTrack::GetClassNameUID(AttackRightsClearPreviousBestAttackerTrack *this)
{
  return AttackRightsClearPreviousBestAttackerTrack::sClassNameUID;
}

// File Line: 1838
// RVA: 0x2C08F0
const char *__fastcall AttackRightsReSortListTrack::GetClassname(AttackRightsReSortListTrack *this)
{
  return AttackRightsReSortListTrack::sClassName;
}

// File Line: 1867
// RVA: 0x2C08C0
const char *__fastcall AttackRightsCancelAnyIncomingAttackTrack::GetClassname(AttackRightsCancelAnyIncomingAttackTrack *this)
{
  return AttackRightsCancelAnyIncomingAttackTrack::sClassName;
}

// File Line: 1900
// RVA: 0x2BDC40
__int64 __fastcall AttackRightsFormationManagerFreezeRangeSwitchesTrack::GetClassNameUID(AttackRightsFormationManagerFreezeRangeSwitchesTrack *this)
{
  return AttackRightsFormationManagerFreezeRangeSwitchesTrack::sClassNameUID;
}

// File Line: 1923
// RVA: 0x2BE220
__int64 __fastcall CombatRegionMoveToTrack::GetClassNameUID(CombatRegionMoveToTrack *this)
{
  return CombatRegionMoveToTrack::sClassNameUID;
}

// File Line: 1957
// RVA: 0x3242F0
void __fastcall UpdateHijackableVehicleTargetTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x38ui64,
         "MemberMap::UpdateHijackableVehicleTargetTrack",
         0i64,
         1u);
  if ( v0 )
    UpdateHijackableVehicleTargetTrack::UpdateHijackableVehicleTargetTrack((UpdateHijackableVehicleTargetTrack *)v0);
}

// File Line: 1973
// RVA: 0x31D4E0
void __fastcall MoveToBetterAttackPositionTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x48ui64,
         "MemberMap::MoveToBetterAttackPositionTrack",
         0i64,
         1u);
  if ( v0 )
    MoveToBetterAttackPositionTrack::MoveToBetterAttackPositionTrack((MoveToBetterAttackPositionTrack *)v0);
}

// File Line: 2012
// RVA: 0x31D530
void __fastcall MoveToFindLineOfSightTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x48ui64, "MemberMap::MoveToFindLineOfSightTrack", 0i64, 1u);
  if ( v0 )
    MoveToFindLineOfSightTrack::MoveToFindLineOfSightTrack((MoveToFindLineOfSightTrack *)v0);
}

// File Line: 2055
// RVA: 0x326320
void __fastcall WaitUntilAbleToPathToTargetTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x40ui64,
         "MemberMap::WaitUntilAbleToPathToTargetTrack",
         0i64,
         1u);
  if ( v0 )
    WaitUntilAbleToPathToTargetTrack::WaitUntilAbleToPathToTargetTrack((WaitUntilAbleToPathToTargetTrack *)v0);
}

// File Line: 2084
// RVA: 0x31AE70
void __fastcall InteractingWithVehicleHeuristicTrack::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x38ui64,
         "MemberMap::InteractingWithVehicleHeuristicTrack",
         0i64,
         1u);
  if ( v0 )
    InteractingWithVehicleHeuristicTrack::InteractingWithVehicleHeuristicTrack((InteractingWithVehicleHeuristicTrack *)v0);
}

// File Line: 2102
// RVA: 0x313BC0
AIAwarenessEnableTrack *__fastcall AIAwarenessEnableTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::AIAwarenessEnableTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, AIAwarenessEnableTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<AIAwarenessEnableTask>::`vftable';
  *(_QWORD *)v1 = &AIAwarenessEnableTrack::`vftable';
  v1[56] = 1;
  return (AIAwarenessEnableTrack *)v1;
}

// File Line: 2120
// RVA: 0x2BD790
__int64 __fastcall AIAwarenessAddTargetTrack::GetClassNameUID(AIAwarenessAddTargetTrack *this)
{
  return AIAwarenessAddTargetTrack::sClassNameUID;
}

// File Line: 2143
// RVA: 0x31CBE0
LookAtTrack *__fastcall LookAtTrack::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::LookAtTrack", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  ITrack::ITrack((ITrack *)v0, LookAtTrack::sClassNameUID);
  *(_QWORD *)v1 = &Track<LookAtTask>::`vftable';
  *(_QWORD *)v1 = &LookAtTrack::`vftable';
  v1[56] = 0;
  return (LookAtTrack *)v1;
}

// File Line: 2163
// RVA: 0x2C2A10
const char *__fastcall TestPathToTargetTrack::GetClassname(TestPathToTargetTrack *this)
{
  return TestPathToTargetTrack::sClassName;
}

// File Line: 2181
// RVA: 0x2C16C0
const char *__fastcall InvokeBehaviourTrack::GetClassname(InvokeBehaviourTrack *this)
{
  return InvokeBehaviourTrack::sClassName;
}

// File Line: 2192
// RVA: 0x2BD340
ITask *__fastcall InvokeBehaviourTrack::CreateTask(InvokeBehaviourTrack *this, const char *debugName)
{
  InvokeBehaviourTrack *v2; // rdi
  char *v3; // rax
  ITask *v4; // rax
  ITask *v5; // rbx

  v2 = this;
  v3 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x2C0ui64, debugName, 0i64, 1u);
  if ( v3 )
  {
    InvokeBehaviourTask::InvokeBehaviourTask((InvokeBehaviourTask *)v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  ITask::SetTrack(v5, (ITrack *)&v2->vfptr);
  return v5;
}

