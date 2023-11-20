// File Line: 56
// RVA: 0x5C5160
void __fastcall UFG::UIHKScreenFightClub::UIHKScreenFightClub(UFG::UIHKScreenFightClub *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenFightClub::`vftable';
  this->mState = 0;
  this->mIsDone = 0;
  this->mWelcomeIndex = 0;
  this->mSelectedFighterIndex = -1;
  this->mFighterArray.p = 0i64;
  *(_QWORD *)&this->mFighterArray.size = 0i64;
  this->mSelectedFighter = 0i64;
  this->mCurrentBet = -1;
  this->mWeiMoney = 0;
  UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(&this->DOF);
}

// File Line: 61
// RVA: 0x5CA950
void __fastcall UFG::UIHKScreenFightClub::~UIHKScreenFightClub(UFG::UIHKScreenFightClub *this)
{
  UFG::UIHKScreenFightClub *v1; // rbx
  unsigned int v2; // eax
  UFG::UIScreenTextureManager *v3; // rax
  unsigned int v4; // esi
  signed __int64 v5; // rbp
  UFG::qString *v6; // rdi
  unsigned int v7; // er8
  signed __int64 v8; // rdx
  unsigned int v9; // eax
  UFG::UIHKFighterData **v10; // rcx

  v1 = this;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenFightClub::`vftable';
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
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "FightClub");
  v4 = 0;
  if ( v1->mFighterArray.size )
  {
    v5 = 8i64;
    do
    {
      v6 = &v1->mFighterArray.p[v4]->name;
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
          *(UFG::UIHKFighterData **)((char *)v1->mFighterArray.p + v8 - 8) = *(UFG::UIHKFighterData **)((char *)v1->mFighterArray.p + v8);
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
  UFG::GameCameraComponent::EndDOFOverride(0);
  v10 = v1->mFighterArray.p;
  if ( v10 )
    operator delete[](v10);
  v1->mFighterArray.p = 0i64;
  *(_QWORD *)&v1->mFighterArray.size = 0i64;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 77
// RVA: 0x631760
void __fastcall UFG::UIHKScreenFightClub::init(UFG::UIHKScreenFightClub *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenFightClub *v2; // rbx
  UFG::Controller *v3; // rcx
  UFG::GameStatTracker *v4; // rax
  Scaleform::GFx::Movie *v5; // rcx

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
  UFG::UIHKScreenFightClub::RefreshFighterList(v2);
  v5 = v2->mMovie;
  v2->mState = 1;
  if ( v5 )
  {
    Scaleform::GFx::Movie::Invoke(v5, "FightClub_PlayIntro", 0i64, 0i64, 0);
    UFG::UIHKScreenFightClub::ShowHelpBar(v2);
  }
}

// File Line: 145
// RVA: 0x5D1CD0
void __fastcall UFG::UIHKScreenFightClub::AddFigther(UFG::UIHKScreenFightClub *this, UFG::qString *name, UFG::qString *gang, UFG::qString *style, int age, int weight, int height, int odds)
{
  UFG::qString *v8; // rbp
  UFG::qString *v9; // r14
  UFG::qString *v10; // r15
  UFG::UIHKScreenFightClub *v11; // r13
  UFG::qString *v12; // rax
  UFG::UIHKFighterData *v13; // rbx
  __int64 v14; // r12
  unsigned int v15; // edi
  unsigned int v16; // edx
  unsigned int v17; // edx

  v8 = style;
  v9 = gang;
  v10 = name;
  v11 = this;
  v12 = (UFG::qString *)UFG::qMalloc(0x88ui64, "UIHKFighterData", 0i64);
  v13 = (UFG::UIHKFighterData *)v12;
  if ( v12 )
  {
    UFG::qString::qString(v12);
    UFG::qString::qString(&v13->gang);
    UFG::qString::qString(&v13->style);
  }
  else
  {
    v13 = 0i64;
  }
  UFG::qString::Set(&v13->name, v10->mData, v10->mLength, 0i64, 0);
  UFG::qString::Set(&v13->gang, v9->mData, v9->mLength, 0i64, 0);
  UFG::qString::Set(&v13->style, v8->mData, v8->mLength, 0i64, 0);
  v13->age = age;
  v13->weight = weight;
  v13->height = height;
  v13->odds = odds;
  v14 = v11->mFighterArray.size;
  v15 = v14 + 1;
  v16 = v11->mFighterArray.capacity;
  if ( (signed int)v14 + 1 > v16 )
  {
    if ( v16 )
      v17 = 2 * v16;
    else
      v17 = 1;
    for ( ; v17 < v15; v17 *= 2 )
      ;
    if ( v17 <= 2 )
      v17 = 2;
    if ( v17 - v15 > 0x10000 )
      v17 = v14 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v11->mFighterArray,
      v17,
      "qArray.Add");
  }
  v11->mFighterArray.size = v15;
  v11->mFighterArray.p[v14] = v13;
  UFG::UIHKScreenFightClub::RefreshFighterList(v11);
  UFG::qString::~qString(v10);
  UFG::qString::~qString(v9);
  UFG::qString::~qString(v8);
}

// File Line: 180
// RVA: 0x600280
void __fastcall UFG::UIHKScreenFightClub::RefreshFighterList(UFG::UIHKScreenFightClub *this)
{
  UFG::UIHKScreenFightClub *v1; // rbx
  __int64 v2; // rax
  UFG::qString *v3; // rdi
  Scaleform::GFx::Movie *v4; // rcx
  UFG::qString *v5; // rcx
  unsigned int i; // er14
  __int64 v7; // rsi
  __int64 v8; // rsi
  __int64 v9; // rsi
  double v10; // xmm6_8
  double v11; // xmm6_8
  double v12; // xmm6_8
  double v13; // xmm6_8
  char ptr; // [rsp+30h] [rbp-A8h]
  __int64 v15; // [rsp+40h] [rbp-98h]
  unsigned int v16; // [rsp+48h] [rbp-90h]
  __int64 v17; // [rsp+50h] [rbp-88h]
  __int64 v18; // [rsp+58h] [rbp-80h]
  char v19; // [rsp+60h] [rbp-78h]
  char v20; // [rsp+68h] [rbp-70h]
  __int64 v21; // [rsp+70h] [rbp-68h]
  __int64 v22; // [rsp+78h] [rbp-60h]
  unsigned int v23; // [rsp+80h] [rbp-58h]
  __int64 v24; // [rsp+88h] [rbp-50h]
  char v25; // [rsp+98h] [rbp-40h]
  __int64 v26; // [rsp+A8h] [rbp-30h]
  unsigned int v27; // [rsp+B0h] [rbp-28h]
  double v28; // [rsp+B8h] [rbp-20h]
  char v29; // [rsp+C8h] [rbp-10h]
  __int64 v30; // [rsp+D8h] [rbp+0h]
  unsigned int v31; // [rsp+E0h] [rbp+8h]
  double v32; // [rsp+E8h] [rbp+10h]
  char v33; // [rsp+F8h] [rbp+20h]
  __int64 v34; // [rsp+108h] [rbp+30h]
  unsigned int v35; // [rsp+110h] [rbp+38h]
  double v36; // [rsp+118h] [rbp+40h]
  char v37; // [rsp+128h] [rbp+50h]
  __int64 v38; // [rsp+138h] [rbp+60h]
  unsigned int v39; // [rsp+140h] [rbp+68h]
  double v40; // [rsp+148h] [rbp+70h]
  __int64 v41; // [rsp+158h] [rbp+80h]
  __int64 v42; // [rsp+188h] [rbp+B0h]
  __int64 v43; // [rsp+1C8h] [rbp+F0h]

  v41 = -2i64;
  v1 = this;
  UFG::qString::qString((UFG::qString *)&v42, "FightClub_ClearFighterList");
  v3 = (UFG::qString *)v2;
  v43 = v2;
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
    `eh vector constructor iterator'(&ptr, 0x30ui64, 7, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v7 = (__int64)v1->mFighterArray.p[i]->name.mData;
    if ( (v16 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, &ptr, v17);
      v15 = 0i64;
    }
    v16 = 6;
    v17 = v7;
    v8 = (__int64)v1->mFighterArray.p[i]->gang.mData;
    if ( ((unsigned int)v22 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v21 + 16i64))(v21, &v19, v18);
      v21 = 0i64;
    }
    LODWORD(v22) = 6;
    v18 = v8;
    v9 = (__int64)v1->mFighterArray.p[i]->style.mData;
    if ( (v23 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v22 + 16i64))(v22, &v20, v24);
      v22 = 0i64;
    }
    v23 = 6;
    v24 = v9;
    v10 = (double)v1->mFighterArray.p[i]->age;
    if ( (v27 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v26 + 16i64))(
        v26,
        &v25,
        COERCE_DOUBLE(*(_QWORD *)&v28));
      v26 = 0i64;
    }
    v27 = 5;
    v28 = v10;
    v11 = (double)v1->mFighterArray.p[i]->weight;
    if ( (v31 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v30 + 16i64))(
        v30,
        &v29,
        COERCE_DOUBLE(*(_QWORD *)&v32));
      v30 = 0i64;
    }
    v31 = 5;
    v32 = v11;
    v12 = (double)v1->mFighterArray.p[i]->height;
    if ( (v35 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v34 + 16i64))(
        v34,
        &v33,
        COERCE_DOUBLE(*(_QWORD *)&v36));
      v34 = 0i64;
    }
    v35 = 5;
    v36 = v12;
    v13 = (double)v1->mFighterArray.p[i]->odds;
    if ( (v39 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v38 + 16i64))(
        v38,
        &v37,
        COERCE_DOUBLE(*(_QWORD *)&v40));
      v38 = 0i64;
    }
    v39 = 5;
    v40 = v13;
    Scaleform::GFx::Movie::Invoke(v1->mMovie, "FightClub_AddFighter", 0i64, (Scaleform::GFx::Value *)&ptr, 7u);
    `eh vector destructor iterator'(&ptr, 0x30ui64, 7, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 215
// RVA: 0x61A2C0
void __fastcall UFG::UIHKScreenFightClub::UpdateBetAmount(UFG::UIHKScreenFightClub *this)
{
  UFG::UIHKScreenFightClub *v1; // rbx
  double v2; // xmm6_8
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]

  v1 = this;
  `eh vector constructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v2 = (double)v1->mCurrentBet;
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 5;
  pargs.mValue.NValue = v2;
  Scaleform::GFx::Movie::Invoke(v1->mMovie, "FightClub_UpdateBetAmount", 0i64, &pargs, 1u);
  `eh vector destructor iterator'(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 226
// RVA: 0x622A30
bool __fastcall UFG::UIHKScreenFightClub::handleMessage(UFG::UIHKScreenFightClub *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // edi
  UFG::UIHKScreenFightClub *v5; // rbx
  int v7; // eax
  UFG::UIHKScreenFightClub::eFightClubOption v8; // eax
  UFG::qString *v9; // rax
  UFG::qString *v10; // rax
  __int32 v11; // ecx
  int v12; // ecx
  UFG::qString *v13; // rax
  UFG::qString *v14; // rax
  __int32 v15; // ecx
  UFG::qString *v16; // rax
  __int32 v17; // ecx
  UFG::qString *v18; // rax
  UFG::qString *v19; // rax
  UFG::qString v20; // [rsp+30h] [rbp-1h]
  UFG::qString v21; // [rsp+58h] [rbp+27h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
  if ( msgId == UI_HASH_FIGHTCLUB_INTRO_COMPLETE_20 )
  {
    this->mState = 2;
    return 1;
  }
  if ( msgId == UI_HASH_OPTION_HIGHLIGHTED_30 )
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0x4A3D1F6Cu,
        0i64,
        0,
        0i64);
    switch ( v5->mState )
    {
      case 2:
        if ( (unsigned int)UFG::UIHKScreenFightClub::GetWelcomeIndex(v5) )
        {
          if ( (unsigned int)UFG::UIHKScreenFightClub::GetWelcomeIndex(v5) == 1 )
          {
            v5->mIsDone = 0;
            v5->mFightClubOption = 1;
          }
        }
        else
        {
          v5->mIsDone = 1;
        }
        v5->mState = 3;
        UFG::qString::qString(&v21, "FightClub_GotoFighterSelect");
        UFG::UIHKScreenFightClub::Invoke(v5, v10);
        UFG::UIHKScreenFightClub::ShowHelpBar(v5);
        break;
      case 3:
        v7 = UFG::UIHKScreenFightClub::GetSelectedFighterIndexFromFlash(v5);
        v5->mSelectedFighterIndex = v7;
        v5->mSelectedFighter = v5->mFighterArray.p[v7];
        v8 = v5->mFightClubOption;
        if ( v8 == 1 )
        {
          v5->mCurrentBet = 500;
          UFG::UIHKScreenFightClub::UpdateBetAmount(v5);
          UFG::qString::qString(&v20, "FightClub_GotoPlaceBet");
          UFG::UIHKScreenFightClub::Invoke(v5, v9);
          v5->mState = 4;
          UFG::UIHKScreenFightClub::ShowHelpBar(v5);
          v5->mSelectedFighter = v5->mFighterArray.p[v5->mSelectedFighterIndex];
        }
        else if ( v8 == OPTION_FIGHT )
        {
          v5->mIsDone = 1;
        }
        break;
      case 4:
        v5->mIsDone = 1;
        break;
    }
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
  {
    if ( this->mState != 2 )
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    UFG::qString::qString(&v21, "FightClub_PrevWelcomeIndex");
    goto LABEL_67;
  }
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
  {
    if ( this->mState != 2 )
      return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    UFG::qString::qString(&v21, "FightClub_NextWelcomeIndex");
LABEL_67:
    UFG::UIHKScreenFightClub::Invoke(v5, v19);
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
  if ( msgId == UI_HASH_DPAD_LEFT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
  {
    v17 = this->mState - 3;
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
        v5->mCurrentBet -= 500;
        UFG::UIHKScreenFightClub::UpdateBetAmount(v5);
      }
    }
    else
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xEDB4A8C7,
          0i64,
          0,
          0i64);
      UFG::qString::qString(&v21, "FightClub_PrevFighter");
      UFG::UIHKScreenFightClub::Invoke(v5, v18);
    }
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_RIGHT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
  {
    v15 = this->mState - 3;
    if ( !v15 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xEDB4A8C7,
          0i64,
          0,
          0i64);
      UFG::qString::qString(&v21, "FightClub_NextFighter");
      UFG::UIHKScreenFightClub::Invoke(v5, v16);
      return 1;
    }
    if ( v15 == 1 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xEDB4A8C7,
          0i64,
          0,
          0i64);
      v5->mCurrentBet += 500;
      UFG::UIHKScreenFightClub::UpdateBetAmount(v5);
    }
    return 1;
  }
  if ( msgId != UI_HASH_BUTTON_BACK_PRESSED_30 )
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  v11 = this->mState - 2;
  if ( v11 )
  {
    v12 = v11 - 1;
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
      UFG::qString::qString(&v21, "FightClub_GotoFighterSelect");
      UFG::UIHKScreenFightClub::Invoke(v5, v13);
      v5->mCurrentBet = -1;
      v5->mState = 3;
      UFG::UIHKScreenFightClub::ShowHelpBar(v5);
    }
    else
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
          0xA4E5BFBD,
          0i64,
          0,
          0i64);
      UFG::qString::qString(&v20, "FightClub_GotoWelcome");
      UFG::UIHKScreenFightClub::Invoke(v5, v14);
      v5->mState = 2;
      UFG::UIHKScreenFightClub::ShowHelpBar(v5);
    }
    return 1;
  }
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xA4E5BFBD,
      0i64,
      0,
      0i64);
  UFG::UIHKScreenMartialArts::PopScreen((UFG::UIHKScreenMartialArts *)v5);
  return 1;
}

