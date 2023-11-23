// File Line: 43
// RVA: 0x2EC610
void __fastcall DestructionSetDefinitionTask::Begin(DestructionSetDefinitionTask *this, ActionContext *context)
{
  UFG::RigidBodyComponent *ComponentOfType; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  int vfptr; // ebx
  char *Name; // rax
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rbx
  ITrack *m_Track; // rcx
  UFG::qReflectHandleBase v14; // [rsp+38h] [rbp-50h] BYREF

  ComponentOfType = (UFG::RigidBodyComponent *)UFG::SimObject::GetComponentOfType(
                                                 context->mSimObject.m_pPointer,
                                                 UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                                 0,
                                                 0i64);
  if ( ComponentOfType )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             context->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             ComponentOfType);
      UFG::qReflectHandleBase::qReflectHandleBase(&v14);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v14.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      mCollisionMeshData = ComponentOfType->mCollisionMeshData;
      if ( mCollisionMeshData )
        UFG::qReflectHandleBase::operator=(&v14, &mCollisionMeshData->mObjectProperties);
      if ( v14.mData )
      {
        vfptr = (int)this->m_Track[1].vfptr;
        Name = UFG::qReflectObject::GetName(v14.mData);
        if ( vfptr == (unsigned int)UFG::qStringHashUpper32(Name, -1) || LODWORD(this->m_Track[1].vfptr) == -1 )
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
          m_Track = this->m_Track;
          HIDWORD(v12[12].mNext) = HIDWORD(m_Track[1].vfptr);
          LODWORD(v12[13].mNext) = m_Track[1].mResourceOwner;
          HIDWORD(v12[13].mNext) = HIDWORD(m_Track[1].mResourceOwner);
          LODWORD(v12[14].mNext) = m_Track[1].m_TrackClassNameUID;
          HIDWORD(v12[14].mNext) = *(_DWORD *)&m_Track[1].mBreakPoint;
          UFG::RigidBodyComponent::CreateRuntimeStateMachineDefinition(
            ComponentOfType,
            (UFG::StateMachineDefinition *)v12);
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v14);
      ComponentOfType = (UFG::RigidBodyComponent *)v5;
    }
    while ( v5 );
  }
}

