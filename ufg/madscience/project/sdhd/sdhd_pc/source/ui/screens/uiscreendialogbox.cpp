// File Line: 19
// RVA: 0x1569950
__int64 dynamic_initializer_for__UIHASH_SELECT__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("select", 0xFFFFFFFF);
  UIHASH_SELECT = result;
  return result;
}

// File Line: 20
// RVA: 0x156A250
__int64 dynamic_initializer_for__UI_DIALOG_HELP_BAR__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("UI_DIALOG", 0xFFFFFFFF);
  UI_DIALOG_HELP_BAR = result;
  return result;
}

// File Line: 30
// RVA: 0x5C8A90
void __fastcall UFG::UIScreenDialogBox::UIScreenDialogBox(UFG::UIScreenDialogBox *this)
{
  UFG::UIScreenDialogBox *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreenDialogBox::`vftable;
  UFG::UIScreenDialogBox::UIScreenDialogBoxData::UIScreenDialogBoxData(&this->mData);
  v1->mState = 0;
  ++UFG::UIScreenDialogBox::m_iDialogBoxRefCount;
}

// File Line: 38
// RVA: 0x5CE3A0
void __fastcall UFG::UIScreenDialogBox::~UIScreenDialogBox(UFG::UIScreenDialogBox *this)
{
  UFG::UIScreenDialogBox *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreenDialogBox::`vftable;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
    UFG::UIHKHelpBarWidget::Hide(&UFG::UIHKScreenGlobalOverlay::mThis->HelpBar, UI_DIALOG_HELP_BAR);
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_DIALOG_BOX_DISAPPEAR_3,
    0xFFFFFFFF);
  --UFG::UIScreenDialogBox::m_iDialogBoxRefCount;
  UFG::UIScreenDialogBox::UIScreenDialogBoxData::~UIScreenDialogBoxData(&v1->mData);
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 56
// RVA: 0x637F40
void __fastcall UFG::UIScreenDialogBox::init(UFG::UIScreenDialogBox *this, UFG::UICommandData *data)
{
  UFG::UICommandData *v2; // rdi
  UFG::UIScreenDialogBox *v3; // rsi
  UFG::UIHKHelpBarWidget *v4; // r14
  unsigned int v5; // ebx
  Scaleform::GFx::Movie *v6; // r14
  double v7; // xmm6_8
  __int64 v8; // rbx
  __int64 v9; // rbx
  __int64 v10; // rbx
  double v11; // xmm6_8
  char v12; // bl
  double v13; // xmm6_8
  double v14; // xmm6_8
  long double v15; // rbx
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-B8h]
  char ptr; // [rsp+60h] [rbp-88h]
  double v18; // [rsp+68h] [rbp-80h]
  __int64 v19; // [rsp+70h] [rbp-78h]
  unsigned int v20; // [rsp+78h] [rbp-70h]
  __int64 v21; // [rsp+88h] [rbp-60h]
  unsigned int v22; // [rsp+90h] [rbp-58h]
  __int64 v23; // [rsp+98h] [rbp-50h]
  char v24; // [rsp+A8h] [rbp-40h]
  __int64 v25; // [rsp+B8h] [rbp-30h]
  unsigned int v26; // [rsp+C0h] [rbp-28h]
  __int64 v27; // [rsp+C8h] [rbp-20h]
  char v28; // [rsp+D8h] [rbp-10h]
  __int64 v29; // [rsp+E8h] [rbp+0h]
  unsigned int v30; // [rsp+F0h] [rbp+8h]
  __int64 v31; // [rsp+F8h] [rbp+10h]
  char v32; // [rsp+108h] [rbp+20h]
  __int64 v33; // [rsp+118h] [rbp+30h]
  unsigned int v34; // [rsp+120h] [rbp+38h]
  double v35; // [rsp+128h] [rbp+40h]
  char v36; // [rsp+138h] [rbp+50h]
  __int64 v37; // [rsp+148h] [rbp+60h]
  unsigned int v38; // [rsp+150h] [rbp+68h]
  __int64 v39; // [rsp+158h] [rbp+70h]
  char v40; // [rsp+168h] [rbp+80h]
  __int64 v41; // [rsp+178h] [rbp+90h]
  unsigned int v42; // [rsp+180h] [rbp+98h]
  double v43; // [rsp+188h] [rbp+A0h]
  char v44; // [rsp+198h] [rbp+B0h]
  __int64 v45; // [rsp+1A8h] [rbp+C0h]
  unsigned int v46; // [rsp+1B0h] [rbp+C8h]
  double v47; // [rsp+1B8h] [rbp+D0h]
  __int64 v48; // [rsp+1C8h] [rbp+E0h]
  UFG::UIHKHelpBarData dataa; // [rsp+1D8h] [rbp+F0h]

  v48 = -2i64;
  v2 = data;
  v3 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  UFG::UIScreenManagerBase::queueMessage(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    UI_HASH_DIALOG_BOX_APPEAR_3,
    0xFFFFFFFF);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v4 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v5 = UI_DIALOG_HELP_BAR;
    UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
    dataa.id = v5;
    dataa.priority = 0;
    dataa.alignment = 1;
    _mm_store_si128((__m128i *)dataa.Buttons, (__m128i)0i64);
    *(_QWORD *)&dataa.Buttons[4] = 0i64;
    UFG::qString::Set(dataa.Captions, &customWorldMapCaption);
    UFG::qString::Set(&dataa.Captions[1], &customWorldMapCaption);
    UFG::qString::Set(&dataa.Captions[2], &customWorldMapCaption);
    UFG::qString::Set(&dataa.Captions[3], &customWorldMapCaption);
    UFG::qString::Set(&dataa.Captions[4], &customWorldMapCaption);
    UFG::qString::Set(&dataa.Captions[5], &customWorldMapCaption);
    *(_QWORD *)dataa.MessageIds = 0i64;
    *(_QWORD *)&dataa.MessageIds[2] = 0i64;
    *(_QWORD *)&dataa.MessageIds[4] = 0i64;
    UFG::UIHKHelpBarWidget::Show(v4, &dataa);
    UFG::qString::~qString(&dataa.CustomTexturePack);
    `eh vector destructor iterator(dataa.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(dataa.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  }
  v3->mState = 1;
  v6 = v3->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v7 = (double)SLODWORD(v2[2].vfptr);
  if ( (v20 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v19 + 16i64))(
      v19,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v18));
    v19 = 0i64;
  }
  v20 = 5;
  v18 = v7;
  v8 = (__int64)v2[18].vfptr;
  if ( (v22 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v21 + 16i64))(v21, &v20, v23);
    v21 = 0i64;
  }
  v22 = 6;
  v23 = v8;
  v9 = (__int64)v2[23].vfptr;
  if ( (v26 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v25 + 16i64))(v25, &v24, v27);
    v25 = 0i64;
  }
  v26 = 6;
  v27 = v9;
  v10 = (__int64)v2[28].vfptr;
  if ( (v30 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v29 + 16i64))(v29, &v28, v31);
    v29 = 0i64;
  }
  v30 = 6;
  v31 = v10;
  v11 = (double)SHIDWORD(v2[2].vfptr);
  if ( (v34 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v33 + 16i64))(
      v33,
      &v32,
      COERCE_DOUBLE(*(_QWORD *)&v35));
    v33 = 0i64;
  }
  v34 = 5;
  v35 = v11;
  v12 = BYTE4(v2[30].vfptr);
  if ( (v38 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v37 + 16i64))(v37, &v36, v39);
    v37 = 0i64;
  }
  v38 = 2;
  LOBYTE(v39) = v12;
  v13 = (double)SLODWORD(v2[36].vfptr);
  if ( (v42 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v41 + 16i64))(
      v41,
      &v40,
      COERCE_DOUBLE(*(_QWORD *)&v43));
    v41 = 0i64;
  }
  v42 = 5;
  v43 = v13;
  v14 = (double)SHIDWORD(v2[36].vfptr);
  if ( (v46 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v45 + 16i64))(
      v45,
      &v44,
      COERCE_DOUBLE(*(_QWORD *)&v47));
    v45 = 0i64;
  }
  v46 = 5;
  v47 = v14;
  Scaleform::GFx::Movie::Invoke(v6, "setOptions", 0i64, (Scaleform::GFx::Value *)&ptr, 8u);
  pargs.pObjectInterface = 0i64;
  pargs.Type = 0;
  v15 = *(double *)&v2[11].vfptr;
  pargs.Type = 6;
  pargs.mValue.NValue = v15;
  Scaleform::GFx::Movie::Invoke(v6, "setBodyText", 0i64, &pargs, 1u);
  UFG::UIScreenDialogBox::UIScreenDialogBoxData::operator=(
    &v3->mData,
    (UFG::UIScreenDialogBox::UIScreenDialogBoxData *)v2);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 0;
  `eh vector destructor iterator(&ptr, 0x30ui64, 8, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 109
// RVA: 0x62F670
bool __fastcall UFG::UIScreenDialogBox::handleMessage(UFG::UIScreenDialogBox *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIScreenDialogBox *v3; // rbx
  UFG::UIMessage *v4; // rsi
  unsigned int v5; // edi
  __int32 v6; // ecx
  int v7; // eax
  UFG::UIScreen *v8; // rcx
  unsigned int v9; // edi
  int v10; // eax
  int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // edx

  v3 = this;
  v4 = msg;
  v5 = msgId;
  v6 = this->mState - 1;
  if ( v6 )
  {
    if ( v6 == 1 && msgId == UIHASH_SELECT )
    {
      v7 = atol(*(const char **)&msg[1].m_commandType);
      v8 = v3->mData.mOwner;
      v9 = -1;
      if ( v8 )
        v9 = v8->mScreenUID;
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
              v13 = v3->mScreenUID;
              v3->mState = 0;
              UFG::UIScreenManagerBase::queuePopScreen(
                (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                v13);
              return 1;
            }
            v12 = v3->mData.mOption3Msg;
          }
          else
          {
            v12 = v3->mData.mOption2Msg;
          }
        }
        else
        {
          v12 = v3->mData.mOption1Msg;
        }
      }
      else
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xA4E5BFBD,
            0i64,
            0,
            0i64);
        v12 = UI_HASH_DIALOG_CANCEL_30;
      }
      UFG::UIScreenManagerBase::queueMessage(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        v12,
        v9);
      goto LABEL_17;
    }
  }
  else
  {
    if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
      || msgId == UI_HASH_DPAD_UP_REPEAT_30
      || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
    {
      UFG::UIScreen::invoke((UFG::UIScreen *)&v3->vfptr, "scrollLeft");
      if ( v3->mData.mNumOptions > 1 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xC415B16F,
            0i64,
            0,
            0i64);
      }
    }
    if ( v5 == UI_HASH_DPAD_DOWN_PRESSED_30
      || v5 == UI_HASH_DPAD_DOWN_REPEAT_30
      || v5 == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
    {
      UFG::UIScreen::invoke((UFG::UIScreen *)&v3->vfptr, "scrollRight");
      if ( v3->mData.mNumOptions > 1 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xC415B16F,
            0i64,
            0,
            0i64);
      }
    }
    if ( v5 == UI_HASH_MOUSE_MOVE_30 )
    {
      UFG::UIScreenDialogBox::Flash_handleMouseMove(v3, (float)SLODWORD(v4[1].vfptr), (float)SHIDWORD(v4[1].vfptr));
    }
    else if ( v5 == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
    {
      UFG::UIScreenDialogBox::Flash_handleMouseClick(v3, (float)SLODWORD(v4[1].vfptr), (float)SHIDWORD(v4[1].vfptr));
    }
    if ( v5 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 || v5 == UI_HASH_LIST_OPTION_SELECTED_30 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x4A3D1F6Cu,
          0i64,
          0,
          0i64);
      UFG::UIScreen::invoke((UFG::UIScreen *)&v3->vfptr, "accept");
      v3->mState = 2;
    }
  }
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
}

