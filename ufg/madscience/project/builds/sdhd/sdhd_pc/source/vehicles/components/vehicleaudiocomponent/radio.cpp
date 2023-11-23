// File Line: 27
// RVA: 0x1583210
__int64 dynamic_initializer_for__ms_player_radio__()
{
  ms_player_radio.mUID = UFG::qWiseSymbolUIDFromString("ms_player_radio", 0x811C9DC5);
  _((AMD_HD3D *)ms_player_radio.mUID);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__ms_player_radio__);
}

// File Line: 28
// RVA: 0x1585390
__int64 dynamic_initializer_for__radio_on__()
{
  radio_on.mUID = UFG::qWiseSymbolUIDFromString("radio_on", 0x811C9DC5);
  _((AMD_HD3D *)radio_on.mUID);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__radio_on__);
}

// File Line: 29
// RVA: 0x1585340
__int64 dynamic_initializer_for__radio_off__()
{
  radio_off.mUID = UFG::qWiseSymbolUIDFromString("radio_off", 0x811C9DC5);
  _((AMD_HD3D *)radio_off.mUID);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__radio_off__);
}

// File Line: 36
// RVA: 0x157B960
__int64 dynamic_initializer_for__UFG::Radio::sm_stationList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Radio::sm_stationList__);
}

// File Line: 46
// RVA: 0x667CF0
void __fastcall UFG::DJAsset::DJAsset(
        UFG::DJAsset *this,
        UFG::RadioStation *station,
        unsigned __int8 index,
        UFG::qString *trackNames,
        unsigned int numTracks)
{
  unsigned int v6; // ebx
  unsigned int v9; // r15d
  UFG::TrackAsset **m_trackAssets; // rdi
  unsigned int *p_mStringHash32; // rbx
  __int64 v12; // rbp
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **p_mNext; // rax
  UFG::qString v14; // [rsp+28h] [rbp-A0h] BYREF
  UFG::qString v15; // [rsp+50h] [rbp-78h] BYREF
  UFG::qString v16; // [rsp+78h] [rbp-50h] BYREF

  v6 = index;
  this->mPrev = &this->UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset>;
  this->mNext = &this->UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset>;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::RadioStationAsset::`vftable;
  this->m_index = index;
  *(_QWORD *)&this->m_type = 1i64;
  *((_BYTE *)&this->UFG::RadioStationAsset + 36) |= 1u;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::DJAsset::`vftable;
  UFG::qString::qString(&v16);
  v9 = v6;
  UFG::qString::Format(&v16, "play_station_%02u_dj_%01ua", station->m_id, v6);
  this->m_beforeTracksEvent = UFG::TiDo::CalcWwiseUid(v16.mData);
  UFG::qString::qString(&v15);
  UFG::qString::Format(&v15, "play_station_%02u_dj_%0ub", station->m_id, v6);
  this->m_afterTracksEvent = UFG::TiDo::CalcWwiseUid(v15.mData);
  m_trackAssets = this->m_trackAssets;
  this->m_trackAssets[0] = 0i64;
  this->m_trackAssets[1] = 0i64;
  this->m_trackAssets[2] = 0i64;
  if ( numTracks )
  {
    p_mStringHash32 = &trackNames->mStringHash32;
    v12 = numTracks;
    do
    {
      if ( *p_mStringHash32 == -1 )
        *p_mStringHash32 = UFG::qStringHash32(*((const char **)p_mStringHash32 - 1), 0xFFFFFFFF);
      p_mNext = &station->m_assets.mNode.mNext[-1].mNext;
      if ( station->m_assets.mNode.mNext != (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)8 )
      {
        while ( p_mNext != (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **)&station->m_programs.mNode.mNext )
        {
          if ( !*((_DWORD *)p_mNext + 7) && *p_mStringHash32 == *((_DWORD *)p_mNext + 10) )
            goto LABEL_11;
          p_mNext = &p_mNext[2][-1].mNext;
          if ( !p_mNext )
            break;
        }
      }
      UFG::qString::operator!=((UFG::qString *)(p_mStringHash32 - 8), &customCaption);
      p_mNext = 0i64;
LABEL_11:
      *m_trackAssets++ = (UFG::TrackAsset *)p_mNext;
      p_mStringHash32 += 10;
      --v12;
    }
    while ( v12 );
  }
  UFG::qString::qString(&v14);
  UFG::qString::Format(&v14, "play_station_%02u_dj_%02u", station->m_id, v9);
  this->m_assetId = UFG::TiDo::CalcWwiseUid(v14.mData);
  UFG::qString::~qString(&v14);
  UFG::qString::~qString(&v15);
  UFG::qString::~qString(&v16);
}

// File Line: 80
// RVA: 0x66A6B0
void __fastcall UFG::TrackAsset::TrackAsset(
        UFG::TrackAsset *this,
        UFG::RadioStation *station,
        unsigned __int8 index,
        char *artistName,
        char *trackName)
{
  unsigned int v6; // edi
  int v9; // eax
  char *v10; // rax
  int v11; // eax
  char *v12; // rax
  UFG::qString v13; // [rsp+28h] [rbp-30h] BYREF

  v6 = index;
  this->mPrev = &this->UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset>;
  this->mNext = &this->UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset>;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::RadioStationAsset::`vftable;
  this->m_index = index;
  *(_QWORD *)&this->m_type = 0i64;
  *((_BYTE *)&this->UFG::RadioStationAsset + 36) |= 1u;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::TrackAsset::`vftable;
  this->m_trackUID = -1;
  this->m_trackName = 0i64;
  this->m_artistName = 0i64;
  UFG::qString::qString(&v13);
  UFG::qString::Format(&v13, "play_station_%02u_track_%02u", station->m_id, v6);
  this->m_assetId = UFG::TiDo::CalcWwiseUid(v13.mData);
  if ( artistName && *artistName )
  {
    v9 = UFG::qStringLength(artistName);
    v10 = (char *)UFG::qMalloc(v9 + 1, "RadioStation", 0i64);
    this->m_artistName = v10;
    UFG::qStringCopy(v10, 0x7FFFFFFF, artistName, -1);
  }
  if ( trackName && *trackName )
  {
    v11 = UFG::qStringLength(trackName);
    v12 = (char *)UFG::qMalloc(v11 + 1, "RadioStation", 0i64);
    this->m_trackName = v12;
    UFG::qStringCopy(v12, 0x7FFFFFFF, trackName, -1);
    this->m_trackUID = UFG::qStringHash32(trackName, 0xFFFFFFFF);
  }
  UFG::qString::~qString(&v13);
}

// File Line: 105
// RVA: 0x666CE0
void __fastcall UFG::AdAsset::AdAsset(UFG::AdAsset *this, UFG::RadioStation *station, unsigned __int8 index)
{
  unsigned int v3; // edi
  UFG::qString v6; // [rsp+28h] [rbp-30h] BYREF

  v3 = index;
  this->mPrev = &this->UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset>;
  this->mNext = &this->UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset>;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::RadioStationAsset::`vftable;
  this->m_index = index;
  *(_QWORD *)&this->m_type = 2i64;
  *((_BYTE *)&this->UFG::RadioStationAsset + 36) |= 1u;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::AdAsset::`vftable;
  UFG::qString::qString(&v6);
  UFG::qString::Format(&v6, "play_station_%02u_ad_%02u", station->m_id, v3);
  this->m_assetId = UFG::TiDo::CalcWwiseUid(v6.mData);
  UFG::qString::~qString(&v6);
}

// File Line: 116
// RVA: 0x6699A0
void __fastcall UFG::IdentAsset::IdentAsset(UFG::IdentAsset *this, UFG::RadioStation *station)
{
  UFG::qString v4; // [rsp+28h] [rbp-30h] BYREF

  this->mPrev = &this->UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset>;
  this->mNext = &this->UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset>;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::RadioStationAsset::`vftable;
  this->m_index = 0;
  *(_QWORD *)&this->m_type = 3i64;
  *((_BYTE *)&this->UFG::RadioStationAsset + 36) |= 1u;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::IdentAsset::`vftable;
  UFG::qString::qString(&v4);
  UFG::qString::Format(&v4, "play_station_%02u_ident", station->m_id);
  this->m_assetId = UFG::TiDo::CalcWwiseUid(v4.mData);
  UFG::qString::~qString(&v4);
}

// File Line: 132
// RVA: 0x669F60
void __fastcall UFG::RadioStation::RadioStation(
        UFG::RadioStation *this,
        const char *name,
        unsigned int id,
        unsigned int consecTracks,
        float chanceTrack,
        float chanceDj,
        float chanceAd,
        bool copScannerStation)
{
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *p_m_playList; // r14
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *p_m_prevPlayed; // r15
  UFG::RadioStation *i; // rax
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v15; // rdx
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *mPrev; // rcx
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *mNext; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *j; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v19; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v20; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *k; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v22; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v23; // rax
  UFG::qWiseSymbol *v24; // rax
  unsigned int *m_firstAssetIndex; // rax
  __int64 v26; // rdx
  UFG::qString result; // [rsp+30h] [rbp-58h] BYREF

  this->mPrev = &this->UFG::qNode<UFG::RadioStation,UFG::RadioStation>;
  this->mNext = &this->UFG::qNode<UFG::RadioStation,UFG::RadioStation>;
  this->vfptr = (UFG::RadioStationVtbl *)&UFG::RadioStation::`vftable;
  UFG::qString::qString(&this->m_textureName);
  UFG::qString::qString(&this->m_texturePack);
  UFG::qString::qString(&this->m_currentlyPlayingAssetName);
  this->m_bankId.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  this->m_programs.mNode.mPrev = &this->m_programs.mNode;
  this->m_programs.mNode.mNext = &this->m_programs.mNode;
  this->m_assets.mNode.mPrev = &this->m_assets.mNode;
  this->m_assets.mNode.mNext = &this->m_assets.mNode;
  p_m_playList = &this->m_playList;
  this->m_playList.mNode.mPrev = &this->m_playList.mNode;
  this->m_playList.mNode.mNext = &this->m_playList.mNode;
  p_m_prevPlayed = &this->m_prevPlayed;
  this->m_prevPlayed.mNode.mPrev = &this->m_prevPlayed.mNode;
  this->m_prevPlayed.mNode.mNext = &this->m_prevPlayed.mNode;
  UFG::qSPrintf(this->m_name, "%s", name);
  this->m_id = id;
  this->m_numConsecutiveTracks = consecTracks;
  this->m_percentTrack = chanceTrack;
  this->m_percentDj = chanceDj;
  this->m_percentAd = chanceAd;
  UFG::qString::Set(&this->m_currentlyPlayingAssetName, &customCaption);
  this->m_currentlyPlaying = 0i64;
  this->m_numRecentlyPlayed = 0;
  for ( i = (UFG::RadioStation *)&this->m_assets.mNode.mNext[-1].mNext;
        i != (UFG::RadioStation *)&this->m_programs.mNode.mNext;
        i = (UFG::RadioStation *)&this->m_assets.mNode.mNext[-1].mNext )
  {
    v15 = &i->UFG::qNode<UFG::RadioStation,UFG::RadioStation>;
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v15->mPrev = v15;
    v15->mNext = v15;
  }
  for ( j = this->m_playList.mNode.mNext;
        j != (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)p_m_playList;
        j = this->m_playList.mNode.mNext )
  {
    v19 = j->mPrev;
    v20 = j->mNext;
    v19->mNext = v20;
    v20->mPrev = v19;
    j->mPrev = j;
    j->mNext = j;
  }
  for ( k = this->m_prevPlayed.mNode.mNext;
        k != (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)p_m_prevPlayed;
        k = this->m_prevPlayed.mNode.mNext )
  {
    v22 = k->mPrev;
    v23 = k->mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    k->mPrev = k;
    k->mNext = k;
  }
  *(_QWORD *)&this->m_timeSinceStarted = 0i64;
  this->m_currentTrackTimer = 0.0;
  UFG::qString::FormatEx(&result, "mus_radio_station_%d", this->m_id);
  v24 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&chanceTrack, result.mData);
  UFG::qWiseSymbol::operator=(&this->m_bankId, v24);
  _((AMD_HD3D *)LODWORD(chanceTrack));
  this->m_bIsRaceStation = 0;
  this->m_bIsCopScannerStation = copScannerStation;
  m_firstAssetIndex = this->m_firstAssetIndex;
  v26 = 4i64;
  do
  {
    *(m_firstAssetIndex - 4) = 0;
    *m_firstAssetIndex++ = 0;
    --v26;
  }
  while ( v26 );
  UFG::qString::Set(&this->m_currentlyPlayingAssetName, " ");
  UFG::qString::~qString(&result);
}

// File Line: 170
// RVA: 0x66CD60
void __fastcall UFG::RadioStation::~RadioStation(UFG::RadioStation *this)
{
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *p_m_playList; // r15
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *p_m_prevPlayed; // r14
  UFG::qList<UFG::RadioStationAsset,UFG::RadioStationAsset,1,0> *p_m_assets; // rdi
  UFG::RadioStation *i; // rax
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v6; // rdx
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *mPrev; // rcx
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *mNext; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v9; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v10; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v11; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v12; // rax
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v13; // rcx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v14; // rax
  UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> *v15; // rcx
  UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> *v16; // rax
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v17; // rcx
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v18; // rax

  this->vfptr = (UFG::RadioStationVtbl *)&UFG::RadioStation::`vftable;
  p_m_playList = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_playList;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_playList);
  p_m_prevPlayed = &this->m_prevPlayed;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_prevPlayed);
  p_m_assets = &this->m_assets;
  for ( i = (UFG::RadioStation *)&this->m_assets.mNode.mNext[-1].mNext;
        i != (UFG::RadioStation *)&this->m_programs.mNode.mNext;
        i = (UFG::RadioStation *)&this->m_assets.mNode.mNext[-1].mNext )
  {
    v6 = &i->UFG::qNode<UFG::RadioStation,UFG::RadioStation>;
    mPrev = i->mPrev;
    mNext = i->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v6->mPrev = v6;
    v6->mNext = v6;
    if ( v6 != (UFG::qNode<UFG::RadioStation,UFG::RadioStation> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::RadioStation,UFG::RadioStation> **, __int64))v6[-1].mNext->mPrev)(
        &v6[-1].mNext,
        1i64);
  }
  UFG::qList<UFG::RadioStationProgram,UFG::RadioStationProgram,1,0>::DeleteNodes(&this->m_programs);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_prevPlayed);
  v9 = p_m_prevPlayed->mNode.mPrev;
  v10 = this->m_prevPlayed.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_m_prevPlayed->mNode.mPrev = &p_m_prevPlayed->mNode;
  this->m_prevPlayed.mNode.mNext = &this->m_prevPlayed.mNode;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes(p_m_playList);
  v11 = p_m_playList->mNode.mPrev;
  v12 = p_m_playList->mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  p_m_playList->mNode.mPrev = &p_m_playList->mNode;
  p_m_playList->mNode.mNext = &p_m_playList->mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_assets);
  v13 = p_m_assets->mNode.mPrev;
  v14 = this->m_assets.mNode.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_m_assets->mNode.mPrev = &p_m_assets->mNode;
  this->m_assets.mNode.mNext = &this->m_assets.mNode;
  UFG::qList<UFG::RadioStationProgram,UFG::RadioStationProgram,1,0>::DeleteNodes(&this->m_programs);
  v15 = this->m_programs.mNode.mPrev;
  v16 = this->m_programs.mNode.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  this->m_programs.mNode.mPrev = &this->m_programs.mNode;
  this->m_programs.mNode.mNext = &this->m_programs.mNode;
  _((AMD_HD3D *)this->m_bankId.mUID);
  UFG::qString::~qString(&this->m_currentlyPlayingAssetName);
  UFG::qString::~qString(&this->m_texturePack);
  UFG::qString::~qString(&this->m_textureName);
  v17 = this->mPrev;
  v18 = this->mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->mPrev = &this->UFG::qNode<UFG::RadioStation,UFG::RadioStation>;
  this->mNext = &this->UFG::qNode<UFG::RadioStation,UFG::RadioStation>;
}

