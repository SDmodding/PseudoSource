// File Line: 27
// RVA: 0x1583210
__int64 dynamic_initializer_for__ms_player_radio__()
{
  ms_player_radio.mUID = UFG::qWiseSymbolUIDFromString("ms_player_radio", 0x811C9DC5);
  _((AMD_HD3D *)ms_player_radio.mUID);
  return atexit(dynamic_atexit_destructor_for__ms_player_radio__);
}

// File Line: 28
// RVA: 0x1585390
__int64 dynamic_initializer_for__radio_on__()
{
  radio_on.mUID = UFG::qWiseSymbolUIDFromString("radio_on", 0x811C9DC5);
  _((AMD_HD3D *)radio_on.mUID);
  return atexit(dynamic_atexit_destructor_for__radio_on__);
}

// File Line: 29
// RVA: 0x1585340
__int64 dynamic_initializer_for__radio_off__()
{
  radio_off.mUID = UFG::qWiseSymbolUIDFromString("radio_off", 0x811C9DC5);
  _((AMD_HD3D *)radio_off.mUID);
  return atexit(dynamic_atexit_destructor_for__radio_off__);
}

// File Line: 36
// RVA: 0x157B960
__int64 dynamic_initializer_for__UFG::Radio::sm_stationList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::Radio::sm_stationList__);
}

// File Line: 46
// RVA: 0x667CF0
void __fastcall UFG::DJAsset::DJAsset(UFG::DJAsset *this, UFG::RadioStation *station, char index, UFG::qString *trackNames, unsigned int numTracks)
{
  UFG::qString *v5; // rbp
  unsigned int v6; // ebx
  UFG::RadioStation *v7; // rsi
  UFG::DJAsset *v8; // r14
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v9; // rax
  unsigned int v10; // er15
  _QWORD *v11; // rdi
  unsigned int *v12; // rbx
  __int64 v13; // rbp
  signed __int64 v14; // rax
  UFG::qString v15; // [rsp+28h] [rbp-A0h]
  UFG::qString v16; // [rsp+50h] [rbp-78h]
  UFG::qString v17; // [rsp+78h] [rbp-50h]

  v5 = trackNames;
  v6 = (unsigned __int8)index;
  v7 = station;
  v8 = this;
  v9 = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)&this->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::RadioStationAsset::`vftable';
  this->m_index = index;
  *(_QWORD *)&this->m_type = 1i64;
  *((_BYTE *)&this->0 + 36) |= 1u;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::DJAsset::`vftable';
  UFG::qString::qString(&v17);
  v10 = v6;
  UFG::qString::Format(&v17, "play_station_%02u_dj_%01ua", v7->m_id, v6, -2i64);
  v8->m_beforeTracksEvent = UFG::TiDo::CalcWwiseUid(v17.mData);
  UFG::qString::qString(&v16);
  UFG::qString::Format(&v16, "play_station_%02u_dj_%0ub", v7->m_id, v6);
  v8->m_afterTracksEvent = UFG::TiDo::CalcWwiseUid(v16.mData);
  v11 = v8->m_trackAssets;
  v8->m_trackAssets[0] = 0i64;
  v8->m_trackAssets[1] = 0i64;
  v8->m_trackAssets[2] = 0i64;
  if ( numTracks )
  {
    v12 = &v5->mStringHash32;
    v13 = numTracks;
    do
    {
      if ( *v12 == -1 )
        *v12 = UFG::qStringHash32(*((const char **)v12 - 1), 0xFFFFFFFF);
      v14 = (signed __int64)&v7->m_assets.mNode.mNext[-1].mNext;
      if ( v7->m_assets.mNode.mNext != (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)8 )
      {
        while ( (UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **)v14 != &v7->m_programs.mNode.mNext )
        {
          if ( !*(_DWORD *)(v14 + 28) && *v12 == *(_DWORD *)(v14 + 40) )
            goto LABEL_11;
          v14 = *(_QWORD *)(v14 + 16) - 8i64;
          if ( !v14 )
            break;
        }
      }
      UFG::qString::operator!=((UFG::qString *)(v12 - 8), &customWorldMapCaption);
      v14 = 0i64;
LABEL_11:
      *v11 = v14;
      ++v11;
      v12 += 10;
      --v13;
    }
    while ( v13 );
  }
  UFG::qString::qString(&v15);
  UFG::qString::Format(&v15, "play_station_%02u_dj_%02u", v7->m_id, v10);
  v8->m_assetId = UFG::TiDo::CalcWwiseUid(v15.mData);
  UFG::qString::~qString(&v15);
  UFG::qString::~qString(&v16);
  UFG::qString::~qString(&v17);
}

// File Line: 80
// RVA: 0x66A6B0
void __fastcall UFG::TrackAsset::TrackAsset(UFG::TrackAsset *this, UFG::RadioStation *station, char index, const char *artistName, const char *trackName)
{
  const char *v5; // rbp
  unsigned int v6; // edi
  UFG::RadioStation *v7; // rbx
  UFG::TrackAsset *v8; // rsi
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v9; // rax
  int v10; // eax
  char *v11; // rax
  int v12; // eax
  char *v13; // rax
  UFG::qString v14; // [rsp+28h] [rbp-30h]

  v5 = artistName;
  v6 = (unsigned __int8)index;
  v7 = station;
  v8 = this;
  v9 = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)&this->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::RadioStationAsset::`vftable';
  this->m_index = index;
  *(_QWORD *)&this->m_type = 0i64;
  *((_BYTE *)&v8->0 + 36) |= 1u;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::TrackAsset::`vftable';
  this->m_trackUID = -1;
  this->m_trackName = 0i64;
  this->m_artistName = 0i64;
  UFG::qString::qString(&v14);
  UFG::qString::Format(&v14, "play_station_%02u_track_%02u", v7->m_id, v6, -2i64);
  v8->m_assetId = UFG::TiDo::CalcWwiseUid(v14.mData);
  if ( v5 && *v5 )
  {
    v10 = UFG::qStringLength(v5);
    v11 = (char *)UFG::qMalloc(v10 + 1, "RadioStation", 0i64);
    v8->m_artistName = v11;
    UFG::qStringCopy(v11, 0x7FFFFFFF, v5, -1);
  }
  if ( trackName && *trackName )
  {
    v12 = UFG::qStringLength(trackName);
    v13 = (char *)UFG::qMalloc(v12 + 1, "RadioStation", 0i64);
    v8->m_trackName = v13;
    UFG::qStringCopy(v13, 0x7FFFFFFF, trackName, -1);
    v8->m_trackUID = UFG::qStringHash32(trackName, 0xFFFFFFFF);
  }
  UFG::qString::~qString(&v14);
}

// File Line: 105
// RVA: 0x666CE0
void __fastcall UFG::AdAsset::AdAsset(UFG::AdAsset *this, UFG::RadioStation *station, char index)
{
  unsigned int v3; // edi
  UFG::RadioStation *v4; // rbx
  UFG::AdAsset *v5; // rsi
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v6; // rax
  UFG::qString v7; // [rsp+28h] [rbp-30h]

  v3 = (unsigned __int8)index;
  v4 = station;
  v5 = this;
  v6 = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)&this->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::RadioStationAsset::`vftable';
  this->m_index = index;
  *(_QWORD *)&this->m_type = 2i64;
  *((_BYTE *)&this->0 + 36) |= 1u;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::AdAsset::`vftable';
  UFG::qString::qString(&v7);
  UFG::qString::Format(&v7, "play_station_%02u_ad_%02u", v4->m_id, v3, -2i64);
  v5->m_assetId = UFG::TiDo::CalcWwiseUid(v7.mData);
  UFG::qString::~qString(&v7);
}

// File Line: 116
// RVA: 0x6699A0
void __fastcall UFG::IdentAsset::IdentAsset(UFG::IdentAsset *this, UFG::RadioStation *station)
{
  UFG::RadioStation *v2; // rbx
  UFG::IdentAsset *v3; // rdi
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v4; // rax
  UFG::qString v5; // [rsp+28h] [rbp-30h]

  v2 = station;
  v3 = this;
  v4 = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)&this->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::RadioStationAsset::`vftable';
  this->m_index = 0;
  *(_QWORD *)&this->m_type = 3i64;
  *((_BYTE *)&this->0 + 36) |= 1u;
  this->vfptr = (UFG::RadioStationAssetVtbl *)&UFG::IdentAsset::`vftable';
  UFG::qString::qString(&v5);
  UFG::qString::Format(&v5, "play_station_%02u_ident", v2->m_id);
  v3->m_assetId = UFG::TiDo::CalcWwiseUid(v5.mData);
  UFG::qString::~qString(&v5);
}

