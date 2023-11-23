// File Line: 19
// RVA: 0x66BCB0
void __fastcall UFG::WayTraversalSearch::WayTraversalSearch(
        UFG::WayTraversalSearch *this,
        UFG::WayTraversal *finder,
        UFG::WayTraversalClient *client,
        UFG::qVector3 *source_position,
        UFG::qVector3 *closest_position,
        float goal_min_radius,
        float goal_max_radius)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  UFG::WayGraph *pWayGraph; // r14
  unsigned __int16 v14; // [rsp+58h] [rbp+10h] BYREF
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *p_lClosed; // [rsp+60h] [rbp+18h]

  this->mPrev = &this->UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch>;
  this->mNext = &this->UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch>;
  this->vfptr = (UFG::WayTraversalSearchVtbl *)&UFG::WayTraversalSearch::`vftable;
  this->lOpen.mNode.mPrev = &this->lOpen.mNode;
  this->lOpen.mNode.mNext = &this->lOpen.mNode;
  p_lClosed = &this->lClosed;
  this->lClosed.mNode.mPrev = &this->lClosed.mNode;
  this->lClosed.mNode.mNext = &this->lClosed.mNode;
  this->pFinder = finder;
  this->pClient = client;
  y = source_position->y;
  z = source_position->z;
  this->vSourcePosition.x = source_position->x;
  this->vSourcePosition.y = y;
  this->vSourcePosition.z = z;
  v11 = closest_position->y;
  v12 = closest_position->z;
  this->vClosestPosition.x = closest_position->x;
  this->vClosestPosition.y = v11;
  this->vClosestPosition.z = v12;
  this->fGoalMinRadius = goal_min_radius;
  this->fGoalMaxRadius = goal_max_radius;
  *(_QWORD *)&this->nCandidates = 0i64;
  *(_QWORD *)&this->nSteps = 0i64;
  this->nState = WAYSTAR_SEARCHING;
  pWayGraph = this->pFinder->pWayGraph;
  this->pClient->vfptr->ResetWay(this->pClient);
  v14 = -1;
  if ( ((unsigned __int8 (__fastcall *)(UFG::WayGraph *, UFG::WayTraversalClient *, UFG::qVector3 *, unsigned __int16 *, __int64))pWayGraph->vfptr->GetEdge)(
         pWayGraph,
         client,
         &this->vClosestPosition,
         &v14,
         -2i64) )
  {
    UFG::WayTraversalSearch::AddFirstNode(this, pWayGraph, v14, 0);
    UFG::WayTraversalSearch::AddFirstNode(this, pWayGraph, v14, 1);
  }
}

// File Line: 48
// RVA: 0x66D980
void __fastcall UFG::WayTraversalSearch::~WayTraversalSearch(UFG::WayTraversalSearch *this)
{
  int v2; // r9d
  UFG::WayStarNode **pCandidates; // r8
  UFG::WayStarNode *v4; // rdx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *mPrev; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *mNext; // rax
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *p_lClosed; // r8
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v8; // rdx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v9; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v10; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v11; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v12; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v13; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v14; // rax
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *p_lOpen; // r8
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v16; // rdx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v17; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v18; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v19; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v20; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v21; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v22; // rax
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v23; // rcx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v24; // rax

  this->vfptr = (UFG::WayTraversalSearchVtbl *)&UFG::WayTraversalSearch::`vftable;
  v2 = 0;
  if ( this->nCandidates > 0 )
  {
    pCandidates = this->pCandidates;
    do
    {
      v4 = *pCandidates;
      if ( *pCandidates )
      {
        mPrev = v4->mPrev;
        mNext = v4->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        v4->mPrev = v4;
        v4->mNext = v4;
        v4->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayFinder::s_NodePool.mFreeListHead;
        UFG::WayFinder::s_NodePool.mFreeListHead = (char *)v4;
        --UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
        *pCandidates = 0i64;
      }
      ++v2;
      ++pCandidates;
    }
    while ( v2 < this->nCandidates );
  }
  this->nCandidates = 0;
  p_lClosed = &this->lClosed;
  v8 = this->lClosed.mNode.mNext;
  if ( v8 != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&this->lClosed )
  {
    do
    {
      v9 = v8->mPrev;
      v10 = v8->mNext;
      v9->mNext = v10;
      v10->mPrev = v9;
      v8->mPrev = v8;
      v8->mNext = v8;
      v11 = v8->mPrev;
      v12 = v8->mNext;
      v11->mNext = v12;
      v12->mPrev = v11;
      v8->mPrev = v8;
      v8->mNext = v8;
      v8->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayFinder::s_NodePool.mFreeListHead;
      UFG::WayFinder::s_NodePool.mFreeListHead = (char *)v8;
      --UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
      v8 = this->lClosed.mNode.mNext;
    }
    while ( v8 != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)p_lClosed );
  }
  v13 = p_lClosed->mNode.mPrev;
  v14 = this->lClosed.mNode.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_lClosed->mNode.mPrev = &p_lClosed->mNode;
  this->lClosed.mNode.mNext = &this->lClosed.mNode;
  p_lOpen = &this->lOpen;
  v16 = this->lOpen.mNode.mNext;
  if ( v16 != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&this->lOpen )
  {
    do
    {
      v17 = v16->mPrev;
      v18 = v16->mNext;
      v17->mNext = v18;
      v18->mPrev = v17;
      v16->mPrev = v16;
      v16->mNext = v16;
      v19 = v16->mPrev;
      v20 = v16->mNext;
      v19->mNext = v20;
      v20->mPrev = v19;
      v16->mPrev = v16;
      v16->mNext = v16;
      v16->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayFinder::s_NodePool.mFreeListHead;
      UFG::WayFinder::s_NodePool.mFreeListHead = (char *)v16;
      --UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
      v16 = this->lOpen.mNode.mNext;
    }
    while ( v16 != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)p_lOpen );
  }
  v21 = p_lOpen->mNode.mPrev;
  v22 = this->lOpen.mNode.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  p_lOpen->mNode.mPrev = &p_lOpen->mNode;
  this->lOpen.mNode.mNext = &this->lOpen.mNode;
  v23 = this->mPrev;
  v24 = this->mNext;
  v23->mNext = v24;
  v24->mPrev = v23;
  this->mPrev = &this->UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch>;
  this->mNext = &this->UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch>;
}

