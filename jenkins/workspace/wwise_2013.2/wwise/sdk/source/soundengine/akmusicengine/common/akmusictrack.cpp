// File Line: 37
// RVA: 0xAB2CA0
void __fastcall CAkMusicTrack::CAkMusicTrack(CAkMusicTrack *this, unsigned int in_ulID)
{
  CAkMusicTrack *v2; // rbx

  v2 = this;
  CAkSoundBase::CAkSoundBase((CAkSoundBase *)&this->vfptr, in_ulID);
  v2->vfptr = (CAkIndexableVtbl *)&CAkMusicTrack::`vftable;
  v2->m_arSrcInfo.m_pItems = 0i64;
  *(_QWORD *)&v2->m_arSrcInfo.m_uLength = 0i64;
  v2->m_arClipAutomation.m_pItems = 0i64;
  *(_QWORD *)&v2->m_arClipAutomation.m_uLength = 0i64;
  v2->m_uNumSubTrack = 0;
  v2->m_arTrackPlaylist.m_pItems = 0i64;
  *(_QWORD *)&v2->m_arTrackPlaylist.m_uLength = 0i64;
  *(_QWORD *)&v2->m_iLookAheadTime = 0i64;
  v2->m_SequenceIndex = -1;
}

// File Line: 41
// RVA: 0xAB2D10
void __fastcall CAkMusicTrack::~CAkMusicTrack(CAkMusicTrack *this)
{
  CAkMusicTrack *v1; // rbx
  MapStruct<unsigned long,CAkMusicSource *> *v2; // rdx
  AkTrackSrc *v3; // rdx

  v1 = this;
  this->vfptr = (CAkIndexableVtbl *)&CAkMusicTrack::`vftable;
  CAkMusicTrack::RemoveAllSourcesNoCheck(this);
  v2 = v1->m_arSrcInfo.m_pItems;
  if ( v2 )
  {
    v1->m_arSrcInfo.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
    v1->m_arSrcInfo.m_pItems = 0i64;
    v1->m_arSrcInfo.m_ulReserved = 0;
  }
  v3 = v1->m_arTrackPlaylist.m_pItems;
  if ( v3 )
  {
    v1->m_arTrackPlaylist.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v3);
    v1->m_arTrackPlaylist.m_pItems = 0i64;
    v1->m_arTrackPlaylist.m_ulReserved = 0;
  }
  CAkMusicTrack::ClipAutomationArray::Term(&v1->m_arClipAutomation);
  CAkSoundBase::~CAkSoundBase((CAkSoundBase *)&v1->vfptr);
}

// File Line: 53
// RVA: 0xAB31C0
void __fastcall CAkMusicTrack::Create(unsigned int in_ulID)
{
  unsigned int v1; // ebx
  CAkMusicTrack *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  unsigned int v5; // eax
  signed int v6; // ecx
  bool v7; // al

  v1 = in_ulID;
  v2 = (CAkMusicTrack *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xE0ui64);
  if ( v2 )
  {
    CAkMusicTrack::CAkMusicTrack(v2, v1);
    v4 = v3;
    if ( v3 )
    {
      v5 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 112i64))(v3);
      v7 = 0;
      if ( v5 <= 0xC )
      {
        v6 = 5121;
        if ( _bittest(&v6, v5) )
          v7 = 1;
      }
      *(_BYTE *)(v4 + 83) &= 0xFDu;
      *(_BYTE *)(v4 + 83) |= 2 * v7;
      CAkParameterNodeBase::AddToIndex((CAkParameterNodeBase *)v4);
    }
  }
}

