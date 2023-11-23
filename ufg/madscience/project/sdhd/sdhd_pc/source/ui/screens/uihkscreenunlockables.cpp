// File Line: 32
// RVA: 0x5C78B0
void __fastcall UFG::UIHKScreenUnlockables::UIHKScreenUnlockables(UFG::UIHKScreenUnlockables *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKTaskableScreen::`vftable;
  this->mFinished = 0;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenUnlockables::`vftable;
  this->mWindowState = 0;
  this->isLoadingTexture = 0;
  this->callActionScriptLoadTexture = 0;
  UFG::qString::qString(&this->mRewardTexturePack);
}

// File Line: 37
// RVA: 0x5CCE00
void __fastcall UFG::UIHKScreenUnlockables::~UIHKScreenUnlockables(UFG::UIHKScreenUnlockables *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  char *mData; // rbx
  UFG::UIScreenTextureManager *v4; // rax

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenUnlockables::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Unlockables");
  mData = this->mRewardTexturePack.mData;
  v4 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseTexturePack(v4, mData);
  UFG::qString::~qString(&this->mRewardTexturePack);
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 44
// RVA: 0x5F6D00
void __fastcall UFG::UIHKScreenUnlockables::PopulateFileList(UFG::UIHKScreenUnlockables *this)
{
  Scaleform::GFx::Movie *pObject; // r15
  UFG::qSymbol *v2; // rax
  UFG::qPropertySet *PropertySet; // rbx
  UFG::qArray<unsigned long,0> *v4; // rax
  UFG::qPropertyList *v5; // rsi
  unsigned int v6; // edi
  char *ValuePtr; // rax
  UFG::qPropertySet *v8; // rbx
  UFG::qArray<unsigned long,0> *v9; // rax
  int *v10; // rax
  UFG::qSymbol *p_result; // rdx
  signed int mUID; // r14d
  UFG::qArray<unsigned long,0> *v13; // rax
  char *v14; // rax
  UFG::qSymbol *v15; // rbx
  UFG::GameStatTracker *v16; // rax
  bool Stat; // bl
  char *mData; // rbx
  UFG::qWiseSymbol v19; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-C0h] BYREF
  char v21[16]; // [rsp+70h] [rbp-90h] BYREF
  __int64 v22; // [rsp+80h] [rbp-80h]
  int v23; // [rsp+88h] [rbp-78h]
  __int64 v24; // [rsp+90h] [rbp-70h]
  char v25[16]; // [rsp+A0h] [rbp-60h] BYREF
  __int64 v26; // [rsp+B0h] [rbp-50h]
  int v27; // [rsp+B8h] [rbp-48h]
  char *v28; // [rsp+C0h] [rbp-40h]
  __int64 v29; // [rsp+D0h] [rbp-30h]
  UFG::qString v30; // [rsp+D8h] [rbp-28h] BYREF
  UFG::qSymbol result; // [rsp+150h] [rbp+50h] BYREF
  UFG::qSymbol v32; // [rsp+158h] [rbp+58h] BYREF
  UFG::qSymbol v33; // [rsp+160h] [rbp+60h] BYREF
  UFG::qSymbol v34; // [rsp+168h] [rbp+68h] BYREF

  v29 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  v2 = UFG::qSymbol::create_from_string(&result, "UI-UnlockablesBio");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v2);
  v4 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v32, "items");
  v5 = UFG::qPropertySet::Get<UFG::qPropertyList>(PropertySet, v4, DEPTH_RECURSE);
  v6 = 0;
  if ( v5->mNumElements )
  {
    result.mUID = -1;
    do
    {
      ValuePtr = UFG::qPropertyList::GetValuePtr(v5, 0x1Au, v6);
      if ( !ValuePtr || (v8 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
        v8 = 0i64;
      v9 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v33, "UnlockableBioId");
      v10 = UFG::qPropertySet::Get<long>(v8, v9, DEPTH_RECURSE);
      p_result = &result;
      if ( v10 )
        p_result = (UFG::qSymbol *)v10;
      mUID = p_result->mUID;
      v13 = (UFG::qArray<unsigned long,0> *)UFG::qSymbol::create_from_string(&v34, "DisplayFileName");
      v14 = UFG::qPropertySet::Get<char const *>(v8, v13, DEPTH_RECURSE);
      UFG::qString::FormatEx(&v30, "X:\\Projects\\Reference\\Character\\%s", v14);
      v15 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&v19, mUID);
      v16 = UFG::GameStatTracker::Instance();
      Stat = UFG::GameStatTracker::GetStat(v16, Collectible_Bio, v15);
      `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Number;
      ptr.mValue.NValue = (double)mUID;
      if ( (v23 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v22 + 16i64))(v22, v21, v24);
        v22 = 0i64;
      }
      v23 = 2;
      LOBYTE(v24) = Stat;
      mData = v30.mData;
      if ( (v27 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v26 + 16i64))(v26, v25, v28);
        v26 = 0i64;
      }
      v27 = 6;
      v28 = mData;
      Scaleform::GFx::Movie::Invoke(pObject, "Unlockables_AddItem", 0i64, &ptr, 3u);
      `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
      UFG::qString::~qString(&v30);
      ++v6;
    }
    while ( v6 < v5->mNumElements );
  }
  Scaleform::GFx::Movie::Invoke(pObject, "Unlockables_Refresh", 0i64, 0i64, 0);
}ements );
  }
  Scaleform::GFx::Movie::Invoke

