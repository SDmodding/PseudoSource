// File Line: 68
// RVA: 0x656F20
void __fastcall UFG::TransitUtility::OnSelectDestination(UFG::qVector3 *destPos)
{
  UFG::TransformNodeComponent *v1; // r13
  float v2; // xmm0_4
  UFG::RoadNetworkSegment *v3; // rbx
  UFG::qVector3 *v4; // rax
  float v5; // xmm7_4
  float v6; // xmm8_4
  float v7; // xmm9_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  UFG::RoadNetworkNode *v10; // rcx
  UFG::AiDriverComponent *v11; // rax
  UFG::AiDriverComponent *v12; // r12
  UFG::SimObjectVehicle *v13; // r9
  UFG::RoadSpaceComponent *v14; // rsi
  UFG::RoadNetworkSegment::RoadSegmentBits v15; // er8
  UFG::VehicleSubjectComponent *v16; // r15
  UFG::WheeledVehicleNavigationData *v17; // rbx
  signed __int64 v18; // r14
  bool v19; // al
  int v20; // eax
  __int64 v21; // rdi
  __int64 v22; // rbx
  __int64 v23; // rax
  __int64 v24; // rax
  float v25; // xmm1_4
  float v26; // xmm2_4
  unsigned __int16 v27; // ax
  __int64 v28; // r15
  unsigned __int16 *i; // rbx
  UFG::RoadNetworkSegment *v30; // rax
  UFG::RoadNetworkGate *v31; // rdi
  UFG::RoadNetworkSegment *v32; // r15
  UFG::RoadNetworkGate *v33; // rbx
  UFG::RoadNetworkGate *v34; // rdi
  UFG::RoadNetworkLane *v35; // rbx
  UFG::RoadNetworkLane **v36; // rdx
  __int64 v37; // r8
  UFG::RoadNetworkLane *v38; // rcx
  UFG::RoadNetworkLane **v39; // rdx
  __int64 v40; // r8
  UFG::RoadNetworkLane *v41; // rcx
  float v42; // xmm1_4
  float v43; // xmm7_4
  UFG::qVector3 *v44; // rax
  float v45; // xmm1_4
  float v46; // xmm2_4
  UFG::RoadNetworkNode *v47; // rcx
  UFG::SimObject *v48; // rax
  float v49; // xmm2_4
  float v50; // xmm6_4
  float v51; // xmm1_4
  float v52; // xmm2_4
  UFG::qVector3 goal_position; // [rsp+30h] [rbp-D0h]
  UFG::qVector3 result; // [rsp+40h] [rbp-C0h]
  float nearestT; // [rsp+50h] [rbp-B0h]
  int v56; // [rsp+54h] [rbp-ACh]
  UFG::RoadNetworkResource *v57; // [rsp+58h] [rbp-A8h]
  UFG::RoadNetworkLane *nearestLane; // [rsp+60h] [rbp-A0h]
  UFG::qVector3 pos; // [rsp+68h] [rbp-98h]
  UFG::RoadNetworkLane *laneList; // [rsp+80h] [rbp-80h]
  bool v61; // [rsp+160h] [rbp+60h]
  bool v62; // [rsp+168h] [rbp+68h]
  bool v63; // [rsp+170h] [rbp+70h]
  UFG::WheeledVehicleNavigationData *numLanes; // [rsp+178h] [rbp+78h]

  v1 = 0i64;
  goal_position = UFG::qVector3::msZero;
  v57 = UFG::gpRoadNetworkResource;
  v2 = destPos->y;
  pos.x = destPos->x;
  pos.y = v2;
  pos.z = FLOAT_N1001_0;
  v3 = UFG::RoadNetworkResource::GetClosestSegment(UFG::gpRoadNetworkResource, &pos, 0i64, 0);
  if ( v3 )
  {
    nearestLane = 0i64;
    nearestT = 0.0;
    v4 = UFG::RoadNetworkNode::GetNearestPos(
           (UFG::RoadNetworkNode *)&v3->mType,
           &result,
           &goal_position,
           &nearestLane,
           &nearestT);
    v5 = UFG::qVector3::msZero.x;
    v6 = UFG::qVector3::msZero.y;
    v7 = UFG::qVector3::msZero.z;
    v8 = v4->y;
    v9 = v4->z;
    goal_position.x = v4->x;
    goal_position.y = v8;
    goal_position.z = v9;
    if ( nearestLane )
    {
      if ( nearestLane->mNode.mOffset )
        v10 = (UFG::RoadNetworkNode *)((char *)nearestLane + nearestLane->mNode.mOffset);
      else
        v10 = 0i64;
      UFG::RoadNetworkNode::GetTangent(v10, &result, nearestLane->mLaneIndex, nearestT);
      v5 = result.x;
      v6 = result.y;
      v7 = result.z;
    }
    v11 = UFG::TransitUtility::GetPlayerVehicleAiDriver();
    v12 = v11;
    if ( v11 )
    {
      v13 = (UFG::SimObjectVehicle *)v11->m_pSimObject;
      if ( v13 )
      {
        v14 = (UFG::RoadSpaceComponent *)v13->m_Components.p[24].m_pComponent;
        if ( v14 )
        {
          v15 = v3->mBits;
          if ( (*(unsigned int *)&v15 >> 1) & 1 || (*(unsigned int *)&v15 >> 3) & 1 )
          {
            v16 = UFG::SimObjectVehicle::GetComponent<UFG::VehicleSubjectComponent>(v13);
            if ( v16 )
            {
              v17 = UFG::WheeledVehicleManager::m_Instance->m_NavigationData;
              v18 = (signed __int64)&v14->mWayClient;
              numLanes = UFG::WheeledVehicleNavigationData::GetRoadNetworkGraph(
                           UFG::WheeledVehicleManager::m_Instance->m_NavigationData,
                           &v14->mWayClient);
              *(_QWORD *)&result.x = UFG::WheeledVehicleNavigationData::GetRoadWayFinder(v17, &v14->mWayClient);
              v63 = v14->mGuide.m_Attached;
              if ( v63 )
                UFG::RoadNetworkGuide::RemoveFromNetwork(&v14->mGuide);
              v19 = v14->mWayClient.m_AllowFootPaths;
              v14->mWayClient.m_AllowFootPaths = 1;
              v61 = v19;
              v20 = v14->mWayClient.m_LaneFlags;
              v14->mWayClient.m_LaneFlags = 64;
              v56 = v20;
              v62 = v12->m_bCanTurnAround;
              if ( !v12->m_RoadRuleFlagsLocked )
                v12->m_bCanTurnAround = 1;
              v21 = *(_QWORD *)v18;
              v22 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v16->vfptr[16].__vecDelDtor)(v16);
              v23 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v16->vfptr[17].__vecDelDtor)(v16);
              (*(void (__fastcall **)(UFG::VehicleWayFinderClient *, UFG::WheeledVehicleNavigationData *, __int64, __int64))(v21 + 48))(
                &v14->mWayClient,
                numLanes,
                v23,
                v22);
              UFG::WayFinder::FindWay(
                *(UFG::WayFinder **)&result.x,
                (UFG::WayFinderClient *)&v14->mWayClient.vfptr,
                &goal_position,
                0i64);
              UFG::WayFinder::Service(*(UFG::WayFinder **)&result.x, 0.0);
              v24 = ((__int64 (__fastcall *)(UFG::VehicleSubjectComponent *))v16->vfptr[17].__vecDelDtor)(v16);
              v5 = UFG::qVector3::msZero.x;
              v6 = UFG::qVector3::msZero.y;
              v7 = UFG::qVector3::msZero.z;
              v25 = *(float *)(v24 + 4);
              v26 = *(float *)(v24 + 8);
              goal_position.x = *(float *)v24;
              goal_position.y = v25;
              goal_position.z = v26;
              if ( v18 != -38 )
              {
                v27 = v14->mWayClient.m_NumWayEdges;
                if ( 0 != v27 && v27 > 1u )
                {
                  v28 = (unsigned int)v27 - 2;
                  for ( i = &v14->mWayClient.m_WayEdges[v28]; ; --i )
                  {
                    v30 = UFG::RoadNetworkResource::GetSegment(v57, *i);
                    v31 = (UFG::RoadNetworkGate *)v30;
                    if ( !v30 )
                      break;
                    if ( !((*(_DWORD *)&v30->mBits >> 1) & 1) && !((*(_DWORD *)&v30->mBits >> 3) & 1) )
                    {
                      v32 = UFG::RoadNetworkResource::GetSegment(
                              v57,
                              *(unsigned __int16 *)(v18 + 2i64 * (unsigned int)(v28 + 1) + 38));
                      if ( v32 )
                      {
                        v33 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(v31, 0);
                        v34 = (UFG::RoadNetworkGate *)UFG::RoadNetworkGate::GetIncomingConnection(v31, 1u);
                        LODWORD(numLanes) = 0;
                        UFG::RoadNetworkGate::GetLanesLeadingToNode(
                          v33,
                          (UFG::RoadNetworkNode *)&v32->mType,
                          &laneList,
                          (unsigned int *)&numLanes,
                          8u,
                          0xFFFFFFFF);
                        if ( (_DWORD)numLanes
                          || (UFG::RoadNetworkGate::GetLanesLeadingToNode(
                                v34,
                                (UFG::RoadNetworkNode *)&v32->mType,
                                &laneList,
                                (unsigned int *)&numLanes,
                                8u,
                                0xFFFFFFFF),
                              (_DWORD)numLanes) )
                        {
                          v35 = laneList;
                          if ( UFG::RoadNetworkLane::IsReversedInNode(laneList) )
                          {
                            if ( (_DWORD)numLanes )
                            {
                              v36 = &laneList;
                              v37 = (unsigned int)numLanes;
                              do
                              {
                                v38 = *v36;
                                ++v36;
                                if ( v38->mLaneIndex > v35->mLaneIndex )
                                  v35 = v38;
                                --v37;
                              }
                              while ( v37 );
                            }
                          }
                          else if ( (_DWORD)numLanes )
                          {
                            v39 = &laneList;
                            v40 = (unsigned int)numLanes;
                            do
                            {
                              v41 = *v39;
                              ++v39;
                              if ( v41->mLaneIndex < v35->mLaneIndex )
                                v35 = v41;
                              --v40;
                            }
                            while ( v40 );
                          }
                          v42 = 3.0 / UFG::RoadNetworkLane::GetLength(v35);
                          if ( v42 <= 0.0 )
                          {
                            v42 = 0.0;
                          }
                          else if ( v42 >= 1.0 )
                          {
                            v42 = *(float *)&FLOAT_1_0;
                          }
                          v43 = 1.0 - v42;
                          if ( (float)(1.0 - v42) <= 0.0 )
                          {
                            v43 = 0.0;
                          }
                          else if ( v43 >= 1.0 )
                          {
                            v43 = *(float *)&FLOAT_1_0;
                          }
                          v44 = UFG::RoadNetworkLane::GetPos(v35, &result, v43);
                          v45 = v44->y;
                          v46 = v44->z;
                          goal_position.x = v44->x;
                          goal_position.y = v45;
                          goal_position.z = v46;
                          v47 = (UFG::RoadNetworkNode *)((char *)v35 + v35->mNode.mOffset);
                          if ( !v35->mNode.mOffset )
                            v47 = 0i64;
                          UFG::RoadNetworkNode::GetTangent(v47, &result, v35->mLaneIndex, v43);
                          v5 = result.x;
                          v6 = result.y;
                          v7 = result.z;
                        }
                      }
                      break;
                    }
                    LODWORD(v28) = v28 - 1;
                  }
                }
              }
              v14->mWayClient.m_AllowFootPaths = v61;
              v14->mWayClient.m_LaneFlags = v56;
              if ( !v12->m_RoadRuleFlagsLocked )
                v12->m_bCanTurnAround = v62;
              if ( v63 )
              {
                v48 = v14->m_pSimObject;
                if ( v48 )
                  v1 = v48->m_pTransformNodeComponent;
                UFG::TransformNodeComponent::UpdateWorldTransform(v1);
                UFG::RoadSpaceComponent::AttachToRoadNetwork(v14, (UFG::qVector3 *)&v1->mWorldTransform.v3, 0i64);
              }
              (*(void (__fastcall **)(UFG::VehicleWayFinderClient *))(*(_QWORD *)v18 + 88i64))(&v14->mWayClient);
            }
          }
          v49 = (float)((float)(v6 * v6) + (float)(v5 * v5)) + (float)(v7 * v7);
          if ( v49 > 9.9999994e-11 )
          {
            if ( v49 == 0.0 )
              v50 = 0.0;
            else
              v50 = 1.0 / fsqrt(v49);
            v5 = v5 * v50;
            v6 = v6 * v50;
            v7 = v7 * v50;
          }
          v51 = goal_position.y;
          v52 = goal_position.z;
          v14->mDestinationPosition.x = goal_position.x;
          v14->mDestinationPosition.y = v51;
          v14->mDestinationPosition.z = v52;
          v14->mDestinationDirection.x = v5;
          v14->mDestinationDirection.y = v6;
          v14->mDestinationDirection.z = v7;
        }
      }
    }
  }
}

