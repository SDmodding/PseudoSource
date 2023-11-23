// File Line: 19
// RVA: 0xE2010
void __fastcall UFG::WayStarSearch::WayStarSearch(
        UFG::WayStarSearch *this,
        UFG::WayFinder *finder,
        UFG::WayFinderClient *client,
        UFG::qVector3 *goal_position,
        UFG::qVector3 *p_goal_direction)
{
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *p_m_OpenNodes; // r14
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::WayGraph *m_WayGraph; // rdi
  UFG::WayGraphVtbl *vfptr; // rax
  char v12; // bp
  unsigned __int16 *p_m_GoalWayEdge; // r12
  unsigned __int16 v14; // ax
  unsigned __int16 v15; // bp
  unsigned __int16 v16; // r12
  unsigned __int16 v17; // ax
  UFG::qVector3 *v18; // rax
  __m128 x_low; // xmm5
  float v20; // xmm3_4
  float v21; // xmm4_4
  __m128 v22; // xmm1
  unsigned int v23; // xmm6_4
  unsigned int v24; // xmm7_4
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v25; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v26; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *mPrev; // rax
  unsigned __int16 v28; // si
  bool v29; // zf
  UFG::WayGraphVtbl *v30; // rax
  unsigned __int16 v31; // ax
  UFG::qVector3 *v32; // rax
  float v33; // xmm4_4
  float v34; // xmm5_4
  __m128 v35; // xmm3
  __m128 v36; // xmm1
  unsigned int v37; // xmm6_4
  unsigned int v38; // xmm7_4
  UFG::WayStarNode *v39; // rax
  float v40; // [rsp+38h] [rbp-80h] BYREF
  float v41; // [rsp+3Ch] [rbp-7Ch]
  float v42; // [rsp+40h] [rbp-78h]
  char v43[24]; // [rsp+48h] [rbp-70h] BYREF

  this->mPrev = &this->UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch>;
  this->mNext = &this->UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch>;
  this->vfptr = (UFG::WayStarSearchVtbl *)&UFG::WayStarSearch::`vftable;
  p_m_OpenNodes = &this->m_OpenNodes;
  this->m_OpenNodes.mNode.mPrev = &this->m_OpenNodes.mNode;
  this->m_OpenNodes.mNode.mNext = &this->m_OpenNodes.mNode;
  this->m_ClosedNodes.mNode.mPrev = &this->m_ClosedNodes.mNode;
  this->m_ClosedNodes.mNode.mNext = &this->m_ClosedNodes.mNode;
  this->m_WayFinder = finder;
  this->m_WayFinderClient = client;
  y = goal_position->y;
  z = goal_position->z;
  this->m_GoalPosition.x = goal_position->x;
  this->m_GoalPosition.y = y;
  this->m_GoalPosition.z = z;
  *(_QWORD *)&this->m_NumServices = 0i64;
  this->m_SolutionNode = 0i64;
  this->m_TurnAroundNode = 0i64;
  this->m_SearchTime = 0.0;
  this->m_SearchState = WAYSTAR_SEARCHING;
  m_WayGraph = finder->m_WayGraph;
  vfptr = finder->m_WayGraph->vfptr;
  if ( p_goal_direction )
  {
    p_m_GoalWayEdge = &this->m_GoalWayEdge;
    v12 = ((__int64 (__fastcall *)(UFG::WayGraph *, UFG::WayFinderClient *, UFG::qVector3 *))vfptr->GetEdgeNode)(
            m_WayGraph,
            client,
            &this->m_GoalPosition);
    if ( v12 )
      v14 = m_WayGraph->vfptr->GetEdgeNode(m_WayGraph, *p_m_GoalWayEdge, 0);
    else
      v14 = -1;
    this->m_GoalWayNode = v14;
  }
  else
  {
    v12 = vfptr->GetEdge(m_WayGraph, client, &this->m_GoalPosition, &this->m_GoalWayEdge);
    this->m_GoalWayNode = -1;
  }
  client->vfptr->ResetWay(client);
  if ( v12
    && (v15 = client->vfptr->GetWayEdge(client, m_WayGraph),
        v16 = client->vfptr->GetWayNode(client, m_WayGraph),
        m_WayGraph->vfptr->IsEdge(m_WayGraph, v15))
    && v16 != 0xFFFF )
  {
    client->vfptr->GetPosition(client, (UFG::qVector3 *)&v40);
    v17 = m_WayGraph->vfptr->GetEdgeNode(m_WayGraph, v15, 1);
    v18 = m_WayGraph->vfptr->GetEdgePosition(m_WayGraph, (UFG::qVector3 *)v43, v15, v16 == v17);
    x_low = (__m128)LODWORD(v18->x);
    v20 = v18->y;
    v21 = v18->z;
    v22 = (__m128)LODWORD(v40);
    v22.m128_f32[0] = (float)((float)((float)(v40 - x_low.m128_f32[0]) * (float)(v40 - x_low.m128_f32[0]))
                            + (float)((float)(v41 - v20) * (float)(v41 - v20)))
                    + (float)((float)(v42 - v21) * (float)(v42 - v21));
    v23 = _mm_sqrt_ps(v22).m128_u32[0];
    x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - this->m_GoalPosition.x)
                                      * (float)(x_low.m128_f32[0] - this->m_GoalPosition.x))
                              + (float)((float)(v20 - this->m_GoalPosition.y) * (float)(v20 - this->m_GoalPosition.y)))
                      + (float)((float)(v21 - this->m_GoalPosition.z) * (float)(v21 - this->m_GoalPosition.z));
    v24 = _mm_sqrt_ps(x_low).m128_u32[0];
    v25 = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayStarNode::operator new(0x28ui64);
    v26 = v25;
    if ( v25 )
    {
      v25->mPrev = v25;
      v25->mNext = v25;
      LOWORD(v25[1].mPrev) = v15;
      WORD1(v25[1].mPrev) = v16;
      v25[1].mNext = 0i64;
      LODWORD(v25[2].mPrev) = v23;
      HIDWORD(v25[2].mPrev) = v24;
    }
    else
    {
      v26 = 0i64;
    }
    mPrev = p_m_OpenNodes->mNode.mPrev;
    mPrev->mNext = v26;
    v26->mPrev = mPrev;
    v26->mNext = &p_m_OpenNodes->mNode;
    p_m_OpenNodes->mNode.mPrev = v26;
    if ( (*((unsigned __int8 (__fastcall **)(UFG::WayFinderClient *))&client->vfptr->__vecDelDtor + 1))(client) )
    {
      v28 = m_WayGraph->vfptr->GetEdgeNode(m_WayGraph, v15, 0);
      if ( v28 == v16 )
        v28 = m_WayGraph->vfptr->GetEdgeNode(m_WayGraph, v15, 1);
      if ( v28 != 0xFFFF )
      {
        v29 = !m_WayGraph->vfptr->IsEdge(m_WayGraph, v28);
        v30 = m_WayGraph->vfptr;
        if ( v29 )
        {
          v32 = v30->GetNodePosition(m_WayGraph, (UFG::qVector3 *)v43, v28);
        }
        else
        {
          v31 = v30->GetEdgeNode(m_WayGraph, v15, 1);
          v32 = m_WayGraph->vfptr->GetEdgePosition(m_WayGraph, (UFG::qVector3 *)v43, v15, v28 == v31);
        }
        v33 = v32->z;
        v34 = v32->y;
        v35 = (__m128)LODWORD(v32->x);
        v36 = (__m128)LODWORD(v40);
        v36.m128_f32[0] = (float)((float)((float)(v40 - v35.m128_f32[0]) * (float)(v40 - v35.m128_f32[0]))
                                + (float)((float)(v41 - v34) * (float)(v41 - v34)))
                        + (float)((float)(v42 - v33) * (float)(v42 - v33));
        v37 = _mm_sqrt_ps(v36).m128_u32[0];
        v35.m128_f32[0] = (float)((float)((float)(v35.m128_f32[0] - this->m_GoalPosition.x)
                                        * (float)(v35.m128_f32[0] - this->m_GoalPosition.x))
                                + (float)((float)(v34 - this->m_GoalPosition.y) * (float)(v34 - this->m_GoalPosition.y)))
                        + (float)((float)(v33 - this->m_GoalPosition.z) * (float)(v33 - this->m_GoalPosition.z));
        v38 = _mm_sqrt_ps(v35).m128_u32[0];
        v39 = (UFG::WayStarNode *)UFG::WayStarNode::operator new(0x28ui64);
        if ( v39 )
        {
          v39->mPrev = v39;
          v39->mNext = v39;
          v39->m_WayEdge = v15;
          v39->m_WayNode = v28;
          v39->m_ParentNode = 0i64;
          LODWORD(v39->m_ActualCost) = v37;
          LODWORD(v39->m_EstimatedCost) = v38;
        }
        else
        {
          v39 = 0i64;
        }
        this->m_TurnAroundNode = v39;
        UFG::WayStarSearch::AddOpenNode(this, v39);
      }
    }
  }
  else
  {
    this->m_SearchState = WAYSTAR_NO_WAY;
  }
}

// File Line: 133
// RVA: 0xE2530
void __fastcall UFG::WayStarSearch::~WayStarSearch(UFG::WayStarSearch *this)
{
  UFG::WayStarNode *m_SolutionNode; // rdx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *mPrev; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *mNext; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v5; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v6; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v7; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v8; // rax
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v9; // rcx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v10; // rax

  this->vfptr = (UFG::WayStarSearchVtbl *)&UFG::WayStarSearch::`vftable;
  m_SolutionNode = this->m_SolutionNode;
  if ( m_SolutionNode )
  {
    mPrev = m_SolutionNode->mPrev;
    mNext = m_SolutionNode->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    m_SolutionNode->mPrev = m_SolutionNode;
    m_SolutionNode->mNext = m_SolutionNode;
    m_SolutionNode->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayFinder::s_NodePool.mFreeListHead;
    UFG::WayFinder::s_NodePool.mFreeListHead = (char *)m_SolutionNode;
    --UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
  }
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0>::DeleteNodes(&this->m_ClosedNodes);
  v5 = this->m_ClosedNodes.mNode.mPrev;
  v6 = this->m_ClosedNodes.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->m_ClosedNodes.mNode.mPrev = &this->m_ClosedNodes.mNode;
  this->m_ClosedNodes.mNode.mNext = &this->m_ClosedNodes.mNode;
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0>::DeleteNodes(&this->m_OpenNodes);
  v7 = this->m_OpenNodes.mNode.mPrev;
  v8 = this->m_OpenNodes.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->m_OpenNodes.mNode.mPrev = &this->m_OpenNodes.mNode;
  this->m_OpenNodes.mNode.mNext = &this->m_OpenNodes.mNode;
  v9 = this->mPrev;
  v10 = this->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  this->mPrev = &this->UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch>;
  this->mNext = &this->UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch>;
}

