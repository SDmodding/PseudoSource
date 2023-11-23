// File Line: 30
// RVA: 0xAB4960
void __fastcall CAkMusicTransAware::CAkMusicTransAware(CAkMusicTransAware *this, unsigned int in_ulID)
{
  CAkMusicNode::CAkMusicNode(this, in_ulID);
  this->vfptr = (CAkIndexableVtbl *)&CAkMusicTransAware::`vftable;
  this->m_arTrRules.m_pItems = 0i64;
  *(_QWORD *)&this->m_arTrRules.m_uLength = 0i64;
}

// File Line: 34
// RVA: 0xAB49A0
void __fastcall CAkMusicTransAware::~CAkMusicTransAware(CAkMusicTransAware *this)
{
  AkArray<AkMusicTransitionRule,AkMusicTransitionRule const &,ArrayPoolDefault,0,AkArrayAllocatorDefault> *p_m_arTrRules; // rbx

  p_m_arTrRules = &this->m_arTrRules;
  this->vfptr = (CAkIndexableVtbl *)&CAkMusicTransAware::`vftable;
  if ( this->m_arTrRules.m_pItems )
  {
    AkArray<AkMusicTransitionRule,AkMusicTransitionRule const &,ArrayPoolDefault,0,AkArrayAllocatorDefault>::RemoveAll(&this->m_arTrRules);
    AK::MemoryMgr::Free(g_DefaultPoolId, p_m_arTrRules->m_pItems);
    p_m_arTrRules->m_pItems = 0i64;
    p_m_arTrRules->m_ulReserved = 0;
  }
  CAkMusicNode::~CAkMusicNode(this);
}

