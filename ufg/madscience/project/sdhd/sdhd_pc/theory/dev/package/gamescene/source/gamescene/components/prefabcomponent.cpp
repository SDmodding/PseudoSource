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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PrefabComponent::s_PrefabComponentList__);
}

// File Line: 25
// RVA: 0x2375A0
void __fastcall UFG::PrefabComponent::PrefabComponent(
        UFG::PrefabComponent *this,
        unsigned int nameId,
        component_Prefab *data)
{
  UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, nameId);
  this->mPrev = &this->UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent>;
  this->mNext = &this->UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PrefabComponent::`vftable;
  this->mData = data;
  this->mObjects.p = 0i64;
  *(_QWORD *)&this->mObjects.size = 0i64;
  UFG::SimComponent::AddType(this, UFG::PrefabComponent::_PrefabComponentTypeUID, "PrefabComponent");
  mPrev = UFG::PrefabComponent::s_PrefabComponentList.mNode.mPrev;
  UFG::PrefabComponent::s_PrefabComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *)&UFG::PrefabComponent::s_PrefabComponentList;
  UFG::PrefabComponent::s_PrefabComponentList.mNode.mPrev = &this->UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent>;
}

// File Line: 31
// RVA: 0x238220
void __fastcall UFG::PrefabComponent::~PrefabComponent(UFG::PrefabComponent *this)
{
  UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *v2; // rsi
  UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *mPrev; // rcx
  UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *mNext; // rax
  unsigned int i; // edi
  UFG::SceneObjectProperties **p; // rcx
  UFG::SceneObjectProperties **v7; // rcx
  UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *v8; // rcx
  UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent> *v9; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::PrefabComponent::`vftable;
  if ( this == UFG::PrefabComponent::s_PrefabComponentpCurrentIterator )
    UFG::PrefabComponent::s_PrefabComponentpCurrentIterator = (UFG::PrefabComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::PrefabComponent,UFG::PrefabComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  for ( i = 0; i < this->mObjects.size; ++i )
    UFG::SimObject::Destroy(this->mObjects.p[i]->m_pSimObject);
  p = this->mObjects.p;
  if ( p )
    operator delete[](p);
  this->mObjects.p = 0i64;
  *(_QWORD *)&this->mObjects.size = 0i64;
  v7 = this->mObjects.p;
  if ( v7 )
    operator delete[](v7);
  this->mObjects.p = 0i64;
  *(_QWORD *)&this->mObjects.size = 0i64;
  v8 = v2->mPrev;
  v9 = v2->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 47
// RVA: 0x243030
void __fastcall UFG::PrefabComponent::OnAttach(UFG::PrefabComponent *this, UFG::SimObject *object)
{
  UFG::qPropertySet *PropertySet; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // r13
  UFG::qPropertySet *v5; // rax
  char *MemImagePtr; // r14
  unsigned int i; // esi
  UFG::qPropertyList *v8; // rcx
  char *v9; // rax
  char *ValuePtr; // rax
  UFG::qPropertySet *v11; // rdx
  UFG::allocator::free_link *v12; // r12
  UFG::SimObject *v13; // rax
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v16; // ebx
  unsigned int v17; // edx
  UFG::SceneObjectProperties **p; // rax

  PropertySet = UFG::PropertySetManager::FindPropertySet(&this->mData->PrefabId);
  if ( PropertySet )
  {
    m_pTransformNodeComponent = this->m_pSimObject->m_pTransformNodeComponent;
    v5 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           PropertySet,
           (UFG::qArray<unsigned long,0> *)&component_PrefabData::sPropertyName,
           DEPTH_RECURSE);
    if ( v5 )
    {
      MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v5);
      if ( MemImagePtr )
      {
        for ( i = 0; ; ++i )
        {
          v8 = *(UFG::qPropertyList **)MemImagePtr;
          v9 = *(_QWORD *)MemImagePtr ? &MemImagePtr[(_QWORD)v8] : 0i64;
          if ( i >= *((_DWORD *)v9 + 10) )
            break;
          if ( v8 )
            v8 = (UFG::qPropertyList *)((char *)v8 + (_QWORD)MemImagePtr);
          ValuePtr = UFG::qPropertyList::GetValuePtr(v8, 0x1Au, i);
          if ( ValuePtr && *(_QWORD *)ValuePtr )
            v11 = (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
          else
            v11 = 0i64;
          v12 = UFG::SceneObjectProperties::Create(this->m_NameUID, v11, i);
          v13 = UFG::SceneObjectProperties::Activate(
                  (UFG::SceneObjectProperties *)v12,
                  1u,
                  0i64,
                  m_pTransformNodeComponent);
          if ( UFG::PrefabComponent::PostSimObject )
            UFG::PrefabComponent::PostSimObject(this, v13, i);
          size = this->mObjects.size;
          capacity = this->mObjects.capacity;
          v16 = size + 1;
          if ( (int)size + 1 > capacity )
          {
            if ( capacity )
              v17 = 2 * capacity;
            else
              v17 = 1;
            for ( ; v17 < v16; v17 *= 2 )
              ;
            if ( v17 <= 2 )
              v17 = 2;
            if ( v17 - v16 > 0x10000 )
              v17 = size + 65537;
            UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
              (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mObjects,
              v17,
              "qArray.Add");
          }
          p = this->mObjects.p;
          this->mObjects.size = v16;
          p[size] = (UFG::SceneObjectProperties *)v12;
        }
      }
    }
  }
}

// File Line: 97
// RVA: 0x244080
UFG::PrefabComponent *__fastcall UFG::PrefabComponent::PropertiesOnActivate(UFG::SceneObjectProperties *sceneObject)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v3; // rax
  UFG::SimComponent *v4; // rdi
  char *MemImagePtr; // rsi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::SimComponent *v8; // rax
  UFG::SimObjectModifier v10; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = sceneObject->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = sceneObject->mpConstProperties;
  v3 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_Prefab::sPropertyName,
         DEPTH_RECURSE);
  v4 = 0i64;
  if ( v3 )
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v3);
  else
    MemImagePtr = 0i64;
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v7 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x68ui64, "PrefabComponent", 0i64, 1u);
  if ( v7 )
  {
    UFG::PrefabComponent::PrefabComponent(
      (UFG::PrefabComponent *)v7,
      sceneObject->m_NameUID,
      (component_Prefab *)MemImagePtr);
    v4 = v8;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v10, sceneObject->m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v10, v4, 0xFFFFFFFFi64);
  UFG::SimObjectModifier::Close(&v10);
  UFG::SimObjectModifier::~SimObjectModifier(&v10);
  return (UFG::PrefabComponent *)v4;
}

