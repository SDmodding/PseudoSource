// File Line: 27
// RVA: 0xA53BB0
void __fastcall AkDecisionTree::AkDecisionTree(AkDecisionTree *this)
{
  this->m_uMode = 0;
  this->m_uDepth = 0;
  this->m_pNodes = 0i64;
  this->m_uProbability = 100;
}

// File Line: 32
// RVA: 0xA53BD0
void __fastcall AkDecisionTree::~AkDecisionTree(AkDecisionTree *this)
{
  AkDecisionTree::Node *m_pNodes; // rdx

  m_pNodes = this->m_pNodes;
  if ( m_pNodes )
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pNodes);
}

// File Line: 38
// RVA: 0xA54170
__int64 __fastcall AkDecisionTree::SetTree(
        AkDecisionTree *this,
        void *in_pData,
        unsigned int in_uSize,
        unsigned int in_uDepth)
{
  AkDecisionTree::Node *m_pNodes; // rdx
  unsigned __int64 v7; // rdi
  AkDecisionTree::Node *v9; // rax

  m_pNodes = this->m_pNodes;
  v7 = in_uSize;
  if ( m_pNodes )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pNodes);
    this->m_pNodes = 0i64;
  }
  if ( (_DWORD)v7 )
  {
    v9 = (AkDecisionTree::Node *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v7);
    this->m_pNodes = v9;
    if ( !v9 )
      return 52i64;
    memmove(v9, in_pData, v7);
  }
  this->m_uDepth = in_uDepth;
  return 1i64;
}

// File Line: 60
// RVA: 0xA53BF0
void __fastcall AkDecisionTree::AddCandidate(
        AkDecisionTree *this,
        AkDecisionTree::Node *pNode,
        AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *io_candidates)
{
  unsigned __int64 m_uLength; // rsi
  __int64 v6; // rcx
  AkDecisionTree::Node **v7; // rdx
  unsigned __int16 uWeight; // ax

  m_uLength = io_candidates->m_uLength;
  if ( (m_uLength < io_candidates->m_ulReserved
     || AkArray<MapStruct<unsigned long,unsigned long>,MapStruct<unsigned long,unsigned long> const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::GrowArray(
          io_candidates,
          4u))
    && m_uLength < io_candidates->m_ulReserved )
  {
    v6 = io_candidates->m_uLength;
    v7 = (AkDecisionTree::Node **)&io_candidates->m_pItems[v6];
    io_candidates->m_uLength = v6 + 1;
    if ( v7 )
    {
      *v7 = pNode;
      uWeight = pNode->uWeight;
      if ( uWeight == 100 )
      {
        ++LODWORD(io_candidates[1].m_pItems);
      }
      else if ( !uWeight )
      {
        ++HIDWORD(io_candidates[1].m_pItems);
      }
      io_candidates[1].m_uLength += uWeight;
    }
  }
}

