// File Line: 35
// RVA: 0x2F2DF0
void __fastcall RagdollTask::Begin(RagdollTask *this, ActionContext *context)
{
  RagdollTask *v2; // rbx
  ITrack *v3; // rcx
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rdi
  ITrack *v6; // rdx
  int v7; // eax
  UFG::SimObjectCVBase *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::CharacterAnimationComponent *v10; // rax
  Creature *v11; // rcx
  float v12; // eax

  this->mContext = context;
  this->mTrackingBlendWeight = 1.0;
  v2 = this;
  v3 = this->m_Track;
  if ( LOBYTE(v3[1].mResourceOwner) )
  {
    v4 = UFG::RagdollComponent::Acquire(context->mSimObject.m_pPointer);
    v5 = v4;
    if ( v4 )
    {
      v6 = v2->m_Track;
      v2->mTrackingBlendWeight = *(float *)&v4[2].vfptr;
      v7 = (int)v6[1].vfptr;
      if ( v7 )
      {
        if ( v7 == 1 )
        {
          HIDWORD(v5[2].m_SafePointerList.mNode.mPrev) = 1;
          LODWORD(v5[2].vfptr) = 1065353216;
        }
      }
      else
      {
        v8 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
        if ( v8 )
        {
          v9 = v8->m_Flags;
          if ( (v9 >> 14) & 1 )
          {
            v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
          }
          else if ( (v9 & 0x8000u) == 0 )
          {
            if ( (v9 >> 13) & 1 )
            {
              v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8);
            }
            else if ( (v9 >> 12) & 1 )
            {
              v10 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v8->vfptr,
                                                          UFG::CharacterAnimationComponent::_TypeUID);
            }
            else
            {
              v10 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v8->vfptr,
                                                          UFG::CharacterAnimationComponent::_TypeUID);
            }
          }
          else
          {
            v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
          }
          if ( v10 )
          {
            v11 = v10->mCreature;
            if ( v11 )
              Creature::MakeUpright(v11, *((float *)&v2->m_Track[1].vfptr + 1));
          }
        }
        v12 = *(float *)&v5[2].vfptr;
        HIDWORD(v5[2].m_SafePointerList.mNode.mPrev) = 0;
        v2->mTrackingBlendWeight = v12;
      }
    }
    ((void (__fastcall *)(RagdollTask *))v2->vfptr->Update)(v2);
  }
  else
  {
    UFG::RagdollComponent::Release(context->mSimObject.m_pPointer, BYTE1(v3[1].mResourceOwner) != 0);
    ((void (__fastcall *)(RagdollTask *))v2->vfptr->Update)(v2);
  }
}

// File Line: 90
// RVA: 0x149CC50
__int64 dynamic_initializer_for__g_symBip01Pelvis__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Bip01 Pelvis", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&g_symBip01Pelvis, v0);
  return atexit(dynamic_atexit_destructor_for__g_symBip01Pelvis__);
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
  return atexit(dynamic_atexit_destructor_for__g_limbs__);
}

