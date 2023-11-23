// File Line: 35
// RVA: 0x2F2DF0
void __fastcall RagdollTask::Begin(RagdollTask *this, ActionContext *context)
{
  ITrack *m_Track; // rcx
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  ITrack *v6; // rdx
  int vfptr; // eax
  UFG::SimObjectCVBase *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rcx
  float v12; // eax

  this->mContext = context;
  this->mTrackingBlendWeight = 1.0;
  m_Track = this->m_Track;
  if ( LOBYTE(m_Track[1].mResourceOwner) )
  {
    v4 = UFG::RagdollComponent::Acquire(context->mSimObject.m_pPointer);
    v5 = v4;
    if ( v4 )
    {
      v6 = this->m_Track;
      this->mTrackingBlendWeight = *(float *)&v4[2].vfptr;
      vfptr = (int)v6[1].vfptr;
      if ( vfptr )
      {
        if ( vfptr == 1 )
        {
          HIDWORD(v5[2].m_SafePointerList.mNode.mPrev) = 1;
          LODWORD(v5[2].vfptr) = 1065353216;
        }
      }
      else
      {
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
          if ( ComponentOfTypeHK )
          {
            mCreature = ComponentOfTypeHK->mCreature;
            if ( mCreature )
              Creature::MakeUpright(mCreature, *((float *)&this->m_Track[1].vfptr + 1));
          }
        }
        v12 = *(float *)&v5[2].vfptr;
        HIDWORD(v5[2].m_SafePointerList.mNode.mPrev) = 0;
        this->mTrackingBlendWeight = v12;
      }
    }
    ((void (__fastcall *)(RagdollTask *))this->vfptr->Update)(this);
  }
  else
  {
    UFG::RagdollComponent::Release(context->mSimObject.m_pPointer, BYTE1(m_Track[1].mResourceOwner) != 0);
    ((void (__fastcall *)(RagdollTask *))this->vfptr->Update)(this);
  }
}

// File Line: 90
// RVA: 0x149CC50
__int64 dynamic_initializer_for__g_symBip01Pelvis__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Pelvis", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&g_symBip01Pelvis, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__g_symBip01Pelvis__);
}

// File Line: 97
// RVA: 0x149CAA0
__int64 dynamic_initializer_for__g_limbs__()
{
  UFG::qSymbolUC::create_from_string(g_limbs, "Bip01 Pelvis");
  UFG::qSymbolUC::create_from_string(&stru_1423B6474, "Bip01 R Thigh");
  UFG::qSymbolUC::create_from_string(&stru_1423B6478, "Bip01 Spine");
  UFG::qSymbolUC::create_from_string(&stru_1423B647C, "Bip01 Spine1");
  UFG::qSymbolUC::create_from_string(&stru_1423B6480, "Bip01 Spine2");
  UFG::qSymbolUC::create_from_string(&stru_1423B6484, "Bip01 Spine3");
  UFG::qSymbolUC::create_from_string(&stru_1423B6488, "Bip01 Neck");
  UFG::qSymbolUC::create_from_string(&stru_1423B648C, "Bip01 L Thigh");
  UFG::qSymbolUC::create_from_string(&stru_1423B6490, "Bip01 R Calf");
  UFG::qSymbolUC::create_from_string(&stru_1423B6494, "Bip01 Head");
  UFG::qSymbolUC::create_from_string(&stru_1423B6498, "Bip01 L Clavicle");
  UFG::qSymbolUC::create_from_string(&stru_1423B649C, "Bip01 R Clavicle");
  UFG::qSymbolUC::create_from_string(&stru_1423B64A0, "Bip01 L UpperArm");
  UFG::qSymbolUC::create_from_string(&stru_1423B64A4, "Bip01 R UpperArm");
  UFG::qSymbolUC::create_from_string(&stru_1423B64A8, "Bip01 L Calf");
  UFG::qSymbolUC::create_from_string(&stru_1423B64AC, "Bip01 L Forearm");
  UFG::qSymbolUC::create_from_string(&stru_1423B64B0, "Bip01 R Foot");
  UFG::qSymbolUC::create_from_string(&stru_1423B64B4, "Bip01 R Forearm");
  UFG::qSymbolUC::create_from_string(&stru_1423B64B8, "Bip01 L Foot");
  UFG::qSymbolUC::create_from_string(&stru_1423B64BC, "Bip01 L Hand");
  UFG::qSymbolUC::create_from_string(&stru_1423B64C0, "Bip01 R Hand");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__g_limbs__);
}

