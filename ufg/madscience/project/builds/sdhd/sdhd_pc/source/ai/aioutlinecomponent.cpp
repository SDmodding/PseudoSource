// File Line: 43
// RVA: 0x14AEA20
__int64 dynamic_initializer_for__UFG::AIOutlineComponent::s_AIOutlineComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::AIOutlineComponent::s_AIOutlineComponentList__);
}

// File Line: 44
// RVA: 0x35D8D0
UFG::ComponentIDDesc *__fastcall UFG::AIOutlineComponent::GetDesc(UFG::AIOutlineComponent *this)
{
  return &UFG::AIOutlineComponent::_TypeIDesc;
}

// File Line: 56
// RVA: 0x32B920
void __fastcall UFG::AIOutlineComponent::AIOutlineComponent(UFG::AIOutlineComponent *this, unsigned int name_uid)
{
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent>;
  this->mNext = &this->UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIOutlineComponent::`vftable;
  this->m_pTransformNodeComponent.mPrev = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  this->m_pRigidBodyComponent.mPrev = &this->m_pRigidBodyComponent;
  this->m_pRigidBodyComponent.mNext = &this->m_pRigidBodyComponent;
  this->m_pRigidBodyComponent.m_pPointer = 0i64;
  *(_QWORD *)&this->mStationaryTimer = 0i64;
  *(_QWORD *)&this->mLength = 0i64;
  this->mpDynamicOutline = 0i64;
  this->mDimensionsDefinedBy = 0;
  mPrev = UFG::AIOutlineComponent::s_AIOutlineComponentList.mNode.mPrev;
  UFG::AIOutlineComponent::s_AIOutlineComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *)&UFG::AIOutlineComponent::s_AIOutlineComponentList;
  UFG::AIOutlineComponent::s_AIOutlineComponentList.mNode.mPrev = &this->UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent>;
  UFG::SimComponent::AddType(this, UFG::AIOutlineComponent::_AIOutlineComponentTypeUID, "AIOutlineComponent");
  *(_WORD *)&this->mQueueAddToWorld = 0;
  this->mSizeInitialized = 0;
}

// File Line: 66
// RVA: 0x334510
void __fastcall UFG::AIOutlineComponent::~AIOutlineComponent(UFG::AIOutlineComponent *this)
{
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *v2; // r8
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *mPrev; // rcx
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_m_pRigidBodyComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *v15; // rcx
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *v16; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIOutlineComponent::`vftable;
  if ( !this->mQueueAddToWorld || (this->mQueueAddToWorld = 0, this->mAddedToWorld) )
  {
    if ( this->mAddedToWorld )
    {
      UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline(UFG::NavManager::ms_pInstance, this->mpDynamicOutline);
      this->mpDynamicOutline = 0i64;
      *(_WORD *)&this->mQueueAddToWorld = 0;
    }
  }
  if ( this == UFG::AIOutlineComponent::s_AIOutlineComponentpCurrentIterator )
    UFG::AIOutlineComponent::s_AIOutlineComponentpCurrentIterator = (UFG::AIOutlineComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent>;
  this->mNext = &this->UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent>;
  p_m_pRigidBodyComponent = &this->m_pRigidBodyComponent;
  if ( this->m_pRigidBodyComponent.m_pPointer )
  {
    v6 = p_m_pRigidBodyComponent->mPrev;
    v7 = this->m_pRigidBodyComponent.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_pRigidBodyComponent->mPrev = p_m_pRigidBodyComponent;
    this->m_pRigidBodyComponent.mNext = &this->m_pRigidBodyComponent;
  }
  this->m_pRigidBodyComponent.m_pPointer = 0i64;
  v8 = p_m_pRigidBodyComponent->mPrev;
  v9 = this->m_pRigidBodyComponent.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_m_pRigidBodyComponent->mPrev = p_m_pRigidBodyComponent;
  this->m_pRigidBodyComponent.mNext = &this->m_pRigidBodyComponent;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    v11 = p_m_pTransformNodeComponent->mPrev;
    v12 = this->m_pTransformNodeComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  }
  this->m_pTransformNodeComponent.m_pPointer = 0i64;
  v13 = p_m_pTransformNodeComponent->mPrev;
  v14 = this->m_pTransformNodeComponent.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
  this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  v15 = v2->mPrev;
  v16 = this->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v2->mPrev = v2;
  this->mNext = &this->UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 73
// RVA: 0x3630B0
bool __fastcall UFG::AIOutlineComponent::GetTransform(UFG::AIOutlineComponent *this, UFG::qMatrix44 *transform)
{
  char mDimensionsDefinedBy; // al
  bool result; // al
  UFG::SimComponent *m_pPointer; // rbx
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 m_BoundComponentHandles; // xmm1

  if ( this->m_pRigidBodyComponent.m_pPointer
    && (mDimensionsDefinedBy = this->mDimensionsDefinedBy, (mDimensionsDefinedBy & 1) != 0)
    && (unsigned __int8)mDimensionsDefinedBy < 2u )
  {
    UFG::RigidBody::GetTransform((UFG::RigidBody *)this->m_pRigidBodyComponent.m_pPointer, transform);
    return 1;
  }
  else
  {
    m_pPointer = this->m_pTransformNodeComponent.m_pPointer;
    if ( m_pPointer )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer);
      result = 1;
      v6 = *(UFG::qVector4 *)&m_pPointer[2].m_SafePointerList.mNode.mNext;
      v7 = *(UFG::qVector4 *)&m_pPointer[2].m_Flags;
      m_BoundComponentHandles = (UFG::qVector4)m_pPointer[2].m_BoundComponentHandles;
      transform->v0 = *(UFG::qVector4 *)&m_pPointer[2].vfptr;
      transform->v1 = v6;
      transform->v2 = v7;
      transform->v3 = m_BoundComponentHandles;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

// File Line: 100
// RVA: 0x378680
// attributes: thunk
void __fastcall UFG::AIOutlineComponent::OnAttach(UFG::AIOutlineComponent *this, UFG::SimObject *object)
{
  UFG::AIOutlineComponent::Init(this);
}

// File Line: 114
// RVA: 0x379CE0
void __fastcall UFG::AIOutlineComponent::OnDetach(UFG::AIOutlineComponent *this)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_m_pRigidBodyComponent; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  if ( !this->mQueueAddToWorld || (this->mQueueAddToWorld = 0, this->mAddedToWorld) )
  {
    if ( this->mAddedToWorld )
    {
      UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline(UFG::NavManager::ms_pInstance, this->mpDynamicOutline);
      this->mpDynamicOutline = 0i64;
      *(_WORD *)&this->mQueueAddToWorld = 0;
    }
  }
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  this->mStationaryTimer = 0.0;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    mPrev = p_m_pTransformNodeComponent->mPrev;
    mNext = this->m_pTransformNodeComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    this->m_pTransformNodeComponent.mNext = &this->m_pTransformNodeComponent;
  }
  p_m_pRigidBodyComponent = &this->m_pRigidBodyComponent;
  p_m_pTransformNodeComponent->m_pPointer = 0i64;
  if ( p_m_pRigidBodyComponent->m_pPointer )
  {
    v6 = p_m_pRigidBodyComponent->mPrev;
    v7 = p_m_pRigidBodyComponent->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    p_m_pRigidBodyComponent->mPrev = p_m_pRigidBodyComponent;
    p_m_pRigidBodyComponent->mNext = p_m_pRigidBodyComponent;
  }
  p_m_pRigidBodyComponent->m_pPointer = 0i64;
}

