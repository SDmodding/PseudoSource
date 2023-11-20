// File Line: 19
// RVA: 0x66BCB0
void __fastcall UFG::WayTraversalSearch::WayTraversalSearch(UFG::WayTraversalSearch *this, UFG::WayTraversal *finder, UFG::WayTraversalClient *client, UFG::qVector3 *source_position, UFG::qVector3 *closest_position, const float goal_min_radius, const float goal_max_radius)
{
  UFG::WayTraversalClient *v7; // rdi
  UFG::WayTraversalSearch *v8; // rsi
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v9; // rax
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *v10; // rax
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::WayGraph *v16; // r14
  unsigned __int16 v17; // [rsp+58h] [rbp+10h]
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *v18; // [rsp+60h] [rbp+18h]

  v7 = client;
  v8 = this;
  v9 = (UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *)&this->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  this->vfptr = (UFG::WayTraversalSearchVtbl *)&UFG::WayTraversalSearch::`vftable';
  v10 = &this->lOpen;
  v10->mNode.mPrev = &v10->mNode;
  v10->mNode.mNext = &v10->mNode;
  v11 = &this->lClosed;
  v18 = v11;
  v11->mNode.mPrev = &v11->mNode;
  v11->mNode.mNext = &v11->mNode;
  this->pFinder = finder;
  this->pClient = client;
  v12 = source_position->y;
  v13 = source_position->z;
  this->vSourcePosition.x = source_position->x;
  this->vSourcePosition.y = v12;
  this->vSourcePosition.z = v13;
  v14 = closest_position->y;
  v15 = closest_position->z;
  this->vClosestPosition.x = closest_position->x;
  this->vClosestPosition.y = v14;
  this->vClosestPosition.z = v15;
  this->fGoalMinRadius = goal_min_radius;
  this->fGoalMaxRadius = goal_max_radius;
  *(_QWORD *)&this->nCandidates = 0i64;
  *(_QWORD *)&this->nSteps = 0i64;
  this->nState = 0;
  v16 = this->pFinder->pWayGraph;
  ((void (__cdecl *)(UFG::WayTraversalClient *))this->pClient->vfptr->ResetWay)(this->pClient);
  v17 = -1;
  if ( ((unsigned __int8 (__fastcall *)(UFG::WayGraph *, UFG::WayTraversalClient *, UFG::qVector3 *, unsigned __int16 *, signed __int64))v16->vfptr->GetEdge)(
         v16,
         v7,
         &v8->vClosestPosition,
         &v17,
         -2i64) )
  {
    UFG::WayTraversalSearch::AddFirstNode(v8, v16, v17, 0);
    UFG::WayTraversalSearch::AddFirstNode(v8, v16, v17, 1);
  }
}

// File Line: 48
// RVA: 0x66D980
void __fastcall UFG::WayTraversalSearch::~WayTraversalSearch(UFG::WayTraversalSearch *this)
{
  UFG::WayTraversalSearch *v1; // r10
  int v2; // er9
  UFG::WayStarNode **v3; // r8
  UFG::WayStarNode *v4; // rdx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v5; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v6; // rax
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *v7; // r8
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v8; // rdx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v9; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v10; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v11; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v12; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v13; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v14; // rax
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *v15; // r8
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v16; // rdx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v17; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v18; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v19; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v20; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v21; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v22; // rax
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v23; // rdx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v24; // rcx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v25; // rax

  v1 = this;
  this->vfptr = (UFG::WayTraversalSearchVtbl *)&UFG::WayTraversalSearch::`vftable';
  v2 = 0;
  if ( this->nCandidates > 0 )
  {
    v3 = this->pCandidates;
    do
    {
      v4 = *v3;
      if ( *v3 )
      {
        v5 = v4->mPrev;
        v6 = v4->mNext;
        v5->mNext = v6;
        v6->mPrev = v5;
        v4->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&v4->mPrev;
        v4->mNext = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&v4->mPrev;
        v4->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayFinder::s_NodePool.mFreeListHead;
        UFG::WayFinder::s_NodePool.mFreeListHead = (char *)v4;
        --UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
        *v3 = 0i64;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < v1->nCandidates );
  }
  v1->nCandidates = 0;
  v7 = &v1->lClosed;
  v8 = v1->lClosed.mNode.mNext;
  if ( v8 != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&v1->lClosed )
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
      v8 = v1->lClosed.mNode.mNext;
    }
    while ( v8 != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)v7 );
  }
  v13 = v7->mNode.mPrev;
  v14 = v1->lClosed.mNode.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v7->mNode.mPrev = &v7->mNode;
  v1->lClosed.mNode.mNext = &v1->lClosed.mNode;
  v15 = &v1->lOpen;
  v16 = v1->lOpen.mNode.mNext;
  if ( v16 != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&v1->lOpen )
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
      v16 = v1->lOpen.mNode.mNext;
    }
    while ( v16 != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)v15 );
  }
  v21 = v15->mNode.mPrev;
  v22 = v1->lOpen.mNode.mNext;
  v21->mNext = v22;
  v22->mPrev = v21;
  v15->mNode.mPrev = &v15->mNode;
  v1->lOpen.mNode.mNext = &v1->lOpen.mNode;
  v23 = (UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *)&v1->mPrev;
  v24 = v1->mPrev;
  v25 = v1->mNext;
  v24->mNext = v25;
  v25->mPrev = v24;
  v23->mPrev = v23;
  v23->mNext = v23;
}

