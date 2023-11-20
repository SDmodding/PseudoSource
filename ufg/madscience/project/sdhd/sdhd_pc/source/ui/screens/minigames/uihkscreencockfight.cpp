// File Line: 54
// RVA: 0x5C4B70
void __fastcall UFG::UIHKScreenCockFight::UIHKScreenCockFight(UFG::UIHKScreenCockFight *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax
  hkgpIndexedMeshDefinitions::Edge *v2; // rdx
  hkgpIndexedMesh::EdgeBarrier *v3; // rcx
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKMinigameScreen::`vftable';
  *(_QWORD *)&this->mfAlphaValue = 1109393408i64;
  ++UFG::UIHKMinigameScreen::mNumMinigameScreens;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenCockFight::`vftable';
  this->mState = 0;
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
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v3, v2) )
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
  UFG::UIHKScreenCockFight *v1; // rdi
  unsigned int v2; // eax
  UFG::UIScreenTextureManager *v3; // rax
  unsigned int v4; // esi
  signed __int64 v5; // rbp
  UFG::qString *v6; // rbx
  unsigned int v7; // er8
  signed __int64 v8; // rdx
  unsigned int v9; // eax
  hkgpIndexedMeshDefinitions::Edge *v10; // rdx
  hkgpIndexedMesh::EdgeBarrier *v11; // rcx
  UFG::UIHKHelpBarWidget *v12; // rbx
  unsigned int v13; // eax
  UFG::qString *v14; // rcx
  unsigned int *v15; // rbx
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
  UFG::qWiseSymbol result; // [rsp+68h] [rbp+10h]
  UFG::qString *v28; // [rsp+70h] [rbp+18h]

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenCockFight::`vftable';
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
  if ( v1->mFighterArray.size )
  {
    v5 = 8i64;
    do
    {
      v6 = &v1->mFighterArray.p[v4]->name;
      v28 = v6;
      if ( v6 )
      {
        UFG::qString::~qString(v6 + 2);
        UFG::qString::~qString(v6 + 1);
        UFG::qString::~qString(v6);
        operator delete[](v6);
      }
      v7 = ++v4;
      if ( v4 != v1->mFighterArray.size )
      {
        v8 = v5;
        do
        {
          *(UFG::UIHKCockData **)((char *)v1->mFighterArray.p + v8 - 8) = *(UFG::UIHKCockData **)((char *)v1->mFighterArray.p
                                                                                                + v8);
          ++v7;
          v8 += 8i64;
        }
        while ( v7 != v1->mFighterArray.size );
      }
      v9 = v1->mFighterArray.size;
      if ( v9 > 1 )
        v1->mFighterArray.size = v9 - 1;
      else
        v1->mFighterArray.size = 0;
      v5 += 8i64;
    }
    while ( v4 < v1->mFighterArray.size );
  }
  UFG::SetInputMode(v1->mSavedControllerMode, UFG::gActiveControllerNum);
  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v12 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v13 = UFG::qStringHash32("COCKFIGHT", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(v12, v13);
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
  v14 = v1->mBird2Types.p;
  if ( v14 )
  {
    v15 = &v14[-1].mStringHash32;
    `eh vector destructor iterator'(
      v14,
      0x28ui64,
      v14[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v15);
  }
  v1->mBird2Types.p = 0i64;
  *(_QWORD *)&v1->mBird2Types.size = 0i64;
  v16 = v1->mTrainer2Names.p;
  if ( v16 )
  {
    v17 = &v16[-1].mStringHash32;
    `eh vector destructor iterator'(
      v16,
      0x28ui64,
      v16[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v17);
  }
  v1->mTrainer2Names.p = 0i64;
  *(_QWORD *)&v1->mTrainer2Names.size = 0i64;
  v18 = v1->mBird2Names.p;
  if ( v18 )
  {
    v19 = &v18[-1].mStringHash32;
    `eh vector destructor iterator'(
      v18,
      0x28ui64,
      v18[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v19);
  }
  v1->mBird2Names.p = 0i64;
  *(_QWORD *)&v1->mBird2Names.size = 0i64;
  v20 = v1->mBird1Types.p;
  if ( v20 )
  {
    v21 = &v20[-1].mStringHash32;
    `eh vector destructor iterator'(
      v20,
      0x28ui64,
      v20[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v21);
  }
  v1->mBird1Types.p = 0i64;
  *(_QWORD *)&v1->mBird1Types.size = 0i64;
  v22 = v1->mTrainer1Names.p;
  if ( v22 )
  {
    v23 = &v22[-1].mStringHash32;
    `eh vector destructor iterator'(
      v22,
      0x28ui64,
      v22[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v23);
  }
  v1->mTrainer1Names.p = 0i64;
  *(_QWORD *)&v1->mTrainer1Names.size = 0i64;
  v24 = v1->mBird1Names.p;
  if ( v24 )
  {
    v25 = &v24[-1].mStringHash32;
    `eh vector destructor iterator'(
      v24,
      0x28ui64,
      v24[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v25);
  }
  v1->mBird1Names.p = 0i64;
  *(_QWORD *)&v1->mBird1Names.size = 0i64;
  v26 = v1->mFighterArray.p;
  if ( v26 )
    operator delete[](v26);
  v1->mFighterArray.p = 0i64;
  *(_QWORD *)&v1->mFighterArray.size = 0i64;
  UFG::UIHKMinigameScreen::~UIHKMinigameScreen((UFG::UIHKMinigameScreen *)&v1->vfptr);
}

// File Line: 98
// RVA: 0x6300A0
void __fastcall UFG::UIHKScreenCockFight::init(UFG::UIHKScreenCockFight *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenCockFight *v2; // rbx
  UFG::Controller *v3; // rcx
  UFG::GameStatTracker *v4; // rax

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  if ( UFG::gInputSystem && UFG::gActiveControllerNum != -1 )
  {
    v3 = UFG::gInputSystem->mControllers[UFG::gActiveControllerNum];
    if ( !UFG::UI::gUIInputLocked )
      g_saved_gameplay_controller_mode = v3->m_ActiveMapSet;
    UFG::SetInputMode(IM_UI_ONLY, v3->mControllerIndex);
    ++UFG::UI::gUIInputLocked;
  }
  v2->mMovie = v2->mRenderable->m_movie.pObject;
  v4 = UFG::GameStatTracker::Instance();
  v2->mWeiMoney = UFG::GameStatTracker::GetStat(v4, Money);
  v2->mCurrentBet = UFG::UIHKScreenCockFight::mMinBet;
  UFG::UIHKScreenCockFight::PopulateFighterList(v2);
  UFG::UIHKScreenCockFight::ShowHelpBar(v2);
}

// File Line: 119
// RVA: 0x5F6700
void __fastcall UFG::UIHKScreenCockFight::PopulateFighterList(UFG::UIHKScreenCockFight *this)
{
  UFG::UIHKScreenCockFight *v1; // r13
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
  signed __int64 v26; // rdx
  UFG::qArray<UFG::UIHKCockData *,0> *v27; // rsi
  __int64 v28; // r12
  unsigned int v29; // edi
  unsigned int v30; // edx
  unsigned int v31; // ebx
  unsigned int v32; // edx
  __int64 v33; // r15
  unsigned int v34; // edi
  unsigned int v35; // eax
  UFG::qString v36; // [rsp+38h] [rbp-28h]

  v1 = this;
  UFG::qString::qString(&v36, "Rhode Island Leghorn");
  UFG::qArray<UFG::qString,0>::Add(&v1->mBird1Types, v2, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Jersey Giant");
  UFG::qArray<UFG::qString,0>::Add(&v1->mBird1Types, v3, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Buckeye Brahma");
  UFG::qArray<UFG::qString,0>::Add(&v1->mBird2Types, v4, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Croad Langshan");
  UFG::qArray<UFG::qString,0>::Add(&v1->mBird2Types, v5, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Dou Gai An");
  UFG::qArray<UFG::qString,0>::Add(&v1->mBird1Names, v6, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Chow Tai");
  UFG::qArray<UFG::qString,0>::Add(&v1->mBird1Names, v7, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Huo Yuanjia");
  UFG::qArray<UFG::qString,0>::Add(&v1->mBird1Names, v8, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Guk Hei");
  UFG::qArray<UFG::qString,0>::Add(&v1->mBird2Names, v9, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Sun Tzu");
  UFG::qArray<UFG::qString,0>::Add(&v1->mBird2Names, v10, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Leung Kwan");
  UFG::qArray<UFG::qString,0>::Add(&v1->mBird2Names, v11, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Lin Hong");
  UFG::qArray<UFG::qString,0>::Add(&v1->mTrainer1Names, v12, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Zhang Ming");
  UFG::qArray<UFG::qString,0>::Add(&v1->mTrainer1Names, v13, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Wu Zhi");
  UFG::qArray<UFG::qString,0>::Add(&v1->mTrainer1Names, v14, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Huang Ya");
  UFG::qArray<UFG::qString,0>::Add(&v1->mTrainer2Names, v15, "qArray.Add");
  UFG::qString::~qString(&v36);
  UFG::qString::qString(&v36, "Cai Wen");
  UFG::qArray<UFG::qString,0>::Add(&v1->mTrainer2Names, v16, "qArray.Add");
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
  v19 = UFG::qRandom(v1->mBird1Names.size, &UFG::qDefaultSeed);
  UFG::qString::Set(&v18->name, v1->mBird1Names.p[v19].mData, v1->mBird1Names.p[v19].mLength, 0i64, 0);
  v20 = UFG::qRandom(v1->mTrainer1Names.size, &UFG::qDefaultSeed);
  UFG::qString::Set(&v18->trainer, v1->mTrainer1Names.p[v20].mData, v1->mTrainer1Names.p[v20].mLength, 0i64, 0);
  v21 = UFG::qRandom(v1->mBird1Types.size, &UFG::qDefaultSeed);
  UFG::qString::Set(&v18->breed, v1->mBird1Types.p[v21].mData, v1->mBird1Types.p[v21].mLength, 0i64, 0);
  v18->record = UFG::qRandom(7, &UFG::qDefaultSeed);
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
  v24 = UFG::qRandom(v1->mBird2Names.size, &UFG::qDefaultSeed);
  UFG::qString::Set(&v23->name, v1->mBird2Names.p[v24].mData, v1->mBird2Names.p[v24].mLength, 0i64, 0);
  v25 = UFG::qRandom(v1->mTrainer2Names.size, &UFG::qDefaultSeed);
  UFG::qString::Set(&v23->trainer, v1->mTrainer2Names.p[v25].mData, v1->mTrainer2Names.p[v25].mLength, 0i64, 0);
  v26 = (signed __int64)&v1->mBird2Types.p[(unsigned int)UFG::qRandom(v1->mBird2Types.size, &UFG::qDefaultSeed)];
  UFG::qString::Set(&v23->breed, *(const char **)(v26 + 24), *(_DWORD *)(v26 + 20), 0i64, 0);
  v23->record = UFG::qRandom(5, &UFG::qDefaultSeed);
  v27 = &v1->mFighterArray;
  v28 = v1->mFighterArray.size;
  v29 = v28 + 1;
  v30 = v1->mFighterArray.capacity;
  v31 = 1;
  if ( (signed int)v28 + 1 > v30 )
  {
    if ( v30 )
      v32 = 2 * v30;
    else
      v32 = 1;
    for ( ; v32 < v29; v32 *= 2 )
      ;
    if ( v32 <= 2 )
      v32 = 2;
    if ( v32 - v29 > 0x10000 )
      v32 = v28 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v1->mFighterArray,
      v32,
      "qArray.Add");
  }
  v27->size = v29;
  v1->mFighterArray.p[v28] = v18;
  v33 = v27->size;
  v34 = v33 + 1;
  v35 = v1->mFighterArray.capacity;
  if ( (signed int)v33 + 1 > v35 )
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
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v1->mFighterArray,
      v31,
      "qArray.Add");
  }
  v27->size = v34;
  v1->mFighterArray.p[v33] = v23;
  UFG::UIHKScreenCockFight::RefreshFighterList(v1);
}

// File Line: 163
// RVA: 0x5FFFD0
void __fastcall UFG::UIHKScreenCockFight::RefreshFighterList(UFG::UIHKScreenCockFight *this)
{
  UFG::UIHKScreenCockFight *v1; // rbx
  __int64 v2; // rax
  UFG::qString *v3; // rdi
  Scaleform::GFx::Movie *v4; // rcx
  UFG::qString *v5; // rcx
  unsigned int i; // er14
  __int64 v7; // rsi
  __int64 v8; // rsi
  __int64 v9; // rsi
  double v10; // xmm6_8
  __int64 v11; // rax
  UFG::qString *v12; // rdi
  Scaleform::GFx::Movie *v13; // rcx
  UFG::qString *v14; // rcx
  char ptr; // [rsp+30h] [rbp-A8h]
  __int64 v16; // [rsp+40h] [rbp-98h]
  unsigned int v17; // [rsp+48h] [rbp-90h]
  __int64 v18; // [rsp+50h] [rbp-88h]
  __int64 v19; // [rsp+58h] [rbp-80h]
  char v20; // [rsp+60h] [rbp-78h]
  char v21; // [rsp+68h] [rbp-70h]
  __int64 v22; // [rsp+70h] [rbp-68h]
  __int64 v23; // [rsp+78h] [rbp-60h]
  unsigned int v24; // [rsp+80h] [rbp-58h]
  __int64 v25; // [rsp+88h] [rbp-50h]
  char v26; // [rsp+98h] [rbp-40h]
  __int64 v27; // [rsp+A8h] [rbp-30h]
  unsigned int v28; // [rsp+B0h] [rbp-28h]
  double v29; // [rsp+B8h] [rbp-20h]
  __int64 v30; // [rsp+C8h] [rbp-10h]
  UFG::qString v31; // [rsp+D0h] [rbp-8h]
  __int64 v32; // [rsp+F8h] [rbp+20h]
  __int64 v33; // [rsp+138h] [rbp+60h]

  v30 = -2i64;
  v1 = this;
  UFG::qString::qString((UFG::qString *)&v32, "CockFight_ClearFighterList");
  v3 = (UFG::qString *)v2;
  v33 = v2;
  if ( !v1->mMovie )
    v1->mMovie = v1->mRenderable->m_movie.pObject;
  v4 = v1->mMovie;
  if ( v4 )
  {
    Scaleform::GFx::Movie::Invoke(v4, *(const char **)(v2 + 24), 0i64, 0i64, 0);
    v5 = v3;
  }
  else
  {
    v5 = (UFG::qString *)v2;
  }
  UFG::qString::~qString(v5);
  for ( i = 0; i < v1->mFighterArray.size; ++i )
  {
    `eh vector constructor iterator'(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v7 = (__int64)v1->mFighterArray.p[i]->name.mData;
    if ( (v17 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, &ptr, v18);
      v16 = 0i64;
    }
    v17 = 6;
    v18 = v7;
    v8 = (__int64)v1->mFighterArray.p[i]->trainer.mData;
    if ( ((unsigned int)v23 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v22 + 16i64))(v22, &v20, v19);
      v22 = 0i64;
    }
    LODWORD(v23) = 6;
    v19 = v8;
    v9 = (__int64)v1->mFighterArray.p[i]->breed.mData;
    if ( (v24 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v23 + 16i64))(v23, &v21, v25);
      v23 = 0i64;
    }
    v24 = 6;
    v25 = v9;
    v10 = (double)v1->mFighterArray.p[i]->record;
    if ( (v28 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v27 + 16i64))(
        v27,
        &v26,
        COERCE_DOUBLE(*(_QWORD *)&v29));
      v27 = 0i64;
    }
    v28 = 5;
    v29 = v10;
    Scaleform::GFx::Movie::Invoke(v1->mMovie, "CockFight_AddFighter", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
  UFG::qString::qString(&v31, "CockFight_GotoFighterSelect");
  v12 = (UFG::qString *)v11;
  v33 = v11;
  if ( !v1->mMovie )
    v1->mMovie = v1->mRenderable->m_movie.pObject;
  v13 = v1->mMovie;
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
  v1->mState = 1;
}

