// File Line: 90
// RVA: 0x1567410
__int64 dynamic_initializer_for__UFG::UIHKScreenWorldMap::mScreenInvokeQueue__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenWorldMap::mScreenInvokeQueue__);
}

// File Line: 91
// RVA: 0x1567170
__int64 dynamic_initializer_for__UFG::UIHKScreenWorldMap::mIconManager__()
{
  UFG::UIMapBlipManager::UIMapBlipManager(&UFG::UIHKScreenWorldMap::mIconManager);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenWorldMap::mIconManager__);
}

// File Line: 92
// RVA: 0x1566B70
__int64 dynamic_initializer_for__UFG::UIHKScreenWorldMap::MapLines__()
{
  UFG::UIMapLinesWidget::UIMapLinesWidget(&UFG::UIHKScreenWorldMap::MapLines);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenWorldMap::MapLines__);
}

// File Line: 100
// RVA: 0x156E0F0
__int64 UFG::_dynamic_initializer_for__gWorldMapHelpbarID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("worldmap_helpbar", 0xFFFFFFFF);
  gWorldMapHelpbarID = result;
  return result;
}

// File Line: 128
// RVA: 0x5C7B90
void __fastcall UFG::UIHKScreenWorldMap::UIHKScreenWorldMap(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rdi
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  UFG::UITiledMapTextureManager *v3; // rsi
  UFG::UIHKWorldMapInfoPopupWidget *v4; // rbx
  UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *v5; // rbx
  UFG::allocator::free_link *v6; // rax
  UFG::UITiledMapTextureManager *v7; // rax
  UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *i; // rdx
  UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *v9; // rcx
  UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *v10; // rax
  signed __int64 v11; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  v3 = 0i64;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenWorldMap::`vftable;
  *(_QWORD *)&this->mState = 0i64;
  this->mViewTypeChanged = 1;
  this->mViewTypeScrollDirection = 0;
  *(_DWORD *)&this->mShouldPushHud = 1;
  *(_WORD *)&this->mIsKeyboardController = 0;
  this->mIntroTimeOut = 2.0;
  *(_QWORD *)&this->mMapFadeTime = 1056964608i64;
  *(_QWORD *)&this->mMapTileAlpha = 0i64;
  *(_QWORD *)&this->mIconAlpha = 0i64;
  *(_QWORD *)&this->mRacePathFadeTime = 1056964608i64;
  this->mRacePathAlpha = 0.0;
  *(_WORD *)&this->mUseLowResTiles = 0;
  v4 = &this->InfoPopup;
  v4->mState = 0;
  *(_WORD *)&v4->mChanged = 0;
  v4->mCueAnimation = 0;
  UFG::qString::qString(&this->InfoPopup.mTitleText);
  UFG::qString::qString(&v4->mBodyText);
  UFG::UIHKWorldMapTerritoryWidget::UIHKWorldMapTerritoryWidget(&v1->Territory);
  *(_QWORD *)&v1->Legend.mState = 0i64;
  v1->Legend.mToggleFadeOut = 0;
  v1->ObjectivesWidget.mState = 3;
  *(_WORD *)&v1->ObjectivesWidget.mbIsHiding = 1;
  v1->PerkGoalsWidget.mState = 3;
  *(_WORD *)&v1->PerkGoalsWidget.mbIsHiding = 1;
  v11 = (signed __int64)&v1->TutorialPopup;
  *(_DWORD *)v11 = 1;
  *(_WORD *)(v11 + 4) = 256;
  UFG::qString::qString(&v1->TutorialPopup.mCaption);
  v1->TutorialPopup.mType.mUID = qSymbol_Food_20.mUID;
  *(_QWORD *)&v1->TutorialPopup.mPosition = 0i64;
  v1->TutorialPopup.mHintReminderTimeout = 0.0;
  *(_WORD *)&v1->TutorialPopup.mInfinite = 0;
  v1->TutorialPopup.mState = 0;
  UFG::UITiledMapWidget::UITiledMapWidget(&v1->mTiledMap);
  UFG::UIMapBlipManager::UIMapBlipManager(&v1->mMinimapIconManagerClone);
  v1->Cursor.mPos = 0i64;
  v1->Cursor.mMinLimit = 0i64;
  v1->Cursor.mMaxLimit = 0i64;
  v1->Cursor.mEdgePush = 0i64;
  v1->Cursor.mMargin = 30.0;
  v1->Cursor.mIsMoving = 0;
  v1->Cursor.mSelectedObjective = 0i64;
  v1->Cursor.mIsOpen = 0;
  v1->Cursor.mSelectedBlipColor.r = UFG::qColour::White.r;
  v1->Cursor.mSelectedBlipColor.g = UFG::qColour::White.g;
  v1->Cursor.mSelectedBlipColor.b = UFG::qColour::White.b;
  v1->Cursor.mSelectedBlipColor.a = UFG::qColour::White.a;
  UFG::UITiledMapGPS::UITiledMapGPS(&v1->GPS);
  UFG::UITiledMapRaceSplines::UITiledMapRaceSplines(&v1->RacePath);
  v5 = &v1->mLegendItems;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  UFG::UITiledMapMath::UITiledMapMath(&v1->m_mapGeo);
  v1->mOriginPos = 0i64;
  v1->mWaitForScreenPush = 0;
  *(_QWORD *)&v1->OldMapGeo.MinX = 0i64;
  *(_QWORD *)&v1->OldMapGeo.MinY = 0i64;
  *(_QWORD *)&v1->OldMapGeo.TextureWidth = 0i64;
  v1->mPolyListNative.p = 0i64;
  *(_QWORD *)&v1->mPolyListNative.size = 0i64;
  v6 = UFG::qMalloc(0x58ui64, "UIHKMinimapTileStreamer", 0i64);
  if ( v6 )
  {
    UFG::UITiledMapTextureManager::UITiledMapTextureManager((UFG::UITiledMapTextureManager *)v6, 0xCu, 9u, 0x100u);
    v3 = v7;
  }
  v1->mTileStreamerLowRes = v3;
  UFG::UITiledMapTextureManager::SetTileTag(v3, "_lowres");
  v1->mTileStreamerLowRes->mStreamingEnabled = 0;
  UFG::UITiledMapTextureManager::SetActive(v1->mTileStreamerLowRes, 1);
  v1->mUseLowResTiles = 1;
  UFG::UIMapBlipManager::SetMaxNumIcons(&UFG::UIHKScreenWorldMap::mIconManager, 2000);
  v1->mViewportScale = UFG::gUIViewportScale;
  v1->mViewportScaleH = UFG::gUIViewportScaleH;
  v1->mViewportScaleV = UFG::gUIViewportScaleV;
  for ( i = (UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *)v1->mLegendItems.mNode.mNext;
        i != v5;
        i = (UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *)v1->mLegendItems.mNode.mNext )
  {
    v9 = i->mNode.mPrev;
    v10 = i->mNode.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    i->mNode.mPrev = &i->mNode;
    i->mNode.mNext = &i->mNode;
  }
  v1->mLegendPageNumber = 1;
  UFG::InputSystem::SetShouldRestrictCursor(1, 1, 1, 1);
  UFG::InputSystem::SetShouldHideCursor(1, 1, 1, 1);
  UFG::InputSystem::msRelativeMouseMode = 1;
  UFG::InputSystem::msForceSendMouseMsgs = 1;
}

// File Line: 160
// RVA: 0x5CD230
void __fastcall UFG::UIHKScreenWorldMap::~UIHKScreenWorldMap(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rdi
  UFG::UITiledMapTextureManager *v2; // rbx
  UFG::UIScreenTextureManager *v3; // rax
  UFG::TiDoVtbl *v4; // rax
  UFG::UI *v5; // rcx
  UFG::UI *v6; // rcx
  unsigned int v7; // eax
  UFG::UIHKScreenGlobalOverlay *v8; // rax
  UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *v9; // rbx
  UFG::UIRenderQuad *v10; // rcx
  UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *v11; // rcx
  UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *v12; // rax
  UFG::qVector3 *v13; // rcx
  UFG::qVector3 *v14; // rcx

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenWorldMap::`vftable;
  v2 = this->mTileStreamerLowRes;
  if ( v2 )
  {
    UFG::UITiledMapTextureManager::~UITiledMapTextureManager(this->mTileStreamerLowRes);
    operator delete[](v2);
  }
  v1->mTileStreamerLowRes = 0i64;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "WorldMap");
  UFG::InputSystem::SetShouldRestrictCursor(0, 0, 1, 1);
  UFG::InputSystem::msForceSendMouseMsgs = 0;
  v4 = UFG::TiDo::m_pInstance->vfptr;
  if ( v1->mState == 5 )
  {
    ((void (__fastcall *)(UFG::TiDo *, signed __int64))v4[1].Close)(UFG::TiDo::m_pInstance, 1i64);
    UFG::InputSystem::SetShouldHideCursor(1, 0, 1, 0);
    UFG::InputSystem::msRelativeMouseMode = 0;
  }
  else
  {
    ((void (__fastcall *)(UFG::TiDo *, signed __int64))v4[1].Close)(UFG::TiDo::m_pInstance, 4i64);
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
  UFG::UITiledMapMath::WorldGeo.MinX = v1->OldMapGeo.MinX;
  UFG::UITiledMapMath::WorldGeo.MaxX = v1->OldMapGeo.MaxX;
  UFG::UITiledMapMath::WorldGeo.MinY = v1->OldMapGeo.MinY;
  UFG::UITiledMapMath::WorldGeo.MaxY = v1->OldMapGeo.MaxY;
  UFG::UITiledMapMath::WorldGeo.TextureWidth = v1->OldMapGeo.TextureWidth;
  UFG::UITiledMapMath::WorldGeo.TextureHeight = v1->OldMapGeo.TextureHeight;
  v8 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v8 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Hide(&v8->HelpBar, gWorldMapHelpbarID);
  v9 = &v1->mLegendItems;
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&v1->mLegendItems);
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_PAUSE_SCREEN_EXIT_20,
    0xFFFFFFFF);
  UFG::UIHKScreenWorldMap::gPushedFromPauseMenu = 0;
  v10 = v1->mPolyListNative.p;
  if ( v10 )
    operator delete[](v10);
  v1->mPolyListNative.p = 0i64;
  *(_QWORD *)&v1->mPolyListNative.size = 0i64;
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&v1->mLegendItems);
  v11 = v9->mNode.mPrev;
  v12 = v1->mLegendItems.mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v9->mNode.mPrev = &v9->mNode;
  v1->mLegendItems.mNode.mNext = &v1->mLegendItems.mNode;
  v13 = v1->RacePath.m_SplinePoints.p;
  if ( v13 )
    operator delete[](v13);
  v1->RacePath.m_SplinePoints.p = 0i64;
  *(_QWORD *)&v1->RacePath.m_SplinePoints.size = 0i64;
  v14 = v1->RacePath.m_MarkerPositions.p;
  if ( v14 )
    operator delete[](v14);
  v1->RacePath.m_MarkerPositions.p = 0i64;
  *(_QWORD *)&v1->RacePath.m_MarkerPositions.size = 0i64;
  UFG::qString::~qString(&v1->RacePath.m_CurrentLayerName);
  UFG::UITiledMapGPS::~UITiledMapGPS(&v1->GPS);
  UFG::UIMapBlipManager::~UIMapBlipManager(&v1->mMinimapIconManagerClone);
  UFG::UITiledMapWidget::~UITiledMapWidget(&v1->mTiledMap);
  UFG::qString::~qString(&v1->TutorialPopup.mCaption);
  `eh vector destructor iterator(
    v1->Territory.mData,
    0x30ui64,
    20,
    (void (__fastcall *)(void *))UFG::SecondaryObjective::~SecondaryObjective);
  UFG::qString::~qString(&v1->InfoPopup.mBodyText);
  UFG::qString::~qString(&v1->InfoPopup.mTitleText);
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 223
// RVA: 0x637120
void __fastcall UFG::UIHKScreenWorldMap::init(UFG::UIHKScreenWorldMap *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenWorldMap *v2; // rsi
  UFG::Controller *v3; // rcx
  float v4; // xmm0_4
  __int64 v5; // rax
  UFG::UIScreenRenderable *v6; // rax
  float v7; // xmm0_4
  UFG::UIHKScreenWorldMap::eViewType v8; // edx
  UFG::UITiledMapTextureManager *v9; // rcx
  UFG::MinimapPoint2f v10; // [rsp+50h] [rbp+8h]
  UFG::MinimapPoint2f pos; // [rsp+60h] [rbp+18h]

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  v2->OldMapGeo.MinX = UFG::UITiledMapMath::WorldGeo.MinX;
  v2->OldMapGeo.MaxX = UFG::UITiledMapMath::WorldGeo.MaxX;
  v2->OldMapGeo.MinY = UFG::UITiledMapMath::WorldGeo.MinY;
  v2->OldMapGeo.MaxY = UFG::UITiledMapMath::WorldGeo.MaxY;
  v2->OldMapGeo.TextureWidth = UFG::UITiledMapMath::WorldGeo.TextureWidth;
  v2->OldMapGeo.TextureHeight = UFG::UITiledMapMath::WorldGeo.TextureHeight;
  UFG::UITiledMapMath::WorldGeo = UFG::UITiledMapMath::InitWorldGeo;
  v4 = UFG::UITiledMapMath::InitWorldGeo.TextureWidth;
  v5 = ((__int64 (*)(void))v2->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)();
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 48i64))(v5);
  v6 = v2->mRenderable;
  *(_QWORD *)&v2->m_mapGeo.CircleMaskX = 0i64;
  v2->m_mapGeo.IsWorldMap = 1;
  v7 = v4 * 0.5;
  v2->m_mapGeo.MaskRadius = v7;
  if ( v6->m_movie.pObject )
  {
    v2->mTiledMap.mIsWorldMap = 1;
    UFG::UITiledMapWidget::Init(&v2->mTiledMap, (UFG::UIScreen *)&v2->vfptr);
    v2->GPS.mMaxNumSplinePoints = 1100;
    v2->GPS.mGPS_UpdatePeriod = 0.2;
    UFG::UIMapBlipManager::HandleScreenInit(&UFG::UIHKScreenWorldMap::mIconManager);
    UFG::UIHKCursorWidget::HandleScreenInit((UFG::UIHKCursorWidget *)&v2->Cursor.mPos, (UFG::UIScreen *)&v2->vfptr);
    UFG::UIHKCursorWidget::SetMargin(
      (UFG::UIHKCursorWidget *)&v2->Cursor.mPos,
      (UFG::UIScreen *)&v2->vfptr,
      UFG::UIHKTweakables::WorldMap_CursorMargin,
      v7);
    v2->Legend.mState = STATE_COMPLETE;
    UFG::UIHKWorldMapLegendWidget::Flash_SetTerritoryLegendVisible(&v2->Legend, (UFG::UIScreen *)&v2->vfptr, 0);
    UFG::UITiledMapGPS::HandleScreenInit(&v2->GPS, (UFG::UIScreen *)&v2->vfptr);
    if ( (unsigned int)(v2->TutorialPopup.mState - 4) <= 1 )
      v2->TutorialPopup.mState = 0;
    if ( v2->TutorialPopup.mState )
      v2->TutorialPopup.mState = 1;
    v2->mState = 1;
    if ( UFG::UIHKScreenWorldMap::mShortcut )
    {
      v8 = v2->mViewType;
      if ( UFG::UIHKScreenWorldMap::mShortcut == 1 )
        v2->mViewType = TERRITORY_VIEW;
      v2->mViewTypeChanged |= v2->mViewType != v8;
      UFG::UIHKScreenWorldMap::mShortcut = 0;
    }
    UFG::UIHKScreenWorldMap::UpdateViewType(v2, v7);
    UFG::MinimapPoint2f::MinimapPoint2f(&pos, &v2->mOriginPos);
    UFG::UITiledMapMath::UpdatePosition(&v2->m_mapGeo, pos, 256);
    UFG::UIHKScreenWorldMap::CenterMapOnPlayerPos(v2);
    UFG::MinimapPoint2f::MinimapPoint2f(&v10, &v2->mOriginPos);
    v9 = v2->mTileStreamerLowRes;
    if ( v9 )
    {
      v7 = v10.x + -256.0;
      v10.x = v10.x + -256.0;
      v10.y = v10.y + -256.0;
      UFG::UITiledMapTextureManager::SetPlayerPosition(v9, &v10);
    }
    UFG::UIHKScreenWorldMap::ShowHelpBar(v2);
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      UI_HASH_PAUSE_SCREEN_INIT_20,
      0xFFFFFFFF);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xB6A0047E,
        0i64,
        0,
        0i64);
    UFG::UIHKScreenWorldMap::GetViewportScaleMatrix(v2, &v2->mViewportScaleMatrix, v7);
    UFG::UIHKScreenWorldMap::ShowTutorialPopup(v2);
  }
}2, &v2->mViewportScaleMatr

// File Line: 326
// RVA: 0x6406B0
void __fastcall UFG::UIHKScreenWorldMap::update(UFG::UIHKScreenWorldMap *this, float elapsed)
{
  float v2; // xmm6_4
  UFG::UIHKScreenWorldMap *v3; // rdi
  float v4; // xmm0_4
  bool v5; // al
  Scaleform::GFx::Movie *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm4_4
  int v14; // xmm2_4
  UFG::ProgressionTracker *v15; // rax
  UFG::UIHKMapLabelManager *v16; // rax
  UFG::SceneSettings settings; // [rsp+40h] [rbp-168h]

  v2 = elapsed;
  v3 = this;
  UFG::UIScreenInvokeQueue::Update(&UFG::UIHKScreenWorldMap::mScreenInvokeQueue, (UFG::UIScreen *)&this->vfptr);
  UFG::UIHKInfoPopupWidget::Update(&v3->TutorialPopup, (UFG::UIScreen *)&v3->vfptr, elapsed);
  if ( UFG::gUIViewportScale != v3->mViewportScale
    || UFG::gUIViewportScaleH != v3->mViewportScaleH
    || (v4 = UFG::gUIViewportScaleV, UFG::gUIViewportScaleV != v3->mViewportScaleV) )
  {
    v3->mViewportScale = UFG::gUIViewportScale;
    v4 = UFG::gUIViewportScaleH;
    v3->mViewportScaleH = UFG::gUIViewportScaleH;
    v3->mViewportScaleV = UFG::gUIViewportScaleV;
    UFG::UIHKScreenWorldMap::GetViewportScaleMatrix(v3, &v3->mViewportScaleMatrix, v4);
  }
  v5 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController;
  if ( v5 != v3->mIsKeyboardController )
  {
    v3->mIsKeyboardController = v5;
    v6 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&v3->vfptr);
    if ( v6 )
      Scaleform::GFx::Movie::Invoke(v6, "KeyboardControllerStatusChanged", 0i64, 0i64, 0);
  }
  switch ( v3->mState )
  {
    case 1:
      v7 = elapsed + v3->mMapFadeElapsed;
      v3->mMapFadeElapsed = v7;
      if ( v3->mBackgroundAlpha >= 0.0 )
        goto LABEL_47;
      v8 = v7 / v3->mMapFadeTime;
      if ( v8 > 0.0 )
        v8 = 0.0;
      v3->mBackgroundAlpha = v8;
      if ( v8 >= 0.0 )
      {
LABEL_47:
        if ( v3->mFlashIntroComplete )
          goto LABEL_46;
      }
      if ( v7 > v3->mIntroTimeOut )
      {
LABEL_46:
        v3->mMapFadeElapsed = 0.0;
        UFG::UIHKScreenWorldMap::FinishIntro(v3);
      }
      break;
    case 2:
      UFG::UIHKScreenWorldMap::UpdateMapFadeIn(v3, elapsed);
      if ( v3->mTilesLoadedFirstTime )
      {
        UFG::UIHKScreenWorldMap::UpdateScale(v3, elapsed);
        UFG::UIHKScreenWorldMap::UpdateMapPosition(v3, elapsed);
        UFG::UIHKScreenWorldMap::UpdateViewType(v3, v4);
        UFG::UIHKScreenWorldMap::UpdateRacePath(v3, elapsed);
        UFG::UIHKWorldMapTerritoryWidget::Update(&v3->Territory, (UFG::UIScreen *)&v3->vfptr, &v3->m_mapGeo);
        UFG::UIHKWorldMapLegendWidget::Update(&v3->Legend, (UFG::UIScreen *)&v3->vfptr);
      }
      break;
    case 3:
      UFG::UIHKScreenWorldMap::UpdateMapFadeIn(v3, elapsed);
      if ( v3->mTilesLoadedFirstTime )
      {
        UFG::UIHKScreenWorldMap::UpdateScale(v3, elapsed);
        UFG::UIHKScreenWorldMap::UpdateMapPosition(v3, elapsed);
        UFG::UIHKWorldMapLegendWidget::Update(&v3->Legend, (UFG::UIScreen *)&v3->vfptr);
      }
      break;
    case 6:
      if ( UFG::UIHKScreenGlobalOverlay::mThis
        && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
      {
        UFG::UIHK_NISOverlay::ShowElement(
          &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
          (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
          &UFG::UIHK_NISOverlay::m_curtains,
          0.33000001,
          1);
        UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 1;
      }
      UFG::UIHK_NISOverlay::UpdateAudioMuteState();
      v3->mState = 7;
      break;
    case 7:
      if ( !(UFG::UIHK_NISOverlay::m_curtains.m_state & 0xFFFFFFFD) )
      {
        v3->vfptr[1].__vecDelDtor((UFG::UIScreen *)&v3->vfptr, 1073741824u);
        UFG::TransitUtility::OnExitMap();
        UFG::SceneSettings::SceneSettings(&settings, "non-permanent-must-use-ApplySceneSettingsCached()");
        settings.mHideCurtains = 0;
        v15 = UFG::ProgressionTracker::Instance();
        UFG::ProgressionTracker::ApplySceneSettingsCached(v15, &settings);
        UFG::SceneSettings::~SceneSettings(&settings);
      }
      break;
    case 8:
      v9 = 0.0;
      if ( v3->mMapTileAlpha > 0.0 )
      {
        v10 = elapsed + v3->mMapFadeElapsed;
        v3->mMapFadeElapsed = v10;
        v11 = v10 / v3->mMapFadeTime;
        v12 = 1.0 - v11;
        if ( (float)(1.0 - v11) >= 0.0 )
          v13 = 1.0 - v11;
        else
          v13 = 0.0;
        v3->mMapTileAlpha = v13;
        if ( v12 < 0.0 )
          v12 = 0.0;
        v3->mIconAlpha = v12;
        v14 = LODWORD(v11) ^ _xmm[0];
        if ( COERCE_FLOAT(LODWORD(v11) ^ _xmm[0]) < 0.0 )
          v14 = 0;
        LODWORD(v3->mBackgroundAlpha) = v14;
        if ( (float)(UFG::UIHKTweakables::WorldMap_GridAlpha - v11) >= 0.0 )
          v9 = UFG::UIHKTweakables::WorldMap_GridAlpha - v11;
        v3->mMapGridAlpha = v9;
        v3->mTiledMap.mAlpha = v13;
      }
      UFG::UIHKScreenWorldMap::UpdateRacePath(v3, v2);
      break;
    default:
      break;
  }
  v16 = qword_142433908;
  if ( !qword_142433908 )
  {
    v16 = (UFG::UIHKMapLabelManager *)UFG::qMalloc(
                                        (unsigned int)((_DWORD)qword_142433908 + 32),
                                        "UIHKMapLabelManager",
                                        0i64);
    if ( v16 )
    {
      v16->mData.p = 0i64;
      *(_QWORD *)&v16->mData.size = 0i64;
      v16->mNumLabels = 0;
      v16->mInitialized = 0;
    }
    else
    {
      v16 = 0i64;
    }
    qword_142433908 = v16;
  }
  UFG::UIHKMapLabelManager::update(v16, (UFG::UIScreen *)&v3->vfptr, &v3->m_mapGeo);
  UFG::UITiledMapWidget::UpdateWorldMap(&v3->mTiledMap, (UFG::UIScreen *)&v3->vfptr, &v3->m_mapGeo);
  UFG::UIScreen::update((UFG::UIScreen *)&v3->vfptr, v2);
}

// File Line: 519
// RVA: 0x62E2C0
char __fastcall UFG::UIHKScreenWorldMap::handleMessage(UFG::UIHKScreenWorldMap *this, __int64 msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // edi
  UFG::UIHKScreenWorldMap *v5; // rbx
  UFG::UIScreenTextureManager *v7; // rax
  UFG::qVector3 destPos; // [rsp+30h] [rbp-18h]
  UFG::WorldPoint2f v9; // [rsp+50h] [rbp+8h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
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
        if ( v5->ObjectivesWidget.mState == STATE_INVALID )
          v5->ObjectivesWidget.mState = 1;
      }
      else if ( UI_HASH_OBJECTIVES_FADE_OUT_20 == v4 && v5->ObjectivesWidget.mState == 2 )
      {
        v5->ObjectivesWidget.mState = 3;
      }
      if ( UI_HASH_PERKGOALS_FADE_IN_20 == v4 )
      {
        if ( v5->PerkGoalsWidget.mState == STATE_INVALID )
          v5->PerkGoalsWidget.mState = 1;
      }
      else if ( UI_HASH_PERKGOALS_FADE_OUT_20 == v4 && v5->PerkGoalsWidget.mState == 2 )
      {
        v5->PerkGoalsWidget.mState = 3;
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    case 2:
      if ( !UFG::UIHKScreenWorldMap::handleMessage_StateNormal(this, msgId, msg) )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
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
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0xCCF5DDCu,
              0i64,
              0,
              0i64);
          UFG::WorldPoint2f::WorldPoint2f(&v9, &v5->Cursor.mPos, &v5->m_mapGeo);
          *(UFG::WorldPoint2f *)&destPos.x = v9;
          destPos.z = 0.0;
          UFG::TransitUtility::OnSelectDestination(&destPos);
          UFG::UIScreenDialogBox::createYesNoDialog(
            (UFG::UIScreen *)&v5->vfptr,
            "$WORLD_MAP_TRANSIT_DIAGLOG_TITLE",
            "$WORLD_MAP_TRANSIT_ENGAGE",
            0,
            0);
          v5->mState = 4;
        }
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      }
      if ( (_DWORD)msgId != UI_HASH_BUTTON_BACK_RELEASED_30 || !this->mTransitEnableBackButton )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      ((void (__fastcall *)(UFG::UIHKScreenWorldMap *))this->vfptr[1].__vecDelDtor)(this);
      UFG::UIHKScreenWorldMap::gDidPlayerCancelTaxi = 1;
      return 1;
    case 4:
      if ( (_DWORD)msgId == UI_HASH_DIALOG_YES_30 )
      {
        this->mState = 6;
      }
      else if ( (_DWORD)msgId == UI_HASH_DIALOG_NO_30 )
      {
        this->mState = 3;
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    case 5:
      if ( (_DWORD)msgId != UI_HASH_SCREEN_FADE_IN_COMPLETE_12 )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      UFG::UIScreenManagerBase::queuePopScreen(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        0xFFFFFFFF);
      v7 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueLoadAndPush(v7, "PauseMenu", 0i64);
      v5->mShouldPushHud = 0;
      v5->mWaitForScreenPush = 1;
      return 1;
    case 8:
      if ( (_DWORD)msgId != UI_HASH_OUTRO_COMPLETE_30 )
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      UFG::UIHKScreenWorldMap::Exit(this);
      return 1;
    default:
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
}

// File Line: 655
// RVA: 0x62F8A0
char __fastcall UFG::UIHKScreenWorldMap::handleMessage_StateNormal(UFG::UIHKScreenWorldMap *this, __int64 msgId, UFG::UIMessage *msg)
{
  int v3; // edi
  UFG::UIHKScreenWorldMap *v4; // rbx
  bool v6; // zf
  UFG::qVector3 worldPos; // [rsp+30h] [rbp-18h]
  UFG::WorldPoint2f v8; // [rsp+68h] [rbp+20h]

  v3 = msgId;
  v4 = this;
  if ( (_DWORD)msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 || (_DWORD)msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
  {
    if ( UFG::UIHKWorldMapCursorWidget::SelectObjective(&this->Cursor, &this->m_mapGeo) )
      UFG::UIHKScreenWorldMap::HighlightCurrentObjectiveBlip(v4);
    if ( v4->mCurrentViewHasGPS )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xC17D78C0,
          0i64,
          0,
          0i64);
      UFG::WorldPoint2f::WorldPoint2f(&v8, &v4->Cursor.mPos, &v4->m_mapGeo);
      *(UFG::WorldPoint2f *)&worldPos.x = v8;
      worldPos.z = 0.0;
      UFG::UIHKScreenWorldMap::SetGPSDestination(v4, &worldPos);
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
              (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
              &UFG::UIHK_NISOverlay::m_curtains,
              0.33000001,
              1);
            UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 1;
          }
        }
        UFG::UIHK_NISOverlay::UpdateAudioMuteState();
        ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
          UFG::TiDo::m_pInstance,
          1i64);
        v4->mState = 5;
        return 1;
      }
LABEL_11:
      ((void (__fastcall *)(UFG::UIHKScreenWorldMap *, __int64, UFG::UIMessage *))this->vfptr[1].__vecDelDtor)(
        this,
        msgId,
        msg);
      return 1;
    }
    if ( (_DWORD)msgId == UI_HASH_BUTTON_SELECT_PRESSED_30 && !UFG::UIHKScreenWorldMap::gPushedFromPauseMenu )
      goto LABEL_11;
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
          (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
          &UFG::UIHK_NISOverlay::m_curtains,
          0.33000001,
          1);
        UFG::UIHK_NISOverlay::m_curtains.m_mutingAudio = 1;
      }
      UFG::UIHK_NISOverlay::UpdateAudioMuteState();
      ((void (__fastcall *)(UFG::TiDo *, signed __int64))UFG::TiDo::m_pInstance->vfptr[1].Close)(
        UFG::TiDo::m_pInstance,
        1i64);
      v4->mState = 5;
      return 1;
    }
  }
  if ( v3 == UI_HASH_FADE_IN_COMPLETE_30 )
  {
    v4->InfoPopup.mState = 3;
  }
  else if ( v3 == UI_HASH_FADE_OUT_COMPLETE_30 )
  {
    v6 = v4->InfoPopup.mVisible == 0;
    v4->InfoPopup.mState = 0;
    v4->InfoPopup.mVisible = 0;
    v4->InfoPopup.mChanged |= !v6;
  }
  if ( v3 == UI_HASH_WIDGET_FADE_IN_20 )
  {
    v4->Legend.mState = 5;
  }
  else if ( v3 == UI_HASH_WIDGET_FADE_OUT_20 )
  {
    v4->Legend.mState = 3;
  }
  if ( UI_HASH_OBJECTIVES_FADE_IN_20 == v3 )
  {
    if ( v4->ObjectivesWidget.mState == STATE_INVALID )
      v4->ObjectivesWidget.mState = 1;
  }
  else if ( UI_HASH_OBJECTIVES_FADE_OUT_20 == v3 && v4->ObjectivesWidget.mState == 2 )
  {
    v4->ObjectivesWidget.mState = 3;
  }
  if ( UI_HASH_PERKGOALS_FADE_IN_20 == v3 )
  {
    if ( v4->PerkGoalsWidget.mState == STATE_INVALID )
    {
      v4->PerkGoalsWidget.mState = 1;
      return 0;
    }
  }
  else if ( UI_HASH_PERKGOALS_FADE_OUT_20 == v3 && v4->PerkGoalsWidget.mState == 2 )
  {
    v4->PerkGoalsWidget.mState = 3;
  }
  return 0;
}

// File Line: 772
// RVA: 0x612A10
void __fastcall UFG::UIHKScreenWorldMap::ToggleCollectibles(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rbx
  UFG::HudAudio *v2; // rcx
  unsigned int v3; // edx

  v1 = this;
  if ( this->mViewType == 3 )
  {
    this->mViewType = 0;
    UFG::UIHKScreenWorldMap::Flash_SetViewType(this, 0);
    v1->mViewTypeChanged = 1;
    UFG::UIHKScreenWorldMap::UpdateViewType(v1);
    v2 = UFG::HudAudio::m_instance;
    if ( !UFG::HudAudio::m_instance )
      return;
    v3 = -782291096;
  }
  else
  {
    this->mViewType = 3;
    UFG::UIHKScreenWorldMap::Flash_SetViewType(this, 1);
    v1->mViewTypeChanged = 1;
    UFG::UIHKScreenWorldMap::UpdateViewType(v1);
    v2 = UFG::HudAudio::m_instance;
    if ( !UFG::HudAudio::m_instance )
      return;
    v3 = -1616300686;
  }
  UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v2->vfptr, v3, 0i64, 0, 0i64);
}

// File Line: 793
// RVA: 0x612AA0
void __fastcall UFG::UIHKScreenWorldMap::ToggleObjectives(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rbx

  v1 = this;
  UFG::UIHKWorldMapObjectivesWidget::ToggleOpen(&this->ObjectivesWidget, (UFG::UIScreen *)&this->vfptr);
  UFG::UIHKWorldMapPerkGoalsWidget::ToggleOpen(&v1->PerkGoalsWidget, (UFG::UIScreen *)&v1->vfptr);
}

// File Line: 800
// RVA: 0x60C800
char __fastcall UFG::UIHKScreenWorldMap::SetWorldMapFromVehicle(UFG::SimObject *vehicle)
{
  UFG::SimObject *v1; // rdi
  char result; // al
  char v3; // bl
  char v4; // si

  v1 = vehicle;
  if ( UFG::SimObjectUtility::IsClassType(vehicle, (UFG::qSymbol *)&qSymbol_Taxi.mUID) )
  {
    UFG::UIHKScreenWorldMap::mViewMode = 1;
    UFG::UIHKScreenWorldMap::gDidPlayerCancelTaxi = 0;
    result = 1;
  }
  else
  {
    v3 = UFG::SimObjectUtility::IsClassType(v1, (UFG::qSymbol *)&qSymbol_Tram.mUID);
    v4 = UFG::SimObjectUtility::IsClassType(v1, (UFG::qSymbol *)&qSymbol_Ferry.mUID);
    result = UFG::SimObjectUtility::IsClassType(v1, (UFG::qSymbol *)&qSymbol_Minibus.mUID);
    if ( v3 || v4 || result )
    {
      UFG::UIHKScreenWorldMap::mViewMode = 1;
      UFG::UIHKScreenWorldMap::gDidPlayerCancelTaxi = 0;
      result = 1;
    }
  }
  return result;
}

// File Line: 826
// RVA: 0x5D89B0
void __fastcall UFG::UIHKScreenWorldMap::FinishIntro(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rbx
  UFG::UIHKMapLabelManager *v2; // rax

  v1 = this;
  this->mState = (UFG::UIHKScreenWorldMap::mViewMode == 1) + 2;
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
  UFG::UIHKMapLabelManager::HandleScreenInit(v2, (UFG::UIScreen *)&v1->vfptr);
}

// File Line: 844
// RVA: 0x638FF0
void __fastcall UFG::UIHKScreenWorldMap::outro(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rbx
  Scaleform::GFx::Movie *v2; // rcx
  UFG::UIHKMapLabelManager *v3; // rax
  UFG::UIHKScreenGlobalOverlay *v4; // rax

  v1 = this;
  UFG::UIScreen::outro((UFG::UIScreen *)&this->vfptr, 0i64);
  v1->mState = 8;
  UFG::UIHKScreenWorldMap::mViewMode = 0;
  v1->mMapFadeElapsed = 0.0;
  if ( v1->Legend.mState == 5 )
  {
    v1->Legend.mToggleFadeOut = 1;
    v1->Legend.mChanged = 1;
  }
  UFG::UIHKWorldMapLegendWidget::Update(&v1->Legend, (UFG::UIScreen *)&v1->vfptr);
  if ( v1->ObjectivesWidget.mState <= 1u )
  {
    v1->ObjectivesWidget.mState = 2;
    UFG::UIScreen::invoke((UFG::UIScreen *)&v1->vfptr, "Objectives_Hide");
  }
  if ( v1->PerkGoalsWidget.mState <= 1u )
  {
    v1->PerkGoalsWidget.mState = 2;
    v2 = v1->mRenderable->m_movie.pObject;
    if ( v2 )
      Scaleform::GFx::Movie::Invoke(v2, "PerkGoals_Hide", 0i64, 0i64, 0);
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
  UFG::UIHKMapLabelManager::StartOutro(v3, (UFG::UIScreen *)&v1->vfptr);
  v4 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v4 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Hide(&v4->HelpBar, gWorldMapHelpbarID);
  if ( v1->mRacePathState != 3 )
    v1->mRacePathState = 2;
}

// File Line: 865
// RVA: 0x5E6900
UFG::UIScreen *__fastcall UFG::UIHKScreenWorldMap::Get()
{
  return UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "WorldMap");
}

// File Line: 879
// RVA: 0x5D7C20
void __fastcall UFG::UIHKScreenWorldMap::Exit(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rbx
  bool v2; // di
  bool v3; // al
  ANTLR3_INPUT_STREAM_struct *v4; // rax

  v1 = this;
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    this->mScreenUID);
  v2 = UFG::UIHKScreenWorldMap::gDidPlayerCancelTaxi == 0;
  v3 = (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateChangeLocation_13
    || (unsigned int)UFG::FlowController::GetPendingState(&UFG::gFlowController) == uidGameStateChangeLocation_13;
  if ( v2 && v3 )
  {
    v4 = (ANTLR3_INPUT_STREAM_struct *)UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::SetGameState(v4, 8u);
  }
  v1->mFinished = 1;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xA4E5BFBD,
      0i64,
      0,
      0i64);
}

// File Line: 898
// RVA: 0x60FA60
void __fastcall UFG::UIHKScreenWorldMap::ShowHelpBar(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // r14
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIHKHelpBarWidget *v3; // rdi
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
  UFG::UIHKHelpBarData data; // [rsp+20h] [rbp-D8h]
  __int64 v33; // [rsp+268h] [rbp+170h]

  v33 = -2i64;
  v1 = this;
  if ( UFG::UIHKScreenWorldMap::mViewMode == 1 )
  {
    v2 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( this->mTransitEnableBackButton )
    {
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v2 = &gGlobalOverlaySentinel;
      v3 = &v2->HelpBar;
      v4 = gWorldMapHelpbarID;
      UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
      data.id = v4;
      *(_QWORD *)&data.priority = 0i64;
      _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
      *(_QWORD *)&data.Buttons[4] = 0i64;
      UFG::qString::Set(data.Captions, "$WORLDMAP_SET_DESTINATION_UPPERCASE");
      UFG::qString::Set(&data.Captions[1], "$COMMON_ZOOM_UPPERCASE");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), "$COMMON_CANCEL");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 32), &customWorldMapCaption);
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 32), &customWorldMapCaption);
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 32), &customWorldMapCaption);
      *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
      *(_QWORD *)data.MessageIds = 0i64;
      *(_QWORD *)&data.MessageIds[2] = 0i64;
      UFG::UIHKHelpBarWidget::Show(v3, &data);
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
      _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
      *(_QWORD *)&data.Buttons[4] = 0i64;
      UFG::qString::Set(data.Captions, "$WORLDMAP_SET_DESTINATION_UPPERCASE");
      UFG::qString::Set(&data.Captions[1], "$COMMON_ZOOM_UPPERCASE");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), "$WORLD_MAP_COLLECTIBLES_VIEW");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 32), &customWorldMapCaption);
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 32), &customWorldMapCaption);
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 32), &customWorldMapCaption);
      *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
      *(_QWORD *)data.MessageIds = 0i64;
      *(_QWORD *)&data.MessageIds[2] = 0i64;
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
    data.Buttons[v9] = 1;
    v10 = v7;
    UFG::qString::Set(&data.Captions[v10], "$WORLDMAP_SET_WAYPOINT_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v10 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v9 * 4) = 0;
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
    data.Buttons[v13] = 2;
    v14 = v11;
    UFG::qString::Set(&data.Captions[v14], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v14 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v13 * 4) = 0;
LABEL_19:
    if ( v1->mViewType != 3 )
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
      data.Buttons[v17] = 4;
      v18 = v15;
      UFG::qString::Set(&data.Captions[v18], "$WORLDMAP_OBJECTIVES_CAPS");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v18 + 5] + 32), &customWorldMapCaption);
      *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v17 * 4) = 0;
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
    data.Buttons[v21] = 14;
    v22 = v19;
    UFG::qString::Set(&data.Captions[v22], "$COMMON_ZOOM_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v22 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v21 * 4) = 0;
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
    data.Buttons[v25] = 8;
    v26 = v23;
    UFG::qString::Set(&data.Captions[v26], "$WORLDMAP_LEGEND_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v26 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v25 * 4) = 0;
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
    data.Buttons[v29] = 3;
    v30 = v27;
    UFG::qString::Set(&data.Captions[v30], "$WORLD_MAP_COLLECTIBLES_VIEW");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v30 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v29 * 4) = 0;
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
  UFG::UIHKScreenWorldMap *v2; // rbx
  UFG::UITiledMapMath *mapGeo; // rsi
  float v4; // xmm6_4
  float v5; // xmm0_4
  UFG::InputActionData *v6; // rcx
  float v7; // xmm1_4
  float v8; // xmm4_4
  UFG::UITiledMapTextureManager *v9; // rcx
  float v10; // xmm0_4
  float v11; // xmm1_4
  UFG::UIAmbientMapBlipManager *v12; // rax
  bool isIndoors[8]; // [rsp+48h] [rbp+7h]
  bool forceUpdate[4]; // [rsp+50h] [rbp+Fh]
  UFG::qVector3 playerPos; // [rsp+58h] [rbp+17h]
  UFG::qVector3 dir; // [rsp+68h] [rbp+27h]
  UFG::ScreenPoint2f offset; // [rsp+A8h] [rbp+67h]
  void *retaddr; // [rsp+B8h] [rbp+77h]

  v2 = this;
  mapGeo = &this->m_mapGeo;
  v4 = elapsed;
  UFG::UIHKWorldMapCursorWidget::Update(
    &this->Cursor,
    (UFG::UIScreen *)&this->vfptr,
    &this->mMinimapIconManagerClone,
    &this->m_mapGeo);
  v5 = 0.0;
  if ( !v2->mLockMapScrolling )
  {
    offset = v2->Cursor.mEdgePush;
    v6 = UFG::ActionDef_UIRightThumbstick.mDataPerController[UFG::gActiveControllerNum];
    if ( v6 )
      v7 = v6->mAxisPositionX;
    else
      v7 = 0.0;
    if ( v6 )
      v5 = v6->mAxisPositionY;
    v8 = 1.0 / v2->m_mapGeo.scale;
    if ( COERCE_FLOAT(LODWORD(offset.x) & _xmm) <= COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                                                  (float)(UFG::UIHKTweakables::WorldMap_PanSpeed * v7)
                                                                * v8) & _xmm) )
      offset.x = (float)(UFG::UIHKTweakables::WorldMap_PanSpeed * v7) * v8;
    if ( COERCE_FLOAT(LODWORD(offset.y) & _xmm) <= COERCE_FLOAT((COERCE_UNSIGNED_INT(
                                                                   (float)(UFG::UIHKTweakables::WorldMap_PanSpeed * v5)
                                                                 * v8) ^ _xmm[0]) & _xmm) )
      LODWORD(offset.y) = COERCE_UNSIGNED_INT((float)(UFG::UIHKTweakables::WorldMap_PanSpeed * v5) * v8) ^ _xmm[0];
    UFG::UIHKScreenWorldMap::MoveCenter(v2, offset);
  }
  UFG::UIHKWorldMapInfoPopupWidget::Update(&v2->InfoPopup, (UFG::UIScreen *)&v2->vfptr);
  UFG::MinimapPoint2f::MinimapPoint2f((UFG::MinimapPoint2f *)&retaddr, &v2->mOriginPos);
  v9 = v2->mTileStreamerLowRes;
  if ( v9 )
  {
    *(float *)&retaddr = *(float *)&retaddr + -256.0;
    *((float *)&retaddr + 1) = *((float *)&retaddr + 1) + -256.0;
    UFG::UITiledMapTextureManager::SetPlayerPosition(v9, (UFG::MinimapPoint2f *)&retaddr);
  }
  UFG::UITiledMapGPS::Update(&v2->GPS, v4, (UFG::UIScreen *)&v2->vfptr, mapGeo);
  UFG::UIMapLinesWidget::Update(&UFG::UIHKScreenWorldMap::MapLines, v4, mapGeo);
  playerPos.z = 0.0;
  v11 = v2->mOriginPos.y;
  playerPos.x = v2->mOriginPos.x;
  v10 = playerPos.x;
  playerPos.y = v11;
  v2->mPolyListNative.size = 0;
  v12 = UFG::UIAmbientMapBlipManager::getInstance(v10);
  UFG::UIAmbientMapBlipManager::Update(v12, v4, &v2->mMinimapIconManagerClone, 1);
  UFG::UIMapBlipManager::Update(
    &UFG::UIHKScreenWorldMap::mIconManager,
    (UFG::UIScreen *)&v2->vfptr,
    v4,
    &playerPos,
    mapGeo,
    mapGeo,
    &v2->mPolyListNative,
    &v2->mPolyListNative,
    &v2->mPolyListNative,
    1,
    0);
  UFG::UIMapBlipManager::Update(
    &v2->mMinimapIconManagerClone,
    (UFG::UIScreen *)&v2->vfptr,
    v4,
    &playerPos,
    mapGeo,
    mapGeo,
    &v2->mPolyListNative,
    &v2->mPolyListNative,
    &v2->mPolyListNative,
    1,
    0);
  if ( !UFG::UI::GetPlayerWorldPosition((UFG::qVector3 *)isIndoors, &dir) )
  {
    *(_QWORD *)isIndoors = 0i64;
    *(_DWORD *)forceUpdate = 0;
    dir.x = 0.0;
    dir.y = 1.0;
  }
  dir.z = 0.0;
  UFG::UIHKScreenWorldMap::PlacePlayerIcon(v2, (UFG::qVector3 *)isIndoors, &dir);
  _((AMD_HD3D *)&v2->mMinimapIconManagerClone);
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
  float v2; // xmm6_4
  UFG::UIHKScreenWorldMap *v3; // rsi
  UFG::InputActionData *v4; // rax
  float v5; // xmm2_4
  bool v6; // r9
  UFG::InputActionData *v7; // rax
  bool v8; // dl
  UFG::InputActionData *v9; // rax
  UFG::InputActionData *v10; // rax
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  __int64 v14; // rax
  __int64 v15; // rax
  float v16; // xmm0_4
  float v17; // xmm1_4
  UFG::ScreenPoint2f point; // [rsp+50h] [rbp+8h]
  UFG::WorldPoint2f v19; // [rsp+60h] [rbp+18h]

  v2 = this->m_mapGeo.scale;
  v3 = this;
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
    if ( !v8 && v2 > UFG::UIHKTweakables::WorldMap_MinZoom )
    {
      v11 = v2 - (float)((float)((float)(UFG::UIHKTweakables::WorldMap_ZoomSpeed * elapsed) * v5) * v2);
LABEL_25:
      this->m_mapGeo.scale = v11;
      goto LABEL_26;
    }
  }
  else if ( v8 && v2 < UFG::UIHKTweakables::WorldMap_MaxZoom )
  {
    v11 = (float)((float)((float)(UFG::UIHKTweakables::WorldMap_ZoomSpeed * elapsed) * v5) * v2) + v2;
    goto LABEL_25;
  }
LABEL_26:
  v12 = this->m_mapGeo.scale;
  if ( v12 <= UFG::UIHKTweakables::WorldMap_MinZoom )
    v12 = UFG::UIHKTweakables::WorldMap_MinZoom;
  if ( v12 >= UFG::UIHKTweakables::WorldMap_MaxZoom )
    v12 = UFG::UIHKTweakables::WorldMap_MaxZoom;
  this->m_mapGeo.scale = v12;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v12 - v2) & _xmm) > 0.0000099999997 )
  {
    UFG::ScreenPoint2f::ScreenPoint2f(&point, &this->mOriginPos, &this->m_mapGeo);
    v13 = v3->m_mapGeo.scale / v2;
    v14 = ((__int64 (*)(void))v3->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)();
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v14 + 48i64))(v14);
    v15 = ((__int64 (*)(void))v3->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)();
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v15 + 56i64))(v15);
    point.x = point.x + (float)((float)(v13 * (float)(1.0 - v13)) * -0.5);
    point.y = point.y + (float)((float)(v13 * (float)(1.0 - v13)) * -0.5);
    UFG::WorldPoint2f::WorldPoint2f(&v19, &point, &v3->m_mapGeo);
    v16 = v19.x;
    v17 = v19.y;
    v3->mOriginPos.x = v19.x;
    v3->mOriginPos.y = v17;
    UFG::UIHKScreenWorldMap::BoundMapOrigin(v3, v16);
  }
}

// File Line: 1114
// RVA: 0x5F3CE0
void __fastcall UFG::UIHKScreenWorldMap::PlacePlayerIcon(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rbx
  UFG::qVector3 dir; // [rsp+20h] [rbp-28h]
  UFG::qVector3 pos; // [rsp+30h] [rbp-18h]

  v1 = this;
  if ( !UFG::UI::GetPlayerWorldPosition(&pos, &dir) )
  {
    *(_QWORD *)&pos.x = 0i64;
    pos.z = 0.0;
    LODWORD(dir.y) = (_DWORD)FLOAT_1_0;
    dir.x = 0.0;
  }
  dir.z = 0.0;
  UFG::UIHKScreenWorldMap::PlacePlayerIcon(v1, &pos, &dir);
}

// File Line: 1128
// RVA: 0x5F3B10
void __fastcall UFG::UIHKScreenWorldMap::PlacePlayerIcon(UFG::UIHKScreenWorldMap *this, UFG::qVector3 *playerPos, UFG::qVector3 *playerForward)
{
  UFG::UIHKScreenWorldMap *v3; // rsi
  UFG::qVector3 *v4; // rdi
  UFG::qVector3 *v5; // rbx
  float v6; // xmm3_4
  float v7; // xmm7_4
  float i; // xmm7_4
  UFG::qVector3 v2; // [rsp+30h] [rbp-48h]
  UFG::MinimapPoint2f v10; // [rsp+80h] [rbp+8h]
  UFG::ScreenPoint2f v11; // [rsp+88h] [rbp+10h]
  UFG::WorldPoint2f point; // [rsp+90h] [rbp+18h]
  UFG::MinimapTilePoint2f iconPos; // [rsp+98h] [rbp+20h]

  v3 = this;
  v4 = playerPos;
  v5 = playerForward;
  UFG::qStringHash32("the_player", 0xFFFFFFFF);
  v2.x = 0.0;
  *(_QWORD *)&v2.y = 1065353216i64;
  v6 = FLOAT_N1_0;
  v7 = (float)(UFG::qAngleBetween(v5, &v2) * 180.0) * 0.31830987;
  if ( (float)((float)(v2.x * v5->y) - (float)(v2.y * v5->x)) < 0.0 )
    v6 = *(float *)&FLOAT_1_0;
  for ( i = v7 * v6; i < -180.0; i = i + 360.0 )
    ;
  for ( ; i > 180.0; i = i + -360.0 )
    ;
  UFG::WorldPoint2f::WorldPoint2f(&point, v4);
  UFG::MinimapPoint2f::MinimapPoint2f(&v10, &point);
  if ( v4->y > 1690.0 && v4->z > 20.0 )
  {
    v10.x = v10.x + UFG::UITiledMapTweakables::WorldMap_ElectionBlipOffsetX;
    v10.y = v10.y + UFG::UITiledMapTweakables::WorldMap_ElectionBlipOffsetY;
  }
  UFG::MinimapTilePoint2f::MinimapTilePoint2f(&iconPos, &v10, &v3->m_mapGeo);
  v11 = 0i64;
  UFG::ScreenPoint2f::InitFromIconPos(&v11, &iconPos, &v3->m_mapGeo);
  UFG::UIMapBlipManager::UpdatePlayerArrow(&v3->mMinimapIconManagerClone, (signed int)v11.x, (signed int)v11.y, i, 1);
}

// File Line: 1166
// RVA: 0x5F1E40
void __fastcall UFG::UIHKScreenWorldMap::MoveCenter(UFG::UIHKScreenWorldMap *this, UFG::ScreenPoint2f offset)
{
  UFG::UIHKScreenWorldMap *v2; // rdi
  float v3; // xmm1_4
  float v4; // xmm0_4
  UFG::MinimapPoint2f pos; // [rsp+30h] [rbp+8h]
  UFG::ScreenPoint2f v6; // [rsp+38h] [rbp+10h]

  v6 = offset;
  v2 = this;
  v3 = offset.y
     * COERCE_FLOAT(COERCE_UNSIGNED_INT(
                      (float)(UFG::UITiledMapMath::WorldGeo.MaxY - UFG::UITiledMapMath::WorldGeo.MinY)
                    / UFG::UITiledMapMath::WorldGeo.TextureHeight) ^ _xmm[0]);
  this->mOriginPos.x = (float)((float)((float)(UFG::UITiledMapMath::WorldGeo.MaxX - UFG::UITiledMapMath::WorldGeo.MinX)
                                     / UFG::UITiledMapMath::WorldGeo.TextureWidth)
                             * offset.x)
                     + this->mOriginPos.x;
  v4 = this->mOriginPos.y - v3;
  this->mOriginPos.y = v4;
  UFG::UIHKScreenWorldMap::BoundMapOrigin(this, v4);
  UFG::MinimapPoint2f::MinimapPoint2f(&pos, &v2->mOriginPos);
  UFG::UITiledMapMath::UpdatePosition(&v2->m_mapGeo, pos, 256);
}

// File Line: 1200
// RVA: 0x5D4B60
void __fastcall UFG::UIHKScreenWorldMap::CenterMapOnPlayerPos(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rdi
  UFG::UIScreenRenderable *v2; // rax
  float v3; // xmm0_4
  float v4; // xmm1_4
  __int64 v5; // rdx
  __int64 v6; // rax
  __int64 v7; // rdx
  __int64 v8; // rax
  UFG::qVector3 pos; // [rsp+20h] [rbp-48h]
  UFG::qVector3 dir; // [rsp+30h] [rbp-38h]
  UFG::MinimapTilePoint2f v11; // [rsp+70h] [rbp+8h]
  UFG::ScreenPoint2f offset; // [rsp+78h] [rbp+10h]
  UFG::WorldPoint2f point; // [rsp+80h] [rbp+18h]
  UFG::MinimapPoint2f v14; // [rsp+88h] [rbp+20h]

  v1 = this;
  if ( !UFG::UI::GetPlayerWorldPosition(&pos, &dir) )
  {
    *(_QWORD *)&pos.x = 0i64;
    pos.z = 0.0;
  }
  UFG::WorldPoint2f::WorldPoint2f(&point, &pos);
  UFG::MinimapPoint2f::MinimapPoint2f(&v14, &point);
  UFG::MinimapTilePoint2f::MinimapTilePoint2f(&v11, &v14, &v1->m_mapGeo);
  v2 = v1->mRenderable;
  v4 = v11.y + v1->m_mapGeo.screenPosition.y;
  v11.x = v11.x + v1->m_mapGeo.screenPosition.x;
  v3 = v11.x;
  v11.y = v4;
  v6 = ((__int64 (__cdecl *)(Scaleform::GFx::Movie *, __int64))v2->m_movie.pObject->vfptr[1].__vecDelDtor)(
         v2->m_movie.pObject,
         v5);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 48i64))(v6);
  v8 = ((__int64 (__cdecl *)(Scaleform::GFx::Movie *, __int64))v1->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)(
         v1->mRenderable->m_movie.pObject,
         v7);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 56i64))(v8);
  offset.x = v11.x - (float)(v3 * 0.5);
  offset.y = (float)(v3 * 0.5) - v11.y;
  UFG::UIHKScreenWorldMap::MoveCenter(v1, offset);
}

// File Line: 1227
// RVA: 0x5D4290
void __usercall UFG::UIHKScreenWorldMap::BoundMapOrigin(UFG::UIHKScreenWorldMap *this@<rcx>, float a2@<xmm0>)
{
  UFG::UIHKScreenWorldMap *v2; // rbx
  float v3; // xmm8_4
  __int64 v4; // rax
  float v5; // xmm6_4
  float v6; // xmm0_4
  float v7; // xmm7_4
  __int64 v8; // rax
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm1_4

  v2 = this;
  v3 = UFG::UIHKTweakables::WorldMap_MinX;
  v4 = ((__int64 (*)(void))this->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)();
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 48i64))(v4);
  v5 = UFG::UIHKTweakables::WorldMap_MinY;
  v6 = a2 / v2->m_mapGeo.scale;
  v7 = UFG::UIHKTweakables::WorldMap_MaxX - v6;
  v8 = ((__int64 (*)(void))v2->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)();
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 56i64))(v8);
  v9 = (float)(v6 / v2->m_mapGeo.scale) + UFG::UIHKTweakables::WorldMap_MaxY;
  if ( v3 > v7 )
    v3 = v7;
  if ( v5 < v9 )
    v5 = v9;
  v10 = v2->mOriginPos.x;
  if ( v10 <= v7 )
  {
    if ( v10 < v3 )
      v2->mOriginPos.x = v3;
  }
  else
  {
    v2->mOriginPos.x = v7;
  }
  v11 = v2->mOriginPos.y;
  if ( v11 >= v9 )
  {
    if ( v11 > v5 )
      v2->mOriginPos.y = v5;
  }
  else
  {
    v2->mOriginPos.y = v9;
  }
}

// File Line: 1282
// RVA: 0x6109A0
void __fastcall UFG::UIHKScreenWorldMap::ShowInfoPopup(UFG::UIHKScreenWorldMap *this, float x, float y, const char *titleText, const char *bodyText)
{
  UFG::UIHKScreenWorldMap *v5; // rbx
  UFG::UIHKWorldMapInfoPopupWidget::eState v6; // ecx
  bool v7; // al
  int v8; // ecx

  this->InfoPopup.mPosX = x;
  this->InfoPopup.mPosY = y;
  v5 = this;
  this->InfoPopup.mChanged = 1;
  UFG::qString::Set(&this->InfoPopup.mTitleText, titleText);
  v5->InfoPopup.mChanged = 1;
  UFG::qString::Set(&v5->InfoPopup.mBodyText, bodyText);
  v6 = v5->InfoPopup.mState;
  v7 = v5->InfoPopup.mVisible != 1;
  v5->InfoPopup.mVisible = 1;
  v5->InfoPopup.mChanged |= v7;
  if ( v6 == STATE_IDLE || (v8 = v6 - 1) != 0 && v8 == 1 )
  {
    v5->InfoPopup.mState = 1;
    v5->InfoPopup.mCueAnimation = 1;
  }
}

// File Line: 1325
// RVA: 0x61CE70
void __fastcall UFG::UIHKScreenWorldMap::UpdateRacePath(UFG::UIHKScreenWorldMap *this, float elapsed)
{
  UFG::UIHKScreenWorldMap::eRacePathState v2; // eax
  float v3; // xmm1_4
  double v4; // xmm0_8
  double v5; // xmm1_8
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm1_4

  v2 = this->mRacePathState;
  if ( v2 )
  {
    if ( v2 == 2 )
    {
      if ( this->mRacePathAlpha <= 0.0 )
      {
        this->mRacePathState = 3;
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
      this->mRacePathState = 1;
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
void __fastcall UFG::UIHKScreenWorldMap::RefreshSecondaryObjectives(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap::DisplaySecondaryObjectives(this);
}

// File Line: 1397
// RVA: 0x61D860
void __usercall UFG::UIHKScreenWorldMap::UpdateViewType(UFG::UIHKScreenWorldMap *this@<rcx>, float a2@<xmm0>)
{
  UFG::UIHKScreenWorldMap *v2; // rbx
  signed int v3; // edi
  bool v4; // al
  bool v5; // cl
  bool v6; // cl
  UFG::UIAmbientMapBlipManager *v7; // rax
  UFG::UIScreenRenderable *v8; // rax
  Scaleform::GFx::Movie *v9; // rdi
  unsigned int v10; // eax
  UFG::UIGfxTranslator *v11; // rcx
  const char *v12; // rax
  char *v13; // rsi
  Scaleform::GFx::Movie *v14; // rcx
  const char *v15; // rdx
  UFG::qSymbolUC *v16; // rbx
  UFG::qArray<UFG::qSymbolUC,0> blipTypes; // [rsp+20h] [rbp-21h]
  UFG::qString v18; // [rsp+30h] [rbp-11h]
  char ptr; // [rsp+58h] [rbp+17h]
  __int64 v20; // [rsp+68h] [rbp+27h]
  unsigned int v21; // [rsp+70h] [rbp+2Fh]
  char *v22; // [rsp+78h] [rbp+37h]

  v2 = this;
  if ( !this->mViewTypeChanged )
    return;
  this->mViewTypeChanged = 0;
  UFG::UIMapBlipManager::Clear(&this->mMinimapIconManagerClone);
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&v2->mLegendItems);
  v2->mLegendPageNumber = 1;
  UFG::UIHKScreenWorldMap::AddLegendItem(v2, "player_arrow", "$MAP_LEGEND_PLAYER");
  blipTypes.p = 0i64;
  *(_QWORD *)&blipTypes.size = 0i64;
  v3 = 0;
  do
  {
    v4 = UFG::UIHKScreenWorldMap::SetUpLegend(v2, &blipTypes, 0);
    if ( !v4 )
      v2->mViewTypeChanged = 0;
    ++v3;
  }
  while ( v3 <= 20 && !v4 );
  v5 = v2->mViewType == 4;
  v2->Legend.mChanged |= v2->Legend.mTerritoryMode != v5;
  v2->Legend.mTerritoryMode = v5;
  v6 = v2->mViewType == 4;
  v2->Territory.mChanged |= v2->Territory.mVisible != v6;
  v2->Territory.mVisible = v6;
  UFG::UIHKWorldMapCollectiblesStatsWidget::Flash_SetVisible(
    &v2->CollectiblesStats,
    (UFG::UIScreen *)&v2->vfptr,
    v2->mViewType == 3);
  v7 = UFG::UIAmbientMapBlipManager::getInstance(a2);
  UFG::UIAmbientMapBlipManager::HandleScreenInit(v7);
  if ( UFG::UIHKScreenWorldMap::mViewMode == 1 )
  {
    UFG::UITiledMapGPS::SetActive(&v2->GPS, 0);
    *(_QWORD *)&blipTypes.size = Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v21 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v20 + 16i64))(v20, &ptr, v22);
      v20 = 0i64;
    }
    v21 = 2;
    LOBYTE(v22) = 1;
    v8 = v2->mRenderable;
    if ( v8 )
    {
      v9 = v8->m_movie.pObject;
      if ( v9 )
      {
        Scaleform::GFx::Movie::Invoke(v9, "Transit_ShowButton", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
        v10 = UFG::qStringHashUpper32("WORLD_MAP_TRANSIT_DIAGLOG_TITLE", 0xFFFFFFFF);
        v11 = UFG::UIScreenManager::s_instance->m_translator;
        if ( !v11
          || (v12 = (const char *)v11->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, v10)) == 0i64 )
        {
          v12 = "WORLD_MAP_TRANSIT_DIAGLOG_TITLE";
        }
        UFG::qString::qString(&v18, v12);
        v13 = v18.mData;
        if ( (v21 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v20 + 16i64))(v20, &ptr, v22);
          v20 = 0i64;
        }
        v21 = 6;
        v22 = v13;
        Scaleform::GFx::Movie::Invoke(v9, "SetMapTitle", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
        UFG::qString::~qString(&v18);
      }
    }
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
  UFG::UIMapBlipManager::PopulateWorldMap(
    &v2->mMinimapIconManagerClone,
    (UFG::UIScreen *)&v2->vfptr,
    UFG::UIHKScreenHud::mIconManager,
    &blipTypes,
    a2);
  v14 = v2->mRenderable->m_movie.pObject;
  if ( v2->mViewType == 4 )
  {
    if ( v14 )
    {
      v15 = "Legend_Resize_Territory";
LABEL_24:
      Scaleform::GFx::Movie::Invoke(v14, v15, 0i64, 0i64, 0);
      goto LABEL_25;
    }
  }
  else if ( v14 )
  {
    v15 = "Legend_Resize";
    goto LABEL_24;
  }
LABEL_25:
  UFG::UIHKScreenWorldMap::ShowLegend(v2, v2->mLegendPageNumber);
  UFG::UIHKScreenWorldMap::ShowHelpBar(v2);
  UFG::UIHKScreenWorldMap::PlacePlayerIcon(v2);
  UFG::UIHKScreenWorldMap::HighlightCurrentObjectiveBlip(v2);
  UFG::UIHKScreenWorldMap::SetUpObjectiveView(v2);
  if ( v2->mViewType == 4 )
  {
    v2->mCurrentViewHasGPS = 0;
    UFG::UITiledMapGPS::SetActive(&v2->GPS, 0);
  }
  else
  {
    v2->mCurrentViewHasGPS = 1;
    UFG::UITiledMapGPS::PopulateWorldMap(UFG::UIHKScreenHud::GPS, &v2->GPS);
  }
  if ( blipTypes.p )
  {
    v16 = blipTypes.p - 1;
    `eh vector destructor iterator(blipTypes.p, 4ui64, blipTypes.p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v16);
  }
}

