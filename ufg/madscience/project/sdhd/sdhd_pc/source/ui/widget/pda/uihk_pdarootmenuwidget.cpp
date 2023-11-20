// File Line: 49
// RVA: 0x5CDE20
void __fastcall UFG::UIHK_PDARootMenuWidget::~UIHK_PDARootMenuWidget(UFG::UIHK_PDARootMenuWidget *this)
{
  UFG::UIHK_PDARootMenuWidget *v1; // rbx

  v1 = this;
  UFG::UIHK_PDARootMenuWidget::Deactivate(this);
  UFG::qString::~qString(&v1->mInputLocker.mOwner);
  UFG::qString::~qString(&v1->mSelectedItem);
}

// File Line: 60
// RVA: 0x619960
void __fastcall UFG::UIHK_PDARootMenuWidget::Update(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIHK_PDARootMenuWidget::eState v3; // eax
  UFG::UIScreen *v4; // rdi
  UFG::UIHK_PDARootMenuWidget *v5; // rbx
  UFG::InputActionData *v6; // rcx
  UFG::UIScreenTextureManager *v7; // rax
  float v8; // xmm0_4

  v3 = this->mState;
  v4 = screen;
  v5 = this;
  if ( this->mState > 0 )
  {
    if ( (signed int)v3 <= 2 )
    {
      UFG::UIHK_PDARootMenuWidget::Flash_Refresh(this, screen);
      v6 = UFG::ActionDef_Raw_Focus.mDataPerController[UFG::gActiveControllerNum];
      if ( v6 && v6->mActionTrue && UFG::UIHK_PDARootMenuWidget::CanUseCamera(v5) )
      {
        v7 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::QueueLoadAndPush(v7, "Camera", 0i64);
      }
    }
    else
    {
      switch ( v3 )
      {
        case 4:
          this->mState = 1;
          UFG::UIHK_PDARootMenuWidget::Flash_Show(this, screen);
          UFG::UIHK_PDARootMenuWidget::Flash_GetSelected(v5, v4);
          break;
        case 5:
          UFG::UIHK_PDARootMenuWidget::Flash_Hide(this, screen);
          v5->mState = 0;
          break;
        case 6:
          UFG::UIHK_PDARootMenuWidget::Flash_EnterSubmenu(this, screen);
          v5->mState = 3;
          break;
      }
    }
  }
  v8 = v5->mRefreshTimer - elapsed;
  if ( v8 <= 0.0 )
    v5->mRefreshTimer = 0.0;
  else
    v5->mRefreshTimer = v8;
}

// File Line: 106
// RVA: 0x5EB3C0
void __fastcall UFG::UIHK_PDARootMenuWidget::HandleMessage(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen, unsigned int msgId)
{
  UFG::UIHK_PDAWidget *v3; // rcx

  if ( this->mState == 1 )
  {
    if ( msgId == UI_HASH_PDA_INTRO_20 )
      this->mState = 2;
  }
  else if ( this->mState == 2 )
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
        v3 = UFG::UIHKScreenHud::mInstance->PDA;
      else
        v3 = 0i64;
      v3->vfptr->handleMessage(v3, screen, UI_HASH_LIST_OPTION_SELECTED_30, 0i64);
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
  UFG::InputActionData *v2; // rax
  UFG::InputActionData *v3; // rax

  result = 0;
  if ( !UFG::UIScreenManagerBase::getOverlay(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "PhoneSignalMinigame") )
  {
    v2 = UFG::ActionDef_UILeftRepeat.mDataPerController[UFG::gActiveControllerNum];
    if ( !v2 || !v2->mActionTrue )
    {
      v3 = UFG::ActionDef_UIRightRepeat.mDataPerController[UFG::gActiveControllerNum];
      if ( !v3 || !v3->mActionTrue )
        result = 1;
    }
  }
  return result;
}

