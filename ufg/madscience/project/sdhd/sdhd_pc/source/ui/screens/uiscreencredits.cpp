// File Line: 24
// RVA: 0x156E1F0
__int64 anonymous_namespace_::_dynamic_initializer_for__nis_mixer_credits_in__()
{
  UFG::qWiseSymbol::create_from_string(&nis_mixer_credits_in, "nis_mixer_credits_in");
  return atexit(anonymous_namespace_::_dynamic_atexit_destructor_for__nis_mixer_credits_in__);
}

// File Line: 25
// RVA: 0x156E220
__int64 anonymous_namespace_::_dynamic_initializer_for__nis_mixer_credits_out__()
{
  UFG::qWiseSymbol::create_from_string(&nis_mixer_credits_out, "nis_mixer_credits_out");
  return atexit(anonymous_namespace_::_dynamic_atexit_destructor_for__nis_mixer_credits_out__);
}

// File Line: 26
// RVA: 0x156E250
__int64 anonymous_namespace_::_dynamic_initializer_for__nis_mixer_exit_to_game__()
{
  UFG::qWiseSymbol::create_from_string(&nis_mixer_exit_to_game_0, "nis_mixer_exit_to_game");
  return atexit(anonymous_namespace_::_dynamic_atexit_destructor_for__nis_mixer_exit_to_game__);
}

// File Line: 28
// RVA: 0x156E3C0
__int64 anonymous_namespace_::_dynamic_initializer_for__play_credits_end_game_music__()
{
  UFG::qWiseSymbol::create_from_string(&play_credits_end_game_music, "play_credits_end_game_music");
  return atexit(anonymous_namespace_::_dynamic_atexit_destructor_for__play_credits_end_game_music__);
}

// File Line: 29
// RVA: 0x1570960
__int64 anonymous_namespace_::_dynamic_initializer_for__stop_credits_end_game_music__()
{
  UFG::qWiseSymbol::create_from_string(&stop_credits_end_game_music, "stop_credits_end_game_music");
  return atexit(anonymous_namespace_::_dynamic_atexit_destructor_for__stop_credits_end_game_music__);
}

