// File Line: 67
// RVA: 0xAAD8E0
void __fastcall CAkSegmentCtx::CAkSegmentCtx(CAkSegmentCtx *this, CAkMusicSegment *in_pSegmentNode, CAkMusicCtx *in_pParentCtx)
{
  CAkMusicSegment *v3; // rbx
  CAkSegmentCtx *v4; // rdi
  CAkAudioLibIndex *v5; // rbx
  unsigned __int16 v6; // ax
  signed int v7; // er13
  CAkMusicTrack **v8; // rax
  unsigned __int16 v9; // bp
  CAkMusicTrack *v10; // r14
  unsigned __int64 v11; // r12
  unsigned __int64 v12; // rcx
  unsigned int v13; // er15
  CAkMusicTrack **v14; // rsi
  unsigned __int64 v15; // r8
  unsigned __int64 v16; // rdx
  __int64 v17; // rcx
  CAkMusicTrack **v18; // rdx

  v3 = in_pSegmentNode;
  v4 = this;
  CAkMusicCtx::CAkMusicCtx((CAkMusicCtx *)&this->vfptr, in_pParentCtx);
  v4->vfptr = (CAkChildCtxVtbl *)&CAkSegmentCtx::`vftable'{for `CAkChildCtx'};
  v4->vfptr = (CAkTransportAwareVtbl *)&CAkSegmentCtx::`vftable'{for `CAkTransportAware'};
  v4->vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable'{for `ITransitionable'};
  CAkContextualMusicSequencer::CAkContextualMusicSequencer(&v4->m_sequencer);
  v4->m_pSegmentNode = v3;
  v4->m_pOwner = 0i64;
  v4->m_iAudibleTime = 0;
  v4->m_arTracks.m_pItems = 0i64;
  *(_QWORD *)&v4->m_arTracks.m_uLength = 0i64;
  v4->m_arTrackRS.m_pItems = 0i64;
  *(_QWORD *)&v4->m_arTrackRS.m_uLength = 0i64;
  v4->m_listAutomation.m_pFirst = 0i64;
  if ( v4->m_pSegmentNode )
  {
    v5 = CAkAudioLibIndex::GetNodeLock(g_pIndex, 0);
    EnterCriticalSection(&v5->m_idxAudioNode.m_IndexLock.m_csLock);
    ((void (*)(void))v4->m_pSegmentNode->vfptr->AddRef)();
    v6 = ((__int64 (*)(void))v4->m_pSegmentNode->vfptr[20].Release)();
    v7 = v6;
    if ( v6 )
    {
      v8 = (CAkMusicTrack **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * v6);
      v4->m_arTracks.m_pItems = v8;
      if ( !v8 )
      {
        LeaveCriticalSection(&v5->m_idxAudioNode.m_IndexLock.m_csLock);
        return;
      }
      v4->m_arTracks.m_ulReserved = v7;
    }
    v9 = 0;
    if ( v7 > 0 )
    {
      while ( 1 )
      {
        v10 = CAkMusicSegment::Track(v4->m_pSegmentNode, v9);
        v10->vfptr->AddRef((CAkIndexable *)&v10->vfptr);
        v11 = v4->m_arTracks.m_uLength;
        v12 = v4->m_arTracks.m_ulReserved;
        if ( v11 < v12 )
          goto LABEL_13;
        v13 = v12 + 4;
        v14 = (CAkMusicTrack **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * (unsigned int)(v12 + 4));
        if ( v14 )
          break;
LABEL_16:
        if ( ++v9 >= v7 )
          goto LABEL_17;
      }
      v15 = v4->m_arTracks.m_uLength;
      if ( v4->m_arTracks.m_pItems )
      {
        v16 = 0i64;
        if ( v4->m_arTracks.m_uLength )
        {
          do
          {
            ++v16;
            v14[v16 - 1] = v4->m_arTracks.m_pItems[v16 - 1];
          }
          while ( v16 < v15 );
        }
        AK::MemoryMgr::Free(g_DefaultPoolId, v4->m_arTracks.m_pItems);
      }
      v4->m_arTracks.m_pItems = v14;
      v4->m_arTracks.m_ulReserved = v13;
LABEL_13:
      if ( v11 < v4->m_arTracks.m_ulReserved )
      {
        v17 = v4->m_arTracks.m_uLength;
        v18 = &v4->m_arTracks.m_pItems[v17];
        v4->m_arTracks.m_uLength = v17 + 1;
        if ( v18 )
          *v18 = v10;
      }
      goto LABEL_16;
    }
LABEL_17:
    LeaveCriticalSection(&v5->m_idxAudioNode.m_IndexLock.m_csLock);
  }
}

