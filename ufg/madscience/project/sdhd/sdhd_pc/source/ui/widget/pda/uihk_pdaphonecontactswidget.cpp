// File Line: 54
// RVA: 0x1567E10
__int64 UFG::_dynamic_initializer_for__TxtMsgSymbol_List__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("List", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&TxtMsgSymbol_List, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__TxtMsgSymbol_List__);
}

// File Line: 55
// RVA: 0x1567E90
__int64 UFG::_dynamic_initializer_for__TxtMsgSymbol_MsgMarker__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MsgMarker", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&TxtMsgSymbol_MsgMarker, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__TxtMsgSymbol_MsgMarker__);
}

// File Line: 56
// RVA: 0x1567E50
__int64 UFG::_dynamic_initializer_for__TxtMsgSymbol_Msg__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Message", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&TxtMsgSymbol_Msg, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__TxtMsgSymbol_Msg__);
}

// File Line: 57
// RVA: 0x1567F10
__int64 UFG::_dynamic_initializer_for__TxtMsgSymbol_Sender__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Sender", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&TxtMsgSymbol_Sender, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__TxtMsgSymbol_Sender__);
}

// File Line: 58
// RVA: 0x1567ED0
__int64 UFG::_dynamic_initializer_for__TxtMsgSymbol_Param1__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("Param1", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&TxtMsgSymbol_Param1, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__TxtMsgSymbol_Param1__);
}

