// File Line: 19
// RVA: 0xE2010
void __fastcall UFG::WayStarSearch::WayStarSearch(UFG::WayStarSearch *this, UFG::WayFinder *finder, UFG::WayFinderClient *client, UFG::qVector3 *goal_position, UFG::qVector3 *p_goal_direction)
{
  UFG::WayFinderClient *v5; // rsi
  UFG::WayStarSearch *v6; // rbx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v7; // rax
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *v8; // r14
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm2_4
  UFG::WayGraph *v12; // rdi
  UFG::WayGraphVtbl *v13; // rax
  _BOOL8 v14; // rbp
  unsigned __int16 *v15; // r12
  signed __int16 v16; // ax
  __int64 v17; // rbp
  __int64 v18; // r12
  unsigned __int16 v19; // ax
  float *v20; // rax
  __m128 v21; // xmm5
  float v22; // xmm3_4
  float v23; // xmm4_4
  __m128 v24; // xmm1
  int v25; // xmm6_4
  int v26; // xmm7_4
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v27; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v28; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v29; // rax
  __int64 v30; // rsi
  bool v31; // zf
  UFG::WayGraphVtbl *v32; // rax
  unsigned __int16 v33; // ax
  float *v34; // rax
  float v35; // xmm4_4
  float v36; // xmm5_4
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  float v39; // xmm6_4
  float v40; // xmm7_4
  UFG::qVector3 *v41; // rax
  float v42; // [rsp+38h] [rbp-80h]
  float v43; // [rsp+3Ch] [rbp-7Ch]
  float v44; // [rsp+40h] [rbp-78h]
  char v45; // [rsp+48h] [rbp-70h]
  unsigned int v46; // [rsp+C8h] [rbp+10h]
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *v47; // [rsp+D0h] [rbp+18h]

  v5 = client;
  v6 = this;
  v7 = (UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *)&this->mPrev;
  v7->mPrev = v7;
  v7->mNext = v7;
  this->vfptr = (UFG::WayStarSearchVtbl *)&UFG::WayStarSearch::`vftable;
  v8 = &this->m_OpenNodes;
  v8->mNode.mPrev = &v8->mNode;
  v8->mNode.mNext = &v8->mNode;
  v9 = &this->m_ClosedNodes;
  v47 = &this->m_ClosedNodes;
  v9->mNode.mPrev = &v9->mNode;
  v9->mNode.mNext = &v9->mNode;
  this->m_WayFinder = finder;
  this->m_WayFinderClient = client;
  v10 = goal_position->y;
  v11 = goal_position->z;
  this->m_GoalPosition.x = goal_position->x;
  this->m_GoalPosition.y = v10;
  this->m_GoalPosition.z = v11;
  *(_QWORD *)&this->m_NumServices = 0i64;
  this->m_SolutionNode = 0i64;
  this->m_TurnAroundNode = 0i64;
  this->m_SearchTime = 0.0;
  this->m_SearchState = 0;
  v46 = 0;
  v12 = finder->m_WayGraph;
  v13 = finder->m_WayGraph->vfptr;
  if ( p_goal_direction )
  {
    v15 = &this->m_GoalWayEdge;
    LOBYTE(v14) = ((__int64 (__fastcall *)(UFG::WayGraph *, UFG::WayFinderClient *, UFG::qVector3 *))v13->GetEdgeNode)(
                    v12,
                    client,
                    &this->m_GoalPosition);
    if ( (_BYTE)v14 )
      v16 = v12->vfptr->GetEdgeNode(v12, *v15, v46);
    else
      v16 = -1;
    v6->m_GoalWayNode = v16;
  }
  else
  {
    v14 = v13->GetEdge(v12, client, &this->m_GoalPosition, &this->m_GoalWayEdge);
    v6->m_GoalWayNode = -1;
  }
  v5->vfptr->ResetWay(v5);
  if ( (_BYTE)v14
    && (v17 = v5->vfptr->GetWayEdge(v5, v12), v18 = v5->vfptr->GetWayNode(v5, v12), v12->vfptr->IsEdge(v12, v17))
    && (_WORD)v18 != -1 )
  {
    v5->vfptr->GetPosition(v5, (UFG::qVector3 *)&v42);
    v19 = v12->vfptr->GetEdgeNode(v12, v17, 1);
    v20 = (float *)v12->vfptr->GetEdgePosition(v12, (UFG::qVector3 *)&v45, v17, (_WORD)v18 == v19);
    v21 = (__m128)*(unsigned int *)v20;
    v22 = v20[1];
    v23 = v20[2];
    v24 = (__m128)LODWORD(v42);
    v24.m128_f32[0] = (float)((float)((float)(v42 - v21.m128_f32[0]) * (float)(v42 - v21.m128_f32[0]))
                            + (float)((float)(v43 - v22) * (float)(v43 - v22)))
                    + (float)((float)(v44 - v23) * (float)(v44 - v23));
    v25 = (unsigned __int128)_mm_sqrt_ps(v24);
    v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] - v6->m_GoalPosition.x)
                                    * (float)(v21.m128_f32[0] - v6->m_GoalPosition.x))
                            + (float)((float)(v22 - v6->m_GoalPosition.y) * (float)(v22 - v6->m_GoalPosition.y)))
                    + (float)((float)(v23 - v6->m_GoalPosition.z) * (float)(v23 - v6->m_GoalPosition.z));
    v26 = (unsigned __int128)_mm_sqrt_ps(v21);
    v27 = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayStarNode::operator new(0x28ui64);
    v28 = v27;
    p_goal_direction = (UFG::qVector3 *)v27;
    if ( v27 )
    {
      v27->mPrev = v27;
      v27->mNext = v27;
      LOWORD(v27[1].mPrev) = v17;
      WORD1(v27[1].mPrev) = v18;
      v27[1].mNext = 0i64;
      LODWORD(v27[2].mPrev) = v25;
      HIDWORD(v27[2].mPrev) = v26;
    }
    else
    {
      v28 = 0i64;
    }
    v29 = v8->mNode.mPrev;
    v29->mNext = v28;
    v28->mPrev = v29;
    v28->mNext = &v8->mNode;
    v8->mNode.mPrev = v28;
    if ( (*((unsigned __int8 (__fastcall **)(UFG::WayFinderClient *))&v5->vfptr->__vecDelDtor + 1))(v5) )
    {
      LOWORD(v30) = v12->vfptr->GetEdgeNode(v12, v17, 0);
      if ( (_WORD)v30 == (_WORD)v18 )
        v30 = v12->vfptr->GetEdgeNode(v12, v17, 1);
      if ( (_WORD)v30 != -1 )
      {
        v31 = v12->vfptr->IsEdge(v12, v30) == 0;
        v32 = v12->vfptr;
        if ( v31 )
        {
          v34 = (float *)v32->GetNodePosition(v12, (UFG::qVector3 *)&v45, v30);
        }
        else
        {
          v33 = v32->GetEdgeNode(v12, v17, 1);
          v34 = (float *)v12->vfptr->GetEdgePosition(v12, (UFG::qVector3 *)&v45, v17, (_WORD)v30 == v33);
        }
        v35 = v34[2];
        v36 = v34[1];
        v37 = (__m128)*(unsigned int *)v34;
        v38 = (__m128)LODWORD(v42);
        v38.m128_f32[0] = (float)((float)((float)(v42 - v37.m128_f32[0]) * (float)(v42 - v37.m128_f32[0]))
                                + (float)((float)(v43 - v36) * (float)(v43 - v36)))
                        + (float)((float)(v44 - v35) * (float)(v44 - v35));
        LODWORD(v39) = (unsigned __int128)_mm_sqrt_ps(v38);
        v37.m128_f32[0] = (float)((float)((float)(v37.m128_f32[0] - v6->m_GoalPosition.x)
                                        * (float)(v37.m128_f32[0] - v6->m_GoalPosition.x))
                                + (float)((float)(v36 - v6->m_GoalPosition.y) * (float)(v36 - v6->m_GoalPosition.y)))
                        + (float)((float)(v35 - v6->m_GoalPosition.z) * (float)(v35 - v6->m_GoalPosition.z));
        LODWORD(v40) = (unsigned __int128)_mm_sqrt_ps(v37);
        v41 = (UFG::qVector3 *)UFG::WayStarNode::operator new(0x28ui64);
        p_goal_direction = v41;
        if ( v41 )
        {
          *(_QWORD *)&v41->x = v41;
          *(_QWORD *)&v41->z = v41;
          LOWORD(v41[1].y) = v17;
          HIWORD(v41[1].y) = v30;
          *(_QWORD *)&v41[2].x = 0i64;
          v41[2].z = v39;
          v41[3].x = v40;
        }
        else
        {
          v41 = 0i64;
        }
        v6->m_TurnAroundNode = (UFG::WayStarNode *)v41;
        UFG::WayStarSearch::AddOpenNode(v6, (UFG::WayStarNode *)v41);
      }
    }
  }
  else
  {
    v6->m_SearchState = 3;
  }
}

// File Line: 133
// RVA: 0xE2530
void __fastcall UFG::WayStarSearch::~WayStarSearch(UFG::WayStarSearch *this)
{
  UFG::WayStarSearch *v1; // rdi
  UFG::WayStarNode *v2; // rdx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v3; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v4; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v5; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v6; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v7; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v8; // rax
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v9; // rdx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v10; // rcx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::WayStarSearchVtbl *)&UFG::WayStarSearch::`vftable;
  v2 = this->m_SolutionNode;
  if ( v2 )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&v2->mPrev;
    v2->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayFinder::s_NodePool.mFreeListHead;
    UFG::WayFinder::s_NodePool.mFreeListHead = (char *)v2;
    --UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
  }
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0>::DeleteNodes(&v1->m_ClosedNodes);
  v5 = v1->m_ClosedNodes.mNode.mPrev;
  v6 = v1->m_ClosedNodes.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->m_ClosedNodes.mNode.mPrev = &v1->m_ClosedNodes.mNode;
  v1->m_ClosedNodes.mNode.mNext = &v1->m_ClosedNodes.mNode;
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0>::DeleteNodes(&v1->m_OpenNodes);
  v7 = v1->m_OpenNodes.mNode.mPrev;
  v8 = v1->m_OpenNodes.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->m_OpenNodes.mNode.mPrev = &v1->m_OpenNodes.mNode;
  v1->m_OpenNodes.mNode.mNext = &v1->m_OpenNodes.mNode;
  v9 = (UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *)&v1->mPrev;
  v10 = v1->mPrev;
  v11 = v1->mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v9->mPrev = v9;
  v9->mNext = v9;
}

