// File Line: 50
// RVA: 0x5C7780
void __fastcall UFG::UIHKScreenStartFlow::UIHKScreenStartFlow(UFG::UIHKScreenStartFlow *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable';
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenStartFlow::`vftable';
  *(_QWORD *)&this->mState = 0i64;
  this->mAutoSaveSlotIndex = 0;
}

// File Line: 57
// RVA: 0x5CCCD0
void __fastcall UFG::UIHKScreenStartFlow::~UIHKScreenStartFlow(UFG::UIHKScreenStartFlow *this)
{
  UFG::UIHKScreenStartFlow *v1; // rbx
  UFG::UIHKScreenGlobalOverlay *v2; // rax
  UFG::UIHKHelpBarWidget *v3; // rdi
  unsigned int v4; // eax
  UFG::UIScreenTextureManager *v5; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenStartFlow::`vftable';
  v2 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v2 = &gGlobalOverlaySentinel;
  v3 = &v2->HelpBar;
  v4 = UFG::qStringHash32("UIHKScreenStartFlow", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v3, v4);
  v5 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v5, "StartFlowScreen");
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 65
// RVA: 0x636940
void __fastcall UFG::UIHKScreenStartFlow::init(UFG::UIHKScreenStartFlow *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenStartFlow *v2; // rbx
  Scaleform::GFx::Movie *v3; // rax
  Scaleform::GFx::Movie *v4; // rdi

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v2->mState = 0;
  v3 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&v2->vfptr);
  v4 = v3;
  if ( v3 )
  {
    UFG::UIHKScreenStartFlow::StartSaveFileHeaderLoad(v2, v3);
    UFG::UIHKScreenStartFlow::InitScreen(v2, v4);
    UFG::UIHKScreenStartFlow::SetHeaderText(v2, v4);
    UFG::UIHKScreenStartFlow::SetNewGameSlotText(v2, v4);
    UFG::UIHKScreenStartFlow::UpdateHelpbar(v2);
  }
}

// File Line: 86
// RVA: 0x640150
void __fastcall UFG::UIHKScreenStartFlow::update(UFG::UIHKScreenStartFlow *this, float elapsed)
{
  UFG::UIHKScreenStartFlow *v2; // rbx
  __int32 v3; // ecx
  float v4; // xmm0_4

  v2 = this;
  v3 = this->mState - 2;
  if ( v3 )
  {
    if ( v3 == 1 )
    {
      v4 = elapsed + v2->mLoadTimeElapsed;
      v2->mLoadTimeElapsed = v4;
      if ( v4 > 2.0 )
      {
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v2->mPopupDialogScreenUID);
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v2->mScreenUID);
        v2->mState = 7;
      }
    }
  }
  else
  {
    v2->mLoadTimeElapsed = elapsed + v2->mLoadTimeElapsed;
  }
  UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
}

