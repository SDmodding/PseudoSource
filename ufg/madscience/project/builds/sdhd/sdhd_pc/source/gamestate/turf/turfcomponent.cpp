// File Line: 47
// RVA: 0x14F8990
__int64 dynamic_initializer_for__UFG::TurfComponent::s_TurfComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::TurfComponent::s_TurfComponentList__);
}

// File Line: 48
// RVA: 0x41AD40
UFG::ComponentIDDesc *__fastcall UFG::TurfComponent::GetDesc(UFG::TurfComponent *this)
{
  return &UFG::TurfComponent::_TypeIDesc;
}

// File Line: 65
// RVA: 0x419900
void __fastcall UFG::TurfComponent::TurfComponent(UFG::TurfComponent *this, unsigned int uid)
{
  UFG::TurfComponent *v2; // rsi
  UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *v3; // rdi
  UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *v4; // rcx
  const char *v5; // rax
  UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *v6; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v7; // [rsp+60h] [rbp+18h]

  v2 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, uid);
  v3 = (UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *)&v2->mPrev;
  v3->mPrev = v3;
  v3->mNext = v3;
  v2->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TurfComponent::`vftable'{for `UFG::SimComponent'};
  v2->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TurfComponent::`vftable'{for `UFG::UpdateInterface'};
  v2->m_SpawnedRackets.p = 0i64;
  *(_QWORD *)&v2->m_SpawnedRackets.size = 0i64;
  v2->mSpawnedSafehouseRacket = 0i64;
  v2->mSafehouseRacketLevel = 0;
  v2->mSpawnedWarehouseRacket = 0i64;
  v2->mWarehouseRacketLevel = 0;
  v2->mSpawnedTriadTempleRacket = 0i64;
  v2->mTriadTempleRacketLevel = 0;
  v2->m_BusinessRackets.p = 0i64;
  *(_QWORD *)&v2->m_BusinessRackets.size = 0i64;
  v2->m_BusinessRackets2.p = 0i64;
  *(_QWORD *)&v2->m_BusinessRackets2.size = 0i64;
  v2->m_SpawnedTemplatePrefabs.p = 0i64;
  *(_QWORD *)&v2->m_SpawnedTemplatePrefabs.size = 0i64;
  v7 = &v2->m_TurfGameplayPrefabInstance;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v7->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v2->m_TurfGameplayPrefabInstance.m_pPointer = 0i64;
  v2->m_PrefabSceneObjs.p = 0i64;
  *(_QWORD *)&v2->m_PrefabSceneObjs.size = 0i64;
  v2->mCurrentTurfInstanceData = 0i64;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v2->mCurrentTurfTemplate.mPrev);
  v5 = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(v4);
  v2->mCurrentTurfTemplate.mTypeUID = UFG::qStringHash64(v5, 0xFFFFFFFFFFFFFFFFui64);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&v2->mTransformNodeComponent);
  v2->mSafeLocationSet = 0;
  v2->mPlayerIsInTurf = 0;
  v2->mRivalIndex = -1;
  v2->mTurfIndex = 0;
  v6 = UFG::TurfComponent::s_TurfComponentList.mNode.mPrev;
  UFG::TurfComponent::s_TurfComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *)&v2->mPrev;
  v3->mPrev = v6;
  v2->mNext = (UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *)&UFG::TurfComponent::s_TurfComponentList;
  UFG::TurfComponent::s_TurfComponentList.mNode.mPrev = (UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *)&v2->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v2->vfptr,
    UFG::TurfComponent::_TurfComponentTypeUID,
    "TurfComponent");
}

// File Line: 72
// RVA: 0x419D60
void __fastcall UFG::TurfComponent::~TurfComponent(UFG::TurfComponent *this)
{
  UFG::TurfComponent *v1; // rdi
  UFG::qPropertySet **v2; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v3; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v4; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v8; // rcx
  UFG::SimComponent **v9; // rbx
  UFG::RacketInstance2 *v10; // rcx
  unsigned int *v11; // rbx
  UFG::RacketInstanceData **v12; // rcx
  UFG::SpawnedRacket **v13; // rcx
  UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *v14; // rdx
  UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *v15; // rcx
  UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *v16; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TurfComponent::`vftable'{for `UFG::SimComponent'};
  this->vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TurfComponent::`vftable'{for `UFG::UpdateInterface'};
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->mTransformNodeComponent);
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v1->mCurrentTurfTemplate.mPrev);
  v2 = v1->m_PrefabSceneObjs.p;
  if ( v2 )
    operator delete[](v2);
  v1->m_PrefabSceneObjs.p = 0i64;
  *(_QWORD *)&v1->m_PrefabSceneObjs.size = 0i64;
  v3 = &v1->m_TurfGameplayPrefabInstance;
  if ( v1->m_TurfGameplayPrefabInstance.m_pPointer )
  {
    v4 = v3->mPrev;
    v5 = v1->m_TurfGameplayPrefabInstance.mNext;
    v4->mNext = v5;
    v5->mPrev = v4;
    v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
    v1->m_TurfGameplayPrefabInstance.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_TurfGameplayPrefabInstance.mPrev;
  }
  v1->m_TurfGameplayPrefabInstance.m_pPointer = 0i64;
  v6 = v3->mPrev;
  v7 = v1->m_TurfGameplayPrefabInstance.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v3->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v3->mPrev;
  v1->m_TurfGameplayPrefabInstance.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_TurfGameplayPrefabInstance.mPrev;
  v8 = v1->m_SpawnedTemplatePrefabs.p;
  if ( v8 )
  {
    v9 = &v8[-1].m_pPointer;
    `eh vector destructor iterator'(
      v8,
      0x18ui64,
      (int)v8[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
    operator delete[](v9);
  }
  v1->m_SpawnedTemplatePrefabs.p = 0i64;
  *(_QWORD *)&v1->m_SpawnedTemplatePrefabs.size = 0i64;
  v10 = v1->m_BusinessRackets2.p;
  if ( v10 )
  {
    v11 = &v10[-1].mBlockIndex;
    `eh vector destructor iterator'(
      v10,
      0x48ui64,
      v10[-1].mBlockIndex,
      (void (__fastcall *)(void *))UFG::RacketInstance2::~RacketInstance2);
    operator delete[](v11);
  }
  v1->m_BusinessRackets2.p = 0i64;
  *(_QWORD *)&v1->m_BusinessRackets2.size = 0i64;
  v12 = v1->m_BusinessRackets.p;
  if ( v12 )
    operator delete[](v12);
  v1->m_BusinessRackets.p = 0i64;
  *(_QWORD *)&v1->m_BusinessRackets.size = 0i64;
  v13 = v1->m_SpawnedRackets.p;
  if ( v13 )
    operator delete[](v13);
  v1->m_SpawnedRackets.p = 0i64;
  *(_QWORD *)&v1->m_SpawnedRackets.size = 0i64;
  v14 = (UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *)&v1->mPrev;
  v15 = v1->mPrev;
  v16 = v1->mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v14->mPrev = v14;
  v14->mNext = v14;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 107
// RVA: 0x41BE10
void __fastcall UFG::TurfComponent::OnAttach(UFG::TurfComponent *this, UFG::SimObject *simObject)
{
  UFG::SimObject *v2; // rdi
  UFG::TurfComponent *v3; // rbx
  LOCALNAMESPACE::hkNativeResource *v4; // rax
  const char *v5; // rax
  UFG::GameDB *v6; // rax
  UFG::TurfInstanceData *v7; // rax
  UFG::qReflectHandle<UFG::TurfTemplate> *v8; // rax
  UFG::qReflectHandle<UFG::TurfTemplate> result; // [rsp+28h] [rbp-30h]

  v2 = simObject;
  v3 = this;
  v4 = (LOCALNAMESPACE::hkNativeResource *)UFG::GameDB::Instance();
  v5 = Scaleform::GFx::FontManagerStates::GetStateBagImpl(v4);
  if ( v5 && *(_DWORD *)(*((_QWORD *)v5 + 21) + 4i64) != v3->m_pSimObject->m_Name.mUID )
  {
    v6 = UFG::GameDB::Instance();
    v3->mRivalIndex = UFG::GameDB::GetRivalIndexFor(v6, v3);
    v3->mTurfIndex = 0;
  }
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(&v3->mTransformNodeComponent, v2);
  v7 = UFG::PlaceholderGameDB::GetTurfInstanceDataForMarkerId(UFG::PlaceholderGameDB::ms_pSingleton, v3->m_NameUID);
  v3->mCurrentTurfInstanceData = v7;
  if ( v7 )
  {
    v8 = UFG::TurfManager::GetTurfTemplate(&result, v7->templateName.mData);
    UFG::qReflectHandleBase::operator=(
      (UFG::qReflectHandleBase *)&v3->mCurrentTurfTemplate.mPrev,
      (UFG::qReflectHandleBase *)&v8->mPrev);
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mPrev);
    UFG::TurfComponent::Spawn(v3);
  }
}

// File Line: 135
// RVA: 0x41BEE0
void __fastcall UFG::TurfComponent::OnDetach(UFG::TurfComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *v1; // r8
  UFG::TurfComponent *v2; // r9
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v4; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx

  v1 = &this->mTransformNodeComponent;
  v2 = this;
  if ( this->mTransformNodeComponent.m_pSimComponent )
  {
    v3 = this->mTransformNodeComponent.mNext;
    v4 = v1->mPrev;
    v4->mNext = v3;
    v3->mPrev = v4;
    this->mTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_7:
    v1->m_pSimObject = 0i64;
    v1->mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    v1->mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&v1->mPrev;
    goto LABEL_8;
  }
  if ( this->mTransformNodeComponent.m_pSimObject
    && ((UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)v1->mPrev != v1
     || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)this->mTransformNodeComponent.mNext != &this->mTransformNodeComponent) )
  {
    v5 = this->mTransformNodeComponent.mNext;
    v6 = v1->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    goto LABEL_7;
  }
LABEL_8:
  v1->m_Changed = 1;
  UFG::TurfComponent::DeSpawn(v2);
}