// File Line: 67
// RVA: 0xAB39E0
signed __int64 __fastcall CAkMusicTrack::SetInitialValues(CAkMusicTrack *this, char *in_pData, unsigned int in_ulDataSize, CAkUsageSlot *__formal, bool in_bIsPartialLoadOnly)
{
  char *v5; // rdx
  CAkMusicTrack *v6; // r14
  unsigned int v7; // esi
  char *v8; // rdx
  AKRESULT v9; // ebx
  int v10; // edi
  signed __int64 result; // rax
  AKRESULT v12; // eax
  __int64 v13; // rdi
  AkTrackSrcInfo *v14; // rax
  AkTrackSrcInfo *v15; // rsi
  unsigned int v16; // er9
  signed __int64 v17; // r10
  signed __int64 v18; // rdx
  unsigned int v19; // eax
  __int64 v20; // r8
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  __int64 v23; // xmm0_8
  __int64 v24; // xmm1_8
  __int64 v25; // xmm0_8
  __int64 v26; // xmm1_8
  unsigned int v27; // ecx
  unsigned int v28; // ecx
  __int64 v29; // xmm0_8
  __int64 v30; // xmm1_8
  __int64 v31; // xmm0_8
  __int64 v32; // xmm1_8
  unsigned int v33; // ecx
  unsigned int v34; // ecx
  __int64 v35; // xmm0_8
  __int64 v36; // xmm1_8
  __int64 v37; // xmm0_8
  __int64 v38; // xmm1_8
  unsigned int v39; // ecx
  unsigned int v40; // ecx
  __int64 v41; // xmm0_8
  __int64 v42; // xmm1_8
  __int64 v43; // xmm0_8
  __int64 v44; // xmm1_8
  signed __int64 v45; // r8
  __int64 v46; // r9
  unsigned int v47; // ecx
  unsigned int v48; // ecx
  __int64 v49; // xmm0_8
  __int64 v50; // xmm1_8
  __int64 v51; // xmm0_8
  __int64 v52; // xmm1_8
  unsigned int v53; // er9
  CAkMusicTrack::ClipAutomationArray *v54; // rbx
  __int64 v55; // r15
  CAkClipAutomation *v56; // rax
  unsigned int v57; // esi
  char *v58; // r8
  unsigned __int64 v59; // rdi
  bool v60; // al
  __int64 v61; // rdx
  signed __int64 v62; // rcx
  unsigned int v63; // edx
  char *v64; // r8
  AkClipAutomationType v65; // eax
  __int64 in_uNumPoints; // rdi
  bool v67; // bl
  unsigned int v68; // edi
  char *v69; // rcx
  AkMusicTrackRanSeqType v70; // eax
  int v71; // edx
  __int128 v72; // [rsp+30h] [rbp-50h]
  int v73; // [rsp+40h] [rbp-40h]
  AkBankSourceData out_rSource; // [rsp+50h] [rbp-30h]
  char *io_pData; // [rsp+B8h] [rbp+38h]
  unsigned int io_ulDataSize; // [rsp+C0h] [rbp+40h]

  io_ulDataSize = in_ulDataSize;
  v5 = in_pData + 4;
  v6 = this;
  io_pData = v5;
  v7 = *(_DWORD *)v5;
  v8 = v5 + 4;
  v9 = 1;
  io_pData = v8;
  v10 = 0;
  if ( v7 )
  {
    while ( 1 )
    {
      if ( v9 == 1 )
      {
        result = CAkBankMgr::LoadSource(&io_pData, &io_ulDataSize, &out_rSource);
        if ( (_DWORD)result != 1 )
          return result;
        if ( out_rSource.m_pParam )
        {
          v12 = (unsigned int)CAkMusicTrack::AddPluginSource(v6, out_rSource.m_MediaInfo.sourceID);
        }
        else
        {
          v73 = *((_DWORD *)&out_rSource.m_MediaInfo + 4);
          v72 = *(_OWORD *)&out_rSource.m_MediaInfo.sourceID;
          v12 = (unsigned int)CAkMusicTrack::AddSource(
                                v6,
                                _mm_cvtsi128_si32(*(__m128i *)&out_rSource.m_MediaInfo.sourceID),
                                out_rSource.m_PluginID,
                                (AkMediaInformation *)&v72);
        }
        v9 = v12;
        if ( v12 != 1 )
          break;
      }
      if ( ++v10 >= v7 )
      {
        v8 = io_pData;
        goto LABEL_10;
      }
    }
    result = 2i64;
  }
  else
  {
LABEL_10:
    v13 = *(unsigned int *)v8;
    io_pData = v8 + 4;
    if ( (_DWORD)v13 )
    {
      v14 = (AkTrackSrcInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 40 * v13);
      v15 = v14;
      if ( !v14 )
        return 52i64;
      v16 = 0;
      v17 = 0i64;
      if ( (signed int)v13 >= 4 )
      {
        v18 = (signed __int64)&v14->fPlayAt;
        v19 = ((unsigned int)(v13 - 4) >> 2) + 1;
        v20 = v19;
        v16 = 4 * v19;
        v17 = 4i64 * v19;
        do
        {
          v21 = *(_DWORD *)io_pData;
          io_pData += 4;
          *(_DWORD *)(v18 - 8) = v21;
          v22 = *(_DWORD *)io_pData;
          io_pData += 4;
          *(_DWORD *)(v18 - 4) = v22;
          v23 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)v18 = v23;
          v24 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 + 8) = v24;
          v25 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 + 16) = v25;
          v26 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 + 24) = v26;
          v27 = *(_DWORD *)io_pData;
          io_pData += 4;
          *(_DWORD *)(v18 + 32) = v27;
          v28 = *(_DWORD *)io_pData;
          io_pData += 4;
          *(_DWORD *)(v18 + 36) = v28;
          v29 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 + 40) = v29;
          v30 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 + 48) = v30;
          v31 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 + 56) = v31;
          v32 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 + 64) = v32;
          v33 = *(_DWORD *)io_pData;
          io_pData += 4;
          *(_DWORD *)(v18 + 72) = v33;
          v34 = *(_DWORD *)io_pData;
          io_pData += 4;
          *(_DWORD *)(v18 + 76) = v34;
          v35 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 + 80) = v35;
          v36 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 + 88) = v36;
          v37 = *(_QWORD *)io_pData;
          v18 += 160i64;
          io_pData += 8;
          *(_QWORD *)(v18 - 64) = v37;
          v38 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 - 56) = v38;
          v39 = *(_DWORD *)io_pData;
          io_pData += 4;
          *(_DWORD *)(v18 - 48) = v39;
          v40 = *(_DWORD *)io_pData;
          io_pData += 4;
          *(_DWORD *)(v18 - 44) = v40;
          v41 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 - 40) = v41;
          v42 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 - 32) = v42;
          v43 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 - 24) = v43;
          v44 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v18 - 16) = v44;
          --v20;
        }
        while ( v20 );
      }
      if ( v16 < (unsigned int)v13 )
      {
        v45 = (signed __int64)v15 + 8 * (v17 + 4 * v17 + 1);
        v46 = (unsigned int)v13 - v16;
        do
        {
          v45 += 40i64;
          v47 = *(_DWORD *)io_pData;
          io_pData += 4;
          *(_DWORD *)(v45 - 48) = v47;
          v48 = *(_DWORD *)io_pData;
          io_pData += 4;
          *(_DWORD *)(v45 - 44) = v48;
          v49 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v45 - 40) = v49;
          v50 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v45 - 32) = v50;
          v51 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v45 - 24) = v51;
          v52 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)(v45 - 16) = v52;
          --v46;
        }
        while ( v46 );
      }
      v53 = *(_DWORD *)io_pData;
      io_pData += 4;
      v9 = CAkMusicTrack::SetPlayList(v6, v13, v15, v53);
      AK::MemoryMgr::Free(g_DefaultPoolId, v15);
    }
    if ( v9 != 1 )
      return (unsigned int)v9;
    v54 = &v6->m_arClipAutomation;
    CAkMusicTrack::ClipAutomationArray::Term(&v6->m_arClipAutomation);
    v55 = *(unsigned int *)io_pData;
    io_pData += 4;
    if ( (_DWORD)v55 )
    {
      v56 = (CAkClipAutomation *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v55);
      v54->m_pItems = v56;
      if ( !v56 )
        return 2i64;
      v6->m_arClipAutomation.m_ulReserved = v55;
      v57 = 0;
      if ( (_DWORD)v55 )
      {
        v58 = io_pData;
        do
        {
          v59 = v6->m_arClipAutomation.m_uLength;
          if ( (v59 < v6->m_arClipAutomation.m_ulReserved
             || (v60 = AkArray<CAkClipAutomation,CAkClipAutomation const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
                         (AkArray<CAkClipAutomation,CAkClipAutomation const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)&v6->m_arClipAutomation.m_pItems,
                         1u),
                 v58 = io_pData,
                 v60))
            && v59 < v6->m_arClipAutomation.m_ulReserved )
          {
            v61 = v6->m_arClipAutomation.m_uLength;
            v62 = (signed __int64)&v54->m_pItems[v61];
            v6->m_arClipAutomation.m_uLength = v61 + 1;
            if ( v62 )
            {
              *(_QWORD *)(v62 + 8) = 0i64;
              *(_QWORD *)(v62 + 16) = 0i64;
              v58 = io_pData;
            }
          }
          else
          {
            v62 = 0i64;
          }
          v63 = *(_DWORD *)v58;
          v64 = v58 + 4;
          io_pData = v64;
          v65 = *(_DWORD *)v64;
          v64 += 4;
          io_pData = v64;
          in_uNumPoints = *(unsigned int *)v64;
          v58 = v64 + 4;
          io_pData = v58;
          if ( (_DWORD)in_uNumPoints )
          {
            if ( (unsigned int)CAkClipAutomation::Set(
                                 (CAkClipAutomation *)v62,
                                 v63,
                                 v65,
                                 (AkRTPCGraphPointBase<float> *)v58,
                                 in_uNumPoints) != 1 )
              return 2i64;
            v58 = &io_pData[12 * in_uNumPoints];
            io_pData += 12 * in_uNumPoints;
          }
          ++v57;
        }
        while ( v57 < (unsigned int)v55 );
      }
    }
    v67 = in_bIsPartialLoadOnly;
    result = CAkParameterNodeBase::SetNodeBaseParams(
               (CAkParameterNodeBase *)&v6->vfptr,
               &io_pData,
               &io_ulDataSize,
               in_bIsPartialLoadOnly);
    v68 = result;
    if ( !v67 )
    {
      if ( (_DWORD)result == 1 )
      {
        v69 = io_pData + 4;
        v70 = *(_DWORD *)io_pData;
        io_pData = v69;
        v69 += 4;
        v6->m_eRSType = v70;
        v71 = *((_DWORD *)v69 - 1);
        io_pData = v69;
        CAkMusicTrack::LookAheadTime(v6, v71);
      }
      result = v68;
    }
  }
  return result;
}