// File Line: 176
// RVA: 0xE2780
void __fastcall UFG::WayStarSearch::AddOpenNode(UFG::WayStarSearch *this, UFG::WayStarNode *to_add)
{
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v2; // r8
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *i; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v4; // rax

  v2 = this->m_OpenNodes.mNode.mNext;
  for ( i = &this->m_OpenNodes; v2 != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)i; v2 = v2->mNext )
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

// File Line: 186
// RVA: 0xE1F90
void __fastcall UFG::WayFinderClient::WayFinderClient(UFG::WayFinderClient *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  this->vfptr = (UFG::WayFinderClientVtbl *)&UFG::WayFinderClient::`vftable;
  this->m_WayStartsWithTurnAround = 0;
  *(_DWORD *)&this->m_CurrWayEdge = 0;
  v1 = UFG::qVector3::msZero.y;
  v2 = UFG::qVector3::msZero.z;
  this->m_CurrPos.x = UFG::qVector3::msZero.x;
  this->m_CurrPos.y = v1;
  this->m_CurrPos.z = v2;
  v3 = UFG::qVector3::msUnity.y;
  v4 = UFG::qVector3::msUnity.z;
  this->m_CurrDir.x = UFG::qVector3::msUnity.x;
  this->m_CurrDir.y = v3;
  this->m_CurrDir.z = v4;
  this->m_NumWayEdges = 0;
  this->m_CurrEdgeIndex = 0;
  this->m_WayStartsWithTurnAround = 0;
}

// File Line: 192
// RVA: 0xE2A40
void __fastcall UFG::WayFinderClient::GetEdgeLength(UFG::WayFinderClient *this, UFG::WayGraph *wayGraph, unsigned __int16 wayEdge)
{
  wayGraph->vfptr->GetEdgeLength(wayGraph, wayEdge);
}

// File Line: 197
// RVA: 0xE34E0
void __fastcall UFG::WayFinderClient::SetPosition(UFG::WayFinderClient *this, UFG::qVector3 *position, unsigned __int16 edge, unsigned __int16 node)
{
  float v4; // xmm0_4
  float v5; // xmm1_4

  v4 = position->y;
  v5 = position->z;
  this->m_CurrPos.x = position->x;
  this->m_CurrPos.y = v4;
  this->m_CurrPos.z = v5;
  this->m_CurrWayEdge = edge;
  this->m_CurrWayNode = node;
}

// File Line: 204
// RVA: 0xE3510
void __fastcall UFG::WayFinderClient::SetPosition(UFG::WayFinderClient *this, UFG::WayGraph *graph, UFG::qVector3 *position, UFG::qVector3 *direction)
{
  float v4; // xmm1_4
  UFG::WayGraphVtbl *v5; // rax
  UFG::WayFinderClient *v6; // rbx
  unsigned __int16 *v7; // r15
  UFG::WayGraph *v8; // r14
  float v9; // xmm0_4
  UFG::qVector3 *v10; // rdi
  UFG::qVector3 *v11; // rsi
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // [rsp+30h] [rbp-28h]
  float v17; // [rsp+34h] [rbp-24h]
  float v18; // [rsp+38h] [rbp-20h]
  unsigned int v19; // [rsp+60h] [rbp+8h]

  v4 = position->y;
  v5 = graph->vfptr;
  v6 = this;
  v7 = &this->m_CurrWayEdge;
  v8 = graph;
  v16 = position->x;
  v9 = position->z;
  v10 = position;
  v17 = v4;
  v18 = v9;
  v11 = direction;
  v19 = 0;
  if ( ((unsigned __int8 (__fastcall *)(UFG::WayGraph *, UFG::WayFinderClient *, float *))v5->GetEdgeNode)(
         graph,
         this,
         &v16) )
  {
    v6->m_CurrWayNode = v8->vfptr->GetEdgeNode(v8, *v7, v19);
  }
  v12 = v11->y;
  v13 = v11->z;
  v6->m_CurrDir.x = v11->x;
  v6->m_CurrDir.y = v12;
  v6->m_CurrDir.z = v13;
  v14 = v10->y;
  v15 = v10->z;
  v6->m_CurrPos.x = v10->x;
  v6->m_CurrPos.y = v14;
  v6->m_CurrPos.z = v15;
}

// File Line: 215
// RVA: 0xE2C90
void __fastcall UFG::WayFinderClient::Reset(UFG::WayFinderClient *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  *(_DWORD *)&this->m_CurrWayEdge = 0;
  this->m_WayStartsWithTurnAround = 0;
  v1 = UFG::qVector3::msZero.y;
  v2 = UFG::qVector3::msZero.z;
  this->m_CurrPos.x = UFG::qVector3::msZero.x;
  this->m_CurrPos.y = v1;
  this->m_CurrPos.z = v2;
  v3 = UFG::qVector3::msUnity.y;
  v4 = UFG::qVector3::msUnity.z;
  this->m_CurrDir.x = UFG::qVector3::msUnity.x;
  this->m_CurrDir.y = v3;
  this->m_CurrDir.z = v4;
}

// File Line: 224
// RVA: 0xE2CF0
void __fastcall UFG::WayFinderClient::ResetWay(UFG::WayFinderClient *this)
{
  this->m_NumWayEdges = 0;
  this->m_CurrEdgeIndex = 0;
  this->m_WayStartsWithTurnAround = 0;
}

// File Line: 231
// RVA: 0xE28E0
void __fastcall UFG::WayFinderClient::FindCurrentEdge(UFG::WayFinderClient *this)
{
  unsigned __int16 v1; // r9
  unsigned __int16 v2; // r8
  unsigned __int16 v3; // dx
  int v4; // edx
  int v5; // er11

  v1 = this->m_NumWayEdges;
  if ( v1 )
  {
    v2 = this->m_CurrWayEdge;
    if ( v2 != -1 )
    {
      v3 = this->m_CurrEdgeIndex;
      if ( v3 < v1 )
      {
        if ( v2 == this->m_WayEdges[v3] )
          return;
        v5 = v3;
        v4 = v3 + 1;
        if ( v4 >= v1 )
        {
LABEL_12:
          v4 = v5 - 1;
          if ( v5 - 1 < 0 )
            return;
          while ( v2 != this->m_WayEdges[v4] )
          {
            if ( --v4 < 0 )
              return;
          }
        }
        else
        {
          while ( v2 != this->m_WayEdges[v4] )
          {
            if ( ++v4 >= v1 )
              goto LABEL_12;
          }
        }
      }
      else
      {
        v4 = v1 - 1;
        if ( v4 < 0 )
          return;
        while ( v2 != this->m_WayEdges[v4] )
        {
          if ( --v4 < 0 )
            return;
        }
      }
      this->m_CurrEdgeIndex = v4;
    }
  }
}

// File Line: 287
// RVA: 0xE2B60
bool __fastcall UFG::WayFinderClient::LostWay(UFG::WayFinderClient *this, UFG::WayGraph *graph)
{
  UFG::WayGraph *v2; // r14
  UFG::WayFinderClient *v3; // rdi
  bool result; // al
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // bx
  __int64 v7; // rax
  unsigned __int16 *v8; // rcx
  char v9; // al

  v2 = graph;
  v3 = this;
  if ( !this->m_NumWayEdges )
    return 0;
  v5 = ((__int64 (*)(void))this->vfptr->GetWayEdge)();
  v6 = v5;
  result = v2->vfptr->IsEdge(v2, v5);
  if ( result )
  {
    v7 = v3->m_NumWayEdges - 1;
    if ( (signed int)v7 < 0 )
    {
LABEL_8:
      v9 = 0;
    }
    else
    {
      v8 = &v3->m_WayEdges[(signed int)v7];
      while ( v6 != *v8 )
      {
        --v8;
        if ( --v7 < 0 )
          goto LABEL_8;
      }
      v9 = 1;
    }
    result = v9 == 0;
  }
  return result;
}

// File Line: 306
// RVA: 0xE2C00
bool __fastcall UFG::WayFinderClient::OnWay(UFG::WayFinderClient *this, UFG::WayGraph *graph)
{
  bool result; // al
  UFG::WayGraph *v3; // rsi
  UFG::WayFinderClient *v4; // rdi
  __int64 v5; // rbx
  __int64 v6; // rax
  unsigned __int16 *v7; // rcx

  result = 0;
  v3 = graph;
  v4 = this;
  if ( this->m_NumWayEdges )
  {
    v5 = ((unsigned __int16 (*)(void))this->vfptr->GetWayEdge)();
    if ( !v3->vfptr->IsEdge(v3, v5) )
      return 1;
    v6 = v4->m_NumWayEdges - 1;
    if ( (signed int)v6 >= 0 )
    {
      v7 = &v4->m_WayEdges[(signed int)v6];
      while ( (_WORD)v5 != *v7 )
      {
        --v7;
        if ( --v6 < 0 )
          goto LABEL_7;
      }
      return 1;
    }
LABEL_7:
    result = 0;
  }
  return result;
}

// File Line: 316
// RVA: 0xE2DF0
float __usercall UFG::WayStarSearch::Service@<xmm0>(UFG::WayStarSearch *this@<rcx>, float time_limit_ms@<xmm1>, float a3@<xmm0>)
{
  float v3; // xmm10_4
  UFG::WayStarSearch *v4; // rsi
  unsigned __int64 v5; // r12
  UFG::WayGraph *v6; // r14
  __int64 l; // rbp
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *v8; // r15
  unsigned __int64 v9; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v10; // r13
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v11; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v12; // rax
  unsigned __int16 v13; // r12
  unsigned __int16 v14; // ax
  bool v15; // al
  bool v16; // al
  int v17; // ebx
  signed int v18; // edx
  signed int v19; // eax
  signed int v20; // ecx
  __int64 v21; // rdi
  unsigned __int16 v22; // bx
  bool v23; // bp
  bool v24; // cl
  float v25; // xmm6_4
  __m128 v26; // xmm1
  __int64 v27; // rbx
  float v28; // xmm6_4
  unsigned __int16 v29; // ax
  bool v30; // al
  bool v31; // r12
  float v32; // xmm7_4
  float *v33; // rax
  __m128 v34; // xmm1
  float v35; // xmm7_4
  float *v36; // rax
  float v37; // xmm0_4
  __m128 v38; // xmm1
  float v39; // xmm6_4
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *j; // rdx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *k; // r8
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v42; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v43; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v44; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v45; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v46; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v47; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v48; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v49; // rax
  int v50; // xmm7_4
  float *v51; // rax
  __m128 v52; // xmm1
  char *v53; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v54; // rcx
  bool v55; // zf
  bool v56; // sf
  UFG::WayStarNode *v57; // rdi
  UFG::WayStarNode *v58; // rax
  UFG::WayFinderClient *v59; // r15
  int v60; // ebx
  unsigned __int64 v61; // rax
  float result; // xmm0_4
  __int64 v63[2]; // [rsp+20h] [rbp-118h]
  signed int i; // [rsp+30h] [rbp-108h]
  signed int v65; // [rsp+34h] [rbp-104h]
  unsigned __int64 start; // [rsp+38h] [rbp-100h]
  BOOL v67; // [rsp+40h] [rbp-F8h]
  float v68; // [rsp+50h] [rbp-E8h]
  float v69; // [rsp+54h] [rbp-E4h]
  float v70; // [rsp+58h] [rbp-E0h]
  float v71; // [rsp+60h] [rbp-D8h]
  float v72; // [rsp+64h] [rbp-D4h]
  float v73; // [rsp+68h] [rbp-D0h]
  __int64 v74; // [rsp+70h] [rbp-C8h]
  char v75; // [rsp+78h] [rbp-C0h]
  char v76; // [rsp+84h] [rbp-B4h]
  char v77; // [rsp+90h] [rbp-A8h]
  bool v78; // [rsp+140h] [rbp+8h]
  unsigned __int16 v79; // [rsp+150h] [rbp+18h]
  unsigned __int16 v80; // [rsp+158h] [rbp+20h]

  v74 = -2i64;
  v3 = time_limit_ms;
  v4 = this;
  ++this->m_NumServices;
  v5 = UFG::qGetTicks();
  start = v5;
  v6 = v4->m_WayFinder->m_WayGraph;
  LODWORD(l) = 0;
  if ( v4->m_SearchState == WAYSTAR_SEARCHING )
  {
    v8 = &v4->m_OpenNodes;
    while ( 1 )
    {
      if ( (UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *)v4->m_OpenNodes.mNode.mNext == &v4->m_OpenNodes )
        goto LABEL_69;
      if ( v3 > 0.0 )
      {
        v9 = UFG::qGetTicks();
        a3 = UFG::qGetTickTime(v5, v9) * 1000.0;
        if ( a3 > v3 )
          goto LABEL_69;
      }
      ++v4->m_NumSteps;
      v10 = v8->mNode.mPrev;
      v11 = v8->mNode.mPrev->mPrev;
      v12 = v8->mNode.mPrev->mNext;
      v11->mNext = v12;
      v12->mPrev = v11;
      v10->mPrev = v10;
      v10->mNext = v10;
      v13 = WORD1(v10[1].mPrev);
      v79 = WORD1(v10[1].mPrev);
      v80 = (unsigned __int16)v10[1].mPrev;
      v14 = v4->m_GoalWayNode;
      v15 = -1 == v14 || v14 == v13;
      if ( v15 && v4->m_GoalWayEdge == LOWORD(v10[1].mPrev) )
        break;
      if ( -1 != v13 )
      {
        v16 = v6->vfptr->IsEdge(v6, v13);
        v78 = v16;
        v17 = 4096 - UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
        if ( v16 )
        {
          v18 = 1;
          v65 = 1;
        }
        else
        {
          v19 = v6->vfptr->GetNumNodeEdges(v6, v13);
          v18 = v19;
          v65 = v19;
          v16 = v78;
        }
        if ( v17 < v18 - 1 )
        {
          v4->m_SearchState = 2;
          goto LABEL_68;
        }
        v20 = 0;
        for ( i = 0; v20 < v18; v16 = v78 )
        {
          if ( v16 )
          {
            LOWORD(v21) = v13;
          }
          else
          {
            v21 = v6->vfptr->GetNodeEdge(v6, v13, v20);
            v20 = i;
            v18 = v65;
          }
          if ( (_WORD)v21 != v80 )
          {
            LOWORD(v63[0]) = v13;
            if ( v4->m_WayFinderClient->vfptr->CanGo(v4->m_WayFinderClient, v6, v80, v21, v63[0]) )
            {
              v22 = v13;
              if ( v78 )
                v22 = v80;
              v23 = v22 == v6->vfptr->GetEdgeNode(v6, v21, 0);
              v24 = v22 == v6->vfptr->GetEdgeNode(v6, v80, 1);
              v25 = 0.0;
              if ( !v78 )
              {
                v6->vfptr->GetEdgePosition(v6, (UFG::qVector3 *)&v71, v80, v24);
                v6->vfptr->GetEdgePosition(v6, (UFG::qVector3 *)&v68, v21, v23 == 0);
                v26 = (__m128)LODWORD(v72);
                a3 = (float)(v71 - v68) * (float)(v71 - v68);
                v26.m128_f32[0] = (float)((float)((float)(v72 - v69) * (float)(v72 - v69)) + a3)
                                + (float)((float)(v73 - v70) * (float)(v73 - v70));
                LODWORD(v25) = (unsigned __int128)_mm_sqrt_ps(v26);
              }
              v67 = v23;
              v27 = v6->vfptr->GetEdgeNode(v6, v21, v23);
              v28 = v25 + *(float *)&v10[2].mPrev;
              v29 = v4->m_GoalWayNode;
              v30 = v29 == -1 || v29 == (_WORD)v27;
              v31 = v30 && v4->m_GoalWayEdge == (_WORD)v21;
              v32 = *(float *)&FLOAT_1_0;
              if ( v31 )
              {
                v33 = (float *)v6->vfptr->GetEdgePosition(v6, (UFG::qVector3 *)&v75, v21, v23 == 0);
                v34 = (__m128)LODWORD(v4->m_GoalPosition.y);
                v34.m128_f32[0] = (float)((float)((float)(v34.m128_f32[0] - v33[1]) * (float)(v34.m128_f32[0] - v33[1]))
                                        + (float)((float)(v4->m_GoalPosition.x - *v33)
                                                * (float)(v4->m_GoalPosition.x - *v33)))
                                + (float)((float)(v4->m_GoalPosition.z - v33[2]) * (float)(v4->m_GoalPosition.z - v33[2]));
                LODWORD(v35) = (unsigned __int128)_mm_sqrt_ps(v34);
                v36 = (float *)v6->vfptr->GetEdgePosition(v6, (UFG::qVector3 *)&v76, v21, v23 != 0);
                v37 = v4->m_GoalPosition.y - v36[1];
                v38 = (__m128)LODWORD(v4->m_GoalPosition.x);
                v38.m128_f32[0] = (float)((float)((float)(v38.m128_f32[0] - *v36) * (float)(v38.m128_f32[0] - *v36))
                                        + (float)(v37 * v37))
                                + (float)((float)(v4->m_GoalPosition.z - v36[2]) * (float)(v4->m_GoalPosition.z - v36[2]));
                a3 = COERCE_FLOAT(_mm_sqrt_ps(v38)) + v35;
                v32 = v35 / a3;
              }
              v4->m_WayFinderClient->vfptr->GetEdgeLength(v4->m_WayFinderClient, v6, v21);
              a3 = a3 * v32;
              v39 = v28 + a3;
              for ( j = v4->m_OpenNodes.mNode.mNext; ; j = j->mNext )
              {
                if ( j == (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)v8 )
                {
                  LODWORD(l) = 0;
                  j = 0i64;
                  goto LABEL_45;
                }
                if ( (_WORD)v27 == WORD1(j[1].mPrev) && (_WORD)v21 == LOWORD(j[1].mPrev) )
                  break;
              }
              LODWORD(l) = 0;
              if ( v39 >= *(float *)&j[2].mPrev )
                goto LABEL_61;
LABEL_45:
              for ( k = v4->m_ClosedNodes.mNode.mNext;
                    k != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&v4->m_ClosedNodes;
                    k = k->mNext )
              {
                if ( (_WORD)v27 == WORD1(k[1].mPrev) && (_WORD)v21 == LOWORD(k[1].mPrev) )
                {
                  if ( v39 >= *(float *)&k[2].mPrev )
                    goto LABEL_61;
                  v42 = k->mPrev;
                  v43 = k->mNext;
                  v42->mNext = v43;
                  v43->mPrev = v42;
                  k->mPrev = k;
                  k->mNext = k;
                  v44 = k->mPrev;
                  v45 = k->mNext;
                  v44->mNext = v45;
                  v45->mPrev = v44;
                  k->mPrev = k;
                  k->mNext = k;
                  k->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayFinder::s_NodePool.mFreeListHead;
                  UFG::WayFinder::s_NodePool.mFreeListHead = (char *)k;
                  --UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
                  break;
                }
              }
              if ( j )
              {
                v46 = j->mPrev;
                v47 = j->mNext;
                v46->mNext = v47;
                v47->mPrev = v46;
                j->mPrev = j;
                j->mNext = j;
                v48 = j->mPrev;
                v49 = j->mNext;
                v48->mNext = v49;
                v49->mPrev = v48;
                j->mPrev = j;
                j->mNext = j;
                j->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayFinder::s_NodePool.mFreeListHead;
                UFG::WayFinder::s_NodePool.mFreeListHead = (char *)j;
                --UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
              }
              if ( v31 )
              {
                v50 = 0;
              }
              else
              {
                v51 = (float *)v6->vfptr->GetEdgePosition(v6, (UFG::qVector3 *)&v77, v21, v67);
                v52 = (__m128)*(unsigned int *)v51;
                a3 = (float)(v51[1] - v4->m_GoalPosition.y) * (float)(v51[1] - v4->m_GoalPosition.y);
                v52.m128_f32[0] = (float)((float)((float)(v52.m128_f32[0] - v4->m_GoalPosition.x)
                                                * (float)(v52.m128_f32[0] - v4->m_GoalPosition.x))
                                        + a3)
                                + (float)((float)(v51[2] - v4->m_GoalPosition.z) * (float)(v51[2] - v4->m_GoalPosition.z));
                v50 = (unsigned __int128)_mm_sqrt_ps(v52);
              }
              v53 = UFG::WayStarNode::operator new(0x28ui64);
              if ( v53 )
              {
                *(_QWORD *)v53 = v53;
                *((_QWORD *)v53 + 1) = v53;
                *((_WORD *)v53 + 8) = v21;
                *((_WORD *)v53 + 9) = v27;
                *((_QWORD *)v53 + 3) = v10;
                *((float *)v53 + 8) = v39;
                *((_DWORD *)v53 + 9) = v50;
              }
              else
              {
                v53 = 0i64;
              }
              UFG::WayStarSearch::AddOpenNode(v4, (UFG::WayStarNode *)v53);
LABEL_61:
              v13 = v79;
            }
            v18 = v65;
            v20 = i;
          }
          i = ++v20;
        }
      }
      v54 = v4->m_ClosedNodes.mNode.mNext;
      v4->m_ClosedNodes.mNode.mNext = v10;
      v10->mPrev = &v4->m_ClosedNodes.mNode;
      v10->mNext = v54;
      v54->mPrev = v10;
      v5 = start;
      v55 = v4->m_SearchState == 0;
      v56 = v4->m_SearchState < 0;
      if ( v4->m_SearchState )
        goto LABEL_73;
    }
    v4->m_SearchState = 1;
LABEL_68:
    v5 = start;
    v4->m_SolutionNode = (UFG::WayStarNode *)v10;
  }
LABEL_69:
  v55 = v4->m_SearchState == 0;
  v56 = v4->m_SearchState < 0;
  if ( v4->m_SearchState == WAYSTAR_SEARCHING )
  {
    if ( (UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *)v4->m_OpenNodes.mNode.mNext == &v4->m_OpenNodes )
    {
      v4->m_WayFinderClient->m_NumWayEdges = 0;
      v4->m_SearchState = 3;
      v4->m_SolutionNode = 0i64;
    }
    v55 = v4->m_SearchState == 0;
    v56 = v4->m_SearchState < 0;
  }
LABEL_73:
  if ( !v56 && !v55 )
  {
    v57 = v4->m_SolutionNode;
    v58 = v57;
    if ( v57 )
    {
      do
      {
        LODWORD(l) = l + 1;
        v58 = v58->m_ParentNode;
      }
      while ( v58 );
      for ( ; v57; v57 = v57->m_ParentNode )
      {
        if ( (signed int)l <= 512 )
          break;
        LODWORD(l) = l - 1;
      }
    }
    v4->m_WayFinderClient->m_NumWayEdges = l;
    v59 = v4->m_WayFinderClient;
    for ( l = (signed int)l; v57; v57 = v57->m_ParentNode )
    {
      if ( l <= 0 )
        break;
      v60 = v57->m_WayEdge;
      v59->m_WayEdges[--l] = v60;
      if ( v60 == v4->m_WayFinderClient->vfptr->GetWayEdge(v4->m_WayFinderClient, v6) )
        v4->m_WayFinderClient->vfptr->GetWayNode(v4->m_WayFinderClient, v6);
      if ( !l )
        v4->m_WayFinderClient->m_WayStartsWithTurnAround = v57 == v4->m_TurnAroundNode;
    }
  }
  v61 = UFG::qGetTicks();
  result = UFG::qGetTickTime(v5, v61) * 1000.0;
  v4->m_SearchTime = result + v4->m_SearchTime;
  return result;
}

// File Line: 526
// RVA: 0x1460B00
__int64 dynamic_initializer_for__UFG::WayFinder::s_NodePool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::WayFinder::s_NodePool);
  return atexit(dynamic_atexit_destructor_for__UFG::WayFinder::s_NodePool__);
}

// File Line: 527
// RVA: 0x1460B20
__int64 dynamic_initializer_for__UFG::WayFinder::s_SearchPool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::WayFinder::s_SearchPool);
  return atexit(dynamic_atexit_destructor_for__UFG::WayFinder::s_SearchPool__);
}

// File Line: 530
// RVA: 0xE2A60
UFG::WayFinder *__fastcall UFG::GetWayFinder()
{
  unsigned int v0; // eax
  int v1; // ecx

  v0 = _S1_16;
  if ( !(_S1_16 & 1) )
  {
    _S1_16 |= 1u;
    WayFinderDummyGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
    atexit(UFG::GetWayFinder_::_2_::_dynamic_atexit_destructor_for__WayFinderDummyGraph__);
    v0 = _S1_16;
  }
  if ( !(v0 & 2) )
  {
    _S1_16 = v0 | 2;
    gWayFinder.m_WayStarSearches.mNode.mPrev = &gWayFinder.m_WayStarSearches.mNode;
    gWayFinder.m_WayStarSearches.mNode.mNext = &gWayFinder.m_WayStarSearches.mNode;
    gWayFinder.m_WayGraph = &WayFinderDummyGraph;
    v1 = UFG::WayFinder::s_PoolReferenceCount++;
    if ( !v1 )
    {
      UFG::qFixedAllocator::Init(&UFG::WayFinder::s_NodePool, 163840, 40, "WayFinderNodes", 0i64);
      UFG::qFixedAllocator::Init(&UFG::WayFinder::s_SearchPool, 2048, 128, "WayFinderSearches", 0i64);
    }
    atexit(UFG::GetWayFinder_::_2_::_dynamic_atexit_destructor_for__gWayFinder__);
  }
  return &gWayFinder;
}

// File Line: 539
// RVA: 0xE1EF0
void __fastcall UFG::WayFinder::WayFinder(UFG::WayFinder *this, UFG::WayGraph *graph)
{
  int v2; // edx
  UFG::qList<UFG::WayStarSearch,UFG::WayStarSearch,1,0> *v3; // [rsp+58h] [rbp+10h]

  v3 = &this->m_WayStarSearches;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  this->m_WayGraph = graph;
  v2 = UFG::WayFinder::s_PoolReferenceCount++;
  if ( !v2 )
  {
    UFG::qFixedAllocator::Init(&UFG::WayFinder::s_NodePool, 163840, 40, "WayFinderNodes", 0i64);
    UFG::qFixedAllocator::Init(&UFG::WayFinder::s_SearchPool, 2048, 128, "WayFinderSearches", 0i64);
  }
}

// File Line: 550
// RVA: 0xE2460
void __fastcall UFG::WayFinder::~WayFinder(UFG::WayFinder *this)
{
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *v1; // rbx
  UFG::WayFinder *v2; // rax
  UFG::WayFinder *i; // rdi
  UFG::qList<UFG::WayStarSearch,UFG::WayStarSearch,1,0> *v4; // rdx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v5; // rcx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v6; // rax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v7; // rcx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v8; // rax

  v1 = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_WayStarSearches;
  v2 = (UFG::WayFinder *)&this->m_WayStarSearches.mNode.mNext[-1].mNext;
  for ( i = this; v2 != i; v2 = (UFG::WayFinder *)&v1->mNode.mNext[-1].mNext )
  {
    v4 = &v2->m_WayStarSearches;
    v5 = v2->m_WayStarSearches.mNode.mPrev;
    v6 = v2->m_WayStarSearches.mNode.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mNode.mPrev = &v4->mNode;
    v4->mNode.mNext = &v4->mNode;
    if ( v4 != (UFG::qList<UFG::WayStarSearch,UFG::WayStarSearch,1,0> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> **, signed __int64))v4[-1].mNode.mNext->mPrev)(
        &v4[-1].mNode.mNext,
        1i64);
  }
  if ( !--UFG::WayFinder::s_PoolReferenceCount )
  {
    UFG::qFixedAllocator::Close(&UFG::WayFinder::s_SearchPool);
    UFG::qFixedAllocator::Close(&UFG::WayFinder::s_NodePool);
  }
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes(v1);
  v7 = v1->mNode.mPrev;
  v8 = v1->mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 566
// RVA: 0xE2D10
void __fastcall UFG::WayFinder::Service(UFG::WayFinder *this, float time_limit_ms)
{
  UFG::WayFinder *v2; // rdi
  float v3; // xmm7_4
  float v4; // xmm6_4
  bool v5; // si
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v6; // rbx
  float v7; // xmm1_4
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v8; // rcx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v9; // rax

  v2 = this;
  v3 = time_limit_ms;
  v4 = 0.0;
  v5 = time_limit_ms >= 0.0;
  while ( (UFG::WayFinder *)&v2->m_WayStarSearches.mNode.mNext[-1].mNext != v2 )
  {
    if ( !v5 && v4 >= v3 )
      break;
    v6 = v2->m_WayStarSearches.mNode.mNext;
    v7 = v5 ? 0.0 : v3 - v4;
    v4 = v4 + UFG::WayStarSearch::Service((UFG::WayStarSearch *)&v6[-1].mNext, v7);
    if ( SLODWORD(v6[1].mPrev) > 0 )
    {
      v8 = v6->mPrev;
      v9 = v6->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v6->mPrev = v6;
      v6->mNext = v6;
      if ( v6 != (UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *)8 )
        ((void (__fastcall *)(UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> **, signed __int64))v6[-1].mNext->mPrev)(
          &v6[-1].mNext,
          1i64);
    }
  }
}

// File Line: 580
// RVA: 0xE27D0
void __fastcall UFG::WayFinder::Cancel(UFG::WayFinder *this, UFG::WayFinderClient *client)
{
  UFG::WayFinderClient *v2; // rdi
  UFG::WayFinder *v3; // rsi
  UFG::WayFinder *v4; // rdx
  signed __int64 v5; // rbx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v6; // rcx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v7; // rax
  UFG::qList<UFG::WayStarSearch,UFG::WayStarSearch,1,0> *v8; // rdx

  v2 = client;
  v3 = this;
  v4 = (UFG::WayFinder *)&this->m_WayStarSearches.mNode.mNext[-1].mNext;
  if ( v4 != this )
  {
    do
    {
      v5 = (signed __int64)&v4->m_WayStarSearches.mNode.mNext[-1].mNext;
      if ( v2 == (UFG::WayFinderClient *)v4[3].m_WayGraph )
      {
        v6 = v4->m_WayStarSearches.mNode.mPrev;
        v7 = v4->m_WayStarSearches.mNode.mNext;
        v8 = &v4->m_WayStarSearches;
        v6->mNext = v7;
        v7->mPrev = v6;
        v8->mNode.mPrev = &v8->mNode;
        v8->mNode.mNext = &v8->mNode;
        if ( v8 != (UFG::qList<UFG::WayStarSearch,UFG::WayStarSearch,1,0> *)8 )
          ((void (__fastcall *)(UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> **, signed __int64))v8[-1].mNode.mNext->mPrev)(
            &v8[-1].mNode.mNext,
            1i64);
        v2->m_CurrEdgeIndex = 0;
      }
      v4 = (UFG::WayFinder *)v5;
    }
    while ( (UFG::WayFinder *)v5 != v3 );
  }
}

// File Line: 608
// RVA: 0xE2980
UFG::WayStarSearch *__fastcall UFG::WayFinder::FindWay(UFG::WayFinder *this, UFG::WayFinderClient *client, UFG::qVector3 *goal_position, UFG::qVector3 *p_goal_direction)
{
  UFG::qVector3 *v4; // rbp
  UFG::qVector3 *v5; // r14
  UFG::WayFinderClient *v6; // rsi
  UFG::WayFinder *v7; // rdi
  __int64 v8; // rbx
  char *v9; // rax
  __int64 v10; // rax
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> **v11; // rdx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v12; // rcx

  v4 = p_goal_direction;
  v5 = goal_position;
  v6 = client;
  v7 = this;
  UFG::WayFinder::Cancel(this, client);
  v8 = 0i64;
  if ( UFG::WayFinder::s_SearchPool.mFreeListHead
    && (signed int)(4096 - UFG::WayFinder::s_NodePool.mNumSlotsAllocated) > 1 )
  {
    v9 = UFG::WayStarSearch::operator new(0x80ui64);
    if ( v9 )
    {
      UFG::WayStarSearch::WayStarSearch((UFG::WayStarSearch *)v9, v7, v6, v5, v4);
      v8 = v10;
    }
    v11 = (UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> **)(v8 + 8);
    v12 = v7->m_WayStarSearches.mNode.mPrev;
    v12->mNext = (UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *)(v8 + 8);
    *v11 = v12;
    v11[1] = &v7->m_WayStarSearches.mNode;
    v7->m_WayStarSearches.mNode.mPrev = (UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *)(v8 + 8);
  }
  return (UFG::WayStarSearch *)v8;
}