// File Line: 1570
// RVA: 0x1570FA0
__int64 UFG::_dynamic_initializer_for__sym_cop_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_symbol", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_symbol, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_cop_symbol__);
}

// File Line: 1571
// RVA: 0x1570EE0
__int64 UFG::_dynamic_initializer_for__sym_cop_foot_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_foot_symbol", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_foot_symbol, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_cop_foot_symbol__);
}

// File Line: 1572
// RVA: 0x1570EA0
__int64 UFG::_dynamic_initializer_for__sym_cop_foot_patrol_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_foot_patrol_symbol", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_foot_patrol_symbol, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_cop_foot_patrol_symbol__);
}

// File Line: 1573
// RVA: 0x1570FE0
__int64 UFG::_dynamic_initializer_for__sym_cop_vehicle_patrol_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_vehicle_patrol_symbol", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_vehicle_patrol_symbol, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_cop_vehicle_patrol_symbol__);
}

// File Line: 1574
// RVA: 0x1571BA0
__int64 UFG::_dynamic_initializer_for__sym_roadblock_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("roadblock_symbol", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_roadblock_symbol, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_roadblock_symbol__);
}

// File Line: 1575
// RVA: 0x15715A0
__int64 UFG::_dynamic_initializer_for__sym_hiding_spot__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("hiding_spot", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_hiding_spot, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_hiding_spot__);
}

