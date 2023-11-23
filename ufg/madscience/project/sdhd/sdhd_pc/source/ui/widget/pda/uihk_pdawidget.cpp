// File Line: 67
// RVA: 0x1567440
__int64 dynamic_initializer_for__UFG::UIHK_PDAWidget::mScreenInvokeQueue__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHK_PDAWidget::mScreenInvokeQueue__);
}

// File Line: 68
// RVA: 0x1566B90
__int64 dynamic_initializer_for__UFG::UIHK_PDAWidget::ObjectiveManager__()
{
  UFG::UIHKPlayerObjectiveManager::UIHKPlayerObjectiveManager(&UFG::UIHK_PDAWidget::ObjectiveManager);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHK_PDAWidget::ObjectiveManager__);
}

// File Line: 79
// RVA: 0x15674C0
__int64 dynamic_initializer_for__UFG::UIHK_PDAWidget::mTxtContact__()
{
  UFG::qString::qString(&UFG::UIHK_PDAWidget::mTxtContact, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHK_PDAWidget::mTxtContact__);
}

// File Line: 80
// RVA: 0x15674F0
__int64 dynamic_initializer_for__UFG::UIHK_PDAWidget::mTxtMsg__()
{
  UFG::qString::qString(&UFG::UIHK_PDAWidget::mTxtMsg, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHK_PDAWidget::mTxtMsg__);
}

// File Line: 81
// RVA: 0x1566F20
__int64 dynamic_initializer_for__UFG::UIHK_PDAWidget::mContactImage__()
{
  UFG::qString::qString(&UFG::UIHK_PDAWidget::mContactImage, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHK_PDAWidget::mContactImage__);
}

// File Line: 82
// RVA: 0x1566EF0
__int64 dynamic_initializer_for__UFG::UIHK_PDAWidget::mContactID__()
{
  UFG::qString::qString(&UFG::UIHK_PDAWidget::mContactID, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::UIHK_PDAWidget::mContactID__);
}

// File Line: 112
// RVA: 0x5C8670
void __fastcall UFG::UIHK_PDAWidget::UIHK_PDAWidget(UFG::UIHK_PDAWidget *this, UFG::UIHK_PDACache *cache)
{
  this->vfptr = (UFG::UIHK_PDAWidgetVtbl *)&UFG::UIHK_PDAWidget::`vftable;
  UFG::UIHK_PDAPhoneContactsWidget::UIHK_PDAPhoneContactsWidget(&this->PhoneContacts);
  this->mState = cache->state;
  this->mMovie = 0i64;
  *(_QWORD *)&this->RootMenu.mState = 0i64;
  this->RootMenu.mRefreshTimer = 0.0;
  this->RootMenu.mLastScrolledPrev = 0;
  *(_QWORD *)&this->RootMenu.mIntroIndex = 0i64;
  UFG::qString::qString(&this->RootMenu.mSelectedItem);
  UFG::qString::qString(&this->RootMenu.mInputLocker.mOwner, "UIHK_PDARootMenuWidget");
  this->RootMenu.mInputLocker.mAcquired = 0;
  this->TextInbox.mState = STATE_IDLE;
  UFG::UIHK_PDAIncomingCallWidget::UIHK_PDAIncomingCallWidget(&this->IncomingCall);
  this->IncomingText.mState = STATE_IDLE;
  *(_WORD *)&this->IncomingText.mMessageRead = 0;
  this->IncomingText.mIgnoreButtonOnce = 0;
  *(_QWORD *)&this->IncomingText.mDismissCause = 0i64;
  UFG::qString::qString(&this->IncomingText.mInputLocker.mOwner, "UIHK_PDAIncomingTextWidget");
  this->IncomingText.mInputLocker.mAcquired = 0;
  this->Clock.mClockTime = 0;
  this->m_objectiveScrollingInProgress = 0;
  *(_QWORD *)&this->m_objectiveScrollingTimer = 0i64;
  *(_QWORD *)&this->m_R3_timer = 0i64;
  this->mRightStickTimer = 0.0;
  *(_WORD *)&this->mLeftStickActive = 257;
  this->mGPSActivatedFlag = 0;
  this->mPDAOpenDelay = 0;
  this->mShouldHighlight = 0;
  this->mPreLocked = cache->plock;
  this->mRootIntro = cache->root;
  UFG::qString::qString(&this->mPhoneContact, &cache->caller);
  this->mOutgoingCall = cache->outgoing;
  this->mAutoAnsCall = cache->answered;
  this->mVoiceMail = cache->vmail;
  this->mTime = 0.0;
}

// File Line: 117
// RVA: 0x5CDEA0
void __fastcall UFG::UIHK_PDAWidget::~UIHK_PDAWidget(UFG::UIHK_PDAWidget *this)
{
  this->vfptr = (UFG::UIHK_PDAWidgetVtbl *)&UFG::UIHK_PDAWidget::`vftable;
  UFG::UIHK_PDAWidget::EndPhoneCall(this, 0);
  UFG::UIHK_PDAWidget::ForceIdle(this);
  UFG::qString::~qString(&this->mPhoneContact);
  UFG::UIHK_PDAIncomingTextWidget::~UIHK_PDAIncomingTextWidget(&this->IncomingText);
  UFG::UIHK_PDAIncomingCallWidget::~UIHK_PDAIncomingCallWidget(&this->IncomingCall);
  UFG::UIHK_PDARootMenuWidget::Deactivate(&this->RootMenu);
  UFG::qString::~qString(&this->RootMenu.mInputLocker.mOwner);
  UFG::qString::~qString(&this->RootMenu.mSelectedItem);
  UFG::UIHK_PDAPhoneContactsWidget::~UIHK_PDAPhoneContactsWidget(&this->PhoneContacts);
}

// File Line: 124
// RVA: 0x5E6920
UFG::UIHK_PDAWidget *__fastcall UFG::UIHK_PDAWidget::Get()
{
  UFG::UIHK_PDAWidget *result; // rax

  result = (UFG::UIHK_PDAWidget *)UFG::UIHKScreenHud::mInstance;
  if ( UFG::UIHKScreenHud::mInstance )
    return UFG::UIHKScreenHud::mInstance->PDA;
  return result;
}

// File Line: 135
// RVA: 0x5E9520
__int64 __fastcall UFG::UIHK_PDAWidget::GetState()
{
  UFG::UIHK_PDAWidget *PDA; // rcx

  if ( UFG::UIHKScreenHud::mInstance && (PDA = UFG::UIHKScreenHud::mInstance->PDA) != 0i64 )
    return (unsigned int)PDA->mState;
  else
    return (unsigned int)UFG::UIHKScreenHud::PDACache.state;
}