// File Line: 220
// RVA: 0x656C30
void UFG::TransitUtility::OnExitMap(void)
{
  UFG::AiDriverComponent *v0; // rax
  UFG::AiDriverComponent *v1; // rbx
  UFG::SimObject *v2; // rcx
  UFG::RoadSpaceComponent *v3; // rbp
  bool v4; // zf
  UFG::TransformNodeComponent *v5; // rdi
  float *v6; // rax
  unsigned int v7; // er14
  UFG::SimObject *v8; // rax

  v0 = UFG::TransitUtility::GetPlayerVehicleAiDriver();
  v1 = v0;
  if ( v0 )
  {
    v2 = v0->m_pSimObject;
    if ( v2 )
    {
      v3 = (UFG::RoadSpaceComponent *)v2->m_Components.p[24].m_pComponent;
      if ( v3 )
      {
        v4 = v0->m_DrivingRole == 4;
        v0->m_IsAmbient = 0;
        if ( !v4 )
        {
          v0->m_DrivingRole = 4;
          if ( !v0->m_RoadRuleFlagsLocked )
          {
            v0->m_bAvoidPeds = 1;
            v0->m_bAllowedToPass = 1;
            v0->m_bStayOffSidewalk = 1;
            v0->m_bRespectSpeedLimit = 1;
            v0->m_bCanTurnAround = 0;
          }
          v0->m_bSavedAvoidPeds = v0->m_bAvoidPeds;
        }
        v5 = 0i64;
        if ( v0->m_DrivingMode != 2 )
        {
          v6 = (float *)v0->m_pRoadSpace.m_pSimComponent;
          v1->m_DrivingMode = 2;
          v1->m_fReactionTime = 0.0;
          v1->m_fDelayedStopDecel = 0.0;
          v1->mModeSteeringLockEnabled = 0;
          v1->mModeGasBrakeLockEnabled = 0;
          v1->m_bIgnoreArrivalDirection = 0;
          if ( !v6
            || (float)((float)((float)(v6[415] * v6[415]) + (float)(v6[416] * v6[416])) + (float)(v6[417] * v6[417])) < 0.0000010000001 )
          {
            v1->m_bIgnoreArrivalDirection = 1;
          }
        }
        if ( !v1->m_RoadRuleFlagsLocked )
          v1->m_ObeyTrafficLights = 0;
        v7 = 0;
        if ( v3 != (UFG::RoadSpaceComponent *)-552i64 )
        {
          v7 = v3->mWayClient.m_LaneFlags;
          v3->mWayClient.m_LaneFlags = 8;
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
          v8 = v3->m_pSimObject;
          if ( v8 )
            v5 = v8->m_pTransformNodeComponent;
          UFG::TransformNodeComponent::UpdateWorldTransform(v5);
          UFG::RoadSpaceComponent::AttachToRoadNetwork(v3, (UFG::qVector3 *)&v5->mWorldTransform.v3, 0i64);
        }
        if ( v3 != (UFG::RoadSpaceComponent *)-552i64 )
          v3->mWayClient.m_LaneFlags = v7;
      }
    }
  }
}