// File Line: 142
// RVA: 0x307B20
char __fastcall RagdollTask::Update(RagdollTask *this, float timeDelta)
{
  float v2; // xmm8_4
  RagdollTask *v3; // rsi
  float v4; // xmm7_4
  UFG::SimObjectGame *v5; // rcx
  unsigned __int16 v6; // dx
  UFG::SimComponent *v7; // r14
  UFG::SimComponent *v8; // rax
  UFG::SimObjectGame *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::SimComponent *v11; // rax
  signed __int64 v12; // rbp
  int v13; // er15
  int v14; // edi
  UFG::SimObjectCVBase *v15; // rcx
  unsigned __int16 v16; // dx
  UFG::CharacterAnimationComponent *v17; // rax
  UFG::CharacterAnimationComponent *v18; // rbx
  Creature *v19; // rcx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v20; // rcx
  const char *v21; // rax
  __int64 v22; // rax
  Creature *v23; // rcx
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  UFG::qVector3 impulse; // [rsp+28h] [rbp-80h]
  UFG::qReflectHandleBase v30; // [rsp+38h] [rbp-70h]

  v2 = timeDelta;
  v3 = this;
  v4 = *((float *)&this->m_Track[1].mResourceOwner + 1);
  if ( v4 != 0.0 && !this->mFired )
  {
    v5 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( v5 )
    {
      v6 = v5->m_Flags;
      if ( (v6 >> 14) & 1 )
      {
        v7 = v5->m_Components.p[42].m_pComponent;
      }
      else
      {
        if ( (v6 & 0x8000u) == 0 )
        {
          if ( (v6 >> 13) & 1 )
            v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RagdollComponent::_TypeUID);
          else
            v8 = (v6 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RagdollComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v5->vfptr, UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v5, UFG::RagdollComponent::_TypeUID);
        }
        v7 = v8;
      }
      if ( v7 )
      {
        if ( LODWORD(v7[2].m_SafePointerList.mNode.mPrev) == 1 )
        {
          v9 = (UFG::SimObjectGame *)v3->mContext->mSimObject.m_pPointer;
          if ( v9 )
          {
            v10 = v9->m_Flags;
            if ( (v10 >> 14) & 1 )
            {
              v11 = v9->m_Components.p[15].m_pComponent;
            }
            else if ( (v10 & 0x8000u) == 0 )
            {
              if ( (v10 >> 13) & 1 )
                v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v9, UFG::HitReactionComponent::_TypeUID);
              else
                v11 = (v10 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                          v9,
                                          UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v9->vfptr,
                                                                                   UFG::HitReactionComponent::_TypeUID);
            }
            else
            {
              v11 = v9->m_Components.p[15].m_pComponent;
            }
            if ( v11 )
            {
              v12 = (signed __int64)&v11[2].m_BoundComponentHandles.mNode.mNext;
              v13 = *(_DWORD *)&v11[7].m_Flags;
              while ( v13 > 0 )
              {
                v14 = 1;
                v15 = (UFG::SimObjectCVBase *)v3->mContext->mSimObject.m_pPointer;
                if ( v15 )
                {
                  v16 = v15->m_Flags;
                  if ( (v16 >> 14) & 1 )
                  {
                    v17 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v15);
                  }
                  else if ( (v16 & 0x8000u) == 0 )
                  {
                    if ( (v16 >> 13) & 1 )
                      v17 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v15);
                    else
                      v17 = (UFG::CharacterAnimationComponent *)((v16 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                     (UFG::SimObjectGame *)&v15->vfptr,
                                                                                     UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v15->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
                  }
                  else
                  {
                    v17 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v15);
                  }
                  v18 = v17;
                  if ( v17 )
                  {
                    v19 = v17->mCreature;
                    if ( v19 )
                    {
                      if ( v19->mPose.mRigHandle.mData )
                        v14 = Skeleton::GetBoneID(v19->mPose.mRigHandle.mUFGSkeleton, g_symBip01Pelvis.mUID);
                      else
                        v14 = -1;
                      UFG::qReflectHandleBase::qReflectHandleBase(&v30);
                      v21 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v20);
                      v30.mTypeUID = UFG::qStringHash64(v21, 0xFFFFFFFFFFFFFFFFui64);
                      UFG::qReflectHandleBase::Init(&v30, v30.mTypeUID, *(_QWORD *)(v12 + 168));
                      if ( v30.mData )
                      {
                        v22 = LODWORD(v30.mData[2].mTypeUID);
                        if ( (_DWORD)v22 != -1 )
                        {
                          v23 = v18->mCreature;
                          if ( v23->mPose.mRigHandle.mData )
                            v14 = Skeleton::GetBoneID(v23->mPose.mRigHandle.mUFGSkeleton, g_limbs[v22].mUID);
                          else
                            v14 = -1;
                        }
                      }
                      UFG::qReflectHandleBase::~qReflectHandleBase(&v30);
                    }
                  }
                }
                v24 = v4 * *(float *)(v12 + 220);
                v25 = v4 * *(float *)(v12 + 216);
                impulse.x = v4 * *(float *)(v12 + 212);
                impulse.y = v25;
                impulse.z = v24;
                UFG::RagdollComponent::ApplyImpulse(
                  (UFG::RagdollComponent *)v7,
                  v14,
                  (UFG::qVector3 *)(v12 + 200),
                  &impulse);
                v3->mFired = 1;
                --v13;
                if ( *(_QWORD *)(v12 + 288) )
                  v12 = *(_QWORD *)(v12 + 288);
              }
            }
          }
        }
      }
    }
  }
  v26 = *((float *)&v3->m_Track[1].vfptr + 1);
  if ( v26 > 0.0 )
  {
    v27 = v3->mTrackingBlendWeight;
    if ( v27 >= 0.0 )
      v3->mTrackingBlendWeight = v27 - (float)(v2 / v26);
  }
  if ( v3->mTrackingBlendWeight < 0.0 )
    v3->mTrackingBlendWeight = 0.0;
  RagdollTask::handleVelocityTracking(v3);
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
  RagdollTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rcx
  UFG::SimComponent *v5; // rax

  v1 = this;
  if ( LOBYTE(this->m_Track[1].mResourceOwner) )
  {
    v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( v2 )
    {
      v3 = v2->m_Flags;
      if ( (v3 >> 14) & 1 )
      {
        v4 = v2->m_Components.p[42].m_pComponent;
      }
      else
      {
        if ( (v3 & 0x8000u) == 0 )
        {
          if ( (v3 >> 13) & 1 )
          {
            v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
          }
          else if ( (v3 >> 12) & 1 )
          {
            v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
          }
          else
          {
            v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RagdollComponent::_TypeUID);
          }
        }
        else
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
        }
        v4 = v5;
      }
      if ( v4 && !LODWORD(v1->m_Track[1].vfptr) )
      {
        *(float *)&v4[2].vfptr = v1->mTrackingBlendWeight;
        if ( v1->mTrackingBlendWeight == 0.0 )
          HIDWORD(v4[2].m_SafePointerList.mNode.mPrev) = 0;
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
  RagdollImpulseTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RagdollComponent *v5; // rbx
  UFG::RagdollComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::TransformNodeComponent *v9; // r15
  UFG::CharacterAnimationComponent *v10; // rax
  Creature *v11; // rsi
  int v12; // er14
  float *v13; // rax
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  UFG::qVector3 dest; // [rsp+20h] [rbp-A8h]
  UFG::qVector3 source; // [rsp+30h] [rbp-98h]
  UFG::qMatrix44 transform; // [rsp+40h] [rbp-88h]

  v2 = this;
  if ( !this->mFired )
  {
    v3 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( v3 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = (UFG::RagdollComponent *)v3->m_Components.p[42].m_pComponent;
      }
      else
      {
        if ( (v4 & 0x8000u) == 0 )
        {
          if ( (v4 >> 13) & 1 )
          {
            v6 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
          }
          else if ( (v4 >> 12) & 1 )
          {
            v6 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
          }
          else
          {
            v6 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                            (UFG::SimObject *)&v3->vfptr,
                                            UFG::RagdollComponent::_TypeUID);
          }
        }
        else
        {
          v6 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
        }
        v5 = v6;
      }
      if ( v5 )
      {
        if ( v5->mPoseState <= 1u )
        {
          v7 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
          if ( v7 )
          {
            v8 = v7->m_Flags;
            v9 = v7->m_pTransformNodeComponent;
            if ( (v8 >> 14) & 1 )
            {
              v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v7);
            }
            else if ( (v8 & 0x8000u) == 0 )
            {
              if ( (v8 >> 13) & 1 )
                v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v7);
              else
                v10 = (UFG::CharacterAnimationComponent *)((v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                              (UFG::SimObjectGame *)&v7->vfptr,
                                                                              UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
            }
            else
            {
              v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v7);
            }
            if ( v10 )
            {
              v11 = v10->mCreature;
              if ( v11 )
              {
                if ( v11->mPose.mRigHandle.mData )
                  v12 = Skeleton::GetBoneID(v11->mPose.mRigHandle.mUFGSkeleton, HIDWORD(v2->m_Track[1].mResourceOwner));
                else
                  v12 = -1;
                v13 = (float *)v2->m_Track;
                v14 = v13[14];
                v15 = v13[15];
                v16 = v13[16];
                UFG::TransformNodeComponent::UpdateWorldTransform(v9);
                v17 = v9->mWorldTransform.v0.y;
                source.x = v9->mWorldTransform.v0.x;
                v18 = v9->mWorldTransform.v0.z;
                source.y = v17;
                source.z = v18;
                UFG::qRotateVectorZ(&dest, &source, (float)(v14 * 3.1415927) * 0.0055555557);
                dest.z = v16 * v15;
                LODWORD(dest.x) = COERCE_UNSIGNED_INT(dest.x * v15) ^ _xmm[0];
                LODWORD(dest.y) = COERCE_UNSIGNED_INT(dest.y * v15) ^ _xmm[0];
                Creature::GetTransform(v11, v12, &transform);
                UFG::RagdollComponent::ApplyImpulse(v5, v12, (UFG::qVector3 *)&transform.v3, &dest);
                v2->mFired = 1;
              }
            }
          }
        }
      }
    }
  }
  return v2->mFired == 0;
}