// File Line: 125
// RVA: 0x62CDF0
char __fastcall UFG::UIHKScreenStartFlow::handleMessage(UFG::UIHKScreenStartFlow *this, unsigned int msgId, UFG::UIMessage *msg)
{
  char v3; // bl
  UFG::UIMessage *v4; // rbp
  unsigned int v5; // esi
  UFG::UIHKScreenStartFlow *v6; // rdi
  __int32 v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  Scaleform::GFx::Movie *v12; // rax
  unsigned int v13; // ebx
  UFG::GameSaveLoad *v14; // rax
  UFG::UIScreen *v15; // rax
  UFG::UIHKScreenGlobalOverlay *v16; // rcx
  UFG::UIScreenManager *v17; // rbx
  unsigned int v18; // eax
  UFG::UI *v19; // rcx

  v3 = 0;
  v4 = msg;
  v5 = msgId;
  v6 = this;
  if ( !this->mRenderable->m_movie.pObject )
    return 0;
  v8 = this->mState - 1;
  if ( !v8 )
  {
    if ( msgId != -339696135 )
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
    UFG::UIHKScreenStartFlow::OnHeaderFileLoadComplete(v6);
    ++v6->mInputEnabled;
    goto LABEL_46;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    if ( msgId == 1552074461 )
    {
      v17 = UFG::UIScreenManager::s_instance;
      v18 = UFG::UIScreenManagerBase::getScreenUID(
              (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
              "MainMenu");
      UFG::UIScreenManagerBase::queueMessage((UFG::UIScreenManagerBase *)&v17->vfptr, UI_HASH_LOAD_COMPLETE_20, v18);
      UFG::UI::HandleGameCheckpointRestore(v19);
      if ( v6->mLoadTimeElapsed <= 2.0 )
      {
        v6->mState = 3;
      }
      else
      {
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v6->mPopupDialogScreenUID);
        UFG::UIScreenManagerBase::queuePopScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          v6->mScreenUID);
        v6->mState = 7;
      }
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
    }
    if ( msgId != 1323471633 )
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      0xFFFFFFFF);
LABEL_46:
    v6->mState = 4;
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
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
      v3 = UFG::UIHKScreenStartFlow::HandleUserInput(v6, msgId);
    }
    v15 = UFG::UIScreenManagerBase::getOverlay(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            "GlobalOverlay");
    if ( v15 )
    {
      v16 = UFG::UIHKScreenGlobalOverlay::mThis;
      if ( !UFG::UIHKScreenGlobalOverlay::mThis )
        v16 = &gGlobalOverlaySentinel;
      UFG::UIHKHelpBarWidget::HandleMessage(&v16->HelpBar, v15, v5, v4);
    }
    if ( v5 == UI_HASH_MOUSE_MOVE_30 )
    {
      UFG::UIHKScreenUpgrades::Flash_HandleMouseMove(
        (UFG::UIHKScreenUpgrades *)v6,
        (float)SLODWORD(v4[1].vfptr),
        (float)SHIDWORD(v4[1].vfptr));
      UFG::UIHKScreenStartFlow::UpdateHelpbar(v6);
    }
    else if ( v5 == UI_HASH_MOUSE_BUTTON_LEFT_PRESSED_30 )
    {
      UFG::UIHKScreenSaveLoad::Flash_HandleMouseClick(
        (UFG::UIHKScreenUpgrades *)v6,
        (float)SLODWORD(v4[1].vfptr),
        (float)SHIDWORD(v4[1].vfptr));
    }
    if ( v3 )
      return v3;
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
  }
  v11 = v10 - 1;
  if ( v11 )
  {
    if ( v11 == 1 && msgId == UI_HASH_DELETE_GAME_COMPLETE_20 )
    {
      v6->mState = 4;
      v12 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&v6->vfptr);
      if ( v12 )
        UFG::UIHKScreenStartFlow::StartSaveFileHeaderLoad(v6, v12);
      UFG::UIScreenManagerBase::queuePopScreen(
        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
        v6->mPopupDialogScreenUID);
    }
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
  }
  if ( msgId == UI_HASH_DIALOG_YES_30 )
  {
    v13 = (unsigned __int64)UFG::UIHKScreenStartFlow::GetSelectedSlot(v6) - 1;
    if ( v13 == v6->mAutoSaveSlotIndex )
      v13 = 4;
    v14 = UFG::GameSaveLoad::Instance();
    UFG::GameSaveLoad::DeleteGameData(v14, v13);
    v6->mState = 6;
    v6->mPopupDialogScreenUID = UFG::UIScreenDialogBox::createZeroButtonDialog(
                                  (UFG::UIScreen *)&v6->vfptr,
                                  &customWorldMapCaption,
                                  "$DELETING_SAVE_DATA",
                                  0,
                                  "DialogBox");
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
  }
  if ( msgId == UI_HASH_DIALOG_NO_30 )
    goto LABEL_46;
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v6->vfptr, v5, v4);
}

// File Line: 313
// RVA: 0x5ED610
void __fastcall UFG::UIHKScreenStartFlow::InitScreen(UFG::UIHKScreenStartFlow *this, Scaleform::GFx::Movie *movie)
{
  Scaleform::GFx::Movie *v2; // rsi
  UFG::UIHKScreenStartFlow *v3; // rbx
  hkMemoryResourceContainer *v4; // rax
  int v5; // eax
  int v6; // edi
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]

  v2 = movie;
  v3 = this;
  pargs.pObjectInterface = 0i64;
  pargs.Type = 0;
  v4 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
  v5 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v4);
  v6 = v5 + 2;
  v3->mAutoSaveSlotIndex = v5;
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 5;
  pargs.mValue.NValue = (double)v6;
  Scaleform::GFx::Movie::Invoke(v2, "init", 0i64, &pargs, 1u);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
}