// File Line: 78
// RVA: 0xA53F00
AkDecisionTree::Node *__fastcall AkDecisionTree::ResolvePathWeighted(
        AkDecisionTree *this,
        unsigned int *in_pPath,
        unsigned int in_cPath,
        unsigned int in_idEvent,
        unsigned int in_idSequence,
        AkDecisionTree::WeightedDecisionInfo *out_decisionInfo)
{
  AkDecisionTree::Node *m_pNodes; // rdx
  AkDecisionTree::Node **m_pItems; // r9
  AkDecisionTree::Node *v10; // rbx
  unsigned int v12; // eax
  unsigned int m_uLength; // r11d
  unsigned int uCount100; // r10d
  AkDecisionTree::Node **v15; // r8
  unsigned int v16; // edx
  AkDecisionTree::Node **v17; // rax
  unsigned int v19; // eax
  unsigned int v20; // r11d
  AkDecisionTree::Node **v21; // r10
  unsigned int v22; // edx
  AkDecisionTree::Node **v23; // rax
  unsigned int uWeight; // r8d
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int v27; // r11d
  unsigned int uCount0; // r10d
  AkDecisionTree::Node **v29; // r8
  unsigned int v30; // edx
  AkDecisionTree::Node **v31; // rax
  AkDecisionTree::WeightedCandidates io_candidates; // [rsp+30h] [rbp-28h] BYREF

  m_pNodes = this->m_pNodes;
  memset(&io_candidates, 0, 28);
  AkDecisionTree::_ResolvePathWeighted(this, m_pNodes, in_pPath, in_cPath, &io_candidates);
  if ( !io_candidates.nodes.m_uLength )
  {
    m_pItems = io_candidates.nodes.m_pItems;
    out_decisionInfo->uWeightedDecisionType = 4;
LABEL_3:
    v10 = 0i64;
    goto LABEL_4;
  }
  if ( io_candidates.uCount100 )
  {
    v12 = rand();
    m_pItems = io_candidates.nodes.m_pItems;
    m_uLength = io_candidates.nodes.m_uLength;
    uCount100 = io_candidates.uCount100;
    v15 = &io_candidates.nodes.m_pItems[io_candidates.nodes.m_uLength];
    v16 = v12 % io_candidates.uCount100;
    v17 = io_candidates.nodes.m_pItems;
    if ( io_candidates.nodes.m_pItems == v15 )
      goto LABEL_3;
    while ( (*v17)->uWeight != 100 || v16-- )
    {
      if ( ++v17 == v15 )
        goto LABEL_3;
    }
    out_decisionInfo->uWeightedDecisionType = 1;
    out_decisionInfo->uWeightedPossibleCount = uCount100;
    out_decisionInfo->uWeightedTotalCount = m_uLength;
    v10 = *v17;
  }
  else if ( io_candidates.nodes.m_uLength <= io_candidates.uCount0 )
  {
    v26 = rand();
    m_pItems = io_candidates.nodes.m_pItems;
    v27 = io_candidates.nodes.m_uLength;
    uCount0 = io_candidates.uCount0;
    v29 = &io_candidates.nodes.m_pItems[io_candidates.nodes.m_uLength];
    v30 = v26 % io_candidates.uCount0;
    v31 = io_candidates.nodes.m_pItems;
    if ( io_candidates.nodes.m_pItems == v29 )
      goto LABEL_3;
    while ( (*v31)->uWeight || v30-- )
    {
      if ( ++v31 == v29 )
        goto LABEL_3;
    }
    out_decisionInfo->uWeightedDecisionType = 3;
    out_decisionInfo->uWeightedPossibleCount = uCount0;
    out_decisionInfo->uWeightedTotalCount = v27;
    v10 = *v31;
  }
  else
  {
    v19 = rand();
    m_pItems = io_candidates.nodes.m_pItems;
    v20 = io_candidates.nodes.m_uLength;
    v21 = &io_candidates.nodes.m_pItems[io_candidates.nodes.m_uLength];
    v22 = v19 % io_candidates.uTotalWeight;
    v23 = io_candidates.nodes.m_pItems;
    if ( io_candidates.nodes.m_pItems == v21 )
      goto LABEL_3;
    while ( 1 )
    {
      uWeight = (*v23)->uWeight;
      if ( v22 < uWeight )
        break;
      ++v23;
      v22 -= uWeight;
      if ( v23 == v21 )
        goto LABEL_3;
    }
    v25 = io_candidates.nodes.m_uLength - io_candidates.uCount0;
    out_decisionInfo->uWeightedDecisionType = 2;
    out_decisionInfo->uWeightedTotalCount = v20;
    out_decisionInfo->uWeightedPossibleCount = v25;
    v10 = *v23;
  }
LABEL_4:
  if ( m_pItems )
  {
    io_candidates.nodes.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
  }
  return v10;
}

// File Line: 145
// RVA: 0xA54300
void __fastcall AkDecisionTree::_ResolvePathWeighted(
        AkDecisionTree *this,
        AkDecisionTree::Node *in_pRootNode,
        unsigned int *in_pPath,
        unsigned int in_cPath,
        AkDecisionTree::WeightedCandidates *io_candidates)
{
  AkDecisionTree::Node *m_pNodes; // r10
  int v10; // r8d
  int v11; // r9d
  AkDecisionTree::Node *v12; // rbx
  unsigned int v13; // r10d
  int v14; // eax
  unsigned int key; // ecx
  AkDecisionTree::Node *v16; // rdx

  m_pNodes = this->m_pNodes;
  if ( !m_pNodes )
    return;
  do
  {
    v10 = 0;
    v11 = in_pRootNode->children.uCount - 1;
    v12 = &m_pNodes[in_pRootNode->children.uIdx];
    v13 = *in_pPath;
    while ( 1 )
    {
      v14 = v10 + (v11 - v10) / 2;
      key = v12[v14].key;
      if ( key <= v13 )
        break;
      v11 = v14 - 1;
LABEL_7:
      if ( v10 > v11 )
        goto LABEL_13;
    }
    if ( key < v13 )
    {
      v10 = v14 + 1;
      goto LABEL_7;
    }
    v16 = &v12[v14];
    if ( v16 )
    {
      if ( in_cPath == 1 )
        AkDecisionTree::AddCandidate(
          this,
          v16,
          (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)io_candidates);
      else
        AkDecisionTree::_ResolvePathWeighted(this, v16, in_pPath + 1, in_cPath - 1, io_candidates);
    }
LABEL_13:
    if ( v12->key || !*in_pPath )
      break;
    if ( in_cPath == 1 )
    {
      AkDecisionTree::AddCandidate(
        this,
        v12,
        (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)io_candidates);
      return;
    }
    m_pNodes = this->m_pNodes;
    --in_cPath;
    ++in_pPath;
    in_pRootNode = v12;
  }
  while ( m_pNodes );
}

