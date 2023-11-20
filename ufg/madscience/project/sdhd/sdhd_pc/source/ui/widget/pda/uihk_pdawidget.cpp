// File Line: 67
// RVA: 0x1567440
__int64 dynamic_initializer_for__UFG::UIHK_PDAWidget::mScreenInvokeQueue__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::UIHK_PDAWidget::mScreenInvokeQueue__);
}

// File Line: 68
// RVA: 0x1566B90
__int64 dynamic_initializer_for__UFG::UIHK_PDAWidget::ObjectiveManager__()
{
  UFG::UIHKPlayerObjectiveManager::UIHKPlayerObjectiveManager(&UFG::UIHK_PDAWidget::ObjectiveManager);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHK_PDAWidget::ObjectiveManager__);
}

// File Line: 79
// RVA: 0x15674C0
__int64 dynamic_initializer_for__UFG::UIHK_PDAWidget::mTxtContact__()
{
  UFG::qString::qString(&UFG::UIHK_PDAWidget::mTxtContact, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHK_PDAWidget::mTxtContact__);
}

// File Line: 80
// RVA: 0x15674F0
__int64 dynamic_initializer_for__UFG::UIHK_PDAWidget::mTxtMsg__()
{
  UFG::qString::qString(&UFG::UIHK_PDAWidget::mTxtMsg, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHK_PDAWidget::mTxtMsg__);
}

// File Line: 81
// RVA: 0x1566F20
__int64 dynamic_initializer_for__UFG::UIHK_PDAWidget::mContactImage__()
{
  UFG::qString::qString(&UFG::UIHK_PDAWidget::mContactImage, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHK_PDAWidget::mContactImage__);
}

// File Line: 82
// RVA: 0x1566EF0
__int64 dynamic_initializer_for__UFG::UIHK_PDAWidget::mContactID__()
{
  UFG::qString::qString(&UFG::UIHK_PDAWidget::mContactID, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::UIHK_PDAWidget::mContactID__);
}

// File Line: 112
// RVA: 0x5C8670
void __fastcall UFG::UIHK_PDAWidget::UIHK_PDAWidget(UFG::UIHK_PDAWidget *this, UFG::UIHK_PDACache *cache)
{
  UFG::UIHK_PDACache *v2; // rdi
  UFG::UIHK_PDAWidget *v3; // rsi
  signed __int64 v4; // [rsp+58h] [rbp+10h]
  signed __int64 v5; // [rsp+58h] [rbp+10h]

  v2 = cache;
  v3 = this;
  this->vfptr = (UFG::UIHK_PDAWidgetVtbl *)&UFG::UIHK_PDAWidget::`vftable;
  UFG::UIHK_PDAPhoneContactsWidget::UIHK_PDAPhoneContactsWidget(&this->PhoneContacts);
  v3->mState = v2->state;
  v3->mMovie = 0i64;
  v4 = (signed __int64)&v3->RootMenu;
  *(_QWORD *)v4 = 0i64;
  *(_DWORD *)(v4 + 8) = 0;
  *(_BYTE *)(v4 + 12) = 0;
  *(_QWORD *)(v4 + 16) = 0i64;
  UFG::qString::qString(&v3->RootMenu.mSelectedItem);
  UFG::qString::qString(&v3->RootMenu.mInputLocker.mOwner, "UIHK_PDARootMenuWidget");
  v3->RootMenu.mInputLocker.mAcquired = 0;
  v3->TextInbox.mState = 0;
  UFG::UIHK_PDAIncomingCallWidget::UIHK_PDAIncomingCallWidget(&v3->IncomingCall);
  v5 = (signed __int64)&v3->IncomingText;
  *(_DWORD *)v5 = 0;
  *(_WORD *)(v5 + 4) = 0;
  *(_BYTE *)(v5 + 6) = 0;
  *(_QWORD *)(v5 + 8) = 0i64;
  UFG::qString::qString(&v3->IncomingText.mInputLocker.mOwner, "UIHK_PDAIncomingTextWidget");
  v3->IncomingText.mInputLocker.mAcquired = 0;
  v3->Clock.mClockTime = 0;
  v3->m_objectiveScrollingInProgress = 0;
  *(_QWORD *)&v3->m_objectiveScrollingTimer = 0i64;
  *(_QWORD *)&v3->m_R3_timer = 0i64;
  v3->mRightStickTimer = 0.0;
  *(_WORD *)&v3->mLeftStickActive = 257;
  v3->mGPSActivatedFlag = 0;
  v3->mPDAOpenDelay = 0;
  v3->mShouldHighlight = 0;
  v3->mPreLocked = v2->plock;
  v3->mRootIntro = v2->root;
  UFG::qString::qString(&v3->mPhoneContact, &v2->caller);
  v3->mOutgoingCall = v2->outgoing;
  v3->mAutoAnsCall = v2->answered;
  v3->mVoiceMail = v2->vmail;
  v3->mTime = 0.0;
}

// File Line: 117
// RVA: 0x5CDEA0
void __fastcall UFG::UIHK_PDAWidget::~UIHK_PDAWidget(UFG::UIHK_PDAWidget *this)
{
  UFG::UIHK_PDAWidget *v1; // rdi

  v1 = this;
  this->vfptr = (UFG::UIHK_PDAWidgetVtbl *)&UFG::UIHK_PDAWidget::`vftable;
  UFG::UIHK_PDAWidget::EndPhoneCall(this, 0);
  UFG::UIHK_PDAWidget::ForceIdle(v1);
  UFG::qString::~qString(&v1->mPhoneContact);
  UFG::UIHK_PDAIncomingTextWidget::~UIHK_PDAIncomingTextWidget(&v1->IncomingText);
  UFG::UIHK_PDAIncomingCallWidget::~UIHK_PDAIncomingCallWidget(&v1->IncomingCall);
  UFG::UIHK_PDARootMenuWidget::Deactivate(&v1->RootMenu);
  UFG::qString::~qString(&v1->RootMenu.mInputLocker.mOwner);
  UFG::qString::~qString(&v1->RootMenu.mSelectedItem);
  UFG::UIHK_PDAPhoneContactsWidget::~UIHK_PDAPhoneContactsWidget(&v1->PhoneContacts);
}

