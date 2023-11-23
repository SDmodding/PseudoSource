// File Line: 55
// RVA: 0x5CBB90
void __fastcall UFG::UIHKScreenOptions::~UIHKScreenOptions(UFG::UIHKScreenOptions *this)
{
  unsigned int v2; // eax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v5; // eax

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
  p_HelpBar = &v3->HelpBar;
  v5 = UFG::qStringHash32(this->mHelpBarName, 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v5);
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 64
// RVA: 0x6331D0
void __fastcall UFG::UIHKScreenOptions::init(UFG::UIHKScreenOptions *this, UFG::UICommandData *data)
{
  UFG::Controller *v3; // rcx
  UFG::UIScreenVtbl *vfptr; // rax

  UFG::UIScreen::init(this, data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  vfptr = this->vfptr;
  this->mState = STATE_BRIGHTNESS;
  (*((void (__fastcall **)(UFG::UIHKScreenOptions *))&vfptr[1].__vecDelDtor + 1))(this);
}

// File Line: 76
// RVA: 0x63E520
void __fastcall UFG::UIHKScreenOptions::update(UFG::UIHKScreenOptions *this, float elapsed)
{
  float mSavingDialogTimer; // xmm0_4

  mSavingDialogTimer = this->mSavingDialogTimer;
  if ( mSavingDialogTimer > 0.0 )
    this->mSavingDialogTimer = mSavingDialogTimer - elapsed;
  if ( this->mState == (NUM_CALIBRATION_STATES|STATE_BRIGHTNESS) && this->mSavingDialogTimer <= 0.0 )
  {
    this->mState = NUM_CALIBRATION_STATES;
    UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, 0xEB77BCB8, 0xFFFFFFFF);
  }
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 102
// RVA: 0x625E30
bool __fastcall UFG::UIHKScreenOptions::handleMessage(
        UFG::UIHKScreenOptions *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::GameSaveLoad *v6; // rax
  UFG::GameSaveLoad *v7; // rax
  UFG::GameSaveLoad *v8; // rax
  unsigned int ZeroButtonDialog; // eax
  UFG::GameSaveLoad *v10; // rax
  UFG::UIScreen *Overlay; // rax
  UFG::UIHKScreenGlobalOverlay *v12; // rcx
  Scaleform::GFx::Movie *v13; // rcx
  const char *v14; // rdx
  Scaleform::GFx::Movie *pObject; // rcx
  const char *v17; // rdx

  if ( this->mState != NUM_CALIBRATION_STATES )
  {
    if ( msgId == UI_HASH_OPTION_INTRO_COMPLETE_20 )
    {
      this->mState = STATE_VOLUME;
      return 1;
    }
    if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30
      || msgId == UI_HASH_DPAD_DOWN_REPEAT_30
      || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
      pObject = this->mRenderable->m_movie.pObject;
      if ( !pObject )
        return 1;
      v17 = "OptionList_ScrollDown";
    }
    else if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
           || msgId == UI_HASH_DPAD_UP_REPEAT_30
           || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
      pObject = this->mRenderable->m_movie.pObject;
      if ( !pObject )
        return 1;
      v17 = "OptionList_ScrollUp";
    }
    else if ( msgId == UI_HASH_DPAD_RIGHT_PRESSED_30
           || msgId == UI_HASH_DPAD_RIGHT_REPEAT_30
           || msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
      pObject = this->mRenderable->m_movie.pObject;
      if ( !pObject )
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
              ZeroButtonDialog = UFG::UIScreenDialogBox::createZeroButtonDialog(
                                   this,
                                   &customCaption,
                                   "$SAVING_POPUP_PC",
                                   0,
                                   "DialogBox");
              this->mSavingDialogTimer = 1.0;
              this->mState = NUM_CALIBRATION_STATES;
              this->mSavingDialogUID = ZeroButtonDialog;
            }
            else
            {
              UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, 0xE85D9378, 0xFFFFFFFF);
              this->mState = NUM_CALIBRATION_STATES;
            }
          }
          else if ( msgId == UI_HASH_DIALOG_NO_30 )
          {
            ((void (__fastcall *)(UFG::UIHKScreenOptions *))this->vfptr[1].handleMessage)(this);
            v10 = UFG::GameSaveLoad::Instance();
            UFG::GameSaveLoad::ApplyOptions(v10);
            ((void (__fastcall *)(UFG::UIHKScreenOptions *))this->vfptr[1].__vecDelDtor)(this);
          }
          Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "GlobalOverlay");
          if ( Overlay )
          {
            v12 = UFG::UIHKScreenGlobalOverlay::mThis;
            if ( !UFG::UIHKScreenGlobalOverlay::mThis )
              v12 = &gGlobalOverlaySentinel;
            UFG::UIHKHelpBarWidget::HandleMessage(&v12->HelpBar, Overlay, msgId, msg);
          }
          if ( msgId == UI_HASH_MOUSE_MOVE_30 )
          {
            UFG::UIHKScreenUpgrades::Flash_HandleMouseMove(
              (UFG::UIHKScreenUpgrades *)this,
              (float)SLODWORD(msg[1].vfptr),
              (float)SHIDWORD(msg[1].vfptr));
          }
          else if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
          {
            UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(
              (UFG::UIHKScreenUpgrades *)this,
              (float)SLODWORD(msg[1].vfptr),
              (float)SHIDWORD(msg[1].vfptr));
          }
          else if ( msgId == UI_HASH_MOUSE_WHEEL_SCROLL_30 )
          {
            if ( SLODWORD(msg[1].mPrev) <= 0 )
            {
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
              v13 = this->mRenderable->m_movie.pObject;
              if ( !v13 )
                goto LABEL_53;
              v14 = "OptionList_ScrollDown";
            }
            else
            {
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
              v13 = this->mRenderable->m_movie.pObject;
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
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
          UFG::UIScreenDialogBox::createYesNoDialog(this, "$OPTIONS_OPTIONS_CHANGED", "$OPTIONS_SAVE_CHANGES", 1, 1);
          this->mState = STATE_UISCALE;
          this->mOptionChanged = 0;
        }
        else
        {
          ((void (__fastcall *)(UFG::UIHKScreenOptions *))this->vfptr[1].__vecDelDtor)(this);
          this->mOptionChanged = 0;
        }
        return 1;
      }
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
      pObject = this->mRenderable->m_movie.pObject;
      if ( !pObject )
        return 1;
      v17 = "OptionList_GoLeft";
    }
    Scaleform::GFx::Movie::Invoke(pObject, v17, 0i64, 0i64, 0);
    return 1;
  }
  if ( msgId != -396520584 )
  {
    if ( msgId != -344474440 )
    {
      if ( msgId == -167642174 )
        this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
      goto LABEL_53;
    }
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mSavingDialogUID);
  }
  v6 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::LoadAllHeaders(v6);
  v7 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::ApplyOptions(v7);
  UFG::DataSynchronizer::SetOptionsDirty();
  ((void (__fastcall *)(UFG::UIHKScreenOptions *))this->vfptr[1].update)(this);
  ((void (__fastcall *)(UFG::UIHKScreenOptions *))this->vfptr[1].__vecDelDtor)(this);
