// File Line: 32
// RVA: 0x5C78B0
void __fastcall UFG::UIHKScreenUnlockables::UIHKScreenUnlockables(UFG::UIHKScreenUnlockables *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable';
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenUnlockables::`vftable';
  this->mWindowState = 0;
  this->isLoadingTexture = 0;
  this->callActionScriptLoadTexture = 0;
  UFG::qString::qString(&this->mRewardTexturePack);
}

// File Line: 37
// RVA: 0x5CCE00
void __fastcall UFG::UIHKScreenUnlockables::~UIHKScreenUnlockables(UFG::UIHKScreenUnlockables *this)
{
  UFG::UIHKScreenUnlockables *v1; // rdi
  UFG::UIScreenTextureManager *v2; // rax
  const char *v3; // rbx
  UFG::UIScreenTextureManager *v4; // rax

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenUnlockables::`vftable';
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Unlockables");
  v3 = v1->mRewardTexturePack.mData;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v4, v3);
  UFG::qString::~qString(&v1->mRewardTexturePack);
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 44
// RVA: 0x5F6D00
void __fastcall UFG::UIHKScreenUnlockables::PopulateFileList(UFG::UIHKScreenUnlockables *this)
{
  Scaleform::GFx::Movie *v1; // r15
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *v3; // rbx
  UFG::qSymbol *v4; // rax
  UFG::qPropertyList *v5; // rsi
  unsigned int v6; // edi
  char *v7; // rax
  UFG::qPropertySet *v8; // rbx
  UFG::qSymbol *v9; // rax
  int *v10; // rax
  UFG::qSymbol *v11; // rdx
  signed int v12; // er14
  UFG::qSymbol *v13; // rax
  char *v14; // rax
  UFG::qSymbol *v15; // rbx
  UFG::GameStatTracker *v16; // rax
  bool v17; // bl
  char *v18; // rbx
  UFG::qWiseSymbol v19; // [rsp+30h] [rbp-D0h]
  char ptr; // [rsp+40h] [rbp-C0h]
  __int64 v21; // [rsp+50h] [rbp-B0h]
  unsigned int v22; // [rsp+58h] [rbp-A8h]
  double v23; // [rsp+60h] [rbp-A0h]
  char v24; // [rsp+70h] [rbp-90h]
  __int64 v25; // [rsp+80h] [rbp-80h]
  unsigned int v26; // [rsp+88h] [rbp-78h]
  __int64 v27; // [rsp+90h] [rbp-70h]
  char v28; // [rsp+A0h] [rbp-60h]
  __int64 v29; // [rsp+B0h] [rbp-50h]
  unsigned int v30; // [rsp+B8h] [rbp-48h]
  char *v31; // [rsp+C0h] [rbp-40h]
  __int64 v32; // [rsp+D0h] [rbp-30h]
  UFG::qString v33; // [rsp+D8h] [rbp-28h]
  UFG::qSymbol result; // [rsp+150h] [rbp+50h]
  UFG::qSymbol v35; // [rsp+158h] [rbp+58h]
  UFG::qSymbol v36; // [rsp+160h] [rbp+60h]
  UFG::qSymbol v37; // [rsp+168h] [rbp+68h]

  v32 = -2i64;
  v1 = this->mRenderable->m_movie.pObject;
  v2 = UFG::qSymbol::create_from_string(&result, "UI-UnlockablesBio");
  v3 = UFG::PropertySetManager::GetPropertySet(v2);
  v4 = UFG::qSymbol::create_from_string(&v35, "items");
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, v4, DEPTH_RECURSE);
  v6 = 0;
  if ( v5->mNumElements )
  {
    result.mUID = -1;
    do
    {
      v7 = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v6);
      if ( !v7 || (v8 = (UFG::qPropertySet *)&v7[*(_QWORD *)v7], !*(_QWORD *)v7) )
        v8 = 0i64;
      v9 = UFG::qSymbol::create_from_string(&v36, "UnlockableBioId");
      v10 = UFG::qPropertySet::Get<long>(v8, v9, DEPTH_RECURSE);
      v11 = &result;
      if ( v10 )
        v11 = (UFG::qSymbol *)v10;
      v12 = v11->mUID;
      v13 = UFG::qSymbol::create_from_string(&v37, "DisplayFileName");
      v14 = UFG::qPropertySet::Get<char const *>(v8, v13, DEPTH_RECURSE);
      UFG::qString::FormatEx(&v33, "X:\\Projects\\Reference\\Character\\%s", v14);
      v15 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v19, v12);
      v16 = UFG::GameStatTracker::Instance();
      v17 = UFG::GameStatTracker::GetStat(v16, Collectible_Bio, v15);
      `eh vector constructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (v22 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v21 + 16i64))(
          v21,
          &ptr,
          COERCE_DOUBLE(*(_QWORD *)&v23));
        v21 = 0i64;
      }
      v22 = 5;
      v23 = (double)v12;
      if ( (v26 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v25 + 16i64))(v25, &v24, v27);
        v25 = 0i64;
      }
      v26 = 2;
      LOBYTE(v27) = v17;
      v18 = v33.mData;
      if ( (v30 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v29 + 16i64))(v29, &v28, v31);
        v29 = 0i64;
      }
      v30 = 6;
      v31 = v18;
      Scaleform::GFx::Movie::Invoke(v1, "Unlockables_AddItem", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
      `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      UFG::qString::~qString(&v33);
      ++v6;
    }
    while ( v6 < v5->mNumElements );
  }
  Scaleform::GFx::Movie::Invoke(v1, "Unlockables_Refresh", 0i64, 0i64, 0);
}