// File Line: 124
// RVA: 0x5E6920
UFG::UIHK_PDAWidget *__fastcall UFG::UIHK_PDAWidget::Get()
{
  UFG::UIHK_PDAWidget *result; // rax

  result = (UFG::UIHK_PDAWidget *)UFG::UIHKScreenHud::mInstance;
  if ( UFG::UIHKScreenHud::mInstance )
    result = UFG::UIHKScreenHud::mInstance->PDA;
  return result;
}

// File Line: 135
// RVA: 0x5E9520
__int64 __fastcall UFG::UIHK_PDAWidget::GetState()
{
  UFG::UIHK_PDAWidget *v0; // rcx
  __int64 result; // rax

  if ( UFG::UIHKScreenHud::mInstance && (v0 = UFG::UIHKScreenHud::mInstance->PDA) != 0i64 )
    result = (unsigned int)v0->mState;
  else
    result = (unsigned int)UFG::UIHKScreenHud::PDACache.state;
  return result;
}

// File Line: 193
// RVA: 0x637460
void __fastcall UFG::UIHK_PDAWidget::init(UFG::UIHK_PDAWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHK_PDAWidget *v2; // rsi
  Scaleform::GFx::Movie *v3; // r13
  __int64 v4; // rdi
  signed int v5; // er14
  UFG::GameStatTracker *v6; // rax
  UFG::PersistentData::MapBool *v7; // r12
  unsigned int v8; // er15
  unsigned int v9; // ebx
  bool v10; // r15
  UFG::ProgressionTracker *v11; // rax
  UFG::GameStatTracker *v12; // rax
  UFG::PersistentData::MapBool *v13; // r14
  unsigned int v14; // ebx
  UFG::qSymbol *v15; // rax
  bool v16; // bl
  char *v17; // rbx
  char *v18; // rbx
  Scaleform::GFx::Value value; // [rsp+30h] [rbp-D0h]
  char ptr; // [rsp+60h] [rbp-A0h]
  __int64 v21; // [rsp+70h] [rbp-90h]
  unsigned int v22; // [rsp+78h] [rbp-88h]
  char *v23; // [rsp+80h] [rbp-80h]
  char v24; // [rsp+90h] [rbp-70h]
  __int64 v25; // [rsp+A0h] [rbp-60h]
  unsigned int v26; // [rsp+A8h] [rbp-58h]
  char *v27; // [rsp+B0h] [rbp-50h]
  char v28; // [rsp+C0h] [rbp-40h]
  __int64 v29; // [rsp+D0h] [rbp-30h]
  unsigned int v30; // [rsp+D8h] [rbp-28h]
  char *v31; // [rsp+E0h] [rbp-20h]
  __int64 v32; // [rsp+120h] [rbp+20h]
  UFG::qWiseSymbol result; // [rsp+178h] [rbp+78h]
  __int64 v34; // [rsp+180h] [rbp+80h]
  __int64 v35; // [rsp+188h] [rbp+88h]

  v32 = -2i64;
  v2 = this;
  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    this->mMovie = v3;
    v4 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
           Scaleform::Memory::pGlobalHeap,
           32i64);
    v34 = v4;
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
    v35 = v4;
    *(_DWORD *)(v4 + 24) |= 2u;
    v3->vfptr->SetState((Scaleform::GFx::StateBag *)&v3->vfptr, State_Filter, (Scaleform::GFx::State *)v4);
    UFG::UIHKPlayerObjectiveManager::UpdateObjectives(&UFG::UIHK_PDAWidget::ObjectiveManager);
    v5 = 0;
    v6 = UFG::GameStatTracker::Instance();
    v7 = UFG::GameStatTracker::GetMapBool(v6, Collectible_Safehouse);
    v8 = UFG::PersistentData::MapBool::GetCount(v7);
    v9 = 0;
    if ( v8 )
    {
      do
      {
        if ( UFG::PersistentData::MapBool::GetStatusByIndex(v7, v9) == 1 )
          ++v5;
        ++v9;
      }
      while ( v9 < v8 );
    }
    v10 = 1;
    if ( UFG::ProgressionTracker::Instance()->mModeType == 2
      || (v11 = UFG::ProgressionTracker::Instance(),
          !(unsigned __int8)UFG::ProgressionTracker::IsUICancellationAllowed(v11)) )
    {
      v10 = 0;
    }
    value.pObjectInterface = 0i64;
    value.Type = 0;
    value.Type = 5;
    value.mValue.NValue = (double)v5;
    Scaleform::GFx::Movie::SetVariable(v3, "gWallpaperId", &value, 1i64);
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
        goto LABEL_19;
      }
    }
    v16 = 1;
