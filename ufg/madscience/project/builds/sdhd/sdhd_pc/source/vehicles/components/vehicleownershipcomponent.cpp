// File Line: 11
// RVA: 0x67B4B0
const char *__fastcall UFG::VehicleOwnershipComponent::GetTypeName(UFG::VehicleOwnershipComponent *this)
{
  return "VehicleOwnershipComponent";
}

// File Line: 15
// RVA: 0x66B8A0
void __fastcall UFG::VehicleOwnershipComponent::VehicleOwnershipComponent(
        UFG::VehicleOwnershipComponent *this,
        UFG::SceneObjectProperties *pSceneObj)
{
  unsigned int v3; // eax

  v3 = UFG::qStringHash32("VehicleOwnershipComponent", 0xFFFFFFFF);
  UFG::SimComponent::SimComponent(this, v3);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::VehicleOwnershipComponent::`vftable;
  this->m_PriorityLockComponent.mPrev = &this->m_PriorityLockComponent;
  this->m_PriorityLockComponent.mNext = &this->m_PriorityLockComponent;
  this->m_PriorityLockComponent.m_pPointer = 0i64;
  UFG::SimComponent::AddType(
    this,
    UFG::VehicleOwnershipComponent::_VehicleOwnershipComponentTypeUID,
    "VehicleOwnershipComponent");
}

// File Line: 21
// RVA: 0x67D0C0
bool __fastcall UFG::VehicleOwnershipComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  return PropertyUtils::HasComponentPropertySet(
           pSceneObj,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentVehicleOwnership);
}

// File Line: 27
// RVA: 0x687CE0
UFG::VehicleOwnershipComponent *__fastcall UFG::VehicleOwnershipComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x58ui64, "VehicleOwnershipComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::VehicleOwnershipComponent::VehicleOwnershipComponent((UFG::VehicleOwnershipComponent *)v3, pSceneObj);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v7, pSceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v7, v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v7);
  UFG::SimObjectModifier::~SimObjectModifier(&v7);
  return (UFG::VehicleOwnershipComponent *)v5;
}

// File Line: 34
// RVA: 0x68CB30
void __fastcall UFG::VehicleOwnershipComponent::TakeOwnsership(
        UFG::VehicleOwnershipComponent *this,
        UFG::SimObject *newlyOwnedVehicle)
{
  UFG::SimComponent *m_pPointer; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // r8
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_m_PriorityLockComponent; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::SimObject *m_pSimObject; // rdx
  UFG::SimObjectModifier v14; // [rsp+38h] [rbp-50h] BYREF
  UFG::SimObjectModifier v15; // [rsp+58h] [rbp-30h] BYREF

  m_pPointer = this->m_PriorityLockComponent.m_pPointer;
  if ( m_pPointer )
  {
    m_pSimObject = m_pPointer->m_pSimObject;
    if ( m_pSimObject )
    {
      UFG::SimObjectModifier::SimObjectModifier(&v14, m_pSimObject, 1);
      ArrayOfTuplesImplementation::clear((ArrayOfTuplesImplementation *)&v14);
      UFG::SimObjectModifier::Close(&v14);
      UFG::SimObjectModifier::~SimObjectModifier(&v14);
    }
  }
  else
  {
    SimulationMemoryPool = UFG::GetSimulationMemoryPool();
    v6 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x40ui64, "ResourcePriorityLockComponent", 0i64, 1u);
    if ( v6 )
    {
      UFG::ResourcePriorityLockComponent::ResourcePriorityLockComponent((UFG::ResourcePriorityLockComponent *)v6);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
    p_m_PriorityLockComponent = &this->m_PriorityLockComponent;
    if ( this->m_PriorityLockComponent.m_pPointer )
    {
      mPrev = p_m_PriorityLockComponent->mPrev;
      mNext = this->m_PriorityLockComponent.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_m_PriorityLockComponent->mPrev = p_m_PriorityLockComponent;
      this->m_PriorityLockComponent.mNext = &this->m_PriorityLockComponent;
    }
    this->m_PriorityLockComponent.m_pPointer = v8;
    if ( v8 )
    {
      v12 = v8->m_SafePointerList.mNode.mPrev;
      v12->mNext = p_m_PriorityLockComponent;
      p_m_PriorityLockComponent->mPrev = v12;
      this->m_PriorityLockComponent.mNext = &v8->m_SafePointerList.mNode;
      v8->m_SafePointerList.mNode.mPrev = p_m_PriorityLockComponent;
    }
  }
  UFG::SimObjectModifier::SimObjectModifier(&v15, newlyOwnedVehicle, 1);
  UFG::SimObjectModifier::AttachComponent(&v15, this->m_PriorityLockComponent.m_pPointer, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v15);
  UFG::SimObjectModifier::~SimObjectModifier(&v15);
}

// File Line: 58
// RVA: 0x67AF30
UFG::qBaseNodeRB *__fastcall UFG::VehicleOwnershipComponent::GetOwnedVehicle(UFG::VehicleOwnershipComponent *this)
{
  UFG::qBaseNodeRB *result; // rax

  result = (UFG::qBaseNodeRB *)this->m_PriorityLockComponent.m_pPointer;
  if ( result )
    return result[1].mChild[0];
  return result;
}