// File Line: 62
// RVA: 0x66F960
void __fastcall UFG::WayTraversalSearch::AddFirstNode(
        UFG::WayTraversalSearch *this,
        UFG::WayGraph *graph,
        unsigned __int16 current_edge,
        int index)
{
  __int64 v7; // rdi
  unsigned __int16 v8; // ax
  UFG::qVector3 *v9; // rax
  __m128 x_low; // xmm1
  unsigned int v11; // xmm6_4
  char *mFreeListHead; // rbx
  unsigned int v13; // eax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *mPrev; // rax
  char v15[24]; // [rsp+28h] [rbp-30h] BYREF

  v7 = graph->vfptr->GetEdgeNode(graph, current_edge, index);
  if ( graph->vfptr->IsEdge(graph, v7) )
  {
    v8 = graph->vfptr->GetEdgeNode(graph, current_edge, 1);
    v9 = graph->vfptr->GetEdgePosition(graph, v15, current_edge, (_WORD)v7 == v8);
  }
  else
  {
    v9 = graph->vfptr->GetNodePosition(graph, v15, (unsigned __int16)v7);
  }
  x_low = (__m128)LODWORD(this->vClosestPosition.x);
  x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - v9->x) * (float)(x_low.m128_f32[0] - v9->x))
                            + (float)((float)(this->vClosestPosition.y - v9->y)
                                    * (float)(this->vClosestPosition.y - v9->y)))
                    + (float)((float)(this->vClosestPosition.z - v9->z) * (float)(this->vClosestPosition.z - v9->z));
  v11 = _mm_sqrt_ps(x_low).m128_u32[0];
  mFreeListHead = UFG::WayFinder::s_NodePool.mFreeListHead;
  if ( UFG::WayFinder::s_NodePool.mFreeListHead )
  {
    UFG::WayFinder::s_NodePool.mFreeListHead = *(char **)UFG::WayFinder::s_NodePool.mFreeListHead;
    v13 = UFG::WayFinder::s_NodePool.mNumSlotsAllocated + 1;
    UFG::WayFinder::s_NodePool.mNumSlotsAllocated = v13;
    if ( UFG::WayFinder::s_NodePool.mMostSlotsAllocated <= v13 )
      UFG::WayFinder::s_NodePool.mMostSlotsAllocated = v13;
  }
  else
  {
    UFG::qFixedAllocator::ReportFull(&UFG::WayFinder::s_NodePool);
  }
  if ( mFreeListHead )
  {
    *(_QWORD *)mFreeListHead = mFreeListHead;
    *((_QWORD *)mFreeListHead + 1) = mFreeListHead;
    *((_WORD *)mFreeListHead + 8) = current_edge;
    *((_WORD *)mFreeListHead + 9) = v7;
    *((_QWORD *)mFreeListHead + 3) = 0i64;
    *((_DWORD *)mFreeListHead + 8) = 0;
    *((_DWORD *)mFreeListHead + 9) = v11;
  }
  mPrev = this->lOpen.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)mFreeListHead;
  *(_QWORD *)mFreeListHead = mPrev;
  *((_QWORD *)mFreeListHead + 1) = &this->lOpen;
  this->lOpen.mNode.mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)mFreeListHead;
}

