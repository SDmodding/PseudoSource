// File Line: 55
// RVA: 0x14AD460
__int64 dynamic_initializer_for__UFG::AISidewalkGraph::sAIGraphDirectory__()
{
  UFG::qString::qString(&UFG::AISidewalkGraph::sAIGraphDirectory);
  return atexit(dynamic_atexit_destructor_for__UFG::AISidewalkGraph::sAIGraphDirectory__);
}

// File Line: 71
// RVA: 0x14AE9A0
__int64 dynamic_initializer_for__UFG::AISidewalkGraph::sSections__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AISidewalkGraph::sSections__);
}

// File Line: 72
// RVA: 0x14AE980
__int64 dynamic_initializer_for__UFG::AISidewalkGraph::sLastSectionName__()
{
  UFG::qString::qString(&UFG::AISidewalkGraph::sLastSectionName);
  return atexit(dynamic_atexit_destructor_for__UFG::AISidewalkGraph::sLastSectionName__);
}

// File Line: 79
// RVA: 0x14AD480
__int64 dynamic_initializer_for__UFG::AISidewalkGraph::sAlteredNodeData__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AISidewalkGraph::sAlteredNodeData__);
}

// File Line: 88
// RVA: 0x34F2C0
void __fastcall UFG::SidewalkWanderData::ClearData(UFG::SidewalkWanderData *this)
{
  UFG::SidewalkWanderData *v1; // rdi
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  int *v8; // rcx
  int *v9; // rcx

  v1 = this;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)this);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&v1->mGoals[0].mpDestinationNode);
  v2 = UFG::qVector3::msZero.y;
  v3 = UFG::qVector3::msZero.z;
  v1->mGoals[0].mPosition.x = UFG::qVector3::msZero.x;
  v1->mGoals[0].mPosition.y = v2;
  v1->mGoals[0].mPosition.z = v3;
  v1->mGoals[0].mGoalId = -1;
  v1->mGoals[0].mIsValid = 0;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&v1->mGoals[1]);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&v1->mGoals[1].mpDestinationNode);
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mGoals[1].mPosition.x = UFG::qVector3::msZero.x;
  v1->mGoals[1].mPosition.y = v4;
  v1->mGoals[1].mPosition.z = v5;
  v1->mGoals[1].mGoalId = -1;
  v1->mGoals[1].mIsValid = 0;
  v1->mAllowedToUseCrosswalks = 0;
  v1->mPreviousDesiredDirectionValid = 0;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  v1->mPreviousDesiredDirection.x = UFG::qVector3::msZero.x;
  v1->mPreviousDesiredDirection.y = v6;
  v1->mPreviousDesiredDirection.z = v7;
  *(_WORD *)&v1->mAtCrossWalk = 0;
  v1->mIsDestinationSegment = 0;
  v8 = v1->mCrosswalkLanes.m_iIntersectionID.p;
  if ( v8 )
    operator delete[](v8);
  v1->mCrosswalkLanes.m_iIntersectionID.p = 0i64;
  *(_QWORD *)&v1->mCrosswalkLanes.m_iIntersectionID.size = 0i64;
  v9 = v1->mCrosswalkLanes.m_aLanes.p;
  if ( v9 )
    operator delete[](v9);
  v1->mCrosswalkLanes.m_aLanes.p = 0i64;
  *(_QWORD *)&v1->mCrosswalkLanes.m_aLanes.size = 0i64;
}

// File Line: 123
// RVA: 0x33C000
UFG::SidewalkWanderData *__fastcall UFG::SidewalkWanderData::operator=(UFG::SidewalkWanderData *this, UFG::SidewalkWanderData *data)
{
  UFG::SidewalkWanderData *v2; // rdi
  UFG::SidewalkWanderData *v3; // rsi
  float v4; // eax
  float v5; // xmm1_4
  float v6; // eax
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  v2 = data;
  v3 = this;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)this,
    data->mGoals[0].mpSidewalkEdge.mObjUID,
    data->mGoals[0].mpSidewalkEdge.mNameUID,
    data->mGoals[0].mpSidewalkEdge.mIndex);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    &v3->mGoals[0].mpDestinationNode,
    v2->mGoals[0].mpDestinationNode.mObjUID,
    v2->mGoals[0].mpDestinationNode.mNameUID,
    v2->mGoals[0].mpDestinationNode.mIndex);
  v4 = v2->mGoals[0].mPosition.x;
  v5 = v2->mGoals[0].mPosition.z;
  v3->mGoals[0].mPosition.y = v2->mGoals[0].mPosition.y;
  v3->mGoals[0].mPosition.z = v5;
  v3->mGoals[0].mPosition.x = v4;
  v3->mGoals[0].mGoalId = v2->mGoals[0].mGoalId;
  v3->mGoals[0].mIsValid = v2->mGoals[0].mIsValid;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&v3->mGoals[1],
    v2->mGoals[1].mpSidewalkEdge.mObjUID,
    v2->mGoals[1].mpSidewalkEdge.mNameUID,
    v2->mGoals[1].mpSidewalkEdge.mIndex);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    &v3->mGoals[1].mpDestinationNode,
    v2->mGoals[1].mpDestinationNode.mObjUID,
    v2->mGoals[1].mpDestinationNode.mNameUID,
    v2->mGoals[1].mpDestinationNode.mIndex);
  v6 = v2->mGoals[1].mPosition.x;
  v7 = v2->mGoals[1].mPosition.z;
  v3->mGoals[1].mPosition.y = v2->mGoals[1].mPosition.y;
  v3->mGoals[1].mPosition.z = v7;
  v3->mGoals[1].mPosition.x = v6;
  v3->mGoals[1].mGoalId = v2->mGoals[1].mGoalId;
  v3->mGoals[1].mIsValid = v2->mGoals[1].mIsValid;
  v3->mPreviousDesiredDirectionValid = v2->mPreviousDesiredDirectionValid;
  v8 = v2->mPreviousDesiredDirection.y;
  v9 = v2->mPreviousDesiredDirection.z;
  v3->mPreviousDesiredDirection.x = v2->mPreviousDesiredDirection.x;
  v3->mPreviousDesiredDirection.y = v8;
  v3->mPreviousDesiredDirection.z = v9;
  v3->mAllowedToUseCrosswalks = v2->mAllowedToUseCrosswalks;
  v3->mLastUpdateFrame = v2->mLastUpdateFrame;
  return v3;
}

// File Line: 136
// RVA: 0x36D640
void __fastcall UFG::SidewalkWanderData::MakeLookAheadCurrent(UFG::SidewalkWanderData *this)
{
  UFG::SidewalkWanderData *v1; // rdi
  float v2; // eax
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v1 = this;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)this,
    this->mGoals[1].mpSidewalkEdge.mObjUID,
    this->mGoals[1].mpSidewalkEdge.mNameUID,
    this->mGoals[1].mpSidewalkEdge.mIndex);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    &v1->mGoals[0].mpDestinationNode,
    v1->mGoals[1].mpDestinationNode.mObjUID,
    v1->mGoals[1].mpDestinationNode.mNameUID,
    v1->mGoals[1].mpDestinationNode.mIndex);
  v2 = v1->mGoals[1].mPosition.x;
  v3 = v1->mGoals[1].mPosition.z;
  v1->mGoals[0].mPosition.y = v1->mGoals[1].mPosition.y;
  v1->mGoals[0].mPosition.z = v3;
  v1->mGoals[0].mPosition.x = v2;
  v1->mGoals[0].mGoalId = v1->mGoals[1].mGoalId;
  v1->mGoals[0].mIsValid = v1->mGoals[1].mIsValid;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&v1->mGoals[1]);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&v1->mGoals[1].mpDestinationNode);
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  v1->mGoals[1].mPosition.x = UFG::qVector3::msZero.x;
  v1->mGoals[1].mPosition.y = v4;
  v1->mGoals[1].mPosition.z = v5;
  v1->mGoals[1].mGoalId = -1;
  v1->mGoals[1].mIsValid = 0;
}

// File Line: 142
// RVA: 0x3861D0
void __fastcall UFG::SidewalkWanderData::SetDestinationPos(UFG::SidewalkWanderData *this, UFG::qVector3 *destination, UFG::qVector3 *current_position)
{
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm3_4
  __m128 v6; // xmm4
  float v7; // xmm5_4
  __m128 v8; // xmm2
  float v9; // xmm0_4
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v10; // rbx
  float v11; // xmm1_4
  float v12; // xmm2_4

  v3 = destination->y;
  v4 = destination->z;
  this->mGoals[0].mPosition.x = destination->x;
  this->mGoals[0].mPosition.z = v4;
  this->mGoals[0].mPosition.y = v3;
  this->mGoals[0].mIsValid = 1;
  v6 = (__m128)LODWORD(destination->y);
  v5 = destination->x - current_position->x;
  v6.m128_f32[0] = v6.m128_f32[0] - current_position->y;
  v7 = destination->z - current_position->z;
  v8 = v6;
  v8.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5)) + (float)(v7 * v7);
  LODWORD(v9) = (unsigned __int128)_mm_sqrt_ps(v8);
  if ( v9 <= 0.001 )
  {
    this->mPreviousDesiredDirectionValid = 0;
  }
  else
  {
    this->mPreviousDesiredDirection.z = (float)(1.0 / v9) * v7;
    this->mPreviousDesiredDirection.x = (float)(1.0 / v9) * v5;
    this->mPreviousDesiredDirection.y = (float)(1.0 / v9) * v6.m128_f32[0];
    this->mPreviousDesiredDirectionValid = 1;
  }
  v10 = (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&this->mGoals[1];
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&this->mGoals[1]);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(v10 + 1);
  v11 = UFG::qVector3::msZero.y;
  v12 = UFG::qVector3::msZero.z;
  *(float *)&v10[2].mPrev = UFG::qVector3::msZero.x;
  *((float *)&v10[2].mPrev + 1) = v11;
  *(float *)&v10[2].mNext = v12;
  HIDWORD(v10[2].mNext) = -1;
  LOBYTE(v10[2].mData) = 0;
}