// File Line: 142
// RVA: 0x307B20
char __fastcall RagdollTask::Update(RagdollTask *this, float timeDelta)
{
  float v4; // xmm7_4
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // r14
  UFG::SimComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **p_mNext; // rbp
  int i; // r15d
  int BoneID; // edi
  UFG::SimObjectCVBase *v15; // rcx
  __int16 v16; // dx
  UFG::CharacterAnimationComponent *v17; // rax
  UFG::CharacterAnimationComponent *v18; // rbx
  Creature *mCreature; // rcx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v20; // rcx
  const char *TypeName; // rax
  __int64 mTypeUID_low; // rax
  Creature *v23; // rcx
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  float mTrackingBlendWeight; // xmm0_4
  UFG::qVector3 impulse; // [rsp+28h] [rbp-80h] BYREF
  UFG::qReflectHandleBase v30; // [rsp+38h] [rbp-70h] BYREF

  v4 = *((float *)&this->m_Track[1].mResourceOwner + 1);
  if ( v4 != 0.0 && !this->mFired )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[42].m_pComponent;
      }
      else
      {
        v8 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
        m_pComponent = v8;
      }
      if ( m_pComponent )
      {
        if ( LODWORD(m_pComponent[2].m_SafePointerList.mNode.mPrev) == 1 )
        {
          v9 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
          if ( v9 )
          {
            v10 = v9->m_Flags;
            if ( (v10 & 0x4000) != 0 )
            {
              v11 = v9->m_Components.p[15].m_pComponent;
            }
            else if ( v10 >= 0 )
            {
              v11 = (v10 & 0x2000) != 0 || (v10 & 0x1000) != 0
                  ? UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::HitReactionComponent::_TypeUID)
                  : UFG::SimObject::GetComponentOfType(v9, UFG::HitReactionComponent::_TypeUID);
            }
            else
            {
              v11 = v9->m_Components.p[15].m_pComponent;
            }
            if ( v11 )
            {
              p_mNext = &v11[2].m_BoundComponentHandles.mNode.mNext;
              for ( i = *(_DWORD *)&v11[7].m_Flags; i > 0; --i )
              {
                BoneID = 1;
                v15 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
                if ( v15 )
                {
                  v16 = v15->m_Flags;
                  if ( (v16 & 0x4000) != 0 || v16 < 0 )
                  {
                    v17 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v15);
                  }
                  else if ( (v16 & 0x2000) != 0 )
                  {
                    v17 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v15);
                  }
                  else
                  {
                    v17 = (UFG::CharacterAnimationComponent *)((v16 & 0x1000) != 0
                                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 v15,
                                                                 UFG::CharacterAnimationComponent::_TypeUID)
                                                             : UFG::SimObject::GetComponentOfType(
                                                                 v15,
                                                                 UFG::CharacterAnimationComponent::_TypeUID));
                  }
                  v18 = v17;
                  if ( v17 )
                  {
                    mCreature = v17->mCreature;
                    if ( mCreature )
                    {
                      if ( mCreature->mPose.mRigHandle.mData )
                        BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, g_symBip01Pelvis.mUID);
                      else
                        BoneID = -1;
                      UFG::qReflectHandleBase::qReflectHandleBase(&v30);
                      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v20);
                      v30.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
                      UFG::qReflectHandleBase::Init(&v30, v30.mTypeUID, (unsigned __int64)p_mNext[21]);
                      if ( v30.mData )
                      {
                        mTypeUID_low = LODWORD(v30.mData[2].mTypeUID);
                        if ( (_DWORD)mTypeUID_low != -1 )
                        {
                          v23 = v18->mCreature;
                          if ( v23->mPose.mRigHandle.mData )
                            BoneID = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, g_limbs[mTypeUID_low].mUID);
                          else
                            BoneID = -1;
                        }
                      }
                      UFG::qReflectHandleBase::~qReflectHandleBase(&v30);
                    }
                  }
                }
                v24 = v4 * *((float *)p_mNext + 55);
                v25 = v4 * *((float *)p_mNext + 54);
                impulse.x = v4 * *((float *)p_mNext + 53);
                impulse.y = v25;
                impulse.z = v24;
                UFG::RagdollComponent::ApplyImpulse(
                  (UFG::RagdollComponent *)m_pComponent,
                  BoneID,
                  (UFG::qVector3 *)(p_mNext + 25),
                  &impulse);
                this->mFired = 1;
                if ( p_mNext[36] )
                  p_mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)p_mNext[36];
              }
            }
          }
        }
      }
    }
  }
  v26 = *((float *)&this->m_Track[1].vfptr + 1);
  if ( v26 > 0.0 )
  {
    mTrackingBlendWeight = this->mTrackingBlendWeight;
    if ( mTrackingBlendWeight >= 0.0 )
      this->mTrackingBlendWeight = mTrackingBlendWeight - (float)(timeDelta / v26);
  }
  if ( this->mTrackingBlendWeight < 0.0 )
    this->mTrackingBlendWeight = 0.0;
  RagdollTask::handleVelocityTracking(this);
  return 1;
}

// File Line: 216
// RVA: 0x2FFEF0
void __fastcall RagdollTask::End(RagdollTask *this)
{
  this->mTrackingBlendWeight = 0.0;
  RagdollTask::handleVelocityTracking(this);
}

// File Line: 222
// RVA: 0x30DCE0
void __fastcall RagdollTask::handleVelocityTracking(RagdollTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  if ( LOBYTE(this->m_Track[1].mResourceOwner) )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[42].m_pComponent;
      }
      else
      {
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      if ( m_pComponent && !LODWORD(this->m_Track[1].vfptr) )
      {
        *(float *)&m_pComponent[2].vfptr = this->mTrackingBlendWeight;
        if ( this->mTrackingBlendWeight == 0.0 )
          HIDWORD(m_pComponent[2].m_SafePointerList.mNode.mPrev) = 0;
      }
    }
  }
}

// File Line: 246
// RVA: 0x2F2B50
void __fastcall RagdollCollisionTask::Begin(RagdollCollisionTask *this, ActionContext *context)
{
  UFG::RagdollComponent *v2; // rax

  this->mContext = context;
  v2 = (UFG::RagdollComponent *)UFG::RagdollComponent::Acquire(context->mSimObject.m_pPointer);
  if ( v2 )
    UFG::RagdollComponent::SetCollisionState(v2, CS_KEYFRAMED_RAGDOLL_LAYER);
}

// File Line: 260
// RVA: 0x2FFE20
void __fastcall RagdollCollisionTask::End(RagdollCollisionTask *this)
{
  UFG::RagdollComponent *v1; // rax

  v1 = (UFG::RagdollComponent *)UFG::RagdollComponent::Acquire(this->mContext->mSimObject.m_pPointer);
  if ( v1 )
    UFG::RagdollComponent::SetCollisionState(v1, CS_KEYFRAMED_RAGDOLL_LAYER_2);
}

// File Line: 279
// RVA: 0x307870
bool __fastcall RagdollImpulseTask::Update(RagdollImpulseTask *this, float __formal)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rbx
  UFG::RagdollComponent *ComponentOfTypeHK; // rax
  UFG::SimObjectCVBase *v7; // rcx
  __int16 v8; // dx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r15
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  Creature *mCreature; // rsi
  int BoneID; // r14d
  float *m_Track; // rax
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 dest; // [rsp+20h] [rbp-A8h] BYREF
  UFG::qVector3 source; // [rsp+30h] [rbp-98h] BYREF
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-88h] BYREF

  if ( !this->mFired )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
      }
      else
      {
        if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         m_pPointer,
                                                         UFG::RagdollComponent::_TypeUID);
        else
          ComponentOfTypeHK = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                                         m_pPointer,
                                                         UFG::RagdollComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
      if ( m_pComponent )
      {
        if ( m_pComponent->mPoseState <= (unsigned int)STATE_POWERED_TRACKING )
        {
          v7 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
          if ( v7 )
          {
            v8 = v7->m_Flags;
            m_pTransformNodeComponent = v7->m_pTransformNodeComponent;
            if ( (v8 & 0x4000) != 0 || v8 < 0 )
            {
              ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v7);
            }
            else if ( (v8 & 0x2000) != 0 )
            {
              ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v7);
            }
            else if ( (v8 & 0x1000) != 0 )
            {
              ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v7,
                                                                      UFG::CharacterAnimationComponent::_TypeUID);
            }
            else
            {
              ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                      v7,
                                                                      UFG::CharacterAnimationComponent::_TypeUID);
            }
            if ( ComponentOfType )
            {
              mCreature = ComponentOfType->mCreature;
              if ( mCreature )
              {
                if ( mCreature->mPose.mRigHandle.mData )
                  BoneID = Skeleton::GetBoneID(
                             mCreature->mPose.mRigHandle.mUFGSkeleton,
                             HIDWORD(this->m_Track[1].mResourceOwner));
                else
                  BoneID = -1;
                m_Track = (float *)this->m_Track;
                v14 = m_Track[14];
                v15 = m_Track[15];
                v16 = m_Track[16];
                UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                y = m_pTransformNodeComponent->mWorldTransform.v0.y;
                source.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
                z = m_pTransformNodeComponent->mWorldTransform.v0.z;
                source.y = y;
                source.z = z;
                UFG::qRotateVectorZ(&dest, &source, (float)(v14 * 3.1415927) * 0.0055555557);
                dest.z = v16 * v15;
                LODWORD(dest.x) = COERCE_UNSIGNED_INT(dest.x * v15) ^ _xmm[0];
                LODWORD(dest.y) = COERCE_UNSIGNED_INT(dest.y * v15) ^ _xmm[0];
                Creature::GetTransform(mCreature, BoneID, &transform);
                UFG::RagdollComponent::ApplyImpulse(m_pComponent, BoneID, (UFG::qVector3 *)&transform.v3, &dest);
                this->mFired = 1;
              }
            }
          }
        }
      }
    }
  }
  return !this->mFired;
}