// File Line: 208
// RVA: 0x5E63D0
void __fastcall UFG::UIScreenDialogBox::Flash_handleMouseMove(UFG::UIScreenDialogBox *this, float mouseX, float mouseY)
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
    Scaleform::GFx::Movie::Invoke(v3, "handleMouseMove", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 222
// RVA: 0x5E6150
void __fastcall UFG::UIScreenDialogBox::Flash_handleMouseClick(UFG::UIScreenDialogBox *this, float mouseX, float mouseY)
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
    Scaleform::GFx::Movie::Invoke(v3, "handleMouseClick", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 257
// RVA: 0x61F470
__int64 __fastcall UFG::UIScreenDialogBox::createOKDialog(UFG::UIScreen *owner, const char *titleText, const char *bodyText, bool fullscreen)
{
  bool v4; // bl
  const char *v5; // rdi
  const char *v6; // rsi
  UFG::UIScreen *v7; // rbp
  unsigned int v8; // ebx
  UFG::qString v10; // [rsp+48h] [rbp-30h]

  v4 = fullscreen;
  v5 = bodyText;
  v6 = titleText;
  v7 = owner;
  UFG::qString::qString(&v10, "$COMMON_OK_UPPERCASE");
  v8 = UFG::UIScreenDialogBox::createOneButtonDialog(v7, v6, v5, v10.mData, UI_HASH_DIALOG_OK_30, v4, "DialogBox");
  UFG::qString::~qString(&v10);
  return v8;
}

// File Line: 272
// RVA: 0x61FAB0
__int64 __fastcall UFG::UIScreenDialogBox::createYesNoDialog(UFG::UIScreen *owner, const char *titleText, const char *bodyText, bool defaultYes, bool fullscreen)
{
  bool v5; // bl
  const char *v6; // rdi
  const char *v7; // rsi
  UFG::UIScreen *v8; // rbp
  unsigned int v9; // ebx
  UFG::qString option2Text; // [rsp+58h] [rbp-60h]
  UFG::qString v12; // [rsp+80h] [rbp-38h]

  v5 = defaultYes;
  v6 = bodyText;
  v7 = titleText;
  v8 = owner;
  UFG::qString::qString(&v12, "$OPTIONS_YES");
  UFG::qString::qString(&option2Text, "$OPTIONS_NO");
  v9 = UFG::UIScreenDialogBox::createTwoButtonDialog(
         v8,
         v7,
         v6,
         v12.mData,
         UI_HASH_DIALOG_YES_30,
         option2Text.mData,
         UI_HASH_DIALOG_NO_30,
         (UFG::UIScreenDialogBox::eDefaultButton)(2 - (v5 != 0)),
         fullscreen,
         "DialogBox");
  UFG::qString::~qString(&option2Text);
  UFG::qString::~qString(&v12);
  return v9;
}

// File Line: 289
// RVA: 0x61FB90
__int64 __fastcall UFG::UIScreenDialogBox::createZeroButtonDialog(UFG::UIScreen *owner, const char *titleText, const char *bodyText, bool fullscreen, const char *flashFile)
{
  bool v5; // di
  const char *v6; // rsi
  const char *v7; // rbp
  UFG::UIScreen *v8; // r14
  UFG::allocator::free_link *v9; // rax
  __int64 v10; // rax
  __int64 v11; // rbx
  UFG::UICommand *v12; // rax

  v5 = fullscreen;
  v6 = bodyText;
  v7 = titleText;
  v8 = owner;
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
  *(_QWORD *)(v11 + 8) = v8;
  UFG::qString::Set((UFG::qString *)(v11 + 24), v7);
  UFG::qString::Set((UFG::qString *)(v11 + 64), v6);
  *(_BYTE *)(v11 + 244) = v5;
  *(_DWORD *)(v11 + 288) = (signed int)gUIHorizontalResolution;
  *(_DWORD *)(v11 + 292) = (signed int)gUIVerticalResolution;
  v12 = UFG::UIScreenManagerBase::queuePushScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          *(const char **)(v11 + 272),
          -1);
  v12->m_commandData = (UFG::UICommandData *)v11;
  return LODWORD(v12[4].mPrev);
}

// File Line: 312
// RVA: 0x61F500
__int64 __fastcall UFG::UIScreenDialogBox::createOneButtonDialog(UFG::UIScreen *owner, const char *titleText, const char *bodyText, const char *optionText, unsigned int optionMsg, bool fullscreen, const char *flashFile)
{
  const char *v7; // rdi
  const char *v8; // rsi
  const char *v9; // rbp
  UFG::UIScreen *v10; // r14
  UFG::allocator::free_link *v11; // rax
  __int64 v12; // rax
  __int64 v13; // rbx
  UFG::UICommand *v14; // rax

  v7 = optionText;
  v8 = bodyText;
  v9 = titleText;
  v10 = owner;
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
  *(_QWORD *)(v13 + 8) = v10;
  UFG::qString::Set((UFG::qString *)(v13 + 24), v9);
  UFG::qString::Set((UFG::qString *)(v13 + 64), v8);
  *(_DWORD *)(v13 + 20) = 1;
  *(_DWORD *)(v13 + 104) = optionMsg;
  UFG::qString::Set((UFG::qString *)(v13 + 120), v7);
  *(_BYTE *)(v13 + 244) = fullscreen;
  *(_DWORD *)(v13 + 288) = (signed int)gUIHorizontalResolution;
  *(_DWORD *)(v13 + 292) = (signed int)gUIVerticalResolution;
  v14 = UFG::UIScreenManagerBase::queuePushScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          *(const char **)(v13 + 272),
          -1);
  v14->m_commandData = (UFG::UICommandData *)v13;
  return LODWORD(v14[4].mPrev);
}

