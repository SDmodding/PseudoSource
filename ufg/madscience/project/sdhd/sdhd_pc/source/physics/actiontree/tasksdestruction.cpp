// File Line: 43
// RVA: 0x2EC610
void __fastcall DestructionSetDefinitionTask::Begin(DestructionSetDefinitionTask *this, ActionContext *context)
{
  ActionContext *v2; // r14
  DestructionSetDefinitionTask *v3; // rbp
  UFG::RigidBodyComponent *v4; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  UFG::CollisionMeshData *v8; // rdx
  int v9; // ebx
  char *v10; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rbx
  ITrack *v13; // rcx
  UFG::qReflectHandleBase v14; // [rsp+38h] [rbp-50h]

  v2 = context;
  v3 = this;
  v4 = (UFG::RigidBodyComponent *)UFG::SimObject::GetComponentOfType(
                                    context->mSimObject.m_pPointer,
                                    UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                    0,
                                    0i64);
  if ( v4 )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             v2->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             (UFG::SimComponent *)&v4->vfptr);
      UFG::qReflectHandleBase::qReflectHandleBase(&v14);
      v7 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v14.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
      v8 = v4->mCollisionMeshData;
      if ( v8 )
        UFG::qReflectHandleBase::operator=(&v14, (UFG::qReflectHandleBase *)&v8->mObjectProperties.mPrev);
      if ( v14.mData )
      {
        v9 = (int)v3->m_Track[1].vfptr;
        v10 = UFG::qReflectObject::GetName(v14.mData);
        if ( v9 == (unsigned int)UFG::qStringHashUpper32(v10, 0xFFFFFFFF) || LODWORD(v3->m_Track[1].vfptr) == -1 )
        {
          v11 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x80ui64, "StateMachineDefinition", 0i64, 1u);
          v12 = v11;
          if ( v11 )
          {
            UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject>((UFG::qReflectObjectType<UFG::StateMachineDefinition,UFG::qReflectObject> *)v11);
            v12->mNext = (UFG::allocator::free_link *)&UFG::StateMachineDefinition::`vftable;
            v12[11].mNext = 0i64;
            v12[10].mNext = 0i64;
            LODWORD(v12[12].mNext) = -1;
            LOWORD(v12[15].mNext) = 0;
            BYTE2(v12[15].mNext) = 0;
          }
          else
          {
            v12 = 0i64;
          }
          v13 = v3->m_Track;
          HIDWORD(v12[12].mNext) = HIDWORD(v13[1].vfptr);
          LODWORD(v12[13].mNext) = v13[1].mResourceOwner;
          HIDWORD(v12[13].mNext) = HIDWORD(v13[1].mResourceOwner);
          LODWORD(v12[14].mNext) = v13[1].m_TrackClassNameUID;
          HIDWORD(v12[14].mNext) = *(_DWORD *)&v13[1].mBreakPoint;
          UFG::RigidBodyComponent::CreateRuntimeStateMachineDefinition(v4, (UFG::StateMachineDefinition *)v12);
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v14);
      v4 = (UFG::RigidBodyComponent *)v5;
    }
    while ( v5 );
  }
}

// File Line: 69
// RVA: 0x2EBBF0
void __fastcall DestructionEventTask::Begin(DestructionEventTask *this, ActionContext *context)
{
  ActionContext *v2; // r15
  DestructionEventTask *v3; // rdi
  UFG::TransformNodeComponent *v4; // rsi
  UFG::TransformNodeComponent *v5; // r14
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  __int64 v8; // rdx
  int v9; // ebx
  char *v10; // rax
  ITrack *v11; // rax
  unsigned int v12; // ebx
  UFG::DynamicCoverComponent *v13; // rcx
  UFG::SimObject *v14; // rax
  UFG::SimObjectGame *v15; // rcx
  UFG::PhysicsRenderHelper *v16; // rcx
  unsigned __int16 v17; // dx
  UFG::SimComponent *v18; // rax
  ITrack *v19; // rax
  UFG::SimObjectGame *v20; // rcx
  UFG::PhysicsRenderHelper *v21; // rax
  unsigned __int16 v22; // dx
  float v23; // xmm0_4
  UFG::SimObjectGame *v24; // rcx
  unsigned __int16 v25; // dx
  UFG::SimComponent *v26; // rax
  ITrack *v27; // rax
  unsigned int v28; // eax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v29; // rax
  int v30; // er9
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v31; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v32; // rax
  UFG::SimObjectGame *v33; // rcx
  unsigned __int16 v34; // dx
  UFG::RigidBodyComponent *v35; // rax
  UFG::qReflectHandleBase v36; // [rsp+30h] [rbp-A8h]
  __int64 v37; // [rsp+58h] [rbp-80h]
  UFG::qMatrix44 mat; // [rsp+60h] [rbp-78h]
  UFG::qWiseSymbol result; // [rsp+128h] [rbp+50h]
  UFG::OneShotHandle pHandle; // [rsp+130h] [rbp+58h]

  v37 = -2i64;
  v2 = context;
  v3 = this;
  v4 = UFG::SimObject::GetComponentOfType(
         context->mSimObject.m_pPointer,
         UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
         0,
         0i64);
  if ( v4 )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             v2->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             (UFG::SimComponent *)&v4->vfptr);
      UFG::qReflectHandleBase::qReflectHandleBase(&v36);
      v7 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v36.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
      v8 = *(_QWORD *)&v4->mWorldTransform.v2.x;
      if ( v8 )
        UFG::qReflectHandleBase::operator=(&v36, (UFG::qReflectHandleBase *)(v8 + 224));
      if ( v36.mData )
      {
        v9 = (int)v3->m_Track[1].vfptr;
        v10 = UFG::qReflectObject::GetName(v36.mData);
        if ( v9 == (unsigned int)UFG::qStringHashUpper32(v10, 0xFFFFFFFF) || LODWORD(v3->m_Track[1].vfptr) == -1 )
        {
          if ( BYTE1(v3->m_Track[1].mResourceOwner) )
            UFG::RigidBody::SetCollisionLayer((UFG::RigidBody *)v4, 0x15u, -1, -1, -1);
          v11 = v3->m_Track;
          if ( HIDWORD(v11[1].vfptr) != -1 )
          {
            v12 = UFG::qSymbol::qSymbol(&result, HIDWORD(v11[1].vfptr))->mUID;
            _((AMD_HD3D *)result.mUID);
            UFG::RigidBody::GetTransform((UFG::RigidBody *)v4, &mat);
            pHandle.m_pOneShot = 0i64;
            UFG::OneShotPool::GetOneShotHandle(&pHandle, &mat);
            if ( UFG::OneShotHandle::IsValid(&pHandle) )
              UFG::OneShot::Play(pHandle.m_pOneShot, v12);
            UFG::OneShotHandle::Release(&pHandle);
          }
          if ( LOBYTE(v3->m_Track[1].mResourceOwner) )
          {
            hkpPhysicsSystem::hkpPhysicsSystem((hkpPhysicsSystem *)&mat.v1.z);
            UFG::Destruction::ForceFracture(
              UFG::Destruction::mInstance,
              (UFG::RigidBody *)v4,
              (hkpPhysicsSystem *)&mat.v1.z,
              0xFFFFFFFFi64);
            hkpPhysicsSystem::~hkpPhysicsSystem((hkpPhysicsSystem *)&mat.v1.z);
          }
          if ( BYTE4(v3->m_Track[1].mResourceOwner) )
          {
            v13 = (UFG::DynamicCoverComponent *)v4[1].mPrev;
            if ( v13 )
              UFG::DynamicCoverComponent::DisableCoverCorners(v13);
          }
          if ( BYTE5(v3->m_Track[1].mResourceOwner) )
          {
            v14 = v4[1].m_pSimObject;
            if ( v14 )
              LODWORD(v14[1].mNode.mChild[1]) |= 8u;
          }
          if ( *(_DWORD *)&v3->m_Track[1].mBreakPoint != -1 )
          {
            v15 = (UFG::SimObjectGame *)v4->m_pSimObject;
            if ( v15 )
            {
              v17 = v15->m_Flags;
              if ( (v17 >> 14) & 1 )
              {
                v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::PhysicsRenderHelper::_TypeUID);
              }
              else if ( (v17 & 0x8000u) == 0 )
              {
                if ( (v17 >> 13) & 1 )
                {
                  v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::PhysicsRenderHelper::_TypeUID);
                }
                else if ( (v17 >> 12) & 1 )
                {
                  v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::PhysicsRenderHelper::_TypeUID);
                }
                else
                {
                  v18 = UFG::SimObject::GetComponentOfType(
                          (UFG::SimObject *)&v15->vfptr,
                          UFG::PhysicsRenderHelper::_TypeUID);
                }
              }
              else
              {
                v18 = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::PhysicsRenderHelper::_TypeUID);
              }
              v16 = (UFG::PhysicsRenderHelper *)v18;
            }
            else
            {
              v16 = 0i64;
            }
            UFG::PhysicsRenderHelper::SwapRenderModel(v16, *(_DWORD *)&v3->m_Track[1].mBreakPoint);
          }
          if ( BYTE6(v3->m_Track[1].mResourceOwner) )
            UFG::RigidBody::SetMotionType((UFG::RigidBody *)v4, 0x80u);
          v19 = v3->m_Track;
          if ( HIBYTE(v19[1].mResourceOwner) )
            UFG::RigidBody::SetCollisionLayer((UFG::RigidBody *)v4, v19[1].m_TrackClassNameUID, -1, -1, -1);
          if ( BYTE4(v3->m_Track[1].mMasterRate.text.mOffset) )
          {
            v20 = (UFG::SimObjectGame *)v4->m_pSimObject;
            if ( v20 )
            {
              v22 = v20->m_Flags;
              if ( (v22 >> 14) & 1 )
              {
                v21 = (UFG::PhysicsRenderHelper *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v20,
                                                    UFG::PhysicsRenderHelper::_TypeUID);
              }
              else if ( (v22 & 0x8000u) == 0 )
              {
                if ( (v22 >> 13) & 1 )
                {
                  v21 = (UFG::PhysicsRenderHelper *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v20,
                                                      UFG::PhysicsRenderHelper::_TypeUID);
                }
                else if ( (v22 >> 12) & 1 )
                {
                  v21 = (UFG::PhysicsRenderHelper *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                      v20,
                                                      UFG::PhysicsRenderHelper::_TypeUID);
                }
                else
                {
                  v21 = (UFG::PhysicsRenderHelper *)UFG::SimObject::GetComponentOfType(
                                                      (UFG::SimObject *)&v20->vfptr,
                                                      UFG::PhysicsRenderHelper::_TypeUID);
                }
              }
              else
              {
                v21 = (UFG::PhysicsRenderHelper *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v20,
                                                    UFG::PhysicsRenderHelper::_TypeUID);
              }
            }
            else
            {
              v21 = 0i64;
            }
            UFG::PhysicsRenderHelper::DisableSelfIllumination(v21);
          }
          v23 = *(float *)&v3->m_Track[1].mMasterRate.expression.mOffset;
          if ( v23 >= 0.0 )
            v4[1].mWorldTransform.v3.z = v23;
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v36);
      v4 = v5;
    }
    while ( v5 );
  }
  if ( BYTE2(v3->m_Track[1].mResourceOwner) )
  {
    v24 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
    if ( v24 )
    {
      v25 = v24->m_Flags;
      if ( (v25 >> 14) & 1 )
      {
        v26 = v24->m_Components.p[14].m_pComponent;
      }
      else if ( (v25 & 0x8000u) == 0 )
      {
        if ( (v25 >> 13) & 1 )
          v26 = v24->m_Components.p[9].m_pComponent;
        else
          v26 = (v25 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v24,
                                    UFG::CompositeDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v24->vfptr,
                                                                                   UFG::CompositeDrawableComponent::_TypeUID);
      }
      else
      {
        v26 = v24->m_Components.p[14].m_pComponent;
      }
      if ( v26 )
        Render::IDecalScenery::RemoveAttachedDecals((Render::IDecalScenery *)&v26[1], 0xFFFFFFFF);
    }
  }
  v27 = v3->m_Track;
  if ( LODWORD(v27[1].mMasterRate.text.mOffset) != -1 )
  {
    v28 = UFG::qSymbol::qSymbol(&result, v27[1].mMasterRate.text.mOffset)->mUID;
    v36.mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v36;
    v36.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v36;
    LODWORD(v36.mTypeUID) = v28;
    *(unsigned __int64 *)((char *)&v36.mTypeUID + 4) = 0i64;
    HIDWORD(v36.mNameUID) = 0;
    if ( gVisualTreatmentEnum.m_enumLists.size )
    {
      TracksEnum<unsigned long>::ResolveBinding(&gVisualTreatmentEnum, (TracksEnumBinding<unsigned long> *)&v36);
    }
    else
    {
      v29 = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev;
      gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev->mNext = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v36;
      v36.mPrev = v29;
      v36.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList;
      gVisualTreatmentEnum.m_UnresolvedTracksEnumBindingList.mNode.mPrev = (UFG::qNode<TracksEnumBinding<unsigned long>,TracksEnumBinding<unsigned long> > *)&v36;
    }
    v30 = HIDWORD(v36.mTypeUID);
    v31 = v36.mPrev;
    v32 = v36.mNext;
    v36.mPrev->mNext = v36.mNext;
    v32->mPrev = v31;
    v36.mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v36;
    v36.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v36;
    UFG::RenderWorld::VisualTreatmentPostEffect_StartVisualTreatment(v30, 0, 0);
  }
  if ( BYTE3(v3->m_Track[1].mResourceOwner) )
  {
    v33 = (UFG::SimObjectGame *)v2->mSimObject.m_pPointer;
    if ( v33 )
    {
      v34 = v33->m_Flags;
      if ( (v34 >> 14) & 1 )
      {
        v35 = (UFG::RigidBodyComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v33,
                                           UFG::RigidBodyComponent::_TypeUID);
      }
      else if ( (v34 & 0x8000u) == 0 )
      {
        if ( (v34 >> 13) & 1 )
        {
          v35 = (UFG::RigidBodyComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v33,
                                             UFG::RigidBodyComponent::_TypeUID);
        }
        else if ( (v34 >> 12) & 1 )
        {
          v35 = (UFG::RigidBodyComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                             v33,
                                             UFG::RigidBodyComponent::_TypeUID);
        }
        else
        {
          v35 = (UFG::RigidBodyComponent *)UFG::SimObject::GetComponentOfType(
                                             (UFG::SimObject *)&v33->vfptr,
                                             UFG::RigidBodyComponent::_TypeUID);
        }
      }
      else
      {
        v35 = (UFG::RigidBodyComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v33,
                                           UFG::RigidBodyComponent::_TypeUID);
      }
      if ( v35 )
        UFG::RigidBodyComponent::Delete(v35);
    }
  }
}

// File Line: 182
// RVA: 0x2EBAE0
void __fastcall DestructionEnableRiggedGeoTask::Begin(DestructionEnableRiggedGeoTask *this, ActionContext *context)
{
  DestructionEnableRiggedGeoTask *v2; // rdi
  UFG::SimObjectGame *v3; // rcx
  unsigned __int16 v4; // dx
  UFG::SimComponent *v5; // rbx
  UFG::SimComponent *v6; // rax
  unsigned int v7; // esi
  ModelType *v8; // rbp
  UFG::qBaseNodeRB *v9; // rax
  unsigned int v10; // eax
  UFG::qWiseSymbol result; // [rsp+38h] [rbp+10h]

  v2 = this;
  v3 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( v3 )
  {
    v4 = v3->m_Flags;
    if ( (v4 >> 14) & 1 )
    {
      v5 = v3->m_Components.p[14].m_pComponent;
    }
    else if ( (v4 & 0x8000u) == 0 )
    {
      if ( (v4 >> 13) & 1 )
      {
        v5 = v3->m_Components.p[9].m_pComponent;
      }
      else
      {
        if ( (v4 >> 12) & 1 )
          v6 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CompositeDrawableComponent::_TypeUID);
        else
          v6 = UFG::SimObject::GetComponentOfType(
                 (UFG::SimObject *)&v3->vfptr,
                 UFG::CompositeDrawableComponent::_TypeUID);
        v5 = v6;
      }
    }
    else
    {
      v5 = v3->m_Components.p[14].m_pComponent;
    }
    if ( v5 )
    {
      UFG::qSymbol::qSymbol(&result, (unsigned int)v2->m_Track[1].vfptr);
      v7 = result.mUID;
      v8 = (ModelType *)v5[22].m_SafePointerList.mNode.mNext;
      ModelType::SetRigidModelVisibilityOnBone(
        (ModelType *)v5[22].m_SafePointerList.mNode.mNext,
        result.mUID,
        BYTE4(v2->m_Track[1].vfptr) != 0);
      if ( BYTE5(v2->m_Track[1].vfptr) )
      {
        v9 = ModelType::GetSkeleton(v8);
        v10 = Skeleton::GetBoneID((Skeleton *)v9, v7);
        Render::IDecalScenery::RemoveAttachedDecals((Render::IDecalScenery *)&v5[1], v10);
      }
    }
  }
}

// File Line: 206
// RVA: 0x2EC930
void __fastcall DestructionSpawnPropertySetTask::Begin(DestructionSpawnPropertySetTask *this, ActionContext *context)
{
  ActionContext *v2; // r15
  DestructionSpawnPropertySetTask *v3; // r14
  UFG::RigidBody *v4; // rdi
  bool i; // zf
  UFG::TransformNodeComponent *v6; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *v8; // rax
  UFG::CollisionMeshData *v9; // rdx
  int v10; // ebx
  char *v11; // rax
  float *v12; // rax
  float v13; // xmm6_4
  float v14; // xmm7_4
  __m128 v15; // xmm9
  __m128 v16; // xmm10
  __m128 v17; // xmm14
  ITrack *v18; // rax
  float v19; // xmm6_4
  float v20; // xmm7_4
  __m128 v21; // xmm9
  __m128 v22; // xmm13
  __m128 v23; // xmm7
  __m128 v24; // xmm8
  __m128 v25; // xmm3
  ITrack *v26; // rcx
  float v27; // xmm0_4
  __m128 v28; // xmm1
  __m128 v29; // xmm2
  UFG::qPropertySet *v30; // rbx
  __m128 v31; // xmm11
  __m128 v32; // xmm12
  __m128 v33; // xmm9
  __m128 v34; // xmm10
  __m128 v35; // xmm6
  __m128 v36; // xmm2
  __m128 v37; // xmm3
  __m128 v38; // xmm1
  __m128 v39; // xmm11
  UFG::SimObject *v40; // rax
  float v41; // xmm10_4
  float v42; // xmm9_4
  float v43; // xmm7_4
  float v44; // xmm6_4
  float v45; // xmm8_4
  __m128 v46; // xmm2
  UFG::RigidBody *v47; // rax
  UFG::RigidBody *v48; // rbx
  __m128 v49; // [rsp+30h] [rbp-A8h]
  __m128 v50; // [rsp+40h] [rbp-98h]
  UFG::qSymbol result; // [rsp+50h] [rbp-88h]
  __m128 v52; // [rsp+58h] [rbp-80h]
  __m256i v53; // [rsp+68h] [rbp-70h]
  UFG::qVector4 v54; // [rsp+88h] [rbp-50h]
  UFG::qVector4 v55; // [rsp+98h] [rbp-40h]
  __m128 v56; // [rsp+A8h] [rbp-30h]
  __m128 v57; // [rsp+B8h] [rbp-20h]
  __m128 v58; // [rsp+C8h] [rbp-10h]
  UFG::qMatrix44 dest; // [rsp+D8h] [rbp+0h]
  UFG::qMatrix44 v60; // [rsp+118h] [rbp+40h]
  UFG::qMatrix44 v61; // [rsp+158h] [rbp+80h]
  UFG::qReflectHandleBase v62; // [rsp+198h] [rbp+C0h]
  __m128 v63; // [rsp+1C8h] [rbp+F0h]
  __int64 v64; // [rsp+1D8h] [rbp+100h]
  __m128 v65; // [rsp+1E0h] [rbp+108h]
  __m128 v66; // [rsp+1F8h] [rbp+120h]
  __m128 v67; // [rsp+208h] [rbp+130h]
  __m128 v68; // [rsp+228h] [rbp+150h]
  float v69; // [rsp+310h] [rbp+238h]
  float v70; // [rsp+318h] [rbp+240h]
  float vars0; // [rsp+320h] [rbp+248h]

  v64 = -2i64;
  v2 = context;
  v3 = this;
  v4 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                           context->mSimObject.m_pPointer,
                           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                           0,
                           0i64);
  for ( i = v4 == 0i64; !i; i = v6 == 0i64 )
  {
    v6 = UFG::SimObject::GetComponentOfType(
           v2->mSimObject.m_pPointer,
           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
           0,
           (UFG::SimComponent *)&v4->vfptr);
    UFG::qReflectHandleBase::qReflectHandleBase(&v62);
    v8 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
    v62.mTypeUID = UFG::qStringHash64(v8, 0xFFFFFFFFFFFFFFFFui64);
    v9 = v4->mCollisionMeshData;
    if ( v9 )
      UFG::qReflectHandleBase::operator=(&v62, (UFG::qReflectHandleBase *)&v9->mObjectProperties.mPrev);
    if ( v62.mData )
    {
      v10 = (int)v3->m_Track[1].vfptr;
      v11 = UFG::qReflectObject::GetName(v62.mData);
      if ( v10 == (unsigned int)UFG::qStringHashUpper32(v11, 0xFFFFFFFF) || LODWORD(v3->m_Track[1].vfptr) == -1 )
      {
        UFG::RigidBody::GetTransform(v4, (UFG::qMatrix44 *)&v52.m128_u16[4]);
        *(UFG::qVector4 *)&v53.m256i_u64[2] = UFG::qMatrix44::msIdentity.v0;
        v54 = UFG::qMatrix44::msIdentity.v1;
        v55 = UFG::qMatrix44::msIdentity.v2;
        v56.m128_i32[3] = LODWORD(UFG::qMatrix44::msIdentity.v3.w);
        v12 = (float *)v3->m_Track;
        v13 = (float)(v12[20] * 3.1415927) * 0.0055555557;
        v14 = (float)(v12[21] * 3.1415927) * 0.0055555557;
        UFG::qRotationMatrixX(&dest, (float)(v12[19] * 3.1415927) * 0.0055555557);
        UFG::qRotationMatrixY(&v61, v13);
        UFG::qRotationMatrixZ(&v60, v14);
        v15 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), (__m128)v61.v3),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0), (__m128)v61.v0), _xmm),
                    _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85), (__m128)v61.v1)),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170), (__m128)v61.v2)));
        v16 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255), (__m128)v61.v3),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0), (__m128)v61.v0),
                      (__m128)0i64),
                    _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85), (__m128)v61.v1)),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170), (__m128)v61.v2)));
        v17 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), (__m128)v61.v3),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0), (__m128)v61.v0),
                      (__m128)0i64),
                    _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85), (__m128)v61.v1)),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170), (__m128)v61.v2)));
        v49 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), (__m128)v61.v2),
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0), (__m128)v61.v0),
                      (__m128)0i64),
                    _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85), (__m128)v61.v1))),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), (__m128)v61.v3));
        v50 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), (__m128)v60.v0);
        v65 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(v50, _xmm), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), (__m128)v60.v1)),
                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), (__m128)v60.v2)),
                _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), (__m128)v60.v3));
        v57 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), (__m128)v60.v1),
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), (__m128)v60.v0), (__m128)0i64)),
                  _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), (__m128)v60.v2)),
                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 255), (__m128)v60.v3));
        v58 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), (__m128)v60.v0), (__m128)0i64),
                    _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), (__m128)v60.v1)),
                  _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), (__m128)v60.v2)),
                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 255), (__m128)v60.v3));
        v56 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v49, v49, 255), (__m128)v60.v3),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), (__m128)v60.v0), (__m128)0i64),
                    _mm_mul_ps(_mm_shuffle_ps(v49, v49, 85), (__m128)v60.v1)),
                  _mm_mul_ps(_mm_shuffle_ps(v49, v49, 170), (__m128)v60.v2)));
        v18 = v3->m_Track;
        v56.m128_u64[0] = (unsigned __int64)v18[1].mResourceOwner;
        v56.m128_i32[2] = v18[1].m_TrackClassNameUID;
        v19 = (float)(*((float *)&v18[1].mMasterRate.expression.mOffset + 1) * 3.1415927) * 0.0055555557;
        v20 = (float)(v18[1].mMasterRate.value * 3.1415927) * 0.0055555557;
        UFG::qRotationMatrixX(
          &dest,
          (float)(*(float *)&v18[1].mMasterRate.expression.mOffset * 3.1415927) * 0.0055555557);
        UFG::qRotationMatrixY(&v61, v19);
        UFG::qRotationMatrixZ(&v60, v20);
        v49 = _mm_mul_ps((__m128)v61.v1, _mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85));
        v21 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      (__m128)0i64,
                      _mm_mul_ps((__m128)v61.v0, _mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0))),
                    _mm_mul_ps((__m128)v61.v1, _mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85))),
                  _mm_mul_ps((__m128)v61.v2, _mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170))),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), (__m128)v61.v3));
        v22 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      (__m128)0i64,
                      _mm_mul_ps((__m128)v61.v0, _mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0))),
                    v49),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), (__m128)v61.v2)),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), (__m128)v61.v3));
        v23 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      (__m128)0i64,
                      _mm_mul_ps((__m128)v61.v0, _mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0))),
                    _mm_mul_ps((__m128)v61.v1, _mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85))),
                  _mm_mul_ps((__m128)v61.v2, _mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170))),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), (__m128)v61.v3));
        v24 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      (__m128)0i64,
                      _mm_mul_ps((__m128)v61.v0, _mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0))),
                    _mm_mul_ps((__m128)v61.v1, _mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85))),
                  _mm_mul_ps((__m128)v61.v2, _mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170))),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255), (__m128)v61.v3));
        v50 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), (__m128)v60.v0);
        v25 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps((__m128)v60.v2, _mm_shuffle_ps(v21, v21, 170)),
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), (__m128)v60.v0), (__m128)0i64),
                    _mm_mul_ps((__m128)v60.v1, _mm_shuffle_ps(v21, v21, 85)))),
                _mm_mul_ps((__m128)v60.v3, _mm_shuffle_ps(v21, v21, 255)));
        v66 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(v50, _xmm), _mm_mul_ps((__m128)v60.v1, _mm_shuffle_ps(v23, v23, 85))),
                  _mm_mul_ps((__m128)v60.v2, _mm_shuffle_ps(v23, v23, 170))),
                _mm_mul_ps((__m128)v60.v3, _mm_shuffle_ps(v23, v23, 255)));
        v67 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), (__m128)v60.v0), (__m128)0i64),
                    _mm_mul_ps((__m128)v60.v1, _mm_shuffle_ps(v24, v24, 85))),
                  _mm_mul_ps((__m128)v60.v2, _mm_shuffle_ps(v24, v24, 170))),
                _mm_mul_ps((__m128)v60.v3, _mm_shuffle_ps(v24, v24, 255)));
        v68 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), (__m128)v60.v0), (__m128)0i64),
                    _mm_mul_ps((__m128)v60.v1, _mm_shuffle_ps(v22, v22, 85))),
                  _mm_mul_ps((__m128)v60.v2, _mm_shuffle_ps(v22, v22, 170))),
                _mm_mul_ps((__m128)v60.v3, _mm_shuffle_ps(v22, v22, 255)));
        v26 = v3->m_Track;
        v27 = *(&v26[1].mMasterRate.value + 1);
        v28 = _mm_shuffle_ps(v25, v25, 170);
        v28.m128_f32[0] = v28.m128_f32[0] * v27;
        v63 = v28;
        v29 = _mm_shuffle_ps(v25, v25, 85);
        v29.m128_f32[0] = v29.m128_f32[0] * v27;
        v49 = v29;
        v25.m128_f32[0] = v25.m128_f32[0] * v27;
        v50 = v25;
        v69 = v26[1].mTimeBegin;
        v70 = v26[1].mTimeEnd;
        vars0 = *(float *)&v26[2].vfptr;
        v30 = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&v26[1].vfptr + 1);
        if ( v30 )
        {
          UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, (UFG::qSymbol *)&v3->m_Track[1].vfptr + 1);
          v31 = v57;
          v32 = v58;
          v33 = _mm_mul_ps(*(__m128 *)((char *)&v52 + 8), _mm_shuffle_ps(v57, v57, 0));
          v34 = _mm_mul_ps(*(__m128 *)((char *)&v52 + 8), _mm_shuffle_ps(v58, v58, 0));
          v58 = _mm_mul_ps(*(__m128 *)((char *)&v52 + 8), _mm_shuffle_ps(v56, v56, 0));
          v35 = _mm_mul_ps(*(__m128 *)&v53.m256i_u64[1], _mm_shuffle_ps(v57, v57, 85));
          v36 = _mm_mul_ps(v52, _mm_shuffle_ps(v57, v57, 170));
          v57 = _mm_mul_ps(v52, _mm_shuffle_ps(v56, v56, 170));
          v37 = _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(_mm_add_ps((__m128)0i64, v33), v35), v36),
                  _mm_mul_ps(*(__m128 *)v53.m256i_i8, _mm_shuffle_ps(v31, v31, 255)));
          v38 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps((__m128)0i64, v34),
                      _mm_mul_ps(*(__m128 *)&v53.m256i_u64[1], _mm_shuffle_ps(v32, v32, 85))),
                    _mm_mul_ps(v52, _mm_shuffle_ps(v32, v32, 170))),
                  _mm_mul_ps(*(__m128 *)v53.m256i_i8, _mm_shuffle_ps(v32, v32, 255)));
          v39 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps((__m128)0i64, v58),
                      _mm_mul_ps(*(__m128 *)&v53.m256i_u64[1], _mm_shuffle_ps(v56, v56, 85))),
                    v57),
                  _mm_mul_ps(*(__m128 *)v53.m256i_i8, _mm_shuffle_ps(v56, v56, 255)));
          *(__m128 *)&v53.m256i_u64[2] = _mm_add_ps(
                                           _mm_add_ps(
                                             _mm_add_ps(
                                               _mm_add_ps(
                                                 (__m128)0i64,
                                                 _mm_mul_ps(*(__m128 *)((char *)&v52 + 8), _mm_shuffle_ps(v65, v65, 0))),
                                               _mm_mul_ps(*(__m128 *)&v53.m256i_u64[1], _mm_shuffle_ps(v65, v65, 85))),
                                             _mm_mul_ps(v52, _mm_shuffle_ps(v65, v65, 170))),
                                           _mm_mul_ps(*(__m128 *)v53.m256i_i8, _mm_shuffle_ps(v65, v65, 255)));
          v54 = (UFG::qVector4)v37;
          v55 = (UFG::qVector4)v38;
          v56 = v39;
          v40 = UFG::SpawnInfoInterface::SpawnObject(
                  &result,
                  v30,
                  (UFG::qMatrix44 *)&v53.m256i_u64[2],
                  Count,
                  0i64,
                  0i64);
          v41 = v49.m128_f32[0];
          v42 = v63.m128_f32[0];
          v43 = v70;
          v44 = v69;
          v45 = vars0;
          if ( fsqrt(
                 (float)((float)(v50.m128_f32[0] * v50.m128_f32[0]) + (float)(v49.m128_f32[0] * v49.m128_f32[0]))
               + (float)(v63.m128_f32[0] * v63.m128_f32[0])) > 0.0
            || (v46 = (__m128)LODWORD(v70),
                v46.m128_f32[0] = (float)((float)(v70 * v70) + (float)(v69 * v69)) + (float)(vars0 * vars0),
                COERCE_FLOAT(_mm_sqrt_ps(v46)) != 0.0) )
          {
            if ( v40 )
            {
              v47 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(v40, UFG::RigidBodyComponent::_TypeUID);
              v48 = v47;
              if ( v47 )
              {
                v49.m128_f32[0] = (float)((float)(v52.m128_f32[2] * v50.m128_f32[0])
                                        + (float)(v49.m128_f32[0] * *(float *)&v53.m256i_i32[2]))
                                + (float)(v42 * v52.m128_f32[0]);
                v49.m128_f32[1] = (float)((float)(v52.m128_f32[3] * v50.m128_f32[0])
                                        + (float)(v41 * *(float *)&v53.m256i_i32[3]))
                                + (float)(v42 * v52.m128_f32[1]);
                v49.m128_f32[2] = (float)((float)(*(float *)v53.m256i_i32 * v50.m128_f32[0])
                                        + (float)(v41 * *(float *)&v53.m256i_i32[4]))
                                + (float)(v42 * v52.m128_f32[2]);
                UFG::RigidBody::ApplyLinearImpulse(v47, (UFG::qVector3 *)&v49);
                v49.m128_f32[0] = (float)((float)(v44 * v52.m128_f32[2]) + (float)(v43 * *(float *)&v53.m256i_i32[2]))
                                + (float)(v45 * v52.m128_f32[0]);
                v49.m128_f32[1] = (float)((float)(v44 * v52.m128_f32[3]) + (float)(v43 * *(float *)&v53.m256i_i32[3]))
                                + (float)(v45 * v52.m128_f32[1]);
                v49.m128_f32[2] = (float)((float)(v44 * *(float *)v53.m256i_i32)
                                        + (float)(v43 * *(float *)&v53.m256i_i32[4]))
                                + (float)(v45 * v52.m128_f32[2]);
                UFG::RigidBody::ApplyAngularImpulse(v48, (UFG::qVector3 *)&v49);
              }
            }
          }
        }
        UFG::qReflectHandleBase::~qReflectHandleBase(&v62);
        return;
      }
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v62);
    v4 = (UFG::RigidBody *)v6;
  }
}

// File Line: 287
// RVA: 0x2EC7B0
void __fastcall DestructionSpawnPhantomVolumeTask::Begin(DestructionSpawnPhantomVolumeTask *this, ActionContext *context)
{
  ActionContext *v2; // r14
  DestructionSpawnPhantomVolumeTask *v3; // rbp
  UFG::TransformNodeComponent *v4; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  __int64 v8; // rdx
  int v9; // ebx
  char *v10; // rax
  ITrack *v11; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::StateMachineComponent *v16; // rcx
  UFG::qVector3 extents; // [rsp+38h] [rbp-50h]
  UFG::qVector3 offset; // [rsp+48h] [rbp-40h]
  UFG::qReflectHandleBase v19; // [rsp+58h] [rbp-30h]

  v2 = context;
  v3 = this;
  v4 = UFG::SimObject::GetComponentOfType(
         context->mSimObject.m_pPointer,
         UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
         0,
         0i64);
  if ( v4 )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             v2->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             (UFG::SimComponent *)&v4->vfptr);
      UFG::qReflectHandleBase::qReflectHandleBase(&v19);
      v7 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v19.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
      v8 = *(_QWORD *)&v4->mWorldTransform.v2.x;
      if ( v8 )
        UFG::qReflectHandleBase::operator=(&v19, (UFG::qReflectHandleBase *)(v8 + 224));
      if ( v19.mData )
      {
        v9 = (int)v3->m_Track[1].vfptr;
        v10 = UFG::qReflectObject::GetName(v19.mData);
        if ( v9 == (unsigned int)UFG::qStringHashUpper32(v10, 0xFFFFFFFF) || LODWORD(v3->m_Track[1].vfptr) == -1 )
        {
          v11 = v3->m_Track;
          v12 = *((float *)&v11[1].mResourceOwner + 1);
          v13 = *(float *)&v11[1].m_TrackClassNameUID;
          offset.x = *(float *)&v11[1].mResourceOwner;
          offset.y = v12;
          offset.z = v13;
          v14 = *(float *)&v11[1].mMasterRate.text.mOffset;
          v15 = *((float *)&v11[1].mMasterRate.text.mOffset + 1);
          extents.x = *(float *)&v11[1].mBreakPoint;
          extents.y = v14;
          extents.z = v15;
          v16 = *(UFG::StateMachineComponent **)&v4[1].mChanged;
          if ( v16 )
            UFG::StateMachineComponent::SpawnDestructionPhantomVolume(
              v16,
              HIDWORD(v11[1].vfptr),
              &offset,
              &extents,
              *(float *)&v11[1].mMasterRate.expression.mOffset);
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v19);
      v4 = v5;
    }
    while ( v5 );
  }
}

// File Line: 311
// RVA: 0x2EC180
void __fastcall DestructionExplosionTask::Begin(DestructionExplosionTask *this, ActionContext *context)
{
  ActionContext *v2; // r14
  DestructionExplosionTask *v3; // rbp
  UFG::RigidBody *v4; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  UFG::CollisionMeshData *v8; // rdx
  int v9; // ebx
  char *v10; // rax
  ITrack *v11; // rdx
  float v12; // xmm2_4
  float v13; // xmm1_4
  UFG::qVector3 pos; // [rsp+30h] [rbp-88h]
  UFG::qReflectHandleBase v15; // [rsp+40h] [rbp-78h]
  __int64 v16; // [rsp+68h] [rbp-50h]
  UFG::qMatrix44 mat; // [rsp+70h] [rbp-48h]

  v16 = -2i64;
  v2 = context;
  v3 = this;
  v4 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                           context->mSimObject.m_pPointer,
                           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                           0,
                           0i64);
  if ( v4 )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             v2->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             (UFG::SimComponent *)&v4->vfptr);
      UFG::qReflectHandleBase::qReflectHandleBase(&v15);
      v7 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v15.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
      v8 = v4->mCollisionMeshData;
      if ( v8 )
        UFG::qReflectHandleBase::operator=(&v15, (UFG::qReflectHandleBase *)&v8->mObjectProperties.mPrev);
      if ( v15.mData )
      {
        v9 = (int)v3->m_Track[1].vfptr;
        v10 = UFG::qReflectObject::GetName(v15.mData);
        if ( v9 == (unsigned int)UFG::qStringHashUpper32(v10, 0xFFFFFFFF) || LODWORD(v3->m_Track[1].vfptr) == -1 )
        {
          UFG::RigidBody::GetTransform(v4, &mat);
          v11 = v3->m_Track;
          v12 = mat.v3.z + *(float *)&v11[1].m_TrackClassNameUID;
          v13 = mat.v3.y + *((float *)&v11[1].mResourceOwner + 1);
          pos.x = mat.v3.x + *(float *)&v11[1].mResourceOwner;
          pos.y = v13;
          pos.z = v12;
          UFG::ExplosionManager::CreateExplosion(
            &pos,
            (UFG::qSymbol *)&v11[1].vfptr + 1,
            v4->m_pSimObject,
            (UFG::SimObject *)v4[1].mCollisionMeshBundle.mPrev[13].mPrev);
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
      v4 = (UFG::RigidBody *)v5;
    }
    while ( v5 );
  }
}

// File Line: 330
// RVA: 0x2EBA40
void __fastcall DestructionEnableFractureElementTask::Begin(DestructionEnableFractureElementTask *this, ActionContext *context)
{
  ActionContext *v2; // rsi
  DestructionEnableFractureElementTask *v3; // rbp
  UFG::RigidBody *v4; // rbx
  UFG::TransformNodeComponent *v5; // rdi
  ITrack *v6; // rax
  unsigned int v7; // edx

  v2 = context;
  v3 = this;
  v4 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                           context->mSimObject.m_pPointer,
                           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                           0,
                           0i64);
  if ( v4 )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             v2->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             (UFG::SimComponent *)&v4->vfptr);
      v6 = v3->m_Track;
      v7 = (unsigned int)v6[1].vfptr;
      if ( v7 != UFG::gNullQSymbolUC.mUID )
      {
        if ( BYTE4(v6[1].vfptr) )
          UFG::RigidBody::EnableFracturePartByGuid(v4, v7, 0);
        else
          UFG::RigidBody::DisableFracturePartByGuid(v4, v7);
      }
      v4 = (UFG::RigidBody *)v5;
    }
    while ( v5 );
  }
}

// File Line: 388
// RVA: 0x2EC4E0
void __fastcall DestructionSetDamageTask::Begin(DestructionSetDamageTask *this, ActionContext *context)
{
  ActionContext *v2; // r14
  DestructionSetDamageTask *v3; // rsi
  UFG::TransformNodeComponent *v4; // rdi
  UFG::TransformNodeComponent *v5; // rbp
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  __int64 v8; // rdx
  int v9; // ebx
  char *v10; // rax
  UFG::StateMachineComponent *v11; // rcx
  UFG::qReflectHandleBase v12; // [rsp+28h] [rbp-30h]

  v2 = context;
  v3 = this;
  v4 = UFG::SimObject::GetComponentOfType(
         context->mSimObject.m_pPointer,
         UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
         0,
         0i64);
  if ( v4 )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             v2->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             (UFG::SimComponent *)&v4->vfptr);
      UFG::qReflectHandleBase::qReflectHandleBase(&v12);
      v7 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v12.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
      v8 = *(_QWORD *)&v4->mWorldTransform.v2.x;
      if ( v8 )
        UFG::qReflectHandleBase::operator=(&v12, (UFG::qReflectHandleBase *)(v8 + 224));
      if ( v12.mData )
      {
        v9 = (int)v3->m_Track[1].vfptr;
        v10 = UFG::qReflectObject::GetName(v12.mData);
        if ( v9 == (unsigned int)UFG::qStringHashUpper32(v10, 0xFFFFFFFF) || LODWORD(v3->m_Track[1].vfptr) == -1 )
        {
          v11 = *(UFG::StateMachineComponent **)&v4[1].mChanged;
          if ( v11 )
            UFG::StateMachineComponent::SetDamage(v11, *((float *)&v3->m_Track[1].vfptr + 1));
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v12);
      v4 = v5;
    }
    while ( v5 );
  }
}

// File Line: 409
// RVA: 0x2EB8E0
void __fastcall DestructionDeleteConstraintTask::Begin(DestructionDeleteConstraintTask *this, ActionContext *context)
{
  ActionContext *v2; // r14
  DestructionDeleteConstraintTask *v3; // rsi
  UFG::RigidBody *v4; // rdi
  UFG::TransformNodeComponent *v5; // rbp
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  UFG::CollisionMeshData *v8; // rdx
  int v9; // ebx
  char *v10; // rax
  ITrack *v11; // rax
  UFG::Constraint *v12; // rax
  UFG::Constraint *v13; // rbx
  UFG::qReflectHandleBase v14; // [rsp+28h] [rbp-50h]
  hkBool result; // [rsp+88h] [rbp+10h]
  UFG::qSymbol name; // [rsp+90h] [rbp+18h]
  UFG::qSymbol *v17; // [rsp+98h] [rbp+20h]

  v2 = context;
  v3 = this;
  v4 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                           context->mSimObject.m_pPointer,
                           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                           0,
                           0i64);
  if ( v4 )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             v2->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             (UFG::SimComponent *)&v4->vfptr);
      UFG::qReflectHandleBase::qReflectHandleBase(&v14);
      v7 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v14.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
      v8 = v4->mCollisionMeshData;
      if ( v8 )
        UFG::qReflectHandleBase::operator=(&v14, (UFG::qReflectHandleBase *)&v8->mObjectProperties.mPrev);
      if ( v14.mData )
      {
        v9 = (int)v3->m_Track[1].vfptr;
        v10 = UFG::qReflectObject::GetName(v14.mData);
        if ( v9 == (unsigned int)UFG::qStringHashUpper32(v10, 0xFFFFFFFF) || LODWORD(v3->m_Track[1].vfptr) == -1 )
        {
          v11 = v3->m_Track;
          if ( LOBYTE(v11[1].mResourceOwner) )
          {
            UFG::RigidBody::DeleteAllConstraints(v4);
          }
          else if ( HIDWORD(v11[1].vfptr) != -1 )
          {
            v17 = &name;
            name.mUID = HIDWORD(v11[1].vfptr);
            v12 = UFG::RigidBody::GetConstraintByName(v4, (__int64)&name);
            v13 = v12;
            if ( v12 )
            {
              if ( hkpConstraintInstance::isEnabled(v12->mConstraintInstance, &result)->m_bool )
                hkpConstraintInstance::disable(v13->mConstraintInstance);
            }
          }
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v14);
      v4 = (UFG::RigidBody *)v5;
    }
    while ( v5 );
  }
}

// File Line: 440
// RVA: 0x2ED690
void __fastcall DestructionThrusterTask::Begin(DestructionThrusterTask *this, ActionContext *context)
{
  this->mContext = context;
  this->mDecayAmount = 0.0;
}

// File Line: 447
// RVA: 0x304040
char __fastcall DestructionThrusterTask::Update(DestructionThrusterTask *this, float timeDelta)
{
  DestructionThrusterTask *v2; // rdi
  UFG::RigidBody *v3; // rsi
  float v4; // xmm6_4
  UFG::TransformNodeComponent *v5; // r14
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  UFG::CollisionMeshData *v8; // rdx
  int v9; // ebx
  char *v10; // rax
  float v11; // xmm1_4
  float *v12; // rax
  float v13; // xmm12_4
  float v14; // xmm8_4
  float v15; // xmm10_4
  float *v16; // rax
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  UFG::qVector3 force; // [rsp+20h] [rbp-C8h]
  UFG::qVector3 point; // [rsp+2Ch] [rbp-BCh]
  UFG::qMatrix44 mat; // [rsp+40h] [rbp-A8h]
  unsigned __int64 v24; // [rsp+80h] [rbp-68h]
  UFG::qReflectObject *v25; // [rsp+90h] [rbp-58h]
  float v26; // [rsp+158h] [rbp+70h]
  float timeDeltaa; // [rsp+160h] [rbp+78h]

  *(_QWORD *)&mat.v2.z = -2i64;
  v2 = this;
  this->mDecayAmount = (float)(*((float *)&this->m_Track[1].mMasterRate.text.mOffset + 1) * timeDelta)
                     + this->mDecayAmount;
  v3 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                           this->mContext->mSimObject.m_pPointer,
                           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                           0,
                           0i64);
  if ( v3 )
  {
    v4 = *(float *)&FLOAT_1_0;
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             v2->mContext->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             (UFG::SimComponent *)&v3->vfptr);
      UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&mat.v3);
      v7 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v24 = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
      v8 = v3->mCollisionMeshData;
      if ( v8 )
        UFG::qReflectHandleBase::operator=(
          (UFG::qReflectHandleBase *)&mat.v3,
          (UFG::qReflectHandleBase *)&v8->mObjectProperties.mPrev);
      if ( v25 )
      {
        v9 = (int)v2->m_Track[1].vfptr;
        v10 = UFG::qReflectObject::GetName(v25);
        if ( v9 == (unsigned int)UFG::qStringHashUpper32(v10, 0xFFFFFFFF) || LODWORD(v2->m_Track[1].vfptr) == -1 )
        {
          v11 = v2->mDecayAmount;
          if ( v11 <= v4 )
          {
            v12 = (float *)v2->m_Track;
            v13 = v12[20] * (float)(v4 - v11);
            v14 = v12[19] * (float)(v4 - v11);
            v15 = v12[18] * (float)(v4 - v11);
            UFG::RigidBody::GetTransform(v3, &mat);
            v26 = (float)((float)(mat.v1.x * v14) + (float)(mat.v0.x * v15)) + (float)(mat.v2.x * v13);
            v16 = (float *)v2->m_Track;
            v17 = v16[15];
            v18 = v16[16];
            v19 = v16[17];
            point.x = (float)((float)(mat.v1.x * v18) + (float)(mat.v0.x * v17)) + (float)(mat.v2.x * v19);
            point.y = (float)((float)(mat.v1.y * v18) + (float)(mat.v0.y * v17)) + (float)(mat.v2.y * v19);
            point.z = (float)((float)(mat.v1.z * v18) + (float)(mat.v0.z * v17)) + (float)(mat.v2.z * v19);
            force.x = (float)((float)(mat.v1.x * v14) + (float)(mat.v0.x * v15)) + (float)(mat.v2.x * v13);
            force.y = (float)((float)(mat.v1.y * v14) + (float)(mat.v0.y * v15)) + (float)(mat.v2.y * v13);
            force.z = (float)((float)(mat.v1.z * v14) + (float)(mat.v0.z * v15)) + (float)(mat.v2.z * v13);
            UFG::RigidBody::ApplyForce(v3, timeDeltaa, &force, &point);
            v4 = *(float *)&FLOAT_1_0;
          }
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&mat.v3);
      v3 = (UFG::RigidBody *)v5;
    }
    while ( v5 );
  }
  return 1;
}

// File Line: 481
// RVA: 0x2EC310
void __fastcall DestructionHingeConstraintTask::Begin(DestructionHingeConstraintTask *this, ActionContext *context)
{
  ActionContext *v2; // r14
  DestructionHingeConstraintTask *v3; // rbp
  UFG::RigidBody *v4; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  UFG::CollisionMeshData *v8; // rdx
  int v9; // ebx
  char *v10; // rax
  hkpRigidBody *v11; // rcx
  ITrack *v12; // r8
  float limitMax; // xmm4_4
  float limitMin; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::Constraint *v19; // rbx
  UFG::qVector3 axis; // [rsp+48h] [rbp-50h]
  UFG::qVector3 pivot; // [rsp+54h] [rbp-44h]
  UFG::qReflectHandleBase v22; // [rsp+60h] [rbp-38h]

  v2 = context;
  v3 = this;
  v4 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                           context->mSimObject.m_pPointer,
                           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                           0,
                           0i64);
  if ( v4 )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             v2->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             (UFG::SimComponent *)&v4->vfptr);
      UFG::qReflectHandleBase::qReflectHandleBase(&v22);
      v7 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v22.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
      v8 = v4->mCollisionMeshData;
      if ( v8 )
        UFG::qReflectHandleBase::operator=(&v22, (UFG::qReflectHandleBase *)&v8->mObjectProperties.mPrev);
      if ( v22.mData )
      {
        v9 = (int)v3->m_Track[1].vfptr;
        v10 = UFG::qReflectObject::GetName(v22.mData);
        if ( v9 == (unsigned int)UFG::qStringHashUpper32(v10, 0xFFFFFFFF) || LODWORD(v3->m_Track[1].vfptr) == -1 )
        {
          v11 = v4->mBody;
          if ( v11 )
          {
            v12 = v3->m_Track;
            limitMax = *((float *)&v12[1].mMasterRate.expression.mOffset + 1);
            limitMin = *(float *)&v12[1].mMasterRate.expression.mOffset;
            v15 = *(float *)&v12[1].mMasterRate.text.mOffset;
            v16 = *((float *)&v12[1].mMasterRate.text.mOffset + 1);
            axis.x = *(float *)&v12[1].mBreakPoint;
            axis.y = v15;
            axis.z = v16;
            v17 = *((float *)&v12[1].mResourceOwner + 1);
            v18 = *(float *)&v12[1].m_TrackClassNameUID;
            pivot.x = *(float *)&v12[1].mResourceOwner;
            pivot.y = v17;
            pivot.z = v18;
            v19 = UFG::Constraint::CreateHingeConstraint(
                    v11,
                    0i64,
                    (UFG::qSymbol *)&v12[1].vfptr + 1,
                    &pivot,
                    &axis,
                    limitMin,
                    limitMax);
            UFG::RigidBody::AddConstraint(v4, v19);
            UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v19->mConstraintInstance);
          }
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v22);
      v4 = (UFG::RigidBody *)v5;
    }
    while ( v5 );
  }
}

// File Line: 505
// RVA: 0x2ED4C0
void __fastcall DestructionStiffSpringConstraintTask::Begin(DestructionStiffSpringConstraintTask *this, ActionContext *context)
{
  ActionContext *v2; // r14
  DestructionStiffSpringConstraintTask *v3; // rbp
  UFG::RigidBody *v4; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  UFG::CollisionMeshData *v8; // rdx
  int v9; // ebx
  char *v10; // rax
  hkpRigidBody *v11; // rcx
  ITrack *v12; // r8
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  UFG::Constraint *v17; // rbx
  UFG::qVector3 pivot2; // [rsp+38h] [rbp-60h]
  UFG::qVector3 pivot1; // [rsp+44h] [rbp-54h]
  UFG::qReflectHandleBase v20; // [rsp+50h] [rbp-48h]

  v2 = context;
  v3 = this;
  v4 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                           context->mSimObject.m_pPointer,
                           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                           0,
                           0i64);
  if ( v4 )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             v2->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             (UFG::SimComponent *)&v4->vfptr);
      UFG::qReflectHandleBase::qReflectHandleBase(&v20);
      v7 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v20.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
      v8 = v4->mCollisionMeshData;
      if ( v8 )
        UFG::qReflectHandleBase::operator=(&v20, (UFG::qReflectHandleBase *)&v8->mObjectProperties.mPrev);
      if ( v20.mData )
      {
        v9 = (int)v3->m_Track[1].vfptr;
        v10 = UFG::qReflectObject::GetName(v20.mData);
        if ( v9 == (unsigned int)UFG::qStringHashUpper32(v10, 0xFFFFFFFF) || LODWORD(v3->m_Track[1].vfptr) == -1 )
        {
          v11 = v4->mBody;
          if ( v11 )
          {
            v12 = v3->m_Track;
            v13 = *(float *)&v12[1].mMasterRate.text.mOffset;
            v14 = *((float *)&v12[1].mMasterRate.text.mOffset + 1);
            pivot2.x = *(float *)&v12[1].mBreakPoint;
            pivot2.y = v13;
            pivot2.z = v14;
            v15 = *((float *)&v12[1].mResourceOwner + 1);
            v16 = *(float *)&v12[1].m_TrackClassNameUID;
            pivot1.x = *(float *)&v12[1].mResourceOwner;
            pivot1.y = v15;
            pivot1.z = v16;
            v17 = UFG::Constraint::CreateStiffSpringContraint(
                    v11,
                    0i64,
                    (UFG::qSymbol *)&v12[1].vfptr + 1,
                    &pivot1,
                    &pivot2);
            UFG::RigidBody::AddConstraint(v4, v17);
            UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v17->mConstraintInstance);
          }
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v20);
      v4 = (UFG::RigidBody *)v5;
    }
    while ( v5 );
  }
}

// File Line: 529
// RVA: 0x2EB770
void __fastcall DestructionBallAndSocketConstraintTask::Begin(DestructionBallAndSocketConstraintTask *this, ActionContext *context)
{
  ActionContext *v2; // r14
  DestructionBallAndSocketConstraintTask *v3; // rbp
  UFG::RigidBody *v4; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  UFG::CollisionMeshData *v8; // rdx
  int v9; // ebx
  char *v10; // rax
  hkpRigidBody *v11; // rcx
  ITrack *v12; // r8
  float v13; // xmm1_4
  float v14; // xmm2_4
  UFG::Constraint *v15; // rbx
  UFG::qVector3 pivot; // [rsp+28h] [rbp-40h]
  UFG::qReflectHandleBase v17; // [rsp+38h] [rbp-30h]

  v2 = context;
  v3 = this;
  v4 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                           context->mSimObject.m_pPointer,
                           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                           0,
                           0i64);
  if ( v4 )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             v2->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             (UFG::SimComponent *)&v4->vfptr);
      UFG::qReflectHandleBase::qReflectHandleBase(&v17);
      v7 = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v17.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
      v8 = v4->mCollisionMeshData;
      if ( v8 )
        UFG::qReflectHandleBase::operator=(&v17, (UFG::qReflectHandleBase *)&v8->mObjectProperties.mPrev);
      if ( v17.mData )
      {
        v9 = (int)v3->m_Track[1].vfptr;
        v10 = UFG::qReflectObject::GetName(v17.mData);
        if ( v9 == (unsigned int)UFG::qStringHashUpper32(v10, 0xFFFFFFFF) || LODWORD(v3->m_Track[1].vfptr) == -1 )
        {
          v11 = v4->mBody;
          if ( v11 )
          {
            v12 = v3->m_Track;
            v13 = *((float *)&v12[1].mResourceOwner + 1);
            v14 = *(float *)&v12[1].m_TrackClassNameUID;
            pivot.x = *(float *)&v12[1].mResourceOwner;
            pivot.y = v13;
            pivot.z = v14;
            v15 = UFG::Constraint::CreateBallAndSocketConstraint(v11, 0i64, (UFG::qSymbol *)&v12[1].vfptr + 1, &pivot);
            UFG::RigidBody::AddConstraint(v4, v15);
            UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v15->mConstraintInstance);
          }
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v17);
      v4 = (UFG::RigidBody *)v5;
    }
    while ( v5 );
  }
}

