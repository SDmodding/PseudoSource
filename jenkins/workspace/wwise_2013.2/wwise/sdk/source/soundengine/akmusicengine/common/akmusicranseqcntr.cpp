// File Line: 31
// RVA: 0xAB1910
void __fastcall CAkMusicRanSeqCntr::CAkMusicRanSeqCntr(CAkMusicRanSeqCntr *this, unsigned int in_ulID)
{
  CAkMusicRanSeqCntr *v2; // rbx

  v2 = this;
  CAkMusicTransAware::CAkMusicTransAware((CAkMusicTransAware *)&this->vfptr, in_ulID);
  v2->vfptr = (CAkIndexableVtbl *)&CAkMusicRanSeqCntr::`vftable';
  v2->m_playListRoot.m_pParent = 0i64;
  v2->m_playListRoot.vfptr = (CAkRSNodeVtbl *)&CAkRSSub::`vftable';
  v2->m_playListRoot.m_ID = 0;
  v2->m_playListRoot.m_Weight = 50000;
  v2->m_playListRoot.m_listChildren.m_pItems = 0i64;
  *(_QWORD *)&v2->m_playListRoot.m_listChildren.m_uLength = 0i64;
  v2->m_playListRoot.m_eRSType = 0;
  v2->m_playListRoot.m_pGlobalCntrBaseInfo = 0i64;
  *(_WORD *)&v2->m_playListRoot.m_bIsUsingWeight = 256;
  v2->m_playListRoot.m_bHasSegmentLeaves = 0;
  v2->m_playListRoot.m_wAvoidRepeatCount = 0;
}

// File Line: 42
// RVA: 0xAB1E40
void __fastcall CAkMusicRanSeqCntr::Create(unsigned int in_ulID)
{
  unsigned int v1; // ebx
  CAkMusicRanSeqCntr *v2; // rax
  __int64 v3; // rax
  __int64 v4; // rbx
  unsigned int v5; // eax
  signed int v6; // ecx
  bool v7; // al

  v1 = in_ulID;
  v2 = (CAkMusicRanSeqCntr *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x120ui64);
  if ( v2 )
  {
    CAkMusicRanSeqCntr::CAkMusicRanSeqCntr(v2, v1);
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

// File Line: 56
// RVA: 0xAB2090
AKRESULT __fastcall CAkMusicRanSeqCntr::SetInitialValues(CAkMusicRanSeqCntr *this, char *in_pData, unsigned int in_ulDataSize)
{
  CAkMusicRanSeqCntr *v3; // r14
  AKRESULT result; // eax
  unsigned int v5; // ebx
  __int64 v6; // rsi
  AkMusicRanSeqPlaylistItem *v7; // rax
  AkMusicRanSeqPlaylistItem *v8; // rdi
  signed __int64 v9; // rdx
  unsigned int v10; // ecx
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  char *io_rpData; // [rsp+48h] [rbp+20h]
  unsigned int io_rulDataSize; // [rsp+50h] [rbp+28h]

  io_rulDataSize = in_ulDataSize;
  io_rpData = in_pData;
  v3 = this;
  result = CAkMusicTransAware::SetMusicTransNodeParams(
             (CAkMusicTransAware *)&this->vfptr,
             &io_rpData,
             &io_rulDataSize,
             0);
  if ( result == 1 )
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
      if ( v5 )
      {
        v9 = (signed __int64)&v7->m_NumChildren;
        do
        {
          v9 += 28i64;
          v10 = *(_DWORD *)io_rpData;
          io_rpData += 4;
          *(_DWORD *)(v9 - 36) = v10;
          v11 = *(_DWORD *)io_rpData;
          io_rpData += 4;
          *(_DWORD *)(v9 - 32) = v11;
          v12 = *(_DWORD *)io_rpData;
          io_rpData += 4;
          *(_DWORD *)(v9 - 28) = v12;
          v13 = *(_DWORD *)io_rpData;
          io_rpData += 4;
          *(_DWORD *)(v9 - 24) = v13;
          LOWORD(v13) = *(_WORD *)io_rpData;
          io_rpData += 2;
          *(_WORD *)(v9 - 20) = v13;
          v14 = *(_DWORD *)io_rpData;
          io_rpData += 4;
          *(_DWORD *)(v9 - 16) = v14;
          LOWORD(v14) = *(_WORD *)io_rpData;
          io_rpData += 2;
          *(_WORD *)(v9 - 12) = v14;
          LOBYTE(v14) = *io_rpData++;
          *(_BYTE *)(v9 - 10) = (_BYTE)v14 != 0;
          LOBYTE(v14) = *io_rpData++;
          *(_BYTE *)(v9 - 9) = (_BYTE)v14 != 0;
          --v6;
        }
        while ( v6 );
      }
      CAkMusicRanSeqCntr::SetPlayList(v3, v7);
      AK::MemoryMgr::Free(g_DefaultPoolId, v8);
    }
    result = 1;
  }
  return result;
}

