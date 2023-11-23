// File Line: 20
// RVA: 0x1543FA0
__int64 dynamic_initializer_for__UFG::NISScriptSystemComponent::s_NISScriptSystemComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::NISScriptSystemComponent::s_NISScriptSystemComponentList__);
}

// File Line: 21
// RVA: 0x532500
const char *__fastcall UFG::NISScriptSystemComponent::GetTypeName(UFG::NISScriptSystemComponent *this)
{
  return "NISScriptSystemComponent";
}

// File Line: 23
// RVA: 0x15443A0
__int64 dynamic_initializer_for__UFG::NISScriptSystemComponent::symNISPath__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("NISScriptSystem_NISPath", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::NISScriptSystemComponent::symNISPath, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::NISScriptSystemComponent::symNISPath__);
}

// File Line: 24
// RVA: 0x1544260
__int64 dynamic_initializer_for__UFG::NISScriptSystemComponent::symActiveGameslices__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("NISScriptSystem_ActiveGameslices", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::NISScriptSystemComponent::symActiveGameslices, v0);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::NISScriptSystemComponent::symActiveGameslices__);
}

// File Line: 30
// RVA: 0x5185F0
void __fastcall UFG::NISScriptSystemComponent::NISScriptSystemComponent(
        UFG::NISScriptSystemComponent *this,
        unsigned int nameUID,
        UFG::SimObject *pSimObject)
{
  UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *mPrev; // rax
  UFG::TSActorComponent *ComponentOfType; // rax

  UFG::SimComponent::SimComponent(this, nameUID);
  this->mPrev = &this->UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent>;
  this->mNext = &this->UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::NISScriptSystemComponent::`vftable;
  UFG::qString::qString(&this->mNISPath, &customCaption);
  UFG::qString::qString(&this->mActiveGameslices, &customCaption);
  mPrev = UFG::NISScriptSystemComponent::s_NISScriptSystemComponentList.mNode.mPrev;
  UFG::NISScriptSystemComponent::s_NISScriptSystemComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *)&UFG::NISScriptSystemComponent::s_NISScriptSystemComponentList;
  UFG::NISScriptSystemComponent::s_NISScriptSystemComponentList.mNode.mPrev = &this->UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::NISScriptSystemComponent::_NISScriptSystemComponentTypeUID,
    "NISScriptSystemComponent");
  if ( pSimObject )
    ComponentOfType = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(
                                                 pSimObject,
                                                 UFG::TSActorComponent::_TypeUID);
  else
    ComponentOfType = 0i64;
  UFG::TSActorComponent::GetActor(ComponentOfType);
}

// File Line: 42
// RVA: 0x51C1B0
void __fastcall UFG::NISScriptSystemComponent::~NISScriptSystemComponent(UFG::NISScriptSystemComponent *this)
{
  UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *v2; // rbx
  UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *mPrev; // rcx
  UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *mNext; // rax
  UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *v5; // rcx
  UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::NISScriptSystemComponent::`vftable;
  if ( this == UFG::NISScriptSystemComponent::s_NISScriptSystemComponentpCurrentIterator )
    UFG::NISScriptSystemComponent::s_NISScriptSystemComponentpCurrentIterator = (UFG::NISScriptSystemComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qString::~qString(&this->mActiveGameslices);
  UFG::qString::~qString(&this->mNISPath);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 53
// RVA: 0x5452A0
UFG::NISScriptSystemComponent *__fastcall UFG::NISScriptSystemComponent::PropertiesOnActivate(
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
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h] BYREF

  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0xA0ui64, "NISScriptSystemComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::NISScriptSystemComponent::NISScriptSystemComponent(
      (UFG::NISScriptSystemComponent *)v3,
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
         (UFG::qArray<unsigned long,0> *)&UFG::NISScriptSystemComponent::symNISPath,
         DEPTH_RECURSE);
  UFG::qString::Set((UFG::qString *)(v5 + 80), v7);
  mpConstProperties = sceneObj->mpWritableProperties;
  if ( !mpConstProperties )
    mpConstProperties = sceneObj->mpConstProperties;
  v9 = UFG::qPropertySet::Get<char const *>(
         mpConstProperties,
         (UFG::qArray<unsigned long,0> *)&UFG::NISScriptSystemComponent::symActiveGameslices,
         DEPTH_RECURSE);
  UFG::qString::Set((UFG::qString *)(v5 + 120), v9);
  UFG::SimObjectModifier::SimObjectModifier(&v11, sceneObj->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, (UFG::SimComponent *)v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return (UFG::NISScriptSystemComponent *)v5;
}

