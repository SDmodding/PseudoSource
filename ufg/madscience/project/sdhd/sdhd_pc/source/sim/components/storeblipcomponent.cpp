// File Line: 16
// RVA: 0x15440A0
__int64 dynamic_initializer_for__UFG::StoreBlipComponent::s_StoreBlipComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StoreBlipComponent::s_StoreBlipComponentList__);
}

// File Line: 17
// RVA: 0x52CB30
UFG::ComponentIDDesc *__fastcall UFG::StoreBlipComponent::GetDesc(UFG::StoreBlipComponent *this)
{
  return &UFG::StoreBlipComponent::_TypeIDesc;
}

// File Line: 21
// RVA: 0x519690
void __fastcall UFG::StoreBlipComponent::StoreBlipComponent(UFG::StoreBlipComponent *this, unsigned int name_uid)
{
  UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->mPrev = &this->UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent>;
  this->mNext = &this->UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StoreBlipComponent::`vftable;
  mPrev = UFG::StoreBlipComponent::s_StoreBlipComponentList.mNode.mPrev;
  UFG::StoreBlipComponent::s_StoreBlipComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *)&UFG::StoreBlipComponent::s_StoreBlipComponentList;
  UFG::StoreBlipComponent::s_StoreBlipComponentList.mNode.mPrev = &this->UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent>;
  UFG::SimComponent::AddType(this, UFG::StoreBlipComponent::_StoreBlipComponentTypeUID, "StoreBlipComponent");
}

// File Line: 29
// RVA: 0x51CAE0
void __fastcall UFG::StoreBlipComponent::~StoreBlipComponent(UFG::StoreBlipComponent *this)
{
  UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *v2; // rdx
  UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *mPrev; // rcx
  UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *mNext; // rax
  UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *v5; // rcx
  UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StoreBlipComponent::`vftable;
  if ( this == UFG::StoreBlipComponent::s_StoreBlipComponentpCurrentIterator )
    UFG::StoreBlipComponent::s_StoreBlipComponentpCurrentIterator = (UFG::StoreBlipComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 33
// RVA: 0x154CAD0
__int64 UFG::_dynamic_initializer_for__storeBlipName__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("StoreBlipName", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::storeBlipName, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__storeBlipName__);
}

// File Line: 37
// RVA: 0x53E910
void __fastcall UFG::StoreBlipComponent::OnAttach(UFG::StoreBlipComponent *this, UFG::SimObject *pObject)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::qPropertySet *mNext; // rcx
  char *v5; // rax
  UFG::SimObject *v6; // rcx

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pSimObject = (UFG::SimObject *)m_pSimObject->m_pSceneObj;
  mNext = (UFG::qPropertySet *)m_pSimObject[1].m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mNext;
  if ( !mNext )
    mNext = (UFG::qPropertySet *)m_pSimObject[1].m_SafePointerWithCallbackList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::mNode.mPrev;
  v5 = UFG::qPropertySet::Get<char const *>(mNext, (UFG::qArray<unsigned long,0> *)&UFG::storeBlipName, DEPTH_RECURSE);
  v6 = this->m_pSimObject;
  if ( v6 )
    UFG::SimObjectUtility::AttachHudSymbol(v6, v5, 0, 0.0, &customCaption);
}

// File Line: 50
// RVA: 0x540BF0
void __fastcall UFG::StoreBlipComponent::OnDetach(UFG::StoreBlipComponent *this)
{
  UFG::SimObject *m_pSimObject; // rcx

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    UFG::SimObjectUtility::DetachHudSymbol(m_pSimObject);
}

// File Line: 60
// RVA: 0x5357A0
bool __fastcall UFG::StoreBlipComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&SimSymX_propset_componentStoreBlip,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 66
// RVA: 0x545540
UFG::StoreBlipComponent *__fastcall UFG::StoreBlipComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x50ui64, "StoreBlipComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::StoreBlipComponent::StoreBlipComponent((UFG::StoreBlipComponent *)v3, pSceneObj->m_NameUID);
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
  return (UFG::StoreBlipComponent *)v5;
}

