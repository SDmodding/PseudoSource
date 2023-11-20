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
  AkDecisionTree::Node *v1; // rdx

  v1 = this->m_pNodes;
  if ( v1 )
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
}

// File Line: 38
// RVA: 0xA54170
signed __int64 __fastcall AkDecisionTree::SetTree(AkDecisionTree *this, void *in_pData, unsigned int in_uSize, unsigned int in_uDepth)
{
  void *v4; // rbp
  AkDecisionTree::Node *v5; // rdx
  unsigned int v6; // esi
  unsigned __int64 v7; // rdi
  AkDecisionTree *v8; // rbx
  AkDecisionTree::Node *v9; // rax

  v4 = in_pData;
  v5 = this->m_pNodes;
  v6 = in_uDepth;
  v7 = in_uSize;
  v8 = this;
  if ( v5 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v5);
    v8->m_pNodes = 0i64;
  }
  if ( (_DWORD)v7 )
  {
    v9 = (AkDecisionTree::Node *)AK::MemoryMgr::Malloc(g_DefaultPoolId, v7);
    v8->m_pNodes = v9;
    if ( !v9 )
      return 52i64;
    memmove(v9, v4, v7);
  }
  v8->m_uDepth = v6;
  return 1i64;
}

// File Line: 60
// RVA: 0xA53BF0
void __fastcall AkDecisionTree::AddCandidate(AkDecisionTree *this, AkDecisionTree::Node *pNode, AkDecisionTree::WeightedCandidates *io_candidates)
{
  unsigned __int64 v3; // rsi
  AkDecisionTree::WeightedCandidates *v4; // rbx
  AkDecisionTree::Node *v5; // rdi
  __int64 v6; // rcx
  AkDecisionTree::Node **v7; // rdx
  unsigned __int16 v8; // ax

  v3 = io_candidates->nodes.m_uLength;
  v4 = io_candidates;
  v5 = pNode;
  if ( (v3 < io_candidates->nodes.m_ulReserved
     || AkArray<MapStruct<unsigned long,unsigned long>,MapStruct<unsigned long,unsigned long> const &,ArrayPoolDefault,8,AkArrayAllocatorDefault>::GrowArray(
          (AkArray<CAkRSNode *,CAkRSNode *,ArrayPoolDefault,8,AkArrayAllocatorDefault> *)io_candidates,
          4u))
    && v3 < v4->nodes.m_ulReserved )
  {
    v6 = v4->nodes.m_uLength;
    v7 = &v4->nodes.m_pItems[v6];
    v4->nodes.m_uLength = v6 + 1;
    if ( v7 )
    {
      *v7 = v5;
      v8 = v5->uWeight;
      if ( v8 == 100 )
      {
        ++v4->uCount100;
      }
      else if ( !v8 )
      {
        ++v4->uCount0;
      }
      v4->uTotalWeight += v8;
    }
  }
}

