// File Line: 45
// RVA: 0x5C74F0
void __fastcall UFG::UIHKScreenSpyCam::UIHKScreenSpyCam(UFG::UIHKScreenSpyCam *this)
{
  UFG::ScriptCameraComponent *ComponentOfType; // rdi
  UFG::qSymbol *v3; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF

  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  ComponentOfType = 0i64;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable;
  *(_QWORD *)&this->mfAlphaValue = 1109393408i64;
  ++UFG::UIHKMinigameScreen::mNumMinigameScreens;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSpyCam::`vftable;
  *(_WORD *)&this->mbControlsAllowed = 0;
  *(_WORD *)&this->mUpdateHelpbar = 0;
  v3 = UFG::qSymbol::create_from_string(&result, "SurveillanceCamera");
  this->mVisualTreatmentIndex = TracksEnum<unsigned long>::GetEnumFromSymbol(&gVisualTreatmentEnum, v3);
  m_pSimObject = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( m_pSimObject )
    ComponentOfType = (UFG::ScriptCameraComponent *)UFG::SimObject::GetComponentOfType(
                                                      m_pSimObject,
                                                      UFG::ScriptCameraComponent::_TypeUID);
  this->pSCC = ComponentOfType;
}

// File Line: 60
// RVA: 0x5CC9F0
void __fastcall UFG::UIHKScreenSpyCam::~UIHKScreenSpyCam(UFG::UIHKScreenSpyCam *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v5; // eax
  UFG::UIScreen *Screen; // rax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSpyCam::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "SpyCam");
  UFG::RenderWorld::VisualTreatmentPostEffect_StopAllVisualTreatments();
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  p_HelpBar = &v3->HelpBar;
  v5 = UFG::qStringHash32("UIHKScreenSpyCam", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v5);
  Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "SpyPC");
  if ( Screen )
  {
    LODWORD(Screen[1].mPrev) = 2;
    Screen->mRenderable->m_shouldRender = 1;
  }
  v7 = UFG::TiDo::CalcWwiseUid("unmute_rain");
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v7, 0i64, 0, 0i64);
  v8 = UFG::TiDo::CalcWwiseUid("stop_camera_zoom_in_loop");
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v8, 0i64, 0, 0i64);
  v9 = UFG::TiDo::CalcWwiseUid("stop_camera_zoom_out_loop");
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v9, 0i64, 0, 0i64);
  v10 = UFG::TiDo::CalcWwiseUid("Stop_spycam_servo");
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v10, 0i64, 0, 0i64);
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen(this);
}

// File Line: 86
// RVA: 0x6365F0
void __fastcall UFG::UIHKScreenSpyCam::init(UFG::UIHKScreenSpyCam *this, UFG::UICommandData *data)
{
  UFG::UIScreen *Screen; // rax
  UFG::UIScreen *v4; // rax
  UFG::UIHKMissionProgressWidget *v5; // rax

  UFG::UIScreen::init(this, data);
  Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "SpyPC");
  if ( Screen )
    Screen->mRenderable->m_shouldRender = 0;
  v4 = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "SpyPC");
  if ( v4 )
    this->mbTriadSensitive = v4[1].m_screenName[0];
  v5 = UFG::UIHKScreenHud::MissionProgress;
  UFG::UIHKScreenHud::MissionProgress->mChanged = 1;
  v5->mData[0].Changed = 1;
  v5->mData[1].Changed = 1;
  v5->mData[2].Changed = 1;
  v5->mData[3].Changed = 1;
  if ( UFG::UIHKScreenGlobalOverlay::mThis
    && UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-408i64 )
  {
    UFG::UIHK_NISOverlay::HideElement(
      &UFG::UIHKScreenGlobalOverlay::mThis->NISOverlay,
      UFG::UIHKScreenGlobalOverlay::mThis,
      &UFG::UIHK_NISOverlay::m_curtains,
      1.0,
      0);
  }
  UFG::UIHK_NISOverlay::UpdateAudioMuteState();
}

// File Line: 110
// RVA: 0x63FFD0
void __fastcall UFG::UIHKScreenSpyCam::update(UFG::UIHKScreenSpyCam *this, float elapsed)
{
  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") )
  {
    this->mUpdateHelpbar = 1;
  }
  else
  {
    if ( this->mUpdateHelpbar )
      this->mUpdateHelpbar = 0;
    UFG::RenderWorld::VisualTreatmentPostEffect_StartVisualTreatment(this->mVisualTreatmentIndex, 0, 0);
    UFG::UIScreen::update(this, elapsed);
    UFG::UIHKMissionProgressWidget::Update(UFG::UIHKScreenHud::MissionProgress, this);
  }
}

// File Line: 131
// RVA: 0x62C2A0
bool __fastcall UFG::UIHKScreenSpyCam::handleMessage(
        UFG::UIHKScreenSpyCam *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::ScriptCameraComponent *pSCC; // rcx
  SSClass *v7; // rax
  SSInstance *v8; // rbx
  ASymbol *v9; // rax
  Scaleform::GFx::Movie *pObject; // rcx
  unsigned int v11; // eax
  unsigned int v12; // eax
  UFG::UIHKScreenGlobalOverlay *v13; // rbx
  UFG::UIHKScreenGlobalOverlay *v14; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // r15
  unsigned int v16; // eax
  UFG::UIHKHelpBarWidget *v17; // r14
  unsigned int v18; // ebx
  unsigned int v19; // eax
  SSInstance *args_pp[3]; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qString v22; // [rsp+58h] [rbp-A8h] BYREF
  UFG::UIHKHelpBarData data; // [rsp+80h] [rbp-80h] BYREF
  ASymbol result; // [rsp+310h] [rbp+210h] BYREF
  ASymbol sym; // [rsp+318h] [rbp+218h] BYREF

  args_pp[2] = (SSInstance *)-2i64;
  if ( this->mbControlsAllowed )
  {
    if ( msgId != UI_HASH_BUTTON_BACK_PRESSED_30 || this->mbTriadSensitive )
    {
      if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 || msgId == UI_HASH_MOUSE_BUTTON_LEFT_RELEASED_30 )
      {
        pSCC = this->pSCC;
        if ( pSCC )
        {
          if ( pSCC->mbHighlightOn && !this->mbArrestMade )
          {
            sym.i_uid = UFG::ScriptCameraComponent::getHighlightedCharacter(pSCC)->m_Name.mUID;
            args_pp[0] = SSSymbol::as_instance(&sym);
            args_pp[1] = SSBoolean::pool_new(this->mbTriadSensitive);
            v7 = SSBrain::get_class("SpyPC");
            if ( LODWORD(v7[1].vfptr) )
              v8 = **(SSInstance ***)&v7[1].i_name.i_uid;
            else
              v8 = 0i64;
            v9 = ASymbol::create(&result, "_initiate_arrest", 0xFFFFFFFF, ATerm_long);
            SSInstance::coroutine_call(v8, v9, args_pp, 2u, 1, 0.0, 0i64, 0i64);
            this->mbArrestMade = 1;
            UFG::ScriptCameraComponent::DisableProfiling(this->pSCC);
            pObject = this->mRenderable->m_movie.pObject;
            if ( pObject )
              Scaleform::GFx::Movie::Invoke(pObject, "arrest", 0i64, &customCaption);
            v11 = UFG::TiDo::CalcWwiseUid("play_sp_camera_nav");
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v11, 0i64, 0, 0i64);
            v12 = UFG::TiDo::CalcWwiseUid("play_sp_arrest_dlg");
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v12, 0i64, 0, 0i64);
            v13 = &gGlobalOverlaySentinel;
            v14 = UFG::UIHKScreenGlobalOverlay::mThis;
            if ( !UFG::UIHKScreenGlobalOverlay::mThis )
              v14 = &gGlobalOverlaySentinel;
            p_HelpBar = &v14->HelpBar;
            v16 = UFG::qStringHash32("UIHKScreenSpyCam", 0xFFFFFFFF);
            UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v16);
            if ( UFG::UIHKScreenGlobalOverlay::mThis )
              v13 = UFG::UIHKScreenGlobalOverlay::mThis;
            v17 = &v13->HelpBar;
            v18 = UFG::qStringHash32("UIHKScreenSpyCam", 0xFFFFFFFF);
            UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
            data.id = v18;
            data.priority = PRIORITY_THREE;
            data.alignment = ALIGN_RIGHT;
            *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
            *(_QWORD *)&data.Buttons[4] = 0i64;
            UFG::qString::Set(data.Captions, "$MINIGAME_SPYCAM_MOVE");
            UFG::qString::Set(&data.Captions[1], "$COMMON_ZOOM_UPPERCASE");
            UFG::qString::Set(&data.Captions[2], &customCaption);
            UFG::qString::Set(&data.Captions[3], &customCaption);
            UFG::qString::Set(&data.Captions[4], &customCaption);
            UFG::qString::Set(&data.Captions[5], &customCaption);
            memset(data.MessageIds, 0, sizeof(data.MessageIds));
            UFG::UIHKHelpBarWidget::Show(v17, &data);
            UFG::qString::~qString(&data.CustomTexturePack);
            `eh vector destructor iterator(
              data.Icons,
              0x28ui64,
              6,
              (void (__fastcall *)(void *))UFG::qString::~qString);
            `eh vector destructor iterator(
              data.Captions,
              0x28ui64,
              6,
              (void (__fastcall *)(void *))UFG::qString::~qString);
          }
        }
      }
    }
    else
    {
      UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
    }
  }
  if ( msgId != UI_HASH_PLAYSOUND_20 )
    return UFG::UIHKMinigameScreen::handleMessage(this, msgId, msg);
  UFG::qString::qString(&v22, (UFG::qString *)&msg[1]);
  v19 = UFG::TiDo::CalcWwiseUid(v22.mData);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v19, 0i64, 0, 0i64);
  UFG::qString::~qString(&v22);
  return 1;
}

// File Line: 200
// RVA: 0x63B3A0
void __fastcall UFG::UIHKScreenSpyCam::stopLoadingLoop(UFG::UIHKScreenSpyCam *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  int v3; // ecx
  __int64 v4; // rax
  __int64 v5; // rdi
  unsigned __int64 v6; // rbx
  int v7; // ecx
  __int64 v8; // rax
  __int64 v9; // rdi
  unsigned __int64 v10; // rbx
  int v11; // ecx
  __int64 v12; // rax
  __int64 v13; // rdi
  unsigned __int64 v14; // rbx
  int v15; // ecx
  __int64 v16; // rax
  __int64 v17; // rdi
  unsigned __int64 v18; // rbx
  UFG::UIHKScreenGlobalOverlay *v19; // rax
  Scaleform::GFx::Value value; // [rsp+20h] [rbp-D8h] BYREF
  __int64 v21; // [rsp+50h] [rbp-A8h]
  UFG::UIHKHelpBarData data; // [rsp+60h] [rbp-98h] BYREF

  v21 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = VT_Boolean;
  value.mValue.BValue = 0;
  if ( pObject )
    Scaleform::GFx::Movie::SetVariable(pObject, "mc_Load._visible", &value, 1i64);
  this->mbControlsAllowed = 1;
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = UFG::qStringHash32("UIHKScreenSpyCam", 0xFFFFFFFF);
  data.priority = PRIORITY_THREE;
  data.alignment = ALIGN_RIGHT;
  v3 = 0;
  v4 = 0i64;
  while ( data.Buttons[v4] )
  {
    ++v3;
    if ( ++v4 >= 6 )
      goto LABEL_8;
  }
  v5 = v3;
  data.Buttons[v5] = R_STICK_BUTTON;
  v6 = 40i64 * v3;
  UFG::qString::Set((UFG::qString *)&data.Buttons[v6 / 4 + 4], "$MINIGAME_SPYCAM_MOVE");
  UFG::qString::Set((UFG::qString *)&data.Captions[v6 / 0x28 + 5].mStringHash32, &customCaption);
  data.MessageIds[v5 - 2] = 0;
LABEL_8:
  v7 = 0;
  v8 = 0i64;
  while ( data.Buttons[v8] )
  {
    ++v7;
    if ( ++v8 >= 6 )
      goto LABEL_13;
  }
  v9 = v7;
  data.Buttons[v9] = L2R2_BUTTON;
  v10 = 40i64 * v7;
  UFG::qString::Set((UFG::qString *)&data.Buttons[v10 / 4 + 4], "$COMMON_ZOOM_UPPERCASE");
  UFG::qString::Set((UFG::qString *)&data.Captions[v10 / 0x28 + 5].mStringHash32, &customCaption);
  data.MessageIds[v9 - 2] = 0;
LABEL_13:
  v11 = 0;
  v12 = 0i64;
  while ( data.Buttons[v12] )
  {
    ++v11;
    if ( ++v12 >= 6 )
      goto LABEL_18;
  }
  v13 = v11;
  data.Buttons[v13] = ACCEPT_BUTTON;
  v14 = 40i64 * v11;
  UFG::qString::Set((UFG::qString *)&data.Buttons[v14 / 4 + 4], "$MINIGAME_SPYCAM_ARREST");
  UFG::qString::Set((UFG::qString *)&data.Captions[v14 / 0x28 + 5].mStringHash32, &customCaption);
  data.MessageIds[v13 - 2] = 0;
LABEL_18:
  if ( !this->mbTriadSensitive )
  {
    v15 = 0;
    v16 = 0i64;
    while ( data.Buttons[v16] )
    {
      ++v15;
      if ( ++v16 >= 6 )
        goto LABEL_24;
    }
    v17 = v15;
    data.Buttons[v17] = BACK_BUTTON;
    v18 = 40i64 * v15;
    UFG::qString::Set((UFG::qString *)&data.Buttons[v18 / 4 + 4], "$COMMON_EXIT");
    UFG::qString::Set((UFG::qString *)&data.Captions[v18 / 0x28 + 5].mStringHash32, &customCaption);
    data.MessageIds[v17 - 2] = 0;
  }
LABEL_24:
  v19 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v19 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v19->HelpBar, &data);
  UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
  `eh vector destructor iterator(
    &data.Captions[5].mStringHash32,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(&data.Buttons[4], 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  if ( (value.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
}

// File Line: 234
// RVA: 0x61F220
void __fastcall UFG::UIHKScreenSpyCam::cancelTriadSensitive(UFG::UIHKScreenSpyCam *this)
{
  this->mbTriadSensitive = 0;
}