// File Line: 168
// RVA: 0x41C7B0
void __fastcall UFG::TurfComponent::Spawn(UFG::TurfComponent *this)
{
  UFG::TurfComponent *v1; // rdi
  UFG::TurfManager *v2; // rax
  UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> **v3; // rax
  char v4; // r13
  unsigned int v5; // er15
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // ebx
  UFG::TurfBlockInstanceData *v9; // r12
  UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *v10; // rcx
  const char *v11; // rax
  UFG::TurfInstanceData *v12; // rax
  UFG::qReflectHandle<UFG::TurfTemplate> *v13; // rax
  unsigned int v14; // ebx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v15; // rcx
  const char *v16; // rax
  UFG::RacketInstanceData *v17; // rax
  UFG::qReflectHandle<UFG::RacketType> *v18; // rax
  char *v19; // rax
  UFG::SpawnedRacket *v20; // r12
  __int64 v21; // r13
  unsigned int v22; // esi
  unsigned int v23; // ebx
  unsigned int v24; // ebx
  unsigned __int64 v25; // rax
  UFG::allocator::free_link *v26; // rax
  UFG::SpawnedRacket **v27; // r14
  __int64 v28; // r9
  char *v29; // rax
  unsigned int v30; // ebx
  UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *v31; // rcx
  const char *v32; // rax
  UFG::SimComponent *v33; // rbx
  UFG::qMatrix44 *v34; // r12
  char *v35; // rax
  UFG::qSymbol *v36; // rbx
  UFG::qSymbol *v37; // rax
  UFG::SceneObjectProperties *v38; // rsi
  UFG::qNode<UFG::qString,UFG::qString> *v39; // rax
  __int64 v40; // r15
  unsigned int v41; // ebx
  unsigned int v42; // eax
  unsigned int v43; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v44; // rdx
  UFG::SimComponent *v45; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v46; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v47; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v48; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v49; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v50; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v51; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v52; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v53; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v54; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v55; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v56; // rax
  UFG::qString v57; // [rsp+30h] [rbp-D0h]
  UFG::qVector3 box_min; // [rsp+58h] [rbp-A8h]
  UFG::qVector3 box_max; // [rsp+68h] [rbp-98h]
  UFG::RacketInstance racket; // [rsp+78h] [rbp-88h]
  UFG::TurfBlockInstance v61; // [rsp+B0h] [rbp-50h]
  UFG::TurfInstance v62; // [rsp+E8h] [rbp-18h]
  __int64 v63; // [rsp+120h] [rbp+20h]
  UFG::qReflectHandle<UFG::RacketType> *v64; // [rsp+128h] [rbp+28h]
  UFG::qReflectHandle<UFG::RacketType> *v65; // [rsp+130h] [rbp+30h]
  UFG::qString v66; // [rsp+138h] [rbp+38h]
  UFG::qReflectHandle<UFG::RacketType> v67; // [rsp+160h] [rbp+60h]
  UFG::qReflectHandle<UFG::TurfTemplate> result; // [rsp+188h] [rbp+88h]
  UFG::qSymbol v69; // [rsp+200h] [rbp+100h]
  UFG::qSymbol v70; // [rsp+208h] [rbp+108h]
  UFG::SceneObjectProperties *prefabInstanceOut; // [rsp+210h] [rbp+110h]
  UFG::TurfBlockInstanceData *v72; // [rsp+218h] [rbp+118h]

  v63 = -2i64;
  v1 = this;
  if ( this->mCurrentTurfInstanceData )
  {
    UFG::TurfComponent::ActivateBoundaryLayer(this);
    v2 = UFG::TurfManager::Instance();
    v3 = UFG::TurfManager::GetLocalPlayerTurf(v2);
    v4 = v3 == (UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> **)v1;
    LOBYTE(v69.mUID) = v3 == (UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> **)v1;
    v5 = 0;
    v6 = 0;
    v7 = 0;
    v70.mUID = 0;
    do
    {
      v8 = UFG::PlaceholderGameDB::GetBlockIdByIndex(v1->mCurrentTurfInstanceData, v7);
      v9 = UFG::PlaceholderGameDB::GetTurfBlockInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v8);
      v72 = v9;
      if ( v9 )
      {
        v61.mData = 0i64;
        v61.mTurfData = 0i64;
        prefabInstanceOut = (UFG::SceneObjectProperties *)&v61.mTurfTemplate;
        UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v61.mTurfTemplate.mPrev);
        v11 = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(v10);
        v61.mTurfTemplate.mTypeUID = UFG::qStringHash64(v11, 0xFFFFFFFFFFFFFFFFui64);
        v61.mData = UFG::PlaceholderGameDB::GetTurfBlockInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v8);
        if ( v61.mData )
        {
          v12 = UFG::PlaceholderGameDB::GetTurfInstanceDataForBlockId(UFG::PlaceholderGameDB::ms_pSingleton, v8);
          v61.mTurfData = v12;
          if ( v12 )
          {
            v13 = UFG::TurfManager::GetTurfTemplate(&result, v12->templateName.mData);
            UFG::qReflectHandleBase::operator=(
              (UFG::qReflectHandleBase *)&v61.mTurfTemplate.mPrev,
              (UFG::qReflectHandleBase *)&v13->mPrev);
            UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mPrev);
          }
        }
        UFG::TurfBlockInstance::PopulateEmptyLots(&v61);
        v65 = &racket.mType;
        do
        {
          v14 = UFG::PlaceholderGameDB::GetRacketIdByIndex(v9, v5);
          racket.mData = 0i64;
          UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&racket.mType.mPrev);
          v16 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v15);
          racket.mType.mTypeUID = UFG::qStringHash64(v16, 0xFFFFFFFFFFFFFFFFui64);
          racket.mContainingBlock = 0i64;
          v17 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v14);
          racket.mData = v17;
          if ( v17 )
          {
            v18 = UFG::TurfManager::GetRacketType(&v67, v17->type.mData);
            UFG::qReflectHandleBase::operator=(
              (UFG::qReflectHandleBase *)&racket.mType.mPrev,
              (UFG::qReflectHandleBase *)&v18->mPrev);
            UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v67.mPrev);
          }
          racket.mContainingBlock = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(
                                      UFG::PlaceholderGameDB::ms_pSingleton,
                                      v14);
          if ( racket.mData && racket.mType.mData )
          {
            v19 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1->m_pSimObject->m_Name);
            UFG::qString::FormatEx(&v57, "%s-%d", v19, v6);
            LODWORD(prefabInstanceOut) = v6 + 1;
            v20 = UFG::TurfComponent::SpawnRacket(v1, &racket, v57.mData, v4, 1);
            v21 = v1->m_SpawnedRackets.size;
            v22 = v21 + 1;
            v23 = v1->m_SpawnedRackets.capacity;
            if ( (signed int)v21 + 1 > v23 )
            {
              if ( v23 )
                v24 = 2 * v23;
              else
                v24 = 1;
              for ( ; v24 < v22; v24 *= 2 )
                ;
              if ( v24 <= 2 )
                v24 = 2;
              if ( v24 - v22 > 0x10000 )
                v24 = v21 + 65537;
              if ( v24 != (_DWORD)v21 )
              {
                v25 = 8i64 * v24;
                if ( !is_mul_ok(v24, 8ui64) )
                  v25 = -1i64;
                v26 = UFG::qMalloc(v25, "qArray.Add", 0i64);
                v27 = (UFG::SpawnedRacket **)v26;
                if ( v1->m_SpawnedRackets.p )
                {
                  v28 = 0i64;
                  if ( v1->m_SpawnedRackets.size )
                  {
                    do
                    {
                      v26[v28] = (UFG::allocator::free_link)v1->m_SpawnedRackets.p[v28];
                      v28 = (unsigned int)(v28 + 1);
                    }
                    while ( (unsigned int)v28 < v1->m_SpawnedRackets.size );
                  }
                  operator delete[](v1->m_SpawnedRackets.p);
                }
                v1->m_SpawnedRackets.p = v27;
                v1->m_SpawnedRackets.capacity = v24;
              }
            }
            v1->m_SpawnedRackets.size = v22;
            v1->m_SpawnedRackets.p[v21] = v20;
            UFG::qString::~qString(&v57);
            v64 = &racket.mType;
            UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&racket.mType.mPrev);
            v6 = (unsigned int)prefabInstanceOut;
            v9 = v72;
            v4 = v69.mUID;
          }
          else
          {
            prefabInstanceOut = (UFG::SceneObjectProperties *)&racket.mType;
            UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&racket.mType.mPrev);
          }
          ++v5;
        }
        while ( v5 < 4 );
        prefabInstanceOut = (UFG::SceneObjectProperties *)&v61.mTurfTemplate;
        UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v61.mTurfTemplate.mPrev);
        v5 = 0;
      }
      v7 = v70.mUID + 1;
      v70.mUID = v7;
    }
    while ( v7 < 8 );
    v29 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1->m_pSimObject->m_Name);
    UFG::TurfComponent::SpawnSafehouseRackets(v1, v29, v4);
    v30 = v1->mCurrentTurfInstanceData->ownerPlayerId;
    v62.mData = 0i64;
    v62.mComponent = 0i64;
    *(_QWORD *)&v69.mUID = (char *)&v62 + 16;
    UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v62.mTemplate.mPrev);
    v32 = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(v31);
    v62.mTemplate.mTypeUID = UFG::qStringHash64(v32, 0xFFFFFFFFFFFFFFFFui64);
    UFG::TurfInstance::Init(&v62, v30);
    v33 = v1->mTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)v1->mTransformNodeComponent.m_pSimComponent);
    v34 = (UFG::qMatrix44 *)&v33[2];
    prefabInstanceOut = 0i64;
    UFG::qString::qString(&v66);
    v35 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v1->m_pSimObject->m_Name);
    UFG::qString::Format(&v66, "TurfGameplay-%s", v35);
    v36 = UFG::qSymbol::create_from_string(&v69, v66.mData);
    v37 = UFG::TurfInstance::GameplayPrefab(&v62, &v70);
    if ( UFG::TurfComponent::SpawnPrefab(v1, v37, v36, v34, &prefabInstanceOut) )
    {
      v57.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v57;
      v57.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v57;
      v38 = prefabInstanceOut;
      *(_QWORD *)&v57.mMagic = prefabInstanceOut;
      if ( prefabInstanceOut )
      {
        v39 = (UFG::qNode<UFG::qString,UFG::qString> *)prefabInstanceOut->m_SafePointerList.mNode.mPrev;
        v39->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v57;
        v57.mPrev = v39;
        v57.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v38->m_SafePointerList;
        v38->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v57;
      }
      v40 = v1->m_SpawnedTemplatePrefabs.size;
      v41 = v40 + 1;
      v42 = v1->m_SpawnedTemplatePrefabs.capacity;
      if ( (signed int)v40 + 1 > v42 )
      {
        v43 = 1;
        if ( v42 )
          v43 = 2 * v42;
        for ( ; v43 < v41; v43 *= 2 )
          ;
        if ( v43 - v41 > 0x10000 )
          v43 = v40 + 65537;
        UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
          (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *)&v1->m_SpawnedTemplatePrefabs,
          v43,
          "qArray.Add");
      }
      v1->m_SpawnedTemplatePrefabs.size = v41;
      v44 = &v1->m_SpawnedTemplatePrefabs.p[v40];
      v45 = *(UFG::SimComponent **)&v57.mMagic;
      if ( v44->m_pPointer )
      {
        v46 = v44->mPrev;
        v47 = v44->mNext;
        v46->mNext = v47;
        v47->mPrev = v46;
        v44->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v44->mPrev;
        v44->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v44->mPrev;
      }
      v44->m_pPointer = v45;
      if ( v45 )
      {
        v48 = v45->m_SafePointerList.mNode.mPrev;
        v48->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v44->mPrev;
        v44->mPrev = v48;
        v44->mNext = &v45->m_SafePointerList.mNode;
        v45->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v44->mPrev;
      }
      if ( *(_QWORD *)&v57.mMagic )
      {
        v49 = v57.mPrev;
        v50 = v57.mNext;
        v57.mPrev->mNext = v57.mNext;
        v50->mPrev = v49;
        v57.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v57;
        v57.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v57;
      }
      *(_QWORD *)&v57.mMagic = 0i64;
      v51 = v57.mPrev;
      v52 = v57.mNext;
      v57.mPrev->mNext = v57.mNext;
      v52->mPrev = v51;
      v57.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v57;
      v57.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v57;
      v53 = &v1->m_TurfGameplayPrefabInstance;
      if ( v1->m_TurfGameplayPrefabInstance.m_pPointer )
      {
        v54 = v53->mPrev;
        v55 = v1->m_TurfGameplayPrefabInstance.mNext;
        v54->mNext = v55;
        v55->mPrev = v54;
        v53->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v53->mPrev;
        v1->m_TurfGameplayPrefabInstance.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v1->m_TurfGameplayPrefabInstance.mPrev;
      }
      v1->m_TurfGameplayPrefabInstance.m_pPointer = (UFG::SimComponent *)&v38->vfptr;
      if ( v38 )
      {
        v56 = v38->m_SafePointerList.mNode.mPrev;
        v56->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v53->mPrev;
        v53->mPrev = v56;
        v1->m_TurfGameplayPrefabInstance.mNext = &v38->m_SafePointerList.mNode;
        v38->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v53->mPrev;
      }
    }
    box_min.x = FLOAT_N56_0;
    box_min.y = FLOAT_N168_0;
    box_min.z = FLOAT_N50_0;
    box_max.x = FLOAT_168_0;
    box_max.y = FLOAT_56_0;
    box_max.z = FLOAT_75_0;
    UFG::AddAltColorEffect(v1->m_pSimObject->mNode.mUID, v34, &box_min, &box_max);
    UFG::qString::~qString(&v66);
    *(_QWORD *)&v69.mUID = (char *)&v62 + 16;
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v62.mTemplate.mPrev);
  }
}

