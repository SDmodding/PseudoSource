// File Line: 30
// RVA: 0x1458BC0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_UFG::PhysicsObjectProperties_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::sInventory.vfptr,
    "UFG::PhysicsObjectProperties",
    v0);
  UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<UFG::PhysicsObjectProperties>::`vftable';
  UFG::qReflectInventory<UFG::PhysicsObjectProperties>::OnAddToWarehouse(&UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<UFG::PhysicsObjectProperties,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_UFG::PhysicsObjectProperties_UFG::qReflectObject_::sInventory__);
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

  v0 = UFG::qStringHashUpper32("Vehicle_SkidSmoke", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&UFG::defaultSkidEffectUID, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__defaultSkidEffectUID__);
}

// File Line: 37
// RVA: 0x1459150
__int64 UFG::_dynamic_initializer_for__physicsObjectPropertyTypeUid__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("PhysicsObjectProperties", 0xFFFFFFFF);
  UFG::physicsObjectPropertyTypeUid = result;
  return result;
}

// File Line: 39
// RVA: 0x1458D40
__int64 dynamic_initializer_for__UFG::PhysicsPropertyManager::sObjectPropertiesLookup__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::PhysicsPropertyManager::sObjectPropertiesLookup__);
}

// File Line: 40
// RVA: 0x1458D70
__int64 dynamic_initializer_for__UFG::PhysicsPropertyManager::sSurfacePropertiesLookup__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::PhysicsPropertyManager::sSurfacePropertiesLookup__);
}

// File Line: 167
// RVA: 0xA95B0
UFG::qWiseSymbol *__fastcall UFG::PhysicsObjectProperties::GetAudioProperty(UFG::PhysicsObjectProperties *this, UFG::qWiseSymbol *key)
{
  unsigned int v2; // er8
  __int64 v3; // rax
  UFG::PhysicsObjectProperties::AudioProperty *v4; // r9
  unsigned int v5; // edx
  UFG::PhysicsObjectProperties::AudioProperty *v6; // rcx

  v2 = this->mAudioProperties.mData.mNumItems;
  v3 = 0i64;
  if ( !v2 )
    return UFG::qWiseSymbol::get_null();
  v4 = this->mAudioProperties.mData.mItems;
  v5 = key->mUID;
  v6 = this->mAudioProperties.mData.mItems;
  while ( v6->mKey.mUID != v5 )
  {
    v3 = (unsigned int)(v3 + 1);
    ++v6;
    if ( (unsigned int)v3 >= v2 )
      return UFG::qWiseSymbol::get_null();
  }
  return &v4[v3].mValue;
}

// File Line: 271
// RVA: 0xACD70
void UFG::PhysicsPropertyManager::LoadDefinitionsFromInventory(void)
{
  Render::SkinningCacheNode *v0; // rbx
  unsigned __int64 v1; // rbx
  UFG::qReflectWarehouse *v2; // rax
  UFG::qReflectInventoryBase *v3; // rbp
  UFG::qReflectObject *v4; // r15
  UFG::qTree64Base *v5; // rax
  UFG::qReflectObject *v6; // rbx
  char *v7; // rax
  char *v8; // rsi
  const char *v9; // rax
  UFG::qTree64Base::BaseNode *v10; // rdi
  unsigned __int64 v11; // rbx
  unsigned __int64 v12; // rax
  UFG::qTree64Base *v13; // rax
  Render::SkinningCacheNode *v14; // rbx
  unsigned __int64 v15; // rbx
  UFG::qReflectWarehouse *v16; // rax
  UFG::qReflectInventoryBase *v17; // rax
  UFG::qTree64Base *v18; // rbp
  UFG::qTree64Base *v19; // rax
  signed __int64 v20; // rsi
  char *v21; // rax
  char *v22; // rbx
  const char *v23; // rax
  unsigned __int64 v24; // rdi
  unsigned __int64 v25; // rax
  UFG::qTree64Base *v26; // rax

  while ( UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree.mCount )
  {
    v0 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup,
      &v0->mNode);
    if ( v0 )
    {
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v0->mCachedBufferPtr);
      operator delete[](v0);
    }
  }
  v1 = UFG::qStringHash64("UFG::PhysicsSurfaceProperties", 0xFFFFFFFFFFFFFFFFui64);
  v2 = UFG::qReflectWarehouse::Instance();
  v3 = UFG::qReflectWarehouse::GetInventory(v2, v1);
  v4 = UFG::qReflectInventoryBase::FindObjectByName(v3, "default");
  v5 = UFG::qTree64Base::GetHead(&v3->mItems.mTree);
  if ( v5 )
  {
    v6 = (UFG::qReflectObject *)&v5[-1].mCount;
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
        v9 = UFG::qReflectObject::GetName(v6);
        *((_DWORD *)v8 + 6) = UFG::qStringHashUpper32(v9, 0xFFFFFFFF);
        v10 = &v6->mBaseNode;
        v11 = v6->mBaseNode.mUID;
        v12 = UFG::qStringHash64("UFG::PhysicsSurfaceProperties", 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)(v8 + 32), v12, v11);
        UFG::qBaseTreeRB::Add(&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree, (UFG::qBaseNodeRB *)v8);
        v13 = UFG::qTree64Base::GetNext(&v3->mItems.mTree, v10);
        if ( !v13 )
          break;
        v6 = (UFG::qReflectObject *)&v13[-1].mCount;
      }
      while ( v13 != (UFG::qTree64Base *)8 );
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
  v17 = UFG::qReflectWarehouse::GetInventory(v16, v15);
  v18 = &v17->mItems.mTree;
  v19 = UFG::qTree64Base::GetHead(&v17->mItems.mTree);
  if ( v19 )
  {
    v20 = (signed __int64)&v19[-1].mCount;
    if ( v19 != (UFG::qTree64Base *)8 )
    {
      do
      {
        v21 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
        v22 = v21;
        if ( v21 )
        {
          *(_QWORD *)v21 = 0i64;
          *((_QWORD *)v21 + 1) = 0i64;
          *((_QWORD *)v21 + 2) = 0i64;
          UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)(v21 + 32));
        }
        else
        {
          v22 = 0i64;
        }
        v23 = UFG::qReflectObject::GetName((UFG::qReflectObject *)v20);
        *((_DWORD *)v22 + 6) = UFG::qStringHashUpper32(v23, 0xFFFFFFFF);
        v24 = *(_QWORD *)(v20 + 8);
        v25 = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)(v22 + 32), v25, v24);
        UFG::qBaseTreeRB::Add(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, (UFG::qBaseNodeRB *)v22);
        if ( !*(_QWORD *)(v20 + 328) )
          UFG::qReflectHandleBase::Init(
            (UFG::qReflectHandleBase *)(v20 + 296),
            *(_QWORD *)(v20 + 312),
            v4->mBaseNode.mUID);
        v26 = UFG::qTree64Base::GetNext(v18, (UFG::qTree64Base::BaseNode *)(v20 + 8));
        if ( !v26 )
          break;
        v20 = (signed __int64)&v26[-1].mCount;
      }
      while ( v26 != (UFG::qTree64Base *)8 );
    }
  }
}

// File Line: 313
// RVA: 0xB2A90
void UFG::PhysicsPropertyManager::Shutdown(void)
{
  Render::SkinningCacheNode *v0; // rbx
  Render::SkinningCacheNode *v1; // rbx

  while ( UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree.mCount )
  {
    v0 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::PhysicsPropertyManager::sObjectPropertiesLookup);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::PhysicsPropertyManager::sObjectPropertiesLookup,
      &v0->mNode);
    if ( v0 )
    {
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v0->mCachedBufferPtr);
      operator delete[](v0);
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
void __fastcall UFG::PhysicsPropertyManager::GetObjectProperties(UFG::qReflectHandle<UFG::PhysicsObjectProperties> *handle, unsigned int guid, bool allowDefault)
{
  bool v3; // bp
  unsigned int v4; // esi
  UFG::qReflectHandle<UFG::PhysicsObjectProperties> *v5; // rbx
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rdi
  UFG::qBaseTreeRB *v8; // rax
  unsigned __int64 v9; // r8

  v3 = allowDefault;
  v4 = guid;
  v5 = handle;
  if ( _S2_3 & 1 )
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
  if ( v4 && (v8 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, v4)) != 0i64 )
  {
    v9 = *(_QWORD *)&v8->mNULL.mUID;
  }
  else
  {
    if ( !v3 )
      return;
    v9 = *(_QWORD *)&v7->mNULL.mUID;
  }
  UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)&v5->mPrev, v5->mTypeUID, v9);
}

// File Line: 875
// RVA: 0xAB590
void __fastcall UFG::PhysicsPropertyManager::GetSurfaceProperties(UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *handle, unsigned int guid, bool allowDefault)
{
  bool v3; // bp
  unsigned int v4; // esi
  UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *v5; // rbx
  unsigned int v6; // eax
  UFG::qBaseTreeRB *v7; // rdi
  UFG::qBaseTreeRB *v8; // rax
  unsigned __int64 v9; // r8

  v3 = allowDefault;
  v4 = guid;
  v5 = handle;
  if ( _S3_2 & 1 )
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
  if ( v4 && (v8 = UFG::qBaseTreeRB::Get(&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree, v4)) != 0i64 )
  {
    v9 = *(_QWORD *)&v8->mNULL.mUID;
  }
  else
  {
    if ( !v3 )
      return;
    v9 = *(_QWORD *)&v7->mNULL.mUID;
  }
  UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)&v5->mPrev, v5->mTypeUID, v9);
}

// File Line: 894
// RVA: 0xA9970
void __fastcall UFG::PhysicsPropertyManager::GetDefaultObjectProperties(UFG::qReflectHandle<UFG::PhysicsObjectProperties> *handle)
{
  UFG::qReflectHandle<UFG::PhysicsObjectProperties> *v1; // rbx
  unsigned int v2; // eax
  UFG::qBaseTreeRB *v3; // rax

  v1 = handle;
  if ( _S4_2 & 1 )
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
  UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)&v1->mPrev, v1->mTypeUID, *(_QWORD *)&v3->mNULL.mUID);
}

// File Line: 905
// RVA: 0xA99E0
void __fastcall UFG::PhysicsPropertyManager::GetDefaultSurfaceProperties(UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *handle)
{
  UFG::qReflectHandle<UFG::PhysicsSurfaceProperties> *v1; // rbx
  unsigned int v2; // eax
  UFG::qBaseTreeRB *v3; // rax

  v1 = handle;
  if ( _S5_1 & 1 )
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
  UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)&v1->mPrev, v1->mTypeUID, *(_QWORD *)&v3->mNULL.mUID);
}

// File Line: 933
// RVA: 0xB1B70
void __fastcall UFG::PhysicsPropertyManager::SetObjectPropertiesHandleUid(unsigned __int64 objectPropertyHandleUid, hkpWorldObject *object)
{
  __int64 v2; // r10
  int v3; // er9
  hkpWorldObject *v4; // rbx
  unsigned __int64 v5; // rdi
  __int64 v6; // r8
  hkSimpleProperty *v7; // rax
  hkSimplePropertyValue result; // [rsp+30h] [rbp+8h]

  v2 = object->m_properties.m_size;
  v3 = 0;
  v4 = object;
  v5 = objectPropertyHandleUid;
  v6 = 0i64;
  if ( v2 <= 0 )
    goto LABEL_5;
  v7 = object->m_properties.m_data;
  while ( v7->m_key != UFG::physicsObjectPropertyTypeUid )
  {
    ++v6;
    ++v3;
    ++v7;
    if ( v6 >= v2 )
      goto LABEL_5;
  }
  if ( LODWORD(object->m_properties.m_data[v3].m_value.m_data) )
  {
    hkpWorldObject::removeProperty(object, &result, UFG::physicsObjectPropertyTypeUid);
    hkpWorldObject::addProperty(v4, UFG::physicsObjectPropertyTypeUid, (hkSimplePropertyValue)v5);
  }
  else
  {
LABEL_5:
    hkpWorldObject::addProperty(
      object,
      UFG::physicsObjectPropertyTypeUid,
      (hkSimplePropertyValue)objectPropertyHandleUid);
  }
}

// File Line: 960
// RVA: 0xAAD00
unsigned __int64 __fastcall UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(hkpWorldObject *object)
{
  __int64 v1; // r9
  int v2; // er8
  __int64 v3; // rdx
  hkSimpleProperty *v4; // rax

  v1 = object->m_properties.m_size;
  v2 = 0;
  v3 = 0i64;
  if ( v1 <= 0 )
    return 0i64;
  v4 = object->m_properties.m_data;
  while ( v4->m_key != UFG::physicsObjectPropertyTypeUid )
  {
    ++v3;
    ++v2;
    ++v4;
    if ( v3 >= v1 )
      return 0i64;
  }
  return object->m_properties.m_data[v2].m_value.m_data;
}

// File Line: 969
// RVA: 0xAAD50
unsigned __int64 __fastcall UFG::PhysicsPropertyManager::GetObjectPropertiesHandleUid(hkpWorldObject *object, hkpShape *shape, unsigned int shapeKey)
{
  unsigned int v3; // ebp
  hkpShape *v4; // rbx
  hkpWorldObject *v5; // rsi
  unsigned __int64 v6; // rdi
  __int64 v7; // rdi
  UFG::CollisionMeshData::Part *v8; // rax
  unsigned __int64 result; // rax
  __int64 v10; // r9
  int v11; // er8
  __int64 v12; // rdx
  hkSimpleProperty *v13; // rcx

  v3 = shapeKey;
  v4 = shape;
  v5 = object;
  if ( shape )
  {
    if ( shape->m_type.m_storage == 9 && *(_BYTE *)(shape[2].m_userData + 16) == 8 )
    {
      v6 = object->m_userData;
      if ( v6 )
      {
        v7 = *(_QWORD *)(v6 + 24);
        if ( v7 )
        {
          if ( UFG::SimComponent::IsType((UFG::SimComponent *)v7, UFG::RigidBody::_RigidBodyTypeUID) )
          {
            v8 = UFG::CollisionMeshData::GetPart(*(UFG::CollisionMeshData **)(v7 + 160), v3);
            return v8->mBaseProperty.objectPropertyHandleId;
          }
        }
      }
    }
    v8 = (UFG::CollisionMeshData::Part *)UFG::GetBaseProperty(v4, v3);
    if ( v8 )
      return v8->mBaseProperty.objectPropertyHandleId;
  }
  v10 = v5->m_properties.m_size;
  result = 0i64;
  v11 = 0;
  v12 = 0i64;
  if ( v10 > 0 )
  {
    v13 = v5->m_properties.m_data;
    while ( v13->m_key != UFG::physicsObjectPropertyTypeUid )
    {
      ++v12;
      ++v11;
      ++v13;
      if ( v12 >= v10 )
        return result;
    }
    result = v5->m_properties.m_data[v11].m_value.m_data;
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gObjectPropertiesNotifier__);
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
  return atexit(UFG::_dynamic_atexit_destructor_for__gSurfacePropertiesNotifier__);
}

// File Line: 1023
// RVA: 0xAE120
void __fastcall UFG::PhysicsPropertyManager::OnObjectPropertyChanged(char *object, UFG::qReflectField *field, UFG::qReflectType *field_type, char *field_data)
{
  char *v4; // r15
  hkpWorld *v5; // r13
  int v6; // ebp
  __int64 v7; // r12
  hkpSimulationIsland *v8; // r14
  int v9; // edi
  __int64 v10; // rsi
  unsigned __int64 v11; // rbx
  UFG::SimComponent *v12; // rbx
  __int64 v13; // rdx
  __int64 v14; // rdx
  UFG::qReflectHandleBase v15; // [rsp+28h] [rbp-50h]

  v4 = object;
  v5 = UFG::BasePhysicsSystem::mInstance->mWorld;
  v6 = 0;
  if ( v5->m_activeSimulationIslands.m_size > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v5->m_activeSimulationIslands.m_data[v7];
      v9 = 0;
      if ( v8->m_entities.m_size > 0 )
      {
        v10 = 0i64;
        do
        {
          v11 = v8->m_entities.m_data[v10]->m_userData;
          if ( v11 )
          {
            v12 = *(UFG::SimComponent **)(v11 + 24);
            if ( v12 )
            {
              if ( UFG::SimComponent::IsType(v12, UFG::RigidBody::_RigidBodyTypeUID) )
              {
                UFG::qReflectHandleBase::qReflectHandleBase(&v15);
                v15.mTypeUID = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
                v13 = *(_QWORD *)&v12[2].m_Flags;
                if ( v13 )
                  UFG::qReflectHandleBase::operator=(&v15, (UFG::qReflectHandleBase *)(v13 + 224));
                if ( (char *)v15.mData == v4 )
                {
                  ((void (__fastcall *)(UFG::SimComponent *))v12->vfptr[16].__vecDelDtor)(v12);
                  LOBYTE(v14) = 1;
                  v12->vfptr[15].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v12->vfptr, v14);
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
    while ( v6 < v5->m_activeSimulationIslands.m_size );
  }
}

// File Line: 1070
// RVA: 0xAE270
void __fastcall UFG::PhysicsPropertyManager::OnObjectReloaded(char *object, void *user_data)
{
  UFG::PhysicsPropertyManager::BuildLookupTrees();
}

// File Line: 1078
// RVA: 0xA1340
void UFG::PhysicsPropertyManager::BuildLookupTrees(void)
{
  Render::SkinningCacheNode *v0; // rbx
  Render::SkinningCacheNode *v1; // rbx
  unsigned __int64 v2; // rbx
  UFG::qReflectWarehouse *v3; // rax
  UFG::qReflectInventoryBase *v4; // rbp
  UFG::qReflectObject *v5; // r15
  UFG::qTree64Base *v6; // rax
  UFG::qReflectObject *v7; // rbx
  char *v8; // rax
  char *v9; // rsi
  const char *v10; // rax
  UFG::qTree64Base::BaseNode *v11; // rdi
  unsigned __int64 v12; // rbx
  unsigned __int64 v13; // rax
  UFG::qTree64Base *v14; // rax
  unsigned __int64 v15; // rbx
  UFG::qReflectWarehouse *v16; // rax
  UFG::qReflectInventoryBase *v17; // rax
  UFG::qTree64Base *v18; // rbp
  UFG::qTree64Base *v19; // rax
  signed __int64 v20; // rsi
  char *v21; // rax
  char *v22; // rbx
  const char *v23; // rax
  unsigned __int64 v24; // rdi
  unsigned __int64 v25; // rax
  UFG::qTree64Base *v26; // rax

  while ( UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree.mCount )
  {
    v0 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead((UFG::qTreeRB64<Render::SkinningCacheNode,Render::SkinningCacheNode,1> *)&UFG::PhysicsPropertyManager::sObjectPropertiesLookup);
    UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
      (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::PhysicsPropertyManager::sObjectPropertiesLookup,
      &v0->mNode);
    if ( v0 )
    {
      UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v0->mCachedBufferPtr);
      operator delete[](v0);
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
  v4 = UFG::qReflectWarehouse::GetInventory(v3, v2);
  v5 = UFG::qReflectInventoryBase::FindObjectByName(v4, "default");
  v6 = UFG::qTree64Base::GetHead(&v4->mItems.mTree);
  if ( v6 )
  {
    v7 = (UFG::qReflectObject *)&v6[-1].mCount;
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
        v10 = UFG::qReflectObject::GetName(v7);
        *((_DWORD *)v9 + 6) = UFG::qStringHashUpper32(v10, 0xFFFFFFFF);
        v11 = &v7->mBaseNode;
        v12 = v7->mBaseNode.mUID;
        v13 = UFG::qStringHash64("UFG::PhysicsSurfaceProperties", 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)(v9 + 32), v13, v12);
        UFG::qBaseTreeRB::Add(&UFG::PhysicsPropertyManager::sSurfacePropertiesLookup.mTree, (UFG::qBaseNodeRB *)v9);
        v14 = UFG::qTree64Base::GetNext(&v4->mItems.mTree, v11);
        if ( !v14 )
          break;
        v7 = (UFG::qReflectObject *)&v14[-1].mCount;
      }
      while ( v14 != (UFG::qTree64Base *)8 );
    }
  }
  v15 = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
  v16 = UFG::qReflectWarehouse::Instance();
  v17 = UFG::qReflectWarehouse::GetInventory(v16, v15);
  v18 = &v17->mItems.mTree;
  v19 = UFG::qTree64Base::GetHead(&v17->mItems.mTree);
  if ( v19 )
  {
    v20 = (signed __int64)&v19[-1].mCount;
    if ( v19 != (UFG::qTree64Base *)8 )
    {
      do
      {
        v21 = UFG::qMalloc(0x48ui64, UFG::gGlobalNewName, 0i64);
        v22 = v21;
        if ( v21 )
        {
          *(_QWORD *)v21 = 0i64;
          *((_QWORD *)v21 + 1) = 0i64;
          *((_QWORD *)v21 + 2) = 0i64;
          UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)(v21 + 32));
        }
        else
        {
          v22 = 0i64;
        }
        v23 = UFG::qReflectObject::GetName((UFG::qReflectObject *)v20);
        *((_DWORD *)v22 + 6) = UFG::qStringHashUpper32(v23, 0xFFFFFFFF);
        v24 = *(_QWORD *)(v20 + 8);
        v25 = UFG::qStringHash64("UFG::PhysicsObjectProperties", 0xFFFFFFFFFFFFFFFFui64);
        UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)(v22 + 32), v25, v24);
        UFG::qBaseTreeRB::Add(&UFG::PhysicsPropertyManager::sObjectPropertiesLookup.mTree, (UFG::qBaseNodeRB *)v22);
        if ( !*(_QWORD *)(v20 + 328) )
          UFG::qReflectHandleBase::Init(
            (UFG::qReflectHandleBase *)(v20 + 296),
            *(_QWORD *)(v20 + 312),
            v5->mBaseNode.mUID);
        v26 = UFG::qTree64Base::GetNext(v18, (UFG::qTree64Base::BaseNode *)(v20 + 8));
        if ( !v26 )
          break;
        v20 = (signed __int64)&v26[-1].mCount;
      }
      while ( v26 != (UFG::qTree64Base *)8 );
    }
  }
}

