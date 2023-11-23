// File Line: 36
// RVA: 0xA6C080
StructMaxInst *__fastcall CAkKeyArray<CAkRegisteredObj *,StructMaxInst,2>::Exists(
        CAkKeyArray<CAkRegisteredObj *,StructMaxInst,2> *this,
        CAkRegisteredObj *in_Key)
{
  MapStruct<CAkRegisteredObj *,StructMaxInst> *m_pItems; // rax
  MapStruct<CAkRegisteredObj *,StructMaxInst> *v3; // rcx

  m_pItems = this->m_pItems;
  v3 = &this->m_pItems[this->m_uLength];
  if ( m_pItems == v3 )
    return 0i64;
  do
  {
    if ( m_pItems->key == in_Key )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v3 );
  if ( m_pItems == v3 )
    return 0i64;
  else
    return &m_pItems->item;
}

// File Line: 47
// RVA: 0xA738E0
AkStateLink *__fastcall CAkKeyArray<unsigned long,AkStateLink,2>::Set(
        CAkKeyArray<unsigned long,AkStateLink,2> *this,
        unsigned int in_Key,
        AkStateLink *in_Item)
{
  MapStruct<unsigned long,AkStateLink> *m_pItems; // rax
  unsigned __int64 m_uLength; // r15
  MapStruct<unsigned long,AkStateLink> *v8; // r9
  AkStateLink *p_item; // rbx
  AkStateLink *result; // rax
  __int64 v11; // rdx
  MapStruct<unsigned long,AkStateLink> *v12; // r8

  m_pItems = this->m_pItems;
  m_uLength = this->m_uLength;
  v8 = &this->m_pItems[m_uLength];
  if ( this->m_pItems != v8 )
  {
    do
    {
      if ( m_pItems->key == in_Key )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v8 );
  }
  if ( m_pItems == v8 )
  {
    p_item = 0i64;
  }
  else
  {
    p_item = &m_pItems->item;
    if ( m_pItems != (MapStruct<unsigned long,AkStateLink> *)-8i64 )
    {
      p_item->pState = in_Item->pState;
      *(_QWORD *)&m_pItems->item.ulStateID = *(_QWORD *)&in_Item->ulStateID;
      return p_item;
    }
  }
  if ( m_uLength >= this->m_ulReserved
    && !AkArray<MapStruct<AkMutedMapItem,float>,MapStruct<AkMutedMapItem,float> const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::GrowArray(
          this,
          2u) )
  {
    return p_item;
  }
  if ( m_uLength >= this->m_ulReserved )
    return p_item;
  v11 = this->m_uLength;
  v12 = &this->m_pItems[v11];
  this->m_uLength = v11 + 1;
  if ( !v12 )
    return p_item;
  v12->key = in_Key;
  result = &v12->item;
  v12->item.pState = in_Item->pState;
  *(_QWORD *)&v12->item.ulStateID = *(_QWORD *)&in_Item->ulStateID;
  return result;
}

// File Line: 87
// RVA: 0xAAB7A0
AkSegmentInfoRecord *__fastcall CAkKeyArray<unsigned long,AkSegmentInfoRecord,1>::Set(
        CAkKeyArray<unsigned long,AkSegmentInfoRecord,1> *this,
        unsigned int in_Key)
{
  MapStruct<unsigned long,AkSegmentInfoRecord> *m_pItems; // rax
  unsigned __int64 m_uLength; // r14
  MapStruct<unsigned long,AkSegmentInfoRecord> *v6; // r8
  AkSegmentInfoRecord *p_item; // rbx
  __int64 v9; // rdx
  MapStruct<unsigned long,AkSegmentInfoRecord> *v10; // r8

  m_pItems = this->m_pItems;
  m_uLength = this->m_uLength;
  v6 = &this->m_pItems[m_uLength];
  if ( this->m_pItems != v6 )
  {
    do
    {
      if ( m_pItems->key == in_Key )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v6 );
  }
  if ( m_pItems == v6 )
  {
    p_item = 0i64;
  }
  else
  {
    p_item = &m_pItems->item;
    if ( m_pItems != (MapStruct<unsigned long,AkSegmentInfoRecord> *)-8i64 )
      return p_item;
  }
  if ( m_uLength >= this->m_ulReserved
    && !AkArray<MapStruct<unsigned long,AkPositionInfo>,MapStruct<unsigned long,AkPositionInfo> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::GrowArray(
          this,
          1u) )
  {
    return p_item;
  }
  if ( m_uLength >= this->m_ulReserved )
    return p_item;
  v9 = this->m_uLength;
  v10 = &this->m_pItems[v9];
  this->m_uLength = v9 + 1;
  if ( !v10 )
    return p_item;
  v10->key = in_Key;
  return &v10->item;
}

