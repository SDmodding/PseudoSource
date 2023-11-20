// File Line: 36
// RVA: 0xA6C080
StructMaxInst *__fastcall CAkKeyArray<CAkRegisteredObj *,StructMaxInst,2>::Exists(CAkKeyArray<CAkRegisteredObj *,StructMaxInst,2> *this, CAkRegisteredObj *in_Key)
{
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v2; // rax
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v3; // rcx
  StructMaxInst *result; // rax

  v2 = this->m_pItems;
  v3 = &this->m_pItems[this->m_uLength];
  if ( v2 == v3 )
    goto LABEL_9;
  do
  {
    if ( v2->key == in_Key )
      break;
    ++v2;
  }
  while ( v2 != v3 );
  if ( v2 == v3 )
LABEL_9:
    result = 0i64;
  else
    result = &v2->item;
  return result;
}

// File Line: 47
// RVA: 0xA738E0
AkStateLink *__fastcall CAkKeyArray<unsigned long,AkStateLink,2>::Set(CAkKeyArray<unsigned long,AkStateLink,2> *this, unsigned int in_Key, AkStateLink *in_Item)
{
  MapStruct<unsigned long,AkStateLink> *v3; // rax
  unsigned __int64 v4; // r15
  AkStateLink *v5; // r14
  unsigned int v6; // esi
  CAkKeyArray<unsigned long,AkStateLink,2> *v7; // rdi
  MapStruct<unsigned long,AkStateLink> *v8; // r9
  AkStateLink *v9; // rbx
  AkStateLink *result; // rax
  __int64 v11; // rdx
  signed __int64 v12; // r8

  v3 = this->m_pItems;
  v4 = this->m_uLength;
  v5 = in_Item;
  v6 = in_Key;
  v7 = this;
  v8 = &this->m_pItems[v4];
  if ( this->m_pItems != v8 )
  {
    do
    {
      if ( v3->key == in_Key )
        break;
      ++v3;
    }
    while ( v3 != v8 );
  }
  if ( v3 == v8 )
  {
    v9 = 0i64;
  }
  else
  {
    v9 = &v3->item;
    if ( v3 != (MapStruct<unsigned long,AkStateLink> *)-8i64 )
    {
      v9->pState = in_Item->pState;
      *(_QWORD *)&v3->item.ulStateID = *(_QWORD *)&in_Item->ulStateID;
      return v9;
    }
  }
  if ( v4 >= this->m_ulReserved
    && !AkArray<MapStruct<AkMutedMapItem,float>,MapStruct<AkMutedMapItem,float> const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::GrowArray(
          (AkArray<MapStruct<unsigned long,AkStateLink>,MapStruct<unsigned long,AkStateLink> const &,ArrayPoolDefault,2,AkArrayAllocatorDefault> *)&this->m_pItems,
          2u) )
  {
    return v9;
  }
  if ( v4 >= v7->m_ulReserved )
    return v9;
  v11 = v7->m_uLength;
  v12 = (signed __int64)&v7->m_pItems[v11];
  v7->m_uLength = v11 + 1;
  if ( !v12 )
    return v9;
  *(_DWORD *)v12 = v6;
  result = (AkStateLink *)(v12 + 8);
  result->pState = v5->pState;
  *(_QWORD *)&result->ulStateID = *(_QWORD *)&v5->ulStateID;
  return result;
}