// File Line: 71
// RVA: 0x5FDEC0
void __fastcall UFG::UIHKScreenUnlockables::PopulateViews(UFG::UIHKScreenUnlockables *this, int windowState)
{
  Scaleform::GFx::Movie *pObject; // rdi
  char *mData; // rbx
  UFG::UIScreenTextureManager *v6; // rax
  UFG::qString *v7; // rax
  char *v8; // rbx
  UFG::UIScreenTextureManager *v9; // rax
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  char v11[8]; // [rsp+60h] [rbp-88h] BYREF
  __int64 v12; // [rsp+68h] [rbp-80h]
  __int64 v13; // [rsp+70h] [rbp-78h]
  int v14[4]; // [rsp+78h] [rbp-70h] BYREF
  __int64 v15; // [rsp+88h] [rbp-60h]
  int v16; // [rsp+90h] [rbp-58h]
  __int64 v17; // [rsp+98h] [rbp-50h]
  Scaleform::GFx::Value pval; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v19; // [rsp+D8h] [rbp-10h]
  UFG::qString result; // [rsp+E0h] [rbp-8h] BYREF
  UFG::qString v21; // [rsp+108h] [rbp+20h] BYREF

  v19 = -2i64;
  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  switch ( windowState )
  {
    case 0:
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Boolean;
      ptr.mValue.BValue = 0;
      if ( (v14[0] & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v13 + 16i64))(v13, v11, v12);
        v13 = 0i64;
      }
      v14[0] = 2;
      LOBYTE(v12) = 0;
      if ( (v16 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v15 + 16i64))(v15, v14, v17);
        v15 = 0i64;
      }
