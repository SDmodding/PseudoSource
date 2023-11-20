// File Line: 32
// RVA: 0x5C84B0
void __fastcall UFG::UIHK_PDAIncomingCallWidget::UIHK_PDAIncomingCallWidget(UFG::UIHK_PDAIncomingCallWidget *this)
{
  UFG::UIHK_PDAIncomingCallWidget *v1; // rdi

  v1 = this;
  *(_QWORD *)&this->mState = 0i64;
  this->mOldSeconds = 0;
  this->mUpdateTimer = 0;
  UFG::qString::qString(&this->mCallerName);
  UFG::qString::qString(&v1->mCallerPortrait);
  v1->mVoiceMail = 0;
  UFG::qString::qString(&v1->mInputLocker.mOwner, "UIHK_PDAIncomingCallWidget");
  v1->mInputLocker.mAcquired = 0;
}

// File Line: 37
// RVA: 0x5CDB60
void __fastcall UFG::UIHK_PDAIncomingCallWidget::~UIHK_PDAIncomingCallWidget(UFG::UIHK_PDAIncomingCallWidget *this)
{
  UFG::UIHK_PDAIncomingCallWidget *v1; // rbx

  v1 = this;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xD92517u,
      0i64,
      0,
      0i64);
  if ( v1->mState )
  {
    UFG::UIHK_PDAIncomingCallWidget::HangUp(v1, 0);
    v1->mUpdateTimer = 0;
  }
  UFG::UIHK_PDAIncomingCallWidget::ReleaseInputLock(v1, "Deactivate");
  UFG::qString::~qString(&v1->mInputLocker.mOwner);
  UFG::qString::~qString(&v1->mCallerPortrait);
  UFG::qString::~qString(&v1->mCallerName);
}

