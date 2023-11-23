// File Line: 19
// RVA: 0x1569950
__int64 dynamic_initializer_for__UIHASH_SELECT__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("select", -1);
  UIHASH_SELECT = result;
  return result;
}

// File Line: 20
// RVA: 0x156A250
__int64 dynamic_initializer_for__UI_DIALOG_HELP_BAR__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("UI_DIALOG", -1);
  UI_DIALOG_HELP_BAR = result;
  return result;
}

// File Line: 30
// RVA: 0x5C8A90
void __fastcall UFG::UIScreenDialogBox::UIScreenDialogBox(UFG::UIScreenDialogBox *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreenDialogBox::`vftable;
  UFG::UIScreenDialogBox::UIScreenDialogBoxData::UIScreenDialogBoxData(&this->mData);
  this->mState = STATE_NONE;
  ++UFG::UIScreenDialogBox::m_iDialogBoxRefCount;
}

// File Line: 38
// RVA: 0x5CE3A0
void __fastcall UFG::UIScreenDialogBox::~UIScreenDialogBox(UFG::UIScreenDialogBox *this)
{
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreenDialogBox::`vftable;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    UFG::UIHKHelpBarWidget::Hide(&UFG::UIHKScreenGlobalOverlay::mThis->HelpBar, UI_DIALOG_HELP_BAR);
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_DIALOG_BOX_DISAPPEAR_3, 0xFFFFFFFF);
  --UFG::UIScreenDialogBox::m_iDialogBoxRefCount;
  UFG::UIScreenDialogBox::UIScreenDialogBoxData::~UIScreenDialogBoxData(&this->mData);
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 56
// RVA: 0x637F40
void __fastcall UFG::UIScreenDialogBox::init(
        UFG::UIScreenDialogBox *this,
        UFG::UIScreenDialogBox::UIScreenDialogBoxData *data)
{
  UFG::UIHKHelpBarWidget *p_HelpBar; // r14
  unsigned int v5; // ebx
  Scaleform::GFx::Movie *pObject; // r14
  double mNumOptions; // xmm6_8
  UFG::UICommandDataVtbl *mData; // rbx
  UFG::UICommandDataVtbl *v9; // rbx
  UFG::UICommandDataVtbl *v10; // rbx
  double mDefaultButton; // xmm6_8
  bool mFullScreen; // bl
  double mHorizontalResolution; // xmm6_8
  double mVerticalResolution; // xmm6_8
  UFG::UICommandDataVtbl *v15; // rbx
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-88h] BYREF
  int v18; // [rsp+90h] [rbp-58h]
  UFG::UICommandDataVtbl *v19; // [rsp+98h] [rbp-50h]
  char v20[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v21; // [rsp+B8h] [rbp-30h]
  int v22; // [rsp+C0h] [rbp-28h]
  UFG::UICommandDataVtbl *v23; // [rsp+C8h] [rbp-20h]
  char v24[16]; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v25; // [rsp+E8h] [rbp+0h]
  int v26; // [rsp+F0h] [rbp+8h]
  UFG::UICommandDataVtbl *v27; // [rsp+F8h] [rbp+10h]
  char v28[16]; // [rsp+108h] [rbp+20h] BYREF
  __int64 v29; // [rsp+118h] [rbp+30h]
  int v30; // [rsp+120h] [rbp+38h]
  double v31; // [rsp+128h] [rbp+40h]
  char v32[16]; // [rsp+138h] [rbp+50h] BYREF
  __int64 v33; // [rsp+148h] [rbp+60h]
  int v34; // [rsp+150h] [rbp+68h]
  __int64 v35; // [rsp+158h] [rbp+70h]
  char v36[16]; // [rsp+168h] [rbp+80h] BYREF
  __int64 v37; // [rsp+178h] [rbp+90h]
  int v38; // [rsp+180h] [rbp+98h]
  double v39; // [rsp+188h] [rbp+A0h]
  char v40[16]; // [rsp+198h] [rbp+B0h] BYREF
  __int64 v41; // [rsp+1A8h] [rbp+C0h]
  int v42; // [rsp+1B0h] [rbp+C8h]
  double v43; // [rsp+1B8h] [rbp+D0h]
  __int64 v44; // [rsp+1C8h] [rbp+E0h]
  UFG::UIHKHelpBarData dataa; // [rsp+1D8h] [rbp+F0h] BYREF

  v44 = -2i64;
  UFG::UIScreen::init(this, data);
  UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, UI_HASH_DIALOG_BOX_APPEAR_3, 0xFFFFFFFF);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v5 = UI_DIALOG_HELP_BAR;
    UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
    dataa.id = v5;
    dataa.priority = PRIORITY_ONE;
    dataa.alignment = ALIGN_RIGHT;
    memset(dataa.Buttons, 0, sizeof(dataa.Buttons));
    UFG::qString::Set(dataa.Captions, &customCaption);
    UFG::qString::Set(&dataa.Captions[1], &customCaption);
    UFG::qString::Set(&dataa.Captions[2], &customCaption);
    UFG::qString::Set(&dataa.Captions[3], &customCaption);
    UFG::qString::Set(&dataa.Captions[4], &customCaption);
    UFG::qString::Set(&dataa.Captions[5], &customCaption);
    memset(dataa.MessageIds, 0, sizeof(dataa.MessageIds));
    UFG::UIHKHelpBarWidget::Show(p_HelpBar, &dataa);
    UFG::qString::~qString(&dataa.CustomTexturePack);
    `eh vector destructor iterator(dataa.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(dataa.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  }
  this->mState = STATE_QUEUED;
  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  mNumOptions = (double)(int)data->mNumOptions;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.pNext);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  *(double *)&ptr.pNext = mNumOptions;
  mData = (UFG::UICommandDataVtbl *)data->mOption1Text.mData;
  if ( (v18 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, UFG::UICommandDataVtbl *))(*(_QWORD *)ptr.DataAux + 16i64))(
      ptr.DataAux,
      &ptr.Type,
      v19);
    ptr.DataAux = 0i64;
  }
  v18 = 6;
  v19 = mData;
  v9 = (UFG::UICommandDataVtbl *)data->mOption2Text.mData;
  if ( (v22 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, UFG::UICommandDataVtbl *))(*(_QWORD *)v21 + 16i64))(v21, v20, v23);
    v21 = 0i64;
  }
  v22 = 6;
  v23 = v9;
  v10 = (UFG::UICommandDataVtbl *)data->mOption3Text.mData;
  if ( (v26 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, UFG::UICommandDataVtbl *))(*(_QWORD *)v25 + 16i64))(v25, v24, v27);
    v25 = 0i64;
  }
  v26 = 6;
  v27 = v10;
  mDefaultButton = (double)(int)data->mDefaultButton;
  if ( (v30 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v29 + 16i64))(v29, v28, COERCE_DOUBLE(*(_QWORD *)&v31));
    v29 = 0i64;
  }
  v30 = 5;
  v31 = mDefaultButton;
  mFullScreen = data->mFullScreen;
  if ( (v34 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v33 + 16i64))(v33, v32, v35);
    v33 = 0i64;
  }
  v34 = 2;
  LOBYTE(v35) = mFullScreen;
  mHorizontalResolution = (double)(int)data->mHorizontalResolution;
  if ( (v38 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v37 + 16i64))(v37, v36, COERCE_DOUBLE(*(_QWORD *)&v39));
    v37 = 0i64;
  }
  v38 = 5;
  v39 = mHorizontalResolution;
  mVerticalResolution = (double)(int)data->mVerticalResolution;
  if ( (v42 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v41 + 16i64))(v41, v40, COERCE_DOUBLE(*(_QWORD *)&v43));
    v41 = 0i64;
  }
  v42 = 5;
  v43 = mVerticalResolution;
  Scaleform::GFx::Movie::Invoke(pObject, "setOptions", 0i64, &ptr, 8u);
  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Undefined;
  v15 = (UFG::UICommandDataVtbl *)data->mBodyText.mData;
  pargs.Type = VT_String;
  pargs.mValue.pString = (const char *)v15;
  Scaleform::GFx::Movie::Invoke(pObject, "setBodyText", 0i64, &pargs, 1u);
  UFG::UIScreenDialogBox::UIScreenDialogBoxData::operator=(&this->mData, data);
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Undefined;
  `eh vector destructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 109
