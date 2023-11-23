// File Line: 35
// RVA: 0x1465640
__int64 UFG::_dynamic_initializer_for__gOneShotPool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::gOneShotPool);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gOneShotPool__);
}

// File Line: 37
// RVA: 0x1464F40
__int64 dynamic_initializer_for__UFG::OneShot::smMarkedForClearList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::OneShot::smMarkedForClearList__);
}

// File Line: 43
// RVA: 0x1465120
__int64 dynamic_initializer_for__UFG::Music::sm_controller__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Music::sm_controller__);
}

// File Line: 45
// RVA: 0x14656A0
__int64 UFG::_dynamic_initializer_for__play_mp3__()
{
  play_mp3.mUID = UFG::qWiseSymbolUIDFromString("play_mp3", 0x811C9DC5);
  _((AMD_HD3D *)play_mp3.mUID);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__play_mp3__);
}

// File Line: 46
// RVA: 0x1465240
__int64 dynamic_initializer_for__UFG::Music::sm_mp3Controller__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Music::sm_mp3Controller__);
}

// File Line: 47
// RVA: 0x1465250
__int64 dynamic_initializer_for__UFG::Music::sm_mp3Playlist__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Music::sm_mp3Playlist__);
}

// File Line: 54
// RVA: 0x1465390
__int64 dynamic_initializer_for__UFG::Music::sm_stateRequestQueue__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Music::sm_stateRequestQueue__);
}

// File Line: 77
// RVA: 0x13FDC0
void __fastcall UFG::AmbienceAudio::AmbienceAudio(UFG::AmbienceAudio *this)
{
  UFG::qSymbol *v2; // rax
  _BOOL8 v3; // rdx
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF

  UFG::AudioEntity::AudioEntity(this);
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::AmbienceAudio::`vftable;
  this->m_ambienceController.m_pEvent = 0i64;
  v2 = UFG::qSymbol::create_from_string(&result, "Ambience");
  UFG::AudioEntity::Init(this, v2, &UFG::qMatrix44::msIdentity);
  LOBYTE(v3) = 1;
  this->vfptr->SetShouldFollowListener(this, v3);
}

// File Line: 91
// RVA: 0x14C670
// attributes: thunk
void __fastcall UFG::AmbienceAudio::Shutdown(UFG::HudAudio *this)
{
  UFG::AudioEntity::Shutdown(this);
}

// File Line: 100
// RVA: 0x140710
void __fastcall UFG::HudAudio::HudAudio(UFG::HudAudio *this)
{
  UFG::qSymbol *v2; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF

  UFG::AudioEntity::AudioEntity(this);
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::HudAudio::`vftable;
  v2 = UFG::qSymbol::create_from_string(&result, "HUD");
  UFG::AudioEntity::Init(this, v2, &UFG::qMatrix44::msIdentity);
  UFG::AudioEntity::SetShouldFollowListener(this, 1);
}