// File Line: 183
// RVA: 0x67F250
bool __fastcall UFG::RadioStation::IsInCurrentProgram(UFG::RadioStation *this, char index)
{
  UFG::TimeOfDayManager *Instance; // rax
  int v5; // r8d
  float m_SecondsSinceMidnight; // xmm0_4
  UFG::RadioStation *mNext; // rax
  float v8; // xmm0_4
  UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> *v9; // rcx
  float v10; // xmm2_4
  float v11; // xmm1_4

  Instance = UFG::TimeOfDayManager::GetInstance();
  v5 = 0;
  m_SecondsSinceMidnight = Instance->m_SecondsSinceMidnight;
  mNext = (UFG::RadioStation *)this->m_programs.mNode.mNext;
  v8 = m_SecondsSinceMidnight * 0.00027777778;
  if ( mNext == (UFG::RadioStation *)&this->m_programs )
    return 1;
  do
  {
    mNext = (UFG::RadioStation *)mNext->mPrev;
    ++v5;
  }
  while ( mNext != (UFG::RadioStation *)&this->m_programs );
  if ( !v5 )
    return 1;
  v9 = this->m_programs.mNode.mNext;
  if ( !v9 )
    return 0;
  while ( 1 )
  {
    v10 = (float)BYTE3(v9[1].mPrev);
    v11 = (float)BYTE2(v9[1].mPrev);
    if ( v10 <= v11 )
      break;
    if ( v8 >= v11 && v8 <= v10 )
      return index >= (int)LOBYTE(v9[1].mPrev) && index <= (int)BYTE1(v9[1].mPrev);
LABEL_14:
    v9 = v9->mNext;
    if ( !v9 )
      return 0;
  }
  if ( v8 <= v11 && v8 > v10 && v8 < v11 )
    goto LABEL_14;
  return index >= (int)LOBYTE(v9[1].mPrev) && index <= (int)BYTE1(v9[1].mPrev);
}

// File Line: 233
// RVA: 0x67AA80
__int64 __fastcall UFG::RadioStation::GetNextTrack(UFG::RadioStation *this)
{
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *p_m_playList; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *mNext; // rbx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *mPrev; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v5; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v6; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v7; // rax
  __int64 v8; // r13
  float v9; // xmm0_4
  int v10; // edx
  UFG::DJAsset *p_mNext; // rbx
  __int64 v12; // rax
  UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **i; // r14
  int j; // eax
  int k; // r12d
  int v16; // ecx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **m; // rax
  unsigned int v18; // r15d
  UFG::RadioStation *v19; // rdi
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v20; // rcx
  UFG::RadioStationAsset *v21; // rdx
  UFG::RadioStation *v22; // rcx
  int v23; // esi
  UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **v24; // rdi
  int v25; // ecx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **n; // rax
  int ii; // edx
  int v28; // ecx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **jj; // rax

  p_m_playList = &this->m_playList;
  while ( 2 )
  {
    if ( (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)p_m_playList->mNode.mNext != p_m_playList )
    {
      mNext = this->m_playList.mNode.mNext;
      mPrev = mNext->mPrev;
      v5 = mNext->mNext;
      mPrev->mNext = v5;
      v5->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      UFG::RadioStation::SetCurrentlyPlaying(this, (UFG::RadioStationAsset *)mNext[1].mPrev);
      v6 = mNext->mPrev;
      v7 = mNext->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      operator delete[](mNext);
      if ( this->m_currentlyPlaying )
        return ((__int64 (__fastcall *)(UFG::RadioStationAsset *))this->m_currentlyPlaying->vfptr->GetActiveAssetId)(this->m_currentlyPlaying);
    }
    v8 = (int)UFG::RadioStation::DetermineAssetType(this);
    v9 = UFG::qRandom((float)(int)this->m_assetCount[v8], (unsigned int *)&UFG::qDefaultSeed)
       + (float)(int)this->m_firstAssetIndex[v8];
    v10 = 0;
    p_mNext = (UFG::DJAsset *)&this->m_assets.mNode.mNext[-1].mNext;
    v12 = (__int64)p_mNext;
    for ( i = &this->m_programs.mNode.mNext;
          (UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **)v12 != i;
          v12 = *(_QWORD *)(v12 + 16) - 8i64 )
    {
      ++v10;
    }
    if ( v9 <= 0.0 )
      v9 = 0.0;
    if ( v9 >= (float)(v10 - 1) )
      v9 = (float)(v10 - 1);
    for ( j = (int)v9; j > 0; p_mNext = (UFG::DJAsset *)&p_mNext->mNext[-1].mNext )
    {
      if ( p_mNext == (UFG::DJAsset *)i )
        break;
      --j;
    }
    for ( k = 0; ; ++k )
    {
      v16 = 0;
      for ( m = &this->m_assets.mNode.mNext[-1].mNext;
            m != (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **)i;
            m = &m[2][-1].mNext )
      {
        ++v16;
      }
      if ( k >= v16 )
      {
        v23 = 0;
        v24 = &this->m_programs.mNode.mNext;
        while ( 1 )
        {
          v25 = 0;
          for ( n = &this->m_assets.mNode.mNext[-1].mNext;
                n != (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **)v24;
                n = &n[2][-1].mNext )
          {
            ++v25;
          }
          if ( v23 >= v25 )
            break;
          if ( p_mNext->m_type == (_DWORD)v8
            && UFG::RadioStation::IsInCurrentProgram(this, (unsigned __int8)p_mNext->m_index) )
          {
            goto LABEL_45;
          }
          p_mNext = (UFG::DJAsset *)&p_mNext->mNext[-1].mNext;
          if ( p_mNext == (UFG::DJAsset *)&this->m_programs.mNode.mNext )
            p_mNext = (UFG::DJAsset *)&p_mNext->mNext[-1].mNext;
          ++v23;
        }
        for ( ii = 0; ; ++ii )
        {
          v28 = 0;
          for ( jj = &this->m_assets.mNode.mNext[-1].mNext;
                jj != (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **)v24;
                jj = &jj[2][-1].mNext )
          {
            ++v28;
          }
          if ( ii >= v28 || p_mNext->m_type == (_DWORD)v8 )
            break;
          p_mNext = (UFG::DJAsset *)&p_mNext->mNext[-1].mNext;
          if ( p_mNext == (UFG::DJAsset *)&this->m_programs.mNode.mNext )
            p_mNext = (UFG::DJAsset *)&p_mNext->mNext[-1].mNext;
        }
LABEL_45:
        v21 = p_mNext;
        v22 = this;
        goto LABEL_46;
      }
      v18 = p_mNext->vfptr->GetActiveAssetId(p_mNext);
      v19 = (UFG::RadioStation *)this->m_prevPlayed.mNode.mNext;
      if ( v19 == (UFG::RadioStation *)&this->m_prevPlayed )
        break;
      while ( 1 )
      {
        v20 = v19->mNext;
        if ( v20 )
        {
          if ( ((unsigned int (__fastcall *)(UFG::qNode<UFG::RadioStation,UFG::RadioStation> *))v20->mPrev->mNext)(v20) == v18 )
            break;
        }
        v19 = (UFG::RadioStation *)v19->mPrev;
        if ( v19 == (UFG::RadioStation *)&this->m_prevPlayed )
          goto LABEL_21;
      }
LABEL_23:
      p_mNext = (UFG::DJAsset *)&p_mNext->mNext[-1].mNext;
      if ( p_mNext == (UFG::DJAsset *)&this->m_programs.mNode.mNext )
        p_mNext = (UFG::DJAsset *)&p_mNext->mNext[-1].mNext;
    }
LABEL_21:
    if ( p_mNext->m_type != (_DWORD)v8
      || !UFG::RadioStation::IsInCurrentProgram(this, (unsigned __int8)p_mNext->m_index) )
    {
      goto LABEL_23;
    }
    v21 = p_mNext;
    v22 = this;
    if ( (_DWORD)v8 == 1 )
    {
      UFG::RadioStation::AddDjAssetToPlaylist(this, p_mNext);
      p_m_playList = &this->m_playList;
      continue;
    }
    break;
  }
LABEL_46:
  UFG::RadioStation::SetCurrentlyPlaying(v22, v21);
  return ((__int64 (__fastcall *)(UFG::RadioStationAsset *))this->m_currentlyPlaying->vfptr->GetActiveAssetId)(this->m_currentlyPlaying);
}