// File Line: 77
// RVA: 0x5C8520
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::UIHK_PDAPhoneContactsWidget(UFG::UIHK_PDAPhoneContactsWidget *this)
{
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (UFG::UIHK_PDAPhoneContactsWidgetVtbl *)&UFG::UIHK_PDAPhoneContactsWidget::`vftable;
  *(_QWORD *)&this->mState = 0i64;
  *(_QWORD *)&this->mSelectedIndex = 0i64;
  UFG::qString::qString(&this->mSelectedName);
  UFG::qString::qString(&this->mSelectedSubOption);
  this->mMissionList.p = 0i64;
  *(_QWORD *)&this->mMissionList.size = 0i64;
  this->mMessages.p = 0i64;
  *(_QWORD *)&this->mMessages.size = 0i64;
  this->mData = 0i64;
  UFG::qString::qString(&this->mTraceName, &customCaption);
  this->mTraceSymbol.mUID = -1;
  UFG::qString::qString(&this->mPerkGiverName, "$AMBIENT_PERKCONTACT_CONTACT_001");
  this->mPerkGiverSymbol.mUID = -1;
  *(_WORD *)&this->mShowingPerkIcon = 0;
  this->mUpdateContactMethod = 0;
  this->mSelectedSymbol.mUID = -1;
  this->mSymbolList.p = 0i64;
  *(_QWORD *)&this->mSymbolList.size = 0i64;
  this->mNameList.p = 0i64;
  *(_QWORD *)&this->mNameList.size = 0i64;
  this->mPortraitList.p = 0i64;
  *(_QWORD *)&this->mPortraitList.size = 0i64;
  this->mPerkGiverSymbol = (UFG::qSymbol)UFG::qSymbol::create_from_string(&result, "PDAContact_JANE_TENG")->mUID;
}

// File Line: 91
// RVA: 0x5CDC80
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::~UIHK_PDAPhoneContactsWidget(UFG::UIHK_PDAPhoneContactsWidget *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::qString *p; // rcx
  unsigned int *p_mStringHash32; // rbx
  UFG::qString *v5; // rcx
  unsigned int *v6; // rbx
  UFG::qSymbol *v7; // rcx
  UFG::qSymbol *v8; // rbx
  UFG::UIHK_PDAPhoneContactsWidget::UIHKTxtMsgInfo *v9; // rcx
  UFG::qSymbol *p_symbol; // rbx
  UFG::qString *v11; // rcx
  unsigned int *v12; // rbx

  this->vfptr = (UFG::UIHK_PDAPhoneContactsWidgetVtbl *)&UFG::UIHK_PDAPhoneContactsWidget::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v2, UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename);
  p = this->mPortraitList.p;
  if ( p )
  {
    p_mStringHash32 = &p[-1].mStringHash32;
    `eh vector destructor iterator(
      p,
      0x28ui64,
      p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  this->mPortraitList.p = 0i64;
  *(_QWORD *)&this->mPortraitList.size = 0i64;
  v5 = this->mNameList.p;
  if ( v5 )
  {
    v6 = &v5[-1].mStringHash32;
    `eh vector destructor iterator(
      v5,
      0x28ui64,
      v5[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v6);
  }
  this->mNameList.p = 0i64;
  *(_QWORD *)&this->mNameList.size = 0i64;
  v7 = this->mSymbolList.p;
  if ( v7 )
  {
    v8 = v7 - 1;
    `eh vector destructor iterator(v7, 4ui64, v7[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v8);
  }
  this->mSymbolList.p = 0i64;
  *(_QWORD *)&this->mSymbolList.size = 0i64;
  UFG::qString::~qString(&this->mPerkGiverName);
  UFG::qString::~qString(&this->mTraceName);
  v9 = this->mMessages.p;
  if ( v9 )
  {
    p_symbol = &v9[-1].symbol;
    `eh vector destructor iterator(
      v9,
      0x30ui64,
      v9[-1].symbol.mUID,
      (void (__fastcall *)(void *))UFG::PersistentData::String::~String);
    operator delete[](p_symbol);
  }
  this->mMessages.p = 0i64;
  *(_QWORD *)&this->mMessages.size = 0i64;
  v11 = this->mMissionList.p;
  if ( v11 )
  {
    v12 = &v11[-1].mStringHash32;
    `eh vector destructor iterator(
      v11,
      0x28ui64,
      v11[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v12);
  }
  this->mMissionList.p = 0i64;
  *(_QWORD *)&this->mMissionList.size = 0i64;
  UFG::qString::~qString(&this->mSelectedSubOption);
  UFG::qString::~qString(&this->mSelectedName);
}

// File Line: 99
// RVA: 0x6198E0
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::Update(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  UFG::UIHK_PDAPhoneContactsWidget::eState mState; // eax
  const char *ActivePerk; // rax

  mState = this->mState;
  if ( mState == STATE_PHONE_CONTACTS )
  {
    UFG::UIHK_PDAPhoneContactsWidget::Flash_Activate(this, screen);
  }
  else if ( mState == STATE_INCOMING_TEXT )
  {
    UFG::UIHK_PDAPhoneContactsWidget::Exit(this, screen, 0);
  }
  if ( this->mShowingPerkIcon )
  {
    ActivePerk = UFG::UIHK_PDAPhoneContactsWidget::GetActivePerk(this);
    UFG::UIHK_PDAPhoneContactsWidget::SetSubMenuIcon(this, screen, 0, ActivePerk);
  }
  if ( this->mUpdateContactMethod )
  {
    UFG::UIHK_PDAPhoneContactsWidget::UpdateContactMethod(this, screen);
    this->mUpdateContactMethod = 0;
  }
}

// File Line: 137
// RVA: 0x5FE760
char __fastcall UFG::UIHK_PDAPhoneContactsWidget::ProcessInput(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        UFG::UIScreen *screen,
        unsigned int msgId)
{
  UFG::UIHK_PDAPhoneContactsWidget::eState mState; // ecx
  __int32 v7; // ecx

  mState = this->mState;
  if ( mState <= (unsigned int)STATE_PHONE_CONTACTS || mState == STATE_INCOMING_TEXT )
    return 0;
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4F717979u, 0i64, 0, 0i64);
    UFG::UIHK_PDAPhoneContactsWidget::ScrollPrev(this);
    this->mUpdateContactMethod = 1;
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4F717979u, 0i64, 0, 0i64);
    UFG::UIHK_PDAPhoneContactsWidget::ScrollNext(this);
    this->mUpdateContactMethod = 1;
    return 1;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_RELEASED_30 )
  {
    if ( mState == STATE_OUTGOING_CALL )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4AAC5E6Bu, 0i64, 0, 0i64);
      this->mState = STATE_IDLE;
      return 1;
    }
    else
    {
      UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::m_ActionRequests.mBits[(__int64)(int)gActionRequest_PDAExit.m_EnumValue >> 6] |= 1i64 << (gActionRequest_PDAExit.m_EnumValue & 0x3F);
      UFG::UIHK_PDAPhoneContactsWidget::Exit(this, screen, 0);
      return 1;
    }
  }
  if ( msgId != UI_HASH_BUTTON_ACCEPT_RELEASED_30 )
    return 0;
  v7 = mState - 4;
  if ( !v7 )
    return 1;
  if ( v7 == 1 )
    return 0;
  UFG::UIHK_PDAPhoneContactsWidget::GetSelectedName(this, screen);
  UFG::UIHK_PDAPhoneContactsWidget::GetSectedIndex(this, screen);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x9E75334E, 0i64, 0, 0i64);
  UFG::UIHK_PDAPhoneContactsWidget::LaunchSubOption(this, screen);
  UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::m_ActionRequests.mBits[(__int64)(int)gActionRequest_PDATalk.m_EnumValue >> 6] |= 1i64 << (gActionRequest_PDATalk.m_EnumValue & 0x3F);
  return 1;
}

