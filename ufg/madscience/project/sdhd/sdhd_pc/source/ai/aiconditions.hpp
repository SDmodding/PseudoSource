// File Line: 50
// RVA: 0x2BF520
__int64 __fastcall ReceivedStimulusCondition::GetClassNameUID(ReceivedStimulusCondition *this)
{
  return ReceivedStimulusCondition::sClassNameUID;
}

// File Line: 112
// RVA: 0x2C21A0
const char *__fastcall ReceivedHeatEventCondition::GetClassname(ReceivedHeatEventCondition *this)
{
  return ReceivedHeatEventCondition::sClassName;
}

// File Line: 125
// RVA: 0x314610
void __fastcall AIPlayerInsideAIMeshHeuristicCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::AIPlayerInsideAIMeshHeuristicCondition",
         0i64,
         1u);
  if ( v0 )
    AIPlayerInsideAIMeshHeuristicCondition::AIPlayerInsideAIMeshHeuristicCondition((AIPlayerInsideAIMeshHeuristicCondition *)v0);
}

// File Line: 134
// RVA: 0x2BD7B0
__int64 __fastcall AICopAcquireArrestRightCondition::GetClassNameUID(AICopAcquireArrestRightCondition *this)
{
  return AICopAcquireArrestRightCondition::sClassNameUID;
}

// File Line: 144
// RVA: 0x2C04E0
const char *__fastcall AICopPlayerInsideUnlockedSafehouseCondition::GetClassname(
        AICopPlayerInsideUnlockedSafehouseCondition *this)
{
  return AICopPlayerInsideUnlockedSafehouseCondition::sClassName;
}

// File Line: 154
// RVA: 0x2C04D0
const char *__fastcall AICopOnFootNoSprintCondition::GetClassname(AICopOnFootNoSprintCondition *this)
{
  return AICopOnFootNoSprintCondition::sClassName;
}

// File Line: 164
// RVA: 0x2C0490
const char *__fastcall AICopIsSoloOnSceneCondition::GetClassname(AICopIsSoloOnSceneCondition *this)
{
  return AICopIsSoloOnSceneCondition::sClassName;
}

// File Line: 175
// RVA: 0x313E90
void __fastcall AICopNumArrestAttemptCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::AICopNumArrestAttemptCondition",
         0i64,
         1u);
  if ( v0 )
    AICopNumArrestAttemptCondition::AICopNumArrestAttemptCondition((AICopNumArrestAttemptCondition *)v0);
}

// File Line: 193
// RVA: 0x2BD810
__int64 __fastcall AICopIsSuspectInsideInteriorCondition::GetClassNameUID(AICopIsSuspectInsideInteriorCondition *this)
{
  return AICopIsSuspectInsideInteriorCondition::sClassNameUID;
}

// File Line: 202
// RVA: 0x313DF0
void __fastcall AICopIsSuspectInWaterCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::AICopIsSuspectInWaterCondition",
         0i64,
         1u);
  if ( v0 )
    AICopIsSuspectInWaterCondition::AICopIsSuspectInWaterCondition((AICopIsSuspectInWaterCondition *)v0);
}

// File Line: 211
// RVA: 0x2BD7D0
__int64 __fastcall AICopHasSuspectOpenedFiredCondition::GetClassNameUID(AICopHasSuspectOpenedFiredCondition *this)
{
  return AICopHasSuspectOpenedFiredCondition::sClassNameUID;
}

// File Line: 226
// RVA: 0x313D50
void __fastcall AICopHasVehicleToDefendCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::AICopHasVehicleToDefendCondition",
         0i64,
         1u);
  if ( v0 )
    AICopHasVehicleToDefendCondition::AICopHasVehicleToDefendCondition((AICopHasVehicleToDefendCondition *)v0);
}

// File Line: 235
// RVA: 0x2BD8F0
__int64 __fastcall AIEncounterRoleCondition::GetClassNameUID(AIEncounterRoleCondition *this)
{
  return AIEncounterRoleCondition::sClassNameUID;
}

// File Line: 250
// RVA: 0x2C05A0
const char *__fastcall AIEncounterUnitGotStuckCondition::GetClassname(AIEncounterUnitGotStuckCondition *this)
{
  return AIEncounterUnitGotStuckCondition::sClassName;
}