// File Line: 246
// RVA: 0x41A0B0
UFG::qPropertyList *__fastcall UFG::TurfComponent::ActivateBoundaryLayer(UFG::TurfComponent *this)
{
  unsigned __int8 v1; // di
  UFG::SceneObjectProperties *v2; // rcx
  UFG::qPropertySet *v3; // rbp
  UFG::qPropertyList *result; // rax
  UFG::qPropertyList *v5; // r14
  unsigned int v6; // esi
  unsigned int v7; // ebx
  UFG::qSymbol *v8; // rax
  UFG::qSymbol *v9; // rax
  UFG::qBaseTreeRB *v10; // rax

  v1 = 1;
  v2 = this->m_pSimObject->m_pSceneObj;
  v3 = v2->mpWritableProperties;
  if ( !v3 )
    v3 = v2->mpConstProperties;
  if ( !(_S4_7 & 1) )
  {
    _S4_7 |= 1u;
    UFG::qSymbol::create_from_string(&qSymbol_TurfBoundaryLayers, "TurfBoundaryLayers");
    atexit(UFG::TurfComponent::ActivateBoundaryLayer_::_2_::_dynamic_atexit_destructor_for__qSymbol_TurfBoundaryLayers__);
  }
  result = UFG::qPropertySet::Get<UFG::qPropertyList>(v3, &qSymbol_TurfBoundaryLayers, DEPTH_RECURSE);
  v5 = result;
  if ( result )
  {
    v6 = result->mNumElements;
    v7 = 0;
    if ( v6 )
    {
      do
      {
        v8 = UFG::qPropertyList::Get<UFG::qSymbol>(v5, v7);
        v9 = UFG::qPropertySet::Get<UFG::qSymbol>(v3, v8, DEPTH_RECURSE);
        if ( v9 )
        {
          v10 = UFG::Scene::FindLayer(&UFG::Scene::msDefault, v9);
          if ( v10 )
            UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)v10, 1, 0, 0);
          else
            v1 = 0;
        }
        else
        {
          v1 = 0;
        }
        ++v7;
      }
      while ( v7 < v6 );
    }
    result = (UFG::qPropertyList *)v1;
  }
  return result;
}