// File Line: 123
// RVA: 0x3897B0
void __fastcall UFG::AIOutlineComponent::Suspend(UFG::AIOutlineComponent *this)
{
  bool v2; // zf

  if ( this->mQueueAddToWorld )
  {
    v2 = !this->mAddedToWorld;
    this->mQueueAddToWorld = 0;
    if ( v2 )
    {
LABEL_3:
      this->mStationaryTimer = 0.0;
      return;
    }
  }
  else if ( !this->mAddedToWorld )
  {
    goto LABEL_3;
  }
  UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline(UFG::NavManager::ms_pInstance, this->mpDynamicOutline);
  this->mpDynamicOutline = 0i64;
  *(_WORD *)&this->mQueueAddToWorld = 0;
  this->mStationaryTimer = 0.0;
}

// File Line: 129
// RVA: 0x383E40
// attributes: thunk
void __fastcall UFG::AIOutlineComponent::Restore(UFG::AIOutlineComponent *this)
{
  UFG::AIOutlineComponent::ActivateOutline(this);
}

// File Line: 135
// RVA: 0x364D60
bool __fastcall UFG::AIOutlineComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentAIOutline,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 140
// RVA: 0x37E3F0
UFG::AIOutlineComponent *__fastcall UFG::AIOutlineComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::AIOutlineComponent *v4; // rax
  UFG::AIOutlineComponent *v5; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xB0ui64, "AI::AIOutlineComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::AIOutlineComponent::AIOutlineComponent((UFG::AIOutlineComponent *)v3, pSceneObj->m_NameUID);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::AIOutlineComponent::SetAABBFromPropertySet(v5, pSceneObj);
  m_pSimObject = pSceneObj->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags >= 0 )
    v8 = -1;
  else
    v8 = 27;
  UFG::SimObjectModifier::SimObjectModifier(&v10, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v5, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return v5;
}