// File Line: 132
// RVA: 0x669F60
void __fastcall UFG::RadioStation::RadioStation(UFG::RadioStation *this, const char *name, unsigned int id, unsigned int consecTracks, float chanceTrack, float chanceDj, float chanceAd, bool copScannerStation)
{
  unsigned int v8; // esi
  unsigned int v9; // edi
  const char *v10; // rbx
  UFG::RadioStation *v11; // rbp
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v12; // rax
  UFG::qList<UFG::RadioStationProgram,UFG::RadioStationProgram,1,0> *v13; // ST28_8
  UFG::qList<UFG::RadioStationAsset,UFG::RadioStationAsset,1,0> *v14; // ST28_8
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *v15; // r14
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *v16; // r15
  signed __int64 i; // rax
  _QWORD *v18; // rdx
  __int64 v19; // rcx
  _QWORD *v20; // rax
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *j; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v22; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v23; // rax
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *k; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v25; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v26; // rax
  UFG::qWiseSymbol *v27; // rax
  unsigned int *v28; // rax
  signed __int64 v29; // rdx
  UFG::qString result; // [rsp+30h] [rbp-58h]

  v8 = consecTracks;
  v9 = id;
  v10 = name;
  v11 = this;
  v12 = (UFG::qNode<UFG::RadioStation,UFG::RadioStation> *)&this->mPrev;
  v12->mPrev = v12;
  v12->mNext = v12;
  this->vfptr = (UFG::RadioStationVtbl *)&UFG::RadioStation::`vftable';
  UFG::qString::qString(&this->m_textureName);
  UFG::qString::qString(&v11->m_texturePack);
  UFG::qString::qString(&v11->m_currentlyPlayingAssetName);
  v11->m_bankId.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v13 = &v11->m_programs;
  v13->mNode.mPrev = &v13->mNode;
  v13->mNode.mNext = &v13->mNode;
  v14 = &v11->m_assets;
  v14->mNode.mPrev = &v14->mNode;
  v14->mNode.mNext = &v14->mNode;
  v15 = &v11->m_playList;
  v15->mNode.mPrev = &v15->mNode;
  v15->mNode.mNext = &v15->mNode;
  v16 = &v11->m_prevPlayed;
  v16->mNode.mPrev = &v16->mNode;
  v16->mNode.mNext = &v16->mNode;
  UFG::qSPrintf(v11->m_name, "%s", v10);
  v11->m_id = v9;
  v11->m_numConsecutiveTracks = v8;
  v11->m_percentTrack = chanceTrack;
  v11->m_percentDj = chanceDj;
  v11->m_percentAd = chanceAd;
  UFG::qString::Set(&v11->m_currentlyPlayingAssetName, &customWorldMapCaption);
  v11->m_currentlyPlaying = 0i64;
  v11->m_numRecentlyPlayed = 0;
  for ( i = (signed __int64)&v11->m_assets.mNode.mNext[-1].mNext;
        (UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **)i != &v11->m_programs.mNode.mNext;
        i = (signed __int64)&v11->m_assets.mNode.mNext[-1].mNext )
  {
    v18 = (_QWORD *)(i + 8);
    v19 = *(_QWORD *)(i + 8);
    v20 = *(_QWORD **)(i + 16);
    *(_QWORD *)(v19 + 8) = v20;
    *v20 = v19;
    *v18 = v18;
    v18[1] = v18;
  }
  for ( j = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)v11->m_playList.mNode.mNext;
        j != v15;
        j = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)v11->m_playList.mNode.mNext )
  {
    v22 = j->mNode.mPrev;
    v23 = j->mNode.mNext;
    v22->mNext = v23;
    v23->mPrev = v22;
    j->mNode.mPrev = &j->mNode;
    j->mNode.mNext = &j->mNode;
  }
  for ( k = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)v11->m_prevPlayed.mNode.mNext;
        k != v16;
        k = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)v11->m_prevPlayed.mNode.mNext )
  {
    v25 = k->mNode.mPrev;
    v26 = k->mNode.mNext;
    v25->mNext = v26;
    v26->mPrev = v25;
    k->mNode.mPrev = &k->mNode;
    k->mNode.mNext = &k->mNode;
  }
  *(_QWORD *)&v11->m_timeSinceStarted = 0i64;
  v11->m_currentTrackTimer = 0.0;
  UFG::qString::FormatEx(&result, "mus_radio_station_%d", v11->m_id);
  v27 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&chanceTrack, result.mData);
  UFG::qWiseSymbol::operator=(&v11->m_bankId, v27);
  _((AMD_HD3D *)LODWORD(chanceTrack));
  v11->m_bIsRaceStation = 0;
  v11->m_bIsCopScannerStation = copScannerStation;
  v28 = v11->m_firstAssetIndex;
  v29 = 4i64;
  do
  {
    *(v28 - 4) = 0;
    *v28 = 0;
    ++v28;
    --v29;
  }
  while ( v29 );
  UFG::qString::Set(&v11->m_currentlyPlayingAssetName, " ");
  UFG::qString::~qString(&result);
}

// File Line: 170
// RVA: 0x66CD60
void __fastcall UFG::RadioStation::~RadioStation(UFG::RadioStation *this)
{
  UFG::RadioStation *v1; // rsi
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *v2; // r15
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *v3; // r14
  UFG::qList<UFG::RadioStationAsset,UFG::RadioStationAsset,1,0> *v4; // rdi
  signed __int64 i; // rax
  _QWORD *v6; // rdx
  __int64 v7; // rcx
  _QWORD *v8; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v9; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v10; // rax
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v11; // rcx
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v12; // rax
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v13; // rcx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v14; // rax
  UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> *v15; // rcx
  UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> *v16; // rax
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v17; // rdx
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v18; // rcx
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v19; // rax

  v1 = this;
  this->vfptr = (UFG::RadioStationVtbl *)&UFG::RadioStation::`vftable';
  v2 = (UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_playList;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&this->m_playList);
  v3 = &v1->m_prevPlayed;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->m_prevPlayed);
  v4 = &v1->m_assets;
  for ( i = (signed __int64)&v1->m_assets.mNode.mNext[-1].mNext;
        (UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **)i != &v1->m_programs.mNode.mNext;
        i = (signed __int64)&v1->m_assets.mNode.mNext[-1].mNext )
  {
    v6 = (_QWORD *)(i + 8);
    v7 = *(_QWORD *)(i + 8);
    v8 = *(_QWORD **)(i + 16);
    *(_QWORD *)(v7 + 8) = v8;
    *v8 = v7;
    *v6 = v6;
    v6[1] = v6;
    if ( v6 != (_QWORD *)8 )
      (*(void (__fastcall **)(_QWORD *, signed __int64))*(v6 - 1))(v6 - 1, 1i64);
  }
  UFG::qList<UFG::RadioStationProgram,UFG::RadioStationProgram,1,0>::DeleteNodes(&v1->m_programs);
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v1->m_prevPlayed);
  v9 = v3->mNode.mPrev;
  v10 = v1->m_prevPlayed.mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v3->mNode.mPrev = &v3->mNode;
  v1->m_prevPlayed.mNode.mNext = &v1->m_prevPlayed.mNode;
  UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes(v2);
  v11 = v2->mNode.mPrev;
  v12 = v2->mNode.mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->m_assets);
  v13 = v4->mNode.mPrev;
  v14 = v1->m_assets.mNode.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v4->mNode.mPrev = &v4->mNode;
  v1->m_assets.mNode.mNext = &v1->m_assets.mNode;
  UFG::qList<UFG::RadioStationProgram,UFG::RadioStationProgram,1,0>::DeleteNodes(&v1->m_programs);
  v15 = v1->m_programs.mNode.mPrev;
  v16 = v1->m_programs.mNode.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v1->m_programs.mNode.mPrev = &v1->m_programs.mNode;
  v1->m_programs.mNode.mNext = &v1->m_programs.mNode;
  _((AMD_HD3D *)v1->m_bankId.mUID);
  UFG::qString::~qString(&v1->m_currentlyPlayingAssetName);
  UFG::qString::~qString(&v1->m_texturePack);
  UFG::qString::~qString(&v1->m_textureName);
  v17 = (UFG::qNode<UFG::RadioStation,UFG::RadioStation> *)&v1->mPrev;
  v18 = v1->mPrev;
  v19 = v1->mNext;
  v18->mNext = v19;
  v19->mPrev = v18;
  v17->mPrev = v17;
  v17->mNext = v17;
}

// File Line: 183
// RVA: 0x67F250
char __fastcall UFG::RadioStation::IsInCurrentProgram(UFG::RadioStation *this, unsigned int index)
{
  char v2; // di
  UFG::RadioStation *v3; // rbx
  UFG::TimeOfDayManager *v4; // rax
  int v5; // er8
  float v6; // xmm0_4
  UFG::RadioStation *v7; // rax
  float v8; // xmm0_4
  UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> *v9; // rcx
  float v10; // xmm2_4
  float v11; // xmm1_4

  v2 = index;
  v3 = this;
  v4 = UFG::TimeOfDayManager::GetInstance();
  v5 = 0;
  v6 = v4->m_SecondsSinceMidnight;
  v7 = (UFG::RadioStation *)v3->m_programs.mNode.mNext;
  v8 = v6 * 0.00027777778;
  if ( v7 == (UFG::RadioStation *)&v3->m_programs )
    return 1;
  do
  {
    v7 = (UFG::RadioStation *)v7->mPrev;
    ++v5;
  }
  while ( v7 != (UFG::RadioStation *)&v3->m_programs );
  if ( !v5 )
    return 1;
  v9 = v3->m_programs.mNode.mNext;
  if ( !v9 )
    return 0;
  while ( 1 )
  {
    v10 = (float)BYTE3(v9[1].mPrev);
    v11 = (float)BYTE2(v9[1].mPrev);
    if ( v10 <= v11 )
      break;
    if ( v8 >= v11 && v8 <= v10 )
      goto LABEL_8;
LABEL_14:
    v9 = v9->mNext;
    if ( !v9 )
      return 0;
  }
  if ( v8 <= v11 && v8 > v10 && v8 < v11 )
    goto LABEL_14;
LABEL_8:
  if ( v2 < (signed int)LOBYTE(v9[1].mPrev) || v2 > (signed int)BYTE1(v9[1].mPrev) )
    return 0;
  return 1;
}

// File Line: 233
// RVA: 0x67AA80
__int64 __fastcall UFG::RadioStation::GetNextTrack(UFG::RadioStation *this)
{
  UFG::RadioStation *v1; // rbp
  char **v2; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v3; // rbx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v4; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v5; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v6; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v7; // rax
  __int64 v8; // r13
  float v9; // xmm0_4
  int v10; // edx
  UFG::DJAsset *v11; // rbx
  signed __int64 v12; // rax
  signed __int64 i; // r14
  signed int j; // eax
  int k; // er12
  int v16; // ecx
  signed __int64 l; // rax
  unsigned int v18; // er15
  UFG::RadioStation *v19; // rdi
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v20; // rcx
  UFG::RadioStationAsset *v21; // rdx
  UFG::RadioStation *v22; // rcx
  int v23; // esi
  signed __int64 v24; // rdi
  int v25; // ecx
  signed __int64 m; // rax
  int n; // edx
  int v28; // ecx
  signed __int64 ii; // rax

  v1 = this;
  v2 = (char **)&this->m_playList;
  while ( 2 )
  {
    if ( v2[1] != (char *)v2 )
    {
      v3 = v1->m_playList.mNode.mNext;
      v4 = v3->mPrev;
      v5 = v3->mNext;
      v4->mNext = v5;
      v5->mPrev = v4;
      v3->mPrev = v3;
      v3->mNext = v3;
      UFG::RadioStation::SetCurrentlyPlaying(v1, (UFG::RadioStationAsset *)v3[1].mPrev);
      v6 = v3->mPrev;
      v7 = v3->mNext;
      v6->mNext = v7;
      v7->mPrev = v6;
      v3->mPrev = v3;
      v3->mNext = v3;
      operator delete[](v3);
      if ( v1->m_currentlyPlaying )
        return ((__int64 (*)(void))v1->m_currentlyPlaying->vfptr->GetActiveAssetId)();
    }
    v8 = (signed int)UFG::RadioStation::DetermineAssetType(v1);
    v9 = UFG::qRandom((float)(signed int)v1->m_assetCount[v8], &UFG::qDefaultSeed)
       + (float)(signed int)v1->m_firstAssetIndex[v8];
    v10 = 0;
    v11 = (UFG::DJAsset *)&v1->m_assets.mNode.mNext[-1].mNext;
    v12 = (signed __int64)v11;
    for ( i = (signed __int64)&v1->m_programs.mNode.mNext; v12 != i; v12 = *(_QWORD *)(v12 + 16) - 8i64 )
      ++v10;
    if ( v9 <= 0.0 )
      v9 = 0.0;
    if ( v9 >= (float)(v10 - 1) )
      v9 = (float)(v10 - 1);
    for ( j = (signed int)v9; j > 0; v11 = (UFG::DJAsset *)&v11->mNext[-1].mNext )
    {
      if ( v11 == (UFG::DJAsset *)i )
        break;
      --j;
    }
    for ( k = 0; ; ++k )
    {
      v16 = 0;
      for ( l = (signed __int64)&v1->m_assets.mNode.mNext[-1].mNext; l != i; l = *(_QWORD *)(l + 16) - 8i64 )
        ++v16;
      if ( k >= v16 )
      {
        v23 = 0;
        v24 = (signed __int64)&v1->m_programs.mNode.mNext;
        while ( 1 )
        {
          v25 = 0;
          for ( m = (signed __int64)&v1->m_assets.mNode.mNext[-1].mNext; m != v24; m = *(_QWORD *)(m + 16) - 8i64 )
            ++v25;
          if ( v23 >= v25 )
            break;
          if ( v11->m_type == (_DWORD)v8 && UFG::RadioStation::IsInCurrentProgram(v1, (unsigned __int8)v11->m_index) )
            goto LABEL_45;
          v11 = (UFG::DJAsset *)&v11->mNext[-1].mNext;
          if ( v11 == (UFG::DJAsset *)&v1->m_programs.mNode.mNext )
            v11 = (UFG::DJAsset *)&v11->mNext[-1].mNext;
          ++v23;
        }
        for ( n = 0; ; ++n )
        {
          v28 = 0;
          for ( ii = (signed __int64)&v1->m_assets.mNode.mNext[-1].mNext; ii != v24; ii = *(_QWORD *)(ii + 16) - 8i64 )
            ++v28;
          if ( n >= v28 || v11->m_type == (_DWORD)v8 )
            break;
          v11 = (UFG::DJAsset *)&v11->mNext[-1].mNext;
          if ( v11 == (UFG::DJAsset *)&v1->m_programs.mNode.mNext )
            v11 = (UFG::DJAsset *)&v11->mNext[-1].mNext;
        }
LABEL_45:
        v21 = (UFG::RadioStationAsset *)&v11->vfptr;
        v22 = v1;
        goto LABEL_46;
      }
      v18 = v11->vfptr->GetActiveAssetId((UFG::RadioStationAsset *)&v11->vfptr);
      v19 = (UFG::RadioStation *)v1->m_prevPlayed.mNode.mNext;
      if ( v19 == (UFG::RadioStation *)&v1->m_prevPlayed )
        break;
      while ( 1 )
      {
        v20 = v19->mNext;
        if ( v20 )
        {
          if ( ((unsigned int (__cdecl *)(UFG::qNode<UFG::RadioStation,UFG::RadioStation> *))v20->mPrev->mNext)(v20) == v18 )
            break;
        }
        v19 = (UFG::RadioStation *)v19->mPrev;
        if ( v19 == (UFG::RadioStation *)&v1->m_prevPlayed )
          goto LABEL_21;
      }
LABEL_23:
      v11 = (UFG::DJAsset *)&v11->mNext[-1].mNext;
      if ( v11 == (UFG::DJAsset *)&v1->m_programs.mNode.mNext )
        v11 = (UFG::DJAsset *)&v11->mNext[-1].mNext;
    }
LABEL_21:
    if ( v11->m_type != (_DWORD)v8 || !UFG::RadioStation::IsInCurrentProgram(v1, (unsigned __int8)v11->m_index) )
      goto LABEL_23;
    v21 = (UFG::RadioStationAsset *)&v11->vfptr;
    v22 = v1;
    if ( (_DWORD)v8 == 1 )
    {
      UFG::RadioStation::AddDjAssetToPlaylist(v1, v11);
      v2 = (char **)&v1->m_playList;
      continue;
    }
    break;
  }
LABEL_46:
  UFG::RadioStation::SetCurrentlyPlaying(v22, v21);
  return ((__int64 (*)(void))v1->m_currentlyPlaying->vfptr->GetActiveAssetId)();
}