// File Line: 122
// RVA: 0x140770
void __fastcall UFG::Music::Music(UFG::Music *this)
{
  UFG::qSymbol *v2; // rax
  UFG::qSymbol result; // [rsp+48h] [rbp+10h] BYREF

  UFG::AudioEntity::AudioEntity(this);
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::Music::`vftable;
  v2 = UFG::qSymbol::create_from_string(&result, "Music");
  UFG::AudioEntity::Init(this, v2, &UFG::qMatrix44::msIdentity);
  UFG::AudioEntity::SetShouldFollowListener(this, 1);
}

// File Line: 138
// RVA: 0x148F30
void __fastcall UFG::Music::MusicCallback(
        UFG::Music *this,
        UFG::eAudioEventCallbackType in_eType,
        UFG::AudioEvent *in_pEvent,
        _DWORD *in_pCallbackInfo)
{
  UFG::qWiseSymbol *v5; // rax
  UFG::qWiseSymbol result; // [rsp+48h] [rbp+10h] BYREF

  if ( in_eType == eAudioEventCallbackType_End )
  {
    if ( in_pCallbackInfo )
    {
      if ( in_pCallbackInfo[8] == 2 )
      {
        v5 = UFG::qSymbol::qSymbol(&result, in_pCallbackInfo[9]);
        UFG::TiDo::UnloadWwiseBank(v5);
        _((AMD_HD3D *)result.mUID);
      }
      (**(void (__fastcall ***)(_DWORD *, __int64, UFG::AudioEvent *))in_pCallbackInfo)(
        in_pCallbackInfo,
        1i64,
        in_pEvent);
    }
  }
  else if ( in_eType == eAudioEventCallbackType_Marker )
  {
    UFG::Music::sm_bRecievedMarker = 1;
    UFG::Music::sm_markerCallbackInfo = in_pEvent->m_markerCallbackInfo;
  }
}

// File Line: 155
// RVA: 0x148FD0
char __fastcall UFG::Music::MusicEvent(unsigned int id)
{
  __int64 v2; // [rsp+40h] [rbp-38h]
  UFG::AudioEventInitParams v3; // [rsp+48h] [rbp-30h] BYREF

  LODWORD(v2) = 0;
  *(_QWORD *)v3.gap8 = 0i64;
  v3.m_EventPlayEndCallback = (void (__fastcall *)(UFG::AudioEntity *, UFG::eAudioEventCallbackType, UFG::AudioEvent *, void *))UFG::Music::MusicCallback;
  v3.m_EventCallbackUserData = 0i64;
  *(_QWORD *)&v3.gap8[8] = v2;
  if ( UFG::Music::sm_instance )
    UFG::AudioEntity::CreateAndPlayEvent(UFG::Music::sm_instance, id, &v3, 0, 0i64);
  return 1;
}

// File Line: 168
// RVA: 0x14BFE0
void __fastcall UFG::Music::SetMusicState(unsigned int stateName, unsigned int stateMode)
{
  if ( AK::SoundEngine::IsInitialized() && stateName && stateMode && !UFG::WwiseInterface::smShuttingDown )
    AK::SoundEngine::SetState(stateName, stateMode);
}

// File Line: 173
// RVA: 0x1430E0
void __fastcall UFG::Music::AudioEntityUpdate(UFG::Music *this, float delta_sec)
{
  __int64 (__fastcall **v3)(); // rax
  char v4; // cl
  UFG::Music *p_mNext; // rbx
  UFG::EventInfo **p_p; // rdi
  int NextMP3Idx; // eax
  int v8; // ecx
  UFG::qList<UFG::qString,UFG::qString,1,0> *mNext; // rbx
  bool v10; // zf
  UFG::qString *Directory; // rax
  unsigned int mUID; // edi
  UFG::Music *v13; // rsi
  char *v14; // rax
  __int64 v15; // rax
  __int64 (__fastcall **v16)(); // [rsp+38h] [rbp-80h] BYREF
  char v17; // [rsp+40h] [rbp-78h]
  UFG::qString v18; // [rsp+48h] [rbp-70h] BYREF
  UFG::qString result; // [rsp+70h] [rbp-48h] BYREF

  if ( UFG::Metrics::msInstance.mSimFrameCount - UFG::Music::sm_lastFrameChange > 40 )
  {
    UFG::Music::sm_bIsObjectActive = 0;
    if ( UFG::Music::sm_bIsObjectActiveDirty
      && UFG::Music::sm_instance->vfptr->CountNumPlayingEvents(UFG::Music::sm_instance)
      && UFG::Music::sm_instance )
    {
      v3 = &`UFG::Music::AudioEntityUpdate::`2::AreEventsPlayingMusic::`vftable;
      v16 = &`UFG::Music::AudioEntityUpdate::`2::AreEventsPlayingMusic::`vftable;
      v4 = 0;
      v17 = 0;
      p_mNext = (UFG::Music *)&UFG::Music::sm_instance->m_events.mNode.mNext[-1].mNext;
      p_p = &UFG::Music::sm_instance->m_eventInfos.p;
      if ( p_mNext != (UFG::Music *)&UFG::Music::sm_instance->m_eventInfos.p )
      {
        while ( 1 )
        {
          ((void (__fastcall *)(__int64 (__fastcall ***)(), UFG::Music *))*v3)(&v16, p_mNext);
          p_mNext = (UFG::Music *)&p_mNext->mNext[-1].mNext;
          if ( p_mNext == (UFG::Music *)p_p )
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
    NextMP3Idx = UFG::Music::GetNextMP3Idx();
    UFG::Music::sm_curPlayingMp3 = NextMP3Idx;
    v8 = NextMP3Idx;
    mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)UFG::Music::sm_mp3Playlist.mNode.mNext;
    v10 = NextMP3Idx == 0;
    if ( NextMP3Idx > 0 )
    {
      do
      {
        if ( mNext == &UFG::Music::sm_mp3Playlist )
          break;
        --v8;
        mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)mNext->mNode.mNext;
      }
      while ( v8 > 0 );
      v10 = NextMP3Idx == 0;
    }
    if ( !v10 )
    {
      Directory = UFG::qGetDirectory(&result);
      UFG::qString::Substring((UFG::qString *)mNext, &v18, Directory->mLength, -1);
      UFG::qString::~qString(&result);
      if ( (unsigned __int8)UFG::WwiseInterface::PrepareMP3(v18.mData) )
      {
        mUID = play_mp3.mUID;
        v13 = UFG::Music::sm_instance;
        if ( UFG::Music::sm_instance->m_bIsInitialized
          && AK::SoundEngine::IsInitialized()
          && mUID
          && UFG::gAudioEventPool.mFreeListHead )
        {
          v14 = UFG::AudioDialogEvent::operator new(0x98ui64);
          if ( v14 )
            UFG::AudioEvent::AudioEvent((UFG::AudioEvent *)v14, mUID, v13, &UFG::Music::sm_mp3Controller, 0i64, 0i64);
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
      UFG::qString::~qString(&v18);
    }
  }
  UFG::AudioEntity::AudioEntityUpdate(this, delta_sec);
}

// File Line: 177
// RVA: 0x144BD0
void __fastcall UFG::Music::AudioEntityUpdate_::_2_::AreEventsPlayingMusic::Do(UFG::AudioEvent *pAe, __int64 a2)
{
  AkSegmentInfo out_segmentInfo; // [rsp+20h] [rbp-28h] BYREF

  LOBYTE(pAe->mPrev) = LOBYTE(pAe->mPrev)
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
  UFG::qList<UFG::qString,UFG::qString,1,0> *mNext; // rax
  int i; // ebx

  if ( !UFG::Music::sm_shuffleMP3s )
    return UFG::Music::sm_curPlayingMp3 + 1;
  mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)UFG::Music::sm_mp3Playlist.mNode.mNext;
  for ( i = 0; mNext != &UFG::Music::sm_mp3Playlist; ++i )
    mNext = (UFG::qList<UFG::qString,UFG::qString,1,0> *)mNext->mNode.mNext;
  for ( result = UFG::qRandom(i, &UFG::qDefaultSeed);
        result == UFG::Music::sm_curPlayingMp3;
        result = UFG::qRandom(i, &UFG::qDefaultSeed) )
  {
    ;
  }
  return result;
}