// File Line: 40
// RVA: 0xAB50D0
__int64 __fastcall CAkMusicTransAware::SetMusicTransNodeParams(
        CAkMusicTransAware *this,
        char **io_rpData,
        unsigned int *io_rulDataSize,
        bool in_bPartialLoadOnly)
{
  __int64 result; // rax
  AkArray<AkMusicTransitionRule,AkMusicTransitionRule const &,ArrayPoolDefault,0,AkArrayAllocatorDefault> *p_m_arTrRules; // r15
  unsigned int v8; // r13d
  AkMusicTransitionRule *v9; // rax
  unsigned int i; // r12d
  unsigned int m_uLength; // eax
  __int64 v12; // rdi
  __int64 v13; // rsi
  void *v14; // rax
  unsigned int v15; // ebp
  unsigned int *v16; // rax
  __int64 v17; // rsi
  void *v18; // rax
  unsigned int v19; // ebp
  unsigned int *v20; // rax
  int v21; // ecx
  int v22; // ecx
  int v23; // ecx
  int v24; // ecx
  int v25; // ecx
  int v26; // ecx
  int v27; // ecx
  int v28; // ecx
  int v29; // ecx
  int v30; // ecx
  _DWORD *v31; // r8
  int v32; // ecx
  int v33; // ecx
  int v34; // ecx
  int v35; // ecx
  int v36; // ecx
  int v37; // ecx
  int v38; // ecx

  result = CAkMusicNode::SetMusicNodeParams(this, io_rpData, io_rulDataSize, in_bPartialLoadOnly);
  if ( (_DWORD)result == 1 )
  {
    p_m_arTrRules = &this->m_arTrRules;
    if ( p_m_arTrRules->m_pItems )
    {
      AkArray<AkMusicTransitionRule,AkMusicTransitionRule const &,ArrayPoolDefault,0,AkArrayAllocatorDefault>::RemoveAll(p_m_arTrRules);
      AK::MemoryMgr::Free(g_DefaultPoolId, p_m_arTrRules->m_pItems);
      p_m_arTrRules->m_pItems = 0i64;
      p_m_arTrRules->m_ulReserved = 0;
    }
    v8 = *(_DWORD *)*io_rpData;
    *io_rpData += 4;
    if ( v8 )
    {
      v9 = (AkMusicTransitionRule *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 88i64 * v8);
      p_m_arTrRules->m_pItems = v9;
      if ( !v9 )
        return 2i64;
      p_m_arTrRules->m_ulReserved = v8;
      for ( i = 0; i < v8; ++i )
      {
        m_uLength = p_m_arTrRules->m_uLength;
        if ( m_uLength >= p_m_arTrRules->m_ulReserved )
        {
          v12 = 0i64;
        }
        else
        {
          p_m_arTrRules->m_uLength = m_uLength + 1;
          v12 = (__int64)&p_m_arTrRules->m_pItems[m_uLength];
          if ( v12 )
          {
            *(_QWORD *)v12 = 0i64;
            *(_QWORD *)(v12 + 8) = 0i64;
            *(_QWORD *)(v12 + 16) = 0i64;
            *(_QWORD *)(v12 + 24) = 0i64;
            *(_QWORD *)(v12 + 80) = 0i64;
          }
        }
        v13 = *(unsigned int *)*io_rpData;
        *io_rpData += 4;
        if ( (_DWORD)v13 )
        {
          v14 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 4i64 * (unsigned int)v13);
          *(_QWORD *)v12 = v14;
          if ( !v14 )
            return 2i64;
          *(_DWORD *)(v12 + 12) = v13;
          do
          {
            v15 = *(_DWORD *)*io_rpData;
            *io_rpData += 4;
            v16 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast((AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault> *)v12);
            if ( v16 )
              *v16 = v15;
            --v13;
          }
          while ( v13 );
        }
        v17 = *(unsigned int *)*io_rpData;
        *io_rpData += 4;
        if ( (_DWORD)v17 )
        {
          v18 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 4i64 * (unsigned int)v17);
          *(_QWORD *)(v12 + 16) = v18;
          if ( !v18 )
            return 2i64;
          *(_DWORD *)(v12 + 28) = v17;
          do
          {
            v19 = *(_DWORD *)*io_rpData;
            *io_rpData += 4;
            v20 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast((AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault> *)(v12 + 16));
            if ( v20 )
              *v20 = v19;
            --v17;
          }
          while ( v17 );
        }
        v21 = *(_DWORD *)*io_rpData;
        *io_rpData += 4;
        *(_DWORD *)(v12 + 32) = v21;
        v22 = *(_DWORD *)*io_rpData;
        *io_rpData += 4;
        *(_DWORD *)(v12 + 36) = v22;
        v23 = *(_DWORD *)*io_rpData;
        *io_rpData += 4;
        *(_DWORD *)(v12 + 40) = v23 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
        v24 = *(_DWORD *)*io_rpData;
        *io_rpData += 4;
        *(_DWORD *)(v12 + 48) &= 0xFFFFFFE0;
        *(_DWORD *)(v12 + 48) |= v24 & 0x1F;
        v25 = *(_DWORD *)*io_rpData;
        *io_rpData += 4;
        *(_DWORD *)(v12 + 44) = v25;
        LOBYTE(v25) = *(*io_rpData)++;
        *(_DWORD *)(v12 + 48) &= ~0x20u;
        *(_DWORD *)(v12 + 48) |= 32 * (v25 & 1);
        v26 = *(_DWORD *)*io_rpData;
        *io_rpData += 4;
        *(_DWORD *)(v12 + 52) = v26;
        v27 = *(_DWORD *)*io_rpData;
        *io_rpData += 4;
        *(_DWORD *)(v12 + 56) = v27;
        v28 = *(_DWORD *)*io_rpData;
        *io_rpData += 4;
        *(_DWORD *)(v12 + 60) = v28 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
        v29 = *(_DWORD *)*io_rpData;
        *io_rpData += 4;
        *(_DWORD *)(v12 + 64) = v29;
        v30 = *(_DWORD *)*io_rpData;
        *io_rpData += 4;
        *(_DWORD *)(v12 + 68) = v30;
        LOWORD(v30) = *(_WORD *)*io_rpData;
        *io_rpData += 2;
        *(_WORD *)(v12 + 72) &= 0xFFF8u;
        *(_WORD *)(v12 + 72) |= v30 & 7;
        LOBYTE(v30) = *(*io_rpData)++;
        *(_WORD *)(v12 + 72) &= ~8u;
        *(_WORD *)(v12 + 72) |= 8 * (v30 & 1);
        LOBYTE(v30) = *(*io_rpData)++;
        *(_WORD *)(v12 + 72) &= ~0x10u;
        *(_WORD *)(v12 + 72) |= 16 * (v30 & 1);
        LOBYTE(v30) = *(*io_rpData)++;
        if ( (_BYTE)v30 )
        {
          v31 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x20ui64);
          *(_QWORD *)(v12 + 80) = v31;
        }
        else
        {
          v31 = 0i64;
        }
        if ( v31 )
        {
          v32 = *(_DWORD *)*io_rpData;
          *io_rpData += 4;
          *v31 = v32;
          v33 = *(_DWORD *)*io_rpData;
          *io_rpData += 4;
          v31[1] = v33;
          v34 = *(_DWORD *)*io_rpData;
          *io_rpData += 4;
          v31[2] = v34;
          v35 = *(_DWORD *)*io_rpData;
          *io_rpData += 4;
          v31[3] = v35 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
          v36 = *(_DWORD *)*io_rpData;
          *io_rpData += 4;
          v31[4] = v36;
          v37 = *(_DWORD *)*io_rpData;
          *io_rpData += 4;
          v31[5] = v37;
          v38 = *(_DWORD *)*io_rpData;
          *io_rpData += 4;
          v31[6] = v38 * (AkAudioLibSettings::g_pipelineCoreFrequency / 0x3E8);
          LOBYTE(v38) = *(*io_rpData)++;
          v31[7] &= ~1u;
          v31[7] |= v38 & 1;
          LOBYTE(v38) = *(*io_rpData)++;
          v31[7] &= ~2u;
          v31[7] |= 2 * (v38 & 1);
        }
      }
    }
    return 1i64;
  }
  return result;
}