LABEL_53:
  if ( msgId == UI_HASH_SAVE_OPERATION_SKIP_SAVING_9 )
    this->mSavingDialogTimer = 0.0;
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

// File Line: 310
// RVA: 0x5E9170
__int64 __fastcall UFG::UIHKScreenOptions::GetSelectedSlot(UFG::UIHKScreenOptions *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  unsigned int NValue; // ebx
  Scaleform::GFx::Value v4; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  v4.pObjectInterface = 0i64;
  v4.Type = VT_Undefined;
  Scaleform::GFx::Movie::Invoke(pObject, "OptionList_GetSelectedSlot", &v4, 0i64, 0);
  NValue = (int)v4.mValue.NValue;
  if ( (v4.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v4.pObjectInterface->vfptr->gap8[8])(
      v4.pObjectInterface,
      &v4,
      v4.mValue);
    v4.pObjectInterface = 0i64;
  }
  return NValue;
}

// File Line: 342
// RVA: 0x60E9F0
void __fastcall UFG::UIHKScreenOptions::ShowHelpBar(UFG::UIHKScreenOptions *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rsi
  unsigned int v3; // edi
  unsigned int v4; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-258h] BYREF

  v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = &gGlobalOverlaySentinel;
  p_HelpBar = &v1->HelpBar;
  v3 = UI_HASH_BUTTON_BACK_PRESSED_30;
  v4 = UFG::qStringHash32(this->mHelpBarName, 0xFFFFFFFF);
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = v4;
  *(_QWORD *)&data.priority = 0i64;
  *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
  *(_QWORD *)&data.Buttons[4] = 0i64;
  UFG::qString::Set(data.Captions, "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set(&data.Captions[1], &customCaption);
  UFG::qString::Set(&data.Captions[2], &customCaption);
  UFG::qString::Set(&data.Captions[3], &customCaption);
  UFG::qString::Set(&data.Captions[4], &customCaption);
  UFG::qString::Set(&data.Captions[5], &customCaption);
  data.MessageIds[0] = v3;
  memset(&data.MessageIds[1], 0, 20);
  UFG::UIHKHelpBarWidget::Show(p_HelpBar, &data);
  UFG::qString::~qString(&data.CustomTexturePack);
  `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 353
// RVA: 0x5ED000
void __fastcall UFG::UIHKScreenOptions::HideHelpBar(UFG::UIHKScreenOptions *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v3; // eax

  v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = &gGlobalOverlaySentinel;
  p_HelpBar = &v1->HelpBar;
  v3 = UFG::qStringHash32(this->mHelpBarName, 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v3);
}

// File Line: 359
// RVA: 0x5D7890
void __fastcall UFG::UIHKScreenOptions::Exit(UFG::UIHKScreenOptions *this)
{
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
  this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
}

// File Line: 368
// RVA: 0x5DB260
void __fastcall UFG::UIHKScreenUpgrades::Flash_HandleMouseMove(
        UFG::UIHKScreenUpgrades *this,
        float mouseX,
        float mouseY)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-88h] BYREF
  char v5[16]; // [rsp+70h] [rbp-58h] BYREF
  __int64 v6; // [rsp+80h] [rbp-48h]
  int v7; // [rsp+88h] [rbp-40h]
  double v8; // [rsp+90h] [rbp-38h]

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
    ptr.Type = VT_Number;
    ptr.mValue.NValue = mouseX;
    if ( (v7 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(v6, v5, COERCE_DOUBLE(*(_QWORD *)&v8));
      v6 = 0i64;
    }
    v7 = 5;
    v8 = mouseY;
    Scaleform::GFx::Movie::Invoke(pObject, "HandleMouseMove", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

