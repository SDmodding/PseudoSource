// File Line: 54
// RVA: 0x1567E10
__int64 UFG::_dynamic_initializer_for__TxtMsgSymbol_List__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("List", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&TxtMsgSymbol_List, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__TxtMsgSymbol_List__);
}

// File Line: 55
// RVA: 0x1567E90
__int64 UFG::_dynamic_initializer_for__TxtMsgSymbol_MsgMarker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MsgMarker", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&TxtMsgSymbol_MsgMarker, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__TxtMsgSymbol_MsgMarker__);
}

// File Line: 56
// RVA: 0x1567E50
__int64 UFG::_dynamic_initializer_for__TxtMsgSymbol_Msg__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Message", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&TxtMsgSymbol_Msg, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__TxtMsgSymbol_Msg__);
}

// File Line: 57
// RVA: 0x1567F10
__int64 UFG::_dynamic_initializer_for__TxtMsgSymbol_Sender__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Sender", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&TxtMsgSymbol_Sender, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__TxtMsgSymbol_Sender__);
}

// File Line: 58
// RVA: 0x1567ED0
__int64 UFG::_dynamic_initializer_for__TxtMsgSymbol_Param1__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Param1", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&TxtMsgSymbol_Param1, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__TxtMsgSymbol_Param1__);
}

