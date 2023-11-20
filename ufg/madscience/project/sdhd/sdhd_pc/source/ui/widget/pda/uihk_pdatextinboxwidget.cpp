// File Line: 26
// RVA: 0x1567370
__int64 dynamic_initializer_for__UFG::UIHK_PDATextInboxWidget::mSavedMessages__()
{
  `eh vector constructor iterator(
    UFG::UIHK_PDATextInboxWidget::mSavedMessages,
    0x80ui64,
    1,
    (void (__fastcall *)(void *))UFG::UIHK_PDATextMessageData::UIHK_PDATextMessageData);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHK_PDATextInboxWidget::mSavedMessages__);
}

// File Line: 69
// RVA: 0x5EB480
char __fastcall UFG::UIHK_PDATextInboxWidget::HandleMessage(UFG::UIHK_PDATextInboxWidget *this, UFG::UIScreen *screen, unsigned int msgId)
{
  char result; // al

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
    result = 1;
  }
  else if ( msgId == UI_HASH_BUTTON_BACK_RELEASED_30 )
  {
    UFG::UIHK_PDATextInboxWidget::Deactivate(this);
    result = 1;
  }
  else
  {
    if ( msgId != UI_HASH_BUTTON_ACCEPT_RELEASED_30 )
      return 0;
    UFG::UIScreenManagerBase::queueMessage(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      UI_HASH_LIST_OPTION_SELECTED_30,
      0xFFFFFFFF);
    result = 1;
  }
  return result;
}

// File Line: 109
// RVA: 0x5D6040
void __fastcall UFG::UIHK_PDATextInboxWidget::Deactivate(UFG::UIHK_PDATextInboxWidget *this)
{
  UFG::UIHK_PDATextInboxWidget *v1; // rbx

  v1 = this;
  if ( this->mState )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x4AAC5E6Bu,
        0i64,
        0,
        0i64);
    v1->mState = 3;
  }
}

// File Line: 123
// RVA: 0x6039E0
void __fastcall UFG::UIHK_PDATextInboxWidget::SaveMessage(const char *messageText, const char *contactName, bool outgoing, const char *contactImage)
{
  const char *v4; // rbx
  unsigned int v5; // eax
  const char *v6; // rdi
  bool v7; // si
  UFG::TimeOfDayManager *v8; // rax
  float v9; // xmm0_4

  v4 = contactName;
  v5 = UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex + 1;
  v6 = contactImage;
  v7 = outgoing;
  if ( UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex < 0xFFFFFFFF )
    v5 = 0;
  UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex = v5;
  UFG::qString::Set(&UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)v5].Message, messageText);
  UFG::qString::Set(
    &UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex].Contact,
    v4);
  UFG::qString::Set(
    &UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex].ContactImage,
    v6);
  UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex].Outgoing = v7;
  v8 = UFG::TimeOfDayManager::GetInstance();
  if ( v8 )
    v9 = v8->m_SecondsSinceMidnight;
  else
    v9 = 0.0;
  UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex].Time = (signed int)v9;
}

// File Line: 139
// RVA: 0x5D5780
void UFG::UIHK_PDATextInboxWidget::ClearMessages(void)
{
  unsigned __int64 v0; // rax

  UFG::qString::Set(
    &UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex].Message,
    &customWorldMapCaption);
  UFG::qString::Set(
    &UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex].Contact,
    &customWorldMapCaption);
  v0 = (unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex << 7;
  *(&UFG::UIHK_PDATextInboxWidget::mSavedMessages[0].Outgoing + v0) = 0;
  *(int *)((char *)&UFG::UIHK_PDATextInboxWidget::mSavedMessages[0].Time + v0) = 0;
  UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex = 0;
}

// File Line: 152
// RVA: 0x5E3AB0
void __fastcall UFG::UIHK_PDATextInboxWidget::Flash_Show(UFG::UIHK_PDATextInboxWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // r15
  UFG::UIHK_PDATextMessageData *v3; // rdi
  unsigned int v4; // ecx
  signed int v5; // er8
  __int64 v6; // r9
  const char *v7; // rcx
  signed __int64 v8; // r8
  const char *v9; // rsi
  __int64 v10; // rax
  unsigned int v11; // eax
  UFG::UIGfxTranslator *v12; // rcx
  char *v13; // rsi
  const char *v14; // rsi
  char *v15; // r14
  unsigned int v16; // eax
  UFG::UIGfxTranslator *v17; // rcx
  const char *v18; // rcx
  unsigned int v19; // eax
  UFG::UIGfxTranslator *v20; // rcx
  bool v21; // si
  char *v22; // rdi
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v24; // [rsp+40h] [rbp-A8h]
  unsigned int v25; // [rsp+48h] [rbp-A0h]
  const char *v26; // [rsp+50h] [rbp-98h]
  char v27; // [rsp+60h] [rbp-88h]
  char *v28; // [rsp+68h] [rbp-80h]
  __int64 v29; // [rsp+70h] [rbp-78h]
  unsigned int v30; // [rsp+78h] [rbp-70h]
  __int64 v31; // [rsp+88h] [rbp-60h]
  unsigned int v32; // [rsp+90h] [rbp-58h]
  __int64 v33; // [rsp+98h] [rbp-50h]
  char v34; // [rsp+A8h] [rbp-40h]
  __int64 v35; // [rsp+B8h] [rbp-30h]
  unsigned int v36; // [rsp+C0h] [rbp-28h]
  char *v37; // [rsp+C8h] [rbp-20h]
  __int64 v38; // [rsp+D8h] [rbp-10h]
  UFG::qString v39; // [rsp+E0h] [rbp-8h]
  UFG::qString v40; // [rsp+108h] [rbp+20h]

  v38 = -2i64;
  v2 = screen->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  UFG::qString::qString(&v40);
  UFG::qString::qString(&v39);
  v3 = &UFG::UIHK_PDATextInboxWidget::mSavedMessages[(unsigned __int64)UFG::UIHK_PDATextInboxWidget::mLastSavedMessageIndex];
  if ( v3->Message.mLength )
  {
    v4 = v3->Time;
    v5 = v4 / 0xE10;
    v6 = v4 % 0xE10 / 0x3C;
    v7 = "PM";
    if ( v5 < 12 )
      v7 = "AM";
    v8 = (unsigned int)(v5 % -12);
    if ( !(_DWORD)v8 )
      v8 = 12i64;
    UFG::qString::Format(&v40, "%d:%02d %s", v8, v6, v7);
    v9 = v3->Message.mData;
    if ( v9 )
    {
      if ( *v9 == 36 )
        ++v9;
      v11 = UFG::qStringHashUpper32(v9, 0xFFFFFFFF);
      v12 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v12 || (v10 = (__int64)v12->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, v11)) == 0 )
        v10 = (__int64)v9;
    }
    else
    {
      v10 = 0i64;
    }
    UFG::qString::Format(&v39, "(%s) %s", v40.mData, v10);
    v13 = v39.mData;
    if ( (v25 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v24 + 16i64))(v24, &ptr, v26);
      v24 = 0i64;
    }
    v25 = 6;
    v26 = v13;
    v14 = v3->Contact.mData;
    if ( v14 )
    {
      if ( *v14 == 36 )
        ++v14;
      v16 = UFG::qStringHashUpper32(v14, 0xFFFFFFFF);
      v17 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v17 || (v15 = (char *)v17->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v17->vfptr, v16)) == 0i64 )
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
      v19 = UFG::qStringHashUpper32(v18, 0xFFFFFFFF);
      v20 = UFG::UIScreenManager::s_instance->m_translator;
      if ( v20 )
        v20->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v20->vfptr, v19);
    }
    if ( (v30 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v29 + 16i64))(v29, &v27, v28);
      v29 = 0i64;
    }
    v30 = 6;
    v28 = v15;
    v21 = v3->Outgoing;
    if ( (v32 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v31 + 16i64))(v31, &v30, v33);
      v31 = 0i64;
    }
    LOBYTE(v33) = v21;
    v22 = v3->ContactImage.mData;
  }
  else
  {
    if ( (v25 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v24 + 16i64))(v24, &ptr, v26);
      v24 = 0i64;
    }
    v25 = 6;
    v26 = "$PDA_NO_MESSAGES";
    if ( (v30 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v29 + 16i64))(v29, &v27, v28);
      v29 = 0i64;
    }
    v30 = 6;
    v22 = &customWorldMapCaption;
    v28 = &customWorldMapCaption;
    if ( (v32 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v31 + 16i64))(v31, &v30, v33);
      v31 = 0i64;
    }
    LOBYTE(v33) = 0;
  }
  v32 = 2;
  if ( (v36 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v35 + 16i64))(v35, &v34, v37);
    v35 = 0i64;
  }
  v37 = v22;
  v36 = 6;
  Scaleform::GFx::Movie::Invoke(v2, "TextInbox_Show", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
  UFG::qString::~qString(&v39);
  UFG::qString::~qString(&v40);
  `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