// File Line: 315
// RVA: 0x6767C0
signed __int64 __fastcall UFG::RadioStation::DetermineAssetType(UFG::RadioStation *this)
{
  int v3; // ebx
  float m_percentAd; // xmm7_4
  UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **p_mNext; // r9
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **v6; // rax
  int v7; // r8d
  int v8; // edx
  int v9; // ecx
  float m_percentTrack; // xmm6_4
  float v11; // xmm0_4
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *p_m_prevPlayed; // rdx
  int v13; // ecx
  UFG::RadioStation *mNext; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v15; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *mPrev; // rdi
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v17; // rcx

  if ( !this->m_numRecentlyPlayed )
    return 0i64;
  v3 = 0;
  m_percentAd = 0.0;
  p_mNext = &this->m_programs.mNode.mNext;
  v6 = &this->m_assets.mNode.mNext[-1].mNext;
  v7 = 0;
  v8 = 0;
  if ( v6 == (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **)&this->m_programs.mNode.mNext )
    goto LABEL_12;
  do
  {
    v9 = *((_DWORD *)v6 + 7);
    if ( v9 != 1 )
    {
      if ( v9 == 2 )
      {
        ++v7;
      }
      else if ( !v9 )
      {
        ++v8;
      }
    }
    v6 = &v6[2][-1].mNext;
  }
  while ( v6 != (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **)p_mNext );
  if ( !v8 )
LABEL_12:
    m_percentTrack = 0.0;
  else
    m_percentTrack = this->m_percentTrack;
  if ( v7 )
    m_percentAd = this->m_percentAd;
  v11 = UFG::qRandom(100.0, (unsigned int *)&UFG::qDefaultSeed);
  if ( v11 <= m_percentTrack )
    return 0i64;
  if ( v11 >= (float)(m_percentAd + m_percentTrack) )
    return 1i64;
  p_m_prevPlayed = &this->m_prevPlayed;
  v13 = 0;
  mNext = (UFG::RadioStation *)this->m_prevPlayed.mNode.mNext;
  if ( mNext == (UFG::RadioStation *)&this->m_prevPlayed )
    return 3i64;
  do
  {
    mNext = (UFG::RadioStation *)mNext->mPrev;
    ++v13;
  }
  while ( mNext != (UFG::RadioStation *)p_m_prevPlayed );
  if ( v13 <= 0 )
    return 3i64;
  v15 = this->m_prevPlayed.mNode.mNext;
  mPrev = v15[1].mPrev;
  if ( !mPrev )
    return 2i64;
  for ( ;
        v15 != (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)p_m_prevPlayed;
        v15 = v15->mNext )
  {
    v17 = v15[1].mPrev;
    if ( !v17 || HIDWORD(v17[1].mNext) != 2 )
      break;
    if ( (unsigned int)++v3 >= 2 )
      return 0i64;
  }
  if ( UFG::qRandom(100.0, (unsigned int *)&UFG::qDefaultSeed) >= 50.0 && HIDWORD(mPrev[1].mNext) != 3 )
    return 3i64;
  else
    return 2i64;
}

// File Line: 415
// RVA: 0x66F7F0
void __fastcall UFG::RadioStation::AddDjAssetToPlaylist(UFG::RadioStation *this, UFG::DJAsset *djAsset)
{
  char v4; // r13
  unsigned int v5; // eax
  UFG::TrackAsset **m_trackAssets; // r14
  __int64 v7; // r15
  unsigned int v8; // ebp
  UFG::RadioStation *i; // rbx
  UFG::allocator::free_link *v10; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v11; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *mPrev; // rax
  unsigned int v13; // eax

  v4 = 1;
  if ( UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed) >= 0.5 )
  {
    djAsset->m_assetId = djAsset->m_beforeTracksEvent;
    v5 = djAsset->vfptr->GetActiveAssetId(djAsset);
    UFG::RadioStation::AddToPlaylist(this, v5, 1);
  }
  else
  {
    v4 = 0;
  }
  m_trackAssets = djAsset->m_trackAssets;
  v7 = 3i64;
  do
  {
    if ( *m_trackAssets )
    {
      v8 = (*m_trackAssets)->vfptr->GetActiveAssetId(*m_trackAssets);
      for ( i = (UFG::RadioStation *)&this->m_assets.mNode.mNext[-1].mNext;
            i != (UFG::RadioStation *)&this->m_programs.mNode.mNext;
            i = (UFG::RadioStation *)&i->mNext[-1].mNext )
      {
        if ( ((unsigned int (__fastcall *)(UFG::RadioStation *))i->vfptr[1].__vecDelDtor)(i) == v8 )
        {
          LOBYTE(i->m_id) |= 1u;
          v10 = UFG::qMalloc(0x18ui64, "PlayList.Asset", 0i64);
          v11 = (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)v10;
          if ( v10 )
          {
            v10->mNext = v10;
            v10[1].mNext = v10;
            v10[2].mNext = (UFG::allocator::free_link *)i;
          }
          else
          {
            v11 = 0i64;
          }
          mPrev = this->m_playList.mNode.mPrev;
          mPrev->mNext = v11;
          v11->mPrev = mPrev;
          v11->mNext = &this->m_playList.mNode;
          this->m_playList.mNode.mPrev = v11;
        }
      }
    }
    ++m_trackAssets;
    --v7;
  }
  while ( v7 );
  if ( !v4 )
  {
    djAsset->m_assetId = djAsset->m_afterTracksEvent;
    v13 = djAsset->vfptr->GetActiveAssetId(djAsset);
    UFG::RadioStation::AddToPlaylist(this, v13, 1);
  }
}

// File Line: 455
// RVA: 0x66FF70
void __fastcall UFG::RadioStation::AddToPlaylist(UFG::RadioStation *this, const char *id, bool isSeekable)
{
  unsigned int v5; // eax

  v5 = UFG::TiDo::CalcWwiseUid(id);
  UFG::RadioStation::AddToPlaylist(this, v5, isSeekable);
}

// File Line: 459
// RVA: 0x66FEB0
void __fastcall UFG::RadioStation::AddToPlaylist(UFG::RadioStation *this, unsigned int id, bool isSeekable)
{
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *p_mNext; // rbx
  UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **i; // rsi
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v8; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *mPrev; // rcx

  p_mNext = (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)&this->m_assets.mNode.mNext[-1].mNext;
  for ( i = &this->m_programs.mNode.mNext;
        p_mNext != (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)i;
        p_mNext = (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)((char *)p_mNext[1].mPrev - 8) )
  {
    if ( ((unsigned int (__fastcall *)(UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *))p_mNext->mPrev->mNext)(p_mNext) == id )
    {
      BYTE4(p_mNext[2].mPrev) &= ~1u;
      BYTE4(p_mNext[2].mPrev) |= isSeekable;
      v8 = (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)UFG::qMalloc(0x18ui64, "PlayList.Asset", 0i64);
      if ( v8 )
      {
        v8->mPrev = v8;
        v8->mNext = v8;
        v8[1].mPrev = p_mNext;
      }
      mPrev = this->m_playList.mNode.mPrev;
      mPrev->mNext = v8;
      v8->mPrev = mPrev;
      v8->mNext = &this->m_playList.mNode;
      this->m_playList.mNode.mPrev = v8;
    }
  }
}

// File Line: 475
// RVA: 0x688460
void __fastcall UFG::RadioStation::RandomizePlaylist(UFG::RadioStation *this)
{
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *p_m_playList; // rdi
  int v2; // edx
  UFG::RadioStation *mNext; // rax
  __int64 v5; // r15
  float v6; // xmm8_4
  float v7; // xmm0_4
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *v8; // rbx
  int i; // eax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v10; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *mPrev; // rcx
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *j; // rax
  float v13; // xmm0_4
  int v14; // eax
  UFG::RadioStation *v15; // rsi
  int v16; // r14d
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v17; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v18; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v19; // rax
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *k; // rax

  p_m_playList = &this->m_playList;
  v2 = 0;
  mNext = (UFG::RadioStation *)this->m_playList.mNode.mNext;
  if ( mNext != (UFG::RadioStation *)&this->m_playList )
  {
    do
    {
      mNext = (UFG::RadioStation *)mNext->mPrev;
      ++v2;
    }
    while ( mNext != (UFG::RadioStation *)p_m_playList );
  }
  if ( 10 * v2 )
  {
    v5 = (unsigned int)(10 * v2);
    v6 = (float)(v2 - 1);
    do
    {
      v7 = UFG::qRandom(v6, (unsigned int *)&UFG::qDefaultSeed);
      v8 = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)p_m_playList->mNode.mNext;
      for ( i = (int)v7; i > 0; --i )
      {
        if ( v8 == p_m_playList )
          break;
        v8 = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)v8->mNode.mNext;
      }
      if ( !v8 )
        goto LABEL_20;
      v10 = v8->mNode.mNext;
      mPrev = v8->mNode.mPrev;
      mPrev->mNext = v10;
      v10->mPrev = mPrev;
      v8->mNode.mPrev = &v8->mNode;
      v8->mNode.mNext = &v8->mNode;
      for ( j = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)p_m_playList->mNode.mNext;
            j != p_m_playList;
            j = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)j->mNode.mNext )
      {
        ;
      }
      v13 = UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed);
      v14 = ((__int64 (__fastcall *)(UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *))v8[1].mNode.mPrev->mPrev->mNext)(v8[1].mNode.mPrev);
      v15 = (UFG::RadioStation *)this->m_prevPlayed.mNode.mNext;
      v16 = v14;
      if ( v15 == (UFG::RadioStation *)&this->m_prevPlayed )
      {
LABEL_15:
        if ( v13 > 0.5 )
        {
          v18 = p_m_playList->mNode.mNext;
          p_m_playList->mNode.mNext = &v8->mNode;
          v8->mNode.mPrev = &p_m_playList->mNode;
          v8->mNode.mNext = v18;
          v18->mPrev = &v8->mNode;
          goto LABEL_18;
        }
      }
      else
      {
        while ( 1 )
        {
          v17 = v15->mNext;
          if ( v17 )
          {
            if ( ((unsigned int (__fastcall *)(UFG::qNode<UFG::RadioStation,UFG::RadioStation> *))v17->mPrev->mNext)(v17) == v16 )
              break;
          }
          v15 = (UFG::RadioStation *)v15->mPrev;
          if ( v15 == (UFG::RadioStation *)&this->m_prevPlayed )
            goto LABEL_15;
        }
      }
      v19 = p_m_playList->mNode.mPrev;
      v19->mNext = &v8->mNode;
      v8->mNode.mPrev = v19;
      v8->mNode.mNext = &p_m_playList->mNode;
      p_m_playList->mNode.mPrev = &v8->mNode;
LABEL_18:
      for ( k = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)p_m_playList->mNode.mNext;
            k != p_m_playList;
            k = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)k->mNode.mNext )
      {
        ;
      }
LABEL_20:
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 528
// RVA: 0x66F410
void __fastcall UFG::RadioStation::AddCurrentlyPlayingToRecentlyPlayed(UFG::RadioStation *this)
{
  UFG::RadioStationAsset *m_currentlyPlaying; // rdi
  UFG::allocator::free_link *v3; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v4; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *mNext; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *mPrev; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v7; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v8; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v9; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v10; // rax

  ++this->m_numRecentlyPlayed;
  m_currentlyPlaying = this->m_currentlyPlaying;
  v3 = UFG::qMalloc(0x18ui64, "PlayList.Asset", 0i64);
  v4 = (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)v3;
  if ( v3 )
  {
    v3->mNext = v3;
    v3[1].mNext = v3;
    v3[2].mNext = (UFG::allocator::free_link *)m_currentlyPlaying;
  }
  else
  {
    v4 = 0i64;
  }
  mNext = this->m_prevPlayed.mNode.mNext;
  this->m_prevPlayed.mNode.mNext = v4;
  v4->mPrev = &this->m_prevPlayed.mNode;
  v4->mNext = mNext;
  mNext->mPrev = v4;
  if ( this->m_numRecentlyPlayed > 0x14 )
  {
    mPrev = this->m_prevPlayed.mNode.mPrev;
    v7 = mPrev->mPrev;
    v8 = mPrev->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    mPrev->mPrev = mPrev;
    mPrev->mNext = mPrev;
    v9 = mPrev->mPrev;
    v10 = mPrev->mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    mPrev->mPrev = mPrev;
    mPrev->mNext = mPrev;
    operator delete[](mPrev);
    --this->m_numRecentlyPlayed;
  }
  UFG::qString::Set(&this->m_currentlyPlayingAssetName, &customCaption);
  this->m_currentlyPlaying = 0i64;
}