// File Line: 128
// RVA: 0xAB4BF0
AkMusicTransitionRule *__fastcall CAkMusicTransAware::GetTransitionRule(
        CAkMusicTransAware *this,
        unsigned int in_srcID,
        unsigned int in_destID)
{
  signed int v5; // eax
  __int64 v7; // rsi
  AkMusicTransitionRule *i; // r11
  unsigned int *m_pItems; // r9
  __int64 m_uLength; // rax
  unsigned int *v11; // rcx
  unsigned int *v12; // r8
  unsigned int *v13; // r10
  __int64 v14; // kr00_8
  unsigned int *v15; // rdx
  unsigned int *v16; // r9
  __int64 v17; // rax
  unsigned int *v18; // rcx
  unsigned int *v19; // r8
  unsigned int *v20; // r10
  __int64 v21; // kr08_8
  unsigned int *v22; // rdx

  v5 = this->m_arTrRules.m_uLength - 1;
  v7 = v5;
  if ( v5 < 0 )
    return this->m_arTrRules.m_pItems;
  for ( i = &this->m_arTrRules.m_pItems[v5]; ; --i )
  {
    m_pItems = i->srcIDs.m_pItems;
    if ( *i->srcIDs.m_pItems == -1 )
      goto LABEL_30;
    m_uLength = i->srcIDs.m_uLength;
    v11 = &m_pItems[m_uLength];
    v12 = v11;
    if ( m_pItems )
    {
      v13 = &m_pItems[m_uLength];
      if ( m_pItems <= v11 )
      {
        do
        {
          v14 = v13 - m_pItems;
          v15 = &m_pItems[v14 / 2];
          if ( in_srcID >= *v15 )
          {
            if ( in_srcID <= *v15 )
            {
              v12 = &m_pItems[v14 / 2];
              break;
            }
            m_pItems = v15 + 1;
          }
          else
          {
            v13 = v15 - 1;
          }
        }
        while ( m_pItems <= v13 );
      }
    }
    if ( v12 != v11 )
    {
LABEL_30:
      v16 = i->destIDs.m_pItems;
      if ( *v16 == -1 )
        break;
      v17 = i->destIDs.m_uLength;
      v18 = &v16[v17];
      v19 = v18;
      if ( v16 )
      {
        v20 = &v16[v17];
        if ( v16 <= v18 )
        {
          do
          {
            v21 = v20 - v16;
            v22 = &v16[v21 / 2];
            if ( in_destID >= *v22 )
            {
              if ( in_destID <= *v22 )
              {
                v19 = &v16[v21 / 2];
                break;
              }
              v16 = v22 + 1;
            }
            else
            {
              v20 = v22 - 1;
            }
          }
          while ( v16 <= v20 );
        }
      }
      if ( v19 != v18 )
        break;
    }
    if ( --v7 < 0 )
      return this->m_arTrRules.m_pItems;
  }
  return i;
}

