// File Line: 50
// RVA: 0x5C7780
void __fastcall UFG::UIHKScreenStartFlow::UIHKScreenStartFlow(UFG::UIHKScreenStartFlow *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenStartFlow::`vftable;
  *(_QWORD *)&this->mState = 0i64;
  this->mAutoSaveSlotIndex = 0;
}

// File Line: 57
// RVA: 0x5CCCD0
void __fastcall UFG::UIHKScreenStartFlow::~UIHKScreenStartFlow(UFG::UIHKScreenStartFlow *this)
{
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v4; // eax
  UFG::UIScreenTextureManager *v5; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenStartFlow::`vftable;
  v2 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v2 = &gGlobalOverlaySentinel;
  p_HelpBar = &v2->HelpBar;
  v4 = UFG::qStringHash32("UIHKScreenStartFlow", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v4);
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v5, "StartFlowScreen");
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 65
// RVA: 0x636940
void __fastcall UFG::UIHKScreenStartFlow::init(UFG::UIHKScreenStartFlow *this, UFG::UICommandData *data)
{
  Scaleform::GFx::Movie *MovieSafe; // rax
  Scaleform::GFx::Movie *v4; // rdi

  UFG::UIScreen::init(this, data);
  this->mState = STATE_INIT;
  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  v4 = MovieSafe;
  if ( MovieSafe )
  {
    UFG::UIHKScreenStartFlow::StartSaveFileHeaderLoad(this, MovieSafe);
    UFG::UIHKScreenStartFlow::InitScreen(this, v4);
    UFG::UIHKScreenStartFlow::SetHeaderText(this, v4);
    UFG::UIHKScreenStartFlow::SetNewGameSlotText(this, v4);
    UFG::UIHKScreenStartFlow::UpdateHelpbar(this);
  }
}

// File Line: 86
// RVA: 0x640150
void __fastcall UFG::UIHKScreenStartFlow::update(UFG::UIHKScreenStartFlow *this, float elapsed)
{
  __int32 v3; // ecx
  float v4; // xmm0_4

  v3 = this->mState - 2;
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      v4 = elapsed + this->mLoadTimeElapsed;
      this->mLoadTimeElapsed = v4;
      if ( v4 > 2.0 )
      {
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mPopupDialogScreenUID);
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
        this->mState = NUM_CALIBRATION_STATES|STATE_UISCALE;
      }
    }
  }
  else
  {
    this->mLoadTimeElapsed = elapsed + this->mLoadTimeElapsed;
  }
  UFG::UIScreen::update(this, elapsed);
}