// File Line: 577
// RVA: 0x68BBB0
void __fastcall UFG::RadioStation::SetupTrackAsset(
        UFG::RadioStation *this,
        unsigned __int8 index,
        char *artistName,
        char *trackName)
{
  __int64 v8; // rdi
  unsigned int v9; // ecx
  UFG::RadioStation *i; // rax
  UFG::allocator::free_link *v11; // rax
  __int64 v12; // rax
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *mPrev; // rax

  v8 = 0i64;
  if ( !this->m_assetCount[0] )
  {
    v9 = 0;
    for ( i = (UFG::RadioStation *)&this->m_assets.mNode.mNext[-1].mNext;
          i != (UFG::RadioStation *)&this->m_programs.mNode.mNext;
          i = (UFG::RadioStation *)&i->mNext[-1].mNext )
    {
      ++v9;
    }
    this->m_firstAssetIndex[0] = v9;
  }
  v11 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x40ui64, "TrackAsset", 0i64, 1u);
  if ( v11 )
  {
    UFG::TrackAsset::TrackAsset((UFG::TrackAsset *)v11, this, index, artistName, trackName);
    v8 = v12;
  }
  mPrev = this->m_assets.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v8 + 8);
  *(_QWORD *)(v8 + 8) = mPrev;
  *(_QWORD *)(v8 + 16) = &this->m_assets;
  this->m_assets.mNode.mPrev = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v8 + 8);
  ++this->m_assetCount[0];
}

// File Line: 590
// RVA: 0x68B7B0
void __fastcall UFG::RadioStation::SetupAdAsset(UFG::RadioStation *this, unsigned __int8 index)
{
  __int64 v4; // rdi
  unsigned int v5; // ecx
  UFG::RadioStation *i; // rax
  UFG::allocator::free_link *v7; // rax
  __int64 v8; // rax
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *mPrev; // rax

  v4 = 0i64;
  if ( !this->m_assetCount[2] )
  {
    v5 = 0;
    for ( i = (UFG::RadioStation *)&this->m_assets.mNode.mNext[-1].mNext;
          i != (UFG::RadioStation *)&this->m_programs.mNode.mNext;
          i = (UFG::RadioStation *)&i->mNext[-1].mNext )
    {
      ++v5;
    }
    this->m_firstAssetIndex[2] = v5;
  }
  v7 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x28ui64, "AdAsset", 0i64, 1u);
  if ( v7 )
  {
    UFG::AdAsset::AdAsset((UFG::AdAsset *)v7, this, index);
    v4 = v8;
  }
  mPrev = this->m_assets.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v4 + 8);
  *(_QWORD *)(v4 + 8) = mPrev;
  *(_QWORD *)(v4 + 16) = &this->m_assets;
  this->m_assets.mNode.mPrev = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v4 + 8);
  ++this->m_assetCount[2];
}

// File Line: 603
// RVA: 0x68B870
void __fastcall UFG::RadioStation::SetupIdentAsset(UFG::RadioStation *this)
{
  __int64 v2; // rdi
  unsigned int v3; // ecx
  UFG::RadioStation *i; // rax
  UFG::allocator::free_link *v5; // rax
  __int64 v6; // rax
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *mPrev; // rax

  v2 = 0i64;
  if ( !this->m_assetCount[3] )
  {
    v3 = 0;
    for ( i = (UFG::RadioStation *)&this->m_assets.mNode.mNext[-1].mNext;
          i != (UFG::RadioStation *)&this->m_programs.mNode.mNext;
          i = (UFG::RadioStation *)&i->mNext[-1].mNext )
    {
      ++v3;
    }
    this->m_firstAssetIndex[3] = v3;
  }
  v5 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x28ui64, "IdentAsset", 0i64, 1u);
  if ( v5 )
  {
    UFG::IdentAsset::IdentAsset((UFG::IdentAsset *)v5, this);
    v2 = v6;
  }
  mPrev = this->m_assets.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v2 + 8);
  *(_QWORD *)(v2 + 8) = mPrev;
  *(_QWORD *)(v2 + 16) = &this->m_assets;
  this->m_assets.mNode.mPrev = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v2 + 8);
  ++this->m_assetCount[3];
}

// File Line: 655
// RVA: 0x678C20
UFG::qNode<UFG::RadioStation,UFG::RadioStation> **__fastcall UFG::Radio::FindRadioStation(UFG::qSymbol *name)
{
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> **result; // rax
  unsigned int mUID; // ecx

  result = &UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
  if ( &UFG::Radio::sm_stationList.mNode.mNext[-1].mNext == (UFG::qNode<UFG::RadioStation,UFG::RadioStation> **)((char *)&UFG::Radio::sm_stationList - 8) )
    return 0i64;
  mUID = name->mUID;
  while ( *((_DWORD *)result + 9) != mUID )
  {
    result = &result[2][-1].mNext;
    if ( result == (UFG::qNode<UFG::RadioStation,UFG::RadioStation> **)((char *)&UFG::Radio::sm_stationList - 8) )
      return 0i64;
  }
  return result;
}

// File Line: 667
// RVA: 0x68B170
void __fastcall UFG::Radio::SetRadioType(UFG::Radio *this, UFG::Radio::eRadioType type)
{
  this->m_radioType = type;
}

// File Line: 673
// RVA: 0x67F730
void UFG::Radio::LoadRadioStationData(void)
{
  SimpleXML::XMLDocument *v0; // rax
  SimpleXML::XMLDocument *v1; // r12
  unsigned int v2; // r15d
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *ChildNode; // r14
  char *Attribute; // rbx
  unsigned int v6; // edi
  unsigned int v7; // esi
  double v8; // xmm0_8
  float chanceDj; // xmm6_4
  double v10; // xmm0_8
  float chanceAd; // xmm7_4
  double v12; // xmm0_8
  char copScannerStation; // bp
  UFG::allocator::free_link *v14; // rax
  UFG::RadioStation *v15; // rax
  UFG::RadioStation *v16; // rbp
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *mPrev; // rax
  SimpleXML::XMLNode *v18; // r13
  char *Name; // rdi
  unsigned int v20; // r14d
  SimpleXML::XMLNode *v21; // rbx
  char *v22; // rax
  char *v23; // rdi
  char *v24; // rsi
  unsigned int v25; // eax
  unsigned int v26; // ebx
  __int64 v27; // rdi
  SimpleXML::XMLNode *v28; // rsi
  unsigned __int8 v29; // r14
  char *v30; // rax
  int v31; // ebx
  unsigned int v32; // edi
  char *v33; // rax
  unsigned int v34; // ecx
  __int64 j; // rax
  UFG::allocator::free_link *v36; // rax
  __int64 v37; // rax
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v38; // rcx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v39; // rax
  char *v40; // rax
  char *v41; // rax
  unsigned int v42; // ecx
  __int64 k; // rax
  UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *m; // rax
  UFG::qString result; // [rsp+50h] [rbp-128h] BYREF
  char ptr[184]; // [rsp+80h] [rbp-F8h] BYREF
  char *v47; // [rsp+180h] [rbp+8h]
  SimpleXML::XMLNode *v48; // [rsp+188h] [rbp+10h]
  SimpleXML::XMLNode *i; // [rsp+190h] [rbp+18h]
  SimpleXML::XMLNode *prev_node; // [rsp+198h] [rbp+20h]

  v0 = SimpleXML::XMLDocument::Open("Data\\Audio\\Radios.xml", 1ui64, 0i64);
  v1 = v0;
  v2 = 0;
  if ( v0 )
  {
    Node = SimpleXML::XMLDocument::GetNode(v0, 0i64, 0i64);
    for ( prev_node = Node; Node; prev_node = Node )
    {
      ChildNode = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, Node);
      for ( i = ChildNode; ChildNode; i = ChildNode )
      {
        Attribute = SimpleXML::XMLNode::GetAttribute(ChildNode, "name", &customCaption);
        v6 = SimpleXML::XMLNode::GetAttribute(ChildNode, "id", 0);
        v7 = SimpleXML::XMLNode::GetAttribute(ChildNode, "numConsecutiveTracks", 0);
        v8 = SimpleXML::XMLNode::GetAttribute(ChildNode, "chanceDJ", 0.0);
        chanceDj = *(float *)&v8;
        v10 = SimpleXML::XMLNode::GetAttribute(ChildNode, "chanceAd", 0.0);
        chanceAd = *(float *)&v10;
        v12 = SimpleXML::XMLNode::GetAttribute(ChildNode, "chanceTrack", 0.0);
        copScannerStation = SimpleXML::XMLNode::GetAttribute(ChildNode, "copScanner", 0);
        v14 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x170ui64, "RadioStation", 0i64, 1u);
        if ( v14 )
        {
          UFG::RadioStation::RadioStation(
            (UFG::RadioStation *)v14,
            Attribute,
            v6,
            v7,
            *(float *)&v12,
            chanceDj,
            chanceAd,
            copScannerStation);
          v16 = v15;
        }
        else
        {
          v16 = 0i64;
        }
        mPrev = UFG::Radio::sm_stationList.mNode.mPrev;
        UFG::Radio::sm_stationList.mNode.mPrev->mNext = &v16->UFG::qNode<UFG::RadioStation,UFG::RadioStation>;
        v16->mPrev = mPrev;
        v16->mNext = (UFG::qNode<UFG::RadioStation,UFG::RadioStation> *)&UFG::Radio::sm_stationList;
        UFG::Radio::sm_stationList.mNode.mPrev = &v16->UFG::qNode<UFG::RadioStation,UFG::RadioStation>;
        UFG::RadioStation::SetupIdentAsset(v16);
        v18 = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, ChildNode);
        v48 = v18;
        if ( v18 )
        {
          do
          {
            Name = SimpleXML::XMLNode::GetName(v18);
            v47 = Name;
            if ( !(unsigned int)UFG::qStringCompare(Name, "Tracks", -1) )
            {
              v20 = 1;
              v21 = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, v18);
              if ( v21 )
              {
                do
                {
                  v22 = SimpleXML::XMLNode::GetName(v21);
                  if ( !(unsigned int)UFG::qStringCompare(v22, "Track", -1) )
                  {
                    v23 = &customCaption;
                    v24 = &customCaption;
                    if ( SimpleXML::XMLNode::GetAttribute(v21, "artist") )
                      v24 = SimpleXML::XMLNode::GetAttribute(v21, "artist");
                    if ( SimpleXML::XMLNode::GetAttribute(v21, "name") )
                      v23 = SimpleXML::XMLNode::GetAttribute(v21, "name");
                    UFG::RadioStation::SetupTrackAsset(v16, v20++, v24, v23);
                  }
                  v21 = SimpleXML::XMLDocument::GetNode(v1, 0i64, v21);
                }
                while ( v21 );
                Name = v47;
              }
            }
            if ( !(unsigned int)UFG::qStringCompare(Name, "Ads", -1) )
            {
              v25 = SimpleXML::XMLNode::GetAttribute(v18, "count", 0);
              v26 = 1;
              if ( v25 )
              {
                v27 = v25;
                do
                {
                  UFG::RadioStation::SetupAdAsset(v16, v26++);
                  --v27;
                }
                while ( v27 );
                Name = v47;
              }
            }
            if ( !(unsigned int)UFG::qStringCompare(Name, "DJs", -1) )
            {
              SimpleXML::XMLNode::GetAttribute(v18, "count", 0);
              v28 = SimpleXML::XMLDocument::GetChildNode(v1, 0i64, v18);
              v29 = 1;
              if ( v28 )
              {
                do
                {
                  v30 = SimpleXML::XMLNode::GetName(v28);
                  if ( !(unsigned int)UFG::qStringCompare(v30, "DJ", -1) )
                  {
                    `eh vector constructor iterator(
                      ptr,
                      0x28ui64,
                      3,
                      (void (__fastcall *)(void *))UFG::qString::qString);
                    v31 = 0;
                    do
                    {
                      v32 = v31 + 1;
                      UFG::qString::FormatEx(&result, "track%d", (unsigned int)(v31 + 1));
                      if ( SimpleXML::XMLNode::GetAttribute(v28, result.mData) )
                      {
                        v33 = SimpleXML::XMLNode::GetAttribute(v28, result.mData);
                        UFG::qString::Set((UFG::qString *)&ptr[40 * v31], v33);
                      }
                      UFG::qString::~qString(&result);
                      ++v31;
                    }
                    while ( v32 < 3 );
                    if ( !v16->m_assetCount[1] )
                    {
                      v34 = 0;
                      for ( j = (__int64)&v16->m_assets.mNode.mNext[-1].mNext;
                            (UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **)j != &v16->m_programs.mNode.mNext;
                            j = *(_QWORD *)(j + 16) - 8i64 )
                      {
                        ++v34;
                      }
                      v16->m_firstAssetIndex[1] = v34;
                    }
                    v36 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x48ui64, "DJAsset", 0i64, 1u);
                    if ( v36 )
                      UFG::DJAsset::DJAsset((UFG::DJAsset *)v36, v16, v29, (UFG::qString *)ptr, 3u);
                    else
                      v37 = 0i64;
                    v38 = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v37 + 8);
                    v39 = v16->m_assets.mNode.mPrev;
                    v39->mNext = v38;
                    v38->mPrev = v39;
                    v38->mNext = &v16->m_assets.mNode;
                    v16->m_assets.mNode.mPrev = v38;
                    ++v16->m_assetCount[1];
                    ++v29;
                    `eh vector destructor iterator(
                      ptr,
                      0x28ui64,
                      3,
                      (void (__fastcall *)(void *))UFG::qString::~qString);
                  }
                  v28 = SimpleXML::XMLDocument::GetNode(v1, 0i64, v28);
                }
                while ( v28 );
                v18 = v48;
                Name = v47;
              }
            }
            if ( !(unsigned int)UFG::qStringCompare(Name, "TextureName", -1) )
            {
              v40 = SimpleXML::XMLNode::GetAttribute(v18, "name");
              UFG::qString::Set(&v16->m_textureName, v40);
            }
            if ( !(unsigned int)UFG::qStringCompare(Name, "TexturePack", -1) )
            {
              v41 = SimpleXML::XMLNode::GetAttribute(v18, "name");
              UFG::qString::Set(&v16->m_texturePack, v41);
            }
            v18 = SimpleXML::XMLDocument::GetNode(v1, 0i64, v18);
            v48 = v18;
          }
          while ( v18 );
          ChildNode = i;
        }
        v42 = 0;
        for ( k = (__int64)&v16->m_assets.mNode.mNext[-1].mNext;
              (UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **)k != &v16->m_programs.mNode.mNext;
              k = *(_QWORD *)(k + 16) - 8i64 )
        {
          ++v42;
        }
        v16->m_numAssets = v42;
        ChildNode = SimpleXML::XMLDocument::GetNode(v1, 0i64, ChildNode);
      }
      Node = SimpleXML::XMLDocument::GetNode(v1, 0i64, prev_node);
    }
    SimpleXML::XMLDocument::~XMLDocument(v1);
    operator delete[](v1);
  }
  for ( m = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
        m != (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)((char *)&UFG::Radio::sm_stationList - 8);
        m = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&m[1].mNode.mPrev[-1].mNext )
  {
    ++v2;
  }
  UFG::Radio::sm_numStations = v2;
}