// File Line: 378
// RVA: 0x5E8DC0
__int64 __fastcall UFG::UIHKScreenFightClub::GetSelectedFighterIndexFromFlash(UFG::UIHKScreenFightClub *this)
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

// File Line: 389
// RVA: 0x5EA620
__int64 __fastcall UFG::UIHKScreenFightClub::GetWelcomeIndex(UFG::UIHKScreenFightClub *this)
{
  unsigned int v1; // ebx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h]

  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(this->mMovie, &pval, "gWelcomeIndex");
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

// File Line: 409
// RVA: 0x5F4310
void __fastcall UFG::UIHKScreenMartialArts::PopScreen(UFG::UIHKScreenMartialArts *this)
{
  UFG::UIHKHelpBarWidget *v1; // rbx
  unsigned int v2; // eax

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    v1 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v2 = UFG::qStringHash32("FIGHT_CLUB", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(v1, v2);
  }
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xFFFFFFFF);
}

// File Line: 416
// RVA: 0x5EDF10
void __fastcall UFG::UIHKScreenFightClub::Invoke(UFG::UIHKScreenFightClub *this, UFG::qString *cmd)
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

// File Line: 436
// RVA: 0x60DF10
void __fastcall UFG::UIHKScreenFightClub::ShowHelpBar(UFG::UIHKScreenFightClub *this)
{
  UFG::UIHKScreenFightClub::eState v1; // eax
  UFG::UIHKHelpBarWidget *v2; // rdi
  unsigned int v3; // ebx
  UFG::UIHKHelpBarWidget *v4; // rdi
  unsigned int v5; // ebx
  UFG::UIHKHelpBarWidget *v6; // rdi
  unsigned int v7; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-C8h]

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    if ( UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-144i64 )
    {
      v1 = this->mState;
      if ( (signed int)v1 >= 0 )
      {
        if ( (signed int)v1 > 2 )
        {
          if ( v1 == 3 )
          {
            v4 = &gHelpBarSentinel;
            if ( UFG::UIHKScreenGlobalOverlay::mThis )
              v4 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
            v5 = UFG::qStringHash32("FIGHT_CLUB", 0xFFFFFFFF);
            UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
            data.id = v5;
            data.priority = 0;
            data.alignment = 1;
            _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
            *(_QWORD *)&data.Buttons[4] = 0i64;
            UFG::qString::Set(data.Captions, "$FIGHTCLUB_CHANGE_FIGHTER_UPPERCASE");
            UFG::qString::Set((UFG::qString *)((char *)data.Captions + 32), "$COMMON_ACCEPT_UPPERCASE");
            UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), "$COMMON_BACK_UPPERCASE");
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
            goto LABEL_18;
          }
          if ( v1 == 4 )
          {
            v2 = &gHelpBarSentinel;
            if ( UFG::UIHKScreenGlobalOverlay::mThis )
              v2 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
            v3 = UFG::qStringHash32("FIGHT_CLUB", 0xFFFFFFFF);
            UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
            data.id = v3;
            data.priority = 0;
            data.alignment = 1;
            _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
            *(_QWORD *)&data.Buttons[4] = 0i64;
            UFG::qString::Set(data.Captions, "$FIGHTCLUB_CHANGE_BET_UPPERCASE");
            UFG::qString::Set((UFG::qString *)((char *)data.Captions + 32), "$COMMON_ACCEPT_UPPERCASE");
            UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), "$COMMON_BACK_UPPERCASE");
            UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 32), &customWorldMapCaption);
            UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 32), &customWorldMapCaption);
            UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 32), &customWorldMapCaption);
            *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
            *(_QWORD *)data.MessageIds = 0i64;
            *(_QWORD *)&data.MessageIds[2] = 0i64;
            UFG::UIHKHelpBarWidget::Show(v2, &data);
            UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
            `eh vector destructor iterator'(
              &data.Captions[5].mStringHash32,
              0x28ui64,
              6,
              (void (__fastcall *)(void *))UFG::qString::~qString);
            goto LABEL_18;
          }
          if ( v1 != 5 )
            return;
        }
        v6 = &gHelpBarSentinel;
        if ( UFG::UIHKScreenGlobalOverlay::mThis )
          v6 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
        v7 = UFG::qStringHash32("FIGHT_CLUB", 0xFFFFFFFF);
        UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
        data.id = v7;
        data.priority = 0;
        data.alignment = 1;
        _mm_store_si128((__m128i *)data.Buttons, _mm_load_si128((const __m128i *)&_xmm));
        *(_QWORD *)&data.Buttons[4] = 0i64;
        UFG::qString::Set(data.Captions, "$COMMON_MOVE_SELECTION_UPPERCASE");
        UFG::qString::Set((UFG::qString *)((char *)data.Captions + 32), "$COMMON_ACCEPT_UPPERCASE");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[1] + 32), "$COMMON_BACK_UPPERCASE");
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[2] + 32), &customWorldMapCaption);
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[3] + 32), &customWorldMapCaption);
        UFG::qString::Set((UFG::qString *)((char *)&data.Captions[4] + 32), &customWorldMapCaption);
        *(_QWORD *)&data.Icons[5].mStringHash32 = 0i64;
        *(_QWORD *)data.MessageIds = 0i64;
        *(_QWORD *)&data.MessageIds[2] = 0i64;
        UFG::UIHKHelpBarWidget::Show(v6, &data);
        UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
        `eh vector destructor iterator'(
          &data.Captions[5].mStringHash32,
          0x28ui64,
          6,
          (void (__fastcall *)(void *))UFG::qString::~qString);
LABEL_18:
        `eh vector destructor iterator'(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
        return;
      }
    }
  }
}

