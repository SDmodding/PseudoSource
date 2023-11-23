// File Line: 20
// RVA: 0x1543F60
__int64 dynamic_initializer_for__UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentList__);
}

// File Line: 21
// RVA: 0x5324E0
const char *__fastcall UFG::MeleeScriptSystemComponent::GetTypeName(UFG::MeleeScriptSystemComponent *this)
{
  return "MeleeScriptSystemComponent";
}

// File Line: 23
// RVA: 0x1544220
__int64 dynamic_initializer_for__UFG::MeleeScriptSystemComponent::symActiveGameslices__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MeleeScriptSystem_ActiveGameslices", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::MeleeScriptSystemComponent::symActiveGameslices, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::MeleeScriptSystemComponent::symActiveGameslices__);
}

// File Line: 24
// RVA: 0x1544460
__int64 dynamic_initializer_for__UFG::MeleeScriptSystemComponent::symSpawnGroup__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MeleeScriptSystem_SpawnGroup", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::MeleeScriptSystemComponent::symSpawnGroup, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::MeleeScriptSystemComponent::symSpawnGroup__);
}

// File Line: 25
// RVA: 0x15444A0
__int64 dynamic_initializer_for__UFG::MeleeScriptSystemComponent::symStartTrigger__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MeleeScriptSystem_StartTrigger", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::MeleeScriptSystemComponent::symStartTrigger, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::MeleeScriptSystemComponent::symStartTrigger__);
}

// File Line: 32
// RVA: 0x518290
void __fastcall UFG::MeleeScriptSystemComponent::MeleeScriptSystemComponent(
        UFG::MeleeScriptSystemComponent *this,
        unsigned int nameUID,
        UFG::SimObject *pSimObject)
{
  UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *mPrev; // rax
  UFG::TSActorComponent *ComponentOfType; // rax

  UFG::SimComponent::SimComponent(this, nameUID);
  this->mPrev = &this->UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent>;
  this->mNext = &this->UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MeleeScriptSystemComponent::`vftable;
  UFG::qString::qString(&this->mActiveGameslices, &customCaption);
  UFG::qString::qString(&this->mSpawnGroup, &customCaption);
  UFG::qString::qString(&this->mStartTrigger, &customCaption);
  mPrev = UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentList.mNode.mPrev;
  UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *)&UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentList;
  UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentList.mNode.mPrev = &this->UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::MeleeScriptSystemComponent::_MeleeScriptSystemComponentTypeUID,
    "MeleeScriptSystemComponent");
  if ( pSimObject )
    ComponentOfType = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                 pSimObject,
                                                 UFG::TSActorComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  UFG::TSActorComponent::GetActor(ComponentOfType);
}

// File Line: 44
// RVA: 0x51C020
void __fastcall UFG::MeleeScriptSystemComponent::~MeleeScriptSystemComponent(UFG::MeleeScriptSystemComponent *this)
{
  UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *v2; // rbx
  UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *mPrev; // rcx
  UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *mNext; // rax
  UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *v5; // rcx
  UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MeleeScriptSystemComponent::`vftable;
  if ( this == UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentpCurrentIterator )
    UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentpCurrentIterator = (UFG::MeleeScriptSystemComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qString::~qString(&this->mStartTrigger);
  UFG::qString::~qString(&this->mSpawnGroup);
  UFG::qString::~qString(&this->mActiveGameslices);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 55
// RVA: 0x545160
UFG::MeleeScriptSystemComponent *__fastcall UFG::MeleeScriptSystemComponent::PropertiesOnActivate(
        UFG::SceneObjectProperties *sceneObj)
{
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v3; // rax
  __int64 v4; // rax
  __int64 v5; // rdi
  UFG::qPropertySet *mpWritableProperties; // rcx
  char *v7; // rax
  UFG::qPropertySet *mpConstProperties; // rcx
  char *v9; // rax
  UFG::qPropertySet *v10; // rcx
  char *v11; // rax
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xC8ui64, "MeleeScriptSystemComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::MeleeScriptSystemComponent::MeleeScriptSystemComponent(
      (UFG::MeleeScriptSystemComponent *)v3,
      sceneObj->m_NameUID,
      sceneObj->m_pSimObject);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  mpWritableProperties = sceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObj->mpConstProperties;
  v7 = UFG::qPropertySet::Get<char const *>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&UFG::MeleeScriptSystemComponent::symActiveGameslices,
         DEPTH_RECURSE);
  UFG::qString::Set((UFG::qString *)(v5 + 80), v7);
  mpConstProperties = sceneObj->mpWritableProperties;
  if ( !mpConstProperties )
    mpConstProperties = sceneObj->mpConstProperties;
  v9 = UFG::qPropertySet::Get<char const *>(
         mpConstProperties,
         (UFG::qArray<unsigned long,0> *)&UFG::MeleeScriptSystemComponent::symSpawnGroup,
         DEPTH_RECURSE);
  UFG::qString::Set((UFG::qString *)(v5 + 120), v9);
  v10 = sceneObj->mpWritableProperties;
  if ( !v10 )
    v10 = sceneObj->mpConstProperties;
  v11 = UFG::qPropertySet::Get<char const *>(
          v10,
          (UFG::qArray<unsigned long,0> *)&UFG::MeleeScriptSystemComponent::symStartTrigger,
          DEPTH_RECURSE);
  UFG::qString::Set((UFG::qString *)(v5 + 160), v11);
  UFG::SimObjectModifier::SimObjectModifier(&v13, sceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v13, (UFG::SimComponent *)v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v13);
  UFG::SimObjectModifier::~SimObjectModifier(&v13);
  return (UFG::MeleeScriptSystemComponent *)v5;
}

