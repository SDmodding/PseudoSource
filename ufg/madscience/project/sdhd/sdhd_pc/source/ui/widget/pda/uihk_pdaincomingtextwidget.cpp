// File Line: 45
// RVA: 0x5CDBF0
void __fastcall UFG::UIHK_PDAIncomingTextWidget::~UIHK_PDAIncomingTextWidget(UFG::UIHK_PDAIncomingTextWidget *this)
{
  UFG::UIHK_PDAIncomingTextWidget *v1; // rbx
  signed __int64 v2; // rbx
  int v3; // eax

  v1 = this;
  if ( this->mState )
    UFG::UIHK_PDAIncomingTextWidget::DismissMessage(this, DISMISS_CAUSE_DEACTIVATE);
  v2 = (signed __int64)&v1->mInputLocker;
  if ( *(_BYTE *)(v2 + 40) )
  {
    if ( UFG::UIHK_PDAWidget::mInputLocked )
    {
      UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
      v3 = UFG::UIHKGameplayHelpWidget::mLocked;
      if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
        v3 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
      if ( v3 < 1 )
        UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
      --UFG::UIHK_PDAWidget::mInputLocked;
    }
    *(_BYTE *)(v2 + 40) = 0;
  }
  UFG::qString::~qString((UFG::qString *)v2);
}

// File Line: 67
// RVA: 0x5EB340
void __fastcall UFG::UIHK_PDAIncomingTextWidget::HandleMessage(UFG::UIHK_PDAIncomingTextWidget *this, UFG::UIScreen *screen, unsigned int msgId)
{
  bool v3; // zf

  if ( this->mState == 2 )
  {
    JUMPOUT(msgId, UI_HASH_DPAD_UP_PRESSED_30, UFG::UIHK_PDAIncomingTextWidget::DisplayMessage);
  }
  else
  {
    if ( this->mState == 4 )
    {
      v3 = msgId == UI_HASH_BUTTON_BACK_RELEASED_30;
    }
    else
    {
      if ( this->mState != 5 )
        return;
      v3 = msgId == UI_HASH_BUTTON_ACCEPT_RELEASED_30;
    }
    if ( v3 )
      UFG::UIHK_PDAIncomingTextWidget::DismissMessage(this, DISMISS_CAUSE_INPUT);
  }
}