// File Line: 340
// RVA: 0x61F970
__int64 __fastcall UFG::UIScreenDialogBox::createTwoButtonDialog(UFG::UIScreen *owner, const char *titleText, const char *bodyText, const char *option1Text, unsigned int option1Msg, const char *option2Text, unsigned int option2Msg, UFG::UIScreenDialogBox::eDefaultButton defaultButton, bool fullscreen, const char *flashFile)
{
  const char *v10; // rdi
  const char *v11; // rsi
  const char *v12; // rbp
  UFG::UIScreen *v13; // r14
  UFG::allocator::free_link *v14; // rax
  UFG::UIScreenDialogBox::UIScreenDialogBoxData *v15; // rax
  UFG::UIScreenDialogBox::UIScreenDialogBoxData *v16; // rbx
  UFG::UICommand *v17; // rax

  v10 = option1Text;
  v11 = bodyText;
  v12 = titleText;
  v13 = owner;
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
  v16->mOwner = v13;
  UFG::qString::Set(&v16->mTitleText, v12);
  UFG::qString::Set(&v16->mBodyText, v11);
  v16->mDefaultButton = defaultButton;
  v16->mOption1Msg = option1Msg;
  UFG::qString::Set(&v16->mOption1Text, v10);
  v16->mOption2Msg = option2Msg;
  UFG::qString::Set(&v16->mOption2Text, option2Text);
  v16->mFullScreen = fullscreen;
  v16->mHorizontalResolution = (signed int)gUIHorizontalResolution;
  v16->mVerticalResolution = (signed int)gUIVerticalResolution;
  v17 = UFG::UIScreenManagerBase::queuePushScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v16->mFlashFile.mData,
          -1);
  v17->m_commandData = (UFG::UICommandData *)&v16->vfptr;
  return LODWORD(v17[4].mPrev);
}