// File Line: 102
// RVA: 0xAB1F70
void __fastcall CAkMusicRanSeqCntr::FlushPlaylist(CAkMusicRanSeqCntr *this)
{
  CAkRSNode **v1; // rbx
  CAkMusicRanSeqCntr *v2; // rbp
  CAkRSNode *v3; // rdi
  int v4; // esi

  v1 = this->m_playListRoot.m_listChildren.m_pItems;
  v2 = this;
  if ( v1 != &v1[this->m_playListRoot.m_listChildren.m_uLength] )
  {
    do
    {
      v3 = *v1;
      if ( *v1 )
      {
        v4 = g_DefaultPoolId;
        v3->vfptr->__vecDelDtor(*v1, 0);
        AK::MemoryMgr::Free(v4, v3);
      }
      ++v1;
    }
    while ( v1 != &v2->m_playListRoot.m_listChildren.m_pItems[v2->m_playListRoot.m_listChildren.m_uLength] );
  }
  v2->m_playListRoot.m_listChildren.m_uLength = 0;
  CAkRSSub::Clear(&v2->m_playListRoot);
}

// File Line: 122
// RVA: 0xAB1F60
__int64 __fastcall CAkMusicRanSeqCntr::ExecuteAction(CAkMusicRanSeqCntr *this, ActionParams *in_rAction)
{
  __int64 result; // rax

  if ( in_rAction->eType == 4 )
    result = 2i64;
  else
    result = CAkMusicNode::ExecuteAction((CAkMusicNode *)&this->vfptr, in_rAction);
  return result;
}

// File Line: 161
// RVA: 0xAB1DA0
signed __int64 __fastcall CAkMusicRanSeqCntr::CanAddChild(CAkMusicRanSeqCntr *this, CAkParameterNodeBase *in_pAudioNode)
{
  CAkMusicRanSeqCntr *v2; // rsi
  CAkParameterNodeBase *v3; // rdi
  unsigned int v4; // ebx
  unsigned int v5; // ebp
  unsigned int v7; // edi

  v2 = this;
  v3 = in_pAudioNode;
  v4 = 1;
  v5 = in_pAudioNode->vfptr[3].Release((CAkIndexable *)in_pAudioNode);
  if ( (unsigned __int16)v2->vfptr[20].Release((CAkIndexable *)&v2->vfptr) >= 0xFFFFu )
    return 9i64;
  if ( v5 != 7 )
    return 4i64;
  if ( v3->m_pParentNode )
    return 21i64;
  v7 = v3->key;
  if ( AkSortedKeyArray<unsigned long,CAkParameterNodeBase *,ArrayPoolDefault,AkChildIDValueGetKey,1>::Exists<unsigned long>(
         &v2->m_mapChildId,
         v7) )
  {
    return 5i64;
  }
  if ( v2->key == v7 )
    v4 = 23;
  return v4;
}