// File Line: 261
// RVA: 0x2BDE60
__int64 __fastcall CanBeginSinglePersonConversationCondition::GetClassNameUID(
        CanBeginSinglePersonConversationCondition *this)
{
  return CanBeginSinglePersonConversationCondition::sClassNameUID;
}

// File Line: 277
// RVA: 0x2BE850
__int64 __fastcall HasRangedWeaponEquippedWithAmmoCondition::GetClassNameUID(
        HasRangedWeaponEquippedWithAmmoCondition *this)
{
  return HasRangedWeaponEquippedWithAmmoCondition::sClassNameUID;
}

// File Line: 290
// RVA: 0x317710
void __fastcall CollisionAvoidanceIsActiveCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::CollisionAvoidanceIsActiveCondition",
         0i64,
         1u);
  if ( v0 )
    CollisionAvoidanceIsActiveCondition::CollisionAvoidanceIsActiveCondition((CollisionAvoidanceIsActiveCondition *)v0);
}

// File Line: 303
// RVA: 0x2C14B0
const char *__fastcall HasAnyDangerousEntitiesOrPointsCondition::GetClassname(
        HasAnyDangerousEntitiesOrPointsCondition *this)
{
  return HasAnyDangerousEntitiesOrPointsCondition::sClassName;
}

// File Line: 316
// RVA: 0x2C21B0
const char *__fastcall ReceivedScriptCommandCondition::GetClassname(ReceivedScriptCommandCondition *this)
{
  return ReceivedScriptCommandCondition::sClassName;
}

// File Line: 329
// RVA: 0x31DBC0
void __fastcall OneShotCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x28ui64, "MemberMap::OneShotCondition", 0i64, 1u);
  if ( v0 )
    OneShotCondition::OneShotCondition((OneShotCondition *)v0);
}

// File Line: 347
// RVA: 0x2BE2C0
__int64 __fastcall CooldownCondition::GetClassNameUID(CooldownCondition *this)
{
  return CooldownCondition::sClassNameUID;
}

// File Line: 374
// RVA: 0x2C1400
const char *__fastcall GlobalCooldownCondition::GetClassname(GlobalCooldownCondition *this)
{
  return GlobalCooldownCondition::sClassName;
}

// File Line: 402
// RVA: 0x31FB30
void __fastcall RandomStartTimeCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x30ui64, "MemberMap::RandomStartTimeCondition", 0i64, 1u);
  if ( v0 )
    RandomStartTimeCondition::RandomStartTimeCondition((RandomStartTimeCondition *)v0);
}

// File Line: 428
// RVA: 0x2C05D0
const char *__fastcall AIObjectiveAnyCondition::GetClassname(AIObjectiveAnyCondition *this)
{
  return AIObjectiveAnyCondition::sClassName;
}

// File Line: 440
// RVA: 0x314430
void __fastcall AIObjectiveCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::AIObjectiveCondition", 0i64, 1u);
  if ( v0 )
    AIObjectiveCondition::AIObjectiveCondition((AIObjectiveCondition *)v0);
}

// File Line: 455
// RVA: 0x314480
void __fastcall AIObjectiveIsHostileCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::AIObjectiveIsHostileCondition",
         0i64,
         1u);
  if ( v0 )
    AIObjectiveIsHostileCondition::AIObjectiveIsHostileCondition((AIObjectiveIsHostileCondition *)v0);
}

// File Line: 469
// RVA: 0x314520
void __fastcall AIOnMeshCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::AIOnMeshCondition", 0i64, 1u);
  if ( v0 )
    AIOnMeshCondition::AIOnMeshCondition((AIOnMeshCondition *)v0);
}

// File Line: 482
// RVA: 0x2C0420
const char *__fastcall AIAtDestinationCondition::GetClassname(AIAtDestinationCondition *this)
{
  return AIAtDestinationCondition::sClassName;
}

// File Line: 501
// RVA: 0x2BD910
__int64 __fastcall AIHasValidPathCondition::GetClassNameUID(AIHasValidPathCondition *this)
{
  return AIHasValidPathCondition::sClassNameUID;
}

// File Line: 514
// RVA: 0x314250
void __fastcall AIDestinationObstructedCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::AIDestinationObstructedCondition",
         0i64,
         1u);
  if ( v0 )
    AIDestinationObstructedCondition::AIDestinationObstructedCondition((AIDestinationObstructedCondition *)v0);
}