// File Line: 45
// RVA: 0x619780
void __fastcall UFG::UIHK_PDAIncomingCallWidget::Update(UFG::UIHK_PDAIncomingCallWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIHK_PDAIncomingCallWidget *v3; // rbx
  Scaleform::GFx::Movie *v4; // rsi
  signed int v5; // ecx
  int v6; // edi
  void (__fastcall *numArgs[3])(Scaleform::GFx::Value *); // [rsp+20h] [rbp-68h]
  char dest; // [rsp+38h] [rbp-50h]
  Scaleform::GFx::Value pargs; // [rsp+50h] [rbp-38h]

  v3 = this;
  if ( this->mUpdateTimer )
  {
    this->mTimer = elapsed + this->mTimer;
    v4 = screen->mRenderable->m_movie.pObject;
    numArgs[0] = Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v5 = (signed int)(float)(v3->mTimer * 1000.0);
    v6 = v5 / 1000 % 60;
    if ( v3->mOldSeconds != v6 )
    {
      LODWORD(numArgs[0]) = v5 / 1000 % 60;
      UFG::qSPrintf(&dest, 20, "%d:%02d", v5 / 1000 / 60, numArgs[0]);
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = 6;
      *(_QWORD *)&pargs.mValue.NValue = &dest;
      Scaleform::GFx::Movie::Invoke(v4, "ContactList_UpdatedConnectedTime", 0i64, &pargs, 1u);
    }
    v3->mOldSeconds = v6;
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 91
// RVA: 0x5D1260
void __fastcall UFG::UIHK_PDAIncomingCallWidget::Activate(UFG::UIHK_PDAIncomingCallWidget *this, const char *callerName, const char *portrait, bool outgoing, bool voiceMail)
{
  bool v5; // bp
  UFG::UIHK_PDAIncomingCallWidget *v6; // r14
  UFG::allocator::free_link *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rdi
  const char *v10; // rbx
  const char *v11; // rax
  unsigned int v12; // eax
  UFG::UIGfxTranslator *v13; // rcx
  UFG::allocator::free_link *v14; // rax
  UFG::qString *v15; // rbx
  UFG::allocator::free_link *v16; // rax
  signed __int64 v17; // rbx
  __int64 v18; // rsi
  __int64 v19; // rbx
  UFG::qString result; // [rsp+40h] [rbp-38h]

  v5 = outgoing;
  v6 = this;
  UFG::UIHK_PDAIncomingCallWidget::SetCallerName(this, callerName, portrait, voiceMail);
  v7 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x58ui64, "UIHK_PDAWidget::ShowIncomingPhoneCall", 0i64, 1u);
  if ( v7 )
  {
    UFG::UIScreenInvokeValueArgs::UIScreenInvokeValueArgs((UFG::UIScreenInvokeValueArgs *)v7);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  if ( v9 )
  {
    if ( voiceMail )
    {
      v10 = "$PDA_VOICEMAIL";
    }
    else
    {
      v10 = "$PDA_INCOMING_CALL";
      if ( v5 )
        v10 = "$PDA_OUTGOING_CALL";
    }
    if ( v10 )
    {
      if ( *v10 == 36 )
        ++v10;
      v12 = UFG::qStringHashUpper32(v10, 0xFFFFFFFF);
      v13 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v13
        || (v11 = (const char *)v13->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v13->vfptr, v12)) == 0i64 )
      {
        v11 = v10;
      }
    }
    else
    {
      v11 = 0i64;
    }
    UFG::qString::FormatEx(&result, v11, v6->mCallerName.mData);
    v14 = UFG::qMalloc(0x30ui64, "UIHK_PDAIncomingCallWidget qString[]", 0i64);
    if ( v14 )
    {
      LODWORD(v14->mNext) = 1;
      v15 = (UFG::qString *)&v14[1];
      `eh vector constructor iterator(&v14[1], 0x28ui64, 1, (void (__fastcall *)(void *))UFG::qString::qString);
    }
    else
    {
      v15 = 0i64;
    }
    *(_QWORD *)(v9 + 80) = v15;
    UFG::qString::Set(v15, result.mData, result.mLength, 0i64, 0);
    UFG::qString::Set((UFG::qString *)(v9 + 24), "Phone_ShowCall");
    *(_DWORD *)(v9 + 72) = 2;
    v16 = UFG::qMalloc(0x68ui64, "UIHK_PDAIncomingCallWidget GFxValue[]", 0i64);
    if ( v16 )
    {
      LODWORD(v16->mNext) = 2;
      v17 = (signed __int64)&v16[1];
      `eh vector constructor iterator(&v16[1], 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    }
    else
    {
      v17 = 0i64;
    }
    *(_QWORD *)(v9 + 64) = v17;
    v18 = *(_QWORD *)(*(_QWORD *)(v9 + 80) + 24i64);
    if ( (*(_DWORD *)(v17 + 24) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, signed __int64, _QWORD))(**(_QWORD **)(v17 + 16) + 16i64))(
        *(_QWORD *)(v17 + 16),
        v17,
        *(_QWORD *)(v17 + 32));
      *(_QWORD *)(v17 + 16) = 0i64;
    }
    *(_DWORD *)(v17 + 24) = 6;
    *(_QWORD *)(v17 + 32) = v18;
    v19 = *(_QWORD *)(v9 + 64);
    if ( (*(_DWORD *)(v19 + 72) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, __int64, _QWORD))(**(_QWORD **)(v19 + 64) + 16i64))(
        *(_QWORD *)(v19 + 64),
        v19 + 48,
        *(_QWORD *)(v19 + 80));
      *(_QWORD *)(v19 + 64) = 0i64;
    }
    *(_DWORD *)(v19 + 72) = 2;
    *(_BYTE *)(v19 + 80) = v5;
    if ( *(_DWORD *)(v9 + 44) )
      UFG::UIScreenInvokeQueue::Add(&UFG::UIHK_PDAWidget::mScreenInvokeQueue, (UFG::UIScreenInvoke *)v9);
    v6->mState = 2;
    UFG::qString::~qString(&result);
  }
}

