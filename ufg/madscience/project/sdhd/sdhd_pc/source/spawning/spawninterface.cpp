// File Line: 106
// RVA: 0x5B3EE0
UFG::qSymbol *__fastcall UFG::SpawnInfoInterface::GetSpawnPriority(UFG::qPropertySet *pPropSet, UFG::SpawnInfoInterface::SpawnPriority *pPriority)
{
  UFG::SpawnInfoInterface::SpawnPriority *v2; // rbx
  UFG::qSymbol *result; // rax
  UFG::qSymbol *v4; // rcx
  signed int v5; // eax
  UFG::qSymbol v6; // edx

  v2 = pPriority;
  result = UFG::qPropertySet::Get<UFG::qSymbol>(pPropSet, (UFG::qSymbol *)&qSymbol_SpawnPriority.mUID, DEPTH_RECURSE);
  v4 = result;
  if ( v2 )
  {
    v5 = 0;
    *v2 = 0;
    if ( v4 )
    {
      v6.mUID = v4->mUID;
      if ( v4->mUID != qSymbol_Critical.mUID )
      {
        if ( v6.mUID == qSymbol_High.mUID )
        {
          *v2 = 1;
          return v4;
        }
        if ( v6.mUID == qSymbol_Medium.mUID )
        {
          *v2 = 2;
          return v4;
        }
        if ( v6.mUID == qSymbol_Low.mUID )
          v5 = 3;
      }
      *v2 = v5;
    }
    result = v4;
  }
  return result;
}

// File Line: 363
// RVA: 0x5B7410
UFG::SimObject *__fastcall UFG::SpawnInfoInterface::SpawnObject(UFG::qSymbol *objName, UFG::qPropertySet *parentSet, UFG::SpawnInfoInterface::SpawnPriority priority, UFG::SceneLayer *pOwnerLayer, UFG::SceneObjectProperties *pSpawnerSceneObj, UFG::SimObject *pOwner)
{
  UFG::SpawnInfoInterface::SpawnPriority v6; // edi
  UFG::qPropertySet *pParentPropertySet; // rsi
  UFG::SceneObjectProperties *v8; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v9; // r9
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v10; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v12; // rax
  UFG::qStaticSymbol *v13; // r8

  v6 = priority;
  pParentPropertySet = parentSet;
  v8 = UFG::SceneObjectProperties::Create(objName, pOwnerLayer, parentSet);
  if ( pOwner )
  {
    v9 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mpOwner.mPrev;
    if ( v8->mpOwner.m_pPointer )
    {
      v10 = v9->mPrev;
      v11 = v8->mpOwner.mNext;
      v10->mNext = v11;
      v11->mPrev = v10;
      v9->mPrev = v9;
      v8->mpOwner.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v8->mpOwner.mPrev;
    }
    v8->mpOwner.m_pPointer = pOwner;
    v12 = pOwner->m_SafePointerList.mNode.mPrev;
    v12->mNext = v9;
    v9->mPrev = v12;
    v8->mpOwner.mNext = &pOwner->m_SafePointerList.mNode;
    pOwner->m_SafePointerList.mNode.mPrev = v9;
  }
  if ( v6 != 5 )
  {
    switch ( v6 )
    {
      case 1:
        v13 = &qSymbol_High;
        goto LABEL_14;
      case 2:
        v13 = &qSymbol_Medium;
        goto LABEL_14;
      case 3:
        v13 = &qSymbol_Low;
        goto LABEL_14;
    }
    if ( v6 != 5 )
    {
      v13 = &qSymbol_Critical;
LABEL_14:
      PropertyUtils::SetRuntime<UFG::qSymbol>(
        v8,
        (UFG::qSymbol *)&qSymbol_SpawnPriority.mUID,
        (UFG::qSymbol *)&v13->mUID);
      return UFG::SpawnInfoInterface::ActivateObject(v8, v6, 0i64, pSpawnerSceneObj, pParentPropertySet, 3u, 0);
    }
  }
  return UFG::SpawnInfoInterface::ActivateObject(v8, v6, 0i64, pSpawnerSceneObj, pParentPropertySet, 3u, 0);
}