// File Line: 157
// RVA: 0xAB4D20
AkMusicTransitionRule *__fastcall CAkMusicTransAware::GetTransitionRule(
        CAkMusicTransAware *this,
        CAkParameterNodeBase *in_pOwnerNode,
        unsigned int in_srcID,
        CAkParameterNodeBase *in_pSrcParentNode,
        unsigned int in_destID,
        CAkParameterNodeBase *in_pDestParentNode,
        bool *out_bIsDestSequenceSpecific)
{
  CAkParameterNodeBase *v7; // r11
  signed int v9; // eax
  CAkMusicTransAware *v11; // r10
  __int64 v12; // r12
  AkMusicTransitionRule *i; // rsi
  __int64 m_uLength; // rax
  __int64 v15; // rbx
  unsigned int *m_pItems; // r9
  unsigned int *v17; // rcx
  unsigned int *v18; // r8
  unsigned int *v19; // r10
  __int64 v20; // kr00_8
  unsigned int *v21; // rdx
  unsigned int *v22; // rdi
  unsigned int *v23; // r8
  unsigned int *v24; // rcx
  unsigned int *v25; // r9
  unsigned int *v26; // r10
  __int64 v27; // kr08_8
  unsigned int *v28; // rdx
  CAkParameterNodeBase *v29; // rbx
  unsigned int key; // r11d
  unsigned int *v31; // rcx
  unsigned int *v32; // r9
  unsigned int *v33; // r10
  __int64 v34; // kr10_8
  unsigned int *v35; // rdx
  AkMusicTransitionRule *result; // rax

  v7 = in_pSrcParentNode;
  v9 = this->m_arTrRules.m_uLength - 1;
  v11 = this;
  v12 = v9;
  if ( v9 < 0 )
    return v11->m_arTrRules.m_pItems;
  for ( i = &this->m_arTrRules.m_pItems[v9]; ; --i )
  {
    m_uLength = i->srcIDs.m_uLength;
    if ( (_DWORD)m_uLength )
    {
      v15 = i->destIDs.m_uLength;
      if ( (_DWORD)v15 )
        break;
    }
LABEL_43:
    if ( --v12 < 0 )
      return v11->m_arTrRules.m_pItems;
    v7 = in_pSrcParentNode;
  }
  m_pItems = i->srcIDs.m_pItems;
  if ( *i->srcIDs.m_pItems == -1 )
    goto LABEL_18;
  v17 = &m_pItems[m_uLength];
  v18 = v17;
  if ( !m_pItems )
    goto LABEL_16;
  v19 = &m_pItems[m_uLength];
  if ( m_pItems > v17 )
    goto LABEL_15;
  while ( 1 )
  {
    v20 = v19 - m_pItems;
    v21 = &m_pItems[v20 / 2];
    if ( in_srcID >= *v21 )
      break;
    v19 = v21 - 1;
LABEL_12:
    if ( m_pItems > v19 )
      goto LABEL_15;
  }
  if ( in_srcID > *v21 )
  {
    m_pItems = v21 + 1;
    goto LABEL_12;
  }
  v18 = &m_pItems[v20 / 2];
LABEL_15:
  v11 = this;
LABEL_16:
  if ( v18 == v17 && !CAkMusicTransAware::AscendentMatch(v11, in_pOwnerNode, &i->srcIDs, v7) )
  {
LABEL_42:
    v11 = this;
    goto LABEL_43;
  }
LABEL_18:
  v22 = i->destIDs.m_pItems;
  if ( *v22 != -1 )
  {
    v23 = &v22[v15];
    v24 = v23;
    if ( v22 )
    {
      v25 = i->destIDs.m_pItems;
      v26 = &v22[v15];
      if ( v22 <= v23 )
      {
        do
        {
          v27 = v26 - v25;
          v28 = &v25[v27 / 2];
          if ( in_destID >= *v28 )
          {
            if ( in_destID <= *v28 )
            {
              v24 = &v25[v27 / 2];
              break;
            }
            v25 = v28 + 1;
          }
          else
          {
            v26 = v28 - 1;
          }
        }
        while ( v25 <= v26 );
      }
    }
    if ( v24 == v23 )
    {
      v29 = in_pDestParentNode;
      if ( in_pDestParentNode )
      {
        while ( v29 != in_pOwnerNode )
        {
          key = v29->key;
          v31 = v23;
          if ( v22 )
          {
            v32 = i->destIDs.m_pItems;
            v33 = v23;
            if ( v22 <= v23 )
            {
              do
              {
                v34 = v33 - v32;
                v35 = &v32[v34 / 2];
                if ( key >= *v35 )
                {
                  if ( key <= *v35 )
                  {
                    v31 = &v32[v34 / 2];
                    break;
                  }
                  v32 = v35 + 1;
                }
                else
                {
                  v33 = v35 - 1;
                }
              }
              while ( v32 <= v33 );
            }
          }
          if ( v31 != v23 )
          {
            if ( v29->vfptr[3].Release(v29) != 8 )
              goto LABEL_47;
            *out_bIsDestSequenceSpecific = 1;
            return i;
          }
          v29 = v29->m_pParentNode;
          if ( !v29 )
            goto LABEL_42;
        }
      }
      goto LABEL_42;
    }
  }
LABEL_47:
  result = i;
  *out_bIsDestSequenceSpecific = 0;
  return result;
}

