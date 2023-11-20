// File Line: 35
// RVA: 0x1465640
__int64 UFG::_dynamic_initializer_for__gOneShotPool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::gOneShotPool);
  return atexit(UFG::_dynamic_atexit_destructor_for__gOneShotPool__);
}

// File Line: 37
// RVA: 0x1464F40
__int64 dynamic_initializer_for__UFG::OneShot::smMarkedForClearList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::OneShot::smMarkedForClearList__);
}

// File Line: 43
// RVA: 0x1465120
__int64 dynamic_initializer_for__UFG::Music::sm_controller__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::Music::sm_controller__);
}

// File Line: 45
// RVA: 0x14656A0
__int64 UFG::_dynamic_initializer_for__play_mp3__()
{
  play_mp3.mUID = UFG::qWiseSymbolUIDFromString("play_mp3", 0x811C9DC5);
  _((AMD_HD3D *)play_mp3.mUID);
  return atexit(UFG::_dynamic_atexit_destructor_for__play_mp3__);
}

// File Line: 46
// RVA: 0x1465240
__int64 dynamic_initializer_for__UFG::Music::sm_mp3Controller__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::Music::sm_mp3Controller__);
}

// File Line: 47
// RVA: 0x1465250
__int64 dynamic_initializer_for__UFG::Music::sm_mp3Playlist__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::Music::sm_mp3Playlist__);
}

// File Line: 54
// RVA: 0x1465390
__int64 dynamic_initializer_for__UFG::Music::sm_stateRequestQueue__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::Music::sm_stateRequestQueue__);
}

// File Line: 77
// RVA: 0x13FDC0
void __fastcall UFG::AmbienceAudio::AmbienceAudio(UFG::AmbienceAudio *this)
{
  UFG::AmbienceAudio *v1; // rbx
  UFG::qSymbol *v2; // rax
  _BOOL8 v3; // rdx
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)&this->vfptr);
  v1->vfptr = (UFG::AudioEntityVtbl *)&UFG::AmbienceAudio::`vftable';
  v1->m_ambienceController.m_pEvent = 0i64;
  v2 = UFG::qSymbol::create_from_string(&result, "Ambience");
  UFG::AudioEntity::Init((UFG::AudioEntity *)&v1->vfptr, v2, &UFG::qMatrix44::msIdentity);
  LOBYTE(v3) = 1;
  v1->vfptr->SetShouldFollowListener((UFG::AudioEntity *)&v1->vfptr, v3);
}

// File Line: 91
// RVA: 0x14C670
void __fastcall UFG::AmbienceAudio::Shutdown(UFG::HudAudio *this)
{
  UFG::AudioEntity::Shutdown((UFG::AudioEntity *)&this->vfptr);
}

// File Line: 100
// RVA: 0x140710
void __fastcall UFG::HudAudio::HudAudio(UFG::HudAudio *this)
{
  UFG::HudAudio *v1; // rbx
  UFG::qSymbol *v2; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)&this->vfptr);
  v1->vfptr = (UFG::AudioEntityVtbl *)&UFG::HudAudio::`vftable';
  v2 = UFG::qSymbol::create_from_string(&result, "HUD");
  UFG::AudioEntity::Init((UFG::AudioEntity *)&v1->vfptr, v2, &UFG::qMatrix44::msIdentity);
  UFG::AudioEntity::SetShouldFollowListener((UFG::AudioEntity *)&v1->vfptr, 1);
}