// File Line: 283
// RVA: 0x6577B0
void UFG::TransitUtility::PlaceTransitVehicle(void)
{
  UFG::AiDriverComponent *v0; // rax
  UFG::SimObjectVehicle *v1; // rbx
  UFG::SimComponentHolder *v2; // rax
  UFG::TransformNodeComponent *v3; // rdi
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  UFG::allocator::free_link *v8; // rax
  float v9; // xmm6_4
  UFG::SimComponent *v10; // rdi
  UFG::RoadNetworkGuide *v11; // rdi
  UFG::SimObject *v12; // rcx
  UFG::SimComponent *v13; // rax
  UFG::qVector3 position; // [rsp+48h] [rbp-50h]
  UFG::qVector3 out; // [rsp+58h] [rbp-40h]
  UFG::qVector3 dir; // [rsp+68h] [rbp-30h]

  v0 = UFG::TransitUtility::GetPlayerVehicleAiDriver();
  if ( v0 )
  {
    v1 = (UFG::SimObjectVehicle *)v0->m_pSimObject;
    if ( v1 )
    {
      v2 = v1->m_Components.p;
      v3 = (UFG::TransformNodeComponent *)v2[2].m_pComponent;
      if ( v3 )
      {
        UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2[2].m_pComponent);
        v4 = v3->mWorldTransform.v3.y;
        v5 = v3->mWorldTransform.v3.z;
        position.x = v3->mWorldTransform.v3.x;
        position.y = v4;
        position.z = v5;
        UFG::TransformNodeComponent::UpdateWorldTransform(v3);
        v6 = v3->mWorldTransform.v0.y;
        v7 = v3->mWorldTransform.v0.z;
        dir.x = v3->mWorldTransform.v0.x;
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
              v1->mNode.mUID,
              0,
              UFG::TeleportEvent::m_Name,
              &UFG::qVector3::msDirUp);
          UFG::EventDispatcher::DispatchEvent(&UFG::EventDispatcher::mInstance, (UFG::Event *)v8);
          v9 = FLOAT_2_0;
          v10 = v1->m_Components.p[24].m_pComponent;
          if ( v10 )
          {
            v11 = (UFG::RoadNetworkGuide *)&v10[5].m_BoundComponentHandles.mNode.mNext;
            if ( v11 )
            {
              if ( (unsigned __int8)UFG::RoadNetworkGuide::IsCurrentLocationValid(v11)
                && (float)(v11->m_SpeedLimit * 0.80000001) >= 2.0 )
              {
                v9 = v11->m_SpeedLimit * 0.80000001;
              }
            }
          }
          UFG::VehicleUtility::OverrideForwardSpeedKPH(v1, v9 * 3.5999999);
        }
        v12 = UFG::Director::Get()->mCurrentCamera->m_pSimObject;
        if ( v12 )
        {
          v13 = UFG::SimObject::GetComponentOfType(v12, UFG::ChaseCameraComponent::_TypeUID);
          if ( v13 )
            ((void (__fastcall *)(UFG::SimComponent *))v13->vfptr[14].__vecDelDtor)(v13);
        }
      }
    }
  }
}

// File Line: 327
// RVA: 0x64EEA0
UFG::AiDriverComponent *__fastcall UFG::TransitUtility::GetPlayerVehicleAiDriver()
{
  unsigned __int16 v0; // dx
  UFG::CharacterOccupantComponent *v1; // rax
  UFG::SimObjectCVBase *v2; // rax
  UFG::AiDriverComponent *result; // rax

  if ( LocalPlayer
    && ((v0 = LocalPlayer->m_Flags, !((v0 >> 14) & 1)) ? ((v0 & 0x8000u) == 0 ? (!((v0 >> 13) & 1) ? (!((v0 >> 12) & 1) ? (v1 = (UFG::CharacterOccupantComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID)) : (v1 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v1 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v1 = (UFG::CharacterOccupantComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&LocalPlayer->vfptr, UFG::CharacterOccupantComponent::_TypeUID))) : (v1 = (UFG::CharacterOccupantComponent *)LocalPlayer->m_Components.p[44].m_pComponent),
        v1 && (v2 = (UFG::SimObjectCVBase *)UFG::CharacterOccupantComponent::GetCurrentVehicle(v1)) != 0i64) )
  {
    result = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v2);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

