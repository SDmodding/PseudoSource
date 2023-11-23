// File Line: 105
// RVA: 0x1566BB0
__int64 dynamic_initializer_for__UFG::UIHKScreenHud::PDACache__()
{
  UFG::qString::qString(&stru_142431A20);
  UFG::UIHKScreenHud::PDACache.state = STATE_IDLE;
  byte_142431A14 = 0;
  dword_142431A18 = 0;
  UFG::qString::Set(&stru_142431A20, &customCaption);
  unk_142431A48 = 0;
  unk_142431A4A = 0;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenHud::PDACache__);
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

  v0 = (UFG::UIScreenInvokeQueue *)UFG::qMemoryPool::Allocate(
                                     &gScaleformMemoryPool,
                                     0x20ui64,
                                     "UIHKScreenHud",
                                     0i64,
                                     1u);
  if ( v0 )
  {
    v0->vfptr = (UFG::UIScreenInvokeQueueVtbl *)&UFG::UIScreenInvokeQueue::`vftable;
    v0->mNumCommandsPerFrame = -1;
    v0->mCommandQueue.mNode.mPrev = &v0->mCommandQueue.mNode;
    v0->mCommandQueue.mNode.mNext = &v0->mCommandQueue.mNode;
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
    `eh vector constructor iterator(
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
    v30->mNext = (UFG::allocator::free_link *)&UFG::UIHKMissionRewardsWidget::`vftable;
    v30[1].mNext = (UFG::allocator::free_link *)&UFG::UIHKMissionRewardsHeaderWidget::`vftable;
    *(UFG::allocator::free_link **)((char *)&v30[2].mNext + 4) = 0i64;
    v30[4].mNext = (UFG::allocator::free_link *)&UFG::UIHKMissionRewardsFlasherWidget::`vftable;
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
  UFG::GameStatTracker *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::UIHK_PDAWidget *v4; // rax

  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = eDIM_INVALID;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenHud::`vftable;
  UFG::UITiledMapWidget::UITiledMapWidget(&this->Minimap);
  this->HealthMeter.mHealthPercent = -1.0;
  this->HealthMeter.mHealthPercentOfMaxPossible = -1.0;
  *(_WORD *)&this->HealthMeter.mChanged = 1;
  this->HealthMeter.mIsFirstUpdate = 1;
  UFG::UIHKWeaponAmmoWidget::UIHKWeaponAmmoWidget(&this->WeaponAmmo);
  this->RadioStationWidget.mState = STATE_IDLE;
  *(_DWORD *)&this->RadioStationWidget.mChanged = 257;
  *(_QWORD *)&this->RadioStationWidget.mCurrentStation = 0i64;
  this->RadioStationWidget.mWaitingForTextureTimer = 0.0;
  this->RadioStationWidget.mStationData.p = 0i64;
  *(_QWORD *)&this->RadioStationWidget.mStationData.size = 0i64;
  UFG::qString::qString(&this->RadioStationWidget.mLoadedTexturePack);
  UFG::UIHKRadioStationWidget::ReadStationList(&this->RadioStationWidget);
  *(_WORD *)&this->ActionHijack.mChanged = 0;
  this->ActionHijack.mDistance = 0.0;
  this->ActionHijack.mCanHijack = 0;
  *(_DWORD *)&this->MoneyPopup.mIsVisible = 0;
  *(_WORD *)&this->MoneyPopup.mTryToHide = 0;
  *(_QWORD *)&this->MoneyPopup.mMoney = 0i64;
  v2 = UFG::GameStatTracker::Instance();
  this->MoneyPopup.mMoney = UFG::GameStatTracker::GetStat(v2, Money);
  UFG::qString::qString(&this->Buffs.mTexturePackFilename);
  `eh vector constructor iterator(
    this->Buffs.mIconLoaded,
    0x28ui64,
    7,
    (void (__fastcall *)(void *))UFG::qString::qString);
  *(_WORD *)&this->Buffs.mPerkActivate = 0;
  this->Buffs.mPerkTimer = 0.0;
  this->SocialActionManager.mScoredTargets.size = 0;
  this->SocialActionManager.mTargets.size = 0;
  this->SocialActionManager.mWidgetIndexToUpdate = -1;
  *(_WORD *)&this->SocialActionManager.mIconsReset = 256;
  UFG::UIHKSocialActionManager::mThis = &this->SocialActionManager;
  ++this->SocialActionManager.mTargets.size;
  ++this->SocialActionManager.mTargets.size;
  ++this->SocialActionManager.mTargets.size;
  ++this->SocialActionManager.mTargets.size;
  ++this->SocialActionManager.mTargets.size;
  this->SocialActionManager.mTargets.p[0].m_pSimObject = 0i64;
  this->SocialActionManager.mTargets.p[0].m_fScore = 0.0;
  this->SocialActionManager.mTargets.p[1].m_pSimObject = 0i64;
  this->SocialActionManager.mTargets.p[1].m_fScore = 0.0;
  this->SocialActionManager.mTargets.p[2].m_pSimObject = 0i64;
  this->SocialActionManager.mTargets.p[2].m_fScore = 0.0;
  this->SocialActionManager.mTargets.p[3].m_pSimObject = 0i64;
  this->SocialActionManager.mTargets.p[3].m_fScore = 0.0;
  this->SocialActionManager.mTargets.p[4].m_pSimObject = 0i64;
  this->SocialActionManager.mTargets.p[4].m_fScore = 0.0;
  UFG::UIHKSecondaryObjectivesWidget::UIHKSecondaryObjectivesWidget(&this->SecondaryObjectives);
  this->ObjectiveFlasher.mOldVisible = 0;
  *(_QWORD *)&this->mState = 0i64;
  this->mMinimapFadeTimeout = 0.0;
  this->mMinimapVisibleChanged = 1;
  *(_DWORD *)&this->Reticle.mChanged = 1;
  this->Reticle.mVisible = 1;
  *(_QWORD *)&this->Reticle.mScreenX = 0i64;
  *(_QWORD *)&this->Reticle.mRadius = 0i64;
  *(_QWORD *)&this->Reticle.mfSizeMax = 0i64;
  *(_WORD *)&this->Reticle.mLockAnimationPlaying = 0;
  this->Reticle.mHasAmmo = 1;
  *(_QWORD *)&this->Reticle.mTargetFaction = 1i64;
  this->DirectionalDamage.mDDTimers[0].bActive = 0;
  this->DirectionalDamage.mDDTimers[0].fElapsedTime = 0.0;
  this->DirectionalDamage.mDDTimers[1].bActive = 0;
  this->DirectionalDamage.mDDTimers[1].fElapsedTime = 0.0;
  this->DirectionalDamage.mDDTimers[2].bActive = 0;
  this->DirectionalDamage.mDDTimers[2].fElapsedTime = 0.0;
  this->DirectionalDamage.mDDTimers[3].bActive = 0;
  *(_QWORD *)&this->DirectionalDamage.mDDTimers[3].fElapsedTime = 0i64;
  this->HeatLevel.mHeatLevel = -1;
  *(_WORD *)&this->HeatLevel.mCopCooldown = 256;
  this->HeatLevel.mVisibleChanged = 0;
  this->TimeOfDay.mLightingConditions = LIGHTING_INVALID;
  this->SniperWidget.vfptr = (UFG::UIHKSniperWidgetVtbl *)&UFG::UIHKSniperWidget::`vftable;
  this->SniperWidget.mState = STATE_HIDE;
  this->SniperWidget.mSniperMode = 0;
  this->mStatInfoTimer = 0.0;
  *(_DWORD *)&this->mStatSocialAwardActive = 0x1000000;
  UFG::UIHKScreenHud::mInstance = this;
  v3 = UFG::qMalloc(0x300ui64, "PDAWidget", 0i64);
  if ( v3 )
    UFG::UIHK_PDAWidget::UIHK_PDAWidget((UFG::UIHK_PDAWidget *)v3, &UFG::UIHKScreenHud::PDACache);
  else
    v4 = 0i64;
  this->PDA = v4;
  UFG::UIHKScreenHud::PDACache.state = STATE_IDLE;
  byte_142431A14 = 0;
  dword_142431A18 = 0;
}

// File Line: 179
// RVA: 0x5CB110
void __fastcall UFG::UIHKScreenHud::~UIHKScreenHud(UFG::UIHKScreenHud *this)
{
  UFG::UIHK_PDAWidget *PDA; // rcx
  UFG::UIHKMissionRewardsWidget *v3; // rbx
  UFG::UIScreenTextureManager *v4; // rax
  UFG::UIHKMissionRewardsHeaderWidget::eState mState; // eax
  UFG::UIHKCombatMeterWidget *v6; // rcx
  UFG::UIScreenTextureManager *v7; // rax
  UFG::UIScreenTextureManager *v8; // rax
  UFG::UIHKGameplayHelpWidget *v9; // rdx
  UFG::UIHKScreenGlobalOverlay *v10; // rcx
  int v11; // eax
  UFG::UIHKScreenGlobalOverlay *v12; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenHud::`vftable;
  UFG::UIHKScreenHud::PopulatePDACache(this);
  PDA = this->PDA;
  if ( PDA )
    PDA->vfptr->__vecDelDtor(PDA, 1u);
  this->PDA = 0i64;
  UFG::UIMapInteriorManager::HandleScreenDestruct(UFG::UIHKScreenHud::mInteriorManager, &this->Minimap);
  v3 = UFG::UIHKScreenHud::MissionRewards;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v4, UFG::UIHKMissionRewardsWidget::gTexturePackFilename);
  if ( v3->mState )
  {
    mState = v3->Header.mState;
    if ( mState == (STATE_SYNCED|STATE_WAITING) || mState == STATE_NONE )
      v3->mShouldSkipHeader = 1;
    v3->mState = STATE_SYNCED|STATE_WAITING|0x8;
  }
  v3->Rewards.vfptr->HandleScreenDestruct(&v3->Rewards);
  v6 = UFG::UIHKScreenHud::CombatMeter;
  UFG::UIHKScreenHud::CombatMeter->mSleepPrevState = UFG::UIHKScreenHud::CombatMeter->mState;
  v6->mState = STATE_INCOMING_TEXT;
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
      v11 = --UFG::UIHKHelpBarWidget::mLocked;
    if ( v11 < 1 )
    {
      v12 = UFG::UIHKScreenGlobalOverlay::mThis;
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v12 = &gGlobalOverlaySentinel;
      v12->HelpBar.mChanged = 1;
    }
    v9->mShowingInFlash = 0;
  }
  this->SniperWidget.vfptr = (UFG::UIHKSniperWidgetVtbl *)&UFG::UIHKSniperWidget::`vftable;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    v10 = UFG::UIHKScreenGlobalOverlay::mThis;
  UFG::UIHKHelpBarWidget::Hide(&v10->HelpBar, UI_HASH_SNIPER);
  UFG::qString::~qString(&this->SecondaryObjectives.mTriadObjective.Caption);
  UFG::qString::~qString(&this->SecondaryObjectives.mCopObjective.Caption);
  UFG::UIHKSocialActionManager::mThis = 0i64;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    UFG::UIHKHelpBarWidget::Hide(&UFG::UIHKScreenGlobalOverlay::mThis->HelpBar, UI_HASH_HELPBAR_SOCIAL_20);
  this->SocialActionManager.mTargets.size = 0;
  this->SocialActionManager.mScoredTargets.size = 0;
  UFG::UIHKBuffWidget::~UIHKBuffWidget(&this->Buffs);
  UFG::UIHKRadioStationWidget::~UIHKRadioStationWidget(&this->RadioStationWidget);
  UFG::UIHKWeaponAmmoWidget::~UIHKWeaponAmmoWidget(&this->WeaponAmmo);
  UFG::UITiledMapWidget::~UITiledMapWidget(&this->Minimap);
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 205
// RVA: 0x632060
void __fastcall UFG::UIHKScreenHud::init(UFG::UIHKScreenHud *this, UFG::UICommandData *data)
{
  UFG::GameStatTracker *v3; // rax
  bool Stat; // al
  UFG::UIScreenRenderable *mRenderable; // rsi
  UFG::UIHKMissionProgressWidget *v6; // rax
  UFG::UIHKInfoPopupWidget *v7; // rcx
  UFG::UIHKActionButtonWidget *v8; // rcx
  UFG::UIHKObjectiveDistanceWidget *v9; // rax
  UFG::UIHKBuffData *v10; // rcx
  __int64 v11; // rdx
  UFG::UIHKMissionHealthWidget *v12; // rax
  UFG::UIHKRegionIndicatorWidget *v13; // rcx
  bool mVisible; // r8
  UFG::UIHKCombatMeterWidget *v15; // rax
  UFG::UIHKGameplayHelpWidget *v16; // rcx
  UFG::UIHK_XPFlasherWidget *v17; // rax
  UFG::UIScreenTextureManager *v18; // rax
  UFG::Controller *v19; // rdx
  UFG::UIHKScreenGlobalOverlay *v20; // rax

  UFG::UIScreen::init(this, data);
  v3 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v3, HudEnable);
  mRenderable = this->mRenderable;
  this->mHudEnable = Stat;
  if ( mRenderable )
  {
    this->mState = STATE_QUEUED;
    UFG::UITiledMapWidget::Init(&this->Minimap, this);
    this->PDA->vfptr->init(this->PDA, this);
    this->Minimap.mVisible = UFG::UIHKTweakables::RenderMinimap;
    mRenderable->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
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
      UFG::UIHKScreenHud::InfoPopup->mState = STATE_IDLE;
    if ( v7->mState )
      v7->mState = STATE_ROOT_MENU;
    UFG::UIHKReticleWidget::HandleScreenInit(&this->Reticle, this);
    UFG::UIHKHealthMeterWidget::Flash_SetVisible(&this->HealthMeter, this, 0);
    v8 = UFG::UIHKScreenHud::ActionButton;
    UFG::UIHKScreenHud::ActionButton->mChanged = 1;
    UFG::UIHKActionButtonWidget::Update(v8, this);
    v9 = UFG::UIHKScreenHud::ObjectiveDistance;
    UFG::UIHKScreenHud::ObjectiveDistance->mChanged = 1;
    v9->mColorChanged = 1;
    v9->mOldDistance = -1.0;
    UFG::UIMapLinesWidget::HandleScreenInit(UFG::UIHKScreenHud::MapLines);
    UFG::UIHKScreenHud::MapLines->mClipToPlayerPos = 1;
    UFG::UITiledMapGPS::HandleScreenInit(UFG::UIHKScreenHud::GPS, this);
    UFG::UITiledMapGPS::UsePlayerSourcePosition(UFG::UIHKScreenHud::GPS);
    UFG::UIHKScreenHud::GPS->mOnlyShowInVehicles = UFG::UIHKTweakables::OnlyShowGPSInVehicles;
    if ( UFG::UIHKBuffWidget::mNumBuffs )
    {
      v10 = UFG::UIHKBuffWidget::mBuffData;
      v11 = UFG::UIHKBuffWidget::mNumBuffs;
      do
      {
        if ( (unsigned int)(v10->mState - 2) <= 1 )
          v10->mState = STATE_INCOMING_CALL;
        ++v10;
        --v11;
      }
      while ( v11 );
    }
    UFG::UIHKSocialActionManager::Init(&this->SocialActionManager, this);
    v12 = UFG::UIHKScreenHud::MissionHealth;
    UFG::UIHKScreenHud::MissionHealth->mChanged = 1;
    v12->mVisibleChanged = 1;
    UFG::UIHKScreenHud::TurnHint->mChanged = UFG::UIHKScreenHud::TurnHint->mVisible;
    UFG::UIHKScreenHud::TraceSignalBar->mVisible = 0;
    *(_WORD *)&UFG::UIHKScreenHud::RaceTimer->mTimeChanged = 257;
    UFG::UIHKScreenHud::RacePosition->mChanged = 1;
    UFG::UIHKScreenHud::RacePercentage->mChanged = 1;
    *(_WORD *)&this->SecondaryObjectives.mCopObjective.CaptionChanged = 257;
    *(_WORD *)&this->SecondaryObjectives.mTriadObjective.CaptionChanged = 257;
    UFG::UIHKSecondaryObjectivesWidget::UpdateObjective(
      &this->SecondaryObjectives,
      this,
      0.0,
      &this->SecondaryObjectives.mCopObjective,
      1);
    UFG::UIHKSecondaryObjectivesWidget::UpdateObjective(
      &this->SecondaryObjectives,
      this,
      0.0,
      &this->SecondaryObjectives.mTriadObjective,
      0);
    UFG::UIHKMissionRewardsWidget::HandleScreenInit(UFG::UIHKScreenHud::MissionRewards, this);
    v13 = UFG::UIHKScreenHud::RegionIndicator;
    mVisible = UFG::UIHKScreenHud::RegionIndicator->mVisible;
    UFG::UIHKScreenHud::RegionIndicator->mChanged = 0;
    UFG::UIHKRegionIndicatorWidget::Flash_SetVisible(v13, this, mVisible);
    UFG::UIHKObjectiveFlasherWidget::mState = (unsigned int)(UFG::UIHKObjectiveFlasherWidget::mState - 3) > 1
                                           && UFG::UIHKObjectiveFlasherWidget::mState != STATE_IDLE;
    v15 = UFG::UIHKScreenHud::CombatMeter;
    if ( UFG::UIHKScreenHud::CombatMeter->mSleepPrevState == STATE_INCOMING_CALL )
      UFG::UIHKScreenHud::CombatMeter->mPreserveBuffStartingDuration = 1;
    *(_QWORD *)&v15->mState = 0i64;
    UFG::UIHKScreenHud::HintText->vfptr->HandleScreenInit(UFG::UIHKScreenHud::HintText, this);
    v16 = UFG::UIHKScreenHud::GameplayHelp;
    UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    UFG::UIHKGameplayHelpWidget::Update(v16, this);
    v17 = UFG::UIHKScreenHud::XPFlasher;
    if ( UFG::UIHKScreenHud::XPFlasher->mState )
    {
      if ( UFG::UIHKScreenHud::XPFlasher->mState == STATE_PHONE_CONTACTS )
      {
        UFG::UIHKScreenHud::XPFlasher->mStateElapsed = 0.0;
        if ( v17->mData[0].Total > 0 )
          v17->mData[0].Changed = 1;
        if ( v17->mData[1].Total > 0 )
          v17->mData[1].Changed = 1;
        if ( v17->mData[2].Total > 0 )
          v17->mData[2].Changed = 1;
      }
    }
    else
    {
      UFG::UIHKScreenHud::XPFlasher->mState = STATE_ROOT_MENU;
    }
    if ( UFG::UIHKScreenHud::mOnDemandTextureLoadRefCounter > 0 )
    {
      v18 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueTexturePackLoad(
        v18,
        UFG::kOnDemandTexturePackFilename,
        HIGH_PRIORITY,
        (UFG::qReflectInventoryBase *)UFG::UIHKScreenHud::HandleTutorialHudTexturePackLoaded,
        0i64);
    }
    v19 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( v19 && v19->m_ActiveMapSet == 8 && !UFG::UI::gUIInputLocked )
      UFG::UIHKScreenHud::EmergencyInputModeRecovery(this);
    v20 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v20 = &gGlobalOverlaySentinel;
    v20->HelpBar.mChanged = 1;
  }
}

// File Line: 279
// RVA: 0x63D310
void __fastcall UFG::UIHKScreenHud::update(UFG::UIHKScreenHud *this, float elapsed)
{
  char v4; // al
  bool v5; // dl
  UFG::UIScreenRenderable *mRenderable; // rax
  float mMinimapAlpha; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  float mStatInfoTimer; // xmm0_4
  float v11; // xmm0_4
  UFG::UIHKRacePositionWidget *v12; // rbx
  UFG::UIHKRacePositionWidget *v13; // rcx
  UFG::UIHKShortcutButtonWidget *v14; // rdx
  UFG::UIHKShortcutButtonWidget::eState mState; // ecx
  __int32 v16; // ecx
  float v17; // xmm0_4
  UFG::UIHKHelpBarWidget *p_HelpBar; // rcx
  float v19; // xmm0_4
  float mYOffset; // xmm0_4
  UFG::UIScreenRenderable *v21; // rcx

  if ( UFG::UIHKScreenHud::mHandleSigninChange )
  {
    v4 = UFG::UIHKMessageOverlay::HandleSigninChange();
    v5 = UFG::UIHKScreenHud::mHandleSigninChange;
    if ( v4 )
      v5 = 0;
    UFG::UIHKScreenHud::mHandleSigninChange = v5;
  }
  mRenderable = this->mRenderable;
  if ( mRenderable && mRenderable->m_shouldRender )
  {
    switch ( this->mState )
    {
      case STATE_QUEUED:
        v9 = elapsed + this->mMinimapFadeTimeout;
        this->mMinimapFadeTimeout = v9;
        if ( !UFG::UIHKScreenHud::mInteriorManager->mActive
          || UFG::UIHKScreenHud::mInteriorManager->mTextureLoaded
          || v9 > 5.0 )
        {
          this->mState = STATE_WAITING;
        }
        break;
      case STATE_WAITING:
        mMinimapAlpha = this->mMinimapAlpha;
        if ( mMinimapAlpha >= 1.0 )
          this->mState = STATE_EXECUTING;
        v8 = (float)(elapsed * 1.5) + mMinimapAlpha;
        this->mMinimapAlpha = v8;
        if ( v8 > 1.0 )
          this->mMinimapAlpha = 1.0;
        this->Minimap.mAlpha = this->mMinimapAlpha;
        break;
      case STATE_DONE:
        return;
    }
    mStatInfoTimer = this->mStatInfoTimer;
    if ( mStatInfoTimer > 0.0 )
    {
      v11 = mStatInfoTimer - elapsed;
      this->mStatInfoTimer = v11;
      if ( v11 <= 0.0 )
        UFG::UIHKScreenHud::HideStatGameInfo(this);
    }
    UFG::UIScreenInvokeQueue::Update(UFG::UIHKScreenHud::mScreenInvokeQueue, this);
    UFG::UITiledMapWidget::Update(
      &this->Minimap,
      this,
      elapsed,
      UFG::UIHKScreenHud::mIconManager,
      UFG::UIHKScreenHud::mInteriorManager,
      0i64,
      0i64,
      UFG::UIHKScreenHud::GPS);
    UFG::UIHKScreenHud::Flash_Update(this);
    UFG::UIHKSocialActionManager::Update(&this->SocialActionManager, this, elapsed);
    UFG::UIHKMissionProgressWidget::Update(UFG::UIHKScreenHud::MissionProgress, this);
    UFG::UIHKInfoPopupWidget::Update(UFG::UIHKScreenHud::InfoPopup, this, elapsed);
    UFG::UIHKMoneyPopupWidget::Update(&this->MoneyPopup, this, elapsed);
    UFG::UIHKWeaponAmmoWidget::Update(&this->WeaponAmmo, this, elapsed);
    UFG::UIHKReticleWidget::Update(&this->Reticle, this);
    UFG::UIHKHealthMeterWidget::Update(&this->HealthMeter, this, elapsed);
    UFG::UIHKDirectionalDamageWidget::Update(&this->DirectionalDamage, this, elapsed);
    UFG::UIHKCombatMeterWidget::Update(UFG::UIHKScreenHud::CombatMeter, this);
    UFG::UIHKHeatLevelWidget::Update(&this->HeatLevel, this);
    UFG::UIHKActionButtonWidget::Update(UFG::UIHKScreenHud::ActionButton, this);
    UFG::UIHKRadioStationWidget::Update(&this->RadioStationWidget, this, elapsed);
    UFG::UIHKWitnessManager::Update(UFG::UIHKScreenHud::WitnessManager, elapsed);
    UFG::UIHKTimeOfDayWidget::Update(&this->TimeOfDay, this);
    UFG::UIMapLinesWidget::Update(UFG::UIHKScreenHud::MapLines, elapsed, &this->Minimap.m_mapGeo);
    UFG::UIHKSniperWidget::Update(&this->SniperWidget, this);
    UFG::UIHKBuffWidget::Update(&this->Buffs, this, elapsed);
    UFG::UIHKMissionHealthWidget::Update(UFG::UIHKScreenHud::MissionHealth, this);
    UFG::UIHKUpgradePopupWidget::Update(UFG::UIHKScreenHud::UpgradePopup, this, elapsed);
    UFG::UIHKTurnHintWidget::Update(UFG::UIHKScreenHud::TurnHint, this);
    UFG::UIHKPhoneTraceSignalBarWidget::Update(UFG::UIHKScreenHud::TraceSignalBar, this);
    UFG::UIHKRaceTimerWidget::Update(UFG::UIHKScreenHud::RaceTimer, this);
    v12 = UFG::UIHKScreenHud::RacePosition;
    if ( UFG::UIHKScreenHud::RacePosition->mChanged )
    {
      v13 = UFG::UIHKScreenHud::RacePosition;
      UFG::UIHKScreenHud::RacePosition->mChanged = 0;
      UFG::UIHKRacePositionWidget::Flash_SetVisible(v13, this);
      if ( v12->mVisible )
        UFG::UIHKRacePositionWidget::Flash_SetPlayerPosition(v12, this);
    }
    UFG::UIHKRacePercentageWidget::Update(UFG::UIHKScreenHud::RacePercentage, this);
    UFG::UIHKSecondaryObjectivesWidget::UpdateObjective(
      &this->SecondaryObjectives,
      this,
      elapsed,
      &this->SecondaryObjectives.mCopObjective,
      1);
    UFG::UIHKSecondaryObjectivesWidget::UpdateObjective(
      &this->SecondaryObjectives,
      this,
      elapsed,
      &this->SecondaryObjectives.mTriadObjective,
      0);
    UFG::UIHKMissionRewardsWidget::Update(UFG::UIHKScreenHud::MissionRewards, this, elapsed);
    UFG::UIHKRegionIndicatorWidget::Update(UFG::UIHKScreenHud::RegionIndicator, this, elapsed);
    UFG::UIHKObjectiveFlasherWidget::Update(&this->ObjectiveFlasher, this);
    v14 = UFG::UIHKScreenHud::ShortcutButton;
    mState = UFG::UIHKScreenHud::ShortcutButton->mState;
    if ( mState && this->mRenderable->m_movie.pObject )
    {
      v16 = mState - 1;
      if ( v16 )
      {
        if ( v16 == 1 )
        {
          v17 = UFG::UIHKScreenHud::ShortcutButton->mTimeout - elapsed;
          UFG::UIHKScreenHud::ShortcutButton->mTimeout = v17;
          if ( v17 <= 0.0 )
            v14->mState = STATE_IDLE;
        }
      }
      else
      {
        UFG::UIHKScreenHud::ShortcutButton->mState = STATE_PHONE_CONTACTS;
      }
    }
    ((void (__fastcall *)(UFG::UIHKHintText *, UFG::UIHKScreenHud *))UFG::UIHKScreenHud::HintText->vfptr->Update)(
      UFG::UIHKScreenHud::HintText,
      this);
    UFG::UIHKGameplayHelpWidget::Update(UFG::UIHKScreenHud::GameplayHelp, this);
    UFG::UIHK_XPFlasherWidget::Update(UFG::UIHKScreenHud::XPFlasher, this, elapsed);
    UFG::UIHKSecondaryTutorialWidget::Update(UFG::UIHKScreenHud::SecondaryTutorial, this, elapsed);
    ((void (__fastcall *)(UFG::UIHK_PDAWidget *, UFG::UIHKScreenHud *))this->PDA->vfptr->update)(this->PDA, this);
    UFG::UIScreen::update(this, elapsed);
    if ( UFG::UIHKScreenGlobalOverlay::mThis
      && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-144i64 )
    {
      if ( UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay.mSubtitleQueue.mCurrent1
        || UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay.mSubtitleQueue.mCurrent2
        || (UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0> *)UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay.mSubtitleQueue.mQueue.mNode.mNext != &UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay.mSubtitleQueue.mQueue )
      {
        if ( UFG::UIHKScreenGlobalOverlay::mThis )
          p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
        else
          p_HelpBar = &gHelpBarSentinel;
        mYOffset = p_HelpBar->mYOffset;
        p_HelpBar->mYOffset = -70.0;
        v19 = mYOffset - -70.0;
      }
      else if ( UFG::UIHKScreenGlobalOverlay::mThis )
      {
        v19 = UFG::UIHKScreenGlobalOverlay::mThis->HelpBar.mYOffset;
        p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
        UFG::UIHKScreenGlobalOverlay::mThis->HelpBar.mYOffset = 0.0;
      }
      else
      {
        p_HelpBar = &gHelpBarSentinel;
        v19 = gHelpBarSentinel.mYOffset;
        gHelpBarSentinel.mYOffset = 0.0;
      }
      p_HelpBar->mChanged |= COERCE_FLOAT(LODWORD(v19) & _xmm) > 0.001;
    }
    if ( this->mUpdateStatGamePosition )
    {
      v21 = this->mRenderable;
      if ( v21 )
      {
        if ( v21->m_movie.pObject )
        {
          this->mUpdateStatGamePosition = 0;
          Scaleform::GFx::Movie::Invoke(v21->m_movie.pObject, "StatGame_MakeSafe", 0i64);
        }
      }
    }
  }
  else
  {
    UFG::UIScreen::update(this, elapsed);
  }
}ition = 0;
          Scaleform::GFx::Movie::Invoke(v21->m_movie.pObject, "StatGame_MakeSafe", 0i64);
        }
      }
    }
  }
  else
  {
    UFG::UISc

// File Line: 425
// RVA: 0x61FD40
void __fastcall UFG::UIHKScreenHud::customPreRender(UFG::UIHKScreenHud *this, Render::View *view)
{
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // rcx

  if ( UFG::UIHKScreenHud::ObjectiveDistance )
    UFG::UIHKObjectiveDistanceWidget::Update(UFG::UIHKScreenHud::ObjectiveDistance, this, gUIUpdateDelta);
  if ( this->mHudEnable && UFG::UIScreenManager::s_instance->m_renderUI && UFG::UIHKTweakables::RenderMinimap )
  {
    mRenderable = this->mRenderable;
    if ( mRenderable )
    {
      if ( mRenderable->m_shouldRender )
      {
        pObject = mRenderable->m_movie.pObject;
        if ( pObject )
        {
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Movie *))pObject->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[10].__vecDelDtor)(pObject) )
            UFG::UITiledMapWidget::RenderMinimapBackdrop(
              &this->Minimap,
              view,
              UFG::UIHKScreenHud::mInteriorManager,
              0i64,
              UFG::UIHKScreenHud::MapLines);
        }
      }
    }
  }
}

