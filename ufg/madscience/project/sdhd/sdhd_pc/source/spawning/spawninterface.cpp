// File Line: 106
// RVA: 0x5B3EE0
UFG::qSymbol *__fastcall UFG::SpawnInfoInterface::GetSpawnPriority(
        UFG::qPropertySet *pPropSet,
        UFG::SpawnInfoInterface::SpawnPriority *pPriority)
{
  UFG::qSymbol *result; // rax
  UFG::qSymbol *v4; // rcx
  UFG::SpawnInfoInterface::SpawnPriority v5; // eax
  unsigned int mUID; // edx

  result = UFG::qPropertySet::Get<UFG::qSymbol>(
             pPropSet,
             (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnPriority,
             DEPTH_RECURSE);
  v4 = result;
  if ( pPriority )
  {
    v5 = UnReferenced;
    *pPriority = UnReferenced;
    if ( v4 )
    {
      mUID = v4->mUID;
      if ( v4->mUID != qSymbol_Critical.mUID )
      {
        if ( mUID == qSymbol_High.mUID )
        {
          *pPriority = Reserved;
          return v4;
        }
        if ( mUID == qSymbol_Medium.mUID )
        {
          *pPriority = Critical;
          return v4;
        }
        if ( mUID == qSymbol_Low.mUID )
          v5 = High;
      }
      *pPriority = v5;
    }
    return v4;
  }
  return result;
}

// File Line: 363
// RVA: 0x5B7410
UFG::SimObject *__fastcall UFG::SpawnInfoInterface::SpawnObject(
        UFG::qSymbol *objName,
        UFG::qPropertySet *parentSet,
        UFG::SpawnInfoInterface::SpawnPriority priority,
        UFG::SceneLayer *pOwnerLayer,
        UFG::SceneObjectProperties *pSpawnerSceneObj,
        UFG::SimObject *pOwner)
{
  UFG::SceneObjectProperties *v8; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mpOwner; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qStaticSymbol *v13; // r8

  v8 = UFG::SceneObjectProperties::Create(objName, pOwnerLayer, parentSet);
  if ( pOwner )
  {
    p_mpOwner = &v8->mpOwner;
    if ( v8->mpOwner.m_pPointer )
    {
      mPrev = p_mpOwner->mPrev;
      mNext = v8->mpOwner.mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      p_mpOwner->mPrev = p_mpOwner;
      v8->mpOwner.mNext = &v8->mpOwner;
    }
    v8->mpOwner.m_pPointer = pOwner;
    v12 = pOwner->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev;
    v12->mNext = p_mpOwner;
    p_mpOwner->mPrev = v12;
    v8->mpOwner.mNext = &pOwner->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode;
    pOwner->m_SafePointerList.UFG::qSafePointerNodeWithCallbacks<UFG::SimObject>::UFG::qSafePointerNode<UFG::SimObject>::mNode.mPrev = p_mpOwner;
  }
  if ( priority != Count )
  {
    switch ( priority )
    {
      case Reserved:
        v13 = &qSymbol_High;
        break;
      case Critical:
        v13 = &qSymbol_Medium;
        break;
      case High:
        v13 = &qSymbol_Low;
        break;
      default:
        v13 = &qSymbol_Critical;
        break;
    }
    PropertyUtils::SetRuntime<UFG::qSymbol>(v8, (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnPriority, v13);
  }
  return UFG::SpawnInfoInterface::ActivateObject(v8, priority, 0i64, pSpawnerSceneObj, parentSet, 3u, 0);
}

// File Line: 413
// RVA: 0x5B7310
UFG::SimObject *__fastcall UFG::SpawnInfoInterface::SpawnObject(
        UFG::qSymbol *objName,
        UFG::qSymbol *parentSetName,
        UFG::SpawnInfoInterface::SpawnPriority priority,
        UFG::SceneLayer *pOwnerLayer,
        UFG::SceneObjectProperties *pSpawnerSceneObj,
        UFG::SimObject *pOwner)
{
  UFG::qPropertySet *PropertySet; // rax

  PropertySet = UFG::PropertySetManager::GetPropertySet(parentSetName);
  return UFG::SpawnInfoInterface::SpawnObject(objName, PropertySet, priority, pOwnerLayer, pSpawnerSceneObj, pOwner);
}

// File Line: 441
// RVA: 0x5B7350
UFG::SimObject *__fastcall UFG::SpawnInfoInterface::SpawnObject(
        UFG::qSymbol *objName,
        UFG::qPropertySet *parentSet,
        UFG::qMatrix44 *xform,
        UFG::SpawnInfoInterface::SpawnPriority priority,
        UFG::SceneLayer *pOwnerLayer,
        UFG::SceneObjectProperties *pSpawnerSceneObj)
{
  UFG::SceneObjectProperties *v9; // rax
  UFG::SceneObjectProperties *v10; // rbx
  UFG::qStaticSymbol *v11; // r8

  v9 = UFG::SceneObjectProperties::Create(objName, 0i64, parentSet);
  v10 = v9;
  if ( priority != Count )
  {
    switch ( priority )
    {
      case Reserved:
        v11 = &qSymbol_High;
        break;
      case Critical:
        v11 = &qSymbol_Medium;
        break;
      case High:
        v11 = &qSymbol_Low;
        break;
      default:
        v11 = &qSymbol_Critical;
        break;
    }
    PropertyUtils::SetRuntime<UFG::qSymbol>(v9, (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnPriority, v11);
  }
  return UFG::SpawnInfoInterface::ActivateObject(v10, priority, xform, pSpawnerSceneObj, parentSet, 3u, 0);
}

// File Line: 479
// RVA: 0x5B72D0
UFG::SimObject *__fastcall UFG::SpawnInfoInterface::SpawnObject(
        UFG::qSymbol *objName,
        UFG::qSymbol *parentSetName,
        UFG::qMatrix44 *xform,
        UFG::SpawnInfoInterface::SpawnPriority priority,
        UFG::SceneLayer *pOwnerLayer,
        UFG::SceneObjectProperties *pSpawnerSceneObj)
{
  UFG::qPropertySet *PropertySet; // rax

  PropertySet = UFG::PropertySetManager::GetPropertySet(parentSetName);
  return UFG::SpawnInfoInterface::SpawnObject(objName, PropertySet, xform, priority, pOwnerLayer, pSpawnerSceneObj);
}

// File Line: 503
// RVA: 0x5B2830
UFG::SimObject *__fastcall UFG::SpawnInfoInterface::ActivateObject(
        UFG::SceneObjectProperties *pSpawnSceneObj,
        UFG::SpawnInfoInterface::SpawnPriority priority,
        UFG::qMatrix44 *pXformOverride,
        UFG::SceneObjectProperties *pSpawnerSceneObj,
        UFG::qPropertySet *pParentPropertySet,
        unsigned int activateFlags,
        bool called_from_script)
{
  UFG::SimObject *v10; // rbp
  char *v11; // rbx
  UFG::qSymbolUC *v12; // rax
  char *v13; // rdi
  UFG::qSymbolUC *v14; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp-18h] BYREF
  UFG::qWiseSymbol v17; // [rsp+34h] [rbp-14h] BYREF

  v10 = UFG::SceneObjectProperties::Activate(pSpawnSceneObj, activateFlags, pXformOverride, 0i64);
  if ( v10 )
  {
    UFG::SpawnInfoInterface::ClearSpawnLocation(pSpawnSceneObj, priority);
    UFG::SpawnInfoInterface::ActivateObjectPost(
      pSpawnSceneObj,
      priority,
      pSpawnerSceneObj,
      pParentPropertySet,
      called_from_script);
  }
  else
  {
    v11 = "<NULL>";
    if ( pSpawnSceneObj )
    {
      v12 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol(&result, pSpawnSceneObj->m_NameUID);
      v13 = UFG::qSymbol::as_cstr_dbg(v12);
    }
    else
    {
      v13 = "<NULL>";
    }
    if ( pSpawnerSceneObj )
    {
      v14 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol(&v17, pSpawnerSceneObj->m_NameUID);
      v11 = UFG::qSymbol::as_cstr_dbg(v14);
    }
    UFG::qPrintf("Spawn Object [%s] failed to spawn object [%s]\n", v11, v13);
  }
  return v10;
}

// File Line: 540
// RVA: 0x5B5700
void __fastcall UFG::SpawnInfoInterface::ReinitializeSpawnedObject(
        UFG::SpawnInfoInterface *this,
        UFG::SimObjectCharacter *pSpawnedObj,
        int priority,
        UFG::SceneObjectProperties *pSpawnerSceneObj,
        bool called_from_skookum)
{
  UFG::qPropertySet *ArchetypeProperties; // rax

  UFG::SimObjectUtility::ReinitializeSimObject(pSpawnedObj, 1, 0);
  ArchetypeProperties = (UFG::qPropertySet *)UFG::SceneObjectProperties::GetArchetypeProperties(pSpawnerSceneObj);
  UFG::SpawnInfoInterface::ActivateObjectPost(
    pSpawnedObj->m_pSceneObj,
    priority,
    pSpawnerSceneObj,
    ArchetypeProperties,
    called_from_skookum);
}

// File Line: 556
// RVA: 0x5B2E40
void __fastcall UFG::SpawnInfoInterface::ClearSpawnLocation(
        UFG::SceneObjectProperties *pSpawnSceneObj,
        UFG::SpawnInfoInterface::SpawnPriority priority)
{
  char *MemImagePtr; // rbx
  UFG::allocator::free_link *v5; // rax
  UFG::SensorPhantom *v6; // rax
  UFG::SimObject *m_pSimObject; // rax
  bool v8; // al
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *mpConstProperties; // rcx
  UFG::qPropertySet *v11; // rax
  UFG::SimObject *v12; // rbx
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  UFG::qMatrix44 *p_mWorldTransform; // rdx
  int *v15; // rax
  int v16; // xmm1_4
  int v17; // xmm2_4
  int v18; // xmm3_4
  int v19; // xmm1_4
  int v20; // xmm2_4
  int v21; // xmm3_4
  int v22; // xmm1_4
  int v23; // xmm2_4
  int v24; // xmm3_4
  int v25; // xmm1_4
  int v26; // xmm2_4
  int v27; // xmm3_4
  UFG::SimObjectGame *v28; // rax
  UFG::SimObject *v29; // rdi
  __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rax
  UFG::SpawnInfoInterface::SpawnPriority v32; // eax
  UFG::qWiseSymbol *v33; // rax
  char *v34; // rbx
  UFG::qWiseSymbol *v35; // rax
  char *v36; // rax
  UFG::qVector3 vmax; // [rsp+38h] [rbp-31h] BYREF
  UFG::qVector3 vmin; // [rsp+48h] [rbp-21h] BYREF
  hkAabb aabb; // [rsp+60h] [rbp-9h] BYREF
  int v40; // [rsp+80h] [rbp+17h]
  int v41; // [rsp+84h] [rbp+1Bh]
  int v42; // [rsp+88h] [rbp+1Fh]
  int v43; // [rsp+8Ch] [rbp+23h]
  int v44; // [rsp+90h] [rbp+27h]
  int v45; // [rsp+94h] [rbp+2Bh]
  int v46; // [rsp+98h] [rbp+2Fh]
  int v47; // [rsp+9Ch] [rbp+33h]
  UFG::allocator::free_link *prioritya; // [rsp+D0h] [rbp+67h] BYREF
  UFG::qSymbol result; // [rsp+E0h] [rbp+77h] BYREF
  UFG::qSymbol v50; // [rsp+E8h] [rbp+7Fh] BYREF

  MemImagePtr = 0i64;
  if ( !UFG::SpawnInfoInterface::mpSpawnSensor )
  {
    aabb.m_min = (hkVector4f)_xmm;
    aabb.m_max = (hkVector4f)_xmm;
    v5 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, 0x18ui64, "SensorPhantom", 0i64, 1u);
    prioritya = v5;
    if ( v5 )
      UFG::SensorPhantom::SensorPhantom((UFG::SensorPhantom *)v5, &aabb, 0x18u, "VehicleSpawnSensor");
    else
      v6 = 0i64;
    UFG::SpawnInfoInterface::mpSpawnSensor = v6;
  }
  m_pSimObject = pSpawnSceneObj->m_pSimObject;
  if ( m_pSimObject )
  {
    v8 = (m_pSimObject->m_Flags & 0x8000u) != 0;
  }
  else
  {
    mpWritableProperties = pSpawnSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSpawnSceneObj->mpConstProperties;
    v8 = UFG::qPropertySet::GetParentFromName(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&qSymbolX_propset_vehicle,
           DEPTH_RECURSE) != 0i64;
  }
  if ( v8 )
  {
    mpConstProperties = pSpawnSceneObj->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = pSpawnSceneObj->mpConstProperties;
    v11 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            mpConstProperties,
            (UFG::qArray<unsigned long,0> *)&component_PhysicsMover::sPropertyName,
            DEPTH_RECURSE);
    if ( v11 )
      MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v11);
    Scaleform::Render::WrapperImageSource::GetImageType(UFG::SpawnInfoInterface::mpSpawnSensor, &vmin, &vmax);
    Scaleform::Render::WrapperImageSource::GetFormat(
      (hkSubStreamWriter *)UFG::SpawnInfoInterface::mpSpawnSensor,
      MemImagePtr + 36,
      (_DWORD)MemImagePtr + 48);
    v12 = pSpawnSceneObj->m_pSimObject;
    if ( v12 )
    {
      m_pTransformNodeComponent = v12->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
      p_mWorldTransform = &m_pTransformNodeComponent->mWorldTransform;
    }
    else
    {
      v15 = (int *)PropertyUtils::Get<UFG::qMatrix44>(
                     pSpawnSceneObj,
                     (UFG::qArray<unsigned long,0> *)&SimSym_XformLocal);
      v16 = v15[1];
      v17 = v15[2];
      v18 = v15[3];
      aabb.m_min.m_quad.m128_i32[0] = *v15;
      *(unsigned __int64 *)((char *)aabb.m_min.m_quad.m128_u64 + 4) = __PAIR64__(v17, v16);
      aabb.m_min.m_quad.m128_i32[3] = v18;
      v19 = v15[5];
      v20 = v15[6];
      v21 = v15[7];
      aabb.m_max.m_quad.m128_i32[0] = v15[4];
      *(unsigned __int64 *)((char *)aabb.m_max.m_quad.m128_u64 + 4) = __PAIR64__(v20, v19);
      aabb.m_max.m_quad.m128_i32[3] = v21;
      v22 = v15[9];
      v23 = v15[10];
      v24 = v15[11];
      v40 = v15[8];
      v41 = v22;
      v42 = v23;
      v43 = v24;
      v25 = v15[13];
      v26 = v15[14];
      v27 = v15[15];
      v44 = v15[12];
      v45 = v25;
      v46 = v26;
      v47 = v27;
      p_mWorldTransform = (UFG::qMatrix44 *)&aabb;
    }
    UFG::SensorPhantom::SetTransform(UFG::SpawnInfoInterface::mpSpawnSensor, p_mWorldTransform);
    UFG::SensorPhantomIterator::SensorPhantomIterator(
      (UFG::SensorPhantomIterator *)&aabb,
      UFG::SpawnInfoInterface::mpSpawnSensor,
      0);
    while ( UFG::SensorPhantomIterator::operator*((UFG::SensorPhantomIterator *)&aabb) )
    {
      v28 = (UFG::SimObjectGame *)UFG::SensorPhantomIterator::operator*((UFG::SensorPhantomIterator *)&aabb);
      v29 = v28;
      if ( v28 && v28->m_pSceneObj )
      {
        m_Flags = v28->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::StreamedResourceComponent *)v28->m_Components.p[10].m_pComponent;
        }
        else if ( m_Flags >= 0 )
        {
          if ( (m_Flags & 0x2000) != 0 )
            m_pComponent = (UFG::StreamedResourceComponent *)v28->m_Components.p[7].m_pComponent;
          else
            m_pComponent = (UFG::StreamedResourceComponent *)((m_Flags & 0x1000) != 0
                                                            ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                v28,
                                                                UFG::StreamedResourceComponent::_TypeUID)
                                                            : UFG::SimObject::GetComponentOfType(
                                                                v28,
                                                                UFG::StreamedResourceComponent::_TypeUID));
        }
        else
        {
          m_pComponent = (UFG::StreamedResourceComponent *)v28->m_Components.p[10].m_pComponent;
        }
        if ( m_pComponent )
        {
          UFG::StreamedResourceComponent::GetSpawnPriority(
            m_pComponent,
            (UFG::SpawnInfoInterface::SpawnPriority *)&prioritya);
          v32 = (int)prioritya;
          if ( !(_DWORD)prioritya && priority == UnReferenced )
          {
            v33 = UFG::SceneObjectProperties::operator UFG::qSymbol const(v29->m_pSceneObj, (UFG::qWiseSymbol *)&result);
            v34 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v33);
            v35 = UFG::SceneObjectProperties::operator UFG::qSymbol const(pSpawnSceneObj, (UFG::qWiseSymbol *)&v50);
            v36 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)v35);
            UFG::qPrintf(
              "Mission spawn attempted over top of another mission spawn!  This needs to be resolved at the script level."
              " object spawning: %s, object in world: %s",
              v36,
              v34);
            v32 = (int)prioritya;
          }
          if ( v32 > priority )
            UFG::Simulation::DestroySimObject(&UFG::gSim, v29);
        }
      }
      UFG::SensorPhantomIterator::operator++((UFG::SensorPhantomIterator *)&aabb);
    }
    UFG::SensorPhantomIterator::~SensorPhantomIterator((UFG::SensorPhantomIterator *)&aabb);
    Scaleform::Render::WrapperImageSource::GetFormat(
      (hkSubStreamWriter *)UFG::SpawnInfoInterface::mpSpawnSensor,
      &vmin,
      (int)&vmax);
  }
}

