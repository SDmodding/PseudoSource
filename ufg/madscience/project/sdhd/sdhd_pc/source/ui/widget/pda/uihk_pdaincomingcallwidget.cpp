// File Line: 32
// RVA: 0x5C84B0
void __fastcall UFG::UIHK_PDAIncomingCallWidget::UIHK_PDAIncomingCallWidget(UFG::UIHK_PDAIncomingCallWidget *this)
{
  *(_QWORD *)&this->mState = 0i64;
  this->mOldSeconds = 0;
  this->mUpdateTimer = 0;
  UFG::qString::qString(&this->mCallerName);
  UFG::qString::qString(&this->mCallerPortrait);
  this->mVoiceMail = 0;
  UFG::qString::qString(&this->mInputLocker.mOwner, "UIHK_PDAIncomingCallWidget");
  this->mInputLocker.mAcquired = 0;
}

// File Line: 37
// RVA: 0x5CDB60
void __fastcall UFG::UIHK_PDAIncomingCallWidget::~UIHK_PDAIncomingCallWidget(UFG::UIHK_PDAIncomingCallWidget *this)
{
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xD92517u, 0i64, 0, 0i64);
  if ( this->mState )
  {
    UFG::UIHK_PDAIncomingCallWidget::HangUp(this, 0);
    this->mUpdateTimer = 0;
  }
  UFG::UIHK_PDAIncomingCallWidget::ReleaseInputLock(this, "Deactivate");
  UFG::qString::~qString(&this->mInputLocker.mOwner);
  UFG::qString::~qString(&this->mCallerPortrait);
  UFG::qString::~qString(&this->mCallerName);
}