// File Line: 413
// RVA: 0x5B7310
UFG::SimObject *__fastcall UFG::SpawnInfoInterface::SpawnObject(UFG::qSymbol *objName, UFG::qSymbol *parentSetName, UFG::SpawnInfoInterface::SpawnPriority priority, UFG::SceneLayer *pOwnerLayer, UFG::SceneObjectProperties *pSpawnerSceneObj, UFG::SimObject *pOwner)
{
  UFG::qSymbol *v6; // rbx
  UFG::SceneLayer *v7; // rdi
  UFG::SpawnInfoInterface::SpawnPriority v8; // esi
  UFG::qPropertySet *v9; // rax

  v6 = objName;
  v7 = pOwnerLayer;
  v8 = priority;
  v9 = UFG::PropertySetManager::GetPropertySet(parentSetName);
  return UFG::SpawnInfoInterface::SpawnObject(v6, v9, v8, v7, pSpawnerSceneObj, pOwner);
}

// File Line: 441
// RVA: 0x5B7350
UFG::SimObject *__fastcall UFG::SpawnInfoInterface::SpawnObject(UFG::qSymbol *objName, UFG::qPropertySet *parentSet, UFG::qMatrix44 *xform, UFG::SpawnInfoInterface::SpawnPriority priority, UFG::SceneLayer *pOwnerLayer, UFG::SceneObjectProperties *pSpawnerSceneObj)
{
  UFG::qMatrix44 *v6; // rbp
  UFG::qPropertySet *pParentPropertySet; // rsi
  UFG::SpawnInfoInterface::SpawnPriority v8; // edi
  UFG::SceneObjectProperties *v9; // rax
  UFG::SceneObjectProperties *v10; // rbx
  UFG::qStaticSymbol *v11; // r8

  v6 = xform;
  pParentPropertySet = parentSet;
  v8 = priority;
  v9 = UFG::SceneObjectProperties::Create(objName, 0i64, parentSet);
  v10 = v9;
  if ( v8 != Count )
  {
    switch ( v8 )
    {
      case 1:
        v11 = &qSymbol_High;
        goto LABEL_10;
      case 2:
        v11 = &qSymbol_Medium;
        goto LABEL_10;
      case 3:
        v11 = &qSymbol_Low;
        goto LABEL_10;
    }
    if ( v8 != Count )
    {
      v11 = &qSymbol_Critical;
LABEL_10:
      PropertyUtils::SetRuntime<UFG::qSymbol>(
        v9,
        (UFG::qSymbol *)&qSymbol_SpawnPriority.mUID,
        (UFG::qSymbol *)&v11->mUID);
      return UFG::SpawnInfoInterface::ActivateObject(v10, v8, v6, pSpawnerSceneObj, pParentPropertySet, 3u, 0);
    }
  }
  return UFG::SpawnInfoInterface::ActivateObject(v10, v8, v6, pSpawnerSceneObj, pParentPropertySet, 3u, 0);
}

// File Line: 479
// RVA: 0x5B72D0
UFG::SimObject *__fastcall UFG::SpawnInfoInterface::SpawnObject(UFG::qSymbol *objName, UFG::qSymbol *parentSetName, UFG::qMatrix44 *xform, UFG::SpawnInfoInterface::SpawnPriority priority, UFG::SceneLayer *pOwnerLayer, UFG::SceneObjectProperties *pSpawnerSceneObj)
{
  UFG::qSymbol *v6; // rbx
  UFG::SpawnInfoInterface::SpawnPriority v7; // edi
  UFG::qMatrix44 *v8; // rsi
  UFG::qPropertySet *v9; // rax

  v6 = objName;
  v7 = priority;
  v8 = xform;
  v9 = UFG::PropertySetManager::GetPropertySet(parentSetName);
  return UFG::SpawnInfoInterface::SpawnObject(v6, v9, v8, v7, pOwnerLayer, pSpawnerSceneObj);
}

