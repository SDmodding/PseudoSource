// File Line: 66
// RVA: 0xBCEA0
void __fastcall UFG::UITiledMapGPS::UITiledMapGPS(UFG::UITiledMapGPS *this)
{
  UFG::UITiledMapGPS *v1; // rdi
  UFG::MiniMapWayFinderClient *v2; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::HudComponent> *v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = &this->mWayFinderClient;
  UFG::WayFinderClient::WayFinderClient((UFG::WayFinderClient *)&this->mWayFinderClient.vfptr);
  v2->vfptr = (UFG::WayFinderClientVtbl *)&UFG::MiniMapWayFinderClient::`vftable';
  v2->m_LastLaneIndex = -1;
  *(_WORD *)&v2->m_AllowFootPaths = 1;
  v2->m_LaneFlags = 64;
  v1->mSplinePoints.p = 0i64;
  *(_QWORD *)&v1->mSplinePoints.size = 0i64;
  v3 = &v1->mTrackingTarget;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->mTrackingTarget.m_pPointer = 0i64;
  v1->mUpdateTimer = 0.0;
  *(_DWORD *)&v1->mChanged = 16777473;
  *(_DWORD *)&v1->mInVehicle = 256;
  v1->mOnlyShowInVehicles = 0;
  v1->mIsManualMapDest = 0;
  *(_QWORD *)&v1->mSourcePos.x = 0i64;
  *(_QWORD *)&v1->mSourcePos.z = 0i64;
  *(_QWORD *)&v1->mSourceDir.y = 0i64;
  *(_QWORD *)&v1->mDestinationPos.x = 0i64;
  *(_QWORD *)&v1->mDestinationPos.z = 0i64;
  *(_QWORD *)&v1->mDestinationDir.y = 0i64;
  v1->mGPS_UpdatePeriod = 0.5;
  v1->mTrueDirectionIntersectionLane = 0i64;
  v1->mTrueDirectionHighwayRamp = 0;
  v1->mTrueDirectionEdgeCount = 0;
  v1->mNumSplinePoints = 0;
  v1->mMaxNumSplinePoints = 50;
}

// File Line: 72
// RVA: 0xC5B60
void __fastcall UFG::UITiledMapGPS::Initialize(UFG::UITiledMapGPS *this)
{
  *(_DWORD *)&this->mChanged = 16777473;
  *(_DWORD *)&this->mInVehicle = 256;
  this->mUpdateTimer = 0.0;
  this->mOnlyShowInVehicles = 0;
  this->mIsManualMapDest = 0;
  *(_QWORD *)&this->mSourcePos.x = 0i64;
  *(_QWORD *)&this->mSourcePos.z = 0i64;
  *(_QWORD *)&this->mSourceDir.y = 0i64;
  *(_QWORD *)&this->mDestinationPos.x = 0i64;
  *(_QWORD *)&this->mDestinationPos.z = 0i64;
  *(_QWORD *)&this->mDestinationDir.y = 0i64;
  this->mGPS_UpdatePeriod = 0.5;
  this->mTrueDirectionIntersectionLane = 0i64;
  this->mTrueDirectionHighwayRamp = 0;
  this->mTrueDirectionEdgeCount = 0;
  this->mNumSplinePoints = 0;
  this->mMaxNumSplinePoints = 50;
}

// File Line: 109
// RVA: 0xCA430
void __fastcall UFG::UITiledMapGPS::SetActive(UFG::UITiledMapGPS *this, bool value)
{
  bool v2; // zf

  v2 = this->mActive == value;
  this->mActive = value;
  this->mChanged |= !v2;
}

// File Line: 116
// RVA: 0xCB8D0
void __fastcall UFG::UITiledMapGPS::SetVisible(UFG::UITiledMapGPS *this, bool value)
{
  bool v2; // zf

  v2 = this->mVisible == value;
  this->mVisible = value;
  this->mChanged |= !v2;
}

// File Line: 144
// RVA: 0xC4D70
void __fastcall UFG::UITiledMapGPS::HandleScreenInit(UFG::UITiledMapGPS *this, UFG::UIScreen *screen)
{
  float v2; // eax

  v2 = this->mGPS_UpdatePeriod;
  this->mChanged = 1;
  this->mUpdateTimer = v2;
}

// File Line: 152
// RVA: 0xCC6A0
void __fastcall UFG::UITiledMapGPS::Update(UFG::UITiledMapGPS *this, float elapsed, UFG::UIScreen *screen, UFG::UITiledMapMath *geo)
{
  UFG::UITiledMapGPS *v4; // rbx
  float v5; // xmm6_4
  UFG::HudComponent *v6; // rcx
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  hkgpIndexedMesh::EdgeBarrier *v12; // rdi
  int v13; // edx
  int v14; // er8
  hkgpIndexedMeshDefinitions::Edge *v15; // rdx
  bool v16; // al
  char v17; // di
  bool v18; // si
  float v19; // xmm6_4
  bool v20; // zf
  unsigned int v21; // edx
  UFG::qVector3 pos; // [rsp+20h] [rbp-28h]

  if ( screen )
  {
    v4 = this;
    v5 = elapsed;
    UFG::UITiledMapGPS::UpdateRace(this);
    v6 = (UFG::HudComponent *)v4->mTrackingTarget.m_pPointer;
    if ( v6 )
    {
      pos = UFG::qVector3::msZero;
      if ( UFG::HudComponent::GetWorldPosition(v6, &pos) )
      {
        v7 = pos.y;
        if ( (float)((float)((float)(v4->mDestinationPos.y - pos.y) * (float)(v4->mDestinationPos.y - pos.y))
                   + (float)((float)(v4->mDestinationPos.x - pos.x) * (float)(v4->mDestinationPos.x - pos.x))) > 25.0 )
        {
          v4->mDestinationPos.x = pos.x;
          v8 = pos.z;
          v4->mDestinationPos.z = pos.z;
          v4->mDestinationPos.y = v7;
          v9 = v4->mDestinationPos.x - v4->mSourcePos.x;
          v10 = v7 - v4->mSourcePos.y;
          v11 = v8 - v4->mSourcePos.z;
          v4->mDestinationDir.x = v9;
          v4->mDestinationDir.y = v10;
          v4->mDestinationDir.z = v11;
          LODWORD(v4->mSourceDir.x) = LODWORD(v9) ^ _xmm[0];
          LODWORD(v4->mSourceDir.y) = LODWORD(v10) ^ _xmm[0];
          LODWORD(v4->mSourceDir.z) = LODWORD(v11) ^ _xmm[0];
          *(_WORD *)&v4->mChanged = 257;
        }
      }
    }
    if ( v4->mUsePlayerSourcePos )
    {
      UFG::UITiledMapGPS::UpdatePlayerPos(v4);
      v12 = (hkgpIndexedMesh::EdgeBarrier *)UFG::WheeledVehicleManager::m_Instance;
      if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
             (hkGeometryUtils::IVertices *)UFG::WheeledVehicleManager::m_Instance,
             v13,
             v14)
        || Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v12, v15) )
      {
        UFG::UITiledMapGPS::UpdateTrueDirection(v4);
      }
      if ( !v4->mTrackingTarget.m_pPointer
        && v4->mIsManualMapDest
        && (float)((float)((float)(v4->mDestinationPos.y - v4->mSourcePos.y)
                         * (float)(v4->mDestinationPos.y - v4->mSourcePos.y))
                 + (float)((float)(v4->mDestinationPos.x - v4->mSourcePos.x)
                         * (float)(v4->mDestinationPos.x - v4->mSourcePos.x))) < 400.0 )
      {
        UFG::UITiledMapGPS::HandleArrivedAtManualMapDestination(v4);
      }
    }
    v16 = UFG::UI::IsPlayerInVehicle();
    v17 = v16 ^ v4->mInVehicle;
    v18 = v16;
    if ( v17 )
    {
      v4->mWayFinderClient.vfptr->ResetWay((UFG::WayFinderClient *)&v4->mWayFinderClient.vfptr);
      v4->mWayFinderClient.m_AllowFootPaths = 1;
    }
    v4->mChanged |= v17;
    v19 = v5 + v4->mUpdateTimer;
    v4->mInVehicle = v18;
    v4->mUpdateTimer = v19;
    v4->mWayFinderClient.m_AllowFootPaths = v18 == 0;
    if ( v19 >= v4->mGPS_UpdatePeriod )
    {
      v20 = v4->mChanged == 0;
      v4->mUpdateTimer = 0.0;
      if ( !v20 )
      {
        v21 = v4->mMaxNumSplinePoints;
        if ( v4->mSplinePoints.size != v21 && v21 > v4->mSplinePoints.capacity )
          UFG::qArray<UFG::qVector3,0>::Reallocate(&v4->mSplinePoints, v21, "mMaxNumSplinePoints");
        UFG::UITiledMapGPS::DoGenerateSpline(v4);
        *(_WORD *)&v4->mChanged = 0;
      }
    }
  }
}

// File Line: 308
// RVA: 0xCEAE0
void __fastcall UFG::UITiledMapGPS::UsePlayerSourcePosition(UFG::UITiledMapGPS *this)
{
  this->mUsePlayerSourcePos = 1;
}

// File Line: 330
// RVA: 0xCA6F0
void __fastcall UFG::UITiledMapGPS::SetDestination(UFG::UITiledMapGPS *this, UFG::qVector3 *dest, bool isManualMapDest)
{
  UFG::UITiledMapGPS *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4
  UFG::qSafePointer<UFG::SimComponent,UFG::HudComponent> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::WayFinderClientVtbl *v9; // rax
  bool v10; // zf
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm1_4

  v3 = this;
  if ( (float)((float)((float)(this->mDestinationPos.y - dest->y) * (float)(this->mDestinationPos.y - dest->y))
             + (float)((float)(this->mDestinationPos.x - dest->x) * (float)(this->mDestinationPos.x - dest->x))) >= 1.0 )
  {
    this->mChanged = 1;
    this->mNoDestination = 0;
    v4 = dest->y;
    v5 = dest->z;
    this->mDestinationPos.x = dest->x;
    v6 = &this->mTrackingTarget;
    this->mDestinationPos.y = v4;
    this->mDestinationPos.z = v5;
    this->mDestChanged = 1;
    if ( this->mTrackingTarget.m_pPointer )
    {
      v7 = v6->mPrev;
      v8 = v6->mNext;
      v7->mNext = v8;
      v8->mPrev = v7;
      v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
      v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    }
    v6->m_pPointer = 0i64;
    v9 = v3->mWayFinderClient.vfptr;
    v3->mIsManualMapDest = isManualMapDest;
    v9->ResetWay((UFG::WayFinderClient *)&v3->mWayFinderClient.vfptr);
    v10 = v3->mUsePlayerSourcePos == 0;
    v11 = v3->mGPS_UpdatePeriod + v3->mUpdateTimer;
    v3->mWayFinderClient.m_AllowFootPaths = 1;
    v3->mUpdateTimer = v11;
    if ( v10 )
    {
      v12 = v3->mDestinationPos.x - v3->mSourcePos.x;
      v13 = v3->mDestinationPos.y - v3->mSourcePos.y;
      v14 = v3->mDestinationPos.z - v3->mSourcePos.z;
      v3->mDestinationDir.x = v12;
      v3->mDestinationDir.y = v13;
      v3->mDestinationDir.z = v14;
      LODWORD(v3->mSourceDir.x) = LODWORD(v12) ^ _xmm[0];
      LODWORD(v3->mSourceDir.y) = LODWORD(v13) ^ _xmm[0];
      LODWORD(v3->mSourceDir.z) = LODWORD(v14) ^ _xmm[0];
    }
  }
}

// File Line: 352
// RVA: 0xCB7A0
void __fastcall UFG::UITiledMapGPS::SetTrackingTarget(UFG::UITiledMapGPS *this, UFG::HudComponent *target)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mTrackingTarget.mPrev;
  if ( this->mTrackingTarget.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = v2;
    v2->mNext = v2;
  }
  v2[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)target;
  if ( target )
  {
    v5 = target->m_SafePointerList.mNode.mPrev;
    v5->mNext = v2;
    v2->mPrev = v5;
    v2->mNext = &target->m_SafePointerList.mNode;
    target->m_SafePointerList.mNode.mPrev = v2;
  }
}

// File Line: 408
// RVA: 0xC66A0
void __fastcall UFG::UITiledMapGPS::PopulateWorldMap(UFG::UITiledMapGPS *this, UFG::UITiledMapGPS *clone)
{
  float v2; // xmm0_4
  float v3; // xmm1_4
  UFG::UITiledMapGPS *v4; // rbx
  UFG::UITiledMapGPS *v5; // rdi
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // eax
  float v11; // xmm1_4
  bool v12; // al

  v2 = this->mSourcePos.y;
  v3 = this->mSourcePos.z;
  clone->mSourcePos.x = this->mSourcePos.x;
  v4 = clone;
  v5 = this;
  clone->mSourcePos.y = v2;
  clone->mSourcePos.z = v3;
  v6 = this->mSourceDir.y;
  v7 = this->mSourceDir.z;
  clone->mSourceDir.x = this->mSourceDir.x;
  clone->mSourceDir.y = v6;
  clone->mSourceDir.z = v7;
  v8 = this->mDestinationPos.y;
  v9 = this->mDestinationPos.z;
  clone->mDestinationPos.x = this->mDestinationPos.x;
  clone->mDestinationPos.y = v8;
  clone->mDestinationPos.z = v9;
  v10 = this->mDestinationDir.x;
  v11 = this->mDestinationDir.z;
  clone->mDestinationDir.y = this->mDestinationDir.y;
  clone->mDestinationDir.x = v10;
  clone->mDestinationDir.z = v11;
  *(_WORD *)&clone->mChanged = 257;
  clone->mActive = this->mActive;
  clone->mInVehicle = this->mInVehicle;
  clone->mNoDestination = this->mNoDestination;
  clone->mUsePlayerSourcePos = this->mUsePlayerSourcePos;
  v12 = this->mVisible && this->mActive;
  clone->mVisible = v12;
  ((void (*)(void))clone->mWayFinderClient.vfptr->ResetWay)();
  v4->mWayFinderClient.m_AllowFootPaths = 1;
  v4->mWayFinderClient.m_AllowFootPaths = v5->mWayFinderClient.m_AllowFootPaths;
  v4->mWayFinderClient.m_RestrictedMode = v5->mWayFinderClient.m_RestrictedMode;
  v4->mWayFinderClient.m_LaneFlags = v5->mWayFinderClient.m_LaneFlags;
}

// File Line: 431
// RVA: 0xC44C0
float __fastcall UFG::UITiledMapGPS::GetPathLength(UFG::UITiledMapGPS *this)
{
  unsigned __int16 *v1; // r15
  float v2; // xmm7_4
  UFG::UITiledMapGPS *v3; // rdi
  float v4; // xmm6_4
  float v5; // xmm0_4
  unsigned int v6; // esi
  UFG::RoadNetworkResource *v7; // rax
  UFG::RoadNetworkResource *v8; // r12
  __int64 v9; // rbp
  char *v10; // r13
  UFG::RoadNetworkSegment *v11; // rax
  UFG::RoadNetworkLane *v12; // rax
  UFG::WayFinderClientVtbl *v13; // r8
  UFG::RoadNetworkLane *v14; // rbx
  UFG::qVector3 *v15; // rax
  __int64 v16; // r14
  UFG::RoadNetworkSegment *v17; // rax
  float v18; // xmm1_4
  UFG::RoadNetworkNode *v19; // rbx
  __m128 v20; // xmm0
  UFG::RoadNetworkLane *v21; // rax
  UFG::RoadNetworkLane *v22; // rbx
  float v23; // xmm0_4
  int v24; // ebx
  unsigned int v25; // edi
  UFG::RoadNetworkSegment *v26; // rax
  UFG::RoadNetworkGate *v27; // rbp
  UFG::RoadNetworkLane *v28; // r14
  char v29; // si
  unsigned int v30; // ebx
  UFG::RoadNetworkGate *v31; // r15
  UFG::RoadNetworkConnection *v32; // rax
  __int64 v33; // rcx
  UFG::RoadNetworkConnection *v34; // rdx
  signed __int64 v35; // rcx
  __int64 v36; // rax
  signed __int64 v37; // rax
  bool v38; // bl
  float v39; // xmm1_4
  unsigned int v40; // ebx
  UFG::RoadNetworkSegment *v41; // r14
  UFG::RoadNetworkGate *v42; // r15
  UFG::RoadNetworkGate *v43; // rsi
  __int64 v44; // rax
  signed __int64 v45; // rcx
  __int64 v46; // rax
  signed __int64 v47; // rax
  UFG::RoadNetworkLane *v48; // rbx
  UFG::RoadNetworkLane *v49; // rax
  UFG::RoadNetworkLane *v50; // rcx
  char v51; // si
  unsigned int v52; // ebx
  UFG::RoadNetworkSegment *v53; // r15
  UFG::RoadNetworkConnection *v54; // rdi
  UFG::RoadNetworkConnection *v55; // rax
  UFG::RoadNetworkGate *v56; // r8
  __int64 v57; // rcx
  signed __int64 v58; // rcx
  __int64 v59; // rax
  signed __int64 v60; // rax
  bool v61; // bl
  float v62; // xmm1_4
  unsigned __int16 *v63; // [rsp+20h] [rbp-C8h]
  UFG::RoadNetworkNode *targetNode; // [rsp+28h] [rbp-C0h]
  UFG::qVector3 pos; // [rsp+38h] [rbp-B0h]
  UFG::qVector3 v66; // [rsp+48h] [rbp-A0h]
  UFG::qVector3 result; // [rsp+58h] [rbp-90h]
  int v68; // [rsp+F0h] [rbp+8h]
  unsigned int v69; // [rsp+F8h] [rbp+10h]
  float laneT; // [rsp+100h] [rbp+18h]
  float v71; // [rsp+108h] [rbp+20h]

  v1 = this->mWayFinderClient.m_WayEdges;
  v2 = 0.0;
  v3 = this;
  v63 = this->mWayFinderClient.m_WayEdges;
  v4 = 0.0;
  if ( this == (UFG::UITiledMapGPS *)-110i64 )
    return 0.0;
  v6 = this->mWayFinderClient.m_NumWayEdges;
  v69 = this->mWayFinderClient.m_NumWayEdges;
  if ( !this->mWayFinderClient.m_NumWayEdges )
    return 0.0;
  v7 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  v8 = v7;
  if ( !v7 )
    return 0.0;
  v9 = v3->mWayFinderClient.m_CurrEdgeIndex;
  v10 = (char *)&v1[v9];
  v68 = v3->mWayFinderClient.m_CurrEdgeIndex;
  v11 = UFG::RoadNetworkResource::GetSegment(v7, v1[v9]);
  v12 = UFG::RoadNetworkNode::GetCenterLane((UFG::RoadNetworkNode *)&v11->mType);
  v13 = v3->mWayFinderClient.vfptr;
  v14 = v12;
  laneT = 0.0;
  v15 = v13->GetPosition((UFG::WayFinderClient *)&v3->mWayFinderClient.vfptr, (UFG::qVector3 *)&targetNode);
  UFG::RoadNetworkLane::GetNearestPoint(v14, &result, v15, &laneT);
  v16 = v6 - 1;
  v17 = UFG::RoadNetworkResource::GetSegment(v8, v1[v16]);
  v18 = v3->mDestinationPos.y;
  pos.x = v3->mDestinationPos.x;
  pos.y = v18;
  v19 = (UFG::RoadNetworkNode *)&v17->mType;
  pos.z = 0.0;
  UFG::RoadNetworkNode::GetClosestPosition((UFG::RoadNetworkNode *)&v17->mType, &v66, &pos, 0i64);
  v20 = (__m128)LODWORD(v66.z);
  pos.z = v66.z;
  v21 = UFG::RoadNetworkNode::GetCenterLane(v19);
  v71 = 0.0;
  v22 = v21;
  UFG::RoadNetworkLane::GetNearestPoint(v21, &result, &pos, &v71);
  if ( (_DWORD)v9 == (_DWORD)v16 )
  {
    v23 = UFG::RoadNetworkLane::GetLength(v22);
    LODWORD(v5) = COERCE_UNSIGNED_INT((float)(v23 * v71) - (float)(v23 * laneT)) & _xmm;
    return v5;
  }
  v24 = v9;
  v25 = v9;
  if ( (unsigned int)v9 >= v6 )
    return v4;
  while ( 1 )
  {
    v26 = UFG::RoadNetworkResource::GetSegment(v8, *(unsigned __int16 *)v10);
    v27 = (UFG::RoadNetworkGate *)v26;
    if ( !v26 )
      goto LABEL_44;
    v28 = UFG::RoadNetworkNode::GetCenterLane((UFG::RoadNetworkNode *)&v26->mType);
    if ( !v28 )
      goto LABEL_44;
    if ( v25 == v6 - 1 )
      break;
    if ( v25 == v24 )
    {
      v29 = 1;
      v30 = v1[v25 + 1];
      targetNode = (UFG::RoadNetworkNode *)UFG::RoadNetworkResource::GetSegment(v8, v30);
      v31 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(v27, 0);
      v32 = UFG::RoadNetworkGate::GetIncomingConnection(v27, 1u);
      v33 = v31->mConnectedNode.mOffset;
      v34 = v32;
      if ( v33
        && (v35 = (signed __int64)&v31->mConnectedNode + v33) != 0
        && !*(_WORD *)v35
        && *(_DWORD *)(v35 + 24) == v30 )
      {
        v29 = 0;
      }
      else
      {
        v36 = v32->mLaneList.mOffset;
        if ( !v36 || (v37 = (signed __int64)&v34->mLaneList + v36) == 0 || *(_WORD *)v37 || *(_DWORD *)(v37 + 24) != v30 )
        {
          v29 = 1;
          if ( UFG::RoadNetworkGate::GetAnyLaneLeadingToNode(v31, targetNode) )
            v29 = 0;
        }
      }
      v38 = UFG::RoadNetworkLane::IsReversedInNode(v28);
      v20.m128_f32[0] = UFG::RoadNetworkLane::GetLength(v28);
      v39 = v20.m128_f32[0] * laneT;
      if ( v38 == v29 )
        v20 = 0i64;
      v1 = v63;
      v6 = v69;
      v20.m128_f32[0] = v20.m128_f32[0] - v39;
      v20 = _mm_and_ps(v20, (__m128)(unsigned int)_xmm);
    }
    else
    {
      v20.m128_f32[0] = UFG::RoadNetworkLane::GetLength(v28);
    }
    v4 = v4 + v20.m128_f32[0];
    v40 = v1[v25 + 1];
    v41 = UFG::RoadNetworkResource::GetSegment(v8, v40);
    if ( !v41 )
      goto LABEL_43;
    v42 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(v27, 0);
    v43 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(v27, 1u);
    v44 = v42->mConnectedNode.mOffset;
    if ( !v44
      || (v45 = (signed __int64)&v42->mConnectedNode + v44) == 0
      || *(_WORD *)v45
      || *(_DWORD *)(v45 + 24) != v40 )
    {
      v46 = v43->mConnectedNode.mOffset;
      if ( !v46
        || (v47 = (signed __int64)&v43->mConnectedNode + v46) == 0
        || *(_WORD *)v47
        || *(_DWORD *)(v47 + 24) != v40 )
      {
        v48 = UFG::RoadNetworkGate::GetAnyLaneLeadingToNode(v42, (UFG::RoadNetworkNode *)&v41->mType);
        v49 = UFG::RoadNetworkGate::GetAnyLaneLeadingToNode(v43, (UFG::RoadNetworkNode *)&v41->mType);
        if ( v48 )
        {
          v50 = v48;
          goto LABEL_41;
        }
        if ( v49 )
        {
          v50 = v49;
LABEL_41:
          v4 = v4 + UFG::RoadNetworkLane::GetLength(v50);
          goto LABEL_42;
        }
      }
    }
LABEL_42:
    v6 = v69;
    v1 = v63;
LABEL_43:
    v24 = v68;
LABEL_44:
    ++v25;
    v10 += 2;
    if ( v25 >= v6 )
      return v4;
  }
  v51 = 1;
  v52 = v1[v25 - 1];
  v53 = UFG::RoadNetworkResource::GetSegment(v8, v52);
  v54 = UFG::RoadNetworkGate::GetIncomingConnection(v27, 0);
  v55 = UFG::RoadNetworkGate::GetIncomingConnection(v27, 1u);
  v56 = (UFG::RoadNetworkGate *)v55;
  v57 = v55->mLaneList.mOffset;
  if ( v57 && (v58 = (signed __int64)&v55->mLaneList + v57) != 0 && !*(_WORD *)v58 && *(_DWORD *)(v58 + 24) == v52 )
  {
    v51 = 0;
  }
  else
  {
    v59 = v54->mLaneList.mOffset;
    if ( !v59 || (v60 = (signed __int64)&v54->mLaneList + v59) == 0 || *(_WORD *)v60 || *(_DWORD *)(v60 + 24) != v52 )
    {
      v51 = 1;
      if ( UFG::RoadNetworkGate::GetAnyLaneLeadingHereFromNode(v56, (UFG::RoadNetworkNode *)&v53->mType) )
        v51 = 0;
    }
  }
  v61 = UFG::RoadNetworkLane::IsReversedInNode(v28);
  v62 = UFG::RoadNetworkLane::GetLength(v28);
  if ( v61 == v51 )
    v2 = v62;
  return COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v62 * v71) - v2) & _xmm) + v4;
}    v51 = 0;
    }
  }
  v61 = UFG::RoadNetworkLane::IsReversedInNode(v28);
  v62 = UFG::RoadNetworkLane::GetLength(v28);
  if ( v61 == v51 )
    v2 = v62;
  return COERCE_FLOAT(COERCE_UNSIGNED_INT((floa

// File Line: 618
// RVA: 0xC0CE0
float __fastcall UFG::UITiledMapGPS::GetApproxAltitude(UFG::qVector3 *pos)
{
  UFG::qVector3 *v1; // rbx
  UFG::RoadNetworkResource *v2; // rax
  UFG::RoadNetworkNode *v4; // rax
  UFG::RoadNetworkLane *v5; // rax
  UFG::RoadNetworkLane *v6; // rbx
  UFG::qVector3 v7; // [rsp+30h] [rbp-28h]
  UFG::qVector3 result; // [rsp+40h] [rbp-18h]

  v1 = pos;
  v2 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  if ( !v2 )
    return 0.0;
  v4 = UFG::RoadNetworkResource::GetClosestNode(v2, v1, 0, 0i64, 0i64);
  if ( !v4 )
    return 0.0;
  v5 = UFG::RoadNetworkNode::GetLane(v4, (unsigned int)(unsigned __int8)v4->mNumLanes >> 1);
  v6 = v5;
  if ( !v5 )
    return 0.0;
  UFG::RoadNetworkLane::GetPos(v5, &result, 0.0);
  UFG::RoadNetworkLane::GetPos(v6, &v7, 1.0);
  return (float)(v7.z + result.z) * 0.5;
}

// File Line: 826
// RVA: 0xBE6B0
bool __fastcall UFG::MiniMapWayFinderClient::CanGo(UFG::MiniMapWayFinderClient *this, UFG::WayGraph *graph, unsigned __int16 from_edge, unsigned __int16 to_edge, unsigned __int16 thru_node)
{
  UFG::RoadNetworkGraph *v5; // rsi
  UFG::MiniMapWayFinderClient *v6; // rbx
  unsigned __int16 v7; // r14
  unsigned __int16 v8; // r13
  bool result; // al
  unsigned __int16 v10; // bp
  UFG::RoadNetworkResource *v11; // r15
  UFG::RoadNetworkSegment *v12; // rdi
  UFG::RoadNetworkSegment *v13; // rax

  v5 = (UFG::RoadNetworkGraph *)graph;
  v6 = this;
  v7 = to_edge;
  v8 = from_edge;
  if ( graph->vfptr->IsEdge(graph, thru_node) )
    return 1;
  v10 = v6->vfptr->GetWayEdge((UFG::WayFinderClient *)&v6->vfptr, (UFG::WayGraph *)&v5->vfptr);
  if ( v7 == v10 )
    return 1;
  v11 = v5->pRoadNetworkResource;
  v12 = UFG::RoadNetworkResource::GetSegment(v5->pRoadNetworkResource, v7);
  if ( *(_BYTE *)&v12->mBits & 1
    || (v13 = UFG::RoadNetworkResource::GetSegment(v11, v10), !v6->m_AllowFootPaths)
    && !((*(_DWORD *)&v13->mBits >> 1) & 1)
    && (*(_DWORD *)&v12->mBits >> 1) & 1
    || v6->m_RestrictedMode && (*(_DWORD *)&v12->mBits >> 2) & 1 )
  {
    result = 0;
  }
  else
  {
    result = UFG::RoadNetworkGraph::GetNumLanesFromToThru(v5, v8, v7, thru_node, (unsigned __int8)v6->m_LaneFlags) > 0;
  }
  return result;
}

// File Line: 863
// RVA: 0xC0F40
float __fastcall UFG::MiniMapWayFinderClient::GetEdgeLength(UFG::MiniMapWayFinderClient *this, UFG::WayGraph *wayGraph, unsigned __int16 wayEdge)
{
  UFG::RoadNetworkSegment *v3; // rax
  UFG::RoadNetworkSegment *v4; // rbx
  UFG::RoadNetworkLane *v5; // rax
  float result; // xmm0_4

  v3 = UFG::RoadNetworkResource::GetSegment((UFG::RoadNetworkResource *)wayGraph[3].vfptr, wayEdge);
  v4 = v3;
  v5 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v3->mType, 0);
  result = UFG::RoadNetworkLane::GetLength(v5);
  if ( (*(_DWORD *)&v4->mBits >> 2) & 1 )
    result = result * UFG::UITiledMapTweakables::GPS_RestrictedEdgeWeight;
  if ( (*(_DWORD *)&v4->mBits >> 1) & 1 )
  {
    if ( result <= (float)(UFG::UITiledMapTweakables::GPS_NoVehicleEdgeWeight * result) )
      result = UFG::UITiledMapTweakables::GPS_NoVehicleEdgeWeight * result;
  }
  return result;
}

// File Line: 880
// RVA: 0xCA410
void __fastcall UFG::MiniMapWayFinderClient::ResetWay(UFG::MiniMapWayFinderClient *this)
{
  UFG::MiniMapWayFinderClient *v1; // rbx

  v1 = this;
  UFG::WayFinderClient::ResetWay((UFG::WayFinderClient *)&this->vfptr);
  v1->m_LastLaneIndex = -1;
}

// File Line: 915
// RVA: 0xBEEF0
void __fastcall UFG::UITiledMapGPS::DoGenerateSpline(UFG::UITiledMapGPS *this)
{
  UFG::RoadNetworkLane *v1; // r12
  UFG::UITiledMapGPS *v2; // r14
  UFG::RoadNetworkResource *v3; // r13
  UFG::WheeledVehicleNavigationData *v4; // rsi
  unsigned __int16 v5; // ax
  UFG::WayFinderClientVtbl *v6; // r10
  unsigned __int16 v7; // bx
  bool v8; // al
  UFG::RoadNetworkSegment *v9; // rax
  UFG::WayFinder *v10; // rax
  UFG::WayFinder *v11; // rax
  int v12; // ebx
  signed __int64 v13; // rdi
  unsigned int v14; // ebx
  UFG::RoadNetworkSegment *v15; // rax
  float v16; // xmm1_4
  UFG::RoadNetworkSegment *v17; // rsi
  unsigned int v18; // er14
  unsigned int v19; // eax
  UFG::RoadNetworkLane *v20; // rax
  UFG::qVector3 *v21; // r13
  UFG::RoadNetworkLane *v22; // r15
  unsigned int v23; // ebx
  UFG::RoadNetworkLane *v24; // rdi
  UFG::UITiledMapGPS *v25; // rbx
  unsigned int j; // ebx
  UFG::RoadNetworkLane *v27; // rdi
  char v28; // bl
  UFG::RoadNetworkLane *v29; // r15
  float v30; // esi
  signed __int64 v31; // rcx
  unsigned int v32; // eax
  UFG::RoadNetworkSegment *v33; // rax
  UFG::RoadNetworkSegment *v34; // r13
  UFG::RoadNetworkLane *v35; // rdi
  char v36; // bl
  unsigned int v37; // esi
  UFG::RoadNetworkSegment *v38; // r15
  UFG::RoadNetworkConnection *v39; // r14
  UFG::RoadNetworkConnection *v40; // rax
  UFG::RoadNetworkGate *v41; // r8
  __int64 v42; // rcx
  signed __int64 v43; // rcx
  __int64 v44; // rax
  signed __int64 v45; // rax
  unsigned int v46; // er15
  UFG::RoadNetworkLane *v47; // r14
  unsigned int v48; // ebx
  UFG::RoadNetworkLane *v49; // rsi
  unsigned int i; // ebx
  UFG::RoadNetworkLane *v51; // rsi
  UFG::RoadNetworkSegment *v52; // rsi
  UFG::RoadNetworkGate *v53; // rbx
  UFG::RoadNetworkGate *v54; // r14
  UFG::RoadNetworkLane **v55; // rdx
  __int64 v56; // r8
  UFG::RoadNetworkLane *v57; // rcx
  char v58; // r13
  UFG::RoadNetworkLane **v59; // rdx
  __int64 v60; // r8
  UFG::RoadNetworkLane *v61; // rcx
  __int64 v62; // rax
  UFG::RoadNetworkConnection *v63; // rcx
  __int64 v64; // rax
  UFG::qOffset64<UFG::RoadNetworkGate *> *v65; // rax
  UFG::RoadNetworkSegment *v66; // rdx
  float v67; // xmm2_4
  UFG::RoadNetworkSegment *v68; // r14
  __int64 v69; // rcx
  UFG::RoadNetworkConnection *v70; // rsi
  __int64 v71; // rcx
  _QWORD *v72; // rax
  UFG::RoadNetworkSegment *v73; // rcx
  unsigned int v74; // edi
  unsigned int v75; // ebx
  UFG::RoadNetworkLane *v76; // rax
  UFG::RoadNetworkLane *v77; // r8
  __int64 v78; // rcx
  signed __int64 v79; // rcx
  __int64 v80; // rdx
  _QWORD *v81; // rax
  UFG::RoadNetworkSegment *v82; // rcx
  unsigned int v83; // [rsp+30h] [rbp-D0h]
  signed __int64 v84; // [rsp+38h] [rbp-C8h]
  UFG::qVector3 segPos; // [rsp+40h] [rbp-C0h]
  float v86; // [rsp+50h] [rbp-B0h]
  float v87; // [rsp+54h] [rbp-ACh]
  UFG::qVector3 pos; // [rsp+58h] [rbp-A8h]
  UFG::RoadNetworkResource *v89; // [rsp+68h] [rbp-98h]
  UFG::qVector3 v90; // [rsp+70h] [rbp-90h]
  UFG::qVector3 result; // [rsp+80h] [rbp-80h]
  UFG::RoadNetworkLane *laneList; // [rsp+90h] [rbp-70h]
  UFG::UITiledMapGPS *v93; // [rsp+130h] [rbp+30h]
  float endLaneT; // [rsp+138h] [rbp+38h]
  float laneT; // [rsp+140h] [rbp+40h]
  UFG::qVector3 *v96; // [rsp+148h] [rbp+48h]

  v93 = this;
  v1 = 0i64;
  v2 = this;
  this->mNumSplinePoints = 0;
  this->mSplinePoints.size = 0;
  v3 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  v89 = v3;
  if ( !v3 )
    return;
  v4 = UFG::WheeledVehicleManager::m_Instance->m_NavigationData;
  if ( !UFG::WheeledVehicleManager::m_Instance->m_NavigationData || !v4->m_RoadNetworkGraph.pWayfindingList )
    return;
  v5 = v2->mWayFinderClient.vfptr->GetWayEdge(
         (UFG::WayFinderClient *)&v2->mWayFinderClient.vfptr,
         (UFG::WayGraph *)&v4->m_RoadNetworkGraph.vfptr);
  v6 = v2->mWayFinderClient.vfptr;
  v7 = v5;
  v96 = &v2->mSourcePos;
  v6->SetPosition(
    (UFG::WayFinderClient *)&v2->mWayFinderClient.vfptr,
    (UFG::WayGraph *)&v4->m_RoadNetworkGraph.vfptr,
    &v2->mSourcePos,
    &v2->mSourceDir);
  v8 = v2->mWayFinderClient.vfptr->GetWayEdge(
         (UFG::WayFinderClient *)&v2->mWayFinderClient.vfptr,
         (UFG::WayGraph *)&v4->m_RoadNetworkGraph.vfptr) != v7;
  if ( v2->mDestChanged
    || v8
    || UFG::WheeledVehicleManager::m_Instance->m_NavigationData->m_RoadNetworkGraph.pWayfindingList
    && (0 == v2->mWayFinderClient.m_NumWayEdges
     || UFG::WayFinderClient::LostWay(
          (UFG::WayFinderClient *)&v2->mWayFinderClient.vfptr,
          (UFG::WayGraph *)&UFG::WheeledVehicleManager::m_Instance->m_NavigationData->m_RoadNetworkGraph.vfptr)) )
  {
    if ( !v2->mWayFinderClient.m_AllowFootPaths )
    {
      segPos = UFG::qVector3::msZero;
      v9 = UFG::RoadNetworkResource::GetClosestSegment(v3, &v2->mDestinationPos, 0i64, 0, &segPos, 0i64);
      if ( v9 )
      {
        if ( (*(_DWORD *)&v9->mBits >> 1) & 1 )
          v2->mWayFinderClient.m_AllowFootPaths = 1;
      }
    }
    v10 = UFG::GetWayFinder();
    UFG::WayFinder::FindWay(v10, (UFG::WayFinderClient *)&v2->mWayFinderClient.vfptr, &v2->mDestinationPos, 0i64);
    v11 = UFG::GetWayFinder();
    UFG::WayFinder::Service(v11, 0.0);
  }
  v84 = (signed __int64)v2->mWayFinderClient.m_WayEdges;
  if ( v2 == (UFG::UITiledMapGPS *)-110i64 )
    return;
  v12 = v2->mWayFinderClient.m_NumWayEdges;
  v83 = v2->mWayFinderClient.m_NumWayEdges;
  if ( !v2->mWayFinderClient.m_NumWayEdges )
    return;
  UFG::WayFinderClient::FindCurrentEdge((UFG::WayFinderClient *)&v2->mWayFinderClient.vfptr);
  v13 = (signed __int64)v2->mWayFinderClient.m_WayEdges;
  v14 = v12 - 1;
  LODWORD(v87) = v2->mWayFinderClient.m_CurrEdgeIndex;
  v15 = UFG::RoadNetworkResource::GetSegment(v3, v2->mWayFinderClient.m_WayEdges[v14]);
  v16 = v2->mDestinationPos.y;
  pos.x = v2->mDestinationPos.x;
  pos.y = v16;
  v17 = v15;
  pos.z = 0.0;
  UFG::RoadNetworkNode::GetClosestPosition((UFG::RoadNetworkNode *)&v15->mType, &result, &pos, 0i64);
  pos.z = result.z;
  if ( LODWORD(v87) != v14 )
  {
    v28 = 0;
    v29 = 0i64;
    v30 = v87;
    laneT = v87;
    v31 = LODWORD(v87);
    LOBYTE(endLaneT) = 0;
    *(_QWORD *)&segPos.x = LODWORD(v87);
    if ( LODWORD(v87) >= v83 )
    {
LABEL_129:
      v32 = v2->mSplinePoints.size;
LABEL_130:
      v2->mNumSplinePoints = v32;
      return;
    }
    while ( 1 )
    {
      v32 = v2->mSplinePoints.size;
      if ( v32 >= v2->mMaxNumSplinePoints )
        goto LABEL_130;
      v33 = UFG::RoadNetworkResource::GetSegment(v3, *(unsigned __int16 *)(v13 + 2 * v31));
      v34 = v33;
      if ( !v33 )
        goto LABEL_124;
      v35 = UFG::RoadNetworkNode::GetCenterLane((UFG::RoadNetworkNode *)&v33->mType);
      if ( v29 )
      {
        v62 = v29->mNextConnection.mOffset;
        if ( v62 )
        {
          v63 = (UFG::RoadNetworkConnection *)((char *)&v29->mNextConnection + v62);
          if ( v63 )
          {
            v64 = v63->mGate.mOffset;
            v65 = v64 ? (UFG::qOffset64<UFG::RoadNetworkGate *> *)((char *)&v63->mGate + v64) : 0i64;
            v66 = (UFG::RoadNetworkSegment *)(v65->mOffset ? (UFG::qOffset64<UFG::RoadNetworkGate *> *)((char *)v65 + v65->mOffset) : 0i64);
            if ( v66 == v34 )
              v35 = UFG::qBezierPathCollectionMemImaged::GetPath(v63, 0);
          }
        }
      }
      else
      {
        if ( LODWORD(v30) != v83 - 1 )
        {
          v52 = UFG::RoadNetworkResource::GetSegment(v89, v2->mWayFinderClient.m_WayEdges[LODWORD(v30) + 1]);
          if ( v52 )
          {
            v53 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v34, 0);
            v54 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v34, 1u);
            LODWORD(v96) = 0;
            UFG::RoadNetworkGate::GetLanesLeadingToNode(
              v53,
              (UFG::RoadNetworkNode *)&v52->mType,
              &laneList,
              (unsigned int *)&v96,
              8u,
              0xFFFFFFFF);
            if ( (_DWORD)v96
              || (UFG::RoadNetworkGate::GetLanesLeadingToNode(
                    v54,
                    (UFG::RoadNetworkNode *)&v52->mType,
                    &laneList,
                    (unsigned int *)&v96,
                    8u,
                    0xFFFFFFFF),
                  (_DWORD)v96) )
            {
              v35 = laneList;
              if ( UFG::RoadNetworkLane::IsReversedInNode(laneList) )
              {
                if ( (_DWORD)v96 )
                {
                  v55 = &laneList;
                  v56 = (unsigned int)v96;
                  do
                  {
                    v57 = *v55;
                    ++v55;
                    if ( v57->mLaneIndex < v35->mLaneIndex )
                      v35 = v57;
                    --v56;
                  }
                  while ( v56 );
                }
              }
              else if ( (_DWORD)v96 )
              {
                v59 = &laneList;
                v60 = (unsigned int)v96;
                do
                {
                  v61 = *v59;
                  ++v59;
                  if ( v61->mLaneIndex > v35->mLaneIndex )
                    v35 = v61;
                  --v60;
                }
                while ( v60 );
              }
            }
LABEL_66:
            v28 = LOBYTE(endLaneT);
            v2 = v93;
          }
          v30 = laneT;
          goto LABEL_68;
        }
        v36 = 1;
        v37 = *(unsigned __int16 *)(v84 + 2i64 * (unsigned int)(LODWORD(v30) - 1));
        v38 = UFG::RoadNetworkResource::GetSegment(v89, v37);
        v39 = UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v34, 0);
        v40 = UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v34, 1u);
        v41 = (UFG::RoadNetworkGate *)v40;
        v42 = v40->mLaneList.mOffset;
        if ( v42 && (v43 = (signed __int64)&v40->mLaneList + v42) != 0 && !*(_WORD *)v43 && *(_DWORD *)(v43 + 24) == v37 )
        {
          v36 = 0;
        }
        else
        {
          v44 = v39->mLaneList.mOffset;
          if ( !v44
            || (v45 = (signed __int64)&v39->mLaneList + v44) == 0
            || *(_WORD *)v45
            || *(_DWORD *)(v45 + 24) != v37 )
          {
            v36 = 1;
            if ( UFG::RoadNetworkGate::GetAnyLaneLeadingHereFromNode(v41, (UFG::RoadNetworkNode *)&v38->mType) )
              v36 = 0;
          }
        }
        v46 = (unsigned __int8)v34->mNumLanes;
        v47 = 0i64;
        if ( v36 )
        {
          v48 = 0;
          if ( !v34->mNumLanes )
            goto LABEL_66;
          do
          {
            v49 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v34->mType, v48);
            if ( UFG::RoadNetworkLane::IsReversedInNode(v49) )
              break;
            ++v48;
            v47 = v49;
          }
          while ( v48 < v46 );
        }
        else
        {
          for ( i = v46 - 1; ; --i )
          {
            v51 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v34->mType, i);
            if ( !UFG::RoadNetworkLane::IsReversedInNode(v51) )
              break;
            v47 = v51;
          }
        }
        v30 = laneT;
        v28 = LOBYTE(endLaneT);
        if ( v47 )
          v35 = v47;
        v2 = v93;
      }
LABEL_68:
      v29 = 0i64;
      if ( !v35 )
        goto LABEL_123;
      v32 = v2->mSplinePoints.size;
      if ( v32 >= v2->mMaxNumSplinePoints )
        goto LABEL_130;
      if ( (*(_DWORD *)&v34->mBits >> 1) & 1 )
      {
        v58 = 0;
      }
      else
      {
        v58 = 1;
        if ( LODWORD(v30) == LODWORD(v87) )
        {
          v86 = 0.0;
          UFG::RoadNetworkLane::GetNearestPoint(v35, &v90, &v2->mSourcePos, &v86);
          v67 = v86;
        }
        else
        {
          if ( LODWORD(v30) == v83 - 1 )
          {
            LODWORD(v93) = 0;
            UFG::RoadNetworkLane::GetNearestPoint(v35, &v90, &pos, (float *)&v93);
            UFG::UITiledMapGPS::PlotRoadLane(v2, v35, 0.0, *(float *)&v93, v28 == 0);
            goto LABEL_129;
          }
          v67 = 0.0;
        }
        UFG::UITiledMapGPS::PlotRoadLane(v2, v35, v67, 1.0, v28 == 0);
        v32 = v2->mSplinePoints.size;
        LOBYTE(endLaneT) = 1;
        if ( v32 >= v2->mMaxNumSplinePoints )
          goto LABEL_130;
      }
      if ( LODWORD(v30) == v83 - 1 )
        goto LABEL_129;
      v68 = UFG::RoadNetworkResource::GetSegment(
              v89,
              *(unsigned __int16 *)(v84 + 2i64 * (unsigned int)(LODWORD(v30) + 1)));
      if ( v68 && (v69 = v35->mNextConnection.mOffset) != 0 )
      {
        v70 = (UFG::RoadNetworkConnection *)((char *)&v35->mNextConnection + v69);
        if ( !v70 )
          goto LABEL_105;
        v71 = v70->mGate.mOffset;
        if ( v71 )
          v72 = (__int64 *)((char *)&v70->mGate.mOffset + v71);
        else
          v72 = 0i64;
        if ( *v72 )
          v73 = (UFG::RoadNetworkSegment *)((char *)v72 + *v72);
        else
          v73 = 0i64;
        if ( v73 == v68 )
        {
          v29 = v35;
LABEL_105:
          v2 = v93;
          v30 = laneT;
          v28 = LOBYTE(endLaneT);
          v13 = v84;
          goto LABEL_124;
        }
        v74 = v70->mNumLanes;
        v75 = 0;
        if ( v70->mNumLanes )
        {
          while ( 1 )
          {
            v76 = UFG::qBezierPathCollectionMemImaged::GetPath(v70, v75);
            v77 = v76;
            v78 = v76->mNextConnection.mOffset;
            if ( v78 )
            {
              v79 = (signed __int64)&v76->mNextConnection + v78;
              if ( v79 )
              {
                v80 = *(_QWORD *)(v79 + 24);
                v81 = (_QWORD *)(v80 ? v79 + v80 + 24 : 0i64);
                v82 = (UFG::RoadNetworkSegment *)(*v81 ? (_QWORD *)((char *)v81 + *v81) : 0i64);
                if ( v82 == v68 )
                  break;
              }
            }
            if ( ++v75 >= v74 )
              goto LABEL_119;
          }
          v29 = v77;
        }
LABEL_119:
        if ( (v58 || ~(unsigned __int8)(*(_DWORD *)&v68->mBits >> 1) & 1) && v29 )
        {
          v2 = v93;
          UFG::UITiledMapGPS::PlotRoadLane(v93, v29, 0.0, 1.0, LOBYTE(endLaneT) == 0);
          v30 = laneT;
          v28 = 1;
          LOBYTE(endLaneT) = 1;
LABEL_123:
          v13 = (signed __int64)v2->mWayFinderClient.m_WayEdges;
          goto LABEL_124;
        }
        v2 = v93;
        v30 = laneT;
        v13 = v84;
        v28 = 0;
        LOBYTE(endLaneT) = 0;
      }
      else
      {
        v2 = v93;
        v28 = LOBYTE(endLaneT);
        v13 = v84;
      }
LABEL_124:
      ++LODWORD(v30);
      v31 = *(_QWORD *)&segPos.x + 1i64;
      laneT = v30;
      ++*(_QWORD *)&segPos.x;
      if ( LODWORD(v30) >= v83 )
        goto LABEL_129;
      v3 = v89;
    }
  }
  v18 = (unsigned __int8)v17->mNumLanes;
  if ( v17->mNumLanes && ~(unsigned __int8)(*(_DWORD *)&v17->mBits >> 1) & 1 )
  {
    v19 = UFG::RoadNetworkNode::GetCenterLaneIndex((UFG::RoadNetworkNode *)&v17->mType);
    v20 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v17->mType, v19);
    v21 = v96;
    v22 = v20;
    laneT = 0.0;
    UFG::RoadNetworkLane::GetNearestPoint(v20, &segPos, v96, &laneT);
    endLaneT = 0.0;
    UFG::RoadNetworkLane::GetNearestPoint(v22, &segPos, &pos, &endLaneT);
    if ( laneT > endLaneT )
    {
      if ( !UFG::RoadNetworkLane::IsReversedInNode(v22) )
      {
        for ( j = v18 - 1; ; --j )
        {
          v27 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v17->mType, j);
          if ( !UFG::RoadNetworkLane::IsReversedInNode(v27) )
            break;
          v1 = v27;
        }
LABEL_24:
        if ( v1 )
        {
          v22 = v1;
          UFG::RoadNetworkLane::GetNearestPoint(v1, &segPos, v21, &laneT);
          UFG::RoadNetworkLane::GetNearestPoint(v1, &segPos, &pos, &endLaneT);
        }
        goto LABEL_26;
      }
      v23 = 0;
      if ( v18 )
      {
        do
        {
          v24 = UFG::RoadNetworkNode::GetLane((UFG::RoadNetworkNode *)&v17->mType, v23);
          if ( UFG::RoadNetworkLane::IsReversedInNode(v24) )
            break;
          ++v23;
          v1 = v24;
        }
        while ( v23 < v18 );
        goto LABEL_24;
      }
    }
LABEL_26:
    v25 = v93;
    UFG::UITiledMapGPS::PlotRoadLane(v93, v22, laneT, endLaneT, 1);
    v25->mNumSplinePoints = v25->mSplinePoints.size;
    return;
  }
  v93->mNumSplinePoints = v93->mSplinePoints.size;
}

// File Line: 1281
// RVA: 0xC6230
void __fastcall UFG::UITiledMapGPS::PlotRoadLane(UFG::UITiledMapGPS *this, UFG::RoadNetworkLane *roadLane, float startLaneT, float endLaneT, bool plotFirstPoint)
{
  UFG::UITiledMapGPS *v5; // rdi
  float v6; // xmm6_4
  UFG::RoadNetworkLane *v7; // rbx
  float v8; // xmm0_4
  float v9; // xmm7_4
  float v10; // xmm8_4

  if ( !roadLane )
    return;
  v5 = this;
  v6 = startLaneT;
  v7 = roadLane;
  v8 = UFG::RoadNetworkLane::GetLength(roadLane);
  if ( v8 < 0.000099999997 )
    return;
  v9 = 1.0 / (float)((signed int)(float)(v8 * 0.06666667) + 1);
  if ( startLaneT > endLaneT )
  {
    if ( !plotFirstPoint )
      v6 = v9 + startLaneT;
    if ( v6 > (float)(endLaneT + 0.0000099999997) )
    {
      while ( UFG::UITiledMapGPS::AddSplinePoint(v5, v7, v6) )
      {
        v6 = v6 - v9;
        if ( v6 <= (float)(endLaneT + 0.0000099999997) )
          goto LABEL_17;
      }
      return;
    }
LABEL_17:
    UFG::UITiledMapGPS::AddSplinePoint(v5, v7, endLaneT);
    return;
  }
  if ( !plotFirstPoint )
    v6 = v9 + startLaneT;
  v10 = endLaneT - 0.0000099999997;
  if ( (float)(endLaneT - 0.0000099999997) <= 0.0 )
    v10 = 0.0;
  if ( v6 >= v10 )
    goto LABEL_17;
  while ( UFG::UITiledMapGPS::AddSplinePoint(v5, v7, v6) )
  {
    v6 = v6 + v9;
    if ( v6 >= v10 )
      goto LABEL_17;
  }
}

// File Line: 1322
// RVA: 0xBE470
char __fastcall UFG::UITiledMapGPS::AddSplinePoint(UFG::UITiledMapGPS *this, UFG::RoadNetworkLane *roadLane, float laneT)
{
  UFG::qArray<UFG::qVector3,0> *v3; // rdi
  signed __int64 v5; // rsi
  unsigned int v6; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  UFG::qVector3 *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm2_4
  signed __int64 v12; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  v3 = &this->mSplinePoints;
  if ( this->mSplinePoints.size >= this->mMaxNumSplinePoints )
    return 0;
  UFG::RoadNetworkLane::GetPosNoOffset(roadLane, &result, laneT);
  v5 = v3->size;
  v6 = v3->capacity;
  v7 = v5 + 1;
  if ( (signed int)v5 + 1 > v6 )
  {
    if ( v6 )
      v8 = 2 * v6;
    else
      v8 = 1;
    for ( ; v8 < v7; v8 *= 2 )
      ;
    if ( v8 - v7 > 0x10000 )
      v8 = v5 + 65537;
    UFG::qArray<UFG::qVector3,0>::Reallocate(v3, v8, "qArray.Add");
  }
  v9 = v3->p;
  v10 = result.y;
  v11 = result.z;
  v12 = v5;
  v3->size = v7;
  v9[v12].x = result.x;
  v9[v12].y = v10;
  v9[v12].z = v11;
  return 1;
}

// File Line: 1699
// RVA: 0xCE300
void __fastcall UFG::UITiledMapGPS::UpdateRace(UFG::UITiledMapGPS *this)
{
  UFG::UITiledMapGPS *v1; // rdi
  unsigned __int16 v2; // dx
  UFG::CharacterOccupantComponent *v3; // rax
  UFG::SimObjectGame *v4; // rax
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rbx
  UFG::RacePoint *v8; // rbx
  UFG::qVector3 *v9; // rax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  bool v14; // zf
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  v1 = this;
  if ( !this->mActive )
  {
    if ( LocalPlayer
      && ((v2 = LocalPlayer->m_Flags, !((v2 >> 14) & 1)) ? ((v2 & 0x8000u) == 0 ? (!((v2 >> 13) & 1) ? (!((v2 >> 12) & 1) ? (v3 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v3 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v3 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v3 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v3 = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent),
          v3
       && (v4 = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v3)) != 0i64
       && ((v5 = v4->m_Flags, !((v5 >> 14) & 1)) ? ((v5 & 0x8000u) == 0 ? (!((v5 >> 13) & 1) ? (!((v5 >> 12) & 1) ? (v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::RoadSpaceComponent::_TypeUID)) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RoadSpaceComponent::_TypeUID))) : (v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RoadSpaceComponent::_TypeUID))) : (v6 = v4->m_Components.p[24].m_pComponent)) : (v6 = v4->m_Components.p[24].m_pComponent),
           v6)) )
    {
      v7 = v6[26].m_SafePointerList.mNode.mPrev;
    }
    else
    {
      v7 = 0i64;
    }
    if ( v7 )
    {
      if ( *((float *)&v7[3].mPrev + 1) > 50.0 )
      {
        v8 = (UFG::RacePoint *)v7[1].mNext;
        v9 = UFG::RacePoint::GetNextPosition(v8, &result);
        v10 = v9->y;
        v11 = v9->z;
        v1->mDestinationPos.x = v9->x;
        v1->mDestinationPos.y = v10;
        v1->mDestinationPos.z = v11;
        v12 = v8->vDirection.y;
        v13 = v8->vDirection.z;
        v1->mDestinationDir.x = v8->vDirection.x;
        v1->mDestinationDir.y = v12;
        v1->mDestinationDir.z = v13;
        v14 = v1->mActive == 1;
        v1->mDestChanged = 1;
        v1->mUsePlayerSourcePos = 1;
        v1->mActive = 1;
        v1->mChanged |= !v14;
      }
    }
  }
}

// File Line: 1729
// RVA: 0xCE080
void __usercall UFG::UITiledMapGPS::UpdatePlayerPos(UFG::UITiledMapGPS *this@<rcx>, float a2@<xmm0>)
{
  UFG::UITiledMapGPS *v2; // rbx
  unsigned __int16 v3; // dx
  UFG::CharacterSubjectComponent *v4; // rax
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm5_4
  float v8; // xmm6_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-38h]
  UFG::qVector3 dir; // [rsp+30h] [rbp-28h]

  v2 = this;
  if ( UFG::UI::GetPlayerWorldPosition(&pos, &dir) )
  {
    if ( LocalPlayer
      && ((v3 = LocalPlayer->m_Flags, !((v3 >> 14) & 1)) ? ((v3 & 0x8000u) == 0 ? (!((v3 >> 13) & 1) ? (!((v3 >> 12) & 1) ? (v4 = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::CharacterSubjectComponent::_TypeUID)) : (v4 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterSubjectComponent::_TypeUID))) : (v4 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterSubjectComponent::_TypeUID))) : (v4 = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterSubjectComponent::_TypeUID))) : (v4 = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(LocalPlayer)),
          v4) )
    {
      ((void (__fastcall *)(UFG::CharacterSubjectComponent *))v4->vfptr[28].__vecDelDtor)(v4);
    }
    else
    {
      a2 = 0.0;
    }
    v5 = a2 * v2->mGPS_UpdatePeriod;
    if ( v5 <= 1.0 )
    {
      v5 = *(float *)&FLOAT_1_0;
    }
    else
    {
      v6 = FLOAT_5_0;
      if ( v5 >= 5.0 )
      {
LABEL_20:
        v7 = pos.x;
        v8 = pos.y;
        v9 = v2->mSourcePos.x;
        v10 = v2->mSourcePos.y;
        if ( (float)((float)((float)(pos.y - v10) * (float)(pos.y - v10))
                   + (float)((float)(pos.x - v9) * (float)(pos.x - v9))) > (float)(v6 * v6) )
        {
          v11 = v2->mDestinationPos.y - v10;
          v12 = v2->mDestinationPos.x - v9;
          v2->mDestinationDir.z = v2->mDestinationPos.z - v2->mSourcePos.z;
          v13 = pos.z;
          v2->mDestinationDir.y = v11;
          v14 = dir.x;
          v2->mDestinationDir.x = v12;
          v2->mSourcePos.z = v13;
          v15 = dir.y;
          v2->mSourcePos.x = v7;
          v2->mSourcePos.y = v8;
          v2->mSourceDir.x = v14;
          v16 = dir.z;
          v2->mSourceDir.y = v15;
          v2->mSourceDir.z = v16;
          v2->mChanged = 1;
        }
        return;
      }
    }
    v6 = v5;
    goto LABEL_20;
  }
}

// File Line: 1766
// RVA: 0xCE520
void __fastcall UFG::UITiledMapGPS::UpdateTrueDirection(UFG::UITiledMapGPS *this)
{
  UFG::UITiledMapGPS *v1; // rbp
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rax
  __int16 v4; // ax
  unsigned int v5; // er8
  signed __int64 v6; // rbx
  unsigned int v7; // er13
  unsigned int v8; // ecx
  unsigned __int16 *v9; // rdx
  unsigned int v10; // esi
  UFG::RoadNetworkResource *v11; // rax
  UFG::RoadNetworkResource *v12; // rdi
  unsigned int v13; // eax
  unsigned __int16 *v14; // r12
  UFG::RoadNetworkSegment *v15; // r14
  UFG::RoadNetworkSegment *v16; // rsi
  UFG::RoadNetworkGate *v17; // rbx
  UFG::RoadNetworkGate *v18; // rdi
  UFG::RoadNetworkLane *v19; // r15
  UFG::RoadNetworkLane *v20; // rax
  UFG::RoadNetworkLane *v21; // rbx
  bool v22; // di
  UFG::BaseCameraComponent *v23; // rax
  signed __int64 v24; // rax
  int v25; // xmm6_4
  int v26; // xmm7_4
  UFG::RoadNetworkNode *v27; // rcx
  float v28; // xmm4_4
  __m128 v29; // xmm5
  __m128 v30; // xmm1
  float v31; // xmm2_4
  float v32; // xmm5_4
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm3_4
  float v37; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-D8h]
  unsigned int v39; // [rsp+100h] [rbp+8h]
  unsigned int v40; // [rsp+108h] [rbp+10h]
  unsigned int v41; // [rsp+110h] [rbp+18h]
  UFG::RoadNetworkResource *v42; // [rsp+118h] [rbp+20h]

  v1 = this;
  v40 = this->mTrueDirectionEdgeCount;
  this->mTrueDirectionIntersectionLane = 0i64;
  this->mTrueDirectionHighwayRamp = 0;
  this->mTrueDirectionEdgeCount = 0;
  if ( !this->mActive || this->mInteriorActive || this->mOnlyShowInVehicles && !UFG::UI::IsPlayerInVehicle() )
    return;
  if ( UFG::UI::IsPlayerInWater()
    || !v1->mVisible
    || !UFG::WheeledVehicleManager::IsTrueDirectionUpdateEnabled(UFG::WheeledVehicleManager::m_Instance)
    || 0 == v1->mWayFinderClient.m_NumWayEdges
    || !LocalPlayer )
  {
    return;
  }
  v2 = LocalPlayer->m_Flags;
  if ( (v2 >> 14) & 1 )
  {
    v3 = LocalPlayer->m_Components.p[44].m_pComponent;
  }
  else if ( (v2 & 0x8000u) == 0 )
  {
    if ( (v2 >> 13) & 1 )
      v3 = UFG::SimObjectGame::GetComponentOfTypeHK(
             (UFG::SimObjectGame *)&LocalPlayer->vfptr,
             UFG::CharacterOccupantComponent::_TypeUID);
    else
      v3 = (v2 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                              UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                             (UFG::SimObject *)&LocalPlayer->vfptr,
                                                                             UFG::CharacterOccupantComponent::_TypeUID);
  }
  else
  {
    v3 = UFG::SimObjectGame::GetComponentOfTypeHK(
           (UFG::SimObjectGame *)&LocalPlayer->vfptr,
           UFG::CharacterOccupantComponent::_TypeUID);
  }
  if ( !v3
    || LODWORD(v3[1].m_SafePointerList.mNode.mNext) != 4
    || !UFG::WheeledVehicleManager::m_Instance->m_NavigationData->m_RoadNetworkGraph.pWayfindingList )
  {
    return;
  }
  v4 = ((__int64 (__fastcall *)(UFG::MiniMapWayFinderClient *))v1->mWayFinderClient.vfptr->GetWayEdge)(&v1->mWayFinderClient);
  v5 = v1->mWayFinderClient.m_NumWayEdges;
  v6 = (signed __int64)v1->mWayFinderClient.m_WayEdges;
  v7 = 0;
  v8 = 0;
  if ( v1->mWayFinderClient.m_NumWayEdges )
  {
    v9 = v1->mWayFinderClient.m_WayEdges;
    while ( *v9 != v4 )
    {
      ++v8;
      ++v9;
      if ( v8 >= v5 )
        goto LABEL_28;
    }
    v7 = v8;
  }
LABEL_28:
  v10 = v5 - 1;
  v41 = v5 - 1;
  if ( v7 == v5 - 1 )
    return;
  v11 = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  v12 = v11;
  v42 = v11;
  v13 = 0;
  if ( v7 >= v10 )
    return;
  v14 = (unsigned __int16 *)(v6 + 2i64 * v7);
  while ( 1 )
  {
    v39 = v13 + 1;
    ++v7;
    v15 = UFG::RoadNetworkResource::GetSegment(v12, *v14);
    v16 = UFG::RoadNetworkResource::GetSegment(v12, *(unsigned __int16 *)(v6 + 2i64 * v7));
    if ( UFG::RoadNetworkNode::IsConnectedToNode(
           (UFG::RoadNetworkNode *)&v15->mType,
           (UFG::RoadNetworkNode *)&v16->mType) )
    {
      v13 = v39;
      goto LABEL_59;
    }
    v17 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v15, 0);
    v18 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v15, 1u);
    v19 = UFG::RoadNetworkGate::GetAnyLaneLeadingToNode(v17, (UFG::RoadNetworkNode *)&v16->mType);
    v20 = UFG::RoadNetworkGate::GetAnyLaneLeadingToNode(v18, (UFG::RoadNetworkNode *)&v16->mType);
    v21 = v20;
    if ( !v19 && !v20 )
      return;
    v22 = (*(_DWORD *)&v15->mBits >> 1) & 1 && (*(_DWORD *)&v16->mBits >> 1) & 1;
    if ( v19 )
      v21 = v19;
    if ( v16->mPropertyID1 == 650 )
      break;
    UFG::Director::Get();
    v23 = UFG::Director::Get()->mCurrentCamera;
    if ( v23 )
      v24 = (signed __int64)&v23->mCamera;
    else
      v24 = 0i64;
    v25 = *(_DWORD *)(v24 + 160) ^ _xmm[0];
    v26 = *(_DWORD *)(v24 + 164) ^ _xmm[0];
    v27 = (UFG::RoadNetworkNode *)((char *)v21 + v21->mNode.mOffset);
    if ( !v21->mNode.mOffset )
      v27 = 0i64;
    UFG::RoadNetworkNode::GetTangent(v27, &result, v21->mLaneIndex, 1.0);
    result.z = 0.0;
    v28 = (float)(*(float *)&v26 * *(float *)&v26) + (float)(*(float *)&v25 * *(float *)&v25);
    if ( v28 < 0.0000010000001
      || (v29 = (__m128)LODWORD(result.x),
          v30 = v29,
          v30.m128_f32[0] = (float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(result.y * result.y),
          v30.m128_f32[0] < 0.0000010000001) )
    {
      v13 = v39;
    }
    else
    {
      if ( v30.m128_f32[0] == 0.0 )
        v31 = 0.0;
      else
        v31 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v30));
      v32 = result.x * v31;
      v33 = result.y * v31;
      v34 = v31 * 0.0;
      if ( v28 == 0.0 )
        v35 = 0.0;
      else
        v35 = 1.0 / fsqrt(v28);
      v13 = v39;
      LODWORD(v36) = COERCE_UNSIGNED_INT(
                       (float)((float)(v33 * (float)(*(float *)&v26 * v35))
                             + (float)(v32 * (float)(*(float *)&v25 * v35)))
                     + (float)((float)(v35 * 0.0) * v34)) & _xmm;
      if ( v40 <= v39 )
        v37 = FLOAT_0_72999996;
      else
        v37 = FLOAT_0_70999998;
      if ( v36 < v37 )
        goto LABEL_64;
    }
    v12 = v42;
    v6 = (signed __int64)v1->mWayFinderClient.m_WayEdges;
LABEL_59:
    ++v14;
    if ( v7 >= v41 )
      return;
  }
  v13 = v39;
  v1->mTrueDirectionHighwayRamp = 1;
LABEL_64:
  v1->mTrueDirectionEdgeCount = v13;
  if ( !v22 )
    v1->mTrueDirectionIntersectionLane = v21;
}

// File Line: 1923
// RVA: 0xC5E30
bool __fastcall UFG::UITiledMapGPS::IsVisible(UFG::UITiledMapGPS *this)
{
  UFG::UITiledMapGPS *v1; // rbx
  bool result; // al

  v1 = this;
  if ( !this->mActive
    || this->mInteriorActive
    || this->mOnlyShowInVehicles && !UFG::UI::IsPlayerInVehicle()
    || UFG::UI::IsPlayerInWater() )
  {
    result = 0;
  }
  else
  {
    result = v1->mVisible;
  }
  return result;
}

// File Line: 1937
// RVA: 0xCB8E0
void __fastcall UFG::UITiledMapGPS::SetWayfinderIgnoreAlleys(UFG::UITiledMapGPS *this, bool ignore)
{
  this->mWayFinderClient.m_RestrictedMode = ignore;
}

// File Line: 1949
// RVA: 0xC4B20
void __fastcall UFG::UITiledMapGPS::HandleArrivedAtManualMapDestination(UFG::UITiledMapGPS *this)
{
  bool v1; // zf

  v1 = this->mActive == 0;
  this->mActive = 0;
  this->mChanged |= !v1;
  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    UFG::UIHKPlayerObjectiveManager::ClearWorldMapDest(UFG::UIHKPlayerObjectiveManager::mInstance);
  UFG::UIHKObjectiveDistanceWidget::Clear(UFG::UIHKScreenHud::ObjectiveDistance);
}