// File Line: 69
// RVA: 0x2EBBF0
void __fastcall DestructionEventTask::Begin(DestructionEventTask *this, ActionContext *context)
{
  UFG::TransformNodeComponent *ComponentOfType; // rsi
  UFG::TransformNodeComponent *v5; // r14
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *TypeName; // rax
  __int64 v8; // rdx
  int vfptr; // ebx
  char *Name; // rax
  ITrack *m_Track; // rax
  unsigned int mUID; // ebx
  UFG::DynamicCoverComponent *mPrev; // rcx
  UFG::SimObject *m_pSimObject; // rax
  UFG::SimObjectGame *v15; // rcx
  UFG::PhysicsRenderHelper *v16; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  ITrack *v19; // rax
  UFG::SimObjectGame *v20; // rcx
  UFG::PhysicsRenderHelper *v21; // rax
  __int16 v22; // dx
  float v23; // xmm0_4
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 v25; // dx
  UFG::SimComponent *m_pComponent; // rax
  ITrack *v27; // rax
  unsigned int v28; // eax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v29; // rax
  int mTypeUID_high; // r9d
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v31; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mNext; // rax
  UFG::SimObjectGame *v33; // rcx
  __int16 v34; // dx
  UFG::RigidBodyComponent *v35; // rax
  UFG::qReflectHandleBase v36; // [rsp+30h] [rbp-A8h] BYREF
  __int64 v37; // [rsp+58h] [rbp-80h]
  UFG::qMatrix44 mat; // [rsp+60h] [rbp-78h] BYREF
  UFG::qWiseSymbol result; // [rsp+128h] [rbp+50h] BYREF
  UFG::OneShotHandle pHandle; // [rsp+130h] [rbp+58h] BYREF

  v37 = -2i64;
  ComponentOfType = UFG::SimObject::GetComponentOfType(
                      context->mSimObject.m_pPointer,
                      UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                      0,
                      0i64);
  if ( ComponentOfType )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             context->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             ComponentOfType);
      UFG::qReflectHandleBase::qReflectHandleBase(&v36);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v36.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      v8 = *(_QWORD *)&ComponentOfType->mWorldTransform.v2.x;
      if ( v8 )
        UFG::qReflectHandleBase::operator=(&v36, (UFG::qReflectHandleBase *)(v8 + 224));
      if ( v36.mData )
      {
        vfptr = (int)this->m_Track[1].vfptr;
        Name = UFG::qReflectObject::GetName(v36.mData);
        if ( vfptr == (unsigned int)UFG::qStringHashUpper32(Name, -1) || LODWORD(this->m_Track[1].vfptr) == -1 )
        {
          if ( BYTE1(this->m_Track[1].mResourceOwner) )
            UFG::RigidBody::SetCollisionLayer((UFG::RigidBody *)ComponentOfType, 0x15u, -1, -1, -1);
          m_Track = this->m_Track;
          if ( HIDWORD(m_Track[1].vfptr) != -1 )
          {
            mUID = UFG::qSymbol::qSymbol(&result, HIDWORD(m_Track[1].vfptr))->mUID;
            _((AMD_HD3D *)result.mUID);
            UFG::RigidBody::GetTransform((UFG::RigidBody *)ComponentOfType, &mat);
            pHandle.m_pOneShot = 0i64;
            UFG::OneShotPool::GetOneShotHandle(&pHandle, &mat);
            if ( UFG::OneShotHandle::IsValid(&pHandle) )
              UFG::OneShot::Play(pHandle.m_pOneShot, mUID);
            UFG::OneShotHandle::Release(&pHandle);
          }
          if ( LOBYTE(this->m_Track[1].mResourceOwner) )
          {
            hkpPhysicsSystem::hkpPhysicsSystem((hkpPhysicsSystem *)&mat.v1.z);
            UFG::Destruction::ForceFracture(
              UFG::Destruction::mInstance,
              (UFG::RigidBody *)ComponentOfType,
              (hkpPhysicsSystem *)&mat.v1.z,
              -1);
            hkpPhysicsSystem::~hkpPhysicsSystem((hkpPhysicsSystem *)&mat.v1.z);
          }
          if ( BYTE4(this->m_Track[1].mResourceOwner) )
          {
            mPrev = (UFG::DynamicCoverComponent *)ComponentOfType[1].mPrev;
            if ( mPrev )
              UFG::DynamicCoverComponent::DisableCoverCorners(mPrev);
          }
          if ( BYTE5(this->m_Track[1].mResourceOwner) )
          {
            m_pSimObject = ComponentOfType[1].m_pSimObject;
            if ( m_pSimObject )
              LODWORD(m_pSimObject[1].mNode.mChild[1]) |= 8u;
          }
          if ( *(_DWORD *)&this->m_Track[1].mBreakPoint != -1 )
          {
            v15 = (UFG::SimObjectGame *)ComponentOfType->m_pSimObject;
            if ( v15 )
            {
              m_Flags = v15->m_Flags;
              if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
                ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v15, UFG::PhysicsRenderHelper::_TypeUID);
              else
                ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v15, UFG::PhysicsRenderHelper::_TypeUID);
              v16 = (UFG::PhysicsRenderHelper *)ComponentOfTypeHK;
            }
            else
            {
              v16 = 0i64;
            }
            UFG::PhysicsRenderHelper::SwapRenderModel(v16, *(_DWORD *)&this->m_Track[1].mBreakPoint);
          }
          if ( BYTE6(this->m_Track[1].mResourceOwner) )
            UFG::RigidBody::SetMotionType((UFG::RigidBody *)ComponentOfType, 0x80u);
          v19 = this->m_Track;
          if ( HIBYTE(v19[1].mResourceOwner) )
            UFG::RigidBody::SetCollisionLayer((UFG::RigidBody *)ComponentOfType, v19[1].m_TrackClassNameUID, -1, -1, -1);
          if ( BYTE4(this->m_Track[1].mMasterRate.text.mOffset) )
          {
            v20 = (UFG::SimObjectGame *)ComponentOfType->m_pSimObject;
            if ( v20 )
            {
              v22 = v20->m_Flags;
              if ( (v22 & 0x4000) != 0 || v22 < 0 || (v22 & 0x2000) != 0 || (v22 & 0x1000) != 0 )
                v21 = (UFG::PhysicsRenderHelper *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v20,
                                                    UFG::PhysicsRenderHelper::_TypeUID);
              else
                v21 = (UFG::PhysicsRenderHelper *)UFG::SimObject::GetComponentOfType(
                                                    v20,
                                                    UFG::PhysicsRenderHelper::_TypeUID);
            }
            else
            {
              v21 = 0i64;
            }
            UFG::PhysicsRenderHelper::DisableSelfIllumination(v21);
          }
          v23 = *(float *)&this->m_Track[1].mMasterRate.expression.mOffset;
          if ( v23 >= 0.0 )
            ComponentOfType[1].mWorldTransform.v3.z = v23;
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v36);
      ComponentOfType = v5;
    }
    while ( v5 );
  }
  if ( BYTE2(this->m_Track[1].mResourceOwner) )
  {
    m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( m_pPointer )
    {
      v25 = m_pPointer->m_Flags;
      if ( (v25 & 0x4000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[14].m_pComponent;
      }
      else if ( v25 >= 0 )
      {
        if ( (v25 & 0x2000) != 0 )
          m_pComponent = m_pPointer->m_Components.p[9].m_pComponent;
        else
          m_pComponent = (v25 & 0x1000) != 0
                       ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pPointer, UFG::CompositeDrawableComponent::_TypeUID)
                       : UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CompositeDrawableComponent::_TypeUID);
      }
      else
      {
        m_pComponent = m_pPointer->m_Components.p[14].m_pComponent;
      }
      if ( m_pComponent )
        Render::IDecalScenery::RemoveAttachedDecals((Render::IDecalScenery *)&m_pComponent[1], 0xFFFFFFFF);
    }
  }
  v27 = this->m_Track;
  if ( LODWORD(v27[1].mMasterRate.text.mOffset) != -1 )
  {
    v28 = UFG::qSymbol::qSymbol(&result, v27[1].mMasterRate.text.mOffset)->mUID;
    v36.mPrev = &v36;
    v36.mNext = &v36;
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
    mTypeUID_high = HIDWORD(v36.mTypeUID);
    v31 = v36.mPrev;
    mNext = v36.mNext;
    v36.mPrev->mNext = v36.mNext;
    mNext->mPrev = v31;
    v36.mPrev = &v36;
    v36.mNext = &v36;
    UFG::RenderWorld::VisualTreatmentPostEffect_StartVisualTreatment(mTypeUID_high, 0, 0);
  }
  if ( BYTE3(this->m_Track[1].mResourceOwner) )
  {
    v33 = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
    if ( v33 )
    {
      v34 = v33->m_Flags;
      if ( (v34 & 0x4000) != 0 || v34 < 0 || (v34 & 0x2000) != 0 || (v34 & 0x1000) != 0 )
        v35 = (UFG::RigidBodyComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                           v33,
                                           UFG::RigidBodyComponent::_TypeUID);
      else
        v35 = (UFG::RigidBodyComponent *)UFG::SimObject::GetComponentOfType(v33, UFG::RigidBodyComponent::_TypeUID);
      if ( v35 )
        UFG::RigidBodyComponent::Delete(v35);
    }
  }
}

// File Line: 182
// RVA: 0x2EBAE0
void __fastcall DestructionEnableRiggedGeoTask::Begin(DestructionEnableRiggedGeoTask *this, ActionContext *context)
{
  UFG::SimObjectGame *m_pPointer; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  unsigned int mUID; // esi
  ModelType *mNext; // rbp
  UFG::qBaseNodeRB *Skeleton; // rax
  unsigned int BoneID; // eax
  UFG::qWiseSymbol result; // [rsp+38h] [rbp+10h] BYREF

  m_pPointer = (UFG::SimObjectGame *)context->mSimObject.m_pPointer;
  if ( m_pPointer )
  {
    m_Flags = m_pPointer->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = m_pPointer->m_Components.p[14].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = m_pPointer->m_Components.p[9].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                m_pPointer,
                                UFG::CompositeDrawableComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pPointer, UFG::CompositeDrawableComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = m_pPointer->m_Components.p[14].m_pComponent;
    }
    if ( m_pComponent )
    {
      UFG::qSymbol::qSymbol(&result, (unsigned int)this->m_Track[1].vfptr);
      mUID = result.mUID;
      mNext = (ModelType *)m_pComponent[22].m_SafePointerList.mNode.mNext;
      ModelType::SetRigidModelVisibilityOnBone(mNext, result.mUID, BYTE4(this->m_Track[1].vfptr) != 0);
      if ( BYTE5(this->m_Track[1].vfptr) )
      {
        Skeleton = ModelType::GetSkeleton(mNext);
        BoneID = Skeleton::GetBoneID((Skeleton *)Skeleton, mUID);
        Render::IDecalScenery::RemoveAttachedDecals((Render::IDecalScenery *)&m_pComponent[1], BoneID);
      }
    }
  }
}