// File Line: 154
// RVA: 0x5D3810
void __fastcall UFG::UIHK_PDAIncomingCallWidget::Answer(UFG::UIHK_PDAIncomingCallWidget *this)
{
  UFG::UIHK_PDAIncomingCallWidget *v1; // rbx
  UFG::allocator::free_link *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rsi
  unsigned int v5; // eax
  UFG::UIGfxTranslator *v6; // rcx
  const char *v7; // rax
  unsigned int v8; // eax
  UFG::UIGfxTranslator *v9; // rcx
  UFG::allocator::free_link *v10; // rax
  UFG::qString *v11; // rdi
  UFG::allocator::free_link *v12; // rax
  signed __int64 v13; // rdi
  __int64 v14; // rbp
  __int64 v15; // rbp
  __int64 v16; // rdi
  UFG::qString result; // [rsp+38h] [rbp-40h]

  v1 = this;
  this->mState = 4;
  if ( !this->mInputLocker.mAcquired )
  {
    UFG::SetInputMode_PDA_On(UFG::gActiveControllerNum);
    ++UFG::UIHKGameplayHelpWidget::mLocked;
    ++UFG::UIHK_PDAWidget::mInputLocked;
    v1->mInputLocker.mAcquired = 1;
  }
  UFG::ActivateInputSubMode(ISM_PHONE_CALL, UFG::gActiveControllerNum);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xD92517u,
      0i64,
      0,
      0i64);
  v2 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x58ui64, "UIHK_PDAIncomingCallWidget::Answer", 0i64, 1u);
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
    if ( v1->mVoiceMail )
    {
      v5 = UFG::qStringHashUpper32("PDA_VOICEMAIL", 0xFFFFFFFF);
      v6 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v6 || (v7 = (const char *)v6->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, v5)) == 0i64 )
        v7 = "PDA_VOICEMAIL";
    }
    else
    {
      v8 = UFG::qStringHashUpper32("PDA_CONNECTED", 0xFFFFFFFF);
      v9 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v9 || (v7 = (const char *)v9->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, v8)) == 0i64 )
        v7 = "PDA_CONNECTED";
    }
    UFG::qString::FormatEx(&result, v7, v1->mCallerName.mData);
    v10 = UFG::qMalloc(0x58ui64, "UIHK_PDAIncomingCallWidget qString[]", 0i64);
    if ( v10 )
    {
      LODWORD(v10->mNext) = 2;
      v11 = (UFG::qString *)&v10[1];
      `eh vector constructor iterator(&v10[1], 0x28ui64, 2, (void (__fastcall *)(void *))UFG::qString::qString);
    }
    else
    {
      v11 = 0i64;
    }
    *(_QWORD *)(v4 + 80) = v11;
    UFG::qString::Set(v11, result.mData, result.mLength, 0i64, 0);
    UFG::qString::Set(
      (UFG::qString *)(*(_QWORD *)(v4 + 80) + 40i64),
      v1->mCallerPortrait.mData,
      v1->mCallerPortrait.mLength,
      0i64,
      0);
    UFG::qString::Set((UFG::qString *)(v4 + 24), "Phone_AnswerCall");
    *(_DWORD *)(v4 + 72) = 2;
    v12 = UFG::qMalloc(0x68ui64, "UIHK_PDAIncomingCallWidget GFxValue[]", 0i64);
    if ( v12 )
    {
      LODWORD(v12->mNext) = 2;
      v13 = (signed __int64)&v12[1];
      `eh vector constructor iterator(&v12[1], 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    }
    else
    {
      v13 = 0i64;
    }
    *(_QWORD *)(v4 + 64) = v13;
    v14 = *(_QWORD *)(*(_QWORD *)(v4 + 80) + 24i64);
    if ( (*(_DWORD *)(v13 + 24) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, signed __int64, _QWORD))(**(_QWORD **)(v13 + 16) + 16i64))(
        *(_QWORD *)(v13 + 16),
        v13,
        *(_QWORD *)(v13 + 32));
      *(_QWORD *)(v13 + 16) = 0i64;
    }
    *(_DWORD *)(v13 + 24) = 6;
    *(_QWORD *)(v13 + 32) = v14;
    v15 = *(_QWORD *)(*(_QWORD *)(v4 + 80) + 64i64);
    v16 = *(_QWORD *)(v4 + 64);
    if ( (*(_DWORD *)(v16 + 72) >> 6) & 1 )
    {
      (*(void (__fastcall **)(_QWORD, __int64, _QWORD))(**(_QWORD **)(v16 + 64) + 16i64))(
        *(_QWORD *)(v16 + 64),
        v16 + 48,
        *(_QWORD *)(v16 + 80));
      *(_QWORD *)(v16 + 64) = 0i64;
    }
    *(_DWORD *)(v16 + 72) = 6;
    *(_QWORD *)(v16 + 80) = v15;
    if ( *(_DWORD *)(v4 + 44) )
      UFG::UIScreenInvokeQueue::Add(&UFG::UIHK_PDAWidget::mScreenInvokeQueue, (UFG::UIScreenInvoke *)v4);
    v1->mOldSeconds = -1;
    v1->mTimer = 0.0;
    v1->mUpdateTimer = 1;
    UFG::qString::~qString(&result);
  }
}

