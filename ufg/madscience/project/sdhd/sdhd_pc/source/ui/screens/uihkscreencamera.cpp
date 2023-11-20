// File Line: 54
// RVA: 0x156E710
__int64 UFG::_dynamic_initializer_for__play_ui_camera_take_photo__()
{
  play_ui_camera_take_photo.mUID = UFG::qWiseSymbolUIDFromString("play_ui_camera_take_photo", 0x811C9DC5);
  _((AMD_HD3D *)play_ui_camera_take_photo.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__play_ui_camera_take_photo__);
}

// File Line: 71
// RVA: 0x5C4960
void __fastcall UFG::UIHKScreenCamera::UIHKScreenCamera(UFG::UIHKScreenCamera *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
  this->m_screenNameHash = 0;
  this->mRenderable = 0i64;
  this->mLoadThread = 0i64;
  this->mScreenUID = -1;
  *(_QWORD *)&this->mControllerMask = 15i64;
  *(_QWORD *)&this->mPriority = 0i64;
  this->mDimToApplyType = 0;
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
  UFG::UIHKScreenCamera *v1; // rbx
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UI *v3; // rcx
  unsigned int v4; // eax
  UFG::UIHKScreenGlobalOverlay *v5; // rax
  UFG::UIHKHelpBarWidget *v6; // rdi
  unsigned int v7; // eax
  UFG::UIScreenTextureManager *v8; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenCamera::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Camera");
  UFG::SetInputMode((UFG::eHKControllerInputMode)v1->mSavedControllerMode, UFG::gActiveControllerNum);
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
  v6 = &v5->HelpBar;
  v7 = UFG::qStringHash32("CAMERA", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v6, v7);
  if ( v1->mUploadPhoto )
  {
    UFG::UIHKScreenCaseComplete::mCaseType = 1;
    v8 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v8, "CaseComplete", 0i64);
  }
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 104
// RVA: 0x62FF40
void __fastcall UFG::UIHKScreenCamera::init(UFG::UIHKScreenCamera *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenCamera *v2; // rbx
  UFG::UIScreenRenderable *v3; // rcx
  UFG::InputSystem *v4; // rcx
  signed int v5; // eax
  UFG::Controller *v6; // rdx

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  UFG::UIHKPlayerObjectiveManager::UpdateObjectives(&UFG::UIHK_PDAWidget::ObjectiveManager);
  if ( (unsigned int)(UFG::UIHKObjectiveFlasherWidget::mState - 3) > 1 )
    UFG::UIHKObjectiveFlasherWidget::mState = UFG::UIHKObjectiveFlasherWidget::mState != 0;
  else
    UFG::UIHKObjectiveFlasherWidget::mState = 0;
  v3 = v2->mRenderable;
  v2->mState = 1;
  Scaleform::GFx::Movie::Invoke(v3->m_movie.pObject, "Camera_HideReticles", 0i64, 0i64, 0);
  v2->mReticleState = 0;
  UFG::UIHKScreenCamera::ShowHelpBar(v2);
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
  v2->mSavedControllerMode = v4->mControllers[v5]->m_ActiveMapSet;
  UFG::SetInputMode(IM_SNIPER, UFG::gActiveControllerNum);
  v2->mTriggerCooldown = 0.2;
  *(_WORD *)&v2->mValidPhoto = 0;
}

// File Line: 127
// RVA: 0x603E30
void __fastcall UFG::UIHKScreenCamera::ScreenShotCallback(Illusion::Target *target)
{
  UFG::UIScreen *v1; // rbx

  UFG::UIHKScreenCamera::sPhotoTarget = target;
  v1 = UFG::UIScreenManagerBase::getOverlay(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "Camera");
  if ( v1 )
  {
    UFG::UIScreenManagerBase::queuePopOverlay(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      "Camera");
    LODWORD(v1[1].vfptr) = 5;
  }
  else if ( UFG::UIHKScreenCamera::sPhotoTarget )
  {
    Illusion::DeleteTarget(UFG::UIHKScreenCamera::sPhotoTarget, 1);
    UFG::UIHKScreenCamera::sPhotoTarget = 0i64;
  }
}