// File Line: 1576
// RVA: 0x15715E0
__int64 UFG::_dynamic_initializer_for__sym_hiding_spot_garage__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("hiding_spot_garage", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_hiding_spot_garage, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_hiding_spot_garage__);
}

// File Line: 1577
// RVA: 0x15722A0
__int64 UFG::_dynamic_initializer_for__sym_witness_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("witness_symbol", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_witness_symbol, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_witness_symbol__);
}

// File Line: 1578
// RVA: 0x1571420
__int64 UFG::_dynamic_initializer_for__sym_friendly__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("friendly", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_friendly, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_friendly__);
}

// File Line: 1579
// RVA: 0x15710E0
__int64 UFG::_dynamic_initializer_for__sym_enemy__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("enemy", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_enemy, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_enemy__);
}

// File Line: 1580
// RVA: 0x1571120
__int64 UFG::_dynamic_initializer_for__sym_enemy_noncombat__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("enemy_noncombat", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_enemy_noncombat, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_enemy_noncombat__);
}

// File Line: 1581
// RVA: 0x1570E20
__int64 UFG::_dynamic_initializer_for__sym_contact__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("contact", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_contact, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_contact__);
}

// File Line: 1582
// RVA: 0x1571DA0
__int64 UFG::_dynamic_initializer_for__sym_social__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("social", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_social, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_social__);
}