// File Line: 185
// RVA: 0xAB3230
signed __int64 __fastcall CAkMusicTrack::ExecuteAction(CAkMusicTrack *this, ActionParams *in_rAction)
{
  if ( in_rAction->bIsMasterCall )
  {
    LOBYTE(in_rAction) = in_rAction->eType == 1;
    ((void (__fastcall *)(CAkMusicTrack *, ActionParams *))this->vfptr[10].Category)(this, in_rAction);
  }
  return 1i64;
}

// File Line: 199
// RVA: 0xAB3260
signed __int64 __fastcall CAkMusicTrack::ExecuteActionExcept(CAkMusicTrack *this, ActionParamsExcept *in_rAction)
{
  if ( !in_rAction->pGameObj )
  {
    LOBYTE(in_rAction) = in_rAction->eType == 1;
    ((void (__fastcall *)(CAkMusicTrack *, ActionParamsExcept *))this->vfptr[10].Category)(this, in_rAction);
  }
  return 1i64;
}

// File Line: 216
// RVA: 0xAB2DD0
signed __int64 __fastcall CAkMusicTrack::AddPlaylistItem(CAkMusicTrack *this, AkTrackSrcInfo *in_srcInfo)
{
  AkTrackSrcInfo *v2; // rdi
  double v3; // xmm6_8
  AkArray<AkTrackSrc,AkTrackSrc const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *v5; // rbx
  unsigned __int64 v6; // rsi
  __int64 v7; // rdx
  unsigned int *v8; // r8
  double v9; // xmm0_8
  double v10; // xmm3_8
  double v11; // xmm1_8
  double v12; // xmm3_8
  double v13; // xmm1_8
  double v14; // xmm3_8
  double v15; // xmm1_8
  signed int v16; // ecx
  double v17; // xmm1_8
  int v18; // edx

  v2 = in_srcInfo;
  v3 = in_srcInfo->fEndTrimOffset + in_srcInfo->fSrcDuration - in_srcInfo->fBeginTrimOffset;
  if ( v3 <= 0.0 )
    return 1i64;
  v5 = &this->m_arTrackPlaylist;
  v6 = this->m_arTrackPlaylist.m_uLength;
  if ( v6 >= this->m_arTrackPlaylist.m_ulReserved
    && !AkArray<AkTrackSrc,AkTrackSrc const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
          &this->m_arTrackPlaylist,
          1u) )
  {
    return 2i64;
  }
  if ( v6 >= v5->m_ulReserved )
    return 2i64;
  v7 = v5->m_uLength;
  v8 = &v5->m_pItems[v7].uSubTrackIndex;
  v5->m_uLength = v7 + 1;
  if ( !v8 )
    return 2i64;
  *v8 = v2->trackID;
  v8[1] = v2->sourceID;
  v9 = DOUBLE_0_5;
  v10 = (v2->fPlayAt + v2->fBeginTrimOffset) * (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * 0.001;
  if ( v10 <= 0.0 )
    v11 = DOUBLE_N0_5;
  else
    v11 = DOUBLE_0_5;
  v8[2] = (signed int)(v11 + v10);
  v12 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * v3 * 0.001;
  if ( v12 <= 0.0 )
    v13 = DOUBLE_N0_5;
  else
    v13 = DOUBLE_0_5;
  v8[3] = (signed int)(v13 + v12);
  v14 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * v2->fSrcDuration * 0.001;
  if ( v14 <= 0.0 )
    v15 = DOUBLE_N0_5;
  else
    v15 = DOUBLE_0_5;
  v16 = (signed int)(v15 + v14);
  v8[4] = v16;
  v17 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * v2->fBeginTrimOffset * 0.001;
  if ( v17 <= 0.0 )
    v9 = DOUBLE_N0_5;
  v18 = (signed int)(v9 + v17) % v16;
  v8[5] = v18;
  if ( v18 < 0 )
    v8[5] = v18 + v16;
  return 1i64;
}

