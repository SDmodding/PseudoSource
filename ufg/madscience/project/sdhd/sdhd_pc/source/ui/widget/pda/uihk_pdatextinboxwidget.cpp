// File Line: 26
// RVA: 0x1567370
__int64 dynamic_initializer_for__UFG::UIHK_PDATextInboxWidget::mSavedMessages__()
{
  `eh vector constructor iterator(
    (char *)UFG::UIHK_PDATextInboxWidget::mSavedMessages,
    0x80ui64,
    1,
    (void (__fastcall *)(void *))UFG::UIHK_PDATextMessageData::UIHK_PDATextMessageData);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHK_PDATextInboxWidget::mSavedMessages__);
}

// File Line: 69
// RVA: 0x5EB480
char __fastcall UFG::UIHK_PDATextInboxWidget::HandleMessage(
        UFG::UIHK_PDATextInboxWidget *this,
        UFG::UIScreen *screen,
        unsigned int msgId)
{
  if ( this->mState == STATE_IDLE )
    return 0;
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30
    || msgId == UI_HASH_THUMBSTICK_RIGHT_UP_30
    || msgId == UI_HASH_DPAD_DOWN_PRESSED_30
    || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
    || msgId == UI_HASH_THUMBSTICK_RIGHT_DOWN_30 )
  {
    Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, "TextInbox_ScrollPrev", 0i64, 0i64, 0);
    return 1;
  }
  else if ( msgId == UI_HASH_BUTTON_BACK_RELEASED_30 )
  {
    UFG::UIHK_PDATextInboxWidget::Deactivate(this);
    return 1;
  }
  else
  {
    if ( msgId != UI_HASH_BUTTON_ACCEPT_RELEASED_30 )
      return 0;
    UFG::UIScreenManagerBase::queueMessage(
      UFG::UIScreenManager::s_instance,
      UI_HASH_LIST_OPTION_SELECTED_30,
      0xFFFFFFFF);
    return 1;
  }
}

// File Line: 109
// RVA: 0x5D6040
void __fastcall UFG::UIHK_PDATextInboxWidget::Deactivate(UFG::UIHK_PDATextInboxWidget *this)
{
  if ( this->mState )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4AAC5E6Bu, 0i64, 0, 0i64);
    this->mState = STATE_TEXT_INBOX;
  }
}

// File Line: 123
// RVA: 0x6039E0
void __fastcall UFG::UIHK_PDATextInboxWidget::SaveMessage(
        const char *messageText,
        const char *contactName,
        bool outgoing,
        const char *contactImage)
{
  unsigned int v5; // eax
  UFG::TimeOfDayManager *Instance; // rax
  float m_SecondsSinceMidnight; // xmm0_4

  v5 = UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex + 1;
  if ( UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex != -1 )
    v5 = 0;
  UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex = v5;
  UFG::qString::Set(&UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)v5].Message, messageText);
  UFG::qString::Set(
    &UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex].Contact,
    contactName);
  UFG::qString::Set(
    &UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex].ContactImage,
    contactImage);
  UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex].Outgoing = outgoing;
  Instance = UFG::TimeOfDayManager::GetInstance();
  if ( Instance )
    m_SecondsSinceMidnight = Instance->m_SecondsSinceMidnight;
  else
    m_SecondsSinceMidnight = 0.0;
  UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex].Time = (int)m_SecondsSinceMidnight;
}

// File Line: 139
// RVA: 0x5D5780
void UFG::UIHK_PDATextInboxWidget::ClearMessages(void)
{
  unsigned __int64 v0; // rax

  UFG::qString::Set(
    &UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex].Message,
    &customCaption);
  UFG::qString::Set(
    &UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex].Contact,
    &customCaption);
  v0 = (unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex << 7;
  *(&UFG::UIHK_PDATextInboxWidget::mSavedMessages[0].Outgoing + v0) = 0;
  *(int *)((char *)&UFG::UIHK_PDATextInboxWidget::mSavedMessages[0].Time + v0) = 0;
  UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex = 0;
}

// File Line: 152
// RVA: 0x5E3AB0
void __fastcall UFG::UIHK_PDATextInboxWidget::Flash_Show(UFG::UIHK_PDATextInboxWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // r15
  UFG::UIHK_PDATextMessageData *v3; // rdi
  unsigned int Time; // ecx
  signed int v5; // r8d
  __int64 v6; // r9
  const char *v7; // rcx
  __int64 v8; // r8
  const char *mData; // rsi
  const char *v10; // rax
  unsigned int v11; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  char *v13; // rsi
  const char *v14; // rsi
  char *v15; // r14
  unsigned int v16; // eax
  UFG::UIGfxTranslator *v17; // rcx
  const char *v18; // rcx
  unsigned int v19; // eax
  UFG::UIGfxTranslator *v20; // rcx
  bool Outgoing; // si
  char *v22; // rdi
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  char v24[8]; // [rsp+60h] [rbp-88h] BYREF
  char *v25; // [rsp+68h] [rbp-80h]
  __int64 v26; // [rsp+70h] [rbp-78h]
  int v27[4]; // [rsp+78h] [rbp-70h] BYREF
  __int64 v28; // [rsp+88h] [rbp-60h]
  int v29; // [rsp+90h] [rbp-58h]
  __int64 v30; // [rsp+98h] [rbp-50h]
  char v31[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v32; // [rsp+B8h] [rbp-30h]
  int v33; // [rsp+C0h] [rbp-28h]
  char *v34; // [rsp+C8h] [rbp-20h]
  __int64 v35; // [rsp+D8h] [rbp-10h]
  UFG::qString v36; // [rsp+E0h] [rbp-8h] BYREF
  UFG::qString v37; // [rsp+108h] [rbp+20h] BYREF

  v35 = -2i64;
  pObject = screen->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  UFG::qString::qString(&v37);
  UFG::qString::qString(&v36);
  v3 = &UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex];
  if ( v3->Message.mLength )
  {
    Time = v3->Time;
    v5 = Time / 0xE10;
    v6 = Time % 0xE10 / 0x3C;
    v7 = "PM";
    if ( v5 < 12 )
      v7 = "AM";
    v8 = (unsigned int)(v5 % -12);
    if ( !(_DWORD)v8 )
      v8 = 12i64;
    UFG::qString::Format(&v37, "%d:%02d %s", v8, v6, v7);
    mData = v3->Message.mData;
    if ( mData )
    {
      if ( *mData == 36 )
        ++mData;
      v11 = UFG::qStringHashUpper32(mData, -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v10 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v11)) == 0i64 )
        v10 = mData;
    }
    else
    {
      v10 = 0i64;
    }
    UFG::qString::Format(&v36, "(%s) %s", v37.mData, v10);
    v13 = v36.mData;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_String;
    ptr.mValue.pString = v13;
    v14 = v3->Contact.mData;
    if ( v14 )
    {
      if ( *v14 == 36 )
        ++v14;
      v16 = UFG::qStringHashUpper32(v14, -1);
      v17 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v17 || (v15 = (char *)v17->vfptr[5].__vecDelDtor(v17, v16)) == 0i64 )
        v15 = (char *)v14;
    }
    else
    {
      v15 = 0i64;
    }
    v18 = v3->ContactImage.mData;
    if ( v18 )
    {
      if ( *v18 == 36 )
        ++v18;
      v19 = UFG::qStringHashUpper32(v18, -1);
      v20 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v20 )
        v20->vfptr[5].__vecDelDtor(v20, v19);
    }
    if ( (v27[0] & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v26 + 16i64))(v26, v24, v25);
      v26 = 0i64;
    }
    v27[0] = 6;
    v25 = v15;
    Outgoing = v3->Outgoing;
    if ( (v29 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v28 + 16i64))(v28, v27, v30);
      v28 = 0i64;
    }
    LOBYTE(v30) = Outgoing;
    v22 = v3->ContactImage.mData;
  }
  else
  {
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_String;
    ptr.mValue.pString = "$PDA_NO_MESSAGES";
    if ( (v27[0] & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v26 + 16i64))(v26, v24, v25);
      v26 = 0i64;
    }
    v27[0] = 6;
    v22 = &customCaption;
    v25 = &customCaption;
    if ( (v29 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v28 + 16i64))(v28, v27, v30);
      v28 = 0i64;
    }
    LOBYTE(v30) = 0;
  }
  v29 = 2;
  if ( (v33 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v32 + 16i64))(v32, v31, v34);
    v32 = 0i64;
  }
  v34 = v22;
  v33 = 6;
  Scaleform::GFx::Movie::Invoke(pObject, "TextInbox_Show", 0i64, &ptr, 4u);
  UFG::qString::~qString(&v36);
  UFG::qString::~qString(&v37);
  `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