// File Line: 143
// RVA: 0x66FE60
void __fastcall UFG::WayTraversalSearch::AddOpenNode(UFG::WayTraversalSearch *this, UFG::WayStarNode *to_add)
{
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *mNext; // r8
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *i; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *mPrev; // rax

  mNext = this->lOpen.mNode.mNext;
  for ( i = &this->lOpen; mNext != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)i; mNext = mNext->mNext )
  {
    if ( (float)(to_add->m_EstimatedCost + to_add->m_ActualCost) >= (float)(*((float *)&mNext[2].mPrev + 1)
                                                                          + *(float *)&mNext[2].mPrev) )
      break;
  }
  mPrev = mNext->mPrev;
  mPrev->mNext = to_add;
  to_add->mPrev = mPrev;
  to_add->mNext = mNext;
  mNext->mPrev = to_add;
}

// File Line: 152
// RVA: 0x689B80
float __fastcall UFG::WayTraversalSearch::Service(UFG::WayTraversalSearch *this, float time_limit_ms)
{
  unsigned __int64 Ticks; // rbx
  UFG::WayGraph *pWayGraph; // rsi
  int v6; // r12d
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *p_lOpen; // r15
  unsigned __int64 v8; // rax
  _QWORD *p_mPrev; // r14
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *mPrev; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *mNext; // rax
  unsigned __int16 v12; // r13
  bool v13; // zf
  UFG::WayGraphVtbl *vfptr; // rax
  UFG::WayStarNode *v15; // rdi
  float v16; // xmm1_4
  UFG::WayStarNode *mFreeListHead; // rbx
  unsigned int v18; // eax
  float v19; // xmm1_4
  float v20; // xmm0_4
  unsigned __int16 v21; // cx
  unsigned __int16 v22; // ax
  bool v23; // dl
  signed int v24; // ebx
  int v25; // eax
  unsigned __int16 v26; // di
  unsigned __int16 v27; // bx
  unsigned __int16 v28; // ax
  unsigned __int16 v29; // cx
  bool v30; // di
  float v31; // xmm6_4
  double v32; // xmm0_8
  float v33; // xmm7_4
  unsigned __int16 v34; // di
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *i; // r8
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *j; // rdx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v37; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v38; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v39; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v40; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v41; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v42; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v43; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v44; // rax
  UFG::WayGraphVtbl *v45; // rax
  float *v46; // rax
  float v47; // xmm0_4
  __m128 x_low; // xmm1
  unsigned int v49; // xmm6_4
  char *v50; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v51; // rcx
  UFG::WayStarNode *v52; // rbx
  unsigned int v53; // eax
  float v54; // xmm1_4
  float v55; // xmm0_4
  unsigned __int16 v56; // cx
  unsigned __int16 v57; // ax
  bool v58; // cc
  UFG::WayStarSearchState v59; // eax
  unsigned __int16 *aWayNodes; // rcx
  UFG::WayStarNode **pCandidates; // r8
  UFG::WayStarNode *v62; // rdx
  UFG::WayStarNode *m_ParentNode; // rax
  unsigned __int16 m_WayNode; // ax
  unsigned __int64 v65; // rax
  float result; // xmm0_4
  int v67; // [rsp+20h] [rbp-D8h]
  BOOL v68; // [rsp+30h] [rbp-C8h]
  unsigned __int64 v69; // [rsp+38h] [rbp-C0h]
  UFG::qVector3 v70; // [rsp+50h] [rbp-A8h] BYREF
  UFG::qVector3 v71; // [rsp+5Ch] [rbp-9Ch] BYREF
  UFG::qVector3 v72; // [rsp+68h] [rbp-90h] BYREF
  char v73; // [rsp+74h] [rbp-84h] BYREF
  bool v74; // [rsp+100h] [rbp+8h]
  unsigned __int16 v75; // [rsp+110h] [rbp+18h]
  int v76; // [rsp+118h] [rbp+20h]

  ++this->nServices;
  Ticks = UFG::qGetTicks();
  v69 = Ticks;
  pWayGraph = this->pFinder->pWayGraph;
  v6 = 0;
  if ( this->nState == WAYSTAR_SEARCHING )
  {
    p_lOpen = &this->lOpen;
    do
    {
      if ( (UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *)this->lOpen.mNode.mNext == &this->lOpen )
        break;
      if ( time_limit_ms > 0.0 )
      {
        v8 = UFG::qGetTicks();
        if ( UFG::qGetTickTime(Ticks, v8) > time_limit_ms )
          break;
      }
      ++this->nSteps;
      p_mPrev = &p_lOpen->mNode.mPrev->mPrev;
      mPrev = p_lOpen->mNode.mPrev->mPrev;
      mNext = p_lOpen->mNode.mPrev->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      *p_mPrev = p_mPrev;
      p_mPrev[1] = p_mPrev;
      v12 = *((_WORD *)p_mPrev + 9);
      v75 = *((_WORD *)p_mPrev + 8);
      pWayGraph->vfptr->IsEdge(pWayGraph, v12);
      v13 = !pWayGraph->vfptr->IsEdge(pWayGraph, v12);
      vfptr = pWayGraph->vfptr;
      if ( v13 )
        vfptr->GetNodePosition(pWayGraph, &v71, v12);
      else
        vfptr->GetEdgePosition(pWayGraph, &v70, v12, 0);
      v15 = (UFG::WayStarNode *)p_mPrev[3];
      if ( v15 )
        v16 = v15->m_EstimatedCost + v15->m_ActualCost;
      else
        v16 = 0.0;
      if ( (float)(*((float *)p_mPrev + 8) + *((float *)p_mPrev + 9)) >= this->fGoalMinRadius
        && v16 <= this->fGoalMaxRadius )
      {
        mFreeListHead = (UFG::WayStarNode *)UFG::WayFinder::s_NodePool.mFreeListHead;
        if ( UFG::WayFinder::s_NodePool.mFreeListHead )
        {
          UFG::WayFinder::s_NodePool.mFreeListHead = *(char **)UFG::WayFinder::s_NodePool.mFreeListHead;
          v18 = UFG::WayFinder::s_NodePool.mNumSlotsAllocated + 1;
          UFG::WayFinder::s_NodePool.mNumSlotsAllocated = v18;
          if ( UFG::WayFinder::s_NodePool.mMostSlotsAllocated <= v18 )
            UFG::WayFinder::s_NodePool.mMostSlotsAllocated = v18;
        }
        else
        {
          UFG::qFixedAllocator::ReportFull(&UFG::WayFinder::s_NodePool);
        }
        if ( mFreeListHead )
        {
          v19 = *((float *)p_mPrev + 8);
          v20 = v19 + *((float *)p_mPrev + 9);
          v21 = *((_WORD *)p_mPrev + 9);
          v22 = *((_WORD *)p_mPrev + 8);
          mFreeListHead->mPrev = mFreeListHead;
          mFreeListHead->mNext = mFreeListHead;
          mFreeListHead->m_WayEdge = v22;
          mFreeListHead->m_WayNode = v21;
          mFreeListHead->m_ParentNode = v15;
          mFreeListHead->m_ActualCost = v19;
          mFreeListHead->m_EstimatedCost = v20;
        }
        else
        {
          mFreeListHead = 0i64;
        }
        this->pCandidates[this->nCandidates++] = mFreeListHead;
        if ( this->nCandidates >= 512 )
        {
          this->nState = WAYSTAR_FULL_WAY;
          Ticks = v69;
          break;
        }
      }
      if ( v12 != 0xFFFF )
      {
        v23 = pWayGraph->vfptr->IsEdge(pWayGraph, v12);
        v74 = v23;
        v24 = 4096 - UFG::WayTraversal::NodePool.mNumSlotsAllocated;
        if ( v23 )
        {
          v25 = 1;
        }
        else
        {
          v25 = pWayGraph->vfptr->GetNumNodeEdges(pWayGraph, v12);
          v23 = 0;
        }
        v76 = v25;
        if ( v24 < v25 - 1 )
        {
          this->nState = WAYSTAR_PART_WAY;
          v52 = (UFG::WayStarNode *)UFG::WayFinder::s_NodePool.mFreeListHead;
          if ( UFG::WayFinder::s_NodePool.mFreeListHead )
          {
            UFG::WayFinder::s_NodePool.mFreeListHead = *(char **)UFG::WayFinder::s_NodePool.mFreeListHead;
            v53 = UFG::WayFinder::s_NodePool.mNumSlotsAllocated + 1;
            UFG::WayFinder::s_NodePool.mNumSlotsAllocated = v53;
            if ( UFG::WayFinder::s_NodePool.mMostSlotsAllocated <= v53 )
              UFG::WayFinder::s_NodePool.mMostSlotsAllocated = v53;
          }
          else
          {
            UFG::qFixedAllocator::ReportFull(&UFG::WayFinder::s_NodePool);
          }
          if ( v52 )
          {
            v54 = *((float *)p_mPrev + 8);
            v55 = v54 + *((float *)p_mPrev + 9);
            v56 = *((_WORD *)p_mPrev + 9);
            v57 = *((_WORD *)p_mPrev + 8);
            v52->mPrev = v52;
            v52->mNext = v52;
            v52->m_WayEdge = v57;
            v52->m_WayNode = v56;
            v52->m_ParentNode = v15;
            v52->m_ActualCost = v54;
            v52->m_EstimatedCost = v55;
          }
          else
          {
            v52 = 0i64;
          }
          this->pCandidates[this->nCandidates++] = v52;
          Ticks = v69;
          break;
        }
        if ( v25 > 0 )
        {
          v26 = v75;
          do
          {
            if ( v23 )
            {
              v27 = v12;
            }
            else
            {
              v27 = pWayGraph->vfptr->GetNodeEdge(pWayGraph, v12, v6);
              v25 = v76;
            }
            if ( v27 != v26 )
            {
              v28 = pWayGraph->vfptr->GetEdgeNode(pWayGraph, v27, 0);
              v29 = v12;
              if ( v74 )
                v29 = v75;
              v30 = v29 == v28;
              LOWORD(v67) = v12;
              if ( this->pClient->vfptr->CanGo(this->pClient, pWayGraph, v75, v27, v67) )
              {
                v31 = *((float *)p_mPrev + 8);
                v32 = ((double (__fastcall *)(UFG::WayGraph *, _QWORD))pWayGraph->vfptr->GetEdgeLength)(pWayGraph, v27);
                v33 = *(float *)&v32 + v31;
                v68 = v30;
                v34 = pWayGraph->vfptr->GetEdgeNode(pWayGraph, v27, v30);
                for ( i = this->lOpen.mNode.mNext; ; i = i->mNext )
                {
                  if ( i == (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)p_lOpen )
                  {
                    i = 0i64;
                    goto LABEL_44;
                  }
                  if ( v34 == WORD1(i[1].mPrev) && v27 == LOWORD(i[1].mPrev) )
                    break;
                }
                if ( v33 >= *(float *)&i[2].mPrev )
                  goto LABEL_60;
LABEL_44:
                for ( j = this->lClosed.mNode.mNext;
                      j != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&this->lClosed;
                      j = j->mNext )
                {
                  if ( v34 == WORD1(j[1].mPrev) && v27 == LOWORD(j[1].mPrev) )
                  {
                    if ( v33 >= *(float *)&j[2].mPrev )
                      goto LABEL_60;
                    v37 = j->mPrev;
                    v38 = j->mNext;
                    v37->mNext = v38;
                    v38->mPrev = v37;
                    j->mPrev = j;
                    j->mNext = j;
                    v39 = j->mPrev;
                    v40 = j->mNext;
                    v39->mNext = v40;
                    v40->mPrev = v39;
                    j->mPrev = j;
                    j->mNext = j;
                    j->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayFinder::s_NodePool.mFreeListHead;
                    UFG::WayFinder::s_NodePool.mFreeListHead = (char *)j;
                    --UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
                    break;
                  }
                }
                if ( i )
                {
                  v41 = i->mPrev;
                  v42 = i->mNext;
                  v41->mNext = v42;
                  v42->mPrev = v41;
                  i->mPrev = i;
                  i->mNext = i;
                  v43 = i->mPrev;
                  v44 = i->mNext;
                  v43->mNext = v44;
                  v44->mPrev = v43;
                  i->mPrev = i;
                  i->mNext = i;
                  i->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayFinder::s_NodePool.mFreeListHead;
                  UFG::WayFinder::s_NodePool.mFreeListHead = (char *)i;
                  --UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
                }
                v13 = !pWayGraph->vfptr->IsEdge(pWayGraph, v34);
                v45 = pWayGraph->vfptr;
                if ( v13 )
                  v46 = (float *)v45->GetNodePosition(pWayGraph, (UFG::qVector3 *)&v73, v34);
                else
                  v46 = (float *)v45->GetEdgePosition(pWayGraph, &v72, v27, v68);
                v47 = this->vSourcePosition.y - v46[1];
                x_low = (__m128)LODWORD(this->vSourcePosition.x);
                x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - *v46) * (float)(x_low.m128_f32[0] - *v46))
                                          + (float)(v47 * v47))
                                  + (float)((float)(this->vSourcePosition.z - v46[2])
                                          * (float)(this->vSourcePosition.z - v46[2]));
                v49 = _mm_sqrt_ps(x_low).m128_u32[0];
                if ( (float)(*((float *)p_mPrev + 8) + *((float *)p_mPrev + 9)) < this->fGoalMaxRadius )
                {
                  v50 = UFG::WayStarNode::operator new(0x28ui64);
                  if ( v50 )
                  {
                    *(_QWORD *)v50 = v50;
                    *((_QWORD *)v50 + 1) = v50;
                    *((_WORD *)v50 + 8) = v27;
                    *((_WORD *)v50 + 9) = v34;
                    *((_QWORD *)v50 + 3) = p_mPrev;
                    *((float *)v50 + 8) = v33;
                    *((_DWORD *)v50 + 9) = v49;
                  }
                  UFG::WayTraversalSearch::AddOpenNode(this, (UFG::WayStarNode *)v50);
                }
              }
LABEL_60:
              v25 = v76;
              v26 = v75;
            }
            ++v6;
            v23 = v74;
          }
          while ( v6 < v25 );
        }
        v6 = 0;
      }
      v51 = this->lClosed.mNode.mNext;
      this->lClosed.mNode.mNext = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)p_mPrev;
      *p_mPrev = &this->lClosed;
      p_mPrev[1] = v51;
      v51->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)p_mPrev;
      Ticks = v69;
    }
    while ( this->nState == WAYSTAR_SEARCHING );
  }
  v58 = this->nState <= WAYSTAR_SEARCHING;
  if ( this->nState == WAYSTAR_SEARCHING )
  {
    if ( (UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *)this->lOpen.mNode.mNext == &this->lOpen )
    {
      v59 = WAYSTAR_NO_WAY;
      if ( this->nCandidates > 0 )
        v59 = WAYSTAR_FULL_WAY;
      this->nState = v59;
    }
    v58 = this->nState <= WAYSTAR_SEARCHING;
  }
  if ( !v58 )
  {
    this->pClient->m_NumWayEdges = this->nCandidates;
    this->pClient->nWayNodes = this->nCandidates;
    aWayNodes = this->pClient->aWayNodes;
    if ( this->nCandidates > 0 )
    {
      pCandidates = this->pCandidates;
      do
      {
        v62 = *pCandidates;
        *(aWayNodes - 530) = (*pCandidates)->m_WayEdge;
        m_ParentNode = v62->m_ParentNode;
        if ( m_ParentNode )
          m_WayNode = m_ParentNode->m_WayNode;
        else
          m_WayNode = v62->m_WayNode;
        *aWayNodes = m_WayNode;
        ++v6;
        ++pCandidates;
        ++aWayNodes;
      }
      while ( v6 < this->nCandidates );
    }
  }
  v65 = UFG::qGetTicks();
  result = UFG::qGetTickTime(Ticks, v65);
  this->fSearchTime = result + this->fSearchTime;
  return result;
}