// File Line: 184
// RVA: 0xA53E20
__int64 __fastcall AkDecisionTree::ResolvePath(
        AkDecisionTree *this,
        unsigned int in_idEvent,
        unsigned int *in_pPath,
        unsigned int in_cPath,
        unsigned int in_idSequence)
{
  __int64 result; // rax
  AkDecisionTree::Node *m_pNodes; // rdi
  AkDecisionTree::Node *v8; // rax
  bool v9; // si
  AkDecisionTree::WeightedDecisionInfo out_decisionInfo; // [rsp+30h] [rbp-18h] BYREF

  if ( in_cPath != this->m_uDepth )
    return 0i64;
  if ( in_cPath )
  {
    if ( this->m_uMode )
      v8 = AkDecisionTree::ResolvePathWeighted(this, in_pPath, in_cPath, in_idEvent, in_idSequence, &out_decisionInfo);
    else
      v8 = AkDecisionTree::_ResolvePath(this, this->m_pNodes, in_pPath, in_cPath);
    m_pNodes = v8;
  }
  else
  {
    m_pNodes = this->m_pNodes;
  }
  v9 = 0;
  if ( m_pNodes )
  {
    if ( this->m_uProbability < 0x64u || m_pNodes->uProbability < 0x64u )
      v9 = (unsigned __int16)(this->m_uProbability * m_pNodes->uProbability) <= (unsigned __int16)(int)((double)rand() * 0.00003051850947599719 * 10000.0);
    result = m_pNodes->audioNodeID;
  }
  else
  {
    result = 0i64;
  }
  if ( v9 )
    return 0i64;
  return result;
}

// File Line: 237
// RVA: 0xA54200
AkDecisionTree::Node *__fastcall AkDecisionTree::_ResolvePath(
        AkDecisionTree *this,
        AkDecisionTree::Node *in_pRootNode,
        unsigned int *in_pPath,
        unsigned int in_cPath)
{
  AkDecisionTree::Node *m_pNodes; // r9
  unsigned int v7; // edi
  AkDecisionTree::Node *v8; // rbx
  int v9; // r10d
  int v10; // r11d
  int v11; // edx
  unsigned int key; // eax
  AkDecisionTree *v13; // rdi
  AkDecisionTree::Node *result; // rax
  AkDecisionTree::Node *v15; // rdx

  m_pNodes = this->m_pNodes;
  if ( !m_pNodes )
    return 0i64;
  v7 = *in_pPath;
  v8 = &m_pNodes[in_pRootNode->children.uIdx];
  v9 = 0;
  v10 = in_pRootNode->children.uCount - 1;
  while ( 1 )
  {
    v11 = v9 + (v10 - v9) / 2;
    key = v8[v11].key;
    if ( key <= v7 )
      break;
    v10 = v11 - 1;
LABEL_7:
    if ( v9 > v10 )
      goto LABEL_8;
  }
  if ( key < v7 )
  {
    v9 = v11 + 1;
    goto LABEL_7;
  }
  v15 = &v8[v11];
  if ( !v15 )
  {
LABEL_8:
    v13 = this;
    goto LABEL_9;
  }
  if ( in_cPath == 1 )
    return v15;
  v13 = this;
  result = AkDecisionTree::_ResolvePath(this, v15, in_pPath + 1, in_cPath - 1);
  if ( result )
    return result;
LABEL_9:
  if ( !v8->key && *in_pPath )
  {
    if ( in_cPath == 1 )
      return v8;
    result = AkDecisionTree::_ResolvePath(v13, v8, in_pPath + 1, in_cPath - 1);
    if ( result )
      return result;
  }
  return 0i64;
}

