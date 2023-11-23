// File Line: 37
// RVA: 0x3632F0
const char *__fastcall UFG::AILightWeightComponent::GetTypeName(UFG::AILightWeightComponent *this)
{
  return "AILightWeightComponent";
}

// File Line: 47
// RVA: 0x32B700
void __fastcall UFG::AILightWeightComponent::AILightWeightComponent(
        UFG::AILightWeightComponent *this,
        unsigned int name_uid)
{
  UFG::SimComponent::SimComponent(this, name_uid);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AILightWeightComponent::`vftable;
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->m_pTransformNodeComponent);
  `eh vector constructor iterator(
    &this->mWanderData,
    0x78ui64,
    2,
    (void (__fastcall *)(void *))UFG::SidewalkWanderData::GoalInfo::GoalInfo);
  this->mWanderData.mCrosswalkLanes.m_iIntersectionID.p = 0i64;
  *(_QWORD *)&this->mWanderData.mCrosswalkLanes.m_iIntersectionID.size = 0i64;
  this->mWanderData.mCrosswalkLanes.m_aLanes.p = 0i64;
  *(_QWORD *)&this->mWanderData.mCrosswalkLanes.m_aLanes.size = 0i64;
  UFG::SimComponent::AddType(
    this,
    UFG::AILightWeightComponent::_AILightWeightComponentTypeUID,
    "AILightWeightComponent");
  UFG::SidewalkWanderData::ClearData(&this->mWanderData);
}

// File Line: 73
// RVA: 0x378650
void __fastcall UFG::AILightWeightComponent::OnAttach(UFG::AILightWeightComponent *this, UFG::SimObject *object)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->m_pTransformNodeComponent,
    object);
  this->mAIMode = REQUIRES_INIT;
}

// File Line: 84
// RVA: 0x379C70
void __fastcall UFG::AILightWeightComponent::OnDetach(UFG::AILightWeightComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rcx

  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pSimComponent )
  {
    mNext = this->m_pTransformNodeComponent.mNext;
    mPrev = p_m_pTransformNodeComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTransformNodeComponent->mNext = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->m_Changed = 1;
    p_m_pTransformNodeComponent->m_pSimComponent = 0i64;
    p_m_pTransformNodeComponent->m_pSimObject = 0i64;
  }
  else
  {
    if ( this->m_pTransformNodeComponent.m_pSimObject
      && (p_m_pTransformNodeComponent->mPrev != p_m_pTransformNodeComponent
       || this->m_pTransformNodeComponent.mNext != &this->m_pTransformNodeComponent) )
    {
      v4 = this->m_pTransformNodeComponent.mNext;
      v5 = p_m_pTransformNodeComponent->mPrev;
      v5->mNext = v4;
      v4->mPrev = v5;
      p_m_pTransformNodeComponent->mNext = p_m_pTransformNodeComponent;
      p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
      p_m_pTransformNodeComponent->m_pSimObject = 0i64;
    }
    p_m_pTransformNodeComponent->m_Changed = 1;
  }
}

// File Line: 89
// RVA: 0x389A00
void __fastcall UFG::AILightWeightComponent::TeleportEventHandler(
        UFG::AILightWeightComponent *this,
        UFG::Event *this_event)
{
  this->mAIMode = REQUIRES_INIT;
}