// File Line: 196
// RVA: 0xAB1EB0
CAkSequenceCtx *__fastcall CAkMusicRanSeqCntr::CreateContext(CAkMusicRanSeqCntr *this, CAkMatrixAwareCtx *in_pParentCtx, CAkRegisteredObj *in_GameObject, UserParams *in_rUserparams)
{
  return CAkMusicRanSeqCntr::CreateSequenceCtx(this, in_pParentCtx, in_GameObject, in_rUserparams);
}

// File Line: 205
// RVA: 0xAB1EC0
void __fastcall CAkMusicRanSeqCntr::CreateSequenceCtx(CAkMusicRanSeqCntr *this, CAkMatrixAwareCtx *in_pParentCtx, CAkRegisteredObj *in_GameObject, UserParams *in_rUserparams)
{
  CAkMusicRanSeqCntr *v4; // rdi
  CAkMatrixAwareCtx *v5; // rbx
  UserParams *v6; // rsi
  CAkRegisteredObj *v7; // rbp
  CAkSequenceCtx *v8; // rax
  CAkSequenceCtx *v9; // rax
  CAkMusicCtx *v10; // rbx

  v4 = this;
  v5 = in_pParentCtx;
  v6 = in_rUserparams;
  v7 = in_GameObject;
  v8 = (CAkSequenceCtx *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0xF0ui64);
  if ( v8 )
  {
    CAkSequenceCtx::CAkSequenceCtx(v8, v4, (CAkMusicCtx *)&v5->vfptr);
    v10 = (CAkMusicCtx *)&v9->vfptr;
    if ( v9 )
    {
      ++v9->m_uRefCount;
      if ( CAkSequenceCtx::Init(v9, v7, v6) != 1 )
        UFG::OnUnloadClass<UITest::HandleArrayTest>(v10);
      CAkMusicCtx::Release(v10);
    }
  }
}

// File Line: 228
// RVA: 0xAB2010
signed __int64 __fastcall CAkMusicRanSeqCntr::PlayInternal(CAkMusicRanSeqCntr *this, AkPBIParams *in_rPBIParams)
{
  AkPBIParams *v2; // rdi
  CAkMatrixAwareCtx *v3; // rax
  CAkMatrixAwareCtx *v4; // rbx
  TransParams *v5; // rdx
  __int64 v6; // r8
  AkMusicFade in_fadeParams; // [rsp+20h] [rbp-18h]

  v2 = in_rPBIParams;
  CAkMusicRanSeqCntr::CreateSequenceCtx(this, 0i64, in_rPBIParams->pGameObj, &in_rPBIParams->userParams);
  v4 = v3;
  if ( !v3 )
    return 2i64;
  v3->vfptr[1].OnResumed((CAkChildCtx *)&v3->vfptr);
  v5 = v2->pTransitionParameters;
  in_fadeParams.transitionTime = v5->TransitionTime;
  in_fadeParams.eFadeCurve = v5->eFadeCurve;
  in_fadeParams.iFadeOffset = CAkMatrixAwareCtx::GetSilentDuration(v4);
  CAkMusicCtx::_Play((CAkMusicCtx *)&v4->vfptr, &in_fadeParams, v6);
  return 1i64;
}