// File Line: 225
// RVA: 0x5ED520
void __fastcall UFG::UIHKScreenCockFight::IncreaseBet(UFG::UIHKScreenCockFight *this)
{
  unsigned int v1; // eax

  this->mCurrentBet += UFG::UIHKScreenCockFight::mBetMultiple;
  v1 = this->mCurrentBet;
  if ( v1 > UFG::UIHKScreenCockFight::mMaxBet || v1 > this->mWeiMoney )
    this->mCurrentBet = v1 - UFG::UIHKScreenCockFight::mBetMultiple;
  UFG::UIHKScreenCockFight::UpdateBetAmount(this);
}

// File Line: 236
// RVA: 0x61A120
void __fastcall UFG::UIHKScreenCockFight::UpdateBetAmount(UFG::UIHKScreenCockFight *this)
{
  UFG::UIHKScreenCockFight *v1; // rbx
  double v2; // xmm6_8
  double v3; // xmm6_8
  double v4; // xmm6_8
  double v5; // xmm6_8
  char ptr; // [rsp+30h] [rbp-C8h]
  __int64 v7; // [rsp+40h] [rbp-B8h]
  unsigned int v8; // [rsp+48h] [rbp-B0h]
  double v9; // [rsp+50h] [rbp-A8h]
  char v10; // [rsp+60h] [rbp-98h]
  __int64 v11; // [rsp+70h] [rbp-88h]
  double v12; // [rsp+78h] [rbp-80h]
  char v13; // [rsp+88h] [rbp-70h]
  __int64 v14; // [rsp+98h] [rbp-60h]
  unsigned int v15; // [rsp+A0h] [rbp-58h]
  double v16; // [rsp+A8h] [rbp-50h]
  char v17; // [rsp+B8h] [rbp-40h]
  __int64 v18; // [rsp+C8h] [rbp-30h]
  unsigned int v19; // [rsp+D0h] [rbp-28h]
  double v20; // [rsp+D8h] [rbp-20h]
  __int64 v21; // [rsp+E8h] [rbp-10h]

  v21 = -2i64;
  v1 = this;
  `eh vector constructor iterator'(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v2 = (double)(signed int)v1->mCurrentBet;
  if ( (v8 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v7 + 16i64))(v7, &ptr, COERCE_DOUBLE(*(_QWORD *)&v9));
    v7 = 0i64;
  }
  v8 = 5;
  v9 = v2;
  v3 = (double)(signed int)v1->mWeiMoney;
  if ( (LODWORD(v12) >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v11 + 16i64))(
      v11,
      &v10,
      COERCE_DOUBLE(*(_QWORD *)&v12));
    v11 = 0i64;
  }
  v12 = v3;
  v4 = (double)(signed int)UFG::UIHKScreenCockFight::mMinBet;
  if ( (v15 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v14 + 16i64))(
      v14,
      &v13,
      COERCE_DOUBLE(*(_QWORD *)&v16));
    v14 = 0i64;
  }
  v15 = 5;
  v16 = v4;
  v5 = (double)(signed int)UFG::UIHKScreenCockFight::mMaxBet;
  if ( (v19 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v18 + 16i64))(
      v18,
      &v17,
      COERCE_DOUBLE(*(_QWORD *)&v20));
    v18 = 0i64;
  }
  v19 = 5;
  v20 = v5;
  Scaleform::GFx::Movie::Invoke(v1->mMovie, "CockFight_UpdateBetAmount", 0i64, (Scaleform::GFx::Value *)&ptr, 4u);
  `eh vector destructor iterator'(&ptr, 0x30ui64, 4, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 251
// RVA: 0x621E60
bool __fastcall UFG::UIHKScreenCockFight::handleMessage(UFG::UIHKScreenCockFight *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rbp
  unsigned int v4; // esi
  UFG::UIHKScreenCockFight *v5; // rbx
  __int32 v6; // ecx
  int v7; // ecx
  UFG::qString *v8; // rax
  int v9; // eax
  unsigned int v10; // ecx
  UFG::qString *v11; // rax
  __int32 v12; // ecx
  UFG::qString *v14; // rax
  __int32 v15; // ecx
  UFG::qString *v16; // rax
  __int32 v17; // ecx
  unsigned int v18; // ecx
  __int64 v19; // rcx
  UFG::UIHKCockData **v20; // rax
  UFG::qString v21; // [rsp+38h] [rbp-60h]
  UFG::qString v22; // [rsp+60h] [rbp-38h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
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
            UFG::AudioEntity::CreateAndPlayEvent(
              (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
              0x4A3D1F6Cu,
              0i64,
              0,
              0i64);
          v5->mFinished = 1;
        }
        return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
      }
      v5->mIsReady = 1;
      v5->mState = 3;
      UFG::qString::qString(&v21, "CockFight_HideScreen");
      UFG::UIHKScreenCockFight::Invoke(v5, v8);
      UFG::UIHKScreenCockFight::HideHelpBar(v5);
    }
    else
    {
      v9 = UFG::UIHKScreenCockFight::GetSelectedFighterIndexFromFlash(v5);
      v5->mSelectedFighterIndex = v9;
      v5->mSelectedFighter = v5->mFighterArray.p[v9];
      v10 = v5->mWeiMoney;
      if ( v10 > UFG::UIHKScreenCockFight::mMinBet )
        v10 = UFG::UIHKScreenCockFight::mMinBet;
      v5->mCurrentBet = v10;
      UFG::UIHKScreenCockFight::UpdateBetAmount(v5);
      UFG::qString::qString(&v22, "CockFight_GotoPlaceBet");
      UFG::UIHKScreenCockFight::Invoke(v5, v11);
      v5->mState = 2;
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x4A3D1F6Cu,
        0i64,
        0,
        0i64);
    return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
  }
  if ( msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 || msgId == UI_HASH_DPAD_LEFT_PRESSED_30 )
  {
    v17 = this->mState - 1;
    if ( v17 )
    {
      if ( v17 == 1 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xEDB4A8C7,
            0i64,
            0,
            0i64);
        v5->mCurrentBet -= UFG::UIHKScreenCockFight::mBetMultiple;
        v18 = v5->mCurrentBet;
        if ( v18 < UFG::UIHKScreenCockFight::mMinBet )
          v18 = UFG::UIHKScreenCockFight::mMinBet;
        v5->mCurrentBet = v18;
        UFG::UIHKScreenCockFight::UpdateBetAmount(v5);
      }
      return 1;
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    UFG::qString::qString(&v22, "CockFight_PrevFighter");
LABEL_48:
    UFG::UIHKScreenCockFight::Invoke(v5, v16);
    v19 = (unsigned int)UFG::UIHKScreenCockFight::GetSelectedFighterIndexFromFlash(v5);
    v20 = v5->mFighterArray.p;
    v5->mSelectedFighterIndex = v19;
    v5->mSelectedFighter = v20[v19];
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
          UFG::AudioEntity::CreateAndPlayEvent(
            (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
            0xEDB4A8C7,
            0i64,
            0,
            0i64);
        UFG::UIHKScreenCockFight::IncreaseBet(v5);
      }
      return 1;
    }
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    UFG::qString::qString(&v22, "CockFight_NextFighter");
    goto LABEL_48;
  }
  if ( msgId != UI_HASH_BUTTON_BACK_PRESSED_30 )
    return UFG::UIHKMinigameScreen::handleMessage((UFG::UIHKMinigameScreen *)&v5->vfptr, v4, v3);
  v12 = this->mState - 1;
  if ( v12 )
  {
    if ( v12 != 1 )
      return 0;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xA4E5BFBD,
        0i64,
        0,
        0i64);
    UFG::qString::qString(&v22, "CockFight_GotoFighterSelect");
    UFG::UIHKScreenCockFight::Invoke(v5, v14);
    v5->mCurrentBet = 0;
    v5->mState = 1;
    UFG::UIHKScreenCockFight::ShowHelpBar(v5);
  }
  else if ( UFG::UIHK_NISOverlay::m_curtains.m_state == STATE_CURTAIN_HIDDEN )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xA4E5BFBD,
        0i64,
        0,
        0i64);
    v5->mFinished = 1;
  }
  return 1;
}

