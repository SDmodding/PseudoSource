// File Line: 31
// RVA: 0xAB5580
void __fastcall CAkRSSub::~CAkRSSub(CAkRSSub *this)
{
  CAkContainerBaseInfo *m_pGlobalCntrBaseInfo; // rcx
  CAkRSNode **m_pItems; // rbx
  CAkRSNode *v4; // r14
  int v5; // esi

  this->vfptr = (CAkRSNodeVtbl *)&CAkRSSub::`vftable;
  m_pGlobalCntrBaseInfo = this->m_pGlobalCntrBaseInfo;
  if ( m_pGlobalCntrBaseInfo )
  {
    m_pGlobalCntrBaseInfo->vfptr->Destroy(m_pGlobalCntrBaseInfo);
    this->m_pGlobalCntrBaseInfo = 0i64;
  }
  m_pItems = this->m_listChildren.m_pItems;
  if ( m_pItems != &m_pItems[this->m_listChildren.m_uLength] )
  {
    do
    {
      v4 = *m_pItems;
      if ( *m_pItems )
      {
        v5 = g_DefaultPoolId;
        v4->vfptr->__vecDelDtor(*m_pItems, 0);
        AK::MemoryMgr::Free(v5, v4);
      }
      ++m_pItems;
    }
    while ( m_pItems != &this->m_listChildren.m_pItems[this->m_listChildren.m_uLength] );
  }
  if ( this->m_listChildren.m_pItems )
  {
    this->m_listChildren.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_listChildren.m_pItems);
    this->m_listChildren.m_pItems = 0i64;
    this->m_listChildren.m_ulReserved = 0;
  }
  this->vfptr = (CAkRSNodeVtbl *)&CAkRSNode::`vftable;
}

// File Line: 44
// RVA: 0xAB57C0
void __fastcall CAkRSSub::Clear(CAkRSSub *this)
{
  CAkContainerBaseInfo *m_pGlobalCntrBaseInfo; // rcx

  m_pGlobalCntrBaseInfo = this->m_pGlobalCntrBaseInfo;
  if ( m_pGlobalCntrBaseInfo )
  {
    m_pGlobalCntrBaseInfo->vfptr->Destroy(m_pGlobalCntrBaseInfo);
    this->m_pGlobalCntrBaseInfo = 0i64;
  }
}

// File Line: 53
// RVA: 0xAB7030
void __fastcall CAkRSSub::WasSegmentLeafFound(CAkRSSub *this)
{
  CAkRSSub *m_pParent; // rcx

  if ( this->m_bHasSegmentLeaves )
  {
    this->m_bHasSegmentLeaves = 1;
  }
  else
  {
    m_pParent = (CAkRSSub *)this->m_pParent;
    if ( m_pParent )
      CAkRSSub::WasSegmentLeafFound(m_pParent);
    this->m_bHasSegmentLeaves = 1;
  }
}

// File Line: 68
// RVA: 0xAB5780
__int64 __fastcall CAkRSSub::CalculateTotalWeight(CAkRSSub *this)
{
  CAkRSNode **m_pItems; // rdx
  __int64 result; // rax
  CAkRSNode **i; // r8
  __int64 v4; // rcx

  m_pItems = this->m_listChildren.m_pItems;
  result = 0i64;
  for ( i = &m_pItems[this->m_listChildren.m_uLength]; m_pItems != i; result = (unsigned int)(*(_DWORD *)(v4 + 24)
                                                                                            + result) )
    v4 = (__int64)*m_pItems++;
  return result;
}