// File Line: 1583
// RVA: 0x1571DE0
__int64 UFG::_dynamic_initializer_for__sym_social_ambient__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("social_ambient", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_social_ambient, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_social_ambient__);
}

// File Line: 1584
// RVA: 0x1571E20
__int64 UFG::_dynamic_initializer_for__sym_social_mission__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("social_mission", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_social_mission, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_social_mission__);
}

// File Line: 1585
// RVA: 0x1570DA0
__int64 UFG::_dynamic_initializer_for__sym_case_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("case_start", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_case_start, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_case_start__);
}

// File Line: 1586
// RVA: 0x1570D60
__int64 UFG::_dynamic_initializer_for__sym_case_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("case_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_case_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_case_objective__);
}

// File Line: 1587
// RVA: 0x15712E0
__int64 UFG::_dynamic_initializer_for__sym_face_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("face_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_face_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_face_objective__);
}

// File Line: 1588
// RVA: 0x1571960
__int64 UFG::_dynamic_initializer_for__sym_mission_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("mission_start", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_mission_start, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_mission_start__);
}

// File Line: 1589
// RVA: 0x1571920
__int64 UFG::_dynamic_initializer_for__sym_mission_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("mission_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_mission_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_mission_objective__);
}

// File Line: 1590
// RVA: 0x1571B20
__int64 UFG::_dynamic_initializer_for__sym_race_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("race_start", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_race_start, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_race_start__);
}

// File Line: 1591
// RVA: 0x1571B60
__int64 UFG::_dynamic_initializer_for__sym_race_start_flag__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("race_start_flag", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_race_start_flag, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_race_start_flag__);
}

// File Line: 1592
// RVA: 0x1571AA0
__int64 UFG::_dynamic_initializer_for__sym_race_end__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("race_end", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_race_end, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_race_end__);
}

// File Line: 1593
// RVA: 0x1571AE0
__int64 UFG::_dynamic_initializer_for__sym_race_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("race_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_race_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_race_objective__);
}

// File Line: 1594
// RVA: 0x1570E60
__int64 UFG::_dynamic_initializer_for__sym_cop_event_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_event_start", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_event_start, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_cop_event_start__);
}

// File Line: 1595
// RVA: 0x15711E0
__int64 UFG::_dynamic_initializer_for__sym_event_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("event_start", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_event_start, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_event_start__);
}

// File Line: 1596
// RVA: 0x15711A0
__int64 UFG::_dynamic_initializer_for__sym_event_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("event_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_event_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_event_objective__);
}

// File Line: 1597
// RVA: 0x1571720
__int64 UFG::_dynamic_initializer_for__sym_job_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("job_start", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_job_start, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_job_start__);
}

// File Line: 1598
// RVA: 0x15716E0
__int64 UFG::_dynamic_initializer_for__sym_job_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("job_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_job_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_job_objective__);
}

// File Line: 1599
// RVA: 0x1571160
__int64 UFG::_dynamic_initializer_for__sym_enemy_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("enemy_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_enemy_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_enemy_objective__);
}

// File Line: 1600
// RVA: 0x1570F20
__int64 UFG::_dynamic_initializer_for__sym_cop_job__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_job", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_job, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_cop_job__);
}

// File Line: 1601
// RVA: 0x1570F60
__int64 UFG::_dynamic_initializer_for__sym_cop_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cop_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cop_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_cop_objective__);
}

// File Line: 1602
// RVA: 0x15721A0
__int64 UFG::_dynamic_initializer_for__sym_transterror_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("transterror_start", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_transterror_start, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_transterror_start__);
}

// File Line: 1603
// RVA: 0x1572160
__int64 UFG::_dynamic_initializer_for__sym_transterror_mission__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("transterror_mission", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_transterror_mission, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_transterror_mission__);
}

// File Line: 1604
// RVA: 0x1572120
__int64 UFG::_dynamic_initializer_for__sym_transterror_event__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("transterror_event", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_transterror_event, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_transterror_event__);
}

// File Line: 1605
// RVA: 0x15723E0
__int64 UFG::_dynamic_initializer_for__sym_zodiac_start__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("zodiac_start", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_zodiac_start, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_zodiac_start__);
}

// File Line: 1606
// RVA: 0x15723A0
__int64 UFG::_dynamic_initializer_for__sym_zodiac_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("zodiac_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_zodiac_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_zodiac_objective__);
}

// File Line: 1607
// RVA: 0x1572320
__int64 UFG::_dynamic_initializer_for__sym_zodiac_event__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("zodiac_event", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_zodiac_event, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_zodiac_event__);
}

// File Line: 1608
// RVA: 0x15722E0
__int64 UFG::_dynamic_initializer_for__sym_zodiac_enemy__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("zodiac_enemy", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_zodiac_enemy, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_zodiac_enemy__);
}

// File Line: 1609
// RVA: 0x1572360
__int64 UFG::_dynamic_initializer_for__sym_zodiac_friendly__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("zodiac_friendly", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_zodiac_friendly, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_zodiac_friendly__);
}

// File Line: 1610
// RVA: 0x1571460
__int64 UFG::_dynamic_initializer_for__sym_ghost_elite_ghoul__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("ghost_elite_ghoul", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_ghost_elite_ghoul, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_ghost_elite_ghoul__);
}

// File Line: 1611
// RVA: 0x15714A0
__int64 UFG::_dynamic_initializer_for__sym_ghost_lesser_ghoul__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("ghost_lesser_ghoul", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_ghost_lesser_ghoul, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_ghost_lesser_ghoul__);
}

// File Line: 1612
// RVA: 0x1571560
__int64 UFG::_dynamic_initializer_for__sym_ghost_trapped_ped__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("ghost_trapped_ped", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_ghost_trapped_ped, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_ghost_trapped_ped__);
}

// File Line: 1613
// RVA: 0x1571020
__int64 UFG::_dynamic_initializer_for__sym_crime_scene__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("crime_scene", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_crime_scene, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_crime_scene__);
}

// File Line: 1614
// RVA: 0x1571BE0
__int64 UFG::_dynamic_initializer_for__sym_safe_house__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("safe_house", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_safe_house, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_safe_house__);
}

// File Line: 1615
// RVA: 0x1571C20
__int64 UFG::_dynamic_initializer_for__sym_safe_house_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("safe_house_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_safe_house_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_safe_house_objective__);
}

// File Line: 1616
// RVA: 0x1571C60
__int64 UFG::_dynamic_initializer_for__sym_safe_house_unlocked__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("safe_house_unlocked", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_safe_house_unlocked, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_safe_house_unlocked__);
}

// File Line: 1617
// RVA: 0x1572220
__int64 UFG::_dynamic_initializer_for__sym_undercover_safe_house__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("undercover_safe_house", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_undercover_safe_house, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_undercover_safe_house__);
}

// File Line: 1618
// RVA: 0x15721E0
__int64 UFG::_dynamic_initializer_for__sym_triad_war__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("triad_war", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_triad_war, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_triad_war__);
}

// File Line: 1619
// RVA: 0x1571060
__int64 UFG::_dynamic_initializer_for__sym_date_character__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("date_character", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_date_character, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_date_character__);
}

// File Line: 1620
// RVA: 0x15712A0
__int64 UFG::_dynamic_initializer_for__sym_face_character__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("face_character", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_face_character, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_face_character__);
}

// File Line: 1621
// RVA: 0x1572260
__int64 UFG::_dynamic_initializer_for__sym_waypoint__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("waypoint", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_waypoint, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_waypoint__);
}

// File Line: 1622
// RVA: 0x1571A60
__int64 UFG::_dynamic_initializer_for__sym_player_car__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("player_car", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_player_car, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_player_car__);
}

// File Line: 1623
// RVA: 0x1571A20
__int64 UFG::_dynamic_initializer_for__sym_parking_symbol__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("parking_symbol", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_parking_symbol, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_parking_symbol__);
}

// File Line: 1624
// RVA: 0x15719E0
__int64 UFG::_dynamic_initializer_for__sym_parking_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("parking_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_parking_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_parking_objective__);
}

// File Line: 1625
// RVA: 0x1571320
__int64 UFG::_dynamic_initializer_for__sym_ferry__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("ferry", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_ferry, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_ferry__);
}

// File Line: 1626
// RVA: 0x1570D20
__int64 UFG::_dynamic_initializer_for__sym_bus_stop__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("bus_stop", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_bus_stop, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_bus_stop__);
}

// File Line: 1627
// RVA: 0x1571EA0
__int64 UFG::_dynamic_initializer_for__sym_store_clothing__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_clothing", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_clothing, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_store_clothing__);
}

// File Line: 1628
// RVA: 0x1571EE0
__int64 UFG::_dynamic_initializer_for__sym_store_clothing_indoors__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_clothing_indoors", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_clothing_indoors, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_store_clothing_indoors__);
}

// File Line: 1629
// RVA: 0x1571F60
__int64 UFG::_dynamic_initializer_for__sym_store_exotic_clothing__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_exotic_clothing", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_exotic_clothing, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_store_exotic_clothing__);
}

// File Line: 1630
// RVA: 0x1571F20
__int64 UFG::_dynamic_initializer_for__sym_store_convenience__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_convenience", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_convenience, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_store_convenience__);
}

// File Line: 1631
// RVA: 0x1571E60
__int64 UFG::_dynamic_initializer_for__sym_store_apothecary__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_apothecary", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_apothecary, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_store_apothecary__);
}

// File Line: 1632
// RVA: 0x1572060
__int64 UFG::_dynamic_initializer_for__sym_store_vehicle__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_vehicle", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_vehicle, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_store_vehicle__);
}

// File Line: 1633
// RVA: 0x1572020
__int64 UFG::_dynamic_initializer_for__sym_store_social__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_social", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_social, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_store_social__);
}

// File Line: 1634
// RVA: 0x1571FA0
__int64 UFG::_dynamic_initializer_for__sym_store_gambling__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_gambling", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_gambling, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_store_gambling__);
}

// File Line: 1635
// RVA: 0x15717A0
__int64 UFG::_dynamic_initializer_for__sym_karaoke__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("karaoke", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_karaoke, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_karaoke__);
}

// File Line: 1636
// RVA: 0x15710A0
__int64 UFG::_dynamic_initializer_for__sym_drunken_dice__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("drunken_dice", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_drunken_dice, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_drunken_dice__);
}

// File Line: 1637
// RVA: 0x1570DE0
__int64 UFG::_dynamic_initializer_for__sym_cock_fighting__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("cock_fighting", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_cock_fighting, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_cock_fighting__);
}

// File Line: 1638
// RVA: 0x1571360
__int64 UFG::_dynamic_initializer_for__sym_fight_club__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("fight_club", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_fight_club, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_fight_club__);
}

// File Line: 1639
// RVA: 0x1571FE0
__int64 UFG::_dynamic_initializer_for__sym_store_massage__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("store_massage", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_store_massage, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_store_massage__);
}

// File Line: 1640
// RVA: 0x15719A0
__int64 UFG::_dynamic_initializer_for__sym_outdoor_massage__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("outdoor_massage", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_outdoor_massage, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_outdoor_massage__);
}

// File Line: 1641
// RVA: 0x1571860
__int64 UFG::_dynamic_initializer_for__sym_martial_arts__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("martial_arts", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_martial_arts, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_martial_arts__);
}

// File Line: 1642
// RVA: 0x15718A0
__int64 UFG::_dynamic_initializer_for__sym_martial_arts_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("martial_arts_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_martial_arts_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_martial_arts_objective__);
}

// File Line: 1643
// RVA: 0x15716A0
__int64 UFG::_dynamic_initializer_for__sym_hijack__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("hijack", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_hijack, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_hijack__);
}

// File Line: 1644
// RVA: 0x1571CA0
__int64 UFG::_dynamic_initializer_for__sym_security_camera__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("security_camera", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_security_camera, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_security_camera__);
}

// File Line: 1645
// RVA: 0x1571CE0
__int64 UFG::_dynamic_initializer_for__sym_security_camera_collected__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("security_camera_collected", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_security_camera_collected, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_security_camera_collected__);
}

// File Line: 1646
// RVA: 0x1571D20
__int64 UFG::_dynamic_initializer_for__sym_shrine__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("shrine", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_shrine, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_shrine__);
}

// File Line: 1647
// RVA: 0x1571D60
__int64 UFG::_dynamic_initializer_for__sym_shrine_collected__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("shrine_collected", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_shrine_collected, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_shrine_collected__);
}

// File Line: 1648
// RVA: 0x15717E0
__int64 UFG::_dynamic_initializer_for__sym_lockbox__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("lockbox", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_lockbox, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_lockbox__);
}

// File Line: 1649
// RVA: 0x1571820
__int64 UFG::_dynamic_initializer_for__sym_lockbox_collected__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("lockbox_collected", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_lockbox_collected, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_lockbox_collected__);
}

// File Line: 1650
// RVA: 0x1571660
__int64 UFG::_dynamic_initializer_for__sym_hiding_spot_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("hiding_spot_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_hiding_spot_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_hiding_spot_objective__);
}

// File Line: 1651
// RVA: 0x1571620
__int64 UFG::_dynamic_initializer_for__sym_hiding_spot_garage_objective__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("hiding_spot_garage_objective", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_hiding_spot_garage_objective, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_hiding_spot_garage_objective__);
}

// File Line: 1652
// RVA: 0x15720E0
__int64 UFG::_dynamic_initializer_for__sym_tourist_photo__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("tourist_photo", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_tourist_photo, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_tourist_photo__);
}

// File Line: 1653
// RVA: 0x1571760
__int64 UFG::_dynamic_initializer_for__sym_jump__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("jump", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_jump, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_jump__);
}

// File Line: 1654
// RVA: 0x15720A0
__int64 UFG::_dynamic_initializer_for__sym_tape_recorder__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("tape_recorder", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_tape_recorder, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_tape_recorder__);
}

// File Line: 1655
// RVA: 0x1570CE0
__int64 UFG::_dynamic_initializer_for__sym_bug__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("bug", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_bug, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_bug__);
}

// File Line: 1656
// RVA: 0x15718E0
__int64 UFG::_dynamic_initializer_for__sym_melee_upgrade__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("melee_upgrade", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_melee_upgrade, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_melee_upgrade__);
}

