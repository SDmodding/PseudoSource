// File Line: 45
// RVA: 0x5C74F0
void __fastcall UFG::UIHKScreenSpyCam::UIHKScreenSpyCam(UFG::UIHKScreenSpyCam *this)
{
  UFG::UIHKScreenSpyCam *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  UFG::SimComponent *v3; // rdi
  UFG::qSymbol *v4; // rax
  UFG::SimObject *v5; // rcx
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable';
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable';
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable';
  *(_QWORD *)&this->mfAlphaValue = 1109393408i64;
  ++UFG::UIHKMinigameScreen::mNumMinigameScreens;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSpyCam::`vftable';
  *(_WORD *)&this->mbControlsAllowed = 0;
  *(_WORD *)&this->mUpdateHelpbar = 0;
  v4 = UFG::qSymbol::create_from_string(&result, "SurveillanceCamera");
  v1->mVisualTreatmentIndex = TracksEnum<unsigned long>::GetEnumFromSymbol(&gVisualTreatmentEnum, v4);
  v5 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
  if ( v5 )
    v3 = UFG::SimObject::GetComponentOfType(v5, UFG::ScriptCameraComponent::_TypeUID);
  v1->pSCC = (UFG::ScriptCameraComponent *)v3;
}

// File Line: 60
// RVA: 0x5CC9F0
void __fastcall UFG::UIHKScreenSpyCam::~UIHKScreenSpyCam(UFG::UIHKScreenSpyCam *this)
{
  UFG::UIHKScreenSpyCam *v1; // rdi
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *v4; // rbx
  unsigned int v5; // eax
  UFG::UIScreen *v6; // rax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenSpyCam::`vftable';
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "SpyCam");
  UFG::RenderWorld::VisualTreatmentPostEffect_StopAllVisualTreatments();
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  v4 = &v3->HelpBar;
  v5 = UFG::qStringHash32("UIHKScreenSpyCam", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v4, v5);
  v6 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "SpyPC");
  if ( v6 )
  {
    LODWORD(v6[1].mPrev) = 2;
    v6->mRenderable->m_shouldRender = 1;
  }
  v7 = UFG::TiDo::CalcWwiseUid("unmute_rain");
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v7, 0i64, 0, 0i64);
  v8 = UFG::TiDo::CalcWwiseUid("stop_camera_zoom_in_loop");
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v8, 0i64, 0, 0i64);
  v9 = UFG::TiDo::CalcWwiseUid("stop_camera_zoom_out_loop");
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v9, 0i64, 0, 0i64);
  v10 = UFG::TiDo::CalcWwiseUid("Stop_spycam_servo");
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v10, 0i64, 0, 0i64);
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen((UFG::UIHKMinigameScreen *)&v1->vfptr);
}

// File Line: 86
// RVA: 0x6365F0
void __fastcall UFG::UIHKScreenSpyCam::init(UFG::UIHKScreenSpyCam *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenSpyCam *v2; // rbx
  UFG::UIScreen *v3; // rax
  UFG::UIScreen *v4; // rax
  UFG::UIHKMissionProgressWidget *v5; // rax

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v3 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "SpyPC");
  if ( v3 )
    v3->mRenderable->m_shouldRender = 0;
  v4 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "SpyPC");
  if ( v4 )
    v2->mbTriadSensitive = v4[1].m_screenName[0];
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
      (UFG::UIScreen *)&UFG::UIHKScreenGlobalOverlay::mThis->vfptr,
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
  UFG::UIHKScreenSpyCam *v2; // rbx

  v2 = this;
  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "NISPause") )
  {
    v2->mUpdateHelpbar = 1;
  }
  else
  {
    if ( v2->mUpdateHelpbar == 1 )
      v2->mUpdateHelpbar = 0;
    UFG::RenderWorld::VisualTreatmentPostEffect_StartVisualTreatment(v2->mVisualTreatmentIndex, 0, 0);
    UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
    UFG::UIHKMissionProgressWidget::Update(UFG::UIHKScreenHud::MissionProgress, (UFG::UIScreen *)&v2->vfptr);
  }
}