// File Line: 503
// RVA: 0x5B2830
UFG::SimObject *__fastcall UFG::SpawnInfoInterface::ActivateObject(UFG::SceneObjectProperties *pSpawnSceneObj, UFG::SpawnInfoInterface::SpawnPriority priority, UFG::qMatrix44 *pXformOverride, UFG::SceneObjectProperties *pSpawnerSceneObj, UFG::qPropertySet *pParentPropertySet, unsigned int activateFlags, bool called_from_script)
{
  UFG::SpawnInfoInterface::SpawnPriority v7; // ebx
  UFG::SceneObjectProperties *v8; // rsi
  UFG::SceneObjectProperties *v9; // rdi
  UFG::SimObject *v10; // rbp
  char *v11; // rbx
  UFG::qSymbolUC *v12; // rax
  char *v13; // rdi
  UFG::qSymbolUC *v14; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp-18h]
  UFG::qWiseSymbol v17; // [rsp+34h] [rbp-14h]

  v7 = priority;
  v8 = pSpawnerSceneObj;
  v9 = pSpawnSceneObj;
  v10 = UFG::SceneObjectProperties::Activate(pSpawnSceneObj, activateFlags, pXformOverride, 0i64);
  if ( v10 )
  {
    UFG::SpawnInfoInterface::ClearSpawnLocation(v9, v7);
    UFG::SpawnInfoInterface::ActivateObjectPost(v9, v7, v8, pParentPropertySet, called_from_script);
  }
  else
  {
    v11 = "<NULL>";
    if ( v9 )
    {
      v12 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol(&result, v9->m_NameUID);
      v13 = UFG::qSymbol::as_cstr_dbg(v12);
    }
    else
    {
      v13 = "<NULL>";
    }
    if ( v8 )
    {
      v14 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol(&v17, v8->m_NameUID);
      v11 = UFG::qSymbol::as_cstr_dbg(v14);
    }
    UFG::qPrintf("Spawn Object [%s] failed to spawn object [%s]\n", v11, v13);
  }
  return v10;
}

// File Line: 540
// RVA: 0x5B5700
void __fastcall UFG::SpawnInfoInterface::ReinitializeSpawnedObject(UFG::SpawnInfoInterface *this, UFG::SimObject *pSpawnedObj, UFG::SpawnInfoInterface::SpawnPriority priority, UFG::SceneObjectProperties *pSpawnerSceneObj, bool called_from_skookum)
{
  UFG::SimObject *v5; // rsi
  UFG::SpawnInfoInterface::SpawnPriority v6; // edi
  UFG::SceneObjectProperties *v7; // rbx
  UFG::qPropertySet *v8; // rax

  v5 = pSpawnedObj;
  v6 = priority;
  v7 = pSpawnerSceneObj;
  UFG::SimObjectUtility::ReinitializeSimObject(pSpawnedObj, 1, 0);
  v8 = (UFG::qPropertySet *)UFG::SceneObjectProperties::GetArchetypeProperties(v7);
  UFG::SpawnInfoInterface::ActivateObjectPost(v5->m_pSceneObj, v6, v7, v8, called_from_skookum);
}