// File Line: 287
// RVA: 0x41D040
UFG::SpawnedRacket *__fastcall UFG::TurfComponent::SpawnRacket(UFG::TurfComponent *this, UFG::RacketInstance *racket, const char *suffix, bool isLocalPlayer, bool isBusiness)
{
  UFG::RacketInstance *v5; // r13
  UFG::TurfComponent *v6; // r14
  UFG::allocator::free_link *v7; // rax
  unsigned int v8; // edx
  UFG::SpawnedRacket *v9; // rax
  unsigned int v10; // esi
  UFG::qReflectInventoryBase *v11; // r15
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v12; // rdi
  __int64 v13; // r14
  unsigned int v14; // ebx
  unsigned int v15; // edx
  unsigned int v16; // edx
  UFG::SpawnedRacket *v17; // r15
  UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *v18; // rdi
  UFG::qSymbol *v19; // rbx
  UFG::qSymbol *v20; // rax
  UFG::SceneObjectProperties *v21; // r14
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v22; // rax
  __int64 v23; // r15
  unsigned int v24; // ebx
  unsigned int v25; // edx
  unsigned int v26; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v27; // rdx
  UFG::SimComponent *v28; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v30; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v36; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qSymbol *v40; // rbx
  UFG::qSymbol *v41; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v42; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v43; // rax
  __int64 v44; // r14
  unsigned int v45; // ebx
  unsigned int v46; // edx
  unsigned int v47; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v48; // rdx
  UFG::SimComponent *v49; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v50; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v51; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v52; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v53; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v54; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v55; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v56; // rax
  UFG::qSymbol *v57; // rbx
  UFG::qSymbol *v58; // rax
  UFG::SceneObjectProperties *v59; // r14
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v60; // rax
  __int64 v61; // r15
  unsigned int v62; // ebx
  unsigned int v63; // edx
  unsigned int v64; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v65; // rdx
  UFG::SimComponent *v66; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v67; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v68; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v69; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v70; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v71; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v72; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v73; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v74; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v75; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v76; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v77; // rax
  UFG::qSymbol *v78; // rbx
  UFG::qSymbol *v79; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v80; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v81; // rax
  __int64 v82; // r14
  unsigned int v83; // ebx
  unsigned int v84; // edx
  unsigned int v85; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v86; // rdx
  UFG::SimComponent *v87; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v88; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v89; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v90; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v91; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v92; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v93; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v94; // rax
  UFG::qSymbol *v95; // rbx
  UFG::qSymbol *v96; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v97; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v98; // rax
  __int64 v99; // r14
  unsigned int v100; // ebx
  unsigned int v101; // edx
  unsigned int v102; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v103; // rdx
  UFG::SimComponent *v104; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v105; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v106; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v107; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v108; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v109; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v110; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v111; // rax
  UFG::qSymbol *v112; // rbx
  UFG::qSymbol *v113; // rax
  UFG::SceneObjectProperties *v114; // r14
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v115; // rax
  __int64 v116; // r15
  unsigned int v117; // ebx
  unsigned int v118; // edx
  unsigned int v119; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v120; // rdx
  UFG::SimComponent *v121; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v122; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v123; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v124; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v125; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v126; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v127; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v128; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v129; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v130; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v131; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v132; // rax
  UFG::qSymbol *v133; // rbx
  UFG::qSymbol *v134; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v135; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v136; // rax
  __int64 v137; // r14
  unsigned int v138; // ebx
  unsigned int v139; // edx
  unsigned int v140; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v141; // rdx
  UFG::SimComponent *v142; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v143; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v144; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v145; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v146; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v147; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v148; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v149; // rax
  UFG::qSymbol *v150; // rbx
  UFG::qSymbol *v151; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v152; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v153; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v154; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v155; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v156; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v157; // rax
  UFG::qSymbol *v158; // rbx
  UFG::qSymbol *v159; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v160; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v161; // rax
  __int64 v162; // r14
  unsigned int v163; // ebx
  unsigned int v164; // eax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v165; // rdx
  UFG::SimComponent *v166; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v167; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v168; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v169; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v170; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v171; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v172; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v173; // rax
  UFG::qSymbol *v174; // rbx
  UFG::qSymbol *v175; // rax
  UFG::SceneObjectProperties *v176; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v177; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v178; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v179; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v180; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v181; // rax
  UFG::qSymbol *v182; // rbx
  UFG::qSymbol *v183; // rax
  UFG::SceneObjectProperties *v184; // rbx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v185; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v186; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v187; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v188; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v189; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> item; // [rsp+30h] [rbp-91h]
  UFG::SceneObjectProperties *prefabInstance; // [rsp+48h] [rbp-79h]
  UFG::SpawnedRacket *v193; // [rsp+50h] [rbp-71h]
  UFG::qString v194; // [rsp+58h] [rbp-69h]
  UFG::qMatrix44 result; // [rsp+80h] [rbp-41h]
  __int64 v196; // [rsp+C0h] [rbp-1h]
  UFG::TurfComponent *v197; // [rsp+120h] [rbp+5Fh]
  UFG::allocator::free_link *v198; // [rsp+128h] [rbp+67h]
  const char *v199; // [rsp+130h] [rbp+6Fh]
  UFG::qSymbol v200; // [rsp+138h] [rbp+77h]

  LOBYTE(v200.mUID) = isLocalPlayer;
  v199 = suffix;
  v197 = this;
  v196 = -2i64;
  v5 = racket;
  v6 = this;
  v7 = UFG::qMalloc(0xE0ui64, "SpawnedRacket", 0i64);
  v198 = v7;
  if ( v7 )
  {
    if ( v5->mData )
      v8 = v5->mData->id;
    else
      v8 = 0;
    UFG::SpawnedRacket::SpawnedRacket((UFG::SpawnedRacket *)v7, v8);
    v193 = v9;
  }
  else
  {
    v193 = 0i64;
  }
  v10 = 1;
  if ( isBusiness )
  {
    v11 = (UFG::qReflectInventoryBase *)v5->mData;
    v12 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v6->m_BusinessRackets;
    v13 = v6->m_BusinessRackets.size;
    v14 = v13 + 1;
    v15 = v12->capacity;
    if ( (signed int)v13 + 1 > v15 )
    {
      if ( v15 )
        v16 = 2 * v15;
      else
        v16 = 1;
      for ( ; v16 < v14; v16 *= 2 )
        ;
      if ( v16 <= 2 )
        v16 = 2;
      if ( v16 - v14 > 0x10000 )
        v16 = v13 + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v12, v16, "qArray.Add");
    }
    v12->size = v14;
    v12->p[v13] = v11;
    v6 = v197;
  }
  v17 = v193;
  v18 = (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *)&v193->m_PrefabInstances;
  UFG::TurfComponent::GetRacketTransform(v6, &result, v5);
  UFG::qString::qString(&v194);
  prefabInstance = 0i64;
  UFG::qString::Format(&v194, "TurfRacketExteriorCore-%s", v199);
  v19 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&isBusiness, v194.mData);
  v20 = UFG::RacketInstance::ExteriorCorePrefab(v5, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v20, v19, &result, &prefabInstance) )
  {
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    v21 = prefabInstance;
    item.m_pPointer = (UFG::SimComponent *)&prefabInstance->vfptr;
    if ( prefabInstance )
    {
      v22 = prefabInstance->m_SafePointerList.mNode.mPrev;
      v22->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mPrev = v22;
      item.mNext = &v21->m_SafePointerList.mNode;
      v21->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    v23 = v18->size;
    v24 = v23 + 1;
    v25 = v18->capacity;
    if ( (signed int)v23 + 1 > v25 )
    {
      if ( v25 )
        v26 = 2 * v25;
      else
        v26 = 1;
      for ( ; v26 < v24; v26 *= 2 )
        ;
      if ( v26 - v24 > 0x10000 )
        v26 = v23 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(v18, v26, "qArray.Add");
    }
    v18->size = v24;
    v27 = &v18->p[v23];
    v28 = item.m_pPointer;
    if ( v27->m_pPointer )
    {
      v29 = v27->mPrev;
      v30 = v27->mNext;
      v29->mNext = v30;
      v30->mPrev = v29;
      v27->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
      v27->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
    }
    v27->m_pPointer = v28;
    if ( v28 )
    {
      v31 = v28->m_SafePointerList.mNode.mPrev;
      v31->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
      v27->mPrev = v31;
      v27->mNext = &v28->m_SafePointerList.mNode;
      v28->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v27->mPrev;
    }
    if ( item.m_pPointer )
    {
      v32 = item.mPrev;
      v33 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v33->mPrev = v32;
      item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    item.m_pPointer = 0i64;
    v34 = item.mPrev;
    v35 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v35->mPrev = v34;
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    v17 = v193;
    v36 = &v193->m_ExteriorCorePrefabInstance;
    if ( v193->m_ExteriorCorePrefabInstance.m_pPointer )
    {
      v37 = v36->mPrev;
      v38 = v193->m_ExteriorCorePrefabInstance.mNext;
      v37->mNext = v38;
      v38->mPrev = v37;
      v36->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
      v36->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
    }
    v36->m_pPointer = (UFG::SimComponent *)&v21->vfptr;
    if ( v21 )
    {
      v39 = v21->m_SafePointerList.mNode.mPrev;
      v39->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
      v36->mPrev = v39;
      v36->mNext = &v21->m_SafePointerList.mNode;
      v21->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v36->mPrev;
    }
    v6 = v197;
  }
  UFG::qString::Format(&v194, "TurfRacketExteriorCoreProps-%s", v199);
  v40 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&isBusiness, v194.mData);
  v41 = UFG::RacketInstance::ExteriorCorePropsPrefab(v5, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v41, v40, &result, &prefabInstance) )
  {
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.m_pPointer = (UFG::SimComponent *)&prefabInstance->vfptr;
    if ( prefabInstance )
    {
      v42 = &prefabInstance->m_SafePointerList.mNode;
      v43 = prefabInstance->m_SafePointerList.mNode.mPrev;
      v43->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mPrev = v43;
      item.mNext = v42;
      v42->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    v44 = v18->size;
    v45 = v44 + 1;
    v46 = v18->capacity;
    if ( (signed int)v44 + 1 > v46 )
    {
      if ( v46 )
        v47 = 2 * v46;
      else
        v47 = 1;
      for ( ; v47 < v45; v47 *= 2 )
        ;
      if ( v47 - v45 > 0x10000 )
        v47 = v44 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(v18, v47, "qArray.Add");
    }
    v18->size = v45;
    v48 = &v18->p[v44];
    v49 = item.m_pPointer;
    if ( v48->m_pPointer )
    {
      v50 = v48->mPrev;
      v51 = v48->mNext;
      v50->mNext = v51;
      v51->mPrev = v50;
      v48->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v48->mPrev;
      v48->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v48->mPrev;
    }
    v48->m_pPointer = v49;
    if ( v49 )
    {
      v52 = v49->m_SafePointerList.mNode.mPrev;
      v52->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v48->mPrev;
      v48->mPrev = v52;
      v48->mNext = &v49->m_SafePointerList.mNode;
      v49->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v48->mPrev;
    }
    if ( item.m_pPointer )
    {
      v53 = item.mPrev;
      v54 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v54->mPrev = v53;
      item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    item.m_pPointer = 0i64;
    v55 = item.mPrev;
    v56 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v56->mPrev = v55;
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    v6 = v197;
  }
  UFG::qString::Format(&v194, "TurfRacketExteriorCoreDoors-%s", v199);
  v57 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&isBusiness, v194.mData);
  v58 = UFG::RacketInstance::ExteriorCoreDoorsPrefab(v5, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v58, v57, &result, &prefabInstance) )
  {
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    v59 = prefabInstance;
    item.m_pPointer = (UFG::SimComponent *)&prefabInstance->vfptr;
    if ( prefabInstance )
    {
      v60 = prefabInstance->m_SafePointerList.mNode.mPrev;
      v60->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mPrev = v60;
      item.mNext = &v59->m_SafePointerList.mNode;
      v59->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    v61 = v18->size;
    v62 = v61 + 1;
    v63 = v18->capacity;
    if ( (signed int)v61 + 1 > v63 )
    {
      if ( v63 )
        v64 = 2 * v63;
      else
        v64 = 1;
      for ( ; v64 < v62; v64 *= 2 )
        ;
      if ( v64 - v62 > 0x10000 )
        v64 = v61 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(v18, v64, "qArray.Add");
    }
    v18->size = v62;
    v65 = &v18->p[v61];
    v66 = item.m_pPointer;
    if ( v65->m_pPointer )
    {
      v67 = v65->mPrev;
      v68 = v65->mNext;
      v67->mNext = v68;
      v68->mPrev = v67;
      v65->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v65->mPrev;
      v65->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v65->mPrev;
    }
    v65->m_pPointer = v66;
    if ( v66 )
    {
      v69 = v66->m_SafePointerList.mNode.mPrev;
      v69->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v65->mPrev;
      v65->mPrev = v69;
      v65->mNext = &v66->m_SafePointerList.mNode;
      v66->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v65->mPrev;
    }
    if ( item.m_pPointer )
    {
      v70 = item.mPrev;
      v71 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v71->mPrev = v70;
      item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    item.m_pPointer = 0i64;
    v72 = item.mPrev;
    v73 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v73->mPrev = v72;
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    v17 = v193;
    v74 = &v193->m_ExteriorCoreDoorsPrefabInstance;
    if ( v193->m_ExteriorCoreDoorsPrefabInstance.m_pPointer )
    {
      v75 = v74->mPrev;
      v76 = v193->m_ExteriorCoreDoorsPrefabInstance.mNext;
      v75->mNext = v76;
      v76->mPrev = v75;
      v74->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v74->mPrev;
      v74->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v74->mPrev;
    }
    v74->m_pPointer = (UFG::SimComponent *)&v59->vfptr;
    if ( v59 )
    {
      v77 = v59->m_SafePointerList.mNode.mPrev;
      v77->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v74->mPrev;
      v74->mPrev = v77;
      v74->mNext = &v59->m_SafePointerList.mNode;
      v59->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v74->mPrev;
    }
    v6 = v197;
  }
  UFG::qString::Format(&v194, "TurfRacketInteriorCore-%s", v199);
  v78 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&isBusiness, v194.mData);
  v79 = UFG::RacketInstance::InteriorCorePrefab(v5, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v79, v78, &result, &prefabInstance) )
  {
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.m_pPointer = (UFG::SimComponent *)&prefabInstance->vfptr;
    if ( prefabInstance )
    {
      v80 = &prefabInstance->m_SafePointerList.mNode;
      v81 = prefabInstance->m_SafePointerList.mNode.mPrev;
      v81->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mPrev = v81;
      item.mNext = v80;
      v80->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    v82 = v18->size;
    v83 = v82 + 1;
    v84 = v18->capacity;
    if ( (signed int)v82 + 1 > v84 )
    {
      if ( v84 )
        v85 = 2 * v84;
      else
        v85 = 1;
      for ( ; v85 < v83; v85 *= 2 )
        ;
      if ( v85 - v83 > 0x10000 )
        v85 = v82 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(v18, v85, "qArray.Add");
    }
    v18->size = v83;
    v86 = &v18->p[v82];
    v87 = item.m_pPointer;
    if ( v86->m_pPointer )
    {
      v88 = v86->mPrev;
      v89 = v86->mNext;
      v88->mNext = v89;
      v89->mPrev = v88;
      v86->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v86->mPrev;
      v86->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v86->mPrev;
    }
    v86->m_pPointer = v87;
    if ( v87 )
    {
      v90 = v87->m_SafePointerList.mNode.mPrev;
      v90->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v86->mPrev;
      v86->mPrev = v90;
      v86->mNext = &v87->m_SafePointerList.mNode;
      v87->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v86->mPrev;
    }
    if ( item.m_pPointer )
    {
      v91 = item.mPrev;
      v92 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v92->mPrev = v91;
      item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    item.m_pPointer = 0i64;
    v93 = item.mPrev;
    v94 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v94->mPrev = v93;
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    v6 = v197;
  }
  UFG::qString::Format(&v194, "TurfRacketInteriorCoreProps-%s", v199);
  v95 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&isBusiness, v194.mData);
  v96 = UFG::RacketInstance::InteriorCorePropsPrefab(v5, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v96, v95, &result, &prefabInstance) )
  {
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.m_pPointer = (UFG::SimComponent *)&prefabInstance->vfptr;
    if ( prefabInstance )
    {
      v97 = &prefabInstance->m_SafePointerList.mNode;
      v98 = prefabInstance->m_SafePointerList.mNode.mPrev;
      v98->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mPrev = v98;
      item.mNext = v97;
      v97->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    v99 = v18->size;
    v100 = v99 + 1;
    v101 = v18->capacity;
    if ( (signed int)v99 + 1 > v101 )
    {
      if ( v101 )
        v102 = 2 * v101;
      else
        v102 = 1;
      for ( ; v102 < v100; v102 *= 2 )
        ;
      if ( v102 - v100 > 0x10000 )
        v102 = v99 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(v18, v102, "qArray.Add");
    }
    v18->size = v100;
    v103 = &v18->p[v99];
    v104 = item.m_pPointer;
    if ( v103->m_pPointer )
    {
      v105 = v103->mPrev;
      v106 = v103->mNext;
      v105->mNext = v106;
      v106->mPrev = v105;
      v103->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v103->mPrev;
      v103->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v103->mPrev;
    }
    v103->m_pPointer = v104;
    if ( v104 )
    {
      v107 = v104->m_SafePointerList.mNode.mPrev;
      v107->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v103->mPrev;
      v103->mPrev = v107;
      v103->mNext = &v104->m_SafePointerList.mNode;
      v104->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v103->mPrev;
    }
    if ( item.m_pPointer )
    {
      v108 = item.mPrev;
      v109 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v109->mPrev = v108;
      item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    item.m_pPointer = 0i64;
    v110 = item.mPrev;
    v111 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v111->mPrev = v110;
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    v6 = v197;
  }
  UFG::qString::Format(&v194, "TurfRacketInteriorCoreDoors-%s", v199);
  v112 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&isBusiness, v194.mData);
  v113 = UFG::RacketInstance::InteriorCoreDoorsPrefab(v5, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v113, v112, &result, &prefabInstance) )
  {
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    v114 = prefabInstance;
    item.m_pPointer = (UFG::SimComponent *)&prefabInstance->vfptr;
    if ( prefabInstance )
    {
      v115 = prefabInstance->m_SafePointerList.mNode.mPrev;
      v115->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mPrev = v115;
      item.mNext = &v114->m_SafePointerList.mNode;
      v114->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    v116 = v18->size;
    v117 = v116 + 1;
    v118 = v18->capacity;
    if ( (signed int)v116 + 1 > v118 )
    {
      if ( v118 )
        v119 = 2 * v118;
      else
        v119 = 1;
      for ( ; v119 < v117; v119 *= 2 )
        ;
      if ( v119 - v117 > 0x10000 )
        v119 = v116 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(v18, v119, "qArray.Add");
    }
    v18->size = v117;
    v120 = &v18->p[v116];
    v121 = item.m_pPointer;
    if ( v120->m_pPointer )
    {
      v122 = v120->mPrev;
      v123 = v120->mNext;
      v122->mNext = v123;
      v123->mPrev = v122;
      v120->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v120->mPrev;
      v120->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v120->mPrev;
    }
    v120->m_pPointer = v121;
    if ( v121 )
    {
      v124 = v121->m_SafePointerList.mNode.mPrev;
      v124->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v120->mPrev;
      v120->mPrev = v124;
      v120->mNext = &v121->m_SafePointerList.mNode;
      v121->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v120->mPrev;
    }
    if ( item.m_pPointer )
    {
      v125 = item.mPrev;
      v126 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v126->mPrev = v125;
      item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    item.m_pPointer = 0i64;
    v127 = item.mPrev;
    v128 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v128->mPrev = v127;
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    v17 = v193;
    v129 = &v193->m_InteriorCoreDoorsPrefabInstance;
    if ( v193->m_InteriorCoreDoorsPrefabInstance.m_pPointer )
    {
      v130 = v129->mPrev;
      v131 = v193->m_InteriorCoreDoorsPrefabInstance.mNext;
      v130->mNext = v131;
      v131->mPrev = v130;
      v129->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v129->mPrev;
      v129->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v129->mPrev;
    }
    v129->m_pPointer = (UFG::SimComponent *)&v114->vfptr;
    if ( v114 )
    {
      v132 = v114->m_SafePointerList.mNode.mPrev;
      v132->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v129->mPrev;
      v129->mPrev = v132;
      v129->mNext = &v114->m_SafePointerList.mNode;
      v114->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v129->mPrev;
    }
    v6 = v197;
  }
  UFG::qString::Format(&v194, "TurfRacketDecals-%s", v199);
  v133 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&isBusiness, v194.mData);
  v134 = UFG::RacketInstance::DecalsPrefab(v5, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v134, v133, &result, &prefabInstance) )
  {
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.m_pPointer = (UFG::SimComponent *)&prefabInstance->vfptr;
    if ( prefabInstance )
    {
      v135 = &prefabInstance->m_SafePointerList.mNode;
      v136 = prefabInstance->m_SafePointerList.mNode.mPrev;
      v136->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mPrev = v136;
      item.mNext = v135;
      v135->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    v137 = v18->size;
    v138 = v137 + 1;
    v139 = v18->capacity;
    if ( (signed int)v137 + 1 > v139 )
    {
      if ( v139 )
        v140 = 2 * v139;
      else
        v140 = 1;
      for ( ; v140 < v138; v140 *= 2 )
        ;
      if ( v140 - v138 > 0x10000 )
        v140 = v137 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(v18, v140, "qArray.Add");
    }
    v18->size = v138;
    v141 = &v18->p[v137];
    v142 = item.m_pPointer;
    if ( v141->m_pPointer )
    {
      v143 = v141->mPrev;
      v144 = v141->mNext;
      v143->mNext = v144;
      v144->mPrev = v143;
      v141->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v141->mPrev;
      v141->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v141->mPrev;
    }
    v141->m_pPointer = v142;
    if ( v142 )
    {
      v145 = v142->m_SafePointerList.mNode.mPrev;
      v145->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v141->mPrev;
      v141->mPrev = v145;
      v141->mNext = &v142->m_SafePointerList.mNode;
      v142->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v141->mPrev;
    }
    if ( item.m_pPointer )
    {
      v146 = item.mPrev;
      v147 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v147->mPrev = v146;
      item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    item.m_pPointer = 0i64;
    v148 = item.mPrev;
    v149 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v149->mPrev = v148;
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    v6 = v197;
  }
  if ( v5->mData )
  {
    if ( v5->mType.mData )
    {
      if ( (signed int)v5->mData->construction_time_left > 0 )
      {
        UFG::qString::Format(&v194, "TurfRacketUnderConstruction-%s", v199);
        v150 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&isBusiness, v194.mData);
        v151 = UFG::RacketInstance::UnderConstructionPrefab(v5, (UFG::qSymbol *)&v198);
        if ( UFG::TurfComponent::SpawnPrefab(v6, v151, v150, &result, &prefabInstance) )
        {
          item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
          item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
          item.m_pPointer = (UFG::SimComponent *)&prefabInstance->vfptr;
          if ( prefabInstance )
          {
            v152 = &prefabInstance->m_SafePointerList.mNode;
            v153 = prefabInstance->m_SafePointerList.mNode.mPrev;
            v153->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
            item.mPrev = v153;
            item.mNext = v152;
            v152->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
          }
          UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0>::Add(
            (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0> *)v18,
            &item,
            "qArray.Add");
          if ( item.m_pPointer )
          {
            v154 = item.mPrev;
            v155 = item.mNext;
            item.mPrev->mNext = item.mNext;
            v155->mPrev = v154;
            item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
            item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
          }
          item.m_pPointer = 0i64;
          v156 = item.mPrev;
          v157 = item.mNext;
          item.mPrev->mNext = item.mNext;
          v157->mPrev = v156;
          item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
          item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
        }
      }
    }
  }
  UFG::qString::Format(&v194, "TurfRacketTheme-%s", v199);
  v158 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&isBusiness, v194.mData);
  v159 = UFG::RacketInstance::ThemePrefab(v5, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v159, v158, &result, &prefabInstance) )
  {
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.m_pPointer = (UFG::SimComponent *)&prefabInstance->vfptr;
    if ( prefabInstance )
    {
      v160 = &prefabInstance->m_SafePointerList.mNode;
      v161 = prefabInstance->m_SafePointerList.mNode.mPrev;
      v161->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mPrev = v161;
      item.mNext = v160;
      v160->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    v162 = v18->size;
    v163 = v162 + 1;
    v164 = v18->capacity;
    if ( (signed int)v162 + 1 > v164 )
    {
      if ( v164 )
        v10 = 2 * v164;
      for ( ; v10 < v163; v10 *= 2 )
        ;
      if ( v10 - v163 > 0x10000 )
        v10 = v162 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(v18, v10, "qArray.Add");
    }
    v18->size = v163;
    v165 = &v18->p[v162];
    v166 = item.m_pPointer;
    if ( v165->m_pPointer )
    {
      v167 = v165->mPrev;
      v168 = v165->mNext;
      v167->mNext = v168;
      v168->mPrev = v167;
      v165->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v165->mPrev;
      v165->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v165->mPrev;
    }
    v165->m_pPointer = v166;
    if ( v166 )
    {
      v169 = v166->m_SafePointerList.mNode.mPrev;
      v169->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v165->mPrev;
      v165->mPrev = v169;
      v165->mNext = &v166->m_SafePointerList.mNode;
      v166->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v165->mPrev;
    }
    if ( item.m_pPointer )
    {
      v170 = item.mPrev;
      v171 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v171->mPrev = v170;
      item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    }
    item.m_pPointer = 0i64;
    v172 = item.mPrev;
    v173 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v173->mPrev = v172;
    item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
    v6 = v197;
  }
  if ( LOBYTE(v200.mUID) )
  {
    UFG::qString::Format(&v194, "TurfRacketAmbient-%s", v199);
    v182 = UFG::qSymbol::create_from_string(&v200, v194.mData);
    v183 = UFG::RacketInstance::AmbientPrefab(v5, (UFG::qSymbol *)&isBusiness);
    if ( UFG::TurfComponent::SpawnPrefab(v6, v183, v182, &result, &prefabInstance) )
    {
      item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      v184 = prefabInstance;
      item.m_pPointer = (UFG::SimComponent *)&prefabInstance->vfptr;
      if ( prefabInstance )
      {
        v185 = prefabInstance->m_SafePointerList.mNode.mPrev;
        v185->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
        item.mPrev = v185;
        item.mNext = &v184->m_SafePointerList.mNode;
        v184->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      }
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0>::Add(
        (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0> *)v18,
        &item,
        "qArray.Add");
      if ( item.m_pPointer )
      {
        v186 = item.mPrev;
        v187 = item.mNext;
        item.mPrev->mNext = item.mNext;
        v187->mPrev = v186;
        item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
        item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      }
      item.m_pPointer = 0i64;
      v188 = item.mPrev;
      v189 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v189->mPrev = v188;
      item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      UFG::SpawnedRacket::SetAmbientPrefabInstance(v17, v184);
    }
  }
  else
  {
    UFG::qString::Format(&v194, "TurfRacketRaiding-%s", v199);
    v174 = UFG::qSymbol::create_from_string(&v200, v194.mData);
    v175 = UFG::RacketInstance::GameplayPrefab(v5, (UFG::qSymbol *)&isBusiness);
    if ( UFG::TurfComponent::SpawnPrefab(v6, v175, v174, &result, &prefabInstance) )
    {
      item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      v176 = prefabInstance;
      item.m_pPointer = (UFG::SimComponent *)&prefabInstance->vfptr;
      if ( prefabInstance )
      {
        v177 = prefabInstance->m_SafePointerList.mNode.mPrev;
        v177->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
        item.mPrev = v177;
        item.mNext = &v176->m_SafePointerList.mNode;
        v176->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      }
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0>::Add(
        (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0> *)v18,
        &item,
        "qArray.Add");
      if ( item.m_pPointer )
      {
        v178 = item.mPrev;
        v179 = item.mNext;
        item.mPrev->mNext = item.mNext;
        v179->mPrev = v178;
        item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
        item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      }
      item.m_pPointer = 0i64;
      v180 = item.mPrev;
      v181 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v181->mPrev = v180;
      item.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      item.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&item;
      UFG::SpawnedRacket::SetGameplayPrefabInstance(v17, v176);
    }
  }
  UFG::qString::~qString(&v194);
  return v17;
}ce(v17, v176);
    }
  }
  UFG::qString::~qString(&v194);
  return v17;
}