// File Line: 348
// RVA: 0x306A50
bool __fastcall RagdollAngularImpulseTask::Update(RagdollAngularImpulseTask *this, float __formal)
{
  RagdollAngularImpulseTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rsi
  UFG::SimComponent *v6; // rax
  UFG::SimObjectCVBase *v7; // rcx
  UFG::CharacterAnimationComponent *v8; // rdi
  unsigned __int16 v9; // dx
  UFG::CharacterAnimationComponent *v10; // rax
  UFG::SimObjectGame *v11; // rcx
  UFG::CharacterPhysicsComponent *v12; // rax
  unsigned __int16 v13; // dx
  Creature *v14; // r14
  float v15; // xmm6_4
  __int128 v16; // xmm2
  __int128 v17; // xmm4
  __m128 v18; // xmm5
  float v19; // xmm1_4
  float v20; // xmm3_4
  UFG::SimObject *v21; // rdi
  UFG::TransformNodeComponent *v22; // rdi
  ITrack *v23; // rax
  float v24; // xmm8_4
  float v25; // xmm15_4
  float v26; // xmm5_4
  float v27; // xmm9_4
  float v28; // xmm10_4
  float v29; // xmm12_4
  float v30; // xmm13_4
  __m128 v31; // xmm11
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm7_4
  float v35; // xmm1_4
  __m128 v36; // xmm0
  float v37; // xmm5_4
  __m128 v38; // xmm5
  float v39; // xmm9_4
  __m128 v40; // xmm5
  float v41; // xmm10_4
  int v42; // eax
  float v44; // [rsp+20h] [rbp-F8h]
  UFG::qVector3 impulse; // [rsp+28h] [rbp-F0h]
  UFG::qVector3 result; // [rsp+38h] [rbp-E0h]
  float v47; // [rsp+120h] [rbp+8h]
  float v48; // [rsp+130h] [rbp+18h]
  float v49; // [rsp+138h] [rbp+20h]

  v2 = this;
  if ( !this->mFired )
  {
    v3 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( v3 )
    {
      v4 = v3->m_Flags;
      if ( (v4 >> 14) & 1 )
      {
        v5 = v3->m_Components.p[42].m_pComponent;
      }
      else
      {
        if ( (v4 & 0x8000u) == 0 )
        {
          if ( (v4 >> 13) & 1 )
            v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
          else
            v6 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
        }
        v5 = v6;
      }
      if ( v5 && LODWORD(v5[2].m_SafePointerList.mNode.mPrev) <= 1 )
      {
        v7 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
        if ( v7 )
        {
          v9 = v7->m_Flags;
          if ( (v9 >> 14) & 1 )
          {
            v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v7);
          }
          else if ( (v9 & 0x8000u) == 0 )
          {
            if ( (v9 >> 13) & 1 )
              v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v7);
            else
              v10 = (UFG::CharacterAnimationComponent *)((v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                            (UFG::SimObjectGame *)&v7->vfptr,
                                                                            UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
          }
          else
          {
            v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v7);
          }
          v8 = v10;
        }
        else
        {
          v8 = 0i64;
        }
        v11 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
        if ( v11 )
        {
          v13 = v11->m_Flags;
          if ( (v13 >> 14) & 1 )
          {
            v12 = (UFG::CharacterPhysicsComponent *)v11->m_Components.p[27].m_pComponent;
          }
          else if ( (v13 & 0x8000u) == 0 )
          {
            if ( (v13 >> 13) & 1 )
              v12 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                        v11,
                                                        UFG::CharacterPhysicsComponent::_TypeUID);
            else
              v12 = (UFG::CharacterPhysicsComponent *)((v13 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                           v11,
                                                                           UFG::CharacterPhysicsComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v11->vfptr, UFG::CharacterPhysicsComponent::_TypeUID));
          }
          else
          {
            v12 = (UFG::CharacterPhysicsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v11,
                                                      UFG::CharacterPhysicsComponent::_TypeUID);
          }
        }
        else
        {
          v12 = 0i64;
        }
        if ( v8 )
        {
          if ( v12 )
          {
            v14 = v8->mCreature;
            if ( v14 )
            {
              UFG::CharacterPhysicsComponent::GetVelocity(v12, &result);
              v15 = 0.0;
              if ( LOBYTE(v2->m_Track[1].mMasterRate.text.mOffset)
                && (v16 = LODWORD(result.x),
                    v17 = LODWORD(result.z),
                    v18 = (__m128)v16,
                    v18.m128_f32[0] = (float)((float)(*(float *)&v16 * *(float *)&v16) + (float)(result.y * result.y))
                                    + (float)(*(float *)&v17 * *(float *)&v17),
                    v18.m128_f32[0] > 0.000099999997) )
              {
                if ( v18.m128_f32[0] == 0.0 )
                {
                  *(float *)&v16 = result.x * 0.0;
                  v20 = result.y * 0.0;
                  *(float *)&v17 = result.z * 0.0;
                }
                else
                {
                  v19 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v18));
                  *(float *)&v16 = result.x * v19;
                  v20 = result.y * v19;
                  *(float *)&v17 = result.z * v19;
                }
              }
              else
              {
                v21 = v2->mContext->mSimObject.m_pPointer;
                if ( v21 )
                  v22 = v21->m_pTransformNodeComponent;
                else
                  v22 = 0i64;
                UFG::TransformNodeComponent::UpdateWorldTransform(v22);
                v20 = v22->mWorldTransform.v0.y;
                v17 = LODWORD(v22->mWorldTransform.v0.z);
                v16 = LODWORD(v22->mWorldTransform.v0.x);
              }
              v23 = v2->m_Track;
              v31 = (__m128)v17;
              LODWORD(result.z) = v17;
              result.y = v20;
              LODWORD(result.x) = v16;
              v24 = 0.0;
              v25 = *((float *)&v23[1].mResourceOwner + 1);
              v26 = *((float *)&v23[1].vfptr + 1);
              v27 = *(float *)&v23[1].vfptr;
              v28 = *(float *)&v23[1].mResourceOwner;
              v29 = (float)(*(float *)&v16 * 0.0) - (float)(v20 * 0.0);
              v30 = v20 - (float)(*(float *)&v17 * 0.0);
              v31.m128_f32[0] = (float)(*(float *)&v17 * 0.0) - *(float *)&v16;
              impulse.x = 0.0;
              impulse.z = 0.0;
              v47 = (float)(v31.m128_f32[0] * *(float *)&v17) - (float)(v29 * v20);
              v32 = (float)(v29 * *(float *)&v16)
                  - (float)((float)(v20 - (float)(*(float *)&v17 * 0.0)) * *(float *)&v17);
              v48 = v32;
              v49 = (float)((float)(v20 - (float)(*(float *)&v17 * 0.0)) * v20)
                  - (float)(v31.m128_f32[0] * *(float *)&v16);
              v33 = (float)((float)(v20 - (float)(*(float *)&v17 * 0.0)) * v20)
                  - (float)(v31.m128_f32[0] * *(float *)&v16);
              v34 = 0.0;
              v44 = (float)(v32 * v32) + (float)(v47 * v47);
              impulse.y = 0.0;
              v35 = v33 * v33;
              v36 = (__m128)LODWORD(v44);
              if ( (float)(v44 + v35) > 0.000099999997 )
              {
                v36.m128_f32[0] = v44 + v35;
                v37 = (float)(v26 * v25) / COERCE_FLOAT(_mm_sqrt_ps(v36));
                v15 = v47 * v37;
                v34 = v48 * v37;
                v24 = v49 * v37;
                impulse.x = v47 * v37;
                impulse.y = v48 * v37;
                impulse.z = v49 * v37;
              }
              v38 = v31;
              v38.m128_f32[0] = (float)((float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(v30 * v30))
                              + (float)(v29 * v29);
              if ( v38.m128_f32[0] > 0.000099999997 )
              {
                LODWORD(v39) = COERCE_UNSIGNED_INT((float)(v27 * v25) / COERCE_FLOAT(_mm_sqrt_ps(v38))) ^ _xmm[0];
                v15 = v15 + (float)(v30 * v39);
                v34 = v34 + (float)(v31.m128_f32[0] * v39);
                v24 = v24 + (float)(v29 * v39);
                impulse.x = v15;
                impulse.y = v34;
                impulse.z = v24;
              }
              v40 = (__m128)v16;
              v40.m128_f32[0] = (float)((float)(*(float *)&v16 * *(float *)&v16) + (float)(v20 * v20))
                              + (float)(*(float *)&v17 * *(float *)&v17);
              if ( v40.m128_f32[0] > 0.000099999997 )
              {
                v41 = (float)(v28 * v25) / COERCE_FLOAT(_mm_sqrt_ps(v40));
                impulse.x = v15 + (float)(*(float *)&v16 * v41);
                impulse.y = v34 + (float)(v20 * v41);
                impulse.z = v24 + (float)(*(float *)&v17 * v41);
              }
              if ( v14->mPose.mRigHandle.mData )
                v42 = Skeleton::GetBoneID(v14->mPose.mRigHandle.mUFGSkeleton, *(_DWORD *)&v23[1].mBreakPoint);
              else
                v42 = -1;
              UFG::RagdollComponent::ApplyAngularImpulse(
                (UFG::RagdollComponent *)v5,
                v42,
                &impulse,
                *(float *)&v2->m_Track[1].m_TrackClassNameUID);
              v2->mFired = 1;
            }
          }
        }
      }
    }
  }
  return v2->mFired == 0;
}

