// File Line: 38
// RVA: 0x5C4DF0
void __fastcall UFG::UIHKScreenDebugScreenList::UIHKScreenDebugScreenList(UFG::UIHKScreenDebugScreenList *this)
{
  UFG::allocator::free_link *v2; // rax
  UFG::UIListText *v3; // rdi

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDebugScreenList::`vftable;
  this->m_list = 0i64;
  v2 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x90ui64, "UIListText", 0i64, 1u);
  v3 = (UFG::UIListText *)v2;
  if ( v2 )
  {
    UFG::UIList::UIList((UFG::UIList *)v2, this);
    v3->vfptr = (UFG::UIWidgetVtbl *)&UFG::UIListText::`vftable;
  }
  else
  {
    v3 = 0i64;
  }
  this->m_list = v3;
}

// File Line: 52
// RVA: 0x630380
void __fastcall UFG::UIHKScreenDebugScreenList::init(UFG::UIHKScreenDebugScreenList *this, UFG::UICommandData *data)
{
  int v3; // edi
  Scaleform::GFx::Movie *pObject; // rcx
  const char **v5; // rsi
  UFG::allocator::free_link *v6; // rbx
  unsigned int v7; // r14d
  int v8; // eax
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-71h] BYREF
  UFG::qString v10; // [rsp+68h] [rbp-41h] BYREF
  int NValue; // [rsp+90h] [rbp-19h]
  __int16 v12; // [rsp+94h] [rbp-15h]
  __int64 v13; // [rsp+98h] [rbp-11h]
  UFG::qString text; // [rsp+A0h] [rbp-9h] BYREF

  v13 = -2i64;
  v3 = 0;
  UFG::UIScreen::init(this, data);
  pObject = this->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "list.numSlots");
  UFG::qString::qString(&v10);
  v12 = 257;
  NValue = (int)pval.mValue.NValue;
  UFG::qString::Set(&v10, "list");
  this->m_list->vfptr[1].__vecDelDtor(this->m_list, (unsigned int)&v10);
  v5 = gUIKnownScreens;
  do
  {
    v6 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x68ui64, "UIHKScreenDebugScreenList::UIItemText", 0i64, 1u);
    if ( v6 )
    {
      UFG::qString::qString(&text, *v5);
      v3 |= 1u;
      v7 = UI_HASH_MENU_OPTION_SELECTED_20;
      v8 = UFG::qStringHash32(text.mData, 0xFFFFFFFF);
      v6[1].mNext = v6 + 1;
      v6[2].mNext = v6 + 1;
      v6->mNext = (UFG::allocator::free_link *)&UFG::UIItem::`vftable;
      LODWORD(v6[3].mNext) = v8;
      v6[4].mNext = (UFG::allocator::free_link *)this;
      v6->mNext = (UFG::allocator::free_link *)&UFG::UIItemText::`vftable;
      UFG::qString::qString((UFG::qString *)&v6[5], &text);
      v6[10].mNext = v6 + 10;
      v6[11].mNext = v6 + 10;
      v6[12].mNext = 0i64;
      if ( v7 )
        LODWORD(v6[3].mNext) = v7;
    }
    else
    {
      v6 = 0i64;
    }
    if ( (v3 & 1) != 0 )
    {
      v3 &= ~1u;
      UFG::qString::~qString(&text);
    }
    this->m_list->vfptr->addItem(this->m_list, (UFG::UIItem *)v6);
    ++v5;
  }
  while ( (__int64)v5 < (__int64)&UFG::UIHKInfoPopupWidget::gHintReminderPeriod );
  this->m_list->vfptr->update(this->m_list);
  UFG::qString::~qString(&v10);
  if ( (pval.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
}

// File Line: 83
// RVA: 0x6224D0
bool __fastcall UFG::UIHKScreenDebugScreenList::handleMessage(
        UFG::UIHKScreenDebugScreenList *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIListText *m_list; // rcx
  UFG::UIScreenTextureManager *v8; // rax
  UFG::qString v9; // [rsp+28h] [rbp-30h] BYREF

  m_list = this->m_list;
  if ( m_list && m_list->vfptr->handleMessage(m_list, msg) )
    return 1;
  if ( msgId == UI_HASH_MENU_OPTION_SELECTED_20 )
  {
    UFG::qString::qString(&v9, (UFG::qString *)&this->m_list->m_selectedItem[1]);
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
    v8 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v8, v9.mData, 0i64);
    UFG::qString::~qString(&v9);
  }
  else if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
  }
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