// File Line: 309
// RVA: 0xAB2210
signed __int64 __fastcall CAkMusicRanSeqCntr::SetPlayList(CAkMusicRanSeqCntr *this, AkMusicRanSeqPlaylistItem *in_pArrayItems)
{
  CAkMusicRanSeqCntr *v2; // rbx
  AkMusicRanSeqPlaylistItem *v3; // rdx
  RSType v4; // eax
  unsigned int v5; // er9
  signed __int64 result; // rax
  AkMusicRanSeqPlaylistItem *in_pArrayItemsa; // [rsp+38h] [rbp+10h]

  in_pArrayItemsa = in_pArrayItems;
  v2 = this;
  CAkMusicRanSeqCntr::FlushPlaylist(this);
  v3 = in_pArrayItemsa;
  ++in_pArrayItemsa;
  v2->m_playListRoot.m_wAvoidRepeatCount = v3->m_wAvoidRepeatCount;
  v2->m_playListRoot.m_Loop = v3->m_Loop;
  v2->m_playListRoot.m_Weight = v3->m_Weight;
  v4 = v3->m_eRSType;
  v2->m_playListRoot.m_bIsUsingWeight = 0;
  v2->m_playListRoot.m_eRSType = v4;
  v2->m_playListRoot.m_bIsShuffle = v3->m_bIsShuffle;
  v2->m_playListRoot.m_ID = v3->m_playlistItemID;
  v5 = v3->m_NumChildren;
  if ( v5 )
    result = CAkMusicRanSeqCntr::AddPlaylistChildren(v2, &v2->m_playListRoot, &in_pArrayItemsa, v5);
  else
    result = 1i64;
  return result;
}