// File Line: 131
// RVA: 0x62C2A0
bool __fastcall UFG::UIHKScreenSpyCam::handleMessage(UFG::UIHKScreenSpyCam *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r13
  unsigned int v4; // esi
  UFG::UIHKScreenSpyCam *v5; // rdi
  UFG::ScriptCameraComponent *v6; // rcx
  SSClass *v7; // rax
  SSInstance *v8; // rbx
  ASymbol *v9; // rax
  Scaleform::GFx::Movie *v10; // rcx
  unsigned int v11; // eax
  unsigned int v12; // eax
  UFG::UIHKScreenGlobalOverlay *v13; // rbx
  UFG::UIHKScreenGlobalOverlay *v14; // rax
  UFG::UIHKHelpBarWidget *v15; // r15
  unsigned int v16; // eax
  UFG::UIHKHelpBarWidget *v17; // r14
  unsigned int v18; // ebx
  unsigned int v19; // eax
  SSInstance *args_pp; // [rsp+40h] [rbp-C0h]
  SSBoolean *v22; // [rsp+48h] [rbp-B8h]
  __int64 v23; // [rsp+50h] [rbp-B0h]
  UFG::qString v24; // [rsp+58h] [rbp-A8h]
  UFG::UIHKHelpBarData data; // [rsp+80h] [rbp-80h]
  ASymbol result; // [rsp+310h] [rbp+210h]
  ASymbol sym; // [rsp+318h] [rbp+218h]

  v23 = -2i64;
  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( this->mbControlsAllowed )
  {
    if ( msgId != UI_HASH_BUTTON_BACK_PRESSED_30 || this->mbTriadSensitive )
    {
      if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 || msgId == UI_HASH_MOUSE_BUTTON_LEFT_RELEASED_30 )
      {
        v6 = this->pSCC;
        if ( v6 )
        {
          if ( v6->mbHighlightOn && !v5->mbArrestMade )
          {
            sym.i_uid = UFG::ScriptCameraComponent::getHighlightedCharacter(v6)->m_Name.mUID;
            args_pp = SSSymbol::as_instance(&sym);
            v22 = SSBoolean::pool_new(v5->mbTriadSensitive);
            v7 = SSBrain::get_class("SpyPC");
            if ( LODWORD(v7[1].vfptr) )
              v8 = **(SSInstance ***)&v7[1].i_name.i_uid;
            else
              v8 = 0i64;
            v9 = ASymbol::create(&result, "_initiate_arrest", 0xFFFFFFFF, ATerm_long);
            SSInstance::coroutine_call(v8, v9, &args_pp, 2u, 1, 0.0, 0i64, 0i64);
            v5->mbArrestMade = 1;
            UFG::ScriptCameraComponent::DisableProfiling(v5->pSCC);
            v10 = v5->mRenderable->m_movie.pObject;
            if ( v10 )
              Scaleform::GFx::Movie::Invoke(v10, "arrest", 0i64, &customWorldMapCaption);
            v11 = UFG::TiDo::CalcWwiseUid("play_sp_camera_nav");
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                v11,
                0i64,
                0,
                0i64);
            v12 = UFG::TiDo::CalcWwiseUid("play_sp_arrest_dlg");
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                v12,
                0i64,
                0,
                0i64);
            v13 = &gGlobalOverlaySentinel;
            v14 = UFG::UIHKScreenGlobalOverlay::mThis;
            if ( !UFG::UIHKScreenGlobalOverlay::mThis )
              v14 = &gGlobalOverlaySentinel;
            v15 = &v14->HelpBar;
            v16 = UFG::qStringHash32("UIHKScreenSpyCam", 0xFFFFFFFF);
            UFG::UIHKHelpBarWidget::Hide(v15, v16);
            if ( UFG::UIHKScreenGlobalOverlay::mThis )
              v13 = UFG::UIHKScreenGlobalOverlay::mThis;
            v17 = &v13->HelpBar;
            v18 = UFG::qStringHash32("UIHKScreenSpyCam", 0xFFFFFFFF);
            UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
            data.id = v18;
            data.priority = 2;
            data.alignment = 1;
            _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
            *(_QWORD *)&data.Buttons[4] = 0i64;
            UFG::qString::Set(data.Captions, "$MINIGAME_SPYCAM_MOVE");
            UFG::qString::Set(&data.Captions[1], "$COMMON_ZOOM_UPPERCASE");
            UFG::qString::Set(&data.Captions[2], &customWorldMapCaption);
            UFG::qString::Set(&data.Captions[3], &customWorldMapCaption);
            UFG::qString::Set(&data.Captions[4], &customWorldMapCaption);
            UFG::qString::Set(&data.Captions[5], &customWorldMapCaption);
            *(_QWORD *)data.MessageIds = 0i64;
            *(_QWORD *)&data.MessageIds[2] = 0i64;
            *(_QWORD *)&data.MessageIds[4] = 0i64;
            UFG::UIHKHelpBarWidget::Show(v17, &data);
            UFG::qString::~qString(&data.CustomTexturePack);
            `eh vector destructor iterator'(
              data.Icons,
              0x28ui64,
              6,
              (void (__fastcall *)(void *))UFG::qString::~qString);
            `eh vector destructor iterator'(
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
      UFG::UIScreenManagerBase::queuePopScreen(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        0xFFFFFFFF);
    }
  }
  if ( v4 != UI_HASH_PLAYSOUND_20 )
    return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
  UFG::qString::qString(&v24, (UFG::qString *)&v3[1]);
  v19 = UFG::TiDo::CalcWwiseUid(v24.mData);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v19, 0i64, 0, 0i64);
  UFG::qString::~qString(&v24);
  return 1;
}