// File Line: 322
// RVA: 0x6060F0
void __fastcall UFG::UIHKScreenStartFlow::SetHeaderText(UFG::UIHKScreenStartFlow *this, Scaleform::GFx::Movie *movie)
{
  Scaleform::GFx::Movie *v2; // rdi
  UFG::ProgressionTracker *v3; // rax
  UFG::ProgressionTracker *v4; // rax
  UFG::qPropertySet *v5; // rbx
  unsigned int v6; // eax
  UFG::qSymbol *v7; // rax
  char *v8; // rax
  const char *v9; // rbx
  unsigned int v10; // eax
  UFG::UIGfxTranslator *v11; // rcx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-40h]
  UFG::qSymbol flowId; // [rsp+90h] [rbp+18h]
  UFG::qWiseSymbol result; // [rsp+98h] [rbp+20h]

  v2 = movie;
  v3 = UFG::ProgressionTracker::Instance();
  flowId.mUID = UFG::ProgressionTracker::GetActiveFlow(v3)->mUID;
  v4 = UFG::ProgressionTracker::Instance();
  v5 = UFG::ProgressionTracker::GetGameFlowProperties(v4, &flowId);
  if ( v5 )
  {
    v6 = UFG::qStringHash32("Title", 0xFFFFFFFF);
    v7 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, v6);
    v8 = UFG::qPropertySet::Get<char const *>(v5, v7, DEPTH_RECURSE);
    v9 = v8;
    if ( v8 )
    {
      if ( *v8 == 36 )
        v9 = v8 + 1;
      v10 = UFG::qStringHashUpper32(v9, 0xFFFFFFFF);
      v11 = UFG::UIScreenManager::s_instance->m_translator;
      if ( !v11 || (v8 = (char *)v11->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, v10)) == 0i64 )
        v8 = (char *)v9;
    }
    pargs.pObjectInterface = 0i64;
    pargs.Type = 6;
    *(_QWORD *)&pargs.mValue.NValue = v8;
    Scaleform::GFx::Movie::Invoke(v2, "SetHeaderText", 0i64, &pargs, 1u);
    if ( ((unsigned int)pargs.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
        pargs.pObjectInterface,
        &pargs,
        *(_QWORD *)&pargs.mValue.NValue);
  }
}

