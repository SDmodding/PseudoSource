// File Line: 67
// RVA: 0x2F6660
void __fastcall TargetFractureTask::Begin(TargetFractureTask *this, ActionContext *pContext)
{
  TargetFractureTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  ITrack *v7; // rax
  __int64 v8; // rcx
  int v9; // xmm1_4
  int v10; // xmm2_4
  bool v11; // r9
  int v12; // xmm3_4
  int v13; // xmm1_4
  __int64 v14; // r10
  __int64 v15; // rcx
  unsigned int v16; // [rsp+20h] [rbp-28h]
  int v17; // [rsp+24h] [rbp-24h]
  int v18; // [rsp+28h] [rbp-20h]
  int v19; // [rsp+30h] [rbp-18h]
  int v20; // [rsp+34h] [rbp-14h]
  int v21; // [rsp+38h] [rbp-10h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = v2->m_Track;
      v8 = LODWORD(v7[1].vfptr);
      v9 = *(_DWORD *)&v7[1].mBreakPoint;
      v10 = v7[1].mMasterRate.text.mOffset;
      v11 = BYTE4(v7[1].mMasterRate.text.mOffset) != 0;
      v16 = v7[1].m_TrackClassNameUID;
      v17 = v9;
      v18 = v10;
      v12 = HIDWORD(v7[1].mResourceOwner);
      v13 = (int)v7[1].mResourceOwner;
      v14 = *(unsigned __int8 *)(v8 + *(_QWORD *)&v5[1].m_Flags + 8);
      v15 = *(_QWORD *)&v5[1].m_TypeUID;
      v19 = HIDWORD(v7[1].vfptr);
      v20 = v13;
      v21 = v12;
      UFG::ShearObject(*(UFG::SimObject **)(56 * v14 + v15 + 40), (UFG::qVector3 *)&v19, (UFG::qVector3 *)&v16, v11);
    }
  }
}

// File Line: 87
// RVA: 0x2F6520
void __fastcall TargetFractureStrengthTask::Begin(TargetFractureStrengthTask *this, ActionContext *pContext)
{
  TargetFractureStrengthTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rcx
  UFG::RigidBodyComponent *v8; // r9
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBodyComponent> *v9; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::RigidBodyComponent *parentOut; // [rsp+38h] [rbp+10h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = *(UFG::SimObject **)(56i64
                              * *(unsigned __int8 *)(LODWORD(v2->m_Track[1].vfptr) + *(_QWORD *)&v5[1].m_Flags + 8i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
      parentOut = 0i64;
      UFG::PhysicsSystem::FindParentObjectOfSimObject(v7, &parentOut, &v2->mIndex);
      v8 = parentOut;
      if ( parentOut )
      {
        v9 = &v2->mRigidBody;
        if ( v2->mRigidBody.m_pPointer )
        {
          v10 = v9->mPrev;
          v11 = v2->mRigidBody.mNext;
          v10->mNext = v11;
          v11->mPrev = v10;
          v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
          v2->mRigidBody.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mRigidBody.mPrev;
        }
        v2->mRigidBody.m_pPointer = (UFG::SimComponent *)&v8->vfptr;
        if ( v8 )
        {
          v12 = v8->m_SafePointerList.mNode.mPrev;
          v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
          v9->mPrev = v12;
          v2->mRigidBody.mNext = &v8->m_SafePointerList.mNode;
          v8->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
        }
        UFG::RigidBody::DisableFracturePartByIndex((UFG::RigidBody *)v2->mRigidBody.m_pPointer, v2->mIndex);
        UFG::RigidBody::EnableFracturePartByIndex(
          (UFG::RigidBody *)v2->mRigidBody.m_pPointer,
          v2->mIndex,
          FRACTURE_STRENGTH_ALTERNATE);
      }
    }
  }
}

// File Line: 114
// RVA: 0x300CC0
void __fastcall TargetFractureStrengthTask::End(TargetFractureStrengthTask *this)
{
  TargetFractureStrengthTask *v1; // rbx
  UFG::RigidBody *v2; // rcx

  v1 = this;
  v2 = (UFG::RigidBody *)this->mRigidBody.m_pPointer;
  if ( v2 )
  {
    UFG::RigidBody::DisableFracturePartByIndex(v2, v1->mIndex);
    UFG::RigidBody::EnableFracturePartByIndex((UFG::RigidBody *)v1->mRigidBody.m_pPointer, v1->mIndex, 0);
  }
}

// File Line: 127
// RVA: 0x2F6AC0
void __fastcall TargetJumpTask::Begin(TargetJumpTask *this, ActionContext *context)
{
  TargetJumpTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  UFG::SimComponent *v4; // rdi
  UFG::SimComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterPhysicsComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObject *v12; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::SimObjectGame *v17; // rcx
  unsigned __int16 v18; // dx
  UFG::SimComponent *v19; // r8
  UFG::SimComponent *v20; // rax
  UFG::SimObject *v21; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::CharacterPhysicsComponent *v26; // rcx
  float v27; // xmm6_4
  UFG::CharacterPhysicsComponent *v28; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-28h]

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0i64;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::CharacterPhysicsComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CharacterPhysicsComponent::_TypeUID);
      }
      v5 = v7;
    }
  }
  else
  {
    v5 = 0i64;
  }
  v8 = &v2->m_pCharacterPhysicsComponent;
  if ( v2->m_pCharacterPhysicsComponent.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v2->m_pCharacterPhysicsComponent.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v2->m_pCharacterPhysicsComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pCharacterPhysicsComponent.mPrev;
  }
  v2->m_pCharacterPhysicsComponent.m_pPointer = v5;
  if ( v5 )
  {
    v11 = v5->m_SafePointerList.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mPrev = v11;
    v2->m_pCharacterPhysicsComponent.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
  v12 = v2->mContext->mSimObject.m_pPointer;
  if ( v12 )
    v4 = (UFG::SimComponent *)&v12->m_pTransformNodeComponent->vfptr;
  v13 = &v2->m_pTransformNodeComponent;
  if ( v2->m_pTransformNodeComponent.m_pPointer )
  {
    v14 = v13->mPrev;
    v15 = v2->m_pTransformNodeComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v2->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTransformNodeComponent.mPrev;
  }
  v2->m_pTransformNodeComponent.m_pPointer = v4;
  if ( v4 )
  {
    v16 = v4->m_SafePointerList.mNode.mPrev;
    v16->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
    v13->mPrev = v16;
    v2->m_pTransformNodeComponent.mNext = &v4->m_SafePointerList.mNode;
    v4->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
  }
  v17 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
  if ( v17 )
  {
    v18 = v17->m_Flags;
    if ( (v18 >> 14) & 1 )
    {
      v19 = v17->m_Components.p[20].m_pComponent;
    }
    else if ( (v18 & 0x8000u) == 0 )
    {
      if ( (v18 >> 13) & 1 )
        v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v20 = (v18 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v17,
                                  UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v17->vfptr,
                                                                                   UFG::TargetingSystemBaseComponent::_TypeUID);
      v19 = v20;
    }
    else
    {
      v19 = v17->m_Components.p[20].m_pComponent;
    }
    if ( v19 )
    {
      v21 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)(HIDWORD(v2->m_Track[1].mResourceOwner)
                                                    + *(_QWORD *)&v19[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&v19[1].m_TypeUID
                               + 40);
      v22 = &v2->m_pTargetSimObject;
      if ( v2->m_pTargetSimObject.m_pPointer )
      {
        v23 = v22->mPrev;
        v24 = v2->m_pTargetSimObject.mNext;
        v23->mNext = v24;
        v24->mPrev = v23;
        v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v22->mPrev;
        v2->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->m_pTargetSimObject.mPrev;
      }
      v2->m_pTargetSimObject.m_pPointer = v21;
      if ( v21 )
      {
        v25 = v21->m_SafePointerList.mNode.mPrev;
        v25->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v22->mPrev;
        v22->mPrev = v25;
        v2->m_pTargetSimObject.mNext = &v21->m_SafePointerList.mNode;
        v21->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v22->mPrev;
      }
    }
  }
  v26 = (UFG::CharacterPhysicsComponent *)v2->m_pCharacterPhysicsComponent.m_pPointer;
  if ( v26 && v2->m_pTransformNodeComponent.m_pPointer )
  {
    if ( v2->m_pTargetSimObject.m_pPointer )
    {
      v27 = *(float *)&v2->m_Track[1].vfptr;
      UFG::CharacterPhysicsComponent::GetVelocity(v26, &result);
      v28 = (UFG::CharacterPhysicsComponent *)v2->m_pCharacterPhysicsComponent.m_pPointer;
      result.x = result.x + (float)(UFG::qVector3::msDirUp.x * v27);
      result.y = result.y + (float)(UFG::qVector3::msDirUp.y * v27);
      result.z = result.z + (float)(UFG::qVector3::msDirUp.z * v27);
      UFG::CharacterPhysicsComponent::SetVelocity(v28, &result);
    }
  }
}

// File Line: 158
// RVA: 0x30CB30
void __fastcall debugDrawTrajectory(float tFlight, float gravity, UFG::qVector3 *startPoint, UFG::qVector3 *vXYdir, const float vXY, const float vUpStart, float dt)
{
  float v7; // xmm3_4
  float v8; // xmm2_4
  UFG::qVector3 *v9; // rbx
  float v10; // xmm10_4
  float v11; // xmm11_4
  float v12; // xmm12_4
  Render::DebugDrawContext *v13; // rdi
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm13_4
  float v17; // xmm8_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  UFG::qVector3 p1; // [rsp+40h] [rbp-A8h]
  UFG::qVector3 p0; // [rsp+50h] [rbp-98h]

  v7 = startPoint->y;
  v8 = startPoint->z;
  v9 = vXYdir;
  v10 = 0.0;
  v11 = vUpStart;
  p0.x = startPoint->x;
  p0.y = v7;
  v12 = tFlight;
  p0.z = v8;
  p1.x = p0.x;
  p1.y = v7;
  p1.z = v8;
  v13 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  if ( tFlight > 0.0 )
  {
    v14 = p1.y;
    v15 = p1.x;
    v16 = p1.z;
    v17 = vXY * dt;
    do
    {
      v18 = v11;
      v11 = v11 + (float)(gravity * dt);
      v19 = v17 * v9->y;
      v20 = (float)((float)(v17 * v9->z) + v16)
          + (float)((float)(v18 * dt) + (float)((float)(dt * dt) * (float)(gravity * 0.5)));
      p1.x = v15 + (float)(v17 * v9->x);
      p1.z = v20;
      p1.y = v14 + v19;
      Render::DebugDrawContext::DrawLine(v13, &p0, &p1, &UFG::qColour::Green, &UFG::qMatrix44::msIdentity, 0i64, 0);
      v15 = p1.x;
      v14 = p1.y;
      v16 = p1.z;
      v10 = v10 + dt;
      p0 = p1;
    }
    while ( v10 < v12 );
  }
}

// File Line: 185
// RVA: 0x30A820
char __fastcall TargetJumpTask::Update(TargetJumpTask *this, float timeDelta)
{
  TargetJumpTask *v2; // rdi
  UFG::SimObjectCVBase *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::TransformNodeComponent *v5; // rsi
  UFG::CharacterAnimationComponent *v6; // rax
  Creature *v7; // r14
  int v8; // er15
  float *v9; // rbx
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  ITrack *v35; // rax
  __m128 v36; // xmm6
  float v37; // xmm7_4
  float v38; // xmm3_4
  __m128 v39; // xmm4
  float v40; // xmm5_4
  __m128 v41; // xmm10
  float v42; // xmm2_4
  float v43; // xmm1_4
  UFG::CharacterPhysicsComponent *v44; // rcx
  float v45; // xmm9_4
  float v46; // xmm11_4
  UFG::SimComponent *v47; // rbx
  float v48; // xmm12_4
  __m128 v49; // xmm13
  float v50; // xmm8_4
  float v51; // xmm9_4
  float v52; // xmm12_4
  float v53; // xmm13_4
  float v54; // xmm14_4
  float v55; // xmm10_4
  float v56; // xmm8_4
  UFG::TransformNodeComponent *v57; // rcx
  float v58; // xmm1_4
  UFG::CharacterPhysicsComponent *v59; // rcx
  Render::DebugDrawContext *v60; // rax
  Render::DebugDrawContext *v61; // rbx
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  UFG::qVector3 pos; // [rsp+50h] [rbp-B0h]
  UFG::qVector3 p0; // [rsp+60h] [rbp-A0h]
  UFG::qVector3 result; // [rsp+70h] [rbp-90h]
  UFG::qVector3 velocity; // [rsp+80h] [rbp-80h]
  UFG::qMatrix44 xform; // [rsp+90h] [rbp-70h]
  UFG::qMatrix44 transform; // [rsp+D0h] [rbp-30h]
  UFG::qVector3 v71; // [rsp+110h] [rbp+10h]
  UFG::qVector3 p1; // [rsp+120h] [rbp+20h]

  v2 = this;
  if ( this->m_pCharacterPhysicsComponent.m_pPointer )
  {
    if ( this->m_pTransformNodeComponent.m_pPointer )
    {
      v3 = (UFG::SimObjectCVBase *)this->m_pTargetSimObject.m_pPointer;
      if ( v3 )
      {
        v4 = v3->m_Flags;
        v5 = v3->m_pTransformNodeComponent;
        if ( (v4 >> 14) & 1 )
        {
          v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
        }
        else if ( (v4 & 0x8000u) == 0 )
        {
          if ( (v4 >> 13) & 1 )
            v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v3);
          else
            v6 = (UFG::CharacterAnimationComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         (UFG::SimObjectGame *)&v3->vfptr,
                                                                         UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
        }
        else
        {
          v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
        }
        if ( v5 )
        {
          if ( v6 )
          {
            v7 = v6->mCreature;
            if ( v7 )
            {
              if ( v7->mPose.mRigHandle.mData )
              {
                v8 = Skeleton::GetBoneID(v7->mPose.mRigHandle.mUFGSkeleton, v2->m_Track[1].m_TrackClassNameUID);
                if ( v8 >= 0 )
                {
                  TargetJumpTask::getTargetsVelocity(v2, &result, v2->m_pTargetSimObject.m_pPointer);
                  v9 = (float *)v2->m_pTransformNodeComponent.m_pPointer;
                  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pPointer);
                  v10 = v9[34];
                  v11 = v9[35];
                  v12 = v9[32];
                  xform.v0.y = v9[33];
                  xform.v0.z = v10;
                  xform.v0.x = v12;
                  xform.v0.w = v11;
                  v13 = v9[37];
                  v14 = v9[38];
                  v15 = v9[39];
                  xform.v1.x = v9[36];
                  xform.v1.y = v13;
                  xform.v1.z = v14;
                  xform.v1.w = v15;
                  v16 = v9[42];
                  v17 = v9[43];
                  v18 = v9[40];
                  xform.v2.y = v9[41];
                  xform.v2.x = v18;
                  xform.v2.z = v16;
                  xform.v2.w = v17;
                  v19 = v9[46];
                  v20 = v9[47];
                  v21 = v9[44];
                  xform.v3.y = v9[45];
                  xform.v3.z = v19;
                  xform.v3.x = v21;
                  xform.v3.w = v20;
                  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
                  v22 = v5->mWorldTransform.v0.y;
                  transform.v0.x = v5->mWorldTransform.v0.x;
                  v23 = v5->mWorldTransform.v0.z;
                  transform.v0.y = v22;
                  v24 = v5->mWorldTransform.v0.w;
                  transform.v0.z = v23;
                  transform.v1.x = v5->mWorldTransform.v1.x;
                  v25 = v5->mWorldTransform.v1.z;
                  transform.v0.w = v24;
                  v26 = v5->mWorldTransform.v1.y;
                  transform.v1.z = v25;
                  v27 = v5->mWorldTransform.v2.x;
                  transform.v1.y = v26;
                  v28 = v5->mWorldTransform.v1.w;
                  transform.v2.x = v27;
                  v29 = v5->mWorldTransform.v2.z;
                  transform.v1.w = v28;
                  v30 = v5->mWorldTransform.v2.y;
                  transform.v2.z = v29;
                  v31 = v5->mWorldTransform.v3.x;
                  transform.v2.y = v30;
                  v32 = v5->mWorldTransform.v2.w;
                  transform.v3.x = v31;
                  v33 = v5->mWorldTransform.v3.z;
                  transform.v2.w = v32;
                  v34 = v5->mWorldTransform.v3.y;
                  transform.v3.z = v33;
                  transform.v3.y = v34;
                  transform.v3.w = v5->mWorldTransform.v3.w;
                  Creature::GetTransform(v7, v8, &transform);
                  v35 = v2->m_Track;
                  v36 = (__m128)LODWORD(transform.v3.y);
                  v37 = 0.0;
                  v39 = (__m128)LODWORD(transform.v3.y);
                  v38 = transform.v3.x - xform.v3.x;
                  v39.m128_f32[0] = transform.v3.y - xform.v3.y;
                  v41 = v39;
                  v40 = transform.v3.z - xform.v3.z;
                  p1 = *(UFG::qVector3 *)&transform.v3.x;
                  v41.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v38 * v38))
                                  + (float)(v40 * v40);
                  v42 = *(float *)&v35[1].mResourceOwner;
                  if ( v41.m128_f32[0] == 0.0 )
                    v43 = 0.0;
                  else
                    v43 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v41));
                  v44 = (UFG::CharacterPhysicsComponent *)v2->m_pCharacterPhysicsComponent.m_pPointer;
                  transform.v3.y = transform.v3.y - (float)(v42 * (float)(v39.m128_f32[0] * v43));
                  v36.m128_f32[0] = transform.v3.y - xform.v3.y;
                  transform.v3.w = transform.v3.w + -1.0;
                  transform.v3.x = transform.v3.x - (float)(v42 * (float)(v38 * v43));
                  transform.v3.z = transform.v3.z - (float)(v42 * (float)(v40 * v43));
                  v45 = transform.v3.x - xform.v3.x;
                  v46 = transform.v3.z - xform.v3.z;
                  UFG::CharacterPhysicsComponent::GetVelocity(v44, &v71);
                  v47 = v2->m_pTransformNodeComponent.m_pPointer;
                  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pPointer);
                  v48 = *(float *)&v47[2].vfptr;
                  v49 = (__m128)HIDWORD(v47[2].vfptr);
                  if ( (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(v48 * v48)) == 0.0 )
                    v50 = 0.0;
                  else
                    v50 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v49));
                  v36.m128_f32[0] = (float)(v36.m128_f32[0] * v36.m128_f32[0]) + (float)(v45 * v45);
                  v51 = v71.z;
                  v52 = v48 * v50;
                  v53 = v49.m128_f32[0] * v50;
                  v54 = *((float *)&v2->m_Track[1].vfptr + 1);
                  v55 = COERCE_FLOAT(_mm_sqrt_ps(v36)) / v54;
                  v56 = v50 * 0.0;
                  if ( v71.z < 0.0 && v46 > 0.0 )
                  {
                    v57 = (UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pPointer;
                    v51 = 0.0;
                    pos.x = xform.v3.x;
                    pos.y = xform.v3.y;
                    pos.z = transform.v3.z;
                    UFG::TransformNodeComponent::SetLocalTranslation(v57, &pos);
                    goto LABEL_32;
                  }
                  v58 = (float)((float)((float)(v71.z * v55) - v46) * -2.0) / (float)(v55 * v55);
                  if ( v58 <= -100.0 )
                  {
                    v58 = FLOAT_N100_0;
                  }
                  else if ( v58 >= 0.0 )
                  {
LABEL_32:
                    *(float *)&v2->m_pCharacterPhysicsComponent.m_pPointer[9].m_SafePointerList.mNode.mPrev = v37;
                    v59 = (UFG::CharacterPhysicsComponent *)v2->m_pCharacterPhysicsComponent.m_pPointer;
                    result.z = 0.0;
                    velocity.x = result.x + (float)((float)(v51 * UFG::qVector3::msAxisZ.x) + (float)(v52 * v54));
                    velocity.y = result.y + (float)((float)(v51 * UFG::qVector3::msAxisZ.y) + (float)(v53 * v54));
                    velocity.z = (float)(v51 * UFG::qVector3::msAxisZ.z) + (float)(v54 * v56);
                    UFG::CharacterPhysicsComponent::SetVelocity(v59, &velocity);
                    if ( sTargetJumpTaskDebug )
                    {
                      v60 = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                          Render::DebugDrawManager::mInstance,
                                                          1u);
                      pos = *(UFG::qVector3 *)&transform.v3.x;
                      v61 = v60;
                      Render::DebugDrawContext::DrawArrow(
                        v60,
                        &pos,
                        &p1,
                        &UFG::qColour::Green,
                        &UFG::qMatrix44::msIdentity,
                        0i64);
                      pos.z = xform.v3.z + v71.z;
                      pos.x = v71.x + xform.v3.x;
                      pos.y = v71.y + xform.v3.y;
                      p0 = *(UFG::qVector3 *)&xform.v3.x;
                      Render::DebugDrawContext::DrawArrow(
                        v61,
                        &p0,
                        &pos,
                        &UFG::qColour::Green,
                        &UFG::qMatrix44::msIdentity,
                        0i64);
                      p0.x = xform.v3.x;
                      p0.y = xform.v3.y;
                      v62 = (__m128)LODWORD(result.x);
                      p0.z = xform.v3.z + 1.4;
                      v63 = (__m128)LODWORD(velocity.y);
                      v62.m128_f32[0] = (float)(v62.m128_f32[0] * v62.m128_f32[0]) + (float)(result.y * result.y);
                      v63.m128_f32[0] = (float)(v63.m128_f32[0] * v63.m128_f32[0]) + (float)(velocity.x * velocity.x);
                      Render::DebugDrawContext::DrawText(
                        v61,
                        &p0,
                        &UFG::qColour::Green,
                        "Vxy:%f.3\n VxyCar:%f.3\nVZ:%f.3\nVZa:%f.3\nVZcar:%f.3\n",
                        COERCE_FLOAT(_mm_sqrt_ps(v63)),
                        COERCE_FLOAT(_mm_sqrt_ps(v62)),
                        v51,
                        velocity.z,
                        result.z);
                      p0 = *(UFG::qVector3 *)&transform.v3.x;
                      pos = *(UFG::qVector3 *)&xform.v3.x;
                      Render::DebugDrawContext::DrawLine(
                        v61,
                        &pos,
                        &p0,
                        &UFG::qColour::Red,
                        &UFG::qMatrix44::msIdentity,
                        0i64,
                        0);
                      Render::DebugDrawContext::DrawAxes(v61, &xform, 0.5, 0, 0i64);
                      Render::DebugDrawContext::DrawAxes(v61, &transform, 0.5, 0, 0i64);
                      pos.y = xform.v3.y;
                      pos.x = xform.v3.x;
                      p0.x = v52;
                      p0.y = v53;
                      p0.z = v56;
                      pos.z = xform.v3.z;
                      debugDrawTrajectory(v55, v37, &pos, &p0, v54, v51, 0.033333335);
                    }
                    return 1;
                  }
                  v37 = v58;
                  goto LABEL_32;
                }
              }
            }
          }
        }
      }
    }
  }
  return 1;
}

// File Line: 308
// RVA: 0x30D450
UFG::qVector3 *__fastcall TargetJumpTask::getTargetsVelocity(TargetJumpTask *this, UFG::qVector3 *result, UFG::SimObject *simObject)
{
  UFG::SimObjectVehicle *v3; // rbx
  UFG::qVector3 *v4; // rdi
  unsigned __int16 v5; // cx
  UFG::BoatPhysicsMoverComponent *v6; // rax
  UFG::qVector3 *v7; // rax
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // cx
  float v10; // xmm1_4
  float v11; // xmm2_4

  v3 = (UFG::SimObjectVehicle *)simObject;
  v4 = result;
  if ( simObject
    && ((v5 = simObject->m_Flags, !((v5 >> 14) & 1))
     && ((v5 & 0x8000u) == 0 ? (!((v5 >> 13) & 1) ? (!((v5 >> 12) & 1) ? (v6 = (UFG::BoatPhysicsMoverComponent *)UFG::SimObject::GetComponentOfType(simObject, UFG::CarPhysicsMoverComponent::_TypeUID)) : (v6 = (UFG::BoatPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)simObject, UFG::CarPhysicsMoverComponent::_TypeUID))) : (v6 = (UFG::BoatPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)simObject, UFG::CarPhysicsMoverComponent::_TypeUID))) : (v6 = (UFG::BoatPhysicsMoverComponent *)UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>((UFG::SimObjectVehicle *)simObject)),
         v6)
     || (v8 = v3->m_Flags, !((v8 >> 14) & 1))
     && ((v8 & 0x8000u) == 0 ? (!((v8 >> 13) & 1) ? (!((v8 >> 12) & 1) ? (v6 = (UFG::BoatPhysicsMoverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::BikePhysicsMoverComponent::_TypeUID)) : (v6 = (UFG::BoatPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::BikePhysicsMoverComponent::_TypeUID))) : (v6 = (UFG::BoatPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::BikePhysicsMoverComponent::_TypeUID))) : (v6 = (UFG::BoatPhysicsMoverComponent *)UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(v3)),
         v6)
     || (v9 = v3->m_Flags, !((v9 >> 14) & 1))
     && ((v9 & 0x8000u) == 0 ? (!((v9 >> 13) & 1) ? (!((v9 >> 12) & 1) ? (v6 = (UFG::BoatPhysicsMoverComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::BoatPhysicsMoverComponent::_TypeUID)) : (v6 = (UFG::BoatPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::BoatPhysicsMoverComponent::_TypeUID))) : (v6 = (UFG::BoatPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v3->vfptr, UFG::BoatPhysicsMoverComponent::_TypeUID))) : (v6 = UFG::SimObjectVehicle::GetComponent<UFG::BoatPhysicsMoverComponent>(v3)),
         v6)) )
  {
    UFG::PhysicsMoverInterface::GetVelocity((UFG::PhysicsMoverInterface *)&v6->vfptr, v4);
    v7 = v4;
  }
  else
  {
    v10 = UFG::qVector3::msZero.y;
    v11 = UFG::qVector3::msZero.z;
    v7 = v4;
    v4->x = UFG::qVector3::msZero.x;
    v4->y = v10;
    v4->z = v11;
  }
  return v7;
}

// File Line: 341
// RVA: 0x2E1D20
void __fastcall TargetPlayEffectTask::TargetPlayEffectTask(TargetPlayEffectTask *this)
{
  TargetPlayEffectTask *v1; // rbx
  UFG::qNode<ITask,ITask> *v2; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v3; // [rsp+48h] [rbp+10h]
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v4; // [rsp+48h] [rbp+10h]

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<TargetPlayEffectTrack>::`vftable';
  FX::HardwareOcclusionQuery::HardwareOcclusionQuery((FX::HardwareOcclusionQuery *)&this->mFXHandle);
  v1->vfptr = (ITaskVtbl *)&TargetPlayEffectTask::`vftable';
  v3 = &v1->m_pTSBC;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->m_pTSBC.m_pPointer = 0i64;
  v4 = &v1->m_pTargetSimObject;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v1->m_pTargetSimObject.m_pPointer = 0i64;
}

