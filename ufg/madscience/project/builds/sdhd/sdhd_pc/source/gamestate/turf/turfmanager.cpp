// File Line: 72
// RVA: 0x41BBE0
UFG::TurfManager *__fastcall UFG::TurfManager::Instance()
{
  if ( (_S6_7 & 1) == 0 )
  {
    _S6_7 |= 1u;
    staticInstance.mDebugDrawLocations.p = 0i64;
    *(_QWORD *)&staticInstance.mDebugDrawLocations.size = 0i64;
    staticInstance.mEmptyRackets_Small.p = 0i64;
    *(_QWORD *)&staticInstance.mEmptyRackets_Small.size = 0i64;
    staticInstance.mEmptyRackets_Medium.p = 0i64;
    *(_QWORD *)&staticInstance.mEmptyRackets_Medium.size = 0i64;
    staticInstance.mEmptyRackets_Large.p = 0i64;
    *(_QWORD *)&staticInstance.mEmptyRackets_Large.size = 0i64;
    staticInstance.mRacketUpdateTimer = 0.0;
    atexit(UFG::TurfManager::Instance_::_2_::_dynamic_atexit_destructor_for__staticInstance__);
  }
  return &staticInstance;
}

// File Line: 151
// RVA: 0x41AD50
UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> **__fastcall UFG::TurfManager::GetLocalPlayerTurf(
        UFG::TurfManager *this)
{
  unsigned int LocalPlayerOwnerPlayerId; // eax
  UFG::TurfInstanceData *TurfInstanceDataForPlayerId; // rax
  UFG::TurfInstanceData *v3; // rbx
  UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> **result; // rax

  LocalPlayerOwnerPlayerId = UFG::GameplayUtil::GetLocalPlayerOwnerPlayerId();
  TurfInstanceDataForPlayerId = UFG::PlaceholderGameDB::GetTurfInstanceDataForPlayerId(
                                  UFG::PlaceholderGameDB::ms_pSingleton,
                                  LocalPlayerOwnerPlayerId);
  v3 = TurfInstanceDataForPlayerId;
  if ( !TurfInstanceDataForPlayerId )
    return 0i64;
  if ( TurfInstanceDataForPlayerId->locationName.mStringHash32 == -1 )
    TurfInstanceDataForPlayerId->locationName.mStringHash32 = UFG::qStringHash32(
                                                                TurfInstanceDataForPlayerId->locationName.mData,
                                                                0xFFFFFFFF);
  result = &UFG::TurfComponent::s_TurfComponentList.mNode.mNext[-5].mNext;
  if ( &UFG::TurfComponent::s_TurfComponentList.mNode.mNext[-5].mNext == (UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> **)((char *)&UFG::TurfComponent::s_TurfComponentList - 72) )
    return 0i64;
  while ( *((_DWORD *)result + 7) != v3->locationName.mStringHash32 )
  {
    result = &result[10][-5].mNext;
    if ( result == (UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> **)((char *)&UFG::TurfComponent::s_TurfComponentList
                                                                        - 72) )
      return 0i64;
  }
  return result;
}

// File Line: 192
// RVA: 0x41B690
UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *__fastcall UFG::TurfManager::GetTurfTemplate(
        UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *result,
        char *templateID)
{
  const char *StaticTypeName; // rax
  unsigned __int64 v5; // rbx
  UFG::qReflectWarehouse *v6; // rax
  UFG::qReflectInventoryBase *Inventory; // rax
  UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *v8; // rcx
  const char *v9; // rax
  UFG::qReflectObject *ObjectByName; // rbx
  UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *v11; // rcx
  const char *v12; // rax
  UFG::qReflectHandleBase other; // [rsp+30h] [rbp-38h] BYREF

  StaticTypeName = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(result);
  v5 = UFG::qStringHash64(StaticTypeName, 0xFFFFFFFFFFFFFFFFui64);
  v6 = UFG::qReflectWarehouse::Instance();
  Inventory = UFG::qReflectWarehouse::GetInventory(v6, v5);
  if ( Inventory && (ObjectByName = UFG::qReflectInventoryBase::FindObjectByName(Inventory, templateID)) != 0i64 )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&other);
    v12 = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(v11);
    other.mTypeUID = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&other, other.mTypeUID, ObjectByName->mBaseNode.mUID);
    UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)result, &other);
    UFG::qReflectHandleBase::~qReflectHandleBase(&other);
  }
  else
  {
    UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)result);
    v9 = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(v8);
    result->mBaseNode.mParent = (UFG::qTree64Base::BaseNode *)UFG::qStringHash64(v9, 0xFFFFFFFFFFFFFFFFui64);
  }
  return result;
}

// File Line: 206
// RVA: 0x41B4E0
UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *__fastcall UFG::TurfManager::GetRacketType(
        UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *result,
        char *racketTypeID)
{
  const char *TypeName; // rax
  unsigned __int64 v5; // rbx
  UFG::qReflectWarehouse *v6; // rax
  UFG::qReflectInventoryBase *Inventory; // rax
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v8; // rcx
  const char *v9; // rax
  UFG::qReflectObject *ObjectByName; // rbx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v11; // rcx
  const char *v12; // rax
  UFG::qReflectHandleBase other; // [rsp+30h] [rbp-38h] BYREF

  TypeName = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(result);
  v5 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  v6 = UFG::qReflectWarehouse::Instance();
  Inventory = UFG::qReflectWarehouse::GetInventory(v6, v5);
  if ( Inventory && (ObjectByName = UFG::qReflectInventoryBase::FindObjectByName(Inventory, racketTypeID)) != 0i64 )
  {
    UFG::qReflectHandleBase::qReflectHandleBase(&other);
    v12 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v11);
    other.mTypeUID = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
    UFG::qReflectHandleBase::Init(&other, other.mTypeUID, ObjectByName->mBaseNode.mUID);
    UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)result, &other);
    UFG::qReflectHandleBase::~qReflectHandleBase(&other);
  }
  else
  {
    UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)result);
    v9 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v8);
    result->mBaseNode.mParent = (UFG::qTree64Base::BaseNode *)UFG::qStringHash64(v9, 0xFFFFFFFFFFFFFFFFui64);
  }
  return result;
}

// File Line: 354
// RVA: 0x41B610
UFG::qReflectHandle<UFG::RacketType> *__fastcall UFG::TurfManager::GetRandomEmptyRacketType(
        UFG::TurfManager *this,
        UFG::qReflectHandle<UFG::RacketType> *result,
        UFG::RacketType::eSize size)
{
  int v4; // r8d
  UFG::qArray<UFG::qReflectHandle<UFG::RacketType>,0> *p_mEmptyRackets_Large; // rbx
  int v6; // eax

  v4 = size - 1;
  if ( v4 )
  {
    if ( v4 == 1 )
      p_mEmptyRackets_Large = &this->mEmptyRackets_Large;
    else
      p_mEmptyRackets_Large = &this->mEmptyRackets_Small;
  }
  else
  {
    p_mEmptyRackets_Large = &this->mEmptyRackets_Medium;
  }
  v6 = UFG::qRandom(p_mEmptyRackets_Large->size, (unsigned int *)&UFG::qDefaultSeed);
  UFG::qReflectHandleBase::qReflectHandleBase(result, &p_mEmptyRackets_Large->p[v6]);
  return result;
}