// File Line: 253
// RVA: 0xAB3F50
signed __int64 __fastcall CAkMusicTrack::SetPlayList(CAkMusicTrack *this, unsigned int in_uNumPlaylistItem, AkTrackSrcInfo *in_pArrayPlaylistItems, unsigned int in_uNumSubTrack)
{
  __int64 v4; // rsi
  AkTrackSrc *v5; // rdx
  unsigned int v6; // ebp
  AkTrackSrcInfo *v7; // rbx
  CAkMusicTrack *v8; // rdi
  AkTrackSrc *v9; // rax

  v4 = in_uNumPlaylistItem;
  v5 = this->m_arTrackPlaylist.m_pItems;
  v6 = in_uNumSubTrack;
  v7 = in_pArrayPlaylistItems;
  v8 = this;
  if ( v5 )
  {
    this->m_arTrackPlaylist.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v5);
    v8->m_arTrackPlaylist.m_pItems = 0i64;
    v8->m_arTrackPlaylist.m_ulReserved = 0;
  }
  v8->m_uNumSubTrack = v6;
  if ( !(_DWORD)v4 )
    return 1i64;
  v9 = (AkTrackSrc *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v4);
  v8->m_arTrackPlaylist.m_pItems = v9;
  if ( v9 )
  {
    v8->m_arTrackPlaylist.m_ulReserved = v4;
    if ( (_DWORD)v4 )
    {
      do
      {
        CAkMusicTrack::AddPlaylistItem(v8, v7);
        ++v7;
        --v4;
      }
      while ( v4 );
    }
    return 1i64;
  }
  return 2i64;
}

