// File Line: 24
// RVA: 0x156E1F0
__int64 anonymous_namespace_::_dynamic_initializer_for__nis_mixer_credits_in__()
{
  UFG::qWiseSymbol::create_from_string(&nis_mixer_credits_in, "nis_mixer_credits_in");
  return atexit((int (__fastcall *)())anonymous_namespace_::_dynamic_atexit_destructor_for__nis_mixer_credits_in__);
}

// File Line: 25
// RVA: 0x156E220
__int64 anonymous_namespace_::_dynamic_initializer_for__nis_mixer_credits_out__()
{
  UFG::qWiseSymbol::create_from_string(&nis_mixer_credits_out, "nis_mixer_credits_out");
  return atexit((int (__fastcall *)())anonymous_namespace_::_dynamic_atexit_destructor_for__nis_mixer_credits_out__);
}

// File Line: 26
// RVA: 0x156E250
__int64 anonymous_namespace_::_dynamic_initializer_for__nis_mixer_exit_to_game__()
{
  UFG::qWiseSymbol::create_from_string(&nis_mixer_exit_to_game_0, "nis_mixer_exit_to_game");
  return atexit((int (__fastcall *)())anonymous_namespace_::_dynamic_atexit_destructor_for__nis_mixer_exit_to_game__);
}

// File Line: 28
// RVA: 0x156E3C0
__int64 anonymous_namespace_::_dynamic_initializer_for__play_credits_end_game_music__()
{
  UFG::qWiseSymbol::create_from_string(&play_credits_end_game_music, "play_credits_end_game_music");
  return atexit((int (__fastcall *)())anonymous_namespace_::_dynamic_atexit_destructor_for__play_credits_end_game_music__);
}

// File Line: 29
// RVA: 0x1570960
__int64 anonymous_namespace_::_dynamic_initializer_for__stop_credits_end_game_music__()
{
  UFG::qWiseSymbol::create_from_string(&stop_credits_end_game_music, "stop_credits_end_game_music");
  return atexit((int (__fastcall *)())anonymous_namespace_::_dynamic_atexit_destructor_for__stop_credits_end_game_music__);
}