// File Line: 324
// RVA: 0x157AB70
__int64 dynamic_initializer_for__UFG::WayTraversal::NodePool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::WayTraversal::NodePool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WayTraversal::NodePool__);
}

// File Line: 325
// RVA: 0x157AB90
__int64 dynamic_initializer_for__UFG::WayTraversal::SearchPool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::WayTraversal::SearchPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WayTraversal::SearchPool__);
}

// File Line: 328
// RVA: 0x67B860
UFG::WayTraversal *__fastcall UFG::GetWayTraversal()
{
  unsigned int v0; // eax

  v0 = _S31_2;
  if ( (_S31_2 & 1) == 0 )
  {
    _S31_2 |= 1u;
    WayTraversalDummyGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
    atexit(UFG::GetWayTraversal_::_2_::_dynamic_atexit_destructor_for__WayTraversalDummyGraph__);
    v0 = _S31_2;
  }
  if ( (v0 & 2) == 0 )
  {
    _S31_2 = v0 | 2;
    gWayTraversal.lSearches.mNode.mPrev = &gWayTraversal.lSearches.mNode;
    gWayTraversal.lSearches.mNode.mNext = &gWayTraversal.lSearches.mNode;
    gWayTraversal.pWayGraph = &WayTraversalDummyGraph;
    if ( !UFG::WayTraversal::nPoolReferenceCount++ )
    {
      UFG::qFixedAllocator::Init(&UFG::WayTraversal::NodePool, 163840, 40, "WayTraversalNodes", 0i64);
      UFG::qFixedAllocator::Init(&UFG::WayTraversal::SearchPool, 67840, 4240, "WayTraversalSearches", 0i64);
    }
    atexit(UFG::GetWayTraversal_::_2_::_dynamic_atexit_destructor_for__gWayTraversal__);
  }
  return &gWayTraversal;
}