// File Line: 338
// RVA: 0x606410
void __fastcall UFG::UIHKScreenStartFlow::SetNewGameSlotText(UFG::UIHKScreenStartFlow *this, Scaleform::GFx::Movie *movie)
{
  Scaleform::GFx::Movie *v2; // rbx
  unsigned int v3; // eax
  UFG::UIGfxTranslator *v4; // rcx
  const char *v5; // rax
  char v6; // [rsp+28h] [rbp-79h]
  __int64 v7; // [rsp+38h] [rbp-69h]
  unsigned int v8; // [rsp+40h] [rbp-61h]
  char *v9; // [rsp+48h] [rbp-59h]
  __int64 v10; // [rsp+50h] [rbp-51h]
  char ptr; // [rsp+58h] [rbp-49h]
  __int64 v12; // [rsp+60h] [rbp-41h]
  __int64 v13; // [rsp+68h] [rbp-39h]
  unsigned int v14; // [rsp+70h] [rbp-31h]
  __int64 v15; // [rsp+78h] [rbp-29h]
  char v16; // [rsp+88h] [rbp-19h]
  __int64 v17; // [rsp+98h] [rbp-9h]
  unsigned int v18; // [rsp+A0h] [rbp-1h]
  char *v19; // [rsp+A8h] [rbp+7h]
  __int64 v20; // [rsp+B0h] [rbp+Fh]
  char v21; // [rsp+B8h] [rbp+17h]
  __int64 v22; // [rsp+C8h] [rbp+27h]
  unsigned int v23; // [rsp+D0h] [rbp+2Fh]
  char *v24; // [rsp+D8h] [rbp+37h]
  __int64 v25; // [rsp+E0h] [rbp+3Fh]
  __int64 v26; // [rsp+E8h] [rbp+47h]

  v26 = -2i64;
  v2 = movie;
  `eh vector constructor iterator'(&v12, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v14 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v13 + 16i64))(v13, &ptr, v15);
    v13 = 0i64;
  }
  v14 = 5;
  v15 = 0i64;
  v7 = 0i64;
  v8 = 6;
  v9 = &customWorldMapCaption;
  if ( (v18 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v17 + 16i64))(v17, &v16, v19);
    v17 = 0i64;
  }
  v18 = v8;
  v19 = v9;
  v20 = v10;
  if ( (v8 >> 6) & 1 )
  {
    v17 = v7;
    (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v7 + 8i64))(v7, &v16);
  }
  if ( (v8 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v7 + 16i64))(v7, &v6, v9);
    v7 = 0i64;
  }
  v8 = 0;
  v3 = UFG::qStringHashUpper32("START_NEW_GAME", 0xFFFFFFFF);
  v4 = UFG::UIScreenManager::s_instance->m_translator;
  if ( !v4 || (v5 = (const char *)v4->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, v3)) == 0i64 )
    v5 = "START_NEW_GAME";
  v7 = 0i64;
  v8 = 6;
  v9 = (char *)v5;
  if ( (v23 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v22 + 16i64))(v22, &v21, v24);
    v22 = 0i64;
  }
  v23 = v8;
  v24 = v9;
  v25 = v10;
  if ( (v8 >> 6) & 1 )
  {
    v22 = v7;
    (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v7 + 8i64))(v7, &v21);
  }
  if ( (v8 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v7 + 16i64))(v7, &v6, v9);
    v7 = 0i64;
  }
  v8 = 0;
  Scaleform::GFx::Movie::Invoke(v2, "SetSlot", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 348
// RVA: 0x6070F0
void __fastcall UFG::UIHKScreenStartFlow::SetSaveFileSlotText(UFG::UIHKScreenStartFlow *this, Scaleform::GFx::Movie *movie, int slotNum, const char *date)
{
  const char *v4; // rbx
  int v5; // edi
  Scaleform::GFx::Movie *v6; // rsi
  const char *v7; // rbx
  __int64 v8; // rax
  __int64 v9; // rdx
  UFG::UIGfxTranslator *v10; // rcx
  unsigned int v11; // [rsp+30h] [rbp-79h]
  __int64 v12; // [rsp+38h] [rbp-71h]
  __int64 v13; // [rsp+40h] [rbp-69h]
  char ptr; // [rsp+48h] [rbp-61h]
  __int64 v15; // [rsp+58h] [rbp-51h]
  unsigned int v16; // [rsp+60h] [rbp-49h]
  double v17; // [rsp+68h] [rbp-41h]
  char v18; // [rsp+78h] [rbp-31h]
  __int64 v19; // [rsp+88h] [rbp-21h]
  unsigned int v20; // [rsp+90h] [rbp-19h]
  __int64 v21; // [rsp+98h] [rbp-11h]
  __int64 v22; // [rsp+A0h] [rbp-9h]
  char v23; // [rsp+A8h] [rbp-1h]
  __int64 v24; // [rsp+B8h] [rbp+Fh]
  unsigned int v25; // [rsp+C0h] [rbp+17h]
  __int64 v26; // [rsp+C8h] [rbp+1Fh]
  __int64 v27; // [rsp+D0h] [rbp+27h]
  __int64 v28; // [rsp+D8h] [rbp+2Fh]
  char *str; // [rsp+128h] [rbp+7Fh]

  v28 = -2i64;
  v4 = date;
  v5 = slotNum;
  v6 = movie;
  `eh vector constructor iterator'(&v16, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v16 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v15 + 16i64))(
      v15,
      &ptr,
      COERCE_DOUBLE(*(_QWORD *)&v17));
    v15 = 0i64;
  }
  v16 = 5;
  v17 = (double)(v5 + 1);
  v13 = 0i64;
  v11 = 6;
  v12 = (__int64)v4;
  if ( (v20 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
    v19 = 0i64;
  }
  v20 = v11;
  v21 = v12;
  v22 = v13;
  if ( (v11 >> 6) & 1 )
  {
    v19 = v13;
    (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v13 + 8i64))(v13, &v18);
  }
  if ( (v11 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v13 + 16i64))(v13, &v11, v12);
    v13 = 0i64;
  }
  v11 = 0;
  v7 = str;
  if ( str )
  {
    if ( *str == 36 )
      v7 = str + 1;
    v9 = (unsigned int)UFG::qStringHashUpper32(v7, 0xFFFFFFFF);
    v10 = UFG::UIScreenManager::s_instance->m_translator;
    if ( !v10 || (v8 = (__int64)v10->vfptr[5].__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, v9)) == 0 )
      v8 = (__int64)v7;
  }
  else
  {
    v8 = 0i64;
  }
  v13 = 0i64;
  v11 = 6;
  v12 = v8;
  if ( (v25 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v24 + 16i64))(v24, &v23, v26);
    v24 = 0i64;
  }
  v25 = v11;
  v26 = v12;
  v27 = v13;
  if ( (v11 >> 6) & 1 )
  {
    v24 = v13;
    (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v13 + 8i64))(v13, &v23);
  }
  if ( (v11 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v13 + 16i64))(v13, &v11, v12);
    v13 = 0i64;
  }
  v11 = 0;
  Scaleform::GFx::Movie::Invoke(v6, "SetSlot", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 358
// RVA: 0x6121B0
void __fastcall UFG::UIHKScreenStartFlow::StartSaveFileHeaderLoad(UFG::UIHKScreenStartFlow *this, Scaleform::GFx::Movie *movie)
{
  Scaleform::GFx::Movie *v2; // rbp
  UFG::UIHKScreenStartFlow *v3; // rsi
  UFG::GameSaveLoad *v4; // rax
  hkMemoryResourceContainer *v5; // rax
  int v6; // ebx
  __int64 v7; // rdi
  UFG::GameSaveLoad *v8; // rax
  __int128 v9; // ST50_16
  __int128 v10; // ST60_16
  __int128 v11; // xmm0
  __int128 v12; // ST80_16
  int v13; // ecx
  UFG::qString *v14; // rax
  __m128i systemTime; // [rsp+40h] [rbp-98h]
  UFG::qString result; // [rsp+90h] [rbp-48h]

  v2 = movie;
  v3 = this;
  this->mState = 1;
  v4 = UFG::GameSaveLoad::Instance();
  UFG::GameSaveLoad::LoadAllHeaders(v4);
  v5 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v5);
  v6 = 0;
  v7 = 0i64;
  do
  {
    v8 = UFG::GameSaveLoad::Instance();
    systemTime = *(__m128i *)&v8->m_GameSlotHeaderInfo[v7].m_State;
    v9 = *(_OWORD *)v8->m_GameSlotHeaderInfo[v7].m_szLastMissionStringID;
    v10 = *(_OWORD *)&v8->m_GameSlotHeaderInfo[v7].m_szLastMissionStringID[16];
    v11 = *(_OWORD *)&v8->m_GameSlotHeaderInfo[v7].m_szLastMissionStringID[32];
    v12 = *(_OWORD *)&v8->m_GameSlotHeaderInfo[v7].m_szLastMissionStringID[48];
    v13 = _mm_cvtsi128_si32(systemTime);
    if ( v13 && v13 == 1 )
    {
      v14 = UFG::UI::GetDateString(&result, systemTime.m128i_u64[1], 1);
      UFG::UIHKScreenStartFlow::SetSaveFileSlotText(v3, v2, v6, v14->mData);
      UFG::qString::~qString(&result);
    }
    else
    {
      UFG::UIHKScreenStartFlow::SetSaveFileSlotText(v3, v2, v6, &customWorldMapCaption);
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
  UFG::UIHKScreenStartFlow *v1; // rbx
  Scaleform::GFx::Movie *v2; // rsi
  hkMemoryResourceContainer *v3; // rax
  int v4; // eax
  int v5; // edi
  __int64 v6; // r14
  __int64 v7; // rbp
  UFG::GameSaveLoad *v8; // rax
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  const char *v13; // r9
  UFG::qString *v14; // rax
  UFG::GameSaveLoad *v15; // rax
  int v16; // ecx
  int v17; // ecx
  int v18; // ecx
  int v19; // ecx
  const char *v20; // r9
  UFG::qString *v21; // rax
  UFG::qString result; // [rsp+38h] [rbp-F0h]
  unsigned __int64 systemTime[2]; // [rsp+60h] [rbp-C8h]
  char v24[16]; // [rsp+70h] [rbp-B8h]
  __int128 v25; // [rsp+80h] [rbp-A8h]
  __int128 v26; // [rsp+90h] [rbp-98h]
  __int128 v27; // [rsp+A0h] [rbp-88h]
  unsigned __int64 v28[2]; // [rsp+B0h] [rbp-78h]
  char v29[16]; // [rsp+C0h] [rbp-68h]
  __int128 v30; // [rsp+D0h] [rbp-58h]
  __int128 v31; // [rsp+E0h] [rbp-48h]
  __int128 v32; // [rsp+F0h] [rbp-38h]

  v1 = this;
  v2 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&this->vfptr);
  if ( v2 )
  {
    v3 = (hkMemoryResourceContainer *)UFG::GameSaveLoad::Instance();
    v4 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos(v3);
    v5 = 0;
    v6 = v4;
    if ( v4 > 0 )
    {
      v7 = 0i64;
      while ( 1 )
      {
        v8 = UFG::GameSaveLoad::Instance();
        *(_OWORD *)systemTime = *(_OWORD *)&v8->m_GameSlotHeaderInfo[v7].m_State;
        *(_OWORD *)v24 = *(_OWORD *)v8->m_GameSlotHeaderInfo[v7].m_szLastMissionStringID;
        v25 = *(_OWORD *)&v8->m_GameSlotHeaderInfo[v7].m_szLastMissionStringID[16];
        v26 = *(_OWORD *)&v8->m_GameSlotHeaderInfo[v7].m_szLastMissionStringID[32];
        v27 = *(_OWORD *)&v8->m_GameSlotHeaderInfo[v7].m_szLastMissionStringID[48];
        v9 = _mm_cvtsi128_si32(*(__m128i *)systemTime);
        if ( !v9 )
          break;
        v10 = v9 - 2;
        if ( !v10 )
          break;
        v11 = v10 - 1;
        if ( !v11 )
          break;
        v12 = v11 - 1;
        if ( !v12 || v12 != 1 )
        {
          v13 = "$SAVELOAD_EMPTY_DATE";
LABEL_12:
          UFG::UIHKScreenStartFlow::SetSaveFileSlotText(v1, v2, v5, v13);
          goto LABEL_13;
        }
        UFG::qPrintf("XXX name of the save is  %s", v24);
        v14 = UFG::UI::GetDateString(&result, systemTime[1], 1);
        UFG::UIHKScreenStartFlow::SetSaveFileSlotText(v1, v2, v5, v14->mData);
        UFG::qString::~qString(&result);
LABEL_13:
        ++v5;
        ++v7;
        if ( !--v6 )
          goto LABEL_14;
      }
      v13 = &customWorldMapCaption;
      goto LABEL_12;
    }
LABEL_14:
    v15 = UFG::GameSaveLoad::Instance();
    *(_OWORD *)v28 = *(_OWORD *)&v15->m_GameSlotHeaderInfo[4].m_State;
    *(_OWORD *)v29 = *(_OWORD *)v15->m_GameSlotHeaderInfo[4].m_szLastMissionStringID;
    v30 = *(_OWORD *)&v15->m_GameSlotHeaderInfo[4].m_szLastMissionStringID[16];
    v31 = *(_OWORD *)&v15->m_GameSlotHeaderInfo[4].m_szLastMissionStringID[32];
    v32 = *(_OWORD *)&v15->m_GameSlotHeaderInfo[4].m_szLastMissionStringID[48];
    v16 = _mm_cvtsi128_si32(*(__m128i *)v28);
    if ( v16 && (v17 = v16 - 2) != 0 && (v18 = v17 - 1) != 0 )
    {
      v19 = v18 - 1;
      if ( v19 && v19 == 1 )
      {
        v21 = UFG::UI::GetDateString(&result, v28[1], 1);
        UFG::UIHKScreenStartFlow::SetSaveFileSlotText(v1, v2, v1->mAutoSaveSlotIndex, v21->mData);
        UFG::qString::~qString(&result);
LABEL_23:
        UFG::UIHKScreenStartFlow::UpdateHelpbar(v1);
        return;
      }
      v20 = "$SAVELOAD_EMPTY_DATE";
    }
    else
    {
      v20 = &customWorldMapCaption;
    }
    UFG::UIHKScreenStartFlow::SetSaveFileSlotText(v1, v2, v1->mAutoSaveSlotIndex, v20);
    goto LABEL_23;
  }
}

// File Line: 484
// RVA: 0x5EC390
__int64 __fastcall UFG::UIHKScreenStartFlow::HandleUserInput(UFG::UIHKScreenStartFlow *this, int messageId)
{
  int v2; // ebx
  UFG::UIHKScreenStartFlow *v3; // rdi
  unsigned __int8 v4; // si
  Scaleform::GFx::Movie *v5; // rbp
  int v6; // eax
  UFG::UIScreenManager *v7; // rbx
  unsigned int v8; // eax
  int v9; // ebp
  UFG::GameSaveLoad *v10; // rax
  __int128 v11; // ST40_16
  __int128 v12; // ST50_16
  __int128 v13; // xmm0
  __int128 v14; // ST70_16
  UFG::UIScreenManager *v15; // rbx
  unsigned int v16; // eax
  UFG::GameSaveLoad *v17; // rax
  int v18; // eax
  signed int v19; // ebx
  UFG::GameSaveLoad *v20; // rax
  __int128 v21; // ST40_16
  __int128 v22; // ST50_16
  __int128 v23; // xmm0
  __int128 v24; // ST70_16
  const char *v25; // rdx

  v2 = messageId;
  v3 = this;
  v4 = 0;
  v5 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&this->vfptr);
  if ( !v5 )
    return v4;
  v4 = 1;
  if ( v2 == UI_HASH_DPAD_DOWN_PRESSED_30 || v2 == UI_HASH_DPAD_DOWN_REPEAT_30 || v2 == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    v25 = "ScrollDown";
    goto LABEL_34;
  }
  if ( v2 == UI_HASH_DPAD_UP_PRESSED_30 || v2 == UI_HASH_DPAD_UP_REPEAT_30 || v2 == UI_HASH_THUMBSTICK_LEFT_UP_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    v25 = "ScrollUp";
LABEL_34:
    Scaleform::GFx::Movie::Invoke(v5, v25, 0i64, 0i64, 0);
    UFG::UIHKScreenStartFlow::UpdateHelpbar(v3);
    return v4;
  }
  if ( v2 == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xA4E5BFBD,
        0i64,
        0,
        0i64);
    UFG::UIScreenManagerBase::queuePopScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      v3->mScreenUID);
    v3->mState = 7;
    return v4;
  }
  if ( v2 == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    v6 = UFG::UIHKScreenStartFlow::GetSelectedSlot(v3);
    if ( v6 != -1 )
    {
      if ( v6 )
      {
        v9 = v6 - 1;
        if ( v6 - 1 == v3->mAutoSaveSlotIndex )
          v9 = 4;
        v10 = UFG::GameSaveLoad::Instance();
        v11 = *(_OWORD *)v10->m_GameSlotHeaderInfo[v9].m_szLastMissionStringID;
        v12 = *(_OWORD *)&v10->m_GameSlotHeaderInfo[v9].m_szLastMissionStringID[16];
        v13 = *(_OWORD *)&v10->m_GameSlotHeaderInfo[v9].m_szLastMissionStringID[32];
        v14 = *(_OWORD *)&v10->m_GameSlotHeaderInfo[v9].m_szLastMissionStringID[48];
        if ( _mm_cvtsi128_si32(*(__m128i *)&v10->m_GameSlotHeaderInfo[v9].m_State) == 5 )
        {
          v15 = UFG::UIScreenManager::s_instance;
          v16 = UFG::UIScreenManagerBase::getScreenUID(
                  (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                  "MainMenu");
          UFG::UIScreenManagerBase::queueMessage((UFG::UIScreenManagerBase *)&v15->vfptr, UI_HASH_LOAD_SAVEGAME_20, v16);
          v17 = UFG::GameSaveLoad::Instance();
          UFG::GameSaveLoad::LoadGameSlot(v17, (UFG::GameSaveLoad::eGameSlotNum)v9);
          v18 = UFG::UIScreenDialogBox::createZeroButtonDialog(
                  (UFG::UIScreen *)&v3->vfptr,
                  &customWorldMapCaption,
                  "$LOADING_POPUP",
                  0,
                  "DialogBox");
          *(_QWORD *)&v3->mState = 2i64;
          v3->mPopupDialogScreenUID = v18;
        }
      }
      else
      {
        v7 = UFG::UIScreenManager::s_instance;
        v8 = UFG::UIScreenManagerBase::getScreenUID(
               (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
               "MainMenu");
        UFG::UIScreenManagerBase::queueMessage((UFG::UIScreenManagerBase *)&v7->vfptr, UI_HASH_LOAD_FREEROAM_20, v8);
      }
      return v4;
    }
  }
  else
  {
    if ( v2 != UI_HASH_BUTTON_BUTTON1_PRESSED_30 )
      return 0;
    v19 = (unsigned __int64)UFG::UIHKScreenStartFlow::GetSelectedSlot(v3) - 1;
    if ( v19 == v3->mAutoSaveSlotIndex )
      v19 = 4;
    v20 = UFG::GameSaveLoad::Instance();
    v21 = *(_OWORD *)v20->m_GameSlotHeaderInfo[v19].m_szLastMissionStringID;
    v22 = *(_OWORD *)&v20->m_GameSlotHeaderInfo[v19].m_szLastMissionStringID[16];
    v23 = *(_OWORD *)&v20->m_GameSlotHeaderInfo[v19].m_szLastMissionStringID[32];
    v24 = *(_OWORD *)&v20->m_GameSlotHeaderInfo[v19].m_szLastMissionStringID[48];
    if ( _mm_cvtsi128_si32(*(__m128i *)&v20->m_GameSlotHeaderInfo[v19].m_State) == 5 )
    {
      UFG::UIScreenDialogBox::createYesNoDialog(
        (UFG::UIScreen *)&v3->vfptr,
        &customWorldMapCaption,
        "$COMMON_TRC_DELETE_SAVE_FILE",
        0,
        1);
      v3->mState = 5;
      return v4;
    }
  }
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xA4E5BFBD,
      0i64,
      0,
      0i64);
  return v4;
}

