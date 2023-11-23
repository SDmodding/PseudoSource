// File Line: 54
// RVA: 0x5C60A0
void __fastcall UFG::UIHKScreenMartialArts::UIHKScreenMartialArts(UFG::UIHKScreenMartialArts *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenMartialArts::`vftable;
  this->mState = STATE_INIT;
  this->mIsDone = 0;
  this->mSelectedMoveIndex = 0;
  this->mNewMoveArray.p = 0i64;
  *(_QWORD *)&this->mNewMoveArray.size = 0i64;
  this->mSelectedMove = 0i64;
  this->mCurrentBet = -1;
  this->mWeiMoney = 0;
  UFG::UIHKDepthOfFieldWidget::UIHKDepthOfFieldWidget(&this->DOF);
}

// File Line: 59
// RVA: 0x5CB6F0
void __fastcall UFG::UIHKScreenMartialArts::~UIHKScreenMartialArts(UFG::UIHKScreenMartialArts *this)
{
  unsigned int v2; // eax
  UFG::UIScreenTextureManager *v3; // rax
  unsigned int v4; // esi
  __int64 v5; // rbp
  UFG::UIHKMoveData *v6; // rdi
  unsigned int v7; // r8d
  __int64 v8; // rdx
  unsigned int size; // eax
  UFG::UIHKMoveData **p; // rcx

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenMartialArts::`vftable;
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
  UFG::UIScreenTextureManager::ReleaseScreen(v3, "MartialArts");
  v4 = 0;
  if ( this->mNewMoveArray.size )
  {
    v5 = 8i64;
    do
    {
      v6 = this->mNewMoveArray.p[v4];
      if ( v6 )
      {
        UFG::qString::~qString(&v6->type);
        UFG::qString::~qString(&v6->name);
        operator delete[](v6);
      }
      v7 = ++v4;
      if ( v4 != this->mNewMoveArray.size )
      {
        v8 = v5;
        do
        {
          *(UFG::UIHKMoveData **)((char *)this->mNewMoveArray.p + v8 - 8) = *(UFG::UIHKMoveData **)((char *)this->mNewMoveArray.p
                                                                                                  + v8);
          ++v7;
          v8 += 8i64;
        }
        while ( v7 != this->mNewMoveArray.size );
      }
      size = this->mNewMoveArray.size;
      if ( size > 1 )
        this->mNewMoveArray.size = size - 1;
      else
        this->mNewMoveArray.size = 0;
      v5 += 8i64;
    }
    while ( v4 < this->mNewMoveArray.size );
  }
  UFG::GameCameraComponent::EndDOFOverride(DOFOverridePriority_0);
  p = this->mNewMoveArray.p;
  if ( p )
    operator delete[](p);
  this->mNewMoveArray.p = 0i64;
  *(_QWORD *)&this->mNewMoveArray.size = 0i64;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 75
// RVA: 0x632C70
void __fastcall UFG::UIHKScreenMartialArts::init(UFG::UIHKScreenMartialArts *this, UFG::UICommandData *data)
{
  UFG::Controller *v3; // rcx
  UFG::GameStatTracker *v4; // rax
  bool v5; // zf

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
  UFG::UIHKScreenMartialArts::RefreshMoveList(this);
  v5 = this->mMovie == 0i64;
  this->mState = STATE_BRIGHTNESS;
  if ( !v5 )
    UFG::UIHKScreenMartialArts::ShowHelpBar(this);
  this->mState = STATE_UISCALE;
  this->mSelectedMoveIndex = UFG::UIHKScreenMartialArts::GetSelectedMoveIndexFromFlash(this);
}

// File Line: 103
// RVA: 0x5D25B0
void __fastcall UFG::UIHKScreenMartialArts::AddMove(
        UFG::UIHKScreenMartialArts *this,
        UFG::qString *name,
        UFG::qString *type,
        bool isOffensive)
{
  UFG::qString *v8; // rax
  UFG::UIHKMoveData *v9; // rdi
  __int64 size; // r13
  unsigned int v11; // ebx
  unsigned int capacity; // edx
  unsigned int v13; // edx

  v8 = (UFG::qString *)UFG::qMalloc(0x58ui64, "UIHKMoveData ", 0i64);
  v9 = (UFG::UIHKMoveData *)v8;
  if ( v8 )
  {
    UFG::qString::qString(v8);
    UFG::qString::qString(&v9->type);
  }
  else
  {
    v9 = 0i64;
  }
  UFG::qString::Set(&v9->name, name->mData, name->mLength, 0i64, 0);
  UFG::qString::Set(&v9->type, type->mData, type->mLength, 0i64, 0);
  v9->isOffensive = isOffensive;
  size = this->mNewMoveArray.size;
  v11 = size + 1;
  capacity = this->mNewMoveArray.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v13 = 2 * capacity;
    else
      v13 = 1;
    for ( ; v13 < v11; v13 *= 2 )
      ;
    if ( v13 <= 2 )
      v13 = 2;
    if ( v13 - v11 > 0x10000 )
      v13 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mNewMoveArray,
      v13,
      "qArray.Add");
  }
  this->mNewMoveArray.size = v11;
  this->mNewMoveArray.p[size] = v9;
  UFG::UIHKScreenMartialArts::RefreshMoveList(this);
  Scaleform::GFx::Movie::Invoke(this->mMovie, "MartialArts_PlayIntro", 0i64, 0i64, 0);
  this->mSelectedMoveIndex = UFG::UIHKScreenMartialArts::GetSelectedMoveIndexFromFlash(this);
  UFG::qString::~qString(name);
  UFG::qString::~qString(type);
}