// File Line: 556
// RVA: 0x5B2E40
void __fastcall UFG::SpawnInfoInterface::ClearSpawnLocation(UFG::SceneObjectProperties *pSpawnSceneObj, UFG::SpawnInfoInterface::SpawnPriority priority)
{
  UFG::SpawnInfoInterface::SpawnPriority v2; // er14
  UFG::SceneObjectProperties *v3; // rsi
  char *v4; // rbx
  UFG::allocator::free_link *v5; // rax
  UFG::SensorPhantom *v6; // rax
  UFG::SimObject *v7; // rax
  bool v8; // al
  UFG::qPropertySet *v9; // rcx
  UFG::qPropertySet *v10; // rcx
  UFG::qPropertySet *v11; // rax
  UFG::SimObject *v12; // rbx
  UFG::TransformNodeComponent *v13; // rbx
  UFG::qMatrix44 *v14; // rdx
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
  unsigned __int16 v30; // dx
  UFG::StreamedResourceComponent *v31; // rax
  UFG::SpawnInfoInterface::SpawnPriority v32; // eax
  UFG::qSymbolUC *v33; // rax
  char *v34; // rbx
  UFG::qSymbolUC *v35; // rax
  char *v36; // rax
  UFG::qVector3 vmax; // [rsp+38h] [rbp-31h]
  UFG::qVector3 vmin; // [rsp+48h] [rbp-21h]
  hkAabb aabb; // [rsp+60h] [rbp-9h]
  int v40; // [rsp+80h] [rbp+17h]
  int v41; // [rsp+84h] [rbp+1Bh]
  int v42; // [rsp+88h] [rbp+1Fh]
  int v43; // [rsp+8Ch] [rbp+23h]
  int v44; // [rsp+90h] [rbp+27h]
  int v45; // [rsp+94h] [rbp+2Bh]
  int v46; // [rsp+98h] [rbp+2Fh]
  int v47; // [rsp+9Ch] [rbp+33h]
  UFG::allocator::free_link *prioritya; // [rsp+D0h] [rbp+67h]
  UFG::qSymbol result; // [rsp+E0h] [rbp+77h]
  UFG::qSymbol v50; // [rsp+E8h] [rbp+7Fh]

  v2 = priority;
  v3 = pSpawnSceneObj;
  v4 = 0i64;
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
  v7 = v3->m_pSimObject;
  if ( v7 )
  {
    v8 = (v7->m_Flags & 0x8000u) != 0;
  }
  else
  {
    v9 = v3->mpWritableProperties;
    if ( !v9 )
      v9 = v3->mpConstProperties;
    v8 = UFG::qPropertySet::GetParentFromName(v9, (UFG::qSymbol *)&qSymbolX_propset_vehicle.mUID, DEPTH_RECURSE) != 0i64;
  }
  if ( v8 )
  {
    v10 = v3->mpWritableProperties;
    if ( !v10 )
      v10 = v3->mpConstProperties;
    v11 = UFG::qPropertySet::Get<UFG::qPropertySet>(
            v10,
            (UFG::qSymbol *)&component_PhysicsMover::sPropertyName.mUID,
            DEPTH_RECURSE);
    if ( v11 )
      v4 = UFG::qPropertySet::GetMemImagePtr(v11);
    Scaleform::Render::WrapperImageSource::GetImageType(UFG::SpawnInfoInterface::mpSpawnSensor, &vmin, &vmax);
    Scaleform::Render::WrapperImageSource::GetFormat(
      (hkSubStreamWriter *)UFG::SpawnInfoInterface::mpSpawnSensor,
      v4 + 36,
      (_DWORD)v4 + 48);
    v12 = v3->m_pSimObject;
    if ( v12 )
    {
      v13 = v12->m_pTransformNodeComponent;
      UFG::TransformNodeComponent::UpdateWorldTransform(v13);
      v14 = &v13->mWorldTransform;
    }
    else
    {
      v15 = (int *)PropertyUtils::Get<UFG::qMatrix44>(v3, (UFG::qSymbol *)&SimSym_XformLocal.mUID);
      v16 = v15[1];
      v17 = v15[2];
      v18 = v15[3];
      aabb.m_min.m_quad.m128_i32[0] = *v15;
      *(unsigned __int64 *)((char *)aabb.m_min.m_quad.m128_u64 + 4) = __PAIR__(v17, v16);
      aabb.m_min.m_quad.m128_i32[3] = v18;
      v19 = v15[5];
      v20 = v15[6];
      v21 = v15[7];
      aabb.m_max.m_quad.m128_i32[0] = v15[4];
      *(unsigned __int64 *)((char *)aabb.m_max.m_quad.m128_u64 + 4) = __PAIR__(v20, v19);
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
      v14 = (UFG::qMatrix44 *)&aabb;
    }
    UFG::SensorPhantom::SetTransform(UFG::SpawnInfoInterface::mpSpawnSensor, v14);
    UFG::SensorPhantomIterator::SensorPhantomIterator(
      (UFG::SensorPhantomIterator *)&aabb,
      UFG::SpawnInfoInterface::mpSpawnSensor,
      0);
    while ( UFG::SensorPhantomIterator::operator*((UFG::SensorPhantomIterator *)&aabb) )
    {
      v28 = (UFG::SimObjectGame *)UFG::SensorPhantomIterator::operator*((UFG::SensorPhantomIterator *)&aabb);
      v29 = (UFG::SimObject *)&v28->vfptr;
      if ( v28 && v28->m_pSceneObj )
      {
        v30 = v28->m_Flags;
        if ( (v30 >> 14) & 1 )
        {
          v31 = (UFG::StreamedResourceComponent *)v28->m_Components.p[10].m_pComponent;
        }
        else if ( (v30 & 0x8000u) == 0 )
        {
          if ( (v30 >> 13) & 1 )
            v31 = (UFG::StreamedResourceComponent *)v28->m_Components.p[7].m_pComponent;
          else
            v31 = (UFG::StreamedResourceComponent *)((v30 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                                                         v28,
                                                                         UFG::StreamedResourceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v28->vfptr, UFG::StreamedResourceComponent::_TypeUID));
        }
        else
        {
          v31 = (UFG::StreamedResourceComponent *)v28->m_Components.p[10].m_pComponent;
        }
        if ( v31 )
        {
          UFG::StreamedResourceComponent::GetSpawnPriority(v31, (UFG::SpawnInfoInterface::SpawnPriority *)&prioritya);
          v32 = (signed int)prioritya;
          if ( !(_DWORD)prioritya && v2 == UnReferenced )
          {
            v33 = (UFG::qSymbolUC *)UFG::SceneObjectProperties::operator UFG::qSymbol const(v29->m_pSceneObj, &result);
            v34 = UFG::qSymbol::as_cstr_dbg(v33);
            v35 = (UFG::qSymbolUC *)UFG::SceneObjectProperties::operator UFG::qSymbol const(v3, &v50);
            v36 = UFG::qSymbol::as_cstr_dbg(v35);
            UFG::qPrintf(
              "Mission spawn attempted over top of another mission spawn!  This needs to be resolved at the script level."
              " object spawning: %s, object in world: %s",
              v36,
              v34);
            v32 = (signed int)prioritya;
          }
          if ( v32 > v2 )
            UFG::Simulation::DestroySimObject(&UFG::gSim, v29);
        }
      }
      UFG::SensorPhantomIterator::operator++((UFG::SensorPhantomIterator *)&aabb);
    }
    UFG::SensorPhantomIterator::~SensorPhantomIterator((UFG::SensorPhantomIterator *)&aabb);
    Scaleform::Render::WrapperImageSource::GetFormat(
      (hkSubStreamWriter *)UFG::SpawnInfoInterface::mpSpawnSensor,
      &vmin,
      (unsigned __int64)&vmax);
  }
}