// File Line: 206
// RVA: 0x2EC930
void __fastcall DestructionSpawnPropertySetTask::Begin(DestructionSpawnPropertySetTask *this, ActionContext *context)
{
  UFG::RigidBody *ComponentOfType; // rdi
  bool i; // zf
  UFG::TransformNodeComponent *v6; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v7; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  int vfptr; // ebx
  char *Name; // rax
  float *m_Track; // rax
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
  UFG::qPropertySet *PropertySet; // rbx
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
  __m128 v49; // [rsp+30h] [rbp-A8h] BYREF
  __m128 v50; // [rsp+40h] [rbp-98h]
  UFG::qSymbol result; // [rsp+50h] [rbp-88h] BYREF
  _BYTE v52[48]; // [rsp+58h] [rbp-80h] BYREF
  UFG::qVector4 mat_40; // [rsp+88h] [rbp-50h]
  UFG::qVector4 mat_56; // [rsp+98h] [rbp-40h]
  __m128 v55; // [rsp+A8h] [rbp-30h]
  __m128 v56; // [rsp+B8h] [rbp-20h]
  __m128 v57; // [rsp+C8h] [rbp-10h]
  UFG::qMatrix44 dest; // [rsp+D8h] [rbp+0h] BYREF
  UFG::qMatrix44 v59; // [rsp+118h] [rbp+40h] BYREF
  UFG::qMatrix44 v60; // [rsp+158h] [rbp+80h] BYREF
  UFG::qReflectHandleBase v61; // [rsp+198h] [rbp+C0h] BYREF
  __m128 v62; // [rsp+1C8h] [rbp+F0h]
  __int64 v63; // [rsp+1D8h] [rbp+100h]
  __m128 v64; // [rsp+1E0h] [rbp+108h]
  __m128 v65; // [rsp+1F8h] [rbp+120h]
  __m128 v66; // [rsp+208h] [rbp+130h]
  __m128 v67; // [rsp+228h] [rbp+150h]
  float mTimeBegin; // [rsp+310h] [rbp+238h]
  float mTimeEnd; // [rsp+318h] [rbp+240h]
  float vars0; // [rsp+320h] [rbp+248h]

  v63 = -2i64;
  ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                        context->mSimObject.m_pPointer,
                                        UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                        0,
                                        0i64);
  for ( i = ComponentOfType == 0i64; !i; i = v6 == 0i64 )
  {
    v6 = UFG::SimObject::GetComponentOfType(
           context->mSimObject.m_pPointer,
           UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
           0,
           ComponentOfType);
    UFG::qReflectHandleBase::qReflectHandleBase(&v61);
    TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v7);
    v61.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
    mCollisionMeshData = ComponentOfType->mCollisionMeshData;
    if ( mCollisionMeshData )
      UFG::qReflectHandleBase::operator=(&v61, &mCollisionMeshData->mObjectProperties);
    if ( v61.mData )
    {
      vfptr = (int)this->m_Track[1].vfptr;
      Name = UFG::qReflectObject::GetName(v61.mData);
      if ( vfptr == (unsigned int)UFG::qStringHashUpper32(Name, -1) || LODWORD(this->m_Track[1].vfptr) == -1 )
      {
        UFG::RigidBody::GetTransform(ComponentOfType, (UFG::qMatrix44 *)&v52[8]);
        *(UFG::qVector4 *)&v52[32] = UFG::qMatrix44::msIdentity.v0;
        mat_40 = UFG::qMatrix44::msIdentity.v1;
        mat_56 = UFG::qMatrix44::msIdentity.v2;
        v55.m128_i32[3] = LODWORD(UFG::qMatrix44::msIdentity.v3.w);
        m_Track = (float *)this->m_Track;
        v13 = (float)(m_Track[20] * 3.1415927) * 0.0055555557;
        v14 = (float)(m_Track[21] * 3.1415927) * 0.0055555557;
        UFG::qRotationMatrixX(&dest, (float)(m_Track[19] * 3.1415927) * 0.0055555557);
        UFG::qRotationMatrixY(&v60, v13);
        UFG::qRotationMatrixZ(&v59, v14);
        v15 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), (__m128)v60.v3),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0), (__m128)v60.v0), _xmm),
                    _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85), (__m128)v60.v1)),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170), (__m128)v60.v2)));
        v16 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255), (__m128)v60.v3),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0), (__m128)v60.v0),
                      (__m128)0i64),
                    _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85), (__m128)v60.v1)),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170), (__m128)v60.v2)));
        v17 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), (__m128)v60.v3),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0), (__m128)v60.v0),
                      (__m128)0i64),
                    _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85), (__m128)v60.v1)),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170), (__m128)v60.v2)));
        v49 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), (__m128)v60.v2),
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0), (__m128)v60.v0),
                      (__m128)0i64),
                    _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85), (__m128)v60.v1))),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), (__m128)v60.v3));
        v50 = _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), (__m128)v59.v0);
        v64 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(v50, _xmm), _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), (__m128)v59.v1)),
                  _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), (__m128)v59.v2)),
                _mm_mul_ps(_mm_shuffle_ps(v15, v15, 255), (__m128)v59.v3));
        v56 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v16, v16, 85), (__m128)v59.v1),
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v16, v16, 0), (__m128)v59.v0), (__m128)0i64)),
                  _mm_mul_ps(_mm_shuffle_ps(v16, v16, 170), (__m128)v59.v2)),
                _mm_mul_ps(_mm_shuffle_ps(v16, v16, 255), (__m128)v59.v3));
        v57 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v17, v17, 0), (__m128)v59.v0), (__m128)0i64),
                    _mm_mul_ps(_mm_shuffle_ps(v17, v17, 85), (__m128)v59.v1)),
                  _mm_mul_ps(_mm_shuffle_ps(v17, v17, 170), (__m128)v59.v2)),
                _mm_mul_ps(_mm_shuffle_ps(v17, v17, 255), (__m128)v59.v3));
        v55 = _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v49, v49, 255), (__m128)v59.v3),
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), (__m128)v59.v0), (__m128)0i64),
                    _mm_mul_ps(_mm_shuffle_ps(v49, v49, 85), (__m128)v59.v1)),
                  _mm_mul_ps(_mm_shuffle_ps(v49, v49, 170), (__m128)v59.v2)));
        v18 = this->m_Track;
        v55.m128_u64[0] = (unsigned __int64)v18[1].mResourceOwner;
        v55.m128_i32[2] = v18[1].m_TrackClassNameUID;
        v19 = (float)(*((float *)&v18[1].mMasterRate.expression.mOffset + 1) * 3.1415927) * 0.0055555557;
        v20 = (float)(v18[1].mMasterRate.value * 3.1415927) * 0.0055555557;
        UFG::qRotationMatrixX(
          &dest,
          (float)(*(float *)&v18[1].mMasterRate.expression.mOffset * 3.1415927) * 0.0055555557);
        UFG::qRotationMatrixY(&v60, v19);
        UFG::qRotationMatrixZ(&v59, v20);
        v49 = _mm_mul_ps((__m128)v60.v1, _mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 85));
        v21 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      (__m128)0i64,
                      _mm_mul_ps((__m128)v60.v0, _mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 0))),
                    _mm_mul_ps((__m128)v60.v1, _mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 85))),
                  _mm_mul_ps((__m128)v60.v2, _mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 170))),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v2, (__m128)dest.v2, 255), (__m128)v60.v3));
        v22 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      (__m128)0i64,
                      _mm_mul_ps((__m128)v60.v0, _mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 0))),
                    v49),
                  _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 170), (__m128)v60.v2)),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v3, (__m128)dest.v3, 255), (__m128)v60.v3));
        v23 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      (__m128)0i64,
                      _mm_mul_ps((__m128)v60.v0, _mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 0))),
                    _mm_mul_ps((__m128)v60.v1, _mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 85))),
                  _mm_mul_ps((__m128)v60.v2, _mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 170))),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v0, (__m128)dest.v0, 255), (__m128)v60.v3));
        v24 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      (__m128)0i64,
                      _mm_mul_ps((__m128)v60.v0, _mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 0))),
                    _mm_mul_ps((__m128)v60.v1, _mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 85))),
                  _mm_mul_ps((__m128)v60.v2, _mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 170))),
                _mm_mul_ps(_mm_shuffle_ps((__m128)dest.v1, (__m128)dest.v1, 255), (__m128)v60.v3));
        v50 = _mm_mul_ps(_mm_shuffle_ps(v23, v23, 0), (__m128)v59.v0);
        v25 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps((__m128)v59.v2, _mm_shuffle_ps(v21, v21, 170)),
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 0), (__m128)v59.v0), (__m128)0i64),
                    _mm_mul_ps((__m128)v59.v1, _mm_shuffle_ps(v21, v21, 85)))),
                _mm_mul_ps((__m128)v59.v3, _mm_shuffle_ps(v21, v21, 255)));
        v65 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(v50, _xmm), _mm_mul_ps((__m128)v59.v1, _mm_shuffle_ps(v23, v23, 85))),
                  _mm_mul_ps((__m128)v59.v2, _mm_shuffle_ps(v23, v23, 170))),
                _mm_mul_ps((__m128)v59.v3, _mm_shuffle_ps(v23, v23, 255)));
        v66 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), (__m128)v59.v0), (__m128)0i64),
                    _mm_mul_ps((__m128)v59.v1, _mm_shuffle_ps(v24, v24, 85))),
                  _mm_mul_ps((__m128)v59.v2, _mm_shuffle_ps(v24, v24, 170))),
                _mm_mul_ps((__m128)v59.v3, _mm_shuffle_ps(v24, v24, 255)));
        v67 = _mm_add_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), (__m128)v59.v0), (__m128)0i64),
                    _mm_mul_ps((__m128)v59.v1, _mm_shuffle_ps(v22, v22, 85))),
                  _mm_mul_ps((__m128)v59.v2, _mm_shuffle_ps(v22, v22, 170))),
                _mm_mul_ps((__m128)v59.v3, _mm_shuffle_ps(v22, v22, 255)));
        v26 = this->m_Track;
        v27 = *(&v26[1].mMasterRate.value + 1);
        v28 = _mm_shuffle_ps(v25, v25, 170);
        v28.m128_f32[0] = v28.m128_f32[0] * v27;
        v62 = v28;
        v29 = _mm_shuffle_ps(v25, v25, 85);
        v29.m128_f32[0] = v29.m128_f32[0] * v27;
        v49 = v29;
        v25.m128_f32[0] = v25.m128_f32[0] * v27;
        v50 = v25;
        mTimeBegin = v26[1].mTimeBegin;
        mTimeEnd = v26[1].mTimeEnd;
        vars0 = *(float *)&v26[2].vfptr;
        PropertySet = UFG::PropertySetManager::FindPropertySet((UFG::qSymbol *)&v26[1].vfptr + 1);
        if ( PropertySet )
        {
          UFG::Simulation::GenerateUniqueName(&UFG::gSim, &result, (UFG::qSymbol *)&this->m_Track[1].vfptr + 1);
          v31 = v56;
          v32 = v57;
          v33 = _mm_mul_ps(*(__m128 *)&v52[8], _mm_shuffle_ps(v56, v56, 0));
          v34 = _mm_mul_ps(*(__m128 *)&v52[8], _mm_shuffle_ps(v57, v57, 0));
          v57 = _mm_mul_ps(*(__m128 *)&v52[8], _mm_shuffle_ps(v55, v55, 0));
          v35 = _mm_mul_ps(*(__m128 *)&v52[24], _mm_shuffle_ps(v56, v56, 85));
          v36 = _mm_mul_ps(*(__m128 *)v52, _mm_shuffle_ps(v56, v56, 170));
          v56 = _mm_mul_ps(*(__m128 *)v52, _mm_shuffle_ps(v55, v55, 170));
          v37 = _mm_add_ps(
                  _mm_add_ps(_mm_add_ps(_mm_add_ps((__m128)0i64, v33), v35), v36),
                  _mm_mul_ps(*(__m128 *)&v52[16], _mm_shuffle_ps(v31, v31, 255)));
          v38 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps((__m128)0i64, v34),
                      _mm_mul_ps(*(__m128 *)&v52[24], _mm_shuffle_ps(v32, v32, 85))),
                    _mm_mul_ps(*(__m128 *)v52, _mm_shuffle_ps(v32, v32, 170))),
                  _mm_mul_ps(*(__m128 *)&v52[16], _mm_shuffle_ps(v32, v32, 255)));
          v39 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_add_ps((__m128)0i64, v57),
                      _mm_mul_ps(*(__m128 *)&v52[24], _mm_shuffle_ps(v55, v55, 85))),
                    v56),
                  _mm_mul_ps(*(__m128 *)&v52[16], _mm_shuffle_ps(v55, v55, 255)));
          *(__m128 *)&v52[32] = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(
                                        (__m128)0i64,
                                        _mm_mul_ps(*(__m128 *)&v52[8], _mm_shuffle_ps(v64, v64, 0))),
                                      _mm_mul_ps(*(__m128 *)&v52[24], _mm_shuffle_ps(v64, v64, 85))),
                                    _mm_mul_ps(*(__m128 *)v52, _mm_shuffle_ps(v64, v64, 170))),
                                  _mm_mul_ps(*(__m128 *)&v52[16], _mm_shuffle_ps(v64, v64, 255)));
          mat_40 = (UFG::qVector4)v37;
          mat_56 = (UFG::qVector4)v38;
          v55 = v39;
          v40 = UFG::SpawnInfoInterface::SpawnObject(
                  &result,
                  PropertySet,
                  (UFG::qMatrix44 *)&v52[32],
                  Count,
                  0i64,
                  0i64);
          v41 = v49.m128_f32[0];
          v42 = v62.m128_f32[0];
          v43 = mTimeEnd;
          v44 = mTimeBegin;
          v45 = vars0;
          if ( fsqrt(
                 (float)((float)(v50.m128_f32[0] * v50.m128_f32[0]) + (float)(v49.m128_f32[0] * v49.m128_f32[0]))
               + (float)(v62.m128_f32[0] * v62.m128_f32[0])) > 0.0
            || (v46 = (__m128)LODWORD(mTimeEnd),
                v46.m128_f32[0] = (float)((float)(mTimeEnd * mTimeEnd) + (float)(mTimeBegin * mTimeBegin))
                                + (float)(vars0 * vars0),
                _mm_sqrt_ps(v46).m128_f32[0] != 0.0) )
          {
            if ( v40 )
            {
              v47 = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(v40, UFG::RigidBodyComponent::_TypeUID);
              v48 = v47;
              if ( v47 )
              {
                v49.m128_f32[0] = (float)((float)(*(float *)&v52[8] * v50.m128_f32[0])
                                        + (float)(v49.m128_f32[0] * *(float *)&v52[24]))
                                + (float)(v42 * *(float *)v52);
                v49.m128_f32[1] = (float)((float)(*(float *)&v52[12] * v50.m128_f32[0])
                                        + (float)(v41 * *(float *)&v52[28]))
                                + (float)(v42 * *(float *)&v52[4]);
                v49.m128_f32[2] = (float)((float)(*(float *)&v52[16] * v50.m128_f32[0])
                                        + (float)(v41 * *(float *)&v52[32]))
                                + (float)(v42 * *(float *)&v52[8]);
                UFG::RigidBody::ApplyLinearImpulse(v47, (UFG::qVector3 *)&v49);
                v49.m128_f32[0] = (float)((float)(v44 * *(float *)&v52[8]) + (float)(v43 * *(float *)&v52[24]))
                                + (float)(v45 * *(float *)v52);
                v49.m128_f32[1] = (float)((float)(v44 * *(float *)&v52[12]) + (float)(v43 * *(float *)&v52[28]))
                                + (float)(v45 * *(float *)&v52[4]);
                v49.m128_f32[2] = (float)((float)(v44 * *(float *)&v52[16]) + (float)(v43 * *(float *)&v52[32]))
                                + (float)(v45 * *(float *)&v52[8]);
                UFG::RigidBody::ApplyAngularImpulse(v48, (UFG::qVector3 *)&v49);
              }
            }
          }
        }
        UFG::qReflectHandleBase::~qReflectHandleBase(&v61);
        return;
      }
    }
    UFG::qReflectHandleBase::~qReflectHandleBase(&v61);
    ComponentOfType = (UFG::RigidBody *)v6;
  }
}