// File Line: 315
// RVA: 0x6767C0
signed __int64 __fastcall UFG::RadioStation::DetermineAssetType(UFG::RadioStation *this)
{
  UFG::RadioStation *v1; // rdi
  signed __int64 result; // rax
  unsigned int v3; // ebx
  float v4; // xmm7_4
  UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **v5; // r9
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **v6; // rax
  int v7; // er8
  int v8; // edx
  int v9; // ecx
  float v10; // xmm6_4
  float v11; // xmm0_4
  signed __int64 v12; // rdx
  int v13; // ecx
  UFG::RadioStation *v14; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v15; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v16; // rdi
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v17; // rcx

  v1 = this;
  if ( !this->m_numRecentlyPlayed )
    return 0i64;
  v3 = 0;
  v4 = 0.0;
  v5 = &this->m_programs.mNode.mNext;
  v6 = &this->m_assets.mNode.mNext[-1].mNext;
  v7 = 0;
  v8 = 0;
  if ( v6 == (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **)&this->m_programs.mNode.mNext )
    goto LABEL_35;
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
  while ( v6 != (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **)v5 );
  if ( v8 )
    v10 = v1->m_percentTrack;
  else
LABEL_35:
    v10 = 0.0;
  if ( v7 )
    v4 = v1->m_percentAd;
  v11 = UFG::qRandom(100.0, &UFG::qDefaultSeed);
  if ( v11 <= v10 )
    return 0i64;
  if ( v11 >= (float)(v4 + v10) )
    return 1i64;
  v12 = (signed __int64)&v1->m_prevPlayed;
  v13 = 0;
  v14 = (UFG::RadioStation *)v1->m_prevPlayed.mNode.mNext;
  if ( v14 == (UFG::RadioStation *)&v1->m_prevPlayed )
    goto LABEL_36;
  do
  {
    v14 = (UFG::RadioStation *)v14->mPrev;
    ++v13;
  }
  while ( v14 != (UFG::RadioStation *)v12 );
  if ( v13 <= 0 )
    goto LABEL_36;
  v15 = v1->m_prevPlayed.mNode.mNext;
  v16 = v15[1].mPrev;
  if ( !v16 )
    goto LABEL_37;
  if ( v15 != (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)v12 )
  {
    do
    {
      v17 = v15[1].mPrev;
      if ( !v17 || HIDWORD(v17[1].mNext) != 2 )
        break;
      if ( ++v3 >= 2 )
        return 0i64;
      v15 = v15->mNext;
    }
    while ( v15 != (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)v12 );
    if ( v3 >= 2 )
      return 0i64;
  }
  if ( UFG::qRandom(100.0, &UFG::qDefaultSeed) >= 50.0 && HIDWORD(v16[1].mNext) != 3 )
LABEL_36:
    result = 3i64;
  else
LABEL_37:
    result = 2i64;
  return result;
}

// File Line: 415
// RVA: 0x66F7F0
void __fastcall UFG::RadioStation::AddDjAssetToPlaylist(UFG::RadioStation *this, UFG::DJAsset *djAsset)
{
  UFG::DJAsset *v2; // r12
  UFG::RadioStation *v3; // rdi
  char v4; // r13
  unsigned int v5; // eax
  UFG::TrackAsset **v6; // r14
  signed __int64 v7; // r15
  int v8; // ebp
  signed __int64 i; // rbx
  UFG::allocator::free_link *v10; // rax
  UFG::allocator::free_link *v11; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v12; // rax
  unsigned int v13; // eax

  v2 = djAsset;
  v3 = this;
  v4 = 1;
  if ( UFG::qRandom(1.0, &UFG::qDefaultSeed) >= 0.5 )
  {
    v2->m_assetId = v2->m_beforeTracksEvent;
    v5 = v2->vfptr->GetActiveAssetId((UFG::RadioStationAsset *)&v2->vfptr);
    UFG::RadioStation::AddToPlaylist(v3, v5, 1);
  }
  else
  {
    v4 = 0;
  }
  v6 = v2->m_trackAssets;
  v7 = 3i64;
  do
  {
    if ( *v6 )
    {
      v8 = ((__int64 (__cdecl *)(UFG::TrackAsset *))(*v6)->vfptr->GetActiveAssetId)(*v6);
      for ( i = (signed __int64)&v3->m_assets.mNode.mNext[-1].mNext;
            (UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **)i != &v3->m_programs.mNode.mNext;
            i = *(_QWORD *)(i + 16) - 8i64 )
      {
        if ( (*(unsigned int (__fastcall **)(signed __int64))(*(_QWORD *)i + 8i64))(i) == v8 )
        {
          *(_BYTE *)(i + 36) |= 1u;
          v10 = UFG::qMalloc(0x18ui64, "PlayList.Asset", 0i64);
          v11 = v10;
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
          v12 = v3->m_playList.mNode.mPrev;
          v12->mNext = (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)v11;
          v11->mNext = (UFG::allocator::free_link *)v12;
          v11[1].mNext = (UFG::allocator::free_link *)&v3->m_playList;
          v3->m_playList.mNode.mPrev = (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)v11;
        }
      }
    }
    ++v6;
    --v7;
  }
  while ( v7 );
  if ( !v4 )
  {
    v2->m_assetId = v2->m_afterTracksEvent;
    v13 = v2->vfptr->GetActiveAssetId((UFG::RadioStationAsset *)&v2->vfptr);
    UFG::RadioStation::AddToPlaylist(v3, v13, 1);
  }
}

// File Line: 455
// RVA: 0x66FF70
void __fastcall UFG::RadioStation::AddToPlaylist(UFG::RadioStation *this, const char *id, bool isSeekable)
{
  UFG::RadioStation *v3; // rbx
  bool v4; // di
  unsigned int v5; // eax

  v3 = this;
  v4 = isSeekable;
  v5 = UFG::TiDo::CalcWwiseUid(id);
  UFG::RadioStation::AddToPlaylist(v3, v5, v4);
}

// File Line: 459
// RVA: 0x66FEB0
void __fastcall UFG::RadioStation::AddToPlaylist(UFG::RadioStation *this, unsigned int id, bool isSeekable)
{
  bool v3; // r14
  unsigned int v4; // ebp
  UFG::RadioStation *v5; // rdi
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **v6; // rbx
  UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **v7; // rsi
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rcx

  v3 = isSeekable;
  v4 = id;
  v5 = this;
  v6 = &this->m_assets.mNode.mNext[-1].mNext;
  v7 = &this->m_programs.mNode.mNext;
  if ( v6 != (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **)&this->m_programs.mNode.mNext )
  {
    do
    {
      if ( ((unsigned int (__fastcall *)(UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **))(*v6)->mNext)(v6) == v4 )
      {
        *((_BYTE *)v6 + 36) &= 0xFEu;
        *((_BYTE *)v6 + 36) |= v3;
        v8 = UFG::qMalloc(0x18ui64, "PlayList.Asset", 0i64);
        if ( v8 )
        {
          v8->mNext = v8;
          v8[1].mNext = v8;
          v8[2].mNext = (UFG::allocator::free_link *)v6;
        }
        v9 = (UFG::allocator::free_link *)v5->m_playList.mNode.mPrev;
        v9[1].mNext = v8;
        v8->mNext = v9;
        v8[1].mNext = (UFG::allocator::free_link *)&v5->m_playList;
        v5->m_playList.mNode.mPrev = (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)v8;
      }
      v6 = &v6[2][-1].mNext;
    }
    while ( v6 != (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **)v7 );
  }
}

// File Line: 475
// RVA: 0x688460
void __fastcall UFG::RadioStation::RandomizePlaylist(UFG::RadioStation *this)
{
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *v1; // rdi
  int v2; // edx
  UFG::RadioStation *v3; // r13
  UFG::RadioStation *v4; // rax
  __int64 v5; // r15
  float v6; // xmm8_4
  float v7; // xmm0_4
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v8; // rbx
  signed int i; // eax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v10; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v11; // rcx
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *j; // rax
  float v13; // xmm0_4
  int v14; // eax
  UFG::RadioStation *v15; // rsi
  int v16; // er14
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v17; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v18; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v19; // rax
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *k; // rax

  v1 = &this->m_playList;
  v2 = 0;
  v3 = this;
  v4 = (UFG::RadioStation *)this->m_playList.mNode.mNext;
  if ( v4 != (UFG::RadioStation *)&this->m_playList )
  {
    do
    {
      v4 = (UFG::RadioStation *)v4->mPrev;
      ++v2;
    }
    while ( v4 != (UFG::RadioStation *)v1 );
  }
  if ( 10 * v2 )
  {
    v5 = (unsigned int)(10 * v2);
    v6 = (float)(v2 - 1);
    do
    {
      v7 = UFG::qRandom(v6, &UFG::qDefaultSeed);
      v8 = v1->mNode.mNext;
      for ( i = (signed int)v7; i > 0; --i )
      {
        if ( v8 == (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)v1 )
          break;
        v8 = v8->mNext;
      }
      if ( !v8 )
        goto LABEL_20;
      v10 = v8->mNext;
      v11 = v8->mPrev;
      v11->mNext = v10;
      v10->mPrev = v11;
      v8->mPrev = v8;
      v8->mNext = v8;
      for ( j = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)v1->mNode.mNext;
            j != v1;
            j = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)j->mNode.mNext )
      {
        ;
      }
      v13 = UFG::qRandom(1.0, &UFG::qDefaultSeed);
      v14 = ((__int64 (*)(void))v8[1].mPrev->mPrev->mNext)();
      v15 = (UFG::RadioStation *)v3->m_prevPlayed.mNode.mNext;
      v16 = v14;
      if ( v15 == (UFG::RadioStation *)&v3->m_prevPlayed )
      {
LABEL_15:
        if ( v13 > 0.5 )
        {
          v18 = v1->mNode.mNext;
          v1->mNode.mNext = v8;
          v8->mPrev = &v1->mNode;
          v8->mNext = v18;
          v18->mPrev = v8;
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
            if ( ((unsigned int (*)(void))v17->mPrev->mNext)() == v16 )
              break;
          }
          v15 = (UFG::RadioStation *)v15->mPrev;
          if ( v15 == (UFG::RadioStation *)&v3->m_prevPlayed )
            goto LABEL_15;
        }
      }
      v19 = v1->mNode.mPrev;
      v19->mNext = v8;
      v8->mPrev = v19;
      v8->mNext = &v1->mNode;
      v1->mNode.mPrev = v8;
LABEL_18:
      for ( k = (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)v1->mNode.mNext;
            k != v1;
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
  UFG::RadioStation *v1; // rbx
  UFG::RadioStationAsset *v2; // rdi
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v5; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v6; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v7; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v8; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v9; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v10; // rax

  v1 = this;
  ++this->m_numRecentlyPlayed;
  v2 = this->m_currentlyPlaying;
  v3 = UFG::qMalloc(0x18ui64, "PlayList.Asset", 0i64);
  v4 = v3;
  if ( v3 )
  {
    v3->mNext = v3;
    v3[1].mNext = v3;
    v3[2].mNext = (UFG::allocator::free_link *)v2;
  }
  else
  {
    v4 = 0i64;
  }
  v5 = v1->m_prevPlayed.mNode.mNext;
  v1->m_prevPlayed.mNode.mNext = (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)v4;
  v4->mNext = (UFG::allocator::free_link *)&v1->m_prevPlayed;
  v4[1].mNext = (UFG::allocator::free_link *)v5;
  v5->mPrev = (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)v4;
  if ( v1->m_numRecentlyPlayed > 0x14 )
  {
    v6 = v1->m_prevPlayed.mNode.mPrev;
    v7 = v6->mPrev;
    v8 = v6->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = v6;
    v6->mNext = v6;
    v9 = v6->mPrev;
    v10 = v6->mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v6->mPrev = v6;
    v6->mNext = v6;
    operator delete[](v6);
    --v1->m_numRecentlyPlayed;
  }
  UFG::qString::Set(&v1->m_currentlyPlayingAssetName, &customWorldMapCaption);
  v1->m_currentlyPlaying = 0i64;
}

