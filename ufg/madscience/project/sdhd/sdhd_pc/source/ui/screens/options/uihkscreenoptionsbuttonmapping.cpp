// File Line: 85
// RVA: 0x5C6480
void __fastcall UFG::UIHKScreenOptionsButtonMapping::UIHKScreenOptionsButtonMapping(
        UFG::UIHKScreenOptionsButtonMapping *this)
{
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsButtonMapping::`vftable;
  this->mOnFootActions.pObjectInterface = 0i64;
  this->mOnFootActions.Type = VT_Undefined;
  this->mOnFootInputs.pObjectInterface = 0i64;
  this->mOnFootInputs.Type = VT_Undefined;
  this->mDrivingActions.pObjectInterface = 0i64;
  this->mDrivingActions.Type = VT_Undefined;
  this->mDrivingInputs.pObjectInterface = 0i64;
  this->mDrivingInputs.Type = VT_Undefined;
  *(_DWORD *)&this->mOptionChanged = 0;
  this->mPendingRemap = 0;
}

// File Line: 91
// RVA: 0x5CBC30
void __fastcall UFG::UIHKScreenOptionsButtonMapping::~UIHKScreenOptionsButtonMapping(
        UFG::UIHKScreenOptionsButtonMapping *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v5; // eax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenOptionsButtonMapping::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Options_ButtonMapping");
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  p_HelpBar = &v3->HelpBar;
  v5 = UFG::qStringHash32("BUTTON_MAPPING_SCREEN", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v5);
  if ( (this->mDrivingInputs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&this->mDrivingInputs.pObjectInterface->vfptr->gap8[8])(
      this->mDrivingInputs.pObjectInterface,
      &this->mDrivingInputs,
      this->mDrivingInputs.mValue);
    this->mDrivingInputs.pObjectInterface = 0i64;
  }
  this->mDrivingInputs.Type = VT_Undefined;
  if ( (this->mDrivingActions.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&this->mDrivingActions.pObjectInterface->vfptr->gap8[8])(
      this->mDrivingActions.pObjectInterface,
      &this->mDrivingActions,
      this->mDrivingActions.mValue);
    this->mDrivingActions.pObjectInterface = 0i64;
  }
  this->mDrivingActions.Type = VT_Undefined;
  if ( (this->mOnFootInputs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&this->mOnFootInputs.pObjectInterface->vfptr->gap8[8])(
      this->mOnFootInputs.pObjectInterface,
      &this->mOnFootInputs,
      this->mOnFootInputs.mValue);
    this->mOnFootInputs.pObjectInterface = 0i64;
  }
  this->mOnFootInputs.Type = VT_Undefined;
  if ( (this->mOnFootActions.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&this->mOnFootActions.pObjectInterface->vfptr->gap8[8])(
      this->mOnFootActions.pObjectInterface,
      &this->mOnFootActions,
      this->mOnFootActions.mValue);
    this->mOnFootActions.pObjectInterface = 0i64;
  }
  this->mOnFootActions.Type = VT_Undefined;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 98
// RVA: 0x6334E0
void __fastcall UFG::UIHKScreenOptionsButtonMapping::init(
        UFG::UIHKScreenOptionsButtonMapping *this,
        UFG::UICommandData *data)
{
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // r12
  unsigned int v5; // r14d
  unsigned int v6; // ebp
  unsigned int v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ebx
  UFG::UIHKHelpBarData dataa; // [rsp+40h] [rbp-268h] BYREF

  UFG::UIScreen::init(this, data);
  UFG::UIHKScreenOptionsButtonMapping::PopulateUCS2Array(this);
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  p_HelpBar = &v3->HelpBar;
  v5 = UI_HASH_BUTTON_BACK_PRESSED_30;
  v6 = UI_HASH_KEYBOARD_INPUT_30;
  v7 = UI_HASH_BUTTON_R1_PRESSED_30;
  v8 = UI_HASH_BUTTON_ACCEPT_PRESSED_30;
  v9 = UFG::qStringHash32("BUTTON_MAPPING_SCREEN", 0xFFFFFFFF);
  UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
  dataa.id = v9;
  *(_QWORD *)&dataa.priority = 0i64;
  *(__m128i *)dataa.Buttons = _mm_load_si128((const __m128i *)&_xmm);
  *(_QWORD *)&dataa.Buttons[4] = 0i64;
  UFG::qString::Set(dataa.Captions, "$COMMON_REMAP");
  UFG::qString::Set(&dataa.Captions[1], "$HELPBAR_CHANGE_SECTION_UC");
  UFG::qString::Set(&dataa.Captions[2], "$COMMON_RESTORE_DEFAULTS_UPPERCASE");
  UFG::qString::Set(&dataa.Captions[3], "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set(&dataa.Captions[4], &customCaption);
  UFG::qString::Set(&dataa.Captions[5], &customCaption);
  dataa.MessageIds[0] = v8;
  dataa.MessageIds[1] = v7;
  dataa.MessageIds[2] = v6;
  dataa.MessageIds[3] = v5;
  *(_QWORD *)&dataa.MessageIds[4] = 0i64;
  UFG::UIHKHelpBarWidget::Show(p_HelpBar, &dataa);
  UFG::qString::~qString(&dataa.CustomTexturePack);
  `eh vector destructor iterator(dataa.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(dataa.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
  *(_DWORD *)&this->mOptionChanged = 0;
  this->mPendingRemap = 0;
  UFG::UIHKScreenOptionsButtonMapping::Bind(this);
  UFG::UIHKScreenOptionsButtonMapping::ClearArrays(this);
  UFG::UIHKScreenOptionsButtonMapping::PopulateOnFootArray(this);
  UFG::UIHKScreenOptionsButtonMapping::PopulateDrivingArray(this);
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "OptionList_PopulateData_OnFoot", 0i64, 0i64, 0);
}

// File Line: 133
// RVA: 0x5FDAA0
void __fastcall UFG::UIHKScreenOptionsButtonMapping::PopulateUCS2Array(UFG::UIHKScreenOptionsButtonMapping *this)
{
  int i; // ebx
  bool v2; // r8
  unsigned __int16 v3; // cx
  wchar_t pwszBuff[8]; // [rsp+40h] [rbp-118h] BYREF
  BYTE dest[256]; // [rsp+50h] [rbp-108h] BYREF

  if ( !UFG::UIHKScreenOptionsButtonMapping::bUCS2ArrayInitialized )
  {
    UFG::qMemSet(dest, 0, 0x100u);
    for ( i = 0; i < 256; ++i )
    {
      v2 = (unsigned int)(i - 106 + 41) <= 0x19;
      if ( (unsigned int)(i - 106 + 58) <= 9 )
        v2 = 1;
      if ( i == 106 || v2 )
      {
        UFG::qMemSet(pwszBuff, 0, 0x10u);
        if ( ToUnicodeEx((unsigned __int8)i, 0, dest, pwszBuff, 7, 1u, 0i64) < 1 )
          v3 = 0;
        else
          v3 = pwszBuff[0];
        UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[(unsigned __int8)i] = v3;
      }
      else
      {
        UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[(unsigned __int8)i] = 0;
      }
    }
    UFG::UIHKScreenOptionsButtonMapping::bUCS2ArrayInitialized = 1;
  }
}

// File Line: 207
// RVA: 0x6264F0
bool __fastcall UFG::UIHKScreenOptionsButtonMapping::handleMessage(
        UFG::UIHKScreenOptionsButtonMapping *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIMessage::UIMessageType m_messageType; // eax
  char vfptr; // bl
  const char *KeyActionTextToLocalize; // rax
  const char *v9; // rbx
  const char *v10; // rax
  char *mData; // rbx
  UFG::UIScreen *Overlay; // rax
  UFG *v13; // rcx
  UFG::UIHKScreenGlobalOverlay *v14; // rcx
  const char *v15; // rdx
  const char *v16; // rdx
  UFG *v17; // rcx
  UFG::GameSaveLoad *v18; // rax
  UFG::qString v20; // [rsp+48h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+70h] [rbp-38h] BYREF

  if ( !this->mMapping )
  {
    if ( this->mRestoring )
    {
      if ( msgId == UI_HASH_DIALOG_YES_30 )
      {
        UFG::UIHKScreenOptionsButtonMapping::ResetKeys(this);
        this->mOptionChanged = 1;
        this->mRestoring = 0;
      }
      else if ( msgId == UI_HASH_DIALOG_NO_30 )
      {
        this->mRestoring = 0;
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
    Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "GlobalOverlay");
    if ( Overlay )
    {
      v14 = UFG::UIHKScreenGlobalOverlay::mThis;
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v14 = &gGlobalOverlaySentinel;
      UFG::UIHKHelpBarWidget::HandleMessage(&v14->HelpBar, Overlay, msgId, msg);
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
        v15 = "OptionList_ScrollDown";
      }
      else
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
        v15 = "OptionList_ScrollUp";
      }
      Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, v15, 0i64, 0i64, 0);
    }
    if ( msgId == UI_HASH_BUTTON_L1_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCCF5DDCu, 0i64, 0, 0i64);
      v16 = "OptionController_ScrollPrev";
LABEL_91:
      Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, v16, 0i64, 0i64, 0);
      return 1;
    }
    if ( msgId == UI_HASH_BUTTON_R1_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xCCF5DDCu, 0i64, 0, 0i64);
      v16 = "OptionController_ScrollNext";
      goto LABEL_91;
    }
    if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
      v16 = "OptionList_ScrollDown";
      goto LABEL_91;
    }
    if ( msgId == UI_HASH_DPAD_UP_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
      v16 = "OptionList_ScrollUp";
      goto LABEL_91;
    }
    if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
      Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "OptionList_MapStart", 0i64, 0i64, 0);
      *(_WORD *)&this->mMapping = 257;
      return 1;
    }
    if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xF343A439, 0i64, 0, 0i64);
      if ( this->mOptionChanged )
        UFG::UIScreenDialogBox::createYesNoDialog(this, "$OPTIONS_OPTIONS_CHANGED", "$OPTIONS_SAVE_CHANGES", 1, 1);
      else
        UFG::UIHKScreenOptionsController::Exit((UFG::UIHKScreenOptionsController *)this);
      return 1;
    }
    if ( msgId == UI_HASH_DIALOG_YES_30 )
    {
      UFG::UIHKScreenOptionsButtonMapping::ApplyRemap(this);
      UFG::SaveKeyboardRemap(v17);
      v18 = UFG::GameSaveLoad::Instance();
      UFG::GameSaveLoad::SaveGameOptions(v18);
      UFG::DataSynchronizer::SetOptionsDirty();
      UFG::UIGfxTranslator::reloadDictionary(UFG::UIScreenManager::s_instance->m_translator, 0i64);
    }
    else
    {
      if ( msgId != UI_HASH_DIALOG_NO_30 )
      {
LABEL_81:
        if ( msg->m_messageType == UIMESSAGE_KEYBOARD_INPUT && LOBYTE(msg[1].vfptr) == 112 )
        {
          UFG::UIScreenDialogBox::createYesNoDialog(this, &customCaption, "$OPTIONS_RESTORE_DEFAULTS", 0, 1);
          this->mRestoring = 1;
        }
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      UFG::LoadKeyboardRemap(v13);
    }
    UFG::UIHKScreenOptionsController::Exit((UFG::UIHKScreenOptionsController *)this);
    goto LABEL_81;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
    Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "OptionList_MapCancel", 0i64, 0i64, 0);
    this->mMapping = 0;
    return 1;
  }
  if ( msgId == UI_HASH_DIALOG_YES_30 )
  {
    UFG::UIHKScreenOptionsButtonMapping::ExecuteRemap(this, this->mPendingRemap);
    this->mPendingRemap = 0;
  }
  else
  {
    if ( msgId != UI_HASH_DIALOG_NO_30 )
    {
      m_messageType = msg->m_messageType;
      if ( m_messageType == UIMESSAGE_KEYBOARD_INPUT )
      {
        vfptr = (char)msg[1].vfptr;
        if ( vfptr == 13 )
        {
          if ( this->mEatEnter )
          {
            this->mEatEnter = 0;
            return 1;
          }
        }
        else if ( (unsigned __int8)(vfptr - 91) <= 1u || vfptr == 20 )
        {
          return 1;
        }
        if ( !vfptr )
          return 1;
      }
      else
      {
        if ( m_messageType != UIMESSAGE_MOUSE_INPUT )
          return 1;
        if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
        {
          vfptr = 1;
        }
        else if ( msgId == UI_HASH_MOUSE_BUTTON_RIGHT_PRESSED_30 )
        {
          vfptr = 2;
        }
        else if ( msgId == UI_HASH_MOUSE_BUTTON_MIDDLE_PRESSED_30 )
        {
          vfptr = 4;
        }
        else if ( msgId == UI_HASH_MOUSE_BUTTON_4_PRESSED_30 )
        {
          vfptr = 5;
        }
        else
        {
          if ( msgId != UI_HASH_MOUSE_BUTTON_5_PRESSED_30 )
            return 1;
          vfptr = 6;
        }
      }
      if ( UFG::UIHKScreenOptionsButtonMapping::IsKeyAvailable(this, vfptr) )
      {
        UFG::UIHKScreenOptionsButtonMapping::ExecuteRemap(this, vfptr);
      }
      else
      {
        KeyActionTextToLocalize = UFG::UIHKScreenOptionsButtonMapping::GetKeyActionTextToLocalize(this, vfptr);
        v9 = UFG::UI::LocalizeText(KeyActionTextToLocalize);
        v10 = UFG::UI::LocalizeText("$OPTIONS_KEY_TAKEN_PC");
        UFG::qString::FormatEx(&result, v10, v9);
        mData = result.mData;
        UFG::qString::qString(&v20, "$COMMON_OK_UPPERCASE");
        UFG::UIScreenDialogBox::createOneButtonDialog(
          this,
          &customCaption,
          mData,
          v20.mData,
          UI_HASH_DIALOG_OK_30,
          1,
          "DialogBox");
        UFG::qString::~qString(&v20);
        this->mPendingRemap = 0;
        Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "OptionList_MapCancel", 0i64, 0i64, 0);
        this->mMapping = 0;
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
  Scaleform::GFx::Movie *pObject; // rbx

  pObject = this->mRenderable->m_movie.pObject;
  Scaleform::GFx::Movie::GetVariable(pObject, &this->mOnFootActions, "gOnFootActions");
  Scaleform::GFx::Movie::GetVariable(pObject, &this->mOnFootInputs, "gOnFootInputs");
  Scaleform::GFx::Movie::GetVariable(pObject, &this->mDrivingActions, "gDrivingActions");
  Scaleform::GFx::Movie::GetVariable(pObject, &this->mDrivingInputs, "gDrivingInputs");
}

// File Line: 476
// RVA: 0x5D5670
void __fastcall UFG::UIHKScreenOptionsButtonMapping::ClearArrays(UFG::UIHKScreenOptionsButtonMapping *this)
{
  this->mOnFootActions.pObjectInterface->vfptr->RemoveElements(
    this->mOnFootActions.pObjectInterface,
    (void *)this->mOnFootActions.mValue.pString,
    0,
    -1);
  this->mOnFootInputs.pObjectInterface->vfptr->RemoveElements(
    this->mOnFootInputs.pObjectInterface,
    (void *)this->mOnFootInputs.mValue.pString,
    0,
    -1);
  this->mDrivingActions.pObjectInterface->vfptr->RemoveElements(
    this->mDrivingActions.pObjectInterface,
    (void *)this->mDrivingActions.mValue.pString,
    0,
    -1);
  this->mDrivingInputs.pObjectInterface->vfptr->RemoveElements(
    this->mDrivingInputs.pObjectInterface,
    (void *)this->mDrivingInputs.mValue.pString,
    0,
    -1);
}

// File Line: 493
// RVA: 0x5F9B50
void __fastcall UFG::UIHKScreenOptionsButtonMapping::PopulateOnFootArray(UFG::UIHKScreenOptionsButtonMapping *this)
{
  unsigned int *v2; // rsi
  const char **v3; // r14
  __int64 v4; // r15
  __int64 v5; // rax
  int Key; // eax
  unsigned __int8 v7; // bl
  __int64 v8; // [rsp+8h] [rbp-79h]
  char v9; // [rsp+10h] [rbp-71h]
  __int64 v10; // [rsp+18h] [rbp-69h]
  char v11[8]; // [rsp+20h] [rbp-61h] BYREF
  char v12[16]; // [rsp+28h] [rbp-59h] BYREF
  __int64 v13; // [rsp+38h] [rbp-49h]
  int v14; // [rsp+40h] [rbp-41h]
  char *mData; // [rsp+48h] [rbp-39h]
  char v16[16]; // [rsp+58h] [rbp-29h] BYREF
  __int64 v17; // [rsp+68h] [rbp-19h]
  int v18; // [rsp+70h] [rbp-11h]
  __int64 v19; // [rsp+78h] [rbp-9h]
  __int64 v20; // [rsp+88h] [rbp+7h]
  UFG::qString keyName; // [rsp+90h] [rbp+Fh] BYREF
  unsigned __int16 v22; // [rsp+F0h] [rbp+6Fh]
  __int16 v23; // [rsp+F2h] [rbp+71h]

  v20 = -2i64;
  v2 = (unsigned int *)OnFootRemapIds_0;
  v3 = UFG::OnFootActions;
  v4 = 14i64;
  do
  {
    v5 = (__int64)*v3;
    v17 = 0i64;
    v18 = 6;
    v19 = v5;
    this->mOnFootActions.pObjectInterface->vfptr->PushBack(
      this->mOnFootActions.pObjectInterface,
      (void *)this->mOnFootActions.mValue.pString,
      (Scaleform::GFx::Value *)v16);
    if ( (v18 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v17 + 16i64))(v17, v16, v19);
      v17 = 0i64;
    }
    v18 = 0;
    Key = UFG::UIHKScreenOptionsButtonMapping::GetKey(*v2);
    v7 = Key;
    if ( UFG::UIHKScreenOptionsButtonMapping::bUCS2ArrayInitialized
      && UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[Key] )
    {
      v22 = UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[Key];
      v23 = 0;
      this->mOnFootInputs.pObjectInterface->vfptr->PushBack(
        this->mOnFootInputs.pObjectInterface,
        (void *)this->mOnFootInputs.mValue.pString,
        (Scaleform::GFx::Value *)v11);
      if ( (v9 & 0x40) != 0 )
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v8 + 16i64))(v8, v11, v10);
    }
    else
    {
      UFG::qString::qString(&keyName);
      UFG::KeyToKeyName(&keyName, v7);
      v13 = 0i64;
      v14 = 6;
      mData = keyName.mData;
      this->mOnFootInputs.pObjectInterface->vfptr->PushBack(
        this->mOnFootInputs.pObjectInterface,
        (void *)this->mOnFootInputs.mValue.pString,
        (Scaleform::GFx::Value *)v12);
      if ( (v14 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v13 + 16i64))(v13, v12, mData);
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
  unsigned int *v2; // rsi
  const char **v3; // r14
  __int64 v4; // r15
  __int64 v5; // rax
  int Key; // eax
  unsigned __int8 v7; // bl
  char v8[16]; // [rsp+20h] [rbp-B8h] BYREF
  __int64 v9; // [rsp+30h] [rbp-A8h]
  int v10; // [rsp+38h] [rbp-A0h]
  __int16 *v11; // [rsp+40h] [rbp-98h]
  char v12[8]; // [rsp+50h] [rbp-88h] BYREF
  char v13[8]; // [rsp+58h] [rbp-80h] BYREF
  __int64 v14; // [rsp+60h] [rbp-78h]
  __int64 v15; // [rsp+68h] [rbp-70h]
  char *mData; // [rsp+70h] [rbp-68h]
  __int64 v17; // [rsp+78h] [rbp-60h]
  __int64 v18; // [rsp+88h] [rbp-50h]
  UFG::qString keyName; // [rsp+90h] [rbp-48h] BYREF
  UFG::qString v20; // [rsp+B8h] [rbp-20h] BYREF
  UFG::qString v21; // [rsp+E0h] [rbp+8h] BYREF
  __int16 v22[8]; // [rsp+120h] [rbp+48h] BYREF

  v18 = -2i64;
  UFG::qString::qString(&v21);
  v2 = (unsigned int *)DrivingRemapIds_0;
  v3 = UFG::DrivingActions;
  v4 = 13i64;
  do
  {
    v5 = (__int64)*v3;
    v15 = 0i64;
    LODWORD(mData) = 6;
    v17 = v5;
    this->mDrivingActions.pObjectInterface->vfptr->PushBack(
      this->mDrivingActions.pObjectInterface,
      (void *)this->mDrivingActions.mValue.pString,
      (Scaleform::GFx::Value *)v13);
    if ( ((unsigned __int8)mData & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, v13, v17);
      v15 = 0i64;
    }
    LODWORD(mData) = 0;
    Key = UFG::UIHKScreenOptionsButtonMapping::GetKey(*v2);
    v7 = Key;
    if ( UFG::UIHKScreenOptionsButtonMapping::bUCS2ArrayInitialized
      && UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[Key] )
    {
      v22[0] = UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[Key];
      v22[1] = 0;
      v9 = 0i64;
      v10 = 7;
      v11 = v22;
      this->mDrivingInputs.pObjectInterface->vfptr->PushBack(
        this->mDrivingInputs.pObjectInterface,
        (void *)this->mDrivingInputs.mValue.pString,
        (Scaleform::GFx::Value *)v8);
      if ( (v10 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, __int16 *))(*(_QWORD *)v9 + 16i64))(v9, v8, v11);
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
      mData = keyName.mData;
      this->mDrivingInputs.pObjectInterface->vfptr->PushBack(
        this->mDrivingInputs.pObjectInterface,
        (void *)this->mDrivingInputs.mValue.pString,
        (Scaleform::GFx::Value *)v12);
      if ( (v15 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v14 + 16i64))(v14, v12, mData);
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
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
}

// File Line: 577
// RVA: 0x5EE340
char __fastcall UFG::UIHKScreenOptionsButtonMapping::IsKeyAvailable(
        UFG::UIHKScreenOptionsButtonMapping *this,
        char key)
{
  const unsigned int *v4; // rsi
  bool v5; // al
  unsigned int v6; // ebx
  BOOL v7; // ebp
  unsigned int v8; // r14d
  unsigned int v9; // ebp
  unsigned int v10; // edi

  v4 = DrivingRemapIds_0;
  v5 = (unsigned int)UFG::UIHKScreenOptionsButtonMapping::GetSelectedTab(this) == 0;
  if ( v5 )
    v4 = OnFootRemapIds_0;
  v6 = 0;
  v7 = v5;
  v8 = v4[(unsigned int)UFG::UIHKScreenOptionsButtonMapping::GetSelectedIndex(this)];
  v9 = v7 + 13;
  if ( !v9 )
    return 1;
  while ( 1 )
  {
    v10 = *v4;
    if ( (unsigned __int8)UFG::UIHKScreenOptionsButtonMapping::GetKey(*v4) == key && v10 != v8 )
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
const char *__fastcall UFG::UIHKScreenOptionsButtonMapping::GetKeyActionTextToLocalize(
        UFG::UIHKScreenOptionsButtonMapping *this,
        unsigned __int8 key)
{
  unsigned int SelectedTab; // eax
  const unsigned int *v4; // r14
  bool v5; // r15
  int v6; // edi
  __int64 v7; // rbx
  int v8; // eax
  __int64 v9; // rsi

  SelectedTab = UFG::UIHKScreenOptionsButtonMapping::GetSelectedTab(this);
  v4 = DrivingRemapIds_0;
  v5 = SelectedTab == 0;
  if ( !SelectedTab )
    v4 = OnFootRemapIds_0;
  v6 = 0;
  v7 = 0i64;
  v8 = (SelectedTab == 0) + 13;
  v9 = v8;
  if ( v8 <= 0 )
    return " ";
  while ( (unsigned int)UFG::UIHKScreenOptionsButtonMapping::GetKey(v4[v7]) != key )
  {
    ++v7;
    ++v6;
    if ( v7 >= v9 )
      return " ";
  }
  if ( v5 )
    return UFG::OnFootActions[v6];
  else
    return UFG::DrivingActions[v6];
}

// File Line: 614
// RVA: 0x602940
void __fastcall UFG::UIHKScreenOptionsButtonMapping::ResetKeys(UFG::UIHKScreenOptionsButtonMapping *this)
{
  unsigned int v1; // edx
  UFG::Controller **mControllers; // rax
  UFG::Controller *v4; // rcx

  v1 = 0;
  mControllers = UFG::gInputSystem->mControllers;
  while ( 1 )
  {
    v4 = *mControllers;
    if ( *mControllers )
    {
      if ( v4->m_IsKeyboardController )
        break;
    }
    ++v1;
    ++mControllers;
    if ( v1 >= 5 )
    {
      v4 = 0i64;
      break;
    }
  }
  UFG::Controller::ResetRemapList(v4);
  UFG::UIHKScreenOptionsButtonMapping::ClearArrays(this);
  UFG::UIHKScreenOptionsButtonMapping::PopulateOnFootArray(this);
  UFG::UIHKScreenOptionsButtonMapping::PopulateDrivingArray(this);
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "OptionList_Refresh", 0i64, 0i64, 0);
}

// File Line: 624
// RVA: 0x5D7620
void __fastcall UFG::UIHKScreenOptionsButtonMapping::ExecuteRemap(
        UFG::UIHKScreenOptionsButtonMapping *this,
        unsigned __int8 key)
{
  __int16 v4; // bx
  UFG::qString externalSourceInfo; // [rsp+20h] [rbp-11h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+48h] [rbp+17h] BYREF
  __int16 vars0[4]; // [rsp+A0h] [rbp+6Fh] BYREF

  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
  if ( UFG::UIHKScreenOptionsButtonMapping::bUCS2ArrayInitialized )
    v4 = UFG::UIHKScreenOptionsButtonMapping::aUCS2Array[key];
  else
    v4 = 0;
  UFG::qString::qString(&externalSourceInfo);
  UFG::KeyToKeyName(&externalSourceInfo, key);
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Undefined;
  if ( v4 )
  {
    vars0[0] = v4;
    vars0[1] = 0;
    pargs.Type = VT_StringW;
    pargs.mValue.pString = (const char *)vars0;
  }
  else
  {
    pargs.Type = VT_String;
    pargs.mValue.pString = externalSourceInfo.mData;
  }
  Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "OptionList_MapSet", 0i64, &pargs, 1u);
  UFG::UIHKScreenOptionsButtonMapping::SaveKey(this, key);
  *(_WORD *)&this->mOptionChanged = 1;
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Undefined;
  UFG::qString::~qString(&externalSourceInfo);
}

// File Line: 653
// RVA: 0x603830
bool __fastcall UFG::UIHKScreenOptionsButtonMapping::SaveKey(
        UFG::UIHKScreenOptionsButtonMapping *this,
        unsigned int key)
{
  unsigned int v4; // ebx
  bool v5; // bp
  unsigned int v7; // eax
  int SelectedIndex; // eax
  unsigned int v9; // ebp
  unsigned int v10; // ebx
  unsigned int v11; // r8d
  unsigned int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // eax

  if ( (unsigned int)UFG::UIHKScreenOptionsButtonMapping::GetSelectedTab(this) )
  {
    SelectedIndex = UFG::UIHKScreenOptionsButtonMapping::GetSelectedIndex(this);
    v9 = REMAP_ID_STEER_R_2;
    v10 = DrivingRemapIds_0[SelectedIndex];
    if ( v10 != REMAP_ID_STEER_L_2 && v10 != REMAP_ID_STEER_R_2 )
    {
      v11 = key;
      v12 = DrivingRemapIds_0[SelectedIndex];
      return UFG::UIHKScreenOptionsButtonMapping::SaveKey(this, v12, v11);
    }
    v13 = UFG::UIHKScreenOptionsButtonMapping::GetKey(REMAP_ID_STEER_2);
    if ( v10 == v9 )
    {
      v14 = v13 & 0xFFFF00FF;
      key <<= 8;
    }
    else
    {
      if ( v10 != REMAP_ID_STEER_L_2 )
      {
LABEL_19:
        v12 = REMAP_ID_STEER_2;
        v11 = v13;
        return UFG::UIHKScreenOptionsButtonMapping::SaveKey(this, v12, v11);
      }
      v14 = v13 & 0xFFFFFF00;
    }
    v13 = key + v14;
    goto LABEL_19;
  }
  v4 = OnFootRemapIds_0[(unsigned int)UFG::UIHKScreenOptionsButtonMapping::GetSelectedIndex(this)];
  if ( v4 != REMAP_ID_MOVE_F_2 && v4 != REMAP_ID_MOVE_B_2 && v4 != REMAP_ID_MOVE_L_2 && v4 != REMAP_ID_MOVE_R_2 )
  {
    v5 = UFG::UIHKScreenOptionsButtonMapping::SaveKey(this, v4, key);
    if ( v4 == REMAP_ID_FIRE_2 )
      return v5 & UFG::UIHKScreenOptionsButtonMapping::SaveKey(this, REMAP_ID_ATTACK_2, key);
    return v5;
  }
  v7 = UFG::UIHKScreenOptionsButtonMapping::PackMoveButton(v4, key);
  v5 = UFG::UIHKScreenOptionsButtonMapping::SaveKey(this, REMAP_ID_MOVE_2, v7);
  if ( v4 != REMAP_ID_MOVE_F_2 )
    return v5;
  return v5 & UFG::UIHKScreenOptionsButtonMapping::SaveKey(this, REMAP_ID_FORWARD_KEY_2, key);
}

// File Line: 698
// RVA: 0x603980
char __fastcall UFG::UIHKScreenOptionsButtonMapping::SaveKey(
        UFG::UIHKScreenOptionsButtonMapping *this,
        unsigned int remapId,
        unsigned int key)
{
  unsigned int v3; // ecx
  UFG::Controller **mControllers; // r9
  UFG::Controller *v5; // rax
  UFG::qList<UFG::ActionRemapInfo,UFG::ActionRemapInfo,1,0> *p_mRemappableActions; // rcx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *mNext; // rax

  v3 = 0;
  mControllers = UFG::gInputSystem->mControllers;
  while ( 1 )
  {
    v5 = *mControllers;
    if ( *mControllers )
    {
      if ( v5->m_IsKeyboardController )
        break;
    }
    ++v3;
    ++mControllers;
    if ( v3 >= 5 )
    {
      v5 = 0i64;
      break;
    }
  }
  p_mRemappableActions = &v5->mRemappableActions;
  mNext = v5->mRemappableActions.mNode.mNext;
  if ( mNext == (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)p_mRemappableActions )
    return 0;
  while ( LODWORD(mNext[2].mNext) != remapId )
  {
    mNext = mNext->mNext;
    if ( mNext == (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)p_mRemappableActions )
      return 0;
  }
  LODWORD(mNext[3].mPrev) = key;
  return 1;
}

// File Line: 723
// RVA: 0x5D46A0
__int64 __fastcall UFG::UIHKScreenOptionsButtonMapping::ButtonToRemapId(
        UFG::UI::eButtons button,
        UFG::UI::RemapContext ctx)
{
  bool v2; // dl
  __int64 result; // rax

  v2 = ctx == RemapContext_OnFoot;
  switch ( button )
  {
    case ACCEPT_BUTTON:
      result = REMAP_ID_ACTIONHIJACK_2;
      if ( v2 )
        result = REMAP_ID_FREERUN_2;
      break;
    case BACK_BUTTON:
    case BACK_BUTTON_HOLD:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_GRAPPLE_2;
      break;
    case BUTTON1_BUTTON:
    case R2_BUTTON:
    case BUTTON1_BUTTON_HOLD:
    case R2_BUTTON_HOLD:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_FIRE_2;
      break;
    case BUTTON2_BUTTON:
    case BUTTON2_BUTTON_HOLD:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_ACTION_2;
      break;
    case L1_BUTTON:
    case L1_BUTTON_HOLD:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_COVERTOGGLE_2;
      break;
    case R1_BUTTON:
    case R1_BUTTON_HOLD:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_RELOAD_2;
      break;
    case L2_BUTTON:
    case L2_BUTTON_HOLD:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_AIM_2;
      break;
    case R3_BUTTON:
      result = REMAP_ID_INVALID_2;
      if ( v2 )
        result = REMAP_ID_WEAPON_SPECIAL_2;
      break;
    case ACCEPT_BUTTON_HOLD:
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
  UFG::Controller **mControllers; // rax
  UFG::Controller *v3; // rcx

  v1 = 0;
  mControllers = UFG::gInputSystem->mControllers;
  while ( 1 )
  {
    v3 = *mControllers;
    if ( *mControllers )
    {
      if ( v3->m_IsKeyboardController )
        break;
    }
    ++v1;
    ++mControllers;
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
  __int64 result; // rax

  result = UFG::UIHKScreenOptionsButtonMapping::GetKey(REMAP_ID_MOVE_2);
  if ( remapId == REMAP_ID_MOVE_F_2 )
    return (dirButton << 24) + (result & 0xFFFFFF);
  if ( remapId == REMAP_ID_MOVE_B_2 )
    return (dirButton << 16) + (result & 0xFF00FFFF);
  if ( remapId == REMAP_ID_MOVE_R_2 )
    return (dirButton << 8) + (result & 0xFFFF00FF);
  if ( remapId == REMAP_ID_MOVE_L_2 )
    return dirButton + (result & 0xFFFFFF00);
  return result;
}

// File Line: 867
// RVA: 0x5E7EF0
__int64 __fastcall UFG::UIHKScreenOptionsButtonMapping::GetKey(unsigned int remapId)
{
  unsigned int v1; // r10d
  unsigned int v2; // edx
  UFG::Controller **mControllers; // r8
  unsigned int v4; // r9d
  UFG::Controller *v5; // rax
  UFG::qList<UFG::ActionRemapInfo,UFG::ActionRemapInfo,1,0> *p_mRemappableActions; // r8
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *mNext; // rax
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
  mControllers = UFG::gInputSystem->mControllers;
  v4 = 0;
  while ( 1 )
  {
    v5 = *mControllers;
    if ( *mControllers )
    {
      if ( v5->m_IsKeyboardController )
        break;
    }
    ++v4;
    ++mControllers;
    if ( v4 >= 5 )
    {
      v5 = 0i64;
      break;
    }
  }
  p_mRemappableActions = &v5->mRemappableActions;
  mNext = v5->mRemappableActions.mNode.mNext;
  if ( mNext == (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)p_mRemappableActions )
    return v2;
  while ( LODWORD(mNext[2].mNext) != v1 )
  {
    mNext = mNext->mNext;
    if ( mNext == (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)p_mRemappableActions )
      return 0i64;
  }
  result = LODWORD(mNext[3].mPrev);
  if ( remapId == REMAP_ID_MOVE_F_2 )
    return BYTE3(result);
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
          return (unsigned __int8)result;
        return v2;
      }
      return BYTE1(result);
    }
    return BYTE3(result);
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
  Scaleform::GFx::Movie *pObject; // rcx
  double NValue; // xmm6_8
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-50h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_ConvertNumber;
  pval.mValue.pString = 0i64;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gSelectedTab");
  if ( (pval.Type & 0x8F) == 5 )
  {
    NValue = pval.mValue.NValue;
    if ( (pval.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
      pval.pObjectInterface = 0i64;
    }
    return (unsigned int)(int)NValue;
  }
  else
  {
    if ( (pval.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
      pval.pObjectInterface = 0i64;
    }
    return (unsigned int)(int)0.0;
  }
}

// File Line: 928
// RVA: 0x5E8ED0
__int64 __fastcall UFG::UIHKScreenOptionsButtonMapping::GetSelectedIndex(UFG::UIHKScreenOptionsButtonMapping *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  double NValue; // xmm6_8
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-50h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_ConvertNumber;
  pval.mValue.pString = 0i64;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gSelectedIndex");
  if ( (pval.Type & 0x8F) == 5 )
  {
    NValue = pval.mValue.NValue;
    if ( (pval.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
      pval.pObjectInterface = 0i64;
    }
    return (unsigned int)(int)NValue;
  }
  else
  {
    if ( (pval.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
      pval.pObjectInterface = 0i64;
    }
    return (unsigned int)(int)0.0;
  }
}

