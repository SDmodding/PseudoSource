// File Line: 54
// RVA: 0x5C60A0
void __fastcall UFG::UIHKScreenMartialArts::UIHKScreenMartialArts(UFG::UIHKScreenMartialArts *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax

  v1 = (UFG::qNode<UFG::UIScreen,UFG::UIScreen> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreen::`vftable;
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIHKScreenMartialArts::`vftable;
  this->mState = 0;
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
  UFG::UIHKScreenMartialArts *v1; // rbx
  unsigned int v2; // eax
  UFG::UIScreenTextureManager *v3; // rax
  unsigned int v4; // esi
  signed __int64 v5; // rbp
  UFG::qString *v6; // rdi
  unsigned int v7; // er8
  signed __int64 v8; // rdx
  unsigned int v9; // eax
  UFG::UIHKMoveData **v10; // rcx

  v1 = this;
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
  if ( v1->mNewMoveArray.size )
  {
    v5 = 8i64;
    do
    {
      v6 = &v1->mNewMoveArray.p[v4]->name;
      if ( v6 )
      {
        UFG::qString::~qString(v6 + 1);
        UFG::qString::~qString(v6);
        operator delete[](v6);
      }
      v7 = ++v4;
      if ( v4 != v1->mNewMoveArray.size )
      {
        v8 = v5;
        do
        {
          *(UFG::UIHKMoveData **)((char *)v1->mNewMoveArray.p + v8 - 8) = *(UFG::UIHKMoveData **)((char *)v1->mNewMoveArray.p
                                                                                                + v8);
          ++v7;
          v8 += 8i64;
        }
        while ( v7 != v1->mNewMoveArray.size );
      }
      v9 = v1->mNewMoveArray.size;
      if ( v9 > 1 )
        v1->mNewMoveArray.size = v9 - 1;
      else
        v1->mNewMoveArray.size = 0;
      v5 += 8i64;
    }
    while ( v4 < v1->mNewMoveArray.size );
  }
  UFG::GameCameraComponent::EndDOFOverride(0);
  v10 = v1->mNewMoveArray.p;
  if ( v10 )
    operator delete[](v10);
  v1->mNewMoveArray.p = 0i64;
  *(_QWORD *)&v1->mNewMoveArray.size = 0i64;
  UFG::UIScreen::~UIScreen((UFG::UIScreen *)&v1->vfptr);
}

// File Line: 75
// RVA: 0x632C70
void __fastcall UFG::UIHKScreenMartialArts::init(UFG::UIHKScreenMartialArts *this, UFG::UICommandData *data)
{
  UFG::UIHKScreenMartialArts *v2; // rbx
  UFG::Controller *v3; // rcx
  UFG::GameStatTracker *v4; // rax
  bool v5; // zf

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
  UFG::UIHKScreenMartialArts::RefreshMoveList(v2);
  v5 = v2->mMovie == 0i64;
  v2->mState = 1;
  if ( !v5 )
    UFG::UIHKScreenMartialArts::ShowHelpBar(v2);
  v2->mState = 3;
  v2->mSelectedMoveIndex = UFG::UIHKScreenMartialArts::GetSelectedMoveIndexFromFlash(v2);
}

// File Line: 103
// RVA: 0x5D25B0
void __fastcall UFG::UIHKScreenMartialArts::AddMove(UFG::UIHKScreenMartialArts *this, UFG::qString *name, UFG::qString *type, bool isOffensive)
{
  bool v4; // bl
  UFG::qString *v5; // rbp
  UFG::qString *v6; // r14
  UFG::UIHKScreenMartialArts *v7; // r15
  UFG::qString *v8; // rax
  UFG::UIHKMoveData *v9; // rdi
  __int64 v10; // r13
  unsigned int v11; // ebx
  unsigned int v12; // edx
  unsigned int v13; // edx

  v4 = isOffensive;
  v5 = type;
  v6 = name;
  v7 = this;
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
  UFG::qString::Set(&v9->name, v6->mData, v6->mLength, 0i64, 0);
  UFG::qString::Set(&v9->type, v5->mData, v5->mLength, 0i64, 0);
  v9->isOffensive = v4;
  v10 = v7->mNewMoveArray.size;
  v11 = v10 + 1;
  v12 = v7->mNewMoveArray.capacity;
  if ( (signed int)v10 + 1 > v12 )
  {
    if ( v12 )
      v13 = 2 * v12;
    else
      v13 = 1;
    for ( ; v13 < v11; v13 *= 2 )
      ;
    if ( v13 <= 2 )
      v13 = 2;
    if ( v13 - v11 > 0x10000 )
      v13 = v10 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v7->mNewMoveArray,
      v13,
      "qArray.Add");
  }
  v7->mNewMoveArray.size = v11;
  v7->mNewMoveArray.p[v10] = v9;
  UFG::UIHKScreenMartialArts::RefreshMoveList(v7);
  Scaleform::GFx::Movie::Invoke(v7->mMovie, "MartialArts_PlayIntro", 0i64, 0i64, 0);
  v7->mSelectedMoveIndex = UFG::UIHKScreenMartialArts::GetSelectedMoveIndexFromFlash(v7);
  UFG::qString::~qString(v6);
  UFG::qString::~qString(v5);
}

