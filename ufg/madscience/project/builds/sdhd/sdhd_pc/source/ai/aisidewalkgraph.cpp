// File Line: 55
// RVA: 0x14AD460
__int64 dynamic_initializer_for__UFG::AISidewalkGraph::sAIGraphDirectory__()
{
  UFG::qString::qString(&UFG::AISidewalkGraph::sAIGraphDirectory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AISidewalkGraph::sAIGraphDirectory__);
}

// File Line: 71
// RVA: 0x14AE9A0
__int64 dynamic_initializer_for__UFG::AISidewalkGraph::sSections__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AISidewalkGraph::sSections__);
}

// File Line: 72
// RVA: 0x14AE980
__int64 dynamic_initializer_for__UFG::AISidewalkGraph::sLastSectionName__()
{
  UFG::qString::qString(&UFG::AISidewalkGraph::sLastSectionName);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AISidewalkGraph::sLastSectionName__);
}

// File Line: 79
// RVA: 0x14AD480
__int64 dynamic_initializer_for__UFG::AISidewalkGraph::sAlteredNodeData__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AISidewalkGraph::sAlteredNodeData__);
}

// File Line: 88
// RVA: 0x34F2C0
void __fastcall UFG::SidewalkWanderData::ClearData(UFG::SidewalkWanderData *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  int *p; // rcx
  int *v9; // rcx

  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)this);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&this->mGoals[0].mpDestinationNode);
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->mGoals[0].mPosition.x = UFG::qVector3::msZero.x;
  this->mGoals[0].mPosition.y = y;
  this->mGoals[0].mPosition.z = z;
  this->mGoals[0].mGoalId = -1;
  this->mGoals[0].mIsValid = 0;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&this->mGoals[1]);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&this->mGoals[1].mpDestinationNode);
  v4 = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mGoals[1].mPosition.x = UFG::qVector3::msZero.x;
  this->mGoals[1].mPosition.y = v4;
  this->mGoals[1].mPosition.z = v5;
  this->mGoals[1].mGoalId = -1;
  this->mGoals[1].mIsValid = 0;
  this->mAllowedToUseCrosswalks = 0;
  this->mPreviousDesiredDirectionValid = 0;
  v6 = UFG::qVector3::msZero.y;
  v7 = UFG::qVector3::msZero.z;
  this->mPreviousDesiredDirection.x = UFG::qVector3::msZero.x;
  this->mPreviousDesiredDirection.y = v6;
  this->mPreviousDesiredDirection.z = v7;
  *(_WORD *)&this->mAtCrossWalk = 0;
  this->mIsDestinationSegment = 0;
  p = this->mCrosswalkLanes.m_iIntersectionID.p;
  if ( p )
    operator delete[](p);
  this->mCrosswalkLanes.m_iIntersectionID.p = 0i64;
  *(_QWORD *)&this->mCrosswalkLanes.m_iIntersectionID.size = 0i64;
  v9 = this->mCrosswalkLanes.m_aLanes.p;
  if ( v9 )
    operator delete[](v9);
  this->mCrosswalkLanes.m_aLanes.p = 0i64;
  *(_QWORD *)&this->mCrosswalkLanes.m_aLanes.size = 0i64;
}

// File Line: 123
// RVA: 0x33C000
UFG::SidewalkWanderData *__fastcall UFG::SidewalkWanderData::operator=(
        UFG::SidewalkWanderData *this,
        UFG::SidewalkWanderData *data)
{
  float x; // eax
  float z; // xmm1_4
  float v6; // eax
  float v7; // xmm1_4
  float y; // xmm0_4
  float v9; // xmm1_4

  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)this,
    data->mGoals[0].mpSidewalkEdge.mObjUID,
    data->mGoals[0].mpSidewalkEdge.mNameUID,
    data->mGoals[0].mpSidewalkEdge.mIndex);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    &this->mGoals[0].mpDestinationNode,
    data->mGoals[0].mpDestinationNode.mObjUID,
    data->mGoals[0].mpDestinationNode.mNameUID,
    data->mGoals[0].mpDestinationNode.mIndex);
  x = data->mGoals[0].mPosition.x;
  z = data->mGoals[0].mPosition.z;
  this->mGoals[0].mPosition.y = data->mGoals[0].mPosition.y;
  this->mGoals[0].mPosition.z = z;
  this->mGoals[0].mPosition.x = x;
  this->mGoals[0].mGoalId = data->mGoals[0].mGoalId;
  this->mGoals[0].mIsValid = data->mGoals[0].mIsValid;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&this->mGoals[1],
    data->mGoals[1].mpSidewalkEdge.mObjUID,
    data->mGoals[1].mpSidewalkEdge.mNameUID,
    data->mGoals[1].mpSidewalkEdge.mIndex);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    &this->mGoals[1].mpDestinationNode,
    data->mGoals[1].mpDestinationNode.mObjUID,
    data->mGoals[1].mpDestinationNode.mNameUID,
    data->mGoals[1].mpDestinationNode.mIndex);
  v6 = data->mGoals[1].mPosition.x;
  v7 = data->mGoals[1].mPosition.z;
  this->mGoals[1].mPosition.y = data->mGoals[1].mPosition.y;
  this->mGoals[1].mPosition.z = v7;
  this->mGoals[1].mPosition.x = v6;
  this->mGoals[1].mGoalId = data->mGoals[1].mGoalId;
  this->mGoals[1].mIsValid = data->mGoals[1].mIsValid;
  this->mPreviousDesiredDirectionValid = data->mPreviousDesiredDirectionValid;
  y = data->mPreviousDesiredDirection.y;
  v9 = data->mPreviousDesiredDirection.z;
  this->mPreviousDesiredDirection.x = data->mPreviousDesiredDirection.x;
  this->mPreviousDesiredDirection.y = y;
  this->mPreviousDesiredDirection.z = v9;
  this->mAllowedToUseCrosswalks = data->mAllowedToUseCrosswalks;
  this->mLastUpdateFrame = data->mLastUpdateFrame;
  return this;
}

// File Line: 136
// RVA: 0x36D640
void __fastcall UFG::SidewalkWanderData::MakeLookAheadCurrent(UFG::SidewalkWanderData *this)
{
  float x; // eax
  float z; // xmm0_4
  float y; // xmm1_4
  float v5; // xmm2_4

  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)this,
    this->mGoals[1].mpSidewalkEdge.mObjUID,
    this->mGoals[1].mpSidewalkEdge.mNameUID,
    this->mGoals[1].mpSidewalkEdge.mIndex);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    &this->mGoals[0].mpDestinationNode,
    this->mGoals[1].mpDestinationNode.mObjUID,
    this->mGoals[1].mpDestinationNode.mNameUID,
    this->mGoals[1].mpDestinationNode.mIndex);
  x = this->mGoals[1].mPosition.x;
  z = this->mGoals[1].mPosition.z;
  this->mGoals[0].mPosition.y = this->mGoals[1].mPosition.y;
  this->mGoals[0].mPosition.z = z;
  this->mGoals[0].mPosition.x = x;
  this->mGoals[0].mGoalId = this->mGoals[1].mGoalId;
  this->mGoals[0].mIsValid = this->mGoals[1].mIsValid;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&this->mGoals[1]);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&this->mGoals[1].mpDestinationNode);
  y = UFG::qVector3::msZero.y;
  v5 = UFG::qVector3::msZero.z;
  this->mGoals[1].mPosition.x = UFG::qVector3::msZero.x;
  this->mGoals[1].mPosition.y = y;
  this->mGoals[1].mPosition.z = v5;
  this->mGoals[1].mGoalId = -1;
  this->mGoals[1].mIsValid = 0;
}

// File Line: 142
// RVA: 0x3861D0
void __fastcall UFG::SidewalkWanderData::SetDestinationPos(
        UFG::SidewalkWanderData *this,
        UFG::qVector3 *destination,
        UFG::qVector3 *current_position)
{
  float y; // xmm1_4
  float z; // xmm0_4
  float v5; // xmm3_4
  __m128 y_low; // xmm4
  float v7; // xmm5_4
  __m128 v8; // xmm2
  float v9; // xmm0_4
  UFG::SidewalkWanderData::GoalInfo *v10; // rbx
  float v11; // xmm1_4
  float v12; // xmm2_4

  y = destination->y;
  z = destination->z;
  this->mGoals[0].mPosition.x = destination->x;
  this->mGoals[0].mPosition.z = z;
  this->mGoals[0].mPosition.y = y;
  this->mGoals[0].mIsValid = 1;
  y_low = (__m128)LODWORD(destination->y);
  v5 = destination->x - current_position->x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - current_position->y;
  v7 = destination->z - current_position->z;
  v8 = y_low;
  v8.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v5 * v5)) + (float)(v7 * v7);
  v9 = _mm_sqrt_ps(v8).m128_f32[0];
  if ( v9 <= 0.001 )
  {
    this->mPreviousDesiredDirectionValid = 0;
  }
  else
  {
    this->mPreviousDesiredDirection.z = (float)(1.0 / v9) * v7;
    this->mPreviousDesiredDirection.x = (float)(1.0 / v9) * v5;
    this->mPreviousDesiredDirection.y = (float)(1.0 / v9) * y_low.m128_f32[0];
    this->mPreviousDesiredDirectionValid = 1;
  }
  v10 = &this->mGoals[1];
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull((UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&this->mGoals[1]);
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(&v10->mpDestinationNode);
  v11 = UFG::qVector3::msZero.y;
  v12 = UFG::qVector3::msZero.z;
  v10->mPosition.x = UFG::qVector3::msZero.x;
  v10->mPosition.y = v11;
  v10->mPosition.z = v12;
  v10->mGoalId = -1;
  v10->mIsValid = 0;
}