// File Line: 193
// RVA: 0x637460
void __fastcall UFG::UIHK_PDAWidget::init(UFG::UIHK_PDAWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // r13
  __int64 v4; // rdi
  int v5; // r14d
  UFG::GameStatTracker *v6; // rax
  UFG::PersistentData::MapBool *MapBool; // r12
  unsigned int Count; // r15d
  unsigned int i; // ebx
  bool v10; // r15
  UFG::ProgressionTracker *v11; // rax
  UFG::GameStatTracker *v12; // rax
  UFG::PersistentData::MapBool *v13; // r14
  unsigned int v14; // ebx
  UFG::qSymbol *v15; // rax
  bool v16; // bl
  char *mData; // rbx
  char *v18; // rbx
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+60h] [rbp-A0h] BYREF
  char v21[16]; // [rsp+90h] [rbp-70h] BYREF
  __int64 v22; // [rsp+A0h] [rbp-60h]
  int v23; // [rsp+A8h] [rbp-58h]
  char *v24; // [rsp+B0h] [rbp-50h]
  char v25[16]; // [rsp+C0h] [rbp-40h] BYREF
  __int64 v26; // [rsp+D0h] [rbp-30h]
  int v27; // [rsp+D8h] [rbp-28h]
  char *v28; // [rsp+E0h] [rbp-20h]
  __int64 v29; // [rsp+120h] [rbp+20h]
  UFG::qWiseSymbol result; // [rsp+178h] [rbp+78h] BYREF
  __int64 v31; // [rsp+180h] [rbp+80h]
  __int64 v32; // [rsp+188h] [rbp+88h]

  v29 = -2i64;
  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    this->mMovie = pObject;
    v4 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
           Scaleform::Memory::pGlobalHeap,
           32i64);
    v31 = v4;
    if ( v4 )
    {
      *(_QWORD *)v4 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v4 + 8) = 1;
      *(_QWORD *)v4 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v4 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v4 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
      *(_QWORD *)v4 = &Scaleform::GFx::State::`vftable;
      *(_DWORD *)(v4 + 16) = 3;
      *(_QWORD *)v4 = &Scaleform::GFx::ActionControl::`vftable;
      *(_DWORD *)(v4 + 24) = 8;
    }
    else
    {
      v4 = 0i64;
    }
    v32 = v4;
    *(_DWORD *)(v4 + 24) |= 2u;
    pObject->Scaleform::GFx::StateBag::vfptr->SetState(
      &pObject->Scaleform::GFx::StateBag,
      State_Filter,
      (Scaleform::GFx::State *)v4);
    UFG::UIHKPlayerObjectiveManager::UpdateObjectives(&UFG::UIHK_PDAWidget::ObjectiveManager);
    v5 = 0;
    v6 = UFG::GameStatTracker::Instance();
    MapBool = UFG::GameStatTracker::GetMapBool(v6, Collectible_Safehouse);
    Count = UFG::PersistentData::MapBool::GetCount(MapBool);
    for ( i = 0; i < Count; ++i )
    {
      if ( UFG::PersistentData::MapBool::GetStatusByIndex(MapBool, i) )
        ++v5;
    }
    v10 = 1;
    if ( UFG::ProgressionTracker::Instance()->mModeType == ModeType_Challenge
      || (v11 = UFG::ProgressionTracker::Instance(),
          !(unsigned __int8)UFG::ProgressionTracker::IsUICancellationAllowed(v11)) )
    {
      v10 = 0;
    }
    value.pObjectInterface = 0i64;
    value.Type = VT_Number;
    value.mValue.NValue = (double)v5;
    Scaleform::GFx::Movie::SetVariable(pObject, "gWallpaperId", &value, 1i64);
    v12 = UFG::GameStatTracker::Instance();
    v13 = UFG::GameStatTracker::GetMapBool(v12, Collectible_Bio);
    v14 = 1;
    while ( 1 )
    {
      v15 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v14);
      if ( UFG::PersistentData::MapBool::GetStatus(v13, v15) )
        break;
      if ( ++v14 > 0x2D )
      {
        v16 = 0;
        goto LABEL_17;
      }
    }
    v16 = 1;
LABEL_17:
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Boolean;
    value.mValue.BValue = v16;
    Scaleform::GFx::Movie::SetVariable(pObject, "gBiosAvailable", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Boolean;
    value.mValue.BValue = v10;
    Scaleform::GFx::Movie::SetVariable(pObject, "gSocialHubAvailable", &value, 1i64);
    `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    mData = UFG::UIHK_PDAWidget::mTxtMsg.mData;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_String;
    ptr.mValue.pString = mData;
    v18 = UFG::UIHK_PDAWidget::mTxtContact.mData;
    if ( (v23 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v22 + 16i64))(v22, v21, v24);
      v22 = 0i64;
    }
    v23 = 6;
    v24 = v18;
    if ( (v27 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v26 + 16i64))(v26, v25, v28);
      v26 = 0i64;
    }
    v27 = 6;
    v28 = UFG::UIHK_PDAWidget::mContactImage.mData;
    Scaleform::GFx::Movie::Invoke(pObject, "Phone_SetTextMessage", 0i64, &ptr, 4u);
    switch ( this->mState )
    {
      case STATE_ROOT_MENU:
      case STATE_PHONE_CONTACTS:
      case STATE_TEXT_INBOX:
        UFG::UIHK_PDARootMenuWidget::Activate(&this->RootMenu, this->mRootIntro, this->mPreLocked);
        break;
      case STATE_INCOMING_CALL:
      case STATE_OUTGOING_CALL:
        UFG::UIHK_PDAWidget::ShowIncomingPhoneCall(this);
        if ( this->mAutoAnsCall )
          UFG::UIHK_PDAWidget::AnswerPhoneCall(this);
        break;
      case STATE_INCOMING_TEXT:
      case STATE_OUTGOING_TEXT:
        UFG::UIHK_PDAIncomingTextWidget::Activate(
          &this->IncomingText,
          UFG::UIHK_PDAWidget::mTxtMsg.mData,
          UFG::UIHK_PDAWidget::mTxtContact.mData,
          UFG::UIHK_PDAWidget::mOutgoingTxt,
          UFG::UIHK_PDAWidget::mContactImage.mData);
        break;
      case STATE_DISPLAY_TEXT:
        UFG::UIHK_PDAIncomingTextWidget::DisplayMessage(&this->IncomingText);
        break;
      case STATE_READING_TEXT:
      case STATE_WAIT_TO_WRITE_TEXT:
      case STATE_WRITING_TEXT:
        break;
      default:
        this->mState = STATE_IDLE;
        UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
        break;
    }
    `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Undefined;
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v4);
  }
}