// File Line: 136
// RVA: 0x6006B0
void __fastcall UFG::UIHKScreenMartialArts::RefreshMoveList(UFG::UIHKScreenMartialArts *this)
{
  UFG::UIHKScreenMartialArts *v1; // rbx
  __int64 v2; // rax
  UFG::qString *v3; // rdi
  Scaleform::GFx::Movie *v4; // rcx
  UFG::qString *v5; // rcx
  unsigned int i; // esi
  signed __int64 v7; // rdi
  char *v8; // r14
  __int64 v9; // r14
  bool v10; // di
  __int64 v11; // [rsp+18h] [rbp-79h]
  char *v12; // [rsp+28h] [rbp-69h]
  char ptr; // [rsp+30h] [rbp-61h]
  char v14; // [rsp+38h] [rbp-59h]
  __int64 v15; // [rsp+48h] [rbp-49h]
  unsigned int v16; // [rsp+50h] [rbp-41h]
  __int64 v17; // [rsp+58h] [rbp-39h]
  char v18; // [rsp+68h] [rbp-29h]
  __int64 v19; // [rsp+78h] [rbp-19h]
  unsigned int v20; // [rsp+80h] [rbp-11h]
  __int64 v21; // [rsp+88h] [rbp-9h]
  __int64 v22; // [rsp+98h] [rbp+7h]
  __int64 v23; // [rsp+C8h] [rbp+37h]
  __int64 v24; // [rsp+F8h] [rbp+67h]

  v22 = -2i64;
  v1 = this;
  UFG::qString::qString((UFG::qString *)&v23, "MartialArts_ClearMoveList");
  v3 = (UFG::qString *)v2;
  v24 = v2;
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
  for ( i = 0; i < v1->mNewMoveArray.size; ++i )
  {
    `eh vector constructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
    v7 = i;
    v8 = v1->mNewMoveArray.p[v7]->name.mData;
    if ( ((unsigned int)Scaleform::GFx::Value::~Value >> 6) & 1 )
      (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v11 + 16i64))(v11, &ptr, v12);
    v12 = v8;
    v9 = (__int64)v1->mNewMoveArray.p[v7]->type.mData;
    if ( (v16 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, &v14, v17);
      v15 = 0i64;
    }
    v16 = 6;
    v17 = v9;
    v10 = v1->mNewMoveArray.p[v7]->isOffensive;
    if ( (v20 >> 6) & 1 )
    {
      (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
      v19 = 0i64;
    }
    v20 = 2;
    LOBYTE(v21) = v10;
    Scaleform::GFx::Movie::Invoke(v1->mMovie, "MartialArts_AddMove", 0i64, (Scaleform::GFx::Value *)&ptr, 3u);
    `eh vector destructor iterator(&ptr, 0x30ui64, 3, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
  }
}

// File Line: 153
// RVA: 0x6255B0
bool __fastcall UFG::UIHKScreenMartialArts::handleMessage(UFG::UIHKScreenMartialArts *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // edi
  UFG::UIHKScreenMartialArts *v5; // rbx
  int v6; // eax
  UFG::qString *v8; // rax
  UFG::qString v9; // [rsp+38h] [rbp-30h]

  v3 = msg;
  v4 = msgId;
  v5 = this;
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
    if ( v5->mState == 3 )
    {
      v6 = UFG::UIHKScreenMartialArts::GetSelectedMoveIndexFromFlash(v5);
      v5->mSelectedMoveIndex = v6;
      v5->mSelectedMove = v5->mNewMoveArray.p[v6];
      v5->mIsDone = 1;
    }
    return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  }
  if ( msgId == UI_HASH_DPAD_LEFT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_LEFT_30 )
  {
    if ( this->mState != 3 )
      return 1;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    UFG::qString::qString(&v9, "MartialArts_PrevMove");
LABEL_19:
    UFG::UIHKScreenMartialArts::Invoke(v5, v8);
    v5->mSelectedMoveIndex = UFG::UIHKScreenMartialArts::GetSelectedMoveIndexFromFlash(v5);
    return 1;
  }
  if ( msgId == UI_HASH_DPAD_RIGHT_PRESSED_30 || msgId == UI_HASH_THUMBSTICK_LEFT_RIGHT_30 )
  {
    if ( this->mState != 3 )
      return 0;
    if ( UFG::HudAudio::m_instance )
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
        0xEDB4A8C7,
        0i64,
        0,
        0i64);
    UFG::qString::qString(&v9, "MartialArts_NextMove");
    goto LABEL_19;
  }
  if ( msgId == UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    if ( this->mState == 3 )
    {
      UFG::UIHKScreenMartialArts::PopScreen(this);
      return 1;
    }
    return 0;
  }
  return UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
}