// File Line: 164
// RVA: 0x368AD0
void UFG::AISidewalkGraph::Initialize(void)
{
  char v0; // cl
  UFG::Grid<UFG::AISidewalkEdge_Game> *v1; // rdi
  UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *mGridNodes; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game> > **p_mNext; // rbx
  UFG::Grid<UFG::AISidewalkEdge_Game> *v4; // rdi
  UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *v5; // rcx
  UFG::qNode<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game> > **v6; // rbx
  float x; // xmm6_4
  float y; // xmm7_4
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
    mGridNodes = gAISidewalkEdgeDataGrid->mGridNodes;
    if ( gAISidewalkEdgeDataGrid->mGridNodes )
    {
      p_mNext = &mGridNodes[-1].mNode.mNext;
      `eh vector destructor iterator(
        mGridNodes,
        0x10ui64,
        (int)mGridNodes[-1].mNode.mNext,
        (void (__fastcall *)(void *))UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0>::~qList<UFG::qReflectField,UFG::qReflectField,1,0>);
      operator delete[](p_mNext);
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
      `eh vector destructor iterator(
        v5,
        0x10ui64,
        (int)v5[-1].mNode.mNext,
        (void (__fastcall *)(void *))UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0>::~qList<UFG::qReflectField,UFG::qReflectField,1,0>);
      operator delete[](v6);
    }
    operator delete[](v4);
  }
  x = UFG::gWorldExtents_min.x;
  y = UFG::gWorldExtents_min.y;
  v9 = UFG::gWorldExtents_max.x;
  y_max = UFG::gWorldExtents_max.y;
  v11 = (UFG::Grid<UFG::RoadNetworkSegment> *)UFG::qMalloc(0x30ui64, "Grid<AISidewalkEdge_Game>", 0i64);
  v12 = (UFG::Grid<UFG::AISidewalkEdge_Game> *)v11;
  if ( v11 )
  {
    v11->mGridNodes = 0i64;
    UFG::Grid<UFG::RoadNetworkSegment>::Init(v11, x, y, v9, y_max, 125.0);
    gAISidewalkEdgeDataGrid = v12;
  }
  else
  {
    gAISidewalkEdgeDataGrid = 0i64;
  }
}