// File Line: 297
// RVA: 0x641060
void __fastcall UFG::UIHK_PDAWidget::update(UFG::UIHK_PDAWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIHKPlayerObjective *v5; // rsi
  unsigned __int8 v6; // dl
  float v7; // xmm0_4
  UFG::GameStatTracker *v8; // rax
  UFG::UIHK_PDATextInboxWidget *p_TextInbox; // rcx
  UFG::ePDAStateEnum mState; // eax
  bool v11; // zf
  bool v12; // zf
  UFG::UIHK_PDAPhoneContactsWidget::eState v13; // eax

  UFG::UIScreenInvokeQueue::Update(&UFG::UIHK_PDAWidget::mScreenInvokeQueue, screen);
  UFG::UIHKPlayerObjectiveManager::UpdatePendingBlips(&UFG::UIHK_PDAWidget::ObjectiveManager);
  if ( !unk_142432920 || UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "MissionRewards") )
    goto LABEL_15;
  unk_142432920 = 0;
  if ( unk_1424329E8 )
  {
    v5 = &stru_142432928;
LABEL_14:
    UFG::UIHKPlayerObjectiveManager::FlashObjective(&UFG::UIHK_PDAWidget::ObjectiveManager, v5);
    goto LABEL_15;
  }
  if ( !unk_1424329EA )
  {
LABEL_9:
    if ( !unk_142432878 )
      goto LABEL_15;
    v6 = byte_142432888[0];
    if ( (unsigned int)byte_142432888[0] >= unk_142432878 )
      v6 = 0;
    byte_142432888[0] = v6;
    v5 = *(UFG::UIHKPlayerObjective **)(*(_QWORD *)&dword_142432880 + 8i64 * v6);
    if ( !v5 )
      goto LABEL_15;
    goto LABEL_13;
  }
  if ( !unk_1424329E9 )
  {
    unk_1424329EA = 0;
    goto LABEL_9;
  }
  v5 = &obj;
LABEL_13:
  if ( UFG::UIHKPlayerObjectiveManager::ShouldFlashObjective(&UFG::UIHK_PDAWidget::ObjectiveManager, v5) )
    goto LABEL_14;
LABEL_15:
  if ( this->m_objectiveScrollingInProgress )
  {
    v7 = elapsed + this->m_objectiveScrollingTimer;
    this->m_objectiveScrollingTimer = v7;
    if ( v7 > 8.0 )
      this->m_objectiveScrollingInProgress = 0;
  }
  UFG::UIHK_PDAWidget::ProcessCustomInput(this, screen, elapsed);
  v8 = UFG::GameStatTracker::Instance();
  if ( UFG::GameStatTracker::GetStat(v8, EnablePDA) && !UFG::UIHK_PDAWidget::mLocked )
  {
    UFG::UIHK_PDARootMenuWidget::Update(&this->RootMenu, screen, elapsed);
    UFG::UIHK_PDAPhoneContactsWidget::Update(&this->PhoneContacts, screen, elapsed);
    if ( (unsigned int)(this->IncomingText.mState - 4) <= 1 )
    {
      if ( !this->IncomingText.mHelpbarShown && this->IncomingText.mDisplayTime > 1.0 )
      {
        UFG::UIHK_PDAIncomingTextWidget::DisplayHelpbar(&this->IncomingText);
        this->IncomingText.mHelpbarShown = 1;
      }
      this->IncomingText.mDisplayTime = elapsed + this->IncomingText.mDisplayTime;
    }
    UFG::UIHK_PDAIncomingCallWidget::Update(&this->IncomingCall, screen, elapsed);
    p_TextInbox = &this->TextInbox;
    if ( this->TextInbox.mState == STATE_ROOT_MENU )
    {
      p_TextInbox->mState = STATE_PHONE_CONTACTS;
      UFG::UIHK_PDATextInboxWidget::Flash_Show(p_TextInbox, screen);
    }
    else if ( this->TextInbox.mState == STATE_TEXT_INBOX )
    {
      p_TextInbox->mState = STATE_IDLE;
      Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, "TextInbox_Hide", 0i64, 0i64, 0);
    }
    UFG::UIHK_PDAClockWidget::Update(&this->Clock, screen);
  }
  if ( this->mShouldHighlight )
  {
    this->mShouldHighlight = 0;
    UFG::UIHK_PDAWidget::Flash_UIHighlight_Init(this, screen);
  }
  if ( this->mState != this->mPrevState && UFG::UIHKScreenHud::mInstance )
    UFG::UIHKScreenHud::mInstance->mUpdateStatGamePosition = 1;
  mState = this->mState;
  switch ( mState )
  {
    case STATE_ROOT_MENU:
      v11 = this->RootMenu.mState == STATE_IDLE;
      goto LABEL_46;
    case STATE_PHONE_CONTACTS:
      v13 = this->PhoneContacts.mState;
      if ( (unsigned int)v13 <= STATE_PHONE_CONTACTS )
        goto LABEL_42;
      v12 = v13 == STATE_INCOMING_TEXT;
LABEL_41:
      if ( !v12 )
        goto LABEL_49;
LABEL_42:
      UFG::UIHK_PDARootMenuWidget::LeaveSubMenu(&this->RootMenu, screen);
      this->mState = STATE_ROOT_MENU;
LABEL_48:
      UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
      goto LABEL_49;
    case STATE_TEXT_INBOX:
      v12 = this->TextInbox.mState == STATE_IDLE;
      goto LABEL_41;
  }
  if ( (unsigned int)(mState - 6) > 2 )
    goto LABEL_49;
  v11 = this->IncomingText.mState == STATE_IDLE;
LABEL_46:
  if ( v11 )
  {
    this->mState = STATE_IDLE;
    goto LABEL_48;
  }
LABEL_49:
  this->mPrevState = this->mState;
}

