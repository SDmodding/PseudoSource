// File Line: 66
// RVA: 0xBCEA0
void __fastcall UFG::UITiledMapGPS::UITiledMapGPS(UFG::UITiledMapGPS *this)
{
  UFG::MiniMapWayFinderClient *p_mWayFinderClient; // rbx

  p_mWayFinderClient = &this->mWayFinderClient;
  UFG::WayFinderClient::WayFinderClient(&this->mWayFinderClient);
  p_mWayFinderClient->vfptr = (UFG::WayFinderClientVtbl *)&UFG::MiniMapWayFinderClient::`vftable;
  p_mWayFinderClient->m_LastLaneIndex = -1;
  *(_WORD *)&p_mWayFinderClient->m_AllowFootPaths = 1;
  p_mWayFinderClient->m_LaneFlags = 64;
  this->mSplinePoints.p = 0i64;
  *(_QWORD *)&this->mSplinePoints.size = 0i64;
  this->mTrackingTarget.mPrev = &this->mTrackingTarget;
  this->mTrackingTarget.mNext = &this->mTrackingTarget;
  this->mTrackingTarget.m_pPointer = 0i64;
  this->mUpdateTimer = 0.0;
  *(_DWORD *)&this->mChanged = 16777473;
  *(_DWORD *)&this->mInVehicle = 256;
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
  float mGPS_UpdatePeriod; // eax

  mGPS_UpdatePeriod = this->mGPS_UpdatePeriod;
  this->mChanged = 1;
  this->mUpdateTimer = mGPS_UpdatePeriod;
}

// File Line: 152
// RVA: 0xCC6A0
void __fastcall UFG::UITiledMapGPS::Update(
        UFG::UITiledMapGPS *this,
        float elapsed,
        UFG::UIScreen *screen,
        UFG::UITiledMapMath *geo)
{
  UFG::HudComponent *m_pPointer; // rcx
  float y; // xmm3_4
  float z; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm2_4
  hkgpIndexedMesh::EdgeBarrier *v12; // rdi
  int v13; // edx
  int v14; // r8d
  hkgpIndexedMeshDefinitions::Edge *v15; // rdx
  bool IsPlayerInVehicle; // al
  char v17; // di
  bool v18; // si
  float v19; // xmm6_4
  bool v20; // zf
  unsigned int mMaxNumSplinePoints; // edx
  UFG::qVector3 pos; // [rsp+20h] [rbp-28h] BYREF

  if ( screen )
  {
    UFG::UITiledMapGPS::UpdateRace(this);
    m_pPointer = (UFG::HudComponent *)this->mTrackingTarget.m_pPointer;
    if ( m_pPointer )
    {
      pos = UFG::qVector3::msZero;
      if ( UFG::HudComponent::GetWorldPosition(m_pPointer, &pos) )
      {
        y = pos.y;
        if ( (float)((float)((float)(this->mDestinationPos.y - pos.y) * (float)(this->mDestinationPos.y - pos.y))
                   + (float)((float)(this->mDestinationPos.x - pos.x) * (float)(this->mDestinationPos.x - pos.x))) > 25.0 )
        {
          this->mDestinationPos.x = pos.x;
          z = pos.z;
          this->mDestinationPos.z = pos.z;
          this->mDestinationPos.y = y;
          v9 = this->mDestinationPos.x - this->mSourcePos.x;
          v10 = y - this->mSourcePos.y;
          v11 = z - this->mSourcePos.z;
          this->mDestinationDir.x = v9;
          this->mDestinationDir.y = v10;
          this->mDestinationDir.z = v11;
          LODWORD(this->mSourceDir.x) = LODWORD(v9) ^ _xmm[0];
          LODWORD(this->mSourceDir.y) = LODWORD(v10) ^ _xmm[0];
          LODWORD(this->mSourceDir.z) = LODWORD(v11) ^ _xmm[0];
          *(_WORD *)&this->mChanged = 257;
        }
      }
    }
    if ( this->mUsePlayerSourcePos )
    {
      UFG::UITiledMapGPS::UpdatePlayerPos(this);
      v12 = (hkgpIndexedMesh::EdgeBarrier *)UFG::WheeledVehicleManager::m_Instance;
      if ( Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
             (hkGeometryUtils::IVertices *)UFG::WheeledVehicleManager::m_Instance,
             v13,
             v14)
        || Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(v12, v15) )
      {
        UFG::UITiledMapGPS::UpdateTrueDirection(this);
      }
      if ( !this->mTrackingTarget.m_pPointer
        && this->mIsManualMapDest
        && (float)((float)((float)(this->mDestinationPos.y - this->mSourcePos.y)
                         * (float)(this->mDestinationPos.y - this->mSourcePos.y))
                 + (float)((float)(this->mDestinationPos.x - this->mSourcePos.x)
                         * (float)(this->mDestinationPos.x - this->mSourcePos.x))) < 400.0 )
      {
        UFG::UITiledMapGPS::HandleArrivedAtManualMapDestination(this);
      }
    }
    IsPlayerInVehicle = UFG::UI::IsPlayerInVehicle();
    v17 = IsPlayerInVehicle ^ this->mInVehicle;
    v18 = IsPlayerInVehicle;
    if ( v17 )
    {
      this->mWayFinderClient.vfptr->ResetWay(&this->mWayFinderClient);
      this->mWayFinderClient.m_AllowFootPaths = 1;
    }
    this->mChanged |= v17;
    v19 = elapsed + this->mUpdateTimer;
    this->mInVehicle = v18;
    this->mUpdateTimer = v19;
    this->mWayFinderClient.m_AllowFootPaths = !v18;
    if ( v19 >= this->mGPS_UpdatePeriod )
    {
      v20 = !this->mChanged;
      this->mUpdateTimer = 0.0;
      if ( !v20 )
      {
        mMaxNumSplinePoints = this->mMaxNumSplinePoints;
        if ( this->mSplinePoints.size != mMaxNumSplinePoints && mMaxNumSplinePoints > this->mSplinePoints.capacity )
          UFG::qArray<UFG::qVector3,0>::Reallocate(&this->mSplinePoints, mMaxNumSplinePoints, "mMaxNumSplinePoints");
        UFG::UITiledMapGPS::DoGenerateSpline(this);
        *(_WORD *)&this->mChanged = 0;
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
  float y; // xmm0_4
  float z; // xmm1_4
  UFG::qSafePointer<UFG::SimComponent,UFG::HudComponent> *p_mTrackingTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::WayFinderClientVtbl *vfptr; // rax
  bool v10; // zf
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm1_4

  if ( (float)((float)((float)(this->mDestinationPos.y - dest->y) * (float)(this->mDestinationPos.y - dest->y))
             + (float)((float)(this->mDestinationPos.x - dest->x) * (float)(this->mDestinationPos.x - dest->x))) >= 1.0 )
  {
    this->mChanged = 1;
    this->mNoDestination = 0;
    y = dest->y;
    z = dest->z;
    this->mDestinationPos.x = dest->x;
    p_mTrackingTarget = &this->mTrackingTarget;
    this->mDestinationPos.y = y;
    this->mDestinationPos.z = z;
    this->mDestChanged = 1;
    if ( this->mTrackingTarget.m_pPointer )
    {
      mPrev = p_mTrackingTarget->mPrev;
      mNext = p_mTrackingTarget->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mTrackingTarget->mPrev = p_mTrackingTarget;
      p_mTrackingTarget->mNext = p_mTrackingTarget;
    }
    p_mTrackingTarget->m_pPointer = 0i64;
    vfptr = this->mWayFinderClient.vfptr;
    this->mIsManualMapDest = isManualMapDest;
    vfptr->ResetWay(&this->mWayFinderClient);
    v10 = !this->mUsePlayerSourcePos;
    v11 = this->mGPS_UpdatePeriod + this->mUpdateTimer;
    this->mWayFinderClient.m_AllowFootPaths = 1;
    this->mUpdateTimer = v11;
    if ( v10 )
    {
      v12 = this->mDestinationPos.x - this->mSourcePos.x;
      v13 = this->mDestinationPos.y - this->mSourcePos.y;
      v14 = this->mDestinationPos.z - this->mSourcePos.z;
      this->mDestinationDir.x = v12;
      this->mDestinationDir.y = v13;
      this->mDestinationDir.z = v14;
      LODWORD(this->mSourceDir.x) = LODWORD(v12) ^ _xmm[0];
      LODWORD(this->mSourceDir.y) = LODWORD(v13) ^ _xmm[0];
      LODWORD(this->mSourceDir.z) = LODWORD(v14) ^ _xmm[0];
    }
  }
}

// File Line: 352
// RVA: 0xCB7A0
void __fastcall UFG::UITiledMapGPS::SetTrackingTarget(UFG::UITiledMapGPS *this, UFG::HudComponent *target)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::HudComponent> *p_mTrackingTarget; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax

  p_mTrackingTarget = &this->mTrackingTarget;
  if ( this->mTrackingTarget.m_pPointer )
  {
    mPrev = p_mTrackingTarget->mPrev;
    mNext = p_mTrackingTarget->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mTrackingTarget->mPrev = p_mTrackingTarget;
    p_mTrackingTarget->mNext = p_mTrackingTarget;
  }
  p_mTrackingTarget->m_pPointer = target;
  if ( target )
  {
    v5 = target->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v5->mNext = p_mTrackingTarget;
    p_mTrackingTarget->mPrev = v5;
    p_mTrackingTarget->mNext = &target->m_SafePointerList.mNode;
    target->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mTrackingTarget;
  }
}

// File Line: 408
// RVA: 0xC66A0
void __fastcall UFG::UITiledMapGPS::PopulateWorldMap(UFG::UITiledMapGPS *this, UFG::UITiledMapGPS *clone)
{
  float y; // xmm0_4
  float z; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float x; // eax
  float v11; // xmm1_4
  bool v12; // al

  y = this->mSourcePos.y;
  z = this->mSourcePos.z;
  clone->mSourcePos.x = this->mSourcePos.x;
  clone->mSourcePos.y = y;
  clone->mSourcePos.z = z;
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
  x = this->mDestinationDir.x;
  v11 = this->mDestinationDir.z;
  clone->mDestinationDir.y = this->mDestinationDir.y;
  clone->mDestinationDir.x = x;
  clone->mDestinationDir.z = v11;
  *(_WORD *)&clone->mChanged = 257;
  clone->mActive = this->mActive;
  clone->mInVehicle = this->mInVehicle;
  clone->mNoDestination = this->mNoDestination;
  clone->mUsePlayerSourcePos = this->mUsePlayerSourcePos;
  v12 = this->mVisible && this->mActive;
  clone->mVisible = v12;
  clone->mWayFinderClient.vfptr->ResetWay(&clone->mWayFinderClient);
  clone->mWayFinderClient.m_AllowFootPaths = 1;
  clone->mWayFinderClient.m_AllowFootPaths = this->mWayFinderClient.m_AllowFootPaths;
  clone->mWayFinderClient.m_RestrictedMode = this->mWayFinderClient.m_RestrictedMode;
  clone->mWayFinderClient.m_LaneFlags = this->mWayFinderClient.m_LaneFlags;
}

// File Line: 431
// RVA: 0xC44C0
float __fastcall UFG::UITiledMapGPS::GetPathLength(UFG::UITiledMapGPS *this)
{
  unsigned __int16 *m_WayEdges; // r15
  float v2; // xmm7_4
  float v4; // xmm6_4
  float v5; // xmm0_4
  unsigned int m_NumWayEdges; // esi
  UFG::RoadNetworkResource *RoadNetwork; // rax
  UFG::RoadNetworkResource *v8; // r12
  __int64 m_CurrEdgeIndex; // rbp
  unsigned __int16 *v10; // r13
  UFG::RoadNetworkSegment *Segment; // rax
  UFG::RoadNetworkLane *CenterLane; // rax
  UFG::WayFinderClientVtbl *vfptr; // r8
  UFG::RoadNetworkLane *v14; // rbx
  UFG::qVector3 *v15; // rax
  __int64 v16; // r14
  UFG::RoadNetworkSegment *v17; // rax
  float y; // xmm1_4
  UFG::RoadNetworkNode *v19; // rbx
  __m128 z_low; // xmm0
  UFG::RoadNetworkLane *v21; // rax
  UFG::RoadNetworkLane *v22; // rbx
  float Length; // xmm0_4
  int v24; // ebx
  unsigned int v25; // edi
  UFG::RoadNetworkSegment *v26; // rax
  UFG::RoadNetworkGate *v27; // rbp
  UFG::RoadNetworkLane *v28; // r14
  char v29; // si
  unsigned int v30; // ebx
  UFG::RoadNetworkGate *IncomingConnection; // r15
  UFG::RoadNetworkConnection *v32; // rax
  __int64 mOffset; // rcx
  UFG::RoadNetworkConnection *v34; // rdx
  char *v35; // rcx
  __int64 v36; // rax
  char *v37; // rax
  char IsReversedInNode; // bl
  float v39; // xmm1_4
  unsigned int v40; // ebx
  UFG::RoadNetworkSegment *v41; // r14
  UFG::RoadNetworkGate *v42; // r15
  UFG::RoadNetworkGate *v43; // rsi
  __int64 v44; // rax
  char *v45; // rcx
  __int64 v46; // rax
  char *v47; // rax
  UFG::RoadNetworkLane *AnyLaneLeadingToNode; // rbx
  UFG::RoadNetworkLane *v49; // rax
  UFG::RoadNetworkLane *v50; // rcx
  char v51; // si
  unsigned int v52; // ebx
  UFG::RoadNetworkSegment *v53; // r15
  UFG::RoadNetworkConnection *v54; // rdi
  UFG::RoadNetworkConnection *v55; // rax
  UFG::RoadNetworkGate *v56; // r8
  __int64 v57; // rcx
  char *v58; // rcx
  __int64 v59; // rax
  char *v60; // rax
  char v61; // bl
  float v62; // xmm1_4
  unsigned __int16 *v63; // [rsp+20h] [rbp-C8h]
  UFG::RoadNetworkNode *targetNode; // [rsp+28h] [rbp-C0h] BYREF
  UFG::qVector3 pos; // [rsp+38h] [rbp-B0h] BYREF
  UFG::qVector3 v66; // [rsp+48h] [rbp-A0h] BYREF
  UFG::qVector3 result; // [rsp+58h] [rbp-90h] BYREF
  int v68; // [rsp+F0h] [rbp+8h]
  unsigned int v69; // [rsp+F8h] [rbp+10h]
  float laneT; // [rsp+100h] [rbp+18h] BYREF
  float v71; // [rsp+108h] [rbp+20h] BYREF

  m_WayEdges = this->mWayFinderClient.m_WayEdges;
  v2 = 0.0;
  v63 = this->mWayFinderClient.m_WayEdges;
  v4 = 0.0;
  if ( this == (UFG::UITiledMapGPS *)-110i64 )
    return 0.0;
  m_NumWayEdges = this->mWayFinderClient.m_NumWayEdges;
  v69 = m_NumWayEdges;
  if ( !this->mWayFinderClient.m_NumWayEdges )
    return 0.0;
  RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  v8 = RoadNetwork;
  if ( !RoadNetwork )
    return 0.0;
  m_CurrEdgeIndex = this->mWayFinderClient.m_CurrEdgeIndex;
  v10 = &m_WayEdges[m_CurrEdgeIndex];
  v68 = this->mWayFinderClient.m_CurrEdgeIndex;
  Segment = UFG::RoadNetworkResource::GetSegment(RoadNetwork, *v10);
  CenterLane = UFG::RoadNetworkNode::GetCenterLane(Segment);
  vfptr = this->mWayFinderClient.vfptr;
  v14 = CenterLane;
  laneT = 0.0;
  v15 = vfptr->GetPosition(&this->mWayFinderClient, (UFG::qVector3 *)&targetNode);
  UFG::RoadNetworkLane::GetNearestPoint(v14, &result, v15, &laneT);
  v16 = m_NumWayEdges - 1;
  v17 = UFG::RoadNetworkResource::GetSegment(v8, m_WayEdges[v16]);
  y = this->mDestinationPos.y;
  pos.x = this->mDestinationPos.x;
  pos.y = y;
  v19 = v17;
  pos.z = 0.0;
  UFG::RoadNetworkNode::GetClosestPosition(v17, &v66, &pos, 0i64);
  z_low = (__m128)LODWORD(v66.z);
  pos.z = v66.z;
  v21 = UFG::RoadNetworkNode::GetCenterLane(v19);
  v71 = 0.0;
  v22 = v21;
  UFG::RoadNetworkLane::GetNearestPoint(v21, &result, &pos, &v71);
  if ( (_DWORD)m_CurrEdgeIndex == (_DWORD)v16 )
  {
    Length = UFG::RoadNetworkLane::GetLength(v22);
    LODWORD(v5) = COERCE_UNSIGNED_INT((float)(Length * v71) - (float)(Length * laneT)) & _xmm;
    return v5;
  }
  v24 = m_CurrEdgeIndex;
  v25 = m_CurrEdgeIndex;
  if ( (unsigned int)m_CurrEdgeIndex >= m_NumWayEdges )
    return v4;
  while ( 1 )
  {
    v26 = UFG::RoadNetworkResource::GetSegment(v8, *v10);
    v27 = (UFG::RoadNetworkGate *)v26;
    if ( !v26 )
      goto LABEL_43;
    v28 = UFG::RoadNetworkNode::GetCenterLane(v26);
    if ( !v28 )
      goto LABEL_43;
    if ( v25 == m_NumWayEdges - 1 )
      break;
    if ( v25 == v24 )
    {
      v29 = 1;
      v30 = m_WayEdges[v25 + 1];
      targetNode = UFG::RoadNetworkResource::GetSegment(v8, v30);
      IncomingConnection = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(v27, 0);
      v32 = UFG::RoadNetworkGate::GetIncomingConnection(v27, 1u);
      mOffset = IncomingConnection->mConnectedNode.mOffset;
      v34 = v32;
      if ( mOffset
        && (v35 = (char *)&IncomingConnection->mConnectedNode + mOffset) != 0i64
        && !*(_WORD *)v35
        && *((_DWORD *)v35 + 6) == v30 )
      {
        v29 = 0;
      }
      else
      {
        v36 = v32->mLaneList.mOffset;
        if ( !v36 || (v37 = (char *)&v34->mLaneList + v36) == 0i64 || *(_WORD *)v37 || *((_DWORD *)v37 + 6) != v30 )
          v29 = UFG::RoadNetworkGate::GetAnyLaneLeadingToNode(IncomingConnection, targetNode) == 0i64;
      }
      IsReversedInNode = UFG::RoadNetworkLane::IsReversedInNode(v28);
      z_low.m128_f32[0] = UFG::RoadNetworkLane::GetLength(v28);
      v39 = z_low.m128_f32[0] * laneT;
      if ( IsReversedInNode == v29 )
        z_low = 0i64;
      m_WayEdges = v63;
      m_NumWayEdges = v69;
      z_low.m128_f32[0] = z_low.m128_f32[0] - v39;
      z_low = _mm_and_ps(z_low, (__m128)(unsigned int)_xmm);
    }
    else
    {
      z_low.m128_f32[0] = UFG::RoadNetworkLane::GetLength(v28);
    }
    v4 = v4 + z_low.m128_f32[0];
    v40 = m_WayEdges[v25 + 1];
    v41 = UFG::RoadNetworkResource::GetSegment(v8, v40);
    if ( !v41 )
      goto LABEL_42;
    v42 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(v27, 0);
    v43 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(v27, 1u);
    v44 = v42->mConnectedNode.mOffset;
    if ( !v44 || (v45 = (char *)&v42->mConnectedNode + v44) == 0i64 || *(_WORD *)v45 || *((_DWORD *)v45 + 6) != v40 )
    {
      v46 = v43->mConnectedNode.mOffset;
      if ( !v46 || (v47 = (char *)&v43->mConnectedNode + v46) == 0i64 || *(_WORD *)v47 || *((_DWORD *)v47 + 6) != v40 )
      {
        AnyLaneLeadingToNode = UFG::RoadNetworkGate::GetAnyLaneLeadingToNode(v42, v41);
        v49 = UFG::RoadNetworkGate::GetAnyLaneLeadingToNode(v43, v41);
        if ( AnyLaneLeadingToNode )
        {
          v50 = AnyLaneLeadingToNode;
          goto LABEL_40;
        }
        if ( v49 )
        {
          v50 = v49;
LABEL_40:
          v4 = v4 + UFG::RoadNetworkLane::GetLength(v50);
        }
      }
    }
    m_NumWayEdges = v69;
    m_WayEdges = v63;
LABEL_42:
    v24 = v68;
LABEL_43:
    ++v25;
    ++v10;
    if ( v25 >= m_NumWayEdges )
      return v4;
  }
  v51 = 1;
  v52 = m_WayEdges[v25 - 1];
  v53 = UFG::RoadNetworkResource::GetSegment(v8, v52);
  v54 = UFG::RoadNetworkGate::GetIncomingConnection(v27, 0);
  v55 = UFG::RoadNetworkGate::GetIncomingConnection(v27, 1u);
  v56 = (UFG::RoadNetworkGate *)v55;
  v57 = v55->mLaneList.mOffset;
  if ( v57 && (v58 = (char *)&v55->mLaneList + v57) != 0i64 && !*(_WORD *)v58 && *((_DWORD *)v58 + 6) == v52 )
  {
    v51 = 0;
  }
  else
  {
    v59 = v54->mLaneList.mOffset;
    if ( !v59 || (v60 = (char *)&v54->mLaneList + v59) == 0i64 || *(_WORD *)v60 || *((_DWORD *)v60 + 6) != v52 )
      v51 = UFG::RoadNetworkGate::GetAnyLaneLeadingHereFromNode(v56, v53) == 0i64;
  }
  v61 = UFG::RoadNetworkLane::IsReversedInNode(v28);
  v62 = UFG::RoadNetworkLane::GetLength(v28);
  if ( v61 == v51 )
    v2 = v62;
  return COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v62 * v71) - v2) & _xmm) + v4;
};
  }
  v61 = UFG::RoadNetworkLane::IsReversedInNode(v28);
  v62 = UFG::RoadNetworkLane::GetLength(v28);
  if ( v61 == v51 )
    v2 = v62;
  return COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v62 * v71) - v2) & _xmm) + v4

// File Line: 618
// RVA: 0xC0CE0
float __fastcall UFG::UITiledMapGPS::GetApproxAltitude(UFG::qVector3 *pos)
{
  UFG::RoadNetworkResource *RoadNetwork; // rax
  UFG::RoadNetworkNode *ClosestNode; // rax
  UFG::RoadNetworkLane *Lane; // rax
  UFG::RoadNetworkLane *v6; // rbx
  UFG::qVector3 v7; // [rsp+30h] [rbp-28h] BYREF
  UFG::qVector3 result; // [rsp+40h] [rbp-18h] BYREF

  RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  if ( !RoadNetwork )
    return 0.0;
  ClosestNode = UFG::RoadNetworkResource::GetClosestNode(RoadNetwork, pos, 0, 0i64, 0i64);
  if ( !ClosestNode )
    return 0.0;
  Lane = UFG::RoadNetworkNode::GetLane(ClosestNode, (unsigned __int8)ClosestNode->mNumLanes >> 1);
  v6 = Lane;
  if ( !Lane )
    return 0.0;
  UFG::RoadNetworkLane::GetPos(Lane, &result, 0.0);
  UFG::RoadNetworkLane::GetPos(v6, &v7, 1.0);
  return (float)(v7.z + result.z) * 0.5;
}

// File Line: 826
// RVA: 0xBE6B0
bool __fastcall UFG::MiniMapWayFinderClient::CanGo(
        UFG::MiniMapWayFinderClient *this,
        UFG::RoadNetworkGraph *graph,
        unsigned __int16 from_edge,
        unsigned __int16 to_edge,
        unsigned __int16 thru_node)
{
  bool result; // al
  unsigned __int16 v10; // bp
  UFG::RoadNetworkResource *pRoadNetworkResource; // r15
  UFG::RoadNetworkSegment *Segment; // rdi
  UFG::RoadNetworkSegment *v13; // rax

  if ( graph->vfptr->IsEdge(graph, thru_node) )
    return 1;
  v10 = this->vfptr->GetWayEdge(this, graph);
  if ( to_edge == v10 )
    return 1;
  pRoadNetworkResource = graph->pRoadNetworkResource;
  Segment = UFG::RoadNetworkResource::GetSegment(pRoadNetworkResource, to_edge);
  result = (*(_BYTE *)&Segment->mBits & 1) == 0
        && ((v13 = UFG::RoadNetworkResource::GetSegment(pRoadNetworkResource, v10), this->m_AllowFootPaths)
         || (*(_DWORD *)&v13->mBits & 2) != 0
         || (*(_DWORD *)&Segment->mBits & 2) == 0)
        && (!this->m_RestrictedMode || (*(_DWORD *)&Segment->mBits & 4) == 0)
        && UFG::RoadNetworkGraph::GetNumLanesFromToThru(
             graph,
             from_edge,
             to_edge,
             thru_node,
             (unsigned __int8)this->m_LaneFlags) > 0;
  return result;
}

// File Line: 863
// RVA: 0xC0F40
float __fastcall UFG::MiniMapWayFinderClient::GetEdgeLength(
        UFG::MiniMapWayFinderClient *this,
        UFG::WayGraph *wayGraph,
        unsigned __int16 wayEdge)
{
  UFG::RoadNetworkSegment *Segment; // rbx
  UFG::RoadNetworkLane *Lane; // rax
  float result; // xmm0_4
  UFG::RoadNetworkSegment::RoadSegmentBits mBits; // ecx

  Segment = UFG::RoadNetworkResource::GetSegment((UFG::RoadNetworkResource *)wayGraph[3].vfptr, wayEdge);
  Lane = UFG::RoadNetworkNode::GetLane(Segment, 0);
  result = UFG::RoadNetworkLane::GetLength(Lane);
  mBits = Segment->mBits;
  if ( (*(_BYTE *)&mBits & 4) != 0 )
    result = result * UFG::UITiledMapTweakables::GPS_RestrictedEdgeWeight;
  if ( (*(_BYTE *)&mBits & 2) != 0 && result <= (float)(UFG::UITiledMapTweakables::GPS_NoVehicleEdgeWeight * result) )
    return UFG::UITiledMapTweakables::GPS_NoVehicleEdgeWeight * result;
  return result;
}

// File Line: 880
// RVA: 0xCA410
void __fastcall UFG::MiniMapWayFinderClient::ResetWay(UFG::MiniMapWayFinderClient *this)
{
  UFG::WayFinderClient::ResetWay(this);
  this->m_LastLaneIndex = -1;
}

// File Line: 915
// RVA: 0xBEEF0
void __fastcall UFG::UITiledMapGPS::DoGenerateSpline(UFG::UITiledMapGPS *this)
{
  UFG::RoadNetworkLane *v1; // r12
  UFG::UITiledMapGPS *v2; // r14
  UFG::RoadNetworkResource *RoadNetwork; // r13
  UFG::WheeledVehicleNavigationData *m_NavigationData; // rsi
  unsigned __int16 v5; // ax
  UFG::WayFinderClientVtbl *vfptr; // r10
  unsigned __int16 v7; // bx
  bool v8; // al
  UFG::RoadNetworkSegment *ClosestSegment; // rax
  UFG::WayFinder *WayFinder; // rax
  UFG::WayFinder *v11; // rax
  unsigned int m_NumWayEdges; // ebx
  unsigned __int16 *v13; // rdi
  unsigned int v14; // ebx
  UFG::RoadNetworkSegment *Segment; // rax
  float y; // xmm1_4
  UFG::RoadNetworkSegment *v17; // rsi
  unsigned int v18; // r14d
  unsigned int CenterLaneIndex; // eax
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
  __int64 v31; // rcx
  unsigned int size; // eax
  UFG::RoadNetworkSegment *v33; // rax
  UFG::RoadNetworkSegment *v34; // r13
  UFG::RoadNetworkLane *CenterLane; // rdi
  bool v36; // bl
  unsigned int v37; // esi
  UFG::RoadNetworkSegment *v38; // r15
  UFG::RoadNetworkConnection *v39; // r14
  UFG::RoadNetworkConnection *v40; // rax
  UFG::RoadNetworkGate *v41; // r8
  __int64 v42; // rcx
  char *v43; // rcx
  __int64 v44; // rax
  char *v45; // rax
  unsigned int mNumLanes; // r15d
  UFG::RoadNetworkLane *v47; // r14
  unsigned int v48; // ebx
  UFG::RoadNetworkLane *Lane; // rsi
  unsigned int i; // ebx
  UFG::RoadNetworkLane *v51; // rsi
  UFG::RoadNetworkSegment *v52; // rsi
  UFG::RoadNetworkGate *IncomingConnection; // rbx
  UFG::RoadNetworkGate *v54; // r14
  UFG::RoadNetworkLane **v55; // rdx
  __int64 v56; // r8
  UFG::RoadNetworkLane *v57; // rcx
  char v58; // r13
  UFG::RoadNetworkLane **v59; // rdx
  __int64 v60; // r8
  UFG::RoadNetworkLane *v61; // rcx
  __int64 mOffset; // rax
  UFG::RoadNetworkConnection *v63; // rcx
  __int64 v64; // rax
  UFG::qOffset64<UFG::RoadNetworkGate *> *v65; // rax
  char *v66; // rdx
  float v67; // xmm2_4
  UFG::RoadNetworkSegment *v68; // r14
  __int64 v69; // rcx
  UFG::RoadNetworkConnection *v70; // rsi
  __int64 v71; // rcx
  _QWORD *v72; // rax
  UFG::RoadNetworkSegment *v73; // rcx
  unsigned int v74; // edi
  unsigned int v75; // ebx
  UFG::RoadNetworkLane *Path; // rax
  UFG::RoadNetworkLane *v77; // r8
  __int64 v78; // rcx
  char *v79; // rcx
  __int64 v80; // rdx
  char *v81; // rax
  UFG::RoadNetworkSegment *v82; // rcx
  unsigned int v83; // [rsp+30h] [rbp-D0h]
  unsigned __int16 *m_WayEdges; // [rsp+38h] [rbp-C8h]
  UFG::qVector3 segPos; // [rsp+40h] [rbp-C0h] BYREF
  float v86; // [rsp+50h] [rbp-B0h] BYREF
  float v87; // [rsp+54h] [rbp-ACh]
  UFG::qVector3 pos; // [rsp+58h] [rbp-A8h] BYREF
  UFG::RoadNetworkResource *v89; // [rsp+68h] [rbp-98h]
  UFG::qVector3 v90; // [rsp+70h] [rbp-90h] BYREF
  UFG::qVector3 result; // [rsp+80h] [rbp-80h] BYREF
  UFG::RoadNetworkLane *laneList[8]; // [rsp+90h] [rbp-70h] BYREF
  UFG::UITiledMapGPS *v93; // [rsp+130h] [rbp+30h] BYREF
  float endLaneT; // [rsp+138h] [rbp+38h] BYREF
  float laneT; // [rsp+140h] [rbp+40h] BYREF
  UFG::qVector3 *p_mSourcePos; // [rsp+148h] [rbp+48h] BYREF

  v93 = this;
  v1 = 0i64;
  v2 = this;
  this->mNumSplinePoints = 0;
  this->mSplinePoints.size = 0;
  RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  v89 = RoadNetwork;
  if ( !RoadNetwork )
    return;
  m_NavigationData = UFG::WheeledVehicleManager::m_Instance->m_NavigationData;
  if ( !UFG::WheeledVehicleManager::m_Instance->m_NavigationData
    || !m_NavigationData->m_RoadNetworkGraph.pWayfindingList )
  {
    return;
  }
  v5 = v2->mWayFinderClient.vfptr->GetWayEdge(&v2->mWayFinderClient, &m_NavigationData->m_RoadNetworkGraph);
  vfptr = v2->mWayFinderClient.vfptr;
  v7 = v5;
  p_mSourcePos = &v2->mSourcePos;
  vfptr->SetPosition(&v2->mWayFinderClient, &m_NavigationData->m_RoadNetworkGraph, &v2->mSourcePos, &v2->mSourceDir);
  v8 = v2->mWayFinderClient.vfptr->GetWayEdge(&v2->mWayFinderClient, &m_NavigationData->m_RoadNetworkGraph) != v7;
  if ( v2->mDestChanged
    || v8
    || UFG::WheeledVehicleManager::m_Instance->m_NavigationData->m_RoadNetworkGraph.pWayfindingList
    && (!v2->mWayFinderClient.m_NumWayEdges
     || UFG::WayFinderClient::LostWay(
          &v2->mWayFinderClient,
          &UFG::WheeledVehicleManager::m_Instance->m_NavigationData->m_RoadNetworkGraph)) )
  {
    if ( !v2->mWayFinderClient.m_AllowFootPaths )
    {
      segPos = UFG::qVector3::msZero;
      ClosestSegment = UFG::RoadNetworkResource::GetClosestSegment(
                         RoadNetwork,
                         &v2->mDestinationPos,
                         0i64,
                         0,
                         &segPos,
                         0i64);
      if ( ClosestSegment )
      {
        if ( (*(_DWORD *)&ClosestSegment->mBits & 2) != 0 )
          v2->mWayFinderClient.m_AllowFootPaths = 1;
      }
    }
    WayFinder = UFG::GetWayFinder();
    UFG::WayFinder::FindWay(WayFinder, &v2->mWayFinderClient, &v2->mDestinationPos, 0i64);
    v11 = UFG::GetWayFinder();
    UFG::WayFinder::Service(v11, 0.0);
  }
  m_WayEdges = v2->mWayFinderClient.m_WayEdges;
  if ( v2 == (UFG::UITiledMapGPS *)-110i64 )
    return;
  m_NumWayEdges = v2->mWayFinderClient.m_NumWayEdges;
  v83 = m_NumWayEdges;
  if ( !v2->mWayFinderClient.m_NumWayEdges )
    return;
  UFG::WayFinderClient::FindCurrentEdge(&v2->mWayFinderClient);
  v13 = v2->mWayFinderClient.m_WayEdges;
  v14 = m_NumWayEdges - 1;
  LODWORD(v87) = v2->mWayFinderClient.m_CurrEdgeIndex;
  Segment = UFG::RoadNetworkResource::GetSegment(RoadNetwork, v2->mWayFinderClient.m_WayEdges[v14]);
  y = v2->mDestinationPos.y;
  pos.x = v2->mDestinationPos.x;
  pos.y = y;
  v17 = Segment;
  pos.z = 0.0;
  UFG::RoadNetworkNode::GetClosestPosition(Segment, &result, &pos, 0i64);
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
LABEL_128:
      size = v2->mSplinePoints.size;
LABEL_129:
      v2->mNumSplinePoints = size;
      return;
    }
    while ( 1 )
    {
      size = v2->mSplinePoints.size;
      if ( size >= v2->mMaxNumSplinePoints )
        goto LABEL_129;
      v33 = UFG::RoadNetworkResource::GetSegment(RoadNetwork, v13[v31]);
      v34 = v33;
      if ( !v33 )
        goto LABEL_123;
      CenterLane = UFG::RoadNetworkNode::GetCenterLane(v33);
      if ( v29 )
      {
        mOffset = v29->mNextConnection.mOffset;
        if ( mOffset )
        {
          v63 = (UFG::RoadNetworkConnection *)((char *)&v29->mNextConnection + mOffset);
          if ( v63 )
          {
            v64 = v63->mGate.mOffset;
            v65 = v64 ? (UFG::qOffset64<UFG::RoadNetworkGate *> *)((char *)&v63->mGate + v64) : 0i64;
            v66 = v65->mOffset ? (char *)v65 + v65->mOffset : 0i64;
            if ( v66 == (char *)v34 )
              CenterLane = UFG::qBezierPathCollectionMemImaged::GetPath(v63, 0);
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
            IncomingConnection = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(
                                                           (UFG::RoadNetworkGate *)v34,
                                                           0);
            v54 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v34, 1u);
            LODWORD(p_mSourcePos) = 0;
            UFG::RoadNetworkGate::GetLanesLeadingToNode(
              IncomingConnection,
              v52,
              laneList,
              (unsigned int *)&p_mSourcePos,
              8u,
              0xFFFFFFFF);
            if ( (_DWORD)p_mSourcePos
              || (UFG::RoadNetworkGate::GetLanesLeadingToNode(
                    v54,
                    v52,
                    laneList,
                    (unsigned int *)&p_mSourcePos,
                    8u,
                    0xFFFFFFFF),
                  (_DWORD)p_mSourcePos) )
            {
              CenterLane = laneList[0];
              if ( UFG::RoadNetworkLane::IsReversedInNode(laneList[0]) )
              {
                if ( (_DWORD)p_mSourcePos )
                {
                  v55 = laneList;
                  v56 = (unsigned int)p_mSourcePos;
                  do
                  {
                    v57 = *v55++;
                    if ( v57->mLaneIndex < CenterLane->mLaneIndex )
                      CenterLane = v57;
                    --v56;
                  }
                  while ( v56 );
                }
              }
              else if ( (_DWORD)p_mSourcePos )
              {
                v59 = laneList;
                v60 = (unsigned int)p_mSourcePos;
                do
                {
                  v61 = *v59++;
                  if ( v61->mLaneIndex > CenterLane->mLaneIndex )
                    CenterLane = v61;
                  --v60;
                }
                while ( v60 );
              }
            }
LABEL_65:
            v28 = LOBYTE(endLaneT);
            v2 = v93;
          }
          v30 = laneT;
          goto LABEL_67;
        }
        v36 = 1;
        v37 = m_WayEdges[LODWORD(v30) - 1];
        v38 = UFG::RoadNetworkResource::GetSegment(v89, v37);
        v39 = UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v34, 0);
        v40 = UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)v34, 1u);
        v41 = (UFG::RoadNetworkGate *)v40;
        v42 = v40->mLaneList.mOffset;
        if ( v42 && (v43 = (char *)&v40->mLaneList + v42) != 0i64 && !*(_WORD *)v43 && *((_DWORD *)v43 + 6) == v37 )
        {
          v36 = 0;
        }
        else
        {
          v44 = v39->mLaneList.mOffset;
          if ( !v44 || (v45 = (char *)&v39->mLaneList + v44) == 0i64 || *(_WORD *)v45 || *((_DWORD *)v45 + 6) != v37 )
            v36 = UFG::RoadNetworkGate::GetAnyLaneLeadingHereFromNode(v41, v38) == 0i64;
        }
        mNumLanes = (unsigned __int8)v34->mNumLanes;
        v47 = 0i64;
        if ( v36 )
        {
          v48 = 0;
          if ( !v34->mNumLanes )
            goto LABEL_65;
          do
          {
            Lane = UFG::RoadNetworkNode::GetLane(v34, v48);
            if ( UFG::RoadNetworkLane::IsReversedInNode(Lane) )
              break;
            ++v48;
            v47 = Lane;
          }
          while ( v48 < mNumLanes );
        }
        else
        {
          for ( i = mNumLanes - 1; ; --i )
          {
            v51 = UFG::RoadNetworkNode::GetLane(v34, i);
            if ( !UFG::RoadNetworkLane::IsReversedInNode(v51) )
              break;
            v47 = v51;
          }
        }
        v30 = laneT;
        v28 = LOBYTE(endLaneT);
        if ( v47 )
          CenterLane = v47;
        v2 = v93;
      }
LABEL_67:
      v29 = 0i64;
      if ( !CenterLane )
        goto LABEL_122;
      size = v2->mSplinePoints.size;
      if ( size >= v2->mMaxNumSplinePoints )
        goto LABEL_129;
      if ( (*(_DWORD *)&v34->mBits & 2) != 0 )
      {
        v58 = 0;
      }
      else
      {
        v58 = 1;
        if ( LODWORD(v30) == LODWORD(v87) )
        {
          v86 = 0.0;
          UFG::RoadNetworkLane::GetNearestPoint(CenterLane, &v90, &v2->mSourcePos, &v86);
          v67 = v86;
        }
        else
        {
          if ( LODWORD(v30) == v83 - 1 )
          {
            LODWORD(v93) = 0;
            UFG::RoadNetworkLane::GetNearestPoint(CenterLane, &v90, &pos, (float *)&v93);
            UFG::UITiledMapGPS::PlotRoadLane(v2, CenterLane, 0.0, *(float *)&v93, v28 == 0);
            goto LABEL_128;
          }
          v67 = 0.0;
        }
        UFG::UITiledMapGPS::PlotRoadLane(v2, CenterLane, v67, 1.0, v28 == 0);
        size = v2->mSplinePoints.size;
        LOBYTE(endLaneT) = 1;
        if ( size >= v2->mMaxNumSplinePoints )
          goto LABEL_129;
      }
      if ( LODWORD(v30) == v83 - 1 )
        goto LABEL_128;
      v68 = UFG::RoadNetworkResource::GetSegment(v89, m_WayEdges[LODWORD(v30) + 1]);
      if ( v68 && (v69 = CenterLane->mNextConnection.mOffset) != 0 )
      {
        v70 = (UFG::RoadNetworkConnection *)((char *)&CenterLane->mNextConnection + v69);
        if ( !v70 )
          goto LABEL_104;
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
          v29 = CenterLane;
LABEL_104:
          v2 = v93;
          v30 = laneT;
          v28 = LOBYTE(endLaneT);
          v13 = m_WayEdges;
          goto LABEL_123;
        }
        v74 = v70->mNumLanes;
        v75 = 0;
        if ( v70->mNumLanes )
        {
          while ( 1 )
          {
            Path = UFG::qBezierPathCollectionMemImaged::GetPath(v70, v75);
            v77 = Path;
            v78 = Path->mNextConnection.mOffset;
            if ( v78 )
            {
              v79 = (char *)&Path->mNextConnection + v78;
              if ( v79 )
              {
                v80 = *((_QWORD *)v79 + 3);
                v81 = v80 ? &v79[v80 + 24] : 0i64;
                v82 = *(_QWORD *)v81 ? (UFG::RoadNetworkSegment *)&v81[*(_QWORD *)v81] : 0i64;
                if ( v82 == v68 )
                  break;
              }
            }
            if ( ++v75 >= v74 )
              goto LABEL_118;
          }
          v29 = v77;
        }
LABEL_118:
        if ( (v58 || (*(_DWORD *)&v68->mBits & 2) == 0) && v29 )
        {
          v2 = v93;
          UFG::UITiledMapGPS::PlotRoadLane(v93, v29, 0.0, 1.0, LOBYTE(endLaneT) == 0);
          v30 = laneT;
          v28 = 1;
          LOBYTE(endLaneT) = 1;
LABEL_122:
          v13 = v2->mWayFinderClient.m_WayEdges;
          goto LABEL_123;
        }
        v2 = v93;
        v30 = laneT;
        v13 = m_WayEdges;
        v28 = 0;
        LOBYTE(endLaneT) = 0;
      }
      else
      {
        v2 = v93;
        v28 = LOBYTE(endLaneT);
        v13 = m_WayEdges;
      }
LABEL_123:
      ++LODWORD(v30);
      v31 = *(_QWORD *)&segPos.x + 1i64;
      laneT = v30;
      ++*(_QWORD *)&segPos.x;
      if ( LODWORD(v30) >= v83 )
        goto LABEL_128;
      RoadNetwork = v89;
    }
  }
  v18 = (unsigned __int8)v17->mNumLanes;
  if ( v17->mNumLanes && (*(_DWORD *)&v17->mBits & 2) == 0 )
  {
    CenterLaneIndex = UFG::RoadNetworkNode::GetCenterLaneIndex(v17);
    v20 = UFG::RoadNetworkNode::GetLane(v17, CenterLaneIndex);
    v21 = p_mSourcePos;
    v22 = v20;
    laneT = 0.0;
    UFG::RoadNetworkLane::GetNearestPoint(v20, &segPos, p_mSourcePos, &laneT);
    endLaneT = 0.0;
    UFG::RoadNetworkLane::GetNearestPoint(v22, &segPos, &pos, &endLaneT);
    if ( laneT > endLaneT )
    {
      if ( !UFG::RoadNetworkLane::IsReversedInNode(v22) )
      {
        for ( j = v18 - 1; ; --j )
        {
          v27 = UFG::RoadNetworkNode::GetLane(v17, j);
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
          v24 = UFG::RoadNetworkNode::GetLane(v17, v23);
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
void __fastcall UFG::UITiledMapGPS::PlotRoadLane(
        UFG::UITiledMapGPS *this,
        UFG::RoadNetworkLane *roadLane,
        float startLaneT,
        float endLaneT,
        bool plotFirstPoint)
{
  float v6; // xmm6_4
  float Length; // xmm0_4
  float v9; // xmm7_4
  float v10; // xmm8_4

  if ( !roadLane )
    return;
  v6 = startLaneT;
  Length = UFG::RoadNetworkLane::GetLength(roadLane);
  if ( Length < 0.000099999997 )
    return;
  v9 = 1.0 / (float)((int)(float)(Length * 0.06666667) + 1);
  if ( startLaneT > endLaneT )
  {
    if ( !plotFirstPoint )
      v6 = v9 + startLaneT;
    if ( v6 > (float)(endLaneT + 0.0000099999997) )
    {
      while ( UFG::UITiledMapGPS::AddSplinePoint(this, roadLane, v6) )
      {
        v6 = v6 - v9;
        if ( v6 <= (float)(endLaneT + 0.0000099999997) )
          goto LABEL_17;
      }
      return;
    }
LABEL_17:
    UFG::UITiledMapGPS::AddSplinePoint(this, roadLane, endLaneT);
    return;
  }
  if ( !plotFirstPoint )
    v6 = v9 + startLaneT;
  v10 = endLaneT - 0.0000099999997;
  if ( (float)(endLaneT - 0.0000099999997) <= 0.0 )
    v10 = 0.0;
  if ( v6 >= v10 )
    goto LABEL_17;
  while ( UFG::UITiledMapGPS::AddSplinePoint(this, roadLane, v6) )
  {
    v6 = v6 + v9;
    if ( v6 >= v10 )
      goto LABEL_17;
  }
}

// File Line: 1322
// RVA: 0xBE470
char __fastcall UFG::UITiledMapGPS::AddSplinePoint(
        UFG::UITiledMapGPS *this,
        UFG::RoadNetworkLane *roadLane,
        float laneT)
{
  UFG::qArray<UFG::qVector3,0> *p_mSplinePoints; // rdi
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  UFG::qVector3 *p; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  __int64 v12; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  p_mSplinePoints = &this->mSplinePoints;
  if ( this->mSplinePoints.size >= this->mMaxNumSplinePoints )
    return 0;
  UFG::RoadNetworkLane::GetPosNoOffset(roadLane, &result, laneT);
  size = p_mSplinePoints->size;
  capacity = p_mSplinePoints->capacity;
  v7 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v8 = 2 * capacity;
    else
      v8 = 1;
    for ( ; v8 < v7; v8 *= 2 )
      ;
    if ( v8 - v7 > 0x10000 )
      v8 = size + 65537;
    UFG::qArray<UFG::qVector3,0>::Reallocate(p_mSplinePoints, v8, "qArray.Add");
  }
  p = p_mSplinePoints->p;
  y = result.y;
  z = result.z;
  v12 = size;
  p_mSplinePoints->size = v7;
  p[v12].x = result.x;
  p[v12].y = y;
  p[v12].z = z;
  return 1;
}

// File Line: 1699
// RVA: 0xCE300
void __fastcall UFG::UITiledMapGPS::UpdateRace(UFG::UITiledMapGPS *this)
{
  signed __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *ComponentOfType; // rax
  UFG::SimObjectGame *CurrentVehicle; // rax
  __int16 v5; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rbx
  UFG::RacePoint *mNext; // rbx
  UFG::qVector3 *NextPosition; // rax
  float y; // xmm0_4
  float z; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  bool mActive; // zf
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  if ( !this->mActive )
  {
    if ( LocalPlayer
      && ((m_Flags = LocalPlayer->m_Flags, (m_Flags & 0x4000) == 0)
        ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
         ? (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType(
                                                                   LocalPlayer,
                                                                   UFG::CharacterOccupantComponent::_TypeUID))
         : (ComponentOfType = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   LocalPlayer,
                                                                   UFG::CharacterOccupantComponent::_TypeUID)))
        : (ComponentOfType = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent),
          ComponentOfType
       && (CurrentVehicle = (UFG::SimObjectGame *)UFG::CharacterOccupantComponent::GetCurrentVehicle(ComponentOfType)) != 0i64
       && ((v5 = CurrentVehicle->m_Flags, (v5 & 0x4000) == 0)
         ? (v5 >= 0
          ? ((v5 & 0x2000) != 0 || (v5 & 0x1000) != 0
           ? (ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    CurrentVehicle,
                                    UFG::RoadSpaceComponent::_TypeUID))
           : (ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(CurrentVehicle, UFG::RoadSpaceComponent::_TypeUID)))
          : (ComponentOfTypeHK = CurrentVehicle->m_Components.p[24].m_pComponent))
         : (ComponentOfTypeHK = CurrentVehicle->m_Components.p[24].m_pComponent),
           ComponentOfTypeHK)) )
    {
      mPrev = ComponentOfTypeHK[26].m_SafePointerList.mNode.mPrev;
    }
    else
    {
      mPrev = 0i64;
    }
    if ( mPrev )
    {
      if ( *((float *)&mPrev[3].mPrev + 1) > 50.0 )
      {
        mNext = (UFG::RacePoint *)mPrev[1].mNext;
        NextPosition = UFG::RacePoint::GetNextPosition(mNext, &result);
        y = NextPosition->y;
        z = NextPosition->z;
        this->mDestinationPos.x = NextPosition->x;
        this->mDestinationPos.y = y;
        this->mDestinationPos.z = z;
        v12 = mNext->vDirection.y;
        v13 = mNext->vDirection.z;
        this->mDestinationDir.x = mNext->vDirection.x;
        this->mDestinationDir.y = v12;
        this->mDestinationDir.z = v13;
        mActive = this->mActive;
        this->mDestChanged = 1;
        this->mUsePlayerSourcePos = 1;
        this->mActive = 1;
        this->mChanged |= !mActive;
      }
    }
  }
}

// File Line: 1729
// RVA: 0xCE080
void __fastcall UFG::UITiledMapGPS::UpdatePlayerPos(UFG::UITiledMapGPS *this)
{
  float v1; // xmm0_4
  signed __int16 m_Flags; // dx
  UFG::CharacterSubjectComponent *ComponentOfType; // rax
  float v5; // xmm0_4
  float v6; // xmm2_4
  float x; // xmm5_4
  float y; // xmm6_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float z; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-38h] BYREF
  UFG::qVector3 dir; // [rsp+30h] [rbp-28h] BYREF

  if ( UFG::UI::GetPlayerWorldPosition(&pos, &dir) )
  {
    if ( LocalPlayer
      && ((m_Flags = LocalPlayer->m_Flags, (m_Flags & 0x4000) == 0)
        ? (m_Flags >= 0 && (m_Flags & 0x2000) == 0 && (m_Flags & 0x1000) == 0
         ? (ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObject::GetComponentOfType(
                                                                  LocalPlayer,
                                                                  UFG::CharacterSubjectComponent::_TypeUID))
         : (ComponentOfType = (UFG::CharacterSubjectComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  LocalPlayer,
                                                                  UFG::CharacterSubjectComponent::_TypeUID)))
        : (ComponentOfType = UFG::SimObjectCharacter::GetComponent<UFG::CharacterSubjectComponent>(LocalPlayer)),
          ComponentOfType) )
    {
      ((void (__fastcall *)(UFG::CharacterSubjectComponent *))ComponentOfType->vfptr[28].__vecDelDtor)(ComponentOfType);
    }
    else
    {
      v1 = 0.0;
    }
    v5 = v1 * this->mGPS_UpdatePeriod;
    if ( v5 <= 1.0 )
    {
      v5 = *(float *)&FLOAT_1_0;
    }
    else
    {
      v6 = FLOAT_5_0;
      if ( v5 >= 5.0 )
      {
LABEL_19:
        x = pos.x;
        y = pos.y;
        v9 = this->mSourcePos.x;
        v10 = this->mSourcePos.y;
        if ( (float)((float)((float)(pos.y - v10) * (float)(pos.y - v10))
                   + (float)((float)(pos.x - v9) * (float)(pos.x - v9))) > (float)(v6 * v6) )
        {
          v11 = this->mDestinationPos.y - v10;
          v12 = this->mDestinationPos.x - v9;
          this->mDestinationDir.z = this->mDestinationPos.z - this->mSourcePos.z;
          z = pos.z;
          this->mDestinationDir.y = v11;
          v14 = dir.x;
          this->mDestinationDir.x = v12;
          this->mSourcePos.z = z;
          v15 = dir.y;
          this->mSourcePos.x = x;
          this->mSourcePos.y = y;
          this->mSourceDir.x = v14;
          v16 = dir.z;
          this->mSourceDir.y = v15;
          this->mSourceDir.z = v16;
          this->mChanged = 1;
        }
        return;
      }
    }
    v6 = v5;
    goto LABEL_19;
  }
}

// File Line: 1766
// RVA: 0xCE520
void __fastcall UFG::UITiledMapGPS::UpdateTrueDirection(UFG::UITiledMapGPS *this)
{
  signed __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  __int16 v4; // ax
  unsigned int m_NumWayEdges; // r8d
  unsigned __int16 *m_WayEdges; // rbx
  unsigned int v7; // r13d
  unsigned int v8; // ecx
  unsigned __int16 *v9; // rdx
  unsigned int v10; // esi
  UFG::RoadNetworkResource *RoadNetwork; // rdi
  unsigned int v12; // eax
  unsigned __int16 *i; // r12
  UFG::RoadNetworkSegment *Segment; // r14
  UFG::RoadNetworkSegment *v15; // rsi
  UFG::RoadNetworkGate *IncomingConnection; // rbx
  UFG::RoadNetworkGate *v17; // rdi
  UFG::RoadNetworkLane *AnyLaneLeadingToNode; // r15
  UFG::RoadNetworkLane *v19; // rax
  UFG::RoadNetworkLane *v20; // rbx
  bool v21; // di
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::Camera *p_mCamera; // rax
  int v24; // xmm6_4
  int v25; // xmm7_4
  UFG::RoadNetworkNode *v26; // rcx
  float v27; // xmm4_4
  __m128 x_low; // xmm1
  float v29; // xmm2_4
  float v30; // xmm5_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-D8h] BYREF
  unsigned int v37; // [rsp+100h] [rbp+8h]
  unsigned int mTrueDirectionEdgeCount; // [rsp+108h] [rbp+10h]
  unsigned int v39; // [rsp+110h] [rbp+18h]
  UFG::RoadNetworkResource *v40; // [rsp+118h] [rbp+20h]

  mTrueDirectionEdgeCount = this->mTrueDirectionEdgeCount;
  this->mTrueDirectionIntersectionLane = 0i64;
  this->mTrueDirectionHighwayRamp = 0;
  this->mTrueDirectionEdgeCount = 0;
  if ( !this->mActive
    || this->mInteriorActive
    || this->mOnlyShowInVehicles && !UFG::UI::IsPlayerInVehicle()
    || UFG::UI::IsPlayerInWater()
    || !this->mVisible
    || !UFG::WheeledVehicleManager::IsTrueDirectionUpdateEnabled(UFG::WheeledVehicleManager::m_Instance)
    || !this->mWayFinderClient.m_NumWayEdges
    || !LocalPlayer )
  {
    return;
  }
  m_Flags = LocalPlayer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    m_pComponent = LocalPlayer->m_Components.p[44].m_pComponent;
  else
    m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                 ? UFG::SimObjectGame::GetComponentOfTypeHK(LocalPlayer, UFG::CharacterOccupantComponent::_TypeUID)
                 : UFG::SimObject::GetComponentOfType(LocalPlayer, UFG::CharacterOccupantComponent::_TypeUID);
  if ( !m_pComponent
    || LODWORD(m_pComponent[1].m_SafePointerList.mNode.mNext) != 4
    || !UFG::WheeledVehicleManager::m_Instance->m_NavigationData->m_RoadNetworkGraph.pWayfindingList )
  {
    return;
  }
  v4 = ((__int64 (__fastcall *)(UFG::MiniMapWayFinderClient *))this->mWayFinderClient.vfptr->GetWayEdge)(&this->mWayFinderClient);
  m_NumWayEdges = this->mWayFinderClient.m_NumWayEdges;
  m_WayEdges = this->mWayFinderClient.m_WayEdges;
  v7 = 0;
  v8 = 0;
  if ( this->mWayFinderClient.m_NumWayEdges )
  {
    v9 = this->mWayFinderClient.m_WayEdges;
    while ( *v9 != v4 )
    {
      ++v8;
      ++v9;
      if ( v8 >= m_NumWayEdges )
        goto LABEL_27;
    }
    v7 = v8;
  }
LABEL_27:
  v10 = m_NumWayEdges - 1;
  v39 = m_NumWayEdges - 1;
  if ( v7 == m_NumWayEdges - 1 )
    return;
  RoadNetwork = UFG::WheeledVehicleNavigationData::GetRoadNetwork(UFG::WheeledVehicleManager::m_Instance->m_NavigationData);
  v40 = RoadNetwork;
  v12 = 0;
  if ( v7 >= v10 )
    return;
  for ( i = &m_WayEdges[v7]; ; ++i )
  {
    v37 = v12 + 1;
    ++v7;
    Segment = UFG::RoadNetworkResource::GetSegment(RoadNetwork, *i);
    v15 = UFG::RoadNetworkResource::GetSegment(RoadNetwork, m_WayEdges[v7]);
    if ( UFG::RoadNetworkNode::IsConnectedToNode(Segment, v15) )
    {
      v12 = v37;
      goto LABEL_58;
    }
    IncomingConnection = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(
                                                   (UFG::RoadNetworkGate *)Segment,
                                                   0);
    v17 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection((UFG::RoadNetworkGate *)Segment, 1u);
    AnyLaneLeadingToNode = UFG::RoadNetworkGate::GetAnyLaneLeadingToNode(IncomingConnection, v15);
    v19 = UFG::RoadNetworkGate::GetAnyLaneLeadingToNode(v17, v15);
    v20 = v19;
    if ( !AnyLaneLeadingToNode && !v19 )
      return;
    v21 = (*(_DWORD *)&Segment->mBits & 2) != 0 && (*(_DWORD *)&v15->mBits & 2) != 0;
    if ( AnyLaneLeadingToNode )
      v20 = AnyLaneLeadingToNode;
    if ( v15->mPropertyID1 == 650 )
      break;
    UFG::Director::Get();
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      p_mCamera = &mCurrentCamera->mCamera;
    else
      p_mCamera = 0i64;
    v24 = LODWORD(p_mCamera->mTransformation.v2.x) ^ _xmm[0];
    v25 = LODWORD(p_mCamera->mTransformation.v2.y) ^ _xmm[0];
    v26 = (UFG::RoadNetworkNode *)((char *)v20 + v20->mNode.mOffset);
    if ( !v20->mNode.mOffset )
      v26 = 0i64;
    UFG::RoadNetworkNode::GetTangent(v26, &result, v20->mLaneIndex, 1.0);
    result.z = 0.0;
    v27 = (float)(*(float *)&v25 * *(float *)&v25) + (float)(*(float *)&v24 * *(float *)&v24);
    if ( v27 < 0.0000010000001
      || (x_low = (__m128)LODWORD(result.x),
          x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(result.y * result.y),
          x_low.m128_f32[0] < 0.0000010000001) )
    {
      v12 = v37;
    }
    else
    {
      if ( x_low.m128_f32[0] == 0.0 )
        v29 = 0.0;
      else
        v29 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
      v30 = result.x * v29;
      v31 = result.y * v29;
      v32 = v29 * 0.0;
      if ( v27 == 0.0 )
        v33 = 0.0;
      else
        v33 = 1.0 / fsqrt(v27);
      v12 = v37;
      LODWORD(v34) = COERCE_UNSIGNED_INT(
                       (float)((float)(v31 * (float)(*(float *)&v25 * v33))
                             + (float)(v30 * (float)(*(float *)&v24 * v33)))
                     + (float)((float)(v33 * 0.0) * v32)) & _xmm;
      if ( mTrueDirectionEdgeCount <= v37 )
        v35 = FLOAT_0_72999996;
      else
        v35 = FLOAT_0_70999998;
      if ( v34 < v35 )
        goto LABEL_63;
    }
    RoadNetwork = v40;
    m_WayEdges = this->mWayFinderClient.m_WayEdges;
LABEL_58:
    if ( v7 >= v39 )
      return;
  }
  v12 = v37;
  this->mTrueDirectionHighwayRamp = 1;
LABEL_63:
  this->mTrueDirectionEdgeCount = v12;
  if ( !v21 )
    this->mTrueDirectionIntersectionLane = v20;
}

// File Line: 1923
// RVA: 0xC5E30
bool __fastcall UFG::UITiledMapGPS::IsVisible(UFG::UITiledMapGPS *this)
{
  return this->mActive
      && !this->mInteriorActive
      && (!this->mOnlyShowInVehicles || UFG::UI::IsPlayerInVehicle())
      && !UFG::UI::IsPlayerInWater()
      && this->mVisible;
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

  v1 = !this->mActive;
  this->mActive = 0;
  this->mChanged |= !v1;
  if ( UFG::UIHKPlayerObjectiveManager::mInstance )
    UFG::UIHKPlayerObjectiveManager::ClearWorldMapDest(UFG::UIHKPlayerObjectiveManager::mInstance);
  UFG::UIHKObjectiveDistanceWidget::Clear(UFG::UIHKScreenHud::ObjectiveDistance);
}