// File Line: 150
// RVA: 0x384CF0
void __fastcall UFG::AIOutlineComponent::SetAABBFromPropertySet(
        UFG::AIOutlineComponent *this,
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *mpConstProperties; // rbx
  UFG::qPropertySet *v5; // rax
  UFG::qVector3 *MemImagePtr; // rax
  UFG::qVector3 *v7; // rsi
  UFG::qVector3 *v8; // rax

  mpWritableProperties = pSceneObj->mpWritableProperties;
  mpConstProperties = mpWritableProperties;
  if ( !mpWritableProperties )
    mpConstProperties = pSceneObj->mpConstProperties;
  if ( mpConstProperties )
  {
    if ( !mpWritableProperties )
      mpWritableProperties = pSceneObj->mpConstProperties;
    v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&component_PhysicsMover::sPropertyName,
           DEPTH_RECURSE);
    if ( v5 && (MemImagePtr = (UFG::qVector3 *)UFG::qPropertySet::GetMemImagePtr(v5)) != 0i64 )
    {
      UFG::AIOutlineComponent::SetLocalAABB(
        this,
        MemImagePtr + 3,
        MemImagePtr + 4,
        eOutlineDimensionsDefinedBy_PropertySet);
    }
    else
    {
      v7 = UFG::qPropertySet::Get<UFG::qVector3>(
             mpConstProperties,
             (UFG::qArray<unsigned long,0> *)&qSymbol_AIOutlineBoundingBoxMin,
             DEPTH_RECURSE);
      v8 = UFG::qPropertySet::Get<UFG::qVector3>(
             mpConstProperties,
             (UFG::qArray<unsigned long,0> *)&qSymbol_AIOutlineBoundingBoxMax,
             DEPTH_RECURSE);
      if ( v7 )
      {
        if ( v8 )
          UFG::AIOutlineComponent::SetLocalAABB(this, v7, v8, eOutlineDimensionsDefinedBy_PropertySet);
      }
    }
  }
}