// File Line: 164
// RVA: 0x368AD0
void UFG::AISidewalkGraph::Initialize(void)
{
  char v0; // cl
  UFG::Grid<UFG::AISidewalkEdge_Game> *v1; // rdi
  UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *v2; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game> > **v3; // rbx
  UFG::Grid<UFG::AISidewalkEdge_Game> *v4; // rdi
  UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *v5; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game> > **v6; // rbx
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float y_max; // xmm9_4
  UFG::Grid<UFG::RoadNetworkSegment> *v11; // rax
  UFG::Grid<UFG::AISidewalkEdge_Game> *v12; // rbx

  v0 = initTweak;
  if ( !initTweak )
    v0 = 1;
  initTweak = v0;
  v1 = gAISidewalkEdgeDataGrid;
  if ( gAISidewalkEdgeDataGrid )
  {
    v2 = gAISidewalkEdgeDataGrid->mGridNodes;
    if ( gAISidewalkEdgeDataGrid->mGridNodes )
    {
      v3 = &v2[-1].mNode.mNext;
      `eh vector destructor iterator'(
        v2,
        0x10ui64,
        (int)v2[-1].mNode.mNext,
        (void (__fastcall *)(void *))UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0>::~qList<UFG::qReflectField,UFG::qReflectField,1,0>);
      operator delete[](v3);
    }
    operator delete[](v1);
  }
  v4 = gAISidewalkEdgeCrosswalkDataGrid;
  if ( gAISidewalkEdgeCrosswalkDataGrid )
  {
    v5 = gAISidewalkEdgeCrosswalkDataGrid->mGridNodes;
    if ( gAISidewalkEdgeCrosswalkDataGrid->mGridNodes )
    {
      v6 = &v5[-1].mNode.mNext;
      `eh vector destructor iterator'(
        v5,
        0x10ui64,
        (int)v5[-1].mNode.mNext,
        (void (__fastcall *)(void *))UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0>::~qList<UFG::qReflectField,UFG::qReflectField,1,0>);
      operator delete[](v6);
    }
    operator delete[](v4);
  }
  v7 = UFG::gWorldExtents_min.x;
  v8 = UFG::gWorldExtents_min.y;
  v9 = UFG::gWorldExtents_max.x;
  y_max = UFG::gWorldExtents_max.y;
  v11 = (UFG::Grid<UFG::RoadNetworkSegment> *)UFG::qMalloc(0x30ui64, "Grid<AISidewalkEdge_Game>", 0i64);
  v12 = (UFG::Grid<UFG::AISidewalkEdge_Game> *)v11;
  if ( v11 )
  {
    v11->mGridNodes = 0i64;
    UFG::Grid<UFG::RoadNetworkSegment>::Init(v11, v7, v8, v9, y_max, 125.0);
    gAISidewalkEdgeDataGrid = v12;
  }
  else
  {
    gAISidewalkEdgeDataGrid = 0i64;
  }
}

// File Line: 697
// RVA: 0x3561C0
void __fastcall UFG::AISidewalkGraph::FindClosestSidewalkConnection(UFG::qVector3 *pos, const float maxDist, UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *resultantEdge, unsigned int searchFlags)
{
  unsigned int v4; // er13
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v5; // rbp
  UFG::qVector3 *v6; // r12
  unsigned int v7; // eax
  UFG::Grid<UFG::AISidewalkEdge_Game> *v8; // rdi
  float v9; // xmm8_4
  float v10; // xmm2_4
  __int64 v11; // r10
  float v12; // xmm9_4
  signed int v13; // er11
  signed int v14; // ebx
  int v15; // eax
  signed int v16; // er8
  int v17; // ecx
  unsigned int v18; // edx
  signed __int64 v19; // rsi
  signed __int64 v20; // r9
  __int64 v21; // r10
  __int64 v22; // rcx
  __int64 v23; // r8
  float v24; // xmm10_4
  __int64 v25; // r15
  __int64 *v26; // r14
  __int64 v27; // rsi
  __int64 v28; // rdi
  __int64 v29; // rbx
  char v30; // cl
  __int64 v31; // rdx
  __int64 v32; // rax
  __int64 v33; // rax
  signed __int64 v34; // rax
  __int64 v35; // rdx
  int v36; // eax
  __int64 v37; // rax
  signed __int64 v38; // rcx
  __int64 v39; // rdx
  float v40; // xmm10_4
  Render::SkinningCacheNode *v41; // r14
  UFG::qBaseTreeRB *v42; // rax
  unsigned int v43; // ecx
  UFG::qBaseTreeRB *v44; // r12
  UFG::qBaseNodeVariableRB<unsigned __int64> *v45; // rsi
  __int64 v46; // rbp
  __int64 v47; // rdi
  signed __int64 v48; // rax
  unsigned int v49; // er9
  _QWORD *v50; // rbx
  int v51; // er11
  char v52; // cl
  __int64 v53; // r8
  char *v54; // rax
  __int64 v55; // rdx
  __int64 v56; // rdx
  signed __int64 v57; // rax
  __int64 v58; // r10
  char *v59; // rax
  signed __int64 v60; // rax
  signed __int64 v61; // rax
  UFG::qVector3 **v62; // rdx
  UFG::qResourceInventory *v63; // rax
  UFG::qResourceWarehouse *v64; // rax
  __int64 v65; // [rsp+20h] [rbp-178h]
  UFG::qBaseTreeRB *v66; // [rsp+20h] [rbp-178h]
  UFG::qVector3 result; // [rsp+28h] [rbp-170h]
  _QWORD *v68; // [rsp+38h] [rbp-160h]
  __int64 v69[25]; // [rsp+40h] [rbp-158h]
  int v70; // [rsp+108h] [rbp-90h]
  UFG::qVector3 *posa; // [rsp+1A0h] [rbp+8h]
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v72; // [rsp+1B0h] [rbp+18h]

  v72 = (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)resultantEdge;
  posa = pos;
  v4 = searchFlags;
  v5 = (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)resultantEdge;
  v6 = pos;
  v7 = UFG::SectionChooser::GetVisIndexAtPosition(pos, 0);
  if ( !UFG::SectionChooser::IsSectionVisible_VisIndex(v7, SCENERY_LAYER_STD, 0) )
  {
    UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(v5);
    return;
  }
  v8 = gAISidewalkEdgeDataGrid;
  v68 = 0i64;
  if ( !gAISidewalkEdgeDataGrid )
    goto LABEL_102;
  v9 = v6->x;
  v10 = gAISidewalkEdgeDataGrid->mGridSizeInv;
  v11 = gAISidewalkEdgeDataGrid->mXDim;
  v12 = v6->y;
  v13 = (signed int)(float)((float)((float)(v6->x - maxDist) - gAISidewalkEdgeDataGrid->mXMin) * v10);
  if ( v13 < 0 )
    v13 = 0;
  v14 = (signed int)(float)((float)((float)(v6->x + maxDist) - gAISidewalkEdgeDataGrid->mXMin) * v10);
  if ( v14 >= (signed int)v11 )
    v14 = v11 - 1;
  v15 = gAISidewalkEdgeDataGrid->mYDim;
  v16 = (signed int)(float)((float)((float)(v12 - maxDist) - gAISidewalkEdgeDataGrid->mYMin) * v10);
  if ( v16 < 0 )
    v16 = 0;
  v17 = (signed int)(float)((float)((float)(v12 + maxDist) - gAISidewalkEdgeDataGrid->mYMin) * v10);
  if ( v17 >= v15 )
    v17 = v15 - 1;
  v18 = 0;
  v70 = 0;
  if ( v16 <= v17 )
  {
    v19 = 16 * v11;
    v20 = 16i64 * (v13 + v16 * (signed int)v11);
    v21 = (unsigned int)(v17 - v16 + 1);
    do
    {
      if ( v13 <= v14 )
      {
        v22 = (__int64)v8->mGridNodes + v20;
        v23 = (unsigned int)(v14 - v13 + 1);
        do
        {
          if ( *(_QWORD *)(v22 + 8) != v22 )
          {
            v69[v18] = v22;
            v18 = v70++ + 1;
          }
          v22 += 16i64;
          --v23;
        }
        while ( v23 );
      }
      v20 += v19;
      --v21;
    }
    while ( v21 );
  }
  if ( v18 )
  {
    v24 = maxDist * maxDist;
    if ( !v18 )
      goto LABEL_97;
    v25 = v18;
    v26 = v69;
    v65 = v18;
    do
    {
      v27 = *v26;
      v28 = *(_QWORD *)(*v26 + 8);
      if ( v28 != *v26 )
      {
        do
        {
          v29 = *(_QWORD *)(v28 + 16);
          if ( v4 & 4 )
            v30 = 1;
          else
            v30 = ~(unsigned __int8)(*(_DWORD *)(v29 + 24) >> 2) & 1;
          if ( v29 )
          {
            v31 = *(_QWORD *)v29 + v29;
            if ( !*(_QWORD *)v29 )
              v31 = 0i64;
            v32 = *(_QWORD *)(v31 + 40);
            if ( v32 && *(_WORD *)(v32 + 34) != 0 )
            {
              v33 = *(_QWORD *)(v29 + 8);
              v34 = v33 ? v29 + v33 + 8 : 0i64;
              v35 = *(_QWORD *)(v34 + 40);
              if ( v35 )
              {
                if ( *(_WORD *)(v35 + 34) )
                {
                  v36 = *(_DWORD *)(v29 + 24);
                  if ( v36 & 2 )
                  {
                    if ( (v36 & 0x80u) == 0 && v4 & 2 && v30 && *(_BYTE *)(v29 + 24) & 0xFC & (unsigned __int8)v4 )
                    {
                      v37 = *(_QWORD *)(v29 + 8);
                      if ( v37 )
                        v38 = v37 + v29 + 8;
                      else
                        v38 = 0i64;
                      v39 = *(_QWORD *)v29 + v29;
                      if ( !*(_QWORD *)v29 )
                        v39 = 0i64;
                      UFG::qNearestSegPoint(&result, *(UFG::qVector3 **)(v39 + 40), *(UFG::qVector3 **)(v38 + 40), v6);
                      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(result.z - v6->z) & _xmm) < 1.5
                        && (float)((float)((float)(v12 - result.y) * (float)(v12 - result.y))
                                 + (float)((float)(v9 - result.x) * (float)(v9 - result.x))) < v24 )
                      {
                        v24 = (float)((float)(v12 - result.y) * (float)(v12 - result.y))
                            + (float)((float)(v9 - result.x) * (float)(v9 - result.x));
                        v68 = (_QWORD *)v29;
                      }
                    }
                  }
                }
              }
            }
          }
          v28 = *(_QWORD *)(v28 + 8);
        }
        while ( v28 != v27 );
        v25 = v65;
      }
      ++v26;
      v65 = --v25;
    }
    while ( v25 );
  }
  else
  {
LABEL_102:
    v40 = maxDist * maxDist;
    v41 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423BAAD0);
    if ( !v41 )
      goto LABEL_97;
    do
    {
      v42 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423BAAD0, (UFG::qBaseNodeRB *)v41);
      v43 = HIDWORD(v41[2].mNode.mChild1);
      v44 = v42;
      v66 = v42;
      if ( v43 )
      {
        v45 = v41[3].mNode.mParent;
        v46 = v43;
        v47 = 0i64;
        do
        {
          if ( v45 )
            v48 = (signed __int64)&v41[3] + (_QWORD)v45;
          else
            v48 = 0i64;
          v49 = *(_DWORD *)(v47 + v48 + 24);
          v50 = (_QWORD *)(v47 + v48);
          v51 = *(_DWORD *)(v47 + v48 + 24) & 0xFC;
          if ( v4 & 4 )
            v52 = 1;
          else
            v52 = ~(unsigned __int8)(v49 >> 2) & 1;
          v53 = *v50;
          v54 = (char *)v50 + *v50;
          if ( !*v50 )
            v54 = 0i64;
          v55 = *((_QWORD *)v54 + 5);
          if ( v55 && *(_WORD *)(v55 + 34) )
          {
            v56 = v50[1];
            v57 = (signed __int64)(v56 ? (_QWORD *)((char *)v50 + v56 + 8) : 0i64);
            v58 = *(_QWORD *)(v57 + 40);
            if ( v58 )
            {
              if ( *(_WORD *)(v58 + 34) && v49 & 2 && (v49 & 0x80u) == 0 && v4 & 2 && v52 && v51 & v4 )
              {
                v59 = (char *)v50 + v53;
                if ( !v53 )
                  v59 = 0i64;
                if ( *((_QWORD *)v59 + 5) )
                {
                  v60 = (signed __int64)(v56 ? (_QWORD *)((char *)v50 + v56 + 8) : 0i64);
                  if ( *(_QWORD *)(v60 + 40) )
                  {
                    if ( v56 )
                      v61 = (signed __int64)v50 + v56 + 8;
                    else
                      v61 = 0i64;
                    v62 = (UFG::qVector3 **)((char *)v50 + v53);
                    if ( !v53 )
                      v62 = 0i64;
                    UFG::qNearestSegPoint(&result, v62[5], *(UFG::qVector3 **)(v61 + 40), posa);
                    if ( (float)((float)((float)(posa->y - result.y) * (float)(posa->y - result.y))
                               + (float)((float)(posa->x - result.x) * (float)(posa->x - result.x))) < v40 )
                    {
                      v40 = (float)((float)(posa->y - result.y) * (float)(posa->y - result.y))
                          + (float)((float)(posa->x - result.x) * (float)(posa->x - result.x));
                      v68 = v50;
                    }
                  }
                }
              }
            }
          }
          v47 += 80i64;
          --v46;
        }
        while ( v46 );
        v44 = v66;
      }
      v41 = (Render::SkinningCacheNode *)v44;
    }
    while ( v44 );
  }
  if ( v68 )
  {
    UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game>::_Set(v72, *((_DWORD *)v68 + 4), *((_DWORD *)v68 + 5));
    return;
  }
  v5 = v72;