LABEL_19:
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 2;
    value.mValue.BValue = v16;
    Scaleform::GFx::Movie::SetVariable(v3, "gBiosAvailable", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 2;
    value.mValue.BValue = v10;
    Scaleform::GFx::Movie::SetVariable(v3, "gSocialHubAvailable", &value, 1i64);
    `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v17 = UFG::UIHK_PDAWidget::mTxtMsg.mData;
    if ( (v22 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v21 + 16i64))(v21, &ptr, v23);
      v21 = 0i64;
    }
    v22 = 6;
    v23 = v17;
    v18 = UFG::UIHK_PDAWidget::mTxtContact.mData;
    if ( (v26 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v25 + 16i64))(v25, &v24, v27);
      v25 = 0i64;
    }
    v26 = 6;
    v27 = v18;
    if ( (v30 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v29 + 16i64))(v29, &v28, v31);
      v29 = 0i64;
    }
    v30 = 6;
    v31 = UFG::UIHK_PDAWidget::mContactImage.mData;
    Scaleform::GFx::Movie::Invoke(v3, "Phone_SetTextMessage", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
    switch ( v2->mState )
    {
      case STATE_ROOT_MENU:
      case STATE_PHONE_CONTACTS:
      case STATE_TEXT_INBOX:
        UFG::UIHK_PDARootMenuWidget::Activate(&v2->RootMenu, v2->mRootIntro, v2->mPreLocked);
        break;
      case STATE_INCOMING_CALL:
      case STATE_OUTGOING_CALL:
        UFG::UIHK_PDAWidget::ShowIncomingPhoneCall(v2);
        if ( v2->mAutoAnsCall )
          UFG::UIHK_PDAWidget::AnswerPhoneCall(v2);
        break;
      case STATE_INCOMING_TEXT:
      case STATE_OUTGOING_TEXT:
        UFG::UIHK_PDAIncomingTextWidget::Activate(
          &v2->IncomingText,
          UFG::UIHK_PDAWidget::mTxtMsg.mData,
          UFG::UIHK_PDAWidget::mTxtContact.mData,
          UFG::UIHK_PDAWidget::mOutgoingTxt,
          UFG::UIHK_PDAWidget::mContactImage.mData);
        break;
      case STATE_DISPLAY_TEXT:
        UFG::UIHK_PDAIncomingTextWidget::DisplayMessage(&v2->IncomingText);
        break;
      case STATE_READING_TEXT:
      case STATE_WAIT_TO_WRITE_TEXT:
      case STATE_WRITING_TEXT:
        break;
      default:
        v2->mState = 0;
        UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
        break;
    }
    `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 0;
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v4);
  }
}

// File Line: 297
// RVA: 0x641060
void __fastcall UFG::UIHK_PDAWidget::update(UFG::UIHK_PDAWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIHK_PDAWidget *v3; // rbx
  UFG::UIScreen *v4; // rdi
  UFG::UIHKPlayerObjective *v5; // rsi
  unsigned __int8 v6; // dl
  float v7; // xmm0_4
  UFG::GameStatTracker *v8; // rax
  UFG::UIHK_PDATextInboxWidget *v9; // rcx
  UFG::ePDAStateEnum v10; // eax
  bool v11; // zf
  bool v12; // zf
  unsigned int v13; // eax

  v3 = this;
  v4 = screen;
  UFG::UIScreenInvokeQueue::Update(&UFG::UIHK_PDAWidget::mScreenInvokeQueue, screen);
  UFG::UIHKPlayerObjectiveManager::UpdatePendingBlips(&UFG::UIHK_PDAWidget::ObjectiveManager);
  if ( !unk_142432920
    || UFG::UIScreenManagerBase::getOverlay(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "MissionRewards") )
  {
    goto LABEL_15;
  }
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
  if ( v3->m_objectiveScrollingInProgress )
  {
    v7 = elapsed + v3->m_objectiveScrollingTimer;
    v3->m_objectiveScrollingTimer = v7;
    if ( v7 > 8.0 )
      v3->m_objectiveScrollingInProgress = 0;
  }
  UFG::UIHK_PDAWidget::ProcessCustomInput(v3, v4, elapsed);
  v8 = UFG::GameStatTracker::Instance();
  if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v8, EnablePDA) && !UFG::UIHK_PDAWidget::mLocked )
  {
    UFG::UIHK_PDARootMenuWidget::Update(&v3->RootMenu, v4, elapsed);
    UFG::UIHK_PDAPhoneContactsWidget::Update(&v3->PhoneContacts, v4, elapsed);
    if ( (unsigned int)(v3->IncomingText.mState - 4) <= 1 )
    {
      if ( !v3->IncomingText.mHelpbarShown && v3->IncomingText.mDisplayTime > 1.0 )
      {
        UFG::UIHK_PDAIncomingTextWidget::DisplayHelpbar(&v3->IncomingText);
        v3->IncomingText.mHelpbarShown = 1;
      }
      v3->IncomingText.mDisplayTime = elapsed + v3->IncomingText.mDisplayTime;
    }
    UFG::UIHK_PDAIncomingCallWidget::Update(&v3->IncomingCall, v4, elapsed);
    v9 = &v3->TextInbox;
    if ( v3->TextInbox.mState == 1 )
    {
      v9->mState = 2;
      UFG::UIHK_PDATextInboxWidget::Flash_Show(v9, v4);
    }
    else if ( v3->TextInbox.mState == 3 )
    {
      v9->mState = 0;
      Scaleform::GFx::Movie::Invoke(v4->mRenderable->m_movie.pObject, "TextInbox_Hide", 0i64, 0i64, 0);
    }
    UFG::UIHK_PDAClockWidget::Update(&v3->Clock, v4);
  }
  if ( v3->mShouldHighlight )
  {
    v3->mShouldHighlight = 0;
    UFG::UIHK_PDAWidget::Flash_UIHighlight_Init(v3, v4);
  }
  if ( v3->mState != v3->mPrevState && UFG::UIHKScreenHud::mInstance )
    UFG::UIHKScreenHud::mInstance->mUpdateStatGamePosition = 1;
  v10 = v3->mState;
  switch ( v10 )
  {
    case 1:
      v11 = v3->RootMenu.mState == 0;
      goto LABEL_46;
    case 2:
      v13 = v3->PhoneContacts.mState;
      if ( v13 <= 2 )
        goto LABEL_42;
      v12 = v13 == 6;
LABEL_41:
      if ( !v12 )
        goto LABEL_49;
LABEL_42:
      UFG::UIHK_PDARootMenuWidget::LeaveSubMenu(&v3->RootMenu, v4);
      v3->mState = 1;
LABEL_48:
      UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
      goto LABEL_49;
    case 3:
      v12 = v3->TextInbox.mState == 0;
      goto LABEL_41;
  }
  if ( (unsigned int)(v10 - 6) > 2 )
    goto LABEL_49;
  v11 = v3->IncomingText.mState == 0;