// File Line: 392
// RVA: 0x62EBB0
bool __fastcall UFG::UIHK_PDAWidget::handleMessage(
        UFG::UIHK_PDAWidget *this,
        UFG::UIScreen *screen,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  bool result; // al
  UFG::UIHK_PDARootMenuWidget *p_RootMenu; // rsi
  char *mData; // rdi
  UFG::UIScreenTextureManager *v9; // rax

  if ( msgId == UI_HASH_PDA_CAMERA_DESTROY_20 )
  {
    if ( this->mState )
    {
      UFG::ConversationManager::InterruptPlayerConversations(eInterruptType_PDAHangup, 1, 0i64);
      UFG::UIHK_PDAWidget::DeactivateAll(this);
      this->mState = STATE_IDLE;
      UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
    }
    return 1;
  }
  else
  {
    switch ( this->mState )
    {
      case STATE_IDLE:
        if ( msgId == UI_HASH_PDA_PHONE_SUCCESS_20 )
        {
          p_RootMenu = &this->RootMenu;
          if ( UFG::UIHK_PDARootMenuWidget::CanActivate(&this->RootMenu) )
          {
            if ( p_RootMenu->mState == STATE_IDLE )
            {
              *(_QWORD *)&p_RootMenu->mState = 4i64;
              this->RootMenu.mRefreshTimer = 0.33333334;
              this->RootMenu.mLastScrolledPrev = 0;
              this->RootMenu.mIntroIndex = 0;
              if ( !this->RootMenu.mInputLocker.mAcquired )
              {
                UFG::SetInputMode_PDA_On(UFG::gActiveControllerNum);
                ++UFG::UIHKGameplayHelpWidget::mLocked;
                ++UFG::UIHK_PDAWidget::mInputLocked;
                this->RootMenu.mInputLocker.mAcquired = 1;
              }
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xF48906FE, 0i64, 0, 0i64);
            }
            this->mState = STATE_ROOT_MENU;
            UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
          }
        }
        goto LABEL_14;
      case STATE_ROOT_MENU:
        if ( msgId == UI_HASH_LIST_OPTION_SELECTED_30 )
        {
          if ( this->RootMenu.mState == STATE_PHONE_CONTACTS )
            this->RootMenu.mState = STATE_INCOMING_TEXT;
          mData = this->RootMenu.mSelectedItem.mData;
          if ( (unsigned int)UFG::qStringCompare(mData, "$HUD_SMARTPHONE_CONTACTS", -1) )
          {
            if ( (unsigned int)UFG::qStringCompare(mData, "$HUD_SMARTPHONE_MESSAGES", -1) )
            {
              if ( (unsigned int)UFG::qStringCompare(mData, "$HUD_SMARTPHONE_SOCIALHUB", -1) )
              {
                if ( (unsigned int)UFG::qStringCompare(mData, "$HUD_SMARTPHONE_BIOS", -1) )
                {
LABEL_14:
                  result = 0;
                }
                else
                {
                  byte_142431A14 = 1;
                  if ( UFG::HudAudio::m_instance )
                    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x9E75334E, 0i64, 0, 0i64);
                  UFG::UIHKScreenCaseComplete::mCaseType = CASE_TYPE_BIOS;
                  v9 = UFG::UIScreenTextureManager::Instance();
                  UFG::UIScreenTextureManager::QueueLoadAndPush(v9, "CaseComplete", 0i64);
                  result = 0;
                }
              }
              else
              {
                byte_142431A14 = 1;
                if ( UFG::HudAudio::m_instance )
                  UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x9E75334E, 0i64, 0, 0i64);
                UFG::UI::PauseGame("SocialHub");
                result = 0;
              }
            }
            else
            {
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x9E75334E, 0i64, 0, 0i64);
              if ( this->TextInbox.mState == STATE_IDLE )
                this->TextInbox.mState = STATE_ROOT_MENU;
              this->mState = STATE_TEXT_INBOX;
              result = 0;
              UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
            }
          }
          else
          {
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x9E75334E, 0i64, 0, 0i64);
            if ( this->PhoneContacts.mState == STATE_IDLE )
            {
              this->PhoneContacts.mState = STATE_ROOT_MENU;
              UFG::UIHK_PDAPhoneContactsWidget::LoadTexturePack(&this->PhoneContacts);
            }
            this->mState = STATE_PHONE_CONTACTS;
            result = 0;
            UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
          }
        }
        else
        {
          UFG::UIHK_PDARootMenuWidget::HandleMessage(&this->RootMenu, screen, msgId);
          result = 0;
        }
        break;
      case STATE_PHONE_CONTACTS:
        if ( UFG::UIHK_PDAPhoneContactsWidget::HandleMessage(&this->PhoneContacts, screen, msgId) )
          return 1;
        goto $LN4_69;
      case STATE_TEXT_INBOX:
$LN4_69:
        if ( msgId != UI_HASH_LIST_OPTION_SELECTED_30 )
          goto LABEL_14;
        result = 1;
        break;
      case STATE_INCOMING_CALL:
      case STATE_OUTGOING_CALL:
        if ( msgId != UI_HASH_PDA_PHONE_SUCCESS_20 || !this->mAutoAnsCall )
          goto LABEL_14;
        UFG::UIHK_PDAWidget::AnswerPhoneCall(this);
        result = 0;
        break;
      case STATE_INCOMING_TEXT:
      case STATE_OUTGOING_TEXT:
        if ( msgId != UI_HASH_PDA_PHONE_SUCCESS_20 || !UFG::UIHK_PDAWidget::mAutoAnsTxt )
          goto LABEL_14;
        UFG::UIHK_PDAWidget::DisplayTextMessage(this);
        result = 0;
        break;
      case STATE_WAIT_TO_WRITE_TEXT:
        if ( msgId != UI_HASH_PDA_PHONE_SUCCESS_20 )
          goto LABEL_14;
        this->mState = STATE_WRITING_TEXT;
        result = 0;
        UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
        break;
      default:
        goto LABEL_14;
    }
  }
  return result;
}