// File Line: 190
// RVA: 0x365810
void __fastcall UFG::AIOutlineComponent::Init(UFG::AIOutlineComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_m_pTransformNodeComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  __int16 m_Flags; // cx
  UFG::RigidBodyComponent *ComponentOfTypeHK; // rax
  UFG::SimComponent *ComponentOfType; // rax
  UFG::RegionComponent *vfptr; // rcx
  char mDimensionsDefinedBy; // al
  float y; // xmm3_4
  float x; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float z; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  char v20; // al
  UFG::RigidBody *m_pPointer; // rcx
  UFG::SimComponent *v22; // rdi
  UFG::qVector4 v23; // xmm2
  UFG::qVector4 m_BoundComponentHandles; // xmm1
  UFG::qVector4 v25; // xmm0
  UFG::qBox pBox; // [rsp+20h] [rbp-78h] BYREF
  UFG::qMatrix44 mat; // [rsp+40h] [rbp-58h] BYREF

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  p_m_pTransformNodeComponent = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    mPrev = p_m_pTransformNodeComponent->mPrev;
    mNext = p_m_pTransformNodeComponent->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pTransformNodeComponent->mPrev = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mNext = p_m_pTransformNodeComponent;
  }
  p_m_pTransformNodeComponent->m_pPointer = m_pTransformNodeComponent;
  if ( m_pTransformNodeComponent )
  {
    v7 = m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v7->mNext = p_m_pTransformNodeComponent;
    p_m_pTransformNodeComponent->mPrev = v7;
    p_m_pTransformNodeComponent->mNext = &m_pTransformNodeComponent->m_SafePointerList.mNode;
    m_pTransformNodeComponent->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pTransformNodeComponent;
  }
  if ( !this->m_pRigidBodyComponent.m_pPointer )
  {
    if ( !m_pSimObject )
      goto LABEL_25;
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = (UFG::RigidBodyComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                       m_pSimObject,
                                                       UFG::RigidBodyComponent::_TypeUID);
    else
      ComponentOfTypeHK = (UFG::RigidBodyComponent *)UFG::SimObject::GetComponentOfType(
                                                       m_pSimObject,
                                                       UFG::RigidBodyComponent::_TypeUID);
    if ( ComponentOfTypeHK )
      UFG::AIOutlineComponent::SetLocalAABB(this, ComponentOfTypeHK);
  }
  if ( m_pSimObject )
  {
    ComponentOfType = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::AIOutlineRegion::_TypeUID);
    if ( ComponentOfType )
    {
      vfptr = (UFG::RegionComponent *)ComponentOfType[2].vfptr;
      memset(&pBox, 0, sizeof(pBox));
      UFG::RegionComponent::GetLocalBoundingBox(vfptr, &pBox);
      mDimensionsDefinedBy = this->mDimensionsDefinedBy;
      if ( (unsigned __int8)mDimensionsDefinedBy > 4u )
      {
        this->mDimensionsDefinedBy = mDimensionsDefinedBy | 4;
      }
      else
      {
        y = pBox.mMax.y;
        x = pBox.mMax.x;
        v15 = pBox.mMin.y;
        this->mDimensionsDefinedBy = mDimensionsDefinedBy | 4;
        v16 = pBox.mMin.x;
        z = pBox.mMax.z;
        v18 = x - pBox.mMin.x;
        this->mWidth = y - v15;
        v19 = pBox.mMin.z;
        this->mLength = v18;
        this->mHeight = z - v19;
        this->mOffset.x = (float)(v16 + x) * 0.5;
        this->mOffset.z = (float)(v19 + z) * 0.5;
        this->mOffset.y = (float)(v15 + y) * 0.5;
        this->mOffset.z = this->mOffset.z - (float)(this->mHeight * 0.5);
      }
      this->mSizeInitialized = 1;
    }
  }
LABEL_25:
  v20 = this->mDimensionsDefinedBy;
  if ( !v20 )
    return;
  m_pPointer = (UFG::RigidBody *)this->m_pRigidBodyComponent.m_pPointer;
  if ( m_pPointer && (v20 & 1) != 0 && (unsigned __int8)v20 < 2u )
  {
    UFG::RigidBody::GetTransform(m_pPointer, &mat);
  }
  else
  {
    v22 = this->m_pTransformNodeComponent.m_pPointer;
    if ( !v22 )
      return;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer);
    v23 = *(UFG::qVector4 *)&v22[2].m_Flags;
    m_BoundComponentHandles = (UFG::qVector4)v22[2].m_BoundComponentHandles;
    v25 = *(UFG::qVector4 *)&v22[2].vfptr;
    mat.v1 = *(UFG::qVector4 *)&v22[2].m_SafePointerList.mNode.mNext;
    mat.v2 = v23;
    mat.v0 = v25;
    mat.v3 = m_BoundComponentHandles;
  }
  this->mQueueAddToWorld = 1;
}

