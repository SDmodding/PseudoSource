// File Line: 30
// RVA: 0x5C5070
void __fastcall UFG::UIHKScreenDialogPopup::UIHKScreenDialogPopup(UFG::UIHKScreenDialogPopup *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDialogPopup::`vftable';
  this->mOwner = 0i64;
  *(_QWORD *)&this->mOptionMsgAccept = 0i64;
}

// File Line: 35
// RVA: 0x5CA8D0
void __fastcall UFG::UIHKScreenDialogPopup::~UIHKScreenDialogPopup(UFG::UIHKScreenDialogPopup *this)
{
  UFG::UIHKScreenDialogPopup *v1; // rbx
  UFG::UIHKHelpBarWidget *v2; // rdi
  unsigned int v3; // eax
  UFG::UIScreenTextureManager *v4; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDialogPopup::`vftable';
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v2 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v3 = UFG::qStringHash32("DialogPopup", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(v2, v3);
  }
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v4, "DialogPopup");
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 46
// RVA: 0x6307B0
void __fastcall UFG::UIHKScreenDialogPopup::init(UFG::UIHKScreenDialogPopup *this, UFG::UICommandData *data)
{
  UFG::UICommandData *v2; // rbx
  UFG::UIHKScreenDialogPopup *v3; // rdi
  UFG::UIHKScreenGlobalOverlay *v4; // rax
  unsigned int v5; // eax
  UFG::UIGfxTranslator *v6; // rcx
  const char *v7; // rsi
  Scaleform::GFx::Movie *v8; // r14
  char *v9; // rbx
  UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *v10; // rax
  signed __int64 v11; // rbx
  long double v12; // rsi
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-B8h]
  char ptr; // [rsp+60h] [rbp-88h]
  const char *v15; // [rsp+68h] [rbp-80h]
  __int64 v16; // [rsp+70h] [rbp-78h]
  unsigned int v17; // [rsp+78h] [rbp-70h]
  __int64 v18; // [rsp+88h] [rbp-60h]
  unsigned int v19; // [rsp+90h] [rbp-58h]
  char *v20; // [rsp+98h] [rbp-50h]
  char v21; // [rsp+A8h] [rbp-40h]
  __int64 v22; // [rsp+B8h] [rbp-30h]
  unsigned int v23; // [rsp+C0h] [rbp-28h]
  const char *v24; // [rsp+C8h] [rbp-20h]
  char v25; // [rsp+D8h] [rbp-10h]
  __int64 v26; // [rsp+E8h] [rbp+0h]
  unsigned int v27; // [rsp+F0h] [rbp+8h]
  const char *v28; // [rsp+F8h] [rbp+10h]
  char v29; // [rsp+108h] [rbp+20h]
  __int64 v30; // [rsp+118h] [rbp+30h]
  unsigned int v31; // [rsp+120h] [rbp+38h]
  const char *v32; // [rsp+128h] [rbp+40h]
  __int64 v33; // [rsp+138h] [rbp+50h]
  UFG::qString v34; // [rsp+140h] [rbp+58h]
  UFG::qString result; // [rsp+168h] [rbp+80h]
  UFG::UIHKHelpBarData dataa; // [rsp+198h] [rbp+B0h]

  v33 = -2i64;
  v2 = data;
  v3 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
  dataa.id = UFG::qStringHash32("DialogPopup", 0xFFFFFFFF);
  *(_QWORD *)&dataa.priority = 0i64;
  v4 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v4 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v4->HelpBar, &dataa);
  v3->mOwner = (UFG::UIScreen *)v2[1].vfptr;
  v3->mEntries = (UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *)v2[2].vfptr;
  v3->mOptionMsgAccept = (unsigned int)v2[8].vfptr;
  v3->mOptionMsgCancel = HIDWORD(v2[8].vfptr);
  v5 = UFG::qStringHashUpper32("HUD_SOCIAL_CH_PPL", 0xFFFFFFFF);
  v6 = UFG::UIScreenManager::s_instance->m_translator;
  if ( !v6 || (v7 = (const char *)v6->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, v5)) == 0i64 )
    v7 = "HUD_SOCIAL_CH_PPL";
  UFG::qString::qString(&v34, (UFG::qString *)&v2[3]);
  UFG::qString::FormatEx(&result, "%s %s", v7, v34.mData);
  v8 = v3->mRenderable->m_movie.pObject;
  `eh vector constructor iterator'(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v17 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v16 + 16i64))(v16, &ptr, v15);
    v16 = 0i64;
  }
  v17 = 6;
  v15 = "$HUD_SOCIAL_CH_NEW";
  v9 = result.mData;
  if ( (v19 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, unsigned int *, char *))(*(_QWORD *)v18 + 16i64))(v18, &v17, v20);
    v18 = 0i64;
  }
  v19 = 6;
  v20 = v9;
  if ( (v23 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v22 + 16i64))(v22, &v21, v24);
    v22 = 0i64;
  }
  v23 = 6;
  v24 = "$HUD_SOCIAL_CH_SELECT";
  if ( (v27 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v26 + 16i64))(v26, &v25, v28);
    v26 = 0i64;
  }
  v27 = 6;
  v28 = "$HUD_SOCIAL_CH_CHALLENGE";
  if ( (v31 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v30 + 16i64))(v30, &v29, v32);
    v30 = 0i64;
  }
  v31 = 6;
  v32 = "$HUD_SOCIAL_CH_CANCEL";
  Scaleform::GFx::Movie::Invoke(v8, "InitView", 0i64, (Scaleform::GFx::Value *)&ptr, 5u);
  v10 = v3->mEntries;
  v11 = (signed __int64)&v10->mNode.mNext[-1].mNext;
  if ( (UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> **)v11 != &v10[-1].mNode.mNext )
  {
    do
    {
      `eh vector constructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v12 = *(double *)(v11 + 48);
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = 6;
      pargs.mValue.NValue = v12;
      Scaleform::GFx::Movie::Invoke(v8, "DialogPopupList_AddItem", 0i64, &pargs, 1u);
      `eh vector destructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      v11 = *(_QWORD *)(v11 + 16) - 8i64;
    }
    while ( (UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> **)v11 != &v3->mEntries[-1].mNode.mNext );
  }
  Scaleform::GFx::Movie::Invoke(v8, "DialogPopupList_Refresh", 0i64, 0i64, 0);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v34);
  UFG::qString::~qString(&dataa.CustomTexturePack);
  `eh vector destructor iterator'(dataa.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator'(dataa.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 94
// RVA: 0x622720
char __fastcall UFG::UIHKScreenDialogPopup::handleMessage(UFG::UIHKScreenDialogPopup *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r15
  unsigned int v4; // esi
  UFG::UIHKScreenDialogPopup *v5; // rbp
  Scaleform::GFx::Movie *v6; // r14
  signed int v8; // ecx
  UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *v9; // rdx
  signed __int64 v10; // rbx
  signed __int64 v11; // rdx
  char v12; // bl
  const char *v13; // rdx
  char ptr; // [rsp+38h] [rbp-80h]
  __int64 v15; // [rsp+48h] [rbp-70h]
  unsigned int v16; // [rsp+50h] [rbp-68h]
  __int64 v17; // [rsp+58h] [rbp-60h]
  Scaleform::GFx::Value pval; // [rsp+68h] [rbp-50h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = this->mRenderable->m_movie.pObject;
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      this->mOptionMsgCancel,
      this->mOwner->mScreenUID);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xA4E5BFBD,
        0i64,
        0,
        0i64);
    goto LABEL_4;
  }
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
    || msgId == UI_HASH_DPAD_UP_REPEAT_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
  {
    v13 = "DialogPopupList_ScrollPrev";
LABEL_27:
    Scaleform::GFx::Movie::Invoke(v6, v13, 0i64, 0i64, 0);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC415B16F,
        0i64,
        0,
        0i64);
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30
    || msgId == UI_HASH_DPAD_DOWN_REPEAT_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
  {
    v13 = "DialogPopupList_ScrollNext";
    goto LABEL_27;
  }
  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    pval.pObjectInterface = 0i64;
    pval.Type = 0;
    Scaleform::GFx::Movie::GetVariable(v6, &pval, "gIndex");
    v8 = (signed int)pval.mValue.NValue;
    v9 = v5->mEntries;
    v10 = (signed __int64)&v9->mNode.mNext[-1].mNext;
    if ( (signed int)pval.mValue.NValue > 0 )
    {
      v11 = (signed __int64)&v9[-1].mNode.mNext;
      do
      {
        if ( v10 == v11 )
          break;
        --v8;
        v10 = *(_QWORD *)(v10 + 16) - 8i64;
      }
      while ( v8 > 0 );
    }
    *(_BYTE *)(v10 + 64) = *(_BYTE *)(v10 + 64) == 0;
    `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v12 = *(_BYTE *)(v10 + 64);
    if ( (v16 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, &ptr, v17);
      v15 = 0i64;
    }
    v16 = 2;
    LOBYTE(v17) = v12;
    Scaleform::GFx::Movie::Invoke(v6, "DialogPopupList_CheckBox", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xF41B2F0D,
        0i64,
        0,
        0i64);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    if ( ((unsigned int)pval.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
      pval.pObjectInterface = 0i64;
    }
    pval.Type = 0;
  }
  else if ( msgId == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
  {
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      this->mOptionMsgAccept,
      this->mOwner->mScreenUID);
LABEL_4:
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
    return 1;
  }
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
}

// File Line: 171
// RVA: 0x61F380
void __fastcall UFG::UIHKScreenDialogPopup::createDialog(UFG::UIScreen *owner, UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *entries, const char *caption, unsigned int optionMsgAccept, unsigned int optionMsgCancel)
{
  unsigned int v5; // esi
  const char *v6; // rbp
  UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *v7; // r14
  UFG::UIScreen *v8; // r15
  UFG::allocator::free_link *v9; // rbx

  v5 = optionMsgAccept;
  v6 = caption;
  v7 = entries;
  v8 = owner;
  v9 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x48ui64, "UIHKScreenDialogPopup", 0i64, 1u);
  if ( v9 )
  {
    v9->mNext = (UFG::allocator::free_link *)&UFG::UICommandData::`vftable';
    v9->mNext = (UFG::allocator::free_link *)&UFG::UIHKScreenDialogPopup::UIHKScreenDialogPopupData::`vftable';
    v9[1].mNext = 0i64;
    v9[2].mNext = 0i64;
    UFG::qString::qString((UFG::qString *)&v9[3]);
    v9[8].mNext = 0i64;
  }
  else
  {
    v9 = 0i64;
  }
  v9[1].mNext = (UFG::allocator::free_link *)v8;
  v9[2].mNext = (UFG::allocator::free_link *)v7;
  UFG::qString::Set((UFG::qString *)&v9[3], v6);
  LODWORD(v9[8].mNext) = v5;
  HIDWORD(v9[8].mNext) = optionMsgCancel;
  UFG::UIScreenManagerBase::queuePushScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    "DialogPopup",
    -1)->m_commandData = (UFG::UICommandData *)v9;
}