// File Line: 532
// RVA: 0x5FE430
void __fastcall UFG::UIHK_PDAWidget::ProcessCustomInput(
        UFG::UIHK_PDAWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  UFG::InputActionData *v5; // rcx
  UFG::InputActionData *v6; // rcx
  UFG::InputActionData *v7; // rcx
  UFG::InputActionData *v8; // rcx
  UFG::InputActionData *v9; // rcx
  UFG::InputActionData *v10; // rcx
  UFG::InputActionData *v11; // rcx
  bool v12; // r13
  UFG::InputActionData *v13; // rcx
  bool v14; // r12
  UFG::InputActionData *v15; // rcx
  bool v16; // r15
  UFG::InputActionData *v17; // rcx
  float v18; // xmm2_4
  float mAxisPositionY; // xmm3_4
  UFG::InputActionData *v20; // rcx
  char v21; // [rsp+20h] [rbp-48h]
  char v22; // [rsp+21h] [rbp-47h]
  char v23; // [rsp+22h] [rbp-46h]
  char v24; // [rsp+23h] [rbp-45h]
  char v25; // [rsp+78h] [rbp+10h]
  char v26; // [rsp+88h] [rbp+20h]

  if ( screen->mRenderable->m_shouldRender )
  {
    v5 = UFG::ActionDef_UIL1Pressed.mDataPerController[UFG::gActiveControllerNum];
    if ( !v5 || (v22 = 1, !v5->mActionTrue) )
      v22 = 0;
    v6 = UFG::ActionDef_UIR1Pressed.mDataPerController[UFG::gActiveControllerNum];
    if ( !v6 || (v24 = 1, !v6->mActionTrue) )
      v24 = 0;
    v7 = UFG::ActionDef_UIL3Pressed.mDataPerController[UFG::gActiveControllerNum];
    if ( !v7 || (v23 = 1, !v7->mActionTrue) )
      v23 = 0;
    v8 = UFG::ActionDef_UIAcceptReleased.mDataPerController[UFG::gActiveControllerNum];
    if ( !v8 || (v26 = 1, !v8->mActionTrue) )
      v26 = 0;
    v9 = UFG::ActionDef_UIBackReleased.mDataPerController[UFG::gActiveControllerNum];
    if ( !v9 || (v21 = 1, !v9->mActionTrue) )
      v21 = 0;
    v10 = UFG::ActionDef_UIUpPressed.mDataPerController[UFG::gActiveControllerNum];
    if ( !v10 || (v25 = 1, !v10->mActionTrue) )
      v25 = 0;
    v11 = UFG::ActionDef_UIDownPressed.mDataPerController[UFG::gActiveControllerNum];
    v12 = v11 && v11->mActionTrue;
    v13 = UFG::ActionDef_UILeftPressed.mDataPerController[UFG::gActiveControllerNum];
    v14 = v13 && v13->mActionTrue;
    v15 = UFG::ActionDef_UIRightPressed.mDataPerController[UFG::gActiveControllerNum];
    v16 = v15 && v15->mActionTrue;
    v17 = UFG::ActionDef_UIRightThumbstick.mDataPerController[UFG::gActiveControllerNum];
    v18 = 0.0;
    if ( v17 )
      mAxisPositionY = v17->mAxisPositionY;
    else
      mAxisPositionY = 0.0;
    v20 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
    if ( v20 )
      v18 = v20->mAxisPositionY;
    if ( v18 < -0.2 )
      UFG::UIHK_PDAWidget::HandleCustomInput(this, screen, UI_HASH_THUMBSTICK_LEFT_UP_30);
    if ( v18 > 0.2 )
      UFG::UIHK_PDAWidget::HandleCustomInput(this, screen, UI_HASH_THUMBSTICK_LEFT_DOWN_30);
    if ( mAxisPositionY < -0.2 )
      UFG::UIHK_PDAWidget::HandleCustomInput(this, screen, UI_HASH_THUMBSTICK_RIGHT_UP_30);
    if ( mAxisPositionY > 0.2 )
      UFG::UIHK_PDAWidget::HandleCustomInput(this, screen, UI_HASH_THUMBSTICK_RIGHT_DOWN_30);
    if ( v25 )
      UFG::UIHK_PDAWidget::HandleCustomInput(this, screen, UI_HASH_DPAD_UP_PRESSED_30);
    if ( v12 )
      UFG::UIHK_PDAWidget::HandleCustomInput(this, screen, UI_HASH_DPAD_DOWN_PRESSED_30);
    if ( v14 )
      UFG::UIHK_PDAWidget::HandleCustomInput(this, screen, UI_HASH_DPAD_LEFT_PRESSED_30);
    if ( v16 )
      UFG::UIHK_PDAWidget::HandleCustomInput(this, screen, UI_HASH_DPAD_RIGHT_PRESSED_30);
    if ( v26 )
      UFG::UIHK_PDAWidget::HandleCustomInput(this, screen, UI_HASH_BUTTON_ACCEPT_RELEASED_30);
    if ( v21 )
      UFG::UIHK_PDAWidget::HandleCustomInput(this, screen, UI_HASH_BUTTON_BACK_RELEASED_30);
    if ( v22 )
      UFG::UIHK_PDAWidget::HandleCustomInput(this, screen, UI_HASH_BUTTON_L1_PRESSED_30);
    if ( v23 )
      UFG::UIHK_PDAWidget::HandleCustomInput(this, screen, UI_HASH_BUTTON_L3_PRESSED_30);
    if ( v24 )
      UFG::UIHK_PDAWidget::HandleCustomInput(this, screen, UI_HASH_BUTTON_R1_PRESSED_30);
    if ( UFG::gEnableWorldMapAndPDA && v23 && UFG::UIHKTweakables::RenderMinimap )
      UFG::UIHK_PDAWidget::DisplayObjective(this);
  }
}:UIHKTweakables::RenderMinimap )
   

// File Line: 596
// RVA: 0x5EA850
void __fastcall UFG::UIHK_PDAWidget::HandleCustomInput(
        UFG::UIHK_PDAWidget *this,
        UFG::UIScreen *screen,
        unsigned int msgId)
{
  UFG::ePDAStateEnum mState; // eax
  UFG::UIHK_PDAIncomingCallWidget *p_IncomingCall; // rcx

  mState = this->mState;
  switch ( mState )
  {
    case STATE_PHONE_CONTACTS:
      UFG::UIHK_PDAPhoneContactsWidget::ProcessInput(&this->PhoneContacts, screen, msgId);
      break;
    case STATE_TEXT_INBOX:
      UFG::UIHK_PDATextInboxWidget::HandleMessage(&this->TextInbox, screen, msgId);
      break;
    case STATE_INCOMING_CALL:
      p_IncomingCall = &this->IncomingCall;
      if ( p_IncomingCall->mState == STATE_PHONE_CONTACTS && msgId == UI_HASH_DPAD_UP_PRESSED_30 )
        UFG::UIHK_PDAIncomingCallWidget::Answer(p_IncomingCall);
      break;
    default:
      if ( (unsigned int)(mState - 6) <= 2 )
        UFG::UIHK_PDAIncomingTextWidget::HandleMessage(&this->IncomingText, screen, msgId);
      break;
  }
}

