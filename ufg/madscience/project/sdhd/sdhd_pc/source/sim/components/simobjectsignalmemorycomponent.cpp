// File Line: 30
// RVA: 0x1544040
__int64 dynamic_initializer_for__UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentList__);
}

// File Line: 31
// RVA: 0x52CB00
UFG::ComponentIDDesc *__fastcall UFG::SimObjectSignalMemoryComponent::GetDesc(
        UFG::SimObjectSignalMemoryComponent *this)
{
  return &UFG::SimObjectSignalMemoryComponent::_TypeIDesc;
}

// File Line: 38
// RVA: 0x518C40
void __fastcall UFG::SimObjectSignalMemoryComponent::SimObjectSignalMemoryComponent(
        UFG::SimObjectSignalMemoryComponent *this,
        unsigned int name_uid,
        UFG::qPropertySet *properties,
        component_CharacterProperties *dataPtr)
{
  UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, name_uid);
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::UpdateInterface::`vftable;
  this->mPrev = &this->UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent>;
  this->mNext = &this->UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectSignalMemoryComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::SimObjectSignalMemoryComponent::`vftable{for `UFG::UpdateInterface};
  mPrev = UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentList.mNode.mPrev;
  UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *)&UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentList;
  UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentList.mNode.mPrev = &this->UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::SimObjectSignalMemoryComponent::_SimObjectSignalMemoryComponentTypeUID,
    "SimObjectSignalMemoryComponent");
  *(_QWORD *)&this->mUserSignal0 = 0i64;
  this->mStruggle = 0.0;
  this->mDebugFloatInputSignals = 0;
}

// File Line: 70
// RVA: 0x51C7D0
void __fastcall UFG::SimObjectSignalMemoryComponent::~SimObjectSignalMemoryComponent(
        UFG::SimObjectSignalMemoryComponent *this)
{
  UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *v2; // rdx
  UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *mPrev; // rcx
  UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *mNext; // rax
  UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *v5; // rcx
  UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent> *v6; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SimObjectSignalMemoryComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::SimObjectSignalMemoryComponent::`vftable{for `UFG::UpdateInterface};
  if ( this == UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentpCurrentIterator )
    UFG::SimObjectSignalMemoryComponent::s_SimObjectSignalMemoryComponentpCurrentIterator = (UFG::SimObjectSignalMemoryComponent *)&this->mPrev[-5].mNext;
  v2 = &this->UFG::qNode<UFG::SimObjectSignalMemoryComponent,UFG::SimObjectSignalMemoryComponent>;
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

// File Line: 78
// RVA: 0x546D30
UFG::SimObjectSignalMemoryComponent *__fastcall UFG::SimObjectSignalMemoryComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *pSceneObj,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v5; // rax
  UFG::SimComponent *v6; // rsi
  char *MemImagePtr; // rdi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v10; // rax
  UFG::qPropertySet *mpConstProperties; // r8
  UFG::SimComponent *v12; // rax
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_CharacterProperties::sPropertyName,
         DEPTH_RECURSE);
  v6 = 0i64;
  if ( v5 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
    if ( MemImagePtr )
      goto LABEL_9;
  }
  else
  {
    MemImagePtr = 0i64;
  }
  if ( !required )
    return 0i64;
LABEL_9:
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v10 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x70ui64, "SimObjectSignalMemoryComponent", 0i64, 1u);
  if ( v10 )
  {
    mpConstProperties = pSceneObj->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = pSceneObj->mpConstProperties;
    UFG::SimObjectSignalMemoryComponent::SimObjectSignalMemoryComponent(
      (UFG::SimObjectSignalMemoryComponent *)v10,
      pSceneObj->m_NameUID,
      mpConstProperties,
      (component_CharacterProperties *)MemImagePtr);
    v6 = v12;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v13, pSceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v13, v6, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v13);
  UFG::SimObjectModifier::~SimObjectModifier(&v13);
  return (UFG::SimObjectSignalMemoryComponent *)v6;
}

