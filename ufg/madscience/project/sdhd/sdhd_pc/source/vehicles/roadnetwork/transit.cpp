// File Line: 68
// RVA: 0x656F20
void __fastcall UFG::TransitUtility::OnSelectDestination(UFG::qVector3 *destPos)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r13
  float x; // xmm1_4
  float y; // xmm0_4
  UFG::RoadNetworkSegment *ClosestSegment; // rbx
  UFG::qVector3 *NearestPos; // rax
  float v6; // xmm7_4
  float v7; // xmm8_4
  float z; // xmm9_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  UFG::RoadNetworkNode *v11; // rcx
  UFG::AiDriverComponent *PlayerVehicleAiDriver; // rax
  UFG::AiDriverComponent *v13; // r12
  UFG::SimObjectVehicle *m_pSimObject; // r9
  UFG::RoadSpaceComponent *m_pComponent; // rsi
  UFG::RoadNetworkSegment::RoadSegmentBits mBits; // r8d
  UFG::VehicleSubjectComponent *v17; // r15
  UFG::WheeledVehicleNavigationData *m_NavigationData; // rbx
  UFG::VehicleWayFinderClient *p_mWayClient; // r14
  bool m_AllowFootPaths; // al
  int m_LaneFlags; // eax
  UFG::WayFinderClientVtbl *vfptr; // rdi
  __int64 v23; // rbx
  __int64 v24; // rax
  __int64 v25; // rax
  float v26; // xmm1_4
  float v27; // xmm2_4
  unsigned __int16 m_NumWayEdges; // ax
  __int64 v29; // r15
  unsigned __int16 *i; // rbx
  UFG::RoadNetworkSegment *Segment; // rax
  UFG::RoadNetworkGate *v32; // rdi
  UFG::RoadNetworkSegment::RoadSegmentBits v33; // edx
  UFG::RoadNetworkSegment *v34; // r15
  UFG::RoadNetworkGate *IncomingConnection; // rbx
  UFG::RoadNetworkGate *v36; // rdi
  UFG::RoadNetworkLane *v37; // rbx
  UFG::RoadNetworkLane **v38; // rdx
  __int64 v39; // r8
  UFG::RoadNetworkLane *v40; // rcx
  UFG::RoadNetworkLane **v41; // rdx
  __int64 v42; // r8
  UFG::RoadNetworkLane *v43; // rcx
  float v44; // xmm1_4
  float v45; // xmm7_4
  UFG::qVector3 *v46; // rax
  float v47; // xmm1_4
  float v48; // xmm2_4
  UFG::RoadNetworkNode *v49; // rcx
  UFG::SimObject *v50; // rax
  float v51; // xmm2_4
  float v52; // xmm6_4
  float v53; // xmm1_4
  float v54; // xmm2_4
  UFG::qVector3 goal_position; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qVector3 result; // [rsp+40h] [rbp-C0h] BYREF
  float nearestT; // [rsp+50h] [rbp-B0h] BYREF
  int v58; // [rsp+54h] [rbp-ACh]
  UFG::RoadNetworkResource *v59; // [rsp+58h] [rbp-A8h]
  UFG::RoadNetworkLane *nearestLane; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qVector3 pos; // [rsp+68h] [rbp-98h] BYREF
  UFG::RoadNetworkLane *laneList[8]; // [rsp+80h] [rbp-80h] BYREF
  bool v63; // [rsp+160h] [rbp+60h]
  bool m_bCanTurnAround; // [rsp+168h] [rbp+68h]
  bool m_Attached; // [rsp+170h] [rbp+70h]
  UFG::WheeledVehicleNavigationData *numLanes; // [rsp+178h] [rbp+78h] BYREF

  m_pTransformNodeComponent = 0i64;
  goal_position.x = UFG::qVector3::msZero.x;
  goal_position.y = UFG::qVector3::msZero.y;
  v59 = UFG::gpRoadNetworkResource;
  x = destPos->x;
  goal_position.z = UFG::qVector3::msZero.z;
  y = destPos->y;
  pos.x = x;
  pos.y = y;
  pos.z = FLOAT_N1001_0;
  ClosestSegment = UFG::RoadNetworkResource::GetClosestSegment(UFG::gpRoadNetworkResource, &pos, 0i64, 0);
  if ( ClosestSegment )
  {
    nearestLane = 0i64;
    nearestT = 0.0;
    NearestPos = UFG::RoadNetworkNode::GetNearestPos(ClosestSegment, &result, &goal_position, &nearestLane, &nearestT);
    v6 = UFG::qVector3::msZero.x;
    v7 = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    v9 = NearestPos->y;
    v10 = NearestPos->z;
    goal_position.x = NearestPos->x;
    goal_position.y = v9;
    goal_position.z = v10;
    if ( nearestLane )
    {
      if ( nearestLane->mNode.mOffset )
        v11 = (UFG::RoadNetworkNode *)((char *)nearestLane + nearestLane->mNode.mOffset);
      else
        v11 = 0i64;
      UFG::RoadNetworkNode::GetTangent(v11, &result, nearestLane->mLaneIndex, nearestT);
      v6 = result.x;
      v7 = result.y;
      z = result.z;
    }
    PlayerVehicleAiDriver = UFG::TransitUtility::GetPlayerVehicleAiDriver();
    v13 = PlayerVehicleAiDriver;
    if ( PlayerVehicleAiDriver )
    {
      m_pSimObject = (UFG::SimObjectVehicle *)PlayerVehicleAiDriver->m_pSimObject;
      if ( m_pSimObject )
      {
        m_pComponent = (UFG::RoadSpaceComponent *)m_pSimObject->m_Components.p[24].m_pComponent;
        if ( m_pComponent )
        {
          mBits = ClosestSegment->mBits;
          if ( (*(_BYTE *)&mBits & 2) != 0 || (*(_BYTE *)&mBits & 8) != 0 )
          {
            v17 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(m_pSimObject);
            if ( v17 )
            {
              m_NavigationData = UFG::WheeledVehicleManager::m_Instance->m_NavigationData;
              p_mWayClient = &m_pComponent->mWayClient;
              numLanes = UFG::WheeledVehicleNavigationData::GetRoadNetworkGraph(
                           UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                           &m_pComponent->mWayClient);
              *(_QWORD *)&result.x = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(
                                       m_NavigationData,
                                       &m_pComponent->mWayClient);
              m_Attached = m_pComponent->mGuide.m_Attached;
              if ( m_Attached )
                UFG::RoadNetworkGuide::RemoveFromNetwork(&m_pComponent->mGuide);
              m_AllowFootPaths = m_pComponent->mWayClient.m_AllowFootPaths;
              m_pComponent->mWayClient.m_AllowFootPaths = 1;
              v63 = m_AllowFootPaths;
              m_LaneFlags = m_pComponent->mWayClient.m_LaneFlags;
              m_pComponent->mWayClient.m_LaneFlags = 64;
              v58 = m_LaneFlags;
              m_bCanTurnAround = v13->m_bCanTurnAround;
              if ( !v13->m_RoadRuleFlagsLocked )
                v13->m_bCanTurnAround = 1;
              vfptr = p_mWayClient->vfptr;
              v23 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v17->vfptr[16].__vecDelDtor)(v17);
              v24 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v17->vfptr[17].__vecDelDtor)(v17);
              vfptr->SetPosition(
                &m_pComponent->mWayClient,
                &numLanes->m_RoadNetworkGraph,
                (UFG::qVector3 *)v24,
                (UFG::qVector3 *)v23);
              UFG::WayFinder::FindWay(*(UFG::WayFinder **)&result.x, &m_pComponent->mWayClient, &goal_position, 0i64);
              UFG::WayFinder::Service(*(UFG::WayFinder **)&result.x, 0.0);
              v25 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v17->vfptr[17].__vecDelDtor)(v17);
              v6 = UFG::qVector3::msZero.x;
              v7 = UFG::qVector3::msZero.y;
              z = UFG::qVector3::msZero.z;
              v26 = *(float *)(v25 + 4);
              v27 = *(float *)(v25 + 8);
              goal_position.x = *(float *)v25;
              goal_position.y = v26;
              goal_position.z = v27;
              if ( m_pComponent != (UFG::RoadSpaceComponent *)-590i64 )
              {
                m_NumWayEdges = m_pComponent->mWayClient.m_NumWayEdges;
                if ( m_NumWayEdges )
                {
                  if ( m_NumWayEdges > 1u )
                  {
                    v29 = (unsigned int)m_NumWayEdges - 2;
                    for ( i = &m_pComponent->mWayClient.m_WayEdges[v29]; ; --i )
                    {
                      Segment = UFG::RoadNetworkResource::GetSegment(v59, *i);
                      v32 = (UFG::RoadNetworkGate *)Segment;
                      if ( !Segment )
                        break;
                      v33 = Segment->mBits;
                      if ( (*(_BYTE *)&v33 & 2) == 0 && (*(_BYTE *)&v33 & 8) == 0 )
                      {
                        v34 = UFG::RoadNetworkResource::GetSegment(
                                v59,
                                p_mWayClient->m_WayEdges[(unsigned int)(v29 + 1)]);
                        if ( v34 )
                        {
                          IncomingConnection = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(
                                                                         v32,
                                                                         0);
                          v36 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(v32, 1u);
                          LODWORD(numLanes) = 0;
                          UFG::RoadNetworkGate::GetLanesLeadingToNode(
                            IncomingConnection,
                            v34,
                            laneList,
                            (unsigned int *)&numLanes,
                            8u,
                            0xFFu);
                          if ( (_DWORD)numLanes
                            || (UFG::RoadNetworkGate::GetLanesLeadingToNode(
                                  v36,
                                  v34,
                                  laneList,
                                  (unsigned int *)&numLanes,
                                  8u,
                                  0xFFu),
                                (_DWORD)numLanes) )
                          {
                            v37 = laneList[0];
                            if ( UFG::RoadNetworkLane::IsReversedInNode(laneList[0]) )
                            {
                              if ( (_DWORD)numLanes )
                              {
                                v38 = laneList;
                                v39 = (unsigned int)numLanes;
                                do
                                {
                                  v40 = *v38++;
                                  if ( v40->mLaneIndex > v37->mLaneIndex )
                                    v37 = v40;
                                  --v39;
                                }
                                while ( v39 );
                              }
                            }
                            else if ( (_DWORD)numLanes )
                            {
                              v41 = laneList;
                              v42 = (unsigned int)numLanes;
                              do
                              {
                                v43 = *v41++;
                                if ( v43->mLaneIndex < v37->mLaneIndex )
                                  v37 = v43;
                                --v42;
                              }
                              while ( v42 );
                            }
                            v44 = 3.0 / UFG::RoadNetworkLane::GetLength(v37);
                            if ( v44 <= 0.0 )
                            {
                              v44 = 0.0;
                            }
                            else if ( v44 >= 1.0 )
                            {
                              v44 = *(float *)&FLOAT_1_0;
                            }
                            v45 = 1.0 - v44;
                            if ( (float)(1.0 - v44) <= 0.0 )
                            {
                              v45 = 0.0;
                            }
                            else if ( v45 >= 1.0 )
                            {
                              v45 = *(float *)&FLOAT_1_0;
                            }
                            v46 = UFG::RoadNetworkLane::GetPos(v37, &result, v45);
                            v47 = v46->y;
                            v48 = v46->z;
                            goal_position.x = v46->x;
                            goal_position.y = v47;
                            goal_position.z = v48;
                            v49 = (UFG::RoadNetworkNode *)((char *)v37 + v37->mNode.mOffset);
                            if ( !v37->mNode.mOffset )
                              v49 = 0i64;
                            UFG::RoadNetworkNode::GetTangent(v49, &result, v37->mLaneIndex, v45);
                            v6 = result.x;
                            v7 = result.y;
                            z = result.z;
                          }
                        }
                        break;
                      }
                      LODWORD(v29) = v29 - 1;
                    }
                  }
                }
              }
              m_pComponent->mWayClient.m_AllowFootPaths = v63;
              m_pComponent->mWayClient.m_LaneFlags = v58;
              if ( !v13->m_RoadRuleFlagsLocked )
                v13->m_bCanTurnAround = m_bCanTurnAround;
              if ( m_Attached )
              {
                v50 = m_pComponent->m_pSimObject;
                if ( v50 )
                  m_pTransformNodeComponent = v50->m_pTransformNodeComponent;
                UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                UFG::RoadSpaceComponent::AttachToRoadNetwork(
                  m_pComponent,
                  (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
                  0i64);
              }
              p_mWayClient->vfptr->ResetWay(&m_pComponent->mWayClient);
            }
          }
          v51 = (float)((float)(v7 * v7) + (float)(v6 * v6)) + (float)(z * z);
          if ( v51 > 9.9999994e-11 )
          {
            if ( v51 == 0.0 )
              v52 = 0.0;
            else
              v52 = 1.0 / fsqrt(v51);
            v6 = v6 * v52;
            v7 = v7 * v52;
            z = z * v52;
          }
          v53 = goal_position.y;
          v54 = goal_position.z;
          m_pComponent->mDestinationPosition.x = goal_position.x;
          m_pComponent->mDestinationPosition.y = v53;
          m_pComponent->mDestinationPosition.z = v54;
          m_pComponent->mDestinationDirection.x = v6;
          m_pComponent->mDestinationDirection.y = v7;
          m_pComponent->mDestinationDirection.z = z;
        }
      }
    }
  }
}

