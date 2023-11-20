// File Line: 43
// RVA: 0x14AEA20
__int64 dynamic_initializer_for__UFG::AIOutlineComponent::s_AIOutlineComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::AIOutlineComponent::s_AIOutlineComponentList__);
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
  UFG::AIOutlineComponent *v2; // rbx
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *v3; // rdx
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v5; // [rsp+50h] [rbp+18h]
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v6; // [rsp+50h] [rbp+18h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIOutlineComponent::`vftable';
  v5 = &v2->m_pTransformNodeComponent;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v2->m_pTransformNodeComponent.m_pPointer = 0i64;
  v6 = &v2->m_pRigidBodyComponent;
  v6->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v6->mPrev;
  v2->m_pRigidBodyComponent.m_pPointer = 0i64;
  *(_QWORD *)&v2->mStationaryTimer = 0i64;
  *(_QWORD *)&v2->mLength = 0i64;
  v2->mpDynamicOutline = 0i64;
  v2->mDimensionsDefinedBy = 0;
  v4 = UFG::AIOutlineComponent::s_AIOutlineComponentList.mNode.mPrev;
  UFG::AIOutlineComponent::s_AIOutlineComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *)&UFG::AIOutlineComponent::s_AIOutlineComponentList;
  UFG::AIOutlineComponent::s_AIOutlineComponentList.mNode.mPrev = (UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::AIOutlineComponent::_AIOutlineComponentTypeUID,
    "AIOutlineComponent");
  *(_WORD *)&v2->mQueueAddToWorld = 0;
  v2->mSizeInitialized = 0;
}

