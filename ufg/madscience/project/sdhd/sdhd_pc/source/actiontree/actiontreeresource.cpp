// File Line: 65
// RVA: 0x1494260
__int64 dynamic_initializer_for__gActionTreeResourceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&gActionTreeResourceInventory.vfptr,
    "ActionTreeResourceInventory",
    0x8DB8241B,
    0x4BCE8537u,
    0,
    0);
  gActionTreeResourceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&ActionTreeResourceInventory::`vftable';
  return atexit(dynamic_atexit_destructor_for__gActionTreeResourceInventory__);
}

// File Line: 66
// RVA: 0x14942C0
__int64 dynamic_initializer_for__gAnimationGroupResourceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&gAnimationGroupResourceInventory.vfptr,
    "AnimationGroupResourceInventory",
    0x58087229u,
    0x3D0EBC72u,
    0,
    0);
  gAnimationGroupResourceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&AnimationGroupResourceInventory::`vftable';
  return atexit(dynamic_atexit_destructor_for__gAnimationGroupResourceInventory__);
}

// File Line: 67
// RVA: 0x14944A0
__int64 dynamic_initializer_for__gWeightSetGroupResourceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&gWeightSetGroupResourceInventory.vfptr,
    "WeightSetGroupResourceInventory",
    0x50C27D5Fu,
    0x1146D4C8u,
    0,
    0);
  gWeightSetGroupResourceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&WeightSetGroupResourceInventory::`vftable';
  return atexit(dynamic_atexit_destructor_for__gWeightSetGroupResourceInventory__);
}

// File Line: 71
// RVA: 0x1494410
__int64 dynamic_initializer_for__gUELFragmentTableInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&gUELFragmentTableInventory.vfptr,
    "UELFragmentTableInventory",
    0x2DB16C3Eu,
    0x32890C01u,
    0,
    0);
  gUELFragmentTableInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UELFragmentTableInventory::`vftable';
  return atexit(dynamic_atexit_destructor_for__gUELFragmentTableInventory__);
}

// File Line: 72
// RVA: 0x1494380
__int64 dynamic_initializer_for__gRigInfoResourceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&gRigInfoResourceInventory.vfptr,
    "RigInfoResourceInventory",
    0xAEF1F66F,
    0x36C2E8Eu,
    0,
    0);
  gRigInfoResourceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&RigInfoResourceInventory::`vftable';
  return atexit(dynamic_atexit_destructor_for__gRigInfoResourceInventory__);
}

// File Line: 73
// RVA: 0x1494320
__int64 dynamic_initializer_for__gBlendTreeResourceInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&gBlendTreeResourceInventory.vfptr,
    "BlendTreeResourceInventory",
    0x2680E48u,
    0xE691BB97,
    0,
    0);
  gBlendTreeResourceInventory.vfptr = (UFG::qResourceInventoryVtbl *)&BlendTreeResourceInventory::`vftable';
  return atexit(dynamic_atexit_destructor_for__gBlendTreeResourceInventory__);
}

// File Line: 80
// RVA: 0x2CA570
void __fastcall InPlaceInit<AccuracyEnsureMissTrack>::InPlaceNew(void *ptr)
{
  _QWORD *v1; // rbx

  v1 = ptr;
  if ( ptr )
  {
    ITrack::ITrack((ITrack *)ptr, 0);
    *v1 = &Track<AccuracyEnsureMissTask>::`vftable';
    *v1 = &AccuracyEnsureMissTrack::`vftable';
  }
}

// File Line: 91
// RVA: 0x2DCD00
bool __fastcall BlendTreeDataBase::UIDSort(ClassTypeDescriptor *a, ClassTypeDescriptor *b)
{
  return a->mUID < b->mUID;
}

