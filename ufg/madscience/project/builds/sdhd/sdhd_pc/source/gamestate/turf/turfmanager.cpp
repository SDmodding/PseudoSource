// File Line: 72
// RVA: 0x41BBE0
UFG::TurfManager *__fastcall UFG::TurfManager::Instance()
{
  if ( !(_S6_7 & 1) )
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
UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> **__fastcall UFG::TurfManager::GetLocalPlayerTurf(UFG::TurfManager *this)
{
  unsigned int v1; // eax
  UFG::TurfInstanceData *v2; // rax
  UFG::TurfInstanceData *v3; // rbx
  UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> **result; // rax

  v1 = UFG::GameplayUtil::GetLocalPlayerOwnerPlayerId();
  v2 = UFG::PlaceholderGameDB::GetTurfInstanceDataForPlayerId(UFG::PlaceholderGameDB::ms_pSingleton, v1);
  v3 = v2;
  if ( !v2 )
    return 0i64;
  if ( v2->locationName.mStringHash32 == -1 )
    v2->locationName.mStringHash32 = UFG::qStringHash32(v2->locationName.mData, 0xFFFFFFFF);
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
UFG::qReflectHandle<UFG::TurfTemplate> *__fastcall UFG::TurfManager::GetTurfTemplate(UFG::qReflectHandle<UFG::TurfTemplate> *result, const char *templateID)
{
  const char *v2; // rsi
  UFG::qReflectHandle<UFG::TurfTemplate> *v3; // rdi
  const char *v4; // rax
  unsigned __int64 v5; // rbx
  UFG::qReflectWarehouse *v6; // rax
  UFG::qReflectInventoryBase *v7; // rax
  UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *v8; // rcx
  const char *v9; // rax
  UFG::qReflectObject *v10; // rbx
  UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *v11; // rcx
  const char *v12; // rax
  UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *v13; // rcx
  const char *v14; // rax
  UFG::qReflectHandleBase other; // [rsp+30h] [rbp-38h]

  v2 = templateID;
  v3 = result;
  v4 = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName((UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *)result);
  v5 = UFG::qStringHash64(v4, 0xFFFFFFFFFFFFFFFFui64);
  v6 = UFG::qReflectWarehouse::Instance();
  v7 = UFG::qReflectWarehouse::GetInventory(v6, v5);
  if ( v7 )
  {
    v10 = UFG::qReflectInventoryBase::FindObjectByName(v7, v2);
    if ( v10 )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&other);
      v14 = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(v13);
      other.mTypeUID = UFG::qStringHash64(v14, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&other, other.mTypeUID, v10->mBaseNode.mUID);
      UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v3->mPrev, &other);
      UFG::qReflectHandleBase::~qReflectHandleBase(&other);
    }
    else
    {
      UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v3->mPrev);
      v12 = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(v11);
      v3->mTypeUID = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
    }
  }
  else
  {
    UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v3->mPrev);
    v9 = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(v8);
    v3->mTypeUID = UFG::qStringHash64(v9, 0xFFFFFFFFFFFFFFFFui64);
  }
  return v3;
}

// File Line: 206
// RVA: 0x41B4E0
UFG::qReflectHandle<UFG::RacketType> *__fastcall UFG::TurfManager::GetRacketType(UFG::qReflectHandle<UFG::RacketType> *result, const char *racketTypeID)
{
  const char *v2; // rsi
  UFG::qReflectHandle<UFG::RacketType> *v3; // rdi
  const char *v4; // rax
  unsigned __int64 v5; // rbx
  UFG::qReflectWarehouse *v6; // rax
  UFG::qReflectInventoryBase *v7; // rax
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v8; // rcx
  const char *v9; // rax
  UFG::qReflectObject *v10; // rbx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v11; // rcx
  const char *v12; // rax
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v13; // rcx
  const char *v14; // rax
  UFG::qReflectHandleBase other; // [rsp+30h] [rbp-38h]

  v2 = racketTypeID;
  v3 = result;
  v4 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName((UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *)result);
  v5 = UFG::qStringHash64(v4, 0xFFFFFFFFFFFFFFFFui64);
  v6 = UFG::qReflectWarehouse::Instance();
  v7 = UFG::qReflectWarehouse::GetInventory(v6, v5);
  if ( v7 )
  {
    v10 = UFG::qReflectInventoryBase::FindObjectByName(v7, v2);
    if ( v10 )
    {
      UFG::qReflectHandleBase::qReflectHandleBase(&other);
      v14 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v13);
      other.mTypeUID = UFG::qStringHash64(v14, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectHandleBase::Init(&other, other.mTypeUID, v10->mBaseNode.mUID);
      UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v3->mPrev, &other);
      UFG::qReflectHandleBase::~qReflectHandleBase(&other);
    }
    else
    {
      UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v3->mPrev);
      v12 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v11);
      v3->mTypeUID = UFG::qStringHash64(v12, 0xFFFFFFFFFFFFFFFFui64);
    }
  }
  else
  {
    UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v3->mPrev);
    v9 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v8);
    v3->mTypeUID = UFG::qStringHash64(v9, 0xFFFFFFFFFFFFFFFFui64);
  }
  return v3;
}

// File Line: 354
// RVA: 0x41B610
UFG::qReflectHandle<UFG::RacketType> *__fastcall UFG::TurfManager::GetRandomEmptyRacketType(UFG::TurfManager *this, UFG::qReflectHandle<UFG::RacketType> *result, UFG::RacketType::eSize size)
{
  UFG::qReflectHandle<UFG::RacketType> *v3; // rdi
  __int32 v4; // er8
  UFG::qArray<UFG::qReflectHandle<UFG::RacketType>,0> *v5; // rbx
  int v6; // eax

  v3 = result;
  v4 = size - 1;
  if ( v4 )
  {
    if ( v4 == 1 )
      v5 = &this->mEmptyRackets_Large;
    else
      v5 = &this->mEmptyRackets_Small;
  }
  else
  {
    v5 = &this->mEmptyRackets_Medium;
  }
  v6 = UFG::qRandom(v5->size, &UFG::qDefaultSeed);
  UFG::qReflectHandleBase::qReflectHandleBase(
    (UFG::qReflectHandleBase *)&v3->mPrev,
    (UFG::qReflectHandleBase *)&v5->p[v6].mPrev);
  return v3;
}

