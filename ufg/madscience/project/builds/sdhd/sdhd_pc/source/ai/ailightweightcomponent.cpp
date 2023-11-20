// File Line: 37
// RVA: 0x3632F0
const char *__fastcall UFG::AILightWeightComponent::GetTypeName(UFG::AILightWeightComponent *this)
{
  return "AILightWeightComponent";
}

// File Line: 47
// RVA: 0x32B700
void __fastcall UFG::AILightWeightComponent::AILightWeightComponent(UFG::AILightWeightComponent *this, unsigned int name_uid)
{
  UFG::AILightWeightComponent *v2; // rdi
  signed __int64 v3; // rbx
  signed __int64 v4; // [rsp+68h] [rbp+20h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AILightWeightComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v2->m_pTransformNodeComponent);
  v3 = (signed __int64)&v2->mWanderData;
  `eh vector constructor iterator(
    &v2->mWanderData,
    0x78ui64,
    2,
    (void (__fastcall *)(void *))UFG::SidewalkWanderData::GoalInfo::GoalInfo);
  v4 = (signed __int64)&v2->mWanderData.mCrosswalkLanes;
  *(_QWORD *)(v4 + 32) = 0i64;
  *(_QWORD *)(v4 + 24) = 0i64;
  *(_QWORD *)(v3 + 312) = 0i64;
  *(_QWORD *)(v3 + 304) = 0i64;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::AILightWeightComponent::_AILightWeightComponentTypeUID,
    "AILightWeightComponent");
  UFG::SidewalkWanderData::ClearData(&v2->mWanderData);
}

// File Line: 73
// RVA: 0x378650
void __fastcall UFG::AILightWeightComponent::OnAttach(UFG::AILightWeightComponent *this, UFG::SimObject *object)
{
  UFG::AILightWeightComponent *v2; // rbx

  v2 = this;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->m_pTransformNodeComponent,
    object);
  v2->mAIMode = 0;
}

// File Line: 84
// RVA: 0x379C70
void __fastcall UFG::AILightWeightComponent::OnDetach(UFG::AILightWeightComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v1; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx

  v1 = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    v2 = this->m_pTransformNodeComponent.mNext;
    v3 = v1->mPrev;
    v3->mNext = v2;
    v2->mPrev = v3;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->m_Changed = 1;
    v1->m_pSimComponent = 0i64;
    v1->m_pSimObject = 0i64;
  }
  else
  {
    if ( this->m_pTransformNodeComponent.m_pSimObject
      && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->mPrev != v1
       || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)this->m_pTransformNodeComponent.mNext != &this->m_pTransformNodeComponent) )
    {
      v4 = this->m_pTransformNodeComponent.mNext;
      v5 = v1->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
      v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
      v1->m_pSimObject = 0i64;
    }
    v1->m_Changed = 1;
  }
}

// File Line: 89
// RVA: 0x389A00
void __fastcall UFG::AILightWeightComponent::TeleportEventHandler(UFG::AILightWeightComponent *this, UFG::Event *this_event)
{
  this->mAIMode = 0;
}

// File Line: 95
// RVA: 0x365240
void __fastcall UFG::AILightWeightComponent::Init(UFG::AILightWeightComponent *this)
{
  bool v1; // zf
  UFG::AILightWeightComponent *v2; // rdi
  UFG::SimComponent *v3; // rbx
  unsigned int v4; // er9
  float v5; // xmm1_4
  float v6; // xmm0_4
  UFG::TransformNodeComponent *v7; // rbx
  UFG::AISidewalkEdge_Game *v8; // r15
  char *v9; // rsi
  char *v10; // rax
  UFG::qVector3 *v11; // r12
  __int64 v12; // rax
  signed __int64 v13; // r8
  float v14; // xmm4_4
  float v15; // xmm3_4
  float v16; // xmm5_4
  float v17; // xmm2_4
  signed __int64 v18; // rax
  char *v19; // rax
  UFG::qVector3 *v20; // rdx
  float v21; // xmm0_4
  float v22; // xmm8_4
  UFG::qVector3 *v23; // r8
  UFG::SidewalkWanderData *v24; // rcx
  __int64 v25; // rax
  UFG::AISidewalkEdge_Game *v26; // rax
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm12_4
  float v30; // xmm13_4
  float v31; // xmm14_4
  __int128 v32; // xmm5
  __m128 v33; // xmm8
  __int128 v34; // xmm9
  __m128 v35; // xmm2
  float v36; // xmm1_4
  __m128 v37; // xmm3
  float v38; // xmm8_4
  __m128 v39; // xmm2
  float v40; // xmm4_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm4_4
  float v44; // xmm2_4
  float v45; // xmm1_4
  __int128 v46; // xmm10
  float v47; // xmm11_4
  __m128 v48; // xmm3
  float v49; // xmm11_4
  __m128 v50; // xmm2
  float v51; // xmm1_4
  float v52; // xmm3_4
  float v53; // xmm0_4
  __m128 v54; // xmm4
  float v55; // xmm3_4
  float v56; // xmm2_4
  __m128 v57; // xmm5
  float v58; // xmm6_4
  UFG::TransformNodeComponent *v59; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-D0h]
  UFG::qMatrix44 m; // [rsp+30h] [rbp-C0h]

  v1 = this->m_pTransformNodeComponent.m_pSimComponent == 0i64;
  v2 = this;
  this->mAIMode = 2;
  if ( !v1 )
  {
    v3 = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v3);
    v4 = 251;
    v5 = *(float *)&v3[2].m_BoundComponentHandles.mNode.mNext;
    v6 = *((float *)&v3[2].m_BoundComponentHandles.mNode.mPrev + 1);
    v2->mInitPos.x = *(float *)&v3[2].m_BoundComponentHandles.mNode.mPrev;
    v2->mInitPos.z = v5;
    v2->mInitPos.y = v6;
    if ( v2->mWanderData.mAllowedToUseCrosswalks )
      v4 = 255;
    UFG::AISidewalkGraph::FindClosestSidewalkConnection(
      &v2->mInitPos,
      30.0,
      (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)&v2->mWanderData,
      v4);
    if ( v2->mWanderData.mGoals[0].mpSidewalkEdge.mPtr )
    {
      v7 = (UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(v7);
      v8 = v2->mWanderData.mGoals[0].mpSidewalkEdge.mPtr;
      v9 = 0i64;
      if ( v8->mpStartNodeHandle.mOffset )
        v10 = (char *)v8 + v8->mpStartNodeHandle.mOffset;
      else
        v10 = 0i64;
      v11 = (UFG::qVector3 *)*((_QWORD *)v10 + 5);
      v12 = v8->mpEndNodeHandle.mOffset;
      if ( v12 )
        v13 = (signed __int64)&v8->mpEndNodeHandle + v12;
      else
        v13 = 0i64;
      UFG::qNearestSegPoint(&result, v11, *(UFG::qVector3 **)(v13 + 40), &v2->mInitPos);
      v14 = v2->mInitPos.x;
      v15 = v2->mInitPos.y;
      v16 = v2->mInitPos.z;
      v17 = (float)((float)((float)(v11->y - v15) * v7->mWorldTransform.v0.y)
                  + (float)((float)(v11->x - v14) * v7->mWorldTransform.v0.x))
          + (float)((float)(v11->z - v16) * v7->mWorldTransform.v0.z);
      if ( v17 <= 0.0 )
      {
        v25 = v8->mpEndNodeHandle.mOffset;
        if ( !v25 )
          goto LABEL_13;
        v18 = v25 + 8;
      }
      else
      {
        v18 = v8->mpStartNodeHandle.mOffset;
        if ( !v8->mpStartNodeHandle.mOffset )
        {
LABEL_13:
          v19 = 0i64;
LABEL_14:
          v20 = (UFG::qVector3 *)*((_QWORD *)v19 + 5);
          v21 = *(float *)&FLOAT_1_0;
          if ( v20 )
            v21 = v20[1].z;
          v22 = result.x;
          v23 = &v2->mInitPos;
          v24 = &v2->mWanderData;
          if ( (float)((float)((float)((float)(v15 - result.y) * (float)(v15 - result.y))
                             + (float)((float)(v14 - result.x) * (float)(v14 - result.x)))
                     + (float)((float)(v16 - result.z) * (float)(v16 - result.z))) >= (float)(v21 * v21) )
          {
            UFG::SidewalkWanderData::SetDestinationPos(v24, &result, v23);
            v2->mWanderData.mIsDestinationSegment = 1;
          }
          else
          {
            UFG::SidewalkWanderData::SetDestinationPos(v24, v20, v23);
            v2->mWanderData.mIsDestinationSegment = 0;
          }
          v26 = v2->mWanderData.mGoals[0].mpSidewalkEdge.mPtr;
          if ( v17 <= 0.0 )
            v26 = (UFG::AISidewalkEdge_Game *)((char *)v26 + 8);
          if ( v26->mpStartNodeHandle.mOffset )
            v9 = (char *)v26 + v26->mpStartNodeHandle.mOffset;
          UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
            &v2->mWanderData.mGoals[0].mpDestinationNode,
            *((_DWORD *)v9 + 9),
            *((_DWORD *)v9 + 6),
            *((unsigned __int16 *)v9 + 16));
          if ( (float)((float)((float)((float)(v2->mInitPos.y - v2->mWanderData.mGoals[0].mPosition.y)
                                     * (float)(v2->mInitPos.y - v2->mWanderData.mGoals[0].mPosition.y))
                             + (float)((float)(v2->mInitPos.x - v2->mWanderData.mGoals[0].mPosition.x)
                                     * (float)(v2->mInitPos.x - v2->mWanderData.mGoals[0].mPosition.x)))
                     + (float)((float)(v2->mInitPos.z - v2->mWanderData.mGoals[0].mPosition.z)
                             * (float)(v2->mInitPos.z - v2->mWanderData.mGoals[0].mPosition.z))) < 0.001 )
          {
            result.x = v22 + 0.050000001;
            UFG::SidewalkWanderData::SetDestinationPos(&v2->mWanderData, &result, &v2->mInitPos);
          }
          v27 = v2->mWanderData.mPreviousDesiredDirection.x;
          v28 = v2->mWanderData.mPreviousDesiredDirection.y;
          v2->mTravelDirection.z = v2->mWanderData.mPreviousDesiredDirection.z;
          v2->mTravelDirection.x = v27;
          v2->mTravelDirection.y = v28;
          v34 = LODWORD(v2->mInitPos.z);
          v32 = LODWORD(v2->mWanderData.mGoals[0].mPosition.x);
          v33 = (__m128)LODWORD(v2->mWanderData.mGoals[0].mPosition.y);
          v29 = v2->mInitPos.x;
          v30 = v2->mInitPos.y;
          v31 = *(float *)&v34;
          *(float *)&v32 = *(float *)&v32 - v29;
          v33.m128_f32[0] = v33.m128_f32[0] - v30;
          *(float *)&v34 = *(float *)&v34 - *(float *)&v34;
          v35 = v33;
          v35.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v33.m128_f32[0]) + (float)(*(float *)&v32 * *(float *)&v32))
                          + (float)(*(float *)&v34 * *(float *)&v34);
          if ( v35.m128_f32[0] == 0.0 )
            v36 = 0.0;
          else
            v36 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
          v37 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
          *(float *)&v32 = *(float *)&v32 * v36;
          v38 = v33.m128_f32[0] * v36;
          *(float *)&v34 = *(float *)&v34 * v36;
          m.v0.w = 0.0;
          v39 = v37;
          LODWORD(m.v0.x) = v32;
          m.v0.y = v38;
          LODWORD(m.v0.z) = v34;
          v39.m128_f32[0] = (float)((float)(v37.m128_f32[0] * v37.m128_f32[0])
                                  + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                          + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
          if ( v39.m128_f32[0] == 0.0 )
            v40 = 0.0;
          else
            v40 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v39));
          v41 = v40;
          v42 = v40;
          v43 = v40 * UFG::qVector3::msDirUp.z;
          v44 = v42 * UFG::qVector3::msDirUp.x;
          v45 = v41 * UFG::qVector3::msDirUp.y;
          v46 = v34;
          v48 = (__m128)v32;
          *(float *)&v46 = (float)(*(float *)&v34 * v45) - (float)(v38 * v43);
          v47 = v38 * v44;
          v48.m128_f32[0] = (float)(*(float *)&v32 * v43) - (float)(*(float *)&v34 * v44);
          v50 = v48;
          v49 = v47 - (float)(*(float *)&v32 * v45);
          v50.m128_f32[0] = (float)((float)(v48.m128_f32[0] * v48.m128_f32[0]) + (float)(*(float *)&v46 * *(float *)&v46))
                          + (float)(v49 * v49);
          if ( v50.m128_f32[0] == 0.0 )
            v51 = 0.0;
          else
            v51 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v50));
          *(float *)&v46 = *(float *)&v46 * v51;
          v52 = v48.m128_f32[0] * v51;
          m.v1.w = 0.0;
          v54 = (__m128)v46;
          m.v1.z = v49 * v51;
          LODWORD(m.v1.x) = v46;
          m.v1.y = v52;
          v53 = v52 * *(float *)&v34;
          v54.m128_f32[0] = (float)(*(float *)&v46 * *(float *)&v34) - (float)((float)(v49 * v51) * *(float *)&v32);
          v55 = (float)(v52 * *(float *)&v32) - (float)(*(float *)&v46 * v38);
          v56 = (float)((float)(v49 * v51) * v38) - v53;
          v57 = v54;
          v57.m128_f32[0] = (float)((float)(v54.m128_f32[0] * v54.m128_f32[0]) + (float)(v56 * v56))
                          + (float)(v55 * v55);
          if ( v57.m128_f32[0] == 0.0 )
            v58 = 0.0;
          else
            v58 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v57));
          v59 = (UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pSimComponent;
          m.v3.x = v29;
          m.v3.y = v30;
          m.v2.w = 0.0;
          m.v3.w = 1.0;
          m.v3.z = v31;
          m.v2.x = v56 * v58;
          m.v2.y = v54.m128_f32[0] * v58;
          m.v2.z = v55 * v58;
          UFG::TransformNodeComponent::SetWorldTransform(v59, &m);
          return;
        }
      }
      v19 = (char *)v8 + v18;
      goto LABEL_14;
    }
  }
}

// File Line: 200
// RVA: 0x388020
void __fastcall UFG::AILightWeightComponent::SetWanderData(UFG::AILightWeightComponent *this, UFG::SidewalkWanderData *data)
{
  UFG::SidewalkWanderData::operator=(&this->mWanderData, data);
}

// File Line: 255
// RVA: 0x34A560
char __fastcall UFG::AILightWeightComponent::CalculateDestination(UFG::AILightWeightComponent *this)
{
  UFG::SidewalkWanderData *sidewalkWanderData; // rbp
  UFG::AILightWeightComponent *v2; // rsi
  char result; // al
  UFG::SimComponent *v4; // rbx
  UFG::SimObjectGame *v5; // rcx
  bool isGroupLeader; // r14
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  float v9; // xmm0_4
  UFG::SimComponent *v10; // rdi
  UFG::TransformNodeComponent *v11; // rcx
  UFG::SimComponent *v12; // rbx
  UFG::SimComponent *v13; // rbx
  UFG::qVector3 pDestinationPoint; // [rsp+40h] [rbp-28h]

  sidewalkWanderData = &this->mWanderData;
  v2 = this;
  if ( !this->mWanderData.mGoals[0].mpSidewalkEdge.mPtr )
    return 0;
  if ( this->mWanderData.mIsDestinationSegment && this->mWanderData.mGoals[0].mpDestinationNode.mPtr )
  {
    v4 = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent);
    UFG::SidewalkWanderData::SetDestinationPos(
      sidewalkWanderData,
      &v2->mWanderData.mGoals[0].mpDestinationNode.mPtr->mPos,
      (UFG::qVector3 *)&v4[2].m_BoundComponentHandles);
    v2->mWanderData.mIsDestinationSegment = 0;
    result = 1;
  }
  else
  {
    v5 = (UFG::SimObjectGame *)this->m_pSimObject;
    isGroupLeader = 0;
    if ( v5 )
    {
      v7 = v5->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::GroupComponent::_TypeUID);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::GroupComponent::_TypeUID);
        else
          v8 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::GroupComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::GroupComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::GroupComponent::_TypeUID);
      }
      if ( v8 )
        isGroupLeader = *(_QWORD *)&v8[3].m_Flags && LODWORD(v8[1].m_BoundComponentHandles.mNode.mNext);
    }
    pDestinationPoint.x = UFG::qVector3::msZero.x;
    v9 = UFG::qVector3::msZero.z;
    pDestinationPoint.y = UFG::qVector3::msZero.y;
    v2->mWanderData.mIsDestinationSegment = 0;
    v10 = v2->m_pTransformNodeComponent.m_pSimComponent;
    v11 = (UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pSimComponent;
    pDestinationPoint.z = v9;
    UFG::TransformNodeComponent::UpdateWorldTransform(v11);
    v12 = v2->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pSimComponent);
    if ( UFG::AISidewalkGraph::CalculateDestinationPoint(
           (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)sidewalkWanderData,
           &v2->mWanderData.mGoals[0].mpDestinationNode,
           &pDestinationPoint,
           (UFG::qVector3 *)&v12[2].m_BoundComponentHandles,
           (UFG::qVector3 *)&v10[2],
           isGroupLeader,
           0i64,
           sidewalkWanderData)
      && pDestinationPoint.x != 0.0 )
    {
      v13 = v2->m_pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pSimComponent);
      UFG::SidewalkWanderData::SetDestinationPos(
        sidewalkWanderData,
        &pDestinationPoint,
        (UFG::qVector3 *)&v13[2].m_BoundComponentHandles);
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

// File Line: 311
// RVA: 0x374DC0
char __fastcall UFG::AILightWeightComponent::MaybeReversePath(UFG::AILightWeightComponent *this, UFG::qVector3 *player_pos, UFG::qVector3 *pos, bool should_tend_towards_player)
{
  UFG::qVector3 *v4; // r12
  UFG::AILightWeightComponent *v5; // rdi
  UFG::AISidewalkEdge_Game *v6; // rax
  char *v7; // rax
  __int64 v8; // rax
  UFG::qResourceInventory *v9; // rax
  UFG::qResourceWarehouse *v10; // rax
  signed int v11; // edx
  unsigned int v12; // er15
  unsigned int v13; // esi
  UFG::qResourceInventory *v14; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  UFG::AISidewalkEdge_Game *v18; // rax
  __int64 v19; // rcx
  signed __int64 v20; // rax
  __int64 v21; // rax
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  unsigned int v24; // er15
  unsigned int v25; // esi
  UFG::qResourceInventory *v26; // rax
  UFG::qResourceWarehouse *v27; // rax
  UFG::qResourceInventory *v28; // rax
  UFG::qResourceWarehouse *v29; // rax
  float v30; // xmm1_4
  float v31; // xmm2_4
  UFG::qResourceInventory *v32; // rax
  UFG::qResourceWarehouse *v33; // rax
  UFG::qResourceInventory *v35; // rax
  UFG::qResourceWarehouse *v36; // rax
  UFG::qResourceHandle v37; // [rsp+28h] [rbp-38h]
  int v38; // [rsp+48h] [rbp-18h]
  unsigned int objUID; // [rsp+4Ch] [rbp-14h]
  __int64 v40; // [rsp+50h] [rbp-10h]

  v4 = pos;
  v5 = this;
  if ( (float)((float)((float)((float)(player_pos->y - pos->y) * this->mTravelDirection.y)
                     + (float)((float)(player_pos->x - pos->x) * this->mTravelDirection.x))
             + (float)((float)(player_pos->z - pos->z) * this->mTravelDirection.z)) > 0.0 == should_tend_towards_player
    || !this->mWanderData.mGoals[0].mpDestinationNode.mPtr
    || !this->mWanderData.mGoals[0].mpSidewalkEdge.mPtr )
  {
    return 0;
  }
  UFG::qResourceHandle::qResourceHandle(&v37);
  v38 = 0xFFFF;
  objUID = -1;
  v40 = 0i64;
  v37.mNameUID = -1;
  v6 = v5->mWanderData.mGoals[0].mpSidewalkEdge.mPtr;
  if ( v6->mpStartNodeHandle.mOffset )
    v7 = (char *)v6 + v6->mpStartNodeHandle.mOffset;
  else
    v7 = 0i64;
  v8 = *((_QWORD *)v7 + 5);
  if ( v8 )
  {
    v12 = *(_DWORD *)(v8 + 16);
    v13 = *(_DWORD *)(v8 + 12);
    v40 = 0i64;
    v14 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v15 = UFG::qResourceWarehouse::Instance();
      v14 = UFG::qResourceWarehouse::GetInventory(v15, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v14;
    }
    UFG::qResourceHandle::Close(&v37, v14);
    LOWORD(v38) = -1;
    objUID = v13;
    v16 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v17 = UFG::qResourceWarehouse::Instance();
      v16 = UFG::qResourceWarehouse::GetInventory(v17, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v16;
    }
    UFG::qResourceHandle::Init(&v37, 0x43E99F7Eu, v12, v16);
    v11 = objUID;
  }
  else
  {
    v40 = 0i64;
    v9 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v10 = UFG::qResourceWarehouse::Instance();
      v9 = UFG::qResourceWarehouse::GetInventory(v10, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v9;
    }
    UFG::qResourceHandle::Close(&v37, v9);
    LOWORD(v38) = -1;
    v11 = -1;
    objUID = -1;
    v37.mNameUID = -1;
    v40 = 0i64;
  }
  if ( v5->mWanderData.mGoals[0].mpDestinationNode.mObjUID == v11 )
  {
    v18 = v5->mWanderData.mGoals[0].mpSidewalkEdge.mPtr;
    v19 = v18->mpEndNodeHandle.mOffset;
    if ( v19 )
      v20 = (signed __int64)&v18->mpEndNodeHandle + v19;
    else
      v20 = 0i64;
    v21 = *(_QWORD *)(v20 + 40);
    if ( !v21 )
    {
      v40 = 0i64;
      v22 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
      {
        v23 = UFG::qResourceWarehouse::Instance();
        v22 = UFG::qResourceWarehouse::GetInventory(v23, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v22;
      }
      UFG::qResourceHandle::Close(&v37, v22);
      LOWORD(v38) = -1;
      objUID = -1;
      v37.mNameUID = -1;
      v40 = 0i64;
      goto LABEL_33;
    }
    v24 = *(_DWORD *)(v21 + 16);
    v25 = *(_DWORD *)(v21 + 12);
    v40 = 0i64;
    v26 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v27 = UFG::qResourceWarehouse::Instance();
      v26 = UFG::qResourceWarehouse::GetInventory(v27, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v26;
    }
    UFG::qResourceHandle::Close(&v37, v26);
    LOWORD(v38) = -1;
    objUID = v25;
    v28 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v29 = UFG::qResourceWarehouse::Instance();
      v28 = UFG::qResourceWarehouse::GetInventory(v29, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v28;
    }
    UFG::qResourceHandle::Init(&v37, 0x43E99F7Eu, v24, v28);
    v11 = objUID;
  }
  if ( !v40 )
  {
LABEL_33:
    v35 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v36 = UFG::qResourceWarehouse::Instance();
      v35 = UFG::qResourceWarehouse::GetInventory(v36, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v35;
    }
    UFG::qResourceHandle::Close(&v37, v35);
    UFG::qResourceHandle::~qResourceHandle(&v37);
    return 0;
  }
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
    &v5->mWanderData.mGoals[0].mpDestinationNode,
    v11,
    v37.mNameUID,
    (unsigned __int16)v38);
  UFG::SidewalkWanderData::SetDestinationPos(
    &v5->mWanderData,
    &v5->mWanderData.mGoals[0].mpDestinationNode.mPtr->mPos,
    v4);
  v30 = v4->y;
  v31 = v4->z;
  v5->mInitPos.x = v4->x;
  v5->mInitPos.y = v30;
  v5->mInitPos.z = v31;
  v32 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v33 = UFG::qResourceWarehouse::Instance();
    v32 = UFG::qResourceWarehouse::GetInventory(v33, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v32;
  }
  UFG::qResourceHandle::Close(&v37, v32);
  UFG::qResourceHandle::~qResourceHandle(&v37);
  return 1;
}

// File Line: 350
// RVA: 0x38B670
char __fastcall UFG::AILightWeightComponent::Update(UFG::AILightWeightComponent *this, float delta_sec, UFG::PedSpawningInfo *pedInfo)
{
  UFG::PedSpawningInfo *v3; // rsi
  float v4; // xmm7_4
  UFG::AILightWeightComponent *v5; // rdi
  UFG::SimObjectCharacter *v6; // rbx
  unsigned __int16 v7; // cx
  float *v8; // rbx
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  UFG::TransformNodeComponent *v12; // rbx
  float v13; // xmm8_4
  float v14; // xmm6_4
  float v15; // xmm9_4
  float v16; // xmm8_4
  float v17; // xmm6_4
  float v18; // xmm9_4
  bool v19; // al
  float *v20; // rbx
  __m128 v21; // xmm9
  float v22; // xmm10_4
  UFG::TransformNodeComponent *v23; // rcx
  float v24; // xmm6_4
  float v25; // xmm14_4
  float v26; // xmm13_4
  float v27; // xmm15_4
  float v28; // xmm11_4
  __m128 v29; // xmm12
  float v30; // xmm10_4
  __m128 v31; // xmm8
  float v32; // xmm1_4
  float v33; // xmm3_4
  float v35; // xmm9_4
  __int128 v36; // xmm8
  __int128 v37; // xmm6
  float v38; // xmm12_4
  float v39; // xmm13_4
  float v40; // xmm14_4
  float v41; // xmm10_4
  __m128 v42; // xmm11
  float v43; // xmm9_4
  __m128 v44; // xmm7
  float v45; // xmm1_4
  float v46; // xmm6_4
  __m128 v47; // xmm2
  float v48; // xmm1_4
  __m128 v49; // xmm9
  float v50; // xmm8_4
  float v51; // xmm7_4
  __m128 v52; // xmm2
  __int128 v53; // xmm5
  __int128 v54; // xmm1
  float v55; // xmm2_4
  float v56; // xmm5_4
  float v57; // xmm2_4
  float v58; // xmm11_4
  __int128 v59; // xmm9
  __m128 v60; // xmm10
  float v61; // xmm11_4
  __m128 v62; // xmm2
  float v63; // xmm1_4
  float v64; // xmm2_4
  __m128 v65; // xmm5
  float v66; // xmm6_4
  __m128 v67; // xmm7
  float v68; // xmm3_4
  UFG::TransformNodeComponent *v69; // rcx
  float v70; // xmm6_4
  __m128 v71; // xmm2
  float v72; // xmm1_4
  __m128 v73; // xmm5
  float v74; // xmm6_4
  float v75; // xmm9_4
  float v76; // xmm11_4
  __m128 v77; // xmm2
  float v78; // xmm0_4
  __m128 v79; // xmm2
  __m128 v80; // xmm1
  float v81; // xmm10_4
  float v82; // xmm10_4
  __m128 v83; // xmm12
  float v84; // xmm10_4
  __m128 v85; // xmm5
  float v86; // xmm1_4
  float v87; // xmm2_4
  float v88; // xmm5_4
  __m128 v89; // xmm8
  float v90; // xmm2_4
  __m128 v91; // xmm6
  float v92; // xmm3_4
  UFG::TransformNodeComponent *v93; // rcx
  float v94; // xmm7_4
  UFG::TransformNodeComponent *v95; // rcx
  float v96; // xmm2_4
  float v97; // xmm1_4
  float v98; // xmm7_4
  float v99; // xmm2_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-D8h]
  UFG::qVector3 destination; // [rsp+30h] [rbp-C8h]
  UFG::qMatrix44 m; // [rsp+40h] [rbp-B8h]

  v3 = pedInfo;
  v4 = delta_sec;
  v5 = this;
  if ( this->mAIMode == REQUIRES_INIT )
    UFG::AILightWeightComponent::Init(this);
  v6 = LocalPlayer;
  if ( v5->mAILCanUseCrosswalks && LocalPlayer )
  {
    v7 = LocalPlayer->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v5->mWanderData.mAllowedToUseCrosswalks = LocalPlayer->m_Components.p[44].m_pComponent == 0i64;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
      {
        v5->mWanderData.mAllowedToUseCrosswalks = UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                    UFG::CharacterOccupantComponent::_TypeUID) == 0i64;
      }
      else if ( (v7 >> 12) & 1 )
      {
        v5->mWanderData.mAllowedToUseCrosswalks = UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                    UFG::CharacterOccupantComponent::_TypeUID) == 0i64;
      }
      else
      {
        v5->mWanderData.mAllowedToUseCrosswalks = UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&LocalPlayer->vfptr,
                                                    UFG::CharacterOccupantComponent::_TypeUID) == 0i64;
      }
    }
    else
    {
      v5->mWanderData.mAllowedToUseCrosswalks = UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  (UFG::SimObjectGame *)&LocalPlayer->vfptr,
                                                  UFG::CharacterOccupantComponent::_TypeUID) == 0i64;
    }
  }
  else
  {
    v5->mWanderData.mAllowedToUseCrosswalks = 0;
  }
  if ( !v5->mWanderData.mGoals[0].mIsValid || !v6 )
    goto LABEL_74;
  v8 = (float *)v5->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pSimComponent);
  v9 = v8[45];
  v10 = v8[46];
  v11 = v8[44];
  v12 = (UFG::TransformNodeComponent *)LocalPlayer;
  v13 = v5->mWanderData.mGoals[0].mPosition.x;
  v14 = v5->mWanderData.mGoals[0].mPosition.y;
  v15 = v5->mWanderData.mGoals[0].mPosition.z;
  pos.x = v11;
  pos.y = v9;
  pos.z = v10;
  v16 = v13 - v11;
  v17 = v14 - v9;
  v18 = v15 - v10;
  if ( LocalPlayer )
    v12 = LocalPlayer->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v12);
  v19 = 1;
  if ( UFG::PedSpawnManager::msProxyExclusionZoneActive )
  {
    if ( !UFG::PedSpawnManager::msProxyExclusionZoneActive_2 )
    {
      v33 = UFG::PedSpawnManager::msProxyExclusionZoneRadius;
LABEL_36:
      if ( (float)((float)((float)((float)(v12->mWorldTransform.v3.y - pos.y)
                                 * (float)(v12->mWorldTransform.v3.y - pos.y))
                         + (float)((float)(v12->mWorldTransform.v3.x - pos.x)
                                 * (float)(v12->mWorldTransform.v3.x - pos.x)))
                 + (float)((float)(v12->mWorldTransform.v3.z - pos.z) * (float)(v12->mWorldTransform.v3.z - pos.z))) > (float)(v33 * v33) )
        return 0;
      v19 = UFG::AILightWeightComponent::MaybeReversePath(v5, (UFG::qVector3 *)&v12->mWorldTransform.v3, &pos, 0) == 0;
      if ( !v19 )
      {
        v35 = v5->mWanderData.mGoals[0].mPosition.z;
        v36 = LODWORD(v5->mWanderData.mGoals[0].mPosition.y);
        v37 = LODWORD(v5->mWanderData.mGoals[0].mPosition.x);
        v42 = (__m128)LODWORD(v5->mWanderData.mGoals[0].mPosition.y);
        v38 = pos.x;
        v39 = pos.y;
        v40 = pos.z;
        v41 = v5->mWanderData.mGoals[0].mPosition.x - pos.x;
        v42.m128_f32[0] = v42.m128_f32[0] - pos.y;
        destination.z = v35;
        v44 = v42;
        v43 = v35 - pos.z;
        LODWORD(destination.y) = v36;
        v44.m128_f32[0] = (float)((float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v41 * v41)) + (float)(v43 * v43);
        if ( v44.m128_f32[0] < 0.001 )
        {
          *(float *)&v37 = *(float *)&v37 + 0.050000001;
          LODWORD(destination.x) = v37;
          UFG::SidewalkWanderData::SetDestinationPos(&v5->mWanderData, &destination, &pos);
          v40 = pos.z;
          v39 = pos.y;
          v38 = pos.x;
        }
        if ( v44.m128_f32[0] == 0.0 )
          v45 = 0.0;
        else
          v45 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v44));
        v46 = *(float *)&v37 - v38;
        *(float *)&v36 = *(float *)&v36 - v39;
        v47 = (__m128)v36;
        v5->mTravelDirection.x = v41 * v45;
        v5->mTravelDirection.y = v42.m128_f32[0] * v45;
        v5->mTravelDirection.z = v43 * v45;
        v47.m128_f32[0] = (float)((float)(*(float *)&v36 * *(float *)&v36) + (float)(v46 * v46)) + (float)(0.0 * 0.0);
        if ( v47.m128_f32[0] == 0.0 )
          v48 = 0.0;
        else
          v48 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v47));
        v49 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        *(float *)&v37 = v46 * v48;
        v50 = *(float *)&v36 * v48;
        v52 = v49;
        m.v0.w = 0.0;
        v51 = 0.0 * v48;
        LODWORD(m.v0.x) = v37;
        m.v0.y = v50;
        m.v0.z = 0.0 * v48;
        v52.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0])
                                + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                        + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
        if ( v52.m128_f32[0] == 0.0 )
        {
          v53 = 0i64;
        }
        else
        {
          v53 = (unsigned int)FLOAT_1_0;
          *(float *)&v53 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v52));
        }
        v54 = v53;
        v55 = *(float *)&v53;
        v56 = *(float *)&v53 * UFG::qVector3::msDirUp.z;
        v57 = v55 * UFG::qVector3::msDirUp.x;
        *(float *)&v54 = *(float *)&v54 * UFG::qVector3::msDirUp.y;
        v60 = (__m128)v37;
        v58 = v50 * v57;
        v59 = v54;
        *(float *)&v59 = (float)(*(float *)&v54 * v51) - (float)(v50 * v56);
        v60.m128_f32[0] = (float)(*(float *)&v37 * v56) - (float)(v57 * v51);
        v62 = v60;
        v61 = v58 - (float)(*(float *)&v37 * *(float *)&v54);
        v62.m128_f32[0] = (float)((float)(v60.m128_f32[0] * v60.m128_f32[0]) + (float)(*(float *)&v59 * *(float *)&v59))
                        + (float)(v61 * v61);
        if ( v62.m128_f32[0] == 0.0 )
          v63 = 0.0;
        else
          v63 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v62));
        *(float *)&v59 = *(float *)&v59 * v63;
        m.v1.w = 0.0;
        v65 = (__m128)v59;
        LODWORD(m.v1.x) = v59;
        m.v1.y = v60.m128_f32[0] * v63;
        m.v1.z = v61 * v63;
        v64 = (float)(v50 * (float)(v61 * v63)) - (float)((float)(v60.m128_f32[0] * v63) * v51);
        v65.m128_f32[0] = (float)(*(float *)&v59 * v51) - (float)(*(float *)&v37 * (float)(v61 * v63));
        v66 = (float)(*(float *)&v37 * (float)(v60.m128_f32[0] * v63)) - (float)(v50 * *(float *)&v59);
        v67 = v65;
        v67.m128_f32[0] = (float)((float)(v65.m128_f32[0] * v65.m128_f32[0]) + (float)(v64 * v64)) + (float)(v66 * v66);
        if ( v67.m128_f32[0] == 0.0 )
          v68 = 0.0;
        else
          v68 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v67));
        v69 = (UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pSimComponent;
        m.v3.x = v38;
        m.v3.y = v39;
        m.v2.w = 0.0;
        m.v3.w = 1.0;
        m.v3.z = v40;
        m.v2.x = v64 * v68;
        m.v2.y = v65.m128_f32[0] * v68;
        m.v2.z = v66 * v68;
        UFG::TransformNodeComponent::SetWorldTransform(v69, &m);
        return 1;
      }
      goto LABEL_21;
    }
LABEL_34:
    v33 = UFG::PedSpawnManager::msProxyExclusionZoneRadius_2;
    goto LABEL_36;
  }
  if ( UFG::PedSpawnManager::msProxyExclusionZoneActive_2 )
    goto LABEL_34;
LABEL_21:
  if ( (float)((float)((float)(v17 * v17) + (float)(v16 * v16)) + (float)(v18 * v18)) < (float)(`anonymous namespace::gLightWeightDestReachedThreshold
                                                                                              * `anonymous namespace::gLightWeightDestReachedThreshold) )
  {
    if ( v19 )
    {
      if ( v3->mCulledTime >= 0.0
        && v3->mDistInCameraSpace > 130.0
        && (float)((float)((float)((float)(pos.y - v5->mInitPos.y) * (float)(pos.y - v5->mInitPos.y))
                         + (float)((float)(pos.x - v5->mInitPos.x) * (float)(pos.x - v5->mInitPos.x)))
                 + (float)((float)(pos.z - v5->mInitPos.z) * (float)(pos.z - v5->mInitPos.z))) > 400.0 )
      {
        v19 = UFG::AILightWeightComponent::MaybeReversePath(v5, (UFG::qVector3 *)&v12->mWorldTransform.v3, &pos, 1) == 0;
      }
      if ( v19 && !UFG::AILightWeightComponent::CalculateDestination(v5) )
        return 1;
    }
    v20 = (float *)v5->m_pTransformNodeComponent.m_pSimComponent;
    v22 = v5->mWanderData.mGoals[0].mPosition.z;
    v23 = (UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pSimComponent;
    v24 = v5->mWanderData.mGoals[0].mPosition.x;
    destination.y = v5->mWanderData.mGoals[0].mPosition.y;
    v21 = (__m128)LODWORD(destination.y);
    destination.z = v22;
    UFG::TransformNodeComponent::UpdateWorldTransform(v23);
    v29 = v21;
    v25 = v20[45];
    v26 = v20[44];
    v27 = v20[46];
    v28 = v24 - v26;
    v29.m128_f32[0] = v21.m128_f32[0] - v25;
    v30 = v22 - v27;
    v31 = v29;
    pos.x = v20[44];
    pos.y = v25;
    v31.m128_f32[0] = (float)((float)(v29.m128_f32[0] * v29.m128_f32[0]) + (float)(v28 * v28)) + (float)(v30 * v30);
    pos.z = v27;
    if ( v31.m128_f32[0] < 0.001 )
    {
      v24 = v24 + 0.050000001;
      destination.x = v24;
      UFG::SidewalkWanderData::SetDestinationPos(&v5->mWanderData, &destination, &pos);
      v27 = pos.z;
      v25 = pos.y;
      v26 = pos.x;
    }
    if ( v31.m128_f32[0] == 0.0 )
      v32 = 0.0;
    else
      v32 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
    v70 = v24 - v26;
    v21.m128_f32[0] = v21.m128_f32[0] - v25;
    v71 = v21;
    v5->mTravelDirection.x = v28 * v32;
    v5->mTravelDirection.y = v29.m128_f32[0] * v32;
    v5->mTravelDirection.z = v30 * v32;
    v71.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v70 * v70)) + (float)(0.0 * 0.0);
    if ( v71.m128_f32[0] == 0.0 )
      v72 = 0.0;
    else
      v72 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v71));
    v73 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
    v74 = v70 * v72;
    v75 = v21.m128_f32[0] * v72;
    v77 = v73;
    m.v0.w = 0.0;
    v76 = 0.0 * v72;
    m.v0.x = v74;
    m.v0.y = v75;
    m.v0.z = 0.0 * v72;
    v77.m128_f32[0] = (float)((float)(v73.m128_f32[0] * v73.m128_f32[0])
                            + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                    + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
    if ( v77.m128_f32[0] == 0.0 )
    {
      v79 = 0i64;
    }
    else
    {
      LODWORD(v78) = (unsigned __int128)_mm_sqrt_ps(v77);
      v79 = (__m128)(unsigned int)FLOAT_1_0;
      v79.m128_f32[0] = 1.0 / v78;
    }
    v80 = v79;
    v81 = v79.m128_f32[0];
    v79.m128_f32[0] = v79.m128_f32[0] * UFG::qVector3::msDirUp.z;
    v82 = v81 * UFG::qVector3::msDirUp.x;
    v80.m128_f32[0] = v80.m128_f32[0] * UFG::qVector3::msDirUp.y;
    v83 = v80;
    v83.m128_f32[0] = (float)(v80.m128_f32[0] * v76) - (float)(v79.m128_f32[0] * v75);
    v79.m128_f32[0] = (float)(v79.m128_f32[0] * v74) - (float)(v82 * v76);
    v84 = (float)(v82 * v75) - (float)(v80.m128_f32[0] * v74);
    v85 = v79;
    v85.m128_f32[0] = (float)((float)(v79.m128_f32[0] * v79.m128_f32[0]) + (float)(v83.m128_f32[0] * v83.m128_f32[0]))
                    + (float)(v84 * v84);
    if ( v85.m128_f32[0] == 0.0 )
      v86 = 0.0;
    else
      v86 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v85));
    v87 = v79.m128_f32[0] * v86;
    v83.m128_f32[0] = v83.m128_f32[0] * v86;
    m.v1.w = 0.0;
    v89 = v83;
    m.v1.y = v87;
    m.v1.z = v84 * v86;
    LODWORD(m.v1.x) = v83.m128_i32[0];
    v88 = (float)((float)(v84 * v86) * v75) - (float)(v87 * v76);
    v89.m128_f32[0] = (float)(v83.m128_f32[0] * v76) - (float)((float)(v84 * v86) * v74);
    v90 = (float)(v87 * v74) - (float)(v83.m128_f32[0] * v75);
    v91 = v89;
    v91.m128_f32[0] = (float)((float)(v89.m128_f32[0] * v89.m128_f32[0]) + (float)(v88 * v88)) + (float)(v90 * v90);
    if ( v91.m128_f32[0] == 0.0 )
      v92 = 0.0;
    else
      v92 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v91));
    v93 = (UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pSimComponent;
    m.v3.x = v26;
    m.v3.y = v25;
    m.v2.w = 0.0;
    m.v3.w = 1.0;
    m.v3.z = v27;
    m.v2.x = v88 * v92;
    m.v2.y = v89.m128_f32[0] * v92;
    m.v2.z = v90 * v92;
    UFG::TransformNodeComponent::SetWorldTransform(v93, &m);
  }
  v94 = v4 * 1.5;
  if ( v94 > 0.40000001 )
    v94 = FLOAT_0_40000001;
  v95 = (UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pSimComponent;
  v96 = v94;
  v97 = v94 * v5->mTravelDirection.x;
  v98 = v94 * v5->mTravelDirection.z;
  v99 = v96 * v5->mTravelDirection.y;
  pos.x = pos.x + v97;
  pos.z = pos.z + v98;
  pos.y = pos.y + v99;
  UFG::TransformNodeComponent::SetWorldTranslation(v95, &pos);
LABEL_74:
  v5->mWanderData.mLastUpdateFrame = UFG::Metrics::msFrameCount;
  return 1;
}UFG::TransformNodeComponent *)v5->m_pTransformNodeComponent.m_pSimComponent;
  v96 = v94;
  v97 = v94 * v5->mTravelDirection.x;
  v98 = v94 * v5->mTravelDirection.z;
  v99 = v96 * v5->mTravelDirection.y;
  pos.x = pos.x + v97;
  pos.z = pos.z + v98;
  pos.y = pos.y + v99;
  UFG::TransformNodeComponent::SetWorldTranslation(v95, &pos);
LABEL_74:
  v5->mWanderData.mLastUpdateFrame = UFG::Metrics::m