// File Line: 577
// RVA: 0x68BBB0
void __fastcall UFG::RadioStation::SetupTrackAsset(UFG::RadioStation *this, unsigned int index, const char *artistName, const char *trackName)
{
  const char *v4; // rsi
  const char *v5; // rbp
  char v6; // r14
  UFG::RadioStation *v7; // rbx
  __int64 v8; // rdi
  unsigned int v9; // ecx
  signed __int64 i; // rax
  UFG::allocator::free_link *v11; // rax
  __int64 v12; // rax
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **v13; // rcx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v14; // rax

  v4 = trackName;
  v5 = artistName;
  v6 = index;
  v7 = this;
  v8 = 0i64;
  if ( !this->m_assetCount[0] )
  {
    v9 = 0;
    for ( i = (signed __int64)&v7->m_assets.mNode.mNext[-1].mNext;
          (UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **)i != &v7->m_programs.mNode.mNext;
          i = *(_QWORD *)(i + 16) - 8i64 )
    {
      ++v9;
    }
    v7->m_firstAssetIndex[0] = v9;
  }
  v11 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x40ui64, "TrackAsset", 0i64, 1u);
  if ( v11 )
  {
    UFG::TrackAsset::TrackAsset((UFG::TrackAsset *)v11, v7, v6, v5, v4);
    v8 = v12;
  }
  v13 = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **)(v8 + 8);
  v14 = v7->m_assets.mNode.mPrev;
  v14->mNext = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v8 + 8);
  *v13 = v14;
  v13[1] = &v7->m_assets.mNode;
  v7->m_assets.mNode.mPrev = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v8 + 8);
  ++v7->m_assetCount[0];
}

// File Line: 590
// RVA: 0x68B7B0
void __fastcall UFG::RadioStation::SetupAdAsset(UFG::RadioStation *this, unsigned int index)
{
  char v2; // si
  UFG::RadioStation *v3; // rbx
  __int64 v4; // rdi
  unsigned int v5; // ecx
  signed __int64 i; // rax
  UFG::allocator::free_link *v7; // rax
  __int64 v8; // rax
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **v9; // rcx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v10; // rax

  v2 = index;
  v3 = this;
  v4 = 0i64;
  if ( !this->m_assetCount[2] )
  {
    v5 = 0;
    for ( i = (signed __int64)&v3->m_assets.mNode.mNext[-1].mNext;
          (UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **)i != &v3->m_programs.mNode.mNext;
          i = *(_QWORD *)(i + 16) - 8i64 )
    {
      ++v5;
    }
    v3->m_firstAssetIndex[2] = v5;
  }
  v7 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x28ui64, "AdAsset", 0i64, 1u);
  if ( v7 )
  {
    UFG::AdAsset::AdAsset((UFG::AdAsset *)v7, v3, v2);
    v4 = v8;
  }
  v9 = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **)(v4 + 8);
  v10 = v3->m_assets.mNode.mPrev;
  v10->mNext = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v4 + 8);
  *v9 = v10;
  v9[1] = &v3->m_assets.mNode;
  v3->m_assets.mNode.mPrev = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v4 + 8);
  ++v3->m_assetCount[2];
}

// File Line: 603
// RVA: 0x68B870
void __fastcall UFG::RadioStation::SetupIdentAsset(UFG::RadioStation *this)
{
  UFG::RadioStation *v1; // rbx
  __int64 v2; // rdi
  unsigned int v3; // ecx
  signed __int64 i; // rax
  UFG::allocator::free_link *v5; // rax
  __int64 v6; // rax
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **v7; // rcx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v8; // rax

  v1 = this;
  v2 = 0i64;
  if ( !this->m_assetCount[3] )
  {
    v3 = 0;
    for ( i = (signed __int64)&v1->m_assets.mNode.mNext[-1].mNext;
          (UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **)i != &v1->m_programs.mNode.mNext;
          i = *(_QWORD *)(i + 16) - 8i64 )
    {
      ++v3;
    }
    v1->m_firstAssetIndex[3] = v3;
  }
  v5 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x28ui64, "IdentAsset", 0i64, 1u);
  if ( v5 )
  {
    UFG::IdentAsset::IdentAsset((UFG::IdentAsset *)v5, v1);
    v2 = v6;
  }
  v7 = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> **)(v2 + 8);
  v8 = v1->m_assets.mNode.mPrev;
  v8->mNext = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v2 + 8);
  *v7 = v8;
  v7[1] = &v1->m_assets.mNode;
  v1->m_assets.mNode.mPrev = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v2 + 8);
  ++v1->m_assetCount[3];
}

// File Line: 655
// RVA: 0x678C20
UFG::qNode<UFG::RadioStation,UFG::RadioStation> **__fastcall UFG::Radio::FindRadioStation(UFG::qSymbol *name)
{
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> **result; // rax
  unsigned int v2; // ecx

  result = &UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
  if ( &UFG::Radio::sm_stationList.mNode.mNext[-1].mNext == (UFG::qNode<UFG::RadioStation,UFG::RadioStation> **)((char *)&UFG::Radio::sm_stationList - 8) )
    return 0i64;
  v2 = name->mUID;
  while ( *((_DWORD *)result + 9) != v2 )
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
void __fastcall UFG::Radio::LoadRadioStationData(float chanceDj)
{
  SimpleXML::XMLDocument *v1; // rax
  SimpleXML::XMLDocument *v2; // r12
  unsigned int v3; // er15
  SimpleXML::XMLNode *v4; // rax
  SimpleXML::XMLNode *v5; // r14
  char *v6; // rbx
  unsigned int v7; // edi
  unsigned int v8; // esi
  char copScannerStation; // bp
  UFG::allocator::free_link *v10; // rax
  UFG::RadioStation *v11; // rax
  UFG::RadioStation *v12; // rbp
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v13; // rcx
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v14; // rax
  SimpleXML::XMLNode *v15; // r13
  char *v16; // rdi
  unsigned int v17; // er14
  SimpleXML::XMLNode *v18; // rbx
  char *v19; // rax
  char *v20; // rdi
  char *v21; // rsi
  unsigned int v22; // eax
  unsigned int v23; // ebx
  __int64 v24; // rdi
  SimpleXML::XMLNode *v25; // rsi
  char v26; // r14
  char *v27; // rax
  int v28; // ebx
  unsigned int v29; // edi
  char *v30; // rax
  unsigned int v31; // ecx
  signed __int64 j; // rax
  UFG::allocator::free_link *v33; // rax
  __int64 v34; // rax
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v35; // rcx
  UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *v36; // rax
  char *v37; // rax
  char *v38; // rax
  unsigned int v39; // ecx
  signed __int64 k; // rax
  UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *l; // rax
  UFG::qString result; // [rsp+50h] [rbp-128h]
  char ptr[184]; // [rsp+80h] [rbp-F8h]
  char *v44; // [rsp+180h] [rbp+8h]
  SimpleXML::XMLNode *v45; // [rsp+188h] [rbp+10h]
  SimpleXML::XMLNode *i; // [rsp+190h] [rbp+18h]
  SimpleXML::XMLNode *prev_node; // [rsp+198h] [rbp+20h]

  v1 = SimpleXML::XMLDocument::Open("Data\\Audio\\Radios.xml", 1ui64, 0i64);
  v2 = v1;
  v3 = 0;
  if ( v1 )
  {
    v4 = SimpleXML::XMLDocument::GetNode(v1, 0i64, 0i64);
    for ( prev_node = v4; v4; prev_node = v4 )
    {
      v5 = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, v4);
      for ( i = v5; v5; i = v5 )
      {
        v6 = SimpleXML::XMLNode::GetAttribute(v5, "name", &customWorldMapCaption);
        v7 = SimpleXML::XMLNode::GetAttribute(v5, "id", 0);
        v8 = SimpleXML::XMLNode::GetAttribute(v5, "numConsecutiveTracks", 0);
        SimpleXML::XMLNode::GetAttribute(v5, "chanceDJ", 0.0);
        SimpleXML::XMLNode::GetAttribute(v5, "chanceAd", 0.0);
        SimpleXML::XMLNode::GetAttribute(v5, "chanceTrack", 0.0);
        copScannerStation = SimpleXML::XMLNode::GetAttribute(v5, "copScanner", 0);
        v10 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x170ui64, "RadioStation", 0i64, 1u);
        if ( v10 )
        {
          UFG::RadioStation::RadioStation(
            (UFG::RadioStation *)v10,
            v6,
            v7,
            v8,
            chanceDj,
            chanceDj,
            chanceDj,
            copScannerStation);
          v12 = v11;
        }
        else
        {
          v12 = 0i64;
        }
        v13 = (UFG::qNode<UFG::RadioStation,UFG::RadioStation> *)&v12->mPrev;
        v14 = UFG::Radio::sm_stationList.mNode.mPrev;
        UFG::Radio::sm_stationList.mNode.mPrev->mNext = (UFG::qNode<UFG::RadioStation,UFG::RadioStation> *)&v12->mPrev;
        v13->mPrev = v14;
        v13->mNext = (UFG::qNode<UFG::RadioStation,UFG::RadioStation> *)&UFG::Radio::sm_stationList;
        UFG::Radio::sm_stationList.mNode.mPrev = (UFG::qNode<UFG::RadioStation,UFG::RadioStation> *)&v12->mPrev;
        UFG::RadioStation::SetupIdentAsset(v12);
        v15 = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, v5);
        v45 = v15;
        if ( v15 )
        {
          do
          {
            v16 = SimpleXML::XMLNode::GetName(v15);
            v44 = v16;
            if ( !(unsigned int)UFG::qStringCompare(v16, "Tracks", -1) )
            {
              v17 = 1;
              v18 = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, v15);
              if ( v18 )
              {
                do
                {
                  v19 = SimpleXML::XMLNode::GetName(v18);
                  if ( !(unsigned int)UFG::qStringCompare(v19, "Track", -1) )
                  {
                    v20 = &customWorldMapCaption;
                    v21 = &customWorldMapCaption;
                    if ( SimpleXML::XMLNode::GetAttribute(v18, "artist") )
                      v21 = SimpleXML::XMLNode::GetAttribute(v18, "artist");
                    if ( SimpleXML::XMLNode::GetAttribute(v18, "name") )
                      v20 = SimpleXML::XMLNode::GetAttribute(v18, "name");
                    UFG::RadioStation::SetupTrackAsset(v12, v17++, v21, v20);
                  }
                  v18 = SimpleXML::XMLDocument::GetNode(v2, 0i64, v18);
                }
                while ( v18 );
                v16 = v44;
              }
            }
            if ( !(unsigned int)UFG::qStringCompare(v16, "Ads", -1) )
            {
              v22 = SimpleXML::XMLNode::GetAttribute(v15, "count", 0);
              v23 = 1;
              if ( v22 )
              {
                v24 = v22;
                do
                {
                  UFG::RadioStation::SetupAdAsset(v12, v23++);
                  --v24;
                }
                while ( v24 );
                v16 = v44;
              }
            }
            if ( !(unsigned int)UFG::qStringCompare(v16, "DJs", -1) )
            {
              SimpleXML::XMLNode::GetAttribute(v15, "count", 0);
              v25 = SimpleXML::XMLDocument::GetChildNode(v2, 0i64, v15);
              v26 = 1;
              if ( v25 )
              {
                do
                {
                  v27 = SimpleXML::XMLNode::GetName(v25);
                  if ( !(unsigned int)UFG::qStringCompare(v27, "DJ", -1) )
                  {
                    `eh vector constructor iterator'(
                      ptr,
                      0x28ui64,
                      3,
                      (void (__fastcall *)(void *))UFG::qString::qString);
                    v28 = 0;
                    do
                    {
                      v29 = v28 + 1;
                      UFG::qString::FormatEx(&result, "track%d", (unsigned int)(v28 + 1));
                      if ( SimpleXML::XMLNode::GetAttribute(v25, result.mData) )
                      {
                        v30 = SimpleXML::XMLNode::GetAttribute(v25, result.mData);
                        UFG::qString::Set((UFG::qString *)&ptr[40 * v28], v30);
                      }
                      UFG::qString::~qString(&result);
                      ++v28;
                    }
                    while ( v29 < 3 );
                    if ( !v12->m_assetCount[1] )
                    {
                      v31 = 0;
                      for ( j = (signed __int64)&v12->m_assets.mNode.mNext[-1].mNext;
                            (UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **)j != &v12->m_programs.mNode.mNext;
                            j = *(_QWORD *)(j + 16) - 8i64 )
                      {
                        ++v31;
                      }
                      v12->m_firstAssetIndex[1] = v31;
                    }
                    v33 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x48ui64, "DJAsset", 0i64, 1u);
                    if ( v33 )
                      UFG::DJAsset::DJAsset((UFG::DJAsset *)v33, v12, v26, (UFG::qString *)ptr, 3u);
                    else
                      v34 = 0i64;
                    v35 = (UFG::qNode<UFG::RadioStationAsset,UFG::RadioStationAsset> *)(v34 + 8);
                    v36 = v12->m_assets.mNode.mPrev;
                    v36->mNext = v35;
                    v35->mPrev = v36;
                    v35->mNext = &v12->m_assets.mNode;
                    v12->m_assets.mNode.mPrev = v35;
                    ++v12->m_assetCount[1];
                    ++v26;
                    `eh vector destructor iterator'(
                      ptr,
                      0x28ui64,
                      3,
                      (void (__fastcall *)(void *))UFG::qString::~qString);
                  }
                  v25 = SimpleXML::XMLDocument::GetNode(v2, 0i64, v25);
                }
                while ( v25 );
                v15 = v45;
                v16 = v44;
              }
            }
            if ( !(unsigned int)UFG::qStringCompare(v16, "TextureName", -1) )
            {
              v37 = SimpleXML::XMLNode::GetAttribute(v15, "name");
              UFG::qString::Set(&v12->m_textureName, v37);
            }
            if ( !(unsigned int)UFG::qStringCompare(v16, "TexturePack", -1) )
            {
              v38 = SimpleXML::XMLNode::GetAttribute(v15, "name");
              UFG::qString::Set(&v12->m_texturePack, v38);
            }
            v15 = SimpleXML::XMLDocument::GetNode(v2, 0i64, v15);
            v45 = v15;
          }
          while ( v15 );
          v5 = i;
        }
        v39 = 0;
        for ( k = (signed __int64)&v12->m_assets.mNode.mNext[-1].mNext;
              (UFG::qNode<UFG::RadioStationProgram,UFG::RadioStationProgram> **)k != &v12->m_programs.mNode.mNext;
              k = *(_QWORD *)(k + 16) - 8i64 )
        {
          ++v39;
        }
        v12->m_numAssets = v39;
        v5 = SimpleXML::XMLDocument::GetNode(v2, 0i64, v5);
      }
      v4 = SimpleXML::XMLDocument::GetNode(v2, 0i64, prev_node);
    }
    SimpleXML::XMLDocument::~XMLDocument(v2);
    operator delete[](v2);
  }
  for ( l = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
        l != (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)((char *)&UFG::Radio::sm_stationList - 8);
        l = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&l[1].mNode.mPrev[-1].mNext )
  {
    ++v3;
  }
  UFG::Radio::sm_numStations = v3;
}

