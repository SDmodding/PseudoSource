// File Line: 55
// RVA: 0x5CBB90
void __fastcall UFG::UIHKScreenOptions::~UIHKScreenOptions(UFG::UIHKScreenOptions *this)
{
  UFG::UIHKScreenOptions *v1; // rbx
  unsigned int v2; // eax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *v4; // rdi
  unsigned int v5; // eax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptions::`vftable;
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v2 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v2 == 1) )
        UFG::UI::ResetGameplayInput((UFG::UI *)this);
    }
  }
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  v4 = &v3->HelpBar;
  v5 = UFG::qStringHash32(v1->mHelpBarName, 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v4, v5);
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 64
// RVA: 0x6331D0
void __fastcall UFG::UIHKScreenOptions::init(UFG::UIHKScreenOptions *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenOptions *v2; // rbx
  UFG::Controller *v3; // rcx
  UFG::UIScreenVtbl *v4; // rax

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
  v4 = v2->vfptr;
  v2->mState = 1;
  (*((void (__fastcall **)(UFG::UIHKScreenOptions *))&v4[1].__vecDelDtor + 1))(v2);
}

// File Line: 76
// RVA: 0x63E520
void __fastcall UFG::UIHKScreenOptions::update(UFG::UIHKScreenOptions *this, float elapsed)
{
  float v2; // xmm0_4
  UFG::UIHKScreenOptions *v3; // rbx

  v2 = this->mSavingDialogTimer;
  v3 = this;
  if ( v2 > 0.0 )
    this->mSavingDialogTimer = v2 - elapsed;
  if ( this->mState == 5 && this->mSavingDialogTimer <= 0.0 )
  {
    this->mState = 4;
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xEB77BCB8,
      0xFFFFFFFF);
  }
  UFG::UIScreen::update((UFG::UIScreen *)&v3->vfptr, elapsed);
}