LABEL_46:
  if ( v11 )
  {
    v3->mState = 0;
    goto LABEL_48;
  }
LABEL_49:
  v3->mPrevState = v3->mState;
}.mState == 0;
LABEL_46:
  if ( v11 )


// File Line: 392
// RVA: 0x62EBB0
bool __fastcall UFG::UIHK_PDAWidget::handleMessage(UFG::UIHK_PDAWidget *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  unsigned int v4; // edi
  UFG::UIHK_PDAWidget *v5; // rbx
  bool result; // al
  UFG::UIHK_PDARootMenuWidget *v7; // rsi
  char *v8; // rdi
  UFG::UIScreenTextureManager *v9; // rax

  v4 = msgId;
  v5 = this;
  if ( msgId == UI_HASH_PDA_CAMERA_DESTROY_20 )
  {
    if ( this->mState )
    {
      UFG::ConversationManager::InterruptPlayerConversations(eInterruptType_PDAHangup, 1, 0i64);
      UFG::UIHK_PDAWidget::DeactivateAll(v5);
      v5->mState = 0;
      UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
    }
LABEL_4:
    result = 1;
  }
  else
  {
    switch ( this->mState )
    {
      case 0:
        if ( msgId == UI_HASH_PDA_PHONE_SUCCESS_20 )
        {
          v7 = &this->RootMenu;
          if ( UFG::UIHK_PDARootMenuWidget::CanActivate(&this->RootMenu) )
          {
            if ( v7->mState == STATE_IDLE )
            {
              *(_QWORD *)&v7->mState = 4i64;
              v5->RootMenu.mRefreshTimer = 0.33333334;
              v5->RootMenu.mLastScrolledPrev = 0;
              v5->RootMenu.mIntroIndex = 0;
              if ( !v5->RootMenu.mInputLocker.mAcquired )
              {
                UFG::SetInputMode_PDA_On(UFG::gActiveControllerNum);
                ++UFG::UIHKGameplayHelpWidget::mLocked;
                ++UFG::UIHK_PDAWidget::mInputLocked;
                v5->RootMenu.mInputLocker.mAcquired = 1;
              }
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(
                  (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                  0xF48906FE,
                  0i64,
                  0,
                  0i64);
            }
            v5->mState = 1;
            UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
          }
        }
        goto LABEL_14;
      case 1:
        if ( msgId == UI_HASH_LIST_OPTION_SELECTED_30 )
        {
          if ( this->RootMenu.mState == 2 )
            this->RootMenu.mState = 6;
          v8 = this->RootMenu.mSelectedItem.mData;
          if ( (unsigned int)UFG::qStringCompare(this->RootMenu.mSelectedItem.mData, "$HUD_SMARTPHONE_CONTACTS", -1) )
          {
            if ( (unsigned int)UFG::qStringCompare(v8, "$HUD_SMARTPHONE_MESSAGES", -1) )
            {
              if ( (unsigned int)UFG::qStringCompare(v8, "$HUD_SMARTPHONE_SOCIALHUB", -1) )
              {
                if ( (unsigned int)UFG::qStringCompare(v8, "$HUD_SMARTPHONE_BIOS", -1) )
                {
LABEL_14:
                  result = 0;
                }
                else
                {
                  unk_142431A14 = 1;
                  if ( UFG::HudAudio::m_instance )
                    UFG::AudioEntity::CreateAndPlayEvent(
                      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                      0x9E75334E,
                      0i64,
                      0,
                      0i64);
                  UFG::UIHKScreenCaseComplete::mCaseType = 4;
                  v9 = UFG::UIScreenTextureManager::Instance();
                  UFG::UIScreenTextureManager::QueueLoadAndPush(v9, "CaseComplete", 0i64);
                  result = 0;
                }
              }
              else
              {
                unk_142431A14 = 1;
                if ( UFG::HudAudio::m_instance )
                  UFG::AudioEntity::CreateAndPlayEvent(
                    (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                    0x9E75334E,
                    0i64,
                    0,
                    0i64);
                UFG::UI::PauseGame("SocialHub");
                result = 0;
              }
            }
            else
            {
              if ( UFG::HudAudio::m_instance )
                UFG::AudioEntity::CreateAndPlayEvent(
                  (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                  0x9E75334E,
                  0i64,
                  0,
                  0i64);
              if ( v5->TextInbox.mState == STATE_IDLE )
                v5->TextInbox.mState = 1;
              v5->mState = 3;
              result = 0;
              UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
            }
          }
          else
          {
            if ( UFG::HudAudio::m_instance )
              UFG::AudioEntity::CreateAndPlayEvent(
                (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
                0x9E75334E,
                0i64,
                0,
                0i64);
            if ( v5->PhoneContacts.mState == STATE_IDLE )
            {
              v5->PhoneContacts.mState = 1;
              UFG::UIHK_PDAPhoneContactsWidget::LoadTexturePack(&v5->PhoneContacts);
            }
            v5->mState = 2;
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
      case 2:
        if ( UFG::UIHK_PDAPhoneContactsWidget::HandleMessage(&this->PhoneContacts, screen, msgId) )
          goto LABEL_4;
        goto $LN4_69;
      case 3:
$LN4_69:
        if ( v4 != UI_HASH_LIST_OPTION_SELECTED_30 )
          goto LABEL_14;
        return 1;
      case 4:
      case 5:
        if ( msgId != UI_HASH_PDA_PHONE_SUCCESS_20 || !this->mAutoAnsCall )
          goto LABEL_14;
        UFG::UIHK_PDAWidget::AnswerPhoneCall(this);
        return 0;
      case 6:
      case 8:
        if ( msgId != UI_HASH_PDA_PHONE_SUCCESS_20 || !UFG::UIHK_PDAWidget::mAutoAnsTxt )
          goto LABEL_14;
        UFG::UIHK_PDAWidget::DisplayTextMessage(this);
        return 0;
      case 0xB:
        if ( msgId != UI_HASH_PDA_PHONE_SUCCESS_20 )
          goto LABEL_14;
        this->mState = 12;
        result = 0;
        UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
        return result;
      default:
        goto LABEL_14;
    }
  }
  return result;
}

// File Line: 532
// RVA: 0x5FE430
void __fastcall UFG::UIHK_PDAWidget::ProcessCustomInput(UFG::UIHK_PDAWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreen *v3; // rdi
  UFG::UIHK_PDAWidget *v4; // rbx
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
  float v19; // xmm3_4
  UFG::InputActionData *v20; // rcx
  char v21; // [rsp+20h] [rbp-48h]
  char v22; // [rsp+21h] [rbp-47h]
  char v23; // [rsp+22h] [rbp-46h]
  char v24; // [rsp+23h] [rbp-45h]
  char v25; // [rsp+78h] [rbp+10h]
  char v26; // [rsp+88h] [rbp+20h]

  v3 = screen;
  v4 = this;
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
      v19 = v17->mAxisPositionY;
    else
      v19 = 0.0;
    v20 = UFG::ActionDef_UILeftThumbstick.mDataPerController[UFG::gActiveControllerNum];
    if ( v20 )
      v18 = v20->mAxisPositionY;
    if ( v18 < -0.2 )
      UFG::UIHK_PDAWidget::HandleCustomInput(v4, screen, UI_HASH_THUMBSTICK_LEFT_UP_30);
    if ( v18 > 0.2 )
      UFG::UIHK_PDAWidget::HandleCustomInput(v4, v3, UI_HASH_THUMBSTICK_LEFT_DOWN_30);
    if ( v19 < -0.2 )
      UFG::UIHK_PDAWidget::HandleCustomInput(v4, v3, UI_HASH_THUMBSTICK_RIGHT_UP_30);
    if ( v19 > 0.2 )
      UFG::UIHK_PDAWidget::HandleCustomInput(v4, v3, UI_HASH_THUMBSTICK_RIGHT_DOWN_30);
    if ( v25 )
      UFG::UIHK_PDAWidget::HandleCustomInput(v4, v3, UI_HASH_DPAD_UP_PRESSED_30);
    if ( v12 )
      UFG::UIHK_PDAWidget::HandleCustomInput(v4, v3, UI_HASH_DPAD_DOWN_PRESSED_30);
    if ( v14 )
      UFG::UIHK_PDAWidget::HandleCustomInput(v4, v3, UI_HASH_DPAD_LEFT_PRESSED_30);
    if ( v16 )
      UFG::UIHK_PDAWidget::HandleCustomInput(v4, v3, UI_HASH_DPAD_RIGHT_PRESSED_30);
    if ( v26 )
      UFG::UIHK_PDAWidget::HandleCustomInput(v4, v3, UI_HASH_BUTTON_ACCEPT_RELEASED_30);
    if ( v21 )
      UFG::UIHK_PDAWidget::HandleCustomInput(v4, v3, UI_HASH_BUTTON_BACK_RELEASED_30);
    if ( v22 )
      UFG::UIHK_PDAWidget::HandleCustomInput(v4, v3, UI_HASH_BUTTON_L1_PRESSED_30);
    if ( v23 )
      UFG::UIHK_PDAWidget::HandleCustomInput(v4, v3, UI_HASH_BUTTON_L3_PRESSED_30);
    if ( v24 )
      UFG::UIHK_PDAWidget::HandleCustomInput(v4, v3, UI_HASH_BUTTON_R1_PRESSED_30);
    if ( UFG::gEnableWorldMapAndPDA && v23 && UFG::UIHKTweakables::RenderMinimap )
      UFG::UIHK_PDAWidget::DisplayObjective(v4);
  }
}

// File Line: 596
// RVA: 0x5EA850
void __fastcall UFG::UIHK_PDAWidget::HandleCustomInput(UFG::UIHK_PDAWidget *this, UFG::UIScreen *screen, unsigned int msgId)
{
  UFG::ePDAStateEnum v3; // eax
  UFG::UIHK_PDAIncomingCallWidget *v4; // rcx

  v3 = this->mState;
  switch ( v3 )
  {
    case STATE_PHONE_CONTACTS:
      UFG::UIHK_PDAPhoneContactsWidget::ProcessInput(&this->PhoneContacts, screen, msgId);
      break;
    case STATE_TEXT_INBOX:
      UFG::UIHK_PDATextInboxWidget::HandleMessage(&this->TextInbox, screen, msgId);
      break;
    case STATE_INCOMING_CALL:
      v4 = &this->IncomingCall;
      if ( v4->mState == 2 && msgId == UI_HASH_DPAD_UP_PRESSED_30 )
        UFG::UIHK_PDAIncomingCallWidget::Answer(v4);
      break;
    default:
      if ( (unsigned int)(v3 - 6) <= 2 )
        UFG::UIHK_PDAIncomingTextWidget::HandleMessage(&this->IncomingText, screen, msgId);
      break;
  }
}

// File Line: 649
// RVA: 0x5F1C70
void UFG::UIHK_PDAWidget::Lock(void)
{
  UFG::UIHK_PDAWidget *v0; // rbx

  if ( UFG::UIHKScreenHud::mInstance )
  {
    v0 = UFG::UIHKScreenHud::mInstance->PDA;
    if ( v0 )
    {
      UFG::UIHK_PDAWidget::ForceIdle(v0);
      v0->mState = 0;
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
  return this->IncomingCall.mState == 4;
}

// File Line: 749
// RVA: 0x5FE9C0
char __fastcall UFG::UIHK_PDAWidget::QueueIncomingPhoneCall(UFG::UIHK_PDAWidget *this, const char *contactName, bool outgoing, bool autoCall, bool voiceMail)
{
  bool v5; // bl
  UFG::UIHK_PDAWidget *v6; // rsi
  const char *v7; // r14
  bool v8; // r12
  const char *v9; // rdi
  unsigned int v10; // edx
  UFG::qSymbol *v11; // rax
  UFG::qPropertySet *v12; // rax
  UFG::qPropertyList *v13; // rax
  UFG::qPropertyList *v14; // r13
  unsigned int v15; // er15
  unsigned int v16; // ebp
  char *v17; // rax
  UFG::qPropertySet *v18; // rbx
  char *v19; // rax
  char *v20; // rax
  unsigned int v21; // eax
  UFG::UIGfxTranslator *v22; // rcx
  bool v23; // al
  bool v25; // [rsp+80h] [rbp+18h]
  UFG::qSymbol result; // [rsp+88h] [rbp+20h]

  v25 = outgoing;
  v5 = outgoing;
  v6 = this;
  v7 = contactName;
  v8 = autoCall;
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
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v10, 0i64, 0, 0i64);
    goto LABEL_7;
  }
LABEL_7:
  UFG::qString::Set(&UFG::UIHK_PDAWidget::mContactImage, "Portrait_Smartphone_Unknown");
  v11 = UFG::qSymbol::create_from_string(&result, "default-unlockables-contactList-list");
  v12 = UFG::PropertySetManager::GetPropertySet(v11);
  v6->mContactData = v12;
  v13 = UFG::qPropertySet::Get<UFG::qPropertyList>(v12, (UFG::qSymbol *)&qSymbol_List_20.mUID, DEPTH_RECURSE);
  v14 = v13;
  if ( v13 )
  {
    v15 = v13->mNumElements;
    v16 = 0;
    if ( v15 )
    {
      do
      {
        v17 = UFG::qPropertyList::GetValuePtr(v14, 0x1Au, v16);
        if ( !v17 || (v18 = (UFG::qPropertySet *)&v17[*(_QWORD *)v17], !*(_QWORD *)v17) )
          v18 = 0i64;
        v19 = PropertyUtils::Get<char const *>(v18, (UFG::qSymbol *)&qSymbol_Name_20.mUID, DEPTH_RECURSE);
        UFG::qString::Set(&UFG::UIHK_PDAWidget::mContactID, v19);
        if ( UFG::qString::operator==(&UFG::UIHK_PDAWidget::mContactID, v7) )
        {
          v20 = PropertyUtils::Get<char const *>(v18, (UFG::qSymbol *)&qSymbol_Portrait_20.mUID, DEPTH_RECURSE);
          UFG::qString::Set(&UFG::UIHK_PDAWidget::mContactImage, v20);
        }
        ++v16;
      }
      while ( v16 < v15 );
      v5 = v25;
    }
  }
  if ( v7 )
  {
    if ( *v7 == 36 )
      ++v7;
    v21 = UFG::qStringHashUpper32(v7, 0xFFFFFFFF);
    v22 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v22
      || (v9 = (const char *)v22->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v22->vfptr, v21)) == 0i64 )
    {
      v9 = v7;
    }
  }
  UFG::qString::Set(&v6->mPhoneContact, v9);
  v23 = voiceMail;
  v6->mOutgoingCall = v5;
  v6->mAutoAnsCall = v8;
  v6->mVoiceMail = v23;
  UFG::UIHK_PDAWidget::ForceIdle(v6);
  if ( v6->mOutgoingCall )
    v6->mState = 5;
  else
    v6->mState = 4;
  UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  UFG::UIHK_PDAIncomingCallWidget::Activate(
    &v6->IncomingCall,
    v6->mPhoneContact.mData,
    UFG::UIHK_PDAWidget::mContactImage.mData,
    v6->mOutgoingCall,
    v6->mVoiceMail);
  return 1;
}

// File Line: 789
// RVA: 0x610890
void __fastcall UFG::UIHK_PDAWidget::ShowIncomingPhoneCall(UFG::UIHK_PDAWidget *this)
{
  UFG::UIHK_PDAWidget *v1; // rbx

  v1 = this;
  UFG::UIHK_PDAWidget::ForceIdle(this);
  if ( v1->mOutgoingCall )
    v1->mState = 5;
  else
    v1->mState = 4;
  UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  UFG::UIHK_PDAIncomingCallWidget::Activate(
    &v1->IncomingCall,
    v1->mPhoneContact.mData,
    UFG::UIHK_PDAWidget::mContactImage.mData,
    v1->mOutgoingCall,
    v1->mVoiceMail);
}

// File Line: 804
// RVA: 0x5D3B10
char __fastcall UFG::UIHK_PDAWidget::AnswerPhoneCall(UFG::UIHK_PDAWidget *this)
{
  UFG::UIHK_PDAWidget *v1; // rdi

  v1 = this;
  UFG::UIHK_PDAIncomingCallWidget::SetCallerName(
    &this->IncomingCall,
    this->mPhoneContact.mData,
    UFG::UIHK_PDAWidget::mContactImage.mData,
    this->mVoiceMail);
  UFG::UIHK_PDAIncomingCallWidget::Answer(&v1->IncomingCall);
  v1->mState = STATE_INCOMING_CALL;
  UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  UFG::ConversationManager::ResumePlayerConversations(eInterruptType_PDAHangup);
  return 1;
}

// File Line: 814
// RVA: 0x5D7150
char __fastcall UFG::UIHK_PDAWidget::EndPhoneCall(UFG::UIHK_PDAWidget *this, bool playSound)
{
  bool v2; // si
  UFG::UIHK_PDAWidget *v3; // rdi
  char result; // al

  v2 = playSound;
  v3 = this;
  if ( (unsigned int)(this->mState - 4) > 1 )
    return 0;
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xD92517u,
      0i64,
      0,
      0i64);
  if ( v3->IncomingCall.mState )
  {
    UFG::UIHK_PDAIncomingCallWidget::HangUp(&v3->IncomingCall, v2);
    v3->IncomingCall.mUpdateTimer = 0;
  }
  UFG::UIHK_PDAIncomingCallWidget::ReleaseInputLock(&v3->IncomingCall, "Deactivate");
  UFG::UIHK_PDARootMenuWidget::Deactivate(&v3->RootMenu);
  v3->mState = 0;
  result = 1;
  UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  return result;
}

// File Line: 827
// RVA: 0x5FEC40
char __fastcall UFG::UIHK_PDAWidget::QueueIncomingTextMessage(UFG::UIHK_PDAWidget *this, const char *contactName, const char *message, const char *portrait, bool outgoing, bool autoAnswer)
{
  UFG::UIHK_PDAWidget *v6; // rsi
  const char *v7; // rdi
  const char *v8; // rbx

  v6 = this;
  v7 = portrait;
  v8 = message;
  UFG::qString::Set(&UFG::UIHK_PDAWidget::mTxtContact, contactName);
  UFG::qString::Set(&UFG::UIHK_PDAWidget::mTxtMsg, v8);
  UFG::UIHK_PDAWidget::mOutgoingTxt = outgoing;
  UFG::UIHK_PDAWidget::mAutoAnsTxt = autoAnswer;
  UFG::qString::Set(&UFG::UIHK_PDAWidget::mContactImage, v7);
  UFG::UIHK_PDAWidget::ShowIncomingTextMessage(v6);
  return 1;
}

// File Line: 840
// RVA: 0x612190
char __fastcall UFG::UIHK_PDAWidget::StartReadingText(UFG::UIHK_PDAWidget *this)
{
  char result; // al

  if ( this->mState )
    return 0;
  this->mState = 10;
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
  this->mState = 11;
  result = 1;
  UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  return result;
}

// File Line: 864
// RVA: 0x610900
void __fastcall UFG::UIHK_PDAWidget::ShowIncomingTextMessage(UFG::UIHK_PDAWidget *this)
{
  UFG::UIHK_PDAWidget *v1; // rbx
  signed int v2; // eax
  unsigned int v3; // edx

  v1 = this;
  UFG::UIHK_PDAWidget::ForceIdle(this);
  v2 = 6;
  if ( UFG::UIHK_PDAWidget::mOutgoingTxt )
    v2 = 8;
  v1->mState = v2;
  UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  UFG::UIHK_PDAIncomingTextWidget::Activate(
    &v1->IncomingText,
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
  UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v3, 0i64, 0, 0i64);
}

// File Line: 881
// RVA: 0x5D6EB0
void __fastcall UFG::UIHK_PDAWidget::DisplayTextMessage(UFG::UIHK_PDAWidget *this)
{
  UFG::UIHK_PDAWidget *v1; // rbx

  v1 = this;
  if ( this->mState == 2 && this->PhoneContacts.mState )
    this->PhoneContacts.mState = 6;
  if ( !UFG::UIHK_PDAWidget::mLocked )
  {
    UFG::UIHK_PDAIncomingTextWidget::DisplayMessage(&this->IncomingText);
    v1->mState = 7;
    UFG::UIHKObjectiveFlasherWidget::mPDAStateChanged = 1;
  }
}

// File Line: 896
// RVA: 0x5D6640
char __fastcall UFG::UIHK_PDAWidget::DismissTextMessage(UFG::UIHK_PDAWidget *this, UFG::UIHK_PDAIncomingTextWidget::eDismissCause dismissCause)
{
  if ( (this->mState - 6) & 0xFFFFFFFD )
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
  UFG::UIHK_PDAWidget *v1; // rbx
  UFG::UIHK_PDARootMenuWidget *v2; // rcx
  unsigned int v3; // eax
  int v4; // eax

  v1 = this;
  v2 = &this->RootMenu;
  if ( v2->mState )
    UFG::UIHK_PDARootMenuWidget::Deactivate(v2);
  v3 = v1->PhoneContacts.mState;
  if ( v3 > STATE_PHONE_CONTACTS && v3 != STATE_INCOMING_TEXT )
    v1->PhoneContacts.mState = STATE_INCOMING_TEXT;
  if ( v1->TextInbox.mState )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x4AAC5E6Bu,
        0i64,
        0,
        0i64);
    v1->TextInbox.mState = 3;
  }
  if ( v1->IncomingCall.mState )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xD92517u,
        0i64,
        0,
        0i64);
    if ( v1->IncomingCall.mState )
    {
      UFG::UIHK_PDAIncomingCallWidget::HangUp(&v1->IncomingCall, 1);
      v1->IncomingCall.mUpdateTimer = 0;
    }
    UFG::UIHK_PDAIncomingCallWidget::ReleaseInputLock(&v1->IncomingCall, "Deactivate");
  }
  if ( v1->IncomingText.mState )
  {
    UFG::UIHK_PDAIncomingTextWidget::DismissMessage(&v1->IncomingText, DISMISS_CAUSE_DEACTIVATE);
    if ( v1->IncomingText.mInputLocker.mAcquired )
    {
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
      v1->IncomingText.mInputLocker.mAcquired = 0;
    }
  }
}