// File Line: 501
// RVA: 0x41CE40
char __fastcall UFG::TurfComponent::SpawnPrefab(UFG::TurfComponent *this, UFG::qSymbol *prefabPropertySetId, UFG::qSymbol *sceneObjName, UFG::qMatrix44 *transform, UFG::SceneObjectProperties **prefabInstanceOut)
{
  UFG::qMatrix44 *v5; // r12
  UFG::qSymbol *v6; // r14
  UFG::qSymbol *v7; // r15
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v8; // rsi
  UFG::SceneObjectProperties **v9; // rdi
  UFG::qPropertySet *v11; // rbp
  __int64 v12; // r13
  unsigned int v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // edx
  UFG::SceneObjectProperties *v16; // rax
  char v17; // bl
  UFG::NavManager *v18; // r14
  UFG::TransformNodeComponent *v19; // rbp
  unsigned int v20; // esi
  char *v21; // rbx
  UFG::NavManagerVtbl *v22; // rdi
  unsigned int v23; // eax
  UFG::qString result; // [rsp+28h] [rbp-50h]

  v5 = transform;
  v6 = sceneObjName;
  v7 = prefabPropertySetId;
  v8 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)this;
  v9 = prefabInstanceOut;
  *prefabInstanceOut = 0i64;
  if ( prefabPropertySetId->mUID == -1 )
    return 0;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&prefabInstanceOut);
  v11 = UFG::qPropertySet::CreateContainedSet(v6, "TurfComponentSceneObject");
  v12 = v8[14].size;
  v13 = v12 + 1;
  v14 = v8[14].capacity;
  if ( (signed int)v12 + 1 > v14 )
  {
    if ( v14 )
      v15 = 2 * v14;
    else
      v15 = 1;
    for ( ; v15 < v13; v15 *= 2 )
      ;
    if ( v15 <= 2 )
      v15 = 2;
    if ( v15 - v13 > 0x10000 )
      v15 = v12 + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v8 + 14, v15, "qArray.Add");
  }
  v8[14].size = v13;
  v8[14].p[v12] = (UFG::qReflectInventoryBase *)v11;
  v11->mFlags &= 0xFFFFFFFu;
  v11->mFlags |= 0x20000000u;
  UFG::qPropertySet::AddParent(v11, (UFG::qSymbol *)&UFG::Editor::gsymPrefabLogicalName.mUID);
  UFG::qPropertySet::Set<UFG::qMatrix44>(v11, (UFG::qSymbol *)&UFG::Editor::gsymXformLocal.mUID, v5);
  UFG::qPropertySet::SetWithSchema<UFG::qSymbol>(v11, (UFG::qSymbol *)&gsymPrefabId.mUID, v7);
  UFG::PrefabDB::Load(v7->mUID);
  UFG::PrefabDB::WaitForStreamer(v7->mUID);
  v16 = UFG::SceneObjectProperties::Create(v6, 0i64, v11);
  *v9 = v16;
  if ( v16 )
  {
    UFG::SceneObjectProperties::Activate(v16, 1u, 0i64, 0i64);
    v18 = UFG::NavManager::ms_pInstance;
    if ( UFG::NavManager::ms_pInstance )
    {
      v19 = (*v9)->m_pSimObject->m_pTransformNodeComponent;
      if ( v19 )
      {
        UFG::qString::FormatEx(&result, "%u", v7->mUID);
        v20 = (*v9)->m_NameUID;
        v21 = result.mData;
        UFG::TransformNodeComponent::UpdateWorldTransform(v19);
        v22 = v18->vfptr;
        v23 = UFG::qStringHashUpper32(v21, 0xFFFFFFFF);
        ((void (__fastcall *)(UFG::NavManager *, UFG::qMatrix44 *, _QWORD, _QWORD, signed __int64))v22[1].__vecDelDtor)(
          v18,
          &v19->mWorldTransform,
          v23,
          v20,
          -2i64);
        UFG::qString::~qString(&result);
      }
    }
    v17 = 1;
  }
  else
  {
    v17 = 0;
  }
  UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&prefabInstanceOut);
  return v17;
}

