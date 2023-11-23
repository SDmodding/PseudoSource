// File Line: 31
// RVA: 0xAB1910
void __fastcall CAkMusicRanSeqCntr::CAkMusicRanSeqCntr(CAkMusicRanSeqCntr *this, unsigned int in_ulID)
{
  CAkMusicTransAware::CAkMusicTransAware(this, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkMusicRanSeqCntr::`vftable;
  this->m_playListRoot.m_pParent = 0i64;
  this->m_playListRoot.vfptr = (CAkRSNodeVtbl *)&CAkRSSub::`vftable;
  this->m_playListRoot.m_ID = 0;
  this->m_playListRoot.m_Weight = 50000;
  this->m_playListRoot.m_listChildren.m_pItems = 0i64;
  *(_QWORD *)&this->m_playListRoot.m_listChildren.m_uLength = 0i64;
  this->m_playListRoot.m_eRSType = RSType_ContinuousSequence;
  this->m_playListRoot.m_pGlobalCntrBaseInfo = 0i64;
  *(_WORD *)&this->m_playListRoot.m_bIsUsingWeight = 256;
  this->m_playListRoot.m_bHasSegmentLeaves = 0;
  this->m_playListRoot.m_wAvoidRepeatCount = 0;
}

// File Line: 42
// RVA: 0xAB1E40
void __fastcall CAkMusicRanSeqCntr::Create(unsigned int in_ulID)
{
  CAkMusicRanSeqCntr *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  unsigned int v5; // eax
  int v6; // ecx
  bool v7; // al

  v2 = (CAkMusicRanSeqCntr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x120ui64);
  if ( v2 )
  {
    CAkMusicRanSeqCntr::CAkMusicRanSeqCntr(v2, in_ulID);
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

// File Line: 56
// RVA: 0xAB2090
AKRESULT __fastcall CAkMusicRanSeqCntr::SetInitialValues(
        CAkMusicRanSeqCntr *this,
        char *in_pData,
        unsigned int in_ulDataSize)
{
  AKRESULT result; // eax
  unsigned int v5; // ebx
  __int64 v6; // rsi
  AkMusicRanSeqPlaylistItem *v7; // rax
  AkMusicRanSeqPlaylistItem *v8; // rdi
  unsigned int *p_m_NumChildren; // rdx
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  char *io_rpData; // [rsp+48h] [rbp+20h] BYREF
  unsigned int io_rulDataSize; // [rsp+50h] [rbp+28h] BYREF

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData;
  result = CAkMusicTransAware::SetMusicTransNodeParams(this, &io_rpData, &io_rulDataSize, 0);
  if ( result == AK_Success )
  {
    v5 = *(_DWORD *)io_rpData;
    io_rpData += 4;
    if ( v5 )
    {
      v6 = v5;
      v7 = (AkMusicRanSeqPlaylistItem *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 28i64 * v5);
      v8 = v7;
      if ( !v7 )
        return 2;
      p_m_NumChildren = &v7->m_NumChildren;
      do
      {
        p_m_NumChildren += 7;
        v10 = *(_DWORD *)io_rpData;
        io_rpData += 4;
        *(p_m_NumChildren - 9) = v10;
        v11 = *(_DWORD *)io_rpData;
        io_rpData += 4;
        *(p_m_NumChildren - 8) = v11;
        v12 = *(_DWORD *)io_rpData;
        io_rpData += 4;
        *(p_m_NumChildren - 7) = v12;
        v13 = *(_DWORD *)io_rpData;
        io_rpData += 4;
        *(p_m_NumChildren - 6) = v13;
        LOWORD(v13) = *(_WORD *)io_rpData;
        io_rpData += 2;
        *((_WORD *)p_m_NumChildren - 10) = v13;
        v14 = *(_DWORD *)io_rpData;
        io_rpData += 4;
        *(p_m_NumChildren - 4) = v14;
        LOWORD(v14) = *(_WORD *)io_rpData;
        io_rpData += 2;
        *((_WORD *)p_m_NumChildren - 6) = v14;
        LOBYTE(v14) = *io_rpData++;
        *((_BYTE *)p_m_NumChildren - 10) = (_BYTE)v14 != 0;
        LOBYTE(v14) = *io_rpData++;
        *((_BYTE *)p_m_NumChildren - 9) = (_BYTE)v14 != 0;
        --v6;
      }
      while ( v6 );
      CAkMusicRanSeqCntr::SetPlayList(this, v7);
      AK::MemoryMgr::Free(g_DefaultPoolId, v8);
    }
    return 1;
  }
  return result;
}

// File Line: 102
// RVA: 0xAB1F70
void __fastcall CAkMusicRanSeqCntr::FlushPlaylist(CAkMusicRanSeqCntr *this)
{
  CAkRSNode **m_pItems; // rbx
  CAkRSNode *v3; // rdi
  int v4; // esi

  m_pItems = this->m_playListRoot.m_listChildren.m_pItems;
  if ( m_pItems != &m_pItems[this->m_playListRoot.m_listChildren.m_uLength] )
  {
    do
    {
      v3 = *m_pItems;
      if ( *m_pItems )
      {
        v4 = g_DefaultPoolId;
        v3->vfptr->__vecDelDtor(*m_pItems, 0);
        AK::MemoryMgr::Free(v4, v3);
      }
      ++m_pItems;
    }
    while ( m_pItems != &this->m_playListRoot.m_listChildren.m_pItems[this->m_playListRoot.m_listChildren.m_uLength] );
  }
  this->m_playListRoot.m_listChildren.m_uLength = 0;
  CAkRSSub::Clear(&this->m_playListRoot);
}

// File Line: 122
// RVA: 0xAB1F60
__int64 __fastcall CAkMusicRanSeqCntr::ExecuteAction(CAkMusicRanSeqCntr *this, ActionParams *in_rAction)
{
  if ( in_rAction->eType == ActionParamType_Seek )
    return 2i64;
  else
    return CAkMusicNode::ExecuteAction(this, in_rAction);
}

// File Line: 161
// RVA: 0xAB1DA0
__int64 __fastcall CAkMusicRanSeqCntr::CanAddChild(CAkMusicRanSeqCntr *this, CAkParameterNodeBase *in_pAudioNode)
{
  unsigned int v4; // ebx
  unsigned int v5; // ebp
  unsigned int key; // edi

  v4 = 1;
  v5 = in_pAudioNode->vfptr[3].Release(in_pAudioNode);
  if ( (unsigned __int16)this->vfptr[20].Release(this) == 0xFFFF )
    return 9i64;
  if ( v5 != 7 )
    return 4i64;
  if ( in_pAudioNode->m_pParentNode )
    return 21i64;
  key = in_pAudioNode->key;
  if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         &this->m_mapChildId,
         key) )
  {
    return 5i64;
  }
  if ( this->key == key )
    return 23;
  return v4;
}

// File Line: 196
// RVA: 0xAB1EB0
// attributes: thunk
CAkSequenceCtx *__fastcall CAkMusicRanSeqCntr::CreateContext(
        CAkMusicRanSeqCntr *this,
        CAkMatrixAwareCtx *in_pParentCtx,
        CAkRegisteredObj *in_GameObject,
        UserParams *in_rUserparams)
{
  return CAkMusicRanSeqCntr::CreateSequenceCtx(this, in_pParentCtx, in_GameObject, in_rUserparams);
}

// File Line: 205
// RVA: 0xAB1EC0
void __fastcall CAkMusicRanSeqCntr::CreateSequenceCtx(
        CAkMusicRanSeqCntr *this,
        CAkMatrixAwareCtx *in_pParentCtx,
        CAkRegisteredObj *in_GameObject,
        UserParams *in_rUserparams)
{
  CAkSequenceCtx *v8; // rax
  CAkSequenceCtx *v9; // rax
  CAkMusicCtx *v10; // rbx

  v8 = (CAkSequenceCtx *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xF0ui64);
  if ( v8 )
  {
    CAkSequenceCtx::CAkSequenceCtx(v8, this, in_pParentCtx);
    v10 = v9;
    if ( v9 )
    {
      ++v9->m_uRefCount;
      if ( CAkSequenceCtx::Init(v9, in_GameObject, in_rUserparams) != AK_Success )
        UFG::OnUnloadClass<UITest::HandleArrayTest>(v10);
      CAkMusicCtx::Release(v10);
    }
  }
}

// File Line: 228
// RVA: 0xAB2010
__int64 __fastcall CAkMusicRanSeqCntr::PlayInternal(CAkMusicRanSeqCntr *this, AkPBIParams *in_rPBIParams)
{
  CAkMatrixAwareCtx *v3; // rax
  CAkMatrixAwareCtx *v4; // rbx
  TransParams *pTransitionParameters; // rdx
  CAkTransition **v6; // r8
  AkMusicFade in_fadeParams; // [rsp+20h] [rbp-18h] BYREF

  CAkMusicRanSeqCntr::CreateSequenceCtx(this, 0i64, in_rPBIParams->pGameObj, &in_rPBIParams->userParams);
  v4 = v3;
  if ( !v3 )
    return 2i64;
  v3->CAkMusicCtx::CAkChildCtx::vfptr[1].OnResumed(v3);
  pTransitionParameters = in_rPBIParams->pTransitionParameters;
  in_fadeParams.transitionTime = pTransitionParameters->TransitionTime;
  in_fadeParams.eFadeCurve = pTransitionParameters->eFadeCurve;
  in_fadeParams.iFadeOffset = CAkMatrixAwareCtx::GetSilentDuration(v4);
  CAkMusicCtx::_Play(v4, &in_fadeParams, v6);
  return 1i64;
}

// File Line: 309
// RVA: 0xAB2210
__int64 __fastcall CAkMusicRanSeqCntr::SetPlayList(CAkMusicRanSeqCntr *this, AkMusicRanSeqPlaylistItem *in_pArrayItems)
{
  AkMusicRanSeqPlaylistItem *v3; // rdx
  RSType m_eRSType; // eax
  unsigned int m_NumChildren; // r9d
  AkMusicRanSeqPlaylistItem *in_pArrayItemsa; // [rsp+38h] [rbp+10h] BYREF

  in_pArrayItemsa = in_pArrayItems;
  CAkMusicRanSeqCntr::FlushPlaylist(this);
  v3 = in_pArrayItemsa++;
  this->m_playListRoot.m_wAvoidRepeatCount = v3->m_wAvoidRepeatCount;
  this->m_playListRoot.m_Loop = v3->m_Loop;
  this->m_playListRoot.m_Weight = v3->m_Weight;
  m_eRSType = v3->m_eRSType;
  this->m_playListRoot.m_bIsUsingWeight = 0;
  this->m_playListRoot.m_eRSType = m_eRSType;
  this->m_playListRoot.m_bIsShuffle = v3->m_bIsShuffle;
  this->m_playListRoot.m_ID = v3->m_playlistItemID;
  m_NumChildren = v3->m_NumChildren;
  if ( m_NumChildren )
    return CAkMusicRanSeqCntr::AddPlaylistChildren(this, &this->m_playListRoot, &in_pArrayItemsa, m_NumChildren);
  else
    return 1i64;
}

// File Line: 420
// RVA: 0xAB1AB0
__int64 __fastcall CAkMusicRanSeqCntr::AddPlaylistChildren(
        CAkMusicRanSeqCntr *this,
        CAkRSSub *in_pParent,
        AkMusicRanSeqPlaylistItem **in_pArrayItems,
        unsigned int in_ulNumItems)
{
  unsigned int v5; // ebp
  AkMusicRanSeqPlaylistItem *v6; // rsi
  CAkRSSub *v7; // rax
  CAkRSSub *v8; // rdi
  unsigned __int64 m_uLength; // rcx
  unsigned __int64 m_ulReserved; // rax
  CAkRSNode **v11; // rbp
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rdx
  __int64 v14; // rcx
  CAkRSNode **v15; // rdx
  RSType m_eRSType; // eax
  unsigned int m_NumChildren; // r9d
  CAkRSSub *v18; // rax
  unsigned __int64 v19; // rcx
  unsigned __int64 v20; // rax
  CAkRSNode **v21; // rbp
  unsigned __int64 v22; // r8
  unsigned __int64 v23; // rdx
  __int64 v24; // rcx
  CAkRSNode **v25; // rdx
  int v26; // ebx
  unsigned int v28; // [rsp+20h] [rbp-28h]
  unsigned int v29; // [rsp+24h] [rbp-24h]
  unsigned int v30; // [rsp+24h] [rbp-24h]
  unsigned __int64 v31; // [rsp+28h] [rbp-20h]
  unsigned __int64 v32; // [rsp+28h] [rbp-20h]
  AkMusicRanSeqPlaylistItem **in_pArrayItemsa; // [rsp+60h] [rbp+18h]

  in_pArrayItemsa = in_pArrayItems;
  v5 = 0;
  v28 = 0;
  if ( !in_ulNumItems )
    return 1i64;
  while ( 1 )
  {
    v6 = (*in_pArrayItems)++;
    if ( v6->m_SegmentID )
      break;
    v7 = (CAkRSSub *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x48ui64);
    v8 = v7;
    if ( !v7 )
      return 2i64;
    v7->m_pParent = in_pParent;
    v7->m_Weight = 50000;
    v7->m_ID = 0;
    v7->vfptr = (CAkRSNodeVtbl *)&CAkRSSub::`vftable;
    v7->m_listChildren.m_pItems = 0i64;
    *(_QWORD *)&v7->m_listChildren.m_uLength = 0i64;
    v7->m_eRSType = RSType_ContinuousSequence;
    v7->m_pGlobalCntrBaseInfo = 0i64;
    *(_WORD *)&v7->m_bIsUsingWeight = 256;
    v7->m_bHasSegmentLeaves = 0;
    v7->m_wAvoidRepeatCount = 0;
    m_uLength = in_pParent->m_listChildren.m_uLength;
    m_ulReserved = in_pParent->m_listChildren.m_ulReserved;
    v31 = m_uLength;
    if ( m_uLength >= m_ulReserved )
    {
      v29 = m_ulReserved + 8;
      v11 = (CAkRSNode **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * (unsigned int)(m_ulReserved + 8));
      if ( !v11 )
        goto LABEL_31;
      v12 = in_pParent->m_listChildren.m_uLength;
      if ( in_pParent->m_listChildren.m_pItems )
      {
        v13 = 0i64;
        if ( in_pParent->m_listChildren.m_uLength )
        {
          do
          {
            ++v13;
            v11[v13 - 1] = in_pParent->m_listChildren.m_pItems[v13 - 1];
          }
          while ( v13 < v12 );
        }
        AK::MemoryMgr::Free(g_DefaultPoolId, in_pParent->m_listChildren.m_pItems);
      }
      m_uLength = v31;
      in_pParent->m_listChildren.m_pItems = v11;
      v5 = v28;
      in_pParent->m_listChildren.m_ulReserved = v29;
    }
    if ( m_uLength >= in_pParent->m_listChildren.m_ulReserved )
      goto LABEL_31;
    v14 = in_pParent->m_listChildren.m_uLength;
    v15 = &in_pParent->m_listChildren.m_pItems[v14];
    in_pParent->m_listChildren.m_uLength = v14 + 1;
    if ( !v15 )
      goto LABEL_31;
    *v15 = v8;
    v8->m_wAvoidRepeatCount = v6->m_wAvoidRepeatCount;
    v8->m_Loop = v6->m_Loop;
    v8->m_Weight = v6->m_Weight;
    m_eRSType = v6->m_eRSType;
    v8->m_bIsUsingWeight = 0;
    v8->m_eRSType = m_eRSType;
    v8->m_bIsShuffle = v6->m_bIsShuffle;
    v8->m_ID = v6->m_playlistItemID;
    m_NumChildren = v6->m_NumChildren;
    if ( m_NumChildren
      && CAkMusicRanSeqCntr::AddPlaylistChildren(this, v8, in_pArrayItemsa, m_NumChildren) != AK_Success )
    {
      return 2i64;
    }
LABEL_27:
    if ( v6->m_Weight != 50000 )
      in_pParent->m_bIsUsingWeight = 1;
    v28 = ++v5;
    if ( v5 >= in_ulNumItems )
      return 1i64;
    in_pArrayItems = in_pArrayItemsa;
  }
  v18 = (CAkRSSub *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
  v8 = v18;
  if ( !v18 )
    return 2i64;
  v18->m_pParent = in_pParent;
  v18->m_Weight = 50000;
  v18->m_ID = 0;
  v18->vfptr = (CAkRSNodeVtbl *)&CAkRSSegment::`vftable;
  v19 = in_pParent->m_listChildren.m_uLength;
  v20 = in_pParent->m_listChildren.m_ulReserved;
  v32 = v19;
  if ( v19 >= v20 )
  {
    v30 = v20 + 8;
    v21 = (CAkRSNode **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * (unsigned int)(v20 + 8));
    if ( !v21 )
      goto LABEL_31;
    v22 = in_pParent->m_listChildren.m_uLength;
    if ( in_pParent->m_listChildren.m_pItems )
    {
      v23 = 0i64;
      if ( in_pParent->m_listChildren.m_uLength )
      {
        do
        {
          ++v23;
          v21[v23 - 1] = in_pParent->m_listChildren.m_pItems[v23 - 1];
        }
        while ( v23 < v22 );
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, in_pParent->m_listChildren.m_pItems);
    }
    v19 = v32;
    in_pParent->m_listChildren.m_pItems = v21;
    v5 = v28;
    in_pParent->m_listChildren.m_ulReserved = v30;
  }
  if ( v19 < in_pParent->m_listChildren.m_ulReserved )
  {
    v24 = in_pParent->m_listChildren.m_uLength;
    v25 = &in_pParent->m_listChildren.m_pItems[v24];
    in_pParent->m_listChildren.m_uLength = v24 + 1;
    if ( v25 )
    {
      *v25 = v8;
      v8->m_Loop = v6->m_Loop;
      v8->m_Weight = v6->m_Weight;
      LODWORD(v8->m_listChildren.m_pItems) = v6->m_SegmentID;
      v8->m_ID = v6->m_playlistItemID;
      CAkRSSub::WasSegmentLeafFound(in_pParent);
      goto LABEL_27;
    }
  }
LABEL_31:
  v26 = g_DefaultPoolId;
  v8->vfptr->__vecDelDtor(v8, 0);
  AK::MemoryMgr::Free(v26, v8);
  return 2i64;
}