// File Line: 71
// RVA: 0x5FDEC0
void __fastcall UFG::UIHKScreenUnlockables::PopulateViews(UFG::UIHKScreenUnlockables *this, int windowState)
{
  int v2; // ebx
  UFG::UIHKScreenUnlockables *v3; // rsi
  Scaleform::GFx::Movie *v4; // rdi
  const char *v5; // rbx
  UFG::UIScreenTextureManager *v6; // rax
  UFG::qString *v7; // rax
  const char *v8; // rbx
  UFG::UIScreenTextureManager *v9; // rax
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v11; // [rsp+40h] [rbp-A8h]
  unsigned int v12; // [rsp+48h] [rbp-A0h]
  __int64 v13; // [rsp+50h] [rbp-98h]
  char v14; // [rsp+60h] [rbp-88h]
  __int64 v15; // [rsp+68h] [rbp-80h]
  __int64 v16; // [rsp+70h] [rbp-78h]
  unsigned int v17; // [rsp+78h] [rbp-70h]
  __int64 v18; // [rsp+88h] [rbp-60h]
  unsigned int v19; // [rsp+90h] [rbp-58h]
  __int64 v20; // [rsp+98h] [rbp-50h]
  Scaleform::GFx::Value pval; // [rsp+A8h] [rbp-40h]
  __int64 v22; // [rsp+D8h] [rbp-10h]
  UFG::qString result; // [rsp+E0h] [rbp-8h]
  UFG::qString v24; // [rsp+108h] [rbp+20h]

  v22 = -2i64;
  v2 = windowState;
  v3 = this;
  v4 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( v2 )
  {
    switch ( v2 )
    {
      case 1:
        if ( (v12 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
          v11 = 0i64;
        }
        v12 = 2;
        LOBYTE(v13) = 1;
        if ( (v17 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, &v14, v15);
          v16 = 0i64;
        }
        v17 = 2;
        LOBYTE(v15) = 0;
        if ( (v19 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v18 + 16i64))(v18, &v17, v20);
          v18 = 0i64;
        }
        v19 = 2;
        LOBYTE(v20) = 0;
        Scaleform::GFx::Movie::Invoke(v4, "SetupUnlockablesView", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
        break;
      case 2:
        if ( (v12 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
          v11 = 0i64;
        }
        v12 = 2;
        LOBYTE(v13) = 1;
        if ( (v17 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, &v14, v15);
          v16 = 0i64;
        }
        v17 = 2;
        LOBYTE(v15) = 1;
        if ( (v19 >> 6) & 1 )
        {
          (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v18 + 16i64))(v18, &v17, v20);
          v18 = 0i64;
        }
        v19 = 2;
        LOBYTE(v20) = 0;
        Scaleform::GFx::Movie::Invoke(v4, "SetupUnlockablesView", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
        v5 = v3->mRewardTexturePack.mData;
        v6 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::ReleaseTexturePack(v6, v5);
        break;
      case 3:
        pval.pObjectInterface = 0i64;
        pval.Type = 0;
        Scaleform::GFx::Movie::GetVariable(v4, &pval, "gUnlockableBioId");
        UFG::qString::FormatEx(&result, "Unlockables_Attachment_%02d", (unsigned int)(signed int)pval.mValue.NValue);
        v7 = UFG::qString::FormatEx(&v24, "Data\\UI\\%s_tp.perm.bin", result.mData);
        UFG::qString::Set(&v3->mRewardTexturePack, v7->mData, v7->mLength, 0i64, 0);
        UFG::qString::~qString(&v24);
        v8 = v3->mRewardTexturePack.mData;
        v9 = UFG::UIScreenTextureManager::Instance();
        UFG::UIScreenTextureManager::QueueTexturePackLoad(
          v9,
          v8,
          HIGH_PRIORITY,
          UFG::UIHKScreenUnlockables::TextureLoaded,
          v3);
        v3->isLoadingTexture = 1;
        UFG::qString::~qString(&result);
        if ( ((unsigned int)pval.Type >> 6) & 1 )
        {
          (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
            pval.pObjectInterface,
            &pval,
            *(_QWORD *)&pval.mValue.NValue);
          pval.pObjectInterface = 0i64;
        }
        pval.Type = 0;
        break;
    }
  }
  else
  {
    if ( (v12 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v13);
      v11 = 0i64;
    }
    v12 = 2;
    LOBYTE(v13) = 0;
    if ( (v17 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, &v14, v15);
      v16 = 0i64;
    }
    v17 = 2;
    LOBYTE(v15) = 0;
    if ( (v19 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, unsigned int *, __int64))(*(_QWORD *)v18 + 16i64))(v18, &v17, v20);
      v18 = 0i64;
    }
    v19 = 2;
    LOBYTE(v20) = 0;
    Scaleform::GFx::Movie::Invoke(v4, "SetupUnlockablesView", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
  }
  Scaleform::GFx::Movie::Invoke(v4, "Unlockables_Refresh", 0i64, 0i64, 0);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 117
// RVA: 0x636BA0
void __fastcall UFG::UIHKScreenUnlockables::init(UFG::UIHKScreenUnlockables *this, UFG::UICommandData *data)
{
  UFG::UICommandData *v2; // rbx
  UFG::UIHKScreenUnlockables *v3; // rdi
  UFG::UIHKScreenGlobalOverlay *v4; // rax
  UFG::UIHKHelpBarWidget *v5; // rdi
  unsigned int v6; // ebx
  UFG::UIHKHelpBarData dataa; // [rsp+40h] [rbp-258h]

  v2 = data;
  v3 = this;
  UFG::UI::PauseGame(0i64);
  UFG::UIScreen::init((UFG::UIScreen *)&v3->vfptr, v2);
  UFG::UIHKScreenUnlockables::PopulateFileList(v3);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0x4A3D1F6Cu,
      0i64,
      0,
      0i64);
  v4 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v4 = &gGlobalOverlaySentinel;
  v5 = &v4->HelpBar;
  v6 = UFG::qStringHash32("UIHKScreenUnlockables", 0xFFFFFFFF);
  UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
  dataa.id = v6;
  *(_QWORD *)&dataa.priority = 0i64;
  _mm_store_si128((__m128i *)dataa.Buttons, _mm_load_si128((const __m128i *)&_xmm));
  *(_QWORD *)&dataa.Buttons[4] = 0i64;
  UFG::qString::Set(dataa.Captions, "$COMMON_SELECT_UPPERCASE");
  UFG::qString::Set(&dataa.Captions[1], "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set(&dataa.Captions[2], &customWorldMapCaption);
  UFG::qString::Set(&dataa.Captions[3], &customWorldMapCaption);
  UFG::qString::Set(&dataa.Captions[4], &customWorldMapCaption);
  UFG::qString::Set(&dataa.Captions[5], &customWorldMapCaption);
  *(_QWORD *)dataa.MessageIds = 0i64;
  *(_QWORD *)&dataa.MessageIds[2] = 0i64;
  *(_QWORD *)&dataa.MessageIds[4] = 0i64;
  UFG::UIHKHelpBarWidget::Show(v5, &dataa);
  UFG::qString::~qString(&dataa.CustomTexturePack);
  `eh vector destructor iterator'(dataa.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator'(dataa.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 137
// RVA: 0x638FA0
void __fastcall UFG::UIHKScreenUnlockables::outro(UFG::UIHKScreenUnlockables *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *v2; // rbx
  unsigned int v3; // eax

  UFG::UIScreen::outro((UFG::UIScreen *)&this->vfptr, 0i64);
  v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = &gGlobalOverlaySentinel;
  v2 = &v1->HelpBar;
  v3 = UFG::qStringHash32("UIHKScreenUnlockables", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v2, v3);
}

// File Line: 145
// RVA: 0x6401F0
void __fastcall UFG::UIHKScreenUnlockables::update(UFG::UIHKScreenUnlockables *this, float elapsed)
{
  UFG::UIHKScreenUnlockables *v2; // rbx
  Scaleform::GFx::Movie *v3; // rdi
  char *v4; // rsi
  char ptr; // [rsp+30h] [rbp-B8h]
  __int64 v6; // [rsp+40h] [rbp-A8h]
  unsigned int v7; // [rsp+48h] [rbp-A0h]
  char *v8; // [rsp+50h] [rbp-98h]
  Scaleform::GFx::Value pval; // [rsp+60h] [rbp-88h]
  unsigned int v10; // [rsp+90h] [rbp-58h]
  __int64 v11; // [rsp+98h] [rbp-50h]
  char v12; // [rsp+A8h] [rbp-40h]
  __int64 v13; // [rsp+B8h] [rbp-30h]
  unsigned int v14; // [rsp+C0h] [rbp-28h]
  __int64 v15; // [rsp+C8h] [rbp-20h]
  char v16; // [rsp+D8h] [rbp-10h]
  __int64 v17; // [rsp+E8h] [rbp+0h]
  unsigned int v18; // [rsp+F0h] [rbp+8h]
  __int64 v19; // [rsp+F8h] [rbp+10h]
  __int64 v20; // [rsp+108h] [rbp+20h]
  UFG::qString result; // [rsp+110h] [rbp+28h]

  v20 = -2i64;
  v2 = this;
  UFG::UIScreen::update((UFG::UIScreen *)&this->vfptr, elapsed);
  if ( v2->callActionScriptLoadTexture )
  {
    v3 = v2->mRenderable->m_movie.pObject;
    pval.pObjectInterface = 0i64;
    pval.Type = 0;
    Scaleform::GFx::Movie::GetVariable(v3, &pval, "gUnlockableBioId");
    UFG::qString::FormatEx(&result, "Unlockables_Attachment_%02d", (unsigned int)(signed int)*(double *)&pval.pNext);
    `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v4 = result.mData;
    if ( (v7 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v6 + 16i64))(v6, &ptr, v8);
      v6 = 0i64;
    }
    v7 = 6;
    v8 = v4;
    Scaleform::GFx::Movie::Invoke(v3, "LoadRewardTexture", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
    `eh vector constructor iterator'(&pval.Type, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v10 >> 6) & 1 )
    {
      (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, __int64))(*(_QWORD *)pval.DataAux
                                                                                            + 16i64))(
        pval.DataAux,
        &pval.Type,
        v11);
      pval.DataAux = 0i64;
    }
    v10 = 2;
    LOBYTE(v11) = 1;
    if ( (v14 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v13 + 16i64))(v13, &v12, v15);
      v13 = 0i64;
    }
    v14 = 2;
    LOBYTE(v15) = 1;
    if ( (v18 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v17 + 16i64))(v17, &v16, v19);
      v17 = 0i64;
    }
    v18 = 2;
    LOBYTE(v19) = 1;
    Scaleform::GFx::Movie::Invoke(v3, "SetupUnlockablesView", 0i64, (Scaleform::GFx::Value *)((char *)&pval + 24), 3u);
    Scaleform::GFx::Movie::Invoke(v3, "Unlockables_Refresh", 0i64, 0i64, 0);
    v2->callActionScriptLoadTexture = 0;
    `eh vector destructor iterator'(&pval.Type, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&result);
    if ( ((unsigned int)pval.Type >> 6) & 1 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.pNext);
  }
}

// File Line: 173
// RVA: 0x62D3E0
bool __fastcall UFG::UIHKScreenUnlockables::handleMessage(UFG::UIHKScreenUnlockables *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbp
  unsigned int v4; // esi
  UFG::UIHKScreenUnlockables *v5; // rbx
  Scaleform::GFx::Movie *v6; // rcx
  int v7; // edx
  UFG::UI *v8; // rcx
  int v9; // edx
  int v11; // edx
  int v12; // edx
  const char *v13; // rdx
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-40h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( this->isLoadingTexture )
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&this->vfptr, msgId, msg);
  v6 = this->mRenderable->m_movie.pObject;
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    v7 = v5->mWindowState;
    if ( v7 )
    {
      v9 = v7 - 1;
      v5->mWindowState = v9;
      UFG::UIHKScreenUnlockables::PopulateViews(v5, v9);
      if ( !UFG::HudAudio::m_instance )
        return 1;
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xA4E5BFBD,
        0i64,
        0,
        0i64);
    }
    else
    {
      ((void (__fastcall *)(UFG::UIHKScreenUnlockables *))v5->vfptr[1].__vecDelDtor)(v5);
      UFG::UI::UnpauseGame(v8);
      v5->mFinished = 1;
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xC415B16F,
        0i64,
        0,
        0i64);
    return 1;
  }
  if ( msgId != UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    if ( msgId == UI_HASH_DPAD_UP_PRESSED_30
      || msgId == UI_HASH_DPAD_UP_REPEAT_30
      || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
    {
      if ( v5->mWindowState == 1 )
      {
        v13 = "UnlockablesList_ScrollPrev";
LABEL_30:
        Scaleform::GFx::Movie::Invoke(v6, v13, 0i64, 0i64, 0);
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xC415B16F,
            0i64,
            0,
            0i64);
        goto LABEL_32;
      }
    }
    else if ( (msgId == UI_HASH_DPAD_DOWN_PRESSED_30
            || msgId == UI_HASH_DPAD_DOWN_REPEAT_30
            || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30)
           && v5->mWindowState == 1 )
    {
      v13 = "UnlockablesList_ScrollNext";
      goto LABEL_30;
    }
LABEL_32:
    msg = v3;
    msgId = v4;
    this = v5;
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&this->vfptr, msgId, msg);
  }
  if ( v5->mWindowState < 3 )
  {
    pval.pObjectInterface = 0i64;
    pval.Type = 0;
    Scaleform::GFx::Movie::GetVariable(v6, &pval, "gUnlocked");
    v11 = v5->mWindowState;
    if ( v11 != 1 || pval.mValue.BValue )
    {
      v12 = v11 + 1;
      v5->mWindowState = v12;
      UFG::UIHKScreenUnlockables::PopulateViews(v5, v12);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0x4A3D1F6Cu,
          0i64,
          0,
          0i64);
    }
    if ( ((unsigned int)pval.Type >> 6) & 1 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        *(_QWORD *)&pval.mValue.NValue);
      pval.pObjectInterface = 0i64;
    }
    pval.Type = 0;
  }
  return 1;
}

// File Line: 247
// RVA: 0x6127C0
void __fastcall UFG::UIHKScreenUnlockables::TextureLoaded(UFG::DataStreamer::Handle *handle, void *param)
{
  *((_BYTE *)param + 156) = 0;
  *((_BYTE *)param + 157) = 1;
}