// File Line: 439
// RVA: 0x2F2B90
void __fastcall RagdollMotorTask::Begin(RagdollMotorTask *this, ActionContext *context)
{
  RagdollMotorTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  UFG::Ragdoll *v6; // rbx
  ITrack *v7; // rsi
  float v8; // xmm6_4
  UFG::SimObjectCVBase *v9; // rcx
  unsigned __int16 v10; // dx
  UFG::CharacterAnimationComponent *v11; // rax
  Creature *v12; // rcx
  int v13; // eax

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[42].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      else
        v5 = (v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RagdollComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = (UFG::Ragdoll *)v5[1].m_BoundComponentHandles.mNode.mPrev;
      if ( v6 )
      {
        v7 = v2->m_Track;
        v8 = *(float *)&v7[1].vfptr;
        if ( HIDWORD(v7[1].vfptr) == UFG::gNullQSymbolUC.mUID )
        {
          UFG::Ragdoll::SetMotorMaxForce(v6, *(float *)&v7[1].vfptr);
        }
        else
        {
          v9 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
          if ( v9 )
          {
            v10 = v9->m_Flags;
            if ( (v10 >> 14) & 1 )
            {
              v11 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
            }
            else if ( (v10 & 0x8000u) == 0 )
            {
              if ( (v10 >> 13) & 1 )
              {
                v11 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v9);
              }
              else if ( (v10 >> 12) & 1 )
              {
                v11 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            (UFG::SimObjectGame *)&v9->vfptr,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
              }
              else
              {
                v11 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                            (UFG::SimObject *)&v9->vfptr,
                                                            UFG::CharacterAnimationComponent::_TypeUID);
              }
            }
            else
            {
              v11 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v9);
            }
            if ( v11 )
            {
              v12 = v11->mCreature;
              if ( v12 )
              {
                if ( v12->mPose.mRigHandle.mData )
                {
                  v13 = Skeleton::GetBoneID(v12->mPose.mRigHandle.mUFGSkeleton, HIDWORD(v7[1].vfptr));
                  if ( v13 >= 0 )
                    UFG::Ragdoll::SetMotorMaxForceAtJoint(v6, v8, v13);
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
  RagdollBlendMotorTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RagdollComponent *v5; // rax
  float v6; // xmm0_4
  ITrack *v7; // rax
  float v8; // xmm2_4
  float v9; // xmm1_4

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::RagdollComponent *)v3->m_Components.p[42].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v3->vfptr,
                                        UFG::RagdollComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = UFG::RagdollComponent::GetMotorMaxForce(v5);
      v7 = v2->m_Track;
      v2->mCurrentStrength = v6;
      v8 = *((float *)&v7[1].vfptr + 1);
      v9 = *(float *)&v7[1].vfptr - v6;
      if ( v8 <= 0.0 )
        v2->mDeltaStrength = v9 * 3.4028233e32;
      else
        v2->mDeltaStrength = v9 / v8;
    }
  }
}

// File Line: 496
// RVA: 0x307000
char __fastcall RagdollBlendMotorTask::Update(RagdollBlendMotorTask *this, float timeDelta)
{
  RagdollBlendMotorTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  float v4; // xmm6_4
  unsigned __int16 v5; // dx
  UFG::RagdollComponent *v6; // rcx
  UFG::SimComponent *v7; // rax
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  v4 = timeDelta;
  if ( v3 )
  {
    v5 = v3->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::RagdollComponent *)v3->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( (v5 & 0x8000u) == 0 )
      {
        if ( (v5 >> 13) & 1 )
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
        else
          v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RagdollComponent::_TypeUID);
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      v6 = (UFG::RagdollComponent *)v7;
    }
    if ( v6 )
    {
      v8 = v2->mDeltaStrength;
      v9 = (float)(v2->mDeltaStrength * v4) + v2->mCurrentStrength;
      v2->mCurrentStrength = v9;
      if ( v8 <= 0.0 )
      {
        if ( v8 >= 0.0 )
          goto LABEL_19;
        v10 = *(float *)&v2->m_Track[1].vfptr;
        if ( v9 >= v10 )
          goto LABEL_19;
      }
      else
      {
        v10 = *(float *)&v2->m_Track[1].vfptr;
        if ( v9 <= v10 )
        {
LABEL_19:
          UFG::RagdollComponent::SetMotorMaxForce(v6, v2->mCurrentStrength);
          return 1;
        }
      }
      v2->mCurrentStrength = v10;
      goto LABEL_19;
    }
  }
  return 1;
}