// File Line: 524
// RVA: 0x31E070
void __fastcall POIUseTypeCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::POIUseTypeCondition", 0i64, 1u);
  if ( v0 )
    POIUseTypeCondition::POIUseTypeCondition((POIUseTypeCondition *)v0);
}

// File Line: 541
// RVA: 0x2C1510
const char *__fastcall HasRequestedSpeechCondition::GetClassname(HasRequestedSpeechCondition *this)
{
  return HasRequestedSpeechCondition::sClassName;
}

// File Line: 554
// RVA: 0x2C12A0
const char *__fastcall FailedSpeechCondition::GetClassname(FailedSpeechCondition *this)
{
  return FailedSpeechCondition::sClassName;
}

// File Line: 567
// RVA: 0x2C1530
const char *__fastcall HasSpecificSpeechAnimationCondition::GetClassname(HasSpecificSpeechAnimationCondition *this)
{
  return HasSpecificSpeechAnimationCondition::sClassName;
}

// File Line: 580
// RVA: 0x31A280
HasScriptedConversationCondition *__fastcall HasScriptedConversationCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::HasScriptedConversationCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &HasScriptedConversationCondition::`vftable;
  *((_DWORD *)v1 + 6) = 0;
  return (HasScriptedConversationCondition *)v1;
}

// File Line: 598
// RVA: 0x2BE860
__int64 __fastcall HasRemainingLinesCondition::GetClassNameUID(HasRemainingLinesCondition *this)
{
  return HasRemainingLinesCondition::sClassNameUID;
}

// File Line: 611
// RVA: 0x2C14A0
const char *__fastcall HasActiveConversationCondition::GetClassname(HasActiveConversationCondition *this)
{
  return HasActiveConversationCondition::sClassName;
}

// File Line: 624
// RVA: 0x317B80
ConversationFinishedCondition *__fastcall ConversationFinishedCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::ConversationFinishedCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &ConversationFinishedCondition::`vftable;
  return (ConversationFinishedCondition *)v1;
}

// File Line: 637
// RVA: 0x2C0F10
const char *__fastcall ConversationIsSpeakingCondition::GetClassname(ConversationIsSpeakingCondition *this)
{
  return ConversationIsSpeakingCondition::sClassName;
}

// File Line: 650
// RVA: 0x317C40
ConversationIsListeningCondition *__fastcall ConversationIsListeningCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::ConversationIsListeningCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &ConversationIsListeningCondition::`vftable;
  return (ConversationIsListeningCondition *)v1;
}

// File Line: 663
// RVA: 0x2C1930
const char *__fastcall IsSpeakingCondition::GetClassname(IsSpeakingCondition *this)
{
  return IsSpeakingCondition::sClassName;
}

// File Line: 676
// RVA: 0x317BE0
ConversationHasActionRequestsCondition *__fastcall ConversationHasActionRequestsCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::ConversationHasActionRequestsCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &ConversationHasActionRequestsCondition::`vftable;
  return (ConversationHasActionRequestsCondition *)v1;
}

// File Line: 690
// RVA: 0x3227C0
TargetPOIIsValidCondition *__fastcall TargetPOIIsValidCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::TargetPOIIsValidCondition", 0i64, 1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &TargetPOIIsValidCondition::`vftable;
  return (TargetPOIIsValidCondition *)v1;
}

// File Line: 703
// RVA: 0x2BFB70
__int64 __fastcall TargetPOIRequiresSyncCondition::GetClassNameUID(TargetPOIRequiresSyncCondition *this)
{
  return TargetPOIRequiresSyncCondition::sClassNameUID;
}

// File Line: 720
// RVA: 0x2BFB80
__int64 __fastcall TargetPOISyncRequiredCondition::GetClassNameUID(TargetPOISyncRequiredCondition *this)
{
  return TargetPOISyncRequiredCondition::sClassNameUID;
}

