// File Line: 37
// RVA: 0xAB2CA0
void __fastcall CAkMusicTrack::CAkMusicTrack(CAkMusicTrack *this, unsigned int in_ulID)
{
  CAkSoundBase::CAkSoundBase(this, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkMusicTrack::`vftable;
  this->m_arSrcInfo.m_pItems = 0i64;
  *(_QWORD *)&this->m_arSrcInfo.m_uLength = 0i64;
  this->m_arClipAutomation.m_pItems = 0i64;
  *(_QWORD *)&this->m_arClipAutomation.m_uLength = 0i64;
  this->m_uNumSubTrack = 0;
  this->m_arTrackPlaylist.m_pItems = 0i64;
  *(_QWORD *)&this->m_arTrackPlaylist.m_uLength = 0i64;
  *(_QWORD *)&this->m_iLookAheadTime = 0i64;
  this->m_SequenceIndex = -1;
}

// File Line: 41
// RVA: 0xAB2D10
void __fastcall CAkMusicTrack::~CAkMusicTrack(CAkMusicTrack *this)
{
  MapStruct<unsigned long,CAkMusicSource *> *m_pItems; // rdx
  AkTrackSrc *v3; // rdx

  this->vfptr = (CAkIndexableVtbl *)&CAkMusicTrack::`vftable;
  CAkMusicTrack::RemoveAllSourcesNoCheck(this);
  m_pItems = this->m_arSrcInfo.m_pItems;
  if ( m_pItems )
  {
    this->m_arSrcInfo.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_arSrcInfo.m_pItems = 0i64;
    this->m_arSrcInfo.m_ulReserved = 0;
  }
  v3 = this->m_arTrackPlaylist.m_pItems;
  if ( v3 )
  {
    this->m_arTrackPlaylist.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v3);
    this->m_arTrackPlaylist.m_pItems = 0i64;
    this->m_arTrackPlaylist.m_ulReserved = 0;
  }
  CAkMusicTrack::ClipAutomationArray::Term(&this->m_arClipAutomation);
  CAkSoundBase::~CAkSoundBase(this);
}

// File Line: 53
// RVA: 0xAB31C0
void __fastcall CAkMusicTrack::Create(unsigned int in_ulID)
{
  CAkMusicTrack *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  unsigned int v5; // eax
  int v6; // ecx
  bool v7; // al

  v2 = (CAkMusicTrack *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xE0ui64);
  if ( v2 )
  {
    CAkMusicTrack::CAkMusicTrack(v2, in_ulID);
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
      *(_BYTE *)(v4 + 83) &= ~2u;
      *(_BYTE *)(v4 + 83) |= 2 * v7;
      CAkParameterNodeBase::AddToIndex((CAkParameterNodeBase *)v4);
    }
  }
}