// File Line: 101
// RVA: 0x5D14E0
void __fastcall UFG::UIHK_PDAIncomingTextWidget::Activate(UFG::UIHK_PDAIncomingTextWidget *this, const char *textMessage, const char *contactName, bool outgoing, const char *contactImage)
{
  bool v5; // r13
  const char *v6; // rbp
  const char *v7; // rsi
  UFG::UIHK_PDAIncomingTextWidget *v8; // r12
  const char *v9; // r14
  UFG::allocator::free_link *v10; // rax
  int v11; // ebx
  __int64 v12; // rax
  __int64 v13; // rdi
  UFG::allocator::free_link *v14; // rax
  signed __int64 v15; // r15
  const char *v16; // rax
  unsigned int v17; // eax
  UFG::UIGfxTranslator *v18; // rcx
  const char *v19; // rax
  unsigned int v20; // eax
  UFG::UIGfxTranslator *v21; // rcx
  const char *v22; // rax
  unsigned int v23; // eax
  UFG::UIGfxTranslator *v24; // rcx
  UFG::allocator::free_link *v25; // rax
  signed __int64 v26; // rsi
  __int64 v27; // rbp
  __int64 v28; // rbp
  __int64 v29; // rsi
  __int64 v30; // rsi
  __int64 v31; // rbp
  signed __int64 v32; // rsi

  v5 = outgoing;
  v6 = contactName;
  v7 = textMessage;
  v8 = this;
  v9 = contactImage;
  UFG::UIHK_PDATextInboxWidget::SaveMessage(textMessage, contactName, outgoing, contactImage);
  v10 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x58ui64, "UIHK_PDAIncomingTextWidget", 0i64, 1u);
  v11 = 0;
  if ( v10 )
  {
    UFG::UIScreenInvokeValueArgs::UIScreenInvokeValueArgs((UFG::UIScreenInvokeValueArgs *)v10);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  v14 = UFG::qMalloc(0x80ui64, "UIHK_PDAIncomingTextWidget qString[]", 0i64);
  if ( v14 )
  {
    LODWORD(v14->mNext) = 3;
    v15 = (signed __int64)&v14[1];
    `eh vector constructor iterator'(&v14[1], 0x28ui64, 3, (void (__fastcall *)(void *))UFG::qString::qString);
  }
  else
  {
    v15 = 0i64;
  }
  *(_QWORD *)(v13 + 80) = v15;
  if ( v7 )
  {
    if ( *v7 == 36 )
      ++v7;
    v17 = UFG::qStringHashUpper32(v7, 0xFFFFFFFF);
    v18 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v18
      || (v16 = (const char *)v18->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v18->vfptr, v17)) == 0i64 )
    {
      v16 = v7;
    }
  }
  else
  {
    v16 = 0i64;
  }
  UFG::qString::Set(*(UFG::qString **)(v13 + 80), v16);
  if ( v6 )
  {
    if ( *v6 == 36 )
      ++v6;
    v20 = UFG::qStringHashUpper32(v6, 0xFFFFFFFF);
    v21 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v21
      || (v19 = (const char *)v21->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, v20)) == 0i64 )
    {
      v19 = v6;
    }
  }
  else
  {
    v19 = 0i64;
  }
  UFG::qString::Set((UFG::qString *)(*(_QWORD *)(v13 + 80) + 40i64), v19);
  if ( contactImage )
  {
    if ( *contactImage == 36 )
      v9 = contactImage + 1;
    v23 = UFG::qStringHashUpper32(v9, 0xFFFFFFFF);
    v24 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v24
      || (v22 = (const char *)v24->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v24->vfptr, v23)) == 0i64 )
    {
      v22 = v9;
    }
  }
  else
  {
    v22 = 0i64;
  }
  UFG::qString::Set((UFG::qString *)(*(_QWORD *)(v13 + 80) + 80i64), v22);
  UFG::qString::Set((UFG::qString *)(v13 + 24), "Phone_SetTextMessage");
  *(_DWORD *)(v13 + 72) = 4;
  v25 = UFG::qMalloc(0xC8ui64, "UIHK_PDAIncomingTextWidget GFxValue[]", 0i64);
  if ( v25 )
  {
    LODWORD(v25->mNext) = 4;
    v26 = (signed __int64)&v25[1];
    `eh vector constructor iterator'(&v25[1], 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  }
  else
  {
    v26 = 0i64;
  }
  *(_QWORD *)(v13 + 64) = v26;
  v27 = *(_QWORD *)(*(_QWORD *)(v13 + 80) + 24i64);
  if ( (*(_DWORD *)(v26 + 24) >> 6) & 1 )
  {
    (*(void (__fastcall **)(_QWORD, signed __int64, _QWORD))(**(_QWORD **)(v26 + 16) + 16i64))(
      *(_QWORD *)(v26 + 16),
      v26,
      *(_QWORD *)(v26 + 32));
    *(_QWORD *)(v26 + 16) = 0i64;
  }
  *(_DWORD *)(v26 + 24) = 6;
  *(_QWORD *)(v26 + 32) = v27;
  v28 = *(_QWORD *)(*(_QWORD *)(v13 + 80) + 64i64);
  v29 = *(_QWORD *)(v13 + 64);
  if ( (*(_DWORD *)(v29 + 72) >> 6) & 1 )
  {
    (*(void (__fastcall **)(_QWORD, __int64, _QWORD))(**(_QWORD **)(v29 + 64) + 16i64))(
      *(_QWORD *)(v29 + 64),
      v29 + 48,
      *(_QWORD *)(v29 + 80));
    *(_QWORD *)(v29 + 64) = 0i64;
  }
  *(_DWORD *)(v29 + 72) = 6;
  *(_QWORD *)(v29 + 80) = v28;
  v30 = *(_QWORD *)(v13 + 64);
  if ( (*(_DWORD *)(v30 + 120) >> 6) & 1 )
  {
    (*(void (__fastcall **)(_QWORD, __int64, _QWORD))(**(_QWORD **)(v30 + 112) + 16i64))(
      *(_QWORD *)(v30 + 112),
      v30 + 96,
      *(_QWORD *)(v30 + 128));
    *(_QWORD *)(v30 + 112) = 0i64;
  }
  *(_DWORD *)(v30 + 120) = 2;
  *(_BYTE *)(v30 + 128) = v5;
  v31 = *(_QWORD *)(*(_QWORD *)(v13 + 80) + 104i64);
  v32 = *(_QWORD *)(v13 + 64) + 144i64;
  if ( (*(_DWORD *)(*(_QWORD *)(v13 + 64) + 168i64) >> 6) & 1 )
  {
    (*(void (__fastcall **)(_QWORD, signed __int64, _QWORD))(**(_QWORD **)(*(_QWORD *)(v13 + 64) + 160i64) + 16i64))(
      *(_QWORD *)(*(_QWORD *)(v13 + 64) + 160i64),
      *(_QWORD *)(v13 + 64) + 144i64,
      *(_QWORD *)(*(_QWORD *)(v13 + 64) + 176i64));
    *(_QWORD *)(v32 + 16) = 0i64;
  }
  *(_DWORD *)(v32 + 24) = 6;
  *(_QWORD *)(v32 + 32) = v31;
  if ( *(_DWORD *)(v13 + 44) )
    UFG::UIScreenInvokeQueue::Add(&UFG::UIHK_PDAWidget::mScreenInvokeQueue, (UFG::UIScreenInvoke *)v13);
  LOBYTE(v11) = v5 != 0;
  v8->mState = v11 + 2;
  UFG::UIHK_PDAIncomingTextWidget::DisplayMessage(v8);
}

// File Line: 151
// RVA: 0x5D6730
void __fastcall UFG::UIHK_PDAIncomingTextWidget::DisplayMessage(UFG::UIHK_PDAIncomingTextWidget *this)
{
  UFG::UIHK_PDAIncomingTextWidget *v1; // rbx
  UFG::UIHK_PDAIncomingTextWidget::eState v2; // ecx
  UFG::InputActionData *v3; // rax
  UFG::InputActionData *v4; // rax
  bool v5; // al
  UFG::allocator::free_link *v6; // rax
  UFG::UIScreenInvoke *v7; // rax
  UFG::UIScreenInvoke *v8; // rbx

  v1 = this;
  v2 = this->mState;
  if ( (unsigned int)(v2 - 4) > 1 )
  {
    v1->mState = (v2 != 2) + 4;
    *(_WORD *)&v1->mMessageRead = 0;
    v3 = UFG::ActionDef_UIAcceptRepeat.mDataPerController[UFG::gActiveControllerNum];
    v5 = 1;
    if ( !v3 || !v3->mActionTrue )
    {
      v4 = UFG::ActionDef_UIBackRepeat.mDataPerController[UFG::gActiveControllerNum];
      if ( !v4 || !v4->mActionTrue )
        v5 = 0;
    }
    v1->mIgnoreButtonOnce = v5;
    *(_QWORD *)&v1->mDismissCause = 0i64;
    if ( !v1->mInputLocker.mAcquired )
    {
      UFG::SetInputMode_PDA_On(UFG::gActiveControllerNum);
      ++UFG::UIHKGameplayHelpWidget::mLocked;
      ++UFG::UIHK_PDAWidget::mInputLocked;
      v1->mInputLocker.mAcquired = 1;
    }
    v6 = UFG::qMemoryPool::Allocate(
           &gScaleformMemoryPool,
           0x58ui64,
           "UIHK_PDAIncomingTextWidget UIScreenInvokeValueArgs",
           0i64,
           1u);
    if ( v6 )
    {
      UFG::UIScreenInvokeValueArgs::UIScreenInvokeValueArgs((UFG::UIScreenInvokeValueArgs *)v6);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    UFG::qString::Set(&v8->command, "Phone_DisplayTextMessage");
    if ( v8 && v8->command.mLength )
      UFG::UIScreenInvokeQueue::Add(&UFG::UIHK_PDAWidget::mScreenInvokeQueue, v8);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x9E75334E,
        0i64,
        0,
        0i64);
  }
}

// File Line: 171
// RVA: 0x5D6500
void __fastcall UFG::UIHK_PDAIncomingTextWidget::DismissMessage(UFG::UIHK_PDAIncomingTextWidget *this, UFG::UIHK_PDAIncomingTextWidget::eDismissCause dismissCause)
{
  UFG::UIHK_PDAIncomingTextWidget *v2; // rbx
  int v3; // eax
  UFG::allocator::free_link *v4; // rax
  UFG::UIScreenInvoke *v5; // rbx
  UFG::allocator::free_link *v6; // rax

  v2 = this;
  if ( dismissCause != 3 )
    goto LABEL_23;
  if ( this->mIgnoreButtonOnce )
  {
    this->mIgnoreButtonOnce = 0;
    return;
  }
  if ( this->mDisplayTime >= 1.0 )
  {
LABEL_23:
    this->mState = 0;
    this->mMessageRead = 1;
    this->mDismissCause = dismissCause;
    if ( this->mInputLocker.mAcquired )
    {
      if ( UFG::UIHK_PDAWidget::mInputLocked )
      {
        UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
        v3 = UFG::UIHKGameplayHelpWidget::mLocked;
        if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
          v3 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
        if ( v3 < 1 )
          UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
        --UFG::UIHK_PDAWidget::mInputLocked;
      }
      v2->mInputLocker.mAcquired = 0;
    }
    v4 = UFG::qMemoryPool::Allocate(
           &gScaleformMemoryPool,
           0x40ui64,
           "UIHK_PDAIncomingTextWidget ScreenInvoke",
           0i64,
           1u);
    v5 = (UFG::UIScreenInvoke *)v4;
    if ( v4 )
    {
      v6 = v4 + 1;
      v6->mNext = v6;
      v6[1].mNext = v6;
      v5->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable';
      UFG::qString::qString(&v5->command, &customWorldMapCaption);
    }
    else
    {
      v5 = 0i64;
    }
    UFG::qString::Set(&v5->command, "Phone_DismissTextMessage");
    if ( v5 && v5->command.mLength )
      UFG::UIScreenInvokeQueue::Add(&UFG::UIHK_PDAWidget::mScreenInvokeQueue, v5);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x4AAC5E6Bu,
        0i64,
        0,
        0i64);
  }
}

// File Line: 191
// RVA: 0x5D66B0
void __fastcall UFG::UIHK_PDAIncomingTextWidget::DisplayHelpbar(UFG::UIHK_PDAIncomingTextWidget *this)
{
  UFG::allocator::free_link *v1; // rax
  UFG::UIScreenInvoke *v2; // rax
  UFG::UIScreenInvoke *v3; // rbx

  v1 = UFG::qMemoryPool::Allocate(
         &gScaleformMemoryPool,
         0x58ui64,
         "UIHK_PDAIncomingTextWidget UIScreenInvokeValueArgs",
         0i64,
         1u);
  if ( v1 )
  {
    UFG::UIScreenInvokeValueArgs::UIScreenInvokeValueArgs((UFG::UIScreenInvokeValueArgs *)v1);
    v3 = v2;
  }
  else
  {
    v3 = 0i64;
  }
  UFG::qString::Set(&v3->command, "Phone_DisplayTextMessageHelpbar");
  if ( v3 )
  {
    if ( v3->command.mLength )
      UFG::UIScreenInvokeQueue::Add(&UFG::UIHK_PDAWidget::mScreenInvokeQueue, v3);
  }
}