LABEL_8:
      v16 = 2;
      LOBYTE(v17) = 0;
      Scaleform::GFx::Movie::Invoke(pObject, "SetupUnlockablesView", 0i64, &ptr, 3u);
      break;
    case 1:
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Boolean;
      ptr.mValue.BValue = 1;
      if ( (v14[0] & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v13 + 16i64))(v13, v11, v12);
        v13 = 0i64;
      }
      v14[0] = 2;
      LOBYTE(v12) = 0;
      if ( (v16 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v15 + 16i64))(v15, v14, v17);
        v15 = 0i64;
      }
      goto LABEL_8;
    case 2:
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_Boolean;
      ptr.mValue.BValue = 1;
      if ( (v14[0] & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v13 + 16i64))(v13, v11, v12);
        v13 = 0i64;
      }
      v14[0] = 2;
      LOBYTE(v12) = 1;
      if ( (v16 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, int *, __int64))(*(_QWORD *)v15 + 16i64))(v15, v14, v17);
        v15 = 0i64;
      }
      v16 = 2;
      LOBYTE(v17) = 0;
      Scaleform::GFx::Movie::Invoke(pObject, "SetupUnlockablesView", 0i64, &ptr, 3u);
      mData = this->mRewardTexturePack.mData;
      v6 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::ReleaseTexturePack(v6, mData);
      break;
    case 3:
      pval.pObjectInterface = 0i64;
      pval.Type = VT_Undefined;
      Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gUnlockableBioId");
      UFG::qString::FormatEx(&result, "Unlockables_Attachment_%02d", (unsigned int)(int)pval.mValue.NValue);
      v7 = UFG::qString::FormatEx(&v21, "Data\\UI\\%s_tp.perm.bin", result.mData);
      UFG::qString::Set(&this->mRewardTexturePack, v7->mData, v7->mLength, 0i64, 0);
      UFG::qString::~qString(&v21);
      v8 = this->mRewardTexturePack.mData;
      v9 = UFG::UIScreenTextureManager::Instance();
      UFG::UIScreenTextureManager::QueueTexturePackLoad(
        v9,
        v8,
        HIGH_PRIORITY,
        (UFG::qReflectInventoryBase *)UFG::UIHKScreenUnlockables::TextureLoaded,
        (UFG::qReflectInventoryBase *)this);
      this->isLoadingTexture = 1;
      UFG::qString::~qString(&result);
      if ( (pval.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
          pval.pObjectInterface,
          &pval,
          pval.mValue);
        pval.pObjectInterface = 0i64;
      }
      pval.Type = VT_Undefined;
      break;
  }
  Scaleform::GFx::Movie::Invoke(pObject, "Unlockables_Refresh", 0i64, 0i64, 0);
  `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 117
// RVA: 0x636BA0
void __fastcall UFG::UIHKScreenUnlockables::init(UFG::UIHKScreenUnlockables *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenGlobalOverlay *v4; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v6; // ebx
  UFG::UIHKHelpBarData dataa; // [rsp+40h] [rbp-258h] BYREF

  UFG::UI::PauseGame(0i64);
  UFG::UIScreen::init(this, data);
  UFG::UIHKScreenUnlockables::PopulateFileList(this);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
  v4 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v4 = &gGlobalOverlaySentinel;
  p_HelpBar = &v4->HelpBar;
  v6 = UFG::qStringHash32("UIHKScreenUnlockables", 0xFFFFFFFF);
  UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
  dataa.id = v6;
  *(_QWORD *)&dataa.priority = 0i64;
  *(__m128i *)dataa.Buttons = _mm_load_si128((const __m128i *)&_xmm);
  *(_QWORD *)&dataa.Buttons[4] = 0i64;
  UFG::qString::Set(dataa.Captions, "$COMMON_SELECT_UPPERCASE");
  UFG::qString::Set(&dataa.Captions[1], "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set(&dataa.Captions[2], &customCaption);
  UFG::qString::Set(&dataa.Captions[3], &customCaption);
  UFG::qString::Set(&dataa.Captions[4], &customCaption);
  UFG::qString::Set(&dataa.Captions[5], &customCaption);
  memset(dataa.MessageIds, 0, sizeof(dataa.MessageIds));
  UFG::UIHKHelpBarWidget::Show(p_HelpBar, &dataa);
  UFG::qString::~qString(&dataa.CustomTexturePack);
  `eh vector destructor iterator(dataa.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(dataa.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 137
// RVA: 0x638FA0
void __fastcall UFG::UIHKScreenUnlockables::outro(UFG::UIHKScreenUnlockables *this)
{
  UFG::UIHKScreenGlobalOverlay *v1; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v3; // eax

  UFG::UIScreen::outro(this, 0i64);
  v1 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v1 = &gGlobalOverlaySentinel;
  p_HelpBar = &v1->HelpBar;
  v3 = UFG::qStringHash32("UIHKScreenUnlockables", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v3);
}

// File Line: 145
// RVA: 0x6401F0
void __fastcall UFG::UIHKScreenUnlockables::update(UFG::UIHKScreenUnlockables *this, float elapsed)
{
  Scaleform::GFx::Movie *pObject; // rdi
  char *mData; // rsi
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::GFx::Value pval; // [rsp+60h] [rbp-88h] BYREF
  int v7; // [rsp+90h] [rbp-58h]
  __int64 v8; // [rsp+98h] [rbp-50h]
  char v9[16]; // [rsp+A8h] [rbp-40h] BYREF
  __int64 v10; // [rsp+B8h] [rbp-30h]
  int v11; // [rsp+C0h] [rbp-28h]
  __int64 v12; // [rsp+C8h] [rbp-20h]
  char v13[16]; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v14; // [rsp+E8h] [rbp+0h]
  int v15; // [rsp+F0h] [rbp+8h]
  __int64 v16; // [rsp+F8h] [rbp+10h]
  __int64 v17; // [rsp+108h] [rbp+20h]
  UFG::qString result; // [rsp+110h] [rbp+28h] BYREF

  v17 = -2i64;
  UFG::UIScreen::update(this, elapsed);
  if ( this->callActionScriptLoadTexture )
  {
    pObject = this->mRenderable->m_movie.pObject;
    pval.pObjectInterface = 0i64;
    pval.Type = VT_Undefined;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gUnlockableBioId");
    UFG::qString::FormatEx(&result, "Unlockables_Attachment_%02d", (unsigned int)(int)*(double *)&pval.pNext);
    `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    mData = result.mData;
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
    Scaleform::GFx::Movie::Invoke(pObject, "LoadRewardTexture", 0i64, &ptr, 1u);
    `eh vector constructor iterator(&pval.Type, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    if ( (v7 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(unsigned __int64, Scaleform::GFx::Value::ValueType *, __int64))(*(_QWORD *)pval.DataAux
                                                                                            + 16i64))(
        pval.DataAux,
        &pval.Type,
        v8);
      pval.DataAux = 0i64;
    }
    v7 = 2;
    LOBYTE(v8) = 1;
    if ( (v11 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v10 + 16i64))(v10, v9, v12);
      v10 = 0i64;
    }
    v11 = 2;
    LOBYTE(v12) = 1;
    if ( (v15 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v14 + 16i64))(v14, v13, v16);
      v14 = 0i64;
    }
    v15 = 2;
    LOBYTE(v16) = 1;
    Scaleform::GFx::Movie::Invoke(pObject, "SetupUnlockablesView", 0i64, (Scaleform::GFx::Value *)&pval.Type, 3u);
    Scaleform::GFx::Movie::Invoke(pObject, "Unlockables_Refresh", 0i64, 0i64, 0);
    this->callActionScriptLoadTexture = 0;
    `eh vector destructor iterator(&pval.Type, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    UFG::qString::~qString(&result);
    if ( (pval.Type & 0x40) != 0 )
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value *))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.pNext);
  }
}

// File Line: 173
// RVA: 0x62D3E0
bool __fastcall UFG::UIHKScreenUnlockables::handleMessage(
        UFG::UIHKScreenUnlockables *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbp
  unsigned int v4; // esi
  UFG::UIHKScreenUnlockables *v5; // rbx
  Scaleform::GFx::Movie *pObject; // rcx
  int mWindowState; // edx
  UFG::UI *v8; // rcx
  int v9; // edx
  int v11; // edx
  int v12; // edx
  const char *v13; // rdx
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-40h] BYREF

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( this->isLoadingTexture )
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  pObject = this->mRenderable->m_movie.pObject;
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    mWindowState = v5->mWindowState;
    if ( mWindowState )
    {
      v9 = mWindowState - 1;
      v5->mWindowState = v9;
      UFG::UIHKScreenUnlockables::PopulateViews(v5, v9);
      if ( !UFG::HudAudio::m_instance )
        return 1;
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
    }
    else
    {
      ((void (__fastcall *)(UFG::UIHKScreenUnlockables *))v5->vfptr[1].__vecDelDtor)(v5);
      UFG::UI::UnpauseGame(v8);
      v5->mFinished = 1;
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
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
        Scaleform::GFx::Movie::Invoke(pObject, v13, 0i64, 0i64, 0);
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xC415B16F, 0i64, 0, 0i64);
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
    msg = v3;
    msgId = v4;
    this = v5;
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( v5->mWindowState < 3 )
  {
    pval.pObjectInterface = 0i64;
    pval.Type = VT_Undefined;
    Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gUnlocked");
    v11 = v5->mWindowState;
    if ( v11 != 1 || pval.mValue.BValue )
    {
      v12 = v11 + 1;
      v5->mWindowState = v12;
      UFG::UIHKScreenUnlockables::PopulateViews(v5, v12);
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
    }
    if ( (pval.Type & 0x40) != 0 )
    {
      (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
        pval.pObjectInterface,
        &pval,
        pval.mValue);
      pval.pObjectInterface = 0i64;
    }
    pval.Type = VT_Undefined;
  }
  return 1;
}

// File Line: 247
// RVA: 0x6127C0
void __fastcall UFG::UIHKScreenUnlockables::TextureLoaded(UFG::DataStreamer::Handle *handle, _BYTE *param)
{
  param[156] = 0;
  param[157] = 1;
}