// File Line: 67
// RVA: 0xAB39E0
__int64 __fastcall CAkMusicTrack::SetInitialValues(
        CAkMusicTrack *this,
        char *in_pData,
        unsigned int in_ulDataSize,
        CAkUsageSlot *__formal,
        bool in_bIsPartialLoadOnly)
{
  unsigned int v6; // esi
  char *v7; // rdx
  AKRESULT v8; // ebx
  int v9; // edi
  __int64 result; // rax
  AKRESULT v11; // eax
  __int64 v12; // rdi
  AkTrackSrcInfo *v13; // rax
  AkTrackSrcInfo *v14; // rsi
  unsigned int v15; // r9d
  __int64 v16; // r10
  char *p_fPlayAt; // rdx
  unsigned int v18; // eax
  __int64 v19; // r8
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  __int64 v22; // xmm0_8
  __int64 v23; // xmm1_8
  __int64 v24; // xmm0_8
  __int64 v25; // xmm1_8
  unsigned int v26; // ecx
  unsigned int v27; // ecx
  __int64 v28; // xmm0_8
  __int64 v29; // xmm1_8
  __int64 v30; // xmm0_8
  __int64 v31; // xmm1_8
  unsigned int v32; // ecx
  unsigned int v33; // ecx
  __int64 v34; // xmm0_8
  __int64 v35; // xmm1_8
  __int64 v36; // xmm0_8
  __int64 v37; // xmm1_8
  unsigned int v38; // ecx
  unsigned int v39; // ecx
  __int64 v40; // xmm0_8
  __int64 v41; // xmm1_8
  __int64 v42; // xmm0_8
  __int64 v43; // xmm1_8
  long double *v44; // r8
  __int64 v45; // r9
  unsigned int v46; // ecx
  unsigned int v47; // ecx
  __int64 v48; // xmm0_8
  __int64 v49; // xmm1_8
  __int64 v50; // xmm0_8
  __int64 v51; // xmm1_8
  unsigned int v52; // r9d
  CAkMusicTrack::ClipAutomationArray *p_m_arClipAutomation; // rbx
  __int64 v54; // r15
  CAkClipAutomation *v55; // rax
  unsigned int v56; // esi
  char *v57; // r8
  unsigned __int64 m_uLength; // rdi
  bool v59; // al
  __int64 v60; // rdx
  __int64 v61; // rcx
  unsigned int v62; // edx
  AkClipAutomationType v63; // eax
  __int64 in_uNumPoints; // rdi
  bool v65; // bl
  unsigned int v66; // edi
  AkMusicTrackRanSeqType v67; // eax
  char *v68; // rcx
  int v69; // edx
  AkMediaInformation m_MediaInfo; // [rsp+30h] [rbp-50h] BYREF
  AkBankSourceData out_rSource; // [rsp+50h] [rbp-30h] BYREF
  char *io_pData; // [rsp+B8h] [rbp+38h] BYREF
  unsigned int io_ulDataSize; // [rsp+C0h] [rbp+40h] BYREF

  io_ulDataSize = in_ulDataSize;
  io_pData = in_pData + 4;
  v6 = *((_DWORD *)in_pData + 1);
  v7 = in_pData + 8;
  v8 = AK_Success;
  io_pData = v7;
  v9 = 0;
  if ( v6 )
  {
    while ( 1 )
    {
      if ( v8 == AK_Success )
      {
        result = CAkBankMgr::LoadSource(&io_pData, &io_ulDataSize, &out_rSource);
        if ( (_DWORD)result != 1 )
          return result;
        if ( out_rSource.m_pParam )
        {
          v11 = (unsigned int)CAkMusicTrack::AddPluginSource(this, out_rSource.m_MediaInfo.sourceID);
        }
        else
        {
          m_MediaInfo = out_rSource.m_MediaInfo;
          v11 = (unsigned int)CAkMusicTrack::AddSource(
                                this,
                                _mm_cvtsi128_si32(*(__m128i *)&out_rSource.m_MediaInfo.sourceID),
                                out_rSource.m_PluginID,
                                &m_MediaInfo);
        }
        v8 = v11;
        if ( v11 != AK_Success )
          return 2i64;
      }
      if ( ++v9 >= v6 )
      {
        v7 = io_pData;
        goto LABEL_10;
      }
    }
  }
  else
  {
LABEL_10:
    v12 = *(unsigned int *)v7;
    io_pData = v7 + 4;
    if ( (_DWORD)v12 )
    {
      v13 = (AkTrackSrcInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 40 * v12);
      v14 = v13;
      if ( !v13 )
        return 52i64;
      v15 = 0;
      v16 = 0i64;
      if ( (int)v12 >= 4 )
      {
        p_fPlayAt = (char *)&v13->fPlayAt;
        v18 = ((unsigned int)(v12 - 4) >> 2) + 1;
        v19 = v18;
        v15 = 4 * v18;
        v16 = 4i64 * v18;
        do
        {
          v20 = *(_DWORD *)io_pData;
          io_pData += 4;
          *((_DWORD *)p_fPlayAt - 2) = v20;
          v21 = *(_DWORD *)io_pData;
          io_pData += 4;
          *((_DWORD *)p_fPlayAt - 1) = v21;
          v22 = *(_QWORD *)io_pData;
          io_pData += 8;
          *(_QWORD *)p_fPlayAt = v22;
          v23 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt + 1) = v23;
          v24 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt + 2) = v24;
          v25 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt + 3) = v25;
          v26 = *(_DWORD *)io_pData;
          io_pData += 4;
          *((_DWORD *)p_fPlayAt + 8) = v26;
          v27 = *(_DWORD *)io_pData;
          io_pData += 4;
          *((_DWORD *)p_fPlayAt + 9) = v27;
          v28 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt + 5) = v28;
          v29 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt + 6) = v29;
          v30 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt + 7) = v30;
          v31 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt + 8) = v31;
          v32 = *(_DWORD *)io_pData;
          io_pData += 4;
          *((_DWORD *)p_fPlayAt + 18) = v32;
          v33 = *(_DWORD *)io_pData;
          io_pData += 4;
          *((_DWORD *)p_fPlayAt + 19) = v33;
          v34 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt + 10) = v34;
          v35 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt + 11) = v35;
          v36 = *(_QWORD *)io_pData;
          p_fPlayAt += 160;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt - 8) = v36;
          v37 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt - 7) = v37;
          v38 = *(_DWORD *)io_pData;
          io_pData += 4;
          *((_DWORD *)p_fPlayAt - 12) = v38;
          v39 = *(_DWORD *)io_pData;
          io_pData += 4;
          *((_DWORD *)p_fPlayAt - 11) = v39;
          v40 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt - 5) = v40;
          v41 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt - 4) = v41;
          v42 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt - 3) = v42;
          v43 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)p_fPlayAt - 2) = v43;
          --v19;
        }
        while ( v19 );
      }
      if ( v15 < (unsigned int)v12 )
      {
        v44 = &v14->fPlayAt + 4 * v16 + v16;
        v45 = (unsigned int)v12 - v15;
        do
        {
          v44 += 5;
          v46 = *(_DWORD *)io_pData;
          io_pData += 4;
          *((_DWORD *)v44 - 12) = v46;
          v47 = *(_DWORD *)io_pData;
          io_pData += 4;
          *((_DWORD *)v44 - 11) = v47;
          v48 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)v44 - 5) = v48;
          v49 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)v44 - 4) = v49;
          v50 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)v44 - 3) = v50;
          v51 = *(_QWORD *)io_pData;
          io_pData += 8;
          *((_QWORD *)v44 - 2) = v51;
          --v45;
        }
        while ( v45 );
      }
      v52 = *(_DWORD *)io_pData;
      io_pData += 4;
      v8 = CAkMusicTrack::SetPlayList(this, v12, v14, v52);
      AK::MemoryMgr::Free(g_DefaultPoolId, v14);
    }
    if ( v8 != AK_Success )
      return (unsigned int)v8;
    p_m_arClipAutomation = &this->m_arClipAutomation;
    CAkMusicTrack::ClipAutomationArray::Term(&this->m_arClipAutomation);
    v54 = *(unsigned int *)io_pData;
    io_pData += 4;
    if ( (_DWORD)v54 )
    {
      v55 = (CAkClipAutomation *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v54);
      p_m_arClipAutomation->m_pItems = v55;
      if ( !v55 )
        return 2i64;
      this->m_arClipAutomation.m_ulReserved = v54;
      v56 = 0;
      v57 = io_pData;
      do
      {
        m_uLength = this->m_arClipAutomation.m_uLength;
        if ( (m_uLength < this->m_arClipAutomation.m_ulReserved
           || (v59 = AkArray<CAkClipAutomation,CAkClipAutomation const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
                       &this->m_arClipAutomation,
                       1u),
               v57 = io_pData,
               v59))
          && m_uLength < this->m_arClipAutomation.m_ulReserved )
        {
          v60 = this->m_arClipAutomation.m_uLength;
          v61 = (__int64)&p_m_arClipAutomation->m_pItems[v60];
          this->m_arClipAutomation.m_uLength = v60 + 1;
          if ( v61 )
          {
            *(_QWORD *)(v61 + 8) = 0i64;
            *(_QWORD *)(v61 + 16) = 0i64;
            v57 = io_pData;
          }
        }
        else
        {
          v61 = 0i64;
        }
        v62 = *(_DWORD *)v57;
        io_pData = v57 + 4;
        v63 = *((_DWORD *)v57 + 1);
        io_pData = v57 + 8;
        in_uNumPoints = *((unsigned int *)v57 + 2);
        v57 += 12;
        io_pData = v57;
        if ( (_DWORD)in_uNumPoints )
        {
          if ( (unsigned int)CAkClipAutomation::Set(
                               (CAkClipAutomation *)v61,
                               v62,
                               v63,
                               (AkRTPCGraphPointBase<float> *)v57,
                               in_uNumPoints) != 1 )
            return 2i64;
          v57 = &io_pData[12 * in_uNumPoints];
          io_pData = v57;
        }
        ++v56;
      }
      while ( v56 < (unsigned int)v54 );
    }
    v65 = in_bIsPartialLoadOnly;
    result = CAkParameterNodeBase::SetNodeBaseParams(this, &io_pData, &io_ulDataSize, in_bIsPartialLoadOnly);
    v66 = result;
    if ( !v65 )
    {
      if ( (_DWORD)result == 1 )
      {
        v67 = *(_DWORD *)io_pData;
        io_pData += 4;
        v68 = io_pData + 4;
        this->m_eRSType = v67;
        v69 = *((_DWORD *)v68 - 1);
        io_pData = v68;
        CAkMusicTrack::LookAheadTime(this, v69);
      }
      return v66;
    }
  }
  return result;
}