// File Line: 125
// RVA: 0x62CDF0
char __fastcall UFG::UIHKScreenStartFlow::handleMessage(
        UFG::UIHKScreenStartFlow *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  char v3; // bl
  __int32 v8; // ecx
  __int32 v9; // ecx
  __int32 v10; // ecx
  __int32 v11; // ecx
  Scaleform::GFx::Movie *MovieSafe; // rax
  __int32 v13; // ebx
  UFG::GameSaveLoad *v14; // rax
  UFG::UIScreen *Overlay; // rax
  UFG::UIHKScreenGlobalOverlay *v16; // rcx
  UFG::UIScreenManager *v17; // rbx
  unsigned int ScreenUID; // eax
  UFG::UI *v19; // rcx

  v3 = 0;
  if ( !this->mRenderable->m_movie.pObject )
    return 0;
  v8 = this->mState - 1;
  if ( !v8 )
  {
    if ( msgId != -339696135 )
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    UFG::UIHKScreenStartFlow::OnHeaderFileLoadComplete(this);
    ++this->mInputEnabled;
    goto LABEL_46;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    if ( msgId == 1552074461 )
    {
      v17 = UFG::UIScreenManager::s_instance;
      ScreenUID = UFG::UIScreenManagerBase::getScreenUID(UFG::UIScreenManager::s_instance, "MainMenu");
      UFG::UIScreenManagerBase::queueMessage(v17, UI_HASH_LOAD_COMPLETE_20, ScreenUID);
      UFG::UI::HandleGameCheckpointRestore(v19);
      if ( this->mLoadTimeElapsed <= 2.0 )
      {
        this->mState = STATE_UISCALE;
      }
      else
      {
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mPopupDialogScreenUID);
        UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
        this->mState = NUM_CALIBRATION_STATES|STATE_UISCALE;
      }
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    }
    if ( msgId != 1323471633 )
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
LABEL_46:
    this->mState = NUM_CALIBRATION_STATES;
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  v10 = v9 - 2;
  if ( !v10 )
  {
    if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30
      || msgId == UI_HASH_DPAD_DOWN_REPEAT_30
      || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30
      || msgId == UI_HASH_DPAD_UP_PRESSED_30
      || msgId == UI_HASH_DPAD_UP_REPEAT_30
      || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30
      || msgId == UI_HASH_BUTTON_BACK_PRESSED_30
      || msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30
      || msgId == UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
    {
      v3 = UFG::UIHKScreenStartFlow::HandleUserInput(this, msgId);
    }
    Overlay = UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "GlobalOverlay");
    if ( Overlay )
    {
      v16 = UFG::UIHKScreenGlobalOverlay::mThis;
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v16 = &gGlobalOverlaySentinel;
      UFG::UIHKHelpBarWidget::HandleMessage(&v16->HelpBar, Overlay, msgId, msg);
    }
    if ( msgId == UI_HASH_MOUSE_MOVE_30 )
    {
      UFG::UIHKScreenUpgrades::Flash_HandleMouseMove(
        (UFG::UIHKScreenUpgrades *)this,
        (float)SLODWORD(msg[1].vfptr),
        (float)SHIDWORD(msg[1].vfptr));
      UFG::UIHKScreenStartFlow::UpdateHelpbar(this);
    }
    else if ( msgId == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
    {
      UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(
        (UFG::UIHKScreenUpgrades *)this,
        (float)SLODWORD(msg[1].vfptr),
        (float)SHIDWORD(msg[1].vfptr));
    }
    if ( v3 )
      return v3;
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  v11 = v10 - 1;
  if ( v11 )
  {
    if ( v11 == 1 && msgId == UI_HASH_DELETE_GAME_COMPLETE_20 )
    {
      this->mState = NUM_CALIBRATION_STATES;
      MovieSafe = UFG::UIScreen::getMovieSafe(this);
      if ( MovieSafe )
        UFG::UIHKScreenStartFlow::StartSaveFileHeaderLoad(this, MovieSafe);
      UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mPopupDialogScreenUID);
    }
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( msgId == UI_HASH_DIALOG_YES_30 )
  {
    v13 = UFG::UIHKScreenStartFlow::GetSelectedSlot(this) - 1;
    if ( v13 == this->mAutoSaveSlotIndex )
      v13 = 4;
    v14 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::DeleteGameData(v14, v13);
    this->mState = NUM_CALIBRATION_STATES|STATE_VOLUME;
    this->mPopupDialogScreenUID = UFG::UIScreenDialogBox::createZeroButtonDialog(
                                    this,
                                    &customCaption,
                                    "$DELETING_SAVE_DATA",
                                    0,
                                    "DialogBox");
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( msgId == UI_HASH_DIALOG_NO_30 )
    goto LABEL_46;
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

// File Line: 313
// RVA: 0x5ED610
void __fastcall UFG::UIHKScreenStartFlow::InitScreen(UFG::UIHKScreenStartFlow *this, Scaleform::GFx::Movie *movie)
{
  hkMemoryResourceContainer *v4; // rax
  int StartingPos; // eax
  int v6; // edi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF

  pargs.pObjectInterface = 0i64;
  pargs.Type = VT_Undefined;
  v4 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
  StartingPos = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v4);
  v6 = StartingPos + 2;
  this->mAutoSaveSlotIndex = StartingPos;
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Number;
  pargs.mValue.NValue = (double)v6;
  Scaleform::GFx::Movie::Invoke(movie, "init", 0i64, &pargs, 1u);
  if ( (pargs.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
}

// File Line: 322
// RVA: 0x6060F0
void __fastcall UFG::UIHKScreenStartFlow::SetHeaderText(UFG::UIHKScreenStartFlow *this, Scaleform::GFx::Movie *movie)
{
  UFG::ProgressionTracker *v3; // rax
  UFG::ProgressionTracker *v4; // rax
  UFG::qPropertySet *GameFlowProperties; // rbx
  unsigned int v6; // eax
  UFG::qArray<unsigned long,0> *v7; // rax
  char *v8; // rax
  const char *v9; // rbx
  unsigned int v10; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h] BYREF
  UFG::qArray<unsigned long,0> flowId; // [rsp+90h] [rbp+18h] BYREF

  v3 = UFG::ProgressionTracker::Instance();
  flowId.size = UFG::ProgressionTracker::GetActiveFlow(v3)->mUID;
  v4 = UFG::ProgressionTracker::Instance();
  GameFlowProperties = UFG::ProgressionTracker::GetGameFlowProperties(v4, &flowId);
  if ( GameFlowProperties )
  {
    v6 = UFG::qStringHash32("Title", 0xFFFFFFFF);
    v7 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&flowId.p, v6);
    v8 = UFG::qPropertySet::Get<char const *>(GameFlowProperties, v7, DEPTH_RECURSE);
    v9 = v8;
    if ( v8 )
    {
      if ( *v8 == 36 )
        v9 = v8 + 1;
      v10 = UFG::qStringHashUpper32(v9, -1);
      m_translator = UFG::UIScreenManager::s_instance->m_translator;
      if ( !m_translator || (v8 = (char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v10)) == 0i64 )
        v8 = (char *)v9;
    }
    pargs.pObjectInterface = 0i64;
    pargs.Type = VT_String;
    pargs.mValue.pString = v8;
    Scaleform::GFx::Movie::Invoke(movie, "SetHeaderText", 0i64, &pargs, 1u);
    if ( (pargs.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        pargs.mValue);
  }
}

// File Line: 338
// RVA: 0x606410
void __fastcall UFG::UIHKScreenStartFlow::SetNewGameSlotText(
        UFG::UIHKScreenStartFlow *this,
        Scaleform::GFx::Movie *movie)
{
  unsigned int v3; // eax
  UFG::UIGfxTranslator *m_translator; // rcx
  const char *v5; // rax
  char v6[16]; // [rsp+28h] [rbp-79h] BYREF
  __int64 v7; // [rsp+38h] [rbp-69h]
  int v8; // [rsp+40h] [rbp-61h]
  char *v9; // [rsp+48h] [rbp-59h]
  __int64 v10; // [rsp+50h] [rbp-51h]
  Scaleform::GFx::Value ptr; // [rsp+58h] [rbp-49h] BYREF
  char v12[16]; // [rsp+88h] [rbp-19h] BYREF
  __int64 v13; // [rsp+98h] [rbp-9h]
  int v14; // [rsp+A0h] [rbp-1h]
  char *v15; // [rsp+A8h] [rbp+7h]
  __int64 v16; // [rsp+B0h] [rbp+Fh]
  char v17[16]; // [rsp+B8h] [rbp+17h] BYREF
  __int64 v18; // [rsp+C8h] [rbp+27h]
  int v19; // [rsp+D0h] [rbp+2Fh]
  char *v20; // [rsp+D8h] [rbp+37h]
  __int64 v21; // [rsp+E0h] [rbp+3Fh]
  __int64 v22; // [rsp+E8h] [rbp+47h]

  v22 = -2i64;
  `eh vector constructor iterator(&ptr.8, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue.pString = 0i64;
  v7 = 0i64;
  v8 = 6;
  v9 = &customCaption;
  if ( (v14 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v13 + 16i64))(v13, v12, v15);
    v13 = 0i64;
  }
  v14 = v8;
  v15 = v9;
  v16 = v10;
  v8 = 0;
  v3 = UFG::qStringHashUpper32("START_NEW_GAME", -1);
  m_translator = UFG::UIScreenManager::s_instance->m_translator;
  if ( !m_translator || (v5 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v3)) == 0i64 )
    v5 = "START_NEW_GAME";
  v7 = 0i64;
  v8 = 6;
  v9 = (char *)v5;
  if ( (v19 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v18 + 16i64))(v18, v17, v20);
    v18 = 0i64;
  }
  v19 = v8;
  v20 = v9;
  v21 = v10;
  if ( (v8 & 0x40) != 0 )
  {
    v18 = v7;
    (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v7 + 8i64))(v7, v17);
  }
  if ( (v8 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v7 + 16i64))(v7, v6, v9);
    v7 = 0i64;
  }
  v8 = 0;
  Scaleform::GFx::Movie::Invoke(movie, "SetSlot", 0i64, &ptr, 3u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 348
// RVA: 0x6070F0
void __fastcall UFG::UIHKScreenStartFlow::SetSaveFileSlotText(
        UFG::UIHKScreenStartFlow *this,
        Scaleform::GFx::Movie *movie,
        int slotNum,
        const char *date,
        const char *fileText)
{
  const char *v8; // rbx
  const char *v9; // rax
  __int64 v10; // rdx
  UFG::UIGfxTranslator *m_translator; // rcx
  int v12[4]; // [rsp+30h] [rbp-91h] BYREF
  __int64 v13; // [rsp+40h] [rbp-81h]
  int ptr; // [rsp+48h] [rbp-79h]
  const char *v15; // [rsp+50h] [rbp-71h]
  __int64 v16; // [rsp+58h] [rbp-69h]
  Scaleform::GFx::Value v17; // [rsp+60h] [rbp-61h] BYREF
  int v18[4]; // [rsp+90h] [rbp-31h] BYREF
  __int64 v19; // [rsp+A0h] [rbp-21h]
  int v20; // [rsp+A8h] [rbp-19h]
  const char *v21; // [rsp+B0h] [rbp-11h]
  __int64 v22; // [rsp+B8h] [rbp-9h]
  int v23[4]; // [rsp+C0h] [rbp-1h] BYREF
  __int64 v24; // [rsp+D0h] [rbp+Fh]
  __int64 v25; // [rsp+D8h] [rbp+17h]
  const char *v26; // [rsp+E0h] [rbp+1Fh]
  __int64 v27; // [rsp+E8h] [rbp+27h]
  __int64 v28; // [rsp+F0h] [rbp+2Fh]

  v28 = -2i64;
  `eh vector constructor iterator(&v17, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v17.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v17.pObjectInterface->vfptr->gap8[8])(
      v17.pObjectInterface,
      &v17,
      v17.mValue);
    v17.pObjectInterface = 0i64;
  }
  v17.Type = VT_Number;
  v17.mValue.NValue = (double)(slotNum + 1);
  v13 = 0i64;
  ptr = 6;
  v15 = date;
  if ( (v20 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, int *, const char *))(*(_QWORD *)v19 + 16i64))(v19, v18, v21);
    v19 = 0i64;
  }
  v20 = ptr;
  v21 = v15;
  v22 = v16;
  ptr = 0;
  v8 = fileText;
  if ( fileText )
  {
    if ( *fileText == 36 )
      v8 = fileText + 1;
    v10 = (unsigned int)UFG::qStringHashUpper32(v8, -1);
    m_translator = UFG::UIScreenManager::s_instance->m_translator;
    if ( !m_translator || (v9 = (const char *)m_translator->vfptr[5].__vecDelDtor(m_translator, v10)) == 0i64 )
      v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v13 = 0i64;
  ptr = 6;
  v15 = v9;
  if ( (v25 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, int *, const char *))(*(_QWORD *)v24 + 16i64))(v24, v23, v26);
    v24 = 0i64;
  }
  LODWORD(v25) = ptr;
  v26 = v15;
  v27 = v16;
  if ( (ptr & 0x40) != 0 )
  {
    v24 = v13;
    (*(void (__fastcall **)(__int64, int *))(*(_QWORD *)v13 + 8i64))(v13, v23);
  }
  if ( (ptr & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, int *, const char *))(*(_QWORD *)v13 + 16i64))(v13, v12, v15);
    v13 = 0i64;
  }
  ptr = 0;
  Scaleform::GFx::Movie::Invoke(movie, "SetSlot", 0i64, &v17, 3u);
  `eh vector destructor iterator(&v17, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 358
// RVA: 0x6121B0
void __fastcall UFG::UIHKScreenStartFlow::StartSaveFileHeaderLoad(
        UFG::UIHKScreenStartFlow *this,
        Scaleform::GFx::Movie *movie)
{
  UFG::GameSaveLoad *v4; // rax
  hkMemoryResourceContainer *v5; // rax
  int v6; // ebx
  __int64 v7; // rdi
  UFG::qString *DateString; // rax
  __m128i systemTime; // [rsp+40h] [rbp-98h]
  UFG::qString result; // [rsp+90h] [rbp-48h] BYREF

  this->mState = STATE_BRIGHTNESS;
  v4 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::LoadAllHeaders(v4);
  v5 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v5);
  v6 = 0;
  v7 = 0i64;
  do
  {
    systemTime = *(__m128i *)&UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[v7].m_State;
    if ( _mm_cvtsi128_si32(systemTime) == 1 )
    {
      DateString = UFG::UI::GetDateString(&result, systemTime.m128i_u64[1], 1);
      UFG::UIHKScreenStartFlow::SetSaveFileSlotText(this, movie, v6, DateString->mData, "$COMMON_LOADING_UPPERCASE");
      UFG::qString::~qString(&result);
    }
    else
    {
      UFG::UIHKScreenStartFlow::SetSaveFileSlotText(this, movie, v6, &customCaption, &customCaption);
    }
    ++v6;
    ++v7;
  }
  while ( v6 < 5 );
}

// File Line: 395
// RVA: 0x5F2B40
void __fastcall UFG::UIHKScreenStartFlow::OnHeaderFileLoadComplete(UFG::UIHKScreenStartFlow *this)
{
  Scaleform::GFx::Movie *MovieSafe; // rsi
  hkMemoryResourceContainer *v3; // rax
  int StartingPos; // eax
  int v5; // edi
  __int64 v6; // r14
  __int64 v7; // rbp
  UFG::GameSaveLoad *v8; // rax
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  const char *v12; // r9
  UFG::qString *DateString; // rax
  UFG::GameSaveLoad *v14; // rax
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx
  const char *v18; // r9
  UFG::qString *v19; // rax
  UFG::qString result; // [rsp+38h] [rbp-F0h] BYREF
  unsigned __int64 systemTime[2]; // [rsp+60h] [rbp-C8h]
  char v22[16]; // [rsp+70h] [rbp-B8h] BYREF
  __int128 v23; // [rsp+80h] [rbp-A8h]
  __int128 v24; // [rsp+90h] [rbp-98h]
  __int128 v25; // [rsp+A0h] [rbp-88h]
  unsigned __int64 v26[2]; // [rsp+B0h] [rbp-78h]
  char v27[16]; // [rsp+C0h] [rbp-68h]
  __int128 v28; // [rsp+D0h] [rbp-58h]
  __int128 v29; // [rsp+E0h] [rbp-48h]
  __int128 v30; // [rsp+F0h] [rbp-38h]

  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  if ( MovieSafe )
  {
    v3 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
    StartingPos = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v3);
    v5 = 0;
    v6 = StartingPos;
    if ( StartingPos > 0 )
    {
      v7 = 0i64;
      while ( 1 )
      {
        v8 = UFG::GameSaveLoad::Instance();
        *(_OWORD *)systemTime = *(_OWORD *)&v8->m_GameSlotHeaderInfo[v7].m_State;
        *(_OWORD *)v22 = *(_OWORD *)v8->m_GameSlotHeaderInfo[v7].m_szLastMissionStringID;
        v23 = *(_OWORD *)&v8->m_GameSlotHeaderInfo[v7].m_szLastMissionStringID[16];
        v24 = *(_OWORD *)&v8->m_GameSlotHeaderInfo[v7].m_szLastMissionStringID[32];
        v25 = *(_OWORD *)&v8->m_GameSlotHeaderInfo[v7].m_szLastMissionStringID[48];
        v9 = _mm_cvtsi128_si32(*(__m128i *)systemTime);
        if ( !v9 )
          break;
        v10 = v9 - 2;
        if ( !v10 )
          break;
        v11 = v10 - 1;
        if ( !v11 )
          break;
        if ( v11 != 2 )
        {
          v12 = "$SAVELOAD_EMPTY_DATE";
LABEL_11:
          UFG::UIHKScreenStartFlow::SetSaveFileSlotText(this, MovieSafe, v5, v12);
          goto LABEL_12;
        }
        UFG::qPrintf("XXX name of the save is  %s", v22);
        DateString = UFG::UI::GetDateString(&result, systemTime[1], 1);
        UFG::UIHKScreenStartFlow::SetSaveFileSlotText(this, MovieSafe, v5, DateString->mData);
        UFG::qString::~qString(&result);
LABEL_12:
        ++v5;
        ++v7;
        if ( !--v6 )
          goto LABEL_13;
      }
      v12 = &customCaption;
      goto LABEL_11;
    }
LABEL_13:
    v14 = UFG::GameSaveLoad::Instance();
    *(_OWORD *)v26 = *(_OWORD *)&v14->m_GameSlotHeaderInfo[4].m_State;
    *(_OWORD *)v27 = *(_OWORD *)v14->m_GameSlotHeaderInfo[4].m_szLastMissionStringID;
    v28 = *(_OWORD *)&v14->m_GameSlotHeaderInfo[4].m_szLastMissionStringID[16];
    v29 = *(_OWORD *)&v14->m_GameSlotHeaderInfo[4].m_szLastMissionStringID[32];
    v30 = *(_OWORD *)&v14->m_GameSlotHeaderInfo[4].m_szLastMissionStringID[48];
    v15 = _mm_cvtsi128_si32(*(__m128i *)v26);
    if ( v15 && (v16 = v15 - 2) != 0 && (v17 = v16 - 1) != 0 )
    {
      if ( v17 == 2 )
      {
        v19 = UFG::UI::GetDateString(&result, v26[1], 1);
        UFG::UIHKScreenStartFlow::SetSaveFileSlotText(this, MovieSafe, this->mAutoSaveSlotIndex, v19->mData);
        UFG::qString::~qString(&result);
LABEL_21:
        UFG::UIHKScreenStartFlow::UpdateHelpbar(this);
        return;
      }
      v18 = "$SAVELOAD_EMPTY_DATE";
    }
    else
    {
      v18 = &customCaption;
    }
    UFG::UIHKScreenStartFlow::SetSaveFileSlotText(this, MovieSafe, this->mAutoSaveSlotIndex, v18);
    goto LABEL_21;
  }
}

// File Line: 484
// RVA: 0x5EC390
__int64 __fastcall UFG::UIHKScreenStartFlow::HandleUserInput(UFG::UIHKScreenStartFlow *this, int messageId)
{
  unsigned __int8 v4; // si
  Scaleform::GFx::Movie *MovieSafe; // rbp
  int SelectedSlot; // eax
  UFG::UIScreenManager *v7; // rbx
  unsigned int v8; // eax
  UFG::GameSaveLoad::eGameSlotNum v9; // ebp
  UFG::UIScreenManager *v10; // rbx
  unsigned int ScreenUID; // eax
  UFG::GameSaveLoad *v12; // rax
  int ZeroButtonDialog; // eax
  int v14; // ebx
  const char *v15; // rdx

  v4 = 0;
  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  if ( !MovieSafe )
    return v4;
  v4 = 1;
  if ( messageId == UI_HASH_DPAD_DOWN_PRESSED_30
    || messageId == UI_HASH_DPAD_DOWN_REPEAT_30
    || messageId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    v15 = "ScrollDown";
    goto LABEL_34;
  }
  if ( messageId == UI_HASH_DPAD_UP_PRESSED_30
    || messageId == UI_HASH_DPAD_UP_REPEAT_30
    || messageId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    v15 = "ScrollUp";
LABEL_34:
    Scaleform::GFx::Movie::Invoke(MovieSafe, v15, 0i64, 0i64, 0);
    UFG::UIHKScreenStartFlow::UpdateHelpbar(this);
    return v4;
  }
  if ( messageId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
    UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, this->mScreenUID);
    this->mState = NUM_CALIBRATION_STATES|STATE_UISCALE;
    return v4;
  }
  if ( messageId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    SelectedSlot = UFG::UIHKScreenStartFlow::GetSelectedSlot(this);
    if ( SelectedSlot != -1 )
    {
      if ( SelectedSlot )
      {
        v9 = SelectedSlot - 1;
        if ( SelectedSlot - 1 == this->mAutoSaveSlotIndex )
          v9 = GAMESLOT_AUTOSAVE;
        if ( _mm_cvtsi128_si32(*(__m128i *)&UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[v9].m_State) == 5 )
        {
          v10 = UFG::UIScreenManager::s_instance;
          ScreenUID = UFG::UIScreenManagerBase::getScreenUID(UFG::UIScreenManager::s_instance, "MainMenu");
          UFG::UIScreenManagerBase::queueMessage(v10, UI_HASH_LOAD_SAVEGAME_20, ScreenUID);
          v12 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::LoadGameSlot(v12, v9);
          ZeroButtonDialog = UFG::UIScreenDialogBox::createZeroButtonDialog(
                               this,
                               &customCaption,
                               "$LOADING_POPUP",
                               0,
                               "DialogBox");
          *(_QWORD *)&this->mState = 2i64;
          this->mPopupDialogScreenUID = ZeroButtonDialog;
        }
      }
      else
      {
        v7 = UFG::UIScreenManager::s_instance;
        v8 = UFG::UIScreenManagerBase::getScreenUID(UFG::UIScreenManager::s_instance, "MainMenu");
        UFG::UIScreenManagerBase::queueMessage(v7, UI_HASH_LOAD_FREEROAM_20, v8);
      }
      return v4;
    }
  }
  else
  {
    if ( messageId != UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
      return 0;
    v14 = UFG::UIHKScreenStartFlow::GetSelectedSlot(this) - 1;
    if ( v14 == this->mAutoSaveSlotIndex )
      v14 = 4;
    if ( _mm_cvtsi128_si32(*(__m128i *)&UFG::GameSaveLoad::Instance()->m_GameSlotHeaderInfo[v14].m_State) == 5 )
    {
      UFG::UIScreenDialogBox::createYesNoDialog(this, &customCaption, "$COMMON_TRC_DELETE_SAVE_FILE", 0, 1);
      this->mState = NUM_CALIBRATION_STATES|STATE_BRIGHTNESS;
      return v4;
    }
  }
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
  return v4;
}

// File Line: 632
// RVA: 0x5E9200
__int64 __fastcall UFG::UIHKScreenStartFlow::GetSelectedSlot(UFG::UIHKScreenStartFlow *this)
{
  Scaleform::GFx::Movie *MovieSafe; // rax
  unsigned int NValue; // ebx
  Scaleform::GFx::Value presult; // [rsp+38h] [rbp-40h] BYREF

  MovieSafe = UFG::UIScreen::getMovieSafe(this);
  if ( !MovieSafe )
    return 0xFFFFFFFFi64;
  presult.pObjectInterface = 0i64;
  presult.Type = VT_Undefined;
  Scaleform::GFx::Movie::Invoke(MovieSafe, "GetSelectedSlot", &presult, 0i64, 0);
  NValue = (int)presult.mValue.NValue;
  if ( (presult.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&presult.pObjectInterface->vfptr->gap8[8])(
      presult.pObjectInterface,
      &presult,
      presult.mValue);
    presult.pObjectInterface = 0i64;
  }
  presult.Type = VT_Undefined;
  return NValue;
}

// File Line: 656
// RVA: 0x61ABE0
void __fastcall UFG::UIHKScreenStartFlow::UpdateHelpbar(UFG::UIHKScreenStartFlow *this)
{
  int SelectedSlot; // ebx
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *v4; // r15
  int v5; // esi
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int v8; // ebx
  UFG::GameSaveLoad *v9; // rax
  __m128i v10; // xmm2
  UFG::UIHKScreenGlobalOverlay *v11; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // r15
  unsigned int v13; // r14d
  int v14; // esi
  unsigned int v15; // edi
  unsigned int v16; // ebx
  UFG::UIHKHelpBarWidget *v17; // r15
  unsigned int v18; // edi
  unsigned int v19; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-B8h] BYREF
  __int128 v21; // [rsp+278h] [rbp+190h]
  __int128 v22; // [rsp+288h] [rbp+1A0h]
  __int128 v23; // [rsp+298h] [rbp+1B0h]
  __int128 v24; // [rsp+2A8h] [rbp+1C0h]

  SelectedSlot = UFG::UIHKScreenStartFlow::GetSelectedSlot(this);
  if ( SelectedSlot )
  {
    v8 = SelectedSlot - 1;
    if ( v8 == this->mAutoSaveSlotIndex )
      v8 = 4;
    v9 = UFG::GameSaveLoad::Instance();
    v10 = *(__m128i *)&v9->m_GameSlotHeaderInfo[v8].m_State;
    v21 = *(_OWORD *)v9->m_GameSlotHeaderInfo[v8].m_szLastMissionStringID;
    v22 = *(_OWORD *)&v9->m_GameSlotHeaderInfo[v8].m_szLastMissionStringID[16];
    v23 = *(_OWORD *)&v9->m_GameSlotHeaderInfo[v8].m_szLastMissionStringID[32];
    v24 = *(_OWORD *)&v9->m_GameSlotHeaderInfo[v8].m_szLastMissionStringID[48];
    v11 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( _mm_cvtsi128_si32(v10) == 5 )
    {
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v11 = &gGlobalOverlaySentinel;
      p_HelpBar = &v11->HelpBar;
      v13 = UI_HASH_BUTTON_BUTTON1_PRESSED_30;
      v14 = UI_HASH_BUTTON_BACK_PRESSED_30;
      v15 = UI_HASH_BUTTON_ACCEPT_PRESSED_30;
      v16 = UFG::qStringHash32("UIHKScreenStartFlow", 0xFFFFFFFF);
      UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
      data.id = v16;
      *(_QWORD *)&data.priority = 0i64;
      *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
      *(_QWORD *)&data.Buttons[4] = 0i64;
      UFG::qString::Set(data.Captions, "$SAVELOAD_LOAD_GAME");
      UFG::qString::Set((UFG::qString *)&data.Captions[0].mMagic, "$COMMON_BACK_UPPERCASE");
      UFG::qString::Set((UFG::qString *)&data.Captions[1].mMagic, "$SAVELOAD_DELETE_GAME");
      UFG::qString::Set((UFG::qString *)&data.Captions[2].mMagic, &customCaption);
      UFG::qString::Set((UFG::qString *)&data.Captions[3].mMagic, &customCaption);
      UFG::qString::Set((UFG::qString *)&data.Captions[4].mMagic, &customCaption);
      data.Icons[5].mMagic = v15;
      data.Icons[5].mLength = v14;
      LODWORD(data.Icons[5].mData) = v13;
      *(char **)((char *)&data.Icons[5].mData + 4) = 0i64;
      data.Icons[5].mStringHashUpper32 = 0;
      UFG::UIHKHelpBarWidget::Show(p_HelpBar, &data);
      UFG::qString::~qString((UFG::qString *)data.MessageIds);
      `eh vector destructor iterator(
        &data.Captions[5].mMagic,
        0x28ui64,
        6,
        (void (__fastcall *)(void *))UFG::qString::~qString);
    }
    else
    {
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v11 = &gGlobalOverlaySentinel;
      v17 = &v11->HelpBar;
      v18 = UI_HASH_BUTTON_BACK_PRESSED_30;
      v19 = UFG::qStringHash32("UIHKScreenStartFlow", 0xFFFFFFFF);
      UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
      data.id = v19;
      *(_QWORD *)&data.priority = 0i64;
      *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
      *(_QWORD *)&data.Buttons[4] = 0i64;
      UFG::qString::Set(data.Captions, "$COMMON_BACK_UPPERCASE");
      UFG::qString::Set((UFG::qString *)&data.Captions[0].mMagic, &customCaption);
      UFG::qString::Set((UFG::qString *)&data.Captions[1].mMagic, &customCaption);
      UFG::qString::Set((UFG::qString *)&data.Captions[2].mMagic, &customCaption);
      UFG::qString::Set((UFG::qString *)&data.Captions[3].mMagic, &customCaption);
      UFG::qString::Set((UFG::qString *)&data.Captions[4].mMagic, &customCaption);
      data.Icons[5].mMagic = v18;
      memset(&data.Icons[5].mLength, 0, 20);
      UFG::UIHKHelpBarWidget::Show(v17, &data);
      UFG::qString::~qString((UFG::qString *)data.MessageIds);
      `eh vector destructor iterator(
        &data.Captions[5].mMagic,
        0x28ui64,
        6,
        (void (__fastcall *)(void *))UFG::qString::~qString);
    }
  }
  else
  {
    v3 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v3 = &gGlobalOverlaySentinel;
    v4 = &v3->HelpBar;
    v5 = UI_HASH_BUTTON_BACK_PRESSED_30;
    v6 = UI_HASH_BUTTON_ACCEPT_PRESSED_30;
    v7 = UFG::qStringHash32("UIHKScreenStartFlow", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v7;
    *(_QWORD *)&data.priority = 0i64;
    *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$START_NEW_GAME_SHORT");
    UFG::qString::Set((UFG::qString *)&data.Captions[0].mMagic, "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)&data.Captions[1].mMagic, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[2].mMagic, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[3].mMagic, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[4].mMagic, &customCaption);
    data.Icons[5].mMagic = v6;
    data.Icons[5].mLength = v5;
    data.Icons[5].mData = 0i64;
    *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
    UFG::UIHKHelpBarWidget::Show(v4, &data);
    UFG::qString::~qString((UFG::qString *)data.MessageIds);
    `eh vector destructor iterator(
      &data.Captions[5].mMagic,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
  }
  `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

