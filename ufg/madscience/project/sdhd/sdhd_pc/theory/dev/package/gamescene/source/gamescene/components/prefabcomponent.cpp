// File Line: 19
// RVA: 0x23D600
UFG::ComponentIDDesc *__fastcall UFG::PrefabComponent::GetDesc(UFG::PrefabComponent *this)
{
  return &UFG::PrefabComponent::_TypeIDesc;
}

// File Line: 20
// RVA: 0x1470E50
__int64 dynamic_initializer_for__UFG::PrefabComponent::s_PrefabComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::PrefabComponent::s_PrefabComponentList__);
}

// File Line: 25
// RVA: 0x2375A0
void __fastcall UFG::PrefabComponent::PrefabComponent(UFG::PrefabComponent *this, unsigned int nameId, component_Prefab *data)
{
  component_Prefab *v3; // rbx
  UFG::PrefabComponent *v4; // rsi
  UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *v5; // rdi
  UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *v6; // rax

  v3 = data;
  v4 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, nameId);
  v5 = (UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *)&v4->mPrev;
  v5->mPrev = v5;
  v5->mNext = v5;
  v4->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PrefabComponent::`vftable;
  v4->mData = v3;
  v4->mObjects.p = 0i64;
  *(_QWORD *)&v4->mObjects.size = 0i64;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v4->vfptr,
    UFG::PrefabComponent::_PrefabComponentTypeUID,
    "PrefabComponent");
  v6 = UFG::PrefabComponent::s_PrefabComponentList.mNode.mPrev;
  UFG::PrefabComponent::s_PrefabComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *)&v4->mPrev;
  v5->mPrev = v6;
  v4->mNext = (UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *)&UFG::PrefabComponent::s_PrefabComponentList;
  UFG::PrefabComponent::s_PrefabComponentList.mNode.mPrev = (UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *)&v4->mPrev;
}

// File Line: 31
// RVA: 0x238220
void __fastcall UFG::PrefabComponent::~PrefabComponent(UFG::PrefabComponent *this)
{
  UFG::PrefabComponent *v1; // rbx
  UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *v2; // rsi
  UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *v3; // rcx
  UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *v4; // rax
  unsigned int v5; // edi
  UFG::SceneObjectProperties **v6; // rcx
  UFG::SceneObjectProperties **v7; // rcx
  UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *v8; // rcx
  UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *v9; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PrefabComponent::`vftable;
  if ( this == UFG::PrefabComponent::s_PrefabComponentpCurrentIterator )
    UFG::PrefabComponent::s_PrefabComponentpCurrentIterator = (UFG::PrefabComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v5 = 0;
  if ( v1->mObjects.size )
  {
    do
      UFG::SimObject::Destroy(v1->mObjects.p[v5++]->m_pSimObject);
    while ( v5 < v1->mObjects.size );
  }
  v6 = v1->mObjects.p;
  if ( v6 )
    operator delete[](v6);
  v1->mObjects.p = 0i64;
  *(_QWORD *)&v1->mObjects.size = 0i64;
  v7 = v1->mObjects.p;
  if ( v7 )
    operator delete[](v7);
  v1->mObjects.p = 0i64;
  *(_QWORD *)&v1->mObjects.size = 0i64;
  v8 = v2->mPrev;
  v9 = v2->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 47
// RVA: 0x243030
void __fastcall UFG::PrefabComponent::OnAttach(UFG::PrefabComponent *this, UFG::SimObject *object)
{
  UFG::PrefabComponent *v2; // r15
  UFG::qPropertySet *v3; // rax
  UFG::TransformNodeComponent *v4; // r13
  UFG::qPropertySet *v5; // rax
  char *v6; // r14
  unsigned int v7; // esi
  UFG::qPropertyList *v8; // rcx
  char *v9; // rax
  char *v10; // rax
  UFG::qPropertySet *v11; // rdx
  UFG::SceneObjectProperties *v12; // r12
  UFG::SimObject *v13; // rax
  __int64 v14; // rbp
  unsigned int v15; // edx
  unsigned int v16; // ebx
  unsigned int v17; // edx
  UFG::SceneObjectProperties **v18; // rax

  v2 = this;
  v3 = UFG::PropertySetManager::FindPropertySet(&this->mData->PrefabId);
  if ( v3 )
  {
    v4 = v2->m_pSimObject->m_pTransformNodeComponent;
    v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           v3,
           (UFG::qSymbol *)&component_PrefabData::sPropertyName.mUID,
           DEPTH_RECURSE);
    if ( v5 )
    {
      v6 = UFG::qPropertySet::GetMemImagePtr(v5);
      if ( v6 )
      {
        v7 = 0;
        while ( 1 )
        {
          v8 = *(UFG::qPropertyList **)v6;
          v9 = *(_QWORD *)v6 ? &v6[(_QWORD)v8] : 0i64;
          if ( v7 >= *((_DWORD *)v9 + 10) )
            break;
          if ( v8 )
            v8 = (UFG::qPropertyList *)((char *)v8 + (_QWORD)v6);
          v10 = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, v7);
          if ( v10 && *(_QWORD *)v10 )
            v11 = (UFG::qPropertySet *)&v10[*(_QWORD *)v10];
          else
            v11 = 0i64;
          v12 = UFG::SceneObjectProperties::Create(v2->m_NameUID, v11, v7);
          v13 = UFG::SceneObjectProperties::Activate(v12, 1u, 0i64, v4);
          if ( UFG::PrefabComponent::PostSimObject )
            UFG::PrefabComponent::PostSimObject(v2, v13, v7);
          v14 = v2->mObjects.size;
          v15 = v2->mObjects.capacity;
          v16 = v14 + 1;
          if ( (signed int)v14 + 1 > v15 )
          {
            if ( v15 )
              v17 = 2 * v15;
            else
              v17 = 1;
            for ( ; v17 < v16; v17 *= 2 )
              ;
            if ( v17 <= 2 )
              v17 = 2;
            if ( v17 - v16 > 0x10000 )
              v17 = v14 + 65537;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v2->mObjects,
              v17,
              "qArray.Add");
          }
          v18 = v2->mObjects.p;
          v2->mObjects.size = v16;
          ++v7;
          v18[v14] = v12;
        }
      }
    }
  }
}

// File Line: 97
// RVA: 0x244080
UFG::SimComponent *__fastcall UFG::PrefabComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qPropertySet *v2; // rcx
  UFG::qPropertySet *v3; // rax
  UFG::SimComponent *v4; // rdi
  char *v5; // rsi
  UFG::qMemoryPool *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::SimComponent *v8; // rax
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h]

  v1 = sceneObject;
  v2 = sceneObject->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  v3 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v2,
         (UFG::qSymbol *)&component_Prefab::sPropertyName.mUID,
         DEPTH_RECURSE);
  v4 = 0i64;
  if ( v3 )
    v5 = UFG::qPropertySet::GetMemImagePtr(v3);
  else
    v5 = 0i64;
  v6 = UFG::GetSimulationMemoryPool();
  v7 = UFG::qMemoryPool::Allocate(v6, 0x68ui64, "PrefabComponent", 0i64, 1u);
  if ( v7 )
  {
    UFG::PrefabComponent::PrefabComponent((UFG::PrefabComponent *)v7, v1->m_NameUID, (component_Prefab *)v5);
    v4 = v8;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v10, v1->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v4, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return v4;
}