// File Line: 96
// RVA: 0x2C32C0
ClassTypeDescriptor *__fastcall GetTypeDescriptors(unsigned int *count)
{
  unsigned int *v1; // rbx

  v1 = count;
  if ( !(_S4_5 & 1) )
  {
    _S4_5 |= 1u;
    gTypeDescriptors[0].mUID = TargetActionRequestTrack::sClassNameUID;
    qword_1423B1AF8 = (__int64)InPlaceInit<TargetActionRequestTrack>::InPlaceNew;
    dword_1423B1B00 = ActionRequestTrack::sClassNameUID;
    qword_1423B1B08 = (__int64)InPlaceInit<ActionRequestTrack>::InPlaceNew;
    dword_1423B1B10 = SubtitleTrack::sClassNameUID;
    qword_1423B1B18 = (__int64)InPlaceInit<SubtitleTrack>::InPlaceNew;
    dword_1423B1B20 = ConversationTrackInterrupt::sClassNameUID;
    qword_1423B1B28 = (__int64)InPlaceInit<ConversationTrackInterrupt>::InPlaceNew;
    dword_1423B1B30 = Phoneme_Ee::sClassNameUID;
    qword_1423B1B38 = (__int64)InPlaceInit<Phoneme_Ee>::InPlaceNew;
    dword_1423B1B40 = Phoneme_Eh::sClassNameUID;
    qword_1423B1B48 = (__int64)InPlaceInit<Phoneme_Eh>::InPlaceNew;
    dword_1423B1B50 = Phoneme_Rr::sClassNameUID;
    qword_1423B1B58 = (__int64)InPlaceInit<Phoneme_Rr>::InPlaceNew;
    dword_1423B1B60 = Phoneme_Fr::sClassNameUID;
    qword_1423B1B68 = (__int64)InPlaceInit<Phoneme_Fr>::InPlaceNew;
    dword_1423B1B70 = Phoneme_Mm::sClassNameUID;
    qword_1423B1B78 = (__int64)InPlaceInit<Phoneme_Mm>::InPlaceNew;
    dword_1423B1B80 = Phoneme_A0::sClassNameUID;
    qword_1423B1B88 = (__int64)InPlaceInit<Phoneme_A0>::InPlaceNew;
    dword_1423B1B90 = Phoneme_AA::sClassNameUID;
    qword_1423B1B98 = (__int64)InPlaceInit<Phoneme_AA>::InPlaceNew;
    dword_1423B1BA0 = Phoneme_OW::sClassNameUID;
    qword_1423B1BA8 = (__int64)InPlaceInit<Phoneme_OW>::InPlaceNew;
    dword_1423B1BB0 = NISActorNode::sClassNameUID;
    qword_1423B1BB8 = (__int64)InPlaceInit<NISActorNode>::InPlaceNew;
    dword_1423B1BC0 = PrintTrack::sClassNameUID;
    qword_1423B1BC8 = (__int64)InPlaceInit<PrintTrack>::InPlaceNew;
    dword_1423B1BD0 = AudioTrackNIS::sClassNameUID;
    qword_1423B1BD8 = (__int64)InPlaceInit<AudioTrackNIS>::InPlaceNew;
    dword_1423B1BE0 = AudioTrackSimple::sClassNameUID;
    qword_1423B1BE8 = (__int64)InPlaceInit<AudioTrackSimple>::InPlaceNew;
    dword_1423B1BF0 = AudioTrackMusicState::sClassNameUID;
    qword_1423B1BF8 = (__int64)InPlaceInit<AudioTrackMusicState>::InPlaceNew;
    dword_1423B1C00 = CameraAnimationTrack::sClassNameUID;
    qword_1423B1C08 = (__int64)InPlaceInit<CameraAnimationTrack>::InPlaceNew;
    dword_1423B1C10 = SkookumTrack::sClassNameUID;
    qword_1423B1C18 = (__int64)InPlaceInit<SkookumTrack>::InPlaceNew;
    dword_1423B1C20 = SubtitleTrack::sClassNameUID;
    qword_1423B1C28 = (__int64)InPlaceInit<SubtitleTrack>::InPlaceNew;
    dword_1423B1C30 = SubtitleGroupTrack::sClassNameUID;
    qword_1423B1C38 = (__int64)InPlaceInit<SubtitleGroupTrack>::InPlaceNew;
    dword_1423B1C40 = CurtainShowTrack::sClassNameUID;
    qword_1423B1C48 = (__int64)InPlaceInit<CurtainShowTrack>::InPlaceNew;
    dword_1423B1C50 = FastCurtainShowTrack::sClassNameUID;
    qword_1423B1C58 = (__int64)InPlaceInit<FastCurtainShowTrack>::InPlaceNew;
    dword_1423B1C60 = NISFadeOutTrack::sClassNameUID;
    qword_1423B1C68 = (__int64)InPlaceInit<NISFadeOutTrack>::InPlaceNew;
    dword_1423B1C70 = NISLightGroupAnimationTrack::sClassNameUID;
    qword_1423B1C78 = (__int64)InPlaceInit<NISLightGroupAnimationTrack>::InPlaceNew;
    dword_1423B1C80 = PlayEffectTrack::sClassNameUID;
    qword_1423B1C88 = (__int64)InPlaceInit<PlayEffectTrack>::InPlaceNew;
    dword_1423B1C90 = UIScreenTrack::sClassNameUID;
    qword_1423B1C98 = (__int64)InPlaceInit<UIScreenTrack>::InPlaceNew;
    dword_1423B1CA0 = NISShadowCascadeTrack::sClassNameUID;
    qword_1423B1CA8 = (__int64)InPlaceInit<NISShadowCascadeTrack>::InPlaceNew;
    dword_1423B1CB0 = DamageEffectTrack::sClassNameUID;
    qword_1423B1CB8 = (__int64)InPlaceInit<DamageEffectTrack>::InPlaceNew;
    dword_1423B1CC0 = NISPlayMovieTrack::sClassNameUID;
    qword_1423B1CC8 = (__int64)InPlaceInit<NISPlayMovieTrack>::InPlaceNew;
    dword_1423B1CD0 = NISAllowPlayerControlTrack::sClassNameUID;
    qword_1423B1CD8 = (__int64)InPlaceInit<NISAllowPlayerControlTrack>::InPlaceNew;
    dword_1423B1CE0 = ActionNodeRoot::sClassNameUID;
    qword_1423B1CE8 = (__int64)InPlaceInit<ActionNodeRoot>::InPlaceNew;
    dword_1423B1CF0 = ActionNodeBank::sClassNameUID;
    qword_1423B1CF8 = (__int64)InPlaceInit<ActionNodeBank>::InPlaceNew;
    dword_1423B1D00 = ActionNodePlayable::sClassNameUID;
    qword_1423B1D08 = (__int64)InPlaceInit<ActionNodePlayable>::InPlaceNew;
    dword_1423B1D10 = ActionNodeFileReference::sClassNameUID;
    qword_1423B1D18 = (__int64)InPlaceInit<ActionNodeFileReference>::InPlaceNew;
    dword_1423B1D20 = NISNode::sClassNameUID;
    qword_1423B1D28 = (__int64)InPlaceInit<NISNode>::InPlaceNew;
    dword_1423B1D30 = StimulusBank::sClassNameUID;
    qword_1423B1D38 = (__int64)InPlaceInit<StimulusBank>::InPlaceNew;
    dword_1423B1D40 = TrackLibraryNode::sClassNameUID;
    qword_1423B1D48 = (__int64)InPlaceInit<TrackLibraryNode>::InPlaceNew;
    dword_1423B1D50 = ActionController::sClassNameUID;
    qword_1423B1D58 = (__int64)InPlaceInit<ActionController>::InPlaceNew;
    dword_1423B1D60 = ActionRequestDebug::sClassNameUID;
    qword_1423B1D68 = (__int64)InPlaceInit<ActionRequestDebug>::InPlaceNew;
    dword_1423B1D70 = TimePlotPoint::sClassNameUID;
    qword_1423B1D78 = (__int64)InPlaceInit<TimePlotPoint>::InPlaceNew;
    dword_1423B1D80 = BoneInfo::sClassNameUID;
    qword_1423B1D88 = (__int64)InPlaceInit<BoneInfo>::InPlaceNew;
    dword_1423B1D90 = Weightset::sClassNameUID;
    qword_1423B1D98 = (__int64)InPlaceInit<Weightset>::InPlaceNew;
    dword_1423B1DA0 = WeightsetEntry::sClassNameUID;
    qword_1423B1DA8 = (__int64)InPlaceInit<WeightsetEntry>::InPlaceNew;
    dword_1423B1DB0 = RootUprightDriver::sClassNameUID;
    qword_1423B1DB8 = (__int64)InPlaceInit<RootUprightDriver>::InPlaceNew;
    dword_1423B1DC0 = AimConstraint::sClassNameUID;
    qword_1423B1DC8 = (__int64)InPlaceInit<AimConstraint>::InPlaceNew;
    dword_1423B1DD0 = AimConstraint2::sClassNameUID;
    qword_1423B1DD8 = (__int64)InPlaceInit<AimConstraint2>::InPlaceNew;
    dword_1423B1DE0 = AimConstraintMultiLink::sClassNameUID;
    qword_1423B1DE8 = (__int64)InPlaceInit<AimConstraintMultiLink>::InPlaceNew;
    dword_1423B1DF0 = TwoLinkIKsolver::sClassNameUID;
    qword_1423B1DF8 = (__int64)InPlaceInit<TwoLinkIKsolver>::InPlaceNew;
    dword_1423B1E00 = OrientationConstraint::sClassNameUID;
    qword_1423B1E08 = (__int64)InPlaceInit<OrientationConstraint>::InPlaceNew;
    dword_1423B1E10 = TwistXRotLinearLink::sClassNameUID;
    qword_1423B1E18 = (__int64)InPlaceInit<TwistXRotLinearLink>::InPlaceNew;
    dword_1423B1E20 = FollowLink::sClassNameUID;
    qword_1423B1E28 = (__int64)InPlaceInit<FollowLink>::InPlaceNew;
    dword_1423B1E30 = Follow2Link::sClassNameUID;
    qword_1423B1E38 = (__int64)InPlaceInit<Follow2Link>::InPlaceNew;
    dword_1423B1E40 = Follow3Link::sClassNameUID;
    qword_1423B1E48 = (__int64)InPlaceInit<Follow3Link>::InPlaceNew;
    dword_1423B1E50 = Spring1DOF::sClassNameUID;
    qword_1423B1E58 = (__int64)InPlaceInit<Spring1DOF>::InPlaceNew;
    dword_1423B1E60 = BlendTreeControllerTrack::sClassNameUID;
    qword_1423B1E68 = (__int64)InPlaceInit<BlendTreeControllerTrack>::InPlaceNew;
    dword_1423B1E70 = BlendTreeControllerTargetPositionTrack::sClassNameUID;
    qword_1423B1E78 = (__int64)InPlaceInit<BlendTreeControllerTargetPositionTrack>::InPlaceNew;
    dword_1423B1E80 = BlendTreeControllerTargetDistancTrack::sClassNameUID;
    qword_1423B1E88 = (__int64)InPlaceInit<BlendTreeControllerTargetDistancTrack>::InPlaceNew;
    dword_1423B1E90 = BlendTreeControllerGroup::sClassNameUID;
    qword_1423B1E98 = (__int64)InPlaceInit<BlendTreeControllerGroup>::InPlaceNew;
    dword_1423B1EA0 = PoseNodeParent::sClassNameUID;
    qword_1423B1EA8 = (__int64)InPlaceInit<PoseNodeParent>::InPlaceNew;
    dword_1423B1EB0 = PoseNodeRoot::sClassNameUID;
    qword_1423B1EB8 = (__int64)InPlaceInit<PoseNodeRoot>::InPlaceNew;
    dword_1423B1EC0 = BlendNode::sClassNameUID;
    qword_1423B1EC8 = (__int64)InPlaceInit<BlendNode>::InPlaceNew;
    dword_1423B1ED0 = BlendDirectionNode::sClassNameUID;
    qword_1423B1ED8 = (__int64)InPlaceInit<BlendDirectionNode>::InPlaceNew;
    dword_1423B1EE0 = BlendAddNode::sClassNameUID;
    qword_1423B1EE8 = (__int64)InPlaceInit<BlendAddNode>::InPlaceNew;
    dword_1423B1EF0 = BlendSubNode::sClassNameUID;
    qword_1423B1EF8 = (__int64)InPlaceInit<BlendSubNode>::InPlaceNew;
    dword_1423B1F00 = BlendPhaseNode::sClassNameUID;
    qword_1423B1F08 = (__int64)InPlaceInit<BlendPhaseNode>::InPlaceNew;
    dword_1423B1F10 = MotionPhase2::sClassNameUID;
    qword_1423B1F18 = (__int64)InPlaceInit<MotionPhase2>::InPlaceNew;
    dword_1423B1F20 = AnimationNode::sClassNameUID;
    qword_1423B1F28 = (__int64)InPlaceInit<AnimationNode>::InPlaceNew;
    dword_1423B1F30 = AnimationGroup::sClassNameUID;
    qword_1423B1F38 = (__int64)InPlaceInit<AnimationGroup>::InPlaceNew;
    dword_1423B1F40 = SkeletalAnimation::sClassNameUID;
    qword_1423B1F48 = (__int64)InPlaceInit<SkeletalAnimation>::InPlaceNew;
    dword_1423B1F50 = MotionPhaseChannel::sClassNameUID;
    qword_1423B1F58 = (__int64)InPlaceInit<MotionPhaseChannel>::InPlaceNew;
    dword_1423B1F60 = PrintTrack::sClassNameUID;
    qword_1423B1F68 = (__int64)InPlaceInit<PrintTrack>::InPlaceNew;
    dword_1423B1F70 = PlayEffectTrack::sClassNameUID;
    qword_1423B1F78 = (__int64)InPlaceInit<PlayEffectTrack>::InPlaceNew;
    dword_1423B1F80 = RumbleTrack::sClassNameUID;
    qword_1423B1F88 = (__int64)InPlaceInit<RumbleTrack>::InPlaceNew;
    dword_1423B1F90 = DoorStateTrack::sClassNameUID;
    qword_1423B1F98 = (__int64)InPlaceInit<DoorStateTrack>::InPlaceNew;
    dword_1423B1FA0 = AudioTrack::sClassNameUID;
    qword_1423B1FA8 = (__int64)InPlaceInit<AudioTrack>::InPlaceNew;
    dword_1423B1FB0 = AudioTrackSimple::sClassNameUID;
    qword_1423B1FB8 = (__int64)InPlaceInit<AudioTrackSimple>::InPlaceNew;
    dword_1423B1FC0 = AudioTrackSurfaceDetection::sClassNameUID;
    qword_1423B1FC8 = (__int64)InPlaceInit<AudioTrackSurfaceDetection>::InPlaceNew;
    dword_1423B1FD0 = AudioTrackSoundbankIO::sClassNameUID;
    qword_1423B1FD8 = (__int64)InPlaceInit<AudioTrackSoundbankIO>::InPlaceNew;
    dword_1423B1FE0 = AudioTrackMusicState::sClassNameUID;
    qword_1423B1FE8 = (__int64)InPlaceInit<AudioTrackMusicState>::InPlaceNew;
    dword_1423B1FF0 = DialogueTrack::sClassNameUID;
    qword_1423B1FF8 = (__int64)InPlaceInit<DialogueTrack>::InPlaceNew;
    dword_1423B2000 = DialogueTrackWeaponImpact::sClassNameUID;
    qword_1423B2008 = (__int64)InPlaceInit<DialogueTrackWeaponImpact>::InPlaceNew;
    dword_1423B2010 = FootStepLeftEffectTrack::sClassNameUID;
    qword_1423B2018 = (__int64)InPlaceInit<FootStepLeftEffectTrack>::InPlaceNew;
    dword_1423B2020 = FootStepRightEffectTrack::sClassNameUID;
    qword_1423B2028 = (__int64)InPlaceInit<FootStepRightEffectTrack>::InPlaceNew;
    dword_1423B2030 = CollisionEffectTrack::sClassNameUID;
    qword_1423B2038 = (__int64)InPlaceInit<CollisionEffectTrack>::InPlaceNew;
    dword_1423B2040 = EffectSurfaceCollisionTrack::sClassNameUID;
    qword_1423B2048 = (__int64)InPlaceInit<EffectSurfaceCollisionTrack>::InPlaceNew;
    dword_1423B2050 = PoliceScannerAudioEventTrack::sClassNameUID;
    qword_1423B2058 = (__int64)InPlaceInit<PoliceScannerAudioEventTrack>::InPlaceNew;
    dword_1423B2060 = MotionKeyFootStepLeft::sClassNameUID;
    qword_1423B2068 = (__int64)InPlaceInit<MotionKeyFootStepLeft>::InPlaceNew;
    dword_1423B2070 = MotionKeyFootStepRight::sClassNameUID;
    qword_1423B2078 = (__int64)InPlaceInit<MotionKeyFootStepRight>::InPlaceNew;
    dword_1423B2080 = FalseCondition::sClassNameUID;
    qword_1423B2088 = (__int64)InPlaceInit<FalseCondition>::InPlaceNew;
    dword_1423B2090 = NotCondition::sClassNameUID;
    qword_1423B2098 = (__int64)InPlaceInit<NotCondition>::InPlaceNew;
    dword_1423B20A0 = ORCondition::sClassNameUID;
    qword_1423B20A8 = (__int64)InPlaceInit<ORCondition>::InPlaceNew;
    dword_1423B20B0 = ConditionGroup::sClassNameUID;
    qword_1423B20B8 = (__int64)InPlaceInit<ConditionGroup>::InPlaceNew;
    dword_1423B20C0 = IsPlayingCondition::sClassNameUID;
    qword_1423B20C8 = (__int64)InPlaceInit<IsPlayingCondition>::InPlaceNew;
    dword_1423B20D0 = IsPlayingThisCondition::sClassNameUID;
    qword_1423B20D8 = (__int64)InPlaceInit<IsPlayingThisCondition>::InPlaceNew;
    dword_1423B20E0 = IsPlayingNodeCondition::sClassNameUID;
    qword_1423B20E8 = (__int64)InPlaceInit<IsPlayingNodeCondition>::InPlaceNew;
    dword_1423B20F0 = TargetDistance::sClassNameUID;
    qword_1423B20F8 = (__int64)InPlaceInit<TargetDistance>::InPlaceNew;
    dword_1423B2100 = TargetConditionGroup::sClassNameUID;
    qword_1423B2108 = (__int64)InPlaceInit<TargetConditionGroup>::InPlaceNew;
    dword_1423B2110 = TargetRelativePosition::sClassNameUID;
    qword_1423B2118 = (__int64)InPlaceInit<TargetRelativePosition>::InPlaceNew;
    dword_1423B2120 = TargetRelativeOrientationCondition::sClassNameUID;
    qword_1423B2128 = (__int64)InPlaceInit<TargetRelativeOrientationCondition>::InPlaceNew;
    dword_1423B2130 = TargetValidCondition::sClassNameUID;
    qword_1423B2138 = (__int64)InPlaceInit<TargetValidCondition>::InPlaceNew;
    dword_1423B2140 = TargetDistanceHysteresis::sClassNameUID;
    qword_1423B2148 = (__int64)InPlaceInit<TargetDistanceHysteresis>::InPlaceNew;
    dword_1423B2150 = TargetVisibleCondition::sClassNameUID;
    qword_1423B2158 = (__int64)InPlaceInit<TargetVisibleCondition>::InPlaceNew;
    dword_1423B2160 = TargetVisibleInAIDataCondition::sClassNameUID;
    qword_1423B2168 = (__int64)InPlaceInit<TargetVisibleInAIDataCondition>::InPlaceNew;
    dword_1423B2170 = TargetIsPlayingCondition::sClassNameUID;
    qword_1423B2178 = (__int64)InPlaceInit<TargetIsPlayingCondition>::InPlaceNew;
    dword_1423B2180 = TargetIsLockedCondition::sClassNameUID;
    qword_1423B2188 = (__int64)InPlaceInit<TargetIsLockedCondition>::InPlaceNew;
    dword_1423B2190 = CooldownCondition::sClassNameUID;
    qword_1423B2198 = (__int64)InPlaceInit<CooldownCondition>::InPlaceNew;
    dword_1423B21A0 = ReceivedStimulusCondition::sClassNameUID;
    qword_1423B21A8 = (__int64)InPlaceInit<ReceivedStimulusCondition>::InPlaceNew;
    dword_1423B21B0 = IsOnScreenCondition::sClassNameUID;
    qword_1423B21B8 = (__int64)InPlaceInit<IsOnScreenCondition>::InPlaceNew;
    dword_1423B21C0 = IsAtRangePreferenceCondition::sClassNameUID;
    qword_1423B21C8 = (__int64)InPlaceInit<IsAtRangePreferenceCondition>::InPlaceNew;
    dword_1423B21D0 = SkookumCondition::sClassNameUID;
    qword_1423B21D8 = (__int64)InPlaceInit<SkookumCondition>::InPlaceNew;
    dword_1423B21E0 = HasRangedWeaponEquippedWithAmmoCondition::sClassNameUID;
    qword_1423B21E8 = (__int64)InPlaceInit<HasRangedWeaponEquippedWithAmmoCondition>::InPlaceNew;
    dword_1423B21F0 = AiBehaviourCondition::sClassNameUID;
    qword_1423B21F8 = (__int64)InPlaceInit<AiBehaviourCondition>::InPlaceNew;
    dword_1423B2200 = FalseCondition::sClassNameUID;
    qword_1423B2208 = (__int64)InPlaceInit<FalseCondition>::InPlaceNew;
    dword_1423B2210 = NotCondition::sClassNameUID;
    qword_1423B2218 = (__int64)InPlaceInit<NotCondition>::InPlaceNew;
    dword_1423B2220 = ORCondition::sClassNameUID;
    qword_1423B2228 = (__int64)InPlaceInit<ORCondition>::InPlaceNew;
    dword_1423B2230 = DebugTestCondition::sClassNameUID;
    qword_1423B2238 = (__int64)InPlaceInit<DebugTestCondition>::InPlaceNew;
    dword_1423B2240 = NodeRequestCondition::sClassNameUID;
    qword_1423B2248 = (__int64)InPlaceInit<NodeRequestCondition>::InPlaceNew;
    dword_1423B2250 = NodeRequestAnyCondition::sClassNameUID;
    qword_1423B2258 = (__int64)InPlaceInit<NodeRequestAnyCondition>::InPlaceNew;
    dword_1423B2260 = PrintCondition::sClassNameUID;
    qword_1423B2268 = (__int64)InPlaceInit<PrintCondition>::InPlaceNew;
    dword_1423B2270 = FacialRequestCondition::sClassNameUID;
    qword_1423B2278 = (__int64)InPlaceInit<FacialRequestCondition>::InPlaceNew;
    dword_1423B2280 = ActionRequestCondition::sClassNameUID;
    qword_1423B2288 = (__int64)InPlaceInit<ActionRequestCondition>::InPlaceNew;
    dword_1423B2290 = QueryCondition::sClassNameUID;
    qword_1423B2298 = (__int64)InPlaceInit<QueryCondition>::InPlaceNew;
    dword_1423B22A0 = IsPlayingCondition::sClassNameUID;
    qword_1423B22A8 = (__int64)InPlaceInit<IsPlayingCondition>::InPlaceNew;
    dword_1423B22B0 = IsPlayingThisCondition::sClassNameUID;
    qword_1423B22B8 = (__int64)InPlaceInit<IsPlayingThisCondition>::InPlaceNew;
    dword_1423B22C0 = IsPlayingThisInPathCondition::sClassNameUID;
    qword_1423B22C8 = (__int64)InPlaceInit<IsPlayingThisInPathCondition>::InPlaceNew;
    dword_1423B22D0 = IsPlayingNodeCondition::sClassNameUID;
    qword_1423B22D8 = (__int64)InPlaceInit<IsPlayingNodeCondition>::InPlaceNew;
    dword_1423B22E0 = IsPlayingPreviousCondition::sClassNameUID;
    qword_1423B22E8 = (__int64)InPlaceInit<IsPlayingPreviousCondition>::InPlaceNew;
    dword_1423B22F0 = IsPlayingNodePreviousCondition::sClassNameUID;
    qword_1423B22F8 = (__int64)InPlaceInit<IsPlayingNodePreviousCondition>::InPlaceNew;
    dword_1423B2300 = IsPlayingNextCondition::sClassNameUID;
    qword_1423B2308 = (__int64)InPlaceInit<IsPlayingNextCondition>::InPlaceNew;
    dword_1423B2310 = IsHostCondition::sClassNameUID;
    qword_1423B2318 = (__int64)InPlaceInit<IsHostCondition>::InPlaceNew;
    dword_1423B2320 = IsPlayerCondition::sClassNameUID;
    qword_1423B2328 = (__int64)InPlaceInit<IsPlayerCondition>::InPlaceNew;
    dword_1423B2330 = IsPlayerInClothingStore::sClassNameUID;
    qword_1423B2338 = (__int64)InPlaceInit<IsPlayerInClothingStore>::InPlaceNew;
    dword_1423B2340 = ClothingPurchaseCondition::sClassNameUID;
    qword_1423B2348 = (__int64)InPlaceInit<ClothingPurchaseCondition>::InPlaceNew;
    dword_1423B2350 = IsPlayerInBerserkModeCondition::sClassNameUID;
    qword_1423B2358 = (__int64)InPlaceInit<IsPlayerInBerserkModeCondition>::InPlaceNew;
    dword_1423B2360 = IsPlayerInCombatBuffModeCondition::sClassNameUID;
    qword_1423B2368 = (__int64)InPlaceInit<IsPlayerInCombatBuffModeCondition>::InPlaceNew;
    dword_1423B2370 = IsTakingDamageCondition::sClassNameUID;
    qword_1423B2378 = (__int64)InPlaceInit<IsTakingDamageCondition>::InPlaceNew;
    dword_1423B2380 = IsInvulnerableCondition::sClassNameUID;
    qword_1423B2388 = (__int64)InPlaceInit<IsInvulnerableCondition>::InPlaceNew;
    dword_1423B2390 = IsFemaleCondition::sClassNameUID;
    qword_1423B2398 = (__int64)InPlaceInit<IsFemaleCondition>::InPlaceNew;
    dword_1423B23A0 = TargetIsFemaleCondition::sClassNameUID;
    qword_1423B23A8 = (__int64)InPlaceInit<TargetIsFemaleCondition>::InPlaceNew;
    dword_1423B23B0 = PlayerIsInSpecificInterior::sClassNameUID;
    qword_1423B23B8 = (__int64)InPlaceInit<PlayerIsInSpecificInterior>::InPlaceNew;
    dword_1423B23C0 = IsCriticalPriorityCondition::sClassNameUID;
    qword_1423B23C8 = (__int64)InPlaceInit<IsCriticalPriorityCondition>::InPlaceNew;
    dword_1423B23D0 = IsSpawningCondition::sClassNameUID;
    qword_1423B23D8 = (__int64)InPlaceInit<IsSpawningCondition>::InPlaceNew;
    dword_1423B23E0 = IsSkippingIntoPOICondition::sClassNameUID;
    qword_1423B23E8 = (__int64)InPlaceInit<IsSkippingIntoPOICondition>::InPlaceNew;
    dword_1423B23F0 = HasRagdollCondition::sClassNameUID;
    qword_1423B23F8 = (__int64)InPlaceInit<HasRagdollCondition>::InPlaceNew;
    dword_1423B2400 = RagdollHasConstraintsCondition::sClassNameUID;
    qword_1423B2408 = (__int64)InPlaceInit<RagdollHasConstraintsCondition>::InPlaceNew;
    dword_1423B2410 = IsDLCMoveUnlockedCondition::sClassNameUID;
    qword_1423B2418 = (__int64)InPlaceInit<IsDLCMoveUnlockedCondition>::InPlaceNew;
    dword_1423B2420 = IsPossessedPedModeEnabledCondition::sClassNameUID;
    qword_1423B2428 = (__int64)InPlaceInit<IsPossessedPedModeEnabledCondition>::InPlaceNew;
    dword_1423B2430 = AmIPossessedCondition::sClassNameUID;
    qword_1423B2438 = (__int64)InPlaceInit<AmIPossessedCondition>::InPlaceNew;
    dword_1423B2440 = IsNavigationControlledCondition::sClassNameUID;
    qword_1423B2448 = (__int64)InPlaceInit<IsNavigationControlledCondition>::InPlaceNew;
    dword_1423B2450 = NumCollectiblesCollectedCondition::sClassNameUID;
    qword_1423B2458 = (__int64)InPlaceInit<NumCollectiblesCollectedCondition>::InPlaceNew;
    dword_1423B2460 = TargetAimingDirectionCondition::sClassNameUID;
    qword_1423B2468 = (__int64)InPlaceInit<TargetAimingDirectionCondition>::InPlaceNew;
    dword_1423B2470 = ActiveProgressionFlowCondition::sClassNameUID;
    qword_1423B2478 = (__int64)InPlaceInit<ActiveProgressionFlowCondition>::InPlaceNew;
    dword_1423B2480 = WasBittenCondition::sClassNameUID;
    qword_1423B2488 = (__int64)InPlaceInit<WasBittenCondition>::InPlaceNew;
    dword_1423B2490 = AiBehaviourCondition::sClassNameUID;
    qword_1423B2498 = (__int64)InPlaceInit<AiBehaviourCondition>::InPlaceNew;
    dword_1423B24A0 = AiBehaviourTreeTypeCondition::sClassNameUID;
    qword_1423B24A8 = (__int64)InPlaceInit<AiBehaviourTreeTypeCondition>::InPlaceNew;
    dword_1423B24B0 = AiEmotionCondition::sClassNameUID;
    qword_1423B24B8 = (__int64)InPlaceInit<AiEmotionCondition>::InPlaceNew;
    dword_1423B24C0 = FacialEmotionCondition::sClassNameUID;
    qword_1423B24C8 = (__int64)InPlaceInit<FacialEmotionCondition>::InPlaceNew;
    dword_1423B24D0 = CharacterPhysicsCondition::sClassNameUID;
    qword_1423B24D8 = (__int64)InPlaceInit<CharacterPhysicsCondition>::InPlaceNew;
    dword_1423B24E0 = MotionIntentionDirection::sClassNameUID;
    qword_1423B24E8 = (__int64)InPlaceInit<MotionIntentionDirection>::InPlaceNew;
    dword_1423B24F0 = MotionIntentionDirectionRaw::sClassNameUID;
    qword_1423B24F8 = (__int64)InPlaceInit<MotionIntentionDirectionRaw>::InPlaceNew;
    dword_1423B2500 = MotionIntentionDirectionRel::sClassNameUID;
    qword_1423B2508 = (__int64)InPlaceInit<MotionIntentionDirectionRel>::InPlaceNew;
    dword_1423B2510 = MotionIntentionDirectionRelTarget::sClassNameUID;
    qword_1423B2518 = (__int64)InPlaceInit<MotionIntentionDirectionRelTarget>::InPlaceNew;
    dword_1423B2520 = MotionIntentionSpeed::sClassNameUID;
    qword_1423B2528 = (__int64)InPlaceInit<MotionIntentionSpeed>::InPlaceNew;
    dword_1423B2530 = MotionIntentionSpeedRaw::sClassNameUID;
    qword_1423B2538 = (__int64)InPlaceInit<MotionIntentionSpeedRaw>::InPlaceNew;
    dword_1423B2540 = MotionVelocityMagnitude::sClassNameUID;
    qword_1423B2548 = (__int64)InPlaceInit<MotionVelocityMagnitude>::InPlaceNew;
    dword_1423B2550 = MotionAngularVelocityMagnitude::sClassNameUID;
    qword_1423B2558 = (__int64)InPlaceInit<MotionAngularVelocityMagnitude>::InPlaceNew;
    dword_1423B2560 = MotionRotationSignal::sClassNameUID;
    qword_1423B2568 = (__int64)InPlaceInit<MotionRotationSignal>::InPlaceNew;
    dword_1423B2570 = MotionPhase::sClassNameUID;
    qword_1423B2578 = (__int64)InPlaceInit<MotionPhase>::InPlaceNew;
    dword_1423B2580 = FootStepLeftCondition::sClassNameUID;
    qword_1423B2588 = (__int64)InPlaceInit<FootStepLeftCondition>::InPlaceNew;
    dword_1423B2590 = FootStepRightCondition::sClassNameUID;
    qword_1423B2598 = (__int64)InPlaceInit<FootStepRightCondition>::InPlaceNew;
    dword_1423B25A0 = AnimationFrameCondition::sClassNameUID;
    qword_1423B25A8 = (__int64)InPlaceInit<AnimationFrameCondition>::InPlaceNew;
    dword_1423B25B0 = FacingIntentionDirection::sClassNameUID;
    qword_1423B25B8 = (__int64)InPlaceInit<FacingIntentionDirection>::InPlaceNew;
    dword_1423B25C0 = FacingPelvisDirection::sClassNameUID;
    qword_1423B25C8 = (__int64)InPlaceInit<FacingPelvisDirection>::InPlaceNew;
    dword_1423B25D0 = AimIntentionRangeCondition::sClassNameUID;
    qword_1423B25D8 = (__int64)InPlaceInit<AimIntentionRangeCondition>::InPlaceNew;
    dword_1423B25E0 = AimIntentionAngleCondition::sClassNameUID;
    qword_1423B25E8 = (__int64)InPlaceInit<AimIntentionAngleCondition>::InPlaceNew;
    dword_1423B25F0 = AimIntentionSpeedCondition::sClassNameUID;
    qword_1423B25F8 = (__int64)InPlaceInit<AimIntentionSpeedCondition>::InPlaceNew;
    dword_1423B2600 = OnGround::sClassNameUID;
    qword_1423B2608 = (__int64)InPlaceInit<OnGround>::InPlaceNew;
    dword_1423B2610 = OnGroundSurfaceType::sClassNameUID;
    qword_1423B2618 = (__int64)InPlaceInit<OnGroundSurfaceType>::InPlaceNew;
    dword_1423B2620 = OnGroundSurfaceGrade::sClassNameUID;
    qword_1423B2628 = (__int64)InPlaceInit<OnGroundSurfaceGrade>::InPlaceNew;
    dword_1423B2630 = DropoffCondition::sClassNameUID;
    qword_1423B2638 = (__int64)InPlaceInit<DropoffCondition>::InPlaceNew;
    dword_1423B2640 = ParkourSphereCastCondition::sClassNameUID;
    qword_1423B2648 = (__int64)InPlaceInit<ParkourSphereCastCondition>::InPlaceNew;
    dword_1423B2650 = ParkourHandleInfoCondition::sClassNameUID;
    qword_1423B2658 = (__int64)InPlaceInit<ParkourHandleInfoCondition>::InPlaceNew;
    dword_1423B2660 = ParkourHandleLatchedCloseToEdgeCondition::sClassNameUID;
    qword_1423B2668 = (__int64)InPlaceInit<ParkourHandleLatchedCloseToEdgeCondition>::InPlaceNew;
    dword_1423B2670 = ParkourHandleOwnerIsCondition::sClassNameUID;
    qword_1423B2678 = (__int64)InPlaceInit<ParkourHandleOwnerIsCondition>::InPlaceNew;
    dword_1423B2680 = ParkourHandleSpeedCondition::sClassNameUID;
    qword_1423B2688 = (__int64)InPlaceInit<ParkourHandleSpeedCondition>::InPlaceNew;
    dword_1423B2690 = SphereCastCondition::sClassNameUID;
    qword_1423B2698 = (__int64)InPlaceInit<SphereCastCondition>::InPlaceNew;
    dword_1423B26A0 = BrokenVehicleGlassSphereCastCondition::sClassNameUID;
    qword_1423B26A8 = (__int64)InPlaceInit<BrokenVehicleGlassSphereCastCondition>::InPlaceNew;
    dword_1423B26B0 = GroundDistance::sClassNameUID;
    qword_1423B26B8 = (__int64)InPlaceInit<GroundDistance>::InPlaceNew;
    dword_1423B26C0 = HealthCondition::sClassNameUID;
    qword_1423B26C8 = (__int64)InPlaceInit<HealthCondition>::InPlaceNew;
    dword_1423B26D0 = HealthClampedToMinimumCondition::sClassNameUID;
    qword_1423B26D8 = (__int64)InPlaceInit<HealthClampedToMinimumCondition>::InPlaceNew;
    dword_1423B26E0 = ConditionGroup::sClassNameUID;
    qword_1423B26E8 = (__int64)InPlaceInit<ConditionGroup>::InPlaceNew;
    dword_1423B26F0 = ParkourHandleCondition::sClassNameUID;
    qword_1423B26F8 = (__int64)InPlaceInit<ParkourHandleCondition>::InPlaceNew;
    dword_1423B2700 = CombatRegionExistsCondition::sClassNameUID;
    qword_1423B2708 = (__int64)InPlaceInit<CombatRegionExistsCondition>::InPlaceNew;
    dword_1423B2710 = CombatRegionIsInsideCondition::sClassNameUID;
    qword_1423B2718 = (__int64)InPlaceInit<CombatRegionIsInsideCondition>::InPlaceNew;
    dword_1423B2720 = CombatRegionTargetIsInsideCondition::sClassNameUID;
    qword_1423B2728 = (__int64)InPlaceInit<CombatRegionTargetIsInsideCondition>::InPlaceNew;
    dword_1423B2730 = CoverIsInCoverZoneCondition::sClassNameUID;
    qword_1423B2738 = (__int64)InPlaceInit<CoverIsInCoverZoneCondition>::InPlaceNew;
    dword_1423B2740 = CoverPositionsEquivalentCondition::sClassNameUID;
    qword_1423B2748 = (__int64)InPlaceInit<CoverPositionsEquivalentCondition>::InPlaceNew;
    dword_1423B2750 = CoverProbeForCoverZoneCondition::sClassNameUID;
    qword_1423B2758 = (__int64)InPlaceInit<CoverProbeForCoverZoneCondition>::InPlaceNew;
    dword_1423B2760 = CoverDirectionCondition::sClassNameUID;
    qword_1423B2768 = (__int64)InPlaceInit<CoverDirectionCondition>::InPlaceNew;
    dword_1423B2770 = CoverHeightCondition::sClassNameUID;
    qword_1423B2778 = (__int64)InPlaceInit<CoverHeightCondition>::InPlaceNew;
    dword_1423B2780 = CoverTypeCondition::sClassNameUID;
    qword_1423B2788 = (__int64)InPlaceInit<CoverTypeCondition>::InPlaceNew;
    dword_1423B2790 = CoverCanTraverseInDirectionCondition::sClassNameUID;
    qword_1423B2798 = (__int64)InPlaceInit<CoverCanTraverseInDirectionCondition>::InPlaceNew;
    dword_1423B27A0 = AICoverIsValidCondition::sClassNameUID;
    qword_1423B27A8 = (__int64)InPlaceInit<AICoverIsValidCondition>::InPlaceNew;
    dword_1423B27B0 = AICoverTargetIsLatched::sClassNameUID;
    qword_1423B27B8 = (__int64)InPlaceInit<AICoverTargetIsLatched>::InPlaceNew;
    dword_1423B27C0 = AICoverFiringPositionClear::sClassNameUID;
    qword_1423B27C8 = (__int64)InPlaceInit<AICoverFiringPositionClear>::InPlaceNew;
    dword_1423B27D0 = DestructionDamageCondition::sClassNameUID;
    qword_1423B27D8 = (__int64)InPlaceInit<DestructionDamageCondition>::InPlaceNew;
    dword_1423B27E0 = DestructionFractureCondition::sClassNameUID;
    qword_1423B27E8 = (__int64)InPlaceInit<DestructionFractureCondition>::InPlaceNew;
    dword_1423B27F0 = HitTime::sClassNameUID;
    qword_1423B27F8 = (__int64)InPlaceInit<HitTime>::InPlaceNew;
    dword_1423B2800 = HitRecordProcessingCondition::sClassNameUID;
    qword_1423B2808 = (__int64)InPlaceInit<HitRecordProcessingCondition>::InPlaceNew;
    dword_1423B2810 = HitRecordBerserkAttackFlagCondition::sClassNameUID;
    qword_1423B2818 = (__int64)InPlaceInit<HitRecordBerserkAttackFlagCondition>::InPlaceNew;
    dword_1423B2820 = AttackType::sClassNameUID;
    qword_1423B2828 = (__int64)InPlaceInit<AttackType>::InPlaceNew;
    dword_1423B2830 = AttackLocationLateral::sClassNameUID;
    qword_1423B2838 = (__int64)InPlaceInit<AttackLocationLateral>::InPlaceNew;
    dword_1423B2840 = AttackLocationHorizontal::sClassNameUID;
    qword_1423B2848 = (__int64)InPlaceInit<AttackLocationHorizontal>::InPlaceNew;
    dword_1423B2850 = AttackLocationRagdoll::sClassNameUID;
    qword_1423B2858 = (__int64)InPlaceInit<AttackLocationRagdoll>::InPlaceNew;
    dword_1423B2860 = AttackIntensityCondition::sClassNameUID;
    qword_1423B2868 = (__int64)InPlaceInit<AttackIntensityCondition>::InPlaceNew;
    dword_1423B2870 = AttackDamageCondition::sClassNameUID;
    qword_1423B2878 = (__int64)InPlaceInit<AttackDamageCondition>::InPlaceNew;
    dword_1423B2880 = AttackTimerCondition::sClassNameUID;
    qword_1423B2888 = (__int64)InPlaceInit<AttackTimerCondition>::InPlaceNew;
    dword_1423B2890 = AttackPhaseCondition::sClassNameUID;
    qword_1423B2898 = (__int64)InPlaceInit<AttackPhaseCondition>::InPlaceNew;
    dword_1423B28A0 = AttackInfoNumberHitsCondition::sClassNameUID;
    qword_1423B28A8 = (__int64)InPlaceInit<AttackInfoNumberHitsCondition>::InPlaceNew;
    dword_1423B28B0 = HitLocation::sClassNameUID;
    qword_1423B28B8 = (__int64)InPlaceInit<HitLocation>::InPlaceNew;
    dword_1423B28C0 = HitImpulse::sClassNameUID;
    qword_1423B28C8 = (__int64)InPlaceInit<HitImpulse>::InPlaceNew;
    dword_1423B28D0 = HitLocationTargettedCondition::sClassNameUID;
    qword_1423B28D8 = (__int64)InPlaceInit<HitLocationTargettedCondition>::InPlaceNew;
    dword_1423B28E0 = HitProjectileReactionCondition::sClassNameUID;
    qword_1423B28E8 = (__int64)InPlaceInit<HitProjectileReactionCondition>::InPlaceNew;
    dword_1423B28F0 = HitProjectileWeaponTypeCondition::sClassNameUID;
    qword_1423B28F8 = (__int64)InPlaceInit<HitProjectileWeaponTypeCondition>::InPlaceNew;
    dword_1423B2900 = HitProjectileWeaponInventoryTypeCondition::sClassNameUID;
    qword_1423B2908 = (__int64)InPlaceInit<HitProjectileWeaponInventoryTypeCondition>::InPlaceNew;
    dword_1423B2910 = HitProjectileIsExplosiveCondition::sClassNameUID;
    qword_1423B2918 = (__int64)InPlaceInit<HitProjectileIsExplosiveCondition>::InPlaceNew;
    dword_1423B2920 = HitDistanceFromExplosionCondition::sClassNameUID;
    qword_1423B2928 = (__int64)InPlaceInit<HitDistanceFromExplosionCondition>::InPlaceNew;
    dword_1423B2930 = HitExplosionCanTriggerVehicleExplosion::sClassNameUID;
    qword_1423B2938 = (__int64)InPlaceInit<HitExplosionCanTriggerVehicleExplosion>::InPlaceNew;
    dword_1423B2940 = CollisionTime::sClassNameUID;
    qword_1423B2948 = (__int64)InPlaceInit<CollisionTime>::InPlaceNew;
    dword_1423B2950 = CollisionSpeed::sClassNameUID;
    qword_1423B2958 = (__int64)InPlaceInit<CollisionSpeed>::InPlaceNew;
    dword_1423B2960 = CollisionEstimatedImpulseMagnitude::sClassNameUID;
    qword_1423B2968 = (__int64)InPlaceInit<CollisionEstimatedImpulseMagnitude>::InPlaceNew;
    dword_1423B2970 = CollisionLayer::sClassNameUID;
    qword_1423B2978 = (__int64)InPlaceInit<CollisionLayer>::InPlaceNew;
    dword_1423B2980 = CollisionMass::sClassNameUID;
    qword_1423B2988 = (__int64)InPlaceInit<CollisionMass>::InPlaceNew;
    dword_1423B2990 = HitCollisionVelocityRelativeToNormal::sClassNameUID;
    qword_1423B2998 = (__int64)InPlaceInit<HitCollisionVelocityRelativeToNormal>::InPlaceNew;
    dword_1423B29A0 = TargetDistance::sClassNameUID;
    qword_1423B29A8 = (__int64)InPlaceInit<TargetDistance>::InPlaceNew;
    dword_1423B29B0 = TargetDistanceRelativeDesiredRangeCondition::sClassNameUID;
    qword_1423B29B8 = (__int64)InPlaceInit<TargetDistanceRelativeDesiredRangeCondition>::InPlaceNew;
    dword_1423B29C0 = TargetCloserThanTargetCondition::sClassNameUID;
    qword_1423B29C8 = (__int64)InPlaceInit<TargetCloserThanTargetCondition>::InPlaceNew;
    dword_1423B29D0 = TargetConditionGroup::sClassNameUID;
    qword_1423B29D8 = (__int64)InPlaceInit<TargetConditionGroup>::InPlaceNew;
    dword_1423B29E0 = TargetRelativePosition::sClassNameUID;
    qword_1423B29E8 = (__int64)InPlaceInit<TargetRelativePosition>::InPlaceNew;
    dword_1423B29F0 = TargetRelativeOrientationCondition::sClassNameUID;
    qword_1423B29F8 = (__int64)InPlaceInit<TargetRelativeOrientationCondition>::InPlaceNew;
    dword_1423B2A00 = TargetValidCondition::sClassNameUID;
    qword_1423B2A08 = (__int64)InPlaceInit<TargetValidCondition>::InPlaceNew;
    dword_1423B2A10 = TargetIsEqualCondition::sClassNameUID;
    qword_1423B2A18 = (__int64)InPlaceInit<TargetIsEqualCondition>::InPlaceNew;
    dword_1423B2A20 = TargetInventoryItemCondition::sClassNameUID;
    qword_1423B2A28 = (__int64)InPlaceInit<TargetInventoryItemCondition>::InPlaceNew;
    dword_1423B2A30 = TargetSimObjectTypeCondition::sClassNameUID;
    qword_1423B2A38 = (__int64)InPlaceInit<TargetSimObjectTypeCondition>::InPlaceNew;
    dword_1423B2A40 = TargetSimObjectBooleanCondition::sClassNameUID;
    qword_1423B2A48 = (__int64)InPlaceInit<TargetSimObjectBooleanCondition>::InPlaceNew;
    dword_1423B2A50 = TargetSimObjectWeaponTypeCondition::sClassNameUID;
    qword_1423B2A58 = (__int64)InPlaceInit<TargetSimObjectWeaponTypeCondition>::InPlaceNew;
    dword_1423B2A60 = TargetSimObjectWeaponAmmoInventoryItemCondition::sClassNameUID;
    qword_1423B2A68 = (__int64)InPlaceInit<TargetSimObjectWeaponAmmoInventoryItemCondition>::InPlaceNew;
    dword_1423B2A70 = TargetSimObjectWeaponBooleanCondition::sClassNameUID;
    qword_1423B2A78 = (__int64)InPlaceInit<TargetSimObjectWeaponBooleanCondition>::InPlaceNew;
    dword_1423B2A80 = TargetSimObjectWeaponAmmoCondition::sClassNameUID;
    qword_1423B2A88 = (__int64)InPlaceInit<TargetSimObjectWeaponAmmoCondition>::InPlaceNew;
    dword_1423B2A90 = TargetSimObjectVehicleTypeCondition::sClassNameUID;
    qword_1423B2A98 = (__int64)InPlaceInit<TargetSimObjectVehicleTypeCondition>::InPlaceNew;
    dword_1423B2AA0 = SimObjectVehicleTypeCondition::sClassNameUID;
    qword_1423B2AA8 = (__int64)InPlaceInit<SimObjectVehicleTypeCondition>::InPlaceNew;
    dword_1423B2AB0 = TargetSimObjectBoatTypeCondition::sClassNameUID;
    qword_1423B2AB8 = (__int64)InPlaceInit<TargetSimObjectBoatTypeCondition>::InPlaceNew;
    dword_1423B2AC0 = TargetSimObjectCharacterBooleanCondition::sClassNameUID;
    qword_1423B2AC8 = (__int64)InPlaceInit<TargetSimObjectCharacterBooleanCondition>::InPlaceNew;
    dword_1423B2AD0 = SimObjectCharacterBooleanCondition::sClassNameUID;
    qword_1423B2AD8 = (__int64)InPlaceInit<SimObjectCharacterBooleanCondition>::InPlaceNew;
    dword_1423B2AE0 = SimObjectBoatTypeCondition::sClassNameUID;
    qword_1423B2AE8 = (__int64)InPlaceInit<SimObjectBoatTypeCondition>::InPlaceNew;
    dword_1423B2AF0 = TargetIsPlayingCondition::sClassNameUID;
    qword_1423B2AF8 = (__int64)InPlaceInit<TargetIsPlayingCondition>::InPlaceNew;
    dword_1423B2B00 = TargetIsLockedCondition::sClassNameUID;
    qword_1423B2B08 = (__int64)InPlaceInit<TargetIsLockedCondition>::InPlaceNew;
    dword_1423B2B10 = TargetVelocityRelativeToCollisionCondition::sClassNameUID;
    qword_1423B2B18 = (__int64)InPlaceInit<TargetVelocityRelativeToCollisionCondition>::InPlaceNew;
    dword_1423B2B20 = TargetPhysicalMassCondition::sClassNameUID;
    qword_1423B2B28 = (__int64)InPlaceInit<TargetPhysicalMassCondition>::InPlaceNew;
    dword_1423B2B30 = TargetPhysicalCollisionLayerCondition::sClassNameUID;
    qword_1423B2B38 = (__int64)InPlaceInit<TargetPhysicalCollisionLayerCondition>::InPlaceNew;
    dword_1423B2B40 = TargetPhysicalAttackShootComboCondition::sClassNameUID;
    qword_1423B2B48 = (__int64)InPlaceInit<TargetPhysicalAttackShootComboCondition>::InPlaceNew;
    dword_1423B2B50 = TargetPhysicalAttackVelocityCondition::sClassNameUID;
    qword_1423B2B58 = (__int64)InPlaceInit<TargetPhysicalAttackVelocityCondition>::InPlaceNew;
    dword_1423B2B60 = TargetPhysicalDamageMultiplierCondition::sClassNameUID;
    qword_1423B2B68 = (__int64)InPlaceInit<TargetPhysicalDamageMultiplierCondition>::InPlaceNew;
    dword_1423B2B70 = TargetPhysicalDodgeableCondition::sClassNameUID;
    qword_1423B2B78 = (__int64)InPlaceInit<TargetPhysicalDodgeableCondition>::InPlaceNew;
    dword_1423B2B80 = TargetPhysicalMeleeAttackableCondition::sClassNameUID;
    qword_1423B2B88 = (__int64)InPlaceInit<TargetPhysicalMeleeAttackableCondition>::InPlaceNew;
    dword_1423B2B90 = TargetIsSubTargetValid::sClassNameUID;
    qword_1423B2B98 = (__int64)InPlaceInit<TargetIsSubTargetValid>::InPlaceNew;
    dword_1423B2BA0 = TargetPropInteractAvailableCondition::sClassNameUID;
    qword_1423B2BA8 = (__int64)InPlaceInit<TargetPropInteractAvailableCondition>::InPlaceNew;
    dword_1423B2BB0 = TargetPropInteractOrientationCondition::sClassNameUID;
    qword_1423B2BB8 = (__int64)InPlaceInit<TargetPropInteractOrientationCondition>::InPlaceNew;
    dword_1423B2BC0 = TargetParkourHandleCondition::sClassNameUID;
    qword_1423B2BC8 = (__int64)InPlaceInit<TargetParkourHandleCondition>::InPlaceNew;
    dword_1423B2BD0 = TargetIsEnemyOfMineCondition::sClassNameUID;
    qword_1423B2BD8 = (__int64)InPlaceInit<TargetIsEnemyOfMineCondition>::InPlaceNew;
    dword_1423B2BE0 = TargetWeaponAmmoCompatibleCondition::sClassNameUID;
    qword_1423B2BE8 = (__int64)InPlaceInit<TargetWeaponAmmoCompatibleCondition>::InPlaceNew;
    dword_1423B2BF0 = TargetedByTypeCondition::sClassNameUID;
    qword_1423B2BF8 = (__int64)InPlaceInit<TargetedByTypeCondition>::InPlaceNew;
    dword_1423B2C00 = IsTargetsTargetCondition::sClassNameUID;
    qword_1423B2C08 = (__int64)InPlaceInit<IsTargetsTargetCondition>::InPlaceNew;
    dword_1423B2C10 = TargetInventoryCheckPropertyCondition::sClassNameUID;
    qword_1423B2C18 = (__int64)InPlaceInit<TargetInventoryCheckPropertyCondition>::InPlaceNew;
    dword_1423B2C20 = TargetPurchaseItemFailCondition::sClassNameUID;
    qword_1423B2C28 = (__int64)InPlaceInit<TargetPurchaseItemFailCondition>::InPlaceNew;
    dword_1423B2C30 = PurchasableItemAvailableCondition::sClassNameUID;
    qword_1423B2C38 = (__int64)InPlaceInit<PurchasableItemAvailableCondition>::InPlaceNew;
    dword_1423B2C40 = InteractionPointFindBestCondition::sClassNameUID;
    qword_1423B2C48 = (__int64)InPlaceInit<InteractionPointFindBestCondition>::InPlaceNew;
    dword_1423B2C50 = InteractionPointValidCondition::sClassNameUID;
    qword_1423B2C58 = (__int64)InPlaceInit<InteractionPointValidCondition>::InPlaceNew;
    dword_1423B2C60 = InteractionPointIsAccessable::sClassNameUID;
    qword_1423B2C68 = (__int64)InPlaceInit<InteractionPointIsAccessable>::InPlaceNew;
    dword_1423B2C70 = InteractionPointIsBestBusyCondition::sClassNameUID;
    qword_1423B2C78 = (__int64)InPlaceInit<InteractionPointIsBestBusyCondition>::InPlaceNew;
    dword_1423B2C80 = InteractionPointIsBestOfTypeCondition::sClassNameUID;
    qword_1423B2C88 = (__int64)InPlaceInit<InteractionPointIsBestOfTypeCondition>::InPlaceNew;
    dword_1423B2C90 = IfTargetsInteractionPointNotBusySetBestCondition::sClassNameUID;
    qword_1423B2C98 = (__int64)InPlaceInit<IfTargetsInteractionPointNotBusySetBestCondition>::InPlaceNew;
    dword_1423B2CA0 = InventoryQuantityCondition::sClassNameUID;
    qword_1423B2CA8 = (__int64)InPlaceInit<InventoryQuantityCondition>::InPlaceNew;
    dword_1423B2CB0 = InventoryIsItemEquipped::sClassNameUID;
    qword_1423B2CB8 = (__int64)InPlaceInit<InventoryIsItemEquipped>::InPlaceNew;
    dword_1423B2CC0 = InventoryCanDrop::sClassNameUID;
    qword_1423B2CC8 = (__int64)InPlaceInit<InventoryCanDrop>::InPlaceNew;
    dword_1423B2CD0 = InventoryCheckPropertyCondition::sClassNameUID;
    qword_1423B2CD8 = (__int64)InPlaceInit<InventoryCheckPropertyCondition>::InPlaceNew;
    dword_1423B2CE0 = RandomCondition::sClassNameUID;
    qword_1423B2CE8 = (__int64)InPlaceInit<RandomCondition>::InPlaceNew;
    dword_1423B2CF0 = PersonalityTypeCondition::sClassNameUID;
    qword_1423B2CF8 = (__int64)InPlaceInit<PersonalityTypeCondition>::InPlaceNew;
    dword_1423B2D00 = SpeedCondition::sClassNameUID;
    qword_1423B2D08 = (__int64)InPlaceInit<SpeedCondition>::InPlaceNew;
    dword_1423B2D10 = MinigameSuccessCondition::sClassNameUID;
    qword_1423B2D18 = (__int64)InPlaceInit<MinigameSuccessCondition>::InPlaceNew;
    dword_1423B2D20 = TargetIsSittingConversationCondition::sClassNameUID;
    qword_1423B2D28 = (__int64)InPlaceInit<TargetIsSittingConversationCondition>::InPlaceNew;
    dword_1423B2D30 = VehicleBurnoutCondition::sClassNameUID;
    qword_1423B2D38 = (__int64)InPlaceInit<VehicleBurnoutCondition>::InPlaceNew;
    dword_1423B2D40 = VehicleWheelieCondition::sClassNameUID;
    qword_1423B2D48 = (__int64)InPlaceInit<VehicleWheelieCondition>::InPlaceNew;
    dword_1423B2D50 = VehicleOneEightyCondition::sClassNameUID;
    qword_1423B2D58 = (__int64)InPlaceInit<VehicleOneEightyCondition>::InPlaceNew;
    dword_1423B2D60 = VehicleHandbrakeCondition::sClassNameUID;
    qword_1423B2D68 = (__int64)InPlaceInit<VehicleHandbrakeCondition>::InPlaceNew;
    dword_1423B2D70 = VehicleSpeedCondition::sClassNameUID;
    qword_1423B2D78 = (__int64)InPlaceInit<VehicleSpeedCondition>::InPlaceNew;
    dword_1423B2D80 = VehicleCollisionShouldTriggerExplosion::sClassNameUID;
    qword_1423B2D88 = (__int64)InPlaceInit<VehicleCollisionShouldTriggerExplosion>::InPlaceNew;
    dword_1423B2D90 = VehicleIsRammingCondition::sClassNameUID;
    qword_1423B2D98 = (__int64)InPlaceInit<VehicleIsRammingCondition>::InPlaceNew;
    dword_1423B2DA0 = VehicleIsWreckedCondition::sClassNameUID;
    qword_1423B2DA8 = (__int64)InPlaceInit<VehicleIsWreckedCondition>::InPlaceNew;
    dword_1423B2DB0 = VehicleAngularSpeedCondition::sClassNameUID;
    qword_1423B2DB8 = (__int64)InPlaceInit<VehicleAngularSpeedCondition>::InPlaceNew;
    dword_1423B2DC0 = VehicleVectorCompareCondition::sClassNameUID;
    qword_1423B2DC8 = (__int64)InPlaceInit<VehicleVectorCompareCondition>::InPlaceNew;
    dword_1423B2DD0 = VehicleOffGroundCondition::sClassNameUID;
    qword_1423B2DD8 = (__int64)InPlaceInit<VehicleOffGroundCondition>::InPlaceNew;
    dword_1423B2DE0 = VehicleUntargetableCondition::sClassNameUID;
    qword_1423B2DE8 = (__int64)InPlaceInit<VehicleUntargetableCondition>::InPlaceNew;
    dword_1423B2DF0 = VehicleInDeepWaterCondition::sClassNameUID;
    qword_1423B2DF8 = (__int64)InPlaceInit<VehicleInDeepWaterCondition>::InPlaceNew;
    dword_1423B2E00 = VehicleDoorAngleCondition::sClassNameUID;
    qword_1423B2E08 = (__int64)InPlaceInit<VehicleDoorAngleCondition>::InPlaceNew;
    dword_1423B2E10 = VehicleOccupantHasActiveRoleCondition::sClassNameUID;
    qword_1423B2E18 = (__int64)InPlaceInit<VehicleOccupantHasActiveRoleCondition>::InPlaceNew;
    dword_1423B2E20 = VehicleOccupantIsPassengerCondition::sClassNameUID;
    qword_1423B2E28 = (__int64)InPlaceInit<VehicleOccupantIsPassengerCondition>::InPlaceNew;
    dword_1423B2E30 = VehicleOccupantIsInBoatCondition::sClassNameUID;
    qword_1423B2E38 = (__int64)InPlaceInit<VehicleOccupantIsInBoatCondition>::InPlaceNew;
    dword_1423B2E40 = VehicleOccupantIsInSinkingBoatCondition::sClassNameUID;
    qword_1423B2E48 = (__int64)InPlaceInit<VehicleOccupantIsInSinkingBoatCondition>::InPlaceNew;
    dword_1423B2E50 = VehicleOccupantTypeCondition::sClassNameUID;
    qword_1423B2E58 = (__int64)InPlaceInit<VehicleOccupantTypeCondition>::InPlaceNew;
    dword_1423B2E60 = IsOccupantOfTargetVehicleCondition::sClassNameUID;
    qword_1423B2E68 = (__int64)InPlaceInit<IsOccupantOfTargetVehicleCondition>::InPlaceNew;
    dword_1423B2E70 = VehicleOrientationCondition::sClassNameUID;
    qword_1423B2E78 = (__int64)InPlaceInit<VehicleOrientationCondition>::InPlaceNew;
    dword_1423B2E80 = IsBoatInsideWorldCondition::sClassNameUID;
    qword_1423B2E88 = (__int64)InPlaceInit<IsBoatInsideWorldCondition>::InPlaceNew;
    dword_1423B2E90 = TargetVehicleOrientationCondition::sClassNameUID;
    qword_1423B2E98 = (__int64)InPlaceInit<TargetVehicleOrientationCondition>::InPlaceNew;
    dword_1423B2EA0 = TargetVehicleDoorsLockedCondition::sClassNameUID;
    qword_1423B2EA8 = (__int64)InPlaceInit<TargetVehicleDoorsLockedCondition>::InPlaceNew;
    dword_1423B2EB0 = VehicleWheelSurfaceCondition::sClassNameUID;
    qword_1423B2EB8 = (__int64)InPlaceInit<VehicleWheelSurfaceCondition>::InPlaceNew;
    dword_1423B2EC0 = CharacterSurfaceCondition::sClassNameUID;
    qword_1423B2EC8 = (__int64)InPlaceInit<CharacterSurfaceCondition>::InPlaceNew;
    dword_1423B2ED0 = VehicleWindowBrokenCondition::sClassNameUID;
    qword_1423B2ED8 = (__int64)InPlaceInit<VehicleWindowBrokenCondition>::InPlaceNew;
    dword_1423B2EE0 = TargetVehicleWindowBrokenCondition::sClassNameUID;
    qword_1423B2EE8 = (__int64)InPlaceInit<TargetVehicleWindowBrokenCondition>::InPlaceNew;
    dword_1423B2EF0 = VehicleNumberOfTiresDamagedCondition::sClassNameUID;
    qword_1423B2EF8 = (__int64)InPlaceInit<VehicleNumberOfTiresDamagedCondition>::InPlaceNew;
    dword_1423B2F00 = VehicleEngineRipeForTakedownCondition::sClassNameUID;
    qword_1423B2F08 = (__int64)InPlaceInit<VehicleEngineRipeForTakedownCondition>::InPlaceNew;
    dword_1423B2F10 = VehicleDamageCondition::sClassNameUID;
    qword_1423B2F18 = (__int64)InPlaceInit<VehicleDamageCondition>::InPlaceNew;
    dword_1423B2F20 = VehicleHasDriverOrPassengerOccupantCondition::sClassNameUID;
    qword_1423B2F28 = (__int64)InPlaceInit<VehicleHasDriverOrPassengerOccupantCondition>::InPlaceNew;
    dword_1423B2F30 = VehicleDeniesAllyDriverCondition::sClassNameUID;
    qword_1423B2F38 = (__int64)InPlaceInit<VehicleDeniesAllyDriverCondition>::InPlaceNew;
    dword_1423B2F40 = VehicleDeniesAllyPassengerCondition::sClassNameUID;
    qword_1423B2F48 = (__int64)InPlaceInit<VehicleDeniesAllyPassengerCondition>::InPlaceNew;
    dword_1423B2F50 = VehicleDeniesGetInPassengerSideCondition::sClassNameUID;
    qword_1423B2F58 = (__int64)InPlaceInit<VehicleDeniesGetInPassengerSideCondition>::InPlaceNew;
    dword_1423B2F60 = VehicleDeniesGetInDriverSideCondition::sClassNameUID;
    qword_1423B2F68 = (__int64)InPlaceInit<VehicleDeniesGetInDriverSideCondition>::InPlaceNew;
    dword_1423B2F70 = VehicleDeniesHijackCondition::sClassNameUID;
    qword_1423B2F78 = (__int64)InPlaceInit<VehicleDeniesHijackCondition>::InPlaceNew;
    dword_1423B2F80 = VehicleAimingShotBlockedCondition::sClassNameUID;
    qword_1423B2F88 = (__int64)InPlaceInit<VehicleAimingShotBlockedCondition>::InPlaceNew;
    dword_1423B2F90 = VehicleCanActionHijackCondition::sClassNameUID;
    qword_1423B2F98 = (__int64)InPlaceInit<VehicleCanActionHijackCondition>::InPlaceNew;
    dword_1423B2FA0 = VehicleCanActionHijackClimbCondition::sClassNameUID;
    qword_1423B2FA8 = (__int64)InPlaceInit<VehicleCanActionHijackClimbCondition>::InPlaceNew;
    dword_1423B2FB0 = VehicleCanOpenDoorCondition::sClassNameUID;
    qword_1423B2FB8 = (__int64)InPlaceInit<VehicleCanOpenDoorCondition>::InPlaceNew;
    dword_1423B2FC0 = VehicleBoxSideCondition::sClassNameUID;
    qword_1423B2FC8 = (__int64)InPlaceInit<VehicleBoxSideCondition>::InPlaceNew;
    dword_1423B2FD0 = VehicleDirectlyBehindCondition::sClassNameUID;
    qword_1423B2FD8 = (__int64)InPlaceInit<VehicleDirectlyBehindCondition>::InPlaceNew;
    dword_1423B2FE0 = DriverProfileTypeCondition::sClassNameUID;
    qword_1423B2FE8 = (__int64)InPlaceInit<DriverProfileTypeCondition>::InPlaceNew;
    dword_1423B2FF0 = CharacterTypeCondition::sClassNameUID;
    qword_1423B2FF8 = (__int64)InPlaceInit<CharacterTypeCondition>::InPlaceNew;
    dword_1423B3000 = FightingClassCondition::sClassNameUID;
    qword_1423B3008 = (__int64)InPlaceInit<FightingClassCondition>::InPlaceNew;
    dword_1423B3010 = SkookumCondition::sClassNameUID;
    qword_1423B3018 = (__int64)InPlaceInit<SkookumCondition>::InPlaceNew;
    dword_1423B3020 = NumCharactersDeadCondition::sClassNameUID;
    qword_1423B3028 = (__int64)InPlaceInit<NumCharactersDeadCondition>::InPlaceNew;
    dword_1423B3030 = CharacterIsAliveCondition::sClassNameUID;
    qword_1423B3038 = (__int64)InPlaceInit<CharacterIsAliveCondition>::InPlaceNew;
    dword_1423B3040 = ReceivedScriptCommandCondition::sClassNameUID;
    qword_1423B3048 = (__int64)InPlaceInit<ReceivedScriptCommandCondition>::InPlaceNew;
    dword_1423B3050 = ReceivedStimulusCondition::sClassNameUID;
    qword_1423B3058 = (__int64)InPlaceInit<ReceivedStimulusCondition>::InPlaceNew;
    dword_1423B3060 = ReceivedHeatEventCondition::sClassNameUID;
    qword_1423B3068 = (__int64)InPlaceInit<ReceivedHeatEventCondition>::InPlaceNew;
    dword_1423B3070 = AIPlayerInsideAIMeshHeuristicCondition::sClassNameUID;
    qword_1423B3078 = (__int64)InPlaceInit<AIPlayerInsideAIMeshHeuristicCondition>::InPlaceNew;
    dword_1423B3080 = AICopAcquireArrestRightCondition::sClassNameUID;
    qword_1423B3088 = (__int64)InPlaceInit<AICopAcquireArrestRightCondition>::InPlaceNew;
    dword_1423B3090 = AICopIsSoloOnSceneCondition::sClassNameUID;
    qword_1423B3098 = (__int64)InPlaceInit<AICopIsSoloOnSceneCondition>::InPlaceNew;
    dword_1423B30A0 = AICopIsSuspectInsideInteriorCondition::sClassNameUID;
    qword_1423B30A8 = (__int64)InPlaceInit<AICopIsSuspectInsideInteriorCondition>::InPlaceNew;
    dword_1423B30B0 = AICopIsSuspectInWaterCondition::sClassNameUID;
    qword_1423B30B8 = (__int64)InPlaceInit<AICopIsSuspectInWaterCondition>::InPlaceNew;
    dword_1423B30C0 = AICopPlayerInsideUnlockedSafehouseCondition::sClassNameUID;
    qword_1423B30C8 = (__int64)InPlaceInit<AICopPlayerInsideUnlockedSafehouseCondition>::InPlaceNew;
    dword_1423B30D0 = AICopOnFootNoSprintCondition::sClassNameUID;
    qword_1423B30D8 = (__int64)InPlaceInit<AICopOnFootNoSprintCondition>::InPlaceNew;
    dword_1423B30E0 = AICopNumArrestAttemptCondition::sClassNameUID;
    qword_1423B30E8 = (__int64)InPlaceInit<AICopNumArrestAttemptCondition>::InPlaceNew;
    dword_1423B30F0 = AICopHasSuspectOpenedFiredCondition::sClassNameUID;
    qword_1423B30F8 = (__int64)InPlaceInit<AICopHasSuspectOpenedFiredCondition>::InPlaceNew;
    dword_1423B3100 = AICopHasVehicleToDefendCondition::sClassNameUID;
    qword_1423B3108 = (__int64)InPlaceInit<AICopHasVehicleToDefendCondition>::InPlaceNew;
    dword_1423B3110 = AIEncounterRoleCondition::sClassNameUID;
    qword_1423B3118 = (__int64)InPlaceInit<AIEncounterRoleCondition>::InPlaceNew;
    dword_1423B3120 = AIEncounterUnitGotStuckCondition::sClassNameUID;
    qword_1423B3128 = (__int64)InPlaceInit<AIEncounterUnitGotStuckCondition>::InPlaceNew;
    dword_1423B3130 = CanBeginSinglePersonConversationCondition::sClassNameUID;
    qword_1423B3138 = (__int64)InPlaceInit<CanBeginSinglePersonConversationCondition>::InPlaceNew;
    dword_1423B3140 = CollisionAvoidanceIsActiveCondition::sClassNameUID;
    qword_1423B3148 = (__int64)InPlaceInit<CollisionAvoidanceIsActiveCondition>::InPlaceNew;
    dword_1423B3150 = HasAnyDangerousEntitiesOrPointsCondition::sClassNameUID;
    qword_1423B3158 = (__int64)InPlaceInit<HasAnyDangerousEntitiesOrPointsCondition>::InPlaceNew;
    dword_1423B3160 = HasRangedWeaponEquippedWithAmmoCondition::sClassNameUID;
    qword_1423B3168 = (__int64)InPlaceInit<HasRangedWeaponEquippedWithAmmoCondition>::InPlaceNew;
    dword_1423B3170 = OneShotCondition::sClassNameUID;
    qword_1423B3178 = (__int64)InPlaceInit<OneShotCondition>::InPlaceNew;
    dword_1423B3180 = CooldownCondition::sClassNameUID;
    qword_1423B3188 = (__int64)InPlaceInit<CooldownCondition>::InPlaceNew;
    dword_1423B3190 = GlobalCooldownCondition::sClassNameUID;
    qword_1423B3198 = (__int64)InPlaceInit<GlobalCooldownCondition>::InPlaceNew;
    dword_1423B31A0 = RandomStartTimeCondition::sClassNameUID;
    qword_1423B31A8 = (__int64)InPlaceInit<RandomStartTimeCondition>::InPlaceNew;
    dword_1423B31B0 = AIObjectiveAnyCondition::sClassNameUID;
    qword_1423B31B8 = (__int64)InPlaceInit<AIObjectiveAnyCondition>::InPlaceNew;
    dword_1423B31C0 = AIObjectiveCondition::sClassNameUID;
    qword_1423B31C8 = (__int64)InPlaceInit<AIObjectiveCondition>::InPlaceNew;
    dword_1423B31D0 = AIObjectiveIsHostileCondition::sClassNameUID;
    qword_1423B31D8 = (__int64)InPlaceInit<AIObjectiveIsHostileCondition>::InPlaceNew;
    dword_1423B31E0 = AIOnMeshCondition::sClassNameUID;
    qword_1423B31E8 = (__int64)InPlaceInit<AIOnMeshCondition>::InPlaceNew;
    dword_1423B31F0 = AIAtDestinationCondition::sClassNameUID;
    qword_1423B31F8 = (__int64)InPlaceInit<AIAtDestinationCondition>::InPlaceNew;
    dword_1423B3200 = AIHasValidPathCondition::sClassNameUID;
    qword_1423B3208 = (__int64)InPlaceInit<AIHasValidPathCondition>::InPlaceNew;
    dword_1423B3210 = AIDestinationObstructedCondition::sClassNameUID;
    qword_1423B3218 = (__int64)InPlaceInit<AIDestinationObstructedCondition>::InPlaceNew;
    dword_1423B3220 = POIUseTypeCondition::sClassNameUID;
    qword_1423B3228 = (__int64)InPlaceInit<POIUseTypeCondition>::InPlaceNew;
    dword_1423B3230 = HasRequestedSpeechCondition::sClassNameUID;
    qword_1423B3238 = (__int64)InPlaceInit<HasRequestedSpeechCondition>::InPlaceNew;
    dword_1423B3240 = HasRemainingLinesCondition::sClassNameUID;
    qword_1423B3248 = (__int64)InPlaceInit<HasRemainingLinesCondition>::InPlaceNew;
    dword_1423B3250 = HasScriptedConversationCondition::sClassNameUID;
    qword_1423B3258 = (__int64)InPlaceInit<HasScriptedConversationCondition>::InPlaceNew;
    dword_1423B3260 = HasActiveConversationCondition::sClassNameUID;
    qword_1423B3268 = (__int64)InPlaceInit<HasActiveConversationCondition>::InPlaceNew;
    dword_1423B3270 = ConversationFinishedCondition::sClassNameUID;
    qword_1423B3278 = (__int64)InPlaceInit<ConversationFinishedCondition>::InPlaceNew;
    dword_1423B3280 = ConversationIsListeningCondition::sClassNameUID;
    qword_1423B3288 = (__int64)InPlaceInit<ConversationIsListeningCondition>::InPlaceNew;
    dword_1423B3290 = ConversationIsSpeakingCondition::sClassNameUID;
    qword_1423B3298 = (__int64)InPlaceInit<ConversationIsSpeakingCondition>::InPlaceNew;
    dword_1423B32A0 = IsSpeakingCondition::sClassNameUID;
    qword_1423B32A8 = (__int64)InPlaceInit<IsSpeakingCondition>::InPlaceNew;
    dword_1423B32B0 = ConversationHasActionRequestsCondition::sClassNameUID;
    qword_1423B32B8 = (__int64)InPlaceInit<ConversationHasActionRequestsCondition>::InPlaceNew;
    dword_1423B32C0 = FailedSpeechCondition::sClassNameUID;
    qword_1423B32C8 = (__int64)InPlaceInit<FailedSpeechCondition>::InPlaceNew;
    dword_1423B32D0 = HasSpecificSpeechAnimationCondition::sClassNameUID;
    qword_1423B32D8 = (__int64)InPlaceInit<HasSpecificSpeechAnimationCondition>::InPlaceNew;
    dword_1423B32E0 = TargetDistanceHysteresis::sClassNameUID;
    qword_1423B32E8 = (__int64)InPlaceInit<TargetDistanceHysteresis>::InPlaceNew;
    dword_1423B32F0 = TargetVisibleCondition::sClassNameUID;
    qword_1423B32F8 = (__int64)InPlaceInit<TargetVisibleCondition>::InPlaceNew;
    dword_1423B3300 = TargetVisibleInAIDataCondition::sClassNameUID;
    qword_1423B3308 = (__int64)InPlaceInit<TargetVisibleInAIDataCondition>::InPlaceNew;
    dword_1423B3310 = OpportunityAttackCooldownCondition::sClassNameUID;
    qword_1423B3318 = (__int64)InPlaceInit<OpportunityAttackCooldownCondition>::InPlaceNew;
    dword_1423B3320 = TimeWarpCondition::sClassNameUID;
    qword_1423B3328 = (__int64)InPlaceInit<TimeWarpCondition>::InPlaceNew;
    dword_1423B3330 = TimeOfDayCondition::sClassNameUID;
    qword_1423B3338 = (__int64)InPlaceInit<TimeOfDayCondition>::InPlaceNew;
    dword_1423B3340 = HasClothingBuffCondition::sClassNameUID;
    qword_1423B3348 = (__int64)InPlaceInit<HasClothingBuffCondition>::InPlaceNew;
    dword_1423B3350 = FaceActionRequestCondition::sClassNameUID;
    qword_1423B3358 = (__int64)InPlaceInit<FaceActionRequestCondition>::InPlaceNew;
    dword_1423B3360 = FaceActionAvailableCondition::sClassNameUID;
    qword_1423B3368 = (__int64)InPlaceInit<FaceActionAvailableCondition>::InPlaceNew;
    dword_1423B3370 = SocialSetEvaluatedCondition::sClassNameUID;
    qword_1423B3378 = (__int64)InPlaceInit<SocialSetEvaluatedCondition>::InPlaceNew;
    dword_1423B3380 = SocialABKsLoadedCondition::sClassNameUID;
    qword_1423B3388 = (__int64)InPlaceInit<SocialABKsLoadedCondition>::InPlaceNew;
    dword_1423B3390 = SocialFaceActionEnabledCondition::sClassNameUID;
    qword_1423B3398 = (__int64)InPlaceInit<SocialFaceActionEnabledCondition>::InPlaceNew;
    dword_1423B33A0 = SocialFaceActionRequiresGreetCondition::sClassNameUID;
    qword_1423B33A8 = (__int64)InPlaceInit<SocialFaceActionRequiresGreetCondition>::InPlaceNew;
    dword_1423B33B0 = SocialFaceActionAutoChargeCondition::sClassNameUID;
    qword_1423B33B8 = (__int64)InPlaceInit<SocialFaceActionAutoChargeCondition>::InPlaceNew;
    dword_1423B33C0 = SocialFaceActionUseConfirmationDialogCondition::sClassNameUID;
    qword_1423B33C8 = (__int64)InPlaceInit<SocialFaceActionUseConfirmationDialogCondition>::InPlaceNew;
    dword_1423B33D0 = SocialFaceActionGetConfirmationDialogConfirmedCondition::sClassNameUID;
    qword_1423B33D8 = (__int64)InPlaceInit<SocialFaceActionGetConfirmationDialogConfirmedCondition>::InPlaceNew;
    dword_1423B33E0 = UISocialChargeHappenedCondition::sClassNameUID;
    qword_1423B33E8 = (__int64)InPlaceInit<UISocialChargeHappenedCondition>::InPlaceNew;
    dword_1423B33F0 = SocialGreetSuccessfulCondition::sClassNameUID;
    qword_1423B33F8 = (__int64)InPlaceInit<SocialGreetSuccessfulCondition>::InPlaceNew;
    dword_1423B3400 = SocialChargeSuccessfulCondition::sClassNameUID;
    qword_1423B3408 = (__int64)InPlaceInit<SocialChargeSuccessfulCondition>::InPlaceNew;
    dword_1423B3410 = SocialRequiresFastTalkCondition::sClassNameUID;
    qword_1423B3418 = (__int64)InPlaceInit<SocialRequiresFastTalkCondition>::InPlaceNew;
    dword_1423B3420 = SocialRequiresInteractionPointSyncCondition::sClassNameUID;
    qword_1423B3428 = (__int64)InPlaceInit<SocialRequiresInteractionPointSyncCondition>::InPlaceNew;
    dword_1423B3430 = SocialRequiresInteractionAreaCheckCondition::sClassNameUID;
    qword_1423B3438 = (__int64)InPlaceInit<SocialRequiresInteractionAreaCheckCondition>::InPlaceNew;
    dword_1423B3440 = SocialCombatFastTalkSucceededCondition::sClassNameUID;
    qword_1423B3448 = (__int64)InPlaceInit<SocialCombatFastTalkSucceededCondition>::InPlaceNew;
    dword_1423B3450 = SocialFastTalkOccurredCondition::sClassNameUID;
    qword_1423B3458 = (__int64)InPlaceInit<SocialFastTalkOccurredCondition>::InPlaceNew;
    dword_1423B3460 = SocialFaceActionStateCondition::sClassNameUID;
    qword_1423B3468 = (__int64)InPlaceInit<SocialFaceActionStateCondition>::InPlaceNew;
    dword_1423B3470 = SocialIsTargetStandingSufficientCondition::sClassNameUID;
    qword_1423B3478 = (__int64)InPlaceInit<SocialIsTargetStandingSufficientCondition>::InPlaceNew;
    dword_1423B3480 = FactionClassCondition::sClassNameUID;
    qword_1423B3488 = (__int64)InPlaceInit<FactionClassCondition>::InPlaceNew;
    dword_1423B3490 = CollectibleIsCollectedCondition::sClassNameUID;
    qword_1423B3498 = (__int64)InPlaceInit<CollectibleIsCollectedCondition>::InPlaceNew;
    dword_1423B34A0 = IsTargetingStandingCondition::sClassNameUID;
    qword_1423B34A8 = (__int64)InPlaceInit<IsTargetingStandingCondition>::InPlaceNew;
    dword_1423B34B0 = IsExcludedFromScoring::sClassNameUID;
    qword_1423B34B8 = (__int64)InPlaceInit<IsExcludedFromScoring>::InPlaceNew;
    dword_1423B34C0 = IsFactionStandingCondition::sClassNameUID;
    qword_1423B34C8 = (__int64)InPlaceInit<IsFactionStandingCondition>::InPlaceNew;
    dword_1423B34D0 = IsTargetsTargetFactionStandingCondition::sClassNameUID;
    qword_1423B34D8 = (__int64)InPlaceInit<IsTargetsTargetFactionStandingCondition>::InPlaceNew;
    dword_1423B34E0 = ScriptFakeHasHostageCondition::sClassNameUID;
    qword_1423B34E8 = (__int64)InPlaceInit<ScriptFakeHasHostageCondition>::InPlaceNew;
    dword_1423B34F0 = CanWanderCondition::sClassNameUID;
    qword_1423B34F8 = (__int64)InPlaceInit<CanWanderCondition>::InPlaceNew;
    dword_1423B3500 = FaceMeterActivatedCondition::sClassNameUID;
    qword_1423B3508 = (__int64)InPlaceInit<FaceMeterActivatedCondition>::InPlaceNew;
    dword_1423B3510 = FaceMeterCondition::sClassNameUID;
    qword_1423B3518 = (__int64)InPlaceInit<FaceMeterCondition>::InPlaceNew;
    dword_1423B3520 = PipLevelCondition::sClassNameUID;
    qword_1423B3528 = (__int64)InPlaceInit<PipLevelCondition>::InPlaceNew;
    dword_1423B3530 = IncomingAttackPhaseCondition::sClassNameUID;
    qword_1423B3538 = (__int64)InPlaceInit<IncomingAttackPhaseCondition>::InPlaceNew;
    dword_1423B3540 = IncomingAttackTypeCondition::sClassNameUID;
    qword_1423B3548 = (__int64)InPlaceInit<IncomingAttackTypeCondition>::InPlaceNew;
    dword_1423B3550 = IncomingAttackLocationLateralCondition::sClassNameUID;
    qword_1423B3558 = (__int64)InPlaceInit<IncomingAttackLocationLateralCondition>::InPlaceNew;
    dword_1423B3560 = IncomingAttackLocationHorizontalCondition::sClassNameUID;
    qword_1423B3568 = (__int64)InPlaceInit<IncomingAttackLocationHorizontalCondition>::InPlaceNew;
    dword_1423B3570 = AnimationBankRequestCondition::sClassNameUID;
    qword_1423B3578 = (__int64)InPlaceInit<AnimationBankRequestCondition>::InPlaceNew;
    dword_1423B3580 = AnimationRequiredIsLoadedCondition::sClassNameUID;
    qword_1423B3588 = (__int64)InPlaceInit<AnimationRequiredIsLoadedCondition>::InPlaceNew;
    dword_1423B3590 = ResourceIsAvailableCondition::sClassNameUID;
    qword_1423B3598 = (__int64)InPlaceInit<ResourceIsAvailableCondition>::InPlaceNew;
    dword_1423B35A0 = ObjectIsAvailableCondition::sClassNameUID;
    qword_1423B35A8 = (__int64)InPlaceInit<ObjectIsAvailableCondition>::InPlaceNew;
    dword_1423B35B0 = TargetPOIIsValidCondition::sClassNameUID;
    qword_1423B35B8 = (__int64)InPlaceInit<TargetPOIIsValidCondition>::InPlaceNew;
    dword_1423B35C0 = TargetPOIRequiresSyncCondition::sClassNameUID;
    qword_1423B35C8 = (__int64)InPlaceInit<TargetPOIRequiresSyncCondition>::InPlaceNew;
    dword_1423B35D0 = TargetPOISyncRequiredCondition::sClassNameUID;
    qword_1423B35D8 = (__int64)InPlaceInit<TargetPOISyncRequiredCondition>::InPlaceNew;
    dword_1423B35E0 = TargetPOIAllowsSocialCondition::sClassNameUID;
    qword_1423B35E8 = (__int64)InPlaceInit<TargetPOIAllowsSocialCondition>::InPlaceNew;
    dword_1423B35F0 = CarModeCondition::sClassNameUID;
    qword_1423B35F8 = (__int64)InPlaceInit<CarModeCondition>::InPlaceNew;
    dword_1423B3600 = CarEscortMode::sClassNameUID;
    qword_1423B3608 = (__int64)InPlaceInit<CarEscortMode>::InPlaceNew;
    dword_1423B3610 = CarAtOffset::sClassNameUID;
    qword_1423B3618 = (__int64)InPlaceInit<CarAtOffset>::InPlaceNew;
    dword_1423B3620 = CarAttackStat::sClassNameUID;
    qword_1423B3628 = (__int64)InPlaceInit<CarAttackStat>::InPlaceNew;
    dword_1423B3630 = CarLastAttack::sClassNameUID;
    qword_1423B3638 = (__int64)InPlaceInit<CarLastAttack>::InPlaceNew;
    dword_1423B3640 = CarWithinRange::sClassNameUID;
    qword_1423B3648 = (__int64)InPlaceInit<CarWithinRange>::InPlaceNew;
    dword_1423B3650 = CarFormationAvailable::sClassNameUID;
    qword_1423B3658 = (__int64)InPlaceInit<CarFormationAvailable>::InPlaceNew;
    dword_1423B3660 = CarFormationAssignedPosition::sClassNameUID;
    qword_1423B3668 = (__int64)InPlaceInit<CarFormationAssignedPosition>::InPlaceNew;
    dword_1423B3670 = CarAtFormation::sClassNameUID;
    qword_1423B3678 = (__int64)InPlaceInit<CarAtFormation>::InPlaceNew;
    dword_1423B3680 = CarFormationTimeout::sClassNameUID;
    qword_1423B3688 = (__int64)InPlaceInit<CarFormationTimeout>::InPlaceNew;
    dword_1423B3690 = CarFormationNumChasers::sClassNameUID;
    qword_1423B3698 = (__int64)InPlaceInit<CarFormationNumChasers>::InPlaceNew;
    dword_1423B36A0 = CarFormationNumChasersInRange::sClassNameUID;
    qword_1423B36A8 = (__int64)InPlaceInit<CarFormationNumChasersInRange>::InPlaceNew;
    dword_1423B36B0 = CarFormationAttackStat::sClassNameUID;
    qword_1423B36B8 = (__int64)InPlaceInit<CarFormationAttackStat>::InPlaceNew;
    dword_1423B36C0 = CarDistanceToEscortEnemy::sClassNameUID;
    qword_1423B36C8 = (__int64)InPlaceInit<CarDistanceToEscortEnemy>::InPlaceNew;
    dword_1423B36D0 = CarLastFormationAttack::sClassNameUID;
    qword_1423B36D8 = (__int64)InPlaceInit<CarLastFormationAttack>::InPlaceNew;
    dword_1423B36E0 = CarFormationIsCustom::sClassNameUID;
    qword_1423B36E8 = (__int64)InPlaceInit<CarFormationIsCustom>::InPlaceNew;
    dword_1423B36F0 = CarOccupantHasGun::sClassNameUID;
    qword_1423B36F8 = (__int64)InPlaceInit<CarOccupantHasGun>::InPlaceNew;
    dword_1423B3700 = CarOccupantHasTarget::sClassNameUID;
    qword_1423B3708 = (__int64)InPlaceInit<CarOccupantHasTarget>::InPlaceNew;
    dword_1423B3710 = CarOccupantTargetInFrustum::sClassNameUID;
    qword_1423B3718 = (__int64)InPlaceInit<CarOccupantTargetInFrustum>::InPlaceNew;
    dword_1423B3720 = CarIsRacing::sClassNameUID;
    qword_1423B3728 = (__int64)InPlaceInit<CarIsRacing>::InPlaceNew;
    dword_1423B3730 = CarRacingLongerThan::sClassNameUID;
    qword_1423B3738 = (__int64)InPlaceInit<CarRacingLongerThan>::InPlaceNew;
    dword_1423B3740 = CarRoleCondition::sClassNameUID;
    qword_1423B3748 = (__int64)InPlaceInit<CarRoleCondition>::InPlaceNew;
    dword_1423B3750 = CarCanShoveCargo::sClassNameUID;
    qword_1423B3758 = (__int64)InPlaceInit<CarCanShoveCargo>::InPlaceNew;
    dword_1423B3760 = VehicleTrunkTypeCondition::sClassNameUID;
    qword_1423B3768 = (__int64)InPlaceInit<VehicleTrunkTypeCondition>::InPlaceNew;
    dword_1423B3770 = VehicleInTrafficJamCondition::sClassNameUID;
    qword_1423B3778 = (__int64)InPlaceInit<VehicleInTrafficJamCondition>::InPlaceNew;
    dword_1423B3780 = VehicleIsAvoidingCondition::sClassNameUID;
    qword_1423B3788 = (__int64)InPlaceInit<VehicleIsAvoidingCondition>::InPlaceNew;
    dword_1423B3790 = VehicleIsParkedCondition::sClassNameUID;
    qword_1423B3798 = (__int64)InPlaceInit<VehicleIsParkedCondition>::InPlaceNew;
    dword_1423B37A0 = VehicleIsParkedWithDriverCondition::sClassNameUID;
    qword_1423B37A8 = (__int64)InPlaceInit<VehicleIsParkedWithDriverCondition>::InPlaceNew;
    dword_1423B37B0 = VehicleNumberOfPassengersCondition::sClassNameUID;
    qword_1423B37B8 = (__int64)InPlaceInit<VehicleNumberOfPassengersCondition>::InPlaceNew;
    dword_1423B37C0 = TransitDistanceToGoalLocationCondition::sClassNameUID;
    qword_1423B37C8 = (__int64)InPlaceInit<TransitDistanceToGoalLocationCondition>::InPlaceNew;
    dword_1423B37D0 = HasAIDriverCondition::sClassNameUID;
    qword_1423B37D8 = (__int64)InPlaceInit<HasAIDriverCondition>::InPlaceNew;
    dword_1423B37E0 = DriverFlagAvoidPedsCondition::sClassNameUID;
    qword_1423B37E8 = (__int64)InPlaceInit<DriverFlagAvoidPedsCondition>::InPlaceNew;
    dword_1423B37F0 = DriverFlagAllowedToPassCondition::sClassNameUID;
    qword_1423B37F8 = (__int64)InPlaceInit<DriverFlagAllowedToPassCondition>::InPlaceNew;
    dword_1423B3800 = DriverFlagStayOffSidewalkCondition::sClassNameUID;
    qword_1423B3808 = (__int64)InPlaceInit<DriverFlagStayOffSidewalkCondition>::InPlaceNew;
    dword_1423B3810 = DriverFlagRespectSpeedLimitCondition::sClassNameUID;
    qword_1423B3818 = (__int64)InPlaceInit<DriverFlagRespectSpeedLimitCondition>::InPlaceNew;
    dword_1423B3820 = ActionDefLeanBackCondition::sClassNameUID;
    qword_1423B3828 = (__int64)InPlaceInit<ActionDefLeanBackCondition>::InPlaceNew;
    dword_1423B3830 = PlayerMeleeUpgradeCondition::sClassNameUID;
    qword_1423B3838 = (__int64)InPlaceInit<PlayerMeleeUpgradeCondition>::InPlaceNew;
    dword_1423B3840 = PlayerGunplayUpgradeCondition::sClassNameUID;
    qword_1423B3848 = (__int64)InPlaceInit<PlayerGunplayUpgradeCondition>::InPlaceNew;
    dword_1423B3850 = PlayerCopUpgradeCondition::sClassNameUID;
    qword_1423B3858 = (__int64)InPlaceInit<PlayerCopUpgradeCondition>::InPlaceNew;
    dword_1423B3860 = PlayerTriadUpgradeCondition::sClassNameUID;
    qword_1423B3868 = (__int64)InPlaceInit<PlayerTriadUpgradeCondition>::InPlaceNew;
    dword_1423B3870 = StruggleCondition::sClassNameUID;
    qword_1423B3878 = (__int64)InPlaceInit<StruggleCondition>::InPlaceNew;
    dword_1423B3880 = InputSignalCondition::sClassNameUID;
    qword_1423B3888 = (__int64)InPlaceInit<InputSignalCondition>::InPlaceNew;
    dword_1423B3890 = WantToUsePOICondition::sClassNameUID;
    qword_1423B3898 = (__int64)InPlaceInit<WantToUsePOICondition>::InPlaceNew;
    dword_1423B38A0 = POIParentObjectHasOwner::sClassNameUID;
    qword_1423B38A8 = (__int64)InPlaceInit<POIParentObjectHasOwner>::InPlaceNew;
    dword_1423B38B0 = POIIsTimingOut::sClassNameUID;
    qword_1423B38B8 = (__int64)InPlaceInit<POIIsTimingOut>::InPlaceNew;
    dword_1423B38C0 = POIIgnoreStimuliCondition::sClassNameUID;
    qword_1423B38C8 = (__int64)InPlaceInit<POIIgnoreStimuliCondition>::InPlaceNew;
    dword_1423B38D0 = POIWeatherFilterOnWithIsRainingCondition::sClassNameUID;
    qword_1423B38D8 = (__int64)InPlaceInit<POIWeatherFilterOnWithIsRainingCondition>::InPlaceNew;
    dword_1423B38E0 = PlayerHeatLevelCondition::sClassNameUID;
    qword_1423B38E8 = (__int64)InPlaceInit<PlayerHeatLevelCondition>::InPlaceNew;
    dword_1423B38F0 = PlayerHeatLevelTimerCondition::sClassNameUID;
    qword_1423B38F8 = (__int64)InPlaceInit<PlayerHeatLevelTimerCondition>::InPlaceNew;
    dword_1423B3900 = TargetKnowledgeCondition::sClassNameUID;
    qword_1423B3908 = (__int64)InPlaceInit<TargetKnowledgeCondition>::InPlaceNew;
    dword_1423B3910 = IsOnScreenCondition::sClassNameUID;
    qword_1423B3918 = (__int64)InPlaceInit<IsOnScreenCondition>::InPlaceNew;
    dword_1423B3920 = HasAIAttackerCondition::sClassNameUID;
    qword_1423B3928 = (__int64)InPlaceInit<HasAIAttackerCondition>::InPlaceNew;
    dword_1423B3930 = NumAIAttackersCondition::sClassNameUID;
    qword_1423B3938 = (__int64)InPlaceInit<NumAIAttackersCondition>::InPlaceNew;
    dword_1423B3940 = PlayerIsInCombatCondition::sClassNameUID;
    qword_1423B3948 = (__int64)InPlaceInit<PlayerIsInCombatCondition>::InPlaceNew;
    dword_1423B3950 = PlayerIsInCombatConditionTU::sClassNameUID;
    qword_1423B3958 = (__int64)InPlaceInit<PlayerIsInCombatConditionTU>::InPlaceNew;
    dword_1423B3960 = PlayerIsInCombatWithNumEnemiesCondition::sClassNameUID;
    qword_1423B3968 = (__int64)InPlaceInit<PlayerIsInCombatWithNumEnemiesCondition>::InPlaceNew;
    dword_1423B3970 = IsMultiplayerActiveCondition::sClassNameUID;
    qword_1423B3978 = (__int64)InPlaceInit<IsMultiplayerActiveCondition>::InPlaceNew;
    dword_1423B3980 = IsTiredCondition::sClassNameUID;
    qword_1423B3988 = (__int64)InPlaceInit<IsTiredCondition>::InPlaceNew;
    dword_1423B3990 = CharacterStatIntCondition::sClassNameUID;
    qword_1423B3998 = (__int64)InPlaceInit<CharacterStatIntCondition>::InPlaceNew;
    dword_1423B39A0 = IsPlayingDialogueCondition::sClassNameUID;
    qword_1423B39A8 = (__int64)InPlaceInit<IsPlayingDialogueCondition>::InPlaceNew;
    dword_1423B39B0 = GetInFormationCondition::sClassNameUID;
    qword_1423B39B8 = (__int64)InPlaceInit<GetInFormationCondition>::InPlaceNew;
    dword_1423B39C0 = GetInPedFormationCondition::sClassNameUID;
    qword_1423B39C8 = (__int64)InPlaceInit<GetInPedFormationCondition>::InPlaceNew;
    dword_1423B39D0 = AIIsStandingBetweenAttackerAndTarget::sClassNameUID;
    qword_1423B39D8 = (__int64)InPlaceInit<AIIsStandingBetweenAttackerAndTarget>::InPlaceNew;
    dword_1423B39E0 = NextAttackerCondition::sClassNameUID;
    qword_1423B39E8 = (__int64)InPlaceInit<NextAttackerCondition>::InPlaceNew;
    dword_1423B39F0 = HasAttackRequestCondition::sClassNameUID;
    qword_1423B39F8 = (__int64)InPlaceInit<HasAttackRequestCondition>::InPlaceNew;
    dword_1423B3A00 = IsNextAttackerCondition::sClassNameUID;
    qword_1423B3A08 = (__int64)InPlaceInit<IsNextAttackerCondition>::InPlaceNew;
    dword_1423B3A10 = IsAtRangePreferenceCondition::sClassNameUID;
    qword_1423B3A18 = (__int64)InPlaceInit<IsAtRangePreferenceCondition>::InPlaceNew;
    dword_1423B3A20 = TimeoutCondition::sClassNameUID;
    qword_1423B3A28 = (__int64)InPlaceInit<TimeoutCondition>::InPlaceNew;
    dword_1423B3A30 = RunningAttackCooldownCondition::sClassNameUID;
    qword_1423B3A38 = (__int64)InPlaceInit<RunningAttackCooldownCondition>::InPlaceNew;
    dword_1423B3A40 = TimeToInterceptCondition::sClassNameUID;
    qword_1423B3A48 = (__int64)InPlaceInit<TimeToInterceptCondition>::InPlaceNew;
    dword_1423B3A50 = TargetCanBeAttackedCondition::sClassNameUID;
    qword_1423B3A58 = (__int64)InPlaceInit<TargetCanBeAttackedCondition>::InPlaceNew;
    dword_1423B3A60 = HasPositionToDefendCondition::sClassNameUID;
    qword_1423B3A68 = (__int64)InPlaceInit<HasPositionToDefendCondition>::InPlaceNew;
    dword_1423B3A70 = OutsideOfPositionToDefendCondition::sClassNameUID;
    qword_1423B3A78 = (__int64)InPlaceInit<OutsideOfPositionToDefendCondition>::InPlaceNew;
    dword_1423B3A80 = AbandonPositionToDefendCondition::sClassNameUID;
    qword_1423B3A88 = (__int64)InPlaceInit<AbandonPositionToDefendCondition>::InPlaceNew;
    dword_1423B3A90 = CrouchWhileDefendingPositionCondition::sClassNameUID;
    qword_1423B3A98 = (__int64)InPlaceInit<CrouchWhileDefendingPositionCondition>::InPlaceNew;
    dword_1423B3AA0 = LeaderHasFollowersCondition::sClassNameUID;
    qword_1423B3AA8 = (__int64)InPlaceInit<LeaderHasFollowersCondition>::InPlaceNew;
    dword_1423B3AB0 = TargetSimObjectWeaponCanFireCondition::sClassNameUID;
    qword_1423B3AB8 = (__int64)InPlaceInit<TargetSimObjectWeaponCanFireCondition>::InPlaceNew;
    dword_1423B3AC0 = TargetSimObjectWeaponIsAutomaticCondition::sClassNameUID;
    qword_1423B3AC8 = (__int64)InPlaceInit<TargetSimObjectWeaponIsAutomaticCondition>::InPlaceNew;
    dword_1423B3AD0 = TargetSimObjectWeaponCanReloadCondition::sClassNameUID;
    qword_1423B3AD8 = (__int64)InPlaceInit<TargetSimObjectWeaponCanReloadCondition>::InPlaceNew;
    dword_1423B3AE0 = IsClosestFormationMemberCondition::sClassNameUID;
    qword_1423B3AE8 = (__int64)InPlaceInit<IsClosestFormationMemberCondition>::InPlaceNew;
    dword_1423B3AF0 = StateFlagCondition::sClassNameUID;
    qword_1423B3AF8 = (__int64)InPlaceInit<StateFlagCondition>::InPlaceNew;
    dword_1423B3B00 = IsRainingCondition::sClassNameUID;
    qword_1423B3B08 = (__int64)InPlaceInit<IsRainingCondition>::InPlaceNew;
    dword_1423B3B10 = IsIndoorsCondition::sClassNameUID;
    qword_1423B3B18 = (__int64)InPlaceInit<IsIndoorsCondition>::InPlaceNew;
    dword_1423B3B20 = IsLockboxContainingCondition::sClassNameUID;
    qword_1423B3B28 = (__int64)InPlaceInit<IsLockboxContainingCondition>::InPlaceNew;
    dword_1423B3B30 = IsGroupLeaderCondition::sClassNameUID;
    qword_1423B3B38 = (__int64)InPlaceInit<IsGroupLeaderCondition>::InPlaceNew;
    dword_1423B3B40 = IsGroupFollowerCondition::sClassNameUID;
    qword_1423B3B48 = (__int64)InPlaceInit<IsGroupFollowerCondition>::InPlaceNew;
    dword_1423B3B50 = IsGroupMemberCondition::sClassNameUID;
    qword_1423B3B58 = (__int64)InPlaceInit<IsGroupMemberCondition>::InPlaceNew;
    dword_1423B3B60 = TargetIsGroupLeaderCondition::sClassNameUID;
    qword_1423B3B68 = (__int64)InPlaceInit<TargetIsGroupLeaderCondition>::InPlaceNew;
    dword_1423B3B70 = TargetIsGroupFollowerCondition::sClassNameUID;
    qword_1423B3B78 = (__int64)InPlaceInit<TargetIsGroupFollowerCondition>::InPlaceNew;
    dword_1423B3B80 = TargetIsGroupMemberCondition::sClassNameUID;
    qword_1423B3B88 = (__int64)InPlaceInit<TargetIsGroupMemberCondition>::InPlaceNew;
    dword_1423B3B90 = TargetIsInMyGroupCondition::sClassNameUID;
    qword_1423B3B98 = (__int64)InPlaceInit<TargetIsInMyGroupCondition>::InPlaceNew;
    dword_1423B3BA0 = IsClosestGroupMemberCondition::sClassNameUID;
    qword_1423B3BA8 = (__int64)InPlaceInit<IsClosestGroupMemberCondition>::InPlaceNew;
    dword_1423B3BB0 = NumGroupMemberAliveCondition::sClassNameUID;
    qword_1423B3BB8 = (__int64)InPlaceInit<NumGroupMemberAliveCondition>::InPlaceNew;
    dword_1423B3BC0 = WaterDepth::sClassNameUID;
    qword_1423B3BC8 = (__int64)InPlaceInit<WaterDepth>::InPlaceNew;
    dword_1423B3BD0 = UICameraOverlayExistsCondition::sClassNameUID;
    qword_1423B3BD8 = (__int64)InPlaceInit<UICameraOverlayExistsCondition>::InPlaceNew;
    dword_1423B3BE0 = IsCopCondition::sClassNameUID;
    qword_1423B3BE8 = (__int64)InPlaceInit<IsCopCondition>::InPlaceNew;
    dword_1423B3BF0 = IsCameraCollidingCondition::sClassNameUID;
    qword_1423B3BF8 = (__int64)InPlaceInit<IsCameraCollidingCondition>::InPlaceNew;
    dword_1423B3C00 = IsCameraTypeCondition::sClassNameUID;
    qword_1423B3C08 = (__int64)InPlaceInit<IsCameraTypeCondition>::InPlaceNew;
    dword_1423B3C10 = IsClassTypeCondition::sClassNameUID;
    qword_1423B3C18 = (__int64)InPlaceInit<IsClassTypeCondition>::InPlaceNew;
    dword_1423B3C20 = SelectSuitableVehicleCondition::sClassNameUID;
    qword_1423B3C28 = (__int64)InPlaceInit<SelectSuitableVehicleCondition>::InPlaceNew;
    dword_1423B3C30 = PropertyBooleanCondition::sClassNameUID;
    qword_1423B3C38 = (__int64)InPlaceInit<PropertyBooleanCondition>::InPlaceNew;
    dword_1423B3C40 = PropertyIntegerCondition::sClassNameUID;
    qword_1423B3C48 = (__int64)InPlaceInit<PropertyIntegerCondition>::InPlaceNew;
    dword_1423B3C50 = PropertyFloatCondition::sClassNameUID;
    qword_1423B3C58 = (__int64)InPlaceInit<PropertyFloatCondition>::InPlaceNew;
    dword_1423B3C60 = PropertySymbolCondition::sClassNameUID;
    qword_1423B3C68 = (__int64)InPlaceInit<PropertySymbolCondition>::InPlaceNew;
    dword_1423B3C70 = TargetPropertyBooleanCondition::sClassNameUID;
    qword_1423B3C78 = (__int64)InPlaceInit<TargetPropertyBooleanCondition>::InPlaceNew;
    dword_1423B3C80 = TargetPropertyIntegerCondition::sClassNameUID;
    qword_1423B3C88 = (__int64)InPlaceInit<TargetPropertyIntegerCondition>::InPlaceNew;
    dword_1423B3C90 = TargetPropertyFloatCondition::sClassNameUID;
    qword_1423B3C98 = (__int64)InPlaceInit<TargetPropertyFloatCondition>::InPlaceNew;
    dword_1423B3CA0 = TargetPropertySymbolCondition::sClassNameUID;
    qword_1423B3CA8 = (__int64)InPlaceInit<TargetPropertySymbolCondition>::InPlaceNew;
    dword_1423B3CB0 = IsInCrosswalkCondition::sClassNameUID;
    qword_1423B3CB8 = (__int64)InPlaceInit<IsInCrosswalkCondition>::InPlaceNew;
    dword_1423B3CC0 = GameSliceIsActiveCondition::sClassNameUID;
    qword_1423B3CC8 = (__int64)InPlaceInit<GameSliceIsActiveCondition>::InPlaceNew;
    dword_1423B3CD0 = LastCompletedMissionCondition::sClassNameUID;
    qword_1423B3CD8 = (__int64)InPlaceInit<LastCompletedMissionCondition>::InPlaceNew;
    dword_1423B3CE0 = AttackRequestCanceledCondition::sClassNameUID;
    qword_1423B3CE8 = (__int64)InPlaceInit<AttackRequestCanceledCondition>::InPlaceNew;
    dword_1423B3CF0 = CouldShootSomeoneUnintendedCondition::sClassNameUID;
    qword_1423B3CF8 = (__int64)InPlaceInit<CouldShootSomeoneUnintendedCondition>::InPlaceNew;
    dword_1423B3D00 = IsSocialConversationActiveCondition::sClassNameUID;
    qword_1423B3D08 = (__int64)InPlaceInit<IsSocialConversationActiveCondition>::InPlaceNew;
    dword_1423B3D10 = SocialConversationHasActionRequestsCondition::sClassNameUID;
    qword_1423B3D18 = (__int64)InPlaceInit<SocialConversationHasActionRequestsCondition>::InPlaceNew;
    dword_1423B3D20 = IsOnFireCondition::sClassNameUID;
    qword_1423B3D28 = (__int64)InPlaceInit<IsOnFireCondition>::InPlaceNew;
    dword_1423B3D30 = SimObjectFlagCondition::sClassNameUID;
    qword_1423B3D38 = (__int64)InPlaceInit<SimObjectFlagCondition>::InPlaceNew;
    dword_1423B3D40 = CharacterTypeHasWeaponTypeCondition::sClassNameUID;
    qword_1423B3D48 = (__int64)InPlaceInit<CharacterTypeHasWeaponTypeCondition>::InPlaceNew;
    dword_1423B3D50 = IsNISPlayingCondition::sClassNameUID;
    qword_1423B3D58 = (__int64)InPlaceInit<IsNISPlayingCondition>::InPlaceNew;
    dword_1423B3D60 = IsNISPlayingActionCondition::sClassNameUID;
    qword_1423B3D68 = (__int64)InPlaceInit<IsNISPlayingActionCondition>::InPlaceNew;
    dword_1423B3D70 = IsNISControlledCondition::sClassNameUID;
    qword_1423B3D78 = (__int64)InPlaceInit<IsNISControlledCondition>::InPlaceNew;
    dword_1423B3D80 = IsNISSeamlessInCondition::sClassNameUID;
    qword_1423B3D88 = (__int64)InPlaceInit<IsNISSeamlessInCondition>::InPlaceNew;
    dword_1423B3D90 = IsNISSeamlessOutCondition::sClassNameUID;
    qword_1423B3D98 = (__int64)InPlaceInit<IsNISSeamlessOutCondition>::InPlaceNew;
    dword_1423B3DA0 = IsNISPlayerControllableCondition::sClassNameUID;
    qword_1423B3DA8 = (__int64)InPlaceInit<IsNISPlayerControllableCondition>::InPlaceNew;
    dword_1423B3DB0 = UIPDAStateCondition::sClassNameUID;
    qword_1423B3DB8 = (__int64)InPlaceInit<UIPDAStateCondition>::InPlaceNew;
    dword_1423B3DC0 = UIPDAIsActiveCondition::sClassNameUID;
    qword_1423B3DC8 = (__int64)InPlaceInit<UIPDAIsActiveCondition>::InPlaceNew;
    dword_1423B3DD0 = IsPlayerUsingKeyboardCondition::sClassNameUID;
    qword_1423B3DD8 = (__int64)InPlaceInit<IsPlayerUsingKeyboardCondition>::InPlaceNew;
    dword_1423B3DE0 = PlayerIsInVehicleCondition::sClassNameUID;
    qword_1423B3DE8 = (__int64)InPlaceInit<PlayerIsInVehicleCondition>::InPlaceNew;
    dword_1423B3DF0 = PlayerIsInVehicleTypeCondition::sClassNameUID;
    qword_1423B3DF8 = (__int64)InPlaceInit<PlayerIsInVehicleTypeCondition>::InPlaceNew;
    dword_1423B3E00 = PlayerIsDriverInVehicleCondition::sClassNameUID;
    qword_1423B3E08 = (__int64)InPlaceInit<PlayerIsDriverInVehicleCondition>::InPlaceNew;
    dword_1423B3E10 = PlayerIsDriverInVehicleTypeCondition::sClassNameUID;
    qword_1423B3E18 = (__int64)InPlaceInit<PlayerIsDriverInVehicleTypeCondition>::InPlaceNew;
    dword_1423B3E20 = PlayerIsPassengerInVehicleCondition::sClassNameUID;
    qword_1423B3E28 = (__int64)InPlaceInit<PlayerIsPassengerInVehicleCondition>::InPlaceNew;
    dword_1423B3E30 = PlayerIsPassengerInVehicleTypeCondition::sClassNameUID;
    qword_1423B3E38 = (__int64)InPlaceInit<PlayerIsPassengerInVehicleTypeCondition>::InPlaceNew;
    dword_1423B3E40 = PlayerIsCloseToVehicleTypeCondition::sClassNameUID;
    qword_1423B3E48 = (__int64)InPlaceInit<PlayerIsCloseToVehicleTypeCondition>::InPlaceNew;
    dword_1423B3E50 = PlayerIsCloseToDriverSideOfVehicleTypeCondition::sClassNameUID;
    qword_1423B3E58 = (__int64)InPlaceInit<PlayerIsCloseToDriverSideOfVehicleTypeCondition>::InPlaceNew;
    dword_1423B3E60 = PlayerIsCloseToPassengerSideOfVehicleTypeCondition::sClassNameUID;
    qword_1423B3E68 = (__int64)InPlaceInit<PlayerIsCloseToPassengerSideOfVehicleTypeCondition>::InPlaceNew;
    dword_1423B3E70 = PlayerHasOwnedWeaponTypeCondition::sClassNameUID;
    qword_1423B3E78 = (__int64)InPlaceInit<PlayerHasOwnedWeaponTypeCondition>::InPlaceNew;
    dword_1423B3E80 = PlayerCloseToWeaponTypeCondition::sClassNameUID;
    qword_1423B3E88 = (__int64)InPlaceInit<PlayerCloseToWeaponTypeCondition>::InPlaceNew;
    dword_1423B3E90 = WeaponIsOwnedCondition::sClassNameUID;
    qword_1423B3E98 = (__int64)InPlaceInit<WeaponIsOwnedCondition>::InPlaceNew;
    dword_1423B3EA0 = WeaponIsTargetedForInteractionCondition::sClassNameUID;
    qword_1423B3EA8 = (__int64)InPlaceInit<WeaponIsTargetedForInteractionCondition>::InPlaceNew;
    dword_1423B3EB0 = VehicleHasDriverCondition::sClassNameUID;
    qword_1423B3EB8 = (__int64)InPlaceInit<VehicleHasDriverCondition>::InPlaceNew;
    dword_1423B3EC0 = VehicleHasDriverWithWeaponCondition::sClassNameUID;
    qword_1423B3EC8 = (__int64)InPlaceInit<VehicleHasDriverWithWeaponCondition>::InPlaceNew;
    dword_1423B3ED0 = VehicleHasPassengerCondition::sClassNameUID;
    qword_1423B3ED8 = (__int64)InPlaceInit<VehicleHasPassengerCondition>::InPlaceNew;
    dword_1423B3EE0 = VehicleHasPassengerWithWeaponCondition::sClassNameUID;
    qword_1423B3EE8 = (__int64)InPlaceInit<VehicleHasPassengerWithWeaponCondition>::InPlaceNew;
    dword_1423B3EF0 = VehicleTargetedForInteractionOnFootDriverSideCondition::sClassNameUID;
    qword_1423B3EF8 = (__int64)InPlaceInit<VehicleTargetedForInteractionOnFootDriverSideCondition>::InPlaceNew;
    dword_1423B3F00 = VehicleTargetedForInteractionOnFootPassengerSideCondition::sClassNameUID;
    qword_1423B3F08 = (__int64)InPlaceInit<VehicleTargetedForInteractionOnFootPassengerSideCondition>::InPlaceNew;
    dword_1423B3F10 = VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition::sClassNameUID;
    qword_1423B3F18 = (__int64)InPlaceInit<VehicleTargetedForInteractionOnFootWithWeaponDriverSideCondition>::InPlaceNew;
    dword_1423B3F20 = VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition::sClassNameUID;
    qword_1423B3F28 = (__int64)InPlaceInit<VehicleTargetedForInteractionOnFootWithWeaponPassengerSideCondition>::InPlaceNew;
    dword_1423B3F30 = PredictiveVehicleDriverPotentialInteractionCondition::sClassNameUID;
    qword_1423B3F38 = (__int64)InPlaceInit<PredictiveVehicleDriverPotentialInteractionCondition>::InPlaceNew;
    dword_1423B3F40 = PredictiveVehiclePassengerPotentialInteractionCondition::sClassNameUID;
    qword_1423B3F48 = (__int64)InPlaceInit<PredictiveVehiclePassengerPotentialInteractionCondition>::InPlaceNew;
    dword_1423B3F50 = PredictiveVehiclePlayerPotentialInteractionCondition::sClassNameUID;
    qword_1423B3F58 = (__int64)InPlaceInit<PredictiveVehiclePlayerPotentialInteractionCondition>::InPlaceNew;
    dword_1423B3F60 = PredictiveWeaponPotentialInteractionCondition::sClassNameUID;
    qword_1423B3F68 = (__int64)InPlaceInit<PredictiveWeaponPotentialInteractionCondition>::InPlaceNew;
    dword_1423B3F70 = UELExpressionCondition::sClassNameUID;
    qword_1423B3F78 = (__int64)InPlaceInit<UELExpressionCondition>::InPlaceNew;
    dword_1423B3F80 = PrintTrack::sClassNameUID;
    qword_1423B3F88 = (__int64)InPlaceInit<PrintTrack>::InPlaceNew;
    dword_1423B3F90 = OpportunityTrack::sClassNameUID;
    qword_1423B3F98 = (__int64)InPlaceInit<OpportunityTrack>::InPlaceNew;
    dword_1423B3FA0 = SequenceTrack::sClassNameUID;
    qword_1423B3FA8 = (__int64)InPlaceInit<SequenceTrack>::InPlaceNew;
    dword_1423B3FB0 = ExecuteTrack::sClassNameUID;
    qword_1423B3FB8 = (__int64)InPlaceInit<ExecuteTrack>::InPlaceNew;
    dword_1423B3FC0 = MasterTrack::sClassNameUID;
    qword_1423B3FC8 = (__int64)InPlaceInit<MasterTrack>::InPlaceNew;
    dword_1423B3FD0 = SpawnTrack::sClassNameUID;
    qword_1423B3FD8 = (__int64)InPlaceInit<SpawnTrack>::InPlaceNew;
    dword_1423B3FE0 = NodeRequestTrack::sClassNameUID;
    qword_1423B3FE8 = (__int64)InPlaceInit<NodeRequestTrack>::InPlaceNew;
    dword_1423B3FF0 = InvokeBehaviourTrack::sClassNameUID;
    qword_1423B3FF8 = (__int64)InPlaceInit<InvokeBehaviourTrack>::InPlaceNew;
    dword_1423B4000 = SetBittenTrack::sClassNameUID;
    qword_1423B4008 = (__int64)InPlaceInit<SetBittenTrack>::InPlaceNew;
    dword_1423B4010 = UpdateStatAwardWithFloatTrack::sClassNameUID;
    qword_1423B4018 = (__int64)InPlaceInit<UpdateStatAwardWithFloatTrack>::InPlaceNew;
    dword_1423B4020 = UpdateStatAwardWithIntegerTrack::sClassNameUID;
    qword_1423B4028 = (__int64)InPlaceInit<UpdateStatAwardWithIntegerTrack>::InPlaceNew;
    dword_1423B4030 = EndStatGameTrack::sClassNameUID;
    qword_1423B4038 = (__int64)InPlaceInit<EndStatGameTrack>::InPlaceNew;
    dword_1423B4040 = UpdateStatGameWithIntegerTrack::sClassNameUID;
    qword_1423B4048 = (__int64)InPlaceInit<UpdateStatGameWithIntegerTrack>::InPlaceNew;
    dword_1423B4050 = UpdateStatGameWithFloatTrack::sClassNameUID;
    qword_1423B4058 = (__int64)InPlaceInit<UpdateStatGameWithFloatTrack>::InPlaceNew;
    dword_1423B4060 = UpdateStatGameWithUpdateTimeTrack::sClassNameUID;
    qword_1423B4068 = (__int64)InPlaceInit<UpdateStatGameWithUpdateTimeTrack>::InPlaceNew;
    dword_1423B4070 = CharacterSetVisualDamageTrack::sClassNameUID;
    qword_1423B4078 = (__int64)InPlaceInit<CharacterSetVisualDamageTrack>::InPlaceNew;
    dword_1423B4080 = ShootTrackTU::sClassNameUID;
    qword_1423B4088 = (__int64)InPlaceInit<ShootTrackTU>::InPlaceNew;
    dword_1423B4090 = VehicleOnDeadDriverStopTrack::sClassNameUID;
    qword_1423B4098 = (__int64)InPlaceInit<VehicleOnDeadDriverStopTrack>::InPlaceNew;
    dword_1423B40A0 = ExecuteTrackLibraryTrack::sClassNameUID;
    qword_1423B40A8 = (__int64)InPlaceInit<ExecuteTrackLibraryTrack>::InPlaceNew;
    dword_1423B40B0 = ResourceOpportunityTrack::sClassNameUID;
    qword_1423B40B8 = (__int64)InPlaceInit<ResourceOpportunityTrack>::InPlaceNew;
    dword_1423B40C0 = ActorAttachTrack::sClassNameUID;
    qword_1423B40C8 = (__int64)InPlaceInit<ActorAttachTrack>::InPlaceNew;
    dword_1423B40D0 = ActorDetachTrack::sClassNameUID;
    qword_1423B40D8 = (__int64)InPlaceInit<ActorDetachTrack>::InPlaceNew;
    dword_1423B40E0 = AnimationBankReferenceTrack::sClassNameUID;
    qword_1423B40E8 = (__int64)InPlaceInit<AnimationBankReferenceTrack>::InPlaceNew;
    dword_1423B40F0 = AnimationBankPriorityTrack::sClassNameUID;
    qword_1423B40F8 = (__int64)InPlaceInit<AnimationBankPriorityTrack>::InPlaceNew;
    dword_1423B4100 = AnimationTrack::sClassNameUID;
    qword_1423B4108 = (__int64)InPlaceInit<AnimationTrack>::InPlaceNew;
    dword_1423B4110 = AnimationRefPoseTrack::sClassNameUID;
    qword_1423B4118 = (__int64)InPlaceInit<AnimationRefPoseTrack>::InPlaceNew;
    dword_1423B4120 = AnimationLockHighLODTrack::sClassNameUID;
    qword_1423B4128 = (__int64)InPlaceInit<AnimationLockHighLODTrack>::InPlaceNew;
    dword_1423B4130 = BlendTreeTrack::sClassNameUID;
    qword_1423B4138 = (__int64)InPlaceInit<BlendTreeTrack>::InPlaceNew;
    dword_1423B4140 = PoseDriverDisableTrack::sClassNameUID;
    qword_1423B4148 = (__int64)InPlaceInit<PoseDriverDisableTrack>::InPlaceNew;
    dword_1423B4150 = ExplosionTrack::sClassNameUID;
    qword_1423B4158 = (__int64)InPlaceInit<ExplosionTrack>::InPlaceNew;
    dword_1423B4160 = PlayEffectTrack::sClassNameUID;
    qword_1423B4168 = (__int64)InPlaceInit<PlayEffectTrack>::InPlaceNew;
    dword_1423B4170 = RumbleTrack::sClassNameUID;
    qword_1423B4178 = (__int64)InPlaceInit<RumbleTrack>::InPlaceNew;
    dword_1423B4180 = AudioTrack::sClassNameUID;
    qword_1423B4188 = (__int64)InPlaceInit<AudioTrack>::InPlaceNew;
    dword_1423B4190 = AudioTrackSimple::sClassNameUID;
    qword_1423B4198 = (__int64)InPlaceInit<AudioTrackSimple>::InPlaceNew;
    dword_1423B41A0 = DoorStateTrack::sClassNameUID;
    qword_1423B41A8 = (__int64)InPlaceInit<DoorStateTrack>::InPlaceNew;
    dword_1423B41B0 = AudioTrackSoundbankIO::sClassNameUID;
    qword_1423B41B8 = (__int64)InPlaceInit<AudioTrackSoundbankIO>::InPlaceNew;
    dword_1423B41C0 = AudioTrackMusicState::sClassNameUID;
    qword_1423B41C8 = (__int64)InPlaceInit<AudioTrackMusicState>::InPlaceNew;
    dword_1423B41D0 = PoliceScannerAudioEventTrack::sClassNameUID;
    qword_1423B41D8 = (__int64)InPlaceInit<PoliceScannerAudioEventTrack>::InPlaceNew;
    dword_1423B41E0 = AudioTrackSurfaceDetection::sClassNameUID;
    qword_1423B41E8 = (__int64)InPlaceInit<AudioTrackSurfaceDetection>::InPlaceNew;
    dword_1423B41F0 = DialogueTrack::sClassNameUID;
    qword_1423B41F8 = (__int64)InPlaceInit<DialogueTrack>::InPlaceNew;
    dword_1423B4200 = DialogueTrackPOI::sClassNameUID;
    qword_1423B4208 = (__int64)InPlaceInit<DialogueTrackPOI>::InPlaceNew;
    dword_1423B4210 = DialogueTrackWeaponImpact::sClassNameUID;
    qword_1423B4218 = (__int64)InPlaceInit<DialogueTrackWeaponImpact>::InPlaceNew;
    dword_1423B4220 = ConversationTrackCleanup::sClassNameUID;
    qword_1423B4228 = (__int64)InPlaceInit<ConversationTrackCleanup>::InPlaceNew;
    dword_1423B4230 = ConversationTrackCreate::sClassNameUID;
    qword_1423B4238 = (__int64)InPlaceInit<ConversationTrackCreate>::InPlaceNew;
    dword_1423B4240 = ConversationTrackOperation::sClassNameUID;
    qword_1423B4248 = (__int64)InPlaceInit<ConversationTrackOperation>::InPlaceNew;
    dword_1423B4250 = LocomotionTrack::sClassNameUID;
    qword_1423B4258 = (__int64)InPlaceInit<LocomotionTrack>::InPlaceNew;
    dword_1423B4260 = Locomotion2Track::sClassNameUID;
    qword_1423B4268 = (__int64)InPlaceInit<Locomotion2Track>::InPlaceNew;
    dword_1423B4270 = LocomotionParamTrack::sClassNameUID;
    qword_1423B4278 = (__int64)InPlaceInit<LocomotionParamTrack>::InPlaceNew;
    dword_1423B4280 = FootStepLeftEffectTrack::sClassNameUID;
    qword_1423B4288 = (__int64)InPlaceInit<FootStepLeftEffectTrack>::InPlaceNew;
    dword_1423B4290 = FootStepRightEffectTrack::sClassNameUID;
    qword_1423B4298 = (__int64)InPlaceInit<FootStepRightEffectTrack>::InPlaceNew;
    dword_1423B42A0 = CurtainShowTrack::sClassNameUID;
    qword_1423B42A8 = (__int64)InPlaceInit<CurtainShowTrack>::InPlaceNew;
    dword_1423B42B0 = JumpTrack::sClassNameUID;
    qword_1423B42B8 = (__int64)InPlaceInit<JumpTrack>::InPlaceNew;
    dword_1423B42C0 = TargetJumpTrack::sClassNameUID;
    qword_1423B42C8 = (__int64)InPlaceInit<TargetJumpTrack>::InPlaceNew;
    dword_1423B42D0 = ParkourSyncPositionTrack::sClassNameUID;
    qword_1423B42D8 = (__int64)InPlaceInit<ParkourSyncPositionTrack>::InPlaceNew;
    dword_1423B42E0 = ParkourNeighborAdvanceTrack::sClassNameUID;
    qword_1423B42E8 = (__int64)InPlaceInit<ParkourNeighborAdvanceTrack>::InPlaceNew;
    dword_1423B42F0 = TargetLatchParkourHandleTrack::sClassNameUID;
    qword_1423B42F8 = (__int64)InPlaceInit<TargetLatchParkourHandleTrack>::InPlaceNew;
    dword_1423B4300 = ParkourConstrainTrack::sClassNameUID;
    qword_1423B4308 = (__int64)InPlaceInit<ParkourConstrainTrack>::InPlaceNew;
    dword_1423B4310 = CombatRegionMoveToTrack::sClassNameUID;
    qword_1423B4318 = (__int64)InPlaceInit<CombatRegionMoveToTrack>::InPlaceNew;
    dword_1423B4320 = CoverSyncPositionTrack::sClassNameUID;
    qword_1423B4328 = (__int64)InPlaceInit<CoverSyncPositionTrack>::InPlaceNew;
    dword_1423B4330 = CoverHoldPositionTrack::sClassNameUID;
    qword_1423B4338 = (__int64)InPlaceInit<CoverHoldPositionTrack>::InPlaceNew;
    dword_1423B4340 = CoverProbeForwardAndLatchTrack::sClassNameUID;
    qword_1423B4348 = (__int64)InPlaceInit<CoverProbeForwardAndLatchTrack>::InPlaceNew;
    dword_1423B4350 = CoverProbeAndLatchTrack::sClassNameUID;
    qword_1423B4358 = (__int64)InPlaceInit<CoverProbeAndLatchTrack>::InPlaceNew;
    dword_1423B4360 = CoverSetPopoutSideTrack::sClassNameUID;
    qword_1423B4368 = (__int64)InPlaceInit<CoverSetPopoutSideTrack>::InPlaceNew;
    dword_1423B4370 = DynamicWallHandleTrack::sClassNameUID;
    qword_1423B4378 = (__int64)InPlaceInit<DynamicWallHandleTrack>::InPlaceNew;
    dword_1423B4380 = GravityTrack::sClassNameUID;
    qword_1423B4388 = (__int64)InPlaceInit<GravityTrack>::InPlaceNew;
    dword_1423B4390 = VelocitySlopeModeTrack::sClassNameUID;
    qword_1423B4398 = (__int64)InPlaceInit<VelocitySlopeModeTrack>::InPlaceNew;
    dword_1423B43A0 = DetailedOnGroundTrack::sClassNameUID;
    qword_1423B43A8 = (__int64)InPlaceInit<DetailedOnGroundTrack>::InPlaceNew;
    dword_1423B43B0 = ParkourHandleTrack::sClassNameUID;
    qword_1423B43B8 = (__int64)InPlaceInit<ParkourHandleTrack>::InPlaceNew;
    dword_1423B43C0 = DisableCollisionTrack::sClassNameUID;
    qword_1423B43C8 = (__int64)InPlaceInit<DisableCollisionTrack>::InPlaceNew;
    dword_1423B43D0 = DisableSelfIlluminationTrack::sClassNameUID;
    qword_1423B43D8 = (__int64)InPlaceInit<DisableSelfIlluminationTrack>::InPlaceNew;
    dword_1423B43E0 = MinimumDistanceTrack::sClassNameUID;
    qword_1423B43E8 = (__int64)InPlaceInit<MinimumDistanceTrack>::InPlaceNew;
    dword_1423B43F0 = AttackCollisionTrack::sClassNameUID;
    qword_1423B43F8 = (__int64)InPlaceInit<AttackCollisionTrack>::InPlaceNew;
    dword_1423B4400 = HitRecordSetBerserkAttackFlagTrack::sClassNameUID;
    qword_1423B4408 = (__int64)InPlaceInit<HitRecordSetBerserkAttackFlagTrack>::InPlaceNew;
    dword_1423B4410 = AttackTimerTrack::sClassNameUID;
    qword_1423B4418 = (__int64)InPlaceInit<AttackTimerTrack>::InPlaceNew;
    dword_1423B4420 = DamageTrack::sClassNameUID;
    qword_1423B4428 = (__int64)InPlaceInit<DamageTrack>::InPlaceNew;
    dword_1423B4430 = SetEngineDamageTrack::sClassNameUID;
    qword_1423B4438 = (__int64)InPlaceInit<SetEngineDamageTrack>::InPlaceNew;
    dword_1423B4440 = DamageEffectTrack::sClassNameUID;
    qword_1423B4448 = (__int64)InPlaceInit<DamageEffectTrack>::InPlaceNew;
    dword_1423B4450 = EffectSurfaceCollisionTrack::sClassNameUID;
    qword_1423B4458 = (__int64)InPlaceInit<EffectSurfaceCollisionTrack>::InPlaceNew;
    dword_1423B4460 = HandleDamageTrack::sClassNameUID;
    qword_1423B4468 = (__int64)InPlaceInit<HandleDamageTrack>::InPlaceNew;
    dword_1423B4470 = OverrideDesiredFocusModeTrack::sClassNameUID;
    qword_1423B4478 = (__int64)InPlaceInit<OverrideDesiredFocusModeTrack>::InPlaceNew;
    dword_1423B4480 = TargetDamageTrack::sClassNameUID;
    qword_1423B4488 = (__int64)InPlaceInit<TargetDamageTrack>::InPlaceNew;
    dword_1423B4490 = TargetPlayTrack::sClassNameUID;
    qword_1423B4498 = (__int64)InPlaceInit<TargetPlayTrack>::InPlaceNew;
    dword_1423B44A0 = TargetPlayAITrack::sClassNameUID;
    qword_1423B44A8 = (__int64)InPlaceInit<TargetPlayAITrack>::InPlaceNew;
    dword_1423B44B0 = TargetPlayHoldTrack::sClassNameUID;
    qword_1423B44B8 = (__int64)InPlaceInit<TargetPlayHoldTrack>::InPlaceNew;
    dword_1423B44C0 = TargetSteerToTrack::sClassNameUID;
    qword_1423B44C8 = (__int64)InPlaceInit<TargetSteerToTrack>::InPlaceNew;
    dword_1423B44D0 = TargetSyncPositionTrack::sClassNameUID;
    qword_1423B44D8 = (__int64)InPlaceInit<TargetSyncPositionTrack>::InPlaceNew;
    dword_1423B44E0 = TargetAttachTrack::sClassNameUID;
    qword_1423B44E8 = (__int64)InPlaceInit<TargetAttachTrack>::InPlaceNew;
    dword_1423B44F0 = TargetDetachTrack::sClassNameUID;
    qword_1423B44F8 = (__int64)InPlaceInit<TargetDetachTrack>::InPlaceNew;
    dword_1423B4500 = TargetAttachEXTrack::sClassNameUID;
    qword_1423B4508 = (__int64)InPlaceInit<TargetAttachEXTrack>::InPlaceNew;
    dword_1423B4510 = TargetDetachEXTrack::sClassNameUID;
    qword_1423B4518 = (__int64)InPlaceInit<TargetDetachEXTrack>::InPlaceNew;
    dword_1423B4520 = TargetAttachEffectorTrack::sClassNameUID;
    qword_1423B4528 = (__int64)InPlaceInit<TargetAttachEffectorTrack>::InPlaceNew;
    dword_1423B4530 = TargetDetachEffectorTrack::sClassNameUID;
    qword_1423B4538 = (__int64)InPlaceInit<TargetDetachEffectorTrack>::InPlaceNew;
    dword_1423B4540 = TargetAttachConstraintTrack::sClassNameUID;
    qword_1423B4548 = (__int64)InPlaceInit<TargetAttachConstraintTrack>::InPlaceNew;
    dword_1423B4550 = TargetDetachConstraintTrack::sClassNameUID;
    qword_1423B4558 = (__int64)InPlaceInit<TargetDetachConstraintTrack>::InPlaceNew;
    dword_1423B4560 = TargetStealAttachedItemTrack::sClassNameUID;
    qword_1423B4568 = (__int64)InPlaceInit<TargetStealAttachedItemTrack>::InPlaceNew;
    dword_1423B4570 = TargetLockTrack::sClassNameUID;
    qword_1423B4578 = (__int64)InPlaceInit<TargetLockTrack>::InPlaceNew;
    dword_1423B4580 = TargetReleaseTrack::sClassNameUID;
    qword_1423B4588 = (__int64)InPlaceInit<TargetReleaseTrack>::InPlaceNew;
    dword_1423B4590 = TargetGrappleReleaseTrack::sClassNameUID;
    qword_1423B4598 = (__int64)InPlaceInit<TargetGrappleReleaseTrack>::InPlaceNew;
    dword_1423B45A0 = TargetPropInteractTrack::sClassNameUID;
    qword_1423B45A8 = (__int64)InPlaceInit<TargetPropInteractTrack>::InPlaceNew;
    dword_1423B45B0 = TargetAssignTrack::sClassNameUID;
    qword_1423B45B8 = (__int64)InPlaceInit<TargetAssignTrack>::InPlaceNew;
    dword_1423B45C0 = TargetAssignTargetsTargetToMyTargetTrack::sClassNameUID;
    qword_1423B45C8 = (__int64)InPlaceInit<TargetAssignTargetsTargetToMyTargetTrack>::InPlaceNew;
    dword_1423B45D0 = TargetAssignMyTargetToTargetsTargetTrack::sClassNameUID;
    qword_1423B45D8 = (__int64)InPlaceInit<TargetAssignMyTargetToTargetsTargetTrack>::InPlaceNew;
    dword_1423B45E0 = TargetDestroyTrack::sClassNameUID;
    qword_1423B45E8 = (__int64)InPlaceInit<TargetDestroyTrack>::InPlaceNew;
    dword_1423B45F0 = TargetWeaponAmmoConsumeTrack::sClassNameUID;
    qword_1423B45F8 = (__int64)InPlaceInit<TargetWeaponAmmoConsumeTrack>::InPlaceNew;
    dword_1423B4600 = TargetWeaponModeChangeTrack::sClassNameUID;
    qword_1423B4608 = (__int64)InPlaceInit<TargetWeaponModeChangeTrack>::InPlaceNew;
    dword_1423B4610 = TargetAddToInventoryTrack::sClassNameUID;
    qword_1423B4618 = (__int64)InPlaceInit<TargetAddToInventoryTrack>::InPlaceNew;
    dword_1423B4620 = TargetRemoveFromInventoryTrack::sClassNameUID;
    qword_1423B4628 = (__int64)InPlaceInit<TargetRemoveFromInventoryTrack>::InPlaceNew;
    dword_1423B4630 = TargetPurchaseItemTrack::sClassNameUID;
    qword_1423B4638 = (__int64)InPlaceInit<TargetPurchaseItemTrack>::InPlaceNew;
    dword_1423B4640 = TargetVehicleBreakWindowTrack::sClassNameUID;
    qword_1423B4648 = (__int64)InPlaceInit<TargetVehicleBreakWindowTrack>::InPlaceNew;
    dword_1423B4650 = TargetFocusOverrideTrack::sClassNameUID;
    qword_1423B4658 = (__int64)InPlaceInit<TargetFocusOverrideTrack>::InPlaceNew;
    dword_1423B4660 = TargetHitReactionTrack::sClassNameUID;
    qword_1423B4668 = (__int64)InPlaceInit<TargetHitReactionTrack>::InPlaceNew;
    dword_1423B4670 = TargetAssignSubTargetTrack::sClassNameUID;
    qword_1423B4678 = (__int64)InPlaceInit<TargetAssignSubTargetTrack>::InPlaceNew;
    dword_1423B4680 = TargetActionRequestTrack::sClassNameUID;
    qword_1423B4688 = (__int64)InPlaceInit<TargetActionRequestTrack>::InPlaceNew;
    dword_1423B4690 = TargetPlayEffectTrack::sClassNameUID;
    qword_1423B4698 = (__int64)InPlaceInit<TargetPlayEffectTrack>::InPlaceNew;
    dword_1423B46A0 = TargetSpawnTrack::sClassNameUID;
    qword_1423B46A8 = (__int64)InPlaceInit<TargetSpawnTrack>::InPlaceNew;
    dword_1423B46B0 = ProxyTargetSphereCastTrack::sClassNameUID;
    qword_1423B46B8 = (__int64)InPlaceInit<ProxyTargetSphereCastTrack>::InPlaceNew;
    dword_1423B46C0 = TargetingProfileSelectTrack::sClassNameUID;
    qword_1423B46C8 = (__int64)InPlaceInit<TargetingProfileSelectTrack>::InPlaceNew;
    dword_1423B46D0 = AimingFreeAimIntentionResetTrack::sClassNameUID;
    qword_1423B46D8 = (__int64)InPlaceInit<AimingFreeAimIntentionResetTrack>::InPlaceNew;
    dword_1423B46E0 = AimingSoftLockTrack::sClassNameUID;
    qword_1423B46E8 = (__int64)InPlaceInit<AimingSoftLockTrack>::InPlaceNew;
    dword_1423B46F0 = AimingSoftLockDisableTrack::sClassNameUID;
    qword_1423B46F8 = (__int64)InPlaceInit<AimingSoftLockDisableTrack>::InPlaceNew;
    dword_1423B4700 = AimingFreeAimConeClampTrack::sClassNameUID;
    qword_1423B4708 = (__int64)InPlaceInit<AimingFreeAimConeClampTrack>::InPlaceNew;
    dword_1423B4710 = PowerManagementSuspendPermanentlyTrack::sClassNameUID;
    qword_1423B4718 = (__int64)InPlaceInit<PowerManagementSuspendPermanentlyTrack>::InPlaceNew;
    dword_1423B4720 = InteractionPointInteractWithBestTrack::sClassNameUID;
    qword_1423B4728 = (__int64)InPlaceInit<InteractionPointInteractWithBestTrack>::InPlaceNew;
    dword_1423B4730 = InteractionPointSetupTrack::sClassNameUID;
    qword_1423B4738 = (__int64)InPlaceInit<InteractionPointSetupTrack>::InPlaceNew;
    dword_1423B4740 = InteractionPointActivateTrack::sClassNameUID;
    qword_1423B4748 = (__int64)InPlaceInit<InteractionPointActivateTrack>::InPlaceNew;
    dword_1423B4750 = InteractionPointDeactivateTrack::sClassNameUID;
    qword_1423B4758 = (__int64)InPlaceInit<InteractionPointDeactivateTrack>::InPlaceNew;
    dword_1423B4760 = AttachmentTransferTrack::sClassNameUID;
    qword_1423B4768 = (__int64)InPlaceInit<AttachmentTransferTrack>::InPlaceNew;
    dword_1423B4770 = SetRollStabilityTrack::sClassNameUID;
    qword_1423B4778 = (__int64)InPlaceInit<SetRollStabilityTrack>::InPlaceNew;
    dword_1423B4780 = EventTrack::sClassNameUID;
    qword_1423B4788 = (__int64)InPlaceInit<EventTrack>::InPlaceNew;
    dword_1423B4790 = UIEventTrack::sClassNameUID;
    qword_1423B4798 = (__int64)InPlaceInit<UIEventTrack>::InPlaceNew;
    dword_1423B47A0 = RagdollTrack::sClassNameUID;
    qword_1423B47A8 = (__int64)InPlaceInit<RagdollTrack>::InPlaceNew;
    dword_1423B47B0 = SensorComponentTrack::sClassNameUID;
    qword_1423B47B8 = (__int64)InPlaceInit<SensorComponentTrack>::InPlaceNew;
    dword_1423B47C0 = RagdollCollisionTrack::sClassNameUID;
    qword_1423B47C8 = (__int64)InPlaceInit<RagdollCollisionTrack>::InPlaceNew;
    dword_1423B47D0 = RagdollImpulseTrack::sClassNameUID;
    qword_1423B47D8 = (__int64)InPlaceInit<RagdollImpulseTrack>::InPlaceNew;
    dword_1423B47E0 = RagdollAngularImpulseTrack::sClassNameUID;
    qword_1423B47E8 = (__int64)InPlaceInit<RagdollAngularImpulseTrack>::InPlaceNew;
    dword_1423B47F0 = RagdollMotorTrack::sClassNameUID;
    qword_1423B47F8 = (__int64)InPlaceInit<RagdollMotorTrack>::InPlaceNew;
    dword_1423B4800 = RagdollBlendMotorTrack::sClassNameUID;
    qword_1423B4808 = (__int64)InPlaceInit<RagdollBlendMotorTrack>::InPlaceNew;
    dword_1423B4810 = RagdollAquireTrack::sClassNameUID;
    qword_1423B4818 = (__int64)InPlaceInit<RagdollAquireTrack>::InPlaceNew;
    dword_1423B4820 = RagdollReleaseTrack::sClassNameUID;
    qword_1423B4828 = (__int64)InPlaceInit<RagdollReleaseTrack>::InPlaceNew;
    dword_1423B4830 = RagdollChangeModeTrack::sClassNameUID;
    qword_1423B4838 = (__int64)InPlaceInit<RagdollChangeModeTrack>::InPlaceNew;
    dword_1423B4840 = RagdollChangeMotorTrack::sClassNameUID;
    qword_1423B4848 = (__int64)InPlaceInit<RagdollChangeMotorTrack>::InPlaceNew;
    dword_1423B4850 = RagdollChangeBlendWeightTrack::sClassNameUID;
    qword_1423B4858 = (__int64)InPlaceInit<RagdollChangeBlendWeightTrack>::InPlaceNew;
    dword_1423B4860 = RagdollChangeVelocityTrackingStrTrack::sClassNameUID;
    qword_1423B4868 = (__int64)InPlaceInit<RagdollChangeVelocityTrackingStrTrack>::InPlaceNew;
    dword_1423B4870 = RagdollChangeVelocityTrackingParamsRawTrack::sClassNameUID;
    qword_1423B4878 = (__int64)InPlaceInit<RagdollChangeVelocityTrackingParamsRawTrack>::InPlaceNew;
    dword_1423B4880 = RagdollChangeAngularLimitStrTrack::sClassNameUID;
    qword_1423B4888 = (__int64)InPlaceInit<RagdollChangeAngularLimitStrTrack>::InPlaceNew;
    dword_1423B4890 = RagdollSetFrictionTrack::sClassNameUID;
    qword_1423B4898 = (__int64)InPlaceInit<RagdollSetFrictionTrack>::InPlaceNew;
    dword_1423B48A0 = RagdollAdjustMassTrack::sClassNameUID;
    qword_1423B48A8 = (__int64)InPlaceInit<RagdollAdjustMassTrack>::InPlaceNew;
    dword_1423B48B0 = RagdollDeathImpulseTrack::sClassNameUID;
    qword_1423B48B8 = (__int64)InPlaceInit<RagdollDeathImpulseTrack>::InPlaceNew;
    dword_1423B48C0 = CharacterPhysicsTrack::sClassNameUID;
    qword_1423B48C8 = (__int64)InPlaceInit<CharacterPhysicsTrack>::InPlaceNew;
    dword_1423B48D0 = CharacterPhysicsSuperMassiveTrack::sClassNameUID;
    qword_1423B48D8 = (__int64)InPlaceInit<CharacterPhysicsSuperMassiveTrack>::InPlaceNew;
    dword_1423B48E0 = PairedGrappleTrack::sClassNameUID;
    qword_1423B48E8 = (__int64)InPlaceInit<PairedGrappleTrack>::InPlaceNew;
    dword_1423B48F0 = PhysicsMotionTypeTrack::sClassNameUID;
    qword_1423B48F8 = (__int64)InPlaceInit<PhysicsMotionTypeTrack>::InPlaceNew;
    dword_1423B4900 = CollisionDisableAgainstTargetTrack::sClassNameUID;
    qword_1423B4908 = (__int64)InPlaceInit<CollisionDisableAgainstTargetTrack>::InPlaceNew;
    dword_1423B4910 = SlopeLocomotionFixupTrack::sClassNameUID;
    qword_1423B4918 = (__int64)InPlaceInit<SlopeLocomotionFixupTrack>::InPlaceNew;
    dword_1423B4920 = MotionIntentionFilterTrack::sClassNameUID;
    qword_1423B4928 = (__int64)InPlaceInit<MotionIntentionFilterTrack>::InPlaceNew;
    dword_1423B4930 = MotionIntentionCOMTrack::sClassNameUID;
    qword_1423B4938 = (__int64)InPlaceInit<MotionIntentionCOMTrack>::InPlaceNew;
    dword_1423B4940 = MotionIntentionSetRelativeToPlayerTrack::sClassNameUID;
    qword_1423B4948 = (__int64)InPlaceInit<MotionIntentionSetRelativeToPlayerTrack>::InPlaceNew;
    dword_1423B4950 = MotionIntentionHoldTrack::sClassNameUID;
    qword_1423B4958 = (__int64)InPlaceInit<MotionIntentionHoldTrack>::InPlaceNew;
    dword_1423B4960 = DestructionSetDefinitionTrack::sClassNameUID;
    qword_1423B4968 = (__int64)InPlaceInit<DestructionSetDefinitionTrack>::InPlaceNew;
    dword_1423B4970 = DestructionEventTrack::sClassNameUID;
    qword_1423B4978 = (__int64)InPlaceInit<DestructionEventTrack>::InPlaceNew;
    dword_1423B4980 = DestructionEnableRiggedGeoTrack::sClassNameUID;
    qword_1423B4988 = (__int64)InPlaceInit<DestructionEnableRiggedGeoTrack>::InPlaceNew;
    dword_1423B4990 = DestructionSpawnPropertySetTrack::sClassNameUID;
    qword_1423B4998 = (__int64)InPlaceInit<DestructionSpawnPropertySetTrack>::InPlaceNew;
    dword_1423B49A0 = DestructionSpawnPhantomVolumeTrack::sClassNameUID;
    qword_1423B49A8 = (__int64)InPlaceInit<DestructionSpawnPhantomVolumeTrack>::InPlaceNew;
    dword_1423B49B0 = DestructionExplosionTrack::sClassNameUID;
    qword_1423B49B8 = (__int64)InPlaceInit<DestructionExplosionTrack>::InPlaceNew;
    dword_1423B49C0 = DestructionEnableFractureElementTrack::sClassNameUID;
    qword_1423B49C8 = (__int64)InPlaceInit<DestructionEnableFractureElementTrack>::InPlaceNew;
    dword_1423B49D0 = DestructionSetDamageTrack::sClassNameUID;
    qword_1423B49D8 = (__int64)InPlaceInit<DestructionSetDamageTrack>::InPlaceNew;
    dword_1423B49E0 = DestructionThrusterTrack::sClassNameUID;
    qword_1423B49E8 = (__int64)InPlaceInit<DestructionThrusterTrack>::InPlaceNew;
    dword_1423B49F0 = DestructionHingeConstraintTrack::sClassNameUID;
    qword_1423B49F8 = (__int64)InPlaceInit<DestructionHingeConstraintTrack>::InPlaceNew;
    dword_1423B4A00 = DestructionStiffSpringConstraintTrack::sClassNameUID;
    qword_1423B4A08 = (__int64)InPlaceInit<DestructionStiffSpringConstraintTrack>::InPlaceNew;
    dword_1423B4A10 = DestructionBallAndSocketConstraintTrack::sClassNameUID;
    qword_1423B4A18 = (__int64)InPlaceInit<DestructionBallAndSocketConstraintTrack>::InPlaceNew;
    dword_1423B4A20 = DestructionDeleteConstraintTrack::sClassNameUID;
    qword_1423B4A28 = (__int64)InPlaceInit<DestructionDeleteConstraintTrack>::InPlaceNew;
    dword_1423B4A30 = VehicleNISModeTrack::sClassNameUID;
    qword_1423B4A38 = (__int64)InPlaceInit<VehicleNISModeTrack>::InPlaceNew;
    dword_1423B4A40 = VehicleSetDoorsLockedTrack::sClassNameUID;
    qword_1423B4A48 = (__int64)InPlaceInit<VehicleSetDoorsLockedTrack>::InPlaceNew;
    dword_1423B4A50 = VehicleDestroyTrack::sClassNameUID;
    qword_1423B4A58 = (__int64)InPlaceInit<VehicleDestroyTrack>::InPlaceNew;
    dword_1423B4A60 = VehicleFlipTrack::sClassNameUID;
    qword_1423B4A68 = (__int64)InPlaceInit<VehicleFlipTrack>::InPlaceNew;
    dword_1423B4A70 = VehicleSpinOutTrack::sClassNameUID;
    qword_1423B4A78 = (__int64)InPlaceInit<VehicleSpinOutTrack>::InPlaceNew;
    dword_1423B4A80 = VehicleTripRollTrack::sClassNameUID;
    qword_1423B4A88 = (__int64)InPlaceInit<VehicleTripRollTrack>::InPlaceNew;
    dword_1423B4A90 = VehicleAddSpeedTrack::sClassNameUID;
    qword_1423B4A98 = (__int64)InPlaceInit<VehicleAddSpeedTrack>::InPlaceNew;
    dword_1423B4AA0 = VehicleRamTrack::sClassNameUID;
    qword_1423B4AA8 = (__int64)InPlaceInit<VehicleRamTrack>::InPlaceNew;
    dword_1423B4AB0 = VehicleOverrideWheelFrictionMultiplierTrack::sClassNameUID;
    qword_1423B4AB8 = (__int64)InPlaceInit<VehicleOverrideWheelFrictionMultiplierTrack>::InPlaceNew;
    dword_1423B4AC0 = VehicleSetCollisionShouldTriggerExplosionTrack::sClassNameUID;
    qword_1423B4AC8 = (__int64)InPlaceInit<VehicleSetCollisionShouldTriggerExplosionTrack>::InPlaceNew;
    dword_1423B4AD0 = VehicleLockHighLODTrack::sClassNameUID;
    qword_1423B4AD8 = (__int64)InPlaceInit<VehicleLockHighLODTrack>::InPlaceNew;
    dword_1423B4AE0 = VehicleLightTrack::sClassNameUID;
    qword_1423B4AE8 = (__int64)InPlaceInit<VehicleLightTrack>::InPlaceNew;
    dword_1423B4AF0 = VehicleStateTrack::sClassNameUID;
    qword_1423B4AF8 = (__int64)InPlaceInit<VehicleStateTrack>::InPlaceNew;
    dword_1423B4B00 = VehicleInteractTrack::sClassNameUID;
    qword_1423B4B08 = (__int64)InPlaceInit<VehicleInteractTrack>::InPlaceNew;
    dword_1423B4B10 = VehicleCruiseControlTrack::sClassNameUID;
    qword_1423B4B18 = (__int64)InPlaceInit<VehicleCruiseControlTrack>::InPlaceNew;
    dword_1423B4B20 = VehicleMassScaleForCollisionsTrack::sClassNameUID;
    qword_1423B4B28 = (__int64)InPlaceInit<VehicleMassScaleForCollisionsTrack>::InPlaceNew;
    dword_1423B4B30 = VehicleStopTrack::sClassNameUID;
    qword_1423B4B38 = (__int64)InPlaceInit<VehicleStopTrack>::InPlaceNew;
    dword_1423B4B40 = VehicleSteerTrack::sClassNameUID;
    qword_1423B4B48 = (__int64)InPlaceInit<VehicleSteerTrack>::InPlaceNew;
    dword_1423B4B50 = VehicleEngineAutoDeteriorateTrack::sClassNameUID;
    qword_1423B4B58 = (__int64)InPlaceInit<VehicleEngineAutoDeteriorateTrack>::InPlaceNew;
    dword_1423B4B60 = VehicleTriggerExplosionTrack::sClassNameUID;
    qword_1423B4B68 = (__int64)InPlaceInit<VehicleTriggerExplosionTrack>::InPlaceNew;
    dword_1423B4B70 = VehicleTurnOnDisabledEffectTrack::sClassNameUID;
    qword_1423B4B78 = (__int64)InPlaceInit<VehicleTurnOnDisabledEffectTrack>::InPlaceNew;
    dword_1423B4B80 = BikePhysicsEnableConstraintTrack::sClassNameUID;
    qword_1423B4B88 = (__int64)InPlaceInit<BikePhysicsEnableConstraintTrack>::InPlaceNew;
    dword_1423B4B90 = VehicleDoorPhysicsTrack::sClassNameUID;
    qword_1423B4B98 = (__int64)InPlaceInit<VehicleDoorPhysicsTrack>::InPlaceNew;
    dword_1423B4BA0 = VehiclePreventWheelieTrack::sClassNameUID;
    qword_1423B4BA8 = (__int64)InPlaceInit<VehiclePreventWheelieTrack>::InPlaceNew;
    dword_1423B4BB0 = MotorBikeStandUpTrack::sClassNameUID;
    qword_1423B4BB8 = (__int64)InPlaceInit<MotorBikeStandUpTrack>::InPlaceNew;
    dword_1423B4BC0 = UIScreenTrack::sClassNameUID;
    qword_1423B4BC8 = (__int64)InPlaceInit<UIScreenTrack>::InPlaceNew;
    dword_1423B4BD0 = ShootTrack::sClassNameUID;
    qword_1423B4BD8 = (__int64)InPlaceInit<ShootTrack>::InPlaceNew;
    dword_1423B4BE0 = ReloadGunTrack::sClassNameUID;
    qword_1423B4BE8 = (__int64)InPlaceInit<ReloadGunTrack>::InPlaceNew;
    dword_1423B4BF0 = TargetGunSetAmmoForAIDeathTrack::sClassNameUID;
    qword_1423B4BF8 = (__int64)InPlaceInit<TargetGunSetAmmoForAIDeathTrack>::InPlaceNew;
    dword_1423B4C00 = GunConsumeAmmoTrack::sClassNameUID;
    qword_1423B4C08 = (__int64)InPlaceInit<GunConsumeAmmoTrack>::InPlaceNew;
    dword_1423B4C10 = StimulusTrack::sClassNameUID;
    qword_1423B4C18 = (__int64)InPlaceInit<StimulusTrack>::InPlaceNew;
    dword_1423B4C20 = ApplyStimulusEmitterToTargetTrack::sClassNameUID;
    qword_1423B4C28 = (__int64)InPlaceInit<ApplyStimulusEmitterToTargetTrack>::InPlaceNew;
    dword_1423B4C30 = AttackRightsTrack::sClassNameUID;
    qword_1423B4C38 = (__int64)InPlaceInit<AttackRightsTrack>::InPlaceNew;
    dword_1423B4C40 = TargetAttackRightsTrack::sClassNameUID;
    qword_1423B4C48 = (__int64)InPlaceInit<TargetAttackRightsTrack>::InPlaceNew;
    dword_1423B4C50 = SkookumTrack::sClassNameUID;
    qword_1423B4C58 = (__int64)InPlaceInit<SkookumTrack>::InPlaceNew;
    dword_1423B4C60 = TargetPhysicalAttackTrack::sClassNameUID;
    qword_1423B4C68 = (__int64)InPlaceInit<TargetPhysicalAttackTrack>::InPlaceNew;
    dword_1423B4C70 = TargetPhysicalImpulseTrack::sClassNameUID;
    qword_1423B4C78 = (__int64)InPlaceInit<TargetPhysicalImpulseTrack>::InPlaceNew;
    dword_1423B4C80 = TargetPhysicalDamageTrack::sClassNameUID;
    qword_1423B4C88 = (__int64)InPlaceInit<TargetPhysicalDamageTrack>::InPlaceNew;
    dword_1423B4C90 = TargetFractureTrack::sClassNameUID;
    qword_1423B4C98 = (__int64)InPlaceInit<TargetFractureTrack>::InPlaceNew;
    dword_1423B4CA0 = TargetFractureStrengthTrack::sClassNameUID;
    qword_1423B4CA8 = (__int64)InPlaceInit<TargetFractureStrengthTrack>::InPlaceNew;
    dword_1423B4CB0 = PhysicalDamageTrack::sClassNameUID;
    qword_1423B4CB8 = (__int64)InPlaceInit<PhysicalDamageTrack>::InPlaceNew;
    dword_1423B4CC0 = TimeWarpTrack::sClassNameUID;
    qword_1423B4CC8 = (__int64)InPlaceInit<TimeWarpTrack>::InPlaceNew;
    dword_1423B4CD0 = VisualTreatmentTrack::sClassNameUID;
    qword_1423B4CD8 = (__int64)InPlaceInit<VisualTreatmentTrack>::InPlaceNew;
    dword_1423B4CE0 = CameraDOFTrack::sClassNameUID;
    qword_1423B4CE8 = (__int64)InPlaceInit<CameraDOFTrack>::InPlaceNew;
    dword_1423B4CF0 = CameraChangeTrack::sClassNameUID;
    qword_1423B4CF8 = (__int64)InPlaceInit<CameraChangeTrack>::InPlaceNew;
    dword_1423B4D00 = CameraShakeTrack::sClassNameUID;
    qword_1423B4D08 = (__int64)InPlaceInit<CameraShakeTrack>::InPlaceNew;
    dword_1423B4D10 = CameraResetTrack::sClassNameUID;
    qword_1423B4D18 = (__int64)InPlaceInit<CameraResetTrack>::InPlaceNew;
    dword_1423B4D20 = CameraAnimationTrack::sClassNameUID;
    qword_1423B4D28 = (__int64)InPlaceInit<CameraAnimationTrack>::InPlaceNew;
    dword_1423B4D30 = CameraSetSniperModeTrack::sClassNameUID;
    qword_1423B4D38 = (__int64)InPlaceInit<CameraSetSniperModeTrack>::InPlaceNew;
    dword_1423B4D40 = CameraFollowTargetTrack::sClassNameUID;
    qword_1423B4D48 = (__int64)InPlaceInit<CameraFollowTargetTrack>::InPlaceNew;
    dword_1423B4D50 = CameraRecoilTrack::sClassNameUID;
    qword_1423B4D58 = (__int64)InPlaceInit<CameraRecoilTrack>::InPlaceNew;
    dword_1423B4D60 = CameraCollisionGotoAngleTrack::sClassNameUID;
    qword_1423B4D68 = (__int64)InPlaceInit<CameraCollisionGotoAngleTrack>::InPlaceNew;
    dword_1423B4D70 = CameraConstrainYawTrack::sClassNameUID;
    qword_1423B4D78 = (__int64)InPlaceInit<CameraConstrainYawTrack>::InPlaceNew;
    dword_1423B4D80 = CameraIgnoreCollisionTrack::sClassNameUID;
    qword_1423B4D88 = (__int64)InPlaceInit<CameraIgnoreCollisionTrack>::InPlaceNew;
    dword_1423B4D90 = SubjectSprintTrack::sClassNameUID;
    qword_1423B4D98 = (__int64)InPlaceInit<SubjectSprintTrack>::InPlaceNew;
    dword_1423B4DA0 = SubjectElevationTrack::sClassNameUID;
    qword_1423B4DA8 = (__int64)InPlaceInit<SubjectElevationTrack>::InPlaceNew;
    dword_1423B4DB0 = SubjectFallingAttackTrack::sClassNameUID;
    qword_1423B4DB8 = (__int64)InPlaceInit<SubjectFallingAttackTrack>::InPlaceNew;
    dword_1423B4DC0 = SubjectFollowOverrideTrack::sClassNameUID;
    qword_1423B4DC8 = (__int64)InPlaceInit<SubjectFollowOverrideTrack>::InPlaceNew;
    dword_1423B4DD0 = SubjectFollowOverridePOITrack::sClassNameUID;
    qword_1423B4DD8 = (__int64)InPlaceInit<SubjectFollowOverridePOITrack>::InPlaceNew;
    dword_1423B4DE0 = SubjectFollowOverrideChooseTrack::sClassNameUID;
    qword_1423B4DE8 = (__int64)InPlaceInit<SubjectFollowOverrideChooseTrack>::InPlaceNew;
    dword_1423B4DF0 = CameraFollowGotoTrack::sClassNameUID;
    qword_1423B4DF8 = (__int64)InPlaceInit<CameraFollowGotoTrack>::InPlaceNew;
    dword_1423B4E00 = AiDriverSteeringWobbleTrack::sClassNameUID;
    qword_1423B4E08 = (__int64)InPlaceInit<AiDriverSteeringWobbleTrack>::InPlaceNew;
    dword_1423B4E10 = AiDriverSteeringLockTrack::sClassNameUID;
    qword_1423B4E18 = (__int64)InPlaceInit<AiDriverSteeringLockTrack>::InPlaceNew;
    dword_1423B4E20 = AiDriverGasBrakeLockTrack::sClassNameUID;
    qword_1423B4E28 = (__int64)InPlaceInit<AiDriverGasBrakeLockTrack>::InPlaceNew;
    dword_1423B4E30 = MissionFailTriggerTrack::sClassNameUID;
    qword_1423B4E38 = (__int64)InPlaceInit<MissionFailTriggerTrack>::InPlaceNew;
    dword_1423B4E40 = RimLightTargetTrack::sClassNameUID;
    qword_1423B4E48 = (__int64)InPlaceInit<RimLightTargetTrack>::InPlaceNew;
    dword_1423B4E50 = RimLightTrack::sClassNameUID;
    qword_1423B4E58 = (__int64)InPlaceInit<RimLightTrack>::InPlaceNew;
    dword_1423B4E60 = ApplyWetnessOrSweatTrack::sClassNameUID;
    qword_1423B4E68 = (__int64)InPlaceInit<ApplyWetnessOrSweatTrack>::InPlaceNew;
    dword_1423B4E70 = PlaybackSpeedModifierEnabledTrack::sClassNameUID;
    qword_1423B4E78 = (__int64)InPlaceInit<PlaybackSpeedModifierEnabledTrack>::InPlaceNew;
    dword_1423B4E80 = HealthRegenRateTrack::sClassNameUID;
    qword_1423B4E88 = (__int64)InPlaceInit<HealthRegenRateTrack>::InPlaceNew;
    dword_1423B4E90 = HealthSetPercentageTrack::sClassNameUID;
    qword_1423B4E98 = (__int64)InPlaceInit<HealthSetPercentageTrack>::InPlaceNew;
    dword_1423B4EA0 = HealthRegenerateTrack::sClassNameUID;
    qword_1423B4EA8 = (__int64)InPlaceInit<HealthRegenerateTrack>::InPlaceNew;
    dword_1423B4EB0 = HealthReplenishInstantTrack::sClassNameUID;
    qword_1423B4EB8 = (__int64)InPlaceInit<HealthReplenishInstantTrack>::InPlaceNew;
    dword_1423B4EC0 = InvulnerableTrack::sClassNameUID;
    qword_1423B4EC8 = (__int64)InPlaceInit<InvulnerableTrack>::InPlaceNew;
    dword_1423B4ED0 = SocialSetEnabledTrack::sClassNameUID;
    qword_1423B4ED8 = (__int64)InPlaceInit<SocialSetEnabledTrack>::InPlaceNew;
    dword_1423B4EE0 = PlayerGainHealthBasedOnActiveBuffTrack::sClassNameUID;
    qword_1423B4EE8 = (__int64)InPlaceInit<PlayerGainHealthBasedOnActiveBuffTrack>::InPlaceNew;
    dword_1423B4EF0 = CharacterStatModifyTrack::sClassNameUID;
    qword_1423B4EF8 = (__int64)InPlaceInit<CharacterStatModifyTrack>::InPlaceNew;
    dword_1423B4F00 = CharacterStatModifyIntTrack::sClassNameUID;
    qword_1423B4F08 = (__int64)InPlaceInit<CharacterStatModifyIntTrack>::InPlaceNew;
    dword_1423B4F10 = PerformScriptCommandTrack::sClassNameUID;
    qword_1423B4F18 = (__int64)InPlaceInit<PerformScriptCommandTrack>::InPlaceNew;
    dword_1423B4F20 = FleeTrack::sClassNameUID;
    qword_1423B4F28 = (__int64)InPlaceInit<FleeTrack>::InPlaceNew;
    dword_1423B4F30 = WanderTrack::sClassNameUID;
    qword_1423B4F38 = (__int64)InPlaceInit<WanderTrack>::InPlaceNew;
    dword_1423B4F40 = FacialRequestTrack::sClassNameUID;
    qword_1423B4F48 = (__int64)InPlaceInit<FacialRequestTrack>::InPlaceNew;
    dword_1423B4F50 = ActionRequestTrack::sClassNameUID;
    qword_1423B4F58 = (__int64)InPlaceInit<ActionRequestTrack>::InPlaceNew;
    dword_1423B4F60 = ActionRequestClearTrack::sClassNameUID;
    qword_1423B4F68 = (__int64)InPlaceInit<ActionRequestClearTrack>::InPlaceNew;
    dword_1423B4F70 = ActionRequestAndWaitUntilPlayingTrack::sClassNameUID;
    qword_1423B4F78 = (__int64)InPlaceInit<ActionRequestAndWaitUntilPlayingTrack>::InPlaceNew;
    dword_1423B4F80 = NodeRequestAndWaitUntilPlayingTrack::sClassNameUID;
    qword_1423B4F88 = (__int64)InPlaceInit<NodeRequestAndWaitUntilPlayingTrack>::InPlaceNew;
    dword_1423B4F90 = TurnToFaceTargetTrack::sClassNameUID;
    qword_1423B4F98 = (__int64)InPlaceInit<TurnToFaceTargetTrack>::InPlaceNew;
    dword_1423B4FA0 = HeadTrackTargetTrack::sClassNameUID;
    qword_1423B4FA8 = (__int64)InPlaceInit<HeadTrackTargetTrack>::InPlaceNew;
    dword_1423B4FB0 = MinimumDurationTrack::sClassNameUID;
    qword_1423B4FB8 = (__int64)InPlaceInit<MinimumDurationTrack>::InPlaceNew;
    dword_1423B4FC0 = RunLaterallyFromTargetTrack::sClassNameUID;
    qword_1423B4FC8 = (__int64)InPlaceInit<RunLaterallyFromTargetTrack>::InPlaceNew;
    dword_1423B4FD0 = FleeTrack::sClassNameUID;
    qword_1423B4FD8 = (__int64)InPlaceInit<FleeTrack>::InPlaceNew;
    dword_1423B4FE0 = SetCurrentEmotionTrack::sClassNameUID;
    qword_1423B4FE8 = (__int64)InPlaceInit<SetCurrentEmotionTrack>::InPlaceNew;
    dword_1423B4FF0 = SetFacialEmotionTrack::sClassNameUID;
    qword_1423B4FF8 = (__int64)InPlaceInit<SetFacialEmotionTrack>::InPlaceNew;
    dword_1423B5000 = HangOutTrack::sClassNameUID;
    qword_1423B5008 = (__int64)InPlaceInit<HangOutTrack>::InPlaceNew;
    dword_1423B5010 = IdleTrack::sClassNameUID;
    qword_1423B5018 = (__int64)InPlaceInit<IdleTrack>::InPlaceNew;
    dword_1423B5020 = CollisionAvoidanceTrack::sClassNameUID;
    qword_1423B5028 = (__int64)InPlaceInit<CollisionAvoidanceTrack>::InPlaceNew;
    dword_1423B5030 = Pathing_OverrideCollisionAvoidanceTypeTrack::sClassNameUID;
    qword_1423B5038 = (__int64)InPlaceInit<Pathing_OverrideCollisionAvoidanceTypeTrack>::InPlaceNew;
    dword_1423B5040 = PathfindToTargetTrack::sClassNameUID;
    qword_1423B5048 = (__int64)InPlaceInit<PathfindToTargetTrack>::InPlaceNew;
    dword_1423B5050 = PathfindAwayFromTargetTrack::sClassNameUID;
    qword_1423B5058 = (__int64)InPlaceInit<PathfindAwayFromTargetTrack>::InPlaceNew;
    dword_1423B5060 = MoveDirectlyToTargetTrack::sClassNameUID;
    qword_1423B5068 = (__int64)InPlaceInit<MoveDirectlyToTargetTrack>::InPlaceNew;
    dword_1423B5070 = CircleAroundCombatantsTrack::sClassNameUID;
    qword_1423B5078 = (__int64)InPlaceInit<CircleAroundCombatantsTrack>::InPlaceNew;
    dword_1423B5080 = UsePOITrack::sClassNameUID;
    qword_1423B5088 = (__int64)InPlaceInit<UsePOITrack>::InPlaceNew;
    dword_1423B5090 = POIBeginTrack::sClassNameUID;
    qword_1423B5098 = (__int64)InPlaceInit<POIBeginTrack>::InPlaceNew;
    dword_1423B50A0 = POIBehaviourActiveTrack::sClassNameUID;
    qword_1423B50A8 = (__int64)InPlaceInit<POIBehaviourActiveTrack>::InPlaceNew;
    dword_1423B50B0 = POIManagementTrack::sClassNameUID;
    qword_1423B50B8 = (__int64)InPlaceInit<POIManagementTrack>::InPlaceNew;
    dword_1423B50C0 = POIDisableSelfTrack::sClassNameUID;
    qword_1423B50C8 = (__int64)InPlaceInit<POIDisableSelfTrack>::InPlaceNew;
    dword_1423B50D0 = POIEnableChildTrack::sClassNameUID;
    qword_1423B50D8 = (__int64)InPlaceInit<POIEnableChildTrack>::InPlaceNew;
    dword_1423B50E0 = AIObjectiveTrack::sClassNameUID;
    qword_1423B50E8 = (__int64)InPlaceInit<AIObjectiveTrack>::InPlaceNew;
    dword_1423B50F0 = FollowTargetTrack::sClassNameUID;
    qword_1423B50F8 = (__int64)InPlaceInit<FollowTargetTrack>::InPlaceNew;
    dword_1423B5100 = AITargetingParametersTrack::sClassNameUID;
    qword_1423B5108 = (__int64)InPlaceInit<AITargetingParametersTrack>::InPlaceNew;
    dword_1423B5110 = AIAddSupplementaryAttackTargetTrack::sClassNameUID;
    qword_1423B5118 = (__int64)InPlaceInit<AIAddSupplementaryAttackTargetTrack>::InPlaceNew;
    dword_1423B5120 = AIRemoveSupplementaryAttackTargetTrack::sClassNameUID;
    qword_1423B5128 = (__int64)InPlaceInit<AIRemoveSupplementaryAttackTargetTrack>::InPlaceNew;
    dword_1423B5130 = SetOutOfFightTrack::sClassNameUID;
    qword_1423B5138 = (__int64)InPlaceInit<SetOutOfFightTrack>::InPlaceNew;
    dword_1423B5140 = GetInFormationTrack::sClassNameUID;
    qword_1423B5148 = (__int64)InPlaceInit<GetInFormationTrack>::InPlaceNew;
    dword_1423B5150 = GetInPedFormationTrack::sClassNameUID;
    qword_1423B5158 = (__int64)InPlaceInit<GetInPedFormationTrack>::InPlaceNew;
    dword_1423B5160 = LeaveGroupTrack::sClassNameUID;
    qword_1423B5168 = (__int64)InPlaceInit<LeaveGroupTrack>::InPlaceNew;
    dword_1423B5170 = JustPerformedRunningAttackTrack::sClassNameUID;
    qword_1423B5178 = (__int64)InPlaceInit<JustPerformedRunningAttackTrack>::InPlaceNew;
    dword_1423B5180 = RequestFormationPositionChangeTrack::sClassNameUID;
    qword_1423B5188 = (__int64)InPlaceInit<RequestFormationPositionChangeTrack>::InPlaceNew;
    dword_1423B5190 = FireWeaponTrack::sClassNameUID;
    qword_1423B5198 = (__int64)InPlaceInit<FireWeaponTrack>::InPlaceNew;
    dword_1423B51A0 = AICoverSearchTrack::sClassNameUID;
    qword_1423B51A8 = (__int64)InPlaceInit<AICoverSearchTrack>::InPlaceNew;
    dword_1423B51B0 = AICoverFaceCoverObjectTrack::sClassNameUID;
    qword_1423B51B8 = (__int64)InPlaceInit<AICoverFaceCoverObjectTrack>::InPlaceNew;
    dword_1423B51C0 = AICoverClearCoverObjectTrack::sClassNameUID;
    qword_1423B51C8 = (__int64)InPlaceInit<AICoverClearCoverObjectTrack>::InPlaceNew;
    dword_1423B51D0 = AICoverLatchTargetedObjectTrack::sClassNameUID;
    qword_1423B51D8 = (__int64)InPlaceInit<AICoverLatchTargetedObjectTrack>::InPlaceNew;
    dword_1423B51E0 = AICopReleaseArrestRightTrack::sClassNameUID;
    qword_1423B51E8 = (__int64)InPlaceInit<AICopReleaseArrestRightTrack>::InPlaceNew;
    dword_1423B51F0 = AICopReportInfractionTargetTrack::sClassNameUID;
    qword_1423B51F8 = (__int64)InPlaceInit<AICopReportInfractionTargetTrack>::InPlaceNew;
    dword_1423B5200 = AICopApplyReducedRadiusTrack::sClassNameUID;
    qword_1423B5208 = (__int64)InPlaceInit<AICopApplyReducedRadiusTrack>::InPlaceNew;
    dword_1423B5210 = AIOverrideAvoidanceRadiusTrack::sClassNameUID;
    qword_1423B5218 = (__int64)InPlaceInit<AIOverrideAvoidanceRadiusTrack>::InPlaceNew;
    dword_1423B5220 = InvalidateFormationPositionTrack::sClassNameUID;
    qword_1423B5228 = (__int64)InPlaceInit<InvalidateFormationPositionTrack>::InPlaceNew;
    dword_1423B5230 = MoveToBetterAttackPositionTrack::sClassNameUID;
    qword_1423B5238 = (__int64)InPlaceInit<MoveToBetterAttackPositionTrack>::InPlaceNew;
    dword_1423B5240 = MoveToFindLineOfSightTrack::sClassNameUID;
    qword_1423B5248 = (__int64)InPlaceInit<MoveToFindLineOfSightTrack>::InPlaceNew;
    dword_1423B5250 = WaitUntilAbleToPathToTargetTrack::sClassNameUID;
    qword_1423B5258 = (__int64)InPlaceInit<WaitUntilAbleToPathToTargetTrack>::InPlaceNew;
    dword_1423B5260 = InteractingWithVehicleHeuristicTrack::sClassNameUID;
    qword_1423B5268 = (__int64)InPlaceInit<InteractingWithVehicleHeuristicTrack>::InPlaceNew;
    dword_1423B5270 = AIAwarenessEnableTrack::sClassNameUID;
    qword_1423B5278 = (__int64)InPlaceInit<AIAwarenessEnableTrack>::InPlaceNew;
    dword_1423B5280 = AIAwarenessAddTargetTrack::sClassNameUID;
    qword_1423B5288 = (__int64)InPlaceInit<AIAwarenessAddTargetTrack>::InPlaceNew;
    dword_1423B5290 = LookAtTrack::sClassNameUID;
    qword_1423B5298 = (__int64)InPlaceInit<LookAtTrack>::InPlaceNew;
    dword_1423B52A0 = TestPathToTargetTrack::sClassNameUID;
    qword_1423B52A8 = (__int64)InPlaceInit<TestPathToTargetTrack>::InPlaceNew;
    dword_1423B52B0 = FaceMeterActivateTrack::sClassNameUID;
    qword_1423B52B8 = (__int64)InPlaceInit<FaceMeterActivateTrack>::InPlaceNew;
    dword_1423B52C0 = FaceInteractionResultSetTrack::sClassNameUID;
    qword_1423B52C8 = (__int64)InPlaceInit<FaceInteractionResultSetTrack>::InPlaceNew;
    dword_1423B52D0 = PlayerBuffActivateTrack::sClassNameUID;
    qword_1423B52D8 = (__int64)InPlaceInit<PlayerBuffActivateTrack>::InPlaceNew;
    dword_1423B52E0 = HUDSocialActionChargeTrack::sClassNameUID;
    qword_1423B52E8 = (__int64)InPlaceInit<HUDSocialActionChargeTrack>::InPlaceNew;
    dword_1423B52F0 = HUDSocialActionActivateTrack::sClassNameUID;
    qword_1423B52F8 = (__int64)InPlaceInit<HUDSocialActionActivateTrack>::InPlaceNew;
    dword_1423B5300 = HUDSocialActionEnableTrack::sClassNameUID;
    qword_1423B5308 = (__int64)InPlaceInit<HUDSocialActionEnableTrack>::InPlaceNew;
    dword_1423B5310 = SocialSetFaceActionStateTrack::sClassNameUID;
    qword_1423B5318 = (__int64)InPlaceInit<SocialSetFaceActionStateTrack>::InPlaceNew;
    dword_1423B5320 = SocialFaceActionDisplayConfirmationDialogTrack::sClassNameUID;
    qword_1423B5328 = (__int64)InPlaceInit<SocialFaceActionDisplayConfirmationDialogTrack>::InPlaceNew;
    dword_1423B5330 = SocialSetFastTalkSuccessTrack::sClassNameUID;
    qword_1423B5338 = (__int64)InPlaceInit<SocialSetFastTalkSuccessTrack>::InPlaceNew;
    dword_1423B5340 = ObjectReferenceTrack::sClassNameUID;
    qword_1423B5348 = (__int64)InPlaceInit<ObjectReferenceTrack>::InPlaceNew;
    dword_1423B5350 = ObjectCreateTrack::sClassNameUID;
    qword_1423B5358 = (__int64)InPlaceInit<ObjectCreateTrack>::InPlaceNew;
    dword_1423B5360 = ObjectCreateFromPropertiesTrack::sClassNameUID;
    qword_1423B5368 = (__int64)InPlaceInit<ObjectCreateFromPropertiesTrack>::InPlaceNew;
    dword_1423B5370 = HideTrack::sClassNameUID;
    qword_1423B5378 = (__int64)InPlaceInit<HideTrack>::InPlaceNew;
    dword_1423B5380 = UnhideTrack::sClassNameUID;
    qword_1423B5388 = (__int64)InPlaceInit<UnhideTrack>::InPlaceNew;
    dword_1423B5390 = SelectSuitableVehicleTrack::sClassNameUID;
    qword_1423B5398 = (__int64)InPlaceInit<SelectSuitableVehicleTrack>::InPlaceNew;
    dword_1423B53A0 = DriverPathfindToTargetTrack::sClassNameUID;
    qword_1423B53A8 = (__int64)InPlaceInit<DriverPathfindToTargetTrack>::InPlaceNew;
    dword_1423B53B0 = DriverFollowTargetTrack::sClassNameUID;
    qword_1423B53B8 = (__int64)InPlaceInit<DriverFollowTargetTrack>::InPlaceNew;
    dword_1423B53C0 = DriverChaseTargetTrack::sClassNameUID;
    qword_1423B53C8 = (__int64)InPlaceInit<DriverChaseTargetTrack>::InPlaceNew;
    dword_1423B53D0 = DriverWanderTrack::sClassNameUID;
    qword_1423B53D8 = (__int64)InPlaceInit<DriverWanderTrack>::InPlaceNew;
    dword_1423B53E0 = DriverStopTrack::sClassNameUID;
    qword_1423B53E8 = (__int64)InPlaceInit<DriverStopTrack>::InPlaceNew;
    dword_1423B53F0 = PlayerGrappleTrack::sClassNameUID;
    qword_1423B53F8 = (__int64)InPlaceInit<PlayerGrappleTrack>::InPlaceNew;
    dword_1423B5400 = SetHighlightingModeTrack::sClassNameUID;
    qword_1423B5408 = (__int64)InPlaceInit<SetHighlightingModeTrack>::InPlaceNew;
    dword_1423B5410 = SetOpeningBranchTrack::sClassNameUID;
    qword_1423B5418 = (__int64)InPlaceInit<SetOpeningBranchTrack>::InPlaceNew;
    dword_1423B5420 = GroupStimulusTrack::sClassNameUID;
    qword_1423B5428 = (__int64)InPlaceInit<GroupStimulusTrack>::InPlaceNew;
    dword_1423B5430 = AttackRightsSetTimeUntilNextAttackTrack::sClassNameUID;
    qword_1423B5438 = (__int64)InPlaceInit<AttackRightsSetTimeUntilNextAttackTrack>::InPlaceNew;
    dword_1423B5440 = AttackRightsClearPreviousBestAttackerTrack::sClassNameUID;
    qword_1423B5448 = (__int64)InPlaceInit<AttackRightsClearPreviousBestAttackerTrack>::InPlaceNew;
    dword_1423B5450 = AttackRightsReSortListTrack::sClassNameUID;
    qword_1423B5458 = (__int64)InPlaceInit<AttackRightsReSortListTrack>::InPlaceNew;
    dword_1423B5460 = AttackRightsCancelAnyIncomingAttackTrack::sClassNameUID;
    qword_1423B5468 = (__int64)InPlaceInit<AttackRightsCancelAnyIncomingAttackTrack>::InPlaceNew;
    dword_1423B5470 = AttackRightsFormationManagerFreezeRangeSwitchesTrack::sClassNameUID;
    qword_1423B5478 = (__int64)InPlaceInit<AttackRightsFormationManagerFreezeRangeSwitchesTrack>::InPlaceNew;
    dword_1423B5480 = CarStopTrack::sClassNameUID;
    qword_1423B5488 = (__int64)InPlaceInit<CarStopTrack>::InPlaceNew;
    dword_1423B5490 = CarStopAtTrack::sClassNameUID;
    qword_1423B5498 = (__int64)InPlaceInit<CarStopAtTrack>::InPlaceNew;
    dword_1423B54A0 = CarStopAtStimulusTrack::sClassNameUID;
    qword_1423B54A8 = (__int64)InPlaceInit<CarStopAtStimulusTrack>::InPlaceNew;
    dword_1423B54B0 = CarWaitTrack::sClassNameUID;
    qword_1423B54B8 = (__int64)InPlaceInit<CarWaitTrack>::InPlaceNew;
    dword_1423B54C0 = CarWanderTrack::sClassNameUID;
    qword_1423B54C8 = (__int64)InPlaceInit<CarWanderTrack>::InPlaceNew;
    dword_1423B54D0 = CarFollowTrack::sClassNameUID;
    qword_1423B54D8 = (__int64)InPlaceInit<CarFollowTrack>::InPlaceNew;
    dword_1423B54E0 = CarEscortTrack::sClassNameUID;
    qword_1423B54E8 = (__int64)InPlaceInit<CarEscortTrack>::InPlaceNew;
    dword_1423B54F0 = CarRaceTrack::sClassNameUID;
    qword_1423B54F8 = (__int64)InPlaceInit<CarRaceTrack>::InPlaceNew;
    dword_1423B5500 = CarGoToTrack::sClassNameUID;
    qword_1423B5508 = (__int64)InPlaceInit<CarGoToTrack>::InPlaceNew;
    dword_1423B5510 = CarNoDestinationTrack::sClassNameUID;
    qword_1423B5518 = (__int64)InPlaceInit<CarNoDestinationTrack>::InPlaceNew;
    dword_1423B5520 = CarAttackTrack::sClassNameUID;
    qword_1423B5528 = (__int64)InPlaceInit<CarAttackTrack>::InPlaceNew;
    dword_1423B5530 = CarFormationAttackTrack::sClassNameUID;
    qword_1423B5538 = (__int64)InPlaceInit<CarFormationAttackTrack>::InPlaceNew;
    dword_1423B5540 = CarFormationTrack::sClassNameUID;
    qword_1423B5548 = (__int64)InPlaceInit<CarFormationTrack>::InPlaceNew;
    dword_1423B5550 = CarOffsetDriveTrack::sClassNameUID;
    qword_1423B5558 = (__int64)InPlaceInit<CarOffsetDriveTrack>::InPlaceNew;
    dword_1423B5560 = CarFormationDriveTrack::sClassNameUID;
    qword_1423B5568 = (__int64)InPlaceInit<CarFormationDriveTrack>::InPlaceNew;
    dword_1423B5570 = CarOccupantAimTrack::sClassNameUID;
    qword_1423B5578 = (__int64)InPlaceInit<CarOccupantAimTrack>::InPlaceNew;
    dword_1423B5580 = CarOccupantShootTrack::sClassNameUID;
    qword_1423B5588 = (__int64)InPlaceInit<CarOccupantShootTrack>::InPlaceNew;
    dword_1423B5590 = CarOccupantIntentionTrack::sClassNameUID;
    qword_1423B5598 = (__int64)InPlaceInit<CarOccupantIntentionTrack>::InPlaceNew;
    dword_1423B55A0 = CarOccupantsActionTrack::sClassNameUID;
    qword_1423B55A8 = (__int64)InPlaceInit<CarOccupantsActionTrack>::InPlaceNew;
    dword_1423B55B0 = SetCarModeTrack::sClassNameUID;
    qword_1423B55B8 = (__int64)InPlaceInit<SetCarModeTrack>::InPlaceNew;
    dword_1423B55C0 = VehicleAudioEventTrack::sClassNameUID;
    qword_1423B55C8 = (__int64)InPlaceInit<VehicleAudioEventTrack>::InPlaceNew;
    dword_1423B55D0 = VehicleEffectTrack::sClassNameUID;
    qword_1423B55D8 = (__int64)InPlaceInit<VehicleEffectTrack>::InPlaceNew;
    dword_1423B55E0 = VehicleEnableTemporaryPassTrack::sClassNameUID;
    qword_1423B55E8 = (__int64)InPlaceInit<VehicleEnableTemporaryPassTrack>::InPlaceNew;
    dword_1423B55F0 = VehicleQueueHeadlightFlashesTrack::sClassNameUID;
    qword_1423B55F8 = (__int64)InPlaceInit<VehicleQueueHeadlightFlashesTrack>::InPlaceNew;
    dword_1423B5600 = StruggleTrack::sClassNameUID;
    qword_1423B5608 = (__int64)InPlaceInit<StruggleTrack>::InPlaceNew;
    dword_1423B5610 = Struggle2Track::sClassNameUID;
    qword_1423B5618 = (__int64)InPlaceInit<Struggle2Track>::InPlaceNew;
    dword_1423B5620 = InputSignalFilterTrack::sClassNameUID;
    qword_1423B5628 = (__int64)InPlaceInit<InputSignalFilterTrack>::InPlaceNew;
    dword_1423B5630 = InputSignalLerpFilterTrack::sClassNameUID;
    qword_1423B5638 = (__int64)InPlaceInit<InputSignalLerpFilterTrack>::InPlaceNew;
    dword_1423B5640 = InputEnableMappingTrack::sClassNameUID;
    qword_1423B5648 = (__int64)InPlaceInit<InputEnableMappingTrack>::InPlaceNew;
    dword_1423B5650 = ActorStateCounterTrack::sClassNameUID;
    qword_1423B5658 = (__int64)InPlaceInit<ActorStateCounterTrack>::InPlaceNew;
    dword_1423B5660 = GameStatEventTrack::sClassNameUID;
    qword_1423B5668 = (__int64)InPlaceInit<GameStatEventTrack>::InPlaceNew;
    dword_1423B5670 = GameStatDistanceTrack::sClassNameUID;
    qword_1423B5678 = (__int64)InPlaceInit<GameStatDistanceTrack>::InPlaceNew;
    dword_1423B5680 = GameStatSpecialMoveTrack::sClassNameUID;
    qword_1423B5688 = (__int64)InPlaceInit<GameStatSpecialMoveTrack>::InPlaceNew;
    dword_1423B5690 = AccuracyOverrideTrack::sClassNameUID;
    qword_1423B5698 = (__int64)InPlaceInit<AccuracyOverrideTrack>::InPlaceNew;
    dword_1423B56A0 = AccuracyEnsureMissTrack::sClassNameUID;
    qword_1423B56A8 = (__int64)InPlaceInit<AccuracyEnsureMissTrack>::InPlaceNew;
    dword_1423B56B0 = ReticleSizeOverrideTrack::sClassNameUID;
    qword_1423B56B8 = (__int64)InPlaceInit<ReticleSizeOverrideTrack>::InPlaceNew;
    dword_1423B56C0 = AccuracyModifierTrack::sClassNameUID;
    qword_1423B56C8 = (__int64)InPlaceInit<AccuracyModifierTrack>::InPlaceNew;
    dword_1423B56D0 = CollectibleCollectTrack::sClassNameUID;
    qword_1423B56D8 = (__int64)InPlaceInit<CollectibleCollectTrack>::InPlaceNew;
    dword_1423B56E0 = SimObjectFlagSetTrack::sClassNameUID;
    qword_1423B56E8 = (__int64)InPlaceInit<SimObjectFlagSetTrack>::InPlaceNew;
    dword_1423B56F0 = SetStateFlagTrack::sClassNameUID;
    qword_1423B56F8 = (__int64)InPlaceInit<SetStateFlagTrack>::InPlaceNew;
    dword_1423B5700 = ReadControllerInputTrack::sClassNameUID;
    qword_1423B5708 = (__int64)InPlaceInit<ReadControllerInputTrack>::InPlaceNew;
    dword_1423B5710 = AttackRightsScoreBonusTrack::sClassNameUID;
    qword_1423B5718 = (__int64)InPlaceInit<AttackRightsScoreBonusTrack>::InPlaceNew;
    dword_1423B5720 = LockFormationPositionToCurrentPositionTrack::sClassNameUID;
    qword_1423B5728 = (__int64)InPlaceInit<LockFormationPositionToCurrentPositionTrack>::InPlaceNew;
    dword_1423B5730 = ForceUpdateTargetingTrack::sClassNameUID;
    qword_1423B5738 = (__int64)InPlaceInit<ForceUpdateTargetingTrack>::InPlaceNew;
    dword_1423B5740 = AIOutlineActivateTrack::sClassNameUID;
    qword_1423B5748 = (__int64)InPlaceInit<AIOutlineActivateTrack>::InPlaceNew;
    dword_1423B5750 = MoneyDropTrack::sClassNameUID;
    qword_1423B5758 = (__int64)InPlaceInit<MoneyDropTrack>::InPlaceNew;
    dword_1423B5760 = MoneyPickupTrack::sClassNameUID;
    qword_1423B5768 = (__int64)InPlaceInit<MoneyPickupTrack>::InPlaceNew;
    dword_1423B5770 = ItemPickupTrack::sClassNameUID;
    qword_1423B5778 = (__int64)InPlaceInit<ItemPickupTrack>::InPlaceNew;
    dword_1423B5780 = AddTargetAsDangerousEntityTrack::sClassNameUID;
    qword_1423B5788 = (__int64)InPlaceInit<AddTargetAsDangerousEntityTrack>::InPlaceNew;
    dword_1423B5790 = SetDriverFlagsTrack::sClassNameUID;
    qword_1423B5798 = (__int64)InPlaceInit<SetDriverFlagsTrack>::InPlaceNew;
    dword_1423B57A0 = LightingRimBoostTrack::sClassNameUID;
    qword_1423B57A8 = (__int64)InPlaceInit<LightingRimBoostTrack>::InPlaceNew;
    dword_1423B57B0 = UpdateHijackableVehicleTargetTrack::sClassNameUID;
    qword_1423B57B8 = (__int64)InPlaceInit<UpdateHijackableVehicleTargetTrack>::InPlaceNew;
    dword_1423B57C0 = TriggerRecoilPostEffectTrack::sClassNameUID;
    qword_1423B57C8 = (__int64)InPlaceInit<TriggerRecoilPostEffectTrack>::InPlaceNew;
    dword_1423B57D0 = SetCharacterOnFireTrack::sClassNameUID;
    qword_1423B57D8 = (__int64)InPlaceInit<SetCharacterOnFireTrack>::InPlaceNew;
    dword_1423B57E0 = SetCharacterInvulnerableToFireTrack::sClassNameUID;
    qword_1423B57E8 = (__int64)InPlaceInit<SetCharacterInvulnerableToFireTrack>::InPlaceNew;
    dword_1423B57F0 = UFG::PredictiveSubPriorityModifierTrack::sClassNameUID;
    qword_1423B57F8 = (__int64)InPlaceInit<UFG::PredictiveSubPriorityModifierTrack>::InPlaceNew;
    dword_1423B5800 = ActionController::sClassNameUID;
    qword_1423B5808 = (__int64)InPlaceInit<ActionController>::InPlaceNew;
    dword_1423B5810 = IntentionDebug::sClassNameUID;
    qword_1423B5818 = (__int64)InPlaceInit<IntentionDebug>::InPlaceNew;
    dword_1423B5820 = DebugDrawMyPositionTrack::sClassNameUID;
    qword_1423B5828 = (__int64)InPlaceInit<DebugDrawMyPositionTrack>::InPlaceNew;
    dword_1423B5830 = DebugDrawMyTargetTrack::sClassNameUID;
    qword_1423B5838 = (__int64)InPlaceInit<DebugDrawMyTargetTrack>::InPlaceNew;
    dword_1423B5840 = TrackGroup::sClassNameUID;
    qword_1423B5848 = (__int64)InPlaceInit<TrackGroup>::InPlaceNew;
    dword_1423B5850 = ActionNodeReference::sClassNameUID;
    qword_1423B5858 = (__int64)InPlaceInit<ActionNodeReference>::InPlaceNew;
    dword_1423B5860 = CanAttackConditionGroup::sClassNameUID;
    qword_1423B5868 = (__int64)InPlaceInit<CanAttackConditionGroup>::InPlaceNew;
    dword_1423B5870 = WeightSetGroup::sClassNameUID;
    qword_1423B5878 = (__int64)InPlaceInit<WeightSetGroup>::InPlaceNew;
    dword_1423B5880 = UELFragmentTable::sClassNameUID;
    qword_1423B5888 = (__int64)InPlaceInit<UELFragmentTable>::InPlaceNew;
    dword_1423B5890 = UELGroupNode::sClassNameUID;
    qword_1423B5898 = (__int64)InPlaceInit<UELGroupNode>::InPlaceNew;
    dword_1423B58A0 = UELFragmentNode::sClassNameUID;
    qword_1423B58A8 = (__int64)InPlaceInit<UELFragmentNode>::InPlaceNew;
    dword_1423B58B0 = RigInfo::sClassNameUID;
    qword_1423B58B8 = (__int64)InPlaceInit<RigInfo>::InPlaceNew;
    dword_1423B58C0 = JointReferences::sClassNameUID;
    qword_1423B58C8 = (__int64)InPlaceInit<JointReferences>::InPlaceNew;
    dword_1423B58D0 = TestClassB::sClassNameUID;
    qword_1423B58D8 = (__int64)InPlaceInit<TestClassB>::InPlaceNew;
    dword_1423B58E0 = TestClassC::sClassNameUID;
    qword_1423B58E8 = (__int64)InPlaceInit<TestClassC>::InPlaceNew;
    dword_1423B58F0 = UEL::UnaryExpression::sClassNameUID;
    qword_1423B58F8 = (__int64)InPlaceInit<UEL::UnaryExpression>::InPlaceNew;
    dword_1423B5900 = UEL::BinaryExpression::sClassNameUID;
    qword_1423B5908 = (__int64)InPlaceInit<UEL::BinaryExpression>::InPlaceNew;
    dword_1423B5910 = UEL::ConstantExpression::sClassNameUID;
    qword_1423B5918 = (__int64)InPlaceInit<UEL::ConstantExpression>::InPlaceNew;
    dword_1423B5920 = UEL::ParameterExpression::sClassNameUID;
    qword_1423B5928 = (__int64)InPlaceInit<UEL::ParameterExpression>::InPlaceNew;
    dword_1423B5930 = UEL::InvocationExpression::sClassNameUID;
    qword_1423B5938 = (__int64)InPlaceInit<UEL::InvocationExpression>::InPlaceNew;
    dword_1423B5940 = UEL::FragmentExpression::sClassNameUID;
    qword_1423B5948 = (__int64)InPlaceInit<UEL::FragmentExpression>::InPlaceNew;
    dword_1423B5950 = UEL::ArgumentExpression::sClassNameUID;
    qword_1423B5958 = (__int64)InPlaceInit<UEL::ArgumentExpression>::InPlaceNew;
    dword_1423B5960 = UEL::FragmentInvocationExpression::sClassNameUID;
    qword_1423B5968 = (__int64)InPlaceInit<UEL::FragmentInvocationExpression>::InPlaceNew;
    dword_1423B5970 = UEL::ArgumentUsageExpression::sClassNameUID;
    qword_1423B5978 = (__int64)InPlaceInit<UEL::ArgumentUsageExpression>::InPlaceNew;
    dword_1423B5980 = UEL::Value::sClassNameUID;
    qword_1423B5988 = (__int64)InPlaceInit<UEL::Value>::InPlaceNew;
    right.mUID = UEL::Value::Type::sClassNameUID;
    right.mfnInPlaceNew = InPlaceInit<UEL::Value>::InPlaceNew;
    v1 = count;
  }
  if ( once_1 )
  {
    UFG::qQuickSortImpl<UFG::ClosePhysicalTarget,bool (*)(UFG::ClosePhysicalTarget const &,UFG::ClosePhysicalTarget const &)>(
      gTypeDescriptors,
      &right,
      BlendTreeDataBase::UIDSort);
    once_1 = 0;
  }
  *v1 = 1003;
  return gTypeDescriptors;
}t<TestClassB>::InPlaceNew;
    dword_1423B58E0 = TestClassC::sClassNameUID;
    qword_1423B58E8 = (__int64)InPlaceInit<TestClassC>::InPlaceNew;
    dword_1423B58F0 = UEL::UnaryExpression::sClassNameUID;
    qword_1423B58F8 = (__int64)InPlaceInit<UEL::UnaryExpression>::InPlaceNew;
    dword_1423B5900 = UEL::BinaryExpression::sClassNameUID;
    qword_1423B5908 = (__int64)InPlaceInit<UEL::BinaryExpression>::InPlaceNew;
    dword_1423B5910 = UEL::ConstantExpression::sClassNameUID;
    qword_1423B5918 = (__int64)InPlaceInit<UEL::ConstantExpression>::InPlaceNew;
    dword_1423B5920 = UEL::ParameterExpression::sClassNameUID;
    qword_1423B5928 = (__int64)InPlaceInit<UEL::ParameterExpression>::InPlaceNew;
    dword_1423B5930 = UEL::InvocationExpression::sClassNameUID;
    qword_1423B5938 = (__int64)InPlaceInit<UEL::InvocationExpression>::InPlaceNew;
    dword_1423B5940 = UEL::

