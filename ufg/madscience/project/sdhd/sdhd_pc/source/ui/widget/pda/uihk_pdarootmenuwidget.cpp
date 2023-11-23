// File Line: 49
// RVA: 0x5CDE20
void __fastcall UFG::UIHK_PDARootMenuWidget::~UIHK_PDARootMenuWidget(UFG::UIHK_PDARootMenuWidget *this)
{
  UFG::UIHK_PDARootMenuWidget::Deactivate(this);
  UFG::qString::~qString(&this->mInputLocker.mOwner);
  UFG::qString::~qString(&this->mSelectedItem);
}

// File Line: 60
// RVA: 0x619960
void __fastcall UFG::UIHK_PDARootMenuWidget::Update(
        UFG::UIHK_PDARootMenuWidget *this,
        UFG::UIScreen *screen,
        float elapsed)
{
  UFG::UIHK_PDARootMenuWidget::eState mState; // eax
  UFG::InputActionData *v6; // rcx
  UFG::UIScreenTextureManager *v7; // rax
  float v8; // xmm0_4

  mState = this->mState;
  if ( this->mState > STATE_IDLE )
  {
    if ( mState <= STATE_PHONE_CONTACTS )
    {
      UFG::UIHK_PDARootMenuWidget::Flash_Refresh(this, screen);
      v6 = UFG::ActionDef_Raw_Focus.mDataPerController[UFG::gActiveControllerNum];
      if ( v6 && v6->mActionTrue && UFG::UIHK_PDARootMenuWidget::CanUseCamera(this) )
      {
        v7 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::QueueLoadAndPush(v7, "Camera", 0i64);
      }
    }
    else
    {
      switch ( mState )
      {
        case STATE_INCOMING_CALL:
          this->mState = STATE_ROOT_MENU;
          UFG::UIHK_PDARootMenuWidget::Flash_Show(this, screen);
          UFG::UIHK_PDARootMenuWidget::Flash_GetSelected(this, screen);
          break;
        case STATE_OUTGOING_CALL:
          UFG::UIHK_PDARootMenuWidget::Flash_Hide(this, screen);
          this->mState = STATE_IDLE;
          break;
        case STATE_INCOMING_TEXT:
          UFG::UIHK_PDARootMenuWidget::Flash_EnterSubmenu(this, screen);
          this->mState = STATE_TEXT_INBOX;
          break;
      }
    }
  }
  v8 = this->mRefreshTimer - elapsed;
  if ( v8 <= 0.0 )
    this->mRefreshTimer = 0.0;
  else
    this->mRefreshTimer = v8;
}

// File Line: 106
// RVA: 0x5EB3C0
void __fastcall UFG::UIHK_PDARootMenuWidget::HandleMessage(
        UFG::UIHK_PDARootMenuWidget *this,
        UFG::UIScreen *screen,
        unsigned int msgId)
{
  UFG::UIHK_PDAWidget *PDA; // rcx

  if ( this->mState == STATE_ROOT_MENU )
  {
    if ( msgId == UI_HASH_PDA_INTRO_20 )
      this->mState = STATE_PHONE_CONTACTS;
  }
  else if ( this->mState == STATE_PHONE_CONTACTS )
  {
    if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
      || msgId == UI_HASH_DPAD_UP_REPEAT_30
      || msgId == UI_HASH_DPAD_LEFT_PRESSED_30
      || msgId == UI_HASH_DPAD_LEFT_REPEAT_30 )
    {
      UFG::UIHK_PDARootMenuWidget::ScrollPrev(this, screen);
    }
    else if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30
           || msgId == UI_HASH_DPAD_DOWN_REPEAT_30
           || msgId == UI_HASH_DPAD_RIGHT_PRESSED_30
           || msgId == UI_HASH_DPAD_RIGHT_REPEAT_30 )
    {
      UFG::UIHK_PDARootMenuWidget::ScrollNext(this, screen);
    }
    else if ( msgId == UI_HASH_BUTTON_ACCEPT_RELEASED_30 )
    {
      if ( UFG::UIHKScreenHud::mInstance )
        PDA = UFG::UIHKScreenHud::mInstance->PDA;
      else
        PDA = 0i64;
      PDA->vfptr->handleMessage(PDA, screen, UI_HASH_LIST_OPTION_SELECTED_30, 0i64);
    }
    else if ( msgId == UI_HASH_BUTTON_BACK_RELEASED_30 )
    {
      UFG::UIHK_PDARootMenuWidget::Deactivate(this);
    }
  }
}