// File Line: 45
// RVA: 0x619780
void __fastcall UFG::UIHK_PDAIncomingCallWidget::Update(
        UFG::UIHK_PDAIncomingCallWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  Scaleform::GFx::Movie *pObject; // rsi
  int v5; // ecx
  int v6; // edi
  void (__fastcall *numArgs)(Scaleform::GFx::Value *); // [rsp+20h] [rbp-68h]
  char dest[24]; // [rsp+38h] [rbp-50h] BYREF
  Scaleform::GFx::Value pargs; // [rsp+50h] [rbp-38h] BYREF

  if ( this->mUpdateTimer )
  {
    this->mTimer = elapsed + this->mTimer;
    pObject = screen->mRenderable->m_movie.pObject;
    numArgs = Scaleform::GFx::Value::~Value;
    `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v5 = (int)(float)(this->mTimer * 1000.0);
    v6 = v5 / 1000 % 60;
    if ( this->mOldSeconds != v6 )
    {
      LODWORD(numArgs) = v5 / 1000 % 60;
      UFG::qSPrintf(dest, 20, "%d:%02d", (unsigned int)(v5 / 1000 / 60), numArgs);
      if ( (pargs.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = VT_String;
      pargs.mValue.pString = dest;
      Scaleform::GFx::Movie::Invoke(pObject, "ContactList_UpdatedConnectedTime", 0i64, &pargs, 1u);
    }
    this->mOldSeconds = v6;
    `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 91
// RVA: 0x5D1260
void __fastcall UFG::UIHK_PDAIncomingCallWidget::Activate(
        UFG::UIHK_PDAIncomingCallWidget *this,
        const char *callerName,
        const char *portrait,
        bool outgoing,
        bool voiceMail)
{
  UFG::allocator::free_link *v7; // rax
  __int64 v8; // rax
  __int64 v9; // rdi
  const char *v10; // rbx
  unsigned int v11; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::qString *v15; // rbx
  UFG::allocator::free_link *v16; // rax
  UFG::allocator::free_link *v17; // rbx
  UFG::allocator::free_link *v18; // rsi
  __int64 v19; // rbx
  UFG::qString result; // [rsp+40h] [rbp-38h] BYREF

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
      if ( outgoing )
        v10 = "$PDA_OUTGOING_CALL";
    }
    if ( v10 )
    {
      if ( *v10 == 36 )
        ++v10;
      v11 = UFG::qStringHashUpper32(v10, -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v13 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v11)) == 0i64 )
        v13 = v10;
      UFG::qString::FormatEx(&result, v13, this->mCallerName.mData);
    }
    else
    {
      UFG::qString::FormatEx(&result, 0i64, this->mCallerName.mData);
    }
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
      v17 = v16 + 1;
      `eh vector constructor iterator(&v16[1], 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    }
    else
    {
      v17 = 0i64;
    }
    *(_QWORD *)(v9 + 64) = v17;
    v18 = *(UFG::allocator::free_link **)(*(_QWORD *)(v9 + 80) + 24i64);
    if ( ((__int64)v17[3].mNext & 0x40) != 0 )
    {
      ((void (__fastcall *)(UFG::allocator::free_link *, UFG::allocator::free_link *, UFG::allocator::free_link *))v17[2].mNext->mNext[2].mNext)(
        v17[2].mNext,
        v17,
        v17[4].mNext);
      v17[2].mNext = 0i64;
    }
    LODWORD(v17[3].mNext) = 6;
    v17[4].mNext = v18;
    v19 = *(_QWORD *)(v9 + 64);
    if ( (*(_DWORD *)(v19 + 72) & 0x40) != 0 )
    {
      (*(void (__fastcall **)(_QWORD, __int64, _QWORD))(**(_QWORD **)(v19 + 64) + 16i64))(
        *(_QWORD *)(v19 + 64),
        v19 + 48,
        *(_QWORD *)(v19 + 80));
      *(_QWORD *)(v19 + 64) = 0i64;
    }
    *(_DWORD *)(v19 + 72) = 2;
    *(_BYTE *)(v19 + 80) = outgoing;
    if ( *(_DWORD *)(v9 + 44) )
      UFG::UIScreenInvokeQueue::Add(&UFG::UIHK_PDAWidget::mScreenInvokeQueue, (UFG::UIScreenInvoke *)v9);
    this->mState = STATE_PHONE_CONTACTS;
    UFG::qString::~qString(&result);
  }
}

// File Line: 154
// RVA: 0x5D3810
void __fastcall UFG::UIHK_PDAIncomingCallWidget::Answer(UFG::UIHK_PDAIncomingCallWidget *this)
{
  UFG::allocator::free_link *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rsi
  unsigned int v5; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v7; // rax
  unsigned int v8; // eax
  UFG::UIGfxTranslator *v9; // rcx
  UFG::allocator::free_link *v10; // rax
  UFG::qString *v11; // rdi
  UFG::allocator::free_link *v12; // rax
  UFG::allocator::free_link *v13; // rdi
  UFG::allocator::free_link *v14; // rbp
  __int64 v15; // rbp
  __int64 v16; // rdi
  UFG::qString result; // [rsp+38h] [rbp-40h] BYREF

  this->mState = STATE_INCOMING_CALL;
  if ( !this->mInputLocker.mAcquired )
  {
    UFG::SetInputMode_PDA_On(UFG::gActiveControllerNum);
    ++UFG::UIHKGameplayHelpWidget::mLocked;
    ++UFG::UIHK_PDAWidget::mInputLocked;
    this->mInputLocker.mAcquired = 1;
  }
  UFG::ActivateInputSubMode(ISM_PHONE_CALL, UFG::gActiveControllerNum);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xD92517u, 0i64, 0, 0i64);
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
    if ( this->mVoiceMail )
    {
      v5 = UFG::qStringHashUpper32("PDA_VOICEMAIL", -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v7 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v5)) == 0i64 )
      {
        UFG::qString::FormatEx(&result, "PDA_VOICEMAIL", this->mCallerName.mData);
LABEL_17:
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
          this->mCallerPortrait.mData,
          this->mCallerPortrait.mLength,
          0i64,
          0);
        UFG::qString::Set((UFG::qString *)(v4 + 24), "Phone_AnswerCall");
        *(_DWORD *)(v4 + 72) = 2;
        v12 = UFG::qMalloc(0x68ui64, "UIHK_PDAIncomingCallWidget GFxValue[]", 0i64);
        if ( v12 )
        {
          LODWORD(v12->mNext) = 2;
          v13 = v12 + 1;
          `eh vector constructor iterator(
            &v12[1],
            0x30ui64,
            2,
            (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        }
        else
        {
          v13 = 0i64;
        }
        *(_QWORD *)(v4 + 64) = v13;
        v14 = *(UFG::allocator::free_link **)(*(_QWORD *)(v4 + 80) + 24i64);
        if ( ((__int64)v13[3].mNext & 0x40) != 0 )
        {
          ((void (__fastcall *)(UFG::allocator::free_link *, UFG::allocator::free_link *, UFG::allocator::free_link *))v13[2].mNext->mNext[2].mNext)(
            v13[2].mNext,
            v13,
            v13[4].mNext);
          v13[2].mNext = 0i64;
        }
        LODWORD(v13[3].mNext) = 6;
        v13[4].mNext = v14;
        v15 = *(_QWORD *)(*(_QWORD *)(v4 + 80) + 64i64);
        v16 = *(_QWORD *)(v4 + 64);
        if ( (*(_DWORD *)(v16 + 72) & 0x40) != 0 )
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
        this->mOldSeconds = -1;
        this->mTimer = 0.0;
        this->mUpdateTimer = 1;
        UFG::qString::~qString(&result);
        return;
      }
    }
    else
    {
      v8 = UFG::qStringHashUpper32("PDA_CONNECTED", -1);
      v9 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v9 || (v7 = (const char *)v9->vfptr[5].__vecDelDtor(v9, v8)) == 0i64 )
        v7 = "PDA_CONNECTED";
    }
    UFG::qString::FormatEx(&result, v7, this->mCallerName.mData);
    goto LABEL_17;
  }
}