// File Line: 149
// RVA: 0x63C750
void __fastcall UFG::UIHKScreenCamera::update(UFG::UIHKScreenCamera *this, float elapsed)
{
  UFG::UIHKScreenCamera *v2; // rbx
  Scaleform::GFx::Movie *v3; // rsi
  UFG::UIHKPlayerObjective *v4; // rdi
  unsigned __int8 v5; // dl
  UFG::InputActionData *v6; // rcx
  UFG::PhotoTarget *v7; // rdi
  char v8; // dl
  bool v9; // cl
  bool v10; // al
  bool v11; // di
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-48h]

  v2 = this;
  v3 = this->mRenderable->m_movie.pObject;
  UFG::UIHKPlayerObjectiveManager::UpdatePendingBlips(&UFG::UIHK_PDAWidget::ObjectiveManager);
  if ( unk_142432920
    && !UFG::UIScreenManagerBase::getOverlay(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "MissionRewards") )
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
  UFG::UIHKObjectiveFlasherWidget::Update(&v2->mObjectiveFlasher, (UFG::UIScreen *)&v2->vfptr);
  v2->mValidPhoto = 0;
  if ( (unsigned int)(v2->mState - 2) <= 1 )
  {
    v6 = UFG::ActionDef_Focus.mDataPerController[UFG::gActiveControllerNum];
    if ( v6 && v6->mActionTrue )
    {
      pargs.pObjectInterface = 0i64;
      pargs.Type = 0;
      pargs.Type = 2;
      pargs.mValue.BValue = 1;
      if ( v2->mReticleState != 1 )
      {
        Scaleform::GFx::Movie::Invoke(v2->mRenderable->m_movie.pObject, "Camera_ShowReticles", 0i64, 0i64, 0);
        v2->mReticleState = 1;
      }
      v7 = UFG::PhotoManager::GetValidOnScreenTarget();
      v8 = UFG::PhotoManager::AnyValidTargetsFramed();
      if ( v7 )
        v9 = v7->bClearLOS;
      else
        v9 = 0;
      if ( v7 )
        v10 = v7->fDelay < v7->fTimer;
      else
        v10 = 0;
      if ( !v8 || !v9 || (v11 = 1, !v10) )
        v11 = 0;
      v2->mValidPhoto = v11;
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = 2;
      pargs.mValue.BValue = v11;
      Scaleform::GFx::Movie::Invoke(v3, "Camera_SetReticleFrame", 0i64, &pargs, 1u);
      Scaleform::GFx::Movie::Invoke(v3, "Camera_SetReticleFocus", 0i64, &pargs, 1u);
      if ( v2->mState != 3 )
      {
        v2->mState = 3;
        UFG::UIHKScreenCamera::ShowHelpBar(v2);
      }
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
        pargs.pObjectInterface = 0i64;
      }
      pargs.Type = 0;
    }
    else
    {
      v2->mState = 5;
      UFG::UIScreenManagerBase::queuePopOverlay(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        "Camera");
    }
  }
  if ( v2->mState == 1 )
  {
    v2->mState = 2;
    UFG::UIHKScreenCamera::ShowHelpBar(v2);
  }
  else if ( v2->mState == 3 )
  {
    UFG::UIHKScreenCamera::update_FirstPersonReadyForPic(v2);
  }
  if ( v2->mState != 5 && !UFG::UIHKScreenCamera::IsHoldingPDA(v2) )
  {
    v2->mState = 5;
    UFG::UIHKScreenHud::ClearPDACache();
    UFG::UIScreenManagerBase::queuePopOverlay(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      "Camera");
  }
  v2->mTriggerCooldown = elapsed + v2->mTriggerCooldown;
  UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
}

// File Line: 226
// RVA: 0x621990
bool __fastcall UFG::UIHKScreenCamera::handleMessage(UFG::UIHKScreenCamera *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIHKScreenCamera *v3; // rsi
  UFG::UIMessage *v4; // rbx
  unsigned int v5; // edi

  v3 = this;
  v4 = msg;
  v5 = msgId;
  UFG::UIHKObjectiveFlasherWidget::HandleMessage(&this->mObjectiveFlasher, (UFG::UIScreen *)&this->vfptr, msgId, msg);
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v3->vfptr, v5, v4);
}