// File Line: 632
// RVA: 0x5E9200
signed __int64 __fastcall UFG::UIHKScreenStartFlow::GetSelectedSlot(UFG::UIHKScreenStartFlow *this)
{
  Scaleform::GFx::Movie *v1; // rax
  unsigned int v2; // ebx
  Scaleform::GFx::Value presult; // [rsp+38h] [rbp-40h]

  v1 = UFG::UIScreen::getMovieSafe((UFG::UIScreen *)&this->vfptr);
  if ( !v1 )
    return 0xFFFFFFFFi64;
  presult.pObjectInterface = 0i64;
  presult.Type = 0;
  Scaleform::GFx::Movie::Invoke(v1, "GetSelectedSlot", &presult, 0i64, 0);
  v2 = (signed int)presult.mValue.NValue;
  if ( ((unsigned int)presult.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&presult.pObjectInterface->vfptr->gap8[8])(
      presult.pObjectInterface,
      &presult,
      *(_QWORD *)&presult.mValue.NValue);
    presult.pObjectInterface = 0i64;
  }
  presult.Type = 0;
  return v2;
}

// File Line: 656
// RVA: 0x61ABE0
void __fastcall UFG::UIHKScreenStartFlow::UpdateHelpbar(UFG::UIHKScreenStartFlow *this)
{
  UFG::UIHKScreenStartFlow *v1; // rdi
  int v2; // ebx
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *v4; // r15
  int v5; // esi
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int v8; // ebx
  UFG::GameSaveLoad *v9; // rax
  __m128i v10; // xmm2
  UFG::UIHKScreenGlobalOverlay *v11; // rax
  UFG::UIHKHelpBarWidget *v12; // r15
  unsigned int v13; // er14
  int v14; // esi
  unsigned int v15; // edi
  unsigned int v16; // ebx
  UFG::UIHKHelpBarWidget *v17; // r15
  unsigned int v18; // edi
  unsigned int v19; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-B8h]
  __int128 v21; // [rsp+278h] [rbp+190h]
  __int128 v22; // [rsp+288h] [rbp+1A0h]
  __int128 v23; // [rsp+298h] [rbp+1B0h]
  __int128 v24; // [rsp+2A8h] [rbp+1C0h]

  v1 = this;
  v2 = UFG::UIHKScreenStartFlow::GetSelectedSlot(this);
  if ( v2 )
  {
    v8 = v2 - 1;
    if ( v8 == v1->mAutoSaveSlotIndex )
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
      v12 = &v11->HelpBar;
      v13 = UI_HASH_BUTTON_BUTTON1_PRESSED_30;
      v14 = UI_HASH_BUTTON_BACK_PRESSED_30;
      v15 = UI_HASH_BUTTON_ACCEPT_PRESSED_30;
      v16 = UFG::qStringHash32("UIHKScreenStartFlow", 0xFFFFFFFF);
      UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
      data.id = v16;
      *(_QWORD *)&data.priority = 0i64;
      _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
      *(_QWORD *)&data.Buttons[4] = 0i64;
      UFG::qString::Set(data.Captions, "$SAVELOAD_LOAD_GAME");
      UFG::qString::Set((UFG::qString *)((char *)data.Captions + 16), "$COMMON_BACK_UPPERCASE");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 16), "$SAVELOAD_DELETE_GAME");
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 16), &customWorldMapCaption);
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 16), &customWorldMapCaption);
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 16), &customWorldMapCaption);
      data.Icons[5].mMagic = v15;
      data.Icons[5].mLength = v14;
      LODWORD(data.Icons[5].mData) = v13;
      *(char **)((char *)&data.Icons[5].mData + 4) = 0i64;
      data.Icons[5].mStringHashUpper32 = 0;
      UFG::UIHKHelpBarWidget::Show(v12, &data);
      UFG::qString::~qString((UFG::qString *)data.MessageIds);
      `eh vector destructor iterator'(
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
      _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
      *(_QWORD *)&data.Buttons[4] = 0i64;
      UFG::qString::Set(data.Captions, "$COMMON_BACK_UPPERCASE");
      UFG::qString::Set((UFG::qString *)((char *)data.Captions + 16), &customWorldMapCaption);
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 16), &customWorldMapCaption);
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 16), &customWorldMapCaption);
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 16), &customWorldMapCaption);
      UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 16), &customWorldMapCaption);
      data.Icons[5].mMagic = v18;
      *(_OWORD *)&data.Icons[5].mLength = 0ui64;
      data.Icons[5].mStringHashUpper32 = 0;
      UFG::UIHKHelpBarWidget::Show(v17, &data);
      UFG::qString::~qString((UFG::qString *)data.MessageIds);
      `eh vector destructor iterator'(
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
    _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$START_NEW_GAME_SHORT");
    UFG::qString::Set((UFG::qString *)((char *)data.Captions + 16), "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 16), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 16), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 16), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 16), &customWorldMapCaption);
    data.Icons[5].mMagic = v6;
    data.Icons[5].mLength = v5;
    data.Icons[5].mData = 0i64;
    *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
    UFG::UIHKHelpBarWidget::Show(v4, &data);
    UFG::qString::~qString((UFG::qString *)data.MessageIds);
    `eh vector destructor iterator'(
      &data.Captions[5].mMagic,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
  }
  `eh vector destructor iterator'(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