// File Line: 443
// RVA: 0x63A150
void __fastcall UFG::UIHKScreenHud::render(UFG::UIHKScreenHud *this)
{
  if ( this->mHudEnable && UFG::UIScreenManager::s_instance->m_renderUI )
    UFG::UIScreenRenderable::render(this->mRenderable);
}

// File Line: 451
// RVA: 0x61FC90
void __fastcall UFG::UIHKScreenHud::customPostRender(UFG::UIHKScreenHud *this, Render::View *view)
{
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // rcx

  if ( this->mHudEnable && UFG::UIScreenManager::s_instance->m_renderUI && UFG::UIHKTweakables::RenderMinimap )
  {
    mRenderable = this->mRenderable;
    if ( mRenderable )
    {
      if ( mRenderable->m_shouldRender )
      {
        pObject = mRenderable->m_movie.pObject;
        if ( pObject )
        {
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Movie *))pObject->Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[10].__vecDelDtor)(pObject) )
            UFG::UITiledMapWidget::Render(
              &this->Minimap,
              view,
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

// File Line: 474
// RVA: 0x623EA0
char __fastcall UFG::UIHKScreenHud::handleMessage(UFG::UIHKScreenHud *this, unsigned int msgId, UFG::UIMessage *msg)
{
  const char *v7; // rdx
  char v8; // r14
  bool v9; // bp
  char v10; // al
  unsigned __int8 v11; // bp
  NISManager *Instance; // rax
  UFG::UIHKRegionIndicatorWidget *v13; // rdx
  unsigned int vfptr; // ecx
  bool v15; // zf
  UFG::UIHKCombatMeterWidget *v16; // rax

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
    if ( !UFG::UIScreenDialogBox::m_iDialogBoxRefCount )
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
  if ( UFG::UIHKShortcutButtonWidget::HandleMessage(UFG::UIHKScreenHud::ShortcutButton, this, msgId, msg) )
    return 1;
  if ( (msgId == UI_HASH_BUTTON_START_PRESSED_30 || msgId == UI_HASH_BUTTON_SELECT_PRESSED_30)
    && this->mState != STATE_DONE )
  {
    v8 = 1;
    v9 = UFG::UIScreenManagerBase::getTopScreen(UFG::UIScreenManager::s_instance) == 0i64;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis
      || (v10 = 0, !UFG::UIHKScreenGlobalOverlay::mThis->m_skookum_dialog_active) )
    {
      v10 = 1;
    }
    v11 = v10 & v9;
    Instance = NISManager::GetInstance();
    if ( Instance && Instance->mState )
      v8 = 0;
    if ( ((UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_HIDDEN) & (unsigned __int8)v8 & (UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") == 0i64) & v11) != 0 )
    {
      if ( msgId == UI_HASH_BUTTON_START_PRESSED_30 )
      {
        UFG::UI::PauseGame("PauseMenu");
        this->mState = STATE_DONE;
        return 1;
      }
      if ( msgId == UI_HASH_BUTTON_SELECT_PRESSED_30 && UFG::gEnableWorldMapAndPDA && !UFG::UI::InGameIntroChapter() )
      {
        if ( UFG::UI::PauseGame("WorldMap") )
          UFG::UIHKScreenHud::Pop();
      }
      return 1;
    }
  }
  else
  {
    UFG::UIHKSniperWidget::HandleMessage(&this->SniperWidget, this, msgId);
    if ( this->RadioStationWidget.mState == STATE_TEXT_INBOX && msgId == UI_HASH_RADIO_OUTRO_COMPLETE_20 )
      this->RadioStationWidget.mState = STATE_IDLE;
    UFG::UIHKSocialActionWidget::HandleMessage(&UFG::UIHKSocialActionManager::SocialAction, this, msgId, msg);
    UFG::UIHKMissionRewardsWidget::HandleMessage(UFG::UIHKScreenHud::MissionRewards, this, msgId, msg);
    v13 = UFG::UIHKScreenHud::RegionIndicator;
    if ( msgId == UI_HASH_REGION_CHANGE_20 )
    {
      vfptr = (unsigned int)msg[1].vfptr;
      v15 = UFG::UIHKScreenHud::RegionIndicator->mZone == vfptr;
      UFG::UIHKScreenHud::RegionIndicator->mZone = vfptr;
      v13->mChanged |= !v15;
    }
    if ( msgId == UI_HASH_REGION_SHOW_20 )
      *(_WORD *)&v13->mChanged = 257;
    UFG::UIHKObjectiveFlasherWidget::HandleMessage(&this->ObjectiveFlasher, this, msgId, msg);
    if ( msgId == UI_HASH_RACEHUD_LOADED_20 )
    {
      UFG::UIHKScreenHud::RacePosition->mChanged = 1;
      UFG::UIHKScreenHud::RacePercentage->mChanged = 1;
    }
    v16 = UFG::UIHKScreenHud::CombatMeter;
    if ( msgId == UI_HASH_COMBAT_METER_INTRO_20 )
    {
      UFG::UIHKScreenHud::CombatMeter->mChanged = 1;
      v16->mState = STATE_TEXT_INBOX;
    }
    else if ( msgId == UI_HASH_COMBAT_METER_OUTRO_20 )
    {
      UFG::UIHKScreenHud::CombatMeter->mState = STATE_IDLE;
    }
    UFG::UIHKScreenHud::HintText->vfptr->HandleMessage(UFG::UIHKScreenHud::HintText, this, msgId, msg);
    if ( msgId == UI_HASH_GAME_UNLOADING_30 )
      UFG::UIHKGameplayHelpWidget::ClearAll(UFG::UIHKScreenHud::GameplayHelp);
    this->PDA->vfptr->handleMessage(this->PDA, this, msgId, msg);
    UFG::UIScreen::handleMessage(this, msgId, msg);
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
  bool m_shouldRender; // si
  UFG::UIScreen *Overlay; // rax
  char v4; // di
  UFG::UIScreenRenderable *mRenderable; // rax
  char v6; // bp

  if ( cmd )
  {
    m_shouldRender = 0;
    Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "Hud");
    v4 = 0;
    if ( Overlay && (mRenderable = Overlay->mRenderable) != 0i64 && (m_shouldRender = mRenderable->m_shouldRender)
      || (v6 = 1, (unsigned int)UFG::qStringCompare(cmd->command.mData, "hideFace", -1)) )
    {
      v6 = 0;
    }
    if ( !m_shouldRender && !(unsigned int)UFG::qStringCompare(cmd->command.mData, "Cops_PingMinimap", -1) )
      v4 = 1;
    if ( (unsigned __int8)v6 | (unsigned __int8)v4 )
      cmd->vfptr->__vecDelDtor(cmd, 1i64);
    else
      UFG::UIScreenInvokeQueue::Add(UFG::UIHKScreenHud::mScreenInvokeQueue, cmd);
  }
}

// File Line: 633
// RVA: 0x5F4290
void UFG::UIHKScreenHud::Pop(void)
{
  UFG::UIScreenRenderable *mRenderable; // rcx
  UFG::UIScreenTextureManager *v1; // rax
  UFG::UIScreenTextureManager *v2; // rax

  if ( UFG::UIHKScreenHud::mInstance )
  {
    mRenderable = UFG::UIHKScreenHud::mInstance->mRenderable;
    UFG::UIHKScreenHud::mInstance->mState = STATE_DONE;
    if ( mRenderable )
      mRenderable->m_shouldRender = 0;
  }
  UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, "Hud");
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
    (UFG::qReflectInventoryBase *)UFG::UIHKScreenHud::HandleTutorialHudTexturePackLoaded,
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
  signed __int16 m_Flags; // cx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v5; // cx
  UFG::SimComponent *v6; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int v8; // eax
  unsigned int MostUsedIndex; // eax
  bool v10; // dl
  UFG::ePDAStateEnum state; // ecx
  UFG::UIHK_PDAWidget *PDA; // r8
  UFG::ePDAStateEnum mState; // r8d
  UFG::UIHK_PDAWidget *v14; // r8
  char v15; // al
  int v16; // ecx

  v1 = LocalPlayer;
  if ( LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = LocalPlayer->m_Components.p[44].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              LocalPlayer,
                              UFG::CharacterOccupantComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::CharacterOccupantComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    v5 = v1->m_Flags;
    if ( (v5 & 0x4000) != 0 )
    {
      v6 = v1->m_Components.p[7].m_pComponent;
    }
    else if ( v5 >= 0 )
    {
      if ( (v5 & 0x2000) != 0 )
      {
        v6 = v1->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (v5 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::ActionTreeComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v1, UFG::ActionTreeComponent::_TypeUID);
        v6 = ComponentOfType;
      }
    }
    else
    {
      v6 = v1->m_Components.p[7].m_pComponent;
    }
    v8 = _S12_11;
    if ( (_S12_11 & 1) == 0 )
    {
      _S12_11 |= 1u;
      sActionHijackUID.mUID = UFG::qStringHashUpper32("ActionHijack", -1);
      v8 = _S12_11;
    }
    if ( (v8 & 2) != 0 )
    {
      MostUsedIndex = sMostUsedIndex_ActionHijack;
    }
    else
    {
      _S12_11 = v8 | 2;
      MostUsedIndex = GetMostUsedIndex(sActionHijackUID.mUID);
      sMostUsedIndex_ActionHijack = MostUsedIndex;
    }
    v10 = ActionController::IsPlaying((ActionController *)&v6[3], &sActionHijackUID, MostUsedIndex, 1)
       || m_pComponent && ((LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) - 9) & 0xFFFFFFFB) != 0;
    state = UFG::UIHKScreenHud::PDACache.state;
    if ( UFG::UIHKScreenHud::mInstance && (PDA = UFG::UIHKScreenHud::mInstance->PDA) != 0i64 )
      mState = PDA->mState;
    else
      mState = UFG::UIHKScreenHud::PDACache.state;
    if ( mState == STATE_IDLE )
      goto LABEL_41;
    if ( UFG::UIHKScreenHud::mInstance )
    {
      v14 = UFG::UIHKScreenHud::mInstance->PDA;
      if ( v14 )
        state = v14->mState;
    }
    if ( state == STATE_WAIT_TO_WRITE_TEXT )
LABEL_41:
      v15 = 0;
    else
      v15 = 1;
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
  Scaleform::GFx::Movie *pObject; // rdi
  long double v3; // xmm6_8
  bool v4; // cl
  bool v5; // bl
  Scaleform::GFx::Value value; // [rsp+38h] [rbp-48h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Undefined;
    if ( UFG::UIHKScreenHud::mIconManager )
      UFG::UIMapBlipManager::UpdatePlayerArrow(
        UFG::UIHKScreenHud::mIconManager,
        (int)UFG::UITiledMapWidget::gMinimapCenter.x,
        (int)UFG::UITiledMapWidget::gMinimapCenter.y,
        this->Minimap.m_mapGeo.playerRot,
        0);
    if ( (unsigned int)(this->mState - 1) <= 1 )
    {
      v3 = (float)(this->mMinimapAlpha * 100.0);
      value.Type = VT_Number;
      value.mValue.NValue = v3;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_minimapBorder._alpha", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(pObject, "mcOuterRing._alpha", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(pObject, "mcHeatMeter._alpha", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_MinimapPulse._alpha", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_HealthBar._alpha", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_CombatTarget._alpha", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_ObjectiveFlasherTarget._alpha", &value, 1i64);
    }
    if ( this->mMinimapVisibleChanged )
    {
      this->mMinimapVisibleChanged = 0;
      v4 = UFG::UIHKTweakables::RenderMinimap;
      this->HeatLevel.mVisibleChanged |= this->HeatLevel.mVisible != UFG::UIHKTweakables::RenderMinimap;
      this->HeatLevel.mVisible = v4;
      v5 = UFG::UIHKTweakables::RenderMinimap;
      if ( (value.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
          value.pObjectInterface,
          &value,
          value.mValue);
        value.pObjectInterface = 0i64;
      }
      value.Type = VT_Boolean;
      value.mValue.BValue = v5;
      Scaleform::GFx::Movie::SetVariable(pObject, "mc_minimapBorder._visible", &value, 1i64);
      Scaleform::GFx::Movie::SetVariable(pObject, "mcOuterRing._visible", &value, 1i64);
    }
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
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
  v1 = !UFG::UIHKScreenHud::RaceTimer->mVisible;
  UFG::UIHKScreenHud::RaceTimer->mVisible = 0;
  v0->mVisibilityChanged |= !v1;
  v2 = UFG::UIHKScreenHud::RacePosition;
  v1 = !UFG::UIHKScreenHud::RacePosition->mVisible;
  UFG::UIHKScreenHud::RacePosition->mVisible = 0;
  v2->mChanged |= !v1;
  v3 = UFG::UIHKScreenHud::RacePercentage;
  v1 = !UFG::UIHKScreenHud::RacePercentage->mVisible;
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
    v1->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable;
    UFG::qString::qString(&v1->command, &customCaption);
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
  __int64 v0; // rdi
  UFG::UIHKInfoPopupWidget::eState mState; // ecx
  UFG::UIHKHintText *v2; // rcx
  bool m_isShowingOnlineDisconnect; // zf
  UFG::UIHKHintText::eState m_eState; // eax
  UFG::UIHKActionButtonWidget *v5; // rcx
  UFG::UIHKMissionProgressWidget *v6; // rsi
  UFG::qString *p_Caption; // rbx
  UFG::qString *v8; // rbx
  __int64 v9; // rdi
  UFG::UIHKObjectiveFlasherWidget::eState v10; // eax
  int v11; // eax
  UFG::UIHKRaceTimerWidget *v12; // rcx
  UFG::UIHKRacePositionWidget *v13; // rcx
  UFG::UIHKRacePercentageWidget *v14; // rcx
  UFG::UIHKScreenGlobalOverlay *v15; // rax
  UFG::UIHKTextOverlay *p_TextOverlay; // rbx
  UFG::UISubtitleMessage *mCurrent1; // rdx
  UFG::UIHKTextOverlay *mParent; // rcx
  UFG::UISubtitleMessage *mCurrent2; // rdx
  UFG::UIHKTextOverlay *v20; // rcx

  UFG::UITiledMapGPS::Initialize(UFG::UIHKScreenHud::GPS);
  v0 = 4i64;
  mState = UFG::UIHKScreenHud::InfoPopup->mState;
  if ( mState && mState != STATE_OUTGOING_CALL )
    UFG::UIHKScreenHud::InfoPopup->mState = STATE_INCOMING_CALL;
  v2 = UFG::UIHKScreenHud::HintText;
  m_isShowingOnlineDisconnect = UFG::UIHKScreenHud::HintText->m_isShowingOnlineDisconnect;
  UFG::UIHKScreenHud::HintText->m_bShowMsg = 0;
  v2->m_bUseTimer = 0;
  v2->m_bRepeatMsg = 0;
  if ( m_isShowingOnlineDisconnect )
    v2->m_isShowingOnlineDisconnect = 0;
  m_eState = v2->m_eState;
  if ( m_eState == STATE_TEXT_INBOX )
  {
    v2->m_eState = STATE_INCOMING_CALL;
  }
  else if ( ((m_eState - 2) & 0xFFFFFFFB) == 0 )
  {
    v2->m_eState = STATE_IDLE;
  }
  v5 = UFG::UIHKScreenHud::ActionButton;
  m_isShowingOnlineDisconnect = !UFG::UIHKScreenHud::ActionButton->mVisible;
  UFG::UIHKScreenHud::ActionButton->mVisible = 0;
  v5->mChanged |= !m_isShowingOnlineDisconnect;
  v6 = UFG::UIHKScreenHud::MissionProgress;
  p_Caption = &UFG::UIHKScreenHud::MissionProgress->mData[0].Caption;
  do
  {
    LOBYTE(p_Caption[-1].mStringHash32) = 1;
    p_Caption[-1].mStringHashUpper32 = 0;
    UFG::qString::Set(p_Caption, &customCaption);
    p_Caption = (UFG::qString *)((char *)p_Caption + 48);
    --v0;
  }
  while ( v0 );
  v6->mChanged = 1;
  v8 = &UFG::UIHKScreenHud::XPFlasher->mData[0].Caption;
  v9 = 3i64;
  do
  {
    v8[-1].mData = 0i64;
    UFG::qString::Set(v8, &customCaption);
    LOBYTE(v8[1].mPrev) = 0;
    v8 = (UFG::qString *)((char *)v8 + 64);
    --v9;
  }
  while ( v9 );
  UFG::UIHKGameplayHelpWidget::ClearAll(UFG::UIHKScreenHud::GameplayHelp);
  UFG::UIHKBuffWidget::Clear();
  v10 = UFG::UIHKObjectiveFlasherWidget::mState;
  if ( (UFG::UIHKObjectiveFlasherWidget::mState & 0xFFFFFFFB) != 0 )
    v10 = STATE_TEXT_INBOX;
  UFG::UIHKObjectiveFlasherWidget::mState = v10;
  UFG::UIHK_PDATextInboxWidget::ClearMessages();
  if ( byte_142431A14 && UFG::UIHK_PDAWidget::mInputLocked )
  {
    UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
    v11 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v11 = --UFG::UIHKGameplayHelpWidget::mLocked;
    if ( v11 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    --UFG::UIHK_PDAWidget::mInputLocked;
  }
  v12 = UFG::UIHKScreenHud::RaceTimer;
  UFG::UIHKScreenHud::PDACache.state = STATE_IDLE;
  byte_142431A14 = 0;
  dword_142431A18 = 0;
  m_isShowingOnlineDisconnect = !UFG::UIHKScreenHud::RaceTimer->mVisible;
  UFG::UIHKScreenHud::RaceTimer->mVisible = 0;
  v12->mVisibilityChanged |= !m_isShowingOnlineDisconnect;
  v13 = UFG::UIHKScreenHud::RacePosition;
  m_isShowingOnlineDisconnect = !UFG::UIHKScreenHud::RacePosition->mVisible;
  UFG::UIHKScreenHud::RacePosition->mVisible = 0;
  v13->mChanged |= !m_isShowingOnlineDisconnect;
  v14 = UFG::UIHKScreenHud::RacePercentage;
  m_isShowingOnlineDisconnect = !UFG::UIHKScreenHud::RacePercentage->mVisible;
  UFG::UIHKScreenHud::RacePercentage->mVisible = 0;
  v14->mChanged |= !m_isShowingOnlineDisconnect;
  v15 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_TextOverlay = &UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay;
    if ( UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-144i64 )
    {
      UFG::qList<UFG::UISubtitleMessage,UFG::UISubtitleMessage,1,0>::DeleteNodes(&UFG::UIHKScreenGlobalOverlay::mThis->TextOverlay.mSubtitleQueue.mQueue);
      mCurrent1 = p_TextOverlay->mSubtitleQueue.mCurrent1;
      if ( mCurrent1 )
      {
        mCurrent1->state = STATE_EXECUTING;
        mParent = p_TextOverlay->mSubtitleQueue.mParent;
        if ( mParent )
          UFG::UIHKTextOverlay::OnHideNow(mParent, mCurrent1, 1);
      }
      mCurrent2 = p_TextOverlay->mSubtitleQueue.mCurrent2;
      if ( mCurrent2 )
      {
        mCurrent2->state = STATE_EXECUTING;
        v20 = p_TextOverlay->mSubtitleQueue.mParent;
        if ( v20 )
          UFG::UIHKTextOverlay::OnHideNow(v20, mCurrent2, 2);
      }
      if ( !p_TextOverlay->mSubtitlesVisible )
      {
        *(_WORD *)&p_TextOverlay->mChanged = 257;
        p_TextOverlay->mSubtitleQueue.mPauseQueue = 0;
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

  if ( byte_142431A14 && UFG::UIHK_PDAWidget::mInputLocked )
  {
    UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
    v0 = UFG::UIHKGameplayHelpWidget::mLocked;
    if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
      v0 = --UFG::UIHKGameplayHelpWidget::mLocked;
    if ( v0 < 1 )
      UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
    --UFG::UIHK_PDAWidget::mInputLocked;
  }
  UFG::UIHKScreenHud::PDACache.state = STATE_IDLE;
  byte_142431A14 = 0;
  dword_142431A18 = 0;
}

// File Line: 908
// RVA: 0x60C670
void __fastcall UFG::UIHKScreenHud::SetVisible(bool value)
{
  UFG::UIScreen *Overlay; // rax

  if ( UFG::UIHKScreenHud::mShouldRender != value )
  {
    UFG::UIHKScreenHud::mShouldRender = value;
    Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "Hud");
    if ( Overlay )
      Overlay->mRenderable->m_shouldRender = UFG::UIHKScreenHud::mShouldRender;
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
  UFG::UIHK_PDAWidget *PDA; // rdx

  if ( UFG::UIHKScreenHud::mInstance )
  {
    PDA = UFG::UIHKScreenHud::mInstance->PDA;
    if ( PDA )
      UFG::UIHKScreenHud::PDACache.state = PDA->mState;
  }
  UFG::qString::Set(&stru_142431A20, this->PDA->IncomingCall.mCallerName.mData);
  unk_142431A48 = this->PDA->mOutgoingCall;
  unk_142431A49 = this->PDA->IncomingCall.mState == STATE_INCOMING_CALL;
  unk_142431A4A = this->PDA->mVoiceMail;
  dword_142431A18 = this->PDA->RootMenu.mSelectedIndex;
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
  UFG::qSymbol widget; // [rsp+40h] [rbp+10h] BYREF
  UFG::qSymbol *p_widget; // [rsp+48h] [rbp+18h]

  p_widget = &widget;
  widget.mUID = UIHudWidgetID_HUD_MINIMAP_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
  p_widget = &widget;
  widget.mUID = UIHudWidgetID_HUD_PDA_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
  p_widget = &widget;
  widget.mUID = UIHudWidgetID_HUD_HEALTH_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
  p_widget = &widget;
  widget.mUID = UIHudWidgetID_HUD_COMBAT_METER_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
  p_widget = &widget;
  widget.mUID = UIHudWidgetID_HUD_WEAPON_AMMO_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
  p_widget = &widget;
  widget.mUID = UIHudWidgetID_HUD_REGION_INDICATOR_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
  p_widget = &widget;
  widget.mUID = UIHudWidgetID_HUD_GAMEPLAY_HELP_13.mUID;
  UFG::UIHKScreenHud::SetWidgetVisible((__int64)&widget, 1);
}

// File Line: 998
// RVA: 0x60C720
void __fastcall UFG::UIHKScreenHud::SetWidgetVisible(int *widget, bool visible)
{
  int v2; // eax
  UFG::UIHKScreenHud *v3; // r8
  bool v4; // zf
  UFG::UIHKRegionIndicatorWidget *v5; // rcx
  UFG::UIHKGameplayHelpWidget *v6; // rcx

  v2 = *widget;
  v3 = UFG::UIHKScreenHud::mInstance;
  if ( *widget == UIHudWidgetID_HUD_MINIMAP_13.mUID )
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
void __fastcall UFG::UIHKScreenHud::SetWidgetHighlight(UFG::UIHKScreenHud *this, int *widget, bool highlight)
{
  int v3; // eax

  v3 = *widget;
  if ( *widget == UIHudWidgetID_HUD_MINIMAP_13.mUID )
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
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-68h] BYREF
  char v4[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v5; // [rsp+80h] [rbp-28h]
  int v6; // [rsp+88h] [rbp-20h]
  const char *v7; // [rsp+90h] [rbp-18h]

  if ( highlight )
  {
    pObject = this->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      ptr.mValue.pString = "mc_Minimap";
      if ( (v6 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v5 + 16i64))(v5, v4, v7);
        v5 = 0i64;
      }
      v6 = 6;
      v7 = "mc_HealthBar_highlight";
      Scaleform::GFx::Movie::Invoke(pObject, "UIHighlight_Init", 0i64, &ptr, 2u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 1110
// RVA: 0x6081F0
void __fastcall UFG::UIHKScreenHud::SetSocialAwardMedal(
        UFG::UIHKScreenHud *this,
        int medal,
        const char *socialaward,
        const char *myname,
        const char *myscore)
{
  __int64 v7; // r14
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // rsi
  UFG::GameStatTracker *v11; // rax
  UFG::UIHK_PDAWidget *PDA; // rcx
  UFG::ePDAStateEnum state; // eax
  unsigned int v14; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v16; // rdi
  char *mData; // rdi
  __int64 v18; // rdi
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-D0h] BYREF
  char v20[16]; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v21; // [rsp+70h] [rbp-90h]
  int v22; // [rsp+78h] [rbp-88h]
  const char *v23; // [rsp+80h] [rbp-80h]
  char v24[16]; // [rsp+90h] [rbp-70h] BYREF
  __int64 v25; // [rsp+A0h] [rbp-60h]
  int v26; // [rsp+A8h] [rbp-58h]
  char *v27; // [rsp+B0h] [rbp-50h]
  char v28[16]; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v29; // [rsp+D0h] [rbp-30h]
  int v30; // [rsp+D8h] [rbp-28h]
  double v31; // [rsp+E0h] [rbp-20h]
  char v32[16]; // [rsp+F0h] [rbp-10h] BYREF
  __int64 v33; // [rsp+100h] [rbp+0h]
  int v34; // [rsp+108h] [rbp+8h]
  __int64 v35; // [rsp+110h] [rbp+10h]
  __int64 v36[5]; // [rsp+120h] [rbp+20h]
  UFG::qString v37; // [rsp+148h] [rbp+48h] BYREF

  v36[4] = -2i64;
  v7 = medal;
  mRenderable = this->mRenderable;
  if ( mRenderable )
  {
    pObject = mRenderable->m_movie.pObject;
    if ( pObject )
    {
      v11 = UFG::GameStatTracker::Instance();
      if ( !UFG::GameStatTracker::GetStat(v11, OptionsDisableSocial) )
      {
        if ( !this->PDA
          || (!UFG::UIHKScreenHud::mInstance || (PDA = UFG::UIHKScreenHud::mInstance->PDA) == 0i64
            ? (state = UFG::UIHKScreenHud::PDACache.state)
            : (state = PDA->mState),
              state == STATE_IDLE) )
        {
          v14 = UFG::qStringHashUpper32("LEADERBOARD_YOUR_SCORE", -1);
          m_translator = UFG::UIScreenManager::s_instance->m_translator;
          if ( !m_translator || (v16 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v14)) == 0i64 )
            v16 = "LEADERBOARD_YOUR_SCORE";
          UFG::qString::qString(&v37);
          UFG::qString::Format(&v37, "%s: %s", v16, myscore);
          v36[0] = (__int64)&customCaption;
          v36[1] = (__int64)"$HUD_SOCIAL_AWARDBRONZE";
          v36[2] = (__int64)"$HUD_SOCIAL_AWARDSILVER";
          v36[3] = (__int64)"$HUD_SOCIAL_AWARDGOLD";
          `eh vector constructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
          if ( (ptr.Type & 0x40) != 0 )
          {
            (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
              ptr.pObjectInterface,
              &ptr,
              ptr.mValue);
            ptr.pObjectInterface = 0i64;
          }
          ptr.Type = VT_String;
          ptr.mValue.pString = socialaward;
          if ( (v22 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v21 + 16i64))(v21, v20, v23);
            v21 = 0i64;
          }
          v22 = 6;
          v23 = myname;
          mData = v37.mData;
          if ( (v26 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v25 + 16i64))(v25, v24, v27);
            v25 = 0i64;
          }
          v26 = 6;
          v27 = mData;
          if ( (v30 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v29 + 16i64))(
              v29,
              v28,
              COERCE_DOUBLE(*(_QWORD *)&v31));
            v29 = 0i64;
          }
          v30 = 5;
          v31 = (double)((int)v7 - 1);
          v18 = v36[v7];
          if ( (v34 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v33 + 16i64))(v33, v32, v35);
            v33 = 0i64;
          }
          v34 = 6;
          v35 = v18;
          Scaleform::GFx::Movie::Invoke(pObject, "StatGame_SetStatAward", 0i64, &ptr, 5u);
          this->mStatInfoTimer = 5.0;
          this->mStatSocialAwardActive = 1;
          `eh vector destructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
          UFG::qString::~qString(&v37);
        }
      }
    }
  }
}

// File Line: 1141
// RVA: 0x608960
void __fastcall UFG::UIHKScreenHud::SetStatGameInfo(
        UFG::UIHKScreenHud *this,
        const char *statInfo,
        const char *myname,
        const char *myscore,
        const char *leader,
        const char *leaderscore)
{
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // r14
  UFG::GameStatTracker *v12; // rax
  UFG::UIHK_PDAWidget *PDA; // rcx
  UFG::ePDAStateEnum state; // eax
  const char *v15; // r12
  const char *v16; // rbx
  const char *v17; // rdi
  char *mData; // rbx
  char *v19; // rbx
  unsigned int v20; // eax
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-D0h] BYREF
  char v22[16]; // [rsp+60h] [rbp-A0h] BYREF
  __int64 v23; // [rsp+70h] [rbp-90h]
  int v24; // [rsp+78h] [rbp-88h]
  const char *v25; // [rsp+80h] [rbp-80h]
  char v26[16]; // [rsp+90h] [rbp-70h] BYREF
  __int64 v27; // [rsp+A0h] [rbp-60h]
  int v28; // [rsp+A8h] [rbp-58h]
  char *v29; // [rsp+B0h] [rbp-50h]
  char v30[16]; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v31; // [rsp+D0h] [rbp-30h]
  int v32; // [rsp+D8h] [rbp-28h]
  const char *v33; // [rsp+E0h] [rbp-20h]
  char v34[16]; // [rsp+F0h] [rbp-10h] BYREF
  __int64 v35; // [rsp+100h] [rbp+0h]
  int v36; // [rsp+108h] [rbp+8h]
  char *v37; // [rsp+110h] [rbp+10h]
  __int64 v38; // [rsp+120h] [rbp+20h]
  UFG::qString v39; // [rsp+128h] [rbp+28h] BYREF
  UFG::qString v40; // [rsp+150h] [rbp+50h] BYREF

  v38 = -2i64;
  mRenderable = this->mRenderable;
  if ( mRenderable )
  {
    pObject = mRenderable->m_movie.pObject;
    if ( pObject )
    {
      v12 = UFG::GameStatTracker::Instance();
      if ( !UFG::GameStatTracker::GetStat(v12, OptionsDisableSocial) )
      {
        if ( !this->PDA
          || (!UFG::UIHKScreenHud::mInstance || (PDA = UFG::UIHKScreenHud::mInstance->PDA) == 0i64
            ? (state = UFG::UIHKScreenHud::PDACache.state)
            : (state = PDA->mState),
              state == STATE_IDLE) )
        {
          if ( this->mStatInfoTimer <= 0.0 )
          {
            v15 = UFG::UI::LocalizeText(statInfo);
            v16 = UFG::UI::LocalizeText("LEADERBOARD_YOUR_SCORE");
            v17 = UFG::UI::LocalizeText("LEADERBOARD_SCORE_TO_BEAT");
            UFG::qString::qString(&v40);
            UFG::qString::qString(&v39);
            UFG::qString::Format(&v40, "%s: %s", v16, myscore);
            UFG::qString::Format(&v39, "%s: %s", v17, leaderscore);
            `eh vector constructor iterator(
              &ptr,
              0x30ui64,
              5,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
            if ( (ptr.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
                ptr.pObjectInterface,
                &ptr,
                ptr.mValue);
              ptr.pObjectInterface = 0i64;
            }
            ptr.Type = VT_String;
            ptr.mValue.pString = v15;
            if ( (v24 & 0x40) != 0 )
            {
              (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v23 + 16i64))(v23, v22, v25);
              v23 = 0i64;
            }
            v24 = 6;
            v25 = myname;
            mData = v40.mData;
            if ( (v28 & 0x40) != 0 )
            {
              (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v27 + 16i64))(v27, v26, v29);
              v27 = 0i64;
            }
            v28 = 6;
            v29 = mData;
            if ( (v32 & 0x40) != 0 )
            {
              (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v31 + 16i64))(v31, v30, v33);
              v31 = 0i64;
            }
            v32 = 6;
            v33 = leader;
            v19 = v39.mData;
            if ( (v36 & 0x40) != 0 )
            {
              (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v35 + 16i64))(v35, v34, v37);
              v35 = 0i64;
            }
            v36 = 6;
            v37 = v19;
            Scaleform::GFx::Movie::Invoke(pObject, "StatGame_SetLocalInfo", 0i64, &ptr, 5u);
            if ( !this->mStatGameInfoActive )
            {
              v20 = UFG::TiDo::CalcWwiseUid("Play_ui_stat_game");
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v20, 0i64, 0, 0i64);
              this->mStatGameInfoActive = 1;
            }
            `eh vector destructor iterator(
              &ptr,
              0x30ui64,
              5,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
            UFG::qString::~qString(&v39);
            UFG::qString::~qString(&v40);
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
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::GameStatTracker *v4; // rax
  UFG::UIHK_PDAWidget *PDA; // rcx
  UFG::ePDAStateEnum state; // eax

  mRenderable = this->mRenderable;
  if ( mRenderable )
  {
    pObject = mRenderable->m_movie.pObject;
    if ( pObject )
    {
      v4 = UFG::GameStatTracker::Instance();
      if ( !UFG::GameStatTracker::GetStat(v4, OptionsDisableSocial) )
      {
        if ( !this->PDA
          || (!UFG::UIHKScreenHud::mInstance || (PDA = UFG::UIHKScreenHud::mInstance->PDA) == 0i64
            ? (state = UFG::UIHKScreenHud::PDACache.state)
            : (state = PDA->mState),
              state == STATE_IDLE) )
        {
          if ( this->mStatInfoTimer <= 0.0 )
            Scaleform::GFx::Movie::Invoke(pObject, "StatGame_ShowSettingHighRecord", 0i64, 0i64, 0);
        }
      }
    }
  }
}

// File Line: 1205
// RVA: 0x6084C0
void __fastcall UFG::UIHKScreenHud::SetStatGameBeatHim(
        UFG::UIHKScreenHud *this,
        const char *hisname,
        const char *score)
{
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::GameStatTracker *v8; // rax
  UFG::UIHK_PDAWidget *PDA; // rcx
  UFG::ePDAStateEnum state; // eax
  const char *v11; // rbx
  char *mData; // rbx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-98h] BYREF
  char v14[16]; // [rsp+60h] [rbp-68h] BYREF
  __int64 v15; // [rsp+70h] [rbp-58h]
  int v16; // [rsp+78h] [rbp-50h]
  const char *v17; // [rsp+80h] [rbp-48h]
  __int64 v18; // [rsp+90h] [rbp-38h]
  UFG::qString v19; // [rsp+98h] [rbp-30h] BYREF

  v18 = -2i64;
  mRenderable = this->mRenderable;
  if ( mRenderable )
  {
    pObject = mRenderable->m_movie.pObject;
    if ( pObject )
    {
      v8 = UFG::GameStatTracker::Instance();
      if ( !UFG::GameStatTracker::GetStat(v8, OptionsDisableSocial) )
      {
        if ( !this->PDA
          || (!UFG::UIHKScreenHud::mInstance || (PDA = UFG::UIHKScreenHud::mInstance->PDA) == 0i64
            ? (state = UFG::UIHKScreenHud::PDACache.state)
            : (state = PDA->mState),
              state == STATE_IDLE) )
        {
          if ( !this->mStatSocialAwardActive )
          {
            v11 = UFG::UI::LocalizeText("LEADERBOARD_YOU_BEAT");
            UFG::qString::qString(&v19);
            UFG::qString::Format(&v19, "%s: %s", v11, hisname);
            `eh vector constructor iterator(
              &ptr,
              0x30ui64,
              2,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
            mData = v19.mData;
            if ( (ptr.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
                ptr.pObjectInterface,
                &ptr,
                ptr.mValue);
              ptr.pObjectInterface = 0i64;
            }
            ptr.Type = VT_String;
            ptr.mValue.pString = mData;
            if ( (v16 & 0x40) != 0 )
            {
              (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v15 + 16i64))(v15, v14, v17);
              v15 = 0i64;
            }
            v16 = 6;
            v17 = score;
            Scaleform::GFx::Movie::Invoke(pObject, "StatGame_SetYouBeatHimInfo", 0i64, &ptr, 2u);
            `eh vector destructor iterator(
              &ptr,
              0x30ui64,
              2,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
            UFG::qString::~qString(&v19);
          }
        }
      }
    }
  }
}

// File Line: 1234
// RVA: 0x6086A0
void __fastcall UFG::UIHKScreenHud::SetStatGameFinalScore(
        UFG::UIHKScreenHud *this,
        int popup_id,
        const char *statDescr,
        unsigned int rank)
{
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // r14
  UFG::GameStatTracker *v10; // rax
  UFG::UIHK_PDAWidget *PDA; // rcx
  UFG::ePDAStateEnum state; // eax
  const char *v13; // r13
  const char *v14; // rbx
  const char *v15; // rdi
  const char *v16; // rdx
  char *mData; // rbx
  char *v18; // rbx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-A8h] BYREF
  char v20[8]; // [rsp+60h] [rbp-78h] BYREF
  char v21[8]; // [rsp+68h] [rbp-70h] BYREF
  __int64 v22; // [rsp+70h] [rbp-68h]
  __int64 v23; // [rsp+78h] [rbp-60h]
  int v24; // [rsp+80h] [rbp-58h]
  char *v25; // [rsp+88h] [rbp-50h]
  char v26[16]; // [rsp+98h] [rbp-40h] BYREF
  __int64 v27; // [rsp+A8h] [rbp-30h]
  int v28; // [rsp+B0h] [rbp-28h]
  char *v29; // [rsp+B8h] [rbp-20h]
  UFG::qString v30; // [rsp+C8h] [rbp-10h] BYREF
  __int64 v31; // [rsp+F0h] [rbp+18h]
  UFG::qString v32; // [rsp+F8h] [rbp+20h] BYREF
  const char *retaddr; // [rsp+178h] [rbp+A0h]

  v31 = -2i64;
  mRenderable = this->mRenderable;
  if ( mRenderable )
  {
    pObject = mRenderable->m_movie.pObject;
    if ( pObject )
    {
      v10 = UFG::GameStatTracker::Instance();
      if ( !UFG::GameStatTracker::GetStat(v10, OptionsDisableSocial) )
      {
        if ( !this->PDA
          || (!UFG::UIHKScreenHud::mInstance || (PDA = UFG::UIHKScreenHud::mInstance->PDA) == 0i64
            ? (state = UFG::UIHKScreenHud::PDACache.state)
            : (state = PDA->mState),
              state == STATE_IDLE) )
        {
          if ( !this->mStatSocialAwardActive )
          {
            `eh vector constructor iterator(
              &ptr,
              0x30ui64,
              4,
              (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
            v13 = UFG::UI::LocalizeText(statDescr);
            v14 = UFG::UI::LocalizeText("$LEADERBOARD_YOUR_SCORE");
            v15 = UFG::UI::LocalizeText("$LEADERBOARD_YOUR_RANK");
            UFG::qString::qString(&v32);
            UFG::qString::qString(&v30);
            UFG::qString::Format(&v32, "%s: %s", v14, retaddr);
            UFG::qString::Format(&v30, v15, rank);
            if ( !UFG::OSuiteManager::Instance()->m_bConnected )
            {
              if ( rank == 1 )
                v16 = UFG::UI::LocalizeText("$MINIGAME_KARAOKE_HIGH_SCORE");
              else
                v16 = &customCaption;
              UFG::qString::Set(&v30, v16);
            }
            if ( (ptr.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
                ptr.pObjectInterface,
                &ptr,
                ptr.mValue);
              ptr.pObjectInterface = 0i64;
            }
            ptr.Type = VT_Number;
            ptr.mValue.NValue = (double)popup_id;
            if ( (v23 & 0x40) != 0 )
            {
              (*(void (__fastcall **)(__int64, char *, unsigned __int64))(*(_QWORD *)v22 + 16i64))(
                v22,
                v20,
                ptr.DataAux);
              v22 = 0i64;
            }
            LODWORD(v23) = 6;
            ptr.DataAux = (unsigned __int64)v13;
            mData = v30.mData;
            if ( (v24 & 0x40) != 0 )
            {
              (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v23 + 16i64))(v23, v21, v25);
              v23 = 0i64;
            }
            v24 = 6;
            v25 = mData;
            v18 = v32.mData;
            if ( (v28 & 0x40) != 0 )
            {
              (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v27 + 16i64))(v27, v26, v29);
              v27 = 0i64;
            }
            v28 = 6;
            v29 = v18;
            Scaleform::GFx::Movie::Invoke(pObject, "StatGame_SetFinalScore", 0i64, &ptr, 4u);
            this->mStatInfoTimer = 5.0;
            UFG::qString::~qString(&v30);
            UFG::qString::~qString(&v32);
            `eh vector destructor iterator(
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
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // rcx

  mRenderable = this->mRenderable;
  if ( mRenderable )
  {
    pObject = mRenderable->m_movie.pObject;
    if ( pObject )
    {
      this->mStatSocialAwardActive = 0;
      Scaleform::GFx::Movie::Invoke(pObject, "StatGame_Hide", 0i64, 0i64, 0);
      this->mStatGameInfoActive = 0;
    }
  }
}

// File Line: 1306
// RVA: 0x5F08B0
void __fastcall UFG::UIHKScreenHud::LeadUnlocked(UFG::UIHKScreenHud *this, _DWORD *assetID)
{
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v5; // rbp
  unsigned int mNumElements; // edi
  unsigned int v7; // ebx
  char *ValuePtr; // rax
  UFG::qPropertySet *v9; // rcx
  char *v10; // rax
  UFG::qString v11; // [rsp+28h] [rbp-30h] BYREF
  UFG::qSymbol result; // [rsp+60h] [rbp+8h] BYREF

  if ( this->mRenderable->m_movie.pObject )
  {
    v3 = UFG::qSymbol::create_from_string(&result, "default-unlockables-caseLeads-list");
    PropertySet = UFG::PropertySetManager::GetPropertySet(v3);
    v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)&qSymbol_List_20,
           DEPTH_RECURSE);
    UFG::qString::qString(&v11);
    if ( v5 )
    {
      mNumElements = v5->mNumElements;
      v7 = 0;
      if ( mNumElements )
      {
        while ( 1 )
        {
          ValuePtr = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v7);
          if ( ValuePtr && *(_QWORD *)ValuePtr )
            v9 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
          else
            v9 = 0i64;
          if ( v9->mName.mUID == *assetID )
            break;
          if ( ++v7 >= mNumElements )
            goto LABEL_12;
        }
        v10 = PropertyUtils::Get<char const *>(
                v9,
                (UFG::qArray<unsigned long,0> *)&qSymbol_Description_20,
                DEPTH_RECURSE);
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
  int v2; // eax
  const char *v3; // rdx
  UFG::UIScreenTextureManager *v4; // rax
  UFG::qBaseTreeRB *ScreenInfo; // rax
  UFG::qString v6; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::qString(&v6);
  v2 = UFG::qStringCompare(flowPostfix, "G", -1);
  v3 = "Data\\UI\\hud_texturepack_ghost.perm.bin";
  if ( v2 )
    v3 = "Data\\UI\\hud_texturepack.perm.bin";
  UFG::qString::Set(&v6, v3);
  UFG::UIHKScreenHud::gTexturePackFilename = v6.mData;
  v4 = UFG::UIScreenTextureManager::Instance();
  ScreenInfo = UFG::UIScreenTextureManager::GetScreenInfo(v4, "Hud");
  UFG::UIScreenTextureManager::ScreenInfo::SetTexturePack(
    (UFG::UIScreenTextureManager::ScreenInfo *)ScreenInfo,
    v6.mData);
  UFG::qString::~qString(&v6);
}