// File Line: 841
// RVA: 0x6745F0
void UFG::Radio::ClearRadioStationData(void)
{
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *i; // rax
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *mNext; // rcx
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *mPrev; // rdx

  for ( i = UFG::Radio::sm_stationList.mNode.mNext;
        &UFG::Radio::sm_stationList.mNode.mNext[-1].mNext != (UFG::qNode<UFG::RadioStation,UFG::RadioStation> **)((char *)&UFG::Radio::sm_stationList - 8);
        i = UFG::Radio::sm_stationList.mNode.mNext )
  {
    mNext = i->mNext;
    mPrev = i->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::RadioStation,UFG::RadioStation> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::RadioStation,UFG::RadioStation> **, __int64))i[-1].mNext->mPrev)(
        &i[-1].mNext,
        1i64);
  }
}

// File Line: 846
// RVA: 0x669E90
void __fastcall UFG::Radio::Radio(UFG::Radio *this)
{
  UFG::AudioEntity::AudioEntity(this);
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::Radio::`vftable;
  this->m_ecRadio.m_pEvent = 0i64;
  *(_QWORD *)&this->m_timeSinceRadioStarted = 0i64;
  this->m_buttonHoldLength = 0.0;
  this->m_ignoreRelease = 0;
  this->m_pVehAudComponent = 0i64;
  *(_QWORD *)&this->m_adjacentNextStationCount = 0i64;
  *((_BYTE *)this + 345) &= ~1u;
  this->m_timeSinceStationChanged = 0.0;
  this->m_radioType = eRadioType_Radio;
  UFG::Radio::SetupParams(this, -1);
}

// File Line: 879
// RVA: 0x68B930
void __fastcall UFG::Radio::SetupParams(UFG::Radio *this, int station)
{
  char *MemImagePtr; // rsi
  int v3; // r8d
  UFG::Radio *v4; // rbx
  UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *p_mNext; // rdx
  float v6; // xmm0_4
  int i; // ecx
  UFG::VehicleAudioComponent *m_pVehAudComponent; // rax
  UFG::qPropertySet *mpPropertySet; // rdi

  MemImagePtr = 0i64;
  *((_BYTE *)this + 344) = -124;
  this->m_curStation = 0i64;
  v3 = station;
  v4 = this;
  if ( station < 0 )
  {
    v6 = UFG::qRandom((float)(int)UFG::Radio::sm_numStations - 1.0, (unsigned int *)&UFG::qDefaultSeed);
    p_mNext = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
    for ( i = (int)v6;
          i > 0;
          p_mNext = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&p_mNext[1].mNode.mPrev[-1].mNext )
    {
      if ( p_mNext == (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)((char *)&UFG::Radio::sm_stationList - 8) )
        break;
      --i;
    }
    this = v4;
  }
  else
  {
    for ( p_mNext = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
          v3 > 0;
          p_mNext = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&p_mNext[1].mNode.mPrev[-1].mNext )
    {
      if ( p_mNext == (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)((char *)&UFG::Radio::sm_stationList - 8) )
        break;
      --v3;
    }
  }
  UFG::Radio::SetCurStation(this, (UFG::RadioStation *)p_mNext);
  m_pVehAudComponent = v4->m_pVehAudComponent;
  if ( m_pVehAudComponent )
  {
    mpPropertySet = m_pVehAudComponent->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(mpPropertySet->mSchemaName.mUID) )
      MemImagePtr = UFG::qPropertySet::GetMemImagePtr(mpPropertySet);
    *((_BYTE *)v4 + 344) ^= (*((_BYTE *)v4 + 344) ^ MemImagePtr[192]) & 1;
  }
}

// File Line: 914
// RVA: 0x67C650
void __fastcall UFG::Radio::HandleInputs(UFG::Radio *this)
{
  hkgpIndexedMeshDefinitions::Edge *v2; // rdx
  hkgpIndexedMesh::EdgeBarrier *v3; // rcx
  __int64 v4; // rdi
  UFG::InputActionData *v5; // rax
  float mSimTimeDelta; // xmm6_4
  UFG::UIHKScreenHud *Instance; // rax
  UFG::UIHKRadioStationWidget *p_RadioStationWidget; // rsi
  __int64 v9; // rdx
  UFG::InputActionData *v10; // rax
  UFG::UIHKScreenHud *v11; // rax
  UFG::UIHKRadioStationWidget *v12; // rsi
  __int64 v13; // rdx
  UFG::InputActionData *v14; // rax
  UFG::InputActionData *v15; // rax
  UFG::InputActionData *v16; // rax
  UFG::InputActionData *v17; // rax
  UFG::InputActionData *v18; // rax
  UFG::InputActionData *v19; // rax

  if ( UFG::UIHKScreenHud::getInstance() )
  {
    UFG::Music::sm_bIsObjectActiveDirty = 1;
    if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v3, v2)
      || !UFG::Music::sm_bIsObjectActive )
    {
      v4 = (int)UFG::gActiveControllerNum;
      v5 = UFG::ActionDef_NextRadioStationReleased.mDataPerController[UFG::gActiveControllerNum];
      mSimTimeDelta = UFG::Metrics::msInstance.mSimTimeDelta;
      if ( v5 && v5->mActionTrue )
      {
        if ( !this->m_ignoreRelease )
        {
          Instance = UFG::UIHKScreenHud::getInstance();
          if ( Instance )
          {
            p_RadioStationWidget = &Instance->RadioStationWidget;
            if ( UFG::UIHKRadioStationWidget::IsActive(&Instance->RadioStationWidget) )
            {
              LOBYTE(v9) = 1;
              (*(void (__fastcall **)(UFG::Radio *, __int64))this->vfptr[1].gap8)(this, v9);
            }
            else
            {
              UFG::Radio::PlayClick(this);
              UFG::UIHKRadioStationWidget::ChangeStation(p_RadioStationWidget, this->m_curStation->m_id);
            }
          }
        }
        this->m_ignoreRelease = 0;
      }
      v10 = UFG::ActionDef_PrevRadioStationReleased.mDataPerController[v4];
      if ( v10 && v10->mActionTrue )
      {
        if ( !this->m_ignoreRelease )
        {
          v11 = UFG::UIHKScreenHud::getInstance();
          if ( v11 )
          {
            v12 = &v11->RadioStationWidget;
            if ( UFG::UIHKRadioStationWidget::IsActive(&v11->RadioStationWidget) )
            {
              LOBYTE(v13) = 1;
              ((void (__fastcall *)(UFG::Radio *, __int64))this->vfptr[1].StopAndForgetEvent)(this, v13);
            }
            else
            {
              UFG::Radio::PlayClick(this);
              UFG::UIHKRadioStationWidget::ChangeStation(v12, this->m_curStation->m_id);
            }
          }
        }
        this->m_ignoreRelease = 0;
      }
      v14 = UFG::ActionDef_NextRadioStationHold.mDataPerController[v4];
      if ( v14 && v14->mActionTrue
        || (v15 = UFG::ActionDef_PrevRadioStationHold.mDataPerController[v4]) != 0i64 && v15->mActionTrue )
      {
        this->m_buttonHoldLength = mSimTimeDelta + this->m_buttonHoldLength;
      }
      else
      {
        this->m_buttonHoldLength = 0.0;
      }
      v16 = UFG::ActionDef_NextRadioStationHold.mDataPerController[v4];
      if ( v16 && v16->mActionTrue && this->m_buttonHoldLength > 0.40000001 )
      {
        if ( (*((_BYTE *)this + 344) & 4) != 0 )
        {
          ((void (__fastcall *)(UFG::Radio *))this->vfptr[1].AudioEntityUpdate)(this);
          UFG::Radio::PlayClick(this);
        }
        UFG::Radio::IncreaseRadioVolume(this);
        this->m_buttonHoldLength = 0.0;
        this->m_ignoreRelease = 1;
      }
      v17 = UFG::ActionDef_UIDownPressed.mDataPerController[v4];
      if ( v17 && v17->mActionTrue )
        this->m_ignoreRelease = 1;
      v18 = UFG::ActionDef_UIUpPressed.mDataPerController[v4];
      if ( v18 && v18->mActionTrue )
        this->m_ignoreRelease = 1;
      v19 = UFG::ActionDef_PrevRadioStationHold.mDataPerController[v4];
      if ( v19 && v19->mActionTrue && this->m_buttonHoldLength > 0.40000001 )
      {
        if ( (*((_BYTE *)this + 344) & 4) == 0 )
          UFG::Radio::DecreaseRadioVolume(this);
        this->m_buttonHoldLength = 0.0;
        this->m_ignoreRelease = 1;
      }
    }
  }
}

// File Line: 1029
// RVA: 0x6932B0
void __fastcall UFG::Radio::Update(UFG::Radio *this, float delta_sec)
{
  int v3; // edx
  int v4; // r8d
  UFG::VehicleAudioComponent *m_pVehAudComponent; // rcx
  char *v6; // rax
  UFG::qString *v7; // rax
  UFG::qString *v8; // rax
  UFG::AudioEntityVtbl *vfptr; // rbx
  UFG::qSymbol *v10; // rax
  UFG::RadioStation *m_curStation; // rcx
  bool v12; // bl
  UFG::UIHKScreenHud *Instance; // rax
  UFG::UIHKScreenHud *v14; // rax
  UFG::qString v15; // [rsp+38h] [rbp-90h] BYREF
  UFG::qString result; // [rsp+60h] [rbp-68h] BYREF
  UFG::qString v17; // [rsp+88h] [rbp-40h] BYREF
  UFG::qSymbol v18; // [rsp+D0h] [rbp+8h] BYREF

  UFG::Radio::HandleInputs(this);
  if ( this->m_bIsInitialized )
  {
    this->m_timeSinceStationChanged = delta_sec + this->m_timeSinceStationChanged;
    m_curStation = this->m_curStation;
    v12 = m_curStation
       && (UFG::SoundBankManager::BankLoaded(&m_curStation->m_bankId) || this->m_curStation->m_bIsCopScannerStation)
       && UFG::Radio::PlayerInVehicle(this)
       && this->m_timeSinceStationChanged > 0.30000001;
    if ( (*((_BYTE *)this + 344) & 0x20) != 0 && v12 )
    {
      Instance = UFG::UIHKScreenHud::getInstance();
      if ( Instance )
        UFG::UIHKRadioStationWidget::ChangeStation(&Instance->RadioStationWidget, this->m_curStation->m_id);
      *((_BYTE *)this + 344) &= ~0x20u;
    }
    if ( (*((_BYTE *)this + 344) & 0x40) != 0 && v12 )
    {
      v14 = UFG::UIHKScreenHud::getInstance();
      if ( v14 )
        UFG::UIHKRadioStationWidget::ChangeStation(&v14->RadioStationWidget, this->m_curStation->m_id);
      *((_BYTE *)this + 344) &= ~0x40u;
    }
    if ( (*((_BYTE *)this + 344) & 8) != 0 && v12 )
    {
      if ( !this->m_curStation->m_bIsCopScannerStation )
        UFG::Radio::DoStartTrack(this, v3, v4);
      *((_BYTE *)this + 344) &= 0xE7u;
    }
    if ( !UFG::Radio::s_bEnabled && (*((_BYTE *)this + 344) & 2) != 0 )
      ((void (__fastcall *)(UFG::Radio *, __int64))this->vfptr[1].StopAndForgetAllEvents)(this, 500i64);
  }
  else
  {
    UFG::qString::qString(&v15, &customCaption);
    m_pVehAudComponent = this->m_pVehAudComponent;
    if ( m_pVehAudComponent )
    {
      v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pVehAudComponent->m_pSimObject->m_Name);
      UFG::qString::qString(&v17, v6);
      v8 = UFG::operator+(&result, v7, "_Radio");
      UFG::qString::Set(&v15, v8->mData, v8->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      UFG::qString::~qString(&v17);
    }
    vfptr = this->vfptr;
    v10 = UFG::qSymbol::create_from_string(&v18, v15.mData);
    (*(void (__fastcall **)(UFG::Radio *, UFG::qSymbol *, UFG::qMatrix44 *))vfptr->gap8)(
      this,
      v10,
      &UFG::qMatrix44::msIdentity);
    *((_BYTE *)this + 344) |= 0x80u;
    UFG::qString::~qString(&v15);
  }
}

// File Line: 1101
// RVA: 0x6707D0
void __fastcall UFG::Radio::AdvanceAllStations(UFG::Radio *this, float delta_sec)
{
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> **i; // rax
  bool v3; // zf
  float v4; // xmm0_4
  float v5; // xmm0_4

  for ( i = &UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
        i != (UFG::qNode<UFG::RadioStation,UFG::RadioStation> **)((char *)&UFG::Radio::sm_stationList - 8);
        i = &i[2][-1].mNext )
  {
    if ( i )
    {
      v3 = i == (UFG::qNode<UFG::RadioStation,UFG::RadioStation> **)this->m_curStation;
      *((float *)i + 8) = delta_sec + *((float *)i + 8);
      if ( v3 )
      {
        v4 = delta_sec + *((float *)i + 6);
        *((_DWORD *)i + 7) = 0;
        *((float *)i + 6) = v4;
      }
      else
      {
        v5 = delta_sec + *((float *)i + 7);
        *((_DWORD *)i + 6) = 0;
        *((float *)i + 7) = v5;
      }
    }
  }
}

// File Line: 1119
// RVA: 0x69A530
void __fastcall UFG::Radio::UpdateTrackTimers(UFG::Radio *this, float delta_sec)
{
  float v3; // xmm6_4
  float v4; // xmm6_4

  if ( (*((_BYTE *)this + 344) & 4) != 0 )
  {
    v3 = delta_sec + this->m_timeSinceRadioStopped;
    this->m_timeSinceRadioStarted = 0.0;
    if ( v3 <= 0.0 )
    {
      v3 = 0.0;
    }
    else if ( v3 >= 600.0 )
    {
      this->m_timeSinceRadioStopped = FLOAT_600_0;
      return;
    }
    this->m_timeSinceRadioStopped = v3;
  }
  else
  {
    UFG::Radio::AdvanceAllStations(this, delta_sec);
    v4 = delta_sec + this->m_timeSinceRadioStarted;
    this->m_timeSinceRadioStopped = 0.0;
    if ( v4 <= 0.0 )
    {
      v4 = 0.0;
    }
    else if ( v4 >= 600.0 )
    {
      this->m_timeSinceRadioStarted = FLOAT_600_0;
      return;
    }
    this->m_timeSinceRadioStarted = v4;
  }
}

// File Line: 1139
// RVA: 0x681D70
void __fastcall UFG::Radio::NextStation(UFG::Radio *this, bool displayStationId)
{
  char v4; // al
  UFG::AudioEntityVtbl *vfptr; // rax
  UFG::RadioStation *m_curStation; // rbx
  bool v7; // bl
  UFG::RadioStationAsset *m_currentlyPlaying; // rcx

  if ( UFG::Radio::s_bEnabled )
  {
    v4 = *((_BYTE *)this + 344);
    if ( (v4 & 1) != 0 && (v4 & 0x20) == 0 && (v4 & 0x40) == 0 )
    {
      vfptr = this->vfptr;
      ++this->m_adjacentNextStationCount;
      this->m_timeSinceStationChanged = 0.0;
      this->m_adjacentPrevStationCount = 0;
      ((void (__fastcall *)(UFG::Radio *, __int64))vfptr[1].StopAndForgetAllEvents)(this, 500i64);
      m_curStation = this->m_curStation;
      UFG::Radio::GetNextStationId(this);
      if ( m_curStation != this->m_curStation )
        UFG::Radio::PlayClick(this);
      *((_BYTE *)this + 344) |= 0x80u;
      v7 = 0;
      m_currentlyPlaying = this->m_curStation->m_currentlyPlaying;
      if ( m_currentlyPlaying )
      {
        v7 = m_currentlyPlaying->m_type == eRadioStationAssetType_Ad;
        if ( this->m_adjacentNextStationCount == UFG::Radio::sm_numStations - 1 )
        {
          UFG::Radio::AdvanceAllStations(this, 180.0);
          this->m_adjacentNextStationCount = 0;
        }
      }
      ((void (__fastcall *)(UFG::Radio *, bool))this->vfptr[1].DestroyAllEvents)(this, v7);
      if ( displayStationId )
        *((_BYTE *)this + 344) |= 0x20u;
    }
  }
}

// File Line: 1201
// RVA: 0x687600
void __fastcall UFG::Radio::PrevStation(UFG::Radio *this, bool displayStationId)
{
  char v4; // al
  UFG::AudioEntityVtbl *vfptr; // rax
  UFG::RadioStation *m_curStation; // rbx
  bool v7; // bl
  UFG::RadioStationAsset *m_currentlyPlaying; // rcx

  if ( UFG::Radio::s_bEnabled )
  {
    v4 = *((_BYTE *)this + 344);
    if ( (v4 & 1) != 0 && (v4 & 0x40) == 0 && (v4 & 0x20) == 0 )
    {
      vfptr = this->vfptr;
      ++this->m_adjacentPrevStationCount;
      this->m_timeSinceStationChanged = 0.0;
      this->m_adjacentNextStationCount = 0;
      ((void (__fastcall *)(UFG::Radio *, __int64))vfptr[1].StopAndForgetAllEvents)(this, 500i64);
      m_curStation = this->m_curStation;
      UFG::Radio::GetPrevStationId(this);
      if ( m_curStation != this->m_curStation )
        UFG::Radio::PlayClick(this);
      *((_BYTE *)this + 344) |= 0x80u;
      v7 = 0;
      m_currentlyPlaying = this->m_curStation->m_currentlyPlaying;
      if ( m_currentlyPlaying )
      {
        v7 = m_currentlyPlaying->m_type == eRadioStationAssetType_Ad;
        if ( this->m_adjacentPrevStationCount == UFG::Radio::sm_numStations - 1 )
        {
          UFG::Radio::AdvanceAllStations(this, 180.0);
          this->m_adjacentPrevStationCount = 0;
        }
      }
      ((void (__fastcall *)(UFG::Radio *, bool))this->vfptr[1].DestroyAllEvents)(this, v7);
      if ( displayStationId )
        *((_BYTE *)this + 344) |= 0x40u;
    }
  }
}

// File Line: 1261
// RVA: 0x68B5B0
void __fastcall UFG::Radio::SetStation(UFG::Radio *this, unsigned int stationIdx)
{
  UFG::RadioStation *m_curStation; // r8
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *mNext; // rax
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *p_m_playList; // r8
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *mPrev; // rcx
  char v8; // al
  int v9; // ecx
  UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *i; // rdx
  char v11; // al

  m_curStation = this->m_curStation;
  if ( m_curStation->m_id != stationIdx )
  {
    if ( !m_curStation
      || (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)m_curStation->m_playList.mNode.mNext == &m_curStation->m_playList
      || (mNext = m_curStation->m_playList.mNode.mNext,
          p_m_playList = &m_curStation->m_playList,
          mNext == (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)p_m_playList) )
    {
LABEL_8:
      v8 = *((_BYTE *)this + 344);
      if ( (v8 & 4) == 0 && (v8 & 2) != 0 )
        ((void (__fastcall *)(UFG::Radio *, __int64))this->vfptr[1].StopAndForgetAllEvents)(this, 500i64);
      v9 = stationIdx - 1;
      for ( i = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
            v9 > 0;
            i = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&i[1].mNode.mPrev[-1].mNext )
      {
        if ( i == (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)((char *)&UFG::Radio::sm_stationList - 8) )
          break;
        --v9;
      }
      UFG::Radio::SetCurStation(this, (UFG::RadioStation *)i);
      v11 = *((_BYTE *)this + 344);
      if ( (v11 & 4) == 0 && (v11 & 2) != 0 )
        ((void (__fastcall *)(UFG::Radio *, _QWORD))this->vfptr[1].DestroyAllEvents)(this, 0i64);
    }
    else
    {
      while ( 1 )
      {
        mPrev = mNext[1].mPrev;
        if ( mPrev )
        {
          if ( (BYTE4(mPrev[2].mPrev) & 1) == 0 )
            break;
        }
        mNext = mNext->mNext;
        if ( mNext == (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)p_m_playList )
          goto LABEL_8;
      }
    }
  }
}

// File Line: 1298
// RVA: 0x67A990
void __fastcall UFG::Radio::GetNextStationId(UFG::Radio *this)
{
  UFG::RadioStation *m_curStation; // rcx
  char *v3; // rax
  __int64 p_mNext; // rbx
  UFG::Radio::eRadioType m_radioType; // edx
  UFG::RadioStation *v6; // rcx

  m_curStation = this->m_curStation;
  v3 = (char *)&UFG::Radio::sm_stationList - 8;
  p_mNext = (__int64)&m_curStation->mNext[-1].mNext;
  if ( (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)p_mNext == (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)((char *)&UFG::Radio::sm_stationList - 8) )
    p_mNext = *(_QWORD *)(p_mNext + 16) - 8i64;
  m_radioType = this->m_radioType;
  if ( m_radioType == eRadioType_Radio && *(_BYTE *)(p_mNext + 361) )
  {
    do
    {
      p_mNext = *(_QWORD *)(p_mNext + 16) - 8i64;
      if ( (char *)p_mNext == v3 )
        p_mNext = *(_QWORD *)(p_mNext + 16) - 8i64;
    }
    while ( *(_BYTE *)(p_mNext + 361) );
  }
  if ( m_radioType == eRadioType_Scanner && !*(_BYTE *)(p_mNext + 361) )
  {
    do
    {
      p_mNext = *(_QWORD *)(p_mNext + 16) - 8i64;
      if ( (char *)p_mNext == v3 )
        p_mNext = *(_QWORD *)(p_mNext + 16) - 8i64;
    }
    while ( !*(_BYTE *)(p_mNext + 361) );
  }
  if ( m_curStation != (UFG::RadioStation *)p_mNext )
  {
    if ( m_curStation )
      UFG::TiDo::UnloadWwiseBank(&m_curStation->m_bankId);
    UFG::GameStatAction::Radio::Stop(this->m_curStation);
    this->m_curStation = (UFG::RadioStation *)p_mNext;
    UFG::GameStatAction::Radio::Start();
    v6 = this->m_curStation;
    if ( v6 )
      UFG::TiDo::LoadWwiseBank(&v6->m_bankId);
  }
}

// File Line: 1329
// RVA: 0x67AFE0
void __fastcall UFG::Radio::GetPrevStationId(UFG::Radio *this)
{
  UFG::RadioStation *m_curStation; // rcx
  char *v3; // rax
  __int64 p_mNext; // rbx
  UFG::Radio::eRadioType m_radioType; // edx
  UFG::RadioStation *v6; // rcx

  m_curStation = this->m_curStation;
  v3 = (char *)&UFG::Radio::sm_stationList - 8;
  p_mNext = (__int64)&m_curStation->mPrev[-1].mNext;
  if ( (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)p_mNext == (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)((char *)&UFG::Radio::sm_stationList - 8) )
    p_mNext = (__int64)&m_curStation->mPrev->mPrev[-1].mNext;
  m_radioType = this->m_radioType;
  if ( m_radioType == eRadioType_Radio && *(_BYTE *)(p_mNext + 361) )
  {
    do
    {
      p_mNext = *(_QWORD *)(p_mNext + 8) - 8i64;
      if ( (char *)p_mNext == v3 )
        p_mNext = *(_QWORD *)(p_mNext + 8) - 8i64;
    }
    while ( *(_BYTE *)(p_mNext + 361) );
  }
  if ( m_radioType == eRadioType_Scanner && !*(_BYTE *)(p_mNext + 361) )
  {
    do
    {
      p_mNext = *(_QWORD *)(p_mNext + 8) - 8i64;
      if ( (char *)p_mNext == v3 )
        p_mNext = *(_QWORD *)(p_mNext + 8) - 8i64;
    }
    while ( !*(_BYTE *)(p_mNext + 361) );
  }
  if ( m_curStation != (UFG::RadioStation *)p_mNext )
  {
    if ( m_curStation )
      UFG::TiDo::UnloadWwiseBank(&m_curStation->m_bankId);
    UFG::GameStatAction::Radio::Stop(this->m_curStation);
    this->m_curStation = (UFG::RadioStation *)p_mNext;
    UFG::GameStatAction::Radio::Start();
    v6 = this->m_curStation;
    if ( v6 )
      UFG::TiDo::LoadWwiseBank(&v6->m_bankId);
  }
}

// File Line: 1384
// RVA: 0x68C520
void __fastcall UFG::Radio::StartTrack(UFG::RadioFullyControlled *this, bool skipTrack)
{
  *((_BYTE *)&this->UFG::Radio + 344) = *((_BYTE *)&this->UFG::Radio + 344) ^ (*((_BYTE *)&this->UFG::Radio + 344) ^ (16 * skipTrack)) & 0x10 | 8;
}

// File Line: 1392
// RVA: 0x68A490
void __fastcall UFG::Radio::SetCurStation(UFG::Radio *this, UFG::RadioStation *station)
{
  UFG::RadioStation *m_curStation; // rcx
  UFG::RadioStation *v5; // rcx

  m_curStation = this->m_curStation;
  if ( m_curStation != station )
  {
    if ( m_curStation )
      UFG::TiDo::UnloadWwiseBank(&m_curStation->m_bankId);
    UFG::GameStatAction::Radio::Stop(this->m_curStation);
    this->m_curStation = station;
    UFG::GameStatAction::Radio::Start();
    v5 = this->m_curStation;
    if ( v5 )
      UFG::TiDo::LoadWwiseBank(&v5->m_bankId);
  }
}

// File Line: 1416
// RVA: 0x676F00
void __fastcall UFG::Radio::DoStartTrack(UFG::Radio *this, int a2, int a3)
{
  UFG::AudioEvent *m_pEvent; // rax
  char v5; // al
  UFG::VehicleAudioComponent *m_pVehAudComponent; // rax
  UFG::AudioEvent *v7; // rcx
  UFG::RadioStationAsset *m_currentlyPlaying; // rcx
  unsigned int NextTrack; // eax
  char v10; // al
  UFG::UIHKScreenHud *Instance; // rax
  UFG::RadioStation *m_curStation; // rdx
  UFG::RadioStationAsset *v13; // rax
  UFG::AudioEvent *v14; // rcx
  __int64 v15; // [rsp+48h] [rbp-30h]
  UFG::AudioEventInitParams pInitParams; // [rsp+50h] [rbp-28h] BYREF

  if ( UFG::Radio::s_bEnabled
    && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse((hkGeometryUtils::IVertices *)this, a2, a3) )
  {
    m_pEvent = this->m_ecRadio.m_pEvent;
    if ( (!m_pEvent || (*((_BYTE *)m_pEvent + 144) & 0x40) == 0) && UFG::Radio::PlayerInVehicle(this) )
    {
      v5 = *((_BYTE *)this + 344);
      if ( (v5 & 4) == 0 && (v5 & 2) == 0 )
      {
        m_pVehAudComponent = this->m_pVehAudComponent;
        if ( m_pVehAudComponent )
        {
          if ( (*((_BYTE *)m_pVehAudComponent + 636) & 8) != 0 )
          {
            v7 = this->m_ecRadio.m_pEvent;
            if ( v7 )
              UFG::AudioEvent::StopAndForget(v7, 0);
            *((_BYTE *)this + 344) |= 2u;
            if ( (_S17_7 & 1) == 0 )
            {
              _S17_7 |= 1u;
              effect_off_on.mUID = UFG::qWiseSymbolUIDFromString("effect_off_on", 0x811C9DC5);
              _((AMD_HD3D *)effect_off_on.mUID);
              atexit(UFG::Radio::DoStartTrack_::_10_::_dynamic_atexit_destructor_for__effect_off_on__);
            }
            UFG::AudioEntity::SetRtpcValue(this, effect_off_on.mUID, 0.94999999);
            pInitParams.m_EventCallbackUserData = 0i64;
            LODWORD(v15) = 0;
            pInitParams.m_EventPlayEndCallback = (void (__fastcall *)(UFG::AudioEntity *, UFG::eAudioEventCallbackType, UFG::AudioEvent *, void *))UFG::Radio::TrackFinishCallback;
            *(_QWORD *)pInitParams.gap8 = 0i64;
            *(_QWORD *)&pInitParams.gap8[8] = v15;
            m_currentlyPlaying = this->m_curStation->m_currentlyPlaying;
            NextTrack = 0;
            if ( m_currentlyPlaying )
              NextTrack = m_currentlyPlaying->vfptr->GetActiveAssetId(m_currentlyPlaying);
            if ( (*((_BYTE *)this + 344) & 0x10) != 0 || !NextTrack )
            {
              UFG::RadioStation::AddCurrentlyPlayingToRecentlyPlayed(this->m_curStation);
              NextTrack = UFG::RadioStation::GetNextTrack(this->m_curStation);
            }
            v10 = UFG::AudioEntity::CreateAndPlayEvent(this, NextTrack, &this->m_ecRadio, &pInitParams, 0, 0i64);
            *((_BYTE *)this + 344) &= ~2u;
            *((_BYTE *)this + 344) |= 2 * (v10 & 1);
            Instance = UFG::UIHKScreenHud::getInstance();
            if ( Instance )
              UFG::UIHKRadioStationWidget::HandleNewSong(&Instance->RadioStationWidget);
            if ( *((char *)this + 344) < 0 )
            {
              m_curStation = this->m_curStation;
              v13 = m_curStation->m_currentlyPlaying;
              if ( v13 )
              {
                if ( (*((_BYTE *)v13 + 36) & 1) != 0 )
                {
                  v14 = this->m_ecRadio.m_pEvent;
                  if ( v14 )
                    v14->vfptr->SeekMS(v14, (int)(float)(m_curStation->m_currentTrackTimer * 1000.0));
                  *((_BYTE *)this + 344) &= ~0x80u;
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 1485
// RVA: 0x68CA90
char __fastcall UFG::Radio::StopTrack(UFG::Radio *this, int fadeOut)
{
  UFG::AudioEvent *m_pEvent; // rax

  m_pEvent = this->m_ecRadio.m_pEvent;
  *((_BYTE *)this + 344) &= ~2u;
  if ( !m_pEvent )
    return 1;
  *((_BYTE *)this + 345) |= 1u;
  UFG::AudioEvent::StopAndForget(m_pEvent, fadeOut);
  return 0;
}

// File Line: 1498
// RVA: 0x68D2F0
void __fastcall UFG::Radio::TrackFinishCallback(
        UFG::Radio *this,
        __int64 in_eType,
        UFG::AudioEvent *in_pEvent,
        void *in_pCallbackInfo)
{
  char v4; // al
  UFG::RadioStation *m_curStation; // rax
  UFG::AudioEvent *m_pEvent; // rax
  UFG::AudioEntityVtbl *vfptr; // rax

  if ( (_DWORD)in_eType == 2 && (*((_BYTE *)this + 344) & 4) == 0 )
  {
    v4 = *((_BYTE *)this + 345);
    if ( (v4 & 1) != 0 )
    {
      *((_BYTE *)this + 345) = v4 & 0xFE;
    }
    else
    {
      m_curStation = this->m_curStation;
      if ( m_curStation )
        m_curStation->m_currentTrackTimer = 0.0;
    }
    m_pEvent = this->m_ecRadio.m_pEvent;
    if ( !m_pEvent || (*((_BYTE *)m_pEvent + 144) & 0x40) == 0 )
    {
      vfptr = this->vfptr;
      *((_BYTE *)this + 344) &= ~2u;
      LOBYTE(in_eType) = 1;
      ((void (__fastcall *)(UFG::Radio *, __int64, UFG::AudioEvent *, void *))vfptr[1].DestroyAllEvents)(
        this,
        in_eType,
        in_pEvent,
        in_pCallbackInfo);
    }
  }
}

// File Line: 1533
// RVA: 0x68B180
void __fastcall UFG::Radio::SetRadioVolume(UFG::Radio *this, float volume)
{
  float v2; // xmm2_4
  UFG::TiDo *Instance; // rax
  UFG::GameStatTracker *v4; // rax

  if ( volume <= 0.0 )
  {
    volume = 0.0;
  }
  else
  {
    v2 = FLOAT_10_0;
    if ( volume >= 10.0 )
      goto LABEL_6;
  }
  v2 = volume;
LABEL_6:
  UFG::Radio::s_volume = v2;
  UFG::AudioEntity::SetRtpcValue(this, UFG::Radio::sm_radioVolumeRtpcId, v2);
  Instance = UFG::TiDo::GetInstance();
  UFG::TiDo::SetWwiseRtpcValue(Instance, UFG::Radio::sm_radioVolumeRtpcId, UFG::Radio::s_volume, 0xFFFFFFFFFFFFFFFFui64);
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v4, VolumeCarMusic, (int)UFG::Radio::s_volume);
}

// File Line: 1546
// RVA: 0x67D430
void __fastcall UFG::Radio::IncreaseRadioVolume(UFG::Radio *this)
{
  float v1; // xmm2_4

  v1 = UFG::Radio::s_volume;
  if ( UFG::Radio::s_volume == 0.0 )
  {
    UFG::Radio::PlayClick(this);
    v1 = UFG::Radio::s_volume;
  }
  UFG::Radio::SetRadioVolume(this, UFG::Radio::s_volumeRate + v1);
}

// File Line: 1558
// RVA: 0x676250
void __fastcall UFG::Radio::DecreaseRadioVolume(UFG::Radio *this)
{
  float v1; // xmm6_4

  v1 = UFG::Radio::s_volume;
  UFG::Radio::SetRadioVolume(this, UFG::Radio::s_volume - UFG::Radio::s_volumeRate);
  if ( v1 > 0.0 && UFG::Radio::s_volume == 0.0 )
    UFG::Radio::PlayClick(this);
}

// File Line: 1572
// RVA: 0x68DE80
void __fastcall UFG::Radio::TurnOffRadio(UFG::Radio *this, bool playClick)
{
  UFG::UIHKScreenHud *Instance; // rax

  if ( (*((_BYTE *)this + 344) & 4) == 0 )
  {
    UFG::AudioEntity::SetWwiseState((UFG::TiDo *)this, ms_player_radio.mUID, radio_off.mUID);
    UFG::GameStatAction::Radio::Stop(this->m_curStation);
    *((_BYTE *)this + 344) = *((_BYTE *)this + 344) & 0x7A | 0x84;
    ((void (__fastcall *)(UFG::Radio *, __int64))this->vfptr[1].StopAndForgetAllEvents)(this, 500i64);
    Instance = UFG::UIHKScreenHud::getInstance();
    if ( Instance )
      UFG::UIHKRadioStationWidget::OnRadioTurnedOff(&Instance->RadioStationWidget);
  }
}

// File Line: 1599
// RVA: 0x68E9D0
void __fastcall UFG::Radio::TurnOnRadio(UFG::Radio *this)
{
  UFG::GameStatTracker *v2; // rax
  int Stat; // eax
  float m_timeSinceRadioStopped; // xmm1_4

  if ( (*((_BYTE *)this + 344) & 4) != 0 )
  {
    UFG::AudioEntity::SetWwiseState((UFG::TiDo *)this, ms_player_radio.mUID, radio_on.mUID);
    UFG::GameStatAction::Radio::Start();
    v2 = UFG::GameStatTracker::Instance();
    Stat = UFG::GameStatTracker::GetStat(v2, VolumeCarMusic);
    UFG::Radio::SetRadioVolume(this, (float)Stat);
    m_timeSinceRadioStopped = this->m_timeSinceRadioStopped;
    *((_BYTE *)this + 344) = *((_BYTE *)this + 344) & 0xFA | 1;
    UFG::Radio::AdvanceAllStations(this, m_timeSinceRadioStopped);
    ((void (__fastcall *)(UFG::Radio *, _QWORD))this->vfptr[1].DestroyAllEvents)(this, 0i64);
  }
}

// File Line: 1624
// RVA: 0x686D20
void __fastcall UFG::Radio::PlayClick(UFG::Radio *this)
{
  unsigned int v2; // eax

  if ( (_S18_7 & 1) != 0 )
  {
    v2 = uiClickId_0;
  }
  else
  {
    _S18_7 |= 1u;
    v2 = UFG::TiDo::CalcWwiseUid("play_ui_click");
    uiClickId_0 = v2;
  }
  UFG::AudioEntity::CreateAndPlayEvent(this, v2, 0i64, 0, 0i64);
}

// File Line: 1631
// RVA: 0x687500
bool __fastcall UFG::Radio::PlayerInVehicle(UFG::Radio *this)
{
  signed __int16 m_Flags; // dx
  unsigned int v3; // edx
  bool v4; // zf

  if ( !LocalPlayer )
    return 0;
  m_Flags = LocalPlayer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    return LocalPlayer->m_Components.p[44].m_pComponent != 0i64;
  if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 )
  {
    v3 = UFG::CharacterOccupantComponent::_TypeUID;
    return UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, v3) != 0i64;
  }
  v4 = (m_Flags & 0x1000) == 0;
  v3 = UFG::CharacterOccupantComponent::_TypeUID;
  if ( !v4 )
    return UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, v3) != 0i64;
  return UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::CharacterOccupantComponent::_TypeUID) != 0i64;
}

// File Line: 1646
// RVA: 0x669F10
void __fastcall UFG::RadioFullyControlled::RadioFullyControlled(UFG::RadioFullyControlled *this)
{
  UFG::Radio::Radio(this);
  this->vfptr = (UFG::AudioEntityVtbl *)&UFG::RadioFullyControlled::`vftable;
  this->m_pVehAudComponent = 0i64;
  UFG::Radio::SetupParams(this, -1);
}

