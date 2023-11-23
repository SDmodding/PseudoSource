// File Line: 90
// RVA: 0x1567410
__int64 dynamic_initializer_for__UFG::UIHKScreenWorldMap::mScreenInvokeQueue__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenWorldMap::mScreenInvokeQueue__);
}

// File Line: 91
// RVA: 0x1567170
__int64 dynamic_initializer_for__UFG::UIHKScreenWorldMap::mIconManager__()
{
  UFG::UIMapBlipManager::UIMapBlipManager(&UFG::UIHKScreenWorldMap::mIconManager);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenWorldMap::mIconManager__);
}

// File Line: 92
// RVA: 0x1566B70
__int64 dynamic_initializer_for__UFG::UIHKScreenWorldMap::MapLines__()
{
  UFG::UIMapLinesWidget::UIMapLinesWidget(&UFG::UIHKScreenWorldMap::MapLines);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenWorldMap::MapLines__);
}

// File Line: 100
// RVA: 0x156E0F0
__int64 UFG::_dynamic_initializer_for__gWorldMapHelpbarID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("worldmap_helpbar", -1);
  gWorldMapHelpbarID = result;
  return result;
}

// File Line: 128
// RVA: 0x5C7B90
void __fastcall UFG::UIHKScreenWorldMap::UIHKScreenWorldMap(UFG::UIHKScreenWorldMap *this)
{
  UFG::UITiledMapTextureManager *v2; // rsi
  UFG::UIHKWorldMapInfoPopupWidget *p_InfoPopup; // rbx
  UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *p_mLegendItems; // rbx
  UFG::allocator::free_link *v5; // rax
  UFG::UITiledMapTextureManager *v6; // rax
  UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *i; // rdx
  UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *mPrev; // rcx
  UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *mNext; // rax

  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  v2 = 0i64;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenWorldMap::`vftable;
  *(_QWORD *)&this->mState = 0i64;
  this->mViewTypeChanged = 1;
  this->mViewTypeScrollDirection = SCROLL_NONE;
  *(_DWORD *)&this->mShouldPushHud = 1;
  *(_WORD *)&this->mIsKeyboardController = 0;
  this->mIntroTimeOut = 2.0;
  *(_QWORD *)&this->mMapFadeTime = 1056964608i64;
  *(_QWORD *)&this->mMapTileAlpha = 0i64;
  *(_QWORD *)&this->mIconAlpha = 0i64;
  *(_QWORD *)&this->mRacePathFadeTime = 1056964608i64;
  this->mRacePathAlpha = 0.0;
  *(_WORD *)&this->mUseLowResTiles = 0;
  p_InfoPopup = &this->InfoPopup;
  this->InfoPopup.mState = STATE_IDLE;
  *(_WORD *)&this->InfoPopup.mChanged = 0;
  this->InfoPopup.mCueAnimation = 0;
  UFG::qString::qString(&this->InfoPopup.mTitleText);
  UFG::qString::qString(&p_InfoPopup->mBodyText);
  UFG::UIHKWorldMapTerritoryWidget::UIHKWorldMapTerritoryWidget(&this->Territory);
  *(_QWORD *)&this->Legend.mState = 0i64;
  this->Legend.mToggleFadeOut = 0;
  this->ObjectivesWidget.mState = STATE_COMPLETE;
  *(_WORD *)&this->ObjectivesWidget.mbIsHiding = 1;
  this->PerkGoalsWidget.mState = STATE_COMPLETE;
  *(_WORD *)&this->PerkGoalsWidget.mbIsHiding = 1;
  this->TutorialPopup.HealthShrineUpgradeProgress = 1;
  *(_WORD *)&this->TutorialPopup.mChanged = 256;
  UFG::qString::qString(&this->TutorialPopup.mCaption);
  this->TutorialPopup.mType.mUID = qSymbol_Food_20.mUID;
  *(_QWORD *)&this->TutorialPopup.mPosition = 0i64;
  this->TutorialPopup.mHintReminderTimeout = 0.0;
  *(_WORD *)&this->TutorialPopup.mInfinite = 0;
  this->TutorialPopup.mState = STATE_IDLE;
  UFG::UITiledMapWidget::UITiledMapWidget(&this->mTiledMap);
  UFG::UIMapBlipManager::UIMapBlipManager(&this->mMinimapIconManagerClone);
  this->Cursor.mPos = 0i64;
  this->Cursor.mMinLimit = 0i64;
  this->Cursor.mMaxLimit = 0i64;
  this->Cursor.mEdgePush = 0i64;
  this->Cursor.mMargin = 30.0;
  this->Cursor.mIsMoving = 0;
  this->Cursor.mSelectedObjective = 0i64;
  this->Cursor.mIsOpen = 0;
  this->Cursor.mSelectedBlipColor = UFG::qColour::White;
  UFG::UITiledMapGPS::UITiledMapGPS(&this->GPS);
  UFG::UITiledMapRaceSplines::UITiledMapRaceSplines(&this->RacePath);
  p_mLegendItems = &this->mLegendItems;
  this->mLegendItems.mNode.mPrev = &this->mLegendItems.mNode;
  this->mLegendItems.mNode.mNext = &this->mLegendItems.mNode;
  UFG::UITiledMapMath::UITiledMapMath(&this->m_mapGeo);
  this->mOriginPos = 0i64;
  this->mWaitForScreenPush = 0;
  *(_QWORD *)&this->OldMapGeo.MinX = 0i64;
  *(_QWORD *)&this->OldMapGeo.MinY = 0i64;
  *(_QWORD *)&this->OldMapGeo.TextureWidth = 0i64;
  this->mPolyListNative.p = 0i64;
  *(_QWORD *)&this->mPolyListNative.size = 0i64;
  v5 = UFG::qMalloc(0x58ui64, "UIHKMinimapTileStreamer", 0i64);
  if ( v5 )
  {
    UFG::UITiledMapTextureManager::UITiledMapTextureManager((UFG::UITiledMapTextureManager *)v5, 0xCu, 9u, 0x100u);
    v2 = v6;
  }
  this->mTileStreamerLowRes = v2;
  UFG::UITiledMapTextureManager::SetTileTag(v2, "_lowres");
  this->mTileStreamerLowRes->mStreamingEnabled = 0;
  UFG::UITiledMapTextureManager::SetActive(this->mTileStreamerLowRes, 1);
  this->mUseLowResTiles = 1;
  UFG::UIMapBlipManager::SetMaxNumIcons(&UFG::UIHKScreenWorldMap::mIconManager, 2000);
  this->mViewportScale = UFG::gUIViewportScale;
  this->mViewportScaleH = UFG::gUIViewportScaleH;
  this->mViewportScaleV = UFG::gUIViewportScaleV;
  for ( i = this->mLegendItems.mNode.mNext;
        i != (UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *)p_mLegendItems;
        i = this->mLegendItems.mNode.mNext )
  {
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
  }
  this->mLegendPageNumber = 1;
  UFG::InputSystem::SetShouldRestrictCursor(1, 1, 1, 1);
  UFG::InputSystem::SetShouldHideCursor(1, 1, 1, 1);
  UFG::InputSystem::msRelativeMouseMode = 1;
  UFG::InputSystem::msForceSendMouseMsgs = 1;
}

// File Line: 160
// RVA: 0x5CD230
void __fastcall UFG::UIHKScreenWorldMap::~UIHKScreenWorldMap(UFG::UIHKScreenWorldMap *this)
{
  UFG::UITiledMapTextureManager *mTileStreamerLowRes; // rbx
  UFG::UIScreenTextureManager *v3; // rax
  UFG::TiDoVtbl *vfptr; // rax
  UFG::UI *v5; // rcx
  UFG::UI *v6; // rcx
  unsigned int v7; // eax
  UFG::UIHKScreenGlobalOverlay *v8; // rax
  UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *p_mLegendItems; // rbx
  UFG::UIRenderQuad *p; // rcx
  UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *mPrev; // rcx
  UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *mNext; // rax
  UFG::qVector3 *v13; // rcx
  UFG::qVector3 *v14; // rcx

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenWorldMap::`vftable;
  mTileStreamerLowRes = this->mTileStreamerLowRes;
  if ( mTileStreamerLowRes )
  {
    UFG::UITiledMapTextureManager::~UITiledMapTextureManager(this->mTileStreamerLowRes);
    operator delete[](mTileStreamerLowRes);
  }
  this->mTileStreamerLowRes = 0i64;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "WorldMap");
  UFG::InputSystem::SetShouldRestrictCursor(0, 0, 1, 1);
  UFG::InputSystem::msForceSendMouseMsgs = 0;
  vfptr = UFG::TiDo::m_pInstance->vfptr;
  if ( this->mState == (NUM_CALIBRATION_STATES|STATE_BRIGHTNESS) )
  {
    ((void (__fastcall *)(UFG::TiDo *, __int64))vfptr[1].Close)(UFG::TiDo::m_pInstance, 1i64);
    UFG::InputSystem::SetShouldHideCursor(1, 0, 1, 0);
    UFG::InputSystem::msRelativeMouseMode = 0;
  }
  else
  {
    ((void (__fastcall *)(UFG::TiDo *, __int64))vfptr[1].Close)(UFG::TiDo::m_pInstance, 4i64);
    UFG::InputSystem::msRelativeMouseMode = 1;
    UFG::InputSystem::SetShouldHideCursor(1, 1, 1, 1);
    UFG::UI::UnpauseGame(v6);
  }
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v7 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v7 == 1) )
        UFG::UI::ResetGameplayInput(v5);
    }
  }
  UFG::UITiledMapMath::WorldGeo = this->OldMapGeo;
  v8 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v8 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Hide(&v8->HelpBar, gWorldMapHelpbarID);
  p_mLegendItems = &this->mLegendItems;
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&this->mLegendItems);
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_PAUSE_SCREEN_EXIT_20, 0xFFFFFFFF);
  UFG::UIHKScreenWorldMap::gPushedFromPauseMenu = 0;
  p = this->mPolyListNative.p;
  if ( p )
    operator delete[](p);
  this->mPolyListNative.p = 0i64;
  *(_QWORD *)&this->mPolyListNative.size = 0i64;
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&this->mLegendItems);
  mPrev = p_mLegendItems->mNode.mPrev;
  mNext = this->mLegendItems.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mLegendItems->mNode.mPrev = &p_mLegendItems->mNode;
  this->mLegendItems.mNode.mNext = &this->mLegendItems.mNode;
  v13 = this->RacePath.m_SplinePoints.p;
  if ( v13 )
    operator delete[](v13);
  this->RacePath.m_SplinePoints.p = 0i64;
  *(_QWORD *)&this->RacePath.m_SplinePoints.size = 0i64;
  v14 = this->RacePath.m_MarkerPositions.p;
  if ( v14 )
    operator delete[](v14);
  this->RacePath.m_MarkerPositions.p = 0i64;
  *(_QWORD *)&this->RacePath.m_MarkerPositions.size = 0i64;
  UFG::qString::~qString(&this->RacePath.m_CurrentLayerName);
  UFG::UITiledMapGPS::~UITiledMapGPS(&this->GPS);
  UFG::UIMapBlipManager::~UIMapBlipManager(&this->mMinimapIconManagerClone);
  UFG::UITiledMapWidget::~UITiledMapWidget(&this->mTiledMap);
  UFG::qString::~qString(&this->TutorialPopup.mCaption);
  `eh vector destructor iterator(
    this->Territory.mData,
    0x30ui64,
    20,
    (void (__fastcall *)(void *))UFG::SecondaryObjective::~SecondaryObjective);
  UFG::qString::~qString(&this->InfoPopup.mBodyText);
  UFG::qString::~qString(&this->InfoPopup.mTitleText);
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 223
// RVA: 0x637120
void __fastcall UFG::UIHKScreenWorldMap::init(UFG::UIHKScreenWorldMap *this, UFG::UICommandData *data)
{
  UFG::Controller *v3; // rcx
  __int64 v4; // rax
  float v5; // xmm0_4
  UFG::UIScreenRenderable *mRenderable; // rax
  UFG::UIHKScreenWorldMap::eViewType mViewType; // edx
  UFG::UITiledMapTextureManager *mTileStreamerLowRes; // rcx
  UFG::MinimapPoint2f v9; // [rsp+50h] [rbp+8h] BYREF
  UFG::MinimapPoint2f pos; // [rsp+60h] [rbp+18h] BYREF

  UFG::UIScreen::init(this, data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  this->OldMapGeo = UFG::UITiledMapMath::WorldGeo;
  UFG::UITiledMapMath::WorldGeo = UFG::UITiledMapMath::InitWorldGeo;
  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))this->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)(this->mRenderable->m_movie.pObject);
  v5 = (*(float (__fastcall **)(__int64))(*(_QWORD *)v4 + 48i64))(v4);
  mRenderable = this->mRenderable;
  *(_QWORD *)&this->m_mapGeo.CircleMaskX = 0i64;
  this->m_mapGeo.IsWorldMap = 1;
  this->m_mapGeo.MaskRadius = v5 * 0.5;
  if ( mRenderable->m_movie.pObject )
  {
    this->mTiledMap.mIsWorldMap = 1;
    UFG::UITiledMapWidget::Init(&this->mTiledMap, this);
    this->GPS.mMaxNumSplinePoints = 1100;
    this->GPS.mGPS_UpdatePeriod = 0.2;
    UFG::UIMapBlipManager::HandleScreenInit(&UFG::UIHKScreenWorldMap::mIconManager);
    UFG::UIHKCursorWidget::HandleScreenInit(&this->Cursor, this);
    UFG::UIHKCursorWidget::SetMargin(&this->Cursor, this, UFG::UIHKTweakables::WorldMap_CursorMargin);
    this->Legend.mState = STATE_COMPLETE;
    UFG::UIHKWorldMapLegendWidget::Flash_SetTerritoryLegendVisible(&this->Legend, this, 0);
    UFG::UITiledMapGPS::HandleScreenInit(&this->GPS, this);
    if ( (unsigned int)(this->TutorialPopup.mState - 4) <= 1 )
      this->TutorialPopup.mState = STATE_IDLE;
    if ( this->TutorialPopup.mState )
      this->TutorialPopup.mState = STATE_ROOT_MENU;
    this->mState = STATE_BRIGHTNESS;
    if ( UFG::UIHKScreenWorldMap::mShortcut )
    {
      mViewType = this->mViewType;
      if ( UFG::UIHKScreenWorldMap::mShortcut == TYPE_OCCLUSION )
        this->mViewType = TERRITORY_VIEW;
      this->mViewTypeChanged |= this->mViewType != mViewType;
      UFG::UIHKScreenWorldMap::mShortcut = TYPE_CULL;
    }
    UFG::UIHKScreenWorldMap::UpdateViewType(this);
    UFG::MinimapPoint2f::MinimapPoint2f(&pos, &this->mOriginPos);
    UFG::UITiledMapMath::UpdatePosition(&this->m_mapGeo, pos, 256);
    UFG::UIHKScreenWorldMap::CenterMapOnPlayerPos(this);
    UFG::MinimapPoint2f::MinimapPoint2f(&v9, &this->mOriginPos);
    mTileStreamerLowRes = this->mTileStreamerLowRes;
    if ( mTileStreamerLowRes )
    {
      v9.x = v9.x + -256.0;
      v9.y = v9.y + -256.0;
      UFG::UITiledMapTextureManager::SetPlayerPosition(mTileStreamerLowRes, &v9);
    }
    UFG::UIHKScreenWorldMap::ShowHelpBar(this);
    UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_PAUSE_SCREEN_INIT_20, 0xFFFFFFFF);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xB6A0047E, 0i64, 0, 0i64);
    UFG::UIHKScreenWorldMap::GetViewportScaleMatrix(this, &this->mViewportScaleMatrix);
    UFG::UIHKScreenWorldMap::ShowTutorialPopup(this);
  }
}

// File Line: 326
// RVA: 0x6406B0
void __fastcall UFG::UIHKScreenWorldMap::update(UFG::UIHKScreenWorldMap *this, float elapsed)
{
  bool m_IsKeyboardController; // al
  Scaleform::GFx::Movie *MovieSafe; // rax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm4_4
  int v13; // xmm2_4
  UFG::ProgressionTracker *v14; // rax
  UFG::UIHKMapLabelManager *v15; // rax
  UFG::SceneSettings settings; // [rsp+40h] [rbp-168h] BYREF

  UFG::UIScreenInvokeQueue::Update(&UFG::UIHKScreenWorldMap::mScreenInvokeQueue, this);
  UFG::UIHKInfoPopupWidget::Update(&this->TutorialPopup, this, elapsed);
  if ( UFG::gUIViewportScale != this->mViewportScale
    || UFG::gUIViewportScaleH != this->mViewportScaleH
    || UFG::gUIViewportScaleV != this->mViewportScaleV )
  {
    this->mViewportScale = UFG::gUIViewportScale;
    this->mViewportScaleH = UFG::gUIViewportScaleH;
    this->mViewportScaleV = UFG::gUIViewportScaleV;
    UFG::UIHKScreenWorldMap::GetViewportScaleMatrix(this, &this->mViewportScaleMatrix);
  }
  m_IsKeyboardController = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
  if ( m_IsKeyboardController != this->mIsKeyboardController )
  {
    this->mIsKeyboardController = m_IsKeyboardController;
    MovieSafe = UFG::UIScreen::getMovieSafe(this);
    if ( MovieSafe )
      Scaleform::GFx::Movie::Invoke(MovieSafe, "KeyboardControllerStatusChanged", 0i64, 0i64, 0);
  }
  switch ( this->mState )
  {
    case 1:
      v6 = elapsed + this->mMapFadeElapsed;
      this->mMapFadeElapsed = v6;
      if ( this->mBackgroundAlpha >= 0.0 )
        goto LABEL_46;
      v7 = v6 / this->mMapFadeTime;
      if ( v7 > 0.0 )
        v7 = 0.0;
      this->mBackgroundAlpha = v7;
      if ( v7 >= 0.0 )
      {
LABEL_46:
        if ( this->mFlashIntroComplete )
          goto LABEL_15;
      }
      if ( v6 > this->mIntroTimeOut )
      {
LABEL_15:
        this->mMapFadeElapsed = 0.0;
        UFG::UIHKScreenWorldMap::FinishIntro(this);
      }
      break;
    case 2:
      UFG::UIHKScreenWorldMap::UpdateMapFadeIn(this, elapsed);
      if ( this->mTilesLoadedFirstTime )
      {
        UFG::UIHKScreenWorldMap::UpdateScale(this, elapsed);
        UFG::UIHKScreenWorldMap::UpdateMapPosition(this, elapsed);
        UFG::UIHKScreenWorldMap::UpdateViewType(this);
        UFG::UIHKScreenWorldMap::UpdateRacePath(this, elapsed);
        UFG::UIHKWorldMapTerritoryWidget::Update(&this->Territory, this, &this->m_mapGeo);
        UFG::UIHKWorldMapLegendWidget::Update(&this->Legend, this);
      }
      break;
    case 3:
      UFG::UIHKScreenWorldMap::UpdateMapFadeIn(this, elapsed);
      if ( this->mTilesLoadedFirstTime )
      {
        UFG::UIHKScreenWorldMap::UpdateScale(this, elapsed);
        UFG::UIHKScreenWorldMap::UpdateMapPosition(this, elapsed);
        UFG::UIHKWorldMapLegendWidget::Update(&this->Legend, this);
      }
      break;
    case 6:
      if ( UFG::UIHKScreenGlobalOverlay::mThis
        && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
      {
        UFG::UIHK_NISOverlay::ShowElement(
          &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
          UFG::UIHKScreenGlobalOverlay::mThis,
          &UFG::UIHK_NISOverlay::m_curtains,
          0.33000001,
          1);
        UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 1;
      }
      UFG::UIHK_NISOverlay::UpdateAudioMuteState();
      this->mState = NUM_CALIBRATION_STATES|STATE_UISCALE;
      break;
    case 7:
      if ( (UFG::UIHK_NISOverlay::m_curtains.m_state & 0xFFFFFFFD) == 0 )
      {
        this->vfptr[1].__vecDelDtor(this, 0x40000000u);
        UFG::TransitUtility::OnExitMap();
        UFG::SceneSettings::SceneSettings(&settings, "non-permanent-must-use-ApplySceneSettingsCached()");
        settings.mHideCurtains = 0;
        v14 = UFG::ProgressionTracker::Instance();
        UFG::ProgressionTracker::ApplySceneSettingsCached(v14, &settings);
        UFG::SceneSettings::~SceneSettings(&settings);
      }
      break;
    case 8:
      v8 = 0.0;
      if ( this->mMapTileAlpha > 0.0 )
      {
        v9 = elapsed + this->mMapFadeElapsed;
        this->mMapFadeElapsed = v9;
        v10 = v9 / this->mMapFadeTime;
        v11 = 1.0 - v10;
        if ( (float)(1.0 - v10) >= 0.0 )
          v12 = 1.0 - v10;
        else
          v12 = 0.0;
        this->mMapTileAlpha = v12;
        if ( v11 < 0.0 )
          v11 = 0.0;
        this->mIconAlpha = v11;
        v13 = LODWORD(v10) ^ _xmm[0];
        if ( COERCE_FLOAT(LODWORD(v10) ^ _xmm[0]) < 0.0 )
          v13 = 0;
        LODWORD(this->mBackgroundAlpha) = v13;
        if ( (float)(UFG::UIHKTweakables::WorldMap_GridAlpha - v10) >= 0.0 )
          v8 = UFG::UIHKTweakables::WorldMap_GridAlpha - v10;
        this->mMapGridAlpha = v8;
        this->mTiledMap.mAlpha = v12;
      }
      UFG::UIHKScreenWorldMap::UpdateRacePath(this, elapsed);
      break;
    default:
      break;
  }
  v15 = qword_142433908;
  if ( !qword_142433908 )
  {
    v15 = (UFG::UIHKMapLabelManager *)UFG::qMalloc(
                                        (unsigned int)((_DWORD)qword_142433908 + 32),
                                        "UIHKMapLabelManager",
                                        0i64);
    if ( v15 )
    {
      v15->mData.p = 0i64;
      *(_QWORD *)&v15->mData.size = 0i64;
      v15->mNumLabels = 0;
      v15->mInitialized = 0;
    }
    else
    {
      v15 = 0i64;
    }
    qword_142433908 = v15;
  }
  UFG::UIHKMapLabelManager::update(v15, this, &this->m_mapGeo);
  UFG::UITiledMapWidget::UpdateWorldMap(&this->mTiledMap, this, &this->m_mapGeo);
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 519
// RVA: 0x62E2C0
bool __fastcall UFG::UIHKScreenWorldMap::handleMessage(
        UFG::UIHKScreenWorldMap *this,
        __int64 msgId,
        UFG::UIMessage *msg)
{
  unsigned int v4; // edi
  UFG::UIScreenTextureManager *v7; // rax
  UFG::qVector3 destPos; // [rsp+30h] [rbp-18h] BYREF
  UFG::WorldPoint2f v9; // [rsp+50h] [rbp+8h] BYREF

  v4 = msgId;
  switch ( this->mState )
  {
    case 1:
      if ( (_DWORD)msgId == UI_HASH_INTRO_COMPLETE_30 )
      {
        this->mFlashIntroComplete = 1;
        if ( UFG::UIHKScreenGlobalOverlay::mThis )
        {
          if ( UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64
            && UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay.mActive )
          {
            UFG::UIHK_NISOverlay::FadeToLight();
          }
        }
      }
      if ( UI_HASH_OBJECTIVES_FADE_IN_20 == v4 )
      {
        if ( this->ObjectivesWidget.mState == STATE_INVALID )
          this->ObjectivesWidget.mState = STATE_NORMAL;
      }
      else if ( UI_HASH_OBJECTIVES_FADE_OUT_20 == v4 && this->ObjectivesWidget.mState == STATE_DANGER )
      {
        this->ObjectivesWidget.mState = STATE_COMPLETE;
      }
      if ( UI_HASH_PERKGOALS_FADE_IN_20 == v4 )
      {
        if ( this->PerkGoalsWidget.mState == STATE_INVALID )
          this->PerkGoalsWidget.mState = STATE_NORMAL;
      }
      else if ( UI_HASH_PERKGOALS_FADE_OUT_20 == v4 && this->PerkGoalsWidget.mState == STATE_DANGER )
      {
        this->PerkGoalsWidget.mState = STATE_COMPLETE;
      }
      return UFG::UIScreen::handleMessage(this, v4, msg);
    case 2:
      if ( !UFG::UIHKScreenWorldMap::handleMessage_StateNormal(this, msgId, msg) )
        return UFG::UIScreen::handleMessage(this, v4, msg);
      return 1;
    case 3:
      if ( (_DWORD)msgId == UI_HASH_EXIT_FROM_TRANSIT_SCREEN_20 )
      {
        ((void (__fastcall *)(UFG::UIHKScreenWorldMap *))this->vfptr[1].__vecDelDtor)(this);
        UFG::TransitUtility::OnExitMap();
        return 1;
      }
      if ( (_DWORD)msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 || (_DWORD)msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
      {
        if ( this->Cursor.mIsOpen )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCCF5DDCu, 0i64, 0, 0i64);
          UFG::WorldPoint2f::WorldPoint2f(&v9, &this->Cursor.mPos, &this->m_mapGeo);
          destPos.x = v9.x;
          destPos.y = v9.y;
          destPos.z = 0.0;
          UFG::TransitUtility::OnSelectDestination(&destPos);
          UFG::UIScreenDialogBox::createYesNoDialog(
            this,
            "$WORLD_MAP_TRANSIT_DIAGLOG_TITLE",
            "$WORLD_MAP_TRANSIT_ENGAGE",
            0,
            0);
          this->mState = NUM_CALIBRATION_STATES;
        }
        return UFG::UIScreen::handleMessage(this, v4, msg);
      }
      if ( (_DWORD)msgId != UI_HASH_BUTTON_BACK_RELEASED_30 || !this->mTransitEnableBackButton )
        return UFG::UIScreen::handleMessage(this, v4, msg);
      ((void (__fastcall *)(UFG::UIHKScreenWorldMap *))this->vfptr[1].__vecDelDtor)(this);
      UFG::UIHKScreenWorldMap::gDidPlayerCancelTaxi = 1;
      return 1;
    case 4:
      if ( (_DWORD)msgId == UI_HASH_DIALOG_YES_30 )
      {
        this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
      }
      else if ( (_DWORD)msgId == UI_HASH_DIALOG_NO_30 )
      {
        this->mState = STATE_UISCALE;
      }
      return UFG::UIScreen::handleMessage(this, v4, msg);
    case 5:
      if ( (_DWORD)msgId != UI_HASH_SCREEN_FADE_IN_COMPLETE_12 )
        return UFG::UIScreen::handleMessage(this, v4, msg);
      UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
      v7 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueLoadAndPush(v7, "PauseMenu", 0i64);
      this->mShouldPushHud = 0;
      this->mWaitForScreenPush = 1;
      return 1;
    case 8:
      if ( (_DWORD)msgId != UI_HASH_OUTRO_COMPLETE_30 )
        return UFG::UIScreen::handleMessage(this, v4, msg);
      UFG::UIHKScreenWorldMap::Exit(this);
      return 1;
    default:
      return UFG::UIScreen::handleMessage(this, v4, msg);
  }
}

// File Line: 655
// RVA: 0x62F8A0
char __fastcall UFG::UIHKScreenWorldMap::handleMessage_StateNormal(
        UFG::UIHKScreenWorldMap *this,
        __int64 msgId,
        UFG::UIMessage *msg)
{
  int v3; // edi
  bool v6; // zf
  UFG::qVector3 worldPos; // [rsp+30h] [rbp-18h] BYREF
  UFG::WorldPoint2f v8; // [rsp+68h] [rbp+20h] BYREF

  v3 = msgId;
  if ( (_DWORD)msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 || (_DWORD)msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
  {
    if ( UFG::UIHKWorldMapCursorWidget::SelectObjective(&this->Cursor, &this->m_mapGeo) )
      UFG::UIHKScreenWorldMap::HighlightCurrentObjectiveBlip(this);
    if ( this->mCurrentViewHasGPS )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC17D78C0, 0i64, 0, 0i64);
      UFG::WorldPoint2f::WorldPoint2f(&v8, &this->Cursor.mPos, &this->m_mapGeo);
      worldPos.x = v8.x;
      worldPos.y = v8.y;
      worldPos.z = 0.0;
      UFG::UIHKScreenWorldMap::SetGPSDestination(this, &worldPos);
    }
  }
  else
  {
    if ( (_DWORD)msgId == UI_HASH_BUTTON_BACK_RELEASED_30 )
    {
      if ( UFG::UIHKScreenWorldMap::gPushedFromPauseMenu )
      {
        if ( UFG::UIHKScreenGlobalOverlay::mThis )
        {
          if ( UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
          {
            UFG::UIHK_NISOverlay::ShowElement(
              &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
              UFG::UIHKScreenGlobalOverlay::mThis,
              &UFG::UIHK_NISOverlay::m_curtains,
              0.33000001,
              1);
            UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 1;
          }
        }
LABEL_8:
        UFG::UIHK_NISOverlay::UpdateAudioMuteState();
        ((void (__fastcall *)(UFG::TiDo *, __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
          UFG::TiDo::m_pInstance,
          1i64);
        this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
        return 1;
      }
      goto LABEL_11;
    }
    if ( (_DWORD)msgId == UI_HASH_BUTTON_SELECT_PRESSED_30 && !UFG::UIHKScreenWorldMap::gPushedFromPauseMenu )
    {
LABEL_11:
      ((void (__fastcall *)(UFG::UIHKScreenWorldMap *, __int64, UFG::UIMessage *))this->vfptr[1].__vecDelDtor)(
        this,
        msgId,
        msg);
      return 1;
    }
    if ( (_DWORD)msgId == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
    {
      UFG::UIHKScreenWorldMap::ToggleCollectibles(this);
      return 1;
    }
    if ( (_DWORD)msgId == UI_HASH_BUTTON_L1_PRESSED_30 )
    {
      UFG::UIHKScreenWorldMap::LegendTurnPage(this);
      return 1;
    }
    if ( (_DWORD)msgId == UI_HASH_BUTTON_R1_PRESSED_30 )
    {
      UFG::UIHKWorldMapLegendWidget::ToggleOpen(&this->Legend);
      return 1;
    }
    if ( (_DWORD)msgId == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
    {
      UFG::UIHKScreenWorldMap::ToggleObjectives(this);
      return 1;
    }
    if ( (_DWORD)msgId == UI_HASH_BUTTON_START_PRESSED_30 )
    {
      if ( UFG::UIHKScreenGlobalOverlay::mThis
        && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
      {
        UFG::UIHK_NISOverlay::ShowElement(
          &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
          UFG::UIHKScreenGlobalOverlay::mThis,
          &UFG::UIHK_NISOverlay::m_curtains,
          0.33000001,
          1);
        UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 1;
      }
      goto LABEL_8;
    }
  }
  if ( v3 == UI_HASH_FADE_IN_COMPLETE_30 )
  {
    this->InfoPopup.mState = STATE_TEXT_INBOX;
  }
  else if ( v3 == UI_HASH_FADE_OUT_COMPLETE_30 )
  {
    v6 = !this->InfoPopup.mVisible;
    this->InfoPopup.mState = STATE_IDLE;
    this->InfoPopup.mVisible = 0;
    this->InfoPopup.mChanged |= !v6;
  }
  if ( v3 == UI_HASH_WIDGET_FADE_IN_20 )
  {
    this->Legend.mState = STATE_ANIMATE_COMPLETE;
  }
  else if ( v3 == UI_HASH_WIDGET_FADE_OUT_20 )
  {
    this->Legend.mState = STATE_COMPLETE;
  }
  if ( UI_HASH_OBJECTIVES_FADE_IN_20 == v3 )
  {
    if ( this->ObjectivesWidget.mState == STATE_INVALID )
      this->ObjectivesWidget.mState = STATE_NORMAL;
  }
  else if ( UI_HASH_OBJECTIVES_FADE_OUT_20 == v3 && this->ObjectivesWidget.mState == STATE_DANGER )
  {
    this->ObjectivesWidget.mState = STATE_COMPLETE;
  }
  if ( UI_HASH_PERKGOALS_FADE_IN_20 == v3 )
  {
    if ( this->PerkGoalsWidget.mState == STATE_INVALID )
    {
      this->PerkGoalsWidget.mState = STATE_NORMAL;
      return 0;
    }
  }
  else if ( UI_HASH_PERKGOALS_FADE_OUT_20 == v3 && this->PerkGoalsWidget.mState == STATE_DANGER )
  {
    this->PerkGoalsWidget.mState = STATE_COMPLETE;
  }
  return 0;
}

// File Line: 772
// RVA: 0x612A10
void __fastcall UFG::UIHKScreenWorldMap::ToggleCollectibles(UFG::UIHKScreenWorldMap *this)
{
  UFG::HudAudio *v2; // rcx
  unsigned int v3; // edx

  if ( this->mViewType == COLLECTIBLES_VIEW )
  {
    this->mViewType = BASIC_VIEW;
    UFG::UIHKScreenWorldMap::Flash_SetViewType(this, 0);
    this->mViewTypeChanged = 1;
    UFG::UIHKScreenWorldMap::UpdateViewType(this);
    v2 = UFG::HudAudio::m_instance;
    if ( !UFG::HudAudio::m_instance )
      return;
    v3 = -782291096;
  }
  else
  {
    this->mViewType = COLLECTIBLES_VIEW;
    UFG::UIHKScreenWorldMap::Flash_SetViewType(this, 1);
    this->mViewTypeChanged = 1;
    UFG::UIHKScreenWorldMap::UpdateViewType(this);
    v2 = UFG::HudAudio::m_instance;
    if ( !UFG::HudAudio::m_instance )
      return;
    v3 = -1616300686;
  }
  UFG::AudioEntity::CreateAndPlayEvent(v2, v3, 0i64, 0, 0i64);
}

// File Line: 793
// RVA: 0x612AA0
void __fastcall UFG::UIHKScreenWorldMap::ToggleObjectives(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKWorldMapObjectivesWidget::ToggleOpen(&this->ObjectivesWidget, this);
  UFG::UIHKWorldMapPerkGoalsWidget::ToggleOpen(&this->PerkGoalsWidget, this);
}

// File Line: 800
// RVA: 0x60C800
char __fastcall UFG::UIHKScreenWorldMap::SetWorldMapFromVehicle(UFG::SimObject *vehicle)
{
  char result; // al
  char IsClassType; // bl
  char v4; // si

  if ( UFG::SimObjectUtility::IsClassType(vehicle, &qSymbol_Taxi) )
  {
    UFG::UIHKScreenWorldMap::mViewMode = TRANSIT_VIEW_MODE;
    UFG::UIHKScreenWorldMap::gDidPlayerCancelTaxi = 0;
    return 1;
  }
  else
  {
    IsClassType = UFG::SimObjectUtility::IsClassType(vehicle, &qSymbol_Tram);
    v4 = UFG::SimObjectUtility::IsClassType(vehicle, &qSymbol_Ferry);
    result = UFG::SimObjectUtility::IsClassType(vehicle, &qSymbol_Minibus);
    if ( IsClassType || v4 || result )
    {
      UFG::UIHKScreenWorldMap::mViewMode = TRANSIT_VIEW_MODE;
      UFG::UIHKScreenWorldMap::gDidPlayerCancelTaxi = 0;
      return 1;
    }
  }
  return result;
}

// File Line: 826
// RVA: 0x5D89B0
void __fastcall UFG::UIHKScreenWorldMap::FinishIntro(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKMapLabelManager *v2; // rax

  this->mState = (UFG::UIHKScreenWorldMap::mViewMode == TRANSIT_VIEW_MODE) + 2;
  v2 = qword_142433908;
  if ( !qword_142433908 )
  {
    v2 = (UFG::UIHKMapLabelManager *)UFG::qMalloc(0x20ui64, "UIHKMapLabelManager", 0i64);
    if ( v2 )
    {
      v2->mData.p = 0i64;
      *(_QWORD *)&v2->mData.size = 0i64;
      v2->mNumLabels = 0;
      v2->mInitialized = 0;
    }
    else
    {
      v2 = 0i64;
    }
    qword_142433908 = v2;
  }
  UFG::UIHKMapLabelManager::HandleScreenInit(v2, this);
}

// File Line: 844
// RVA: 0x638FF0
void __fastcall UFG::UIHKScreenWorldMap::outro(UFG::UIHKScreenWorldMap *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  UFG::UIHKMapLabelManager *v3; // rax
  UFG::UIHKScreenGlobalOverlay *v4; // rax

  UFG::UIScreen::outro(this, 0i64);
  this->mState = 8;
  UFG::UIHKScreenWorldMap::mViewMode = DEFAULT_VIEW_MODE;
  this->mMapFadeElapsed = 0.0;
  if ( this->Legend.mState == STATE_ANIMATE_COMPLETE )
  {
    this->Legend.mToggleFadeOut = 1;
    this->Legend.mChanged = 1;
  }
  UFG::UIHKWorldMapLegendWidget::Update(&this->Legend, this);
  if ( this->ObjectivesWidget.mState <= (unsigned int)STATE_NORMAL )
  {
    this->ObjectivesWidget.mState = STATE_DANGER;
    UFG::UIScreen::invoke(this, "Objectives_Hide");
  }
  if ( this->PerkGoalsWidget.mState <= (unsigned int)STATE_NORMAL )
  {
    this->PerkGoalsWidget.mState = STATE_DANGER;
    pObject = this->mRenderable->m_movie.pObject;
    if ( pObject )
      Scaleform::GFx::Movie::Invoke(pObject, "PerkGoals_Hide", 0i64, 0i64, 0);
  }
  v3 = qword_142433908;
  if ( !qword_142433908 )
  {
    v3 = (UFG::UIHKMapLabelManager *)UFG::qMalloc(
                                       (unsigned int)((_DWORD)qword_142433908 + 32),
                                       "UIHKMapLabelManager",
                                       0i64);
    if ( v3 )
    {
      v3->mData.p = 0i64;
      *(_QWORD *)&v3->mData.size = 0i64;
      v3->mNumLabels = 0;
      v3->mInitialized = 0;
    }
    else
    {
      v3 = 0i64;
    }
    qword_142433908 = v3;
  }
  UFG::UIHKMapLabelManager::StartOutro(v3, this);
  v4 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v4 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Hide(&v4->HelpBar, gWorldMapHelpbarID);
  if ( this->mRacePathState != LOADING )
    this->mRacePathState = UNLOADED;
}

// File Line: 865
// RVA: 0x5E6900
UFG::UIScreen *__fastcall UFG::UIHKScreenWorldMap::Get()
{
  return UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "WorldMap");
}

// File Line: 879
// RVA: 0x5D7C20
void __fastcall UFG::UIHKScreenWorldMap::Exit(UFG::UIHKScreenWorldMap *this)
{
  bool v2; // di
  bool v3; // al
  ANTLR3_INPUT_STREAM_struct *v4; // rax

  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
  v2 = !UFG::UIHKScreenWorldMap::gDidPlayerCancelTaxi;
  v3 = (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateChangeLocation_13
    || (unsigned int)UFG::FlowController::GetPendingState(&UFG::gFlowController) == uidGameStateChangeLocation_13;
  if ( v2 && v3 )
  {
    v4 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::SetGameState(v4, 8u);
  }
  this->mFinished = 1;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
}

// File Line: 898
// RVA: 0x60FA60
void __fastcall UFG::UIHKScreenWorldMap::ShowHelpBar(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v4; // ebx
  UFG::UIHKHelpBarWidget *v5; // rdi
  unsigned int v6; // ebx
  int v7; // ecx
  __int64 v8; // rax
  __int64 v9; // rdi
  __int64 v10; // rbx
  int v11; // ecx
  __int64 v12; // rax
  __int64 v13; // rdi
  __int64 v14; // rbx
  int v15; // ecx
  __int64 v16; // rax
  __int64 v17; // rdi
  __int64 v18; // rbx
  int v19; // ecx
  __int64 v20; // rax
  __int64 v21; // rdi
  __int64 v22; // rbx
  int v23; // ecx
  __int64 v24; // rax
  __int64 v25; // rdi
  __int64 v26; // rbx
  int v27; // ecx
  __int64 v28; // rax
  __int64 v29; // rdi
  __int64 v30; // rbx
  UFG::UIHKScreenGlobalOverlay *v31; // rax
  UFG::UIHKHelpBarData data; // [rsp+20h] [rbp-D8h] BYREF
  __int64 v33; // [rsp+268h] [rbp+170h]

  v33 = -2i64;
  if ( UFG::UIHKScreenWorldMap::mViewMode == TRANSIT_VIEW_MODE )
  {
    v2 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( this->mTransitEnableBackButton )
    {
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v2 = &gGlobalOverlaySentinel;
      p_HelpBar = &v2->HelpBar;
      v4 = gWorldMapHelpbarID;
      UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
      data.id = v4;
      *(_QWORD *)&data.priority = 0i64;
      *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
      *(_QWORD *)&data.Buttons[4] = 0i64;
      UFG::qString::Set(data.Captions, "$WORLDMAP_SET_DESTINATION_UPPERCASE");
      UFG::qString::Set(&data.Captions[1], "$COMMON_ZOOM_UPPERCASE");
      UFG::qString::Set((UFG::qString *)&data.Captions[1].mStringHash32, "$COMMON_CANCEL");
      UFG::qString::Set((UFG::qString *)&data.Captions[2].mStringHash32, &customCaption);
      UFG::qString::Set((UFG::qString *)&data.Captions[3].mStringHash32, &customCaption);
      UFG::qString::Set((UFG::qString *)&data.Captions[4].mStringHash32, &customCaption);
      memset(&data.Icons[5].mStringHash32, 0, 24);
      UFG::UIHKHelpBarWidget::Show(p_HelpBar, &data);
      UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
      `eh vector destructor iterator(
        &data.Captions[5].mStringHash32,
        0x28ui64,
        6,
        (void (__fastcall *)(void *))UFG::qString::~qString);
    }
    else
    {
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v2 = &gGlobalOverlaySentinel;
      v5 = &v2->HelpBar;
      v6 = gWorldMapHelpbarID;
      UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
      data.id = v6;
      *(_QWORD *)&data.priority = 0i64;
      *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
      *(_QWORD *)&data.Buttons[4] = 0i64;
      UFG::qString::Set(data.Captions, "$WORLDMAP_SET_DESTINATION_UPPERCASE");
      UFG::qString::Set(&data.Captions[1], "$COMMON_ZOOM_UPPERCASE");
      UFG::qString::Set((UFG::qString *)&data.Captions[1].mStringHash32, "$WORLD_MAP_COLLECTIBLES_VIEW");
      UFG::qString::Set((UFG::qString *)&data.Captions[2].mStringHash32, &customCaption);
      UFG::qString::Set((UFG::qString *)&data.Captions[3].mStringHash32, &customCaption);
      UFG::qString::Set((UFG::qString *)&data.Captions[4].mStringHash32, &customCaption);
      memset(&data.Icons[5].mStringHash32, 0, 24);
      UFG::UIHKHelpBarWidget::Show(v5, &data);
      UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
      `eh vector destructor iterator(
        &data.Captions[5].mStringHash32,
        0x28ui64,
        6,
        (void (__fastcall *)(void *))UFG::qString::~qString);
    }
  }
  else
  {
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = gWorldMapHelpbarID;
    *(_QWORD *)&data.priority = 0i64;
    v7 = 0;
    v8 = 0i64;
    while ( data.Buttons[v8] )
    {
      ++v7;
      if ( ++v8 >= 6 )
        goto LABEL_14;
    }
    v9 = v7;
    data.Buttons[v9] = ACCEPT_BUTTON;
    v10 = v7;
    UFG::qString::Set(&data.Captions[v10], "$WORLDMAP_SET_WAYPOINT_UPPERCASE");
    UFG::qString::Set((UFG::qString *)&data.Captions[v10 + 5].mStringHash32, &customCaption);
    data.MessageIds[v9 - 2] = 0;
LABEL_14:
    v11 = 0;
    v12 = 0i64;
    while ( data.Buttons[v12] )
    {
      ++v11;
      if ( ++v12 >= 6 )
        goto LABEL_19;
    }
    v13 = v11;
    data.Buttons[v13] = BACK_BUTTON;
    v14 = v11;
    UFG::qString::Set(&data.Captions[v14], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)&data.Captions[v14 + 5].mStringHash32, &customCaption);
    data.MessageIds[v13 - 2] = 0;
LABEL_19:
    if ( this->mViewType != COLLECTIBLES_VIEW )
    {
      v15 = 0;
      v16 = 0i64;
      while ( data.Buttons[v16] )
      {
        ++v15;
        if ( ++v16 >= 6 )
          goto LABEL_25;
      }
      v17 = v15;
      data.Buttons[v17] = BUTTON2_BUTTON;
      v18 = v15;
      UFG::qString::Set(&data.Captions[v18], "$WORLDMAP_OBJECTIVES_CAPS");
      UFG::qString::Set((UFG::qString *)&data.Captions[v18 + 5].mStringHash32, &customCaption);
      data.MessageIds[v17 - 2] = 0;
    }
LABEL_25:
    v19 = 0;
    v20 = 0i64;
    while ( data.Buttons[v20] )
    {
      ++v19;
      if ( ++v20 >= 6 )
        goto LABEL_30;
    }
    v21 = v19;
    data.Buttons[v21] = L2R2_BUTTON;
    v22 = v19;
    UFG::qString::Set(&data.Captions[v22], "$COMMON_ZOOM_UPPERCASE");
    UFG::qString::Set((UFG::qString *)&data.Captions[v22 + 5].mStringHash32, &customCaption);
    data.MessageIds[v21 - 2] = 0;
LABEL_30:
    v23 = 0;
    v24 = 0i64;
    while ( data.Buttons[v24] )
    {
      ++v23;
      if ( ++v24 >= 6 )
        goto LABEL_35;
    }
    v25 = v23;
    data.Buttons[v25] = R1_BUTTON;
    v26 = v23;
    UFG::qString::Set(&data.Captions[v26], "$WORLDMAP_LEGEND_UPPERCASE");
    UFG::qString::Set((UFG::qString *)&data.Captions[v26 + 5].mStringHash32, &customCaption);
    data.MessageIds[v25 - 2] = 0;
LABEL_35:
    v27 = 0;
    v28 = 0i64;
    while ( data.Buttons[v28] )
    {
      ++v27;
      if ( ++v28 >= 6 )
        goto LABEL_40;
    }
    v29 = v27;
    data.Buttons[v29] = BUTTON1_BUTTON;
    v30 = v27;
    UFG::qString::Set(&data.Captions[v30], "$WORLD_MAP_COLLECTIBLES_VIEW");
    UFG::qString::Set((UFG::qString *)&data.Captions[v30 + 5].mStringHash32, &customCaption);
    data.MessageIds[v29 - 2] = 0;
LABEL_40:
    v31 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v31 = &gGlobalOverlaySentinel;
    UFG::UIHKHelpBarWidget::Show(&v31->HelpBar, &data);
    UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
    `eh vector destructor iterator(
      &data.Captions[5].mStringHash32,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
  }
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 948
// RVA: 0x61B190
void __fastcall UFG::UIHKScreenWorldMap::UpdateMapPosition(UFG::UIHKScreenWorldMap *this, float elapsed)
{
  UFG::UITiledMapMath *mapGeo; // rsi
  float mAxisPositionY; // xmm0_4
  UFG::InputActionData *v6; // rcx
  float mAxisPositionX; // xmm1_4
  float v8; // xmm4_4
  UFG::UITiledMapTextureManager *mTileStreamerLowRes; // rcx
  float y; // xmm1_4
  UFG::UIAmbientMapBlipManager *Instance; // rax
  UFG::qVector3 isIndoors; // [rsp+48h] [rbp+7h] BYREF
  UFG::qVector3 playerPos; // [rsp+58h] [rbp+17h] BYREF
  UFG::qVector3 dir; // [rsp+68h] [rbp+27h] BYREF
  UFG::ScreenPoint2f offset; // [rsp+A8h] [rbp+67h]
  UFG::MinimapPoint2f retaddr; // [rsp+B8h] [rbp+77h] BYREF

  mapGeo = &this->m_mapGeo;
  UFG::UIHKWorldMapCursorWidget::Update(
    &this->Cursor,
    this,
    (UFG::BasePhysicsSystem *)&this->mMinimapIconManagerClone,
    &this->m_mapGeo);
  mAxisPositionY = 0.0;
  if ( !this->mLockMapScrolling )
  {
    offset = this->Cursor.mEdgePush;
    v6 = UFG::ActionDef_UIRightThumbstick.mDataPerController[UFG::gActiveControllerNum];
    if ( v6 )
      mAxisPositionX = v6->mAxisPositionX;
    else
      mAxisPositionX = 0.0;
    if ( v6 )
      mAxisPositionY = v6->mAxisPositionY;
    v8 = 1.0 / this->m_mapGeo.scale;
    if ( COERCE_FLOAT(LODWORD(offset.x) & _xmm) <= COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                                                  (float)(UFG::UIHKTweakables::WorldMap_PanSpeed
                                                                        * mAxisPositionX)
                                                                * v8) & _xmm) )
      offset.x = (float)(UFG::UIHKTweakables::WorldMap_PanSpeed * mAxisPositionX) * v8;
    if ( COERCE_FLOAT(LODWORD(offset.y) & _xmm) <= COERCE_FLOAT((COERCE_UNSIGNED_INT(
                                                                   (float)(UFG::UIHKTweakables::WorldMap_PanSpeed
                                                                         * mAxisPositionY)
                                                                 * v8) ^ _xmm[0]) & _xmm) )
      LODWORD(offset.y) = COERCE_UNSIGNED_INT((float)(UFG::UIHKTweakables::WorldMap_PanSpeed * mAxisPositionY) * v8) ^ _xmm[0];
    UFG::UIHKScreenWorldMap::MoveCenter(this, offset);
  }
  UFG::UIHKWorldMapInfoPopupWidget::Update(&this->InfoPopup, this);
  UFG::MinimapPoint2f::MinimapPoint2f(&retaddr, &this->mOriginPos);
  mTileStreamerLowRes = this->mTileStreamerLowRes;
  if ( mTileStreamerLowRes )
  {
    retaddr.x = retaddr.x + -256.0;
    retaddr.y = retaddr.y + -256.0;
    UFG::UITiledMapTextureManager::SetPlayerPosition(mTileStreamerLowRes, &retaddr);
  }
  UFG::UITiledMapGPS::Update(&this->GPS, elapsed, this, mapGeo);
  UFG::UIMapLinesWidget::Update(&UFG::UIHKScreenWorldMap::MapLines, elapsed, mapGeo);
  playerPos.z = 0.0;
  y = this->mOriginPos.y;
  playerPos.x = this->mOriginPos.x;
  playerPos.y = y;
  this->mPolyListNative.size = 0;
  Instance = UFG::UIAmbientMapBlipManager::getInstance();
  UFG::UIAmbientMapBlipManager::Update(Instance, elapsed, &this->mMinimapIconManagerClone, 1);
  UFG::UIMapBlipManager::Update(
    &UFG::UIHKScreenWorldMap::mIconManager,
    this,
    elapsed,
    &playerPos,
    mapGeo,
    mapGeo,
    &this->mPolyListNative,
    &this->mPolyListNative,
    &this->mPolyListNative,
    1,
    0);
  UFG::UIMapBlipManager::Update(
    &this->mMinimapIconManagerClone,
    this,
    elapsed,
    &playerPos,
    mapGeo,
    mapGeo,
    &this->mPolyListNative,
    &this->mPolyListNative,
    &this->mPolyListNative,
    1,
    0);
  if ( !UFG::UI::GetPlayerWorldPosition(&isIndoors, &dir) )
  {
    *(_QWORD *)&isIndoors.x = 0i64;
    isIndoors.z = 0.0;
    dir.x = 0.0;
    dir.y = 1.0;
  }
  dir.z = 0.0;
  UFG::UIHKScreenWorldMap::PlacePlayerIcon(this, &isIndoors, &dir);
  _((AMD_HD3D *)&this->mMinimapIconManagerClone);
  _((AMD_HD3D *)&UFG::UIHKScreenWorldMap::mIconManager);
}

