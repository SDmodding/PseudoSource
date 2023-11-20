// File Line: 30
// RVA: 0x1544040
__int64 dynamic_initializer_for__UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentList__);
}

// File Line: 31
// RVA: 0x52CB00
UFG::ComponentIDDesc *__fastcall UFG::SimObjectSignalMemoryComponent::GetDesc(UFG::SimObjectSignalMemoryComponent *this)
{
  return &UFG::SimObjectSignalMemoryComponent::_TypeIDesc;
}

// File Line: 38
// RVA: 0x518C40
void __fastcall UFG::SimObjectSignalMemoryComponent::SimObjectSignalMemoryComponent(UFG::SimObjectSignalMemoryComponent *this, unsigned int name_uid, UFG::qPropertySet *properties, component_CharacterProperties *dataPtr)
{
  UFG::SimObjectSignalMemoryComponent *v4; // rbx
  UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *v5; // rdx
  UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *v6; // rax

  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, name_uid);
  v4->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  v5 = (UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectSignalMemoryComponent::`vftable{for `UFG::SimComponent};
  v4->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::SimObjectSignalMemoryComponent::`vftable{for `UFG::UpdateInterface};
  v6 = UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentList.mNode.mPrev;
  UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *)&UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentList;
  UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentList.mNode.mPrev = (UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::SimObjectSignalMemoryComponent::_SimObjectSignalMemoryComponentTypeUID,
    "SimObjectSignalMemoryComponent");
  *(_QWORD *)&v4->mUserSignal0 = 0i64;
  v4->mStruggle = 0.0;
  v4->mDebugFloatInputSignals = 0;
}

// File Line: 70
// RVA: 0x51C7D0
void __fastcall UFG::SimObjectSignalMemoryComponent::~SimObjectSignalMemoryComponent(UFG::SimObjectSignalMemoryComponent *this)
{
  UFG::SimObjectSignalMemoryComponent *v1; // r8
  UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *v2; // rdx
  UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *v3; // rcx
  UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *v4; // rax
  UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *v5; // rcx
  UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectSignalMemoryComponent::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::SimObjectSignalMemoryComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentpCurrentIterator )
    UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentpCurrentIterator = (UFG::SimObjectSignalMemoryComponent *)&this->mPrev[-5].mNext;
  v2 = (UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *)&this->mPrev;
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

// File Line: 78
// RVA: 0x546D30
UFG::SimComponent *__fastcall UFG::SimObjectSignalMemoryComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *pSceneObj, bool required)
{
  bool v2; // bp
  UFG::SceneObjectProperties *v3; // rbx
  UFG::qPropertySet *v4; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *v7; // rdi
  UFG::qMemoryPool *v9; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qPropertySet *v11; // r8
  UFG::SimComponent *v12; // rax
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h]

  v2 = required;
  v3 = pSceneObj;
  v4 = pSceneObj->mpWritableProperties;
  if ( !v4 )
    v4 = v3->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v4,
         (UFG::qSymbol *)&component_CharacterProperties::sPropertyName.mUID,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    v7 = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( v7 )
      goto LABEL_9;
  }
  else
  {
    v7 = 0i64;
  }
  if ( !v2 )
    return 0i64;
LABEL_9:
  v9 = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(v9, 0x70ui64, "SimObjectSignalMemoryComponent", 0i64, 1u);
  if ( v10 )
  {
    v11 = v3->mpWritableProperties;
    if ( !v11 )
      v11 = v3->mpConstProperties;
    UFG::SimObjectSignalMemoryComponent::SimObjectSignalMemoryComponent(
      (UFG::SimObjectSignalMemoryComponent *)v10,
      v3->m_NameUID,
      v11,
      (component_CharacterProperties *)v7);
    v6 = v12;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v13, v3->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v13, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v13);
  UFG::SimObjectModifier::~SimObjectModifier(&v13);
  return v6;
}