// File Line: 340
// RVA: 0xAB3070
signed __int64 __fastcall CAkMusicTrack::AddSource(CAkMusicTrack *this, unsigned int in_srcID, unsigned int in_pluginID, AkMediaInformation *in_MediaInfo)
{
  MapStruct<unsigned long,CAkMusicSource *> *v4; // rax
  AkMediaInformation *v5; // rbp
  unsigned int v6; // er12
  unsigned int v7; // edi
  signed __int64 v8; // r11
  CAkMusicTrack *v9; // r15
  MapStruct<unsigned long,CAkMusicSource *> *v10; // r10
  signed __int64 result; // rax
  signed __int64 v12; // rbx
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v13; // rax
  CAkSource *v14; // rax
  CAkSource *v15; // rsi
  __int128 v16; // xmm0
  __int128 v17; // [rsp+20h] [rbp-38h]
  int v18; // [rsp+30h] [rbp-28h]

  v4 = this->m_arSrcInfo.m_pItems;
  v5 = in_MediaInfo;
  v6 = in_pluginID;
  v7 = in_srcID;
  v8 = (signed __int64)&v4[this->m_arSrcInfo.m_uLength];
  v9 = this;
  v10 = this->m_arSrcInfo.m_pItems;
  if ( v4 != (MapStruct<unsigned long,CAkMusicSource *> *)v8 )
  {
    do
    {
      if ( v10->key == in_srcID )
        break;
      ++v10;
    }
    while ( v10 != (MapStruct<unsigned long,CAkMusicSource *> *)v8 );
  }
  if ( v10 != (MapStruct<unsigned long,CAkMusicSource *> *)v8
    && v10 != (MapStruct<unsigned long,CAkMusicSource *> *)-8i64 )
  {
    return 1i64;
  }
  for ( ; v4 != (MapStruct<unsigned long,CAkMusicSource *> *)v8; ++v4 )
  {
    if ( v4->key == in_srcID )
      break;
  }
  if ( v4 == (MapStruct<unsigned long,CAkMusicSource *> *)v8 )
  {
    v12 = 0i64;
  }
  else
  {
    v12 = (signed __int64)&v4->item;
    if ( v4 != (MapStruct<unsigned long,CAkMusicSource *> *)-8i64 )
      goto LABEL_17;
  }
  v13 = AkArray<MapStruct<unsigned long,CAkMusicSource *>,MapStruct<unsigned long,CAkMusicSource *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast((AkArray<MapStruct<CAkRSSub *,CAkContainerBaseInfo *>,MapStruct<CAkRSSub *,CAkContainerBaseInfo *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&this->m_arSrcInfo);
  if ( v13 )
  {
    LODWORD(v13->key) = v7;
    v12 = (signed __int64)&v13->item;
  }
  if ( !v12 )
    return 2i64;
LABEL_17:
  v14 = (CAkSource *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
  v15 = v14;
  if ( v14 )
  {
    CAkSource::CAkSource(v14);
    v15[1].m_sSrcTypeInfo.mediaInfo.sourceID = 0;
  }
  else
  {
    v15 = 0i64;
  }
  *(_QWORD *)v12 = v15;
  if ( v15 )
  {
    v16 = *(_OWORD *)&v5->sourceID;
    v18 = *((_DWORD *)v5 + 4);
    v17 = v16;
    CAkSource::SetSource(v15, v6, (AkMediaInformation *)&v17);
    *(_DWORD *)(*(_QWORD *)v12 + 40i64) = v9->m_iLookAheadTime;
  }
  else
  {
    CAkKeyArray<unsigned long,CAkMusicSource *,4>::Unset(&v9->m_arSrcInfo, v7);
  }
  result = 1i64;
  if ( !*(_QWORD *)v12 )
    return 2i64;
  return result;
}

// File Line: 369
// RVA: 0xAB2F90
signed __int64 __fastcall CAkMusicTrack::AddPluginSource(CAkMusicTrack *this, unsigned int in_srcID)
{
  AkArray<MapStruct<CAkRSSub *,CAkContainerBaseInfo *>,MapStruct<CAkRSSub *,CAkContainerBaseInfo *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *v2; // r14
  unsigned int v3; // esi
  MapStruct<unsigned long,CAkMusicSource *> *v4; // rax
  signed __int64 i; // rcx
  _QWORD *v6; // rbx
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v7; // rax
  CAkSource *v8; // rax
  CAkSource *v9; // rdi
  signed __int64 result; // rax

  v2 = (AkArray<MapStruct<CAkRSSub *,CAkContainerBaseInfo *>,MapStruct<CAkRSSub *,CAkContainerBaseInfo *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&this->m_arSrcInfo;
  v3 = in_srcID;
  v4 = this->m_arSrcInfo.m_pItems;
  for ( i = (signed __int64)&v4[this->m_arSrcInfo.m_uLength]; v4 != (MapStruct<unsigned long,CAkMusicSource *> *)i; ++v4 )
  {
    if ( v4->key == in_srcID )
      break;
  }
  if ( v4 == (MapStruct<unsigned long,CAkMusicSource *> *)i )
  {
    v6 = 0i64;
  }
  else
  {
    v6 = &v4->item;
    if ( v4 != (MapStruct<unsigned long,CAkMusicSource *> *)-8i64 )
      goto LABEL_11;
  }
  v7 = AkArray<MapStruct<unsigned long,CAkMusicSource *>,MapStruct<unsigned long,CAkMusicSource *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast(v2);
  if ( v7 )
  {
    LODWORD(v7->key) = v3;
    v6 = &v7->item;
  }
  if ( !v6 )
    return 2i64;
LABEL_11:
  v8 = (CAkSource *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x30ui64);
  v9 = v8;
  if ( v8 )
  {
    CAkSource::CAkSource(v8);
    v9[1].m_sSrcTypeInfo.mediaInfo.sourceID = 0;
  }
  else
  {
    v9 = 0i64;
  }
  *v6 = v9;
  if ( v9 )
    CAkSource::SetSource(v9, v3);
  else
    CAkKeyArray<unsigned long,CAkMusicSource *,4>::Unset((CAkKeyArray<unsigned long,CAkMusicSource *,4> *)v2, v3);
  result = 1i64;
  if ( !*v6 )
    return 2i64;
  return result;
}

// File Line: 387
// RVA: 0xAB3530
char __fastcall CAkMusicTrack::HasBankSource(CAkMusicTrack *this)
{
  MapStruct<unsigned long,CAkMusicSource *> *v1; // rax
  signed __int64 v2; // r8

  v1 = this->m_arSrcInfo.m_pItems;
  v2 = (signed __int64)&v1[this->m_arSrcInfo.m_uLength];
  if ( v1 == (MapStruct<unsigned long,CAkMusicSource *> *)v2 )
    return 0;
  while ( !((*((_DWORD *)&v1->item->m_sSrcTypeInfo.mediaInfo + 4) >> 7) & 1) )
  {
    ++v1;
    if ( v1 == (MapStruct<unsigned long,CAkMusicSource *> *)v2 )
      return 0;
  }
  return 1;
}

// File Line: 407
// RVA: 0xAB36D0
void __fastcall CAkMusicTrack::RemoveAllSourcesNoCheck(CAkMusicTrack *this)
{
  CAkMusicTrack *v1; // rsi
  MapStruct<unsigned long,CAkMusicSource *> *v2; // rbx
  CAkMusicSource *v3; // rdi
  int v4; // ebp

  v1 = this;
  this->m_uNumSubTrack = 0;
  this->m_arTrackPlaylist.m_uLength = 0;
  v2 = this->m_arSrcInfo.m_pItems;
  if ( v2 == &v2[this->m_arSrcInfo.m_uLength] )
  {
    this->m_arSrcInfo.m_uLength = 0;
  }
  else
  {
    do
    {
      v3 = v2->item;
      v4 = g_DefaultPoolId;
      if ( v3 )
      {
        CAkSource::~CAkSource((CAkSource *)&v2->item->m_sSrcTypeInfo);
        AK::MemoryMgr::Free(v4, v3);
      }
      ++v2;
    }
    while ( v2 != &v1->m_arSrcInfo.m_pItems[v1->m_arSrcInfo.m_uLength] );
    v1->m_arSrcInfo.m_uLength = 0;
  }
}

// File Line: 426
// RVA: 0xAB3570
void __fastcall CAkMusicTrack::LookAheadTime(CAkMusicTrack *this, int in_LookAheadTime)
{
  double v2; // xmm1_8
  double v3; // xmm0_8
  MapStruct<unsigned long,CAkMusicSource *> *v4; // rax
  CAkMusicSource *v5; // rdx

  v2 = (float)((float)in_LookAheadTime * CAkMusicRenderer::m_musicSettings.fStreamingLookAheadRatio)
     * (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency
     * 0.001;
  if ( v2 <= 0.0 )
    v3 = DOUBLE_N0_5;
  else
    v3 = DOUBLE_0_5;
  this->m_iLookAheadTime = (signed int)(v3 + v2);
  v4 = this->m_arSrcInfo.m_pItems;
  if ( v4 != &v4[this->m_arSrcInfo.m_uLength] )
  {
    do
    {
      v5 = v4->item;
      ++v4;
      v5->m_uStreamingLookAhead = this->m_iLookAheadTime;
    }
    while ( v4 != &this->m_arSrcInfo.m_pItems[this->m_arSrcInfo.m_uLength] );
  }
}

// File Line: 441
// RVA: 0xAB3340
bool __fastcall CAkMusicTrack::GetStateSyncTypes(CAkMusicTrack *this, unsigned int in_stateGroupID, CAkParameterNodeBase::CAkStateSyncArray *io_pSyncTypes)
{
  CAkParameterNodeBase::CAkStateSyncArray *v3; // rdi
  unsigned int v4; // esi
  CAkMusicTrack *v5; // rbx
  bool result; // al
  CAkBus *v7; // rcx

  v3 = io_pSyncTypes;
  v4 = in_stateGroupID;
  v5 = this;
  result = 1;
  if ( !CAkParameterNodeBase::CheckSyncTypes((CAkParameterNodeBase *)&this->vfptr, in_stateGroupID, io_pSyncTypes) )
  {
    v7 = (CAkBus *)v5->m_pBusOutputNode;
    if ( !v7 || !CAkBus::GetStateSyncTypes(v7, v4, v3) )
      result = 0;
  }
  return result;
}

// File Line: 459
// RVA: 0xAB3300
CAkMusicSource *__fastcall CAkMusicTrack::GetSourcePtr(CAkMusicTrack *this, unsigned int SourceID)
{
  MapStruct<unsigned long,CAkMusicSource *> *v2; // rax
  signed __int64 v3; // rcx
  CAkMusicSource **v4; // rax
  CAkMusicSource *result; // rax

  v2 = this->m_arSrcInfo.m_pItems;
  v3 = (signed __int64)&v2[this->m_arSrcInfo.m_uLength];
  if ( v2 == (MapStruct<unsigned long,CAkMusicSource *> *)v3 )
    goto LABEL_10;
  do
  {
    if ( v2->key == SourceID )
      break;
    ++v2;
  }
  while ( v2 != (MapStruct<unsigned long,CAkMusicSource *> *)v3 );
  if ( v2 != (MapStruct<unsigned long,CAkMusicSource *> *)v3 && (v4 = &v2->item) != 0i64 )
    result = *v4;
  else
LABEL_10:
    result = 0i64;
  return result;
}

// File Line: 467
// RVA: 0xAB3290
__int64 __fastcall CAkMusicTrack::GetNextRS(CAkMusicTrack *this)
{
  CAkMusicTrack *v1; // rbx
  unsigned int v2; // edx
  __int32 v3; // ecx

  v1 = this;
  LOWORD(v2) = 0;
  v3 = this->m_eRSType - 1;
  if ( !v3 )
  {
    if ( v1->m_uNumSubTrack )
      v2 = rand() % v1->m_uNumSubTrack;
    return (unsigned __int16)v2;
  }
  if ( v3 != 1 )
    return (unsigned __int16)v2;
  if ( ++v1->m_SequenceIndex >= v1->m_uNumSubTrack )
    v1->m_SequenceIndex = 0;
  return v1->m_SequenceIndex;
}

// File Line: 495
// RVA: 0xAB3610
signed __int64 __fastcall CAkMusicTrack::PrepareData(CAkMusicTrack *this)
{
  MapStruct<unsigned long,CAkMusicSource *> *v1; // rbx
  CAkMusicTrack *v2; // rdi
  signed __int64 result; // rax
  unsigned int v4; // esi
  MapStruct<unsigned long,CAkMusicSource *> *v5; // rdi

  v1 = this->m_arSrcInfo.m_pItems;
  v2 = this;
  if ( v1 == &v1[this->m_arSrcInfo.m_uLength] )
    return 1i64;
  while ( 1 )
  {
    result = CAkSource::PrepareData((CAkSource *)&v1->item->m_sSrcTypeInfo);
    v4 = result;
    if ( (_DWORD)result != 1 )
      break;
    ++v1;
    if ( v1 == &v2->m_arSrcInfo.m_pItems[v2->m_arSrcInfo.m_uLength] )
      return (unsigned int)result;
  }
  v5 = v2->m_arSrcInfo.m_pItems;
  if ( v5 != v1 )
  {
    do
    {
      CAkSource::UnPrepareData((CAkSource *)&v5->item->m_sSrcTypeInfo);
      ++v5;
    }
    while ( v5 != v1 );
    result = v4;
  }
  return result;
}