// File Line: 95
// RVA: 0x365240
void __fastcall UFG::AILightWeightComponent::Init(UFG::AILightWeightComponent *this)
{
  bool v1; // zf
  UFG::SimComponent *m_pSimComponent; // rbx
  unsigned __int8 v4; // r9
  float v5; // xmm1_4
  float v6; // xmm0_4
  UFG::TransformNodeComponent *v7; // rbx
  UFG::AISidewalkEdge_Game *mPtr; // r15
  char *v9; // rsi
  char *v10; // rax
  UFG::qVector3 *v11; // r12
  __int64 mOffset; // rax
  UFG::qVector3 **v13; // r8
  float x; // xmm4_4
  float y; // xmm3_4
  float z; // xmm5_4
  float v17; // xmm2_4
  __int64 v18; // rax
  char *v19; // rax
  UFG::qVector3 *v20; // rdx
  float v21; // xmm0_4
  float v22; // xmm8_4
  UFG::qVector3 *p_mInitPos; // r8
  UFG::SidewalkWanderData *p_mWanderData; // rcx
  __int64 v25; // rax
  UFG::AISidewalkEdge_Game *v26; // rax
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm12_4
  float v30; // xmm13_4
  float v31; // xmm14_4
  __int128 x_low; // xmm5
  __m128 y_low; // xmm8
  __int128 z_low; // xmm9
  __m128 v35; // xmm2
  float v36; // xmm1_4
  float v37; // xmm8_4
  __m128 v38; // xmm2
  float v39; // xmm4_4
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm4_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  __int128 v45; // xmm10
  float v46; // xmm11_4
  __m128 v47; // xmm3
  float v48; // xmm11_4
  __m128 v49; // xmm2
  float v50; // xmm1_4
  float v51; // xmm0_4
  __m128 v52; // xmm4
  float v53; // xmm3_4
  float v54; // xmm2_4
  __m128 v55; // xmm5
  float v56; // xmm6_4
  UFG::TransformNodeComponent *v57; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-D0h] BYREF
  UFG::qMatrix44 m; // [rsp+30h] [rbp-C0h] BYREF

  v1 = this->m_pTransformNodeComponent.m_pSimComponent == 0i64;
  this->mAIMode = NORMAL_OPERATION;
  if ( !v1 )
  {
    m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
    v4 = -5;
    v5 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
    v6 = *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1);
    this->mInitPos.x = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
    this->mInitPos.z = v5;
    this->mInitPos.y = v6;
    if ( this->mWanderData.mAllowedToUseCrosswalks )
      v4 = -1;
    UFG::AISidewalkGraph::FindClosestSidewalkConnection(
      &this->mInitPos,
      30.0,
      (UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *)&this->mWanderData,
      v4);
    if ( this->mWanderData.mGoals[0].mpSidewalkEdge.mPtr )
    {
      v7 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(v7);
      mPtr = this->mWanderData.mGoals[0].mpSidewalkEdge.mPtr;
      v9 = 0i64;
      if ( mPtr->mpStartNodeHandle.mOffset )
        v10 = (char *)mPtr + mPtr->mpStartNodeHandle.mOffset;
      else
        v10 = 0i64;
      v11 = (UFG::qVector3 *)*((_QWORD *)v10 + 5);
      mOffset = mPtr->mpEndNodeHandle.mOffset;
      if ( mOffset )
        v13 = (UFG::qVector3 **)((char *)&mPtr->mpEndNodeHandle + mOffset);
      else
        v13 = 0i64;
      UFG::qNearestSegPoint(&result, v11, v13[5], &this->mInitPos);
      x = this->mInitPos.x;
      y = this->mInitPos.y;
      z = this->mInitPos.z;
      v17 = (float)((float)((float)(v11->y - y) * v7->mWorldTransform.v0.y)
                  + (float)((float)(v11->x - x) * v7->mWorldTransform.v0.x))
          + (float)((float)(v11->z - z) * v7->mWorldTransform.v0.z);
      if ( v17 <= 0.0 )
      {
        v25 = mPtr->mpEndNodeHandle.mOffset;
        if ( !v25 )
          goto LABEL_13;
        v18 = v25 + 8;
      }
      else
      {
        v18 = mPtr->mpStartNodeHandle.mOffset;
        if ( !mPtr->mpStartNodeHandle.mOffset )
        {
LABEL_13:
          v19 = 0i64;
LABEL_14:
          v20 = (UFG::qVector3 *)*((_QWORD *)v19 + 5);
          v21 = *(float *)&FLOAT_1_0;
          if ( v20 )
            v21 = v20[1].z;
          v22 = result.x;
          p_mInitPos = &this->mInitPos;
          p_mWanderData = &this->mWanderData;
          if ( (float)((float)((float)((float)(y - result.y) * (float)(y - result.y))
                             + (float)((float)(x - result.x) * (float)(x - result.x)))
                     + (float)((float)(z - result.z) * (float)(z - result.z))) >= (float)(v21 * v21) )
          {
            UFG::SidewalkWanderData::SetDestinationPos(p_mWanderData, &result, p_mInitPos);
            this->mWanderData.mIsDestinationSegment = 1;
          }
          else
          {
            UFG::SidewalkWanderData::SetDestinationPos(p_mWanderData, v20, p_mInitPos);
            this->mWanderData.mIsDestinationSegment = 0;
          }
          v26 = this->mWanderData.mGoals[0].mpSidewalkEdge.mPtr;
          if ( v17 <= 0.0 )
            v26 = (UFG::AISidewalkEdge_Game *)((char *)v26 + 8);
          if ( v26->mpStartNodeHandle.mOffset )
            v9 = (char *)v26 + v26->mpStartNodeHandle.mOffset;
          UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
            &this->mWanderData.mGoals[0].mpDestinationNode,
            *((_DWORD *)v9 + 9),
            *((_DWORD *)v9 + 6),
            *((unsigned __int16 *)v9 + 16));
          if ( (float)((float)((float)((float)(this->mInitPos.y - this->mWanderData.mGoals[0].mPosition.y)
                                     * (float)(this->mInitPos.y - this->mWanderData.mGoals[0].mPosition.y))
                             + (float)((float)(this->mInitPos.x - this->mWanderData.mGoals[0].mPosition.x)
                                     * (float)(this->mInitPos.x - this->mWanderData.mGoals[0].mPosition.x)))
                     + (float)((float)(this->mInitPos.z - this->mWanderData.mGoals[0].mPosition.z)
                             * (float)(this->mInitPos.z - this->mWanderData.mGoals[0].mPosition.z))) < 0.001 )
          {
            result.x = v22 + 0.050000001;
            UFG::SidewalkWanderData::SetDestinationPos(&this->mWanderData, &result, &this->mInitPos);
          }
          v27 = this->mWanderData.mPreviousDesiredDirection.x;
          v28 = this->mWanderData.mPreviousDesiredDirection.y;
          this->mTravelDirection.z = this->mWanderData.mPreviousDesiredDirection.z;
          this->mTravelDirection.x = v27;
          this->mTravelDirection.y = v28;
          z_low = LODWORD(this->mInitPos.z);
          x_low = LODWORD(this->mWanderData.mGoals[0].mPosition.x);
          y_low = (__m128)LODWORD(this->mWanderData.mGoals[0].mPosition.y);
          v29 = this->mInitPos.x;
          v30 = this->mInitPos.y;
          v31 = *(float *)&z_low;
          *(float *)&x_low = *(float *)&x_low - v29;
          y_low.m128_f32[0] = y_low.m128_f32[0] - v30;
          *(float *)&z_low = *(float *)&z_low - *(float *)&z_low;
          v35 = y_low;
          v35.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                                  + (float)(*(float *)&x_low * *(float *)&x_low))
                          + (float)(*(float *)&z_low * *(float *)&z_low);
          if ( v35.m128_f32[0] == 0.0 )
            v36 = 0.0;
          else
            v36 = 1.0 / _mm_sqrt_ps(v35).m128_f32[0];
          *(float *)&x_low = *(float *)&x_low * v36;
          v37 = y_low.m128_f32[0] * v36;
          *(float *)&z_low = *(float *)&z_low * v36;
          m.v0.w = 0.0;
          v38 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
          LODWORD(m.v0.x) = x_low;
          m.v0.y = v37;
          LODWORD(m.v0.z) = z_low;
          v38.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v38.m128_f32[0])
                                  + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                          + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
          if ( v38.m128_f32[0] == 0.0 )
            v39 = 0.0;
          else
            v39 = 1.0 / _mm_sqrt_ps(v38).m128_f32[0];
          v40 = v39;
          v41 = v39;
          v42 = v39 * UFG::qVector3::msDirUp.z;
          v43 = v41 * UFG::qVector3::msDirUp.x;
          v44 = v40 * UFG::qVector3::msDirUp.y;
          v45 = z_low;
          v47 = (__m128)x_low;
          *(float *)&v45 = (float)(*(float *)&z_low * v44) - (float)(v37 * v42);
          v46 = v37 * v43;
          v47.m128_f32[0] = (float)(*(float *)&x_low * v42) - (float)(*(float *)&z_low * v43);
          v49 = v47;
          v48 = v46 - (float)(*(float *)&x_low * v44);
          v49.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(*(float *)&v45 * *(float *)&v45))
                          + (float)(v48 * v48);
          if ( v49.m128_f32[0] == 0.0 )
            v50 = 0.0;
          else
            v50 = 1.0 / _mm_sqrt_ps(v49).m128_f32[0];
          *(float *)&v45 = *(float *)&v45 * v50;
          m.v1.w = 0.0;
          v52 = (__m128)v45;
          m.v1.z = v48 * v50;
          LODWORD(m.v1.x) = v45;
          m.v1.y = v47.m128_f32[0] * v50;
          v51 = (float)(v47.m128_f32[0] * v50) * *(float *)&z_low;
          v52.m128_f32[0] = (float)(*(float *)&v45 * *(float *)&z_low) - (float)((float)(v48 * v50) * *(float *)&x_low);
          v53 = (float)((float)(v47.m128_f32[0] * v50) * *(float *)&x_low) - (float)(*(float *)&v45 * v37);
          v54 = (float)((float)(v48 * v50) * v37) - v51;
          v55 = v52;
          v55.m128_f32[0] = (float)((float)(v52.m128_f32[0] * v52.m128_f32[0]) + (float)(v54 * v54))
                          + (float)(v53 * v53);
          if ( v55.m128_f32[0] == 0.0 )
            v56 = 0.0;
          else
            v56 = 1.0 / _mm_sqrt_ps(v55).m128_f32[0];
          v57 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
          m.v3.x = v29;
          m.v3.y = v30;
          m.v2.w = 0.0;
          m.v3.w = 1.0;
          m.v3.z = v31;
          m.v2.x = v54 * v56;
          m.v2.y = v52.m128_f32[0] * v56;
          m.v2.z = v53 * v56;
          UFG::TransformNodeComponent::SetWorldTransform(v57, &m);
          return;
        }
      }
      v19 = (char *)mPtr + v18;
      goto LABEL_14;
    }
  }
}