// File Line: 102
// RVA: 0x625E30
bool __fastcall UFG::UIHKScreenOptions::handleMessage(UFG::UIHKScreenOptions *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbp
  unsigned int v4; // ebx
  UFG::UIHKScreenOptions *v5; // rdi
  UFG::GameSaveLoad *v6; // rax
  UFG::GameSaveLoad *v7; // rax
  UFG::GameSaveLoad *v8; // rax
  unsigned int v9; // eax
  UFG::GameSaveLoad *v10; // rax
  UFG::UIScreen *v11; // rax
  UFG::UIHKScreenGlobalOverlay *v12; // rcx
  Scaleform::GFx::Movie *v13; // rcx
  const char *v14; // rdx
  Scaleform::GFx::Movie *v16; // rcx
  const char *v17; // rdx

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( this->mState != 4 )
  {
    if ( msgId == UI_HASH_OPTION_INTRO_COMPLETE_20 )
    {
      this->mState = 2;
      return 1;
    }
    if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30
      || msgId == UI_HASH_DPAD_DOWN_REPEAT_30
      || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xEDB4A8C7,
          0i64,
          0,
          0i64);
      v16 = v5->mRenderable->m_movie.pObject;
      if ( !v16 )
        return 1;
      v17 = "OptionList_ScrollDown";
    }
    else if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
           || msgId == UI_HASH_DPAD_UP_REPEAT_30
           || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xEDB4A8C7,
          0i64,
          0,
          0i64);
      v16 = v5->mRenderable->m_movie.pObject;
      if ( !v16 )
        return 1;
      v17 = "OptionList_ScrollUp";
    }
    else if ( msgId == UI_HASH_DPAD_RIGHT_PRESSED_30
           || msgId == UI_HASH_DPAD_RIGHT_REPEAT_30
           || msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xEDB4A8C7,
          0i64,
          0,
          0i64);
      v16 = v5->mRenderable->m_movie.pObject;
      if ( !v16 )
        return 1;
      v17 = "OptionList_GoRight";
    }
    else
    {
      if ( msgId != UI_HASH_DPAD_LEFT_PRESSED_30
        && msgId != UI_HASH_DPAD_LEFT_REPEAT_30
        && msgId != UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
      {
        if ( msgId != UI_HASH_BUTTON_BACK_PRESSED_30 )
        {
          if ( msgId == UI_HASH_DIALOG_YES_30 )
          {
            UFG::HDDmanager::mInstance->m_eSaveLoadPermission |= 2u;
            v8 = UFG::GameSaveLoad::Instance();
            if ( UFG::GameSaveLoad::SaveGameOptions(v8) )
            {
              v9 = UFG::UIScreenDialogBox::createZeroButtonDialog(
                     (UFG::UIScreen *)&v5->vfptr,
                     &customWorldMapCaption,
                     "$SAVING_POPUP_PC",
                     0,
                     "DialogBox");
              v5->mSavingDialogTimer = 1.0;
              v5->mState = 4;
              v5->mSavingDialogUID = v9;
            }
            else
            {
              UFG::UIScreenManagerBase::queueMessage(
                (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                0xE85D9378,
                0xFFFFFFFF);
              v5->mState = 4;
            }
          }
          else if ( msgId == UI_HASH_DIALOG_NO_30 )
          {
            ((void (*)(void))this->vfptr[1].handleMessage)();
            v10 = UFG::GameSaveLoad::Instance();
            UFG::GameSaveLoad::ApplyOptions(v10);
            ((void (__fastcall *)(UFG::UIHKScreenOptions *))v5->vfptr[1].__vecDelDtor)(v5);
          }
          v11 = UFG::UIScreenManagerBase::getOverlay(
                  (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                  "GlobalOverlay");
          if ( v11 )
          {
            v12 = UFG::UIHKScreenGlobalOverlay::mThis;
            if ( !UFG::UIHKScreenGlobalOverlay::mThis )
              v12 = &gGlobalOverlaySentinel;
            UFG::UIHKHelpBarWidget::HandleMessage(&v12->HelpBar, v11, v4, v3);
          }
          if ( v4 == UI_HASH_MOUSE_MOVE_30 )
          {
            UFG::UIHKScreenUpgrades::Flash_HandleMouseMove(
              (UFG::UIHKScreenUpgrades *)v5,
              (float)SLODWORD(v3[1].vfptr),
              (float)SHIDWORD(v3[1].vfptr));
          }
          else if ( v4 == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
          {
            UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(
              (UFG::UIHKScreenUpgrades *)v5,
              (float)SLODWORD(v3[1].vfptr),
              (float)SHIDWORD(v3[1].vfptr));
          }
          else if ( v4 == UI_HASH_MOUSE_WHEEL_SCROLL_30 )
          {
            if ( SLODWORD(v3[1].mPrev) <= 0 )
            {
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(
                  (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                  0xEDB4A8C7,
                  0i64,
                  0,
                  0i64);
              v13 = v5->mRenderable->m_movie.pObject;
              if ( !v13 )
                goto LABEL_53;
              v14 = "OptionList_ScrollDown";
            }
            else
            {
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(
                  (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                  0xEDB4A8C7,
                  0i64,
                  0,
                  0i64);
              v13 = v5->mRenderable->m_movie.pObject;
              if ( !v13 )
                goto LABEL_53;
              v14 = "OptionList_ScrollUp";
            }
            Scaleform::GFx::Movie::Invoke(v13, v14, 0i64, 0i64, 0);
          }
          goto LABEL_53;
        }
        if ( this->mOptionChanged )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0xA4E5BFBD,
              0i64,
              0,
              0i64);
          UFG::UIScreenDialogBox::createYesNoDialog(
            (UFG::UIScreen *)&v5->vfptr,
            "$OPTIONS_OPTIONS_CHANGED",
            "$OPTIONS_SAVE_CHANGES",
            1,
            1);
          v5->mState = 3;
          v5->mOptionChanged = 0;
        }
        else
        {
          ((void (*)(void))this->vfptr[1].__vecDelDtor)();
          v5->mOptionChanged = 0;
        }
        return 1;
      }
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xEDB4A8C7,
          0i64,
          0,
          0i64);
      v16 = v5->mRenderable->m_movie.pObject;
      if ( !v16 )
        return 1;
      v17 = "OptionList_GoLeft";
    }
    Scaleform::GFx::Movie::Invoke(v16, v17, 0i64, 0i64, 0);
    return 1;
  }
  if ( msgId != -396520584 )
  {
    if ( msgId != -344474440 )
    {
      if ( msgId == -167642174 )
        this->mState = 5;
      goto LABEL_53;
    }
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      this->mSavingDialogUID);
  }
  v6 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::LoadAllHeaders(v6);
  v7 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::ApplyOptions(v7);
  UFG::DataSynchronizer::SetOptionsDirty();
  ((void (__fastcall *)(UFG::UIHKScreenOptions *))v5->vfptr[1].update)(v5);
  ((void (__fastcall *)(UFG::UIHKScreenOptions *))v5->vfptr[1].__vecDelDtor)(v5);
LABEL_53:
  if ( v4 == UI_HASH_SAVE_OPERATION_SKIP_SAVING_9 )
    v5->mSavingDialogTimer = 0.0;
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
})
    v5->mSavingDialogTimer = 0.0;
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
}

