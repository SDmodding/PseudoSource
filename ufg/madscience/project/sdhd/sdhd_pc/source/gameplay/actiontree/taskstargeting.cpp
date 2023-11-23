// File Line: 67
// RVA: 0x2F6660
void __fastcall TargetFractureTask::Begin(TargetFractureTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // rax
  __int64 vfptr_low; // rcx
  float v9; // xmm1_4
  float v10; // xmm2_4
  bool v11; // r9
  float v12; // xmm3_4
  float v13; // xmm1_4
  __int64 v14; // r10
  __int64 v15; // rcx
  UFG::qVector3 v16; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 v17; // [rsp+30h] [rbp-18h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      m_Track = this->m_Track;
      vfptr_low = LODWORD(m_Track[1].vfptr);
      v9 = *(float *)&m_Track[1].mBreakPoint;
      v10 = *(float *)&m_Track[1].mMasterRate.text.mOffset;
      v11 = BYTE4(m_Track[1].mMasterRate.text.mOffset) != 0;
      LODWORD(v16.x) = m_Track[1].m_TrackClassNameUID;
      v16.y = v9;
      v16.z = v10;
      v12 = *((float *)&m_Track[1].mResourceOwner + 1);
      v13 = *(float *)&m_Track[1].mResourceOwner;
      v14 = *(unsigned __int8 *)(vfptr_low + *(_QWORD *)&m_pComponent[1].m_Flags + 8);
      v15 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
      v17.x = *((float *)&m_Track[1].vfptr + 1);
      v17.y = v13;
      v17.z = v12;
      UFG::ShearObject(*(UFG::SimObject **)(56 * v14 + v15 + 40), &v17, &v16, v11);
    }
  }
}

// File Line: 87
// RVA: 0x2F6520
void __fastcall TargetFractureStrengthTask::Begin(TargetFractureStrengthTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v6; // rax
  UFG::SimObject *v7; // rcx
  UFG::RigidBodyComponent *v8; // r9
  UFG::qSafePointer<UFG::SimComponent,UFG::RigidBodyComponent> *p_mRigidBody; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::RigidBodyComponent *parentOut; // [rsp+38h] [rbp+10h] BYREF

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v6;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = *(UFG::SimObject **)(56i64
                              * *(unsigned __int8 *)(LODWORD(this->m_Track[1].vfptr)
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
      parentOut = 0i64;
      UFG::PhysicsSystem::FindParentObjectOfSimObject(v7, &parentOut, &this->mIndex);
      v8 = parentOut;
      if ( parentOut )
      {
        p_mRigidBody = &this->mRigidBody;
        if ( this->mRigidBody.m_pPointer )
        {
          mPrev = p_mRigidBody->mPrev;
          mNext = this->mRigidBody.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_mRigidBody->mPrev = p_mRigidBody;
          this->mRigidBody.mNext = &this->mRigidBody;
        }
        this->mRigidBody.m_pPointer = v8;
        if ( v8 )
        {
          v12 = v8->m_SafePointerList.mNode.UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
          v12->mNext = p_mRigidBody;
          p_mRigidBody->mPrev = v12;
          this->mRigidBody.mNext = &v8->m_SafePointerList.mNode;
          v8->m_SafePointerList.mNode.UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_mRigidBody;
        }
        UFG::RigidBody::DisableFracturePartByIndex((UFG::RigidBody *)this->mRigidBody.m_pPointer, this->mIndex);
        UFG::RigidBody::EnableFracturePartByIndex(
          (UFG::RigidBody *)this->mRigidBody.m_pPointer,
          this->mIndex,
          FRACTURE_STRENGTH_ALTERNATE);
      }
    }
  }
}

// File Line: 114
// RVA: 0x300CC0
void __fastcall TargetFractureStrengthTask::End(TargetFractureStrengthTask *this)
{
  UFG::RigidBody *m_pPointer; // rcx

  m_pPointer = (UFG::RigidBody *)this->mRigidBody.m_pPointer;
  if ( m_pPointer )
  {
    UFG::RigidBody::DisableFracturePartByIndex(m_pPointer, this->mIndex);
    UFG::RigidBody::EnableFracturePartByIndex(
      (UFG::RigidBody *)this->mRigidBody.m_pPointer,
      this->mIndex,
      FRACTURE_STRENGTH_NORMAL);
  }
}

