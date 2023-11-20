// File Line: 20
// RVA: 0x1543F60
__int64 dynamic_initializer_for__UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentList__);
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
  return atexit(dynamic_atexit_destructor_for__UFG::MeleeScriptSystemComponent::symActiveGameslices__);
}

// File Line: 24
// RVA: 0x1544460
__int64 dynamic_initializer_for__UFG::MeleeScriptSystemComponent::symSpawnGroup__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MeleeScriptSystem_SpawnGroup", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::MeleeScriptSystemComponent::symSpawnGroup, v0);
  return atexit(dynamic_atexit_destructor_for__UFG::MeleeScriptSystemComponent::symSpawnGroup__);
}

// File Line: 25
// RVA: 0x15444A0
__int64 dynamic_initializer_for__UFG::MeleeScriptSystemComponent::symStartTrigger__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("MeleeScriptSystem_StartTrigger", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::MeleeScriptSystemComponent::symStartTrigger, v0);
  return atexit(dynamic_atexit_destructor_for__UFG::MeleeScriptSystemComponent::symStartTrigger__);
}

// File Line: 32
// RVA: 0x518290
void __fastcall UFG::MeleeScriptSystemComponent::MeleeScriptSystemComponent(UFG::MeleeScriptSystemComponent *this, unsigned int nameUID, UFG::SimObject *pSimObject)
{
  UFG::SimObject *v3; // rsi
  UFG::MeleeScriptSystemComponent *v4; // rdi
  UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *v5; // rbx
  UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *v6; // rax
  UFG::TSActorComponent *v7; // rax

  v3 = pSimObject;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, nameUID);
  v5 = (UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MeleeScriptSystemComponent::`vftable';
  UFG::qString::qString(&v4->mActiveGameslices, &customWorldMapCaption);
  UFG::qString::qString(&v4->mSpawnGroup, &customWorldMapCaption);
  UFG::qString::qString(&v4->mStartTrigger, &customWorldMapCaption);
  v6 = UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentList.mNode.mPrev;
  UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *)&UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentList;
  UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentList.mNode.mPrev = (UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *)&v4->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::MeleeScriptSystemComponent::_MeleeScriptSystemComponentTypeUID,
    "MeleeScriptSystemComponent");
  if ( v3 )
    v7 = (UFG::TSActorComponent *)UFG::SimObject::GetComponentOfType(v3, UFG::TSActorComponent::_TypeUID);
  else
    v7 = 0i64;
  UFG::TSActorComponent::GetActor(v7);
}

// File Line: 44
// RVA: 0x51C020
void __fastcall UFG::MeleeScriptSystemComponent::~MeleeScriptSystemComponent(UFG::MeleeScriptSystemComponent *this)
{
  UFG::MeleeScriptSystemComponent *v1; // rdi
  UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *v2; // rbx
  UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *v3; // rcx
  UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *v4; // rax
  UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *v5; // rcx
  UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::MeleeScriptSystemComponent::`vftable';
  if ( this == UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentpCurrentIterator )
    UFG::MeleeScriptSystemComponent::s_MeleeScriptSystemComponentpCurrentIterator = (UFG::MeleeScriptSystemComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::MeleeScriptSystemComponent,UFG::MeleeScriptSystemComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::qString::~qString(&v1->mStartTrigger);
  UFG::qString::~qString(&v1->mSpawnGroup);
  UFG::qString::~qString(&v1->mActiveGameslices);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 55
// RVA: 0x545160
UFG::MeleeScriptSystemComponent *__fastcall UFG::MeleeScriptSystemComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObj)
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
  UFG::qPropertySet *v10; // rcx
  char *v11; // rax
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h]

  v1 = sceneObj;
  v2 = UFG::GetSimulationMemoryPool();
  v3 = UFG::qMemoryPool::Allocate(v2, 0xC8ui64, "MeleeScriptSystemComponent", 0i64, 1u);
  if ( v3 )
  {
    UFG::MeleeScriptSystemComponent::MeleeScriptSystemComponent(
      (UFG::MeleeScriptSystemComponent *)v3,
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
         (UFG::qSymbol *)&UFG::MeleeScriptSystemComponent::symActiveGameslices.mUID,
         DEPTH_RECURSE);
  UFG::qString::Set((UFG::qString *)(v5 + 80), v7);
  v8 = v1->mpWritableProperties;
  if ( !v8 )
    v8 = v1->mpConstProperties;
  v9 = UFG::qPropertySet::Get<char const *>(
         v8,
         (UFG::qSymbol *)&UFG::MeleeScriptSystemComponent::symSpawnGroup.mUID,
         DEPTH_RECURSE);
  UFG::qString::Set((UFG::qString *)(v5 + 120), v9);
  v10 = v1->mpWritableProperties;
  if ( !v10 )
    v10 = v1->mpConstProperties;
  v11 = UFG::qPropertySet::Get<char const *>(
          v10,
          (UFG::qSymbol *)&UFG::MeleeScriptSystemComponent::symStartTrigger.mUID,
          DEPTH_RECURSE);
  UFG::qString::Set((UFG::qString *)(v5 + 160), v11);
  UFG::SimObjectModifier::SimObjectModifier(&v13, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v13, (UFG::SimComponent *)v5, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v13);
  UFG::SimObjectModifier::~SimObjectModifier(&v13);
  return (UFG::MeleeScriptSystemComponent *)v5;
}