// File Line: 650
// RVA: 0x5B2900
void __fastcall UFG::SpawnInfoInterface::ActivateObjectPost(
        UFG::SceneObjectProperties *pSpawnSceneObj,
        int priority,
        UFG::SceneObjectProperties *pSpawnerSceneObj,
        UFG::qPropertySet *pParentPropertySet,
        bool called_from_skookum)
{
  UFG::qPropertySet *mpWritableProperties; // rbp
  UFG::SimObjectCharacter *m_pSimObject; // rsi
  UFG::qPropertySet *mpConstProperties; // r14
  __int16 m_Flags; // cx
  bool canSuspend; // r15
  UFG::qPropertySet *WritablePersistentProperties; // rbx
  UFG::PedSpawnManager *Instance; // rax
  UFG::qPropertySet *v15; // rax
  UFG::qWiseSymbol IsAmbientRegionPed; // [rsp+20h] [rbp-48h]

  mpWritableProperties = pSpawnSceneObj->mpWritableProperties;
  m_pSimObject = (UFG::SimObjectCharacter *)pSpawnSceneObj->m_pSimObject;
  if ( !mpWritableProperties )
    mpWritableProperties = pSpawnSceneObj->mpConstProperties;
  if ( pSpawnerSceneObj )
  {
    mpConstProperties = pSpawnerSceneObj->mpWritableProperties;
    if ( !mpConstProperties )
      mpConstProperties = pSpawnerSceneObj->mpConstProperties;
  }
  else
  {
    mpConstProperties = 0i64;
  }
  m_Flags = m_pSimObject->m_Flags;
  if ( m_Flags >= 0 )
  {
    if ( (m_Flags & 0x4000) != 0 )
    {
      if ( UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>(m_pSimObject) )
      {
        if ( mpWritableProperties )
          canSuspend = UFG::SpawnInfoInterface::CanSuspend(mpWritableProperties);
        else
          canSuspend = 1;
        WritablePersistentProperties = UFG::SceneObjectProperties::GetWritablePersistentProperties(pSpawnSceneObj);
        Instance = UFG::PedSpawnManager::GetInstance();
        LOBYTE(IsAmbientRegionPed.mUID) = priority >= 1;
        UFG::PedSpawnManager::RegisterPed(
          Instance,
          m_pSimObject,
          pParentPropertySet,
          WritablePersistentProperties,
          IsAmbientRegionPed,
          canSuspend,
          called_from_skookum);
      }
      v15 = UFG::SpawnInfoInterface::ChooseAttachedProp(
              m_pSimObject,
              mpWritableProperties,
              mpConstProperties,
              priority > 1);
      if ( v15 )
        UFG::SimObjectUtility::CreateAndAttachProp(v15, (UFG::SimObjectProp *)m_pSimObject, 1);
    }
  }
  else
  {
    UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>((UFG::SimObjectVehicle *)m_pSimObject);
  }
}