// File Line: 176
// RVA: 0xE2780
void __fastcall UFG::WayStarSearch::AddOpenNode(UFG::WayStarSearch *this, UFG::WayStarNode *to_add)
{
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *mNext; // r8
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *i; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *mPrev; // rax

  mNext = this->m_OpenNodes.mNode.mNext;
  for ( i = &this->m_OpenNodes; mNext != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)i; mNext = mNext->mNext )
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

// File Line: 186
// RVA: 0xE1F90
void __fastcall UFG::WayFinderClient::WayFinderClient(UFG::WayFinderClient *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  this->vfptr = (UFG::WayFinderClientVtbl *)&UFG::WayFinderClient::`vftable;
  this->m_WayStartsWithTurnAround = 0;
  *(_DWORD *)&this->m_CurrWayEdge = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_CurrPos.x = UFG::qVector3::msZero.x;
  this->m_CurrPos.y = y;
  this->m_CurrPos.z = z;
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
void __fastcall UFG::WayFinderClient::GetEdgeLength(
        UFG::WayFinderClient *this,
        UFG::WayGraph *wayGraph,
        unsigned __int16 wayEdge)
{
  wayGraph->vfptr->GetEdgeLength(wayGraph, wayEdge);
}

// File Line: 197
// RVA: 0xE34E0
void __fastcall UFG::WayFinderClient::SetPosition(
        UFG::WayFinderClient *this,
        UFG::qVector3 *position,
        unsigned __int16 edge,
        unsigned __int16 node)
{
  float y; // xmm0_4
  float z; // xmm1_4

  y = position->y;
  z = position->z;
  this->m_CurrPos.x = position->x;
  this->m_CurrPos.y = y;
  this->m_CurrPos.z = z;
  this->m_CurrWayEdge = edge;
  this->m_CurrWayNode = node;
}

// File Line: 204
// RVA: 0xE3510
void __fastcall UFG::WayFinderClient::SetPosition(
        UFG::WayFinderClient *this,
        UFG::WayGraph *graph,
        UFG::qVector3 *position,
        UFG::qVector3 *direction)
{
  float y; // xmm1_4
  UFG::WayGraphVtbl *vfptr; // rax
  unsigned __int16 *p_m_CurrWayEdge; // r15
  float z; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  int v16[10]; // [rsp+30h] [rbp-28h] BYREF

  y = position->y;
  vfptr = graph->vfptr;
  p_m_CurrWayEdge = &this->m_CurrWayEdge;
  v16[0] = LODWORD(position->x);
  z = position->z;
  *(float *)&v16[1] = y;
  *(float *)&v16[2] = z;
  if ( ((unsigned __int8 (__fastcall *)(UFG::WayGraph *, UFG::WayFinderClient *, int *))vfptr->GetEdgeNode)(
         graph,
         this,
         v16) )
  {
    this->m_CurrWayNode = graph->vfptr->GetEdgeNode(graph, *p_m_CurrWayEdge, 0);
  }
  v12 = direction->y;
  v13 = direction->z;
  this->m_CurrDir.x = direction->x;
  this->m_CurrDir.y = v12;
  this->m_CurrDir.z = v13;
  v14 = position->y;
  v15 = position->z;
  this->m_CurrPos.x = position->x;
  this->m_CurrPos.y = v14;
  this->m_CurrPos.z = v15;
}

// File Line: 215
// RVA: 0xE2C90
void __fastcall UFG::WayFinderClient::Reset(UFG::WayFinderClient *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4

  *(_DWORD *)&this->m_CurrWayEdge = 0;
  this->m_WayStartsWithTurnAround = 0;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_CurrPos.x = UFG::qVector3::msZero.x;
  this->m_CurrPos.y = y;
  this->m_CurrPos.z = z;
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
  unsigned __int16 m_NumWayEdges; // r9
  unsigned __int16 m_CurrWayEdge; // r8
  unsigned __int16 m_CurrEdgeIndex; // dx
  int v4; // edx
  int v5; // r11d

  m_NumWayEdges = this->m_NumWayEdges;
  if ( m_NumWayEdges )
  {
    m_CurrWayEdge = this->m_CurrWayEdge;
    if ( m_CurrWayEdge != 0xFFFF )
    {
      m_CurrEdgeIndex = this->m_CurrEdgeIndex;
      if ( m_CurrEdgeIndex < m_NumWayEdges )
      {
        if ( m_CurrWayEdge == this->m_WayEdges[m_CurrEdgeIndex] )
          return;
        v5 = m_CurrEdgeIndex;
        v4 = m_CurrEdgeIndex + 1;
        if ( v4 >= m_NumWayEdges )
        {
LABEL_12:
          v4 = v5 - 1;
          if ( v5 - 1 < 0 )
            return;
          while ( m_CurrWayEdge != this->m_WayEdges[v4] )
          {
            if ( --v4 < 0 )
              return;
          }
        }
        else
        {
          while ( m_CurrWayEdge != this->m_WayEdges[v4] )
          {
            if ( ++v4 >= m_NumWayEdges )
              goto LABEL_12;
          }
        }
      }
      else
      {
        v4 = m_NumWayEdges - 1;
        if ( v4 < 0 )
          return;
        while ( m_CurrWayEdge != this->m_WayEdges[v4] )
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
  bool result; // al
  __int64 v5; // rbx
  __int64 v6; // rax
  unsigned __int16 *v7; // rcx
  char v8; // al

  if ( !this->m_NumWayEdges )
    return 0;
  v5 = ((unsigned __int16 (*)(void))this->vfptr->GetWayEdge)();
  result = graph->vfptr->IsEdge(graph, v5);
  if ( result )
  {
    v6 = this->m_NumWayEdges - 1;
    if ( (int)v6 < 0 )
    {
LABEL_8:
      v8 = 0;
    }
    else
    {
      v7 = &this->m_WayEdges[(int)v6];
      while ( (_WORD)v5 != *v7 )
      {
        --v7;
        if ( --v6 < 0 )
          goto LABEL_8;
      }
      v8 = 1;
    }
    return v8 == 0;
  }
  return result;
}

// File Line: 306
// RVA: 0xE2C00
bool __fastcall UFG::WayFinderClient::OnWay(UFG::WayFinderClient *this, UFG::WayGraph *graph)
{
  bool result; // al
  __int64 v5; // rbx
  __int64 v6; // rax
  unsigned __int16 *i; // rcx

  result = 0;
  if ( this->m_NumWayEdges )
  {
    v5 = ((unsigned __int16 (*)(void))this->vfptr->GetWayEdge)();
    if ( !graph->vfptr->IsEdge(graph, v5) )
      return 1;
    v6 = this->m_NumWayEdges - 1;
    if ( (int)v6 >= 0 )
    {
      for ( i = &this->m_WayEdges[(int)v6]; (_WORD)v5 != *i; --i )
      {
        if ( --v6 < 0 )
          return 0;
      }
      return 1;
    }
    return 0;
  }
  return result;
}

// File Line: 316
// RVA: 0xE2DF0
float __fastcall UFG::WayStarSearch::Service(UFG::WayStarSearch *this, float time_limit_ms)
{
  unsigned __int64 Ticks; // r12
  UFG::WayGraph *m_WayGraph; // r14
  __int64 m; // rbp
  UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *p_m_OpenNodes; // r15
  unsigned __int64 v8; // rax
  UFG::WayStarNode *mPrev; // r13
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v10; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *mNext; // rax
  unsigned __int16 m_WayNode; // r12
  unsigned __int16 m_GoalWayNode; // ax
  bool v14; // al
  bool v15; // al
  signed int v16; // ebx
  int v17; // edx
  int v18; // ecx
  unsigned __int16 v19; // di
  unsigned __int16 v20; // bx
  bool v21; // bp
  bool v22; // cl
  float v23; // xmm6_4
  __m128 v24; // xmm1
  unsigned __int16 v25; // bx
  float v26; // xmm6_4
  unsigned __int16 v27; // ax
  bool v28; // al
  bool v29; // r12
  float v30; // xmm7_4
  float *v31; // rax
  __m128 y_low; // xmm1
  float v33; // xmm7_4
  float *v34; // rax
  float v35; // xmm0_4
  __m128 x_low; // xmm1
  float v37; // xmm6_4
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *j; // rdx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *k; // r8
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v40; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v41; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v42; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v43; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v44; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v45; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v46; // rcx
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v47; // rax
  unsigned int v48; // xmm7_4
  UFG::qVector3 *v49; // rax
  __m128 v50; // xmm1
  char *v51; // rax
  UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *v52; // rcx
  bool v53; // cc
  UFG::WayStarNode *m_SolutionNode; // rdi
  UFG::WayStarNode *v55; // rax
  UFG::WayFinderClient *m_WayFinderClient; // r15
  int v57; // ebx
  unsigned __int64 v58; // rax
  float result; // xmm0_4
  int v60; // [rsp+20h] [rbp-118h]
  int i; // [rsp+30h] [rbp-108h]
  int v62; // [rsp+34h] [rbp-104h]
  unsigned __int64 start; // [rsp+38h] [rbp-100h]
  BOOL v64; // [rsp+40h] [rbp-F8h]
  float v65; // [rsp+50h] [rbp-E8h] BYREF
  float v66; // [rsp+54h] [rbp-E4h]
  float v67; // [rsp+58h] [rbp-E0h]
  float v68; // [rsp+60h] [rbp-D8h] BYREF
  float v69; // [rsp+64h] [rbp-D4h]
  float v70; // [rsp+68h] [rbp-D0h]
  __int64 v71; // [rsp+70h] [rbp-C8h]
  UFG::qVector3 v72; // [rsp+78h] [rbp-C0h] BYREF
  UFG::qVector3 v73; // [rsp+84h] [rbp-B4h] BYREF
  char v74; // [rsp+90h] [rbp-A8h] BYREF
  bool v75; // [rsp+140h] [rbp+8h]
  unsigned __int16 v76; // [rsp+150h] [rbp+18h]
  unsigned __int16 m_WayEdge; // [rsp+158h] [rbp+20h]

  v71 = -2i64;
  ++this->m_NumServices;
  Ticks = UFG::qGetTicks();
  start = Ticks;
  m_WayGraph = this->m_WayFinder->m_WayGraph;
  LODWORD(m) = 0;
  if ( this->m_SearchState == WAYSTAR_SEARCHING )
  {
    p_m_OpenNodes = &this->m_OpenNodes;
    while ( 1 )
    {
      if ( (UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *)this->m_OpenNodes.mNode.mNext == &this->m_OpenNodes )
        goto LABEL_69;
      if ( time_limit_ms > 0.0 )
      {
        v8 = UFG::qGetTicks();
        if ( (float)(UFG::qGetTickTime(Ticks, v8) * 1000.0) > time_limit_ms )
          goto LABEL_69;
      }
      ++this->m_NumSteps;
      mPrev = (UFG::WayStarNode *)p_m_OpenNodes->mNode.mPrev;
      v10 = p_m_OpenNodes->mNode.mPrev->mPrev;
      mNext = p_m_OpenNodes->mNode.mPrev->mNext;
      v10->mNext = mNext;
      mNext->mPrev = v10;
      mPrev->mPrev = mPrev;
      mPrev->mNext = mPrev;
      m_WayNode = mPrev->m_WayNode;
      v76 = m_WayNode;
      m_WayEdge = mPrev->m_WayEdge;
      m_GoalWayNode = this->m_GoalWayNode;
      v14 = m_GoalWayNode == 0xFFFF || m_GoalWayNode == m_WayNode;
      if ( v14 && this->m_GoalWayEdge == mPrev->m_WayEdge )
        break;
      if ( m_WayNode != 0xFFFF )
      {
        v15 = m_WayGraph->vfptr->IsEdge(m_WayGraph, m_WayNode);
        v75 = v15;
        v16 = 4096 - UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
        if ( v15 )
        {
          v17 = 1;
          v62 = 1;
        }
        else
        {
          v17 = m_WayGraph->vfptr->GetNumNodeEdges(m_WayGraph, m_WayNode);
          v62 = v17;
          v15 = 0;
        }
        if ( v16 < v17 - 1 )
        {
          this->m_SearchState = WAYSTAR_PART_WAY;
          goto LABEL_68;
        }
        v18 = 0;
        for ( i = 0; v18 < v17; v15 = v75 )
        {
          if ( v15 )
          {
            v19 = m_WayNode;
          }
          else
          {
            v19 = m_WayGraph->vfptr->GetNodeEdge(m_WayGraph, m_WayNode, v18);
            v18 = i;
            v17 = v62;
          }
          if ( v19 != m_WayEdge )
          {
            LOWORD(v60) = m_WayNode;
            if ( this->m_WayFinderClient->vfptr->CanGo(this->m_WayFinderClient, m_WayGraph, m_WayEdge, v19, v60) )
            {
              v20 = m_WayNode;
              if ( v75 )
                v20 = m_WayEdge;
              v21 = v20 == m_WayGraph->vfptr->GetEdgeNode(m_WayGraph, v19, 0);
              v22 = v20 == m_WayGraph->vfptr->GetEdgeNode(m_WayGraph, m_WayEdge, 1);
              v23 = 0.0;
              if ( !v75 )
              {
                m_WayGraph->vfptr->GetEdgePosition(m_WayGraph, (UFG::qVector3 *)&v68, m_WayEdge, v22);
                m_WayGraph->vfptr->GetEdgePosition(m_WayGraph, (UFG::qVector3 *)&v65, v19, !v21);
                v24 = (__m128)LODWORD(v69);
                v24.m128_f32[0] = (float)((float)((float)(v69 - v66) * (float)(v69 - v66))
                                        + (float)((float)(v68 - v65) * (float)(v68 - v65)))
                                + (float)((float)(v70 - v67) * (float)(v70 - v67));
                LODWORD(v23) = _mm_sqrt_ps(v24).m128_u32[0];
              }
              v64 = v21;
              v25 = m_WayGraph->vfptr->GetEdgeNode(m_WayGraph, v19, v21);
              v26 = v23 + mPrev->m_ActualCost;
              v27 = this->m_GoalWayNode;
              v28 = v27 == 0xFFFF || v27 == v25;
              v29 = v28 && this->m_GoalWayEdge == v19;
              v30 = *(float *)&FLOAT_1_0;
              if ( v29 )
              {
                v31 = (float *)m_WayGraph->vfptr->GetEdgePosition(m_WayGraph, &v72, v19, !v21);
                y_low = (__m128)LODWORD(this->m_GoalPosition.y);
                y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v31[1])
                                                  * (float)(y_low.m128_f32[0] - v31[1]))
                                          + (float)((float)(this->m_GoalPosition.x - *v31)
                                                  * (float)(this->m_GoalPosition.x - *v31)))
                                  + (float)((float)(this->m_GoalPosition.z - v31[2])
                                          * (float)(this->m_GoalPosition.z - v31[2]));
                v33 = _mm_sqrt_ps(y_low).m128_f32[0];
                v34 = (float *)m_WayGraph->vfptr->GetEdgePosition(m_WayGraph, &v73, v19, v21);
                v35 = this->m_GoalPosition.y - v34[1];
                x_low = (__m128)LODWORD(this->m_GoalPosition.x);
                x_low.m128_f32[0] = (float)((float)((float)(x_low.m128_f32[0] - *v34) * (float)(x_low.m128_f32[0] - *v34))
                                          + (float)(v35 * v35))
                                  + (float)((float)(this->m_GoalPosition.z - v34[2])
                                          * (float)(this->m_GoalPosition.z - v34[2]));
                v30 = v33 / (float)(_mm_sqrt_ps(x_low).m128_f32[0] + v33);
              }
              v37 = v26
                  + (float)(this->m_WayFinderClient->vfptr->GetEdgeLength(this->m_WayFinderClient, m_WayGraph, v19) * v30);
              for ( j = this->m_OpenNodes.mNode.mNext; ; j = j->mNext )
              {
                if ( j == (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)p_m_OpenNodes )
                {
                  LODWORD(m) = 0;
                  j = 0i64;
                  goto LABEL_45;
                }
                if ( v25 == WORD1(j[1].mPrev) && v19 == LOWORD(j[1].mPrev) )
                  break;
              }
              LODWORD(m) = 0;
              if ( v37 >= *(float *)&j[2].mPrev )
                goto LABEL_61;
LABEL_45:
              for ( k = this->m_ClosedNodes.mNode.mNext;
                    k != (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)&this->m_ClosedNodes;
                    k = k->mNext )
              {
                if ( v25 == WORD1(k[1].mPrev) && v19 == LOWORD(k[1].mPrev) )
                {
                  if ( v37 >= *(float *)&k[2].mPrev )
                    goto LABEL_61;
                  v40 = k->mPrev;
                  v41 = k->mNext;
                  v40->mNext = v41;
                  v41->mPrev = v40;
                  k->mPrev = k;
                  k->mNext = k;
                  v42 = k->mPrev;
                  v43 = k->mNext;
                  v42->mNext = v43;
                  v43->mPrev = v42;
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
                v44 = j->mPrev;
                v45 = j->mNext;
                v44->mNext = v45;
                v45->mPrev = v44;
                j->mPrev = j;
                j->mNext = j;
                v46 = j->mPrev;
                v47 = j->mNext;
                v46->mNext = v47;
                v47->mPrev = v46;
                j->mPrev = j;
                j->mNext = j;
                j->mPrev = (UFG::qNode<UFG::WayStarNode,UFG::WayStarNode> *)UFG::WayFinder::s_NodePool.mFreeListHead;
                UFG::WayFinder::s_NodePool.mFreeListHead = (char *)j;
                --UFG::WayFinder::s_NodePool.mNumSlotsAllocated;
              }
              if ( v29 )
              {
                v48 = 0;
              }
              else
              {
                v49 = m_WayGraph->vfptr->GetEdgePosition(m_WayGraph, (UFG::qVector3 *)&v74, v19, v64);
                v50 = (__m128)LODWORD(v49->x);
                v50.m128_f32[0] = (float)((float)((float)(v50.m128_f32[0] - this->m_GoalPosition.x)
                                                * (float)(v50.m128_f32[0] - this->m_GoalPosition.x))
                                        + (float)((float)(v49->y - this->m_GoalPosition.y)
                                                * (float)(v49->y - this->m_GoalPosition.y)))
                                + (float)((float)(v49->z - this->m_GoalPosition.z)
                                        * (float)(v49->z - this->m_GoalPosition.z));
                v48 = _mm_sqrt_ps(v50).m128_u32[0];
              }
              v51 = UFG::WayStarNode::operator new(0x28ui64);
              if ( v51 )
              {
                *(_QWORD *)v51 = v51;
                *((_QWORD *)v51 + 1) = v51;
                *((_WORD *)v51 + 8) = v19;
                *((_WORD *)v51 + 9) = v25;
                *((_QWORD *)v51 + 3) = mPrev;
                *((float *)v51 + 8) = v37;
                *((_DWORD *)v51 + 9) = v48;
              }
              else
              {
                v51 = 0i64;
              }
              UFG::WayStarSearch::AddOpenNode(this, (UFG::WayStarNode *)v51);
LABEL_61:
              m_WayNode = v76;
            }
            v17 = v62;
            v18 = i;
          }
          i = ++v18;
        }
      }
      v52 = this->m_ClosedNodes.mNode.mNext;
      this->m_ClosedNodes.mNode.mNext = mPrev;
      mPrev->mPrev = &this->m_ClosedNodes.mNode;
      mPrev->mNext = v52;
      v52->mPrev = mPrev;
      Ticks = start;
      v53 = this->m_SearchState <= WAYSTAR_SEARCHING;
      if ( this->m_SearchState )
        goto LABEL_73;
    }
    this->m_SearchState = WAYSTAR_FULL_WAY;
LABEL_68:
    Ticks = start;
    this->m_SolutionNode = mPrev;
  }
LABEL_69:
  v53 = this->m_SearchState <= WAYSTAR_SEARCHING;
  if ( this->m_SearchState == WAYSTAR_SEARCHING )
  {
    if ( (UFG::qList<UFG::WayStarNode,UFG::WayStarNode,1,0> *)this->m_OpenNodes.mNode.mNext == &this->m_OpenNodes )
    {
      this->m_WayFinderClient->m_NumWayEdges = 0;
      this->m_SearchState = WAYSTAR_NO_WAY;
      this->m_SolutionNode = 0i64;
    }
    v53 = this->m_SearchState <= WAYSTAR_SEARCHING;
  }
LABEL_73:
  if ( !v53 )
  {
    m_SolutionNode = this->m_SolutionNode;
    v55 = m_SolutionNode;
    if ( m_SolutionNode )
    {
      do
      {
        LODWORD(m) = m + 1;
        v55 = v55->m_ParentNode;
      }
      while ( v55 );
      do
      {
        if ( (int)m <= 512 )
          break;
        LODWORD(m) = m - 1;
        m_SolutionNode = m_SolutionNode->m_ParentNode;
      }
      while ( m_SolutionNode );
    }
    this->m_WayFinderClient->m_NumWayEdges = m;
    m_WayFinderClient = this->m_WayFinderClient;
    for ( m = (int)m; m_SolutionNode; m_SolutionNode = m_SolutionNode->m_ParentNode )
    {
      if ( m <= 0 )
        break;
      v57 = m_SolutionNode->m_WayEdge;
      m_WayFinderClient->m_WayEdges[--m] = v57;
      if ( v57 == this->m_WayFinderClient->vfptr->GetWayEdge(this->m_WayFinderClient, m_WayGraph) )
        this->m_WayFinderClient->vfptr->GetWayNode(this->m_WayFinderClient, m_WayGraph);
      if ( !m )
        this->m_WayFinderClient->m_WayStartsWithTurnAround = m_SolutionNode == this->m_TurnAroundNode;
    }
  }
  v58 = UFG::qGetTicks();
  result = UFG::qGetTickTime(Ticks, v58) * 1000.0;
  this->m_SearchTime = result + this->m_SearchTime;
  return result;
}

// File Line: 526
// RVA: 0x1460B00
__int64 dynamic_initializer_for__UFG::WayFinder::s_NodePool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::WayFinder::s_NodePool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WayFinder::s_NodePool__);
}

// File Line: 527
// RVA: 0x1460B20
__int64 dynamic_initializer_for__UFG::WayFinder::s_SearchPool__()
{
  UFG::qFixedAllocator::qFixedAllocator(&UFG::WayFinder::s_SearchPool);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WayFinder::s_SearchPool__);
}

// File Line: 530
// RVA: 0xE2A60
UFG::WayFinder *__fastcall UFG::GetWayFinder()
{
  unsigned int v0; // eax

  v0 = _S1_16;
  if ( (_S1_16 & 1) == 0 )
  {
    _S1_16 |= 1u;
    WayFinderDummyGraph.vfptr = (UFG::WayGraphVtbl *)&UFG::WayGraph::`vftable;
    atexit(UFG::GetWayFinder_::_2_::_dynamic_atexit_destructor_for__WayFinderDummyGraph__);
    v0 = _S1_16;
  }
  if ( (v0 & 2) == 0 )
  {
    _S1_16 = v0 | 2;
    gWayFinder.m_WayStarSearches.mNode.mPrev = &gWayFinder.m_WayStarSearches.mNode;
    gWayFinder.m_WayStarSearches.mNode.mNext = &gWayFinder.m_WayStarSearches.mNode;
    gWayFinder.m_WayGraph = &WayFinderDummyGraph;
    if ( !UFG::WayFinder::s_PoolReferenceCount++ )
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
  this->m_WayStarSearches.mNode.mPrev = &this->m_WayStarSearches.mNode;
  this->m_WayStarSearches.mNode.mNext = &this->m_WayStarSearches.mNode;
  this->m_WayGraph = graph;
  if ( !UFG::WayFinder::s_PoolReferenceCount++ )
  {
    UFG::qFixedAllocator::Init(&UFG::WayFinder::s_NodePool, 163840, 40, "WayFinderNodes", 0i64);
    UFG::qFixedAllocator::Init(&UFG::WayFinder::s_SearchPool, 2048, 128, "WayFinderSearches", 0i64);
  }
}