// File Line: 123
// RVA: 0xA6F6E0
void __fastcall CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4>::Unset(
        CAkKeyArray<CAkRegisteredObj *,CAkSIS *,4> *this,
        CAkRegisteredObj *in_Key)
{
  MapStruct<CAkRegisteredObj *,CAkSIS *> *m_pItems; // rdi
  MapStruct<CAkRegisteredObj *,CAkSIS *> *v3; // rax

  m_pItems = this->m_pItems;
  v3 = &this->m_pItems[this->m_uLength];
  if ( this->m_pItems != v3 )
  {
    do
    {
      if ( m_pItems->key == in_Key )
        break;
      ++m_pItems;
    }
    while ( m_pItems != v3 );
    if ( m_pItems != v3 )
    {
      if ( m_pItems < &v3[-1] )
        qmemcpy(
          m_pItems,
          &m_pItems[1],
          8
        * (((((unsigned __int64)((char *)&v3[-1] - (char *)m_pItems - 1) >> 3) & 0xFFFFFFFFFFFFFFFEui64) + 2) & 0x1FFFFFFFFFFFFFFEi64));
      --this->m_uLength;
    }
  }
}

// File Line: 162
// RVA: 0xA8B2E0
CAkRTPCMgr::AkRTPCValue *__fastcall AkSortedKeyArray<CAkContinuationList *,CAkMultiPlayNode::ContParam,ArrayPoolDefault,CAkMultiPlayNode::ContParamGetKey,1>::Exists<CAkContinuationList *>(
        AkSortedKeyArray<CAkRegisteredObj *,CAkRTPCMgr::AkRTPCValue,ArrayPoolDefault,CAkRTPCMgr::AkRTPCValueGetKey,8> *this,
        CAkRegisteredObj *in_key)
{
  signed int v3; // r9d
  signed int v4; // r8d
  CAkRTPCMgr::AkRTPCValue *m_pItems; // rbx
  int v6; // eax
  unsigned __int64 pGameObj; // rdx

  v3 = this->m_uLength - 1;
  v4 = 0;
  if ( v3 < 0 )
    return 0i64;
  m_pItems = this->m_pItems;
  while ( 1 )
  {
    v6 = v4 + (v3 - v4) / 2;
    pGameObj = (unsigned __int64)m_pItems[v6].pGameObj;
    if ( (unsigned __int64)in_key >= pGameObj )
      break;
    v3 = v6 - 1;
LABEL_7:
    if ( v4 > v3 )
      return 0i64;
  }
  if ( (unsigned __int64)in_key > pGameObj )
  {
    v4 = v6 + 1;
    goto LABEL_7;
  }
  return &m_pItems[v6];
}

// File Line: 184
// RVA: 0xA54410
CAkRTPCMgr::AkRTPCSubscription **__fastcall AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2>::AddNoSetKey<CAkRTPCMgr::AkRTPCSubscription *>(
        AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2> *this,
        CAkRTPCMgr::AkRTPCSubscription *in_key)
{
  unsigned __int64 m_uLength; // rdi
  int v3; // r8d
  int v5; // r9d
  CAkRTPCMgr::AkRTPCSubscription **m_pItems; // r10
  __int64 v8; // rax
  unsigned __int64 v9; // rdx
  CAkRTPCMgr::AkRTPCSubscription **result; // rax
  __int64 v11; // rcx

  m_uLength = this->m_uLength;
  v3 = 0;
  v5 = m_uLength - 1;
  if ( (int)m_uLength - 1 < 0 )
  {
LABEL_8:
    m_pItems = this->m_pItems;
    if ( this->m_pItems )
    {
      v8 = v3;
      goto LABEL_10;
    }
    goto LABEL_13;
  }
  m_pItems = this->m_pItems;
  while ( 1 )
  {
    LODWORD(v8) = v3 + (v5 - v3) / 2;
    v9 = (unsigned __int64)m_pItems[(int)v8];
    if ( (unsigned __int64)in_key >= v9 )
      break;
    v5 = v8 - 1;
LABEL_7:
    if ( v3 > v5 )
      goto LABEL_8;
  }
  if ( (unsigned __int64)in_key > v9 )
  {
    v3 = v8 + 1;
    goto LABEL_7;
  }
  v8 = (int)v8;
LABEL_10:
  if ( &m_pItems[v8] )
    return AkArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription * const &,ArrayPoolDefault,2,AkArrayAllocatorDefault>::Insert(
             this,
             (8 * v8) >> 3);
LABEL_13:
  if ( m_uLength >= this->m_ulReserved
    && !AkArray<MapStruct<unsigned long,unsigned long>,MapStruct<unsigned long,unsigned long> const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::GrowArray(
          (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)this,
          2u)
    || m_uLength >= this->m_ulReserved )
  {
    return 0i64;
  }
  v11 = this->m_uLength;
  result = &this->m_pItems[v11];
  this->m_uLength = v11 + 1;
  return result;
}