// File Line: 297
// RVA: 0xA53CB0
char __fastcall AkDecisionTree::GetSwitchNodeAssoc(
        AkDecisionTree *this,
        CAkKeyArray<unsigned long,unsigned long,8> *out_switchNodeAssoc)
{
  AkDecisionTree *v3; // rdx
  AkDecisionTree::Node *m_pNodes; // rax
  __int64 v6; // r14
  __int64 i; // r13
  AkDecisionTree::Node *v8; // rax
  unsigned __int64 m_uLength; // r15
  unsigned int audioNodeID; // r12d
  unsigned int key; // esi
  MapStruct<unsigned long,unsigned long> *m_pItems; // rax
  MapStruct<unsigned long,unsigned long> *v13; // rcx
  unsigned int *p_item; // rax
  unsigned __int64 m_ulReserved; // rax
  unsigned int v16; // ebp
  MapStruct<unsigned long,unsigned long> *v17; // rdi
  unsigned __int64 v18; // r8
  unsigned __int64 v19; // rdx
  __int64 v20; // rcx
  MapStruct<unsigned long,unsigned long> *v21; // rdx

  v3 = this;
  if ( this->m_uDepth != 1 )
    return 0;
  m_pNodes = this->m_pNodes;
  if ( m_pNodes->children.uCount )
  {
    v6 = 0i64;
    for ( i = m_pNodes->children.uCount; i; --i )
    {
      v8 = v3->m_pNodes;
      m_uLength = out_switchNodeAssoc->m_uLength;
      audioNodeID = v8[v6].audioNodeID;
      key = v8[v6].key;
      m_pItems = out_switchNodeAssoc->m_pItems;
      v13 = &out_switchNodeAssoc->m_pItems[m_uLength];
      if ( out_switchNodeAssoc->m_pItems == v13 )
        goto LABEL_11;
      do
      {
        if ( m_pItems->key == key )
          break;
        ++m_pItems;
      }
      while ( m_pItems != v13 );
      if ( m_pItems == v13 || (p_item = &m_pItems->item) == 0i64 )
      {
LABEL_11:
        m_ulReserved = out_switchNodeAssoc->m_ulReserved;
        if ( m_uLength < m_ulReserved )
          goto LABEL_18;
        v16 = m_ulReserved + 8;
        v17 = (MapStruct<unsigned long,unsigned long> *)AK::MemoryMgr::Malloc(
                                                          g_DefaultPoolId,
                                                          8i64 * (unsigned int)(m_ulReserved + 8));
        if ( v17 )
        {
          v18 = out_switchNodeAssoc->m_uLength;
          if ( out_switchNodeAssoc->m_pItems )
          {
            v19 = 0i64;
            if ( out_switchNodeAssoc->m_uLength )
            {
              do
              {
                ++v19;
                v17[v19 - 1] = out_switchNodeAssoc->m_pItems[v19 - 1];
              }
              while ( v19 < v18 );
            }
            AK::MemoryMgr::Free(g_DefaultPoolId, out_switchNodeAssoc->m_pItems);
          }
          out_switchNodeAssoc->m_pItems = v17;
          out_switchNodeAssoc->m_ulReserved = v16;
LABEL_18:
          if ( m_uLength < out_switchNodeAssoc->m_ulReserved )
          {
            v20 = out_switchNodeAssoc->m_uLength;
            v21 = &out_switchNodeAssoc->m_pItems[v20];
            out_switchNodeAssoc->m_uLength = v20 + 1;
            if ( v21 )
            {
              v21->key = key;
              v21->item = audioNodeID;
            }
          }
        }
      }
      else
      {
        *p_item = audioNodeID;
      }
      v3 = this;
      ++v6;
    }
  }
  return 1;
}

// File Line: 311
// RVA: 0xA53C70
__int64 __fastcall AkDecisionTree::GetAudioNodeForState(AkDecisionTree *this, unsigned int in_stateID)
{
  AkDecisionTree::Node *m_pNodes; // r9
  __int64 v3; // rax
  AkDecisionTree::Node *i; // rcx

  if ( this->m_uDepth != 1 )
    return 0i64;
  m_pNodes = this->m_pNodes;
  v3 = 0i64;
  if ( !m_pNodes->children.uCount )
    return 0i64;
  for ( i = this->m_pNodes; in_stateID != i->key; ++i )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= m_pNodes->children.uCount )
      return 0i64;
  }
  return m_pNodes[v3].audioNodeID;
}