// File Line: 185
// RVA: 0xAB3230
__int64 __fastcall CAkMusicTrack::ExecuteAction(CAkMusicTrack *this, ActionParams *in_rAction)
{
  if ( in_rAction->bIsMasterCall )
  {
    LOBYTE(in_rAction) = in_rAction->eType == ActionParamType_Pause;
    ((void (__fastcall *)(CAkMusicTrack *, ActionParams *))this->vfptr[10].Category)(this, in_rAction);
  }
  return 1i64;
}

// File Line: 199
// RVA: 0xAB3260
__int64 __fastcall CAkMusicTrack::ExecuteActionExcept(CAkMusicTrack *this, ActionParamsExcept *in_rAction)
{
  if ( !in_rAction->pGameObj )
  {
    LOBYTE(in_rAction) = in_rAction->eType == ActionParamType_Pause;
    ((void (__fastcall *)(CAkMusicTrack *, ActionParamsExcept *))this->vfptr[10].Category)(this, in_rAction);
  }
  return 1i64;
}

// File Line: 216
// RVA: 0xAB2DD0
__int64 __fastcall CAkMusicTrack::AddPlaylistItem(CAkMusicTrack *this, AkTrackSrcInfo *in_srcInfo)
{
  double v3; // xmm6_8
  AkArray<AkTrackSrc,AkTrackSrc const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *p_m_arTrackPlaylist; // rbx
  unsigned __int64 m_uLength; // rsi
  __int64 v7; // rdx
  AkTrackSrc *v8; // r8
  double v9; // xmm0_8
  double v10; // xmm3_8
  double v11; // xmm1_8
  double v12; // xmm3_8
  double v13; // xmm1_8
  double v14; // xmm3_8
  double v15; // xmm1_8
  int v16; // ecx
  double v17; // xmm1_8
  int v18; // edx

  v3 = in_srcInfo->fEndTrimOffset + in_srcInfo->fSrcDuration - in_srcInfo->fBeginTrimOffset;
  if ( v3 <= 0.0 )
    return 1i64;
  p_m_arTrackPlaylist = &this->m_arTrackPlaylist;
  m_uLength = this->m_arTrackPlaylist.m_uLength;
  if ( m_uLength >= this->m_arTrackPlaylist.m_ulReserved
    && !AkArray<AkTrackSrc,AkTrackSrc const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
          &this->m_arTrackPlaylist,
          1u) )
  {
    return 2i64;
  }
  if ( m_uLength >= p_m_arTrackPlaylist->m_ulReserved )
    return 2i64;
  v7 = p_m_arTrackPlaylist->m_uLength;
  v8 = &p_m_arTrackPlaylist->m_pItems[v7];
  p_m_arTrackPlaylist->m_uLength = v7 + 1;
  if ( !v8 )
    return 2i64;
  v8->uSubTrackIndex = in_srcInfo->trackID;
  v8->srcID = in_srcInfo->sourceID;
  v9 = DOUBLE_0_5;
  v10 = (in_srcInfo->fPlayAt + in_srcInfo->fBeginTrimOffset)
      * (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency
      * 0.001;
  if ( v10 <= 0.0 )
    v11 = DOUBLE_N0_5;
  else
    v11 = DOUBLE_0_5;
  v8->uClipStartPosition = (int)(v11 + v10);
  v12 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * v3 * 0.001;
  if ( v12 <= 0.0 )
    v13 = DOUBLE_N0_5;
  else
    v13 = DOUBLE_0_5;
  v8->uClipDuration = (int)(v13 + v12);
  v14 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * in_srcInfo->fSrcDuration * 0.001;
  if ( v14 <= 0.0 )
    v15 = DOUBLE_N0_5;
  else
    v15 = DOUBLE_0_5;
  v16 = (int)(v15 + v14);
  v8->uSrcDuration = v16;
  v17 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * in_srcInfo->fBeginTrimOffset * 0.001;
  if ( v17 <= 0.0 )
    v9 = DOUBLE_N0_5;
  v18 = (int)(v9 + v17) % v16;
  v8->iSourceTrimOffset = v18;
  if ( v18 < 0 )
    v8->iSourceTrimOffset = v18 + v16;
  return 1i64;
}