// File Line: 420
// RVA: 0xAB1AB0
signed __int64 __fastcall CAkMusicRanSeqCntr::AddPlaylistChildren(CAkMusicRanSeqCntr *this, CAkRSSub *in_pParent, AkMusicRanSeqPlaylistItem **in_pArrayItems, unsigned int in_ulNumItems)
{
  CAkRSSub *v4; // rbx
  unsigned int v5; // ebp
  AkMusicRanSeqPlaylistItem *v6; // rsi
  CAkRSSub *v7; // rax
  CAkRSSub *v8; // rdi
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rax
  CAkRSNode **v11; // rbp
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rdx
  __int64 v14; // rcx
  CAkRSNode **v15; // rdx
  RSType v16; // eax
  unsigned int v17; // er9
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
  CAkMusicRanSeqCntr *v33; // [rsp+50h] [rbp+8h]
  AkMusicRanSeqPlaylistItem **in_pArrayItemsa; // [rsp+60h] [rbp+18h]
  unsigned int v35; // [rsp+68h] [rbp+20h]

  v35 = in_ulNumItems;
  in_pArrayItemsa = in_pArrayItems;
  v33 = this;
  v4 = in_pParent;
  v5 = 0;
  v28 = 0;
  if ( !in_ulNumItems )
    return 1i64;
  while ( 1 )
  {
    v6 = *in_pArrayItems;
    ++*in_pArrayItems;
    if ( v6->m_SegmentID )
      break;
    v7 = (CAkRSSub *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x48ui64);
    v8 = v7;
    if ( !v7 )
      return 2i64;
    v7->m_pParent = (CAkRSNode *)&v4->vfptr;
    v7->m_Weight = 50000;
    v7->m_ID = 0;
    v7->vfptr = (CAkRSNodeVtbl *)&CAkRSSub::`vftable';
    v7->m_listChildren.m_pItems = 0i64;
    *(_QWORD *)&v7->m_listChildren.m_uLength = 0i64;
    v7->m_eRSType = 0;
    v7->m_pGlobalCntrBaseInfo = 0i64;
    *(_WORD *)&v7->m_bIsUsingWeight = 256;
    v7->m_bHasSegmentLeaves = 0;
    v7->m_wAvoidRepeatCount = 0;
    v9 = v4->m_listChildren.m_uLength;
    v10 = v4->m_listChildren.m_ulReserved;
    v31 = v9;
    if ( v9 >= v10 )
    {
      v29 = v10 + 8;
      v11 = (CAkRSNode **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * (unsigned int)(v10 + 8));
      if ( !v11 )
        goto LABEL_31;
      v12 = v4->m_listChildren.m_uLength;
      if ( v4->m_listChildren.m_pItems )
      {
        v13 = 0i64;
        if ( v4->m_listChildren.m_uLength )
        {
          do
          {
            ++v13;
            v11[v13 - 1] = v4->m_listChildren.m_pItems[v13 - 1];
          }
          while ( v13 < v12 );
        }
        AK::MemoryMgr::Free(g_DefaultPoolId, v4->m_listChildren.m_pItems);
      }
      v9 = v31;
      v4->m_listChildren.m_pItems = v11;
      v5 = v28;
      v4->m_listChildren.m_ulReserved = v29;
    }
    if ( v9 >= v4->m_listChildren.m_ulReserved )
      goto LABEL_31;
    v14 = v4->m_listChildren.m_uLength;
    v15 = &v4->m_listChildren.m_pItems[v14];
    v4->m_listChildren.m_uLength = v14 + 1;
    if ( !v15 )
      goto LABEL_31;
    *v15 = (CAkRSNode *)&v8->vfptr;
    v8->m_wAvoidRepeatCount = v6->m_wAvoidRepeatCount;
    v8->m_Loop = v6->m_Loop;
    v8->m_Weight = v6->m_Weight;
    v16 = v6->m_eRSType;
    v8->m_bIsUsingWeight = 0;
    v8->m_eRSType = v16;
    v8->m_bIsShuffle = v6->m_bIsShuffle;
    v8->m_ID = v6->m_playlistItemID;
    v17 = v6->m_NumChildren;
    if ( v17 && CAkMusicRanSeqCntr::AddPlaylistChildren(v33, v8, in_pArrayItemsa, v17) != 1 )
      return 2i64;
LABEL_27:
    if ( v6->m_Weight != 50000 )
      v4->m_bIsUsingWeight = 1;
    v28 = ++v5;
    if ( v5 >= v35 )
      return 1i64;
    in_pArrayItems = in_pArrayItemsa;
  }
  v18 = (CAkRSSub *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
  v8 = v18;
  if ( !v18 )
    return 2i64;
  v18->m_pParent = (CAkRSNode *)&v4->vfptr;
  v18->m_Weight = 50000;
  v18->m_ID = 0;
  v18->vfptr = (CAkRSNodeVtbl *)&CAkRSSegment::`vftable';
  v19 = v4->m_listChildren.m_uLength;
  v20 = v4->m_listChildren.m_ulReserved;
  v32 = v19;
  if ( v19 >= v20 )
  {
    v30 = v20 + 8;
    v21 = (CAkRSNode **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * (unsigned int)(v20 + 8));
    if ( !v21 )
      goto LABEL_31;
    v22 = v4->m_listChildren.m_uLength;
    if ( v4->m_listChildren.m_pItems )
    {
      v23 = 0i64;
      if ( v4->m_listChildren.m_uLength )
      {
        do
        {
          ++v23;
          v21[v23 - 1] = v4->m_listChildren.m_pItems[v23 - 1];
        }
        while ( v23 < v22 );
      }
      AK::MemoryMgr::Free(g_DefaultPoolId, v4->m_listChildren.m_pItems);
    }
    v19 = v32;
    v4->m_listChildren.m_pItems = v21;
    v5 = v28;
    v4->m_listChildren.m_ulReserved = v30;
  }
  if ( v19 < v4->m_listChildren.m_ulReserved )
  {
    v24 = v4->m_listChildren.m_uLength;
    v25 = &v4->m_listChildren.m_pItems[v24];
    v4->m_listChildren.m_uLength = v24 + 1;
    if ( v25 )
    {
      *v25 = (CAkRSNode *)&v8->vfptr;
      v8->m_Loop = v6->m_Loop;
      v8->m_Weight = v6->m_Weight;
      LODWORD(v8->m_listChildren.m_pItems) = v6->m_SegmentID;
      v8->m_ID = v6->m_playlistItemID;
      CAkRSSub::WasSegmentLeafFound(v4);
      goto LABEL_27;
    }
  }
LABEL_31:
  v26 = g_DefaultPoolId;
  v8->vfptr->__vecDelDtor((CAkRSNode *)&v8->vfptr, 0);
  AK::MemoryMgr::Free(v26, v8);
  return 2i64;
}

