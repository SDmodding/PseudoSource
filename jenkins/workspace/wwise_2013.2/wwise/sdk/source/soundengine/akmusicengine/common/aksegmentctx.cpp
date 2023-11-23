// File Line: 67
// RVA: 0xAAD8E0
void __fastcall CAkSegmentCtx::CAkSegmentCtx(
        CAkSegmentCtx *this,
        CAkMusicSegment *in_pSegmentNode,
        CAkMusicCtx *in_pParentCtx)
{
  CAkAudioLibIndex *NodeLock; // rbx
  unsigned __int16 v6; // ax
  signed int v7; // r13d
  CAkMusicTrack **v8; // rax
  unsigned __int16 v9; // bp
  CAkMusicTrack *v10; // r14
  unsigned __int64 m_uLength; // r12
  unsigned __int64 m_ulReserved; // rcx
  unsigned int v13; // r15d
  CAkMusicTrack **v14; // rsi
  unsigned __int64 v15; // r8
  unsigned __int64 v16; // rdx
  __int64 v17; // rcx
  CAkMusicTrack **v18; // rdx

  CAkMusicCtx::CAkMusicCtx(this, in_pParentCtx);
  this->CAkMusicCtx::CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkSegmentCtx::`vftable{for `CAkChildCtx};
  this->CAkMusicCtx::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkSegmentCtx::`vftable{for `CAkTransportAware};
  this->CAkMusicCtx::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  CAkContextualMusicSequencer::CAkContextualMusicSequencer(&this->m_sequencer);
  this->m_pSegmentNode = in_pSegmentNode;
  this->m_pOwner = 0i64;
  this->m_iAudibleTime = 0;
  this->m_arTracks.m_pItems = 0i64;
  *(_QWORD *)&this->m_arTracks.m_uLength = 0i64;
  this->m_arTrackRS.m_pItems = 0i64;
  *(_QWORD *)&this->m_arTrackRS.m_uLength = 0i64;
  this->m_listAutomation.m_pFirst = 0i64;
  if ( this->m_pSegmentNode )
  {
    NodeLock = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Default);
    EnterCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
    this->m_pSegmentNode->vfptr->AddRef(this->m_pSegmentNode);
    v6 = this->m_pSegmentNode->vfptr[20].Release(this->m_pSegmentNode);
    v7 = v6;
    if ( v6 )
    {
      v8 = (CAkMusicTrack **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * v6);
      this->m_arTracks.m_pItems = v8;
      if ( !v8 )
      {
LABEL_17:
        LeaveCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
        return;
      }
      this->m_arTracks.m_ulReserved = v7;
    }
    v9 = 0;
    if ( v7 > 0 )
    {
      while ( 1 )
      {
        v10 = CAkMusicSegment::Track(this->m_pSegmentNode, v9);
        v10->vfptr->AddRef(v10);
        m_uLength = this->m_arTracks.m_uLength;
        m_ulReserved = this->m_arTracks.m_ulReserved;
        if ( m_uLength < m_ulReserved )
          goto LABEL_13;
        v13 = m_ulReserved + 4;
        v14 = (CAkMusicTrack **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * (unsigned int)(m_ulReserved + 4));
        if ( v14 )
          break;
LABEL_16:
        if ( ++v9 >= v7 )
          goto LABEL_17;
      }
      v15 = this->m_arTracks.m_uLength;
      if ( this->m_arTracks.m_pItems )
      {
        v16 = 0i64;
        if ( this->m_arTracks.m_uLength )
        {
          do
          {
            ++v16;
            v14[v16 - 1] = this->m_arTracks.m_pItems[v16 - 1];
          }
          while ( v16 < v15 );
        }
        AK::MemoryMgr::Free(g_DefaultPoolId, this->m_arTracks.m_pItems);
      }
      this->m_arTracks.m_pItems = v14;
      this->m_arTracks.m_ulReserved = v13;
LABEL_13:
      if ( m_uLength < this->m_arTracks.m_ulReserved )
      {
        v17 = this->m_arTracks.m_uLength;
        v18 = &this->m_arTracks.m_pItems[v17];
        this->m_arTracks.m_uLength = v17 + 1;
        if ( v18 )
          *v18 = v10;
      }
      goto LABEL_16;
    }
    goto LABEL_17;
  }
}