// File Line: 228
// RVA: 0x358470
void __fastcall UFG::AIOutlineComponent::ForceUpdate(UFG::AIOutlineComponent *this, UFG::Event *this_event)
{
  bool v3; // cf

  if ( this->mQueueAddToWorld )
  {
    v3 = !this->mAddedToWorld;
    this->mQueueAddToWorld = 0;
    if ( !v3 )
    {
      UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline(UFG::NavManager::ms_pInstance, this->mpDynamicOutline);
      this->mpDynamicOutline = 0i64;
      *(_WORD *)&this->mQueueAddToWorld = 0;
    }
    this->mStationaryTimer = 0.0;
    this->mQueueAddToWorld = 1;
  }
}

// File Line: 242
// RVA: 0x387350
void __fastcall UFG::AIOutlineComponent::SetLocalAABB(
        UFG::AIOutlineComponent *this,
        UFG::RigidBodyComponent *pRigidBodyComp)
{
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_m_pRigidBodyComponent; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::SimObject *m_pSimObject; // rsi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rsi
  float v10; // xmm0_4
  float z; // xmm7_4
  float v12; // xmm6_4
  char mDimensionsDefinedBy; // al
  float x; // xmm3_4
  float v15; // xmm5_4
  float y; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm4_4
  float v19; // xmm6_4
  UFG::qVector3 aabbMax; // [rsp+20h] [rbp-60h] BYREF
  UFG::qVector3 aabbMin; // [rsp+30h] [rbp-50h] BYREF
  UFG::qVector3 v22; // [rsp+40h] [rbp-40h] BYREF
  UFG::qVector3 v23; // [rsp+50h] [rbp-30h] BYREF

  p_m_pRigidBodyComponent = &this->m_pRigidBodyComponent;
  if ( this->m_pRigidBodyComponent.m_pPointer )
  {
    mPrev = p_m_pRigidBodyComponent->mPrev;
    mNext = this->m_pRigidBodyComponent.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_pRigidBodyComponent->mPrev = p_m_pRigidBodyComponent;
    this->m_pRigidBodyComponent.mNext = &this->m_pRigidBodyComponent;
  }
  this->m_pRigidBodyComponent.m_pPointer = pRigidBodyComp;
  if ( pRigidBodyComp )
  {
    v7 = pRigidBodyComp->m_SafePointerList.mNode.UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
    v7->mNext = p_m_pRigidBodyComponent;
    p_m_pRigidBodyComponent->mPrev = v7;
    this->m_pRigidBodyComponent.mNext = &pRigidBodyComp->m_SafePointerList.mNode;
    pRigidBodyComp->m_SafePointerList.mNode.UFG::RigidBody::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_pRigidBodyComponent;
  }
  aabbMin.x = -1.0;
  aabbMin.y = -1.0;
  aabbMin.z = -1.0;
  aabbMax.x = 1.0;
  aabbMax.y = 1.0;
  aabbMax.z = 1.0;
  if ( UFG::RigidBody::GetAabb(pRigidBodyComp, &aabbMin, &aabbMax, LOCAL_AABB) )
  {
    m_pSimObject = pRigidBodyComp->m_pSimObject;
    if ( m_pSimObject && (m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent) != 0i64 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      v22.x = -1.0;
      v22.y = -1.0;
      v22.z = -1.0;
      v23.x = 1.0;
      v23.y = 1.0;
      v23.z = 1.0;
      UFG::RigidBody::GetAabb(pRigidBodyComp, &v22, &v23, WORLD_AABB);
      v10 = v22.z - m_pTransformNodeComponent->mWorldTransform.v3.z;
      z = aabbMin.z - v10;
      v12 = aabbMax.z - v10;
    }
    else
    {
      z = aabbMin.z;
      v12 = aabbMax.z;
    }
    mDimensionsDefinedBy = this->mDimensionsDefinedBy;
    if ( (unsigned __int8)mDimensionsDefinedBy > 1u )
    {
      this->mDimensionsDefinedBy = mDimensionsDefinedBy | 1;
    }
    else
    {
      x = aabbMax.x;
      v15 = aabbMin.x;
      y = aabbMax.y;
      this->mDimensionsDefinedBy = mDimensionsDefinedBy | 1;
      v17 = y - aabbMin.y;
      v18 = y + aabbMin.y;
      this->mLength = x - v15;
      this->mWidth = v17;
      this->mHeight = v12 - z;
      v19 = (float)(v12 + z) * 0.5;
      this->mOffset.x = (float)(v15 + x) * 0.5;
      this->mOffset.y = v18 * 0.5;
      this->mOffset.z = v19;
      this->mOffset.z = v19 - (float)(this->mHeight * 0.5);
    }
    this->mSizeInitialized = 1;
  }
}