// File Line: 127
// RVA: 0x2F6AC0
void __fastcall TargetJumpTask::Begin(TargetJumpTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::SimComponent *m_pTransformNodeComponent; // rdi
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::CharacterPhysicsComponent> *p_m_pCharacterPhysicsComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimObject *v12; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::SimObjectGame *v17; // rcx
  __int16 v18; // dx
  UFG::SimComponent *v19; // r8
  UFG::SimComponent *v20; // rax
  UFG::SimObject *v21; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::CharacterPhysicsComponent *v26; // rcx
  float v27; // xmm6_4
  UFG::CharacterPhysicsComponent *v28; // rcx
  UFG::qVector3 result; // [rsp+20h] [rbp-28h] BYREF

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  m_pTransformNodeComponent = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[27].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::CharacterPhysicsComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CharacterPhysicsComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pCharacterPhysicsComponent = &this->m_pCharacterPhysicsComponent;
  if ( this->m_pCharacterPhysicsComponent.m_pPointer )
  {
    mPrev = p_m_pCharacterPhysicsComponent->mPrev;
    mNext = this->m_pCharacterPhysicsComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pCharacterPhysicsComponent->mPrev = p_m_pCharacterPhysicsComponent;
    this->m_pCharacterPhysicsComponent.mNext = &this->m_pCharacterPhysicsComponent;
  }
  this->m_pCharacterPhysicsComponent.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v11 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v11->mNext = p_m_pCharacterPhysicsComponent;
    p_m_pCharacterPhysicsComponent->mPrev = v11;
    this->m_pCharacterPhysicsComponent.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pCharacterPhysicsComponent;
  }
  v12 = this->mContext->mSimObject.m_pPointer;
  if ( v12 )
    m_pTransformNodeComponent = v12->m_pTransformNodeComponent;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    v14 = p_m_pTransformNodeComponent->mPrev;
    v15 = this->m_pTransformNodeComponent.mNext;
    v14->mNext = v15;
    v15->mPrev = v14;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  }
  this->m_pTransformNodeComponent.m_pPointer = m_pTransformNodeComponent;
  if ( m_pTransformNodeComponent )
  {
    v16 = m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev;
    v16->mNext = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = v16;
    this->m_pTransformNodeComponent.mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
    m_pTransformNodeComponent->m_SafePointerList.mNode.mPrev = p_m_pTransformNodeComponent;
  }
  v17 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v17 )
  {
    v18 = v17->m_Flags;
    if ( (v18 & 0x4000) != 0 )
    {
      v19 = v17->m_Components.p[20].m_pComponent;
    }
    else if ( v18 >= 0 )
    {
      v20 = (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(v17, UFG::TargetingSystemBaseComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(v17, UFG::TargetingSystemBaseComponent::_TypeUID);
      v19 = v20;
    }
    else
    {
      v19 = v17->m_Components.p[20].m_pComponent;
    }
    if ( v19 )
    {
      v21 = *(UFG::SimObject **)(56i64
                               * *(unsigned __int8 *)(HIDWORD(this->m_Track[1].mResourceOwner)
                                                    + *(_QWORD *)&v19[1].m_Flags
                                                    + 8i64)
                               + *(_QWORD *)&v19[1].m_TypeUID
                               + 40);
      p_m_pTargetSimObject = &this->m_pTargetSimObject;
      if ( this->m_pTargetSimObject.m_pPointer )
      {
        v23 = p_m_pTargetSimObject->mPrev;
        v24 = this->m_pTargetSimObject.mNext;
        v23->mNext = v24;
        v24->mPrev = v23;
        p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
        this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
      }
      this->m_pTargetSimObject.m_pPointer = v21;
      if ( v21 )
      {
        v25 = v21->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
        v25->mNext = p_m_pTargetSimObject;
        p_m_pTargetSimObject->mPrev = v25;
        this->m_pTargetSimObject.mNext = &v21->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
        v21->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pTargetSimObject;
      }
    }
  }
  v26 = (UFG::CharacterPhysicsComponent *)this->m_pCharacterPhysicsComponent.m_pPointer;
  if ( v26 && this->m_pTransformNodeComponent.m_pPointer )
  {
    if ( this->m_pTargetSimObject.m_pPointer )
    {
      v27 = *(float *)&this->m_Track[1].vfptr;
      UFG::CharacterPhysicsComponent::GetVelocity(v26, &result);
      v28 = (UFG::CharacterPhysicsComponent *)this->m_pCharacterPhysicsComponent.m_pPointer;
      result.x = result.x + (float)(UFG::qVector3::msDirUp.x * v27);
      result.y = result.y + (float)(UFG::qVector3::msDirUp.y * v27);
      result.z = result.z + (float)(UFG::qVector3::msDirUp.z * v27);
      UFG::CharacterPhysicsComponent::SetVelocity(v28, &result);
    }
  }
}

// File Line: 158
// RVA: 0x30CB30
void __fastcall debugDrawTrajectory(
        float tFlight,
        float gravity,
        UFG::qVector3 *startPoint,
        UFG::qVector3 *vXYdir,
        const float vXY,
        float vUpStart,
        float dt)
{
  float y; // xmm3_4
  float z; // xmm2_4
  float v10; // xmm10_4
  Render::DebugDrawContext *Context; // rdi
  float v14; // xmm4_4
  float x; // xmm5_4
  float v16; // xmm13_4
  float v17; // xmm8_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  UFG::qVector3 p1; // [rsp+40h] [rbp-A8h] BYREF
  UFG::qVector3 p0; // [rsp+50h] [rbp-98h] BYREF

  y = startPoint->y;
  z = startPoint->z;
  v10 = 0.0;
  p0.x = startPoint->x;
  p0.y = y;
  p0.z = z;
  p1.x = p0.x;
  p1.y = y;
  p1.z = z;
  Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(Render::DebugDrawManager::mInstance, 1u);
  if ( tFlight > 0.0 )
  {
    v14 = p1.y;
    x = p1.x;
    v16 = p1.z;
    v17 = vXY * dt;
    do
    {
      v18 = vUpStart;
      vUpStart = vUpStart + (float)(gravity * dt);
      v19 = v17 * vXYdir->y;
      v20 = (float)((float)(v17 * vXYdir->z) + v16)
          + (float)((float)(v18 * dt) + (float)((float)(dt * dt) * (float)(gravity * 0.5)));
      p1.x = x + (float)(v17 * vXYdir->x);
      p1.z = v20;
      p1.y = v14 + v19;
      Render::DebugDrawContext::DrawLine(Context, &p0, &p1, &UFG::qColour::Green, &UFG::qMatrix44::msIdentity, 0i64, 0);
      x = p1.x;
      v14 = p1.y;
      v16 = p1.z;
      v10 = v10 + dt;
      p0 = p1;
    }
    while ( v10 < tFlight );
  }
}

// File Line: 185
// RVA: 0x30A820
char __fastcall TargetJumpTask::Update(TargetJumpTask *this, float timeDelta)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  UFG::CharacterAnimationComponent *v6; // rax
  Creature *mCreature; // r14
  int BoneID; // r15d
  UFG::SimComponent *v9; // rbx
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
  float y; // xmm1_4
  float z; // xmm0_4
  float w; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float x; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  ITrack *m_Track; // rax
  float v36; // xmm9_4
  __m128 y_low; // xmm6
  float v38; // xmm11_4
  float v39; // xmm7_4
  float v40; // xmm3_4
  __m128 v41; // xmm4
  float v42; // xmm5_4
  __m128 v43; // xmm10
  float v44; // xmm2_4
  float v45; // xmm1_4
  UFG::CharacterPhysicsComponent *v46; // rcx
  float v47; // xmm5_4
  float v48; // xmm1_4
  float v49; // xmm2_4
  float v50; // xmm9_4
  float v51; // xmm11_4
  UFG::SimComponent *v52; // rbx
  float v53; // xmm12_4
  __m128 vfptr_high; // xmm13
  float v55; // xmm8_4
  float v56; // xmm9_4
  float v57; // xmm12_4
  float v58; // xmm13_4
  float v59; // xmm14_4
  float v60; // xmm10_4
  float v61; // xmm8_4
  UFG::TransformNodeComponent *v62; // rcx
  float v63; // xmm1_4
  UFG::CharacterPhysicsComponent *v64; // rcx
  Render::DebugDrawContext *Context; // rax
  Render::DebugDrawContext *v66; // rbx
  __m128 x_low; // xmm1
  __m128 v68; // xmm2
  UFG::qVector3 pos; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qVector3 p0; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qVector3 result; // [rsp+70h] [rbp-90h] BYREF
  UFG::qVector3 velocity; // [rsp+80h] [rbp-80h] BYREF
  UFG::qMatrix44 xform; // [rsp+90h] [rbp-70h] BYREF
  UFG::qMatrix44 transform; // [rsp+D0h] [rbp-30h] BYREF
  UFG::qVector3 v76; // [rsp+110h] [rbp+10h] BYREF
  UFG::qVector3 p1; // [rsp+120h] [rbp+20h] BYREF

  if ( this->m_pCharacterPhysicsComponent.m_pPointer )
  {
    if ( this->m_pTransformNodeComponent.m_pPointer )
    {
      m_pPointer = (UFG::SimObjectCVBase *)this->m_pTargetSimObject.m_pPointer;
      if ( m_pPointer )
      {
        m_Flags = m_pPointer->m_Flags;
        m_pTransformNodeComponent = m_pPointer->m_pTransformNodeComponent;
        if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
        {
          v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
        }
        else if ( (m_Flags & 0x2000) != 0 )
        {
          v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
        }
        else
        {
          v6 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                                  ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      m_pPointer,
                                                      UFG::CharacterAnimationComponent::_TypeUID)
                                                  : UFG::SimObject::GetComponentOfType(
                                                      m_pPointer,
                                                      UFG::CharacterAnimationComponent::_TypeUID));
        }
        if ( m_pTransformNodeComponent )
        {
          if ( v6 )
          {
            mCreature = v6->mCreature;
            if ( mCreature )
            {
              if ( mCreature->mPose.mRigHandle.mData )
              {
                BoneID = Skeleton::GetBoneID(
                           mCreature->mPose.mRigHandle.mUFGSkeleton,
                           this->m_Track[1].m_TrackClassNameUID);
                if ( BoneID >= 0 )
                {
                  TargetJumpTask::getTargetsVelocity(this, &result, this->m_pTargetSimObject.m_pPointer);
                  v9 = this->m_pTransformNodeComponent.m_pPointer;
                  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v9);
                  v10 = *(float *)&v9[2].m_SafePointerList.mNode.mPrev;
                  v11 = *((float *)&v9[2].m_SafePointerList.mNode.mPrev + 1);
                  v12 = *(float *)&v9[2].vfptr;
                  xform.v0.y = *((float *)&v9[2].vfptr + 1);
                  xform.v0.z = v10;
                  xform.v0.x = v12;
                  xform.v0.w = v11;
                  v13 = *((float *)&v9[2].m_SafePointerList.mNode.mNext + 1);
                  v14 = *(float *)&v9[2].m_TypeUID;
                  v15 = *(float *)&v9[2].m_NameUID;
                  xform.v1.x = *(float *)&v9[2].m_SafePointerList.mNode.mNext;
                  xform.v1.y = v13;
                  xform.v1.z = v14;
                  xform.v1.w = v15;
                  v16 = *(float *)&v9[2].m_pSimObject;
                  v17 = *((float *)&v9[2].m_pSimObject + 1);
                  v18 = *(float *)&v9[2].m_Flags;
                  xform.v2.y = *(float *)(&v9[2].m_SimObjIndex + 1);
                  xform.v2.x = v18;
                  xform.v2.z = v16;
                  xform.v2.w = v17;
                  v19 = *(float *)&v9[2].m_BoundComponentHandles.mNode.mNext;
                  v20 = *((float *)&v9[2].m_BoundComponentHandles.mNode.mNext + 1);
                  v21 = *(float *)&v9[2].m_BoundComponentHandles.mNode.mPrev;
                  xform.v3.y = *((float *)&v9[2].m_BoundComponentHandles.mNode.mPrev + 1);
                  xform.v3.z = v19;
                  xform.v3.x = v21;
                  xform.v3.w = v20;
                  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                  y = m_pTransformNodeComponent->mWorldTransform.v0.y;
                  transform.v0.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
                  z = m_pTransformNodeComponent->mWorldTransform.v0.z;
                  transform.v0.y = y;
                  w = m_pTransformNodeComponent->mWorldTransform.v0.w;
                  transform.v0.z = z;
                  transform.v1.x = m_pTransformNodeComponent->mWorldTransform.v1.x;
                  v25 = m_pTransformNodeComponent->mWorldTransform.v1.z;
                  transform.v0.w = w;
                  v26 = m_pTransformNodeComponent->mWorldTransform.v1.y;
                  transform.v1.z = v25;
                  x = m_pTransformNodeComponent->mWorldTransform.v2.x;
                  transform.v1.y = v26;
                  v28 = m_pTransformNodeComponent->mWorldTransform.v1.w;
                  transform.v2.x = x;
                  v29 = m_pTransformNodeComponent->mWorldTransform.v2.z;
                  transform.v1.w = v28;
                  v30 = m_pTransformNodeComponent->mWorldTransform.v2.y;
                  transform.v2.z = v29;
                  v31 = m_pTransformNodeComponent->mWorldTransform.v3.x;
                  transform.v2.y = v30;
                  v32 = m_pTransformNodeComponent->mWorldTransform.v2.w;
                  transform.v3.x = v31;
                  v33 = m_pTransformNodeComponent->mWorldTransform.v3.z;
                  transform.v2.w = v32;
                  v34 = m_pTransformNodeComponent->mWorldTransform.v3.y;
                  transform.v3.z = v33;
                  transform.v3.y = v34;
                  transform.v3.w = m_pTransformNodeComponent->mWorldTransform.v3.w;
                  Creature::GetTransform(mCreature, BoneID, &transform);
                  m_Track = this->m_Track;
                  v36 = transform.v3.x;
                  y_low = (__m128)LODWORD(transform.v3.y);
                  v38 = transform.v3.z;
                  v39 = 0.0;
                  v41 = (__m128)LODWORD(transform.v3.y);
                  v40 = transform.v3.x - xform.v3.x;
                  v41.m128_f32[0] = transform.v3.y - xform.v3.y;
                  v43 = v41;
                  v42 = transform.v3.z - xform.v3.z;
                  p1.x = transform.v3.x;
                  v43.m128_f32[0] = (float)((float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v40 * v40))
                                  + (float)(v42 * v42);
                  p1.y = transform.v3.y;
                  p1.z = transform.v3.z;
                  v44 = *(float *)&m_Track[1].mResourceOwner;
                  if ( v43.m128_f32[0] == 0.0 )
                    v45 = 0.0;
                  else
                    v45 = 1.0 / _mm_sqrt_ps(v43).m128_f32[0];
                  v46 = (UFG::CharacterPhysicsComponent *)this->m_pCharacterPhysicsComponent.m_pPointer;
                  v47 = v42 * v45;
                  transform.v3.y = transform.v3.y - (float)(v44 * (float)(v41.m128_f32[0] * v45));
                  y_low.m128_f32[0] = transform.v3.y - xform.v3.y;
                  v48 = v44 * (float)(v40 * v45);
                  v49 = v44 * v47;
                  transform.v3.w = transform.v3.w + -1.0;
                  transform.v3.x = transform.v3.x - v48;
                  transform.v3.z = transform.v3.z - v49;
                  v50 = (float)(v36 - v48) - xform.v3.x;
                  v51 = (float)(v38 - v49) - xform.v3.z;
                  UFG::CharacterPhysicsComponent::GetVelocity(v46, &v76);
                  v52 = this->m_pTransformNodeComponent.m_pPointer;
                  UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v52);
                  v53 = *(float *)&v52[2].vfptr;
                  vfptr_high = (__m128)HIDWORD(v52[2].vfptr);
                  if ( (float)((float)(vfptr_high.m128_f32[0] * vfptr_high.m128_f32[0]) + (float)(v53 * v53)) == 0.0 )
                    v55 = 0.0;
                  else
                    v55 = 1.0 / _mm_sqrt_ps(vfptr_high).m128_f32[0];
                  y_low.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v50 * v50);
                  v56 = v76.z;
                  v57 = v53 * v55;
                  v58 = vfptr_high.m128_f32[0] * v55;
                  v59 = *((float *)&this->m_Track[1].vfptr + 1);
                  v60 = _mm_sqrt_ps(y_low).m128_f32[0] / v59;
                  v61 = v55 * 0.0;
                  if ( v76.z < 0.0 && v51 > 0.0 )
                  {
                    v62 = (UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer;
                    v56 = 0.0;
                    pos.x = xform.v3.x;
                    pos.y = xform.v3.y;
                    pos.z = transform.v3.z;
                    UFG::TransformNodeComponent::SetLocalTranslation(v62, &pos);
                    goto LABEL_31;
                  }
                  v63 = (float)((float)((float)(v76.z * v60) - v51) * -2.0) / (float)(v60 * v60);
                  if ( v63 <= -100.0 )
                  {
                    v63 = FLOAT_N100_0;
                  }
                  else if ( v63 >= 0.0 )
                  {
LABEL_31:
                    *(float *)&this->m_pCharacterPhysicsComponent.m_pPointer[9].m_SafePointerList.mNode.mPrev = v39;
                    v64 = (UFG::CharacterPhysicsComponent *)this->m_pCharacterPhysicsComponent.m_pPointer;
                    result.z = 0.0;
                    velocity.x = result.x + (float)((float)(v56 * UFG::qVector3::msAxisZ.x) + (float)(v57 * v59));
                    velocity.y = result.y + (float)((float)(v56 * UFG::qVector3::msAxisZ.y) + (float)(v58 * v59));
                    velocity.z = (float)(v56 * UFG::qVector3::msAxisZ.z) + (float)(v59 * v61);
                    UFG::CharacterPhysicsComponent::SetVelocity(v64, &velocity);
                    if ( sTargetJumpTaskDebug )
                    {
                      Context = (Render::DebugDrawContext *)Render::DebugDrawManager::GetContext(
                                                              Render::DebugDrawManager::mInstance,
                                                              1u);
                      pos.x = transform.v3.x;
                      pos.y = transform.v3.y;
                      pos.z = transform.v3.z;
                      v66 = Context;
                      Render::DebugDrawContext::DrawArrow(
                        Context,
                        &pos,
                        &p1,
                        &UFG::qColour::Green,
                        &UFG::qMatrix44::msIdentity,
                        0i64);
                      pos.z = xform.v3.z + v76.z;
                      pos.x = v76.x + xform.v3.x;
                      pos.y = v76.y + xform.v3.y;
                      p0.x = xform.v3.x;
                      p0.y = xform.v3.y;
                      p0.z = xform.v3.z;
                      Render::DebugDrawContext::DrawArrow(
                        v66,
                        &p0,
                        &pos,
                        &UFG::qColour::Green,
                        &UFG::qMatrix44::msIdentity,
                        0i64);
                      p0.x = xform.v3.x;
                      p0.y = xform.v3.y;
                      x_low = (__m128)LODWORD(result.x);
                      p0.z = xform.v3.z + 1.4;
                      v68 = (__m128)LODWORD(velocity.y);
                      x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(result.y * result.y);
                      v68.m128_f32[0] = (float)(v68.m128_f32[0] * v68.m128_f32[0]) + (float)(velocity.x * velocity.x);
                      Render::DebugDrawContext::DrawText(
                        v66,
                        &p0,
                        &UFG::qColour::Green,
                        "Vxy:%f.3\n VxyCar:%f.3\nVZ:%f.3\nVZa:%f.3\nVZcar:%f.3\n",
                        _mm_sqrt_ps(v68).m128_f32[0],
                        _mm_sqrt_ps(x_low).m128_f32[0],
                        v56,
                        velocity.z,
                        result.z);
                      p0.x = transform.v3.x;
                      p0.y = transform.v3.y;
                      p0.z = transform.v3.z;
                      pos.x = xform.v3.x;
                      pos.y = xform.v3.y;
                      pos.z = xform.v3.z;
                      Render::DebugDrawContext::DrawLine(
                        v66,
                        &pos,
                        &p0,
                        &UFG::qColour::Red,
                        &UFG::qMatrix44::msIdentity,
                        0i64,
                        0);
                      Render::DebugDrawContext::DrawAxes(v66, &xform, 0.5, 0, 0i64);
                      Render::DebugDrawContext::DrawAxes(v66, &transform, 0.5, 0, 0i64);
                      pos.y = xform.v3.y;
                      pos.x = xform.v3.x;
                      p0.x = v57;
                      p0.y = v58;
                      p0.z = v61;
                      pos.z = xform.v3.z;
                      debugDrawTrajectory(v60, v39, &pos, &p0, v59, v56, 0.033333335);
                    }
                    return 1;
                  }
                  v39 = v63;
                  goto LABEL_31;
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
UFG::qVector3 *__fastcall TargetJumpTask::getTargetsVelocity(
        TargetJumpTask *this,
        UFG::qVector3 *result,
        UFG::SimObjectVehicle *simObject)
{
  signed __int16 m_Flags; // cx
  UFG::BoatPhysicsMoverComponent *ComponentOfTypeHK; // rax
  UFG::qVector3 *v7; // rax
  signed __int16 v8; // cx
  signed __int16 v9; // cx
  float y; // xmm1_4
  float z; // xmm2_4

  if ( simObject
    && ((m_Flags = simObject->m_Flags, (m_Flags & 0x4000) == 0)
     && (m_Flags >= 0
       ? ((m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
        ? (ComponentOfTypeHK = (UFG::BoatPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   simObject,
                                                                   UFG::CarPhysicsMoverComponent::_TypeUID))
        : (ComponentOfTypeHK = (UFG::BoatPhysicsMoverComponent *)UFG::SimObject::GetComponentOfType(
                                                                   simObject,
                                                                   UFG::CarPhysicsMoverComponent::_TypeUID)))
       : (ComponentOfTypeHK = (UFG::BoatPhysicsMoverComponent *)UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>(simObject)),
         ComponentOfTypeHK)
     || (v8 = simObject->m_Flags, (v8 & 0x4000) == 0)
     && (v8 >= 0
       ? ((v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
        ? (ComponentOfTypeHK = (UFG::BoatPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   simObject,
                                                                   UFG::BikePhysicsMoverComponent::_TypeUID))
        : (ComponentOfTypeHK = (UFG::BoatPhysicsMoverComponent *)UFG::SimObject::GetComponentOfType(
                                                                   simObject,
                                                                   UFG::BikePhysicsMoverComponent::_TypeUID)))
       : (ComponentOfTypeHK = (UFG::BoatPhysicsMoverComponent *)UFG::SimObjectVehicle::GetComponent<UFG::BikePhysicsMoverComponent>(simObject)),
         ComponentOfTypeHK)
     || (v9 = simObject->m_Flags, (v9 & 0x4000) == 0)
     && (v9 >= 0
       ? ((v9 & 0x2000) != 0 || (v9 & 0x1000) != 0
        ? (ComponentOfTypeHK = (UFG::BoatPhysicsMoverComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   simObject,
                                                                   UFG::BoatPhysicsMoverComponent::_TypeUID))
        : (ComponentOfTypeHK = (UFG::BoatPhysicsMoverComponent *)UFG::SimObject::GetComponentOfType(
                                                                   simObject,
                                                                   UFG::BoatPhysicsMoverComponent::_TypeUID)))
       : (ComponentOfTypeHK = UFG::SimObjectVehicle::GetComponent<UFG::BoatPhysicsMoverComponent>(simObject)),
         ComponentOfTypeHK)) )
  {
    UFG::PhysicsMoverInterface::GetVelocity(ComponentOfTypeHK, result);
    return result;
  }
  else
  {
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    v7 = result;
    result->x = UFG::qVector3::msZero.x;
    result->y = y;
    result->z = z;
  }
  return v7;
}

// File Line: 341
// RVA: 0x2E1D20
void __fastcall TargetPlayEffectTask::TargetPlayEffectTask(TargetPlayEffectTask *this)
{
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<TargetPlayEffectTrack>::`vftable;
  FX::HardwareOcclusionQuery::HardwareOcclusionQuery((FX::HardwareOcclusionQuery *)&this->PlayEffectBaseTask);
  this->vfptr = (ITaskVtbl *)&TargetPlayEffectTask::`vftable;
  this->m_pTSBC.mPrev = &this->m_pTSBC;
  this->m_pTSBC.mNext = &this->m_pTSBC;
  this->m_pTSBC.m_pPointer = 0i64;
  this->m_pTargetSimObject.mPrev = &this->m_pTargetSimObject;
  this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
  this->m_pTargetSimObject.m_pPointer = 0i64;
}

// File Line: 346
// RVA: 0x2E5790
void __fastcall TargetPlayEffectTask::~TargetPlayEffectTask(TargetPlayEffectTask *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTSBC; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<ITask,ITask> *v12; // rcx
  UFG::qNode<ITask,ITask> *v13; // rax

  this->vfptr = (ITaskVtbl *)&TargetPlayEffectTask::`vftable;
  p_m_pTargetSimObject = &this->m_pTargetSimObject;
  if ( this->m_pTargetSimObject.m_pPointer )
  {
    mPrev = p_m_pTargetSimObject->mPrev;
    mNext = p_m_pTargetSimObject->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
    p_m_pTargetSimObject->mNext = p_m_pTargetSimObject;
  }
  p_m_pTargetSimObject->m_pPointer = 0i64;
  v5 = p_m_pTargetSimObject->mPrev;
  v6 = p_m_pTargetSimObject->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
  p_m_pTargetSimObject->mNext = p_m_pTargetSimObject;
  p_m_pTSBC = &this->m_pTSBC;
  if ( this->m_pTSBC.m_pPointer )
  {
    v8 = p_m_pTSBC->mPrev;
    v9 = this->m_pTSBC.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_m_pTSBC->mPrev = p_m_pTSBC;
    this->m_pTSBC.mNext = &this->m_pTSBC;
  }
  this->m_pTSBC.m_pPointer = 0i64;
  v10 = p_m_pTSBC->mPrev;
  v11 = this->m_pTSBC.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_m_pTSBC->mPrev = p_m_pTSBC;
  this->m_pTSBC.mNext = &this->m_pTSBC;
  _((AMD_HD3D *)&this->PlayEffectBaseTask);
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v12 = this->mPrev;
  v13 = this->mNext;
  v12->mNext = v13;
  v13->mPrev = v12;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 351
// RVA: 0x2F8180
void __fastcall TargetPlayEffectTask::Begin(TargetPlayEffectTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  PlayEffectBaseTrack *v4; // rsi
  UFG::SimComponent *m_pComponent; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemBaseComponent> *p_m_pTSBC; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::SimComponent *v12; // r9
  ITrack *m_Track; // r8
  UFG::SimObject *pSimObject; // rdi
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v17; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v18; // rax

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  v4 = 0i64;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  p_m_pTSBC = &this->m_pTSBC;
  if ( this->m_pTSBC.m_pPointer )
  {
    mPrev = p_m_pTSBC->mPrev;
    mNext = this->m_pTSBC.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTSBC->mPrev = p_m_pTSBC;
    this->m_pTSBC.mNext = &this->m_pTSBC;
  }
  this->m_pTSBC.m_pPointer = m_pComponent;
  if ( m_pComponent )
  {
    v11 = m_pComponent->m_SafePointerList.mNode.mPrev;
    v11->mNext = p_m_pTSBC;
    p_m_pTSBC->mPrev = v11;
    this->m_pTSBC.mNext = &m_pComponent->m_SafePointerList.mNode;
    m_pComponent->m_SafePointerList.mNode.mPrev = p_m_pTSBC;
  }
  v12 = this->m_pTSBC.m_pPointer;
  if ( v12 )
  {
    m_Track = this->m_Track;
    pSimObject = *(UFG::SimObject **)(56i64
                                    * *(unsigned __int8 *)(LODWORD(m_Track[2].mTimeBegin)
                                                         + *(_QWORD *)&v12[1].m_Flags
                                                         + 8i64)
                                    + *(_QWORD *)&v12[1].m_TypeUID
                                    + 40);
    if ( pSimObject )
    {
      if ( m_Track )
        v4 = (PlayEffectBaseTrack *)&m_Track[1];
      PlayEffectBaseTask::playEffectBegin(
        &this->PlayEffectBaseTask,
        this->mContext,
        v4,
        m_Track->mTimeBegin,
        m_Track->mTimeEnd,
        pSimObject);
      p_m_pTargetSimObject = &this->m_pTargetSimObject;
      if ( this->m_pTargetSimObject.m_pPointer )
      {
        v16 = p_m_pTargetSimObject->mPrev;
        v17 = this->m_pTargetSimObject.mNext;
        v16->mNext = v17;
        v17->mPrev = v16;
        p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
        this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
      }
      this->m_pTargetSimObject.m_pPointer = pSimObject;
      v18 = pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v18->mNext = p_m_pTargetSimObject;
      p_m_pTargetSimObject->mPrev = v18;
      this->m_pTargetSimObject.mNext = &pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      pSimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pTargetSimObject;
    }
  }
}

// File Line: 370
// RVA: 0x30B0F0
char __fastcall TargetPlayEffectTask::Update(TargetPlayEffectTask *this, float timeDelta)
{
  UFG::SimComponent *m_pPointer; // rcx
  int v4; // esi
  UFG::SimObject *v5; // rdi
  UFG::SimObject *pSimObject; // rax
  ITrack *m_Track; // rcx
  PlayEffectBaseTrack *v8; // r8
  ITrack *v9; // rax
  PlayEffectBaseTrack *v10; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_m_pTargetSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  ITrack *v15; // rax

  m_pPointer = this->m_pTSBC.m_pPointer;
  v4 = 0;
  if ( m_pPointer )
    v5 = *(UFG::SimObject **)(56i64
                            * *(unsigned __int8 *)(LODWORD(this->m_Track[2].mTimeBegin)
                                                 + *(_QWORD *)&m_pPointer[1].m_Flags
                                                 + 8i64)
                            + *(_QWORD *)&m_pPointer[1].m_TypeUID
                            + 40);
  else
    v5 = 0i64;
  pSimObject = this->m_pTargetSimObject.m_pPointer;
  if ( pSimObject && v5 != pSimObject )
  {
    m_Track = this->m_Track;
    v8 = (PlayEffectBaseTrack *)&m_Track[1];
    if ( !m_Track )
      v8 = 0i64;
    PlayEffectBaseTask::playEffectEnd(
      &this->PlayEffectBaseTask,
      this->mContext,
      v8,
      m_Track->mTimeBegin,
      m_Track->mTimeEnd,
      pSimObject);
    if ( v5 )
    {
      v9 = this->m_Track;
      v10 = (PlayEffectBaseTrack *)&v9[1];
      if ( !v9 )
        v10 = 0i64;
      PlayEffectBaseTask::playEffectBegin(
        &this->PlayEffectBaseTask,
        this->mContext,
        v10,
        v9->mTimeBegin,
        v9->mTimeEnd,
        v5);
    }
    p_m_pTargetSimObject = &this->m_pTargetSimObject;
    if ( this->m_pTargetSimObject.m_pPointer )
    {
      mPrev = p_m_pTargetSimObject->mPrev;
      mNext = this->m_pTargetSimObject.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_pTargetSimObject->mPrev = p_m_pTargetSimObject;
      this->m_pTargetSimObject.mNext = &this->m_pTargetSimObject;
    }
    this->m_pTargetSimObject.m_pPointer = v5;
    if ( v5 )
    {
      v14 = v5->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
      v14->mNext = p_m_pTargetSimObject;
      p_m_pTargetSimObject->mPrev = v14;
      this->m_pTargetSimObject.mNext = &v5->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
      v5->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_m_pTargetSimObject;
    }
  }
  v15 = this->m_Track;
  if ( v15 )
    v4 = (_DWORD)v15 + 56;
  Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse(
    (hkGeometryUtils::IVertices *)&this->PlayEffectBaseTask,
    (int)this->mContext,
    v4);
  return 1;
}

// File Line: 394
// RVA: 0x301010
void __fastcall TargetPlayEffectTask::End(TargetPlayEffectTask *this)
{
  ITrack *m_Track; // rdx
  PlayEffectBaseTrack *v2; // r8

  m_Track = this->m_Track;
  if ( m_Track )
    v2 = (PlayEffectBaseTrack *)&m_Track[1];
  else
    v2 = 0i64;
  PlayEffectBaseTask::playEffectEnd(
    &this->PlayEffectBaseTask,
    this->mContext,
    v2,
    m_Track->mTimeBegin,
    m_Track->mTimeEnd,
    this->m_pTargetSimObject.m_pPointer);
}

// File Line: 402
// RVA: 0x2F5F30
void __fastcall TargetDamageTask::Begin(TargetDamageTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rbx
  __int16 v9; // cx
  UFG::HealthComponent *v10; // rbp
  UFG::SimComponent *v11; // rax
  __int16 v12; // cx
  UFG::SimComponent *v13; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v15; // rsi
  UFG::HitRecord *p_mNext; // r14
  float mDamageMultiplier; // xmm6_4
  __int16 v18; // cx
  UFG::SimComponent *v19; // rcx
  UFG::SimComponent *v20; // rax
  __int64 v21; // rax
  UFG::SimObjectProp *v22; // rcx
  __int16 v23; // dx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax
  int v25; // eax
  bool v26; // si
  UFG::CopSystem *v27; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( (m_pPointer->m_Flags & 0x400) == 0 && m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v7;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v8 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LODWORD(this->m_Track[1].mMasterRate.text.mOffset)
                                                       + *(_QWORD *)&m_pComponent[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 & 0x4000) != 0 )
        {
          v10 = (UFG::HealthComponent *)v8->m_Components.p[6].m_pComponent;
        }
        else if ( v9 >= 0 )
        {
          v11 = (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HealthComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v8, UFG::HealthComponent::_TypeUID);
          v10 = (UFG::HealthComponent *)v11;
        }
        else
        {
          v10 = (UFG::HealthComponent *)v8->m_Components.p[6].m_pComponent;
        }
        if ( v10 )
        {
          v12 = v8->m_Flags;
          if ( (v12 & 0x4000) != 0 )
          {
            v13 = v8->m_Components.p[15].m_pComponent;
          }
          else if ( v12 >= 0 )
          {
            if ( (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HitReactionComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, UFG::HitReactionComponent::_TypeUID);
            v13 = ComponentOfTypeHK;
          }
          else
          {
            v13 = v8->m_Components.p[15].m_pComponent;
          }
          if ( v13 )
          {
            v15 = *(UFG::SimObjectGame **)&v13[3].m_TypeUID;
            p_mNext = (UFG::HitRecord *)&v13[2].m_BoundComponentHandles.mNode.mNext;
          }
          else
          {
            p_mNext = 0i64;
            v15 = 0i64;
          }
          mDamageMultiplier = *(float *)&FLOAT_1_0;
          if ( !v15 )
            goto LABEL_59;
          v18 = v15->m_Flags;
          if ( (v18 & 0x4000) != 0 )
          {
            v19 = v15->m_Components.p[20].m_pComponent;
          }
          else if ( v18 >= 0 )
          {
            v20 = (v18 & 0x2000) != 0 || (v18 & 0x1000) != 0
                ? UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::TargetingSystemBaseComponent::_TypeUID)
                : UFG::SimObject::GetComponentOfType(v15, UFG::TargetingSystemBaseComponent::_TypeUID);
            v19 = v20;
          }
          else
          {
            v19 = v15->m_Components.p[20].m_pComponent;
          }
          if ( !v19 )
            goto LABEL_59;
          v21 = ((__int64 (__fastcall *)(UFG::SimComponent *))v19->vfptr[15].__vecDelDtor)(v19);
          if ( !v21 )
            goto LABEL_59;
          v22 = *(UFG::SimObjectProp **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)(v21 + 96) + 25i64)
                                       + *(_QWORD *)(v21 + 88)
                                       + 40);
          if ( !v22 )
            goto LABEL_59;
          v23 = v22->m_Flags;
          if ( (v23 & 0x4000) != 0 || v23 < 0 )
            goto LABEL_55;
          if ( (v23 & 0x2000) != 0 )
          {
            ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v22);
            goto LABEL_57;
          }
          if ( (v23 & 0x1000) != 0 )
LABEL_55:
            ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           v22,
                                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
          else
            ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                           v22,
                                                                           UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
LABEL_57:
          if ( ComponentOfType )
            mDamageMultiplier = ComponentOfType->mWeaponTypeInfo->mFireModes[ComponentOfType->mFireMode]->mDamageMultiplier;
LABEL_59:
          v25 = ExpressionParameterInt::operator long((ExpressionParameterInt *)&this->m_Track[1]);
          v26 = UFG::HealthComponent::ApplyHealthDamage(
                  v10,
                  (int)(float)((float)v25 * mDamageMultiplier),
                  v15,
                  p_mNext,
                  0);
          if ( v26 )
          {
            if ( v13 )
            {
              v27 = UFG::CopSystem::Instance();
              ((void (__fastcall *)(UFG::CopSystem *, UFG::SimObject *, UFG::SimObjectGame *, UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **, UFG::HealthComponent *, bool))v27->vfptr[95].__vecDelDtor)(
                v27,
                context->mSimObject.m_pPointer,
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
  ITrack *m_Track; // rcx
  ActionNodePlayable *v5; // rsi
  Expression::IMemberMapVtbl *vfptr; // rax
  __int64 v7; // rax
  __int64 v8; // rdx
  UFG::eTargetTypeEnum mResourceOwner; // r14d
  UFG::SimObject *Target; // rax
  __int64 v11; // r9
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mTarget; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v21; // rcx
  __int16 v22; // dx
  UFG::PowerManagementComponent *ComponentOfType; // rax
  UFG::SimObjectGame *v24; // rcx
  UEL::ParametersBase *v25; // rbp
  __int16 v26; // dx
  UEL::ParametersBase *v27; // rax
  ITrack *v28; // rax
  ActionController *v29; // rdi
  Expression::IMemberMapVtbl *v30; // rcx
  char *v31; // rcx
  __int64 v32; // rdx
  char *v33; // rcx
  __int64 v34; // rax
  ITrack *v35; // rdx
  UFG::SimObjectGame *v36; // rcx
  __int16 v37; // dx
  UFG::SimComponent *v38; // rcx
  UFG::SimComponent *v39; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v40; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v41; // rax

  this->mContext = context;
  if ( (context->mSimObject.m_pPointer->m_Flags & 0x400) == 0 )
  {
    m_Track = this->m_Track;
    v5 = 0i64;
    vfptr = m_Track[1].vfptr;
    v7 = vfptr ? (__int64)&vfptr->ResolveReferences + (_QWORD)m_Track : 0i64;
    v8 = *(_QWORD *)(v7 + 72);
    if ( v8 )
    {
      if ( v8 + v7 + 72 )
      {
        mResourceOwner = (UFG::eTargetTypeEnum)m_Track[2].mResourceOwner;
        Target = UFG::getTarget(context, mResourceOwner);
        p_mTarget = &this->mTarget;
        if ( this->mTarget.m_pPointer )
        {
          mPrev = p_mTarget->mPrev;
          mNext = this->mTarget.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_mTarget->mPrev = p_mTarget;
          this->mTarget.mNext = &this->mTarget;
        }
        this->mTarget.m_pPointer = Target;
        if ( Target )
        {
          p_mNode = &Target->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
          v16 = Target->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
          v16->mNext = p_mTarget;
          p_mTarget->mPrev = v16;
          this->mTarget.mNext = p_mNode;
          p_mNode->mPrev = p_mTarget;
        }
        m_pPointer = (UFG::SimObjectGame *)this->mTarget.m_pPointer;
        if ( m_pPointer )
        {
          if ( m_pPointer == this->mContext->mSimObject.m_pPointer )
          {
            if ( this->mTarget.m_pPointer )
            {
              v40 = p_mTarget->mPrev;
              v41 = this->mTarget.mNext;
              v40->mNext = v41;
              v41->mPrev = v40;
              p_mTarget->mPrev = p_mTarget;
              this->mTarget.mNext = &this->mTarget;
            }
            this->mTarget.m_pPointer = 0i64;
          }
          else
          {
            m_Flags = m_pPointer->m_Flags;
            if ( (m_Flags & 0x4000) != 0 )
            {
              m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
            }
            else if ( m_Flags >= 0 )
            {
              if ( (m_Flags & 0x2000) != 0 )
              {
                m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
              }
              else
              {
                if ( (m_Flags & 0x1000) != 0 )
                  ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                        m_pPointer,
                                        UFG::ActionTreeComponent::_TypeUID);
                else
                  ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
                m_pComponent = ComponentOfTypeHK;
              }
            }
            else
            {
              m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
            }
            if ( m_pComponent )
            {
              v21 = (UFG::SimObjectGame *)this->mTarget.m_pPointer;
              if ( v21 )
              {
                v22 = v21->m_Flags;
                if ( (v22 & 0x4000) != 0 || v22 < 0 || (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0 )
                  ComponentOfType = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v21,
                                                                       UFG::PowerManagementComponent::_TypeUID);
                else
                  ComponentOfType = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v21,
                                                                       UFG::PowerManagementComponent::_TypeUID);
                if ( ComponentOfType )
                  UFG::PowerManagementComponent::PreventSuspendTemporarily(ComponentOfType, 10.0);
              }
              v24 = (UFG::SimObjectGame *)this->mTarget.m_pPointer;
              v25 = UEL::gCurrentParameters;
              if ( v24 )
              {
                v26 = v24->m_Flags;
                if ( (v26 & 0x4000) != 0 )
                {
                  v27 = (UEL::ParametersBase *)v24->m_Components.p->m_pComponent;
                }
                else if ( v26 >= 0 )
                {
                  if ( (v26 & 0x2000) != 0 )
                    v27 = (UEL::ParametersBase *)v24->m_Components.p->m_pComponent;
                  else
                    v27 = (UEL::ParametersBase *)((v26 & 0x1000) != 0
                                                ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v24,
                                                    UFG::UELComponent::_TypeUID)
                                                : UFG::SimObject::GetComponentOfType(v24, UFG::UELComponent::_TypeUID));
                }
                else
                {
                  v27 = (UEL::ParametersBase *)v24->m_Components.p->m_pComponent;
                }
                if ( v27 )
                  UEL::gCurrentParameters = v27 + 88;
              }
              v28 = this->m_Track;
              v29 = (ActionController *)&m_pComponent[3];
              v30 = v28[1].vfptr;
              if ( BYTE4(v28[2].mResourceOwner) )
              {
                if ( v30 )
                  v31 = (char *)&v30->ResolveReferences + (_QWORD)v28;
                else
                  v31 = 0i64;
                v32 = *((_QWORD *)v31 + 9);
                if ( v32 )
                  v5 = (ActionNodePlayable *)&v31[v32 + 72];
                ActionController::PlayTracks(
                  v29,
                  v5,
                  LOBYTE(v28[2].m_TrackClassNameUID) != 0,
                  v29->m_ActionNodePlayTime);
              }
              else
              {
                if ( v30 )
                  v33 = (char *)&v30->ResolveReferences + (_QWORD)v28;
                else
                  v33 = 0i64;
                v34 = *((_QWORD *)v33 + 9);
                if ( v34 )
                  v5 = (ActionNodePlayable *)&v33[v34 + 72];
                ActionController::Play(v29, v5, 0);
                v35 = this->m_Track;
                if ( BYTE5(v35[2].mResourceOwner) )
                  ActionController::PlayTracks(v29, (ITrack *)((char *)v35 + 64), 0, 0.0);
              }
              ActionController::updateTasksTimeBegin(v29, 0.0, 0);
              UEL::gCurrentParameters = v25;
            }
            if ( BYTE6(this->m_Track[2].mResourceOwner) )
            {
              v36 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
              if ( v36 )
              {
                v37 = v36->m_Flags;
                if ( (v37 & 0x4000) != 0 )
                {
                  v38 = v36->m_Components.p[20].m_pComponent;
                }
                else if ( v37 >= 0 )
                {
                  if ( (v37 & 0x2000) != 0 || (v37 & 0x1000) != 0 )
                    v39 = UFG::SimObjectGame::GetComponentOfTypeHK(v36, UFG::TargetingSystemBaseComponent::_TypeUID);
                  else
                    v39 = UFG::SimObject::GetComponentOfType(v36, UFG::TargetingSystemBaseComponent::_TypeUID);
                  v38 = v39;
                }
                else
                {
                  v38 = v36->m_Components.p[20].m_pComponent;
                }
                if ( v38 )
                {
                  LOBYTE(p_mTarget) = 1;
                  LOBYTE(v11) = HIBYTE(this->m_Track[2].mResourceOwner) != 0;
                  ((void (__fastcall *)(UFG::SimComponent *, _QWORD, UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *, __int64, _DWORD, char *, ActionContext *, ITrack *))v38->vfptr[14].__vecDelDtor)(
                    v38,
                    (unsigned int)mResourceOwner,
                    p_mTarget,
                    v11,
                    0,
                    &customCaption,
                    this->mContext,
                    this->m_Track);
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
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  ActionNodePlayable **v5; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mTarget.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[6].m_pComponent;
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
      }
      else
      {
        m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::ActionTreeComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[7].m_pComponent;
    }
    if ( m_pComponent )
    {
      v5 = ActionController::IsPlaying((ActionController *)&m_pComponent[3], (ITrack *)((char *)this->m_Track + 64));
      if ( v5 )
        *((_BYTE *)v5 + 40) = 0;
    }
  }
}

// File Line: 612
// RVA: 0x2F8050
void __fastcall TargetPlayAITask::Begin(TargetPlayAITask *this, ActionContext *context)
{
  ITrack *m_Track; // rdx
  ActionNodePlayable *v4; // rbx
  Expression::IMemberMapVtbl *vfptr; // rax
  char *v7; // rax
  __int64 v8; // rcx
  UFG::SimObjectGame *Target; // rax
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  ITrack *v12; // rcx
  Expression::IMemberMapVtbl *v13; // rdx
  ITrack *v14; // rcx
  char *v15; // rdx
  __int64 v16; // rcx

  m_Track = this->m_Track;
  v4 = 0i64;
  vfptr = m_Track[1].vfptr;
  if ( vfptr )
    v7 = (char *)&vfptr->ResolveReferences + (_QWORD)m_Track;
  else
    v7 = 0i64;
  v8 = *((_QWORD *)v7 + 9);
  if ( v8 )
  {
    if ( &v7[v8 + 72] )
    {
      Target = (UFG::SimObjectGame *)UFG::getTarget(context, (UFG::eTargetTypeEnum)LODWORD(m_Track[1].mResourceOwner));
      if ( Target )
      {
        if ( Target != context->mSimObject.m_pPointer )
        {
          m_Flags = Target->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = Target->m_Components.p[19].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
              m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(Target, UFG::AIActionTreeComponent::_TypeUID);
            else
              m_pComponent = UFG::SimObject::GetComponentOfType(Target, UFG::AIActionTreeComponent::_TypeUID);
          }
          else
          {
            m_pComponent = Target->m_Components.p[19].m_pComponent;
          }
          v12 = this->m_Track;
          v13 = v12[1].vfptr;
          v14 = v12 + 1;
          if ( v13 )
            v15 = (char *)v13 + (_QWORD)v14;
          else
            v15 = 0i64;
          v16 = *((_QWORD *)v15 + 9);
          if ( v16 )
            v4 = (ActionNodePlayable *)&v15[v16 + 72];
          ActionController::Play((ActionController *)&m_pComponent[3].m_TypeUID, v4, 0);
        }
      }
    }
  }
}

// File Line: 635
// RVA: 0x2F8B70
void __fastcall TargetSpawnTask::Begin(TargetSpawnTask *this, ActionContext *context)
{
  ITrack *m_Track; // rsi
  Expression::IMemberMap *mResourceOwner; // rax
  ITrack *v6; // rsi
  Expression::IMemberMap *v7; // rcx
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v12; // rbx
  __int16 v13; // cx
  UFG::SimComponent *v14; // rdi
  UFG::SimComponent *v15; // rax
  __int16 v16; // cx
  UFG::PowerManagementComponent *ComponentOfType; // rax

  m_Track = this->m_Track;
  mResourceOwner = m_Track[2].mResourceOwner;
  v6 = (ITrack *)((char *)m_Track + 64);
  if ( mResourceOwner )
    mResourceOwner = (Expression::IMemberMap *)((char *)mResourceOwner + (_QWORD)v6 + 56);
  v7 = mResourceOwner[4].mResourceOwner;
  if ( v7 )
  {
    if ( (Expression::IMemberMap **)((char *)&mResourceOwner[4].mResourceOwner + (_QWORD)v7) )
    {
      m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
      if ( m_pPointer )
      {
        m_Flags = m_pPointer->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pPointer,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                  m_pPointer,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          m_pComponent = ComponentOfTypeHK;
        }
        else
        {
          m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
        }
        if ( m_pComponent )
        {
          v12 = *(UFG::SimObjectGame **)(56i64
                                       * *(unsigned __int8 *)(LODWORD(this->m_Track[1].vfptr)
                                                            + *(_QWORD *)&m_pComponent[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                       + 40);
          if ( v12 )
          {
            if ( v12 != context->mSimObject.m_pPointer )
            {
              v13 = v12->m_Flags;
              if ( (v13 & 0x4000) != 0 )
              {
                v14 = v12->m_Components.p[7].m_pComponent;
              }
              else if ( v13 >= 0 )
              {
                if ( (v13 & 0x2000) != 0 )
                {
                  v14 = v12->m_Components.p[6].m_pComponent;
                }
                else
                {
                  v15 = (v13 & 0x1000) != 0
                      ? UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID)
                      : UFG::SimObject::GetComponentOfType(v12, UFG::ActionTreeComponent::_TypeUID);
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
                if ( (v16 & 0x4000) != 0 || v16 < 0 || (v16 & 0x2000) != 0 || (v16 & 0x1000) != 0 )
                  ComponentOfType = (UFG::PowerManagementComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v12,
                                                                       UFG::PowerManagementComponent::_TypeUID);
                else
                  ComponentOfType = (UFG::PowerManagementComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v12,
                                                                       UFG::PowerManagementComponent::_TypeUID);
                if ( ComponentOfType )
                  UFG::PowerManagementComponent::PreventSuspendTemporarily(ComponentOfType, 10.0);
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
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  __int16 v10; // dx
  UFG::SimComponent *v11; // rsi
  UFG::SimComponent *v12; // rax
  unsigned __int8 v13; // cl
  __int64 v14; // rbx
  __int64 v15; // r9
  unsigned __int8 v16; // cl
  __int64 v17; // rbx
  UFG::SimObjectGame *v18; // rcx
  __int16 v19; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimComponent *v21; // rdx
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v8 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v8;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v9 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 31i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v9 )
      {
        v10 = v9->m_Flags;
        if ( (v10 & 0x4000) != 0 )
        {
          v11 = v9->m_Components.p[20].m_pComponent;
        }
        else if ( v10 >= 0 )
        {
          v12 = (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::TargetingSystemBaseComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
          v11 = v12;
        }
        else
        {
          v11 = v9->m_Components.p[20].m_pComponent;
        }
        if ( v11 )
        {
          LOBYTE(a4) = 1;
          ((void (__fastcall *)(UFG::SimComponent *, __int64, _QWORD, __int64, _DWORD, char *, ActionContext *, ITrack *))v11->vfptr[14].__vecDelDtor)(
            v11,
            23i64,
            0i64,
            a4,
            0,
            &customCaption,
            this->mContext,
            this->m_Track);
          v13 = *(_BYTE *)(*(_QWORD *)&v11[1].m_Flags + 31i64);
          if ( v13 )
          {
            v14 = 56i64 * v13;
            UFG::TargetingSimObject::SetTarget((UFG::TargetingSimObject *)(v14 + *(_QWORD *)&v11[1].m_TypeUID), 0i64);
            UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v14 + *(_QWORD *)&v11[1].m_TypeUID), 0);
          }
        }
      }
      LOBYTE(a4) = 1;
      ((void (__fastcall *)(UFG::SimComponent *, __int64, _QWORD, __int64, _DWORD, char *, ActionContext *, ITrack *))m_pComponent->vfptr[14].__vecDelDtor)(
        m_pComponent,
        23i64,
        0i64,
        a4,
        0,
        &customCaption,
        this->mContext,
        this->m_Track);
      v16 = *(_BYTE *)(*(_QWORD *)&m_pComponent[1].m_Flags + 31i64);
      if ( v16 )
      {
        v17 = 56i64 * v16;
        UFG::TargetingSimObject::SetTarget(
          (UFG::TargetingSimObject *)(v17 + *(_QWORD *)&m_pComponent[1].m_TypeUID),
          0i64);
        UFG::TargetingSimObject::SetLock((UFG::TargetingSimObject *)(v17 + *(_QWORD *)&m_pComponent[1].m_TypeUID), 0);
      }
      v18 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 48i64)
                                   + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                   + 40);
      if ( !v18 )
        goto LABEL_42;
      v19 = v18->m_Flags;
      if ( (v19 & 0x4000) != 0 )
        goto LABEL_29;
      if ( v19 >= 0 )
      {
        if ( (v19 & 0x2000) == 0 )
        {
          if ( (v19 & 0x1000) == 0 )
          {
            ComponentOfType = UFG::SimObject::GetComponentOfType(v18, UFG::PropInteractComponent::_TypeUID);
            goto LABEL_36;
          }
LABEL_29:
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v18, UFG::PropInteractComponent::_TypeUID);
LABEL_36:
          v21 = ComponentOfType;
          goto LABEL_37;
        }
        v21 = v18->m_Components.p[13].m_pComponent;
      }
      else
      {
        v21 = v18->m_Components.p[33].m_pComponent;
      }
LABEL_37:
      if ( v21 && this->mContext->mSimObject.m_pPointer == *(UFG::SimObject **)&v21[2].m_TypeUID )
      {
        p_m_SafePointerList = &v21[2].m_SafePointerList;
        if ( p_m_SafePointerList[1].mNode.mPrev )
        {
          mPrev = p_m_SafePointerList->mNode.mPrev;
          mNext = p_m_SafePointerList->mNode.mNext;
          mPrev->mNext = mNext;
          mNext->mPrev = mPrev;
          p_m_SafePointerList->mNode.mPrev = &p_m_SafePointerList->mNode;
          p_m_SafePointerList->mNode.mNext = &p_m_SafePointerList->mNode;
        }
        p_m_SafePointerList[1].mNode.mPrev = 0i64;
      }
LABEL_42:
      LOBYTE(v15) = 1;
      ((void (__fastcall *)(UFG::SimComponent *, __int64, _QWORD, __int64, _DWORD, _QWORD, _QWORD, _QWORD))m_pComponent->vfptr[14].__vecDelDtor)(
        m_pComponent,
        40i64,
        0i64,
        v15,
        0,
        0i64,
        0i64,
        0i64);
    }
  }
}

// File Line: 762
// RVA: 0x2F6F30
void __fastcall TargetLockTask::Begin(TargetLockTask *this, ActionContext *pContext, __int64 a3, __int64 a4)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::TargetingSystemBaseComponent *m_pComponent; // r10
  __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *ComponentOfTypeHK; // rax
  TargetLockTrack *m_Track; // r11
  __int64 mTargetType; // rdx
  UFG::TargetingSimObject *m_pTargets; // rax
  __int64 v13; // r8

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   m_pPointer,
                                                                   UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                   m_pPointer,
                                                                   UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  m_Track = (TargetLockTrack *)this->m_Track;
  mTargetType = (unsigned int)m_Track->mTargetType;
  if ( m_pComponent )
  {
    m_pTargets = m_pComponent->m_pTargets;
    v13 = 56i64 * (unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[mTargetType];
    if ( *(UFG::SimObject **)((char *)&m_pTargets->m_pTarget.m_pPointer + v13) )
    {
      if ( !*(&m_pTargets->m_bLock + v13) )
      {
        LOBYTE(a4) = m_Track->mDisableCollision != 0;
        LOBYTE(v13) = 1;
        ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, __int64, __int64, __int64, _DWORD, char *, ActionContext *, ITrack *))m_pComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
          m_pComponent,
          mTargetType,
          v13,
          a4,
          0,
          &customCaption,
          pContext,
          this->m_Track);
      }
    }
  }
}

// File Line: 786
// RVA: 0x2F8900
void __fastcall TargetReleaseTask::Begin(TargetReleaseTask *this, ActionContext *context, __int64 a3, __int64 a4)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::TargetingSystemBaseComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // rax
  UFG::eTargetTypeEnum vfptr; // ebp

  if ( BYTE5(this->m_Track[1].vfptr) )
  {
    this->mContext = context;
  }
  else
  {
    m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = (UFG::TargetingSystemBaseComponent *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
      }
      if ( m_pComponent )
      {
        m_Track = this->m_Track;
        LOBYTE(a4) = BYTE6(m_Track[1].vfptr) != 0;
        vfptr = (UFG::eTargetTypeEnum)m_Track[1].vfptr;
        ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, _DWORD, char *, ActionContext *, ITrack *))m_pComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
          m_pComponent,
          (unsigned int)vfptr,
          0i64,
          a4,
          0,
          &customCaption,
          context,
          m_Track);
        if ( BYTE4(this->m_Track[1].vfptr) )
          UFG::TargetingSystemBaseComponent::ClearTarget(m_pComponent, vfptr);
      }
    }
  }
}

// File Line: 816
// RVA: 0x301190
void __fastcall TargetReleaseTask::End(TargetReleaseTask *this, __int64 a2, __int64 a3, __int64 a4)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::eTargetTypeEnum vfptr; // esi

  if ( BYTE5(this->m_Track[1].vfptr) )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = (UFG::TargetingSystemBaseComponent *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
      }
      if ( m_pComponent )
      {
        vfptr = (UFG::eTargetTypeEnum)this->m_Track[1].vfptr;
        LOBYTE(a4) = 1;
        ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, _DWORD, char *, ActionContext *, ITrack *))m_pComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
          m_pComponent,
          (unsigned int)vfptr,
          0i64,
          a4,
          0,
          &customCaption,
          this->mContext,
          this->m_Track);
        if ( BYTE4(this->m_Track[1].vfptr) )
          UFG::TargetingSystemBaseComponent::ClearTarget(m_pComponent, vfptr);
      }
    }
  }
}

// File Line: 848
// RVA: 0x2E1F60
void __fastcall TargetSteerToTask::TargetSteerToTask(TargetSteerToTask *this)
{
  this->Task<TargetSteerToTrack>::ITask::UFG::qNode<ITask,ITask>::mPrev = &this->UFG::qNode<ITask,ITask>;
  this->Task<TargetSteerToTrack>::ITask::UFG::qNode<ITask,ITask>::mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<TargetSteerToTrack>::`vftable;
  this->UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList>::mPrev = &this->UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList>;
  this->UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList>::mNext = &this->UFG::qNode<TargetSteerToTask,TargetingSystemTargetSteerToList>;
  this->vfptr = (ITaskVtbl *)&TargetSteerToTask::`vftable;
  this->mContext = 0i64;
}

// File Line: 852
// RVA: 0x2F9340
void __fastcall TargetSteerToTask::Begin(TargetSteerToTask *this, ActionContext *context)
{
  ITrack *m_Track; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TargetingSystemPedBaseComponent *v7; // rax

  m_Track = this->m_Track;
  this->mContext = context;
  if ( HIBYTE(m_Track[1].m_TrackClassNameUID) )
  {
    m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pPointer = (UFG::SimObjectGame *)m_pPointer->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pPointer = (UFG::SimObjectGame *)ComponentOfTypeHK;
      }
      else
      {
        m_pPointer = (UFG::SimObjectGame *)m_pPointer->m_Components.p[20].m_pComponent;
      }
    }
    v7 = (UFG::TargetingSystemPedBaseComponent *)((__int64 (__fastcall *)(UFG::SimObjectGame *))m_pPointer->vfptr[15].__vecDelDtor)(m_pPointer);
    if ( v7 )
      UFG::TargetingSystemPedBaseComponent::AddTargetSteerToTask(v7, this);
  }
}

// File Line: 866
// RVA: 0x30B460
char __fastcall TargetSteerToTask::Update(TargetSteerToTask *this, float timeDelta)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // r10
  __int64 v8; // rax
  __int64 v9; // rdx
  UFG::SimObject *v10; // rcx
  UFG::SimObject *v11; // rdx

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      m_Track = this->m_Track;
      v8 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
      v9 = 56i64
         * *(unsigned __int8 *)((unsigned int)m_Track[1].mBreakPoint + *(_QWORD *)&m_pComponent[1].m_Flags + 8i64);
      if ( BYTE2(m_Track[1].m_TrackClassNameUID) )
      {
        v10 = *(UFG::SimObject **)(v9 + v8 + 40);
        v11 = this->mContext->mSimObject.m_pPointer;
      }
      else
      {
        v10 = this->mContext->mSimObject.m_pPointer;
        v11 = *(UFG::SimObject **)(v9 + v8 + 40);
      }
      UFG::SteerToTarget(
        v10,
        v11,
        (UFG::qSymbolUC *)&m_Track[1].mResourceOwner + 1,
        timeDelta * *(float *)&m_Track[1].vfptr);
    }
  }
  return 1;
}

// File Line: 909
// RVA: 0x2F93F0
void __fastcall TargetSyncPositionTask::Begin(TargetSyncPositionTask *this, ActionContext *context)
{
  ITrack *m_Track; // r9
  bool *p_mManagePowerLevel; // rdi
  UFG::SimObject *v5; // r8
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mSimObjectTarget; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::SimObject *ppOutSimObjectTarget; // [rsp+A0h] [rbp+8h] BYREF

  m_Track = this->m_Track;
  this->mContext = context;
  this->mManagePowerLevel = 1;
  ppOutSimObjectTarget = 0i64;
  p_mManagePowerLevel = &this->mManagePowerLevel;
  if ( !UFG::TargetAttach(
          context,
          SHIDWORD(m_Track[1].vfptr),
          0i64,
          &ppOutSimObjectTarget,
          (UFG::qSymbolUC *)&m_Track[1].mResourceOwner,
          (UFG::qSymbolUC *)&m_Track[1].mResourceOwner + 1,
          *(float *)&m_Track[1].vfptr,
          0,
          -1.0,
          LOBYTE(m_Track[1].m_TrackClassNameUID) != 0,
          0,
          0,
          eTARGET_TYPE_INVALID,
          0,
          BYTE1(m_Track[1].m_TrackClassNameUID) != 0,
          BYTE2(m_Track[1].m_TrackClassNameUID) != 0,
          &this->mManagePowerLevel) )
    *p_mManagePowerLevel = 0;
  v5 = ppOutSimObjectTarget;
  p_mSimObjectTarget = &this->mSimObjectTarget;
  if ( this->mSimObjectTarget.m_pPointer )
  {
    mPrev = p_mSimObjectTarget->mPrev;
    mNext = this->mSimObjectTarget.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mSimObjectTarget->mPrev = p_mSimObjectTarget;
    this->mSimObjectTarget.mNext = &this->mSimObjectTarget;
  }
  this->mSimObjectTarget.m_pPointer = v5;
  if ( v5 )
  {
    v9 = v5->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v9->mNext = p_mSimObjectTarget;
    p_mSimObjectTarget->mPrev = v9;
    this->mSimObjectTarget.mNext = &v5->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v5->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mSimObjectTarget;
  }
}

// File Line: 965
// RVA: 0x3012A0
void __fastcall TargetSyncPositionTask::End(TargetSyncPositionTask *this)
{
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
    UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_Track[1].mResourceOwner + 1);
}

// File Line: 1008
// RVA: 0x2F5C20
void __fastcall TargetAttachTask::Begin(TargetAttachTask *this, ActionContext *context)
{
  TargetAttachTrack *m_Track; // rdx

  m_Track = (TargetAttachTrack *)this->m_Track;
  UFG::TargetAttach(
    context,
    (UFG::eTargetTypeEnum)m_Track->mTargetType,
    0i64,
    0i64,
    &m_Track->mAttachJointName,
    &m_Track->mTargetAttachJointName,
    m_Track->mBlendInTime,
    m_Track->mAttachRelative != 0,
    m_Track->mAttachRelativeMaxDistance,
    m_Track->mAttachToTarget != 0,
    m_Track->mAddToInventory != 0,
    m_Track->mAssignTargetType != 0,
    (UFG::eTargetTypeEnum)m_Track->mAssignmentTargetType,
    m_Track->mLockTarget != 0,
    0,
    m_Track->mPositionXYOnly != 0,
    0i64);
}

// File Line: 1050
// RVA: 0x2F6460
void __fastcall TargetDetachTask::Begin(TargetDetachTask *this, ActionContext *context)
{
  ITrack *m_Track; // rdx

  m_Track = this->m_Track;
  UFG::TargetDetach(
    context,
    (UFG::eTargetTypeEnum)m_Track[1].vfptr,
    0i64,
    (UFG::qSymbolUC *)&m_Track[1].m_TrackClassNameUID,
    (UFG::qSymbolUC *)&m_Track[1].mBreakPoint,
    *((float *)&m_Track[1].vfptr + 1),
    LOBYTE(m_Track[1].mMasterRate.text.mOffset) != 0,
    BYTE3(m_Track[1].mMasterRate.text.mOffset) != 0,
    BYTE1(m_Track[1].mMasterRate.text.mOffset) != 0,
    BYTE2(m_Track[1].mMasterRate.text.mOffset) != 0,
    BYTE4(m_Track[1].mMasterRate.text.mOffset) != 0,
    BYTE5(m_Track[1].mMasterRate.text.mOffset) != 0,
    *((float *)&m_Track[1].mResourceOwner + 1),
    *(float *)&m_Track[1].mResourceOwner,
    0);
}

// File Line: 1104
// RVA: 0x300A40
// attributes: thunk
void __fastcall TargetAttachEXTask::End(TargetAttachEXTask *this)
{
  TargetAttachEXTask::doAttach(this);
}

// File Line: 1109
// RVA: 0x30CD40
void __fastcall TargetAttachEXTask::doAttach(TargetAttachEXTask *this)
{
  ITrack *m_Track; // rax
  bool positionOnly; // r15
  UFG::SimObject *m_pPointer; // rbp
  bool positionXYOnly; // r12
  UFG::SimObject *v6; // r14
  UFG::SimComponent *ComponentOfType; // rax
  __int64 v8; // r8
  __int64 v9; // r9
  ITrack *v10; // rdx
  ITrack *v11; // rdx

  m_Track = this->m_Track;
  positionOnly = BYTE4(m_Track[1].mMasterRate.expression.mOffset) != 0;
  m_pPointer = this->mContext->mSimObject.m_pPointer;
  positionXYOnly = BYTE3(m_Track[1].mMasterRate.expression.mOffset) != 0;
  v6 = 0i64;
  ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
  if ( ComponentOfType )
  {
    v8 = *(_QWORD *)&ComponentOfType[1].m_Flags;
    v9 = *(_QWORD *)&ComponentOfType[1].m_TypeUID;
    v10 = this->m_Track;
    m_pPointer = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(LODWORD(v10[1].vfptr) + v8 + 8) + v9 + 40);
    v6 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(HIDWORD(v10[1].vfptr) + v8 + 8) + v9 + 40);
  }
  v11 = this->m_Track;
  UFG::TargetAttach(
    m_pPointer,
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
  UFG::SimObject *m_pPointer; // r14
  UFG::SimObject *v3; // r15
  UFG::SimComponent *ComponentOfType; // rax
  __int64 v5; // r8
  __int64 v6; // r9
  ITrack *m_Track; // rdx
  ITrack *v8; // rdx

  m_pPointer = this->mContext->mSimObject.m_pPointer;
  v3 = 0i64;
  ComponentOfType = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
  if ( ComponentOfType )
  {
    v5 = *(_QWORD *)&ComponentOfType[1].m_Flags;
    v6 = *(_QWORD *)&ComponentOfType[1].m_TypeUID;
    m_Track = this->m_Track;
    m_pPointer = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(LODWORD(m_Track[1].vfptr) + v5 + 8) + v6 + 40);
    v3 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(HIDWORD(m_Track[1].vfptr) + v5 + 8) + v6 + 40);
  }
  v8 = this->m_Track;
  UFG::TargetDetach(
    m_pPointer,
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
  ITaskVtbl *vfptr; // rax

  vfptr = this->vfptr;
  this->mAttached = 0;
  this->mContext = context;
  ((void (*)(void))vfptr->Update)();
}

// File Line: 1224
// RVA: 0x30A640
bool __fastcall TargetAttachEffectorTask::Update(TargetAttachEffectorTask *this, float timeDelta)
{
  bool v3; // zf
  ITrack *m_Track; // rsi
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::eTargetTypeEnum vfptr; // r14d
  float blendTime; // xmm6_4
  bool onlyEnablePostPhysics; // bp
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx

  if ( !TargetAttachEffectorTask::TargetValid(this) )
    return !this->mAttached;
  v3 = !this->mAttached;
  if ( !this->mAttached )
  {
    m_Track = this->m_Track;
    m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
    vfptr = (UFG::eTargetTypeEnum)m_Track[1].vfptr;
    blendTime = *(float *)&m_Track[1].mResourceOwner;
    onlyEnablePostPhysics = BYTE4(m_Track[1].vfptr) != 0;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
      }
      else if ( (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  m_pPointer,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  m_pPointer,
                                                                  UFG::CharacterAnimationComponent::_TypeUID);
      }
    }
    else
    {
      ComponentOfTypeHK = 0i64;
    }
    UFG::TargetAttachEffector(
      this->mContext->mSimObject.m_pPointer,
      ComponentOfTypeHK,
      vfptr,
      (UFG::qSymbolUC *)&m_Track[1].mResourceOwner + 1,
      (UFG::qSymbolUC *)&m_Track[1].m_TrackClassNameUID,
      (UFG::qSymbolUC *)&m_Track[1].mBreakPoint,
      blendTime,
      onlyEnablePostPhysics);
    this->mAttached = 1;
    return !this->mAttached;
  }
  return v3;
}

// File Line: 1243
// RVA: 0x3036E0
char __fastcall TargetAttachEffectorTask::TargetValid(TargetAttachEffectorTask *this)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::CharacterAnimationComponent *v4; // rbx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v10; // rax
  UFG::SimObjectCVBase *v11; // rcx
  __int16 v12; // dx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  Creature *mCreature; // rcx
  Creature *v15; // rdx

  if ( sTargetAttachEffectorTaskDisable )
    return 0;
  m_pPointer = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    v4 = ComponentOfTypeHK;
  }
  else
  {
    v4 = 0i64;
  }
  v7 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( !v7 )
    return 0;
  v8 = v7->m_Flags;
  if ( (v8 & 0x4000) != 0 )
  {
    m_pComponent = v7->m_Components.p[20].m_pComponent;
  }
  else if ( v8 >= 0 )
  {
    v10 = (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0
        ? UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::TargetingSystemBaseComponent::_TypeUID)
        : UFG::SimObject::GetComponentOfType(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v10;
  }
  else
  {
    m_pComponent = v7->m_Components.p[20].m_pComponent;
  }
  if ( m_pComponent
    && (v11 = *(UFG::SimObjectCVBase **)(56i64
                                       * *(unsigned __int8 *)(LODWORD(this->m_Track[1].vfptr)
                                                            + *(_QWORD *)&m_pComponent[1].m_Flags
                                                            + 8i64)
                                       + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                       + 40)) != 0i64
    && ((v12 = v11->m_Flags, (v12 & 0x4000) != 0) || v12 < 0
      ? (ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v11))
      : (v12 & 0x2000) == 0
      ? ((v12 & 0x1000) == 0
       ? (ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v11,
                                                                  UFG::CharacterAnimationComponent::_TypeUID))
       : (ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v11,
                                                                  UFG::CharacterAnimationComponent::_TypeUID)))
      : (ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v11)),
        ComponentOfType
     && v4
     && (mCreature = v4->mCreature, v15 = ComponentOfType->mCreature, mCreature)
     && v15
     && v15->mPose.mRigHandle.mData
     && mCreature->mPose.mRigHandle.mData
     && !ComponentOfType->mTemporaryRig
     && ComponentOfType->mRigHandle.mData
     && !v4->mTemporaryRig
     && v4->mRigHandle.mData) )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// File Line: 1280
// RVA: 0x2F63B0
void __fastcall TargetDetachEffectorTask::Begin(TargetDetachEffectorTask *this, ActionContext *context)
{
  UFG::qSymbolUC *m_Track; // rbx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  UFG::eTargetTypeEnum mUID; // esi
  float blendTime; // xmm6_4
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx

  m_Track = (UFG::qSymbolUC *)this->m_Track;
  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  mUID = m_Track[14].mUID;
  blendTime = *(float *)&m_Track[15].mUID;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
    }
    else if ( (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                m_pPointer,
                                                                UFG::CharacterAnimationComponent::_TypeUID);
    }
  }
  else
  {
    ComponentOfTypeHK = 0i64;
  }
  UFG::TargetDetachEffector(context->mSimObject.m_pPointer, ComponentOfTypeHK, mUID, m_Track + 16, blendTime);
}

// File Line: 1294
// RVA: 0x2F5BB0
void __fastcall TargetAttachConstraintTask::Begin(TargetAttachConstraintTask *this, ActionContext *context)
{
  ITrack *m_Track; // rdx

  m_Track = this->m_Track;
  UFG::TargetAttachConstraint(
    context->mSimObject.m_pPointer,
    (UFG::eTargetTypeEnum)m_Track[1].vfptr,
    (UFG::qSymbolUC *)&m_Track[1].mResourceOwner,
    (UFG::qSymbolUC *)&m_Track[1].mResourceOwner + 1,
    BYTE1(m_Track[1].m_TrackClassNameUID) != 0,
    LOBYTE(m_Track[1].mMasterRate.text.mOffset) != 0,
    SHIDWORD(m_Track[1].vfptr),
    BYTE1(m_Track[1].mMasterRate.text.mOffset) != 0);
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
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::CharacterAnimationComponent *v6; // rax
  UFG::CharacterAnimationComponent *v7; // rbx
  Creature *mCreature; // rcx
  UFG::SimObjectCVBase *Target; // rax
  UFG::SimObjectCharacter *v10; // rdi
  __int16 v11; // dx
  UFG::CharacterAnimationComponent *v12; // rax
  Creature *v13; // rbx
  int v14; // ebp
  UFG::eTargetTypeEnum v15; // r14d
  UFG::SimObjectCVBase *v16; // rsi
  __int16 v17; // cx
  UFG::CharacterAnimationComponent *v18; // rax
  Creature *v19; // rcx
  __int16 v20; // cx
  UFG::InventoryComponent *m_pComponent; // rax
  __int64 v22; // r8
  __int64 v23; // r9
  UFG::GameStatTracker *v24; // rax
  UFG::PersistentData::ID *Stat; // rax
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  unsigned int mUID; // ebx
  UFG::qResourceData *ArchetypeProperties; // rax
  __int16 v29; // cx
  UFG::PropInteractComponent *ComponentOfType; // rax
  __int16 v31; // cx
  UFG::TargetingSystemBaseComponent *v32; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v34; // rcx
  UFG::TargetingSystemBaseComponent *v35; // rbx
  __int16 v36; // dx
  UFG::SimComponent *v37; // rax
  ITrack *m_Track; // r11

  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      v6 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 )
    {
      v6 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)m_pPointer);
    }
    else
    {
      v6 = (UFG::CharacterAnimationComponent *)((m_Flags & 0x1000) != 0
                                              ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  m_pPointer,
                                                  UFG::CharacterAnimationComponent::_TypeUID)
                                              : UFG::SimObject::GetComponentOfType(
                                                  m_pPointer,
                                                  UFG::CharacterAnimationComponent::_TypeUID));
    }
    v7 = v6;
    if ( v6 )
    {
      if ( !UFG::getTarget(context, (UFG::eTargetTypeEnum)HIDWORD(this->m_Track[1].vfptr)) )
      {
        mCreature = v7->mCreature;
        if ( mCreature )
        {
          if ( mCreature->mPose.mRigHandle.mData )
            Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, HIDWORD(this->m_Track[1].mResourceOwner));
          Target = (UFG::SimObjectCVBase *)UFG::getTarget(
                                             context,
                                             (UFG::eTargetTypeEnum)LODWORD(this->m_Track[1].vfptr));
          v10 = (UFG::SimObjectCharacter *)Target;
          if ( Target )
          {
            v11 = Target->m_Flags;
            if ( (v11 & 0x4000) != 0 || v11 < 0 )
            {
              v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(Target);
            }
            else if ( (v11 & 0x2000) != 0 )
            {
              v12 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)Target);
            }
            else
            {
              v12 = (UFG::CharacterAnimationComponent *)((v11 & 0x1000) != 0
                                                       ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                           Target,
                                                           UFG::CharacterAnimationComponent::_TypeUID)
                                                       : UFG::SimObject::GetComponentOfType(
                                                           Target,
                                                           UFG::CharacterAnimationComponent::_TypeUID));
            }
            if ( v12 )
            {
              v13 = v12->mCreature;
              if ( v13 )
              {
                v14 = v13->mPose.mRigHandle.mData
                    ? Skeleton::GetBoneID(v13->mPose.mRigHandle.mUFGSkeleton, this->m_Track[1].m_TrackClassNameUID)
                    : -1;
                v15 = eTARGET_TYPE_EQUIPPED;
                v16 = (UFG::SimObjectCVBase *)UFG::getTarget(v10, eTARGET_TYPE_EQUIPPED);
                if ( v16
                  || (v15 = eTARGET_TYPE_EQUIPPED_LEFT_HAND,
                      (v16 = (UFG::SimObjectCVBase *)UFG::getTarget(v10, eTARGET_TYPE_EQUIPPED_LEFT_HAND)) != 0i64) )
                {
                  v17 = v16->m_Flags;
                  if ( (v17 & 0x4000) != 0 || v17 < 0 )
                  {
                    v18 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v16);
                  }
                  else if ( (v17 & 0x2000) != 0 )
                  {
                    v18 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v16);
                  }
                  else
                  {
                    v18 = (UFG::CharacterAnimationComponent *)((v17 & 0x1000) != 0
                                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 v16,
                                                                 UFG::CharacterAnimationComponent::_TypeUID)
                                                             : UFG::SimObject::GetComponentOfType(
                                                                 v16,
                                                                 UFG::CharacterAnimationComponent::_TypeUID));
                  }
                  if ( v18 )
                  {
                    v19 = v18->mCreature;
                    if ( v19->mPose.mRigHandle.mData )
                      Skeleton::GetBoneID(v19->mPose.mRigHandle.mUFGSkeleton, *(_DWORD *)&this->m_Track[1].mBreakPoint);
                    Creature::RemoveAttachment(v13, v10, v14, v16);
                    v20 = v10->m_Flags;
                    if ( (v20 & 0x4000) != 0 )
                    {
                      m_pComponent = (UFG::InventoryComponent *)v10->m_Components.p[39].m_pComponent;
                    }
                    else if ( v20 < 0 || (v20 & 0x2000) != 0 || (v20 & 0x1000) != 0 )
                    {
                      m_pComponent = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v10,
                                                                  UFG::InventoryComponent::_TypeUID);
                    }
                    else
                    {
                      m_pComponent = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v10,
                                                                  UFG::InventoryComponent::_TypeUID);
                    }
                    if ( m_pComponent )
                      UFG::InventoryComponent::RemoveObjectFromInventory(m_pComponent, v16, (__int64)this);
                    if ( v10 == UFG::GetLocalPlayer() )
                    {
                      v24 = UFG::GameStatTracker::Instance();
                      Stat = UFG::GameStatTracker::GetStat(v24, Equipped);
                      m_pSceneObj = v16->m_pSceneObj;
                      mUID = Stat->mValue.mUID;
                      if ( m_pSceneObj )
                      {
                        ArchetypeProperties = UFG::SceneObjectProperties::GetArchetypeProperties(m_pSceneObj);
                        if ( ArchetypeProperties )
                        {
                          if ( mUID == *(_DWORD *)&ArchetypeProperties->mDebugName[12] )
                            UFG::GameStatAction::Inventory::UnEquip(0);
                        }
                      }
                    }
                    v29 = v16->m_Flags;
                    if ( (v29 & 0x4000) == 0 )
                    {
                      if ( v29 < 0 )
                      {
                        ComponentOfType = (UFG::PropInteractComponent *)v16->m_Components.p[33].m_pComponent;
                        goto LABEL_65;
                      }
                      if ( (v29 & 0x2000) != 0 )
                      {
                        ComponentOfType = (UFG::PropInteractComponent *)v16->m_Components.p[13].m_pComponent;
                        goto LABEL_65;
                      }
                      if ( (v29 & 0x1000) == 0 )
                      {
                        ComponentOfType = (UFG::PropInteractComponent *)UFG::SimObject::GetComponentOfType(
                                                                          v16,
                                                                          UFG::PropInteractComponent::_TypeUID);
                        goto LABEL_65;
                      }
                    }
                    ComponentOfType = (UFG::PropInteractComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v16,
                                                                      UFG::PropInteractComponent::_TypeUID);
LABEL_65:
                    if ( ComponentOfType )
                      UFG::PropInteractComponent::DetachFromObject(ComponentOfType, v10, v22, v23);
                    v31 = v10->m_Flags;
                    if ( (v31 & 0x4000) != 0 )
                    {
                      v32 = (UFG::TargetingSystemBaseComponent *)v10->m_Components.p[20].m_pComponent;
                    }
                    else if ( v31 >= 0 )
                    {
                      if ( (v31 & 0x2000) != 0 || (v31 & 0x1000) != 0 )
                        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v10,
                                              UFG::TargetingSystemBaseComponent::_TypeUID);
                      else
                        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                              v10,
                                              UFG::TargetingSystemBaseComponent::_TypeUID);
                      v32 = (UFG::TargetingSystemBaseComponent *)ComponentOfTypeHK;
                    }
                    else
                    {
                      v32 = (UFG::TargetingSystemBaseComponent *)v10->m_Components.p[20].m_pComponent;
                    }
                    if ( v32 )
                    {
                      LOBYTE(v23) = 1;
                      ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, _QWORD, _QWORD, __int64, _DWORD, _QWORD, _QWORD, _QWORD))v32->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
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
                    v34 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
                    if ( v34 )
                    {
                      v36 = v34->m_Flags;
                      if ( (v36 & 0x4000) != 0 )
                      {
                        v35 = (UFG::TargetingSystemBaseComponent *)v34->m_Components.p[20].m_pComponent;
                      }
                      else if ( v36 >= 0 )
                      {
                        if ( (v36 & 0x2000) != 0 || (v36 & 0x1000) != 0 )
                          v37 = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v34,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
                        else
                          v37 = UFG::SimObject::GetComponentOfType(v34, UFG::TargetingSystemBaseComponent::_TypeUID);
                        v35 = (UFG::TargetingSystemBaseComponent *)v37;
                      }
                      else
                      {
                        v35 = (UFG::TargetingSystemBaseComponent *)v34->m_Components.p[20].m_pComponent;
                      }
                      if ( v35 )
                        UFG::TargetingSystemBaseComponent::AssignTarget(v35, eTARGET_TYPE_PICKUP_ITEM, v16);
                    }
                    else
                    {
                      v35 = 0i64;
                    }
                    m_Track = this->m_Track;
                    UFG::TargetAttach(
                      context,
                      eTARGET_TYPE_PICKUP_ITEM,
                      0i64,
                      0i64,
                      (UFG::qSymbolUC *)&m_Track[1].mResourceOwner + 1,
                      (UFG::qSymbolUC *)&m_Track[1].mBreakPoint,
                      *(float *)&m_Track[1].mResourceOwner,
                      BYTE1(m_Track[1].mMasterRate.text.mOffset) != 0,
                      -1.0,
                      0,
                      LOBYTE(m_Track[1].mMasterRate.text.mOffset) != 0,
                      BYTE2(m_Track[1].mMasterRate.text.mOffset) != 0,
                      SHIDWORD(m_Track[1].vfptr),
                      BYTE3(m_Track[1].mMasterRate.text.mOffset) != 0,
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
}

// File Line: 1505
// RVA: 0x2F8720
void __fastcall TargetPropInteractTask::Begin(TargetPropInteractTask *this, ActionContext *context)
{
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax

  this->mContext = context;
  m_pPointer = (UFG::SimObjectCVBase *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
    {
      ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
    }
    else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            m_pPointer,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                            m_pPointer,
                                                            UFG::ActiveAIEntityComponent::_TypeUID);
    }
    if ( ComponentOfTypeHK )
      ComponentOfTypeHK->m_InPropInteractBranch = 1;
  }
}

// File Line: 1515
// RVA: 0x30B240
bool __fastcall TargetPropInteractTask::Update(TargetPropInteractTask *this, float timeDelta, __int64 a3)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimComponent *v11; // rdi
  UFG::SimObjectGame *v12; // rcx
  __int16 v13; // dx
  UFG::SimComponent *v14; // rsi
  UFG::SimComponent *v15; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return 0;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                            m_pPointer,
                            UFG::TargetingSystemBaseComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = ComponentOfTypeHK;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return 0;
  v8 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 48i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v8 )
    return 0;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 )
    goto LABEL_14;
  if ( v9 < 0 )
  {
    v11 = v8->m_Components.p[33].m_pComponent;
    goto LABEL_22;
  }
  if ( (v9 & 0x2000) != 0 )
  {
    v11 = v8->m_Components.p[13].m_pComponent;
    goto LABEL_22;
  }
  if ( (v9 & 0x1000) != 0 )
LABEL_14:
    ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::PropInteractComponent::_TypeUID);
  else
    ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::PropInteractComponent::_TypeUID);
  v11 = ComponentOfType;
LABEL_22:
  if ( v11 )
  {
    if ( *(_QWORD *)&v11[2].m_Flags )
    {
      v12 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
      if ( v12 )
      {
        v13 = v12->m_Flags;
        if ( (v13 & 0x4000) != 0 )
        {
          v14 = v12->m_Components.p[7].m_pComponent;
        }
        else if ( v13 >= 0 )
        {
          if ( (v13 & 0x2000) != 0 )
          {
            v14 = v12->m_Components.p[6].m_pComponent;
          }
          else
          {
            if ( (v13 & 0x1000) != 0 )
              v15 = UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::ActionTreeComponent::_TypeUID);
            else
              v15 = UFG::SimObject::GetComponentOfType(v12, UFG::ActionTreeComponent::_TypeUID);
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
          ((void (__fastcall *)(UFG::SimComponent *, __int64, __int64, _QWORD, _DWORD, _QWORD, _QWORD, _QWORD))m_pComponent->vfptr[14].__vecDelDtor)(
            m_pComponent,
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
  ActionContext *mContext; // rcx
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::ActiveAIEntityComponent *ComponentOfTypeHK; // rax

  mContext = this->mContext;
  if ( mContext )
  {
    m_pPointer = (UFG::SimObjectCVBase *)mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::ActiveAIEntityComponent>(m_pPointer);
      }
      else if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      {
        ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pPointer,
                                                              UFG::ActiveAIEntityComponent::_TypeUID);
      }
      else
      {
        ComponentOfTypeHK = (UFG::ActiveAIEntityComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pPointer,
                                                              UFG::ActiveAIEntityComponent::_TypeUID);
      }
      if ( ComponentOfTypeHK )
        ComponentOfTypeHK->m_InPropInteractBranch = 0;
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
  ITrack *m_Track; // rax

  m_Track = this->m_Track;
  if ( !LOBYTE(m_Track[1].mResourceOwner) )
    return BYTE1(m_Track[1].mResourceOwner) != 0;
  TargetAssignTask::PerformAssignment(this);
  return 1;
}

// File Line: 1577
// RVA: 0x302A00
void __fastcall TargetAssignTask::PerformAssignment(TargetAssignTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // rax
  unsigned int vfptr_high; // ebx
  UFG::TargetingSystemPedBaseComponent *v8; // rax
  UFG::SimObjectVehicle *v9; // rcx

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = (UFG::TargetingSystemBaseComponent *)ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      m_Track = this->m_Track;
      vfptr_high = HIDWORD(m_Track[1].vfptr);
      UFG::TargetingSystemBaseComponent::AssignTarget(m_pComponent, vfptr_high, (unsigned int)m_Track[1].vfptr);
      if ( vfptr_high == 28 )
      {
        v8 = (UFG::TargetingSystemPedBaseComponent *)((__int64 (__fastcall *)(UFG::TargetingSystemBaseComponent *))m_pComponent->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[15].__vecDelDtor)(m_pComponent);
        if ( v8 )
          UFG::TargetingSystemPedBaseComponent::updateVehicleOccupantTargets(v8);
        v9 = (UFG::SimObjectVehicle *)m_pComponent->m_pTargets[(unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[28]].m_pTarget.m_pPointer;
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
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( BYTE1(this->m_Track[1].mResourceOwner) )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                m_pPointer,
                                UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = (UFG::TargetingSystemBaseComponent *)ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
      }
      if ( m_pComponent )
        UFG::TargetingSystemBaseComponent::SetTarget(m_pComponent, SHIDWORD(this->m_Track[1].vfptr), 0i64);
    }
  }
}

// File Line: 1640
// RVA: 0x2F5B90
void __fastcall TargetAssignTargetsTargetToMyTargetTask::Begin(
        TargetAssignTargetsTargetToMyTargetTask *this,
        ActionContext *pContext)
{
  this->mContext = pContext;
  TargetAssignTargetsTargetToMyTargetTask::PerformAssignment(this);
}

// File Line: 1647
// RVA: 0x30A5E0
char __fastcall TargetAssignTargetsTargetToMyTargetTask::Update(
        TargetAssignTargetsTargetToMyTargetTask *this,
        float timeDelta)
{
  if ( !BYTE4(this->m_Track[1].mResourceOwner) )
    return 0;
  TargetAssignTargetsTargetToMyTargetTask::PerformAssignment(this);
  return 1;
}

// File Line: 1657
// RVA: 0x302840
void __fastcall TargetAssignTargetsTargetToMyTargetTask::PerformAssignment(
        TargetAssignTargetsTargetToMyTargetTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rdi
  UFG::SimComponent *v5; // rax
  unsigned int *m_Track; // rax
  __int64 v7; // rbx
  __int64 v8; // rbp
  UFG::SimObject *v9; // rsi
  UFG::SimObjectGame *v10; // r8
  __int16 v11; // cx
  UFG::SimComponent *v12; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TargetingSimObject *m_pTargets; // rcx
  __int64 v15; // rbx

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v5 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = (UFG::TargetingSystemBaseComponent *)v5;
    }
    else
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      m_Track = (unsigned int *)this->m_Track;
      v7 = m_Track[15];
      v8 = m_Track[16];
      v9 = 0i64;
      v10 = (UFG::SimObjectGame *)m_pComponent->m_pTargets[(unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[m_Track[14]]].m_pTarget.m_pPointer;
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 & 0x4000) != 0 )
        {
          v12 = v10->m_Components.p[20].m_pComponent;
        }
        else if ( v11 >= 0 )
        {
          if ( (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v10,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v10, UFG::TargetingSystemBaseComponent::_TypeUID);
          v12 = ComponentOfTypeHK;
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
      m_pTargets = m_pComponent->m_pTargets;
      if ( m_pTargets[(unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[v8]].m_pTarget.m_pPointer != v9 )
      {
        if ( m_pComponent->m_pTargetingMap->m_Map.p[v8] )
        {
          v15 = (unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[v8];
          UFG::TargetingSimObject::SetTarget(&m_pTargets[v15], 0i64);
          UFG::TargetingSimObject::SetLock(&m_pComponent->m_pTargets[v15], 0);
        }
        UFG::TargetingSystemBaseComponent::SetTarget(m_pComponent, (UFG::eTargetTypeEnum)v8, v9);
      }
    }
  }
}

// File Line: 1691
// RVA: 0x2F5920
void __fastcall TargetAssignMyTargetToTargetsTargetTask::Begin(
        TargetAssignMyTargetToTargetsTargetTask *this,
        ActionContext *pContext)
{
  this->mContext = pContext;
  TargetAssignMyTargetToTargetsTargetTask::PerformAssignment(this);
}

// File Line: 1698
// RVA: 0x30A5B0
char __fastcall TargetAssignMyTargetToTargetsTargetTask::Update(
        TargetAssignMyTargetToTargetsTargetTask *this,
        float timeDelta)
{
  if ( !BYTE4(this->m_Track[1].mResourceOwner) )
    return 0;
  TargetAssignMyTargetToTargetsTargetTask::PerformAssignment(this);
  return 1;
}

// File Line: 1708
// RVA: 0x3026F0
void __fastcall TargetAssignMyTargetToTargetsTargetTask::PerformAssignment(
        TargetAssignMyTargetToTargetsTargetTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  unsigned int *m_Track; // r8
  __int64 v6; // rdx
  __int64 v7; // r9
  UFG::eTargetTypeEnum v8; // ebx
  UFG::SimObject *v9; // rdi
  UFG::SimObjectGame *v10; // r8
  __int16 v11; // cx
  UFG::TargetingSystemBaseComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      m_Track = (unsigned int *)this->m_Track;
      v6 = *(_QWORD *)&m_pComponent[1].m_Flags;
      v7 = *(_QWORD *)&m_pComponent[1].m_TypeUID;
      v8 = m_Track[16];
      v9 = *(UFG::SimObject **)(56i64 * *(unsigned __int8 *)(m_Track[14] + v6 + 8) + v7 + 40);
      v10 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(m_Track[15] + v6 + 8) + v7 + 40);
      if ( v10 )
      {
        v11 = v10->m_Flags;
        if ( (v11 & 0x4000) != 0 )
        {
          ComponentOfTypeHK = (UFG::TargetingSystemBaseComponent *)v10->m_Components.p[20].m_pComponent;
        }
        else if ( v11 >= 0 )
        {
          if ( (v11 & 0x2000) != 0 || (v11 & 0x1000) != 0 )
            ComponentOfTypeHK = (UFG::TargetingSystemBaseComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                       v10,
                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfTypeHK = (UFG::TargetingSystemBaseComponent *)UFG::SimObject::GetComponentOfType(
                                                                       v10,
                                                                       UFG::TargetingSystemBaseComponent::_TypeUID);
        }
        else
        {
          ComponentOfTypeHK = (UFG::TargetingSystemBaseComponent *)v10->m_Components.p[20].m_pComponent;
        }
        if ( ComponentOfTypeHK )
          UFG::TargetingSystemBaseComponent::AssignTarget(ComponentOfTypeHK, v8, v9);
      }
    }
  }
}

// File Line: 1739
// RVA: 0x2F62D0
void __fastcall TargetDestroyTask::Begin(TargetDestroyTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v7; // rcx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = *(UFG::SimObject **)(56i64
                              * *(unsigned __int8 *)(LODWORD(this->m_Track[1].vfptr)
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
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
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *v6; // rax
  __int64 vfptr_low; // r8
  UFG::SimObjectCVBase *v8; // rbx
  __int16 v9; // cx
  UFG::CharacterAnimationComponent *v10; // rax
  Creature *mCreature; // rbp
  int v12; // r14d
  UFG::SimObject *Target; // rax
  UFG::SimObjectGame *v14; // rsi
  __int64 v15; // r8
  __int64 v16; // r9
  __int16 v17; // dx
  UFG::InventoryComponent *ComponentOfTypeHK; // rax
  __int16 v19; // cx
  UFG::PropInteractComponent *ComponentOfType; // rax
  __int16 v21; // cx
  UFG::TargetingSystemBaseComponent *v22; // rbx
  UFG::SimComponent *v23; // rax
  __int16 v24; // cx
  UFG::SimComponent *v25; // rax
  UFG::GunComponent *v26; // rsi
  __int64 v27; // rax
  __int64 v28; // rcx
  UFG::SimObjectGame *v29; // rcx
  __int16 v30; // dx
  UFG::GunComponent *v31; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v6 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v6;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return;
  vfptr_low = LODWORD(this->m_Track[1].vfptr);
  v8 = *(UFG::SimObjectCVBase **)(56i64 * *(unsigned __int8 *)(vfptr_low + *(_QWORD *)&m_pComponent[1].m_Flags + 8)
                                + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                + 40);
  if ( !v8 )
    return;
  v9 = v8->m_Flags;
  if ( (v9 & 0x400) != 0 )
    return;
  if ( (_DWORD)vfptr_low == 23 )
  {
    if ( (v9 & 0x4000) != 0 || v9 < 0 )
    {
      v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
    }
    else if ( (v9 & 0x2000) != 0 )
    {
      v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8);
    }
    else
    {
      v10 = (UFG::CharacterAnimationComponent *)((v9 & 0x1000) != 0
                                               ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v8,
                                                   UFG::CharacterAnimationComponent::_TypeUID)
                                               : UFG::SimObject::GetComponentOfType(
                                                   v8,
                                                   UFG::CharacterAnimationComponent::_TypeUID));
    }
    if ( v10 )
    {
      mCreature = v10->mCreature;
      if ( mCreature )
      {
        v12 = mCreature->mPose.mRigHandle.mData
            ? Skeleton::GetBoneID(
                mCreature->mPose.mRigHandle.mUFGSkeleton,
                (unsigned int)this->m_Track[1].mResourceOwner)
            : -1;
        Target = UFG::getTarget(v8, eTARGET_TYPE_EQUIPPED);
        v14 = (UFG::SimObjectGame *)Target;
        if ( Target )
        {
          Creature::RemoveAttachment(mCreature, v8, v12, Target);
          v17 = v8->m_Flags;
          if ( (v17 & 0x4000) != 0 )
          {
            ComponentOfTypeHK = (UFG::InventoryComponent *)v8->m_Components.p[39].m_pComponent;
          }
          else if ( v17 < 0 || (v17 & 0x2000) != 0 || (v17 & 0x1000) != 0 )
          {
            ComponentOfTypeHK = (UFG::InventoryComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                             v8,
                                                             UFG::InventoryComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = (UFG::InventoryComponent *)UFG::SimObject::GetComponentOfType(
                                                             v8,
                                                             UFG::InventoryComponent::_TypeUID);
          }
          if ( ComponentOfTypeHK )
            UFG::InventoryComponent::RemoveObjectFromInventory(ComponentOfTypeHK, v14, (__int64)this);
          v19 = v14->m_Flags;
          if ( (v19 & 0x4000) == 0 )
          {
            if ( v19 < 0 )
            {
              ComponentOfType = (UFG::PropInteractComponent *)v14->m_Components.p[33].m_pComponent;
              goto LABEL_47;
            }
            if ( (v19 & 0x2000) != 0 )
            {
              ComponentOfType = (UFG::PropInteractComponent *)v14->m_Components.p[13].m_pComponent;
              goto LABEL_47;
            }
            if ( (v19 & 0x1000) == 0 )
            {
              ComponentOfType = (UFG::PropInteractComponent *)UFG::SimObject::GetComponentOfType(
                                                                v14,
                                                                UFG::PropInteractComponent::_TypeUID);
              goto LABEL_47;
            }
          }
          ComponentOfType = (UFG::PropInteractComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            v14,
                                                            UFG::PropInteractComponent::_TypeUID);
LABEL_47:
          if ( ComponentOfType )
            UFG::PropInteractComponent::DetachFromObject(ComponentOfType, v8, v15, v16);
          v21 = v8->m_Flags;
          if ( (v21 & 0x4000) != 0 )
          {
            v22 = (UFG::TargetingSystemBaseComponent *)v8->m_Components.p[20].m_pComponent;
          }
          else if ( v21 >= 0 )
          {
            if ( (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0 )
              v23 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
            else
              v23 = UFG::SimObject::GetComponentOfType(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
            v22 = (UFG::TargetingSystemBaseComponent *)v23;
          }
          else
          {
            v22 = (UFG::TargetingSystemBaseComponent *)v8->m_Components.p[20].m_pComponent;
          }
          if ( v22 )
          {
            LOBYTE(v16) = 1;
            ((void (__fastcall *)(UFG::TargetingSystemBaseComponent *, __int64, _QWORD, __int64, _DWORD, _QWORD, _QWORD, _QWORD))v22->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[14].__vecDelDtor)(
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
    if ( (v24 & 0x4000) != 0 || v24 < 0 || (v24 & 0x2000) != 0 || (v24 & 0x1000) != 0 )
      v25 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID);
    else
      v25 = UFG::SimObject::GetComponentOfType(v8, UFG::GunComponent::_TypeUID);
    v26 = (UFG::GunComponent *)v25;
    if ( v25 )
    {
      v27 = *(_QWORD *)&m_pComponent[1].m_Flags;
      v28 = BYTE5(this->m_Track[1].vfptr) ? *(unsigned __int8 *)(v27 + 50) : *(unsigned __int8 *)(v27 + 25);
      v29 = *(UFG::SimObjectGame **)(56 * v28 + *(_QWORD *)&m_pComponent[1].m_TypeUID + 40);
      if ( v29 )
      {
        v30 = v29->m_Flags;
        if ( (v30 & 0x4000) != 0 || v30 < 0 || (v30 & 0x2000) != 0 || (v30 & 0x1000) != 0 )
          v31 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v29, UFG::GunComponent::_TypeUID);
        else
          v31 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(v29, UFG::GunComponent::_TypeUID);
        if ( v31 )
          UFG::GunComponent::TransferAmmoFromGun(v31, v26);
      }
    }
  }
  if ( BYTE4(this->m_Track[1].vfptr) )
    UFG::SimObject::Destroy(v8);
}G::GunComponent::_TypeUI

// File Line: 1861
// RVA: 0x2F57D0
void __fastcall TargetAddToInventoryTask::Begin(TargetAddToInventoryTask *this, ActionContext *pContext)
{
  __int64 v2; // r15
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::InventoryComponent *m_pComponent; // rbx
  UFG::SimComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  __int16 v10; // dx
  UFG::SimComponent *v11; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v13; // rdx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InventoryComponent *)m_pPointer->m_Components.p[39].m_pComponent;
    }
    else
    {
      v8 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InventoryComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InventoryComponent::_TypeUID);
      m_pComponent = (UFG::InventoryComponent *)v8;
    }
    if ( m_pComponent )
    {
      v9 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
      if ( v9 )
      {
        v10 = v9->m_Flags;
        if ( (v10 & 0x4000) != 0 )
        {
          v11 = v9->m_Components.p[20].m_pComponent;
        }
        else if ( v10 >= 0 )
        {
          if ( (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v9,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
          v11 = ComponentOfTypeHK;
        }
        else
        {
          v11 = v9->m_Components.p[20].m_pComponent;
        }
        if ( v11 )
        {
          v13 = *(UFG::SimObject **)(56i64
                                   * *(unsigned __int8 *)(LODWORD(this->m_Track[1].vfptr)
                                                        + *(_QWORD *)&v11[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&v11[1].m_TypeUID
                                   + 40);
          if ( v13 )
            UFG::InventoryComponent::AddObjectToInventory(m_pComponent, v13, 0, v2);
        }
      }
    }
  }
}

// File Line: 1887
// RVA: 0x2F8A20
void __fastcall TargetRemoveFromInventoryTask::Begin(TargetRemoveFromInventoryTask *this, ActionContext *pContext)
{
  __int64 v2; // r15
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::InventoryComponent *m_pComponent; // rbx
  UFG::SimComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  __int16 v10; // dx
  UFG::SimComponent *v11; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObject *v13; // rdx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::InventoryComponent *)m_pPointer->m_Components.p[39].m_pComponent;
    }
    else
    {
      v8 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::InventoryComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::InventoryComponent::_TypeUID);
      m_pComponent = (UFG::InventoryComponent *)v8;
    }
    if ( m_pComponent )
    {
      v9 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
      if ( v9 )
      {
        v10 = v9->m_Flags;
        if ( (v10 & 0x4000) != 0 )
        {
          v11 = v9->m_Components.p[20].m_pComponent;
        }
        else if ( v10 >= 0 )
        {
          if ( (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v9,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v9, UFG::TargetingSystemBaseComponent::_TypeUID);
          v11 = ComponentOfTypeHK;
        }
        else
        {
          v11 = v9->m_Components.p[20].m_pComponent;
        }
        if ( v11 )
        {
          v13 = *(UFG::SimObject **)(56i64
                                   * *(unsigned __int8 *)(LODWORD(this->m_Track[1].vfptr)
                                                        + *(_QWORD *)&v11[1].m_Flags
                                                        + 8i64)
                                   + *(_QWORD *)&v11[1].m_TypeUID
                                   + 40);
          if ( v13 )
            UFG::InventoryComponent::RemoveObjectFromInventory(m_pComponent, v13, v2);
        }
      }
    }
  }
}

// File Line: 1907
// RVA: 0x2F87A0
void __fastcall TargetPurchaseItemTask::Begin(TargetPurchaseItemTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *Target; // rax
  UFG::SimObject *v3; // rdi
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool IsSafehouseItemVendor; // al
  UFG::eInventoryItemEnum v8; // ecx
  int Cost; // eax
  int v10; // eax

  Target = (UFG::SimObjectGame *)UFG::getTarget(pContext, (UFG::eTargetTypeEnum)LODWORD(this->m_Track[1].vfptr));
  v3 = Target;
  if ( Target )
  {
    m_Flags = Target->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = Target->m_Components.p[39].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(Target, UFG::InventoryComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(Target, UFG::InventoryComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    if ( m_pComponent )
    {
      IsSafehouseItemVendor = UFG::FaceActionComponent::IsSafehouseItemVendor(*(UFG::eInventoryItemEnum *)&m_pComponent[14].m_Flags);
      v8 = *(_DWORD *)&m_pComponent[14].m_Flags;
      if ( IsSafehouseItemVendor )
      {
        Cost = UFG::ItemProfiles::GetCost(v8);
      }
      else
      {
        v10 = UFG::ItemProfiles::GetCost(v8);
        Cost = (int)UFG::StoreFrontTracker::GetItemPriceBasedOnClothes((float)v10);
      }
      UFG::GameStatAction::Money::PurchaseItem(v3, *(UFG::eInventoryItemEnum *)&m_pComponent[14].m_Flags, Cost);
      if ( UFG::TiDo::GetIsInstantiated() )
      {
        if ( (_S7_6 & 1) == 0 )
        {
          _S7_6 |= 1u;
          UFG::qWiseSymbol::create_from_string(&Play_ui_cha_ching, "Play_ui_cha_ching");
          atexit(TargetPurchaseItemTask::Begin_::_11_::_dynamic_atexit_destructor_for__Play_ui_cha_ching__);
        }
        UFG::AudioEntity::CreateAndPlayEvent(UFG::AmbienceAudio::m_instance, Play_ui_cha_ching.mUID, 0i64, 0, 0i64);
      }
    }
  }
}

// File Line: 1933
// RVA: 0x2F9510
void __fastcall TargetVehicleBreakWindowTask::Begin(TargetVehicleBreakWindowTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *Target; // rax
  __int16 m_Flags; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::VehicleEffectsComponent *m_pComponent; // rcx

  Target = (UFG::SimObjectGame *)UFG::getTarget(pContext, (UFG::eTargetTypeEnum)LODWORD(this->m_Track[1].vfptr));
  if ( Target )
  {
    m_Flags = Target->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      goto LABEL_3;
    if ( m_Flags < 0 )
    {
      m_pComponent = (UFG::VehicleEffectsComponent *)Target->m_Components.p[32].m_pComponent;
      goto LABEL_11;
    }
    if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_3:
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(Target, UFG::VehicleEffectsComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(Target, UFG::VehicleEffectsComponent::_TypeUID);
    m_pComponent = (UFG::VehicleEffectsComponent *)ComponentOfTypeHK;
LABEL_11:
    if ( m_pComponent )
      UFG::VehicleEffectsComponent::BreakGlass(m_pComponent, SHIDWORD(this->m_Track[1].vfptr));
  }
}

// File Line: 1961
// RVA: 0x30A750
char __fastcall TargetFocusOverrideTask::Update(TargetFocusOverrideTask *this, float timeDelta)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TargetingSystemPedPlayerComponent *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v8; // r8

  m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = (UFG::TargetingSystemPedPlayerComponent *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[19].__vecDelDtor)(m_pComponent);
      if ( v7 )
      {
        v8 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)(56i64
                                                                                           * (unsigned __int8)v7->m_pTargetingMap->m_Map.p[LODWORD(this->m_Track[1].vfptr)]);
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
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TargetingSystemPedPlayerComponent *v5; // rax

  m_pPointer = (UFG::SimObjectGame *)this->m_pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v5 = (UFG::TargetingSystemPedPlayerComponent *)((__int64 (__fastcall *)(UFG::SimComponent *))m_pComponent->vfptr[19].__vecDelDtor)(m_pComponent);
      if ( v5 )
        UFG::TargetingSystemPedPlayerComponent::ClearFocusModeOverrideSimObject(v5);
    }
  }
}

// File Line: 1999
// RVA: 0x2F6930
void __fastcall TargetHitReactionTask::Begin(TargetHitReactionTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *Target; // rbx
  UFG::SimObject *m_pPointer; // r8
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimObjectGame *v7; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v9; // cx
  UFG::HitReactionComponent *v10; // rbx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::HitRecord hitrecord; // [rsp+30h] [rbp-138h] BYREF

  Target = (UFG::SimObjectGame *)UFG::getTarget(pContext, (UFG::eTargetTypeEnum)LODWORD(this->m_Track[1].vfptr));
  if ( Target )
  {
    m_pPointer = pContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        v7 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::HitReactionComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::HitReactionComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[15].m_pComponent;
      }
      if ( m_pComponent )
      {
        v9 = Target->m_Flags;
        if ( (v9 & 0x4000) != 0 )
        {
          v10 = (UFG::HitReactionComponent *)Target->m_Components.p[15].m_pComponent;
        }
        else if ( v9 >= 0 )
        {
          if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(Target, UFG::HitReactionComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(Target, UFG::HitReactionComponent::_TypeUID);
          v10 = (UFG::HitReactionComponent *)ComponentOfType;
        }
        else
        {
          v10 = (UFG::HitReactionComponent *)Target->m_Components.p[15].m_pComponent;
        }
        if ( v10 )
        {
          UFG::HitRecord::HitRecord(&hitrecord);
          UFG::HitRecord::operator=(&hitrecord, (UFG::HitRecord *)&m_pComponent[2].m_BoundComponentHandles.mNode.mNext);
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
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  UFG::ParkourHandle *v7; // rdi
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *v10; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v12; // r8
  __int16 v13; // cx
  UFG::WorldContextComponent *ComponentOfType; // rax

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[28].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::WorldContextComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::WorldContextComponent::_TypeUID);
    if ( m_pComponent )
    {
      v7 = *(UFG::ParkourHandle **)&m_pComponent[5].m_TypeUID;
      if ( v7 )
      {
        v8 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
        if ( v8 )
        {
          v9 = v8->m_Flags;
          if ( (v9 & 0x4000) != 0 )
          {
            v10 = v8->m_Components.p[20].m_pComponent;
          }
          else if ( v9 >= 0 )
          {
            if ( (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v8,
                                    UFG::TargetingSystemBaseComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, UFG::TargetingSystemBaseComponent::_TypeUID);
            v10 = ComponentOfTypeHK;
          }
          else
          {
            v10 = v8->m_Components.p[20].m_pComponent;
          }
          if ( v10 )
          {
            v12 = *(UFG::SimObjectGame **)(56i64
                                         * *(unsigned __int8 *)(LODWORD(this->m_Track[1].vfptr)
                                                              + *(_QWORD *)&v10[1].m_Flags
                                                              + 8i64)
                                         + *(_QWORD *)&v10[1].m_TypeUID
                                         + 40);
            if ( v12 )
            {
              v13 = v12->m_Flags;
              if ( (v13 & 0x4000) != 0 )
              {
                ComponentOfType = (UFG::WorldContextComponent *)v12->m_Components.p[28].m_pComponent;
              }
              else if ( v13 < 0 || (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0 )
              {
                ComponentOfType = (UFG::WorldContextComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                  v12,
                                                                  UFG::WorldContextComponent::_TypeUID);
              }
              else
              {
                ComponentOfType = (UFG::WorldContextComponent *)UFG::SimObject::GetComponentOfType(
                                                                  v12,
                                                                  UFG::WorldContextComponent::_TypeUID);
              }
              if ( ComponentOfType )
                UFG::WorldContextComponent::LatchParkourHandle(ComponentOfType, v7);
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
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<TargetAttackRightsTrack>::`vftable;
  this->vfptr = (ITaskVtbl *)&TargetAttackRightsTask::`vftable;
  this->mTargetAttackRightsComponent.mPrev = &this->mTargetAttackRightsComponent;
  this->mTargetAttackRightsComponent.mNext = &this->mTargetAttackRightsComponent;
  this->mTargetAttackRightsComponent.m_pPointer = 0i64;
  this->mPreviousAttackRights = 0;
  this->mpContext = 0i64;
}

// File Line: 2068
// RVA: 0x301EE0
UFG::qString *__fastcall TargetAttackRightsTask::GetDebugString(
        TargetAttackRightsTask *this,
        UFG::qString *result,
        ActionContext *context)
{
  hkResourceHandle *m_pComponent; // rbx
  UFG::SimObject *m_pPointer; // rcx
  char *v7; // rax
  UFG::qString *v8; // rax
  UFG::qString *v9; // rax
  UFG::SimObjectGame *v10; // rcx
  __int16 v11; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectGame *v13; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  const char *Clone; // rdx
  UFG::qString resulta; // [rsp+30h] [rbp-58h] BYREF
  UFG::qString v19; // [rsp+58h] [rbp-30h] BYREF

  m_pComponent = 0i64;
  UFG::qString::qString(result, "TargetAttackRightsTask: ");
  m_pPointer = context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    v7 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&m_pPointer->m_Name);
    UFG::qString::qString(&v19, v7);
    v9 = UFG::operator+(&resulta, v8, ": ");
    UFG::qString::operator+=(result, v9);
    UFG::qString::~qString(&resulta);
    UFG::qString::~qString(&v19);
  }
  else
  {
    UFG::qString::operator+=(result, "unknown SimObject: ");
  }
  v10 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v10
    && ((v11 = v10->m_Flags, (v11 & 0x4000) == 0)
      ? (v11 >= 0
       ? ((v11 & 0x2000) == 0
        ? ((v11 & 0x1000) == 0
         ? (ComponentOfType = UFG::SimObject::GetComponentOfType(v10, UFG::ActionTreeComponent::_TypeUID))
         : (ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::ActionTreeComponent::_TypeUID)))
        : (ComponentOfType = v10->m_Components.p[6].m_pComponent))
       : (ComponentOfType = v10->m_Components.p[7].m_pComponent))
      : (ComponentOfType = v10->m_Components.p[7].m_pComponent),
        ComponentOfType) )
  {
    v13 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( v13 )
    {
      m_Flags = v13->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
      {
        m_pComponent = (hkResourceHandle *)v13->m_Components.p[7].m_pComponent;
      }
      else if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (hkResourceHandle *)v13->m_Components.p[6].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v13, UFG::ActionTreeComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v13, UFG::ActionTreeComponent::_TypeUID);
        m_pComponent = (hkResourceHandle *)ComponentOfTypeHK;
      }
    }
    Clone = (const char *)TargetVisibleInAIDataCondition::CreateClone(m_pComponent + 12);
  }
  else
  {
    Clone = "no node path found";
  }
  UFG::qString::operator+=(result, Clone);
  return result;
}

// File Line: 2093
// RVA: 0x2F5CF0
void __fastcall TargetAttackRightsTask::Begin(TargetAttackRightsTask *this, ActionContext *context)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::AttackRightsComponent> *p_mTargetAttackRightsComponent; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v10; // rax
  ITrack *m_Track; // r9
  UFG::SimObjectGame *v12; // r8
  char v13; // bp
  __int16 v14; // cx
  UFG::SimComponent *v15; // rdi
  UFG::SimComponent *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  char v20; // al
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  p_mTargetAttackRightsComponent = &this->mTargetAttackRightsComponent;
  if ( this->mTargetAttackRightsComponent.m_pPointer )
  {
    mPrev = p_mTargetAttackRightsComponent->mPrev;
    mNext = this->mTargetAttackRightsComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mTargetAttackRightsComponent->mPrev = p_mTargetAttackRightsComponent;
    this->mTargetAttackRightsComponent.mNext = &this->mTargetAttackRightsComponent;
  }
  this->mTargetAttackRightsComponent.m_pPointer = 0i64;
  this->mpContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v10 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
          ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
          : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v10;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      m_Track = this->m_Track;
      v12 = *(UFG::SimObjectGame **)(56i64
                                   * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags
                                                        + LODWORD(m_Track[1].vfptr)
                                                        + 8i64)
                                   + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                   + 40);
      if ( v12 )
      {
        v13 = BYTE4(m_Track[1].vfptr) != 0;
        v14 = v12->m_Flags;
        if ( (v14 & 0x4000) != 0 )
        {
          v15 = v12->m_Components.p[46].m_pComponent;
        }
        else
        {
          v16 = v14 < 0 || (v14 & 0x2000) != 0 || (v14 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v12, UFG::AttackRightsComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v12, UFG::AttackRightsComponent::_TypeUID);
          v15 = v16;
        }
        if ( v15 )
        {
          if ( p_mTargetAttackRightsComponent->m_pPointer )
          {
            v17 = p_mTargetAttackRightsComponent->mPrev;
            v18 = p_mTargetAttackRightsComponent->mNext;
            v17->mNext = v18;
            v18->mPrev = v17;
            p_mTargetAttackRightsComponent->mPrev = p_mTargetAttackRightsComponent;
            p_mTargetAttackRightsComponent->mNext = p_mTargetAttackRightsComponent;
          }
          p_mTargetAttackRightsComponent->m_pPointer = v15;
          v19 = v15->m_SafePointerList.mNode.mPrev;
          v19->mNext = p_mTargetAttackRightsComponent;
          p_mTargetAttackRightsComponent->mPrev = v19;
          p_mTargetAttackRightsComponent->mNext = &v15->m_SafePointerList.mNode;
          v15->m_SafePointerList.mNode.mPrev = p_mTargetAttackRightsComponent;
          v20 = LOBYTE(v15[149].vfptr) && BYTE1(v15[149].vfptr) && BYTE2(v15[149].vfptr);
          this->mPreviousAttackRights = v20;
          if ( v20 != v13 )
          {
            TargetAttackRightsTask::GetDebugString(this, &result, context);
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
  UFG::SimComponent *m_pPointer; // rax
  bool v3; // al
  char *mData; // rdx
  UFG::SimComponent *v5; // rcx
  bool mPreviousAttackRights; // al
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  if ( BYTE5(this->m_Track[1].vfptr) )
  {
    m_pPointer = this->mTargetAttackRightsComponent.m_pPointer;
    if ( m_pPointer )
    {
      v3 = LOBYTE(m_pPointer[149].vfptr) && BYTE1(m_pPointer[149].vfptr) && BYTE2(m_pPointer[149].vfptr);
      if ( this->mPreviousAttackRights != v3 )
      {
        TargetAttackRightsTask::GetDebugString(this, &result, this->mpContext);
        mData = result.mData;
        v5 = this->mTargetAttackRightsComponent.m_pPointer;
        mPreviousAttackRights = this->mPreviousAttackRights;
        LOBYTE(v5[149].vfptr) = mPreviousAttackRights;
        BYTE1(v5[149].vfptr) = mPreviousAttackRights;
        BYTE2(v5[149].vfptr) = mPreviousAttackRights;
        UFG::qString::Set((UFG::qString *)&v5[161].m_TypeUID, mData);
        UFG::qString::~qString(&result);
      }
    }
  }
}

// File Line: 2144
// RVA: 0x2F6770
void __fastcall TargetGunSetAmmoForAIDeathTask::Begin(TargetGunSetAmmoForAIDeathTask *this, ActionContext *context)
{
  UFG::SimObject *m_pPointer; // rcx
  UFG::SimObjectGame *v5; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v9; // rbx
  __int16 v10; // cx
  UFG::SimComponent *ComponentOfType; // rax
  __int16 v12; // cx
  UFG::GunComponent *v13; // rax

  m_pPointer = context->mSimObject.m_pPointer;
  if ( (m_pPointer->m_Flags & 0x400) == 0 && !UFG::IsAnyLocalPlayer(m_pPointer) )
  {
    v5 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( v5 )
    {
      m_Flags = v5->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = v5->m_Components.p[20].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v5, UFG::TargetingSystemBaseComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      else
      {
        m_pComponent = v5->m_Components.p[20].m_pComponent;
      }
      if ( m_pComponent )
      {
        v9 = *(UFG::SimObjectGame **)(56i64
                                    * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                         + *(_QWORD *)&m_pComponent[1].m_Flags
                                                         + 8i64)
                                    + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                    + 40);
        if ( v9 )
        {
          v10 = v9->m_Flags;
          if ( (v10 & 0x4000) != 0 || v10 < 0 || (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::RigidBodyComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(v9, UFG::RigidBodyComponent::_TypeUID);
          if ( ComponentOfType )
          {
            v12 = v9->m_Flags;
            if ( (v12 & 0x4000) != 0 || v12 < 0 || (v12 & 0x2000) != 0 || (v12 & 0x1000) != 0 )
              v13 = (UFG::GunComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::GunComponent::_TypeUID);
            else
              v13 = (UFG::GunComponent *)UFG::SimObject::GetComponentOfType(v9, UFG::GunComponent::_TypeUID);
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
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rdi
  UFG::SimComponent *v7; // rax
  UFG::SimObjectProp *v8; // rbx
  __int16 v9; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::RigidBody *v11; // rsi
  __int16 v12; // cx
  UFG::SimObjectWeaponPropertiesComponent *ComponentOfType; // rax
  UFG::SimObjectWeaponPropertiesComponent *v14; // rbx
  float mThrownSpeed; // xmm11_4
  float v16; // xmm8_4
  bool v17; // cc
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v18; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  UFG::SimObjectGame *v21; // rcx
  __int16 v22; // dx
  UFG::SimComponent *v23; // rdx
  UFG::SimComponent *v24; // rax
  __m128 mPrev_high; // xmm6
  __m128 mNext_low; // xmm7
  float v27; // xmm10_4
  UFG::qVector3 *p_mThrownWeaponSpinAxis; // rdx
  float x; // xmm12_4
  __m128 y_low; // xmm9
  float z; // xmm13_4
  __m128 v32; // xmm2
  float v33; // xmm15_4
  float v34; // xmm14_4
  __m128 v35; // xmm1
  float v36; // xmm2_4
  __m128 v37; // xmm15
  float v38; // xmm5_4
  float v39; // xmm2_4
  float v40; // xmm4_4
  __m128 v41; // xmm3
  float v42; // xmm3_4
  float v43; // xmm1_4
  float v44; // xmm3_4
  float v45; // xmm4_4
  float v46; // xmm5_4
  float v47; // xmm15_4
  __m128 v48; // xmm0
  float v49; // xmm1_4
  __m128 v50; // xmm2
  float v51; // xmm1_4
  float v52; // xmm10_4
  float v53; // xmm1_4
  float v54; // xmm12_4
  float v55; // xmm9_4
  float v56; // xmm13_4
  float v57; // xmm6_4
  float v58; // xmm0_4
  float v59; // xmm9_4
  float v60; // xmm1_4
  float *p_mSimObjectWeaponType; // rdx
  float RandomNumberInRange; // xmm7_4
  float v63; // xmm6_4
  float v64; // [rsp+20h] [rbp-E0h]
  unsigned int v65; // [rsp+20h] [rbp-E0h]
  UFG::qVector3 vel; // [rsp+28h] [rbp-D8h] BYREF
  float v67; // [rsp+38h] [rbp-C8h]
  float v68; // [rsp+3Ch] [rbp-C4h]
  UFG::qMatrix44 v69; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 v70; // [rsp+80h] [rbp-80h] BYREF
  __int64 v71; // [rsp+90h] [rbp-70h]
  float v72; // [rsp+178h] [rbp+78h]
  float v73; // [rsp+178h] [rbp+78h]
  float v74; // [rsp+180h] [rbp+80h]
  float v75; // [rsp+188h] [rbp+88h]

  v71 = -2i64;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( !m_pPointer )
    return;
  m_Flags = m_pPointer->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  else if ( m_Flags >= 0 )
  {
    v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    m_pComponent = v7;
  }
  else
  {
    m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
  }
  if ( !m_pComponent )
    return;
  v8 = *(UFG::SimObjectProp **)(56i64
                              * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                   + *(_QWORD *)&m_pComponent[1].m_Flags
                                                   + 8i64)
                              + *(_QWORD *)&m_pComponent[1].m_TypeUID
                              + 40);
  if ( !v8 )
    return;
  v9 = v8->m_Flags;
  if ( (v9 & 0x4000) != 0 || v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, UFG::RigidBodyComponent::_TypeUID);
  v11 = (UFG::RigidBody *)ComponentOfTypeHK;
  if ( !ComponentOfTypeHK )
    return;
  v12 = v8->m_Flags;
  if ( (v12 & 0x4000) != 0 || v12 < 0 )
  {
LABEL_27:
    ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                   v8,
                                                                   UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
    goto LABEL_29;
  }
  if ( (v12 & 0x2000) == 0 )
  {
    if ( (v12 & 0x1000) == 0 )
    {
      ComponentOfType = (UFG::SimObjectWeaponPropertiesComponent *)UFG::SimObject::GetComponentOfType(
                                                                     v8,
                                                                     UFG::SimObjectWeaponPropertiesComponent::_TypeUID);
      goto LABEL_29;
    }
    goto LABEL_27;
  }
  ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::SimObjectWeaponPropertiesComponent>(v8);
LABEL_29:
  v14 = ComponentOfType;
  mThrownSpeed = *((float *)&this->m_Track[1].vfptr + 1);
  v16 = 0.0;
  v17 = mThrownSpeed <= 0.0;
  if ( mThrownSpeed < 0.0 )
  {
    UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v69);
    TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v18);
    *(_QWORD *)&v69.v1.x = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
    mCollisionMeshData = v11->mCollisionMeshData;
    if ( mCollisionMeshData )
      UFG::qReflectHandleBase::operator=((UFG::qReflectHandleBase *)&v69, &mCollisionMeshData->mObjectProperties);
    if ( *(_QWORD *)&v69.v2.x && *(float *)(*(_QWORD *)&v69.v2.x + 96i64) > 0.0 )
      mThrownSpeed = *(float *)(*(_QWORD *)&v69.v2.x + 96i64);
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v69);
    v17 = mThrownSpeed <= 0.0;
    if ( mThrownSpeed < 0.0 )
    {
      if ( v14 )
        mThrownSpeed = v14->mWeaponTypeInfo->mFireModes[v14->mFireMode]->mThrownSpeed;
      v17 = mThrownSpeed <= 0.0;
    }
  }
  if ( !v17 )
  {
    v21 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
    if ( v21 )
    {
      v22 = v21->m_Flags;
      if ( (v22 & 0x4000) != 0 )
      {
        v23 = v21->m_Components.p[47].m_pComponent;
      }
      else
      {
        v24 = v22 < 0 || (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0
            ? UFG::SimObjectGame::GetComponentOfTypeHK(v21, UFG::AimingBaseComponent::_TypeUID)
            : UFG::SimObject::GetComponentOfType(v21, UFG::AimingBaseComponent::_TypeUID);
        v23 = v24;
      }
      if ( v23 )
      {
        if ( v14 )
          v14->mLastOwner = pContext->mSimObject.m_pPointer->mNode.mUID;
        if ( *(_QWORD *)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + 30i64)
                       + *(_QWORD *)&m_pComponent[1].m_TypeUID
                       + 40) )
        {
          mPrev_high = (__m128)HIDWORD(v23[1].m_BoundComponentHandles.mNode.mPrev);
          mNext_low = (__m128)LODWORD(v23[1].m_BoundComponentHandles.mNode.mNext);
          v27 = *((float *)&v23[1].m_BoundComponentHandles.mNode.mNext + 1);
        }
        else
        {
          mPrev_high = (__m128)HIDWORD(v23[2].m_SafePointerList.mNode.mPrev);
          mNext_low = (__m128)LODWORD(v23[2].m_SafePointerList.mNode.mNext);
          mPrev_high.m128_f32[0] = (float)(mPrev_high.m128_f32[0] * 20.0) + *(float *)&v23[1].m_pSimObject;
          mNext_low.m128_f32[0] = (float)(mNext_low.m128_f32[0] * 20.0) + *((float *)&v23[1].m_pSimObject + 1);
          v27 = (float)(*((float *)&v23[2].m_SafePointerList.mNode.mNext + 1) * 20.0)
              + *(float *)&v23[1].m_BoundComponentHandles.mNode.mPrev;
        }
        UFG::RigidBody::GetTransform(v11, &v69);
        mPrev_high.m128_f32[0] = mPrev_high.m128_f32[0] - v69.v3.x;
        mNext_low.m128_f32[0] = mNext_low.m128_f32[0] - v69.v3.y;
        if ( v14 )
          p_mThrownWeaponSpinAxis = &v14->mWeaponTypeInfo->mFireModes[v14->mFireMode]->mThrownWeaponSpinAxis;
        else
          p_mThrownWeaponSpinAxis = &UFG::qVector3::msZero;
        x = p_mThrownWeaponSpinAxis->x;
        y_low = (__m128)LODWORD(p_mThrownWeaponSpinAxis->y);
        z = p_mThrownWeaponSpinAxis->z;
        v32 = y_low;
        v32.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(x * x)) + (float)(z * z);
        v33 = _mm_sqrt_ps(v32).m128_f32[0];
        v67 = v33;
        v34 = *(float *)&FLOAT_1_0;
        if ( v33 > 0.1 )
        {
          v35 = mNext_low;
          v35.m128_f32[0] = (float)(mNext_low.m128_f32[0] * mNext_low.m128_f32[0])
                          + (float)(mPrev_high.m128_f32[0] * mPrev_high.m128_f32[0]);
          if ( v35.m128_f32[0] == 0.0 )
            v36 = 0.0;
          else
            v36 = 1.0 / _mm_sqrt_ps(v35).m128_f32[0];
          v37 = mPrev_high;
          v37.m128_f32[0] = mPrev_high.m128_f32[0] * v36;
          v74 = mPrev_high.m128_f32[0] * v36;
          v38 = mNext_low.m128_f32[0] * v36;
          v75 = v38;
          v39 = v36 * 0.0;
          v64 = (float)(v39 * 0.0) - v38;
          v41 = v37;
          v72 = v37.m128_f32[0] - (float)(v39 * 0.0);
          v40 = (float)(v38 * 0.0) - (float)(v37.m128_f32[0] * 0.0);
          v41.m128_f32[0] = (float)((float)(v72 * v72) + (float)(v64 * v64)) + (float)(v40 * v40);
          if ( v41.m128_f32[0] == 0.0 )
            v42 = 0.0;
          else
            v42 = 1.0 / _mm_sqrt_ps(v41).m128_f32[0];
          v43 = v42 * v64;
          v68 = v42 * v64;
          v73 = v42 * v72;
          v44 = v42 * v40;
          v45 = (float)(v44 * v38) - (float)(v73 * v39);
          v46 = (float)(v43 * v39) - (float)(v44 * v37.m128_f32[0]);
          v47 = (float)(v73 * v74) - (float)(v43 * v75);
          *(float *)&v65 = (float)(v46 * v46) + (float)(v45 * v45);
          v48 = (__m128)v65;
          v48.m128_f32[0] = *(float *)&v65 + (float)(v47 * v47);
          if ( v48.m128_f32[0] == 0.0 )
            v49 = 0.0;
          else
            v49 = 1.0 / _mm_sqrt_ps(v48).m128_f32[0];
          v69.v0.x = v74;
          v69.v0.y = v75;
          *(_QWORD *)&v69.v0.z = LODWORD(v39);
          v69.v1.x = v68;
          v69.v1.y = v73;
          *(_QWORD *)&v69.v1.z = LODWORD(v44);
          v69.v2.x = v45 * v49;
          v69.v2.y = v46 * v49;
          *(_QWORD *)&v69.v2.z = COERCE_UNSIGNED_INT(v47 * v49);
          UFG::RigidBody::SetTransform(v11, &v69);
          v33 = v67;
        }
        v50 = mNext_low;
        v50.m128_f32[0] = (float)(mNext_low.m128_f32[0] * mNext_low.m128_f32[0])
                        + (float)(mPrev_high.m128_f32[0] * mPrev_high.m128_f32[0]);
        v51 = _mm_sqrt_ps(v50).m128_f32[0] / mThrownSpeed;
        v52 = (float)((float)(v27 - v69.v3.z)
                    - (float)((float)((float)(UFG::BasePhysicsSystem::mParam.gravity * 0.5) * v51) * v51))
            / v51;
        if ( v50.m128_f32[0] == 0.0 )
          v53 = 0.0;
        else
          v53 = 1.0 / _mm_sqrt_ps(v50).m128_f32[0];
        v70.x = (float)(mPrev_high.m128_f32[0] * v53) * mThrownSpeed;
        v70.y = (float)(mNext_low.m128_f32[0] * v53) * mThrownSpeed;
        v70.z = v52;
        UFG::RigidBody::SetLinearDamping(v11, 0.0);
        UFG::RigidBody::SetVelocity(v11, &v70);
        if ( v33 <= 0.1 )
        {
          v57 = 0.0;
          v58 = 0.0;
          v59 = 0.0;
          v60 = 0.0;
          if ( v14 )
          {
            p_mSimObjectWeaponType = (float *)&v14->mWeaponTypeInfo->mFireModes[v14->mFireMode]->mSimObjectWeaponType;
            v16 = p_mSimObjectWeaponType[43];
            v57 = p_mSimObjectWeaponType[44];
            v58 = p_mSimObjectWeaponType[45];
            v34 = p_mSimObjectWeaponType[46];
            v59 = p_mSimObjectWeaponType[47];
            v60 = p_mSimObjectWeaponType[48];
          }
          RandomNumberInRange = UFG::GetRandomNumberInRange(v58, v60);
          v63 = UFG::GetRandomNumberInRange(v57, v59);
          vel.x = UFG::GetRandomNumberInRange(v16, v34);
          vel.y = v63;
          vel.z = RandomNumberInRange;
        }
        else
        {
          v54 = x * 6.2831855;
          v55 = y_low.m128_f32[0] * 6.2831855;
          v56 = z * 6.2831855;
          vel.x = (float)((float)(v55 * v69.v1.x) + (float)(v54 * v69.v0.x)) + (float)(v56 * v69.v2.x);
          vel.y = (float)((float)(v55 * v69.v1.y) + (float)(v54 * v69.v0.y)) + (float)(v56 * v69.v2.y);
          vel.z = (float)((float)(v55 * v69.v1.z) + (float)(v54 * v69.v0.z)) + (float)(v56 * v69.v2.z);
        }
        UFG::RigidBody::SetAngularVelocity(v11, &vel);
      }
    }
  }
}

// File Line: 2345
// RVA: 0x2F79B0
void __fastcall TargetPhysicalImpulseTask::Begin(TargetPhysicalImpulseTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::RigidBody *v11; // rdi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v12; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  UFG::SimObject *v15; // r14
  UFG::TransformNodeComponent *v16; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r14
  ITrack *m_Track; // rcx
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm6_4
  __int128 v22; // xmm4
  float v23; // xmm5_4
  float v24; // xmm2_4
  __m128 v25; // xmm3
  UFG::SimObject *v26; // rax
  float v27; // xmm2_4
  float v28; // xmm6_4
  float v29; // xmm6_4
  double Mass; // xmm0_8
  UFG::SimObjectGame *v31; // rcx
  __int16 v32; // dx
  UFG::SimComponent *v33; // rax
  float v34; // xmm3_4
  __int128 vfptr_low; // xmm2
  UFG::SimObject *v36; // rax
  float y; // xmm1_4
  float z; // xmm2_4
  __m128 v39; // xmm1
  float v40; // xmm4_4
  double v41; // xmm0_8
  float v42; // xmm6_4
  float v43; // xmm4_4
  UFG::qVector3 vel; // [rsp+8h] [rbp-59h] BYREF
  UFG::qMatrix44 v45; // [rsp+18h] [rbp-49h] BYREF
  UFG::qReflectHandleBase v46; // [rsp+58h] [rbp-9h] BYREF
  __int64 v47; // [rsp+80h] [rbp+1Fh]

  v47 = -2i64;
  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v7 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = v7;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v8 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags
                                                       + LOBYTE(this->m_Track[1].vfptr)
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 & 0x4000) != 0 || v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v8, UFG::RigidBodyComponent::_TypeUID);
        v11 = (UFG::RigidBody *)ComponentOfTypeHK;
        if ( ComponentOfTypeHK )
        {
          UFG::qReflectHandleBase::qReflectHandleBase(&v46);
          TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v12);
          v46.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
          mCollisionMeshData = v11->mCollisionMeshData;
          if ( mCollisionMeshData )
            UFG::qReflectHandleBase::operator=(&v46, &mCollisionMeshData->mObjectProperties);
          if ( !v46.mData || LODWORD(v46.mData[2].mBaseNode.mChildren[1]) == 1 )
            goto LABEL_65;
          v15 = pContext->mSimObject.m_pPointer;
          v16 = 0i64;
          if ( v15 )
            m_pTransformNodeComponent = v15->m_pTransformNodeComponent;
          else
            m_pTransformNodeComponent = 0i64;
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          m_Track = this->m_Track;
          if ( BYTE4(m_Track[1].mResourceOwner) )
          {
            if ( BYTE4(m_Track[1].mResourceOwner) != 1 )
            {
              if ( BYTE4(m_Track[1].mResourceOwner) == 2 )
              {
                v19 = *(float *)&m_Track[1].mBreakPoint;
                v20 = *(float *)&m_Track[1].mMasterRate.text.mOffset;
                LODWORD(vel.x) = m_Track[1].m_TrackClassNameUID;
                vel.y = v19;
                vel.z = v20;
                if ( vel.x != 0.0 || v19 != 0.0 || v20 != 0.0 )
                  UFG::RigidBody::ApplyAngularImpulse(v11, &vel);
              }
              else
              {
                UFG::qString::qString((UFG::qString *)&v45, "TargetPhysicalImpulseTrack: Unsupported direction type!");
                UFG::qString::~qString((UFG::qString *)&v45);
              }
              goto LABEL_65;
            }
            v21 = *(float *)&m_Track[1].m_TrackClassNameUID;
            v22 = *(unsigned int *)&m_Track[1].mBreakPoint;
            v23 = *(float *)&m_Track[1].mMasterRate.text.mOffset;
            vel.x = v21;
            LODWORD(vel.y) = v22;
            vel.z = v23;
            v24 = 0.0;
            if ( v21 == 0.0 && *(float *)&v22 == 0.0 && v23 == 0.0 )
            {
LABEL_65:
              UFG::qReflectHandleBase::~qReflectHandleBase(&v46);
              return;
            }
            v25 = (__m128)v22;
            v25.m128_f32[0] = (float)((float)(*(float *)&v22 * *(float *)&v22) + (float)(v21 * v21))
                            + (float)(v23 * v23);
            if ( v25.m128_f32[0] != 0.0 )
              v24 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
            vel.x = v24 * v21;
            vel.y = v24 * *(float *)&v22;
            vel.z = v24 * v23;
            v26 = pContext->mSimObject.m_pPointer;
            if ( v26 )
              v16 = v26->m_pTransformNodeComponent;
            UFG::TransformNodeComponent::UpdateWorldTransform(v16);
            v27 = (float)((float)(vel.y * v16->mWorldTransform.v1.y) + (float)(vel.x * v16->mWorldTransform.v0.y))
                + (float)(vel.z * v16->mWorldTransform.v2.y);
            v28 = (float)((float)(vel.y * v16->mWorldTransform.v1.z) + (float)(vel.x * v16->mWorldTransform.v0.z))
                + (float)(vel.z * v16->mWorldTransform.v2.z);
            vel.x = (float)((float)(vel.y * v16->mWorldTransform.v1.x) + (float)(vel.x * v16->mWorldTransform.v0.x))
                  + (float)(vel.z * v16->mWorldTransform.v2.x);
            vel.y = v27;
            vel.z = v28;
            v29 = *((float *)&this->m_Track[1].vfptr + 1);
            Mass = UFG::RigidBody::GetMass(v11);
            *(float *)&Mass = *(float *)&Mass * v29;
            vel.x = vel.x * *(float *)&Mass;
            vel.y = vel.y * *(float *)&Mass;
            vel.z = vel.z * *(float *)&Mass;
          }
          else
          {
            v31 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
            if ( !v31 )
              goto LABEL_65;
            v32 = v31->m_Flags;
            if ( (v32 & 0x4000) != 0 )
              v33 = v31->m_Components.p[47].m_pComponent;
            else
              v33 = v32 < 0 || (v32 & 0x2000) != 0 || (v32 & 0x1000) != 0
                  ? UFG::SimObjectGame::GetComponentOfTypeHK(v31, UFG::AimingBaseComponent::_TypeUID)
                  : UFG::SimObject::GetComponentOfType(v31, UFG::AimingBaseComponent::_TypeUID);
            if ( !v33 )
              goto LABEL_65;
            v34 = *((float *)&v33[2].vfptr + 1) - m_pTransformNodeComponent->mWorldTransform.v3.y;
            vfptr_low = LODWORD(v33[2].vfptr);
            *(float *)&vfptr_low = *(float *)&vfptr_low - m_pTransformNodeComponent->mWorldTransform.v3.x;
            LODWORD(vel.x) = vfptr_low;
            vel.y = v34;
            vel.z = 0.0;
            if ( *(float *)&vfptr_low == 0.0 && v34 == 0.0 )
            {
              v36 = pContext->mSimObject.m_pPointer;
              if ( v36 )
                v16 = v36->m_pTransformNodeComponent;
              UFG::TransformNodeComponent::UpdateWorldTransform(v16);
              y = v16->mWorldTransform.v0.y;
              z = v16->mWorldTransform.v0.z;
              vel.x = v16->mWorldTransform.v0.x;
              vel.y = y;
              vel.z = z;
            }
            else
            {
              v39 = (__m128)vfptr_low;
              v39.m128_f32[0] = (float)(*(float *)&vfptr_low * *(float *)&vfptr_low) + (float)(v34 * v34);
              if ( v39.m128_f32[0] == 0.0 )
                v40 = 0.0;
              else
                v40 = 1.0 / _mm_sqrt_ps(v39).m128_f32[0];
              vel.x = *(float *)&vfptr_low * v40;
              vel.y = v40 * v34;
              vel.z = v40 * 0.0;
            }
            v41 = UFG::RigidBody::GetMass(v11);
            vel.x = vel.x * *(float *)&v41;
            vel.y = vel.y * *(float *)&v41;
            vel.z = vel.z * *(float *)&v41;
            UFG::qRotationMatrixY(&v45, *(float *)&this->m_Track[1].mResourceOwner);
            v42 = (float)((float)(v45.v1.y * vel.y) + (float)(v45.v0.y * vel.x)) + (float)(v45.v2.y * vel.z);
            v43 = (float)((float)(v45.v1.z * vel.y) + (float)(v45.v0.z * vel.x)) + (float)(v45.v2.z * vel.z);
            vel.x = (float)((float)(v45.v1.x * vel.y) + (float)(v45.v0.x * vel.x)) + (float)(v45.v2.x * vel.z);
            vel.y = v42;
            vel.z = v43;
            LODWORD(v41) = HIDWORD(this->m_Track[1].vfptr);
            vel.x = vel.x * *(float *)&v41;
            vel.y = v42 * *(float *)&v41;
            vel.z = v43 * *(float *)&v41;
          }
          UFG::RigidBody::ApplyLinearImpulse(v11, &vel);
          goto LABEL_65;
        }
      }
    }
  }
}

// File Line: 2439
// RVA: 0x2F7860
void __fastcall TargetPhysicalDamageTask::Begin(TargetPhysicalDamageTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::StateMachineComponent *vfptr; // rcx

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v8 = *(UFG::SimObjectGame **)(56i64
                                  * *(unsigned __int8 *)(LOBYTE(this->m_Track[1].vfptr)
                                                       + *(_QWORD *)&m_pComponent[1].m_Flags
                                                       + 8i64)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 & 0x4000) != 0 || v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
          ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::RigidBodyComponent::_TypeUID);
        else
          ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::RigidBodyComponent::_TypeUID);
        if ( ComponentOfType )
        {
          vfptr = (UFG::StateMachineComponent *)ComponentOfType[6].vfptr;
          if ( vfptr )
            UFG::StateMachineComponent::ApplyDamage(
              vfptr,
              *(float *)&this->m_Track[1].mResourceOwner,
              SHIDWORD(this->m_Track[1].vfptr),
              pContext->mSimObject.m_pPointer);
        }
      }
    }
  }
}

// File Line: 2466
// RVA: 0x2F9BF0
void __fastcall TargetingProfileSelectTask::Begin(TargetingProfileSelectTask *this, ActionContext *pContext)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // r8
  UFG::SimComponent *m_pComponent; // rax
  UFG::SimObjectGame *v7; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TargetingSystemPedBaseComponent *v10; // rax

  m_pPointer = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      m_pComponent = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      v7 = (UFG::SimObjectGame *)pContext->mSimObject.m_pPointer;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 & 0x4000) != 0 )
        {
          v7 = (UFG::SimObjectGame *)v7->m_Components.p[20].m_pComponent;
        }
        else if ( v8 >= 0 )
        {
          if ( (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  v7,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::TargetingSystemBaseComponent::_TypeUID);
          v7 = (UFG::SimObjectGame *)ComponentOfTypeHK;
        }
        else
        {
          v7 = (UFG::SimObjectGame *)v7->m_Components.p[20].m_pComponent;
        }
      }
      v10 = (UFG::TargetingSystemPedBaseComponent *)((__int64 (__fastcall *)(UFG::SimObjectGame *))v7->vfptr[15].__vecDelDtor)(v7);
      if ( v10 )
        UFG::TargetingSystemPedBaseComponent::SetActiveTargetingProfile(
          v10,
          (UFG::qSymbol *)&this->m_Track[1].vfptr + 1);
    }
  }
}

// File Line: 2481
// RVA: 0x2F9A60
void __fastcall TargetWeaponModeChangeTask::Begin(TargetWeaponModeChangeTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r8
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int64 vfptr_low; // r9
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *ComponentOfType; // rax
  CAkChainCtx *v11; // rdi
  int v12; // esi
  CAkScheduledItem *SimObjectWeaponPropertiesComponent; // rax
  int v14; // ebx

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                              m_pPointer,
                              UFG::TargetingSystemBaseComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      vfptr_low = LOBYTE(this->m_Track[1].vfptr);
      v8 = *(UFG::SimObjectGame **)(56i64 * *(unsigned __int8 *)(*(_QWORD *)&m_pComponent[1].m_Flags + vfptr_low + 8)
                                  + *(_QWORD *)&m_pComponent[1].m_TypeUID
                                  + 40);
      if ( v8 )
      {
        v9 = v8->m_Flags;
        if ( (v9 & 0x400) == 0 && (_DWORD)vfptr_low == 17 )
        {
          if ( (v9 & 0x4000) != 0 || v9 < 0 || (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0 )
            ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::GunComponent::_TypeUID);
          else
            ComponentOfType = UFG::SimObject::GetComponentOfType(v8, UFG::GunComponent::_TypeUID);
          v11 = (CAkChainCtx *)ComponentOfType;
          if ( ComponentOfType )
          {
            v12 = *(_DWORD *)(*(_QWORD *)&UFG::GunComponent::GetSimObjectWeaponPropertiesComponent((CAkChainCtx *)ComponentOfType)[2].m_cmdStop.iRelativeTime
                            + 4i64);
            SimObjectWeaponPropertiesComponent = UFG::GunComponent::GetSimObjectWeaponPropertiesComponent(v11);
            if ( v12 > 1 )
            {
              v14 = SimObjectWeaponPropertiesComponent[2].m_cmdPlay.fadeParams.iFadeOffset + 1;
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
  UFG::eTargetTypeEnum mResourceOwner; // edx
  UFG::SimObject *Target; // rax
  __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *v7; // rdi
  UFG::SimObject *mNext; // rbp
  UFG::InterestPoint *m_pComponent; // rbx
  ITrack *m_Track; // rax
  UFG::SimObject *Parent; // rax
  ITrack *v12; // rcx
  unsigned __int64 v13; // rax
  const char *v14; // rcx
  bool v15; // cc
  ITrack *v16; // rax
  ITrack *v17; // rax
  const char *v18; // rdx
  __int16 v19; // dx
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObjectGame *m_pPointer; // rcx
  UFG::eTargetTypeEnum v22; // ebx
  __int16 v23; // dx
  unsigned int v24; // edx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v26; // zf
  UFG::qSymbol childName; // [rsp+40h] [rbp+8h] BYREF

  mResourceOwner = (UFG::eTargetTypeEnum)this->m_Track[1].mResourceOwner;
  if ( mResourceOwner )
  {
    Target = UFG::getTarget(pActionContext->mSimObject.m_pPointer, mResourceOwner);
    if ( Target )
    {
      m_Flags = Target->m_Flags;
      v7 = 0i64;
      mNext = 0i64;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::InterestPoint *)Target->m_Components.p[25].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
          m_pComponent = (UFG::InterestPoint *)Target->m_Components.p[10].m_pComponent;
        else
          m_pComponent = (UFG::InterestPoint *)((m_Flags & 0x1000) != 0
                                              ? Target->m_Components.p[3].m_pComponent
                                              : UFG::SimObject::GetComponentOfType(Target, UFG::InterestPoint::_TypeUID));
      }
      else
      {
        m_pComponent = (UFG::InterestPoint *)Target->m_Components.p[25].m_pComponent;
      }
      if ( m_pComponent )
      {
        m_Track = this->m_Track;
        if ( LOBYTE(m_Track[1].m_TrackClassNameUID) )
        {
          Parent = UFG::InterestPoint::GetParent(m_pComponent);
        }
        else
        {
          v12 = m_Track + 1;
          v13 = (unsigned __int64)m_Track[1].vfptr & 0xFFFFFFFFFFFFFFFEui64;
          if ( v13 )
            v14 = (char *)v12 + v13;
          else
            v14 = BinString::sEmptyString;
          v15 = (int)UFG::qStringLength(v14) <= 0;
          v16 = this->m_Track;
          if ( v15 )
          {
            Parent = UFG::InterestPoint::GetChild(m_pComponent, HIDWORD(v16[1].mResourceOwner));
          }
          else
          {
            v17 = v16 + 1;
            childName.mUID = -1;
            v18 = (char *)v17 + ((unsigned __int64)v17->vfptr & 0xFFFFFFFFFFFFFFFEui64);
            if ( ((unsigned __int64)v17->vfptr & 0xFFFFFFFFFFFFFFFEui64) == 0 )
              v18 = BinString::sEmptyString;
            UFG::qSymbol::set_from_cstr(&childName, v18);
            Parent = UFG::InterestPoint::GetChild(m_pComponent, &childName);
          }
        }
        if ( Parent )
        {
          if ( BYTE1(this->m_Track[1].m_TrackClassNameUID) )
          {
            v19 = Parent->m_Flags;
            if ( (v19 & 0x4000) != 0 )
            {
              ComponentOfType = Parent->m_Components.p[25].m_pComponent;
            }
            else if ( v19 >= 0 )
            {
              if ( (v19 & 0x2000) != 0 )
              {
                ComponentOfType = Parent->m_Components.p[10].m_pComponent;
              }
              else if ( (v19 & 0x1000) != 0 )
              {
                ComponentOfType = Parent->m_Components.p[3].m_pComponent;
              }
              else
              {
                ComponentOfType = UFG::SimObject::GetComponentOfType(Parent, UFG::InterestPoint::_TypeUID);
              }
            }
            else
            {
              ComponentOfType = Parent->m_Components.p[25].m_pComponent;
            }
            if ( ComponentOfType )
              mNext = (UFG::SimObject *)ComponentOfType[5].m_BoundComponentHandles.mNode.mNext;
          }
          else
          {
            mNext = Parent;
          }
        }
        m_pPointer = (UFG::SimObjectGame *)pActionContext->mSimObject.m_pPointer;
        v22 = *(_DWORD *)&this->m_Track[1].mBreakPoint;
        if ( !m_pPointer )
          goto LABEL_47;
        v23 = m_pPointer->m_Flags;
        if ( (v23 & 0x4000) != 0 || v23 < 0 )
        {
          v7 = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
LABEL_47:
          UFG::TargetingSystemBaseComponent::SetTarget(v7, v22, mNext);
          return;
        }
        if ( (v23 & 0x2000) != 0 )
        {
          v24 = UFG::TargetingSystemBaseComponent::_TypeUID;
        }
        else
        {
          v26 = (v23 & 0x1000) == 0;
          v24 = UFG::TargetingSystemBaseComponent::_TypeUID;
          if ( v26 )
          {
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                  m_pPointer,
                                  UFG::TargetingSystemBaseComponent::_TypeUID);
            goto LABEL_46;
          }
        }
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, v24);
LABEL_46:
        v7 = (UFG::TargetingSystemBaseComponent *)ComponentOfTypeHK;
        goto LABEL_47;
      }
    }
  }
}

// File Line: 2584
// RVA: 0x2E4330
void __fastcall ProxyTargetBaseTask::~ProxyTargetBaseTask(ProxyTargetBaseTask *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemItemComponent> *p_mProxyTargetingSystemComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mProxyTransformNodeComponent; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rax

  p_mProxyTargetingSystemComponent = &this->mProxyTargetingSystemComponent;
  if ( this->mProxyTargetingSystemComponent.m_pPointer )
  {
    mPrev = p_mProxyTargetingSystemComponent->mPrev;
    mNext = p_mProxyTargetingSystemComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mProxyTargetingSystemComponent->mPrev = p_mProxyTargetingSystemComponent;
    p_mProxyTargetingSystemComponent->mNext = p_mProxyTargetingSystemComponent;
  }
  p_mProxyTargetingSystemComponent->m_pPointer = 0i64;
  v5 = p_mProxyTargetingSystemComponent->mPrev;
  v6 = p_mProxyTargetingSystemComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mProxyTargetingSystemComponent->mPrev = p_mProxyTargetingSystemComponent;
  p_mProxyTargetingSystemComponent->mNext = p_mProxyTargetingSystemComponent;
  p_mProxyTransformNodeComponent = &this->mProxyTransformNodeComponent;
  if ( this->mProxyTransformNodeComponent.m_pPointer )
  {
    v8 = p_mProxyTransformNodeComponent->mPrev;
    v9 = this->mProxyTransformNodeComponent.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mProxyTransformNodeComponent->mPrev = p_mProxyTransformNodeComponent;
    this->mProxyTransformNodeComponent.mNext = &this->mProxyTransformNodeComponent;
  }
  this->mProxyTransformNodeComponent.m_pPointer = 0i64;
  v10 = p_mProxyTransformNodeComponent->mPrev;
  v11 = this->mProxyTransformNodeComponent.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mProxyTransformNodeComponent->mPrev = p_mProxyTransformNodeComponent;
  this->mProxyTransformNodeComponent.mNext = &this->mProxyTransformNodeComponent;
  if ( this->mProxySimObject.m_pPointer )
  {
    v12 = this->mProxySimObject.mPrev;
    v13 = this->mProxySimObject.mNext;
    v12->mNext = v13;
    v13->mPrev = v12;
    this->mProxySimObject.mPrev = &this->mProxySimObject;
    this->mProxySimObject.mNext = &this->mProxySimObject;
  }
  this->mProxySimObject.m_pPointer = 0i64;
  v14 = this->mProxySimObject.mPrev;
  v15 = this->mProxySimObject.mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  this->mProxySimObject.mPrev = &this->mProxySimObject;
  this->mProxySimObject.mNext = &this->mProxySimObject;
}

// File Line: 2590
// RVA: 0x3018A0
void __fastcall ProxyTargetBaseTask::GenerateProxySimObject(ProxyTargetBaseTask *this)
{
  unsigned int v2; // eax
  unsigned int v3; // edi
  __int64 v4; // r8
  UFG::qSymbol *v5; // rax
  UFG::SimObject *SimObject; // rax
  UFG::SimObject *v7; // rbp
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mNode; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v13; // rax
  UFG::SimComponent *v14; // r14
  UFG::SimComponent *v15; // rax
  UFG::SimComponent *v16; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::TransformNodeComponent> *p_mProxyTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax
  __int16 m_Flags; // cx
  unsigned int v22; // esi
  UFG::qMemoryPool *v23; // rax
  UFG::allocator::free_link *v24; // rax
  UFG::SimComponent *v25; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::TargetingSystemItemComponent> *p_mProxyTargetingSystemComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v27; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v28; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rax
  __int16 v30; // cx
  UFG::SimObjectModifier v31; // [rsp+30h] [rbp-158h] BYREF
  __int64 v32; // [rsp+50h] [rbp-138h]
  char dest[296]; // [rsp+60h] [rbp-128h] BYREF
  UFG::qSymbol result; // [rsp+190h] [rbp+8h] BYREF
  UFG::allocator::free_link *v35; // [rsp+198h] [rbp+10h]

  v32 = -2i64;
  v2 = _S8_7;
  v3 = -1;
  if ( (_S8_7 & 1) == 0 )
  {
    _S8_7 |= 1u;
    guidTransformNodeComponent = UFG::qStringHash32("TransformNodeComponent", 0xFFFFFFFF);
    v2 = _S8_7;
  }
  if ( (v2 & 2) == 0 )
  {
    _S8_7 = v2 | 2;
    guidTargetingSystemItemComponent = UFG::qStringHash32("TargetingSystemItemComponent", 0xFFFFFFFF);
  }
  v4 = UniqueID++;
  UFG::qSPrintf(dest, "ProxyTarget_%d", v4);
  v5 = UFG::qSymbol::create_from_string(&result, dest);
  SimObject = UFG::Simulation::CreateSimObject(&UFG::gSim, v5);
  v7 = SimObject;
  if ( this->mProxySimObject.m_pPointer )
  {
    mPrev = this->mProxySimObject.mPrev;
    mNext = this->mProxySimObject.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mProxySimObject.mPrev = &this->mProxySimObject;
    this->mProxySimObject.mNext = &this->mProxySimObject;
  }
  this->mProxySimObject.m_pPointer = SimObject;
  if ( SimObject )
  {
    p_mNode = &SimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    v11 = SimObject->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v11->mNext = &this->mProxySimObject;
    this->mProxySimObject.mPrev = v11;
    this->mProxySimObject.mNext = p_mNode;
    p_mNode->mPrev = &this->mProxySimObject;
  }
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v13 = UFG::qMemoryPool::Allocate(
          SimulationMemoryPool,
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
  p_mProxyTransformNodeComponent = &this->mProxyTransformNodeComponent;
  if ( this->mProxyTransformNodeComponent.m_pPointer )
  {
    v18 = p_mProxyTransformNodeComponent->mPrev;
    v19 = this->mProxyTransformNodeComponent.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    p_mProxyTransformNodeComponent->mPrev = p_mProxyTransformNodeComponent;
    this->mProxyTransformNodeComponent.mNext = &this->mProxyTransformNodeComponent;
  }
  this->mProxyTransformNodeComponent.m_pPointer = v16;
  if ( v16 )
  {
    v20 = v16->m_SafePointerList.mNode.mPrev;
    v20->mNext = p_mProxyTransformNodeComponent;
    p_mProxyTransformNodeComponent->mPrev = v20;
    this->mProxyTransformNodeComponent.mNext = &v16->m_SafePointerList.mNode;
    v16->m_SafePointerList.mNode.mPrev = p_mProxyTransformNodeComponent;
  }
  m_Flags = v7->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
  {
    v22 = 2;
  }
  else if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x2000) != 0 )
    {
      v22 = 2;
    }
    else
    {
      v22 = -1;
      if ( (m_Flags & 0x1000) != 0 )
        v22 = 1;
    }
  }
  else
  {
    v22 = 2;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v31, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v31, this->mProxyTransformNodeComponent.m_pPointer, v22);
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
  p_mProxyTargetingSystemComponent = &this->mProxyTargetingSystemComponent;
  if ( this->mProxyTargetingSystemComponent.m_pPointer )
  {
    v27 = p_mProxyTargetingSystemComponent->mPrev;
    v28 = this->mProxyTargetingSystemComponent.mNext;
    v27->mNext = v28;
    v28->mPrev = v27;
    p_mProxyTargetingSystemComponent->mPrev = p_mProxyTargetingSystemComponent;
    this->mProxyTargetingSystemComponent.mNext = &this->mProxyTargetingSystemComponent;
  }
  this->mProxyTargetingSystemComponent.m_pPointer = v14;
  if ( v14 )
  {
    v29 = v14->m_SafePointerList.mNode.mPrev;
    v29->mNext = p_mProxyTargetingSystemComponent;
    p_mProxyTargetingSystemComponent->mPrev = v29;
    this->mProxyTargetingSystemComponent.mNext = &v14->m_SafePointerList.mNode;
    v14->m_SafePointerList.mNode.mPrev = p_mProxyTargetingSystemComponent;
  }
  v30 = v7->m_Flags;
  if ( (v30 & 0x4000) != 0 || v30 < 0 )
    v3 = 20;
  UFG::SimObjectModifier::SimObjectModifier(&v31, v7, 1);
  UFG::SimObjectModifier::AttachComponent(&v31, this->mProxyTargetingSystemComponent.m_pPointer, v3);
  UFG::SimObjectModifier::Close(&v31);
  UFG::SimObjectModifier::~SimObjectModifier(&v31);
}

// File Line: 2633
// RVA: 0x30B860
void __fastcall ProxyTargetBaseTask::UpdateProxySimObjectAsSyncableMatrix(
        ProxyTargetBaseTask *this,
        UFG::qMatrix44 *matProxyTargetXform,
        UFG::qVector3 *vPosition,
        UFG::qVector3 *vSyncDirection,
        UFG::qVector3 *vAlternateSyncDirection)
{
  __int128 y_low; // xmm3
  __m128 x_low; // xmm4
  float z; // xmm5_4
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
  UFG::TransformNodeComponent *m_pPointer; // rcx
  float x; // xmm0_4
  float v21; // xmm2_4
  float v22; // eax
  float v23; // xmm1_4

  y_low = LODWORD(vSyncDirection->y);
  x_low = (__m128)LODWORD(vSyncDirection->x);
  z = vSyncDirection->z;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                      (float)((float)(vSyncDirection->x * UFG::qVector3::msDirUp.x)
                            + (float)(vSyncDirection->y * UFG::qVector3::msDirUp.y))
                    + (float)(z * UFG::qVector3::msDirUp.z)) & _xmm) > 0.99984771 )
  {
    x_low = (__m128)LODWORD(vAlternateSyncDirection->x);
    y_low = LODWORD(vAlternateSyncDirection->y);
    z = vAlternateSyncDirection->z;
  }
  v8 = x_low;
  v8.m128_f32[0] = (float)(x_low.m128_f32[0] * UFG::qVector3::msDirUp.z) - (float)(z * UFG::qVector3::msDirUp.x);
  v9 = (float)(z * UFG::qVector3::msDirUp.y) - (float)(*(float *)&y_low * UFG::qVector3::msDirUp.z);
  v10 = v8;
  *(float *)&y_low = (float)(*(float *)&y_low * UFG::qVector3::msDirUp.x)
                   - (float)(x_low.m128_f32[0] * UFG::qVector3::msDirUp.y);
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v9 * v9))
                  + (float)(*(float *)&y_low * *(float *)&y_low);
  if ( v10.m128_f32[0] == 0.0 )
    v11 = 0.0;
  else
    v11 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  v12 = v8.m128_f32[0] * v11;
  *(float *)&y_low = *(float *)&y_low * v11;
  v13 = v9 * v11;
  v15 = (__m128)y_low;
  v14 = (float)(v12 * UFG::qVector3::msDirUp.z) - (float)(*(float *)&y_low * UFG::qVector3::msDirUp.y);
  v15.m128_f32[0] = (float)(*(float *)&y_low * UFG::qVector3::msDirUp.x) - (float)(v13 * UFG::qVector3::msDirUp.z);
  v17 = v15;
  v16 = (float)(v13 * UFG::qVector3::msDirUp.y) - (float)(v12 * UFG::qVector3::msDirUp.x);
  v17.m128_f32[0] = (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v14 * v14)) + (float)(v16 * v16);
  if ( v17.m128_f32[0] == 0.0 )
    v18 = 0.0;
  else
    v18 = 1.0 / _mm_sqrt_ps(v17).m128_f32[0];
  m_pPointer = (UFG::TransformNodeComponent *)this->mProxyTransformNodeComponent.m_pPointer;
  matProxyTargetXform->v0.w = 0.0;
  matProxyTargetXform->v0.x = v14 * v18;
  matProxyTargetXform->v0.y = v15.m128_f32[0] * v18;
  matProxyTargetXform->v0.z = v16 * v18;
  matProxyTargetXform->v1.x = v13;
  matProxyTargetXform->v1.w = 0.0;
  matProxyTargetXform->v1.y = v12;
  LODWORD(matProxyTargetXform->v1.z) = y_low;
  x = UFG::qVector3::msDirUp.x;
  v21 = UFG::qVector3::msDirUp.z;
  matProxyTargetXform->v2.y = UFG::qVector3::msDirUp.y;
  matProxyTargetXform->v2.w = 0.0;
  matProxyTargetXform->v2.x = x;
  matProxyTargetXform->v2.z = v21;
  v22 = vPosition->x;
  v23 = vPosition->z;
  matProxyTargetXform->v3.y = vPosition->y;
  matProxyTargetXform->v3.x = v22;
  matProxyTargetXform->v3.w = 1.0;
  matProxyTargetXform->v3.z = v23;
  UFG::TransformNodeComponent::SetWorldTransform(m_pPointer, matProxyTargetXform);
}

// File Line: 2672
// RVA: 0x2E0420
void __fastcall ProxyTargetSphereCastTask::ProxyTargetSphereCastTask(ProxyTargetSphereCastTask *this)
{
  ProxyTargetBaseTask *v2; // rcx

  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  this->vfptr = (ITaskVtbl *)&Task<ProxyTargetSphereCastTrack>::`vftable;
  v2 = &this->ProxyTargetBaseTask;
  v2->mProxySimObject.mPrev = &v2->mProxySimObject;
  v2->mProxySimObject.mNext = &v2->mProxySimObject;
  v2->mProxySimObject.m_pPointer = 0i64;
  v2->mProxyTransformNodeComponent.mPrev = &v2->mProxyTransformNodeComponent;
  v2->mProxyTransformNodeComponent.mNext = &v2->mProxyTransformNodeComponent;
  v2->mProxyTransformNodeComponent.m_pPointer = 0i64;
  v2->mProxyTargetingSystemComponent.mPrev = &v2->mProxyTargetingSystemComponent;
  v2->mProxyTargetingSystemComponent.mNext = &v2->mProxyTargetingSystemComponent;
  v2->mProxyTargetingSystemComponent.m_pPointer = 0i64;
  this->vfptr = (ITaskVtbl *)&ProxyTargetSphereCastTask::`vftable;
  this->mRelativeToTransformNodeComponent.mPrev = &this->mRelativeToTransformNodeComponent;
  this->mRelativeToTransformNodeComponent.mNext = &this->mRelativeToTransformNodeComponent;
  this->mRelativeToTransformNodeComponent.m_pPointer = 0i64;
}

// File Line: 2676
// RVA: 0x2E4410
void __fastcall ProxyTargetSphereCastTask::~ProxyTargetSphereCastTask(ProxyTargetSphereCastTask *this)
{
  UFG::qSafePointer<UFG::SimObject,UFG::TransformNodeComponent> *p_mRelativeToTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<ITask,ITask> *v7; // rcx
  UFG::qNode<ITask,ITask> *v8; // rax

  this->vfptr = (ITaskVtbl *)&ProxyTargetSphereCastTask::`vftable;
  p_mRelativeToTransformNodeComponent = &this->mRelativeToTransformNodeComponent;
  if ( this->mRelativeToTransformNodeComponent.m_pPointer )
  {
    mPrev = p_mRelativeToTransformNodeComponent->mPrev;
    mNext = p_mRelativeToTransformNodeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mRelativeToTransformNodeComponent->mPrev = p_mRelativeToTransformNodeComponent;
    p_mRelativeToTransformNodeComponent->mNext = p_mRelativeToTransformNodeComponent;
  }
  p_mRelativeToTransformNodeComponent->m_pPointer = 0i64;
  v5 = p_mRelativeToTransformNodeComponent->mPrev;
  v6 = p_mRelativeToTransformNodeComponent->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mRelativeToTransformNodeComponent->mPrev = p_mRelativeToTransformNodeComponent;
  p_mRelativeToTransformNodeComponent->mNext = p_mRelativeToTransformNodeComponent;
  ProxyTargetBaseTask::~ProxyTargetBaseTask(&this->ProxyTargetBaseTask);
  this->vfptr = (ITaskVtbl *)&ITask::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<ITask,ITask>;
  this->mNext = &this->UFG::qNode<ITask,ITask>;
}

// File Line: 2680
// RVA: 0x2F2220
void __fastcall ProxyTargetSphereCastTask::Begin(ProxyTargetSphereCastTask *this, ActionContext *pContext)
{
  this->mContext = pContext;
  ProxyTargetBaseTask::GenerateProxySimObject(&this->ProxyTargetBaseTask);
}

// File Line: 2688
// RVA: 0x305FF0
char __fastcall ProxyTargetSphereCastTask::Update(ProxyTargetSphereCastTask *this, float fDeltaTime)
{
  ITrack *m_Track; // rax
  __int64 vfptr_low; // r13
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::TargetingSystemBaseComponent *m_pComponent; // rsi
  UFG::SimComponent *v9; // rax
  unsigned int mOffset; // ebx
  int v11; // r12d
  UFG::SimObjectCVBase *v12; // rcx
  __int16 v13; // dx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  Creature *mCreature; // r14
  int BoneID; // edx
  UFG::SimObject *v17; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qMatrix44 *p_mWorldTransform; // rax
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm1
  UFG::qVector4 v22; // xmm0
  ITrack *v23; // r8
  float x; // xmm15_4
  float v25; // xmm8_4
  float v26; // xmm7_4
  UFG::SimObjectCVBase *v27; // r14
  unsigned int value_low; // ebx
  __int16 v29; // cx
  UFG::CharacterAnimationComponent *v30; // rax
  Creature *v31; // r15
  UFG::TransformNodeComponent *v32; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  float v35; // xmm2_4
  ITrack *v36; // rax
  __m128 z_low; // xmm1
  __m128 v38; // xmm2
  float v39; // xmm9_4
  __m128 v40; // xmm3
  float v41; // xmm2_4
  __m128 x_low; // xmm4
  __m128 v43; // xmm5
  float v44; // xmm1_4
  float v45; // xmm5_4
  float v46; // xmm10_4
  float v47; // xmm8_4
  __m128 v48; // xmm4
  __m128 v49; // xmm5
  float v50; // xmm5_4
  float v51; // xmm5_4
  float v52; // xmm10_4
  __m128 v53; // xmm2
  float v54; // xmm6_4
  ITrack *v55; // rax
  float v56; // xmm2_4
  float v57; // xmm8_4
  float v58; // xmm3_4
  float v59; // xmm10_4
  float v60; // xmm11_4
  float v61; // xmm15_4
  float v62; // xmm7_4
  float v63; // xmm6_4
  ITrack *v64; // r8
  __int64 v65; // rdx
  UFG::SimObject *v66; // rbx
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *mNext; // rbx
  int v68; // xmm3_4
  int v69; // xmm1_4
  float v70; // xmm1_4
  float v71; // xmm2_4
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *mPrev; // rsi
  UFG::TransformNodeComponent *v73; // rsi
  UFG::qMatrix44 *v74; // rax
  UFG::qVector4 v75; // xmm2
  UFG::qVector4 v76; // xmm1
  UFG::qVector4 v77; // xmm0
  UFG::qVector3 v78; // [rsp+30h] [rbp-98h] BYREF
  int w_low; // [rsp+3Ch] [rbp-8Ch]
  float start; // [rsp+40h] [rbp-88h] BYREF
  float start_4; // [rsp+44h] [rbp-84h]
  UFG::qVector4 start_8; // [rsp+48h] [rbp-80h] BYREF
  UFG::qVector4 end_8; // [rsp+58h] [rbp-70h] BYREF
  __int64 v84; // [rsp+68h] [rbp-60h]
  UFG::qVector4 v85; // [rsp+70h] [rbp-58h] BYREF
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
  UFG::qMatrix44 result; // [rsp+C8h] [rbp+0h] BYREF
  UFG::ShapeCasterCollector sc; // [rsp+108h] [rbp+40h] BYREF
  UFG::qMatrix44 v99; // [rsp+138h] [rbp+70h] BYREF
  float v100; // [rsp+228h] [rbp+160h]
  float v101; // [rsp+238h] [rbp+170h]
  float v102; // [rsp+240h] [rbp+178h]

  v96 = -2i64;
  if ( !this->mProxySimObject.m_pPointer )
    return 0;
  m_Track = this->m_Track;
  vfptr_low = LOBYTE(m_Track[1].vfptr);
  if ( !LOBYTE(m_Track[1].vfptr) )
    return 0;
  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      v9 = (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::TargetingSystemBaseComponent::_TypeUID);
      m_pComponent = (UFG::TargetingSystemBaseComponent *)v9;
    }
    else
    {
      m_pComponent = (UFG::TargetingSystemBaseComponent *)m_pPointer->m_Components.p[20].m_pComponent;
    }
    if ( m_pComponent )
    {
      mOffset = this->m_Track[1].mMasterRate.expression.mOffset;
      v11 = -1;
      if ( mOffset == -1
        || mOffset == symWorldSpace.mUID
        || mOffset == symLocalSpace.mUID
        || (v12 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer) == 0i64
        || ((v13 = v12->m_Flags, (v13 & 0x4000) != 0) || v13 < 0
          ? (ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v12))
          : (v13 & 0x2000) == 0
          ? ((v13 & 0x1000) == 0
           ? (ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                      v12,
                                                                      UFG::CharacterAnimationComponent::_TypeUID))
           : (ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v12,
                                                                      UFG::CharacterAnimationComponent::_TypeUID)))
          : (ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v12)),
            !ComponentOfType
         || (mCreature = ComponentOfType->mCreature) == 0i64
         || (!mCreature->mPose.mRigHandle.mData
           ? (BoneID = -1)
           : (BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, mOffset)),
             BoneID < 0)) )
      {
        v17 = this->mContext->mSimObject.m_pPointer;
        if ( v17 && (m_pTransformNodeComponent = v17->m_pTransformNodeComponent) != 0i64 )
        {
          UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
          p_mWorldTransform = &m_pTransformNodeComponent->mWorldTransform;
        }
        else
        {
          p_mWorldTransform = &UFG::qMatrix44::msIdentity;
        }
        v20 = p_mWorldTransform->v1;
        v21 = p_mWorldTransform->v2;
        v22 = p_mWorldTransform->v3;
        v84 = *(_QWORD *)&p_mWorldTransform->v0.z;
        v85 = v20;
        start_8 = v21;
        end_8 = v22;
      }
      else
      {
        Creature::GetTransform(mCreature, BoneID, (UFG::qMatrix44 *)&end_8.z);
      }
      v23 = this->m_Track;
      x = *(float *)&v23[1].mBreakPoint;
      v25 = *(float *)&v23[1].mMasterRate.text.mOffset;
      v100 = v25;
      v26 = *((float *)&v23[1].mMasterRate.text.mOffset + 1);
      v102 = v26;
      if ( BYTE4(v23[1].mMasterRate.expression.mOffset) )
      {
        v27 = (UFG::SimObjectCVBase *)m_pComponent->m_pTargets[(unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[BYTE4(v23[1].mMasterRate.expression.mOffset)]].m_pTarget.m_pPointer;
        if ( v27 )
        {
          value_low = LODWORD(v23[1].mMasterRate.value);
          if ( value_low == -1 || value_low == symWorldSpace.mUID || value_low == symLocalSpace.mUID )
            goto LABEL_58;
          v29 = v27->m_Flags;
          if ( (v29 & 0x4000) != 0 || v29 < 0 )
          {
            v30 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v27);
          }
          else if ( (v29 & 0x2000) != 0 )
          {
            v30 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v27);
          }
          else
          {
            v30 = (UFG::CharacterAnimationComponent *)((v29 & 0x1000) != 0
                                                     ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v27,
                                                         UFG::CharacterAnimationComponent::_TypeUID)
                                                     : UFG::SimObject::GetComponentOfType(
                                                         v27,
                                                         UFG::CharacterAnimationComponent::_TypeUID));
          }
          if ( !v30 )
            goto LABEL_58;
          v31 = v30->mCreature;
          if ( !v31 )
            goto LABEL_58;
          if ( v31->mPose.mRigHandle.mData )
            v11 = Skeleton::GetBoneID(v31->mPose.mRigHandle.mUFGSkeleton, value_low);
          if ( v11 < 0 )
          {
LABEL_58:
            v32 = v27->m_pTransformNodeComponent;
            if ( v32 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v27->m_pTransformNodeComponent);
              y = v32->mWorldTransform.v3.y;
              z = v32->mWorldTransform.v3.z;
              v78.x = v32->mWorldTransform.v3.x;
              v78.y = y;
              v78.z = z;
              w_low = 1065353216;
            }
            else
            {
              v78.x = UFG::qVector4::msZero.x;
              v78.y = UFG::qVector4::msZero.y;
              v78.z = UFG::qVector4::msZero.z;
              w_low = LODWORD(UFG::qVector4::msZero.w);
            }
            x = v78.x;
            v25 = v78.y;
            v26 = v78.z;
          }
          else
          {
            Creature::GetTransform(v31, v11, &result);
            x = result.v3.x;
            v25 = result.v3.y;
            v26 = result.v3.z;
          }
        }
        UFG::qInverseAffine((UFG::qMatrix44 *)&v85.z, (UFG::qMatrix44 *)&end_8.z);
        v35 = (float)((float)((float)(x * v85.w) + (float)(v25 * v88)) + (float)(v26 * v91)) + v94;
        v102 = (float)((float)((float)(x * v86) + (float)(v25 * v89)) + (float)(v26 * v92)) + v95;
        x = (float)((float)((float)(x * v85.z) + (float)(v25 * v87)) + (float)(v26 * v90)) + v93;
        v100 = v35;
      }
      v36 = this->m_Track;
      if ( *((_BYTE *)&v36[1].mMasterRate.value + 4) )
      {
        z_low = (__m128)LODWORD(end_8.z);
        z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(end_8.w * end_8.w);
        if ( z_low.m128_f32[0] == 0.0 )
        {
          v38 = 0i64;
        }
        else
        {
          v38 = (__m128)(unsigned int)FLOAT_1_0;
          v38.m128_f32[0] = 1.0 / _mm_sqrt_ps(z_low).m128_f32[0];
        }
        v39 = v38.m128_f32[0] * 0.0;
        v40 = v38;
        v40.m128_f32[0] = v38.m128_f32[0] * end_8.w;
        v41 = v38.m128_f32[0] * end_8.z;
        *(_QWORD *)&end_8.z = __PAIR64__(v40.m128_u32[0], LODWORD(v41));
        v84 = LODWORD(v39);
        x_low = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
        x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                                  + (float)(UFG::qVector3::msDirUp.y * UFG::qVector3::msDirUp.y))
                          + (float)(UFG::qVector3::msDirUp.z * UFG::qVector3::msDirUp.z);
        if ( x_low.m128_f32[0] == 0.0 )
        {
          v43 = 0i64;
        }
        else
        {
          v43 = (__m128)(unsigned int)FLOAT_1_0;
          v43.m128_f32[0] = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
        }
        v44 = v43.m128_f32[0] * UFG::qVector3::msDirUp.z;
        v48 = v43;
        v48.m128_f32[0] = v43.m128_f32[0] * UFG::qVector3::msDirUp.y;
        v45 = v43.m128_f32[0] * UFG::qVector3::msDirUp.x;
        v46 = (float)(v45 * v40.m128_f32[0]) - (float)(v41 * v48.m128_f32[0]);
        v47 = (float)(v41 * v44) - (float)(v45 * v39);
        v48.m128_f32[0] = (float)(v48.m128_f32[0] * v39) - (float)(v44 * v40.m128_f32[0]);
        v49 = v48;
        v49.m128_f32[0] = (float)((float)(v48.m128_f32[0] * v48.m128_f32[0]) + (float)(v47 * v47)) + (float)(v46 * v46);
        if ( v49.m128_f32[0] == 0.0 )
          v50 = 0.0;
        else
          v50 = 1.0 / _mm_sqrt_ps(v49).m128_f32[0];
        v85.x = v48.m128_f32[0] * v50;
        v85.y = v47 * v50;
        v85.z = v50 * v46;
        v85.w = 0.0;
        v51 = (float)(v41 * (float)(v47 * v50)) - (float)(v40.m128_f32[0] * (float)(v48.m128_f32[0] * v50));
        v52 = (float)(v39 * v85.x) - (float)(v41 * v85.z);
        v40.m128_f32[0] = (float)(v40.m128_f32[0] * v85.z) - (float)(v39 * v85.y);
        v53 = v40;
        v53.m128_f32[0] = (float)((float)(v40.m128_f32[0] * v40.m128_f32[0]) + (float)(v52 * v52)) + (float)(v51 * v51);
        if ( v53.m128_f32[0] == 0.0 )
          v54 = 0.0;
        else
          v54 = 1.0 / _mm_sqrt_ps(v53).m128_f32[0];
        start_8.x = v40.m128_f32[0] * v54;
        start_8.y = v54 * v52;
        start_8.z = v54 * v51;
        start_8.w = 0.0;
        end_8.w = 1.0;
      }
      UFG::ShapeCasterCollector::ShapeCasterCollector(
        &sc,
        *((float *)&v36[1].vfptr + 1),
        LODWORD(v36[1].mTimeBegin),
        PhantomBehaviour_Simple);
      v55 = this->m_Track;
      v101 = *(float *)&v55[1].mResourceOwner;
      v56 = *((float *)&v55[1].mResourceOwner + 1);
      v57 = *(float *)&v55[1].m_TrackClassNameUID;
      *(float *)&v84 = (float)((float)((float)(v56 * v85.x) + (float)(v101 * end_8.z)) + (float)(v57 * start_8.x))
                     + end_8.x;
      v58 = (float)((float)((float)(v56 * v85.y) + (float)(v101 * end_8.w)) + (float)(v57 * start_8.y)) + end_8.y;
      v101 = (float)((float)((float)(v101 * *(float *)&v84) + (float)(v56 * v85.z)) + (float)(v57 * start_8.z))
           + end_8.z;
      v85.x = v100 * v85.x;
      v59 = (float)((float)(v85.x + (float)(x * end_8.z)) + (float)(v102 * start_8.x)) + end_8.x;
      v60 = (float)((float)((float)(v100 * v85.y) + (float)(x * end_8.w)) + (float)(v102 * start_8.y)) + end_8.y;
      v61 = (float)((float)((float)(x * *(float *)&v84) + (float)(v100 * v85.z)) + (float)(v102 * start_8.z)) + end_8.z;
      *(_QWORD *)&start_8.z = __PAIR64__(LODWORD(v60), LODWORD(v59));
      end_8.x = v61;
      v62 = *(float *)&v84;
      start = *(float *)&v84;
      start_4 = v58;
      v63 = v101;
      start_8.x = v101;
      UFG::BasePhysicsSystem::CastShape(
        UFG::BasePhysicsSystem::mInstance,
        &sc,
        (UFG::qVector3 *)&start,
        (UFG::qVector3 *)&start_8.z);
      v64 = this->m_Track;
      if ( LOBYTE(v64[1].mTimeEnd)
        && (v65 = (__int64)&m_pComponent->m_pTargets[(unsigned __int8)m_pComponent->m_pTargetingMap->m_Map.p[vfptr_low]],
            *(_QWORD *)(v65 + 40))
        && *(_BYTE *)(v65 + 49) )
      {
        if ( BYTE1(v64[1].mTimeEnd) )
        {
          v66 = this->mRelativeToTransformNodeComponent.m_pPointer;
          if ( v66 )
          {
            UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->mRelativeToTransformNodeComponent.m_pPointer);
            UFG::qMatrix44::operator*(&this->mLocalTransform, &result, (UFG::qMatrix44 *)&v66[1]);
            UFG::TransformNodeComponent::SetWorldTransform(
              (UFG::TransformNodeComponent *)this->mProxyTransformNodeComponent.m_pPointer,
              &result);
          }
        }
      }
      else
      {
        mNext = sc.mHitList.mNode.mNext;
        if ( (UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *)sc.mHitList.mNode.mNext == &sc.mHitList
          || !sc.mHitList.mNode.mNext )
        {
          UFG::TargetingSystemBaseComponent::ClearTarget(m_pComponent, (UFG::eTargetTypeEnum)vfptr_low);
        }
        else
        {
          start = v59 - v62;
          start_4 = v60 - v58;
          start_8.x = v61 - v63;
          v68 = HIDWORD(sc.mHitList.mNode.mNext[2].mPrev) ^ _xmm[0];
          v69 = LODWORD(sc.mHitList.mNode.mNext[2].mPrev) ^ _xmm[0];
          LODWORD(start_8.z) = HIDWORD(sc.mHitList.mNode.mNext[1].mNext) ^ _xmm[0];
          LODWORD(start_8.w) = v69;
          LODWORD(end_8.x) = v68;
          v70 = *((float *)&sc.mHitList.mNode.mNext[1].mPrev + 1);
          v71 = *(float *)&sc.mHitList.mNode.mNext[1].mNext;
          v78.x = *(float *)&sc.mHitList.mNode.mNext[1].mPrev;
          v78.y = v70;
          v78.z = v71;
          ProxyTargetBaseTask::UpdateProxySimObjectAsSyncableMatrix(
            &this->ProxyTargetBaseTask,
            (UFG::qMatrix44 *)&v85.z,
            &v78,
            (UFG::qVector3 *)&start_8.z,
            (UFG::qVector3 *)&start);
          UFG::TargetingSystemBaseComponent::SetTarget(
            m_pComponent,
            (UFG::eTargetTypeEnum)vfptr_low,
            this->mProxySimObject.m_pPointer);
          mPrev = mNext[5].mPrev;
          if ( mPrev )
          {
            if ( BYTE1(this->m_Track[1].mTimeEnd) )
            {
              v73 = (UFG::TransformNodeComponent *)mPrev[5].mNext;
              if ( v73 )
              {
                UFG::qSafePointer<Creature,Creature>::operator=(
                  (UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *)&this->mRelativeToTransformNodeComponent,
                  v73);
                UFG::TransformNodeComponent::UpdateWorldTransform(v73);
                UFG::qInverseAffine(&result, &v73->mWorldTransform);
                v74 = UFG::qMatrix44::operator*((UFG::qMatrix44 *)&v85.z, &v99, &result);
                v75 = v74->v1;
                v76 = v74->v2;
                v77 = v74->v3;
                this->mLocalTransform.v0 = v74->v0;
                this->mLocalTransform.v1 = v75;
                this->mLocalTransform.v2 = v76;
                this->mLocalTransform.v3 = v77;
              }
            }
            UFG::TargetingSystemBaseComponent::SetTarget(
              (UFG::TargetingSystemBaseComponent *)this->mProxyTargetingSystemComponent.m_pPointer,
              eTARGET_TYPE_INTERACTION_POINT1,
              (UFG::SimObject *)mNext[5].mPrev);
          }
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