// File Line: 91
// RVA: 0xAADBB0
void __fastcall CAkSegmentCtx::~CAkSegmentCtx(CAkSegmentCtx *this)
{
  unsigned __int16 *m_pItems; // rdx
  CAkAudioLibIndex *NodeLock; // rdi
  CAkMusicTrack **v4; // rbx
  CAkMusicTrack **v5; // rdx

  this->CAkMusicCtx::CAkChildCtx::vfptr = (CAkChildCtxVtbl *)&CAkSegmentCtx::`vftable{for `CAkChildCtx};
  this->CAkMusicCtx::CAkTransportAware::vfptr = (CAkTransportAwareVtbl *)&CAkSegmentCtx::`vftable{for `CAkTransportAware};
  this->CAkMusicCtx::ITransitionable::vfptr = (ITransitionableVtbl *)&CAkSegmentCtx::`vftable{for `ITransitionable};
  this->m_sequencer.m_pFirst = 0i64;
  this->m_sequencer.m_pLast = 0i64;
  m_pItems = this->m_arTrackRS.m_pItems;
  if ( m_pItems )
  {
    this->m_arTrackRS.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_arTrackRS.m_pItems = 0i64;
    this->m_arTrackRS.m_ulReserved = 0;
  }
  if ( this->m_pSegmentNode )
  {
    NodeLock = CAkAudioLibIndex::GetNodeLock(g_pIndex, AkNodeType_Default);
    EnterCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
    v4 = this->m_arTracks.m_pItems;
    if ( v4 != &v4[this->m_arTracks.m_uLength] )
    {
      do
      {
        (*v4)->vfptr->Release(*v4);
        ++v4;
      }
      while ( v4 != &this->m_arTracks.m_pItems[this->m_arTracks.m_uLength] );
    }
    this->m_pSegmentNode->vfptr->Release(this->m_pSegmentNode);
    LeaveCriticalSection(&NodeLock->m_idxAudioNode.m_IndexLock.m_csLock);
  }
  v5 = this->m_arTracks.m_pItems;
  if ( v5 )
  {
    this->m_arTracks.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v5);
    this->m_arTracks.m_pItems = 0i64;
    this->m_arTracks.m_ulReserved = 0;
  }
  CAkContextualMusicSequencer::~CAkContextualMusicSequencer(&this->m_sequencer);
  CAkMusicCtx::~CAkMusicCtx(this);
}

// File Line: 117
// RVA: 0xAAE500
__int64 __fastcall CAkSegmentCtx::Init(
        CAkSegmentCtx *this,
        CAkRegisteredObj *in_GameObject,
        UserParams *in_rUserparams)
{
  unsigned int m_uLength; // ebx
  unsigned __int16 *v5; // rax
  CAkMusicTrack **m_pItems; // rbx
  unsigned __int16 NextRS; // si
  unsigned __int16 *v8; // rax

  CAkMusicCtx::Init(this, in_GameObject, in_rUserparams);
  m_uLength = this->m_arTracks.m_uLength;
  if ( m_uLength )
  {
    v5 = (unsigned __int16 *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 2i64 * m_uLength);
    this->m_arTrackRS.m_pItems = v5;
    if ( !v5 )
      return 52i64;
    this->m_arTrackRS.m_ulReserved = m_uLength;
  }
  m_pItems = this->m_arTracks.m_pItems;
  if ( m_pItems != &m_pItems[this->m_arTracks.m_uLength] )
  {
    do
    {
      NextRS = CAkMusicTrack::GetNextRS(*m_pItems);
      v8 = AkArray<unsigned short,unsigned short,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast(&this->m_arTrackRS);
      if ( v8 )
        *v8 = NextRS;
      ++m_pItems;
    }
    while ( m_pItems != &this->m_arTracks.m_pItems[this->m_arTracks.m_uLength] );
  }
  return 1i64;
}