// File Line: 841
// RVA: 0x6745F0
void UFG::Radio::ClearRadioStationData(void)
{
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *i; // rax
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v1; // rcx
  UFG::qNode<UFG::RadioStation,UFG::RadioStation> *v2; // rdx

  for ( i = UFG::Radio::sm_stationList.mNode.mNext;
        &UFG::Radio::sm_stationList.mNode.mNext[-1].mNext != (UFG::qNode<UFG::RadioStation,UFG::RadioStation> **)((char *)&UFG::Radio::sm_stationList - 8);
        i = UFG::Radio::sm_stationList.mNode.mNext )
  {
    v1 = i->mNext;
    v2 = i->mPrev;
    v2->mNext = v1;
    v1->mPrev = v2;
    i->mPrev = i;
    i->mNext = i;
    if ( i != (UFG::qNode<UFG::RadioStation,UFG::RadioStation> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::RadioStation,UFG::RadioStation> **, signed __int64))i[-1].mNext->mPrev)(
        &i[-1].mNext,
        1i64);
  }
}

// File Line: 846
// RVA: 0x669E90
void __fastcall UFG::Radio::Radio(UFG::Radio *this)
{
  UFG::Radio *v1; // rbx

  v1 = this;
  UFG::AudioEntity::AudioEntity((UFG::AudioEntity *)&this->vfptr);
  v1->vfptr = (UFG::AudioEntityVtbl *)&UFG::Radio::`vftable';
  v1->m_ecRadio.m_pEvent = 0i64;
  *(_QWORD *)&v1->m_timeSinceRadioStarted = 0i64;
  v1->m_buttonHoldLength = 0.0;
  v1->m_ignoreRelease = 0;
  v1->m_pVehAudComponent = 0i64;
  *(_QWORD *)&v1->m_adjacentNextStationCount = 0i64;
  *((_BYTE *)v1 + 345) &= 0xFEu;
  v1->m_timeSinceStationChanged = 0.0;
  v1->m_radioType = 0;
  UFG::Radio::SetupParams(v1, -1);
}

// File Line: 879
// RVA: 0x68B930
void __fastcall UFG::Radio::SetupParams(UFG::Radio *this, int station)
{
  char *v2; // rsi
  int v3; // er8
  UFG::Radio *v4; // rbx
  UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *j; // rdx
  float v6; // xmm0_4
  signed int i; // ecx
  UFG::VehicleAudioComponent *v8; // rax
  UFG::qPropertySet *v9; // rdi

  v2 = 0i64;
  *((_BYTE *)this + 344) = -124;
  this->m_curStation = 0i64;
  v3 = station;
  v4 = this;
  if ( station < 0 )
  {
    v6 = UFG::qRandom((float)(signed int)UFG::Radio::sm_numStations - 1.0, &UFG::qDefaultSeed);
    j = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
    for ( i = (signed int)v6; i > 0; j = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&j[1].mNode.mPrev[-1].mNext )
    {
      if ( j == (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)((char *)&UFG::Radio::sm_stationList - 8) )
        break;
      --i;
    }
    this = v4;
  }
  else
  {
    for ( j = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
          v3 > 0;
          j = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&j[1].mNode.mPrev[-1].mNext )
    {
      if ( j == (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)((char *)&UFG::Radio::sm_stationList - 8) )
        break;
      --v3;
    }
  }
  UFG::Radio::SetCurStation(this, (UFG::RadioStation *)j);
  v8 = v4->m_pVehAudComponent;
  if ( v8 )
  {
    v9 = v8->m_pSubTypeParameters->mpPropertySet;
    if ( Vehicles_Audio_Base_BaseVehicleBase::IsClass(v9->mSchemaName.mUID) )
      v2 = UFG::qPropertySet::GetMemImagePtr(v9);
    *((_BYTE *)v4 + 344) ^= (*((_BYTE *)v4 + 344) ^ v2[192]) & 1;
  }
}

// File Line: 914
// RVA: 0x67C650
void __fastcall UFG::Radio::HandleInputs(UFG::Radio *this)
{
  UFG::Radio *v1; // rbx
  hkgpIndexedMeshDefinitions::Edge *v2; // rdx
  hkgpIndexedMesh::EdgeBarrier *v3; // rcx
  __int64 v4; // rdi
  UFG::InputActionData *v5; // rax
  float v6; // xmm6_4
  UFG::UIHKScreenHud *v7; // rax
  UFG::UIHKRadioStationWidget *v8; // rsi
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

  v1 = this;
  if ( UFG::UIHKScreenHud::getInstance() )
  {
    UFG::Music::sm_bIsObjectActiveDirty = 1;
    if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v3, v2)
      || !UFG::Music::sm_bIsObjectActive )
    {
      v4 = (signed int)UFG::gActiveControllerNum;
      v5 = UFG::ActionDef_NextRadioStationReleased.mDataPerController[UFG::gActiveControllerNum];
      v6 = UFG::Metrics::msInstance.mSimTimeDelta;
      if ( v5 && v5->mActionTrue )
      {
        if ( !v1->m_ignoreRelease )
        {
          v7 = UFG::UIHKScreenHud::getInstance();
          if ( v7 )
          {
            v8 = &v7->RadioStationWidget;
            if ( UFG::UIHKRadioStationWidget::IsActive(&v7->RadioStationWidget) )
            {
              LOBYTE(v9) = 1;
              (*(void (__fastcall **)(UFG::Radio *, __int64))v1->vfptr[1].gap8)(v1, v9);
            }
            else
            {
              UFG::Radio::PlayClick(v1);
              UFG::UIHKRadioStationWidget::ChangeStation(v8, v1->m_curStation->m_id);
            }
          }
        }
        v1->m_ignoreRelease = 0;
      }
      v10 = UFG::ActionDef_PrevRadioStationReleased.mDataPerController[v4];
      if ( v10 && v10->mActionTrue )
      {
        if ( !v1->m_ignoreRelease )
        {
          v11 = UFG::UIHKScreenHud::getInstance();
          if ( v11 )
          {
            v12 = &v11->RadioStationWidget;
            if ( UFG::UIHKRadioStationWidget::IsActive(&v11->RadioStationWidget) )
            {
              LOBYTE(v13) = 1;
              ((void (__fastcall *)(UFG::Radio *, __int64))v1->vfptr[1].StopAndForgetEvent)(v1, v13);
            }
            else
            {
              UFG::Radio::PlayClick(v1);
              UFG::UIHKRadioStationWidget::ChangeStation(v12, v1->m_curStation->m_id);
            }
          }
        }
        v1->m_ignoreRelease = 0;
      }
      v14 = UFG::ActionDef_NextRadioStationHold.mDataPerController[v4];
      if ( v14 && v14->mActionTrue
        || (v15 = UFG::ActionDef_PrevRadioStationHold.mDataPerController[v4]) != 0i64 && v15->mActionTrue )
      {
        v1->m_buttonHoldLength = v6 + v1->m_buttonHoldLength;
      }
      else
      {
        v1->m_buttonHoldLength = 0.0;
      }
      v16 = UFG::ActionDef_NextRadioStationHold.mDataPerController[v4];
      if ( v16 && v16->mActionTrue && v1->m_buttonHoldLength > 0.40000001 )
      {
        if ( *((_BYTE *)v1 + 344) & 4 )
        {
          ((void (__fastcall *)(UFG::Radio *))v1->vfptr[1].AudioEntityUpdate)(v1);
          UFG::Radio::PlayClick(v1);
        }
        UFG::Radio::IncreaseRadioVolume(v1);
        v1->m_buttonHoldLength = 0.0;
        v1->m_ignoreRelease = 1;
      }
      v17 = UFG::ActionDef_UIDownPressed.mDataPerController[v4];
      if ( v17 && v17->mActionTrue )
        v1->m_ignoreRelease = 1;
      v18 = UFG::ActionDef_UIUpPressed.mDataPerController[v4];
      if ( v18 && v18->mActionTrue )
        v1->m_ignoreRelease = 1;
      v19 = UFG::ActionDef_PrevRadioStationHold.mDataPerController[v4];
      if ( v19 && v19->mActionTrue && v1->m_buttonHoldLength > 0.40000001 )
      {
        if ( !(*((_BYTE *)v1 + 344) & 4) )
          UFG::Radio::DecreaseRadioVolume(v1);
        v1->m_buttonHoldLength = 0.0;
        v1->m_ignoreRelease = 1;
      }
    }
  }
}seRadioVolume(v1);
        v1->m_buttonHoldLength = 0.0;
        v1->m_ignoreR

// File Line: 1029
// RVA: 0x6932B0
void __fastcall UFG::Radio::Update(UFG::Radio *this, float delta_sec)
{
  UFG::Radio *v2; // rdi
  int v3; // edx
  int v4; // er8
  UFG::VehicleAudioComponent *v5; // rcx
  char *v6; // rax
  UFG::qString *v7; // rax
  UFG::qString *v8; // rax
  UFG::AudioEntityVtbl *v9; // rbx
  UFG::qSymbol *v10; // rax
  UFG::qWiseSymbol *v11; // rcx
  bool v12; // bl
  UFG::UIHKScreenHud *v13; // rax
  UFG::UIHKScreenHud *v14; // rax
  UFG::qString v15; // [rsp+38h] [rbp-90h]
  UFG::qString result; // [rsp+60h] [rbp-68h]
  UFG::qString v17; // [rsp+88h] [rbp-40h]
  UFG::qSymbol v18; // [rsp+D0h] [rbp+8h]

  v2 = this;
  UFG::Radio::HandleInputs(this);
  if ( v2->m_bIsInitialized )
  {
    v2->m_timeSinceStationChanged = delta_sec + v2->m_timeSinceStationChanged;
    v11 = (UFG::qWiseSymbol *)v2->m_curStation;
    v12 = v11
       && (UFG::SoundBankManager::BankLoaded(v11 + 70) || v2->m_curStation->m_bIsCopScannerStation)
       && UFG::Radio::PlayerInVehicle(v2)
       && v2->m_timeSinceStationChanged > 0.30000001;
    if ( *((_BYTE *)v2 + 344) & 0x20 && v12 )
    {
      v13 = UFG::UIHKScreenHud::getInstance();
      if ( v13 )
        UFG::UIHKRadioStationWidget::ChangeStation(&v13->RadioStationWidget, v2->m_curStation->m_id);
      *((_BYTE *)v2 + 344) &= 0xDFu;
    }
    if ( *((_BYTE *)v2 + 344) & 0x40 && v12 )
    {
      v14 = UFG::UIHKScreenHud::getInstance();
      if ( v14 )
        UFG::UIHKRadioStationWidget::ChangeStation(&v14->RadioStationWidget, v2->m_curStation->m_id);
      *((_BYTE *)v2 + 344) &= 0xBFu;
    }
    if ( *((_BYTE *)v2 + 344) & 8 && v12 )
    {
      if ( !v2->m_curStation->m_bIsCopScannerStation )
        UFG::Radio::DoStartTrack(v2, v3, v4);
      *((_BYTE *)v2 + 344) &= 0xE7u;
    }
    if ( !UFG::Radio::s_bEnabled && *((_BYTE *)v2 + 344) & 2 )
      ((void (__fastcall *)(UFG::Radio *, signed __int64))v2->vfptr[1].StopAndForgetAllEvents)(v2, 500i64);
  }
  else
  {
    UFG::qString::qString(&v15, &customWorldMapCaption);
    v5 = v2->m_pVehAudComponent;
    if ( v5 )
    {
      v6 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v5->m_pSimObject->m_Name);
      UFG::qString::qString(&v17, v6);
      v8 = UFG::operator+(&result, v7, "_Radio");
      UFG::qString::Set(&v15, v8->mData, v8->mLength, 0i64, 0);
      UFG::qString::~qString(&result);
      UFG::qString::~qString(&v17);
    }
    v9 = v2->vfptr;
    v10 = UFG::qSymbol::create_from_string(&v18, v15.mData);
    (*(void (__fastcall **)(UFG::Radio *, UFG::qSymbol *, UFG::qMatrix44 *))v9->gap8)(
      v2,
      v10,
      &UFG::qMatrix44::msIdentity);
    *((_BYTE *)v2 + 344) |= 0x80u;
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
  UFG::Radio *v2; // rbx
  float v3; // xmm6_4
  float v4; // xmm6_4

  v2 = this;
  if ( *((_BYTE *)this + 344) & 4 )
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
    v4 = delta_sec + v2->m_timeSinceRadioStarted;
    v2->m_timeSinceRadioStopped = 0.0;
    if ( v4 <= 0.0 )
    {
      v4 = 0.0;
    }
    else if ( v4 >= 600.0 )
    {
      v2->m_timeSinceRadioStarted = FLOAT_600_0;
      return;
    }
    v2->m_timeSinceRadioStarted = v4;
  }
}

// File Line: 1139
// RVA: 0x681D70
void __fastcall UFG::Radio::NextStation(UFG::Radio *this, bool displayStationId)
{
  bool v2; // si
  UFG::Radio *v3; // rdi
  char v4; // al
  UFG::AudioEntityVtbl *v5; // rax
  UFG::RadioStation *v6; // rbx
  unsigned __int8 v7; // bl
  UFG::RadioStationAsset *v8; // rcx

  v2 = displayStationId;
  v3 = this;
  if ( UFG::Radio::s_bEnabled )
  {
    v4 = *((_BYTE *)this + 344);
    if ( v4 & 1 )
    {
      if ( !(v4 & 0x20) && !(v4 & 0x40) )
      {
        v5 = this->vfptr;
        ++this->m_adjacentNextStationCount;
        this->m_timeSinceStationChanged = 0.0;
        this->m_adjacentPrevStationCount = 0;
        ((void (__fastcall *)(UFG::Radio *, signed __int64))v5[1].StopAndForgetAllEvents)(this, 500i64);
        v6 = v3->m_curStation;
        UFG::Radio::GetNextStationId(v3);
        if ( v6 != v3->m_curStation )
          UFG::Radio::PlayClick(v3);
        *((_BYTE *)v3 + 344) |= 0x80u;
        v7 = 0;
        v8 = v3->m_curStation->m_currentlyPlaying;
        if ( v8 )
        {
          v7 = 0;
          if ( v8->m_type == 2 )
            v7 = 1;
          if ( v3->m_adjacentNextStationCount == UFG::Radio::sm_numStations - 1 )
          {
            UFG::Radio::AdvanceAllStations(v3, 180.0);
            v3->m_adjacentNextStationCount = 0;
          }
        }
        ((void (__fastcall *)(UFG::Radio *, _QWORD))v3->vfptr[1].DestroyAllEvents)(v3, v7);
        if ( v2 )
          *((_BYTE *)v3 + 344) |= 0x20u;
      }
    }
  }
}

// File Line: 1201
// RVA: 0x687600
void __fastcall UFG::Radio::PrevStation(UFG::Radio *this, bool displayStationId)
{
  bool v2; // si
  UFG::Radio *v3; // rdi
  char v4; // al
  UFG::AudioEntityVtbl *v5; // rax
  UFG::RadioStation *v6; // rbx
  unsigned __int8 v7; // bl
  UFG::RadioStationAsset *v8; // rcx

  v2 = displayStationId;
  v3 = this;
  if ( UFG::Radio::s_bEnabled )
  {
    v4 = *((_BYTE *)this + 344);
    if ( v4 & 1 )
    {
      if ( !(v4 & 0x40) && !(v4 & 0x20) )
      {
        v5 = this->vfptr;
        ++this->m_adjacentPrevStationCount;
        this->m_timeSinceStationChanged = 0.0;
        this->m_adjacentNextStationCount = 0;
        ((void (__fastcall *)(UFG::Radio *, signed __int64))v5[1].StopAndForgetAllEvents)(this, 500i64);
        v6 = v3->m_curStation;
        UFG::Radio::GetPrevStationId(v3);
        if ( v6 != v3->m_curStation )
          UFG::Radio::PlayClick(v3);
        *((_BYTE *)v3 + 344) |= 0x80u;
        v7 = 0;
        v8 = v3->m_curStation->m_currentlyPlaying;
        if ( v8 )
        {
          v7 = 0;
          if ( v8->m_type == 2 )
            v7 = 1;
          if ( v3->m_adjacentPrevStationCount == UFG::Radio::sm_numStations - 1 )
          {
            UFG::Radio::AdvanceAllStations(v3, 180.0);
            v3->m_adjacentPrevStationCount = 0;
          }
        }
        ((void (__fastcall *)(UFG::Radio *, _QWORD))v3->vfptr[1].DestroyAllEvents)(v3, v7);
        if ( v2 )
          *((_BYTE *)v3 + 344) |= 0x40u;
      }
    }
  }
}

// File Line: 1261
// RVA: 0x68B5B0
void __fastcall UFG::Radio::SetStation(UFG::Radio *this, unsigned int stationIdx)
{
  UFG::RadioStation *v2; // r8
  unsigned int v3; // edi
  UFG::Radio *v4; // rbx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v5; // rax
  signed __int64 v6; // r8
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v7; // rcx
  char v8; // al
  int v9; // ecx
  UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *i; // rdx
  char v11; // al

  v2 = this->m_curStation;
  v3 = stationIdx;
  v4 = this;
  if ( v2->m_id != stationIdx )
  {
    if ( v2
      && (UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *)v2->m_playList.mNode.mNext != &v2->m_playList
      && (v5 = v2->m_playList.mNode.mNext,
          v6 = (signed __int64)&v2->m_playList,
          v5 != (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)v6) )
    {
      while ( 1 )
      {
        v7 = v5[1].mPrev;
        if ( v7 )
        {
          if ( !(BYTE4(v7[2].mPrev) & 1) )
            break;
        }
        v5 = v5->mNext;
        if ( v5 == (UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *)v6 )
          goto LABEL_8;
      }
    }
    else
    {
LABEL_8:
      v8 = *((_BYTE *)v4 + 344);
      if ( !(v8 & 4) && v8 & 2 )
        ((void (__fastcall *)(UFG::Radio *, signed __int64))v4->vfptr[1].StopAndForgetAllEvents)(v4, 500i64);
      v9 = v3 - 1;
      for ( i = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&UFG::Radio::sm_stationList.mNode.mNext[-1].mNext;
            v9 > 0;
            i = (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)&i[1].mNode.mPrev[-1].mNext )
      {
        if ( i == (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)((char *)&UFG::Radio::sm_stationList - 8) )
          break;
        --v9;
      }
      UFG::Radio::SetCurStation(v4, (UFG::RadioStation *)i);
      v11 = *((_BYTE *)v4 + 344);
      if ( !(v11 & 4) )
      {
        if ( v11 & 2 )
          ((void (__fastcall *)(UFG::Radio *, _QWORD))v4->vfptr[1].DestroyAllEvents)(v4, 0i64);
      }
    }
  }
}

// File Line: 1298
// RVA: 0x67A990
void __fastcall UFG::Radio::GetNextStationId(UFG::Radio *this)
{
  UFG::Radio *v1; // rdi
  UFG::RadioStation *v2; // rcx
  char *v3; // rax
  signed __int64 v4; // rbx
  UFG::Radio::eRadioType v5; // edx
  UFG::qWiseSymbol *v6; // rcx

  v1 = this;
  v2 = this->m_curStation;
  v3 = (char *)&UFG::Radio::sm_stationList - 8;
  v4 = (signed __int64)&v2->mNext[-1].mNext;
  if ( (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)v4 == (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)((char *)&UFG::Radio::sm_stationList - 8) )
    v4 = *(_QWORD *)(v4 + 16) - 8i64;
  v5 = v1->m_radioType;
  if ( v5 == eRadioType_Radio && *(_BYTE *)(v4 + 361) )
  {
    do
    {
      v4 = *(_QWORD *)(v4 + 16) - 8i64;
      if ( (char *)v4 == v3 )
        v4 = *(_QWORD *)(v4 + 16) - 8i64;
    }
    while ( *(_BYTE *)(v4 + 361) );
  }
  if ( v5 == 1 && !*(_BYTE *)(v4 + 361) )
  {
    do
    {
      v4 = *(_QWORD *)(v4 + 16) - 8i64;
      if ( (char *)v4 == v3 )
        v4 = *(_QWORD *)(v4 + 16) - 8i64;
    }
    while ( !*(_BYTE *)(v4 + 361) );
  }
  if ( v2 != (UFG::RadioStation *)v4 )
  {
    if ( v2 )
      UFG::TiDo::UnloadWwiseBank(&v2->m_bankId);
    UFG::GameStatAction::Radio::Stop(v1->m_curStation);
    v1->m_curStation = (UFG::RadioStation *)v4;
    UFG::GameStatAction::Radio::Start();
    v6 = (UFG::qWiseSymbol *)v1->m_curStation;
    if ( v6 )
      UFG::TiDo::LoadWwiseBank(v6 + 70);
  }
}

// File Line: 1329
// RVA: 0x67AFE0
void __fastcall UFG::Radio::GetPrevStationId(UFG::Radio *this)
{
  UFG::Radio *v1; // rdi
  UFG::RadioStation *v2; // rcx
  char *v3; // rax
  signed __int64 v4; // rbx
  UFG::Radio::eRadioType v5; // edx
  UFG::qWiseSymbol *v6; // rcx

  v1 = this;
  v2 = this->m_curStation;
  v3 = (char *)&UFG::Radio::sm_stationList - 8;
  v4 = (signed __int64)&v2->mPrev[-1].mNext;
  if ( (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)v4 == (UFG::qList<UFG::RadioStation,UFG::RadioStation,1,0> *)((char *)&UFG::Radio::sm_stationList - 8) )
    v4 = (signed __int64)&v2->mPrev->mPrev[-1].mNext;
  v5 = v1->m_radioType;
  if ( v5 == eRadioType_Radio && *(_BYTE *)(v4 + 361) )
  {
    do
    {
      v4 = *(_QWORD *)(v4 + 8) - 8i64;
      if ( (char *)v4 == v3 )
        v4 = *(_QWORD *)(v4 + 8) - 8i64;
    }
    while ( *(_BYTE *)(v4 + 361) );
  }
  if ( v5 == 1 && !*(_BYTE *)(v4 + 361) )
  {
    do
    {
      v4 = *(_QWORD *)(v4 + 8) - 8i64;
      if ( (char *)v4 == v3 )
        v4 = *(_QWORD *)(v4 + 8) - 8i64;
    }
    while ( !*(_BYTE *)(v4 + 361) );
  }
  if ( v2 != (UFG::RadioStation *)v4 )
  {
    if ( v2 )
      UFG::TiDo::UnloadWwiseBank(&v2->m_bankId);
    UFG::GameStatAction::Radio::Stop(v1->m_curStation);
    v1->m_curStation = (UFG::RadioStation *)v4;
    UFG::GameStatAction::Radio::Start();
    v6 = (UFG::qWiseSymbol *)v1->m_curStation;
    if ( v6 )
      UFG::TiDo::LoadWwiseBank(v6 + 70);
  }
}

// File Line: 1384
// RVA: 0x68C520
void __fastcall UFG::Radio::StartTrack(UFG::RadioFullyControlled *this, bool skipTrack)
{
  *((_BYTE *)&this->0 + 344) = *((_BYTE *)&this->0 + 344) ^ (*((_BYTE *)&this->0 + 344) ^ 16 * skipTrack) & 0x10 | 8;
}

// File Line: 1392
// RVA: 0x68A490
void __fastcall UFG::Radio::SetCurStation(UFG::Radio *this, UFG::RadioStation *station)
{
  UFG::Radio *v2; // rbx
  UFG::RadioStation *v3; // rcx
  UFG::RadioStation *v4; // rdi
  UFG::qWiseSymbol *v5; // rcx

  v2 = this;
  v3 = this->m_curStation;
  v4 = station;
  if ( v3 != station )
  {
    if ( v3 )
      UFG::TiDo::UnloadWwiseBank(&v3->m_bankId);
    UFG::GameStatAction::Radio::Stop(v2->m_curStation);
    v2->m_curStation = v4;
    UFG::GameStatAction::Radio::Start();
    v5 = (UFG::qWiseSymbol *)v2->m_curStation;
    if ( v5 )
      UFG::TiDo::LoadWwiseBank(v5 + 70);
  }
}

// File Line: 1416
// RVA: 0x676F00
void __fastcall UFG::Radio::DoStartTrack(UFG::Radio *this, int a2, int a3)
{
  UFG::Radio *v3; // rbx
  UFG::AudioEvent *v4; // rax
  char v5; // al
  UFG::VehicleAudioComponent *v6; // rax
  UFG::AudioEvent *v7; // rcx
  UFG::RadioStationAsset *v8; // rcx
  unsigned int v9; // eax
  char v10; // al
  UFG::UIHKScreenHud *v11; // rax
  UFG::RadioStation *v12; // rdx
  UFG::RadioStationAsset *v13; // rax
  UFG::AudioEvent *v14; // rcx
  __int64 v15; // [rsp+48h] [rbp-30h]
  UFG::AudioEventInitParams pInitParams; // [rsp+50h] [rbp-28h]

  v3 = this;
  if ( UFG::Radio::s_bEnabled
    && Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse((hkGeometryUtils::IVertices *)this, a2, a3) )
  {
    v4 = v3->m_ecRadio.m_pEvent;
    if ( (!v4 || !((*((_BYTE *)v4 + 144) >> 6) & 1)) && UFG::Radio::PlayerInVehicle(v3) )
    {
      v5 = *((_BYTE *)v3 + 344);
      if ( !(v5 & 4) && !(v5 & 2) )
      {
        v6 = v3->m_pVehAudComponent;
        if ( v6 )
        {
          if ( *((_BYTE *)v6 + 636) & 8 )
          {
            v7 = v3->m_ecRadio.m_pEvent;
            if ( v7 )
              UFG::AudioEvent::StopAndForget(v7, 0);
            *((_BYTE *)v3 + 344) |= 2u;
            if ( !(_S17_7 & 1) )
            {
              _S17_7 |= 1u;
              effect_off_on.mUID = UFG::qWiseSymbolUIDFromString("effect_off_on", 0x811C9DC5);
              _((AMD_HD3D *)effect_off_on.mUID);
              atexit(UFG::Radio::DoStartTrack_::_10_::_dynamic_atexit_destructor_for__effect_off_on__);
            }
            UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&v3->vfptr, effect_off_on.mUID, 0.94999999);
            pInitParams.m_EventCallbackUserData = 0i64;
            LODWORD(v15) = 0;
            pInitParams.m_EventPlayEndCallback = (void (__fastcall *)(UFG::AudioEntity *, UFG::eAudioEventCallbackType, UFG::AudioEvent *, void *))UFG::Radio::TrackFinishCallback;
            *(_QWORD *)pInitParams.gap8 = 0i64;
            *(_QWORD *)&pInitParams.gap8[8] = v15;
            v8 = v3->m_curStation->m_currentlyPlaying;
            v9 = 0;
            if ( v8 )
              v9 = ((__int64 (*)(void))v8->vfptr->GetActiveAssetId)();
            if ( *((_BYTE *)v3 + 344) & 0x10 || !v9 )
            {
              UFG::RadioStation::AddCurrentlyPlayingToRecentlyPlayed(v3->m_curStation);
              v9 = UFG::RadioStation::GetNextTrack(v3->m_curStation);
            }
            v10 = UFG::AudioEntity::CreateAndPlayEvent(
                    (UFG::AudioEntity *)&v3->vfptr,
                    v9,
                    &v3->m_ecRadio,
                    &pInitParams,
                    0,
                    0i64);
            *((_BYTE *)v3 + 344) &= 0xFDu;
            *((_BYTE *)v3 + 344) |= 2 * (v10 & 1);
            v11 = UFG::UIHKScreenHud::getInstance();
            if ( v11 )
              UFG::UIHKRadioStationWidget::HandleNewSong(&v11->RadioStationWidget);
            if ( *((_BYTE *)v3 + 344) < 0 )
            {
              v12 = v3->m_curStation;
              v13 = v12->m_currentlyPlaying;
              if ( v13 )
              {
                if ( *((_BYTE *)v13 + 36) & 1 )
                {
                  v14 = v3->m_ecRadio.m_pEvent;
                  if ( v14 )
                    v14->vfptr->SeekMS(v14, (signed int)(float)(v12->m_currentTrackTimer * 1000.0));
                  *((_BYTE *)v3 + 344) &= 0x7Fu;
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
char __fastcall UFG::Radio::StopTrack(UFG::Radio *this, unsigned int fadeOut)
{
  UFG::AudioEvent *v2; // rax

  v2 = this->m_ecRadio.m_pEvent;
  *((_BYTE *)this + 344) &= 0xFDu;
  if ( !v2 )
    return 1;
  *((_BYTE *)this + 345) |= 1u;
  UFG::AudioEvent::StopAndForget(v2, fadeOut);
  return 0;
}

// File Line: 1498
// RVA: 0x68D2F0
void __fastcall UFG::Radio::TrackFinishCallback(UFG::Radio *this, __int64 in_eType, UFG::AudioEvent *in_pEvent, void *in_pCallbackInfo)
{
  char v4; // al
  UFG::RadioStation *v5; // rax
  UFG::AudioEvent *v6; // rax
  UFG::AudioEntityVtbl *v7; // rax

  if ( (_DWORD)in_eType == 2 && !(*((_BYTE *)this + 344) & 4) )
  {
    v4 = *((_BYTE *)this + 345);
    if ( v4 & 1 )
    {
      *((_BYTE *)this + 345) = v4 & 0xFE;
    }
    else
    {
      v5 = this->m_curStation;
      if ( v5 )
        v5->m_currentTrackTimer = 0.0;
    }
    v6 = this->m_ecRadio.m_pEvent;
    if ( !v6 || !((*((_BYTE *)v6 + 144) >> 6) & 1) )
    {
      v7 = this->vfptr;
      *((_BYTE *)this + 344) &= 0xFDu;
      LOBYTE(in_eType) = 1;
      ((void (__fastcall *)(UFG::Radio *, __int64, UFG::AudioEvent *, void *))v7[1].DestroyAllEvents)(
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
  UFG::TiDo *v3; // rax
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
  UFG::AudioEntity::SetRtpcValue((UFG::AudioEntity *)&this->vfptr, UFG::Radio::sm_radioVolumeRtpcId, v2);
  v3 = UFG::TiDo::GetInstance();
  UFG::TiDo::SetWwiseRtpcValue(v3, UFG::Radio::sm_radioVolumeRtpcId, UFG::Radio::s_volume, 0xFFFFFFFFFFFFFFFFui64);
  v4 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v4, VolumeCarMusic, (signed int)UFG::Radio::s_volume);
}

// File Line: 1546
// RVA: 0x67D430
void __fastcall UFG::Radio::IncreaseRadioVolume(UFG::Radio *this)
{
  float v1; // xmm2_4
  UFG::Radio *v2; // rbx

  v1 = UFG::Radio::s_volume;
  v2 = this;
  if ( UFG::Radio::s_volume == 0.0 )
  {
    UFG::Radio::PlayClick(this);
    v1 = UFG::Radio::s_volume;
  }
  UFG::Radio::SetRadioVolume(v2, UFG::Radio::s_volumeRate + v1);
}

// File Line: 1558
// RVA: 0x676250
void __fastcall UFG::Radio::DecreaseRadioVolume(UFG::Radio *this)
{
  float v1; // xmm6_4
  UFG::Radio *v2; // rbx

  v1 = UFG::Radio::s_volume;
  v2 = this;
  UFG::Radio::SetRadioVolume(this, UFG::Radio::s_volume - UFG::Radio::s_volumeRate);
  if ( v1 > 0.0 && UFG::Radio::s_volume == 0.0 )
    UFG::Radio::PlayClick(v2);
}

// File Line: 1572
// RVA: 0x68DE80
void __fastcall UFG::Radio::TurnOffRadio(UFG::Radio *this, bool playClick)
{
  UFG::Radio *v2; // rbx
  UFG::UIHKScreenHud *v3; // rax

  v2 = this;
  if ( !(*((_BYTE *)this + 344) & 4) )
  {
    UFG::AudioEntity::SetWwiseState((UFG::TiDo *)this, ms_player_radio.mUID, radio_off.mUID);
    UFG::GameStatAction::Radio::Stop(v2->m_curStation);
    *((_BYTE *)v2 + 344) = *((_BYTE *)v2 + 344) & 0xFE | 0x84;
    ((void (__fastcall *)(UFG::Radio *, signed __int64))v2->vfptr[1].StopAndForgetAllEvents)(v2, 500i64);
    v3 = UFG::UIHKScreenHud::getInstance();
    if ( v3 )
      UFG::UIHKRadioStationWidget::OnRadioTurnedOff(&v3->RadioStationWidget);
  }
}

// File Line: 1599
// RVA: 0x68E9D0
void __fastcall UFG::Radio::TurnOnRadio(UFG::Radio *this)
{
  UFG::Radio *v1; // rbx
  UFG::GameStatTracker *v2; // rax
  signed int v3; // eax
  float v4; // xmm1_4

  v1 = this;
  if ( *((_BYTE *)this + 344) & 4 )
  {
    UFG::AudioEntity::SetWwiseState((UFG::TiDo *)this, ms_player_radio.mUID, radio_on.mUID);
    UFG::GameStatAction::Radio::Start();
    v2 = UFG::GameStatTracker::Instance();
    v3 = UFG::GameStatTracker::GetStat(v2, VolumeCarMusic);
    UFG::Radio::SetRadioVolume(v1, (float)v3);
    v4 = v1->m_timeSinceRadioStopped;
    *((_BYTE *)v1 + 344) = *((_BYTE *)v1 + 344) & 0xFB | 1;
    UFG::Radio::AdvanceAllStations(v1, v4);
    ((void (__fastcall *)(UFG::Radio *, _QWORD))v1->vfptr[1].DestroyAllEvents)(v1, 0i64);
  }
}

// File Line: 1624
// RVA: 0x686D20
void __fastcall UFG::Radio::PlayClick(UFG::Radio *this)
{
  UFG::Radio *v1; // rbx
  unsigned int v2; // eax

  v1 = this;
  if ( _S18_7 & 1 )
  {
    v2 = uiClickId_0;
  }
  else
  {
    _S18_7 |= 1u;
    v2 = UFG::TiDo::CalcWwiseUid("play_ui_click");
    uiClickId_0 = v2;
  }
  UFG::AudioEntity::CreateAndPlayEvent((UFG::AudioEntity *)&v1->vfptr, v2, 0i64, 0, 0i64);
}

// File Line: 1631
// RVA: 0x687500
bool __fastcall UFG::Radio::PlayerInVehicle(UFG::Radio *this)
{
  unsigned __int16 v2; // dx
  unsigned int v3; // edx
  bool v4; // zf

  if ( !LocalPlayer )
    return 0;
  v2 = LocalPlayer->m_Flags;
  if ( (v2 >> 14) & 1 )
    return LocalPlayer->m_Components.p[44].m_pComponent != 0i64;
  if ( (v2 & 0x8000u) != 0 || (v2 >> 13) & 1 )
  {
    v3 = UFG::CharacterOccupantComponent::_TypeUID;
    return UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, v3) != 0i64;
  }
  v4 = ((v2 >> 12) & 1) == 0;
  v3 = UFG::CharacterOccupantComponent::_TypeUID;
  if ( !v4 )
    return UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, v3) != 0i64;
  return UFG::SimObject::GetComponentOfType(
           (UFG::SimObject *)&LocalPlayer->vfptr,
           UFG::CharacterOccupantComponent::_TypeUID) != 0i64;
}

// File Line: 1646
// RVA: 0x669F10
void __fastcall UFG::RadioFullyControlled::RadioFullyControlled(UFG::RadioFullyControlled *this)
{
  UFG::RadioFullyControlled *v1; // rbx

  v1 = this;
  UFG::Radio::Radio((UFG::Radio *)&this->vfptr);
  v1->vfptr = (UFG::AudioEntityVtbl *)&UFG::RadioFullyControlled::`vftable';
  v1->m_pVehAudComponent = 0i64;
  UFG::Radio::SetupParams((UFG::Radio *)&v1->vfptr, -1);
}