// File Line: 1026
// RVA: 0x61B0E0
void __fastcall UFG::UIHKScreenWorldMap::UpdateMapFadeIn(UFG::UIHKScreenWorldMap *this, float elapsed)
{
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm1_4
  float v5; // xmm3_4
  float v6; // xmm0_4

  if ( UFG::UITiledMapTextureManager::mNumTilesLoaded >= this->mTileStreamerLowRes->mTileCount
    || this->mTilesLoadedFirstTime )
  {
    v2 = *(float *)&FLOAT_1_0;
    this->mTilesLoadedFirstTime = 1;
    if ( this->mMapTileAlpha < 1.0
      || this->mIconAlpha < 1.0
      || UFG::UIHKTweakables::WorldMap_GridAlpha > this->mMapGridAlpha )
    {
      v3 = elapsed + this->mMapFadeElapsed;
      this->mMapFadeElapsed = v3;
      v4 = v3 / this->mMapFadeTime;
      if ( v4 <= 1.0 )
        v5 = v4;
      else
        v5 = *(float *)&FLOAT_1_0;
      this->mMapTileAlpha = v5;
      if ( v4 <= 1.0 )
        v2 = v4;
      this->mIconAlpha = v2;
      v6 = UFG::UIHKTweakables::WorldMap_GridAlpha;
      if ( UFG::UIHKTweakables::WorldMap_GridAlpha >= v4 )
        v6 = v4;
      this->mMapGridAlpha = v6;
      this->mTiledMap.mAlpha = v5;
    }
  }
}