// File Line: 287
// RVA: 0x2EC7B0
void __fastcall DestructionSpawnPhantomVolumeTask::Begin(
        DestructionSpawnPhantomVolumeTask *this,
        ActionContext *context)
{
  UFG::TransformNodeComponent *ComponentOfType; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *TypeName; // rax
  __int64 v8; // rdx
  int vfptr; // ebx
  char *Name; // rax
  ITrack *m_Track; // rax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  UFG::StateMachineComponent *v16; // rcx
  UFG::qVector3 extents; // [rsp+38h] [rbp-50h] BYREF
  UFG::qVector3 offset; // [rsp+48h] [rbp-40h] BYREF
  UFG::qReflectHandleBase v19; // [rsp+58h] [rbp-30h] BYREF

  ComponentOfType = UFG::SimObject::GetComponentOfType(
                      context->mSimObject.m_pPointer,
                      UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                      0,
                      0i64);
  if ( ComponentOfType )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             context->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             ComponentOfType);
      UFG::qReflectHandleBase::qReflectHandleBase(&v19);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v19.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      v8 = *(_QWORD *)&ComponentOfType->mWorldTransform.v2.x;
      if ( v8 )
        UFG::qReflectHandleBase::operator=(&v19, (UFG::qReflectHandleBase *)(v8 + 224));
      if ( v19.mData )
      {
        vfptr = (int)this->m_Track[1].vfptr;
        Name = UFG::qReflectObject::GetName(v19.mData);
        if ( vfptr == (unsigned int)UFG::qStringHashUpper32(Name, -1) || LODWORD(this->m_Track[1].vfptr) == -1 )
        {
          m_Track = this->m_Track;
          v12 = *((float *)&m_Track[1].mResourceOwner + 1);
          v13 = *(float *)&m_Track[1].m_TrackClassNameUID;
          offset.x = *(float *)&m_Track[1].mResourceOwner;
          offset.y = v12;
          offset.z = v13;
          v14 = *(float *)&m_Track[1].mMasterRate.text.mOffset;
          v15 = *((float *)&m_Track[1].mMasterRate.text.mOffset + 1);
          extents.x = *(float *)&m_Track[1].mBreakPoint;
          extents.y = v14;
          extents.z = v15;
          v16 = *(UFG::StateMachineComponent **)&ComponentOfType[1].mChanged;
          if ( v16 )
            UFG::StateMachineComponent::SpawnDestructionPhantomVolume(
              v16,
              HIDWORD(m_Track[1].vfptr),
              &offset,
              &extents,
              *(float *)&m_Track[1].mMasterRate.expression.mOffset);
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v19);
      ComponentOfType = v5;
    }
    while ( v5 );
  }
}