// File Line: 348
// RVA: 0x66D8C0
void __fastcall UFG::WayTraversal::~WayTraversal(UFG::WayTraversal *this)
{
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *p_lSearches; // rbx
  UFG::WayTraversal *i; // rax
  UFG::qList<UFG::WayTraversalSearch,UFG::WayTraversalSearch,1,0> *v4; // rdx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *mPrev; // rcx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *mNext; // rax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v7; // rcx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v8; // rax

  p_lSearches = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->lSearches;
  for ( i = (UFG::WayTraversal *)&this->lSearches.mNode.mNext[-1].mNext;
        i != this;
        i = (UFG::WayTraversal *)&p_lSearches->mNode.mNext[-1].mNext )
  {
    v4 = &i->lSearches;
    mPrev = i->lSearches.mNode.mPrev;
    mNext = i->lSearches.mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v4->mNode.mPrev = &v4->mNode;
    v4->mNode.mNext = &v4->mNode;
    if ( v4 != (UFG::qList<UFG::WayTraversalSearch,UFG::WayTraversalSearch,1,0> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> **, __int64))v4[-1].mNode.mNext->mPrev)(
        &v4[-1].mNode.mNext,
        1i64);
  }
  if ( !--UFG::WayTraversal::nPoolReferenceCount )
  {
    UFG::qFixedAllocator::Close(&UFG::WayTraversal::SearchPool);
    UFG::qFixedAllocator::Close(&UFG::WayTraversal::NodePool);
  }
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes(p_lSearches);
  v7 = p_lSearches->mNode.mPrev;
  v8 = p_lSearches->mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  p_lSearches->mNode.mPrev = &p_lSearches->mNode;
  p_lSearches->mNode.mNext = &p_lSearches->mNode;
}