// File Line: 1046
// RVA: 0x61CF30
void __fastcall UFG::UIHKScreenWorldMap::UpdateScale(UFG::UIHKScreenWorldMap *this, float elapsed)
{
  float scale; // xmm6_4
  UFG::InputActionData *v4; // rax
  float v5; // xmm2_4
  bool v6; // r9
  UFG::InputActionData *v7; // rax
  bool v8; // dl
  UFG::InputActionData *v9; // rax
  UFG::InputActionData *v10; // rax
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm7_4
  __int64 v14; // rax
  double v15; // xmm0_8
  float v16; // xmm6_4
  __int64 v17; // rax
  double v18; // xmm0_8
  float y; // xmm1_4
  UFG::ScreenPoint2f point; // [rsp+50h] [rbp+8h] BYREF
  UFG::WorldPoint2f v21; // [rsp+60h] [rbp+18h] BYREF

  scale = this->m_mapGeo.scale;
  v4 = UFG::ActionDef_UIL2Repeat.mDataPerController[UFG::gActiveControllerNum];
  v5 = *(float *)&FLOAT_1_0;
  v6 = v4 && v4->mActionTrue;
  v7 = UFG::ActionDef_UIR2Repeat.mDataPerController[UFG::gActiveControllerNum];
  v8 = v7 && v7->mActionTrue;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    v9 = UFG::ActionDef_CamZoomOut.mDataPerController[UFG::gActiveControllerNum];
    v5 = UFG::UIHKTweakables::WorldMap_ZoomBoostMouse;
    v6 = v9 && v9->mActionTrue;
    v10 = UFG::ActionDef_CamZoomIn.mDataPerController[UFG::gActiveControllerNum];
    v8 = v10 && v10->mActionTrue;
  }
  if ( v6 )
  {
    if ( !v8 && scale > UFG::UIHKTweakables::WorldMap_MinZoom )
    {
      v11 = scale - (float)((float)((float)(UFG::UIHKTweakables::WorldMap_ZoomSpeed * elapsed) * v5) * scale);
LABEL_25:
      this->m_mapGeo.scale = v11;
    }
  }
  else if ( v8 && scale < UFG::UIHKTweakables::WorldMap_MaxZoom )
  {
    v11 = (float)((float)((float)(UFG::UIHKTweakables::WorldMap_ZoomSpeed * elapsed) * v5) * scale) + scale;
    goto LABEL_25;
  }
  v12 = this->m_mapGeo.scale;
  if ( v12 <= UFG::UIHKTweakables::WorldMap_MinZoom )
    v12 = UFG::UIHKTweakables::WorldMap_MinZoom;
  if ( v12 >= UFG::UIHKTweakables::WorldMap_MaxZoom )
    v12 = UFG::UIHKTweakables::WorldMap_MaxZoom;
  this->m_mapGeo.scale = v12;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v12 - scale) & _xmm) > 0.0000099999997 )
  {
    UFG::ScreenPoint2f::ScreenPoint2f(&point, &this->mOriginPos, &this->m_mapGeo);
    v13 = 1.0 - (float)(this->m_mapGeo.scale / scale);
    v14 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))this->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)(this->mRenderable->m_movie.pObject);
    v15 = (*(double (__fastcall **)(__int64))(*(_QWORD *)v14 + 48i64))(v14);
    v16 = *(float *)&v15;
    v17 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))this->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)(this->mRenderable->m_movie.pObject);
    v18 = (*(double (__fastcall **)(__int64))(*(_QWORD *)v17 + 56i64))(v17);
    point.x = point.x + (float)((float)(v16 * v13) * -0.5);
    point.y = point.y + (float)((float)(*(float *)&v18 * v13) * -0.5);
    UFG::WorldPoint2f::WorldPoint2f(&v21, &point, &this->m_mapGeo);
    y = v21.y;
    this->mOriginPos.x = v21.x;
    this->mOriginPos.y = y;
    UFG::UIHKScreenWorldMap::BoundMapOrigin(this);
  }
}

// File Line: 1114
// RVA: 0x5F3CE0
void __fastcall UFG::UIHKScreenWorldMap::PlacePlayerIcon(UFG::UIHKScreenWorldMap *this)
{
  UFG::qVector3 dir; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 pos; // [rsp+30h] [rbp-18h] BYREF

  if ( !UFG::UI::GetPlayerWorldPosition(&pos, &dir) )
  {
    *(_QWORD *)&pos.x = 0i64;
    pos.z = 0.0;
    LODWORD(dir.y) = (_DWORD)FLOAT_1_0;
    dir.x = 0.0;
  }
  dir.z = 0.0;
  UFG::UIHKScreenWorldMap::PlacePlayerIcon(this, &pos, &dir);
}

// File Line: 1128
// RVA: 0x5F3B10
void __fastcall UFG::UIHKScreenWorldMap::PlacePlayerIcon(
        UFG::UIHKScreenWorldMap *this,
        UFG::qVector3 *playerPos,
        UFG::qVector3 *playerForward)
{
  float v6; // xmm3_4
  float v7; // xmm7_4
  float i; // xmm7_4
  UFG::qVector3 v2; // [rsp+30h] [rbp-48h] BYREF
  UFG::MinimapPoint2f v10; // [rsp+80h] [rbp+8h] BYREF
  UFG::ScreenPoint2f v11; // [rsp+88h] [rbp+10h] BYREF
  UFG::WorldPoint2f point; // [rsp+90h] [rbp+18h] BYREF
  UFG::MinimapTilePoint2f iconPos; // [rsp+98h] [rbp+20h] BYREF

  UFG::qStringHash32("the_player", 0xFFFFFFFF);
  v2.x = 0.0;
  *(_QWORD *)&v2.y = 1065353216i64;
  v6 = FLOAT_N1_0;
  v7 = (float)(UFG::qAngleBetween(playerForward, &v2) * 180.0) * 0.31830987;
  if ( (float)((float)(v2.x * playerForward->y) - (float)(v2.y * playerForward->x)) < 0.0 )
    v6 = *(float *)&FLOAT_1_0;
  for ( i = v7 * v6; i < -180.0; i = i + 360.0 )
    ;
  for ( ; i > 180.0; i = i + -360.0 )
    ;
  UFG::WorldPoint2f::WorldPoint2f(&point, playerPos);
  UFG::MinimapPoint2f::MinimapPoint2f(&v10, &point);
  if ( playerPos->y > 1690.0 && playerPos->z > 20.0 )
  {
    v10.x = v10.x + UFG::UITiledMapTweakables::WorldMap_ElectionBlipOffsetX;
    v10.y = v10.y + UFG::UITiledMapTweakables::WorldMap_ElectionBlipOffsetY;
  }
  UFG::MinimapTilePoint2f::MinimapTilePoint2f(&iconPos, &v10, &this->m_mapGeo);
  v11 = 0i64;
  UFG::ScreenPoint2f::InitFromIconPos(&v11, &iconPos, &this->m_mapGeo);
  UFG::UIMapBlipManager::UpdatePlayerArrow(&this->mMinimapIconManagerClone, (int)v11.x, (int)v11.y, i, 1);
}

// File Line: 1166
// RVA: 0x5F1E40
void __fastcall UFG::UIHKScreenWorldMap::MoveCenter(UFG::UIHKScreenWorldMap *this, UFG::ScreenPoint2f offset)
{
  float v3; // xmm1_4
  UFG::MinimapPoint2f pos; // [rsp+30h] [rbp+8h] BYREF
  UFG::ScreenPoint2f v5; // [rsp+38h] [rbp+10h]

  v5 = offset;
  v3 = offset.y
     * COERCE_FLOAT(COERCE_UNSIGNED_INT(
                      (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY)
                    / UFG::UITiledMapMath::WorldGeo.TextureHeight) ^ _xmm[0]);
  this->mOriginPos.x = (float)((float)((float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX)
                                     / UFG::UITiledMapMath::WorldGeo.TextureWidth)
                             * offset.x)
                     + this->mOriginPos.x;
  this->mOriginPos.y = this->mOriginPos.y - v3;
  UFG::UIHKScreenWorldMap::BoundMapOrigin(this);
  UFG::MinimapPoint2f::MinimapPoint2f(&pos, &this->mOriginPos);
  UFG::UITiledMapMath::UpdatePosition(&this->m_mapGeo, pos, 256);
}

// File Line: 1200
// RVA: 0x5D4B60
void __fastcall UFG::UIHKScreenWorldMap::CenterMapOnPlayerPos(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIScreenRenderable *mRenderable; // rax
  float v3; // xmm1_4
  __int64 v4; // rax
  double v5; // xmm0_8
  float v6; // xmm6_4
  __int64 v7; // rax
  UFG::qVector3 pos; // [rsp+20h] [rbp-48h] BYREF
  UFG::qVector3 dir; // [rsp+30h] [rbp-38h] BYREF
  UFG::MinimapTilePoint2f v10; // [rsp+70h] [rbp+8h] BYREF
  UFG::ScreenPoint2f offset; // [rsp+78h] [rbp+10h]
  UFG::WorldPoint2f point; // [rsp+80h] [rbp+18h] BYREF
  UFG::MinimapPoint2f v13; // [rsp+88h] [rbp+20h] BYREF

  if ( !UFG::UI::GetPlayerWorldPosition(&pos, &dir) )
  {
    *(_QWORD *)&pos.x = 0i64;
    pos.z = 0.0;
  }
  UFG::WorldPoint2f::WorldPoint2f(&point, &pos);
  UFG::MinimapPoint2f::MinimapPoint2f(&v13, &point);
  UFG::MinimapTilePoint2f::MinimapTilePoint2f(&v10, &v13, &this->m_mapGeo);
  mRenderable = this->mRenderable;
  v3 = v10.y + this->m_mapGeo.screenPosition.y;
  v10.x = v10.x + this->m_mapGeo.screenPosition.x;
  v10.y = v3;
  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)(mRenderable->m_movie.pObject);
  v5 = (*(double (__fastcall **)(__int64))(*(_QWORD *)v4 + 48i64))(v4);
  v6 = *(float *)&v5;
  v7 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))this->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)(this->mRenderable->m_movie.pObject);
  *(float *)&v5 = (*(float (__fastcall **)(__int64))(*(_QWORD *)v7 + 56i64))(v7);
  offset.x = v10.x - (float)(v6 * 0.5);
  offset.y = (float)(*(float *)&v5 * 0.5) - v10.y;
  UFG::UIHKScreenWorldMap::MoveCenter(this, offset);
}

// File Line: 1227
// RVA: 0x5D4290
void __fastcall UFG::UIHKScreenWorldMap::BoundMapOrigin(UFG::UIHKScreenWorldMap *this)
{
  float v2; // xmm8_4
  __int64 v3; // rax
  float v4; // xmm0_4
  float v5; // xmm6_4
  float v6; // xmm7_4
  __int64 v7; // rax
  float v8; // xmm0_4
  float x; // xmm1_4
  float y; // xmm1_4

  v2 = UFG::UIHKTweakables::WorldMap_MinX;
  v3 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))this->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)(this->mRenderable->m_movie.pObject);
  v4 = (*(float (__fastcall **)(__int64))(*(_QWORD *)v3 + 48i64))(v3);
  v5 = UFG::UIHKTweakables::WorldMap_MinY;
  v6 = UFG::UIHKTweakables::WorldMap_MaxX - (float)(v4 / this->m_mapGeo.scale);
  v7 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))this->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)(this->mRenderable->m_movie.pObject);
  v8 = (float)((*(float (__fastcall **)(__int64))(*(_QWORD *)v7 + 56i64))(v7) / this->m_mapGeo.scale)
     + UFG::UIHKTweakables::WorldMap_MaxY;
  if ( v2 > v6 )
    v2 = v6;
  if ( v5 < v8 )
    v5 = v8;
  x = this->mOriginPos.x;
  if ( x <= v6 )
  {
    if ( x < v2 )
      this->mOriginPos.x = v2;
  }
  else
  {
    this->mOriginPos.x = v6;
  }
  y = this->mOriginPos.y;
  if ( y >= v8 )
  {
    if ( y > v5 )
      this->mOriginPos.y = v5;
  }
  else
  {
    this->mOriginPos.y = v8;
  }
}