// File Line: 1674
// RVA: 0x67D470
void __fastcall UFG::RadioFullyControlled::Init(UFG::RadioFullyControlled *this, UFG::qSymbol *name)
{
  UFG::qSymbolUC *v3; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+18h] BYREF

  v3 = (UFG::qSymbolUC *)UFG::qSymbol::create_from_string(&result, "Player_Radio");
  UFG::AudioEntity::Init(this, v3, &UFG::qMatrix44::msIdentity);
}

// File Line: 1691
// RVA: 0x681EC0
void __fastcall UFG::RadioFullyControlled::NextTrack(UFG::RadioFullyControlled *this)
{
  __int64 v2; // rdx

  if ( !((unsigned __int8 (__fastcall *)(UFG::RadioFullyControlled *, __int64))this->vfptr[1].StopAndForgetAllEvents)(
          this,
          500i64) )
  {
    LOBYTE(v2) = 1;
    ((void (__fastcall *)(UFG::RadioFullyControlled *, __int64))this->vfptr[1].DestroyAllEvents)(this, v2);
  }
}

// File Line: 1702
// RVA: 0x68EA60
void __fastcall UFG::RadioFullyControlled::TurnOnRadio(UFG::RadioFullyControlled *this)
{
  UFG::RadioStation *m_curStation; // rbx

  if ( this->m_radioType == eRadioType_Scanner )
  {
    UFG::Radio::TurnOnRadio(this);
    m_curStation = this->m_curStation;
    UFG::Radio::NextStation(this, 0);
    UFG::RadioFullyControlled::SetupScannerAndRadio(this, m_curStation, this->m_curStation);
  }
  if ( this->m_radioType == eRadioType_Radio )
    UFG::Radio::TurnOnRadio(this);
  if ( this->m_radioType == eRadioType_RadioWithScanner )
  {
    UFG::Radio::TurnOnRadio(this);
    UFG::RadioFullyControlled::SetupScannerAndRadio(this, this->m_curStation, this->m_curStation);
  }
  *((_BYTE *)&this->UFG::Radio + 344) = *((_BYTE *)&this->UFG::Radio + 344) & 0xFA | 1;
}