// File Line: 40
// RVA: 0x5F4360
void __fastcall UFG::UICreditsData::Populate(UFG::UICreditsData *this, UFG::qPropertySet *data)
{
  UFG::UICreditsData *v2; // rsi
  UFG::UICreditsSection *v3; // rcx
  UFG::qPropertySet *v4; // rdi
  UFG::qString **v5; // rbx
  unsigned int v6; // ebx
  UFG::qPropertyList *v7; // rax
  UFG::qPropertyList *v8; // r14
  unsigned int v9; // edx
  unsigned int v10; // ebp
  unsigned int v11; // edi
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // ebx
  __int64 v15; // rdi
  char *v16; // rax
  UFG::qPropertySet *v17; // rdx

  v2 = this;
  v3 = this->Sections.p;
  v4 = data;
  if ( v3 )
  {
    v5 = &v3[-1].Names.p;
    `eh vector destructor iterator(
      v3,
      0x68ui64,
      (int)v3[-1].Names.p,
      (void (__fastcall *)(void *))UFG::UICreditsSection::~UICreditsSection);
    operator delete[](v5);
  }
  v6 = 1;
  v2->Sections.p = 0i64;
  *(_QWORD *)&v2->Sections.size = 0i64;
  v7 = UFG::qPropertySet::Get<UFG::qPropertyList>(
         v4,
         (UFG::qSymbol *)&UICreditsSymbol_section_list_0.mUID,
         DEPTH_RECURSE);
  v8 = v7;
  if ( v7 )
  {
    v9 = v2->Sections.size;
    v10 = v7->mNumElements;
    if ( (signed int)(v7->mNumElements - v2->Sections.size) <= 0 )
    {
      v13 = v2->Sections.size - v7->mNumElements;
      if ( v2->Sections.size != v7->mNumElements )
      {
        if ( v13 < v9 )
          v2->Sections.size = v9 - v13;
        else
          v2->Sections.size = 0;
      }
    }
    else
    {
      v11 = v7->mNumElements;
      v12 = v2->Sections.capacity;
      if ( v11 > v12 )
      {
        if ( v12 )
          v6 = 2 * v12;
        for ( ; v6 < v11; v6 *= 2 )
          ;
        if ( v6 - v11 > 0x10000 )
          v6 = v11 + 0x10000;
        UFG::qArray<UFG::UICreditsSection,0>::Reallocate(&v2->Sections, v6, "Sections");
      }
      v2->Sections.size = v11;
    }
    v14 = 0;
    if ( v10 )
    {
      v15 = 0i64;
      do
      {
        v16 = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v14);
        if ( !v16 || (v17 = (UFG::qPropertySet *)&v16[*(_QWORD *)v16], !*(_QWORD *)v16) )
          v17 = 0i64;
        UFG::UICreditsSection::Populate(&v2->Sections.p[v15], v17);
        ++v14;
        ++v15;
      }
      while ( v14 < v10 );
    }
  }
}

// File Line: 73
// RVA: 0x5F44A0
void __fastcall UFG::UICreditsSection::Populate(UFG::UICreditsSection *this, UFG::qPropertySet *data)
{
  UFG::qPropertySet *v2; // rsi
  UFG::UICreditsSection *v3; // r15
  unsigned int v4; // edi
  UFG::qSymbol *v5; // rax
  char *v6; // rax
  char *v7; // rax
  UFG::qString *v8; // rcx
  unsigned int *v9; // rbx
  unsigned int v10; // ebx
  UFG::qPropertyList *v11; // rax
  UFG::qPropertyList *v12; // r13
  unsigned int v13; // ebp
  unsigned int v14; // edx
  unsigned int v15; // eax
  __int64 v16; // rdi
  const char *v17; // rax

  v2 = data;
  v3 = this;
  v4 = 1;
  v5 = UFG::qPropertySet::Get<UFG::qSymbol>(data, (UFG::qSymbol *)&UICreditsSymbol_section_type_0.mUID, DEPTH_RECURSE);
  if ( v5 )
    v3->Type = (UFG::qSymbol)v5->mUID;
  UFG::qString::Set(&v3->Heading, &customWorldMapCaption);
  v6 = UFG::qPropertySet::Get<char const *>(v2, (UFG::qSymbol *)&UICreditsSymbol_heading_0.mUID, DEPTH_RECURSE);
  if ( v6 )
    UFG::qString::Set(&v3->Heading, v6);
  UFG::qString::Set(&v3->Body, &customWorldMapCaption);
  v7 = UFG::qPropertySet::Get<char const *>(v2, (UFG::qSymbol *)&UICreditsSymbol_body_0.mUID, DEPTH_RECURSE);
  if ( v7 )
    UFG::qString::Set(&v3->Body, v7);
  v8 = v3->Names.p;
  if ( v8 )
  {
    v9 = &v8[-1].mStringHash32;
    `eh vector destructor iterator(
      v8,
      0x28ui64,
      v8[-1].mStringHash32,
      (void (__fastcall *)(void *))UFG::qString::~qString);
    operator delete[](v9);
  }
  v10 = 0;
  v3->Names.p = 0i64;
  *(_QWORD *)&v3->Names.size = 0i64;
  v11 = UFG::qPropertySet::Get<UFG::qPropertyList>(
          v2,
          (UFG::qSymbol *)&UICreditsSymbol_names_list_0.mUID,
          DEPTH_RECURSE);
  v12 = v11;
  if ( v11 )
  {
    v13 = v11->mNumElements;
    if ( v13 )
    {
      v14 = v3->Names.size;
      if ( (signed int)(v13 - v14) <= 0 )
      {
        if ( v14 != v13 )
        {
          if ( v14 - v13 < v14 )
            v3->Names.size = v13;
          else
            v3->Names.size = 0;
        }
      }
      else
      {
        v15 = v3->Names.capacity;
        if ( v13 > v15 )
        {
          if ( v15 )
            v4 = 2 * v15;
          for ( ; v4 < v13; v4 *= 2 )
            ;
          if ( v4 - v13 > 0x10000 )
            v4 = v13 + 0x10000;
          UFG::qArray<UFG::qString,0>::Reallocate(&v3->Names, v4, "Names");
        }
        v3->Names.size = v13;
      }
      if ( v13 )
      {
        v16 = 0i64;
        do
        {
          v17 = UFG::qPropertyList::Get<char const *>(v12, v10);
          UFG::qString::Set(&v3->Names.p[v16], v17);
          ++v10;
          ++v16;
        }
        while ( v10 < v13 );
      }
    }
  }
}