// File Line: 311
// RVA: 0x2EC180
void __fastcall DestructionExplosionTask::Begin(DestructionExplosionTask *this, ActionContext *context)
{
  UFG::RigidBody *ComponentOfType; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  int vfptr; // ebx
  char *Name; // rax
  ITrack *m_Track; // rdx
  float v12; // xmm2_4
  float v13; // xmm1_4
  UFG::qVector3 pos; // [rsp+30h] [rbp-88h] BYREF
  UFG::qReflectHandleBase v15; // [rsp+40h] [rbp-78h] BYREF
  __int64 v16; // [rsp+68h] [rbp-50h]
  UFG::qMatrix44 mat; // [rsp+70h] [rbp-48h] BYREF

  v16 = -2i64;
  ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                        context->mSimObject.m_pPointer,
                                        UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                        0,
                                        0i64);
  if ( ComponentOfType )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             context->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             ComponentOfType);
      UFG::qReflectHandleBase::qReflectHandleBase(&v15);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v15.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      mCollisionMeshData = ComponentOfType->mCollisionMeshData;
      if ( mCollisionMeshData )
        UFG::qReflectHandleBase::operator=(&v15, &mCollisionMeshData->mObjectProperties);
      if ( v15.mData )
      {
        vfptr = (int)this->m_Track[1].vfptr;
        Name = UFG::qReflectObject::GetName(v15.mData);
        if ( vfptr == (unsigned int)UFG::qStringHashUpper32(Name, -1) || LODWORD(this->m_Track[1].vfptr) == -1 )
        {
          UFG::RigidBody::GetTransform(ComponentOfType, &mat);
          m_Track = this->m_Track;
          v12 = mat.v3.z + *(float *)&m_Track[1].m_TrackClassNameUID;
          v13 = mat.v3.y + *((float *)&m_Track[1].mResourceOwner + 1);
          pos.x = mat.v3.x + *(float *)&m_Track[1].mResourceOwner;
          pos.y = v13;
          pos.z = v12;
          UFG::ExplosionManager::CreateExplosion(
            &pos,
            (UFG::qSymbol *)&m_Track[1].vfptr + 1,
            ComponentOfType->m_pSimObject,
            (UFG::SimObject *)ComponentOfType[1].mCollisionMeshBundle.mPrev[13].mPrev);
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
      ComponentOfType = (UFG::RigidBody *)v5;
    }
    while ( v5 );
  }
}