// File Line: 203
// RVA: 0xA8B450
CAkRanSeqCntr::CntrInfoEntry *__fastcall AkSortedKeyArray<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry,ArrayPoolDefault,AkGetArrayKey<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry>,1>::Set<CAkRegisteredObj *>(
        AkSortedKeyArray<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry,ArrayPoolDefault,AkGetArrayKey<CAkRegisteredObj *,CAkRanSeqCntr::CntrInfoEntry>,1> *this,
        CAkRegisteredObj *in_key)
{
  signed int v2; // r8d
  signed int v4; // r9d
  CAkRanSeqCntr::CntrInfoEntry *m_pItems; // r11
  int v7; // eax
  unsigned __int64 key; // rdx
  CAkRanSeqCntr::CntrInfoEntry *v9; // rcx
  CAkRanSeqCntr::CntrInfoEntry *result; // rax

  v2 = 0;
  v4 = this->m_uLength - 1;
  if ( v4 >= 0 )
  {
    m_pItems = this->m_pItems;
    do
    {
      v7 = v2 + (v4 - v2) / 2;
      key = (unsigned __int64)m_pItems[v7].key;
      if ( (unsigned __int64)in_key >= key )
      {
        if ( (unsigned __int64)in_key <= key )
          return &m_pItems[v7];
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
  if ( this->m_pItems && &v9[v2] )
    result = AkArray<CAkRanSeqCntr::CntrInfoEntry,CAkRanSeqCntr::CntrInfoEntry const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::Insert(
               this,
               (16i64 * v2) >> 4);
  else
    result = (CAkRanSeqCntr::CntrInfoEntry *)AkArray<CAkRanSeqCntr::CntrInfoEntry,CAkRanSeqCntr::CntrInfoEntry const &,ArrayPoolDefault,1,AkArrayAllocatorDefault>::AddLast((AkArray<MapStruct<unsigned __int64,AkVPL *>,MapStruct<unsigned __int64,AkVPL *> const &,ArrayPoolDefault,1,AkArrayAllocatorDefault> *)this);
  if ( result )
    result->key = in_key;
  return result;
}

// File Line: 227
// RVA: 0xA54580
void __fastcall AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2>::Unset<CAkRTPCMgr::AkRTPCSubscription *>(
        AkSortedKeyArray<CAkRTPCMgr::AkRTPCSubscription *,CAkRTPCMgr::AkRTPCSubscription *,ArrayPoolDefault,CAkRTPCMgr::AkSubsPtrGetKey,2> *this,
        CAkRTPCMgr::AkRTPCSubscription *in_key)
{
  __int64 m_uLength; // r11
  int v3; // edi
  int v5; // esi
  CAkRTPCMgr::AkRTPCSubscription **m_pItems; // r10
  int v8; // eax
  unsigned __int64 v9; // rdx
  CAkRTPCMgr::AkRTPCSubscription **v10; // rdi
  CAkRTPCMgr::AkRTPCSubscription **v11; // rcx

  m_uLength = this->m_uLength;
  v3 = 0;
  v5 = m_uLength - 1;
  if ( (int)m_uLength - 1 < 0 )
    return;
  m_pItems = this->m_pItems;
  while ( 1 )
  {
    v8 = v3 + (v5 - v3) / 2;
    v9 = (unsigned __int64)m_pItems[v8];
    if ( (unsigned __int64)in_key >= v9 )
      break;
    v5 = v8 - 1;
LABEL_7:
    if ( v3 > v5 )
      return;
  }
  if ( (unsigned __int64)in_key > v9 )
  {
    v3 = v8 + 1;
    goto LABEL_7;
  }
  v10 = &m_pItems[v8];
  v11 = &m_pItems[m_uLength - 1];
  if ( v10 < v11 )
    qmemcpy(v10, v10 + 1, 8 * (((unsigned __int64)((char *)v11 - (char *)v10 - 1) >> 3) + 1));
  --this->m_uLength;
}

// File Line: 241
// RVA: 0xA70340
void __fastcall AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::Reorder<AkPriorityStruct_INC>(
        AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8> *this,
        AkPriorityStruct_INC in_OldKey,
        AkPriorityStruct_INC in_NewKey,
        CAkPBI *in_item)
{
  CAkPBI **v7; // rax
  CAkPBI **v8; // rdx
  CAkPBI **m_pItems; // rsi
  unsigned int v10; // ebp
  __int64 v11; // rdi
  __int64 v12; // r9
  CAkPBI *v13; // r8
  float priority; // xmm1_4
  float v16; // xmm1_4
  bool v17; // cf
  bool v18; // zf
  float v19; // xmm1_4
  bool v20; // cf
  bool v21; // zf
  float v22; // xmm1_4
  CAkPBI **v24; // rax
  __int64 v25; // rcx
  CAkPBI **v26; // rdx
  CAkPBI **v27; // r8
  CAkPBI *v28; // rax
  bool out_bFound[40]; // [rsp+20h] [rbp-28h] BYREF

  v7 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::BinarySearch<AkPriorityStruct_INC>(
         this,
         in_OldKey,
         out_bFound);
  v8 = v7;
  if ( !out_bFound[0] )
    return;
  m_pItems = this->m_pItems;
  v10 = this->m_uLength - 1;
  v11 = v7 - this->m_pItems;
  if ( (_DWORD)v11 )
  {
    v12 = (unsigned int)(v11 - 1);
    v13 = m_pItems[v12];
    priority = v13->m_PriorityInfoCurrent.currentPriority.priority;
    if ( in_NewKey.priority == priority
       ? in_NewKey.PBIID < v13->m_PriorityInfoCurrent.currentPriority.PBIID
       : in_NewKey.priority > priority )
    {
      if ( (unsigned int)v11 <= 1
        || ((v16 = m_pItems[(unsigned int)(v11 - 2)]->m_PriorityInfoCurrent.currentPriority.priority,
             in_NewKey.priority != v16)
          ? (v17 = v16 < in_NewKey.priority, v18 = v16 == in_NewKey.priority)
          : (v17 = in_NewKey.PBIID < m_pItems[(unsigned int)(v11 - 2)]->m_PriorityInfoCurrent.currentPriority.PBIID,
             v18 = in_NewKey.PBIID == m_pItems[(unsigned int)(v11 - 2)]->m_PriorityInfoCurrent.currentPriority.PBIID),
            !v17 && !v18) )
      {
LABEL_12:
        m_pItems[v12] = *v8;
        *v8 = v13;
        return;
      }
LABEL_24:
      v24 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::BinarySearch<AkPriorityStruct_INC>(
              this,
              in_NewKey,
              out_bFound);
      if ( v24 )
      {
        v25 = v24 - m_pItems;
        if ( (unsigned int)v25 > (unsigned int)v11 )
          LODWORD(v25) = v25 - 1;
      }
      else
      {
        LODWORD(v25) = v10;
      }
      v26 = &m_pItems[(unsigned int)v11];
      v27 = &m_pItems[(unsigned int)v25];
      if ( (unsigned int)v25 >= (unsigned int)v11 )
      {
        for ( ; v26 != v27; ++v26 )
          *v26 = v26[1];
      }
      else if ( v26 != v27 )
      {
        do
        {
          v28 = *--v26;
          v26[1] = v28;
        }
        while ( v26 != v27 );
        *v27 = in_item;
        return;
      }
      *v27 = in_item;
      return;
    }
  }
  if ( (unsigned int)v11 < v10 )
  {
    v12 = (unsigned int)(v11 + 1);
    v13 = m_pItems[v12];
    v19 = v13->m_PriorityInfoCurrent.currentPriority.priority;
    if ( in_NewKey.priority == v19 )
    {
      v20 = in_NewKey.PBIID < v13->m_PriorityInfoCurrent.currentPriority.PBIID;
      v21 = in_NewKey.PBIID == v13->m_PriorityInfoCurrent.currentPriority.PBIID;
    }
    else
    {
      v20 = v19 < in_NewKey.priority;
      v21 = v19 == in_NewKey.priority;
    }
    if ( !v20 && !v21 )
    {
      if ( (unsigned int)v11 >= this->m_uLength - 2 )
        goto LABEL_12;
      v22 = m_pItems[(unsigned int)(v11 + 2)]->m_PriorityInfoCurrent.currentPriority.priority;
      if ( in_NewKey.priority == v22
         ? in_NewKey.PBIID < m_pItems[(unsigned int)(v11 + 2)]->m_PriorityInfoCurrent.currentPriority.PBIID
         : in_NewKey.priority > v22 )
      {
        goto LABEL_12;
      }
      goto LABEL_24;
    }
  }
}

// File Line: 351
// RVA: 0xA70020
void __fastcall AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::ReSortArray<AkPriorityStruct_INC>(
        AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8> *this)
{
  unsigned int m_uLength; // eax
  __int64 v3; // rsi
  CAkPBI **m_pItems; // r13
  __int64 v5; // r12
  CAkPBI *v6; // r15
  CAkPBI **v7; // rax
  CAkPBI **v8; // rdx
  unsigned __int64 v9; // rbp
  unsigned __int64 m_ulReserved; // rax
  unsigned int v11; // r14d
  CAkPBI **v12; // rdi
  unsigned __int64 v13; // r8
  unsigned __int64 v14; // rdx
  __int64 v15; // rcx
  bool out_bFound; // [rsp+50h] [rbp+8h] BYREF

  m_uLength = this->m_uLength;
  if ( m_uLength )
  {
    v3 = 0i64;
    m_pItems = this->m_pItems;
    this->m_uLength = 0;
    v5 = m_uLength;
    do
    {
      v6 = m_pItems[v3];
      v7 = AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::BinarySearch<AkPriorityStruct_INC>(
             this,
             (AkPriorityStruct_INC)v6->m_PriorityInfoCurrent.currentPriority,
             &out_bFound);
      if ( v7 )
      {
        v8 = AkArray<CAkPBI *,CAkPBI * const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::Insert(
               this,
               v7 - this->m_pItems);
      }
      else
      {
        v9 = this->m_uLength;
        m_ulReserved = this->m_ulReserved;
        if ( v9 >= m_ulReserved )
        {
          v11 = m_ulReserved + 8;
          v12 = (CAkPBI **)AK::MemoryMgr::Malloc(g_DefaultPoolId, 8i64 * (unsigned int)(m_ulReserved + 8));
          if ( !v12 )
            goto LABEL_14;
          v13 = this->m_uLength;
          if ( this->m_pItems )
          {
            v14 = 0i64;
            if ( this->m_uLength )
            {
              do
              {
                ++v14;
                v12[v14 - 1] = this->m_pItems[v14 - 1];
              }
              while ( v14 < v13 );
            }
            AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pItems);
          }
          this->m_pItems = v12;
          this->m_ulReserved = v11;
        }
        if ( v9 >= this->m_ulReserved )
        {
LABEL_14:
          v8 = 0i64;
          goto LABEL_15;
        }
        v15 = this->m_uLength;
        v8 = &this->m_pItems[v15];
        this->m_uLength = v15 + 1;
      }
LABEL_15:
      ++v3;
      *v8 = v6;
    }
    while ( v3 < v5 );
  }
}

// File Line: 376
// RVA: 0xA6FDE0
CAkPBI **__fastcall AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8>::BinarySearch<AkPriorityStruct_INC>(
        AkSortedKeyArray<AkPriorityStruct,CAkPBI *,ArrayPoolDefault,CAkLimiter::AkSortedPBIGetKey,8> *this,
        AkPriorityStruct_INC in_key,
        bool *out_bFound)
{
  __int64 v3; // rdi
  signed int v5; // r10d
  signed int v6; // r9d
  int v7; // r8d
  CAkPBI *v8; // rdx
  float priority; // xmm0_4
  bool v10; // al
  bool v11; // cf
  bool v12; // zf

  v3 = 0i64;
  v5 = this->m_uLength - 1;
  v6 = 0;
  while ( v6 <= v5 )
  {
    v7 = v6 + (v5 - v6) / 2;
    v8 = this->m_pItems[v7];
    priority = v8->m_PriorityInfoCurrent.currentPriority.priority;
    if ( in_key.priority == priority )
      v10 = in_key.PBIID < v8->m_PriorityInfoCurrent.currentPriority.PBIID;
    else
      v10 = in_key.priority > priority;
    if ( v10 )
    {
      v5 = v7 - 1;
    }
    else
    {
      if ( in_key.priority == priority )
      {
        v11 = in_key.PBIID < v8->m_PriorityInfoCurrent.currentPriority.PBIID;
        v12 = in_key.PBIID == v8->m_PriorityInfoCurrent.currentPriority.PBIID;
      }
      else
      {
        v11 = priority < in_key.priority;
        v12 = priority == in_key.priority;
      }
      if ( v11 || v12 )
      {
        *out_bFound = 1;
        return &this->m_pItems[v7];
      }
      v6 = v7 + 1;
    }
  }
  *out_bFound = 0;
  if ( this->m_pItems )
    return &this->m_pItems[v6];
  return (CAkPBI **)v3;
}