// File Line: 136
// RVA: 0x6006B0
void __fastcall UFG::UIHKScreenMartialArts::RefreshMoveList(UFG::UIHKScreenMartialArts *this)
{
  __int64 v2; // rax
  UFG::qString *v3; // rdi
  Scaleform::GFx::Movie *mMovie; // rcx
  UFG::qString *v5; // rcx
  unsigned int i; // esi
  char *mData; // r14
  char *v8; // r14
  bool isOffensive; // di
  __int64 v10; // [rsp+18h] [rbp-79h]
  char *v11; // [rsp+28h] [rbp-69h]
  Scaleform::GFx::Value ptr; // [rsp+30h] [rbp-61h] BYREF
  char v13[16]; // [rsp+68h] [rbp-29h] BYREF
  __int64 v14; // [rsp+78h] [rbp-19h]
  int v15; // [rsp+80h] [rbp-11h]
  __int64 v16; // [rsp+88h] [rbp-9h]
  __int64 v17; // [rsp+98h] [rbp+7h]
  UFG::qString v18; // [rsp+C8h] [rbp+37h] BYREF
  __int64 v19; // [rsp+F8h] [rbp+67h]

  v17 = -2i64;
  UFG::qString::qString(&v18, "MartialArts_ClearMoveList");
  v3 = (UFG::qString *)v2;
  v19 = v2;
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
  for ( i = 0; i < this->mNewMoveArray.size; ++i )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    mData = this->mNewMoveArray.p[i]->name.mData;
    if ( ((unsigned int)Scaleform::GFx::Value::~Value & 0x40) != 0 )
      (*(void (__fastcall **)(__int64, Scaleform::GFx::Value *, char *))(*(_QWORD *)v10 + 16i64))(v10, &ptr, v11);
    v11 = mData;
    v8 = this->mNewMoveArray.p[i]->type.mData;
    if ( (ptr.mValue.BValue & 0x40) != 0 )
    {
      (*(void (__fastcall **)(_QWORD, $41EDDC8CC4664C9FE26D4D23F9ACAEE4 *, unsigned __int64))(**(_QWORD **)&ptr.Type
                                                                                            + 16i64))(
        *(_QWORD *)&ptr.Type,
        &ptr.8,
        ptr.DataAux);
      *(_QWORD *)&ptr.Type = 0i64;
    }
    ptr.mValue.IValue = 6;
    ptr.DataAux = (unsigned __int64)v8;
    isOffensive = this->mNewMoveArray.p[i]->isOffensive;
    if ( (v15 & 0x40) != 0 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v14 + 16i64))(v14, v13, v16);
      v14 = 0i64;
    }
    v15 = 2;
    LOBYTE(v16) = isOffensive;
    Scaleform::GFx::Movie::Invoke(this->mMovie, "MartialArts_AddMove", 0i64, &ptr, 3u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 153
// RVA: 0x6255B0
bool __fastcall UFG::UIHKScreenMartialArts::handleMessage(
        UFG::UIHKScreenMartialArts *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  int SelectedMoveIndexFromFlash; // eax
  UFG::qString *v8; // rax
  UFG::qString v9; // [rsp+38h] [rbp-30h] BYREF

  if ( msgId == UI_HASH_OPTION_HIGHLIGHTED_30 )
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  if ( msgId == UI_HASH_BUTTON_ACCEPT_PRESSED_30 )
  {
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0x4A3D1F6Cu, 0i64, 0, 0i64);
    if ( this->mState == STATE_UISCALE )
    {
      SelectedMoveIndexFromFlash = UFG::UIHKScreenMartialArts::GetSelectedMoveIndexFromFlash(this);
      this->mSelectedMoveIndex = SelectedMoveIndexFromFlash;
      this->mSelectedMove = this->mNewMoveArray.p[SelectedMoveIndexFromFlash];
      this->mIsDone = 1;
    }
    return UFG::UIScreen::handleMessage(this, msgId, msg);
  }
  if ( msgId == UI_HASH_DPAD_LEFT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
  {
    if ( this->mState != STATE_UISCALE )
      return 1;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    UFG::qString::qString(&v9, "MartialArts_PrevMove");
LABEL_19:
    UFG::UIHKScreenMartialArts::Invoke(this, v8);
    this->mSelectedMoveIndex = UFG::UIHKScreenMartialArts::GetSelectedMoveIndexFromFlash(this);
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_RIGHT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
  {
    if ( this->mState != STATE_UISCALE )
      return 0;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xEDB4A8C7, 0i64, 0, 0i64);
    UFG::qString::qString(&v9, "MartialArts_NextMove");
    goto LABEL_19;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    if ( this->mState == STATE_UISCALE )
    {
      UFG::UIHKScreenMartialArts::PopScreen(this);
      return 1;
    }
    return 0;
  }
  return UFG::UIScreen::handleMessage(this, msgId, msg);
}

// File Line: 232
// RVA: 0x5E9030
__int64 __fastcall UFG::UIHKScreenMartialArts::GetSelectedMoveIndexFromFlash(UFG::UIHKScreenMartialArts *this)
{
  unsigned int NValue; // ebx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h] BYREF

  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  Scaleform::GFx::Movie::GetVariable(this->mMovie, &pval, "gMoveIndex");
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

// File Line: 259
// RVA: 0x5EDF80
void __fastcall UFG::UIHKScreenMartialArts::Invoke(UFG::UIHKScreenMartialArts *this, UFG::qString *cmd)
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

// File Line: 279
// RVA: 0x60E750
void __fastcall UFG::UIHKScreenMartialArts::ShowHelpBar(UFG::UIHKScreenMartialArts *this)
{
  UFG::UIHKScreenMartialArts::eState mState; // eax
  UFG::UIHKHelpBarWidget *v2; // rdi
  unsigned int v3; // ebx
  UFG::UIHKHelpBarWidget *p_HelpBar; // rdi
  unsigned int v5; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-C8h] BYREF

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    if ( UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-144i64 )
    {
      mState = this->mState;
      if ( mState >= STATE_INIT )
      {
        if ( mState <= STATE_VOLUME )
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
          UFG::qString::Set(data.Captions, "$COMMON_MOVE_SELECTION_UPPERCASE");
          UFG::qString::Set((UFG::qString *)&data.Captions[0].mStringHash32, "$COMMON_ACCEPT_UPPERCASE");
          UFG::qString::Set((UFG::qString *)&data.Captions[1].mStringHash32, "$COMMON_BACK_UPPERCASE");
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
        }
        else
        {
          if ( mState != STATE_UISCALE )
            return;
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
          UFG::qString::Set(data.Captions, "$MA_CHANGE_MOVE_UPPERCASE");
          UFG::qString::Set((UFG::qString *)&data.Captions[0].mStringHash32, "$COMMON_ACCEPT_UPPERCASE");
          UFG::qString::Set((UFG::qString *)&data.Captions[1].mStringHash32, "$COMMON_BACK_UPPERCASE");
          UFG::qString::Set((UFG::qString *)&data.Captions[2].mStringHash32, &customCaption);
          UFG::qString::Set((UFG::qString *)&data.Captions[3].mStringHash32, &customCaption);
          UFG::qString::Set((UFG::qString *)&data.Captions[4].mStringHash32, &customCaption);
          memset(&data.Icons[5].mStringHash32, 0, 24);
          UFG::UIHKHelpBarWidget::Show(v2, &data);
          UFG::qString::~qString((UFG::qString *)&data.MessageIds[4]);
          `eh vector destructor iterator(
            &data.Captions[5].mStringHash32,
            0x28ui64,
            6,
            (void (__fastcall *)(void *))UFG::qString::~qString);
        }
        `eh vector destructor iterator(data.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
      }
    }
  }
}