// File Line: 649
// RVA: 0x5F1C70
void UFG::UIHK_PDAWidget::Lock(void)
{
  UFG::UIHK_PDAWidget *PDA; // rbx

  if ( UFG::UIHKScreenHud::mInstance )
  {
    PDA = UFG::UIHKScreenHud::mInstance->PDA;
    if ( PDA )
    {
      UFG::UIHK_PDAWidget::ForceIdle(PDA);
      PDA->mState = STATE_IDLE;
      UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
    }
  }
  ++UFG::UIHK_PDAWidget::mLocked;
}

// File Line: 661
// RVA: 0x613250
void UFG::UIHK_PDAWidget::Unlock(void)
{
  if ( UFG::UIHK_PDAWidget::mLocked )
    --UFG::UIHK_PDAWidget::mLocked;
}

// File Line: 731
// RVA: 0x5EC970
bool __fastcall UFG::UIHK_PDAWidget::HasAnswered(UFG::UIHK_PDAWidget *this)
{
  return this->IncomingCall.mState == STATE_INCOMING_CALL;
}

// File Line: 749
// RVA: 0x5FE9C0
char __fastcall UFG::UIHK_PDAWidget::QueueIncomingPhoneCall(
        UFG::UIHK_PDAWidget *this,
        const char *contactName,
        bool outgoing,
        bool autoCall,
        bool voiceMail)
{
  bool v5; // bl
  const char *v7; // r14
  const char *v9; // rdi
  unsigned int v10; // edx
  UFG::qSymbol *v11; // rax
  UFG::qPropertySet *PropertySet; // rax
  UFG::qPropertyList *v13; // rax
  UFG::qPropertyList *v14; // r13
  unsigned int mNumElements; // r15d
  unsigned int v16; // ebp
  char *ValuePtr; // rax
  UFG::qPropertySet *v18; // rbx
  char *v19; // rax
  char *v20; // rax
  unsigned int v21; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  bool v23; // al
  UFG::qSymbol result; // [rsp+88h] [rbp+20h] BYREF

  v5 = outgoing;
  v7 = contactName;
  v9 = 0i64;
  if ( (unsigned int)UFG::qStringCompare(contactName, "$PDA_CONTACT_TENG_CASE", -1) )
  {
    if ( UFG::HudAudio::m_instance )
    {
      v10 = 0x19F4418E;                         // Play_pda_ring_01
      goto LABEL_6;
    }
  }
  else if ( UFG::HudAudio::m_instance )
  {
    v10 = 0x846A3783;                           // Play_pda_ring_teng
LABEL_6:
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v10, 0i64, 0, 0i64);
  }
  UFG::qString::Set(&UFG::UIHK_PDAWidget::mContactImage, "Portrait_Smartphone_Unknown");
  v11 = UFG::qSymbol::create_from_string(&result, "default-unlockables-contactList-list");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v11);
  this->mContactData = PropertySet;
  v13 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          PropertySet,
          (UFG::qArray<unsigned long,0> *)&qSymbol_List_20,
          DEPTH_RECURSE);
  v14 = v13;
  if ( v13 )
  {
    mNumElements = v13->mNumElements;
    v16 = 0;
    if ( mNumElements )
    {
      do
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v14, 0x1Au, v16);
        if ( !ValuePtr || (v18 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
          v18 = 0i64;
        v19 = PropertyUtils::Get<char const *>(v18, (UFG::qArray<unsigned long,0> *)&qSymbol_Name_20, DEPTH_RECURSE);
        UFG::qString::Set(&UFG::UIHK_PDAWidget::mContactID, v19);
        if ( UFG::qString::operator==(&UFG::UIHK_PDAWidget::mContactID, v7) )
        {
          v20 = PropertyUtils::Get<char const *>(
                  v18,
                  (UFG::qArray<unsigned long,0> *)&qSymbol_Portrait_20,
                  DEPTH_RECURSE);
          UFG::qString::Set(&UFG::UIHK_PDAWidget::mContactImage, v20);
        }
        ++v16;
      }
      while ( v16 < mNumElements );
      v5 = outgoing;
    }
  }
  if ( v7 )
  {
    if ( *v7 == 36 )
      ++v7;
    v21 = UFG::qStringHashUpper32(v7, -1);
    m_translator = UFG::UIScreenManager::s_instance->m_translator;
    if ( !m_translator || (v9 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v21)) == 0i64 )
      v9 = v7;
  }
  UFG::qString::Set(&this->mPhoneContact, v9);
  v23 = voiceMail;
  this->mOutgoingCall = v5;
  this->mAutoAnsCall = autoCall;
  this->mVoiceMail = v23;
  UFG::UIHK_PDAWidget::ForceIdle(this);
  if ( this->mOutgoingCall )
    this->mState = STATE_OUTGOING_CALL;
  else
    this->mState = STATE_INCOMING_CALL;
  UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  UFG::UIHK_PDAIncomingCallWidget::Activate(
    &this->IncomingCall,
    this->mPhoneContact.mData,
    UFG::UIHK_PDAWidget::mContactImage.mData,
    this->mOutgoingCall,
    this->mVoiceMail);
  return 1;
}

// File Line: 789
// RVA: 0x610890
void __fastcall UFG::UIHK_PDAWidget::ShowIncomingPhoneCall(UFG::UIHK_PDAWidget *this)
{
  UFG::UIHK_PDAWidget::ForceIdle(this);
  if ( this->mOutgoingCall )
    this->mState = STATE_OUTGOING_CALL;
  else
    this->mState = STATE_INCOMING_CALL;
  UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  UFG::UIHK_PDAIncomingCallWidget::Activate(
    &this->IncomingCall,
    this->mPhoneContact.mData,
    UFG::UIHK_PDAWidget::mContactImage.mData,
    this->mOutgoingCall,
    this->mVoiceMail);
}

// File Line: 804
// RVA: 0x5D3B10
char __fastcall UFG::UIHK_PDAWidget::AnswerPhoneCall(UFG::UIHK_PDAWidget *this)
{
  UFG::UIHK_PDAIncomingCallWidget::SetCallerName(
    &this->IncomingCall,
    this->mPhoneContact.mData,
    UFG::UIHK_PDAWidget::mContactImage.mData,
    this->mVoiceMail);
  UFG::UIHK_PDAIncomingCallWidget::Answer(&this->IncomingCall);
  this->mState = STATE_INCOMING_CALL;
  UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  UFG::ConversationManager::ResumePlayerConversations(eInterruptType_PDAHangup);
  return 1;
}

