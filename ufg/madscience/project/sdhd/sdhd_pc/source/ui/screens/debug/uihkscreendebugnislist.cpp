// File Line: 23
// RVA: 0x5CA6E0
void __fastcall UFG::UIHKScreenDebugNISList::~UIHKScreenDebugNISList(UFG::UIHKScreenDebugNISList *this)
{
  UFG::UIHKScreenDebugNISList *v1; // rbx
  unsigned int v2; // eax
  UFG::UIScreenTextureManager *v3; // rax

  v1 = this;
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
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 30
// RVA: 0x630320
void __fastcall UFG::UIHKScreenDebugNISList::init(UFG::UIHKScreenDebugNISList *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenDebugNISList *v2; // rbx
  UFG::Controller *v3; // rdx

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  UFG::UIHKScreenDebugNISList::PopulateList(v2);
}

// File Line: 39
// RVA: 0x622340
bool __fastcall UFG::UIHKScreenDebugNISList::handleMessage(UFG::UIHKScreenDebugNISList *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // r14
  unsigned int v4; // ebx
  UFG::UIHKScreenDebugNISList *v5; // rsi
  Scaleform::GFx::Movie *v6; // rcx
  long double v8; // rbp
  NISManager *v9; // rax
  Scaleform::GFx::Movie *v10; // rcx
  const char *v11; // rdx
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-40h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    v6 = this->mRenderable->m_movie.pObject;
    if ( !v6 )
      return 0;
    pval.pObjectInterface = 0i64;
    pval.Type = 0;
    Scaleform::GFx::Movie::GetVariable(v6, &pval, "gSelectedValue");
    if ( ((unsigned int)pval.Type >> 6) & 1 )
      v8 = *(double *)pval.mValue.pString;
    else
      v8 = pval.mValue.NValue;
    v9 = NISManager::GetInstance();
    NISManager::Play(v9, *(const char **)&v8);
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
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
          UFG::UIScreenManagerBase::queuePopScreen(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            0xFFFFFFFF);
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      }
      v10 = this->mRenderable->m_movie.pObject;
      if ( !v10 )
        return 0;
      v11 = "ScrollUp";
    }
    Scaleform::GFx::Movie::Invoke(v10, v11, 0i64, 0i64, 0);
  }
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
}

// File Line: 78
// RVA: 0x5D1ED0
void __fastcall UFG::UIHKScreenDebugNISList::AddItem(UFG::UIHKScreenDebugNISList *this, const char *caption)
{
  const char *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = caption;
  v3 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 6;
  *(_QWORD *)&pargs.mValue.NValue = v2;
  Scaleform::GFx::Movie::Invoke(v3, "List_AddItem", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 88
// RVA: 0x5F9370
void __fastcall UFG::UIHKScreenDebugNISList::PopulateList(UFG::UIHKScreenDebugNISList *this)
{
  UFG::UIHKScreenDebugNISList *v1; // rdi
  ActionNode *v2; // rbx
  ActionNode *v3; // rax
  ActionNode *v4; // rbx
  const char *v5; // rdx
  ActionPath absolutePath; // [rsp+20h] [rbp-138h]
  __int64 v7; // [rsp+30h] [rbp-128h]
  ActionNode_Iterator v8; // [rsp+40h] [rbp-118h]

  v7 = -2i64;
  v1 = this;
  absolutePath.mPath.mCount = 0;
  absolutePath.mPath.mData.mOffset = 0i64;
  ActionPath::Append(&absolutePath, "\\Global\\NIS");
  v2 = ActionNode::Find(&absolutePath, 0i64);
  if ( v2 )
  {
    ActionNode_Iterator::ActionNode_Iterator(&v8);
    ActionNode_Iterator::First(&v8, v2);
    while ( !(unsigned __int8)ActionNode_Iterator::IsDone(&v8) )
    {
      v3 = ActionNode_Iterator::CurrentItem(&v8);
      v4 = v3;
      if ( v3 && v3->vfptr->GetClassNameUID((Expression::IMemberMap *)&v3->vfptr) == NISNode::sClassNameUID )
      {
        if ( *(_QWORD *)&v4[3].mPad2 & 0xFFFFFFFFFFFFFFFEui64 )
          v5 = &v4[3].mPad2 + (*(_QWORD *)&v4[3].mPad2 & 0xFFFFFFFFFFFFFFFEui64);
        else
          v5 = BinString::sEmptyString;
        UFG::UIHKScreenDebugNISList::AddItem(v1, v5);
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