// File Line: 91
// RVA: 0xAADBB0
void __fastcall CAkSegmentCtx::~CAkSegmentCtx(CAkSegmentCtx *this)
{
  CAkSegmentCtx *v1; // rsi
  unsigned __int16 *v2; // rdx
  CAkAudioLibIndex *v3; // rdi
  CAkMusicTrack **v4; // rbx
  CAkMusicTrack **v5; // rdx

  v1 = this;
  this->vfptr = (CAkChildCtxVtbl *)&CAkSegmentCtx::`vftable'{for `CAkChildCtx'};
  this->vfptr = (CAkTransportAwareVtbl *)&CAkSegmentCtx::`vftable'{for `CAkTransportAware'};
  this->vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable'{for `ITransitionable'};
  this->m_sequencer.m_pFirst = 0i64;
  this->m_sequencer.m_pLast = 0i64;
  v2 = this->m_arTrackRS.m_pItems;
  if ( v2 )
  {
    this->m_arTrackRS.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
    v1->m_arTrackRS.m_pItems = 0i64;
    v1->m_arTrackRS.m_ulReserved = 0;
  }
  if ( v1->m_pSegmentNode )
  {
    v3 = CAkAudioLibIndex::GetNodeLock(g_pIndex, 0);
    EnterCriticalSection(&v3->m_idxAudioNode.m_IndexLock.m_csLock);
    v4 = v1->m_arTracks.m_pItems;
    if ( v4 != &v4[v1->m_arTracks.m_uLength] )
    {
      do
      {
        ((void (*)(void))(*v4)->vfptr->Release)();
        ++v4;
      }
      while ( v4 != &v1->m_arTracks.m_pItems[v1->m_arTracks.m_uLength] );
    }
    ((void (*)(void))v1->m_pSegmentNode->vfptr->Release)();
    LeaveCriticalSection(&v3->m_idxAudioNode.m_IndexLock.m_csLock);
  }
  v5 = v1->m_arTracks.m_pItems;
  if ( v5 )
  {
    v1->m_arTracks.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v5);
    v1->m_arTracks.m_pItems = 0i64;
    v1->m_arTracks.m_ulReserved = 0;
  }
  CAkContextualMusicSequencer::~CAkContextualMusicSequencer(&v1->m_sequencer);
  CAkMusicCtx::~CAkMusicCtx((CAkMusicCtx *)&v1->vfptr);
}

// File Line: 117
// RVA: 0xAAE500
signed __int64 __fastcall CAkSegmentCtx::Init(CAkSegmentCtx *this, CAkRegisteredObj *in_GameObject, UserParams *in_rUserparams)
{
  CAkSegmentCtx *v3; // rdi
  unsigned int v4; // ebx
  unsigned __int16 *v5; // rax
  CAkMusicTrack **v6; // rbx
  unsigned __int16 v7; // si
  unsigned __int16 *v8; // rax

  v3 = this;
  CAkMusicCtx::Init((CAkMusicCtx *)&this->vfptr, in_GameObject, in_rUserparams);
  v4 = v3->m_arTracks.m_uLength;
  if ( v4 )
  {
    v5 = (unsigned __int16 *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 2i64 * v4);
    v3->m_arTrackRS.m_pItems = v5;
    if ( !v5 )
      return 52i64;
    v3->m_arTrackRS.m_ulReserved = v4;
  }
  v6 = v3->m_arTracks.m_pItems;
  if ( v6 != &v6[v3->m_arTracks.m_uLength] )
  {
    do
    {
      v7 = CAkMusicTrack::GetNextRS(*v6);
      v8 = AkArray<unsigned short,unsigned short,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast(&v3->m_arTrackRS);
      if ( v8 )
        *v8 = v7;
      ++v6;
    }
    while ( v6 != &v3->m_arTracks.m_pItems[v3->m_arTracks.m_uLength] );
  }
  return 1i64;
}