// File Line: 200
// RVA: 0x388020
void __fastcall UFG::AILightWeightComponent::SetWanderData(
        UFG::AILightWeightComponent *this,
        UFG::SidewalkWanderData *data)
{
  UFG::SidewalkWanderData::operator=(&this->mWanderData, data);
}

// File Line: 255
// RVA: 0x34A560
char __fastcall UFG::AILightWeightComponent::CalculateDestination(UFG::AILightWeightComponent *this)
{
  UFG::SidewalkWanderData *sidewalkWanderData; // rbp
  UFG::SimComponent *m_pSimComponent; // rbx
  UFG::SimObjectGame *m_pSimObject; // rcx
  bool isGroupLeader; // r14
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float z; // xmm0_4
  UFG::SimComponent *v10; // rdi
  UFG::SimComponent *v11; // rbx
  UFG::SimComponent *v12; // rbx
  UFG::qVector3 pDestinationPoint; // [rsp+40h] [rbp-28h] BYREF

  sidewalkWanderData = &this->mWanderData;
  if ( !this->mWanderData.mGoals[0].mpSidewalkEdge.mPtr )
    return 0;
  if ( this->mWanderData.mIsDestinationSegment && this->mWanderData.mGoals[0].mpDestinationNode.mPtr )
  {
    m_pSimComponent = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)m_pSimComponent);
    UFG::SidewalkWanderData::SetDestinationPos(
      sidewalkWanderData,
      &this->mWanderData.mGoals[0].mpDestinationNode.mPtr->mPos,
      (UFG::qVector3 *)&m_pSimComponent[2].m_BoundComponentHandles);
    this->mWanderData.mIsDestinationSegment = 0;
    return 1;
  }
  else
  {
    m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
    isGroupLeader = 0;
    if ( m_pSimObject )
    {
      m_Flags = m_pSimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::GroupComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::GroupComponent::_TypeUID);
      if ( ComponentOfTypeHK )
        isGroupLeader = *(_QWORD *)&ComponentOfTypeHK[3].m_Flags
                     && LODWORD(ComponentOfTypeHK[1].m_BoundComponentHandles.mNode.mNext);
    }
    pDestinationPoint.x = UFG::qVector3::msZero.x;
    z = UFG::qVector3::msZero.z;
    pDestinationPoint.y = UFG::qVector3::msZero.y;
    this->mWanderData.mIsDestinationSegment = 0;
    v10 = this->m_pTransformNodeComponent.m_pSimComponent;
    pDestinationPoint.z = z;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v10);
    v11 = this->m_pTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v11);
    if ( !UFG::AISidewalkGraph::CalculateDestinationPoint(
            (UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game> *)sidewalkWanderData,
            &this->mWanderData.mGoals[0].mpDestinationNode,
            &pDestinationPoint,
            (UFG::qVector3 *)&v11[2].m_BoundComponentHandles,
            (UFG::qVector3 *)&v10[2],
            isGroupLeader,
            0i64,
            sidewalkWanderData)
      || pDestinationPoint.x == 0.0 )
    {
      return 0;
    }
    else
    {
      v12 = this->m_pTransformNodeComponent.m_pSimComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v12);
      UFG::SidewalkWanderData::SetDestinationPos(
        sidewalkWanderData,
        &pDestinationPoint,
        (UFG::qVector3 *)&v12[2].m_BoundComponentHandles);
      return 1;
    }
  }
}