// File Line: 232
// RVA: 0x5E9030
__int64 __fastcall UFG::UIHKScreenMartialArts::GetSelectedMoveIndexFromFlash(UFG::UIHKScreenMartialArts *this)
{
  unsigned int v1; // ebx
  Scaleform::GFx::Value pval; // [rsp+28h] [rbp-40h]

  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  Scaleform::GFx::Movie::GetVariable(this->mMovie, &pval, "gMoveIndex");
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

// File Line: 259
// RVA: 0x5EDF80
void __fastcall UFG::UIHKScreenMartialArts::Invoke(UFG::UIHKScreenMartialArts *this, UFG::qString *cmd)
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

// File Line: 279
// RVA: 0x60E750
void __fastcall UFG::UIHKScreenMartialArts::ShowHelpBar(UFG::UIHKScreenMartialArts *this)
{
  UFG::UIHKScreenMartialArts::eState v1; // eax
  UFG::UIHKHelpBarWidget *v2; // rdi
  unsigned int v3; // ebx
  UFG::UIHKHelpBarWidget *v4; // rdi
  unsigned int v5; // ebx
  UFG::UIHKHelpBarData data; // [rsp+30h] [rbp-C8h]

  if ( UFG::UIHKScreenGlobalOverlay::mThis )
  {
    if ( UFG::UIHKScreenGlobalOverlay::mThis != (UFG::UIHKScreenGlobalOverlay *)-144i64 )
    {
      v1 = this->mState;
      if ( (signed int)v1 >= 0 )
      {
        if ( (signed int)v1 <= 2 )
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
          UFG::qString::Set(data.Captions, "$COMMON_MOVE_SELECTION_UPPERCASE");
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
          `eh vector destructor iterator(
            &data.Captions[5].mStringHash32,
            0x28ui64,
            6,
            (void (__fastcall *)(void *))UFG::qString::~qString);
        }
        else
        {
          if ( v1 != 3 )
            return;
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
          UFG::qString::Set(data.Captions, "$MA_CHANGE_MOVE_UPPERCASE");
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