// File Line: 532
// RVA: 0x2F22E0
void __fastcall RagdollAquireTask::Begin(RagdollAquireTask *this, ActionContext *context)
{
  RagdollAquireTask *v2; // rdi
  UFG::RagdollComponent *v3; // rax
  UFG::RagdollComponent *v4; // rbx
  ITrack *v5; // rdx
  __int64 v6; // rcx
  UFG::RagdollComponent::PoseState v7; // esi
  int v8; // [rsp+20h] [rbp-18h]
  int v9; // [rsp+24h] [rbp-14h]
  int v10; // [rsp+28h] [rbp-10h]
  int v11; // [rsp+2Ch] [rbp-Ch]

  v2 = this;
  v3 = (UFG::RagdollComponent *)UFG::RagdollComponent::Acquire(context->mSimObject.m_pPointer);
  v4 = v3;
  if ( v3 )
  {
    v5 = v2->m_Track;
    v8 = 0;
    v6 = SLODWORD(v5[1].vfptr);
    v9 = 1;
    v10 = 5;
    v11 = 6;
    v7 = *(&v8 + v6);
    v3->mDesiredPoseState = v7;
    v3->mRagDollWeight = *((float *)&v2->m_Track[1].mResourceOwner + 1);
    UFG::RagdollComponent::SetPositionTrackingStiffness(v3, *((float *)&v2->m_Track[1].vfptr + 1));
    UFG::RagdollComponent::SetMotorMaxForce(v4, *(float *)&v2->m_Track[1].mResourceOwner);
    LODWORD(v4->mVelocityFromProxyScale) = v2->m_Track[1].m_TrackClassNameUID;
    UFG::RagdollComponent::SetLimitStiffness(v4, *(float *)&v2->m_Track[1].mBreakPoint);
    if ( v7 != v4->mPoseState && (unsigned int)v7 <= 1 )
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
  RagdollChangeModeTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rdx
  UFG::SimComponent *v6; // rax
  ITrack *v7; // rax
  __int64 v8; // rcx
  int v9; // [rsp+20h] [rbp-18h]
  int v10; // [rsp+24h] [rbp-14h]
  int v11; // [rsp+28h] [rbp-10h]
  int v12; // [rsp+2Ch] [rbp-Ch]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RagdollComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      v5 = v6;
    }
    if ( v5 )
    {
      v7 = v2->m_Track;
      v9 = 0;
      v10 = 1;
      v8 = SLODWORD(v7[1].vfptr);
      v11 = 5;
      v12 = 6;
      HIDWORD(v5[2].m_SafePointerList.mNode.mPrev) = *(&v9 + v8);
    }
  }
}

// File Line: 587
// RVA: 0x2F2D40
void __fastcall RagdollSetFrictionTask::Begin(RagdollSetFrictionTask *this, ActionContext *context)
{
  RagdollSetFrictionTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RagdollComponent *v5; // rcx
  UFG::SimComponent *v6; // rax

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::RagdollComponent *)v3->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RagdollComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      v5 = (UFG::RagdollComponent *)v6;
    }
    if ( v5 )
      UFG::RagdollComponent::SetFriction(v5, *(float *)&v2->m_Track[1].vfptr);
  }
}

// File Line: 603
// RVA: 0x2FFE50
void __fastcall RagdollSetFrictionTask::End(RagdollSetFrictionTask *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::RagdollComponent *v3; // rax

  v1 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::RagdollComponent *)v1->m_Components.p[42].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RagdollComponent::_TypeUID);
      }
      else if ( (v2 >> 12) & 1 )
      {
        v3 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RagdollComponent::_TypeUID);
      }
      else
      {
        v3 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v1->vfptr,
                                        UFG::RagdollComponent::_TypeUID);
      }
    }
    else
    {
      v3 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RagdollComponent::_TypeUID);
    }
    if ( v3 )
      UFG::RagdollComponent::SetFriction(v3, 0.30000001);
  }
}

// File Line: 615
// RVA: 0x2F2230
void __fastcall RagdollAdjustMassTask::Begin(RagdollAdjustMassTask *this, ActionContext *context)
{
  RagdollAdjustMassTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RagdollComponent *v5; // rcx
  UFG::SimComponent *v6; // rax
  float v7; // xmm1_4

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::RagdollComponent *)v3->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RagdollComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      v5 = (UFG::RagdollComponent *)v6;
    }
    if ( v5 )
    {
      v7 = *(float *)&v2->m_Track[1].vfptr;
      if ( v7 >= 0.001 )
        UFG::RagdollComponent::ScaleMass(v5, v7);
    }
  }
}

// File Line: 635
// RVA: 0x2FFAA0
void __fastcall RagdollAdjustMassTask::End(RagdollAdjustMassTask *this)
{
  RagdollAdjustMassTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::RagdollComponent *v4; // rcx
  UFG::SimComponent *v5; // rax
  float v6; // xmm0_4

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::RagdollComponent *)v2->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RagdollComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
      }
      v4 = (UFG::RagdollComponent *)v5;
    }
    if ( v4 )
    {
      v6 = *(float *)&v1->m_Track[1].vfptr;
      if ( v6 >= 0.001 )
        UFG::RagdollComponent::ScaleMass(v4, 1.0 / v6);
    }
  }
}

// File Line: 651
// RVA: 0x2F2700
void __fastcall RagdollChangeMotorTask::Begin(RagdollChangeMotorTask *this, ActionContext *context)
{
  RagdollChangeMotorTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RagdollComponent *v5; // rax
  float v6; // xmm0_4
  float *v7; // rax
  float v8; // xmm2_4

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::RagdollComponent *)v3->m_Components.p[42].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v3->vfptr,
                                        UFG::RagdollComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = UFG::RagdollComponent::GetMotorMaxForce(v5);
      v7 = (float *)v2->m_Track;
      v2->mCurrentStrength = v6;
      v8 = v7[13] - v7[12];
      if ( v8 <= 0.0 )
      {
        v2->mDeltaStrength = 0.0;
        v2->mCurrentStrength = v7[14];
      }
      else
      {
        v2->mDeltaStrength = (float)(v7[14] - v6) / v8;
      }
    }
  }
}

// File Line: 671
// RVA: 0x307290
char __fastcall RagdollChangeMotorTask::Update(RagdollChangeMotorTask *this, float timeDelta)
{
  RagdollChangeMotorTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RagdollComponent *v5; // rax
  float v6; // xmm6_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::RagdollComponent *)v3->m_Components.p[42].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v3->vfptr,
                                        UFG::RagdollComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = (float)(timeDelta * v2->mDeltaStrength) + v2->mCurrentStrength;
      v2->mCurrentStrength = v6;
      UFG::RagdollComponent::SetMotorMaxForce(v5, v6);
    }
  }
  return 1;
}

// File Line: 683
// RVA: 0x2FFCB0
void __fastcall RagdollChangeMotorTask::End(RagdollChangeMotorTask *this)
{
  RagdollChangeMotorTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::RagdollComponent *v4; // rcx
  UFG::SimComponent *v5; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::RagdollComponent *)v2->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RagdollComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
      }
      v4 = (UFG::RagdollComponent *)v5;
    }
    if ( v4 )
      UFG::RagdollComponent::SetMotorMaxForce(v4, *(float *)&v1->m_Track[1].vfptr);
  }
}

// File Line: 696
// RVA: 0x2F2560
void __fastcall RagdollChangeBlendWeightTask::Begin(RagdollChangeBlendWeightTask *this, ActionContext *context)
{
  RagdollChangeBlendWeightTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  float v6; // xmm2_4
  float *v7; // rax
  float v8; // xmm1_4

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[42].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RagdollComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = *(float *)&v5[2].vfptr;
      v7 = (float *)v2->m_Track;
      v2->mCurrentStrength = v6;
      v8 = v7[13] - v7[12];
      if ( v8 <= 0.0 )
      {
        v2->mDeltaStrength = 0.0;
        v2->mCurrentStrength = v7[14];
      }
      else
      {
        v2->mDeltaStrength = (float)(v7[14] - v6) / v8;
      }
    }
  }
}