// File Line: 220
// RVA: 0x656C30
void UFG::TransitUtility::OnExitMap(void)
{
  UFG::AiDriverComponent *PlayerVehicleAiDriver; // rax
  UFG::AiDriverComponent *v1; // rbx
  UFG::SimObject *m_pSimObject; // rcx
  UFG::RoadSpaceComponent *m_pComponent; // rbp
  bool v4; // zf
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float *m_pSimComponent; // rax
  unsigned int m_LaneFlags; // r14d
  UFG::SimObject *v8; // rax

  PlayerVehicleAiDriver = UFG::TransitUtility::GetPlayerVehicleAiDriver();
  v1 = PlayerVehicleAiDriver;
  if ( PlayerVehicleAiDriver )
  {
    m_pSimObject = PlayerVehicleAiDriver->m_pSimObject;
    if ( m_pSimObject )
    {
      m_pComponent = (UFG::RoadSpaceComponent *)m_pSimObject->m_Components.p[24].m_pComponent;
      if ( m_pComponent )
      {
        v4 = PlayerVehicleAiDriver->m_DrivingRole == 4;
        PlayerVehicleAiDriver->m_IsAmbient = 0;
        if ( !v4 )
        {
          PlayerVehicleAiDriver->m_DrivingRole = 4;
          if ( !PlayerVehicleAiDriver->m_RoadRuleFlagsLocked )
          {
            PlayerVehicleAiDriver->m_bAvoidPeds = 1;
            PlayerVehicleAiDriver->m_bAllowedToPass = 1;
            PlayerVehicleAiDriver->m_bStayOffSidewalk = 1;
            PlayerVehicleAiDriver->m_bRespectSpeedLimit = 1;
            PlayerVehicleAiDriver->m_bCanTurnAround = 0;
          }
          PlayerVehicleAiDriver->m_bSavedAvoidPeds = PlayerVehicleAiDriver->m_bAvoidPeds;
        }
        m_pTransformNodeComponent = 0i64;
        if ( PlayerVehicleAiDriver->m_DrivingMode != 2 )
        {
          m_pSimComponent = (float *)PlayerVehicleAiDriver->m_pRoadSpace.m_pSimComponent;
          v1->m_DrivingMode = 2;
          v1->m_fReactionTime = 0.0;
          v1->m_fDelayedStopDecel = 0.0;
          v1->mModeSteeringLockEnabled = 0;
          v1->mModeGasBrakeLockEnabled = 0;
          v1->m_bIgnoreArrivalDirection = 0;
          if ( !m_pSimComponent
            || (float)((float)((float)(m_pSimComponent[415] * m_pSimComponent[415])
                             + (float)(m_pSimComponent[416] * m_pSimComponent[416]))
                     + (float)(m_pSimComponent[417] * m_pSimComponent[417])) < 0.0000010000001 )
          {
            v1->m_bIgnoreArrivalDirection = 1;
          }
        }
        if ( !v1->m_RoadRuleFlagsLocked )
          v1->m_ObeyTrafficLights = 0;
        m_LaneFlags = 0;
        if ( m_pComponent != (UFG::RoadSpaceComponent *)-552i64 )
        {
          m_LaneFlags = m_pComponent->mWayClient.m_LaneFlags;
          m_pComponent->mWayClient.m_LaneFlags = 8;
        }
        if ( UFG::AiDriverComponent::WarpToDestination(v1) )
        {
          UFG::WheeledVehicleManager::m_Instance->m_PlaceTransitVehiclePending = 1;
        }
        else
        {
          if ( v1->m_DrivingMode != 1 )
          {
            v1->m_DrivingMode = 1;
            v1->m_fReactionTime = 0.0;
            v1->m_fDelayedStopDecel = 0.0;
            v1->mModeSteeringLockEnabled = 0;
            v1->mModeGasBrakeLockEnabled = 0;
            v1->m_bIgnoreArrivalDirection = 0;
          }
          v8 = m_pComponent->m_pSimObject;
          if ( v8 )
            m_pTransformNodeComponent = v8->m_pTransformNodeComponent;
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          UFG::RoadSpaceComponent::AttachToRoadNetwork(
            m_pComponent,
            (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
            0i64);
        }
        if ( m_pComponent != (UFG::RoadSpaceComponent *)-552i64 )
          m_pComponent->mWayClient.m_LaneFlags = m_LaneFlags;
      }
    }
  }
}

// File Line: 283
// RVA: 0x6577B0
void UFG::TransitUtility::PlaceTransitVehicle(void)
{
  UFG::AiDriverComponent *PlayerVehicleAiDriver; // rax
  UFG::SimObjectVehicle *m_pSimObject; // rbx
  UFG::SimComponentHolder *p; // rax
  UFG::TransformNodeComponent *m_pComponent; // rdi
  float y; // xmm1_4
  float z; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  UFG::allocator::free_link *v8; // rax
  float v9; // xmm6_4
  UFG::SimComponent *v10; // rdi
  UFG::RoadNetworkGuide *p_mNext; // rdi
  UFG::SimObject *v12; // rcx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::qVector3 position; // [rsp+48h] [rbp-50h] BYREF
  UFG::qVector3 out; // [rsp+58h] [rbp-40h] BYREF
  UFG::qVector3 dir; // [rsp+68h] [rbp-30h] BYREF

  PlayerVehicleAiDriver = UFG::TransitUtility::GetPlayerVehicleAiDriver();
  if ( PlayerVehicleAiDriver )
  {
    m_pSimObject = (UFG::SimObjectVehicle *)PlayerVehicleAiDriver->m_pSimObject;
    if ( m_pSimObject )
    {
      p = m_pSimObject->m_Components.p;
      m_pComponent = (UFG::TransformNodeComponent *)p[2].m_pComponent;
      if ( m_pComponent )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)p[2].m_pComponent);
        y = m_pComponent->mWorldTransform.v3.y;
        z = m_pComponent->mWorldTransform.v3.z;
        position.x = m_pComponent->mWorldTransform.v3.x;
        position.y = y;
        position.z = z;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pComponent);
        v6 = m_pComponent->mWorldTransform.v0.y;
        v7 = m_pComponent->mWorldTransform.v0.z;
        dir.x = m_pComponent->mWorldTransform.v0.x;
        dir.y = v6;
        dir.z = v7;
        out = position;
        position.z = position.z + 1.0;
        if ( UFG::SimObjectUtility::PlaceOnGround(&out, &position, 0.050000001, 6.0) )
        {
          v8 = UFG::qMalloc(0x90ui64, "TeleportEvent", 0i64);
          if ( v8 )
            UFG::TeleportEvent::TeleportEvent(
              (UFG::TeleportEvent *)v8,
              &out,
              &dir,
              m_pSimObject->mNode.mUID,
              0,
              UFG::TeleportEvent::m_Name,
              &UFG::qVector3::msDirUp);
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v8);
          v9 = FLOAT_2_0;
          v10 = m_pSimObject->m_Components.p[24].m_pComponent;
          if ( v10 )
          {
            p_mNext = (UFG::RoadNetworkGuide *)&v10[5].m_BoundComponentHandles.mNode.mNext;
            if ( p_mNext )
            {
              if ( UFG::RoadNetworkGuide::IsCurrentLocationValid(p_mNext)
                && (float)(p_mNext->m_SpeedLimit * 0.80000001) >= 2.0 )
              {
                v9 = p_mNext->m_SpeedLimit * 0.80000001;
              }
            }
          }
          UFG::VehicleUtility::OverrideForwardSpeedKPH(m_pSimObject, v9 * 3.5999999);
        }
        v12 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
        if ( v12 )
        {
          ComponentOfType = UFG::SimObject::GetComponentOfType(v12, UFG::ChaseCameraComponent::_TypeUID);
          if ( ComponentOfType )
            ((void (__fastcall *)(UFG::SimComponent *))ComponentOfType->vfptr[14].__vecDelDtor)(ComponentOfType);
        }
      }
    }
  }
}

// File Line: 327
// RVA: 0x64EEA0
UFG::AiDriverComponent *__fastcall UFG::TransitUtility::GetPlayerVehicleAiDriver()
{
  signed __int16 m_Flags; // dx
  UFG::CharacterOccupantComponent *ComponentOfType; // rax
  UFG::SimObjectCVBase *CurrentVehicle; // rax

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
     && (CurrentVehicle = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(ComponentOfType)) != 0i64) )
  {
    return UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(CurrentVehicle);
  }
  else
  {
    return 0i64;
  }
}