// File Line: 126
// RVA: 0x2BD5F0
void __fastcall Fixup(TypeTable *typeTable, void *resource)
{
  TypeTable *v2; // rbx
  char *v3; // rbp
  UFG::qOffset64<TypeTableEntry *> *v4; // rdi
  ClassTypeDescriptor *v5; // r10
  char *v6; // rsi
  unsigned int v7; // er9
  unsigned int v8; // edx
  __int64 v9; // rax
  unsigned int v10; // ebx
  char *v11; // rcx
  char *v12; // rdx
  unsigned int count; // [rsp+30h] [rbp+8h]

  v2 = typeTable;
  v3 = (char *)resource;
  count = 0;
  v4 = &typeTable->mEntries;
  v5 = GetTypeDescriptors(&count);
  if ( v4->mOffset )
    v6 = (char *)v4 + v4->mOffset;
  else
    v6 = 0i64;
  v7 = 0;
  if ( v2->mNumEntries )
  {
    v8 = count;
    do
    {
      v9 = 0i64;
      if ( v8 )
      {
        while ( v5[(unsigned int)v9].mUID != *(_DWORD *)&v6[16 * v7] )
        {
          v9 = (unsigned int)(v9 + 1);
          if ( (unsigned int)v9 >= v8 )
            goto LABEL_11;
        }
        *(_QWORD *)&v6[16 * v7 + 8] = v5[v9].mfnInPlaceNew;
      }
LABEL_11:
      ++v7;
    }
    while ( v7 < v2->mNumEntries );
  }
  UFG::qSymbolRegistry::SetAssertOnEmptySymbolCtor(1);
  v10 = 4 * v2->mFirstFixupOffset;
  while ( v10 )
  {
    v11 = &v3[v10];
    v10 = 4 * (*(_DWORD *)v11 & 0x7FFFFF);
    if ( v4->mOffset )
      v12 = (char *)v4 + v4->mOffset;
    else
      v12 = 0i64;
    (*(void (**)(void))&v12[16 * (*(_DWORD *)v11 >> 23) + 8])();
  }
  UFG::qSymbolRegistry::SetAssertOnEmptySymbolCtor(0);
}