// File Line: 716
// RVA: 0x3071D0
char __fastcall RagdollChangeBlendWeightTask::Update(RagdollChangeBlendWeightTask *this, float timeDelta)
{
  RagdollChangeBlendWeightTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rax
  float v6; // xmm6_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[42].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      else
      {
        v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RagdollComponent::_TypeUID);
      }
    }
    else
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = (float)(timeDelta * v2->mDeltaStrength) + v2->mCurrentStrength;
      v2->mCurrentStrength = v6;
      *(float *)&v5[2].vfptr = v6;
    }
  }
  return 1;
}

// File Line: 728
// RVA: 0x2FFC10
void __fastcall RagdollChangeBlendWeightTask::End(RagdollChangeBlendWeightTask *this)
{
  RagdollChangeBlendWeightTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::SimComponent *v4; // rdx
  UFG::SimComponent *v5; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = v2->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RagdollComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
      }
      v4 = v5;
    }
    if ( v4 )
      LODWORD(v4[2].vfptr) = v1->m_Track[1].vfptr;
  }
}

// File Line: 741
// RVA: 0x2F29B0
void __fastcall RagdollChangeVelocityTrackingStrTask::Begin(RagdollChangeVelocityTrackingStrTask *this, ActionContext *context)
{
  signed int v2; // esi
  RagdollChangeVelocityTrackingStrTask *v3; // rbx
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::RagdollComponent *v6; // rax
  float v7; // xmm0_4
  ITrack *v8; // rdi
  float v9; // xmm2_4
  UFG::SimObjectCVBase *v10; // rcx
  unsigned __int16 v11; // dx
  UFG::CharacterAnimationComponent *v12; // rax
  Creature *v13; // rcx

  v2 = -1;
  v3 = this;
  this->mContext = context;
  this->mSkeletonID = -1;
  v4 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v4 )
  {
    v5 = v4->m_Flags;
    if ( (v5 >> 14) & 1 )
    {
      v6 = (UFG::RagdollComponent *)v4->m_Components.p[42].m_pComponent;
    }
    else if ( (v5 & 0x8000u) == 0 )
    {
      if ( (v5 >> 13) & 1 )
        v6 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RagdollComponent::_TypeUID);
      else
        v6 = (UFG::RagdollComponent *)((v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v4,
                                                          UFG::RagdollComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                               (UFG::SimObject *)&v4->vfptr,
                                                                                               UFG::RagdollComponent::_TypeUID));
    }
    else
    {
      v6 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RagdollComponent::_TypeUID);
    }
    if ( v6 )
    {
      v7 = UFG::RagdollComponent::GetPositionTrackingStiffness(v6);
      v8 = v3->m_Track;
      v3->mCurrentStrength = v7;
      v9 = v8->mTimeEnd - v8->mTimeBegin;
      if ( v9 <= 0.0 )
      {
        v3->mDeltaStrength = 0.0;
        v3->mCurrentStrength = *(float *)&v8[1].vfptr;
      }
      else
      {
        v3->mDeltaStrength = (float)(*(float *)&v8[1].vfptr - v7) / v9;
      }
      if ( HIDWORD(v8[1].vfptr) != UFG::gNullQSymbolUC.mUID )
      {
        v10 = (UFG::SimObjectCVBase *)v3->mContext->mSimObject.m_pPointer;
        if ( v10 )
        {
          v11 = v10->m_Flags;
          if ( (v11 >> 14) & 1 )
          {
            v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
          }
          else if ( (v11 & 0x8000u) == 0 )
          {
            if ( (v11 >> 13) & 1 )
              v12 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v10);
            else
              v12 = (UFG::CharacterAnimationComponent *)((v11 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                             (UFG::SimObjectGame *)&v10->vfptr,
                                                                             UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v10->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
          }
          else
          {
            v12 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v10);
          }
          if ( v12 )
          {
            v13 = v12->mCreature;
            if ( v13 )
            {
              if ( v13->mPose.mRigHandle.mData )
                v2 = Skeleton::GetBoneID(v13->mPose.mRigHandle.mUFGSkeleton, HIDWORD(v8[1].vfptr));
              v3->mSkeletonID = v2;
            }
          }
        }
      }
    }
  }
}

// File Line: 773
// RVA: 0x307350
char __fastcall RagdollChangeVelocityTrackingStrTask::Update(RagdollChangeVelocityTrackingStrTask *this, float timeDelta)
{
  RagdollChangeVelocityTrackingStrTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RagdollComponent *v5; // rax
  int v6; // er8
  float v7; // xmm6_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::RagdollComponent *)v3->m_Components.p[42].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      else
        v5 = (UFG::RagdollComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v3,
                                                          UFG::RagdollComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                               (UFG::SimObject *)&v3->vfptr,
                                                                                               UFG::RagdollComponent::_TypeUID));
    }
    else
    {
      v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = v2->mSkeletonID;
      v7 = (float)(timeDelta * v2->mDeltaStrength) + v2->mCurrentStrength;
      v2->mCurrentStrength = v7;
      if ( v6 >= 0 )
      {
        UFG::RagdollComponent::SetPositionTrackingStiffnessAtJoint(v5, v7, v6);
        return 1;
      }
      UFG::RagdollComponent::SetPositionTrackingStiffness(v5, v7);
    }
  }
  return 1;
}

// File Line: 792
// RVA: 0x2FFD60
void __fastcall RagdollChangeVelocityTrackingStrTask::End(RagdollChangeVelocityTrackingStrTask *this)
{
  RagdollChangeVelocityTrackingStrTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::RagdollComponent *v4; // rcx
  UFG::SimComponent *v5; // rax
  int v6; // er8
  float v7; // xmm1_4

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::RagdollComponent *)v2->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RagdollComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
      }
      v4 = (UFG::RagdollComponent *)v5;
    }
    if ( v4 )
    {
      v6 = v1->mSkeletonID;
      v7 = *(float *)&v1->m_Track[1].vfptr;
      v1->mCurrentStrength = v7;
      if ( v6 < 0 )
        UFG::RagdollComponent::SetPositionTrackingStiffness(v4, v7);
      else
        UFG::RagdollComponent::SetPositionTrackingStiffnessAtJoint(v4, v7, v6);
    }
  }
}