// File Line: 146
// RVA: 0x5D47F0
bool __fastcall UFG::UIHK_PDARootMenuWidget::CanActivate(UFG::UIHK_PDARootMenuWidget *this)
{
  bool result; // al
  __int64 v2; // rcx
  UFG::InputActionData *v3; // rax
  UFG::InputActionData *v4; // rax

  result = 0;
  if ( !UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "PhoneSignalMinigame") )
  {
    v2 = (int)UFG::gActiveControllerNum;
    v3 = UFG::ActionDef_UILeftRepeat.mDataPerController[v2];
    if ( !v3 || !v3->mActionTrue )
    {
      v4 = UFG::ActionDef_UIRightRepeat.mDataPerController[v2];
      if ( !v4 || !v4->mActionTrue )
        return 1;
    }
  }
  return result;
}

// File Line: 162
// RVA: 0x5D1850
void __fastcall UFG::UIHK_PDARootMenuWidget::Activate(
        UFG::UIHK_PDARootMenuWidget *this,
        unsigned int introIndex,
        bool preLocked)
{
  if ( this->mState == STATE_IDLE )
  {
    *(_QWORD *)&this->mState = 4i64;
    this->mRefreshTimer = 0.33333334;
    this->mLastScrolledPrev = 0;
    this->mIntroIndex = introIndex;
    if ( preLocked )
    {
      if ( !this->mInputLocker.mAcquired )
        this->mInputLocker.mAcquired = 1;
    }
    else if ( !this->mInputLocker.mAcquired )
    {
      UFG::SetInputMode_PDA_On(UFG::gActiveControllerNum);
      ++UFG::UIHKGameplayHelpWidget::mLocked;
      ++UFG::UIHK_PDAWidget::mInputLocked;
      this->mInputLocker.mAcquired = 1;
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xF48906FE, 0i64, 0, 0i64);
  }
}

// File Line: 177
// RVA: 0x5D5FB0
void __fastcall UFG::UIHK_PDARootMenuWidget::Deactivate(UFG::UIHK_PDARootMenuWidget *this)
{
  int v2; // eax

  if ( this->mState )
  {
    this->mState = STATE_OUTGOING_CALL;
    if ( !byte_142431A14 && this->mInputLocker.mAcquired )
    {
      if ( UFG::UIHK_PDAWidget::mInputLocked )
      {
        UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
        v2 = UFG::UIHKGameplayHelpWidget::mLocked;
        if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
          v2 = --UFG::UIHKGameplayHelpWidget::mLocked;
        if ( v2 < 1 )
          UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
        --UFG::UIHK_PDAWidget::mInputLocked;
      }
      this->mInputLocker.mAcquired = 0;
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x374BF97Au, 0i64, 0, 0i64);
  }
}

// File Line: 194
// RVA: 0x5D48F0
bool __fastcall UFG::UIHK_PDARootMenuWidget::CanUseCamera(UFG::UIHK_PDARootMenuWidget *this)
{
  UFG::UIHK_PDAWidget *v2; // rdx
  bool result; // al

  result = 0;
  if ( UFG::PhotoManager::HasPhotoTarget() )
  {
    v2 = UFG::UIHKScreenHud::mInstance ? UFG::UIHKScreenHud::mInstance->PDA : 0i64;
    if ( v2->IncomingCall.mState != STATE_INCOMING_CALL && !UFG::UIHK_PDARootMenuWidget::IsInVehicle(this) )
      return 1;
  }
  return result;
}

