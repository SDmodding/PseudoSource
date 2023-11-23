// File Line: 26
// RVA: 0x5C4D00
void __fastcall UFG::UIHKScreenDebugLanguageList::UIHKScreenDebugLanguageList(UFG::UIHKScreenDebugLanguageList *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDebugLanguageList::`vftable;
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

// File Line: 32
// RVA: 0x5CA650
void __fastcall UFG::UIHKScreenDebugLanguageList::~UIHKScreenDebugLanguageList(UFG::UIHKScreenDebugLanguageList *this)
{
  UFG::UIListText *m_list; // rcx
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIScreenTextureManager *v4; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDebugLanguageList::`vftable;
  m_list = this->m_list;
  if ( m_list )
    m_list->vfptr->__vecDelDtor(m_list, 1u);
  this->m_list = 0i64;
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "DebugLanguageList");
  if ( UFG::UIHKScreenDebugLanguageList::gReturnToMainMenu )
  {
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v4, "MainMenu", 0i64);
  }
  UFG::UIHKScreenDebugLanguageList::gReturnToMainMenu = 0;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 46
// RVA: 0x630140
void __fastcall UFG::UIHKScreenDebugLanguageList::init(
        UFG::UIHKScreenDebugLanguageList *this,
        UFG::UICommandData *data)
{
  int v3; // edi
  Scaleform::GFx::Movie *pObject; // rcx
  int i; // esi
  const char *LanguageString; // r14
  UFG::allocator::free_link *v7; // rbx
  unsigned int v8; // r14d
  int v9; // eax
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-71h] BYREF
  UFG::qString v11; // [rsp+68h] [rbp-41h] BYREF
  int NValue; // [rsp+90h] [rbp-19h]
  __int16 v13; // [rsp+94h] [rbp-15h]
  __int64 v14; // [rsp+98h] [rbp-11h]
  UFG::qString text; // [rsp+A0h] [rbp-9h] BYREF

  v14 = -2i64;
  v3 = 0;
  UFG::UIScreen::init(this, data);
  pObject = this->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "list.numSlots");
  UFG::qString::qString(&v11);
  v13 = 257;
  NValue = (int)pval.mValue.NValue;
  UFG::qString::Set(&v11, "list");
  this->m_list->vfptr[1].__vecDelDtor(this->m_list, (unsigned int)&v11);
  for ( i = 0; i < 24; ++i )
  {
    LanguageString = UFG::UILanguages::getLanguageString((UFG::UILanguages::eLanguage)i);
    v7 = UFG::qMemoryPool::Allocate(
           &gScaleformMemoryPool,
           0x68ui64,
           "UIHKScreenDebugLanguageList::UIItemText",
           0i64,
           1u);
    if ( v7 )
    {
      UFG::qString::qString(&text, LanguageString);
      v3 |= 1u;
      v8 = UI_HASH_MENU_OPTION_SELECTED_20;
      v9 = UFG::qStringHash32(text.mData, 0xFFFFFFFF);
      v7[1].mNext = v7 + 1;
      v7[2].mNext = v7 + 1;
      v7->mNext = (UFG::allocator::free_link *)&UFG::UIItem::`vftable;
      LODWORD(v7[3].mNext) = v9;
      v7[4].mNext = (UFG::allocator::free_link *)this;
      v7->mNext = (UFG::allocator::free_link *)&UFG::UIItemText::`vftable;
      UFG::qString::qString((UFG::qString *)&v7[5], &text);
      v7[10].mNext = v7 + 10;
      v7[11].mNext = v7 + 10;
      v7[12].mNext = 0i64;
      if ( v8 )
        LODWORD(v7[3].mNext) = v8;
    }
    else
    {
      v7 = 0i64;
    }
    if ( (v3 & 1) != 0 )
    {
      v3 &= ~1u;
      UFG::qString::~qString(&text);
    }
    this->m_list->vfptr->addItem(this->m_list, (UFG::UIItem *)v7);
  }
  this->m_list->vfptr->update(this->m_list);
  UFG::qString::~qString(&v11);
  if ( (pval.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
}

// File Line: 74
// RVA: 0x622250
bool __fastcall UFG::UIHKScreenDebugLanguageList::handleMessage(
        UFG::UIHKScreenDebugLanguageList *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIListText *m_list; // rcx
  UFG::UIGfxTranslator *m_translator; // rbx
  int Language; // eax
  UFG::qString v10; // [rsp+28h] [rbp-30h] BYREF

  m_list = this->m_list;
  if ( m_list && m_list->vfptr->handleMessage(m_list, msg) )
    return 1;
  if ( msgId == UI_HASH_MENU_OPTION_SELECTED_20 )
  {
    UFG::qString::qString(&v10, (UFG::qString *)&this->m_list->m_selectedItem[1]);
    m_translator = UFG::UIScreenManager::s_instance->m_translator;
    Language = UFG::UILanguages::getLanguage(v10.mData);
    UFG::UIGfxTranslator::setLanguage(m_translator, (UFG::UILanguages::eLanguage)Language, 1);
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
    UFG::qString::~qString(&v10);
  }
  else if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
  }
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

