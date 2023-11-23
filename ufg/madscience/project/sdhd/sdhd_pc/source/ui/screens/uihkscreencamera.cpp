// File Line: 54
// RVA: 0x156E710
__int64 UFG::_dynamic_initializer_for__play_ui_camera_take_photo__()
{
  play_ui_camera_take_photo.mUID = UFG::qWiseSymbolUIDFromString("play_ui_camera_take_photo", 0x811C9DC5);
  _((AMD_HD3D *)play_ui_camera_take_photo.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__play_ui_camera_take_photo__);
}

// File Line: 71
// RVA: 0x5C4960
void __fastcall UFG::UIHKScreenCamera::UIHKScreenCamera(UFG::UIHKScreenCamera *this)
{
  this->mPrev = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->mNext = &this->UFG::qNode<UFG::UIScreen,UFG::UIScreen>;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = eDIM_INVALID;
  *(_QWORD *)&this->mCurDimValue = 1120403456i64;
  this->m_screenName[0] = 0;
  --this->mInputEnabled;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenCamera::`vftable;
  *(_QWORD *)&this->mState = 0i64;
  this->mObjectiveFlasher.mOldVisible = 0;
  this->mSavedControllerMode = 0;
  this->mTriggerCooldown = 0.2;
  *(_WORD *)&this->mValidPhoto = 0;
}

// File Line: 76
// RVA: 0x5CA050
void __fastcall UFG::UIHKScreenCamera::~UIHKScreenCamera(UFG::UIHKScreenCamera *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UI *v3; // rcx
  unsigned int v4; // eax
  UFG::UIHKScreenGlobalOverlay *v5; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v7; // eax
  UFG::UIScreenTextureManager *v8; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenCamera::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Camera");
  UFG::SetInputMode((UFG::eHKControllerInputMode)this->mSavedControllerMode, UFG::gActiveControllerNum);
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v4 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v4 == 1) )
        UFG::UI::ResetGameplayInput(v3);
    }
  }
  v5 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v5 = &gGlobalOverlaySentinel;
  p_HelpBar = &v5->HelpBar;
  v7 = UFG::qStringHash32("CAMERA", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v7);
  if ( this->mUploadPhoto )
  {
    UFG::UIHKScreenCaseComplete::mCaseType = CASE_TYPE_PHOTO;
    v8 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v8, "CaseComplete", 0i64);
  }
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 104
// RVA: 0x62FF40
void __fastcall UFG::UIHKScreenCamera::init(UFG::UIHKScreenCamera *this, UFG::UICommandData *data)
{
  UFG::UIScreenRenderable *mRenderable; // rcx
  UFG::InputSystem *v4; // rcx
  signed int v5; // eax
  UFG::Controller *v6; // rdx

  UFG::UIScreen::init(this, data);
  UFG::UIHKPlayerObjectiveManager::UpdateObjectives(&UFG::UIHK_PDAWidget::ObjectiveManager);
  UFG::UIHKObjectiveFlasherWidget::mState = (unsigned int)(UFG::UIHKObjectiveFlasherWidget::mState - 3) > 1
                                         && UFG::UIHKObjectiveFlasherWidget::mState != STATE_IDLE;
  mRenderable = this->mRenderable;
  this->mState = STATE_BRIGHTNESS;
  Scaleform::GFx::Movie::Invoke(mRenderable->m_movie.pObject, "Camera_HideReticles", 0i64, 0i64, 0);
  this->mReticleState = STATE_HIDDEN;
  UFG::UIHKScreenCamera::ShowHelpBar(this);
  v4 = UFG::gInputSystem;
  if ( !UFG::gInputSystem )
  {
LABEL_9:
    v5 = UFG::gActiveControllerNum;
    goto LABEL_10;
  }
  v5 = UFG::gActiveControllerNum;
  if ( UFG::gActiveControllerNum != -1 )
  {
    v6 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v6->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v6->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
    v4 = UFG::gInputSystem;
    goto LABEL_9;
  }
LABEL_10:
  this->mSavedControllerMode = v4->mControllers[v5]->m_ActiveMapSet;
  UFG::SetInputMode(IM_SNIPER, UFG::gActiveControllerNum);
  this->mTriggerCooldown = 0.2;
  *(_WORD *)&this->mValidPhoto = 0;
}

// File Line: 127
// RVA: 0x603E30
void __fastcall UFG::UIHKScreenCamera::ScreenShotCallback(Illusion::Target *target)
{
  UFG::UIScreen *Overlay; // rbx

  UFG::UIHKScreenCamera::sPhotoTarget = target;
  Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "Camera");
  if ( Overlay )
  {
    UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, "Camera");
    LODWORD(Overlay[1].vfptr) = 5;
  }
  else if ( UFG::UIHKScreenCamera::sPhotoTarget )
  {
    Illusion::DeleteTarget((AMD_HD3D *)UFG::UIHKScreenCamera::sPhotoTarget, 1);
    UFG::UIHKScreenCamera::sPhotoTarget = 0i64;
  }
}

// File Line: 149
// RVA: 0x63C750
void __fastcall UFG::UIHKScreenCamera::update(UFG::UIHKScreenCamera *this, float elapsed)
{
  Scaleform::GFx::Movie *pObject; // rsi
  UFG::UIHKPlayerObjective *v4; // rdi
  unsigned __int8 v5; // dl
  UFG::InputActionData *v6; // rcx
  UFG::PhotoTarget *ValidOnScreenTarget; // rdi
  char valid; // dl
  bool bClearLOS; // cl
  bool v10; // al
  bool v11; // di
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-48h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  UFG::UIHKPlayerObjectiveManager::UpdatePendingBlips(&UFG::UIHK_PDAWidget::ObjectiveManager);
  if ( unk_142432920 && !UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "MissionRewards") )
  {
    unk_142432920 = 0;
    if ( unk_1424329E8 )
    {
      v4 = &stru_142432928;
LABEL_14:
      UFG::UIHKPlayerObjectiveManager::FlashObjective(&UFG::UIHK_PDAWidget::ObjectiveManager, v4);
      goto LABEL_15;
    }
    if ( unk_1424329EA )
    {
      if ( unk_1424329E9 )
      {
        v4 = &obj;
        goto LABEL_13;
      }
      unk_1424329EA = 0;
    }
    if ( unk_142432878 )
    {
      v5 = byte_142432888[0];
      if ( (unsigned int)byte_142432888[0] >= unk_142432878 )
        v5 = 0;
      byte_142432888[0] = v5;
      v4 = *(UFG::UIHKPlayerObjective **)(*(_QWORD *)&dword_142432880 + 8i64 * v5);
      if ( v4 )
      {
LABEL_13:
        if ( !UFG::UIHKPlayerObjectiveManager::ShouldFlashObjective(&UFG::UIHK_PDAWidget::ObjectiveManager, v4) )
          goto LABEL_15;
        goto LABEL_14;
      }
    }
  }
LABEL_15:
  UFG::UIHKObjectiveFlasherWidget::Update(&this->mObjectiveFlasher, this);
  this->mValidPhoto = 0;
  if ( (unsigned int)(this->mState - 2) <= 1 )
  {
    v6 = UFG::ActionDef_Focus.mDataPerController[UFG::gActiveControllerNum];
    if ( v6 && v6->mActionTrue )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = VT_Boolean;
      pargs.mValue.BValue = 1;
      if ( this->mReticleState != STATE_SHOWING )
      {
        Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "Camera_ShowReticles", 0i64, 0i64, 0);
        this->mReticleState = STATE_SHOWING;
      }
      ValidOnScreenTarget = UFG::PhotoManager::GetValidOnScreenTarget();
      valid = UFG::PhotoManager::AnyValidTargetsFramed();
      if ( ValidOnScreenTarget )
        bClearLOS = ValidOnScreenTarget->bClearLOS;
      else
        bClearLOS = 0;
      if ( ValidOnScreenTarget )
        v10 = ValidOnScreenTarget->fDelay < ValidOnScreenTarget->fTimer;
      else
        v10 = 0;
      if ( !valid || !bClearLOS || (v11 = 1, !v10) )
        v11 = 0;
      this->mValidPhoto = v11;
      if ( (pargs.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = VT_Boolean;
      pargs.mValue.BValue = v11;
      Scaleform::GFx::Movie::Invoke(pObject, "Camera_SetReticleFrame", 0i64, &pargs, 1u);
      Scaleform::GFx::Movie::Invoke(pObject, "Camera_SetReticleFocus", 0i64, &pargs, 1u);
      if ( this->mState != STATE_UISCALE )
      {
        this->mState = STATE_UISCALE;
        UFG::UIHKScreenCamera::ShowHelpBar(this);
      }
      if ( (pargs.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = VT_Undefined;
    }
    else
    {
      this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
      UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, "Camera");
    }
  }
  if ( this->mState == STATE_BRIGHTNESS )
  {
    this->mState = STATE_VOLUME;
    UFG::UIHKScreenCamera::ShowHelpBar(this);
  }
  else if ( this->mState == STATE_UISCALE )
  {
    UFG::UIHKScreenCamera::update_FirstPersonReadyForPic(this);
  }
  if ( this->mState != (NUM_CALIBRATION_STATES|STATE_BRIGHTNESS) && !UFG::UIHKScreenCamera::IsHoldingPDA(this) )
  {
    this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
    UFG::UIHKScreenHud::ClearPDACache();
    UFG::UIScreenManagerBase::queuePopOverlay(UFG::UIScreenManager::s_instance, "Camera");
  }
  this->mTriggerCooldown = elapsed + this->mTriggerCooldown;
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 226
// RVA: 0x621990
bool __fastcall UFG::UIHKScreenCamera::handleMessage(
        UFG::UIHKScreenCamera *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIHKObjectiveFlasherWidget::HandleMessage(&this->mObjectiveFlasher, this, msgId, msg);
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

// File Line: 233
// RVA: 0x641CC0
void __fastcall UFG::UIHKScreenCamera::update_FirstPersonReadyForPic(UFG::UIHKScreenCamera *this)
{
  Scaleform::GFx::Movie *pObject; // rdi
  UFG::InputActionData *v3; // rdx
  bool v4; // al
  UFG::PhotoTarget *ValidOnScreenTarget; // rax
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    v3 = UFG::ActionDef_FireFullReleased.mDataPerController[UFG::gActiveControllerNum];
  else
    v3 = UFG::ActionDef_FireFull.mDataPerController[UFG::gActiveControllerNum];
  v4 = v3 && v3->mActionTrue;
  if ( this->mTriggerCooldown > 0.2 && v4 )
  {
    UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, play_ui_camera_take_photo.mUID, 0i64, 0, 0i64);
    Scaleform::GFx::Movie::Invoke(this->mRenderable->m_movie.pObject, "Camera_TakePicture", 0i64, 0i64, 0);
    this->mTriggerCooldown = 0.0;
    if ( this->mValidPhoto )
    {
      if ( UFG::UIHKScreenCamera::sPhotoTarget )
      {
        Illusion::DeleteTarget((AMD_HD3D *)UFG::UIHKScreenCamera::sPhotoTarget, 1);
        UFG::UIHKScreenCamera::sPhotoTarget = 0i64;
      }
      UFG::PhotoManager::RecordPhoto();
      pargs.pObjectInterface = 0i64;
      pargs.Type = VT_Boolean;
      pargs.mValue.BValue = 1;
      Scaleform::GFx::Movie::Invoke(pObject, "Camera_PictureSuccess", 0i64, &pargs, 1u);
      ValidOnScreenTarget = UFG::PhotoManager::GetValidOnScreenTarget();
      if ( ValidOnScreenTarget )
        LOBYTE(ValidOnScreenTarget) = ValidOnScreenTarget->bUpload;
      this->mUploadPhoto = (char)ValidOnScreenTarget;
      UFG::RenderWorld::RequestScreenShot(UFG::UIHKScreenCamera::ScreenShotCallback, 0.40000001, IMAGE_FILE_FORMAT_JPG);
      this->mState = NUM_CALIBRATION_STATES;
      if ( (pargs.Type & 0x40) != 0 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          pargs.mValue);
    }
  }
}

// File Line: 289
// RVA: 0x5EE220
bool __fastcall UFG::UIHKScreenCamera::IsHoldingPDA(UFG::UIHKScreenCamera *this)
{
  UFG::SimObjectCharacter *LocalPlayer; // rax
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rax

  LocalPlayer = UFG::GetLocalPlayer();
  if ( LocalPlayer
    && (ComponentOfType = UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::TargetingSystemBaseComponent::_TypeUID)) != 0i64
    && (v3 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&ComponentOfType[1].m_Flags + 26i64)
                                + *(_QWORD *)&ComponentOfType[1].m_TypeUID
                                + 40)) != 0i64
    && (v4 = UFG::SimObject::GetComponentOfType(v3, UFG::SimObjectWeaponPropertiesComponent::_TypeUID)) != 0i64 )
  {
    return BYTE5(v4[3].m_SafePointerList.mNode.mPrev);
  }
  else
  {
    return 0;
  }
}

// File Line: 319
// RVA: 0x60D770
void __fastcall UFG::UIHKScreenCamera::ShowHelpBar(UFG::UIHKScreenCamera *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v3; // ebx
  UFG::UIHKHelpBarWidget *v4; // rdi
  unsigned int v5; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-D0h] BYREF

  v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v1 = &gGlobalOverlaySentinel;
    p_HelpBar = &v1->HelpBar;
    v3 = UFG::qStringHash32("CAMERA", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v3;
    data.priority = PRIORITY_ONE;
    data.alignment = ALIGN_RIGHT;
    *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$HUD_CAMERA_ZOOM_OUT");
    UFG::qString::Set(&data.Captions[1], "$HUD_CAMERA_ZOOM_IN");
    UFG::qString::Set(&data.Captions[2], "$HUD_CAMERA_FOCUS");
    UFG::qString::Set(&data.Captions[3], &customCaption);
    UFG::qString::Set(&data.Captions[4], &customCaption);
    UFG::qString::Set(&data.Captions[5], &customCaption);
    memset(data.MessageIds, 0, sizeof(data.MessageIds));
    UFG::UIHKHelpBarWidget::Show(p_HelpBar, &data);
    UFG::qString::~qString(&data.CustomTexturePack);
    `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    p_HelpBar->mRemappable = 1;
  }
  else
  {
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v1 = &gGlobalOverlaySentinel;
    v4 = &v1->HelpBar;
    v5 = UFG::qStringHash32("CAMERA", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v5;
    data.priority = PRIORITY_ONE;
    data.alignment = ALIGN_RIGHT;
    *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$HUD_CAMERA_ZOOM_OUT");
    UFG::qString::Set(&data.Captions[1], "$HUD_CAMERA_ZOOM_IN");
    UFG::qString::Set(&data.Captions[2], "$HUD_CAMERA_FOCUS");
    UFG::qString::Set(&data.Captions[3], &customCaption);
    UFG::qString::Set(&data.Captions[4], &customCaption);
    UFG::qString::Set(&data.Captions[5], &customCaption);
    memset(data.MessageIds, 0, sizeof(data.MessageIds));
    UFG::UIHKHelpBarWidget::Show(v4, &data);
    UFG::qString::~qString(&data.CustomTexturePack);
    `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  }
}