// RVA: 0x62F670
bool __fastcall UFG::UIScreenDialogBox::handleMessage(
        UFG::UIScreenDialogBox *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  __int32 v6; // ecx
  int v7; // eax
  UFG::UIScreen *mOwner; // rcx
  unsigned int mScreenUID; // edi
  int v10; // eax
  int v11; // eax
  unsigned int mOption3Msg; // edx
  unsigned int v13; // edx

  v6 = this->mState - 1;
  if ( v6 )
  {
    if ( v6 == 1 && msgId == UIHASH_SELECT )
    {
      v7 = atol(*(const char **)&msg[1].m_commandType);
      mOwner = this->mData.mOwner;
      mScreenUID = -1;
      if ( mOwner )
        mScreenUID = mOwner->mScreenUID;
      if ( v7 )
      {
        v10 = v7 - 1;
        if ( v10 )
        {
          v11 = v10 - 1;
          if ( v11 )
          {
            if ( v11 != 1 )
            {
LABEL_17:
              v13 = this->mScreenUID;
              this->mState = STATE_NONE;
              UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, v13);
              return 1;
            }
            mOption3Msg = this->mData.mOption3Msg;
          }
          else
          {
            mOption3Msg = this->mData.mOption2Msg;
          }
        }
        else
        {
          mOption3Msg = this->mData.mOption1Msg;
        }
      }
      else
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
        mOption3Msg = UI_HASH_DIALOG_CANCEL_30;
      }
      UFG::UIScreenManagerBase::queueMessage(UFG::UIScreenManager::s_instance, mOption3Msg, mScreenUID);
      goto LABEL_17;
    }
  }
  else
  {
    if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
      || msgId == UI_HASH_DPAD_UP_REPEAT_30
      || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
    {
      UFG::UIScreen::invoke(this, "scrollLeft");
      if ( this->mData.mNumOptions > 1 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
      }
    }
    if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30
      || msgId == UI_HASH_DPAD_DOWN_REPEAT_30
      || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
    {
      UFG::UIScreen::invoke(this, "scrollRight");
      if ( this->mData.mNumOptions > 1 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
      }
    }
    if ( msgId == UI_HASH_MOUSE_MOVE_30 )
    {
      UFG::UIScreenDialogBox::Flash_handleMouseMove(this, (float)SLODWORD(msg[1].vfptr), (float)SHIDWORD(msg[1].vfptr));
    }
    else if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
    {
      UFG::UIScreenDialogBox::Flash_handleMouseClick(this, (float)SLODWORD(msg[1].vfptr), (float)SHIDWORD(msg[1].vfptr));
    }
    if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 || msgId == UI_HASH_LIST_OPTION_SELECTED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
      UFG::UIScreen::invoke(this, "accept");
      this->mState = STATE_WAITING;
    }
  }
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