// File Line: 542
// RVA: 0x41E1B0
UFG::SpawnedRacket *__fastcall UFG::TurfComponent::SpawnSafehouseRacket(UFG::TurfComponent *this, unsigned int racketId, const char *sceneObjID, const char *turfMarkerName)
{
  unsigned int v4; // ebx
  UFG::TurfComponent *v5; // r14
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v6; // rcx
  const char *v7; // rax
  UFG::RacketInstanceData *v8; // rax
  UFG::qReflectHandle<UFG::RacketType> *v9; // rax
  UFG::SpawnedRacket *v10; // rsi
  UFG::RacketInstanceData *v11; // rax
  UFG::SpawnedRacket *v12; // rax
  unsigned int v13; // ebx
  char *v14; // rbx
  UFG::qMatrix44 *v15; // rdi
  UFG::qSymbol *v16; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v17; // rdx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v18; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v19; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v20; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v21; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v22; // rax
  UFG::SceneObjectProperties *prefabInstanceOut; // [rsp+30h] [rbp-B8h]
  UFG::qSymbol prefabPropertySetId; // [rsp+38h] [rbp-B0h]
  UFG::qReflectHandle<UFG::RacketType> v25; // [rsp+40h] [rbp-A8h]
  UFG::RacketInstance racket; // [rsp+68h] [rbp-80h]
  UFG::qSymbol v27; // [rsp+A0h] [rbp-48h]
  __int64 v28; // [rsp+A8h] [rbp-40h]
  UFG::qString result; // [rsp+B0h] [rbp-38h]
  UFG::qString v30; // [rsp+D8h] [rbp-10h]
  __int64 v31; // [rsp+148h] [rbp+60h]
  bool v32; // [rsp+150h] [rbp+68h]

  v28 = -2i64;
  v4 = racketId;
  v5 = this;
  UFG::qString::FormatEx(&result, "%s-%s", turfMarkerName, sceneObjID);
  prefabInstanceOut = (UFG::SceneObjectProperties *)&racket.mType;
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&racket.mType.mPrev);
  v7 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v6);
  racket.mType.mTypeUID = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
  racket.mContainingBlock = 0i64;
  v8 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v4);
  racket.mData = v8;
  if ( v8 )
  {
    v9 = UFG::TurfManager::GetRacketType(&v25, v8->type.mData);
    UFG::qReflectHandleBase::operator=(
      (UFG::qReflectHandleBase *)&racket.mType.mPrev,
      (UFG::qReflectHandleBase *)&v9->mPrev);
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v25.mPrev);
  }
  racket.mContainingBlock = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(
                              UFG::PlaceholderGameDB::ms_pSingleton,
                              v4);
  v10 = UFG::TurfComponent::SpawnRacket(v5, &racket, result.mData, v32, 0);
  v11 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v4);
  if ( v11 )
  {
    prefabInstanceOut = 0i64;
    v13 = *(_DWORD *)(v31 + 8) - 1;
    if ( v11->level < v13 )
      v13 = v11->level;
    UFG::qString::qString(&v30);
    prefabPropertySetId.mUID = *(_DWORD *)(200i64 * v13 + *(_QWORD *)v31 + 196);
    UFG::qString::Format(&v30, "TurfSafehouseRacketGround-%s", result.mData);
    v14 = v30.mData;
    v15 = UFG::TurfComponent::GetRacketTransform(v5, (UFG::qMatrix44 *)&v25, &racket);
    v16 = UFG::qSymbol::create_from_string(&v27, v14);
    if ( UFG::TurfComponent::SpawnPrefab(v5, &prefabPropertySetId, v16, v15, &prefabInstanceOut) )
    {
      v25.mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v25;
      v25.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v25;
      v25.mTypeUID = (unsigned __int64)prefabInstanceOut;
      if ( prefabInstanceOut )
      {
        v17 = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&prefabInstanceOut->m_SafePointerList;
        v18 = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)prefabInstanceOut->m_SafePointerList.mNode.mPrev;
        v18->mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v25;
        v25.mPrev = v18;
        v25.mNext = v17;
        v17->mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v25;
      }
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0>::Add(
        &v10->m_PrefabInstances,
        (UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *)&v25,
        "qArray.Add");
      if ( v25.mTypeUID )
      {
        v19 = v25.mPrev;
        v20 = v25.mNext;
        v25.mPrev->mNext = v25.mNext;
        v20->mPrev = v19;
        v25.mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v25;
        v25.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v25;
      }
      v25.mTypeUID = 0i64;
      v21 = v25.mPrev;
      v22 = v25.mNext;
      v25.mPrev->mNext = v25.mNext;
      v22->mPrev = v21;
      v25.mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v25;
      v25.mNext = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&v25;
    }
    UFG::qString::~qString(&v30);
    prefabInstanceOut = (UFG::SceneObjectProperties *)&racket.mType;
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&racket.mType.mPrev);
    UFG::qString::~qString(&result);
    v12 = v10;
  }
  else
  {
    prefabInstanceOut = (UFG::SceneObjectProperties *)&racket.mType;
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&racket.mType.mPrev);
    UFG::qString::~qString(&result);
    v12 = 0i64;
  }
  return v12;
}