// File Line: 372
// RVA: 0x61F820
__int64 __fastcall UFG::UIScreenDialogBox::createThreeButtonDialog(UFG::UIScreen *owner, const char *titleText, const char *bodyText, const char *option1Text, unsigned int option1Msg, const char *option2Text, unsigned int option2Msg, const char *option3Text, unsigned int option3Msg, UFG::UIScreenDialogBox::eDefaultButton defaultButton, const char *flashFile)
{
  const char *v11; // rdi
  const char *v12; // rsi
  const char *v13; // rbp
  UFG::UIScreen *v14; // r14
  UFG::allocator::free_link *v15; // rax
  UFG::UIScreenDialogBox::UIScreenDialogBoxData *v16; // rax
  UFG::UIScreenDialogBox::UIScreenDialogBoxData *v17; // rbx
  UFG::UICommand *v18; // rax

  v11 = option1Text;
  v12 = bodyText;
  v13 = titleText;
  v14 = owner;
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
  v17->mOwner = v14;
  UFG::qString::Set(&v17->mTitleText, v13);
  UFG::qString::Set(&v17->mBodyText, v12);
  v17->mDefaultButton = defaultButton;
  v17->mOption1Msg = option1Msg;
  UFG::qString::Set(&v17->mOption1Text, v11);
  v17->mOption2Msg = option2Msg;
  UFG::qString::Set(&v17->mOption2Text, option2Text);
  v17->mOption3Msg = option3Msg;
  UFG::qString::Set(&v17->mOption3Text, option3Text);
  v17->mHorizontalResolution = (signed int)gUIHorizontalResolution;
  v17->mVerticalResolution = (signed int)gUIVerticalResolution;
  v18 = UFG::UIScreenManagerBase::queuePushScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v17->mFlashFile.mData,
          -1);
  v18->m_commandData = (UFG::UICommandData *)&v17->vfptr;
  return LODWORD(v18[4].mPrev);
}