// File Line: 1725
// RVA: 0x68DEF0
void __fastcall UFG::RadioFullyControlled::TurnOffRadio(UFG::RadioFullyControlled *this, bool playClick)
{
  if ( this->m_radioType == eRadioType_Scanner )
  {
    if ( UFG::PoliceScannerAudio::IsOwnedBy(&UFG::PoliceScannerAudio::sm_Instance, this) )
    {
      UFG::PoliceScannerAudio::DetachFromAudioEntity(&UFG::PoliceScannerAudio::sm_Instance, this);
      UFG::PoliceScannerAudio::Enable(&UFG::PoliceScannerAudio::sm_Instance, 0);
    }
    UFG::Radio::TurnOffRadio(this, 1);
  }
  if ( this->m_radioType == eRadioType_Radio )
    UFG::Radio::TurnOffRadio(this, 1);
  if ( this->m_radioType == eRadioType_RadioWithScanner )
  {
    if ( UFG::PoliceScannerAudio::IsOwnedBy(&UFG::PoliceScannerAudio::sm_Instance, this) )
    {
      UFG::PoliceScannerAudio::DetachFromAudioEntity(&UFG::PoliceScannerAudio::sm_Instance, this);
      UFG::PoliceScannerAudio::Enable(&UFG::PoliceScannerAudio::sm_Instance, 0);
    }
    else
    {
      UFG::Radio::TurnOffRadio(this, 1);
    }
  }
  *((_BYTE *)&this->UFG::Radio + 344) &= ~1u;
  *((_BYTE *)&this->UFG::Radio + 344) |= 4u;
}