// File Line: 576
// RVA: 0x41E460
void __fastcall UFG::TurfComponent::SpawnSafehouseRackets(UFG::TurfComponent *this, const char *turfMarkerName, bool isLocalPlayer)
{
  bool v3; // r15
  const char *v4; // r12
  UFG::TurfComponent *v5; // rdi
  UFG::qTree64Base::BaseNode **v6; // r9
  UFG::TurfInstanceData *v7; // rax
  unsigned int v8; // esi
  unsigned int v9; // er14
  UFG::TurfInstanceData *v10; // rax
  unsigned int v11; // ebx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v12; // rcx
  const char *v13; // rax
  UFG::RacketInstanceData *v14; // rax
  UFG::qReflectHandle<UFG::RacketType> *v15; // rax
  unsigned int v16; // ecx
  unsigned __int64 v17; // rcx
  UFG::TurfInstanceData *v18; // rax
  unsigned int v19; // er14
  UFG::TurfInstanceData *v20; // rax
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v21; // rcx
  const char *v22; // rax
  UFG::RacketInstanceData *v23; // rax
  UFG::qReflectHandle<UFG::RacketType> *v24; // rax
  unsigned int v25; // ecx
  unsigned __int64 v26; // rcx
  UFG::TurfInstanceData *v27; // rax
  UFG::TurfInstanceData *v28; // rax
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v29; // rcx
  const char *v30; // rax
  UFG::RacketInstanceData *v31; // rax
  UFG::qReflectHandle<UFG::RacketType> *v32; // rax
  UFG::qReflectHandle<UFG::RacketType> result; // [rsp+10h] [rbp-31h]
  UFG::RacketInstanceData *v34; // [rsp+38h] [rbp-9h]
  UFG::qReflectHandleBase v35; // [rsp+40h] [rbp-1h]
  UFG::TurfBlockInstanceData *v36; // [rsp+68h] [rbp+27h]
  UFG::qReflectHandleBase *v37; // [rsp+A8h] [rbp+67h]

  v3 = isLocalPlayer;
  v4 = turfMarkerName;
  v5 = this;
  v6 = this->mCurrentTurfTemplate.mData[1].mBaseNode.mNeighbours[0][2].mChildren[0][4].mParent[2].mNeighbours;
  v7 = this->mCurrentTurfInstanceData;
  LOBYTE(result.mNameUID) = isLocalPlayer;
  result.mTypeUID = (unsigned __int64)v6;
  this->mSpawnedSafehouseRacket = UFG::TurfComponent::SpawnSafehouseRacket(
                                    this,
                                    v7->safehouseRacketId,
                                    "Safehouse",
                                    turfMarkerName);
  v8 = -1;
  v9 = -1;
  v10 = v5->mCurrentTurfInstanceData;
  if ( v10 )
    v9 = v10->safehouseRacketId;
  v11 = 0;
  v37 = &v35;
  UFG::qReflectHandleBase::qReflectHandleBase(&v35);
  v13 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v12);
  v35.mTypeUID = UFG::qStringHash64(v13, 0xFFFFFFFFFFFFFFFFui64);
  v36 = 0i64;
  v14 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v9);
  v34 = v14;
  if ( v14 )
  {
    v15 = UFG::TurfManager::GetRacketType(&result, v14->type.mData);
    UFG::qReflectHandleBase::operator=(&v35, (UFG::qReflectHandleBase *)&v15->mPrev);
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mPrev);
  }
  v36 = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(UFG::PlaceholderGameDB::ms_pSingleton, v9);
  if ( v34 )
    v16 = v34->level;
  else
    v16 = 0;
  v5->mSafehouseRacketLevel = v16;
  v37 = &v35;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v35);
  v17 = *(_QWORD *)(v5->mCurrentTurfTemplate.mData[1].mBaseNode.mNeighbours[0][4].mUID + 200) + 128i64;
  v18 = v5->mCurrentTurfInstanceData;
  LOBYTE(result.mNameUID) = v3;
  result.mTypeUID = v17;
  v5->mSpawnedWarehouseRacket = UFG::TurfComponent::SpawnSafehouseRacket(
                                  v5,
                                  v18->warehouseRacketId,
                                  "SafehouseWarehouse",
                                  v4);
  v19 = -1;
  v20 = v5->mCurrentTurfInstanceData;
  if ( v20 )
    v19 = v20->warehouseRacketId;
  v34 = 0i64;
  v37 = &v35;
  UFG::qReflectHandleBase::qReflectHandleBase(&v35);
  v22 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v21);
  v35.mTypeUID = UFG::qStringHash64(v22, 0xFFFFFFFFFFFFFFFFui64);
  v36 = 0i64;
  v23 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v19);
  v34 = v23;
  if ( v23 )
  {
    v24 = UFG::TurfManager::GetRacketType(&result, v23->type.mData);
    UFG::qReflectHandleBase::operator=(&v35, (UFG::qReflectHandleBase *)&v24->mPrev);
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mPrev);
  }
  v36 = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(UFG::PlaceholderGameDB::ms_pSingleton, v19);
  if ( v34 )
    v25 = v34->level;
  else
    v25 = 0;
  v5->mWarehouseRacketLevel = v25;
  v37 = &v35;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v35);
  v26 = (unsigned __int64)v5->mCurrentTurfTemplate.mData[1].mBaseNode.mNeighbours[0][4].mNeighbours[1][4].mParent[2].mNeighbours;
  v27 = v5->mCurrentTurfInstanceData;
  LOBYTE(result.mNameUID) = v3;
  result.mTypeUID = v26;
  v5->mSpawnedTriadTempleRacket = UFG::TurfComponent::SpawnSafehouseRacket(
                                    v5,
                                    v27->triadTempleRacketId,
                                    "SafehouseTemple",
                                    v4);
  v28 = v5->mCurrentTurfInstanceData;
  if ( v28 )
    v8 = v28->triadTempleRacketId;
  v34 = 0i64;
  v37 = &v35;
  UFG::qReflectHandleBase::qReflectHandleBase(&v35);
  v30 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v29);
  v35.mTypeUID = UFG::qStringHash64(v30, 0xFFFFFFFFFFFFFFFFui64);
  v36 = 0i64;
  v31 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, v8);
  v34 = v31;
  if ( v31 )
  {
    v32 = UFG::TurfManager::GetRacketType(&result, v31->type.mData);
    UFG::qReflectHandleBase::operator=(&v35, (UFG::qReflectHandleBase *)&v32->mPrev);
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&result.mPrev);
  }
  v36 = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(UFG::PlaceholderGameDB::ms_pSingleton, v8);
  if ( v34 )
    v11 = v34->level;
  v5->mTriadTempleRacketLevel = v11;
  v37 = &v35;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v35);
}

// File Line: 604
// RVA: 0x41A880
void __fastcall UFG::TurfComponent::DeSpawn(UFG::TurfComponent *this)
{
  unsigned int v1; // eax
  UFG::TurfComponent *v2; // rbx
  __int64 v3; // rdi
  __int64 v4; // rsi
  UFG::SceneObjectProperties *v5; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v6; // rcx
  UFG::SimComponent **v7; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v8; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v9; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v10; // rax
  unsigned int i; // edi
  UFG::SpawnedRacket *v12; // rsi
  UFG::SpawnedRacket *v13; // rdx
  UFG::SpawnedRacket *v14; // rdx
  UFG::SpawnedRacket **v15; // rcx
  UFG::RacketInstanceData **v16; // rcx
  unsigned int v17; // eax
  __int64 v18; // rdi
  __int64 v19; // rsi
  UFG::qPropertySet *v20; // rcx
  UFG::qPropertySet **v21; // rcx

  v1 = this->m_SpawnedTemplatePrefabs.size;
  v2 = this;
  if ( v1 )
  {
    v3 = 0i64;
    v4 = v1;
    do
    {
      v5 = (UFG::SceneObjectProperties *)v2->m_SpawnedTemplatePrefabs.p[v3].m_pPointer;
      if ( v5 )
        UFG::SceneObjectProperties::Deactivate(v5);
      ++v3;
      --v4;
    }
    while ( v4 );
  }
  v6 = v2->m_SpawnedTemplatePrefabs.p;
  if ( v6 )
  {
    v7 = &v6[-1].m_pPointer;
    `eh vector destructor iterator'(
      v6,
      0x18ui64,
      (int)v6[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
    operator delete[](v7);
  }
  v8 = &v2->m_TurfGameplayPrefabInstance;
  v2->m_SpawnedTemplatePrefabs.p = 0i64;
  *(_QWORD *)&v2->m_SpawnedTemplatePrefabs.size = 0i64;
  if ( v2->m_TurfGameplayPrefabInstance.m_pPointer )
  {
    v9 = v8->mPrev;
    v10 = v2->m_TurfGameplayPrefabInstance.mNext;
    v9->mNext = v10;
    v10->mPrev = v9;
    v8->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v8->mPrev;
    v2->m_TurfGameplayPrefabInstance.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->m_TurfGameplayPrefabInstance.mPrev;
  }
  v2->m_TurfGameplayPrefabInstance.m_pPointer = 0i64;
  for ( i = 0; i < v2->m_SpawnedRackets.size; ++i )
  {
    v12 = v2->m_SpawnedRackets.p[i];
    UFG::TurfComponent::ClearRacket(v2, v12);
    if ( v12 )
      v12->vfptr->__vecDelDtor(v12, 1u);
  }
  UFG::TurfComponent::ClearRacket(v2, v2->mSpawnedSafehouseRacket);
  v13 = v2->mSpawnedWarehouseRacket;
  v2->mSpawnedSafehouseRacket = 0i64;
  UFG::TurfComponent::ClearRacket(v2, v13);
  v14 = v2->mSpawnedTriadTempleRacket;
  v2->mSpawnedWarehouseRacket = 0i64;
  UFG::TurfComponent::ClearRacket(v2, v14);
  v2->mSpawnedTriadTempleRacket = 0i64;
  v15 = v2->m_SpawnedRackets.p;
  if ( v15 )
    operator delete[](v15);
  v2->m_SpawnedRackets.p = 0i64;
  *(_QWORD *)&v2->m_SpawnedRackets.size = 0i64;
  v16 = v2->m_BusinessRackets.p;
  if ( v16 )
    operator delete[](v16);
  v2->m_BusinessRackets.p = 0i64;
  *(_QWORD *)&v2->m_BusinessRackets.size = 0i64;
  v17 = v2->m_PrefabSceneObjs.size;
  if ( v17 )
  {
    v18 = 0i64;
    v19 = v17;
    do
    {
      v20 = v2->m_PrefabSceneObjs.p[v18];
      if ( v20 )
        UFG::qPropertySet::Destroy(v20);
      ++v18;
      --v19;
    }
    while ( v19 );
  }
  v21 = v2->m_PrefabSceneObjs.p;
  if ( v21 )
    operator delete[](v21);
  v2->m_PrefabSceneObjs.p = 0i64;
  *(_QWORD *)&v2->m_PrefabSceneObjs.size = 0i64;
  UFG::RemoveAltColorEffect(v2->m_pSimObject->mNode.mUID);
}

// File Line: 646
// RVA: 0x41A650
void __fastcall UFG::TurfComponent::ClearRacket(UFG::TurfComponent *this, UFG::SpawnedRacket *spawnedRacket)
{
  UFG::SpawnedRacket *v2; // rbp
  unsigned int v3; // eax
  __int64 v4; // rsi
  __int64 v5; // r14
  UFG::SceneObjectProperties *v6; // rdi
  void *v7; // rcx
  unsigned __int16 v8; // dx
  UFG::SimComponent *v9; // rax
  unsigned int v10; // ebx
  unsigned int v11; // er15
  UFG::NavManager *v12; // rdi
  UFG::NavManagerVtbl *v13; // rbx
  unsigned int v14; // eax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v15; // rcx
  UFG::SimComponent **v16; // rbx
  UFG::qString result; // [rsp+28h] [rbp-40h]

  if ( spawnedRacket )
  {
    v2 = spawnedRacket;
    v3 = spawnedRacket->m_PrefabInstances.size;
    if ( v3 )
    {
      v4 = 0i64;
      v5 = v3;
      do
      {
        v6 = (UFG::SceneObjectProperties *)v2->m_PrefabInstances.p[v4].m_pPointer;
        if ( v6 )
        {
          v7 = v6->m_pSimObject;
          if ( v7 )
          {
            v8 = *((_WORD *)v7 + 38);
            if ( (v8 >> 14) & 1 )
            {
              v9 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v7, UFG::PrefabComponent::_TypeUID);
            }
            else if ( (v8 & 0x8000u) == 0 )
            {
              if ( (v8 >> 13) & 1 )
              {
                v9 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v7, UFG::PrefabComponent::_TypeUID);
              }
              else if ( (v8 >> 12) & 1 )
              {
                v9 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v7, UFG::PrefabComponent::_TypeUID);
              }
              else
              {
                v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)v7, UFG::PrefabComponent::_TypeUID);
              }
            }
            else
            {
              v9 = UFG::SimObjectGame::GetComponentOfTypeHK((UFG::SimObjectGame *)v7, UFG::PrefabComponent::_TypeUID);
            }
            v7 = v9;
          }
          v10 = **((_DWORD **)v7 + 10);
          v11 = *(_DWORD *)(*((_QWORD *)v7 + 5) + 64i64);
          UFG::SceneObjectProperties::Deactivate(v6);
          UFG::PrefabDB::Unload(v10);
          v12 = UFG::NavManager::ms_pInstance;
          if ( UFG::NavManager::ms_pInstance )
          {
            UFG::qString::FormatEx(&result, "%u", v10);
            v13 = v12->vfptr;
            v14 = UFG::qStringHashUpper32(result.mData, 0xFFFFFFFF);
            (*((void (__fastcall **)(UFG::NavManager *, _QWORD, _QWORD))&v13[1].__vecDelDtor + 1))(v12, v14, v11);
            UFG::qString::~qString(&result);
          }
        }
        ++v4;
        --v5;
      }
      while ( v5 );
    }
    v15 = v2->m_PrefabInstances.p;
    if ( v15 )
    {
      v16 = &v15[-1].m_pPointer;
      `eh vector destructor iterator'(
        v15,
        0x18ui64,
        (int)v15[-1].m_pPointer,
        (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
      operator delete[](v16);
    }
    v2->m_PrefabInstances.p = 0i64;
    *(_QWORD *)&v2->m_PrefabInstances.size = 0i64;
  }
}