// File Line: 982
// RVA: 0x5E6510
void __fastcall UFG::UIHK_PDAWidget::ForceIdle(UFG::UIHK_PDAWidget *this)
{
  UFG::UIHK_PDAWidget *v1; // rbx
  Scaleform::GFx::Movie *v2; // rcx
  int v3; // eax
  UFG::UIScreenTextureManager *v4; // rax
  int v5; // eax

  v1 = this;
  v2 = UFG::UIHKScreenHud::mInstance->mRenderable->m_movie.pObject;
  if ( v2 )
    Scaleform::GFx::Movie::Invoke(v2, "Smartphone_HideAll", 0i64, 0i64, 0);
  v1->RootMenu.mState = 0;
  if ( !unk_142431A14 && v1->RootMenu.mInputLocker.mAcquired )
  {
    if ( UFG::UIHK_PDAWidget::mInputLocked > 0 )
    {
      UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
      v3 = UFG::UIHKGameplayHelpWidget::mLocked;
      if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
        v3 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
      if ( v3 < 1 )
        UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
      --UFG::UIHK_PDAWidget::mInputLocked;
    }
    v1->RootMenu.mInputLocker.mAcquired = 0;
  }
  v1->PhoneContacts.mState = 0;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v4, UFG::UIHK_PDAPhoneContactsWidget::gTexturePackFilename);
  v1->TextInbox.mState = 0;
  v1->IncomingCall.mState = 0;
  UFG::UIHK_PDAIncomingCallWidget::ReleaseInputLock(&v1->IncomingCall, "ForceIdle");
  v1->IncomingText.mState = 0;
  if ( v1->IncomingText.mInputLocker.mAcquired )
  {
    if ( UFG::UIHK_PDAWidget::mInputLocked > 0 )
    {
      UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
      v5 = UFG::UIHKGameplayHelpWidget::mLocked;
      if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
        v5 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
      if ( v5 < 1 )
        UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
      --UFG::UIHK_PDAWidget::mInputLocked;
    }
    v1->IncomingText.mInputLocker.mAcquired = 0;
  }
}