// File Line: 353
// RVA: 0x605860
void __fastcall UFG::UIHKScreenCockFight::SetFightOver(UFG::UIHKScreenCockFight *this, bool win)
{
  bool v2; // si
  UFG::UIHKScreenCockFight *v3; // rbx
  int v4; // ebx
  UFG::GameStatTracker *v5; // rax
  int v6; // edi
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::GameStatTracker *v9; // rax
  UFG::OSuiteLeaderboardManager *v10; // rax
  UFG::OSuiteLeaderboardData *v11; // rax
  UFG::qSymbol *v12; // rbx
  UFG::qSymbol *v13; // rax
  UFG::GameStatTracker *v14; // rax
  UFG::qSymbol *v15; // rbx
  UFG::qSymbol *v16; // rax
  UFG::GameStatTracker *v17; // rax
  int v18; // ebx
  UFG::GameStatTracker *v19; // rax
  int v20; // edi
  UFG::OSuiteLeaderboardManager *v21; // rax
  UFG::OSuiteLeaderboardData *v22; // rax
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-31h]
  char ptr; // [rsp+68h] [rbp-1h]
  __int64 v25; // [rsp+78h] [rbp+Fh]
  unsigned int v26; // [rsp+80h] [rbp+17h]
  __int64 v27; // [rsp+88h] [rbp+1Fh]
  UFG::qSymbol v28; // [rsp+D0h] [rbp+67h]
  UFG::qSymbol result; // [rsp+D8h] [rbp+6Fh]

  v2 = win;
  v3 = this;
  this->mState = 4;
  `eh vector constructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v26 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v25 + 16i64))(v25, &ptr, v27);
    v25 = 0i64;
  }
  v26 = 2;
  LOBYTE(v27) = v2;
  Scaleform::GFx::Movie::Invoke(v3->mMovie, "CockFight_GotoResults", 0i64, (Scaleform::GFx::Value *)&ptr, 1u);
  UFG::UIHKScreenCockFight::ShowHelpBar(v3);
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(v3->mMovie, &pval, "gPlayerPocket");
  v4 = (signed int)pval.mValue.NValue;
  v5 = UFG::GameStatTracker::Instance();
  v6 = (unsigned __int64)UFG::GameStatTracker::GetStat(v5, Money) - v4;
  v7 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v7, Money, v4);
  if ( v2 )
  {
    if ( v6 < 0 )
      v6 = -v6;
    v8 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v8, TotalCashEarned, v6);
    v9 = UFG::GameStatTracker::Instance();
    UFG::GameStatTracker::ApplyDelta(v9, GamblingEarnings, v6);
    v10 = UFG::OSuiteLeaderboardManager::Instance();
    v11 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v10, "StatAwardsMogul");
    UFG::DataSynchronizer::ApplyDeltaToGlobalSnapshot(v11, v6);
    v12 = UFG::qSymbol::create_from_string(&result, "Winning");
    v13 = UFG::qSymbol::create_from_string(&v28, "CockFight");
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
    v16 = UFG::qSymbol::create_from_string(&v28, "CockFight");
    UFG::GameStatAction::Money::SendTransactionTelemetry(v16, v15, v6);
  }
  v17 = UFG::GameStatTracker::Instance();
  v18 = UFG::GameStatTracker::GetStat(v17, GamblingLoss);
  v19 = UFG::GameStatTracker::Instance();
  v20 = (unsigned __int64)UFG::GameStatTracker::GetStat(v19, GamblingEarnings) - v18;
  v21 = UFG::OSuiteLeaderboardManager::Instance();
  v22 = UFG::OSuiteLeaderboardManager::GetLeaderboardDataUsingLeaderboardName(v21, "StatAwardsGambler");
  UFG::DataSynchronizer::SetMaxToGlobalSnapshot(v22, v20);
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  pval.Type = 0;
  `eh vector destructor iterator'(&ptr, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 402