// File Line: 162
// RVA: 0x5D1850
void __fastcall UFG::UIHK_PDARootMenuWidget::Activate(UFG::UIHK_PDARootMenuWidget *this, unsigned int introIndex, bool preLocked)
{
  UFG::UIHK_PDARootMenuWidget *v3; // rbx

  v3 = this;
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
      v3->mInputLocker.mAcquired = 1;
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xF48906FE,
        0i64,
        0,
        0i64);
  }
}

// File Line: 177
// RVA: 0x5D5FB0
void __fastcall UFG::UIHK_PDARootMenuWidget::Deactivate(UFG::UIHK_PDARootMenuWidget *this)
{
  UFG::UIHK_PDARootMenuWidget *v1; // rbx
  int v2; // eax

  v1 = this;
  if ( this->mState )
  {
    this->mState = 5;
    if ( !unk_142431A14 && this->mInputLocker.mAcquired )
    {
      if ( UFG::UIHK_PDAWidget::mInputLocked )
      {
        UFG::SetInputMode_PDA_Off(UFG::gActiveControllerNum);
        v2 = UFG::UIHKGameplayHelpWidget::mLocked;
        if ( UFG::UIHKGameplayHelpWidget::mLocked > 0 )
          v2 = UFG::UIHKGameplayHelpWidget::mLocked-- - 1;
        if ( v2 < 1 )
          UFG::UIHKScreenHud::GameplayHelp->mChanged = 1;
        --UFG::UIHK_PDAWidget::mInputLocked;
      }
      v1->mInputLocker.mAcquired = 0;
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x374BF97Au,
        0i64,
        0,
        0i64);
  }
}

// File Line: 194
// RVA: 0x5D48F0
bool __fastcall UFG::UIHK_PDARootMenuWidget::CanUseCamera(UFG::UIHK_PDARootMenuWidget *this)
{
  UFG::UIHK_PDARootMenuWidget *v1; // rbx
  UFG::UIHK_PDAWidget *v2; // rdx
  bool result; // al

  v1 = this;
  result = 0;
  if ( UFG::PhotoManager::HasPhotoTarget() )
  {
    v2 = UFG::UIHKScreenHud::mInstance ? UFG::UIHKScreenHud::mInstance->PDA : 0i64;
    if ( v2->IncomingCall.mState != 4 && !UFG::UIHK_PDARootMenuWidget::IsInVehicle(v1) )
      result = 1;
  }
  return result;
}

// File Line: 206
// RVA: 0x5EE2A0
bool __fastcall UFG::UIHK_PDARootMenuWidget::IsInVehicle(UFG::UIHK_PDARootMenuWidget *this)
{
  _BOOL8 v1; // rax
  unsigned __int16 v2; // dx
  unsigned int v3; // edx
  bool v4; // zf

  if ( LocalPlayer )
  {
    v2 = LocalPlayer->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      LOBYTE(v1) = LocalPlayer->m_Components.p[44].m_pComponent != 0i64;
    }
    else
    {
      if ( (v2 & 0x8000u) != 0 || (v2 >> 13) & 1 )
      {
        v3 = UFG::CharacterOccupantComponent::_TypeUID;
      }
      else
      {
        v4 = ((v2 >> 12) & 1) == 0;
        v3 = UFG::CharacterOccupantComponent::_TypeUID;
        if ( v4 )
          return UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&LocalPlayer->vfptr,
                   UFG::CharacterOccupantComponent::_TypeUID) != 0i64;
      }
      v1 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, v3) != 0i64;
    }
  }
  else
  {
    LOBYTE(v1) = 0;
  }
  return v1;
}

// File Line: 223
// RVA: 0x5F09B0
void __fastcall UFG::UIHK_PDARootMenuWidget::LeaveSubMenu(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHK_PDARootMenuWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // rcx

  v2 = this;
  if ( this->mState == 3 )
  {
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
      Scaleform::GFx::Movie::Invoke(v3, "Smartphone_ShowMenu", 0i64, 0i64, 0);
    v2->mState = 2;
  }
}