// File Line: 78
// RVA: 0xAB5BB0
void __fastcall CAkRSSub::GetGlobalRSInfo(CAkRSSub *this)
{
  __int32 v2; // ecx
  CAkRandomInfo *v3; // rax
  CAkRandomInfo *v4; // rax
  CAkContainerBaseInfo *m_pGlobalCntrBaseInfo; // rdi
  int v6; // eax
  CAkSequenceInfo *v7; // rax
  CAkContainerBaseInfo *v8; // rax

  if ( !this->m_pGlobalCntrBaseInfo && this->m_listChildren.m_uLength )
  {
    v2 = this->m_eRSType - 1;
    if ( v2 )
    {
      if ( v2 == 2 )
      {
        v3 = (CAkRandomInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
        if ( v3 )
          CAkRandomInfo::CAkRandomInfo(v3, this->m_listChildren.m_uLength);
        else
          v4 = 0i64;
        this->m_pGlobalCntrBaseInfo = v4;
        if ( v4 && (unsigned int)CAkRandomInfo::Init(v4, this->m_wAvoidRepeatCount) != 1 )
        {
          this->m_pGlobalCntrBaseInfo->vfptr->Destroy(this->m_pGlobalCntrBaseInfo);
          this->m_pGlobalCntrBaseInfo = 0i64;
        }
        m_pGlobalCntrBaseInfo = this->m_pGlobalCntrBaseInfo;
        if ( m_pGlobalCntrBaseInfo )
        {
          if ( this->m_bIsUsingWeight )
          {
            v6 = CAkRSSub::CalculateTotalWeight(this);
            HIDWORD(m_pGlobalCntrBaseInfo[1].vfptr) = v6;
            LODWORD(this->m_pGlobalCntrBaseInfo[1].vfptr) = v6;
          }
        }
      }
    }
    else
    {
      v7 = (CAkSequenceInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
      if ( v7 )
      {
        CAkSequenceInfo::CAkSequenceInfo(v7);
        this->m_pGlobalCntrBaseInfo = v8;
      }
      else
      {
        this->m_pGlobalCntrBaseInfo = 0i64;
      }
    }
  }
}

// File Line: 128
// RVA: 0xAB6040
__int64 __fastcall RSStackItem::Init(RSStackItem *this, CAkRSSub *in_pSub)
{
  RSType m_eRSType; // ecx
  __int32 v5; // ecx
  __int32 v6; // ecx
  __int64 result; // rax
  CAkRandomInfo *v8; // rax
  CAkContainerBaseInfo *v9; // rax
  CAkRandomInfo *pLocalRSInfo; // rcx
  int v11; // eax
  CAkSequenceInfo *v12; // rax
  CAkContainerBaseInfo *v13; // rax
  CAkContainerBaseInfo *v14; // rsi

  this->pRSNode = in_pSub;
  *((_BYTE *)&this->m_Loop + 2) = *((_BYTE *)&this->m_Loop + 2) ^ (*((_BYTE *)&this->m_Loop + 2) ^ (2
                                                                                                  * (in_pSub->m_Loop == 0))) & 2 | 1;
  this->m_Loop.lLoopCount = in_pSub->m_Loop;
  m_eRSType = in_pSub->m_eRSType;
  if ( m_eRSType )
  {
    v5 = m_eRSType - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( !v6 )
      {
        if ( in_pSub->m_listChildren.m_uLength )
        {
          v8 = (CAkRandomInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
          if ( v8 )
            CAkRandomInfo::CAkRandomInfo(v8, in_pSub->m_listChildren.m_uLength);
          else
            v9 = 0i64;
          this->pLocalRSInfo = v9;
        }
        pLocalRSInfo = (CAkRandomInfo *)this->pLocalRSInfo;
        if ( pLocalRSInfo )
        {
          if ( (unsigned int)CAkRandomInfo::Init(pLocalRSInfo, in_pSub->m_wAvoidRepeatCount) == 1 )
          {
            if ( in_pSub->m_bIsUsingWeight )
            {
              v11 = CAkRSSub::CalculateTotalWeight(in_pSub);
              HIDWORD(this->pLocalRSInfo[1].vfptr) = v11;
              LODWORD(this->pLocalRSInfo[1].vfptr) = v11;
            }
            return 1i64;
          }
          this->pLocalRSInfo->vfptr->Destroy(this->pLocalRSInfo);
          this->pLocalRSInfo = 0i64;
        }
        return 2i64;
      }
      if ( v6 != 1 )
        return 2i64;
    }
    *((_BYTE *)&this->m_Loop + 2) |= 2u;
    return 1i64;
  }
  if ( in_pSub->m_listChildren.m_uLength )
  {
    v12 = (CAkSequenceInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
    if ( v12 )
    {
      CAkSequenceInfo::CAkSequenceInfo(v12);
      v14 = v13;
    }
    else
    {
      v14 = 0i64;
    }
    this->pLocalRSInfo = v14;
  }
  result = 2i64;
  if ( this->pLocalRSInfo )
    return 1i64;
  return result;
}

// File Line: 201
// RVA: 0xAB5550
void __fastcall AkRSIterator::AkRSIterator(AkRSIterator *this, CAkMusicRanSeqCntr *in_pRSCntr)
{
  this->m_pRSCntr = in_pRSCntr;
  this->m_stack.m_pItems = 0i64;
  *(_QWORD *)&this->m_stack.m_uLength = 0i64;
  *(_QWORD *)&this->m_actualSegment = 0i64;
  this->m_bIsSegmentValid = 0;
  this->m_arOriginalGlobalRSInfo.m_pItems = 0i64;
  *(_QWORD *)&this->m_arOriginalGlobalRSInfo.m_uLength = 0i64;
  *((_WORD *)this + 32) |= 1u;
  this->m_uSegmentLoopCount = 0;
}

// File Line: 209
// RVA: 0xAB5D80
__int64 __fastcall AkRSIterator::Init(AkRSIterator *this, unsigned int in_playingID)
{
  CAkMusicRanSeqCntr *m_pRSCntr; // rdi
  CAkRSSub *p_m_playListRoot; // rdi
  CAkRSSub *m_pParent; // r12
  bool v7; // bl
  unsigned __int16 v8; // di
  RSStackItem *m_pItems; // rax
  CAkRSSub *pRSNode; // r13
  RSStackItem *v11; // r15
  int m_eRSType; // eax
  unsigned __int16 v13; // ax
  unsigned int m_uLength; // ebx
  unsigned int m_ID; // r8d
  unsigned int m_playingID; // edx
  RSStackItem *v17; // rcx
  CAkContainerBaseInfo *v18; // rcx
  __int16 *pLocalRSInfo; // rbx
  __int16 *v20; // rax
  CAkRSSub *v21; // rdi
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v22; // rax
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v23; // rcx
  CAkContainerBaseInfo *v24; // rax
  CAkContainerBaseInfo *v25; // r14
  int v26; // ecx
  AkLoop *p_m_Loop; // rax
  char v28; // cl
  bool v29; // zf
  unsigned int v30; // eax
  unsigned int io_uSelection; // [rsp+70h] [rbp+8h] BYREF
  bool out_bIsEnd; // [rsp+78h] [rbp+10h] BYREF
  unsigned int io_uItemDone; // [rsp+80h] [rbp+18h] BYREF

  m_pRSCntr = this->m_pRSCntr;
  *((_WORD *)this + 32) |= 1u;
  this->m_playingID = in_playingID;
  this->m_actualSegment = 0;
  this->m_bIsSegmentValid = 1;
  p_m_playListRoot = &m_pRSCntr->m_playListRoot;
  if ( !p_m_playListRoot )
    return 2i64;
  while ( !p_m_playListRoot->vfptr->IsSegment(p_m_playListRoot) )
  {
    m_pParent = p_m_playListRoot;
    if ( p_m_playListRoot->m_listChildren.m_uLength && p_m_playListRoot->m_bHasSegmentLeaves )
    {
      if ( AkRSIterator::StackItem(this, p_m_playListRoot) != AK_Success )
      {
        AkRSIterator::Term(this);
        return 2i64;
      }
    }
    else
    {
      m_pParent = (CAkRSSub *)p_m_playListRoot->m_pParent;
      if ( !m_pParent )
        return 2i64;
    }
    v7 = 0;
    out_bIsEnd = 0;
    while ( 1 )
    {
      v8 = 0;
      m_pItems = this->m_stack.m_pItems;
      pRSNode = m_pItems[this->m_stack.m_uLength - 1].pRSNode;
      v11 = &m_pItems[this->m_stack.m_uLength];
      m_eRSType = pRSNode->m_eRSType;
      if ( m_eRSType < 0 )
        goto LABEL_14;
      if ( m_eRSType > 1 )
      {
        if ( m_eRSType <= 3 )
        {
          v13 = AkRSIterator::SelectRandomly(this, v11 - 1, &out_bIsEnd);
          v7 = out_bIsEnd;
          v8 = v13;
        }
LABEL_14:
        if ( v7 )
          goto LABEL_18;
        goto LABEL_15;
      }
      if ( ((m_eRSType - 1) & 0xFFFFFFFD) != 0 )
      {
        pLocalRSInfo = (__int16 *)v11[-1].pLocalRSInfo;
      }
      else
      {
        CAkRSSub::GetGlobalRSInfo(pRSNode);
        pLocalRSInfo = v20;
      }
      if ( !pLocalRSInfo )
      {
        v7 = 1;
        out_bIsEnd = 1;
        goto LABEL_18;
      }
      v21 = v11[-1].pRSNode;
      if ( (*((_BYTE *)this + 64) & 1) != 0 && pLocalRSInfo == (__int16 *)v21->m_pGlobalCntrBaseInfo )
      {
        v22 = this->m_arOriginalGlobalRSInfo.m_pItems;
        v23 = &v22[this->m_arOriginalGlobalRSInfo.m_uLength];
        if ( v22 == v23 )
          goto LABEL_53;
        do
        {
          if ( v22->key == v21 )
            break;
          ++v22;
        }
        while ( v22 != v23 );
        if ( v22 == v23 || v22 == (MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *)-8i64 )
        {
LABEL_53:
          v24 = (CAkContainerBaseInfo *)(*(__int64 (__fastcall **)(__int16 *, _QWORD))(*(_QWORD *)pLocalRSInfo + 24i64))(
                                          pLocalRSInfo,
                                          LOWORD(v21->m_listChildren.m_uLength));
          v25 = v24;
          if ( v24 )
          {
            if ( !CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4>::Set(&this->m_arOriginalGlobalRSInfo, v21, v24) )
              v25->vfptr->Destroy(v25);
          }
        }
      }
      v26 = pLocalRSInfo[5];
      if ( v26 + 1 == v21->m_listChildren.m_uLength )
      {
        p_m_Loop = &v11[-1].m_Loop;
        pLocalRSInfo[5] = 0;
        if ( v11 != (RSStackItem *)16 )
        {
          v28 = *((_BYTE *)p_m_Loop + 2);
          if ( (v28 & 1) == 0 || (v28 & 2) == 0 && (v29 = p_m_Loop->lLoopCount == 1, --p_m_Loop->lLoopCount, v29) )
          {
            v7 = 1;
            out_bIsEnd = 1;
            goto LABEL_18;
          }
        }
      }
      else
      {
        pLocalRSInfo[5] = v26 + 1;
      }
      v8 = pLocalRSInfo[5];
LABEL_15:
      m_uLength = pRSNode->m_listChildren.m_uLength;
      m_ID = pRSNode->m_ID;
      m_playingID = this->m_playingID;
      io_uSelection = v8;
      io_uItemDone = 0;
      CAkPlayingMgr::MusicPlaylistCallback(g_pPlayingMgr, m_playingID, m_ID, m_uLength, &io_uSelection, &io_uItemDone);
      if ( io_uSelection < m_uLength )
        v8 = io_uSelection;
      v7 = io_uItemDone != 0;
      out_bIsEnd = io_uItemDone != 0;
      if ( !io_uItemDone )
        break;
LABEL_18:
      p_m_playListRoot = (CAkRSSub *)m_pParent->m_pParent;
      v17 = &this->m_stack.m_pItems[this->m_stack.m_uLength];
      if ( (v17[-1].pRSNode->m_eRSType & 0xFFFFFFFD) == 0 )
      {
        v18 = v17[-1].pLocalRSInfo;
        if ( v18 )
          v18->vfptr->Destroy(v18);
      }
      --this->m_stack.m_uLength;
      if ( !v7 )
        goto LABEL_48;
      if ( !p_m_playListRoot )
        return 2i64;
    }
    p_m_playListRoot = (CAkRSSub *)m_pParent->m_listChildren.m_pItems[v8];
LABEL_48:
    if ( !p_m_playListRoot )
      return 2i64;
  }
  v30 = (unsigned int)p_m_playListRoot->m_listChildren.m_pItems;
  this->m_actualSegment = v30;
  this->m_bIsSegmentValid = v30 != 0;
  this->m_LastSegmentPlayingID = p_m_playListRoot->m_ID;
  this->m_uSegmentLoopCount = p_m_playListRoot->m_Loop;
  return 1i64;
}

// File Line: 260
// RVA: 0xAB57F0
void __fastcall AkRSIterator::EndInit(AkRSIterator *this)
{
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *m_pItems; // rbx

  m_pItems = this->m_arOriginalGlobalRSInfo.m_pItems;
  if ( m_pItems != &m_pItems[this->m_arOriginalGlobalRSInfo.m_uLength] )
  {
    do
    {
      m_pItems->item->vfptr->Destroy(m_pItems->item);
      ++m_pItems;
    }
    while ( m_pItems != &this->m_arOriginalGlobalRSInfo.m_pItems[this->m_arOriginalGlobalRSInfo.m_uLength] );
  }
  this->m_arOriginalGlobalRSInfo.m_uLength = 0;
  *((_WORD *)this + 32) &= ~1u;
}

// File Line: 276
// RVA: 0xAB6DB0
void __fastcall AkRSIterator::Term(AkRSIterator *this)
{
  RSStackItem *m_pItems; // rdx
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v3; // rbx

  AkRSIterator::FlushStack(this);
  m_pItems = this->m_stack.m_pItems;
  if ( m_pItems )
  {
    this->m_stack.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_stack.m_pItems = 0i64;
    this->m_stack.m_ulReserved = 0;
  }
  v3 = this->m_arOriginalGlobalRSInfo.m_pItems;
  if ( v3 != &v3[this->m_arOriginalGlobalRSInfo.m_uLength] )
  {
    do
    {
      v3->item->vfptr->Destroy(v3->item);
      ++v3;
    }
    while ( v3 != &this->m_arOriginalGlobalRSInfo.m_pItems[this->m_arOriginalGlobalRSInfo.m_uLength] );
  }
  if ( this->m_arOriginalGlobalRSInfo.m_pItems )
  {
    this->m_arOriginalGlobalRSInfo.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_arOriginalGlobalRSInfo.m_pItems);
    this->m_arOriginalGlobalRSInfo.m_pItems = 0i64;
    this->m_arOriginalGlobalRSInfo.m_ulReserved = 0;
  }
}

// File Line: 290
// RVA: 0xAB5920
void __fastcall AkRSIterator::FlushStack(AkRSIterator *this)
{
  RSStackItem *m_pItems; // rbx
  CAkContainerBaseInfo *pLocalRSInfo; // rcx

  m_pItems = this->m_stack.m_pItems;
  if ( m_pItems == &m_pItems[this->m_stack.m_uLength] )
  {
    this->m_stack.m_uLength = 0;
  }
  else
  {
    do
    {
      if ( (m_pItems->pRSNode->m_eRSType & 0xFFFFFFFD) == 0 )
      {
        pLocalRSInfo = m_pItems->pLocalRSInfo;
        if ( pLocalRSInfo )
          pLocalRSInfo->vfptr->Destroy(pLocalRSInfo);
      }
      ++m_pItems;
    }
    while ( m_pItems != &this->m_stack.m_pItems[this->m_stack.m_uLength] );
    this->m_stack.m_uLength = 0;
  }
}

// File Line: 306
// RVA: 0xAB6190
void __fastcall AkRSIterator::JumpNext(AkRSIterator *this)
{
  __int16 m_uSegmentLoopCount; // ax
  bool v3; // zf
  __int64 m_uLength; // rax
  CAkRSSub *pRSNode; // rdx
  CAkRSSub *v6; // rbx
  unsigned __int16 v7; // ax
  CAkRSSub *m_pParent; // rbx
  RSStackItem *v9; // rcx
  CAkContainerBaseInfo *pLocalRSInfo; // rcx
  unsigned int m_pItems; // eax
  bool out_bIsEnd; // [rsp+30h] [rbp+8h] BYREF

  m_uSegmentLoopCount = this->m_uSegmentLoopCount;
  if ( m_uSegmentLoopCount <= 1 )
  {
    if ( m_uSegmentLoopCount )
    {
      if ( this->m_actualSegment )
      {
        v3 = this->m_stack.m_uLength == 0;
        this->m_actualSegment = 0;
        this->m_bIsSegmentValid = 1;
        if ( !v3 )
        {
          m_uLength = this->m_stack.m_uLength;
          out_bIsEnd = 1;
          pRSNode = this->m_stack.m_pItems[m_uLength - 1].pRSNode;
LABEL_8:
          v6 = (CAkRSSub *)AkRSIterator::PopObsoleteStackedItems(this, pRSNode);
          while ( v6 )
          {
            v7 = AkRSIterator::Select(this, &this->m_stack.m_pItems[this->m_stack.m_uLength - 1], &out_bIsEnd);
            if ( out_bIsEnd )
            {
              m_pParent = (CAkRSSub *)v6->m_pParent;
              v9 = &this->m_stack.m_pItems[this->m_stack.m_uLength];
              if ( (v9[-1].pRSNode->m_eRSType & 0xFFFFFFFD) == 0 )
              {
                pLocalRSInfo = v9[-1].pLocalRSInfo;
                if ( pLocalRSInfo )
                  pLocalRSInfo->vfptr->Destroy(pLocalRSInfo);
              }
              --this->m_stack.m_uLength;
              pRSNode = m_pParent;
              goto LABEL_8;
            }
            v6 = (CAkRSSub *)v6->m_listChildren.m_pItems[v7];
            if ( v6->vfptr->IsSegment(v6) )
            {
              m_pItems = (unsigned int)v6->m_listChildren.m_pItems;
              this->m_actualSegment = m_pItems;
              this->m_bIsSegmentValid = m_pItems != 0;
              this->m_LastSegmentPlayingID = v6->m_ID;
              this->m_uSegmentLoopCount = v6->m_Loop;
              return;
            }
            if ( v6->m_listChildren.m_uLength && v6->m_bHasSegmentLeaves )
            {
              if ( AkRSIterator::StackItem(this, v6) != AK_Success )
              {
                AkRSIterator::Term(this);
                return;
              }
            }
            else
            {
              v6 = (CAkRSSub *)v6->m_pParent;
            }
            out_bIsEnd = 1;
          }
        }
      }
      else
      {
        this->m_bIsSegmentValid = 0;
      }
    }
  }
  else
  {
    this->m_uSegmentLoopCount = m_uSegmentLoopCount - 1;
  }
}

// File Line: 377
// RVA: 0xAB62F0
__int64 __fastcall AkRSIterator::JumpNextInternal(AkRSIterator *this)
{
  CAkRSSub *pRSNode; // rsi
  bool v3; // di
  unsigned __int16 v4; // bp
  RSStackItem *m_pItems; // rax
  __int64 v6; // rdx
  _DWORD *v7; // r14
  RSStackItem *v8; // rdx
  int v9; // eax
  unsigned __int16 v10; // ax
  unsigned int v11; // edi
  unsigned int v12; // r8d
  unsigned int m_playingID; // edx
  CAkRSNode *m_pParent; // rsi
  RSStackItem *v16; // rcx
  CAkContainerBaseInfo *pLocalRSInfo; // rcx
  unsigned int v18; // eax
  bool out_bIsEnd; // [rsp+60h] [rbp+8h] BYREF
  unsigned int io_uSelection; // [rsp+68h] [rbp+10h] BYREF
  unsigned int io_uItemDone; // [rsp+70h] [rbp+18h] BYREF

  this->m_bIsSegmentValid = 1;
  this->m_actualSegment = 0;
  if ( !this->m_stack.m_uLength )
    return 2i64;
  pRSNode = this->m_stack.m_pItems[this->m_stack.m_uLength - 1].pRSNode;
  while ( 2 )
  {
    v3 = 1;
    out_bIsEnd = 1;
    while ( 1 )
    {
      if ( !pRSNode )
        return 2i64;
      v4 = 0;
      m_pItems = this->m_stack.m_pItems;
      v6 = 3i64 * this->m_stack.m_uLength - 3;
      v7 = (_DWORD *)*((_QWORD *)&m_pItems->pRSNode + v6);
      v8 = (RSStackItem *)((char *)m_pItems + 8 * v6);
      v9 = v7[12];
      if ( v9 >= 0 )
      {
        if ( v9 <= 1 )
        {
          v10 = AkRSIterator::SelectSequentially(this, v8, &out_bIsEnd);
          goto LABEL_10;
        }
        if ( v9 <= 3 )
        {
          v10 = AkRSIterator::SelectRandomly(this, v8, &out_bIsEnd);
LABEL_10:
          v3 = out_bIsEnd;
          v4 = v10;
        }
      }
      if ( !v3 )
      {
        v11 = v7[10];
        v12 = v7[4];
        m_playingID = this->m_playingID;
        io_uSelection = v4;
        io_uItemDone = 0;
        CAkPlayingMgr::MusicPlaylistCallback(g_pPlayingMgr, m_playingID, v12, v11, &io_uSelection, &io_uItemDone);
        if ( io_uSelection < v11 )
          v4 = io_uSelection;
        v3 = io_uItemDone != 0;
        out_bIsEnd = io_uItemDone != 0;
        if ( !io_uItemDone )
          break;
      }
      m_pParent = pRSNode->m_pParent;
      v16 = &this->m_stack.m_pItems[this->m_stack.m_uLength];
      if ( (v16[-1].pRSNode->m_eRSType & 0xFFFFFFFD) == 0 )
      {
        pLocalRSInfo = v16[-1].pLocalRSInfo;
        if ( pLocalRSInfo )
          ((void (__fastcall *)(CAkContainerBaseInfo *, RSStackItem *))pLocalRSInfo->vfptr->Destroy)(pLocalRSInfo, v8);
      }
      --this->m_stack.m_uLength;
      pRSNode = (CAkRSSub *)AkRSIterator::PopObsoleteStackedItems(this, m_pParent);
      if ( !v3 )
        goto LABEL_24;
    }
    pRSNode = (CAkRSSub *)pRSNode->m_listChildren.m_pItems[v4];
    if ( !pRSNode->vfptr->IsSegment(pRSNode) )
    {
      if ( AkRSIterator::StackItem(this, pRSNode) == AK_Success )
        continue;
      AkRSIterator::Term(this);
      return 2i64;
    }
    break;
  }
LABEL_24:
  if ( !pRSNode )
    return 2i64;
  v18 = (unsigned int)pRSNode->m_listChildren.m_pItems;
  this->m_actualSegment = v18;
  this->m_bIsSegmentValid = v18 != 0;
  this->m_LastSegmentPlayingID = pRSNode->m_ID;
  this->m_uSegmentLoopCount = pRSNode->m_Loop;
  return 1i64;
}

// File Line: 423
// RVA: 0xAB64E0
__int64 __fastcall AkRSIterator::JumpTo(AkRSIterator *this, unsigned int in_playlistElementID)
{
  CAkMusicRanSeqCntr *m_pRSCntr; // rsi
  CAkRSSub *p_m_playListRoot; // rsi
  CAkRSNode *m_pItems; // rdx
  CAkRSNode **v7; // rbx
  __int64 m_uLength; // r8
  unsigned int v9; // r14d
  __int64 v10; // rax
  CAkRSNode **v11; // rcx
  AKRESULT v12; // eax
  CAkRSNode **v13; // rbx
  CAkRSNode **v14; // rbx
  CAkRSNode *v15; // rsi
  int m_ID; // ecx
  unsigned int vfptr; // eax
  __int64 result; // rax
  unsigned int v19; // ebx
  AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> in_pvMemAddress; // [rsp+30h] [rbp-10h] BYREF
  bool io_bFound; // [rsp+70h] [rbp+30h] BYREF

  AkRSIterator::RevertGlobalRSInfo(this);
  AkRSIterator::FlushStack(this);
  m_pRSCntr = this->m_pRSCntr;
  this->m_actualSegment = 0;
  this->m_bIsSegmentValid = 1;
  in_pvMemAddress.m_pItems = 0i64;
  *(_QWORD *)&in_pvMemAddress.m_uLength = 0i64;
  io_bFound = 0;
  p_m_playListRoot = &m_pRSCntr->m_playListRoot;
  v7 = (CAkRSNode **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  v9 = 2;
  if ( !v7
    || (m_pItems = (CAkRSNode *)in_pvMemAddress.m_pItems,
        m_uLength = in_pvMemAddress.m_uLength,
        v10 = in_pvMemAddress.m_uLength,
        ++in_pvMemAddress.m_uLength,
        in_pvMemAddress.m_pItems = v7,
        v11 = &v7[v10],
        in_pvMemAddress.m_ulReserved = 8,
        !v11) )
  {
    v12 = AK_Fail;
    goto LABEL_15;
  }
  *v11 = p_m_playListRoot;
  if ( p_m_playListRoot->m_ID != in_playlistElementID )
  {
    if ( !((unsigned __int8 (__fastcall *)(CAkRSSub *, CAkRSNode *, __int64))p_m_playListRoot->vfptr->IsSegment)(
            p_m_playListRoot,
            m_pItems,
            m_uLength) )
    {
      v13 = p_m_playListRoot->m_listChildren.m_pItems;
      if ( io_bFound )
      {
LABEL_13:
        v12 = AK_Success;
        goto LABEL_15;
      }
      while ( v13 != &p_m_playListRoot->m_listChildren.m_pItems[p_m_playListRoot->m_listChildren.m_uLength] )
      {
        v12 = AkRSIterator::FindAndSelect(this, *v13, in_playlistElementID, &in_pvMemAddress, &io_bFound);
        if ( v12 == AK_Success )
        {
          ++v13;
          if ( !io_bFound )
            continue;
        }
        goto LABEL_15;
      }
    }
    if ( !io_bFound )
      --in_pvMemAddress.m_uLength;
    goto LABEL_13;
  }
  io_bFound = 1;
  v12 = AK_Success;
LABEL_15:
  if ( io_bFound
    && v12 == AK_Success
    && (v14 = in_pvMemAddress.m_pItems, in_pvMemAddress.m_pItems != &in_pvMemAddress.m_pItems[in_pvMemAddress.m_uLength]) )
  {
    while ( 1 )
    {
      v15 = *v14;
      if ( ((unsigned __int8 (__fastcall *)(CAkRSNode *, CAkRSNode *, __int64))(*v14)->vfptr->IsSegment)(
             *v14,
             m_pItems,
             m_uLength) )
      {
LABEL_27:
        vfptr = (unsigned int)v15[1].vfptr;
        v9 = 1;
        this->m_actualSegment = vfptr;
        this->m_bIsSegmentValid = vfptr != 0;
        this->m_LastSegmentPlayingID = v15->m_ID;
        this->m_uSegmentLoopCount = v15->m_Loop;
        goto LABEL_28;
      }
      if ( AkRSIterator::StackItem(this, (CAkRSSub *)v15) != AK_Success )
      {
        AkRSIterator::Term(this);
        goto LABEL_28;
      }
      if ( ++v14 == &in_pvMemAddress.m_pItems[in_pvMemAddress.m_uLength] )
        break;
      m_pItems = *v14;
      m_ID = (*v14)->m_pParent[1].m_ID;
      if ( m_ID >= 0 )
      {
        if ( m_ID <= 1 )
        {
          AkRSIterator::ForceSelectSequentially(this, m_pItems);
        }
        else if ( m_ID <= 3 )
        {
          AkRSIterator::ForceSelectRandomly(this, m_pItems);
        }
      }
      if ( v14 == &in_pvMemAddress.m_pItems[in_pvMemAddress.m_uLength] )
        goto LABEL_27;
    }
    result = AkRSIterator::JumpNextInternal(this);
    v19 = result;
    if ( in_pvMemAddress.m_pItems )
    {
      in_pvMemAddress.m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, in_pvMemAddress.m_pItems);
      return v19;
    }
  }
  else
  {
LABEL_28:
    if ( in_pvMemAddress.m_pItems )
    {
      in_pvMemAddress.m_uLength = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, in_pvMemAddress.m_pItems);
    }
    return v9;
  }
  return result;
}

// File Line: 495
// RVA: 0xAB5850
AKRESULT __fastcall AkRSIterator::FindAndSelect(
        AkRSIterator *this,
        CAkRSNode *in_pNode,
        unsigned int in_playlistElementID,
        AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *io_jmpList,
        bool *io_bFound)
{
  AKRESULT result; // eax
  CAkRSNodeVtbl *vfptr; // rbx

  if ( !AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault>::AddLast(io_jmpList, in_pNode) )
    return 2;
  if ( in_pNode->m_ID != in_playlistElementID )
  {
    if ( !in_pNode->vfptr->IsSegment(in_pNode) )
    {
      vfptr = in_pNode[1].vfptr;
      if ( *io_bFound )
        return 1;
      do
      {
        if ( vfptr == (CAkRSNodeVtbl *)((char *)in_pNode[1].vfptr + 8 * LODWORD(in_pNode[1].m_pParent)) )
          break;
        result = AkRSIterator::FindAndSelect(
                   this,
                   (CAkRSNode *)vfptr->__vecDelDtor,
                   in_playlistElementID,
                   io_jmpList,
                   io_bFound);
        if ( result != AK_Success )
          return result;
        vfptr = (CAkRSNodeVtbl *)((char *)vfptr + 8);
      }
      while ( !*io_bFound );
    }
    if ( !*io_bFound )
      --io_jmpList->m_uLength;
    return 1;
  }
  *io_bFound = 1;
  return 1;
}

// File Line: 526
// RVA: 0xAB6760
CAkRSNode *__fastcall AkRSIterator::PopObsoleteStackedItems(AkRSIterator *this, CAkRSNode *in_pNode)
{
  CAkRSNode *v2; // rbx
  RSStackItem *v4; // rcx
  __int16 lLoopCount; // ax
  CAkContainerBaseInfo *pLocalRSInfo; // rcx

  v2 = in_pNode;
  if ( in_pNode )
  {
    while ( (v2[1].m_ID & 0xFFFFFFFD) != 0 )
    {
      v4 = &this->m_stack.m_pItems[this->m_stack.m_uLength];
      lLoopCount = v4[-1].m_Loop.lLoopCount;
      if ( !lLoopCount )
        break;
      if ( lLoopCount > 1 )
      {
        --this->m_stack.m_pItems[this->m_stack.m_uLength - 1].m_Loop.lLoopCount;
        return v2;
      }
      v2 = v2->m_pParent;
      if ( (v4[-1].pRSNode->m_eRSType & 0xFFFFFFFD) == 0 )
      {
        pLocalRSInfo = v4[-1].pLocalRSInfo;
        if ( pLocalRSInfo )
          pLocalRSInfo->vfptr->Destroy(pLocalRSInfo);
      }
      --this->m_stack.m_uLength;
      if ( !v2 )
        return 0i64;
    }
  }
  return v2;
}

// File Line: 548
// RVA: 0xAB6D20
__int64 __fastcall AkRSIterator::StackItem(AkRSIterator *this, CAkRSSub *in_pSub)
{
  RSStackItem *v3; // rax
  RSStackItem v5; // [rsp+20h] [rbp-28h] BYREF

  *((_BYTE *)&v5.m_Loop + 2) &= 0xFCu;
  v5.m_Loop.lLoopCount = 0;
  v5.pLocalRSInfo = 0i64;
  if ( (unsigned int)RSStackItem::Init(&v5, in_pSub) == 1
    && (v3 = AkArray<RSStackItem,RSStackItem const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast(&this->m_stack)) != 0i64 )
  {
    *v3 = v5;
    return 1i64;
  }
  else
  {
    if ( (v5.pRSNode->m_eRSType & 0xFFFFFFFD) == 0 )
    {
      if ( v5.pLocalRSInfo )
        v5.pLocalRSInfo->vfptr->Destroy(v5.pLocalRSInfo);
    }
    return 2i64;
  }
}

// File Line: 560
// RVA: 0xAB6910
__int64 __fastcall AkRSIterator::Select(AkRSIterator *this, RSStackItem *in_rStackItem, bool *out_bIsEnd)
{
  CAkRSSub *pRSNode; // r14
  RSType m_eRSType; // eax
  unsigned __int16 v7; // di
  unsigned __int16 v8; // ax
  unsigned int m_ID; // r8d
  unsigned int m_playingID; // edx
  unsigned int m_uLength; // ebx
  unsigned int io_uSelection; // [rsp+68h] [rbp+10h] BYREF
  unsigned int io_uItemDone; // [rsp+78h] [rbp+20h] BYREF

  pRSNode = in_rStackItem->pRSNode;
  m_eRSType = in_rStackItem->pRSNode->m_eRSType;
  v7 = 0;
  if ( m_eRSType >= RSType_ContinuousSequence )
  {
    if ( m_eRSType <= RSType_StepSequence )
    {
      v8 = AkRSIterator::SelectSequentially(this, in_rStackItem, out_bIsEnd);
    }
    else
    {
      if ( m_eRSType > RSType_StepRandom )
        goto LABEL_7;
      v8 = AkRSIterator::SelectRandomly(this, in_rStackItem, out_bIsEnd);
    }
    v7 = v8;
  }
LABEL_7:
  if ( !*out_bIsEnd )
  {
    m_ID = pRSNode->m_ID;
    m_playingID = this->m_playingID;
    m_uLength = pRSNode->m_listChildren.m_uLength;
    io_uSelection = v7;
    io_uItemDone = 0;
    CAkPlayingMgr::MusicPlaylistCallback(g_pPlayingMgr, m_playingID, m_ID, m_uLength, &io_uSelection, &io_uItemDone);
    if ( io_uSelection < m_uLength )
      v7 = io_uSelection;
    *out_bIsEnd = io_uItemDone != 0;
  }
  return v7;
}

// File Line: 614
// RVA: 0xAB6BD0
__int64 __fastcall AkRSIterator::SelectSequentially(AkRSIterator *this, RSStackItem *in_rStackItem, bool *out_bIsEnd)
{
  CAkContainerBaseInfo *pLocalRSInfo; // rbx
  CAkContainerBaseInfo *v7; // rax
  __int64 result; // rax
  CAkRSSub *pRSNode; // rsi
  int v10; // ecx
  AkLoop *p_m_Loop; // rcx
  char v12; // dl
  bool v13; // zf

  *out_bIsEnd = 0;
  if ( ((in_rStackItem->pRSNode->m_eRSType - 1) & 0xFFFFFFFD) != 0 )
  {
    pLocalRSInfo = in_rStackItem->pLocalRSInfo;
  }
  else
  {
    CAkRSSub::GetGlobalRSInfo(in_rStackItem->pRSNode);
    pLocalRSInfo = v7;
  }
  if ( !pLocalRSInfo )
  {
    *out_bIsEnd = 1;
    return 0i64;
  }
  pRSNode = in_rStackItem->pRSNode;
  if ( (*((_BYTE *)this + 64) & 1) != 0 && pLocalRSInfo == pRSNode->m_pGlobalCntrBaseInfo )
    AkRSIterator::SaveOriginalGlobalRSInfo(this, in_rStackItem->pRSNode, pLocalRSInfo);
  v10 = SWORD1(pLocalRSInfo[1].vfptr);
  if ( v10 + 1 == pRSNode->m_listChildren.m_uLength )
  {
    result = 0i64;
    p_m_Loop = &in_rStackItem->m_Loop;
    WORD1(pLocalRSInfo[1].vfptr) = 0;
    if ( in_rStackItem != (RSStackItem *)-8i64 )
    {
      v12 = *((_BYTE *)&in_rStackItem->m_Loop + 2);
      if ( (v12 & 1) == 0 || (v12 & 2) == 0 && (v13 = p_m_Loop->lLoopCount == 1, --p_m_Loop->lLoopCount, v13) )
      {
        *out_bIsEnd = 1;
        return result;
      }
    }
  }
  else
  {
    WORD1(pLocalRSInfo[1].vfptr) = v10 + 1;
  }
  return WORD1(pLocalRSInfo[1].vfptr);
}

// File Line: 650
// RVA: 0xAB69C0
__int64 __fastcall AkRSIterator::SelectRandomly(AkRSIterator *this, RSStackItem *in_rStackItem, bool *out_bIsEnd)
{
  CAkRandomInfo *in_pRanInfo; // rdi
  CAkRandomInfo *v7; // rax
  __int64 v8; // rbx
  CAkRSSub *pRSNode; // rbp
  int v10; // esi
  AkLoop *p_m_Loop; // r14
  char v12; // al
  bool v13; // zf
  unsigned __int16 *m_pItems; // r9
  unsigned int m_ulTotalWeight; // r8d
  unsigned __int16 *i; // rax
  __int64 v17; // rdx
  int RandomValue; // r14d
  int v19; // r14d

  *out_bIsEnd = 0;
  if ( ((in_rStackItem->pRSNode->m_eRSType - 1) & 0xFFFFFFFD) != 0 )
  {
    in_pRanInfo = (CAkRandomInfo *)in_rStackItem->pLocalRSInfo;
  }
  else
  {
    CAkRSSub::GetGlobalRSInfo(in_rStackItem->pRSNode);
    in_pRanInfo = v7;
  }
  v8 = 0i64;
  if ( in_pRanInfo )
  {
    pRSNode = in_rStackItem->pRSNode;
    v10 = -1;
    if ( !in_pRanInfo->m_wCounter )
    {
      p_m_Loop = &in_rStackItem->m_Loop;
      if ( p_m_Loop )
      {
        v12 = *((_BYTE *)p_m_Loop + 2);
        if ( (v12 & 1) == 0 || (v12 & 2) == 0 && (v13 = p_m_Loop->lLoopCount == 1, --p_m_Loop->lLoopCount, v13) )
        {
          *out_bIsEnd = 1;
          return (unsigned __int16)v8;
        }
      }
      in_pRanInfo->m_wCounter = pRSNode->m_listChildren.m_uLength;
      CAkRandomInfo::ResetFlagsPlayed(in_pRanInfo, pRSNode->m_listChildren.m_uLength);
      m_pItems = in_pRanInfo->m_listAvoid.m_pItems;
      m_ulTotalWeight = in_pRanInfo->m_ulTotalWeight;
      in_pRanInfo->m_ulRemainingWeight = m_ulTotalWeight;
      for ( i = m_pItems;
            i != &m_pItems[in_pRanInfo->m_listAvoid.m_uLength];
            in_pRanInfo->m_ulRemainingWeight = m_ulTotalWeight )
      {
        v17 = *i++;
        m_ulTotalWeight -= pRSNode->m_listChildren.m_pItems[v17]->m_Weight;
      }
      in_pRanInfo->m_wRemainingItemsToPlay -= LOWORD(in_pRanInfo->m_listAvoid.m_uLength);
    }
    if ( pRSNode->m_bIsUsingWeight )
    {
      if ( !in_pRanInfo->m_ulRemainingWeight )
      {
LABEL_17:
        in_pRanInfo->m_wCounter = 0;
        return (unsigned __int16)v8;
      }
      RandomValue = CAkRandomInfo::GetRandomValue(in_pRanInfo);
      if ( RandomValue <= -1 )
      {
LABEL_38:
        LOWORD(v8) = v8 - 1;
        AkRSIterator::UpdateRandomItem(this, pRSNode, v8, &pRSNode->m_listChildren, in_pRanInfo);
        return (unsigned __int16)v8;
      }
      while ( 1 )
      {
        if ( pRSNode->m_bIsShuffle )
        {
          if ( CAkRandomInfo::IsFlagSetPlayed(in_pRanInfo, v8) || CAkRandomInfo::IsFlagBlocked(in_pRanInfo, v8) )
            goto LABEL_26;
        }
        else if ( pRSNode->m_wAvoidRepeatCount && CAkRandomInfo::IsFlagBlocked(in_pRanInfo, v8) )
        {
          goto LABEL_26;
        }
        v10 += pRSNode->m_listChildren.m_pItems[v8]->m_Weight;
LABEL_26:
        v8 = (unsigned int)(v8 + 1);
        if ( v10 >= RandomValue )
          goto LABEL_38;
      }
    }
    if ( !in_pRanInfo->m_wRemainingItemsToPlay )
      goto LABEL_17;
    v19 = (unsigned __int16)(rand() % in_pRanInfo->m_wRemainingItemsToPlay);
    while ( 1 )
    {
      if ( pRSNode->m_bIsShuffle )
      {
        if ( CAkRandomInfo::IsFlagSetPlayed(in_pRanInfo, v8) || CAkRandomInfo::IsFlagBlocked(in_pRanInfo, v8) )
          goto LABEL_37;
      }
      else if ( pRSNode->m_wAvoidRepeatCount && CAkRandomInfo::IsFlagBlocked(in_pRanInfo, v8) )
      {
        goto LABEL_37;
      }
      ++v10;
LABEL_37:
      LOWORD(v8) = v8 + 1;
      if ( v10 >= v19 )
        goto LABEL_38;
    }
  }
  *out_bIsEnd = 1;
  return (unsigned __int16)v8;
}

// File Line: 742
// RVA: 0xAB59A0
void __fastcall AkRSIterator::ForceSelectRandomly(AkRSIterator *this, CAkRSNode *in_pForcedNode)
{
  CAkRSSub *m_pParent; // r13
  unsigned __int16 v3; // bp
  CAkRSNode **m_pItems; // rax
  CAkRSNode **i; // rdi
  RSStackItem *v7; // rbx
  CAkRSSub *pRSNode; // rcx
  CAkRandomInfo *in_pRanInfo; // rbx
  unsigned __int16 *v10; // rdi
  unsigned __int16 *v11; // rax
  unsigned __int16 *v12; // rsi
  unsigned __int64 j; // rcx
  unsigned __int16 *v14; // rsi
  unsigned int m_ulTotalWeight; // edi
  unsigned __int16 *k; // rax
  __int64 v17; // rdx

  m_pParent = (CAkRSSub *)in_pForcedNode->m_pParent;
  v3 = 0;
  m_pItems = m_pParent->m_listChildren.m_pItems;
  for ( i = &m_pItems[m_pParent->m_listChildren.m_uLength]; m_pItems != i; ++v3 )
  {
    if ( *m_pItems == in_pForcedNode )
      break;
    ++m_pItems;
  }
  v7 = &this->m_stack.m_pItems[this->m_stack.m_uLength];
  pRSNode = v7[-1].pRSNode;
  if ( ((pRSNode->m_eRSType - 1) & 0xFFFFFFFD) != 0 )
    in_pRanInfo = (CAkRandomInfo *)v7[-1].pLocalRSInfo;
  else
    in_pRanInfo = (CAkRandomInfo *)CAkRSSub::GetGlobalRSInfo(pRSNode);
  if ( in_pRanInfo )
  {
    CAkRandomInfo::FlagAsUnBlocked(in_pRanInfo, v3);
    v10 = in_pRanInfo->m_listAvoid.m_pItems;
    v11 = &v10[in_pRanInfo->m_listAvoid.m_uLength];
    if ( v10 != v11 )
    {
      do
      {
        if ( *v10 == v3 )
          break;
        ++v10;
      }
      while ( v10 != v11 );
      if ( v10 != v11 )
      {
        if ( v10 < v11 - 1 )
        {
          v12 = v10 + 1;
          for ( j = ((unsigned __int64)((char *)(v11 - 1) - (char *)v10 - 1) >> 1) + 1; j; --j )
            *v10++ = *v12++;
        }
        --in_pRanInfo->m_listAvoid.m_uLength;
      }
    }
    in_pRanInfo->m_wCounter = m_pParent->m_listChildren.m_uLength;
    CAkRandomInfo::ResetFlagsPlayed(in_pRanInfo, m_pParent->m_listChildren.m_uLength);
    v14 = in_pRanInfo->m_listAvoid.m_pItems;
    m_ulTotalWeight = in_pRanInfo->m_ulTotalWeight;
    in_pRanInfo->m_ulRemainingWeight = m_ulTotalWeight;
    for ( k = v14; k != &v14[in_pRanInfo->m_listAvoid.m_uLength]; in_pRanInfo->m_ulRemainingWeight = m_ulTotalWeight )
    {
      v17 = *k++;
      m_ulTotalWeight -= m_pParent->m_listChildren.m_pItems[v17]->m_Weight;
    }
    in_pRanInfo->m_wRemainingItemsToPlay -= LOWORD(in_pRanInfo->m_listAvoid.m_uLength);
    AkRSIterator::UpdateRandomItem(this, m_pParent, v3, &m_pParent->m_listChildren, in_pRanInfo);
  }
}

// File Line: 785
// RVA: 0xAB6E50
void __fastcall AkRSIterator::UpdateRandomItem(
        AkRSIterator *this,
        CAkRSSub *in_pSub,
        unsigned __int16 in_wPosition,
        AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *in_pRSList,
        CAkRandomInfo *in_pRanInfo)
{
  unsigned __int16 *v8; // rax
  unsigned __int16 v9; // cx
  __int64 v10; // rdi
  unsigned int v11; // eax
  unsigned __int16 m_wAvoidRepeatCount; // di
  unsigned int m_Weight; // eax
  unsigned __int16 *v14; // rax
  unsigned __int16 v15; // ax
  unsigned __int16 *m_pItems; // rdi
  unsigned __int16 v17; // bp
  unsigned __int16 *v18; // rsi
  unsigned __int64 i; // rcx

  if ( (*((_BYTE *)this + 64) & 1) != 0 && in_pRanInfo == in_pSub->m_pGlobalCntrBaseInfo )
    AkRSIterator::SaveOriginalGlobalRSInfo(this, in_pSub, in_pRanInfo);
  if ( in_pSub->m_bIsShuffle )
  {
    m_wAvoidRepeatCount = in_pSub->m_wAvoidRepeatCount;
    if ( !m_wAvoidRepeatCount )
      m_wAvoidRepeatCount = 1;
    m_Weight = in_pRSList->m_pItems[in_wPosition]->m_Weight;
    --in_pRanInfo->m_wRemainingItemsToPlay;
    --in_pRanInfo->m_wCounter;
    in_pRanInfo->m_ulRemainingWeight -= m_Weight;
    CAkRandomInfo::FlagSetPlayed(in_pRanInfo, in_wPosition);
    v14 = AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&in_pRanInfo->m_listAvoid);
    if ( !v14 )
      goto LABEL_25;
    *v14 = in_wPosition;
    CAkRandomInfo::FlagAsBlocked(in_pRanInfo, in_wPosition);
    v15 = LOWORD(in_pRSList->m_uLength) - 1;
    if ( m_wAvoidRepeatCount < v15 )
      v15 = m_wAvoidRepeatCount;
    if ( in_pRanInfo->m_listAvoid.m_uLength > v15 )
    {
      m_pItems = in_pRanInfo->m_listAvoid.m_pItems;
      v17 = *m_pItems;
      if ( m_pItems < &m_pItems[in_pRanInfo->m_listAvoid.m_uLength - 1] )
      {
        v18 = m_pItems + 1;
        for ( i = ((2 * ((unsigned __int64)in_pRanInfo->m_listAvoid.m_uLength - 1) - 1) >> 1) + 1; i; --i )
          *m_pItems++ = *v18++;
      }
      --in_pRanInfo->m_listAvoid.m_uLength;
      CAkRandomInfo::FlagAsUnBlocked(in_pRanInfo, v17);
      if ( !CAkRandomInfo::IsFlagSetPlayed(in_pRanInfo, v17) )
      {
        in_pRanInfo->m_ulRemainingWeight += in_pRSList->m_pItems[v17]->m_Weight;
        ++in_pRanInfo->m_wRemainingItemsToPlay;
      }
    }
  }
  else
  {
    if ( !CAkRandomInfo::IsFlagSetPlayed(in_pRanInfo, in_wPosition) )
    {
      CAkRandomInfo::FlagSetPlayed(in_pRanInfo, in_wPosition);
      --in_pRanInfo->m_wCounter;
    }
    if ( in_pSub->m_wAvoidRepeatCount )
    {
      --in_pRanInfo->m_wRemainingItemsToPlay;
      v8 = AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&in_pRanInfo->m_listAvoid);
      if ( v8 )
      {
        *v8 = in_wPosition;
        CAkRandomInfo::FlagAsBlocked(in_pRanInfo, in_wPosition);
        in_pRanInfo->m_ulRemainingWeight -= in_pRSList->m_pItems[in_wPosition]->m_Weight;
        v9 = LOWORD(in_pRSList->m_uLength) - 1;
        if ( in_pSub->m_wAvoidRepeatCount < v9 )
          v9 = in_pSub->m_wAvoidRepeatCount;
        if ( in_pRanInfo->m_listAvoid.m_uLength > v9 )
        {
          v10 = *in_pRanInfo->m_listAvoid.m_pItems;
          CAkRandomInfo::FlagAsUnBlocked(in_pRanInfo, *in_pRanInfo->m_listAvoid.m_pItems);
          v11 = in_pRSList->m_pItems[v10]->m_Weight;
          ++in_pRanInfo->m_wRemainingItemsToPlay;
          in_pRanInfo->m_ulRemainingWeight += v11;
          AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Erase(
            &in_pRanInfo->m_listAvoid,
            0);
        }
        return;
      }
LABEL_25:
      in_pRanInfo->m_wCounter = 0;
    }
  }
}

