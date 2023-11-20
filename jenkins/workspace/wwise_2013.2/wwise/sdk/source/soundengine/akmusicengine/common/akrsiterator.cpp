// File Line: 31
// RVA: 0xAB5580
void __fastcall CAkRSSub::~CAkRSSub(CAkRSSub *this)
{
  CAkRSSub *v1; // rdi
  CAkContainerBaseInfo *v2; // rcx
  CAkRSNode **v3; // rbx
  CAkRSNode *v4; // r14
  int v5; // esi

  v1 = this;
  this->vfptr = (CAkRSNodeVtbl *)&CAkRSSub::`vftable';
  v2 = this->m_pGlobalCntrBaseInfo;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Destroy)();
    v1->m_pGlobalCntrBaseInfo = 0i64;
  }
  v3 = v1->m_listChildren.m_pItems;
  if ( v3 != &v3[v1->m_listChildren.m_uLength] )
  {
    do
    {
      v4 = *v3;
      if ( *v3 )
      {
        v5 = g_DefaultPoolId;
        v4->vfptr->__vecDelDtor(*v3, 0);
        AK::MemoryMgr::Free(v5, v4);
      }
      ++v3;
    }
    while ( v3 != &v1->m_listChildren.m_pItems[v1->m_listChildren.m_uLength] );
  }
  if ( v1->m_listChildren.m_pItems )
  {
    v1->m_listChildren.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v1->m_listChildren.m_pItems);
    v1->m_listChildren.m_pItems = 0i64;
    v1->m_listChildren.m_ulReserved = 0;
  }
  v1->vfptr = (CAkRSNodeVtbl *)&CAkRSNode::`vftable';
}

// File Line: 44
// RVA: 0xAB57C0
void __fastcall CAkRSSub::Clear(CAkRSSub *this)
{
  CAkRSSub *v1; // rbx
  CAkContainerBaseInfo *v2; // rcx

  v1 = this;
  v2 = this->m_pGlobalCntrBaseInfo;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->Destroy)();
    v1->m_pGlobalCntrBaseInfo = 0i64;
  }
}

// File Line: 53
// RVA: 0xAB7030
void __fastcall CAkRSSub::WasSegmentLeafFound(CAkRSSub *this)
{
  CAkRSSub *v1; // rbx
  CAkRSSub *v2; // rcx

  v1 = this;
  if ( this->m_bHasSegmentLeaves )
  {
    this->m_bHasSegmentLeaves = 1;
  }
  else
  {
    v2 = (CAkRSSub *)this->m_pParent;
    if ( v2 )
      CAkRSSub::WasSegmentLeafFound(v2);
    v1->m_bHasSegmentLeaves = 1;
  }
}

// File Line: 68
// RVA: 0xAB5780
__int64 __fastcall CAkRSSub::CalculateTotalWeight(CAkRSSub *this)
{
  CAkRSNode **v1; // rdx
  __int64 result; // rax
  signed __int64 i; // r8
  CAkRSNode *v4; // rcx

  v1 = this->m_listChildren.m_pItems;
  result = 0i64;
  for ( i = (signed __int64)&v1[this->m_listChildren.m_uLength];
        v1 != (CAkRSNode **)i;
        result = (unsigned int)(v4->m_Weight + result) )
  {
    v4 = *v1;
    ++v1;
  }
  return result;
}