// File Line: 253
// RVA: 0xAB3F50
__int64 __fastcall CAkMusicTrack::SetPlayList(
        CAkMusicTrack *this,
        unsigned int in_uNumPlaylistItem,
        AkTrackSrcInfo *in_pArrayPlaylistItems,
        unsigned int in_uNumSubTrack)
{
  __int64 v4; // rsi
  AkTrackSrc *m_pItems; // rdx
  AkTrackSrc *v9; // rax

  v4 = in_uNumPlaylistItem;
  m_pItems = this->m_arTrackPlaylist.m_pItems;
  if ( m_pItems )
  {
    this->m_arTrackPlaylist.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_arTrackPlaylist.m_pItems = 0i64;
    this->m_arTrackPlaylist.m_ulReserved = 0;
  }
  this->m_uNumSubTrack = in_uNumSubTrack;
  if ( !(_DWORD)v4 )
    return 1i64;
  v9 = (AkTrackSrc *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 24 * v4);
  this->m_arTrackPlaylist.m_pItems = v9;
  if ( v9 )
  {
    this->m_arTrackPlaylist.m_ulReserved = v4;
    do
    {
      CAkMusicTrack::AddPlaylistItem(this, in_pArrayPlaylistItems++);
      --v4;
    }
    while ( v4 );
    return 1i64;
  }
  return 2i64;
}

