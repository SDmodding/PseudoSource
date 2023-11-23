// File Line: 30
// RVA: 0x1458BC0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::PhysicsObjectProperties_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::sInventory,
    "UFG::PhysicsObjectProperties",
    v0);
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::PhysicsObjectProperties>::`vftable;
  UFG::qReflectInventory<UFG::PhysicsObjectProperties>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    &UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::PhysicsObjectProperties_UFG::qReflectObject_::sInventory__);
}

// File Line: 31
// RVA: 0x14588A0
void dynamic_initializer_for__UFG::qReflectObjectType_UFG::PhysicsSurfaceProperties_UFG::qReflectObject_::sFactoryOp__()
{
  UFG::FactoryOperation::FactoryOperation(&UFG::qReflectObjectType<UFG::PhysicsSurfaceProperties,UFG::qReflectObject>::sFactoryOp);
}

// File Line: 36
// RVA: 0x1458E20
__int64 UFG::_dynamic_initializer_for__defaultSkidEffectUID__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHashUpper32("Vehicle_SkidSmoke", -1);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::defaultSkidEffectUID, v0);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__defaultSkidEffectUID__);
}

// File Line: 37
// RVA: 0x1459150
__int64 UFG::_dynamic_initializer_for__physicsObjectPropertyTypeUid__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("PhysicsObjectProperties", -1);
  UFG::physicsObjectPropertyTypeUid = result;
  return result;
}

// File Line: 39
// RVA: 0x1458D40
__int64 dynamic_initializer_for__UFG::PhysicsPropertyManager::sObjectPropertiesLookup__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PhysicsPropertyManager::sObjectPropertiesLookup__);
}

// File Line: 40
// RVA: 0x1458D70
__int64 dynamic_initializer_for__UFG::PhysicsPropertyManager::sSurfacePropertiesLookup__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::PhysicsPropertyManager::sSurfacePropertiesLookup__);
}

// File Line: 167
// RVA: 0xA95B0
UFG::qWiseSymbol *__fastcall UFG::PhysicsObjectProperties::GetAudioProperty(
        UFG::PhysicsObjectProperties *this,
        UFG::qWiseSymbol *key)
{
  unsigned int mNumItems; // r8d
  __int64 v3; // rax
  UFG::PhysicsObjectProperties::AudioProperty *mItems; // r9
  unsigned int mUID; // edx
  UFG::PhysicsObjectProperties::AudioProperty *i; // rcx

  mNumItems = this->mAudioProperties.mData.mNumItems;
  v3 = 0i64;
  if ( !mNumItems )
    return UFG::qWiseSymbol::get_null();
  mItems = this->mAudioProperties.mData.mItems;
  mUID = key->mUID;
  for ( i = mItems; i->mKey.mUID != mUID; ++i )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= mNumItems )
      return UFG::qWiseSymbol::get_null();
  }
  return &mItems[v3].mValue;
}

// File Line: 271
// RVA: 0xACD70
void UFG::PhysicsPropertyManager::LoadDefinitionsFromInventory(void)
{
  Render::SkinningCacheNode *Head; // rbx
  unsigned __int64 v1; // rbx
  UFG::qReflectWarehouse *v2; // rax
  UFG::qReflectInventoryBase *Inventory; // rbp
  UFG::qReflectObject *ObjectByName; // r15
  UFG::qTree64Base *v5; // rax
  UFG::qReflectObject *p_mCount; // rbx
  char *v7; // rax
  char *v8; // rsi
  const char *Name; // rax
  UFG::qTree64Base::BaseNode *p_mBaseNode; // rdi
  unsigned __int64 mUID; // rbx
  unsigned __int64 v12; // rax
  UFG::qTree64Base *Next; // rax
  Render::SkinningCacheNode *v14; // rbx
  unsigned __int64 v15; // rbx
  UFG::qReflectWarehouse *v16; // rax
  UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *p_mItems; // rbp
  UFG::qTree64Base *v18; // rax
  __int64 *v19; // rsi
  char *v20; // rax
  char *v21; // rbx
  const char *v22; // rax
  unsigned __int64 v23; // rdi
  unsigned __int64 v24; // rax
  UFG::qTree64Base *v25; // rax

  while ( UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup,
      &Head->mNode);
    if ( Head )
    {
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&Head->mCachedBufferPtr);
      operator delete[](Head);
    }
  }
  v1 = UFG::qStringHash64("UFG::PhysicsSurfaceProperties", 0xFFFFFFFFFFFFFFFFui64);
  v2 = UFG::qReflectWarehouse::Instance();
  Inventory = UFG::qReflectWarehouse::GetInventory(v2, v1);
  ObjectByName = UFG::qReflectInventoryBase::FindObjectByName(Inventory, "default");
  v5 = UFG::qTree64Base::GetHead(&Inventory->mItems.mTree);
  if ( v5 )
  {
    p_mCount = (UFG::qReflectObject *)&v5[-1].mCount;
    if ( v5 != (UFG::qTree64Base *)8 )
    {
      do
      {
        v7 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
        v8 = v7;
        if ( v7 )
        {
          *(_QWORD *)v7 = 0i64;
          *((_QWORD *)v7 + 1) = 0i64;
          *((_QWORD *)v7 + 2) = 0i64;
          UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)(v7 + 32));
        }
        else
        {
          v8 = 0i64;
        }
        Name = UFG::qReflectObject::GetName(p_mCount);
        *((_DWORD *)v8 + 6) = UFG::qStringHashUpper32(Name, 0xFFFFFFFF);
        p_mBaseNode = &p_mCount->mBaseNode;
        mUID = p_mCount->mBaseNode.mUID;
        v12 = UFG::qStringHash64("UFG::PhysicsSurfaceProperties", 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)(v8 + 32), v12, mUID);
        UFG::qBaseTreeRB::Add(&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree, (UFG::qBaseNodeRB *)v8);
        Next = UFG::qTree64Base::GetNext(&Inventory->mItems.mTree, p_mBaseNode);
        if ( !Next )
          break;
        p_mCount = (UFG::qReflectObject *)&Next[-1].mCount;
      }
      while ( Next != (UFG::qTree64Base *)8 );
    }
  }
  while ( UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree.mCount )
  {
    v14 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::PhysicsPropertyManager::sObjectPropertiesLookup);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::PhysicsPropertyManager::sObjectPropertiesLookup,
      &v14->mNode);
    if ( v14 )
    {
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v14->mCachedBufferPtr);
      operator delete[](v14);
    }
  }
  v15 = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  v16 = UFG::qReflectWarehouse::Instance();
  p_mItems = &UFG::qReflectWarehouse::GetInventory(v16, v15)->mItems;
  v18 = UFG::qTree64Base::GetHead(&p_mItems->mTree);
  if ( v18 )
  {
    v19 = &v18[-1].mCount;
    if ( v18 != (UFG::qTree64Base *)8 )
    {
      do
      {
        v20 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
        v21 = v20;
        if ( v20 )
        {
          *(_QWORD *)v20 = 0i64;
          *((_QWORD *)v20 + 1) = 0i64;
          *((_QWORD *)v20 + 2) = 0i64;
          UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)(v20 + 32));
        }
        else
        {
          v21 = 0i64;
        }
        v22 = UFG::qReflectObject::GetName((UFG::qReflectObject *)v19);
        *((_DWORD *)v21 + 6) = UFG::qStringHashUpper32(v22, 0xFFFFFFFF);
        v23 = v19[1];
        v24 = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)(v21 + 32), v24, v23);
        UFG::qBaseTreeRB::Add(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, (UFG::qBaseNodeRB *)v21);
        if ( !v19[41] )
          UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)(v19 + 37), v19[39], ObjectByName->mBaseNode.mUID);
        v25 = UFG::qTree64Base::GetNext(&p_mItems->mTree, (UFG::qTree64Base::BaseNode *)(v19 + 1));
        if ( !v25 )
          break;
        v19 = &v25[-1].mCount;
      }
      while ( v25 != (UFG::qTree64Base *)8 );
    }
  }
}

// File Line: 313
// RVA: 0xB2A90
void UFG::PhysicsPropertyManager::Shutdown(void)
{
  Render::SkinningCacheNode *Head; // rbx
  Render::SkinningCacheNode *v1; // rbx

  while ( UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::PhysicsPropertyManager::sObjectPropertiesLookup);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::PhysicsPropertyManager::sObjectPropertiesLookup,
      &Head->mNode);
    if ( Head )
    {
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&Head->mCachedBufferPtr);
      operator delete[](Head);
    }
  }
  while ( UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree.mCount )
  {
    v1 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup,
      &v1->mNode);
    if ( v1 )
    {
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mCachedBufferPtr);
      operator delete[](v1);
    }
  }
}

// File Line: 855
// RVA: 0xAAC40
void __fastcall UFG::PhysicsPropertyManager::GetObjectProperties(
        UFG::qReflectHandle<UFG::PhysicsObjectProperties> *handle,
        unsigned int guid,
        bool allowDefault)
{
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rdi
  UFG::qBaseTreeRB *v8; // rax
  unsigned __int64 v9; // r8

  if ( (_S2_3 & 1) != 0 )
  {
    v6 = default_uid;
  }
  else
  {
    _S2_3 |= 1u;
    v6 = UFG::qStringHashUpper32("default", 0xFFFFFFFF);
    default_uid = v6;
  }
  if ( v6 )
    v7 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, v6);
  else
    v7 = 0i64;
  if ( guid && (v8 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, guid)) != 0i64 )
  {
    v9 = *(_QWORD *)&v8->mNULL.mUID;
  }
  else
  {
    if ( !allowDefault )
      return;
    v9 = *(_QWORD *)&v7->mNULL.mUID;
  }
  UFG::qReflectHandleBase::Init(handle, handle->mTypeUID, v9);
}

// File Line: 875
// RVA: 0xAB590
void __fastcall UFG::PhysicsPropertyManager::GetSurfaceProperties(
        UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *handle,
        unsigned int guid,
        bool allowDefault)
{
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rdi
  UFG::qBaseTreeRB *v8; // rax
  unsigned __int64 v9; // r8

  if ( (_S3_2 & 1) != 0 )
  {
    v6 = default_uid_0;
  }
  else
  {
    _S3_2 |= 1u;
    v6 = UFG::qStringHashUpper32("default", 0xFFFFFFFF);
    default_uid_0 = v6;
  }
  if ( v6 )
    v7 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree, v6);
  else
    v7 = 0i64;
  if ( guid && (v8 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree, guid)) != 0i64 )
  {
    v9 = *(_QWORD *)&v8->mNULL.mUID;
  }
  else
  {
    if ( !allowDefault )
      return;
    v9 = *(_QWORD *)&v7->mNULL.mUID;
  }
  UFG::qReflectHandleBase::Init(handle, handle->mTypeUID, v9);
}

// File Line: 894
// RVA: 0xA9970
void __fastcall UFG::PhysicsPropertyManager::GetDefaultObjectProperties(
        UFG::qReflectHandle<UFG::PhysicsObjectProperties> *handle)
{
  unsigned int v2; // eax
  UFG::qBaseTreeRB *v3; // rax

  if ( (_S4_2 & 1) != 0 )
  {
    v2 = default_uid_1;
  }
  else
  {
    _S4_2 |= 1u;
    v2 = UFG::qStringHashUpper32("default", 0xFFFFFFFF);
    default_uid_1 = v2;
  }
  if ( v2 )
    v3 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, v2);
  else
    v3 = 0i64;
  UFG::qReflectHandleBase::Init(handle, handle->mTypeUID, *(_QWORD *)&v3->mNULL.mUID);
}

// File Line: 905
// RVA: 0xA99E0
void __fastcall UFG::PhysicsPropertyManager::GetDefaultSurfaceProperties(
        UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *handle)
{
  unsigned int v2; // eax
  UFG::qBaseTreeRB *v3; // rax

  if ( (_S5_1 & 1) != 0 )
  {
    v2 = default_uid_2;
  }
  else
  {
    _S5_1 |= 1u;
    v2 = UFG::qStringHashUpper32("default", 0xFFFFFFFF);
    default_uid_2 = v2;
  }
  if ( v2 )
    v3 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree, v2);
  else
    v3 = 0i64;
  UFG::qReflectHandleBase::Init(handle, handle->mTypeUID, *(_QWORD *)&v3->mNULL.mUID);
}

// File Line: 933
// RVA: 0xB1B70
void __fastcall UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(
        hkSimplePropertyValue objectPropertyHandleUid,
        hkpWorldObject *object)
{
  __int64 m_size; // r10
  int v3; // r9d
  __int64 v6; // r8
  hkSimpleProperty *m_data; // rax
  hkSimplePropertyValue result; // [rsp+30h] [rbp+8h] BYREF

  m_size = object->m_properties.m_size;
  v3 = 0;
  v6 = 0i64;
  if ( m_size <= 0 )
    goto LABEL_5;
  m_data = object->m_properties.m_data;
  while ( m_data->m_key != UFG::physicsObjectPropertyTypeUid )
  {
    ++v6;
    ++v3;
    ++m_data;
    if ( v6 >= m_size )
      goto LABEL_5;
  }
  if ( LODWORD(object->m_properties.m_data[v3].m_value.m_data) )
  {
    hkpWorldObject::removeProperty(object, &result, UFG::physicsObjectPropertyTypeUid);
    hkpWorldObject::addProperty(object, UFG::physicsObjectPropertyTypeUid, objectPropertyHandleUid);
  }
  else
  {
LABEL_5:
    hkpWorldObject::addProperty(object, UFG::physicsObjectPropertyTypeUid, objectPropertyHandleUid);
  }
}

// File Line: 960
// RVA: 0xAAD00
unsigned __int64 __fastcall UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(hkpWorldObject *object)
{
  __int64 m_size; // r9
  int v2; // r8d
  __int64 v3; // rdx
  hkSimpleProperty *i; // rax

  m_size = object->m_properties.m_size;
  v2 = 0;
  v3 = 0i64;
  if ( m_size <= 0 )
    return 0i64;
  for ( i = object->m_properties.m_data; i->m_key != UFG::physicsObjectPropertyTypeUid; ++i )
  {
    ++v3;
    ++v2;
    if ( v3 >= m_size )
      return 0i64;
  }
  return object->m_properties.m_data[v2].m_value.m_data;
}

// File Line: 969
// RVA: 0xAAD50
unsigned __int64 __fastcall UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(
        hkpWorldObject *object,
        hkpShape *shape,
        int shapeKey)
{
  unsigned __int64 m_userData; // rdi
  __int64 v7; // rdi
  UFG::CollisionMeshData::Part *Part; // rax
  unsigned __int64 result; // rax
  __int64 m_size; // r9
  int v11; // r8d
  __int64 v12; // rdx
  hkSimpleProperty *i; // rcx

  if ( shape )
  {
    if ( shape->m_type.m_storage == 9 && *(_BYTE *)(shape[2].m_userData + 16) == 8 )
    {
      m_userData = object->m_userData;
      if ( m_userData )
      {
        v7 = *(_QWORD *)(m_userData + 24);
        if ( v7 )
        {
          if ( UFG::SimComponent::IsType((UFG::SimComponent *)v7, UFG::RigidBody::_RigidBodyTypeUID) )
          {
            Part = UFG::CollisionMeshData::GetPart(*(UFG::CollisionMeshData **)(v7 + 160), shapeKey);
            return Part->mBaseProperty.objectPropertyHandleId;
          }
        }
      }
    }
    Part = (UFG::CollisionMeshData::Part *)UFG::GetBaseProperty(shape, shapeKey);
    if ( Part )
      return Part->mBaseProperty.objectPropertyHandleId;
  }
  m_size = object->m_properties.m_size;
  result = 0i64;
  v11 = 0;
  v12 = 0i64;
  if ( m_size > 0 )
  {
    for ( i = object->m_properties.m_data; i->m_key != UFG::physicsObjectPropertyTypeUid; ++i )
    {
      ++v12;
      ++v11;
      if ( v12 >= m_size )
        return result;
    }
    return object->m_properties.m_data[v11].m_value.m_data;
  }
  return result;
}

// File Line: 1016
// RVA: 0x1459070
__int64 UFG::_dynamic_initializer_for__gObjectPropertiesNotifier__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  UFG::EditNotification::EditNotification(
    &UFG::gObjectPropertiesNotifier,
    v0,
    (void (__fastcall *)(char *, UFG::qReflectField *, UFG::qReflectType *, char *, void *))UFG::PhysicsPropertyManager::OnObjectPropertyChanged,
    UFG::PhysicsPropertyManager::OnObjectReloaded,
    0i64);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gObjectPropertiesNotifier__);
}

// File Line: 1017
// RVA: 0x1459100
__int64 UFG::_dynamic_initializer_for__gSurfacePropertiesNotifier__()
{
  unsigned __int64 v0; // rax

  v0 = UFG::qStringHash64("UFG::PhysicsSurfaceProperties", 0xFFFFFFFFFFFFFFFFui64);
  UFG::EditNotification::EditNotification(
    &UFG::gSurfacePropertiesNotifier,
    v0,
    (void (__fastcall *)(char *, UFG::qReflectField *, UFG::qReflectType *, char *, void *))_,
    UFG::PhysicsPropertyManager::OnObjectReloaded,
    0i64);
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gSurfacePropertiesNotifier__);
}

// File Line: 1023
// RVA: 0xAE120
void __fastcall UFG::PhysicsPropertyManager::OnObjectPropertyChanged(
        char *object,
        UFG::qReflectField *field,
        UFG::qReflectType *field_type,
        char *field_data)
{
  hkpWorld *mWorld; // r13
  int v6; // ebp
  __int64 v7; // r12
  hkpSimulationIsland *v8; // r14
  int v9; // edi
  __int64 v10; // rsi
  unsigned __int64 m_userData; // rbx
  UFG::SimComponent *v12; // rbx
  __int64 v13; // rdx
  __int64 v14; // rdx
  UFG::qReflectHandleBase v15; // [rsp+28h] [rbp-50h] BYREF

  mWorld = UFG::BasePhysicsSystem::mInstance->mWorld;
  v6 = 0;
  if ( mWorld->m_activeSimulationIslands.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = mWorld->m_activeSimulationIslands.m_data[v7];
      v9 = 0;
      if ( v8->m_entities.m_size > 0 )
      {
        v10 = 0i64;
        do
        {
          m_userData = v8->m_entities.m_data[v10]->m_userData;
          if ( m_userData )
          {
            v12 = *(UFG::SimComponent **)(m_userData + 24);
            if ( v12 )
            {
              if ( UFG::SimComponent::IsType(v12, UFG::RigidBody::_RigidBodyTypeUID) )
              {
                UFG::qReflectHandleBase::qReflectHandleBase(&v15);
                v15.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
                v13 = *(_QWORD *)&v12[2].m_Flags;
                if ( v13 )
                  UFG::qReflectHandleBase::operator=(&v15, (UFG::qReflectHandleBase *)(v13 + 224));
                if ( (char *)v15.mData == object )
                {
                  ((void (__fastcall *)(UFG::SimComponent *))v12->vfptr[16].__vecDelDtor)(v12);
                  LOBYTE(v14) = 1;
                  v12->vfptr[15].__vecDelDtor(v12, v14);
                }
                UFG::qReflectHandleBase::~qReflectHandleBase(&v15);
              }
            }
          }
          ++v9;
          ++v10;
        }
        while ( v9 < v8->m_entities.m_size );
      }
      ++v6;
      ++v7;
    }
    while ( v6 < mWorld->m_activeSimulationIslands.m_size );
  }
}

// File Line: 1070
// RVA: 0xAE270
// attributes: thunk
void __fastcall UFG::PhysicsPropertyManager::OnObjectReloaded(char *object, void *user_data)
{
  UFG::PhysicsPropertyManager::BuildLookupTrees();
}

// File Line: 1078
// RVA: 0xA1340
void UFG::PhysicsPropertyManager::BuildLookupTrees(void)
{
  Render::SkinningCacheNode *Head; // rbx
  Render::SkinningCacheNode *v1; // rbx
  unsigned __int64 v2; // rbx
  UFG::qReflectWarehouse *v3; // rax
  UFG::qReflectInventoryBase *Inventory; // rbp
  UFG::qReflectObject *ObjectByName; // r15
  UFG::qTree64Base *v6; // rax
  UFG::qReflectObject *p_mCount; // rbx
  char *v8; // rax
  char *v9; // rsi
  const char *Name; // rax
  UFG::qTree64Base::BaseNode *p_mBaseNode; // rdi
  unsigned __int64 mUID; // rbx
  unsigned __int64 v13; // rax
  UFG::qTree64Base *Next; // rax
  unsigned __int64 v15; // rbx
  UFG::qReflectWarehouse *v16; // rax
  UFG::qTree64<UFG::qReflectObject,UFG::qReflectObject,0> *p_mItems; // rbp
  UFG::qTree64Base *v18; // rax
  __int64 *v19; // rsi
  char *v20; // rax
  char *v21; // rbx
  const char *v22; // rax
  unsigned __int64 v23; // rdi
  unsigned __int64 v24; // rax
  UFG::qTree64Base *v25; // rax

  while ( UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree.mCount )
  {
    Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::PhysicsPropertyManager::sObjectPropertiesLookup);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::PhysicsPropertyManager::sObjectPropertiesLookup,
      &Head->mNode);
    if ( Head )
    {
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&Head->mCachedBufferPtr);
      operator delete[](Head);
    }
  }
  while ( UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree.mCount )
  {
    v1 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup,
      &v1->mNode);
    if ( v1 )
    {
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mCachedBufferPtr);
      operator delete[](v1);
    }
  }
  v2 = UFG::qStringHash64("UFG::PhysicsSurfaceProperties", 0xFFFFFFFFFFFFFFFFui64);
  v3 = UFG::qReflectWarehouse::Instance();
  Inventory = UFG::qReflectWarehouse::GetInventory(v3, v2);
  ObjectByName = UFG::qReflectInventoryBase::FindObjectByName(Inventory, "default");
  v6 = UFG::qTree64Base::GetHead(&Inventory->mItems.mTree);
  if ( v6 )
  {
    p_mCount = (UFG::qReflectObject *)&v6[-1].mCount;
    if ( v6 != (UFG::qTree64Base *)8 )
    {
      do
      {
        v8 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
        v9 = v8;
        if ( v8 )
        {
          *(_QWORD *)v8 = 0i64;
          *((_QWORD *)v8 + 1) = 0i64;
          *((_QWORD *)v8 + 2) = 0i64;
          UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)(v8 + 32));
        }
        else
        {
          v9 = 0i64;
        }
        Name = UFG::qReflectObject::GetName(p_mCount);
        *((_DWORD *)v9 + 6) = UFG::qStringHashUpper32(Name, 0xFFFFFFFF);
        p_mBaseNode = &p_mCount->mBaseNode;
        mUID = p_mCount->mBaseNode.mUID;
        v13 = UFG::qStringHash64("UFG::PhysicsSurfaceProperties", 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)(v9 + 32), v13, mUID);
        UFG::qBaseTreeRB::Add(&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree, (UFG::qBaseNodeRB *)v9);
        Next = UFG::qTree64Base::GetNext(&Inventory->mItems.mTree, p_mBaseNode);
        if ( !Next )
          break;
        p_mCount = (UFG::qReflectObject *)&Next[-1].mCount;
      }
      while ( Next != (UFG::qTree64Base *)8 );
    }
  }
  v15 = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  v16 = UFG::qReflectWarehouse::Instance();
  p_mItems = &UFG::qReflectWarehouse::GetInventory(v16, v15)->mItems;
  v18 = UFG::qTree64Base::GetHead(&p_mItems->mTree);
  if ( v18 )
  {
    v19 = &v18[-1].mCount;
    if ( v18 != (UFG::qTree64Base *)8 )
    {
      do
      {
        v20 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
        v21 = v20;
        if ( v20 )
        {
          *(_QWORD *)v20 = 0i64;
          *((_QWORD *)v20 + 1) = 0i64;
          *((_QWORD *)v20 + 2) = 0i64;
          UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)(v20 + 32));
        }
        else
        {
          v21 = 0i64;
        }
        v22 = UFG::qReflectObject::GetName((UFG::qReflectObject *)v19);
        *((_DWORD *)v21 + 6) = UFG::qStringHashUpper32(v22, 0xFFFFFFFF);
        v23 = v19[1];
        v24 = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)(v21 + 32), v24, v23);
        UFG::qBaseTreeRB::Add(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, (UFG::qBaseNodeRB *)v21);
        if ( !v19[41] )
          UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)(v19 + 37), v19[39], ObjectByName->mBaseNode.mUID);
        v25 = UFG::qTree64Base::GetNext(&p_mItems->mTree, (UFG::qTree64Base::BaseNode *)(v19 + 1));
        if ( !v25 )
          break;
        v19 = &v25[-1].mCount;
      }
      while ( v25 != (UFG::qTree64Base *)8 );
    }
  }
}