// File Line: 1674
// RVA: 0x67D470
void __fastcall UFG::RadioFullyControlled::Init(UFG::RadioFullyControlled *this, UFG::qSymbol *name)
{
  UFG::RadioFullyControlled *v2; // rbx
  UFG::qSymbol *v3; // rax
  UFG::qSymbol result; // [rsp+40h] [rbp+18h]

  v2 = this;
  v3 = UFG::qSymbol::create_from_string(&result, "Player_Radio");
  UFG::AudioEntity::Init((UFG::AudioEntity *)&v2->vfptr, v3, &UFG::qMatrix44::msIdentity);
}

// File Line: 1691
// RVA: 0x681EC0
void __fastcall UFG::RadioFullyControlled::NextTrack(UFG::RadioFullyControlled *this)
{
  UFG::RadioFullyControlled *v1; // rbx
  __int64 v2; // rdx

  v1 = this;
  if ( !((unsigned __int8 (__fastcall *)(UFG::RadioFullyControlled *, signed __int64))this->vfptr[1].StopAndForgetAllEvents)(
          this,
          500i64) )
  {
    LOBYTE(v2) = 1;
    ((void (__fastcall *)(UFG::RadioFullyControlled *, __int64))v1->vfptr[1].DestroyAllEvents)(v1, v2);
  }
}