// File Line: 185
// RVA: 0x2AEE60
void __fastcall ActionTreeResourceInventory::Add(ActionTreeResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  ActionTreeResourceInventory *v3; // rsi
  UFG::qBaseNodeRB *v4; // rax
  signed __int64 v5; // rdi
  TypeTable *v6; // rcx
  UFG::qBaseNodeRB *v7; // rax

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  v4 = v2[1].mNode.mChild[0];
  v5 = 0i64;
  if ( v4 )
    v6 = (TypeTable *)((char *)v2[1].mNode.mChild + (_QWORD)v4);
  else
    v6 = 0i64;
  Fixup(v6, v2);
  v7 = v2[1].mNode.mParent;
  if ( v7 )
    v5 = (signed __int64)&v2[1] + (_QWORD)v7;
  ActionNode::smRoot->vfptr[2].__vecDelDtor((Expression::IMemberMap *)ActionNode::smRoot, v5);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
  v3->mpLastLoadedResource = (ActionTreeResource *)v2;
}

// File Line: 225
// RVA: 0x2DC500
void __fastcall ActionTreeResourceInventory::Remove(ActionTreeResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rdi
  ActionTreeResourceInventory *v3; // rsi
  UFG::qBaseNodeRB *v4; // rax
  IActionTreeSerializer *v5; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rax

  v2 = resource_data;
  v3 = this;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v4 = v2[1].mNode.mParent;
  if ( v4 )
    v5 = (IActionTreeSerializer *)((char *)&v2[1] + (_QWORD)v4);
  else
    v5 = 0i64;
  ActionNode::smRoot->vfptr[2].Serialize((Expression::IMemberMap *)ActionNode::smRoot, v5);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
  v6 = v2->mResourceHandles.mNode.mPrev;
  v7 = v2->mResourceHandles.mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v2->mResourceHandles.mNode.mPrev = &v2->mResourceHandles.mNode;
  v2->mResourceHandles.mNode.mNext = &v2->mResourceHandles.mNode;
  if ( (UFG::qResourceData *)v3->mpLastLoadedResource == v2 )
    v3->mpLastLoadedResource = 0i64;
}