// File Line: 348
// RVA: 0x306A50
bool __fastcall RagdollAngularImpulseTask::Update(RagdollAngularImpulseTask *this, float __formal)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rsi
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  UFG::CharacterAnimationComponent *v8; // rdi
  __int16 v9; // dx
  UFG::CharacterAnimationComponent *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::CharacterPhysicsComponent *v12; // rax
  __int16 v13; // dx
  Creature *mCreature; // r14
  float v15; // xmm6_4
  __int128 x_low; // xmm2
  __int128 z_low; // xmm4
  __m128 v18; // xmm5
  float v19; // xmm1_4
  float y; // xmm3_4
  UFG::SimObject *v21; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  ITrack *m_Track; // rax
  float v24; // xmm8_4
  float v25; // xmm15_4
  float v26; // xmm5_4
  float v27; // xmm9_4
  float v28; // xmm10_4
  float v29; // xmm12_4
  float v30; // xmm13_4
  __m128 v31; // xmm11
  float v32; // xmm7_4
  __m128 v33; // xmm0
  float v34; // xmm5_4
  __m128 v35; // xmm5
  float v36; // xmm9_4
  __m128 v37; // xmm5
  float v38; // xmm10_4
  int BoneID; // eax
  float v41; // [rsp+20h] [rbp-F8h]
  UFG::qVector3 impulse; // [rsp+28h] [rbp-F0h] BYREF
  UFG::qVector3 result; // [rsp+38h] [rbp-E0h] BYREF
  float v44; // [rsp+120h] [rbp+8h]
  float v45; // [rsp+130h] [rbp+18h]
  float v46; // [rsp+138h] [rbp+20h]

  if ( !this->mFired )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[42].m_pComponent;
      }
      else
      {
        v6 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
        m_pComponent = v6;
      }
      if ( m_pComponent && LODWORD(m_pComponent[2].m_SafePointerList.mNode.mPrev) <= 1 )
      {
        v7 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
        if ( v7 )
        {
          v9 = v7->m_Flags;
          if ( (v9 & 0x4000) != 0 || v9 < 0 )
          {
            v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v7);
          }
          else if ( (v9 & 0x2000) != 0 )
          {
            v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v7);
          }
          else
          {
            v10 = (UFG::CharacterAnimationComponent *)((v9 & 0x1000) != 0
                                                     ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                         v7,
                                                         UFG::CharacterAnimationComponent::_TypeUID)
                                                     : UFG::SimObject::GetComponentOfType(
                                                         v7,
                                                         UFG::CharacterAnimationComponent::_TypeUID));
          }
          v8 = v10;
        }
        else
        {
          v8 = 0i64;
        }
        v11 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
        if ( v11 )
        {
          v13 = v11->m_Flags;
          if ( (v13 & 0x4000) != 0 )
            v12 = (UFG::CharacterPhysicsComponent *)v11->m_Components.p[27].m_pComponent;
          else
            v12 = (UFG::CharacterPhysicsComponent *)(v13 < 0 || (v13 & 0x2000) != 0 || (v13 & 0x1000) != 0
                                                   ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       v11,
                                                       UFG::CharacterPhysicsComponent::_TypeUID)
                                                   : UFG::SimObject::GetComponentOfType(
                                                       v11,
                                                       UFG::CharacterPhysicsComponent::_TypeUID));
        }
        else
        {
          v12 = 0i64;
        }
        if ( v8 )
        {
          if ( v12 )
          {
            mCreature = v8->mCreature;
            if ( mCreature )
            {
              UFG::CharacterPhysicsComponent::GetVelocity(v12, &result);
              v15 = 0.0;
              if ( LOBYTE(this->m_Track[1].mMasterRate.text.mOffset)
                && (x_low = LODWORD(result.x),
                    z_low = LODWORD(result.z),
                    v18 = (__m128)x_low,
                    v18.m128_f32[0] = (float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)(result.y * result.y))
                                    + (float)(*(float *)&z_low * *(float *)&z_low),
                    v18.m128_f32[0] > 0.000099999997) )
              {
                if ( v18.m128_f32[0] == 0.0 )
                {
                  *(float *)&x_low = result.x * 0.0;
                  y = result.y * 0.0;
                  *(float *)&z_low = result.z * 0.0;
                }
                else
                {
                  v19 = 1.0 / _mm_sqrt_ps(v18).m128_f32[0];
                  *(float *)&x_low = result.x * v19;
                  y = result.y * v19;
                  *(float *)&z_low = result.z * v19;
                }
              }
              else
              {
                v21 = this->mContext->mSimObject.m_pPointer;
                if ( v21 )
                  m_pTransformNodeComponent = v21->m_pTransformNodeComponent;
                else
                  m_pTransformNodeComponent = 0i64;
                UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
                y = m_pTransformNodeComponent->mWorldTransform.v0.y;
                z_low = LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.z);
                x_low = LODWORD(m_pTransformNodeComponent->mWorldTransform.v0.x);
              }
              m_Track = this->m_Track;
              v31 = (__m128)z_low;
              LODWORD(result.z) = z_low;
              result.y = y;
              LODWORD(result.x) = x_low;
              v24 = 0.0;
              v25 = *((float *)&m_Track[1].mResourceOwner + 1);
              v26 = *((float *)&m_Track[1].vfptr + 1);
              v27 = *(float *)&m_Track[1].vfptr;
              v28 = *(float *)&m_Track[1].mResourceOwner;
              v29 = (float)(*(float *)&x_low * 0.0) - (float)(y * 0.0);
              v30 = y - (float)(*(float *)&z_low * 0.0);
              v31.m128_f32[0] = (float)(*(float *)&z_low * 0.0) - *(float *)&x_low;
              impulse.x = 0.0;
              impulse.z = 0.0;
              v44 = (float)(v31.m128_f32[0] * *(float *)&z_low) - (float)(v29 * y);
              v45 = (float)(v29 * *(float *)&x_low) - (float)(v30 * *(float *)&z_low);
              v46 = (float)(v30 * y) - (float)(v31.m128_f32[0] * *(float *)&x_low);
              v32 = 0.0;
              v41 = (float)(v45 * v45) + (float)(v44 * v44);
              impulse.y = 0.0;
              v33 = (__m128)LODWORD(v41);
              if ( (float)(v41 + (float)(v46 * v46)) > 0.000099999997 )
              {
                v33.m128_f32[0] = v41 + (float)(v46 * v46);
                v34 = (float)(v26 * v25) / _mm_sqrt_ps(v33).m128_f32[0];
                v15 = v44 * v34;
                v32 = v45 * v34;
                v24 = v46 * v34;
                impulse.x = v44 * v34;
                impulse.y = v45 * v34;
                impulse.z = v46 * v34;
              }
              v35 = v31;
              v35.m128_f32[0] = (float)((float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v30 * v30))
                              + (float)(v29 * v29);
              if ( v35.m128_f32[0] > 0.000099999997 )
              {
                LODWORD(v36) = COERCE_UNSIGNED_INT((float)(v27 * v25) / _mm_sqrt_ps(v35).m128_f32[0]) ^ _xmm[0];
                v15 = v15 + (float)(v30 * v36);
                v32 = v32 + (float)(v31.m128_f32[0] * v36);
                v24 = v24 + (float)(v29 * v36);
                impulse.x = v15;
                impulse.y = v32;
                impulse.z = v24;
              }
              v37 = (__m128)x_low;
              v37.m128_f32[0] = (float)((float)(*(float *)&x_low * *(float *)&x_low) + (float)(y * y))
                              + (float)(*(float *)&z_low * *(float *)&z_low);
              if ( v37.m128_f32[0] > 0.000099999997 )
              {
                v38 = (float)(v28 * v25) / _mm_sqrt_ps(v37).m128_f32[0];
                impulse.x = v15 + (float)(*(float *)&x_low * v38);
                impulse.y = v32 + (float)(y * v38);
                impulse.z = v24 + (float)(*(float *)&z_low * v38);
              }
              if ( mCreature->mPose.mRigHandle.mData )
                BoneID = Skeleton::GetBoneID(
                           mCreature->mPose.mRigHandle.mUFGSkeleton,
                           *(_DWORD *)&m_Track[1].mBreakPoint);
              else
                BoneID = -1;
              UFG::RagdollComponent::ApplyAngularImpulse(
                (UFG::RagdollComponent *)m_pComponent,
                BoneID,
                &impulse,
                *(float *)&this->m_Track[1].m_TrackClassNameUID);
              this->mFired = 1;
            }
          }
        }
      }
    }
  }
  return !this->mFired;
}