// File Line: 208
// RVA: 0x5E63D0
void __fastcall UFG::UIScreenDialogBox::Flash_handleMouseMove(UFG::UIScreenDialogBox *this, float mouseX, float mouseY)
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
    Scaleform::GFx::Movie::Invoke(pObject, "handleMouseMove", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 222
// RVA: 0x5E6150
void __fastcall UFG::UIScreenDialogBox::Flash_handleMouseClick(
        UFG::UIScreenDialogBox *this,
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
    Scaleform::GFx::Movie::Invoke(pObject, "handleMouseClick", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 257
// RVA: 0x61F470
__int64 __fastcall UFG::UIScreenDialogBox::createOKDialog(
        UFG::UIScreen *owner,
        const char *titleText,
        const char *bodyText,
        bool fullscreen)
{
  unsigned int OneButtonDialog; // ebx
  UFG::qString v10; // [rsp+48h] [rbp-30h] BYREF

  UFG::qString::qString(&v10, "$COMMON_OK_UPPERCASE");
  OneButtonDialog = UFG::UIScreenDialogBox::createOneButtonDialog(
                      owner,
                      titleText,
                      bodyText,
                      v10.mData,
                      UI_HASH_DIALOG_OK_30,
                      fullscreen,
                      "DialogBox");
  UFG::qString::~qString(&v10);
  return OneButtonDialog;
}

// File Line: 272
// RVA: 0x61FAB0
__int64 __fastcall UFG::UIScreenDialogBox::createYesNoDialog(
        UFG::UIScreen *owner,
        const char *titleText,
        const char *bodyText,
        bool defaultYes,
        bool fullscreen)
{
  unsigned int TwoButtonDialog; // ebx
  UFG::qString option2Text; // [rsp+58h] [rbp-60h] BYREF
  UFG::qString v12; // [rsp+80h] [rbp-38h] BYREF

  UFG::qString::qString(&v12, "$OPTIONS_YES");
  UFG::qString::qString(&option2Text, "$OPTIONS_NO");
  TwoButtonDialog = UFG::UIScreenDialogBox::createTwoButtonDialog(
                      owner,
                      titleText,
                      bodyText,
                      v12.mData,
                      UI_HASH_DIALOG_YES_30,
                      option2Text.mData,
                      UI_HASH_DIALOG_NO_30,
                      (UFG::UIScreenDialogBox::eDefaultButton)(2 - defaultYes),
                      fullscreen,
                      "DialogBox");
  UFG::qString::~qString(&option2Text);
  UFG::qString::~qString(&v12);
  return TwoButtonDialog;
}

// File Line: 289
// RVA: 0x61FB90
__int64 __fastcall UFG::UIScreenDialogBox::createZeroButtonDialog(
        UFG::UIScreen *owner,
        const char *titleText,
        const char *bodyText,
        bool fullscreen,
        const char *flashFile)
{
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rbx
  UFG::UICommand *v12; // rax

  v9 = UFG::qMemoryPool::Allocate(
         &gScaleformMemoryPool,
         0x128ui64,
         "UIScreenDialogBox::createZeroButtonDialog",
         0i64,
         1u);
  if ( v9 )
  {
    UFG::UIScreenDialogBox::UIScreenDialogBoxData::UIScreenDialogBoxData((UFG::UIScreenDialogBox::UIScreenDialogBoxData *)v9);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  UFG::qString::Set((UFG::qString *)(v11 + 248), flashFile);
  *(_DWORD *)(v11 + 16) = 0;
  *(_QWORD *)(v11 + 8) = owner;
  UFG::qString::Set((UFG::qString *)(v11 + 24), titleText);
  UFG::qString::Set((UFG::qString *)(v11 + 64), bodyText);
  *(_BYTE *)(v11 + 244) = fullscreen;
  *(_DWORD *)(v11 + 288) = (int)gUIHorizontalResolution;
  *(_DWORD *)(v11 + 292) = (int)gUIVerticalResolution;
  v12 = UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManager::s_instance, *(const char **)(v11 + 272), -1);
  v12->m_commandData = (UFG::UICommandData *)v11;
  return LODWORD(v12[4].mPrev);
}

// File Line: 312
// RVA: 0x61F500
__int64 __fastcall UFG::UIScreenDialogBox::createOneButtonDialog(
        UFG::UIScreen *owner,
        const char *titleText,
        const char *bodyText,
        const char *optionText,
        unsigned int optionMsg,
        bool fullscreen,
        const char *flashFile)
{
  UFG::allocator::free_link *v11; // rax
  __int64 v12; // rax
  __int64 v13; // rbx
  UFG::UICommand *v14; // rax

  v11 = UFG::qMemoryPool::Allocate(
          &gScaleformMemoryPool,
          0x128ui64,
          "UIScreenDialogBox::createOneButtonDialog",
          0i64,
          1u);
  if ( v11 )
  {
    UFG::UIScreenDialogBox::UIScreenDialogBoxData::UIScreenDialogBoxData((UFG::UIScreenDialogBox::UIScreenDialogBoxData *)v11);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  UFG::qString::Set((UFG::qString *)(v13 + 248), flashFile);
  *(_DWORD *)(v13 + 16) = 1;
  *(_QWORD *)(v13 + 8) = owner;
  UFG::qString::Set((UFG::qString *)(v13 + 24), titleText);
  UFG::qString::Set((UFG::qString *)(v13 + 64), bodyText);
  *(_DWORD *)(v13 + 20) = 1;
  *(_DWORD *)(v13 + 104) = optionMsg;
  UFG::qString::Set((UFG::qString *)(v13 + 120), optionText);
  *(_BYTE *)(v13 + 244) = fullscreen;
  *(_DWORD *)(v13 + 288) = (int)gUIHorizontalResolution;
  *(_DWORD *)(v13 + 292) = (int)gUIVerticalResolution;
  v14 = UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManager::s_instance, *(const char **)(v13 + 272), -1);
  v14->m_commandData = (UFG::UICommandData *)v13;
  return LODWORD(v14[4].mPrev);
}

// File Line: 340
// RVA: 0x61F970
__int64 __fastcall UFG::UIScreenDialogBox::createTwoButtonDialog(
        UFG::UIScreen *owner,
        const char *titleText,
        const char *bodyText,
        const char *option1Text,
        unsigned int option1Msg,
        const char *option2Text,
        unsigned int option2Msg,
        UFG::UIScreenDialogBox::eDefaultButton defaultButton,
        bool fullscreen,
        const char *flashFile)
{
  UFG::allocator::free_link *v14; // rax
  UFG::UIScreenDialogBox::UIScreenDialogBoxData *v15; // rax
  UFG::UIScreenDialogBox::UIScreenDialogBoxData *v16; // rbx
  UFG::UICommand *v17; // rax

  v14 = UFG::qMemoryPool::Allocate(
          &gScaleformMemoryPool,
          0x128ui64,
          "UIScreenDialogBox::createTwoButtonDialog",
          0i64,
          1u);
  if ( v14 )
  {
    UFG::UIScreenDialogBox::UIScreenDialogBoxData::UIScreenDialogBoxData((UFG::UIScreenDialogBox::UIScreenDialogBoxData *)v14);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  UFG::qString::Set(&v16->mFlashFile, flashFile);
  v16->mNumOptions = 2;
  v16->mOwner = owner;
  UFG::qString::Set(&v16->mTitleText, titleText);
  UFG::qString::Set(&v16->mBodyText, bodyText);
  v16->mDefaultButton = defaultButton;
  v16->mOption1Msg = option1Msg;
  UFG::qString::Set(&v16->mOption1Text, option1Text);
  v16->mOption2Msg = option2Msg;
  UFG::qString::Set(&v16->mOption2Text, option2Text);
  v16->mFullScreen = fullscreen;
  v16->mHorizontalResolution = (int)gUIHorizontalResolution;
  v16->mVerticalResolution = (int)gUIVerticalResolution;
  v17 = UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManager::s_instance, v16->mFlashFile.mData, -1);
  v17->m_commandData = v16;
  return LODWORD(v17[4].mPrev);
}

// File Line: 372
// RVA: 0x61F820
__int64 __fastcall UFG::UIScreenDialogBox::createThreeButtonDialog(
        UFG::UIScreen *owner,
        const char *titleText,
        const char *bodyText,
        const char *option1Text,
        unsigned int option1Msg,
        const char *option2Text,
        unsigned int option2Msg,
        const char *option3Text,
        unsigned int option3Msg,
        UFG::UIScreenDialogBox::eDefaultButton defaultButton,
        const char *flashFile)
{
  UFG::allocator::free_link *v15; // rax
  UFG::UIScreenDialogBox::UIScreenDialogBoxData *v16; // rax
  UFG::UIScreenDialogBox::UIScreenDialogBoxData *v17; // rbx
  UFG::UICommand *v18; // rax

  v15 = UFG::qMemoryPool::Allocate(
          &gScaleformMemoryPool,
          0x128ui64,
          "UIScreenDialogBox::createThreeButtonDialog",
          0i64,
          1u);
  if ( v15 )
  {
    UFG::UIScreenDialogBox::UIScreenDialogBoxData::UIScreenDialogBoxData((UFG::UIScreenDialogBox::UIScreenDialogBoxData *)v15);
    v17 = v16;
  }
  else
  {
    v17 = 0i64;
  }
  UFG::qString::Set(&v17->mFlashFile, flashFile);
  v17->mNumOptions = 3;
  v17->mOwner = owner;
  UFG::qString::Set(&v17->mTitleText, titleText);
  UFG::qString::Set(&v17->mBodyText, bodyText);
  v17->mDefaultButton = defaultButton;
  v17->mOption1Msg = option1Msg;
  UFG::qString::Set(&v17->mOption1Text, option1Text);
  v17->mOption2Msg = option2Msg;
  UFG::qString::Set(&v17->mOption2Text, option2Text);
  v17->mOption3Msg = option3Msg;
  UFG::qString::Set(&v17->mOption3Text, option3Text);
  v17->mHorizontalResolution = (int)gUIHorizontalResolution;
  v17->mVerticalResolution = (int)gUIVerticalResolution;
  v18 = UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManager::s_instance, v17->mFlashFile.mData, -1);
  v18->m_commandData = v17;
  return LODWORD(v18[4].mPrev);
}

