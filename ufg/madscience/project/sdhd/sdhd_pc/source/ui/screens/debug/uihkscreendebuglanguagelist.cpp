// File Line: 26
// RVA: 0x5C4D00
void __fastcall UFG::UIHKScreenDebugLanguageList::UIHKScreenDebugLanguageList(UFG::UIHKScreenDebugLanguageList *this)
{
  UFG::UIHKScreenDebugLanguageList *v1; // rbx
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDebugLanguageList::`vftable';
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

// File Line: 32
// RVA: 0x5CA650
void __fastcall UFG::UIHKScreenDebugLanguageList::~UIHKScreenDebugLanguageList(UFG::UIHKScreenDebugLanguageList *this)
{
  UFG::UIHKScreenDebugLanguageList *v1; // rbx
  UFG::UIListText *v2; // rcx
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIScreenTextureManager *v4; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDebugLanguageList::`vftable';
  v2 = this->m_list;
  if ( v2 )
    v2->vfptr->__vecDelDtor((UFG::UIWidget *)&v2->vfptr, 1u);
  v1->m_list = 0i64;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "DebugLanguageList");
  if ( UFG::UIHKScreenDebugLanguageList::gReturnToMainMenu )
  {
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v4, "MainMenu", 0i64);
  }
  UFG::UIHKScreenDebugLanguageList::gReturnToMainMenu = 0;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 46
// RVA: 0x630140
void __fastcall UFG::UIHKScreenDebugLanguageList::init(UFG::UIHKScreenDebugLanguageList *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenDebugLanguageList *v2; // r15
  int v3; // edi
  Scaleform::GFx::Movie *v4; // rcx
  UFG::UILanguages::eLanguage v5; // esi
  const char *v6; // r14
  UFG::allocator::free_link *v7; // rbx
  unsigned int v8; // er14
  int v9; // eax
  UFG::allocator::free_link *v10; // rcx
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-71h]
  UFG::qString v12; // [rsp+68h] [rbp-41h]
  int v13; // [rsp+90h] [rbp-19h]
  __int16 v14; // [rsp+94h] [rbp-15h]
  __int64 v15; // [rsp+98h] [rbp-11h]
  UFG::qString text; // [rsp+A0h] [rbp-9h]
  UFG::allocator::free_link *v17; // [rsp+120h] [rbp+77h]

  v15 = -2i64;
  v2 = this;
  v3 = 0;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v4 = v2->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v4, &pval, "list.numSlots");
  UFG::qString::qString(&v12);
  v14 = 257;
  v13 = (signed int)pval.mValue.NValue;
  UFG::qString::Set(&v12, "list");
  v2->m_list->vfptr[1].__vecDelDtor((UFG::UIWidget *)&v2->m_list->vfptr, (unsigned int)&v12);
  v5 = 0;
  do
  {
    v6 = UFG::UILanguages::getLanguageString(v5);
    v7 = UFG::qMemoryPool::Allocate(
           &gScaleformMemoryPool,
           0x68ui64,
           "UIHKScreenDebugLanguageList::UIItemText",
           0i64,
           1u);
    if ( v7 )
    {
      UFG::qString::qString(&text, v6);
      v3 |= 1u;
      v8 = UI_HASH_MENU_OPTION_SELECTED_20;
      v9 = UFG::qStringHash32(text.mData, 0xFFFFFFFF);
      v10 = v7 + 1;
      v10->mNext = v10;
      v10[1].mNext = v10;
      v7->mNext = (UFG::allocator::free_link *)&UFG::UIItem::`vftable';
      LODWORD(v7[3].mNext) = v9;
      v7[4].mNext = (UFG::allocator::free_link *)v2;
      v7->mNext = (UFG::allocator::free_link *)&UFG::UIItemText::`vftable';
      UFG::qString::qString((UFG::qString *)&v7[5], &text);
      v17 = v7 + 10;
      v17->mNext = v17;
      v17[1].mNext = v17;
      v7[12].mNext = 0i64;
      if ( v8 )
        LODWORD(v7[3].mNext) = v8;
    }
    else
    {
      v7 = 0i64;
    }
    if ( v3 & 1 )
    {
      v3 &= 0xFFFFFFFE;
      UFG::qString::~qString(&text);
    }
    v2->m_list->vfptr->addItem((UFG::UIWidget *)&v2->m_list->vfptr, (UFG::UIItem *)v7);
    ++v5;
  }
  while ( (signed int)v5 < 24 );
  ((void (*)(void))v2->m_list->vfptr->update)();
  UFG::qString::~qString(&v12);
  if ( ((unsigned int)pval.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
}

// File Line: 74
// RVA: 0x622250
bool __fastcall UFG::UIHKScreenDebugLanguageList::handleMessage(UFG::UIHKScreenDebugLanguageList *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbp
  unsigned int v4; // edi
  UFG::UIHKScreenDebugLanguageList *v5; // rsi
  UFG::UIListText *v6; // rcx
  UFG::UIGfxTranslator *v8; // rbx
  unsigned int v9; // eax
  UFG::qString v10; // [rsp+28h] [rbp-30h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  v6 = this->m_list;
  if ( v6 && v6->vfptr->handleMessage((UFG::UIWidget *)&v6->vfptr, msg) )
    return 1;
  if ( v4 == UI_HASH_MENU_OPTION_SELECTED_20 )
  {
    UFG::qString::qString(&v10, (UFG::qString *)&v5->m_list->m_selectedItem[1]);
    v8 = UFG::UIScreenManager::s_instance->m_translator;
    v9 = UFG::UILanguages::getLanguage(v10.mData);
    UFG::UIGfxTranslator::setLanguage(v8, (UFG::UILanguages::eLanguage)v9, 1);
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
    UFG::qString::~qString(&v10);
  }
  else if ( v4 == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
  }
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
}