// File Line: 128
// RVA: 0x5C8A00
void __fastcall UFG::UIScreenCredits::UIScreenCredits(UFG::UIScreenCredits *this)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v1; // rax
  UFG::UICreditsData *v2; // [rsp+28h] [rbp+10h]

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
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreenCredits::`vftable;
  v2 = &this->mData;
  v2->Sections.p = 0i64;
  *(_QWORD *)&v2->Sections.size = 0i64;
  this->mNextSectionIndex = 0;
}

// File Line: 134
// RVA: 0x5CE210
void __fastcall UFG::UIScreenCredits::~UIScreenCredits(UFG::UIScreenCredits *this)
{
  UFG::UIScreen *v1; // rsi
  UFG::UIScreenTextureManager *v2; // rax
  UFG::UIHKScreenGlobalOverlay *v3; // rax
  UFG::UIHKHelpBarWidget *v4; // rbx
  unsigned int v5; // eax
  unsigned int v6; // ebx
  unsigned int v7; // ecx
  int v8; // ecx
  unsigned int v9; // ebx
  UFG::GameStatTracker *v10; // rax
  UFG::PersistentData::Time *v11; // rax
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> *v12; // rcx
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v13; // rbx

  v1 = (UFG::UIScreen *)&this->vfptr;
  this->vfptr = (UFG::UIScreenVtbl *)&UFG::UIScreenCredits::`vftable;
  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::ReleaseScreen(v2, "Credits");
  v3 = UFG::UIHKScreenGlobalOverlay::mThis;
  if ( !UFG::UIHKScreenGlobalOverlay::mThis )
    v3 = &gGlobalOverlaySentinel;
  v4 = &v3->HelpBar;
  v5 = UFG::qStringHashUpper32("credits", 0xFFFFFFFF);
  UFG::UIHKHelpBarWidget::Hide(v4, v5);
  v6 = nis_mixer_credits_out.mUID;
  v7 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  if ( UFG::UIHK_NISOverlay::m_current_audio_event_index == 7 )
  {
    UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
    v7 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  }
  UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[v7] = v6;
  v8 = v7 + 1;
  UFG::UIHK_NISOverlay::m_current_audio_event_index = v8;
  if ( UFG::UIHK_NISOverlay::m_curtains.m_state != 2 )
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
    if ( UFG::UIHK_NISOverlay::m_curtains.m_state != 2 )
      UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
      stop_credits_end_game_music.mUID,
      0i64,
      0,
      0i64);
    if ( UFG::UIScreenCredits::smPauseMissionScoringTimer )
    {
      v10 = UFG::GameStatTracker::Instance();
      v11 = UFG::GameStatTracker::GetTimeStat(v10, ReservedFCTime1);
      UFG::SimpleTimer::Resume(&v11->mTimer);
    }
  }
  UFG::UIScreenCredits::smTriggeredFromMainMenu = 0;
  UFG::UIScreenCredits::smPauseMissionScoringTimer = 0;
  v12 = v1[1].mPrev;
  if ( v12 )
  {
    v13 = &v12[-1].mNext;
    `eh vector destructor iterator(
      v12,
      0x68ui64,
      (int)v12[-1].mNext,
      (void (__fastcall *)(void *))UFG::UICreditsSection::~UICreditsSection);
    operator delete[](v13);
  }
  v1[1].mPrev = 0i64;
  v1[1].vfptr = 0i64;
  UFG::UIScreen::~UIScreen(v1);
}

// File Line: 157
// RVA: 0x637CB0
void __fastcall UFG::UIScreenCredits::init(UFG::UIScreenCredits *this, UFG::UICommandData *data)
{
  UFG::UIScreenCredits *v2; // rbx
  UFG::qSymbol *v3; // rax
  UFG::qPropertySet *v4; // rax
  unsigned int v5; // ebx
  unsigned int v6; // ecx
  UFG::GameStatTracker *v7; // rax
  UFG::GameStatTracker *v8; // rax
  UFG::PersistentData::Time *v9; // rax
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
  UFG::UIHKHelpBarData dataa; // [rsp+40h] [rbp-258h]
  UFG::qSymbol result; // [rsp+2A0h] [rbp+8h]

  v2 = this;
  UFG::UIScreen::init((UFG::UIScreen *)&this->vfptr, data);
  v3 = UFG::qSymbol::create_from_string(&result, "UI-Credits");
  v4 = UFG::PropertySetManager::GetPropertySet(v3);
  if ( v4 )
    UFG::UICreditsData::Populate(&v2->mData, v4);
  if ( v2->mData.Sections.size )
  {
    UFG::UIScreenCredits::SpawnSection(v2, v2->mData.Sections.p, (float)v2->mRenderable->m_height);
    ++v2->mNextSectionIndex;
  }
  v5 = nis_mixer_credits_in.mUID;
  v6 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  if ( UFG::UIHK_NISOverlay::m_current_audio_event_index == 7 )
  {
    UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
    v6 = UFG::UIHK_NISOverlay::m_current_audio_event_index;
  }
  UFG::UIHK_NISOverlay::m_post_nis_hide_curtain_audio_events[v6] = v5;
  UFG::UIHK_NISOverlay::m_current_audio_event_index = v6 + 1;
  if ( UFG::UIHK_NISOverlay::m_curtains.m_state != 2 )
    UFG::UIHK_NISOverlay::FirePostNISAudioEventQueue();
  if ( !UFG::UIScreenCredits::smTriggeredFromMainMenu )
  {
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
      play_credits_end_game_music.mUID,
      0i64,
      0,
      0i64);
    v7 = UFG::GameStatTracker::Instance();
    UFG::UIScreenCredits::smPauseMissionScoringTimer = UFG::GameStatTracker::GetTimeStat(v7, ReservedFCTime1)->mTimer.mIsStarted;
    if ( UFG::UIScreenCredits::smPauseMissionScoringTimer )
    {
      v8 = UFG::GameStatTracker::Instance();
      v9 = UFG::GameStatTracker::GetTimeStat(v8, ReservedFCTime1);
      UFG::PersistentData::Time::EndTimer(v9);
    }
  }
  UFG::UIHKHelpBarData::UIHKHelpBarData(&dataa);
  dataa.id = UFG::qStringHashUpper32("credits", 0xFFFFFFFF);
  dataa.alignment = 0;
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
  dataa.Buttons[v11] = 2;
  v14 = v11;
  UFG::qString::Set(&dataa.Captions[v11], "$COMMON_BACK_UPPERCASE");
  UFG::qString::Set(&dataa.Icons[v14], &customWorldMapCaption);
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
  dataa.Buttons[v15] = 10;
  v18 = v15;
  UFG::qString::Set(&dataa.Captions[v15], "$COMMON_FAST_FORWARD_UPPERCASE");
  UFG::qString::Set(&dataa.Icons[v18], &customWorldMapCaption);
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
bool __fastcall UFG::UIScreenCredits::handleMessage(UFG::UIScreenCredits *this, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIMessage *v3; // rsi
  unsigned int v4; // ebx
  UFG::UIScreenCredits *v5; // rdi
  float v6; // xmm1_4

  v3 = msg;
  v4 = msgId;
  v5 = this;
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
  UFG::UIScreenManagerBase::queuePopScreen(
    (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
    0xFFFFFFFF);
  if ( UFG::HudAudio::m_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::HudAudio::m_instance->vfptr,
      0xA4E5BFBD,
      0i64,
      0,
      0i64);
LABEL_9:
  UFG::UIScreen::handleMessage((UFG::UIScreen *)&v5->vfptr, v4, v3);
  return 0;
}

// File Line: 214
// RVA: 0x6415C0
void __fastcall UFG::UIScreenCredits::update(UFG::UIScreenCredits *this, float elapsed)
{
  UFG::UIScreenCredits *v2; // rbx
  float v3; // xmm6_4
  float v4; // xmm3_4
  unsigned int v5; // eax
  unsigned int v6; // eax
  UFG::qWiseSymbol result; // [rsp+70h] [rbp+18h]

  v2 = this;
  if ( !UFG::UIScreenManagerBase::getScreen(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "NISPause") )
  {
    UFG::UIScreen::update((UFG::UIScreen *)&v2->vfptr, elapsed);
    UFG::UIScreenCredits::Flash_Update(v2, elapsed);
    v3 = (float)v2->mRenderable->m_height;
    v4 = UFG::UIScreenCredits::Flash_GetScrollPosition(v2);
    if ( v4 < (float)(v3 - 80.0) )
    {
      v5 = v2->mNextSectionIndex;
      if ( v5 >= v2->mData.Sections.size )
      {
        if ( v4 < 0.0 )
          UFG::UIScreenManagerBase::queuePopScreen(
            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
            0xFFFFFFFF);
      }
      else
      {
        UFG::UIScreenCredits::SpawnSection(v2, &v2->mData.Sections.p[v5], v3);
        ++v2->mNextSectionIndex;
      }
    }
    if ( UFG::UIScreenCredits::smTriggeredFromMainMenu )
    {
      if ( _S16_5 & 1 )
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
      if ( !UFG::AudioEntity::IsPlayingId((UFG::AudioEntity *)&UFG::Music::sm_instance->vfptr, v6) )
      {
        UFG::qWiseSymbol::create_from_string(&result, "play_mus_fe_lic");
        UFG::Music::MusicEvent(result.mUID);
        _((AMD_HD3D *)result.mUID);
      }
    }
    else if ( !UFG::AudioEntity::IsPlayingId(
                 (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
                 play_credits_end_game_music.mUID) )
    {
      UFG::AudioEntity::CreateAndPlayEvent(
        (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
        play_credits_end_game_music.mUID,
        0i64,
        0,
        0i64);
    }
  }
}

// File Line: 274
// RVA: 0x611BA0
void __fastcall UFG::UIScreenCredits::SpawnSection(UFG::UIScreenCredits *this, UFG::UICreditsSection *section, float yPos)
{
  UFG::UICreditsSection *v3; // rsi
  UFG::UIScreenCredits *v4; // rbp
  unsigned int v5; // eax
  __int64 v6; // rdi
  __int64 v7; // rbx

  v3 = section;
  v4 = this;
  if ( section->Type.mUID == UICreditsSymbol_music_credit_0.mUID )
  {
    UFG::UIScreenCredits::Flash_SpawnMusicSection(this, section->Body.mData, yPos);
  }
  else
  {
    UFG::UIScreenCredits::Flash_SpawnSection(this, section->Heading.mData, yPos);
    v5 = v3->Names.size;
    if ( v5 )
    {
      v6 = v5;
      v7 = 0i64;
      do
      {
        UFG::UIHKScreenOpeningCredits::Flash_AddName(v4, v3->Names.p[v7].mData);
        ++v7;
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
  Scaleform::GFx::Movie *v2; // rbx
  Scaleform::GFx::Value pargs; // [rsp+38h] [rbp-50h]

  v2 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( ((unsigned int)pargs.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pargs.pObjectInterface->vfptr->gap8[8])(
      pargs.pObjectInterface,
      &pargs,
      *(_QWORD *)&pargs.mValue.NValue);
    pargs.pObjectInterface = 0i64;
  }
  pargs.Type = 5;
  pargs.mValue.NValue = elapsed;
  Scaleform::GFx::Movie::Invoke(v2, "Update", 0i64, &pargs, 1u);
  `eh vector destructor iterator(&pargs, 0x30ui64, 1, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 312
// RVA: 0x5E50D0
void __fastcall UFG::UIScreenCredits::Flash_SpawnSection(UFG::UIScreenCredits *this, const char *caption, float yPos)
{
  const char *v3; // rbx
  Scaleform::GFx::Movie *v4; // rdi
  char ptr; // [rsp+40h] [rbp-78h]
  __int64 v6; // [rsp+50h] [rbp-68h]
  unsigned int v7; // [rsp+58h] [rbp-60h]
  const char *v8; // [rsp+60h] [rbp-58h]
  char v9; // [rsp+70h] [rbp-48h]
  __int64 v10; // [rsp+80h] [rbp-38h]
  unsigned int v11; // [rsp+88h] [rbp-30h]
  double v12; // [rsp+90h] [rbp-28h]

  v3 = caption;
  v4 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v7 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v6 + 16i64))(v6, &ptr, v8);
    v6 = 0i64;
  }
  v7 = 6;
  v8 = v3;
  if ( (v11 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(v10, &v9, COERCE_DOUBLE(*(_QWORD *)&v12));
    v10 = 0i64;
  }
  v11 = 5;
  v12 = yPos;
  Scaleform::GFx::Movie::Invoke(v4, "SpawnSection", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 325
// RVA: 0x5E4FA0
void __fastcall UFG::UIScreenCredits::Flash_SpawnMusicSection(UFG::UIScreenCredits *this, const char *body, float yPos)
{
  const char *v3; // rbx
  Scaleform::GFx::Movie *v4; // rdi
  char ptr; // [rsp+40h] [rbp-78h]
  __int64 v6; // [rsp+50h] [rbp-68h]
  unsigned int v7; // [rsp+58h] [rbp-60h]
  const char *v8; // [rsp+60h] [rbp-58h]
  char v9; // [rsp+70h] [rbp-48h]
  __int64 v10; // [rsp+80h] [rbp-38h]
  unsigned int v11; // [rsp+88h] [rbp-30h]
  double v12; // [rsp+90h] [rbp-28h]

  v3 = body;
  v4 = this->mRenderable->m_movie.pObject;
  `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
  if ( (v7 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, const char *))(*(_QWORD *)v6 + 16i64))(v6, &ptr, v8);
    v6 = 0i64;
  }
  v7 = 6;
  v8 = v3;
  if ( (v11 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v10 + 16i64))(v10, &v9, COERCE_DOUBLE(*(_QWORD *)&v12));
    v10 = 0i64;
  }
  v11 = 5;
  v12 = yPos;
  Scaleform::GFx::Movie::Invoke(v4, "SpawnMusicSection", 0i64, (Scaleform::GFx::Value *)&ptr, 2u);
  `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
}

// File Line: 350
// RVA: 0x5DAB60
float __fastcall UFG::UIScreenCredits::Flash_GetScrollPosition(UFG::UIScreenCredits *this)
{
  Scaleform::GFx::Movie *v1; // rbx
  float v2; // xmm6_4
  float v3; // xmm7_4
  Scaleform::GFx::Value pval; // [rsp+38h] [rbp-90h]
  char v6; // [rsp+68h] [rbp-60h]
  __int64 v7; // [rsp+78h] [rbp-50h]
  unsigned int v8; // [rsp+80h] [rbp-48h]
  double v9; // [rsp+88h] [rbp-40h]

  v1 = this->mRenderable->m_movie.pObject;
  pval.pObjectInterface = 0i64;
  pval.Type = 0;
  v7 = 0i64;
  v8 = 0;
  Scaleform::GFx::Movie::Invoke(v1, "GetScrollValue", (Scaleform::GFx::Value *)&v6, 0i64, 0);
  v2 = v9;
  Scaleform::GFx::Movie::GetVariable(v1, &pval, "gCurrentSection._y");
  v3 = (float)pval.mValue.NValue + v2;
  if ( (v8 >> 6) & 1 )
  {
    (*(void (__fastcall **)(__int64, char *, double))(*(_QWORD *)v7 + 16i64))(v7, &v6, COERCE_DOUBLE(*(_QWORD *)&v9));
    v7 = 0i64;
  }
  v8 = 0;
  if ( ((unsigned int)pval.Type >> 6) & 1 )
  {
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&pval.pObjectInterface->vfptr->gap8[8])(
      pval.pObjectInterface,
      &pval,
      *(_QWORD *)&pval.mValue.NValue);
    pval.pObjectInterface = 0i64;
  }
  return v3;
}

// File Line: 365
// RVA: 0x5E09D0
void __fastcall UFG::UIScreenCredits::Flash_SetScrollSpeed(UFG::UIScreenCredits *this, float speed)
{
  Scaleform::GFx::Movie *v2; // rbx
  Scaleform::GFx::Value value; // [rsp+28h] [rbp-50h]

  v2 = this->mRenderable->m_movie.pObject;
  value.pObjectInterface = 0i64;
  value.Type = 5;
  value.mValue.NValue = speed;
  Scaleform::GFx::Movie::SetVariable(v2, "gScrollSpeed", &value, 1i64);
  if ( ((unsigned int)value.Type >> 6) & 1 )
    (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, _QWORD))&value.pObjectInterface->vfptr->gap8[8])(
      value.pObjectInterface,
      &value,
      *(_QWORD *)&value.mValue.NValue);
}