// File Line: 78
// RVA: 0xAB5BB0
void __fastcall CAkRSSub::GetGlobalRSInfo(CAkRSSub *this)
{
  CAkRSSub *v1; // rbx
  __int32 v2; // ecx
  CAkRandomInfo *v3; // rax
  CAkRandomInfo *v4; // rax
  CAkContainerBaseInfo *v5; // rdi
  int v6; // eax
  CAkContainerBaseInfo *v7; // rax
  CAkSequenceInfo *v8; // rax
  CAkContainerBaseInfo *v9; // rax
  CAkContainerBaseInfo *v10; // rax

  v1 = this;
  if ( this->m_pGlobalCntrBaseInfo || !this->m_listChildren.m_uLength )
  {
    v10 = this->m_pGlobalCntrBaseInfo;
  }
  else
  {
    v2 = this->m_eRSType - 1;
    if ( v2 )
    {
      if ( v2 != 2 )
      {
LABEL_14:
        v7 = v1->m_pGlobalCntrBaseInfo;
        return;
      }
      v3 = (CAkRandomInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
      if ( v3 )
        CAkRandomInfo::CAkRandomInfo(v3, v1->m_listChildren.m_uLength);
      else
        v4 = 0i64;
      v1->m_pGlobalCntrBaseInfo = (CAkContainerBaseInfo *)&v4->vfptr;
      if ( v4 && (unsigned int)CAkRandomInfo::Init(v4, v1->m_wAvoidRepeatCount) != 1 )
      {
        ((void (*)(void))v1->m_pGlobalCntrBaseInfo->vfptr->Destroy)();
        v1->m_pGlobalCntrBaseInfo = 0i64;
      }
      v5 = v1->m_pGlobalCntrBaseInfo;
      if ( v5 && v1->m_bIsUsingWeight )
      {
        v6 = CAkRSSub::CalculateTotalWeight(v1);
        HIDWORD(v5[1].vfptr) = v6;
        LODWORD(v1->m_pGlobalCntrBaseInfo[1].vfptr) = v6;
        goto LABEL_14;
      }
    }
    else
    {
      v8 = (CAkSequenceInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x10ui64);
      if ( v8 )
      {
        CAkSequenceInfo::CAkSequenceInfo(v8);
        v1->m_pGlobalCntrBaseInfo = v9;
      }
      else
      {
        v1->m_pGlobalCntrBaseInfo = 0i64;
      }
    }
  }
}

// File Line: 128
// RVA: 0xAB6040
signed __int64 __fastcall RSStackItem::Init(RSStackItem *this, CAkRSSub *in_pSub)
{
  RSStackItem *v2; // rbx
  CAkRSSub *v3; // rdi
  RSType v4; // ecx
  int v5; // ecx
  int v6; // ecx
  signed __int64 result; // rax
  CAkRandomInfo *v8; // rax
  CAkContainerBaseInfo *v9; // rax
  CAkRandomInfo *v10; // rcx
  int v11; // eax
  CAkSequenceInfo *v12; // rax
  CAkContainerBaseInfo *v13; // rax
  CAkContainerBaseInfo *v14; // rsi

  this->pRSNode = in_pSub;
  v2 = this;
  v3 = in_pSub;
  *((_BYTE *)&this->m_Loop + 2) = *((_BYTE *)&this->m_Loop + 2) ^ (*((_BYTE *)&this->m_Loop + 2) ^ 2
                                                                                                 * (in_pSub->m_Loop == 0)) & 2 | 1;
  this->m_Loop.lLoopCount = in_pSub->m_Loop;
  v4 = in_pSub->m_eRSType;
  if ( v4 )
  {
    v5 = v4 - 1;
    if ( v5 )
    {
      v6 = v5 - 1;
      if ( !v6 )
      {
        if ( in_pSub->m_listChildren.m_uLength )
        {
          v8 = (CAkRandomInfo *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x38ui64);
          if ( v8 )
            CAkRandomInfo::CAkRandomInfo(v8, v3->m_listChildren.m_uLength);
          else
            v9 = 0i64;
          v2->pLocalRSInfo = v9;
        }
        v10 = (CAkRandomInfo *)v2->pLocalRSInfo;
        if ( v10 )
        {
          if ( (unsigned int)CAkRandomInfo::Init(v10, v3->m_wAvoidRepeatCount) == 1 )
          {
            if ( v3->m_bIsUsingWeight )
            {
              v11 = CAkRSSub::CalculateTotalWeight(v3);
              HIDWORD(v2->pLocalRSInfo[1].vfptr) = v11;
              LODWORD(v2->pLocalRSInfo[1].vfptr) = v11;
            }
            return 1i64;
          }
          ((void (*)(void))v2->pLocalRSInfo->vfptr->Destroy)();
          v2->pLocalRSInfo = 0i64;
        }
        return 2i64;
      }
      if ( v6 != 1 )
        return 2i64;
    }
    *((_BYTE *)&v2->m_Loop + 2) |= 2u;
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
    v2->pLocalRSInfo = v14;
  }
  result = 2i64;
  if ( v2->pLocalRSInfo )
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
signed __int64 __fastcall AkRSIterator::Init(AkRSIterator *this, unsigned int in_playingID)
{
  CAkMusicRanSeqCntr *v2; // rdi
  AkRSIterator *v3; // rsi
  signed __int64 v4; // rdi
  signed __int64 v5; // r12
  bool v7; // bl
  unsigned __int16 v8; // di
  RSStackItem *v9; // rax
  CAkRSSub *v10; // r13
  signed __int64 v11; // r15
  signed int v12; // eax
  unsigned __int16 v13; // ax
  unsigned int v14; // ebx
  unsigned int v15; // er8
  unsigned int v16; // edx
  unsigned int v17; // er9
  signed __int64 v18; // rcx
  __int64 v19; // rcx
  signed __int16 *v20; // rbx
  signed __int16 *v21; // rax
  __int64 v22; // rdi
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v23; // rax
  signed __int64 v24; // rcx
  CAkContainerBaseInfo *v25; // rax
  CAkContainerBaseInfo *v26; // r14
  int v27; // ecx
  signed __int64 v28; // rax
  char v29; // cl
  bool v30; // zf
  unsigned int v31; // eax
  unsigned int io_uSelection; // [rsp+70h] [rbp+8h]
  bool out_bIsEnd; // [rsp+78h] [rbp+10h]
  unsigned int io_uItemDone; // [rsp+80h] [rbp+18h]

  v2 = this->m_pRSCntr;
  *((_WORD *)this + 32) |= 1u;
  v3 = this;
  this->m_playingID = in_playingID;
  this->m_actualSegment = 0;
  this->m_bIsSegmentValid = 1;
  v4 = (signed __int64)&v2->m_playListRoot;
  if ( !v4 )
    return 2i64;
  while ( !(*(unsigned __int8 (__fastcall **)(signed __int64))(*(_QWORD *)v4 + 8i64))(v4) )
  {
    v5 = v4;
    if ( *(_DWORD *)(v4 + 40) && *(_BYTE *)(v4 + 66) )
    {
      if ( AkRSIterator::StackItem(v3, (CAkRSSub *)v4) != 1 )
      {
        AkRSIterator::Term(v3);
        return 2i64;
      }
    }
    else
    {
      v5 = *(_QWORD *)(v4 + 8);
      if ( !v5 )
        return 2i64;
    }
    v7 = 0;
    out_bIsEnd = 0;
    while ( 1 )
    {
      v8 = 0;
      v9 = v3->m_stack.m_pItems;
      v10 = v9[v3->m_stack.m_uLength - 1].pRSNode;
      v11 = (signed __int64)&v9[v3->m_stack.m_uLength];
      v12 = v10->m_eRSType;
      if ( v12 < 0 )
        goto LABEL_15;
      if ( v12 > 1 )
      {
        if ( v12 <= 3 )
        {
          v13 = AkRSIterator::SelectRandomly(v3, (RSStackItem *)(v11 - 24), &out_bIsEnd);
          v7 = out_bIsEnd;
          v8 = v13;
        }
LABEL_15:
        if ( v7 )
          goto LABEL_19;
        goto LABEL_16;
      }
      if ( (v12 - 1) & 0xFFFFFFFD )
      {
        v20 = *(signed __int16 **)(v11 - 8);
      }
      else
      {
        CAkRSSub::GetGlobalRSInfo(v10);
        v20 = v21;
      }
      if ( !v20 )
      {
        v7 = 1;
        out_bIsEnd = 1;
        goto LABEL_19;
      }
      v22 = *(_QWORD *)(v11 - 24);
      if ( *((_BYTE *)v3 + 64) & 1 && v20 == *(signed __int16 **)(v22 + 56) )
      {
        v23 = v3->m_arOriginalGlobalRSInfo.m_pItems;
        v24 = (signed __int64)&v23[v3->m_arOriginalGlobalRSInfo.m_uLength];
        if ( v23 == (MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *)v24 )
          goto LABEL_54;
        do
        {
          if ( v23->key == (CAkRSSub *)v22 )
            break;
          ++v23;
        }
        while ( v23 != (MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *)v24 );
        if ( v23 == (MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *)v24
          || v23 == (MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *)-8i64 )
        {
LABEL_54:
          v25 = (CAkContainerBaseInfo *)(*(__int64 (__fastcall **)(signed __int16 *, _QWORD))(*(_QWORD *)v20 + 24i64))(
                                          v20,
                                          *(unsigned __int16 *)(v22 + 40));
          v26 = v25;
          if ( v25 )
          {
            if ( !CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4>::Set(&v3->m_arOriginalGlobalRSInfo, (CAkRSSub *)v22, v25) )
              v26->vfptr->Destroy(v26);
          }
        }
      }
      v27 = v20[5];
      if ( v27 + 1 == *(_DWORD *)(v22 + 40) )
      {
        v28 = v11 - 16;
        v20[5] = 0;
        if ( v11 != 16 )
        {
          v29 = *(_BYTE *)(v28 + 2);
          if ( !(v29 & 1) || !(v29 & 2) && (v30 = *(_WORD *)v28 == 1, --*(_WORD *)v28, v30) )
          {
            v7 = 1;
            out_bIsEnd = 1;
            goto LABEL_19;
          }
        }
      }
      else
      {
        v20[5] = v27 + 1;
      }
      v8 = v20[5];
LABEL_16:
      v14 = v10->m_listChildren.m_uLength;
      v15 = v10->m_ID;
      v16 = v3->m_playingID;
      v17 = v10->m_listChildren.m_uLength;
      io_uSelection = v8;
      io_uItemDone = 0;
      CAkPlayingMgr::MusicPlaylistCallback(g_pPlayingMgr, v16, v15, v17, &io_uSelection, &io_uItemDone);
      if ( io_uSelection < v14 )
        v8 = io_uSelection;
      v7 = io_uItemDone != 0;
      out_bIsEnd = io_uItemDone != 0;
      if ( !io_uItemDone )
        break;
LABEL_19:
      v4 = *(_QWORD *)(v5 + 8);
      v18 = (signed __int64)&v3->m_stack.m_pItems[v3->m_stack.m_uLength];
      if ( !(*(_DWORD *)(*(_QWORD *)(v18 - 24) + 48i64) & 0xFFFFFFFD) )
      {
        v19 = *(_QWORD *)(v18 - 8);
        if ( v19 )
          (*(void (**)(void))(*(_QWORD *)v19 + 8i64))();
      }
      --v3->m_stack.m_uLength;
      if ( !v7 )
        goto LABEL_49;
      if ( !v4 )
        return 2i64;
    }
    v4 = *(_QWORD *)(*(_QWORD *)(v5 + 32) + 8i64 * v8);
LABEL_49:
    if ( !v4 )
      return 2i64;
  }
  v31 = *(_DWORD *)(v4 + 32);
  v3->m_actualSegment = v31;
  v3->m_bIsSegmentValid = v31 != 0;
  v3->m_LastSegmentPlayingID = *(_DWORD *)(v4 + 16);
  v3->m_uSegmentLoopCount = *(_WORD *)(v4 + 20);
  return 1i64;
}

// File Line: 260
// RVA: 0xAB57F0
void __fastcall AkRSIterator::EndInit(AkRSIterator *this)
{
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v1; // rbx
  AkRSIterator *v2; // rdi

  v1 = this->m_arOriginalGlobalRSInfo.m_pItems;
  v2 = this;
  if ( v1 != &v1[this->m_arOriginalGlobalRSInfo.m_uLength] )
  {
    do
    {
      ((void (*)(void))v1->item->vfptr->Destroy)();
      ++v1;
    }
    while ( v1 != &v2->m_arOriginalGlobalRSInfo.m_pItems[v2->m_arOriginalGlobalRSInfo.m_uLength] );
  }
  v2->m_arOriginalGlobalRSInfo.m_uLength = 0;
  *((_WORD *)v2 + 32) &= 0xFFFEu;
}

// File Line: 276
// RVA: 0xAB6DB0
void __fastcall AkRSIterator::Term(AkRSIterator *this)
{
  AkRSIterator *v1; // rdi
  RSStackItem *v2; // rdx
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v3; // rbx

  v1 = this;
  AkRSIterator::FlushStack(this);
  v2 = v1->m_stack.m_pItems;
  if ( v2 )
  {
    v1->m_stack.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v2);
    v1->m_stack.m_pItems = 0i64;
    v1->m_stack.m_ulReserved = 0;
  }
  v3 = v1->m_arOriginalGlobalRSInfo.m_pItems;
  if ( v3 != &v3[v1->m_arOriginalGlobalRSInfo.m_uLength] )
  {
    do
    {
      ((void (*)(void))v3->item->vfptr->Destroy)();
      ++v3;
    }
    while ( v3 != &v1->m_arOriginalGlobalRSInfo.m_pItems[v1->m_arOriginalGlobalRSInfo.m_uLength] );
  }
  if ( v1->m_arOriginalGlobalRSInfo.m_pItems )
  {
    v1->m_arOriginalGlobalRSInfo.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v1->m_arOriginalGlobalRSInfo.m_pItems);
    v1->m_arOriginalGlobalRSInfo.m_pItems = 0i64;
    v1->m_arOriginalGlobalRSInfo.m_ulReserved = 0;
  }
}