// File Line: 311
// RVA: 0x374DC0
char __fastcall UFG::AILightWeightComponent::MaybeReversePath(
        UFG::AILightWeightComponent *this,
        UFG::qVector3 *player_pos,
        UFG::qVector3 *pos,
        bool should_tend_towards_player)
{
  UFG::AISidewalkEdge_Game *mPtr; // rax
  char *v7; // rax
  __int64 v8; // rax
  UFG::qResourceInventory *v9; // rax
  UFG::qResourceWarehouse *v10; // rax
  unsigned int v11; // edx
  unsigned int v12; // r15d
  unsigned int v13; // esi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  UFG::AISidewalkEdge_Game *v18; // rax
  __int64 mOffset; // rcx
  char *v20; // rax
  __int64 v21; // rax
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  unsigned int v24; // r15d
  unsigned int v25; // esi
  UFG::qResourceInventory *v26; // rax
  UFG::qResourceWarehouse *v27; // rax
  UFG::qResourceInventory *v28; // rax
  UFG::qResourceWarehouse *v29; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  UFG::qResourceInventory *v32; // rax
  UFG::qResourceWarehouse *v33; // rax
  UFG::qResourceInventory *v35; // rax
  UFG::qResourceWarehouse *v36; // rax
  UFG::qResourceHandle v37; // [rsp+28h] [rbp-38h] BYREF
  int v38; // [rsp+48h] [rbp-18h]
  unsigned int objUID; // [rsp+4Ch] [rbp-14h]
  __int64 v40; // [rsp+50h] [rbp-10h]

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
  mPtr = this->mWanderData.mGoals[0].mpSidewalkEdge.mPtr;
  if ( mPtr->mpStartNodeHandle.mOffset )
    v7 = (char *)mPtr + mPtr->mpStartNodeHandle.mOffset;
  else
    v7 = 0i64;
  v8 = *((_QWORD *)v7 + 5);
  if ( v8 )
  {
    v12 = *(_DWORD *)(v8 + 16);
    v13 = *(_DWORD *)(v8 + 12);
    v40 = 0i64;
    Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v15 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v15, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(&v37, Inventory);
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
  if ( this->mWanderData.mGoals[0].mpDestinationNode.mObjUID == v11 )
  {
    v18 = this->mWanderData.mGoals[0].mpSidewalkEdge.mPtr;
    mOffset = v18->mpEndNodeHandle.mOffset;
    if ( mOffset )
      v20 = (char *)&v18->mpEndNodeHandle + mOffset;
    else
      v20 = 0i64;
    v21 = *((_QWORD *)v20 + 5);
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
    &this->mWanderData.mGoals[0].mpDestinationNode,
    v11,
    v37.mNameUID,
    (unsigned __int16)v38);
  UFG::SidewalkWanderData::SetDestinationPos(
    &this->mWanderData,
    &this->mWanderData.mGoals[0].mpDestinationNode.mPtr->mPos,
    pos);
  y = pos->y;
  z = pos->z;
  this->mInitPos.x = pos->x;
  this->mInitPos.y = y;
  this->mInitPos.z = z;
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
char __fastcall UFG::AILightWeightComponent::Update(
        UFG::AILightWeightComponent *this,
        float delta_sec,
        UFG::PedSpawningInfo *pedInfo)
{
  UFG::SimObjectCharacter *v6; // rbx
  signed __int16 m_Flags; // cx
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  float x; // xmm0_4
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float v13; // xmm8_4
  float v14; // xmm6_4
  float v15; // xmm9_4
  float v16; // xmm8_4
  float v17; // xmm6_4
  float v18; // xmm9_4
  bool v19; // al
  UFG::TransformNodeComponent *v20; // rbx
  __m128 v21; // xmm9
  float v22; // xmm10_4
  float v23; // xmm6_4
  float v24; // xmm14_4
  float v25; // xmm13_4
  float v26; // xmm15_4
  float v27; // xmm11_4
  __m128 v28; // xmm12
  float v29; // xmm10_4
  __m128 v30; // xmm8
  float v31; // xmm1_4
  float v32; // xmm3_4
  __int128 y_low; // xmm8
  __int128 x_low; // xmm6
  float v36; // xmm12_4
  float v37; // xmm13_4
  float v38; // xmm14_4
  float v39; // xmm10_4
  __m128 v40; // xmm11
  float v41; // xmm9_4
  __m128 v42; // xmm7
  float v43; // xmm1_4
  float v44; // xmm6_4
  __m128 v45; // xmm2
  float v46; // xmm1_4
  float v47; // xmm8_4
  float v48; // xmm7_4
  __m128 v49; // xmm2
  __int128 v50; // xmm5
  __int128 v51; // xmm1
  float v52; // xmm2_4
  float v53; // xmm5_4
  float v54; // xmm2_4
  float v55; // xmm11_4
  __int128 v56; // xmm9
  __m128 v57; // xmm10
  float v58; // xmm11_4
  __m128 v59; // xmm2
  float v60; // xmm1_4
  float v61; // xmm2_4
  __m128 v62; // xmm5
  float v63; // xmm6_4
  __m128 v64; // xmm7
  float v65; // xmm3_4
  UFG::TransformNodeComponent *v66; // rcx
  float v67; // xmm6_4
  __m128 v68; // xmm2
  float v69; // xmm1_4
  float v70; // xmm6_4
  float v71; // xmm9_4
  float v72; // xmm11_4
  __m128 v73; // xmm2
  float v74; // xmm0_4
  __m128 v75; // xmm2
  __m128 v76; // xmm1
  float v77; // xmm10_4
  float v78; // xmm10_4
  __m128 v79; // xmm12
  float v80; // xmm10_4
  __m128 v81; // xmm5
  float v82; // xmm1_4
  float v83; // xmm5_4
  __m128 v84; // xmm8
  float v85; // xmm2_4
  __m128 v86; // xmm6
  float v87; // xmm3_4
  UFG::TransformNodeComponent *v88; // rcx
  float v89; // xmm7_4
  UFG::TransformNodeComponent *v90; // rcx
  float v91; // xmm2_4
  float v92; // xmm1_4
  float v93; // xmm7_4
  float v94; // xmm2_4
  UFG::qVector3 pos; // [rsp+20h] [rbp-D8h] BYREF
  UFG::qVector3 destination; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qMatrix44 m; // [rsp+40h] [rbp-B8h] BYREF

  if ( this->mAIMode == REQUIRES_INIT )
    UFG::AILightWeightComponent::Init(this);
  v6 = LocalPlayer;
  if ( this->mAILCanUseCrosswalks && LocalPlayer )
  {
    m_Flags = LocalPlayer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      this->mWanderData.mAllowedToUseCrosswalks = LocalPlayer->m_Components.p[44].m_pComponent == 0i64;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      this->mWanderData.mAllowedToUseCrosswalks = UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    LocalPlayer,
                                                    UFG::CharacterOccupantComponent::_TypeUID) == 0i64;
    }
    else
    {
      this->mWanderData.mAllowedToUseCrosswalks = UFG::SimObject::GetComponentOfType(
                                                    LocalPlayer,
                                                    UFG::CharacterOccupantComponent::_TypeUID) == 0i64;
    }
  }
  else
  {
    this->mWanderData.mAllowedToUseCrosswalks = 0;
  }
  if ( !this->mWanderData.mGoals[0].mIsValid || !v6 )
    goto LABEL_72;
  m_pSimComponent = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
  y = m_pSimComponent->mWorldTransform.v3.y;
  z = m_pSimComponent->mWorldTransform.v3.z;
  x = m_pSimComponent->mWorldTransform.v3.x;
  m_pTransformNodeComponent = (UFG::TransformNodeComponent *)LocalPlayer;
  v13 = this->mWanderData.mGoals[0].mPosition.x;
  v14 = this->mWanderData.mGoals[0].mPosition.y;
  v15 = this->mWanderData.mGoals[0].mPosition.z;
  pos.x = x;
  pos.y = y;
  pos.z = z;
  v16 = v13 - x;
  v17 = v14 - y;
  v18 = v15 - z;
  if ( LocalPlayer )
    m_pTransformNodeComponent = LocalPlayer->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v19 = 1;
  if ( UFG::PedSpawnManager::msProxyExclusionZoneActive )
  {
    if ( !UFG::PedSpawnManager::msProxyExclusionZoneActive_2 )
    {
      v32 = UFG::PedSpawnManager::msProxyExclusionZoneRadius;
LABEL_34:
      if ( (float)((float)((float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.y - pos.y)
                                 * (float)(m_pTransformNodeComponent->mWorldTransform.v3.y - pos.y))
                         + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.x - pos.x)
                                 * (float)(m_pTransformNodeComponent->mWorldTransform.v3.x - pos.x)))
                 + (float)((float)(m_pTransformNodeComponent->mWorldTransform.v3.z - pos.z)
                         * (float)(m_pTransformNodeComponent->mWorldTransform.v3.z - pos.z))) > (float)(v32 * v32) )
        return 0;
      v19 = UFG::AILightWeightComponent::MaybeReversePath(
              this,
              (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
              &pos,
              0) == 0;
      if ( !v19 )
      {
        y_low = LODWORD(this->mWanderData.mGoals[0].mPosition.y);
        x_low = LODWORD(this->mWanderData.mGoals[0].mPosition.x);
        v40 = (__m128)y_low;
        v36 = pos.x;
        v37 = pos.y;
        v38 = pos.z;
        v39 = this->mWanderData.mGoals[0].mPosition.x - pos.x;
        v40.m128_f32[0] = *(float *)&y_low - pos.y;
        destination.z = this->mWanderData.mGoals[0].mPosition.z;
        v42 = v40;
        v41 = destination.z - pos.z;
        LODWORD(destination.y) = y_low;
        v42.m128_f32[0] = (float)((float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(v39 * v39)) + (float)(v41 * v41);
        if ( v42.m128_f32[0] < 0.001 )
        {
          *(float *)&x_low = *(float *)&x_low + 0.050000001;
          LODWORD(destination.x) = x_low;
          UFG::SidewalkWanderData::SetDestinationPos(&this->mWanderData, &destination, &pos);
          v38 = pos.z;
          v37 = pos.y;
          v36 = pos.x;
        }
        if ( v42.m128_f32[0] == 0.0 )
          v43 = 0.0;
        else
          v43 = 1.0 / _mm_sqrt_ps(v42).m128_f32[0];
        v44 = *(float *)&x_low - v36;
        *(float *)&y_low = *(float *)&y_low - v37;
        v45 = (__m128)y_low;
        this->mTravelDirection.x = v39 * v43;
        this->mTravelDirection.y = v40.m128_f32[0] * v43;
        this->mTravelDirection.z = v41 * v43;
        v45.m128_f32[0] = (float)((float)(*(float *)&y_low * *(float *)&y_low) + (float)(v44 * v44))
                        + (float)(0.0 * 0.0);
        if ( v45.m128_f32[0] == 0.0 )
          v46 = 0.0;
        else
          v46 = 1.0 / _mm_sqrt_ps(v45).m128_f32[0];
        *(float *)&x_low = v44 * v46;
        v47 = *(float *)&y_low * v46;
        v49 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        m.v0.w = 0.0;
        v48 = 0.0 * v46;
        LODWORD(m.v0.x) = x_low;
        m.v0.y = v47;
        m.v0.z = 0.0 * v46;
        v49.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0])
                                + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                        + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
        if ( v49.m128_f32[0] == 0.0 )
        {
          v50 = 0i64;
        }
        else
        {
          v50 = (unsigned int)FLOAT_1_0;
          *(float *)&v50 = 1.0 / _mm_sqrt_ps(v49).m128_f32[0];
        }
        v51 = v50;
        v52 = *(float *)&v50;
        v53 = *(float *)&v50 * UFG::qVector3::msDirUp.z;
        v54 = v52 * UFG::qVector3::msDirUp.x;
        *(float *)&v51 = *(float *)&v51 * UFG::qVector3::msDirUp.y;
        v57 = (__m128)x_low;
        v55 = v47 * v54;
        v56 = v51;
        *(float *)&v56 = (float)(*(float *)&v51 * v48) - (float)(v47 * v53);
        v57.m128_f32[0] = (float)(*(float *)&x_low * v53) - (float)(v54 * v48);
        v59 = v57;
        v58 = v55 - (float)(*(float *)&x_low * *(float *)&v51);
        v59.m128_f32[0] = (float)((float)(v57.m128_f32[0] * v57.m128_f32[0]) + (float)(*(float *)&v56 * *(float *)&v56))
                        + (float)(v58 * v58);
        if ( v59.m128_f32[0] == 0.0 )
          v60 = 0.0;
        else
          v60 = 1.0 / _mm_sqrt_ps(v59).m128_f32[0];
        *(float *)&v56 = *(float *)&v56 * v60;
        m.v1.w = 0.0;
        v62 = (__m128)v56;
        LODWORD(m.v1.x) = v56;
        m.v1.y = v57.m128_f32[0] * v60;
        m.v1.z = v58 * v60;
        v61 = (float)(v47 * (float)(v58 * v60)) - (float)((float)(v57.m128_f32[0] * v60) * v48);
        v62.m128_f32[0] = (float)(*(float *)&v56 * v48) - (float)(*(float *)&x_low * (float)(v58 * v60));
        v63 = (float)(*(float *)&x_low * (float)(v57.m128_f32[0] * v60)) - (float)(v47 * *(float *)&v56);
        v64 = v62;
        v64.m128_f32[0] = (float)((float)(v62.m128_f32[0] * v62.m128_f32[0]) + (float)(v61 * v61)) + (float)(v63 * v63);
        if ( v64.m128_f32[0] == 0.0 )
          v65 = 0.0;
        else
          v65 = 1.0 / _mm_sqrt_ps(v64).m128_f32[0];
        v66 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
        m.v3.x = v36;
        m.v3.y = v37;
        m.v2.w = 0.0;
        m.v3.w = 1.0;
        m.v3.z = v38;
        m.v2.x = v61 * v65;
        m.v2.y = v62.m128_f32[0] * v65;
        m.v2.z = v63 * v65;
        UFG::TransformNodeComponent::SetWorldTransform(v66, &m);
        return 1;
      }
      goto LABEL_20;
    }