// File Line: 993
// RVA: 0x5D6A80
void __fastcall UFG::UIHK_PDAWidget::DisplayObjective(UFG::UIHK_PDAWidget *this)
{
  UFG::UIHK_PDAWidget *v1; // rbx
  char v2; // r10
  UFG::UIHKPlayerObjective *v3; // rax
  char v4; // dl
  unsigned int v5; // er8
  unsigned __int8 v6; // r9
  UFG::Objective *v7; // rcx
  const char *v8; // rcx
  unsigned __int8 v9; // cl
  UFG::UIHKPlayerObjective *v10; // rdx

  v1 = this;
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
  v7 = v3->mObjective;
  if ( v7 )
    v8 = v7->mCaption.mData;
  else
    v8 = v3->alternateCaption.mData;
  if ( (signed int)UFG::qStringLength(v8) >= 1 )
  {
    v4 = unk_1424329EA;
    v2 = unk_1424329E8;
    v5 = unk_142432878;
    goto LABEL_19;
  }
LABEL_27:
  UFG::UIHKPlayerObjectiveManager::ScrollNextObjective(&UFG::UIHK_PDAWidget::ObjectiveManager);
LABEL_28:
  v1->m_objectiveScrollingTimer = 0.0;
  v1->m_objectiveScrollingInProgress = 1;
}

// File Line: 1023
// RVA: 0x5E5540
void __fastcall UFG::UIHK_PDAWidget::Flash_UIHighlight_Init(UFG::UIHK_PDAWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rbx
  char ptr; // [rsp+40h] [rbp-68h]
  __int64 v4; // [rsp+50h] [rbp-58h]
  unsigned int v5; // [rsp+58h] [rbp-50h]
  const char *v6; // [rsp+60h] [rbp-48h]
  char v7; // [rsp+70h] [rbp-38h]
  __int64 v8; // [rsp+80h] [rbp-28h]
  unsigned int v9; // [rsp+88h] [rbp-20h]
  const char *v10; // [rsp+90h] [rbp-18h]

  v2 = screen->mRenderable->m_movie.pObject;
  if ( v2 )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v5 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v4 + 16i64))(v4, &ptr, v6);
      v4 = 0i64;
    }
    v5 = 6;
    v6 = "mc_Minimap";
    if ( (v9 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v8 + 16i64))(v8, &v7, v10);
      v8 = 0i64;
    }
    v9 = 6;
    v10 = "mc_CircleMenu_highlight";
    Scaleform::GFx::Movie::Invoke(v2, "UIHighlight_Init", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