// File Line: 650
// RVA: 0x5B2900
void __fastcall UFG::SpawnInfoInterface::ActivateObjectPost(UFG::SceneObjectProperties *pSpawnSceneObj, UFG::SpawnInfoInterface::SpawnPriority priority, UFG::SceneObjectProperties *pSpawnerSceneObj, UFG::qPropertySet *pParentPropertySet, bool called_from_skookum)
{
  UFG::qPropertySet *v5; // rbp
  UFG::SimObjectCharacter *v6; // rsi
  UFG::qPropertySet *v7; // r13
  UFG::SpawnInfoInterface::SpawnPriority v8; // er12
  UFG::SceneObjectProperties *v9; // rbx
  UFG::qPropertySet *v10; // r14
  unsigned __int16 v11; // cx
  bool canSuspend; // r15
  UFG::qPropertySet *v13; // rbx
  UFG::PedSpawnManager *v14; // rax
  UFG::qPropertySet *v15; // rax

  v5 = pSpawnSceneObj->mpWritableProperties;
  v6 = (UFG::SimObjectCharacter *)pSpawnSceneObj->m_pSimObject;
  v7 = pParentPropertySet;
  v8 = priority;
  v9 = pSpawnSceneObj;
  if ( !v5 )
    v5 = pSpawnSceneObj->mpConstProperties;
  if ( pSpawnerSceneObj )
  {
    v10 = pSpawnerSceneObj->mpWritableProperties;
    if ( !v10 )
      v10 = pSpawnerSceneObj->mpConstProperties;
  }
  else
  {
    v10 = 0i64;
  }
  v11 = v6->m_Flags;
  if ( (v11 & 0x8000u) == 0 )
  {
    if ( (v11 >> 14) & 1 )
    {
      if ( UFG::SimObjectCVBase::GetComponent<UFG::SimObjectCharacterPropertiesComponent>((UFG::SimObjectCVBase *)&v6->vfptr) )
      {
        if ( v5 )
          canSuspend = UFG::SpawnInfoInterface::CanSuspend(v5);
        else
          canSuspend = 1;
        v13 = UFG::SceneObjectProperties::GetWritablePersistentProperties(v9);
        v14 = UFG::PedSpawnManager::GetInstance();
        UFG::PedSpawnManager::RegisterPed(v14, v6, v7, v13, (signed int)v8 >= 1, canSuspend, called_from_skookum);
      }
      v15 = UFG::SpawnInfoInterface::ChooseAttachedProp((UFG::SimObject *)&v6->vfptr, v5, v10, (signed int)v8 > 1);
      if ( v15 )
        UFG::SimObjectUtility::CreateAndAttachProp(v15, (UFG::SimObject *)&v6->vfptr, 1);
    }
  }
  else
  {
    UFG::SimObjectVehicle::GetComponent<UFG::CarPhysicsMoverComponent>((UFG::SimObjectVehicle *)v6);
  }
}