LABEL_32:
    v32 = UFG::PedSpawnManager::msProxyExclusionZoneRadius_2;
    goto LABEL_34;
  }
  if ( UFG::PedSpawnManager::msProxyExclusionZoneActive_2 )
    goto LABEL_32;
LABEL_20:
  if ( (float)((float)((float)(v17 * v17) + (float)(v16 * v16)) + (float)(v18 * v18)) < (float)(`anonymous namespace::gLightWeightDestReachedThreshold
                                                                                              * `anonymous namespace::gLightWeightDestReachedThreshold) )
  {
    if ( pedInfo->mCulledTime >= 0.0
      && pedInfo->mDistInCameraSpace > 130.0
      && (float)((float)((float)((float)(pos.y - this->mInitPos.y) * (float)(pos.y - this->mInitPos.y))
                       + (float)((float)(pos.x - this->mInitPos.x) * (float)(pos.x - this->mInitPos.x)))
               + (float)((float)(pos.z - this->mInitPos.z) * (float)(pos.z - this->mInitPos.z))) > 400.0 )
    {
      v19 = UFG::AILightWeightComponent::MaybeReversePath(
              this,
              (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3,
              &pos,
              1) == 0;
    }
    if ( v19 && !UFG::AILightWeightComponent::CalculateDestination(this) )
      return 1;
    v20 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    v22 = this->mWanderData.mGoals[0].mPosition.z;
    v23 = this->mWanderData.mGoals[0].mPosition.x;
    destination.y = this->mWanderData.mGoals[0].mPosition.y;
    v21 = (__m128)LODWORD(destination.y);
    destination.z = v22;
    UFG::TransformNodeComponent::UpdateWorldTransform(v20);
    v28 = v21;
    v24 = v20->mWorldTransform.v3.y;
    v25 = v20->mWorldTransform.v3.x;
    v26 = v20->mWorldTransform.v3.z;
    v27 = v23 - v25;
    v28.m128_f32[0] = v21.m128_f32[0] - v24;
    v29 = v22 - v26;
    v30 = v28;
    pos.x = v25;
    pos.y = v24;
    v30.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v28.m128_f32[0]) + (float)(v27 * v27)) + (float)(v29 * v29);
    pos.z = v26;
    if ( v30.m128_f32[0] < 0.001 )
    {
      v23 = v23 + 0.050000001;
      destination.x = v23;
      UFG::SidewalkWanderData::SetDestinationPos(&this->mWanderData, &destination, &pos);
      v26 = pos.z;
      v24 = pos.y;
      v25 = pos.x;
    }
    if ( v30.m128_f32[0] == 0.0 )
      v31 = 0.0;
    else
      v31 = 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
    v67 = v23 - v25;
    v21.m128_f32[0] = v21.m128_f32[0] - v24;
    v68 = v21;
    this->mTravelDirection.x = v27 * v31;
    this->mTravelDirection.y = v28.m128_f32[0] * v31;
    this->mTravelDirection.z = v29 * v31;
    v68.m128_f32[0] = (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v67 * v67)) + (float)(0.0 * 0.0);
    if ( v68.m128_f32[0] == 0.0 )
      v69 = 0.0;
    else
      v69 = 1.0 / _mm_sqrt_ps(v68).m128_f32[0];
    v70 = v67 * v69;
    v71 = v21.m128_f32[0] * v69;
    v73 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
    m.v0.w = 0.0;
    v72 = 0.0 * v69;
    m.v0.x = v70;
    m.v0.y = v71;
    m.v0.z = 0.0 * v69;
    v73.m128_f32[0] = (float)((float)(v73.m128_f32[0] * v73.m128_f32[0])
                            + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                    + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
    if ( v73.m128_f32[0] == 0.0 )
    {
      v75 = 0i64;
    }
    else
    {
      v74 = _mm_sqrt_ps(v73).m128_f32[0];
      v75 = (__m128)(unsigned int)FLOAT_1_0;
      v75.m128_f32[0] = 1.0 / v74;
    }
    v76 = v75;
    v77 = v75.m128_f32[0];
    v75.m128_f32[0] = v75.m128_f32[0] * UFG::qVector3::msDirUp.z;
    v78 = v77 * UFG::qVector3::msDirUp.x;
    v76.m128_f32[0] = v76.m128_f32[0] * UFG::qVector3::msDirUp.y;
    v79 = v76;
    v79.m128_f32[0] = (float)(v76.m128_f32[0] * v72) - (float)(v75.m128_f32[0] * v71);
    v75.m128_f32[0] = (float)(v75.m128_f32[0] * v70) - (float)(v78 * v72);
    v80 = (float)(v78 * v71) - (float)(v76.m128_f32[0] * v70);
    v81 = v75;
    v81.m128_f32[0] = (float)((float)(v75.m128_f32[0] * v75.m128_f32[0]) + (float)(v79.m128_f32[0] * v79.m128_f32[0]))
                    + (float)(v80 * v80);
    if ( v81.m128_f32[0] == 0.0 )
      v82 = 0.0;
    else
      v82 = 1.0 / _mm_sqrt_ps(v81).m128_f32[0];
    v79.m128_f32[0] = v79.m128_f32[0] * v82;
    m.v1.w = 0.0;
    v84 = v79;
    m.v1.y = v75.m128_f32[0] * v82;
    m.v1.z = v80 * v82;
    LODWORD(m.v1.x) = v79.m128_i32[0];
    v83 = (float)((float)(v80 * v82) * v71) - (float)((float)(v75.m128_f32[0] * v82) * v72);
    v84.m128_f32[0] = (float)(v79.m128_f32[0] * v72) - (float)((float)(v80 * v82) * v70);
    v85 = (float)((float)(v75.m128_f32[0] * v82) * v70) - (float)(v79.m128_f32[0] * v71);
    v86 = v84;
    v86.m128_f32[0] = (float)((float)(v84.m128_f32[0] * v84.m128_f32[0]) + (float)(v83 * v83)) + (float)(v85 * v85);
    if ( v86.m128_f32[0] == 0.0 )
      v87 = 0.0;
    else
      v87 = 1.0 / _mm_sqrt_ps(v86).m128_f32[0];
    v88 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
    m.v3.x = v25;
    m.v3.y = v24;
    m.v2.w = 0.0;
    m.v3.w = 1.0;
    m.v3.z = v26;
    m.v2.x = v83 * v87;
    m.v2.y = v84.m128_f32[0] * v87;
    m.v2.z = v85 * v87;
    UFG::TransformNodeComponent::SetWorldTransform(v88, &m);
  }
  v89 = delta_sec * 1.5;
  if ( v89 > 0.40000001 )
    v89 = FLOAT_0_40000001;
  v90 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pSimComponent;
  v91 = v89;
  v92 = v89 * this->mTravelDirection.x;
  v93 = v89 * this->mTravelDirection.z;
  v94 = v91 * this->mTravelDirection.y;
  pos.x = pos.x + v92;
  pos.z = pos.z + v93;
  pos.y = pos.y + v94;
  UFG::TransformNodeComponent::SetWorldTranslation(v90, &pos);
LABEL_72:
  this->mWanderData.mLastUpdateFrame = UFG::Metrics::msFrameCount;
  return 1;
}