// File Line: 40
// RVA: 0x5F4360
void __fastcall UFG::UICreditsData::Populate(UFG::UICreditsData *this, UFG::qPropertySet *data)
{
  UFG::UICreditsSection *p; // rcx
  UFG::qString **p_p; // rbx
  unsigned int v6; // ebx
  UFG::qPropertyList *v7; // rax
  UFG::qPropertyList *v8; // r14
  unsigned int size; // edx
  unsigned int mNumElements; // ebp
  unsigned int v11; // edi
  unsigned int capacity; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // ebx
  __int64 v15; // rdi
  char *ValuePtr; // rax
  UFG::qPropertySet *v17; // rdx

  p = this->Sections.p;
  if ( p )
  {
    p_p = &p[-1].Names.p;
    `eh vector destructor iterator(
      p,
      0x68ui64,
      (int)p[-1].Names.p,
      (void (__fastcall *)(void *))UFG::UICreditsSection::~UICreditsSection);
    operator delete[](p_p);
  }
  v6 = 1;
  this->Sections.p = 0i64;
  *(_QWORD *)&this->Sections.size = 0i64;
  v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         data,
         (UFG::qArray<unsigned long,0> *)&UICreditsSymbol_section_list_0,
         DEPTH_RECURSE);
  v8 = v7;
  if ( v7 )
  {
    size = this->Sections.size;
    mNumElements = v7->mNumElements;
    if ( (int)(mNumElements - this->Sections.size) <= 0 )
    {
      v13 = this->Sections.size - v7->mNumElements;
      if ( v13 )
      {
        if ( v13 < size )
          this->Sections.size = size - v13;
        else
          this->Sections.size = 0;
      }
    }
    else
    {
      v11 = v7->mNumElements;
      capacity = this->Sections.capacity;
      if ( v11 > capacity )
      {
        if ( capacity )
          v6 = 2 * capacity;
        for ( ; v6 < v11; v6 *= 2 )
          ;
        if ( v6 - v11 > 0x10000 )
          v6 = v11 + 0x10000;
        UFG::qArray<UFG::UICreditsSection,0>::Reallocate(&this->Sections, v6, "Sections");
      }
      this->Sections.size = v11;
    }
    v14 = 0;
    if ( mNumElements )
    {
      v15 = 0i64;
      do
      {
        ValuePtr = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v14);
        if ( !ValuePtr || (v17 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr], !*(_QWORD *)ValuePtr) )
          v17 = 0i64;
        UFG::UICreditsSection::Populate(&this->Sections.p[v15], v17);
        ++v14;
        ++v15;
      }
      while ( v14 < mNumElements );
    }
  }
}

// File Line: 73
// RVA: 0x5F44A0
void __fastcall UFG::UICreditsSection::Populate(UFG::UICreditsSection *this, UFG::qPropertySet *data)
{
  unsigned int v4; // edi
  UFG::qSymbol *v5; // rax
  char *v6; // rax
  char *v7; // rax
  UFG::qString *p; // rcx
  unsigned int *p_mStringHash32; // rbx
  unsigned int v10; // ebx
  UFG::qPropertyList *v11; // rax
  UFG::qPropertyList *v12; // r13
  unsigned int mNumElements; // ebp
  unsigned int size; // edx
  unsigned int capacity; // eax
  __int64 v16; // rdi
  const char *v17; // rax

  v4 = 1;
  v5 = UFG::qPropertySet::Get<UFG::qSymbol>(
         data,
         (UFG::qArray<unsigned long,0> *)&UICreditsSymbol_section_type_0,
         DEPTH_RECURSE);
  if ( v5 )
    this->Type = (UFG::qSymbol)v5->mUID;
  UFG::qString::Set(&this->Heading, &customCaption);
  v6 = UFG::qPropertySet::Get<char const *>(
         data,
         (UFG::qArray<unsigned long,0> *)&UICreditsSymbol_heading_0,
         DEPTH_RECURSE);
  if ( v6 )
    UFG::qString::Set(&this->Heading, v6);
  UFG::qString::Set(&this->Body, &customCaption);
  v7 = UFG::qPropertySet::Get<char const *>(
         data,
         (UFG::qArray<unsigned long,0> *)&UICreditsSymbol_body_0,
         DEPTH_RECURSE);
  if ( v7 )
    UFG::qString::Set(&this->Body, v7);
  p = this->Names.p;
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
  v10 = 0;
  this->Names.p = 0i64;
  *(_QWORD *)&this->Names.size = 0i64;
  v11 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          data,
          (UFG::qArray<unsigned long,0> *)&UICreditsSymbol_names_list_0,
          DEPTH_RECURSE);
  v12 = v11;
  if ( v11 )
  {
    mNumElements = v11->mNumElements;
    if ( mNumElements )
    {
      size = this->Names.size;
      if ( (int)(mNumElements - size) <= 0 )
      {
        if ( size != mNumElements )
        {
          if ( size - mNumElements < size )
            this->Names.size = mNumElements;
          else
            this->Names.size = 0;
        }
      }
      else
      {
        capacity = this->Names.capacity;
        if ( mNumElements > capacity )
        {
          if ( capacity )
            v4 = 2 * capacity;
          for ( ; v4 < mNumElements; v4 *= 2 )
            ;
          if ( v4 - mNumElements > 0x10000 )
            v4 = mNumElements + 0x10000;
          UFG::qArray<UFG::qString,0>::Reallocate(&this->Names, v4, "Names");
        }
        this->Names.size = mNumElements;
      }
      v16 = 0i64;
      do
      {
        v17 = UFG::qPropertyList::Get<char const *>(v12, v10);
        UFG::qString::Set(&this->Names.p[v16], v17);
        ++v10;
        ++v16;
      }
      while ( v10 < mNumElements );
    }
  }
}

// File Line: 128
// RVA: 0x5C8A00
void __fastcall UFG::UIScreenCredits::UIScreenCredits(UFG::UIScreenCredits *this)
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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreenCredits::`vftable;
  this->mData.Sections.p = 0i64;
  *(_QWORD *)&this->mData.Sections.size = 0i64;
  this->mNextSectionIndex = 0;
}

// File Line: 134
// RVA: 0x5CE210
void __fastcall UFG::UIScreenCredits::~UIScreenCredits(UFG::UIScreenCredits *this)
{
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *p_HelpBar; // rbx
  unsigned int v5; // eax
  unsigned int mUID; // ebx
  unsigned int v7; // ecx
  unsigned int v8; // ecx
  unsigned int v9; // ebx
  UFG::GameStatTracker *v10; // rax
  UFG::GameSnapshot *TimeStat; // rax
  UFG::UICreditsSection *p; // rcx
  UFG::qString **p_p; // rbx

  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreenCredits::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Credits");
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  p_HelpBar = &v3->HelpBar;
  v5 = UFG::qStringHashUpper32("credits", -1);
  UFG::UIHKHelpBarWidget::Hide(p_HelpBar, v5);
  mUID = nis_mixer_credits_out.mUID;
  v7 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  if ( UFG::UIHK_NISOverlay::m_current_audio_event_index == 7 )
  {
    UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
    v7 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  }
  UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[v7] = mUID;
  v8 = v7 + 1;
  UFG::UIHK_NISOverlay::m_current_audio_event_index = v8;
  if ( UFG::UIHK_NISOverlay::m_curtains.m_state != STATE_CURTAIN_SHOWING )
  {
    UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
    v8 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  }
  if ( !UFG::UIScreenCredits::smTriggeredFromMainMenu )
  {
    v9 = nis_mixer_exit_to_game_0.mUID;
    if ( v8 == 7 )
    {
      UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
      v8 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
    }
    UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[v8] = v9;
    UFG::UIHK_NISOverlay::m_current_audio_event_index = v8 + 1;
    if ( UFG::UIHK_NISOverlay::m_curtains.m_state != STATE_CURTAIN_SHOWING )
      UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
    UFG::AudioEntity::CreateAndPlayEvent(
      UFG::AmbienceAudio::m_instance,
      stop_credits_end_game_music.mUID,
      0i64,
      0,
      0i64);
    if ( UFG::UIScreenCredits::smPauseMissionScoringTimer )
    {
      v10 = UFG::GameStatTracker::Instance();
      TimeStat = UFG::GameStatTracker::GetTimeStat(v10, ReservedFCTime1);
      UFG::SimpleTimer::Resume((UFG::SimpleTimer *)TimeStat);
    }
  }
  UFG::UIScreenCredits::smTriggeredFromMainMenu = 0;
  UFG::UIScreenCredits::smPauseMissionScoringTimer = 0;
  p = this->mData.Sections.p;
  if ( p )
  {
    p_p = &p[-1].Names.p;
    `eh vector destructor iterator(
      p,
      0x68ui64,
      (int)p[-1].Names.p,
      (void (__fastcall *)(void *))UFG::UICreditsSection::~UICreditsSection);
    operator delete[](p_p);
  }
  this->mData.Sections.p = 0i64;
  *(_QWORD *)&this->mData.Sections.size = 0i64;
  UFG::UIScreen::~UIScreen(this);
}

// File Line: 157
// RVA: 0x637CB0
void __fastcall UFG::UIScreenCredits::init(UFG::UIScreenCredits *this, UFG::UICommandData *data)
{
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *PropertySet; // rax
  unsigned int mUID; // ebx
  unsigned int v6; // ecx
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::GameSnapshot *TimeStat; // rax
  unsigned int v10; // esi
  int v11; // ecx
  __int64 v12; // rax
  __int64 v13; // rdi
  __int64 v14; // rbx
  int v15; // ecx
  __int64 v16; // rax
  __int64 v17; // rdi
  __int64 v18; // rbx
  UFG::UIHKScreenGlobalOverlay *v19; // rax
  UFG::UIHKHelpBarData dataa; // [rsp+40h] [rbp-258h] BYREF
  UFG::qSymbol result; // [rsp+2A0h] [rbp+8h] BYREF

  UFG::UIScreen::init(this, data);
  v3 = UFG::qSymbol::create_from_string(&result, "UI-Credits");
  PropertySet = UFG::PropertySetManager::GetPropertySet(v3);
  if ( PropertySet )
    UFG::UICreditsData::Populate(&this->mData, PropertySet);
  if ( this->mData.Sections.size )
  {
    UFG::UIScreenCredits::SpawnSection(this, this->mData.Sections.p, (float)this->mRenderable->m_height);
    ++this->mNextSectionIndex;
  }
  mUID = nis_mixer_credits_in.mUID;
  v6 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  if ( UFG::UIHK_NISOverlay::m_current_audio_event_index == 7 )
  {
    UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
    v6 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  }
  UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[v6] = mUID;
  UFG::UIHK_NISOverlay::m_current_audio_event_index = v6 + 1;
  if ( UFG::UIHK_NISOverlay::m_curtains.m_state != STATE_CURTAIN_SHOWING )
    UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
  if ( !UFG::UIScreenCredits::smTriggeredFromMainMenu )
  {
    UFG::AudioEntity::CreateAndPlayEvent(
      UFG::AmbienceAudio::m_instance,
      play_credits_end_game_music.mUID,
      0i64,
      0,
      0i64);
    v7 = UFG::GameStatTracker::Instance();
    UFG::UIScreenCredits::smPauseMissionScoringTimer = UFG::GameStatTracker::GetTimeStat(v7, ReservedFCTime1)->mTimes[0].mTimer.mIsStarted;
    if ( UFG::UIScreenCredits::smPauseMissionScoringTimer )
    {
      v8 = UFG::GameStatTracker::Instance();
      TimeStat = UFG::GameStatTracker::GetTimeStat(v8, ReservedFCTime1);
      UFG::PersistentData::Time::EndTimer(TimeStat->mTimes);
    }
  }
  UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
  dataa.id = UFG::qStringHashUpper32("credits", -1);
  dataa.alignment = ALIGN_LEFT;
  v10 = UI_HASH_BUTTON_BACK_PRESSED_30;
  v11 = 0;
  v12 = 0i64;
  while ( dataa.Buttons[v12] )
  {
    ++v11;
    if ( ++v12 >= 6 )
      goto LABEL_17;
  }
  v13 = v11;
  dataa.Buttons[v11] = BACK_BUTTON;
  v14 = v11;
  UFG::qString::Set(&dataa.Captions[v11], "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set(&dataa.Icons[v14], &customCaption);
  dataa.MessageIds[v13] = v10;
LABEL_17:
  v15 = 0;
  v16 = 0i64;
  while ( dataa.Buttons[v16] )
  {
    ++v15;
    if ( ++v16 >= 6 )
      goto LABEL_22;
  }
  v17 = v15;
  dataa.Buttons[v15] = R2_BUTTON;
  v18 = v15;
  UFG::qString::Set(&dataa.Captions[v15], "$COMMON_FAST_FORWARD_UPPERCASE");
  UFG::qString::Set(&dataa.Icons[v18], &customCaption);
  dataa.MessageIds[v17] = 0;
LABEL_22:
  v19 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v19 = &gGlobalOverlaySentinel;
  UFG::UIHKHelpBarWidget::Show(&v19->HelpBar, &dataa);
  UFG::qString::~qString(&dataa.CustomTexturePack);
  `eh vector destructor iterator(dataa.Icons, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
  `eh vector destructor iterator(dataa.Captions, 0x28ui64, 6, (void (__fastcall *)(void *))UFG::qString::~qString);
}

// File Line: 193
// RVA: 0x62F5D0
bool __fastcall UFG::UIScreenCredits::handleMessage(
        UFG::UIScreenCredits *this,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  float v6; // xmm1_4

  if ( msgId != UI_HASH_BUTTON_BACK_PRESSED_30 )
  {
    if ( msgId == UI_HASH_BUTTON_R2_PRESSED_30 )
    {
      v6 = FLOAT_160_0;
    }
    else
    {
      if ( msgId != UI_HASH_BUTTON_R2_RELEASED_30 )
        goto LABEL_9;
      v6 = FLOAT_40_0;
    }
    UFG::UIScreenCredits::Flash_SetScrollSpeed(this, v6);
    goto LABEL_9;
  }
  UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::HudAudio::m_instance, 0xA4E5BFBD, 0i64, 0, 0i64);
LABEL_9:
  UFG::UIScreen::handleMessage(this, msgId, msg);
  return 0;
}

// File Line: 214
// RVA: 0x6415C0
void __fastcall UFG::UIScreenCredits::update(UFG::UIScreenCredits *this, float elapsed)
{
  float m_height; // xmm6_4
  float ScrollPosition; // xmm3_4
  unsigned int mNextSectionIndex; // eax
  unsigned int v6; // eax
  UFG::qWiseSymbol result; // [rsp+70h] [rbp+18h] BYREF

  if ( !UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "NISPause") )
  {
    UFG::UIScreen::update(this, elapsed);
    UFG::UIScreenCredits::Flash_Update(this, elapsed);
    m_height = (float)this->mRenderable->m_height;
    ScrollPosition = UFG::UIScreenCredits::Flash_GetScrollPosition(this);
    if ( ScrollPosition < (float)(m_height - 80.0) )
    {
      mNextSectionIndex = this->mNextSectionIndex;
      if ( mNextSectionIndex >= this->mData.Sections.size )
      {
        if ( ScrollPosition < 0.0 )
          UFG::UIScreenManagerBase::queuePopScreen(UFG::UIScreenManager::s_instance, 0xFFFFFFFF);
      }
      else
      {
        UFG::UIScreenCredits::SpawnSection(this, &this->mData.Sections.p[mNextSectionIndex], m_height);
        ++this->mNextSectionIndex;
      }
    }
    if ( UFG::UIScreenCredits::smTriggeredFromMainMenu )
    {
      if ( (_S16_5 & 1) != 0 )
      {
        v6 = mus_id;
      }
      else
      {
        _S16_5 |= 1u;
        UFG::TiDo::GetInstance();
        v6 = UFG::TiDo::CalcWwiseUid("PLAY_MUS_FE_LIC");
        mus_id = v6;
      }
      if ( !UFG::AudioEntity::IsPlayingId(UFG::Music::sm_instance, v6) )
      {
        UFG::qWiseSymbol::create_from_string(&result, "play_mus_fe_lic");
        UFG::Music::MusicEvent(result.mUID);
        _((AMD_HD3D *)result.mUID);
      }
    }
    else if ( !UFG::AudioEntity::IsPlayingId(UFG::AmbienceAudio::m_instance, play_credits_end_game_music.mUID) )
    {
      UFG::AudioEntity::CreateAndPlayEvent(
        UFG::AmbienceAudio::m_instance,
        play_credits_end_game_music.mUID,
        0i64,
        0,
        0i64);
    }
  }
}

// File Line: 274
// RVA: 0x611BA0
void __fastcall UFG::UIScreenCredits::SpawnSection(
        UFG::UIScreenCredits *this,
        UFG::UICreditsSection *section,
        float yPos)
{
  unsigned int size; // eax
  __int64 v6; // rdi
  __int64 v7; // rbx

  if ( section->Type.mUID == UICreditsSymbol_music_credit_0.mUID )
  {
    UFG::UIScreenCredits::Flash_SpawnMusicSection(this, section->Body.mData, yPos);
  }
  else
  {
    UFG::UIScreenCredits::Flash_SpawnSection(this, section->Heading.mData, yPos);
    size = section->Names.size;
    if ( size )
    {
      v6 = size;
      v7 = 0i64;
      do
      {
        UFG::UIHKScreenOpeningCredits::Flash_AddName(this, section->Names.p[v7++].mData);
        --v6;
      }
      while ( v6 );
    }
  }
}

// File Line: 300
// RVA: 0x5E5A20
void __fastcall UFG::UIScreenCredits::Flash_Update(UFG::UIScreenCredits *this, float elapsed)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (pargs.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      pargs.mValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = VT_Number;
  pargs.mValue.NValue = elapsed;
  Scaleform::GFx::Movie::Invoke(pObject, "Update", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 312
// RVA: 0x5E50D0
void __fastcall UFG::UIScreenCredits::Flash_SpawnSection(UFG::UIScreenCredits *this, const char *caption, float yPos)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-78h] BYREF
  char v6[16]; // [rsp+70h] [rbp-48h] BYREF
  __int64 v7; // [rsp+80h] [rbp-38h]
  int v8; // [rsp+88h] [rbp-30h]
  double v9; // [rsp+90h] [rbp-28h]

  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = caption;
  if ( (v8 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v7 + 16i64))(v7, v6, COERCE_DOUBLE(*(_QWORD *)&v9));
    v7 = 0i64;
  }
  v8 = 5;
  v9 = yPos;
  Scaleform::GFx::Movie::Invoke(pObject, "SpawnSection", 0i64, &ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 325
// RVA: 0x5E4FA0
void __fastcall UFG::UIScreenCredits::Flash_SpawnMusicSection(UFG::UIScreenCredits *this, const char *body, float yPos)
{
  Scaleform::GFx::Movie *pObject; // rdi
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-78h] BYREF
  char v6[16]; // [rsp+70h] [rbp-48h] BYREF
  __int64 v7; // [rsp+80h] [rbp-38h]
  int v8; // [rsp+88h] [rbp-30h]
  double v9; // [rsp+90h] [rbp-28h]

  pObject = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (ptr.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
      ptr.pObjectInterface,
      &ptr,
      ptr.mValue);
    ptr.pObjectInterface = 0i64;
  }
  ptr.Type = VT_String;
  ptr.mValue.pString = body;
  if ( (v8 & 0x40) != 0 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v7 + 16i64))(v7, v6, COERCE_DOUBLE(*(_QWORD *)&v9));
    v7 = 0i64;
  }
  v8 = 5;
  v9 = yPos;
  Scaleform::GFx::Movie::Invoke(pObject, "SpawnMusicSection", 0i64, &ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 350
// RVA: 0x5DAB60
float __fastcall UFG::UIScreenCredits::Flash_GetScrollPosition(UFG::UIScreenCredits *this)
{
  Scaleform::GFx::Movie *pObject; // rbx
  float NValue; // xmm6_4
  float v3; // xmm7_4
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-90h] BYREF
  Scaleform::GFx::Value v6; // [rsp+68h] [rbp-60h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = VT_Undefined;
  v6.pObjectInterface = 0i64;
  v6.Type = VT_Undefined;
  Scaleform::GFx::Movie::Invoke(pObject, "GetScrollValue", &v6, 0i64, 0);
  NValue = v6.mValue.NValue;
  Scaleform::GFx::Movie::GetVariable(pObject, &pval, "gCurrentSection._y");
  v3 = (float)pval.mValue.NValue + NValue;
  if ( (v6.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&v6.pObjectInterface->vfptr->gap8[8])(
      v6.pObjectInterface,
      &v6,
      v6.mValue);
    v6.pObjectInterface = 0i64;
  }
  v6.Type = VT_Undefined;
  if ( (pval.Type & 0x40) != 0 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      pval.mValue);
    pval.pObjectInterface = 0i64;
  }
  return v3;
}

// File Line: 365
// RVA: 0x5E09D0
void __fastcall UFG::UIScreenCredits::Flash_SetScrollSpeed(UFG::UIScreenCredits *this, float speed)
{
  Scaleform::GFx::Movie *pObject; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-50h] BYREF

  pObject = this->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = VT_Number;
  value.mValue.NValue = speed;
  Scaleform::GFx::Movie::SetVariable(pObject, "gScrollSpeed", &value, 1i64);
  if ( (value.Type & 0x40) != 0 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      value.mValue);
}