// File Line: 858
// RVA: 0xAB67F0
void __fastcall AkRSIterator::RevertGlobalRSInfo(AkRSIterator *this)
{
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *m_pItems; // rbx
  CAkRSSub *key; // rsi
  CAkContainerBaseInfo *item; // rdi

  m_pItems = this->m_arOriginalGlobalRSInfo.m_pItems;
  if ( m_pItems == &m_pItems[this->m_arOriginalGlobalRSInfo.m_uLength] )
  {
    this->m_arOriginalGlobalRSInfo.m_uLength = 0;
  }
  else
  {
    do
    {
      key = m_pItems->key;
      item = m_pItems->item;
      m_pItems->key->m_pGlobalCntrBaseInfo->vfptr->Destroy(m_pItems->key->m_pGlobalCntrBaseInfo);
      key->m_pGlobalCntrBaseInfo = item;
      ++m_pItems;
    }
    while ( m_pItems != &this->m_arOriginalGlobalRSInfo.m_pItems[this->m_arOriginalGlobalRSInfo.m_uLength] );
    this->m_arOriginalGlobalRSInfo.m_uLength = 0;
  }
}

// File Line: 875
// RVA: 0xAB6880
void __fastcall AkRSIterator::SaveOriginalGlobalRSInfo(
        AkRSIterator *this,
        CAkRSSub *in_pSub,
        CAkContainerBaseInfo *in_pRSInfo)
{
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *m_pItems; // rax
  CAkKeyArray<CAkRSSub *,CAkContainerBaseInfo *,4> *p_m_arOriginalGlobalRSInfo; // rsi
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v6; // rcx
  CAkContainerBaseInfo *v7; // rax
  CAkContainerBaseInfo *v8; // rdi

  m_pItems = this->m_arOriginalGlobalRSInfo.m_pItems;
  p_m_arOriginalGlobalRSInfo = &this->m_arOriginalGlobalRSInfo;
  v6 = &m_pItems[this->m_arOriginalGlobalRSInfo.m_uLength];
  if ( m_pItems == v6 )
    goto LABEL_6;
  do
  {
    if ( m_pItems->key == in_pSub )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v6 );
  if ( m_pItems == v6 || m_pItems == (MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *)-8i64 )
  {
LABEL_6:
    v7 = in_pRSInfo->vfptr->Clone(in_pRSInfo, LOWORD(in_pSub->m_listChildren.m_uLength));
    v8 = v7;
    if ( v7 )
    {
      if ( !CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4>::Set(p_m_arOriginalGlobalRSInfo, in_pSub, v7) )
        v8->vfptr->Destroy(v8);
    }
  }
}