// File Line: 1658
// RVA: 0x15714E0
__int64 UFG::_dynamic_initializer_for__sym_ghost_orb__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("ghost_orb", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_ghost_orb, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_ghost_orb__);
}

// File Line: 1659
// RVA: 0x1571520
__int64 UFG::_dynamic_initializer_for__sym_ghost_orb_collected__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("ghost_orb_collected", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_ghost_orb_collected, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_ghost_orb_collected__);
}

// File Line: 1660
// RVA: 0x15713A0
__int64 UFG::_dynamic_initializer_for__sym_fire_statue__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("fire_statue", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_fire_statue, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_fire_statue__);
}

// File Line: 1661
// RVA: 0x15713E0
__int64 UFG::_dynamic_initializer_for__sym_fire_statue_collected__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("fire_statue_collected", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_fire_statue_collected, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_fire_statue_collected__);
}

// File Line: 1662
// RVA: 0x1571220
__int64 UFG::_dynamic_initializer_for__sym_evidence_bag__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("evidence_bag", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_evidence_bag, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_evidence_bag__);
}

// File Line: 1663
// RVA: 0x1571260
__int64 UFG::_dynamic_initializer_for__sym_evidence_bag_collected__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("evidence_bag_collected", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::sym_evidence_bag_collected, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__sym_evidence_bag_collected__);
}