// File Line: 62
// RVA: 0x66F960
void __fastcall UFG::WayTraversalSearch::AddFirstNode(UFG::WayTraversalSearch *this, UFG::WayGraph *graph, unsigned __int16 current_edge, int index)
{
  unsigned __int16 v4; // bp
  UFG::WayGraph *v5; // rbx
  UFG::WayTraversalSearch *v6; // rsi
  unsigned __int16 v7; // di
  unsigned __int16 v8; // ax
  float *v9; // rax
  __m128 v10; // xmm1
  int v11; // xmm6_4
  char *v12; // rbx
  unsigned int v13; // eax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v14; // rax
  char v15; // [rsp+28h] [rbp-30h]

  v4 = current_edge;
  v5 = graph;
  v6 = this;
  v7 = graph->vfptr->GetEdgeNode(graph, current_edge, index);
  if ( v5->vfptr->IsEdge(v5, v7) )
  {
    v8 = v5->vfptr->GetEdgeNode(v5, v4, 1);
    v9 = (float *)v5->vfptr->GetEdgePosition(v5, (UFG::qVector3 *)&v15, v4, v7 == v8);
  }
  else
  {
    v9 = (float *)v5->vfptr->GetNodePosition(v5, (UFG::qVector3 *)&v15, v7);
  }
  v10 = (__m128)LODWORD(v6->vClosestPosition.x);
  v10.m128_f32[0] = (float)((float)((float)(v10.m128_f32[0] - *v9) * (float)(v10.m128_f32[0] - *v9))
                          + (float)((float)(v6->vClosestPosition.y - v9[1]) * (float)(v6->vClosestPosition.y - v9[1])))
                  + (float)((float)(v6->vClosestPosition.z - v9[2]) * (float)(v6->vClosestPosition.z - v9[2]));
  v11 = (unsigned __int128)_mm_sqrt_ps(v10);
  v12 = UFG::WayFinder::s_NodePool.mFreeListHead;
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
  if ( v12 )
  {
    *(_QWORD *)v12 = v12;
    *((_QWORD *)v12 + 1) = v12;
    *((_WORD *)v12 + 8) = v4;
    *((_WORD *)v12 + 9) = v7;
    *((_QWORD *)v12 + 3) = 0i64;
    *((_DWORD *)v12 + 8) = 0;
    *((_DWORD *)v12 + 9) = v11;
  }
  v14 = v6->lOpen.mNode.mPrev;
  v14->mNext = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)v12;
  *(_QWORD *)v12 = v14;
  *((_QWORD *)v12 + 1) = (char *)v6 + 4208;
  v6->lOpen.mNode.mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)v12;
}

