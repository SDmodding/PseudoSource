// File Line: 85
// RVA: 0x5C6480
void __fastcall UFG::UIHKScreenOptionsButtonMapping::UIHKScreenOptionsButtonMapping(UFG::UIHKScreenOptionsButtonMapping *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsButtonMapping::`vftable';
  this->mOnFootActions.pObjectInterface = 0i64;
  this->mOnFootActions.Type = 0;
  this->mOnFootInputs.pObjectInterface = 0i64;
  this->mOnFootInputs.Type = 0;
  this->mDrivingActions.pObjectInterface = 0i64;
  this->mDrivingActions.Type = 0;
  this->mDrivingInputs.pObjectInterface = 0i64;
  this->mDrivingInputs.Type = 0;
  *(_DWORD *)&this->mOptionChanged = 0;
  this->mPendingRemap = 0;
}

// File Line: 91
// RVA: 0x5CBC30
void __fastcall UFG::UIHKScreenOptionsButtonMapping::~UIHKScreenOptionsButtonMapping(UFG::UIHKScreenOptionsButtonMapping *this)
{
  UFG::UIHKScreenOptionsButtonMapping *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *v4; // rdi
  unsigned int v5; // eax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsButtonMapping::`vftable';
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Options_ButtonMapping");
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  v4 = &v3->HelpBar;
  v5 = UFG::qStringHash32("BUTTON_MAPPING_SCREEN", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v4, v5);
  if ( ((unsigned int)v1->mDrivingInputs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v1->mDrivingInputs.pObjectInterface->vfptr->gap8[8])(
      v1->mDrivingInputs.pObjectInterface,
      &v1->mDrivingInputs,
      *(_QWORD *)&v1->mDrivingInputs.mValue.NValue);
    v1->mDrivingInputs.pObjectInterface = 0i64;
  }
  v1->mDrivingInputs.Type = 0;
  if ( ((unsigned int)v1->mDrivingActions.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v1->mDrivingActions.pObjectInterface->vfptr->gap8[8])(
      v1->mDrivingActions.pObjectInterface,
      &v1->mDrivingActions,
      *(_QWORD *)&v1->mDrivingActions.mValue.NValue);
    v1->mDrivingActions.pObjectInterface = 0i64;
  }
  v1->mDrivingActions.Type = 0;
  if ( ((unsigned int)v1->mOnFootInputs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v1->mOnFootInputs.pObjectInterface->vfptr->gap8[8])(
      v1->mOnFootInputs.pObjectInterface,
      &v1->mOnFootInputs,
      *(_QWORD *)&v1->mOnFootInputs.mValue.NValue);
    v1->mOnFootInputs.pObjectInterface = 0i64;
  }
  v1->mOnFootInputs.Type = 0;
  if ( ((unsigned int)v1->mOnFootActions.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&v1->mOnFootActions.pObjectInterface->vfptr->gap8[8])(
      v1->mOnFootActions.pObjectInterface,
      &v1->mOnFootActions,
      *(_QWORD *)&v1->mOnFootActions.mValue.NValue);
    v1->mOnFootActions.pObjectInterface = 0i64;
  }
  v1->mOnFootActions.Type = 0;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 98
// RVA: 0x6334E0
void __fastcall UFG::UIHKScreenOptionsButtonMapping::init(UFG::UIHKScreenOptionsButtonMapping *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenOptionsButtonMapping *v2; // r15
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *v4; // r12
  unsigned int v5; // er14
  unsigned int v6; // ebp
  unsigned int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ebx
  UFG::UIHKHelpBarData dataa; // [rsp+40h] [rbp-268h]

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  UFG::UIHKScreenOptionsButtonMapping::PopulateUCS2Array(v2);
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  v4 = &v3->HelpBar;
  v5 = UI_HASH_BUTTON_BACK_PRESSED_30;
  v6 = UI_HASH_KEYBOARD_INPUT_30;
  v7 = UI_HASH_BUTTON_R1_PRESSED_30;
  v8 = UI_HASH_BUTTON_ACCEPT_PRESSED_30;
  v9 = UFG::qStringHash32("BUTTON_MAPPING_SCREEN", 0xFFFFFFFF);
  UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
  dataa.id = v9;
  *(_QWORD *)&dataa.priority = 0i64;
  _mm_store_si128((__m128i *)dataa.Buttons, _mm_load_si128((const __m128i *)&_xmm));
  *(_QWORD *)&dataa.Buttons[4] = 0i64;
  UFG::qString::Set(dataa.Captions, "$COMMON_REMAP");
  UFG::qString::Set(&dataa.Captions[1], "$HELPBAR_CHANGE_SECTION_UC");
  UFG::qString::Set(&dataa.Captions[2], "$COMMON_RESTORE_DEFAULTS_UPPERCASE");
  UFG::qString::Set(&dataa.Captions[3], "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set(&dataa.Captions[4], &customWorldMapCaption);
  UFG::qString::Set(&dataa.Captions[5], &customWorldMapCaption);
  dataa.MessageIds[0] = v8;
  dataa.MessageIds[1] = v7;
  dataa.MessageIds[2] = v6;
  dataa.MessageIds[3] = v5;
  *(_QWORD *)&dataa.MessageIds[4] = 0i64;
  UFG::UIHKHelpBarWidget::Show(v4, &dataa);
  UFG::qString::~qString(&dataa.CustomTexturePack);
  `eh vector destructor iterator'(dataa.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator'(dataa.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0x4A3D1F6Cu,
      0i64,
      0,
      0i64);
  *(_DWORD *)&v2->mOptionChanged = 0;
  v2->mPendingRemap = 0;
  UFG::UIHKScreenOptionsButtonMapping::Bind(v2);
  UFG::UIHKScreenOptionsButtonMapping::ClearArrays(v2);
  UFG::UIHKScreenOptionsButtonMapping::PopulateOnFootArray(v2);
  UFG::UIHKScreenOptionsButtonMapping::PopulateDrivingArray(v2);
  Scaleform::GFx::Movie::Invoke(v2->mRenderable->m_movie.pObject, "OptionList_PopulateData_OnFoot", 0i64, 0i64, 0);
}

// File Line: 133
// RVA: 0x5FDAA0
void __fastcall UFG::UIHKScreenOptionsButtonMapping::PopulateUCS2Array(UFG::UIHKScreenOptionsButtonMapping *this)
{
  signed int v1; // ebx
  char v2; // cl
  char v3; // r8
  wchar_t v4; // cx
  wchar_t pwszBuff; // [rsp+40h] [rbp-118h]
  char dest; // [rsp+50h] [rbp-108h]

  if ( !UFG::UIHKScreenOptionsButtonMapping::bUCS2ArrayInitialized )
  {
    UFG::qMemSet(&dest, 0, 0x100u);
    v1 = 0;
    do
    {
      v2 = 0;
      if ( (unsigned int)(v1 - 106 + 41) <= 0x19 )
        v2 = 1;
      v3 = v2;
      if ( (unsigned int)(v1 - 106 + 58) <= 9 )
        v3 = 1;
      if ( !byte_1405FDBDC[v1 - 106] || v3 )
      {
        UFG::qMemSet(&pwszBuff, 0, 0x10u);
        if ( ToUnicodeEx((unsigned __int8)v1, 0, &dest, &pwszBuff, 7, 1u, 0i64) < 1 )
          v4 = 0;
        else
          v4 = pwszBuff;
        UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[(unsigned __int8)v1] = v4;
      }
      else
      {
        UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[(unsigned __int8)v1] = 0;
      }
      ++v1;
    }
    while ( v1 < 256 );
    UFG::UIHKScreenOptionsButtonMapping::bUCS2ArrayInitialized = 1;
  }
}

// File Line: 207
// RVA: 0x6264F0
bool __fastcall UFG::UIHKScreenOptionsButtonMapping::handleMessage(UFG::UIHKScreenOptionsButtonMapping *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbp
  unsigned int v4; // ebx
  UFG::UIHKScreenOptionsButtonMapping *v5; // rdi
  UFG::UIMessage::UIMessageType v6; // eax
  char v7; // bl
  const char *v8; // rax
  const char *v9; // rbx
  const char *v10; // rax
  char *v11; // rbx
  UFG::UIScreen *v12; // rax
  UFG *v13; // rcx
  UFG::UIHKScreenGlobalOverlay *v14; // rcx
  const char *v15; // rdx
  const char *v16; // rdx
  UFG *v17; // rcx
  UFG::GameSaveLoad *v18; // rax
  UFG::qString v20; // [rsp+48h] [rbp-60h]
  UFG::qString result; // [rsp+70h] [rbp-38h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( !this->mMapping )
  {
    if ( this->mRestoring )
    {
      if ( msgId == UI_HASH_DIALOG_YES_30 )
      {
        UFG::UIHKScreenOptionsButtonMapping::ResetKeys(this);
        v5->mOptionChanged = 1;
        v5->mRestoring = 0;
      }
      else if ( msgId == UI_HASH_DIALOG_NO_30 )
      {
        this->mRestoring = 0;
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    }
    v12 = UFG::UIScreenManagerBase::getOverlay(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            "GlobalOverlay");
    if ( v12 )
    {
      v14 = UFG::UIHKScreenGlobalOverlay::mThis;
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v14 = &gGlobalOverlaySentinel;
      UFG::UIHKHelpBarWidget::HandleMessage(&v14->HelpBar, v12, v4, v3);
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
        v15 = "OptionList_ScrollDown";
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
        v15 = "OptionList_ScrollUp";
      }
      Scaleform::GFx::Movie::Invoke(v5->mRenderable->m_movie.pObject, v15, 0i64, 0i64, 0);
    }
    if ( v4 == UI_HASH_BUTTON_L1_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xCCF5DDCu,
          0i64,
          0,
          0i64);
      v16 = "OptionController_ScrollPrev";
LABEL_91:
      Scaleform::GFx::Movie::Invoke(v5->mRenderable->m_movie.pObject, v16, 0i64, 0i64, 0);
      return 1;
    }
    if ( v4 == UI_HASH_BUTTON_R1_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xCCF5DDCu,
          0i64,
          0,
          0i64);
      v16 = "OptionController_ScrollNext";
      goto LABEL_91;
    }
    if ( v4 == UI_HASH_DPAD_DOWN_PRESSED_30 || v4 == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xC415B16F,
          0i64,
          0,
          0i64);
      v16 = "OptionList_ScrollDown";
      goto LABEL_91;
    }
    if ( v4 == UI_HASH_DPAD_UP_PRESSED_30 || v4 == UI_HASH_THUMBSTICK_LEFT_UP_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xC415B16F,
          0i64,
          0,
          0i64);
      v16 = "OptionList_ScrollUp";
      goto LABEL_91;
    }
    if ( v4 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x4A3D1F6Cu,
          0i64,
          0,
          0i64);
      Scaleform::GFx::Movie::Invoke(v5->mRenderable->m_movie.pObject, "OptionList_MapStart", 0i64, 0i64, 0);
      *(_WORD *)&v5->mMapping = 257;
      return 1;
    }
    if ( v4 == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xF343A439,
          0i64,
          0,
          0i64);
      if ( v5->mOptionChanged )
        UFG::UIScreenDialogBox::createYesNoDialog(
          (UFG::UIScreen *)&v5->vfptr,
          "$OPTIONS_OPTIONS_CHANGED",
          "$OPTIONS_SAVE_CHANGES",
          1,
          1);
      else
        UFG::UIHKScreenOptionsController::Exit((UFG::UIHKScreenOptionsController *)v5);
      return 1;
    }
    if ( v4 == UI_HASH_DIALOG_YES_30 )
    {
      UFG::UIHKScreenOptionsButtonMapping::ApplyRemap(v5);
      UFG::SaveKeyboardRemap(v17);
      v18 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::SaveGameOptions(v18);
      UFG::DataSynchronizer::SetOptionsDirty();
      UFG::UIGfxTranslator::reloadDictionary(UFG::UIScreenManager::s_instance->m_translator, 0i64);
    }
    else
    {
      if ( v4 != UI_HASH_DIALOG_NO_30 )
      {
LABEL_81:
        if ( v3->m_messageType == 2 && LOBYTE(v3[1].vfptr) == 112 )
        {
          UFG::UIScreenDialogBox::createYesNoDialog(
            (UFG::UIScreen *)&v5->vfptr,
            &customWorldMapCaption,
            "$OPTIONS_RESTORE_DEFAULTS",
            0,
            1);
          v5->mRestoring = 1;
        }
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      }
      UFG::LoadKeyboardRemap(v13);
    }
    UFG::UIHKScreenOptionsController::Exit((UFG::UIHKScreenOptionsController *)v5);
    goto LABEL_81;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xA4E5BFBD,
        0i64,
        0,
        0i64);
    Scaleform::GFx::Movie::Invoke(v5->mRenderable->m_movie.pObject, "OptionList_MapCancel", 0i64, 0i64, 0);
    v5->mMapping = 0;
    return 1;
  }
  if ( msgId == UI_HASH_DIALOG_YES_30 )
  {
    UFG::UIHKScreenOptionsButtonMapping::ExecuteRemap(this, this->mPendingRemap);
    v5->mPendingRemap = 0;
  }
  else
  {
    if ( msgId != UI_HASH_DIALOG_NO_30 )
    {
      v6 = msg->m_messageType;
      if ( v6 == 2 )
      {
        v7 = (char)msg[1].vfptr;
        if ( v7 == 13 )
        {
          if ( this->mEatEnter == 1 )
          {
            this->mEatEnter = 0;
            return 1;
          }
        }
        else if ( (unsigned __int8)(v7 - 91) <= 1u || v7 == 20 )
        {
          return 1;
        }
        if ( !v7 )
          return 1;
      }
      else
      {
        if ( v6 != 3 )
          return 1;
        if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
        {
          v7 = 1;
        }
        else if ( msgId == UI_HASH_MOUSE_BUTTON_RIGHT_PRESSED_30 )
        {
          v7 = 2;
        }
        else if ( msgId == UI_HASH_MOUSE_BUTTON_MIDDLE_PRESSED_30 )
        {
          v7 = 4;
        }
        else if ( msgId == UI_HASH_MOUSE_BUTTON_4_PRESSED_30 )
        {
          v7 = 5;
        }
        else
        {
          if ( msgId != UI_HASH_MOUSE_BUTTON_5_PRESSED_30 )
            return 1;
          v7 = 6;
        }
      }
      if ( UFG::UIHKScreenOptionsButtonMapping::IsKeyAvailable(this, v7) )
      {
        UFG::UIHKScreenOptionsButtonMapping::ExecuteRemap(v5, v7);
      }
      else
      {
        v8 = UFG::UIHKScreenOptionsButtonMapping::GetKeyActionTextToLocalize(v5, v7);
        v9 = UFG::UI::LocalizeText(v8);
        v10 = UFG::UI::LocalizeText("$OPTIONS_KEY_TAKEN_PC");
        UFG::qString::FormatEx(&result, v10, v9);
        v11 = result.mData;
        UFG::qString::qString(&v20, "$COMMON_OK_UPPERCASE");
        UFG::UIScreenDialogBox::createOneButtonDialog(
          (UFG::UIScreen *)&v5->vfptr,
          &customWorldMapCaption,
          v11,
          v20.mData,
          UI_HASH_DIALOG_OK_30,
          1,
          "DialogBox");
        UFG::qString::~qString(&v20);
        v5->mPendingRemap = 0;
        Scaleform::GFx::Movie::Invoke(v5->mRenderable->m_movie.pObject, "OptionList_MapCancel", 0i64, 0i64, 0);
        v5->mMapping = 0;
        UFG::qString::~qString(&result);
      }
      return 1;
    }
    this->mPendingRemap = 0;
  }
  return 1;
}

// File Line: 464
// RVA: 0x5D4210
void __fastcall UFG::UIHKScreenOptionsButtonMapping::Bind(UFG::UIHKScreenOptionsButtonMapping *this)
{
  UFG::UIHKScreenOptionsButtonMapping *v1; // rdi
  Scaleform::GFx::Movie *v2; // rbx

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::GetVariable(v2, &this->mOnFootActions, "gOnFootActions");
  Scaleform::GFx::Movie::GetVariable(v2, &v1->mOnFootInputs, "gOnFootInputs");
  Scaleform::GFx::Movie::GetVariable(v2, &v1->mDrivingActions, "gDrivingActions");
  Scaleform::GFx::Movie::GetVariable(v2, &v1->mDrivingInputs, "gDrivingInputs");
}

// File Line: 476
// RVA: 0x5D5670
void __fastcall UFG::UIHKScreenOptionsButtonMapping::ClearArrays(UFG::UIHKScreenOptionsButtonMapping *this)
{
  UFG::UIHKScreenOptionsButtonMapping *v1; // rbx

  v1 = this;
  this->mOnFootActions.pObjectInterface->vfptr->RemoveElements(
    this->mOnFootActions.pObjectInterface,
    *(void **)&this->mOnFootActions.mValue.NValue,
    0,
    -1);
  v1->mOnFootInputs.pObjectInterface->vfptr->RemoveElements(
    v1->mOnFootInputs.pObjectInterface,
    v1->mOnFootInputs.mValue.pStringManaged,
    0,
    -1);
  v1->mDrivingActions.pObjectInterface->vfptr->RemoveElements(
    v1->mDrivingActions.pObjectInterface,
    v1->mDrivingActions.mValue.pStringManaged,
    0,
    -1);
  v1->mDrivingInputs.pObjectInterface->vfptr->RemoveElements(
    v1->mDrivingInputs.pObjectInterface,
    v1->mDrivingInputs.mValue.pStringManaged,
    0,
    -1);
}

// File Line: 493
// RVA: 0x5F9B50
void __fastcall UFG::UIHKScreenOptionsButtonMapping::PopulateOnFootArray(UFG::UIHKScreenOptionsButtonMapping *this)
{
  UFG::UIHKScreenOptionsButtonMapping *v1; // rdi
  unsigned int *v2; // rsi
  const char **v3; // r14
  signed __int64 v4; // r15
  __int64 v5; // rax
  int v6; // eax
  char v7; // bl
  unsigned int v8; // ST10_4
  __int64 v9; // [rsp+8h] [rbp-79h]
  __int64 v10; // [rsp+18h] [rbp-69h]
  char v11; // [rsp+20h] [rbp-61h]
  char v12; // [rsp+28h] [rbp-59h]
  __int64 v13; // [rsp+38h] [rbp-49h]
  unsigned int v14; // [rsp+40h] [rbp-41h]
  char *v15; // [rsp+48h] [rbp-39h]
  char v16; // [rsp+58h] [rbp-29h]
  __int64 v17; // [rsp+68h] [rbp-19h]
  unsigned int v18; // [rsp+70h] [rbp-11h]
  __int64 v19; // [rsp+78h] [rbp-9h]
  __int64 v20; // [rsp+88h] [rbp+7h]
  UFG::qString keyName; // [rsp+90h] [rbp+Fh]
  unsigned __int16 v22; // [rsp+F0h] [rbp+6Fh]
  __int16 v23; // [rsp+F2h] [rbp+71h]

  v20 = -2i64;
  v1 = this;
  v2 = (unsigned int *)OnFootRemapIds_0;
  v3 = UFG::OnFootActions;
  v4 = 14i64;
  do
  {
    v5 = (__int64)*v3;
    v17 = 0i64;
    v18 = 6;
    v19 = v5;
    v1->mOnFootActions.pObjectInterface->vfptr->PushBack(
      v1->mOnFootActions.pObjectInterface,
      v1->mOnFootActions.mValue.pStringManaged,
      (Scaleform::GFx::Value *)&v16);
    if ( (v18 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v17 + 16i64))(v17, &v16, v19);
      v17 = 0i64;
    }
    v18 = 0;
    v6 = UFG::UIHKScreenOptionsButtonMapping::GetKey(*v2);
    v7 = v6;
    if ( UFG::UIHKScreenOptionsButtonMapping::bUCS2ArrayInitialized
      && UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[v6] )
    {
      v22 = UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[v6];
      v23 = 0;
      v1->mOnFootInputs.pObjectInterface->vfptr->PushBack(
        v1->mOnFootInputs.pObjectInterface,
        v1->mOnFootInputs.mValue.pStringManaged,
        (Scaleform::GFx::Value *)&v11);
      if ( (v8 >> 6) & 1 )
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v9 + 16i64))(v9, &v11, v10);
    }
    else
    {
      UFG::qString::qString(&keyName);
      UFG::KeyToKeyName(&keyName, v7);
      v13 = 0i64;
      v14 = 6;
      v15 = keyName.mData;
      v1->mOnFootInputs.pObjectInterface->vfptr->PushBack(
        v1->mOnFootInputs.pObjectInterface,
        v1->mOnFootInputs.mValue.pStringManaged,
        (Scaleform::GFx::Value *)&v12);
      if ( (v14 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v13 + 16i64))(v13, &v12, v15);
        v13 = 0i64;
      }
      v14 = 0;
      UFG::qString::~qString(&keyName);
    }
    ++v3;
    ++v2;
    --v4;
  }
  while ( v4 );
}

// File Line: 521
// RVA: 0x5F64E0
void __fastcall UFG::UIHKScreenOptionsButtonMapping::PopulateDrivingArray(UFG::UIHKScreenOptionsButtonMapping *this)
{
  UFG::UIHKScreenOptionsButtonMapping *v1; // rdi
  unsigned int *v2; // rsi
  const char **v3; // r14
  signed __int64 v4; // r15
  __int64 v5; // rax
  int v6; // eax
  char v7; // bl
  char v8; // [rsp+20h] [rbp-B8h]
  __int64 v9; // [rsp+30h] [rbp-A8h]
  unsigned int v10; // [rsp+38h] [rbp-A0h]
  unsigned __int16 *v11; // [rsp+40h] [rbp-98h]
  char v12; // [rsp+50h] [rbp-88h]
  char v13; // [rsp+58h] [rbp-80h]
  __int64 v14; // [rsp+60h] [rbp-78h]
  __int64 v15; // [rsp+68h] [rbp-70h]
  char *v16; // [rsp+70h] [rbp-68h]
  __int64 v17; // [rsp+78h] [rbp-60h]
  __int64 v18; // [rsp+88h] [rbp-50h]
  UFG::qString keyName; // [rsp+90h] [rbp-48h]
  UFG::qString v20; // [rsp+B8h] [rbp-20h]
  __int64 v21; // [rsp+E0h] [rbp+8h]
  unsigned __int16 v22; // [rsp+120h] [rbp+48h]
  __int16 v23; // [rsp+122h] [rbp+4Ah]

  v18 = -2i64;
  v1 = this;
  UFG::qString::qString((UFG::qString *)&v21);
  v2 = (unsigned int *)DrivingRemapIds_0;
  v3 = UFG::DrivingActions;
  v4 = 13i64;
  do
  {
    v5 = (__int64)*v3;
    v15 = 0i64;
    LODWORD(v16) = 6;
    v17 = v5;
    v1->mDrivingActions.pObjectInterface->vfptr->PushBack(
      v1->mDrivingActions.pObjectInterface,
      v1->mDrivingActions.mValue.pStringManaged,
      (Scaleform::GFx::Value *)&v13);
    if ( ((unsigned int)v16 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, &v13, v17);
      v15 = 0i64;
    }
    LODWORD(v16) = 0;
    v6 = UFG::UIHKScreenOptionsButtonMapping::GetKey(*v2);
    v7 = v6;
    if ( UFG::UIHKScreenOptionsButtonMapping::bUCS2ArrayInitialized
      && UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[v6] )
    {
      v22 = UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[v6];
      v23 = 0;
      v9 = 0i64;
      v10 = 0;
      v10 = 7;
      v11 = &v22;
      v1->mDrivingInputs.pObjectInterface->vfptr->PushBack(
        v1->mDrivingInputs.pObjectInterface,
        v1->mDrivingInputs.mValue.pStringManaged,
        (Scaleform::GFx::Value *)&v8);
      if ( (v10 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, unsigned __int16 *))(*(_QWORD *)v9 + 16i64))(v9, &v8, v11);
        v9 = 0i64;
      }
      v10 = 0;
    }
    else
    {
      UFG::qString::qString(&keyName);
      UFG::KeyToKeyName(&keyName, v7);
      v14 = 0i64;
      LODWORD(v15) = 6;
      v16 = keyName.mData;
      v1->mDrivingInputs.pObjectInterface->vfptr->PushBack(
        v1->mDrivingInputs.pObjectInterface,
        v1->mDrivingInputs.mValue.pStringManaged,
        (Scaleform::GFx::Value *)&v12);
      if ( ((unsigned int)v15 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v14 + 16i64))(v14, &v12, v16);
        v14 = 0i64;
      }
      LODWORD(v15) = 0;
      UFG::qString::~qString(&keyName);
    }
    ++v3;
    ++v2;
    --v4;
  }
  while ( v4 );
  UFG::qString::~qString(&v20);
}

// File Line: 570
// RVA: 0x5D7A00
void __fastcall UFG::UIHKScreenOptionsController::Exit(UFG::UIHKScreenOptionsController *this)
{
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xA4E5BFBD,
      0i64,
      0,
      0i64);
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xFFFFFFFF);
}

// File Line: 577
// RVA: 0x5EE340
char __fastcall UFG::UIHKScreenOptionsButtonMapping::IsKeyAvailable(UFG::UIHKScreenOptionsButtonMapping *this, char key)
{
  char v2; // r15
  UFG::UIHKScreenOptionsButtonMapping *v3; // rdi
  const unsigned int *v4; // rsi
  bool v5; // al
  unsigned int v6; // ebx
  BOOL v7; // ebp
  unsigned int v8; // er14
  unsigned int v9; // ebp
  unsigned int v10; // edi

  v2 = key;
  v3 = this;
  v4 = DrivingRemapIds_0;
  v5 = (unsigned int)UFG::UIHKScreenOptionsButtonMapping::GetSelectedTab(this) == 0;
  if ( v5 )
    v4 = OnFootRemapIds_0;
  v6 = 0;
  v7 = v5 != 0;
  v8 = v4[(unsigned int)UFG::UIHKScreenOptionsButtonMapping::GetSelectedIndex(v3)];
  v9 = v7 + 13;
  if ( !v9 )
    return 1;
  while ( 1 )
  {
    v10 = *v4;
    if ( (unsigned __int8)UFG::UIHKScreenOptionsButtonMapping::GetKey(*v4) == v2 && v10 != v8 )
      break;
    ++v6;
    ++v4;
    if ( v6 >= v9 )
      return 1;
  }
  return 0;
}

// File Line: 598
// RVA: 0x5E8010
const char *__fastcall UFG::UIHKScreenOptionsButtonMapping::GetKeyActionTextToLocalize(UFG::UIHKScreenOptionsButtonMapping *this, char key)
{
  int v2; // ebp
  const unsigned int *v3; // r14
  bool v4; // r15
  int v5; // edi
  __int64 v6; // rbx
  int v7; // eax
  __int64 v8; // rsi
  const char *result; // rax

  LOBYTE(v2) = key;
  v3 = DrivingRemapIds_0;
  v4 = UFG::UIHKScreenOptionsButtonMapping::GetSelectedTab(this) == 0;
  if ( v4 )
    v3 = OnFootRemapIds_0;
  v5 = 0;
  v6 = 0i64;
  v7 = (v4 != 0) + 13;
  v8 = v7;
  if ( v7 <= 0 )
    return " ";
  v2 = (unsigned __int8)v2;
  while ( (unsigned int)UFG::UIHKScreenOptionsButtonMapping::GetKey(v3[v6]) != v2 )
  {
    ++v6;
    ++v5;
    if ( v6 >= v8 )
      return " ";
  }
  if ( v4 )
    result = UFG::OnFootActions[v5];
  else
    result = UFG::DrivingActions[v5];
  return result;
}

// File Line: 614
// RVA: 0x602940
void __fastcall UFG::UIHKScreenOptionsButtonMapping::ResetKeys(UFG::UIHKScreenOptionsButtonMapping *this)
{
  unsigned int v1; // edx
  UFG::UIHKScreenOptionsButtonMapping *v2; // rbx
  UFG::Controller **v3; // rax
  UFG::Controller *v4; // rcx

  v1 = 0;
  v2 = this;
  v3 = UFG::gInputSystem->mControllers;
  while ( 1 )
  {
    v4 = *v3;
    if ( *v3 )
    {
      if ( v4->m_IsKeyboardController )
        break;
    }
    ++v1;
    ++v3;
    if ( v1 >= 5 )
    {
      v4 = 0i64;
      break;
    }
  }
  UFG::Controller::ResetRemapList(v4);
  UFG::UIHKScreenOptionsButtonMapping::ClearArrays(v2);
  UFG::UIHKScreenOptionsButtonMapping::PopulateOnFootArray(v2);
  UFG::UIHKScreenOptionsButtonMapping::PopulateDrivingArray(v2);
  Scaleform::GFx::Movie::Invoke(v2->mRenderable->m_movie.pObject, "OptionList_Refresh", 0i64, 0i64, 0);
}

// File Line: 624
// RVA: 0x5D7620
void __fastcall UFG::UIHKScreenOptionsButtonMapping::ExecuteRemap(UFG::UIHKScreenOptionsButtonMapping *this, char key)
{
  unsigned __int8 v2; // di
  UFG::UIHKScreenOptionsButtonMapping *v3; // rsi
  unsigned __int16 v4; // bx
  long double v5; // rbx
  UFG::UIScreenRenderable *v6; // rax
  UFG::AudioEventExternalSourceInfo *externalSourceInfo; // [rsp+20h] [rbp-11h]
  double v8; // [rsp+38h] [rbp+7h]
  Scaleform::GFx::Value pargs; // [rsp+48h] [rbp+17h]
  unsigned __int16 vars0; // [rsp+A0h] [rbp+6Fh]
  __int16 vars2; // [rsp+A2h] [rbp+71h]

  v2 = key;
  v3 = this;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0x4A3D1F6Cu,
      0i64,
      0,
      0i64);
  if ( UFG::UIHKScreenOptionsButtonMapping::bUCS2ArrayInitialized )
    v4 = UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[v2];
  else
    v4 = 0;
  UFG::qString::qString((UFG::qString *)&externalSourceInfo);
  UFG::KeyToKeyName((UFG::qString *)&externalSourceInfo, v2);
  pargs.pObjectInterface = 0i64;
  pargs.Type = 0;
  if ( v4 )
  {
    vars0 = v4;
    vars2 = 0;
    pargs.Type = 7;
    *(_QWORD *)&pargs.mValue.NValue = &vars0;
  }
  else
  {
    v5 = v8;
    pargs.Type = 6;
    pargs.mValue.NValue = v5;
  }
  v6 = v3->mRenderable;
  LODWORD(externalSourceInfo) = 1;
  Scaleform::GFx::Movie::Invoke(v6->m_movie.pObject, "OptionList_MapSet", 0i64, &pargs, 1u);
  UFG::UIHKScreenOptionsButtonMapping::SaveKey(v3, v2);
  *(_WORD *)&v3->mOptionChanged = 1;
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 0;
  UFG::qString::~qString((UFG::qString *)&externalSourceInfo);
}

// File Line: 653
// RVA: 0x603830
bool __fastcall UFG::UIHKScreenOptionsButtonMapping::SaveKey(UFG::UIHKScreenOptionsButtonMapping *this, unsigned int key)
{
  unsigned int v2; // edi
  UFG::UIHKScreenOptionsButtonMapping *v3; // rsi
  unsigned int v4; // ebx
  bool v5; // bp
  unsigned int v7; // eax
  int v8; // eax
  unsigned int v9; // ebp
  unsigned int v10; // ebx
  unsigned int v11; // er8
  unsigned int v12; // edx
  int v13; // eax
  unsigned int v14; // eax

  v2 = key;
  v3 = this;
  if ( (unsigned int)UFG::UIHKScreenOptionsButtonMapping::GetSelectedTab(this) )
  {
    v8 = UFG::UIHKScreenOptionsButtonMapping::GetSelectedIndex(v3);
    v9 = REMAP_ID_STEER_R_2;
    v10 = DrivingRemapIds_0[v8];
    if ( v10 != REMAP_ID_STEER_L_2 && v10 != REMAP_ID_STEER_R_2 )
    {
      v11 = v2;
      v12 = DrivingRemapIds_0[v8];
      return UFG::UIHKScreenOptionsButtonMapping::SaveKey(v3, v12, v11);
    }
    v13 = UFG::UIHKScreenOptionsButtonMapping::GetKey(REMAP_ID_STEER_2);
    if ( v10 == v9 )
    {
      v14 = v13 & 0xFFFF00FF;
      v2 <<= 8;
    }
    else
    {
      if ( v10 != REMAP_ID_STEER_L_2 )
      {
LABEL_19:
        v12 = REMAP_ID_STEER_2;
        v11 = v13;
        return UFG::UIHKScreenOptionsButtonMapping::SaveKey(v3, v12, v11);
      }
      v14 = v13 & 0xFFFFFF00;
    }
    v13 = v2 + v14;
    goto LABEL_19;
  }
  v4 = OnFootRemapIds_0[(unsigned int)UFG::UIHKScreenOptionsButtonMapping::GetSelectedIndex(v3)];
  if ( v4 != REMAP_ID_MOVE_F_2 && v4 != REMAP_ID_MOVE_B_2 && v4 != REMAP_ID_MOVE_L_2 && v4 != REMAP_ID_MOVE_R_2 )
  {
    v5 = UFG::UIHKScreenOptionsButtonMapping::SaveKey(v3, v4, v2);
    if ( v4 == REMAP_ID_FIRE_2 )
      return v5 & UFG::UIHKScreenOptionsButtonMapping::SaveKey(v3, REMAP_ID_ATTACK_2, v2);
    return v5;
  }
  v7 = UFG::UIHKScreenOptionsButtonMapping::PackMoveButton(v4, v2);
  v5 = UFG::UIHKScreenOptionsButtonMapping::SaveKey(v3, REMAP_ID_MOVE_2, v7);
  if ( v4 != REMAP_ID_MOVE_F_2 )
    return v5;
  return v5 & UFG::UIHKScreenOptionsButtonMapping::SaveKey(v3, REMAP_ID_FORWARD_KEY_2, v2);
}

// File Line: 698
// RVA: 0x603980
char __fastcall UFG::UIHKScreenOptionsButtonMapping::SaveKey(UFG::UIHKScreenOptionsButtonMapping *this, unsigned int remapId, unsigned int key)
{
  unsigned int v3; // ecx
  UFG::Controller **v4; // r9
  UFG::Controller *v5; // rax
  signed __int64 v6; // rcx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v7; // rax

  v3 = 0;
  v4 = UFG::gInputSystem->mControllers;
  while ( 1 )
  {
    v5 = *v4;
    if ( *v4 )
    {
      if ( v5->m_IsKeyboardController )
        break;
    }
    ++v3;
    ++v4;
    if ( v3 >= 5 )
    {
      v5 = 0i64;
      break;
    }
  }
  v6 = (signed __int64)&v5->mRemappableActions;
  v7 = v5->mRemappableActions.mNode.mNext;
  if ( v7 == (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)v6 )
    return 0;
  while ( LODWORD(v7[2].mNext) != remapId )
  {
    v7 = v7->mNext;
    if ( v7 == (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)v6 )
      return 0;
  }
  LODWORD(v7[3].mPrev) = key;
  return 1;
}

// File Line: 723
// RVA: 0x5D46A0
__int64 __fastcall UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(UFG::UI::eButtons button, UFG::UI::RemapContext ctx)
{
  bool v2; // dl
  __int64 result; // rax

  v2 = ctx == 0;
  switch ( button )
  {
    case 1:
      result = REMAP_ID_ACTIONHIJACK_2;
      if ( v2 )
        result = REMAP_ID_FREERUN_2;
      break;
    case 2:
    case 28:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_GRAPPLE_2;
      break;
    case 3:
    case 10:
    case 29:
    case 34:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_FIRE_2;
      break;
    case 4:
    case 30:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_ACTION_2;
      break;
    case 7:
    case 31:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_COVERTOGGLE_2;
      break;
    case 8:
    case 32:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_RELOAD_2;
      break;
    case 9:
    case 33:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_AIM_2;
      break;
    case 12:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_WEAPON_SPECIAL_2;
      break;
    case 27:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_FREERUN_2;
      break;
    default:
      result = REMAP_ID_INVALID_2;
      break;
  }
  return result;
}

// File Line: 755
// RVA: 0x5D3CF0
void __fastcall UFG::UIHKScreenOptionsButtonMapping::ApplyRemap(UFG::UIHKScreenOptionsButtonMapping *this)
{
  unsigned int v1; // edx
  UFG::Controller **v2; // rax
  UFG::Controller *v3; // rcx

  v1 = 0;
  v2 = UFG::gInputSystem->mControllers;
  while ( 1 )
  {
    v3 = *v2;
    if ( *v2 )
    {
      if ( v3->m_IsKeyboardController )
        break;
    }
    ++v1;
    ++v2;
    if ( v1 >= 5 )
    {
      v3 = 0i64;
      break;
    }
  }
  UFG::Controller::ApplyRemapList(v3);
}

// File Line: 769
// RVA: 0x5F3880
__int64 __fastcall UFG::UIHKScreenOptionsButtonMapping::PackMoveButton(unsigned int remapId, unsigned int dirButton)
{
  unsigned int v2; // edi
  unsigned int v3; // ebx
  __int64 result; // rax

  v2 = remapId;
  v3 = dirButton;
  result = UFG::UIHKScreenOptionsButtonMapping::GetKey(REMAP_ID_MOVE_2);
  if ( v2 == REMAP_ID_MOVE_F_2 )
    return (v3 << 24) + (result & 0xFFFFFF);
  if ( v2 == REMAP_ID_MOVE_B_2 )
    return (v3 << 16) + (result & 0xFF00FFFF);
  if ( v2 == REMAP_ID_MOVE_R_2 )
    return (v3 << 8) + (result & 0xFFFF00FF);
  if ( v2 == REMAP_ID_MOVE_L_2 )
    result = v3 + (result & 0xFFFFFF00);
  return result;
}

// File Line: 867
// RVA: 0x5E7EF0
__int64 __fastcall UFG::UIHKScreenOptionsButtonMapping::GetKey(unsigned int remapId)
{
  unsigned int v1; // er10
  unsigned int v2; // edx
  UFG::Controller **v3; // r8
  unsigned int v4; // er9
  UFG::Controller *v5; // rax
  signed __int64 v6; // r8
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v7; // rax
  __int64 result; // rax
  bool v9; // zf

  v1 = remapId;
  if ( remapId == REMAP_ID_MOVE_F_2
    || remapId == REMAP_ID_MOVE_B_2
    || remapId == REMAP_ID_MOVE_L_2
    || remapId == REMAP_ID_MOVE_R_2 )
  {
    v1 = REMAP_ID_MOVE_2;
  }
  else if ( remapId == REMAP_ID_STEER_L_2 || remapId == REMAP_ID_STEER_R_2 )
  {
    v1 = REMAP_ID_STEER_2;
  }
  v2 = 0;
  v3 = UFG::gInputSystem->mControllers;
  v4 = 0;
  while ( 1 )
  {
    v5 = *v3;
    if ( *v3 )
    {
      if ( v5->m_IsKeyboardController )
        break;
    }
    ++v4;
    ++v3;
    if ( v4 >= 5 )
    {
      v5 = 0i64;
      break;
    }
  }
  v6 = (signed __int64)&v5->mRemappableActions;
  v7 = v5->mRemappableActions.mNode.mNext;
  if ( v7 == (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)v6 )
    return v2;
  while ( LODWORD(v7[2].mNext) != v1 )
  {
    v7 = v7->mNext;
    if ( v7 == (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)v6 )
      return 0i64;
  }
  result = LODWORD(v7[3].mPrev);
  if ( remapId == REMAP_ID_MOVE_F_2 )
    return (unsigned int)result >> 24;
  if ( remapId == REMAP_ID_MOVE_B_2 || remapId == REMAP_ID_MOVE_L_2 || remapId == REMAP_ID_MOVE_R_2 )
  {
    if ( remapId != REMAP_ID_MOVE_F_2 )
    {
      if ( remapId == REMAP_ID_MOVE_B_2 )
        return BYTE2(result);
      if ( remapId != REMAP_ID_MOVE_R_2 )
      {
        v9 = remapId == REMAP_ID_MOVE_L_2;
LABEL_33:
        if ( v9 )
          v2 = (unsigned __int8)result;
        return v2;
      }
      return BYTE1(result);
    }
    return (unsigned int)result >> 24;
  }
  if ( remapId == REMAP_ID_STEER_L_2 || remapId == REMAP_ID_STEER_R_2 )
  {
    if ( remapId != REMAP_ID_STEER_R_2 )
    {
      v9 = remapId == REMAP_ID_STEER_L_2;
      goto LABEL_33;
    }
    return BYTE1(result);
  }
  return result;
}

// File Line: 920
// RVA: 0x5E9290
__int64 __fastcall UFG::UIHKScreenOptionsButtonMapping::GetSelectedTab(UFG::UIHKScreenOptionsButtonMapping *this)
{
  Scaleform::GFx::Movie *v1; // rcx
  double v2; // xmm6_8
  __int64 result; // rax
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-50h]

  v1 = this->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = 133;
  pval.mValue.NValue = 0.0;
  Scaleform::GFx::Movie::GetVariable(v1, &pval, "gSelectedTab");
  if ( (pval.Type & 0x8F) == 5 )
  {
    v2 = pval.mValue.NValue;
    if ( ((unsigned int)pval.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
      pval.pObjectInterface = 0i64;
    }
    result = (unsigned int)(signed int)v2;
  }
  else
  {
    if ( ((unsigned int)pval.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
      pval.pObjectInterface = 0i64;
    }
    result = (unsigned int)(signed int)0.0;
  }
  return result;
}

// File Line: 928
// RVA: 0x5E8ED0
__int64 __fastcall UFG::UIHKScreenOptionsButtonMapping::GetSelectedIndex(UFG::UIHKScreenOptionsButtonMapping *this)
{
  Scaleform::GFx::Movie *v1; // rcx
  double v2; // xmm6_8
  __int64 result; // rax
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-50h]

  v1 = this->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = 133;
  pval.mValue.NValue = 0.0;
  Scaleform::GFx::Movie::GetVariable(v1, &pval, "gSelectedIndex");
  if ( (pval.Type & 0x8F) == 5 )
  {
    v2 = pval.mValue.NValue;
    if ( ((unsigned int)pval.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
      pval.pObjectInterface = 0i64;
    }
    result = (unsigned int)(signed int)v2;
  }
  else
  {
    if ( ((unsigned int)pval.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
      pval.pObjectInterface = 0i64;
    }
    result = (unsigned int)(signed int)0.0;
  }
  return result;
}