// File Line: 1282
// RVA: 0x6109A0
void __fastcall UFG::UIHKScreenWorldMap::ShowInfoPopup(
        UFG::UIHKScreenWorldMap *this,
        float x,
        float y,
        const char *titleText,
        const char *bodyText)
{
  UFG::UIHKWorldMapInfoPopupWidget::eState mState; // ecx
  bool v7; // al

  this->InfoPopup.mPosX = x;
  this->InfoPopup.mPosY = y;
  this->InfoPopup.mChanged = 1;
  UFG::qString::Set(&this->InfoPopup.mTitleText, titleText);
  this->InfoPopup.mChanged = 1;
  UFG::qString::Set(&this->InfoPopup.mBodyText, bodyText);
  mState = this->InfoPopup.mState;
  v7 = !this->InfoPopup.mVisible;
  this->InfoPopup.mVisible = 1;
  this->InfoPopup.mChanged |= v7;
  if ( mState == STATE_IDLE || mState == STATE_PHONE_CONTACTS )
  {
    this->InfoPopup.mState = STATE_ROOT_MENU;
    this->InfoPopup.mCueAnimation = 1;
  }
}

// File Line: 1325
// RVA: 0x61CE70
void __fastcall UFG::UIHKScreenWorldMap::UpdateRacePath(UFG::UIHKScreenWorldMap *this, float elapsed)
{
  UFG::UIHKScreenWorldMap::eRacePathState mRacePathState; // eax
  float v3; // xmm1_4
  double v4; // xmm0_8
  double v5; // xmm1_8
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm1_4

  mRacePathState = this->mRacePathState;
  if ( mRacePathState )
  {
    if ( mRacePathState == UNLOADED )
    {
      if ( this->mRacePathAlpha <= 0.0 )
      {
        this->mRacePathState = LOADING;
      }
      else
      {
        v3 = elapsed + this->mRacePathFadeElapsed;
        this->mRacePathFadeElapsed = v3;
        v4 = (float)(v3 / this->mRacePathFadeTime);
        v5 = 0.0;
        if ( 1.0 - v4 >= 0.0 )
          v5 = 1.0 - v4;
        this->mRacePathAlpha = v5;
      }
    }
  }
  else
  {
    v6 = *(float *)&FLOAT_1_0;
    if ( this->mRacePathAlpha >= 1.0 )
    {
      this->mRacePathState = UNLOADING;
    }
    else
    {
      v7 = elapsed + this->mRacePathFadeElapsed;
      this->mRacePathFadeElapsed = v7;
      v8 = v7 / this->mRacePathFadeTime;
      if ( v8 <= 1.0 )
        v6 = v8;
      this->mRacePathAlpha = v6;
    }
  }
}

// File Line: 1359
// RVA: 0x6009C0
// attributes: thunk
void __fastcall UFG::UIHKScreenWorldMap::RefreshSecondaryObjectives(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap::DisplaySecondaryObjectives(this);
}