// File Line: 192
// RVA: 0xAB4B10
AkMusicTransitionRule *__fastcall CAkMusicTransAware::GetPanicTransitionRule()
{
  unsigned int *v0; // rax
  unsigned int *v1; // rax

  if ( (_S1_37 & 1) == 0 )
  {
    panicRule.srcIDs.m_pItems = 0i64;
    unk_14249F658 = 0i64;
    stru_14249F660.m_pItems = 0i64;
    *(_QWORD *)&stru_14249F660.m_uLength = 0i64;
    _S1_37 |= 1u;
    in_pvMemAddress = 0i64;
    atexit(CAkMusicTransAware::GetPanicTransitionRule_::_2_::_dynamic_atexit_destructor_for__panicRule__);
  }
  v0 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast(&panicRule.srcIDs);
  if ( v0 )
    *v0 = -1;
  unk_14249F670 = 0;
  unk_14249F678 = 0i64;
  unk_14249F680 = unk_14249F680 & 0xFFFFFFC0 | 0x27;
  v1 = AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault>::AddLast(&stru_14249F660);
  if ( v1 )
    *v1 = -1;
  unk_14249F684 = 0;
  unk_14249F68C = 0i64;
  unk_14249F694 = 0;
  in_pvMemAddress = 0i64;
  unk_14249F698 &= 0xFFE0u;
  return &panicRule;
}

