// File Line: 54
// RVA: 0x156ABD0
__int64 UFG::_dynamic_initializer_for__UI_HASH_CONTROL_OPTIONS_CHANGED__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("controlOptionsChanged", 0xFFFFFFFF);
  UI_HASH_CONTROL_OPTIONS_CHANGED = result;
  return result;
}

// File Line: 58
// RVA: 0x5C65B0
void __fastcall UFG::UIHKScreenOptionsController::UIHKScreenOptionsController(UFG::UIHKScreenOptionsController *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsController::`vftable';
  this->mOptionChanged = 0;
  this->mNewDrivingConfig = 0;
}

// File Line: 63
// RVA: 0x5CBD60
void __fastcall UFG::UIHKScreenOptionsController::~UIHKScreenOptionsController(UFG::UIHKScreenOptionsController *this)
{
  UFG::UIHKScreenOptionsController *v1; // rbx
  unsigned int v2; // eax
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIHKScreenGlobalOverlay *v4; // rax
  UFG::UIHKHelpBarWidget *v5; // rdi
  unsigned int v6; // eax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsController::`vftable';
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v2 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v2 == 1) )
        UFG::UI::ResetGameplayInput((UFG::UI *)this);
    }
  }
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "Options_Controllers");
  v4 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v4 = &gGlobalOverlaySentinel;
  v5 = &v4->HelpBar;
  v6 = UFG::qStringHash32("AVOPTIONS", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v5, v6);
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 73
// RVA: 0x6339D0
void __fastcall UFG::UIHKScreenOptionsController::init(UFG::UIHKScreenOptionsController *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenOptionsController *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  UFG::GameStatTracker *v4; // rax
  signed int v5; // esi
  UFG::Controller *v6; // rdx
  char ptr; // [rsp+38h] [rbp-40h]
  __int64 v8; // [rsp+48h] [rbp-30h]
  unsigned int v9; // [rsp+50h] [rbp-28h]
  double v10; // [rsp+58h] [rbp-20h]

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v3 = v2->mRenderable->m_movie.pObject;
  v4 = UFG::GameStatTracker::Instance();
  v5 = UFG::GameStatTracker::GetStat(v4, DrivingConfig);
  `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v9 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v8 + 16i64))(v8, &ptr, COERCE_DOUBLE(*(_QWORD *)&v10));
    v8 = 0i64;
  }
  v9 = 5;
  v10 = (double)v5;
  Scaleform::GFx::Movie::Invoke(v3, "OptionController_SetDrivingConfig", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  v2->mOptionChanged = 0;
  v2->mNewDrivingConfig = 0;
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v6 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v6->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v6->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  Scaleform::GFx::Movie::Invoke(v3, "OptionController_ShowX360", 0i64, 0i64, 0);
  ((void (__fastcall *)(UFG::UIHKScreenOptionsController *))v2->vfptr[1].__vecDelDtor)(v2);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0x688D286Au,
      0i64,
      0,
      0i64);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 120
// RVA: 0x627000
bool __fastcall UFG::UIHKScreenOptionsController::handleMessage(UFG::UIHKScreenOptionsController *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // ebx
  UFG::UIHKScreenOptionsController *v5; // rdi
  UFG::UIScreenRenderable *v6; // rcx
  const char *v7; // rdx
  UFG::UIScreenTextureManager *v8; // rax
  UFG::GameStatTracker *v9; // rax
  UFG::SimObjectCharacter *v10; // rax
  UFG::SimComponent *v11; // rax
  UFG::GameSaveLoad *v12; // rax
  UFG::UIScreen *v13; // rax
  UFG::UIHKScreenGlobalOverlay *v14; // rcx
  UFG::qString v16; // [rsp+38h] [rbp-30h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( msgId == UI_HASH_OPTION_INTRO_COMPLETE_20 )
    return 1;
  if ( msgId == UI_HASH_BUTTON_L1_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC415B16F,
        0i64,
        0,
        0i64);
    v6 = v5->mRenderable;
    v7 = "OptionController_ScrollPrev";
    goto LABEL_42;
  }
  if ( msgId == UI_HASH_BUTTON_R1_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC415B16F,
        0i64,
        0,
        0i64);
    v6 = v5->mRenderable;
    v7 = "OptionController_ScrollNext";
    goto LABEL_42;
  }
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
  {
    v7 = "ScrollMoveListDown";
    goto LABEL_41;
  }
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
  {
    v7 = "ScrollMoveListUp";
    goto LABEL_41;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    if ( this->mOptionChanged )
      UFG::UIScreenDialogBox::createYesNoDialog(
        (UFG::UIScreen *)&this->vfptr,
        "$OPTIONS_OPTIONS_CHANGED",
        "$OPTIONS_SAVE_CHANGES",
        1,
        1);
    else
      UFG::UIHKScreenOptionsController::Exit(this);
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_LEFT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
  {
    v7 = "OptionController_AlternateScrollPrev";
    goto LABEL_41;
  }
  if ( msgId == UI_HASH_DPAD_RIGHT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
  {
    v7 = "OptionController_AlternateScrollNext";
LABEL_41:
    v6 = this->mRenderable;
LABEL_42:
    Scaleform::GFx::Movie::Invoke(v6->m_movie.pObject, v7, 0i64, 0i64, 0);
    return 1;
  }
  if ( msgId != UI_HASH_BUTTON_SELECT_PRESSED_30 )
  {
    if ( msgId == UI_HASH_CONTROL_OPTIONS_CHANGED )
    {
      UFG::qString::qString(&v16, (UFG::qString *)&msg[1]);
      v5->mNewDrivingConfig = atol(v16.mData);
      v5->mOptionChanged = 1;
      UFG::qString::~qString(&v16);
      return 1;
    }
    if ( msgId == UI_HASH_DIALOG_YES_30 )
    {
      v9 = UFG::GameStatTracker::Instance();
      UFG::GameStatTracker::SetStat(v9, DrivingConfig, v5->mNewDrivingConfig);
      v10 = UFG::GetLocalPlayer();
      v11 = UFG::SimObject::GetComponentOfType(
              (UFG::SimObject *)&v10->vfptr,
              UFG::AICharacterControllerComponent::_TypeUID);
      UFG::SetInputMode(IM_DRIVING, (int)v11[17].m_SafePointerList.mNode.mPrev);
      v12 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::SaveGameOptions(v12);
      UFG::DataSynchronizer::SetOptionsDirty();
      this = v5;
    }
    else if ( msgId != UI_HASH_DIALOG_NO_30 )
    {
      goto LABEL_30;
    }
    UFG::UIHKScreenOptionsController::Exit(this);
    goto LABEL_30;
  }
  v8 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v8, "Options_ButtonMapping", 0i64);
LABEL_30:
  v13 = UFG::UIScreenManagerBase::getOverlay(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "GlobalOverlay");
  if ( v13 )
  {
    v14 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v14 = &gGlobalOverlaySentinel;
    UFG::UIHKHelpBarWidget::HandleMessage(&v14->HelpBar, v13, v4, v3);
  }
  if ( v4 == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
    UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(
      (UFG::UIHKScreenUpgrades *)v5,
      (float)SLODWORD(v3[1].vfptr),
      (float)SHIDWORD(v3[1].vfptr));
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
}

// File Line: 247
// RVA: 0x60EB60
void __fastcall UFG::UIHKScreenOptionsController::ShowHelpBar(UFG::UIHKScreenOptionsController *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *v2; // r14
  unsigned int v3; // ebp
  unsigned int v4; // esi
  unsigned int v5; // edi
  unsigned int v6; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-258h]

  v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = &gGlobalOverlaySentinel;
  v2 = &v1->HelpBar;
  v3 = UI_HASH_BUTTON_BACK_PRESSED_30;
  v4 = UI_HASH_BUTTON_R1_PRESSED_30;
  v5 = UI_HASH_BUTTON_SELECT_PRESSED_30;
  v6 = UFG::qStringHash32("AVOPTIONS", 0xFFFFFFFF);
  UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
  data.id = v6;
  *(_QWORD *)&data.priority = 0i64;
  _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
  *(_QWORD *)&data.Buttons[4] = 0i64;
  UFG::qString::Set(data.Captions, "$OPTION_SHOW_BUTTON_MAPPING");
  UFG::qString::Set(&data.Captions[1], "$HELPBAR_CHANGE_SECTION_UC");
  UFG::qString::Set(&data.Captions[2], "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set(&data.Captions[3], &customWorldMapCaption);
  UFG::qString::Set(&data.Captions[4], &customWorldMapCaption);
  UFG::qString::Set(&data.Captions[5], &customWorldMapCaption);
  data.MessageIds[0] = v5;
  data.MessageIds[1] = v4;
  data.MessageIds[2] = v3;
  *(_QWORD *)&data.MessageIds[3] = 0i64;
  data.MessageIds[5] = 0;
  UFG::UIHKHelpBarWidget::Show(v2, &data);
  UFG::qString::~qString(&data.CustomTexturePack);
  `eh vector destructor iterator'(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator'(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 270
// RVA: 0x5ED040
void __fastcall UFG::UIHKScreenOptionsController::HideHelpBar(UFG::UIHKScreenOptionsController *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *v2; // rbx
  unsigned int v3; // eax

  v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = &gGlobalOverlaySentinel;
  v2 = &v1->HelpBar;
  v3 = UFG::qStringHash32("AVOPTIONS", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v2, v3);
}