// File Line: 1397
// RVA: 0x61D860
void __fastcall UFG::UIHKScreenWorldMap::UpdateViewType(UFG::UIHKScreenWorldMap *this)
{
  int v2; // edi
  bool v3; // al
  bool v4; // cl
  bool v5; // cl
  UFG::UIAmbientMapBlipManager *Instance; // rax
  UFG::UIScreenRenderable *mRenderable; // rax
  Scaleform::GFx::Movie *pObject; // rdi
  unsigned int v9; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v11; // rax
  char *mData; // rsi
  Scaleform::GFx::Movie *v13; // rcx
  const char *v14; // rdx
  UFG::qSymbolUC *v15; // rbx
  UFG::qArray<UFG::qSymbolUC,0> blipTypes; // [rsp+20h] [rbp-21h] BYREF
  UFG::qString v17; // [rsp+30h] [rbp-11h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+58h] [rbp+17h] BYREF

  if ( !this->mViewTypeChanged )
    return;
  this->mViewTypeChanged = 0;
  UFG::UIMapBlipManager::Clear(&this->mMinimapIconManagerClone);
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&this->mLegendItems);
  this->mLegendPageNumber = 1;
  UFG::UIHKScreenWorldMap::AddLegendItem(this, "player_arrow", "$MAP_LEGEND_PLAYER");
  blipTypes.p = 0i64;
  *(_QWORD *)&blipTypes.size = 0i64;
  v2 = 0;
  do
  {
    v3 = UFG::UIHKScreenWorldMap::SetUpLegend(this, &blipTypes, 0);
    if ( !v3 )
      this->mViewTypeChanged = 0;
    ++v2;
  }
  while ( v2 <= 20 && !v3 );
  v4 = this->mViewType == TERRITORY_VIEW;
  this->Legend.mChanged |= this->Legend.mTerritoryMode != v4;
  this->Legend.mTerritoryMode = v4;
  v5 = this->mViewType == TERRITORY_VIEW;
  this->Territory.mChanged |= this->Territory.mVisible != v5;
  this->Territory.mVisible = v5;
  UFG::UIHKWorldMapCollectiblesStatsWidget::Flash_SetVisible(
    &this->CollectiblesStats,
    this,
    this->mViewType == COLLECTIBLES_VIEW);
  Instance = UFG::UIAmbientMapBlipManager::getInstance();
  UFG::UIAmbientMapBlipManager::HandleScreenInit(Instance);
  if ( UFG::UIHKScreenWorldMap::mViewMode == TRANSIT_VIEW_MODE )
  {
    UFG::UITiledMapGPS::SetActive(&this->GPS, 0);
    *(_QWORD *)&blipTypes.size = Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Boolean;
    ptr.mValue.BValue = 1;
    mRenderable = this->mRenderable;
    if ( mRenderable )
    {
      pObject = mRenderable->m_movie.pObject;
      if ( pObject )
      {
        Scaleform::GFx::Movie::Invoke(pObject, "Transit_ShowButton", 0i64, &ptr, 1u);
        v9 = UFG::qStringHashUpper32("WORLD_MAP_TRANSIT_DIAGLOG_TITLE", -1);
        m_translator = UFG::UIScreenManager::s_instance->m_translator;
        if ( !m_translator || (v11 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v9)) == 0i64 )
          v11 = "WORLD_MAP_TRANSIT_DIAGLOG_TITLE";
        UFG::qString::qString(&v17, v11);
        mData = v17.mData;
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
        Scaleform::GFx::Movie::Invoke(pObject, "SetMapTitle", 0i64, &ptr, 1u);
        UFG::qString::~qString(&v17);
      }
    }
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
  UFG::UIMapBlipManager::PopulateWorldMap(
    &this->mMinimapIconManagerClone,
    this,
    UFG::UIHKScreenHud::mIconManager,
    &blipTypes);
  v13 = this->mRenderable->m_movie.pObject;
  if ( this->mViewType == TERRITORY_VIEW )
  {
    if ( v13 )
    {
      v14 = "Legend_Resize_Territory";
LABEL_24:
      Scaleform::GFx::Movie::Invoke(v13, v14, 0i64, 0i64, 0);
    }
  }
  else if ( v13 )
  {
    v14 = "Legend_Resize";
    goto LABEL_24;
  }
  UFG::UIHKScreenWorldMap::ShowLegend(this, this->mLegendPageNumber);
  UFG::UIHKScreenWorldMap::ShowHelpBar(this);
  UFG::UIHKScreenWorldMap::PlacePlayerIcon(this);
  UFG::UIHKScreenWorldMap::HighlightCurrentObjectiveBlip(this);
  UFG::UIHKScreenWorldMap::SetUpObjectiveView(this);
  if ( this->mViewType == TERRITORY_VIEW )
  {
    this->mCurrentViewHasGPS = 0;
    UFG::UITiledMapGPS::SetActive(&this->GPS, 0);
  }
  else
  {
    this->mCurrentViewHasGPS = 1;
    UFG::UITiledMapGPS::PopulateWorldMap(UFG::UIHKScreenHud::GPS, &this->GPS);
  }
  if ( blipTypes.p )
  {
    v15 = blipTypes.p - 1;
    `eh vector destructor iterator(blipTypes.p, 4ui64, blipTypes.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v15);
  }
}

// File Line: 1570
// RVA: 0x1570FA0
__int64 UFG::_dynamic_initializer_for__sym_cop_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_symbol", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_symbol, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_cop_symbol__);
}

// File Line: 1571
// RVA: 0x1570EE0
__int64 UFG::_dynamic_initializer_for__sym_cop_foot_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_foot_symbol", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_foot_symbol, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_cop_foot_symbol__);
}

// File Line: 1572
// RVA: 0x1570EA0
__int64 UFG::_dynamic_initializer_for__sym_cop_foot_patrol_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_foot_patrol_symbol", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_foot_patrol_symbol, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_cop_foot_patrol_symbol__);
}

// File Line: 1573
// RVA: 0x1570FE0
__int64 UFG::_dynamic_initializer_for__sym_cop_vehicle_patrol_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_vehicle_patrol_symbol", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_vehicle_patrol_symbol, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_cop_vehicle_patrol_symbol__);
}

// File Line: 1574
// RVA: 0x1571BA0
__int64 UFG::_dynamic_initializer_for__sym_roadblock_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("roadblock_symbol", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_roadblock_symbol, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_roadblock_symbol__);
}

// File Line: 1575
// RVA: 0x15715A0
__int64 UFG::_dynamic_initializer_for__sym_hiding_spot__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("hiding_spot", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_hiding_spot, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_hiding_spot__);
}

// File Line: 1576
// RVA: 0x15715E0
__int64 UFG::_dynamic_initializer_for__sym_hiding_spot_garage__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("hiding_spot_garage", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_hiding_spot_garage, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_hiding_spot_garage__);
}

// File Line: 1577
// RVA: 0x15722A0
__int64 UFG::_dynamic_initializer_for__sym_witness_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("witness_symbol", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_witness_symbol, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_witness_symbol__);
}

// File Line: 1578
// RVA: 0x1571420
__int64 UFG::_dynamic_initializer_for__sym_friendly__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("friendly", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_friendly, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_friendly__);
}

// File Line: 1579
// RVA: 0x15710E0
__int64 UFG::_dynamic_initializer_for__sym_enemy__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("enemy", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_enemy, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_enemy__);
}

// File Line: 1580
// RVA: 0x1571120
__int64 UFG::_dynamic_initializer_for__sym_enemy_noncombat__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("enemy_noncombat", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_enemy_noncombat, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_enemy_noncombat__);
}

// File Line: 1581
// RVA: 0x1570E20
__int64 UFG::_dynamic_initializer_for__sym_contact__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("contact", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_contact, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_contact__);
}

// File Line: 1582
// RVA: 0x1571DA0
__int64 UFG::_dynamic_initializer_for__sym_social__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("social", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_social, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_social__);
}

// File Line: 1583
// RVA: 0x1571DE0
__int64 UFG::_dynamic_initializer_for__sym_social_ambient__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("social_ambient", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_social_ambient, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_social_ambient__);
}

// File Line: 1584
// RVA: 0x1571E20
__int64 UFG::_dynamic_initializer_for__sym_social_mission__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("social_mission", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_social_mission, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_social_mission__);
}

// File Line: 1585
// RVA: 0x1570DA0
__int64 UFG::_dynamic_initializer_for__sym_case_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("case_start", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_case_start, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_case_start__);
}

// File Line: 1586
// RVA: 0x1570D60
__int64 UFG::_dynamic_initializer_for__sym_case_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("case_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_case_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_case_objective__);
}

// File Line: 1587
// RVA: 0x15712E0
__int64 UFG::_dynamic_initializer_for__sym_face_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("face_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_face_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_face_objective__);
}

// File Line: 1588
// RVA: 0x1571960
__int64 UFG::_dynamic_initializer_for__sym_mission_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("mission_start", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_mission_start, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_mission_start__);
}

// File Line: 1589
// RVA: 0x1571920
__int64 UFG::_dynamic_initializer_for__sym_mission_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("mission_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_mission_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_mission_objective__);
}

// File Line: 1590
// RVA: 0x1571B20
__int64 UFG::_dynamic_initializer_for__sym_race_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("race_start", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_race_start, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_race_start__);
}

// File Line: 1591
// RVA: 0x1571B60
__int64 UFG::_dynamic_initializer_for__sym_race_start_flag__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("race_start_flag", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_race_start_flag, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_race_start_flag__);
}

// File Line: 1592
// RVA: 0x1571AA0
__int64 UFG::_dynamic_initializer_for__sym_race_end__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("race_end", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_race_end, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_race_end__);
}

// File Line: 1593
// RVA: 0x1571AE0
__int64 UFG::_dynamic_initializer_for__sym_race_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("race_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_race_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_race_objective__);
}

// File Line: 1594
// RVA: 0x1570E60
__int64 UFG::_dynamic_initializer_for__sym_cop_event_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_event_start", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_event_start, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_cop_event_start__);
}

// File Line: 1595
// RVA: 0x15711E0
__int64 UFG::_dynamic_initializer_for__sym_event_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("event_start", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_event_start, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_event_start__);
}

// File Line: 1596
// RVA: 0x15711A0
__int64 UFG::_dynamic_initializer_for__sym_event_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("event_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_event_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_event_objective__);
}

// File Line: 1597
// RVA: 0x1571720
__int64 UFG::_dynamic_initializer_for__sym_job_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("job_start", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_job_start, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_job_start__);
}

// File Line: 1598
// RVA: 0x15716E0
__int64 UFG::_dynamic_initializer_for__sym_job_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("job_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_job_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_job_objective__);
}

// File Line: 1599
// RVA: 0x1571160
__int64 UFG::_dynamic_initializer_for__sym_enemy_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("enemy_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_enemy_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_enemy_objective__);
}

// File Line: 1600
// RVA: 0x1570F20
__int64 UFG::_dynamic_initializer_for__sym_cop_job__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_job", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_job, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_cop_job__);
}

// File Line: 1601
// RVA: 0x1570F60
__int64 UFG::_dynamic_initializer_for__sym_cop_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_cop_objective__);
}

// File Line: 1602
// RVA: 0x15721A0
__int64 UFG::_dynamic_initializer_for__sym_transterror_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("transterror_start", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_transterror_start, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_transterror_start__);
}

// File Line: 1603
// RVA: 0x1572160
__int64 UFG::_dynamic_initializer_for__sym_transterror_mission__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("transterror_mission", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_transterror_mission, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_transterror_mission__);
}

// File Line: 1604
// RVA: 0x1572120
__int64 UFG::_dynamic_initializer_for__sym_transterror_event__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("transterror_event", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_transterror_event, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_transterror_event__);
}

// File Line: 1605
// RVA: 0x15723E0
__int64 UFG::_dynamic_initializer_for__sym_zodiac_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("zodiac_start", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_zodiac_start, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_zodiac_start__);
}

// File Line: 1606
// RVA: 0x15723A0
__int64 UFG::_dynamic_initializer_for__sym_zodiac_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("zodiac_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_zodiac_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_zodiac_objective__);
}

// File Line: 1607
// RVA: 0x1572320
__int64 UFG::_dynamic_initializer_for__sym_zodiac_event__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("zodiac_event", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_zodiac_event, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_zodiac_event__);
}

// File Line: 1608
// RVA: 0x15722E0
__int64 UFG::_dynamic_initializer_for__sym_zodiac_enemy__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("zodiac_enemy", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_zodiac_enemy, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_zodiac_enemy__);
}

// File Line: 1609
// RVA: 0x1572360
__int64 UFG::_dynamic_initializer_for__sym_zodiac_friendly__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("zodiac_friendly", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_zodiac_friendly, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_zodiac_friendly__);
}

// File Line: 1610
// RVA: 0x1571460
__int64 UFG::_dynamic_initializer_for__sym_ghost_elite_ghoul__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("ghost_elite_ghoul", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_ghost_elite_ghoul, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_ghost_elite_ghoul__);
}

// File Line: 1611
// RVA: 0x15714A0
__int64 UFG::_dynamic_initializer_for__sym_ghost_lesser_ghoul__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("ghost_lesser_ghoul", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_ghost_lesser_ghoul, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_ghost_lesser_ghoul__);
}

// File Line: 1612
// RVA: 0x1571560
__int64 UFG::_dynamic_initializer_for__sym_ghost_trapped_ped__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("ghost_trapped_ped", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_ghost_trapped_ped, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_ghost_trapped_ped__);
}

// File Line: 1613
// RVA: 0x1571020
__int64 UFG::_dynamic_initializer_for__sym_crime_scene__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("crime_scene", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_crime_scene, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_crime_scene__);
}

// File Line: 1614
// RVA: 0x1571BE0
__int64 UFG::_dynamic_initializer_for__sym_safe_house__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("safe_house", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_safe_house, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_safe_house__);
}

// File Line: 1615
// RVA: 0x1571C20
__int64 UFG::_dynamic_initializer_for__sym_safe_house_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("safe_house_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_safe_house_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_safe_house_objective__);
}

// File Line: 1616
// RVA: 0x1571C60
__int64 UFG::_dynamic_initializer_for__sym_safe_house_unlocked__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("safe_house_unlocked", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_safe_house_unlocked, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_safe_house_unlocked__);
}

// File Line: 1617
// RVA: 0x1572220
__int64 UFG::_dynamic_initializer_for__sym_undercover_safe_house__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("undercover_safe_house", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_undercover_safe_house, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_undercover_safe_house__);
}

// File Line: 1618
// RVA: 0x15721E0
__int64 UFG::_dynamic_initializer_for__sym_triad_war__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("triad_war", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_triad_war, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_triad_war__);
}

// File Line: 1619
// RVA: 0x1571060
__int64 UFG::_dynamic_initializer_for__sym_date_character__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("date_character", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_date_character, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_date_character__);
}

// File Line: 1620
// RVA: 0x15712A0
__int64 UFG::_dynamic_initializer_for__sym_face_character__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("face_character", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_face_character, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_face_character__);
}

// File Line: 1621
// RVA: 0x1572260
__int64 UFG::_dynamic_initializer_for__sym_waypoint__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("waypoint", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_waypoint, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_waypoint__);
}

// File Line: 1622
// RVA: 0x1571A60
__int64 UFG::_dynamic_initializer_for__sym_player_car__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("player_car", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_player_car, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_player_car__);
}

// File Line: 1623
// RVA: 0x1571A20
__int64 UFG::_dynamic_initializer_for__sym_parking_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("parking_symbol", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_parking_symbol, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_parking_symbol__);
}

// File Line: 1624
// RVA: 0x15719E0
__int64 UFG::_dynamic_initializer_for__sym_parking_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("parking_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_parking_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_parking_objective__);
}

// File Line: 1625
// RVA: 0x1571320
__int64 UFG::_dynamic_initializer_for__sym_ferry__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("ferry", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_ferry, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_ferry__);
}

// File Line: 1626
// RVA: 0x1570D20
__int64 UFG::_dynamic_initializer_for__sym_bus_stop__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("bus_stop", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_bus_stop, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_bus_stop__);
}

// File Line: 1627
// RVA: 0x1571EA0
__int64 UFG::_dynamic_initializer_for__sym_store_clothing__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_clothing", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_clothing, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_store_clothing__);
}

// File Line: 1628
// RVA: 0x1571EE0
__int64 UFG::_dynamic_initializer_for__sym_store_clothing_indoors__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_clothing_indoors", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_clothing_indoors, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_store_clothing_indoors__);
}

// File Line: 1629
// RVA: 0x1571F60
__int64 UFG::_dynamic_initializer_for__sym_store_exotic_clothing__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_exotic_clothing", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_exotic_clothing, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_store_exotic_clothing__);
}

// File Line: 1630
// RVA: 0x1571F20
__int64 UFG::_dynamic_initializer_for__sym_store_convenience__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_convenience", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_convenience, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_store_convenience__);
}

// File Line: 1631
// RVA: 0x1571E60
__int64 UFG::_dynamic_initializer_for__sym_store_apothecary__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_apothecary", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_apothecary, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_store_apothecary__);
}

// File Line: 1632
// RVA: 0x1572060
__int64 UFG::_dynamic_initializer_for__sym_store_vehicle__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_vehicle", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_vehicle, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_store_vehicle__);
}

// File Line: 1633
// RVA: 0x1572020
__int64 UFG::_dynamic_initializer_for__sym_store_social__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_social", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_social, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_store_social__);
}

// File Line: 1634
// RVA: 0x1571FA0
__int64 UFG::_dynamic_initializer_for__sym_store_gambling__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_gambling", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_gambling, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_store_gambling__);
}

// File Line: 1635
// RVA: 0x15717A0
__int64 UFG::_dynamic_initializer_for__sym_karaoke__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("karaoke", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_karaoke, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_karaoke__);
}

// File Line: 1636
// RVA: 0x15710A0
__int64 UFG::_dynamic_initializer_for__sym_drunken_dice__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("drunken_dice", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_drunken_dice, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_drunken_dice__);
}

// File Line: 1637
// RVA: 0x1570DE0
__int64 UFG::_dynamic_initializer_for__sym_cock_fighting__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cock_fighting", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cock_fighting, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_cock_fighting__);
}

// File Line: 1638
// RVA: 0x1571360
__int64 UFG::_dynamic_initializer_for__sym_fight_club__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("fight_club", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_fight_club, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_fight_club__);
}

// File Line: 1639
// RVA: 0x1571FE0
__int64 UFG::_dynamic_initializer_for__sym_store_massage__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_massage", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_massage, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_store_massage__);
}

// File Line: 1640
// RVA: 0x15719A0
__int64 UFG::_dynamic_initializer_for__sym_outdoor_massage__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("outdoor_massage", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_outdoor_massage, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_outdoor_massage__);
}

// File Line: 1641
// RVA: 0x1571860
__int64 UFG::_dynamic_initializer_for__sym_martial_arts__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("martial_arts", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_martial_arts, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_martial_arts__);
}

// File Line: 1642
// RVA: 0x15718A0
__int64 UFG::_dynamic_initializer_for__sym_martial_arts_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("martial_arts_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_martial_arts_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_martial_arts_objective__);
}

// File Line: 1643
// RVA: 0x15716A0
__int64 UFG::_dynamic_initializer_for__sym_hijack__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("hijack", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_hijack, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_hijack__);
}

// File Line: 1644
// RVA: 0x1571CA0
__int64 UFG::_dynamic_initializer_for__sym_security_camera__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("security_camera", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_security_camera, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_security_camera__);
}

// File Line: 1645
// RVA: 0x1571CE0
__int64 UFG::_dynamic_initializer_for__sym_security_camera_collected__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("security_camera_collected", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_security_camera_collected, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_security_camera_collected__);
}

// File Line: 1646
// RVA: 0x1571D20
__int64 UFG::_dynamic_initializer_for__sym_shrine__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("shrine", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_shrine, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_shrine__);
}

// File Line: 1647
// RVA: 0x1571D60
__int64 UFG::_dynamic_initializer_for__sym_shrine_collected__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("shrine_collected", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_shrine_collected, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_shrine_collected__);
}

// File Line: 1648
// RVA: 0x15717E0
__int64 UFG::_dynamic_initializer_for__sym_lockbox__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("lockbox", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_lockbox, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_lockbox__);
}

// File Line: 1649
// RVA: 0x1571820
__int64 UFG::_dynamic_initializer_for__sym_lockbox_collected__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("lockbox_collected", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_lockbox_collected, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_lockbox_collected__);
}

// File Line: 1650
// RVA: 0x1571660
__int64 UFG::_dynamic_initializer_for__sym_hiding_spot_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("hiding_spot_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_hiding_spot_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_hiding_spot_objective__);
}

// File Line: 1651
// RVA: 0x1571620
__int64 UFG::_dynamic_initializer_for__sym_hiding_spot_garage_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("hiding_spot_garage_objective", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_hiding_spot_garage_objective, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_hiding_spot_garage_objective__);
}

// File Line: 1652
// RVA: 0x15720E0
__int64 UFG::_dynamic_initializer_for__sym_tourist_photo__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("tourist_photo", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_tourist_photo, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_tourist_photo__);
}

// File Line: 1653
// RVA: 0x1571760
__int64 UFG::_dynamic_initializer_for__sym_jump__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("jump", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_jump, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_jump__);
}

// File Line: 1654
// RVA: 0x15720A0
__int64 UFG::_dynamic_initializer_for__sym_tape_recorder__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("tape_recorder", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_tape_recorder, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_tape_recorder__);
}

// File Line: 1655
// RVA: 0x1570CE0
__int64 UFG::_dynamic_initializer_for__sym_bug__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("bug", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_bug, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_bug__);
}

// File Line: 1656
// RVA: 0x15718E0
__int64 UFG::_dynamic_initializer_for__sym_melee_upgrade__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("melee_upgrade", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_melee_upgrade, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_melee_upgrade__);
}

// File Line: 1658
// RVA: 0x15714E0
__int64 UFG::_dynamic_initializer_for__sym_ghost_orb__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("ghost_orb", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_ghost_orb, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_ghost_orb__);
}

// File Line: 1659
// RVA: 0x1571520
__int64 UFG::_dynamic_initializer_for__sym_ghost_orb_collected__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("ghost_orb_collected", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_ghost_orb_collected, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_ghost_orb_collected__);
}

// File Line: 1660
// RVA: 0x15713A0
__int64 UFG::_dynamic_initializer_for__sym_fire_statue__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("fire_statue", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_fire_statue, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_fire_statue__);
}

// File Line: 1661
// RVA: 0x15713E0
__int64 UFG::_dynamic_initializer_for__sym_fire_statue_collected__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("fire_statue_collected", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_fire_statue_collected, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_fire_statue_collected__);
}

// File Line: 1662
// RVA: 0x1571220
__int64 UFG::_dynamic_initializer_for__sym_evidence_bag__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("evidence_bag", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_evidence_bag, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_evidence_bag__);
}

// File Line: 1663
// RVA: 0x1571260
__int64 UFG::_dynamic_initializer_for__sym_evidence_bag_collected__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("evidence_bag_collected", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_evidence_bag_collected, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sym_evidence_bag_collected__);
}

// File Line: 1671
// RVA: 0x60A0D0
_BOOL8 __fastcall UFG::UIHKScreenWorldMap::SetUpLegend(
        UFG::UIHKScreenWorldMap *this,
        UFG::qArray<UFG::qSymbolUC,0> *blipTypes,
        bool deleteAllExistingLegendItems)
{
  UFG::qSymbolUC *p; // rcx
  UFG::UIMapBlipManager *v6; // rdi
  bool v7; // r14
  UFG::qSymbolUC *v8; // rbx
  unsigned int v9; // r15d
  unsigned int i; // edx
  int v11; // ebx
  UFG::UIHKScreenWorldMap::eViewType mViewType; // ecx
  __int32 v13; // ecx
  __int32 v14; // ecx
  __int32 v15; // ecx
  const char *v16; // r8
  const char *v17; // rdx
  UFG::qStaticSymbolUC *v18; // r9
  unsigned int size; // eax
  int v20; // ebx
  unsigned int v21; // ebx
  unsigned int capacity; // eax
  unsigned int v23; // ebx

  if ( deleteAllExistingLegendItems )
    UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&this->mLegendItems);
  p = blipTypes->p;
  v6 = UFG::UIHKScreenHud::mIconManager;
  v7 = 0;
  if ( p )
  {
    v8 = p - 1;
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v8);
  }
  v9 = 1;
  blipTypes->p = 0i64;
  *(_QWORD *)&blipTypes->size = 0i64;
  for ( i = 1; i < 0x3C; i *= 2 )
    ;
  if ( i - 60 > 0x10000 )
    i = 65596;
  UFG::qArray<UFG::qSymbolUC,0>::Reallocate(blipTypes, i, "qArray.Reallocate(Resize)");
  blipTypes->size = 60;
  v11 = 0;
  if ( UFG::UIHKScreenWorldMap::mViewMode )
  {
    if ( UFG::UIHKScreenWorldMap::mViewMode == TRANSIT_VIEW_MODE )
    {
      if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_case_start)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_case_start) )
      {
        blipTypes->p->mUID = UFG::sym_case_start.mUID;
        v11 = 1;
        UFG::UIHKScreenWorldMap::AddLegendItem(this, "case_start", "$MAP_LEGEND_CASE_START");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_mission_start)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_mission_start) )
      {
        blipTypes->p[v11++].mUID = UFG::sym_mission_start.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(this, "mission_start", "$MAP_LEGEND_MISSION_START");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_parking_symbol)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_parking_symbol) )
      {
        blipTypes->p[v11++].mUID = UFG::sym_parking_symbol.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(this, "parking_symbol", "$MAP_LEGEND_PARKING_LOT");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_parking_objective)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_parking_objective) )
      {
        blipTypes->p[v11++].mUID = UFG::sym_parking_objective.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(this, "parking_objective", "$MAP_LEGEND_PARKING_LOT");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_bus_stop)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_bus_stop) )
      {
        blipTypes->p[v11++].mUID = UFG::sym_bus_stop.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(this, "bus_stop", "$MAP_LEGEND_BUS_STOP");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_store_clothing)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_store_clothing) )
      {
        blipTypes->p[v11++].mUID = UFG::sym_store_clothing.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(this, "store_clothing", "$MAP_LEGEND_CLOTHING_STORE");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_store_exotic_clothing)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_store_exotic_clothing) )
      {
        blipTypes->p[v11++].mUID = UFG::sym_store_exotic_clothing.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(this, "store_exotic_clothing", "$LEGENDARY_OUTFITS_NO_COLOR");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_store_vehicle)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_store_vehicle) )
      {
        blipTypes->p[v11++].mUID = UFG::sym_store_vehicle.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(this, "store_vehicle", "$MAP_LEGEND_VEHICLE_STORE");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_martial_arts)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_martial_arts) )
      {
        blipTypes->p[v11++].mUID = UFG::sym_martial_arts.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(this, "martial_arts", "$MAP_LEGEND_MARTIAL_ARTS");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_martial_arts_objective)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_martial_arts_objective) )
      {
        blipTypes->p[v11++].mUID = UFG::sym_martial_arts_objective.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(this, "martial_arts_objective", "$MAP_LEGEND_MARTIAL_ARTS");
      }
      this->mTransitEnableBackButton = 1;
      UFG::UIHKScreenWorldMap::ShowHelpBar(this);
    }
    goto LABEL_363;
  }
  mViewType = this->mViewType;
  if ( mViewType == BASIC_VIEW )
  {
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_cop_symbol)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_cop_symbol) )
    {
      blipTypes->p->mUID = UFG::sym_cop_symbol.mUID;
      v11 = 1;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "cop_symbol", "$MAP_LEGEND_POLICE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_cop_foot_symbol)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_cop_foot_symbol) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_cop_foot_symbol.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "cop_foot_symbol", "$MAP_LEGEND_POLICE_FOOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_cop_foot_patrol_symbol)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_cop_foot_patrol_symbol) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_cop_foot_patrol_symbol.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "cop_foot_patrol_symbol", "$MAP_LEGEND_POLICE_FOOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_cop_vehicle_patrol_symbol)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_cop_vehicle_patrol_symbol) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_cop_vehicle_patrol_symbol.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "cop_vehicle_patrol_symbol", "$MAP_LEGEND_POLICE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_roadblock_symbol)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_roadblock_symbol) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_roadblock_symbol.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "roadblock_symbol", "$MAP_LEGEND_ROADBLOCK");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_hiding_spot)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_hiding_spot) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_hiding_spot.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "hiding_spot", "$MAP_LEGEND_HIDING_SPOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_hiding_spot_garage)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_hiding_spot_garage) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_hiding_spot_garage.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "hiding_spot_garage", "$MAP_LEGEND_HIDING_SPOT_GARAGE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_witness_symbol)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_witness_symbol) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_witness_symbol.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "witness_symbol", "$MAP_LEGEND_WITNESS");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_friendly)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_friendly) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_friendly.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "friendly", "$MAP_LEGEND_FRIENDLY");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_enemy)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_enemy) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_enemy.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "enemy", "$MAP_LEGEND_ENEMY");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_enemy_noncombat)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_enemy_noncombat) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_enemy_noncombat.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "enemy_noncombat", "$MAP_LEGEND_ENEMY");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_contact)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_contact) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_contact.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "contact", "$MAP_LEGEND_CONTACT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_social)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_social) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_social.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "social", "$MAP_LEGEND_SOCIAL");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_social_ambient)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_social_ambient) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_social_ambient.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "social_ambient", "$MAP_LEGEND_SOCIAL");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_social_mission)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_social_mission) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_social_mission.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "social_mission", "$MAP_LEGEND_SOCIAL");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_case_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_case_start) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_case_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "case_start", "$MAP_LEGEND_CASE_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_case_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_case_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_case_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "case_objective", "$MAP_LEGEND_CASE_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_face_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_face_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_face_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "face_objective", "$MAP_LEGEND_SOCIAL");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_mission_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_mission_start) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_mission_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "mission_start", "$MAP_LEGEND_MISSION_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_mission_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_mission_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_mission_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "mission_objective", "$MAP_LEGEND_MISSION_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_race_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_race_start) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_race_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "race_start", "$MAP_LEGEND_RACE_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_race_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_race_start) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_race_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "race_start_flag", "$MAP_LEGEND_RACE_START_FLAG");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_race_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_race_start) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_race_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "race_end", "$MAP_LEGEND_RACE_END");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_race_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_race_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_race_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "race_objective", "$MAP_LEGEND_RACE_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_cop_event_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_cop_event_start) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_cop_event_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "cop_event_start", "$MAP_LEGEND_EVENT_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_event_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_event_start) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_event_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "event_start", "$MAP_LEGEND_EVENT_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_event_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_event_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_event_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "event_objective", "$MAP_LEGEND_EVENT_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_job_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_job_start) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_job_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "job_start", "$MAP_LEGEND_JOB_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_job_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_job_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_job_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "job_objective", "$MAP_LEGEND_JOB_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_enemy_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_enemy_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_enemy_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "enemy_objective", "$MAP_LEGEND_ENEMY_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_cop_job)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_cop_job) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_cop_job.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "cop_job", "$MAP_LEGEND_COP_JOB");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_cop_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_cop_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_cop_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "cop_objective", "$MAP_LEGEND_COP_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_transterror_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_transterror_start) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_transterror_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "transterror_start", "$MAP_LEGEND_DLC_10");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_transterror_mission)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_transterror_mission) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_transterror_mission.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "transterror_mission", "$MAP_LEGEND_JOB_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_transterror_event)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_transterror_event) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_transterror_event.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "transterror_event", "$MAP_LEGEND_JOB_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_zodiac_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_zodiac_start) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_zodiac_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "zodiac_start", "$MAP_LEGEND_DLC_04");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_zodiac_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_zodiac_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_zodiac_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "zodiac_objective", "$MAP_LEGEND_JOB_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_zodiac_event)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_zodiac_event) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_zodiac_event.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "zodiac_event", "$MAP_LEGEND_EVENT_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_zodiac_event)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_zodiac_event) )
    {
      v18 = (UFG::qStaticSymbolUC *)&blipTypes->p[v11++];
      v18->mUID = UFG::sym_zodiac_event.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "zodiac_event", "$MAP_LEGEND_EVENT_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_zodiac_enemy)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_zodiac_enemy) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_zodiac_enemy.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "zodiac_enemy", "$MAP_LEGEND_ENEMY");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_zodiac_friendly)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_zodiac_friendly) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_zodiac_friendly.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "zodiac_friendly", "$MAP_LEGEND_FRIENDLY");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_ghost_elite_ghoul)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_ghost_elite_ghoul) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_ghost_elite_ghoul.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "ghost_elite_ghoul", "$MAP_LEGEND_DLC_02");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_ghost_lesser_ghoul)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_ghost_lesser_ghoul) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_ghost_lesser_ghoul.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "ghost_lesser_ghoul", "$MAP_LEGEND_DLC_01");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_ghost_trapped_ped)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_ghost_trapped_ped) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_ghost_trapped_ped.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "ghost_trapped_ped", "$MAP_LEGEND_DLC_03");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_crime_scene)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_crime_scene) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_crime_scene.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "crime_scene", "$MAP_LEGEND_CRIME_SCENE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_safe_house)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_safe_house) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_safe_house.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "safe_house", "$MAP_LEGEND_SAFEHOUSE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_safe_house_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_safe_house_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_safe_house_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "safe_house_objective", "$MAP_LEGEND_SAFEHOUSE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_safe_house_unlocked)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_safe_house_unlocked) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_safe_house_unlocked.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "safe_house_unlocked", "$MAP_LEGEND_SAFEHOUSE_UNLOCKED");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_undercover_safe_house)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_undercover_safe_house) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_undercover_safe_house.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "undercover_safe_house", "$MAP_LEGEND_UNDERCOVER_SAFEHOUSE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_triad_war)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_triad_war) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_triad_war.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "triad_war", "$MAP_LEGEND_DRUG_BUST");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_date_character)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_date_character) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_date_character.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "date_character", "$MAP_LEGEND_SOCIAL");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_face_character)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_face_character) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_face_character.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "face_character", "$MAP_LEGEND_FAVOUR");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_waypoint)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_waypoint) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_waypoint.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "waypoint", "$MAP_LEGEND_WAYPOINT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_player_car)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_player_car) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_player_car.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "player_car", "Car");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_parking_symbol)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_parking_symbol) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_parking_symbol.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "parking_symbol", "$MAP_LEGEND_PARKING_LOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_parking_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_parking_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_parking_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "parking_objective", "$MAP_LEGEND_PARKING_LOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_ferry)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_ferry) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_ferry.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "ferry", "$MAP_LEGEND_FERRY");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_bus_stop)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_bus_stop) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_bus_stop.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "bus_stop", "$MAP_LEGEND_BUS_STOP");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_store_clothing)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_store_clothing) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_store_clothing.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "store_clothing", "$MAP_LEGEND_CLOTHING_STORE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_store_clothing_indoors)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_store_clothing_indoors) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_store_clothing_indoors.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "store_clothing_indoors", "$MAP_LEGEND_CLOTHING_STORE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_store_exotic_clothing)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_store_exotic_clothing) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_store_exotic_clothing.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "store_exotic_clothing", "$LEGENDARY_OUTFITS_NO_COLOR");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_store_convenience)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_store_convenience) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_store_convenience.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "store_convenience", "$MAP_LEGEND_CONVENIENCE_STORE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_store_apothecary)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_store_apothecary) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_store_apothecary.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "store_apothecary", "$MAP_LEGEND_APOTHECARY_STORE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_store_vehicle)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_store_vehicle) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_store_vehicle.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "store_vehicle", "$MAP_LEGEND_VEHICLE_STORE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_store_social)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_store_social) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_store_social.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "store_social", "$MAP_LEGEND_PORK_BUN");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_store_gambling)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_store_gambling) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_store_gambling.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "store_gambling", "$MAP_LEGEND_GAMBLING_DEN");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_drunken_dice)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_drunken_dice) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_drunken_dice.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "drunken_dice", "$MAP_LEGEND_DRUNKEN_DICE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_karaoke)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_karaoke) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_karaoke.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "karaoke", "$MAP_LEGEND_KARAOKE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_cock_fighting)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_cock_fighting) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_cock_fighting.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "cock_fighting", "$MAP_LEGEND_COCK_FIGHTING");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_fight_club)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_fight_club) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_fight_club.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "fight_club", "$MAP_LEGEND_MARTIAL_ARTS_CLUB");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_store_massage)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_store_massage) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_store_massage.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "store_massage", "$MAP_LEGEND_MASSAGE_PARLOR");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_outdoor_massage)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_outdoor_massage) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_outdoor_massage.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "outdoor_massage", "$MAP_LEGEND_MASSAGE_PARLOR");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_martial_arts)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_martial_arts) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_martial_arts.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "martial_arts", "$MAP_LEGEND_MARTIAL_ARTS");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_martial_arts_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_martial_arts_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_martial_arts_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "martial_arts_objective", "$MAP_LEGEND_MARTIAL_ARTS");
    }
    if ( !UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_hijack)
      || !(unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_hijack) )
    {
      goto LABEL_362;
    }
    v16 = "$MAP_LEGEND_HIJACK";
    blipTypes->p[v11].mUID = UFG::sym_hijack.mUID;
    v17 = "hijack";
LABEL_361:
    ++v11;
    UFG::UIHKScreenWorldMap::AddLegendItem(this, v17, v16);
LABEL_362:
    v7 = v11 != 0;
    goto LABEL_363;
  }
  v13 = mViewType - 1;
  if ( !v13 )
  {
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_case_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_case_start) )
    {
      blipTypes->p->mUID = UFG::sym_case_start.mUID;
      v11 = 1;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "case_start", "$MAP_LEGEND_CASE_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_case_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_case_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_case_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "case_objective", "$MAP_LEGEND_CASE_OBJECTIVE");
    }
    if ( !UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_waypoint)
      || !(unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_waypoint) )
    {
      goto LABEL_362;
    }
    v16 = "$MAP_LEGEND_WAYPOINT";
    blipTypes->p[v11].mUID = UFG::sym_waypoint.mUID;
    v17 = "waypoint";
    goto LABEL_361;
  }
  v14 = v13 - 1;
  if ( !v14 )
  {
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_race_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_race_start) )
    {
      blipTypes->p->mUID = UFG::sym_race_start.mUID;
      v11 = 1;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "race_start", "$MAP_LEGEND_RACE_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_race_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_race_start) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_race_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "race_start_flag", "$MAP_LEGEND_RACE_START_FLAG");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_race_start)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_race_start) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_race_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "race_end", "$MAP_LEGEND_RACE_END");
    }
    if ( !UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_race_objective)
      || !(unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_race_objective) )
    {
      goto LABEL_362;
    }
    v16 = "$MAP_LEGEND_RACE_OBJECTIVE";
    blipTypes->p[v11].mUID = UFG::sym_race_objective.mUID;
    v17 = "race_objective";
    goto LABEL_361;
  }
  v15 = v14 - 1;
  if ( !v15 )
  {
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_security_camera)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_security_camera) )
    {
      blipTypes->p->mUID = UFG::sym_security_camera.mUID;
      v11 = 1;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "security_camera", "$MAP_LEGEND_SECURITY_CAMERA");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_security_camera_collected)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_security_camera_collected) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_security_camera_collected.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "security_camera_collected", "$MAP_LEGEND_COLLECTED_SECURITY_CAMERA");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_shrine)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_shrine) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_shrine.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "shrine", "$MAP_LEGEND_HEALTH_SHRINE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_shrine_collected)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_shrine_collected) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_shrine_collected.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "shrine_collected", "$MAP_LEGEND_COLLECTED_HEALTH_SHRINE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_lockbox)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_lockbox) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_lockbox.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "lockbox", "$MAP_LEGEND_LOCKBOX");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_lockbox_collected)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_lockbox_collected) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_lockbox_collected.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "lockbox_collected", "$MAP_LEGEND_LOCK_COLLECTED");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_hiding_spot)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_hiding_spot) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_hiding_spot.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "hiding_spot", "$MAP_LEGEND_HIDING_SPOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_hiding_spot_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_hiding_spot_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_hiding_spot_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "hiding_spot_objective", "$MAP_LEGEND_HIDING_SPOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_hiding_spot_garage)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_hiding_spot_garage) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_hiding_spot_garage.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "hiding_spot_garage", "$MAP_LEGEND_VEHICLE_HIDING_SPOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_hiding_spot_garage_objective)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_hiding_spot_garage_objective) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_hiding_spot_garage_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "hiding_spot_garage_objective", "$MAP_LEGEND_VEHICLE_HIDING_SPOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_tourist_photo)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_tourist_photo) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_tourist_photo.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "tourist_photo", "$MAP_LEGEND_TOURIST_PHOTO");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_tape_recorder)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_tape_recorder) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_tape_recorder.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "tape_recorder", "$MAP_LEGEND_TAPE_RECORDER");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_bug)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_bug) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_bug.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "bug", "$MAP_LEGEND_BUG");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_melee_upgrade)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_melee_upgrade) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_melee_upgrade.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "melee_upgrade", "$MAP_LEGEND_MELEE_UPGRADE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_ghost_orb)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_ghost_orb) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_ghost_orb.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "ghost_orb", "$MAP_LEGEND_DLC_COLL_01");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_ghost_orb_collected)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_ghost_orb_collected) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_ghost_orb_collected.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "ghost_orb_collected", "$MAP_LEGEND_DLC_COLL_01");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_fire_statue)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_fire_statue) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_fire_statue.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "fire_statue", "$MAP_LEGEND_DLC_COLL_02");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_fire_statue_collected)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_fire_statue_collected) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_fire_statue_collected.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "fire_statue_collected", "$MAP_LEGEND_DLC_COLL_02");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_evidence_bag)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_evidence_bag) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_evidence_bag.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "evidence_bag", "$MAP_LEGEND_DLC_COLL_03");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_evidence_bag_collected)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_evidence_bag_collected) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_evidence_bag_collected.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "evidence_bag_collected", "$MAP_LEGEND_DLC_COLL_03");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_waypoint)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_waypoint) )
    {
      blipTypes->p[v11++].mUID = UFG::sym_waypoint.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "waypoint", "$MAP_LEGEND_WAYPOINT");
    }
    this->mCurrentViewHasGPS = 1;
    UFG::UITiledMapGPS::PopulateWorldMap(UFG::UIHKScreenHud::GPS, &this->GPS);
    UFG::UIHKWorldMapCollectiblesStatsWidget::Populate(&this->CollectiblesStats, this);
    goto LABEL_362;
  }
  if ( v15 == 1 )
  {
    if ( UFG::UIMapBlipManager::HasBlipType(v6, &UFG::sym_triad_war)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow(&UFG::sym_triad_war) )
    {
      blipTypes->p->mUID = UFG::sym_triad_war.mUID;
      v11 = 1;
      UFG::UIHKScreenWorldMap::AddLegendItem(this, "triad_war", "$MAP_LEGEND_EVENT_START");
    }
    v7 = 1;
  }
LABEL_363:
  size = blipTypes->size;
  v20 = v11 - blipTypes->size;
  if ( v20 <= 0 )
  {
    v23 = -v20;
    if ( v23 )
    {
      if ( v23 < size )
        blipTypes->size = size - v23;
      else
        blipTypes->size = 0;
    }
  }
  else
  {
    v21 = size + v20;
    capacity = blipTypes->capacity;
    if ( v21 > capacity )
    {
      if ( capacity )
        v9 = 2 * capacity;
      for ( ; v9 < v21; v9 *= 2 )
        ;
      if ( v9 <= 4 )
        v9 = 4;
      if ( v9 - v21 > 0x10000 )
        v9 = v21 + 0x10000;
      UFG::qArray<UFG::qSymbolUC,0>::Reallocate(blipTypes, v9, "qArray.Reallocate(Resize)");
    }
    blipTypes->size = v21;
  }
  return v7;
} v9, "qArray.Reallocate(Resize)");
    }
    blipTypes->size = v21;
  }
  return v7;
}

// File Line: 1905
// RVA: 0x60C4E0
void __fastcall UFG::UIHKScreenWorldMap::SetUpObjectiveView(UFG::UIHKScreenWorldMap *this)
{
  UFG::ProgressionTracker *v2; // rax
  UFG::Objective *FirstObjective; // rax

  v2 = UFG::ProgressionTracker::Instance();
  FirstObjective = UFG::ObjectiveTracker::GetFirstObjective(&v2->mObjectiveTracker);
  if ( FirstObjective && FirstObjective->mpGameSlice->mState == STATE_STARTED )
  {
    UFG::UIHKWorldMapObjectivesWidget::Flash_SetTitle(&this->ObjectivesWidget, this, "$worldmap_objectives_caps");
    UFG::UIHKScreenWorldMap::DisplayObjectives(this);
    UFG::UIHKScreenWorldMap::DisplaySecondaryObjectives(this);
  }
  else
  {
    UFG::UIHKWorldMapObjectivesWidget::Flash_SetTitle(&this->ObjectivesWidget, this, "$worldmap_avail_missions");
    UFG::UIHKScreenWorldMap::DisplayMissions(this);
  }
}

// File Line: 1949
// RVA: 0x5D6BE0
void __fastcall UFG::UIHKScreenWorldMap::DisplayObjectives(UFG::UIHKScreenWorldMap *this)
{
  UFG::ProgressionTracker *v2; // rbp
  int v3; // esi
  UFG::Objective *FirstObjective; // rbx
  UFG::UIHKWorldMapObjectivesWidget *p_ObjectivesWidget; // rcx
  const char *v6; // rdx
  UFG::UIHKWorldMapObjectivesWidget::eState mState; // eax

  UFG::UIScreen::invoke(this, "Objectives_Clear");
  v2 = UFG::ProgressionTracker::Instance();
  v3 = 0;
  FirstObjective = UFG::ObjectiveTracker::GetFirstObjective(&v2->mObjectiveTracker);
  if ( !FirstObjective )
    goto LABEL_12;
  do
  {
    if ( (int)UFG::qStringLength(FirstObjective->mCaption.mData) >= 1 )
    {
      ++v3;
      UFG::UIHKWorldMapObjectivesWidget::Flash_AddObjective(
        &this->ObjectivesWidget,
        this,
        FirstObjective->mCaption.mData,
        FirstObjective->mStatus == STATUS_COMPLETED);
    }
    FirstObjective = UFG::ObjectiveTracker::GetNextObjective(&v2->mObjectiveTracker, FirstObjective);
  }
  while ( FirstObjective );
  if ( !v3 || this->mViewType == COLLECTIBLES_VIEW || UFG::UIHKScreenWorldMap::mViewMode == TRANSIT_VIEW_MODE )
  {
LABEL_12:
    mState = this->ObjectivesWidget.mState;
    this->ObjectivesWidget.mbToggleDisabled = 1;
    if ( (unsigned int)mState > STATE_NORMAL )
      return;
    this->ObjectivesWidget.mbIsHiding = 1;
    this->ObjectivesWidget.mState = STATE_DANGER;
    v6 = "Objectives_Hide";
  }
  else
  {
    p_ObjectivesWidget = &this->ObjectivesWidget;
    if ( v3 <= 0 )
    {
      UFG::UIHKWorldMapObjectivesWidget::Flash_CleanObjective(p_ObjectivesWidget, this, v3);
    }
    else
    {
      UFG::UIHKWorldMapObjectivesWidget::UnHide(p_ObjectivesWidget, this);
      UFG::UIHKWorldMapObjectivesWidget::Flash_CleanObjective(&this->ObjectivesWidget, this, v3);
    }
    v6 = "Objectives_Resize";
  }
  UFG::UIScreen::invoke(this, v6);
}

// File Line: 1991
// RVA: 0x5D6860
void __fastcall UFG::UIHKScreenWorldMap::DisplayMissions(UFG::UIHKScreenWorldMap *this)
{
  UFG::ProgressionTracker *v2; // r15
  int v3; // esi
  UFG::Objective *FirstObjective; // rdi
  UFG::GameSlice *mpGameSlice; // rax
  Render::SkinningCacheNode *FirstIndicator; // rax
  const char *v7; // r14
  UFG::UIMapBlipTypeManager *Instance; // rax
  UFG::UIHKMinimapBlipType *Type; // rbp
  const char *v10; // rdx
  UFG::UIHKWorldMapObjectivesWidget::eState mState; // eax
  UFG::UIHKWorldMapPerkGoalsWidget::eState v12; // eax
  Scaleform::GFx::Movie *pObject; // rcx
  UFG::qSymbolUC result; // [rsp+50h] [rbp+8h] BYREF

  UFG::UIScreen::invoke(this, "Objectives_Clear");
  v2 = UFG::ProgressionTracker::Instance();
  v3 = 0;
  FirstObjective = UFG::ObjectiveTracker::GetFirstObjective(&v2->mObjectiveTracker);
  if ( !FirstObjective )
    goto LABEL_20;
  do
  {
    mpGameSlice = FirstObjective->mpGameSlice;
    if ( mpGameSlice && (unsigned int)(mpGameSlice->mType - 10) <= 1 )
    {
      if ( FirstObjective->mUsesPDA )
      {
        ++v3;
        UFG::UIHKWorldMapObjectivesWidget::Flash_AddMission(
          &this->ObjectivesWidget,
          this,
          FirstObjective->mCaption.mData,
          &customCaption);
      }
      FirstIndicator = UFG::Objective::GetFirstIndicator(FirstObjective);
      if ( FirstIndicator )
      {
        v7 = (const char *)FirstIndicator[1].mNode.mChild[0];
        UFG::qSymbolUC::create_from_string(&result, v7);
        Instance = UFG::UIMapBlipTypeManager::getInstance();
        Type = UFG::UIMapBlipTypeManager::GetType(Instance, &result);
        if ( UFG::UIMapBlipManager::HasBlipType(&this->mMinimapIconManagerClone, &result) )
        {
          if ( Type && Type->IsObjective )
          {
            ++v3;
            UFG::UIHKWorldMapObjectivesWidget::Flash_AddMission(
              &this->ObjectivesWidget,
              this,
              FirstObjective->mCaption.mData,
              v7);
          }
        }
      }
    }
    FirstObjective = UFG::ObjectiveTracker::GetNextObjective(&v2->mObjectiveTracker, FirstObjective);
  }
  while ( FirstObjective );
  if ( v3 && UFG::UIHKScreenWorldMap::mViewMode != TRANSIT_VIEW_MODE )
  {
    if ( v3 > 0 )
    {
      this->ObjectivesWidget.mbToggleDisabled = 0;
      if ( this->ObjectivesWidget.mbIsHiding )
      {
        this->ObjectivesWidget.mbIsHiding = 0;
        if ( (unsigned int)(this->ObjectivesWidget.mState - 2) <= 1 )
        {
          this->ObjectivesWidget.mState = STATE_INVALID;
          UFG::UIScreen::invoke(this, "Objectives_Show");
        }
        *(_WORD *)&this->ObjectivesWidget.mbIsHiding = 0;
      }
    }
    v10 = "Objectives_Resize";
  }
  else
  {
LABEL_20:
    mState = this->ObjectivesWidget.mState;
    this->ObjectivesWidget.mbToggleDisabled = 1;
    if ( (unsigned int)mState > STATE_NORMAL )
      goto LABEL_23;
    this->ObjectivesWidget.mbIsHiding = 1;
    this->ObjectivesWidget.mState = STATE_DANGER;
    v10 = "Objectives_Hide";
  }
  UFG::UIScreen::invoke(this, v10);
LABEL_23:
  v12 = this->PerkGoalsWidget.mState;
  this->PerkGoalsWidget.mbToggleDisabled = 1;
  if ( (unsigned int)v12 <= STATE_NORMAL )
  {
    this->PerkGoalsWidget.mbIsHiding = 1;
    this->PerkGoalsWidget.mState = STATE_DANGER;
    pObject = this->mRenderable->m_movie.pObject;
    if ( pObject )
      Scaleform::GFx::Movie::Invoke(pObject, "PerkGoals_Hide", 0i64, 0i64, 0);
  }
}

// File Line: 2048
// RVA: 0x5D6D20
void __fastcall UFG::UIHKScreenWorldMap::DisplaySecondaryObjectives(UFG::UIHKScreenWorldMap *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  int v3; // esi
  UFG::ProgressionTracker *v4; // rdi
  UFG::SecondaryObjectiveTracker *Objective; // r10
  UFG::SecondaryObjectiveTracker *v6; // r8
  Scaleform::GFx::Movie *v7; // rcx
  const char *v8; // rdx
  UFG::UIHKWorldMapPerkGoalsWidget::eState mState; // eax

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "PerkGoals_Clear", 0i64, 0i64, 0);
  v3 = 0;
  v4 = UFG::ProgressionTracker::Instance();
  Objective = UFG::SecondaryObjectiveTracker::GetObjective(&v4->mSecondaryObjectiveTracker, ID_COP_OBJECTIVE);
  if ( Objective->mObjectives[0].mStatus && Objective->mObjectives[0].mCaption.mLength )
  {
    v3 = 1;
    UFG::UIHKWorldMapPerkGoalsWidget::Flash_AddGoal(
      &this->PerkGoalsWidget,
      this,
      Objective->mObjectives[0].mCaption.mData,
      Objective->mObjectives[0].mStatus == STATUS_HIGHLIGHT,
      Objective->mObjectives[0].mStatus == STATUS_COMPLETED,
      Objective->mObjectives[0].mProgress,
      Objective->mObjectives[0].mMaxProgress);
  }
  v6 = UFG::SecondaryObjectiveTracker::GetObjective(&v4->mSecondaryObjectiveTracker, ID_TRIAD_OBJECTIVE);
  if ( v6->mObjectives[0].mStatus && v6->mObjectives[0].mCaption.mLength )
  {
    ++v3;
    UFG::UIHKWorldMapPerkGoalsWidget::Flash_AddGoal(
      &this->PerkGoalsWidget,
      this,
      v6->mObjectives[0].mCaption.mData,
      v6->mObjectives[0].mStatus == STATUS_HIGHLIGHT,
      v6->mObjectives[0].mStatus == STATUS_COMPLETED,
      v6->mObjectives[0].mProgress,
      v6->mObjectives[0].mMaxProgress);
  }
  if ( v3 && this->mViewType != COLLECTIBLES_VIEW )
  {
    UFG::UIHKWorldMapPerkGoalsWidget::UnHide(&this->PerkGoalsWidget, this);
    v7 = this->mRenderable->m_movie.pObject;
    if ( !v7 )
      return;
    v8 = "PerkGoals_Resize";
    goto LABEL_16;
  }
  mState = this->PerkGoalsWidget.mState;
  this->PerkGoalsWidget.mbToggleDisabled = 1;
  if ( (unsigned int)mState <= STATE_NORMAL )
  {
    this->PerkGoalsWidget.mbIsHiding = 1;
    this->PerkGoalsWidget.mState = STATE_DANGER;
    v7 = this->mRenderable->m_movie.pObject;
    if ( v7 )
    {
      v8 = "PerkGoals_Hide";
LABEL_16:
      Scaleform::GFx::Movie::Invoke(v7, v8, 0i64, 0i64, 0);
    }
  }
}

// File Line: 2100
// RVA: 0x5ED1C0
void __fastcall UFG::UIHKScreenWorldMap::HighlightCurrentObjectiveBlip(UFG::UIHKScreenWorldMap *this)
{
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::UIHKPlayerObjective *CurrentObjective; // rax
  UFG::qBaseTreeRB *CollisionModel; // rax
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(pObject, "mc_ObjectiveHighlight._visible", &value, 1i64);
    UFG::UIMapBlipManager::ResetObjectiveHighlight(&this->mMinimapIconManagerClone);
    if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    {
      CurrentObjective = UFG::UIHKPlayerObjectiveManager::GetCurrentObjective(UFG::UIHKPlayerObjectiveManager::mInstance);
      if ( CurrentObjective )
      {
        if ( CurrentObjective->minimapBlips.size )
        {
          CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(
                             (UFG::BasePhysicsSystem *)&this->mMinimapIconManagerClone,
                             *CurrentObjective->minimapBlips.p);
          if ( CollisionModel )
            BYTE2(CollisionModel->mNULL.mParent) = 1;
        }
      }
    }
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 2131
// RVA: 0x611410
void __fastcall UFG::UIHKScreenWorldMap::ShowTutorialPopup(UFG::UIHKScreenWorldMap *this)
{
  UFG::GameStat::MapBoolStat MapBoolStatEnum; // edi
  UFG::GameStatTracker *v3; // rax
  UFG::GameStatTracker *v4; // rax
  unsigned int v5; // edx
  UFG::qSymbol name; // [rsp+48h] [rbp+10h] BYREF
  UFG::qSymbol result; // [rsp+50h] [rbp+18h] BYREF

  UFG::qSymbol::create_from_string(&result, "DynamicTutorials");
  UFG::qSymbol::create_from_string(&name, "MapTutorial");
  MapBoolStatEnum = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&result, 1);
  v3 = UFG::GameStatTracker::Instance();
  if ( !UFG::GameStatTracker::GetStat(v3, MapBoolStatEnum, &name) )
  {
    v4 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v4, MapBoolStatEnum, &name, 1);
    if ( qSymbol_Default_20.mUID != qSymbol_Collectible_HealthShrine_20.mUID )
    {
      if ( qSymbol_Default_20.mUID == qSymbol_Collectible_LockBox_20.mUID )
      {
        if ( UFG::HudAudio::m_instance )
        {
          v5 = 912326249;
LABEL_14:
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v5, 0i64, 0, 0i64);
        }
      }
      else if ( qSymbol_Default_20.mUID == qSymbol_Upgrade_Melee_20.mUID )
      {
        if ( UFG::HudAudio::m_instance )
        {
          v5 = -1311300124;
          goto LABEL_14;
        }
      }
      else if ( qSymbol_Default_20.mUID == qSymbol_Collectible_Jump_20.mUID )
      {
        if ( UFG::HudAudio::m_instance )
        {
          v5 = -9771139;
          goto LABEL_14;
        }
      }
      else if ( UFG::HudAudio::m_instance )
      {
        v5 = -952868575;
        goto LABEL_14;
      }
    }
    this->TutorialPopup.mChanged = 1;
    UFG::qString::Set(&this->TutorialPopup.mCaption, "$WORLDMAP_TUTORIAL_01");
    this->TutorialPopup.mType.mUID = qSymbol_Default_20.mUID;
    this->TutorialPopup.mPosition = POSITION_DEFAULT;
    this->TutorialPopup.mTimeout = 30.0;
    *(_WORD *)&this->TutorialPopup.mInfinite = 0;
    this->TutorialPopup.mState = STATE_ROOT_MENU;
  }
}

// File Line: 2146
// RVA: 0x605E60
void __fastcall UFG::UIHKScreenWorldMap::SetGPSDestination(UFG::UIHKScreenWorldMap *this, UFG::qVector3 *worldPos)
{
  float x; // xmm6_4
  float y; // xmm7_4
  UFG::UIHKPlayerObjective *mSelectedObjective; // rsi
  float ApproxAltitude; // xmm0_4
  UFG::UIHKPlayerObjectiveManager *v7; // rbx
  bool v8; // r14
  bool v9; // zf
  UFG::UIHKObjectiveFlasherWidget::eState v10; // eax
  UFG::qVector3 pos; // [rsp+20h] [rbp-40h] BYREF
  UFG::qColour color; // [rsp+30h] [rbp-30h] BYREF

  x = worldPos->x;
  color.r = UFG::UITiledMapWidget::DefaultGPSLineColor.r;
  y = worldPos->y;
  pos.z = FLOAT_N1001_0;
  pos.x = x;
  color.g = UFG::UITiledMapWidget::DefaultGPSLineColor.g;
  mSelectedObjective = 0i64;
  pos.y = y;
  color.b = UFG::UITiledMapWidget::DefaultGPSLineColor.b;
  color.a = UFG::UITiledMapWidget::DefaultGPSLineColor.a;
  if ( this->Cursor.mIsOpen )
  {
    mSelectedObjective = this->Cursor.mSelectedObjective;
    color = this->Cursor.mSelectedBlipColor;
  }
  ApproxAltitude = UFG::UITiledMapGPS::GetApproxAltitude(&pos);
  v7 = UFG::UIHKPlayerObjectiveManager::mInstance;
  v8 = 0;
  if ( !UFG::UIHKPlayerObjectiveManager::mInstance )
    goto LABEL_15;
  if ( !mSelectedObjective )
  {
    v9 = !UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjective_IsSet;
    UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjectiveColor.r = color.r;
    v7->mWorldMapObjectiveColor.g = color.g;
    v7->mWorldMapObjectiveColor.b = color.b;
    v7->mWorldMapObjectiveColor.a = color.a;
    if ( v9
      || !v7->mWorldMapObjective.useFixedPos
      || (float)((float)((float)(y - v7->mWorldMapObjective.fixedPos.y) * (float)(y - v7->mWorldMapObjective.fixedPos.y))
               + (float)((float)(x - v7->mWorldMapObjective.fixedPos.x) * (float)(x - v7->mWorldMapObjective.fixedPos.x))) >= 4.0 )
    {
      *(_WORD *)&v7->mTempObjectiveSelected = 256;
      v7->mWorldMapObjective.fixedPos.x = x;
      v7->mWorldMapObjective.fixedPos.y = y;
      v7->mWorldMapObjective.fixedPos.z = ApproxAltitude;
      v7->mWorldMapObjective.useFixedPos = 1;
      v7->mWorldMapObjective_IsSelected = 1;
      UFG::qString::Set(&v7->mWorldMapObjective.alternateCaption, "$WORLD_MAP_MANUAL_DEST");
    }
    else
    {
      *(_WORD *)&v7->mWorldMapObjective_IsSet = 0;
    }
    v8 = 1;
    if ( v7->mWorldMapObjective_IsSet )
      goto LABEL_12;
LABEL_15:
    UFG::UITiledMapGPS::SetActive(&this->GPS, 0);
    UFG::UITiledMapGPS::SetVisible(&this->GPS, 0);
    UFG::UITiledMapGPS::SetActive(UFG::UIHKScreenHud::GPS, 0);
    UFG::UIHKObjectiveDistanceWidget::Clear(UFG::UIHKScreenHud::ObjectiveDistance);
    return;
  }
  *(_WORD *)&UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjective_IsSet = 0;
  UFG::UIHKPlayerObjectiveManager::FlashObjective(v7, mSelectedObjective->mObjective, 1);
LABEL_12:
  v10 = UFG::UIHKObjectiveFlasherWidget::mState;
  if ( (UFG::UIHKObjectiveFlasherWidget::mState & 0xFFFFFFFB) != 0 )
    v10 = STATE_TEXT_INBOX;
  UFG::UIHKObjectiveFlasherWidget::mState = v10;
  UFG::UITiledMapGPS::SetDestination(&this->GPS, &pos, v8);
  UFG::UITiledMapGPS::SetActive(&this->GPS, 1);
  UFG::UITiledMapGPS::SetVisible(&this->GPS, 1);
  UFG::UITiledMapWidget::SetGPSLineColor(&color);
  UFG::UITiledMapGPS::SetDestination(UFG::UIHKScreenHud::GPS, &pos, v8);
  UFG::UITiledMapGPS::SetActive(UFG::UIHKScreenHud::GPS, 1);
  UFG::UIHKObjectiveFlasherWidget::mColor = color;
}

// File Line: 2228
// RVA: 0x61FDF0
void __fastcall UFG::UIHKScreenWorldMap::customPreRender(UFG::UIHKScreenWorldMap *this, Render::View *view)
{
  UFG::UIHKScreenWorldMap::RenderBackground(this, view);
  if ( this->mTileStreamerLowRes && this->mUseLowResTiles )
    UFG::UIHKScreenWorldMap::RenderLowResMapNative(this, view);
  if ( this->mRacePathState == LOADING )
  {
    if ( UFG::BasePhysicsSystem::GetCollisionModel(
           (UFG::BasePhysicsSystem *)&this->mMinimapIconManagerClone,
           UI_BLIP_RACE_START_20) )
    {
      UFG::UIMapBlipManager::RemoveIcon(&this->mMinimapIconManagerClone, UI_BLIP_RACE_START_20);
    }
    if ( UFG::BasePhysicsSystem::GetCollisionModel(
           (UFG::BasePhysicsSystem *)&this->mMinimapIconManagerClone,
           UI_BLIP_RACE_END_20) )
    {
      UFG::UIMapBlipManager::RemoveIcon(&this->mMinimapIconManagerClone, UI_BLIP_RACE_END_20);
    }
  }
  else
  {
    UFG::UIHKScreenWorldMap::RenderRaceSpline(this, view);
  }
  if ( UFG::UITiledMapGPS::IsVisible(&this->GPS) )
  {
    UFG::UIHKScreenWorldMap::RenderGPSSpline(this, view);
  }
  else if ( UFG::BasePhysicsSystem::GetCollisionModel(
              (UFG::BasePhysicsSystem *)&this->mMinimapIconManagerClone,
              UI_BLIP_GPS_DESTINATION_20) )
  {
    UFG::UIMapBlipManager::RemoveIcon(&this->mMinimapIconManagerClone, UI_BLIP_GPS_DESTINATION_20);
  }
  UFG::UIHKScreenWorldMap::RenderIconsNative(this, view);
}

// File Line: 2363
// RVA: 0x5E9BC0
void __fastcall UFG::UIHKScreenWorldMap::GetViewportScaleMatrix(
        UFG::UIHKScreenWorldMap *this,
        UFG::qMatrix44 *ViewportScaleMatrix)
{
  __int64 v4; // rbx
  __int64 v5; // rdi
  double v6; // xmm0_8
  float v7; // xmm8_4
  __m128 v8; // xmm5
  __m128 v9; // xmm6
  UFG::qVector4 v10; // xmm8
  UFG::qVector4 v11; // xmm9
  __m128 v12; // xmm4
  UFG::qVector4 v13; // xmm10
  UFG::qVector4 v14; // xmm11
  __m128 v15; // xmm12
  UFG::qVector4 v16; // xmm7
  UFG::qVector4 v17; // xmm5
  __m128 v18; // xmm2
  UFG::qVector3 offset; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qMatrix44 dest; // [rsp+30h] [rbp-C8h] BYREF
  _BYTE d[24]; // [rsp+70h] [rbp-88h] BYREF
  __m128 d_24; // [rsp+88h] [rbp-70h]
  __m128 d_40; // [rsp+98h] [rbp-60h]
  UFG::qMatrix44 d_56; // [rsp+A8h] [rbp-50h] BYREF

  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))this->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)(this->mRenderable->m_movie.pObject);
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::Movie *))this->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)(this->mRenderable->m_movie.pObject);
  v6 = (*(double (__fastcall **)(__int64))(*(_QWORD *)v4 + 56i64))(v4);
  v7 = (float)(*(float *)&v6 * -1.0) * 0.5;
  *(float *)&v6 = (*(float (__fastcall **)(__int64))(*(_QWORD *)v5 + 48i64))(v5);
  offset.y = v7;
  offset.x = (float)(*(float *)&v6 * -1.0) * 0.5;
  offset.z = 0.0;
  UFG::qTranslationMatrix(&dest, &offset);
  offset.x = UFG::gUIViewportScaleH * UFG::gUIViewportScale;
  offset.y = UFG::gUIViewportScaleV * UFG::gUIViewportScale;
  LODWORD(offset.z) = (_DWORD)FLOAT_1_0;
  UFG::qScaleMatrix((UFG::qMatrix44 *)d, &offset);
  UFG::qInverseAffine(&d_56, &dest);
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0), *(__m128 *)d), (__m128)0i64),
             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85), *(__m128 *)&d[8])),
           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170), d_24)),
         _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), d_40));
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0), *(__m128 *)d), (__m128)0i64),
             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85), *(__m128 *)&d[8])),
           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170), d_24)),
         _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255), d_40));
  v10 = d_56.v0;
  v11 = d_56.v1;
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0), *(__m128 *)d), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85), *(__m128 *)&d[8])),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170), d_24)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), d_40));
  v13 = d_56.v2;
  v14 = d_56.v3;
  v15 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), d_40),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0), *(__m128 *)d), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85), *(__m128 *)&d[8])),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), d_24)));
  v16 = (UFG::qVector4)_mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), (__m128)d_56.v0), (__m128)0i64),
                             _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), (__m128)d_56.v1)),
                           _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), (__m128)d_56.v2)),
                         _mm_mul_ps(_mm_shuffle_ps(v8, v8, 255), (__m128)d_56.v3));
  v17 = (UFG::qVector4)_mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), (__m128)d_56.v0), (__m128)0i64),
                             _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), (__m128)d_56.v1)),
                           _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), (__m128)d_56.v2)),
                         _mm_mul_ps(_mm_shuffle_ps(v9, v9, 255), (__m128)d_56.v3));
  v18 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), (__m128)d_56.v0), (__m128)0i64),
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), (__m128)d_56.v1));
  ViewportScaleMatrix->v0 = v16;
  ViewportScaleMatrix->v1 = v17;
  ViewportScaleMatrix->v2 = (UFG::qVector4)_mm_add_ps(
                                             _mm_mul_ps(_mm_shuffle_ps(v12, v12, 255), (__m128)v14),
                                             _mm_add_ps(v18, _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), (__m128)v13)));
  ViewportScaleMatrix->v3 = (UFG::qVector4)_mm_add_ps(
                                             _mm_add_ps(
                                               _mm_add_ps(
                                                 _mm_add_ps(
                                                   _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), (__m128)v10),
                                                   (__m128)0i64),
                                                 _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), (__m128)v11)),
                                               _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), (__m128)v13)),
                                             _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), (__m128)v14));
}

// File Line: 2374
// RVA: 0x600E80
void __fastcall UFG::UIHKScreenWorldMap::RenderBackground(UFG::UIHKScreenWorldMap *this, Render::View *view)
{
  float mBackgroundAlpha; // xmm0_4
  UFG::qColour colour; // [rsp+30h] [rbp-28h] BYREF
  Render::Poly poly; // [rsp+60h] [rbp+8h] BYREF

  mBackgroundAlpha = this->mBackgroundAlpha;
  *(_QWORD *)&colour.r = 0i64;
  colour.a = mBackgroundAlpha;
  colour.b = 0.0;
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::Poly::SetScreenPos(&poly, 0.0, 0.0, 1.0, 1.0, 0.0);
  Render::Poly::SetColour(&poly, &colour);
  Render::View::Draw(view, &poly, 0xB11369EB, 0i64, 0x62F81854u, 0xA3833FDE);
}

// File Line: 2404
// RVA: 0x601220
void __fastcall UFG::UIHKScreenWorldMap::RenderLowResMapNative(UFG::UIHKScreenWorldMap *this, Render::View *view)
{
  UFG::UITiledMapTextureManager *mTileStreamerLowRes; // r8
  UFG::qVector3 v5; // [rsp+40h] [rbp-18h] BYREF
  UFG::WorldPoint2f point; // [rsp+60h] [rbp+8h] BYREF
  UFG::ScreenPoint2f v7; // [rsp+70h] [rbp+18h] BYREF

  point.x = UFG::UITiledMapMath::InitWorldGeo.MinX;
  point.y = UFG::UITiledMapMath::InitWorldGeo.MaxY;
  UFG::ScreenPoint2f::ScreenPoint2f(&v7, &point, &this->m_mapGeo);
  mTileStreamerLowRes = this->mTileStreamerLowRes;
  *(UFG::ScreenPoint2f *)&v5.x = v7;
  v5.z = 0.0;
  UFG::UIHKScreenWorldMap::RenderMapTilesNative(this, view, mTileStreamerLowRes, 256, 12, 9, 1.0, &v5);
}

// File Line: 2420
// RVA: 0x6012D0
void __fastcall UFG::UIHKScreenWorldMap::RenderMapTilesNative(
        UFG::UIHKScreenWorldMap *this,
        Render::View *view,
        UFG::UITiledMapTextureManager *tileStreamer,
        int tileSize,
        int mapWidth,
        int mapHeight,
        float tileScale,
        UFG::qVector3 *screenPos)
{
  UFG::UITiledMapTextureManager *v10; // r14
  __m128 v11; // xmm5
  __m128 v12; // xmm6
  __m128 v13; // xmm4
  __m128 v14; // xmm12
  __m128 v15; // xmm14
  __m128 v16; // xmm11
  __m128 v17; // xmm15
  __int64 v18; // rax
  __m128 v19; // xmm12
  int v20; // edi
  int v21; // r13d
  int v22; // ebx
  int v23; // esi
  char *TileName; // rax
  unsigned int TextureUID; // r14d
  UFG::qResourceWarehouse *v26; // rax
  UFG::qResourceInventory *Inventory; // rax
  Illusion::Texture *v28; // rax
  Illusion::Texture *v29; // rdi
  int SamplerAddressFlags; // eax
  UFG::qVector3 scale; // [rsp+60h] [rbp-80h] BYREF
  UFG::qMatrix44 Color; // [rsp+70h] [rbp-70h] BYREF
  UFG::qMatrix44 v33; // [rsp+B0h] [rbp-30h] BYREF
  UFG::qMatrix44 dest; // [rsp+F0h] [rbp+10h] BYREF
  UFG::qMatrix44 v35; // [rsp+130h] [rbp+50h] BYREF
  UFG::qMatrix44 v36; // [rsp+170h] [rbp+90h] BYREF
  UFG::qMatrix44 result; // [rsp+1B0h] [rbp+D0h] BYREF
  __int64 v38; // [rsp+2D0h] [rbp+1F0h]
  Render::View *viewa; // [rsp+2D8h] [rbp+1F8h]
  UFG::UITiledMapTextureManager *vars0; // [rsp+2E0h] [rbp+200h]
  int v41; // [rsp+2F0h] [rbp+210h]
  int v42; // [rsp+2F8h] [rbp+218h]
  int v43; // [rsp+300h] [rbp+220h]
  UFG::qVector3 *offset; // [rsp+308h] [rbp+228h]

  v42 = (int)view;
  v41 = (int)this;
  v10 = tileStreamer;
  scale.x = this->m_mapGeo.scale / *(float *)&tileStreamer;
  scale.y = scale.x;
  LODWORD(scale.z) = (_DWORD)FLOAT_1_0;
  UFG::qScaleMatrix((UFG::qMatrix44 *)&dest.v2, &scale);
  UFG::qRotationMatrixZ(&Color, this->m_mapGeo.rot);
  UFG::qTranslationMatrix(&v36, offset);
  v11 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0), (__m128)Color.v0),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85), (__m128)Color.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170), (__m128)Color.v2)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), (__m128)Color.v3));
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0), (__m128)Color.v0),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85), (__m128)Color.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170), (__m128)Color.v2)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255), (__m128)Color.v3));
  v13 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0), (__m128)Color.v0),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85), (__m128)Color.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170), (__m128)Color.v2)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), (__m128)Color.v3));
  v14 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), (__m128)Color.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0), (__m128)Color.v0),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85), (__m128)Color.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), (__m128)Color.v2)));
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), (__m128)v36.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), (__m128)v36.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), (__m128)v36.v2)),
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 255), (__m128)v36.v3));
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), (__m128)v36.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), (__m128)v36.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), (__m128)v36.v2)),
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 255), (__m128)v36.v3));
  v17 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), (__m128)v36.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), (__m128)v36.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), (__m128)v36.v2)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), (__m128)v36.v3));
  v18 = (unsigned int)v42;
  Color.v0.x = UFG::qColour::White.r;
  Color.v0.y = UFG::qColour::White.g;
  Color.v0.z = UFG::qColour::White.b;
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), (__m128)v36.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), (__m128)v36.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), (__m128)v36.v2)),
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 255), (__m128)v36.v3));
  Color.v0.w = this->mMapTileAlpha;
  if ( v42 > 0 )
  {
    v20 = 0;
    v43 = 0;
    v21 = 0;
    *(_QWORD *)&scale.x = (unsigned int)v42;
    do
    {
      v22 = 0;
      if ( v41 > 0 )
      {
        v23 = 0;
        do
        {
          TileName = UFG::UITiledMapTextureManager::GetTileName(v10, v22 + v21);
          if ( TileName )
          {
            TextureUID = UFG::qStringHashUpper32(TileName + 6, -1);
            v26 = UFG::qResourceWarehouse::Instance();
            Inventory = UFG::qResourceWarehouse::GetInventory(v26, 0x8B43FABF);
            v28 = (Illusion::Texture *)Inventory->vfptr->Get(Inventory, TextureUID);
            v29 = v28;
            if ( v28 )
            {
              SamplerAddressFlags = Illusion::Texture::GetSamplerAddressFlags(v28);
              Illusion::Texture::SetSamplerAddressFlags(v29, SamplerAddressFlags | 3);
            }
            v20 = v43;
            scale.z = 0.0;
            scale.x = (float)v23;
            scale.y = (float)v43;
            UFG::qTranslationMatrix(&v33, &scale);
            v35.v0 = (UFG::qVector4)_mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v0, (__m128)v33.v0, 0), v16),
                                            (__m128)0i64),
                                          _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v0, (__m128)v33.v0, 85), v19)),
                                        _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v0, (__m128)v33.v0, 170), v15)),
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v0, (__m128)v33.v0, 255), v17));
            v35.v1 = (UFG::qVector4)_mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v1, (__m128)v33.v1, 0), v16),
                                            (__m128)0i64),
                                          _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v1, (__m128)v33.v1, 85), v19)),
                                        _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v1, (__m128)v33.v1, 170), v15)),
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v1, (__m128)v33.v1, 255), v17));
            v35.v2 = (UFG::qVector4)_mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v2, (__m128)v33.v2, 0), v16),
                                            (__m128)0i64),
                                          _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v2, (__m128)v33.v2, 85), v19)),
                                        _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v2, (__m128)v33.v2, 170), v15)),
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v2, (__m128)v33.v2, 255), v17));
            v35.v3 = (UFG::qVector4)_mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v3, (__m128)v33.v3, 0), v16),
                                            (__m128)0i64),
                                          _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v3, (__m128)v33.v3, 85), v19)),
                                        _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v3, (__m128)v33.v3, 170), v15)),
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)v33.v3, (__m128)v33.v3, 255), v17));
            UFG::qMatrix44::operator*(&v35, &result, (UFG::qMatrix44 *)(v38 + 3416));
            UFG::DrawColoredRect_Xform(
              viewa,
              0.0,
              0.0,
              (float)tileSize,
              (float)tileSize,
              (UFG::qColour *)&Color,
              TextureUID,
              0i64,
              0xA3833FDE,
              0x62F81854u,
              &result);
            v10 = vars0;
          }
          ++v22;
          v23 += tileSize;
        }
        while ( v22 < v41 );
        v18 = *(_QWORD *)&scale.x;
      }
      v20 += tileSize;
      v21 += v41;
      *(_QWORD *)&scale.x = --v18;
      v43 = v20;
    }
    while ( v18 );
  }
}

// File Line: 2468
// RVA: 0x601030
void __fastcall UFG::UIHKScreenWorldMap::RenderIconsNative(UFG::UIHKScreenWorldMap *this, Render::View *view)
{
  UFG::UIRenderQuad *p; // rbx
  UFG::qVector4 v5; // xmm7
  UFG::qVector4 v6; // xmm8
  UFG::qVector4 v7; // xmm9
  UFG::qVector4 v8; // xmm10
  float r; // xmm0_4
  UFG::qMatrix44 *Matrix; // rdx
  float Size; // xmm6_4
  float v12; // xmm1_4
  float h; // xmm6_4
  float b; // xmm0_4
  UFG::qColour Color; // [rsp+60h] [rbp-B8h] BYREF
  UFG::qMatrix44 TransformMatrix; // [rsp+70h] [rbp-A8h] BYREF

  p = this->mPolyListNative.p;
  if ( &p[this->mPolyListNative.size] != p )
  {
    v5 = 0i64;
    v5.x = (float)1;
    v6 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 81);
    v7 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 69);
    v8 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 21);
    do
    {
      r = p->Color.r;
      Matrix = p->Matrix;
      Size = p->Size;
      Color.g = p->Color.g;
      v12 = p->Color.a * this->mIconAlpha;
      h = Size * p->Scale;
      Color.r = r;
      b = p->Color.b;
      Color.a = v12;
      Color.b = b;
      TransformMatrix.v0 = v5;
      TransformMatrix.v1 = v6;
      TransformMatrix.v2 = v7;
      TransformMatrix.v3 = v8;
      if ( Matrix )
        UFG::qMatrix44::operator*=(&TransformMatrix, Matrix);
      UFG::qMatrix44::operator*=(&TransformMatrix, &this->mViewportScaleMatrix);
      UFG::DrawColoredRect_Xform(
        view,
        p->X - (float)(h * 0.5),
        p->Y - (float)(h * 0.5),
        h,
        h,
        &Color,
        p->TextureID,
        p->UVs,
        0xA3833FDE,
        0x62F81854u,
        &TransformMatrix);
      ++p;
    }
    while ( &this->mPolyListNative.p[this->mPolyListNative.size] != p );
  }
}

// File Line: 2562
// RVA: 0x600F20
void __fastcall UFG::UIHKScreenWorldMap::RenderGPSSpline(UFG::UIHKScreenWorldMap *this, Render::View *view)
{
  unsigned int mNumSplinePoints; // edi
  float mIconAlpha; // xmm1_4
  UFG::qBaseTreeRB *CollisionModel; // rax
  UFG::qVector3 *p; // rdx
  __int64 v7; // rcx
  float yPos; // xmm1_4
  float z; // xmm0_4
  float x; // xmm3_4
  UFG::qColour worldPos; // [rsp+30h] [rbp-18h] BYREF

  mNumSplinePoints = this->GPS.mNumSplinePoints;
  if ( mNumSplinePoints >= 2 )
  {
    mIconAlpha = this->mIconAlpha;
    worldPos = UFG::UITiledMapWidget::GPSLineColor;
    worldPos.a = mIconAlpha;
    UFG::UIHKScreenWorldMap::RenderSpline(this, &this->GPS.mSplinePoints, mNumSplinePoints, &worldPos, view);
    if ( UFG::UITiledMapTweakables::GPS_ShowDestinationBlip )
    {
      CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(
                         (UFG::BasePhysicsSystem *)&this->mMinimapIconManagerClone,
                         UI_BLIP_GPS_DESTINATION_20);
      p = this->GPS.mSplinePoints.p;
      v7 = mNumSplinePoints - 1;
      yPos = p[v7].y;
      z = p[v7].z;
      x = p[v7].x;
      worldPos.r = x;
      worldPos.g = yPos;
      worldPos.b = z;
      if ( CollisionModel )
        UFG::UIMapBlip::SetPosition((UFG::UIMapBlip *)CollisionModel, (UFG::qVector3 *)&worldPos);
      else
        UFG::UIMapBlipManager::CreateIcon(
          &this->mMinimapIconManagerClone,
          UI_BLIP_GPS_DESTINATION_20,
          "waypoint",
          x,
          yPos)->mBoundIcon = 0;
    }
  }
}

// File Line: 2594
// RVA: 0x602160
void __fastcall UFG::UIHKScreenWorldMap::RenderRaceSpline(UFG::UIHKScreenWorldMap *this, Render::View *view)
{
  float mRacePathAlpha; // xmm1_4
  unsigned int m_NumSplinePoints; // esi
  UFG::qArray<UFG::qVector3,0> *p_m_SplinePoints; // rdi
  UFG::BasePhysicsSystem *p_mMinimapIconManagerClone; // rbx
  UFG::qBaseTreeRB *CollisionModel; // rax
  UFG::qVector3 *p; // rcx
  float yPos; // xmm1_4
  float z; // xmm0_4
  float x; // xmm3_4
  UFG::qBaseTreeRB *v12; // rax
  UFG::qVector3 *v13; // rcx
  float y; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  UFG::qVector3 worldPos; // [rsp+30h] [rbp-28h] BYREF
  UFG::qColour v18; // [rsp+40h] [rbp-18h] BYREF

  mRacePathAlpha = this->mRacePathAlpha;
  m_NumSplinePoints = this->RacePath.m_NumSplinePoints;
  p_m_SplinePoints = &this->RacePath.m_SplinePoints;
  v18 = UFG::UITiledMapWidget::RaceRouteColor;
  v18.a = mRacePathAlpha;
  UFG::UIHKScreenWorldMap::RenderSpline(this, &this->RacePath.m_SplinePoints, m_NumSplinePoints, &v18, view);
  if ( m_NumSplinePoints )
  {
    p_mMinimapIconManagerClone = (UFG::BasePhysicsSystem *)&this->mMinimapIconManagerClone;
    CollisionModel = UFG::BasePhysicsSystem::GetCollisionModel(p_mMinimapIconManagerClone, UI_BLIP_RACE_START_20);
    p = p_m_SplinePoints->p;
    yPos = p->y;
    z = p->z;
    x = p->x;
    worldPos.x = p->x;
    worldPos.y = yPos;
    worldPos.z = z;
    if ( CollisionModel )
      UFG::UIMapBlip::SetPosition((UFG::UIMapBlip *)CollisionModel, &worldPos);
    else
      UFG::UIMapBlipManager::CreateIcon(
        (UFG::UIMapBlipManager *)p_mMinimapIconManagerClone,
        UI_BLIP_RACE_START_20,
        "race_start_flag",
        x,
        yPos)->mBoundIcon = 0;
    v12 = UFG::BasePhysicsSystem::GetCollisionModel(p_mMinimapIconManagerClone, UI_BLIP_RACE_END_20);
    v13 = p_m_SplinePoints->p;
    y = v13[m_NumSplinePoints - 1].y;
    v15 = v13[m_NumSplinePoints - 1].z;
    v16 = v13[m_NumSplinePoints - 1].x;
    v18.r = v16;
    v18.g = y;
    v18.b = v15;
    if ( v12 )
    {
      UFG::UIMapBlip::SetPosition((UFG::UIMapBlip *)v12, (UFG::qVector3 *)&v18);
    }
    else if ( v16 != worldPos.x || y != worldPos.y || v15 != worldPos.z )
    {
      UFG::UIMapBlipManager::CreateIcon(
        (UFG::UIMapBlipManager *)p_mMinimapIconManagerClone,
        UI_BLIP_RACE_END_20,
        "race_end",
        v16,
        y)->mBoundIcon = 0;
    }
  }
}

// File Line: 2634
// RVA: 0x6022D0
void __fastcall UFG::UIHKScreenWorldMap::RenderSpline(
        UFG::UIHKScreenWorldMap *this,
        UFG::qArray<UFG::qVector3,0> *SplinePoints,
        unsigned int NumSplinePoints,
        UFG::qColour *Colour,
        Render::View *view)
{
  __int64 v9; // rbp
  float *v10; // rdi
  UFG::qVector3 *p; // r9
  __m128 y_low; // xmm6
  float v13; // xmm8_4
  __m128 v14; // xmm1
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm8_4
  __int64 v18; // rbx
  float v19; // xmm9_4
  float v20; // xmm5_4
  float v21; // xmm2_4
  float v22; // xmm10_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm4_4
  float *p_y; // rcx
  float *p_x; // rdx
  float *v29; // r8
  __int64 v30; // r10
  float v31; // xmm12_4
  float v32; // xmm13_4
  float v33; // xmm6_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm5_4
  float v37; // xmm8_4
  float v38; // xmm4_4
  float v39; // xmm10_4
  float v40; // xmm9_4
  float v41; // xmm2_4
  float v42; // xmm1_4
  float v43; // xmm10_4
  float v44; // xmm4_4
  float v45; // xmm9_4
  float v46; // xmm2_4
  float v47; // xmm1_4
  float v48; // xmm0_4
  __int64 v49; // rdx
  __int64 v50; // rcx
  float v51; // xmm1_4
  float v52; // xmm3_4
  __int64 v53; // rax
  float z; // xmm0_4
  float v55; // xmm1_4
  Illusion::Primitive::Type v56; // r8d

  if ( NumSplinePoints >= 2 )
  {
    v9 = 2 * NumSplinePoints;
    v10 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 96 * NumSplinePoints, 0x10u);
    memset(v10, 0, 48 * v9);
    p = SplinePoints->p;
    y_low = (__m128)LODWORD(p[1].y);
    y_low.m128_f32[0] = y_low.m128_f32[0] - p->y;
    LODWORD(v13) = COERCE_UNSIGNED_INT(p[1].x - p->x) ^ _xmm[0];
    v14 = y_low;
    v14.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v13 * v13);
    if ( v14.m128_f32[0] == 0.0 )
      v15 = 0.0;
    else
      v15 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
    v16 = y_low.m128_f32[0] * v15;
    v17 = v13 * v15;
    v18 = NumSplinePoints - 1;
    v19 = v17;
    v20 = v15 * 0.0;
    v21 = (float)(v17 * 3.0) + p->y;
    v22 = v20;
    v23 = (float)(v20 * 3.0) + p->z;
    *v10 = (float)(v16 * 3.0) + p->x;
    v10[1] = v21;
    v10[2] = v23;
    v24 = p->z - (float)(v20 * 3.0);
    v25 = p->y - (float)(v17 * 3.0);
    v10[12] = p->x - (float)(v16 * 3.0);
    v26 = v16;
    v10[13] = v25;
    v10[14] = v24;
    if ( (unsigned int)v18 > 1 )
    {
      p_y = &p[1].y;
      p_x = &p[2].x;
      v29 = v10 + 38;
      v30 = (unsigned int)(v18 - 1);
      do
      {
        v31 = *(p_y - 1);
        v32 = *p_y;
        v33 = p_x[1] - *p_y;
        LODWORD(v34) = COERCE_UNSIGNED_INT(*p_x - v31) ^ _xmm[0];
        v35 = (float)(v34 * v34) + (float)(v33 * v33);
        if ( v35 == 0.0 )
          v36 = 0.0;
        else
          v36 = 1.0 / fsqrt(v35);
        v37 = v36;
        v16 = v33 * v36;
        v20 = v36 * 0.0;
        v38 = v26 + v16;
        v39 = v22 + v20;
        v17 = v37 * v34;
        v40 = v19 + v17;
        v41 = (float)((float)(v40 * v40) + (float)(v38 * v38)) + (float)(v39 * v39);
        if ( v41 == 0.0 )
          v42 = 0.0;
        else
          v42 = 1.0 / fsqrt(v41);
        v43 = v39 * v42;
        v44 = v38 * v42;
        v29 += 24;
        p_x += 3;
        p_y += 3;
        v45 = v40 * v42;
        *(v29 - 36) = (float)(v43 * 3.0) + *(p_y - 2);
        *(v29 - 38) = v31 + (float)(v44 * 3.0);
        *(v29 - 37) = v32 + (float)(v45 * 3.0);
        v46 = *(p_y - 4) - (float)(v44 * 3.0);
        v26 = v16;
        v47 = *(p_y - 3) - (float)(v45 * 3.0);
        v48 = *(p_y - 2) - (float)(v43 * 3.0);
        *(v29 - 26) = v46;
        v19 = v17;
        v22 = v20;
        *(v29 - 25) = v47;
        *(v29 - 24) = v48;
        --v30;
      }
      while ( v30 );
    }
    v49 = (unsigned int)(2 * v18);
    v50 = 6 * v49;
    v51 = (float)(v20 * 3.0) + p[v18].z;
    v52 = (float)(v16 * 3.0) + p[v18].x;
    v53 = 6i64 * (unsigned int)(v49 + 1);
    v10[2 * v50 + 1] = (float)(v17 * 3.0) + p[v18].y;
    v10[2 * v50 + 2] = v51;
    v10[2 * v50] = v52;
    z = p[v18].z;
    v55 = p[v18].y - (float)(v17 * 3.0);
    v56 = TRIANGLESTRIP;
    v10[2 * v53] = p[v18].x - (float)(v16 * 3.0);
    v10[2 * v53 + 1] = v55;
    v10[2 * v53 + 2] = z - (float)(v20 * 3.0);
    if ( UFG::UIHKTweakables::WorldMap_UsePointList )
      v56 = POINTLIST;
    UFG::UIHKScreenWorldMap::RenderMinimapPrimitive(this, view, v56, Colour);
  }
}

// File Line: 2688
// RVA: 0x601910
void __fastcall UFG::UIHKScreenWorldMap::RenderMinimapPrimitive(
        UFG::UIHKScreenWorldMap *this,
        Render::View *view,
        Illusion::Primitive::Type PrimitiveType,
        UFG::qColour *Color)
{
  __m128 v8; // xmm11
  __m128 v9; // xmm14
  __m128 v10; // xmm12
  __m128 v11; // xmm15
  int v12; // r14d
  void *v13; // r15
  int v14; // esi
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm8_4
  float *v18; // rbx
  __int64 v19; // rdi
  float v20; // xmm9_4
  float w; // xmm10_4
  float z; // xmm11_4
  float x; // xmm12_4
  float v24; // xmm13_4
  float v25; // xmm14_4
  float v26; // xmm15_4
  float v27; // xmm1_4
  float v28; // xmm5_4
  float v29; // xmm4_4
  float v30; // xmm1_4
  Illusion::Material *SimpleMaterial; // rdi
  unsigned int v32; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v34; // rax
  Illusion::Primitive *v35; // rbx
  UFG::MinimapPoint2f v36[2]; // [rsp+40h] [rbp-88h] BYREF
  UFG::MinimapPoint2f v37; // [rsp+50h] [rbp-78h] BYREF
  __m128 v38; // [rsp+58h] [rbp-70h] BYREF
  UFG::MinimapTilePoint2f iconPos; // [rsp+68h] [rbp-60h] BYREF
  UFG::qMatrix44 result; // [rsp+70h] [rbp-58h] BYREF
  float v41; // [rsp+B0h] [rbp-18h]
  __int64 v42; // [rsp+B8h] [rbp-10h]
  UFG::qMatrix44 v43; // [rsp+C8h] [rbp+0h] BYREF
  UFG::qMatrix44 dest; // [rsp+108h] [rbp+40h] BYREF
  UFG::qMatrix44 v45; // [rsp+148h] [rbp+80h] BYREF
  UFG::qMatrix44 v46; // [rsp+188h] [rbp+C0h] BYREF
  UFG::qMatrix44 v47; // [rsp+1C8h] [rbp+100h] BYREF
  UFG::ScreenPoint2f v48; // [rsp+2E8h] [rbp+220h] BYREF
  UFG::WorldPoint2f point; // [rsp+300h] [rbp+238h] BYREF
  void *vertices; // [rsp+308h] [rbp+240h]
  int num_vertices; // [rsp+310h] [rbp+248h]
  const void *indices; // [rsp+318h] [rbp+250h]
  int num_indices; // [rsp+320h] [rbp+258h]
  UFG::WorldPoint2f v54; // [rsp+338h] [rbp+270h] BYREF

  v42 = -2i64;
  point = 0i64;
  UFG::MinimapPoint2f::MinimapPoint2f((UFG::MinimapPoint2f *)&result.v1, &v54);
  UFG::MinimapTilePoint2f::MinimapTilePoint2f(&iconPos, &v36[1], &this->m_mapGeo);
  v48 = 0i64;
  UFG::ScreenPoint2f::InitFromIconPos(&v48, &iconPos, &this->m_mapGeo);
  *(UFG::ScreenPoint2f *)v38.m128_f32 = v48;
  v38.m128_i32[2] = 0;
  UFG::MinimapPoint2f::MinimapPoint2f(&v37, &this->m_mapGeo.centerPosition);
  LODWORD(v36[0].x) = LODWORD(v37.x) ^ _xmm[0];
  LODWORD(v36[0].y) = LODWORD(v37.y) ^ _xmm[0];
  v36[1].x = 0.0;
  UFG::qTranslationMatrix(&dest, (UFG::qVector3 *)v36);
  v36[0].x = this->m_mapGeo.scale;
  v36[0].y = v36[0].x;
  LODWORD(v36[1].x) = (_DWORD)FLOAT_1_0;
  UFG::qScaleMatrix(&v45, (UFG::qVector3 *)v36);
  UFG::qRotationMatrixZ(&v46, this->m_mapGeo.rot);
  UFG::qTranslationMatrix(&v43, (UFG::qVector3 *)&v38);
  result.v0 = (UFG::qVector4)_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0), (__m128)v45.v0);
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps((__m128)result.v0, _xmm),
             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85), (__m128)v45.v1)),
           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170), (__m128)v45.v2)),
         _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), (__m128)v45.v3));
  v9 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0), (__m128)v45.v0), (__m128)0i64),
             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85), (__m128)v45.v1)),
           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170), (__m128)v45.v2)),
         _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255), (__m128)v45.v3));
  v38 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0), (__m128)v45.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85), (__m128)v45.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170), (__m128)v45.v2)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), (__m128)v45.v3));
  *(__m128 *)&v36[0].x = _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 (__m128)0i64,
                                 _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0), (__m128)v45.v0)),
                               _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85), (__m128)v45.v1)),
                             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), (__m128)v45.v2)),
                           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), (__m128)v45.v3));
  result.v0 = (UFG::qVector4)_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), (__m128)v46.v0);
  v10 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_add_ps((__m128)result.v0, _xmm), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), (__m128)v46.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), (__m128)v46.v2)),
          _mm_mul_ps(_mm_shuffle_ps(v8, v8, 255), (__m128)v46.v3));
  v11 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps((__m128)0i64, _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), (__m128)v46.v0)),
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), (__m128)v46.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), (__m128)v46.v2)),
          _mm_mul_ps(_mm_shuffle_ps(v9, v9, 255), (__m128)v46.v3));
  v38 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps((__m128)0i64, _mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), (__m128)v46.v0)),
              _mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), (__m128)v46.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), (__m128)v46.v2)),
          _mm_mul_ps(_mm_shuffle_ps(v38, v38, 255), (__m128)v46.v3));
  *(__m128 *)&v36[0].x = _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(
                                 (__m128)0i64,
                                 _mm_mul_ps(
                                   _mm_shuffle_ps(*(__m128 *)&v36[0].x, *(__m128 *)&v36[0].x, 0),
                                   (__m128)v46.v0)),
                               _mm_mul_ps(
                                 _mm_shuffle_ps(*(__m128 *)&v36[0].x, *(__m128 *)&v36[0].x, 85),
                                 (__m128)v46.v1)),
                             _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v36[0].x, *(__m128 *)&v36[0].x, 170), (__m128)v46.v2)),
                           _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v36[0].x, *(__m128 *)&v36[0].x, 255), (__m128)v46.v3));
  v47.v0 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps((__m128)0i64, _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), (__m128)v43.v0)),
                                _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), (__m128)v43.v1)),
                              _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), (__m128)v43.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(v10, v10, 255), (__m128)v43.v3));
  v47.v1 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps((__m128)0i64, _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), (__m128)v43.v0)),
                                _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), (__m128)v43.v1)),
                              _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), (__m128)v43.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 255), (__m128)v43.v3));
  v47.v2 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps((__m128)0i64, _mm_mul_ps(_mm_shuffle_ps(v38, v38, 0), (__m128)v43.v0)),
                                _mm_mul_ps(_mm_shuffle_ps(v38, v38, 85), (__m128)v43.v1)),
                              _mm_mul_ps(_mm_shuffle_ps(v38, v38, 170), (__m128)v43.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(v38, v38, 255), (__m128)v43.v3));
  v47.v3 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(
                                  (__m128)0i64,
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&v36[0].x, *(__m128 *)&v36[0].x, 0),
                                    (__m128)v43.v0)),
                                _mm_mul_ps(
                                  _mm_shuffle_ps(*(__m128 *)&v36[0].x, *(__m128 *)&v36[0].x, 85),
                                  (__m128)v43.v1)),
                              _mm_mul_ps(
                                _mm_shuffle_ps(*(__m128 *)&v36[0].x, *(__m128 *)&v36[0].x, 170),
                                (__m128)v43.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v36[0].x, *(__m128 *)&v36[0].x, 255), (__m128)v43.v3));
  UFG::qMatrix44::operator*(&v47, (UFG::qMatrix44 *)&result.v0.z, &this->mViewportScaleMatrix);
  v12 = (int)(float)(Color->r * 255.0) | (((int)(float)(Color->g * 255.0) | (((int)(float)(Color->b * 255.0) | ((int)(float)(Color->a * 255.0) << 8)) << 8)) << 8);
  v13 = vertices;
  v14 = num_vertices;
  if ( num_vertices )
  {
    v15 = result.v2.z * 0.0;
    v16 = result.v2.w * 0.0;
    v17 = result.v3.x * 0.0;
    v18 = (float *)((char *)vertices + 4);
    v19 = (unsigned int)num_vertices;
    v20 = v41;
    w = result.v3.w;
    z = result.v3.z;
    x = result.v2.x;
    v24 = result.v1.w;
    v25 = result.v1.z;
    v26 = result.v1.x;
    do
    {
      v27 = *v18;
      point.x = *(v18 - 1);
      point.y = v27;
      UFG::MinimapPoint2f::MinimapPoint2f(v36, &point);
      v28 = (float)((float)((float)(v25 * v36[0].y) + (float)(result.v0.z * v36[0].x)) + v15) + z;
      v29 = (float)((float)((float)(v24 * v36[0].y) + (float)(result.v0.w * v36[0].x)) + v16) + w;
      v30 = (float)((float)((float)(x * v36[0].y) + (float)(v26 * v36[0].x)) + v17) + v20;
      *(v18 - 1) = v28;
      *v18 = v29;
      v18[1] = v30;
      *((_DWORD *)v18 + 10) = v12;
      *(v18 - 1) = v28 / (float)(int)UFG::UIScreenManager::s_instance->m_flashWidth;
      *v18 = v29 / (float)(int)UFG::UIScreenManager::s_instance->m_flashHeight;
      v18 += 12;
      --v19;
    }
    while ( v19 );
  }
  SimpleMaterial = Render::View::CreateSimpleMaterial(0xB11369EB, 0x62F81854u, 0xA3833FDE, 0);
  if ( (_S14_4 & 1) == 0 )
  {
    _S14_4 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&vertex_decl_handle_3);
    atexit(UFG::UIHKScreenWorldMap::RenderMinimapPrimitive_::_4_::_dynamic_atexit_destructor_for__vertex_decl_handle__);
  }
  if ( !vertex_decl_handle_3.mData )
  {
    v32 = UFG::qStringHash32("VertexDecl.Dynamic", 0xFFFFFFFF);
    Inventory = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
    {
      v34 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v34, 0x3E5FDA3Eu);
      `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&vertex_decl_handle_3, 0x3E5FDA3Eu, v32, Inventory);
  }
  v35 = Illusion::Primitive::Create("MiniMap");
  Illusion::Primitive::SetBuffers(
    v35,
    PrimitiveType,
    v13,
    v14,
    (Illusion::VertexDecl *)vertex_decl_handle_3.mData,
    indices,
    num_indices,
    1);
  Render::View::Draw(view, v35, SimpleMaterial, 0i64);
}