// File Line: 1702
// RVA: 0x68EA60
void __fastcall UFG::RadioFullyControlled::TurnOnRadio(UFG::RadioFullyControlled *this)
{
  UFG::RadioFullyControlled *v1; // rdi
  UFG::RadioStation *v2; // rbx

  v1 = this;
  if ( this->m_radioType == 1 )
  {
    UFG::Radio::TurnOnRadio((UFG::Radio *)&this->vfptr);
    v2 = v1->m_curStation;
    UFG::Radio::NextStation((UFG::Radio *)&v1->vfptr, 0);
    UFG::RadioFullyControlled::SetupScannerAndRadio(v1, v2, v1->m_curStation);
  }
  if ( v1->m_radioType == eRadioType_Radio )
    UFG::Radio::TurnOnRadio((UFG::Radio *)&v1->vfptr);
  if ( v1->m_radioType == 2 )
  {
    UFG::Radio::TurnOnRadio((UFG::Radio *)&v1->vfptr);
    UFG::RadioFullyControlled::SetupScannerAndRadio(v1, v1->m_curStation, v1->m_curStation);
  }
  *((_BYTE *)&v1->0 + 344) = *((_BYTE *)&v1->0 + 344) & 0xFB | 1;
}

// File Line: 1725
// RVA: 0x68DEF0
void __fastcall UFG::RadioFullyControlled::TurnOffRadio(UFG::RadioFullyControlled *this, bool playClick)
{
  UFG::RadioFullyControlled *v2; // rbx

  v2 = this;
  if ( this->m_radioType == 1 )
  {
    if ( UFG::PoliceScannerAudio::IsOwnedBy(&UFG::PoliceScannerAudio::sm_Instance, (UFG::AudioEntity *)&this->vfptr) )
    {
      UFG::PoliceScannerAudio::DetachFromAudioEntity(
        &UFG::PoliceScannerAudio::sm_Instance,
        (UFG::AudioEntity *)&v2->vfptr);
      UFG::PoliceScannerAudio::Enable(&UFG::PoliceScannerAudio::sm_Instance, 0);
    }
    UFG::Radio::TurnOffRadio((UFG::Radio *)&v2->vfptr, 1);
  }
  if ( v2->m_radioType == eRadioType_Radio )
    UFG::Radio::TurnOffRadio((UFG::Radio *)&v2->vfptr, 1);
  if ( v2->m_radioType == 2 )
  {
    if ( UFG::PoliceScannerAudio::IsOwnedBy(&UFG::PoliceScannerAudio::sm_Instance, (UFG::AudioEntity *)&v2->vfptr) )
    {
      UFG::PoliceScannerAudio::DetachFromAudioEntity(
        &UFG::PoliceScannerAudio::sm_Instance,
        (UFG::AudioEntity *)&v2->vfptr);
      UFG::PoliceScannerAudio::Enable(&UFG::PoliceScannerAudio::sm_Instance, 0);
    }
    else
    {
      UFG::Radio::TurnOffRadio((UFG::Radio *)&v2->vfptr, 1);
    }
  }
  *((_BYTE *)&v2->0 + 344) &= 0xFEu;
  *((_BYTE *)&v2->0 + 344) |= 4u;
}