// File Line: 330
// RVA: 0x2EBA40
void __fastcall DestructionEnableFractureElementTask::Begin(
        DestructionEnableFractureElementTask *this,
        ActionContext *context)
{
  UFG::RigidBody *ComponentOfType; // rbx
  UFG::TransformNodeComponent *v5; // rdi
  ITrack *m_Track; // rax
  unsigned int vfptr; // edx

  ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                        context->mSimObject.m_pPointer,
                                        UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                        0,
                                        0i64);
  if ( ComponentOfType )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             context->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             ComponentOfType);
      m_Track = this->m_Track;
      vfptr = (unsigned int)m_Track[1].vfptr;
      if ( vfptr != UFG::gNullQSymbolUC.mUID )
      {
        if ( BYTE4(m_Track[1].vfptr) )
          UFG::RigidBody::EnableFracturePartByGuid(ComponentOfType, vfptr, FRACTURE_STRENGTH_NORMAL);
        else
          UFG::RigidBody::DisableFracturePartByGuid(ComponentOfType, vfptr);
      }
      ComponentOfType = (UFG::RigidBody *)v5;
    }
    while ( v5 );
  }
}

// File Line: 388
// RVA: 0x2EC4E0
void __fastcall DestructionSetDamageTask::Begin(DestructionSetDamageTask *this, ActionContext *context)
{
  UFG::TransformNodeComponent *ComponentOfType; // rdi
  UFG::TransformNodeComponent *v5; // rbp
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *TypeName; // rax
  __int64 v8; // rdx
  int vfptr; // ebx
  char *Name; // rax
  UFG::StateMachineComponent *v11; // rcx
  UFG::qReflectHandleBase v12; // [rsp+28h] [rbp-30h] BYREF

  ComponentOfType = UFG::SimObject::GetComponentOfType(
                      context->mSimObject.m_pPointer,
                      UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                      0,
                      0i64);
  if ( ComponentOfType )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             context->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             ComponentOfType);
      UFG::qReflectHandleBase::qReflectHandleBase(&v12);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v12.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      v8 = *(_QWORD *)&ComponentOfType->mWorldTransform.v2.x;
      if ( v8 )
        UFG::qReflectHandleBase::operator=(&v12, (UFG::qReflectHandleBase *)(v8 + 224));
      if ( v12.mData )
      {
        vfptr = (int)this->m_Track[1].vfptr;
        Name = UFG::qReflectObject::GetName(v12.mData);
        if ( vfptr == (unsigned int)UFG::qStringHashUpper32(Name, -1) || LODWORD(this->m_Track[1].vfptr) == -1 )
        {
          v11 = *(UFG::StateMachineComponent **)&ComponentOfType[1].mChanged;
          if ( v11 )
            UFG::StateMachineComponent::SetDamage(v11, *((float *)&this->m_Track[1].vfptr + 1));
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v12);
      ComponentOfType = v5;
    }
    while ( v5 );
  }
}

