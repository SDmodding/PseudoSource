// File Line: 56
// RVA: 0x5C5160
void __fastcall UFG::UIHKScreenFightClub::UIHKScreenFightClub(UFG::UIHKScreenFightClub *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenFightClub::`vftable;
  this->mState = STATE_INIT;
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
  unsigned int v2; // eax
  UFG::UIScreenTextureManager *v3; // rax
  unsigned int v4; // esi
  __int64 v5; // rbp
  UFG::UIHKFighterData *v6; // rdi
  unsigned int v7; // r8d
  __int64 v8; // rdx
  unsigned int size; // eax
  UFG::UIHKFighterData **p; // rcx

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenFightClub::`vftable;
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
  if ( this->mFighterArray.size )
  {
    v5 = 8i64;
    do
    {
      v6 = this->mFighterArray.p[v4];
      if ( v6 )
      {
        UFG::qString::~qString(&v6->style);
        UFG::qString::~qString(&v6->gang);
        UFG::qString::~qString(&v6->name);
        operator delete[](v6);
      }
      v7 = ++v4;
      if ( v4 != this->mFighterArray.size )
      {
        v8 = v5;
        do
        {
          *(UFG::UIHKFighterData **)((char *)this->mFighterArray.p + v8 - 8) = *(UFG::UIHKFighterData **)((char *)this->mFighterArray.p + v8);
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
  UFG::GameCameraComponent::EndDOFOverride(DOFOverridePriority_0);
  p = this->mFighterArray.p;
  if ( p )
    operator delete[](p);
  this->mFighterArray.p = 0i64;
  *(_QWORD *)&this->mFighterArray.size = 0i64;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 77
// RVA: 0x631760
void __fastcall UFG::UIHKScreenFightClub::init(UFG::UIHKScreenFightClub *this, UFG::UICommandData *data)
{
  UFG::Controller *v3; // rcx
  UFG::GameStatTracker *v4; // rax
  Scaleform::GFx::Movie *mMovie; // rcx

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
  UFG::UIHKScreenFightClub::RefreshFighterList(this);
  mMovie = this->mMovie;
  this->mState = STATE_BRIGHTNESS;
  if ( mMovie )
  {
    Scaleform::GFx::Movie::Invoke(mMovie, "FightClub_PlayIntro", 0i64, 0i64, 0);
    UFG::UIHKScreenFightClub::ShowHelpBar(this);
  }
}

// File Line: 145
// RVA: 0x5D1CD0
void __fastcall UFG::UIHKScreenFightClub::AddFigther(
        UFG::UIHKScreenFightClub *this,
        UFG::qString *name,
        UFG::qString *gang,
        UFG::qString *style,
        int age,
        int weight,
        int height,
        int odds)
{
  UFG::qString *v12; // rax
  UFG::UIHKFighterData *v13; // rbx
  __int64 size; // r12
  unsigned int v15; // edi
  unsigned int capacity; // edx
  unsigned int v17; // edx

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
  UFG::qString::Set(&v13->name, name->mData, name->mLength, 0i64, 0);
  UFG::qString::Set(&v13->gang, gang->mData, gang->mLength, 0i64, 0);
  UFG::qString::Set(&v13->style, style->mData, style->mLength, 0i64, 0);
  v13->age = age;
  v13->weight = weight;
  v13->height = height;
  v13->odds = odds;
  size = this->mFighterArray.size;
  v15 = size + 1;
  capacity = this->mFighterArray.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v17 = 2 * capacity;
    else
      v17 = 1;
    for ( ; v17 < v15; v17 *= 2 )
      ;
    if ( v17 <= 2 )
      v17 = 2;
    if ( v17 - v15 > 0x10000 )
      v17 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mFighterArray,
      v17,
      "qArray.Add");
  }
  this->mFighterArray.size = v15;
  this->mFighterArray.p[size] = v13;
  UFG::UIHKScreenFightClub::RefreshFighterList(this);
  UFG::qString::~qString(name);
  UFG::qString::~qString(gang);
  UFG::qString::~qString(style);
}

// File Line: 180
// RVA: 0x600280
void __fastcall UFG::UIHKScreenFightClub::RefreshFighterList(UFG::UIHKScreenFightClub *this)
{
  __int64 v2; // rax
  UFG::qString *v3; // rdi
  Scaleform::GFx::Movie *mMovie; // rcx
  UFG::qString *v5; // rcx
  unsigned int i; // r14d
  char *mData; // rsi
  char *v8; // rsi
  char *v9; // rsi
  double age; // xmm6_8
  double weight; // xmm6_8
  double height; // xmm6_8
  double odds; // xmm6_8
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-A8h] BYREF
  char v15[8]; // [rsp+60h] [rbp-78h] BYREF
  char v16[8]; // [rsp+68h] [rbp-70h] BYREF
  __int64 v17; // [rsp+70h] [rbp-68h]
  __int64 v18; // [rsp+78h] [rbp-60h]
  int v19; // [rsp+80h] [rbp-58h]
  char *v20; // [rsp+88h] [rbp-50h]
  char v21[16]; // [rsp+98h] [rbp-40h] BYREF
  __int64 v22; // [rsp+A8h] [rbp-30h]
  int v23; // [rsp+B0h] [rbp-28h]
  double v24; // [rsp+B8h] [rbp-20h]
  char v25[16]; // [rsp+C8h] [rbp-10h] BYREF
  __int64 v26; // [rsp+D8h] [rbp+0h]
  int v27; // [rsp+E0h] [rbp+8h]
  double v28; // [rsp+E8h] [rbp+10h]
  char v29[16]; // [rsp+F8h] [rbp+20h] BYREF
  __int64 v30; // [rsp+108h] [rbp+30h]
  int v31; // [rsp+110h] [rbp+38h]
  double v32; // [rsp+118h] [rbp+40h]
  char v33[16]; // [rsp+128h] [rbp+50h] BYREF
  __int64 v34; // [rsp+138h] [rbp+60h]
  int v35; // [rsp+140h] [rbp+68h]
  double v36; // [rsp+148h] [rbp+70h]
  __int64 v37; // [rsp+158h] [rbp+80h]
  UFG::qString v38; // [rsp+188h] [rbp+B0h] BYREF
  __int64 v39; // [rsp+1C8h] [rbp+F0h]

  v37 = -2i64;
  UFG::qString::qString(&v38, "FightClub_ClearFighterList");
  v3 = (UFG::qString *)v2;
  v39 = v2;
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
    `eh vector constructor iterator(&ptr, 0x30ui64, 7, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
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
    v8 = this->mFighterArray.p[i]->gang.mData;
    if ( (v18 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, unsigned __int64))(*(_QWORD *)v17 + 16i64))(v17, v15, ptr.DataAux);
      v17 = 0i64;
    }
    LODWORD(v18) = 6;
    ptr.DataAux = (unsigned __int64)v8;
    v9 = this->mFighterArray.p[i]->style.mData;
    if ( (v19 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v18 + 16i64))(v18, v16, v20);
      v18 = 0i64;
    }
    v19 = 6;
    v20 = v9;
    age = (double)this->mFighterArray.p[i]->age;
    if ( (v23 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v22 + 16i64))(
        v22,
        v21,
        COERCE_DOUBLE(*(_QWORD *)&v24));
      v22 = 0i64;
    }
    v23 = 5;
    v24 = age;
    weight = (double)this->mFighterArray.p[i]->weight;
    if ( (v27 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v26 + 16i64))(
        v26,
        v25,
        COERCE_DOUBLE(*(_QWORD *)&v28));
      v26 = 0i64;
    }
    v27 = 5;
    v28 = weight;
    height = (double)this->mFighterArray.p[i]->height;
    if ( (v31 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v30 + 16i64))(
        v30,
        v29,
        COERCE_DOUBLE(*(_QWORD *)&v32));
      v30 = 0i64;
    }
    v31 = 5;
    v32 = height;
    odds = (double)this->mFighterArray.p[i]->odds;
    if ( (v35 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v34 + 16i64))(
        v34,
        v33,
        COERCE_DOUBLE(*(_QWORD *)&v36));
      v34 = 0i64;
    }
    v35 = 5;
    v36 = odds;
    Scaleform::GFx::Movie::Invoke(this->mMovie, "FightClub_AddFighter", 0i64, &ptr, 7u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 7, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 215
// RVA: 0x61A2C0
void __fastcall UFG::UIHKScreenFightClub::UpdateBetAmount(UFG::UIHKScreenFightClub *this)
{
  Scaleform::GFx::Value::ValueUnion v2; // xmm6_8
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h] BYREF

  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  v2.NValue = (double)this->mCurrentBet;
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Number;
  pargs.mValue = v2;
  Scaleform::GFx::Movie::Invoke(this->mMovie, "FightClub_UpdateBetAmount", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 226
// RVA: 0x622A30
bool __fastcall UFG::UIHKScreenFightClub::handleMessage(
        UFG::UIHKScreenFightClub *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  int SelectedFighterIndexFromFlash; // eax
  UFG::UIHKScreenFightClub::eFightClubOption mFightClubOption; // eax
  UFG::qString *v9; // rax
  UFG::qString *v10; // rax
  __int32 v11; // ecx
  __int32 v12; // ecx
  UFG::qString *v13; // rax
  UFG::qString *v14; // rax
  __int32 v15; // ecx
  UFG::qString *v16; // rax
  __int32 v17; // ecx
  UFG::qString *v18; // rax
  UFG::qString *v19; // rax
  UFG::qString v20; // [rsp+30h] [rbp-1h] BYREF
  UFG::qString v21; // [rsp+58h] [rbp+27h] BYREF

  if ( msgId == UI_HASH_FIGHTCLUB_INTRO_COMPLETE_20 )
  {
    this->mState = STATE_VOLUME;
    return 1;
  }
  if ( msgId == UI_HASH_OPTION_HIGHLIGHTED_30 )
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
    switch ( this->mState )
    {
      case STATE_VOLUME:
        if ( (unsigned int)UFG::UIHKScreenFightClub::GetWelcomeIndex(this) )
        {
          if ( (unsigned int)UFG::UIHKScreenFightClub::GetWelcomeIndex(this) == 1 )
          {
            this->mIsDone = 0;
            this->mFightClubOption = OPTION_BET;
          }
        }
        else
        {
          this->mIsDone = 1;
        }
        this->mState = STATE_UISCALE;
        UFG::qString::qString(&v21, "FightClub_GotoFighterSelect");
        UFG::UIHKScreenFightClub::Invoke(this, v10);
        UFG::UIHKScreenFightClub::ShowHelpBar(this);
        break;
      case STATE_UISCALE:
        SelectedFighterIndexFromFlash = UFG::UIHKScreenFightClub::GetSelectedFighterIndexFromFlash(this);
        this->mSelectedFighterIndex = SelectedFighterIndexFromFlash;
        this->mSelectedFighter = this->mFighterArray.p[SelectedFighterIndexFromFlash];
        mFightClubOption = this->mFightClubOption;
        if ( mFightClubOption == OPTION_BET )
        {
          this->mCurrentBet = 500;
          UFG::UIHKScreenFightClub::UpdateBetAmount(this);
          UFG::qString::qString(&v20, "FightClub_GotoPlaceBet");
          UFG::UIHKScreenFightClub::Invoke(this, v9);
          this->mState = NUM_CALIBRATION_STATES;
          UFG::UIHKScreenFightClub::ShowHelpBar(this);
          this->mSelectedFighter = this->mFighterArray.p[this->mSelectedFighterIndex];
        }
        else if ( mFightClubOption == OPTION_FIGHT )
        {
          this->mIsDone = 1;
        }
        break;
      case NUM_CALIBRATION_STATES:
        this->mIsDone = 1;
        break;
    }
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( msgId == UI_HASH_DPAD_UP_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_UP_30 )
  {
    if ( this->mState != STATE_VOLUME )
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    UFG::qString::qString(&v21, "FightClub_PrevWelcomeIndex");
    goto LABEL_67;
  }
  if ( msgId == UI_HASH_DPAD_DOWN_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_DOWN_30 )
  {
    if ( this->mState != STATE_VOLUME )
      return UFG::UIScreen::handleMessage(this, msgId, msg);
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    UFG::qString::qString(&v21, "FightClub_NextWelcomeIndex");
LABEL_67:
    UFG::UIHKScreenFightClub::Invoke(this, v19);
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( msgId == UI_HASH_DPAD_LEFT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
  {
    v17 = this->mState - 3;
    if ( v17 )
    {
      if ( v17 == 1 )
      {
        if ( UFG::HudAudio::m_instance )
          UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
        this->mCurrentBet -= 500;
        UFG::UIHKScreenFightClub::UpdateBetAmount(this);
      }
    }
    else
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
      UFG::qString::qString(&v21, "FightClub_PrevFighter");
      UFG::UIHKScreenFightClub::Invoke(this, v18);
    }
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_RIGHT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
  {
    v15 = this->mState - 3;
    if ( !v15 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
      UFG::qString::qString(&v21, "FightClub_NextFighter");
      UFG::UIHKScreenFightClub::Invoke(this, v16);
      return 1;
    }
    if ( v15 == 1 )
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
      this->mCurrentBet += 500;
      UFG::UIHKScreenFightClub::UpdateBetAmount(this);
    }
    return 1;
  }
  if ( msgId != UI_HASH_BUTTON_BACK_PRESSED_30 )
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  v11 = this->mState - 2;
  if ( v11 )
  {
    v12 = v11 - 1;
    if ( v12 )
    {
      if ( v12 != 1 )
        return 0;
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
      UFG::qString::qString(&v21, "FightClub_GotoFighterSelect");
      UFG::UIHKScreenFightClub::Invoke(this, v13);
      this->mCurrentBet = -1;
      this->mState = STATE_UISCALE;
      UFG::UIHKScreenFightClub::ShowHelpBar(this);
    }
    else
    {
      if ( UFG::HudAudio::m_instance )
        UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
      UFG::qString::qString(&v20, "FightClub_GotoWelcome");
      UFG::UIHKScreenFightClub::Invoke(this, v14);
      this->mState = STATE_VOLUME;
      UFG::UIHKScreenFightClub::ShowHelpBar(this);
    }
    return 1;
  }
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
  UFG::UIHKScreenMartialArts::PopScreen((UFG::UIHKScreenMartialArts *)this);
  return 1;
}

// File Line: 378
// RVA: 0x5E8DC0
__int64 __fastcall UFG::UIHKScreenFightClub::GetSelectedFighterIndexFromFlash(UFG::UIHKScreenFightClub *this)
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

// File Line: 389
// RVA: 0x5EA620
__int64 __fastcall UFG::UIHKScreenFightClub::GetWelcomeIndex(UFG::UIHKScreenFightClub *this)
{
  unsigned int NValue; // ebx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h] BYREF

  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(this->mMovie, &pval, "gWelcomeIndex");
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

// File Line: 409
// RVA: 0x5F4310
void __fastcall UFG::UIHKScreenMartialArts::PopScreen(UFG::UIHKScreenMartialArts *this)
{
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v2; // eax

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
    v2 = UFG::qStringHash32("FIGHT_CLUB", 0xFFFFFFFF);
    UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v2);
  }
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
}

// File Line: 416
// RVA: 0x5EDF10
void __fastcall UFG::UIHKScreenFightClub::Invoke(UFG::UIHKScreenFightClub *this, UFG::qString *cmd)
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

// File Line: 436
// RVA: 0x60DF10
void __fastcall UFG::UIHKScreenFightClub::ShowHelpBar(UFG::UIHKScreenFightClub *this)
{
  UFG::UIHKScreenFightClub::eState mState; // eax
  UFG::UIHKHelpBarWidget *v2; // rdi
  unsigned int v3; // ebx
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v5; // ebx
  UFG::UIHKHelpBarWidget *v6; // rdi
  unsigned int v7; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-D0h] BYREF

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    if ( UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-144i64 )
    {
      mState = this->mState;
      if ( mState >= STATE_INIT )
      {
        if ( mState > STATE_VOLUME )
        {
          if ( mState == STATE_UISCALE )
          {
            p_HelpBar = &gHelpBarSentinel;
            if ( UFG::UIHKScreenGlobalOverlay::mThis )
              p_HelpBar = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
            v5 = UFG::qStringHash32("FIGHT_CLUB", 0xFFFFFFFF);
            UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
            data.id = v5;
            data.priority = PRIORITY_ONE;
            data.alignment = ALIGN_RIGHT;
            *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
            *(_QWORD *)&data.Buttons[4] = 0i64;
            UFG::qString::Set(data.Captions, "$FIGHTCLUB_CHANGE_FIGHTER_UPPERCASE");
            UFG::qString::Set(&data.Captions[1], "$COMMON_ACCEPT_UPPERCASE");
            UFG::qString::Set(&data.Captions[2], "$COMMON_BACK_UPPERCASE");
            UFG::qString::Set(&data.Captions[3], &customCaption);
            UFG::qString::Set(&data.Captions[4], &customCaption);
            UFG::qString::Set(&data.Captions[5], &customCaption);
            memset(data.MessageIds, 0, sizeof(data.MessageIds));
            UFG::UIHKHelpBarWidget::Show(p_HelpBar, &data);
            UFG::qString::~qString(&data.CustomTexturePack);
            `eh vector destructor iterator(
              data.Icons,
              0x28ui64,
              6,
              (void (__fastcall *)(void *))UFG::qString::~qString);
            goto LABEL_18;
          }
          if ( mState == NUM_CALIBRATION_STATES )
          {
            v2 = &gHelpBarSentinel;
            if ( UFG::UIHKScreenGlobalOverlay::mThis )
              v2 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
            v3 = UFG::qStringHash32("FIGHT_CLUB", 0xFFFFFFFF);
            UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
            data.id = v3;
            data.priority = PRIORITY_ONE;
            data.alignment = ALIGN_RIGHT;
            *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
            *(_QWORD *)&data.Buttons[4] = 0i64;
            UFG::qString::Set(data.Captions, "$FIGHTCLUB_CHANGE_BET_UPPERCASE");
            UFG::qString::Set(&data.Captions[1], "$COMMON_ACCEPT_UPPERCASE");
            UFG::qString::Set(&data.Captions[2], "$COMMON_BACK_UPPERCASE");
            UFG::qString::Set(&data.Captions[3], &customCaption);
            UFG::qString::Set(&data.Captions[4], &customCaption);
            UFG::qString::Set(&data.Captions[5], &customCaption);
            memset(data.MessageIds, 0, sizeof(data.MessageIds));
            UFG::UIHKHelpBarWidget::Show(v2, &data);
            UFG::qString::~qString(&data.CustomTexturePack);
            `eh vector destructor iterator(
              data.Icons,
              0x28ui64,
              6,
              (void (__fastcall *)(void *))UFG::qString::~qString);
            goto LABEL_18;
          }
          if ( mState != (NUM_CALIBRATION_STATES|STATE_BRIGHTNESS) )
            return;
        }
        v6 = &gHelpBarSentinel;
        if ( UFG::UIHKScreenGlobalOverlay::mThis )
          v6 = &UFG::UIHKScreenGlobalOverlay::mThis->HelpBar;
        v7 = UFG::qStringHash32("FIGHT_CLUB", 0xFFFFFFFF);
        UFG::UIHKHelpBarData::UIHKHelpBarData(&data);
        data.id = v7;
        data.priority = PRIORITY_ONE;
        data.alignment = ALIGN_RIGHT;
        *(__m128i *)data.Buttons = _mm_load_si128((const __m128i *)&_xmm);
        *(_QWORD *)&data.Buttons[4] = 0i64;
        UFG::qString::Set(data.Captions, "$COMMON_MOVE_SELECTION_UPPERCASE");
        UFG::qString::Set(&data.Captions[1], "$COMMON_ACCEPT_UPPERCASE");
        UFG::qString::Set(&data.Captions[2], "$COMMON_BACK_UPPERCASE");
        UFG::qString::Set(&data.Captions[3], &customCaption);
        UFG::qString::Set(&data.Captions[4], &customCaption);
        UFG::qString::Set(&data.Captions[5], &customCaption);
        memset(data.MessageIds, 0, sizeof(data.MessageIds));
        UFG::UIHKHelpBarWidget::Show(v6, &data);
        UFG::qString::~qString(&data.CustomTexturePack);
        `eh vector destructor iterator(data.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
LABEL_18:
        `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
      }
    }
  }
}

