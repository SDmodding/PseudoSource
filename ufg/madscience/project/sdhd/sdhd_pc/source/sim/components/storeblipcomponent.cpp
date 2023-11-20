// File Line: 16
// RVA: 0x15440A0
__int64 dynamic_initializer_for__UFG::StoreBlipComponent::s_StoreBlipComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::StoreBlipComponent::s_StoreBlipComponentList__);
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
  UFG::StoreBlipComponent *v2; // rbx
  UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *v3; // rdx
  UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *v4; // rax

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v3 = (UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StoreBlipComponent::`vftable;
  v4 = UFG::StoreBlipComponent::s_StoreBlipComponentList.mNode.mPrev;
  UFG::StoreBlipComponent::s_StoreBlipComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *)&v2->mPrev;
  v3->mPrev = v4;
  v2->mNext = (UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *)&UFG::StoreBlipComponent::s_StoreBlipComponentList;
  UFG::StoreBlipComponent::s_StoreBlipComponentList.mNode.mPrev = (UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::StoreBlipComponent::_StoreBlipComponentTypeUID,
    "StoreBlipComponent");
}

// File Line: 29
// RVA: 0x51CAE0
void __fastcall UFG::StoreBlipComponent::~StoreBlipComponent(UFG::StoreBlipComponent *this)
{
  UFG::StoreBlipComponent *v1; // r8
  UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *v2; // rdx
  UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *v3; // rcx
  UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *v4; // rax
  UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *v5; // rcx
  UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StoreBlipComponent::`vftable;
  if ( this == UFG::StoreBlipComponent::s_StoreBlipComponentpCurrentIterator )
    UFG::StoreBlipComponent::s_StoreBlipComponentpCurrentIterator = (UFG::StoreBlipComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::StoreBlipComponent,UFG::StoreBlipComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 33
// RVA: 0x154CAD0
__int64 UFG::_dynamic_initializer_for__storeBlipName__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("StoreBlipName", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::storeBlipName, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__storeBlipName__);
}

// File Line: 37
// RVA: 0x53E910
void __fastcall UFG::StoreBlipComponent::OnAttach(UFG::StoreBlipComponent *this, UFG::SimObject *pObject)
{
  UFG::SimObject *v2; // rax
  UFG::StoreBlipComponent *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  char *v5; // rax
  UFG::SimObject *v6; // rcx

  v2 = this->m_pSimObject;
  v3 = this;
  if ( v2 )
    v2 = (UFG::SimObject *)v2->m_pSceneObj;
  v4 = (UFG::qPropertySet *)v2[1].m_SafePointerList.mNode.mNext;
  if ( !v4 )
    v4 = (UFG::qPropertySet *)v2[1].m_SafePointerWithCallbackList.mNode.mPrev;
  v5 = UFG::qPropertySet::Get<char const *>(v4, (UFG::qSymbol *)&UFG::storeBlipName.mUID, DEPTH_RECURSE);
  v6 = v3->m_pSimObject;
  if ( v6 )
    UFG::SimObjectUtility::AttachHudSymbol(v6, v5, 0, 0.0, &customWorldMapCaption);
}

// File Line: 50
// RVA: 0x540BF0
void __fastcall UFG::StoreBlipComponent::OnDetach(UFG::StoreBlipComponent *this)
{
  JUMPOUT(this->m_pSimObject, 0i64, UFG::SimObjectUtility::DetachHudSymbol);
}

// File Line: 60
// RVA: 0x5357A0
bool __fastcall UFG::StoreBlipComponent::HasComponent(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rax
  UFG::qPropertySet *v2; // rcx

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  return UFG::qPropertySet::GetParentFromName(
           v2,
           (UFG::qSymbol *)&SimSymX_propset_componentStoreBlip.mUID,
           DEPTH_RECURSE) != 0i64;
}

// File Line: 66
// RVA: 0x545540
UFG::SimComponent *__fastcall UFG::StoreBlipComponent::PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rdi
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  UFG::SimComponent *v4; // rax
  UFG::SimComponent *v5; // rbx
  UFG::SimObjectModifier v7; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0x50ui64, "StoreBlipComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::StoreBlipComponent::StoreBlipComponent((UFG::StoreBlipComponent *)v3, v1->m_NameUID);
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