// File Line: 409
// RVA: 0x2EB8E0
void __fastcall DestructionDeleteConstraintTask::Begin(DestructionDeleteConstraintTask *this, ActionContext *context)
{
  UFG::RigidBody *ComponentOfType; // rdi
  UFG::TransformNodeComponent *v5; // rbp
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  int vfptr; // ebx
  char *v10; // rax
  ITrack *m_Track; // rax
  UFG::Constraint *ConstraintByName; // rax
  UFG::Constraint *v13; // rbx
  UFG::qReflectHandleBase v14; // [rsp+28h] [rbp-50h] BYREF
  hkBool result; // [rsp+88h] [rbp+10h] BYREF
  UFG::qSymbol name; // [rsp+90h] [rbp+18h] BYREF
  UFG::qSymbol *p_name; // [rsp+98h] [rbp+20h]

  ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                        context->mSimObject.m_pPointer,
                                        UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                        0,
                                        0i64);
  if ( ComponentOfType )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             context->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             ComponentOfType);
      UFG::qReflectHandleBase::qReflectHandleBase(&v14);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v14.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      mCollisionMeshData = ComponentOfType->mCollisionMeshData;
      if ( mCollisionMeshData )
        UFG::qReflectHandleBase::operator=(&v14, &mCollisionMeshData->mObjectProperties);
      if ( v14.mData )
      {
        vfptr = (int)this->m_Track[1].vfptr;
        v10 = UFG::qReflectObject::GetName(v14.mData);
        if ( vfptr == (unsigned int)UFG::qStringHashUpper32(v10, -1) || LODWORD(this->m_Track[1].vfptr) == -1 )
        {
          m_Track = this->m_Track;
          if ( LOBYTE(m_Track[1].mResourceOwner) )
          {
            UFG::RigidBody::DeleteAllConstraints(ComponentOfType);
          }
          else if ( HIDWORD(m_Track[1].vfptr) != -1 )
          {
            p_name = &name;
            name.mUID = HIDWORD(m_Track[1].vfptr);
            ConstraintByName = UFG::RigidBody::GetConstraintByName(ComponentOfType, (int *)&name);
            v13 = ConstraintByName;
            if ( ConstraintByName )
            {
              if ( hkpConstraintInstance::isEnabled(ConstraintByName->mConstraintInstance, &result)->m_bool )
                hkpConstraintInstance::disable(v13->mConstraintInstance);
            }
          }
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v14);
      ComponentOfType = (UFG::RigidBody *)v5;
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
  UFG::RigidBody *ComponentOfType; // rsi
  float v4; // xmm6_4
  UFG::TransformNodeComponent *v5; // r14
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  int vfptr; // ebx
  char *Name; // rax
  float mDecayAmount; // xmm1_4
  float *m_Track; // rax
  float v13; // xmm12_4
  float v14; // xmm8_4
  float v15; // xmm10_4
  float *v16; // rax
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  UFG::qVector3 force; // [rsp+20h] [rbp-C8h] BYREF
  UFG::qVector3 point; // [rsp+2Ch] [rbp-BCh] BYREF
  UFG::qMatrix44 mat; // [rsp+40h] [rbp-A8h] BYREF
  unsigned __int64 v24; // [rsp+80h] [rbp-68h]
  UFG::qReflectObject *v25; // [rsp+90h] [rbp-58h]
  float v26; // [rsp+158h] [rbp+70h]
  float timeDeltaa; // [rsp+160h] [rbp+78h]

  *(_QWORD *)&mat.v2.z = -2i64;
  this->mDecayAmount = (float)(*((float *)&this->m_Track[1].mMasterRate.text.mOffset + 1) * timeDelta)
                     + this->mDecayAmount;
  ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                        this->mContext->mSimObject.m_pPointer,
                                        UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                        0,
                                        0i64);
  if ( ComponentOfType )
  {
    v4 = *(float *)&FLOAT_1_0;
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             this->mContext->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             ComponentOfType);
      UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&mat.v3);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v24 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      mCollisionMeshData = ComponentOfType->mCollisionMeshData;
      if ( mCollisionMeshData )
        UFG::qReflectHandleBase::operator=((UFG::qReflectHandleBase *)&mat.v3, &mCollisionMeshData->mObjectProperties);
      if ( v25 )
      {
        vfptr = (int)this->m_Track[1].vfptr;
        Name = UFG::qReflectObject::GetName(v25);
        if ( vfptr == (unsigned int)UFG::qStringHashUpper32(Name, -1) || LODWORD(this->m_Track[1].vfptr) == -1 )
        {
          mDecayAmount = this->mDecayAmount;
          if ( mDecayAmount <= v4 )
          {
            m_Track = (float *)this->m_Track;
            v13 = m_Track[20] * (float)(v4 - mDecayAmount);
            v14 = m_Track[19] * (float)(v4 - mDecayAmount);
            v15 = m_Track[18] * (float)(v4 - mDecayAmount);
            UFG::RigidBody::GetTransform(ComponentOfType, &mat);
            v26 = (float)((float)(mat.v1.x * v14) + (float)(mat.v0.x * v15)) + (float)(mat.v2.x * v13);
            v16 = (float *)this->m_Track;
            v17 = v16[15];
            v18 = v16[16];
            v19 = v16[17];
            point.x = (float)((float)(mat.v1.x * v18) + (float)(mat.v0.x * v17)) + (float)(mat.v2.x * v19);
            point.y = (float)((float)(mat.v1.y * v18) + (float)(mat.v0.y * v17)) + (float)(mat.v2.y * v19);
            point.z = (float)((float)(mat.v1.z * v18) + (float)(mat.v0.z * v17)) + (float)(mat.v2.z * v19);
            force.x = v26;
            force.y = (float)((float)(mat.v1.y * v14) + (float)(mat.v0.y * v15)) + (float)(mat.v2.y * v13);
            force.z = (float)((float)(mat.v1.z * v14) + (float)(mat.v0.z * v15)) + (float)(mat.v2.z * v13);
            UFG::RigidBody::ApplyForce(ComponentOfType, timeDeltaa, &force, &point);
            v4 = *(float *)&FLOAT_1_0;
          }
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&mat.v3);
      ComponentOfType = (UFG::RigidBody *)v5;
    }
    while ( v5 );
  }
  return 1;
}

// File Line: 481
// RVA: 0x2EC310
void __fastcall DestructionHingeConstraintTask::Begin(DestructionHingeConstraintTask *this, ActionContext *context)
{
  UFG::RigidBody *ComponentOfType; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  int vfptr; // ebx
  char *Name; // rax
  hkpRigidBody *mBody; // rcx
  ITrack *m_Track; // r8
  float limitMax; // xmm4_4
  float limitMin; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  UFG::Constraint *v19; // rbx
  UFG::qVector3 axis; // [rsp+48h] [rbp-50h] BYREF
  UFG::qVector3 pivot; // [rsp+54h] [rbp-44h] BYREF
  UFG::qReflectHandleBase v22; // [rsp+60h] [rbp-38h] BYREF

  ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                        context->mSimObject.m_pPointer,
                                        UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                        0,
                                        0i64);
  if ( ComponentOfType )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             context->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             ComponentOfType);
      UFG::qReflectHandleBase::qReflectHandleBase(&v22);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v22.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      mCollisionMeshData = ComponentOfType->mCollisionMeshData;
      if ( mCollisionMeshData )
        UFG::qReflectHandleBase::operator=(&v22, &mCollisionMeshData->mObjectProperties);
      if ( v22.mData )
      {
        vfptr = (int)this->m_Track[1].vfptr;
        Name = UFG::qReflectObject::GetName(v22.mData);
        if ( vfptr == (unsigned int)UFG::qStringHashUpper32(Name, -1) || LODWORD(this->m_Track[1].vfptr) == -1 )
        {
          mBody = ComponentOfType->mBody;
          if ( mBody )
          {
            m_Track = this->m_Track;
            limitMax = *((float *)&m_Track[1].mMasterRate.expression.mOffset + 1);
            limitMin = *(float *)&m_Track[1].mMasterRate.expression.mOffset;
            v15 = *(float *)&m_Track[1].mMasterRate.text.mOffset;
            v16 = *((float *)&m_Track[1].mMasterRate.text.mOffset + 1);
            axis.x = *(float *)&m_Track[1].mBreakPoint;
            axis.y = v15;
            axis.z = v16;
            v17 = *((float *)&m_Track[1].mResourceOwner + 1);
            v18 = *(float *)&m_Track[1].m_TrackClassNameUID;
            pivot.x = *(float *)&m_Track[1].mResourceOwner;
            pivot.y = v17;
            pivot.z = v18;
            v19 = UFG::Constraint::CreateHingeConstraint(
                    mBody,
                    0i64,
                    (UFG::qSymbol *)&m_Track[1].vfptr + 1,
                    &pivot,
                    &axis,
                    limitMin,
                    limitMax);
            UFG::RigidBody::AddConstraint(ComponentOfType, v19);
            UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v19->mConstraintInstance);
          }
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v22);
      ComponentOfType = (UFG::RigidBody *)v5;
    }
    while ( v5 );
  }
}