// File Line: 1760
// RVA: 0x68BAD0
void __fastcall UFG::RadioFullyControlled::SetupScannerAndRadio(
        UFG::RadioFullyControlled *this,
        UFG::RadioStation *prevStation,
        UFG::RadioStation *curStation)
{
  bool m_bIsCopScannerStation; // al

  m_bIsCopScannerStation = curStation->m_bIsCopScannerStation;
  if ( prevStation )
  {
    if ( !m_bIsCopScannerStation )
      goto LABEL_9;
    if ( !prevStation->m_bIsCopScannerStation )
      goto LABEL_8;
  }
  else if ( m_bIsCopScannerStation )
  {
LABEL_8:
    UFG::PoliceScannerAudio::AttachToAudioEntity(&UFG::PoliceScannerAudio::sm_Instance, this);
    UFG::PoliceScannerAudio::Enable(&UFG::PoliceScannerAudio::sm_Instance, 1);
    goto LABEL_9;
  }
  if ( m_bIsCopScannerStation && !UFG::PoliceScannerAudio::IsOwnedBy(&UFG::PoliceScannerAudio::sm_Instance, this) )
    goto LABEL_8;
LABEL_9:
  if ( !prevStation )
  {
    if ( curStation->m_bIsCopScannerStation )
      return;
    goto LABEL_14;
  }
  if ( !curStation->m_bIsCopScannerStation && prevStation->m_bIsCopScannerStation )
  {
LABEL_14:
    if ( UFG::PoliceScannerAudio::IsOwnedBy(&UFG::PoliceScannerAudio::sm_Instance, this) )
    {
      UFG::PoliceScannerAudio::DetachFromAudioEntity(&UFG::PoliceScannerAudio::sm_Instance, this);
      UFG::PoliceScannerAudio::Enable(&UFG::PoliceScannerAudio::sm_Instance, 0);
    }
  }
}

// File Line: 1785
// RVA: 0x681E80
void __fastcall UFG::RadioFullyControlled::NextStation(UFG::RadioFullyControlled *this, bool displayStationId)
{
  UFG::RadioStation *m_curStation; // rbx

  m_curStation = this->m_curStation;
  UFG::Radio::NextStation(this, displayStationId);
  UFG::RadioFullyControlled::SetupScannerAndRadio(this, m_curStation, this->m_curStation);
}

// File Line: 1794
// RVA: 0x687710
void __fastcall UFG::RadioFullyControlled::PrevStation(UFG::RadioFullyControlled *this, bool displayStationId)
{
  UFG::RadioStation *m_curStation; // rbx

  m_curStation = this->m_curStation;
  UFG::Radio::PrevStation(this, displayStationId);
  UFG::RadioFullyControlled::SetupScannerAndRadio(this, m_curStation, this->m_curStation);
}

// File Line: 1803
// RVA: 0x670AB0
void __fastcall UFG::RadioFullyControlled::AudioEntityUpdate(UFG::RadioFullyControlled *this, float delta_sec)
{
  __int64 v2; // rdx
  UFG::VehicleAudioComponent *m_pVehAudComponent; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  float x; // eax
  UFG::VehicleAudioComponent *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm2_4

  if ( !this->m_pVehAudComponent && (*((_BYTE *)&this->UFG::Radio + 344) & 2) != 0 )
  {
    LOBYTE(v2) = 1;
    ((void (__fastcall *)(UFG::RadioFullyControlled *, __int64))this->vfptr[1].CountNumPlayingEvents)(this, v2);
  }
  m_pVehAudComponent = this->m_pVehAudComponent;
  if ( m_pVehAudComponent )
  {
    y = m_pVehAudComponent->m_WorldMatrix.v3.y;
    z = m_pVehAudComponent->m_WorldMatrix.v3.z;
    x = m_pVehAudComponent->m_WorldMatrix.v3.x;
    this->m_WorldMatrix.v3.w = 1.0;
    this->m_WorldMatrix.v3.x = x;
    this->m_WorldMatrix.v3.y = y;
    this->m_WorldMatrix.v3.z = z;
    UFG::AudioEntity::ForcePositionUpdate(this);
  }
  if ( this->m_pVehAudComponent && UFG::PoliceScannerAudio::IsOwnedBy(&UFG::PoliceScannerAudio::sm_Instance, this) )
  {
    v9 = this->m_pVehAudComponent;
    v10 = v9->m_WorldMatrix.v3.y;
    v11 = v9->m_WorldMatrix.v3.z;
    unk_14242F140 = LODWORD(v9->m_WorldMatrix.v3.x);
    unk_14242F144 = LODWORD(v10);
    unk_14242F14C = (_DWORD)FLOAT_1_0;
    unk_14242F148 = LODWORD(v11);
    UFG::AudioEntity::ForcePositionUpdate(&UFG::PoliceScannerAudio::sm_Instance);
  }
  UFG::AudioEntity::AudioEntityUpdate(this, delta_sec);
}

// File Line: 1894
// RVA: 0x6743D0
void __fastcall UFG::Radio::ClearAllPlaylists(UFG::Radio *this)
{
  UFG::RadioStation *i; // rbx
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *j; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *mPrev; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *mNext; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v5; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v6; // rcx

  for ( i = (UFG::RadioStation *)&UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
        i != (UFG::RadioStation *)((char *)&UFG::Radio::sm_stationList - 8);
        i = (UFG::RadioStation *)&i->mNext[-1].mNext )
  {
    if ( i )
    {
      UFG::RadioStation::AddCurrentlyPlayingToRecentlyPlayed(i);
      for ( j = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)i->m_playList.mNode.mNext;
            j != &i->m_playList;
            j = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)i->m_playList.mNode.mNext )
      {
        mPrev = j->mNode.mPrev;
        mNext = j->mNode.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        j->mNode.mPrev = &j->mNode;
        j->mNode.mNext = &j->mNode;
        v5 = j->mNode.mPrev;
        v6 = j->mNode.mNext;
        v5->mNext = v6;
        v6->mPrev = v5;
        j->mNode.mPrev = &j->mNode;
        j->mNode.mNext = &j->mNode;
        operator delete[](j);
      }
    }
  }
}

// File Line: 1907
// RVA: 0x67A220
char *__fastcall UFG::RadioFullyControlled::GetCurrentlyPlayingSong(UFG::RadioFullyControlled *this)
{
  UFG::RadioStation *m_curStation; // rax

  m_curStation = this->m_curStation;
  if ( m_curStation->m_currentlyPlaying )
    return m_curStation->m_currentlyPlayingAssetName.mData;
  else
    return &customCaption;
}