// File Line: 66
// RVA: 0x334510
void __fastcall UFG::AIOutlineComponent::~AIOutlineComponent(UFG::AIOutlineComponent *this)
{
  UFG::AIOutlineComponent *v1; // rbx
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *v2; // r8
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *v3; // rcx
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v5; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *v15; // rcx
  UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *v16; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::AIOutlineComponent::`vftable';
  if ( !this->mQueueAddToWorld || (this->mQueueAddToWorld = 0, this->mAddedToWorld) )
  {
    if ( this->mAddedToWorld )
    {
      UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline(UFG::NavManager::ms_pInstance, this->mpDynamicOutline);
      v1->mpDynamicOutline = 0i64;
      *(_WORD *)&v1->mQueueAddToWorld = 0;
    }
  }
  if ( v1 == UFG::AIOutlineComponent::s_AIOutlineComponentpCurrentIterator )
    UFG::AIOutlineComponent::s_AIOutlineComponentpCurrentIterator = (UFG::AIOutlineComponent *)&v1->mPrev[-4];
  v2 = (UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = &v1->m_pRigidBodyComponent;
  if ( v1->m_pRigidBodyComponent.m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v1->m_pRigidBodyComponent.mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v1->m_pRigidBodyComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pRigidBodyComponent.mPrev;
  }
  v1->m_pRigidBodyComponent.m_pPointer = 0i64;
  v8 = v5->mPrev;
  v9 = v1->m_pRigidBodyComponent.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  v1->m_pRigidBodyComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pRigidBodyComponent.mPrev;
  v10 = &v1->m_pTransformNodeComponent;
  if ( v1->m_pTransformNodeComponent.m_pPointer )
  {
    v11 = v10->mPrev;
    v12 = v1->m_pTransformNodeComponent.mNext;
    v11->mNext = v12;
    v12->mPrev = v11;
    v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
    v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTransformNodeComponent.mPrev;
  }
  v1->m_pTransformNodeComponent.m_pPointer = 0i64;
  v13 = v10->mPrev;
  v14 = v1->m_pTransformNodeComponent.mNext;
  v13->mNext = v14;
  v14->mPrev = v13;
  v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v10->mPrev;
  v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTransformNodeComponent.mPrev;
  v15 = v2->mPrev;
  v16 = v1->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v2->mPrev = v2;
  v1->mNext = (UFG::qNode<UFG::AIOutlineComponent,UFG::AIOutlineComponent> *)&v1->mPrev;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 73
// RVA: 0x3630B0
char __fastcall UFG::AIOutlineComponent::GetTransform(UFG::AIOutlineComponent *this, UFG::qMatrix44 *transform)
{
  UFG::qMatrix44 *v2; // rdi
  char v3; // al
  char result; // al
  UFG::SimComponent *v5; // rbx
  UFG::qVector4 v6; // xmm3
  UFG::qVector4 v7; // xmm2
  UFG::qVector4 v8; // xmm1

  v2 = transform;
  if ( this->m_pRigidBodyComponent.m_pPointer && (v3 = this->mDimensionsDefinedBy, v3 & 1) && (unsigned __int8)v3 < 2u )
  {
    UFG::RigidBody::GetTransform((UFG::RigidBody *)this->m_pRigidBodyComponent.m_pPointer, transform);
    result = 1;
  }
  else
  {
    v5 = this->m_pTransformNodeComponent.m_pPointer;
    if ( v5 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)this->m_pTransformNodeComponent.m_pPointer);
      result = 1;
      v6 = *(UFG::qVector4 *)&v5[2].m_SafePointerList.mNode.mNext;
      v7 = *(UFG::qVector4 *)&v5[2].m_Flags;
      v8 = (UFG::qVector4)v5[2].m_BoundComponentHandles;
      v2->v0 = *(UFG::qVector4 *)&v5[2].vfptr;
      v2->v1 = v6;
      v2->v2 = v7;
      v2->v3 = v8;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

// File Line: 100
// RVA: 0x378680
void __fastcall UFG::AIOutlineComponent::OnAttach(UFG::AIOutlineComponent *this, UFG::SimObject *object)
{
  UFG::AIOutlineComponent::Init(this);
}

// File Line: 114
// RVA: 0x379CE0
void __fastcall UFG::AIOutlineComponent::OnDetach(UFG::AIOutlineComponent *this)
{
  UFG::AIOutlineComponent *v1; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v5; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax

  v1 = this;
  if ( !this->mQueueAddToWorld || (this->mQueueAddToWorld = 0, this->mAddedToWorld) )
  {
    if ( this->mAddedToWorld )
    {
      UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline(UFG::NavManager::ms_pInstance, this->mpDynamicOutline);
      v1->mpDynamicOutline = 0i64;
      *(_WORD *)&v1->mQueueAddToWorld = 0;
    }
  }
  v2 = &v1->m_pTransformNodeComponent;
  v1->mStationaryTimer = 0.0;
  if ( v1->m_pTransformNodeComponent.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v1->m_pTransformNodeComponent.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v1->m_pTransformNodeComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_pTransformNodeComponent.mPrev;
  }
  v5 = &v1->m_pRigidBodyComponent;
  v2->m_pPointer = 0i64;
  if ( v5->m_pPointer )
  {
    v6 = v5->mPrev;
    v7 = v5->mNext;
    v6->mNext = v7;
    v7->mPrev = v6;
    v5->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
    v5->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mPrev;
  }
  v5->m_pPointer = 0i64;
}

// File Line: 123
// RVA: 0x3897B0
void __fastcall UFG::AIOutlineComponent::Suspend(UFG::AIOutlineComponent *this)
{
  UFG::AIOutlineComponent *v1; // rbx
  bool v2; // zf

  v1 = this;
  if ( this->mQueueAddToWorld )
  {
    v2 = this->mAddedToWorld == 0;
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
  v1->mpDynamicOutline = 0i64;
  *(_WORD *)&v1->mQueueAddToWorld = 0;
  v1->mStationaryTimer = 0.0;
}

// File Line: 129
// RVA: 0x383E40
void __fastcall UFG::AIOutlineComponent::Restore(UFG::AIOutlineComponent *this)
{
  UFG::AIOutlineComponent::ActivateOutline(this);
}

// File Line: 135
// RVA: 0x364D60
bool __fastcall UFG::AIOutlineComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentAIOutline.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 140
// RVA: 0x37E3F0
UFG::AIOutlineComponent *__fastcall UFG::AIOutlineComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::AIOutlineComponent *v4; // rax
  UFG::AIOutlineComponent *v5; // rdi
  UFG::SimObject *v6; // rdx
  unsigned __int16 v7; // cx
  unsigned int v8; // ebx
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0xB0ui64, "AI::AIOutlineComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::AIOutlineComponent::AIOutlineComponent((UFG::AIOutlineComponent *)v3, v1->m_NameUID);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::AIOutlineComponent::SetAABBFromPropertySet(v5, v1);
  v6 = v1->m_pSimObject;
  v7 = v6->m_Flags;
  if ( (v7 >> 14) & 1 || (v7 & 0x8000u) == 0 )
    v8 = -1;
  else
    v8 = 27;
  UFG::SimObjectModifier::SimObjectModifier(&v10, v6, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, (UFG::SimComponent *)&v5->vfptr, v8);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return v5;
}

// File Line: 150
// RVA: 0x384CF0
void __fastcall UFG::AIOutlineComponent::SetAABBFromPropertySet(UFG::AIOutlineComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::AIOutlineComponent *v2; // rdi
  UFG::qPropertySet *v3; // rcx
  UFG::qPropertySet *v4; // rbx
  UFG::qPropertySet *v5; // rax
  UFG::qVector3 *v6; // rax
  UFG::qVector3 *v7; // rsi
  UFG::qVector3 *v8; // rax

  v2 = this;
  v3 = pSceneObj->mpWritableProperties;
  v4 = v3;
  if ( !v3 )
    v4 = pSceneObj->mpConstProperties;
  if ( v4 )
  {
    if ( !v3 )
      v3 = pSceneObj->mpConstProperties;
    v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           v3,
           (UFG::qSymbol *)&component_PhysicsMover::sPropertyName.mUID,
           DEPTH_RECURSE);
    if ( v5 && (v6 = (UFG::qVector3 *)UFG::qPropertySet::GetMemImagePtr(v5)) != 0i64 )
    {
      UFG::AIOutlineComponent::SetLocalAABB(v2, v6 + 3, v6 + 4, eOutlineDimensionsDefinedBy_PropertySet);
    }
    else
    {
      v7 = UFG::qPropertySet::Get<UFG::qVector3>(
             v4,
             (UFG::qSymbol *)&qSymbol_AIOutlineBoundingBoxMin.mUID,
             DEPTH_RECURSE);
      v8 = UFG::qPropertySet::Get<UFG::qVector3>(
             v4,
             (UFG::qSymbol *)&qSymbol_AIOutlineBoundingBoxMax.mUID,
             DEPTH_RECURSE);
      if ( v7 )
      {
        if ( v8 )
          UFG::AIOutlineComponent::SetLocalAABB(v2, v7, v8, eOutlineDimensionsDefinedBy_PropertySet);
      }
    }
  }
}

// File Line: 190
// RVA: 0x365810
void __fastcall UFG::AIOutlineComponent::Init(UFG::AIOutlineComponent *this)
{
  UFG::SimObjectGame *v1; // rdi
  UFG::AIOutlineComponent *v2; // rbx
  UFG::TransformNodeComponent *v3; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  unsigned __int16 v8; // cx
  UFG::RigidBodyComponent *v9; // rax
  UFG::SimComponent *v10; // rax
  UFG::RegionComponent *v11; // rcx
  char v12; // al
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  char v20; // al
  UFG::RigidBody *v21; // rcx
  UFG::qVector4 *v22; // rdi
  UFG::qVector4 v23; // xmm2
  UFG::qVector4 v24; // xmm1
  UFG::qVector4 v25; // xmm0
  UFG::qBox pBox; // [rsp+20h] [rbp-78h]
  UFG::qMatrix44 mat; // [rsp+40h] [rbp-58h]

  v1 = (UFG::SimObjectGame *)this->m_pSimObject;
  v2 = this;
  if ( v1 )
    v3 = v1->m_pTransformNodeComponent;
  else
    v3 = 0i64;
  v4 = &this->m_pTransformNodeComponent;
  if ( this->m_pTransformNodeComponent.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v4->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  v4->m_pPointer = (UFG::SimComponent *)&v3->vfptr;
  if ( v3 )
  {
    v7 = v3->m_SafePointerList.mNode.mPrev;
    v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v4->mPrev = v7;
    v4->mNext = &v3->m_SafePointerList.mNode;
    v3->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  }
  if ( !v2->m_pRigidBodyComponent.m_pPointer )
  {
    if ( !v1 )
      goto LABEL_27;
    v8 = v1->m_Flags;
    if ( (v8 >> 14) & 1 )
    {
      v9 = (UFG::RigidBodyComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v8 & 0x8000u) == 0 )
    {
      if ( (v8 >> 13) & 1 )
      {
        v9 = (UFG::RigidBodyComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RigidBodyComponent::_TypeUID);
      }
      else if ( (v8 >> 12) & 1 )
      {
        v9 = (UFG::RigidBodyComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RigidBodyComponent::_TypeUID);
      }
      else
      {
        v9 = (UFG::RigidBodyComponent *)UFG::SimObject::GetComponentOfType(
                                          (UFG::SimObject *)&v1->vfptr,
                                          UFG::RigidBodyComponent::_TypeUID);
      }
    }
    else
    {
      v9 = (UFG::RigidBodyComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RigidBodyComponent::_TypeUID);
    }
    if ( v9 )
      UFG::AIOutlineComponent::SetLocalAABB(v2, v9);
  }
  if ( v1 )
  {
    v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::AIOutlineRegion::_TypeUID);
    if ( v10 )
    {
      v11 = (UFG::RegionComponent *)v10[2].vfptr;
      *(_QWORD *)&pBox.mMin.x = 0i64;
      *(_QWORD *)&pBox.mMin.z = 0i64;
      *(_QWORD *)&pBox.mMax.y = 0i64;
      UFG::RegionComponent::GetLocalBoundingBox(v11, &pBox);
      v12 = v2->mDimensionsDefinedBy;
      if ( (unsigned __int8)v12 > 4u )
      {
        v2->mDimensionsDefinedBy = v12 | 4;
      }
      else
      {
        v13 = pBox.mMax.y;
        v14 = pBox.mMax.x;
        v15 = pBox.mMin.y;
        v2->mDimensionsDefinedBy = v12 | 4;
        v16 = pBox.mMin.x;
        v17 = pBox.mMax.z;
        v18 = v14 - pBox.mMin.x;
        v2->mWidth = v13 - v15;
        v19 = pBox.mMin.z;
        v2->mLength = v18;
        v2->mHeight = v17 - v19;
        v2->mOffset.x = (float)(v16 + v14) * 0.5;
        v2->mOffset.z = (float)(v19 + v17) * 0.5;
        v2->mOffset.y = (float)(v15 + v13) * 0.5;
        v2->mOffset.z = v2->mOffset.z - (float)(v2->mHeight * 0.5);
      }
      v2->mSizeInitialized = 1;
    }
  }
LABEL_27:
  v20 = v2->mDimensionsDefinedBy;
  if ( !v20 )
    return;
  v21 = (UFG::RigidBody *)v2->m_pRigidBodyComponent.m_pPointer;
  if ( v21 && v20 & 1 && (unsigned __int8)v20 < 2u )
  {
    UFG::RigidBody::GetTransform(v21, &mat);
  }
  else
  {
    v22 = (UFG::qVector4 *)v2->m_pTransformNodeComponent.m_pPointer;
    if ( !v22 )
      return;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v2->m_pTransformNodeComponent.m_pPointer);
    v23 = v22[10];
    v24 = v22[11];
    v25 = v22[8];
    mat.v1 = v22[9];
    mat.v2 = v23;
    mat.v0 = v25;
    mat.v3 = v24;
  }
  v2->mQueueAddToWorld = 1;
}

// File Line: 228
// RVA: 0x358470
void __fastcall UFG::AIOutlineComponent::ForceUpdate(UFG::AIOutlineComponent *this, UFG::Event *this_event)
{
  UFG::AIOutlineComponent *v2; // rbx
  bool v3; // cf

  v2 = this;
  if ( this->mQueueAddToWorld )
  {
    v3 = this->mAddedToWorld < 1u;
    this->mQueueAddToWorld = 0;
    if ( !v3 )
    {
      UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline(UFG::NavManager::ms_pInstance, this->mpDynamicOutline);
      v2->mpDynamicOutline = 0i64;
      *(_WORD *)&v2->mQueueAddToWorld = 0;
    }
    v2->mStationaryTimer = 0.0;
    v2->mQueueAddToWorld = 1;
  }
}

// File Line: 242
// RVA: 0x387350
void __fastcall UFG::AIOutlineComponent::SetLocalAABB(UFG::AIOutlineComponent *this, UFG::RigidBodyComponent *pRigidBodyComp)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v2; // r9
  UFG::RigidBodyComponent *v3; // rbx
  UFG::AIOutlineComponent *v4; // rdi
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::SimObject *v8; // rsi
  UFG::TransformNodeComponent *v9; // rsi
  float v10; // xmm0_4
  float v11; // xmm7_4
  float v12; // xmm6_4
  char v13; // al
  float v14; // xmm3_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm1_4
  float v18; // xmm4_4
  float v19; // xmm6_4
  UFG::qVector3 aabbMax; // [rsp+20h] [rbp-60h]
  UFG::qVector3 aabbMin; // [rsp+30h] [rbp-50h]
  UFG::qVector3 v22; // [rsp+40h] [rbp-40h]
  UFG::qVector3 v23; // [rsp+50h] [rbp-30h]

  v2 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pRigidBodyComponent.mPrev;
  v3 = pRigidBodyComp;
  v4 = this;
  if ( this->m_pRigidBodyComponent.m_pPointer )
  {
    v5 = v2->mPrev;
    v6 = this->m_pRigidBodyComponent.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v2->mPrev = v2;
    this->m_pRigidBodyComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&this->m_pRigidBodyComponent.mPrev;
  }
  this->m_pRigidBodyComponent.m_pPointer = (UFG::SimComponent *)&pRigidBodyComp->vfptr;
  if ( pRigidBodyComp )
  {
    v7 = pRigidBodyComp->m_SafePointerList.mNode.mPrev;
    v7->mNext = v2;
    v2->mPrev = v7;
    this->m_pRigidBodyComponent.mNext = &pRigidBodyComp->m_SafePointerList.mNode;
    pRigidBodyComp->m_SafePointerList.mNode.mPrev = v2;
  }
  aabbMin.x = -1.0;
  aabbMin.y = -1.0;
  aabbMin.z = -1.0;
  aabbMax.x = 1.0;
  aabbMax.y = 1.0;
  aabbMax.z = 1.0;
  if ( UFG::RigidBody::GetAabb((UFG::RigidBody *)&pRigidBodyComp->vfptr, &aabbMin, &aabbMax, LOCAL_AABB) )
  {
    v8 = v3->m_pSimObject;
    if ( v8 && (v9 = v8->m_pTransformNodeComponent) != 0i64 )
    {
      UFG::TransformNodeComponent::UpdateWorldTransform(v9);
      v22.x = -1.0;
      v22.y = -1.0;
      v22.z = -1.0;
      v23.x = 1.0;
      v23.y = 1.0;
      v23.z = 1.0;
      UFG::RigidBody::GetAabb((UFG::RigidBody *)&v3->vfptr, &v22, &v23, WORLD_AABB);
      v10 = v22.z - v9->mWorldTransform.v3.z;
      v11 = aabbMin.z - v10;
      v12 = aabbMax.z - v10;
    }
    else
    {
      v11 = aabbMin.z;
      v12 = aabbMax.z;
    }
    v13 = v4->mDimensionsDefinedBy;
    if ( (unsigned __int8)v13 > 1u )
    {
      v4->mDimensionsDefinedBy = v13 | 1;
    }
    else
    {
      v14 = aabbMax.x;
      v15 = aabbMin.x;
      v16 = aabbMax.y;
      v4->mDimensionsDefinedBy = v13 | 1;
      v17 = v16 - aabbMin.y;
      v18 = v16 + aabbMin.y;
      v4->mLength = v14 - v15;
      v4->mWidth = v17;
      v4->mHeight = v12 - v11;
      v19 = (float)(v12 + v11) * 0.5;
      v4->mOffset.x = (float)(v15 + v14) * 0.5;
      v4->mOffset.y = v18 * 0.5;
      v4->mOffset.z = v19;
      v4->mOffset.z = v19 - (float)(v4->mHeight * 0.5);
    }
    v4->mSizeInitialized = 1;
  }
}

// File Line: 270
// RVA: 0x387270
void __fastcall UFG::AIOutlineComponent::SetLocalAABB(UFG::AIOutlineComponent *this, UFG::qVector3 *min, UFG::qVector3 *max, UFG::eOutlineDimensionsDefinedBy eDefinedBy)
{
  UFG::eOutlineDimensionsDefinedBy v4; // eax
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm1_4

  v4 = (unsigned __int8)this->mDimensionsDefinedBy;
  if ( v4 > eDefinedBy )
  {
    this->mSizeInitialized = 1;
    this->mDimensionsDefinedBy = eDefinedBy | v4;
  }
  else
  {
    this->mDimensionsDefinedBy = eDefinedBy | v4;
    this->mLength = max->x - min->x;
    this->mWidth = max->y - min->y;
    this->mHeight = max->z - min->z;
    v5 = min->y + max->y;
    v6 = (float)(min->x + max->x) * 0.5;
    this->mOffset.z = (float)(min->z + max->z) * 0.5;
    this->mOffset.x = v6;
    this->mOffset.y = v5 * 0.5;
    v7 = this->mHeight;
    this->mSizeInitialized = 1;
    this->mOffset.z = this->mOffset.z - (float)(v7 * 0.5);
  }
}

// File Line: 289
// RVA: 0x360BA0
void __fastcall UFG::AIOutlineComponent::GetLocalAABB(UFG::AIOutlineComponent *this, UFG::qVector3 *min, UFG::qVector3 *max)
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
  UFG::AIOutlineComponent *v2; // rbx
  UFG::SimObject *v3; // rcx
  UFG::SimComponentHolder *v4; // rax
  UFG::SimComponent *v5; // rdi
  float v6; // xmm6_4

  v2 = this;
  v3 = this->m_pSimObject;
  if ( (v3->m_Flags & 0x8000u) != 0 )
  {
    v4 = v3->m_Components.p;
    v5 = v4[34].m_pComponent;
    if ( v5 )
    {
      if ( ((signed int)UFG::PhysicsMoverInterface::GetLOD((UFG::PhysicsMoverInterface *)v4[34].m_pComponent) >= 2
         || (_QWORD)v5[14].vfptr & 1)
        && UFG::PhysicsMoverInterface::GetLinearVelocityMagnitudeKPH((UFG::PhysicsMoverInterface *)v5) < 2.0 )
      {
        v6 = delta_time + v2->mStationaryTimer;
        v2->mStationaryTimer = v6;
        if ( v6 > 0.5 )
        {
          v2->mQueueAddToWorld = 1;
          goto LABEL_10;
        }
      }
      else
      {
        v2->mStationaryTimer = 0.0;
      }
    }
    UFG::AIOutlineComponent::DeactivateOutline(v2);
  }
LABEL_10:
  if ( v2->mQueueAddToWorld )
  {
    if ( !v2->mAddedToWorld )
      UFG::AIOutlineComponent::ActivateOutline(v2);
  }
}

// File Line: 383
// RVA: 0x351980
void __fastcall UFG::AIOutlineComponent::DeactivateOutline(UFG::AIOutlineComponent *this)
{
  UFG::AIOutlineComponent *v1; // rbx
  bool v2; // zf

  v1 = this;
  if ( !this->mQueueAddToWorld || (v2 = this->mAddedToWorld == 0, this->mQueueAddToWorld = 0, !v2) )
  {
    if ( this->mAddedToWorld )
    {
      UFG::NavManager::ms_pInstance->vfptr->RemoveDynamicOutline(UFG::NavManager::ms_pInstance, this->mpDynamicOutline);
      v1->mpDynamicOutline = 0i64;
      *(_WORD *)&v1->mQueueAddToWorld = 0;
    }
  }
}

// File Line: 412
// RVA: 0x33F950
void __fastcall UFG::AIOutlineComponent::ActivateOutline(UFG::AIOutlineComponent *this)
{
  UFG::AIOutlineComponent *v1; // rbx
  float v2; // xmm5_4
  float v3; // xmm4_4
  int v4; // ST28_4
  float v5; // [rsp+38h] [rbp-80h]
  float v6; // [rsp+3Ch] [rbp-7Ch]
  float v7; // [rsp+40h] [rbp-78h]
  float v8; // [rsp+48h] [rbp-70h]
  float v9; // [rsp+4Ch] [rbp-6Ch]
  float v10; // [rsp+50h] [rbp-68h]
  __int128 v11; // [rsp+58h] [rbp-60h]
  UFG::qMatrix44 transform; // [rsp+70h] [rbp-48h]

  v1 = this;
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
          v2 = v1->mLength;
          v8 = v1->mOffset.x - (float)(v1->mLength * 0.5);
          v3 = v1->mWidth;
          v9 = v1->mOffset.y - (float)(v1->mWidth * 0.5);
          v10 = v1->mOffset.z;
          v5 = v2 + v8;
          v6 = v3 + v9;
          v7 = v10 + v1->mHeight;
          v11 = 0ui64;
          v4 = 0;
          v1->mpDynamicOutline = (UFG::NavDynamicOutline *)((__int64 (__fastcall *)(UFG::NavManager *, UFG::qMatrix44 *, float *, float *, _QWORD, int, signed __int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))UFG::NavManager::ms_pInstance->vfptr->AddDynamicOutline)(
                                                             UFG::NavManager::ms_pInstance,
                                                             &transform,
                                                             &v8,
                                                             &v5,
                                                             0i64,
                                                             v4,
                                                             -2i64,
                                                             *(_QWORD *)&v5,
                                                             *(_QWORD *)&v7,
                                                             *(_QWORD *)&v8,
                                                             *(_QWORD *)&v10,
                                                             0i64,
                                                             0i64);
          v1->mAddedToWorld = 1;
        }
      }
      else
      {
        UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
        UFG::qPrintChannel::Print(
          &UFG::gPrintChannel_HK_AIHavok,
          OUTPUT_LEVEL_ERROR,
          "[AIHavok] Error! (0x%x) (%s) Does not have dimensions set!\n");
        v1->mQueueAddToWorld = 0;
      }
    }
  }
  else
  {
    this->mQueueAddToWorld = 1;
  }
}