// File Line: 346
// RVA: 0x2E5790
void __fastcall TargetPlayEffectTask::~TargetPlayEffectTask(TargetPlayEffectTask *this)
{
  TargetPlayEffectTask *v1; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rdx
  UFG::qNode<ITask,ITask> *v13; // rcx
  UFG::qNode<ITask,ITask> *v14; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&TargetPlayEffectTask::`vftable';
  v2 = &this->m_pTargetSimObject;
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1->m_pTSBC;
  if ( v1->m_pTSBC.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->m_pTSBC.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->m_pTSBC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTSBC.mPrev;
  }
  v1->m_pTSBC.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->m_pTSBC.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->m_pTSBC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTSBC.mPrev;
  _((AMD_HD3D *)&v1->mFXHandle);
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v12 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v13 = v1->mPrev;
  v14 = v1->mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v12->mPrev = v12;
  v12->mNext = v12;
}

// File Line: 351
// RVA: 0x2F8180
void __fastcall TargetPlayEffectTask::Begin(TargetPlayEffectTask *this, ActionContext *context)
{
  TargetPlayEffectTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  PlayEffectBaseTrack *v4; // rsi
  UFG::SimComponent *v5; // r8
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimComponent *v12; // r9
  ITrack *v13; // r8
  UFG::SimObject *pSimObject; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v15; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0i64;
  if ( v3 )
  {
    v6 = v3->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v6 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v7;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v5 = 0i64;
  }
  v8 = &v2->m_pTSBC;
  if ( v2->m_pTSBC.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v2->m_pTSBC.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v2->m_pTSBC.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_pTSBC.mPrev;
  }
  v2->m_pTSBC.m_pPointer = v5;
  if ( v5 )
  {
    v11 = v5->m_SafePointerList.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v8->mPrev = v11;
    v2->m_pTSBC.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
  }
  v12 = v2->m_pTSBC.m_pPointer;
  if ( v12 )
  {
    v13 = v2->m_Track;
    pSimObject = *(UFG::SimObject **)(56i64
                                    * *(unsigned __int8 *)(LODWORD(v13[2].mTimeBegin) + *(_QWORD *)&v12[1].m_Flags + 8i64)
                                    + *(_QWORD *)&v12[1].m_TypeUID
                                    + 40);
    if ( pSimObject )
    {
      if ( v13 )
        v4 = (PlayEffectBaseTrack *)&v13[1];
      PlayEffectBaseTask::playEffectBegin(
        (PlayEffectBaseTask *)&v2->mFXHandle,
        v2->mContext,
        v4,
        v13->mTimeBegin,
        v13->mTimeEnd,
        pSimObject);
      v15 = &v2->m_pTargetSimObject;
      if ( v2->m_pTargetSimObject.m_pPointer )
      {
        v16 = v15->mPrev;
        v17 = v2->m_pTargetSimObject.mNext;
        v16->mNext = v17;
        v17->mPrev = v16;
        v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
        v2->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->m_pTargetSimObject.mPrev;
      }
      v2->m_pTargetSimObject.m_pPointer = pSimObject;
      v18 = pSimObject->m_SafePointerList.mNode.mPrev;
      v18->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
      v15->mPrev = v18;
      v2->m_pTargetSimObject.mNext = &pSimObject->m_SafePointerList.mNode;
      pSimObject->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v15->mPrev;
    }
  }
}

// File Line: 370
// RVA: 0x30B0F0
char __fastcall TargetPlayEffectTask::Update(TargetPlayEffectTask *this, float timeDelta)
{
  TargetPlayEffectTask *v2; // rbx
  UFG::SimComponent *v3; // rcx
  int v4; // esi
  UFG::SimObject *v5; // rdi
  UFG::SimObject *pSimObject; // rax
  ITrack *v7; // rcx
  PlayEffectBaseTrack *v8; // r8
  ITrack *v9; // rax
  PlayEffectBaseTrack *v10; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v11; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  ITrack *v15; // rax

  v2 = this;
  v3 = this->m_pTSBC.m_pPointer;
  v4 = 0;
  if ( v3 )
    v5 = *(UFG::SimObject **)(56i64
                            * *(unsigned __int8 *)(LODWORD(v2->m_Track[2].mTimeBegin) + *(_QWORD *)&v3[1].m_Flags + 8i64)
                            + *(_QWORD *)&v3[1].m_TypeUID
                            + 40);
  else
    v5 = 0i64;
  pSimObject = v2->m_pTargetSimObject.m_pPointer;
  if ( pSimObject && v5 != pSimObject )
  {
    v7 = v2->m_Track;
    v8 = (PlayEffectBaseTrack *)&v7[1];
    if ( !v7 )
      v8 = 0i64;
    PlayEffectBaseTask::playEffectEnd(
      (PlayEffectBaseTask *)&v2->mFXHandle,
      v2->mContext,
      v8,
      v7->mTimeBegin,
      v7->mTimeEnd,
      pSimObject);
    if ( v5 )
    {
      v9 = v2->m_Track;
      v10 = (PlayEffectBaseTrack *)&v9[1];
      if ( !v9 )
        v10 = 0i64;
      PlayEffectBaseTask::playEffectBegin(
        (PlayEffectBaseTask *)&v2->mFXHandle,
        v2->mContext,
        v10,
        v9->mTimeBegin,
        v9->mTimeEnd,
        v5);
    }
    v11 = &v2->m_pTargetSimObject;
    if ( v2->m_pTargetSimObject.m_pPointer )
    {
      v12 = v11->mPrev;
      v13 = v2->m_pTargetSimObject.mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      v11->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
      v2->m_pTargetSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->m_pTargetSimObject.mPrev;
    }
    v2->m_pTargetSimObject.m_pPointer = v5;
    if ( v5 )
    {
      v14 = v5->m_SafePointerList.mNode.mPrev;
      v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
      v11->mPrev = v14;
      v2->m_pTargetSimObject.mNext = &v5->m_SafePointerList.mNode;
      v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v11->mPrev;
    }
  }
  v15 = v2->m_Track;
  if ( v15 )
    v4 = (_DWORD)v15 + 56;
  Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
    (hkGeometryUtils::IVertices *)&v2->mFXHandle,
    (int)v2->mContext,
    v4);
  return 1;
}

// File Line: 394
// RVA: 0x301010
void __fastcall TargetPlayEffectTask::End(TargetPlayEffectTask *this)
{
  ITrack *v1; // rdx
  PlayEffectBaseTrack *v2; // r8

  v1 = this->m_Track;
  if ( v1 )
    v2 = (PlayEffectBaseTrack *)&v1[1];
  else
    v2 = 0i64;
  PlayEffectBaseTask::playEffectEnd(
    (PlayEffectBaseTask *)&this->mFXHandle,
    this->mContext,
    v2,
    v1->mTimeBegin,
    v1->mTimeEnd,
    this->m_pTargetSimObject.m_pPointer);
}

// File Line: 402
// RVA: 0x2F5F30
void __fastcall TargetDamageTask::Begin(TargetDamageTask *this, ActionContext *context)
{
  TargetDamageTask *v2; // r13
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // r15
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rbx
  unsigned __int16 v9; // cx
  UFG::HealthComponent *v10; // rbp
  UFG::SimComponent *v11; // rax
  unsigned __int16 v12; // cx
  UFG::SimComponent *v13; // rdi
  UFG::SimComponent *v14; // rax
  UFG::SimObjectGame *v15; // rsi
  UFG::HitRecord *v16; // r14
  float v17; // xmm6_4
  unsigned __int16 v18; // cx
  UFG::SimComponent *v19; // rcx
  UFG::SimComponent *v20; // rax
  __int64 v21; // rax
  UFG::SimObjectProp *v22; // rcx
  unsigned __int16 v23; // dx
  UFG::SimObjectWeaponPropertiesComponent *v24; // rax
  signed int v25; // eax
  bool v26; // si
  UFG::CopSystem *v27; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( !((v3->m_Flags >> 10) & 1) && v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v6 = v7;
    }
    else
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v6 )
    {
      v8 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LODWORD(v2->m_Track[1].mMasterRate.text.mOffset)
                                                       + *(_QWORD *)&v6[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&v6[1].m_TypeUID
                                  + 40);
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = (UFG::HealthComponent *)v8->m_Components.p[6].m_pComponent;
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HealthComponent::_TypeUID);
          else
            v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HealthComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::HealthComponent::_TypeUID);
          v10 = (UFG::HealthComponent *)v11;
        }
        else
        {
          v10 = (UFG::HealthComponent *)v8->m_Components.p[6].m_pComponent;
        }
        if ( v10 )
        {
          v12 = v8->m_Flags;
          if ( (v8->m_Flags >> 14) & 1 )
          {
            v13 = v8->m_Components.p[15].m_pComponent;
          }
          else if ( (v12 & 0x8000u) == 0 )
          {
            if ( (v12 >> 13) & 1 )
            {
              v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HitReactionComponent::_TypeUID);
            }
            else if ( (v12 >> 12) & 1 )
            {
              v14 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HitReactionComponent::_TypeUID);
            }
            else
            {
              v14 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v8->vfptr,
                      UFG::HitReactionComponent::_TypeUID);
            }
            v13 = v14;
          }
          else
          {
            v13 = v8->m_Components.p[15].m_pComponent;
          }
          if ( v13 )
          {
            v15 = *(UFG::SimObjectGame **)&v13[3].m_TypeUID;
            v16 = (UFG::HitRecord *)&v13[2].m_BoundComponentHandles.mNode.mNext;
          }
          else
          {
            v16 = 0i64;
            v15 = 0i64;
          }
          v17 = *(float *)&FLOAT_1_0;
          if ( v15 )
          {
            v18 = v15->m_Flags;
            if ( (v18 >> 14) & 1 )
            {
              v19 = v15->m_Components.p[20].m_pComponent;
            }
            else if ( (v18 & 0x8000u) == 0 )
            {
              if ( (v18 >> 13) & 1 )
              {
                v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::TargetingSystemBaseComponent::_TypeUID);
              }
              else if ( (v18 >> 12) & 1 )
              {
                v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::TargetingSystemBaseComponent::_TypeUID);
              }
              else
              {
                v20 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)&v15->vfptr,
                        UFG::TargetingSystemBaseComponent::_TypeUID);
              }
              v19 = v20;
            }
            else
            {
              v19 = v15->m_Components.p[20].m_pComponent;
            }
            if ( v19 )
            {
              v21 = ((__int64 (*)(void))v19->vfptr[15].__vecDelDtor)();
              if ( v21 )
              {
                v22 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v21 + 96) + 25i64)
                                             + *(_QWORD *)(v21 + 88)
                                             + 40);
                if ( v22 )
                {
                  v23 = v22->m_Flags;
                  if ( (v23 >> 14) & 1 )
                  {
                    v24 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v22->vfptr,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                  }
                  else if ( (v23 & 0x8000u) == 0 )
                  {
                    if ( (v23 >> 13) & 1 )
                      v24 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v22);
                    else
                      v24 = (UFG::SimObjectWeaponPropertiesComponent *)((v23 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                            (UFG::SimObjectGame *)&v22->vfptr,
                                                                                            UFG::SimObjectWeaponPropertiesComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v22->vfptr, UFG::SimObjectWeaponPropertiesComponent::_TypeUID));
                  }
                  else
                  {
                    v24 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       (UFG::SimObjectGame *)&v22->vfptr,
                                                                       UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
                  }
                  if ( v24 )
                    v17 = v24->mWeaponTypeInfo->mFireModes[v24->mFireMode]->mDamageMultiplier;
                }
              }
            }
          }
          v25 = ExpressionParameterInt::operator long((ExpressionParameterInt *)&v2->m_Track[1]);
          v26 = UFG::HealthComponent::ApplyHealthDamage(
                  v10,
                  (signed int)(float)((float)v25 * v17),
                  (UFG::SimObject *)&v15->vfptr,
                  v16,
                  0);
          if ( v26 )
          {
            if ( v13 )
            {
              v27 = UFG::CopSystem::Instance();
              ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObject *, UFG::SimObjectGame *, UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **, UFG::HealthComponent *, bool))v27->vfptr[95].__vecDelDtor)(
                v27,
                v4->mSimObject.m_pPointer,
                v8,
                &v13[2].m_BoundComponentHandles.mNode.mNext,
                v10,
                v26);
            }
          }
        }
      }
    }
  }
}

// File Line: 462
// RVA: 0x2F8300
void __fastcall TargetPlayTask::Begin(TargetPlayTask *this, ActionContext *context)
{
  ActionContext *v2; // r9
  TargetPlayTask *v3; // rbx
  ITrack *v4; // rcx
  ActionNode *v5; // rsi
  Expression::IMemberMapVtbl *v6; // rax
  signed __int64 v7; // rax
  __int64 v8; // rdx
  UFG::eTargetTypeEnum v9; // er14
  UFG::SimObject *v10; // rax
  __int64 v11; // r9
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qList<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList,1,0> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::SimObjectGame *v17; // rcx
  unsigned __int16 v18; // dx
  UFG::SimComponent *v19; // rdi
  UFG::SimComponent *v20; // rax
  UFG::SimObjectGame *v21; // rcx
  unsigned __int16 v22; // dx
  UFG::PowerManagementComponent *v23; // rax
  UFG::SimObject *v24; // rcx
  UEL::ParametersBase *v25; // rbp
  unsigned __int16 v26; // dx
  UEL::ParametersBase *v27; // rax
  ITrack *v28; // rax
  ActionController *v29; // rdi
  Expression::IMemberMapVtbl *v30; // rcx
  signed __int64 v31; // rcx
  __int64 v32; // rdx
  signed __int64 v33; // rcx
  __int64 v34; // rax
  ITrack *v35; // rdx
  UFG::SimObjectGame *v36; // rcx
  unsigned __int16 v37; // dx
  UFG::SimComponent *v38; // rcx
  UFG::SimComponent *v39; // rax
  int v40; // ST20_4
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v41; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v42; // rax

  this->mContext = context;
  v2 = context;
  v3 = this;
  if ( !((context->mSimObject.m_pPointer->m_Flags >> 10) & 1) )
  {
    v4 = this->m_Track;
    v5 = 0i64;
    v6 = v4[1].vfptr;
    v7 = (signed __int64)(v6 ? (void (__fastcall **)(Expression::IMemberMap *))((char *)&v6->ResolveReferences
                                                                              + (_QWORD)v4) : 0i64);
    v8 = *(_QWORD *)(v7 + 72);
    if ( v8 )
    {
      if ( v8 + v7 + 72 )
      {
        v9 = (UFG::eTargetTypeEnum)v4[2].mResourceOwner;
        v10 = UFG::getTarget(v2, v9);
        v12 = &v3->mTarget;
        if ( v3->mTarget.m_pPointer )
        {
          v13 = v12->mPrev;
          v14 = v3->mTarget.mNext;
          v13->mNext = v14;
          v14->mPrev = v13;
          v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
          v3->mTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mTarget.mPrev;
        }
        v3->mTarget.m_pPointer = v10;
        if ( v10 )
        {
          v15 = &v10->m_SafePointerList;
          v16 = v10->m_SafePointerList.mNode.mPrev;
          v16->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
          v12->mPrev = v16;
          v3->mTarget.mNext = &v15->mNode;
          v15->mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
        }
        v17 = (UFG::SimObjectGame *)v3->mTarget.m_pPointer;
        if ( v17 )
        {
          if ( v17 == (UFG::SimObjectGame *)v3->mContext->mSimObject.m_pPointer )
          {
            if ( v3->mTarget.m_pPointer )
            {
              v41 = v12->mPrev;
              v42 = v3->mTarget.mNext;
              v41->mNext = v42;
              v42->mPrev = v41;
              v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
              v3->mTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mTarget.mPrev;
            }
            v3->mTarget.m_pPointer = 0i64;
          }
          else
          {
            v18 = v17->m_Flags;
            if ( (v18 >> 14) & 1 )
            {
              v19 = v17->m_Components.p[7].m_pComponent;
            }
            else if ( (v18 & 0x8000u) == 0 )
            {
              if ( (v18 >> 13) & 1 )
              {
                v19 = v17->m_Components.p[6].m_pComponent;
              }
              else
              {
                if ( (v18 >> 12) & 1 )
                  v20 = UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::ActionTreeComponent::_TypeUID);
                else
                  v20 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v17->vfptr,
                          UFG::ActionTreeComponent::_TypeUID);
                v19 = v20;
              }
            }
            else
            {
              v19 = v17->m_Components.p[7].m_pComponent;
            }
            if ( v19 )
            {
              v21 = (UFG::SimObjectGame *)v3->mTarget.m_pPointer;
              if ( v21 )
              {
                v22 = v21->m_Flags;
                if ( (v22 >> 14) & 1 )
                {
                  v23 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v21,
                                                           UFG::PowerManagementComponent::_TypeUID);
                }
                else if ( (v22 & 0x8000u) == 0 )
                {
                  if ( (v22 >> 13) & 1 )
                    v23 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v21,
                                                             UFG::PowerManagementComponent::_TypeUID);
                  else
                    v23 = (UFG::PowerManagementComponent *)((v22 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                v21,
                                                                                UFG::PowerManagementComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v21->vfptr, UFG::PowerManagementComponent::_TypeUID));
                }
                else
                {
                  v23 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v21,
                                                           UFG::PowerManagementComponent::_TypeUID);
                }
                if ( v23 )
                  UFG::PowerManagementComponent::PreventSuspendTemporarily(v23, 10.0);
              }
              v24 = v3->mTarget.m_pPointer;
              v25 = UEL::gCurrentParameters;
              if ( v24 )
              {
                v26 = v24->m_Flags;
                if ( (v26 >> 14) & 1 )
                {
                  v27 = (UEL::ParametersBase *)v24->m_Components.p->m_pComponent;
                }
                else if ( (v26 & 0x8000u) == 0 )
                {
                  if ( (v26 >> 13) & 1 )
                    v27 = (UEL::ParametersBase *)v24->m_Components.p->m_pComponent;
                  else
                    v27 = (UEL::ParametersBase *)((v26 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      (UFG::SimObjectGame *)v24,
                                                                      UFG::UELComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(v24, UFG::UELComponent::_TypeUID));
                }
                else
                {
                  v27 = (UEL::ParametersBase *)v24->m_Components.p->m_pComponent;
                }
                if ( v27 )
                  UEL::gCurrentParameters = v27 + 88;
              }
              v28 = v3->m_Track;
              v29 = (ActionController *)&v19[3];
              v30 = v28[1].vfptr;
              if ( BYTE4(v28[2].mResourceOwner) )
              {
                if ( v30 )
                  v31 = (signed __int64)&v30->ResolveReferences + (_QWORD)v28;
                else
                  v31 = 0i64;
                v32 = *(_QWORD *)(v31 + 72);
                if ( v32 )
                  v5 = (ActionNode *)(v32 + v31 + 72);
                ActionController::PlayTracks(
                  v29,
                  v5,
                  LOBYTE(v28[2].m_TrackClassNameUID) != 0,
                  v29->m_ActionNodePlayTime);
              }
              else
              {
                if ( v30 )
                  v33 = (signed __int64)&v30->ResolveReferences + (_QWORD)v28;
                else
                  v33 = 0i64;
                v34 = *(_QWORD *)(v33 + 72);
                if ( v34 )
                  v5 = (ActionNode *)(v34 + v33 + 72);
                ActionController::Play(v29, v5, 0);
                v35 = v3->m_Track;
                if ( BYTE5(v35[2].mResourceOwner) )
                  ActionController::PlayTracks(v29, (ITrack *)((char *)v35 + 64), 0, 0.0);
              }
              ActionController::updateTasksTimeBegin(v29, 0.0, 0);
              UEL::gCurrentParameters = v25;
            }
            if ( BYTE6(v3->m_Track[2].mResourceOwner) )
            {
              v36 = (UFG::SimObjectGame *)v3->mContext->mSimObject.m_pPointer;
              if ( v36 )
              {
                v37 = v36->m_Flags;
                if ( (v37 >> 14) & 1 )
                {
                  v38 = v36->m_Components.p[20].m_pComponent;
                }
                else if ( (v37 & 0x8000u) == 0 )
                {
                  if ( (v37 >> 13) & 1 )
                  {
                    v39 = UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::TargetingSystemBaseComponent::_TypeUID);
                  }
                  else if ( (v37 >> 12) & 1 )
                  {
                    v39 = UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::TargetingSystemBaseComponent::_TypeUID);
                  }
                  else
                  {
                    v39 = UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)&v36->vfptr,
                            UFG::TargetingSystemBaseComponent::_TypeUID);
                  }
                  v38 = v39;
                }
                else
                {
                  v38 = v36->m_Components.p[20].m_pComponent;
                }
                if ( v38 )
                {
                  LOBYTE(v12) = 1;
                  LOBYTE(v11) = HIBYTE(v3->m_Track[2].mResourceOwner) != 0;
                  v40 = 0;
                  ((void (__fastcall *)(UFG::SimComponent *, _QWORD, UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *, __int64, int, char *, ActionContext *, ITrack *))v38->vfptr[14].__vecDelDtor)(
                    v38,
                    (unsigned int)v9,
                    v12,
                    v11,
                    v40,
                    &customWorldMapCaption,
                    v3->mContext,
                    v3->m_Track);
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 569
// RVA: 0x301060
void __fastcall TargetPlayTask::End(TargetPlayTask *this)
{
  TargetPlayTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  UFG::qNode<ITask,ITask> **v5; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mTarget.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[7].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = v2->m_Components.p[6].m_pComponent;
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      v4 = v2->m_Components.p[7].m_pComponent;
    }
    if ( v4 )
    {
      v5 = ActionController::IsPlaying((ActionController *)&v4[3], (ITrack *)((char *)v1->m_Track + 64));
      if ( v5 )
        *((_BYTE *)v5 + 40) = 0;
    }
  }
}

// File Line: 612
// RVA: 0x2F8050
void __fastcall TargetPlayAITask::Begin(TargetPlayAITask *this, ActionContext *context)
{
  ActionContext *v2; // rdi
  ITrack *v3; // rdx
  ActionNode *v4; // rbx
  Expression::IMemberMapVtbl *v5; // rax
  TargetPlayAITask *v6; // rsi
  signed __int64 v7; // rax
  __int64 v8; // rcx
  UFG::SimObjectGame *v9; // rax
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  ITrack *v12; // rcx
  Expression::IMemberMapVtbl *v13; // rdx
  signed __int64 v14; // rcx
  signed __int64 v15; // rdx
  __int64 v16; // rcx

  v2 = context;
  v3 = this->m_Track;
  v4 = 0i64;
  v5 = v3[1].vfptr;
  v6 = this;
  if ( v5 )
    v7 = (signed __int64)&v5->ResolveReferences + (_QWORD)v3;
  else
    v7 = 0i64;
  v8 = *(_QWORD *)(v7 + 72);
  if ( v8 )
  {
    if ( v8 + v7 + 72 )
    {
      v9 = (UFG::SimObjectGame *)UFG::getTarget(v2, (UFG::eTargetTypeEnum)LODWORD(v3[1].mResourceOwner));
      if ( v9 )
      {
        if ( v9 != (UFG::SimObjectGame *)v2->mSimObject.m_pPointer )
        {
          v10 = v9->m_Flags;
          if ( (v10 >> 14) & 1 )
          {
            v11 = v9->m_Components.p[19].m_pComponent;
          }
          else if ( (v10 & 0x8000u) == 0 )
          {
            if ( (v10 >> 13) & 1 )
            {
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::AIActionTreeComponent::_TypeUID);
            }
            else if ( (v10 >> 12) & 1 )
            {
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::AIActionTreeComponent::_TypeUID);
            }
            else
            {
              v11 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v9->vfptr,
                      UFG::AIActionTreeComponent::_TypeUID);
            }
          }
          else
          {
            v11 = v9->m_Components.p[19].m_pComponent;
          }
          v12 = v6->m_Track;
          v13 = v12[1].vfptr;
          v14 = (signed __int64)&v12[1];
          if ( v13 )
            v15 = (signed __int64)v13 + v14;
          else
            v15 = 0i64;
          v16 = *(_QWORD *)(v15 + 72);
          if ( v16 )
            v4 = (ActionNode *)(v16 + v15 + 72);
          ActionController::Play((ActionController *)&v11[3].m_TypeUID, v4, 0);
        }
      }
    }
  }
}

// File Line: 635
// RVA: 0x2F8B70
void __fastcall TargetSpawnTask::Begin(TargetSpawnTask *this, ActionContext *context)
{
  ITrack *v2; // rsi
  ActionContext *v3; // rdi
  TargetSpawnTask *v4; // rbx
  Expression::IMemberMap *v5; // rax
  ITrack *v6; // rsi
  Expression::IMemberMap *v7; // rcx
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObjectGame *v12; // rbx
  unsigned __int16 v13; // cx
  UFG::SimComponent *v14; // rdi
  UFG::SimComponent *v15; // rax
  unsigned __int16 v16; // cx
  UFG::PowerManagementComponent *v17; // rax

  v2 = this->m_Track;
  v3 = context;
  v4 = this;
  v5 = v2[2].mResourceOwner;
  v6 = (ITrack *)((char *)v2 + 64);
  if ( v5 )
    v5 = (Expression::IMemberMap *)((char *)v5 + (_QWORD)v6 + 56);
  v7 = v5[4].mResourceOwner;
  if ( v7 )
  {
    if ( (Expression::IMemberMap **)((char *)&v5[4].mResourceOwner + (_QWORD)v7) )
    {
      v8 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = v8->m_Components.p[20].m_pComponent;
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                     v8,
                                     UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                      (UFG::SimObject *)&v8->vfptr,
                                                                                      UFG::TargetingSystemBaseComponent::_TypeUID);
          v10 = v11;
        }
        else
        {
          v10 = v8->m_Components.p[20].m_pComponent;
        }
        if ( v10 )
        {
          v12 = *(UFG::SimObjectGame **)(56i64
                                       * *(unsigned __int8 *)(LODWORD(v4->m_Track[1].vfptr)
                                                            + *(_QWORD *)&v10[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&v10[1].m_TypeUID
                                       + 40);
          if ( v12 )
          {
            if ( v12 != (UFG::SimObjectGame *)v3->mSimObject.m_pPointer )
            {
              v13 = v12->m_Flags;
              if ( (v13 >> 14) & 1 )
              {
                v14 = v12->m_Components.p[7].m_pComponent;
              }
              else if ( (v13 & 0x8000u) == 0 )
              {
                if ( (v13 >> 13) & 1 )
                {
                  v14 = v12->m_Components.p[6].m_pComponent;
                }
                else
                {
                  if ( (v13 >> 12) & 1 )
                    v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID);
                  else
                    v15 = UFG::SimObject::GetComponentOfType(
                            (UFG::SimObject *)&v12->vfptr,
                            UFG::ActionTreeComponent::_TypeUID);
                  v14 = v15;
                }
              }
              else
              {
                v14 = v12->m_Components.p[7].m_pComponent;
              }
              if ( v14 )
              {
                v16 = v12->m_Flags;
                if ( (v16 >> 14) & 1 )
                {
                  v17 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v12,
                                                           UFG::PowerManagementComponent::_TypeUID);
                }
                else if ( (v16 & 0x8000u) == 0 )
                {
                  if ( (v16 >> 13) & 1 )
                  {
                    v17 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v12,
                                                             UFG::PowerManagementComponent::_TypeUID);
                  }
                  else if ( (v16 >> 12) & 1 )
                  {
                    v17 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v12,
                                                             UFG::PowerManagementComponent::_TypeUID);
                  }
                  else
                  {
                    v17 = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                             (UFG::SimObject *)&v12->vfptr,
                                                             UFG::PowerManagementComponent::_TypeUID);
                  }
                }
                else
                {
                  v17 = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           v12,
                                                           UFG::PowerManagementComponent::_TypeUID);
                }
                if ( v17 )
                  UFG::PowerManagementComponent::PreventSuspendTemporarily(v17, 10.0);
                ActionController::PlayTracks((ActionController *)&v14[3], v6, 0, 0.0);
                ActionController::updateTasksTimeBegin((ActionController *)&v14[3], 0.0, 0);
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 694
// RVA: 0x300D00
void __fastcall TargetGrappleReleaseTask::End(TargetGrappleReleaseTask *this, __int64 a2, __int64 a3, __int64 a4)
{
  TargetGrappleReleaseTask *v4; // rbp
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // rdi
  UFG::SimComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rsi
  UFG::SimComponent *v12; // rax
  int v13; // ST20_4
  unsigned __int8 v14; // cl
  signed __int64 v15; // rbx
  __int64 v16; // r9
  unsigned __int8 v17; // cl
  signed __int64 v18; // rbx
  UFG::SimObjectGame *v19; // rcx
  unsigned __int16 v20; // dx
  UFG::SimComponent *v21; // rax
  UFG::SimComponent *v22; // rdx
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v23; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v24; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v25; // rax
  __int64 v26; // [rsp+20h] [rbp-38h]
  __int64 v27; // [rsp+20h] [rbp-38h]

  v4 = this;
  v5 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v5 )
  {
    v6 = v5->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = v5->m_Components.p[20].m_pComponent;
    }
    else if ( (v6 & 0x8000u) == 0 )
    {
      if ( (v6 >> 13) & 1 )
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v7 = v8;
    }
    else
    {
      v7 = v5->m_Components.p[20].m_pComponent;
    }
    if ( v7 )
    {
      v9 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v7[1].m_Flags + 31i64)
                                  + *(_QWORD *)&v7[1].m_TypeUID
                                  + 40);
      if ( v9 )
      {
        v10 = v9->m_Flags;
        if ( (v10 >> 14) & 1 )
        {
          v11 = v9->m_Components.p[20].m_pComponent;
        }
        else if ( (v10 & 0x8000u) == 0 )
        {
          if ( (v10 >> 13) & 1 )
            v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            v12 = (v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v9,
                                      UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v9->vfptr,
                                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
          v11 = v12;
        }
        else
        {
          v11 = v9->m_Components.p[20].m_pComponent;
        }
        if ( v11 )
        {
          LOBYTE(a4) = 1;
          v13 = 0;
          ((void (__fastcall *)(UFG::SimComponent *, signed __int64, _QWORD, __int64, int, char *, ActionContext *, ITrack *))v11->vfptr[14].__vecDelDtor)(
            v11,
            23i64,
            0i64,
            a4,
            v13,
            &customWorldMapCaption,
            v4->mContext,
            v4->m_Track);
          v14 = *(_BYTE *)(*(_QWORD *)&v11[1].m_Flags + 31i64);
          if ( v14 )
          {
            v15 = 56i64 * v14;
            UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v15 + *(_QWORD *)&v11[1].m_TypeUID), 0i64);
            UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v15 + *(_QWORD *)&v11[1].m_TypeUID), 0);
          }
        }
      }
      LOBYTE(a4) = 1;
      LODWORD(v26) = 0;
      ((void (__fastcall *)(UFG::SimComponent *, signed __int64, _QWORD, __int64, __int64, char *, ActionContext *, ITrack *))v7->vfptr[14].__vecDelDtor)(
        v7,
        23i64,
        0i64,
        a4,
        v26,
        &customWorldMapCaption,
        v4->mContext,
        v4->m_Track);
      v17 = *(_BYTE *)(*(_QWORD *)&v7[1].m_Flags + 31i64);
      if ( v17 )
      {
        v18 = 56i64 * v17;
        UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v18 + *(_QWORD *)&v7[1].m_TypeUID), 0i64);
        UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v18 + *(_QWORD *)&v7[1].m_TypeUID), 0);
      }
      v19 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v7[1].m_Flags + 48i64)
                                   + *(_QWORD *)&v7[1].m_TypeUID
                                   + 40);
      if ( !v19 )
        goto LABEL_45;
      v20 = v19->m_Flags;
      if ( (v20 >> 14) & 1 )
      {
        v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::PropInteractComponent::_TypeUID);
LABEL_39:
        v22 = v21;
        goto LABEL_40;
      }
      if ( (v20 & 0x8000u) == 0 )
      {
        if ( !((v20 >> 13) & 1) )
        {
          if ( (v20 >> 12) & 1 )
            v21 = UFG::SimObjectGame::GetComponentOfTypeHK(v19, UFG::PropInteractComponent::_TypeUID);
          else
            v21 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v19->vfptr,
                    UFG::PropInteractComponent::_TypeUID);
          goto LABEL_39;
        }
        v22 = v19->m_Components.p[13].m_pComponent;
      }
      else
      {
        v22 = v19->m_Components.p[33].m_pComponent;
      }
LABEL_40:
      if ( v22 && v4->mContext->mSimObject.m_pPointer == *(UFG::SimObject **)&v22[2].m_TypeUID )
      {
        v23 = &v22[2].m_SafePointerList;
        if ( v23[1].mNode.mPrev )
        {
          v24 = v23->mNode.mPrev;
          v25 = v23->mNode.mNext;
          v24->mNext = v25;
          v25->mPrev = v24;
          v23->mNode.mPrev = &v23->mNode;
          v23->mNode.mNext = &v23->mNode;
        }
        v23[1].mNode.mPrev = 0i64;
      }
LABEL_45:
      LOBYTE(v16) = 1;
      LODWORD(v27) = 0;
      ((void (__fastcall *)(UFG::SimComponent *, signed __int64, _QWORD, __int64, __int64, _QWORD, _QWORD, _QWORD))v7->vfptr[14].__vecDelDtor)(
        v7,
        40i64,
        0i64,
        v16,
        v27,
        0i64,
        0i64,
        0i64);
      return;
    }
  }
}

// File Line: 762
// RVA: 0x2F6F30
void __fastcall TargetLockTask::Begin(TargetLockTask *this, ActionContext *pContext, __int64 a3, __int64 a4)
{
  TargetLockTask *v4; // rdi
  UFG::SimObjectGame *v5; // rcx
  ActionContext *v6; // rbx
  UFG::TargetingSystemBaseComponent *v7; // r10
  unsigned __int16 v8; // dx
  UFG::TargetingSystemBaseComponent *v9; // rax
  TargetLockTrack *v10; // r11
  __int64 v11; // rdx
  UFG::TargetingSimObject *v12; // rax
  signed __int64 v13; // r8

  v4 = this;
  v5 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v6 = pContext;
  if ( v5 )
  {
    v8 = v5->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v7 = (UFG::TargetingSystemBaseComponent *)v5->m_Components.p[20].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v5,
                                                    UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v9 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v5,
                                                    UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v9 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v5->vfptr,
                                                    UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v7 = v9;
    }
    else
    {
      v7 = (UFG::TargetingSystemBaseComponent *)v5->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    v7 = 0i64;
  }
  v10 = (TargetLockTrack *)v4->m_Track;
  v11 = (unsigned int)v10->mTargetType;
  if ( v7 )
  {
    v12 = v7->m_pTargets;
    v13 = 56i64 * (unsigned __int8)v7->m_pTargetingMap->m_Map.p[v11];
    if ( *(UFG::SimObject **)((char *)&v12->m_pTarget.m_pPointer + v13) )
    {
      if ( !*(&v12->m_bLock + v13) )
      {
        LOBYTE(a4) = v10->mDisableCollision != 0;
        LOBYTE(v13) = 1;
        ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, __int64, signed __int64, __int64, _DWORD, char *, ActionContext *, ITrack *))v7->vfptr[14].__vecDelDtor)(
          v7,
          v11,
          v13,
          a4,
          0,
          &customWorldMapCaption,
          v6,
          v4->m_Track);
      }
    }
  }
}

// File Line: 786
// RVA: 0x2F8900
void __fastcall TargetReleaseTask::Begin(TargetReleaseTask *this, ActionContext *context, __int64 a3, __int64 a4)
{
  ActionContext *v4; // rsi
  TargetReleaseTask *v5; // rdi
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // r8
  UFG::TargetingSystemBaseComponent *v8; // rbx
  UFG::SimComponent *v9; // rax
  ITrack *v10; // rax
  UFG::eTargetTypeEnum v11; // ebp
  int v12; // ST20_4

  v4 = context;
  v5 = this;
  if ( BYTE5(this->m_Track[1].vfptr) )
  {
    this->mContext = context;
  }
  else
  {
    v6 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( v6 )
    {
      v7 = v6->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = (UFG::TargetingSystemBaseComponent *)v6->m_Components.p[20].m_pComponent;
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v9 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v6->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v8 = (UFG::TargetingSystemBaseComponent *)v9;
      }
      else
      {
        v8 = (UFG::TargetingSystemBaseComponent *)v6->m_Components.p[20].m_pComponent;
      }
      if ( v8 )
      {
        v10 = v5->m_Track;
        LOBYTE(a4) = BYTE6(v10[1].vfptr) != 0;
        v11 = (UFG::eTargetTypeEnum)v10[1].vfptr;
        v12 = 0;
        ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, int, char *, ActionContext *, ITrack *))v8->vfptr[14].__vecDelDtor)(
          v8,
          (unsigned int)v11,
          0i64,
          a4,
          v12,
          &customWorldMapCaption,
          v4,
          v5->m_Track);
        if ( BYTE4(v5->m_Track[1].vfptr) )
          UFG::TargetingSystemBaseComponent::ClearTarget(v8, v11);
      }
    }
  }
}

// File Line: 816
// RVA: 0x301190
void __fastcall TargetReleaseTask::End(TargetReleaseTask *this, __int64 a2, __int64 a3, __int64 a4)
{
  TargetReleaseTask *v4; // rdi
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::TargetingSystemBaseComponent *v7; // rbx
  UFG::SimComponent *v8; // rax
  UFG::eTargetTypeEnum v9; // esi
  int v10; // ST20_4

  v4 = this;
  if ( BYTE5(this->m_Track[1].vfptr) )
  {
    v5 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = (UFG::TargetingSystemBaseComponent *)v5->m_Components.p[20].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v5->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v7 = (UFG::TargetingSystemBaseComponent *)v8;
      }
      else
      {
        v7 = (UFG::TargetingSystemBaseComponent *)v5->m_Components.p[20].m_pComponent;
      }
      if ( v7 )
      {
        v9 = (UFG::eTargetTypeEnum)v4->m_Track[1].vfptr;
        LOBYTE(a4) = 1;
        v10 = 0;
        ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, int, char *, ActionContext *, ITrack *))v7->vfptr[14].__vecDelDtor)(
          v7,
          (unsigned int)v9,
          0i64,
          a4,
          v10,
          &customWorldMapCaption,
          v4->mContext,
          v4->m_Track);
        if ( BYTE4(v4->m_Track[1].vfptr) )
          UFG::TargetingSystemBaseComponent::ClearTarget(v7, v9);
      }
    }
  }
}

// File Line: 848
// RVA: 0x2E1F60
void __fastcall TargetSteerToTask::TargetSteerToTask(TargetSteerToTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *v2; // rax

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<TargetSteerToTrack>::`vftable';
  v2 = (UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&TargetSteerToTask::`vftable';
  this->mContext = 0i64;
}

// File Line: 852
// RVA: 0x2F9340
void __fastcall TargetSteerToTask::Begin(TargetSteerToTask *this, ActionContext *context)
{
  ITrack *v2; // rax
  TargetSteerToTask *v3; // rbx
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rax
  UFG::TargetingSystemPedBaseComponent *v7; // rax

  v2 = this->m_Track;
  this->mContext = context;
  v3 = this;
  if ( HIBYTE(v2[1].m_TrackClassNameUID) )
  {
    v4 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( v4 )
    {
      v5 = v4->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v4 = (UFG::SimObjectGame *)v4->m_Components.p[20].m_pComponent;
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v5 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v4->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v4 = (UFG::SimObjectGame *)v6;
      }
      else
      {
        v4 = (UFG::SimObjectGame *)v4->m_Components.p[20].m_pComponent;
      }
    }
    v7 = (UFG::TargetingSystemPedBaseComponent *)((__int64 (*)(void))v4->vfptr[15].__vecDelDtor)();
    if ( v7 )
      UFG::TargetingSystemPedBaseComponent::AddTargetSteerToTask(v7, v3);
  }
}

// File Line: 866
// RVA: 0x30B460
char __fastcall TargetSteerToTask::Update(TargetSteerToTask *this, float timeDelta)
{
  TargetSteerToTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  ITrack *v7; // r10
  int v8; // xmm0_4
  __int64 v9; // rax
  signed __int64 v10; // rdx
  UFG::SimObject *v11; // rcx
  UFG::SimObject *v12; // rdx
  bool bSteerUsingAimPosition; // ST38_1
  bool v14; // ST38_1
  bool bSteerWithNoTarget; // ST30_1
  int fMaxDistanceToTarget; // ST20_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = v2->m_Track;
      v8 = (int)v7[1].mResourceOwner;
      v9 = *(_QWORD *)&v5[1].m_TypeUID;
      v10 = 56i64 * *(unsigned __int8 *)((unsigned int)v7[1].mBreakPoint + *(_QWORD *)&v5[1].m_Flags + 8i64);
      if ( BYTE2(v7[1].m_TrackClassNameUID) )
      {
        v11 = *(UFG::SimObject **)(v10 + v9 + 40);
        v12 = v2->mContext->mSimObject.m_pPointer;
        bSteerUsingAimPosition = BYTE1(v7[1].m_TrackClassNameUID) != 0;
      }
      else
      {
        v11 = v2->mContext->mSimObject.m_pPointer;
        v14 = BYTE1(v7[1].m_TrackClassNameUID) != 0;
        v12 = *(UFG::SimObject **)(v10 + v9 + 40);
      }
      bSteerWithNoTarget = LOBYTE(v7[1].m_TrackClassNameUID) != 0;
      fMaxDistanceToTarget = HIDWORD(v7[1].vfptr);
      UFG::SteerToTarget(v11, v12, (UFG::qSymbolUC *)&v7[1].mResourceOwner + 1, timeDelta * *(float *)&v7[1].vfptr);
    }
  }
  return 1;
}

// File Line: 909
// RVA: 0x2F93F0
void __fastcall TargetSyncPositionTask::Begin(TargetSyncPositionTask *this, ActionContext *context)
{
  ITrack *v2; // r9
  bool *v3; // rdi
  TargetSyncPositionTask *v4; // rbx
  UFG::SimObject *v5; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v6; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v7; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::SimObject *ppOutSimObjectTarget; // [rsp+A0h] [rbp+8h]

  v2 = this->m_Track;
  this->mContext = context;
  this->mManagePowerLevel = 1;
  ppOutSimObjectTarget = 0i64;
  v3 = &this->mManagePowerLevel;
  v4 = this;
  if ( !UFG::TargetAttach(
          context,
          SHIDWORD(v2[1].vfptr),
          0i64,
          &ppOutSimObjectTarget,
          (UFG::qSymbolUC *)&v2[1].mResourceOwner,
          (UFG::qSymbolUC *)&v2[1].mResourceOwner + 1,
          *(float *)&v2[1].vfptr,
          0,
          -1.0,
          LOBYTE(v2[1].m_TrackClassNameUID) != 0,
          0,
          0,
          0,
          0,
          BYTE1(v2[1].m_TrackClassNameUID) != 0,
          BYTE2(v2[1].m_TrackClassNameUID) != 0,
          &this->mManagePowerLevel) )
    *v3 = 0;
  v5 = ppOutSimObjectTarget;
  v6 = &v4->mSimObjectTarget;
  if ( v4->mSimObjectTarget.m_pPointer )
  {
    v7 = v6->mPrev;
    v8 = v4->mSimObjectTarget.mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v4->mSimObjectTarget.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mSimObjectTarget.mPrev;
  }
  v4->mSimObjectTarget.m_pPointer = v5;
  if ( v5 )
  {
    v9 = v5->m_SafePointerList.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
    v6->mPrev = v9;
    v4->mSimObjectTarget.mNext = &v5->m_SafePointerList.mNode;
    v5->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  }
}

// File Line: 965
// RVA: 0x3012A0
void __fastcall TargetSyncPositionTask::End(TargetSyncPositionTask *this)
{
  TargetSyncPositionTask *v1; // rbx

  v1 = this;
  if ( !(unsigned __int8)UFG::TargetDetach(
                           this->mContext,
                           (UFG::eTargetTypeEnum)HIDWORD(this->m_Track[1].vfptr),
                           this->mSimObjectTarget.m_pPointer,
                           (UFG::qSymbolUC *)&this->m_Track[1].mResourceOwner,
                           (UFG::qSymbolUC *)&this->m_Track[1].mResourceOwner + 1,
                           0.0,
                           LOBYTE(this->m_Track[1].m_TrackClassNameUID) != 0,
                           0,
                           0,
                           0,
                           1,
                           0,
                           0.0,
                           -1.0,
                           this->mManagePowerLevel) )
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1->m_Track[1].mResourceOwner + 1);
}

// File Line: 1008
// RVA: 0x2F5C20
void __fastcall TargetAttachTask::Begin(TargetAttachTask *this, ActionContext *context)
{
  ActionContext *v2; // rsi
  TargetAttachTrack *v3; // rdx

  v2 = context;
  v3 = (TargetAttachTrack *)this->m_Track;
  UFG::TargetAttach(
    v2,
    (UFG::eTargetTypeEnum)v3->mTargetType,
    0i64,
    0i64,
    &v3->mAttachJointName,
    &v3->mTargetAttachJointName,
    v3->mBlendInTime,
    v3->mAttachRelative != 0,
    v3->mAttachRelativeMaxDistance,
    v3->mAttachToTarget != 0,
    v3->mAddToInventory != 0,
    v3->mAssignTargetType != 0,
    (UFG::eTargetTypeEnum)v3->mAssignmentTargetType,
    v3->mLockTarget != 0,
    0,
    v3->mPositionXYOnly != 0,
    0i64);
}

// File Line: 1050
// RVA: 0x2F6460
void __fastcall TargetDetachTask::Begin(TargetDetachTask *this, ActionContext *context)
{
  ActionContext *v2; // rsi
  ITrack *v3; // rdx

  v2 = context;
  v3 = this->m_Track;
  UFG::TargetDetach(
    v2,
    (UFG::eTargetTypeEnum)v3[1].vfptr,
    0i64,
    (UFG::qSymbolUC *)&v3[1].m_TrackClassNameUID,
    (UFG::qSymbolUC *)&v3[1].mBreakPoint,
    *((float *)&v3[1].vfptr + 1),
    LOBYTE(v3[1].mMasterRate.text.mOffset) != 0,
    BYTE3(v3[1].mMasterRate.text.mOffset) != 0,
    BYTE1(v3[1].mMasterRate.text.mOffset) != 0,
    BYTE2(v3[1].mMasterRate.text.mOffset) != 0,
    BYTE4(v3[1].mMasterRate.text.mOffset) != 0,
    BYTE5(v3[1].mMasterRate.text.mOffset) != 0,
    *((float *)&v3[1].mResourceOwner + 1),
    *(float *)&v3[1].mResourceOwner,
    0);
}

// File Line: 1104
// RVA: 0x300A40
void __fastcall TargetAttachEXTask::End(TargetAttachEXTask *this)
{
  TargetAttachEXTask::doAttach(this);
}

// File Line: 1109
// RVA: 0x30CD40
void __fastcall TargetAttachEXTask::doAttach(TargetAttachEXTask *this)
{
  ITrack *v1; // rax
  TargetAttachEXTask *v2; // rbx
  bool positionOnly; // r15
  UFG::SimObject *v4; // rbp
  bool positionXYOnly; // r12
  UFG::SimObject *v6; // r14
  UFG::SimComponent *v7; // rax
  __int64 v8; // r8
  __int64 v9; // r9
  ITrack *v10; // rdx
  ITrack *v11; // rdx

  v1 = this->m_Track;
  v2 = this;
  positionOnly = BYTE4(v1[1].mMasterRate.expression.mOffset) != 0;
  v4 = this->mContext->mSimObject.m_pPointer;
  positionXYOnly = BYTE3(v1[1].mMasterRate.expression.mOffset) != 0;
  v6 = 0i64;
  v7 = UFG::SimObject::GetComponentOfType(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
  if ( v7 )
  {
    v8 = *(_QWORD *)&v7[1].m_Flags;
    v9 = *(_QWORD *)&v7[1].m_TypeUID;
    v10 = v2->m_Track;
    v4 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(LODWORD(v10[1].vfptr) + v8 + 8) + v9 + 40);
    v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(HIDWORD(v10[1].vfptr) + v8 + 8) + v9 + 40);
  }
  v11 = v2->m_Track;
  UFG::TargetAttach(
    v4,
    SHIDWORD(v11[1].vfptr),
    v6,
    0i64,
    (UFG::qSymbolUC *)&v11[1].m_TrackClassNameUID,
    (UFG::qSymbolUC *)&v11[1].mBreakPoint,
    *((float *)&v11[1].mResourceOwner + 1),
    BYTE1(v11[1].mMasterRate.text.mOffset) != 0,
    *((float *)&v11[1].mMasterRate.text.mOffset + 1),
    LOBYTE(v11[1].mMasterRate.text.mOffset) != 0,
    BYTE2(v11[1].mMasterRate.expression.mOffset) != 0,
    LOBYTE(v11[1].mMasterRate.expression.mOffset) != 0,
    (UFG::eTargetTypeEnum)v11[1].mResourceOwner,
    BYTE1(v11[1].mMasterRate.expression.mOffset) != 0,
    positionOnly,
    positionXYOnly,
    0i64);
}

// File Line: 1164
// RVA: 0x300AF0
void __fastcall TargetDetachEXTask::End(TargetDetachEXTask *this)
{
  TargetDetachEXTask *v1; // rbx
  UFG::SimObject *v2; // r14
  UFG::SimObject *v3; // r15
  UFG::SimComponent *v4; // rax
  __int64 v5; // r8
  __int64 v6; // r9
  ITrack *v7; // rdx
  ITrack *v8; // rdx

  v1 = this;
  v2 = this->mContext->mSimObject.m_pPointer;
  v3 = 0i64;
  v4 = UFG::SimObject::GetComponentOfType(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
  if ( v4 )
  {
    v5 = *(_QWORD *)&v4[1].m_Flags;
    v6 = *(_QWORD *)&v4[1].m_TypeUID;
    v7 = v1->m_Track;
    v2 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(LODWORD(v7[1].vfptr) + v5 + 8) + v6 + 40);
    v3 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(HIDWORD(v7[1].vfptr) + v5 + 8) + v6 + 40);
  }
  v8 = v1->m_Track;
  UFG::TargetDetach(
    v2,
    SHIDWORD(v8[1].vfptr),
    v3,
    (UFG::qSymbolUC *)&v8[1].mBreakPoint,
    (UFG::qSymbolUC *)&v8[1].mMasterRate,
    *(float *)&v8[1].mResourceOwner,
    BYTE4(v8[1].mMasterRate.text.mOffset) != 0,
    HIBYTE(v8[1].mMasterRate.text.mOffset) != 0,
    BYTE5(v8[1].mMasterRate.text.mOffset) != 0,
    BYTE6(v8[1].mMasterRate.text.mOffset) != 0,
    LOBYTE(v8[1].mMasterRate.expression.mOffset) != 0,
    BYTE1(v8[1].mMasterRate.expression.mOffset) != 0,
    *(float *)&v8[1].m_TrackClassNameUID,
    *((float *)&v8[1].mResourceOwner + 1),
    0);
}

// File Line: 1217
// RVA: 0x2F5C00
void __fastcall TargetAttachEffectorTask::Begin(TargetAttachEffectorTask *this, ActionContext *context)
{
  ITaskVtbl *v2; // rax

  v2 = this->vfptr;
  this->mAttached = 0;
  this->mContext = context;
  ((void (*)(void))v2->Update)();
}

// File Line: 1224
// RVA: 0x30A640
bool __fastcall TargetAttachEffectorTask::Update(TargetAttachEffectorTask *this, float timeDelta)
{
  TargetAttachEffectorTask *v2; // rbx
  bool v3; // zf
  ITrack *v4; // rsi
  UFG::SimObjectCVBase *v5; // rcx
  UFG::eTargetTypeEnum v6; // er14
  float blendTime; // xmm6_4
  bool onlyEnablePostPhysics; // bp
  UFG::CharacterAnimationComponent *v9; // rax
  unsigned __int16 v10; // dx

  v2 = this;
  if ( !TargetAttachEffectorTask::TargetValid(this) )
    return v2->mAttached == 0;
  v3 = v2->mAttached == 0;
  if ( !v2->mAttached )
  {
    v4 = v2->m_Track;
    v5 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
    v6 = (UFG::eTargetTypeEnum)v4[1].vfptr;
    blendTime = *(float *)&v4[1].mResourceOwner;
    onlyEnablePostPhysics = BYTE4(v4[1].vfptr) != 0;
    if ( v5 )
    {
      v10 = v5->m_Flags;
      if ( (v10 >> 14) & 1 || (v10 & 0x8000u) != 0 )
      {
        v9 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v5);
      }
      else if ( (v10 >> 13) & 1 )
      {
        v9 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v5);
      }
      else if ( (v10 >> 12) & 1 )
      {
        v9 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v5->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v9 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v5->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v9 = 0i64;
    }
    UFG::TargetAttachEffector(
      v2->mContext->mSimObject.m_pPointer,
      v9,
      v6,
      (UFG::qSymbolUC *)&v4[1].mResourceOwner + 1,
      (UFG::qSymbolUC *)&v4[1].m_TrackClassNameUID,
      (UFG::qSymbolUC *)&v4[1].mBreakPoint,
      blendTime,
      onlyEnablePostPhysics);
    v2->mAttached = 1;
    return v2->mAttached == 0;
  }
  return v3;
}

// File Line: 1243
// RVA: 0x3036E0
char __fastcall TargetAttachEffectorTask::TargetValid(TargetAttachEffectorTask *this)
{
  TargetAttachEffectorTask *v1; // rdi
  char result; // al
  UFG::SimObjectCVBase *v3; // rcx
  UFG::CharacterAnimationComponent *v4; // rbx
  unsigned __int16 v5; // dx
  UFG::CharacterAnimationComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // r8
  UFG::SimComponent *v10; // rax
  UFG::SimObjectProp *v11; // rcx
  unsigned __int16 v12; // dx
  UFG::CharacterAnimationComponent *v13; // rax
  Creature *v14; // rcx
  Creature *v15; // rdx

  v1 = this;
  if ( sTargetAttachEffectorTaskDisable )
    return 0;
  v3 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v3);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v6 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   (UFG::SimObjectGame *)&v3->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        v6 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v3->vfptr,
                                                   UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
    v4 = v6;
  }
  else
  {
    v4 = 0i64;
  }
  v7 = (UFG::SimObjectGame *)v1->mContext->mSimObject.m_pPointer;
  if ( !v7 )
    goto LABEL_51;
  v8 = v7->m_Flags;
  if ( (v8 >> 14) & 1 )
  {
    v9 = v7->m_Components.p[20].m_pComponent;
  }
  else if ( (v8 & 0x8000u) == 0 )
  {
    if ( (v8 >> 13) & 1 )
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    v9 = v10;
  }
  else
  {
    v9 = v7->m_Components.p[20].m_pComponent;
  }
  if ( v9
    && (v11 = *(UFG::SimObjectProp **)(56i64
                                     * *(unsigned __int8 *)(LODWORD(v1->m_Track[1].vfptr)
                                                          + *(_QWORD *)&v9[1].m_Flags
                                                          + 8i64)
                                     + *(_QWORD *)&v9[1].m_TypeUID
                                     + 40)) != 0i64
    && ((v12 = v11->m_Flags, !((v12 >> 14) & 1)) ? ((v12 & 0x8000u) == 0 ? (!((v12 >> 13) & 1) ? (!((v12 >> 12) & 1) ? (v13 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::CharacterAnimationComponent::_TypeUID)) : (v13 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v11->vfptr, UFG::CharacterAnimationComponent::_TypeUID))) : (v13 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v11))) : (v13 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v11))) : (v13 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v11)),
        v13
     && v4
     && (v14 = v4->mCreature, v15 = v13->mCreature, v14)
     && v15
     && v15->mPose.mRigHandle.mData
     && v14->mPose.mRigHandle.mData
     && !v13->mTemporaryRig
     && v13->mRigHandle.mData
     && !v4->mTemporaryRig
     && v4->mRigHandle.mData) )
  {
    result = 1;
  }
  else
  {
LABEL_51:
    result = 0;
  }
  return result;
}le.mData) )
  {
    result = 1;
  

// File Line: 1280
// RVA: 0x2F63B0
void __fastcall TargetDetachEffectorTask::Begin(TargetDetachEffectorTask *this, ActionContext *context)
{
  UFG::qSymbolUC *v2; // rbx
  UFG::SimObjectCVBase *v3; // rcx
  UFG::eTargetTypeEnum v4; // esi
  ActionContext *v5; // rdi
  float blendTime; // xmm6_4
  UFG::CharacterAnimationComponent *v7; // rax
  unsigned __int16 v8; // dx

  v2 = (UFG::qSymbolUC *)this->m_Track;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = v2[14].mUID;
  v5 = context;
  blendTime = *(float *)&v2[15].mUID;
  if ( v3 )
  {
    v8 = v3->m_Flags;
    if ( (v8 >> 14) & 1 || (v8 & 0x8000u) != 0 )
    {
      v7 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
    else if ( (v8 >> 13) & 1 )
    {
      v7 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v3);
    }
    else if ( (v8 >> 12) & 1 )
    {
      v7 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v3->vfptr,
                                                 UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      v7 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v3->vfptr,
                                                 UFG::CharacterAnimationComponent::_TypeUID);
    }
  }
  else
  {
    v7 = 0i64;
  }
  UFG::TargetDetachEffector(v5->mSimObject.m_pPointer, v7, v4, v2 + 16, blendTime);
}

// File Line: 1294
// RVA: 0x2F5BB0
void __fastcall TargetAttachConstraintTask::Begin(TargetAttachConstraintTask *this, ActionContext *context)
{
  ActionContext *v2; // r11
  ITrack *v3; // rdx

  v2 = context;
  v3 = this->m_Track;
  UFG::TargetAttachConstraint(
    v2->mSimObject.m_pPointer,
    (UFG::eTargetTypeEnum)v3[1].vfptr,
    (UFG::qSymbolUC *)&v3[1].mResourceOwner,
    (UFG::qSymbolUC *)&v3[1].mResourceOwner + 1,
    BYTE1(v3[1].m_TrackClassNameUID) != 0,
    LOBYTE(v3[1].mMasterRate.text.mOffset) != 0,
    SHIDWORD(v3[1].vfptr),
    BYTE1(v3[1].mMasterRate.text.mOffset) != 0);
}

// File Line: 1329
// RVA: 0x2F6390
void __fastcall TargetDetachConstraintTask::Begin(TargetDetachConstraintTask *this, ActionContext *context)
{
  UFG::TargetDetachConstraint(
    context->mSimObject.m_pPointer,
    (UFG::eTargetTypeEnum)this->m_Track[1].vfptr,
    (UFG::qSymbolUC *)&this->m_Track[1].vfptr + 1,
    (UFG::qSymbolUC *)&this->m_Track[1].mResourceOwner);
}

// File Line: 1363
// RVA: 0x2F8D90
void __fastcall TargetStealAttachedItemTask::Begin(TargetStealAttachedItemTask *this, ActionContext *context)
{
  TargetStealAttachedItemTask *v2; // r15
  UFG::SimObjectCVBase *v3; // rcx
  ActionContext *v4; // r13
  unsigned __int16 v5; // r8
  UFG::CharacterAnimationComponent *v6; // rax
  UFG::CharacterAnimationComponent *v7; // rbx
  Creature *v8; // rcx
  UFG::SimObjectCVBase *v9; // rax
  UFG::SimObjectCharacter *v10; // rdi
  unsigned __int16 v11; // dx
  UFG::CharacterAnimationComponent *v12; // rax
  Creature *v13; // rbx
  int v14; // ebp
  UFG::eTargetTypeEnum v15; // er14
  UFG::SimObjectCVBase *v16; // rsi
  unsigned __int16 v17; // cx
  UFG::CharacterAnimationComponent *v18; // rax
  Creature *v19; // rcx
  unsigned __int16 v20; // cx
  UFG::InventoryComponent *v21; // rax
  __int64 v22; // r8
  __int64 v23; // r9
  UFG::GameStatTracker *v24; // rax
  UFG::PersistentData::ID *v25; // rax
  UFG::SceneObjectProperties *v26; // rcx
  unsigned int v27; // ebx
  UFG::qResourceData *v28; // rax
  unsigned __int16 v29; // cx
  UFG::PropInteractComponent *v30; // rax
  unsigned __int16 v31; // cx
  UFG::TargetingSystemBaseComponent *v32; // rbx
  UFG::SimComponent *v33; // rax
  UFG::SimObjectGame *v34; // rcx
  UFG::TargetingSystemBaseComponent *v35; // rbx
  unsigned __int16 v36; // dx
  UFG::SimComponent *v37; // rax
  ITrack *v38; // r11

  v2 = this;
  v3 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v3);
      else
        v6 = (UFG::CharacterAnimationComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                     (UFG::SimObjectGame *)&v3->vfptr,
                                                                     UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
    }
    else
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v3);
    }
    v7 = v6;
    if ( v6 )
    {
      if ( !UFG::getTarget(v4, (UFG::eTargetTypeEnum)HIDWORD(v2->m_Track[1].vfptr)) )
      {
        v8 = v7->mCreature;
        if ( v8 )
        {
          if ( v8->mPose.mRigHandle.mData )
            Skeleton::GetBoneID(v8->mPose.mRigHandle.mUFGSkeleton, HIDWORD(v2->m_Track[1].mResourceOwner));
          v9 = (UFG::SimObjectCVBase *)UFG::getTarget(v4, (UFG::eTargetTypeEnum)LODWORD(v2->m_Track[1].vfptr));
          v10 = (UFG::SimObjectCharacter *)v9;
          if ( v9 )
          {
            v11 = v9->m_Flags;
            if ( (v11 >> 14) & 1 )
            {
              v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
            }
            else if ( (v11 & 0x8000u) == 0 )
            {
              if ( (v11 >> 13) & 1 )
                v12 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v9);
              else
                v12 = (UFG::CharacterAnimationComponent *)((v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                               (UFG::SimObjectGame *)&v9->vfptr,
                                                                               UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
            }
            else
            {
              v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
            }
            if ( v12 )
            {
              v13 = v12->mCreature;
              if ( v13 )
              {
                v14 = v13->mPose.mRigHandle.mData ? (unsigned int)Skeleton::GetBoneID(
                                                                    v13->mPose.mRigHandle.mUFGSkeleton,
                                                                    v2->m_Track[1].m_TrackClassNameUID) : -1;
                v15 = 17;
                v16 = (UFG::SimObjectCVBase *)UFG::getTarget((UFG::SimObject *)&v10->vfptr, eTARGET_TYPE_EQUIPPED);
                if ( v16
                  || (v15 = 18,
                      (v16 = (UFG::SimObjectCVBase *)UFG::getTarget(
                                                       (UFG::SimObject *)&v10->vfptr,
                                                       eTARGET_TYPE_EQUIPPED_LEFT_HAND)) != 0i64) )
                {
                  v17 = v16->m_Flags;
                  if ( (v17 >> 14) & 1 )
                  {
                    v18 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v16);
                  }
                  else if ( (v17 & 0x8000u) == 0 )
                  {
                    if ( (v17 >> 13) & 1 )
                      v18 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v16);
                    else
                      v18 = (UFG::CharacterAnimationComponent *)((v17 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                     (UFG::SimObjectGame *)&v16->vfptr,
                                                                                     UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v16->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
                  }
                  else
                  {
                    v18 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v16);
                  }
                  if ( v18 )
                  {
                    v19 = v18->mCreature;
                    if ( v19->mPose.mRigHandle.mData )
                      Skeleton::GetBoneID(v19->mPose.mRigHandle.mUFGSkeleton, *(_DWORD *)&v2->m_Track[1].mBreakPoint);
                    Creature::RemoveAttachment(v13, (UFG::SimObject *)&v10->vfptr, v14, (UFG::SimObject *)&v16->vfptr);
                    v20 = v10->m_Flags;
                    if ( (v20 >> 14) & 1 )
                    {
                      v21 = (UFG::InventoryComponent *)v10->m_Components.p[39].m_pComponent;
                    }
                    else if ( (v20 & 0x8000u) == 0 )
                    {
                      if ( (v20 >> 13) & 1 )
                      {
                        v21 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v10->vfptr,
                                                           UFG::InventoryComponent::_TypeUID);
                      }
                      else if ( (v20 >> 12) & 1 )
                      {
                        v21 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           (UFG::SimObjectGame *)&v10->vfptr,
                                                           UFG::InventoryComponent::_TypeUID);
                      }
                      else
                      {
                        v21 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                           (UFG::SimObject *)&v10->vfptr,
                                                           UFG::InventoryComponent::_TypeUID);
                      }
                    }
                    else
                    {
                      v21 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v10->vfptr,
                                                         UFG::InventoryComponent::_TypeUID);
                    }
                    if ( v21 )
                      UFG::InventoryComponent::RemoveObjectFromInventory(
                        v21,
                        (UFG::SimObject *)&v16->vfptr,
                        (__int64)v2);
                    if ( v10 == UFG::GetLocalPlayer() )
                    {
                      v24 = UFG::GameStatTracker::Instance();
                      v25 = UFG::GameStatTracker::GetStat(v24, Equipped);
                      v26 = v16->m_pSceneObj;
                      v27 = v25->mValue.mUID;
                      if ( v26 )
                      {
                        v28 = UFG::SceneObjectProperties::GetArchetypeProperties(v26);
                        if ( v28 )
                        {
                          if ( v27 == *(_DWORD *)&v28->mDebugName[12] )
                            UFG::GameStatAction::Inventory::UnEquip(0);
                        }
                      }
                    }
                    v29 = v16->m_Flags;
                    if ( (v29 >> 14) & 1 )
                    {
                      v30 = (UFG::PropInteractComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v16->vfptr,
                                                            UFG::PropInteractComponent::_TypeUID);
                    }
                    else if ( (v29 & 0x8000u) == 0 )
                    {
                      if ( (v29 >> 13) & 1 )
                      {
                        v30 = (UFG::PropInteractComponent *)v16->m_Components.p[13].m_pComponent;
                      }
                      else if ( (v29 >> 12) & 1 )
                      {
                        v30 = (UFG::PropInteractComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              (UFG::SimObjectGame *)&v16->vfptr,
                                                              UFG::PropInteractComponent::_TypeUID);
                      }
                      else
                      {
                        v30 = (UFG::PropInteractComponent *)UFG::SimObject::GetComponentOfType(
                                                              (UFG::SimObject *)&v16->vfptr,
                                                              UFG::PropInteractComponent::_TypeUID);
                      }
                    }
                    else
                    {
                      v30 = (UFG::PropInteractComponent *)v16->m_Components.p[33].m_pComponent;
                    }
                    if ( v30 )
                      UFG::PropInteractComponent::DetachFromObject(v30, (UFG::SimObject *)&v10->vfptr, v22, v23);
                    v31 = v10->m_Flags;
                    if ( (v31 >> 14) & 1 )
                    {
                      v32 = (UFG::TargetingSystemBaseComponent *)v10->m_Components.p[20].m_pComponent;
                    }
                    else if ( (v31 & 0x8000u) == 0 )
                    {
                      if ( (v31 >> 13) & 1 )
                      {
                        v33 = UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)&v10->vfptr,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
                      }
                      else if ( (v31 >> 12) & 1 )
                      {
                        v33 = UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)&v10->vfptr,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
                      }
                      else
                      {
                        v33 = UFG::SimObject::GetComponentOfType(
                                (UFG::SimObject *)&v10->vfptr,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
                      }
                      v32 = (UFG::TargetingSystemBaseComponent *)v33;
                    }
                    else
                    {
                      v32 = (UFG::TargetingSystemBaseComponent *)v10->m_Components.p[20].m_pComponent;
                    }
                    if ( v32 )
                    {
                      LOBYTE(v23) = 1;
                      ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, _DWORD, _QWORD, _QWORD, _QWORD))v32->vfptr[14].__vecDelDtor)(
                        v32,
                        (unsigned int)v15,
                        0i64,
                        v23,
                        0,
                        0i64,
                        0i64,
                        0i64);
                      UFG::TargetingSystemBaseComponent::ClearTarget(v32, v15);
                    }
                    v34 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
                    if ( v34 )
                    {
                      v36 = v34->m_Flags;
                      if ( (v36 >> 14) & 1 )
                      {
                        v35 = (UFG::TargetingSystemBaseComponent *)v34->m_Components.p[20].m_pComponent;
                      }
                      else if ( (v36 & 0x8000u) == 0 )
                      {
                        if ( (v36 >> 13) & 1 )
                        {
                          v37 = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v34,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
                        }
                        else if ( (v36 >> 12) & 1 )
                        {
                          v37 = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v34,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
                        }
                        else
                        {
                          v37 = UFG::SimObject::GetComponentOfType(
                                  (UFG::SimObject *)&v34->vfptr,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
                        }
                        v35 = (UFG::TargetingSystemBaseComponent *)v37;
                      }
                      else
                      {
                        v35 = (UFG::TargetingSystemBaseComponent *)v34->m_Components.p[20].m_pComponent;
                      }
                      if ( v35 )
                        UFG::TargetingSystemBaseComponent::AssignTarget(
                          v35,
                          eTARGET_TYPE_PICKUP_ITEM,
                          (UFG::SimObject *)&v16->vfptr);
                    }
                    else
                    {
                      v35 = 0i64;
                    }
                    v38 = v2->m_Track;
                    UFG::TargetAttach(
                      v4,
                      eTARGET_TYPE_PICKUP_ITEM,
                      0i64,
                      0i64,
                      (UFG::qSymbolUC *)&v38[1].mResourceOwner + 1,
                      (UFG::qSymbolUC *)&v38[1].mBreakPoint,
                      *(float *)&v38[1].mResourceOwner,
                      BYTE1(v38[1].mMasterRate.text.mOffset) != 0,
                      -1.0,
                      0,
                      LOBYTE(v38[1].mMasterRate.text.mOffset) != 0,
                      BYTE2(v38[1].mMasterRate.text.mOffset) != 0,
                      SHIDWORD(v38[1].vfptr),
                      BYTE3(v38[1].mMasterRate.text.mOffset) != 0,
                      0,
                      0,
                      0i64);
                    if ( v35 )
                      UFG::TargetingSystemBaseComponent::ClearTarget(v35, eTARGET_TYPE_PICKUP_ITEM);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}               }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 1505
// RVA: 0x2F8720
void __fastcall TargetPropInteractTask::Begin(TargetPropInteractTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActiveAIEntityComponent *v4; // rax

  this->mContext = context;
  v2 = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
      {
        v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v2->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else if ( (v3 >> 12) & 1 )
      {
        v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                               (UFG::SimObjectGame *)&v2->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                               (UFG::SimObject *)&v2->vfptr,
                                               UFG::ActiveAIEntityComponent::_TypeUID);
      }
    }
    else
    {
      v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
    }
    if ( v4 )
      v4->m_InPropInteractBranch = 1;
  }
}

// File Line: 1515
// RVA: 0x30B240
bool __fastcall TargetPropInteractTask::Update(TargetPropInteractTask *this, float timeDelta, __int64 a3)
{
  TargetPropInteractTask *v3; // rsi
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rbx
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::SimComponent *v11; // rdi
  UFG::SimObjectGame *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::SimComponent *v14; // rsi
  UFG::SimComponent *v15; // rax

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( !v4 )
    return 0;
  v5 = v4->m_Flags;
  if ( (v5 >> 14) & 1 )
  {
    v6 = v4->m_Components.p[20].m_pComponent;
  }
  else if ( (v5 & 0x8000u) == 0 )
  {
    if ( (v5 >> 13) & 1 )
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else if ( (v5 >> 12) & 1 )
    {
      v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    v6 = v7;
  }
  else
  {
    v6 = v4->m_Components.p[20].m_pComponent;
  }
  if ( !v6 )
    return 0;
  v8 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + 48i64)
                              + *(_QWORD *)&v6[1].m_TypeUID
                              + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 >> 14) & 1 )
  {
    v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::PropInteractComponent::_TypeUID);
  }
  else
  {
    if ( (v9 & 0x8000u) != 0 )
    {
      v11 = v8->m_Components.p[33].m_pComponent;
      goto LABEL_24;
    }
    if ( (v9 >> 13) & 1 )
    {
      v11 = v8->m_Components.p[13].m_pComponent;
      goto LABEL_24;
    }
    if ( (v9 >> 12) & 1 )
      v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::PropInteractComponent::_TypeUID);
    else
      v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::PropInteractComponent::_TypeUID);
  }
  v11 = v10;
LABEL_24:
  if ( v11 )
  {
    if ( *(_QWORD *)&v11[2].m_Flags )
    {
      v12 = (UFG::SimObjectGame *)v3->mContext->mSimObject.m_pPointer;
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 >> 14) & 1 )
        {
          v14 = v12->m_Components.p[7].m_pComponent;
        }
        else if ( (v13 & 0x8000u) == 0 )
        {
          if ( (v13 >> 13) & 1 )
          {
            v14 = v12->m_Components.p[6].m_pComponent;
          }
          else
          {
            if ( (v13 >> 12) & 1 )
              v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID);
            else
              v15 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v12->vfptr,
                      UFG::ActionTreeComponent::_TypeUID);
            v14 = v15;
          }
        }
        else
        {
          v14 = v12->m_Components.p[7].m_pComponent;
        }
        if ( v14 )
        {
          LOBYTE(a3) = 1;
          ((void (__fastcall *)(UFG::SimComponent *, signed __int64, __int64, _QWORD, _DWORD, _QWORD, _QWORD, _QWORD))v6->vfptr[14].__vecDelDtor)(
            v6,
            40i64,
            a3,
            0i64,
            0,
            0i64,
            0i64,
            0i64);
          ActionController::Play((ActionController *)&v14[3], *(ActionNodePlayable **)&v11[2].m_Flags);
        }
      }
    }
  }
  return 0;
}

// File Line: 1539
// RVA: 0x301100
void __fastcall TargetPropInteractTask::End(TargetPropInteractTask *this)
{
  ActionContext *v1; // rcx
  UFG::SimObjectCVBase *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::ActiveAIEntityComponent *v4; // rax

  v1 = this->mContext;
  if ( v1 )
  {
    v2 = (UFG::SimObjectCVBase *)v1->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v2->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 (UFG::SimObjectGame *)&v2->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
        else
        {
          v4 = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v2->vfptr,
                                                 UFG::ActiveAIEntityComponent::_TypeUID);
        }
      }
      else
      {
        v4 = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(v2);
      }
      if ( v4 )
        v4->m_InPropInteractBranch = 0;
    }
  }
}

// File Line: 1555
// RVA: 0x2F5BA0
void __fastcall TargetAssignTask::Begin(TargetAssignTask *this, ActionContext *pContext)
{
  this->mContext = pContext;
  TargetAssignTask::PerformAssignment(this);
}

// File Line: 1562
// RVA: 0x30A610
bool __fastcall TargetAssignTask::Update(TargetAssignTask *this, float timeDelta)
{
  ITrack *v2; // rax

  v2 = this->m_Track;
  if ( !LOBYTE(v2[1].mResourceOwner) )
    return BYTE1(v2[1].mResourceOwner) != 0;
  TargetAssignTask::PerformAssignment(this);
  return 1;
}

// File Line: 1577
// RVA: 0x302A00
void __fastcall TargetAssignTask::PerformAssignment(TargetAssignTask *this)
{
  TargetAssignTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::TargetingSystemBaseComponent *v4; // rdi
  UFG::SimComponent *v5; // rax
  ITrack *v6; // rax
  int v7; // ebx
  UFG::TargetingSystemPedBaseComponent *v8; // rax
  UFG::SimObjectVehicle *v9; // rcx

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::TargetingSystemBaseComponent *)v2->m_Components.p[20].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v4 = (UFG::TargetingSystemBaseComponent *)v5;
    }
    else
    {
      v4 = (UFG::TargetingSystemBaseComponent *)v2->m_Components.p[20].m_pComponent;
    }
    if ( v4 )
    {
      v6 = v1->m_Track;
      v7 = HIDWORD(v6[1].vfptr);
      UFG::TargetingSystemBaseComponent::AssignTarget(v4, SHIDWORD(v6[1].vfptr), (UFG::eTargetTypeEnum)v6[1].vfptr);
      if ( v7 == 28 )
      {
        v8 = (UFG::TargetingSystemPedBaseComponent *)((__int64 (__fastcall *)(UFG::TargetingSystemBaseComponent *))v4->vfptr[15].__vecDelDtor)(v4);
        if ( v8 )
          UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(v8);
        v9 = (UFG::SimObjectVehicle *)v4->m_pTargets[(unsigned __int8)v4->m_pTargetingMap->m_Map.p[28]].m_pTarget.m_pPointer;
        if ( v9 )
          UFG::VehicleUtility::UpdateTargetsForEachVehicleRole(v9);
      }
    }
  }
}

// File Line: 1623
// RVA: 0x300980
void __fastcall TargetAssignTask::End(TargetAssignTask *this)
{
  TargetAssignTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::TargetingSystemBaseComponent *v4; // rcx
  UFG::SimComponent *v5; // rax

  v1 = this;
  if ( BYTE1(this->m_Track[1].mResourceOwner) )
  {
    v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = (UFG::TargetingSystemBaseComponent *)v2->m_Components.p[20].m_pComponent;
      }
      else if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v2->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v4 = (UFG::TargetingSystemBaseComponent *)v5;
      }
      else
      {
        v4 = (UFG::TargetingSystemBaseComponent *)v2->m_Components.p[20].m_pComponent;
      }
      if ( v4 )
        UFG::TargetingSystemBaseComponent::SetTarget(v4, SHIDWORD(v1->m_Track[1].vfptr), 0i64);
    }
  }
}

// File Line: 1640
// RVA: 0x2F5B90
void __fastcall TargetAssignTargetsTargetToMyTargetTask::Begin(TargetAssignTargetsTargetToMyTargetTask *this, ActionContext *pContext)
{
  this->mContext = pContext;
  TargetAssignTargetsTargetToMyTargetTask::PerformAssignment(this);
}

// File Line: 1647
// RVA: 0x30A5E0
char __fastcall TargetAssignTargetsTargetToMyTargetTask::Update(TargetAssignTargetsTargetToMyTargetTask *this, float timeDelta)
{
  if ( !BYTE4(this->m_Track[1].mResourceOwner) )
    return 0;
  TargetAssignTargetsTargetToMyTargetTask::PerformAssignment(this);
  return 1;
}

// File Line: 1657
// RVA: 0x302840
void __fastcall TargetAssignTargetsTargetToMyTargetTask::PerformAssignment(TargetAssignTargetsTargetToMyTargetTask *this)
{
  TargetAssignTargetsTargetToMyTargetTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::TargetingSystemBaseComponent *v4; // rdi
  UFG::SimComponent *v5; // rax
  unsigned int *v6; // rax
  __int64 v7; // rbx
  __int64 v8; // rbp
  UFG::SimObject *v9; // rsi
  UFG::SimObjectGame *v10; // r8
  unsigned __int16 v11; // cx
  UFG::SimComponent *v12; // r8
  UFG::SimComponent *v13; // rax
  UFG::TargetingSimObject *v14; // rcx
  signed __int64 v15; // rbx

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::TargetingSystemBaseComponent *)v2->m_Components.p[20].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v5 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v4 = (UFG::TargetingSystemBaseComponent *)v5;
    }
    else
    {
      v4 = (UFG::TargetingSystemBaseComponent *)v2->m_Components.p[20].m_pComponent;
    }
    if ( v4 )
    {
      v6 = (unsigned int *)v1->m_Track;
      v7 = v6[15];
      v8 = v6[16];
      v9 = 0i64;
      v10 = (UFG::SimObjectGame *)v4->m_pTargets[(unsigned __int8)v4->m_pTargetingMap->m_Map.p[v6[14]]].m_pTarget.m_pPointer;
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v12 = v10->m_Components.p[20].m_pComponent;
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
            v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            v13 = (v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                      v10,
                                      UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v10->vfptr,
                                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
          v12 = v13;
        }
        else
        {
          v12 = v10->m_Components.p[20].m_pComponent;
        }
        if ( v12 )
          v9 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v12[1].m_Flags + v7 + 8)
                                  + *(_QWORD *)&v12[1].m_TypeUID
                                  + 40);
      }
      v14 = v4->m_pTargets;
      if ( v14[(unsigned __int8)v4->m_pTargetingMap->m_Map.p[v8]].m_pTarget.m_pPointer != v9 )
      {
        if ( v4->m_pTargetingMap->m_Map.p[v8] )
        {
          v15 = (unsigned __int8)v4->m_pTargetingMap->m_Map.p[v8];
          UFG::TargetingSimObject::SetTarget(&v14[v15], 0i64);
          UFG::TargetingSimObject::SetLock(&v4->m_pTargets[v15], 0);
        }
        UFG::TargetingSystemBaseComponent::SetTarget(v4, (UFG::eTargetTypeEnum)v8, v9);
      }
    }
  }
}

// File Line: 1691
// RVA: 0x2F5920
void __fastcall TargetAssignMyTargetToTargetsTargetTask::Begin(TargetAssignMyTargetToTargetsTargetTask *this, ActionContext *pContext)
{
  this->mContext = pContext;
  TargetAssignMyTargetToTargetsTargetTask::PerformAssignment(this);
}

// File Line: 1698
// RVA: 0x30A5B0
char __fastcall TargetAssignMyTargetToTargetsTargetTask::Update(TargetAssignMyTargetToTargetsTargetTask *this, float timeDelta)
{
  if ( !BYTE4(this->m_Track[1].mResourceOwner) )
    return 0;
  TargetAssignMyTargetToTargetsTargetTask::PerformAssignment(this);
  return 1;
}

// File Line: 1708
// RVA: 0x3026F0
void __fastcall TargetAssignMyTargetToTargetsTargetTask::PerformAssignment(TargetAssignMyTargetToTargetsTargetTask *this)
{
  TargetAssignMyTargetToTargetsTargetTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rax
  unsigned int *v5; // r8
  __int64 v6; // rdx
  __int64 v7; // r9
  UFG::eTargetTypeEnum v8; // ebx
  UFG::SimObject *v9; // rdi
  UFG::SimObjectGame *v10; // r8
  unsigned __int16 v11; // cx
  UFG::TargetingSystemBaseComponent *v12; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[20].m_pComponent;
    }
    else if ( (v3 & 0x8000u) == 0 )
    {
      if ( (v3 >> 13) & 1 )
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v4 = (v3 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v4 = v2->m_Components.p[20].m_pComponent;
    }
    if ( v4 )
    {
      v5 = (unsigned int *)v1->m_Track;
      v6 = *(_QWORD *)&v4[1].m_Flags;
      v7 = *(_QWORD *)&v4[1].m_TypeUID;
      v8 = v5[16];
      v9 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(v5[14] + v6 + 8) + v7 + 40);
      v10 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(v5[15] + v6 + 8) + v7 + 40);
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 >> 14) & 1 )
        {
          v12 = (UFG::TargetingSystemBaseComponent *)v10->m_Components.p[20].m_pComponent;
        }
        else if ( (v11 & 0x8000u) == 0 )
        {
          if ( (v11 >> 13) & 1 )
          {
            v12 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v10,
                                                         UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v11 >> 12) & 1 )
          {
            v12 = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v10,
                                                         UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v12 = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v10->vfptr,
                                                         UFG::TargetingSystemBaseComponent::_TypeUID);
          }
        }
        else
        {
          v12 = (UFG::TargetingSystemBaseComponent *)v10->m_Components.p[20].m_pComponent;
        }
        if ( v12 )
          UFG::TargetingSystemBaseComponent::AssignTarget(v12, v8, v9);
      }
    }
  }
}

// File Line: 1739
// RVA: 0x2F62D0
void __fastcall TargetDestroyTask::Begin(TargetDestroyTask *this, ActionContext *pContext)
{
  TargetDestroyTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rcx

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = *(UFG::SimObject **)(56i64
                              * *(unsigned __int8 *)(LODWORD(v2->m_Track[1].vfptr) + *(_QWORD *)&v5[1].m_Flags + 8i64)
                              + *(_QWORD *)&v5[1].m_TypeUID
                              + 40);
      if ( v7 )
        UFG::SimObject::Destroy(v7);
    }
  }
}

// File Line: 1759
// RVA: 0x2F95C0
void __fastcall TargetWeaponAmmoConsumeTask::Begin(TargetWeaponAmmoConsumeTask *this, ActionContext *pContext)
{
  TargetWeaponAmmoConsumeTask *v2; // r15
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdi
  UFG::SimComponent *v6; // rax
  __int64 v7; // r8
  UFG::SimObjectCVBase *v8; // rbx
  unsigned __int16 v9; // cx
  UFG::CharacterAnimationComponent *v10; // rax
  Creature *v11; // rbp
  int v12; // er14
  UFG::SimObject *v13; // rax
  UFG::SimObjectGame *v14; // rsi
  __int64 v15; // r8
  __int64 v16; // r9
  unsigned __int16 v17; // dx
  UFG::InventoryComponent *v18; // rax
  unsigned __int16 v19; // cx
  UFG::PropInteractComponent *v20; // rax
  unsigned __int16 v21; // cx
  UFG::TargetingSystemBaseComponent *v22; // rbx
  UFG::SimComponent *v23; // rax
  unsigned __int16 v24; // cx
  UFG::SimComponent *v25; // rax
  UFG::GunComponent *v26; // rsi
  __int64 v27; // rax
  unsigned __int64 v28; // rcx
  UFG::SimObjectGame *v29; // rcx
  unsigned __int16 v30; // dx
  UFG::GunComponent *v31; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = LODWORD(v2->m_Track[1].vfptr);
      v8 = *(UFG::SimObjectCVBase **)(56i64 * *(unsigned __int8 *)(v7 + *(_QWORD *)&v5[1].m_Flags + 8)
                                    + *(_QWORD *)&v5[1].m_TypeUID
                                    + 40);
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( !((v9 >> 10) & 1) )
        {
          if ( (_DWORD)v7 == 23 )
          {
            if ( (v9 >> 14) & 1 )
            {
              v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
            }
            else if ( (v9 & 0x8000u) == 0 )
            {
              if ( (v9 >> 13) & 1 )
                v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8);
              else
                v10 = (UFG::CharacterAnimationComponent *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                              (UFG::SimObjectGame *)&v8->vfptr,
                                                                              UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
            }
            else
            {
              v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
            }
            if ( v10 )
            {
              v11 = v10->mCreature;
              if ( v11 )
              {
                v12 = v11->mPose.mRigHandle.mData ? (unsigned int)Skeleton::GetBoneID(
                                                                    v11->mPose.mRigHandle.mUFGSkeleton,
                                                                    (const unsigned int)v2->m_Track[1].mResourceOwner) : -1;
                v13 = UFG::getTarget((UFG::SimObject *)&v8->vfptr, eTARGET_TYPE_EQUIPPED);
                v14 = (UFG::SimObjectGame *)v13;
                if ( v13 )
                {
                  Creature::RemoveAttachment(v11, (UFG::SimObject *)&v8->vfptr, v12, v13);
                  v17 = v8->m_Flags;
                  if ( (v17 >> 14) & 1 )
                  {
                    v18 = (UFG::InventoryComponent *)v8->m_Components.p[39].m_pComponent;
                  }
                  else if ( (v17 & 0x8000u) == 0 )
                  {
                    if ( (v17 >> 13) & 1 )
                    {
                      v18 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v8->vfptr,
                                                         UFG::InventoryComponent::_TypeUID);
                    }
                    else if ( (v17 >> 12) & 1 )
                    {
                      v18 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         (UFG::SimObjectGame *)&v8->vfptr,
                                                         UFG::InventoryComponent::_TypeUID);
                    }
                    else
                    {
                      v18 = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                         (UFG::SimObject *)&v8->vfptr,
                                                         UFG::InventoryComponent::_TypeUID);
                    }
                  }
                  else
                  {
                    v18 = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       (UFG::SimObjectGame *)&v8->vfptr,
                                                       UFG::InventoryComponent::_TypeUID);
                  }
                  if ( v18 )
                    UFG::InventoryComponent::RemoveObjectFromInventory(v18, (UFG::SimObject *)&v14->vfptr, (__int64)v2);
                  v19 = v14->m_Flags;
                  if ( (v19 >> 14) & 1 )
                  {
                    v20 = (UFG::PropInteractComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v14,
                                                          UFG::PropInteractComponent::_TypeUID);
                  }
                  else if ( (v19 & 0x8000u) == 0 )
                  {
                    if ( (v19 >> 13) & 1 )
                    {
                      v20 = (UFG::PropInteractComponent *)v14->m_Components.p[13].m_pComponent;
                    }
                    else if ( (v19 >> 12) & 1 )
                    {
                      v20 = (UFG::PropInteractComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v14,
                                                            UFG::PropInteractComponent::_TypeUID);
                    }
                    else
                    {
                      v20 = (UFG::PropInteractComponent *)UFG::SimObject::GetComponentOfType(
                                                            (UFG::SimObject *)&v14->vfptr,
                                                            UFG::PropInteractComponent::_TypeUID);
                    }
                  }
                  else
                  {
                    v20 = (UFG::PropInteractComponent *)v14->m_Components.p[33].m_pComponent;
                  }
                  if ( v20 )
                    UFG::PropInteractComponent::DetachFromObject(v20, (UFG::SimObject *)&v8->vfptr, v15, v16);
                  v21 = v8->m_Flags;
                  if ( (v21 >> 14) & 1 )
                  {
                    v22 = (UFG::TargetingSystemBaseComponent *)v8->m_Components.p[20].m_pComponent;
                  }
                  else if ( (v21 & 0x8000u) == 0 )
                  {
                    if ( (v21 >> 13) & 1 )
                    {
                      v23 = UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)&v8->vfptr,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
                    }
                    else if ( (v21 >> 12) & 1 )
                    {
                      v23 = UFG::SimObjectGame::GetComponentOfTypeHK(
                              (UFG::SimObjectGame *)&v8->vfptr,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
                    }
                    else
                    {
                      v23 = UFG::SimObject::GetComponentOfType(
                              (UFG::SimObject *)&v8->vfptr,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
                    }
                    v22 = (UFG::TargetingSystemBaseComponent *)v23;
                  }
                  else
                  {
                    v22 = (UFG::TargetingSystemBaseComponent *)v8->m_Components.p[20].m_pComponent;
                  }
                  if ( v22 )
                  {
                    LOBYTE(v16) = 1;
                    ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, signed __int64, _QWORD, __int64, _DWORD, _QWORD, _QWORD, _QWORD))v22->vfptr[14].__vecDelDtor)(
                      v22,
                      17i64,
                      0i64,
                      v16,
                      0,
                      0i64,
                      0i64,
                      0i64);
                    UFG::TargetingSystemBaseComponent::ClearTarget(v22, eTARGET_TYPE_EQUIPPED);
                  }
                  v8 = (UFG::SimObjectCVBase *)v14;
                }
              }
            }
          }
          if ( v8 )
          {
            v24 = v8->m_Flags;
            if ( (v24 >> 14) & 1 )
            {
              v25 = UFG::SimObjectGame::GetComponentOfTypeHK(
                      (UFG::SimObjectGame *)&v8->vfptr,
                      UFG::GunComponent::_TypeUID);
            }
            else if ( (v24 & 0x8000u) == 0 )
            {
              if ( (v24 >> 13) & 1 )
                v25 = UFG::SimObjectGame::GetComponentOfTypeHK(
                        (UFG::SimObjectGame *)&v8->vfptr,
                        UFG::GunComponent::_TypeUID);
              else
                v25 = (v24 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          (UFG::SimObjectGame *)&v8->vfptr,
                                          UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                           (UFG::SimObject *)&v8->vfptr,
                                                                           UFG::GunComponent::_TypeUID);
            }
            else
            {
              v25 = UFG::SimObjectGame::GetComponentOfTypeHK(
                      (UFG::SimObjectGame *)&v8->vfptr,
                      UFG::GunComponent::_TypeUID);
            }
            v26 = (UFG::GunComponent *)v25;
            if ( v25 )
            {
              v27 = *(_QWORD *)&v5[1].m_Flags;
              v28 = BYTE5(v2->m_Track[1].vfptr) ? (unsigned __int64)*(unsigned __int8 *)(v27 + 50) : (unsigned __int64)*(unsigned __int8 *)(v27 + 25);
              v29 = *(UFG::SimObjectGame **)(56 * v28 + *(_QWORD *)&v5[1].m_TypeUID + 40);
              if ( v29 )
              {
                v30 = v29->m_Flags;
                if ( (v30 >> 14) & 1 )
                {
                  v31 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v29, UFG::GunComponent::_TypeUID);
                }
                else if ( (v30 & 0x8000u) == 0 )
                {
                  if ( (v30 >> 13) & 1 )
                  {
                    v31 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v29,
                                                 UFG::GunComponent::_TypeUID);
                  }
                  else if ( (v30 >> 12) & 1 )
                  {
                    v31 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 v29,
                                                 UFG::GunComponent::_TypeUID);
                  }
                  else
                  {
                    v31 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                                 (UFG::SimObject *)&v29->vfptr,
                                                 UFG::GunComponent::_TypeUID);
                  }
                }
                else
                {
                  v31 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v29, UFG::GunComponent::_TypeUID);
                }
                if ( v31 )
                  UFG::GunComponent::TransferAmmoFromGun(v31, v26);
              }
            }
          }
          if ( BYTE4(v2->m_Track[1].vfptr) )
            UFG::SimObject::Destroy((UFG::SimObject *)&v8->vfptr);
        }
      }
    }
  }
}

// File Line: 1861
// RVA: 0x2F57D0
void __usercall TargetAddToInventoryTask::Begin(TargetAddToInventoryTask *this@<rcx>, ActionContext *pContext@<rdx>, __int64 a3@<r15>)
{
  TargetAddToInventoryTask *v3; // rsi
  UFG::SimObjectGame *v4; // rcx
  ActionContext *v5; // rdi
  unsigned __int16 v6; // r8
  UFG::InventoryComponent *v7; // rbx
  UFG::SimComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // r8
  UFG::SimComponent *v12; // rax
  UFG::SimObject *v13; // rdx

  v3 = this;
  v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v5 = pContext;
  if ( v4 )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = (UFG::InventoryComponent *)v4->m_Components.p[39].m_pComponent;
    }
    else
    {
      if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::InventoryComponent::_TypeUID);
        else
          v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::InventoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::InventoryComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::InventoryComponent::_TypeUID);
      }
      v7 = (UFG::InventoryComponent *)v8;
    }
    if ( v7 )
    {
      v9 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
      if ( v9 )
      {
        v10 = v9->m_Flags;
        if ( (v10 >> 14) & 1 )
        {
          v11 = v9->m_Components.p[20].m_pComponent;
        }
        else if ( (v10 & 0x8000u) == 0 )
        {
          if ( (v10 >> 13) & 1 )
          {
            v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v10 >> 12) & 1 )
          {
            v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v12 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v9->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          v11 = v12;
        }
        else
        {
          v11 = v9->m_Components.p[20].m_pComponent;
        }
        if ( v11 )
        {
          v13 = *(UFG::SimObject **)(56i64
                                   * *(unsigned __int8 *)(LODWORD(v3->m_Track[1].vfptr)
                                                        + *(_QWORD *)&v11[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&v11[1].m_TypeUID
                                   + 40);
          if ( v13 )
            UFG::InventoryComponent::AddObjectToInventory(v7, v13, 0, a3);
        }
      }
    }
  }
}

// File Line: 1887
// RVA: 0x2F8A20
void __usercall TargetRemoveFromInventoryTask::Begin(TargetRemoveFromInventoryTask *this@<rcx>, ActionContext *pContext@<rdx>, __int64 a3@<r15>)
{
  TargetRemoveFromInventoryTask *v3; // rsi
  UFG::SimObjectGame *v4; // rcx
  ActionContext *v5; // rdi
  unsigned __int16 v6; // r8
  UFG::InventoryComponent *v7; // rbx
  UFG::SimComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // r8
  UFG::SimComponent *v12; // rax
  UFG::SimObject *v13; // rdx

  v3 = this;
  v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v5 = pContext;
  if ( v4 )
  {
    v6 = v4->m_Flags;
    if ( (v6 >> 14) & 1 )
    {
      v7 = (UFG::InventoryComponent *)v4->m_Components.p[39].m_pComponent;
    }
    else
    {
      if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::InventoryComponent::_TypeUID);
        else
          v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::InventoryComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::InventoryComponent::_TypeUID);
      }
      else
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::InventoryComponent::_TypeUID);
      }
      v7 = (UFG::InventoryComponent *)v8;
    }
    if ( v7 )
    {
      v9 = (UFG::SimObjectGame *)v5->mSimObject.m_pPointer;
      if ( v9 )
      {
        v10 = v9->m_Flags;
        if ( (v10 >> 14) & 1 )
        {
          v11 = v9->m_Components.p[20].m_pComponent;
        }
        else if ( (v10 & 0x8000u) == 0 )
        {
          if ( (v10 >> 13) & 1 )
          {
            v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v10 >> 12) & 1 )
          {
            v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v12 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v9->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          v11 = v12;
        }
        else
        {
          v11 = v9->m_Components.p[20].m_pComponent;
        }
        if ( v11 )
        {
          v13 = *(UFG::SimObject **)(56i64
                                   * *(unsigned __int8 *)(LODWORD(v3->m_Track[1].vfptr)
                                                        + *(_QWORD *)&v11[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&v11[1].m_TypeUID
                                   + 40);
          if ( v13 )
            UFG::InventoryComponent::RemoveObjectFromInventory(v7, v13, a3);
        }
      }
    }
  }
}

// File Line: 1907
// RVA: 0x2F87A0
void __fastcall TargetPurchaseItemTask::Begin(TargetPurchaseItemTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *v2; // rax
  UFG::SimObject *v3; // rdi
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rbx
  UFG::SimComponent *v6; // rax
  bool v7; // al
  UFG::eInventoryItemEnum v8; // ecx
  int v9; // eax
  signed int v10; // eax

  v2 = (UFG::SimObjectGame *)UFG::getTarget(pContext, (UFG::eTargetTypeEnum)LODWORD(this->m_Track[1].vfptr));
  v3 = (UFG::SimObject *)&v2->vfptr;
  if ( v2 )
  {
    v4 = v2->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v2->m_Components.p[39].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InventoryComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InventoryComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::InventoryComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::InventoryComponent::_TypeUID);
      }
      v5 = v6;
    }
    if ( v5 )
    {
      v7 = UFG::FaceActionComponent::IsSafehouseItemVendor(*(UFG::eInventoryItemEnum *)&v5[14].m_Flags);
      v8 = *(_DWORD *)&v5[14].m_Flags;
      if ( v7 )
      {
        v9 = UFG::ItemProfiles::GetCost(v8);
      }
      else
      {
        v10 = UFG::ItemProfiles::GetCost(v8);
        v9 = (signed int)UFG::StoreFrontTracker::GetItemPriceBasedOnClothes((float)v10);
      }
      UFG::GameStatAction::Money::PurchaseItem(v3, *(UFG::eInventoryItemEnum *)&v5[14].m_Flags, v9);
      if ( (unsigned __int8)UFG::TiDo::GetIsInstantiated() )
      {
        if ( !(_S7_6 & 1) )
        {
          _S7_6 |= 1u;
          UFG::qWiseSymbol::create_from_string(&Play_ui_cha_ching, "Play_ui_cha_ching");
          atexit(TargetPurchaseItemTask::Begin_::_11_::_dynamic_atexit_destructor_for__Play_ui_cha_ching__);
        }
        UFG::AudioEntity::CreateAndPlayEvent(
          (UFG::AudioEntity *)&UFG::AmbienceAudio::m_instance->vfptr,
          Play_ui_cha_ching.mUID,
          0i64,
          0,
          0i64);
      }
    }
  }
}

// File Line: 1933
// RVA: 0x2F9510
void __fastcall TargetVehicleBreakWindowTask::Begin(TargetVehicleBreakWindowTask *this, ActionContext *pContext)
{
  TargetVehicleBreakWindowTask *v2; // rbx
  UFG::SimObjectGame *v3; // rax
  unsigned __int16 v4; // r8
  UFG::SimComponent *v5; // rax
  UFG::VehicleEffectsComponent *v6; // rcx

  v2 = this;
  v3 = (UFG::SimObjectGame *)UFG::getTarget(pContext, (UFG::eTargetTypeEnum)LODWORD(this->m_Track[1].vfptr));
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID);
    }
    else
    {
      if ( (v4 & 0x8000u) != 0 )
      {
        v6 = (UFG::VehicleEffectsComponent *)v3->m_Components.p[32].m_pComponent;
        goto LABEL_12;
      }
      if ( (v4 >> 13) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::VehicleEffectsComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::VehicleEffectsComponent::_TypeUID);
      }
    }
    v6 = (UFG::VehicleEffectsComponent *)v5;
LABEL_12:
    if ( v6 )
      UFG::VehicleEffectsComponent::BreakGlass(v6, SHIDWORD(v2->m_Track[1].vfptr));
  }
}

// File Line: 1961
// RVA: 0x30A750
char __fastcall TargetFocusOverrideTask::Update(TargetFocusOverrideTask *this, float timeDelta)
{
  TargetFocusOverrideTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rcx
  UFG::SimComponent *v6; // rax
  UFG::TargetingSystemPedPlayerComponent *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // r8

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = (UFG::TargetingSystemPedPlayerComponent *)((__int64 (*)(void))v5->vfptr[19].__vecDelDtor)();
      if ( v7 )
      {
        v8 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(56i64
                                                                                           * (unsigned __int8)v7->m_pTargetingMap->m_Map.p[LODWORD(v2->m_Track[1].vfptr)]);
        UFG::TargetingSystemPedPlayerComponent::SetFocusModeOverrideSimObject(
          v7,
          *(UFG::SimObject **)((char *)&v8[2].mNext + (unsigned __int64)v7->m_pTargets),
          v8);
      }
    }
  }
  return 1;
}

// File Line: 1980
// RVA: 0x300C10
void __fastcall TargetFocusOverrideTask::End(TargetFocusOverrideTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::SimComponent *v3; // rcx
  UFG::SimComponent *v4; // rax
  UFG::TargetingSystemPedPlayerComponent *v5; // rax

  v1 = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = v1->m_Components.p[20].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v4 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v4 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v1->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v3 = v4;
    }
    else
    {
      v3 = v1->m_Components.p[20].m_pComponent;
    }
    if ( v3 )
    {
      v5 = (UFG::TargetingSystemPedPlayerComponent *)((__int64 (*)(void))v3->vfptr[19].__vecDelDtor)();
      if ( v5 )
        UFG::TargetingSystemPedPlayerComponent::ClearFocusModeOverrideSimObject(v5);
    }
  }
}

// File Line: 1999
// RVA: 0x2F6930
void __fastcall TargetHitReactionTask::Begin(TargetHitReactionTask *this, ActionContext *pContext)
{
  ActionContext *v2; // rdi
  UFG::SimObjectGame *v3; // rbx
  UFG::SimObject *v4; // r8
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rdi
  UFG::SimObjectGame *v7; // rcx
  UFG::SimComponent *v8; // rax
  unsigned __int16 v9; // cx
  UFG::HitReactionComponent *v10; // rbx
  UFG::SimComponent *v11; // rax
  UFG::HitRecord hitrecord; // [rsp+30h] [rbp-138h]

  v2 = pContext;
  v3 = (UFG::SimObjectGame *)UFG::getTarget(pContext, (UFG::eTargetTypeEnum)LODWORD(this->m_Track[1].vfptr));
  if ( v3 )
  {
    v4 = v2->mSimObject.m_pPointer;
    if ( v4 )
    {
      v5 = v4->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = v4->m_Components.p[15].m_pComponent;
      }
      else if ( (v5 & 0x8000u) == 0 )
      {
        v7 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
        if ( (v5 >> 13) & 1 )
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::HitReactionComponent::_TypeUID);
        else
          v8 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::HitReactionComponent::_TypeUID);
        v6 = v8;
      }
      else
      {
        v6 = v4->m_Components.p[15].m_pComponent;
      }
      if ( v6 )
      {
        v9 = v3->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = (UFG::HitReactionComponent *)v3->m_Components.p[15].m_pComponent;
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
          }
          else if ( (v9 >> 12) & 1 )
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::HitReactionComponent::_TypeUID);
          }
          else
          {
            v11 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::HitReactionComponent::_TypeUID);
          }
          v10 = (UFG::HitReactionComponent *)v11;
        }
        else
        {
          v10 = (UFG::HitReactionComponent *)v3->m_Components.p[15].m_pComponent;
        }
        if ( v10 )
        {
          UFG::HitRecord::HitRecord(&hitrecord);
          UFG::HitRecord::operator=(&hitrecord, (UFG::HitRecord *)&v6[2].m_BoundComponentHandles.mNode.mNext);
          hitrecord.mNext = 0i64;
          hitrecord.mHitRecordProcessed = 0;
          UFG::HitReactionComponent::HandleHitReaction(v10, &hitrecord);
          UFG::HitRecord::~HitRecord(&hitrecord);
        }
      }
    }
  }
}

// File Line: 2030
// RVA: 0x2F6D60
void __fastcall TargetLatchParkourHandleTask::Begin(TargetLatchParkourHandleTask *this, ActionContext *context)
{
  TargetLatchParkourHandleTask *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::ParkourHandle *v7; // rdi
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *v11; // rax
  UFG::SimObjectGame *v12; // r8
  unsigned __int16 v13; // cx
  UFG::WorldContextComponent *v14; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = context;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[28].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
      else
        v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::WorldContextComponent::_TypeUID);
    }
    else
    {
      v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::WorldContextComponent::_TypeUID);
    }
    if ( v6 )
    {
      v7 = *(UFG::ParkourHandle **)&v6[5].m_TypeUID;
      if ( v7 )
      {
        v8 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
        if ( v8 )
        {
          v9 = v8->m_Flags;
          if ( (v9 >> 14) & 1 )
          {
            v10 = v8->m_Components.p[20].m_pComponent;
          }
          else if ( (v9 & 0x8000u) == 0 )
          {
            if ( (v9 >> 13) & 1 )
            {
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else if ( (v9 >> 12) & 1 )
            {
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            else
            {
              v11 = UFG::SimObject::GetComponentOfType(
                      (UFG::SimObject *)&v8->vfptr,
                      UFG::TargetingSystemBaseComponent::_TypeUID);
            }
            v10 = v11;
          }
          else
          {
            v10 = v8->m_Components.p[20].m_pComponent;
          }
          if ( v10 )
          {
            v12 = *(UFG::SimObjectGame **)(56i64
                                         * *(unsigned __int8 *)(LODWORD(v2->m_Track[1].vfptr)
                                                              + *(_QWORD *)&v10[1].m_Flags
                                                              + 8i64)
                                         + *(_QWORD *)&v10[1].m_TypeUID
                                         + 40);
            if ( v12 )
            {
              v13 = v12->m_Flags;
              if ( (v13 >> 14) & 1 )
              {
                v14 = (UFG::WorldContextComponent *)v12->m_Components.p[28].m_pComponent;
              }
              else if ( (v13 & 0x8000u) == 0 )
              {
                if ( (v13 >> 13) & 1 )
                {
                  v14 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v12,
                                                        UFG::WorldContextComponent::_TypeUID);
                }
                else if ( (v13 >> 12) & 1 )
                {
                  v14 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v12,
                                                        UFG::WorldContextComponent::_TypeUID);
                }
                else
                {
                  v14 = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                                        (UFG::SimObject *)&v12->vfptr,
                                                        UFG::WorldContextComponent::_TypeUID);
                }
              }
              else
              {
                v14 = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v12,
                                                      UFG::WorldContextComponent::_TypeUID);
              }
              if ( v14 )
                UFG::WorldContextComponent::LatchParkourHandle(v14, v7);
            }
          }
        }
      }
    }
  }
}

// File Line: 2062
// RVA: 0x2E1720
void __fastcall TargetAttackRightsTask::TargetAttackRightsTask(TargetAttackRightsTask *this)
{
  UFG::qNode<ITask,ITask> *v1; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v2; // [rsp+28h] [rbp+10h]

  v1 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<TargetAttackRightsTrack>::`vftable';
  this->vfptr = (ITaskVtbl *)&TargetAttackRightsTask::`vftable';
  v2 = &this->mTargetAttackRightsComponent;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  this->mTargetAttackRightsComponent.m_pPointer = 0i64;
  this->mPreviousAttackRights = 0;
  this->mpContext = 0i64;
}

// File Line: 2068
// RVA: 0x301EE0
UFG::qString *__fastcall TargetAttackRightsTask::GetDebugString(TargetAttackRightsTask *this, UFG::qString *result, ActionContext *context)
{
  ActionContext *v3; // rsi
  UFG::qString *v4; // rdi
  hkResourceHandle *v5; // rbx
  UFG::qSymbolUC *v6; // rcx
  char *v7; // rax
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::SimComponent *v12; // rax
  UFG::SimObjectGame *v13; // rcx
  unsigned __int16 v14; // dx
  UFG::SimComponent *v15; // rax
  const char *v16; // rdx
  UFG::qString resulta; // [rsp+30h] [rbp-58h]
  UFG::qString v19; // [rsp+58h] [rbp-30h]

  v3 = context;
  v4 = result;
  v5 = 0i64;
  UFG::qString::qString(result, "TargetAttackRightsTask: ");
  v6 = (UFG::qSymbolUC *)v3->mSimObject.m_pPointer;
  if ( v6 )
  {
    v7 = UFG::qSymbol::as_cstr_dbg(v6 + 18);
    UFG::qString::qString(&v19, v7);
    v9 = UFG::operator+(&resulta, v8, ": ");
    UFG::qString::operator+=(v4, v9);
    UFG::qString::~qString(&resulta);
    UFG::qString::~qString(&v19);
  }
  else
  {
    UFG::qString::operator+=(v4, "unknown SimObject: ");
  }
  v10 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
  if ( v10
    && ((v11 = v10->m_Flags, !((v11 >> 14) & 1)) ? ((v11 & 0x8000u) == 0 ? (!((v11 >> 13) & 1) ? (!((v11 >> 12) & 1) ? (v12 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::ActionTreeComponent::_TypeUID)) : (v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::ActionTreeComponent::_TypeUID))) : (v12 = v10->m_Components.p[6].m_pComponent)) : (v12 = v10->m_Components.p[7].m_pComponent)) : (v12 = v10->m_Components.p[7].m_pComponent),
        v12) )
  {
    v13 = (UFG::SimObjectGame *)v3->mSimObject.m_pPointer;
    if ( v13 )
    {
      v14 = v13->m_Flags;
      if ( (v14 >> 14) & 1 || (v14 & 0x8000u) != 0 )
      {
        v5 = (hkResourceHandle *)v13->m_Components.p[7].m_pComponent;
      }
      else if ( (v14 >> 13) & 1 )
      {
        v5 = (hkResourceHandle *)v13->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (v14 >> 12) & 1 )
          v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::ActionTreeComponent::_TypeUID);
        else
          v15 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v13->vfptr, UFG::ActionTreeComponent::_TypeUID);
        v5 = (hkResourceHandle *)v15;
      }
    }
    v16 = (const char *)TargetVisibleInAIDataCondition::CreateClone(v5 + 12);
  }
  else
  {
    v16 = "no node path found";
  }
  UFG::qString::operator+=(v4, v16);
  return v4;
}

// File Line: 2093
// RVA: 0x2F5CF0
void __fastcall TargetAttackRightsTask::Begin(TargetAttackRightsTask *this, ActionContext *context)
{
  ActionContext *v2; // r14
  TargetAttackRightsTask *v3; // rsi
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *v4; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // r8
  UFG::SimComponent *v10; // rax
  ITrack *v11; // r9
  UFG::SimObjectGame *v12; // r8
  bool v13; // bp
  unsigned __int16 v14; // cx
  UFG::SimComponent *v15; // rdi
  UFG::SimComponent *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  bool v20; // al
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v2 = context;
  v3 = this;
  v4 = &this->mTargetAttackRightsComponent;
  if ( this->mTargetAttackRightsComponent.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = this->mTargetAttackRightsComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    this->mTargetAttackRightsComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->mTargetAttackRightsComponent.mPrev;
  }
  this->mTargetAttackRightsComponent.m_pPointer = 0i64;
  this->mpContext = context;
  v7 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v7 )
  {
    v8 = v7->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = v7->m_Components.p[20].m_pComponent;
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
        v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v10 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v9 = v10;
    }
    else
    {
      v9 = v7->m_Components.p[20].m_pComponent;
    }
    if ( v9 )
    {
      v11 = v3->m_Track;
      v12 = *(UFG::SimObjectGame **)(56i64
                                   * *(unsigned __int8 *)(*(_QWORD *)&v9[1].m_Flags + LODWORD(v11[1].vfptr) + 8i64)
                                   + *(_QWORD *)&v9[1].m_TypeUID
                                   + 40);
      if ( v12 )
      {
        v13 = BYTE4(v11[1].vfptr) != 0;
        v14 = v12->m_Flags;
        if ( (v14 >> 14) & 1 )
        {
          v15 = v12->m_Components.p[46].m_pComponent;
        }
        else
        {
          if ( (v14 & 0x8000u) == 0 )
          {
            if ( (v14 >> 13) & 1 )
              v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AttackRightsComponent::_TypeUID);
            else
              v16 = (v14 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                        v12,
                                        UFG::AttackRightsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                  (UFG::SimObject *)&v12->vfptr,
                                                                                  UFG::AttackRightsComponent::_TypeUID);
          }
          else
          {
            v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AttackRightsComponent::_TypeUID);
          }
          v15 = v16;
        }
        if ( v15 )
        {
          if ( v4->m_pPointer )
          {
            v17 = v4->mPrev;
            v18 = v4->mNext;
            v17->mNext = v18;
            v18->mPrev = v17;
            v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
            v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
          }
          v4->m_pPointer = v15;
          v19 = v15->m_SafePointerList.mNode.mPrev;
          v19->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
          v4->mPrev = v19;
          v4->mNext = &v15->m_SafePointerList.mNode;
          v15->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
          v20 = LOBYTE(v15[149].vfptr) && BYTE1(v15[149].vfptr) && BYTE2(v15[149].vfptr);
          v3->mPreviousAttackRights = v20;
          if ( v20 != v13 )
          {
            TargetAttackRightsTask::GetDebugString(v3, &result, v2);
            LOBYTE(v15[149].vfptr) = v13;
            BYTE1(v15[149].vfptr) = v13;
            BYTE2(v15[149].vfptr) = v13;
            UFG::qString::Set((UFG::qString *)&v15[161].m_TypeUID, result.mData);
            UFG::qString::~qString(&result);
          }
        }
      }
    }
  }
}

// File Line: 2125
// RVA: 0x300A50
void __fastcall TargetAttackRightsTask::End(TargetAttackRightsTask *this)
{
  TargetAttackRightsTask *v1; // rbx
  UFG::SimComponent *v2; // rax
  bool v3; // al
  char *v4; // rdx
  UFG::SimComponent *v5; // rcx
  bool v6; // al
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v1 = this;
  if ( BYTE5(this->m_Track[1].vfptr) )
  {
    v2 = this->mTargetAttackRightsComponent.m_pPointer;
    if ( v2 )
    {
      v3 = LOBYTE(v2[149].vfptr) && BYTE1(v2[149].vfptr) && BYTE2(v2[149].vfptr);
      if ( this->mPreviousAttackRights != v3 )
      {
        TargetAttackRightsTask::GetDebugString(this, &result, this->mpContext);
        v4 = result.mData;
        v5 = v1->mTargetAttackRightsComponent.m_pPointer;
        v6 = v1->mPreviousAttackRights;
        LOBYTE(v5[149].vfptr) = v6;
        BYTE1(v5[149].vfptr) = v6;
        BYTE2(v5[149].vfptr) = v6;
        UFG::qString::Set((UFG::qString *)&v5[161].m_TypeUID, v4);
        UFG::qString::~qString(&result);
      }
    }
  }
}

// File Line: 2144
// RVA: 0x2F6770
void __fastcall TargetGunSetAmmoForAIDeathTask::Begin(TargetGunSetAmmoForAIDeathTask *this, ActionContext *context)
{
  TargetGunSetAmmoForAIDeathTask *v2; // rdi
  UFG::SimObject *v3; // rcx
  ActionContext *v4; // rbx
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // r8
  UFG::SimComponent *v8; // rax
  UFG::SimObjectGame *v9; // rbx
  unsigned __int16 v10; // cx
  UFG::SimComponent *v11; // rax
  unsigned __int16 v12; // cx
  UFG::GunComponent *v13; // rax

  v2 = this;
  v3 = context->mSimObject.m_pPointer;
  v4 = context;
  if ( !((v3->m_Flags >> 10) & 1) && !UFG::IsAnyLocalPlayer(v3) )
  {
    v5 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = v5->m_Components.p[20].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else if ( (v6 >> 12) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v5->vfptr,
                 UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        v7 = v8;
      }
      else
      {
        v7 = v5->m_Components.p[20].m_pComponent;
      }
      if ( v7 )
      {
        v9 = *(UFG::SimObjectGame **)(56i64
                                    * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr)
                                                         + *(_QWORD *)&v7[1].m_Flags
                                                         + 8i64)
                                    + *(_QWORD *)&v7[1].m_TypeUID
                                    + 40);
        if ( v9 )
        {
          v10 = v9->m_Flags;
          if ( (v10 >> 14) & 1 )
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::RigidBodyComponent::_TypeUID);
          }
          else if ( (v10 & 0x8000u) == 0 )
          {
            if ( (v10 >> 13) & 1 )
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::RigidBodyComponent::_TypeUID);
            else
              v11 = (v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v9->vfptr, UFG::RigidBodyComponent::_TypeUID);
          }
          else
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::RigidBodyComponent::_TypeUID);
          }
          if ( v11 )
          {
            v12 = v9->m_Flags;
            if ( (v12 >> 14) & 1 )
            {
              v13 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID);
            }
            else if ( (v12 & 0x8000u) == 0 )
            {
              if ( (v12 >> 13) & 1 )
              {
                v13 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID);
              }
              else if ( (v12 >> 12) & 1 )
              {
                v13 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID);
              }
              else
              {
                v13 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v9->vfptr,
                                             UFG::GunComponent::_TypeUID);
              }
            }
            else
            {
              v13 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID);
            }
            if ( v13 )
              UFG::GunComponent::SetAmmoForAIDeath(v13);
          }
        }
      }
    }
  }
}

// File Line: 2179
// RVA: 0x2F7030
void __fastcall TargetPhysicalAttackTask::Begin(TargetPhysicalAttackTask *this, ActionContext *pContext)
{
  ActionContext *v2; // r14
  TargetPhysicalAttackTask *v3; // r15
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rdi
  UFG::SimComponent *v7; // rax
  UFG::SimObjectProp *v8; // rbx
  unsigned __int16 v9; // cx
  UFG::SimComponent *v10; // rax
  UFG::RigidBody *v11; // rsi
  unsigned __int16 v12; // cx
  UFG::SimObjectWeaponPropertiesComponent *v13; // rax
  UFG::SimObjectWeaponPropertiesComponent *v14; // rbx
  float v15; // xmm11_4
  float v16; // xmm8_4
  bool v17; // cf
  bool v18; // zf
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v19; // rcx
  const char *v20; // rax
  UFG::CollisionMeshData *v21; // rdx
  UFG::SimObjectGame *v22; // rcx
  unsigned __int16 v23; // dx
  UFG::SimComponent *v24; // rdx
  UFG::SimComponent *v25; // rax
  __m128 v26; // xmm6
  __m128 v27; // xmm7
  float v28; // xmm10_4
  UFG::qVector3 *v29; // rdx
  float v30; // xmm12_4
  __m128 v31; // xmm9
  float v32; // xmm13_4
  __m128 v33; // xmm2
  int v34; // xmm15_4
  float v35; // xmm14_4
  __m128 v36; // xmm1
  float v37; // xmm2_4
  __m128 v38; // xmm15
  float v39; // xmm5_4
  float v40; // xmm2_4
  float v41; // xmm4_4
  __m128 v42; // xmm3
  float v43; // xmm3_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm3_4
  float v47; // xmm4_4
  float v48; // xmm5_4
  float v49; // xmm15_4
  unsigned int v50; // ST20_4
  __m128 v51; // xmm0
  float v52; // xmm1_4
  __m128 v53; // xmm2
  float v54; // xmm1_4
  float v55; // xmm10_4
  float v56; // xmm1_4
  float v57; // xmm12_4
  float v58; // xmm9_4
  float v59; // xmm13_4
  float v60; // xmm6_4
  float v61; // xmm0_4
  float v62; // xmm9_4
  float v63; // xmm1_4
  float *v64; // rdx
  float v65; // xmm7_4
  float v66; // xmm6_4
  float v67; // [rsp+20h] [rbp-B8h]
  UFG::qVector3 vel; // [rsp+28h] [rbp-B0h]
  int v69; // [rsp+38h] [rbp-A0h]
  float v70; // [rsp+3Ch] [rbp-9Ch]
  UFG::qReflectHandleBase v71; // [rsp+40h] [rbp-98h]
  __int64 v72; // [rsp+68h] [rbp-70h]
  float v73; // [rsp+70h] [rbp-68h]
  float v74; // [rsp+74h] [rbp-64h]
  float v75; // [rsp+78h] [rbp-60h]
  float v76; // [rsp+150h] [rbp+78h]
  float v77; // [rsp+158h] [rbp+80h]
  float vars0; // [rsp+160h] [rbp+88h]

  v72 = -2i64;
  v2 = pContext;
  v3 = this;
  v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v4->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v6 = v7;
    }
    else
    {
      v6 = v4->m_Components.p[20].m_pComponent;
    }
    if ( v6 )
    {
      v8 = *(UFG::SimObjectProp **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(v3->m_Track[1].vfptr) + *(_QWORD *)&v6[1].m_Flags + 8i64)
                                  + *(_QWORD *)&v6[1].m_TypeUID
                                  + 40);
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v8->vfptr,
                  UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(
                    (UFG::SimObjectGame *)&v8->vfptr,
                    UFG::RigidBodyComponent::_TypeUID);
          else
            v10 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                     (UFG::SimObjectGame *)&v8->vfptr,
                                     UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                            (UFG::SimObject *)&v8->vfptr,
                                                                            UFG::RigidBodyComponent::_TypeUID);
        }
        else
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(
                  (UFG::SimObjectGame *)&v8->vfptr,
                  UFG::RigidBodyComponent::_TypeUID);
        }
        v11 = (UFG::RigidBody *)v10;
        if ( v10 )
        {
          v12 = v8->m_Flags;
          if ( (v12 >> 14) & 1 )
          {
            v13 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v8->vfptr,
                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          }
          else if ( (v12 & 0x8000u) == 0 )
          {
            if ( (v12 >> 13) & 1 )
            {
              v13 = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v8);
            }
            else if ( (v12 >> 12) & 1 )
            {
              v13 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 (UFG::SimObjectGame *)&v8->vfptr,
                                                                 UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
            }
            else
            {
              v13 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                 (UFG::SimObject *)&v8->vfptr,
                                                                 UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
            }
          }
          else
          {
            v13 = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                               (UFG::SimObjectGame *)&v8->vfptr,
                                                               UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          }
          v14 = v13;
          v15 = *((float *)&v3->m_Track[1].vfptr + 1);
          v16 = 0.0;
          v17 = v15 < 0.0;
          v18 = v15 == 0.0;
          if ( v15 < 0.0 )
          {
            UFG::qReflectHandleBase::qReflectHandleBase(&v71);
            v20 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v19);
            v71.mTypeUID = UFG::qStringHash64(v20, 0xFFFFFFFFFFFFFFFFui64);
            v21 = v11->mCollisionMeshData;
            if ( v21 )
              UFG::qReflectHandleBase::operator=(&v71, (UFG::qReflectHandleBase *)&v21->mObjectProperties.mPrev);
            if ( v71.mData && *(float *)&v71.mData[1].mBaseNode.mParent > 0.0 )
              v15 = *(float *)&v71.mData[1].mBaseNode.mParent;
            UFG::qReflectHandleBase::~qReflectHandleBase(&v71);
            v17 = v15 < 0.0;
            v18 = v15 == 0.0;
            if ( v15 < 0.0 )
            {
              if ( v14 )
                v15 = v14->mWeaponTypeInfo->mFireModes[v14->mFireMode]->mThrownSpeed;
              v17 = v15 < 0.0;
              v18 = v15 == 0.0;
            }
          }
          if ( !v17 && !v18 )
          {
            v22 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
            if ( v22 )
            {
              v23 = v22->m_Flags;
              if ( (v23 >> 14) & 1 )
              {
                v24 = v22->m_Components.p[47].m_pComponent;
              }
              else
              {
                if ( (v23 & 0x8000u) == 0 )
                {
                  if ( (v23 >> 13) & 1 )
                    v25 = UFG::SimObjectGame::GetComponentOfTypeHK(v22, UFG::AimingBaseComponent::_TypeUID);
                  else
                    v25 = (v23 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v22,
                                              UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                      (UFG::SimObject *)&v22->vfptr,
                                                                                      UFG::AimingBaseComponent::_TypeUID);
                }
                else
                {
                  v25 = UFG::SimObjectGame::GetComponentOfTypeHK(v22, UFG::AimingBaseComponent::_TypeUID);
                }
                v24 = v25;
              }
              if ( v24 )
              {
                if ( v14 )
                  v14->mLastOwner = v2->mSimObject.m_pPointer->mNode.mUID;
                if ( *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + 30i64)
                               + *(_QWORD *)&v6[1].m_TypeUID
                               + 40) )
                {
                  v26 = (__m128)HIDWORD(v24[1].m_BoundComponentHandles.mNode.mPrev);
                  v27 = (__m128)LODWORD(v24[1].m_BoundComponentHandles.mNode.mNext);
                  v28 = *((float *)&v24[1].m_BoundComponentHandles.mNode.mNext + 1);
                }
                else
                {
                  v26 = (__m128)HIDWORD(v24[2].m_SafePointerList.mNode.mPrev);
                  v27 = (__m128)LODWORD(v24[2].m_SafePointerList.mNode.mNext);
                  v26.m128_f32[0] = (float)(v26.m128_f32[0] * 20.0) + *(float *)&v24[1].m_pSimObject;
                  v27.m128_f32[0] = (float)(v27.m128_f32[0] * 20.0) + *((float *)&v24[1].m_pSimObject + 1);
                  v28 = (float)(*((float *)&v24[2].m_SafePointerList.mNode.mNext + 1) * 20.0)
                      + *(float *)&v24[1].m_BoundComponentHandles.mNode.mPrev;
                }
                UFG::RigidBody::GetTransform(v11, (UFG::qMatrix44 *)&v71);
                v26.m128_f32[0] = v26.m128_f32[0] - v73;
                v27.m128_f32[0] = v27.m128_f32[0] - v74;
                if ( v14 )
                  v29 = &v14->mWeaponTypeInfo->mFireModes[v14->mFireMode]->mThrownWeaponSpinAxis;
                else
                  v29 = &UFG::qVector3::msZero;
                v30 = v29->x;
                v31 = (__m128)LODWORD(v29->y);
                v32 = v29->z;
                v33 = v31;
                v33.m128_f32[0] = (float)((float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v30 * v30))
                                + (float)(v32 * v32);
                v34 = (unsigned __int128)_mm_sqrt_ps(v33);
                v69 = v34;
                v35 = *(float *)&FLOAT_1_0;
                if ( *(float *)&v34 > 0.1 )
                {
                  v36 = v27;
                  v36.m128_f32[0] = (float)(v27.m128_f32[0] * v27.m128_f32[0])
                                  + (float)(v26.m128_f32[0] * v26.m128_f32[0]);
                  if ( v36.m128_f32[0] == 0.0 )
                    v37 = 0.0;
                  else
                    v37 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v36));
                  v38 = v26;
                  v38.m128_f32[0] = v26.m128_f32[0] * v37;
                  v77 = v26.m128_f32[0] * v37;
                  v39 = v27.m128_f32[0] * v37;
                  vars0 = v39;
                  v40 = v37 * 0.0;
                  v67 = (float)(v40 * 0.0) - v39;
                  v42 = v38;
                  v42.m128_f32[0] = v38.m128_f32[0] - (float)(v40 * 0.0);
                  v76 = v42.m128_f32[0];
                  v41 = (float)(v39 * 0.0) - (float)(v38.m128_f32[0] * 0.0);
                  v42.m128_f32[0] = (float)((float)(v42.m128_f32[0] * v42.m128_f32[0]) + (float)(v67 * v67))
                                  + (float)(v41 * v41);
                  if ( v42.m128_f32[0] == 0.0 )
                    v43 = 0.0;
                  else
                    v43 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v42));
                  v44 = v43 * v67;
                  v70 = v43 * v67;
                  v45 = v43 * v76;
                  v76 = v45;
                  v46 = v43 * v41;
                  v47 = (float)(v46 * v39) - (float)(v45 * v40);
                  v48 = (float)(v44 * v40) - (float)(v46 * v38.m128_f32[0]);
                  v49 = (float)(v45 * v77) - (float)(v44 * vars0);
                  *(float *)&v50 = (float)(v48 * v48) + (float)(v47 * v47);
                  v51 = (__m128)v50;
                  v51.m128_f32[0] = *(float *)&v50 + (float)(v49 * v49);
                  if ( v51.m128_f32[0] == 0.0 )
                    v52 = 0.0;
                  else
                    v52 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v51));
                  v71.mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)__PAIR__(
                                                                                               LODWORD(vars0),
                                                                                               LODWORD(v77));
                  v71.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)LODWORD(v40);
                  v71.mTypeUID = __PAIR__(LODWORD(v76), LODWORD(v70));
                  v71.mNameUID = LODWORD(v46);
                  *(float *)&v71.mData = v47 * v52;
                  *((float *)&v71.mData + 1) = v48 * v52;
                  v72 = COERCE_UNSIGNED_INT(v49 * v52);
                  UFG::RigidBody::SetTransform(v11, (UFG::qMatrix44 *)&v71);
                  v34 = v69;
                }
                v53 = v27;
                v53.m128_f32[0] = (float)(v27.m128_f32[0] * v27.m128_f32[0])
                                + (float)(v26.m128_f32[0] * v26.m128_f32[0]);
                v54 = COERCE_FLOAT(_mm_sqrt_ps(v53)) / v15;
                v55 = (float)((float)(v28 - v75)
                            - (float)((float)((float)(UFG::BasePhysicsSystem::mParam.gravity * 0.5) * v54) * v54))
                    / v54;
                if ( v53.m128_f32[0] == 0.0 )
                  v56 = 0.0;
                else
                  v56 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v53));
                *(float *)&v71.mNameUID = (float)(v26.m128_f32[0] * v56) * v15;
                *((float *)&v71.mNameUID + 1) = (float)(v27.m128_f32[0] * v56) * v15;
                *(float *)&v71.mData = v55;
                UFG::RigidBody::SetLinearDamping(v11, 0.0);
                UFG::RigidBody::SetVelocity(v11, (UFG::qVector3 *)&v71.mNameUID);
                if ( *(float *)&v34 <= 0.1 )
                {
                  v60 = 0.0;
                  v61 = 0.0;
                  v62 = 0.0;
                  v63 = 0.0;
                  if ( v14 )
                  {
                    v64 = (float *)&v14->mWeaponTypeInfo->mFireModes[v14->mFireMode]->mSimObjectWeaponType;
                    v16 = v64[43];
                    v60 = v64[44];
                    v61 = v64[45];
                    v35 = v64[46];
                    v62 = v64[47];
                    v63 = v64[48];
                  }
                  v65 = UFG::GetRandomNumberInRange(v61, v63);
                  v66 = UFG::GetRandomNumberInRange(v60, v62);
                  vel.x = UFG::GetRandomNumberInRange(v16, v35);
                  vel.y = v66;
                  vel.z = v65;
                }
                else
                {
                  v57 = v30 * 6.2831855;
                  v58 = v31.m128_f32[0] * 6.2831855;
                  v59 = v32 * 6.2831855;
                  vel.x = (float)((float)(v58 * *(float *)&v71.mTypeUID) + (float)(v57 * *(float *)&v71.mPrev))
                        + (float)(v59 * *(float *)&v71.mData);
                  vel.y = (float)((float)(v58 * *((float *)&v71.mTypeUID + 1))
                                + (float)(v57 * *((float *)&v71.mPrev + 1)))
                        + (float)(v59 * *((float *)&v71.mData + 1));
                  vel.z = (float)((float)(v58 * *(float *)&v71.mNameUID) + (float)(v57 * *(float *)&v71.mNext))
                        + (float)(v59 * *(float *)&v72);
                }
                UFG::RigidBody::SetAngularVelocity(v11, &vel);
              }
            }
          }
        }
      }
    }
  }
}(float)(v59 * *((floa

// File Line: 2345
// RVA: 0x2F79B0
void __fastcall TargetPhysicalImpulseTask::Begin(TargetPhysicalImpulseTask *this, ActionContext *pContext)
{
  ActionContext *v2; // rsi
  TargetPhysicalImpulseTask *v3; // r15
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::RigidBody *v11; // rdi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v12; // rcx
  const char *v13; // rax
  UFG::CollisionMeshData *v14; // rdx
  UFG::SimObject *v15; // r14
  UFG::TransformNodeComponent *v16; // rbx
  UFG::TransformNodeComponent *v17; // r14
  ITrack *v18; // rcx
  float v19; // xmm6_4
  __int128 v20; // xmm4
  float v21; // xmm5_4
  float v22; // xmm3_4
  __m128 v23; // xmm2
  __int128 v24; // xmm0
  float v25; // xmm6_4
  __int128 v26; // xmm4
  float v27; // xmm5_4
  float v28; // xmm2_4
  __m128 v29; // xmm3
  UFG::SimObject *v30; // rax
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm6_4
  float v34; // xmm6_4
  float v35; // xmm0_4
  UFG::SimObjectGame *v36; // rcx
  unsigned __int16 v37; // dx
  UFG::SimComponent *v38; // rax
  float v39; // xmm3_4
  __int128 v40; // xmm2
  UFG::SimObject *v41; // rax
  float v42; // xmm0_4
  float v43; // xmm1_4
  float v44; // xmm2_4
  __m128 v45; // xmm1
  float v46; // xmm4_4
  float v47; // xmm6_4
  float v48; // xmm4_4
  float v49; // xmm0_4
  UFG::qVector3 vel; // [rsp+8h] [rbp-59h]
  UFG::qString v51; // [rsp+18h] [rbp-49h]
  float v52; // [rsp+40h] [rbp-21h]
  UFG::qReflectHandleBase v53; // [rsp+58h] [rbp-9h]
  __int64 v54; // [rsp+80h] [rbp+1Fh]

  v54 = -2i64;
  v2 = pContext;
  v3 = this;
  v4 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v4->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v6 = v7;
    }
    else
    {
      v6 = v4->m_Components.p[20].m_pComponent;
    }
    if ( v6 )
    {
      v8 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(*(_QWORD *)&v6[1].m_Flags + LOBYTE(v3->m_Track[1].vfptr) + 8i64)
                                  + *(_QWORD *)&v6[1].m_TypeUID
                                  + 40);
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
          else
            v10 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::RigidBodyComponent::_TypeUID);
        }
        else
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
        }
        v11 = (UFG::RigidBody *)v10;
        if ( v10 )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v53);
          v13 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v12);
          v53.mTypeUID = UFG::qStringHash64(v13, 0xFFFFFFFFFFFFFFFFui64);
          v14 = v11->mCollisionMeshData;
          if ( v14 )
            UFG::qReflectHandleBase::operator=(&v53, (UFG::qReflectHandleBase *)&v14->mObjectProperties.mPrev);
          if ( !v53.mData || LODWORD(v53.mData[2].mBaseNode.mChildren[1]) == 1 )
            goto LABEL_71;
          v15 = v2->mSimObject.m_pPointer;
          v16 = 0i64;
          if ( v15 )
            v17 = v15->m_pTransformNodeComponent;
          else
            v17 = 0i64;
          UFG::TransformNodeComponent::UpdateWorldTransform(v17);
          v18 = v3->m_Track;
          if ( BYTE4(v18[1].mResourceOwner) )
          {
            if ( BYTE4(v18[1].mResourceOwner) != 1 )
            {
              if ( BYTE4(v18[1].mResourceOwner) == 2 )
              {
                v19 = *(float *)&v18[1].m_TrackClassNameUID;
                v20 = *(unsigned int *)&v18[1].mBreakPoint;
                v21 = *(float *)&v18[1].mMasterRate.text.mOffset;
                vel.x = v19;
                LODWORD(vel.y) = v20;
                vel.z = v21;
                v22 = 0.0;
                if ( v19 != 0.0 || *(float *)&v20 != 0.0 || v21 != 0.0 )
                {
                  v23 = (__m128)v20;
                  v23.m128_f32[0] = (float)((float)(*(float *)&v20 * *(float *)&v20) + (float)(v19 * v19))
                                  + (float)(v21 * v21);
                  if ( v23.m128_f32[0] != 0.0 )
                    v22 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v23));
                  vel.x = v22 * v19;
                  vel.y = v22 * *(float *)&v20;
                  vel.z = v22 * v21;
                  v24 = HIDWORD(v18[1].vfptr);
                  UFG::RigidBody::ApplyAngularImpulse(v11, &vel);
                }
              }
              else
              {
                UFG::qString::qString(&v51, "TargetPhysicalImpulseTrack: Unsupported direction type!");
                UFG::qString::~qString(&v51);
              }
              goto LABEL_71;
            }
            v25 = *(float *)&v18[1].m_TrackClassNameUID;
            v26 = *(unsigned int *)&v18[1].mBreakPoint;
            v27 = *(float *)&v18[1].mMasterRate.text.mOffset;
            vel.x = v25;
            LODWORD(vel.y) = v26;
            vel.z = v27;
            v28 = 0.0;
            if ( v25 == 0.0 && *(float *)&v26 == 0.0 && v27 == 0.0 )
            {
LABEL_71:
              UFG::qReflectHandleBase::~qReflectHandleBase(&v53);
              return;
            }
            v29 = (__m128)v26;
            v29.m128_f32[0] = (float)((float)(*(float *)&v26 * *(float *)&v26) + (float)(v25 * v25))
                            + (float)(v27 * v27);
            if ( v29.m128_f32[0] != 0.0 )
              v28 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v29));
            vel.x = v28 * v25;
            vel.y = v28 * *(float *)&v26;
            vel.z = v28 * v27;
            v30 = v2->mSimObject.m_pPointer;
            if ( v30 )
              v16 = v30->m_pTransformNodeComponent;
            UFG::TransformNodeComponent::UpdateWorldTransform(v16);
            v31 = vel.x * v16->mWorldTransform.v0.y;
            v32 = (float)((float)(vel.y * v16->mWorldTransform.v1.y) + v31) + (float)(vel.z * v16->mWorldTransform.v2.y);
            v33 = (float)((float)(vel.y * v16->mWorldTransform.v1.z) + (float)(vel.x * v16->mWorldTransform.v0.z))
                + (float)(vel.z * v16->mWorldTransform.v2.z);
            vel.x = (float)((float)(vel.y * v16->mWorldTransform.v1.x) + (float)(vel.x * v16->mWorldTransform.v0.x))
                  + (float)(vel.z * v16->mWorldTransform.v2.x);
            vel.y = v32;
            vel.z = v33;
            v34 = *((float *)&v3->m_Track[1].vfptr + 1);
            UFG::RigidBody::GetMass(v11);
            v35 = v31 * v34;
            vel.x = vel.x * v35;
            vel.y = vel.y * v35;
            vel.z = vel.z * v35;
          }
          else
          {
            v36 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
            if ( !v36 )
              goto LABEL_71;
            v37 = v36->m_Flags;
            if ( (v37 >> 14) & 1 )
            {
              v38 = v36->m_Components.p[47].m_pComponent;
            }
            else if ( (v37 & 0x8000u) == 0 )
            {
              if ( (v37 >> 13) & 1 )
                v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::AimingBaseComponent::_TypeUID);
              else
                v38 = (v37 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v36,
                                          UFG::AimingBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                  (UFG::SimObject *)&v36->vfptr,
                                                                                  UFG::AimingBaseComponent::_TypeUID);
            }
            else
            {
              v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::AimingBaseComponent::_TypeUID);
            }
            if ( !v38 )
              goto LABEL_71;
            v39 = *((float *)&v38[2].vfptr + 1) - v17->mWorldTransform.v3.y;
            v40 = LODWORD(v38[2].vfptr);
            *(float *)&v40 = *(float *)&v40 - v17->mWorldTransform.v3.x;
            LODWORD(vel.x) = v40;
            vel.y = v39;
            vel.z = 0.0;
            if ( *(float *)&v40 != 0.0 || v39 != 0.0 )
            {
              v45 = (__m128)v40;
              v45.m128_f32[0] = (float)(*(float *)&v40 * *(float *)&v40) + (float)(v39 * v39);
              if ( v45.m128_f32[0] == 0.0 )
                v46 = 0.0;
              else
                v46 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v45));
              v42 = v46 * v39;
              vel.x = *(float *)&v40 * v46;
              vel.y = v46 * v39;
              vel.z = v46 * 0.0;
            }
            else
            {
              v41 = v2->mSimObject.m_pPointer;
              if ( v41 )
                v16 = v41->m_pTransformNodeComponent;
              UFG::TransformNodeComponent::UpdateWorldTransform(v16);
              v42 = v16->mWorldTransform.v0.x;
              v43 = v16->mWorldTransform.v0.y;
              v44 = v16->mWorldTransform.v0.z;
              vel.x = v16->mWorldTransform.v0.x;
              vel.y = v43;
              vel.z = v44;
            }
            UFG::RigidBody::GetMass(v11);
            vel.x = vel.x * v42;
            vel.y = vel.y * v42;
            vel.z = vel.z * v42;
            UFG::qRotationMatrixY((UFG::qMatrix44 *)&v51, *(float *)&v3->m_Track[1].mResourceOwner);
            v47 = (float)((float)(*(float *)&v51.mLength * vel.y) + (float)(*((float *)&v51.mPrev + 1) * vel.x))
                + (float)(*(float *)&v51.mStringHashUpper32 * vel.z);
            v48 = (float)((float)(*(float *)&v51.mData * vel.y) + (float)(*(float *)&v51.mNext * vel.x))
                + (float)(v52 * vel.z);
            vel.x = (float)((float)(*(float *)&v51.mMagic * vel.y) + (float)(*(float *)&v51.mPrev * vel.x))
                  + (float)(*(float *)&v51.mStringHash32 * vel.z);
            vel.y = v47;
            vel.z = v48;
            v49 = *((float *)&v3->m_Track[1].vfptr + 1);
            vel.x = vel.x * v49;
            vel.y = v47 * v49;
            vel.z = v48 * v49;
          }
          UFG::RigidBody::ApplyLinearImpulse(v11, &vel);
          goto LABEL_71;
        }
      }
    }
  }
}

// File Line: 2439
// RVA: 0x2F7860
void __fastcall TargetPhysicalDamageTask::Begin(TargetPhysicalDamageTask *this, ActionContext *pContext)
{
  TargetPhysicalDamageTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::StateMachineComponent *v11; // rcx

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v5 >> 12) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v6 = v7;
    }
    else
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v6 )
    {
      v8 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(v2->m_Track[1].vfptr) + *(_QWORD *)&v6[1].m_Flags + 8i64)
                                  + *(_QWORD *)&v6[1].m_TypeUID
                                  + 40);
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 >> 14) & 1 )
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v9 & 0x8000u) == 0 )
        {
          if ( (v9 >> 13) & 1 )
          {
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
          }
          else if ( (v9 >> 12) & 1 )
          {
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
          }
          else
          {
            v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::RigidBodyComponent::_TypeUID);
          }
        }
        else
        {
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
        }
        if ( v10 )
        {
          v11 = (UFG::StateMachineComponent *)v10[6].vfptr;
          if ( v11 )
            UFG::StateMachineComponent::ApplyDamage(
              v11,
              *(float *)&v2->m_Track[1].mResourceOwner,
              SHIDWORD(v2->m_Track[1].vfptr),
              v4->mSimObject.m_pPointer);
        }
      }
    }
  }
}

// File Line: 2466
// RVA: 0x2F9BF0
void __fastcall TargetingProfileSelectTask::Begin(TargetingProfileSelectTask *this, ActionContext *pContext)
{
  TargetingProfileSelectTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  ActionContext *v4; // rbx
  unsigned __int16 v5; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObjectGame *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  UFG::TargetingSystemPedBaseComponent *v10; // rax

  v2 = this;
  v3 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  v4 = pContext;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v6 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      v6 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v6 )
    {
      v7 = (UFG::SimObjectGame *)v4->mSimObject.m_pPointer;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v7 = (UFG::SimObjectGame *)v7->m_Components.p[20].m_pComponent;
        }
        else if ( (v8 & 0x8000u) == 0 )
        {
          if ( (v8 >> 13) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else if ( (v8 >> 12) & 1 )
          {
            v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          else
          {
            v9 = UFG::SimObject::GetComponentOfType(
                   (UFG::SimObject *)&v7->vfptr,
                   UFG::TargetingSystemBaseComponent::_TypeUID);
          }
          v7 = (UFG::SimObjectGame *)v9;
        }
        else
        {
          v7 = (UFG::SimObjectGame *)v7->m_Components.p[20].m_pComponent;
        }
      }
      v10 = (UFG::TargetingSystemPedBaseComponent *)((__int64 (*)(void))v7->vfptr[15].__vecDelDtor)();
      if ( v10 )
        UFG::TargetingSystemPedBaseComponent::SetActiveTargetingProfile(v10, (UFG::qSymbol *)&v2->m_Track[1].vfptr + 1);
    }
  }
}

// File Line: 2481
// RVA: 0x2F9A60
void __fastcall TargetWeaponModeChangeTask::Begin(TargetWeaponModeChangeTask *this, ActionContext *context)
{
  TargetWeaponModeChangeTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // r8
  UFG::SimComponent *v6; // rax
  __int64 v7; // r9
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  CAkChainCtx *v11; // rdi
  signed int v12; // esi
  CAkScheduledItem *v13; // rax
  int v14; // ebx

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      else
      {
        v6 = UFG::SimObject::GetComponentOfType(
               (UFG::SimObject *)&v3->vfptr,
               UFG::TargetingSystemBaseComponent::_TypeUID);
      }
      v5 = v6;
    }
    else
    {
      v5 = v3->m_Components.p[20].m_pComponent;
    }
    if ( v5 )
    {
      v7 = LOBYTE(v2->m_Track[1].vfptr);
      v8 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&v5[1].m_Flags + v7 + 8)
                                  + *(_QWORD *)&v5[1].m_TypeUID
                                  + 40);
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( !((v9 >> 10) & 1) && (_DWORD)v7 == 17 )
        {
          if ( (v9 >> 14) & 1 )
          {
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID);
          }
          else if ( (v9 & 0x8000u) == 0 )
          {
            if ( (v9 >> 13) & 1 )
              v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID);
            else
              v10 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::GunComponent::_TypeUID);
          }
          else
          {
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID);
          }
          v11 = (CAkChainCtx *)v10;
          if ( v10 )
          {
            v12 = *(_DWORD *)(*(_QWORD *)&UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)v10)[2].m_cmdStop.iRelativeTime
                            + 4i64);
            v13 = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v11);
            if ( v12 > 1 )
            {
              v14 = v13[2].m_cmdPlay.fadeParams.iFadeOffset + 1;
              if ( v14 == v12 )
                v14 = 0;
              UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v11)[2].m_cmdPlay.fadeParams.iFadeOffset = v14;
            }
          }
        }
      }
    }
  }
}

// File Line: 2527
// RVA: 0x2F5930
void __fastcall TargetAssignSubTargetTask::Begin(TargetAssignSubTargetTask *this, ActionContext *pActionContext)
{
  ActionContext *v2; // r14
  TargetAssignSubTargetTask *v3; // rsi
  UFG::eTargetTypeEnum v4; // edx
  UFG::SimObject *v5; // rax
  unsigned __int16 v6; // dx
  UFG::TargetingSystemBaseComponent *v7; // rdi
  UFG::SimObject *v8; // rbp
  UFG::InterestPoint *v9; // rbx
  ITrack *v10; // rax
  UFG::SimObject *v11; // rax
  signed __int64 v12; // rcx
  unsigned __int64 v13; // rax
  const char *v14; // rcx
  int v15; // eax
  bool v16; // zf
  bool v17; // sf
  ITrack *v18; // rax
  ITrack *v19; // rax
  const char *v20; // rdx
  unsigned __int16 v21; // dx
  UFG::SimComponent *v22; // rax
  UFG::SimObjectGame *v23; // rcx
  UFG::eTargetTypeEnum v24; // ebx
  unsigned __int16 v25; // dx
  unsigned int v26; // edx
  UFG::SimComponent *v27; // rax
  UFG::qSymbol childName; // [rsp+40h] [rbp+8h]

  v2 = pActionContext;
  v3 = this;
  v4 = (UFG::eTargetTypeEnum)this->m_Track[1].mResourceOwner;
  if ( v4 )
  {
    v5 = UFG::getTarget(v2->mSimObject.m_pPointer, v4);
    if ( v5 )
    {
      v6 = v5->m_Flags;
      v7 = 0i64;
      v8 = 0i64;
      if ( (v6 >> 14) & 1 )
      {
        v9 = (UFG::InterestPoint *)v5->m_Components.p[25].m_pComponent;
      }
      else if ( (v6 & 0x8000u) == 0 )
      {
        if ( (v6 >> 13) & 1 )
          v9 = (UFG::InterestPoint *)v5->m_Components.p[10].m_pComponent;
        else
          v9 = (UFG::InterestPoint *)((v6 >> 12) & 1 ? v5->m_Components.p[3].m_pComponent : UFG::SimObject::GetComponentOfType(
                                                                                              v5,
                                                                                              UFG::InterestPoint::_TypeUID));
      }
      else
      {
        v9 = (UFG::InterestPoint *)v5->m_Components.p[25].m_pComponent;
      }
      if ( v9 )
      {
        v10 = v3->m_Track;
        if ( LOBYTE(v10[1].m_TrackClassNameUID) )
        {
          v11 = UFG::InterestPoint::GetParent(v9);
        }
        else
        {
          v12 = (signed __int64)&v10[1];
          v13 = (_QWORD)v10[1].vfptr & 0xFFFFFFFFFFFFFFFEui64;
          if ( v13 )
            v14 = (const char *)(v13 + v12);
          else
            v14 = BinString::sEmptyString;
          v15 = UFG::qStringLength(v14);
          v16 = v15 == 0;
          v17 = v15 < 0;
          v18 = v3->m_Track;
          if ( v17 || v16 )
          {
            v11 = UFG::InterestPoint::GetChild(v9, HIDWORD(v18[1].mResourceOwner));
          }
          else
          {
            v19 = v18 + 1;
            childName.mUID = -1;
            v20 = (char *)v19 + ((_QWORD)v19->vfptr & 0xFFFFFFFFFFFFFFFEui64);
            if ( !((_QWORD)v19->vfptr & 0xFFFFFFFFFFFFFFFEui64) )
              v20 = BinString::sEmptyString;
            UFG::qSymbol::set_from_cstr(&childName, v20);
            v11 = UFG::InterestPoint::GetChild(v9, &childName);
          }
        }
        if ( v11 )
        {
          if ( BYTE1(v3->m_Track[1].m_TrackClassNameUID) )
          {
            v21 = v11->m_Flags;
            if ( (v21 >> 14) & 1 )
            {
              v22 = v11->m_Components.p[25].m_pComponent;
            }
            else if ( (v21 & 0x8000u) == 0 )
            {
              if ( (v21 >> 13) & 1 )
              {
                v22 = v11->m_Components.p[10].m_pComponent;
              }
              else if ( (v21 >> 12) & 1 )
              {
                v22 = v11->m_Components.p[3].m_pComponent;
              }
              else
              {
                v22 = UFG::SimObject::GetComponentOfType(v11, UFG::InterestPoint::_TypeUID);
              }
            }
            else
            {
              v22 = v11->m_Components.p[25].m_pComponent;
            }
            if ( v22 )
              v8 = (UFG::SimObject *)v22[5].m_BoundComponentHandles.mNode.mNext;
          }
          else
          {
            v8 = v11;
          }
        }
        v23 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
        v24 = *(_DWORD *)&v3->m_Track[1].mBreakPoint;
        if ( !v23 )
          goto LABEL_47;
        v25 = v23->m_Flags;
        if ( (v25 >> 14) & 1 || (v25 & 0x8000u) != 0 )
        {
          v7 = (UFG::TargetingSystemBaseComponent *)v23->m_Components.p[20].m_pComponent;
LABEL_47:
          UFG::TargetingSystemBaseComponent::SetTarget(v7, v24, v8);
          return;
        }
        if ( (v25 >> 13) & 1 )
        {
          v26 = UFG::TargetingSystemBaseComponent::_TypeUID;
        }
        else
        {
          v16 = ((v25 >> 12) & 1) == 0;
          v26 = UFG::TargetingSystemBaseComponent::_TypeUID;
          if ( v16 )
          {
            v27 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v23->vfptr,
                    UFG::TargetingSystemBaseComponent::_TypeUID);
            goto LABEL_46;
          }
        }
        v27 = UFG::SimObjectGame::GetComponentOfTypeHK(v23, v26);
LABEL_46:
        v7 = (UFG::TargetingSystemBaseComponent *)v27;
        goto LABEL_47;
      }
    }
  }
}

// File Line: 2584
// RVA: 0x2E4330
void __fastcall ProxyTargetBaseTask::~ProxyTargetBaseTask(ProxyTargetBaseTask *this)
{
  ProxyTargetBaseTask *v1; // rdx
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemItemComponent> *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v7; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax

  v1 = this;
  v2 = &this->mProxyTargetingSystemComponent;
  if ( this->mProxyTargetingSystemComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1->mProxyTransformNodeComponent;
  if ( v1->mProxyTransformNodeComponent.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mProxyTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mProxyTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mProxyTransformNodeComponent.mPrev;
  }
  v1->mProxyTransformNodeComponent.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mProxyTransformNodeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mProxyTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mProxyTransformNodeComponent.mPrev;
  if ( v1->mProxySimObject.m_pPointer )
  {
    v12 = v1->mProxySimObject.mPrev;
    v13 = v1->mProxySimObject.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    v1->mProxySimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mProxySimObject.mPrev;
    v1->mProxySimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mProxySimObject.mPrev;
  }
  v1->mProxySimObject.m_pPointer = 0i64;
  v14 = v1->mProxySimObject.mPrev;
  v15 = v1->mProxySimObject.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  v1->mProxySimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mProxySimObject.mPrev;
  v1->mProxySimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mProxySimObject.mPrev;
}

// File Line: 2590
// RVA: 0x3018A0
void __fastcall ProxyTargetBaseTask::GenerateProxySimObject(ProxyTargetBaseTask *this)
{
  ProxyTargetBaseTask *v1; // rbx
  unsigned int v2; // eax
  unsigned int v3; // edi
  __int64 v4; // r8
  UFG::qSymbol *v5; // rax
  UFG::SimObject *v6; // rax
  UFG::SimObject *v7; // rbp
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qMemoryPool *v12; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::SimComponent *v14; // r14
  UFG::SimComponent *v15; // rax
  UFG::SimComponent *v16; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v17; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  unsigned __int16 v21; // cx
  unsigned int v22; // esi
  UFG::qMemoryPool *v23; // rax
  UFG::allocator::free_link *v24; // rax
  UFG::SimComponent *v25; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemItemComponent> *v26; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  unsigned __int16 v30; // cx
  UFG::SimObjectModifier v31; // [rsp+30h] [rbp-158h]
  __int64 v32; // [rsp+50h] [rbp-138h]
  char dest; // [rsp+60h] [rbp-128h]
  UFG::qSymbol result; // [rsp+190h] [rbp+8h]
  UFG::allocator::free_link *v35; // [rsp+198h] [rbp+10h]

  v32 = -2i64;
  v1 = this;
  v2 = _S8_7;
  v3 = -1;
  if ( !(_S8_7 & 1) )
  {
    _S8_7 |= 1u;
    guidTransformNodeComponent = UFG::qStringHash32("TransformNodeComponent", 0xFFFFFFFF);
    v2 = _S8_7;
  }
  if ( !(v2 & 2) )
  {
    _S8_7 = v2 | 2;
    guidTargetingSystemItemComponent = UFG::qStringHash32("TargetingSystemItemComponent", 0xFFFFFFFF);
  }
  v4 = UniqueID++;
  UFG::qSPrintf(&dest, "ProxyTarget_%d", v4);
  v5 = UFG::qSymbol::create_from_string(&result, &dest);
  v6 = UFG::Simulation::CreateSimObject(&UFG::gSim, v5);
  v7 = v6;
  if ( v1->mProxySimObject.m_pPointer )
  {
    v8 = v1->mProxySimObject.mPrev;
    v9 = v1->mProxySimObject.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v1->mProxySimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mProxySimObject.mPrev;
    v1->mProxySimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mProxySimObject.mPrev;
  }
  v1->mProxySimObject.m_pPointer = v6;
  if ( v6 )
  {
    v10 = &v6->m_SafePointerList.mNode;
    v11 = v6->m_SafePointerList.mNode.mPrev;
    v11->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mProxySimObject.mPrev;
    v1->mProxySimObject.mPrev = v11;
    v1->mProxySimObject.mNext = v10;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mProxySimObject.mPrev;
  }
  v12 = UFG::GetSimulationMemoryPool();
  v13 = UFG::qMemoryPool::Allocate(
          v12,
          0x110ui64,
          "ProxyTargetBaseTask::GenerateProxySimObject_TransformNodeComponent",
          0i64,
          1u);
  v35 = v13;
  v14 = 0i64;
  if ( v13 )
  {
    UFG::TransformNodeComponent::TransformNodeComponent(
      (UFG::TransformNodeComponent *)v13,
      guidTransformNodeComponent,
      0i64,
      0);
    v16 = v15;
  }
  else
  {
    v16 = 0i64;
  }
  v17 = &v1->mProxyTransformNodeComponent;
  if ( v1->mProxyTransformNodeComponent.m_pPointer )
  {
    v18 = v17->mPrev;
    v19 = v1->mProxyTransformNodeComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v17->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v1->mProxyTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mProxyTransformNodeComponent.mPrev;
  }
  v1->mProxyTransformNodeComponent.m_pPointer = v16;
  if ( v16 )
  {
    v20 = v16->m_SafePointerList.mNode.mPrev;
    v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
    v17->mPrev = v20;
    v1->mProxyTransformNodeComponent.mNext = &v16->m_SafePointerList.mNode;
    v16->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v17->mPrev;
  }
  v21 = v7->m_Flags;
  if ( (v21 >> 14) & 1 )
  {
    v22 = 2;
  }
  else if ( (v21 & 0x8000u) == 0 )
  {
    if ( (v21 >> 13) & 1 )
    {
      v22 = 2;
    }
    else
    {
      v22 = -1;
      if ( (v21 >> 12) & 1 )
        v22 = 1;
    }
  }
  else
  {
    v22 = 2;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v31, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v31, v1->mProxyTransformNodeComponent.m_pPointer, v22);
  UFG::SimObjectModifier::Close(&v31);
  UFG::SimObjectModifier::~SimObjectModifier(&v31);
  v23 = UFG::GetSimulationMemoryPool();
  v24 = UFG::qMemoryPool::Allocate(
          v23,
          0x88ui64,
          "ProxyTargetBaseTask::GenerateProxySimObject_TargetingSystemItemComponent",
          0i64,
          1u);
  v35 = v24;
  if ( v24 )
  {
    UFG::TargetingSystemItemComponent::TargetingSystemItemComponent(
      (UFG::TargetingSystemItemComponent *)v24,
      guidTargetingSystemItemComponent,
      0i64,
      0);
    v14 = v25;
  }
  v26 = &v1->mProxyTargetingSystemComponent;
  if ( v1->mProxyTargetingSystemComponent.m_pPointer )
  {
    v27 = v26->mPrev;
    v28 = v1->mProxyTargetingSystemComponent.mNext;
    v27->mNext = v28;
    v28->mPrev = v27;
    v26->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v26->mPrev;
    v1->mProxyTargetingSystemComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->mProxyTargetingSystemComponent.mPrev;
  }
  v1->mProxyTargetingSystemComponent.m_pPointer = v14;
  if ( v14 )
  {
    v29 = v14->m_SafePointerList.mNode.mPrev;
    v29->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v26->mPrev;
    v26->mPrev = v29;
    v1->mProxyTargetingSystemComponent.mNext = &v14->m_SafePointerList.mNode;
    v14->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v26->mPrev;
  }
  v30 = v7->m_Flags;
  if ( (v30 >> 14) & 1 || (v30 & 0x8000u) != 0 )
    v3 = 20;
  UFG::SimObjectModifier::SimObjectModifier(&v31, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v31, v1->mProxyTargetingSystemComponent.m_pPointer, v3);
  UFG::SimObjectModifier::Close(&v31);
  UFG::SimObjectModifier::~SimObjectModifier(&v31);
}

// File Line: 2633
// RVA: 0x30B860
void __fastcall ProxyTargetBaseTask::UpdateProxySimObjectAsSyncableMatrix(ProxyTargetBaseTask *this, UFG::qMatrix44 *matProxyTargetXform, UFG::qVector3 *vPosition, UFG::qVector3 *vSyncDirection, UFG::qVector3 *vAlternateSyncDirection)
{
  __int128 v5; // xmm3
  __m128 v6; // xmm4
  float v7; // xmm5_4
  __m128 v8; // xmm7
  float v9; // xmm6_4
  __m128 v10; // xmm5
  float v11; // xmm1_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm11_4
  __m128 v15; // xmm12
  float v16; // xmm10_4
  __m128 v17; // xmm5
  float v18; // xmm2_4
  UFG::TransformNodeComponent *v19; // rcx
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // eax
  float v23; // xmm1_4

  v5 = LODWORD(vSyncDirection->y);
  v6 = (__m128)LODWORD(vSyncDirection->x);
  v7 = vSyncDirection->z;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                      (float)((float)(vSyncDirection->x * UFG::qVector3::msDirUp.x)
                            + (float)(vSyncDirection->y * UFG::qVector3::msDirUp.y))
                    + (float)(vSyncDirection->z * UFG::qVector3::msDirUp.z)) & _xmm) > 0.99984771 )
  {
    v6 = (__m128)LODWORD(vAlternateSyncDirection->x);
    v5 = LODWORD(vAlternateSyncDirection->y);
    v7 = vAlternateSyncDirection->z;
  }
  v8 = v6;
  v8.m128_f32[0] = (float)(v6.m128_f32[0] * UFG::qVector3::msDirUp.z) - (float)(v7 * UFG::qVector3::msDirUp.x);
  v9 = (float)(v7 * UFG::qVector3::msDirUp.y) - (float)(*(float *)&v5 * UFG::qVector3::msDirUp.z);
  v10 = v8;
  *(float *)&v5 = (float)(*(float *)&v5 * UFG::qVector3::msDirUp.x) - (float)(v6.m128_f32[0] * UFG::qVector3::msDirUp.y);
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v9 * v9))
                  + (float)(*(float *)&v5 * *(float *)&v5);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  v12 = v8.m128_f32[0] * v11;
  *(float *)&v5 = *(float *)&v5 * v11;
  v13 = v9 * v11;
  v15 = (__m128)v5;
  v14 = (float)(v12 * UFG::qVector3::msDirUp.z) - (float)(*(float *)&v5 * UFG::qVector3::msDirUp.y);
  v15.m128_f32[0] = (float)(*(float *)&v5 * UFG::qVector3::msDirUp.x) - (float)(v13 * UFG::qVector3::msDirUp.z);
  v17 = v15;
  v16 = (float)(v13 * UFG::qVector3::msDirUp.y) - (float)(v12 * UFG::qVector3::msDirUp.x);
  v17.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14)) + (float)(v16 * v16);
  if ( v17.m128_f32[0] == 0.0 )
    v18 = 0.0;
  else
    v18 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v17));
  v19 = (UFG::TransformNodeComponent *)this->mProxyTransformNodeComponent.m_pPointer;
  matProxyTargetXform->v0.w = 0.0;
  matProxyTargetXform->v0.x = v14 * v18;
  matProxyTargetXform->v0.y = v15.m128_f32[0] * v18;
  matProxyTargetXform->v0.z = v16 * v18;
  matProxyTargetXform->v1.x = v13;
  matProxyTargetXform->v1.w = 0.0;
  matProxyTargetXform->v1.y = v12;
  LODWORD(matProxyTargetXform->v1.z) = v5;
  v20 = UFG::qVector3::msDirUp.x;
  v21 = UFG::qVector3::msDirUp.z;
  matProxyTargetXform->v2.y = UFG::qVector3::msDirUp.y;
  matProxyTargetXform->v2.w = 0.0;
  matProxyTargetXform->v2.x = v20;
  matProxyTargetXform->v2.z = v21;
  v22 = vPosition->x;
  v23 = vPosition->z;
  matProxyTargetXform->v3.y = vPosition->y;
  matProxyTargetXform->v3.x = v22;
  matProxyTargetXform->v3.w = 1.0;
  matProxyTargetXform->v3.z = v23;
  UFG::TransformNodeComponent::SetWorldTransform(v19, matProxyTargetXform);
}

// File Line: 2672
// RVA: 0x2E0420
void __fastcall ProxyTargetSphereCastTask::ProxyTargetSphereCastTask(ProxyTargetSphereCastTask *this)
{
  ProxyTargetSphereCastTask *v1; // rdx
  UFG::qNode<ITask,ITask> *v2; // rax
  ProxyTargetBaseTask *v3; // rcx
  UFG::qSafePointer<UFG::SimObject,UFG::TransformNodeComponent> *v4; // [rsp+28h] [rbp+10h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *v5; // [rsp+30h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemItemComponent> *v6; // [rsp+30h] [rbp+18h]

  v1 = this;
  v2 = (UFG::qNode<ITask,ITask> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable';
  this->vfptr = (ITaskVtbl *)&Task<ProxyTargetSphereCastTrack>::`vftable';
  v3 = (ProxyTargetBaseTask *)&this->mProxySimObject;
  v3->mProxySimObject.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mProxySimObject.mPrev;
  v3->mProxySimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v3->mProxySimObject.mPrev;
  v3->mProxySimObject.m_pPointer = 0i64;
  v5 = &v3->mProxyTransformNodeComponent;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v3->mProxyTransformNodeComponent.m_pPointer = 0i64;
  v6 = &v3->mProxyTargetingSystemComponent;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v3->mProxyTargetingSystemComponent.m_pPointer = 0i64;
  v1->vfptr = (ITaskVtbl *)&ProxyTargetSphereCastTask::`vftable';
  v4 = &v1->mRelativeToTransformNodeComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v1->mRelativeToTransformNodeComponent.m_pPointer = 0i64;
}

// File Line: 2676
// RVA: 0x2E4410
void __fastcall ProxyTargetSphereCastTask::~ProxyTargetSphereCastTask(ProxyTargetSphereCastTask *this)
{
  ProxyTargetSphereCastTask *v1; // rbx
  UFG::qSafePointer<UFG::SimObject,UFG::TransformNodeComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rdx
  UFG::qNode<ITask,ITask> *v8; // rcx
  UFG::qNode<ITask,ITask> *v9; // rax

  v1 = this;
  this->vfptr = (ITaskVtbl *)&ProxyTargetSphereCastTask::`vftable';
  v2 = &this->mRelativeToTransformNodeComponent;
  if ( this->mRelativeToTransformNodeComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  ProxyTargetBaseTask::~ProxyTargetBaseTask((ProxyTargetBaseTask *)&v1->mProxySimObject);
  v1->vfptr = (ITaskVtbl *)&ITask::`vftable';
  v7 = (UFG::qNode<ITask,ITask> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

// File Line: 2680
// RVA: 0x2F2220
void __fastcall ProxyTargetSphereCastTask::Begin(ProxyTargetSphereCastTask *this, ActionContext *pContext)
{
  this->mContext = pContext;
  ProxyTargetBaseTask::GenerateProxySimObject((ProxyTargetBaseTask *)&this->mProxySimObject);
}

// File Line: 2688
// RVA: 0x305FF0
char __fastcall ProxyTargetSphereCastTask::Update(ProxyTargetSphereCastTask *this, float fDeltaTime)
{
  ProxyTargetSphereCastTask *v2; // rdi
  ITrack *v4; // rax
  __int64 v5; // r13
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::TargetingSystemBaseComponent *v8; // rsi
  UFG::SimComponent *v9; // rax
  unsigned int v10; // ebx
  int v11; // er12
  UFG::SimObjectProp *v12; // rcx
  unsigned __int16 v13; // dx
  UFG::CharacterAnimationComponent *v14; // rax
  Creature *v15; // r14
  int v16; // edx
  UFG::SimObject *v17; // rbx
  UFG::TransformNodeComponent *v18; // rbx
  __int128 *v19; // rax
  __int128 v20; // xmm2
  __int128 v21; // xmm1
  __int128 v22; // xmm0
  ITrack *v23; // r8
  float v24; // xmm15_4
  float v25; // xmm8_4
  float v26; // xmm7_4
  UFG::SimObjectCVBase *v27; // r14
  unsigned int v28; // ebx
  unsigned __int16 v29; // cx
  UFG::CharacterAnimationComponent *v30; // rax
  Creature *v31; // r15
  UFG::TransformNodeComponent *v32; // rbx
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm2_4
  ITrack *v36; // rax
  __m128 v37; // xmm4
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  float v40; // xmm9_4
  __m128 v41; // xmm3
  float v42; // xmm2_4
  __m128 v43; // xmm4
  __m128 v44; // xmm5
  float v45; // xmm1_4
  float v46; // xmm5_4
  float v47; // xmm10_4
  float v48; // xmm8_4
  __m128 v49; // xmm4
  __m128 v50; // xmm5
  float v51; // xmm5_4
  float v52; // xmm5_4
  float v53; // xmm10_4
  __m128 v54; // xmm2
  float v55; // xmm6_4
  float *v56; // rax
  float v57; // xmm6_4
  float v58; // xmm2_4
  float v59; // xmm8_4
  float v60; // xmm3_4
  float v61; // xmm10_4
  float v62; // xmm11_4
  float v63; // xmm15_4
  float v64; // xmm7_4
  float v65; // xmm6_4
  ITrack *v66; // r8
  signed __int64 v67; // rdx
  UFG::qMatrix44 *v68; // rbx
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v69; // rbx
  int v70; // xmm3_4
  int v71; // xmm1_4
  unsigned int v72; // xmm1_4
  unsigned int v73; // xmm2_4
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v74; // rsi
  UFG::TransformNodeComponent *v75; // rsi
  UFG::qMatrix44 *v76; // rax
  UFG::qVector4 v77; // xmm2
  UFG::qVector4 v78; // xmm1
  UFG::qVector4 v79; // xmm0
  UFG::qVector4 v80; // [rsp+30h] [rbp-98h]
  char start[24]; // [rsp+40h] [rbp-88h]
  __int128 v82; // [rsp+58h] [rbp-70h]
  float v83; // [rsp+68h] [rbp-60h]
  int v84; // [rsp+6Ch] [rbp-5Ch]
  __int128 v85; // [rsp+70h] [rbp-58h]
  float v86; // [rsp+80h] [rbp-48h]
  float v87; // [rsp+88h] [rbp-40h]
  float v88; // [rsp+8Ch] [rbp-3Ch]
  float v89; // [rsp+90h] [rbp-38h]
  float v90; // [rsp+98h] [rbp-30h]
  float v91; // [rsp+9Ch] [rbp-2Ch]
  float v92; // [rsp+A0h] [rbp-28h]
  float v93; // [rsp+A8h] [rbp-20h]
  float v94; // [rsp+ACh] [rbp-1Ch]
  float v95; // [rsp+B0h] [rbp-18h]
  __int64 v96; // [rsp+B8h] [rbp-10h]
  UFG::qMatrix44 result; // [rsp+C8h] [rbp+0h]
  UFG::ShapeCasterCollector sc; // [rsp+108h] [rbp+40h]
  UFG::qMatrix44 v99; // [rsp+138h] [rbp+70h]
  float v100; // [rsp+228h] [rbp+160h]
  float v101; // [rsp+238h] [rbp+170h]
  float v102; // [rsp+240h] [rbp+178h]

  v96 = -2i64;
  v2 = this;
  if ( !this->mProxySimObject.m_pPointer )
    return 0;
  v4 = this->m_Track;
  v5 = LOBYTE(v4[1].vfptr);
  if ( !LOBYTE(v4[1].vfptr) )
    return 0;
  v6 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v6 )
  {
    v7 = v6->m_Flags;
    if ( (v7 >> 14) & 1 )
    {
      v8 = (UFG::TargetingSystemBaseComponent *)v6->m_Components.p[20].m_pComponent;
    }
    else if ( (v7 & 0x8000u) == 0 )
    {
      if ( (v7 >> 13) & 1 )
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        v9 = (v7 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::TargetingSystemBaseComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::TargetingSystemBaseComponent::_TypeUID);
      v8 = (UFG::TargetingSystemBaseComponent *)v9;
    }
    else
    {
      v8 = (UFG::TargetingSystemBaseComponent *)v6->m_Components.p[20].m_pComponent;
    }
    if ( v8 )
    {
      v10 = v2->m_Track[1].mMasterRate.expression.mOffset;
      v11 = -1;
      if ( v10 != -1
        && v10 != symWorldSpace.mUID
        && v10 != symLocalSpace.mUID
        && (v12 = (UFG::SimObjectProp *)v2->mContext->mSimObject.m_pPointer) != 0i64
        && ((v13 = v12->m_Flags, !((v13 >> 14) & 1)) ? ((v13 & 0x8000u) == 0 ? (!((v13 >> 13) & 1) ? (!((v13 >> 12) & 1) ? (v14 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v12->vfptr, UFG::CharacterAnimationComponent::_TypeUID)) : (v14 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)&v12->vfptr, UFG::CharacterAnimationComponent::_TypeUID))) : (v14 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>(v12))) : (v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v12))) : (v14 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectCVBase *)v12)),
            v14
         && (v15 = v14->mCreature) != 0i64
         && (!v15->mPose.mRigHandle.mData ? (v16 = -1) : (v16 = Skeleton::GetBoneID(
                                                                  v15->mPose.mRigHandle.mUFGSkeleton,
                                                                  v10)),
             v16 >= 0)) )
      {
        Creature::GetTransform(v15, v16, (UFG::qMatrix44 *)((char *)&v82 + 8));
      }
      else
      {
        v17 = v2->mContext->mSimObject.m_pPointer;
        if ( v17 && (v18 = v17->m_pTransformNodeComponent) != 0i64 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(v18);
          v19 = (__int128 *)&v18->mWorldTransform;
        }
        else
        {
          v19 = (__int128 *)&UFG::qMatrix44::msIdentity;
        }
        v20 = v19[1];
        v21 = v19[2];
        v22 = v19[3];
        *(__int128 *)((char *)&v82 + 8) = *v19;
        v85 = v20;
        *(_OWORD *)&start[8] = v21;
        v82 = v22;
      }
      v23 = v2->m_Track;
      v24 = *(float *)&v23[1].mBreakPoint;
      v25 = *(float *)&v23[1].mMasterRate.text.mOffset;
      v100 = *(float *)&v23[1].mMasterRate.text.mOffset;
      v26 = *((float *)&v23[1].mMasterRate.text.mOffset + 1);
      v102 = *((float *)&v23[1].mMasterRate.text.mOffset + 1);
      if ( BYTE4(v23[1].mMasterRate.expression.mOffset) )
      {
        v27 = (UFG::SimObjectCVBase *)v8->m_pTargets[(unsigned __int8)v8->m_pTargetingMap->m_Map.p[BYTE4(v23[1].mMasterRate.expression.mOffset)]].m_pTarget.m_pPointer;
        if ( v27 )
        {
          v28 = LODWORD(v23[1].mMasterRate.value);
          if ( v28 == -1 || v28 == symWorldSpace.mUID || v28 == symLocalSpace.mUID )
            goto LABEL_98;
          v29 = v27->m_Flags;
          if ( (v29 >> 14) & 1 )
          {
            v30 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v27);
          }
          else if ( (v29 & 0x8000u) == 0 )
          {
            if ( (v29 >> 13) & 1 )
              v30 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v27);
            else
              v30 = (UFG::CharacterAnimationComponent *)((v29 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v27->vfptr,
                                                                             UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v27->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
          }
          else
          {
            v30 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v27);
          }
          if ( !v30 )
            goto LABEL_98;
          v31 = v30->mCreature;
          if ( !v31 )
            goto LABEL_98;
          if ( v31->mPose.mRigHandle.mData )
            v11 = Skeleton::GetBoneID(v31->mPose.mRigHandle.mUFGSkeleton, v28);
          if ( v11 >= 0 )
          {
            Creature::GetTransform(v31, v11, &result);
            v24 = result.v3.x;
            v25 = result.v3.y;
            v26 = result.v3.z;
          }
          else
          {
LABEL_98:
            v32 = v27->m_pTransformNodeComponent;
            if ( v32 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v27->m_pTransformNodeComponent);
              v33 = v32->mWorldTransform.v3.y;
              v34 = v32->mWorldTransform.v3.z;
              v80.x = v32->mWorldTransform.v3.x;
              *(_QWORD *)&v80.y = __PAIR__(LODWORD(v34), LODWORD(v33));
              v80.w = 1.0;
            }
            else
            {
              v80 = UFG::qVector4::msZero;
            }
            v25 = v80.y;
            v24 = v80.x;
            v26 = v80.z;
          }
        }
        UFG::qInverseAffine((UFG::qMatrix44 *)((char *)&v85 + 8), (UFG::qMatrix44 *)((char *)&v82 + 8));
        v35 = (float)((float)((float)(v24 * *((float *)&v85 + 3)) + (float)(v25 * v88)) + (float)(v26 * v91)) + v94;
        v102 = (float)((float)((float)(v24 * v86) + (float)(v25 * v89)) + (float)(v26 * v92)) + v95;
        v24 = (float)((float)((float)(v24 * *((float *)&v85 + 2)) + (float)(v25 * v87)) + (float)(v26 * v90)) + v93;
        v100 = v35;
      }
      v36 = v2->m_Track;
      if ( *((_BYTE *)&v36[1].mMasterRate.value + 4) )
      {
        v37 = (__m128)DWORD2(v82);
        v38 = v37;
        v38.m128_f32[0] = (float)(v37.m128_f32[0] * v37.m128_f32[0])
                        + (float)(*((float *)&v82 + 3) * *((float *)&v82 + 3));
        if ( v38.m128_f32[0] == 0.0 )
        {
          v39 = 0i64;
        }
        else
        {
          v39 = (__m128)(unsigned int)FLOAT_1_0;
          v39.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v38));
        }
        v40 = v39.m128_f32[0] * 0.0;
        v41 = v39;
        v41.m128_f32[0] = v39.m128_f32[0] * *((float *)&v82 + 3);
        v42 = v39.m128_f32[0] * *((float *)&v82 + 2);
        *((_QWORD *)&v82 + 1) = __PAIR__(v41.m128_u32[0], LODWORD(v42));
        v83 = v40;
        v84 = 0;
        v43 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        v43.m128_f32[0] = (float)((float)(v43.m128_f32[0] * v43.m128_f32[0])
                                + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                        + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
        if ( v43.m128_f32[0] == 0.0 )
        {
          v44 = 0i64;
        }
        else
        {
          v44 = (__m128)(unsigned int)FLOAT_1_0;
          v44.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v43));
        }
        v45 = v44.m128_f32[0] * UFG::qVector3::msDirUp.z;
        v49 = v44;
        v49.m128_f32[0] = v44.m128_f32[0] * UFG::qVector3::msDirUp.y;
        v46 = v44.m128_f32[0] * UFG::qVector3::msDirUp.x;
        v47 = (float)(v46 * v41.m128_f32[0]) - (float)(v42 * v49.m128_f32[0]);
        v48 = (float)(v42 * v45) - (float)(v46 * v40);
        v49.m128_f32[0] = (float)(v49.m128_f32[0] * v40) - (float)(v45 * v41.m128_f32[0]);
        v50 = v49;
        v50.m128_f32[0] = (float)((float)(v49.m128_f32[0] * v49.m128_f32[0]) + (float)(v48 * v48)) + (float)(v47 * v47);
        if ( v50.m128_f32[0] == 0.0 )
          v51 = 0.0;
        else
          v51 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v50));
        *(float *)&v85 = v49.m128_f32[0] * v51;
        *((float *)&v85 + 1) = v48 * v51;
        *((float *)&v85 + 2) = v51 * v47;
        HIDWORD(v85) = 0;
        v52 = (float)(v42 * (float)(v48 * v51)) - (float)(v41.m128_f32[0] * (float)(v49.m128_f32[0] * v51));
        v53 = (float)(v40 * *(float *)&v85) - (float)(v42 * *((float *)&v85 + 2));
        v41.m128_f32[0] = (float)(v41.m128_f32[0] * *((float *)&v85 + 2)) - (float)(v40 * *((float *)&v85 + 1));
        v54 = v41;
        v54.m128_f32[0] = (float)((float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v53 * v53)) + (float)(v52 * v52);
        if ( v54.m128_f32[0] == 0.0 )
          v55 = 0.0;
        else
          v55 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v54));
        *(float *)&start[8] = v41.m128_f32[0] * v55;
        *(float *)&start[12] = v55 * v53;
        *(float *)&start[16] = v55 * v52;
        *(_DWORD *)&start[20] = 0;
        HIDWORD(v82) = 1065353216;
      }
      UFG::ShapeCasterCollector::ShapeCasterCollector(&sc, *((float *)&v36[1].vfptr + 1), LODWORD(v36[1].mTimeBegin), 0);
      v56 = (float *)v2->m_Track;
      v57 = v56[16];
      v101 = v57;
      v58 = v56[17];
      v59 = v56[18];
      v83 = (float)((float)((float)(v56[17] * *(float *)&v85) + (float)(v57 * *((float *)&v82 + 2)))
                  + (float)(v56[18] * *(float *)&start[8]))
          + *(float *)&v82;
      v60 = (float)((float)((float)(v58 * *((float *)&v85 + 1)) + (float)(v57 * *((float *)&v82 + 3)))
                  + (float)(v59 * *(float *)&start[12]))
          + *((float *)&v82 + 1);
      v101 = (float)((float)((float)(v57 * v83) + (float)(v58 * *((float *)&v85 + 2)))
                   + (float)(v59 * *(float *)&start[16]))
           + *((float *)&v82 + 2);
      *(float *)&v85 = v100 * *(float *)&v85;
      v61 = (float)((float)(*(float *)&v85 + (float)(v24 * *((float *)&v82 + 2))) + (float)(v102 * *(float *)&start[8]))
          + *(float *)&v82;
      v62 = (float)((float)((float)(v100 * *((float *)&v85 + 1)) + (float)(v24 * *((float *)&v82 + 3)))
                  + (float)(v102 * *(float *)&start[12]))
          + *((float *)&v82 + 1);
      v63 = (float)((float)((float)(v24 * v83) + (float)(v100 * *((float *)&v85 + 2)))
                  + (float)(v102 * *(float *)&start[16]))
          + *((float *)&v82 + 2);
      *(float *)&start[16] = v61;
      *(float *)&start[20] = v62;
      *(float *)&v82 = v63;
      v64 = v83;
      *(float *)start = v83;
      *(float *)&start[4] = (float)((float)((float)(v58 * *((float *)&v85 + 1)) + (float)(v57 * *((float *)&v82 + 3)))
                                  + (float)(v59 * *(float *)&start[12]))
                          + *((float *)&v82 + 1);
      v65 = v101;
      *(float *)&start[8] = v101;
      UFG::BasePhysicsSystem::CastShape(
        UFG::BasePhysicsSystem::mInstance,
        &sc,
        (UFG::qVector3 *)start,
        (UFG::qVector3 *)&start[16]);
      v66 = v2->m_Track;
      if ( LOBYTE(v66[1].mTimeEnd)
        && (v67 = (signed __int64)&v8->m_pTargets[(unsigned __int8)v8->m_pTargetingMap->m_Map.p[v5]],
            *(_QWORD *)(v67 + 40))
        && *(_BYTE *)(v67 + 49) )
      {
        if ( BYTE1(v66[1].mTimeEnd) )
        {
          v68 = (UFG::qMatrix44 *)v2->mRelativeToTransformNodeComponent.m_pPointer;
          if ( v68 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->mRelativeToTransformNodeComponent.m_pPointer);
            UFG::qMatrix44::operator*(&v2->mLocalTransform, &result, v68 + 2);
            UFG::TransformNodeComponent::SetWorldTransform(
              (UFG::TransformNodeComponent *)v2->mProxyTransformNodeComponent.m_pPointer,
              &result);
          }
        }
      }
      else
      {
        v69 = sc.mHitList.mNode.mNext;
        if ( (UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *)sc.mHitList.mNode.mNext != &sc.mHitList
          && sc.mHitList.mNode.mNext )
        {
          *(float *)start = v61 - v64;
          *(float *)&start[4] = v62 - v60;
          *(float *)&start[8] = v63 - v65;
          v70 = HIDWORD(sc.mHitList.mNode.mNext[2].mPrev) ^ _xmm[0];
          v71 = LODWORD(sc.mHitList.mNode.mNext[2].mPrev) ^ _xmm[0];
          *(_DWORD *)&start[16] = HIDWORD(sc.mHitList.mNode.mNext[1].mNext) ^ _xmm[0];
          *(_DWORD *)&start[20] = v71;
          LODWORD(v82) = v70;
          v72 = HIDWORD(sc.mHitList.mNode.mNext[1].mPrev);
          v73 = (unsigned int)sc.mHitList.mNode.mNext[1].mNext;
          v80.x = *(float *)&sc.mHitList.mNode.mNext[1].mPrev;
          *(_QWORD *)&v80.y = __PAIR__(v73, v72);
          ProxyTargetBaseTask::UpdateProxySimObjectAsSyncableMatrix(
            (ProxyTargetBaseTask *)&v2->mProxySimObject,
            (UFG::qMatrix44 *)((char *)&v85 + 8),
            (UFG::qVector3 *)&v80,
            (UFG::qVector3 *)&start[16],
            (UFG::qVector3 *)start);
          UFG::TargetingSystemBaseComponent::SetTarget(v8, (UFG::eTargetTypeEnum)v5, v2->mProxySimObject.m_pPointer);
          v74 = v69[5].mPrev;
          if ( v74 )
          {
            if ( BYTE1(v2->m_Track[1].mTimeEnd) )
            {
              v75 = (UFG::TransformNodeComponent *)v74[5].mNext;
              if ( v75 )
              {
                UFG::qSafePointer<Creature,Creature>::operator=(
                  (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&v2->mRelativeToTransformNodeComponent,
                  (UFG::SimComponent *)&v75->vfptr);
                UFG::TransformNodeComponent::UpdateWorldTransform(v75);
                UFG::qInverseAffine(&result, &v75->mWorldTransform);
                v76 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)((char *)&v85 + 8), &v99, &result);
                v77 = v76->v1;
                v78 = v76->v2;
                v79 = v76->v3;
                v2->mLocalTransform.v0 = v76->v0;
                v2->mLocalTransform.v1 = v77;
                v2->mLocalTransform.v2 = v78;
                v2->mLocalTransform.v3 = v79;
              }
            }
            UFG::TargetingSystemBaseComponent::SetTarget(
              (UFG::TargetingSystemBaseComponent *)v2->mProxyTargetingSystemComponent.m_pPointer,
              eTARGET_TYPE_INTERACTION_POINT1,
              (UFG::SimObject *)v69[5].mPrev);
          }
        }
        else
        {
          UFG::TargetingSystemBaseComponent::ClearTarget(v8, (UFG::eTargetTypeEnum)v5);
        }
      }
      UFG::ShapeCasterCollector::~ShapeCasterCollector(&sc);
    }
  }
  return 1;
}

// File Line: 2916
// RVA: 0x2FFA90
void __fastcall ProxyTargetSphereCastTask::End(ProxyTargetSphereCastTask *this)
{
  UFG::Simulation::DestroySimObject(&UFG::gSim, this->mProxySimObject.m_pPointer);
}