// File Line: 2751
// RVA: 0x5D24F0
void __fastcall UFG::UIHKScreenWorldMap::AddLegendItem(
        UFG::UIHKScreenWorldMap *this,
        const char *icon,
        const char *caption)
{
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rbx
  UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *mPrev; // rax

  v6 = UFG::qMalloc(0x60ui64, "LegendItemData", 0i64);
  v7 = v6;
  if ( v6 )
  {
    v6->mNext = v6;
    v6[1].mNext = v6;
    UFG::qString::qString((UFG::qString *)&v6[2]);
    UFG::qString::qString((UFG::qString *)&v7[7]);
  }
  else
  {
    v7 = 0i64;
  }
  if ( v7 )
  {
    UFG::qString::Set((UFG::qString *)&v7[2], icon);
    UFG::qString::Set((UFG::qString *)&v7[7], caption);
    mPrev = this->mLegendItems.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *)v7;
    v7->mNext = (UFG::allocator::free_link *)mPrev;
    v7[1].mNext = (UFG::allocator::free_link *)&this->mLegendItems;
    this->mLegendItems.mNode.mPrev = (UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *)v7;
  }
}

// File Line: 2784
// RVA: 0x610A30
void __fastcall UFG::UIHKScreenWorldMap::ShowLegend(UFG::UIHKScreenWorldMap *this, int pageNumber)
{
  UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *p_mLegendItems; // rbp
  int v3; // esi
  int v4; // edi
  UFG::UIHKScreenWorldMap *mNext; // r8
  int v8; // ebx
  int v9; // eax
  int i; // ecx
  Scaleform::GFx::Movie *pObject; // rcx
  UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *v12; // rbx
  int v13; // r15d
  __int64 v14; // rax
  UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *j; // rax

  p_mLegendItems = &this->mLegendItems;
  v3 = 0;
  v4 = 1;
  mNext = (UFG::UIHKScreenWorldMap *)this->mLegendItems.mNode.mNext;
  v8 = 1;
  v9 = 0;
  if ( mNext != (UFG::UIHKScreenWorldMap *)&this->mLegendItems )
  {
    do
    {
      mNext = (UFG::UIHKScreenWorldMap *)mNext->mPrev;
      ++v9;
    }
    while ( mNext != (UFG::UIHKScreenWorldMap *)p_mLegendItems );
    if ( v9 )
    {
      if ( v9 <= 12 )
        goto LABEL_8;
      for ( i = 12; i < v9; i += 12 )
        ++v8;
      if ( v8 )
      {
LABEL_8:
        pObject = this->mRenderable->m_movie.pObject;
        if ( pObject )
          Scaleform::GFx::Movie::Invoke(pObject, "Legend_Clear", 0i64, 0i64, 0);
        UFG::UIHKWorldMapLegendWidget::Flash_SetLegendPageNumbers(&this->Legend, this, pageNumber, v8);
        v12 = this->mLegendItems.mNode.mNext;
        v13 = 12 * pageNumber;
        v14 = (unsigned int)(v13 - 12);
        if ( (int)v14 >= 1 )
        {
          v4 = v14 + 1;
          do
          {
            v12 = v12->mNext;
            --v14;
          }
          while ( v14 );
        }
        for ( j = (UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *)p_mLegendItems->mNode.mNext;
              j != p_mLegendItems;
              ++v3 )
        {
          j = (UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *)j->mNode.mNext;
        }
        for ( ; v4 <= v3; ++v4 )
        {
          if ( v4 > v13 )
            break;
          UFG::UIHKWorldMapLegendWidget::Flash_AddItem(
            &this->Legend,
            this,
            (const char *)v12[2].mNext,
            (const char *)v12[5].mPrev);
          v12 = v12->mNext;
        }
      }
    }
  }
}