// File Line: 270
// RVA: 0x387270
void __fastcall UFG::AIOutlineComponent::SetLocalAABB(
        UFG::AIOutlineComponent *this,
        UFG::qVector3 *min,
        UFG::qVector3 *max,
        UFG::eOutlineDimensionsDefinedBy eDefinedBy)
{
  UFG::eOutlineDimensionsDefinedBy mDimensionsDefinedBy; // eax
  float v5; // xmm2_4
  float v6; // xmm3_4
  float mHeight; // xmm1_4

  mDimensionsDefinedBy = (unsigned __int8)this->mDimensionsDefinedBy;
  if ( mDimensionsDefinedBy > eDefinedBy )
  {
    this->mSizeInitialized = 1;
    this->mDimensionsDefinedBy = eDefinedBy | mDimensionsDefinedBy;
  }
  else
  {
    this->mDimensionsDefinedBy = eDefinedBy | mDimensionsDefinedBy;
    this->mLength = max->x - min->x;
    this->mWidth = max->y - min->y;
    this->mHeight = max->z - min->z;
    v5 = min->y + max->y;
    v6 = (float)(min->x + max->x) * 0.5;
    this->mOffset.z = (float)(min->z + max->z) * 0.5;
    this->mOffset.x = v6;
    this->mOffset.y = v5 * 0.5;
    mHeight = this->mHeight;
    this->mSizeInitialized = 1;
    this->mOffset.z = this->mOffset.z - (float)(mHeight * 0.5);
  }
}

// File Line: 289
// RVA: 0x360BA0
void __fastcall UFG::AIOutlineComponent::GetLocalAABB(
        UFG::AIOutlineComponent *this,
        UFG::qVector3 *min,
        UFG::qVector3 *max)
{
  float v3; // xmm3_4

  v3 = this->mOffset.x - (float)(this->mLength * 0.5);
  min->x = v3;
  min->y = this->mOffset.y - (float)(this->mWidth * 0.5);
  min->z = this->mOffset.z;
  max->x = v3 + this->mLength;
  max->y = this->mWidth + min->y;
  max->z = this->mHeight + min->z;
}