// File Line: 505
// RVA: 0x2ED4C0
void __fastcall DestructionStiffSpringConstraintTask::Begin(
        DestructionStiffSpringConstraintTask *this,
        ActionContext *context)
{
  UFG::RigidBody *ComponentOfType; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  int vfptr; // ebx
  char *Name; // rax
  hkpRigidBody *mBody; // rcx
  ITrack *m_Track; // r8
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  UFG::Constraint *v17; // rbx
  UFG::qVector3 pivot2; // [rsp+38h] [rbp-60h] BYREF
  UFG::qVector3 pivot1; // [rsp+44h] [rbp-54h] BYREF
  UFG::qReflectHandleBase v20; // [rsp+50h] [rbp-48h] BYREF

  ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                        context->mSimObject.m_pPointer,
                                        UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                        0,
                                        0i64);
  if ( ComponentOfType )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             context->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             ComponentOfType);
      UFG::qReflectHandleBase::qReflectHandleBase(&v20);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v20.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      mCollisionMeshData = ComponentOfType->mCollisionMeshData;
      if ( mCollisionMeshData )
        UFG::qReflectHandleBase::operator=(&v20, &mCollisionMeshData->mObjectProperties);
      if ( v20.mData )
      {
        vfptr = (int)this->m_Track[1].vfptr;
        Name = UFG::qReflectObject::GetName(v20.mData);
        if ( vfptr == (unsigned int)UFG::qStringHashUpper32(Name, -1) || LODWORD(this->m_Track[1].vfptr) == -1 )
        {
          mBody = ComponentOfType->mBody;
          if ( mBody )
          {
            m_Track = this->m_Track;
            v13 = *(float *)&m_Track[1].mMasterRate.text.mOffset;
            v14 = *((float *)&m_Track[1].mMasterRate.text.mOffset + 1);
            pivot2.x = *(float *)&m_Track[1].mBreakPoint;
            pivot2.y = v13;
            pivot2.z = v14;
            v15 = *((float *)&m_Track[1].mResourceOwner + 1);
            v16 = *(float *)&m_Track[1].m_TrackClassNameUID;
            pivot1.x = *(float *)&m_Track[1].mResourceOwner;
            pivot1.y = v15;
            pivot1.z = v16;
            v17 = UFG::Constraint::CreateStiffSpringContraint(
                    mBody,
                    0i64,
                    (UFG::qSymbol *)&m_Track[1].vfptr + 1,
                    &pivot1,
                    &pivot2);
            UFG::RigidBody::AddConstraint(ComponentOfType, v17);
            UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v17->mConstraintInstance);
          }
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v20);
      ComponentOfType = (UFG::RigidBody *)v5;
    }
    while ( v5 );
  }
}

// File Line: 529
// RVA: 0x2EB770
void __fastcall DestructionBallAndSocketConstraintTask::Begin(
        DestructionBallAndSocketConstraintTask *this,
        ActionContext *context)
{
  UFG::RigidBody *ComponentOfType; // rdi
  UFG::TransformNodeComponent *v5; // rsi
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject> *v6; // rcx
  const char *TypeName; // rax
  UFG::CollisionMeshData *mCollisionMeshData; // rdx
  int vfptr; // ebx
  char *Name; // rax
  hkpRigidBody *mBody; // rcx
  ITrack *m_Track; // r8
  float v13; // xmm1_4
  float v14; // xmm2_4
  UFG::Constraint *v15; // rbx
  UFG::qVector3 pivot; // [rsp+28h] [rbp-40h] BYREF
  UFG::qReflectHandleBase v17; // [rsp+38h] [rbp-30h] BYREF

  ComponentOfType = (UFG::RigidBody *)UFG::SimObject::GetComponentOfType(
                                        context->mSimObject.m_pPointer,
                                        UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
                                        0,
                                        0i64);
  if ( ComponentOfType )
  {
    do
    {
      v5 = UFG::SimObject::GetComponentOfType(
             context->mSimObject.m_pPointer,
             UFG::RigidBodyComponent::_RigidBodyComponentTypeUID,
             0,
             ComponentOfType);
      UFG::qReflectHandleBase::qReflectHandleBase(&v17);
      TypeName = UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::GetTypeName(v6);
      v17.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      mCollisionMeshData = ComponentOfType->mCollisionMeshData;
      if ( mCollisionMeshData )
        UFG::qReflectHandleBase::operator=(&v17, &mCollisionMeshData->mObjectProperties);
      if ( v17.mData )
      {
        vfptr = (int)this->m_Track[1].vfptr;
        Name = UFG::qReflectObject::GetName(v17.mData);
        if ( vfptr == (unsigned int)UFG::qStringHashUpper32(Name, -1) || LODWORD(this->m_Track[1].vfptr) == -1 )
        {
          mBody = ComponentOfType->mBody;
          if ( mBody )
          {
            m_Track = this->m_Track;
            v13 = *((float *)&m_Track[1].mResourceOwner + 1);
            v14 = *(float *)&m_Track[1].m_TrackClassNameUID;
            pivot.x = *(float *)&m_Track[1].mResourceOwner;
            pivot.y = v13;
            pivot.z = v14;
            v15 = UFG::Constraint::CreateBallAndSocketConstraint(
                    mBody,
                    0i64,
                    (UFG::qSymbol *)&m_Track[1].vfptr + 1,
                    &pivot);
            UFG::RigidBody::AddConstraint(ComponentOfType, v15);
            UFG::BasePhysicsSystem::AddConstraint(UFG::BasePhysicsSystem::mInstance, v15->mConstraintInstance);
          }
        }
      }
      UFG::qReflectHandleBase::~qReflectHandleBase(&v17);
      ComponentOfType = (UFG::RigidBody *)v5;
    }
    while ( v5 );
  }
}