// File Line: 2842
// RVA: 0x5E1960
void __fastcall UFG::UIHKScreenWorldMap::Flash_SetViewType(UFG::UIHKScreenWorldMap *this, bool showCollectibles)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (pargs.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = VT_Boolean;
    pargs.mValue.BValue = showCollectibles;
    Scaleform::GFx::Movie::Invoke(pObject, "SetCollectiblesStatsVisible", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 2855
// RVA: 0x5F0A00
void __fastcall UFG::UIHKScreenWorldMap::LegendTurnPage(UFG::UIHKScreenWorldMap *this)
{
  int v1; // edx
  UFG::UIHKScreenWorldMap *mNext; // rax
  int v3; // r8d
  int i; // eax

  ++this->mLegendPageNumber;
  v1 = 0;
  mNext = (UFG::UIHKScreenWorldMap *)this->mLegendItems.mNode.mNext;
  v3 = 1;
  if ( mNext == (UFG::UIHKScreenWorldMap *)&this->mLegendItems )
    goto LABEL_8;
  do
  {
    mNext = (UFG::UIHKScreenWorldMap *)mNext->mPrev;
    ++v1;
  }
  while ( mNext != (UFG::UIHKScreenWorldMap *)&this->mLegendItems );
  if ( !v1 )
  {
LABEL_8:
    v3 = 0;
  }
  else if ( v1 > 12 )
  {
    for ( i = 12; i < v1; i += 12 )
      ++v3;
  }
  if ( this->mLegendPageNumber > v3 )
    this->mLegendPageNumber = 1;
  UFG::UIHKScreenWorldMap::ShowLegend(this, this->mLegendPageNumber);
}