// File Line: 1760
// RVA: 0x68BAD0
void __fastcall UFG::RadioFullyControlled::SetupScannerAndRadio(UFG::RadioFullyControlled *this, UFG::RadioStation *prevStation, UFG::RadioStation *curStation)
{
  bool v3; // al
  UFG::RadioStation *v4; // rbx
  UFG::RadioStation *v5; // rdi
  UFG::RadioFullyControlled *v6; // rsi

  v3 = curStation->m_bIsCopScannerStation;
  v4 = curStation;
  v5 = prevStation;
  v6 = this;
  if ( prevStation )
  {
    if ( !v3 )
      goto LABEL_9;
    if ( !prevStation->m_bIsCopScannerStation )
      goto LABEL_8;
  }
  else if ( v3 )
  {
LABEL_8:
    UFG::PoliceScannerAudio::AttachToAudioEntity(&UFG::PoliceScannerAudio::sm_Instance, (UFG::AudioEntity *)&v6->vfptr);
    UFG::PoliceScannerAudio::Enable(&UFG::PoliceScannerAudio::sm_Instance, 1);
    goto LABEL_9;
  }
  if ( v3
    && !UFG::PoliceScannerAudio::IsOwnedBy(&UFG::PoliceScannerAudio::sm_Instance, (UFG::AudioEntity *)&this->vfptr) )
  {
    goto LABEL_8;
  }
LABEL_9:
  if ( !v5 )
  {
    if ( v4->m_bIsCopScannerStation )
      return;
    goto LABEL_14;
  }
  if ( !v4->m_bIsCopScannerStation && v5->m_bIsCopScannerStation )
  {
LABEL_14:
    if ( UFG::PoliceScannerAudio::IsOwnedBy(&UFG::PoliceScannerAudio::sm_Instance, (UFG::AudioEntity *)&v6->vfptr) )
    {
      UFG::PoliceScannerAudio::DetachFromAudioEntity(
        &UFG::PoliceScannerAudio::sm_Instance,
        (UFG::AudioEntity *)&v6->vfptr);
      UFG::PoliceScannerAudio::Enable(&UFG::PoliceScannerAudio::sm_Instance, 0);
    }
  }
}

// File Line: 1785
// RVA: 0x681E80
void __fastcall UFG::RadioFullyControlled::NextStation(UFG::RadioFullyControlled *this, bool displayStationId)
{
  UFG::RadioStation *v2; // rbx
  UFG::RadioFullyControlled *v3; // rdi

  v2 = this->m_curStation;
  v3 = this;
  UFG::Radio::NextStation((UFG::Radio *)&this->vfptr, displayStationId);
  UFG::RadioFullyControlled::SetupScannerAndRadio(v3, v2, v3->m_curStation);
}

// File Line: 1794
// RVA: 0x687710
void __fastcall UFG::RadioFullyControlled::PrevStation(UFG::RadioFullyControlled *this, bool displayStationId)
{
  UFG::RadioStation *v2; // rbx
  UFG::RadioFullyControlled *v3; // rdi

  v2 = this->m_curStation;
  v3 = this;
  UFG::Radio::PrevStation((UFG::Radio *)&this->vfptr, displayStationId);
  UFG::RadioFullyControlled::SetupScannerAndRadio(v3, v2, v3->m_curStation);
}

// File Line: 1803
// RVA: 0x670AB0
void __usercall UFG::RadioFullyControlled::AudioEntityUpdate(UFG::RadioFullyControlled *this@<rcx>, float delta_sec@<xmm1>, __int64 a3@<rdx>)
{
  UFG::RadioFullyControlled *v3; // rbx
  float v4; // xmm6_4
  UFG::VehicleAudioComponent *v5; // rax
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // eax
  UFG::VehicleAudioComponent *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm2_4

  v3 = this;
  v4 = delta_sec;
  if ( !this->m_pVehAudComponent && *((_BYTE *)&this->0 + 344) & 2 )
  {
    LOBYTE(a3) = 1;
    ((void (__fastcall *)(UFG::RadioFullyControlled *, __int64))this->vfptr[1].CountNumPlayingEvents)(this, a3);
  }
  v5 = v3->m_pVehAudComponent;
  if ( v5 )
  {
    v6 = v5->m_WorldMatrix.v3.y;
    v7 = v5->m_WorldMatrix.v3.z;
    v8 = v5->m_WorldMatrix.v3.x;
    v3->m_WorldMatrix.v3.w = 1.0;
    v3->m_WorldMatrix.v3.x = v8;
    v3->m_WorldMatrix.v3.y = v6;
    v3->m_WorldMatrix.v3.z = v7;
    UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&v3->vfptr);
  }
  if ( v3->m_pVehAudComponent
    && UFG::PoliceScannerAudio::IsOwnedBy(&UFG::PoliceScannerAudio::sm_Instance, (UFG::AudioEntity *)&v3->vfptr) )
  {
    v9 = v3->m_pVehAudComponent;
    v10 = v9->m_WorldMatrix.v3.y;
    v11 = v9->m_WorldMatrix.v3.z;
    unk_14242F140 = LODWORD(v9->m_WorldMatrix.v3.x);
    unk_14242F144 = LODWORD(v10);
    unk_14242F14C = (_DWORD)FLOAT_1_0;
    unk_14242F148 = LODWORD(v11);
    UFG::AudioEntity::ForcePositionUpdate((UFG::AudioEntity *)&UFG::PoliceScannerAudio::sm_Instance.vfptr);
  }
  UFG::AudioEntity::AudioEntityUpdate((UFG::AudioEntity *)&v3->vfptr, v4);
}

// File Line: 1894
// RVA: 0x6743D0
void __fastcall UFG::Radio::ClearAllPlaylists(UFG::Radio *this)
{
  UFG::RadioStation *i; // rbx
  UFG::qList<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset>,1,0> *j; // rax
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v3; // rdx
  UFG::qNode<UFG::qPointerNode<UFG::RadioStationAsset>,UFG::qPointerNode<UFG::RadioStationAsset> > *v4; // rcx
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
        v3 = j->mNode.mPrev;
        v4 = j->mNode.mNext;
        v3->mNext = v4;
        v4->mPrev = v3;
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
  UFG::RadioStation *v1; // rax
  char *result; // rax

  v1 = this->m_curStation;
  if ( v1->m_currentlyPlaying )
    result = v1->m_currentlyPlayingAssetName.mData;
  else
    result = &customWorldMapCaption;
  return result;
}