LABEL_97:
  v5->mPtr = 0i64;
  v63 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v64 = UFG::qResourceWarehouse::Instance();
    v63 = UFG::qResourceWarehouse::GetInventory(v64, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v63;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v5->mPrev, v63);
  v5->mObjUID = -1;
  v5->mIndex = -1;
  v5->mNameUID = -1;
  v5->mPtr = 0i64;
}

// File Line: 807
// RVA: 0x357930
char __fastcall UFG::AISidewalkGraph::FindNodeLocationInRange(UFG::qVector3 *pos, const float minDist, const float maxDist, const bool offScreenOnly, UFG::qVector3 *resultPos)
{
  UFG::qVector3 *v5; // r15
  bool v6; // r12
  float *v7; // r14
  float v8; // xmm7_4
  Render::SkinningCacheNode *v9; // rsi
  __int64 v10; // rdi
  UFG::qBaseTreeRB *v11; // rbp
  unsigned __int64 v12; // rcx
  signed __int64 v13; // rdx
  float *v14; // rbx
  float v15; // xmm6_4
  bool v16; // al

  v5 = pos;
  v6 = offScreenOnly;
  v7 = 0i64;
  v8 = maxDist * maxDist;
  v9 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423BAAD0);
  if ( !v9 )
    return 0;
  do
  {
    v10 = 0i64;
    v11 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423BAAD0, (UFG::qBaseNodeRB *)v9);
    if ( LODWORD(v9[2].mNode.mChild1) )
    {
      do
      {
        v12 = v9[2].mNode.mUID;
        if ( v12 )
          v13 = (signed __int64)&v9[2].mNode.mUID + v12;
        else
          v13 = 0i64;
        v14 = (float *)(v13 + 40 * v10);
        if ( !*(_WORD *)(v13 + 40 * v10 + 34) )
          goto LABEL_14;
        v15 = (float)((float)(v5->y - v14[1]) * (float)(v5->y - v14[1]))
            + (float)((float)(v5->x - *v14) * (float)(v5->x - *v14));
        v16 = UFG::SimObjectUtility::IsPositionOnScreen((UFG::qVector3 *)(v13 + 40 * v10), 2.0, 0);
        if ( v6 )
        {
          if ( !v16 )
          {
LABEL_11:
            if ( (float)(minDist * minDist) < v15 && v15 < v8 )
            {
              v7 = v14;
              v8 = v15;
            }
            goto LABEL_14;
          }
        }
        else if ( v16 )
        {
          goto LABEL_11;
        }
LABEL_14:
        v10 = (unsigned int)(v10 + 1);
      }
      while ( (unsigned int)v10 < LODWORD(v9[2].mNode.mChild1) );
    }
    v9 = (Render::SkinningCacheNode *)v11;
  }
  while ( v11 );
  if ( !v7 )
    return 0;
  *(_QWORD *)&resultPos->x = *(_QWORD *)v7;
  resultPos->z = v7[2];
  return 1;
}

// File Line: 866
// RVA: 0x35E920
char __fastcall UFG::AISidewalkGraph::GetDestinationPointFromNode(UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *nodeHandle, UFG::qVector3 *destPos, const bool isGroupLeader)
{
  UFG::AISidewalkNode_Game *v3; // rdi
  UFG::qVector3 *v4; // rbx
  char v5; // al
  float v6; // xmm6_4
  float v7; // xmm8_4
  float v8; // xmm9_4
  UFG::qVector3 *v9; // rax
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm8_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  UFG::qVector3 range; // [rsp+20h] [rbp-98h]
  UFG::qVector3 position; // [rsp+30h] [rbp-88h]
  UFG::qVector3 result; // [rsp+40h] [rbp-78h]

  v3 = nodeHandle->mPtr;
  v4 = destPos;
  if ( !v3 )
    return 0;
  v6 = v3->mRadius;
  v7 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps((__m128)LODWORD(FLOAT_2_0)));
  v8 = v7 * 0.0;
  if ( isGroupLeader )
  {
    v6 = v6 - 1.0;
    if ( v6 <= 0.0 )
      v6 = 0.0;
  }
  range.x = v7 * 2.0;
  range.z = v8 * 2.0;
  range.y = v7 * 2.0;
  v9 = UFG::qRandom(&result, &range, &UFG::qDefaultSeed);
  v10 = (float)((float)(v9->x - v7) * v6) + v3->mPos.x;
  v11 = (float)((float)(v9->y - v7) * v6) + v3->mPos.y;
  v12 = (float)((float)(v9->z - v8) * v6) + v3->mPos.z;
  position.x = v10;
  position.y = v11;
  position.z = v12;
  if ( UFG::PlaceOnGround(&range, &position, 0.0, 3.0) )
  {
    v13 = range.y;
    v5 = 1;
    v4->x = range.x;
    v14 = range.z;
    v4->y = v13;
    v4->z = v14;
  }
  else
  {
    v4->x = v10;
    v4->y = v11;
    v4->z = v12;
    v5 = 0;
  }
  return v5;
}