// File Line: 1671
// RVA: 0x60A0D0
_BOOL8 __fastcall UFG::UIHKScreenWorldMap::SetUpLegend(UFG::UIHKScreenWorldMap *this, UFG::qArray<UFG::qSymbolUC,0> *blipTypes, bool deleteAllExistingLegendItems)
{
  UFG::qArray<UFG::qSymbolUC,0> *v3; // rsi
  UFG::UIHKScreenWorldMap *v4; // rbp
  UFG::qSymbolUC *v5; // rcx
  UFG::UIMapBlipManager *v6; // rdi
  bool v7; // r14
  UFG::qSymbolUC *v8; // rbx
  unsigned int v9; // er15
  unsigned int v10; // edx
  unsigned int v11; // ebx
  UFG::UIHKScreenWorldMap::eViewType v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  const char *v16; // r8
  const char *v17; // rdx
  UFG::qStaticSymbolUC *v18; // r9
  unsigned int v19; // eax
  int v20; // ebx
  unsigned int v21; // ebx
  unsigned int v22; // eax
  unsigned int v23; // ebx

  v3 = blipTypes;
  v4 = this;
  if ( deleteAllExistingLegendItems )
    UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&this->mLegendItems);
  v5 = v3->p;
  v6 = UFG::UIHKScreenHud::mIconManager;
  v7 = 0;
  if ( v5 )
  {
    v8 = v5 - 1;
    `eh vector destructor iterator(v5, 4ui64, v5[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v8);
  }
  v9 = 1;
  v3->p = 0i64;
  *(_QWORD *)&v3->size = 0i64;
  v10 = 1;
  do
    v10 *= 2;
  while ( v10 < 0x3C );
  if ( v10 <= 4 )
    v10 = 4;
  if ( v10 - 60 > 0x10000 )
    v10 = 65596;
  UFG::qArray<UFG::qSymbolUC,0>::Reallocate(v3, v10, "qArray.Reallocate(Resize)");
  v3->size = 60;
  v11 = 0;
  if ( UFG::UIHKScreenWorldMap::mViewMode )
  {
    if ( UFG::UIHKScreenWorldMap::mViewMode == 1 )
    {
      if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_case_start.mUID)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_case_start.mUID) )
      {
        v3->p->mUID = UFG::sym_case_start.mUID;
        v11 = 1;
        UFG::UIHKScreenWorldMap::AddLegendItem(v4, "case_start", "$MAP_LEGEND_CASE_START");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_mission_start.mUID)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_mission_start.mUID) )
      {
        v3->p[v11++].mUID = UFG::sym_mission_start.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(v4, "mission_start", "$MAP_LEGEND_MISSION_START");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_parking_symbol.mUID)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_parking_symbol.mUID) )
      {
        v3->p[v11++].mUID = UFG::sym_parking_symbol.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(v4, "parking_symbol", "$MAP_LEGEND_PARKING_LOT");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_parking_objective.mUID)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_parking_objective.mUID) )
      {
        v3->p[v11++].mUID = UFG::sym_parking_objective.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(v4, "parking_objective", "$MAP_LEGEND_PARKING_LOT");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_bus_stop.mUID)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_bus_stop.mUID) )
      {
        v3->p[v11++].mUID = UFG::sym_bus_stop.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(v4, "bus_stop", "$MAP_LEGEND_BUS_STOP");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_store_clothing.mUID)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_store_clothing.mUID) )
      {
        v3->p[v11++].mUID = UFG::sym_store_clothing.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(v4, "store_clothing", "$MAP_LEGEND_CLOTHING_STORE");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_store_exotic_clothing.mUID)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_store_exotic_clothing.mUID) )
      {
        v3->p[v11++].mUID = UFG::sym_store_exotic_clothing.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(v4, "store_exotic_clothing", "$LEGENDARY_OUTFITS_NO_COLOR");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_store_vehicle.mUID)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_store_vehicle.mUID) )
      {
        v3->p[v11++].mUID = UFG::sym_store_vehicle.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(v4, "store_vehicle", "$MAP_LEGEND_VEHICLE_STORE");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_martial_arts.mUID)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_martial_arts.mUID) )
      {
        v3->p[v11++].mUID = UFG::sym_martial_arts.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(v4, "martial_arts", "$MAP_LEGEND_MARTIAL_ARTS");
      }
      if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_martial_arts_objective.mUID)
        && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_martial_arts_objective.mUID) )
      {
        v3->p[v11++].mUID = UFG::sym_martial_arts_objective.mUID;
        UFG::UIHKScreenWorldMap::AddLegendItem(v4, "martial_arts_objective", "$MAP_LEGEND_MARTIAL_ARTS");
      }
      v4->mTransitEnableBackButton = 1;
      UFG::UIHKScreenWorldMap::ShowHelpBar(v4);
    }
    goto LABEL_365;
  }
  v12 = v4->mViewType;
  if ( v12 == BASIC_VIEW )
  {
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_cop_symbol.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_cop_symbol.mUID) )
    {
      v3->p->mUID = UFG::sym_cop_symbol.mUID;
      v11 = 1;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "cop_symbol", "$MAP_LEGEND_POLICE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_cop_foot_symbol.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_cop_foot_symbol.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_cop_foot_symbol.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "cop_foot_symbol", "$MAP_LEGEND_POLICE_FOOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_cop_foot_patrol_symbol.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_cop_foot_patrol_symbol.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_cop_foot_patrol_symbol.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "cop_foot_patrol_symbol", "$MAP_LEGEND_POLICE_FOOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_cop_vehicle_patrol_symbol.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_cop_vehicle_patrol_symbol.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_cop_vehicle_patrol_symbol.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "cop_vehicle_patrol_symbol", "$MAP_LEGEND_POLICE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_roadblock_symbol.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_roadblock_symbol.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_roadblock_symbol.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "roadblock_symbol", "$MAP_LEGEND_ROADBLOCK");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_hiding_spot.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_hiding_spot.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_hiding_spot.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "hiding_spot", "$MAP_LEGEND_HIDING_SPOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_hiding_spot_garage.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_hiding_spot_garage.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_hiding_spot_garage.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "hiding_spot_garage", "$MAP_LEGEND_HIDING_SPOT_GARAGE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_witness_symbol.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_witness_symbol.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_witness_symbol.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "witness_symbol", "$MAP_LEGEND_WITNESS");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_friendly.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_friendly.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_friendly.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "friendly", "$MAP_LEGEND_FRIENDLY");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_enemy.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_enemy.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_enemy.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "enemy", "$MAP_LEGEND_ENEMY");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_enemy_noncombat.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_enemy_noncombat.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_enemy_noncombat.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "enemy_noncombat", "$MAP_LEGEND_ENEMY");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_contact.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_contact.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_contact.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "contact", "$MAP_LEGEND_CONTACT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_social.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_social.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_social.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "social", "$MAP_LEGEND_SOCIAL");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_social_ambient.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_social_ambient.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_social_ambient.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "social_ambient", "$MAP_LEGEND_SOCIAL");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_social_mission.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_social_mission.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_social_mission.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "social_mission", "$MAP_LEGEND_SOCIAL");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_case_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_case_start.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_case_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "case_start", "$MAP_LEGEND_CASE_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_case_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_case_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_case_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "case_objective", "$MAP_LEGEND_CASE_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_face_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_face_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_face_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "face_objective", "$MAP_LEGEND_SOCIAL");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_mission_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_mission_start.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_mission_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "mission_start", "$MAP_LEGEND_MISSION_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_mission_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_mission_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_mission_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "mission_objective", "$MAP_LEGEND_MISSION_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_race_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_race_start.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_race_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "race_start", "$MAP_LEGEND_RACE_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_race_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_race_start.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_race_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "race_start_flag", "$MAP_LEGEND_RACE_START_FLAG");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_race_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_race_start.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_race_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "race_end", "$MAP_LEGEND_RACE_END");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_race_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_race_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_race_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "race_objective", "$MAP_LEGEND_RACE_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_cop_event_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_cop_event_start.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_cop_event_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "cop_event_start", "$MAP_LEGEND_EVENT_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_event_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_event_start.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_event_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "event_start", "$MAP_LEGEND_EVENT_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_event_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_event_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_event_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "event_objective", "$MAP_LEGEND_EVENT_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_job_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_job_start.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_job_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "job_start", "$MAP_LEGEND_JOB_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_job_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_job_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_job_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "job_objective", "$MAP_LEGEND_JOB_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_enemy_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_enemy_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_enemy_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "enemy_objective", "$MAP_LEGEND_ENEMY_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_cop_job.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_cop_job.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_cop_job.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "cop_job", "$MAP_LEGEND_COP_JOB");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_cop_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_cop_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_cop_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "cop_objective", "$MAP_LEGEND_COP_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_transterror_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_transterror_start.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_transterror_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "transterror_start", "$MAP_LEGEND_DLC_10");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_transterror_mission.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_transterror_mission.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_transterror_mission.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "transterror_mission", "$MAP_LEGEND_JOB_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_transterror_event.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_transterror_event.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_transterror_event.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "transterror_event", "$MAP_LEGEND_JOB_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_zodiac_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_zodiac_start.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_zodiac_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "zodiac_start", "$MAP_LEGEND_DLC_04");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_zodiac_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_zodiac_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_zodiac_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "zodiac_objective", "$MAP_LEGEND_JOB_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_zodiac_event.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_zodiac_event.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_zodiac_event.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "zodiac_event", "$MAP_LEGEND_EVENT_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_zodiac_event.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_zodiac_event.mUID) )
    {
      v18 = (UFG::qStaticSymbolUC *)&v3->p[v11++];
      v18->mUID = UFG::sym_zodiac_event.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "zodiac_event", "$MAP_LEGEND_EVENT_OBJECTIVE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_zodiac_enemy.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_zodiac_enemy.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_zodiac_enemy.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "zodiac_enemy", "$MAP_LEGEND_ENEMY");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_zodiac_friendly.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_zodiac_friendly.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_zodiac_friendly.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "zodiac_friendly", "$MAP_LEGEND_FRIENDLY");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_ghost_elite_ghoul.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_ghost_elite_ghoul.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_ghost_elite_ghoul.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "ghost_elite_ghoul", "$MAP_LEGEND_DLC_02");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_ghost_lesser_ghoul.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_ghost_lesser_ghoul.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_ghost_lesser_ghoul.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "ghost_lesser_ghoul", "$MAP_LEGEND_DLC_01");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_ghost_trapped_ped.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_ghost_trapped_ped.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_ghost_trapped_ped.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "ghost_trapped_ped", "$MAP_LEGEND_DLC_03");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_crime_scene.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_crime_scene.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_crime_scene.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "crime_scene", "$MAP_LEGEND_CRIME_SCENE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_safe_house.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_safe_house.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_safe_house.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "safe_house", "$MAP_LEGEND_SAFEHOUSE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_safe_house_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_safe_house_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_safe_house_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "safe_house_objective", "$MAP_LEGEND_SAFEHOUSE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_safe_house_unlocked.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_safe_house_unlocked.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_safe_house_unlocked.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "safe_house_unlocked", "$MAP_LEGEND_SAFEHOUSE_UNLOCKED");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_undercover_safe_house.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_undercover_safe_house.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_undercover_safe_house.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "undercover_safe_house", "$MAP_LEGEND_UNDERCOVER_SAFEHOUSE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_triad_war.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_triad_war.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_triad_war.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "triad_war", "$MAP_LEGEND_DRUG_BUST");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_date_character.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_date_character.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_date_character.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "date_character", "$MAP_LEGEND_SOCIAL");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_face_character.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_face_character.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_face_character.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "face_character", "$MAP_LEGEND_FAVOUR");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_waypoint.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_waypoint.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_waypoint.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "waypoint", "$MAP_LEGEND_WAYPOINT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_player_car.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_player_car.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_player_car.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "player_car", "Car");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_parking_symbol.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_parking_symbol.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_parking_symbol.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "parking_symbol", "$MAP_LEGEND_PARKING_LOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_parking_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_parking_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_parking_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "parking_objective", "$MAP_LEGEND_PARKING_LOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_ferry.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_ferry.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_ferry.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "ferry", "$MAP_LEGEND_FERRY");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_bus_stop.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_bus_stop.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_bus_stop.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "bus_stop", "$MAP_LEGEND_BUS_STOP");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_store_clothing.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_store_clothing.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_store_clothing.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "store_clothing", "$MAP_LEGEND_CLOTHING_STORE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_store_clothing_indoors.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_store_clothing_indoors.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_store_clothing_indoors.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "store_clothing_indoors", "$MAP_LEGEND_CLOTHING_STORE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_store_exotic_clothing.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_store_exotic_clothing.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_store_exotic_clothing.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "store_exotic_clothing", "$LEGENDARY_OUTFITS_NO_COLOR");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_store_convenience.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_store_convenience.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_store_convenience.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "store_convenience", "$MAP_LEGEND_CONVENIENCE_STORE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_store_apothecary.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_store_apothecary.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_store_apothecary.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "store_apothecary", "$MAP_LEGEND_APOTHECARY_STORE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_store_vehicle.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_store_vehicle.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_store_vehicle.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "store_vehicle", "$MAP_LEGEND_VEHICLE_STORE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_store_social.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_store_social.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_store_social.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "store_social", "$MAP_LEGEND_PORK_BUN");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_store_gambling.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_store_gambling.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_store_gambling.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "store_gambling", "$MAP_LEGEND_GAMBLING_DEN");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_drunken_dice.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_drunken_dice.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_drunken_dice.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "drunken_dice", "$MAP_LEGEND_DRUNKEN_DICE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_karaoke.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_karaoke.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_karaoke.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "karaoke", "$MAP_LEGEND_KARAOKE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_cock_fighting.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_cock_fighting.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_cock_fighting.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "cock_fighting", "$MAP_LEGEND_COCK_FIGHTING");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_fight_club.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_fight_club.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_fight_club.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "fight_club", "$MAP_LEGEND_MARTIAL_ARTS_CLUB");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_store_massage.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_store_massage.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_store_massage.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "store_massage", "$MAP_LEGEND_MASSAGE_PARLOR");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_outdoor_massage.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_outdoor_massage.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_outdoor_massage.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "outdoor_massage", "$MAP_LEGEND_MASSAGE_PARLOR");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_martial_arts.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_martial_arts.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_martial_arts.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "martial_arts", "$MAP_LEGEND_MARTIAL_ARTS");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_martial_arts_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_martial_arts_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_martial_arts_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "martial_arts_objective", "$MAP_LEGEND_MARTIAL_ARTS");
    }
    if ( !UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_hijack.mUID)
      || !(unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_hijack.mUID) )
    {
      goto LABEL_364;
    }
    v16 = "$MAP_LEGEND_HIJACK";
    v3->p[v11].mUID = UFG::sym_hijack.mUID;
    v17 = "hijack";
LABEL_363:
    ++v11;
    UFG::UIHKScreenWorldMap::AddLegendItem(v4, v17, v16);
LABEL_364:
    v7 = v11 != 0;
    goto LABEL_365;
  }
  v13 = v12 - 1;
  if ( !v13 )
  {
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_case_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_case_start.mUID) )
    {
      v3->p->mUID = UFG::sym_case_start.mUID;
      v11 = 1;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "case_start", "$MAP_LEGEND_CASE_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_case_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_case_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_case_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "case_objective", "$MAP_LEGEND_CASE_OBJECTIVE");
    }
    if ( !UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_waypoint.mUID)
      || !(unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_waypoint.mUID) )
    {
      goto LABEL_364;
    }
    v16 = "$MAP_LEGEND_WAYPOINT";
    v3->p[v11].mUID = UFG::sym_waypoint.mUID;
    v17 = "waypoint";
    goto LABEL_363;
  }
  v14 = v13 - 1;
  if ( !v14 )
  {
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_race_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_race_start.mUID) )
    {
      v3->p->mUID = UFG::sym_race_start.mUID;
      v11 = 1;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "race_start", "$MAP_LEGEND_RACE_START");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_race_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_race_start.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_race_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "race_start_flag", "$MAP_LEGEND_RACE_START_FLAG");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_race_start.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_race_start.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_race_start.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "race_end", "$MAP_LEGEND_RACE_END");
    }
    if ( !UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_race_objective.mUID)
      || !(unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_race_objective.mUID) )
    {
      goto LABEL_364;
    }
    v16 = "$MAP_LEGEND_RACE_OBJECTIVE";
    v3->p[v11].mUID = UFG::sym_race_objective.mUID;
    v17 = "race_objective";
    goto LABEL_363;
  }
  v15 = v14 - 1;
  if ( !v15 )
  {
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_security_camera.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_security_camera.mUID) )
    {
      v3->p->mUID = UFG::sym_security_camera.mUID;
      v11 = 1;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "security_camera", "$MAP_LEGEND_SECURITY_CAMERA");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_security_camera_collected.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_security_camera_collected.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_security_camera_collected.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "security_camera_collected", "$MAP_LEGEND_COLLECTED_SECURITY_CAMERA");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_shrine.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_shrine.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_shrine.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "shrine", "$MAP_LEGEND_HEALTH_SHRINE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_shrine_collected.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_shrine_collected.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_shrine_collected.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "shrine_collected", "$MAP_LEGEND_COLLECTED_HEALTH_SHRINE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_lockbox.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_lockbox.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_lockbox.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "lockbox", "$MAP_LEGEND_LOCKBOX");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_lockbox_collected.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_lockbox_collected.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_lockbox_collected.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "lockbox_collected", "$MAP_LEGEND_LOCK_COLLECTED");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_hiding_spot.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_hiding_spot.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_hiding_spot.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "hiding_spot", "$MAP_LEGEND_HIDING_SPOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_hiding_spot_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_hiding_spot_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_hiding_spot_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "hiding_spot_objective", "$MAP_LEGEND_HIDING_SPOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_hiding_spot_garage.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_hiding_spot_garage.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_hiding_spot_garage.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "hiding_spot_garage", "$MAP_LEGEND_VEHICLE_HIDING_SPOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_hiding_spot_garage_objective.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_hiding_spot_garage_objective.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_hiding_spot_garage_objective.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "hiding_spot_garage_objective", "$MAP_LEGEND_VEHICLE_HIDING_SPOT");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_tourist_photo.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_tourist_photo.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_tourist_photo.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "tourist_photo", "$MAP_LEGEND_TOURIST_PHOTO");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_tape_recorder.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_tape_recorder.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_tape_recorder.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "tape_recorder", "$MAP_LEGEND_TAPE_RECORDER");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_bug.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_bug.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_bug.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "bug", "$MAP_LEGEND_BUG");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_melee_upgrade.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_melee_upgrade.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_melee_upgrade.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "melee_upgrade", "$MAP_LEGEND_MELEE_UPGRADE");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_ghost_orb.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_ghost_orb.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_ghost_orb.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "ghost_orb", "$MAP_LEGEND_DLC_COLL_01");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_ghost_orb_collected.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_ghost_orb_collected.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_ghost_orb_collected.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "ghost_orb_collected", "$MAP_LEGEND_DLC_COLL_01");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_fire_statue.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_fire_statue.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_fire_statue.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "fire_statue", "$MAP_LEGEND_DLC_COLL_02");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_fire_statue_collected.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_fire_statue_collected.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_fire_statue_collected.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "fire_statue_collected", "$MAP_LEGEND_DLC_COLL_02");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_evidence_bag.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_evidence_bag.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_evidence_bag.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "evidence_bag", "$MAP_LEGEND_DLC_COLL_03");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_evidence_bag_collected.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_evidence_bag_collected.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_evidence_bag_collected.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "evidence_bag_collected", "$MAP_LEGEND_DLC_COLL_03");
    }
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_waypoint.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_waypoint.mUID) )
    {
      v3->p[v11++].mUID = UFG::sym_waypoint.mUID;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "waypoint", "$MAP_LEGEND_WAYPOINT");
    }
    v4->mCurrentViewHasGPS = 1;
    UFG::UITiledMapGPS::PopulateWorldMap(UFG::UIHKScreenHud::GPS, &v4->GPS);
    UFG::UIHKWorldMapCollectiblesStatsWidget::Populate(&v4->CollectiblesStats, (UFG::UIScreen *)&v4->vfptr);
    goto LABEL_364;
  }
  if ( v15 == 1 )
  {
    if ( UFG::UIMapBlipManager::HasBlipType(v6, (UFG::qSymbolUC *)&UFG::sym_triad_war.mUID)
      && (unsigned __int8)UFG::UIMapBlipTypeManager::IsTypeSupportedByProgressionFlow((UFG::qSymbolUC *)&UFG::sym_triad_war.mUID) )
    {
      v3->p->mUID = UFG::sym_triad_war.mUID;
      v11 = 1;
      UFG::UIHKScreenWorldMap::AddLegendItem(v4, "triad_war", "$MAP_LEGEND_EVENT_START");
    }
    v7 = 1;
  }
LABEL_365:
  v19 = v3->size;
  v20 = v11 - v3->size;
  if ( v20 <= 0 )
  {
    v23 = -v20;
    if ( v23 )
    {
      if ( v23 < v19 )
        v3->size = v19 - v23;
      else
        v3->size = 0;
    }
  }
  else
  {
    v21 = v19 + v20;
    v22 = v3->capacity;
    if ( v21 > v22 )
    {
      if ( v22 )
        v9 = 2 * v22;
      for ( ; v9 < v21; v9 *= 2 )
        ;
      if ( v9 <= 4 )
        v9 = 4;
      if ( v9 - v21 > 0x10000 )
        v9 = v21 + 0x10000;
      UFG::qArray<UFG::qSymbolUC,0>::Reallocate(v3, v9, "qArray.Reallocate(Resize)");
    }
    v3->size = v21;
  }
  return v7;
}te(v3, v9, "qArray.Reallocate(Resize)");
    }
    v3->size = v21;
  }
  return v7;
}

// File Line: 1905
// RVA: 0x60C4E0
void __fastcall UFG::UIHKScreenWorldMap::SetUpObjectiveView(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rbx
  UFG::ProgressionTracker *v2; // rax
  UFG::Objective *v3; // rax

  v1 = this;
  v2 = UFG::ProgressionTracker::Instance();
  v3 = UFG::ObjectiveTracker::GetFirstObjective(&v2->mObjectiveTracker);
  if ( v3 && v3->mpGameSlice->mState == 4 )
  {
    UFG::UIHKWorldMapObjectivesWidget::Flash_SetTitle(
      &v1->ObjectivesWidget,
      (UFG::UIScreen *)&v1->vfptr,
      "$worldmap_objectives_caps");
    UFG::UIHKScreenWorldMap::DisplayObjectives(v1);
    UFG::UIHKScreenWorldMap::DisplaySecondaryObjectives(v1);
  }
  else
  {
    UFG::UIHKWorldMapObjectivesWidget::Flash_SetTitle(
      &v1->ObjectivesWidget,
      (UFG::UIScreen *)&v1->vfptr,
      "$worldmap_avail_missions");
    UFG::UIHKScreenWorldMap::DisplayMissions(v1);
  }
}

// File Line: 1949
// RVA: 0x5D6BE0
void __fastcall UFG::UIHKScreenWorldMap::DisplayObjectives(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rdi
  UFG::ProgressionTracker *v2; // rbp
  int v3; // esi
  UFG::Objective *v4; // rbx
  bool v5; // r9
  UFG::UIHKWorldMapObjectivesWidget *v6; // rcx
  const char *v7; // rdx
  unsigned int v8; // eax

  v1 = this;
  UFG::UIScreen::invoke((UFG::UIScreen *)&this->vfptr, "Objectives_Clear");
  v2 = UFG::ProgressionTracker::Instance();
  v3 = 0;
  v4 = UFG::ObjectiveTracker::GetFirstObjective(&v2->mObjectiveTracker);
  if ( !v4 )
    goto LABEL_19;
  do
  {
    if ( (signed int)UFG::qStringLength(v4->mCaption.mData) >= 1 )
    {
      v5 = 0;
      if ( v4->mStatus == 3 )
        v5 = 1;
      ++v3;
      UFG::UIHKWorldMapObjectivesWidget::Flash_AddObjective(
        &v1->ObjectivesWidget,
        (UFG::UIScreen *)&v1->vfptr,
        v4->mCaption.mData,
        v5);
    }
    v4 = UFG::ObjectiveTracker::GetNextObjective(&v2->mObjectiveTracker, v4);
  }
  while ( v4 );
  if ( v3 && v1->mViewType != 3 && UFG::UIHKScreenWorldMap::mViewMode != 1 )
  {
    v6 = &v1->ObjectivesWidget;
    if ( v3 <= 0 )
    {
      UFG::UIHKWorldMapObjectivesWidget::Flash_CleanObjective(v6, (UFG::UIScreen *)&v1->vfptr, v3);
    }
    else
    {
      UFG::UIHKWorldMapObjectivesWidget::UnHide(v6, (UFG::UIScreen *)&v1->vfptr);
      UFG::UIHKWorldMapObjectivesWidget::Flash_CleanObjective(&v1->ObjectivesWidget, (UFG::UIScreen *)&v1->vfptr, v3);
    }
    v7 = "Objectives_Resize";
  }
  else
  {
LABEL_19:
    v8 = v1->ObjectivesWidget.mState;
    v1->ObjectivesWidget.mbToggleDisabled = 1;
    if ( v8 > 1 )
      return;
    v1->ObjectivesWidget.mbIsHiding = 1;
    v1->ObjectivesWidget.mState = 2;
    v7 = "Objectives_Hide";
  }
  UFG::UIScreen::invoke((UFG::UIScreen *)&v1->vfptr, v7);
}

// File Line: 1991
// RVA: 0x5D6860
void __fastcall UFG::UIHKScreenWorldMap::DisplayMissions(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rbx
  UFG::ProgressionTracker *v2; // r15
  int v3; // esi
  UFG::Objective *v4; // rdi
  UFG::GameSlice *v5; // rax
  Render::SkinningCacheNode *v6; // rax
  const char *v7; // r14
  UFG::UIMapBlipTypeManager *v8; // rax
  UFG::UIHKMinimapBlipType *v9; // rbp
  UFG::Objective *v10; // rax
  const char *v11; // rdx
  unsigned int v12; // eax
  unsigned int v13; // eax
  Scaleform::GFx::Movie *v14; // rcx
  UFG::qSymbolUC result; // [rsp+50h] [rbp+8h]

  v1 = this;
  UFG::UIScreen::invoke((UFG::UIScreen *)&this->vfptr, "Objectives_Clear");
  v2 = UFG::ProgressionTracker::Instance();
  v3 = 0;
  v4 = UFG::ObjectiveTracker::GetFirstObjective(&v2->mObjectiveTracker);
  if ( !v4 )
    goto LABEL_28;
  do
  {
    v5 = v4->mpGameSlice;
    if ( v5 && (unsigned int)(v5->mType - 10) <= 1 )
    {
      if ( v4->mUsesPDA )
      {
        ++v3;
        UFG::UIHKWorldMapObjectivesWidget::Flash_AddMission(
          &v1->ObjectivesWidget,
          (UFG::UIScreen *)&v1->vfptr,
          v4->mCaption.mData,
          &customWorldMapCaption);
      }
      v6 = UFG::Objective::GetFirstIndicator(v4);
      if ( v6 )
      {
        v7 = (const char *)v6[1].mNode.mChild[0];
        UFG::qSymbolUC::create_from_string(&result, (const char *)v6[1].mNode.mChild[0]);
        v8 = UFG::UIMapBlipTypeManager::getInstance();
        v9 = UFG::UIMapBlipTypeManager::GetType(v8, &result);
        if ( UFG::UIMapBlipManager::HasBlipType(&v1->mMinimapIconManagerClone, &result) )
        {
          if ( v9 && v9->IsObjective )
          {
            ++v3;
            UFG::UIHKWorldMapObjectivesWidget::Flash_AddMission(
              &v1->ObjectivesWidget,
              (UFG::UIScreen *)&v1->vfptr,
              v4->mCaption.mData,
              v7);
          }
        }
      }
    }
    v10 = UFG::ObjectiveTracker::GetNextObjective(&v2->mObjectiveTracker, v4);
    v4 = v10;
  }
  while ( v10 );
  if ( v3 && UFG::UIHKScreenWorldMap::mViewMode != 1 )
  {
    if ( v3 > 0 )
    {
      v1->ObjectivesWidget.mbToggleDisabled = 0;
      if ( v1->ObjectivesWidget.mbIsHiding )
      {
        v1->ObjectivesWidget.mbIsHiding = 0;
        if ( (unsigned int)(v1->ObjectivesWidget.mState - 2) <= 1 )
        {
          v1->ObjectivesWidget.mState = (signed int)v10;
          UFG::UIScreen::invoke((UFG::UIScreen *)&v1->vfptr, "Objectives_Show");
        }
        *(_WORD *)&v1->ObjectivesWidget.mbIsHiding = 0;
      }
    }
    v11 = "Objectives_Resize";
  }
  else
  {
LABEL_28:
    v12 = v1->ObjectivesWidget.mState;
    v1->ObjectivesWidget.mbToggleDisabled = 1;
    if ( v12 > 1 )
      goto LABEL_23;
    v1->ObjectivesWidget.mbIsHiding = 1;
    v1->ObjectivesWidget.mState = 2;
    v11 = "Objectives_Hide";
  }
  UFG::UIScreen::invoke((UFG::UIScreen *)&v1->vfptr, v11);
LABEL_23:
  v13 = v1->PerkGoalsWidget.mState;
  v1->PerkGoalsWidget.mbToggleDisabled = 1;
  if ( v13 <= 1 )
  {
    v1->PerkGoalsWidget.mbIsHiding = 1;
    v1->PerkGoalsWidget.mState = 2;
    v14 = v1->mRenderable->m_movie.pObject;
    if ( v14 )
      Scaleform::GFx::Movie::Invoke(v14, "PerkGoals_Hide", 0i64, 0i64, 0);
  }
}

// File Line: 2048
// RVA: 0x5D6D20
void __fastcall UFG::UIHKScreenWorldMap::DisplaySecondaryObjectives(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rbx
  Scaleform::GFx::Movie *v2; // rcx
  signed int v3; // esi
  UFG::ProgressionTracker *v4; // rax
  UFG::ProgressionTracker *v5; // rdi
  UFG::SecondaryObjective *v6; // rax
  UFG::SecondaryObjective *v7; // r10
  UFG::SecondaryObjective::eStatus v8; // eax
  UFG::SecondaryObjective *v9; // rax
  UFG::SecondaryObjective *v10; // r8
  UFG::SecondaryObjective::eStatus v11; // eax
  Scaleform::GFx::Movie *v12; // rcx
  const char *v13; // rdx
  unsigned int v14; // eax

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  if ( v2 )
    Scaleform::GFx::Movie::Invoke(v2, "PerkGoals_Clear", 0i64, 0i64, 0);
  v3 = 0;
  v4 = UFG::ProgressionTracker::Instance();
  v5 = v4;
  v6 = UFG::SecondaryObjectiveTracker::GetObjective(&v4->mSecondaryObjectiveTracker, 0);
  v7 = v6;
  v8 = v6->mStatus;
  if ( v8 && v7->mCaption.mLength )
  {
    v3 = 1;
    UFG::UIHKWorldMapPerkGoalsWidget::Flash_AddGoal(
      &v1->PerkGoalsWidget,
      (UFG::UIScreen *)&v1->vfptr,
      v7->mCaption.mData,
      v8 == 2,
      v8 == 3,
      v7->mProgress,
      v7->mMaxProgress);
  }
  v9 = UFG::SecondaryObjectiveTracker::GetObjective(&v5->mSecondaryObjectiveTracker, ID_TRIAD_OBJECTIVE);
  v10 = v9;
  v11 = v9->mStatus;
  if ( v11 && v10->mCaption.mLength )
  {
    ++v3;
    UFG::UIHKWorldMapPerkGoalsWidget::Flash_AddGoal(
      &v1->PerkGoalsWidget,
      (UFG::UIScreen *)&v1->vfptr,
      v10->mCaption.mData,
      v11 == 2,
      v11 == 3,
      v10->mProgress,
      v10->mMaxProgress);
  }
  if ( v3 && v1->mViewType != 3 )
  {
    UFG::UIHKWorldMapPerkGoalsWidget::UnHide(&v1->PerkGoalsWidget, (UFG::UIScreen *)&v1->vfptr);
    v12 = v1->mRenderable->m_movie.pObject;
    if ( !v12 )
      return;
    v13 = "PerkGoals_Resize";
    goto LABEL_16;
  }
  v14 = v1->PerkGoalsWidget.mState;
  v1->PerkGoalsWidget.mbToggleDisabled = 1;
  if ( v14 <= 1 )
  {
    v1->PerkGoalsWidget.mbIsHiding = 1;
    v1->PerkGoalsWidget.mState = 2;
    v12 = v1->mRenderable->m_movie.pObject;
    if ( v12 )
    {
      v13 = "PerkGoals_Hide";
LABEL_16:
      Scaleform::GFx::Movie::Invoke(v12, v13, 0i64, 0i64, 0);
      return;
    }
  }
}

// File Line: 2100
// RVA: 0x5ED1C0
void __fastcall UFG::UIHKScreenWorldMap::HighlightCurrentObjectiveBlip(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rbx
  Scaleform::GFx::Movie *v2; // rdi
  UFG::UIHKPlayerObjective *v3; // rax
  UFG::qBaseTreeRB *v4; // rax
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h]

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 2;
    value.mValue.BValue = 0;
    Scaleform::GFx::Movie::SetVariable(v2, "mc_ObjectiveHighlight._visible", &value, 1i64);
    UFG::UIMapBlipManager::ResetObjectiveHighlight(&v1->mMinimapIconManagerClone);
    if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    {
      v3 = UFG::UIHKPlayerObjectiveManager::GetCurrentObjective(UFG::UIHKPlayerObjectiveManager::mInstance);
      if ( v3 )
      {
        if ( v3->minimapBlips.size )
        {
          v4 = UFG::BasePhysicsSystem::GetCollisionModel(
                 (UFG::BasePhysicsSystem *)&v1->mMinimapIconManagerClone,
                 *v3->minimapBlips.p);
          if ( v4 )
            BYTE2(v4->mNULL.mParent) = 1;
        }
      }
    }
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 2131
// RVA: 0x611410
void __fastcall UFG::UIHKScreenWorldMap::ShowTutorialPopup(UFG::UIHKScreenWorldMap *this)
{
  UFG::UIHKScreenWorldMap *v1; // rbx
  UFG::GameStat::MapBoolStat v2; // edi
  UFG::GameStatTracker *v3; // rax
  UFG::GameStatTracker *v4; // rax
  unsigned int v5; // edx
  UFG::qSymbol name; // [rsp+48h] [rbp+10h]
  UFG::qSymbol result; // [rsp+50h] [rbp+18h]

  v1 = this;
  UFG::qSymbol::create_from_string(&result, "DynamicTutorials");
  UFG::qSymbol::create_from_string(&name, "MapTutorial");
  v2 = (unsigned int)UFG::GameStat::GetMapBoolStatEnum(&result, 1);
  v3 = UFG::GameStatTracker::Instance();
  if ( !UFG::GameStatTracker::GetStat(v3, v2, &name) )
  {
    v4 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::SetStat(v4, v2, &name, 1);
    if ( qSymbol_Default_20.mUID != qSymbol_Collectible_HealthShrine_20.mUID )
    {
      if ( qSymbol_Default_20.mUID == qSymbol_Collectible_LockBox_20.mUID )
      {
        if ( UFG::HudAudio::m_instance )
        {
          v5 = 912326249;
LABEL_14:
          UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v5, 0i64, 0, 0i64);
          goto LABEL_15;
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
LABEL_15:
    v1->TutorialPopup.mChanged = 1;
    UFG::qString::Set(&v1->TutorialPopup.mCaption, "$WORLDMAP_TUTORIAL_01");
    v1->TutorialPopup.mType.mUID = qSymbol_Default_20.mUID;
    v1->TutorialPopup.mPosition = 0;
    v1->TutorialPopup.mTimeout = 30.0;
    *(_WORD *)&v1->TutorialPopup.mInfinite = 0;
    v1->TutorialPopup.mState = 1;
  }
}

// File Line: 2146
// RVA: 0x605E60
void __fastcall UFG::UIHKScreenWorldMap::SetGPSDestination(UFG::UIHKScreenWorldMap *this, UFG::qVector3 *worldPos)
{
  float v2; // xmm6_4
  float v3; // xmm7_4
  UFG::UIHKPlayerObjective *v4; // rsi
  UFG::UIHKScreenWorldMap *v5; // rdi
  float v6; // xmm0_4
  UFG::UIHKPlayerObjectiveManager *v7; // rbx
  bool v8; // r14
  bool v9; // zf
  UFG::UIHKObjectiveFlasherWidget::eState v10; // eax
  UFG::qVector3 pos; // [rsp+20h] [rbp-40h]
  UFG::qColour color; // [rsp+30h] [rbp-30h]

  v2 = worldPos->x;
  color = UFG::UITiledMapWidget::DefaultGPSLineColor;
  v3 = worldPos->y;
  pos.z = FLOAT_N1001_0;
  pos.x = v2;
  v4 = 0i64;
  pos.y = v3;
  v5 = this;
  if ( this->Cursor.mIsOpen )
  {
    v4 = this->Cursor.mSelectedObjective;
    color.r = this->Cursor.mSelectedBlipColor.r;
    color.g = this->Cursor.mSelectedBlipColor.g;
    color.b = this->Cursor.mSelectedBlipColor.b;
    color.a = this->Cursor.mSelectedBlipColor.a;
  }
  v6 = UFG::UITiledMapGPS::GetApproxAltitude(&pos);
  v7 = UFG::UIHKPlayerObjectiveManager::mInstance;
  v8 = 0;
  if ( !UFG::UIHKPlayerObjectiveManager::mInstance )
    goto LABEL_15;
  if ( !v4 )
  {
    v9 = UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjective_IsSet == 0;
    UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjectiveColor.r = color.r;
    v7->mWorldMapObjectiveColor.g = color.g;
    v7->mWorldMapObjectiveColor.b = color.b;
    v7->mWorldMapObjectiveColor.a = color.a;
    if ( v9
      || !v7->mWorldMapObjective.useFixedPos
      || (float)((float)((float)(v3 - v7->mWorldMapObjective.fixedPos.y)
                       * (float)(v3 - v7->mWorldMapObjective.fixedPos.y))
               + (float)((float)(v2 - v7->mWorldMapObjective.fixedPos.x)
                       * (float)(v2 - v7->mWorldMapObjective.fixedPos.x))) >= 4.0 )
    {
      *(_WORD *)&v7->mTempObjectiveSelected = 256;
      v7->mWorldMapObjective.fixedPos.x = v2;
      v7->mWorldMapObjective.fixedPos.y = v3;
      v7->mWorldMapObjective.fixedPos.z = v6;
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
    UFG::UITiledMapGPS::SetActive(&v5->GPS, 0);
    UFG::UITiledMapGPS::SetVisible(&v5->GPS, 0);
    UFG::UITiledMapGPS::SetActive(UFG::UIHKScreenHud::GPS, 0);
    UFG::UIHKObjectiveDistanceWidget::Clear(UFG::UIHKScreenHud::ObjectiveDistance);
    return;
  }
  *(_WORD *)&UFG::UIHKPlayerObjectiveManager::mInstance->mWorldMapObjective_IsSet = 0;
  UFG::UIHKPlayerObjectiveManager::FlashObjective(v7, v4->mObjective, 1);
LABEL_12:
  v10 = UFG::UIHKObjectiveFlasherWidget::mState;
  if ( UFG::UIHKObjectiveFlasherWidget::mState & 0xFFFFFFFB )
    v10 = 3;
  UFG::UIHKObjectiveFlasherWidget::mState = v10;
  UFG::UITiledMapGPS::SetDestination(&v5->GPS, &pos, v8);
  UFG::UITiledMapGPS::SetActive(&v5->GPS, 1);
  UFG::UITiledMapGPS::SetVisible(&v5->GPS, 1);
  UFG::UITiledMapWidget::SetGPSLineColor(&color);
  UFG::UITiledMapGPS::SetDestination(UFG::UIHKScreenHud::GPS, &pos, v8);
  UFG::UITiledMapGPS::SetActive(UFG::UIHKScreenHud::GPS, 1);
  UFG::UIHKObjectiveFlasherWidget::mColor = color;
}

// File Line: 2228
// RVA: 0x61FDF0
void __fastcall UFG::UIHKScreenWorldMap::customPreRender(UFG::UIHKScreenWorldMap *this, Render::View *view)
{
  Render::View *v2; // rdi
  UFG::UIHKScreenWorldMap *v3; // rbx

  v2 = view;
  v3 = this;
  UFG::UIHKScreenWorldMap::RenderBackground(this, view);
  if ( v3->mTileStreamerLowRes && v3->mUseLowResTiles )
    UFG::UIHKScreenWorldMap::RenderLowResMapNative(v3, v2);
  if ( v3->mRacePathState == 3 )
  {
    if ( UFG::BasePhysicsSystem::GetCollisionModel(
           (UFG::BasePhysicsSystem *)&v3->mMinimapIconManagerClone,
           UI_BLIP_RACE_START_20) )
    {
      UFG::UIMapBlipManager::RemoveIcon(&v3->mMinimapIconManagerClone, UI_BLIP_RACE_START_20);
    }
    if ( UFG::BasePhysicsSystem::GetCollisionModel(
           (UFG::BasePhysicsSystem *)&v3->mMinimapIconManagerClone,
           UI_BLIP_RACE_END_20) )
    {
      UFG::UIMapBlipManager::RemoveIcon(&v3->mMinimapIconManagerClone, UI_BLIP_RACE_END_20);
    }
  }
  else
  {
    UFG::UIHKScreenWorldMap::RenderRaceSpline(v3, v2);
  }
  if ( UFG::UITiledMapGPS::IsVisible(&v3->GPS) )
  {
    UFG::UIHKScreenWorldMap::RenderGPSSpline(v3, v2);
  }
  else if ( UFG::BasePhysicsSystem::GetCollisionModel(
              (UFG::BasePhysicsSystem *)&v3->mMinimapIconManagerClone,
              UI_BLIP_GPS_DESTINATION_20) )
  {
    UFG::UIMapBlipManager::RemoveIcon(&v3->mMinimapIconManagerClone, UI_BLIP_GPS_DESTINATION_20);
  }
  UFG::UIHKScreenWorldMap::RenderIconsNative(v3, v2);
}

// File Line: 2363
// RVA: 0x5E9BC0
void __usercall UFG::UIHKScreenWorldMap::GetViewportScaleMatrix(UFG::UIHKScreenWorldMap *this@<rcx>, UFG::qMatrix44 *ViewportScaleMatrix@<rdx>, float a3@<xmm0>)
{
  UFG::UIHKScreenWorldMap *v3; // rdi
  UFG::qMatrix44 *v4; // rsi
  __int64 v5; // rbx
  __int64 v6; // rdi
  __m128 v7; // xmm5
  __m128 v8; // xmm6
  __m128 v9; // xmm8
  __m128 v10; // xmm9
  __m128 v11; // xmm4
  __m128 v12; // xmm10
  __m128 v13; // xmm11
  __m128 v14; // xmm12
  __m128 v15; // xmm7
  __m128 v16; // xmm5
  __m128 v17; // xmm2
  UFG::qVector3 offset; // [rsp+20h] [rbp-D8h]
  UFG::qMatrix44 dest; // [rsp+30h] [rbp-C8h]
  UFG::qMatrix44 d; // [rsp+70h] [rbp-88h]
  __m128 v21; // [rsp+B8h] [rbp-40h]
  __m128 v22; // [rsp+C8h] [rbp-30h]
  __m128 v23; // [rsp+D8h] [rbp-20h]

  v3 = this;
  v4 = ViewportScaleMatrix;
  v5 = ((__int64 (*)(void))this->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)();
  v6 = ((__int64 (*)(void))v3->mRenderable->m_movie.pObject->vfptr[1].__vecDelDtor)();
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 56i64))(v5);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 48i64))(v6);
  offset.y = (float)(a3 * -1.0) * 0.5;
  offset.x = (float)(a3 * -1.0) * 0.5;
  offset.z = 0.0;
  UFG::qTranslationMatrix(&dest, &offset);
  offset.x = UFG::gUIViewportScaleH * UFG::gUIViewportScale;
  offset.y = UFG::gUIViewportScaleV * UFG::gUIViewportScale;
  LODWORD(offset.z) = (_DWORD)FLOAT_1_0;
  UFG::qScaleMatrix(&d, &offset);
  UFG::qInverseAffine((UFG::qMatrix44 *)((char *)&d + 56), &dest);
  v7 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0), (__m128)d.v0), (__m128)0i64),
             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85), *(__m128 *)&d.v0.z)),
           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170), *(__m128 *)&d.v1.z)),
         _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), *(__m128 *)&d.v2.z));
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0), (__m128)d.v0), (__m128)0i64),
             _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85), *(__m128 *)&d.v0.z)),
           _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170), *(__m128 *)&d.v1.z)),
         _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255), *(__m128 *)&d.v2.z));
  v9 = *(__m128 *)&d.v3.z;
  v10 = v21;
  v11 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0), (__m128)d.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85), *(__m128 *)&d.v0.z)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170), *(__m128 *)&d.v1.z)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), *(__m128 *)&d.v2.z));
  v12 = v22;
  v13 = v23;
  v14 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), *(__m128 *)&d.v2.z),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0), (__m128)d.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85), *(__m128 *)&d.v0.z)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), *(__m128 *)&d.v1.z)));
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), *(__m128 *)&d.v3.z), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v21)),
            _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v22)),
          _mm_mul_ps(_mm_shuffle_ps(v7, v7, 255), v23));
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), *(__m128 *)&d.v3.z), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), v21)),
            _mm_mul_ps(_mm_shuffle_ps(v8, v8, 170), v22)),
          _mm_mul_ps(_mm_shuffle_ps(v8, v8, 255), v23));
  v17 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), *(__m128 *)&d.v3.z), (__m128)0i64),
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v21));
  v4->v0 = (UFG::qVector4)v15;
  v4->v1 = (UFG::qVector4)v16;
  v4->v2 = (UFG::qVector4)_mm_add_ps(
                            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 255), v13),
                            _mm_add_ps(v17, _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v12)));
  v4->v3 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v9), (__m128)0i64),
                                _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v10)),
                              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v12)),
                            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), v13));
}

// File Line: 2374
// RVA: 0x600E80
void __fastcall UFG::UIHKScreenWorldMap::RenderBackground(UFG::UIHKScreenWorldMap *this, Render::View *view)
{
  float v2; // xmm0_4
  Render::View *v3; // rbx
  UFG::qColour colour; // [rsp+30h] [rbp-28h]
  Render::Poly poly; // [rsp+60h] [rbp+8h]

  v2 = this->mBackgroundAlpha;
  v3 = view;
  *(_QWORD *)&colour.r = 0i64;
  colour.a = v2;
  colour.b = 0.0;
  Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>(&poly);
  Render::Poly::SetScreenPos(&poly, 0.0, 0.0, 1.0, 1.0, 0.0);
  Render::Poly::SetColour(&poly, &colour);
  Render::View::Draw(v3, &poly, 0xB11369EB, 0i64, 0x62F81854u, 0xA3833FDE);
}

// File Line: 2404
// RVA: 0x601220
void __fastcall UFG::UIHKScreenWorldMap::RenderLowResMapNative(UFG::UIHKScreenWorldMap *this, Render::View *view)
{
  Render::View *v2; // rbx
  UFG::UIHKScreenWorldMap *v3; // rdi
  UFG::UITiledMapTextureManager *v4; // r8
  UFG::ScreenPoint2f v5; // [rsp+40h] [rbp-18h]
  int v6; // [rsp+48h] [rbp-10h]
  UFG::WorldPoint2f point; // [rsp+60h] [rbp+8h]
  UFG::ScreenPoint2f v8; // [rsp+70h] [rbp+18h]

  v2 = view;
  v3 = this;
  point.x = UFG::UITiledMapMath::InitWorldGeo.MinX;
  point.y = UFG::UITiledMapMath::InitWorldGeo.MaxY;
  UFG::ScreenPoint2f::ScreenPoint2f(&v8, &point, &this->m_mapGeo);
  v4 = v3->mTileStreamerLowRes;
  v5 = v8;
  v6 = 0;
  UFG::UIHKScreenWorldMap::RenderMapTilesNative(v3, v2, v4, 256, 12, 9, 1.0, (UFG::qVector3 *)&v5);
}

// File Line: 2420
// RVA: 0x6012D0
void __fastcall UFG::UIHKScreenWorldMap::RenderMapTilesNative(UFG::UIHKScreenWorldMap *this, Render::View *view, UFG::UITiledMapTextureManager *tileStreamer, int tileSize, int mapWidth, int mapHeight, float tileScale, UFG::qVector3 *screenPos)
{
  float v8; // xmm0_4
  UFG::UIHKScreenWorldMap *v9; // rbx
  int v10; // er15
  UFG::UITiledMapTextureManager *v11; // r14
  __m128 v12; // xmm5
  __m128 v13; // xmm6
  __m128 v14; // xmm4
  __m128 v15; // xmm12
  __m128 v16; // xmm14
  __m128 v17; // xmm11
  __m128 v18; // xmm15
  __int64 v19; // rax
  __m128 v20; // xmm12
  signed int v21; // edi
  int v22; // er13
  signed int v23; // ebx
  signed int v24; // esi
  char *v25; // rax
  unsigned int TextureUID; // er14
  UFG::qResourceWarehouse *v27; // rax
  UFG::qResourceInventory *v28; // rax
  Illusion::Texture *v29; // rax
  Illusion::Texture *v30; // rdi
  int v31; // eax
  UFG::qVector3 scale; // [rsp+60h] [rbp-80h]
  UFG::qMatrix44 Color; // [rsp+70h] [rbp-70h]
  UFG::qMatrix44 v34; // [rsp+B0h] [rbp-30h]
  UFG::qMatrix44 dest; // [rsp+F0h] [rbp+10h]
  UFG::qMatrix44 v36; // [rsp+130h] [rbp+50h]
  UFG::qMatrix44 v37; // [rsp+170h] [rbp+90h]
  UFG::qMatrix44 result; // [rsp+1B0h] [rbp+D0h]
  __int64 v39; // [rsp+2D0h] [rbp+1F0h]
  Render::View *viewa; // [rsp+2D8h] [rbp+1F8h]
  UFG::UITiledMapTextureManager *vars0; // [rsp+2E0h] [rbp+200h]
  UFG::UIHKScreenWorldMap *v42; // [rsp+2F0h] [rbp+210h]
  Render::View *v43; // [rsp+2F8h] [rbp+218h]
  signed int v44; // [rsp+300h] [rbp+220h]
  UFG::qVector3 *offset; // [rsp+308h] [rbp+228h]

  v43 = view;
  v42 = this;
  v8 = this->m_mapGeo.scale;
  v9 = this;
  v10 = tileSize;
  v11 = tileStreamer;
  scale.x = v8 / *(float *)&tileStreamer;
  scale.y = v8 / *(float *)&tileStreamer;
  LODWORD(scale.z) = (_DWORD)FLOAT_1_0;
  UFG::qScaleMatrix((UFG::qMatrix44 *)((char *)&dest + 32), &scale);
  UFG::qRotationMatrixZ(&Color, v9->m_mapGeo.rot);
  UFG::qTranslationMatrix(&v37, offset);
  v12 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0), (__m128)Color.v0),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85), (__m128)Color.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170), (__m128)Color.v2)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), (__m128)Color.v3));
  v13 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0), (__m128)Color.v0),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85), (__m128)Color.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170), (__m128)Color.v2)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255), (__m128)Color.v3));
  v14 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0), (__m128)Color.v0),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85), (__m128)Color.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170), (__m128)Color.v2)),
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), (__m128)Color.v3));
  v15 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), (__m128)Color.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0), (__m128)Color.v0),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85), (__m128)Color.v1)),
            _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), (__m128)Color.v2)));
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), (__m128)v37.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), (__m128)v37.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), (__m128)v37.v2)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 255), (__m128)v37.v3));
  v17 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), (__m128)v37.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), (__m128)v37.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), (__m128)v37.v2)),
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 255), (__m128)v37.v3));
  v18 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), (__m128)v37.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), (__m128)v37.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), (__m128)v37.v2)),
          _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), (__m128)v37.v3));
  v19 = (unsigned int)v43;
  Color.v0.x = UFG::qColour::White.r;
  Color.v0.y = UFG::qColour::White.g;
  Color.v0.z = UFG::qColour::White.b;
  v20 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), (__m128)v37.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), (__m128)v37.v1)),
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), (__m128)v37.v2)),
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 255), (__m128)v37.v3));
  Color.v0.w = v9->mMapTileAlpha;
  if ( (signed int)v43 > 0 )
  {
    v21 = 0;
    v44 = 0;
    v22 = 0;
    *(_QWORD *)&scale.x = (unsigned int)v43;
    do
    {
      v23 = 0;
      if ( (signed int)v42 > 0 )
      {
        v24 = 0;
        do
        {
          v25 = UFG::UITiledMapTextureManager::GetTileName(v11, v23 + v22);
          if ( v25 )
          {
            TextureUID = UFG::qStringHashUpper32(v25 + 6, 0xFFFFFFFF);
            v27 = UFG::qResourceWarehouse::Instance();
            v28 = UFG::qResourceWarehouse::GetInventory(v27, 0x8B43FABF);
            v29 = (Illusion::Texture *)v28->vfptr->Get(v28, TextureUID);
            v30 = v29;
            if ( v29 )
            {
              v31 = Illusion::Texture::GetSamplerAddressFlags(v29);
              Illusion::Texture::SetSamplerAddressFlags(v30, v31 | 3);
            }
            v21 = v44;
            scale.z = 0.0;
            scale.x = (float)v24;
            scale.y = (float)v44;
            UFG::qTranslationMatrix(&v34, &scale);
            v36.v0 = (UFG::qVector4)_mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v0, (__m128)v34.v0, 0), v17),
                                            (__m128)0i64),
                                          _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v0, (__m128)v34.v0, 85), v20)),
                                        _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v0, (__m128)v34.v0, 170), v16)),
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v0, (__m128)v34.v0, 255), v18));
            v36.v1 = (UFG::qVector4)_mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v1, (__m128)v34.v1, 0), v17),
                                            (__m128)0i64),
                                          _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v1, (__m128)v34.v1, 85), v20)),
                                        _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v1, (__m128)v34.v1, 170), v16)),
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v1, (__m128)v34.v1, 255), v18));
            v36.v2 = (UFG::qVector4)_mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v2, (__m128)v34.v2, 0), v17),
                                            (__m128)0i64),
                                          _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v2, (__m128)v34.v2, 85), v20)),
                                        _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v2, (__m128)v34.v2, 170), v16)),
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v2, (__m128)v34.v2, 255), v18));
            v36.v3 = (UFG::qVector4)_mm_add_ps(
                                      _mm_add_ps(
                                        _mm_add_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v3, (__m128)v34.v3, 0), v17),
                                            (__m128)0i64),
                                          _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v3, (__m128)v34.v3, 85), v20)),
                                        _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v3, (__m128)v34.v3, 170), v16)),
                                      _mm_mul_ps(_mm_shuffle_ps((__m128)v34.v3, (__m128)v34.v3, 255), v18));
            UFG::qMatrix44::operator*(&v36, &result, (UFG::qMatrix44 *)(v39 + 3416));
            UFG::DrawColoredRect_Xform(
              viewa,
              0.0,
              0.0,
              (float)v10,
              (float)v10,
              (UFG::qColour *)&Color,
              TextureUID,
              0i64,
              0xA3833FDE,
              0x62F81854u,
              &result);
            v11 = vars0;
          }
          ++v23;
          v24 += v10;
        }
        while ( v23 < (signed int)v42 );
        v19 = *(_QWORD *)&scale.x;
      }
      v21 += v10;
      v22 += (signed int)v42;
      *(_QWORD *)&scale.x = --v19;
      v44 = v21;
    }
    while ( v19 );
  }
}

// File Line: 2468
// RVA: 0x601030
void __fastcall UFG::UIHKScreenWorldMap::RenderIconsNative(UFG::UIHKScreenWorldMap *this, Render::View *view)
{
  UFG::UIRenderQuad *v2; // rbx
  Render::View *v3; // rsi
  UFG::UIHKScreenWorldMap *v4; // rdi
  UFG::qVector4 v5; // xmm7
  UFG::qVector4 v6; // xmm8
  UFG::qVector4 v7; // xmm9
  UFG::qVector4 v8; // xmm10
  float v9; // xmm0_4
  UFG::qMatrix44 *v10; // rdx
  float v11; // xmm6_4
  float v12; // xmm1_4
  float h; // xmm6_4
  float v14; // xmm0_4
  UFG::qColour Color; // [rsp+60h] [rbp-B8h]
  UFG::qMatrix44 TransformMatrix; // [rsp+70h] [rbp-A8h]

  v2 = this->mPolyListNative.p;
  v3 = view;
  v4 = this;
  if ( &v2[this->mPolyListNative.size] != v2 )
  {
    v5 = 0i64;
    v5.x = (float)1;
    v6 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 81);
    v7 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 69);
    v8 = (UFG::qVector4)_mm_shuffle_ps((__m128)v5, (__m128)v5, 21);
    do
    {
      v9 = v2->Color.r;
      v10 = v2->Matrix;
      v11 = v2->Size;
      Color.g = v2->Color.g;
      v12 = v2->Color.a * v4->mIconAlpha;
      h = v11 * v2->Scale;
      Color.r = v9;
      v14 = v2->Color.b;
      Color.a = v12;
      Color.b = v14;
      TransformMatrix.v0 = v5;
      TransformMatrix.v1 = v6;
      TransformMatrix.v2 = v7;
      TransformMatrix.v3 = v8;
      if ( v10 )
        UFG::qMatrix44::operator*=(&TransformMatrix, v10);
      UFG::qMatrix44::operator*=(&TransformMatrix, &v4->mViewportScaleMatrix);
      UFG::DrawColoredRect_Xform(
        v3,
        v2->X - (float)(h * 0.5),
        v2->Y - (float)(h * 0.5),
        h,
        h,
        &Color,
        v2->TextureID,
        v2->UVs,
        0xA3833FDE,
        0x62F81854u,
        &TransformMatrix);
      ++v2;
    }
    while ( &v4->mPolyListNative.p[v4->mPolyListNative.size] != v2 );
  }
}

// File Line: 2562
// RVA: 0x600F20
void __fastcall UFG::UIHKScreenWorldMap::RenderGPSSpline(UFG::UIHKScreenWorldMap *this, Render::View *view)
{
  unsigned int v2; // edi
  UFG::UIHKScreenWorldMap *v3; // rbx
  float v4; // xmm1_4
  UFG::qBaseTreeRB *v5; // rax
  UFG::qVector3 *v6; // rdx
  __int64 v7; // rcx
  float yPos; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  UFG::qColour worldPos; // [rsp+30h] [rbp-18h]

  v2 = this->GPS.mNumSplinePoints;
  v3 = this;
  if ( v2 >= 2 )
  {
    v4 = this->mIconAlpha;
    worldPos = UFG::UITiledMapWidget::GPSLineColor;
    worldPos.a = v4;
    _mm_store_si128((__m128i *)&worldPos, (__m128i)worldPos);
    UFG::UIHKScreenWorldMap::RenderSpline(this, &this->GPS.mSplinePoints, v2, &worldPos, view);
    if ( UFG::UITiledMapTweakables::GPS_ShowDestinationBlip )
    {
      v5 = UFG::BasePhysicsSystem::GetCollisionModel(
             (UFG::BasePhysicsSystem *)&v3->mMinimapIconManagerClone,
             UI_BLIP_GPS_DESTINATION_20);
      v6 = v3->GPS.mSplinePoints.p;
      v7 = v2 - 1;
      yPos = v6[v7].y;
      v9 = v6[v7].z;
      v10 = v6[v7].x;
      worldPos.r = v6[v7].x;
      worldPos.g = yPos;
      worldPos.b = v9;
      if ( v5 )
        UFG::UIMapBlip::SetPosition((UFG::UIMapBlip *)v5, (UFG::qVector3 *)&worldPos);
      else
        UFG::UIMapBlipManager::CreateIcon(
          &v3->mMinimapIconManagerClone,
          UI_BLIP_GPS_DESTINATION_20,
          "waypoint",
          v10,
          v9,
          yPos)->mBoundIcon = 0;
    }
  }
}

// File Line: 2594
// RVA: 0x602160
void __fastcall UFG::UIHKScreenWorldMap::RenderRaceSpline(UFG::UIHKScreenWorldMap *this, Render::View *view)
{
  float v2; // xmm1_4
  unsigned int v3; // esi
  UFG::qArray<UFG::qVector3,0> *v4; // rdi
  UFG::UIHKScreenWorldMap *v5; // rbx
  UFG::BasePhysicsSystem *v6; // rbx
  UFG::qBaseTreeRB *v7; // rax
  float *v8; // rcx
  float yPos; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  UFG::qBaseTreeRB *v12; // rax
  UFG::qVector3 *v13; // rcx
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  UFG::qVector3 worldPos; // [rsp+30h] [rbp-28h]
  UFG::qColour v18; // [rsp+40h] [rbp-18h]

  v2 = this->mRacePathAlpha;
  v3 = this->RacePath.m_NumSplinePoints;
  v4 = &this->RacePath.m_SplinePoints;
  v18 = UFG::UITiledMapWidget::RaceRouteColor;
  v18.a = v2;
  v5 = this;
  _mm_store_si128((__m128i *)&v18, (__m128i)v18);
  UFG::UIHKScreenWorldMap::RenderSpline(this, &this->RacePath.m_SplinePoints, v3, &v18, view);
  if ( v3 )
  {
    v6 = (UFG::BasePhysicsSystem *)&v5->mMinimapIconManagerClone;
    v7 = UFG::BasePhysicsSystem::GetCollisionModel(v6, UI_BLIP_RACE_START_20);
    v8 = &v4->p->x;
    yPos = v8[1];
    v10 = v8[2];
    v11 = *v8;
    worldPos.x = *v8;
    worldPos.y = yPos;
    worldPos.z = v10;
    if ( v7 )
      UFG::UIMapBlip::SetPosition((UFG::UIMapBlip *)v7, &worldPos);
    else
      UFG::UIMapBlipManager::CreateIcon(
        (UFG::UIMapBlipManager *)v6,
        UI_BLIP_RACE_START_20,
        "race_start_flag",
        v11,
        v10,
        yPos)->mBoundIcon = 0;
    v12 = UFG::BasePhysicsSystem::GetCollisionModel(v6, UI_BLIP_RACE_END_20);
    v13 = v4->p;
    v14 = v13[v3 - 1].y;
    v15 = v13[v3 - 1].z;
    v16 = v13[v3 - 1].x;
    v18.r = v13[v3 - 1].x;
    v18.g = v14;
    v18.b = v15;
    if ( v12 )
    {
      UFG::UIMapBlip::SetPosition((UFG::UIMapBlip *)v12, (UFG::qVector3 *)&v18);
    }
    else if ( v16 != worldPos.x || v14 != worldPos.y || v15 != worldPos.z )
    {
      UFG::UIMapBlipManager::CreateIcon((UFG::UIMapBlipManager *)v6, UI_BLIP_RACE_END_20, "race_end", v16, v14, v14)->mBoundIcon = 0;
    }
  }
}

// File Line: 2634
// RVA: 0x6022D0
void __fastcall UFG::UIHKScreenWorldMap::RenderSpline(UFG::UIHKScreenWorldMap *this, UFG::qArray<UFG::qVector3,0> *SplinePoints, const unsigned int NumSplinePoints, UFG::qColour *Colour, Render::View *view)
{
  UFG::qArray<UFG::qVector3,0> *v5; // rsi
  UFG::UIHKScreenWorldMap *v6; // r15
  unsigned int v7; // ebx
  UFG::qColour *v8; // r14
  __int64 v9; // rbp
  float *v10; // rdi
  UFG::qVector3 *v11; // r9
  __m128 v12; // xmm6
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
  float *v27; // rcx
  float *v28; // rdx
  signed __int64 v29; // r8
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
  signed __int64 v50; // rcx
  float v51; // xmm1_4
  float v52; // xmm3_4
  signed __int64 v53; // rax
  float v54; // xmm0_4
  float v55; // xmm1_4
  unsigned int v56; // er8

  if ( NumSplinePoints >= 2 )
  {
    v5 = SplinePoints;
    v6 = this;
    v7 = NumSplinePoints;
    v8 = Colour;
    v9 = 2 * NumSplinePoints;
    v10 = (float *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 96 * NumSplinePoints, 0x10u);
    memset(v10, 0, 48 * v9);
    v11 = v5->p;
    v12 = (__m128)LODWORD(v11[1].y);
    v12.m128_f32[0] = v12.m128_f32[0] - v11->y;
    LODWORD(v13) = COERCE_UNSIGNED_INT(v11[1].x - v11->x) ^ _xmm[0];
    v14 = v12;
    v14.m128_f32[0] = (float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v13 * v13);
    if ( v14.m128_f32[0] == 0.0 )
      v15 = 0.0;
    else
      v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
    v16 = v12.m128_f32[0] * v15;
    v17 = v13 * v15;
    v18 = v7 - 1;
    v19 = v17;
    v20 = v15 * 0.0;
    v21 = (float)(v17 * 3.0) + v11->y;
    v22 = v20;
    v23 = (float)(v20 * 3.0) + v11->z;
    *v10 = (float)(v16 * 3.0) + v11->x;
    v10[1] = v21;
    v10[2] = v23;
    v24 = v11->z - (float)(v20 * 3.0);
    v25 = v11->y - (float)(v17 * 3.0);
    v10[12] = v11->x - (float)(v16 * 3.0);
    v26 = v16;
    v10[13] = v25;
    v10[14] = v24;
    if ( (unsigned int)v18 > 1 )
    {
      v27 = &v11[1].y;
      v28 = &v11[2].x;
      v29 = (signed __int64)(v10 + 38);
      v30 = (unsigned int)(v18 - 1);
      do
      {
        v31 = *(v27 - 1);
        v32 = *v27;
        v33 = v28[1] - *v27;
        LODWORD(v34) = COERCE_UNSIGNED_INT(*v28 - v31) ^ _xmm[0];
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
        v29 += 96i64;
        v28 += 3;
        v27 += 3;
        v45 = v40 * v42;
        *(float *)(v29 - 144) = (float)(v43 * 3.0) + *(v27 - 2);
        *(float *)(v29 - 152) = v31 + (float)(v44 * 3.0);
        *(float *)(v29 - 148) = v32 + (float)(v45 * 3.0);
        v46 = *(v27 - 4) - (float)(v44 * 3.0);
        v26 = v16;
        v47 = *(v27 - 3) - (float)(v45 * 3.0);
        v48 = *(v27 - 2) - (float)(v43 * 3.0);
        *(float *)(v29 - 104) = v46;
        v19 = v17;
        v22 = v20;
        *(float *)(v29 - 100) = v47;
        *(float *)(v29 - 96) = v48;
        --v30;
      }
      while ( v30 );
    }
    v49 = (unsigned int)(2 * v18);
    v50 = 6 * v49;
    v51 = (float)(v20 * 3.0) + v11[v18].z;
    v52 = (float)(v16 * 3.0) + v11[v18].x;
    v53 = 6i64 * (unsigned int)(v49 + 1);
    v10[2 * v50 + 1] = (float)(v17 * 3.0) + v11[v18].y;
    v10[2 * v50 + 2] = v51;
    v10[2 * v50] = v52;
    v54 = v11[v18].z;
    v55 = v11[v18].y - (float)(v17 * 3.0);
    v56 = 4;
    v10[2 * v53] = v11[v18].x - (float)(v16 * 3.0);
    v10[2 * v53 + 1] = v55;
    v10[2 * v53 + 2] = v54 - (float)(v20 * 3.0);
    if ( UFG::UIHKTweakables::WorldMap_UsePointList )
      v56 = 0;
    UFG::UIHKScreenWorldMap::RenderMinimapPrimitive(v6, view, v56, v8);
  }
}

// File Line: 2688
// RVA: 0x601910
void __fastcall UFG::UIHKScreenWorldMap::RenderMinimapPrimitive(UFG::UIHKScreenWorldMap *this, Render::View *view, unsigned int PrimitiveType, UFG::qColour *Color)
{
  UFG::qColour *v4; // rsi
  signed int v5; // er12
  Render::View *v6; // r13
  UFG::UIHKScreenWorldMap *v7; // rdi
  __m128 v8; // xmm11
  __m128 v9; // xmm14
  __m128 v10; // xmm12
  __m128 v11; // xmm15
  int v12; // er14
  void *v13; // r15
  int v14; // esi
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm8_4
  float *v18; // rbx
  __int64 v19; // rdi
  float v20; // xmm9_4
  float v21; // xmm10_4
  float v22; // xmm11_4
  float v23; // xmm12_4
  float v24; // xmm13_4
  float v25; // xmm14_4
  float v26; // xmm15_4
  float v27; // xmm1_4
  float v28; // xmm5_4
  float v29; // xmm4_4
  float v30; // xmm1_4
  Illusion::Material *v31; // rdi
  unsigned int v32; // ebx
  UFG::qResourceInventory *v33; // rax
  UFG::qResourceWarehouse *v34; // rax
  Illusion::Primitive *v35; // rbx
  UFG::MinimapPoint2f v36[2]; // [rsp+40h] [rbp-88h]
  UFG::MinimapPoint2f v37; // [rsp+50h] [rbp-78h]
  __m128 v38; // [rsp+58h] [rbp-70h]
  UFG::MinimapTilePoint2f iconPos; // [rsp+68h] [rbp-60h]
  UFG::qMatrix44 result; // [rsp+70h] [rbp-58h]
  float v41; // [rsp+B0h] [rbp-18h]
  __int64 v42; // [rsp+B8h] [rbp-10h]
  UFG::qMatrix44 v43; // [rsp+C8h] [rbp+0h]
  UFG::qMatrix44 dest; // [rsp+108h] [rbp+40h]
  UFG::qMatrix44 v45; // [rsp+148h] [rbp+80h]
  UFG::qMatrix44 v46; // [rsp+188h] [rbp+C0h]
  UFG::qMatrix44 v47; // [rsp+1C8h] [rbp+100h]
  UFG::ScreenPoint2f v48; // [rsp+2E8h] [rbp+220h]
  UFG::WorldPoint2f point; // [rsp+300h] [rbp+238h]
  void *vertices; // [rsp+308h] [rbp+240h]
  int num_vertices; // [rsp+310h] [rbp+248h]
  void *indices; // [rsp+318h] [rbp+250h]
  int num_indices; // [rsp+320h] [rbp+258h]
  __int64 v54; // [rsp+338h] [rbp+270h]

  v42 = -2i64;
  v4 = Color;
  v5 = PrimitiveType;
  v6 = view;
  v7 = this;
  point = 0i64;
  UFG::MinimapPoint2f::MinimapPoint2f((UFG::MinimapPoint2f *)&result.v1, (UFG::WorldPoint2f *)&v54);
  UFG::MinimapTilePoint2f::MinimapTilePoint2f(&iconPos, &v36[1], &v7->m_mapGeo);
  v48 = 0i64;
  UFG::ScreenPoint2f::InitFromIconPos(&v48, &iconPos, &v7->m_mapGeo);
  *(UFG::ScreenPoint2f *)v38.m128_f32 = v48;
  v38.m128_i32[2] = 0;
  UFG::MinimapPoint2f::MinimapPoint2f(&v37, &v7->m_mapGeo.centerPosition);
  LODWORD(v36[0].x) = LODWORD(v37.x) ^ _xmm[0];
  LODWORD(v36[0].y) = LODWORD(v37.y) ^ _xmm[0];
  v36[1].x = 0.0;
  UFG::qTranslationMatrix(&dest, (UFG::qVector3 *)v36);
  v36[0].x = v7->m_mapGeo.scale;
  v36[0].y = v36[0].x;
  LODWORD(v36[1].x) = (_DWORD)FLOAT_1_0;
  UFG::qScaleMatrix(&v45, (UFG::qVector3 *)v36);
  UFG::qRotationMatrixZ(&v46, v7->m_mapGeo.rot);
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
  UFG::qMatrix44::operator*(&v47, (UFG::qMatrix44 *)((char *)&result + 8), &v7->mViewportScaleMatrix);
  v12 = (signed int)(float)(v4->r * 255.0) | (((signed int)(float)(v4->g * 255.0) | (((signed int)(float)(v4->b * 255.0) | ((signed int)(float)(v4->a * 255.0) << 8)) << 8)) << 8);
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
    v21 = result.v3.w;
    v22 = result.v3.z;
    v23 = result.v2.x;
    v24 = result.v1.w;
    v25 = result.v1.z;
    v26 = result.v1.x;
    do
    {
      v27 = *v18;
      point.x = *(v18 - 1);
      point.y = v27;
      UFG::MinimapPoint2f::MinimapPoint2f(v36, &point);
      v28 = (float)((float)((float)(v25 * v36[0].y) + (float)(result.v0.z * v36[0].x)) + v15) + v22;
      v29 = (float)((float)((float)(v24 * v36[0].y) + (float)(result.v0.w * v36[0].x)) + v16) + v21;
      v30 = (float)((float)((float)(v23 * v36[0].y) + (float)(v26 * v36[0].x)) + v17) + v20;
      *(v18 - 1) = v28;
      *v18 = v29;
      v18[1] = v30;
      *((_DWORD *)v18 + 10) = v12;
      *(v18 - 1) = v28 / (float)(signed int)UFG::UIScreenManager::s_instance->m_flashWidth;
      *v18 = v29 / (float)(signed int)UFG::UIScreenManager::s_instance->m_flashHeight;
      v18 += 12;
      --v19;
    }
    while ( v19 );
  }
  v31 = Render::View::CreateSimpleMaterial(0xB11369EB, 0x62F81854u, 0xA3833FDE, 0);
  if ( !(_S14_4 & 1) )
  {
    _S14_4 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&vertex_decl_handle_3.mPrev);
    atexit(UFG::UIHKScreenWorldMap::RenderMinimapPrimitive_::_4_::_dynamic_atexit_destructor_for__vertex_decl_handle__);
  }
  if ( !vertex_decl_handle_3.mData )
  {
    v32 = UFG::qStringHash32("VertexDecl.Dynamic", 0xFFFFFFFF);
    v33 = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
    {
      v34 = UFG::qResourceWarehouse::Instance();
      v33 = UFG::qResourceWarehouse::GetInventory(v34, 0x3E5FDA3Eu);
      `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = v33;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&vertex_decl_handle_3.mPrev, 0x3E5FDA3Eu, v32, v33);
  }
  v35 = Illusion::Primitive::Create("MiniMap");
  Illusion::Primitive::SetBuffers(
    v35,
    (Illusion::Primitive::Type)v5,
    v13,
    v14,
    (Illusion::VertexDecl *)vertex_decl_handle_3.mData,
    indices,
    num_indices,
    1);
  Render::View::Draw(v6, v35, v31, 0i64);
}
    indices,
    num_indices,
    1);
  Render::View::Draw(v6, v35, v31, 0i64);
}