// File Line: 767
// RVA: 0x5B2D60
UFG::qPropertySet *__fastcall UFG::SpawnInfoInterface::ChooseAttachedProp(
        UFG::SimObject *attachTo,
        UFG::qPropertySet *spawningSet,
        UFG::qPropertySet *spawnPointPropertySet,
        const bool only_if_loaded)
{
  UFG::PropSpawnManager *Instance; // rax
  UFG::qPropertySet *result; // rax
  UFG::qPropertyList *v9; // rax
  UFG::qPropertyList *v10; // rdi
  unsigned int RandomIndex; // eax
  UFG::qPropertySet *PropertySet; // rbx
  UFG::qSymbol *v13; // rax
  UFG::ObjectResourceManager *v14; // rax

  Instance = UFG::PropSpawnManager::GetInstance();
  result = UFG::PropSpawnManager::GetGlobalProp(Instance, spawningSet, spawnPointPropertySet);
  if ( !result )
  {
    v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(
           spawningSet,
           (UFG::qArray<unsigned long,0> *)&qSymbol_PropList,
           DEPTH_RECURSE);
    v10 = v9;
    if ( v9 && v9->mNumElements )
    {
      RandomIndex = UFG::qPropertyList::GetRandomIndex(v9);
      PropertySet = 0i64;
      v13 = UFG::qPropertyList::Get<UFG::qSymbol>(v10, RandomIndex);
      if ( v13->mUID != UFG::gNullQSymbol.mUID )
      {
        PropertySet = UFG::PropertySetManager::FindPropertySet(v13);
        if ( only_if_loaded )
        {
          v14 = UFG::ObjectResourceManager::Instance();
          if ( !UFG::ObjectResourceManager::CanSpawnAmbient(v14, PropertySet, 0i64, 0) )
            return 0i64;
        }
      }
      return PropertySet;
    }
    else
    {
      return 0i64;
    }
  }
  return result;
}