// File Line: 77
// RVA: 0x5C8520
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::UIHK_PDAPhoneContactsWidget(UFG::UIHK_PDAPhoneContactsWidget *this)
{
  UFG::UIHK_PDAPhoneContactsWidget *v1; // rbx
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::UIHK_PDAPhoneContactsWidgetVtbl *)&UFG::UIHK_PDAPhoneContactsWidget::`vftable';
  *(_QWORD *)&this->mState = 0i64;
  *(_QWORD *)&this->mSelectedIndex = 0i64;
  UFG::qString::qString(&this->mSelectedName);
  UFG::qString::qString(&v1->mSelectedSubOption);
  v1->mMissionList.p = 0i64;
  *(_QWORD *)&v1->mMissionList.size = 0i64;
  v1->mMessages.p = 0i64;
  *(_QWORD *)&v1->mMessages.size = 0i64;
  v1->mData = 0i64;
  UFG::qString::qString(&v1->mTraceName, &customWorldMapCaption);
  v1->mTraceSymbol.mUID = -1;
  UFG::qString::qString(&v1->mPerkGiverName, "$AMBIENT_PERKCONTACT_CONTACT_001");
  v1->mPerkGiverSymbol.mUID = -1;
  *(_WORD *)&v1->mShowingPerkIcon = 0;
  v1->mUpdateContactMethod = 0;
  v1->mSelectedSymbol.mUID = -1;
  v1->mSymbolList.p = 0i64;
  *(_QWORD *)&v1->mSymbolList.size = 0i64;
  v1->mNameList.p = 0i64;
  *(_QWORD *)&v1->mNameList.size = 0i64;
  v1->mPortraitList.p = 0i64;
  *(_QWORD *)&v1->mPortraitList.size = 0i64;
  v1->mPerkGiverSymbol = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, "PDAContact_JANE_TENG")->mUID;
}

// File Line: 91
// RVA: 0x5CDC80
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::~UIHK_PDAPhoneContactsWidget(UFG::UIHK_PDAPhoneContactsWidget *this)
{
  UFG::UIHK_PDAPhoneContactsWidget *v1; // rdi
  UFG::UIScreenTextureManager *v2; // rax
  UFG::qString *v3; // rcx
  unsigned int *v4; // rbx
  UFG::qString *v5; // rcx
  unsigned int *v6; // rbx
  UFG::qSymbol *v7; // rcx
  UFG::qSymbol *v8; // rbx
  UFG::UIHK_PDAPhoneContactsWidget::UIHKTxtMsgInfo *v9; // rcx
  UFG::qSymbol *v10; // rbx
  UFG::qString *v11; // rcx
  unsigned int *v12; // rbx

  v1 = this;
  this->vfptr = (UFG::UIHK_PDAPhoneContactsWidgetVtbl *)&UFG::UIHK_PDAPhoneContactsWidget::`vftable';
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v2, UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename);
  v3 = v1->mPortraitList.p;
  if ( v3 )
  {
    v4 = &v3[-1].mStringHash32;
    `eh vector destructor iterator'(
      v3,
      0x28ui64,
      v3[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v4);
  }
  v1->mPortraitList.p = 0i64;
  *(_QWORD *)&v1->mPortraitList.size = 0i64;
  v5 = v1->mNameList.p;
  if ( v5 )
  {
    v6 = &v5[-1].mStringHash32;
    `eh vector destructor iterator'(
      v5,
      0x28ui64,
      v5[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v6);
  }
  v1->mNameList.p = 0i64;
  *(_QWORD *)&v1->mNameList.size = 0i64;
  v7 = v1->mSymbolList.p;
  if ( v7 )
  {
    v8 = v7 - 1;
    `eh vector destructor iterator'(v7, 4ui64, v7[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v8);
  }
  v1->mSymbolList.p = 0i64;
  *(_QWORD *)&v1->mSymbolList.size = 0i64;
  UFG::qString::~qString(&v1->mPerkGiverName);
  UFG::qString::~qString(&v1->mTraceName);
  v9 = v1->mMessages.p;
  if ( v9 )
  {
    v10 = &v9[-1].symbol;
    `eh vector destructor iterator'(
      v9,
      0x30ui64,
      v9[-1].symbol.mUID,
      (void (__fastcall *)(void *))UFG::PersistentData::String::~String);
    operator delete[](v10);
  }
  v1->mMessages.p = 0i64;
  *(_QWORD *)&v1->mMessages.size = 0i64;
  v11 = v1->mMissionList.p;
  if ( v11 )
  {
    v12 = &v11[-1].mStringHash32;
    `eh vector destructor iterator'(
      v11,
      0x28ui64,
      v11[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v12);
  }
  v1->mMissionList.p = 0i64;
  *(_QWORD *)&v1->mMissionList.size = 0i64;
  UFG::qString::~qString(&v1->mSelectedSubOption);
  UFG::qString::~qString(&v1->mSelectedName);
}

// File Line: 99
// RVA: 0x6198E0
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::Update(UFG::UIHK_PDAPhoneContactsWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIHK_PDAPhoneContactsWidget::eState v3; // eax
  UFG::UIScreen *v4; // rdi
  UFG::UIHK_PDAPhoneContactsWidget *v5; // rbx
  const char *v6; // rax

  v3 = this->mState;
  v4 = screen;
  v5 = this;
  if ( v3 == 2 )
  {
    UFG::UIHK_PDAPhoneContactsWidget::Flash_Activate(this, screen);
  }
  else if ( v3 == 6 )
  {
    UFG::UIHK_PDAPhoneContactsWidget::Exit(this, screen, 0);
  }
  if ( v5->mShowingPerkIcon )
  {
    v6 = UFG::UIHK_PDAPhoneContactsWidget::GetActivePerk(v5);
    UFG::UIHK_PDAPhoneContactsWidget::SetSubMenuIcon(v5, v4, 0, v6);
  }
  if ( v5->mUpdateContactMethod )
  {
    UFG::UIHK_PDAPhoneContactsWidget::UpdateContactMethod(v5, v4);
    v5->mUpdateContactMethod = 0;
  }
}

// File Line: 137
// RVA: 0x5FE760
bool __fastcall UFG::UIHK_PDAPhoneContactsWidget::ProcessInput(UFG::UIHK_PDAPhoneContactsWidget *this, UFG::UIScreen *screen, unsigned int msgId)
{
  UFG::UIHK_PDAPhoneContactsWidget *v3; // rbx
  UFG::UIHK_PDAPhoneContactsWidget::eState v4; // ecx
  UFG::UIScreen *v5; // rsi
  bool result; // al
  int v7; // ecx

  v3 = this;
  v4 = this->mState;
  v5 = screen;
  if ( v4 <= (unsigned int)STATE_PHONE_CONTACTS || v4 == STATE_INCOMING_TEXT )
    return 0;
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x4F717979u,
        0i64,
        0,
        0i64);
    UFG::UIHK_PDAPhoneContactsWidget::ScrollPrev(v3);
    v3->mUpdateContactMethod = 1;
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x4F717979u,
        0i64,
        0,
        0i64);
    UFG::UIHK_PDAPhoneContactsWidget::ScrollNext(v3);
    v3->mUpdateContactMethod = 1;
    return 1;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_RELEASED_30 )
  {
    if ( v4 == 5 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x4AAC5E6Bu,
          0i64,
          0,
          0i64);
      v3->mState = 0;
      result = 1;
    }
    else
    {
      UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::m_ActionRequests.mBits[(signed __int64)(signed int)gActionRequest_PDAExit.m_EnumValue >> 6] |= 1i64 << (gActionRequest_PDAExit.m_EnumValue & 0x3F);
      UFG::UIHK_PDAPhoneContactsWidget::Exit(v3, v5, 0);
      result = 1;
    }
    return result;
  }
  if ( msgId != UI_HASH_BUTTON_ACCEPT_RELEASED_30 )
    return 0;
  v7 = v4 - 4;
  if ( !v7 )
    return 1;
  if ( v7 == 1 )
    return 0;
  UFG::UIHK_PDAPhoneContactsWidget::GetSelectedName(v3, screen);
  UFG::UIHK_PDAPhoneContactsWidget::GetSectedIndex(v3, v5);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0x9E75334E,
      0i64,
      0,
      0i64);
  UFG::UIHK_PDAPhoneContactsWidget::LaunchSubOption(v3, v5);
  UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::m_ActionRequests.mBits[(signed __int64)(signed int)gActionRequest_PDATalk.m_EnumValue >> 6] |= 1i64 << (gActionRequest_PDATalk.m_EnumValue & 0x3F);
  return 1;
}

// File Line: 213
// RVA: 0x5EB380
char __fastcall UFG::UIHK_PDAPhoneContactsWidget::HandleMessage(UFG::UIHK_PDAPhoneContactsWidget *this, UFG::UIScreen *screen, unsigned int msgId)
{
  if ( this->mState != 4 || msgId != UI_HASH_WIDGET_FADE_OUT_20 && msgId != UI_HASH_PAUSE_SCREEN_INIT_20 )
    return 0;
  UFG::UIHK_PDAPhoneContactsWidget::Exit(this, screen, 0);
  return 1;
}

// File Line: 277
// RVA: 0x5D9030
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::Flash_Activate(UFG::UIHK_PDAPhoneContactsWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rsi
  UFG::UIHK_PDAPhoneContactsWidget *v3; // rbx
  Scaleform::GFx::Movie *v4; // rdi

  v2 = screen;
  v3 = this;
  v4 = screen->mRenderable->m_movie.pObject;
  if ( v4 )
  {
    Scaleform::GFx::Movie::Invoke(v4, "ContactList_Init", 0i64, 0i64, 0);
    UFG::UIHK_PDAPhoneContactsWidget::PopulateList(v3, v2);
    Scaleform::GFx::Movie::Invoke(v4, "ContactList_Show", 0i64, 0i64, 0);
    if ( v3->mNumContacts <= 0 )
    {
      v3->mState = 4;
      Scaleform::GFx::Movie::Invoke(v4, "ContactList_PlayEmpty", 0i64, 0i64, 0);
    }
    else
    {
      v3->mState = 3;
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x1F004A69u,
          0i64,
          0,
          0i64);
    }
  }
}

// File Line: 319
// RVA: 0x5E90B0
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::GetSelectedName(UFG::UIHK_PDAPhoneContactsWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHK_PDAPhoneContactsWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // rcx
  char *v4; // rdx
  char v5; // [rsp+38h] [rbp-40h]
  __int64 v6; // [rsp+48h] [rbp-30h]
  unsigned int v7; // [rsp+50h] [rbp-28h]
  char *text; // [rsp+58h] [rbp-20h]

  if ( screen )
  {
    v2 = this;
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      v6 = 0i64;
      v7 = 0;
      Scaleform::GFx::Movie::Invoke(v3, "ContactList_GetSelectedName", (Scaleform::GFx::Value *)&v5, 0i64, 0);
      if ( v7 & 0x8F )
      {
        if ( (v7 >> 6) & 1 )
          v4 = *(char **)text;
        else
          v4 = text;
      }
      else
      {
        v4 = &customWorldMapCaption;
      }
      UFG::qString::Set(&v2->mSelectedName, v4);
      if ( (v7 >> 6) & 1 )
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v6 + 16i64))(v6, &v5, text);
    }
  }
}

// File Line: 345
// RVA: 0x5E8B40
signed __int64 __fastcall UFG::UIHK_PDAPhoneContactsWidget::GetSectedIndex(UFG::UIHK_PDAPhoneContactsWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHK_PDAPhoneContactsWidget *v2; // rbx
  Scaleform::GFx::Movie *v4; // rcx
  unsigned int v5; // ebx
  Scaleform::GFx::Value presult; // [rsp+38h] [rbp-40h]

  v2 = this;
  if ( !screen )
    return 0xFFFFFFFFi64;
  v4 = screen->mRenderable->m_movie.pObject;
  if ( !v4 )
    return 0xFFFFFFFFi64;
  presult.pObjectInterface = 0i64;
  presult.Type = 0;
  Scaleform::GFx::Movie::Invoke(v4, "ContactList_GetSelectedIndex", &presult, 0i64, 0);
  if ( presult.Type & 0x8F )
    v2->mSelectedIndex = (signed int)presult.mValue.NValue;
  else
    v2->mSelectedIndex = 0;
  v5 = v2->mSelectedIndex;
  if ( ((unsigned int)presult.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&presult.pObjectInterface->vfptr->gap8[8])(
      presult.pObjectInterface,
      &presult,
      *(_QWORD *)&presult.mValue.NValue);
    presult.pObjectInterface = 0i64;
  }
  return v5;
}

// File Line: 370
// RVA: 0x5F0740
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::LaunchSubOption(UFG::UIHK_PDAPhoneContactsWidget *this, UFG::UIScreen *screen)
{
  __int64 v2; // rax
  __int64 v3; // rax
  UFG::qSymbol *v4; // r8
  UFG::UIScreenTextureManager *v5; // rax
  __int64 contact; // [rsp+58h] [rbp+10h]
  __int64 *v7; // [rsp+60h] [rbp+18h]

  if ( screen && screen->mRenderable->m_movie.pObject )
  {
    if ( this->mDisablePerk
      || !UFG::UIHK_PDAPhoneContactsWidget::gPerkGiverUnlocked
      || this->mPerkGiverSymbol.mUID != this->mSymbolList.p[this->mSelectedIndex].mUID )
    {
      v4 = &this->mSymbolList.p[this->mSelectedIndex];
      if ( this->mTraceSymbol.mUID == v4->mUID )
      {
        UFG::UIHK_PDAPhoneContactsWidget::Exit(this, screen, 0);
        if ( UFG::UIHKScreenPhoneTraceMinigame::gPhoneTraceEnabled )
        {
          v5 = UFG::UIScreenTextureManager::Instance();
          UFG::UIScreenTextureManager::QueueLoadAndPush(v5, "PhoneTraceMinigame", 0i64);
        }
        else
        {
          UFG::UIScreenDialogBox::createOKDialog(0i64, &customWorldMapCaption, "$MINIGAME_PHONETRACE_WEAK_SIGNAL", 1);
        }
      }
      else
      {
        v7 = &contact;
        LODWORD(contact) = (UFG::qSymbol)v4->mUID;
        UFG::UIHK_PDAPhoneContactsWidget::LaunchCallMission(
          this,
          (__int64)&contact,
          &this->mNameList.p[this->mSelectedIndex],
          &this->mPortraitList.p[this->mSelectedIndex]);
      }
    }
    else
    {
      v2 = ((__int64 (*)(void))SkookumScript::c_world_class_p->vfptr->get_metaclass)();
      v3 = (*(__int64 (__fastcall **)(__int64, UFG::qStaticSymbol *))(*(_QWORD *)(v2 + 8) + 32i64))(
             v2 + 8,
             &qSymbol_c_perk_system);
      if ( v3 )
      {
        contact = 0i64;
        (*(void (__fastcall **)(__int64, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD, signed __int64))(*(_QWORD *)v3 + 104i64))(
          v3,
          &qSymbol_use_perk,
          &contact,
          0i64,
          0i64,
          0i64,
          -2i64);
      }
      if ( UFG::UIHKScreenHud::mInstance )
        UFG::UIHKScreenHud::mInstance->Buffs.mPerkActivate = 1;
    }
  }
}

// File Line: 471
// RVA: 0x5F0610
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::LaunchCallMission(UFG::UIHK_PDAPhoneContactsWidget *this, __int64 contact, UFG::qString *name, UFG::qString *portrait)
{
  UFG::qString *v4; // rbp
  UFG::qString *v5; // r14
  _DWORD *v6; // rsi
  UFG::UIHK_PDAPhoneContactsWidget *v7; // r15
  UFG::ProgressionTracker *v8; // rax
  UFG::PDATriggerTracker *v9; // rdi
  TargetIsSubTargetValid *v10; // rbx
  UFG::GameSlice *v11; // rcx
  UFG::UIHK_PDAWidget *v12; // rbx
  const char *v13; // rsi
  const char *v14; // rdi
  UFG::qSymbol result; // [rsp+20h] [rbp-28h]

  v4 = portrait;
  v5 = name;
  v6 = (_DWORD *)contact;
  v7 = this;
  v8 = UFG::ProgressionTracker::Instance();
  v9 = &v8->mPDATriggerTracker;
  if ( v8 != (UFG::ProgressionTracker *)-704i64 )
  {
    v10 = (TargetIsSubTargetValid *)UFG::PDATriggerTracker::GetFirst(&v8->mPDATriggerTracker);
    if ( v10 )
    {
      while ( 1 )
      {
        TargetIsSubTargetValid::GetSubTargetName(v10, &result);
        if ( *v6 == result.mUID )
          break;
        v10 = (TargetIsSubTargetValid *)UFG::PDATriggerTracker::GetNext(v9, (UFG::PDATrigger *)v10);
        if ( !v10 )
          return;
      }
      UFG::PDATrigger::UseTrigger((UFG::PDATrigger *)v10);
      v11 = (UFG::GameSlice *)v10[1].vfptr;
      if ( v11 )
        UFG::ProgressionTriggerComponent::OnActivate(v11);
      if ( UFG::UIHKScreenHud::mInstance )
      {
        v12 = UFG::UIHKScreenHud::mInstance->PDA;
        v13 = v5->mData;
        v14 = v4->mData;
        UFG::qString::Set(&v12->mPhoneContact, v5->mData);
        UFG::qString::Set(&UFG::UIHK_PDAWidget::mContactImage, v14);
        v12->mOutgoingCall = 1;
        v12->mVoiceMail = 0;
        UFG::UIHK_PDAIncomingCallWidget::SetCallerName(&v12->IncomingCall, v13, v14, 0);
        UFG::UIHK_PDAWidget::AnswerPhoneCall(UFG::UIHKScreenHud::mInstance->PDA);
        v7->mState = STATE_INCOMING_TEXT;
      }
    }
  }
}

// File Line: 505
// RVA: 0x604270
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::ScrollPrev(UFG::UIHK_PDAPhoneContactsWidget *this)
{
  UFG::allocator::free_link *v1; // rax
  UFG::UIScreenInvoke *v2; // rbx
  UFG::allocator::free_link *v3; // rax

  v1 = UFG::qMemoryPool::Allocate(
         &gScaleformMemoryPool,
         0x40ui64,
         "UIHK_PDAPhoneContactsWidget UIScreenInvoke",
         0i64,
         1u);
  v2 = (UFG::UIScreenInvoke *)v1;
  if ( v1 )
  {
    v3 = v1 + 1;
    v3->mNext = v3;
    v3[1].mNext = v3;
    v2->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable';
    UFG::qString::qString(&v2->command, &customWorldMapCaption);
  }
  else
  {
    v2 = 0i64;
  }
  if ( v2 )
  {
    UFG::qString::Set(&v2->command, "ContactList_Prev");
    if ( v2->command.mLength )
      UFG::UIScreenInvokeQueue::Add(&UFG::UIHK_PDAWidget::mScreenInvokeQueue, v2);
  }
}

// File Line: 515
// RVA: 0x603F20
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::ScrollNext(UFG::UIHK_PDAPhoneContactsWidget *this)
{
  UFG::allocator::free_link *v1; // rax
  UFG::UIScreenInvoke *v2; // rbx
  UFG::allocator::free_link *v3; // rax

  v1 = UFG::qMemoryPool::Allocate(
         &gScaleformMemoryPool,
         0x40ui64,
         "UIHK_PDAPhoneContactsWidget UIScreenInvoke",
         0i64,
         1u);
  v2 = (UFG::UIScreenInvoke *)v1;
  if ( v1 )
  {
    v3 = v1 + 1;
    v3->mNext = v3;
    v3[1].mNext = v3;
    v2->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable';
    UFG::qString::qString(&v2->command, &customWorldMapCaption);
  }
  else
  {
    v2 = 0i64;
  }
  if ( v2 )
  {
    UFG::qString::Set(&v2->command, "ContactList_Next");
    if ( v2->command.mLength )
      UFG::UIScreenInvokeQueue::Add(&UFG::UIHK_PDAWidget::mScreenInvokeQueue, v2);
  }
}

// File Line: 531
// RVA: 0x5D7D50
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::Exit(UFG::UIHK_PDAPhoneContactsWidget *this, UFG::UIScreen *screen, bool playSound)
{
  bool v3; // si
  Scaleform::GFx::Movie *v4; // rbx
  UFG::UIHK_PDAPhoneContactsWidget *v5; // rdi
  UFG::qString *v6; // rcx
  unsigned int *v7; // rbx
  UFG::qSymbol *v8; // rcx
  UFG::qSymbol *v9; // rbx
  UFG::qString *v10; // rcx
  unsigned int *v11; // rbx
  UFG::qString *v12; // rcx
  unsigned int *v13; // rbx
  unsigned int v14; // edx
  UFG::UIScreenTextureManager *v15; // rax

  if ( screen )
  {
    v3 = playSound;
    v4 = screen->mRenderable->m_movie.pObject;
    v5 = this;
    if ( v4 )
    {
      this->mState = 0;
      Scaleform::GFx::Movie::Invoke(v4, "ContactList_Collapse", 0i64, 0i64, 0);
      Scaleform::GFx::Movie::Invoke(v4, "ContactList_Hide", 0i64, 0i64, 0);
      v5->mNumContacts = 0;
      UFG::qArray<UFG::UIHK_PDAPhoneContactsWidget::UIHKTxtMsgInfo,0>::Clear(&v5->mMessages);
      v6 = v5->mMissionList.p;
      if ( v6 )
      {
        v7 = &v6[-1].mStringHash32;
        `eh vector destructor iterator'(
          v6,
          0x28ui64,
          v6[-1].mStringHash32,
          (void (__fastcall *)(void *))UFG::qString::~qString);
        operator delete[](v7);
      }
      v5->mMissionList.p = 0i64;
      *(_QWORD *)&v5->mMissionList.size = 0i64;
      v8 = v5->mSymbolList.p;
      if ( v8 )
      {
        v9 = v8 - 1;
        `eh vector destructor iterator'(v8, 4ui64, v8[-1].mUID, (void (__fastcall *)(void *))_);
        operator delete[](v9);
      }
      v5->mSymbolList.p = 0i64;
      *(_QWORD *)&v5->mSymbolList.size = 0i64;
      v10 = v5->mNameList.p;
      if ( v10 )
      {
        v11 = &v10[-1].mStringHash32;
        `eh vector destructor iterator'(
          v10,
          0x28ui64,
          v10[-1].mStringHash32,
          (void (__fastcall *)(void *))UFG::qString::~qString);
        operator delete[](v11);
      }
      v5->mNameList.p = 0i64;
      *(_QWORD *)&v5->mNameList.size = 0i64;
      v12 = v5->mPortraitList.p;
      if ( v12 )
      {
        v13 = &v12[-1].mStringHash32;
        `eh vector destructor iterator'(
          v12,
          0x28ui64,
          v12[-1].mStringHash32,
          (void (__fastcall *)(void *))UFG::qString::~qString);
        operator delete[](v13);
      }
      v5->mPortraitList.p = 0i64;
      *(_QWORD *)&v5->mPortraitList.size = 0i64;
      if ( v3 )
      {
        if ( UFG::HudAudio::m_instance )
        {
          v14 = 1740120221;
LABEL_16:
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            v14,
            0i64,
            0,
            0i64);
          goto LABEL_17;
        }
      }
      else if ( UFG::HudAudio::m_instance )
      {
        v14 = 1252810347;
        goto LABEL_16;
      }
LABEL_17:
      v15 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::ReleaseTexturePack(v15, UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename);
      return;
    }
  }
}

// File Line: 563
// RVA: 0x5D1AA0
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::AddContact(UFG::UIHK_PDAPhoneContactsWidget *this, UFG::UIScreen *screen, __int64 sym, const char *name, const char *portrait)
{
  const char *v5; // rsi
  UFG::UIHK_PDAPhoneContactsWidget *v6; // rbx
  Scaleform::GFx::Movie *v7; // rdi
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v11; // [rsp+40h] [rbp-A8h]
  unsigned int v12; // [rsp+48h] [rbp-A0h]
  const char *v13; // [rsp+50h] [rbp-98h]
  char v14; // [rsp+60h] [rbp-88h]
  char *v15; // [rsp+68h] [rbp-80h]
  __int64 v16; // [rsp+70h] [rbp-78h]
  unsigned int v17; // [rsp+78h] [rbp-70h]
  __int64 v18; // [rsp+88h] [rbp-60h]
  unsigned int v19; // [rsp+90h] [rbp-58h]
  __int64 v20; // [rsp+98h] [rbp-50h]
  __int64 v21; // [rsp+A8h] [rbp-40h]
  UFG::qString v22; // [rsp+B0h] [rbp-38h]
  char string; // [rsp+D8h] [rbp-10h]
  char *format; // [rsp+158h] [rbp+70h]
  __int64 v25; // [rsp+160h] [rbp+78h]

  if ( screen )
  {
    v21 = -2i64;
    v5 = name;
    v6 = this;
    v7 = screen->mRenderable->m_movie.pObject;
    if ( v7 )
    {
      UFG::qArray<UFG::qSymbol,0>::Add(&this->mSymbolList, (UFG::qSymbol *)sym, "qArray.Add");
      UFG::qString::qString(&v22, v5);
      UFG::qArray<UFG::qString,0>::Add(&v6->mNameList, v8, "qArray.Add");
      UFG::qString::~qString(&v22);
      UFG::qString::qString(&v22, format);
      UFG::qArray<UFG::qString,0>::Add(&v6->mPortraitList, v9, "qArray.Add");
      UFG::qString::~qString(&v22);
      sprintf(&string, "%s%s", v5, "_img32");
      `eh vector constructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (v12 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
        v11 = 0i64;
      }
      v12 = 6;
      v13 = v5;
      if ( (v17 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v16 + 16i64))(v16, &v14, v15);
        v16 = 0i64;
      }
      v17 = 6;
      v15 = format;
      if ( (v19 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v18 + 16i64))(v18, &v17, v20);
        v18 = 0i64;
      }
      v19 = 6;
      v20 = v25;
      Scaleform::GFx::Movie::Invoke(v7, "ContactList_AddContact", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
      ++v6->mNumContacts;
      `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 597
// RVA: 0x5F97E0
__int64 __fastcall UFG::UIHK_PDAPhoneContactsWidget::PopulateList(UFG::UIHK_PDAPhoneContactsWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // r14
  UFG::UIHK_PDAPhoneContactsWidget *v3; // rbx
  unsigned int v4; // esi
  UFG::qSymbol *v5; // rax
  UFG::GameStatTracker *v6; // rax
  UFG::PersistentData::ID *v7; // rax
  unsigned int v8; // ecx
  UFG::ProgressionTracker *v9; // rax
  UFG::PDATriggerTracker *v10; // rbp
  UFG::PDATrigger *i; // rdi
  UFG::qSymbol result; // [rsp+60h] [rbp+8h]
  UFG::qSymbol *v14; // [rsp+70h] [rbp+18h]
  UFG::qSymbol *v15; // [rsp+78h] [rbp+20h]

  v2 = screen;
  v3 = this;
  v4 = 0;
  this->mNumContacts = 0;
  v5 = UFG::qSymbol::create_from_string(&result, "default-unlockables-contactList-list");
  v3->mContactData = UFG::PropertySetManager::GetPropertySet(v5);
  v3->mDisablePerk = 0;
  if ( UFG::UIHK_PDAPhoneContactsWidget::gPerkGiverUnlocked )
  {
    v14 = &result;
    result.mUID = v3->mPerkGiverSymbol.mUID;
    UFG::UIHK_PDAPhoneContactsWidget::FindAndAddContact(v3, v2, (__int64)&result);
    v4 = 1;
  }
  v6 = UFG::GameStatTracker::Instance();
  v7 = UFG::GameStatTracker::GetStat(v6, TraceContact);
  v8 = v7->mValue.mUID;
  v3->mTraceSymbol.mUID = v7->mValue.mUID;
  if ( v8 != -1 )
  {
    v14 = &result;
    result.mUID = v8;
    UFG::UIHK_PDAPhoneContactsWidget::FindAndAddContact(v3, v2, (__int64)&result);
    ++v4;
  }
  v9 = UFG::ProgressionTracker::Instance();
  v10 = &v9->mPDATriggerTracker;
  if ( v9 != (UFG::ProgressionTracker *)-704i64 )
  {
    for ( i = (UFG::PDATrigger *)UFG::PDATriggerTracker::GetFirst(&v9->mPDATriggerTracker);
          i;
          i = (UFG::PDATrigger *)UFG::PDATriggerTracker::GetNext(v10, i) )
    {
      TargetIsSubTargetValid::GetSubTargetName((TargetIsSubTargetValid *)i, (UFG::qSymbol *)&v14);
      if ( (_DWORD)v14 == v3->mPerkGiverSymbol.mUID && UFG::UIHK_PDAPhoneContactsWidget::gPerkGiverUnlocked )
      {
        v3->mDisablePerk = 1;
      }
      else if ( (_DWORD)v14 != v3->mTraceSymbol.mUID )
      {
        v15 = &result;
        result.mUID = (unsigned int)v14;
        UFG::UIHK_PDAPhoneContactsWidget::FindAndAddContact(v3, v2, (__int64)&result);
        ++v4;
      }
    }
  }
  return v4;
}

// File Line: 650
// RVA: 0x5D8560
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::FindAndAddContact(UFG::UIHK_PDAPhoneContactsWidget *this, UFG::UIScreen *screen, __int64 contactID)
{
  unsigned int *v3; // r14
  UFG::UIScreen *v4; // r12
  UFG::UIHK_PDAPhoneContactsWidget *v5; // r15
  UFG::qPropertyList *v6; // rax
  UFG::qPropertyList *v7; // rbp
  unsigned int v8; // esi
  unsigned int v9; // edi
  char *v10; // rax
  UFG::qPropertySet *v11; // rbx
  char *portrait; // rdi
  char *v13; // r9
  UFG::qSymbol sym; // [rsp+70h] [rbp+8h]
  UFG::qSymbol *v15; // [rsp+88h] [rbp+20h]

  v3 = (unsigned int *)contactID;
  v4 = screen;
  v5 = this;
  v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         this->mContactData,
         (UFG::qSymbol *)&qSymbol_List_20.mUID,
         DEPTH_RECURSE);
  v7 = v6;
  if ( v6 && (v8 = v6->mNumElements, v9 = 0, v8) )
  {
    while ( 1 )
    {
      v10 = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, v9);
      if ( v10 && *(_QWORD *)v10 )
        v11 = (UFG::qPropertySet *)&v10[*(_QWORD *)v10];
      else
        v11 = 0i64;
      if ( v11->mName.mUID == *v3 )
        break;
      if ( ++v9 >= v8 )
        goto LABEL_11;
    }
    v15 = &sym;
    sym.mUID = *v3;
    PropertyUtils::Get<char const *>(v11, (UFG::qSymbol *)&qSymbol_Info_20.mUID, DEPTH_RECURSE);
    portrait = PropertyUtils::Get<char const *>(v11, (UFG::qSymbol *)&qSymbol_Portrait_20.mUID, DEPTH_RECURSE);
    v13 = PropertyUtils::Get<char const *>(v11, (UFG::qSymbol *)&qSymbol_Name_20.mUID, DEPTH_RECURSE);
    UFG::UIHK_PDAPhoneContactsWidget::AddContact(v5, v4, (__int64)&sym, v13, portrait);
  }
  else
  {
LABEL_11:
    v15 = &sym;
    sym.mUID = SimSym_INVALID.mUID;
    UFG::UIHK_PDAPhoneContactsWidget::AddContact(v5, v4, (__int64)&sym, "Err2", "Portrait_Smartphone_Unknown");
  }
}

// File Line: 796
// RVA: 0x61A3A0
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::UpdateContactMethod(UFG::UIHK_PDAPhoneContactsWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rdi
  UFG::UIHK_PDAPhoneContactsWidget *v3; // rbx
  Scaleform::GFx::Movie *v4; // rsi
  unsigned int v5; // edx
  unsigned int v6; // eax
  const char *v7; // rax
  unsigned int v8; // eax
  char ptr; // [rsp+38h] [rbp-38h]
  __int64 v10; // [rsp+48h] [rbp-28h]
  unsigned int v11; // [rsp+50h] [rbp-20h]
  const char *v12; // [rsp+58h] [rbp-18h]

  v2 = screen;
  v3 = this;
  if ( this->mState == 3 )
  {
    if ( screen )
    {
      v4 = screen->mRenderable->m_movie.pObject;
      if ( v4 )
      {
        `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        UFG::UIHK_PDAPhoneContactsWidget::GetSectedIndex(v3, v2);
        v5 = v3->mTraceSymbol.mUID;
        if ( v5 == -1 || (v6 = v3->mSelectedIndex, v3->mSymbolList.size <= v6) || v5 != v3->mSymbolList.p[v6].mUID )
        {
          if ( v3->mDisablePerk
            || !UFG::UIHK_PDAPhoneContactsWidget::gPerkGiverUnlocked
            || (v8 = v3->mSelectedIndex, v3->mSymbolList.size <= v8)
            || v3->mPerkGiverSymbol.mUID != v3->mSymbolList.p[v8].mUID )
          {
            if ( (v11 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v10 + 16i64))(v10, &ptr, v12);
              v10 = 0i64;
            }
            v7 = "$PDA_CONTACT_LIST_CALL";
          }
          else
          {
            if ( (v11 >> 6) & 1 )
            {
              (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v10 + 16i64))(v10, &ptr, v12);
              v10 = 0i64;
            }
            v7 = "$PDA_CONTACT_PERK";
          }
        }
        else
        {
          if ( (v11 >> 6) & 1 )
          {
            (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v10 + 16i64))(v10, &ptr, v12);
            v10 = 0i64;
          }
          v7 = "$PDA_CONTACT_TRACE";
        }
        v11 = 6;
        v12 = v7;
        Scaleform::GFx::Movie::Invoke(v4, "Smartphone_SetHelpbar", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
        `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
    }
  }
}

// File Line: 864
// RVA: 0x5E69C0
const char *__fastcall UFG::UIHK_PDAPhoneContactsWidget::GetActivePerk(UFG::UIHK_PDAPhoneContactsWidget *this)
{
  __int64 v1; // rax
  _QWORD *v2; // rax
  _QWORD *v3; // rbx
  __int64 v4; // r10
  __int64 v6; // [rsp+48h] [rbp+10h]

  v1 = ((__int64 (*)(void))SkookumScript::c_world_class_p->vfptr->get_metaclass)();
  v2 = (_QWORD *)(*(__int64 (__fastcall **)(__int64, UFG::qStaticSymbol *))(*(_QWORD *)(v1 + 8) + 32i64))(
                   v1 + 8,
                   &qSymbol_c_perk_system);
  v3 = v2;
  if ( !v2 )
    return "CopPerks_None";
  v4 = *v2;
  v6 = 0i64;
  (*(void (__fastcall **)(_QWORD *, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD))(v4 + 104))(
    v2,
    &qSymbol_get_perk_action,
    &v6,
    0i64,
    0i64,
    0i64);
  return **(const char ***)((*(__int64 (__fastcall **)(_QWORD *, UFG::qStaticSymbol *))(*v3 + 32i64))(
                              v3,
                              &qSymbol_i_current_perk)
                          + 32);
}

// File Line: 881
// RVA: 0x609E20
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::SetSubMenuIcon(UFG::UIHK_PDAPhoneContactsWidget *this, UFG::UIScreen *screen, unsigned int slotIndex, const char *iconName)
{
  const char *v4; // rsi
  signed int v5; // edi
  Scaleform::GFx::Movie *v6; // rbx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h]
  char v8; // [rsp+70h] [rbp-38h]
  __int64 v9; // [rsp+80h] [rbp-28h]
  unsigned int v10; // [rsp+88h] [rbp-20h]
  const char *v11; // [rsp+90h] [rbp-18h]

  if ( screen )
  {
    v4 = iconName;
    v5 = slotIndex;
    v6 = screen->mRenderable->m_movie.pObject;
    if ( v6 )
    {
      `eh vector constructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = 5;
      pargs.mValue.NValue = (double)v5;
      if ( (v10 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v9 + 16i64))(v9, &v8, v11);
        v9 = 0i64;
      }
      v10 = 6;
      v11 = v4;
      Scaleform::GFx::Movie::Invoke(v6, "AccordionContactList.SetSubMenuIcon", 0i64, &pargs, 2u);
      `eh vector destructor iterator'(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 899
// RVA: 0x5F1640
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::LoadTexturePack(UFG::UIHK_PDAPhoneContactsWidget *this)
{
  UFG::UIHK_PDAPhoneContactsWidget *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIScreenTextureManager *v4; // rax

  v1 = this;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v2, UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename);
  if ( UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename )
  {
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v4,
      UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename,
      DEFAULT_PRIORITY,
      UFG::UIHK_PDAPhoneContactsWidget::TextureLoadedCallback,
      0i64);
  }
  else if ( v1->mState )
  {
    v1->mState = 2;
    v1->mSelectedIndex = 0;
    v1->mUpdateContactMethod = 1;
  }
  else
  {
    v3 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v3, 0i64);
  }
}

// File Line: 911
// RVA: 0x6129B0
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::TextureLoadedCallback(UFG::DataStreamer::Handle *handle, void *param)
{
  UFG::UIHK_PDAWidget *v2; // rax
  UFG::UIScreenTextureManager *v3; // rax

  v2 = (UFG::UIHK_PDAWidget *)UFG::UIHKScreenHud::mInstance;
  if ( !UFG::UIHKScreenHud::mInstance || !UFG::UIHKScreenHud::mInstance->PDA )
    goto LABEL_10;
  if ( UFG::UIHKScreenHud::mInstance )
    v2 = UFG::UIHKScreenHud::mInstance->PDA;
  if ( v2->PhoneContacts.mState )
  {
    v2->PhoneContacts.mState = 2;
    v2->PhoneContacts.mSelectedIndex = 0;
    v2->PhoneContacts.mUpdateContactMethod = 1;
  }
  else
  {
LABEL_10:
    v3 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v3, UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename);
  }
}