// RVA: 0x5E8D40
__int64 __fastcall UFG::UIHKScreenCockFight::GetSelectedFighterIndexFromFlash(UFG::UIHKScreenCockFight *this)
{
  unsigned int v1; // ebx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h]

  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(this->mMovie, &pval, "gFighterIndex");
  v1 = (signed int)pval.mValue.NValue;
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  return v1;
}

// File Line: 413
// RVA: 0x5EDEA0
void __fastcall UFG::UIHKScreenCockFight::Invoke(UFG::UIHKScreenCockFight *this, UFG::qString *cmd)
{
  UFG::qString *v2; // rbx
  Scaleform::GFx::Movie *v3; // rcx
  UFG::qString *v4; // rcx

  v2 = cmd;
  if ( !this->mMovie )
    this->mMovie = this->mRenderable->m_movie.pObject;
  v3 = this->mMovie;
  if ( v3 )
  {
    Scaleform::GFx::Movie::Invoke(v3, cmd->mData, 0i64, 0i64, 0);
    v4 = v2;
  }
  else
  {
    v4 = cmd;
  }
  UFG::qString::~qString(v4);
}

// File Line: 432
// RVA: 0x60DA10
void __fastcall UFG::UIHKScreenCockFight::ShowHelpBar(UFG::UIHKScreenCockFight *this)
{
  UFG::UIHKScreenCockFight::eState v1; // ecx
  int v2; // ecx
  int v3; // ecx
  UFG::UIHKHelpBarWidget *v4; // rsi
  unsigned int v5; // ebx
  UFG::UIHKScreenGlobalOverlay *v6; // rax
  signed __int64 v7; // rdi
  UFG::UIHKHelpBarWidget *v8; // rdi
  unsigned int v9; // ebx
  UFG::UIHKHelpBarWidget *v10; // rdi
  unsigned int v11; // ebx
  UFG::UIHKHelpBarWidget *v12; // rdi
  unsigned int v13; // ebx
  UFG::UIHKHelpBarData data; // [rsp+20h] [rbp-D8h]
  __int64 v15; // [rsp+268h] [rbp+170h]

  v15 = -2i64;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis
    || UFG::UIHKScreenGlobalOverlay::mThis == (UFG::UIHKScreenGlobalOverlay *)-144i64 )
  {
    return;
  }
  v1 = this->mState;
  if ( v1 == STATE_INIT )
  {
    v12 = &gHelpBarSentinel;
    if ( UFG::UIHKScreenGlobalOverlay::mThis )
      v12 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v13 = UFG::qStringHash32("COCKFIGHT", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v13;
    *(_QWORD *)&data.priority = 0i64;
    _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$COMMON_ACCEPT_UPPERCASE");
    UFG::qString::Set(&data.Captions[1], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 32), &customWorldMapCaption);
    *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
    *(_QWORD *)data.MessageIds = 0i64;
    *(_QWORD *)&data.MessageIds[2] = 0i64;
    UFG::UIHKHelpBarWidget::Show(v12, &data);
    UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
    `eh vector destructor iterator'(
      &data.Captions[5].mStringHash32,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    goto LABEL_21;
  }
  v2 = v1 - 1;
  if ( !v2 )
  {
    v10 = &gHelpBarSentinel;
    if ( UFG::UIHKScreenGlobalOverlay::mThis )
      v10 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v11 = UFG::qStringHash32("COCKFIGHT", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v11;
    *(_QWORD *)&data.priority = 0i64;
    _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$COMMON_ACCEPT_UPPERCASE");
    UFG::qString::Set(&data.Captions[1], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 32), &customWorldMapCaption);
    *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
    *(_QWORD *)data.MessageIds = 0i64;
    *(_QWORD *)&data.MessageIds[2] = 0i64;
    UFG::UIHKHelpBarWidget::Show(v10, &data);
    UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
    `eh vector destructor iterator'(
      &data.Captions[5].mStringHash32,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    goto LABEL_21;
  }
  v3 = v2 - 1;
  if ( !v3 )
  {
    v8 = &gHelpBarSentinel;
    if ( UFG::UIHKScreenGlobalOverlay::mThis )
      v8 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v9 = UFG::qStringHash32("COCKFIGHT", 0xFFFFFFFF);
    UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
    data.id = v9;
    *(_QWORD *)&data.priority = 0i64;
    _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$COMMON_ACCEPT_UPPERCASE");
    UFG::qString::Set(&data.Captions[1], "$COMMON_BACK_UPPERCASE");
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 32), &customWorldMapCaption);
    *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
    *(_QWORD *)data.MessageIds = 0i64;
    *(_QWORD *)&data.MessageIds[2] = 0i64;
    UFG::UIHKHelpBarWidget::Show(v8, &data);
    UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
    `eh vector destructor iterator'(
      &data.Captions[5].mStringHash32,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
LABEL_21:
    `eh vector destructor iterator'(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
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
    _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
    *(_QWORD *)&data.Buttons[4] = 0i64;
    UFG::qString::Set(data.Captions, "$COMMON_EXIT_UPPERCASE");
    UFG::qString::Set(&data.Captions[1], &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 32), &customWorldMapCaption);
    UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 32), &customWorldMapCaption);
    *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
    *(_QWORD *)data.MessageIds = 0i64;
    *(_QWORD *)&data.MessageIds[2] = 0i64;
    UFG::UIHKHelpBarWidget::Show(v4, &data);
    UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
    `eh vector destructor iterator'(
      &data.Captions[5].mStringHash32,
      0x28ui64,
      6,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    `eh vector destructor iterator'(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
    v6 = UFG::UIHKScreenGlobalOverlay::mThis;
    if ( !UFG::UIHKScreenGlobalOverlay::mThis )
      v6 = &gGlobalOverlaySentinel;
    v7 = (signed __int64)&v6->HelpBar;
    *(_BYTE *)(v7 + 1) |= COERCE_FLOAT(COERCE_UNSIGNED_INT(v6->HelpBar.mYOffset - -20.0) & _xmm) > 0.001;
    *(_DWORD *)(v7 + 612) = -1046478848;
  }
}

// File Line: 496
// RVA: 0x5ECF60
void __fastcall UFG::UIHKScreenCockFight::HideHelpBar(UFG::UIHKScreenCockFight *this)
{
  UFG::UIHKHelpBarWidget *v1; // rbx
  unsigned int v2; // eax

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v1 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v2 = UFG::qStringHash32("COCKFIGHT", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(v1, v2);
  }
}