// File Line: 439
// RVA: 0x2F2B90
void __fastcall RagdollMotorTask::Begin(RagdollMotorTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  UFG::Ragdoll *mPrev; // rbx
  ITrack *m_Track; // rsi
  float v8; // xmm6_4
  UFG::SimObjectCVBase *v9; // rcx
  __int16 v10; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rcx
  int BoneID; // eax

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = m_pPointer->m_Components.p[42].m_pComponent;
    else
      m_pComponent = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                   ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID)
                   : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
    if ( m_pComponent )
    {
      mPrev = (UFG::Ragdoll *)m_pComponent[1].m_BoundComponentHandles.mNode.mPrev;
      if ( mPrev )
      {
        m_Track = this->m_Track;
        v8 = *(float *)&m_Track[1].vfptr;
        if ( HIDWORD(m_Track[1].vfptr) == UFG::gNullQSymbolUC.mUID )
        {
          UFG::Ragdoll::SetMotorMaxForce(mPrev, *(float *)&m_Track[1].vfptr);
        }
        else
        {
          v9 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
          if ( v9 )
          {
            v10 = v9->m_Flags;
            if ( (v10 & 0x4000) != 0 || v10 < 0 )
            {
              ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
            }
            else if ( (v10 & 0x2000) != 0 )
            {
              ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v9);
            }
            else if ( (v10 & 0x1000) != 0 )
            {
              ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                        v9,
                                                                        UFG::CharacterAnimationComponent::_TypeUID);
            }
            else
            {
              ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                        v9,
                                                                        UFG::CharacterAnimationComponent::_TypeUID);
            }
            if ( ComponentOfTypeHK )
            {
              mCreature = ComponentOfTypeHK->mCreature;
              if ( mCreature )
              {
                if ( mCreature->mPose.mRigHandle.mData )
                {
                  BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, HIDWORD(m_Track[1].vfptr));
                  if ( BoneID >= 0 )
                    UFG::Ragdoll::SetMotorMaxForceAtJoint(mPrev, v8, BoneID);
                }
              }
            }
          }
        }
      }
    }
  }
}

// File Line: 484
// RVA: 0x2F23B0
void __fastcall RagdollBlendMotorTask::Begin(RagdollBlendMotorTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rax
  float MotorMaxForce; // xmm0_4
  ITrack *m_Track; // rax
  float v8; // xmm2_4
  float v9; // xmm1_4

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pPointer,
                                                UFG::RagdollComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::RagdollComponent::_TypeUID);
    }
    if ( m_pComponent )
    {
      MotorMaxForce = UFG::RagdollComponent::GetMotorMaxForce(m_pComponent);
      m_Track = this->m_Track;
      this->mCurrentStrength = MotorMaxForce;
      v8 = *((float *)&m_Track[1].vfptr + 1);
      v9 = *(float *)&m_Track[1].vfptr - MotorMaxForce;
      if ( v8 <= 0.0 )
        this->mDeltaStrength = v9 * 3.4028233e32;
      else
        this->mDeltaStrength = v9 / v8;
    }
  }
}