// File Line: 264
// RVA: 0x2AEF00
void __fastcall AnimationGroupResourceInventory::Add(AnimationGroupResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qBaseNodeRB *v3; // rax
  AnimationGroup *v4; // rdi
  TypeTable *v5; // rcx
  UFG::qBaseNodeRB *v6; // rax
  AnimationDataBase *v7; // rax

  v2 = resource_data;
  v3 = resource_data[1].mNode.mChild[0];
  v4 = 0i64;
  if ( v3 )
    v5 = (TypeTable *)((char *)resource_data[1].mNode.mChild + (_QWORD)v3);
  else
    v5 = 0i64;
  Fixup(v5, resource_data);
  UFG::qResourceData::qResourceData(v2);
  v6 = v2[1].mNode.mParent;
  if ( v6 )
    v4 = (AnimationGroup *)((char *)&v2[1] + (_QWORD)v6);
  v7 = AnimationDataBase::GetInstance();
  AnimationDataBase::AddAnimBank(v7, v4);
}

// File Line: 276
// RVA: 0x2DC5A0
void __fastcall AnimationGroupResourceInventory::Remove(AnimationGroupResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rsi
  UFG::qBaseNodeRB *v3; // rax
  AnimationGroup *v4; // rbx
  AnimationGroup *v5; // rdi
  AnimationDataBase *v6; // rax
  UFG::qBaseNodeRB *v7; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rax

  v2 = resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v3 = v2[1].mNode.mParent;
  v4 = 0i64;
  if ( v3 )
    v5 = (AnimationGroup *)((char *)&v2[1] + (_QWORD)v3);
  else
    v5 = 0i64;
  v6 = AnimationDataBase::GetInstance();
  AnimationDataBase::RemoveAnimBank(v6, v5);
  v7 = v2[1].mNode.mParent;
  if ( v7 )
    v4 = (AnimationGroup *)((char *)&v2[1] + (_QWORD)v7);
  AnimationGroup::Destroy(v4);
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
  v8 = v2->mResourceHandles.mNode.mPrev;
  v9 = v2->mResourceHandles.mNode.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mResourceHandles.mNode.mPrev = &v2->mResourceHandles.mNode;
  v2->mResourceHandles.mNode.mNext = &v2->mResourceHandles.mNode;
}