// File Line: 233
// RVA: 0x641CC0
void __fastcall UFG::UIHKScreenCamera::update_FirstPersonReadyForPic(UFG::UIHKScreenCamera *this)
{
  UFG::UIHKScreenCamera *v1; // rbx
  Scaleform::GFx::Movie *v2; // rdi
  UFG::InputActionData *v3; // rdx
  bool v4; // al
  UFG::PhotoTarget *v5; // rax
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v1 = this;
  v2 = this->mRenderable->m_movie.pObject;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
    v3 = UFG::ActionDef_FireFullReleased.mDataPerController[UFG::gActiveControllerNum];
  else
    v3 = UFG::ActionDef_FireFull.mDataPerController[UFG::gActiveControllerNum];
  v4 = v3 && v3->mActionTrue;
  if ( this->mTriggerCooldown > 0.2 && v4 )
  {
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
      play_ui_camera_take_photo.mUID,
      0i64,
      0,
      0i64);
    Scaleform::GFx::Movie::Invoke(v1->mRenderable->m_movie.pObject, "Camera_TakePicture", 0i64, 0i64, 0);
    v1->mTriggerCooldown = 0.0;
    if ( v1->mValidPhoto )
    {
      if ( UFG::UIHKScreenCamera::sPhotoTarget )
      {
        Illusion::DeleteTarget(UFG::UIHKScreenCamera::sPhotoTarget, 1);
        UFG::UIHKScreenCamera::sPhotoTarget = 0i64;
      }
      UFG::PhotoManager::RecordPhoto();
      pargs.pObjectInterface = 0i64;
      pargs.Type = 2;
      pargs.mValue.BValue = 1;
      Scaleform::GFx::Movie::Invoke(v2, "Camera_PictureSuccess", 0i64, &pargs, 1u);
      v5 = UFG::PhotoManager::GetValidOnScreenTarget();
      if ( v5 )
        LOBYTE(v5) = v5->bUpload;
      v1->mUploadPhoto = (char)v5;
      UFG::RenderWorld::RequestScreenShot(UFG::UIHKScreenCamera::ScreenShotCallback, 0.40000001, IMAGE_FILE_FORMAT_JPG);
      v1->mState = 4;
      if ( ((unsigned int)pargs.Type >> 6) & 1 )
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
          pargs.pObjectInterface,
          &pargs,
          *(_QWORD *)&pargs.mValue.NValue);
    }
  }
}

// File Line: 289
// RVA: 0x5EE220
bool __fastcall UFG::UIHKScreenCamera::IsHoldingPDA(UFG::UIHKScreenCamera *this)
{
  UFG::SimObjectCharacter *v1; // rax
  UFG::SimComponent *v2; // rax
  UFG::SimObject *v3; // rcx
  UFG::SimComponent *v4; // rax
  bool result; // al

  v1 = UFG::GetLocalPlayer();
  if ( v1
    && (v2 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v1->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID)) != 0i64
    && (v3 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v2[1].m_Flags + 26i64)
                                + *(_QWORD *)&v2[1].m_TypeUID
                                + 40)) != 0i64
    && (v4 = UFG::SimObject::GetComponentOfType(v3, UFG::SimObjectWeaponPropertiesComponent::_TypeUID)) != 0i64 )
  {
    result = BYTE5(v4[3].m_SafePointerList.mNode.mPrev);
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 319
// RVA: 0x60D770
void __fastcall UFG::UIHKScreenCamera::ShowHelpBar(UFG::UIHKScreenCamera *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *v2; // rdi
  unsigned int v3; // ebx
  UFG::UIHKHelpBarWidget *v4; // rdi
  unsigned int v5; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-C8h]

  v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_IsKeyboardController )
  {
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v1 = &gGlobalOverlaySentinel;
    v2 = &v1->HelpBar;
    v3 = UFG::qStringHash32("CAMERA", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v3;
    data.priority = 0;
    data.alignment = 1;
    _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$HUD_CAMERA_ZOOM_OUT");
    UFG::qString::Set((UFG::qString *)((char *)data.Captions + 32), "$HUD_CAMERA_ZOOM_IN");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), "$HUD_CAMERA_FOCUS");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 32), &customWorldMapCaption);
    *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
    *(_QWORD *)data.MessageIds = 0i64;
    *(_QWORD *)&data.MessageIds[2] = 0i64;
    UFG::UIHKHelpBarWidget::Show(v2, &data);
    UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
    `eh vector destructor iterator(
      &data.Captions[5].mStringHash32,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    v2->mRemappable = 1;
  }
  else
  {
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v1 = &gGlobalOverlaySentinel;
    v4 = &v1->HelpBar;
    v5 = UFG::qStringHash32("CAMERA", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v5;
    data.priority = 0;
    data.alignment = 1;
    _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$HUD_CAMERA_ZOOM_OUT");
    UFG::qString::Set((UFG::qString *)((char *)data.Captions + 32), "$HUD_CAMERA_ZOOM_IN");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), "$HUD_CAMERA_FOCUS");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 32), &customWorldMapCaption);
    *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
    *(_QWORD *)data.MessageIds = 0i64;
    *(_QWORD *)&data.MessageIds[2] = 0i64;
    UFG::UIHKHelpBarWidget::Show(v4, &data);
    UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
    `eh vector destructor iterator(
      &data.Captions[5].mStringHash32,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  }
}