// File Line: 340
// RVA: 0xAB3070
__int64 __fastcall CAkMusicTrack::AddSource(
        CAkMusicTrack *this,
        unsigned int in_srcID,
        unsigned int in_pluginID,
        AkMediaInformation *in_MediaInfo)
{
  MapStruct<unsigned long,CAkMusicSource *> *m_pItems; // rax
  MapStruct<unsigned long,CAkMusicSource *> *v8; // r11
  MapStruct<unsigned long,CAkMusicSource *> *i; // r10
  __int64 result; // rax
  void *p_item; // rbx
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v13; // rax
  CAkSource *v14; // rax
  CAkSource *v15; // rsi
  __int128 v16; // xmm0
  AkMediaInformation v17; // [rsp+20h] [rbp-38h] BYREF

  m_pItems = this->m_arSrcInfo.m_pItems;
  v8 = &m_pItems[this->m_arSrcInfo.m_uLength];
  for ( i = m_pItems; i != v8; ++i )
  {
    if ( i->key == in_srcID )
      break;
  }
  if ( i != v8 && i != (MapStruct<unsigned long,CAkMusicSource *> *)-8i64 )
    return 1i64;
  for ( ; m_pItems != v8; ++m_pItems )
  {
    if ( m_pItems->key == in_srcID )
      break;
  }
  if ( m_pItems == v8 )
  {
    p_item = 0i64;
  }
  else
  {
    p_item = &m_pItems->item;
    if ( m_pItems != (MapStruct<unsigned long,CAkMusicSource *> *)-8i64 )
      goto LABEL_17;
  }
  v13 = AkArray<MapStruct<unsigned long,CAkMusicSource *>,MapStruct<unsigned long,CAkMusicSource *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast((AkArray<MapStruct<CAkRSSub *,CAkContainerBaseInfo *>,MapStruct<CAkRSSub *,CAkContainerBaseInfo *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)&this->m_arSrcInfo);
  if ( v13 )
  {
    LODWORD(v13->key) = in_srcID;
    p_item = &v13->item;
  }
  if ( !p_item )
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
  *(_QWORD *)p_item = v15;
  if ( v15 )
  {
    v16 = *(_OWORD *)&in_MediaInfo->sourceID;
    *((_DWORD *)&v17 + 4) = *((_DWORD *)in_MediaInfo + 4);
    *(_OWORD *)&v17.sourceID = v16;
    CAkSource::SetSource(v15, in_pluginID, &v17);
    *(_DWORD *)(*(_QWORD *)p_item + 40i64) = this->m_iLookAheadTime;
  }
  else
  {
    CAkKeyArray<unsigned long,CAkMusicSource *,4>::Unset(&this->m_arSrcInfo, in_srcID);
  }
  result = 1i64;
  if ( !*(_QWORD *)p_item )
    return 2i64;
  return result;
}