// File Line: 814
// RVA: 0x2F27E0
void __fastcall RagdollChangeVelocityTrackingParamsRawTask::Begin(RagdollChangeVelocityTrackingParamsRawTask *this, ActionContext *context)
{
  RagdollChangeVelocityTrackingParamsRawTask *v2; // rsi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rbx
  UFG::SimComponent *v6; // rax
  ITrack *v7; // rdi
  UFG::SimObjectCVBase *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::CharacterAnimationComponent *v10; // rax
  Creature *v11; // rcx
  int v12; // eax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v13; // rbx
  int v14; // eax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v15; // rdx
  ITrack *v16; // rcx

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( (v4 & 0x8000u) == 0 )
      {
        if ( (v4 >> 13) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
        }
        else if ( (v4 >> 12) & 1 )
        {
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v6 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::RagdollComponent::_TypeUID);
        }
      }
      else
      {
        v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      v5 = v6;
    }
    if ( v5 )
    {
      v7 = v2->m_Track;
      if ( LODWORD(v7[1].vfptr) != UFG::gNullQSymbolUC.mUID )
      {
        v8 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
        if ( v8 )
        {
          v9 = v8->m_Flags;
          if ( (v9 >> 14) & 1 )
          {
            v10 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v8);
          }
          else if ( (v9 & 0x8000u) == 0 )
          {
            if ( (v9 >> 13) & 1 )
            {
              v10 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v8);
            }
            else if ( (v9 >> 12) & 1 )
            {
              v10 = (UFG::CharacterAnimationComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          (UFG::SimObjectGame *)&v8->vfptr,
                                                          UFG::CharacterAnimationComponent::_TypeUID);
            }
            else
            {
              v10 = (UFG::CharacterAnimationComponent *)UFG::SimObject::GetComponentOfType(
                                                          (UFG::SimObject *)&v8->vfptr,
                                                          UFG::CharacterAnimationComponent::_TypeUID);
            }
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
              if ( v11->mPose.mRigHandle.mData )
              {
                v12 = Skeleton::GetBoneID(v11->mPose.mRigHandle.mUFGSkeleton, (const unsigned int)v7[1].vfptr);
                if ( v12 >= 0 )
                {
                  v13 = v5[1].m_BoundComponentHandles.mNode.mPrev;
                  v14 = UFG::Ragdoll::GetRigidBodyID((UFG::Ragdoll *)v13, v12);
                  if ( v14 >= 0 )
                  {
                    v15 = &v13[8].mNext->mPrev[3 * v14];
                    v16 = v2->m_Track;
                    LODWORD(v15->mPrev) = HIDWORD(v16[1].vfptr);
                    HIDWORD(v15->mPrev) = v16[1].mResourceOwner;
                    LODWORD(v15->mNext) = HIDWORD(v16[1].mResourceOwner);
                    HIDWORD(v15->mNext) = v16[1].m_TrackClassNameUID;
                    LODWORD(v15[1].mPrev) = *(_DWORD *)&v16[1].mBreakPoint;
                    HIDWORD(v15[1].mPrev) = v16[1].mMasterRate.text.mOffset;
                    LODWORD(v15[1].mNext) = HIDWORD(v16[1].mMasterRate.text.mOffset);
                    HIDWORD(v15[1].mNext) = v16[1].mMasterRate.expression.mOffset;
                    LODWORD(v15[2].mPrev) = HIDWORD(v16[1].mMasterRate.expression.mOffset);
                    HIDWORD(v15[2].mPrev) = LODWORD(v16[1].mMasterRate.value);
                    LODWORD(v15[2].mNext) = *((_DWORD *)&v16[1].mMasterRate.value + 1);
                    HIDWORD(v15[2].mNext) = LODWORD(v16[1].mTimeBegin);
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
  RagdollChangeAngularLimitStrTask *v2; // rbx
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::RagdollComponent *v5; // rax
  float v6; // xmm0_4
  float *v7; // rax
  float v8; // xmm2_4

  v2 = this;
  this->mContext = context;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::RagdollComponent *)v3->m_Components.p[42].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      else if ( (v4 >> 12) & 1 )
      {
        v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      }
      else
      {
        v5 = (UFG::RagdollComponent *)UFG::SimObject::GetComponentOfType(
                                        (UFG::SimObject *)&v3->vfptr,
                                        UFG::RagdollComponent::_TypeUID);
      }
    }
    else
    {
      v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = UFG::RagdollComponent::GetLimitStiffness(v5);
      v7 = (float *)v2->m_Track;
      v2->mCurrentStrength = v6;
      v8 = v7[13] - v7[12];
      if ( v8 <= 0.0 )
      {
        v2->mDeltaStrength = 0.0;
        v2->mCurrentStrength = v7[14];
      }
      else
      {
        v2->mDeltaStrength = (float)(v7[14] - v6) / v8;
      }
    }
  }
}

// File Line: 887
// RVA: 0x3070F0
char __fastcall RagdollChangeAngularLimitStrTask::Update(RagdollChangeAngularLimitStrTask *this, float timeDelta)
{
  RagdollChangeAngularLimitStrTask *v2; // rbx
  UFG::SimObjectGame *v3; // r8
  unsigned __int16 v4; // cx
  UFG::RagdollComponent *v5; // rax
  float v6; // xmm6_4

  v2 = this;
  v3 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = (UFG::RagdollComponent *)v3->m_Components.p[42].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
        v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
      else
        v5 = (UFG::RagdollComponent *)((v4 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                          v3,
                                                          UFG::RagdollComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                               (UFG::SimObject *)&v3->vfptr,
                                                                                               UFG::RagdollComponent::_TypeUID));
    }
    else
    {
      v5 = (UFG::RagdollComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::RagdollComponent::_TypeUID);
    }
    if ( v5 )
    {
      v6 = (float)(timeDelta * v2->mDeltaStrength) + v2->mCurrentStrength;
      v2->mCurrentStrength = v6;
      if ( v6 <= 1.0 )
      {
        if ( v6 < 0.0 )
          v2->mCurrentStrength = 0.0;
      }
      else
      {
        v2->mCurrentStrength = 1.0;
      }
      UFG::RagdollComponent::SetLimitStiffness(v5, v2->mCurrentStrength);
    }
  }
  return 1;
}

// File Line: 908
// RVA: 0x2FFB60
void __fastcall RagdollChangeAngularLimitStrTask::End(RagdollChangeAngularLimitStrTask *this)
{
  RagdollChangeAngularLimitStrTask *v1; // rbx
  UFG::SimObjectGame *v2; // rcx
  unsigned __int16 v3; // dx
  UFG::RagdollComponent *v4; // rcx
  UFG::SimComponent *v5; // rax

  v1 = this;
  v2 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
  if ( v2 )
  {
    v3 = v2->m_Flags;
    if ( (v3 >> 14) & 1 )
    {
      v4 = (UFG::RagdollComponent *)v2->m_Components.p[42].m_pComponent;
    }
    else
    {
      if ( (v3 & 0x8000u) == 0 )
      {
        if ( (v3 >> 13) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
        }
        else if ( (v3 >> 12) & 1 )
        {
          v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v2->vfptr, UFG::RagdollComponent::_TypeUID);
        }
      }
      else
      {
        v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v2, UFG::RagdollComponent::_TypeUID);
      }
      v4 = (UFG::RagdollComponent *)v5;
    }
    if ( v4 )
      UFG::RagdollComponent::SetLimitStiffness(v4, *(float *)&v1->m_Track[1].vfptr);
  }
}