// File Line: 814
// RVA: 0x5D7150
char __fastcall UFG::UIHK_PDAWidget::EndPhoneCall(UFG::UIHK_PDAWidget *this, bool playSound)
{
  char result; // al

  if ( (unsigned int)(this->mState - 4) > 1 )
    return 0;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xD92517u, 0i64, 0, 0i64);
  if ( this->IncomingCall.mState )
  {
    UFG::UIHK_PDAIncomingCallWidget::HangUp(&this->IncomingCall, playSound);
    this->IncomingCall.mUpdateTimer = 0;
  }
  UFG::UIHK_PDAIncomingCallWidget::ReleaseInputLock(&this->IncomingCall, "Deactivate");
  UFG::UIHK_PDARootMenuWidget::Deactivate(&this->RootMenu);
  this->mState = STATE_IDLE;
  result = 1;
  UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  return result;
}

// File Line: 827
// RVA: 0x5FEC40
char __fastcall UFG::UIHK_PDAWidget::QueueIncomingTextMessage(
        UFG::UIHK_PDAWidget *this,
        const char *contactName,
        const char *message,
        const char *portrait,
        bool outgoing,
        bool autoAnswer)
{
  UFG::qString::Set(&UFG::UIHK_PDAWidget::mTxtContact, contactName);
  UFG::qString::Set(&UFG::UIHK_PDAWidget::mTxtMsg, message);
  UFG::UIHK_PDAWidget::mOutgoingTxt = outgoing;
  UFG::UIHK_PDAWidget::mAutoAnsTxt = autoAnswer;
  UFG::qString::Set(&UFG::UIHK_PDAWidget::mContactImage, portrait);
  UFG::UIHK_PDAWidget::ShowIncomingTextMessage(this);
  return 1;
}

// File Line: 840
// RVA: 0x612190
bool __fastcall UFG::UIHK_PDAWidget::StartReadingText(UFG::UIHK_PDAWidget *this)
{
  bool result; // al

  if ( this->mState )
    return 0;
  this->mState = STATE_READING_TEXT;
  result = 1;
  UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  return result;
}

// File Line: 852
// RVA: 0x6124A0
char __fastcall UFG::UIHK_PDAWidget::StartWritingText(UFG::UIHK_PDAWidget *this)
{
  char result; // al

  if ( this->mState )
    return 0;
  this->mState = STATE_WAIT_TO_WRITE_TEXT;
  result = 1;
  UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  return result;
}

// File Line: 864
// RVA: 0x610900
void __fastcall UFG::UIHK_PDAWidget::ShowIncomingTextMessage(UFG::UIHK_PDAWidget *this)
{
  UFG::ePDAStateEnum v2; // eax
  unsigned int v3; // edx

  UFG::UIHK_PDAWidget::ForceIdle(this);
  v2 = STATE_INCOMING_TEXT;
  if ( UFG::UIHK_PDAWidget::mOutgoingTxt )
    v2 = STATE_OUTGOING_TEXT;
  this->mState = v2;
  UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  UFG::UIHK_PDAIncomingTextWidget::Activate(
    &this->IncomingText,
    UFG::UIHK_PDAWidget::mTxtMsg.mData,
    UFG::UIHK_PDAWidget::mTxtContact.mData,
    UFG::UIHK_PDAWidget::mOutgoingTxt,
    UFG::UIHK_PDAWidget::mContactImage.mData);
  if ( UFG::UIHK_PDAWidget::mOutgoingTxt )
  {
    if ( !UFG::HudAudio::m_instance )
      return;
    v3 = 687526935;
  }
  else
  {
    if ( !UFG::HudAudio::m_instance )
      return;
    v3 = 241429984;
  }
  UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v3, 0i64, 0, 0i64);
}

// File Line: 881
// RVA: 0x5D6EB0
void __fastcall UFG::UIHK_PDAWidget::DisplayTextMessage(UFG::UIHK_PDAWidget *this)
{
  if ( this->mState == STATE_PHONE_CONTACTS && this->PhoneContacts.mState )
    this->PhoneContacts.mState = STATE_INCOMING_TEXT;
  if ( !UFG::UIHK_PDAWidget::mLocked )
  {
    UFG::UIHK_PDAIncomingTextWidget::DisplayMessage(&this->IncomingText);
    this->mState = STATE_DISPLAY_TEXT;
    UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  }
}

// File Line: 896
// RVA: 0x5D6640
char __fastcall UFG::UIHK_PDAWidget::DismissTextMessage(
        UFG::UIHK_PDAWidget *this,
        UFG::UIHK_PDAIncomingTextWidget::eDismissCause dismissCause)
{
  if ( ((this->mState - 6) & 0xFFFFFFFD) != 0 )
    return 0;
  UFG::UIHK_PDAIncomingTextWidget::DismissMessage(&this->IncomingText, dismissCause);
  return 1;
}

// File Line: 907
// RVA: 0x5E7920
__int64 __fastcall UFG::UIHK_PDAWidget::GetDismissCause(UFG::UIHK_PDAWidget *this)
{
  return (unsigned int)this->IncomingText.mDismissCause;
}

// File Line: 913
// RVA: 0x5EC980
_BOOL8 __fastcall UFG::UIHK_PDAWidget::HasReadTextMessage(UFG::UIHK_PDAWidget *this)
{
  return this->IncomingText.mMessageRead;
}

// File Line: 919
// RVA: 0x5EE280
_BOOL8 __fastcall UFG::UIHK_PDAWidget::IsIdle(UFG::UIHK_PDAWidget *this)
{
  return this->mState == STATE_IDLE;
}

// File Line: 945
// RVA: 0x5D6080
void __fastcall UFG::UIHK_PDAWidget::DeactivateAll(UFG::UIHK_PDAWidget *this)
{
  UFG::UIHK_PDARootMenuWidget *p_RootMenu; // rcx
  UFG::UIHK_PDAPhoneContactsWidget::eState mState; // eax
  int v4; // eax

  p_RootMenu = &this->RootMenu;
  if ( p_RootMenu->mState )
    UFG::UIHK_PDARootMenuWidget::Deactivate(p_RootMenu);
  mState = this->PhoneContacts.mState;
  if ( mState > (unsigned int)STATE_PHONE_CONTACTS && mState != STATE_INCOMING_TEXT )
    this->PhoneContacts.mState = STATE_INCOMING_TEXT;
  if ( this->TextInbox.mState )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4AAC5E6Bu, 0i64, 0, 0i64);
    this->TextInbox.mState = STATE_TEXT_INBOX;
  }
  if ( this->IncomingCall.mState )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xD92517u, 0i64, 0, 0i64);
    if ( this->IncomingCall.mState )
    {
      UFG::UIHK_PDAIncomingCallWidget::HangUp(&this->IncomingCall, 1);
      this->IncomingCall.mUpdateTimer = 0;
    }
    UFG::UIHK_PDAIncomingCallWidget::ReleaseInputLock(&this->IncomingCall, "Deactivate");
  }
  if ( this->IncomingText.mState )
  {
    UFG::UIHK_PDAIncomingTextWidget::DismissMessage(&this->IncomingText, DISMISS_CAUSE_DEACTIVATE);
    if ( this->IncomingText.mInputLocker.mAcquired )
    {
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
      this->IncomingText.mInputLocker.mAcquired = 0;
    }
  }
}