// File Line: 87
// RVA: 0xAAB7A0
AkSegmentInfoRecord *__fastcall CAkKeyArray<unsigned long,AkSegmentInfoRecord,1>::Set(CAkKeyArray<unsigned long,AkSegmentInfoRecord,1> *this, unsigned int in_Key)
{
  MapStruct<unsigned long,AkSegmentInfoRecord> *v2; // rax
  unsigned __int64 v3; // r14
  unsigned int v4; // edi
  CAkKeyArray<unsigned long,AkSegmentInfoRecord,1> *v5; // rsi
  MapStruct<unsigned long,AkSegmentInfoRecord> *v6; // r8
  signed __int64 v7; // rbx
  __int64 v9; // rdx
  MapStruct<unsigned long,AkSegmentInfoRecord> *v10; // r8

  v2 = this->m_pItems;
  v3 = this->m_uLength;
  v4 = in_Key;
  v5 = this;
  v6 = &this->m_pItems[v3];
  if ( this->m_pItems != v6 )
  {
    do
    {
      if ( v2->key == in_Key )
        break;
      ++v2;
    }
    while ( v2 != v6 );
  }
  if ( v2 == v6 )
  {
    v7 = 0i64;
  }
  else
  {
    v7 = (signed __int64)&v2->item;
    if ( v2 != (MapStruct<unsigned long,AkSegmentInfoRecord> *)-8i64 )
      return (AkSegmentInfoRecord *)v7;
  }
  if ( v3 >= this->m_ulReserved
    && !AkArray<MapStruct<unsigned long,AkPositionInfo>,MapStruct<unsigned long,AkPositionInfo> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
          (AkArray<MapStruct<unsigned long,AkSegmentInfoRecord>,MapStruct<unsigned long,AkSegmentInfoRecord> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)&this->m_pItems,
          1u) )
  {
    return (AkSegmentInfoRecord *)v7;
  }
  if ( v3 >= v5->m_ulReserved )
    return (AkSegmentInfoRecord *)v7;
  v9 = v5->m_uLength;
  v10 = &v5->m_pItems[v9];
  v5->m_uLength = v9 + 1;
  if ( !v10 )
    return (AkSegmentInfoRecord *)v7;
  v10->key = v4;
  return &v10->item;
}