// File Line: 912
// RVA: 0x35F1A0
float __fastcall UFG::GetEffectiveNodeRadius(UFG::AISidewalkEdge_Game *edge_game, UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *pCurrentNode, UFG::qVector3 *entityLocation, UFG::qVector3 *entityForward)
{
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v4; // r11
  UFG::AISidewalkEdge_Game *v5; // r10
  __int64 v6; // rdx
  signed __int64 v7; // rcx
  char *v8; // rax
  __int64 v9; // rdx
  signed __int64 v10; // rax
  float v11; // xmm6_4
  char *v12; // rax
  float *v13; // rax
  float v14; // xmm3_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  UFG::qVector3 v2; // [rsp+28h] [rbp-40h]
  UFG::qVector3 v1; // [rsp+38h] [rbp-30h]

  v4 = pCurrentNode;
  v5 = edge_game;
  if ( !(_S28 & 1) )
  {
    _S28 |= 1u;
    ramp.xBase = 0.0;
    ramp.yBase = 1.0;
    ramp.yMin = FLOAT_0_0099999998;
    ramp.yMax = 1.0;
    ramp.fCoef = FLOAT_N0_42016903;
  }
  v6 = edge_game->mpStartNodeHandle.mOffset;
  v7 = 0i64;
  v8 = (char *)v5 + v6;
  if ( !v6 )
    v8 = 0i64;
  if ( v4->mObjUID == *((_DWORD *)v8 + 9) )
  {
    v9 = v5->mpEndNodeHandle.mOffset;
    if ( v9 )
      v10 = (signed __int64)&v5->mpEndNodeHandle + v9;
    else
      v10 = 0i64;
    v11 = *(float *)(*(_QWORD *)(v10 + 40) + 20i64);
    if ( v9 )
      v7 = (signed __int64)&v5->mpEndNodeHandle + v9;
  }
  else
  {
    v12 = (char *)v5 + v6;
    if ( !v6 )
      v12 = 0i64;
    v11 = *(float *)(*((_QWORD *)v12 + 5) + 20i64);
    if ( v6 )
      v7 = (signed __int64)v5 + v6;
  }
  v13 = *(float **)(v7 + 40);
  v14 = v13[1];
  v15 = *v13;
  v1.x = entityForward->x;
  v1.y = entityForward->y;
  v1.z = 0.0;
  v2.x = v15 - entityLocation->x;
  v2.y = v14 - entityLocation->y;
  v2.z = 0.0;
  v16 = (float)((float)(UFG::qAngleBetween(&v1, &v2) - ramp.xBase) * ramp.fCoef) + ramp.yBase;
  if ( v16 <= ramp.yMin )
    v16 = ramp.yMin;
  if ( v16 >= ramp.yMax )
    v16 = ramp.yMax;
  return v16 * v11;
}