// File Line: 142
// RVA: 0xAAE6D0
void __fastcall CAkSegmentCtx::Process(CAkSegmentCtx *this, int in_iTime, unsigned int in_uNumSamples)
{
  unsigned int v3; // ebx
  int v4; // ebp
  CAkSegmentCtx *v5; // rdi
  int v6; // esi
  AkMusicAutomation *i; // rbx
  float v8; // xmm0_4
  unsigned int out_index; // [rsp+38h] [rbp+10h]

  ++this->m_uRefCount;
  v3 = in_uNumSamples;
  v4 = in_iTime;
  v5 = this;
  if ( *((_BYTE *)&this->0 + 98) & 2 && this->m_uNumLastSamples != -1 )
    v3 = this->m_uNumLastSamples;
  CAkSegmentCtx::ExecuteScheduledCmds(this, in_iTime, v3);
  v6 = v3 + CAkMusicSegment::PreEntryDuration(v5->m_pSegmentNode) + v4;
  for ( i = v5->m_listAutomation.m_pFirst; i; i = i->pNextLightItem )
  {
    v8 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
           &i->pAutomationData->m_tableAutomation,
           (float)(v6 - i->iTimeStart),
           0,
           &out_index);
    CAkMusicPBI::SetAutomationValue(i->pPBI, i->pAutomationData->m_eAutoType, v8);
  }
  if ( *((_BYTE *)&v5->0 + 98) & 2 )
    v5->vfptr[1].OnPaused((CAkChildCtx *)&v5->vfptr);
  CAkMusicCtx::Release((CAkMusicCtx *)&v5->vfptr);
}