// File Line: 290
// RVA: 0xAB5920
void __fastcall AkRSIterator::FlushStack(AkRSIterator *this)
{
  RSStackItem *v1; // rbx
  AkRSIterator *v2; // rdi
  CAkContainerBaseInfo *v3; // rcx

  v1 = this->m_stack.m_pItems;
  v2 = this;
  if ( v1 == &v1[this->m_stack.m_uLength] )
  {
    this->m_stack.m_uLength = 0;
  }
  else
  {
    do
    {
      if ( !(v1->pRSNode->m_eRSType & 0xFFFFFFFD) )
      {
        v3 = v1->pLocalRSInfo;
        if ( v3 )
          ((void (*)(void))v3->vfptr->Destroy)();
      }
      ++v1;
    }
    while ( v1 != &v2->m_stack.m_pItems[v2->m_stack.m_uLength] );
    v2->m_stack.m_uLength = 0;
  }
}

// File Line: 306
// RVA: 0xAB6190
void __fastcall AkRSIterator::JumpNext(AkRSIterator *this)
{
  __int16 v1; // ax
  AkRSIterator *v2; // rdi
  bool v3; // zf
  __int64 v4; // rax
  CAkRSSub *v5; // rdx
  CAkRSSub *v6; // rbx
  unsigned __int16 v7; // ax
  CAkRSSub *v8; // rbx
  signed __int64 v9; // rcx
  __int64 v10; // rcx
  unsigned int v11; // eax
  bool out_bIsEnd; // [rsp+30h] [rbp+8h]

  v1 = this->m_uSegmentLoopCount;
  v2 = this;
  if ( v1 <= 1 )
  {
    if ( v1 )
    {
      if ( this->m_actualSegment )
      {
        v3 = this->m_stack.m_uLength == 0;
        this->m_actualSegment = 0;
        this->m_bIsSegmentValid = 1;
        if ( !v3 )
        {
          v4 = this->m_stack.m_uLength;
          out_bIsEnd = 1;
          v5 = this->m_stack.m_pItems[v4 - 1].pRSNode;
LABEL_8:
          v6 = (CAkRSSub *)AkRSIterator::PopObsoleteStackedItems(v2, (CAkRSNode *)&v5->vfptr);
          while ( v6 )
          {
            v7 = AkRSIterator::Select(
                   v2,
                   (RSStackItem *)((char *)v2->m_stack.m_pItems + 8 * (3i64 * v2->m_stack.m_uLength - 3)),
                   &out_bIsEnd);
            if ( out_bIsEnd )
            {
              v8 = (CAkRSSub *)v6->m_pParent;
              v9 = (signed __int64)&v2->m_stack.m_pItems[v2->m_stack.m_uLength];
              if ( !(*(_DWORD *)(*(_QWORD *)(v9 - 24) + 48i64) & 0xFFFFFFFD) )
              {
                v10 = *(_QWORD *)(v9 - 8);
                if ( v10 )
                  (*(void (**)(void))(*(_QWORD *)v10 + 8i64))();
              }
              --v2->m_stack.m_uLength;
              v5 = v8;
              goto LABEL_8;
            }
            v6 = (CAkRSSub *)v6->m_listChildren.m_pItems[v7];
            if ( v6->vfptr->IsSegment((CAkRSNode *)&v6->vfptr) )
            {
              v11 = (unsigned int)v6->m_listChildren.m_pItems;
              v2->m_actualSegment = v11;
              v2->m_bIsSegmentValid = v11 != 0;
              v2->m_LastSegmentPlayingID = v6->m_ID;
              v2->m_uSegmentLoopCount = v6->m_Loop;
              return;
            }
            if ( v6->m_listChildren.m_uLength && v6->m_bHasSegmentLeaves )
            {
              if ( AkRSIterator::StackItem(v2, v6) != 1 )
              {
                AkRSIterator::Term(v2);
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
    this->m_uSegmentLoopCount = v1 - 1;
  }
}

// File Line: 377
// RVA: 0xAB62F0
signed __int64 __fastcall AkRSIterator::JumpNextInternal(AkRSIterator *this)
{
  AkRSIterator *v1; // rbx
  CAkRSSub *v2; // rsi
  bool v3; // di
  unsigned __int16 v4; // bp
  RSStackItem *v5; // rax
  signed __int64 v6; // rdx
  _DWORD *v7; // r14
  RSStackItem *v8; // rdx
  signed int v9; // eax
  unsigned __int16 v10; // ax
  unsigned int v11; // edi
  unsigned int v12; // er8
  unsigned int v13; // edx
  unsigned int v14; // er9
  CAkRSNode *v16; // rsi
  signed __int64 v17; // rcx
  __int64 v18; // rcx
  unsigned int v19; // eax
  bool out_bIsEnd; // [rsp+60h] [rbp+8h]
  unsigned int io_uSelection; // [rsp+68h] [rbp+10h]
  unsigned int io_uItemDone; // [rsp+70h] [rbp+18h]

  v1 = this;
  this->m_bIsSegmentValid = 1;
  this->m_actualSegment = 0;
  if ( !this->m_stack.m_uLength )
    return 2i64;
  v2 = this->m_stack.m_pItems[this->m_stack.m_uLength - 1].pRSNode;
  while ( 2 )
  {
    v3 = 1;
    out_bIsEnd = 1;
    while ( 1 )
    {
      if ( !v2 )
        return 2i64;
      v4 = 0;
      v5 = v1->m_stack.m_pItems;
      v6 = 3i64 * v1->m_stack.m_uLength - 3;
      v7 = (_DWORD *)*((_QWORD *)&v5->pRSNode + v6);
      v8 = (RSStackItem *)((char *)v5 + 8 * v6);
      v9 = v7[12];
      if ( v9 >= 0 )
      {
        if ( v9 <= 1 )
        {
          v10 = AkRSIterator::SelectSequentially(v1, v8, &out_bIsEnd);
          goto LABEL_10;
        }
        if ( v9 <= 3 )
        {
          v10 = AkRSIterator::SelectRandomly(v1, v8, &out_bIsEnd);
LABEL_10:
          v3 = out_bIsEnd;
          v4 = v10;
          goto LABEL_11;
        }
      }
LABEL_11:
      if ( !v3 )
      {
        v11 = v7[10];
        v12 = v7[4];
        v13 = v1->m_playingID;
        v14 = v7[10];
        io_uSelection = v4;
        io_uItemDone = 0;
        CAkPlayingMgr::MusicPlaylistCallback(g_pPlayingMgr, v13, v12, v14, &io_uSelection, &io_uItemDone);
        if ( io_uSelection < v11 )
          v4 = io_uSelection;
        v3 = io_uItemDone != 0;
        out_bIsEnd = io_uItemDone != 0;
        if ( !io_uItemDone )
          break;
      }
      v16 = v2->m_pParent;
      v17 = (signed __int64)&v1->m_stack.m_pItems[v1->m_stack.m_uLength];
      if ( !(*(_DWORD *)(*(_QWORD *)(v17 - 24) + 48i64) & 0xFFFFFFFD) )
      {
        v18 = *(_QWORD *)(v17 - 8);
        if ( v18 )
          (*(void (__fastcall **)(__int64, RSStackItem *))(*(_QWORD *)v18 + 8i64))(v18, v8);
      }
      --v1->m_stack.m_uLength;
      v2 = (CAkRSSub *)AkRSIterator::PopObsoleteStackedItems(v1, v16);
      if ( !v3 )
        goto LABEL_24;
    }
    v2 = (CAkRSSub *)v2->m_listChildren.m_pItems[v4];
    if ( !v2->vfptr->IsSegment((CAkRSNode *)&v2->vfptr) )
    {
      if ( AkRSIterator::StackItem(v1, v2) == 1 )
        continue;
      AkRSIterator::Term(v1);
      return 2i64;
    }
    break;
  }
LABEL_24:
  if ( !v2 )
    return 2i64;
  v19 = (unsigned int)v2->m_listChildren.m_pItems;
  v1->m_actualSegment = v19;
  v1->m_bIsSegmentValid = v19 != 0;
  v1->m_LastSegmentPlayingID = v2->m_ID;
  v1->m_uSegmentLoopCount = v2->m_Loop;
  return 1i64;
}

// File Line: 423
// RVA: 0xAB64E0
signed __int64 __fastcall AkRSIterator::JumpTo(AkRSIterator *this, unsigned int in_playlistElementID)
{
  unsigned int v2; // er15
  AkRSIterator *v3; // rdi
  CAkMusicRanSeqCntr *v4; // rsi
  signed __int64 v5; // rsi
  CAkRSNode *v6; // rdx
  _QWORD *v7; // rbx
  unsigned __int64 v8; // r8
  unsigned int v9; // er14
  unsigned __int64 v10; // rcx
  __int64 v11; // rax
  __int64 v12; // rax
  signed __int64 *v13; // rcx
  AKRESULT v14; // eax
  CAkRSNode **v15; // rbx
  CAkRSNode **v16; // rbx
  CAkRSNode *v17; // rsi
  signed int v18; // ecx
  unsigned int v19; // eax
  signed __int64 result; // rax
  unsigned int v21; // ebx
  void *in_pvMemAddress; // [rsp+30h] [rbp-10h]
  __int64 v23; // [rsp+38h] [rbp-8h]
  bool io_bFound; // [rsp+70h] [rbp+30h]

  v2 = in_playlistElementID;
  v3 = this;
  AkRSIterator::RevertGlobalRSInfo(this);
  AkRSIterator::FlushStack(v3);
  v4 = v3->m_pRSCntr;
  v3->m_actualSegment = 0;
  v3->m_bIsSegmentValid = 1;
  in_pvMemAddress = 0i64;
  v23 = 0i64;
  io_bFound = 0;
  v5 = (signed __int64)&v4->m_playListRoot;
  v7 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x40ui64);
  v9 = 2;
  if ( !v7 )
    goto LABEL_41;
  v6 = (CAkRSNode *)in_pvMemAddress;
  v8 = (unsigned int)v23;
  if ( in_pvMemAddress )
  {
    v10 = 0i64;
    if ( (_DWORD)v23 )
    {
      do
      {
        v11 = *((_QWORD *)&v6->vfptr + v10++);
        v7[v10 - 1] = v11;
        v6 = (CAkRSNode *)in_pvMemAddress;
      }
      while ( v10 < v8 );
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, v6);
  }
  v12 = (unsigned int)v23;
  LODWORD(v23) = v23 + 1;
  in_pvMemAddress = v7;
  v13 = &v7[v12];
  HIDWORD(v23) = 8;
  if ( !v13 )
  {
LABEL_41:
    v14 = 2;
    goto LABEL_19;
  }
  *v13 = v5;
  if ( *(_DWORD *)(v5 + 16) != v2 )
  {
    if ( !(*(unsigned __int8 (__fastcall **)(signed __int64, CAkRSNode *, unsigned __int64))(*(_QWORD *)v5 + 8i64))(
            v5,
            v6,
            v8) )
    {
      v15 = *(CAkRSNode ***)(v5 + 32);
      if ( io_bFound )
      {
LABEL_17:
        v14 = 1;
        goto LABEL_19;
      }
      while ( v15 != (CAkRSNode **)(*(_QWORD *)(v5 + 32) + 8i64 * *(unsigned int *)(v5 + 40)) )
      {
        v14 = AkRSIterator::FindAndSelect(
                v3,
                *v15,
                v2,
                (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)&in_pvMemAddress,
                &io_bFound);
        if ( v14 == 1 )
        {
          ++v15;
          if ( !io_bFound )
            continue;
        }
        goto LABEL_19;
      }
    }
    if ( !io_bFound )
      LODWORD(v23) = v23 - 1;
    goto LABEL_17;
  }
  io_bFound = 1;
  v14 = 1;
LABEL_19:
  if ( io_bFound
    && v14 == 1
    && (v16 = (CAkRSNode **)in_pvMemAddress, in_pvMemAddress != (char *)in_pvMemAddress + 8 * (unsigned int)v23) )
  {
    while ( 1 )
    {
      v17 = *v16;
      if ( ((unsigned __int8 (__fastcall *)(CAkRSNode *, CAkRSNode *, unsigned __int64))(*v16)->vfptr->IsSegment)(
             *v16,
             v6,
             v8) )
      {
LABEL_31:
        v19 = (unsigned int)v17[1].vfptr;
        v9 = 1;
        v3->m_actualSegment = v19;
        v3->m_bIsSegmentValid = v19 != 0;
        v3->m_LastSegmentPlayingID = v17->m_ID;
        v3->m_uSegmentLoopCount = v17->m_Loop;
        goto LABEL_32;
      }
      if ( AkRSIterator::StackItem(v3, (CAkRSSub *)v17) != 1 )
      {
        AkRSIterator::Term(v3);
        goto LABEL_32;
      }
      ++v16;
      if ( v16 == (CAkRSNode **)((char *)in_pvMemAddress + 8 * (unsigned int)v23) )
        break;
      v6 = *v16;
      v18 = (*v16)->m_pParent[1].m_ID;
      if ( v18 >= 0 )
      {
        if ( v18 <= 1 )
        {
          AkRSIterator::ForceSelectSequentially(v3, v6);
        }
        else if ( v18 <= 3 )
        {
          AkRSIterator::ForceSelectRandomly(v3, v6);
        }
      }
      if ( v16 == (CAkRSNode **)((char *)in_pvMemAddress + 8 * (unsigned int)v23) )
        goto LABEL_31;
    }
    result = AkRSIterator::JumpNextInternal(v3);
    v21 = result;
    if ( in_pvMemAddress )
    {
      LODWORD(v23) = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, in_pvMemAddress);
      result = v21;
    }
  }
  else
  {
LABEL_32:
    if ( in_pvMemAddress )
    {
      LODWORD(v23) = 0;
      AK::MemoryMgr::Free(g_DefaultPoolId, in_pvMemAddress);
    }
    result = v9;
  }
  return result;
}

// File Line: 495
// RVA: 0xAB5850
AKRESULT __fastcall AkRSIterator::FindAndSelect(AkRSIterator *this, CAkRSNode *in_pNode, unsigned int in_playlistElementID, AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *io_jmpList, bool *io_bFound)
{
  AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *v5; // rbp
  unsigned int v6; // ebx
  CAkRSNode *v7; // rdi
  AKRESULT result; // eax
  CAkRSNode **v9; // rbx
  AkRSIterator *v10; // [rsp+50h] [rbp+8h]
  unsigned int in_playlistElementIDa; // [rsp+60h] [rbp+18h]

  in_playlistElementIDa = in_playlistElementID;
  v10 = this;
  v5 = io_jmpList;
  v6 = in_playlistElementID;
  v7 = in_pNode;
  if ( !AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault>::AddLast(io_jmpList, in_pNode) )
    return 2;
  if ( v7->m_ID != v6 )
  {
    if ( !v7->vfptr->IsSegment(v7) )
    {
      v9 = (CAkRSNode **)v7[1].vfptr;
      if ( *io_bFound )
        return 1;
      do
      {
        if ( v9 == (CAkRSNode **)&v7[1].vfptr->__vecDelDtor + LODWORD(v7[1].m_pParent) )
          break;
        result = AkRSIterator::FindAndSelect(v10, *v9, in_playlistElementIDa, v5, io_bFound);
        if ( result != 1 )
          return result;
        ++v9;
      }
      while ( !*io_bFound );
    }
    if ( !*io_bFound )
      --v5->m_uLength;
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
  AkRSIterator *v3; // rdi
  signed __int64 v4; // rcx
  __int16 v5; // ax
  __int64 v6; // rcx

  v2 = in_pNode;
  v3 = this;
  if ( in_pNode )
  {
    while ( v2[1].m_ID & 0xFFFFFFFD )
    {
      v4 = (signed __int64)&v3->m_stack.m_pItems[v3->m_stack.m_uLength];
      v5 = *(_WORD *)(v4 - 16);
      if ( !v5 )
        break;
      if ( v5 > 1 )
      {
        --*((_WORD *)&v3->m_stack.m_pItems[v3->m_stack.m_uLength] - 8);
        return v2;
      }
      v2 = v2->m_pParent;
      if ( !(*(_DWORD *)(*(_QWORD *)(v4 - 24) + 48i64) & 0xFFFFFFFD) )
      {
        v6 = *(_QWORD *)(v4 - 8);
        if ( v6 )
          (*(void (**)(void))(*(_QWORD *)v6 + 8i64))();
      }
      --v3->m_stack.m_uLength;
      if ( !v2 )
        return 0i64;
    }
  }
  return v2;
}

// File Line: 548
// RVA: 0xAB6D20
signed __int64 __fastcall AkRSIterator::StackItem(AkRSIterator *this, CAkRSSub *in_pSub)
{
  AkRSIterator *v2; // rbx
  RSStackItem *v3; // rax
  signed __int64 result; // rax
  RSStackItem v5; // [rsp+20h] [rbp-28h]

  *((_BYTE *)&v5.m_Loop + 2) &= 0xFCu;
  v2 = this;
  v5.m_Loop.lLoopCount = 0;
  v5.pLocalRSInfo = 0i64;
  if ( (unsigned int)RSStackItem::Init(&v5, in_pSub) == 1
    && (v3 = AkArray<RSStackItem,RSStackItem const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::AddLast(&v2->m_stack)) != 0i64 )
  {
    *v3 = v5;
    result = 1i64;
  }
  else
  {
    if ( !(v5.pRSNode->m_eRSType & 0xFFFFFFFD) )
    {
      if ( v5.pLocalRSInfo )
        ((void (*)(void))v5.pLocalRSInfo->vfptr->Destroy)();
    }
    result = 2i64;
  }
  return result;
}

// File Line: 560
// RVA: 0xAB6910
__int64 __fastcall AkRSIterator::Select(AkRSIterator *this, RSStackItem *in_rStackItem, bool *out_bIsEnd)
{
  CAkRSSub *v3; // r14
  bool *v4; // rsi
  RSType v5; // eax
  AkRSIterator *v6; // rbp
  unsigned __int16 v7; // di
  unsigned __int16 v8; // ax
  unsigned int v9; // er8
  unsigned int v10; // edx
  unsigned int v11; // ebx
  unsigned int io_uSelection; // [rsp+68h] [rbp+10h]
  unsigned int io_uItemDone; // [rsp+78h] [rbp+20h]

  v3 = in_rStackItem->pRSNode;
  v4 = out_bIsEnd;
  v5 = in_rStackItem->pRSNode->m_eRSType;
  v6 = this;
  v7 = 0;
  if ( (signed int)v5 >= 0 )
  {
    if ( (signed int)v5 <= 1 )
    {
      v8 = AkRSIterator::SelectSequentially(this, in_rStackItem, out_bIsEnd);
    }
    else
    {
      if ( (signed int)v5 > 3 )
        goto LABEL_7;
      v8 = AkRSIterator::SelectRandomly(this, in_rStackItem, out_bIsEnd);
    }
    v7 = v8;
  }
LABEL_7:
  if ( !*v4 )
  {
    v9 = v3->m_ID;
    v10 = v6->m_playingID;
    v11 = v3->m_listChildren.m_uLength;
    io_uSelection = v7;
    io_uItemDone = 0;
    CAkPlayingMgr::MusicPlaylistCallback(g_pPlayingMgr, v10, v9, v11, &io_uSelection, &io_uItemDone);
    if ( io_uSelection < v11 )
      v7 = io_uSelection;
    *v4 = io_uItemDone != 0;
  }
  return v7;
}

// File Line: 614
// RVA: 0xAB6BD0
__int64 __fastcall AkRSIterator::SelectSequentially(AkRSIterator *this, RSStackItem *in_rStackItem, bool *out_bIsEnd)
{
  AkRSIterator *v3; // rbp
  bool *v4; // r14
  RSStackItem *v5; // rdi
  CAkContainerBaseInfo *v6; // rbx
  CAkContainerBaseInfo *v7; // rax
  __int64 result; // rax
  CAkRSSub *v9; // rsi
  int v10; // ecx
  AkLoop *v11; // rcx
  char v12; // dl
  bool v13; // zf

  *out_bIsEnd = 0;
  v3 = this;
  v4 = out_bIsEnd;
  v5 = in_rStackItem;
  if ( (in_rStackItem->pRSNode->m_eRSType - 1) & 0xFFFFFFFD )
  {
    v6 = in_rStackItem->pLocalRSInfo;
  }
  else
  {
    CAkRSSub::GetGlobalRSInfo(in_rStackItem->pRSNode);
    v6 = v7;
  }
  if ( !v6 )
  {
    *v4 = 1;
    return 0i64;
  }
  v9 = v5->pRSNode;
  if ( *((_BYTE *)v3 + 64) & 1 && v6 == v9->m_pGlobalCntrBaseInfo )
    AkRSIterator::SaveOriginalGlobalRSInfo(v3, v5->pRSNode, v6);
  v10 = SWORD1(v6[1].vfptr);
  if ( v10 + 1 == v9->m_listChildren.m_uLength )
  {
    result = 0i64;
    v11 = &v5->m_Loop;
    WORD1(v6[1].vfptr) = 0;
    if ( v5 != (RSStackItem *)-8i64 )
    {
      v12 = *((_BYTE *)&v5->m_Loop + 2);
      if ( !(v12 & 1) || !(v12 & 2) && (v13 = v11->lLoopCount == 1, --v11->lLoopCount, v13) )
      {
        *v4 = 1;
        return result;
      }
    }
  }
  else
  {
    WORD1(v6[1].vfptr) = v10 + 1;
  }
  return WORD1(v6[1].vfptr);
}

// File Line: 650
// RVA: 0xAB69C0
__int64 __fastcall AkRSIterator::SelectRandomly(AkRSIterator *this, RSStackItem *in_rStackItem, bool *out_bIsEnd)
{
  AkRSIterator *v3; // r13
  bool *v4; // r15
  RSStackItem *v5; // r14
  CAkRandomInfo *in_pRanInfo; // rdi
  CAkRandomInfo *v7; // rax
  __int64 v8; // rbx
  CAkRSSub *v9; // rbp
  signed int v10; // esi
  signed __int64 v11; // r14
  char v12; // al
  bool v13; // zf
  unsigned __int16 *v14; // r9
  unsigned int v15; // er8
  unsigned __int16 *i; // rax
  __int64 v17; // rdx
  signed int v18; // er14
  signed int v19; // er14

  *out_bIsEnd = 0;
  v3 = this;
  v4 = out_bIsEnd;
  v5 = in_rStackItem;
  if ( (in_rStackItem->pRSNode->m_eRSType - 1) & 0xFFFFFFFD )
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
    v9 = v5->pRSNode;
    v10 = -1;
    if ( !in_pRanInfo->m_wCounter )
    {
      v11 = (signed __int64)&v5->m_Loop;
      if ( v11 )
      {
        v12 = *(_BYTE *)(v11 + 2);
        if ( !(v12 & 1) || !(v12 & 2) && (v13 = *(_WORD *)v11 == 1, --*(_WORD *)v11, v13) )
        {
          *v4 = 1;
          return (unsigned __int16)v8;
        }
      }
      in_pRanInfo->m_wCounter = v9->m_listChildren.m_uLength;
      CAkRandomInfo::ResetFlagsPlayed(in_pRanInfo, v9->m_listChildren.m_uLength);
      v14 = in_pRanInfo->m_listAvoid.m_pItems;
      v15 = in_pRanInfo->m_ulTotalWeight;
      in_pRanInfo->m_ulRemainingWeight = v15;
      for ( i = v14; i != &v14[in_pRanInfo->m_listAvoid.m_uLength]; in_pRanInfo->m_ulRemainingWeight = v15 )
      {
        v17 = *i;
        ++i;
        v15 -= v9->m_listChildren.m_pItems[v17]->m_Weight;
      }
      in_pRanInfo->m_wRemainingItemsToPlay -= LOWORD(in_pRanInfo->m_listAvoid.m_uLength);
    }
    if ( v9->m_bIsUsingWeight )
    {
      if ( !in_pRanInfo->m_ulRemainingWeight )
      {
LABEL_17:
        in_pRanInfo->m_wCounter = 0;
        return (unsigned __int16)v8;
      }
      v18 = CAkRandomInfo::GetRandomValue(in_pRanInfo);
      if ( v18 > -1 )
      {
        do
        {
          if ( v9->m_bIsShuffle )
          {
            if ( CAkRandomInfo::IsFlagSetPlayed(in_pRanInfo, v8) || CAkRandomInfo::IsFlagBlocked(in_pRanInfo, v8) )
              goto LABEL_26;
          }
          else if ( v9->m_wAvoidRepeatCount && CAkRandomInfo::IsFlagBlocked(in_pRanInfo, v8) )
          {
            goto LABEL_26;
          }
          v10 += v9->m_listChildren.m_pItems[v8]->m_Weight;
LABEL_26:
          v8 = (unsigned int)(v8 + 1);
        }
        while ( v10 < v18 );
      }
LABEL_38:
      LOWORD(v8) = v8 - 1;
      AkRSIterator::UpdateRandomItem(v3, v9, v8, &v9->m_listChildren, in_pRanInfo);
      return (unsigned __int16)v8;
    }
    if ( !in_pRanInfo->m_wRemainingItemsToPlay )
      goto LABEL_17;
    v19 = (unsigned __int16)(rand() % in_pRanInfo->m_wRemainingItemsToPlay);
    if ( v19 <= -1 )
      goto LABEL_38;
    while ( 1 )
    {
      if ( v9->m_bIsShuffle )
      {
        if ( CAkRandomInfo::IsFlagSetPlayed(in_pRanInfo, v8) || CAkRandomInfo::IsFlagBlocked(in_pRanInfo, v8) )
          goto LABEL_37;
      }
      else if ( v9->m_wAvoidRepeatCount && CAkRandomInfo::IsFlagBlocked(in_pRanInfo, v8) )
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
  *v4 = 1;
  return (unsigned __int16)v8;
}

// File Line: 742
// RVA: 0xAB59A0
void __fastcall AkRSIterator::ForceSelectRandomly(AkRSIterator *this, CAkRSNode *in_pForcedNode)
{
  CAkRSSub *v2; // r13
  unsigned __int16 v3; // bp
  AkRSIterator *v4; // r15
  CAkRSNode **v5; // rax
  signed __int64 i; // rdi
  RSStackItem *v7; // rbx
  CAkRSSub *v8; // rcx
  CAkRandomInfo *in_pRanInfo; // rbx
  unsigned __int16 *v10; // rdi
  signed __int64 v11; // rax
  unsigned __int16 *v12; // rsi
  unsigned __int64 j; // rcx
  unsigned __int16 *v14; // rsi
  unsigned int v15; // edi
  unsigned __int16 *k; // rax
  __int64 v17; // rdx

  v2 = (CAkRSSub *)in_pForcedNode->m_pParent;
  v3 = 0;
  v4 = this;
  v5 = v2->m_listChildren.m_pItems;
  for ( i = (signed __int64)&v5[v2->m_listChildren.m_uLength]; v5 != (CAkRSNode **)i; ++v3 )
  {
    if ( *v5 == in_pForcedNode )
      break;
    ++v5;
  }
  v7 = &this->m_stack.m_pItems[this->m_stack.m_uLength];
  v8 = v7[-1].pRSNode;
  if ( (v8->m_eRSType - 1) & 0xFFFFFFFD )
    in_pRanInfo = (CAkRandomInfo *)v7[-1].pLocalRSInfo;
  else
    in_pRanInfo = (CAkRandomInfo *)CAkRSSub::GetGlobalRSInfo(v8);
  if ( in_pRanInfo )
  {
    CAkRandomInfo::FlagAsUnBlocked(in_pRanInfo, v3);
    v10 = in_pRanInfo->m_listAvoid.m_pItems;
    v11 = (signed __int64)&v10[in_pRanInfo->m_listAvoid.m_uLength];
    if ( v10 != (unsigned __int16 *)v11 )
    {
      do
      {
        if ( *v10 == v3 )
          break;
        ++v10;
      }
      while ( v10 != (unsigned __int16 *)v11 );
      if ( v10 != (unsigned __int16 *)v11 )
      {
        if ( (unsigned __int64)v10 < v11 - 2 )
        {
          v12 = v10 + 1;
          for ( j = ((unsigned __int64)(v11 - 2 - (_QWORD)v10 - 1) >> 1) + 1; j; --j )
          {
            *v10 = *v12;
            ++v12;
            ++v10;
          }
        }
        --in_pRanInfo->m_listAvoid.m_uLength;
      }
    }
    in_pRanInfo->m_wCounter = v2->m_listChildren.m_uLength;
    CAkRandomInfo::ResetFlagsPlayed(in_pRanInfo, v2->m_listChildren.m_uLength);
    v14 = in_pRanInfo->m_listAvoid.m_pItems;
    v15 = in_pRanInfo->m_ulTotalWeight;
    in_pRanInfo->m_ulRemainingWeight = v15;
    for ( k = v14; k != &v14[in_pRanInfo->m_listAvoid.m_uLength]; in_pRanInfo->m_ulRemainingWeight = v15 )
    {
      v17 = *k;
      ++k;
      v15 -= v2->m_listChildren.m_pItems[v17]->m_Weight;
    }
    in_pRanInfo->m_wRemainingItemsToPlay -= LOWORD(in_pRanInfo->m_listAvoid.m_uLength);
    AkRSIterator::UpdateRandomItem(v4, v2, v3, &v2->m_listChildren, in_pRanInfo);
  }
}

// File Line: 785
// RVA: 0xAB6E50
void __fastcall AkRSIterator::UpdateRandomItem(AkRSIterator *this, CAkRSSub *in_pSub, unsigned __int16 in_wPosition, AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *in_pRSList, CAkRandomInfo *in_pRanInfo)
{
  AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *v5; // r15
  unsigned __int16 v6; // si
  CAkRSSub *v7; // rdi
  unsigned __int16 *v8; // rax
  unsigned __int16 v9; // cx
  __int64 v10; // rdi
  unsigned int v11; // eax
  unsigned __int16 v12; // di
  unsigned int v13; // eax
  unsigned __int16 *v14; // rax
  unsigned __int16 v15; // ax
  unsigned __int16 *v16; // rdi
  unsigned __int16 v17; // bp
  unsigned __int16 *v18; // rsi
  unsigned __int64 i; // rcx

  v5 = in_pRSList;
  v6 = in_wPosition;
  v7 = in_pSub;
  if ( *((_BYTE *)this + 64) & 1 && in_pRanInfo == (CAkRandomInfo *)in_pSub->m_pGlobalCntrBaseInfo )
    AkRSIterator::SaveOriginalGlobalRSInfo(this, in_pSub, (CAkContainerBaseInfo *)&in_pRanInfo->vfptr);
  if ( v7->m_bIsShuffle )
  {
    v12 = v7->m_wAvoidRepeatCount;
    if ( !v12 )
      v12 = 1;
    v13 = v5->m_pItems[v6]->m_Weight;
    --in_pRanInfo->m_wRemainingItemsToPlay;
    --in_pRanInfo->m_wCounter;
    in_pRanInfo->m_ulRemainingWeight -= v13;
    CAkRandomInfo::FlagSetPlayed(in_pRanInfo, v6);
    v14 = AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&in_pRanInfo->m_listAvoid);
    if ( !v14 )
      goto LABEL_25;
    *v14 = v6;
    CAkRandomInfo::FlagAsBlocked(in_pRanInfo, v6);
    v15 = LOWORD(v5->m_uLength) - 1;
    if ( v12 < v15 )
      v15 = v12;
    if ( in_pRanInfo->m_listAvoid.m_uLength > v15 )
    {
      v16 = in_pRanInfo->m_listAvoid.m_pItems;
      v17 = *v16;
      if ( v16 < &v16[in_pRanInfo->m_listAvoid.m_uLength - 1i64] )
      {
        v18 = v16 + 1;
        for ( i = ((2 * ((unsigned __int64)in_pRanInfo->m_listAvoid.m_uLength - 1) - 1) >> 1) + 1; i; --i )
        {
          *v16 = *v18;
          ++v18;
          ++v16;
        }
      }
      --in_pRanInfo->m_listAvoid.m_uLength;
      CAkRandomInfo::FlagAsUnBlocked(in_pRanInfo, v17);
      if ( !CAkRandomInfo::IsFlagSetPlayed(in_pRanInfo, v17) )
      {
        in_pRanInfo->m_ulRemainingWeight += v5->m_pItems[v17]->m_Weight;
        ++in_pRanInfo->m_wRemainingItemsToPlay;
      }
    }
  }
  else
  {
    if ( !CAkRandomInfo::IsFlagSetPlayed(in_pRanInfo, v6) )
    {
      CAkRandomInfo::FlagSetPlayed(in_pRanInfo, v6);
      --in_pRanInfo->m_wCounter;
    }
    if ( v7->m_wAvoidRepeatCount )
    {
      --in_pRanInfo->m_wRemainingItemsToPlay;
      v8 = AkArray<unsigned short,unsigned short,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast(&in_pRanInfo->m_listAvoid);
      if ( v8 )
      {
        *v8 = v6;
        CAkRandomInfo::FlagAsBlocked(in_pRanInfo, v6);
        in_pRanInfo->m_ulRemainingWeight -= v5->m_pItems[v6]->m_Weight;
        v9 = LOWORD(v5->m_uLength) - 1;
        if ( v7->m_wAvoidRepeatCount < v9 )
          v9 = v7->m_wAvoidRepeatCount;
        if ( in_pRanInfo->m_listAvoid.m_uLength > v9 )
        {
          v10 = *in_pRanInfo->m_listAvoid.m_pItems;
          CAkRandomInfo::FlagAsUnBlocked(in_pRanInfo, *in_pRanInfo->m_listAvoid.m_pItems);
          v11 = v5->m_pItems[v10]->m_Weight;
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
      return;
    }
  }
}

// File Line: 858
// RVA: 0xAB67F0
void __fastcall AkRSIterator::RevertGlobalRSInfo(AkRSIterator *this)
{
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v1; // rbx
  AkRSIterator *v2; // rbp
  CAkRSSub *v3; // rsi
  CAkContainerBaseInfo *v4; // rdi

  v1 = this->m_arOriginalGlobalRSInfo.m_pItems;
  v2 = this;
  if ( v1 == &v1[this->m_arOriginalGlobalRSInfo.m_uLength] )
  {
    this->m_arOriginalGlobalRSInfo.m_uLength = 0;
  }
  else
  {
    do
    {
      v3 = v1->key;
      v4 = v1->item;
      ((void (*)(void))v1->key->m_pGlobalCntrBaseInfo->vfptr->Destroy)();
      v3->m_pGlobalCntrBaseInfo = v4;
      ++v1;
    }
    while ( v1 != &v2->m_arOriginalGlobalRSInfo.m_pItems[v2->m_arOriginalGlobalRSInfo.m_uLength] );
    v2->m_arOriginalGlobalRSInfo.m_uLength = 0;
  }
}

// File Line: 875
// RVA: 0xAB6880
void __fastcall AkRSIterator::SaveOriginalGlobalRSInfo(AkRSIterator *this, CAkRSSub *in_pSub, CAkContainerBaseInfo *in_pRSInfo)
{
  MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *v3; // rax
  CAkKeyArray<CAkRSSub *,CAkContainerBaseInfo *,4> *v4; // rsi
  CAkRSSub *v5; // rbx
  signed __int64 v6; // rcx
  CAkContainerBaseInfo *v7; // rax
  CAkContainerBaseInfo *v8; // rdi

  v3 = this->m_arOriginalGlobalRSInfo.m_pItems;
  v4 = &this->m_arOriginalGlobalRSInfo;
  v5 = in_pSub;
  v6 = (signed __int64)&v3[this->m_arOriginalGlobalRSInfo.m_uLength];
  if ( v3 == (MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *)v6 )
    goto LABEL_11;
  do
  {
    if ( v3->key == in_pSub )
      break;
    ++v3;
  }
  while ( v3 != (MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *)v6 );
  if ( v3 == (MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *)v6
    || v3 == (MapStruct<CAkRSSub *,CAkContainerBaseInfo *> *)-8i64 )
  {
LABEL_11:
    v7 = in_pRSInfo->vfptr->Clone(in_pRSInfo, in_pSub->m_listChildren.m_uLength);
    v8 = v7;
    if ( v7 )
    {
      if ( !CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4>::Set(v4, v5, v7) )
        v8->vfptr->Destroy(v8);
    }
  }
}

// File Line: 896
// RVA: 0xAB5B00
void __fastcall AkRSIterator::ForceSelectSequentially(AkRSIterator *this, CAkRSNode *in_pForcedNode)
{
  CAkRSNode *v2; // r8
  __int16 v3; // bx
  AkRSIterator *v4; // rsi
  CAkRSNode **v5; // rax
  signed __int64 i; // r9
  RSStackItem *v7; // rdi
  CAkRSSub *v8; // rcx
  CAkContainerBaseInfo *v9; // rdi
  CAkRSSub *v10; // rdx

  v2 = in_pForcedNode->m_pParent;
  v3 = 0;
  v4 = this;
  v5 = (CAkRSNode **)v2[1].vfptr;
  for ( i = (signed __int64)&v5[LODWORD(v2[1].m_pParent)]; v5 != (CAkRSNode **)i; ++v3 )
  {
    if ( *v5 == in_pForcedNode )
      break;
    ++v5;
  }
  v7 = &this->m_stack.m_pItems[this->m_stack.m_uLength];
  v8 = v7[-1].pRSNode;
  if ( (v8->m_eRSType - 1) & 0xFFFFFFFD )
    v9 = v7[-1].pLocalRSInfo;
  else
    v9 = CAkRSSub::GetGlobalRSInfo(v8);
  if ( v9 )
  {
    v10 = v4->m_stack.m_pItems[v4->m_stack.m_uLength - 1].pRSNode;
    if ( *((_BYTE *)v4 + 64) & 1 )
    {
      if ( v9 == v10->m_pGlobalCntrBaseInfo )
        AkRSIterator::SaveOriginalGlobalRSInfo(v4, v10, v9);
    }
    WORD1(v9[1].vfptr) = v3;
  }
}