// File Line: 896
// RVA: 0xAB5B00
void __fastcall AkRSIterator::ForceSelectSequentially(AkRSIterator *this, CAkRSNode *in_pForcedNode)
{
  CAkRSNode *m_pParent; // r8
  __int16 v3; // bx
  CAkRSNode **vfptr; // rax
  CAkRSNode **i; // r9
  RSStackItem *v7; // rdi
  CAkRSSub *pRSNode; // rcx
  CAkContainerBaseInfo *pLocalRSInfo; // rdi
  CAkRSSub *v10; // rdx

  m_pParent = in_pForcedNode->m_pParent;
  v3 = 0;
  vfptr = (CAkRSNode **)m_pParent[1].vfptr;
  for ( i = &vfptr[LODWORD(m_pParent[1].m_pParent)]; vfptr != i; ++v3 )
  {
    if ( *vfptr == in_pForcedNode )
      break;
    ++vfptr;
  }
  v7 = &this->m_stack.m_pItems[this->m_stack.m_uLength];
  pRSNode = v7[-1].pRSNode;
  if ( ((pRSNode->m_eRSType - 1) & 0xFFFFFFFD) != 0 )
    pLocalRSInfo = v7[-1].pLocalRSInfo;
  else
    pLocalRSInfo = CAkRSSub::GetGlobalRSInfo(pRSNode);
  if ( pLocalRSInfo )
  {
    v10 = this->m_stack.m_pItems[this->m_stack.m_uLength - 1].pRSNode;
    if ( (*((_BYTE *)this + 64) & 1) != 0 && pLocalRSInfo == v10->m_pGlobalCntrBaseInfo )
      AkRSIterator::SaveOriginalGlobalRSInfo(this, v10, pLocalRSInfo);
    WORD1(pLocalRSInfo[1].vfptr) = v3;
  }
}