// File Line: 310
// RVA: 0x5E9170
__int64 __fastcall UFG::UIHKScreenOptions::GetSelectedSlot(UFG::UIHKScreenOptions *this)
{
  Scaleform::GFx::Movie *v1; // rcx
  unsigned int v2; // ebx
  char v4; // [rsp+38h] [rbp-40h]
  __int64 v5; // [rsp+48h] [rbp-30h]
  unsigned int v6; // [rsp+50h] [rbp-28h]
  double v7; // [rsp+58h] [rbp-20h]

  v1 = this->mRenderable->m_movie.pObject;
  v5 = 0i64;
  v6 = 0;
  Scaleform::GFx::Movie::Invoke(v1, "OptionList_GetSelectedSlot", (Scaleform::GFx::Value *)&v4, 0i64, 0);
  v2 = (signed int)v7;
  if ( (v6 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v5 + 16i64))(v5, &v4, COERCE_DOUBLE(*(_QWORD *)&v7));
    v5 = 0i64;
  }
  return v2;
}

// File Line: 342
// RVA: 0x60E9F0
void __fastcall UFG::UIHKScreenOptions::ShowHelpBar(UFG::UIHKScreenOptions *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *v2; // rsi
  unsigned int v3; // edi
  unsigned int v4; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-258h]

  v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = &gGlobalOverlaySentinel;
  v2 = &v1->HelpBar;
  v3 = UI_HASH_BUTTON_BACK_PRESSED_30;
  v4 = UFG::qStringHash32(this->mHelpBarName, 0xFFFFFFFF);
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = v4;
  *(_QWORD *)&data.priority = 0i64;
  _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
  *(_QWORD *)&data.Buttons[4] = 0i64;
  UFG::qString::Set(data.Captions, "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set(&data.Captions[1], &customWorldMapCaption);
  UFG::qString::Set(&data.Captions[2], &customWorldMapCaption);
  UFG::qString::Set(&data.Captions[3], &customWorldMapCaption);
  UFG::qString::Set(&data.Captions[4], &customWorldMapCaption);
  UFG::qString::Set(&data.Captions[5], &customWorldMapCaption);
  data.MessageIds[0] = v3;
  *(_QWORD *)&data.MessageIds[1] = 0i64;
  *(_QWORD *)&data.MessageIds[3] = 0i64;
  data.MessageIds[5] = 0;
  UFG::UIHKHelpBarWidget::Show(v2, &data);
  UFG::qString::~qString(&data.CustomTexturePack);
  `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 353
// RVA: 0x5ED000
void __fastcall UFG::UIHKScreenOptions::HideHelpBar(UFG::UIHKScreenOptions *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *v2; // rbx
  unsigned int v3; // eax

  v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = &gGlobalOverlaySentinel;
  v2 = &v1->HelpBar;
  v3 = UFG::qStringHash32(this->mHelpBarName, 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v2, v3);
}

// File Line: 359
// RVA: 0x5D7890
void __fastcall UFG::UIHKScreenOptions::Exit(UFG::UIHKScreenOptions *this)
{
  UFG::UIHKScreenOptions *v1; // rbx

  v1 = this;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xA4E5BFBD,
      0i64,
      0,
      0i64);
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    v1->mScreenUID);
  v1->mState = 6;
}

// File Line: 368
// RVA: 0x5DB260
void __fastcall UFG::UIHKScreenUpgrades::Flash_HandleMouseMove(UFG::UIHKScreenUpgrades *this, float mouseX, float mouseY)
{
  Scaleform::GFx::Movie *v3; // rbx
  char ptr; // [rsp+40h] [rbp-88h]
  __int64 v5; // [rsp+50h] [rbp-78h]
  unsigned int v6; // [rsp+58h] [rbp-70h]
  double v7; // [rsp+60h] [rbp-68h]
  char v8; // [rsp+70h] [rbp-58h]
  __int64 v9; // [rsp+80h] [rbp-48h]
  unsigned int v10; // [rsp+88h] [rbp-40h]
  double v11; // [rsp+90h] [rbp-38h]

  v3 = this->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v6 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v5 + 16i64))(v5, &ptr, COERCE_DOUBLE(*(_QWORD *)&v7));
      v5 = 0i64;
    }
    v6 = 5;
    v7 = mouseX;
    if ( (v10 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v9 + 16i64))(v9, &v8, COERCE_DOUBLE(*(_QWORD *)&v11));
      v9 = 0i64;
    }
    v10 = 5;
    v11 = mouseY;
    Scaleform::GFx::Movie::Invoke(v3, "HandleMouseMove", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

