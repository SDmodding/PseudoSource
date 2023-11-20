// File Line: 105
// RVA: 0x1566BB0
__int64 dynamic_initializer_for__UFG::UIHKScreenHud::PDACache__()
{
  UFG::qString::qString(&stru_142431A20);
  UFG::UIHKScreenHud::PDACache.state = 0;
  unk_142431A14 = 0;
  unk_142431A18 = 0;
  UFG::qString::Set(&stru_142431A20, &customWorldMapCaption);
  unk_142431A48 = 0;
  unk_142431A4A = 0;
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenHud::PDACache__);
}

// File Line: 109
// RVA: 0x5EC380
void __fastcall UFG::UIHKScreenHud::HandleTutorialHudTexturePackLoaded(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHKScreenHud::mOnDemandTexturesLoaded = 1;
}

// File Line: 114
// RVA: 0x5ED7C0
void UFG::UIHKScreenHud::Initialize(void)
{
  UFG::UIScreenInvokeQueue *v0; // rax
  UFG::allocator::free_link *v1; // rax
  UFG::UIMapBlipManager *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::UIMapInteriorManager *v4; // rax
  UFG::allocator::free_link *v5; // rax
  UFG::UITiledMapGPS *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::UIMapLinesWidget *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::UIHKMissionProgressWidget *v10; // rbx
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rbx
  UFG::allocator::free_link *v13; // rax
  UFG::allocator::free_link *v14; // rbx
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // rbx
  UFG::UIHKWitnessManager *v17; // rax
  UFG::allocator::free_link *v18; // rax
  UFG::UIHKObjectiveDistanceWidget *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::UIHKMissionHealthWidget *v21; // rbx
  UFG::allocator::free_link *v22; // rax
  UFG::UIHKUpgradePopupWidget *v23; // rax
  UFG::UIHKTurnHintWidget *v24; // rax
  UFG::allocator::free_link *v25; // rax
  UFG::UIHKPhoneTraceSignalBarWidget *v26; // rbx
  UFG::allocator::free_link *v27; // rax
  UFG::allocator::free_link *v28; // rax
  UFG::UIHKRacePercentageWidget *v29; // rax
  UFG::allocator::free_link *v30; // rax
  UFG::allocator::free_link *v31; // rax
  UFG::allocator::free_link *v32; // rax
  UFG::UITiledMapRaceSplines *v33; // rax
  UFG::allocator::free_link *v34; // rax
  UFG::UIHKShortcutButtonWidget *v35; // rbx
  UFG::allocator::free_link *v36; // rax
  UFG::UIHKHintText *v37; // rax
  UFG::allocator::free_link *v38; // rax
  UFG::UIHKGameplayHelpWidget *v39; // rax
  UFG::allocator::free_link *v40; // rax
  UFG::UIHK_XPFlasherWidget *v41; // rax
  UFG::allocator::free_link *v42; // rax
  UFG::UIHKSecondaryTutorialWidget *v43; // rbx
  UFG::qList<UFG::UIScreenInvoke,UFG::UIScreenInvoke,1,0> *v44; // [rsp+58h] [rbp+18h]

  v0 = (UFG::UIScreenInvokeQueue *)UFG::qMemoryPool::Allocate(
                                     &gScaleformMemoryPool,
                                     0x20ui64,
                                     "UIHKScreenHud",
                                     0i64,
                                     1u);
  if ( v0 )
  {
    v0->vfptr = (UFG::UIScreenInvokeQueueVtbl *)&UFG::UIScreenInvokeQueue::`vftable';
    v0->mNumCommandsPerFrame = -1;
    v44 = &v0->mCommandQueue;
    v44->mNode.mPrev = &v44->mNode;
    v44->mNode.mNext = &v44->mNode;
  }
  else
  {
    v0 = 0i64;
  }
  UFG::UIHKScreenHud::mScreenInvokeQueue = v0;
  v1 = UFG::qMalloc(0x78ui64, "UIHKScreenHud", 0i64);
  if ( v1 )
    UFG::UIMapBlipManager::UIMapBlipManager((UFG::UIMapBlipManager *)v1);
  else
    v2 = 0i64;
  UFG::UIHKScreenHud::mIconManager = v2;
  v3 = UFG::qMalloc(0x6C0ui64, "UIHKScreenHud", 0i64);
  if ( v3 )
    UFG::UIMapInteriorManager::UIMapInteriorManager((UFG::UIMapInteriorManager *)v3);
  else
    v4 = 0i64;
  UFG::UIHKScreenHud::mInteriorManager = v4;
  v5 = UFG::qMalloc(0x4C0ui64, "UIHKScreenHud", 0i64);
  if ( v5 )
    UFG::UITiledMapGPS::UITiledMapGPS((UFG::UITiledMapGPS *)v5);
  else
    v6 = 0i64;
  UFG::UIHKScreenHud::GPS = v6;
  v7 = UFG::qMalloc(0x30ui64, "UIHKScreenHud", 0i64);
  if ( v7 )
    UFG::UIMapLinesWidget::UIMapLinesWidget((UFG::UIMapLinesWidget *)v7);
  else
    v8 = 0i64;
  UFG::UIHKScreenHud::MapLines = v8;
  v9 = UFG::qMalloc(0xC8ui64, "UIHKScreenHud", 0i64);
  v10 = (UFG::UIHKMissionProgressWidget *)v9;
  if ( v9 )
  {
    LOWORD(v9->mNext) = 0;
    `eh vector constructor iterator'(
      &v9[1],
      0x30ui64,
      4,
      (void (__fastcall *)(void *))UFG::UIHKMissionProgressSlotData::UIHKMissionProgressSlotData);
  }
  else
  {
    v10 = 0i64;
  }
  UFG::UIHKScreenHud::MissionProgress = v10;
  v11 = UFG::qMalloc(0x48ui64, "UIHKScreenHud", 0i64);
  v12 = v11;
  if ( v11 )
  {
    LODWORD(v11->mNext) = 1;
    WORD2(v11->mNext) = 256;
    UFG::qString::qString((UFG::qString *)&v11[1]);
    LODWORD(v12[6].mNext) = qSymbol_Food_20;
    *(UFG::allocator::free_link **)((char *)&v12[6].mNext + 4) = 0i64;
    HIDWORD(v12[7].mNext) = 0;
    LOWORD(v12[8].mNext) = 0;
    HIDWORD(v12[8].mNext) = 0;
  }
  else
  {
    v12 = 0i64;
  }
  UFG::UIHKScreenHud::InfoPopup = (UFG::UIHKInfoPopupWidget *)v12;
  v13 = UFG::qMalloc(0x58ui64, "UIHKScreenHud", 0i64);
  v14 = v13;
  if ( v13 )
  {
    v13->mNext = 0i64;
    v13[1].mNext = 0i64;
    UFG::qString::qString((UFG::qString *)&v13[2]);
    LODWORD(v14[7].mNext) = 0;
    WORD2(v14[7].mNext) = 1;
    LODWORD(v14[8].mNext) = 0;
    WORD2(v14[8].mNext) = 0;
    v14[9].mNext = 0i64;
    LOBYTE(v14[10].mNext) = 0;
  }
  else
  {
    v14 = 0i64;
  }
  UFG::UIHKScreenHud::CombatMeter = (UFG::UIHKCombatMeterWidget *)v14;
  v15 = UFG::qMalloc(0x60ui64, "UIHKScreenHud", 0i64);
  v16 = v15;
  if ( v15 )
  {
    LODWORD(v15->mNext) = 0;
    WORD2(v15->mNext) = 0;
    UFG::qString::qString((UFG::qString *)&v15[1]);
    UFG::qString::qString((UFG::qString *)&v16[6]);
    LOWORD(v16[11].mNext) = 0;
  }
  else
  {
    v16 = 0i64;
  }
  UFG::UIHKScreenHud::ActionButton = (UFG::UIHKActionButtonWidget *)v16;
  v17 = (UFG::UIHKWitnessManager *)UFG::qMalloc(0x18ui64, "UIHKScreenHud", 0i64);
  if ( v17 )
  {
    v17->mWitnessList.mNode.mPrev = &v17->mWitnessList.mNode;
    v17->mWitnessList.mNode.mNext = &v17->mWitnessList.mNode;
    v17->mNextId = 0;
  }
  else
  {
    v17 = 0i64;
  }
  UFG::UIHKScreenHud::WitnessManager = v17;
  v18 = UFG::qMalloc(0xA8ui64, "UIHKScreenHud", 0i64);
  if ( v18 )
    UFG::UIHKObjectiveDistanceWidget::UIHKObjectiveDistanceWidget((UFG::UIHKObjectiveDistanceWidget *)v18);
  else
    v19 = 0i64;
  UFG::UIHKScreenHud::ObjectiveDistance = v19;
  v20 = UFG::qMalloc(0x30ui64, "UIHKScreenHud", 0i64);
  v21 = (UFG::UIHKMissionHealthWidget *)v20;
  if ( v20 )
  {
    LODWORD(v20->mNext) = 0;
    HIDWORD(v20->mNext) = 1120403456;
    UFG::qString::qString((UFG::qString *)&v20[1]);
  }
  else
  {
    v21 = 0i64;
  }
  UFG::UIHKScreenHud::MissionHealth = v21;
  v22 = UFG::qMalloc(0x88ui64, "UIHKScreenHud", 0i64);
  if ( v22 )
    UFG::UIHKUpgradePopupWidget::UIHKUpgradePopupWidget((UFG::UIHKUpgradePopupWidget *)v22);
  else
    v23 = 0i64;
  UFG::UIHKScreenHud::UpgradePopup = v23;
  v24 = (UFG::UIHKTurnHintWidget *)UFG::qMalloc(8ui64, "UIHKScreenHud", 0i64);
  if ( v24 )
  {
    *(_DWORD *)&v24->mVisible = 0;
    v24->mIcon.mUID = -1;
  }
  else
  {
    v24 = 0i64;
  }
  UFG::UIHKScreenHud::TurnHint = v24;
  v25 = UFG::qMalloc(0x38ui64, "UIHKScreenHud", 0i64);
  v26 = (UFG::UIHKPhoneTraceSignalBarWidget *)v25;
  if ( v25 )
  {
    WORD2(v25->mNext) = 0;
    BYTE6(v25->mNext) = 0;
    v25[1].mNext = 0i64;
    UFG::qString::qString((UFG::qString *)&v25[2], "Data\\UI\\Phone_Trace_Strength_TP.perm.bin");
  }
  else
  {
    v26 = 0i64;
  }
  UFG::UIHKScreenHud::TraceSignalBar = v26;
  v27 = UFG::qMalloc(0x10ui64, "UIHKScreenHud", 0i64);
  if ( v27 )
  {
    LOWORD(v27->mNext) = 0;
    BYTE2(v27->mNext) = 0;
    *(UFG::allocator::free_link **)((char *)&v27->mNext + 4) = 0i64;
    HIDWORD(v27[1].mNext) = 0;
  }
  else
  {
    v27 = 0i64;
  }
  UFG::UIHKScreenHud::RaceTimer = (UFG::UIHKRaceTimerWidget *)v27;
  v28 = UFG::qMalloc(0xCui64, "UIHKScreenHud", 0i64);
  if ( v28 )
  {
    LOWORD(v28->mNext) = 0;
    *(UFG::allocator::free_link **)((char *)&v28->mNext + 4) = 0i64;
  }
  else
  {
    v28 = 0i64;
  }
  UFG::UIHKScreenHud::RacePosition = (UFG::UIHKRacePositionWidget *)v28;
  v29 = (UFG::UIHKRacePercentageWidget *)UFG::qMalloc(8ui64, "UIHKScreenHud", 0i64);
  if ( v29 )
  {
    *(_WORD *)&v29->mVisible = 256;
    v29->mPercentageDone = 0;
  }
  else
  {
    v29 = 0i64;
  }
  UFG::UIHKScreenHud::RacePercentage = v29;
  v30 = UFG::qMalloc(0x48ui64, "UIHKScreenHud", 0i64);
  if ( v30 )
  {
    v30->mNext = (UFG::allocator::free_link *)&UFG::UIHKMissionRewardsWidget::`vftable';
    v30[1].mNext = (UFG::allocator::free_link *)&UFG::UIHKMissionRewardsHeaderWidget::`vftable';
    *(UFG::allocator::free_link **)((char *)&v30[2].mNext + 4) = 0i64;
    v30[4].mNext = (UFG::allocator::free_link *)&UFG::UIHKMissionRewardsFlasherWidget::`vftable';
    v30[5].mNext = 0i64;
    v30[6].mNext = 0i64;
    v30[7].mNext = 0i64;
    LODWORD(v30[8].mNext) = 0;
    WORD2(v30[8].mNext) = 0;
    *(float *)&v30[2].mNext = UFG::UIHKMissionRewardsWidget::gHeaderDuration;
    *(float *)&v30[5].mNext = UFG::UIHKMissionRewardsWidget::gRewardsDuration;
  }
  else
  {
    v30 = 0i64;
  }
  UFG::UIHKScreenHud::MissionRewards = (UFG::UIHKMissionRewardsWidget *)v30;
  v31 = UFG::qMalloc(0xCui64, "UIHKScreenHud", 0i64);
  if ( v31 )
  {
    LOWORD(v31->mNext) = 256;
    BYTE2(v31->mNext) = 1;
    *(UFG::allocator::free_link **)((char *)&v31->mNext + 4) = 0i64;
  }
  else
  {
    v31 = 0i64;
  }
  UFG::UIHKScreenHud::RegionIndicator = (UFG::UIHKRegionIndicatorWidget *)v31;
  v32 = UFG::qMalloc(0x50ui64, "UIHKScreenHud", 0i64);
  if ( v32 )
    UFG::UITiledMapRaceSplines::UITiledMapRaceSplines((UFG::UITiledMapRaceSplines *)v32);
  else
    v33 = 0i64;
  UFG::UIHKScreenHud::RacePath = v33;
  v34 = UFG::qMalloc(0x40ui64, "UIHKScreenHud", 0i64);
  v35 = (UFG::UIHKShortcutButtonWidget *)v34;
  if ( v34 )
  {
    v34->mNext = 0i64;
    v34[1].mNext = 0i64;
    LODWORD(v34[2].mNext) = 0;
    UFG::qString::qString((UFG::qString *)&v34[3]);
  }
  else
  {
    v35 = 0i64;
  }
  UFG::UIHKScreenHud::ShortcutButton = v35;
  v36 = UFG::qMalloc(0x88ui64, "UIHKScreenHud", 0i64);
  if ( v36 )
    UFG::UIHKHintText::UIHKHintText((UFG::UIHKHintText *)v36);
  else
    v37 = 0i64;
  UFG::UIHKScreenHud::HintText = v37;
  v38 = UFG::qMalloc(0x138ui64, "UIHKScreenHud", 0i64);
  if ( v38 )
    UFG::UIHKGameplayHelpWidget::UIHKGameplayHelpWidget((UFG::UIHKGameplayHelpWidget *)v38);
  else
    v39 = 0i64;
  UFG::UIHKScreenHud::GameplayHelp = v39;
  v40 = UFG::qMalloc(0xC8ui64, "UIHKScreenHud", 0i64);
  if ( v40 )
    UFG::UIHK_XPFlasherWidget::UIHK_XPFlasherWidget((UFG::UIHK_XPFlasherWidget *)v40);
  else
    v41 = 0i64;
  UFG::UIHKScreenHud::XPFlasher = v41;
  v42 = UFG::qMalloc(0x30ui64, "UIHKScreenHud", 0i64);
  v43 = (UFG::UIHKSecondaryTutorialWidget *)v42;
  if ( v42 )
  {
    UFG::qString::qString((UFG::qString *)&v42[1]);
    UFG::UIHKScreenHud::SecondaryTutorial = v43;
  }
  else
  {
    UFG::UIHKScreenHud::SecondaryTutorial = 0i64;
  }
}

// File Line: 158
// RVA: 0x5C59A0
void __fastcall UFG::UIHKScreenHud::UIHKScreenHud(UFG::UIHKScreenHud *this)
{
  UFG::UIHKScreenHud *v1; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  UFG::GameStatTracker *v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::UIHK_PDAWidget *v5; // rax
  signed __int64 v6; // [rsp+58h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable';
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = 0;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenHud::`vftable';
  UFG::UITiledMapWidget::UITiledMapWidget(&this->Minimap);
  v1->HealthMeter.mHealthPercent = -1.0;
  v1->HealthMeter.mHealthPercentOfMaxPossible = -1.0;
  *(_WORD *)&v1->HealthMeter.mChanged = 1;
  v1->HealthMeter.mIsFirstUpdate = 1;
  UFG::UIHKWeaponAmmoWidget::UIHKWeaponAmmoWidget(&v1->WeaponAmmo);
  v6 = (signed __int64)&v1->RadioStationWidget;
  *(_DWORD *)v6 = 0;
  *(_DWORD *)(v6 + 4) = 257;
  *(_QWORD *)(v6 + 8) = 0i64;
  *(_DWORD *)(v6 + 16) = 0;
  *(_QWORD *)(v6 + 32) = 0i64;
  *(_QWORD *)(v6 + 24) = 0i64;
  UFG::qString::qString(&v1->RadioStationWidget.mLoadedTexturePack);
  UFG::UIHKRadioStationWidget::ReadStationList(&v1->RadioStationWidget);
  *(_WORD *)&v1->ActionHijack.mChanged = 0;
  v1->ActionHijack.mDistance = 0.0;
  v1->ActionHijack.mCanHijack = 0;
  *(_DWORD *)&v1->MoneyPopup.mIsVisible = 0;
  *(_WORD *)&v1->MoneyPopup.mTryToHide = 0;
  *(_QWORD *)&v1->MoneyPopup.mMoney = 0i64;
  v3 = UFG::GameStatTracker::Instance();
  v1->MoneyPopup.mMoney = UFG::GameStatTracker::GetStat(v3, Money);
  UFG::qString::qString(&v1->Buffs.mTexturePackFilename);
  `eh vector constructor iterator'(
    v1->Buffs.mIconLoaded,
    0x28ui64,
    7,
    (void (__fastcall *)(void *))UFG::qString::qString);
  *(_WORD *)&v1->Buffs.mPerkActivate = 0;
  v1->Buffs.mPerkTimer = 0.0;
  v1->SocialActionManager.mScoredTargets.size = 0;
  v1->SocialActionManager.mTargets.size = 0;
  v1->SocialActionManager.mWidgetIndexToUpdate = -1;
  *(_WORD *)&v1->SocialActionManager.mIconsReset = 256;
  UFG::UIHKSocialActionManager::mThis = &v1->SocialActionManager;
  ++v1->SocialActionManager.mTargets.size;
  ++v1->SocialActionManager.mTargets.size;
  ++v1->SocialActionManager.mTargets.size;
  ++v1->SocialActionManager.mTargets.size;
  ++v1->SocialActionManager.mTargets.size;
  v1->SocialActionManager.mTargets.p[0].m_pSimObject = 0i64;
  v1->SocialActionManager.mTargets.p[0].m_fScore = 0.0;
  v1->SocialActionManager.mTargets.p[1].m_pSimObject = 0i64;
  v1->SocialActionManager.mTargets.p[1].m_fScore = 0.0;
  v1->SocialActionManager.mTargets.p[2].m_pSimObject = 0i64;
  v1->SocialActionManager.mTargets.p[2].m_fScore = 0.0;
  v1->SocialActionManager.mTargets.p[3].m_pSimObject = 0i64;
  v1->SocialActionManager.mTargets.p[3].m_fScore = 0.0;
  v1->SocialActionManager.mTargets.p[4].m_pSimObject = 0i64;
  v1->SocialActionManager.mTargets.p[4].m_fScore = 0.0;
  UFG::UIHKSecondaryObjectivesWidget::UIHKSecondaryObjectivesWidget(&v1->SecondaryObjectives);
  v1->ObjectiveFlasher.mOldVisible = 0;
  *(_QWORD *)&v1->mState = 0i64;
  v1->mMinimapFadeTimeout = 0.0;
  v1->mMinimapVisibleChanged = 1;
  *(_DWORD *)&v1->Reticle.mChanged = 1;
  v1->Reticle.mVisible = 1;
  *(_QWORD *)&v1->Reticle.mScreenX = 0i64;
  *(_QWORD *)&v1->Reticle.mRadius = 0i64;
  *(_QWORD *)&v1->Reticle.mfSizeMax = 0i64;
  *(_WORD *)&v1->Reticle.mLockAnimationPlaying = 0;
  v1->Reticle.mHasAmmo = 1;
  *(_QWORD *)&v1->Reticle.mTargetFaction = 1i64;
  v1->DirectionalDamage.mDDTimers[0].bActive = 0;
  v1->DirectionalDamage.mDDTimers[0].fElapsedTime = 0.0;
  v1->DirectionalDamage.mDDTimers[1].bActive = 0;
  v1->DirectionalDamage.mDDTimers[1].fElapsedTime = 0.0;
  v1->DirectionalDamage.mDDTimers[2].bActive = 0;
  v1->DirectionalDamage.mDDTimers[2].fElapsedTime = 0.0;
  v1->DirectionalDamage.mDDTimers[3].bActive = 0;
  *(_QWORD *)&v1->DirectionalDamage.mDDTimers[3].fElapsedTime = 0i64;
  v1->HeatLevel.mHeatLevel = -1;
  *(_WORD *)&v1->HeatLevel.mCopCooldown = 256;
  v1->HeatLevel.mVisibleChanged = 0;
  v1->TimeOfDay.mLightingConditions = 0;
  v1->SniperWidget.vfptr = (UFG::UIHKSniperWidgetVtbl *)&UFG::UIHKSniperWidget::`vftable';
  v1->SniperWidget.mState = 0;
  v1->SniperWidget.mSniperMode = 0;
  v1->mStatInfoTimer = 0.0;
  *(_DWORD *)&v1->mStatSocialAwardActive = 0x1000000;
  UFG::UIHKScreenHud::mInstance = v1;
  v4 = UFG::qMalloc(0x300ui64, "PDAWidget", 0i64);
  if ( v4 )
    UFG::UIHK_PDAWidget::UIHK_PDAWidget((UFG::UIHK_PDAWidget *)v4, &UFG::UIHKScreenHud::PDACache);
  else
    v5 = 0i64;
  v1->PDA = v5;
  UFG::UIHKScreenHud::PDACache.state = 0;
  unk_142431A14 = 0;
  unk_142431A18 = 0;
}