// File Line: 364
// RVA: 0x689AA0
void __fastcall UFG::WayTraversal::Service(UFG::WayTraversal *this, float time_limit_ms)
{
  float v4; // xmm6_4
  bool v5; // si
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *mNext; // rbx
  float v7; // xmm1_4
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *mPrev; // rcx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v9; // rax

  v4 = 0.0;
  v5 = time_limit_ms >= 0.0;
  while ( (UFG::WayTraversal *)&this->lSearches.mNode.mNext[-1].mNext != this )
  {
    if ( !v5 && v4 >= time_limit_ms )
      break;
    mNext = this->lSearches.mNode.mNext;
    v7 = v5 ? 0.0 : time_limit_ms - v4;
    v4 = v4 + UFG::WayTraversalSearch::Service((UFG::WayTraversalSearch *)&mNext[-1].mNext, v7);
    if ( SLODWORD(mNext[1].mPrev) > 0 )
    {
      mPrev = mNext->mPrev;
      v9 = mNext->mNext;
      mPrev->mNext = v9;
      v9->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      if ( mNext != (UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *)8 )
        ((void (__fastcall *)(UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> **, __int64))mNext[-1].mNext->mPrev)(
          &mNext[-1].mNext,
          1i64);
    }
  }
}

// File Line: 377
// RVA: 0x674230
void __fastcall UFG::WayTraversal::Cancel(UFG::WayTraversal *this, UFG::WayFinderClient *client)
{
  UFG::WayTraversal *p_mNext; // rdx
  UFG::WayTraversal *v5; // rbx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *mPrev; // rcx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *mNext; // rax
  UFG::qList<UFG::WayTraversalSearch,UFG::WayTraversalSearch,1,0> *p_lSearches; // rdx

  p_mNext = (UFG::WayTraversal *)&this->lSearches.mNode.mNext[-1].mNext;
  if ( p_mNext != this )
  {
    do
    {
      v5 = (UFG::WayTraversal *)&p_mNext->lSearches.mNode.mNext[-1].mNext;
      if ( client == (UFG::WayFinderClient *)p_mNext[173].pWayGraph )
      {
        mPrev = p_mNext->lSearches.mNode.mPrev;
        mNext = p_mNext->lSearches.mNode.mNext;
        p_lSearches = &p_mNext->lSearches;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_lSearches->mNode.mPrev = &p_lSearches->mNode;
        p_lSearches->mNode.mNext = &p_lSearches->mNode;
        if ( p_lSearches != (UFG::qList<UFG::WayTraversalSearch,UFG::WayTraversalSearch,1,0> *)8 )
          ((void (__fastcall *)(UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> **, __int64))p_lSearches[-1].mNode.mNext->mPrev)(
            &p_lSearches[-1].mNode.mNext,
            1i64);
        client->m_CurrEdgeIndex = 0;
      }
      p_mNext = v5;
    }
    while ( v5 != this );
  }
}