// File Line: 297
// RVA: 0x2AEFE0
void __fastcall RigInfoResourceInventory::Add(RigInfoResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qBaseNodeRB *v3; // rax
  WeightSetGroup *v4; // rdi
  TypeTable *v5; // rcx
  UFG::qBaseNodeRB *v6; // rax
  WeightSetDataBase *v7; // rax

  v2 = resource_data;
  v3 = resource_data[1].mNode.mChild[0];
  v4 = 0i64;
  if ( v3 )
    v5 = (TypeTable *)((char *)resource_data[1].mNode.mChild + (_QWORD)v3);
  else
    v5 = 0i64;
  Fixup(v5, resource_data);
  UFG::qResourceData::qResourceData(v2);
  v6 = v2[1].mNode.mParent;
  if ( v6 )
    v4 = (WeightSetGroup *)((char *)&v2[1] + (_QWORD)v6);
  v7 = (WeightSetDataBase *)RigInfoDataBase::GetInstance();
  WeightSetDataBase::AddWeightSetGroup(v7, v4);
}

// File Line: 310
// RVA: 0x2DC6C0
void __fastcall RigInfoResourceInventory::Remove(RigInfoResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qBaseNodeRB *v3; // rax
  WeightSetGroup *v4; // rdi
  WeightSetDataBase *v5; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v8; // [rsp+48h] [rbp+10h]

  v2 = resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v3 = v2[1].mNode.mParent;
  if ( v3 )
    v4 = (WeightSetGroup *)((char *)&v2[1] + (_QWORD)v3);
  else
    v4 = 0i64;
  v5 = (WeightSetDataBase *)RigInfoDataBase::GetInstance();
  RigInfoDataBase::RemoveRigInfo(v5, v4);
  v8 = &v2->mResourceHandles;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
  v6 = v2->mResourceHandles.mNode.mPrev;
  v7 = v2->mResourceHandles.mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
}