// File Line: 949
// RVA: 0x34AA60
char __fastcall UFG::AISidewalkGraph::CalculateDestinationPoint(UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *currentEdge, UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *destinationNode, UFG::qVector3 *pDestinationPoint, UFG::qVector3 *pCurrentPos, UFG::qVector3 *pCurrentFacing, const bool isGroupLeader, UFG::AIEntityComponent *pAIEntityComponent, UFG::SidewalkWanderData *sidewalkWanderData)
{
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v8; // rsi
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v9; // r15
  unsigned int v11; // er14
  int v12; // ebx
  unsigned __int16 v13; // di
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  unsigned int v18; // er14
  int v19; // ebx
  unsigned __int16 v20; // di
  UFG::qResourceInventory *v21; // rax
  UFG::qResourceWarehouse *v22; // rax
  UFG::qResourceInventory *v23; // rax
  UFG::qResourceWarehouse *v24; // rax
  __int64 v25; // rax
  unsigned int v26; // er14
  int v27; // ebx
  __int16 v28; // di
  UFG::qResourceInventory *v29; // rax
  UFG::qResourceWarehouse *v30; // rax
  UFG::qResourceInventory *v31; // rax
  UFG::qResourceWarehouse *v32; // rax
  __int64 v33; // rcx
  __int64 v34; // rax
  unsigned int v35; // er14
  int v36; // ebx
  __int16 v37; // di
  UFG::qResourceInventory *v38; // rax
  UFG::qResourceWarehouse *v39; // rax
  UFG::qResourceInventory *v40; // rax
  UFG::qResourceWarehouse *v41; // rax
  UFG::AISidewalkNode_Game *v42; // r14
  __int64 v43; // rax
  signed __int64 v44; // r12
  signed int v45; // edi
  unsigned int v46; // ebx
  unsigned int v47; // er15
  _QWORD *v48; // rcx
  UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *v49; // rcx
  float v50; // xmm7_4
  float v51; // xmm6_4
  UFG::AISidewalkEdge_Game **v52; // rdi
  unsigned int v53; // ebx
  __int64 *v54; // rdx
  __int64 v55; // rcx
  UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *v56; // rcx
  float v57; // xmm6_4
  unsigned int v58; // er14
  unsigned int i; // ebx
  _QWORD *v60; // rcx
  UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *v61; // rcx
  UFG::AISidewalkEdge_Game *v62; // rdi
  _QWORD *v63; // rcx
  char *v64; // rax
  _QWORD *v65; // rbx
  char *v66; // rax
  __int64 v67; // rax
  UFG::qResourceInventory *v68; // rax
  UFG::qResourceWarehouse *v69; // rax
  unsigned int v70; // er14
  unsigned int v71; // edi
  UFG::qResourceInventory *v72; // rax
  UFG::qResourceWarehouse *v73; // rax
  UFG::qResourceInventory *v74; // rax
  UFG::qResourceWarehouse *v75; // rax
  __int64 v76; // rax
  signed __int64 v77; // rax
  __int64 v78; // rax
  UFG::qResourceInventory *v79; // rax
  UFG::qResourceWarehouse *v80; // rax
  unsigned int v81; // edi
  unsigned int v82; // ebx
  unsigned int v83; // ebx
  unsigned int v84; // er14
  _QWORD *v85; // rcx
  UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *v86; // rdi
  UFG::AISidewalkEdge_Game *v87; // rbx
  UFG::AISidewalkEdge_Game *v88; // rax
  __int64 v89; // rax
  UFG::qResourceInventory *v90; // rax
  UFG::qResourceWarehouse *v91; // rax
  unsigned int v92; // er14
  unsigned int v93; // edi
  UFG::qResourceInventory *v94; // rax
  UFG::qResourceWarehouse *v95; // rax
  UFG::qResourceInventory *v96; // rax
  UFG::qResourceWarehouse *v97; // rax
  __int64 v98; // rax
  signed __int64 v99; // rax
  __int64 v100; // rax
  UFG::qResourceInventory *v101; // rax
  UFG::qResourceWarehouse *v102; // rax
  UFG::qResourceInventory *v103; // rax
  UFG::qResourceWarehouse *v104; // rax
  UFG::qResourceInventory *v105; // rax
  UFG::qResourceWarehouse *v106; // rax
  char v107; // bl
  UFG::qResourceInventory *v108; // rax
  UFG::qResourceWarehouse *v109; // rax
  UFG::qResourceInventory *v110; // rax
  UFG::qResourceWarehouse *v111; // rax
  UFG::qResourceInventory *v112; // rax
  UFG::qResourceWarehouse *v113; // rax
  UFG::qResourceInventory *v114; // rax
  UFG::qResourceWarehouse *v115; // rax
  UFG::qResourceInventory *v116; // rax
  UFG::qResourceWarehouse *v117; // rax
  UFG::qResourceHandle v118; // [rsp+40h] [rbp-C0h]
  int v119; // [rsp+60h] [rbp-A0h]
  unsigned int objUID; // [rsp+64h] [rbp-9Ch]
  __int64 v121; // [rsp+68h] [rbp-98h]
  UFG::qResourceHandle v122; // [rsp+70h] [rbp-90h]
  int v123; // [rsp+90h] [rbp-70h]
  int v124; // [rsp+94h] [rbp-6Ch]
  _QWORD *v125; // [rsp+98h] [rbp-68h]
  UFG::qResourceHandle v126; // [rsp+A0h] [rbp-60h]
  int v127; // [rsp+C0h] [rbp-40h]
  int v128; // [rsp+C4h] [rbp-3Ch]
  __int64 v129; // [rsp+C8h] [rbp-38h]
  UFG::qResourceHandle v130; // [rsp+D0h] [rbp-30h]
  int v131; // [rsp+F0h] [rbp-10h]
  int v132; // [rsp+F4h] [rbp-Ch]
  __int64 v133; // [rsp+F8h] [rbp-8h]
  UFG::qResourceHandle v134; // [rsp+100h] [rbp+0h]
  int v135; // [rsp+120h] [rbp+20h]
  int v136; // [rsp+124h] [rbp+24h]
  __int64 v137; // [rsp+128h] [rbp+28h]
  __int64 v138; // [rsp+130h] [rbp+30h]
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v139; // [rsp+1A0h] [rbp+A0h]
  UFG::qVector3 *destPos; // [rsp+1B0h] [rbp+B0h]
  UFG::qVector3 *entityLocation; // [rsp+1B8h] [rbp+B8h]

  entityLocation = pCurrentPos;
  destPos = pDestinationPoint;
  v139 = (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)currentEdge;
  v138 = -2i64;
  v8 = destinationNode;
  v9 = (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)currentEdge;
  if ( !currentEdge->mPtr )
    return 0;
  if ( !destinationNode->mPtr )
    return UFG::AISidewalkGraph::CalculateInitialDestinationPoint(
             currentEdge,
             destinationNode,
             pDestinationPoint,
             pCurrentPos,
             pCurrentFacing,
             isGroupLeader,
             pAIEntityComponent,
             sidewalkWanderData);
  UFG::qResourceHandle::qResourceHandle(&v118);
  v119 = 0xFFFF;
  objUID = -1;
  v121 = 0i64;
  v118.mNameUID = -1;
  UFG::qResourceHandle::qResourceHandle(&v134);
  v135 = 0xFFFF;
  v136 = -1;
  v137 = 0i64;
  v134.mNameUID = -1;
  v11 = v8->mNameUID;
  v12 = v8->mObjUID;
  v13 = v8->mIndex;
  v137 = 0i64;
  v14 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v14;
  }
  UFG::qResourceHandle::Close(&v134, v14);
  LOWORD(v135) = v13;
  v136 = v12;
  v16 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v17 = UFG::qResourceWarehouse::Instance();
    v16 = UFG::qResourceWarehouse::GetInventory(v17, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v16;
  }
  UFG::qResourceHandle::Init(&v134, 0x43E99F7Eu, v11, v16);
  UFG::qResourceHandle::qResourceHandle(&v122);
  v123 = 0x1FFFF;
  v124 = -1;
  v125 = 0i64;
  v122.mNameUID = -1;
  v18 = v9->mNameUID;
  v19 = v9->mObjUID;
  v20 = v9->mIndex;
  v125 = 0i64;
  v21 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v22 = UFG::qResourceWarehouse::Instance();
    v21 = UFG::qResourceWarehouse::GetInventory(v22, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v21;
  }
  UFG::qResourceHandle::Close(&v122, v21);
  LOWORD(v123) = v20;
  v124 = v19;
  v23 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v24 = UFG::qResourceWarehouse::Instance();
    v23 = UFG::qResourceWarehouse::GetInventory(v24, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v23;
  }
  UFG::qResourceHandle::Init(&v122, 0x43E99F7Eu, v18, v23);
  UFG::qResourceHandle::qResourceHandle(&v130);
  v131 = 0xFFFF;
  v132 = -1;
  v133 = 0i64;
  v130.mNameUID = -1;
  if ( *v125 )
    v25 = (__int64)v125 + *v125;
  else
    v25 = 0i64;
  v26 = *(_DWORD *)(v25 + 24);
  v27 = *(_DWORD *)(v25 + 36);
  v28 = *(_WORD *)(v25 + 32);
  v133 = 0i64;
  v29 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v30 = UFG::qResourceWarehouse::Instance();
    v29 = UFG::qResourceWarehouse::GetInventory(v30, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v29;
  }
  UFG::qResourceHandle::Close(&v130, v29);
  LOWORD(v131) = v28;
  v132 = v27;
  v31 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v32 = UFG::qResourceWarehouse::Instance();
    v31 = UFG::qResourceWarehouse::GetInventory(v32, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v31;
  }
  UFG::qResourceHandle::Init(&v130, 0x43E99F7Eu, v26, v31);
  UFG::qResourceHandle::qResourceHandle(&v126);
  v127 = 0xFFFF;
  v128 = -1;
  v129 = 0i64;
  v126.mNameUID = -1;
  v33 = v125[1];
  if ( v33 )
    v34 = (__int64)v125 + v33 + 8;
  else
    v34 = 0i64;
  v35 = *(_DWORD *)(v34 + 24);
  v36 = *(_DWORD *)(v34 + 36);
  v37 = *(_WORD *)(v34 + 32);
  v129 = 0i64;
  v38 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v39 = UFG::qResourceWarehouse::Instance();
    v38 = UFG::qResourceWarehouse::GetInventory(v39, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v38;
  }
  UFG::qResourceHandle::Close(&v126, v38);
  LOWORD(v127) = v37;
  v128 = v36;
  v40 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v41 = UFG::qResourceWarehouse::Instance();
    v40 = UFG::qResourceWarehouse::GetInventory(v41, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v40;
  }
  UFG::qResourceHandle::Init(&v126, 0x43E99F7Eu, v35, v40);
  if ( !v133 && !v129 )
    goto LABEL_120;
  v42 = v8->mPtr;
  v43 = v42->mConnections.mOffset;
  if ( v43 )
    v44 = (signed __int64)&v42->mConnections + v43;
  else
    v44 = 0i64;
  v45 = v42->mConnectionsCount;
  v46 = 0;
  if ( v42->mConnectionsCount > 0u )
  {
    v47 = v42->mConnectionsCount;
    do
    {
      v48 = (_QWORD *)(v44 + 8i64 * v46);
      if ( *v48 )
        v49 = (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)((char *)v48 + *v48);
      else
        v49 = 0i64;
      if ( !UFG::AISidewalkGraph::OkayToTraverseFrom(v49, v8, sidewalkWanderData) )
        --v45;
      ++v46;
    }
    while ( v46 < v47 );
    v42 = v8->mPtr;
    v9 = v139;
  }
  if ( v45 <= 1 )
  {
    v83 = 0;
    if ( v42->mConnectionsCount > 0u )
    {
      v84 = v42->mConnectionsCount;
      while ( 1 )
      {
        v85 = (_QWORD *)(v44 + 8i64 * v83);
        v86 = (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)((char *)v85 + *v85);
        if ( !*v85 )
          v86 = 0i64;
        if ( UFG::AISidewalkGraph::OkayToTraverseFrom(v86, v8, sidewalkWanderData) )
          break;
        if ( ++v83 >= v84 )
          goto LABEL_117;
      }
      v87 = v86->mPtr;
      UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(v9, v86->mObjUID, v86->mNameUID, v86->mIndex);
      v88 = v87->mpStartNodeHandle.mOffset ? (UFG::AISidewalkEdge_Game *)((char *)v87 + v87->mpStartNodeHandle.mOffset) : 0i64;
      v89 = *(_QWORD *)&v88->mOutlineVerts[1].x;
      if ( v89 )
      {
        v92 = *(_DWORD *)(v89 + 16);
        v93 = *(_DWORD *)(v89 + 12);
        v121 = 0i64;
        v94 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
        {
          v95 = UFG::qResourceWarehouse::Instance();
          v94 = UFG::qResourceWarehouse::GetInventory(v95, 0x43E99F7Eu);
          `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v94;
        }
        UFG::qResourceHandle::Close(&v118, v94);
        LOWORD(v119) = -1;
        objUID = v93;
        v96 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
        {
          v97 = UFG::qResourceWarehouse::Instance();
          v96 = UFG::qResourceWarehouse::GetInventory(v97, 0x43E99F7Eu);
          `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v96;
        }
        UFG::qResourceHandle::Init(&v118, 0x43E99F7Eu, v92, v96);
      }
      else
      {
        v121 = 0i64;
        v90 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
        {
          v91 = UFG::qResourceWarehouse::Instance();
          v90 = UFG::qResourceWarehouse::GetInventory(v91, 0x43E99F7Eu);
          `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v90;
        }
        UFG::qResourceHandle::Close(&v118, v90);
        LOWORD(v119) = -1;
        objUID = -1;
        v118.mNameUID = -1;
        v121 = 0i64;
      }
      if ( v8->mObjUID == objUID )
      {
        v98 = v87->mpEndNodeHandle.mOffset;
        if ( v98 )
          v99 = (signed __int64)&v87->mpEndNodeHandle + v98;
        else
          v99 = 0i64;
        v100 = *(_QWORD *)(v99 + 40);
        if ( !v100 )
        {
          v121 = 0i64;
          v101 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
          if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
          {
            v102 = UFG::qResourceWarehouse::Instance();
            v101 = UFG::qResourceWarehouse::GetInventory(v102, 0x43E99F7Eu);
            `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v101;
          }
          UFG::qResourceHandle::Close(&v118, v101);
          LOWORD(v119) = -1;
          objUID = -1;
          v118.mNameUID = -1;
          v121 = 0i64;
          goto LABEL_120;
        }
        v81 = *(_DWORD *)(v100 + 16);
        v82 = *(_DWORD *)(v100 + 12);
        v121 = 0i64;
LABEL_112:
        v103 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
        {
          v104 = UFG::qResourceWarehouse::Instance();
          v103 = UFG::qResourceWarehouse::GetInventory(v104, 0x43E99F7Eu);
          `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v103;
        }
        UFG::qResourceHandle::Close(&v118, v103);
        v105 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
        objUID = v82;
        LOWORD(v119) = -1;
        if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
        {
          v106 = UFG::qResourceWarehouse::Instance();
          v105 = UFG::qResourceWarehouse::GetInventory(v106, 0x43E99F7Eu);
          `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v105;
        }
        UFG::qResourceHandle::Init(&v118, 0x43E99F7Eu, v81, v105);
        goto LABEL_117;
      }
    }
  }
  else
  {
    v50 = 0.0;
    v51 = 0.0;
    v52 = 0i64;
    v53 = 0;
    if ( v42->mConnectionsCount > 0u )
    {
      do
      {
        v54 = (__int64 *)(v44 + 8i64 * v53);
        v55 = *v54;
        if ( *v54 )
          v52 = (UFG::AISidewalkEdge_Game **)((char *)v54 + v55);
        if ( *((_DWORD *)v52 + 9) != v124 )
        {
          v56 = (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)(v55 ? (__int64 *)((char *)v54 + v55) : 0i64);
          if ( UFG::AISidewalkGraph::OkayToTraverseFrom(v56, v8, sidewalkWanderData) )
            v51 = v51 + UFG::GetEffectiveNodeRadius(v52[5], v8, entityLocation, pCurrentFacing);
        }
        ++v53;
        v52 = 0i64;
      }
      while ( v53 < v8->mPtr->mConnectionsCount );
    }
    v57 = UFG::qRandom(v51, &UFG::qDefaultSeed);
    v58 = -1;
    for ( i = 0; i < v8->mPtr->mConnectionsCount; ++i )
    {
      v60 = (_QWORD *)(v44 + 8i64 * i);
      if ( *v60 )
        v61 = (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)((char *)v60 + *v60);
      else
        v61 = 0i64;
      v62 = v61->mPtr;
      if ( v61->mObjUID != v124 && UFG::AISidewalkGraph::OkayToTraverseFrom(v61, v8, sidewalkWanderData) )
      {
        v58 = i;
        v50 = v50 + UFG::GetEffectiveNodeRadius(v62, v8, entityLocation, pCurrentFacing);
        if ( v50 >= v57 )
          break;
      }
    }
    v63 = (_QWORD *)(v44 + 8i64 * v58);
    if ( *v63 )
      v64 = (char *)v63 + *v63;
    else
      v64 = 0i64;
    v65 = (_QWORD *)*((_QWORD *)v64 + 5);
    UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
      v139,
      *((_DWORD *)v64 + 9),
      *((_DWORD *)v64 + 6),
      *((unsigned __int16 *)v64 + 16));
    if ( *v65 )
      v66 = (char *)v65 + *v65;
    else
      v66 = 0i64;
    v67 = *((_QWORD *)v66 + 5);
    if ( v67 )
    {
      v70 = *(_DWORD *)(v67 + 16);
      v71 = *(_DWORD *)(v67 + 12);
      v121 = 0i64;
      v72 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
      {
        v73 = UFG::qResourceWarehouse::Instance();
        v72 = UFG::qResourceWarehouse::GetInventory(v73, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v72;
      }
      UFG::qResourceHandle::Close(&v118, v72);
      LOWORD(v119) = -1;
      objUID = v71;
      v74 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
      {
        v75 = UFG::qResourceWarehouse::Instance();
        v74 = UFG::qResourceWarehouse::GetInventory(v75, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v74;
      }
      UFG::qResourceHandle::Init(&v118, 0x43E99F7Eu, v70, v74);
    }
    else
    {
      v121 = 0i64;
      v68 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
      {
        v69 = UFG::qResourceWarehouse::Instance();
        v68 = UFG::qResourceWarehouse::GetInventory(v69, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v68;
      }
      UFG::qResourceHandle::Close(&v118, v68);
      LOWORD(v119) = -1;
      objUID = -1;
      v118.mNameUID = -1;
      v121 = 0i64;
    }
    if ( v8->mObjUID == objUID )
    {
      v76 = v65[1];
      if ( v76 )
        v77 = (signed __int64)v65 + v76 + 8;
      else
        v77 = 0i64;
      v78 = *(_QWORD *)(v77 + 40);
      if ( !v78 )
      {
        v121 = 0i64;
        v79 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
        {
          v80 = UFG::qResourceWarehouse::Instance();
          v79 = UFG::qResourceWarehouse::GetInventory(v80, 0x43E99F7Eu);
          `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v79;
        }
        UFG::qResourceHandle::Close(&v118, v79);
        LOWORD(v119) = -1;
        objUID = -1;
        v118.mNameUID = -1;
        v121 = 0i64;
        goto LABEL_120;
      }
      v81 = *(_DWORD *)(v78 + 16);
      v82 = *(_DWORD *)(v78 + 12);
      v121 = 0i64;
      goto LABEL_112;
    }
  }
LABEL_117:
  if ( !v121 || *(_WORD *)(v121 + 34) == 0 )
  {
LABEL_120:
    v107 = 0;
    goto LABEL_121;
  }
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(v8, objUID, v118.mNameUID, (unsigned __int16)v119);
  UFG::AISidewalkGraph::GetDestinationPointFromNode(v8, destPos, isGroupLeader);
  v107 = 1;
LABEL_121:
  v108 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v109 = UFG::qResourceWarehouse::Instance();
    v108 = UFG::qResourceWarehouse::GetInventory(v109, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v108;
  }
  UFG::qResourceHandle::Close(&v126, v108);
  UFG::qResourceHandle::~qResourceHandle(&v126);
  v110 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v111 = UFG::qResourceWarehouse::Instance();
    v110 = UFG::qResourceWarehouse::GetInventory(v111, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v110;
  }
  UFG::qResourceHandle::Close(&v130, v110);
  UFG::qResourceHandle::~qResourceHandle(&v130);
  v112 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v113 = UFG::qResourceWarehouse::Instance();
    v112 = UFG::qResourceWarehouse::GetInventory(v113, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v112;
  }
  UFG::qResourceHandle::Close(&v122, v112);
  UFG::qResourceHandle::~qResourceHandle(&v122);
  v114 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v115 = UFG::qResourceWarehouse::Instance();
    v114 = UFG::qResourceWarehouse::GetInventory(v115, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v114;
  }
  UFG::qResourceHandle::Close(&v134, v114);
  UFG::qResourceHandle::~qResourceHandle(&v134);
  v116 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v117 = UFG::qResourceWarehouse::Instance();
    v116 = UFG::qResourceWarehouse::GetInventory(v117, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v116;
  }
  UFG::qResourceHandle::Close(&v118, v116);
  UFG::qResourceHandle::~qResourceHandle(&v118);
  return v107;
}

// File Line: 1105
// RVA: 0x34B560
bool __fastcall UFG::AISidewalkGraph::CalculateInitialDestinationPoint(UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *currentEdge, UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *destinationNode, UFG::qVector3 *pDestinationPoint, UFG::qVector3 *pCurrentPos, UFG::qVector3 *pCurrentFacing, const bool isGroupLeader, UFG::AIEntityComponent *pAIEntityComponent, UFG::SidewalkWanderData *sidewalkWanderData)
{
  UFG::AISidewalkEdge_Game *v8; // rbx
  __int64 v9; // rax
  signed __int64 v10; // rdi
  UFG::qVector3 *v11; // r12
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v12; // r15
  UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *v13; // rbp
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v14; // rdx
  bool v15; // r14
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v16; // rdx
  __int64 v17; // rax
  __int64 v18; // rax
  char *v19; // rcx
  __int64 v20; // rax
  float *v21; // rdx
  signed __int64 v22; // rcx
  __int64 v23; // r8
  float v24; // xmm9_4
  __m128 v25; // xmm8
  float v26; // xmm10_4
  __m128 v27; // xmm2
  float v28; // xmm1_4
  float v29; // xmm8_4
  float v30; // xmm9_4
  float v31; // xmm10_4
  float v32; // xmm3_4
  __m128 v33; // xmm4
  float v34; // xmm5_4
  __m128 v35; // xmm2
  float v36; // xmm6_4
  float v37; // xmm2_4
  bool v38; // cf
  bool v39; // zf
  float v40; // xmm3_4

  v8 = currentEdge->mPtr;
  v9 = v8->mpEndNodeHandle.mOffset;
  v10 = 0i64;
  v11 = pDestinationPoint;
  v12 = destinationNode;
  v13 = currentEdge;
  if ( v9 )
    v14 = (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)((char *)&v8->mpEndNodeHandle + v9);
  else
    v14 = 0i64;
  v15 = UFG::AISidewalkGraph::OkayToTraverseFrom(currentEdge, v14, sidewalkWanderData);
  v16 = (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)((char *)v8 + v8->mpStartNodeHandle.mOffset);
  if ( !v8->mpStartNodeHandle.mOffset )
    v16 = 0i64;
  if ( UFG::AISidewalkGraph::OkayToTraverseFrom(v13, v16, sidewalkWanderData) )
  {
    if ( !v15 )
      goto LABEL_8;
    v19 = (char *)v8 + v8->mpStartNodeHandle.mOffset;
    if ( !v8->mpStartNodeHandle.mOffset )
      v19 = 0i64;
    v20 = v8->mpEndNodeHandle.mOffset;
    v21 = (float *)*((_QWORD *)v19 + 5);
    if ( v20 )
      v22 = (signed __int64)&v8->mpEndNodeHandle + v20;
    else
      v22 = 0i64;
    v23 = *(_QWORD *)(v22 + 40);
    v24 = pCurrentFacing->y;
    v25 = (__m128)LODWORD(pCurrentFacing->x);
    v26 = pCurrentFacing->z;
    v27 = v25;
    v27.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v24 * v24)) + (float)(v26 * v26);
    if ( v27.m128_f32[0] == 0.0 )
      v28 = 0.0;
    else
      v28 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v27));
    v33 = (__m128)*(unsigned int *)(v23 + 4);
    v29 = v25.m128_f32[0] * v28;
    v30 = v24 * v28;
    v31 = v26 * v28;
    v32 = *(float *)v23 - *v21;
    v33.m128_f32[0] = v33.m128_f32[0] - v21[1];
    v34 = *(float *)(v23 + 8) - v21[2];
    v35 = v33;
    v35.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v32 * v32)) + (float)(v34 * v34);
    if ( COERCE_FLOAT(_mm_sqrt_ps(v35)) > 0.001 )
    {
      if ( v35.m128_f32[0] == 0.0 )
        v36 = 0.0;
      else
        v36 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
      v32 = v32 * v36;
      v33.m128_f32[0] = v33.m128_f32[0] * v36;
      v34 = v34 * v36;
    }
    if ( sidewalkWanderData->mPreviousDesiredDirectionValid )
    {
      v37 = (float)((float)(sidewalkWanderData->mPreviousDesiredDirection.y * v33.m128_f32[0])
                  + (float)(sidewalkWanderData->mPreviousDesiredDirection.x * v32))
          + (float)(sidewalkWanderData->mPreviousDesiredDirection.z * v34);
      v38 = v37 < 0.0;
      v39 = v37 == 0.0;
    }
    else
    {
      v40 = (float)((float)(v32 * v29) + (float)(v33.m128_f32[0] * v30)) + (float)(v34 * v31);
      v38 = v40 < 0.0;
      v39 = v40 == 0.0;
    }
    if ( !v38 && !v39 )
      goto LABEL_8;
  }
  else if ( !v15 )
  {
LABEL_8:
    v17 = v8->mpEndNodeHandle.mOffset;
    if ( v17 )
      v10 = (signed __int64)&v8->mpEndNodeHandle + v17;
    goto LABEL_10;
  }
  if ( v8->mpStartNodeHandle.mOffset )
    v10 = (signed __int64)v8 + v8->mpStartNodeHandle.mOffset;
LABEL_10:
  v18 = *(_QWORD *)(v10 + 40);
  if ( v18 )
    UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game>::_Set(v12, *(_DWORD *)(v18 + 12), *(_DWORD *)(v18 + 16));
  else
    UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(v12);
  return UFG::AISidewalkGraph::GetDestinationPointFromNode(v12, v11, isGroupLeader);
}

// File Line: 1217
// RVA: 0x34A090
void __fastcall UFG::AISidewalkGraph::CalculateCrosswalkLanes(UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *ppCurrentEdge, UFG::CrosswalkLanes *lanes)
{
  UFG::CrosswalkLanes *rbx1; // rbx
  UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *v3; // rdi
  UFG::AISidewalkEdge_Game *v4; // rcx
  char *v5; // rax
  float *v6; // rax
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  __int64 v10; // rax
  signed __int64 v11; // rax
  float *v12; // rax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::qArray<unsigned long,0> *v16; // r12
  int *v17; // rcx
  UFG::qArray<unsigned long,0> *v18; // r15
  int *v19; // rcx
  unsigned __int64 v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // rbx
  _DWORD *v23; // rcx
  unsigned int i; // er8
  unsigned __int64 v25; // rax
  UFG::allocator::free_link *v26; // rax
  UFG::allocator::free_link *v27; // rbx
  _DWORD *v28; // rcx
  unsigned int j; // er8
  UFG::RoadNetworkResource *v30; // rax
  unsigned int k; // edi
  _DWORD *v32; // rbx
  UFG::RoadNetworkResource *v33; // rax
  UFG::RoadNetworkIntersection *v34; // rax
  UFG::RoadNetworkNode *v35; // rbx
  UFG::RoadNetworkLane *v36; // r14
  float v37; // xmm4_4
  float v38; // xmm5_4
  __m128 v39; // xmm3
  __m128 v40; // xmm7
  __m128 v41; // xmm2
  float v42; // xmm1_4
  __m128 v43; // xmm2
  float v44; // xmm2_4
  float v45; // xmm0_4
  bool v46; // bl
  UFG::qVector3 result; // [rsp+38h] [rbp-A0h]
  UFG::qVector3 v2; // [rsp+48h] [rbp-90h]
  UFG::qVector3 v1; // [rsp+58h] [rbp-80h]
  int v50; // [rsp+64h] [rbp-74h]
  void *mem; // [rsp+68h] [rbp-70h]
  float v52; // [rsp+70h] [rbp-68h]
  UFG::qArray<int,0> aLanes; // [rsp+78h] [rbp-60h]

  rbx1 = lanes;
  v3 = ppCurrentEdge;
  if ( UFG::WheeledVehicleManager::m_Instance
    || UFG::WheeledVehicleManager::m_Instance->m_NavigationData
    || UFG::WheeledVehicleNavigationData::GetRoadNetwork(0i64) )
  {
    v4 = v3->mPtr;
    if ( v4->mpStartNodeHandle.mOffset )
      v5 = (char *)v4 + v4->mpStartNodeHandle.mOffset;
    else
      v5 = 0i64;
    v6 = (float *)*((_QWORD *)v5 + 5);
    v7 = *v6;
    v8 = v6[1];
    v9 = v6[2];
    v1.x = *v6;
    v1.y = v8;
    v1.z = v9;
    v10 = v4->mpEndNodeHandle.mOffset;
    if ( v10 )
      v11 = (signed __int64)&v4->mpEndNodeHandle + v10;
    else
      v11 = 0i64;
    v12 = *(float **)(v11 + 40);
    v14 = v12[1];
    v15 = v12[2];
    v2.x = *v12;
    v13 = v2.x;
    v2.y = v14;
    v2.z = v15;
    rbx1->m_v1.x = v7;
    rbx1->m_v1.y = v8;
    rbx1->m_v1.z = v9;
    rbx1->m_v2.x = v13;
    rbx1->m_v2.y = v14;
    rbx1->m_v2.z = v15;
    v16 = (UFG::qArray<unsigned long,0> *)&rbx1->m_iIntersectionID;
    v17 = rbx1->m_iIntersectionID.p;
    if ( v17 )
      operator delete[](v17);
    rbx1->m_iIntersectionID.p = 0i64;
    *(_QWORD *)&v16->size = 0i64;
    v18 = (UFG::qArray<unsigned long,0> *)&rbx1->m_aLanes;
    v19 = rbx1->m_aLanes.p;
    if ( v19 )
      operator delete[](v19);
    rbx1->m_aLanes.p = 0i64;
    *(_QWORD *)&v18->size = 0i64;
    mem = 0i64;
    *(_QWORD *)&v1.z = 0i64;
    *(_QWORD *)&v1.x = 0i64;
    *(_QWORD *)&aLanes.size = 0i64;
    v20 = 128i64;
    if ( !is_mul_ok(0x20ui64, 4ui64) )
      v20 = -1i64;
    v21 = UFG::qMalloc(v20, "qArray.Reserve.Intersections", 0i64);
    v22 = v21;
    v23 = mem;
    if ( mem )
    {
      for ( i = 0; i < LODWORD(v1.z); v23 = mem )
      {
        *((_DWORD *)&v21->mNext + i) = v23[i];
        ++i;
      }
      operator delete[](v23);
    }
    mem = v22;
    v50 = 32;
    if ( aLanes.capacity < 0x20 && aLanes.size != 32 )
    {
      v25 = 128i64;
      if ( !is_mul_ok(0x20ui64, 4ui64) )
        v25 = -1i64;
      v26 = UFG::qMalloc(v25, "qArray.Reserve.LinesIntersecting", 0i64);
      v27 = v26;
      v28 = *(_DWORD **)&v1.x;
      if ( *(_QWORD *)&v1.x )
      {
        for ( j = 0; j < aLanes.size; v28 = *(_DWORD **)&v1.x )
        {
          *((_DWORD *)&v26->mNext + j) = v28[j];
          ++j;
        }
        operator delete[](v28);
      }
      *(_QWORD *)&v1.x = v27;
      aLanes.capacity = 32;
    }
    v30 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
    UFG::RoadNetworkResource::GetLanesIntersectingLine2D(v30, &v1, &v2, (UFG::qArray<int,0> *)&v1.z, &aLanes, 80.0);
    for ( k = 0; k < aLanes.size; ++k )
    {
      v32 = mem;
      v33 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
      v34 = UFG::RoadNetworkResource::GetIntersection(v33, v32[k]);
      v35 = (UFG::RoadNetworkNode *)&v34->mType;
      if ( v34->mNumLightPhases )
      {
        v36 = UFG::RoadNetworkNode::GetLane(
                (UFG::RoadNetworkNode *)&v34->mType,
                *(_DWORD *)(*(_QWORD *)&v1.x + 4i64 * k));
        UFG::RoadNetworkNode::GetTangent(v35, &result, v36->mLaneIndex, 1.0);
        v37 = v2.z - v1.z;
        v38 = v2.y - v1.y;
        v39 = (__m128)LODWORD(v2.x);
        v39.m128_f32[0] = v2.x - v1.x;
        v40 = (__m128)LODWORD(result.x);
        v41 = v40;
        v41.m128_f32[0] = (float)((float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(result.y * result.y))
                        + (float)(result.z * result.z);
        v42 = v41.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v41));
        result.x = result.x * v42;
        result.y = result.y * v42;
        result.z = result.z * v42;
        v43 = v39;
        v43.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v38 * v38)) + (float)(v37 * v37);
        v44 = v43.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v43));
        v45 = v44 * v38;
        *(float *)&mem = v39.m128_f32[0] * v44;
        *((float *)&mem + 1) = v44 * v38;
        v52 = v44 * v37;
        UFG::qAngleBetweenNormals(&result, (UFG::qVector3 *)&mem);
        v46 = v45 < 1.8325958 && v45 > 1.3089969;
        if ( (unsigned int)UFG::RoadNetworkLane::GetTurnDirection(v36) != 1
          && (!v46 || (unsigned int)UFG::RoadNetworkLane::GetTurnDirection(v36) != 2) )
        {
          UFG::qArray<int,0>::Add(v16, (const unsigned int *)mem + k, "qArray.Add.aLanesIntersecting");
          UFG::qArray<int,0>::Add(
            v18,
            (const unsigned int *)(*(_QWORD *)&v1.x + 4i64 * k),
            "qArray.Add.aLanesIntersecting");
        }
      }
    }
    if ( *(_QWORD *)&v1.x )
      operator delete[](*(void **)&v1.x);
    *(_QWORD *)&v1.x = 0i64;
    *(_QWORD *)&aLanes.size = 0i64;
    if ( mem )
      operator delete[](mem);
  }
}

// File Line: 1281
// RVA: 0x36A440
char __fastcall UFG::AISidewalkGraph::IsCrosswalkCrossable(UFG::CrosswalkLanes *lanes, float fTimeToCross)
{
  unsigned int v2; // eax
  UFG::CrosswalkLanes *v3; // r14
  __int64 v5; // rbp
  int *v6; // rbx
  UFG::RoadNetworkResource *v7; // rax
  UFG::RoadNetworkIntersection *v8; // rdi
  UFG::RoadNetworkLane *v9; // rbx
  float v10; // xmm0_4

  v2 = lanes->m_aLanes.size;
  v3 = lanes;
  if ( !v2 )
    return 1;
  v5 = 0i64;
  if ( !v2 )
    return 1;
  while ( 1 )
  {
    v6 = v3->m_iIntersectionID.p;
    v7 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
    v8 = UFG::RoadNetworkResource::GetIntersection(v7, v6[v5]);
    v9 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v8->mType, v3->m_aLanes.p[v5]);
    v10 = UFG::RoadNetworkIntersection::GetRemainingGreenLightTime(v8);
    if ( v9->mStatus.mValue || fTimeToCross > v10 )
      break;
    v5 = (unsigned int)(v5 + 1);
    if ( (unsigned int)v5 >= v3->m_aLanes.size )
      return 1;
  }
  return 0;
}

// File Line: 1464
// RVA: 0x377C60
bool __fastcall UFG::AISidewalkGraph::OkayToTraverseFrom(UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *pEdge, UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *pCurrentNode, UFG::SidewalkWanderData *pSidewalkWanderData)
{
  UFG::AISidewalkEdge_Game *v3; // rcx
  UFG::SidewalkWanderData *v4; // r9
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v5; // r8
  signed __int64 v6; // rax
  char *v7; // rdx
  bool v8; // dl
  __int64 v9; // rdx
  signed __int64 v10; // rdx
  __int64 v11; // rdx
  bool v12; // r8
  unsigned int v13; // eax

  v3 = pEdge->mPtr;
  v4 = pSidewalkWanderData;
  v5 = pCurrentNode;
  if ( !v3 )
    goto LABEL_26;
  v6 = 0i64;
  if ( v3->mpStartNodeHandle.mOffset )
    v7 = (char *)v3 + v3->mpStartNodeHandle.mOffset;
  else
    v7 = 0i64;
  if ( *((_QWORD *)v7 + 5) )
  {
    if ( v3->mpStartNodeHandle.mOffset )
      v6 = (signed __int64)v3 + v3->mpStartNodeHandle.mOffset;
    v8 = v5->mObjUID == *(_DWORD *)(v6 + 36);
    goto LABEL_16;
  }
  v9 = v3->mpEndNodeHandle.mOffset;
  if ( v9 )
    v10 = (signed __int64)&v3->mpEndNodeHandle + v9;
  else
    v10 = 0i64;
  if ( *(_QWORD *)(v10 + 40) )
  {
    v11 = v3->mpEndNodeHandle.mOffset;
    if ( v11 )
      v6 = (signed __int64)&v3->mpEndNodeHandle + v11;
    v8 = v5->mObjUID != *(_DWORD *)(v6 + 36);
LABEL_16:
    v12 = 0;
    if ( v4 )
      v12 = v4->mAllowedToUseCrosswalks;
    v13 = v3->mFlags;
    if ( (v13 & 8 && v8 || v13 & 0x10 && !v8) && (v12 || !(v13 & 4)) && UFG::AISidewalkGraph::IsActive(v3) )
    {
      LOBYTE(v6) = 1;
      return v6;
    }
LABEL_26:
    LOBYTE(v6) = 0;
  }
  return v6;
}

// File Line: 1506
// RVA: 0x3639F0
void __fastcall UFG::AISidewalkGraph::HandleAlteredDataOnAdd(UFG::AISidewalkSectionResource *pSidewalkSection)
{
  UFG::SidewalkAlteredNodeData *v1; // rbx
  UFG::AISidewalkSectionResource *v2; // rbp
  UFG::AISidewalkNode_Game *v3; // rdx
  UFG::qList<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData,1,0> *v4; // r14
  unsigned __int8 v5; // r8
  UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *v6; // rax
  unsigned int v7; // er11
  signed __int64 v8; // rsi
  unsigned int v9; // er9
  __int64 v10; // r8
  __int64 v11; // r10
  signed __int64 v12; // rax
  signed __int64 v13; // rdx
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::AISidewalkNode_Game *v16; // rax

  v1 = (UFG::SidewalkAlteredNodeData *)UFG::AISidewalkGraph::sAlteredNodeData.mNode.mNext;
  v2 = pSidewalkSection;
  if ( (UFG::qList<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData,1,0> *)UFG::AISidewalkGraph::sAlteredNodeData.mNode.mNext != &UFG::AISidewalkGraph::sAlteredNodeData )
  {
    do
    {
      v3 = v1->mpNode.mPtr;
      v4 = (UFG::qList<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData,1,0> *)v1->mNext;
      if ( v3 )
      {
        if ( v1->mpNode.mNameUID == v2->mSectionVisId )
        {
          v5 = v1->mOverRideActiveValue;
          if ( (v1->mpNode.mPtr->mActive != 0) == (v5 != 0) )
          {
            v6 = v1->mPrev;
            v6->mNext = &v4->mNode;
            v4->mNode.mPrev = v6;
            v1->mPrev = (UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *)&v1->mPrev;
            v1->mNext = (UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *)&v1->mPrev;
            UFG::SidewalkAlteredNodeData::~SidewalkAlteredNodeData(v1);
            operator delete[](v1);
          }
          else
          {
            v1->mOriginalValueKnown = 1;
            v1->mOriginalValue = v3->mActive;
            v3->mActive = v5;
          }
        }
      }
      else if ( !v1->mOriginalValueKnown )
      {
        v7 = v2->mNodeCount;
        v8 = 0i64;
        v9 = 0;
        if ( v7 )
        {
          v10 = v2->mNodes.mOffset;
          v11 = 0i64;
          do
          {
            if ( v10 )
              v12 = (signed __int64)&v2->mNodes + v10;
            else
              v12 = 0i64;
            if ( *(_DWORD *)(v11 + v12 + 12) == v1->mNodeUid )
            {
              if ( v10 )
                v13 = (signed __int64)&v2->mNodes + v10;
              else
                v13 = 0i64;
              v8 = v13 + 40i64 * v9;
            }
            ++v9;
            v11 += 40i64;
          }
          while ( v9 < v7 );
        }
        if ( v8 )
        {
          UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game>::_Set(
            &v1->mpNode,
            *(_DWORD *)(v8 + 12),
            *(_DWORD *)(v8 + 16));
        }
        else
        {
          v1->mpNode.mPtr = 0i64;
          v14 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
          if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
          {
            v15 = UFG::qResourceWarehouse::Instance();
            v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x43E99F7Eu);
            `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v14;
          }
          UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mpNode.mPrev, v14);
          v1->mpNode.mIndex = -1;
          v1->mpNode.mObjUID = -1;
          v1->mpNode.mNameUID = -1;
          v1->mpNode.mPtr = 0i64;
        }
        v16 = v1->mpNode.mPtr;
        if ( v16 )
        {
          v1->mOriginalValueKnown = 1;
          v1->mOriginalValue = v16->mActive;
          *(_WORD *)(v8 + 34) = (unsigned __int8)v1->mOverRideActiveValue;
        }
      }
      v1 = (UFG::SidewalkAlteredNodeData *)v4;
    }
    while ( v4 != &UFG::AISidewalkGraph::sAlteredNodeData );
  }
}