// File Line: 78
// RVA: 0xA53F00
AkDecisionTree::Node *__fastcall AkDecisionTree::ResolvePathWeighted(AkDecisionTree *this, unsigned int *in_pPath, unsigned int in_cPath, unsigned int in_idEvent, unsigned int in_idSequence, AkDecisionTree::WeightedDecisionInfo *out_decisionInfo)
{
  unsigned int v6; // er9
  unsigned int *v7; // r8
  AkDecisionTree::Node *v8; // rdx
  AkDecisionTree::Node **v9; // r9
  AkDecisionTree::Node *v10; // rbx
  unsigned int v12; // eax
  unsigned int v13; // er11
  unsigned int v14; // er10
  AkDecisionTree::Node **v15; // r8
  unsigned int v16; // edx
  AkDecisionTree::Node **v17; // rax
  unsigned int v18; // ecx
  unsigned int v19; // eax
  unsigned int v20; // er11
  AkDecisionTree::Node **v21; // r10
  unsigned int v22; // edx
  AkDecisionTree::Node **v23; // rax
  unsigned int v24; // er8
  unsigned int v25; // ecx
  unsigned int v26; // eax
  unsigned int v27; // er11
  unsigned int v28; // er10
  AkDecisionTree::Node **v29; // r8
  unsigned int v30; // edx
  AkDecisionTree::Node **v31; // rax
  unsigned int v32; // ecx
  AkDecisionTree::WeightedCandidates io_candidates; // [rsp+30h] [rbp-28h]

  v6 = in_cPath;
  v7 = in_pPath;
  v8 = this->m_pNodes;
  io_candidates.nodes.m_pItems = 0i64;
  *(_QWORD *)&io_candidates.nodes.m_uLength = 0i64;
  *(_QWORD *)&io_candidates.uCount100 = 0i64;
  io_candidates.uTotalWeight = 0;
  AkDecisionTree::_ResolvePathWeighted(this, v8, v7, v6, &io_candidates);
  if ( !io_candidates.nodes.m_uLength )
  {
    v9 = io_candidates.nodes.m_pItems;
    out_decisionInfo->uWeightedDecisionType = 4;
LABEL_3:
    v10 = 0i64;
    goto LABEL_4;
  }
  if ( io_candidates.uCount100 )
  {
    v12 = rand();
    v9 = io_candidates.nodes.m_pItems;
    v13 = io_candidates.nodes.m_uLength;
    v14 = io_candidates.uCount100;
    v15 = &io_candidates.nodes.m_pItems[io_candidates.nodes.m_uLength];
    v16 = v12 % io_candidates.uCount100;
    v17 = io_candidates.nodes.m_pItems;
    if ( io_candidates.nodes.m_pItems == v15 )
      goto LABEL_3;
    while ( 1 )
    {
      if ( (*v17)->uWeight == 100 )
      {
        v18 = v16--;
        if ( !v18 )
          break;
      }
      ++v17;
      if ( v17 == v15 )
        goto LABEL_3;
    }
    out_decisionInfo->uWeightedDecisionType = 1;
    out_decisionInfo->uWeightedPossibleCount = v14;
    out_decisionInfo->uWeightedTotalCount = v13;
    v10 = *v17;
  }
  else if ( io_candidates.nodes.m_uLength <= io_candidates.uCount0 )
  {
    v26 = rand();
    v9 = io_candidates.nodes.m_pItems;
    v27 = io_candidates.nodes.m_uLength;
    v28 = io_candidates.uCount0;
    v29 = &io_candidates.nodes.m_pItems[io_candidates.nodes.m_uLength];
    v30 = v26 % io_candidates.uCount0;
    v31 = io_candidates.nodes.m_pItems;
    if ( io_candidates.nodes.m_pItems == v29 )
      goto LABEL_3;
    while ( 1 )
    {
      if ( !(*v31)->uWeight )
      {
        v32 = v30--;
        if ( !v32 )
          break;
      }
      ++v31;
      if ( v31 == v29 )
        goto LABEL_3;
    }
    out_decisionInfo->uWeightedDecisionType = 3;
    out_decisionInfo->uWeightedPossibleCount = v28;
    out_decisionInfo->uWeightedTotalCount = v27;
    v10 = *v31;
  }
  else
  {
    v19 = rand();
    v9 = io_candidates.nodes.m_pItems;
    v20 = io_candidates.nodes.m_uLength;
    v21 = &io_candidates.nodes.m_pItems[io_candidates.nodes.m_uLength];
    v22 = v19 % io_candidates.uTotalWeight;
    v23 = io_candidates.nodes.m_pItems;
    if ( io_candidates.nodes.m_pItems == v21 )
      goto LABEL_3;
    while ( 1 )
    {
      v24 = (*v23)->uWeight;
      if ( v22 < v24 )
        break;
      ++v23;
      v22 -= v24;
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
  if ( v9 )
  {
    io_candidates.nodes.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v9);
  }
  return v10;
}ABEL_4:
  if ( v9 )
  {
    io_candidates.nodes.m_uLength = 0;
    AK::MemoryMgr::Free(g_D

// File Line: 145
// RVA: 0xA54300
void __fastcall AkDecisionTree::_ResolvePathWeighted(AkDecisionTree *this, AkDecisionTree::Node *in_pRootNode, unsigned int *in_pPath, unsigned int in_cPath, AkDecisionTree::WeightedCandidates *io_candidates)
{
  AkDecisionTree::Node *v5; // r10
  unsigned int v6; // edi
  unsigned int *v7; // rsi
  AkDecisionTree::Node *v8; // r11
  AkDecisionTree *v9; // rbp
  int v10; // er8
  int v11; // er9
  AkDecisionTree::Node *v12; // rbx
  unsigned int v13; // er10
  int v14; // eax
  unsigned int v15; // ecx
  AkDecisionTree::Node *v16; // rdx

  v5 = this->m_pNodes;
  v6 = in_cPath;
  v7 = in_pPath;
  v8 = in_pRootNode;
  v9 = this;
  if ( !v5 )
    return;
  do
  {
    v10 = 0;
    v11 = v8->children.uCount - 1;
    v12 = &v5[v8->children.uIdx];
    v13 = *v7;
    while ( 1 )
    {
      v14 = v10 + (v11 - v10) / 2;
      v15 = v12[v14].key;
      if ( v15 <= v13 )
        break;
      v11 = v14 - 1;
LABEL_7:
      if ( v10 > v11 )
        goto LABEL_13;
    }
    if ( v15 < v13 )
    {
      v10 = v14 + 1;
      goto LABEL_7;
    }
    v16 = &v12[v14];
    if ( v16 )
    {
      if ( v6 == 1 )
        AkDecisionTree::AddCandidate(v9, v16, io_candidates);
      else
        AkDecisionTree::_ResolvePathWeighted(v9, v16, v7 + 1, v6 - 1, io_candidates);
    }
LABEL_13:
    if ( v12->key || !*v7 )
      break;
    if ( v6 == 1 )
    {
      AkDecisionTree::AddCandidate(v9, v12, io_candidates);
      return;
    }
    v5 = v9->m_pNodes;
    --v6;
    ++v7;
    v8 = v12;
  }
  while ( v5 );
}

// File Line: 184
// RVA: 0xA53E20
__int64 __fastcall AkDecisionTree::ResolvePath(AkDecisionTree *this, unsigned int in_idEvent, unsigned int *in_pPath, unsigned int in_cPath, unsigned int in_idSequence)
{
  AkDecisionTree *v5; // rbx
  __int64 result; // rax
  AkDecisionTree::Node *v7; // rdi
  AkDecisionTree::Node *v8; // rax
  char v9; // si
  AkDecisionTree::WeightedDecisionInfo out_decisionInfo; // [rsp+30h] [rbp-18h]

  v5 = this;
  if ( in_cPath != this->m_uDepth )
    return 0i64;
  if ( in_cPath )
  {
    if ( this->m_uMode )
      v8 = AkDecisionTree::ResolvePathWeighted(this, in_pPath, in_cPath, in_idEvent, in_idSequence, &out_decisionInfo);
    else
      v8 = AkDecisionTree::_ResolvePath(this, this->m_pNodes, in_pPath, in_cPath);
    v7 = v8;
  }
  else
  {
    v7 = this->m_pNodes;
  }
  v9 = 0;
  if ( v7 )
  {
    if ( v5->m_uProbability < 0x64u || v7->uProbability < 0x64u )
    {
      v9 = 0;
      if ( (unsigned __int16)(v5->m_uProbability * v7->uProbability) <= (unsigned __int16)(signed int)((double)rand() * 0.00003051850947599719 * 10000.0) )
        v9 = 1;
    }
    result = v7->audioNodeID;
  }
  else
  {
    result = 0i64;
  }
  if ( v9 )
    result = 0i64;
  return result;
}

// File Line: 237
// RVA: 0xA54200
AkDecisionTree::Node *__fastcall AkDecisionTree::_ResolvePath(AkDecisionTree *this, AkDecisionTree::Node *in_pRootNode, unsigned int *in_pPath, unsigned int in_cPath)
{
  unsigned int v4; // esi
  AkDecisionTree::Node *v5; // r9
  unsigned int *v6; // rbp
  unsigned int v7; // edi
  AkDecisionTree::Node *v8; // rbx
  int v9; // er10
  int v10; // er11
  int v11; // edx
  unsigned int v12; // eax
  AkDecisionTree *v13; // rdi
  AkDecisionTree::Node *result; // rax
  AkDecisionTree::Node *v15; // rdx

  v4 = in_cPath;
  v5 = this->m_pNodes;
  v6 = in_pPath;
  if ( !v5 )
    return 0i64;
  v7 = *in_pPath;
  v8 = &v5[in_pRootNode->children.uIdx];
  v9 = 0;
  v10 = in_pRootNode->children.uCount - 1;
  while ( 1 )
  {
    v11 = v9 + (v10 - v9) / 2;
    v12 = v8[v11].key;
    if ( v12 <= v7 )
      break;
    v10 = v11 - 1;
LABEL_7:
    if ( v9 > v10 )
      goto LABEL_8;
  }
  if ( v12 < v7 )
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
  if ( v4 == 1 )
    return v15;
  v13 = this;
  result = AkDecisionTree::_ResolvePath(this, v15, in_pPath + 1, v4 - 1);
  if ( result )
    return result;
LABEL_9:
  if ( !v8->key && *v6 )
  {
    if ( v4 == 1 )
      return v8;
    result = AkDecisionTree::_ResolvePath(v13, v8, v6 + 1, v4 - 1);
    if ( result )
      return result;
  }
  return 0i64;
}

// File Line: 297
// RVA: 0xA53CB0
char __fastcall AkDecisionTree::GetSwitchNodeAssoc(AkDecisionTree *this, CAkKeyArray<unsigned long,unsigned long,8> *out_switchNodeAssoc)
{
  CAkKeyArray<unsigned long,unsigned long,8> *v2; // rbx
  AkDecisionTree *v3; // rdx
  AkDecisionTree::Node *v5; // rax
  __int64 v6; // r14
  __int64 v7; // r13
  AkDecisionTree::Node *v8; // rax
  unsigned __int64 v9; // r15
  unsigned int v10; // er12
  unsigned int v11; // esi
  MapStruct<unsigned long,unsigned long> *v12; // rax
  signed __int64 v13; // rcx
  unsigned int *v14; // rax
  unsigned __int64 v15; // rax
  unsigned int v16; // ebp
  MapStruct<unsigned long,unsigned long> *v17; // rdi
  unsigned __int64 v18; // r8
  unsigned __int64 v19; // rdx
  __int64 v20; // rcx
  MapStruct<unsigned long,unsigned long> *v21; // rdx
  AkDecisionTree *v22; // [rsp+50h] [rbp+8h]

  v22 = this;
  v2 = out_switchNodeAssoc;
  v3 = this;
  if ( this->m_uDepth != 1 )
    return 0;
  v5 = this->m_pNodes;
  if ( v5->children.uCount )
  {
    v6 = 0i64;
    v7 = v5->children.uCount;
    do
    {
      v8 = v3->m_pNodes;
      v9 = v2->m_uLength;
      v10 = v8[v6].audioNodeID;
      v11 = v8[v6].key;
      v12 = v2->m_pItems;
      v13 = (signed __int64)&v2->m_pItems[v9];
      if ( v2->m_pItems == (MapStruct<unsigned long,unsigned long> *)v13 )
        goto LABEL_25;
      do
      {
        if ( v12->key == v11 )
          break;
        ++v12;
      }
      while ( v12 != (MapStruct<unsigned long,unsigned long> *)v13 );
      if ( v12 != (MapStruct<unsigned long,unsigned long> *)v13 && (v14 = &v12->item) != 0i64 )
      {
        *v14 = v10;
      }
      else
      {
LABEL_25:
        v15 = v2->m_ulReserved;
        if ( v9 < v15 )
          goto LABEL_18;
        v16 = v15 + 8;
        v17 = (MapStruct<unsigned long,unsigned long> *)AK::MemoryMgr::Malloc(
                                                          g_DefaultPoolId,
                                                          8i64 * (unsigned int)(v15 + 8));
        if ( v17 )
        {
          v18 = v2->m_uLength;
          if ( v2->m_pItems )
          {
            v19 = 0i64;
            if ( v2->m_uLength )
            {
              do
              {
                ++v19;
                v17[v19 - 1] = v2->m_pItems[v19 - 1];
              }
              while ( v19 < v18 );
            }
            AK::MemoryMgr::Free(g_DefaultPoolId, v2->m_pItems);
          }
          v2->m_pItems = v17;
          v2->m_ulReserved = v16;
LABEL_18:
          if ( v9 < v2->m_ulReserved )
          {
            v20 = v2->m_uLength;
            v21 = &v2->m_pItems[v20];
            v2->m_uLength = v20 + 1;
            if ( v21 )
            {
              v21->key = v11;
              v21->item = v10;
            }
          }
          goto LABEL_21;
        }
      }
LABEL_21:
      v3 = v22;
      ++v6;
      --v7;
    }
    while ( v7 );
  }
  return 1;
}

// File Line: 311
// RVA: 0xA53C70
__int64 __fastcall AkDecisionTree::GetAudioNodeForState(AkDecisionTree *this, unsigned int in_stateID)
{
  AkDecisionTree::Node *v2; // r9
  __int64 v3; // rax
  AkDecisionTree::Node *v4; // rcx

  if ( this->m_uDepth != 1 )
    return 0i64;
  v2 = this->m_pNodes;
  v3 = 0i64;
  if ( !v2->children.uCount )
    return 0i64;
  v4 = this->m_pNodes;
  while ( in_stateID != v4->key )
  {
    v3 = (unsigned int)(v3 + 1);
    ++v4;
    if ( (unsigned int)v3 >= v2->children.uCount )
      return 0i64;
  }
  return v2[v3].audioNodeID;
}

