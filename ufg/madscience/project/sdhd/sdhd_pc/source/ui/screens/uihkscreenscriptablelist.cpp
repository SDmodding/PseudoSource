// File Line: 16
// RVA: 0x15673E0
__int64 dynamic_initializer_for__UFG::UIHKScreenScriptableList::mScreenInvokeQueue__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenScriptableList::mScreenInvokeQueue__);
}

// File Line: 17
// RVA: 0x1567470
__int64 dynamic_initializer_for__UFG::UIHKScreenScriptableList::mSelectedValue__()
{
  UFG::qString::qString(&UFG::UIHKScreenScriptableList::mSelectedValue);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHKScreenScriptableList::mSelectedValue__);
}

// File Line: 21
// RVA: 0x5CC700
void __fastcall UFG::UIHKScreenScriptableList::~UIHKScreenScriptableList(UFG::UIHKScreenScriptableList *this)
{
  UFG::UIScreenTextureManager *v2; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenScriptableList::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "ScriptableList");
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 33
// RVA: 0x63FA90
void __fastcall UFG::UIHKScreenScriptableList::update(UFG::UIHKScreenScriptableList *this, float elapsed)
{
  UFG::UIScreenInvokeQueue::Update(&UFG::UIHKScreenScriptableList::mScreenInvokeQueue, this);
}

// File Line: 39
// RVA: 0x62B200
bool __fastcall UFG::UIHKScreenScriptableList::handleMessage(
        UFG::UIHKScreenScriptableList *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  Scaleform::GFx::Movie *pObject; // rcx
  const char *pString; // rdx
  Scaleform::GFx::Movie *v9; // rcx
  const char *v10; // rdx
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
    UFG::qString::Set(&UFG::UIHKScreenScriptableList::mSelectedValue, pString);
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
    if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30
      || msgId == UI_HASH_DPAD_DOWN_REPEAT_30
      || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
    {
      v9 = this->mRenderable->m_movie.pObject;
      if ( !v9 )
        return 0;
      v10 = "ScrollDown";
    }
    else
    {
      if ( msgId != UI_HASH_DPAD_UP_PRESSED_30
        && msgId != UI_HASH_DPAD_UP_REPEAT_30
        && msgId != UI_HASH_THUMBSTICK_LEFT_UP_30 )
      {
        return UFG::UIScreen::handleMessage(this, msgId, msg);
      }
      v9 = this->mRenderable->m_movie.pObject;
      if ( !v9 )
        return 0;
      v10 = "ScrollUp";
    }
    Scaleform::GFx::Movie::Invoke(v9, v10, 0i64, 0i64, 0);
  }
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

// File Line: 77
// RVA: 0x5FEDB0
void __fastcall UFG::UIHKScreenScriptableList::QueueInvoke(UFG::UIScreenInvoke *cmd)
{
  if ( cmd )
  {
    if ( cmd->command.mLength )
      UFG::UIScreenInvokeQueue::Add(&UFG::UIHKScreenScriptableList::mScreenInvokeQueue, cmd);
  }
}

// File Line: 85
// RVA: 0x5D2360
void __fastcall UFG::UIHKScreenScriptableList::AddItem(const char *caption)
{
  UFG::allocator::free_link *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::qString *v6; // rbx
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rbx
  UFG::allocator::free_link *v9; // rsi

  v2 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x58ui64, "UIScreenInvoke", 0i64, 1u);
  if ( v2 )
  {
    UFG::UIScreenInvokeValueArgs::UIScreenInvokeValueArgs((UFG::UIScreenInvokeValueArgs *)v2);
    v4 = v3;
  }
  else
  {
    v4 = 0i64;
  }
  if ( v4 )
  {
    v5 = UFG::qMalloc(0x30ui64, "qString[]", 0i64);
    if ( v5 )
    {
      LODWORD(v5->mNext) = 1;
      v6 = (UFG::qString *)&v5[1];
      `eh vector constructor iterator(&v5[1], 0x28ui64, 1, (void (__fastcall *)(void *))UFG::qString::qString);
    }
    else
    {
      v6 = 0i64;
    }
    *(_QWORD *)(v4 + 80) = v6;
    UFG::qString::Set(v6, caption);
    UFG::qString::Set((UFG::qString *)(v4 + 24), "ScriptableList_AddItem");
    *(_DWORD *)(v4 + 72) = 1;
    v7 = UFG::qMalloc(0x38ui64, "UIHKScreenScriptableList GFxValue[]", 0i64);
    if ( v7 )
    {
      LODWORD(v7->mNext) = 1;
      v8 = v7 + 1;
      `eh vector constructor iterator(&v7[1], 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    }
    else
    {
      v8 = 0i64;
    }
    *(_QWORD *)(v4 + 64) = v8;
    v9 = *(UFG::allocator::free_link **)(*(_QWORD *)(v4 + 80) + 24i64);
    if ( ((__int64)v8[3].mNext & 0x40) != 0 )
    {
      ((void (__fastcall *)(UFG::allocator::free_link *, UFG::allocator::free_link *, UFG::allocator::free_link *))v8[2].mNext->mNext[2].mNext)(
        v8[2].mNext,
        v8,
        v8[4].mNext);
      v8[2].mNext = 0i64;
    }
    LODWORD(v8[3].mNext) = 6;
    v8[4].mNext = v9;
    if ( *(_DWORD *)(v4 + 44) )
      UFG::UIScreenInvokeQueue::Add(&UFG::UIHKScreenScriptableList::mScreenInvokeQueue, (UFG::UIScreenInvoke *)v4);
  }
}