// File Line: 844
// RVA: 0x41ADF0
UFG::qMatrix44 *__fastcall UFG::TurfComponent::GetRacketTransform(UFG::TurfComponent *this, UFG::qMatrix44 *result, UFG::RacketInstance *racket)
{
  UFG::RacketInstance *v3; // r14
  UFG::qMatrix44 *v4; // r12
  UFG::TransformNodeComponent *v5; // rbx
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm7_4
  float v19; // xmm6_4
  UFG::qReflectObject *v20; // r15
  unsigned int v21; // esi
  unsigned int v22; // ebx
  unsigned int *v23; // rdi
  UFG::RacketType::eSize v24; // esi
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  UFG::qReflectObject *v28; // rax
  float v29; // xmm0_4
  __m128 v30; // xmm9
  __m128 v31; // xmm10
  __m128 v32; // xmm14
  UFG::qVector4 v33; // xmm15
  UFG::qVector4 v34; // xmm13
  UFG::qVector4 v35; // xmm11
  __m128 v37; // [rsp+20h] [rbp-B8h]
  UFG::qVector3 outOffset; // [rsp+30h] [rbp-A8h]
  UFG::qMatrix44 v39; // [rsp+40h] [rbp-98h]
  __int64 v40; // [rsp+80h] [rbp-58h]
  __m128 v41; // [rsp+88h] [rbp-50h]
  UFG::qMatrix44 dest; // [rsp+98h] [rbp-40h]
  UFG::qMatrix44 b; // [rsp+D8h] [rbp+0h]
  __m128 v44; // [rsp+118h] [rbp+40h]
  UFG::TurfBlockInstance resulta; // [rsp+128h] [rbp+50h]
  __int64 v46; // [rsp+160h] [rbp+88h]
  UFG::qVector2 outPosition; // [rsp+238h] [rbp+160h]

  v46 = -2i64;
  v3 = racket;
  v4 = result;
  v5 = this->m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v5);
  v6 = v5->mWorldTransform.v0.y;
  v7 = v5->mWorldTransform.v0.z;
  v8 = v5->mWorldTransform.v0.w;
  b.v0.x = v5->mWorldTransform.v0.x;
  b.v0.y = v6;
  b.v0.z = v7;
  b.v0.w = v8;
  v9 = v5->mWorldTransform.v1.y;
  v10 = v5->mWorldTransform.v1.z;
  v11 = v5->mWorldTransform.v1.w;
  b.v1.x = v5->mWorldTransform.v1.x;
  b.v1.y = v9;
  b.v1.z = v10;
  b.v1.w = v11;
  v12 = v5->mWorldTransform.v2.y;
  v13 = v5->mWorldTransform.v2.z;
  v14 = v5->mWorldTransform.v2.w;
  b.v2.x = v5->mWorldTransform.v2.x;
  b.v2.y = v12;
  b.v2.z = v13;
  b.v2.w = v14;
  v15 = v5->mWorldTransform.v3.y;
  v16 = v5->mWorldTransform.v3.z;
  v17 = v5->mWorldTransform.v3.w;
  b.v3.x = v5->mWorldTransform.v3.x;
  b.v3.y = v15;
  b.v3.z = v16;
  b.v3.w = v17;
  UFG::RacketInstance::ContainingBlock(v3, &resulta);
  outPosition = 0i64;
  UFG::TurfBlockInstance::GridPosition(&resulta, &outPosition);
  v18 = outPosition.x * UFG::TurfManager::TURF_LOT_SIZE;
  LODWORD(v19) = COERCE_UNSIGNED_INT(outPosition.y * UFG::TurfManager::TURF_LOT_SIZE) ^ _xmm[0];
  if ( resulta.mData && resulta.mTurfData && (v20 = resulta.mTurfTemplate.mData) != 0i64 )
  {
    v21 = 0;
    v22 = 0;
    v23 = resulta.mTurfData->blockId;
    while ( *v23 != UFG::TurfBlockInstance::ID(&resulta) )
    {
      ++v22;
      ++v23;
      if ( v22 >= 8 )
        goto LABEL_9;
    }
    v21 = v22;
LABEL_9:
    v24 = (UFG::RacketType::eSize)v20[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * v21];
  }
  else
  {
    v24 = 0;
  }
  UFG::RacketType::GetWorldSize(v24, (UFG::qVector3 *)&v37);
  v39.v0 = UFG::qMatrix44::msIdentity.v0;
  v39.v1 = UFG::qMatrix44::msIdentity.v1;
  v39.v2 = UFG::qMatrix44::msIdentity.v2;
  v39.v3.x = (float)(v37.m128_f32[0] * 0.5) + v18;
  v39.v3.y = v19 - (float)(v37.m128_f32[1] * 0.5);
  v39.v3.z = v37.m128_f32[2] * 0.5;
  v39.v3.w = 1.0;
  UFG::RacketInstance::BlockPosition(v3, (UFG::qVector3 *)&v37);
  v25 = UFG::qVector3::msZero.x;
  outOffset = UFG::qVector3::msZero;
  v26 = UFG::qVector3::msZero.y;
  v27 = UFG::qVector3::msZero.z;
  if ( v3->mData )
  {
    v28 = v3->mType.mData;
    if ( v28 )
    {
      UFG::RacketType::GetWorldPositionOffset((UFG::RacketType::eSize)v28[1].vfptr, &outOffset);
      v27 = outOffset.z;
      v26 = outOffset.y;
      v25 = outOffset.x;
    }
  }
  v39.v1.z = UFG::qMatrix44::msIdentity.v0.x;
  v39.v1.w = UFG::qMatrix44::msIdentity.v0.y;
  v39.v2.x = UFG::qMatrix44::msIdentity.v0.z;
  v39.v2.y = UFG::qMatrix44::msIdentity.v0.w;
  v39.v2.z = UFG::qMatrix44::msIdentity.v1.x;
  v39.v2.w = UFG::qMatrix44::msIdentity.v1.y;
  v39.v3.x = UFG::qMatrix44::msIdentity.v1.z;
  v39.v3.y = UFG::qMatrix44::msIdentity.v1.w;
  v39.v3.z = UFG::qMatrix44::msIdentity.v2.x;
  v39.v3.w = UFG::qMatrix44::msIdentity.v2.y;
  v40 = *(_QWORD *)&UFG::qMatrix44::msIdentity.v2.z;
  v41.m128_f32[0] = v37.m128_f32[0] + v25;
  v41.m128_f32[1] = v37.m128_f32[1] + v26;
  v41.m128_f32[2] = v37.m128_f32[2] + v27;
  v41.m128_i32[3] = 1065353216;
  dest = UFG::qMatrix44::msIdentity;
  v29 = UFG::TurfBlockInstance::Rotation(&resulta);
  UFG::qRotationMatrixZ(&dest, v29);
  v44 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39.v1.z, *(__m128 *)&v39.v1.z, 0), (__m128)dest.v0);
  v30 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39.v1.z, *(__m128 *)&v39.v1.z, 255), (__m128)dest.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(v44, _xmm),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39.v1.z, *(__m128 *)&v39.v1.z, 85), (__m128)dest.v1)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39.v1.z, *(__m128 *)&v39.v1.z, 170), (__m128)dest.v2)));
  v31 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39.v2.z, *(__m128 *)&v39.v2.z, 255), (__m128)dest.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39.v2.z, *(__m128 *)&v39.v2.z, 0), (__m128)dest.v0),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39.v2.z, *(__m128 *)&v39.v2.z, 85), (__m128)dest.v1)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39.v2.z, *(__m128 *)&v39.v2.z, 170), (__m128)dest.v2)));
  v32 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39.v3.z, *(__m128 *)&v39.v3.z, 255), (__m128)dest.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39.v3.z, *(__m128 *)&v39.v3.z, 0), (__m128)dest.v0),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39.v3.z, *(__m128 *)&v39.v3.z, 85), (__m128)dest.v1)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v39.v3.z, *(__m128 *)&v39.v3.z, 170), (__m128)dest.v2)));
  v37 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), (__m128)dest.v2),
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), (__m128)dest.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), (__m128)dest.v1))),
          _mm_mul_ps(_mm_shuffle_ps(v41, v41, 255), (__m128)dest.v3));
  v44 = _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), (__m128)v39.v0);
  v33 = (UFG::qVector4)_mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), (__m128)v39.v0), (__m128)0i64),
                             _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), (__m128)v39.v1)),
                           _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), (__m128)v39.v2)),
                         _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), (__m128)v39.v3));
  v34 = (UFG::qVector4)_mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), (__m128)v39.v0), (__m128)0i64),
                             _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), (__m128)v39.v1)),
                           _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), (__m128)v39.v2)),
                         _mm_mul_ps(_mm_shuffle_ps(v32, v32, 255), (__m128)v39.v3));
  v35 = (UFG::qVector4)_mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), (__m128)v39.v0), (__m128)0i64),
                             _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), (__m128)v39.v1)),
                           _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), (__m128)v39.v2)),
                         _mm_mul_ps(_mm_shuffle_ps(v37, v37, 255), (__m128)v39.v3));
  v39.v0 = (UFG::qVector4)_mm_add_ps(
                            _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(v44, _xmm),
                                _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), (__m128)v39.v1)),
                              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), (__m128)v39.v2)),
                            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), (__m128)v39.v3));
  v39.v1 = v33;
  v39.v2 = v34;
  v39.v3 = v35;
  UFG::qMatrix44::operator*(&v39, v4, &b);
  outPosition = (UFG::qVector2)&resulta.mTurfTemplate;
  UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&resulta.mTurfTemplate.mPrev);
  return v4;
}