// File Line: 143
// RVA: 0x66FE60
void __fastcall UFG::WayTraversalSearch::AddOpenNode(UFG::WayTraversalSearch *this, UFG::WayStarNode *to_add)
{
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v2; // r8
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *i; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v4; // rax

  v2 = this->lOpen.mNode.mNext;
  for ( i = &this->lOpen; v2 != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)i; v2 = v2->mNext )
  {
    if ( (float)(to_add->m_EstimatedCost + to_add->m_ActualCost) >= (float)(*((float *)&v2[2].mPrev + 1)
                                                                          + *(float *)&v2[2].mPrev) )
      break;
  }
  v4 = v2->mPrev;
  v4->mNext = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&to_add->mPrev;
  to_add->mPrev = v4;
  to_add->mNext = v2;
  v2->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&to_add->mPrev;
}

// File Line: 152
// RVA: 0x689B80
float __fastcall UFG::WayTraversalSearch::Service(UFG::WayTraversalSearch *this, float time_limit_ms)
{
  float v2; // xmm8_4
  UFG::WayTraversalSearch *v3; // rbp
  unsigned __int64 v4; // rbx
  UFG::WayGraph *v5; // rsi
  signed int v6; // er12
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *v7; // r15
  unsigned __int64 v8; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v9; // r14
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v10; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v11; // rax
  unsigned __int16 v12; // r13
  UFG::WayGraphVtbl *v13; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v14; // rdi
  float v15; // xmm1_4
  float v16; // xmm0_4
  char *v17; // rbx
  unsigned int v18; // eax
  int v19; // xmm1_4
  __int16 v20; // cx
  __int16 v21; // ax
  bool v22; // dl
  int v23; // ebx
  signed int v24; // eax
  unsigned __int16 v25; // di
  __int64 v26; // rbx
  unsigned __int16 v27; // ax
  unsigned __int16 v28; // cx
  bool v29; // di
  float v30; // xmm6_4
  float v31; // xmm7_4
  __int64 v32; // rdi
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *i; // r8
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *j; // rdx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v35; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v36; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v37; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v38; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v39; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v40; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v41; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v42; // rax
  UFG::WayGraphVtbl *v43; // rax
  float *v44; // rax
  float v45; // xmm0_4
  __m128 v46; // xmm1
  int v47; // xmm6_4
  char *v48; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v49; // rcx
  char *v50; // rbx
  unsigned int v51; // eax
  int v52; // xmm1_4
  float v53; // xmm0_4
  __int16 v54; // cx
  __int16 v55; // ax
  bool v56; // zf
  bool v57; // sf
  signed int v58; // eax
  unsigned __int16 *v59; // rcx
  signed __int64 v60; // r8
  __int64 v61; // rdx
  __int64 v62; // rax
  unsigned __int16 v63; // ax
  unsigned __int64 v64; // rax
  float result; // xmm0_4
  __int64 v66[2]; // [rsp+20h] [rbp-D8h]
  BOOL v67; // [rsp+30h] [rbp-C8h]
  unsigned __int64 v68; // [rsp+38h] [rbp-C0h]
  char v69; // [rsp+50h] [rbp-A8h]
  char v70; // [rsp+5Ch] [rbp-9Ch]
  char v71; // [rsp+68h] [rbp-90h]
  char v72; // [rsp+74h] [rbp-84h]
  bool v73; // [rsp+100h] [rbp+8h]
  unsigned __int16 v74; // [rsp+110h] [rbp+18h]
  signed int v75; // [rsp+118h] [rbp+20h]

  v2 = time_limit_ms;
  v3 = this;
  ++this->nServices;
  v4 = UFG::qGetTicks();
  v68 = v4;
  v5 = v3->pFinder->pWayGraph;
  v6 = 0;
  if ( v3->nState == WAYSTAR_SEARCHING )
  {
    v7 = &v3->lOpen;
    do
    {
      if ( (UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *)v3->lOpen.mNode.mNext == &v3->lOpen )
        break;
      if ( v2 > 0.0 )
      {
        v8 = UFG::qGetTicks();
        if ( UFG::qGetTickTime(v4, v8) > v2 )
          break;
      }
      ++v3->nSteps;
      v9 = v7->mNode.mPrev;
      v10 = v7->mNode.mPrev->mPrev;
      v11 = v7->mNode.mPrev->mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = v9;
      v9->mNext = v9;
      v12 = WORD1(v9[1].mPrev);
      v74 = (unsigned __int16)v9[1].mPrev;
      v5->vfptr->IsEdge(v5, v12);
      v56 = v5->vfptr->IsEdge(v5, v12) == 0;
      v13 = v5->vfptr;
      if ( v56 )
        v13->GetNodePosition(v5, (UFG::qVector3 *)&v70, v12);
      else
        v13->GetEdgePosition(v5, (UFG::qVector3 *)&v69, v12, 0);
      v14 = v9[1].mNext;
      if ( v14 )
        v15 = *((float *)&v14[2].mPrev + 1) + *(float *)&v14[2].mPrev;
      else
        v15 = 0.0;
      v16 = *(float *)&v9[2].mPrev + *((float *)&v9[2].mPrev + 1);
      if ( v16 >= v3->fGoalMinRadius && v15 <= v3->fGoalMaxRadius )
      {
        v17 = UFG::WayFinder::s_NodePool.mFreeListHead;
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
        if ( v17 )
        {
          v19 = (int)v9[2].mPrev;
          v16 = *(float *)&v9[2].mPrev + *((float *)&v9[2].mPrev + 1);
          v20 = WORD1(v9[1].mPrev);
          v21 = (__int16)v9[1].mPrev;
          *(_QWORD *)v17 = v17;
          *((_QWORD *)v17 + 1) = v17;
          *((_WORD *)v17 + 8) = v21;
          *((_WORD *)v17 + 9) = v20;
          *((_QWORD *)v17 + 3) = v14;
          *((_DWORD *)v17 + 8) = v19;
          *((float *)v17 + 9) = v16;
        }
        else
        {
          v17 = 0i64;
        }
        v3->pCandidates[v3->nCandidates++] = (UFG::WayStarNode *)v17;
        if ( v3->nCandidates >= 512 )
        {
          v3->nState = 1;
          v4 = v68;
          break;
        }
      }
      if ( v12 != -1 )
      {
        v22 = v5->vfptr->IsEdge(v5, v12);
        v73 = v22;
        v23 = 4096 - UFG::WayTraversal::NodePool.mNumSlotsAllocated;
        if ( v22 )
        {
          v24 = 1;
        }
        else
        {
          v24 = v5->vfptr->GetNumNodeEdges(v5, v12);
          v22 = v73;
        }
        v75 = v24;
        if ( v23 < v24 - 1 )
        {
          v3->nState = 2;
          v50 = UFG::WayFinder::s_NodePool.mFreeListHead;
          if ( UFG::WayFinder::s_NodePool.mFreeListHead )
          {
            UFG::WayFinder::s_NodePool.mFreeListHead = *(char **)UFG::WayFinder::s_NodePool.mFreeListHead;
            v51 = UFG::WayFinder::s_NodePool.mNumSlotsAllocated + 1;
            UFG::WayFinder::s_NodePool.mNumSlotsAllocated = v51;
            if ( UFG::WayFinder::s_NodePool.mMostSlotsAllocated <= v51 )
              UFG::WayFinder::s_NodePool.mMostSlotsAllocated = v51;
          }
          else
          {
            UFG::qFixedAllocator::ReportFull(&UFG::WayFinder::s_NodePool);
          }
          if ( v50 )
          {
            v52 = (int)v9[2].mPrev;
            v53 = *(float *)&v9[2].mPrev + *((float *)&v9[2].mPrev + 1);
            v54 = WORD1(v9[1].mPrev);
            v55 = (__int16)v9[1].mPrev;
            *(_QWORD *)v50 = v50;
            *((_QWORD *)v50 + 1) = v50;
            *((_WORD *)v50 + 8) = v55;
            *((_WORD *)v50 + 9) = v54;
            *((_QWORD *)v50 + 3) = v14;
            *((_DWORD *)v50 + 8) = v52;
            *((float *)v50 + 9) = v53;
          }
          else
          {
            v50 = 0i64;
          }
          v3->pCandidates[v3->nCandidates++] = (UFG::WayStarNode *)v50;
          v4 = v68;
          break;
        }
        if ( v24 > 0 )
        {
          v25 = v74;
          do
          {
            if ( v22 )
            {
              LOWORD(v26) = v12;
            }
            else
            {
              v26 = v5->vfptr->GetNodeEdge(v5, v12, v6);
              v24 = v75;
            }
            if ( (_WORD)v26 != v25 )
            {
              v27 = v5->vfptr->GetEdgeNode(v5, v26, 0);
              v28 = v12;
              if ( v73 )
                v28 = v74;
              v29 = v28 == v27;
              LOWORD(v66[0]) = v12;
              if ( v3->pClient->vfptr->CanGo((UFG::WayFinderClient *)v3->pClient, v5, v74, v26, v66[0]) )
              {
                v30 = *(float *)&v9[2].mPrev;
                v5->vfptr->GetEdgeLength(v5, v26);
                v31 = v16 + v30;
                v67 = v29;
                v32 = v5->vfptr->GetEdgeNode(v5, v26, v29);
                for ( i = v3->lOpen.mNode.mNext; ; i = i->mNext )
                {
                  if ( i == (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)v7 )
                  {
                    i = 0i64;
                    goto LABEL_44;
                  }
                  if ( (_WORD)v32 == WORD1(i[1].mPrev) && (_WORD)v26 == LOWORD(i[1].mPrev) )
                    break;
                }
                if ( v31 >= *(float *)&i[2].mPrev )
                  goto LABEL_60;
LABEL_44:
                for ( j = v3->lClosed.mNode.mNext;
                      j != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&v3->lClosed;
                      j = j->mNext )
                {
                  if ( (_WORD)v32 == WORD1(j[1].mPrev) && (_WORD)v26 == LOWORD(j[1].mPrev) )
                  {
                    if ( v31 >= *(float *)&j[2].mPrev )
                      goto LABEL_60;
                    v35 = j->mPrev;
                    v36 = j->mNext;
                    v35->mNext = v36;
                    v36->mPrev = v35;
                    j->mPrev = j;
                    j->mNext = j;
                    v37 = j->mPrev;
                    v38 = j->mNext;
                    v37->mNext = v38;
                    v38->mPrev = v37;
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
                  v39 = i->mPrev;
                  v40 = i->mNext;
                  v39->mNext = v40;
                  v40->mPrev = v39;
                  i->mPrev = i;
                  i->mNext = i;
                  v41 = i->mPrev;
                  v42 = i->mNext;
                  v41->mNext = v42;
                  v42->mPrev = v41;
                  i->mPrev = i;
                  i->mNext = i;
                  i->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayFinder::s_NodePool.mFreeListHead;
                  UFG::WayFinder::s_NodePool.mFreeListHead = (char *)i;
                  --UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
                }
                v56 = v5->vfptr->IsEdge(v5, v32) == 0;
                v43 = v5->vfptr;
                if ( v56 )
                  v44 = (float *)v43->GetNodePosition(v5, (UFG::qVector3 *)&v72, v32);
                else
                  v44 = (float *)v43->GetEdgePosition(v5, (UFG::qVector3 *)&v71, v26, v67);
                v45 = v3->vSourcePosition.y - v44[1];
                v46 = (__m128)LODWORD(v3->vSourcePosition.x);
                v46.m128_f32[0] = (float)((float)((float)(v46.m128_f32[0] - *v44) * (float)(v46.m128_f32[0] - *v44))
                                        + (float)(v45 * v45))
                                + (float)((float)(v3->vSourcePosition.z - v44[2])
                                        * (float)(v3->vSourcePosition.z - v44[2]));
                v47 = (unsigned __int128)_mm_sqrt_ps(v46);
                v16 = *(float *)&v9[2].mPrev + *((float *)&v9[2].mPrev + 1);
                if ( v16 < v3->fGoalMaxRadius )
                {
                  v48 = UFG::WayStarNode::operator new(0x28ui64);
                  if ( v48 )
                  {
                    *(_QWORD *)v48 = v48;
                    *((_QWORD *)v48 + 1) = v48;
                    *((_WORD *)v48 + 8) = v26;
                    *((_WORD *)v48 + 9) = v32;
                    *((_QWORD *)v48 + 3) = v9;
                    *((float *)v48 + 8) = v31;
                    *((_DWORD *)v48 + 9) = v47;
                  }
                  UFG::WayTraversalSearch::AddOpenNode(v3, (UFG::WayStarNode *)v48);
                }
              }
LABEL_60:
              v24 = v75;
              v25 = v74;
            }
            ++v6;
            v22 = v73;
          }
          while ( v6 < v24 );
        }
        v6 = 0;
      }
      v49 = v3->lClosed.mNode.mNext;
      v3->lClosed.mNode.mNext = v9;
      v9->mPrev = &v3->lClosed.mNode;
      v9->mNext = v49;
      v49->mPrev = v9;
      v4 = v68;
    }
    while ( v3->nState == WAYSTAR_SEARCHING );
  }
  v56 = v3->nState == 0;
  v57 = v3->nState < 0;
  if ( v3->nState == WAYSTAR_SEARCHING )
  {
    if ( (UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *)v3->lOpen.mNode.mNext == &v3->lOpen )
    {
      v58 = 3;
      if ( v3->nCandidates > 0 )
        v58 = 1;
      v3->nState = v58;
    }
    v56 = v3->nState == 0;
    v57 = v3->nState < 0;
  }
  if ( !v57 && !v56 )
  {
    v3->pClient->m_NumWayEdges = v3->nCandidates;
    v3->pClient->nWayNodes = v3->nCandidates;
    v59 = v3->pClient->aWayNodes;
    if ( v3->nCandidates > 0 )
    {
      v60 = (signed __int64)v3->pCandidates;
      do
      {
        v61 = *(_QWORD *)v60;
        *(v59 - 530) = *(_WORD *)(*(_QWORD *)v60 + 16i64);
        v62 = *(_QWORD *)(v61 + 24);
        if ( v62 )
          v63 = *(_WORD *)(v62 + 18);
        else
          v63 = *(_WORD *)(v61 + 18);
        *v59 = v63;
        ++v6;
        v60 += 8i64;
        ++v59;
      }
      while ( v6 < v3->nCandidates );
    }
  }
  v64 = UFG::qGetTicks();
  result = UFG::qGetTickTime(v4, v64);
  v3->fSearchTime = result + v3->fSearchTime;
  return result;
}

// File Line: 324
// RVA: 0x157AB70
__int64 dynamic_initializer_for__UFG::WayTraversal::NodePool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::WayTraversal::NodePool);
  return atexit(dynamic_atexit_destructor_for__UFG::WayTraversal::NodePool__);
}