// File Line: 247
// RVA: 0x603FC0
void __fastcall UFG::UIHK_PDARootMenuWidget::ScrollNext(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rdi
  UFG::UIHK_PDARootMenuWidget *v3; // rbx
  Scaleform::GFx::Movie *v4; // rcx

  v2 = screen;
  v3 = this;
  if ( this->mState == 2 )
  {
    v4 = screen->mRenderable->m_movie.pObject;
    if ( v4 )
    {
      Scaleform::GFx::Movie::Invoke(v4, "Smartphone_ScrollNext", 0i64, 0i64, 0);
      v3->mIdleTime = 0.0;
      v3->mLastScrolledPrev = 0;
      UFG::UIHK_PDARootMenuWidget::Flash_GetSelected(v3, v2);
      UFG::UIHK_PDARootMenuWidget::PlayPdaClick(v3);
    }
  }
}

// File Line: 265
// RVA: 0x604310
void __fastcall UFG::UIHK_PDARootMenuWidget::ScrollPrev(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  UFG::UIScreen *v2; // rdi
  UFG::UIHK_PDARootMenuWidget *v3; // rbx
  Scaleform::GFx::Movie *v4; // rcx

  v2 = screen;
  v3 = this;
  if ( this->mState == 2 )
  {
    v4 = screen->mRenderable->m_movie.pObject;
    if ( v4 )
    {
      Scaleform::GFx::Movie::Invoke(v4, "Smartphone_ScrollPrev", 0i64, 0i64, 0);
      v3->mIdleTime = 0.0;
      v3->mLastScrolledPrev = 1;
      UFG::UIHK_PDARootMenuWidget::Flash_GetSelected(v3, v2);
      UFG::UIHK_PDARootMenuWidget::PlayPdaClick(v3);
    }
  }
}