// File Line: 404
// RVA: 0x678890
UFG::WayTraversalSearch *__fastcall UFG::WayTraversal::FindConnectedEdgesInRange(
        UFG::WayTraversal *this,
        UFG::WayTraversalClient *client,
        UFG::qVector3 *source_position,
        UFG::qVector3 *closest_position,
        float goal_min_radius,
        float goal_max_radius)
{
  __int64 v10; // rbx
  char *v11; // rax
  __int64 v12; // rax
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *mPrev; // rcx

  UFG::WayTraversal::Cancel(this, client);
  v10 = 0i64;
  if ( UFG::WayTraversal::SearchPool.mFreeListHead
    && (signed int)(4096 - UFG::WayTraversal::NodePool.mNumSlotsAllocated) > 1 )
  {
    v11 = UFG::WayTraversalSearch::operator new(0x1090ui64);
    if ( v11 )
    {
      UFG::WayTraversalSearch::WayTraversalSearch(
        (UFG::WayTraversalSearch *)v11,
        this,
        client,
        source_position,
        closest_position,
        goal_min_radius,
        goal_max_radius);
      v10 = v12;
    }
    mPrev = this->lSearches.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *)(v10 + 8);
    *(_QWORD *)(v10 + 8) = mPrev;
    *(_QWORD *)(v10 + 16) = &this->lSearches;
    this->lSearches.mNode.mPrev = (UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *)(v10 + 8);
  }
  return (UFG::WayTraversalSearch *)v10;
}

