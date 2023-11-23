// File Line: 30
// RVA: 0x5C5070
void __fastcall UFG::UIHKScreenDialogPopup::UIHKScreenDialogPopup(UFG::UIHKScreenDialogPopup *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDialogPopup::`vftable;
  this->mOwner = 0i64;
  *(_QWORD *)&this->mOptionMsgAccept = 0i64;
}

// File Line: 35
// RVA: 0x5CA8D0
void __fastcall UFG::UIHKScreenDialogPopup::~UIHKScreenDialogPopup(UFG::UIHKScreenDialogPopup *this)
{
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v3; // eax
  UFG::UIScreenTextureManager *v4; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDialogPopup::`vftable;
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v3 = UFG::qStringHash32("DialogPopup", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v3);
  }
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v4, "DialogPopup");
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 46
// RVA: 0x6307B0
void __fastcall UFG::UIHKScreenDialogPopup::init(UFG::UIHKScreenDialogPopup *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenGlobalOverlay *v4; // rax
  unsigned int v5; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v7; // rsi
  Scaleform::GFx::Movie *pObject; // r14
  char *mData; // rbx
  UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *mEntries; // rax
  UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *p_mNext; // rbx
  Scaleform::GFx::Value::ValueUnion mPrev; // rsi
  Scaleform::GFx::Value pargs; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-88h] BYREF
  int v15; // [rsp+90h] [rbp-58h]
  char *v16; // [rsp+98h] [rbp-50h]
  char v17[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v18; // [rsp+B8h] [rbp-30h]
  int v19; // [rsp+C0h] [rbp-28h]
  const char *v20; // [rsp+C8h] [rbp-20h]
  char v21[16]; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v22; // [rsp+E8h] [rbp+0h]
  int v23; // [rsp+F0h] [rbp+8h]
  const char *v24; // [rsp+F8h] [rbp+10h]
  char v25[16]; // [rsp+108h] [rbp+20h] BYREF
  __int64 v26; // [rsp+118h] [rbp+30h]
  int v27; // [rsp+120h] [rbp+38h]
  const char *v28; // [rsp+128h] [rbp+40h]
  __int64 v29; // [rsp+138h] [rbp+50h]
  UFG::qString v30; // [rsp+140h] [rbp+58h] BYREF
  UFG::qString result; // [rsp+168h] [rbp+80h] BYREF
  UFG::UIHKHelpBarData dataa; // [rsp+198h] [rbp+B0h] BYREF

  v29 = -2i64;
  UFG::UIScreen::init(this, data);
  UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
  dataa.id = UFG::qStringHash32("DialogPopup", 0xFFFFFFFF);
  *(_QWORD *)&dataa.priority = 0i64;
  v4 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v4 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v4->HelpBar, &dataa);
  this->mOwner = (UFG::UIScreen *)data[1].vfptr;
  this->mEntries = (UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *)data[2].vfptr;
  this->mOptionMsgAccept = (unsigned int)data[8].vfptr;
  this->mOptionMsgCancel = HIDWORD(data[8].vfptr);
  v5 = UFG::qStringHashUpper32("HUD_SOCIAL_CH_PPL", -1);
  m_translator = UFG::UIScreenManager::s_instance->m_translator;
  if ( !m_translator || (v7 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v5)) == 0i64 )
    v7 = "HUD_SOCIAL_CH_PPL";
  UFG::qString::qString(&v30, (UFG::qString *)&data[3]);
  UFG::qString::FormatEx(&result, "%s %s", v7, v30.mData);
  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.pNext);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.pNext = (Scaleform::GFx::Value *)"$HUD_SOCIAL_CH_NEW";
  mData = result.mData;
  if ( (v15 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, char *))(*(_QWORD *)ptr.DataAux + 16i64))(
      ptr.DataAux,
      &ptr.Type,
      v16);
    ptr.DataAux = 0i64;
  }
  v15 = 6;
  v16 = mData;
  if ( (v19 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v18 + 16i64))(v18, v17, v20);
    v18 = 0i64;
  }
  v19 = 6;
  v20 = "$HUD_SOCIAL_CH_SELECT";
  if ( (v23 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v22 + 16i64))(v22, v21, v24);
    v22 = 0i64;
  }
  v23 = 6;
  v24 = "$HUD_SOCIAL_CH_CHALLENGE";
  if ( (v27 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v26 + 16i64))(v26, v25, v28);
    v26 = 0i64;
  }
  v27 = 6;
  v28 = "$HUD_SOCIAL_CH_CANCEL";
  Scaleform::GFx::Movie::Invoke(pObject, "InitView", 0i64, &ptr, 5u);
  mEntries = this->mEntries;
  p_mNext = (UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *)&mEntries->mNode.mNext[-1].mNext;
  if ( p_mNext != (UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *)&mEntries[-1].mNode.mNext )
  {
    do
    {
      `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      mPrev = (Scaleform::GFx::Value::ValueUnion)p_mNext[3].mNode.mPrev;
      if ( (pargs.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = VT_String;
      pargs.mValue = mPrev;
      Scaleform::GFx::Movie::Invoke(pObject, "DialogPopupList_AddItem", 0i64, &pargs, 1u);
      `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      p_mNext = (UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *)&p_mNext[1].mNode.mPrev[-1].mNext;
    }
    while ( p_mNext != (UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *)((char *)this->mEntries - 8) );
  }
  Scaleform::GFx::Movie::Invoke(pObject, "DialogPopupList_Refresh", 0i64, 0i64, 0);
  `eh vector destructor iterator(&ptr, 0x30ui64, 5, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v30);
  UFG::qString::~qString(&dataa.CustomTexturePack);
  `eh vector destructor iterator(dataa.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(dataa.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 94
// RVA: 0x622720
char __fastcall UFG::UIHKScreenDialogPopup::handleMessage(
        UFG::UIHKScreenDialogPopup *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *pObject; // r14
  int NValue; // ecx
  UFG::qList<UFG::DialogPopupEntry,UFG::DialogPopupEntry,1,0> *mEntries; // rdx
  __int64 p_mNext; // rbx
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> **v11; // rdx
  char v12; // bl
  const char *v13; // rdx
  Scaleform::GFx::Value ptr; // [rsp+38h] [rbp-80h] BYREF
  Scaleform::GFx::Value pval; // [rsp+68h] [rbp-50h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    UFG::UIScreenManagerBase::queueMessage(
      UFG::UIScreenManager::s_instance,
      this->mOptionMsgCancel,
      this->mOwner->mScreenUID);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
    goto LABEL_4;
  }
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
    || msgId == UI_HASH_DPAD_UP_REPEAT_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
  {
    v13 = "DialogPopupList_ScrollPrev";
LABEL_27:
    Scaleform::GFx::Movie::Invoke(pObject, v13, 0i64, 0i64, 0);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
    return UFG::UIScreen::handleMessage(this, msgId, msg);
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
    pval.Type = VT_Undefined;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gIndex");
    NValue = (int)pval.mValue.NValue;
    mEntries = this->mEntries;
    p_mNext = (__int64)&mEntries->mNode.mNext[-1].mNext;
    if ( (int)pval.mValue.NValue > 0 )
    {
      v11 = &mEntries[-1].mNode.mNext;
      do
      {
        if ( (UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> **)p_mNext == v11 )
          break;
        --NValue;
        p_mNext = *(_QWORD *)(p_mNext + 16) - 8i64;
      }
      while ( NValue > 0 );
    }
    *(_BYTE *)(p_mNext + 64) = *(_BYTE *)(p_mNext + 64) == 0;
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v12 = *(_BYTE *)(p_mNext + 64);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Boolean;
    ptr.mValue.BValue = v12;
    Scaleform::GFx::Movie::Invoke(pObject, "DialogPopupList_CheckBox", 0i64, &ptr, 1u);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xF41B2F0D, 0i64, 0, 0i64);
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    if ( (pval.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
      pval.pObjectInterface = 0i64;
    }
    pval.Type = VT_Undefined;
  }
  else if ( msgId == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
  {
    UFG::UIScreenManagerBase::queueMessage(
      UFG::UIScreenManager::s_instance,
      this->mOptionMsgAccept,
      this->mOwner->mScreenUID);
LABEL_4:
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
    return 1;
  }
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

// File Line: 171
// RVA: 0x61F380
void __fastcall UFG::UIHKScreenDialogPopup::createDialog(
        UFG::allocator::free_link *owner,
        UFG::allocator::free_link *entries,
        const char *caption,
        unsigned int optionMsgAccept,
        unsigned int optionMsgCancel)
{
  UFG::allocator::free_link *v9; // rbx

  v9 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x48ui64, "UIHKScreenDialogPopup", 0i64, 1u);
  if ( v9 )
  {
    v9->mNext = (UFG::allocator::free_link *)&UFG::UICommandData::`vftable;
    v9->mNext = (UFG::allocator::free_link *)&UFG::UIHKScreenDialogPopup::UIHKScreenDialogPopupData::`vftable;
    v9[1].mNext = 0i64;
    v9[2].mNext = 0i64;
    UFG::qString::qString((UFG::qString *)&v9[3]);
    v9[8].mNext = 0i64;
  }
  else
  {
    v9 = 0i64;
  }
  v9[1].mNext = owner;
  v9[2].mNext = entries;
  UFG::qString::Set((UFG::qString *)&v9[3], caption);
  LODWORD(v9[8].mNext) = optionMsgAccept;
  HIDWORD(v9[8].mNext) = optionMsgCancel;
  UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManager::s_instance, "DialogPopup", -1)->m_commandData = (UFG::UICommandData *)v9;
}