// File Line: 2751
// RVA: 0x5D24F0
void __fastcall UFG::UIHKScreenWorldMap::AddLegendItem(UFG::UIHKScreenWorldMap *this, const char *icon, const char *caption)
{
  const char *v3; // rdi
  const char *v4; // rsi
  UFG::UIHKScreenWorldMap *v5; // rbp
  UFG::allocator::free_link *v6; // rax
  UFG::allocator::free_link *v7; // rbx
  UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *v8; // rax

  v3 = caption;
  v4 = icon;
  v5 = this;
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
    UFG::qString::Set((UFG::qString *)&v7[2], v4);
    UFG::qString::Set((UFG::qString *)&v7[7], v3);
    v8 = v5->mLegendItems.mNode.mPrev;
    v8->mNext = (UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *)v7;
    v7->mNext = (UFG::allocator::free_link *)v8;
    v7[1].mNext = (UFG::allocator::free_link *)&v5->mLegendItems;
    v5->mLegendItems.mNode.mPrev = (UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *)v7;
  }
}

// File Line: 2784
// RVA: 0x610A30
void __fastcall UFG::UIHKScreenWorldMap::ShowLegend(UFG::UIHKScreenWorldMap *this, int pageNumber)
{
  UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *v2; // rbp
  signed int v3; // esi
  signed int v4; // edi
  UFG::UIHKScreenWorldMap *v5; // r8
  int v6; // er15
  UFG::UIHKScreenWorldMap *v7; // r14
  int v8; // ebx
  signed int v9; // eax
  signed int v10; // ecx
  Scaleform::GFx::Movie *v11; // rcx
  UFG::qNode<UFG::LegendItemData,UFG::LegendItemData> *v12; // rbx
  int v13; // er15
  __int64 v14; // rax
  UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *i; // rax

  v2 = &this->mLegendItems;
  v3 = 0;
  v4 = 1;
  v5 = (UFG::UIHKScreenWorldMap *)this->mLegendItems.mNode.mNext;
  v6 = pageNumber;
  v7 = this;
  v8 = 1;
  v9 = 0;
  if ( v5 != (UFG::UIHKScreenWorldMap *)&this->mLegendItems )
  {
    do
    {
      v5 = (UFG::UIHKScreenWorldMap *)v5->mPrev;
      ++v9;
    }
    while ( v5 != (UFG::UIHKScreenWorldMap *)v2 );
    if ( v9 )
    {
      if ( v9 <= 12 )
        goto LABEL_20;
      v10 = 12;
      do
      {
        v10 += 12;
        ++v8;
      }
      while ( v9 > v10 );
      if ( v8 )
      {
LABEL_20:
        v11 = v7->mRenderable->m_movie.pObject;
        if ( v11 )
          Scaleform::GFx::Movie::Invoke(v11, "Legend_Clear", 0i64, 0i64, 0);
        UFG::UIHKWorldMapLegendWidget::Flash_SetLegendPageNumbers(&v7->Legend, (UFG::UIScreen *)&v7->vfptr, v6, v8);
        v12 = v7->mLegendItems.mNode.mNext;
        v13 = 12 * v6;
        v14 = (unsigned int)(v13 - 12);
        if ( (signed int)v14 >= 1 )
        {
          v4 = v14 + 1;
          do
          {
            v12 = v12->mNext;
            --v14;
          }
          while ( v14 );
        }
        for ( i = (UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *)v2->mNode.mNext; i != v2; ++v3 )
          i = (UFG::qList<UFG::LegendItemData,UFG::LegendItemData,1,0> *)i->mNode.mNext;
        for ( ; v4 <= v3; ++v4 )
        {
          if ( v4 > v13 )
            break;
          UFG::UIHKWorldMapLegendWidget::Flash_AddItem(
            &v7->Legend,
            (UFG::UIScreen *)&v7->vfptr,
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
  bool v2; // di
  Scaleform::GFx::Movie *v3; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = showCollectibles;
  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
      pargs.pObjectInterface = 0i64;
    }
    pargs.Type = 2;
    pargs.mValue.BValue = v2;
    Scaleform::GFx::Movie::Invoke(v3, "SetCollectiblesStatsVisible", 0i64, &pargs, 1u);
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 2855
// RVA: 0x5F0A00
void __fastcall UFG::UIHKScreenWorldMap::LegendTurnPage(UFG::UIHKScreenWorldMap *this)
{
  signed int v1; // edx
  UFG::UIHKScreenWorldMap *v2; // rax
  int v3; // er8
  signed int v4; // eax

  ++this->mLegendPageNumber;
  v1 = 0;
  v2 = (UFG::UIHKScreenWorldMap *)this->mLegendItems.mNode.mNext;
  v3 = 1;
  if ( v2 == (UFG::UIHKScreenWorldMap *)&this->mLegendItems )
    goto LABEL_14;
  do
  {
    v2 = (UFG::UIHKScreenWorldMap *)v2->mPrev;
    ++v1;
  }
  while ( v2 != (UFG::UIHKScreenWorldMap *)&this->mLegendItems );
  if ( v1 )
  {
    if ( v1 > 12 )
    {
      v4 = 12;
      do
      {
        v4 += 12;
        ++v3;
      }
      while ( v1 > v4 );
    }
  }
  else
  {
LABEL_14:
    v3 = 0;
  }
  if ( this->mLegendPageNumber > v3 )
    this->mLegendPageNumber = 1;
  UFG::UIHKScreenWorldMap::ShowLegend(this, this->mLegendPageNumber);
}

