// File Line: 20
// RVA: 0x1567540
__int64 UFG::_dynamic_initializer_for__DIALOG_BOX_HASH__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("HKDIALOGBOX", 0xFFFFFFFF);
  DIALOG_BOX_HASH = result;
  return result;
}

// File Line: 28
// RVA: 0x5C4FE0
void __fastcall UFG::UIHKScreenDialogBox::UIHKScreenDialogBox(UFG::UIHKScreenDialogBox *this)
{
  UFG::Controller *v2; // rcx

  UFG::UIScreenDialogBox::UIScreenDialogBox(this);
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDialogBox::`vftable;
  UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(&this->DOF);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v2 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v2->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v2->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  ++UFG::UIHK_NISOverlay::mLock;
}

// File Line: 35
// RVA: 0x5CA7D0
void __fastcall UFG::UIHKScreenDialogBox::~UIHKScreenDialogBox(UFG::UIHKScreenDialogBox *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UI *v3; // rcx
  unsigned int v4; // eax
  UFG::UIHKScreenGlobalOverlay *v5; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenDialogBox::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "DialogBox");
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v4 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v4 == 1) )
        UFG::UI::ResetGameplayInput(v3);
    }
  }
  --UFG::UIHK_NISOverlay::mLock;
  v5 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v5 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Hide(&v5->HelpBar, this->mScreenUID);
  UFG::InputSystem::PopRestrictAndHideSettings();
  if ( (unsigned int)UFG::FlowController::GetCurrentState(&UFG::gFlowController) == uidGameStateInGame_13
    && UFG::gFlowController.mCurrentState
    && !UFG::gFlowController.mCurrentState->vfptr->ModeIsSet(UFG::gFlowController.mCurrentState, eGSM_PAUSED) )
  {
    UFG::InputSystem::SetShouldRestrictCursor(0, 1, 1, 1);
    UFG::InputSystem::SetShouldHideCursor(1, 1, 1, 1);
  }
  UFG::GameCameraComponent::EndDOFOverride(DOFOverridePriority_0);
  UFG::UIScreenDialogBox::~UIScreenDialogBox(this);
}

// File Line: 61
// RVA: 0x630740
void __fastcall UFG::UIHKScreenDialogBox::init(UFG::UIHKScreenDialogBox *this, UFG::UICommandData *data)
{
  UFG::UIScreenDialogBox::init(this, data);
  if ( data && LODWORD(data[30].vfptr) == UI_HASH_DIALOG_ICON_SAVELOAD_20 )
    UFG::UIHKScreenDialogBox::Flash_ShowSaveLoadIcon(this);
  UFG::InputSystem::PushRestrictAndHideSettings();
  UFG::InputSystem::SetShouldRestrictCursor(1, 0, 1, 0);
  UFG::InputSystem::SetShouldHideCursor(1, 0, 1, 0);
}

// File Line: 80
// RVA: 0x6226D0
bool __fastcall UFG::UIHKScreenDialogBox::handleMessage(
        UFG::UIHKScreenDialogBox *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  if ( msgId == UI_HASH_GAME_OVER_20 )
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
  return UFG::UIScreenDialogBox::handleMessage(this, msgId, msg);
}

// File Line: 91
// RVA: 0x63CB40
void __fastcall UFG::UIHKScreenDialogBox::update(UFG::UIHKScreenDialogBox *this, float elapsed)
{
  unsigned int mScreenUID; // esi
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-268h] BYREF

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    mScreenUID = this->mScreenUID;
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = mScreenUID;
    data.priority = PRIORITY_ONE;
    data.alignment = ALIGN_RIGHT;
    memset(data.Buttons, 0, sizeof(data.Buttons));
    UFG::qString::Set(data.Captions, &customCaption);
    UFG::qString::Set(&data.Captions[1], &customCaption);
    UFG::qString::Set(&data.Captions[2], &customCaption);
    UFG::qString::Set(&data.Captions[3], &customCaption);
    UFG::qString::Set(&data.Captions[4], &customCaption);
    UFG::qString::Set(&data.Captions[5], &customCaption);
    memset(data.MessageIds, 0, sizeof(data.MessageIds));
    UFG::UIHKHelpBarWidget::Show(p_HelpBar, &data);
    UFG::qString::~qString(&data.CustomTexturePack);
    `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  }
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 104
// RVA: 0x61F6A0
void __fastcall UFG::UIHKScreenDialogBox::createSaveLoadNotificationDialog(UFG::UIScreen *owner)
{
  UFG::UICommand *v2; // rsi
  UFG::allocator::free_link *v3; // rax
  UFG::UIScreenDialogBox::UIScreenDialogBoxData *v4; // rax
  UFG::UIScreenDialogBox::UIScreenDialogBoxData *v5; // rbx

  v2 = UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManager::s_instance, "DialogBox", -1);
  v3 = UFG::qMemoryPool::Allocate(&gScaleformMemoryPool, 0x128ui64, "UIHKScreenDialogBox", 0i64, 1u);
  if ( v3 )
  {
    UFG::UIScreenDialogBox::UIScreenDialogBoxData::UIScreenDialogBoxData((UFG::UIScreenDialogBox::UIScreenDialogBoxData *)v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v5->mNumOptions = 1;
  v5->mOwner = owner;
  UFG::qString::Set(&v5->mTitleText, &customCaption);
  UFG::qString::Set(&v5->mBodyText, "$COMMON_TRC_AUTOSAVE_PC");
  v5->mDefaultButton = DIALOG_BUTTON1;
  v5->mOption1Msg = UI_HASH_DIALOG_OK_AUTOSAVE_20;
  UFG::qString::Set(&v5->mOption1Text, "$COMMON_OK_UPPERCASE");
  v5->mIcon = UI_HASH_DIALOG_ICON_SAVELOAD_20;
  v2->m_commandData = v5;
}

// File Line: 133
// RVA: 0x5E4C50
void __fastcall UFG::UIHKScreenDialogBox::Flash_ShowSaveLoadIcon(UFG::UIHKScreenDialogBox *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-40h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  if ( pObject )
  {
    value.pObjectInterface = 0i64;
    value.Type = VT_Boolean;
    value.mValue.BValue = 1;
    Scaleform::GFx::Movie::SetVariable(pObject, "mc_saveIcon._visible", &value, 1i64);
    if ( (value.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
        value.pObjectInterface,
        &value,
        value.mValue);
  }
}