// File Line: 185
// RVA: 0x5EC890
void __fastcall UFG::UIHK_PDAIncomingCallWidget::HangUp(UFG::UIHK_PDAIncomingCallWidget *this, bool playSound)
{
  UFG::allocator::free_link *v3; // rax
  UFG::UIScreenInvoke *v4; // rbx
  UFG::allocator::free_link *v5; // rax

  this->mState = STATE_IDLE;
  UFG::UIHK_PDAIncomingCallWidget::ReleaseInputLock(this, "HangUp");
  if ( playSound && UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x67B8209Du, 0i64, 0, 0i64);
  v3 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x40ui64, "UIHK_PDAIncomingCallWidget ScreenInvoke", 0i64, 1u);
  v4 = (UFG::UIScreenInvoke *)v3;
  if ( v3 )
  {
    v5 = v3 + 1;
    v5->mNext = v5;
    v5[1].mNext = v5;
    v4->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable;
    UFG::qString::qString(&v4->command, &customCaption);
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
void __fastcall UFG::UIHK_PDAIncomingCallWidget::SetCallerName(
        UFG::UIHK_PDAIncomingCallWidget *this,
        const char *callerName,
        const char *portrait,
        bool voiceMail)
{
  const char *v6; // rbx
  const char *v8; // rax
  unsigned int v9; // eax
  UFG::UIGfxTranslator *m_translator; // rcx

  v6 = callerName;
  if ( callerName )
  {
    if ( *callerName == $ )
      v6 = callerName + 1;
    v9 = UFG::qStringHashUpper32(v6, -1);
    m_translator = UFG::UIScreenManager::s_instance->m_translator;
    if ( !m_translator || (v8 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v9)) == 0i64 )
      v8 = v6;
  }
  else
  {
    v8 = 0i64;
  }
  UFG::qString::Set(&this->mCallerName, v8);
  UFG::qString::Set(&this->mCallerPortrait, portrait);
  this->mVoiceMail = voiceMail;
}

// File Line: 237
// RVA: 0x600BD0
void __fastcall UFG::UIHK_PDAIncomingCallWidget::ReleaseInputLock(
        UFG::UIHK_PDAIncomingCallWidget *this,
        const char *trace)
{
  int v4; // eax

  UFG::DeactivateInputSubMode(ISM_PHONE_CALL, UFG::gActiveControllerNum);
  if ( this->mInputLocker.mAcquired )
  {
    UFG::qPrintf("PDAInputLock released by %s through %s\n", this->mInputLocker.mOwner.mData, trace);
    if ( UFG::UIHK_PDAWidget::mInputLocked )
    {
      UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
      v4 = UFG::UIHKGameplayHelpWidget::mLocked;
      if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
        v4 = --UFG::UIHKGameplayHelpWidget::mLocked;
      if ( v4 < 1 )
        UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
      --UFG::UIHK_PDAWidget::mInputLocked;
    }
    this->mInputLocker.mAcquired = 0;
  }
}