// File Line: 767
// RVA: 0x5B2D60
UFG::qPropertySet *__fastcall UFG::SpawnInfoInterface::ChooseAttachedProp(UFG::SimObject *attachTo, UFG::qPropertySet *spawningSet, UFG::qPropertySet *spawnPointPropertySet, const bool only_if_loaded)
{
  bool v4; // si
  UFG::qPropertySet *v5; // rbx
  UFG::qPropertySet *v6; // rdi
  UFG::PropSpawnManager *v7; // rax
  UFG::qPropertySet *result; // rax
  UFG::qPropertyList *v9; // rax
  UFG::qPropertyList *v10; // rdi
  unsigned int v11; // eax
  UFG::qPropertySet *v12; // rbx
  UFG::qSymbol *v13; // rax
  UFG::ObjectResourceManager *v14; // rax

  v4 = only_if_loaded;
  v5 = spawnPointPropertySet;
  v6 = spawningSet;
  v7 = UFG::PropSpawnManager::GetInstance();
  result = UFG::PropSpawnManager::GetGlobalProp(v7, v6, v5);
  if ( !result )
  {
    v9 = UFG::qPropertySet::Get<UFG::qPropertyList>(v6, (UFG::qSymbol *)&qSymbol_PropList.mUID, DEPTH_RECURSE);
    v10 = v9;
    if ( v9 && v9->mNumElements )
    {
      v11 = UFG::qPropertyList::GetRandomIndex(v9);
      v12 = 0i64;
      v13 = UFG::qPropertyList::Get<UFG::qSymbol>(v10, v11);
      if ( v13->mUID != UFG::gNullQSymbol.mUID )
      {
        v12 = UFG::PropertySetManager::FindPropertySet(v13);
        if ( v4 )
        {
          v14 = UFG::ObjectResourceManager::Instance();
          if ( !UFG::ObjectResourceManager::CanSpawnAmbient(v14, v12, 0i64, 0) )
            v12 = 0i64;
        }
      }
      result = v12;
    }
    else
    {
      result = 0i64;
    }
  }
  return result;
}

