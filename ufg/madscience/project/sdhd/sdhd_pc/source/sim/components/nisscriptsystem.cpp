// File Line: 20
// RVA: 0x1543FA0
__int64 dynamic_initializer_for__UFG::NISScriptSystemComponent::s_NISScriptSystemComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::NISScriptSystemComponent::s_NISScriptSystemComponentList__);
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
  return atexit(dynamic_atexit_destructor_for__UFG::NISScriptSystemComponent::symNISPath__);
}

// File Line: 24
// RVA: 0x1544260
__int64 dynamic_initializer_for__UFG::NISScriptSystemComponent::symActiveGameslices__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("NISScriptSystem_ActiveGameslices", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::NISScriptSystemComponent::symActiveGameslices, v0);
  return atexit(dynamic_atexit_destructor_for__UFG::NISScriptSystemComponent::symActiveGameslices__);
}

// File Line: 30
// RVA: 0x5185F0
void __fastcall UFG::NISScriptSystemComponent::NISScriptSystemComponent(UFG::NISScriptSystemComponent *this, unsigned int nameUID, UFG::SimObject *pSimObject)
{
  UFG::SimObject *v3; // rsi
  UFG::NISScriptSystemComponent *v4; // rdi
  UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *v5; // rbx
  UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *v6; // rax
  UFG::TSActorComponent *v7; // rax

  v3 = pSimObject;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, nameUID);
  v5 = (UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::NISScriptSystemComponent::`vftable';
  UFG::qString::qString(&v4->mNISPath, &customWorldMapCaption);
  UFG::qString::qString(&v4->mActiveGameslices, &customWorldMapCaption);
  v6 = UFG::NISScriptSystemComponent::s_NISScriptSystemComponentList.mNode.mPrev;
  UFG::NISScriptSystemComponent::s_NISScriptSystemComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *)&UFG::NISScriptSystemComponent::s_NISScriptSystemComponentList;
  UFG::NISScriptSystemComponent::s_NISScriptSystemComponentList.mNode.mPrev = (UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::NISScriptSystemComponent::_NISScriptSystemComponentTypeUID,
    "NISScriptSystemComponent");
  if ( v3 )
    v7 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::TSActorComponent::_TypeUID);
  else
    v7 = 0i64;
  UFG::TSActorComponent::GetActor(v7);
}

// File Line: 42
// RVA: 0x51C1B0
void __fastcall UFG::NISScriptSystemComponent::~NISScriptSystemComponent(UFG::NISScriptSystemComponent *this)
{
  UFG::NISScriptSystemComponent *v1; // rdi
  UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *v2; // rbx
  UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *v3; // rcx
  UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *v4; // rax
  UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *v5; // rcx
  UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::NISScriptSystemComponent::`vftable';
  if ( this == UFG::NISScriptSystemComponent::s_NISScriptSystemComponentpCurrentIterator )
    UFG::NISScriptSystemComponent::s_NISScriptSystemComponentpCurrentIterator = (UFG::NISScriptSystemComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::NISScriptSystemComponent,UFG::NISScriptSystemComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qString::~qString(&v1->mActiveGameslices);
  UFG::qString::~qString(&v1->mNISPath);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 53
// RVA: 0x5452A0
UFG::NISScriptSystemComponent *__fastcall UFG::NISScriptSystemComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qMemoryPool *v2; // rax
  UFG::allocator::free_link *v3; // rax
  __int64 v4; // rax
  __int64 v5; // rdi
  UFG::qPropertySet *v6; // rcx
  char *v7; // rax
  UFG::qPropertySet *v8; // rcx
  char *v9; // rax
  UFG::SimObjectModifier v11; // [rsp+38h] [rbp-30h]

  v1 = sceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0xA0ui64, "NISScriptSystemComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::NISScriptSystemComponent::NISScriptSystemComponent(
      (UFG::NISScriptSystemComponent *)v3,
      v1->m_NameUID,
      v1->m_pSimObject);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = v1->mpWritableProperties;
  if ( !v6 )
    v6 = v1->mpConstProperties;
  v7 = UFG::qPropertySet::Get<char const *>(
         v6,
         (UFG::qSymbol *)&UFG::NISScriptSystemComponent::symNISPath.mUID,
         DEPTH_RECURSE);
  UFG::qString::Set((UFG::qString *)(v5 + 80), v7);
  v8 = v1->mpWritableProperties;
  if ( !v8 )
    v8 = v1->mpConstProperties;
  v9 = UFG::qPropertySet::Get<char const *>(
         v8,
         (UFG::qSymbol *)&UFG::NISScriptSystemComponent::symActiveGameslices.mUID,
         DEPTH_RECURSE);
  UFG::qString::Set((UFG::qString *)(v5 + 120), v9);
  UFG::SimObjectModifier::SimObjectModifier(&v11, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v11, (UFG::SimComponent *)v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v11);
  UFG::SimObjectModifier::~SimObjectModifier(&v11);
  return (UFG::NISScriptSystemComponent *)v5;
}

