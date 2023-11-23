// File Line: 23
// RVA: 0x5CA6E0
void __fastcall UFG::UIHKScreenDebugNISList::~UIHKScreenDebugNISList(UFG::UIHKScreenDebugNISList *this)
{
  unsigned int v2; // eax
  UFG::UIScreenTextureManager *v3; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDebugNISList::`vftable;
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v2 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v2 == 1) )
        UFG::UI::ResetGameplayInput((UFG::UI *)this);
    }
  }
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "DebugNISList");
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 30
// RVA: 0x630320
void __fastcall UFG::UIHKScreenDebugNISList::init(UFG::UIHKScreenDebugNISList *this, UFG::UICommandData *data)
{
  UFG::Controller *v3; // rdx

  UFG::UIScreen::init(this, data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  UFG::UIHKScreenDebugNISList::PopulateList(this);
}

// File Line: 39
// RVA: 0x622340
bool __fastcall UFG::UIHKScreenDebugNISList::handleMessage(
        UFG::UIHKScreenDebugNISList *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *pObject; // rcx
  const char *pString; // rbp
  NISManager *Instance; // rax
  Scaleform::GFx::Movie *v10; // rcx
  const char *v11; // rdx
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-40h] BYREF

  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    pObject = this->mRenderable->m_movie.pObject;
    if ( !pObject )
      return 0;
    pval.pObjectInterface = 0i64;
    pval.Type = VT_Undefined;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gSelectedValue");
    if ( (pval.Type & 0x40) != 0 )
      pString = *pval.mValue.pStringManaged;
    else
      pString = pval.mValue.pString;
    Instance = NISManager::GetInstance();
    NISManager::Play(Instance, pString);
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
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
  else
  {
    if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
    {
      v10 = this->mRenderable->m_movie.pObject;
      if ( !v10 )
        return 0;
      v11 = "ScrollDown";
    }
    else
    {
      if ( msgId != UI_HASH_DPAD_UP_PRESSED_30 && msgId != UI_HASH_THUMBSTICK_LEFT_UP_30 )
      {
        if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 || msgId == (_DWORD)UI_HASH_BUTTON_BUTTON2_PRESSED_30 )
          UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      v10 = this->mRenderable->m_movie.pObject;
      if ( !v10 )
        return 0;
      v11 = "ScrollUp";
    }
    Scaleform::GFx::Movie::Invoke(v10, v11, 0i64, 0i64, 0);
  }
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

// File Line: 78
// RVA: 0x5D1ED0
void __fastcall UFG::UIHKScreenDebugNISList::AddItem(UFG::UIHKScreenDebugNISList *this, const char *caption)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_String;
  pargs.mValue.pString = caption;
  Scaleform::GFx::Movie::Invoke(pObject, "List_AddItem", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 88
// RVA: 0x5F9370
void __fastcall UFG::UIHKScreenDebugNISList::PopulateList(UFG::UIHKScreenDebugNISList *this)
{
  ActionNode *v2; // rbx
  ActionNode *v3; // rax
  ActionNode *v4; // rbx
  const char *v5; // rdx
  ActionPath absolutePath; // [rsp+20h] [rbp-138h] BYREF
  __int64 v7; // [rsp+30h] [rbp-128h]
  ActionNode_Iterator v8; // [rsp+40h] [rbp-118h] BYREF

  v7 = -2i64;
  absolutePath.mPath.mCount = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&absolutePath, "\\Global\\NIS");
  v2 = ActionNode::Find(&absolutePath, 0i64);
  if ( v2 )
  {
    ActionNode_Iterator::ActionNode_Iterator(&v8);
    ActionNode_Iterator::First(&v8, v2);
    while ( !ActionNode_Iterator::IsDone(&v8) )
    {
      v3 = ActionNode_Iterator::CurrentItem(&v8);
      v4 = v3;
      if ( v3 && v3->vfptr->GetClassNameUID(v3) == NISNode::sClassNameUID )
      {
        if ( (*(_QWORD *)&v4[3].mPad2 & 0xFFFFFFFFFFFFFFFEui64) != 0 )
          v5 = &v4[3].mPad2 + (*(_QWORD *)&v4[3].mPad2 & 0xFFFFFFFFFFFFFFFEui64);
        else
          v5 = BinString::sEmptyString;
        UFG::UIHKScreenDebugNISList::AddItem(this, v5);
      }
      ActionNode_Iterator::Next(&v8);
    }
  }
  if ( absolutePath.mPath.mCount >= 0 && absolutePath.mPath.mData.mOffset )
  {
    if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
  }
}