// File Line: 222
// RVA: 0xAB4A50
CAkParameterNodeBase *__fastcall CAkMusicTransAware::AscendentMatch(
        CAkMusicTransAware *this,
        CAkParameterNodeBase *in_pOwnerNode,
        AkArray<unsigned long,unsigned long,ArrayPoolDefault,16,AkArrayAllocatorDefault> *in_ruleIDs,
        CAkParameterNodeBase *in_pNode)
{
  CAkParameterNodeBase *v4; // r11
  unsigned int *m_pItems; // r10
  __int64 m_uLength; // rax
  unsigned int key; // ebx
  unsigned int *v10; // rcx
  unsigned int *v11; // r8
  unsigned int *v12; // r9
  __int64 v13; // kr00_8
  unsigned int *v14; // rdx

  v4 = in_pNode;
  if ( in_pNode )
  {
    while ( v4 != in_pOwnerNode )
    {
      m_pItems = in_ruleIDs->m_pItems;
      m_uLength = in_ruleIDs->m_uLength;
      key = v4->key;
      v10 = &in_ruleIDs->m_pItems[m_uLength];
      v11 = v10;
      if ( in_ruleIDs->m_pItems )
      {
        v12 = &in_ruleIDs->m_pItems[m_uLength];
        if ( m_pItems <= v10 )
        {
          do
          {
            v13 = v12 - m_pItems;
            v14 = &m_pItems[v13 / 2];
            if ( key >= *v14 )
            {
              if ( key <= *v14 )
              {
                v11 = &m_pItems[v13 / 2];
                break;
              }
              m_pItems = v14 + 1;
            }
            else
            {
              v12 = v14 - 1;
            }
          }
          while ( m_pItems <= v12 );
        }
      }
      if ( v11 != v10 )
        return v4;
      v4 = v4->m_pParentNode;
      if ( !v4 )
        return 0i64;
    }
  }
  return 0i64;
}

// File Line: 322
// RVA: 0xAB4F60
__int64 __fastcall CAkMusicTransAware::PrepareMusicalDependencies(CAkMusicTransAware *this)
{
  __int64 result; // rax
  unsigned int v3; // ebp
  __int64 v4; // rsi
  __int64 v5; // rbx
  AkMusicTransitionObject *pTransObj; // rdx
  AkMusicTransitionObject *v7; // rcx

  result = CAkMusicNode::PrepareMusicalDependencies(this);
  v3 = result;
  if ( (_DWORD)result == 1 )
  {
    v4 = 0i64;
    v5 = 0i64;
    if ( this->m_arTrRules.m_uLength )
    {
      while ( 1 )
      {
        pTransObj = this->m_arTrRules.m_pItems[(unsigned int)v5].pTransObj;
        if ( pTransObj )
        {
          v3 = CAkParameterNodeBase::PrepareNodeData(pTransObj->segmentID);
          if ( v3 != 1 )
            break;
        }
        v5 = (unsigned int)(v5 + 1);
        if ( (unsigned int)v5 >= this->m_arTrRules.m_uLength )
          return v3;
      }
      if ( (_DWORD)v5 )
      {
        do
        {
          v7 = this->m_arTrRules.m_pItems[v4].pTransObj;
          if ( v7 )
            CAkParameterNodeBase::UnPrepareNodeData(v7->segmentID);
          ++v4;
          --v5;
        }
        while ( v5 );
      }
      CAkMusicNode::UnPrepareMusicalDependencies(this);
      return v3;
    }
  }
  return result;
}

// File Line: 358
// RVA: 0xAB54F0
void __fastcall CAkMusicTransAware::UnPrepareMusicalDependencies(CAkMusicTransAware *this)
{
  unsigned int i; // ebx
  AkMusicTransitionObject *pTransObj; // rcx

  for ( i = 0; i < this->m_arTrRules.m_uLength; ++i )
  {
    pTransObj = this->m_arTrRules.m_pItems[i].pTransObj;
    if ( pTransObj )
      CAkParameterNodeBase::UnPrepareNodeData(pTransObj->segmentID);
  }
  CAkMusicNode::UnPrepareMusicalDependencies(this);
}

