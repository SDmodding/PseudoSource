// File Line: 16
// RVA: 0x15673E0
__int64 dynamic_initializer_for__UFG::UIHKScreenScriptableList::mScreenInvokeQueue__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenScriptableList::mScreenInvokeQueue__);
}

// File Line: 17
// RVA: 0x1567470
__int64 dynamic_initializer_for__UFG::UIHKScreenScriptableList::mSelectedValue__()
{
  UFG::qString::qString(&UFG::UIHKScreenScriptableList::mSelectedValue);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHKScreenScriptableList::mSelectedValue__);
}

// File Line: 21
// RVA: 0x5CC700
void __fastcall UFG::UIHKScreenScriptableList::~UIHKScreenScriptableList(UFG::UIHKScreenScriptableList *this)
{
  UFG::UIHKScreenScriptableList *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenScriptableList::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "ScriptableList");
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 33
// RVA: 0x63FA90
void __fastcall UFG::UIHKScreenScriptableList::update(UFG::UIHKScreenScriptableList *this, float elapsed)
{
  UFG::UIScreenInvokeQueue::Update(&UFG::UIHKScreenScriptableList::mScreenInvokeQueue, (UFG::UIScreen *)&this->vfptr);
}

// File Line: 39
// RVA: 0x62B200
bool __fastcall UFG::UIHKScreenScriptableList::handleMessage(UFG::UIHKScreenScriptableList *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbp
  unsigned int v4; // ebx
  UFG::UIHKScreenScriptableList *v5; // rsi
  Scaleform::GFx::Movie *v6; // rcx
  long double v8; // rdx
  Scaleform::GFx::Movie *v9; // rcx
  const char *v10; // rdx
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
    UFG::qString::Set(&UFG::UIHKScreenScriptableList::mSelectedValue, *(const char **)&v8);
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
        return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
      }
      v9 = this->mRenderable->m_movie.pObject;
      if ( !v9 )
        return 0;
      v10 = "ScrollUp";
    }
    Scaleform::GFx::Movie::Invoke(v9, v10, 0i64, 0i64, 0);
  }
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
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
  const char *v1; // rsi
  UFG::allocator::free_link *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rdi
  UFG::allocator::free_link *v5; // rax
  UFG::qString *v6; // rbx
  UFG::allocator::free_link *v7; // rax
  signed __int64 v8; // rbx
  __int64 v9; // rsi

  v1 = caption;
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
    UFG::qString::Set(v6, v1);
    UFG::qString::Set((UFG::qString *)(v4 + 24), "ScriptableList_AddItem");
    *(_DWORD *)(v4 + 72) = 1;
    v7 = UFG::qMalloc(0x38ui64, "UIHKScreenScriptableList GFxValue[]", 0i64);
    if ( v7 )
    {
      LODWORD(v7->mNext) = 1;
      v8 = (signed __int64)&v7[1];
      `eh vector constructor iterator(&v7[1], 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    }
    else
    {
      v8 = 0i64;
    }
    *(_QWORD *)(v4 + 64) = v8;
    v9 = *(_QWORD *)(*(_QWORD *)(v4 + 80) + 24i64);
    if ( (*(_DWORD *)(v8 + 24) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, signed __int64, _QWORD))(**(_QWORD **)(v8 + 16) + 16i64))(
        *(_QWORD *)(v8 + 16),
        v8,
        *(_QWORD *)(v8 + 32));
      *(_QWORD *)(v8 + 16) = 0i64;
    }
    *(_DWORD *)(v8 + 24) = 6;
    *(_QWORD *)(v8 + 32) = v9;
    if ( *(_DWORD *)(v4 + 44) )
      UFG::UIScreenInvokeQueue::Add(&UFG::UIHKScreenScriptableList::mScreenInvokeQueue, (UFG::UIScreenInvoke *)v4);
  }
}