// File Line: 213
// RVA: 0x5EB380
char __fastcall UFG::UIHK_PDAPhoneContactsWidget::HandleMessage(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        UFG::UIScreen *screen,
        unsigned int msgId)
{
  if ( this->mState != STATE_INCOMING_CALL
    || msgId != UI_HASH_WIDGET_FADE_OUT_20 && msgId != UI_HASH_PAUSE_SCREEN_INIT_20 )
  {
    return 0;
  }
  UFG::UIHK_PDAPhoneContactsWidget::Exit(this, screen, 0);
  return 1;
}

// File Line: 277
// RVA: 0x5D9030
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::Flash_Activate(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rdi

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    Scaleform::GFx::Movie::Invoke(pObject, "ContactList_Init", 0i64, 0i64, 0);
    UFG::UIHK_PDAPhoneContactsWidget::PopulateList(this, screen);
    Scaleform::GFx::Movie::Invoke(pObject, "ContactList_Show", 0i64, 0i64, 0);
    if ( this->mNumContacts )
    {
      this->mState = STATE_TEXT_INBOX;
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x1F004A69u, 0i64, 0, 0i64);
    }
    else
    {
      this->mState = STATE_INCOMING_CALL;
      Scaleform::GFx::Movie::Invoke(pObject, "ContactList_PlayEmpty", 0i64, 0i64, 0);
    }
  }
}

// File Line: 319
// RVA: 0x5E90B0
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::GetSelectedName(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx
  const char *pString; // rdx
  Scaleform::GFx::Value v5; // [rsp+38h] [rbp-40h] BYREF

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      v5.pObjectInterface = 0i64;
      v5.Type = VT_Undefined;
      Scaleform::GFx::Movie::Invoke(pObject, "ContactList_GetSelectedName", &v5, 0i64, 0);
      if ( (v5.Type & 0x8F) != 0 )
      {
        if ( (v5.Type & 0x40) != 0 )
          pString = *v5.mValue.pStringManaged;
        else
          pString = v5.mValue.pString;
      }
      else
      {
        pString = &customCaption;
      }
      UFG::qString::Set(&this->mSelectedName, pString);
      if ( (v5.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v5.pObjectInterface->vfptr->gap8[8])(
          v5.pObjectInterface,
          &v5,
          v5.mValue);
    }
  }
}

// File Line: 345
// RVA: 0x5E8B40
signed __int64 __fastcall UFG::UIHK_PDAPhoneContactsWidget::GetSectedIndex(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx
  unsigned int mSelectedIndex; // ebx
  Scaleform::GFx::Value presult; // [rsp+38h] [rbp-40h] BYREF

  if ( !screen )
    return 0xFFFFFFFFi64;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( !pObject )
    return 0xFFFFFFFFi64;
  presult.pObjectInterface = 0i64;
  presult.Type = VT_Undefined;
  Scaleform::GFx::Movie::Invoke(pObject, "ContactList_GetSelectedIndex", &presult, 0i64, 0);
  if ( (presult.Type & 0x8F) != 0 )
    this->mSelectedIndex = (int)presult.mValue.NValue;
  else
    this->mSelectedIndex = 0;
  mSelectedIndex = this->mSelectedIndex;
  if ( (presult.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&presult.pObjectInterface->vfptr->gap8[8])(
      presult.pObjectInterface,
      &presult,
      presult.mValue);
    presult.pObjectInterface = 0i64;
  }
  return mSelectedIndex;
}