// File Line: 301
// RVA: 0x38C110
void __fastcall UFG::AIOutlineComponent::Update(UFG::AIOutlineComponent *this, float delta_time)
{
  UFG::SimObject *m_pSimObject; // rcx
  UFG::SimComponentHolder *p; // rax
  UFG::SimComponent *m_pComponent; // rdi
  float v6; // xmm6_4

  m_pSimObject = this->m_pSimObject;
  if ( (m_pSimObject->m_Flags & 0x8000u) != 0 )
  {
    p = m_pSimObject->m_Components.p;
    m_pComponent = p[34].m_pComponent;
    if ( m_pComponent )
    {
      if ( (UFG::PhysicsMoverInterface::GetLOD((UFG::PhysicsMoverInterface *)p[34].m_pComponent) >= LOD_MEDIUM
         || ((__int64)m_pComponent[14].vfptr & 1) != 0)
        && UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH((UFG::PhysicsMoverInterface *)m_pComponent) < 2.0 )
      {
        v6 = delta_time + this->mStationaryTimer;
        this->mStationaryTimer = v6;
        if ( v6 > 0.5 )
        {
          this->mQueueAddToWorld = 1;
          goto LABEL_10;
        }
      }
      else
      {
        this->mStationaryTimer = 0.0;
      }
    }
    UFG::AIOutlineComponent::DeactivateOutline(this);
  }
LABEL_10:
  if ( this->mQueueAddToWorld && !this->mAddedToWorld )
    UFG::AIOutlineComponent::ActivateOutline(this);
}

// File Line: 383
// RVA: 0x351980
void __fastcall UFG::AIOutlineComponent::DeactivateOutline(UFG::AIOutlineComponent *this)
{
  bool v2; // zf

  if ( !this->mQueueAddToWorld || (v2 = !this->mAddedToWorld, this->mQueueAddToWorld = 0, !v2) )
  {
    if ( this->mAddedToWorld )
    {
      UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline(UFG::NavManager::ms_pInstance, this->mpDynamicOutline);
      this->mpDynamicOutline = 0i64;
      *(_WORD *)&this->mQueueAddToWorld = 0;
    }
  }
}

// File Line: 412
// RVA: 0x33F950
void __fastcall UFG::AIOutlineComponent::ActivateOutline(UFG::AIOutlineComponent *this)
{
  float mLength; // xmm5_4
  float mWidth; // xmm4_4
  int v4[4]; // [rsp+38h] [rbp-80h] BYREF
  float v5; // [rsp+48h] [rbp-70h] BYREF
  float v6; // [rsp+4Ch] [rbp-6Ch]
  float z; // [rsp+50h] [rbp-68h]
  __int64 v8; // [rsp+58h] [rbp-60h]
  __int64 v9; // [rsp+60h] [rbp-58h]
  UFG::qMatrix44 transform; // [rsp+70h] [rbp-48h] BYREF

  if ( this->mQueueAddToWorld )
  {
    if ( !this->mAddedToWorld )
    {
      if ( this->mSizeInitialized )
      {
        if ( UFG::AIOutlineComponent::GetTransform(this, &transform)
          && (COERCE_FLOAT(LODWORD(transform.v3.x) & _xmm) >= 0.1
           || COERCE_FLOAT(LODWORD(transform.v3.y) & _xmm) >= 0.1
           || COERCE_FLOAT(LODWORD(transform.v3.z) & _xmm) >= 0.1) )
        {
          mLength = this->mLength;
          v5 = this->mOffset.x - (float)(mLength * 0.5);
          mWidth = this->mWidth;
          v6 = this->mOffset.y - (float)(mWidth * 0.5);
          z = this->mOffset.z;
          *(float *)v4 = mLength + v5;
          *(float *)&v4[1] = mWidth + v6;
          *(float *)&v4[2] = z + this->mHeight;
          v9 = 0i64;
          v8 = 0i64;
          this->mpDynamicOutline = (UFG::NavDynamicOutline *)((__int64 (__fastcall *)(UFG::NavManager *, UFG::qMatrix44 *, float *, int *, _QWORD, _DWORD, __int64))UFG::NavManager::ms_pInstance->vfptr->AddDynamicOutline)(
                                                               UFG::NavManager::ms_pInstance,
                                                               &transform,
                                                               &v5,
                                                               v4,
                                                               0i64,
                                                               0,
                                                               -2i64);
          this->mAddedToWorld = 1;
        }
      }
      else
      {
        UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_AIHavok,
          OUTPUT_LEVEL_ERROR,
          "[AIHavok] Error! (0x%x) (%s) Does not have dimensions set!\n");
        this->mQueueAddToWorld = 0;
      }
    }
  }
  else
  {
    this->mQueueAddToWorld = 1;
  }
}