// File Line: 834
// RVA: 0x5B4DE0
bool __fastcall UFG::SpawnInfoInterface::IsCharacter(UFG::SceneObjectProperties *pSOP)
{
  UFG::SimObject *m_pSimObject; // rax
  int v2; // eax
  UFG::qPropertySet *mpWritableProperties; // rax

  m_pSimObject = pSOP->m_pSimObject;
  if ( m_pSimObject )
  {
    return (m_pSimObject->m_Flags >> 14) & 1;
  }
  else
  {
    mpWritableProperties = pSOP->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = pSOP->mpConstProperties;
    LOBYTE(v2) = UFG::qPropertySet::GetParentFromName(
                   mpWritableProperties,
                   (UFG::qArray<unsigned long,0> *)&qSymbolX_propset_character,
                   DEPTH_RECURSE) != 0i64;
  }
  return v2;
}

// File Line: 862
// RVA: 0x5B2D30
bool __fastcall UFG::SpawnInfoInterface::CanSuspend(UFG::qPropertySet *pSpawnPropertySet)
{
  bool *v1; // rax

  v1 = UFG::qPropertySet::Get<bool>(
         pSpawnPropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_CanSuspend,
         DEPTH_RECURSE);
  return !v1 || *v1;
}

// File Line: 875
// RVA: 0x5B58B0
bool __fastcall UFG::SpawnInfoInterface::ShouldLockActive(UFG::qPropertySet *pSpawnPropertySet)
{
  bool *v1; // rax

  v1 = UFG::qPropertySet::Get<bool>(
         pSpawnPropertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_LockActive,
         DEPTH_RECURSE);
  return v1 && *v1;
}