// File Line: 697
// RVA: 0x3561C0
void __fastcall UFG::AISidewalkGraph::FindClosestSidewalkConnection(
        UFG::qVector3 *pos,
        const float maxDist,
        UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *resultantEdge,
        unsigned __int8 searchFlags)
{
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v5; // rbp
  unsigned int VisIndexAtPosition; // eax
  UFG::Grid<UFG::AISidewalkEdge_Game> *v8; // rdi
  float x; // xmm8_4
  float mGridSizeInv; // xmm2_4
  __int64 mXDim; // r10
  float y; // xmm9_4
  int v13; // r11d
  int v14; // ebx
  int mYDim; // eax
  int v16; // r8d
  int v17; // ecx
  unsigned int v18; // edx
  __int64 v19; // rsi
  __int64 v20; // r9
  __int64 v21; // r10
  __int64 v22; // rcx
  __int64 v23; // r8
  float v24; // xmm10_4
  __int64 v25; // r15
  __int64 *v26; // r14
  __int64 v27; // rsi
  __int64 v28; // rdi
  __int64 v29; // rbx
  bool v30; // cl
  __int64 v31; // rdx
  __int64 v32; // rax
  __int64 v33; // rax
  __int64 v34; // rax
  __int64 v35; // rdx
  int v36; // eax
  __int64 v37; // rax
  __int64 v38; // rcx
  __int64 v39; // rdx
  float v40; // xmm10_4
  Render::SkinningCacheNode *Head; // r14
  UFG::qBaseTreeRB *Next; // rax
  unsigned int mChild1_high; // ecx
  UFG::qBaseTreeRB *v44; // r12
  UFG::qBaseNodeVariableRB<unsigned __int64> *mParent; // rsi
  __int64 v46; // rbp
  __int64 v47; // rdi
  char *v48; // rax
  int v49; // r9d
  char *v50; // rbx
  bool v51; // cl
  __int64 v52; // r8
  char *v53; // rax
  __int64 v54; // rdx
  __int64 v55; // rdx
  __int64 v56; // rax
  __int64 v57; // r10
  char *v58; // rax
  __int64 v59; // rax
  UFG::qVector3 **v60; // rax
  UFG::qVector3 **v61; // rdx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v63; // rax
  __int64 v64; // [rsp+20h] [rbp-178h]
  UFG::qBaseTreeRB *v65; // [rsp+20h] [rbp-178h]
  UFG::qVector3 result; // [rsp+28h] [rbp-170h] BYREF
  _QWORD *v67; // [rsp+38h] [rbp-160h]
  __int64 v68[25]; // [rsp+40h] [rbp-158h] BYREF
  int v69; // [rsp+108h] [rbp-90h]

  v5 = resultantEdge;
  VisIndexAtPosition = UFG::SectionChooser::GetVisIndexAtPosition(pos, 0);
  if ( !UFG::SectionChooser::IsSectionVisible_VisIndex(VisIndexAtPosition, SCENERY_LAYER_STD, 0) )
  {
    UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(v5);
    return;
  }
  v8 = gAISidewalkEdgeDataGrid;
  v67 = 0i64;
  if ( !gAISidewalkEdgeDataGrid )
    goto LABEL_53;
  x = pos->x;
  mGridSizeInv = gAISidewalkEdgeDataGrid->mGridSizeInv;
  mXDim = gAISidewalkEdgeDataGrid->mXDim;
  y = pos->y;
  v13 = (int)(float)((float)((float)(pos->x - maxDist) - gAISidewalkEdgeDataGrid->mXMin) * mGridSizeInv);
  if ( v13 < 0 )
    v13 = 0;
  v14 = (int)(float)((float)((float)(pos->x + maxDist) - gAISidewalkEdgeDataGrid->mXMin) * mGridSizeInv);
  if ( v14 >= (int)mXDim )
    v14 = mXDim - 1;
  mYDim = gAISidewalkEdgeDataGrid->mYDim;
  v16 = (int)(float)((float)((float)(y - maxDist) - gAISidewalkEdgeDataGrid->mYMin) * mGridSizeInv);
  if ( v16 < 0 )
    v16 = 0;
  v17 = (int)(float)((float)((float)(y + maxDist) - gAISidewalkEdgeDataGrid->mYMin) * mGridSizeInv);
  if ( v17 >= mYDim )
    v17 = mYDim - 1;
  v18 = 0;
  v69 = 0;
  if ( v16 <= v17 )
  {
    v19 = 16 * mXDim;
    v20 = 16i64 * (v13 + v16 * (int)mXDim);
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
            v68[v18] = v22;
            v18 = ++v69;
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
    v25 = v18;
    v26 = v68;
    v64 = v18;
    do
    {
      v27 = *v26;
      v28 = *(_QWORD *)(*v26 + 8);
      if ( v28 != *v26 )
      {
        do
        {
          v29 = *(_QWORD *)(v28 + 16);
          v30 = (searchFlags & 4) != 0 || (*(_DWORD *)(v29 + 24) & 4) == 0;
          if ( v29 )
          {
            v31 = *(_QWORD *)v29 + v29;
            if ( !*(_QWORD *)v29 )
              v31 = 0i64;
            v32 = *(_QWORD *)(v31 + 40);
            if ( v32 && *(_WORD *)(v32 + 34) )
            {
              v33 = *(_QWORD *)(v29 + 8);
              v34 = v33 ? v29 + v33 + 8 : 0i64;
              v35 = *(_QWORD *)(v34 + 40);
              if ( v35 )
              {
                if ( *(_WORD *)(v35 + 34) )
                {
                  v36 = *(_DWORD *)(v29 + 24);
                  if ( (v36 & 2) != 0
                    && (v36 & 0x80u) == 0
                    && (searchFlags & 2) != 0
                    && v30
                    && (*(_BYTE *)(v29 + 24) & 0xFC & searchFlags) != 0 )
                  {
                    v37 = *(_QWORD *)(v29 + 8);
                    if ( v37 )
                      v38 = v37 + v29 + 8;
                    else
                      v38 = 0i64;
                    v39 = *(_QWORD *)v29 + v29;
                    if ( !*(_QWORD *)v29 )
                      v39 = 0i64;
                    UFG::qNearestSegPoint(&result, *(UFG::qVector3 **)(v39 + 40), *(UFG::qVector3 **)(v38 + 40), pos);
                    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(result.z - pos->z) & _xmm) < 1.5
                      && (float)((float)((float)(y - result.y) * (float)(y - result.y))
                               + (float)((float)(x - result.x) * (float)(x - result.x))) < v24 )
                    {
                      v24 = (float)((float)(y - result.y) * (float)(y - result.y))
                          + (float)((float)(x - result.x) * (float)(x - result.x));
                      v67 = (_QWORD *)v29;
                    }
                  }
                }
              }
            }
          }
          v28 = *(_QWORD *)(v28 + 8);
        }
        while ( v28 != v27 );
        v25 = v64;
      }
      ++v26;
      v64 = --v25;
    }
    while ( v25 );
  }
  else
  {
LABEL_53:
    v40 = maxDist * maxDist;
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423BAAD0);
    if ( !Head )
      goto LABEL_96;
    do
    {
      Next = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423BAAD0, (UFG::qBaseNodeRB *)Head);
      mChild1_high = HIDWORD(Head[2].mNode.mChild1);
      v44 = Next;
      v65 = Next;
      if ( mChild1_high )
      {
        mParent = Head[3].mNode.mParent;
        v46 = mChild1_high;
        v47 = 0i64;
        do
        {
          if ( mParent )
            v48 = (char *)&Head[3] + (_QWORD)mParent;
          else
            v48 = 0i64;
          v49 = *(_DWORD *)&v48[v47 + 24];
          v50 = &v48[v47];
          v51 = (searchFlags & 4) != 0 || (v49 & 4) == 0;
          v52 = *(_QWORD *)v50;
          v53 = &v50[*(_QWORD *)v50];
          if ( !*(_QWORD *)v50 )
            v53 = 0i64;
          v54 = *((_QWORD *)v53 + 5);
          if ( v54 && *(_WORD *)(v54 + 34) )
          {
            v55 = *((_QWORD *)v50 + 1);
            v56 = v55 ? (__int64)&v50[v55 + 8] : 0i64;
            v57 = *(_QWORD *)(v56 + 40);
            if ( v57 )
            {
              if ( *(_WORD *)(v57 + 34)
                && (v49 & 2) != 0
                && (v49 & 0x80u) == 0
                && (searchFlags & 2) != 0
                && v51
                && (v49 & 0xFC & searchFlags) != 0 )
              {
                v58 = &v50[v52];
                if ( !v52 )
                  v58 = 0i64;
                if ( *((_QWORD *)v58 + 5) )
                {
                  v59 = v55 ? (__int64)&v50[v55 + 8] : 0i64;
                  if ( *(_QWORD *)(v59 + 40) )
                  {
                    if ( v55 )
                      v60 = (UFG::qVector3 **)&v50[v55 + 8];
                    else
                      v60 = 0i64;
                    v61 = (UFG::qVector3 **)&v50[v52];
                    if ( !v52 )
                      v61 = 0i64;
                    UFG::qNearestSegPoint(&result, v61[5], v60[5], pos);
                    if ( (float)((float)((float)(pos->y - result.y) * (float)(pos->y - result.y))
                               + (float)((float)(pos->x - result.x) * (float)(pos->x - result.x))) < v40 )
                    {
                      v40 = (float)((float)(pos->y - result.y) * (float)(pos->y - result.y))
                          + (float)((float)(pos->x - result.x) * (float)(pos->x - result.x));
                      v67 = v50;
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
        v44 = v65;
      }
      Head = (Render::SkinningCacheNode *)v44;
    }
    while ( v44 );
  }
  if ( v67 )
  {
    UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game>::_Set(resultantEdge, *((_DWORD *)v67 + 4), *((_DWORD *)v67 + 5));
    return;
  }
  v5 = resultantEdge;
LABEL_96:
  v5->mPtr = 0i64;
  Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v63 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v63, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(v5, Inventory);
  v5->mObjUID = -1;
  v5->mIndex = -1;
  v5->mNameUID = -1;
  v5->mPtr = 0i64;
}

// File Line: 807
// RVA: 0x357930
char __fastcall UFG::AISidewalkGraph::FindNodeLocationInRange(
        UFG::qVector3 *pos,
        const float minDist,
        const float maxDist,
        const bool offScreenOnly,
        UFG::qVector3 *resultPos)
{
  UFG::qVector3 *v7; // r14
  float v8; // xmm7_4
  Render::SkinningCacheNode *Head; // rsi
  __int64 v10; // rdi
  UFG::qBaseTreeRB *Next; // rbp
  unsigned __int64 mUID; // rcx
  char *v13; // rdx
  char *v14; // rbx
  float v15; // xmm6_4
  bool IsPositionOnScreen; // al

  v7 = 0i64;
  v8 = maxDist * maxDist;
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423BAAD0);
  if ( !Head )
    return 0;
  do
  {
    v10 = 0i64;
    Next = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423BAAD0, (UFG::qBaseNodeRB *)Head);
    while ( (unsigned int)v10 < LODWORD(Head[2].mNode.mChild1) )
    {
      mUID = Head[2].mNode.mUID;
      if ( mUID )
        v13 = (char *)&Head[2].mNode.mUID + mUID;
      else
        v13 = 0i64;
      v14 = &v13[40 * v10];
      if ( !*((_WORD *)v14 + 17) )
        goto LABEL_14;
      v15 = (float)((float)(pos->y - *((float *)v14 + 1)) * (float)(pos->y - *((float *)v14 + 1)))
          + (float)((float)(pos->x - *(float *)v14) * (float)(pos->x - *(float *)v14));
      IsPositionOnScreen = UFG::SimObjectUtility::IsPositionOnScreen((UFG::qVector3 *)&v13[40 * v10], 2.0, 0);
      if ( offScreenOnly )
      {
        if ( !IsPositionOnScreen )
        {
LABEL_11:
          if ( (float)(minDist * minDist) < v15 && v15 < v8 )
          {
            v7 = (UFG::qVector3 *)v14;
            v8 = v15;
          }
        }
      }
      else if ( IsPositionOnScreen )
      {
        goto LABEL_11;
      }
LABEL_14:
      v10 = (unsigned int)(v10 + 1);
    }
    Head = (Render::SkinningCacheNode *)Next;
  }
  while ( Next );
  if ( !v7 )
    return 0;
  *resultPos = *v7;
  return 1;
}

// File Line: 866
// RVA: 0x35E920
bool __fastcall UFG::AISidewalkGraph::GetDestinationPointFromNode(
        UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *nodeHandle,
        UFG::qVector3 *destPos,
        const bool isGroupLeader)
{
  UFG::AISidewalkNode_Game *mPtr; // rdi
  bool v5; // al
  float mRadius; // xmm6_4
  float v7; // xmm8_4
  float v8; // xmm9_4
  UFG::qVector3 *v9; // rax
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm8_4
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 range; // [rsp+20h] [rbp-98h] BYREF
  UFG::qVector3 position; // [rsp+30h] [rbp-88h] BYREF
  UFG::qVector3 result; // [rsp+40h] [rbp-78h] BYREF

  mPtr = nodeHandle->mPtr;
  if ( !mPtr )
    return 0;
  mRadius = mPtr->mRadius;
  v7 = 1.0 / _mm_sqrt_ps((__m128)LODWORD(FLOAT_2_0)).m128_f32[0];
  v8 = v7 * 0.0;
  if ( isGroupLeader )
  {
    mRadius = mRadius - 1.0;
    if ( mRadius <= 0.0 )
      mRadius = 0.0;
  }
  range.x = v7 * 2.0;
  range.z = v8 * 2.0;
  range.y = v7 * 2.0;
  v9 = UFG::qRandom(&result, &range, (unsigned int *)&UFG::qDefaultSeed);
  v10 = (float)((float)(v9->x - v7) * mRadius) + mPtr->mPos.x;
  v11 = (float)((float)(v9->y - v7) * mRadius) + mPtr->mPos.y;
  v12 = (float)((float)(v9->z - v8) * mRadius) + mPtr->mPos.z;
  position.x = v10;
  position.y = v11;
  position.z = v12;
  if ( UFG::PlaceOnGround(&range, &position, 0.0, 3.0) )
  {
    y = range.y;
    v5 = 1;
    destPos->x = range.x;
    z = range.z;
    destPos->y = y;
    destPos->z = z;
  }
  else
  {
    destPos->x = v10;
    destPos->y = v11;
    destPos->z = v12;
    return 0;
  }
  return v5;
}

// File Line: 912
// RVA: 0x35F1A0
float __fastcall UFG::GetEffectiveNodeRadius(
        UFG::AISidewalkEdge_Game *edge_game,
        UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *pCurrentNode,
        UFG::qVector3 *entityLocation,
        UFG::qVector3 *entityForward)
{
  __int64 mOffset; // rdx
  char *v7; // rcx
  char *v8; // rax
  __int64 v9; // rdx
  char *v10; // rax
  float v11; // xmm6_4
  char *v12; // rax
  float *v13; // rax
  float v14; // xmm3_4
  float v15; // xmm2_4
  float yMin; // xmm0_4
  UFG::qVector3 v2; // [rsp+28h] [rbp-40h] BYREF
  UFG::qVector3 v1; // [rsp+38h] [rbp-30h] BYREF

  if ( (_S28 & 1) == 0 )
  {
    _S28 |= 1u;
    ramp.xBase = 0.0;
    ramp.yBase = 1.0;
    ramp.yMin = FLOAT_0_0099999998;
    ramp.yMax = 1.0;
    ramp.fCoef = FLOAT_N0_42016903;
  }
  mOffset = edge_game->mpStartNodeHandle.mOffset;
  v7 = 0i64;
  v8 = (char *)edge_game + mOffset;
  if ( !mOffset )
    v8 = 0i64;
  if ( pCurrentNode->mObjUID == *((_DWORD *)v8 + 9) )
  {
    v9 = edge_game->mpEndNodeHandle.mOffset;
    if ( v9 )
      v10 = (char *)&edge_game->mpEndNodeHandle + v9;
    else
      v10 = 0i64;
    v11 = *(float *)(*((_QWORD *)v10 + 5) + 20i64);
    if ( v9 )
      v7 = (char *)&edge_game->mpEndNodeHandle + v9;
  }
  else
  {
    v12 = (char *)edge_game + mOffset;
    if ( !mOffset )
      v12 = 0i64;
    v11 = *(float *)(*((_QWORD *)v12 + 5) + 20i64);
    if ( mOffset )
      v7 = (char *)edge_game + mOffset;
  }
  v13 = (float *)*((_QWORD *)v7 + 5);
  v14 = v13[1];
  v15 = *v13;
  v1.x = entityForward->x;
  v1.y = entityForward->y;
  v1.z = 0.0;
  v2.x = v15 - entityLocation->x;
  v2.y = v14 - entityLocation->y;
  v2.z = 0.0;
  yMin = (float)((float)(UFG::qAngleBetween(&v1, &v2) - ramp.xBase) * ramp.fCoef) + ramp.yBase;
  if ( yMin <= ramp.yMin )
    yMin = ramp.yMin;
  if ( yMin >= ramp.yMax )
    yMin = ramp.yMax;
  return yMin * v11;
}

// File Line: 949
// RVA: 0x34AA60
char __fastcall UFG::AISidewalkGraph::CalculateDestinationPoint(
        UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *currentEdge,
        UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *destinationNode,
        UFG::qVector3 *pDestinationPoint,
        UFG::qVector3 *pCurrentPos,
        UFG::qVector3 *pCurrentFacing,
        bool isGroupLeader,
        UFG::AIEntityComponent *pAIEntityComponent,
        UFG::SidewalkWanderData *sidewalkWanderData)
{
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v9; // r15
  unsigned int mNameUID; // r14d
  unsigned int mObjUID; // ebx
  unsigned __int16 mIndex; // di
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  unsigned int v18; // r14d
  int v19; // ebx
  unsigned __int16 v20; // di
  UFG::qResourceInventory *v21; // rax
  UFG::qResourceWarehouse *v22; // rax
  UFG::qResourceInventory *v23; // rax
  UFG::qResourceWarehouse *v24; // rax
  char *v25; // rax
  unsigned int v26; // r14d
  int v27; // ebx
  __int16 v28; // di
  UFG::qResourceInventory *v29; // rax
  UFG::qResourceWarehouse *v30; // rax
  UFG::qResourceInventory *v31; // rax
  UFG::qResourceWarehouse *v32; // rax
  __int64 v33; // rcx
  char *v34; // rax
  unsigned int v35; // r14d
  int v36; // ebx
  __int16 v37; // di
  UFG::qResourceInventory *v38; // rax
  UFG::qResourceWarehouse *v39; // rax
  UFG::qResourceInventory *v40; // rax
  UFG::qResourceWarehouse *v41; // rax
  UFG::AISidewalkNode_Game *mPtr; // r14
  __int64 mOffset; // rax
  char *v44; // r12
  int mConnectionsCount; // edi
  unsigned int v46; // ebx
  unsigned int v47; // r15d
  char *v48; // rcx
  UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *v49; // rcx
  float v50; // xmm7_4
  float v51; // xmm6_4
  UFG::AISidewalkEdge_Game **v52; // rdi
  unsigned int v53; // ebx
  char *v54; // rdx
  __int64 v55; // rcx
  UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *v56; // rcx
  float v57; // xmm6_4
  unsigned int v58; // r14d
  unsigned int i; // ebx
  char *v60; // rcx
  UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *v61; // rcx
  UFG::AISidewalkEdge_Game *v62; // rdi
  char *v63; // rcx
  char *v64; // rax
  _QWORD *v65; // rbx
  char *v66; // rax
  __int64 v67; // rax
  UFG::qResourceInventory *v68; // rax
  UFG::qResourceWarehouse *v69; // rax
  unsigned int v70; // r14d
  unsigned int v71; // edi
  UFG::qResourceInventory *v72; // rax
  UFG::qResourceWarehouse *v73; // rax
  UFG::qResourceInventory *v74; // rax
  UFG::qResourceWarehouse *v75; // rax
  __int64 v76; // rax
  char *v77; // rax
  __int64 v78; // rax
  UFG::qResourceInventory *v79; // rax
  UFG::qResourceWarehouse *v80; // rax
  unsigned int v81; // edi
  unsigned int v82; // ebx
  int v83; // ebx
  unsigned int v84; // r14d
  char *v85; // rcx
  UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *v86; // rdi
  UFG::AISidewalkEdge_Game *v87; // rbx
  char *v88; // rax
  __int64 v89; // rax
  UFG::qResourceInventory *v90; // rax
  UFG::qResourceWarehouse *v91; // rax
  unsigned int v92; // r14d
  unsigned int v93; // edi
  UFG::qResourceInventory *v94; // rax
  UFG::qResourceWarehouse *v95; // rax
  UFG::qResourceInventory *v96; // rax
  UFG::qResourceWarehouse *v97; // rax
  __int64 v98; // rax
  char *v99; // rax
  __int64 v100; // rax
  UFG::qResourceWarehouse *v101; // rax
  UFG::qResourceInventory *v102; // rax
  UFG::qResourceWarehouse *v103; // rax
  UFG::qResourceInventory *v104; // rax
  UFG::qResourceWarehouse *v105; // rax
  char v106; // bl
  UFG::qResourceInventory *v107; // rax
  UFG::qResourceWarehouse *v108; // rax
  UFG::qResourceInventory *v109; // rax
  UFG::qResourceWarehouse *v110; // rax
  UFG::qResourceInventory *v111; // rax
  UFG::qResourceWarehouse *v112; // rax
  UFG::qResourceInventory *v113; // rax
  UFG::qResourceWarehouse *v114; // rax
  UFG::qResourceInventory *v115; // rax
  UFG::qResourceWarehouse *v116; // rax
  UFG::qResourceHandle v117; // [rsp+40h] [rbp-C0h] BYREF
  int v118; // [rsp+60h] [rbp-A0h]
  unsigned int objUID; // [rsp+64h] [rbp-9Ch]
  __int64 v120; // [rsp+68h] [rbp-98h]
  UFG::qResourceHandle v121; // [rsp+70h] [rbp-90h] BYREF
  int v122; // [rsp+90h] [rbp-70h]
  int v123; // [rsp+94h] [rbp-6Ch]
  _QWORD *v124; // [rsp+98h] [rbp-68h]
  UFG::qResourceHandle v125; // [rsp+A0h] [rbp-60h] BYREF
  int v126; // [rsp+C0h] [rbp-40h]
  int v127; // [rsp+C4h] [rbp-3Ch]
  __int64 v128; // [rsp+C8h] [rbp-38h]
  UFG::qResourceHandle v129; // [rsp+D0h] [rbp-30h] BYREF
  int v130; // [rsp+F0h] [rbp-10h]
  int v131; // [rsp+F4h] [rbp-Ch]
  __int64 v132; // [rsp+F8h] [rbp-8h]
  UFG::qResourceHandle v133; // [rsp+100h] [rbp+0h] BYREF
  int v134; // [rsp+120h] [rbp+20h]
  unsigned int v135; // [rsp+124h] [rbp+24h]
  __int64 v136; // [rsp+128h] [rbp+28h]
  __int64 v137; // [rsp+130h] [rbp+30h]

  v137 = -2i64;
  v9 = currentEdge;
  if ( !currentEdge->mPtr )
    return 0;
  if ( !destinationNode->mPtr )
    return UFG::AISidewalkGraph::CalculateInitialDestinationPoint(
             (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)currentEdge,
             destinationNode,
             pDestinationPoint,
             pCurrentPos,
             pCurrentFacing,
             isGroupLeader,
             pAIEntityComponent,
             sidewalkWanderData);
  UFG::qResourceHandle::qResourceHandle(&v117);
  v118 = 0xFFFF;
  objUID = -1;
  v120 = 0i64;
  v117.mNameUID = -1;
  UFG::qResourceHandle::qResourceHandle(&v133);
  v134 = 0xFFFF;
  v135 = -1;
  v136 = 0i64;
  v133.mNameUID = -1;
  mNameUID = destinationNode->mNameUID;
  mObjUID = destinationNode->mObjUID;
  mIndex = destinationNode->mIndex;
  v136 = 0i64;
  Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v15, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&v133, Inventory);
  LOWORD(v134) = mIndex;
  v135 = mObjUID;
  v16 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v17 = UFG::qResourceWarehouse::Instance();
    v16 = UFG::qResourceWarehouse::GetInventory(v17, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v16;
  }
  UFG::qResourceHandle::Init(&v133, 0x43E99F7Eu, mNameUID, v16);
  UFG::qResourceHandle::qResourceHandle(&v121);
  v122 = 0x1FFFF;
  v123 = -1;
  v124 = 0i64;
  v121.mNameUID = -1;
  v18 = v9->mNameUID;
  v19 = v9->mObjUID;
  v20 = v9->mIndex;
  v124 = 0i64;
  v21 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v22 = UFG::qResourceWarehouse::Instance();
    v21 = UFG::qResourceWarehouse::GetInventory(v22, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v21;
  }
  UFG::qResourceHandle::Close(&v121, v21);
  LOWORD(v122) = v20;
  v123 = v19;
  v23 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v24 = UFG::qResourceWarehouse::Instance();
    v23 = UFG::qResourceWarehouse::GetInventory(v24, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v23;
  }
  UFG::qResourceHandle::Init(&v121, 0x43E99F7Eu, v18, v23);
  UFG::qResourceHandle::qResourceHandle(&v129);
  v130 = 0xFFFF;
  v131 = -1;
  v132 = 0i64;
  v129.mNameUID = -1;
  if ( *v124 )
    v25 = (char *)v124 + *v124;
  else
    v25 = 0i64;
  v26 = *((_DWORD *)v25 + 6);
  v27 = *((_DWORD *)v25 + 9);
  v28 = *((_WORD *)v25 + 16);
  v132 = 0i64;
  v29 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v30 = UFG::qResourceWarehouse::Instance();
    v29 = UFG::qResourceWarehouse::GetInventory(v30, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v29;
  }
  UFG::qResourceHandle::Close(&v129, v29);
  LOWORD(v130) = v28;
  v131 = v27;
  v31 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v32 = UFG::qResourceWarehouse::Instance();
    v31 = UFG::qResourceWarehouse::GetInventory(v32, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v31;
  }
  UFG::qResourceHandle::Init(&v129, 0x43E99F7Eu, v26, v31);
  UFG::qResourceHandle::qResourceHandle(&v125);
  v126 = 0xFFFF;
  v127 = -1;
  v128 = 0i64;
  v125.mNameUID = -1;
  v33 = v124[1];
  if ( v33 )
    v34 = (char *)v124 + v33 + 8;
  else
    v34 = 0i64;
  v35 = *((_DWORD *)v34 + 6);
  v36 = *((_DWORD *)v34 + 9);
  v37 = *((_WORD *)v34 + 16);
  v128 = 0i64;
  v38 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v39 = UFG::qResourceWarehouse::Instance();
    v38 = UFG::qResourceWarehouse::GetInventory(v39, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v38;
  }
  UFG::qResourceHandle::Close(&v125, v38);
  LOWORD(v126) = v37;
  v127 = v36;
  v40 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v41 = UFG::qResourceWarehouse::Instance();
    v40 = UFG::qResourceWarehouse::GetInventory(v41, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v40;
  }
  UFG::qResourceHandle::Init(&v125, 0x43E99F7Eu, v35, v40);
  if ( !v132 && !v128 )
    goto LABEL_120;
  mPtr = destinationNode->mPtr;
  mOffset = mPtr->mConnections.mOffset;
  if ( mOffset )
    v44 = (char *)&mPtr->mConnections + mOffset;
  else
    v44 = 0i64;
  mConnectionsCount = mPtr->mConnectionsCount;
  v46 = 0;
  if ( mPtr->mConnectionsCount )
  {
    v47 = mPtr->mConnectionsCount;
    do
    {
      v48 = &v44[8 * v46];
      if ( *(_QWORD *)v48 )
        v49 = (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)&v48[*(_QWORD *)v48];
      else
        v49 = 0i64;
      if ( !UFG::AISidewalkGraph::OkayToTraverseFrom(v49, destinationNode, sidewalkWanderData) )
        --mConnectionsCount;
      ++v46;
    }
    while ( v46 < v47 );
    mPtr = destinationNode->mPtr;
    v9 = currentEdge;
  }
  if ( mConnectionsCount <= 1 )
  {
    v83 = 0;
    if ( mPtr->mConnectionsCount )
    {
      v84 = mPtr->mConnectionsCount;
      while ( 1 )
      {
        v85 = &v44[8 * v83];
        v86 = (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)&v85[*(_QWORD *)v85];
        if ( !*(_QWORD *)v85 )
          v86 = 0i64;
        if ( UFG::AISidewalkGraph::OkayToTraverseFrom(v86, destinationNode, sidewalkWanderData) )
          break;
        if ( ++v83 >= v84 )
          goto LABEL_117;
      }
      v87 = v86->mPtr;
      UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(v9, v86->mObjUID, v86->mNameUID, v86->mIndex);
      v88 = v87->mpStartNodeHandle.mOffset ? (char *)v87 + v87->mpStartNodeHandle.mOffset : 0i64;
      v89 = *((_QWORD *)v88 + 5);
      if ( v89 )
      {
        v92 = *(_DWORD *)(v89 + 16);
        v93 = *(_DWORD *)(v89 + 12);
        v120 = 0i64;
        v94 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
        if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
        {
          v95 = UFG::qResourceWarehouse::Instance();
          v94 = UFG::qResourceWarehouse::GetInventory(v95, 0x43E99F7Eu);
          `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v94;
        }
        UFG::qResourceHandle::Close(&v117, v94);
        LOWORD(v118) = -1;
        objUID = v93;
        v96 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
        if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
        {
          v97 = UFG::qResourceWarehouse::Instance();
          v96 = UFG::qResourceWarehouse::GetInventory(v97, 0x43E99F7Eu);
          `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v96;
        }
        UFG::qResourceHandle::Init(&v117, 0x43E99F7Eu, v92, v96);
      }
      else
      {
        v120 = 0i64;
        v90 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
        if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
        {
          v91 = UFG::qResourceWarehouse::Instance();
          v90 = UFG::qResourceWarehouse::GetInventory(v91, 0x43E99F7Eu);
          `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v90;
        }
        UFG::qResourceHandle::Close(&v117, v90);
        LOWORD(v118) = -1;
        objUID = -1;
        v117.mNameUID = -1;
        v120 = 0i64;
      }
      if ( destinationNode->mObjUID == objUID )
      {
        v98 = v87->mpEndNodeHandle.mOffset;
        if ( v98 )
          v99 = (char *)&v87->mpEndNodeHandle + v98;
        else
          v99 = 0i64;
        v100 = *((_QWORD *)v99 + 5);
        if ( !v100 )
        {
          v120 = 0i64;
          v79 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
          if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
          {
            v101 = UFG::qResourceWarehouse::Instance();
            v79 = UFG::qResourceWarehouse::GetInventory(v101, 0x43E99F7Eu);
            `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v79;
          }
          goto LABEL_82;
        }
        v81 = *(_DWORD *)(v100 + 16);
        v82 = *(_DWORD *)(v100 + 12);
        v120 = 0i64;
        goto LABEL_112;
      }
    }
  }
  else
  {
    v50 = 0.0;
    v51 = 0.0;
    v52 = 0i64;
    v53 = 0;
    if ( mPtr->mConnectionsCount )
    {
      do
      {
        v54 = &v44[8 * v53];
        v55 = *(_QWORD *)v54;
        if ( *(_QWORD *)v54 )
          v52 = (UFG::AISidewalkEdge_Game **)&v54[v55];
        if ( *((_DWORD *)v52 + 9) != v123 )
        {
          v56 = v55 ? (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)&v54[v55] : 0i64;
          if ( UFG::AISidewalkGraph::OkayToTraverseFrom(v56, destinationNode, sidewalkWanderData) )
            v51 = v51 + UFG::GetEffectiveNodeRadius(v52[5], destinationNode, pCurrentPos, pCurrentFacing);
        }
        ++v53;
        v52 = 0i64;
      }
      while ( v53 < destinationNode->mPtr->mConnectionsCount );
    }
    v57 = UFG::qRandom(v51, (unsigned int *)&UFG::qDefaultSeed);
    v58 = -1;
    for ( i = 0; i < destinationNode->mPtr->mConnectionsCount; ++i )
    {
      v60 = &v44[8 * i];
      if ( *(_QWORD *)v60 )
        v61 = (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)&v60[*(_QWORD *)v60];
      else
        v61 = 0i64;
      v62 = v61->mPtr;
      if ( v61->mObjUID != v123 && UFG::AISidewalkGraph::OkayToTraverseFrom(v61, destinationNode, sidewalkWanderData) )
      {
        v58 = i;
        v50 = v50 + UFG::GetEffectiveNodeRadius(v62, destinationNode, pCurrentPos, pCurrentFacing);
        if ( v50 >= v57 )
          break;
      }
    }
    v63 = &v44[8 * v58];
    if ( *(_QWORD *)v63 )
      v64 = &v63[*(_QWORD *)v63];
    else
      v64 = 0i64;
    v65 = (_QWORD *)*((_QWORD *)v64 + 5);
    UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
      currentEdge,
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
      v120 = 0i64;
      v72 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
      {
        v73 = UFG::qResourceWarehouse::Instance();
        v72 = UFG::qResourceWarehouse::GetInventory(v73, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v72;
      }
      UFG::qResourceHandle::Close(&v117, v72);
      LOWORD(v118) = -1;
      objUID = v71;
      v74 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
      {
        v75 = UFG::qResourceWarehouse::Instance();
        v74 = UFG::qResourceWarehouse::GetInventory(v75, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v74;
      }
      UFG::qResourceHandle::Init(&v117, 0x43E99F7Eu, v70, v74);
    }
    else
    {
      v120 = 0i64;
      v68 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
      {
        v69 = UFG::qResourceWarehouse::Instance();
        v68 = UFG::qResourceWarehouse::GetInventory(v69, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v68;
      }
      UFG::qResourceHandle::Close(&v117, v68);
      LOWORD(v118) = -1;
      objUID = -1;
      v117.mNameUID = -1;
      v120 = 0i64;
    }
    if ( destinationNode->mObjUID == objUID )
    {
      v76 = v65[1];
      if ( v76 )
        v77 = (char *)v65 + v76 + 8;
      else
        v77 = 0i64;
      v78 = *((_QWORD *)v77 + 5);
      if ( !v78 )
      {
        v120 = 0i64;
        v79 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
        if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
        {
          v80 = UFG::qResourceWarehouse::Instance();
          v79 = UFG::qResourceWarehouse::GetInventory(v80, 0x43E99F7Eu);
          `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v79;
        }
LABEL_82:
        UFG::qResourceHandle::Close(&v117, v79);
        LOWORD(v118) = -1;
        objUID = -1;
        v117.mNameUID = -1;
        v120 = 0i64;
LABEL_120:
        v106 = 0;
        goto LABEL_121;
      }
      v81 = *(_DWORD *)(v78 + 16);
      v82 = *(_DWORD *)(v78 + 12);
      v120 = 0i64;
LABEL_112:
      v102 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
      {
        v103 = UFG::qResourceWarehouse::Instance();
        v102 = UFG::qResourceWarehouse::GetInventory(v103, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v102;
      }
      UFG::qResourceHandle::Close(&v117, v102);
      v104 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
      objUID = v82;
      LOWORD(v118) = -1;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
      {
        v105 = UFG::qResourceWarehouse::Instance();
        v104 = UFG::qResourceWarehouse::GetInventory(v105, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v104;
      }
      UFG::qResourceHandle::Init(&v117, 0x43E99F7Eu, v81, v104);
    }
  }
LABEL_117:
  if ( !v120 || !*(_WORD *)(v120 + 34) )
    goto LABEL_120;
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    destinationNode,
    objUID,
    v117.mNameUID,
    (unsigned __int16)v118);
  UFG::AISidewalkGraph::GetDestinationPointFromNode(destinationNode, pDestinationPoint, isGroupLeader);
  v106 = 1;
LABEL_121:
  v107 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v108 = UFG::qResourceWarehouse::Instance();
    v107 = UFG::qResourceWarehouse::GetInventory(v108, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v107;
  }
  UFG::qResourceHandle::Close(&v125, v107);
  UFG::qResourceHandle::~qResourceHandle(&v125);
  v109 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v110 = UFG::qResourceWarehouse::Instance();
    v109 = UFG::qResourceWarehouse::GetInventory(v110, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v109;
  }
  UFG::qResourceHandle::Close(&v129, v109);
  UFG::qResourceHandle::~qResourceHandle(&v129);
  v111 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v112 = UFG::qResourceWarehouse::Instance();
    v111 = UFG::qResourceWarehouse::GetInventory(v112, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v111;
  }
  UFG::qResourceHandle::Close(&v121, v111);
  UFG::qResourceHandle::~qResourceHandle(&v121);
  v113 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v114 = UFG::qResourceWarehouse::Instance();
    v113 = UFG::qResourceWarehouse::GetInventory(v114, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v113;
  }
  UFG::qResourceHandle::Close(&v133, v113);
  UFG::qResourceHandle::~qResourceHandle(&v133);
  v115 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v116 = UFG::qResourceWarehouse::Instance();
    v115 = UFG::qResourceWarehouse::GetInventory(v116, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v115;
  }
  UFG::qResourceHandle::Close(&v117, v115);
  UFG::qResourceHandle::~qResourceHandle(&v117);
  return v106;
}

// File Line: 1105
// RVA: 0x34B560
bool __fastcall UFG::AISidewalkGraph::CalculateInitialDestinationPoint(
        UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *currentEdge,
        UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *destinationNode,
        UFG::qVector3 *pDestinationPoint,
        UFG::qVector3 *pCurrentPos,
        UFG::qVector3 *pCurrentFacing,
        bool isGroupLeader,
        UFG::AIEntityComponent *pAIEntityComponent,
        UFG::SidewalkWanderData *sidewalkWanderData)
{
  UFG::AISidewalkEdge_Game *mPtr; // rbx
  __int64 mOffset; // rax
  char *v10; // rdi
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v14; // rdx
  bool v15; // r14
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v16; // rdx
  __int64 v17; // rax
  __int64 v18; // rax
  char *v19; // rcx
  __int64 v20; // rax
  float *v21; // rdx
  char *v22; // rcx
  __int64 v23; // r8
  float y; // xmm9_4
  __m128 x_low; // xmm8
  float z; // xmm10_4
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

  mPtr = currentEdge->mPtr;
  mOffset = mPtr->mpEndNodeHandle.mOffset;
  v10 = 0i64;
  if ( mOffset )
    v14 = (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)((char *)&mPtr->mpEndNodeHandle + mOffset);
  else
    v14 = 0i64;
  v15 = UFG::AISidewalkGraph::OkayToTraverseFrom(currentEdge, v14, sidewalkWanderData);
  v16 = (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)((char *)mPtr + mPtr->mpStartNodeHandle.mOffset);
  if ( !mPtr->mpStartNodeHandle.mOffset )
    v16 = 0i64;
  if ( UFG::AISidewalkGraph::OkayToTraverseFrom(currentEdge, v16, sidewalkWanderData) )
  {
    if ( !v15 )
      goto LABEL_8;
    v19 = (char *)mPtr + mPtr->mpStartNodeHandle.mOffset;
    if ( !mPtr->mpStartNodeHandle.mOffset )
      v19 = 0i64;
    v20 = mPtr->mpEndNodeHandle.mOffset;
    v21 = (float *)*((_QWORD *)v19 + 5);
    if ( v20 )
      v22 = (char *)&mPtr->mpEndNodeHandle + v20;
    else
      v22 = 0i64;
    v23 = *((_QWORD *)v22 + 5);
    y = pCurrentFacing->y;
    x_low = (__m128)LODWORD(pCurrentFacing->x);
    z = pCurrentFacing->z;
    v27 = x_low;
    v27.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(y * y)) + (float)(z * z);
    if ( v27.m128_f32[0] == 0.0 )
      v28 = 0.0;
    else
      v28 = 1.0 / _mm_sqrt_ps(v27).m128_f32[0];
    v33 = (__m128)*(unsigned int *)(v23 + 4);
    v29 = x_low.m128_f32[0] * v28;
    v30 = y * v28;
    v31 = z * v28;
    v32 = *(float *)v23 - *v21;
    v33.m128_f32[0] = v33.m128_f32[0] - v21[1];
    v34 = *(float *)(v23 + 8) - v21[2];
    v35 = v33;
    v35.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(v32 * v32)) + (float)(v34 * v34);
    if ( _mm_sqrt_ps(v35).m128_f32[0] > 0.001 )
    {
      if ( v35.m128_f32[0] == 0.0 )
        v36 = 0.0;
      else
        v36 = 1.0 / _mm_sqrt_ps(v35).m128_f32[0];
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
    v17 = mPtr->mpEndNodeHandle.mOffset;
    if ( v17 )
      v10 = (char *)&mPtr->mpEndNodeHandle + v17;
    goto LABEL_10;
  }
  if ( mPtr->mpStartNodeHandle.mOffset )
    v10 = (char *)mPtr + mPtr->mpStartNodeHandle.mOffset;
LABEL_10:
  v18 = *((_QWORD *)v10 + 5);
  if ( v18 )
    UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game>::_Set(
      destinationNode,
      *(_DWORD *)(v18 + 12),
      *(_DWORD *)(v18 + 16));
  else
    UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::SetToNull(destinationNode);
  return UFG::AISidewalkGraph::GetDestinationPointFromNode(destinationNode, pDestinationPoint, isGroupLeader);
}

// File Line: 1217
// RVA: 0x34A090
void __fastcall UFG::AISidewalkGraph::CalculateCrosswalkLanes(
        UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *ppCurrentEdge,
        UFG::CrosswalkLanes *lanes)
{
  UFG::AISidewalkEdge_Game *mPtr; // rcx
  char *v5; // rax
  float *v6; // rax
  float v7; // xmm3_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  __int64 mOffset; // rax
  char *v11; // rax
  float *v12; // rax
  float x; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::qArray<unsigned long,0> *p_m_iIntersectionID; // r12
  int *p; // rcx
  UFG::qArray<unsigned long,0> *p_m_aLanes; // r15
  int *v19; // rcx
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rax
  UFG::RoadNetworkResource *RoadNetwork; // rax
  unsigned int i; // edi
  unsigned int *v24; // rbx
  UFG::RoadNetworkResource *v25; // rax
  UFG::RoadNetworkIntersection *Intersection; // rax
  UFG::RoadNetworkNode *v27; // rbx
  UFG::RoadNetworkLane *Lane; // r14
  float v29; // xmm4_4
  float v30; // xmm5_4
  __m128 x_low; // xmm3
  float v32; // xmm1_4
  float v33; // xmm2_4
  double v34; // xmm0_8
  bool v35; // bl
  UFG::qVector3 result; // [rsp+38h] [rbp-A0h] BYREF
  UFG::qVector3 v2; // [rsp+48h] [rbp-90h] BYREF
  UFG::allocator::free_link *v1; // [rsp+58h] [rbp-80h] BYREF
  UFG::qArray<unsigned long,0> v1_8; // [rsp+60h] [rbp-78h] BYREF
  float v40; // [rsp+70h] [rbp-68h]
  UFG::qArray<int,0> aLanes; // [rsp+78h] [rbp-60h] BYREF

  if ( UFG::WheeledVehicleManager::m_Instance
    || UFG::WheeledVehicleManager::m_Instance->m_NavigationData
    || UFG::WheeledVehicleNavigationData::GetRoadNetwork(0i64) )
  {
    mPtr = ppCurrentEdge->mPtr;
    if ( mPtr->mpStartNodeHandle.mOffset )
      v5 = (char *)mPtr + mPtr->mpStartNodeHandle.mOffset;
    else
      v5 = 0i64;
    v6 = (float *)*((_QWORD *)v5 + 5);
    v7 = *v6;
    v8 = v6[1];
    v9 = v6[2];
    *(float *)&v1 = *v6;
    *((float *)&v1 + 1) = v8;
    *(float *)&v1_8.size = v9;
    mOffset = mPtr->mpEndNodeHandle.mOffset;
    if ( mOffset )
      v11 = (char *)&mPtr->mpEndNodeHandle + mOffset;
    else
      v11 = 0i64;
    v12 = (float *)*((_QWORD *)v11 + 5);
    v14 = v12[1];
    v15 = v12[2];
    v2.x = *v12;
    x = v2.x;
    v2.y = v14;
    v2.z = v15;
    lanes->m_v1.x = v7;
    lanes->m_v1.y = v8;
    lanes->m_v1.z = v9;
    lanes->m_v2.x = x;
    lanes->m_v2.y = v14;
    lanes->m_v2.z = v15;
    p_m_iIntersectionID = (UFG::qArray<unsigned long,0> *)&lanes->m_iIntersectionID;
    p = lanes->m_iIntersectionID.p;
    if ( p )
      operator delete[](p);
    lanes->m_iIntersectionID.p = 0i64;
    *(_QWORD *)&p_m_iIntersectionID->size = 0i64;
    p_m_aLanes = (UFG::qArray<unsigned long,0> *)&lanes->m_aLanes;
    v19 = lanes->m_aLanes.p;
    if ( v19 )
      operator delete[](v19);
    lanes->m_aLanes.p = 0i64;
    *(_QWORD *)&p_m_aLanes->size = 0i64;
    v1_8.p = 0i64;
    *(_QWORD *)&v1_8.size = 0i64;
    v1 = 0i64;
    *(_QWORD *)&aLanes.size = 0i64;
    v20 = 128i64;
    if ( !is_mul_ok(0x20ui64, 4ui64) )
      v20 = -1i64;
    v1_8.p = (unsigned int *)UFG::qMalloc(v20, "qArray.Reserve.Intersections", 0i64);
    v1_8.capacity = 32;
    v21 = 128i64;
    if ( !is_mul_ok(0x20ui64, 4ui64) )
      v21 = -1i64;
    v1 = UFG::qMalloc(v21, "qArray.Reserve.LinesIntersecting", 0i64);
    aLanes.capacity = 32;
    RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
    UFG::RoadNetworkResource::GetLanesIntersectingLine2D(
      RoadNetwork,
      (UFG::qVector3 *)&v1,
      &v2,
      &v1_8,
      (UFG::qArray<unsigned long,0> *)&aLanes,
      80.0);
    for ( i = 0; i < aLanes.size; ++i )
    {
      v24 = v1_8.p;
      v25 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
      Intersection = UFG::RoadNetworkResource::GetIntersection(v25, v24[i]);
      v27 = Intersection;
      if ( Intersection->mNumLightPhases )
      {
        Lane = UFG::RoadNetworkNode::GetLane(Intersection, *((_DWORD *)&v1->mNext + i));
        UFG::RoadNetworkNode::GetTangent(v27, &result, Lane->mLaneIndex, 1.0);
        v29 = v2.z - *(float *)&v1_8.size;
        v30 = v2.y - *((float *)&v1 + 1);
        x_low = (__m128)LODWORD(v2.x);
        x_low.m128_f32[0] = v2.x - *(float *)&v1;
        v32 = (float)((float)((float)(result.x * result.x) + (float)(result.y * result.y)) + (float)(result.z * result.z)) == 0.0
            ? 0.0
            : 1.0 / _mm_sqrt_ps((__m128)LODWORD(result.x)).m128_f32[0];
        result.x = result.x * v32;
        result.y = result.y * v32;
        result.z = result.z * v32;
        v33 = (float)((float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v30 * v30)) + (float)(v29 * v29)) == 0.0
            ? 0.0
            : 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
        *(float *)&v1_8.p = x_low.m128_f32[0] * v33;
        *((float *)&v1_8.p + 1) = v33 * v30;
        v40 = v33 * v29;
        v34 = UFG::qAngleBetweenNormals(&result, (UFG::qVector3 *)&v1_8.p);
        v35 = *(float *)&v34 < 1.8325958 && *(float *)&v34 > 1.3089969;
        if ( (unsigned int)UFG::RoadNetworkLane::GetTurnDirection(Lane) != 1
          && (!v35 || (unsigned int)UFG::RoadNetworkLane::GetTurnDirection(Lane) != 2) )
        {
          UFG::qArray<int,0>::Add(p_m_iIntersectionID, &v1_8.p[i], "qArray.Add.aLanesIntersecting");
          UFG::qArray<int,0>::Add(p_m_aLanes, (unsigned int *)v1 + i, "qArray.Add.aLanesIntersecting");
        }
      }
    }
    if ( v1 )
      operator delete[](v1);
    v1 = 0i64;
    *(_QWORD *)&aLanes.size = 0i64;
    if ( v1_8.p )
      operator delete[](v1_8.p);
  }
}

// File Line: 1281
// RVA: 0x36A440
char __fastcall UFG::AISidewalkGraph::IsCrosswalkCrossable(UFG::CrosswalkLanes *lanes, float fTimeToCross)
{
  __int64 v4; // rbp
  int *p; // rbx
  UFG::RoadNetworkResource *RoadNetwork; // rax
  UFG::RoadNetworkIntersection *Intersection; // rdi
  UFG::RoadNetworkLane *Lane; // rbx
  float RemainingGreenLightTime; // xmm0_4

  if ( !lanes->m_aLanes.size )
    return 1;
  v4 = 0i64;
  while ( 1 )
  {
    p = lanes->m_iIntersectionID.p;
    RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
    Intersection = UFG::RoadNetworkResource::GetIntersection(RoadNetwork, p[v4]);
    Lane = UFG::RoadNetworkNode::GetLane(Intersection, lanes->m_aLanes.p[v4]);
    RemainingGreenLightTime = UFG::RoadNetworkIntersection::GetRemainingGreenLightTime(Intersection);
    if ( Lane->mStatus.mValue || fTimeToCross > RemainingGreenLightTime )
      break;
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= lanes->m_aLanes.size )
      return 1;
  }
  return 0;
}

// File Line: 1464
// RVA: 0x377C60
bool __fastcall UFG::AISidewalkGraph::OkayToTraverseFrom(
        UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *pEdge,
        UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *pCurrentNode,
        UFG::SidewalkWanderData *pSidewalkWanderData)
{
  UFG::AISidewalkEdge_Game *mPtr; // rcx
  char *v6; // rax
  char *v7; // rdx
  bool v8; // dl
  __int64 mOffset; // rdx
  char *v10; // rdx
  __int64 v11; // rdx
  bool mAllowedToUseCrosswalks; // r8
  unsigned int mFlags; // eax

  mPtr = pEdge->mPtr;
  if ( !mPtr )
    goto LABEL_26;
  v6 = 0i64;
  if ( mPtr->mpStartNodeHandle.mOffset )
    v7 = (char *)mPtr + mPtr->mpStartNodeHandle.mOffset;
  else
    v7 = 0i64;
  if ( *((_QWORD *)v7 + 5) )
  {
    if ( mPtr->mpStartNodeHandle.mOffset )
      v6 = (char *)mPtr + mPtr->mpStartNodeHandle.mOffset;
    v8 = pCurrentNode->mObjUID == *((_DWORD *)v6 + 9);
    goto LABEL_16;
  }
  mOffset = mPtr->mpEndNodeHandle.mOffset;
  if ( mOffset )
    v10 = (char *)&mPtr->mpEndNodeHandle + mOffset;
  else
    v10 = 0i64;
  if ( *((_QWORD *)v10 + 5) )
  {
    v11 = mPtr->mpEndNodeHandle.mOffset;
    if ( v11 )
      v6 = (char *)&mPtr->mpEndNodeHandle + v11;
    v8 = pCurrentNode->mObjUID != *((_DWORD *)v6 + 9);
LABEL_16:
    mAllowedToUseCrosswalks = 0;
    if ( pSidewalkWanderData )
      mAllowedToUseCrosswalks = pSidewalkWanderData->mAllowedToUseCrosswalks;
    mFlags = mPtr->mFlags;
    if ( ((mFlags & 8) != 0 && v8 || (mFlags & 0x10) != 0 && !v8)
      && (mAllowedToUseCrosswalks || (mFlags & 4) == 0)
      && UFG::AISidewalkGraph::IsActive(mPtr) )
    {
      LOBYTE(v6) = 1;
      return (char)v6;
    }
LABEL_26:
    LOBYTE(v6) = 0;
  }
  return (char)v6;
}

// File Line: 1506
// RVA: 0x3639F0
void __fastcall UFG::AISidewalkGraph::HandleAlteredDataOnAdd(UFG::AISidewalkSectionResource *pSidewalkSection)
{
  UFG::SidewalkAlteredNodeData *mNext; // rbx
  UFG::AISidewalkNode_Game *mPtr; // rdx
  UFG::qList<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData,1,0> *v4; // r14
  unsigned __int8 mOverRideActiveValue; // r8
  UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *mPrev; // rax
  unsigned int mNodeCount; // r11d
  char *v8; // rsi
  unsigned int v9; // r9d
  __int64 mOffset; // r8
  __int64 v11; // r10
  char *v12; // rax
  char *v13; // rdx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::AISidewalkNode_Game *v16; // rax

  mNext = (UFG::SidewalkAlteredNodeData *)UFG::AISidewalkGraph::sAlteredNodeData.mNode.mNext;
  if ( (UFG::qList<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData,1,0> *)UFG::AISidewalkGraph::sAlteredNodeData.mNode.mNext != &UFG::AISidewalkGraph::sAlteredNodeData )
  {
    do
    {
      mPtr = mNext->mpNode.mPtr;
      v4 = (UFG::qList<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData,1,0> *)mNext->mNext;
      if ( mPtr )
      {
        if ( mNext->mpNode.mNameUID == pSidewalkSection->mSectionVisId )
        {
          mOverRideActiveValue = mNext->mOverRideActiveValue;
          if ( (mNext->mpNode.mPtr->mActive != 0) == (mOverRideActiveValue != 0) )
          {
            mPrev = mNext->mPrev;
            mPrev->mNext = &v4->mNode;
            v4->mNode.mPrev = mPrev;
            mNext->mPrev = mNext;
            mNext->mNext = mNext;
            UFG::SidewalkAlteredNodeData::~SidewalkAlteredNodeData(mNext);
            operator delete[](mNext);
          }
          else
          {
            mNext->mOriginalValueKnown = 1;
            mNext->mOriginalValue = mPtr->mActive;
            mPtr->mActive = mOverRideActiveValue;
          }
        }
      }
      else if ( !mNext->mOriginalValueKnown )
      {
        mNodeCount = pSidewalkSection->mNodeCount;
        v8 = 0i64;
        v9 = 0;
        if ( mNodeCount )
        {
          mOffset = pSidewalkSection->mNodes.mOffset;
          v11 = 0i64;
          do
          {
            if ( mOffset )
              v12 = (char *)&pSidewalkSection->mNodes + mOffset;
            else
              v12 = 0i64;
            if ( *(_DWORD *)&v12[v11 + 12] == mNext->mNodeUid )
            {
              if ( mOffset )
                v13 = (char *)&pSidewalkSection->mNodes + mOffset;
              else
                v13 = 0i64;
              v8 = &v13[40 * v9];
            }
            ++v9;
            v11 += 40i64;
          }
          while ( v9 < mNodeCount );
        }
        if ( v8 )
        {
          UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game>::_Set(
            &mNext->mpNode,
            *((_DWORD *)v8 + 3),
            *((_DWORD *)v8 + 4));
        }
        else
        {
          mNext->mpNode.mPtr = 0i64;
          Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
          if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
          {
            v15 = UFG::qResourceWarehouse::Instance();
            Inventory = UFG::qResourceWarehouse::GetInventory(v15, 0x43E99F7Eu);
            `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
          }
          UFG::qResourceHandle::Close(&mNext->mpNode, Inventory);
          mNext->mpNode.mIndex = -1;
          mNext->mpNode.mObjUID = -1;
          mNext->mpNode.mNameUID = -1;
          mNext->mpNode.mPtr = 0i64;
        }
        v16 = mNext->mpNode.mPtr;
        if ( v16 )
        {
          mNext->mOriginalValueKnown = 1;
          mNext->mOriginalValue = v16->mActive;
          *((_WORD *)v8 + 17) = (unsigned __int8)mNext->mOverRideActiveValue;
        }
      }
      mNext = (UFG::SidewalkAlteredNodeData *)v4;
    }
    while ( v4 != &UFG::AISidewalkGraph::sAlteredNodeData );
  }
}UFG::SidewalkAlteredNodeData *)v4;
    }
    while ( v4 != &UFG::AISidewalkGraph::sAlteredNo

// File Line: 1632
// RVA: 0x387790
void __fastcall UFG::AISidewalkGraph::SetNodeActive(unsigned int hashId, bool val)
{
  UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *mNext; // rax
  UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *v5; // rcx
  UFG::AISidewalkNode_Game *v6; // rbp
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rdi
  UFG::allocator::free_link *v9; // rbx
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v10; // rcx
  UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *v11; // rax

  if ( hashId != -1 )
  {
    mNext = UFG::AISidewalkGraph::sAlteredNodeData.mNode.mNext;
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
        v9 = v7 + 2;
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v7[2]);
        LODWORD(v9[4].mNext) = 0xFFFF;
        HIDWORD(v9[4].mNext) = -1;
        v9[5].mNext = 0i64;
        LODWORD(v9[3].mNext) = -1;
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
      LODWORD(v8[8].mNext) = hashId;
      BYTE4(v8[8].mNext) = val;
      if ( v8[7].mNext )
      {
        BYTE5(v8[8].mNext) = 1;
        BYTE6(v8[8].mNext) = v6->mActive;
        v6->mActive = val;
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
      while ( LODWORD(mNext[4].mPrev) != hashId )
      {
        mNext = mNext->mNext;
        if ( mNext == (UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *)&UFG::AISidewalkGraph::sAlteredNodeData )
          goto LABEL_8;
      }
      BYTE4(mNext[4].mPrev) = val;
      v5 = mNext[3].mNext;
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
  __int64 mOffset; // rax
  __int64 v5; // rax
  unsigned int mFlags; // eax

  if ( !pEdge )
    return 0;
  v1 = 0i64;
  v2 = (char *)pEdge + pEdge->mpStartNodeHandle.mOffset;
  if ( !pEdge->mpStartNodeHandle.mOffset )
    v2 = 0i64;
  v3 = *((_QWORD *)v2 + 5);
  if ( !v3 || !*(_WORD *)(v3 + 34) )
    return 0;
  mOffset = pEdge->mpEndNodeHandle.mOffset;
  if ( mOffset )
    v1 = (char *)&pEdge->mpEndNodeHandle + mOffset;
  v5 = *((_QWORD *)v1 + 5);
  if ( v5 && *(_WORD *)(v5 + 34) && (mFlags = pEdge->mFlags, (mFlags & 2) != 0) && (mFlags & 0x80u) == 0 )
    return 1;
  else
    return 0;
}