// File Line: 206
// RVA: 0x5EE2A0
bool __fastcall UFG::UIHK_PDARootMenuWidget::IsInVehicle(UFG::UIHK_PDARootMenuWidget *this)
{
  signed __int16 m_Flags; // dx
  unsigned int v3; // edx
  bool v4; // zf

  if ( !LocalPlayer )
    return 0;
  m_Flags = LocalPlayer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return LocalPlayer->m_Components.p[44].m_pComponent != 0i64;
  if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
  {
    v3 = UFG::CharacterOccupantComponent::_TypeUID;
    return UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, v3) != 0i64;
  }
  v4 = (m_Flags & 0x1000) == 0;
  v3 = UFG::CharacterOccupantComponent::_TypeUID;
  if ( !v4 )
    return UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, v3) != 0i64;
  return UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::CharacterOccupantComponent::_TypeUID) != 0i64;
}

// File Line: 223
// RVA: 0x5F09B0
void __fastcall UFG::UIHK_PDARootMenuWidget::LeaveSubMenu(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx

  if ( this->mState == STATE_TEXT_INBOX )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
      Scaleform::GFx::Movie::Invoke(pObject, "Smartphone_ShowMenu", 0i64, 0i64, 0);
    this->mState = STATE_PHONE_CONTACTS;
  }
}

// File Line: 247
// RVA: 0x603FC0
void __fastcall UFG::UIHK_PDARootMenuWidget::ScrollNext(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx

  if ( this->mState == STATE_PHONE_CONTACTS )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      Scaleform::GFx::Movie::Invoke(pObject, "Smartphone_ScrollNext", 0i64, 0i64, 0);
      this->mIdleTime = 0.0;
      this->mLastScrolledPrev = 0;
      UFG::UIHK_PDARootMenuWidget::Flash_GetSelected(this, screen);
      UFG::UIHK_PDARootMenuWidget::PlayPdaClick(this);
    }
  }
}

// File Line: 265
// RVA: 0x604310
void __fastcall UFG::UIHK_PDARootMenuWidget::ScrollPrev(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx

  if ( this->mState == STATE_PHONE_CONTACTS )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      Scaleform::GFx::Movie::Invoke(pObject, "Smartphone_ScrollPrev", 0i64, 0i64, 0);
      this->mIdleTime = 0.0;
      this->mLastScrolledPrev = 1;
      UFG::UIHK_PDARootMenuWidget::Flash_GetSelected(this, screen);
      UFG::UIHK_PDARootMenuWidget::PlayPdaClick(this);
    }
  }
}

