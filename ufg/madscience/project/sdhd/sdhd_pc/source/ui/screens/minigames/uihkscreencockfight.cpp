// File Line: 54
// RVA: 0x5C4B70
void __fastcall UFG::UIHKScreenCockFight::UIHKScreenCockFight(UFG::UIHKScreenCockFight *this)
{
  hkgpIndexedMeshDefinitions::Edge *v1; // rdx
  hkgpIndexedMesh::EdgeBarrier *v2; // rcx
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h] BYREF

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable;
  *(_QWORD *)&this->mfAlphaValue = 1109393408i64;
  ++UFG::UIHKMinigameScreen::mNumMinigameScreens;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenCockFight::`vftable;
  this->mState = STATE_INIT;
  this->mIsReady = 0;
  this->mSelectedFighterIndex = 1;
  this->mFighterArray.p = 0i64;
  *(_QWORD *)&this->mFighterArray.size = 0i64;
  this->mSelectedFighter = 0i64;
  this->mBird1Names.p = 0i64;
  *(_QWORD *)&this->mBird1Names.size = 0i64;
  this->mTrainer1Names.p = 0i64;
  *(_QWORD *)&this->mTrainer1Names.size = 0i64;
  this->mBird1Types.p = 0i64;
  *(_QWORD *)&this->mBird1Types.size = 0i64;
  this->mBird2Names.p = 0i64;
  *(_QWORD *)&this->mBird2Names.size = 0i64;
  this->mTrainer2Names.p = 0i64;
  *(_QWORD *)&this->mTrainer2Names.size = 0i64;
  this->mBird2Types.p = 0i64;
  *(_QWORD *)&this->mBird2Types.size = 0i64;
  *(_QWORD *)&this->mCurrentBet = 0i64;
  this->mSavedControllerMode = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum]->m_ActiveMapSet;
  UFG::SetInputMode(IM_UI_ONLY, UFG::gActiveControllerNum);
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v2, v1) )
  {
    UFG::qWiseSymbol::create_from_string(&result, "mg_cockfight");
    UFG::TiDo::LoadWwiseBank(&result);
    _((AMD_HD3D *)result.mUID);
  }
}

// File Line: 67
// RVA: 0x5CA310
void __fastcall UFG::UIHKScreenCockFight::~UIHKScreenCockFight(UFG::UIHKScreenCockFight *this)
{
  unsigned int v2; // eax
  UFG::UIScreenTextureManager *v3; // rax
  unsigned int v4; // esi
  __int64 v5; // rbp
  UFG::UIHKCockData *v6; // rbx
  unsigned int v7; // r8d
  __int64 v8; // rdx
  unsigned int size; // eax
  hkgpIndexedMeshDefinitions::Edge *v10; // rdx
  hkgpIndexedMesh::EdgeBarrier *v11; // rcx
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v13; // eax
  UFG::qString *p; // rcx
  unsigned int *p_mStringHash32; // rbx
  UFG::qString *v16; // rcx
  unsigned int *v17; // rbx
  UFG::qString *v18; // rcx
  unsigned int *v19; // rbx
  UFG::qString *v20; // rcx
  unsigned int *v21; // rbx
  UFG::qString *v22; // rcx
  unsigned int *v23; // rbx
  UFG::qString *v24; // rcx
  unsigned int *v25; // rbx
  UFG::UIHKCockData **v26; // rcx
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h] BYREF
  UFG::UIHKCockData *v28; // [rsp+70h] [rbp+18h]

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenCockFight::`vftable;
  if ( UFG::gInputSystem )
  {
    if ( UFG::gActiveControllerNum != -1 )
    {
      v2 = UFG::UI::gUIInputLocked;
      if ( !UFG::UI::gUIInputLocked || (--UFG::UI::gUIInputLocked, v2 == 1) )
        UFG::UI::ResetGameplayInput((UFG::UI *)this);
    }
  }
  v3 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "CockFight");
  v4 = 0;
  if ( this->mFighterArray.size )
  {
    v5 = 8i64;
    do
    {
      v6 = this->mFighterArray.p[v4];
      v28 = v6;
      if ( v6 )
      {
        UFG::qString::~qString(&v6->breed);
        UFG::qString::~qString(&v6->trainer);
        UFG::qString::~qString(&v6->name);
        operator delete[](v6);
      }
      v7 = ++v4;
      if ( v4 != this->mFighterArray.size )
      {
        v8 = v5;
        do
        {
          *(UFG::UIHKCockData **)((char *)this->mFighterArray.p + v8 - 8) = *(UFG::UIHKCockData **)((char *)this->mFighterArray.p
                                                                                                  + v8);
          ++v7;
          v8 += 8i64;
        }
        while ( v7 != this->mFighterArray.size );
      }
      size = this->mFighterArray.size;
      if ( size > 1 )
        this->mFighterArray.size = size - 1;
      else
        this->mFighterArray.size = 0;
      v5 += 8i64;
    }
    while ( v4 < this->mFighterArray.size );
  }
  UFG::SetInputMode(this->mSavedControllerMode, UFG::gActiveControllerNum);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v13 = UFG::qStringHash32("COCKFIGHT", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v13);
  }
  UFG::UIHKScreenCockFight::mMinBet = -1;
  UFG::UIHKScreenCockFight::mMaxBet = -1;
  UFG::UIHKScreenCockFight::mBetMultiple = -1;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v11, v10) )
  {
    UFG::qWiseSymbol::create_from_string(&result, "mg_cockfight");
    UFG::TiDo::UnloadWwiseBank(&result);
    _((AMD_HD3D *)result.mUID);
  }
  p = this->mBird2Types.p;
  if ( p )
  {
    p_mStringHash32 = &p[-1].mStringHash32;
    `eh vector destructor iterator(
      p,
      0x28ui64,
      p[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](p_mStringHash32);
  }
  this->mBird2Types.p = 0i64;
  *(_QWORD *)&this->mBird2Types.size = 0i64;
  v16 = this->mTrainer2Names.p;
  if ( v16 )
  {
    v17 = &v16[-1].mStringHash32;
    `eh vector destructor iterator(
      v16,
      0x28ui64,
      v16[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v17);
  }
  this->mTrainer2Names.p = 0i64;
  *(_QWORD *)&this->mTrainer2Names.size = 0i64;
  v18 = this->mBird2Names.p;
  if ( v18 )
  {
    v19 = &v18[-1].mStringHash32;
    `eh vector destructor iterator(
      v18,
      0x28ui64,
      v18[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v19);
  }
  this->mBird2Names.p = 0i64;
  *(_QWORD *)&this->mBird2Names.size = 0i64;
  v20 = this->mBird1Types.p;
  if ( v20 )
  {
    v21 = &v20[-1].mStringHash32;
    `eh vector destructor iterator(
      v20,
      0x28ui64,
      v20[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v21);
  }
  this->mBird1Types.p = 0i64;
  *(_QWORD *)&this->mBird1Types.size = 0i64;
  v22 = this->mTrainer1Names.p;
  if ( v22 )
  {
    v23 = &v22[-1].mStringHash32;
    `eh vector destructor iterator(
      v22,
      0x28ui64,
      v22[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v23);
  }
  this->mTrainer1Names.p = 0i64;
  *(_QWORD *)&this->mTrainer1Names.size = 0i64;
  v24 = this->mBird1Names.p;
  if ( v24 )
  {
    v25 = &v24[-1].mStringHash32;
    `eh vector destructor iterator(
      v24,
      0x28ui64,
      v24[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v25);
  }
  this->mBird1Names.p = 0i64;
  *(_QWORD *)&this->mBird1Names.size = 0i64;
  v26 = this->mFighterArray.p;
  if ( v26 )
    operator delete[](v26);
  this->mFighterArray.p = 0i64;
  *(_QWORD *)&this->mFighterArray.size = 0i64;
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen(this);
}

// File Line: 98
// RVA: 0x6300A0
void __fastcall UFG::UIHKScreenCockFight::init(UFG::UIHKScreenCockFight *this, UFG::UICommandData *data)
{
  UFG::Controller *v3; // rcx
  UFG::GameStatTracker *v4; // rax

  UFG::UIScreen::init(this, data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  this->mMovie = this->mRenderable->m_movie.pObject;
  v4 = UFG::GameStatTracker::Instance();
  this->mWeiMoney = UFG::GameStatTracker::GetStat(v4, Money);
  this->mCurrentBet = UFG::UIHKScreenCockFight::mMinBet;
  UFG::UIHKScreenCockFight::PopulateFighterList(this);
  UFG::UIHKScreenCockFight::ShowHelpBar(this);
}

// File Line: 119
// RVA: 0x5F6700
void __fastcall UFG::UIHKScreenCockFight::PopulateFighterList(UFG::UIHKScreenCockFight *this)
{
  UFG::qString *v2; // rax
  UFG::qString *v3; // rax
  UFG::qString *v4; // rax
  UFG::qString *v5; // rax
  UFG::qString *v6; // rax
  UFG::qString *v7; // rax
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  UFG::qString *v10; // rax
  UFG::qString *v11; // rax
  UFG::qString *v12; // rax
  UFG::qString *v13; // rax
  UFG::qString *v14; // rax
  UFG::qString *v15; // rax
  UFG::qString *v16; // rax
  UFG::qString *v17; // rax
  UFG::UIHKCockData *v18; // r15
  int v19; // eax
  int v20; // eax
  int v21; // eax
  UFG::qString *v22; // rax
  UFG::UIHKCockData *v23; // r14
  int v24; // eax
  int v25; // eax
  UFG::qString *v26; // rdx
  UFG::qArray<UFG::UIHKCockData *,0> *p_mFighterArray; // rsi
  __int64 size; // r12
  unsigned int v29; // edi
  unsigned int capacity; // edx
  unsigned int v31; // ebx
  unsigned int v32; // edx
  __int64 v33; // r15
  unsigned int v34; // edi
  unsigned int v35; // eax
  UFG::qString v36; // [rsp+38h] [rbp-28h] BYREF

  UFG::qString::qString(&v36, "Rhode Island Leghorn");
  UFG::qArray<UFG::qString,0>::Add(&this->mBird1Types, v2, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Jersey Giant");
  UFG::qArray<UFG::qString,0>::Add(&this->mBird1Types, v3, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Buckeye Brahma");
  UFG::qArray<UFG::qString,0>::Add(&this->mBird2Types, v4, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Croad Langshan");
  UFG::qArray<UFG::qString,0>::Add(&this->mBird2Types, v5, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Dou Gai An");
  UFG::qArray<UFG::qString,0>::Add(&this->mBird1Names, v6, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Chow Tai");
  UFG::qArray<UFG::qString,0>::Add(&this->mBird1Names, v7, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Huo Yuanjia");
  UFG::qArray<UFG::qString,0>::Add(&this->mBird1Names, v8, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Guk Hei");
  UFG::qArray<UFG::qString,0>::Add(&this->mBird2Names, v9, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Sun Tzu");
  UFG::qArray<UFG::qString,0>::Add(&this->mBird2Names, v10, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Leung Kwan");
  UFG::qArray<UFG::qString,0>::Add(&this->mBird2Names, v11, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Lin Hong");
  UFG::qArray<UFG::qString,0>::Add(&this->mTrainer1Names, v12, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Zhang Ming");
  UFG::qArray<UFG::qString,0>::Add(&this->mTrainer1Names, v13, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Wu Zhi");
  UFG::qArray<UFG::qString,0>::Add(&this->mTrainer1Names, v14, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Huang Ya");
  UFG::qArray<UFG::qString,0>::Add(&this->mTrainer2Names, v15, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Cai Wen");
  UFG::qArray<UFG::qString,0>::Add(&this->mTrainer2Names, v16, "qArray.Add");
  UFG::qString::~qString(&v36);
  v17 = (UFG::qString *)UFG::qMalloc(0x80ui64, "Fighter1", 0i64);
  v18 = (UFG::UIHKCockData *)v17;
  if ( v17 )
  {
    UFG::qString::qString(v17);
    UFG::qString::qString(&v18->trainer);
    UFG::qString::qString(&v18->breed);
  }
  else
  {
    v18 = 0i64;
  }
  v19 = UFG::qRandom(this->mBird1Names.size, (unsigned int *)&UFG::qDefaultSeed);
  UFG::qString::Set(&v18->name, this->mBird1Names.p[v19].mData, this->mBird1Names.p[v19].mLength, 0i64, 0);
  v20 = UFG::qRandom(this->mTrainer1Names.size, (unsigned int *)&UFG::qDefaultSeed);
  UFG::qString::Set(&v18->trainer, this->mTrainer1Names.p[v20].mData, this->mTrainer1Names.p[v20].mLength, 0i64, 0);
  v21 = UFG::qRandom(this->mBird1Types.size, (unsigned int *)&UFG::qDefaultSeed);
  UFG::qString::Set(&v18->breed, this->mBird1Types.p[v21].mData, this->mBird1Types.p[v21].mLength, 0i64, 0);
  v18->record = UFG::qRandom(7u, (unsigned int *)&UFG::qDefaultSeed);
  v22 = (UFG::qString *)UFG::qMalloc(0x80ui64, "Fighter2", 0i64);
  v23 = (UFG::UIHKCockData *)v22;
  if ( v22 )
  {
    UFG::qString::qString(v22);
    UFG::qString::qString(&v23->trainer);
    UFG::qString::qString(&v23->breed);
  }
  else
  {
    v23 = 0i64;
  }
  v24 = UFG::qRandom(this->mBird2Names.size, (unsigned int *)&UFG::qDefaultSeed);
  UFG::qString::Set(&v23->name, this->mBird2Names.p[v24].mData, this->mBird2Names.p[v24].mLength, 0i64, 0);
  v25 = UFG::qRandom(this->mTrainer2Names.size, (unsigned int *)&UFG::qDefaultSeed);
  UFG::qString::Set(&v23->trainer, this->mTrainer2Names.p[v25].mData, this->mTrainer2Names.p[v25].mLength, 0i64, 0);
  v26 = &this->mBird2Types.p[(unsigned int)UFG::qRandom(this->mBird2Types.size, (unsigned int *)&UFG::qDefaultSeed)];
  UFG::qString::Set(&v23->breed, v26->mData, v26->mLength, 0i64, 0);
  v23->record = UFG::qRandom(5u, (unsigned int *)&UFG::qDefaultSeed);
  p_mFighterArray = &this->mFighterArray;
  size = this->mFighterArray.size;
  v29 = size + 1;
  capacity = this->mFighterArray.capacity;
  v31 = 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v32 = 2 * capacity;
    else
      v32 = 1;
    for ( ; v32 < v29; v32 *= 2 )
      ;
    if ( v32 <= 2 )
      v32 = 2;
    if ( v32 - v29 > 0x10000 )
      v32 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mFighterArray,
      v32,
      "qArray.Add");
  }
  p_mFighterArray->size = v29;
  this->mFighterArray.p[size] = v18;
  v33 = p_mFighterArray->size;
  v34 = v33 + 1;
  v35 = this->mFighterArray.capacity;
  if ( (int)v33 + 1 > v35 )
  {
    if ( v35 )
      v31 = 2 * v35;
    for ( ; v31 < v34; v31 *= 2 )
      ;
    if ( v31 <= 2 )
      v31 = 2;
    if ( v31 - v34 > 0x10000 )
      v31 = v33 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mFighterArray,
      v31,
      "qArray.Add");
  }
  p_mFighterArray->size = v34;
  this->mFighterArray.p[v33] = v23;
  UFG::UIHKScreenCockFight::RefreshFighterList(this);
}

// File Line: 163
// RVA: 0x5FFFD0
void __fastcall UFG::UIHKScreenCockFight::RefreshFighterList(UFG::UIHKScreenCockFight *this)
{
  __int64 v2; // rax
  UFG::qString *v3; // rdi
  Scaleform::GFx::Movie *mMovie; // rcx
  UFG::qString *v5; // rcx
  unsigned int i; // r14d
  char *mData; // rsi
  char *v8; // rsi
  char *v9; // rsi
  double record; // xmm6_8
  __int64 v11; // rax
  UFG::qString *v12; // rdi
  Scaleform::GFx::Movie *v13; // rcx
  UFG::qString *v14; // rcx
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-A8h] BYREF
  char v16[8]; // [rsp+60h] [rbp-78h] BYREF
  char v17[8]; // [rsp+68h] [rbp-70h] BYREF
  __int64 v18; // [rsp+70h] [rbp-68h]
  __int64 v19; // [rsp+78h] [rbp-60h]
  int v20; // [rsp+80h] [rbp-58h]
  char *v21; // [rsp+88h] [rbp-50h]
  char v22[16]; // [rsp+98h] [rbp-40h] BYREF
  __int64 v23; // [rsp+A8h] [rbp-30h]
  int v24; // [rsp+B0h] [rbp-28h]
  double v25; // [rsp+B8h] [rbp-20h]
  __int64 v26; // [rsp+C8h] [rbp-10h]
  UFG::qString v27; // [rsp+D0h] [rbp-8h] BYREF
  UFG::qString v28; // [rsp+F8h] [rbp+20h] BYREF
  __int64 v29; // [rsp+138h] [rbp+60h]

  v26 = -2i64;
  UFG::qString::qString(&v28, "CockFight_ClearFighterList");
  v3 = (UFG::qString *)v2;
  v29 = v2;
  if ( !this->mMovie )
    this->mMovie = this->mRenderable->m_movie.pObject;
  mMovie = this->mMovie;
  if ( mMovie )
  {
    Scaleform::GFx::Movie::Invoke(mMovie, *(const char **)(v2 + 24), 0i64, 0i64, 0);
    v5 = v3;
  }
  else
  {
    v5 = (UFG::qString *)v2;
  }
  UFG::qString::~qString(v5);
  for ( i = 0; i < this->mFighterArray.size; ++i )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    mData = this->mFighterArray.p[i]->name.mData;
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
    v8 = this->mFighterArray.p[i]->trainer.mData;
    if ( (v19 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, unsigned __int64))(*(_QWORD *)v18 + 16i64))(v18, v16, ptr.DataAux);
      v18 = 0i64;
    }
    LODWORD(v19) = 6;
    ptr.DataAux = (unsigned __int64)v8;
    v9 = this->mFighterArray.p[i]->breed.mData;
    if ( (v20 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v19 + 16i64))(v19, v17, v21);
      v19 = 0i64;
    }
    v20 = 6;
    v21 = v9;
    record = (double)this->mFighterArray.p[i]->record;
    if ( (v24 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v23 + 16i64))(
        v23,
        v22,
        COERCE_DOUBLE(*(_QWORD *)&v25));
      v23 = 0i64;
    }
    v24 = 5;
    v25 = record;
    Scaleform::GFx::Movie::Invoke(this->mMovie, "CockFight_AddFighter", 0i64, &ptr, 4u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
  UFG::qString::qString(&v27, "CockFight_GotoFighterSelect");
  v12 = (UFG::qString *)v11;
  v29 = v11;
  if ( !this->mMovie )
    this->mMovie = this->mRenderable->m_movie.pObject;
  v13 = this->mMovie;
  if ( v13 )
  {
    Scaleform::GFx::Movie::Invoke(v13, *(const char **)(v11 + 24), 0i64, 0i64, 0);
    v14 = v12;
  }
  else
  {
    v14 = (UFG::qString *)v11;
  }
  UFG::qString::~qString(v14);
  this->mState = STATE_BRIGHTNESS;
}

// File Line: 225
// RVA: 0x5ED520
void __fastcall UFG::UIHKScreenCockFight::IncreaseBet(UFG::UIHKScreenCockFight *this)
{
  unsigned int mCurrentBet; // eax

  this->mCurrentBet += UFG::UIHKScreenCockFight::mBetMultiple;
  mCurrentBet = this->mCurrentBet;
  if ( mCurrentBet > UFG::UIHKScreenCockFight::mMaxBet || mCurrentBet > this->mWeiMoney )
    this->mCurrentBet = mCurrentBet - UFG::UIHKScreenCockFight::mBetMultiple;
  UFG::UIHKScreenCockFight::UpdateBetAmount(this);
}

// File Line: 236
// RVA: 0x61A120
void __fastcall UFG::UIHKScreenCockFight::UpdateBetAmount(UFG::UIHKScreenCockFight *this)
{
  Scaleform::GFx::Value::ValueUnion v2; // xmm6_8
  double mWeiMoney; // xmm6_8
  double v4; // xmm6_8
  double v5; // xmm6_8
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-C8h] BYREF
  char v7[16]; // [rsp+60h] [rbp-98h] BYREF
  __int64 v8; // [rsp+70h] [rbp-88h]
  double v9; // [rsp+78h] [rbp-80h]
  char v10[16]; // [rsp+88h] [rbp-70h] BYREF
  __int64 v11; // [rsp+98h] [rbp-60h]
  int v12; // [rsp+A0h] [rbp-58h]
  double v13; // [rsp+A8h] [rbp-50h]
  char v14[16]; // [rsp+B8h] [rbp-40h] BYREF
  __int64 v15; // [rsp+C8h] [rbp-30h]
  int v16; // [rsp+D0h] [rbp-28h]
  double v17; // [rsp+D8h] [rbp-20h]
  __int64 v18; // [rsp+E8h] [rbp-10h]

  v18 = -2i64;
  `eh vector constructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v2.NValue = (double)(int)this->mCurrentBet;
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Number;
  ptr.mValue = v2;
  mWeiMoney = (double)(int)this->mWeiMoney;
  if ( (LOBYTE(v9) & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v8 + 16i64))(v8, v7, COERCE_DOUBLE(*(_QWORD *)&v9));
    v8 = 0i64;
  }
  v9 = mWeiMoney;
  v4 = (double)(int)UFG::UIHKScreenCockFight::mMinBet;
  if ( (v12 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(v11, v10, COERCE_DOUBLE(*(_QWORD *)&v13));
    v11 = 0i64;
  }
  v12 = 5;
  v13 = v4;
  v5 = (double)(int)UFG::UIHKScreenCockFight::mMaxBet;
  if ( (v16 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v15 + 16i64))(v15, v14, COERCE_DOUBLE(*(_QWORD *)&v17));
    v15 = 0i64;
  }
  v16 = 5;
  v17 = v5;
  Scaleform::GFx::Movie::Invoke(this->mMovie, "CockFight_UpdateBetAmount", 0i64, &ptr, 4u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 251
// RVA: 0x621E60
bool __fastcall UFG::UIHKScreenCockFight::handleMessage(
        UFG::UIHKScreenCockFight *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  __int32 v6; // ecx
  __int32 v7; // ecx
  UFG::qString *v8; // rax
  int SelectedFighterIndexFromFlash; // eax
  unsigned int mWeiMoney; // ecx
  UFG::qString *v11; // rax
  __int32 v12; // ecx
  UFG::qString *v14; // rax
  __int32 v15; // ecx
  UFG::qString *v16; // rax
  __int32 v17; // ecx
  unsigned int mCurrentBet; // ecx
  __int64 v19; // rcx
  UFG::UIHKCockData **p; // rax
  UFG::qString v21; // [rsp+38h] [rbp-60h] BYREF
  UFG::qString v22; // [rsp+60h] [rbp-38h] BYREF

  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    v6 = this->mState - 1;
    if ( v6 )
    {
      v7 = v6 - 1;
      if ( v7 )
      {
        if ( v7 == 2 )
        {
          if ( UFG::HudAudio::m_instance )
            UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
          this->mFinished = 1;
        }
        return UFG::UIHKMinigameScreen::handleMessage(this, msgId, msg);
      }
      this->mIsReady = 1;
      this->mState = STATE_UISCALE;
      UFG::qString::qString(&v21, "CockFight_HideScreen");
      UFG::UIHKScreenCockFight::Invoke(this, v8);
      UFG::UIHKScreenCockFight::HideHelpBar(this);
    }
    else
    {
      SelectedFighterIndexFromFlash = UFG::UIHKScreenCockFight::GetSelectedFighterIndexFromFlash(this);
      this->mSelectedFighterIndex = SelectedFighterIndexFromFlash;
      this->mSelectedFighter = this->mFighterArray.p[SelectedFighterIndexFromFlash];
      mWeiMoney = this->mWeiMoney;
      if ( mWeiMoney > UFG::UIHKScreenCockFight::mMinBet )
        mWeiMoney = UFG::UIHKScreenCockFight::mMinBet;
      this->mCurrentBet = mWeiMoney;
      UFG::UIHKScreenCockFight::UpdateBetAmount(this);
      UFG::qString::qString(&v22, "CockFight_GotoPlaceBet");
      UFG::UIHKScreenCockFight::Invoke(this, v11);
      this->mState = STATE_VOLUME;
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
    return UFG::UIHKMinigameScreen::handleMessage(this, msgId, msg);
  }
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 || msgId == UI_HASH_DPAD_LEFT_PRESSED_30 )
  {
    v17 = this->mState - 1;
    if ( v17 )
    {
      if ( v17 == 1 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
        this->mCurrentBet -= UFG::UIHKScreenCockFight::mBetMultiple;
        mCurrentBet = this->mCurrentBet;
        if ( mCurrentBet < UFG::UIHKScreenCockFight::mMinBet )
          mCurrentBet = UFG::UIHKScreenCockFight::mMinBet;
        this->mCurrentBet = mCurrentBet;
        UFG::UIHKScreenCockFight::UpdateBetAmount(this);
      }
      return 1;
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    UFG::qString::qString(&v22, "CockFight_PrevFighter");
LABEL_48:
    UFG::UIHKScreenCockFight::Invoke(this, v16);
    v19 = (unsigned int)UFG::UIHKScreenCockFight::GetSelectedFighterIndexFromFlash(this);
    p = this->mFighterArray.p;
    this->mSelectedFighterIndex = v19;
    this->mSelectedFighter = p[v19];
    return 1;
  }
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 || msgId == UI_HASH_DPAD_RIGHT_PRESSED_30 )
  {
    v15 = this->mState - 1;
    if ( v15 )
    {
      if ( v15 == 1 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
        UFG::UIHKScreenCockFight::IncreaseBet(this);
      }
      return 1;
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    UFG::qString::qString(&v22, "CockFight_NextFighter");
    goto LABEL_48;
  }
  if ( msgId != UI_HASH_BUTTON_BACK_PRESSED_30 )
    return UFG::UIHKMinigameScreen::handleMessage(this, msgId, msg);
  v12 = this->mState - 1;
  if ( v12 )
  {
    if ( v12 != 1 )
      return 0;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
    UFG::qString::qString(&v22, "CockFight_GotoFighterSelect");
    UFG::UIHKScreenCockFight::Invoke(this, v14);
    this->mCurrentBet = 0;
    this->mState = STATE_BRIGHTNESS;
    UFG::UIHKScreenCockFight::ShowHelpBar(this);
  }
  else if ( UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_HIDDEN )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
    this->mFinished = 1;
  }
  return 1;
}

// File Line: 353
// RVA: 0x605860
void __fastcall UFG::UIHKScreenCockFight::SetFightOver(UFG::UIHKScreenCockFight *this, bool win)
{
  int NValue; // ebx
  UFG::GameStatTracker *v5; // rax
  int v6; // edi
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  UFG::OSuiteLeaderboardManager *v10; // rax
  UFG::OSuiteLeaderboardData *LeaderboardDataUsingLeaderboardName; // rax
  UFG::qSymbol *v12; // rbx
  UFG::qSymbol *v13; // rax
  UFG::GameStatTracker *v14; // rax
  UFG::qSymbol *v15; // rbx
  UFG::qSymbol *v16; // rax
  UFG::GameStatTracker *v17; // rax
  int Stat; // ebx
  UFG::GameStatTracker *v19; // rax
  int v20; // edi
  UFG::OSuiteLeaderboardManager *v21; // rax
  UFG::OSuiteLeaderboardData *v22; // rax
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-31h] BYREF
  Scaleform::GFx::Value ptr; // [rsp+68h] [rbp-1h] BYREF
  UFG::qSymbol v25; // [rsp+D0h] [rbp+67h] BYREF
  UFG::qSymbol result; // [rsp+D8h] [rbp+6Fh] BYREF

  this->mState = NUM_CALIBRATION_STATES;
  `eh vector constructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_Boolean;
  ptr.mValue.BValue = win;
  Scaleform::GFx::Movie::Invoke(this->mMovie, "CockFight_GotoResults", 0i64, &ptr, 1u);
  UFG::UIHKScreenCockFight::ShowHelpBar(this);
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(this->mMovie, &pval, "gPlayerPocket");
  NValue = (int)pval.mValue.NValue;
  v5 = UFG::GameStatTracker::Instance();
  v6 = UFG::GameStatTracker::GetStat(v5, Money) - NValue;
  v7 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v7, Money, NValue);
  if ( win )
  {
    if ( v6 < 0 )
      v6 = -v6;
    v8 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v8, TotalCashEarned, v6);
    v9 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v9, GamblingEarnings, v6);
    v10 = UFG::OSuiteLeaderboardManager::Instance();
    LeaderboardDataUsingLeaderboardName = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(
                                            v10,
                                            "StatAwardsMogul");
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(LeaderboardDataUsingLeaderboardName, v6);
    v12 = UFG::qSymbol::create_from_string(&result, "Winning");
    v13 = UFG::qSymbol::create_from_string(&v25, "CockFight");
    UFG::GameStatAction::Money::SendTransactionTelemetry(v13, v12, v6);
    UFG::AchievementTrophyManager::UnlockAchievementTrophy(19);
    if ( v6 >= 50000 )
      UFG::AchievementTrophyManager::UnlockAchievementTrophy(20);
  }
  else
  {
    if ( v6 < 0 )
      v6 = -v6;
    v14 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v14, GamblingLoss, v6);
    v15 = UFG::qSymbol::create_from_string(&result, "Lost");
    v16 = UFG::qSymbol::create_from_string(&v25, "CockFight");
    UFG::GameStatAction::Money::SendTransactionTelemetry(v16, v15, v6);
  }
  v17 = UFG::GameStatTracker::Instance();
  Stat = UFG::GameStatTracker::GetStat(v17, GamblingLoss);
  v19 = UFG::GameStatTracker::Instance();
  v20 = UFG::GameStatTracker::GetStat(v19, GamblingEarnings) - Stat;
  v21 = UFG::OSuiteLeaderboardManager::Instance();
  v22 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v21, "StatAwardsGambler");
  UFG::DataSynchronizer::SetMaxToGlobalSnapshot(v22, v20);
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
    pval.pObjectInterface = 0i64;
  }
  pval.Type = VT_Undefined;
  `eh vector destructor iterator(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 402
// RVA: 0x5E8D40
__int64 __fastcall UFG::UIHKScreenCockFight::GetSelectedFighterIndexFromFlash(UFG::UIHKScreenCockFight *this)
{
  unsigned int NValue; // ebx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h] BYREF

  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(this->mMovie, &pval, "gFighterIndex");
  NValue = (int)pval.mValue.NValue;
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
    pval.pObjectInterface = 0i64;
  }
  return NValue;
}

// File Line: 413
// RVA: 0x5EDEA0
void __fastcall UFG::UIHKScreenCockFight::Invoke(UFG::UIHKScreenCockFight *this, UFG::qString *cmd)
{
  Scaleform::GFx::Movie *mMovie; // rcx

  if ( !this->mMovie )
    this->mMovie = this->mRenderable->m_movie.pObject;
  mMovie = this->mMovie;
  if ( mMovie )
  {
    Scaleform::GFx::Movie::Invoke(mMovie, cmd->mData, 0i64, 0i64, 0);
    UFG::qString::~qString(cmd);
  }
  else
  {
    UFG::qString::~qString(cmd);
  }
}

// File Line: 432
// RVA: 0x60DA10
void __fastcall UFG::UIHKScreenCockFight::ShowHelpBar(UFG::UIHKScreenCockFight *this)
{
  UFG::UIHKScreenCockFight::eState mState; // ecx
  __int32 v2; // ecx
  __int32 v3; // ecx
  UFG::UIHKHelpBarWidget *v4; // rsi
  unsigned int v5; // ebx
  UFG::UIHKScreenGlobalOverlay *v6; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v8; // ebx
  UFG::UIHKHelpBarData data; // [rsp+20h] [rbp-D8h] BYREF
  __int64 v10; // [rsp+268h] [rbp+170h]

  v10 = -2i64;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis
    || UFG::UIHKScreenGlobalOverlay::mThis == (UFG::UIHKScreenGlobalOverlay *)-144i64 )
  {
    return;
  }
  mState = this->mState;
  if ( mState == STATE_INIT )
  {
    p_HelpBar = &gHelpBarSentinel;
    if ( UFG::UIHKScreenGlobalOverlay::mThis )
      p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    goto LABEL_20;
  }
  v2 = mState - 1;
  if ( !v2 )
  {
    p_HelpBar = &gHelpBarSentinel;
    if ( UFG::UIHKScreenGlobalOverlay::mThis )
      p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    goto LABEL_20;
  }
  v3 = v2 - 1;
  if ( !v3 )
  {
    p_HelpBar = &gHelpBarSentinel;
    if ( UFG::UIHKScreenGlobalOverlay::mThis )
      p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
LABEL_20:
    v8 = UFG::qStringHash32("COCKFIGHT", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v8;
    *(_QWORD *)&data.priority = 0i64;
    *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$COMMON_ACCEPT_UPPERCASE");
    UFG::qString::Set(&data.Captions[1], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)&data.Captions[1].mStringHash32, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[2].mStringHash32, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[3].mStringHash32, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[4].mStringHash32, &customCaption);
    memset(&data.Icons[5].mStringHash32, 0, 24);
    UFG::UIHKHelpBarWidget::Show(p_HelpBar, &data);
    UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
    `eh vector destructor iterator(
      &data.Captions[5].mStringHash32,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    return;
  }
  if ( v3 == 2 )
  {
    v4 = &gHelpBarSentinel;
    if ( UFG::UIHKScreenGlobalOverlay::mThis )
      v4 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v5 = UFG::qStringHash32("COCKFIGHT", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v5;
    *(_QWORD *)&data.priority = 0i64;
    *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$COMMON_EXIT_UPPERCASE");
    UFG::qString::Set(&data.Captions[1], &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[1].mStringHash32, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[2].mStringHash32, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[3].mStringHash32, &customCaption);
    UFG::qString::Set((UFG::qString *)&data.Captions[4].mStringHash32, &customCaption);
    memset(&data.Icons[5].mStringHash32, 0, 24);
    UFG::UIHKHelpBarWidget::Show(v4, &data);
    UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
    `eh vector destructor iterator(
      &data.Captions[5].mStringHash32,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    v6 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v6 = &gGlobalOverlaySentinel;
    v6->HelpBar.mChanged |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v6->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
    v6->HelpBar.mYOffset = -20.0;
  }
}NED_INT(v6->HelpBa

// File Line: 496
// RVA: 0x5ECF60
void __fastcall UFG::UIHKScreenCockFight::HideHelpBar(UFG::UIHKScreenCockFight *this)
{
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v2; // eax

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v2 = UFG::qStringHash32("COCKFIGHT", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v2);
  }
}