// File Line: 123
// RVA: 0xA6F6E0
void __fastcall CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4>::Unset(CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *this, CAkRegisteredObj *in_Key)
{
  MapStruct<CAkRegisteredObj *,CAkSIS *> *v2; // rdi
  MapStruct<CAkRegisteredObj *,CAkSIS *> *v3; // rax

  v2 = this->m_pItems;
  v3 = &this->m_pItems[this->m_uLength];
  if ( this->m_pItems != v3 )
  {
    do
    {
      if ( v2->key == in_Key )
        break;
      ++v2;
    }
    while ( v2 != v3 );
    if ( v2 != v3 )
    {
      if ( v2 < &v3[-1] )
        qmemcpy(
          v2,
          &v2[1],
          8
        * (((((unsigned __int64)((char *)&v3[-1] - (char *)v2 - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
      --this->m_uLength;
    }
  }
}

// File Line: 162
// RVA: 0xA8B2E0
CAkRTPCMgr::AkRTPCValue *__fastcall AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *this, CAkRegisteredObj *in_key)
{
  CAkRegisteredObj *v2; // r10
  int v3; // er9
  int v4; // er8
  CAkRTPCMgr::AkRTPCValue *v5; // rbx
  int v6; // eax
  CAkRegisteredObj *v7; // rdx

  v2 = in_key;
  v3 = this->m_uLength - 1;
  v4 = 0;
  if ( v3 < 0 )
    return 0i64;
  v5 = this->m_pItems;
  while ( 1 )
  {
    v6 = v4 + (v3 - v4) / 2;
    v7 = v5[v6].pGameObj;
    if ( v2 >= v7 )
      break;
    v3 = v6 - 1;
LABEL_7:
    if ( v4 > v3 )
      return 0i64;
  }
  if ( v2 > v7 )
  {
    v4 = v6 + 1;
    goto LABEL_7;
  }
  return &v5[v6];
}

// File Line: 184
// RVA: 0xA54410
CAkRTPCMgr::AkRTPCSubscription **__fastcall AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2>::AddNoSetKey<CAkRTPCMgr::AkRTPCSubscription *>(AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2> *this, CAkRTPCMgr::AkRTPCSubscription *in_key)
{
  unsigned __int64 v2; // rdi
  int v3; // er8
  CAkRTPCMgr::AkRTPCSubscription *v4; // r11
  int v5; // er9
  AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2> *v6; // rbx
  CAkRTPCMgr::AkRTPCSubscription **v7; // r10
  __int64 v8; // rax
  CAkRTPCMgr::AkRTPCSubscription *v9; // rdx
  CAkRTPCMgr::AkRTPCSubscription **result; // rax
  __int64 v11; // rcx

  v2 = this->m_uLength;
  v3 = 0;
  v4 = in_key;
  v5 = v2 - 1;
  v6 = this;
  if ( (signed int)v2 - 1 < 0 )
  {
LABEL_8:
    v7 = this->m_pItems;
    if ( this->m_pItems )
    {
      v8 = v3;
      goto LABEL_10;
    }
    goto LABEL_13;
  }
  v7 = this->m_pItems;
  while ( 1 )
  {
    LODWORD(v8) = v3 + (v5 - v3) / 2;
    v9 = v7[(signed int)v8];
    if ( v4 >= v9 )
      break;
    v5 = v8 - 1;
LABEL_7:
    if ( v3 > v5 )
      goto LABEL_8;
  }
  if ( v4 > v9 )
  {
    v3 = v8 + 1;
    goto LABEL_7;
  }
  v8 = (signed int)v8;
LABEL_10:
  if ( &v7[v8] )
    return AkArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription * const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::Insert(
             (AkArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription * const &,ArrayPoolDefault,2,AkArrayAllocatorDefault> *)&this->m_pItems,
             8 * v8 >> 3);
LABEL_13:
  if ( v2 >= this->m_ulReserved
    && !AkArray<MapStruct<unsigned long,unsigned long>,MapStruct<unsigned long,unsigned long> const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::GrowArray(
          (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)this,
          2u)
    || v2 >= v6->m_ulReserved )
  {
    return 0i64;
  }
  v11 = v6->m_uLength;
  result = &v6->m_pItems[v11];
  v6->m_uLength = v11 + 1;
  return result;
}

// File Line: 203
// RVA: 0xA8B450
CAkRanSeqCntr::CntrInfoEntry *__fastcall AkSortedKeyArray<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry,ArrayPoolDefault,AkGetArrayKey<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry>,1>::Set<CAkRegisteredObj *>(AkSortedKeyArray<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry,ArrayPoolDefault,AkGetArrayKey<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry>,1> *this, CAkRegisteredObj *in_key)
{
  int v2; // er8
  CAkRegisteredObj *v3; // rbx
  int v4; // er9
  AkSortedKeyArray<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry,ArrayPoolDefault,AkGetArrayKey<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry>,1> *v5; // r10
  CAkRanSeqCntr::CntrInfoEntry *v6; // r11
  int v7; // eax
  CAkRegisteredObj *v8; // rdx
  CAkRanSeqCntr::CntrInfoEntry *v9; // rcx
  CAkRanSeqCntr::CntrInfoEntry *result; // rax

  v2 = 0;
  v3 = in_key;
  v4 = this->m_uLength - 1;
  v5 = this;
  if ( v4 >= 0 )
  {
    v6 = this->m_pItems;
    do
    {
      v7 = v2 + (v4 - v2) / 2;
      v8 = v6[v7].key;
      if ( v3 >= v8 )
      {
        if ( v3 <= v8 )
          return &v6[v7];
        v2 = v7 + 1;
      }
      else
      {
        v4 = v7 - 1;
      }
    }
    while ( v2 <= v4 );
  }
  v9 = this->m_pItems;
  if ( v5->m_pItems && &v9[v2] )
    result = AkArray<CAkRanSeqCntr::CntrInfoEntry,CAkRanSeqCntr::CntrInfoEntry const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Insert(
               (AkArray<CAkRanSeqCntr::CntrInfoEntry,CAkRanSeqCntr::CntrInfoEntry const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)&v5->m_pItems,
               16i64 * v2 >> 4);
  else
    result = (CAkRanSeqCntr::CntrInfoEntry *)AkArray<CAkRanSeqCntr::CntrInfoEntry,CAkRanSeqCntr::CntrInfoEntry const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast((AkArray<MapStruct<unsigned __int64,AkVPL *>,MapStruct<unsigned __int64,AkVPL *> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)v5);
  if ( result )
    result->key = v3;
  return result;
}

// File Line: 227
// RVA: 0xA54580
void __fastcall AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2>::Unset<CAkRTPCMgr::AkRTPCSubscription *>(AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2> *this, CAkRTPCMgr::AkRTPCSubscription *in_key)
{
  __int64 v2; // r11
  int v3; // edi
  CAkRTPCMgr::AkRTPCSubscription *v4; // r8
  int v5; // esi
  AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2> *v6; // r9
  CAkRTPCMgr::AkRTPCSubscription **v7; // r10
  int v8; // eax
  CAkRTPCMgr::AkRTPCSubscription *v9; // rdx
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rcx

  v2 = this->m_uLength;
  v3 = 0;
  v4 = in_key;
  v5 = v2 - 1;
  v6 = this;
  if ( (signed int)v2 - 1 < 0 )
    return;
  v7 = this->m_pItems;
  while ( 1 )
  {
    v8 = v3 + (v5 - v3) / 2;
    v9 = v7[v8];
    if ( v4 >= v9 )
      break;
    v5 = v8 - 1;
LABEL_7:
    if ( v3 > v5 )
      return;
  }
  if ( v4 > v9 )
  {
    v3 = v8 + 1;
    goto LABEL_7;
  }
  v10 = (unsigned __int64)&v7[v8];
  v11 = (unsigned __int64)&v7[v2 - 1];
  if ( v10 < v11 )
    qmemcpy((void *)v10, (const void *)(v10 + 8), 8 * (((v11 - v10 - 1) >> 3) + 1));
  --v6->m_uLength;
}

// File Line: 241
// RVA: 0xA70340
void __fastcall AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::Reorder<AkPriorityStruct_INC>(AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8> *this, AkPriorityStruct_INC in_OldKey, AkPriorityStruct_INC in_NewKey, CAkPBI *in_item)
{
  AkPriorityStruct_INC v4; // rbx
  CAkPBI *v5; // r15
  AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8> *v6; // r14
  CAkPBI **v7; // rax
  CAkPBI **v8; // rdx
  CAkPBI **v9; // rsi
  unsigned int v10; // ebp
  signed __int64 v11; // rdi
  __int64 v12; // r9
  CAkPBI *v13; // r8
  float v14; // xmm1_4
  bool v15; // al
  float v16; // xmm1_4
  bool v17; // cf
  bool v18; // zf
  float v19; // xmm1_4
  bool v20; // cf
  bool v21; // zf
  float v22; // xmm1_4
  bool v23; // al
  CAkPBI **v24; // rax
  signed __int64 v25; // rcx
  CAkPBI **v26; // rdx
  CAkPBI **v27; // r8
  CAkPBI *v28; // rax
  bool out_bFound; // [rsp+20h] [rbp-28h]
  AkPriorityStruct_INC v30; // [rsp+60h] [rbp+18h]

  v30 = in_NewKey;
  v4 = in_NewKey;
  v5 = in_item;
  v6 = this;
  v7 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::BinarySearch<AkPriorityStruct_INC>(
         this,
         in_OldKey,
         &out_bFound);
  v8 = v7;
  if ( !out_bFound )
    return;
  v9 = v6->m_pItems;
  v10 = v6->m_uLength - 1;
  v11 = v7 - v6->m_pItems;
  if ( (_DWORD)v11 )
  {
    v12 = (unsigned int)(v11 - 1);
    v13 = v9[v12];
    v14 = v13->m_PriorityInfoCurrent.currentPriority.priority;
    v15 = v30.priority == v14 ? v30.PBIID < v13->m_PriorityInfoCurrent.currentPriority.PBIID : v30.priority > v14;
    if ( v15 )
    {
      if ( (unsigned int)v11 <= 1
        || ((v16 = v9[(unsigned int)(v11 - 2)]->m_PriorityInfoCurrent.currentPriority.priority, v30.priority != v16) ? (v17 = v16 < v30.priority, v18 = v16 == v30.priority) : (v17 = v30.PBIID < v9[(unsigned int)(v11 - 2)]->m_PriorityInfoCurrent.currentPriority.PBIID, v18 = v30.PBIID == v9[(unsigned int)(v11 - 2)]->m_PriorityInfoCurrent.currentPriority.PBIID),
            !v17 && !v18) )
      {
LABEL_12:
        v9[v12] = *v8;
        *v8 = v13;
        return;
      }
LABEL_24:
      v24 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::BinarySearch<AkPriorityStruct_INC>(
              v6,
              v4,
              &out_bFound);
      if ( v24 )
      {
        v25 = v24 - v9;
        if ( (unsigned int)v25 > (unsigned int)v11 )
          LODWORD(v25) = v25 - 1;
      }
      else
      {
        LODWORD(v25) = v10;
      }
      v26 = &v9[(unsigned int)v11];
      v27 = &v9[(unsigned int)v25];
      if ( (unsigned int)v25 >= (unsigned int)v11 )
      {
        for ( ; v26 != v27; ++v26 )
          *v26 = v26[1];
      }
      else if ( v26 != v27 )
      {
        do
        {
          v28 = *(v26 - 1);
          --v26;
          v26[1] = v28;
        }
        while ( v26 != v27 );
        *v27 = v5;
        return;
      }
      *v27 = v5;
      return;
    }
  }
  if ( (unsigned int)v11 < v10 )
  {
    v12 = (unsigned int)(v11 + 1);
    v13 = v9[v12];
    v19 = v13->m_PriorityInfoCurrent.currentPriority.priority;
    if ( v30.priority == v19 )
    {
      v20 = v30.PBIID < v13->m_PriorityInfoCurrent.currentPriority.PBIID;
      v21 = v30.PBIID == v13->m_PriorityInfoCurrent.currentPriority.PBIID;
    }
    else
    {
      v20 = v19 < v30.priority;
      v21 = v19 == v30.priority;
    }
    if ( !v20 && !v21 )
    {
      if ( (unsigned int)v11 >= v6->m_uLength - 2 )
        goto LABEL_12;
      v22 = v9[(unsigned int)(v11 + 2)]->m_PriorityInfoCurrent.currentPriority.priority;
      v23 = v30.priority == v22 ? v30.PBIID < v9[(unsigned int)(v11 + 2)]->m_PriorityInfoCurrent.currentPriority.PBIID : v30.priority > v22;
      if ( v23 )
        goto LABEL_12;
      goto LABEL_24;
    }
  }
}

// File Line: 351
// RVA: 0xA70020
void __fastcall AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::ReSortArray<AkPriorityStruct_INC>(AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8> *this)
{
  __int64 v1; // rax
  AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8> *v2; // rbx
  __int64 v3; // rsi
  CAkPBI **v4; // r13
  __int64 v5; // r12
  CAkPBI *v6; // r15
  CAkPBI **v7; // rax
  CAkPBI **v8; // rdx
  unsigned __int64 v9; // rbp
  unsigned __int64 v10; // rax
  unsigned int v11; // er14
  CAkPBI **v12; // rdi
  unsigned __int64 v13; // r8
  unsigned __int64 v14; // rdx
  __int64 v15; // rcx
  bool out_bFound; // [rsp+50h] [rbp+8h]

  v1 = this->m_uLength;
  v2 = this;
  if ( (_DWORD)v1 )
  {
    v3 = 0i64;
    v4 = this->m_pItems;
    this->m_uLength = 0;
    v5 = (unsigned int)v1;
    if ( v1 > 0 )
    {
      do
      {
        v6 = v4[v3];
        v7 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::BinarySearch<AkPriorityStruct_INC>(
               v2,
               (AkPriorityStruct_INC)v6->m_PriorityInfoCurrent.currentPriority,
               &out_bFound);
        if ( v7 )
        {
          v8 = AkArray<CAkPBI *,CAkPBI * const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::Insert(
                 (AkArray<CAkPBI *,CAkPBI * const &,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)&v2->m_pItems,
                 v7 - v2->m_pItems);
        }
        else
        {
          v9 = v2->m_uLength;
          v10 = v2->m_ulReserved;
          if ( v9 >= v10 )
          {
            v11 = v10 + 8;
            v12 = (CAkPBI **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * (unsigned int)(v10 + 8));
            if ( !v12 )
              goto LABEL_14;
            v13 = v2->m_uLength;
            if ( v2->m_pItems )
            {
              v14 = 0i64;
              if ( v2->m_uLength )
              {
                do
                {
                  ++v14;
                  v12[v14 - 1] = v2->m_pItems[v14 - 1];
                }
                while ( v14 < v13 );
              }
              AK::MemoryMgr::Free(g_DefaultPoolId, v2->m_pItems);
            }
            v2->m_pItems = v12;
            v2->m_ulReserved = v11;
          }
          if ( v9 >= v2->m_ulReserved )
          {
LABEL_14:
            v8 = 0i64;
            goto LABEL_15;
          }
          v15 = v2->m_uLength;
          v8 = &v2->m_pItems[v15];
          v2->m_uLength = v15 + 1;
        }
LABEL_15:
        ++v3;
        *v8 = v6;
      }
      while ( v3 < v5 );
    }
  }
}

// File Line: 376
// RVA: 0xA6FDE0
CAkPBI **__fastcall AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::BinarySearch<AkPriorityStruct_INC>(AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8> *this, AkPriorityStruct_INC in_key, bool *out_bFound)
{
  CAkPBI **v3; // rdi
  bool *v4; // rsi
  int v5; // er10
  int v6; // er9
  int v7; // er8
  CAkPBI *v8; // rdx
  float v9; // xmm0_4
  bool v10; // al
  bool v11; // cf
  bool v12; // zf
  AkPriorityStruct_INC v14; // [rsp+18h] [rbp+10h]

  v14 = in_key;
  v3 = 0i64;
  v4 = out_bFound;
  v5 = this->m_uLength - 1;
  v6 = 0;
  while ( v6 <= v5 )
  {
    v7 = v6 + (v5 - v6) / 2;
    v8 = this->m_pItems[v7];
    v9 = v8->m_PriorityInfoCurrent.currentPriority.priority;
    if ( v14.priority == v9 )
      v10 = v14.PBIID < v8->m_PriorityInfoCurrent.currentPriority.PBIID;
    else
      v10 = v14.priority > v9;
    if ( v10 )
    {
      v5 = v7 - 1;
    }
    else
    {
      if ( v14.priority == v9 )
      {
        v11 = v14.PBIID < v8->m_PriorityInfoCurrent.currentPriority.PBIID;
        v12 = v14.PBIID == v8->m_PriorityInfoCurrent.currentPriority.PBIID;
      }
      else
      {
        v11 = v9 < v14.priority;
        v12 = v9 == v14.priority;
      }
      if ( v11 || v12 )
      {
        *v4 = 1;
        return &this->m_pItems[v7];
      }
      v6 = v7 + 1;
    }
  }
  *v4 = 0;
  if ( this->m_pItems )
    v3 = &this->m_pItems[v6];
  return v3;
}