// File Line: 834
// RVA: 0x5B4DE0
bool __fastcall UFG::SpawnInfoInterface::IsCharacter(UFG::SceneObjectProperties *pSOP)
{
  UFG::SimObject *v1; // rax
  unsigned int v2; // eax
  UFG::qPropertySet *v3; // rax

  v1 = pSOP->m_pSimObject;
  if ( v1 )
  {
    v2 = ((unsigned int)v1->m_Flags >> 14) & 1;
  }
  else
  {
    v3 = pSOP->mpWritableProperties;
    if ( !v3 )
      v3 = pSOP->mpConstProperties;
    LOBYTE(v2) = UFG::qPropertySet::GetParentFromName(
                   v3,
                   (UFG::qSymbol *)&qSymbolX_propset_character.mUID,
                   DEPTH_RECURSE) != 0i64;
  }
  return v2;
}

// File Line: 862
// RVA: 0x5B2D30
bool __fastcall UFG::SpawnInfoInterface::CanSuspend(UFG::qPropertySet *pSpawnPropertySet)
{
  bool *v1; // rax

  v1 = UFG::qPropertySet::Get<bool>(pSpawnPropertySet, (UFG::qSymbol *)&qSymbol_CanSuspend.mUID, DEPTH_RECURSE);
  return !v1 || *v1 == 1;
}

// File Line: 875
// RVA: 0x5B58B0
bool __fastcall UFG::SpawnInfoInterface::ShouldLockActive(UFG::qPropertySet *pSpawnPropertySet)
{
  bool *v1; // rax

  v1 = UFG::qPropertySet::Get<bool>(pSpawnPropertySet, (UFG::qSymbol *)&qSymbol_LockActive.mUID, DEPTH_RECURSE);
  return v1 && *v1;
}

// File Line: 888
// RVA: 0x5B5860
void __fastcall UFG::SpawnInfoInterface::SetOwner(UFG::SimObject *pTarget, UFG::SimObject *pOwner)
{
  UFG::SceneObjectProperties *v2; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v3; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v6; // rax

  if ( pTarget )
  {
    v2 = pTarget->m_pSceneObj;
    if ( v2 )
    {
      v3 = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v2->mpOwner.mPrev;
      if ( v3[1].mPrev )
      {
        v4 = v3->mPrev;
        v5 = v3->mNext;
        v4->mNext = v5;
        v5->mPrev = v4;
        v3->mPrev = v3;
        v3->mNext = v3;
      }
      v3[1].mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)pOwner;
      if ( pOwner )
      {
        v6 = pOwner->m_SafePointerList.mNode.mPrev;
        v6->mNext = v3;
        v3->mPrev = v6;
        v3->mNext = &pOwner->m_SafePointerList.mNode;
        pOwner->m_SafePointerList.mNode.mPrev = v3;
      }
    }
  }
}

// File Line: 904
// RVA: 0x5B1940
void __fastcall UFG::SpawnPointInterface::SpawnPointInterface(UFG::SpawnPointInterface *this, UFG::qSymbol *name, UFG::SimObject *pSimObj)
{
  UFG::SpawnPointInterface *v3; // rbx

  v3 = this;
  UFG::MarkerBase::MarkerBase((UFG::MarkerBase *)&this->vfptr, name, pSimObj, 0x30000u);
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::SpawnPointInterface::`vftable;
}

