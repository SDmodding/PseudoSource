// File Line: 11
// RVA: 0x67B4B0
const char *__fastcall UFG::VehicleOwnershipComponent::GetTypeName(UFG::VehicleOwnershipComponent *this)
{
  return "VehicleOwnershipComponent";
}

// File Line: 15
// RVA: 0x66B8A0
void __fastcall UFG::VehicleOwnershipComponent::VehicleOwnershipComponent(UFG::VehicleOwnershipComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::VehicleOwnershipComponent *v2; // rbx
  unsigned int v3; // eax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v4; // [rsp+50h] [rbp+18h]

  v2 = this;
  v3 = UFG::qStringHash32("VehicleOwnershipComponent", 0xFFFFFFFF);
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&v2->vfptr, v3);
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleOwnershipComponent::`vftable';
  v4 = &v2->m_PriorityLockComponent;
  v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
  v2->m_PriorityLockComponent.m_pPointer = 0i64;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::VehicleOwnershipComponent::_VehicleOwnershipComponentTypeUID,
    "VehicleOwnershipComponent");
}

// File Line: 21
// RVA: 0x67D0C0
bool __fastcall UFG::VehicleOwnershipComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qSymbol *)&SimSymX_propset_componentVehicleOwnership.mUID);
}

// File Line: 27
// RVA: 0x687CE0
UFG::SimComponent *__fastcall UFG::VehicleOwnershipComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rdi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x58ui64, "VehicleOwnershipComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::VehicleOwnershipComponent::VehicleOwnershipComponent((UFG::VehicleOwnershipComponent *)v3, v1);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return v5;
}

// File Line: 34
// RVA: 0x68CB30
void __fastcall UFG::VehicleOwnershipComponent::TakeOwnsership(UFG::VehicleOwnershipComponent *this, UFG::SimObject *newlyOwnedVehicle)
{
  UFG::SimObject *v2; // rdi
  UFG::VehicleOwnershipComponent *v3; // rbx
  UFG::SimComponent *v4; // rax
  UFG::qMemoryPool *v5; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v9; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObject *v13; // rdx
  UFG::SimComponent *v14; // rdx
  UFG::SimObjectModifier v15; // [rsp+38h] [rbp-50h]
  UFG::SimObjectModifier v16; // [rsp+58h] [rbp-30h]

  v2 = newlyOwnedVehicle;
  v3 = this;
  v4 = this->m_PriorityLockComponent.m_pPointer;
  if ( v4 )
  {
    v13 = v4->m_pSimObject;
    if ( v13 )
    {
      UFG::SimObjectModifier::SimObjectModifier(&v15, v13, 1);
      v14 = v3->m_PriorityLockComponent.m_pPointer;
      ArrayOfTuplesImplementation::clear((ArrayOfTuplesImplementation *)&v15);
      UFG::SimObjectModifier::Close(&v15);
      UFG::SimObjectModifier::~SimObjectModifier(&v15);
    }
  }
  else
  {
    v5 = UFG::GetSimulationMemoryPool();
    v6 = UFG::qMemoryPool::Allocate(v5, 0x40ui64, "ResourcePriorityLockComponent", 0i64, 1u);
    if ( v6 )
    {
      UFG::ResourcePriorityLockComponent::ResourcePriorityLockComponent((UFG::ResourcePriorityLockComponent *)v6);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    v9 = &v3->m_PriorityLockComponent;
    if ( v3->m_PriorityLockComponent.m_pPointer )
    {
      v10 = v9->mPrev;
      v11 = v3->m_PriorityLockComponent.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v3->m_PriorityLockComponent.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->m_PriorityLockComponent.mPrev;
    }
    v3->m_PriorityLockComponent.m_pPointer = v8;
    if ( v8 )
    {
      v12 = v8->m_SafePointerList.mNode.mPrev;
      v12->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
      v9->mPrev = v12;
      v3->m_PriorityLockComponent.mNext = &v8->m_SafePointerList.mNode;
      v8->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v9->mPrev;
    }
  }
  UFG::SimObjectModifier::SimObjectModifier(&v16, v2, 1);
  UFG::SimObjectModifier::AttachComponent(&v16, v3->m_PriorityLockComponent.m_pPointer, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v16);
  UFG::SimObjectModifier::~SimObjectModifier(&v16);
}

// File Line: 58
// RVA: 0x67AF30
UFG::SimObject *__fastcall UFG::VehicleOwnershipComponent::GetOwnedVehicle(UFG::VehicleOwnershipComponent *this)
{
  UFG::SimObject *result; // rax

  result = (UFG::SimObject *)this->m_PriorityLockComponent.m_pPointer;
  if ( result )
    result = (UFG::SimObject *)result->mNode.mParent;
  return result;
}