// File Line: 369
// RVA: 0xAB2F90
__int64 __fastcall CAkMusicTrack::AddPluginSource(CAkMusicTrack *this, unsigned int in_srcID)
{
  CAkKeyArray<unsigned long,CAkMusicSource *,4> *p_m_arSrcInfo; // r14
  MapStruct<unsigned long,CAkMusicSource *> *m_pItems; // rax
  MapStruct<unsigned long,CAkMusicSource *> *i; // rcx
  _QWORD *p_item; // rbx
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v7; // rax
  CAkSource *v8; // rax
  CAkSource *v9; // rdi
  __int64 result; // rax

  p_m_arSrcInfo = &this->m_arSrcInfo;
  m_pItems = this->m_arSrcInfo.m_pItems;
  for ( i = &m_pItems[this->m_arSrcInfo.m_uLength]; m_pItems != i; ++m_pItems )
  {
    if ( m_pItems->key == in_srcID )
      break;
  }
  if ( m_pItems == i )
  {
    p_item = 0i64;
  }
  else
  {
    p_item = &m_pItems->item;
    if ( m_pItems != (MapStruct<unsigned long,CAkMusicSource *> *)-8i64 )
      goto LABEL_11;
  }
  v7 = AkArray<MapStruct<unsigned long,CAkMusicSource *>,MapStruct<unsigned long,CAkMusicSource *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault>::AddLast((AkArray<MapStruct<CAkRSSub *,CAkContainerBaseInfo *>,MapStruct<CAkRSSub *,CAkContainerBaseInfo *> const &,ArrayPoolDefault,4,AkArrayAllocatorDefault> *)p_m_arSrcInfo);
  if ( v7 )
  {
    LODWORD(v7->key) = in_srcID;
    p_item = &v7->item;
  }
  if ( !p_item )
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
  *p_item = v9;
  if ( v9 )
    CAkSource::SetSource(v9, in_srcID);
  else
    CAkKeyArray<unsigned long,CAkMusicSource *,4>::Unset(p_m_arSrcInfo, in_srcID);
  result = 1i64;
  if ( !*p_item )
    return 2i64;
  return result;
}

// File Line: 387
// RVA: 0xAB3530
char __fastcall CAkMusicTrack::HasBankSource(CAkMusicTrack *this)
{
  MapStruct<unsigned long,CAkMusicSource *> *m_pItems; // rax
  MapStruct<unsigned long,CAkMusicSource *> *v2; // r8

  m_pItems = this->m_arSrcInfo.m_pItems;
  v2 = &m_pItems[this->m_arSrcInfo.m_uLength];
  if ( m_pItems == v2 )
    return 0;
  while ( (*((_DWORD *)&m_pItems->item->m_sSrcTypeInfo.mediaInfo + 4) & 0x80) == 0 )
  {
    if ( ++m_pItems == v2 )
      return 0;
  }
  return 1;
}

// File Line: 407
// RVA: 0xAB36D0
void __fastcall CAkMusicTrack::RemoveAllSourcesNoCheck(CAkMusicTrack *this)
{
  MapStruct<unsigned long,CAkMusicSource *> *m_pItems; // rbx
  CAkMusicSource *item; // rdi
  int v4; // ebp

  this->m_uNumSubTrack = 0;
  this->m_arTrackPlaylist.m_uLength = 0;
  m_pItems = this->m_arSrcInfo.m_pItems;
  if ( m_pItems == &m_pItems[this->m_arSrcInfo.m_uLength] )
  {
    this->m_arSrcInfo.m_uLength = 0;
  }
  else
  {
    do
    {
      item = m_pItems->item;
      v4 = g_DefaultPoolId;
      if ( item )
      {
        CAkSource::~CAkSource(m_pItems->item);
        AK::MemoryMgr::Free(v4, item);
      }
      ++m_pItems;
    }
    while ( m_pItems != &this->m_arSrcInfo.m_pItems[this->m_arSrcInfo.m_uLength] );
    this->m_arSrcInfo.m_uLength = 0;
  }
}