// File Line: 330
// RVA: 0x2AEF70
void __fastcall BlendTreeResourceInventory::Add(BlendTreeResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qBaseNodeRB *v3; // rax
  PoseNode *v4; // rdi
  TypeTable *v5; // rcx
  UFG::qBaseNodeRB *v6; // rax
  BlendTreeDataBase *v7; // rax

  v2 = resource_data;
  v3 = resource_data[1].mNode.mChild[0];
  v4 = 0i64;
  if ( v3 )
    v5 = (TypeTable *)((char *)resource_data[1].mNode.mChild + (_QWORD)v3);
  else
    v5 = 0i64;
  Fixup(v5, resource_data);
  UFG::qResourceData::qResourceData(v2);
  v6 = v2[1].mNode.mParent;
  if ( v6 )
    v4 = (PoseNode *)((char *)&v2[1] + (_QWORD)v6);
  v7 = BlendTreeDataBase::GetInstance();
  BlendTreeDataBase::AddBlendTrees(v7, v4);
}

// File Line: 345
// RVA: 0x2DC640
void __fastcall BlendTreeResourceInventory::Remove(BlendTreeResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qBaseNodeRB *v3; // rax
  PoseNode *v4; // rdi
  BlendTreeDataBase *v5; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v8; // [rsp+48h] [rbp+10h]

  v2 = resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v3 = v2[1].mNode.mParent;
  if ( v3 )
    v4 = (PoseNode *)((char *)&v2[1] + (_QWORD)v3);
  else
    v4 = 0i64;
  v5 = BlendTreeDataBase::GetInstance();
  BlendTreeDataBase::RemoveBlendTrees(v5, v4);
  v8 = &v2->mResourceHandles;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
  v6 = v2->mResourceHandles.mNode.mPrev;
  v7 = v2->mResourceHandles.mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
}