// File Line: 162
// RVA: 0xAAE840
void __fastcall CAkSegmentCtx::ScheduleAudioClips(CAkSegmentCtx *this)
{
  int v1; // ebp
  CAkSegmentCtx *v2; // rsi
  int v3; // eax
  CAkMusicTrack **v4; // rbx
  __int64 v5; // r8
  int v6; // ebp
  unsigned int v7; // er12
  CAkMusicTrack *v8; // rbx
  signed __int64 v9; // rcx
  __int64 v10; // r13
  AkTrackSrc *v11; // rdi
  CAkMusicSource *v12; // rax
  unsigned int v13; // er15
  int v14; // edx
  int v15; // esi
  AkMusicActionPlay *v16; // r14
  int v17; // eax
  CAkMusicTrack **v18; // [rsp+20h] [rbp-58h]
  signed __int64 v19; // [rsp+28h] [rbp-50h]
  CAkSegmentCtx *v20; // [rsp+80h] [rbp+8h]
  unsigned int v21; // [rsp+88h] [rbp+10h]
  int v22; // [rsp+90h] [rbp+18h]
  unsigned int v23; // [rsp+98h] [rbp+20h]

  v20 = this;
  v1 = this->m_iAudibleTime;
  v2 = this;
  v3 = CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode);
  v4 = v2->m_arTracks.m_pItems;
  v5 = 0i64;
  v6 = v3 + v1;
  v22 = 0;
  v18 = v2->m_arTracks.m_pItems;
  if ( v4 != &v4[v2->m_arTracks.m_uLength] )
  {
    do
    {
      v7 = 0;
      v23 = (*v4)->m_arTrackPlaylist.m_uLength;
      if ( v23 )
      {
        v8 = *v4;
        v9 = 2 * v5;
        v10 = 0i64;
        v19 = 2 * v5;
        do
        {
          v11 = &v8->m_arTrackPlaylist.m_pItems[v10];
          if ( v11->uSubTrackIndex == *(unsigned __int16 *)((char *)v2->m_arTrackRS.m_pItems + v9) )
          {
            v12 = CAkMusicTrack::GetSourcePtr(v8, v11->srcID);
            if ( v12 )
            {
              v13 = 0;
              if ( (*((_DWORD *)&v12->m_sSrcTypeInfo.mediaInfo + 4) & 0x7C) == 4
                && (!((*((_DWORD *)&v12->m_sSrcTypeInfo.mediaInfo + 4) >> 1) & 1)
                 || v6 > (signed int)v11->uClipStartPosition
                 || v11->iSourceTrimOffset) )
              {
                v13 = v12->m_uStreamingLookAhead;
              }
              v14 = v11->uClipStartPosition;
              if ( v6 < (signed int)(v14 + v11->uClipDuration) )
              {
                if ( v6 <= v14 )
                {
                  v21 = v11->iSourceTrimOffset;
                  v15 = v14 - v13;
                }
                else
                {
                  v15 = v6 - v13;
                  v21 = (v6 + v11->iSourceTrimOffset - v14) % v11->uSrcDuration;
                }
                v16 = (AkMusicActionPlay *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
                if ( v16 )
                {
                  v17 = CAkMusicSegment::PreEntryDuration(v20->m_pSegmentNode);
                  v16->m_pTrack = v8;
                  v16->m_rTrackSrc = v11;
                  v16->m_uPlayOffset = v13;
                  v16->vfptr = (AkMusicActionVtbl *)&AkMusicActionPlay::`vftable';
                  v16->m_iTime = v15 - v17;
                  v16->m_uSourceOffset = v21;
                  v16->m_listAutomation.m_pFirst = 0i64;
                  AkMusicActionPlay::AttachClipAutomation(v16, v7, 0, v11->uClipStartPosition);
                  AkMusicActionPlay::AttachClipAutomation(v16, v7, AutomationType_LPF, v11->uClipStartPosition);
                  AkMusicActionPlay::AttachClipAutomation(v16, v7, AutomationType_FadeIn, v11->uClipStartPosition);
                  AkMusicActionPlay::AttachClipAutomation(v16, v7, AutomationType_FadeOut, v11->uClipStartPosition);
                  v2 = v20;
                  CAkContextualMusicSequencer::ScheduleAction(&v20->m_sequencer, (AkMusicAction *)&v16->vfptr);
                }
                else
                {
                  v2 = v20;
                }
              }
            }
          }
          v9 = v19;
          ++v7;
          ++v10;
        }
        while ( v7 < v23 );
        v4 = v18;
        LODWORD(v5) = v22;
      }
      ++v4;
      v5 = (unsigned int)(v5 + 1);
      v18 = v4;
      v22 = v5;
    }
    while ( v4 != &v2->m_arTracks.m_pItems[v2->m_arTracks.m_uLength] );
  }
}

// File Line: 305
// RVA: 0xAAE6C0
__int64 __fastcall CAkSegmentCtx::Prepare(CAkSegmentCtx *this, int in_iSourceOffset)
{
  this->m_iAudibleTime = in_iSourceOffset;
  return CAkSegmentCtx::ComputeMinSrcLookAhead(this, in_iSourceOffset);
}

// File Line: 315
// RVA: 0xAAE600
void __fastcall CAkSegmentCtx::OnPlayed(CAkSegmentCtx *this)
{
  CAkSegmentCtx *v1; // rbx

  v1 = this;
  CAkMusicCtx::OnPlayed((CAkMusicCtx *)&this->vfptr);
  CAkSegmentCtx::ScheduleAudioClips(v1);
}

// File Line: 326
// RVA: 0xAAE620
void __fastcall CAkSegmentCtx::OnStopped(CAkSegmentCtx *this)
{
  CAkSegmentCtx *v1; // rbx
  AkMusicAutomation *v2; // rdx
  CAkScheduledItem *v3; // rdx
  CAkMusicCtx *v4; // rcx

  ++this->m_uRefCount;
  v1 = this;
  while ( v1->m_listAutomation.m_pFirst )
  {
    v2 = v1->m_listAutomation.m_pFirst;
    if ( v2 )
    {
      v1->m_listAutomation.m_pFirst = v2->pNextLightItem;
      AK::MemoryMgr::Free(g_DefaultPoolId, v2);
    }
  }
  CAkContextualMusicSequencer::Flush(&v1->m_sequencer);
  v3 = v1->m_pOwner;
  if ( v3 )
  {
    v3->m_pSegment.m_pT->m_pOwner = 0i64;
    v4 = (CAkMusicCtx *)&v3->m_pSegment.m_pT->vfptr;
    v3->m_pSegment.m_pT = 0i64;
    if ( v4 )
      CAkMusicCtx::Release(v4);
  }
  CAkMusicCtx::OnStopped((CAkMusicCtx *)&v1->vfptr);
  CAkMusicCtx::Release((CAkMusicCtx *)&v1->vfptr);
}

// File Line: 348
// RVA: 0xAAE5D0
void __fastcall CAkSegmentCtx::OnPaused(CAkSegmentCtx *this)
{
  CAkSegmentCtx *v1; // rbx
  CAkScheduledItem *v2; // rcx

  v1 = this;
  CAkMusicCtx::OnPaused((CAkMusicCtx *)&this->vfptr);
  v2 = v1->m_pOwner;
  if ( v2 )
    CAkScheduledItem::OnPaused(v2);
}

// File Line: 449
// RVA: 0xAAE040
void __fastcall CAkSegmentCtx::ExecuteScheduledCmds(CAkSegmentCtx *this, int in_iTime, unsigned int in_uNumSamples)
{
  CAkContextualMusicSequencer *v3; // rsi
  CAkSegmentCtx *v4; // r15
  int v5; // er13
  int v6; // er14
  AkMusicAutomation *v7; // rdi
  unsigned int v8; // er12
  int v9; // eax
  AkMusicAction *v10; // rsi
  AkMusicAutomation *v11; // rbx
  int v12; // eax
  float v13; // xmm0_4
  AkMusicAutomation *v14; // rax
  int v15; // ecx
  AkMusicAction *v16; // r13
  CAkMusicCtx *v17; // rax
  CAkChildCtxVtbl *v18; // rbx
  unsigned int v19; // edx
  int v20; // edi
  int v21; // esi
  CAkRegisteredObj *v22; // r14
  CAkMusicSource *v23; // rax
  unsigned int in_uSourceOffset; // ST38_4
  AkTrackSrc *v25; // rsi
  AkMusicAction *v26; // rdi
  int v27; // ebx
  int v28; // eax
  AkMusicActionVtbl *v29; // rcx
  AkMusicAutomation *v30; // rax
  int v31; // ecx
  AkMusicAction *v32; // rbx
  int v33; // edi
  unsigned int v34; // edi
  AkMusicActionVtbl *v35; // rbx
  int v36; // eax
  float v37; // xmm0_4
  AkMusicAction *out_pAction; // [rsp+50h] [rbp-19h]
  TransParams in_transParams; // [rsp+58h] [rbp-11h]
  __m128i v40; // [rsp+60h] [rbp-9h]
  __m128i v41; // [rsp+70h] [rbp+7h]
  AkTrackSrc *out_index; // [rsp+D0h] [rbp+67h]
  int v43; // [rsp+D8h] [rbp+6Fh]
  unsigned int v44; // [rsp+E0h] [rbp+77h]
  CAkMusicPBI *out_pPBI; // [rsp+E8h] [rbp+7Fh]

  v44 = in_uNumSamples;
  v43 = in_iTime;
  v3 = &this->m_sequencer;
  v4 = this;
  v5 = in_uNumSamples;
  v6 = in_iTime;
  if ( CAkContextualMusicSequencer::PopImminentAction(&this->m_sequencer, in_iTime, in_uNumSamples, &out_pAction) == 45 )
  {
    v7 = 0i64;
    while ( 1 )
    {
      v8 = out_pAction->m_iTime - v6;
      v9 = ((__int64 (*)(void))out_pAction->vfptr->Type)();
      if ( !v9 )
        break;
      if ( v9 == 1 )
      {
        v10 = out_pAction;
        CAkMusicPBI::_Stop((CAkMusicPBI *)out_pAction[1].vfptr, v8);
        if ( LOBYTE(v10[1].pNextItem) )
        {
          v11 = v4->m_listAutomation.m_pFirst;
          while ( v11 )
          {
            if ( v11->pPBI == (CAkMusicPBI *)v10[1].vfptr )
            {
              v12 = CAkMusicSegment::PreEntryDuration(v4->m_pSegmentNode);
              v13 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                      &v11->pAutomationData->m_tableAutomation,
                      (float)(v5 + v6 + v12 - v11->iTimeStart),
                      0,
                      (unsigned int *)&out_index);
              CAkMusicPBI::SetAutomationValue(v11->pPBI, v11->pAutomationData->m_eAutoType, v13);
              v14 = v11->pNextLightItem;
              v40.m128i_i64[1] = (__int64)v7;
              v40.m128i_i64[0] = (__int64)v14;
              if ( v11 == v4->m_listAutomation.m_pFirst )
                v4->m_listAutomation.m_pFirst = v14;
              else
                v7->pNextLightItem = v14;
              v15 = g_DefaultPoolId;
              _mm_store_si128(&v41, v40);
              AK::MemoryMgr::Free(v15, v11);
              v7 = (AkMusicAutomation *)v41.m128i_i64[1];
              v11 = (AkMusicAutomation *)v41.m128i_i64[0];
            }
            else
            {
              v7 = v11;
              v11 = v11->pNextLightItem;
            }
          }
        }
        goto LABEL_30;
      }
LABEL_31:
      v32 = out_pAction;
      v33 = g_DefaultPoolId;
      if ( out_pAction )
      {
        out_pAction->vfptr->__vecDelDtor(out_pAction, 0);
        AK::MemoryMgr::Free(v33, v32);
      }
      v7 = 0i64;
      if ( CAkContextualMusicSequencer::PopImminentAction(v3, v6, v5, &out_pAction) != 45 )
        return;
    }
    v16 = out_pAction;
    v17 = v4->m_pParentCtx;
    in_transParams.TransitionTime = 0;
    out_pPBI = 0i64;
    v18 = v17[1].vfptr;
    v19 = HIDWORD(out_pAction[1].pNextItem->vfptr);
    v20 = *(&out_pAction[1].m_iTime + 1);
    v21 = out_pAction[1].m_iTime;
    v22 = (CAkRegisteredObj *)v18[1].OnLastFrame;
    out_index = (AkTrackSrc *)out_pAction[1].pNextItem;
    v23 = CAkMusicTrack::GetSourcePtr((CAkMusicTrack *)out_pAction[1].vfptr, v19);
    in_uSourceOffset = v21;
    v25 = out_index;
    if ( (unsigned int)CAkMusicRenderer::Play(
                         (CAkMusicCtx *)&v4->vfptr,
                         (CAkSoundBase *)v16[1].vfptr,
                         (CAkSource *)&v23->m_sSrcTypeInfo,
                         v22,
                         &in_transParams,
                         (UserParams *)&v18->SetPBIFade,
                         out_index,
                         in_uSourceOffset,
                         v20 + v8,
                         &out_pPBI) == 1 )
    {
      if ( *((_BYTE *)&v4->0 + 98) & 2 )
      {
        CAkMusicPBI::_Stop(out_pPBI, v4->m_uNumLastSamples);
        v6 = v43;
        v34 = v44;
        while ( 1 )
        {
          v35 = v16[2].vfptr;
          if ( !v35 )
            break;
          v16[2].vfptr = (AkMusicActionVtbl *)v35[1].Type;
          v35->Type = (AkMusicActionType (__fastcall *)(AkMusicAction *))out_pPBI;
          v36 = CAkMusicSegment::PreEntryDuration(v4->m_pSegmentNode);
          v37 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                  (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)((char *)v35->__vecDelDtor + 8),
                  (float)(signed int)(v34 + v6 + v36 - LODWORD(v35[1].__vecDelDtor)),
                  0,
                  (unsigned int *)&out_index);
          CAkMusicPBI::SetAutomationValue(
            (CAkMusicPBI *)v35->Type,
            *((AkClipAutomationType *)v35->__vecDelDtor + 1),
            v37);
          AK::MemoryMgr::Free(g_DefaultPoolId, v35);
        }
        goto LABEL_29;
      }
      v26 = (AkMusicAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
      if ( v26 )
      {
        v27 = v25->uClipStartPosition + v25->uClipDuration;
        v28 = CAkMusicSegment::PreEntryDuration(v4->m_pSegmentNode);
        v26[1].vfptr = (AkMusicActionVtbl *)out_pPBI;
        v3 = &v4->m_sequencer;
        v26->vfptr = (AkMusicActionVtbl *)&AkMusicActionStop::`vftable';
        v26->m_iTime = v27 - v28;
        CAkContextualMusicSequencer::ScheduleAction(&v4->m_sequencer, v26);
        while ( 1 )
        {
          v29 = v16[2].vfptr;
          if ( !v29 )
            break;
          v16[2].vfptr = (AkMusicActionVtbl *)v29[1].Type;
          v29->Type = (AkMusicActionType (__fastcall *)(AkMusicAction *))out_pPBI;
          LOBYTE(v26[1].pNextItem) = 1;
          v30 = v4->m_listAutomation.m_pFirst;
          if ( v30 )
          {
            v29[1].Type = (AkMusicActionType (__fastcall *)(AkMusicAction *))v30;
            v4->m_listAutomation.m_pFirst = (AkMusicAutomation *)v29;
          }
          else
          {
            v4->m_listAutomation.m_pFirst = (AkMusicAutomation *)v29;
            v29[1].Type = 0i64;
          }
          v31 = *((_DWORD *)v29->__vecDelDtor + 1);
          if ( v31 == 2 )
          {
            CAkMusicPBI::FixStartTimeForFadeIn(out_pPBI);
          }
          else if ( v31 == 3 )
          {
            *((_DWORD *)out_pPBI + 144) |= 2u;
          }
        }
        v6 = v43;
        v5 = v44;
        goto LABEL_31;
      }
      CAkMusicPBI::_Stop(out_pPBI, 0i64);
    }
    v6 = v43;
LABEL_29:
    v5 = v44;
LABEL_30:
    v3 = &v4->m_sequencer;
    goto LABEL_31;
  }
}

// File Line: 578
// RVA: 0xAADEE0
__int64 __fastcall CAkSegmentCtx::ComputeMinSrcLookAhead(CAkSegmentCtx *this, int in_iPosition)
{
  CAkSegmentCtx *v2; // r14
  int v3; // er13
  int v4; // eax
  CAkMusicTrack **v5; // rbx
  int v6; // ebp
  int v7; // er13
  __int64 v8; // r12
  CAkMusicTrack *v9; // rsi
  AkTrackSrc *v10; // rax
  unsigned int *v11; // rdi
  CAkMusicSource *v12; // rax
  int v13; // edx
  unsigned int v14; // er9
  int v15; // er9

  v2 = this;
  v3 = in_iPosition;
  v4 = CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode);
  v5 = v2->m_arTracks.m_pItems;
  v6 = 0;
  v7 = v4 + v3;
  v8 = 0i64;
  if ( v5 != &v5[v2->m_arTracks.m_uLength] )
  {
    do
    {
      v9 = *v5;
      v10 = (*v5)->m_arTrackPlaylist.m_pItems;
      if ( v10 != &v10[(*v5)->m_arTrackPlaylist.m_uLength] )
      {
        v11 = &v10->uClipStartPosition;
        do
        {
          if ( *(v11 - 2) == v2->m_arTrackRS.m_pItems[v8] )
          {
            v12 = CAkMusicTrack::GetSourcePtr(v9, *(v11 - 1));
            if ( v12 )
            {
              v13 = *v11 - v7;
              v14 = 0;
              if ( (*((_DWORD *)&v12->m_sSrcTypeInfo.mediaInfo + 4) & 0x7C) == 4
                && (!((*((_DWORD *)&v12->m_sSrcTypeInfo.mediaInfo + 4) >> 1) & 1) || v13 < 0 || v11[3]) )
              {
                v14 = v12->m_uStreamingLookAhead;
              }
              if ( v13 < 0 )
                v13 = 0;
              v15 = v14 - v13;
              if ( v6 < v15 )
                v6 = v15;
            }
          }
          v11 += 6;
        }
        while ( v11 - 2 != &v9->m_arTrackPlaylist.m_pItems[v9->m_arTrackPlaylist.m_uLength].uSubTrackIndex );
      }
      ++v5;
      v8 = (unsigned int)(v8 + 1);
    }
    while ( v5 != &v2->m_arTracks.m_pItems[v2->m_arTracks.m_uLength] );
  }
  return (unsigned int)v6;
}

// File Line: 699
// RVA: 0xAAE7A0
void __fastcall CAkSegmentCtx::RemoveAllReferences(CAkSegmentCtx *this, CAkPBI *in_pCtx)
{
  CAkSegmentCtx *v2; // rbx
  CAkPBI *v3; // rdi
  AkMusicAutomation *v4; // rax
  AkMusicAutomation *v5; // r8
  AkMusicAutomation *v6; // rcx
  __int128 v7; // [rsp+20h] [rbp-28h]
  __m128i v8; // [rsp+30h] [rbp-18h]

  v2 = this;
  v3 = in_pCtx;
  CAkContextualMusicSequencer::ClearActionsByTarget(&this->m_sequencer, (CAkMusicPBI *)in_pCtx);
  v4 = v2->m_listAutomation.m_pFirst;
  v5 = 0i64;
  while ( v4 )
  {
    if ( (CAkPBI *)v4->pPBI == v3 )
    {
      v6 = v4->pNextLightItem;
      v8.m128i_i64[1] = (__int64)v5;
      v8.m128i_i64[0] = (__int64)v6;
      if ( v4 == v2->m_listAutomation.m_pFirst )
        v2->m_listAutomation.m_pFirst = v6;
      else
        v5->pNextLightItem = v6;
      _mm_store_si128((__m128i *)&v7, v8);
      if ( v4 )
        AK::MemoryMgr::Free(g_DefaultPoolId, v4);
      v5 = (AkMusicAutomation *)*((_QWORD *)&v7 + 1);
      v4 = (AkMusicAutomation *)v7;
    }
    else
    {
      v5 = v4;
      v4 = v4->pNextLightItem;
    }
  }
}

// File Line: 726
// RVA: 0xAAE410
char __fastcall CAkSegmentCtx::GetSourceInfoForPlaybackRestart(CAkSegmentCtx *this, CAkMusicPBI *in_pCtx, int *out_iLookAhead, int *out_iSourceOffset)
{
  int *v4; // r14
  int *v5; // rsi
  CAkSegmentCtx *v6; // rbp
  char result; // al
  CAkSource *v8; // rcx
  CAkChainCtx *v9; // rcx
  AkTrackSrc *v10; // r15
  unsigned int v11; // edi
  int v12; // ebx
  int v13; // eax
  unsigned int v14; // er9
  int v15; // er8
  signed int v16; // edx

  v4 = out_iSourceOffset;
  v5 = out_iLookAhead;
  v6 = this;
  if ( (*((_BYTE *)&this->0 + 98) & 0xFu) > 1 )
    return 0;
  v8 = in_pCtx->m_pSource;
  if ( (*((_DWORD *)&v8->m_sSrcTypeInfo.mediaInfo + 4) & 0x7C) == 4 )
    *out_iLookAhead = v8[1].m_sSrcTypeInfo.mediaInfo.sourceID;
  else
    *out_iLookAhead = 0;
  *out_iLookAhead = (*out_iLookAhead + 1023) & 0xFFFFFC00;
  v9 = (CAkChainCtx *)v6->m_pParentCtx;
  v10 = in_pCtx->m_pSrcInfo;
  v11 = v9->m_pSequencer->m_uCurTimeWindowSize;
  v12 = CAkChainCtx::GetSegmentPosition(v9, v6->m_pOwner);
  v13 = CAkMusicSegment::PreEntryDuration(v6->m_pSegmentNode);
  v14 = v10->uClipStartPosition;
  v15 = v12 - v11 + v13;
  if ( *v5 + v15 >= (signed int)(v14 + v10->uClipDuration) )
    return 0;
  v16 = (v15 + *v5 + v10->iSourceTrimOffset - v14) % v10->uSrcDuration;
  result = 1;
  if ( v16 < 0 )
    v16 = 0;
  *v4 = v16;
  return result;
}