// File Line: 142
// RVA: 0xAAE6D0
void __fastcall CAkSegmentCtx::Process(CAkSegmentCtx *this, int in_iTime, int in_uNumSamples)
{
  int v6; // esi
  AkMusicAutomation *i; // rbx
  float v8; // xmm0_4
  unsigned int out_index; // [rsp+38h] [rbp+10h] BYREF

  ++this->m_uRefCount;
  if ( (*((_BYTE *)&this->CAkMusicCtx + 98) & 2) != 0 && this->m_uNumLastSamples != -1 )
    in_uNumSamples = this->m_uNumLastSamples;
  CAkSegmentCtx::ExecuteScheduledCmds(this, in_iTime, in_uNumSamples);
  v6 = in_uNumSamples + CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode) + in_iTime;
  for ( i = this->m_listAutomation.m_pFirst; i; i = i->pNextLightItem )
  {
    v8 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
           &i->pAutomationData->m_tableAutomation,
           (float)(v6 - i->iTimeStart),
           0,
           &out_index);
    CAkMusicPBI::SetAutomationValue(i->pPBI, i->pAutomationData->m_eAutoType, v8);
  }
  if ( (*((_BYTE *)&this->CAkMusicCtx + 98) & 2) != 0 )
    this->CAkMusicCtx::CAkChildCtx::vfptr[1].OnPaused(this);
  CAkMusicCtx::Release(this);
}