// File Line: 1632
// RVA: 0x387790
void __fastcall UFG::AISidewalkGraph::SetNodeActive(unsigned int hashId, bool val)
{
  bool v2; // r14
  unsigned int v3; // esi
  UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *v4; // rax
  UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *v5; // rcx
  UFG::AISidewalkNode_Game *v6; // rbp
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rdi
  signed __int64 v9; // rbx
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v10; // rcx
  UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *v11; // rax

  if ( hashId != -1 )
  {
    v2 = val;
    v3 = hashId;
    v4 = UFG::AISidewalkGraph::sAlteredNodeData.mNode.mNext;
    if ( (UFG::qList<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData,1,0> *)UFG::AISidewalkGraph::sAlteredNodeData.mNode.mNext == &UFG::AISidewalkGraph::sAlteredNodeData )
    {
LABEL_8:
      v6 = UFG::AISidewalkNode_Game::GetFromObjUID_Slow(hashId);
      v7 = UFG::qMalloc(0x48ui64, "AISidewalkGraph", 0i64);
      v8 = v7;
      if ( v7 )
      {
        v7->mNext = v7;
        v7[1].mNext = v7;
        v9 = (signed __int64)&v7[2];
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v7[2]);
        *(_DWORD *)(v9 + 32) = 0xFFFF;
        *(_DWORD *)(v9 + 36) = -1;
        *(_QWORD *)(v9 + 40) = 0i64;
        *(_DWORD *)(v9 + 24) = -1;
      }
      else
      {
        v8 = 0i64;
      }
      v10 = (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&v8[2];
      if ( v6 )
        UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game>::_Set(v10, v6->mObjId, v6->mCellId);
      else
        UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(v10);
      LODWORD(v8[8].mNext) = v3;
      BYTE4(v8[8].mNext) = v2;
      if ( v8[7].mNext )
      {
        BYTE5(v8[8].mNext) = 1;
        BYTE6(v8[8].mNext) = v6->mActive;
        v6->mActive = v2;
      }
      else
      {
        BYTE5(v8[8].mNext) = 0;
      }
      v11 = UFG::AISidewalkGraph::sAlteredNodeData.mNode.mNext;
      UFG::AISidewalkGraph::sAlteredNodeData.mNode.mNext = (UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *)v8;
      v8->mNext = (UFG::allocator::free_link *)&UFG::AISidewalkGraph::sAlteredNodeData;
      v8[1].mNext = (UFG::allocator::free_link *)v11;
      v11->mPrev = (UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *)v8;
    }
    else
    {
      while ( LODWORD(v4[4].mPrev) != hashId )
      {
        v4 = v4->mNext;
        if ( v4 == (UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *)&UFG::AISidewalkGraph::sAlteredNodeData )
          goto LABEL_8;
      }
      BYTE4(v4[4].mPrev) = val;
      v5 = v4[3].mNext;
      if ( v5 )
        WORD1(v5[2].mPrev) = val;
    }
  }
}

// File Line: 1706
// RVA: 0x369780
char __fastcall UFG::AISidewalkGraph::IsActive(UFG::AISidewalkEdge_Game *pEdge)
{
  char *v1; // rdx
  char *v2; // r8
  __int64 v3; // rax
  __int64 v4; // rax
  __int64 v5; // rax
  unsigned int v6; // eax
  char result; // al

  if ( !pEdge )
    goto LABEL_16;
  v1 = 0i64;
  v2 = (char *)pEdge + pEdge->mpStartNodeHandle.mOffset;
  if ( !pEdge->mpStartNodeHandle.mOffset )
    v2 = 0i64;
  v3 = *((_QWORD *)v2 + 5);
  if ( !v3 || *(_WORD *)(v3 + 34) == 0 )
    goto LABEL_16;
  v4 = pEdge->mpEndNodeHandle.mOffset;
  if ( v4 )
    v1 = (char *)&pEdge->mpEndNodeHandle + v4;
  v5 = *((_QWORD *)v1 + 5);
  if ( v5 && *(_WORD *)(v5 + 34) != 0 && (v6 = pEdge->mFlags, v6 & 2) && (v6 & 0x80u) == 0 )
    result = 1;
  else
LABEL_16:
    result = 0;
  return result;
}

