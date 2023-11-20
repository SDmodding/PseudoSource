// File Line: 38
// RVA: 0x5C4DF0
void __fastcall UFG::UIHKScreenDebugScreenList::UIHKScreenDebugScreenList(UFG::UIHKScreenDebugScreenList *this)
{
  UFG::UIHKScreenDebugScreenList *v1; // rbx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rdi

  v1 = this;
  v2 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDebugScreenList::`vftable';
  this->m_list = 0i64;
  v3 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x90ui64, "UIListText", 0i64, 1u);
  v4 = v3;
  if ( v3 )
  {
    UFG::UIList::UIList((UFG::UIList *)v3, (UFG::UIScreen *)&v1->vfptr);
    v4->mNext = (UFG::allocator::free_link *)&UFG::UIListText::`vftable';
  }
  else
  {
    v4 = 0i64;
  }
  v1->m_list = (UFG::UIListText *)v4;
}

// File Line: 52
// RVA: 0x630380
void __fastcall UFG::UIHKScreenDebugScreenList::init(UFG::UIHKScreenDebugScreenList *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenDebugScreenList *v2; // r15
  int v3; // edi
  Scaleform::GFx::Movie *v4; // rcx
  const char **v5; // rsi
  UFG::allocator::free_link *v6; // rbx
  unsigned int v7; // er14
  int v8; // eax
  UFG::allocator::free_link *v9; // rcx
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-71h]
  UFG::qString v11; // [rsp+68h] [rbp-41h]
  int v12; // [rsp+90h] [rbp-19h]
  __int16 v13; // [rsp+94h] [rbp-15h]
  __int64 v14; // [rsp+98h] [rbp-11h]
  UFG::qString text; // [rsp+A0h] [rbp-9h]
  UFG::allocator::free_link *v16; // [rsp+120h] [rbp+77h]

  v14 = -2i64;
  v2 = this;
  v3 = 0;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v4 = v2->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v4, &pval, "list.numSlots");
  UFG::qString::qString(&v11);
  v13 = 257;
  v12 = (signed int)pval.mValue.NValue;
  UFG::qString::Set(&v11, "list");
  v2->m_list->vfptr[1].__vecDelDtor((UFG::UIWidget *)&v2->m_list->vfptr, (unsigned int)&v11);
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
      v9 = v6 + 1;
      v9->mNext = v9;
      v9[1].mNext = v9;
      v6->mNext = (UFG::allocator::free_link *)&UFG::UIItem::`vftable';
      LODWORD(v6[3].mNext) = v8;
      v6[4].mNext = (UFG::allocator::free_link *)v2;
      v6->mNext = (UFG::allocator::free_link *)&UFG::UIItemText::`vftable';
      UFG::qString::qString((UFG::qString *)&v6[5], &text);
      v16 = v6 + 10;
      v16->mNext = v16;
      v16[1].mNext = v16;
      v6[12].mNext = 0i64;
      if ( v7 )
        LODWORD(v6[3].mNext) = v7;
    }
    else
    {
      v6 = 0i64;
    }
    if ( v3 & 1 )
    {
      v3 &= 0xFFFFFFFE;
      UFG::qString::~qString(&text);
    }
    v2->m_list->vfptr->addItem((UFG::UIWidget *)&v2->m_list->vfptr, (UFG::UIItem *)v6);
    ++v5;
  }
  while ( (signed __int64)v5 < (signed __int64)&UFG::UIHKInfoPopupWidget::gHintReminderPeriod );
  ((void (*)(void))v2->m_list->vfptr->update)();
  UFG::qString::~qString(&v11);
  if ( ((unsigned int)pval.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
}

// File Line: 83
// RVA: 0x6224D0
bool __fastcall UFG::UIHKScreenDebugScreenList::handleMessage(UFG::UIHKScreenDebugScreenList *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // ebx
  UFG::UIHKScreenDebugScreenList *v5; // rdi
  UFG::UIListText *v6; // rcx
  UFG::UIScreenTextureManager *v8; // rax
  UFG::qString v9; // [rsp+28h] [rbp-30h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = this->m_list;
  if ( v6 && v6->vfptr->handleMessage((UFG::UIWidget *)&v6->vfptr, msg) )
    return 1;
  if ( v4 == UI_HASH_MENU_OPTION_SELECTED_20 )
  {
    UFG::qString::qString(&v9, (UFG::qString *)&v5->m_list->m_selectedItem[1]);
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
    v8 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v8, v9.mData, 0i64);
    UFG::qString::~qString(&v9);
  }
  else if ( v4 == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
  }
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
}