// File Line: 550
// RVA: 0xE2460
void __fastcall UFG::WayFinder::~WayFinder(UFG::WayFinder *this)
{
  UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *p_m_WayStarSearches; // rbx
  UFG::WayFinder *i; // rax
  UFG::qList<UFG::WayStarSearch,UFG::WayStarSearch,1,0> *v4; // rdx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *mPrev; // rcx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *mNext; // rax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v7; // rcx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v8; // rax

  p_m_WayStarSearches = (UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_WayStarSearches;
  for ( i = (UFG::WayFinder *)&this->m_WayStarSearches.mNode.mNext[-1].mNext;
        i != this;
        i = (UFG::WayFinder *)&p_m_WayStarSearches->mNode.mNext[-1].mNext )
  {
    v4 = &i->m_WayStarSearches;
    mPrev = i->m_WayStarSearches.mNode.mPrev;
    mNext = i->m_WayStarSearches.mNode.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v4->mNode.mPrev = &v4->mNode;
    v4->mNode.mNext = &v4->mNode;
    if ( v4 != (UFG::qList<UFG::WayStarSearch,UFG::WayStarSearch,1,0> *)8 )
      ((void (__fastcall *)(UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> **, __int64))v4[-1].mNode.mNext->mPrev)(
        &v4[-1].mNode.mNext,
        1i64);
  }
  if ( !--UFG::WayFinder::s_PoolReferenceCount )
  {
    UFG::qFixedAllocator::Close(&UFG::WayFinder::s_SearchPool);
    UFG::qFixedAllocator::Close(&UFG::WayFinder::s_NodePool);
  }
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes(p_m_WayStarSearches);
  v7 = p_m_WayStarSearches->mNode.mPrev;
  v8 = p_m_WayStarSearches->mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  p_m_WayStarSearches->mNode.mPrev = &p_m_WayStarSearches->mNode;
  p_m_WayStarSearches->mNode.mNext = &p_m_WayStarSearches->mNode;
}

// File Line: 566
// RVA: 0xE2D10
void __fastcall UFG::WayFinder::Service(UFG::WayFinder *this, float time_limit_ms)
{
  float v4; // xmm6_4
  bool v5; // si
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *mNext; // rbx
  float v7; // xmm1_4
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *mPrev; // rcx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *v9; // rax

  v4 = 0.0;
  v5 = time_limit_ms >= 0.0;
  while ( (UFG::WayFinder *)&this->m_WayStarSearches.mNode.mNext[-1].mNext != this )
  {
    if ( !v5 && v4 >= time_limit_ms )
      break;
    mNext = this->m_WayStarSearches.mNode.mNext;
    v7 = v5 ? 0.0 : time_limit_ms - v4;
    v4 = v4 + UFG::WayStarSearch::Service((UFG::WayStarSearch *)&mNext[-1].mNext, v7);
    if ( SLODWORD(mNext[1].mPrev) > 0 )
    {
      mPrev = mNext->mPrev;
      v9 = mNext->mNext;
      mPrev->mNext = v9;
      v9->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      if ( mNext != (UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *)8 )
        ((void (__fastcall *)(UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> **, __int64))mNext[-1].mNext->mPrev)(
          &mNext[-1].mNext,
          1i64);
    }
  }
}

// File Line: 580
// RVA: 0xE27D0
void __fastcall UFG::WayFinder::Cancel(UFG::WayFinder *this, UFG::WayFinderClient *client)
{
  UFG::WayFinder *p_mNext; // rdx
  UFG::WayFinder *v5; // rbx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *mPrev; // rcx
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *mNext; // rax
  UFG::qList<UFG::WayStarSearch,UFG::WayStarSearch,1,0> *p_m_WayStarSearches; // rdx

  p_mNext = (UFG::WayFinder *)&this->m_WayStarSearches.mNode.mNext[-1].mNext;
  if ( p_mNext != this )
  {
    do
    {
      v5 = (UFG::WayFinder *)&p_mNext->m_WayStarSearches.mNode.mNext[-1].mNext;
      if ( client == (UFG::WayFinderClient *)p_mNext[3].m_WayGraph )
      {
        mPrev = p_mNext->m_WayStarSearches.mNode.mPrev;
        mNext = p_mNext->m_WayStarSearches.mNode.mNext;
        p_m_WayStarSearches = &p_mNext->m_WayStarSearches;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_m_WayStarSearches->mNode.mPrev = &p_m_WayStarSearches->mNode;
        p_m_WayStarSearches->mNode.mNext = &p_m_WayStarSearches->mNode;
        if ( p_m_WayStarSearches != (UFG::qList<UFG::WayStarSearch,UFG::WayStarSearch,1,0> *)8 )
          ((void (__fastcall *)(UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> **, __int64))p_m_WayStarSearches[-1].mNode.mNext->mPrev)(
            &p_m_WayStarSearches[-1].mNode.mNext,
            1i64);
        client->m_CurrEdgeIndex = 0;
      }
      p_mNext = v5;
    }
    while ( v5 != this );
  }
}

// File Line: 608
// RVA: 0xE2980
UFG::WayStarSearch *__fastcall UFG::WayFinder::FindWay(
        UFG::WayFinder *this,
        UFG::WayFinderClient *client,
        UFG::qVector3 *goal_position,
        UFG::qVector3 *p_goal_direction)
{
  __int64 v8; // rbx
  char *v9; // rax
  __int64 v10; // rax
  UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *mPrev; // rcx

  UFG::WayFinder::Cancel(this, client);
  v8 = 0i64;
  if ( UFG::WayFinder::s_SearchPool.mFreeListHead
    && (signed int)(4096 - UFG::WayFinder::s_NodePool.mNumSlotsAllocated) > 1 )
  {
    v9 = UFG::WayStarSearch::operator new(0x80ui64);
    if ( v9 )
    {
      UFG::WayStarSearch::WayStarSearch((UFG::WayStarSearch *)v9, this, client, goal_position, p_goal_direction);
      v8 = v10;
    }
    mPrev = this->m_WayStarSearches.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *)(v8 + 8);
    *(_QWORD *)(v8 + 8) = mPrev;
    *(_QWORD *)(v8 + 16) = &this->m_WayStarSearches;
    this->m_WayStarSearches.mNode.mPrev = (UFG::qNode<UFG::WayStarSearch,UFG::WayStarSearch> *)(v8 + 8);
  }
  return (UFG::WayStarSearch *)v8;
}