// File Line: 982
// RVA: 0x5E6510
void __fastcall UFG::UIHK_PDAWidget::ForceIdle(UFG::UIHK_PDAWidget *this)
{
  Scaleform::GFx::Movie *pObject; // rcx
  int v3; // eax
  UFG::UIScreenTextureManager *v4; // rax
  int v5; // eax

  pObject = UFG::UIHKScreenHud::mInstance->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "Smartphone_HideAll", 0i64, 0i64, 0);
  this->RootMenu.mState = STATE_IDLE;
  if ( !byte_142431A14 && this->RootMenu.mInputLocker.mAcquired )
  {
    if ( UFG::UIHK_PDAWidget::mInputLocked )
    {
      UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
      v3 = UFG::UIHKGameplayHelpWidget::mLocked;
      if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
        v3 = --UFG::UIHKGameplayHelpWidget::mLocked;
      if ( v3 < 1 )
        UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
      --UFG::UIHK_PDAWidget::mInputLocked;
    }
    this->RootMenu.mInputLocker.mAcquired = 0;
  }
  this->PhoneContacts.mState = STATE_IDLE;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v4, UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename);
  this->TextInbox.mState = STATE_IDLE;
  this->IncomingCall.mState = STATE_IDLE;
  UFG::UIHK_PDAIncomingCallWidget::ReleaseInputLock(&this->IncomingCall, "ForceIdle");
  this->IncomingText.mState = STATE_IDLE;
  if ( this->IncomingText.mInputLocker.mAcquired )
  {
    if ( UFG::UIHK_PDAWidget::mInputLocked )
    {
      UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
      v5 = UFG::UIHKGameplayHelpWidget::mLocked;
      if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
        v5 = --UFG::UIHKGameplayHelpWidget::mLocked;
      if ( v5 < 1 )
        UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
      --UFG::UIHK_PDAWidget::mInputLocked;
    }
    this->IncomingText.mInputLocker.mAcquired = 0;
  }
}

// File Line: 993
// RVA: 0x5D6A80
void __fastcall UFG::UIHK_PDAWidget::DisplayObjective(UFG::UIHK_PDAWidget *this)
{
  char v2; // r10
  UFG::UIHKPlayerObjective *v3; // rax
  char v4; // dl
  unsigned int v5; // r8d
  unsigned __int8 v6; // r9
  UFG::Objective *mObjective; // rcx
  const char *mData; // rcx
  unsigned __int8 v9; // cl
  UFG::UIHKPlayerObjective *v10; // rdx

  if ( this->mGPSActivatedFlag )
  {
    this->mGPSActivatedFlag = 0;
    return;
  }
  if ( this->m_objectiveScrollingInProgress )
    goto LABEL_27;
  v2 = unk_1424329E8;
  if ( unk_1424329E8 )
  {
    v3 = &stru_142432928;
    goto LABEL_14;
  }
  v4 = unk_1424329EA;
  if ( !unk_1424329EA )
  {
LABEL_10:
    v5 = unk_142432878;
    if ( !unk_142432878 )
    {
LABEL_19:
      v6 = byte_142432888[0];
      goto LABEL_20;
    }
    v6 = byte_142432888[0];
    if ( (unsigned int)byte_142432888[0] >= unk_142432878 )
      v6 = 0;
    byte_142432888[0] = v6;
    v3 = *(UFG::UIHKPlayerObjective **)(*(_QWORD *)&dword_142432880 + 8i64 * v6);
    if ( !v3 )
    {
LABEL_20:
      unk_142432920 = 1;
      if ( v2 || v4 || !v5 )
        goto LABEL_28;
      v9 = v6;
      if ( v6 >= v5 )
        v9 = 0;
      byte_142432888[0] = v9;
      v10 = *(UFG::UIHKPlayerObjective **)(*(_QWORD *)&dword_142432880 + 8i64 * v9);
      if ( !v10 || UFG::UIHKPlayerObjectiveManager::ShouldFlashObjective(&UFG::UIHK_PDAWidget::ObjectiveManager, v10) )
        goto LABEL_28;
      goto LABEL_27;
    }
    goto LABEL_14;
  }
  if ( !unk_1424329E9 )
  {
    v4 = 0;
    unk_1424329EA = 0;
    goto LABEL_10;
  }
  v3 = &obj;
LABEL_14:
  mObjective = v3->mObjective;
  if ( mObjective )
    mData = mObjective->mCaption.mData;
  else
    mData = v3->alternateCaption.mData;
  if ( (int)UFG::qStringLength(mData) >= 1 )
  {
    v4 = unk_1424329EA;
    v2 = unk_1424329E8;
    v5 = unk_142432878;
    goto LABEL_19;
  }
LABEL_27:
  UFG::UIHKPlayerObjectiveManager::ScrollNextObjective(&UFG::UIHK_PDAWidget::ObjectiveManager);
LABEL_28:
  this->m_objectiveScrollingTimer = 0.0;
  this->m_objectiveScrollingInProgress = 1;
}

// File Line: 1023
// RVA: 0x5E5540
void __fastcall UFG::UIHK_PDAWidget::Flash_UIHighlight_Init(UFG::UIHK_PDAWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-68h] BYREF
  char v4[16]; // [rsp+70h] [rbp-38h] BYREF
  __int64 v5; // [rsp+80h] [rbp-28h]
  int v6; // [rsp+88h] [rbp-20h]
  const char *v7; // [rsp+90h] [rbp-18h]

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_String;
    ptr.mValue.pString = "mc_Minimap";
    if ( (v6 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v5 + 16i64))(v5, v4, v7);
      v5 = 0i64;
    }
    v6 = 6;
    v7 = "mc_CircleMenu_highlight";
    Scaleform::GFx::Movie::Invoke(pObject, "UIHighlight_Init", 0i64, &ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