// File Line: 179
// RVA: 0x5CB110
void __fastcall UFG::UIHKScreenHud::~UIHKScreenHud(UFG::UIHKScreenHud *this)
{
  UFG::UIHKScreenHud *v1; // rdi
  UFG::UIHK_PDAWidget *v2; // rcx
  UFG::UIHKMissionRewardsWidget *v3; // rbx
  UFG::UIScreenTextureManager *v4; // rax
  UFG::UIHKMissionRewardsHeaderWidget::eState v5; // eax
  UFG::UIHKCombatMeterWidget *v6; // rcx
  UFG::UIScreenTextureManager *v7; // rax
  UFG::UIScreenTextureManager *v8; // rax
  UFG::UIHKGameplayHelpWidget *v9; // rdx
  UFG::UIHKScreenGlobalOverlay *v10; // rcx
  int v11; // eax
  UFG::UIHKScreenGlobalOverlay *v12; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenHud::`vftable';
  UFG::UIHKScreenHud::PopulatePDACache(this);
  v2 = v1->PDA;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  v1->PDA = 0i64;
  UFG::UIMapInteriorManager::HandleScreenDestruct(UFG::UIHKScreenHud::mInteriorManager, &v1->Minimap);
  v3 = UFG::UIHKScreenHud::MissionRewards;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v4, UFG::UIHKMissionRewardsWidget::gTexturePackFilename);
  if ( v3->mState )
  {
    v5 = v3->Header.mState;
    if ( v5 == 7 || v5 == STATE_NONE )
      v3->mShouldSkipHeader = 1;
    v3->mState = 15;
  }
  ((void (__cdecl *)(UFG::UIHKMissionRewardsFlasherWidget *))v3->Rewards.vfptr->HandleScreenDestruct)(&v3->Rewards);
  v6 = UFG::UIHKScreenHud::CombatMeter;
  UFG::UIHKScreenHud::CombatMeter->mSleepPrevState = UFG::UIHKScreenHud::CombatMeter->mState;
  v6->mState = 6;
  v7 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v7, "Hud");
  v8 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v8, UFG::kOnDemandTexturePackFilename);
  UFG::UIHKScreenHud::mOnDemandTexturesLoaded = 0;
  UFG::UIHKScreenHud::mInstance = 0i64;
  v9 = UFG::UIHKScreenHud::GameplayHelp;
  v10 = &gGlobalOverlaySentinel;
  if ( UFG::UIHKScreenHud::GameplayHelp->mShowingInFlash )
  {
    v11 = UFG::UIHKHelpBarWidget::mLocked;
    if ( UFG::UIHKHelpBarWidget::mLocked > 0 )
      v11 = UFG::UIHKHelpBarWidget::mLocked-- - 1;
    if ( v11 < 1 )
    {
      v12 = UFG::UIHKScreenGlobalOverlay::mThis;
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v12 = &gGlobalOverlaySentinel;
      v12->HelpBar.mChanged = 1;
    }
    v9->mShowingInFlash = 0;
  }
  v1->SniperWidget.vfptr = (UFG::UIHKSniperWidgetVtbl *)&UFG::UIHKSniperWidget::`vftable';
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    v10 = UFG::UIHKScreenGlobalOverlay::mThis;
  UFG::UIHKHelpBarWidget::Hide(&v10->HelpBar, UI_HASH_SNIPER);
  UFG::qString::~qString(&v1->SecondaryObjectives.mTriadObjective.Caption);
  UFG::qString::~qString(&v1->SecondaryObjectives.mCopObjective.Caption);
  UFG::UIHKSocialActionManager::mThis = 0i64;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    UFG::UIHKHelpBarWidget::Hide(&UFG::UIHKScreenGlobalOverlay::mThis->HelpBar, UI_HASH_HELPBAR_SOCIAL_20);
  v1->SocialActionManager.mTargets.size = 0;
  v1->SocialActionManager.mScoredTargets.size = 0;
  UFG::UIHKBuffWidget::~UIHKBuffWidget(&v1->Buffs);
  UFG::UIHKRadioStationWidget::~UIHKRadioStationWidget(&v1->RadioStationWidget);
  UFG::UIHKWeaponAmmoWidget::~UIHKWeaponAmmoWidget(&v1->WeaponAmmo);
  UFG::UITiledMapWidget::~UITiledMapWidget(&v1->Minimap);
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 205
// RVA: 0x632060
void __fastcall UFG::UIHKScreenHud::init(UFG::UIHKScreenHud *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenHud *v2; // rdi
  UFG::GameStatTracker *v3; // rax
  bool v4; // al
  UFG::UIScreenRenderable *v5; // rsi
  UFG::UIHKMissionProgressWidget *v6; // rax
  UFG::UIHKInfoPopupWidget *v7; // rcx
  UFG::UIHKActionButtonWidget *v8; // rcx
  UFG::UIHKObjectiveDistanceWidget *v9; // rax
  UFG::UIHKBuffData *v10; // rcx
  __int64 v11; // rdx
  UFG::UIHKMissionHealthWidget *v12; // rax
  signed __int64 v13; // rcx
  UFG::UIHKRegionIndicatorWidget *v14; // rcx
  bool v15; // r8
  UFG::UIHKCombatMeterWidget *v16; // rax
  UFG::UIHKGameplayHelpWidget *v17; // rcx
  UFG::UIHK_XPFlasherWidget *v18; // rax
  UFG::UIScreenTextureManager *v19; // rax
  UFG::Controller *v20; // rdx
  UFG::UIHKScreenGlobalOverlay *v21; // rax

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v3 = UFG::GameStatTracker::Instance();
  v4 = UFG::GameStatTracker::GetStat(v3, HudEnable);
  v5 = v2->mRenderable;
  v2->mHudEnable = v4;
  if ( v5 )
  {
    v2->mState = 1;
    UFG::UITiledMapWidget::Init(&v2->Minimap, (UFG::UIScreen *)&v2->vfptr);
    v2->PDA->vfptr->init(v2->PDA, (UFG::UIScreen *)&v2->vfptr);
    v2->Minimap.mVisible = UFG::UIHKTweakables::RenderMinimap;
    v5->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
    UFG::UIMapBlipManager::HandleScreenInit(UFG::UIHKScreenHud::mIconManager);
    UFG::UIMapBlipManager::PopulateAmbientBlips(UFG::UIHKScreenHud::mIconManager);
    _((AMD_HD3D *)UFG::UIHKScreenHud::mInteriorManager);
    v6 = UFG::UIHKScreenHud::MissionProgress;
    UFG::UIHKScreenHud::MissionProgress->mChanged = 1;
    v6->mData[0].Changed = 1;
    v6->mData[1].Changed = 1;
    v6->mData[2].Changed = 1;
    v6->mData[3].Changed = 1;
    v7 = UFG::UIHKScreenHud::InfoPopup;
    if ( (unsigned int)(UFG::UIHKScreenHud::InfoPopup->mState - 4) <= 1 )
      UFG::UIHKScreenHud::InfoPopup->mState = 0;
    if ( v7->mState )
      v7->mState = 1;
    UFG::UIHKReticleWidget::HandleScreenInit(&v2->Reticle, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIHKHealthMeterWidget::Flash_SetVisible(&v2->HealthMeter, (UFG::UIScreen *)&v2->vfptr, 0);
    v8 = UFG::UIHKScreenHud::ActionButton;
    UFG::UIHKScreenHud::ActionButton->mChanged = 1;
    UFG::UIHKActionButtonWidget::Update(v8, (UFG::UIScreen *)&v2->vfptr);
    v9 = UFG::UIHKScreenHud::ObjectiveDistance;
    UFG::UIHKScreenHud::ObjectiveDistance->mChanged = 1;
    v9->mColorChanged = 1;
    v9->mOldDistance = -1.0;
    UFG::UIMapLinesWidget::HandleScreenInit(UFG::UIHKScreenHud::MapLines);
    UFG::UIHKScreenHud::MapLines->mClipToPlayerPos = 1;
    UFG::UITiledMapGPS::HandleScreenInit(UFG::UIHKScreenHud::GPS, (UFG::UIScreen *)&v2->vfptr);
    UFG::UITiledMapGPS::UsePlayerSourcePosition(UFG::UIHKScreenHud::GPS);
    UFG::UIHKScreenHud::GPS->mOnlyShowInVehicles = UFG::UIHKTweakables::OnlyShowGPSInVehicles;
    if ( UFG::UIHKBuffWidget::mNumBuffs )
    {
      v10 = UFG::UIHKBuffWidget::mBuffData;
      v11 = UFG::UIHKBuffWidget::mNumBuffs;
      do
      {
        if ( (unsigned int)(v10->mState - 2) <= 1 )
          v10->mState = 4;
        ++v10;
        --v11;
      }
      while ( v11 );
    }
    UFG::UIHKSocialActionManager::Init(&v2->SocialActionManager, (UFG::UIScreen *)&v2->vfptr);
    v12 = UFG::UIHKScreenHud::MissionHealth;
    UFG::UIHKScreenHud::MissionHealth->mChanged = 1;
    v12->mVisibleChanged = 1;
    UFG::UIHKScreenHud::TurnHint->mChanged = UFG::UIHKScreenHud::TurnHint->mVisible;
    v13 = (signed __int64)&v2->SecondaryObjectives;
    UFG::UIHKScreenHud::TraceSignalBar->mVisible = 0;
    *(_WORD *)&UFG::UIHKScreenHud::RaceTimer->mTimeChanged = 257;
    UFG::UIHKScreenHud::RacePosition->mChanged = 1;
    UFG::UIHKScreenHud::RacePercentage->mChanged = 1;
    *(_WORD *)(v13 + 52) = 257;
    *(_WORD *)(v13 + 116) = 257;
    UFG::UIHKSecondaryObjectivesWidget::UpdateObjective(
      &v2->SecondaryObjectives,
      (UFG::UIScreen *)&v2->vfptr,
      0.0,
      &v2->SecondaryObjectives.mCopObjective,
      1);
    UFG::UIHKSecondaryObjectivesWidget::UpdateObjective(
      &v2->SecondaryObjectives,
      (UFG::UIScreen *)&v2->vfptr,
      0.0,
      &v2->SecondaryObjectives.mTriadObjective,
      0);
    UFG::UIHKMissionRewardsWidget::HandleScreenInit(UFG::UIHKScreenHud::MissionRewards, (UFG::UIScreen *)&v2->vfptr);
    v14 = UFG::UIHKScreenHud::RegionIndicator;
    v15 = UFG::UIHKScreenHud::RegionIndicator->mVisible;
    UFG::UIHKScreenHud::RegionIndicator->mChanged = 0;
    UFG::UIHKRegionIndicatorWidget::Flash_SetVisible(v14, (UFG::UIScreen *)&v2->vfptr, v15);
    if ( (unsigned int)(UFG::UIHKObjectiveFlasherWidget::mState - 3) > 1 )
      UFG::UIHKObjectiveFlasherWidget::mState = UFG::UIHKObjectiveFlasherWidget::mState != 0;
    else
      UFG::UIHKObjectiveFlasherWidget::mState = 0;
    v16 = UFG::UIHKScreenHud::CombatMeter;
    if ( UFG::UIHKScreenHud::CombatMeter->mSleepPrevState == 4 )
      UFG::UIHKScreenHud::CombatMeter->mPreserveBuffStartingDuration = 1;
    *(_QWORD *)&v16->mState = 0i64;
    UFG::UIHKScreenHud::HintText->vfptr->HandleScreenInit(UFG::UIHKScreenHud::HintText, (UFG::UIScreen *)v2);
    v17 = UFG::UIHKScreenHud::GameplayHelp;
    UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    UFG::UIHKGameplayHelpWidget::Update(v17, (UFG::UIScreen *)&v2->vfptr);
    v18 = UFG::UIHKScreenHud::XPFlasher;
    if ( UFG::UIHKScreenHud::XPFlasher->mState )
    {
      if ( UFG::UIHKScreenHud::XPFlasher->mState == 2 )
      {
        UFG::UIHKScreenHud::XPFlasher->mStateElapsed = 0.0;
        if ( v18->mData[0].Total > 0 )
          v18->mData[0].Changed = 1;
        if ( v18->mData[1].Total > 0 )
          v18->mData[1].Changed = 1;
        if ( v18->mData[2].Total > 0 )
          v18->mData[2].Changed = 1;
      }
    }
    else
    {
      UFG::UIHKScreenHud::XPFlasher->mState = 1;
    }
    if ( UFG::UIHKScreenHud::mOnDemandTextureLoadRefCounter > 0 )
    {
      v19 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueTexturePackLoad(
        v19,
        UFG::kOnDemandTexturePackFilename,
        HIGH_PRIORITY,
        UFG::UIHKScreenHud::HandleTutorialHudTexturePackLoaded,
        0i64);
    }
    v20 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( v20 && v20->m_ActiveMapSet == 8 && !UFG::UI::gUIInputLocked )
      UFG::UIHKScreenHud::EmergencyInputModeRecovery(v2);
    v21 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v21 = &gGlobalOverlaySentinel;
    v21->HelpBar.mChanged = 1;
  }
}

// File Line: 279
// RVA: 0x63D310
void __fastcall UFG::UIHKScreenHud::update(UFG::UIHKScreenHud *this, float elapsed)
{
  UFG::UIHKScreenHud *v2; // rdi
  float v3; // xmm6_4
  char v4; // al
  bool v5; // dl
  UFG::UIScreenRenderable *v6; // rax
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  UFG::UIHKRacePositionWidget *v11; // rbx
  UFG::UIHKRacePositionWidget *v12; // rcx
  UFG::UIHKShortcutButtonWidget *v13; // rdx
  UFG::UIHKShortcutButtonWidget::eState v14; // ecx
  int v15; // ecx
  float v16; // xmm0_4
  UFG::UIHKHelpBarWidget *v17; // rcx
  float v18; // xmm0_4
  float v19; // xmm0_4
  UFG::UIScreenRenderable *v20; // rcx

  v2 = this;
  v3 = elapsed;
  if ( UFG::UIHKScreenHud::mHandleSigninChange )
  {
    v4 = UFG::UIHKMessageOverlay::HandleSigninChange();
    v5 = UFG::UIHKScreenHud::mHandleSigninChange;
    if ( v4 )
      v5 = 0;
    UFG::UIHKScreenHud::mHandleSigninChange = v5;
  }
  v6 = v2->mRenderable;
  if ( v6 && v6->m_shouldRender )
  {
    switch ( v2->mState )
    {
      case 1:
        v9 = elapsed + v2->mMinimapFadeTimeout;
        v2->mMinimapFadeTimeout = v9;
        if ( !UFG::UIHKScreenHud::mInteriorManager->mActive
          || UFG::UIHKScreenHud::mInteriorManager->mTextureLoaded
          || v9 > 5.0 )
        {
          v2->mState = 2;
        }
        break;
      case 2:
        v7 = v2->mMinimapAlpha;
        if ( v7 >= 1.0 )
          v2->mState = 3;
        v8 = (float)(v3 * 1.5) + v7;
        v2->mMinimapAlpha = v8;
        if ( v8 > 1.0 )
          v2->mMinimapAlpha = 1.0;
        v2->Minimap.mAlpha = v2->mMinimapAlpha;
        break;
      case 4:
        return;
    }
    v10 = v2->mStatInfoTimer;
    if ( v10 > 0.0 )
    {
      v10 = v10 - v3;
      v2->mStatInfoTimer = v10;
      if ( v10 <= 0.0 )
        UFG::UIHKScreenHud::HideStatGameInfo(v2);
    }
    UFG::UIScreenInvokeQueue::Update(UFG::UIHKScreenHud::mScreenInvokeQueue, (UFG::UIScreen *)&v2->vfptr);
    UFG::UITiledMapWidget::Update(
      &v2->Minimap,
      (UFG::UIScreen *)&v2->vfptr,
      v3,
      UFG::UIHKScreenHud::mIconManager,
      UFG::UIHKScreenHud::mInteriorManager,
      0i64,
      0i64,
      UFG::UIHKScreenHud::GPS);
    UFG::UIHKScreenHud::Flash_Update(v2);
    UFG::UIHKSocialActionManager::Update(&v2->SocialActionManager, (UFG::UIScreen *)&v2->vfptr, v3);
    UFG::UIHKMissionProgressWidget::Update(UFG::UIHKScreenHud::MissionProgress, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIHKInfoPopupWidget::Update(UFG::UIHKScreenHud::InfoPopup, (UFG::UIScreen *)&v2->vfptr, v3);
    UFG::UIHKMoneyPopupWidget::Update(&v2->MoneyPopup, (UFG::UIScreen *)&v2->vfptr, v3);
    UFG::UIHKWeaponAmmoWidget::Update(&v2->WeaponAmmo, (UFG::UIScreen *)&v2->vfptr, v3);
    UFG::UIHKReticleWidget::Update(&v2->Reticle, (UFG::UIScreen *)&v2->vfptr, v10);
    UFG::UIHKHealthMeterWidget::Update(&v2->HealthMeter, (UFG::UIScreen *)&v2->vfptr, v3);
    UFG::UIHKDirectionalDamageWidget::Update(&v2->DirectionalDamage, (UFG::UIScreen *)&v2->vfptr, v3);
    UFG::UIHKCombatMeterWidget::Update(UFG::UIHKScreenHud::CombatMeter, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIHKHeatLevelWidget::Update(&v2->HeatLevel, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIHKActionButtonWidget::Update(UFG::UIHKScreenHud::ActionButton, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIHKRadioStationWidget::Update(&v2->RadioStationWidget, (UFG::UIScreen *)&v2->vfptr, v3);
    UFG::UIHKWitnessManager::Update(UFG::UIHKScreenHud::WitnessManager, v3);
    UFG::UIHKTimeOfDayWidget::Update(&v2->TimeOfDay, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIMapLinesWidget::Update(UFG::UIHKScreenHud::MapLines, v3, &v2->Minimap.m_mapGeo);
    UFG::UIHKSniperWidget::Update(&v2->SniperWidget, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIHKBuffWidget::Update(&v2->Buffs, (UFG::UIScreen *)&v2->vfptr, v3);
    UFG::UIHKMissionHealthWidget::Update(UFG::UIHKScreenHud::MissionHealth, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIHKUpgradePopupWidget::Update(UFG::UIHKScreenHud::UpgradePopup, (UFG::UIScreen *)&v2->vfptr, v3);
    UFG::UIHKTurnHintWidget::Update(UFG::UIHKScreenHud::TurnHint, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIHKPhoneTraceSignalBarWidget::Update(UFG::UIHKScreenHud::TraceSignalBar, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIHKRaceTimerWidget::Update(UFG::UIHKScreenHud::RaceTimer, (UFG::UIScreen *)&v2->vfptr);
    v11 = UFG::UIHKScreenHud::RacePosition;
    if ( UFG::UIHKScreenHud::RacePosition->mChanged )
    {
      v12 = UFG::UIHKScreenHud::RacePosition;
      UFG::UIHKScreenHud::RacePosition->mChanged = 0;
      UFG::UIHKRacePositionWidget::Flash_SetVisible(v12, (UFG::UIScreen *)&v2->vfptr);
      if ( v11->mVisible )
        UFG::UIHKRacePositionWidget::Flash_SetPlayerPosition(v11, (UFG::UIScreen *)&v2->vfptr);
    }
    UFG::UIHKRacePercentageWidget::Update(UFG::UIHKScreenHud::RacePercentage, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIHKSecondaryObjectivesWidget::UpdateObjective(
      &v2->SecondaryObjectives,
      (UFG::UIScreen *)&v2->vfptr,
      v3,
      &v2->SecondaryObjectives.mCopObjective,
      1);
    UFG::UIHKSecondaryObjectivesWidget::UpdateObjective(
      &v2->SecondaryObjectives,
      (UFG::UIScreen *)&v2->vfptr,
      v3,
      &v2->SecondaryObjectives.mTriadObjective,
      0);
    UFG::UIHKMissionRewardsWidget::Update(UFG::UIHKScreenHud::MissionRewards, (UFG::UIScreen *)&v2->vfptr, v3);
    UFG::UIHKRegionIndicatorWidget::Update(UFG::UIHKScreenHud::RegionIndicator, (UFG::UIScreen *)&v2->vfptr, v3);
    UFG::UIHKObjectiveFlasherWidget::Update(&v2->ObjectiveFlasher, (UFG::UIScreen *)&v2->vfptr);
    v13 = UFG::UIHKScreenHud::ShortcutButton;
    v14 = UFG::UIHKScreenHud::ShortcutButton->mState;
    if ( v14 && v2->mRenderable->m_movie.pObject )
    {
      v15 = v14 - 1;
      if ( v15 )
      {
        if ( v15 == 1 )
        {
          v16 = UFG::UIHKScreenHud::ShortcutButton->mTimeout - v3;
          UFG::UIHKScreenHud::ShortcutButton->mTimeout = v16;
          if ( v16 <= 0.0 )
            v13->mState = 0;
        }
      }
      else
      {
        UFG::UIHKScreenHud::ShortcutButton->mState = 2;
      }
    }
    ((void (__fastcall *)(UFG::UIHKHintText *, UFG::UIHKScreenHud *))UFG::UIHKScreenHud::HintText->vfptr->Update)(
      UFG::UIHKScreenHud::HintText,
      v2);
    UFG::UIHKGameplayHelpWidget::Update(UFG::UIHKScreenHud::GameplayHelp, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIHK_XPFlasherWidget::Update(UFG::UIHKScreenHud::XPFlasher, (UFG::UIScreen *)&v2->vfptr, v3);
    UFG::UIHKSecondaryTutorialWidget::Update(UFG::UIHKScreenHud::SecondaryTutorial, (UFG::UIScreen *)&v2->vfptr, v3);
    ((void (__fastcall *)(UFG::UIHK_PDAWidget *, UFG::UIHKScreenHud *))v2->PDA->vfptr->update)(v2->PDA, v2);
    UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, v3);
    if ( UFG::UIHKScreenGlobalOverlay::mThis
      && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-144i64 )
    {
      if ( UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay.mSubtitleQueue.mCurrent1
        || UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay.mSubtitleQueue.mCurrent2
        || (UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *)UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay.mSubtitleQueue.mQueue.mNode.mNext != &UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay.mSubtitleQueue.mQueue )
      {
        if ( UFG::UIHKScreenGlobalOverlay::mThis )
          v17 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
        else
          v17 = &gHelpBarSentinel;
        v19 = v17->mYOffset;
        v17->mYOffset = -70.0;
        v18 = v19 - -70.0;
      }
      else if ( UFG::UIHKScreenGlobalOverlay::mThis )
      {
        v18 = UFG::UIHKScreenGlobalOverlay::mThis->HelpBar.mYOffset;
        v17 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
        UFG::UIHKScreenGlobalOverlay::mThis->HelpBar.mYOffset = 0.0;
      }
      else
      {
        v17 = &gHelpBarSentinel;
        v18 = gHelpBarSentinel.mYOffset;
        gHelpBarSentinel.mYOffset = 0.0;
      }
      v17->mChanged |= COERCE_FLOAT(LODWORD(v18) & _xmm) > 0.001;
    }
    if ( v2->mUpdateStatGamePosition )
    {
      v20 = v2->mRenderable;
      if ( v20 )
      {
        if ( v20->m_movie.pObject )
        {
          v2->mUpdateStatGamePosition = 0;
          Scaleform::GFx::Movie::Invoke(v20->m_movie.pObject, "StatGame_MakeSafe", 0i64);
        }
      }
    }
  }
  else
  {
    UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
  }
}

// File Line: 425
// RVA: 0x61FD40
void __fastcall UFG::UIHKScreenHud::customPreRender(UFG::UIHKScreenHud *this, Render::View *view)
{
  UFG::UIHKScreenHud *v2; // rbx
  Render::View *v3; // rdi
  UFG::UIScreenRenderable *v4; // rax
  Scaleform::GFx::Movie *v5; // rcx

  v2 = this;
  v3 = view;
  if ( UFG::UIHKScreenHud::ObjectiveDistance )
    UFG::UIHKObjectiveDistanceWidget::Update(
      UFG::UIHKScreenHud::ObjectiveDistance,
      (UFG::UIScreen *)&this->vfptr,
      gUIUpdateDelta);
  if ( v2->mHudEnable )
  {
    if ( UFG::UIScreenManager::s_instance->m_renderUI )
    {
      if ( UFG::UIHKTweakables::RenderMinimap )
      {
        v4 = v2->mRenderable;
        if ( v4 )
        {
          if ( v4->m_shouldRender )
          {
            v5 = v4->m_movie.pObject;
            if ( v5 )
            {
              if ( ((unsigned __int8 (*)(void))v5->vfptr[10].__vecDelDtor)() )
                UFG::UITiledMapWidget::RenderMinimapBackdrop(
                  &v2->Minimap,
                  v3,
                  UFG::UIHKScreenHud::mInteriorManager,
                  0i64,
                  UFG::UIHKScreenHud::MapLines);
            }
          }
        }
      }
    }
  }
}

// File Line: 443
// RVA: 0x63A150
void __fastcall UFG::UIHKScreenHud::render(UFG::UIHKScreenHud *this)
{
  if ( this->mHudEnable )
  {
    if ( UFG::UIScreenManager::s_instance->m_renderUI )
      UFG::UIScreenRenderable::render(this->mRenderable);
  }
}

// File Line: 451
// RVA: 0x61FC90
void __fastcall UFG::UIHKScreenHud::customPostRender(UFG::UIHKScreenHud *this, Render::View *view)
{
  Render::View *v2; // rdi
  UFG::UIHKScreenHud *v3; // rbx
  UFG::UIScreenRenderable *v4; // rax
  Scaleform::GFx::Movie *v5; // rcx

  v2 = view;
  v3 = this;
  if ( this->mHudEnable )
  {
    if ( UFG::UIScreenManager::s_instance->m_renderUI )
    {
      if ( UFG::UIHKTweakables::RenderMinimap )
      {
        v4 = this->mRenderable;
        if ( v4 )
        {
          if ( v4->m_shouldRender )
          {
            v5 = v4->m_movie.pObject;
            if ( v5 )
            {
              if ( ((unsigned __int8 (*)(void))v5->vfptr[10].__vecDelDtor)() )
                UFG::UITiledMapWidget::Render(
                  &v3->Minimap,
                  v2,
                  UFG::UIHKScreenHud::mIconManager,
                  UFG::UIHKScreenHud::mInteriorManager,
                  UFG::UIHKScreenHud::GPS,
                  UFG::UIHKScreenHud::MapLines,
                  UFG::UIHKScreenHud::RacePath);
            }
          }
        }
      }
    }
  }
}

// File Line: 474
// RVA: 0x623EA0
char __fastcall UFG::UIHKScreenHud::handleMessage(UFG::UIHKScreenHud *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbp
  unsigned int v4; // ebx
  UFG::UIHKScreenHud *v5; // rdi
  const char *v7; // rdx
  char v8; // r14
  bool v9; // bp
  char v10; // al
  unsigned __int8 v11; // bp
  NISManager *v12; // rax
  UFG::UIHKRegionIndicatorWidget *v13; // rdx
  unsigned int v14; // ecx
  bool v15; // zf
  UFG::UIHKCombatMeterWidget *v16; // rax

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( msgId == UI_HASH_GAME_UNLOADING_30 )
  {
    UFG::UIHKScreenHud::Pop();
    return 0;
  }
  if ( msgId == UI_HASH_MONEY_POPUP_FINISHED_20 )
  {
    this->MoneyPopup.mIsVisible = 0;
    return 1;
  }
  if ( msgId == UI_HASH_DIALOG_BOX_APPEAR_3 )
  {
    this->mRenderable->m_shouldRender = 0;
    goto LABEL_15;
  }
  if ( msgId == UI_HASH_DIALOG_BOX_DISAPPEAR_3 )
  {
    if ( UFG::UIScreenDialogBox::m_iDialogBoxRefCount <= 0 )
      this->mRenderable->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
  }
  else
  {
    if ( msgId == UI_HASH_GAMESTATE_PAUSE_1 )
    {
      v7 = "OnPause";
    }
    else
    {
      if ( msgId != UI_HASH_GAMESTATE_UNPAUSE_1 )
        goto LABEL_15;
      v7 = "OnUnpause";
    }
    Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, v7, 0i64, 0i64, 0);
  }
LABEL_15:
  if ( UFG::UIHKShortcutButtonWidget::HandleMessage(
         UFG::UIHKScreenHud::ShortcutButton,
         (UFG::UIScreen *)&v5->vfptr,
         v4,
         v3) )
  {
    return 1;
  }
  if ( v4 != UI_HASH_BUTTON_START_PRESSED_30 && v4 != UI_HASH_BUTTON_SELECT_PRESSED_30 || v5->mState == 4 )
  {
    UFG::UIHKSniperWidget::HandleMessage(&v5->SniperWidget, (UFG::UIScreen *)&v5->vfptr, v4);
    if ( v5->RadioStationWidget.mState == 3 && v4 == UI_HASH_RADIO_OUTRO_COMPLETE_20 )
      v5->RadioStationWidget.mState = 0;
    UFG::UIHKSocialActionWidget::HandleMessage(
      &UFG::UIHKSocialActionManager::SocialAction,
      (UFG::UIScreen *)&v5->vfptr,
      v4,
      v3);
    UFG::UIHKMissionRewardsWidget::HandleMessage(
      UFG::UIHKScreenHud::MissionRewards,
      (UFG::UIScreen *)&v5->vfptr,
      v4,
      v3);
    v13 = UFG::UIHKScreenHud::RegionIndicator;
    if ( v4 == UI_HASH_REGION_CHANGE_20 )
    {
      v14 = (unsigned int)v3[1].vfptr;
      v15 = UFG::UIHKScreenHud::RegionIndicator->mZone == v14;
      UFG::UIHKScreenHud::RegionIndicator->mZone = v14;
      v13->mChanged |= !v15;
    }
    if ( v4 == UI_HASH_REGION_SHOW_20 )
      *(_WORD *)&v13->mChanged = 257;
    UFG::UIHKObjectiveFlasherWidget::HandleMessage(&v5->ObjectiveFlasher, (UFG::UIScreen *)&v5->vfptr, v4, v3);
    if ( v4 == UI_HASH_RACEHUD_LOADED_20 )
    {
      UFG::UIHKScreenHud::RacePosition->mChanged = 1;
      UFG::UIHKScreenHud::RacePercentage->mChanged = 1;
    }
    v16 = UFG::UIHKScreenHud::CombatMeter;
    if ( v4 == UI_HASH_COMBAT_METER_INTRO_20 )
    {
      UFG::UIHKScreenHud::CombatMeter->mChanged = 1;
      v16->mState = 3;
    }
    else if ( v4 == UI_HASH_COMBAT_METER_OUTRO_20 )
    {
      UFG::UIHKScreenHud::CombatMeter->mState = 0;
    }
    UFG::UIHKScreenHud::HintText->vfptr->HandleMessage(UFG::UIHKScreenHud::HintText, (UFG::UIScreen *)v5, v4, v3);
    if ( v4 == UI_HASH_GAME_UNLOADING_30 )
      UFG::UIHKGameplayHelpWidget::ClearAll(UFG::UIHKScreenHud::GameplayHelp);
    v5->PDA->vfptr->handleMessage(v5->PDA, (UFG::UIScreen *)&v5->vfptr, v4, v3);
    UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
  else
  {
    v8 = 1;
    v9 = UFG::UIScreenManagerBase::getTopScreen((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr) == 0i64;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis
      || (v10 = 0, !UFG::UIHKScreenGlobalOverlay::mThis->m_skookum_dialog_active) )
    {
      v10 = 1;
    }
    v11 = v10 & v9;
    v12 = NISManager::GetInstance();
    if ( v12 && v12->mState )
      v8 = 0;
    if ( (UFG::UIHK_NISOverlay::m_curtains.m_state == 0) & (unsigned __int8)v8 & (UFG::UIScreenManagerBase::getScreen(
                                                                                    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                                                                    "NISPause") == 0i64) & v11 )
    {
      if ( v4 == UI_HASH_BUTTON_START_PRESSED_30 )
      {
        UFG::UI::PauseGame("PauseMenu");
        v5->mState = 4;
        return 1;
      }
      if ( v4 == UI_HASH_BUTTON_SELECT_PRESSED_30 && UFG::gEnableWorldMapAndPDA && !UFG::UI::InGameIntroChapter() )
      {
        if ( UFG::UI::PauseGame("WorldMap") )
          UFG::UIHKScreenHud::Pop();
      }
      return 1;
    }
  }
  return 0;
}

// File Line: 581
// RVA: 0x620850
UFG::UIHKScreenHud *__fastcall UFG::UIHKScreenHud::getInstance()
{
  return UFG::UIHKScreenHud::mInstance;
}

// File Line: 603
// RVA: 0x5FECD0
void __fastcall UFG::UIHKScreenHud::QueueInvoke(UFG::UIScreenInvoke *cmd)
{
  UFG::UIScreenInvoke *v1; // rbx
  bool v2; // si
  UFG::UIScreen *v3; // rax
  char v4; // di
  UFG::UIScreenRenderable *v5; // rax
  char v6; // bp

  if ( cmd )
  {
    v1 = cmd;
    v2 = 0;
    v3 = UFG::UIScreenManagerBase::getOverlay(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "Hud");
    v4 = 0;
    if ( v3 && (v5 = v3->mRenderable) != 0i64 && (v2 = v5->m_shouldRender) != 0
      || (v6 = 1, (unsigned int)UFG::qStringCompare(v1->command.mData, "hideFace", -1)) )
    {
      v6 = 0;
    }
    if ( !v2 && !(unsigned int)UFG::qStringCompare(v1->command.mData, "Cops_PingMinimap", -1) )
      v4 = 1;
    if ( (unsigned __int8)v6 | (unsigned __int8)v4 )
      v1->vfptr->__vecDelDtor(v1, 1u);
    else
      UFG::UIScreenInvokeQueue::Add(UFG::UIHKScreenHud::mScreenInvokeQueue, v1);
  }
}

// File Line: 633
// RVA: 0x5F4290
void UFG::UIHKScreenHud::Pop(void)
{
  UFG::UIScreenRenderable *v0; // rcx
  UFG::UIScreenTextureManager *v1; // rax
  UFG::UIScreenTextureManager *v2; // rax

  if ( UFG::UIHKScreenHud::mInstance )
  {
    v0 = UFG::UIHKScreenHud::mInstance->mRenderable;
    UFG::UIHKScreenHud::mInstance->mState = 4;
    if ( v0 )
      v0->m_shouldRender = 0;
  }
  UFG::UIScreenManagerBase::queuePopOverlay((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr, "Hud");
  v1 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v1, "Hud");
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v2, UFG::kOnDemandTexturePackFilename);
  UFG::UIHKScreenHud::mOnDemandTexturesLoaded = 0;
}

// File Line: 655
// RVA: 0x5F1B40
void __fastcall UFG::UIHKScreenHud::LoadTutorialHudTexturePack(UFG::UIHKScreenHud *this)
{
  UFG::UIScreenTextureManager *v1; // rax

  v1 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueTexturePackLoad(
    v1,
    UFG::kOnDemandTexturePackFilename,
    HIGH_PRIORITY,
    UFG::UIHKScreenHud::HandleTutorialHudTexturePackLoaded,
    0i64);
  ++UFG::UIHKScreenHud::mOnDemandTextureLoadRefCounter;
}

// File Line: 662
// RVA: 0x6131D0
void __fastcall UFG::UIHKScreenHud::UnloadTutorialHudTexturePack(UFG::UIHKScreenHud *this)
{
  UFG::UIScreenTextureManager *v1; // rax

  if ( --UFG::UIHKScreenHud::mOnDemandTextureLoadRefCounter <= 0 )
  {
    v1 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v1, UFG::kOnDemandTexturePackFilename);
    UFG::UIHKScreenHud::mOnDemandTexturesLoaded = 0;
  }
}

// File Line: 677
// RVA: 0x5D6F50
void __fastcall UFG::UIHKScreenHud::EmergencyInputModeRecovery(UFG::UIHKScreenHud *this)
{
  UFG::SimObjectCharacter *v1; // rbx
  unsigned __int16 v2; // cx
  UFG::SimComponent *v3; // rdi
  UFG::SimComponent *v4; // rax
  unsigned __int16 v5; // cx
  UFG::SimComponent *v6; // rbx
  UFG::SimComponent *v7; // rax
  unsigned int v8; // eax
  unsigned int v9; // eax
  bool v10; // dl
  UFG::ePDAStateEnum v11; // ecx
  UFG::UIHK_PDAWidget *v12; // r8
  UFG::ePDAStateEnum v13; // er8
  UFG::UIHK_PDAWidget *v14; // r8
  char v15; // al
  int v16; // ecx

  v1 = LocalPlayer;
  if ( LocalPlayer )
  {
    v2 = LocalPlayer->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = LocalPlayer->m_Components.p[44].m_pComponent;
    }
    else
    {
      if ( (v2 & 0x8000u) == 0 )
      {
        if ( (v2 >> 13) & 1 )
        {
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                 UFG::CharacterOccupantComponent::_TypeUID);
        }
        else if ( (v2 >> 12) & 1 )
        {
          v4 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                 UFG::CharacterOccupantComponent::_TypeUID);
        }
        else
        {
          v4 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&LocalPlayer->vfptr,
                 UFG::CharacterOccupantComponent::_TypeUID);
        }
      }
      else
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(
               (UFG::SimObjectGame *)&LocalPlayer->vfptr,
               UFG::CharacterOccupantComponent::_TypeUID);
      }
      v3 = v4;
    }
    v5 = v1->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v1->m_Components.p[7].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = v1->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (v5 >> 12) & 1 )
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(
                 (UFG::SimObjectGame *)&v1->vfptr,
                 UFG::ActionTreeComponent::_TypeUID);
        else
          v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::ActionTreeComponent::_TypeUID);
        v6 = v7;
      }
    }
    else
    {
      v6 = v1->m_Components.p[7].m_pComponent;
    }
    v8 = _S12_11;
    if ( !(_S12_11 & 1) )
    {
      _S12_11 |= 1u;
      sActionHijackUID.mUID = UFG::qStringHashUpper32("ActionHijack", 0xFFFFFFFF);
      v8 = _S12_11;
    }
    if ( v8 & 2 )
    {
      v9 = sMostUsedIndex_ActionHijack;
    }
    else
    {
      _S12_11 = v8 | 2;
      v9 = GetMostUsedIndex(sActionHijackUID.mUID);
      sMostUsedIndex_ActionHijack = v9;
    }
    v10 = ActionController::IsPlaying((ActionController *)&v6[3], &sActionHijackUID, v9, 1)
       || v3 && (LODWORD(v3[1].m_SafePointerList.mNode.mNext) - 9) & 0xFFFFFFFB;
    v11 = UFG::UIHKScreenHud::PDACache.state;
    if ( UFG::UIHKScreenHud::mInstance && (v12 = UFG::UIHKScreenHud::mInstance->PDA) != 0i64 )
      v13 = v12->mState;
    else
      v13 = UFG::UIHKScreenHud::PDACache.state;
    if ( v13 == STATE_IDLE )
      goto LABEL_50;
    if ( UFG::UIHKScreenHud::mInstance )
    {
      v14 = UFG::UIHKScreenHud::mInstance->PDA;
      if ( v14 )
        v11 = v14->mState;
    }
    if ( v11 != 11 )
      v15 = 1;
    else
LABEL_50:
      v15 = 0;
    if ( v10 )
    {
      v16 = (v15 != 0) + 4;
    }
    else
    {
      v16 = 1;
      if ( v15 )
        v16 = 7;
    }
    UFG::SetInputMode((UFG::eHKControllerInputMode)v16, UFG::gActiveControllerNum);
  }
}

// File Line: 711
// RVA: 0x5E57D0
void __fastcall UFG::UIHKScreenHud::Flash_Update(UFG::UIHKScreenHud *this)
{
  UFG::UIHKScreenHud *v1; // rbx
  Scaleform::GFx::Movie *v2; // rdi
  double v3; // xmm6_8
  bool v4; // cl
  bool v5; // bl
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-48h]

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 0;
    if ( UFG::UIHKScreenHud::mIconManager )
      UFG::UIMapBlipManager::UpdatePlayerArrow(
        UFG::UIHKScreenHud::mIconManager,
        (signed int)UFG::UITiledMapWidget::gMinimapCenter.x,
        (signed int)UFG::UITiledMapWidget::gMinimapCenter.y,
        this->Minimap.m_mapGeo.playerRot,
        0);
    if ( (unsigned int)(v1->mState - 1) <= 1 )
    {
      v3 = (float)(v1->mMinimapAlpha * 100.0);
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 5;
      value.mValue.NValue = v3;
      Scaleform::GFx::Movie::SetVariable(v2, "mc_minimapBorder._alpha", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(v2, "mcOuterRing._alpha", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(v2, "mcHeatMeter._alpha", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(v2, "mc_MinimapPulse._alpha", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(v2, "mc_HealthBar._alpha", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(v2, "mc_CombatTarget._alpha", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(v2, "mc_ObjectiveFlasherTarget._alpha", &value, 1i64);
    }
    if ( v1->mMinimapVisibleChanged )
    {
      v1->mMinimapVisibleChanged = 0;
      v4 = UFG::UIHKTweakables::RenderMinimap;
      v1->HeatLevel.mVisibleChanged |= v1->HeatLevel.mVisible != UFG::UIHKTweakables::RenderMinimap;
      v1->HeatLevel.mVisible = v4;
      v5 = UFG::UIHKTweakables::RenderMinimap;
      if ( ((unsigned int)value.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          *(_QWORD *)&value.mValue.NValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = 2;
      value.mValue.BValue = v5;
      Scaleform::GFx::Movie::SetVariable(v2, "mc_minimapBorder._visible", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(v2, "mcOuterRing._visible", &value, 1i64);
    }
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 765
// RVA: 0x5FF0D0
void UFG::UIHKScreenHud::RaceClear(void)
{
  UFG::UIHKRaceTimerWidget *v0; // rcx
  bool v1; // zf
  UFG::UIHKRacePositionWidget *v2; // rcx
  UFG::UIHKRacePercentageWidget *v3; // rcx

  v0 = UFG::UIHKScreenHud::RaceTimer;
  v1 = UFG::UIHKScreenHud::RaceTimer->mVisible == 0;
  UFG::UIHKScreenHud::RaceTimer->mVisible = 0;
  v0->mVisibilityChanged |= !v1;
  v2 = UFG::UIHKScreenHud::RacePosition;
  v1 = UFG::UIHKScreenHud::RacePosition->mVisible == 0;
  UFG::UIHKScreenHud::RacePosition->mVisible = 0;
  v2->mChanged |= !v1;
  v3 = UFG::UIHKScreenHud::RacePercentage;
  v1 = UFG::UIHKScreenHud::RacePercentage->mVisible == 0;
  UFG::UIHKScreenHud::RacePercentage->mVisible = 0;
  v3->mChanged |= !v1;
}

// File Line: 773
// RVA: 0x607050
void __fastcall UFG::UIHKScreenHud::SetReticleState(UFG::UIHKReticleWidget::eState state)
{
  UFG::UIHKScreenHud *v1; // rax

  v1 = UFG::UIHKScreenHud::mInstance;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    if ( UFG::UIHKScreenHud::mInstance->Reticle.mState != state )
    {
      UFG::UIHKScreenHud::mInstance->Reticle.mState = state;
      *(_WORD *)&v1->Reticle.mChanged = 257;
    }
  }
}

// File Line: 782
// RVA: 0x606FA0
void __fastcall UFG::UIHKScreenHud::SetReticlePosition(float screen_x, float screen_y)
{
  UFG::UIHKScreenHud *v2; // rax
  bool v3; // cl

  v2 = UFG::UIHKScreenHud::mInstance;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    v3 = screen_x != UFG::UIHKScreenHud::mInstance->Reticle.mScreenX
      || screen_y != UFG::UIHKScreenHud::mInstance->Reticle.mScreenY;
    UFG::UIHKScreenHud::mInstance->Reticle.mChanged |= v3;
    v2->Reticle.mScreenX = screen_x;
    v2->Reticle.mScreenY = screen_y;
  }
}

// File Line: 800
// RVA: 0x606FE0
void __fastcall UFG::UIHKScreenHud::SetReticleScreenSpaceRadius(float radius)
{
  UFG::UIHKScreenHud *v1; // rax

  v1 = UFG::UIHKScreenHud::mInstance;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    if ( radius == UFG::UIHKScreenHud::mInstance->Reticle.mRadius )
    {
      UFG::UIHKScreenHud::mInstance->Reticle.mRadius = radius;
      v1->Reticle.mChanged = v1->Reticle.mChanged;
    }
    else
    {
      UFG::UIHKScreenHud::mInstance->Reticle.mRadius = radius;
      v1->Reticle.mChanged |= 1u;
    }
  }
}

// File Line: 809
// RVA: 0x607080
void __fastcall UFG::UIHKScreenHud::SetReticleTargetFaction(UFG::eFactionStandingEnum faction)
{
  UFG::UIHKScreenHud *v1; // rax

  v1 = UFG::UIHKScreenHud::mInstance;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    if ( UFG::UIHKScreenHud::mInstance->Reticle.mTargetFaction != faction )
    {
      UFG::UIHKScreenHud::mInstance->Reticle.mChanged = 1;
      v1->Reticle.mFactionChanged = 1;
      v1->Reticle.mTargetFaction = faction;
    }
  }
}

// File Line: 818
// RVA: 0x6070B0
void __fastcall UFG::UIHKScreenHud::SetReticleType(unsigned int eWeaponReticleEnum, bool bIsExplosive)
{
  UFG::UIHKScreenHud *v2; // r8

  v2 = UFG::UIHKScreenHud::mInstance;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    if ( eWeaponReticleEnum - 1 <= 1 && bIsExplosive )
      eWeaponReticleEnum = 4;
    if ( UFG::UIHKScreenHud::mInstance->Reticle.mType != eWeaponReticleEnum )
    {
      UFG::UIHKScreenHud::mInstance->Reticle.mChanged = 1;
      v2->Reticle.mTypeChanged = 1;
      v2->Reticle.mType = eWeaponReticleEnum;
    }
  }
}

// File Line: 827
// RVA: 0x606F70
void __fastcall UFG::UIHKScreenHud::SetReticleHighlightMode(UFG::eHighlightModeEnum highlightMode)
{
  UFG::UIHKScreenHud *v1; // rdx
  bool v2; // zf

  v1 = UFG::UIHKScreenHud::mInstance;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    v2 = UFG::UIHKScreenHud::mInstance->Reticle.mHighlightMode == highlightMode;
    UFG::UIHKScreenHud::mInstance->Reticle.mFactionChanged = 1;
    v1->Reticle.mHighlightMode = highlightMode;
    v1->Reticle.mChanged |= !v2;
  }
}

// File Line: 836
// RVA: 0x607020
void __fastcall UFG::UIHKScreenHud::SetReticleSize(float fCurrent, float fMin, float fMax)
{
  UFG::UIHKScreenHud *v3; // rax

  v3 = UFG::UIHKScreenHud::mInstance;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    UFG::UIHKScreenHud::mInstance->Reticle.mfSizeCurrent = fCurrent;
    v3->Reticle.mfSizeMin = fMin;
    v3->Reticle.mfSizeMax = fMax;
  }
}

// File Line: 845
// RVA: 0x5F3A60
void UFG::UIHKScreenHud::PingMinimap(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::UIScreenInvoke *v1; // rbx
  UFG::allocator::free_link *v2; // rax

  v0 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UIScreenInvoke", 0i64, 1u);
  v1 = (UFG::UIScreenInvoke *)v0;
  if ( v0 )
  {
    v2 = v0 + 1;
    v2->mNext = v2;
    v2[1].mNext = v2;
    v1->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable';
    UFG::qString::qString(&v1->command, &customWorldMapCaption);
  }
  else
  {
    v1 = 0i64;
  }
  if ( v1 )
  {
    UFG::qString::Set(&v1->command, "Cops_PingMinimap");
    UFG::UIHKScreenHud::QueueInvoke(v1);
  }
}

// File Line: 856
// RVA: 0x5D2FD0
void __fastcall UFG::UIHKScreenHud::AddWitness(UFG::qVector3 *pos, bool isCop)
{
  UFG::UIHKWitnessManager::AddWitness(UFG::UIHKScreenHud::WitnessManager, pos, isCop);
}

// File Line: 862
// RVA: 0x5EB530
void UFG::UIHKScreenHud::HandleMinimapInteriorTextureLoaded(void)
{
  UFG::UIMapInteriorManager::HandleTextureLoaded(UFG::UIHKScreenHud::mInteriorManager);
}

// File Line: 868
// RVA: 0x602AE0
void UFG::UIHKScreenHud::ResetWidgets(void)
{
  signed __int64 v0; // rdi
  UFG::UIHKInfoPopupWidget::eState v1; // ecx
  UFG::UIHKHintText *v2; // rcx
  bool v3; // zf
  UFG::UIHKHintText::eState v4; // eax
  UFG::UIHKActionButtonWidget *v5; // rcx
  UFG::UIHKMissionProgressWidget *v6; // rsi
  UFG::qString *v7; // rbx
  UFG::qString *v8; // rbx
  signed __int64 v9; // rdi
  UFG::UIHKObjectiveFlasherWidget::eState v10; // eax
  int v11; // eax
  UFG::UIHKRaceTimerWidget *v12; // rcx
  UFG::UIHKRacePositionWidget *v13; // rcx
  UFG::UIHKRacePercentageWidget *v14; // rcx
  UFG::UIHKScreenGlobalOverlay *v15; // rax
  UFG::UIHKTextOverlay *v16; // rbx
  UFG::UISubtitleMessage *v17; // rdx
  UFG::UIHKTextOverlay *v18; // rcx
  UFG::UISubtitleMessage *v19; // rdx
  UFG::UIHKTextOverlay *v20; // rcx

  UFG::UITiledMapGPS::Initialize(UFG::UIHKScreenHud::GPS);
  v0 = 4i64;
  v1 = UFG::UIHKScreenHud::InfoPopup->mState;
  if ( v1 && v1 != 5 )
    UFG::UIHKScreenHud::InfoPopup->mState = 4;
  v2 = UFG::UIHKScreenHud::HintText;
  v3 = UFG::UIHKScreenHud::HintText->m_isShowingOnlineDisconnect == 1;
  UFG::UIHKScreenHud::HintText->m_bShowMsg = 0;
  v2->m_bUseTimer = 0;
  v2->m_bRepeatMsg = 0;
  if ( v3 )
    v2->m_isShowingOnlineDisconnect = 0;
  v4 = v2->m_eState;
  if ( v4 == 3 )
  {
    v2->m_eState = 4;
  }
  else if ( !((v4 - 2) & 0xFFFFFFFB) )
  {
    v2->m_eState = 0;
  }
  v5 = UFG::UIHKScreenHud::ActionButton;
  v3 = UFG::UIHKScreenHud::ActionButton->mVisible == 0;
  UFG::UIHKScreenHud::ActionButton->mVisible = 0;
  v5->mChanged |= !v3;
  v6 = UFG::UIHKScreenHud::MissionProgress;
  v7 = &UFG::UIHKScreenHud::MissionProgress->mData[0].Caption;
  do
  {
    LOBYTE(v7[-1].mStringHash32) = 1;
    v7[-1].mStringHashUpper32 = 0;
    UFG::qString::Set(v7, &customWorldMapCaption);
    v7 = (UFG::qString *)((char *)v7 + 48);
    --v0;
  }
  while ( v0 );
  v6->mChanged = 1;
  v8 = &UFG::UIHKScreenHud::XPFlasher->mData[0].Caption;
  v9 = 3i64;
  do
  {
    v8[-1].mData = 0i64;
    UFG::qString::Set(v8, &customWorldMapCaption);
    LOBYTE(v8[1].mPrev) = 0;
    v8 = (UFG::qString *)((char *)v8 + 64);
    --v9;
  }
  while ( v9 );
  UFG::UIHKGameplayHelpWidget::ClearAll(UFG::UIHKScreenHud::GameplayHelp);
  UFG::UIHKBuffWidget::Clear();
  v10 = UFG::UIHKObjectiveFlasherWidget::mState;
  if ( UFG::UIHKObjectiveFlasherWidget::mState & 0xFFFFFFFB )
    v10 = 3;
  UFG::UIHKObjectiveFlasherWidget::mState = v10;
  UFG::UIHK_PDATextInboxWidget::ClearMessages();
  if ( unk_142431A14 && UFG::UIHK_PDAWidget::mInputLocked > 0 )
  {
    UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
    v11 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v11 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
    if ( v11 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    --UFG::UIHK_PDAWidget::mInputLocked;
  }
  v12 = UFG::UIHKScreenHud::RaceTimer;
  UFG::UIHKScreenHud::PDACache.state = 0;
  unk_142431A14 = 0;
  unk_142431A18 = 0;
  v3 = UFG::UIHKScreenHud::RaceTimer->mVisible == 0;
  UFG::UIHKScreenHud::RaceTimer->mVisible = 0;
  v12->mVisibilityChanged |= !v3;
  v13 = UFG::UIHKScreenHud::RacePosition;
  v3 = UFG::UIHKScreenHud::RacePosition->mVisible == 0;
  UFG::UIHKScreenHud::RacePosition->mVisible = 0;
  v13->mChanged |= !v3;
  v14 = UFG::UIHKScreenHud::RacePercentage;
  v3 = UFG::UIHKScreenHud::RacePercentage->mVisible == 0;
  UFG::UIHKScreenHud::RacePercentage->mVisible = 0;
  v14->mChanged |= !v3;
  v15 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v16 = &UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay;
    if ( UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-144i64 )
    {
      UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay.mSubtitleQueue.mQueue);
      v17 = v16->mSubtitleQueue.mCurrent1;
      if ( v17 )
      {
        v17->state = 3;
        v18 = v16->mSubtitleQueue.mParent;
        if ( v18 )
          UFG::UIHKTextOverlay::OnHideNow(v18, v17, 1);
      }
      v19 = v16->mSubtitleQueue.mCurrent2;
      if ( v19 )
      {
        v19->state = 3;
        v20 = v16->mSubtitleQueue.mParent;
        if ( v20 )
          UFG::UIHKTextOverlay::OnHideNow(v20, v19, 2);
      }
      if ( v16->mSubtitlesVisible != 1 )
      {
        *(_WORD *)&v16->mChanged = 257;
        v16->mSubtitleQueue.mPauseQueue = 0;
      }
      v15 = UFG::UIHKScreenGlobalOverlay::mThis;
    }
    if ( v15 )
    {
      if ( v15 != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
      {
        UFG::UIHK_NISOverlay::mLetterBoxActive = 0;
        if ( UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_HIDDEN )
          UFG::UIHK_NISOverlay::SetActive(&v15->NISOverlay, 0);
      }
    }
  }
  UFG::UIHKScreenHud::ResetWidgetVisibility();
}

// File Line: 898
// RVA: 0x5D57F0
void UFG::UIHKScreenHud::ClearPDACache(void)
{
  int v0; // eax

  if ( unk_142431A14 && UFG::UIHK_PDAWidget::mInputLocked )
  {
    UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
    v0 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v0 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
    if ( v0 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    --UFG::UIHK_PDAWidget::mInputLocked;
  }
  UFG::UIHKScreenHud::PDACache.state = 0;
  unk_142431A14 = 0;
  unk_142431A18 = 0;
}

// File Line: 908
// RVA: 0x60C670
void __fastcall UFG::UIHKScreenHud::SetVisible(bool value)
{
  UFG::UIScreen *v1; // rax

  if ( UFG::UIHKScreenHud::mShouldRender != value )
  {
    UFG::UIHKScreenHud::mShouldRender = value;
    v1 = UFG::UIScreenManagerBase::getOverlay(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "Hud");
    if ( v1 )
      v1->mRenderable->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
  }
}

// File Line: 933
// RVA: 0x613120
void __fastcall UFG::UIHKScreenHud::UnHideAmmoOverlay(UFG::UIHKScreenHud *this)
{
  UFG::allocator::free_link *v1; // rax
  __int64 v2; // rax
  __int64 v3; // rbx

  v1 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x70ui64, "UIScreenInvokeStringArgs", 0i64, 1u);
  if ( v1 )
  {
    UFG::UIScreenInvokeStringArgs::UIScreenInvokeStringArgs((UFG::UIScreenInvokeStringArgs *)v1);
    v3 = v2;
  }
  else
  {
    v3 = 0i64;
  }
  UFG::qString::Set((UFG::qString *)(v3 + 24), "showInventoryIcon");
  UFG::qString::Set((UFG::qString *)(v3 + 64), "camera");
  *(_DWORD *)(v3 + 104) = 1;
  UFG::UIHKScreenHud::QueueInvoke((UFG::UIScreenInvoke *)v3);
}

// File Line: 969
// RVA: 0x5F9F10
void __fastcall UFG::UIHKScreenHud::PopulatePDACache(UFG::UIHKScreenHud *this)
{
  UFG::UIHKScreenHud *v1; // rbx
  UFG::UIHK_PDAWidget *v2; // rdx

  v1 = this;
  if ( UFG::UIHKScreenHud::mInstance )
  {
    v2 = UFG::UIHKScreenHud::mInstance->PDA;
    if ( v2 )
      UFG::UIHKScreenHud::PDACache.state = v2->mState;
  }
  UFG::qString::Set(&stru_142431A20, this->PDA->IncomingCall.mCallerName.mData);
  unk_142431A48 = v1->PDA->mOutgoingCall;
  unk_142431A49 = v1->PDA->IncomingCall.mState == 4;
  unk_142431A4A = v1->PDA->mVoiceMail;
  unk_142431A18 = v1->PDA->RootMenu.mSelectedIndex;
}

// File Line: 980
// RVA: 0x5E83B0
float __fastcall UFG::UIHKScreenHud::GetMapZoomFactor(UFG::UIHKScreenHud *this)
{
  return this->Minimap.m_mapGeo.scale;
}

// File Line: 986
// RVA: 0x602A00
void UFG::UIHKScreenHud::ResetWidgetVisibility(void)
{
  UFG::qSymbol widget; // [rsp+40h] [rbp+10h]
  UFG::qSymbol *v1; // [rsp+48h] [rbp+18h]

  v1 = &widget;
  widget.mUID = UIHudWidgetID_HUD_MINIMAP_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
  v1 = &widget;
  widget.mUID = UIHudWidgetID_HUD_PDA_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
  v1 = &widget;
  widget.mUID = UIHudWidgetID_HUD_HEALTH_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
  v1 = &widget;
  widget.mUID = UIHudWidgetID_HUD_COMBAT_METER_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
  v1 = &widget;
  widget.mUID = UIHudWidgetID_HUD_WEAPON_AMMO_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
  v1 = &widget;
  widget.mUID = UIHudWidgetID_HUD_REGION_INDICATOR_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
  v1 = &widget;
  widget.mUID = UIHudWidgetID_HUD_GAMEPLAY_HELP_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
}

// File Line: 998
// RVA: 0x60C720
void __fastcall UFG::UIHKScreenHud::SetWidgetVisible(__int64 widget, bool visible)
{
  int v2; // eax
  UFG::UIHKScreenHud *v3; // r8
  bool v4; // zf
  UFG::UIHKRegionIndicatorWidget *v5; // rcx
  UFG::UIHKGameplayHelpWidget *v6; // rcx

  v2 = *(_DWORD *)widget;
  v3 = UFG::UIHKScreenHud::mInstance;
  if ( *(_DWORD *)widget == UIHudWidgetID_HUD_MINIMAP_13.mUID )
  {
    UFG::UIHKTweakables::RenderMinimap = visible;
    if ( UFG::UIHKScreenHud::mInstance )
    {
      UFG::UIHKScreenHud::mInstance->mMinimapVisibleChanged = 1;
      v3->Minimap.mVisible = visible;
    }
  }
  else if ( v2 != UIHudWidgetID_HUD_PDA_13.mUID )
  {
    if ( v2 == UIHudWidgetID_HUD_HEALTH_13.mUID )
    {
      if ( UFG::UIHKScreenHud::mInstance )
        UFG::UIHKScreenHud::mInstance->HealthMeter.mChanged |= UFG::UIHKHealthMeterWidget::gVisible != visible;
      UFG::UIHKHealthMeterWidget::gVisible = visible;
    }
    else if ( v2 == UIHudWidgetID_HUD_COMBAT_METER_13.mUID )
    {
      UFG::UIHKScreenHud::CombatMeter->mChanged |= UFG::UIHKCombatMeterWidget::m_bScriptWantVisible != visible;
      UFG::UIHKCombatMeterWidget::m_bScriptWantVisible = visible;
    }
    else if ( v2 == UIHudWidgetID_HUD_WEAPON_AMMO_13.mUID )
    {
      if ( UFG::UIHKScreenHud::mInstance )
      {
        v4 = UFG::UIHKScreenHud::mInstance->WeaponAmmo.mVisible == visible;
        UFG::UIHKScreenHud::mInstance->WeaponAmmo.mVisible = visible;
        v3->WeaponAmmo.mVisibleChanged |= !v4;
      }
    }
    else if ( v2 == UIHudWidgetID_HUD_REGION_INDICATOR_13.mUID )
    {
      v5 = UFG::UIHKScreenHud::RegionIndicator;
      v4 = UFG::UIHKScreenHud::RegionIndicator->mVisible == visible;
      UFG::UIHKScreenHud::RegionIndicator->mVisible = visible;
      v5->mChanged |= !v4;
    }
    else if ( v2 == UIHudWidgetID_HUD_GAMEPLAY_HELP_13.mUID )
    {
      v6 = UFG::UIHKScreenHud::GameplayHelp;
      v4 = UFG::UIHKScreenHud::GameplayHelp->mScriptVisible == visible;
      UFG::UIHKScreenHud::GameplayHelp->mScriptVisible = visible;
      v6->mScriptVisibleChanged |= !v4;
    }
  }
}

// File Line: 1046
// RVA: 0x60C6C0
void __fastcall UFG::UIHKScreenHud::SetWidgetHighlight(UFG::UIHKScreenHud *this, __int64 widget, bool highlight)
{
  int v3; // eax

  v3 = *(_DWORD *)widget;
  if ( *(_DWORD *)widget == UIHudWidgetID_HUD_MINIMAP_13.mUID )
  {
    UFG::UIHKScreenHud::SetMinimapHighlight(this, highlight);
  }
  else if ( v3 == UIHudWidgetID_HUD_PDA_13.mUID )
  {
    if ( highlight )
      this->PDA->mShouldHighlight = 1;
  }
  else if ( v3 == UIHudWidgetID_HUD_HEALTH_13.mUID )
  {
    if ( highlight )
      *(_WORD *)&this->HealthMeter.mChanged = 257;
  }
  else if ( v3 == UIHudWidgetID_HUD_COMBAT_METER_13.mUID && highlight )
  {
    UFG::UIHKScreenHud::CombatMeter->mShouldHighlight = 1;
  }
}

// File Line: 1088
// RVA: 0x6062E0
void __fastcall UFG::UIHKScreenHud::SetMinimapHighlight(UFG::UIHKScreenHud *this, bool highlight)
{
  Scaleform::GFx::Movie *v2; // rbx
  char ptr; // [rsp+40h] [rbp-68h]
  __int64 v4; // [rsp+50h] [rbp-58h]
  unsigned int v5; // [rsp+58h] [rbp-50h]
  const char *v6; // [rsp+60h] [rbp-48h]
  char v7; // [rsp+70h] [rbp-38h]
  __int64 v8; // [rsp+80h] [rbp-28h]
  unsigned int v9; // [rsp+88h] [rbp-20h]
  const char *v10; // [rsp+90h] [rbp-18h]

  if ( highlight )
  {
    v2 = this->mRenderable->m_movie.pObject;
    if ( v2 )
    {
      `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (v5 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v4 + 16i64))(v4, &ptr, v6);
        v4 = 0i64;
      }
      v5 = 6;
      v6 = "mc_Minimap";
      if ( (v9 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v8 + 16i64))(v8, &v7, v10);
        v8 = 0i64;
      }
      v9 = 6;
      v10 = "mc_HealthBar_highlight";
      Scaleform::GFx::Movie::Invoke(v2, "UIHighlight_Init", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
      `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 1110
// RVA: 0x6081F0
void __fastcall UFG::UIHKScreenHud::SetSocialAwardMedal(UFG::UIHKScreenHud *this, int medal, const char *socialaward, const char *myname, const char *myscore)
{
  const char *v5; // r12
  const char *v6; // r15
  __int64 v7; // r14
  UFG::UIHKScreenHud *v8; // rbx
  UFG::UIScreenRenderable *v9; // rax
  Scaleform::GFx::Movie *v10; // rsi
  UFG::GameStatTracker *v11; // rax
  UFG::UIHK_PDAWidget *v12; // rcx
  UFG::ePDAStateEnum v13; // eax
  unsigned int v14; // eax
  UFG::UIGfxTranslator *v15; // rcx
  const char *v16; // rdi
  char *v17; // rdi
  __int64 v18; // rdi
  char ptr; // [rsp+30h] [rbp-D0h]
  __int64 v20; // [rsp+40h] [rbp-C0h]
  unsigned int v21; // [rsp+48h] [rbp-B8h]
  const char *v22; // [rsp+50h] [rbp-B0h]
  char v23; // [rsp+60h] [rbp-A0h]
  __int64 v24; // [rsp+70h] [rbp-90h]
  unsigned int v25; // [rsp+78h] [rbp-88h]
  const char *v26; // [rsp+80h] [rbp-80h]
  char v27; // [rsp+90h] [rbp-70h]
  __int64 v28; // [rsp+A0h] [rbp-60h]
  unsigned int v29; // [rsp+A8h] [rbp-58h]
  char *v30; // [rsp+B0h] [rbp-50h]
  char v31; // [rsp+C0h] [rbp-40h]
  __int64 v32; // [rsp+D0h] [rbp-30h]
  unsigned int v33; // [rsp+D8h] [rbp-28h]
  double v34; // [rsp+E0h] [rbp-20h]
  char v35; // [rsp+F0h] [rbp-10h]
  __int64 v36; // [rsp+100h] [rbp+0h]
  unsigned int v37; // [rsp+108h] [rbp+8h]
  __int64 v38; // [rsp+110h] [rbp+10h]
  char *v39; // [rsp+120h] [rbp+20h]
  const char *v40; // [rsp+128h] [rbp+28h]
  const char *v41; // [rsp+130h] [rbp+30h]
  const char *v42; // [rsp+138h] [rbp+38h]
  __int64 v43; // [rsp+140h] [rbp+40h]
  UFG::qString v44; // [rsp+148h] [rbp+48h]

  v43 = -2i64;
  v5 = myname;
  v6 = socialaward;
  v7 = medal;
  v8 = this;
  v9 = this->mRenderable;
  if ( v9 )
  {
    v10 = v9->m_movie.pObject;
    if ( v10 )
    {
      v11 = UFG::GameStatTracker::Instance();
      if ( !(unsigned __int8)UFG::GameStatTracker::GetStat(v11, OptionsDisableSocial) )
      {
        if ( !v8->PDA
          || (!UFG::UIHKScreenHud::mInstance || (v12 = UFG::UIHKScreenHud::mInstance->PDA) == 0i64 ? (v13 = UFG::UIHKScreenHud::PDACache.state) : (v13 = v12->mState),
              v13 == STATE_IDLE) )
        {
          v14 = UFG::qStringHashUpper32("LEADERBOARD_YOUR_SCORE", 0xFFFFFFFF);
          v15 = UFG::UIScreenManager::s_instance->m_translator;
          if ( !v15
            || (v16 = (const char *)v15->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, v14)) == 0i64 )
          {
            v16 = "LEADERBOARD_YOUR_SCORE";
          }
          UFG::qString::qString(&v44);
          UFG::qString::Format(&v44, "%s: %s", v16, myscore);
          v39 = &customWorldMapCaption;
          v40 = "$HUD_SOCIAL_AWARDBRONZE";
          v41 = "$HUD_SOCIAL_AWARDSILVER";
          v42 = "$HUD_SOCIAL_AWARDGOLD";
          `eh vector constructor iterator'(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          if ( (v21 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v20 + 16i64))(v20, &ptr, v22);
            v20 = 0i64;
          }
          v21 = 6;
          v22 = v6;
          if ( (v25 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v24 + 16i64))(v24, &v23, v26);
            v24 = 0i64;
          }
          v25 = 6;
          v26 = v5;
          v17 = v44.mData;
          if ( (v29 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v28 + 16i64))(v28, &v27, v30);
            v28 = 0i64;
          }
          v29 = 6;
          v30 = v17;
          if ( (v33 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v32 + 16i64))(
              v32,
              &v31,
              COERCE_DOUBLE(*(_QWORD *)&v34));
            v32 = 0i64;
          }
          v33 = 5;
          v34 = (double)((signed int)v7 - 1);
          v18 = (__int64)(&v39)[v7];
          if ( (v37 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v36 + 16i64))(v36, &v35, v38);
            v36 = 0i64;
          }
          v37 = 6;
          v38 = v18;
          Scaleform::GFx::Movie::Invoke(v10, "StatGame_SetStatAward", 0i64, (Scaleform::GFx::Value *)&ptr, 5u);
          v8->mStatInfoTimer = 5.0;
          v8->mStatSocialAwardActive = 1;
          `eh vector destructor iterator'(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
          UFG::qString::~qString(&v44);
        }
      }
    }
  }
}

// File Line: 1141
// RVA: 0x608960
void __fastcall UFG::UIHKScreenHud::SetStatGameInfo(UFG::UIHKScreenHud *this, const char *statInfo, const char *myname, const char *myscore, const char *leader, const char *leaderscore)
{
  const char *v6; // r13
  const char *v7; // r15
  const char *v8; // rbx
  UFG::UIHKScreenHud *v9; // rsi
  UFG::UIScreenRenderable *v10; // rax
  Scaleform::GFx::Movie *v11; // r14
  UFG::GameStatTracker *v12; // rax
  UFG::UIHK_PDAWidget *v13; // rcx
  UFG::ePDAStateEnum v14; // eax
  const char *v15; // r12
  const char *v16; // rbx
  const char *v17; // rdi
  char *v18; // rbx
  char *v19; // rbx
  unsigned int v20; // eax
  char ptr; // [rsp+30h] [rbp-D0h]
  __int64 v22; // [rsp+40h] [rbp-C0h]
  unsigned int v23; // [rsp+48h] [rbp-B8h]
  const char *v24; // [rsp+50h] [rbp-B0h]
  char v25; // [rsp+60h] [rbp-A0h]
  __int64 v26; // [rsp+70h] [rbp-90h]
  unsigned int v27; // [rsp+78h] [rbp-88h]
  const char *v28; // [rsp+80h] [rbp-80h]
  char v29; // [rsp+90h] [rbp-70h]
  __int64 v30; // [rsp+A0h] [rbp-60h]
  unsigned int v31; // [rsp+A8h] [rbp-58h]
  char *v32; // [rsp+B0h] [rbp-50h]
  char v33; // [rsp+C0h] [rbp-40h]
  __int64 v34; // [rsp+D0h] [rbp-30h]
  unsigned int v35; // [rsp+D8h] [rbp-28h]
  const char *v36; // [rsp+E0h] [rbp-20h]
  char v37; // [rsp+F0h] [rbp-10h]
  __int64 v38; // [rsp+100h] [rbp+0h]
  unsigned int v39; // [rsp+108h] [rbp+8h]
  char *v40; // [rsp+110h] [rbp+10h]
  __int64 v41; // [rsp+120h] [rbp+20h]
  UFG::qString v42; // [rsp+128h] [rbp+28h]
  UFG::qString v43; // [rsp+150h] [rbp+50h]

  v41 = -2i64;
  v6 = myscore;
  v7 = myname;
  v8 = statInfo;
  v9 = this;
  v10 = this->mRenderable;
  if ( v10 )
  {
    v11 = v10->m_movie.pObject;
    if ( v11 )
    {
      v12 = UFG::GameStatTracker::Instance();
      if ( !(unsigned __int8)UFG::GameStatTracker::GetStat(v12, OptionsDisableSocial) )
      {
        if ( !v9->PDA
          || (!UFG::UIHKScreenHud::mInstance || (v13 = UFG::UIHKScreenHud::mInstance->PDA) == 0i64 ? (v14 = UFG::UIHKScreenHud::PDACache.state) : (v14 = v13->mState),
              v14 == STATE_IDLE) )
        {
          if ( v9->mStatInfoTimer <= 0.0 )
          {
            v15 = UFG::UI::LocalizeText(v8);
            v16 = UFG::UI::LocalizeText("LEADERBOARD_YOUR_SCORE");
            v17 = UFG::UI::LocalizeText("LEADERBOARD_SCORE_TO_BEAT");
            UFG::qString::qString(&v43);
            UFG::qString::qString(&v42);
            UFG::qString::Format(&v43, "%s: %s", v16, v6);
            UFG::qString::Format(&v42, "%s: %s", v17, leaderscore);
            `eh vector constructor iterator'(
              &ptr,
              0x30ui64,
              5,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
            if ( (v23 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v22 + 16i64))(v22, &ptr, v24);
              v22 = 0i64;
            }
            v23 = 6;
            v24 = v15;
            if ( (v27 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v26 + 16i64))(v26, &v25, v28);
              v26 = 0i64;
            }
            v27 = 6;
            v28 = v7;
            v18 = v43.mData;
            if ( (v31 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v30 + 16i64))(v30, &v29, v32);
              v30 = 0i64;
            }
            v31 = 6;
            v32 = v18;
            if ( (v35 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v34 + 16i64))(v34, &v33, v36);
              v34 = 0i64;
            }
            v35 = 6;
            v36 = leader;
            v19 = v42.mData;
            if ( (v39 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v38 + 16i64))(v38, &v37, v40);
              v38 = 0i64;
            }
            v39 = 6;
            v40 = v19;
            Scaleform::GFx::Movie::Invoke(v11, "StatGame_SetLocalInfo", 0i64, (Scaleform::GFx::Value *)&ptr, 5u);
            if ( !v9->mStatGameInfoActive )
            {
              v20 = UFG::TiDo::CalcWwiseUid("Play_ui_stat_game");
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(
                  (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                  v20,
                  0i64,
                  0,
                  0i64);
              v9->mStatGameInfoActive = 1;
            }
            `eh vector destructor iterator'(
              &ptr,
              0x30ui64,
              5,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
            UFG::qString::~qString(&v42);
            UFG::qString::~qString(&v43);
          }
        }
      }
    }
  }
}

// File Line: 1185
// RVA: 0x608C50
void __fastcall UFG::UIHKScreenHud::SetStatMakingNewRecord(UFG::UIHKScreenHud *this)
{
  UFG::UIScreenRenderable *v1; // rax
  UFG::UIHKScreenHud *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  UFG::GameStatTracker *v4; // rax
  UFG::UIHK_PDAWidget *v5; // rcx
  UFG::ePDAStateEnum v6; // eax

  v1 = this->mRenderable;
  v2 = this;
  if ( v1 )
  {
    v3 = v1->m_movie.pObject;
    if ( v3 )
    {
      v4 = UFG::GameStatTracker::Instance();
      if ( !(unsigned __int8)UFG::GameStatTracker::GetStat(v4, OptionsDisableSocial) )
      {
        if ( !v2->PDA
          || (!UFG::UIHKScreenHud::mInstance || (v5 = UFG::UIHKScreenHud::mInstance->PDA) == 0i64 ? (v6 = UFG::UIHKScreenHud::PDACache.state) : (v6 = v5->mState),
              v6 == STATE_IDLE) )
        {
          if ( v2->mStatInfoTimer <= 0.0 )
            Scaleform::GFx::Movie::Invoke(v3, "StatGame_ShowSettingHighRecord", 0i64, 0i64, 0);
        }
      }
    }
  }
}

// File Line: 1205
// RVA: 0x6084C0
void __fastcall UFG::UIHKScreenHud::SetStatGameBeatHim(UFG::UIHKScreenHud *this, const char *hisname, const char *score)
{
  const char *v3; // rsi
  const char *v4; // rbp
  UFG::UIHKScreenHud *v5; // rbx
  UFG::UIScreenRenderable *v6; // rax
  Scaleform::GFx::Movie *v7; // rdi
  UFG::GameStatTracker *v8; // rax
  UFG::UIHK_PDAWidget *v9; // rcx
  UFG::ePDAStateEnum v10; // eax
  const char *v11; // rbx
  char *v12; // rbx
  char ptr; // [rsp+30h] [rbp-98h]
  __int64 v14; // [rsp+40h] [rbp-88h]
  unsigned int v15; // [rsp+48h] [rbp-80h]
  char *v16; // [rsp+50h] [rbp-78h]
  char v17; // [rsp+60h] [rbp-68h]
  __int64 v18; // [rsp+70h] [rbp-58h]
  unsigned int v19; // [rsp+78h] [rbp-50h]
  const char *v20; // [rsp+80h] [rbp-48h]
  __int64 v21; // [rsp+90h] [rbp-38h]
  UFG::qString v22; // [rsp+98h] [rbp-30h]

  v21 = -2i64;
  v3 = score;
  v4 = hisname;
  v5 = this;
  v6 = this->mRenderable;
  if ( v6 )
  {
    v7 = v6->m_movie.pObject;
    if ( v7 )
    {
      v8 = UFG::GameStatTracker::Instance();
      if ( !(unsigned __int8)UFG::GameStatTracker::GetStat(v8, OptionsDisableSocial) )
      {
        if ( !v5->PDA
          || (!UFG::UIHKScreenHud::mInstance || (v9 = UFG::UIHKScreenHud::mInstance->PDA) == 0i64 ? (v10 = UFG::UIHKScreenHud::PDACache.state) : (v10 = v9->mState),
              v10 == STATE_IDLE) )
        {
          if ( !v5->mStatSocialAwardActive )
          {
            v11 = UFG::UI::LocalizeText("LEADERBOARD_YOU_BEAT");
            UFG::qString::qString(&v22);
            UFG::qString::Format(&v22, "%s: %s", v11, v4);
            `eh vector constructor iterator'(
              &ptr,
              0x30ui64,
              2,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
            v12 = v22.mData;
            if ( (v15 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v14 + 16i64))(v14, &ptr, v16);
              v14 = 0i64;
            }
            v15 = 6;
            v16 = v12;
            if ( (v19 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v18 + 16i64))(v18, &v17, v20);
              v18 = 0i64;
            }
            v19 = 6;
            v20 = v3;
            Scaleform::GFx::Movie::Invoke(v7, "StatGame_SetYouBeatHimInfo", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
            `eh vector destructor iterator'(
              &ptr,
              0x30ui64,
              2,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
            UFG::qString::~qString(&v22);
          }
        }
      }
    }
  }
}

// File Line: 1234
// RVA: 0x6086A0
void __fastcall UFG::UIHKScreenHud::SetStatGameFinalScore(UFG::UIHKScreenHud *this, int popup_id, const char *statDescr, int rank)
{
  unsigned int v4; // er15
  const char *v5; // rbx
  int v6; // er12
  UFG::UIHKScreenHud *v7; // rsi
  UFG::UIScreenRenderable *v8; // rax
  Scaleform::GFx::Movie *v9; // r14
  UFG::GameStatTracker *v10; // rax
  UFG::UIHK_PDAWidget *v11; // rcx
  UFG::ePDAStateEnum v12; // eax
  const char *v13; // r13
  const char *v14; // rbx
  const char *v15; // rdi
  const char *v16; // rdx
  char *v17; // rbx
  char *v18; // rbx
  char ptr; // [rsp+30h] [rbp-A8h]
  __int64 v20; // [rsp+40h] [rbp-98h]
  unsigned int v21; // [rsp+48h] [rbp-90h]
  double v22; // [rsp+50h] [rbp-88h]
  const char *v23; // [rsp+58h] [rbp-80h]
  char v24; // [rsp+60h] [rbp-78h]
  char v25; // [rsp+68h] [rbp-70h]
  __int64 v26; // [rsp+70h] [rbp-68h]
  __int64 v27; // [rsp+78h] [rbp-60h]
  unsigned int v28; // [rsp+80h] [rbp-58h]
  char *v29; // [rsp+88h] [rbp-50h]
  char v30; // [rsp+98h] [rbp-40h]
  __int64 v31; // [rsp+A8h] [rbp-30h]
  unsigned int v32; // [rsp+B0h] [rbp-28h]
  char *v33; // [rsp+B8h] [rbp-20h]
  UFG::qString v34; // [rsp+C8h] [rbp-10h]
  __int64 v35; // [rsp+F0h] [rbp+18h]
  UFG::qString v36; // [rsp+F8h] [rbp+20h]
  void *retaddr; // [rsp+178h] [rbp+A0h]

  v35 = -2i64;
  v4 = rank;
  v5 = statDescr;
  v6 = popup_id;
  v7 = this;
  v8 = this->mRenderable;
  if ( v8 )
  {
    v9 = v8->m_movie.pObject;
    if ( v9 )
    {
      v10 = UFG::GameStatTracker::Instance();
      if ( !(unsigned __int8)UFG::GameStatTracker::GetStat(v10, OptionsDisableSocial) )
      {
        if ( !v7->PDA
          || (!UFG::UIHKScreenHud::mInstance || (v11 = UFG::UIHKScreenHud::mInstance->PDA) == 0i64 ? (v12 = UFG::UIHKScreenHud::PDACache.state) : (v12 = v11->mState),
              v12 == STATE_IDLE) )
        {
          if ( !v7->mStatSocialAwardActive )
          {
            `eh vector constructor iterator'(
              &ptr,
              0x30ui64,
              4,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
            v13 = UFG::UI::LocalizeText(v5);
            v14 = UFG::UI::LocalizeText("$LEADERBOARD_YOUR_SCORE");
            v15 = UFG::UI::LocalizeText("$LEADERBOARD_YOUR_RANK");
            UFG::qString::qString(&v36);
            UFG::qString::qString(&v34);
            UFG::qString::Format(&v36, "%s: %s", v14, retaddr, Scaleform::GFx::Value::~Value);
            UFG::qString::Format(&v34, v15, v4);
            if ( !UFG::OSuiteManager::Instance()->m_bConnected )
            {
              if ( v4 == 1 )
                v16 = UFG::UI::LocalizeText(asc_1417E0F68);
              else
                v16 = &customWorldMapCaption;
              UFG::qString::Set(&v34, v16);
            }
            if ( (v21 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v20 + 16i64))(
                v20,
                &ptr,
                COERCE_DOUBLE(*(_QWORD *)&v22));
              v20 = 0i64;
            }
            v21 = 5;
            v22 = (double)v6;
            if ( ((unsigned int)v27 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v26 + 16i64))(v26, &v24, v23);
              v26 = 0i64;
            }
            LODWORD(v27) = 6;
            v23 = v13;
            v17 = v34.mData;
            if ( (v28 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v27 + 16i64))(v27, &v25, v29);
              v27 = 0i64;
            }
            v28 = 6;
            v29 = v17;
            v18 = v36.mData;
            if ( (v32 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v31 + 16i64))(v31, &v30, v33);
              v31 = 0i64;
            }
            v32 = 6;
            v33 = v18;
            Scaleform::GFx::Movie::Invoke(v9, "StatGame_SetFinalScore", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
            v7->mStatInfoTimer = 5.0;
            UFG::qString::~qString(&v34);
            UFG::qString::~qString(&v36);
            `eh vector destructor iterator'(
              &ptr,
              0x30ui64,
              4,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
          }
        }
      }
    }
  }
}

// File Line: 1282
// RVA: 0x5EE880
bool __fastcall UFG::UIHKScreenHud::IsStatGameShowingFinalScore(UFG::UIHKScreenHud *this)
{
  return this->mStatInfoTimer > 0.0 && !this->mStatSocialAwardActive;
}

// File Line: 1292
// RVA: 0x5ED170
void __fastcall UFG::UIHKScreenHud::HideStatGameInfo(UFG::UIHKScreenHud *this)
{
  UFG::UIScreenRenderable *v1; // rax
  UFG::UIHKScreenHud *v2; // rbx
  Scaleform::GFx::Movie *v3; // rcx

  v1 = this->mRenderable;
  v2 = this;
  if ( v1 )
  {
    v3 = v1->m_movie.pObject;
    if ( v3 )
    {
      v2->mStatSocialAwardActive = 0;
      Scaleform::GFx::Movie::Invoke(v3, "StatGame_Hide", 0i64, 0i64, 0);
      v2->mStatGameInfoActive = 0;
    }
  }
}

// File Line: 1306
// RVA: 0x5F08B0
void __fastcall UFG::UIHKScreenHud::LeadUnlocked(UFG::UIHKScreenHud *this, __int64 assetID)
{
  _DWORD *v2; // rsi
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *v4; // rax
  UFG::qPropertyList *v5; // rbp
  unsigned int v6; // edi
  unsigned int v7; // ebx
  char *v8; // rax
  UFG::qPropertySet *v9; // rcx
  char *v10; // rax
  UFG::qString v11; // [rsp+28h] [rbp-30h]
  UFG::qSymbol result; // [rsp+60h] [rbp+8h]

  v2 = (_DWORD *)assetID;
  if ( this->mRenderable->m_movie.pObject )
  {
    v3 = UFG::qSymbol::create_from_string(&result, "default-unlockables-caseLeads-list");
    v4 = UFG::PropertySetManager::GetPropertySet(v3);
    v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(v4, (UFG::qSymbol *)&qSymbol_List_20.mUID, DEPTH_RECURSE);
    UFG::qString::qString(&v11);
    if ( v5 )
    {
      v6 = v5->mNumElements;
      v7 = 0;
      if ( v6 )
      {
        while ( 1 )
        {
          v8 = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v7);
          if ( v8 && *(_QWORD *)v8 )
            v9 = (UFG::qPropertySet *)&v8[*(_QWORD *)v8];
          else
            v9 = 0i64;
          if ( v9->mName.mUID == *v2 )
            break;
          if ( ++v7 >= v6 )
            goto LABEL_12;
        }
        v10 = PropertyUtils::Get<char const *>(v9, (UFG::qSymbol *)&qSymbol_Description_20.mUID, DEPTH_RECURSE);
        UFG::qString::Set(&v11, v10);
      }
    }
LABEL_12:
    UFG::qString::~qString(&v11);
  }
}

// File Line: 1345
// RVA: 0x60A030
void __fastcall UFG::UIHKScreenHud::SetTexturePackForFlow(const char *flowPostfix)
{
  const char *v1; // rbx
  int v2; // eax
  const char *v3; // rdx
  UFG::UIScreenTextureManager *v4; // rax
  UFG::qBaseTreeRB *v5; // rax
  UFG::qString v6; // [rsp+28h] [rbp-30h]

  v1 = flowPostfix;
  UFG::qString::qString(&v6);
  v2 = UFG::qStringCompare(v1, "G", -1);
  v3 = "Data\\UI\\hud_texturepack_ghost.perm.bin";
  if ( v2 )
    v3 = "Data\\UI\\hud_texturepack.perm.bin";
  UFG::qString::Set(&v6, v3);
  UFG::UIHKScreenHud::gTexturePackFilename = v6.mData;
  v4 = UFG::UIScreenTextureManager::Instance();
  v5 = UFG::UIScreenTextureManager::GetScreenInfo(v4, "Hud");
  UFG::UIScreenTextureManager::ScreenInfo::SetTexturePack((UFG::UIScreenTextureManager::ScreenInfo *)v5, v6.mData);
  UFG::qString::~qString(&v6);
}