// File Line: 370
// RVA: 0x5F0740
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::LaunchSubOption(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        UFG::UIScreen *screen)
{
  SSMetaClass *v2; // rax
  __int64 v3; // rax
  UFG::qSymbol *v4; // r8
  UFG::UIScreenTextureManager *v5; // rax
  __int64 contact; // [rsp+58h] [rbp+10h] BYREF
  __int64 *p_contact; // [rsp+60h] [rbp+18h]

  if ( screen && screen->mRenderable->m_movie.pObject )
  {
    if ( !this->mDisablePerk
      && UFG::UIHK_PDAPhoneContactsWidget::gPerkGiverUnlocked
      && this->mPerkGiverSymbol.mUID == this->mSymbolList.p[this->mSelectedIndex].mUID )
    {
      v2 = SkookumScript::c_world_class_p->vfptr->get_metaclass(SkookumScript::c_world_class_p);
      v3 = (__int64)v2->SSInstanceUnreffed::SSInstance::SSObjectBase::vfptr->get_data_by_name(
                      &v2->SSInstanceUnreffed,
                      (ASymbol *)&qSymbol_c_perk_system);
      if ( v3 )
      {
        contact = 0i64;
        (*(void (__fastcall **)(__int64, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD, __int64))(*(_QWORD *)v3 + 104i64))(
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
    else
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
          UFG::UIScreenDialogBox::createOKDialog(0i64, &customCaption, "$MINIGAME_PHONETRACE_WEAK_SIGNAL", 1);
        }
      }
      else
      {
        p_contact = &contact;
        LODWORD(contact) = (UFG::qSymbol)v4->mUID;
        UFG::UIHK_PDAPhoneContactsWidget::LaunchCallMission(
          this,
          &contact,
          &this->mNameList.p[this->mSelectedIndex],
          &this->mPortraitList.p[this->mSelectedIndex]);
      }
    }
  }
}