// File Line: 496
// RVA: 0x307000
char __fastcall RagdollBlendMotorTask::Update(RagdollBlendMotorTask *this, float timeDelta)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rcx
  UFG::SimComponent *v7; // rax
  float mDeltaStrength; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    }
    else
    {
      v7 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
         ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID)
         : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
      m_pComponent = (UFG::RagdollComponent *)v7;
    }
    if ( m_pComponent )
    {
      mDeltaStrength = this->mDeltaStrength;
      v9 = (float)(mDeltaStrength * timeDelta) + this->mCurrentStrength;
      this->mCurrentStrength = v9;
      if ( mDeltaStrength <= 0.0 )
      {
        if ( mDeltaStrength >= 0.0 )
          goto LABEL_18;
        v10 = *(float *)&this->m_Track[1].vfptr;
        if ( v9 >= v10 )
          goto LABEL_18;
      }
      else
      {
        v10 = *(float *)&this->m_Track[1].vfptr;
        if ( v9 <= v10 )
        {
LABEL_18:
          UFG::RagdollComponent::SetMotorMaxForce(m_pComponent, this->mCurrentStrength);
          return 1;
        }
      }
      this->mCurrentStrength = v10;
      goto LABEL_18;
    }
  }
  return 1;
}

// File Line: 532
// RVA: 0x2F22E0
void __fastcall RagdollAquireTask::Begin(RagdollAquireTask *this, ActionContext *context)
{
  UFG::RagdollComponent *v3; // rax
  UFG::RagdollComponent *v4; // rbx
  ITrack *m_Track; // rdx
  __int64 vfptr_low; // rcx
  UFG::RagdollComponent::PoseState v7; // esi
  int v8[6]; // [rsp+20h] [rbp-18h]

  v3 = (UFG::RagdollComponent *)UFG::RagdollComponent::Acquire(context->mSimObject.m_pPointer);
  v4 = v3;
  if ( v3 )
  {
    m_Track = this->m_Track;
    v8[0] = 0;
    vfptr_low = SLODWORD(m_Track[1].vfptr);
    v8[1] = 1;
    v8[2] = 5;
    v8[3] = 6;
    v7 = v8[vfptr_low];
    v3->mDesiredPoseState = v7;
    v3->mRagDollWeight = *((float *)&this->m_Track[1].mResourceOwner + 1);
    UFG::RagdollComponent::SetPositionTrackingStiffness(v3, *((float *)&this->m_Track[1].vfptr + 1));
    UFG::RagdollComponent::SetMotorMaxForce(v4, *(float *)&this->m_Track[1].mResourceOwner);
    LODWORD(v4->mVelocityFromProxyScale) = this->m_Track[1].m_TrackClassNameUID;
    UFG::RagdollComponent::SetLimitStiffness(v4, *(float *)&this->m_Track[1].mBreakPoint);
    if ( v7 != v4->mPoseState && (unsigned int)v7 <= STATE_POWERED_TRACKING )
      UFG::RagdollComponent::Update(v4, 0.0);
  }
}

// File Line: 563
// RVA: 0x2F2D20
void __fastcall RagdollReleaseTask::Begin(RagdollReleaseTask *this, ActionContext *context)
{
  UFG::RagdollComponent::Release(context->mSimObject.m_pPointer, LOBYTE(this->m_Track[1].vfptr) != 0);
}

// File Line: 573
// RVA: 0x2F2640
void __fastcall RagdollChangeModeTask::Begin(RagdollChangeModeTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // rax
  __int64 vfptr_low; // rcx
  int v9[6]; // [rsp+20h] [rbp-18h]

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    if ( m_pComponent )
    {
      m_Track = this->m_Track;
      v9[0] = 0;
      v9[1] = 1;
      vfptr_low = SLODWORD(m_Track[1].vfptr);
      v9[2] = 5;
      v9[3] = 6;
      HIDWORD(m_pComponent[2].m_SafePointerList.mNode.mPrev) = v9[vfptr_low];
    }
  }
}

// File Line: 587
// RVA: 0x2F2D40
void __fastcall RagdollSetFrictionTask::Begin(RagdollSetFrictionTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
      m_pComponent = (UFG::RagdollComponent *)ComponentOfTypeHK;
    }
    if ( m_pComponent )
      UFG::RagdollComponent::SetFriction(m_pComponent, *(float *)&this->m_Track[1].vfptr);
  }
}

// File Line: 603
// RVA: 0x2FFE50
void __fastcall RagdollSetFrictionTask::End(RagdollSetFrictionTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pPointer,
                                                UFG::RagdollComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::RagdollComponent::_TypeUID);
    }
    if ( m_pComponent )
      UFG::RagdollComponent::SetFriction(m_pComponent, 0.30000001);
  }
}

// File Line: 615
// RVA: 0x2F2230
void __fastcall RagdollAdjustMassTask::Begin(RagdollAdjustMassTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float v7; // xmm1_4

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
      m_pComponent = (UFG::RagdollComponent *)ComponentOfTypeHK;
    }
    if ( m_pComponent )
    {
      v7 = *(float *)&this->m_Track[1].vfptr;
      if ( v7 >= 0.001 )
        UFG::RagdollComponent::ScaleMass(m_pComponent, v7);
    }
  }
}

// File Line: 635
// RVA: 0x2FFAA0
void __fastcall RagdollAdjustMassTask::End(RagdollAdjustMassTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  float v6; // xmm0_4

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
      m_pComponent = (UFG::RagdollComponent *)ComponentOfTypeHK;
    }
    if ( m_pComponent )
    {
      v6 = *(float *)&this->m_Track[1].vfptr;
      if ( v6 >= 0.001 )
        UFG::RagdollComponent::ScaleMass(m_pComponent, 1.0 / v6);
    }
  }
}

// File Line: 651
// RVA: 0x2F2700
void __fastcall RagdollChangeMotorTask::Begin(RagdollChangeMotorTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rax
  float MotorMaxForce; // xmm0_4
  float *m_Track; // rax
  float v8; // xmm2_4

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pPointer,
                                                UFG::RagdollComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::RagdollComponent::_TypeUID);
    }
    if ( m_pComponent )
    {
      MotorMaxForce = UFG::RagdollComponent::GetMotorMaxForce(m_pComponent);
      m_Track = (float *)this->m_Track;
      this->mCurrentStrength = MotorMaxForce;
      v8 = m_Track[13] - m_Track[12];
      if ( v8 <= 0.0 )
      {
        this->mDeltaStrength = 0.0;
        this->mCurrentStrength = m_Track[14];
      }
      else
      {
        this->mDeltaStrength = (float)(m_Track[14] - MotorMaxForce) / v8;
      }
    }
  }
}