// File Line: 930
// RVA: 0x307420
bool __fastcall RagdollDeathImpulseTask::Update(RagdollDeathImpulseTask *this, float thedt)
{
  RagdollDeathImpulseTask *v2; // r15
  float v3; // xmm6_4
  UFG::SimObjectGame *v4; // rcx
  unsigned __int16 v5; // dx
  UFG::SimComponent *v6; // rbp
  UFG::SimComponent *v7; // rax
  UFG::SimObjectGame *v8; // rcx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  signed __int64 v11; // rsi
  int v12; // er12
  int v13; // edi
  UFG::SimObjectCVBase *v14; // rcx
  unsigned __int16 v15; // dx
  UFG::CharacterAnimationComponent *v16; // rax
  int v17; // ecx
  Creature *v18; // rbx
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v19; // rcx
  const char *v20; // rax
  __int64 v21; // rax
  hkArray<hkpRigidBody *,hkContainerHeapAllocator> *v22; // r14
  int v23; // edi
  __int64 v24; // rbx
  hkpRigidBody *v25; // rcx
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  UFG::qVector3 impulse; // [rsp+28h] [rbp-A0h]
  UFG::qVector3 location; // [rsp+38h] [rbp-90h]
  UFG::qVector3 v32; // [rsp+48h] [rbp-80h]
  UFG::qReflectHandleBase v33; // [rsp+58h] [rbp-70h]

  v2 = this;
  v3 = *(float *)&this->m_Track[1].vfptr;
  if ( !this->mFired )
  {
    v4 = (UFG::SimObjectGame *)this->mContext->mSimObject.m_pPointer;
    if ( v4 )
    {
      v5 = v4->m_Flags;
      if ( (v5 >> 14) & 1 )
      {
        v6 = v4->m_Components.p[42].m_pComponent;
      }
      else
      {
        if ( (v5 & 0x8000u) == 0 )
        {
          if ( (v5 >> 13) & 1 )
            v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RagdollComponent::_TypeUID);
          else
            v7 = (v5 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RagdollComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::RagdollComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::RagdollComponent::_TypeUID);
        }
        v6 = v7;
      }
      if ( v6 )
      {
        if ( LODWORD(v6[2].m_SafePointerList.mNode.mPrev) == 1 )
        {
          v8 = (UFG::SimObjectGame *)v2->mContext->mSimObject.m_pPointer;
          if ( v8 )
          {
            v9 = v8->m_Flags;
            if ( (v9 >> 14) & 1 )
            {
              v10 = v8->m_Components.p[15].m_pComponent;
            }
            else if ( (v9 & 0x8000u) == 0 )
            {
              if ( (v9 >> 13) & 1 )
                v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HitReactionComponent::_TypeUID);
              else
                v10 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::HitReactionComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v8->vfptr, UFG::HitReactionComponent::_TypeUID);
            }
            else
            {
              v10 = v8->m_Components.p[15].m_pComponent;
            }
            if ( v10 )
            {
              v11 = (signed __int64)&v10[2].m_BoundComponentHandles.mNode.mNext;
              v12 = *(_DWORD *)&v10[7].m_Flags;
              while ( v12 > 0 )
              {
                v13 = 1;
                v14 = (UFG::SimObjectCVBase *)v2->mContext->mSimObject.m_pPointer;
                if ( v14 )
                {
                  v15 = v14->m_Flags;
                  if ( (v15 >> 14) & 1 )
                  {
                    v16 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v14);
                  }
                  else if ( (v15 & 0x8000u) == 0 )
                  {
                    if ( (v15 >> 13) & 1 )
                      v16 = UFG::SimObjectProp::GetComponent<UFG::CharacterAnimationComponent>((UFG::SimObjectProp *)v14);
                    else
                      v16 = (UFG::CharacterAnimationComponent *)((v15 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                                     (UFG::SimObjectGame *)&v14->vfptr,
                                                                                     UFG::CharacterAnimationComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v14->vfptr, UFG::CharacterAnimationComponent::_TypeUID));
                  }
                  else
                  {
                    v16 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v14);
                  }
                  if ( v16 )
                  {
                    v17 = *(_DWORD *)(v11 + 4);
                    if ( v17 == gAttackCollisionExplosionNoDamage.m_EnumValue
                      || v17 == gAttackCollisionExplosion.m_EnumValue )
                    {
                      v22 = UFG::RagdollComponent::GetRigidBodies((UFG::RagdollComponent *)v6);
                      v23 = 0;
                      if ( v22->m_size > 0 )
                      {
                        v24 = 0i64;
                        do
                        {
                          v25 = v22->m_data[v24];
                          if ( v25 )
                          {
                            location.x = v25->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad.m128_f32[0];
                            location.y = v25->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad.m128_f32[1];
                            location.z = v25->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad.m128_f32[2];
                            v26 = hkpMotion::getMass((hkpMotion *)&v25->m_motion.vfptr) * 0.0125;
                            v27 = v3 * *(float *)(v11 + 216);
                            v28 = v3 * *(float *)(v11 + 220);
                            impulse.x = (float)(v3 * *(float *)(v11 + 212)) * v26;
                            impulse.y = v27 * v26;
                            impulse.z = v28 * v26;
                            UFG::RagdollComponent::ApplyImpulse((UFG::RagdollComponent *)v6, 1, &location, &impulse);
                          }
                          ++v23;
                          ++v24;
                        }
                        while ( v23 < v22->m_size );
                      }
                      goto $skip_to_next;
                    }
                    v18 = v16->mCreature;
                    if ( v18 )
                    {
                      if ( v18->mPose.mRigHandle.mData )
                        v13 = Skeleton::GetBoneID(v18->mPose.mRigHandle.mUFGSkeleton, g_symBip01Pelvis.mUID);
                      else
                        v13 = -1;
                      UFG::qReflectHandleBase::qReflectHandleBase(&v33);
                      v20 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v19);
                      v33.mTypeUID = UFG::qStringHash64(v20, 0xFFFFFFFFFFFFFFFFui64);
                      UFG::qReflectHandleBase::Init(&v33, v33.mTypeUID, *(_QWORD *)(v11 + 168));
                      if ( v33.mData )
                      {
                        v21 = LODWORD(v33.mData[2].mTypeUID);
                        if ( (_DWORD)v21 != -1 )
                        {
                          if ( v18->mPose.mRigHandle.mData )
                            v13 = Skeleton::GetBoneID(v18->mPose.mRigHandle.mUFGSkeleton, g_limbs[v21].mUID);
                          else
                            v13 = -1;
                        }
                      }
                      UFG::qReflectHandleBase::~qReflectHandleBase(&v33);
                    }
                  }
                }
                v32.x = v3 * *(float *)(v11 + 212);
                v32.y = v3 * *(float *)(v11 + 216);
                v32.z = v3 * *(float *)(v11 + 220);
                UFG::RagdollComponent::ApplyImpulse(
                  (UFG::RagdollComponent *)v6,
                  v13,
                  (UFG::qVector3 *)(v11 + 200),
                  &v32);
$skip_to_next:
                v2->mFired = 1;
                --v12;
                if ( *(_QWORD *)(v11 + 288) )
                  v11 = *(_QWORD *)(v11 + 288);
              }
            }
          }
        }
      }
    }
  }
  return v2->mFired == 0;
}