// File Line: 315
// RVA: 0x5E39B0
void __fastcall UFG::UIHK_PDARootMenuWidget::Flash_Show(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value::ValueUnion v4; // xmm6_8
  Scaleform::GFx::Value ptr; // [rsp+38h] [rbp-50h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    UFG::UIHK_PDARootMenuWidget::Flash_SetGlobals(this, screen);
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v4.NValue = (double)(int)this->mIntroIndex;
    if ( (ptr.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
        ptr.pObjectInterface,
        &ptr,
        ptr.mValue);
      ptr.pObjectInterface = 0i64;
    }
    ptr.Type = VT_Number;
    ptr.mValue = v4;
    Scaleform::GFx::Movie::Invoke(pObject, "Smartphone_AnimateIntro", 0i64, &ptr, 1u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 329
// RVA: 0x5DBA40
void __fastcall UFG::UIHK_PDARootMenuWidget::Flash_Hide(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "Smartphone_HideMenu", 0i64, 0i64, 0);
}

// File Line: 339
// RVA: 0x5DA860
void __fastcall UFG::UIHK_PDARootMenuWidget::Flash_EnterSubmenu(
        UFG::UIHK_PDARootMenuWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rcx

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
    Scaleform::GFx::Movie::Invoke(pObject, "Smartphone_EnterSubmenu", 0i64, 0i64, 0);
}

// File Line: 359
// RVA: 0x5DAC70
void __fastcall UFG::UIHK_PDARootMenuWidget::Flash_GetSelected(
        UFG::UIHK_PDARootMenuWidget *this,
        UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  const char *pString; // rdx
  Scaleform::GFx::Value presult; // [rsp+38h] [rbp-40h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    presult.pObjectInterface = 0i64;
    presult.Type = VT_Undefined;
    Scaleform::GFx::Movie::Invoke(pObject, "Smartphone_GetSelectedIndex", &presult, 0i64, 0);
    this->mSelectedIndex = (int)presult.mValue.NValue;
    Scaleform::GFx::Movie::Invoke(pObject, "Smartphone_GetSelectedItem", &presult, 0i64, 0);
    if ( (presult.Type & 0x40) != 0 )
      pString = *presult.mValue.pStringManaged;
    else
      pString = presult.mValue.pString;
    UFG::qString::Set(&this->mSelectedItem, pString);
    if ( (presult.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&presult.pObjectInterface->vfptr->gap8[8])(
        presult.pObjectInterface,
        &presult,
        presult.mValue);
  }
}

// File Line: 373
// RVA: 0x5DEA00
void __fastcall UFG::UIHK_PDARootMenuWidget::Flash_Refresh(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rdi

  if ( this->mRefreshTimer <= 0.0 )
  {
    pObject = screen->mRenderable->m_movie.pObject;
    if ( pObject )
    {
      UFG::UIHK_PDARootMenuWidget::Flash_SetGlobals(this, screen);
      Scaleform::GFx::Movie::Invoke(pObject, "Smartphone_Refresh", 0i64, 0i64, 0);
      this->mRefreshTimer = 0.33333334;
    }
  }
}

// File Line: 388
// RVA: 0x5E0020
void __fastcall UFG::UIHK_PDARootMenuWidget::Flash_SetGlobals(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *pObject; // rbx
  UFG::UIHK_PDAWidget *PDA; // rcx
  bool v5; // al
  bool v6; // di
  UFG::GameStatTracker *v7; // rax
  bool Stat; // di
  bool m_bHasNewChallengeMessage; // di
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-38h] BYREF

  pObject = screen->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Undefined;
    if ( !UFG::PhotoManager::HasPhotoTarget()
      || (!UFG::UIHKScreenHud::mInstance ? (PDA = 0i64) : (PDA = UFG::UIHKScreenHud::mInstance->PDA),
          PDA->IncomingCall.mState == STATE_INCOMING_CALL
       || (v5 = UFG::UIHK_PDARootMenuWidget::IsInVehicle(this), v6 = 1, v5)) )
    {
      v6 = 0;
    }
    value.Type = VT_Boolean;
    value.mValue.BValue = v6;
    Scaleform::GFx::Movie::SetVariable(pObject, "gCameraAvailable", &value, 1i64);
    v7 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v7, Collectible_Bio_New);
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Boolean;
    value.mValue.BValue = Stat;
    Scaleform::GFx::Movie::SetVariable(pObject, "gBiosAlert", &value, 1i64);
    m_bHasNewChallengeMessage = UFG::SocialLogDataManager::Instance()->m_bHasNewChallengeMessage;
    if ( (value.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = VT_Boolean;
    value.mValue.BValue = m_bHasNewChallengeMessage;
    Scaleform::GFx::Movie::SetVariable(pObject, "gSocialHubAlert", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

// File Line: 404
// RVA: 0x5F4090
void __fastcall UFG::UIHK_PDARootMenuWidget::PlayPdaClick(UFG::UIHK_PDARootMenuWidget *this)
{
  unsigned int v1; // eax

  if ( (_S39_1 & 1) != 0 )
  {
    v1 = play_pda_click;
  }
  else
  {
    _S39_1 |= 1u;
    v1 = UFG::TiDo::CalcWwiseUid("play_pda_click");
    play_pda_click = v1;
  }
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, v1, 0i64, 0, 0i64);
}