// File Line: 471
// RVA: 0x5F0610
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::LaunchCallMission(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        _DWORD *contact,
        UFG::qString *name,
        UFG::qString *portrait)
{
  UFG::ProgressionTracker *v8; // rax
  UFG::PDATriggerTracker *p_mPDATriggerTracker; // rdi
  TargetIsSubTargetValid *First; // rbx
  UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *vfptr; // rcx
  UFG::UIHK_PDAWidget *PDA; // rbx
  char *mData; // rsi
  char *v14; // rdi
  UFG::qSymbol result; // [rsp+20h] [rbp-28h] BYREF

  v8 = UFG::ProgressionTracker::Instance();
  p_mPDATriggerTracker = &v8->mPDATriggerTracker;
  if ( v8 != (UFG::ProgressionTracker *)-704i64 )
  {
    First = (TargetIsSubTargetValid *)UFG::PDATriggerTracker::GetFirst(&v8->mPDATriggerTracker);
    if ( First )
    {
      while ( 1 )
      {
        TargetIsSubTargetValid::GetSubTargetName(First, &result);
        if ( *contact == result.mUID )
          break;
        First = (TargetIsSubTargetValid *)UFG::PDATriggerTracker::GetNext(
                                            p_mPDATriggerTracker,
                                            (UFG::PDATrigger *)First);
        if ( !First )
          return;
      }
      UFG::PDATrigger::UseTrigger((UFG::PDATrigger *)First);
      vfptr = (UFG::qNode<UFG::GameSliceStreamer::StreamRequest,UFG::GameSliceStreamer::StreamRequest> *)First[1].vfptr;
      if ( vfptr )
        UFG::ProgressionTriggerComponent::OnActivate(vfptr);
      if ( UFG::UIHKScreenHud::mInstance )
      {
        PDA = UFG::UIHKScreenHud::mInstance->PDA;
        mData = name->mData;
        v14 = portrait->mData;
        UFG::qString::Set(&PDA->mPhoneContact, mData);
        UFG::qString::Set(&UFG::UIHK_PDAWidget::mContactImage, v14);
        PDA->mOutgoingCall = 1;
        PDA->mVoiceMail = 0;
        UFG::UIHK_PDAIncomingCallWidget::SetCallerName(&PDA->IncomingCall, mData, v14, 0);
        UFG::UIHK_PDAWidget::AnswerPhoneCall(UFG::UIHKScreenHud::mInstance->PDA);
        this->mState = STATE_INCOMING_TEXT;
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
    v2->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable;
    UFG::qString::qString(&v2->command, &customCaption);
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
    v2->vfptr = (UFG::UIScreenInvokeVtbl *)&UFG::UIScreenInvoke::`vftable;
    UFG::qString::qString(&v2->command, &customCaption);
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
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::Exit(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        UFG::UIScreen *screen,
        bool playSound)
{
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::qString *p; // rcx
  unsigned int *p_mStringHash32; // rbx
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
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      this->mState = STATE_IDLE;
      Scaleform::GFx::Movie::Invoke(pObject, "ContactList_Collapse", 0i64, 0i64, 0);
      Scaleform::GFx::Movie::Invoke(pObject, "ContactList_Hide", 0i64, 0i64, 0);
      this->mNumContacts = 0;
      UFG::qArray<UFG::UIHK_PDAPhoneContactsWidget::UIHKTxtMsgInfo,0>::Clear(&this->mMessages);
      p = this->mMissionList.p;
      if ( p )
      {
        p_mStringHash32 = &p[-1].mStringHash32;
        `eh vector destructor iterator(
          p,
          0x28ui64,
          p[-1].mStringHash32,
          (void (__fastcall *)(void *))UFG::qString::~qString);
        operator delete[](p_mStringHash32);
      }
      this->mMissionList.p = 0i64;
      *(_QWORD *)&this->mMissionList.size = 0i64;
      v8 = this->mSymbolList.p;
      if ( v8 )
      {
        v9 = v8 - 1;
        `eh vector destructor iterator(v8, 4ui64, v8[-1].mUID, (void (__fastcall *)(void *))_);
        operator delete[](v9);
      }
      this->mSymbolList.p = 0i64;
      *(_QWORD *)&this->mSymbolList.size = 0i64;
      v10 = this->mNameList.p;
      if ( v10 )
      {
        v11 = &v10[-1].mStringHash32;
        `eh vector destructor iterator(
          v10,
          0x28ui64,
          v10[-1].mStringHash32,
          (void (__fastcall *)(void *))UFG::qString::~qString);
        operator delete[](v11);
      }
      this->mNameList.p = 0i64;
      *(_QWORD *)&this->mNameList.size = 0i64;
      v12 = this->mPortraitList.p;
      if ( v12 )
      {
        v13 = &v12[-1].mStringHash32;
        `eh vector destructor iterator(
          v12,
          0x28ui64,
          v12[-1].mStringHash32,
          (void (__fastcall *)(void *))UFG::qString::~qString);
        operator delete[](v13);
      }
      this->mPortraitList.p = 0i64;
      *(_QWORD *)&this->mPortraitList.size = 0i64;
      if ( playSound )
      {
        if ( UFG::HudAudio::m_instance )
        {
          v14 = 1740120221;
LABEL_16:
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v14, 0i64, 0, 0i64);
        }
      }
      else if ( UFG::HudAudio::m_instance )
      {
        v14 = 1252810347;
        goto LABEL_16;
      }
      v15 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::ReleaseTexturePack(v15, UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename);
    }
  }
}

// File Line: 563
// RVA: 0x5D1AA0
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::AddContact(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        UFG::UIScreen *screen,
        __int64 sym,
        const char *name,
        const char *portrait)
{
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  char v11[8]; // [rsp+60h] [rbp-88h] BYREF
  char *v12; // [rsp+68h] [rbp-80h]
  __int64 v13; // [rsp+70h] [rbp-78h]
  int v14[4]; // [rsp+78h] [rbp-70h] BYREF
  __int64 v15; // [rsp+88h] [rbp-60h]
  int v16; // [rsp+90h] [rbp-58h]
  __int64 v17; // [rsp+98h] [rbp-50h]
  __int64 v18; // [rsp+A8h] [rbp-40h]
  UFG::qString v19; // [rsp+B0h] [rbp-38h] BYREF
  char string[64]; // [rsp+D8h] [rbp-10h] BYREF
  char *format; // [rsp+158h] [rbp+70h]
  __int64 v22; // [rsp+160h] [rbp+78h]

  if ( screen )
  {
    v18 = -2i64;
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      UFG::qArray<UFG::qSymbol,0>::Add(&this->mSymbolList, (UFG::qSymbol *)sym, "qArray.Add");
      UFG::qString::qString(&v19, name);
      UFG::qArray<UFG::qString,0>::Add(&this->mNameList, v8, "qArray.Add");
      UFG::qString::~qString(&v19);
      UFG::qString::qString(&v19, format);
      UFG::qArray<UFG::qString,0>::Add(&this->mPortraitList, v9, "qArray.Add");
      UFG::qString::~qString(&v19);
      sprintf(string, "%s%s", name, "_img32");
      `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      ptr.mValue.pString = name;
      if ( (v14[0] & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v13 + 16i64))(v13, v11, v12);
        v13 = 0i64;
      }
      v14[0] = 6;
      v12 = format;
      if ( (v16 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v15 + 16i64))(v15, v14, v17);
        v15 = 0i64;
      }
      v16 = 6;
      v17 = v22;
      Scaleform::GFx::Movie::Invoke(pObject, "ContactList_AddContact", 0i64, &ptr, 3u);
      ++this->mNumContacts;
      `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 597
// RVA: 0x5F97E0
__int64 __fastcall UFG::UIHK_PDAPhoneContactsWidget::PopulateList(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        UFG::UIScreen *screen)
{
  unsigned int v4; // esi
  UFG::qSymbol *v5; // rax
  UFG::GameStatTracker *v6; // rax
  UFG::PersistentData::ID *Stat; // rax
  unsigned int mUID; // ecx
  UFG::ProgressionTracker *v9; // rax
  UFG::PDATriggerTracker *p_mPDATriggerTracker; // rbp
  UFG::PDATrigger *i; // rdi
  UFG::qSymbol result; // [rsp+60h] [rbp+8h] BYREF
  UFG::qSymbol *p_result; // [rsp+70h] [rbp+18h] BYREF
  UFG::qSymbol *v15; // [rsp+78h] [rbp+20h]

  v4 = 0;
  this->mNumContacts = 0;
  v5 = UFG::qSymbol::create_from_string(&result, "default-unlockables-contactList-list");
  this->mContactData = UFG::PropertySetManager::GetPropertySet(v5);
  this->mDisablePerk = 0;
  if ( UFG::UIHK_PDAPhoneContactsWidget::gPerkGiverUnlocked )
  {
    p_result = &result;
    result.mUID = this->mPerkGiverSymbol.mUID;
    UFG::UIHK_PDAPhoneContactsWidget::FindAndAddContact(this, screen, &result.mUID);
    v4 = 1;
  }
  v6 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v6, TraceContact);
  mUID = Stat->mValue.mUID;
  this->mTraceSymbol.mUID = Stat->mValue.mUID;
  if ( mUID != -1 )
  {
    p_result = &result;
    result.mUID = mUID;
    UFG::UIHK_PDAPhoneContactsWidget::FindAndAddContact(this, screen, &result.mUID);
    ++v4;
  }
  v9 = UFG::ProgressionTracker::Instance();
  p_mPDATriggerTracker = &v9->mPDATriggerTracker;
  if ( v9 != (UFG::ProgressionTracker *)-704i64 )
  {
    for ( i = (UFG::PDATrigger *)UFG::PDATriggerTracker::GetFirst(&v9->mPDATriggerTracker);
          i;
          i = (UFG::PDATrigger *)UFG::PDATriggerTracker::GetNext(p_mPDATriggerTracker, i) )
    {
      TargetIsSubTargetValid::GetSubTargetName((TargetIsSubTargetValid *)i, (UFG::qSymbol *)&p_result);
      if ( (_DWORD)p_result == this->mPerkGiverSymbol.mUID && UFG::UIHK_PDAPhoneContactsWidget::gPerkGiverUnlocked )
      {
        this->mDisablePerk = 1;
      }
      else if ( (_DWORD)p_result != this->mTraceSymbol.mUID )
      {
        v15 = &result;
        result.mUID = (unsigned int)p_result;
        UFG::UIHK_PDAPhoneContactsWidget::FindAndAddContact(this, screen, &result.mUID);
        ++v4;
      }
    }
  }
  return v4;
}

// File Line: 650
// RVA: 0x5D8560
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::FindAndAddContact(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        UFG::UIScreen *screen,
        unsigned int *contactID)
{
  UFG::qPropertyList *v6; // rax
  UFG::qPropertyList *v7; // rbp
  unsigned int mNumElements; // esi
  unsigned int v9; // edi
  char *ValuePtr; // rax
  UFG::qPropertySet *v11; // rbx
  char *portrait; // rdi
  char *v13; // r9
  UFG::qSymbol sym; // [rsp+70h] [rbp+8h] BYREF
  UFG::qSymbol *p_sym; // [rsp+88h] [rbp+20h]

  v6 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         this->mContactData,
         (UFG::qArray<unsigned long,0> *)&qSymbol_List_20,
         DEPTH_RECURSE);
  v7 = v6;
  if ( v6 && (mNumElements = v6->mNumElements, v9 = 0, mNumElements) )
  {
    while ( 1 )
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v7, 0x1Au, v9);
      if ( ValuePtr && *(_QWORD *)ValuePtr )
        v11 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
      else
        v11 = 0i64;
      if ( v11->mName.mUID == *contactID )
        break;
      if ( ++v9 >= mNumElements )
        goto LABEL_11;
    }
    p_sym = &sym;
    sym.mUID = *contactID;
    PropertyUtils::Get<char const *>(v11, (UFG::qArray<unsigned long,0> *)&qSymbol_Info_20, DEPTH_RECURSE);
    portrait = PropertyUtils::Get<char const *>(
                 v11,
                 (UFG::qArray<unsigned long,0> *)&qSymbol_Portrait_20,
                 DEPTH_RECURSE);
    v13 = PropertyUtils::Get<char const *>(v11, (UFG::qArray<unsigned long,0> *)&qSymbol_Name_20, DEPTH_RECURSE);
    UFG::UIHK_PDAPhoneContactsWidget::AddContact(this, screen, (__int64)&sym, v13, portrait);
  }
  else
  {
LABEL_11:
    p_sym = &sym;
    sym.mUID = SimSym_INVALID.mUID;
    UFG::UIHK_PDAPhoneContactsWidget::AddContact(this, screen, (__int64)&sym, "Err2", "Portrait_Smartphone_Unknown");
  }
}

// File Line: 796
// RVA: 0x61A3A0
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::UpdateContactMethod(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rsi
  unsigned int mUID; // edx
  unsigned int v6; // eax
  const char *v7; // rax
  unsigned int mSelectedIndex; // eax
  Scaleform::GFx::Value ptr; // [rsp+38h] [rbp-38h] BYREF

  if ( this->mState == STATE_TEXT_INBOX )
  {
    if ( screen )
    {
      pObject = screen->mRenderable->m_movie.pObject;
      if ( pObject )
      {
        `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
        UFG::UIHK_PDAPhoneContactsWidget::GetSectedIndex(this, screen);
        mUID = this->mTraceSymbol.mUID;
        if ( mUID == -1
          || (v6 = this->mSelectedIndex, this->mSymbolList.size <= v6)
          || mUID != this->mSymbolList.p[v6].mUID )
        {
          if ( !this->mDisablePerk
            && UFG::UIHK_PDAPhoneContactsWidget::gPerkGiverUnlocked
            && (mSelectedIndex = this->mSelectedIndex, this->mSymbolList.size > mSelectedIndex)
            && this->mPerkGiverSymbol.mUID == this->mSymbolList.p[mSelectedIndex].mUID )
          {
            if ( (ptr.Type & 0x40) != 0 )
            {
              (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
                ptr.pObjectInterface,
                &ptr,
                ptr.mValue);
              ptr.pObjectInterface = 0i64;
            }
            v7 = "$PDA_CONTACT_PERK";
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
            v7 = "$PDA_CONTACT_LIST_CALL";
          }
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
          v7 = "$PDA_CONTACT_TRACE";
        }
        ptr.Type = VT_String;
        ptr.mValue.pString = v7;
        Scaleform::GFx::Movie::Invoke(pObject, "Smartphone_SetHelpbar", 0i64, &ptr, 1u);
        `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      }
    }
  }
}

// File Line: 864
// RVA: 0x5E69C0
const char *__fastcall UFG::UIHK_PDAPhoneContactsWidget::GetActivePerk(UFG::UIHK_PDAPhoneContactsWidget *this)
{
  SSMetaClass *v1; // rax
  SSInstance *v2; // rax
  SSInstance *v3; // rbx
  SSObjectBaseVtbl *vfptr; // r10
  __int64 v6; // [rsp+48h] [rbp+10h] BYREF

  v1 = SkookumScript::c_world_class_p->vfptr->get_metaclass(SkookumScript::c_world_class_p);
  v2 = v1->SSInstanceUnreffed::SSInstance::SSObjectBase::vfptr->get_data_by_name(
         &v1->SSInstanceUnreffed,
         (ASymbol *)&qSymbol_c_perk_system);
  v3 = v2;
  if ( !v2 )
    return "CopPerks_None";
  vfptr = v2->vfptr;
  v6 = 0i64;
  ((void (__fastcall *)(SSInstance *, UFG::qStaticSymbol *, __int64 *, _QWORD, _QWORD, _QWORD))vfptr[1].set_data_by_name)(
    v2,
    &qSymbol_get_perk_action,
    &v6,
    0i64,
    0i64,
    0i64);
  return *(const char **)v3->vfptr->get_data_by_name(v3, (ASymbol *)&qSymbol_i_current_perk)->i_user_data;
}

// File Line: 881
// RVA: 0x609E20
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::SetSubMenuIcon(
        UFG::UIHK_PDAPhoneContactsWidget *this,
        UFG::UIScreen *screen,
        int slotIndex,
        const char *iconName)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+40h] [rbp-68h] BYREF
  char v8[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v9; // [rsp+80h] [rbp-28h]
  int v10; // [rsp+88h] [rbp-20h]
  const char *v11; // [rsp+90h] [rbp-18h]

  if ( screen )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      `eh vector constructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (pargs.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = VT_Number;
      pargs.mValue.NValue = (double)slotIndex;
      if ( (v10 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v9 + 16i64))(v9, v8, v11);
        v9 = 0i64;
      }
      v10 = 6;
      v11 = iconName;
      Scaleform::GFx::Movie::Invoke(pObject, "AccordionContactList.SetSubMenuIcon", 0i64, &pargs, 2u);
      `eh vector destructor iterator(&pargs, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
  }
}

// File Line: 899
// RVA: 0x5F1640
void __fastcall UFG::UIHK_PDAPhoneContactsWidget::LoadTexturePack(UFG::UIHK_PDAPhoneContactsWidget *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIScreenTextureManager *v3; // rax
  UFG::UIScreenTextureManager *v4; // rax

  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v2, UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename);
  if ( UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename )
  {
    v4 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueTexturePackLoad(
      v4,
      UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename,
      DEFAULT_PRIORITY,
      (UFG::qReflectInventoryBase *)UFG::UIHK_PDAPhoneContactsWidget::TextureLoadedCallback,
      0i64);
  }
  else if ( this->mState )
  {
    this->mState = STATE_PHONE_CONTACTS;
    this->mSelectedIndex = 0;
    this->mUpdateContactMethod = 1;
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
  UFG::UIHK_PDAWidget *PDA; // rax
  UFG::UIScreenTextureManager *v3; // rax

  PDA = (UFG::UIHK_PDAWidget *)UFG::UIHKScreenHud::mInstance;
  if ( !UFG::UIHKScreenHud::mInstance || !UFG::UIHKScreenHud::mInstance->PDA )
    goto LABEL_7;
  if ( UFG::UIHKScreenHud::mInstance )
    PDA = UFG::UIHKScreenHud::mInstance->PDA;
  if ( PDA->PhoneContacts.mState )
  {
    PDA->PhoneContacts.mState = STATE_PHONE_CONTACTS;
    PDA->PhoneContacts.mSelectedIndex = 0;
    PDA->PhoneContacts.mUpdateContactMethod = 1;
  }
  else
  {
LABEL_7:
    v3 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::ReleaseTexturePack(v3, UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename);
  }
}