// File Line: 888
// RVA: 0x5B5860
void __fastcall UFG::SpawnInfoInterface::SetOwner(
        UFG::SimObject *pTarget,
        UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *pOwner)
{
  UFG::SceneObjectProperties *m_pSceneObj; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *p_mpOwner; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  if ( pTarget )
  {
    m_pSceneObj = pTarget->m_pSceneObj;
    if ( m_pSceneObj )
    {
      p_mpOwner = &m_pSceneObj->mpOwner;
      if ( p_mpOwner[1].mPrev )
      {
        mPrev = p_mpOwner->mPrev;
        mNext = p_mpOwner->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mpOwner->mPrev = p_mpOwner;
        p_mpOwner->mNext = p_mpOwner;
      }
      p_mpOwner[1].mPrev = pOwner;
      if ( pOwner )
      {
        v6 = pOwner->mNext;
        v6->mNext = p_mpOwner;
        p_mpOwner->mPrev = v6;
        p_mpOwner->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&pOwner->mNext;
        pOwner->mNext = p_mpOwner;
      }
    }
  }
}

// File Line: 904
// RVA: 0x5B1940
void __fastcall UFG::SpawnPointInterface::SpawnPointInterface(
        UFG::SpawnPointInterface *this,
        UFG::qSymbol *name,
        UFG::SimObject *pSimObj)
{
  UFG::MarkerBase::MarkerBase(this, name, pSimObj, 0x30000u);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnPointInterface::`vftable;
}