// File Line: 739
// RVA: 0x322760
TargetPOIAllowsSocialCondition *__fastcall TargetPOIAllowsSocialCondition::Create()
{
  char *v0; // rax
  char *v1; // rbx

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x18ui64,
         "MemberMap::TargetPOIAllowsSocialCondition",
         0i64,
         1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  Condition::Condition((Condition *)v0);
  *(_QWORD *)v1 = &TargetPOIAllowsSocialCondition::`vftable;
  return (TargetPOIAllowsSocialCondition *)v1;
}

// File Line: 759
// RVA: 0x2C26D0
const char *__fastcall TargetDistanceHysteresis::GetClassname(TargetDistanceHysteresis *this)
{
  return TargetDistanceHysteresis::sClassName;
}

// File Line: 819
// RVA: 0x2BFD10
__int64 __fastcall TargetVisibleCondition::GetClassNameUID(TargetVisibleCondition *this)
{
  return TargetVisibleCondition::sClassNameUID;
}

// File Line: 892
// RVA: 0x2C27C0
const char *__fastcall TargetKnowledgeCondition::GetClassname(TargetKnowledgeCondition *this)
{
  return TargetKnowledgeCondition::sClassName;
}

// File Line: 928
// RVA: 0x2BEBA0
__int64 __fastcall IsOnScreenCondition::GetClassNameUID(IsOnScreenCondition *this)
{
  return IsOnScreenCondition::sClassNameUID;
}

// File Line: 952
// RVA: 0x2BE720
__int64 __fastcall GetInFormationCondition::GetClassNameUID(GetInFormationCondition *this)
{
  return GetInFormationCondition::sClassNameUID;
}

// File Line: 994
// RVA: 0x2BE740
__int64 __fastcall GetInPedFormationCondition::GetClassNameUID(GetInPedFormationCondition *this)
{
  return GetInPedFormationCondition::sClassNameUID;
}

// File Line: 1027
// RVA: 0x314390
void __fastcall AIIsStandingBetweenAttackerAndTarget::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::AIIsStandingBetweenAttackerAndTarget",
         0i64,
         1u);
  if ( v0 )
    AIIsStandingBetweenAttackerAndTarget::AIIsStandingBetweenAttackerAndTarget((AIIsStandingBetweenAttackerAndTarget *)v0);
}

// File Line: 1066
// RVA: 0x2BEF20
__int64 __fastcall NextAttackerCondition::GetClassNameUID(NextAttackerCondition *this)
{
  return NextAttackerCondition::sClassNameUID;
}

// File Line: 1084
// RVA: 0x2C0AF0
const char *__fastcall CanAttackConditionGroup::GetClassname(CanAttackConditionGroup *this)
{
  return CanAttackConditionGroup::sClassName;
}

// File Line: 1089
// RVA: 0x2985C0
void __fastcall CanAttackConditionGroup::CanAttackConditionGroup(CanAttackConditionGroup *this, MemImageLoadFlag flag)
{
  this->ConditionGroup::Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->ConditionGroup::Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&Condition::`vftable;
  this->ConditionGroup::Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&ConditionGroup::`vftable;
  UFG::qSafePointerNode<CanAttackConditionGroup>::qSafePointerNode<CanAttackConditionGroup>(&this->UFG::qSafePointerNode<CanAttackConditionGroup>);
  this->ConditionGroup::Condition::Expression::IMemberMap::vfptr = (Expression::IMemberMapVtbl *)&CanAttackConditionGroup::`vftable{for `ConditionGroup};
  this->UFG::qSafePointerNode<CanAttackConditionGroup>::vfptr = (UFG::qSafePointerNode<CanAttackConditionGroup>Vtbl *)&CanAttackConditionGroup::`vftable{for `UFG::qSafePointerNode<CanAttackConditionGroup>};
}

// File Line: 1103
// RVA: 0x2BEB80
__int64 __fastcall IsNextAttackerCondition::GetClassNameUID(IsNextAttackerCondition *this)
{
  return IsNextAttackerCondition::sClassNameUID;
}

// File Line: 1140
// RVA: 0x2BE820
__int64 __fastcall HasAttackRequestCondition::GetClassNameUID(HasAttackRequestCondition *this)
{
  return HasAttackRequestCondition::sClassNameUID;
}

// File Line: 1220
// RVA: 0x2C16E0
const char *__fastcall IsAtRangePreferenceCondition::GetClassname(IsAtRangePreferenceCondition *this)
{
  return IsAtRangePreferenceCondition::sClassName;
}

// File Line: 1244
// RVA: 0x2C2A70
const char *__fastcall TimeoutCondition::GetClassname(TimeoutCondition *this)
{
  return TimeoutCondition::sClassName;
}

// File Line: 1274
// RVA: 0x2BF5F0
__int64 __fastcall RunningAttackCooldownCondition::GetClassNameUID(RunningAttackCooldownCondition *this)
{
  return RunningAttackCooldownCondition::sClassNameUID;
}

// File Line: 1308
// RVA: 0x2C1C90
const char *__fastcall OpportunityAttackCooldownCondition::GetClassname(OpportunityAttackCooldownCondition *this)
{
  return OpportunityAttackCooldownCondition::sClassName;
}

// File Line: 1360
// RVA: 0x2C2A40
const char *__fastcall TimeToInterceptCondition::GetClassname(TimeToInterceptCondition *this)
{
  return TimeToInterceptCondition::sClassName;
}

// File Line: 1391
// RVA: 0x2BF9C0
__int64 __fastcall TargetCanBeAttackedCondition::GetClassNameUID(TargetCanBeAttackedCondition *this)
{
  return TargetCanBeAttackedCondition::sClassNameUID;
}

// File Line: 1413
// RVA: 0x2C14D0
const char *__fastcall HasPositionToDefendCondition::GetClassname(HasPositionToDefendCondition *this)
{
  return HasPositionToDefendCondition::sClassName;
}

// File Line: 1431
// RVA: 0x31DCB0
void __fastcall OutsideOfPositionToDefendCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::OutsideOfPositionToDefendCondition",
         0i64,
         1u);
  if ( v0 )
    OutsideOfPositionToDefendCondition::OutsideOfPositionToDefendCondition((OutsideOfPositionToDefendCondition *)v0);
}

// File Line: 1459
// RVA: 0x314700
void __fastcall AbandonPositionToDefendCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x28ui64,
         "MemberMap::AbandonPositionToDefendCondition",
         0i64,
         1u);
  if ( v0 )
    AbandonPositionToDefendCondition::AbandonPositionToDefendCondition((AbandonPositionToDefendCondition *)v0);
}

// File Line: 1490
// RVA: 0x2BE320
__int64 __fastcall CrouchWhileDefendingPositionCondition::GetClassNameUID(CrouchWhileDefendingPositionCondition *this)
{
  return CrouchWhileDefendingPositionCondition::sClassNameUID;
}

// File Line: 1508
// RVA: 0x31D670
void __fastcall NodeRequestCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "MemberMap::NodeRequestCondition", 0i64, 1u);
  if ( v0 )
    NodeRequestCondition::NodeRequestCondition((NodeRequestCondition *)v0);
}

// File Line: 1529
// RVA: 0x2C1BE0
const char *__fastcall NodeRequestAnyCondition::GetClassname(NodeRequestAnyCondition *this)
{
  return NodeRequestAnyCondition::sClassName;
}

// File Line: 1547
// RVA: 0x31C9B0
void __fastcall LeaderHasFollowersCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::LeaderHasFollowersCondition", 0i64, 1u);
  if ( v0 )
    LeaderHasFollowersCondition::LeaderHasFollowersCondition((LeaderHasFollowersCondition *)v0);
}

// File Line: 1565
// RVA: 0x2C0540
const char *__fastcall AICoverIsValidCondition::GetClassname(AICoverIsValidCondition *this)
{
  return AICoverIsValidCondition::sClassName;
}

// File Line: 1597
// RVA: 0x2BD8D0
__int64 __fastcall AICoverTargetIsLatched::GetClassNameUID(AICoverTargetIsLatched *this)
{
  return AICoverTargetIsLatched::sClassNameUID;
}

// File Line: 1617
// RVA: 0x2BD890
__int64 __fastcall AICoverFiringPositionClear::GetClassNameUID(AICoverFiringPositionClear *this)
{
  return AICoverFiringPositionClear::sClassNameUID;
}

// File Line: 1649
// RVA: 0x31B580
void __fastcall IsClosestFormationMemberCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::IsClosestFormationMemberCondition",
         0i64,
         1u);
  if ( v0 )
    IsClosestFormationMemberCondition::IsClosestFormationMemberCondition((IsClosestFormationMemberCondition *)v0);
}

// File Line: 1671
// RVA: 0x31B5D0
void __fastcall IsClosestGroupMemberCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::IsClosestGroupMemberCondition",
         0i64,
         1u);
  if ( v0 )
    IsClosestGroupMemberCondition::IsClosestGroupMemberCondition((IsClosestGroupMemberCondition *)v0);
}

// File Line: 1697
// RVA: 0x2C22B0
const char *__fastcall SelectSuitableVehicleCondition::GetClassname(SelectSuitableVehicleCondition *this)
{
  return SelectSuitableVehicleCondition::sClassName;
}

// File Line: 1750
// RVA: 0x2C22A0
const char *__fastcall ScriptFakeHasHostageCondition::GetClassname(ScriptFakeHasHostageCondition *this)
{
  return ScriptFakeHasHostageCondition::sClassName;
}

// File Line: 1768
// RVA: 0x323B10
void __fastcall TargetVisibleInAIDataCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x38ui64,
         "MemberMap::TargetVisibleInAIDataCondition",
         0i64,
         1u);
  if ( v0 )
    TargetVisibleInAIDataCondition::TargetVisibleInAIDataCondition((TargetVisibleInAIDataCondition *)v0);
}

// File Line: 1811
// RVA: 0x3221B0
void __fastcall TargetIsEnemyOfMineCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::TargetIsEnemyOfMineCondition",
         0i64,
         1u);
  if ( v0 )
    TargetIsEnemyOfMineCondition::TargetIsEnemyOfMineCondition((TargetIsEnemyOfMineCondition *)v0);
}

// File Line: 1833
// RVA: 0x3179C0
void __fastcall CombatRegionExistsCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::CombatRegionExistsCondition", 0i64, 1u);
  if ( v0 )
    CombatRegionExistsCondition::CombatRegionExistsCondition((CombatRegionExistsCondition *)v0);
}

// File Line: 1847
// RVA: 0x2BE210
__int64 __fastcall CombatRegionIsInsideCondition::GetClassNameUID(CombatRegionIsInsideCondition *this)
{
  return CombatRegionIsInsideCondition::sClassNameUID;
}

// File Line: 1861
// RVA: 0x2C0ED0
const char *__fastcall CombatRegionTargetIsInsideCondition::GetClassname(CombatRegionTargetIsInsideCondition *this)
{
  return CombatRegionTargetIsInsideCondition::sClassName;
}

// File Line: 1883
// RVA: 0x31B9A0
void __fastcall IsInCrosswalkCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::IsInCrosswalkCondition", 0i64, 1u);
  if ( v0 )
    IsInCrosswalkCondition::IsInCrosswalkCondition((IsInCrosswalkCondition *)v0);
}

// File Line: 1897
// RVA: 0x2C08B0
const char *__fastcall AttackRequestCanceledCondition::GetClassname(AttackRequestCanceledCondition *this)
{
  return AttackRequestCanceledCondition::sClassName;
}

// File Line: 1915
// RVA: 0x319F10
void __fastcall HasAIDriverCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x18ui64, "MemberMap::HasAIDriverCondition", 0i64, 1u);
  if ( v0 )
    HasAIDriverCondition::HasAIDriverCondition((HasAIDriverCondition *)v0);
}

// File Line: 1930
// RVA: 0x2BE4E0
__int64 __fastcall DriverFlagAvoidPedsCondition::GetClassNameUID(DriverFlagAvoidPedsCondition *this)
{
  return DriverFlagAvoidPedsCondition::sClassNameUID;
}

// File Line: 1948
// RVA: 0x2BE4D0
__int64 __fastcall DriverFlagAllowedToPassCondition::GetClassNameUID(DriverFlagAllowedToPassCondition *this)
{
  return DriverFlagAllowedToPassCondition::sClassNameUID;
}

// File Line: 1966
// RVA: 0x2C11A0
const char *__fastcall DriverFlagStayOffSidewalkCondition::GetClassname(DriverFlagStayOffSidewalkCondition *this)
{
  return DriverFlagStayOffSidewalkCondition::sClassName;
}

// File Line: 1984
// RVA: 0x318C50
void __fastcall DriverFlagRespectSpeedLimitCondition::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(
         &gActionTreeMemoryPool,
         0x20ui64,
         "MemberMap::DriverFlagRespectSpeedLimitCondition",
         0i64,
         1u);
  if ( v0 )
    DriverFlagRespectSpeedLimitCondition::DriverFlagRespectSpeedLimitCondition((DriverFlagRespectSpeedLimitCondition *)v0);
}

// File Line: 2009
// RVA: 0x2C26E0
const char *__fastcall TargetDistanceRelativeDesiredRangeCondition::GetClassname(
        TargetDistanceRelativeDesiredRangeCondition *this)
{
  return TargetDistanceRelativeDesiredRangeCondition::sClassName;
}