// File Line: 325
// RVA: 0x157AB90
__int64 dynamic_initializer_for__UFG::WayTraversal::SearchPool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::WayTraversal::SearchPool);
  return atexit(dynamic_atexit_destructor_for__UFG::WayTraversal::SearchPool__);
}

// File Line: 328
// RVA: 0x67B860
UFG::WayTraversal *__fastcall UFG::GetWayTraversal()
{
  unsigned int v0; // eax
  int v1; // ecx

  v0 = _S31_2;
  if ( !(_S31_2 & 1) )
  {
    _S31_2 |= 1u;
    WayTraversalDummyGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable';
    atexit(UFG::GetWayTraversal_::_2_::_dynamic_atexit_destructor_for__WayTraversalDummyGraph__);
    v0 = _S31_2;
  }
  if ( !(v0 & 2) )
  {
    _S31_2 = v0 | 2;
    gWayTraversal.lSearches.mNode.mPrev = &gWayTraversal.lSearches.mNode;
    gWayTraversal.lSearches.mNode.mNext = &gWayTraversal.lSearches.mNode;
    gWayTraversal.pWayGraph = &WayTraversalDummyGraph;
    v1 = UFG::WayTraversal::nPoolReferenceCount++;
    if ( !v1 )
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
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v1; // rbx
  UFG::WayTraversal *v2; // rax
  UFG::WayTraversal *i; // rdi
  UFG::qList<UFG::WayTraversalSearch,UFG::WayTraversalSearch,1,0> *v4; // rdx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v5; // rcx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v6; // rax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v7; // rcx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v8; // rax

  v1 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->lSearches;
  v2 = (UFG::WayTraversal *)&this->lSearches.mNode.mNext[-1].mNext;
  for ( i = this; v2 != i; v2 = (UFG::WayTraversal *)&v1->mNode.mNext[-1].mNext )
  {
    v4 = &v2->lSearches;
    v5 = v2->lSearches.mNode.mPrev;
    v6 = v2->lSearches.mNode.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mNode.mPrev = &v4->mNode;
    v4->mNode.mNext = &v4->mNode;
    if ( v4 != (UFG::qList<UFG::WayTraversalSearch,UFG::WayTraversalSearch,1,0> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> **, signed __int64))v4[-1].mNode.mNext->mPrev)(
        &v4[-1].mNode.mNext,
        1i64);
  }
  if ( !--UFG::WayTraversal::nPoolReferenceCount )
  {
    UFG::qFixedAllocator::Close(&UFG::WayTraversal::SearchPool);
    UFG::qFixedAllocator::Close(&UFG::WayTraversal::NodePool);
  }
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes(v1);
  v7 = v1->mNode.mPrev;
  v8 = v1->mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 364
// RVA: 0x689AA0
void __fastcall UFG::WayTraversal::Service(UFG::WayTraversal *this, float time_limit_ms)
{
  UFG::WayTraversal *v2; // rdi
  float v3; // xmm7_4
  float v4; // xmm6_4
  bool v5; // si
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v6; // rbx
  float v7; // xmm1_4
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v8; // rcx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v9; // rax

  v2 = this;
  v3 = time_limit_ms;
  v4 = 0.0;
  v5 = time_limit_ms >= 0.0;
  while ( (UFG::WayTraversal *)&v2->lSearches.mNode.mNext[-1].mNext != v2 )
  {
    if ( !v5 && v4 >= v3 )
      break;
    v6 = v2->lSearches.mNode.mNext;
    v7 = v5 ? 0.0 : v3 - v4;
    v4 = v4 + UFG::WayTraversalSearch::Service((UFG::WayTraversalSearch *)&v6[-1].mNext, v7);
    if ( SLODWORD(v6[1].mPrev) > 0 )
    {
      v8 = v6->mPrev;
      v9 = v6->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v6->mPrev = v6;
      v6->mNext = v6;
      if ( v6 != (UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *)8 )
        ((void (__fastcall *)(UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> **, signed __int64))v6[-1].mNext->mPrev)(
          &v6[-1].mNext,
          1i64);
    }
  }
}

// File Line: 377
// RVA: 0x674230
void __fastcall UFG::WayTraversal::Cancel(UFG::WayTraversal *this, UFG::WayFinderClient *client)
{
  UFG::WayFinderClient *v2; // rdi
  UFG::WayTraversal *v3; // rsi
  UFG::WayTraversal *v4; // rdx
  signed __int64 v5; // rbx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v6; // rcx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v7; // rax
  UFG::qList<UFG::WayTraversalSearch,UFG::WayTraversalSearch,1,0> *v8; // rdx

  v2 = client;
  v3 = this;
  v4 = (UFG::WayTraversal *)&this->lSearches.mNode.mNext[-1].mNext;
  if ( v4 != this )
  {
    do
    {
      v5 = (signed __int64)&v4->lSearches.mNode.mNext[-1].mNext;
      if ( v2 == (UFG::WayFinderClient *)v4[173].pWayGraph )
      {
        v6 = v4->lSearches.mNode.mPrev;
        v7 = v4->lSearches.mNode.mNext;
        v8 = &v4->lSearches;
        v6->mNext = v7;
        v7->mPrev = v6;
        v8->mNode.mPrev = &v8->mNode;
        v8->mNode.mNext = &v8->mNode;
        if ( v8 != (UFG::qList<UFG::WayTraversalSearch,UFG::WayTraversalSearch,1,0> *)8 )
          ((void (__fastcall *)(UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> **, signed __int64))v8[-1].mNode.mNext->mPrev)(
            &v8[-1].mNode.mNext,
            1i64);
        v2->m_CurrEdgeIndex = 0;
      }
      v4 = (UFG::WayTraversal *)v5;
    }
    while ( (UFG::WayTraversal *)v5 != v3 );
  }
}

// File Line: 404
// RVA: 0x678890
UFG::WayTraversalSearch *__fastcall UFG::WayTraversal::FindConnectedEdgesInRange(UFG::WayTraversal *this, UFG::WayTraversalClient *client, UFG::qVector3 *source_position, UFG::qVector3 *closest_position, const float goal_min_radius, const float goal_max_radius)
{
  UFG::qVector3 *v6; // rbp
  UFG::qVector3 *v7; // r14
  UFG::WayTraversalClient *v8; // rsi
  UFG::WayTraversal *v9; // rdi
  __int64 v10; // rbx
  char *v11; // rax
  __int64 v12; // rax
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> **v13; // rdx
  UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *v14; // rcx

  v6 = closest_position;
  v7 = source_position;
  v8 = client;
  v9 = this;
  UFG::WayTraversal::Cancel(this, (UFG::WayFinderClient *)&client->vfptr);
  v10 = 0i64;
  if ( UFG::WayTraversal::SearchPool.mFreeListHead
    && (signed int)(4096 - UFG::WayTraversal::NodePool.mNumSlotsAllocated) > 1 )
  {
    v11 = UFG::WayTraversalSearch::operator new(0x1090ui64);
    if ( v11 )
    {
      UFG::WayTraversalSearch::WayTraversalSearch(
        (UFG::WayTraversalSearch *)v11,
        v9,
        v8,
        v7,
        v6,
        goal_min_radius,
        goal_max_radius);
      v10 = v12;
    }
    v13 = (UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> **)(v10 + 8);
    v14 = v9->lSearches.mNode.mPrev;
    v14->mNext = (UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *)(v10 + 8);
    *v13 = v14;
    v13[1] = &v9->lSearches.mNode;
    v9->lSearches.mNode.mPrev = (UFG::qNode<UFG::WayTraversalSearch,UFG::WayTraversalSearch> *)(v10 + 8);
  }
  return (UFG::WayTraversalSearch *)v10;
}