// File Line: 315
// RVA: 0x5E39B0
void __fastcall UFG::UIHK_PDARootMenuWidget::Flash_Show(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHK_PDARootMenuWidget *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  double v4; // xmm6_8
  char ptr; // [rsp+38h] [rbp-50h]
  __int64 v6; // [rsp+48h] [rbp-40h]
  unsigned int v7; // [rsp+50h] [rbp-38h]
  double v8; // [rsp+58h] [rbp-30h]

  v2 = this;
  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    UFG::UIHK_PDARootMenuWidget::Flash_SetGlobals(this, screen);
    `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v4 = (double)(signed int)v2->mIntroIndex;
    if ( (v7 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v6 + 16i64))(v6, &ptr, COERCE_DOUBLE(*(_QWORD *)&v8));
      v6 = 0i64;
    }
    v7 = 5;
    v8 = v4;
    Scaleform::GFx::Movie::Invoke(v3, "Smartphone_AnimateIntro", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 329
// RVA: 0x5DBA40
void __fastcall UFG::UIHK_PDARootMenuWidget::Flash_Hide(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rcx

  v2 = screen->mRenderable->m_movie.pObject;
  if ( v2 )
    Scaleform::GFx::Movie::Invoke(v2, "Smartphone_HideMenu", 0i64, 0i64, 0);
}

// File Line: 339
// RVA: 0x5DA860
void __fastcall UFG::UIHK_PDARootMenuWidget::Flash_EnterSubmenu(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  Scaleform::GFx::Movie *v2; // rcx

  v2 = screen->mRenderable->m_movie.pObject;
  if ( v2 )
    Scaleform::GFx::Movie::Invoke(v2, "Smartphone_EnterSubmenu", 0i64, 0i64, 0);
}

// File Line: 359
// RVA: 0x5DAC70
void __fastcall UFG::UIHK_PDARootMenuWidget::Flash_GetSelected(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHK_PDARootMenuWidget *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  long double v4; // rdx
  Scaleform::GFx::Value presult; // [rsp+38h] [rbp-40h]

  v2 = this;
  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    presult.pObjectInterface = 0i64;
    presult.Type = 0;
    Scaleform::GFx::Movie::Invoke(v3, "Smartphone_GetSelectedIndex", &presult, 0i64, 0);
    v2->mSelectedIndex = (signed int)presult.mValue.NValue;
    Scaleform::GFx::Movie::Invoke(v3, "Smartphone_GetSelectedItem", &presult, 0i64, 0);
    if ( ((unsigned int)presult.Type >> 6) & 1 )
      v4 = *(double *)presult.mValue.pString;
    else
      v4 = presult.mValue.NValue;
    UFG::qString::Set(&v2->mSelectedItem, *(const char **)&v4);
    if ( ((unsigned int)presult.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&presult.pObjectInterface->vfptr->gap8[8])(
        presult.pObjectInterface,
        &presult,
        *(_QWORD *)&presult.mValue.NValue);
  }
}

// File Line: 373
// RVA: 0x5DEA00
void __fastcall UFG::UIHK_PDARootMenuWidget::Flash_Refresh(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHK_PDARootMenuWidget *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi

  v2 = this;
  if ( this->mRefreshTimer <= 0.0 )
  {
    v3 = screen->mRenderable->m_movie.pObject;
    if ( v3 )
    {
      UFG::UIHK_PDARootMenuWidget::Flash_SetGlobals(this, screen);
      Scaleform::GFx::Movie::Invoke(v3, "Smartphone_Refresh", 0i64, 0i64, 0);
      v2->mRefreshTimer = 0.33333334;
    }
  }
}

// File Line: 388
// RVA: 0x5E0020
void __fastcall UFG::UIHK_PDARootMenuWidget::Flash_SetGlobals(UFG::UIHK_PDARootMenuWidget *this, UFG::UIScreen *screen)
{
  UFG::UIHK_PDARootMenuWidget *v2; // rdi
  Scaleform::GFx::Movie *v3; // rbx
  UFG::UIHK_PDAWidget *v4; // rcx
  bool v5; // al
  bool v6; // di
  UFG::GameStatTracker *v7; // rax
  __int64 v8; // rdi
  _BOOL8 v9; // rdi
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-38h]

  v2 = this;
  v3 = screen->mRenderable->m_movie.pObject;
  if ( v3 )
  {
    value.pObjectInterface = 0i64;
    value.Type = 0;
    if ( !UFG::PhotoManager::HasPhotoTarget()
      || (!UFG::UIHKScreenHud::mInstance ? (v4 = 0i64) : (v4 = UFG::UIHKScreenHud::mInstance->PDA),
          v4->IncomingCall.mState == 4 || (v5 = UFG::UIHK_PDARootMenuWidget::IsInVehicle(v2), v6 = 1, v5)) )
    {
      v6 = 0;
    }
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 2;
    value.mValue.BValue = v6;
    Scaleform::GFx::Movie::SetVariable(v3, "gCameraAvailable", &value, 1i64);
    v7 = UFG::GameStatTracker::Instance();
    v8 = (unsigned __int8)UFG::GameStatTracker::GetStat(v7, Collectible_Bio_New);
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 2;
    value.mValue.BValue = v8;
    Scaleform::GFx::Movie::SetVariable(v3, "gBiosAlert", &value, 1i64);
    v9 = UFG::SocialLogDataManager::Instance()->m_bHasNewChallengeMessage;
    if ( ((unsigned int)value.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
      value.pObjectInterface = 0i64;
    }
    value.Type = 2;
    value.mValue.BValue = v9;
    Scaleform::GFx::Movie::SetVariable(v3, "gSocialHubAlert", &value, 1i64);
    if ( ((unsigned int)value.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        *(_QWORD *)&value.mValue.NValue);
  }
}

// File Line: 404
// RVA: 0x5F4090
void __fastcall UFG::UIHK_PDARootMenuWidget::PlayPdaClick(UFG::UIHK_PDARootMenuWidget *this)
{
  unsigned int v1; // eax

  if ( _S39_1 & 1 )
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
    UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr, v1, 0i64, 0, 0i64);
}