// File Line: 122
// RVA: 0x140770
void __fastcall UFG::Music::Music(UFG::Music *this)
{
  UFG::Music *v1; // rbx
  UFG::qSymbol *v2; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)&this->vfptr);
  v1->vfptr = (UFG::AudioEntityVtbl *)&UFG::Music::`vftable';
  v2 = UFG::qSymbol::create_from_string(&result, "Music");
  UFG::AudioEntity::Init((UFG::AudioEntity *)&v1->vfptr, v2, &UFG::qMatrix44::msIdentity);
  UFG::AudioEntity::SetShouldFollowListener((UFG::AudioEntity *)&v1->vfptr, 1);
}

// File Line: 138
// RVA: 0x148F30
void __fastcall UFG::Music::MusicCallback(UFG::Music *this, UFG::eAudioEventCallbackType in_eType, UFG::AudioEvent *in_pEvent, void *in_pCallbackInfo)
{
  void (__fastcall ***v4)(void *, signed __int64, UFG::AudioEvent *); // rbx
  UFG::qWiseSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h]

  v4 = (void (__fastcall ***)(void *, signed __int64, UFG::AudioEvent *))in_pCallbackInfo;
  if ( in_eType == 2 )
  {
    if ( in_pCallbackInfo )
    {
      if ( *((_DWORD *)in_pCallbackInfo + 8) == 2 )
      {
        v5 = UFG::qSymbol::qSymbol(&result, *((_DWORD *)in_pCallbackInfo + 9));
        UFG::TiDo::UnloadWwiseBank(v5);
        _((AMD_HD3D *)result.mUID);
      }
      (**v4)(v4, 1i64, in_pEvent);
    }
  }
  else if ( in_eType == 3 )
  {
    UFG::Music::sm_bRecievedMarker = 1;
    UFG::Music::sm_markerCallbackInfo.m_identifier = in_pEvent->m_markerCallbackInfo.m_identifier;
    UFG::Music::sm_markerCallbackInfo.m_position = in_pEvent->m_markerCallbackInfo.m_position;
    UFG::Music::sm_markerCallbackInfo.m_labelHash = in_pEvent->m_markerCallbackInfo.m_labelHash;
    UFG::Music::sm_markerCallbackInfo.m_intParameter = in_pEvent->m_markerCallbackInfo.m_intParameter;
    UFG::Music::sm_markerCallbackInfo.m_floatParameter = in_pEvent->m_markerCallbackInfo.m_floatParameter;
  }
}

// File Line: 155
// RVA: 0x148FD0
char __fastcall UFG::Music::MusicEvent(unsigned int id)
{
  __int64 v2; // [rsp+40h] [rbp-38h]
  void (__fastcall *v3)(UFG::Music *, UFG::eAudioEventCallbackType, UFG::AudioEvent *, void *); // [rsp+48h] [rbp-30h]
  __int64 v4; // [rsp+50h] [rbp-28h]
  __int64 v5; // [rsp+58h] [rbp-20h]
  __int64 v6; // [rsp+60h] [rbp-18h]

  LODWORD(v2) = 0;
  v4 = 0i64;
  v3 = UFG::Music::MusicCallback;
  v6 = 0i64;
  v5 = v2;
  if ( UFG::Music::sm_instance )
    UFG::AudioEntity::CreateAndPlayEvent(
      (UFG::AudioEntity *)&UFG::Music::sm_instance->vfptr,
      id,
      (UFG::AudioEventInitParams *)&v3,
      0,
      0i64);
  return 1;
}

// File Line: 168
// RVA: 0x14BFE0
void __fastcall UFG::Music::SetMusicState(unsigned int stateName, unsigned int stateMode)
{
  unsigned int v2; // ebx
  unsigned int v3; // edi

  v2 = stateMode;
  v3 = stateName;
  if ( (unsigned __int8)AK::SoundEngine::IsInitialized() && v3 && v2 && !UFG::WwiseInterface::smShuttingDown )
    AK::SoundEngine::SetState(v3, v2);
}

// File Line: 173
// RVA: 0x1430E0
void __fastcall UFG::Music::AudioEntityUpdate(UFG::Music *this, float delta_sec)
{
  UFG::Music *v2; // rbp
  __int64 (__fastcall **v3)(); // rax
  char v4; // cl
  UFG::Music *v5; // rbx
  UFG::EventInfo **v6; // rdi
  int v7; // eax
  int v8; // ecx
  UFG::qList<UFG::qString,UFG::qString,1,0> *v9; // rbx
  bool v10; // zf
  UFG::qString *v11; // rax
  unsigned int v12; // edi
  UFG::Music *v13; // rsi
  char *v14; // rax
  __int64 v15; // rax
  __int64 (__fastcall **v16)(); // [rsp+38h] [rbp-80h]
  char v17; // [rsp+40h] [rbp-78h]
  UFG::qString v18; // [rsp+48h] [rbp-70h]
  UFG::qString result; // [rsp+70h] [rbp-48h]

  v2 = this;
  if ( UFG::Metrics::msInstance.mSimFrameCount - UFG::Music::sm_lastFrameChange > 40 )
  {
    UFG::Music::sm_bIsObjectActive = 0;
    if ( UFG::Music::sm_bIsObjectActiveDirty
      && ((unsigned int (*)(void))UFG::Music::sm_instance->vfptr->CountNumPlayingEvents)()
      && UFG::Music::sm_instance )
    {
      v3 = &`UFG::Music::AudioEntityUpdate'::`2'::AreEventsPlayingMusic::`vftable';
      v16 = &`UFG::Music::AudioEntityUpdate'::`2'::AreEventsPlayingMusic::`vftable';
      v4 = 0;
      v17 = 0;
      v5 = (UFG::Music *)&UFG::Music::sm_instance->m_events.mNode.mNext[-1].mNext;
      v6 = &UFG::Music::sm_instance->m_eventInfos.p;
      if ( v5 != (UFG::Music *)&UFG::Music::sm_instance->m_eventInfos.p )
      {
        while ( 1 )
        {
          ((void (__fastcall *)(__int64 (__fastcall ***)(), UFG::Music *))*v3)(&v16, v5);
          v5 = (UFG::Music *)&v5->mNext[-1].mNext;
          if ( v5 == (UFG::Music *)v6 )
            break;
          v3 = v16;
        }
        v4 = v17;
      }
      UFG::Music::sm_bIsObjectActive = v4;
      UFG::Music::sm_bIsObjectActiveDirty = 0;
    }
  }
  if ( UFG::Music::sm_playingUserMP3s && !UFG::Music::sm_mp3Controller.m_pEvent )
  {
    v7 = UFG::Music::GetNextMP3Idx();
    UFG::Music::sm_curPlayingMp3 = v7;
    v8 = v7;
    v9 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)UFG::Music::sm_mp3Playlist.mNode.mNext;
    v10 = v7 == 0;
    if ( v7 > 0 )
    {
      do
      {
        if ( v9 == &UFG::Music::sm_mp3Playlist )
          break;
        --v8;
        v9 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v9->mNode.mNext;
      }
      while ( v8 > 0 );
      v10 = v7 == 0;
    }
    if ( !v10 )
    {
      v11 = UFG::qGetDirectory(&result);
      UFG::qString::Substring((UFG::qString *)v9, &v18, v11->mLength, -1);
      UFG::qString::~qString(&result);
      if ( (unsigned __int8)UFG::WwiseInterface::PrepareMP3(v18.mData) )
      {
        v12 = play_mp3.mUID;
        v13 = UFG::Music::sm_instance;
        if ( UFG::Music::sm_instance->m_bIsInitialized )
        {
          if ( (unsigned __int8)AK::SoundEngine::IsInitialized() && v12 && UFG::gAudioEventPool.mFreeListHead )
          {
            v14 = UFG::AudioDialogEvent::operator new(0x98ui64);
            if ( v14 )
              UFG::AudioEvent::AudioEvent(
                (UFG::AudioEvent *)v14,
                v12,
                (UFG::AudioEntity *)&v13->vfptr,
                &UFG::Music::sm_mp3Controller,
                0i64,
                0i64);
            else
              v15 = 0i64;
            if ( v15
              && UFG::Music::sm_mp3Controller.m_pEvent
              && !UFG::Music::sm_mp3Controller.m_pEvent->vfptr->Play(UFG::Music::sm_mp3Controller.m_pEvent, 0) )
            {
              *((_BYTE *)UFG::Music::sm_mp3Controller.m_pEvent + 144) |= 4u;
              if ( UFG::Music::sm_mp3Controller.m_pEvent )
                UFG::Music::sm_mp3Controller.m_pEvent->m_pController = 0i64;
              UFG::Music::sm_mp3Controller.m_pEvent = 0i64;
            }
          }
        }
      }
      UFG::qString::~qString(&v18);
    }
  }
  UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)&v2->vfptr, delta_sec);
}

// File Line: 177
// RVA: 0x144BD0
void __fastcall UFG::Music::AudioEntityUpdate_::_2_::AreEventsPlayingMusic::Do(UFG::AudioEvent *pAe, __int64 a2)
{
  UFG::AudioEvent *v2; // rbx
  AkSegmentInfo out_segmentInfo; // [rsp+20h] [rbp-28h]

  v2 = pAe;
  LOBYTE(v2->mPrev) = LOBYTE(pAe->mPrev)
                   || (AK::MusicEngine::GetPlayingSegmentInfo(*(_DWORD *)(a2 + 100), &out_segmentInfo, 1),
                       out_segmentInfo.iCurrentPosition)
                   || out_segmentInfo.iPreEntryDuration
                   || out_segmentInfo.iActiveDuration
                   || out_segmentInfo.iPostExitDuration
                   || out_segmentInfo.iRemainingLookAheadTime;
}

// File Line: 254
// RVA: 0x146180
int __fastcall UFG::Music::GetNextMP3Idx()
{
  int result; // eax
  UFG::qList<UFG::qString,UFG::qString,1,0> *v1; // rax
  int i; // ebx

  if ( !UFG::Music::sm_shuffleMP3s )
    return UFG::Music::sm_curPlayingMp3 + 1;
  v1 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)UFG::Music::sm_mp3Playlist.mNode.mNext;
  for ( i = 0; v1 != &UFG::Music::sm_mp3Playlist; ++i )
    v1 = (UFG::qList<UFG::qString,UFG::qString,1,0> *)v1->mNode.mNext;
  for ( result = UFG::qRandom(i, &UFG::qDefaultSeed);
        result == UFG::Music::sm_curPlayingMp3;
        result = UFG::qRandom(i, &UFG::qDefaultSeed) )
  {
    ;
  }
  return result;
}