// File Line: 366
// RVA: 0x2AF0C0
void __fastcall WeightSetGroupResourceInventory::Add(WeightSetGroupResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qBaseNodeRB *v3; // rax
  WeightSetGroup *v4; // rdi
  TypeTable *v5; // rcx
  UFG::qBaseNodeRB *v6; // rax
  WeightSetDataBase *v7; // rax

  v2 = resource_data;
  v3 = resource_data[1].mNode.mChild[0];
  v4 = 0i64;
  if ( v3 )
    v5 = (TypeTable *)((char *)resource_data[1].mNode.mChild + (_QWORD)v3);
  else
    v5 = 0i64;
  Fixup(v5, resource_data);
  UFG::qResourceData::qResourceData(v2);
  v6 = v2[1].mNode.mParent;
  if ( v6 )
    v4 = (WeightSetGroup *)((char *)&v2[1] + (_QWORD)v6);
  v7 = WeightSetDataBase::GetInstance();
  WeightSetDataBase::AddWeightSetGroup(v7, v4);
}

// File Line: 378
// RVA: 0x2DC7A0
void __fastcall WeightSetGroupResourceInventory::Remove(WeightSetGroupResourceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qBaseNodeRB *v3; // rax
  WeightSetGroup *v4; // rdi
  WeightSetDataBase *v5; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v6; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v8; // [rsp+48h] [rbp+10h]

  v2 = resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  v3 = v2[1].mNode.mParent;
  if ( v3 )
    v4 = (WeightSetGroup *)((char *)&v2[1] + (_QWORD)v3);
  else
    v4 = 0i64;
  v5 = WeightSetDataBase::GetInstance();
  RigInfoDataBase::RemoveRigInfo(v5, v4);
  v8 = &v2->mResourceHandles;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
  v6 = v2->mResourceHandles.mNode.mPrev;
  v7 = v2->mResourceHandles.mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
}

// File Line: 432
// RVA: 0x2AF050
void __fastcall UELFragmentTableInventory::Add(UELFragmentTableInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qBaseNodeRB *v3; // rax
  BinPtrArray<UEL::FragmentExpression,0,0> *v4; // rdi
  TypeTable *v5; // rcx
  UFG::qBaseNodeRB *v6; // rax

  v2 = resource_data;
  v3 = resource_data[1].mNode.mChild[0];
  v4 = 0i64;
  if ( v3 )
    v5 = (TypeTable *)((char *)resource_data[1].mNode.mChild + (_QWORD)v3);
  else
    v5 = 0i64;
  Fixup(v5, resource_data);
  UFG::qResourceData::qResourceData(v2);
  v6 = v2[1].mNode.mParent;
  if ( v6 )
    v4 = (BinPtrArray<UEL::FragmentExpression,0,0> *)((char *)&v2[1] + (_QWORD)v6);
  UFG::UELRuntime::SetFragmentTable(v4 + 1);
}

// File Line: 446
// RVA: 0x2DC740
void __fastcall UELFragmentTableInventory::Remove(UELFragmentTableInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v3; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v5; // [rsp+48h] [rbp+10h]

  v2 = resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  UFG::UELRuntime::SetFragmentTable(0i64);
  v5 = &v2->mResourceHandles;
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0>::DeleteNodes(&v2->mResourceHandles);
  v3 = v2->mResourceHandles.mNode.mPrev;
  v4 = v2->mResourceHandles.mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
}