// File Line: 671
// RVA: 0x307290
char __fastcall RagdollChangeMotorTask::Update(RagdollChangeMotorTask *this, float timeDelta)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rax
  float v6; // xmm6_4

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pPointer,
                                                UFG::RagdollComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::RagdollComponent::_TypeUID);
    }
    if ( m_pComponent )
    {
      v6 = (float)(timeDelta * this->mDeltaStrength) + this->mCurrentStrength;
      this->mCurrentStrength = v6;
      UFG::RagdollComponent::SetMotorMaxForce(m_pComponent, v6);
    }
  }
  return 1;
}

// File Line: 683
// RVA: 0x2FFCB0
void __fastcall RagdollChangeMotorTask::End(RagdollChangeMotorTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
      m_pComponent = (UFG::RagdollComponent *)ComponentOfTypeHK;
    }
    if ( m_pComponent )
      UFG::RagdollComponent::SetMotorMaxForce(m_pComponent, *(float *)&this->m_Track[1].vfptr);
  }
}

// File Line: 696
// RVA: 0x2F2560
void __fastcall RagdollChangeBlendWeightTask::Begin(RagdollChangeBlendWeightTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  float v6; // xmm2_4
  float *m_Track; // rax
  float v8; // xmm1_4

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[42].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
    }
    if ( m_pComponent )
    {
      v6 = *(float *)&m_pComponent[2].vfptr;
      m_Track = (float *)this->m_Track;
      this->mCurrentStrength = v6;
      v8 = m_Track[13] - m_Track[12];
      if ( v8 <= 0.0 )
      {
        this->mDeltaStrength = 0.0;
        this->mCurrentStrength = m_Track[14];
      }
      else
      {
        this->mDeltaStrength = (float)(m_Track[14] - v6) / v8;
      }
    }
  }
}

// File Line: 716
// RVA: 0x3071D0
char __fastcall RagdollChangeBlendWeightTask::Update(RagdollChangeBlendWeightTask *this, float timeDelta)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rax
  float v6; // xmm6_4

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[42].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID);
    }
    else
    {
      m_pComponent = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
    }
    if ( m_pComponent )
    {
      v6 = (float)(timeDelta * this->mDeltaStrength) + this->mCurrentStrength;
      this->mCurrentStrength = v6;
      *(float *)&m_pComponent[2].vfptr = v6;
    }
  }
  return 1;
}

// File Line: 728
// RVA: 0x2FFC10
void __fastcall RagdollChangeBlendWeightTask::End(RagdollChangeBlendWeightTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rdx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    if ( m_pComponent )
      LODWORD(m_pComponent[2].vfptr) = this->m_Track[1].vfptr;
  }
}

// File Line: 741
// RVA: 0x2F29B0
void __fastcall RagdollChangeVelocityTrackingStrTask::Begin(
        RagdollChangeVelocityTrackingStrTask *this,
        ActionContext *context)
{
  int BoneID; // esi
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rax
  float PositionTrackingStiffness; // xmm0_4
  ITrack *m_Track; // rdi
  float v9; // xmm2_4
  UFG::SimObjectCVBase *v10; // rcx
  __int16 v11; // dx
  UFG::CharacterAnimationComponent *ComponentOfTypeHK; // rax
  Creature *mCreature; // rcx

  BoneID = -1;
  this->mContext = context;
  this->mSkeletonID = -1;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    else
      m_pComponent = (UFG::RagdollComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::RagdollComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::RagdollComponent::_TypeUID));
    if ( m_pComponent )
    {
      PositionTrackingStiffness = UFG::RagdollComponent::GetPositionTrackingStiffness(m_pComponent);
      m_Track = this->m_Track;
      this->mCurrentStrength = PositionTrackingStiffness;
      v9 = m_Track->mTimeEnd - m_Track->mTimeBegin;
      if ( v9 <= 0.0 )
      {
        this->mDeltaStrength = 0.0;
        this->mCurrentStrength = *(float *)&m_Track[1].vfptr;
      }
      else
      {
        this->mDeltaStrength = (float)(*(float *)&m_Track[1].vfptr - PositionTrackingStiffness) / v9;
      }
      if ( HIDWORD(m_Track[1].vfptr) != UFG::gNullQSymbolUC.mUID )
      {
        v10 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
        if ( v10 )
        {
          v11 = v10->m_Flags;
          if ( (v11 & 0x4000) != 0 || v11 < 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
          }
          else if ( (v11 & 0x2000) != 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v10);
          }
          else if ( (v11 & 0x1000) != 0 )
          {
            ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                      v10,
                                                                      UFG::CharacterAnimationComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                      v10,
                                                                      UFG::CharacterAnimationComponent::_TypeUID);
          }
          if ( ComponentOfTypeHK )
          {
            mCreature = ComponentOfTypeHK->mCreature;
            if ( mCreature )
            {
              if ( mCreature->mPose.mRigHandle.mData )
                BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, HIDWORD(m_Track[1].vfptr));
              this->mSkeletonID = BoneID;
            }
          }
        }
      }
    }
  }
}

// File Line: 773
// RVA: 0x307350
char __fastcall RagdollChangeVelocityTrackingStrTask::Update(
        RagdollChangeVelocityTrackingStrTask *this,
        float timeDelta)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rax
  int mSkeletonID; // r8d
  float v7; // xmm6_4

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    else
      m_pComponent = (UFG::RagdollComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::RagdollComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::RagdollComponent::_TypeUID));
    if ( m_pComponent )
    {
      mSkeletonID = this->mSkeletonID;
      v7 = (float)(timeDelta * this->mDeltaStrength) + this->mCurrentStrength;
      this->mCurrentStrength = v7;
      if ( mSkeletonID >= 0 )
      {
        UFG::RagdollComponent::SetPositionTrackingStiffnessAtJoint(m_pComponent, v7, mSkeletonID);
        return 1;
      }
      UFG::RagdollComponent::SetPositionTrackingStiffness(m_pComponent, v7);
    }
  }
  return 1;
}

// File Line: 792
// RVA: 0x2FFD60
void __fastcall RagdollChangeVelocityTrackingStrTask::End(RagdollChangeVelocityTrackingStrTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  int mSkeletonID; // r8d
  float v7; // xmm1_4

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
      m_pComponent = (UFG::RagdollComponent *)ComponentOfTypeHK;
    }
    if ( m_pComponent )
    {
      mSkeletonID = this->mSkeletonID;
      v7 = *(float *)&this->m_Track[1].vfptr;
      this->mCurrentStrength = v7;
      if ( mSkeletonID < 0 )
        UFG::RagdollComponent::SetPositionTrackingStiffness(m_pComponent, v7);
      else
        UFG::RagdollComponent::SetPositionTrackingStiffnessAtJoint(m_pComponent, v7, mSkeletonID);
    }
  }
}