// File Line: 426
// RVA: 0xAB3570
void __fastcall CAkMusicTrack::LookAheadTime(CAkMusicTrack *this, int in_LookAheadTime)
{
  double v2; // xmm1_8
  double v3; // xmm0_8
  MapStruct<unsigned long,CAkMusicSource *> *m_pItems; // rax
  CAkMusicSource *item; // rdx

  v2 = (float)((float)in_LookAheadTime * CAkMusicRenderer::m_musicSettings.fStreamingLookAheadRatio)
     * (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency
     * 0.001;
  if ( v2 <= 0.0 )
    v3 = DOUBLE_N0_5;
  else
    v3 = DOUBLE_0_5;
  this->m_iLookAheadTime = (int)(v3 + v2);
  m_pItems = this->m_arSrcInfo.m_pItems;
  if ( m_pItems != &m_pItems[this->m_arSrcInfo.m_uLength] )
  {
    do
    {
      item = m_pItems->item;
      ++m_pItems;
      item->m_uStreamingLookAhead = this->m_iLookAheadTime;
    }
    while ( m_pItems != &this->m_arSrcInfo.m_pItems[this->m_arSrcInfo.m_uLength] );
  }
}

// File Line: 441
// RVA: 0xAB3340
bool __fastcall CAkMusicTrack::GetStateSyncTypes(
        CAkMusicTrack *this,
        unsigned int in_stateGroupID,
        AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault> *io_pSyncTypes)
{
  bool result; // al
  CAkBus *m_pBusOutputNode; // rcx

  result = 1;
  if ( !CAkParameterNodeBase::CheckSyncTypes(this, in_stateGroupID, io_pSyncTypes) )
  {
    m_pBusOutputNode = (CAkBus *)this->m_pBusOutputNode;
    if ( !m_pBusOutputNode || !CAkBus::GetStateSyncTypes(m_pBusOutputNode, in_stateGroupID, io_pSyncTypes) )
      return 0;
  }
  return result;
}

// File Line: 459
// RVA: 0xAB3300
CAkMusicSource *__fastcall CAkMusicTrack::GetSourcePtr(CAkMusicTrack *this, unsigned int SourceID)
{
  MapStruct<unsigned long,CAkMusicSource *> *m_pItems; // rax
  MapStruct<unsigned long,CAkMusicSource *> *v3; // rcx
  CAkMusicSource **p_item; // rax

  m_pItems = this->m_arSrcInfo.m_pItems;
  v3 = &m_pItems[this->m_arSrcInfo.m_uLength];
  if ( m_pItems == v3 )
    return 0i64;
  do
  {
    if ( m_pItems->key == SourceID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v3 );
  if ( m_pItems == v3 )
    return 0i64;
  p_item = &m_pItems->item;
  if ( !p_item )
    return 0i64;
  else
    return *p_item;
}

// File Line: 467
// RVA: 0xAB3290
__int64 __fastcall CAkMusicTrack::GetNextRS(CAkMusicTrack *this)
{
  int v2; // edx
  __int32 v3; // ecx

  LOWORD(v2) = 0;
  v3 = this->m_eRSType - 1;
  if ( !v3 )
  {
    if ( this->m_uNumSubTrack )
      return (unsigned __int16)(rand() % this->m_uNumSubTrack);
    return (unsigned __int16)v2;
  }
  if ( v3 != 1 )
    return (unsigned __int16)v2;
  if ( ++this->m_SequenceIndex >= this->m_uNumSubTrack )
    this->m_SequenceIndex = 0;
  return this->m_SequenceIndex;
}

// File Line: 495
// RVA: 0xAB3610
signed __int64 __fastcall CAkMusicTrack::PrepareData(CAkMusicTrack *this)
{
  MapStruct<unsigned long,CAkMusicSource *> *m_pItems; // rbx
  signed __int64 result; // rax
  unsigned int v4; // esi
  MapStruct<unsigned long,CAkMusicSource *> *v5; // rdi

  m_pItems = this->m_arSrcInfo.m_pItems;
  if ( m_pItems == &m_pItems[this->m_arSrcInfo.m_uLength] )
    return 1i64;
  while ( 1 )
  {
    result = CAkSource::PrepareData(m_pItems->item);
    v4 = result;
    if ( (_DWORD)result != 1 )
      break;
    if ( ++m_pItems == &this->m_arSrcInfo.m_pItems[this->m_arSrcInfo.m_uLength] )
      return 1i64;
  }
  v5 = this->m_arSrcInfo.m_pItems;
  if ( v5 != m_pItems )
  {
    do
    {
      CAkSource::UnPrepareData(v5->item);
      ++v5;
    }
    while ( v5 != m_pItems );
    return v4;
  }
  return result;
}