// File Line: 162
// RVA: 0xAAE840
void __fastcall CAkSegmentCtx::ScheduleAudioClips(CAkSegmentCtx *this)
{
  int m_iAudibleTime; // ebp
  CAkSegmentCtx *v2; // rsi
  int v3; // eax
  CAkMusicTrack **m_pItems; // rbx
  __int64 v5; // r8
  int v6; // ebp
  unsigned int v7; // r12d
  CAkMusicTrack *v8; // rbx
  __int64 v9; // rcx
  __int64 v10; // r13
  AkTrackSrc *v11; // rdi
  CAkMusicSource *SourcePtr; // rax
  int v13; // edx
  unsigned int m_uStreamingLookAhead; // r15d
  signed int uClipStartPosition; // edx
  unsigned int v16; // esi
  AkMusicActionPlay *v17; // r14
  int v18; // eax
  CAkMusicTrack **v19; // [rsp+20h] [rbp-58h]
  __int64 v20; // [rsp+28h] [rbp-50h]
  unsigned int iSourceTrimOffset; // [rsp+88h] [rbp+10h]
  int v23; // [rsp+90h] [rbp+18h]
  unsigned int m_uLength; // [rsp+98h] [rbp+20h]

  m_iAudibleTime = this->m_iAudibleTime;
  v2 = this;
  v3 = CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode);
  m_pItems = v2->m_arTracks.m_pItems;
  v5 = 0i64;
  v6 = v3 + m_iAudibleTime;
  v23 = 0;
  v19 = m_pItems;
  if ( m_pItems != &m_pItems[v2->m_arTracks.m_uLength] )
  {
    do
    {
      v7 = 0;
      m_uLength = (*m_pItems)->m_arTrackPlaylist.m_uLength;
      if ( m_uLength )
      {
        v8 = *m_pItems;
        v9 = 2 * v5;
        v10 = 0i64;
        v20 = 2 * v5;
        do
        {
          v11 = &v8->m_arTrackPlaylist.m_pItems[v10];
          if ( v11->uSubTrackIndex == *(unsigned __int16 *)((char *)v2->m_arTrackRS.m_pItems + v9) )
          {
            SourcePtr = CAkMusicTrack::GetSourcePtr(v8, v11->srcID);
            if ( SourcePtr )
            {
              v13 = *((_DWORD *)&SourcePtr->m_sSrcTypeInfo.mediaInfo + 4);
              m_uStreamingLookAhead = 0;
              if ( (v13 & 0x7C) == 4
                && ((v13 & 2) == 0 || v6 > (signed int)v11->uClipStartPosition || v11->iSourceTrimOffset) )
              {
                m_uStreamingLookAhead = SourcePtr->m_uStreamingLookAhead;
              }
              uClipStartPosition = v11->uClipStartPosition;
              if ( v6 < (signed int)(uClipStartPosition + v11->uClipDuration) )
              {
                if ( v6 <= uClipStartPosition )
                {
                  iSourceTrimOffset = v11->iSourceTrimOffset;
                  v16 = uClipStartPosition - m_uStreamingLookAhead;
                }
                else
                {
                  v16 = v6 - m_uStreamingLookAhead;
                  iSourceTrimOffset = (v6 + v11->iSourceTrimOffset - uClipStartPosition) % v11->uSrcDuration;
                }
                v17 = (AkMusicActionPlay *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
                if ( v17 )
                {
                  v18 = CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode);
                  v17->m_pTrack = v8;
                  v17->m_rTrackSrc = v11;
                  v17->m_uPlayOffset = m_uStreamingLookAhead;
                  v17->vfptr = (AkMusicActionVtbl *)&AkMusicActionPlay::`vftable;
                  v17->m_iTime = v16 - v18;
                  v17->m_uSourceOffset = iSourceTrimOffset;
                  v17->m_listAutomation.m_pFirst = 0i64;
                  AkMusicActionPlay::AttachClipAutomation(v17, v7, AutomationType_Volume, v11->uClipStartPosition);
                  AkMusicActionPlay::AttachClipAutomation(v17, v7, AutomationType_LPF, v11->uClipStartPosition);
                  AkMusicActionPlay::AttachClipAutomation(v17, v7, AutomationType_FadeIn, v11->uClipStartPosition);
                  AkMusicActionPlay::AttachClipAutomation(v17, v7, AutomationType_FadeOut, v11->uClipStartPosition);
                  v2 = this;
                  CAkContextualMusicSequencer::ScheduleAction(&this->m_sequencer, v17);
                }
                else
                {
                  v2 = this;
                }
              }
            }
          }
          v9 = v20;
          ++v7;
          ++v10;
        }
        while ( v7 < m_uLength );
        m_pItems = v19;
        LODWORD(v5) = v23;
      }
      ++m_pItems;
      v5 = (unsigned int)(v5 + 1);
      v19 = m_pItems;
      v23 = v5;
    }
    while ( m_pItems != &v2->m_arTracks.m_pItems[v2->m_arTracks.m_uLength] );
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
  CAkMusicCtx::OnPlayed(this);
  CAkSegmentCtx::ScheduleAudioClips(this);
}

// File Line: 326
// RVA: 0xAAE620
void __fastcall CAkSegmentCtx::OnStopped(CAkSegmentCtx *this)
{
  AkMusicAutomation *m_pFirst; // rdx
  CAkScheduledItem *m_pOwner; // rdx
  CAkMusicCtx *m_pT; // rcx

  ++this->m_uRefCount;
  while ( this->m_listAutomation.m_pFirst )
  {
    m_pFirst = this->m_listAutomation.m_pFirst;
    if ( m_pFirst )
    {
      this->m_listAutomation.m_pFirst = m_pFirst->pNextLightItem;
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
    }
  }
  CAkContextualMusicSequencer::Flush(&this->m_sequencer);
  m_pOwner = this->m_pOwner;
  if ( m_pOwner )
  {
    m_pOwner->m_pSegment.m_pT->m_pOwner = 0i64;
    m_pT = m_pOwner->m_pSegment.m_pT;
    m_pOwner->m_pSegment.m_pT = 0i64;
    if ( m_pT )
      CAkMusicCtx::Release(m_pT);
  }
  CAkMusicCtx::OnStopped(this);
  CAkMusicCtx::Release(this);
}

// File Line: 348
// RVA: 0xAAE5D0
void __fastcall CAkSegmentCtx::OnPaused(CAkSegmentCtx *this)
{
  CAkScheduledItem *m_pOwner; // rcx

  CAkMusicCtx::OnPaused(this);
  m_pOwner = this->m_pOwner;
  if ( m_pOwner )
    CAkScheduledItem::OnPaused(m_pOwner);
}

// File Line: 449
// RVA: 0xAAE040
void __fastcall CAkSegmentCtx::ExecuteScheduledCmds(CAkSegmentCtx *this, int in_iTime, int in_uNumSamples)
{
  CAkContextualMusicSequencer *p_m_sequencer; // rsi
  int v5; // r13d
  int v6; // r14d
  AkMusicAutomation *i; // rdi
  unsigned int v8; // r12d
  AkMusicActionType v9; // eax
  AkMusicAction *v10; // rsi
  AkMusicAutomation *m_pFirst; // rbx
  int v12; // eax
  float v13; // xmm0_4
  AkMusicAutomation *pNextLightItem; // rax
  AkMusicAction *v15; // r13
  CAkMusicCtx *m_pParentCtx; // rax
  CAkChildCtxVtbl *vfptr; // rbx
  unsigned int vfptr_high; // edx
  int v19; // edi
  int m_iTime; // esi
  CAkRegisteredObj *OnLastFrame; // r14
  CAkMusicSource *SourcePtr; // rax
  AkTrackSrc *v23; // rsi
  AkMusicAction *v24; // rdi
  int v25; // ebx
  int v26; // eax
  AkMusicAutomation *v27; // rcx
  AkMusicAutomation *v28; // rax
  AkClipAutomationType m_eAutoType; // ecx
  AkMusicAction *v30; // rbx
  int v31; // edi
  int v32; // edi
  AkMusicActionVtbl *v33; // rbx
  int v34; // eax
  float v35; // xmm0_4
  unsigned int in_uSourceOffset; // [rsp+38h] [rbp-31h]
  AkMusicAction *out_pAction; // [rsp+50h] [rbp-19h] BYREF
  TransParams in_transParams; // [rsp+58h] [rbp-11h] BYREF
  __int128 v39; // [rsp+60h] [rbp-9h]
  __int128 v40; // [rsp+70h] [rbp+7h]
  AkTrackSrc *out_index; // [rsp+D0h] [rbp+67h] BYREF
  int v42; // [rsp+D8h] [rbp+6Fh]
  int v43; // [rsp+E0h] [rbp+77h]
  CAkMusicPBI *out_pPBI; // [rsp+E8h] [rbp+7Fh] BYREF

  v43 = in_uNumSamples;
  v42 = in_iTime;
  p_m_sequencer = &this->m_sequencer;
  v5 = in_uNumSamples;
  v6 = in_iTime;
  if ( CAkContextualMusicSequencer::PopImminentAction(&this->m_sequencer, in_iTime, in_uNumSamples, &out_pAction) == AK_DataReady )
  {
    for ( i = 0i64; ; i = 0i64 )
    {
      v8 = out_pAction->m_iTime - v6;
      v9 = out_pAction->vfptr->Type(out_pAction);
      if ( v9 == MusicActionTypePlay )
        break;
      if ( v9 == MusicActionTypeStop )
      {
        v10 = out_pAction;
        CAkMusicPBI::_Stop((CAkMusicPBI *)out_pAction[1].vfptr, v8);
        if ( LOBYTE(v10[1].pNextItem) )
        {
          m_pFirst = this->m_listAutomation.m_pFirst;
          while ( m_pFirst )
          {
            if ( m_pFirst->pPBI == (CAkMusicPBI *)v10[1].vfptr )
            {
              v12 = CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode);
              v13 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                      &m_pFirst->pAutomationData->m_tableAutomation,
                      (float)(v5 + v6 + v12 - m_pFirst->iTimeStart),
                      0,
                      (unsigned int *)&out_index);
              CAkMusicPBI::SetAutomationValue(m_pFirst->pPBI, m_pFirst->pAutomationData->m_eAutoType, v13);
              pNextLightItem = m_pFirst->pNextLightItem;
              *((_QWORD *)&v39 + 1) = i;
              *(_QWORD *)&v39 = pNextLightItem;
              if ( m_pFirst == this->m_listAutomation.m_pFirst )
                this->m_listAutomation.m_pFirst = pNextLightItem;
              else
                i->pNextLightItem = pNextLightItem;
              v40 = v39;
              AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
              i = (AkMusicAutomation *)*((_QWORD *)&v40 + 1);
              m_pFirst = (AkMusicAutomation *)v40;
            }
            else
            {
              i = m_pFirst;
              m_pFirst = m_pFirst->pNextLightItem;
            }
          }
        }
        goto LABEL_30;
      }
LABEL_31:
      v30 = out_pAction;
      v31 = g_DefaultPoolId;
      if ( out_pAction )
      {
        out_pAction->vfptr->__vecDelDtor(out_pAction, 0i64);
        AK::MemoryMgr::Free(v31, v30);
      }
      if ( CAkContextualMusicSequencer::PopImminentAction(p_m_sequencer, v6, v5, &out_pAction) != AK_DataReady )
        return;
    }
    v15 = out_pAction;
    m_pParentCtx = this->m_pParentCtx;
    in_transParams.TransitionTime = 0;
    out_pPBI = 0i64;
    vfptr = m_pParentCtx[1].CAkChildCtx::vfptr;
    vfptr_high = HIDWORD(out_pAction[1].pNextItem->vfptr);
    v19 = *(&out_pAction[1].m_iTime + 1);
    m_iTime = out_pAction[1].m_iTime;
    OnLastFrame = (CAkRegisteredObj *)vfptr[1].OnLastFrame;
    out_index = (AkTrackSrc *)out_pAction[1].pNextItem;
    SourcePtr = CAkMusicTrack::GetSourcePtr((CAkMusicTrack *)out_pAction[1].vfptr, vfptr_high);
    in_uSourceOffset = m_iTime;
    v23 = out_index;
    if ( (unsigned int)CAkMusicRenderer::Play(
                         this,
                         (CAkSoundBase *)v15[1].vfptr,
                         SourcePtr,
                         OnLastFrame,
                         &in_transParams,
                         (UserParams *)&vfptr->SetPBIFade,
                         out_index,
                         in_uSourceOffset,
                         v19 + v8,
                         &out_pPBI) == 1 )
    {
      if ( (*((_BYTE *)&this->CAkMusicCtx + 98) & 2) != 0 )
      {
        CAkMusicPBI::_Stop(out_pPBI, this->m_uNumLastSamples);
        v6 = v42;
        v32 = v43;
        while ( 1 )
        {
          v33 = v15[2].vfptr;
          if ( !v33 )
            break;
          v15[2].vfptr = (AkMusicActionVtbl *)v33[1].Type;
          v33->Type = (AkMusicActionType (__fastcall *)(AkMusicAction *))out_pPBI;
          v34 = CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode);
          v35 = CAkConversionTable<AkRTPCGraphPointBase<float>,float>::ConvertInternal(
                  (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)((char *)v33->__vecDelDtor + 8),
                  (float)(v32 + v6 + v34 - LODWORD(v33[1].__vecDelDtor)),
                  0,
                  (unsigned int *)&out_index);
          CAkMusicPBI::SetAutomationValue((CAkMusicPBI *)v33->Type, *((_DWORD *)v33->__vecDelDtor + 1), v35);
          AK::MemoryMgr::Free(g_DefaultPoolId, v33);
        }
        goto LABEL_29;
      }
      v24 = (AkMusicAction *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
      if ( v24 )
      {
        v25 = v23->uClipStartPosition + v23->uClipDuration;
        v26 = CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode);
        v24[1].vfptr = (AkMusicActionVtbl *)out_pPBI;
        p_m_sequencer = &this->m_sequencer;
        v24->vfptr = (AkMusicActionVtbl *)&AkMusicActionStop::`vftable;
        v24->m_iTime = v25 - v26;
        CAkContextualMusicSequencer::ScheduleAction(&this->m_sequencer, v24);
        while ( 1 )
        {
          v27 = (AkMusicAutomation *)v15[2].vfptr;
          if ( !v27 )
            break;
          v15[2].vfptr = (AkMusicActionVtbl *)v27->pNextLightItem;
          v27->pPBI = out_pPBI;
          LOBYTE(v24[1].pNextItem) = 1;
          v28 = this->m_listAutomation.m_pFirst;
          if ( v28 )
          {
            v27->pNextLightItem = v28;
            this->m_listAutomation.m_pFirst = v27;
          }
          else
          {
            this->m_listAutomation.m_pFirst = v27;
            v27->pNextLightItem = 0i64;
          }
          m_eAutoType = v27->pAutomationData->m_eAutoType;
          if ( m_eAutoType == AutomationType_FadeIn )
          {
            CAkMusicPBI::FixStartTimeForFadeIn(out_pPBI);
          }
          else if ( m_eAutoType == AutomationType_FadeOut )
          {
            *((_DWORD *)out_pPBI + 144) |= 2u;
          }
        }
        v6 = v42;
        v5 = v43;
        goto LABEL_31;
      }
      CAkMusicPBI::_Stop(out_pPBI, 0i64);
    }
    v6 = v42;
LABEL_29:
    v5 = v43;
LABEL_30:
    p_m_sequencer = &this->m_sequencer;
    goto LABEL_31;
  }
}

// File Line: 578
// RVA: 0xAADEE0
__int64 __fastcall CAkSegmentCtx::ComputeMinSrcLookAhead(CAkSegmentCtx *this, int in_iPosition)
{
  int v4; // eax
  CAkMusicTrack **m_pItems; // rbx
  signed int v6; // ebp
  int v7; // r13d
  __int64 v8; // r12
  CAkMusicTrack *v9; // rsi
  AkTrackSrc *v10; // rax
  unsigned int *p_uClipStartPosition; // rdi
  CAkMusicSource *SourcePtr; // rax
  int v13; // r8d
  int v14; // edx
  unsigned int m_uStreamingLookAhead; // r9d
  signed int v16; // r9d

  v4 = CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode);
  m_pItems = this->m_arTracks.m_pItems;
  v6 = 0;
  v7 = v4 + in_iPosition;
  v8 = 0i64;
  if ( m_pItems != &m_pItems[this->m_arTracks.m_uLength] )
  {
    do
    {
      v9 = *m_pItems;
      v10 = (*m_pItems)->m_arTrackPlaylist.m_pItems;
      if ( v10 != &v10[(*m_pItems)->m_arTrackPlaylist.m_uLength] )
      {
        p_uClipStartPosition = &v10->uClipStartPosition;
        do
        {
          if ( *(p_uClipStartPosition - 2) == this->m_arTrackRS.m_pItems[v8] )
          {
            SourcePtr = CAkMusicTrack::GetSourcePtr(v9, *(p_uClipStartPosition - 1));
            if ( SourcePtr )
            {
              v13 = *((_DWORD *)&SourcePtr->m_sSrcTypeInfo.mediaInfo + 4);
              v14 = *p_uClipStartPosition - v7;
              m_uStreamingLookAhead = 0;
              if ( (v13 & 0x7C) == 4 && ((v13 & 2) == 0 || v14 < 0 || p_uClipStartPosition[3]) )
                m_uStreamingLookAhead = SourcePtr->m_uStreamingLookAhead;
              if ( v14 < 0 )
                v14 = 0;
              v16 = m_uStreamingLookAhead - v14;
              if ( v6 < v16 )
                v6 = v16;
            }
          }
          p_uClipStartPosition += 6;
        }
        while ( p_uClipStartPosition - 2 != &v9->m_arTrackPlaylist.m_pItems[v9->m_arTrackPlaylist.m_uLength].uSubTrackIndex );
      }
      ++m_pItems;
      v8 = (unsigned int)(v8 + 1);
    }
    while ( m_pItems != &this->m_arTracks.m_pItems[this->m_arTracks.m_uLength] );
  }
  return (unsigned int)v6;
}

// File Line: 699
// RVA: 0xAAE7A0
void __fastcall CAkSegmentCtx::RemoveAllReferences(CAkSegmentCtx *this, CAkMusicPBI *in_pCtx)
{
  AkMusicAutomation *m_pFirst; // rax
  AkMusicAutomation *v5; // r8
  AkMusicAutomation *pNextLightItem; // rcx
  AkMusicAutomation *v7; // [rsp+30h] [rbp-18h]
  AkMusicAutomation *v8; // [rsp+38h] [rbp-10h]

  CAkContextualMusicSequencer::ClearActionsByTarget(&this->m_sequencer, in_pCtx);
  m_pFirst = this->m_listAutomation.m_pFirst;
  v5 = 0i64;
  while ( m_pFirst )
  {
    if ( m_pFirst->pPBI == in_pCtx )
    {
      pNextLightItem = m_pFirst->pNextLightItem;
      v8 = v5;
      v7 = pNextLightItem;
      if ( m_pFirst == this->m_listAutomation.m_pFirst )
        this->m_listAutomation.m_pFirst = pNextLightItem;
      else
        v5->pNextLightItem = pNextLightItem;
      AK::MemoryMgr::Free(g_DefaultPoolId, m_pFirst);
      v5 = v8;
      m_pFirst = v7;
    }
    else
    {
      v5 = m_pFirst;
      m_pFirst = m_pFirst->pNextLightItem;
    }
  }
}

// File Line: 726
// RVA: 0xAAE410
bool __fastcall CAkSegmentCtx::GetSourceInfoForPlaybackRestart(
        CAkSegmentCtx *this,
        CAkMusicPBI *in_pCtx,
        unsigned int *out_iLookAhead,
        int *out_iSourceOffset)
{
  bool result; // al
  CAkSource *m_pSource; // rcx
  CAkChainCtx *m_pParentCtx; // rcx
  AkTrackSrc *m_pSrcInfo; // r15
  unsigned int m_uCurTimeWindowSize; // edi
  int SegmentPosition; // ebx
  int v13; // eax
  unsigned int uClipStartPosition; // r9d
  int v15; // r8d
  signed int v16; // edx

  if ( (*((_BYTE *)&this->CAkMusicCtx + 98) & 0xFu) > 1 )
    return 0;
  m_pSource = in_pCtx->m_pSource;
  if ( (*((_DWORD *)&m_pSource->m_sSrcTypeInfo.mediaInfo + 4) & 0x7C) == 4 )
    *out_iLookAhead = m_pSource[1].m_sSrcTypeInfo.mediaInfo.sourceID;
  else
    *out_iLookAhead = 0;
  *out_iLookAhead = (*out_iLookAhead + 1023) & 0xFFFFFC00;
  m_pParentCtx = (CAkChainCtx *)this->m_pParentCtx;
  m_pSrcInfo = in_pCtx->m_pSrcInfo;
  m_uCurTimeWindowSize = m_pParentCtx->m_pSequencer->m_uCurTimeWindowSize;
  SegmentPosition = CAkChainCtx::GetSegmentPosition(m_pParentCtx, this->m_pOwner);
  v13 = CAkMusicSegment::PreEntryDuration(this->m_pSegmentNode);
  uClipStartPosition = m_pSrcInfo->uClipStartPosition;
  v15 = SegmentPosition - m_uCurTimeWindowSize + v13;
  if ( (int)(*out_iLookAhead + v15) >= (int)(uClipStartPosition + m_pSrcInfo->uClipDuration) )
    return 0;
  v16 = (v15 + *out_iLookAhead + m_pSrcInfo->iSourceTrimOffset - uClipStartPosition) % m_pSrcInfo->uSrcDuration;
  result = 1;
  if ( v16 < 0 )
    v16 = 0;
  *out_iSourceOffset = v16;
  return result;
}