// File Line: 814
// RVA: 0x2F27E0
void __fastcall RagdollChangeVelocityTrackingParamsRawTask::Begin(
        RagdollChangeVelocityTrackingParamsRawTask *this,
        ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ITrack *m_Track; // rdi
  UFG::SimObjectCVBase *v8; // rcx
  __int16 v9; // dx
  UFG::CharacterAnimationComponent *ComponentOfType; // rax
  Creature *mCreature; // rcx
  int BoneID; // eax
  UFG::Ragdoll *mPrev; // rbx
  int RigidBodyID; // eax
  _DWORD *p_m_hierarchyGain; // rdx
  ITrack *v16; // rcx

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
      m_pComponent = ComponentOfTypeHK;
    }
    if ( m_pComponent )
    {
      m_Track = this->m_Track;
      if ( LODWORD(m_Track[1].vfptr) != UFG::gNullQSymbolUC.mUID )
      {
        v8 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
        if ( v8 )
        {
          v9 = v8->m_Flags;
          if ( (v9 & 0x4000) != 0 || v9 < 0 )
          {
            ComponentOfType = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
          }
          else if ( (v9 & 0x2000) != 0 )
          {
            ComponentOfType = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8);
          }
          else if ( (v9 & 0x1000) != 0 )
          {
            ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                    v8,
                                                                    UFG::CharacterAnimationComponent::_TypeUID);
          }
          else
          {
            ComponentOfType = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                                    v8,
                                                                    UFG::CharacterAnimationComponent::_TypeUID);
          }
          if ( ComponentOfType )
          {
            mCreature = ComponentOfType->mCreature;
            if ( mCreature )
            {
              if ( mCreature->mPose.mRigHandle.mData )
              {
                BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, (unsigned int)m_Track[1].vfptr);
                if ( BoneID >= 0 )
                {
                  mPrev = (UFG::Ragdoll *)m_pComponent[1].m_BoundComponentHandles.mNode.mPrev;
                  RigidBodyID = UFG::Ragdoll::GetRigidBodyID(mPrev, BoneID);
                  if ( RigidBodyID >= 0 )
                  {
                    p_m_hierarchyGain = (_DWORD *)&mPrev->mRigidBodyController->m_controlDataPalette.m_data[RigidBodyID].m_hierarchyGain;
                    v16 = this->m_Track;
                    *p_m_hierarchyGain = HIDWORD(v16[1].vfptr);
                    p_m_hierarchyGain[1] = v16[1].mResourceOwner;
                    p_m_hierarchyGain[2] = HIDWORD(v16[1].mResourceOwner);
                    p_m_hierarchyGain[3] = v16[1].m_TrackClassNameUID;
                    p_m_hierarchyGain[4] = *(_DWORD *)&v16[1].mBreakPoint;
                    p_m_hierarchyGain[5] = v16[1].mMasterRate.text.mOffset;
                    p_m_hierarchyGain[6] = HIDWORD(v16[1].mMasterRate.text.mOffset);
                    p_m_hierarchyGain[7] = v16[1].mMasterRate.expression.mOffset;
                    p_m_hierarchyGain[8] = HIDWORD(v16[1].mMasterRate.expression.mOffset);
                    p_m_hierarchyGain[9] = LODWORD(v16[1].mMasterRate.value);
                    p_m_hierarchyGain[10] = *((_DWORD *)&v16[1].mMasterRate.value + 1);
                    p_m_hierarchyGain[11] = LODWORD(v16[1].mTimeBegin);
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

// File Line: 867
// RVA: 0x2F2480
void __fastcall RagdollChangeAngularLimitStrTask::Begin(RagdollChangeAngularLimitStrTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rax
  float LimitStiffness; // xmm0_4
  float *m_Track; // rax
  float v8; // xmm2_4

  this->mContext = context;
  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    }
    else if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                m_pPointer,
                                                UFG::RagdollComponent::_TypeUID);
    }
    else
    {
      m_pComponent = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                                m_pPointer,
                                                UFG::RagdollComponent::_TypeUID);
    }
    if ( m_pComponent )
    {
      LimitStiffness = UFG::RagdollComponent::GetLimitStiffness(m_pComponent);
      m_Track = (float *)this->m_Track;
      this->mCurrentStrength = LimitStiffness;
      v8 = m_Track[13] - m_Track[12];
      if ( v8 <= 0.0 )
      {
        this->mDeltaStrength = 0.0;
        this->mCurrentStrength = m_Track[14];
      }
      else
      {
        this->mDeltaStrength = (float)(m_Track[14] - LimitStiffness) / v8;
      }
    }
  }
}

// File Line: 887
// RVA: 0x3070F0
char __fastcall RagdollChangeAngularLimitStrTask::Update(RagdollChangeAngularLimitStrTask *this, float timeDelta)
{
  UFG::SimObjectGame *m_pPointer; // r8
  __int16 m_Flags; // cx
  UFG::RagdollComponent *m_pComponent; // rax
  float v6; // xmm6_4

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    else
      m_pComponent = (UFG::RagdollComponent *)(m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                 m_pPointer,
                                                 UFG::RagdollComponent::_TypeUID)
                                             : UFG::SimObject::GetComponentOfType(
                                                 m_pPointer,
                                                 UFG::RagdollComponent::_TypeUID));
    if ( m_pComponent )
    {
      v6 = (float)(timeDelta * this->mDeltaStrength) + this->mCurrentStrength;
      this->mCurrentStrength = v6;
      if ( v6 <= 1.0 )
      {
        if ( v6 < 0.0 )
          this->mCurrentStrength = 0.0;
      }
      else
      {
        this->mCurrentStrength = 1.0;
      }
      UFG::RagdollComponent::SetLimitStiffness(m_pComponent, this->mCurrentStrength);
    }
  }
  return 1;
}

// File Line: 908
// RVA: 0x2FFB60
void __fastcall RagdollChangeAngularLimitStrTask::End(RagdollChangeAngularLimitStrTask *this)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::RagdollComponent *m_pComponent; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax

  m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::RagdollComponent *)m_pPointer->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
      m_pComponent = (UFG::RagdollComponent *)ComponentOfTypeHK;
    }
    if ( m_pComponent )
      UFG::RagdollComponent::SetLimitStiffness(m_pComponent, *(float *)&this->m_Track[1].vfptr);
  }
}