// File Line: 200
// RVA: 0x63B3A0
void __fastcall UFG::UIHKScreenSpyCam::stopLoadingLoop(UFG::UIHKScreenSpyCam *this)
{
  UFG::UIHKScreenSpyCam *v1; // rsi
  Scaleform::GFx::Movie *v2; // rbx
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
  Scaleform::GFx::Value value; // [rsp+20h] [rbp-D8h]
  __int64 v21; // [rsp+50h] [rbp-A8h]
  UFG::UIHKHelpBarData data; // [rsp+60h] [rbp-98h]

  v21 = -2i64;
  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = 2;
  value.mValue.BValue = 0;
  if ( v2 )
    Scaleform::GFx::Movie::SetVariable(v2, "mc_Load._visible", &value, 1i64);
  v1->mbControlsAllowed = 1;
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = UFG::qStringHash32("UIHKScreenSpyCam", 0xFFFFFFFF);
  data.priority = 2;
  data.alignment = 1;
  v3 = 0;
  v4 = 0i64;
  while ( data.Buttons[v4] )
  {
    ++v3;
    if ( ++v4 >= 6 )
      goto LABEL_8;
  }
  v5 = v3;
  data.Buttons[v5] = 22;
  v6 = 40i64 * v3;
  UFG::qString::Set((UFG::qString *)&data.Buttons[v6 / 4 + 4], "$MINIGAME_SPYCAM_MOVE");
  UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v6 / 0x28 + 5] + 32), &customWorldMapCaption);
  *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v5 * 4) = 0;
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
  data.Buttons[v9] = 14;
  v10 = 40i64 * v7;
  UFG::qString::Set((UFG::qString *)&data.Buttons[v10 / 4 + 4], "$COMMON_ZOOM_UPPERCASE");
  UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v10 / 0x28 + 5] + 32), &customWorldMapCaption);
  *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v9 * 4) = 0;
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
  data.Buttons[v13] = 1;
  v14 = 40i64 * v11;
  UFG::qString::Set((UFG::qString *)&data.Buttons[v14 / 4 + 4], "$MINIGAME_SPYCAM_ARREST");
  UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v14 / 0x28 + 5] + 32), &customWorldMapCaption);
  *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v13 * 4) = 0;
LABEL_18:
  if ( !v1->mbTriadSensitive )
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
    data.Buttons[v17] = 2;
    v18 = 40i64 * v15;
    UFG::qString::Set((UFG::qString *)&data.Buttons[v18 / 4 + 4], "$COMMON_EXIT");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[v18 / 0x28 + 5] + 32), &customWorldMapCaption);
    *(unsigned int *)((char *)&data.Icons[5].mStringHash32 + v17 * 4) = 0;
  }
LABEL_24:
  v19 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v19 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v19->HelpBar, &data);
  UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
  `eh vector destructor iterator'(
    &data.Captions[5].mStringHash32,
    0x28ui64,
    6,
    (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator'(&data.Buttons[4], 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  if ( ((unsigned int)value.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
}

// File Line: 234
// RVA: 0x61F220
void __fastcall UFG::UIHKScreenSpyCam::cancelTriadSensitive(UFG::UIHKScreenSpyCam *this)
{
  this->mbTriadSensitive = 0;
}