// File Line: 185
// RVA: 0x5EC890
void __fastcall UFG::UIHK_PDAIncomingCallWidget::HangUp(UFG::UIHK_PDAIncomingCallWidget *this, bool playSound)
{
  bool v2; // bl
  UFG::allocator::free_link *v3; // rax
  UFG::UIScreenInvoke *v4; // rbx
  UFG::allocator::free_link *v5; // rax

  v2 = playSound;
  this->mState = 0;
  UFG::UIHK_PDAIncomingCallWidget::ReleaseInputLock(this, "HangUp");
  if ( v2 && UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0x67B8209Du,
      0i64,
      0,
      0i64);
  v3 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UIHK_PDAIncomingCallWidget ScreenInvoke", 0i64, 1u);
  v4 = (UFG::UIScreenInvoke *)v3;
  if ( v3 )
  {
    v5 = v3 + 1;
    v5->mNext = v5;
    v5[1].mNext = v5;
    v4->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable;
    UFG::qString::qString(&v4->command, &customWorldMapCaption);
  }
  else
  {
    v4 = 0i64;
  }
  if ( v4 )
  {
    UFG::qString::Set(&v4->command, "Phone_EndCall");
    if ( v4->command.mLength )
      UFG::UIScreenInvokeQueue::Add(&UFG::UIHK_PDAWidget::mScreenInvokeQueue, v4);
  }
}

// File Line: 210
// RVA: 0x605570
void __fastcall UFG::UIHK_PDAIncomingCallWidget::SetCallerName(UFG::UIHK_PDAIncomingCallWidget *this, const char *callerName, const char *portrait, bool voiceMail)
{
  bool v4; // si
  const char *v5; // rbp
  const char *v6; // rbx
  UFG::UIHK_PDAIncomingCallWidget *v7; // rdi
  const char *v8; // rax
  unsigned int v9; // eax
  UFG::UIGfxTranslator *v10; // rcx

  v4 = voiceMail;
  v5 = portrait;
  v6 = callerName;
  v7 = this;
  if ( callerName )
  {
    if ( *callerName == $ )
      v6 = callerName + 1;
    v9 = UFG::qStringHashUpper32(v6, 0xFFFFFFFF);
    v10 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v10 || (v8 = (const char *)v10->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, v9)) == 0i64 )
      v8 = v6;
  }
  else
  {
    v8 = 0i64;
  }
  UFG::qString::Set(&v7->mCallerName, v8);
  UFG::qString::Set(&v7->mCallerPortrait, v5);
  v7->mVoiceMail = v4;
}

// File Line: 237
// RVA: 0x600BD0
void __fastcall UFG::UIHK_PDAIncomingCallWidget::ReleaseInputLock(UFG::UIHK_PDAIncomingCallWidget *this, const char *trace)
{
  const char *v2; // rdi
  UFG::UIHK_PDAIncomingCallWidget *v3; // rbx
  int v4; // eax

  v2 = trace;
  v3 = this;
  UFG::DeactivateInputSubMode(ISM_PHONE_CALL, UFG::gActiveControllerNum);
  if ( v3->mInputLocker.mAcquired )
  {
    UFG::qPrintf("PDAInputLock released by %s through %s\n", v3->mInputLocker.mOwner.mData, v2);
    if ( UFG::UIHK_PDAWidget::mInputLocked )
    {
      UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
      v4 = UFG::UIHKGameplayHelpWidget::mLocked;
      if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
        v4 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
      if ( v4 < 1 )
        UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
      --UFG::UIHK_PDAWidget::mInputLocked;
    }
    v3->mInputLocker.mAcquired = 0;
  }
}