// File Line: 930
// RVA: 0x307420
bool __fastcall RagdollDeathImpulseTask::Update(RagdollDeathImpulseTask *this, float thedt)
{
  float v3; // xmm6_4
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbp
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **p_mNext; // rsi
  int i; // r12d
  int BoneID; // edi
  UFG::SimObjectCVBase *v14; // rcx
  __int16 v15; // dx
  UFG::CharacterAnimationComponent *v16; // rax
  int v17; // ecx
  Creature *mCreature; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v19; // rcx
  const char *TypeName; // rax
  __int64 mTypeUID_low; // rax
  hkArray<hkpRigidBody *,hkContainerHeapAllocator> *RigidBodies; // r14
  int v23; // edi
  __int64 v24; // rbx
  hkpRigidBody *v25; // rcx
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  UFG::qVector3 impulse; // [rsp+28h] [rbp-A0h] BYREF
  UFG::qVector3 location; // [rsp+38h] [rbp-90h] BYREF
  UFG::qVector3 v32; // [rsp+48h] [rbp-80h] BYREF
  UFG::qReflectHandleBase v33; // [rsp+58h] [rbp-70h] BYREF

  v3 = *(float *)&this->m_Track[1].vfptr;
  if ( !this->mFired )
  {
    m_pPointer = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      m_Flags = m_pPointer->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[42].m_pComponent;
      }
      else
      {
        v7 = m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::RagdollComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::RagdollComponent::_TypeUID);
        m_pComponent = v7;
      }
      if ( m_pComponent )
      {
        if ( LODWORD(m_pComponent[2].m_SafePointerList.mNode.mPrev) == 1 )
        {
          v8 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
          if ( v8 )
          {
            v9 = v8->m_Flags;
            if ( (v9 & 0x4000) != 0 )
            {
              v10 = v8->m_Components.p[15].m_pComponent;
            }
            else if ( v9 >= 0 )
            {
              v10 = (v9 & 0x2000) != 0 || (v9 & 0x1000) != 0
                  ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HitReactionComponent::_TypeUID)
                  : UFG::SimObject::GetComponentOfType(v8, UFG::HitReactionComponent::_TypeUID);
            }
            else
            {
              v10 = v8->m_Components.p[15].m_pComponent;
            }
            if ( v10 )
            {
              p_mNext = &v10[2].m_BoundComponentHandles.mNode.mNext;
              for ( i = *(_DWORD *)&v10[7].m_Flags; i > 0; --i )
              {
                BoneID = 1;
                v14 = (UFG::SimObjectCVBase *)this->mContext->mSimObject.m_pPointer;
                if ( v14 )
                {
                  v15 = v14->m_Flags;
                  if ( (v15 & 0x4000) != 0 || v15 < 0 )
                  {
                    v16 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v14);
                  }
                  else if ( (v15 & 0x2000) != 0 )
                  {
                    v16 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v14);
                  }
                  else
                  {
                    v16 = (UFG::CharacterAnimationComponent *)((v15 & 0x1000) != 0
                                                             ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                 v14,
                                                                 UFG::CharacterAnimationComponent::_TypeUID)
                                                             : UFG::SimObject::GetComponentOfType(
                                                                 v14,
                                                                 UFG::CharacterAnimationComponent::_TypeUID));
                  }
                  if ( v16 )
                  {
                    v17 = *((_DWORD *)p_mNext + 1);
                    if ( v17 == gAttackCollisionExplosionNoDamage.m_EnumValue
                      || v17 == gAttackCollisionExplosion.m_EnumValue )
                    {
                      RigidBodies = UFG::RagdollComponent::GetRigidBodies((UFG::RagdollComponent *)m_pComponent);
                      v23 = 0;
                      if ( RigidBodies->m_size > 0 )
                      {
                        v24 = 0i64;
                        do
                        {
                          v25 = RigidBodies->m_data[v24];
                          if ( v25 )
                          {
                            location = *(UFG::qVector3 *)v25->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad.m128_i8;
                            v26 = hkpMotion::getMass(&v25->m_motion) * 0.0125;
                            v27 = v3 * *((float *)p_mNext + 54);
                            v28 = v3 * *((float *)p_mNext + 55);
                            impulse.x = (float)(v3 * *((float *)p_mNext + 53)) * v26;
                            impulse.y = v27 * v26;
                            impulse.z = v28 * v26;
                            UFG::RagdollComponent::ApplyImpulse(
                              (UFG::RagdollComponent *)m_pComponent,
                              1,
                              &location,
                              &impulse);
                          }
                          ++v23;
                          ++v24;
                        }
                        while ( v23 < RigidBodies->m_size );
                      }
                      goto $skip_to_next;
                    }
                    mCreature = v16->mCreature;
                    if ( mCreature )
                    {
                      if ( mCreature->mPose.mRigHandle.mData )
                        BoneID = Skeleton::GetBoneID(mCreature->mPose.mRigHandle.mUFGSkeleton, g_symBip01Pelvis.mUID);
                      else
                        BoneID = -1;
                      UFG::qReflectHandleBase::qReflectHandleBase(&v33);
                      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v19);
                      v33.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
                      UFG::qReflectHandleBase::Init(&v33, v33.mTypeUID, (unsigned __int64)p_mNext[21]);
                      if ( v33.mData )
                      {
                        mTypeUID_low = LODWORD(v33.mData[2].mTypeUID);
                        if ( (_DWORD)mTypeUID_low != -1 )
                        {
                          if ( mCreature->mPose.mRigHandle.mData )
                            BoneID = Skeleton::GetBoneID(
                                       mCreature->mPose.mRigHandle.mUFGSkeleton,
                                       g_limbs[mTypeUID_low].mUID);
                          else
                            BoneID = -1;
                        }
                      }
                      UFG::qReflectHandleBase::~qReflectHandleBase(&v33);
                    }
                  }
                }
                v32.x = v3 * *((float *)p_mNext + 53);
                v32.y = v3 * *((float *)p_mNext + 54);
                v32.z = v3 * *((float *)p_mNext + 55);
                UFG::RagdollComponent::ApplyImpulse(
                  (UFG::RagdollComponent *)m_pComponent,
                  BoneID,
                  (UFG::qVector3 *)(p_mNext + 25),
                  &v32);
$skip_to_next:
                this->mFired = 1;
                if ( p_mNext[36] )
                  p_mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)p_mNext[36];
              }
            }
          }
        }
      }
    }
  }
  return !this->mFired;
}:RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> **)p_mNext[36];
   

