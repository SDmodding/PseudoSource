// File Line: 47
// RVA: 0x14F8990
__int64 dynamic_initializer_for__UFG::TurfComponent::s_TurfComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::TurfComponent::s_TurfComponentList__);
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
  UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *v3; // rcx
  const char *StaticTypeName; // rax
  UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *mPrev; // rax

  UFG::SimComponent::SimComponent(this, uid);
  this->mPrev = &this->UFG::qNode<UFG::TurfComponent,UFG::TurfComponent>;
  this->mNext = &this->UFG::qNode<UFG::TurfComponent,UFG::TurfComponent>;
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TurfComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TurfComponent::`vftable{for `UFG::UpdateInterface};
  this->m_SpawnedRackets.p = 0i64;
  *(_QWORD *)&this->m_SpawnedRackets.size = 0i64;
  this->mSpawnedSafehouseRacket = 0i64;
  this->mSafehouseRacketLevel = 0;
  this->mSpawnedWarehouseRacket = 0i64;
  this->mWarehouseRacketLevel = 0;
  this->mSpawnedTriadTempleRacket = 0i64;
  this->mTriadTempleRacketLevel = 0;
  this->m_BusinessRackets.p = 0i64;
  *(_QWORD *)&this->m_BusinessRackets.size = 0i64;
  this->m_BusinessRackets2.p = 0i64;
  *(_QWORD *)&this->m_BusinessRackets2.size = 0i64;
  this->m_SpawnedTemplatePrefabs.p = 0i64;
  *(_QWORD *)&this->m_SpawnedTemplatePrefabs.size = 0i64;
  this->m_TurfGameplayPrefabInstance.mPrev = &this->m_TurfGameplayPrefabInstance;
  this->m_TurfGameplayPrefabInstance.mNext = &this->m_TurfGameplayPrefabInstance;
  this->m_TurfGameplayPrefabInstance.m_pPointer = 0i64;
  this->m_PrefabSceneObjs.p = 0i64;
  *(_QWORD *)&this->m_PrefabSceneObjs.size = 0i64;
  this->mCurrentTurfInstanceData = 0i64;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mCurrentTurfTemplate);
  StaticTypeName = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(v3);
  this->mCurrentTurfTemplate.mTypeUID = UFG::qStringHash64(StaticTypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::RebindingComponentHandle<UFG::TransformNodeComponent,0>(&this->mTransformNodeComponent);
  this->mSafeLocationSet = 0;
  this->mPlayerIsInTurf = 0;
  this->mRivalIndex = -1;
  this->mTurfIndex = 0;
  mPrev = UFG::TurfComponent::s_TurfComponentList.mNode.mPrev;
  UFG::TurfComponent::s_TurfComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::TurfComponent,UFG::TurfComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *)&UFG::TurfComponent::s_TurfComponentList;
  UFG::TurfComponent::s_TurfComponentList.mNode.mPrev = &this->UFG::qNode<UFG::TurfComponent,UFG::TurfComponent>;
  UFG::SimComponent::AddType(this, UFG::TurfComponent::_TurfComponentTypeUID, "TurfComponent");
}

// File Line: 72
// RVA: 0x419D60
void __fastcall UFG::TurfComponent::~TurfComponent(UFG::TurfComponent *this)
{
  UFG::qPropertySet **p; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p_m_TurfGameplayPrefabInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v8; // rcx
  UFG::SimComponent **p_m_pPointer; // rbx
  UFG::RacketInstance2 *v10; // rcx
  unsigned int *p_mBlockIndex; // rbx
  UFG::RacketInstanceData **v12; // rcx
  UFG::SpawnedRacket **v13; // rcx
  UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *v14; // rcx
  UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> *v15; // rax

  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::TurfComponent::`vftable{for `UFG::SimComponent};
  this->UFG::UpdateInterface::vfptr = (UFG::UpdateInterfaceVtbl *)&UFG::TurfComponent::`vftable{for `UFG::UpdateInterface};
  UFG::RebindingComponentHandle<UFG::RagdollComponent,0>::~RebindingComponentHandle<UFG::RagdollComponent,0>(&this->mTransformNodeComponent);
  UFG::qReflectHandleBase::~qReflectHandleBase(&this->mCurrentTurfTemplate);
  p = this->m_PrefabSceneObjs.p;
  if ( p )
    operator delete[](p);
  this->m_PrefabSceneObjs.p = 0i64;
  *(_QWORD *)&this->m_PrefabSceneObjs.size = 0i64;
  p_m_TurfGameplayPrefabInstance = &this->m_TurfGameplayPrefabInstance;
  if ( this->m_TurfGameplayPrefabInstance.m_pPointer )
  {
    mPrev = p_m_TurfGameplayPrefabInstance->mPrev;
    mNext = this->m_TurfGameplayPrefabInstance.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_TurfGameplayPrefabInstance->mPrev = p_m_TurfGameplayPrefabInstance;
    this->m_TurfGameplayPrefabInstance.mNext = &this->m_TurfGameplayPrefabInstance;
  }
  this->m_TurfGameplayPrefabInstance.m_pPointer = 0i64;
  v6 = p_m_TurfGameplayPrefabInstance->mPrev;
  v7 = this->m_TurfGameplayPrefabInstance.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  p_m_TurfGameplayPrefabInstance->mPrev = p_m_TurfGameplayPrefabInstance;
  this->m_TurfGameplayPrefabInstance.mNext = &this->m_TurfGameplayPrefabInstance;
  v8 = this->m_SpawnedTemplatePrefabs.p;
  if ( v8 )
  {
    p_m_pPointer = &v8[-1].m_pPointer;
    `eh vector destructor iterator(
      v8,
      0x18ui64,
      (int)v8[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
    operator delete[](p_m_pPointer);
  }
  this->m_SpawnedTemplatePrefabs.p = 0i64;
  *(_QWORD *)&this->m_SpawnedTemplatePrefabs.size = 0i64;
  v10 = this->m_BusinessRackets2.p;
  if ( v10 )
  {
    p_mBlockIndex = &v10[-1].mBlockIndex;
    `eh vector destructor iterator(
      v10,
      0x48ui64,
      v10[-1].mBlockIndex,
      (void (__fastcall *)(void *))UFG::RacketInstance2::~RacketInstance2);
    operator delete[](p_mBlockIndex);
  }
  this->m_BusinessRackets2.p = 0i64;
  *(_QWORD *)&this->m_BusinessRackets2.size = 0i64;
  v12 = this->m_BusinessRackets.p;
  if ( v12 )
    operator delete[](v12);
  this->m_BusinessRackets.p = 0i64;
  *(_QWORD *)&this->m_BusinessRackets.size = 0i64;
  v13 = this->m_SpawnedRackets.p;
  if ( v13 )
    operator delete[](v13);
  this->m_SpawnedRackets.p = 0i64;
  *(_QWORD *)&this->m_SpawnedRackets.size = 0i64;
  v14 = this->mPrev;
  v15 = this->mNext;
  v14->mNext = v15;
  v15->mPrev = v14;
  this->mPrev = &this->UFG::qNode<UFG::TurfComponent,UFG::TurfComponent>;
  this->mNext = &this->UFG::qNode<UFG::TurfComponent,UFG::TurfComponent>;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 107
// RVA: 0x41BE10
void __fastcall UFG::TurfComponent::OnAttach(UFG::TurfComponent *this, UFG::SimObject *simObject)
{
  LOCALNAMESPACE::hkNativeResource *v4; // rax
  const char *StateBagImpl; // rax
  UFG::GameDB *v6; // rax
  UFG::TurfInstanceData *TurfInstanceDataForMarkerId; // rax
  UFG::qReflectHandleBase *TurfTemplate; // rax
  _BYTE result[48]; // [rsp+28h] [rbp-30h] BYREF

  v4 = (LOCALNAMESPACE::hkNativeResource *)UFG::GameDB::Instance();
  StateBagImpl = Scaleform::GFx::FontManagerStates::GetStateBagImpl(v4);
  if ( StateBagImpl && *(_DWORD *)(*((_QWORD *)StateBagImpl + 21) + 4i64) != this->m_pSimObject->m_Name.mUID )
  {
    v6 = UFG::GameDB::Instance();
    this->mRivalIndex = UFG::GameDB::GetRivalIndexFor(v6, this);
    this->mTurfIndex = 0;
  }
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
    &this->mTransformNodeComponent,
    simObject);
  TurfInstanceDataForMarkerId = UFG::PlaceholderGameDB::GetTurfInstanceDataForMarkerId(
                                  UFG::PlaceholderGameDB::ms_pSingleton,
                                  this->m_NameUID);
  this->mCurrentTurfInstanceData = TurfInstanceDataForMarkerId;
  if ( TurfInstanceDataForMarkerId )
  {
    TurfTemplate = (UFG::qReflectHandleBase *)UFG::TurfManager::GetTurfTemplate(
                                                (UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *)result,
                                                TurfInstanceDataForMarkerId->templateName.mData);
    UFG::qReflectHandleBase::operator=(&this->mCurrentTurfTemplate, TurfTemplate);
    UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)result);
    UFG::TurfComponent::Spawn(this);
  }
}

// File Line: 135
// RVA: 0x41BEE0
void __fastcall UFG::TurfComponent::OnDetach(UFG::TurfComponent *this)
{
  UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *p_mTransformNodeComponent; // r8
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mNext; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *mPrev; // rdx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v5; // rax
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v6; // rcx

  p_mTransformNodeComponent = &this->mTransformNodeComponent;
  if ( this->mTransformNodeComponent.m_pSimComponent )
  {
    mNext = this->mTransformNodeComponent.mNext;
    mPrev = p_mTransformNodeComponent->mPrev;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mTransformNodeComponent.m_pSimComponent = 0i64;
LABEL_7:
    p_mTransformNodeComponent->m_pSimObject = 0i64;
    p_mTransformNodeComponent->mNext = p_mTransformNodeComponent;
    p_mTransformNodeComponent->mPrev = p_mTransformNodeComponent;
    goto LABEL_8;
  }
  if ( this->mTransformNodeComponent.m_pSimObject
    && (p_mTransformNodeComponent->mPrev != p_mTransformNodeComponent
     || this->mTransformNodeComponent.mNext != &this->mTransformNodeComponent) )
  {
    v5 = this->mTransformNodeComponent.mNext;
    v6 = p_mTransformNodeComponent->mPrev;
    v6->mNext = v5;
    v5->mPrev = v6;
    goto LABEL_7;
  }
LABEL_8:
  p_mTransformNodeComponent->m_Changed = 1;
  UFG::TurfComponent::DeSpawn(this);
}

// File Line: 168
// RVA: 0x41C7B0
void __fastcall UFG::TurfComponent::Spawn(UFG::TurfComponent *this)
{
  UFG::TurfManager *v2; // rax
  char v3; // r13
  unsigned int v4; // r15d
  unsigned int v5; // esi
  unsigned int v6; // eax
  unsigned int BlockIdByIndex; // ebx
  UFG::TurfBlockInstanceData *TurfBlockInstanceData; // r12
  UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *v9; // rcx
  const char *StaticTypeName; // rax
  UFG::TurfInstanceData *TurfInstanceDataForBlockId; // rax
  UFG::qReflectHandleBase *TurfTemplate; // rax
  unsigned int RacketIdByIndex; // ebx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v14; // rcx
  const char *TypeName; // rax
  UFG::RacketInstanceData *RacketInstanceData; // rax
  UFG::qReflectHandleBase *RacketType; // rax
  char *v18; // rax
  UFG::SpawnedRacket *v19; // r12
  __int64 size; // r13
  unsigned int v21; // esi
  unsigned int capacity; // ebx
  unsigned int v23; // ebx
  unsigned __int64 v24; // rax
  UFG::allocator::free_link *v25; // rax
  UFG::SpawnedRacket **v26; // r14
  __int64 i; // r9
  char *v28; // rax
  unsigned int ownerPlayerId; // ebx
  UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *v30; // rcx
  const char *v31; // rax
  UFG::TransformNodeComponent *m_pSimComponent; // rbx
  UFG::qMatrix44 *p_mWorldTransform; // r12
  char *v34; // rax
  UFG::qSymbol *v35; // rbx
  UFG::qSymbol *v36; // rax
  UFG::SceneObjectProperties *v37; // rsi
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax
  __int64 v39; // r15
  unsigned int v40; // ebx
  unsigned int v41; // eax
  unsigned int v42; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *v43; // rdx
  UFG::SimComponent *v44; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v45; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v47; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v48; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v49; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v50; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v51; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p_m_TurfGameplayPrefabInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v53; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v54; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v55; // rax
  UFG::qString v56; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qVector3 box_min; // [rsp+58h] [rbp-A8h] BYREF
  UFG::qVector3 box_max; // [rsp+68h] [rbp-98h] BYREF
  UFG::RacketInstance racket; // [rsp+78h] [rbp-88h] BYREF
  UFG::TurfBlockInstance v60; // [rsp+B0h] [rbp-50h] BYREF
  UFG::TurfInstance v61; // [rsp+E8h] [rbp-18h] BYREF
  __int64 v62; // [rsp+120h] [rbp+20h]
  UFG::qReflectHandle<UFG::RacketType> *v63; // [rsp+128h] [rbp+28h]
  UFG::qReflectHandle<UFG::RacketType> *p_mType; // [rsp+130h] [rbp+30h]
  UFG::qString v65; // [rsp+138h] [rbp+38h] BYREF
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> v66; // [rsp+160h] [rbp+60h] BYREF
  UFG::qReflectHandle<UFG::TurfTemplate> *p_mTemplate; // [rsp+200h] [rbp+100h] BYREF
  UFG::qSymbol v68; // [rsp+208h] [rbp+108h] BYREF
  UFG::SceneObjectProperties *prefabInstanceOut; // [rsp+210h] [rbp+110h] BYREF
  UFG::TurfBlockInstanceData *v70; // [rsp+218h] [rbp+118h]

  v62 = -2i64;
  if ( this->mCurrentTurfInstanceData )
  {
    UFG::TurfComponent::ActivateBoundaryLayer(this);
    v2 = UFG::TurfManager::Instance();
    v3 = UFG::TurfManager::GetLocalPlayerTurf(v2) == (UFG::qNode<UFG::TurfComponent,UFG::TurfComponent> **)this;
    LOBYTE(p_mTemplate) = v3;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v68.mUID = 0;
    do
    {
      BlockIdByIndex = UFG::PlaceholderGameDB::GetBlockIdByIndex(this->mCurrentTurfInstanceData, v6);
      TurfBlockInstanceData = UFG::PlaceholderGameDB::GetTurfBlockInstanceData(
                                UFG::PlaceholderGameDB::ms_pSingleton,
                                BlockIdByIndex);
      v70 = TurfBlockInstanceData;
      if ( TurfBlockInstanceData )
      {
        v60.mData = 0i64;
        v60.mTurfData = 0i64;
        prefabInstanceOut = (UFG::SceneObjectProperties *)&v60.mTurfTemplate;
        UFG::qReflectHandleBase::qReflectHandleBase(&v60.mTurfTemplate);
        StaticTypeName = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(v9);
        v60.mTurfTemplate.mTypeUID = UFG::qStringHash64(StaticTypeName, 0xFFFFFFFFFFFFFFFFui64);
        v60.mData = UFG::PlaceholderGameDB::GetTurfBlockInstanceData(
                      UFG::PlaceholderGameDB::ms_pSingleton,
                      BlockIdByIndex);
        if ( v60.mData )
        {
          TurfInstanceDataForBlockId = UFG::PlaceholderGameDB::GetTurfInstanceDataForBlockId(
                                         UFG::PlaceholderGameDB::ms_pSingleton,
                                         BlockIdByIndex);
          v60.mTurfData = TurfInstanceDataForBlockId;
          if ( TurfInstanceDataForBlockId )
          {
            TurfTemplate = (UFG::qReflectHandleBase *)UFG::TurfManager::GetTurfTemplate(
                                                        (UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject> *)v66.mBaseNode.mNeighbours,
                                                        TurfInstanceDataForBlockId->templateName.mData);
            UFG::qReflectHandleBase::operator=(&v60.mTurfTemplate, TurfTemplate);
            UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)v66.mBaseNode.mNeighbours);
          }
        }
        UFG::TurfBlockInstance::PopulateEmptyLots(&v60);
        p_mType = &racket.mType;
        do
        {
          RacketIdByIndex = UFG::PlaceholderGameDB::GetRacketIdByIndex(TurfBlockInstanceData, v4);
          racket.mData = 0i64;
          UFG::qReflectHandleBase::qReflectHandleBase(&racket.mType);
          TypeName = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v14);
          racket.mType.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
          racket.mContainingBlock = 0i64;
          RacketInstanceData = UFG::PlaceholderGameDB::GetRacketInstanceData(
                                 UFG::PlaceholderGameDB::ms_pSingleton,
                                 RacketIdByIndex);
          racket.mData = RacketInstanceData;
          if ( RacketInstanceData )
          {
            RacketType = (UFG::qReflectHandleBase *)UFG::TurfManager::GetRacketType(
                                                      &v66,
                                                      RacketInstanceData->type.mData);
            UFG::qReflectHandleBase::operator=(&racket.mType, RacketType);
            UFG::qReflectHandleBase::~qReflectHandleBase((UFG::qReflectHandleBase *)&v66);
          }
          racket.mContainingBlock = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(
                                      UFG::PlaceholderGameDB::ms_pSingleton,
                                      RacketIdByIndex);
          if ( racket.mData && racket.mType.mData )
          {
            v18 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
            UFG::qString::FormatEx(&v56, "%s-%d", v18, v5);
            LODWORD(prefabInstanceOut) = v5 + 1;
            v19 = UFG::TurfComponent::SpawnRacket(this, &racket, v56.mData, v3, 1);
            size = this->m_SpawnedRackets.size;
            v21 = size + 1;
            capacity = this->m_SpawnedRackets.capacity;
            if ( (int)size + 1 > capacity )
            {
              if ( capacity )
                v23 = 2 * capacity;
              else
                v23 = 1;
              for ( ; v23 < v21; v23 *= 2 )
                ;
              if ( v23 <= 2 )
                v23 = 2;
              if ( v23 - v21 > 0x10000 )
                v23 = size + 65537;
              if ( v23 != (_DWORD)size )
              {
                v24 = 8i64 * v23;
                if ( !is_mul_ok(v23, 8ui64) )
                  v24 = -1i64;
                v25 = UFG::qMalloc(v24, "qArray.Add", 0i64);
                v26 = (UFG::SpawnedRacket **)v25;
                if ( this->m_SpawnedRackets.p )
                {
                  for ( i = 0i64; (unsigned int)i < this->m_SpawnedRackets.size; i = (unsigned int)(i + 1) )
                    v25[i] = (UFG::allocator::free_link)this->m_SpawnedRackets.p[i];
                  operator delete[](this->m_SpawnedRackets.p);
                }
                this->m_SpawnedRackets.p = v26;
                this->m_SpawnedRackets.capacity = v23;
              }
            }
            this->m_SpawnedRackets.size = v21;
            this->m_SpawnedRackets.p[size] = v19;
            UFG::qString::~qString(&v56);
            v63 = &racket.mType;
            UFG::qReflectHandleBase::~qReflectHandleBase(&racket.mType);
            v5 = (unsigned int)prefabInstanceOut;
            TurfBlockInstanceData = v70;
            v3 = (char)p_mTemplate;
          }
          else
          {
            prefabInstanceOut = (UFG::SceneObjectProperties *)&racket.mType;
            UFG::qReflectHandleBase::~qReflectHandleBase(&racket.mType);
          }
          ++v4;
        }
        while ( v4 < 4 );
        prefabInstanceOut = (UFG::SceneObjectProperties *)&v60.mTurfTemplate;
        UFG::qReflectHandleBase::~qReflectHandleBase(&v60.mTurfTemplate);
        v4 = 0;
      }
      v6 = v68.mUID + 1;
      v68.mUID = v6;
    }
    while ( v6 < 8 );
    v28 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
    UFG::TurfComponent::SpawnSafehouseRackets(this, v28, v3);
    ownerPlayerId = this->mCurrentTurfInstanceData->ownerPlayerId;
    v61.mData = 0i64;
    v61.mComponent = 0i64;
    p_mTemplate = &v61.mTemplate;
    UFG::qReflectHandleBase::qReflectHandleBase(&v61.mTemplate);
    v31 = UFG::qReflectObjectType<UFG::TurfTemplate,UFG::qReflectObject>::GetStaticTypeName(v30);
    v61.mTemplate.mTypeUID = UFG::qStringHash64(v31, 0xFFFFFFFFFFFFFFFFui64);
    UFG::TurfInstance::Init(&v61, ownerPlayerId);
    m_pSimComponent = (UFG::TransformNodeComponent *)this->mTransformNodeComponent.m_pSimComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimComponent);
    p_mWorldTransform = &m_pSimComponent->mWorldTransform;
    prefabInstanceOut = 0i64;
    UFG::qString::qString(&v65);
    v34 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&this->m_pSimObject->m_Name);
    UFG::qString::Format(&v65, "TurfGameplay-%s", v34);
    v35 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&p_mTemplate, v65.mData);
    v36 = UFG::TurfInstance::GameplayPrefab(&v61, &v68);
    if ( UFG::TurfComponent::SpawnPrefab(this, v36, v35, p_mWorldTransform, &prefabInstanceOut) )
    {
      v56.mPrev = &v56;
      v56.mNext = &v56;
      v37 = prefabInstanceOut;
      *(_QWORD *)&v56.mMagic = prefabInstanceOut;
      if ( prefabInstanceOut )
      {
        mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)prefabInstanceOut->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
        mPrev->mNext = &v56;
        v56.mPrev = mPrev;
        v56.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v37->m_SafePointerList;
        v37->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v56;
      }
      v39 = this->m_SpawnedTemplatePrefabs.size;
      v40 = v39 + 1;
      v41 = this->m_SpawnedTemplatePrefabs.capacity;
      if ( (int)v39 + 1 > v41 )
      {
        v42 = 1;
        if ( v41 )
          v42 = 2 * v41;
        for ( ; v42 < v40; v42 *= 2 )
          ;
        if ( v42 - v40 > 0x10000 )
          v42 = v39 + 65537;
        UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
          (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *)&this->m_SpawnedTemplatePrefabs,
          v42,
          "qArray.Add");
      }
      this->m_SpawnedTemplatePrefabs.size = v40;
      v43 = &this->m_SpawnedTemplatePrefabs.p[v39];
      v44 = *(UFG::SimComponent **)&v56.mMagic;
      if ( v43->m_pPointer )
      {
        v45 = v43->mPrev;
        mNext = v43->mNext;
        v45->mNext = mNext;
        mNext->mPrev = v45;
        v43->mPrev = v43;
        v43->mNext = v43;
      }
      v43->m_pPointer = v44;
      if ( v44 )
      {
        v47 = v44->m_SafePointerList.mNode.mPrev;
        v47->mNext = v43;
        v43->mPrev = v47;
        v43->mNext = &v44->m_SafePointerList.mNode;
        v44->m_SafePointerList.mNode.mPrev = v43;
      }
      if ( *(_QWORD *)&v56.mMagic )
      {
        v48 = v56.mPrev;
        v49 = v56.mNext;
        v56.mPrev->mNext = v56.mNext;
        v49->mPrev = v48;
        v56.mPrev = &v56;
        v56.mNext = &v56;
      }
      *(_QWORD *)&v56.mMagic = 0i64;
      v50 = v56.mPrev;
      v51 = v56.mNext;
      v56.mPrev->mNext = v56.mNext;
      v51->mPrev = v50;
      v56.mPrev = &v56;
      v56.mNext = &v56;
      p_m_TurfGameplayPrefabInstance = &this->m_TurfGameplayPrefabInstance;
      if ( this->m_TurfGameplayPrefabInstance.m_pPointer )
      {
        v53 = p_m_TurfGameplayPrefabInstance->mPrev;
        v54 = this->m_TurfGameplayPrefabInstance.mNext;
        v53->mNext = v54;
        v54->mPrev = v53;
        p_m_TurfGameplayPrefabInstance->mPrev = p_m_TurfGameplayPrefabInstance;
        this->m_TurfGameplayPrefabInstance.mNext = &this->m_TurfGameplayPrefabInstance;
      }
      this->m_TurfGameplayPrefabInstance.m_pPointer = v37;
      if ( v37 )
      {
        v55 = v37->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
        v55->mNext = p_m_TurfGameplayPrefabInstance;
        p_m_TurfGameplayPrefabInstance->mPrev = v55;
        this->m_TurfGameplayPrefabInstance.mNext = &v37->m_SafePointerList.mNode;
        v37->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_TurfGameplayPrefabInstance;
      }
    }
    box_min.x = FLOAT_N56_0;
    box_min.y = FLOAT_N168_0;
    box_min.z = FLOAT_N50_0;
    box_max.x = FLOAT_168_0;
    box_max.y = FLOAT_56_0;
    box_max.z = FLOAT_75_0;
    UFG::AddAltColorEffect(this->m_pSimObject->mNode.mUID, p_mWorldTransform, &box_min, &box_max);
    UFG::qString::~qString(&v65);
    p_mTemplate = &v61.mTemplate;
    UFG::qReflectHandleBase::~qReflectHandleBase(&v61.mTemplate);
  }
}

// File Line: 246
// RVA: 0x41A0B0
UFG::qPropertyList *__fastcall UFG::TurfComponent::ActivateBoundaryLayer(UFG::TurfComponent *this)
{
  unsigned __int8 v1; // di
  UFG::SceneObjectProperties *m_pSceneObj; // rcx
  UFG::qPropertySet *mpWritableProperties; // rbp
  UFG::qPropertyList *result; // rax
  UFG::qPropertyList *v5; // r14
  unsigned int mNumElements; // esi
  unsigned int i; // ebx
  UFG::qArray<unsigned long,0> *v8; // rax
  UFG::qSymbol *v9; // rax
  UFG::qBaseTreeRB *Layer; // rax

  v1 = 1;
  m_pSceneObj = this->m_pSimObject->m_pSceneObj;
  mpWritableProperties = m_pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = m_pSceneObj->mpConstProperties;
  if ( (_S4_7 & 1) == 0 )
  {
    _S4_7 |= 1u;
    UFG::qSymbol::create_from_string(&qSymbol_TurfBoundaryLayers, "TurfBoundaryLayers");
    atexit(UFG::TurfComponent::ActivateBoundaryLayer_::_2_::_dynamic_atexit_destructor_for__qSymbol_TurfBoundaryLayers__);
  }
  result = UFG::qPropertySet::Get<UFG::qPropertyList>(
             mpWritableProperties,
             (UFG::qArray<unsigned long,0> *)&qSymbol_TurfBoundaryLayers,
             DEPTH_RECURSE);
  v5 = result;
  if ( result )
  {
    mNumElements = result->mNumElements;
    for ( i = 0; i < mNumElements; ++i )
    {
      v8 = (UFG::qArray<unsigned long,0> *)UFG::qPropertyList::Get<UFG::qSymbol>(v5, i);
      v9 = UFG::qPropertySet::Get<UFG::qSymbol>(mpWritableProperties, v8, DEPTH_RECURSE);
      if ( v9 )
      {
        Layer = UFG::Scene::FindLayer(&UFG::Scene::msDefault, v9);
        if ( Layer )
          UFG::SceneLayer::EnableActivate((UFG::SceneLayer *)Layer, 1, NON_PERSISTENT, 0);
        else
          v1 = 0;
      }
      else
      {
        v1 = 0;
      }
    }
    return (UFG::qPropertyList *)v1;
  }
  return result;
}

// File Line: 287
// RVA: 0x41D040
UFG::SpawnedRacket *__fastcall UFG::TurfComponent::SpawnRacket(
        UFG::TurfComponent *this,
        UFG::RacketInstance *racket,
        const char *suffix,
        bool isLocalPlayer,
        UFG::qSymbol isBusiness)
{
  UFG::TurfComponent *v6; // r14
  UFG::allocator::free_link *v7; // rax
  unsigned int id; // edx
  UFG::SpawnedRacket *v9; // rax
  unsigned int v10; // esi
  UFG::RacketInstanceData *mData; // r15
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_m_BusinessRackets; // rdi
  __int64 size; // r14
  unsigned int v14; // ebx
  unsigned int capacity; // edx
  unsigned int v16; // edx
  UFG::SpawnedRacket *v17; // r15
  UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *p_m_PrefabInstances; // rdi
  UFG::qSymbol *v19; // rbx
  UFG::qSymbol *v20; // rax
  UFG::SceneObjectProperties *v21; // r14
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  __int64 v23; // r15
  unsigned int v24; // ebx
  unsigned int v25; // edx
  unsigned int v26; // edx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v27; // rdx
  UFG::SimComponent *m_pPointer; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v29; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v31; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v32; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v33; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v34; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v35; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p_m_ExteriorCorePrefabInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v37; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v38; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v39; // rax
  UFG::qSymbol *v40; // rbx
  UFG::qSymbol *v41; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *p_m_SafePointerList; // rcx
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
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p_m_ExteriorCoreDoorsPrefabInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v75; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v76; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v77; // rax
  UFG::qSymbol *v78; // rbx
  UFG::qSymbol *v79; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v80; // rcx
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
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v97; // rcx
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
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p_m_InteriorCoreDoorsPrefabInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v130; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v131; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v132; // rax
  UFG::qSymbol *v133; // rbx
  UFG::qSymbol *v134; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v135; // rcx
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
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v152; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v153; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v154; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v155; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v156; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v157; // rax
  UFG::qSymbol *v158; // rbx
  UFG::qSymbol *v159; // rax
  UFG::qList<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList,1,0> *v160; // rcx
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
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> item; // [rsp+30h] [rbp-91h] BYREF
  UFG::SceneObjectProperties *prefabInstance; // [rsp+48h] [rbp-79h] BYREF
  UFG::SpawnedRacket *v193; // [rsp+50h] [rbp-71h]
  UFG::qString v194; // [rsp+58h] [rbp-69h] BYREF
  UFG::qMatrix44 result; // [rsp+80h] [rbp-41h] BYREF
  __int64 v196; // [rsp+C0h] [rbp-1h]
  UFG::allocator::free_link *v198; // [rsp+128h] [rbp+67h] BYREF
  const char *v199; // [rsp+130h] [rbp+6Fh]
  UFG::qSymbol v200; // [rsp+138h] [rbp+77h] BYREF

  LOBYTE(v200.mUID) = isLocalPlayer;
  v199 = suffix;
  v196 = -2i64;
  v6 = this;
  v7 = UFG::qMalloc(0xE0ui64, "SpawnedRacket", 0i64);
  v198 = v7;
  if ( v7 )
  {
    if ( racket->mData )
      id = racket->mData->id;
    else
      id = 0;
    UFG::SpawnedRacket::SpawnedRacket((UFG::SpawnedRacket *)v7, id);
    v193 = v9;
  }
  else
  {
    v193 = 0i64;
  }
  v10 = 1;
  if ( LOBYTE(isBusiness.mUID) )
  {
    mData = racket->mData;
    p_m_BusinessRackets = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v6->m_BusinessRackets;
    size = v6->m_BusinessRackets.size;
    v14 = size + 1;
    capacity = p_m_BusinessRackets->capacity;
    if ( (int)size + 1 > capacity )
    {
      if ( capacity )
        v16 = 2 * capacity;
      else
        v16 = 1;
      for ( ; v16 < v14; v16 *= 2 )
        ;
      if ( v16 <= 2 )
        v16 = 2;
      if ( v16 - v14 > 0x10000 )
        v16 = size + 65537;
      UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_m_BusinessRackets, v16, "qArray.Add");
    }
    p_m_BusinessRackets->size = v14;
    p_m_BusinessRackets->p[size] = (UFG::qReflectInventoryBase *)mData;
    v6 = this;
  }
  v17 = v193;
  p_m_PrefabInstances = (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0> *)&v193->m_PrefabInstances;
  UFG::TurfComponent::GetRacketTransform(v6, &result, racket);
  UFG::qString::qString(&v194);
  prefabInstance = 0i64;
  UFG::qString::Format(&v194, "TurfRacketExteriorCore-%s", v199);
  v19 = UFG::qSymbol::create_from_string(&isBusiness, v194.mData);
  v20 = UFG::RacketInstance::ExteriorCorePrefab(racket, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v20, v19, &result, &prefabInstance) )
  {
    item.mPrev = &item;
    item.mNext = &item;
    v21 = prefabInstance;
    item.m_pPointer = prefabInstance;
    if ( prefabInstance )
    {
      mPrev = prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      mPrev->mNext = &item;
      item.mPrev = mPrev;
      item.mNext = &v21->m_SafePointerList.mNode;
      v21->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = &item;
    }
    v23 = p_m_PrefabInstances->size;
    v24 = v23 + 1;
    v25 = p_m_PrefabInstances->capacity;
    if ( (int)v23 + 1 > v25 )
    {
      if ( v25 )
        v26 = 2 * v25;
      else
        v26 = 1;
      for ( ; v26 < v24; v26 *= 2 )
        ;
      if ( v26 - v24 > 0x10000 )
        v26 = v23 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
        p_m_PrefabInstances,
        v26,
        "qArray.Add");
    }
    p_m_PrefabInstances->size = v24;
    v27 = &p_m_PrefabInstances->p[v23];
    m_pPointer = item.m_pPointer;
    if ( v27->m_pPointer )
    {
      v29 = v27->mPrev;
      mNext = v27->mNext;
      v29->mNext = mNext;
      mNext->mPrev = v29;
      v27->mPrev = v27;
      v27->mNext = v27;
    }
    v27->m_pPointer = m_pPointer;
    if ( m_pPointer )
    {
      v31 = m_pPointer->m_SafePointerList.mNode.mPrev;
      v31->mNext = v27;
      v27->mPrev = v31;
      v27->mNext = &m_pPointer->m_SafePointerList.mNode;
      m_pPointer->m_SafePointerList.mNode.mPrev = v27;
    }
    if ( item.m_pPointer )
    {
      v32 = item.mPrev;
      v33 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v33->mPrev = v32;
      item.mPrev = &item;
      item.mNext = &item;
    }
    item.m_pPointer = 0i64;
    v34 = item.mPrev;
    v35 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v35->mPrev = v34;
    item.mPrev = &item;
    item.mNext = &item;
    v17 = v193;
    p_m_ExteriorCorePrefabInstance = &v193->m_ExteriorCorePrefabInstance;
    if ( v193->m_ExteriorCorePrefabInstance.m_pPointer )
    {
      v37 = p_m_ExteriorCorePrefabInstance->mPrev;
      v38 = v193->m_ExteriorCorePrefabInstance.mNext;
      v37->mNext = v38;
      v38->mPrev = v37;
      p_m_ExteriorCorePrefabInstance->mPrev = p_m_ExteriorCorePrefabInstance;
      p_m_ExteriorCorePrefabInstance->mNext = p_m_ExteriorCorePrefabInstance;
    }
    p_m_ExteriorCorePrefabInstance->m_pPointer = v21;
    if ( v21 )
    {
      v39 = v21->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v39->mNext = p_m_ExteriorCorePrefabInstance;
      p_m_ExteriorCorePrefabInstance->mPrev = v39;
      p_m_ExteriorCorePrefabInstance->mNext = &v21->m_SafePointerList.mNode;
      v21->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_ExteriorCorePrefabInstance;
    }
    v6 = this;
  }
  UFG::qString::Format(&v194, "TurfRacketExteriorCoreProps-%s", v199);
  v40 = UFG::qSymbol::create_from_string(&isBusiness, v194.mData);
  v41 = UFG::RacketInstance::ExteriorCorePropsPrefab(racket, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v41, v40, &result, &prefabInstance) )
  {
    item.mPrev = &item;
    item.mNext = &item;
    item.m_pPointer = prefabInstance;
    if ( prefabInstance )
    {
      p_m_SafePointerList = &prefabInstance->m_SafePointerList;
      v43 = prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v43->mNext = &item;
      item.mPrev = v43;
      item.mNext = &p_m_SafePointerList->mNode;
      p_m_SafePointerList->mNode.mPrev = &item;
    }
    v44 = p_m_PrefabInstances->size;
    v45 = v44 + 1;
    v46 = p_m_PrefabInstances->capacity;
    if ( (int)v44 + 1 > v46 )
    {
      if ( v46 )
        v47 = 2 * v46;
      else
        v47 = 1;
      for ( ; v47 < v45; v47 *= 2 )
        ;
      if ( v47 - v45 > 0x10000 )
        v47 = v44 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
        p_m_PrefabInstances,
        v47,
        "qArray.Add");
    }
    p_m_PrefabInstances->size = v45;
    v48 = &p_m_PrefabInstances->p[v44];
    v49 = item.m_pPointer;
    if ( v48->m_pPointer )
    {
      v50 = v48->mPrev;
      v51 = v48->mNext;
      v50->mNext = v51;
      v51->mPrev = v50;
      v48->mPrev = v48;
      v48->mNext = v48;
    }
    v48->m_pPointer = v49;
    if ( v49 )
    {
      v52 = v49->m_SafePointerList.mNode.mPrev;
      v52->mNext = v48;
      v48->mPrev = v52;
      v48->mNext = &v49->m_SafePointerList.mNode;
      v49->m_SafePointerList.mNode.mPrev = v48;
    }
    if ( item.m_pPointer )
    {
      v53 = item.mPrev;
      v54 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v54->mPrev = v53;
      item.mPrev = &item;
      item.mNext = &item;
    }
    item.m_pPointer = 0i64;
    v55 = item.mPrev;
    v56 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v56->mPrev = v55;
    item.mPrev = &item;
    item.mNext = &item;
    v6 = this;
  }
  UFG::qString::Format(&v194, "TurfRacketExteriorCoreDoors-%s", v199);
  v57 = UFG::qSymbol::create_from_string(&isBusiness, v194.mData);
  v58 = UFG::RacketInstance::ExteriorCoreDoorsPrefab(racket, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v58, v57, &result, &prefabInstance) )
  {
    item.mPrev = &item;
    item.mNext = &item;
    v59 = prefabInstance;
    item.m_pPointer = prefabInstance;
    if ( prefabInstance )
    {
      v60 = prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v60->mNext = &item;
      item.mPrev = v60;
      item.mNext = &v59->m_SafePointerList.mNode;
      v59->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = &item;
    }
    v61 = p_m_PrefabInstances->size;
    v62 = v61 + 1;
    v63 = p_m_PrefabInstances->capacity;
    if ( (int)v61 + 1 > v63 )
    {
      if ( v63 )
        v64 = 2 * v63;
      else
        v64 = 1;
      for ( ; v64 < v62; v64 *= 2 )
        ;
      if ( v64 - v62 > 0x10000 )
        v64 = v61 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
        p_m_PrefabInstances,
        v64,
        "qArray.Add");
    }
    p_m_PrefabInstances->size = v62;
    v65 = &p_m_PrefabInstances->p[v61];
    v66 = item.m_pPointer;
    if ( v65->m_pPointer )
    {
      v67 = v65->mPrev;
      v68 = v65->mNext;
      v67->mNext = v68;
      v68->mPrev = v67;
      v65->mPrev = v65;
      v65->mNext = v65;
    }
    v65->m_pPointer = v66;
    if ( v66 )
    {
      v69 = v66->m_SafePointerList.mNode.mPrev;
      v69->mNext = v65;
      v65->mPrev = v69;
      v65->mNext = &v66->m_SafePointerList.mNode;
      v66->m_SafePointerList.mNode.mPrev = v65;
    }
    if ( item.m_pPointer )
    {
      v70 = item.mPrev;
      v71 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v71->mPrev = v70;
      item.mPrev = &item;
      item.mNext = &item;
    }
    item.m_pPointer = 0i64;
    v72 = item.mPrev;
    v73 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v73->mPrev = v72;
    item.mPrev = &item;
    item.mNext = &item;
    v17 = v193;
    p_m_ExteriorCoreDoorsPrefabInstance = &v193->m_ExteriorCoreDoorsPrefabInstance;
    if ( v193->m_ExteriorCoreDoorsPrefabInstance.m_pPointer )
    {
      v75 = p_m_ExteriorCoreDoorsPrefabInstance->mPrev;
      v76 = v193->m_ExteriorCoreDoorsPrefabInstance.mNext;
      v75->mNext = v76;
      v76->mPrev = v75;
      p_m_ExteriorCoreDoorsPrefabInstance->mPrev = p_m_ExteriorCoreDoorsPrefabInstance;
      p_m_ExteriorCoreDoorsPrefabInstance->mNext = p_m_ExteriorCoreDoorsPrefabInstance;
    }
    p_m_ExteriorCoreDoorsPrefabInstance->m_pPointer = v59;
    if ( v59 )
    {
      v77 = v59->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v77->mNext = p_m_ExteriorCoreDoorsPrefabInstance;
      p_m_ExteriorCoreDoorsPrefabInstance->mPrev = v77;
      p_m_ExteriorCoreDoorsPrefabInstance->mNext = &v59->m_SafePointerList.mNode;
      v59->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_ExteriorCoreDoorsPrefabInstance;
    }
    v6 = this;
  }
  UFG::qString::Format(&v194, "TurfRacketInteriorCore-%s", v199);
  v78 = UFG::qSymbol::create_from_string(&isBusiness, v194.mData);
  v79 = UFG::RacketInstance::InteriorCorePrefab(racket, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v79, v78, &result, &prefabInstance) )
  {
    item.mPrev = &item;
    item.mNext = &item;
    item.m_pPointer = prefabInstance;
    if ( prefabInstance )
    {
      v80 = &prefabInstance->m_SafePointerList;
      v81 = prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v81->mNext = &item;
      item.mPrev = v81;
      item.mNext = &v80->mNode;
      v80->mNode.mPrev = &item;
    }
    v82 = p_m_PrefabInstances->size;
    v83 = v82 + 1;
    v84 = p_m_PrefabInstances->capacity;
    if ( (int)v82 + 1 > v84 )
    {
      if ( v84 )
        v85 = 2 * v84;
      else
        v85 = 1;
      for ( ; v85 < v83; v85 *= 2 )
        ;
      if ( v85 - v83 > 0x10000 )
        v85 = v82 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
        p_m_PrefabInstances,
        v85,
        "qArray.Add");
    }
    p_m_PrefabInstances->size = v83;
    v86 = &p_m_PrefabInstances->p[v82];
    v87 = item.m_pPointer;
    if ( v86->m_pPointer )
    {
      v88 = v86->mPrev;
      v89 = v86->mNext;
      v88->mNext = v89;
      v89->mPrev = v88;
      v86->mPrev = v86;
      v86->mNext = v86;
    }
    v86->m_pPointer = v87;
    if ( v87 )
    {
      v90 = v87->m_SafePointerList.mNode.mPrev;
      v90->mNext = v86;
      v86->mPrev = v90;
      v86->mNext = &v87->m_SafePointerList.mNode;
      v87->m_SafePointerList.mNode.mPrev = v86;
    }
    if ( item.m_pPointer )
    {
      v91 = item.mPrev;
      v92 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v92->mPrev = v91;
      item.mPrev = &item;
      item.mNext = &item;
    }
    item.m_pPointer = 0i64;
    v93 = item.mPrev;
    v94 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v94->mPrev = v93;
    item.mPrev = &item;
    item.mNext = &item;
    v6 = this;
  }
  UFG::qString::Format(&v194, "TurfRacketInteriorCoreProps-%s", v199);
  v95 = UFG::qSymbol::create_from_string(&isBusiness, v194.mData);
  v96 = UFG::RacketInstance::InteriorCorePropsPrefab(racket, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v96, v95, &result, &prefabInstance) )
  {
    item.mPrev = &item;
    item.mNext = &item;
    item.m_pPointer = prefabInstance;
    if ( prefabInstance )
    {
      v97 = &prefabInstance->m_SafePointerList;
      v98 = prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v98->mNext = &item;
      item.mPrev = v98;
      item.mNext = &v97->mNode;
      v97->mNode.mPrev = &item;
    }
    v99 = p_m_PrefabInstances->size;
    v100 = v99 + 1;
    v101 = p_m_PrefabInstances->capacity;
    if ( (int)v99 + 1 > v101 )
    {
      if ( v101 )
        v102 = 2 * v101;
      else
        v102 = 1;
      for ( ; v102 < v100; v102 *= 2 )
        ;
      if ( v102 - v100 > 0x10000 )
        v102 = v99 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
        p_m_PrefabInstances,
        v102,
        "qArray.Add");
    }
    p_m_PrefabInstances->size = v100;
    v103 = &p_m_PrefabInstances->p[v99];
    v104 = item.m_pPointer;
    if ( v103->m_pPointer )
    {
      v105 = v103->mPrev;
      v106 = v103->mNext;
      v105->mNext = v106;
      v106->mPrev = v105;
      v103->mPrev = v103;
      v103->mNext = v103;
    }
    v103->m_pPointer = v104;
    if ( v104 )
    {
      v107 = v104->m_SafePointerList.mNode.mPrev;
      v107->mNext = v103;
      v103->mPrev = v107;
      v103->mNext = &v104->m_SafePointerList.mNode;
      v104->m_SafePointerList.mNode.mPrev = v103;
    }
    if ( item.m_pPointer )
    {
      v108 = item.mPrev;
      v109 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v109->mPrev = v108;
      item.mPrev = &item;
      item.mNext = &item;
    }
    item.m_pPointer = 0i64;
    v110 = item.mPrev;
    v111 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v111->mPrev = v110;
    item.mPrev = &item;
    item.mNext = &item;
    v6 = this;
  }
  UFG::qString::Format(&v194, "TurfRacketInteriorCoreDoors-%s", v199);
  v112 = UFG::qSymbol::create_from_string(&isBusiness, v194.mData);
  v113 = UFG::RacketInstance::InteriorCoreDoorsPrefab(racket, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v113, v112, &result, &prefabInstance) )
  {
    item.mPrev = &item;
    item.mNext = &item;
    v114 = prefabInstance;
    item.m_pPointer = prefabInstance;
    if ( prefabInstance )
    {
      v115 = prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v115->mNext = &item;
      item.mPrev = v115;
      item.mNext = &v114->m_SafePointerList.mNode;
      v114->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = &item;
    }
    v116 = p_m_PrefabInstances->size;
    v117 = v116 + 1;
    v118 = p_m_PrefabInstances->capacity;
    if ( (int)v116 + 1 > v118 )
    {
      if ( v118 )
        v119 = 2 * v118;
      else
        v119 = 1;
      for ( ; v119 < v117; v119 *= 2 )
        ;
      if ( v119 - v117 > 0x10000 )
        v119 = v116 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
        p_m_PrefabInstances,
        v119,
        "qArray.Add");
    }
    p_m_PrefabInstances->size = v117;
    v120 = &p_m_PrefabInstances->p[v116];
    v121 = item.m_pPointer;
    if ( v120->m_pPointer )
    {
      v122 = v120->mPrev;
      v123 = v120->mNext;
      v122->mNext = v123;
      v123->mPrev = v122;
      v120->mPrev = v120;
      v120->mNext = v120;
    }
    v120->m_pPointer = v121;
    if ( v121 )
    {
      v124 = v121->m_SafePointerList.mNode.mPrev;
      v124->mNext = v120;
      v120->mPrev = v124;
      v120->mNext = &v121->m_SafePointerList.mNode;
      v121->m_SafePointerList.mNode.mPrev = v120;
    }
    if ( item.m_pPointer )
    {
      v125 = item.mPrev;
      v126 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v126->mPrev = v125;
      item.mPrev = &item;
      item.mNext = &item;
    }
    item.m_pPointer = 0i64;
    v127 = item.mPrev;
    v128 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v128->mPrev = v127;
    item.mPrev = &item;
    item.mNext = &item;
    v17 = v193;
    p_m_InteriorCoreDoorsPrefabInstance = &v193->m_InteriorCoreDoorsPrefabInstance;
    if ( v193->m_InteriorCoreDoorsPrefabInstance.m_pPointer )
    {
      v130 = p_m_InteriorCoreDoorsPrefabInstance->mPrev;
      v131 = v193->m_InteriorCoreDoorsPrefabInstance.mNext;
      v130->mNext = v131;
      v131->mPrev = v130;
      p_m_InteriorCoreDoorsPrefabInstance->mPrev = p_m_InteriorCoreDoorsPrefabInstance;
      p_m_InteriorCoreDoorsPrefabInstance->mNext = p_m_InteriorCoreDoorsPrefabInstance;
    }
    p_m_InteriorCoreDoorsPrefabInstance->m_pPointer = v114;
    if ( v114 )
    {
      v132 = v114->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v132->mNext = p_m_InteriorCoreDoorsPrefabInstance;
      p_m_InteriorCoreDoorsPrefabInstance->mPrev = v132;
      p_m_InteriorCoreDoorsPrefabInstance->mNext = &v114->m_SafePointerList.mNode;
      v114->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = p_m_InteriorCoreDoorsPrefabInstance;
    }
    v6 = this;
  }
  UFG::qString::Format(&v194, "TurfRacketDecals-%s", v199);
  v133 = UFG::qSymbol::create_from_string(&isBusiness, v194.mData);
  v134 = UFG::RacketInstance::DecalsPrefab(racket, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v134, v133, &result, &prefabInstance) )
  {
    item.mPrev = &item;
    item.mNext = &item;
    item.m_pPointer = prefabInstance;
    if ( prefabInstance )
    {
      v135 = &prefabInstance->m_SafePointerList;
      v136 = prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v136->mNext = &item;
      item.mPrev = v136;
      item.mNext = &v135->mNode;
      v135->mNode.mPrev = &item;
    }
    v137 = p_m_PrefabInstances->size;
    v138 = v137 + 1;
    v139 = p_m_PrefabInstances->capacity;
    if ( (int)v137 + 1 > v139 )
    {
      if ( v139 )
        v140 = 2 * v139;
      else
        v140 = 1;
      for ( ; v140 < v138; v140 *= 2 )
        ;
      if ( v140 - v138 > 0x10000 )
        v140 = v137 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
        p_m_PrefabInstances,
        v140,
        "qArray.Add");
    }
    p_m_PrefabInstances->size = v138;
    v141 = &p_m_PrefabInstances->p[v137];
    v142 = item.m_pPointer;
    if ( v141->m_pPointer )
    {
      v143 = v141->mPrev;
      v144 = v141->mNext;
      v143->mNext = v144;
      v144->mPrev = v143;
      v141->mPrev = v141;
      v141->mNext = v141;
    }
    v141->m_pPointer = v142;
    if ( v142 )
    {
      v145 = v142->m_SafePointerList.mNode.mPrev;
      v145->mNext = v141;
      v141->mPrev = v145;
      v141->mNext = &v142->m_SafePointerList.mNode;
      v142->m_SafePointerList.mNode.mPrev = v141;
    }
    if ( item.m_pPointer )
    {
      v146 = item.mPrev;
      v147 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v147->mPrev = v146;
      item.mPrev = &item;
      item.mNext = &item;
    }
    item.m_pPointer = 0i64;
    v148 = item.mPrev;
    v149 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v149->mPrev = v148;
    item.mPrev = &item;
    item.mNext = &item;
    v6 = this;
  }
  if ( racket->mData )
  {
    if ( racket->mType.mData )
    {
      if ( (int)racket->mData->construction_time_left > 0 )
      {
        UFG::qString::Format(&v194, "TurfRacketUnderConstruction-%s", v199);
        v150 = UFG::qSymbol::create_from_string(&isBusiness, v194.mData);
        v151 = UFG::RacketInstance::UnderConstructionPrefab(racket, (UFG::qSymbol *)&v198);
        if ( UFG::TurfComponent::SpawnPrefab(v6, v151, v150, &result, &prefabInstance) )
        {
          item.mPrev = &item;
          item.mNext = &item;
          item.m_pPointer = prefabInstance;
          if ( prefabInstance )
          {
            v152 = &prefabInstance->m_SafePointerList;
            v153 = prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
            v153->mNext = &item;
            item.mPrev = v153;
            item.mNext = &v152->mNode;
            v152->mNode.mPrev = &item;
          }
          UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0>::Add(
            (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0> *)p_m_PrefabInstances,
            &item,
            "qArray.Add");
          if ( item.m_pPointer )
          {
            v154 = item.mPrev;
            v155 = item.mNext;
            item.mPrev->mNext = item.mNext;
            v155->mPrev = v154;
            item.mPrev = &item;
            item.mNext = &item;
          }
          item.m_pPointer = 0i64;
          v156 = item.mPrev;
          v157 = item.mNext;
          item.mPrev->mNext = item.mNext;
          v157->mPrev = v156;
          item.mPrev = &item;
          item.mNext = &item;
        }
      }
    }
  }
  UFG::qString::Format(&v194, "TurfRacketTheme-%s", v199);
  v158 = UFG::qSymbol::create_from_string(&isBusiness, v194.mData);
  v159 = UFG::RacketInstance::ThemePrefab(racket, (UFG::qSymbol *)&v198);
  if ( UFG::TurfComponent::SpawnPrefab(v6, v159, v158, &result, &prefabInstance) )
  {
    item.mPrev = &item;
    item.mNext = &item;
    item.m_pPointer = prefabInstance;
    if ( prefabInstance )
    {
      v160 = &prefabInstance->m_SafePointerList;
      v161 = prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
      v161->mNext = &item;
      item.mPrev = v161;
      item.mNext = &v160->mNode;
      v160->mNode.mPrev = &item;
    }
    v162 = p_m_PrefabInstances->size;
    v163 = v162 + 1;
    v164 = p_m_PrefabInstances->capacity;
    if ( (int)v162 + 1 > v164 )
    {
      if ( v164 )
        v10 = 2 * v164;
      for ( ; v10 < v163; v10 *= 2 )
        ;
      if ( v10 - v163 > 0x10000 )
        v10 = v162 + 65537;
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent>,0>::Reallocate(
        p_m_PrefabInstances,
        v10,
        "qArray.Add");
    }
    p_m_PrefabInstances->size = v163;
    v165 = &p_m_PrefabInstances->p[v162];
    v166 = item.m_pPointer;
    if ( v165->m_pPointer )
    {
      v167 = v165->mPrev;
      v168 = v165->mNext;
      v167->mNext = v168;
      v168->mPrev = v167;
      v165->mPrev = v165;
      v165->mNext = v165;
    }
    v165->m_pPointer = v166;
    if ( v166 )
    {
      v169 = v166->m_SafePointerList.mNode.mPrev;
      v169->mNext = v165;
      v165->mPrev = v169;
      v165->mNext = &v166->m_SafePointerList.mNode;
      v166->m_SafePointerList.mNode.mPrev = v165;
    }
    if ( item.m_pPointer )
    {
      v170 = item.mPrev;
      v171 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v171->mPrev = v170;
      item.mPrev = &item;
      item.mNext = &item;
    }
    item.m_pPointer = 0i64;
    v172 = item.mPrev;
    v173 = item.mNext;
    item.mPrev->mNext = item.mNext;
    v173->mPrev = v172;
    item.mPrev = &item;
    item.mNext = &item;
    v6 = this;
  }
  if ( LOBYTE(v200.mUID) )
  {
    UFG::qString::Format(&v194, "TurfRacketAmbient-%s", v199);
    v182 = UFG::qSymbol::create_from_string(&v200, v194.mData);
    v183 = UFG::RacketInstance::AmbientPrefab(racket, &isBusiness);
    if ( UFG::TurfComponent::SpawnPrefab(v6, v183, v182, &result, &prefabInstance) )
    {
      item.mPrev = &item;
      item.mNext = &item;
      v184 = prefabInstance;
      item.m_pPointer = prefabInstance;
      if ( prefabInstance )
      {
        v185 = prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
        v185->mNext = &item;
        item.mPrev = v185;
        item.mNext = &v184->m_SafePointerList.mNode;
        v184->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = &item;
      }
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0>::Add(
        (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0> *)p_m_PrefabInstances,
        &item,
        "qArray.Add");
      if ( item.m_pPointer )
      {
        v186 = item.mPrev;
        v187 = item.mNext;
        item.mPrev->mNext = item.mNext;
        v187->mPrev = v186;
        item.mPrev = &item;
        item.mNext = &item;
      }
      item.m_pPointer = 0i64;
      v188 = item.mPrev;
      v189 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v189->mPrev = v188;
      item.mPrev = &item;
      item.mNext = &item;
      UFG::SpawnedRacket::SetAmbientPrefabInstance(v17, v184);
    }
  }
  else
  {
    UFG::qString::Format(&v194, "TurfRacketRaiding-%s", v199);
    v174 = UFG::qSymbol::create_from_string(&v200, v194.mData);
    v175 = UFG::RacketInstance::GameplayPrefab(racket, &isBusiness);
    if ( UFG::TurfComponent::SpawnPrefab(v6, v175, v174, &result, &prefabInstance) )
    {
      item.mPrev = &item;
      item.mNext = &item;
      v176 = prefabInstance;
      item.m_pPointer = prefabInstance;
      if ( prefabInstance )
      {
        v177 = prefabInstance->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
        v177->mNext = &item;
        item.mPrev = v177;
        item.mNext = &v176->m_SafePointerList.mNode;
        v176->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev = &item;
      }
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0>::Add(
        (UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0> *)p_m_PrefabInstances,
        &item,
        "qArray.Add");
      if ( item.m_pPointer )
      {
        v178 = item.mPrev;
        v179 = item.mNext;
        item.mPrev->mNext = item.mNext;
        v179->mPrev = v178;
        item.mPrev = &item;
        item.mNext = &item;
      }
      item.m_pPointer = 0i64;
      v180 = item.mPrev;
      v181 = item.mNext;
      item.mPrev->mNext = item.mNext;
      v181->mPrev = v180;
      item.mPrev = &item;
      item.mNext = &item;
      UFG::SpawnedRacket::SetGameplayPrefabInstance(v17, v176);
    }
  }
  UFG::qString::~qString(&v194);
  return v17;
}wnedRacket::SetGameplayPrefabInstance(v17, v176);
    }
  }
  UFG::qString::~qString(&v194);
  return v17;
}

// File Line: 501
// RVA: 0x41CE40
char __fastcall UFG::TurfComponent::SpawnPrefab(
        UFG::TurfComponent *this,
        UFG::qSymbol *prefabPropertySetId,
        UFG::qSymbol *sceneObjName,
        UFG::qMatrix44 *transform,
        UFG::SceneObjectProperties **prefabInstanceOut)
{
  UFG::SceneObjectProperties **v9; // rdi
  UFG::qPropertySet *ContainedSet; // rbp
  __int64 size; // r13
  unsigned int v13; // ebx
  unsigned int capacity; // edx
  unsigned int v15; // edx
  UFG::SceneObjectProperties *v16; // rax
  char v17; // bl
  UFG::NavManager *v18; // r14
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp
  unsigned int m_NameUID; // esi
  char *mData; // rbx
  UFG::NavManagerVtbl *vfptr; // rdi
  unsigned int v23; // eax
  UFG::qString result; // [rsp+28h] [rbp-50h] BYREF

  v9 = prefabInstanceOut;
  *prefabInstanceOut = 0i64;
  if ( prefabPropertySetId->mUID == -1 )
    return 0;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&prefabInstanceOut);
  ContainedSet = UFG::qPropertySet::CreateContainedSet(sceneObjName, "TurfComponentSceneObject");
  size = this->m_PrefabSceneObjs.size;
  v13 = size + 1;
  capacity = this->m_PrefabSceneObjs.capacity;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v15 = 2 * capacity;
    else
      v15 = 1;
    for ( ; v15 < v13; v15 *= 2 )
      ;
    if ( v15 <= 2 )
      v15 = 2;
    if ( v15 - v13 > 0x10000 )
      v15 = size + 65537;
    UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
      (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->m_PrefabSceneObjs,
      v15,
      "qArray.Add");
  }
  this->m_PrefabSceneObjs.size = v13;
  this->m_PrefabSceneObjs.p[size] = ContainedSet;
  ContainedSet->mFlags &= 0xFFFFFFFu;
  ContainedSet->mFlags |= 0x20000000u;
  UFG::qPropertySet::AddParent(ContainedSet, (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymPrefabLogicalName);
  UFG::qPropertySet::Set<UFG::qMatrix44>(
    ContainedSet,
    (UFG::qArray<unsigned long,0> *)&UFG::Editor::gsymXformLocal,
    transform);
  UFG::qPropertySet::SetWithSchema<UFG::qSymbol>(ContainedSet, &gsymPrefabId, prefabPropertySetId);
  UFG::PrefabDB::Load(prefabPropertySetId->mUID);
  UFG::PrefabDB::WaitForStreamer(prefabPropertySetId->mUID);
  v16 = UFG::SceneObjectProperties::Create(sceneObjName, 0i64, ContainedSet);
  *v9 = v16;
  if ( v16 )
  {
    UFG::SceneObjectProperties::Activate(v16, 1u, 0i64, 0i64);
    v18 = UFG::NavManager::ms_pInstance;
    if ( UFG::NavManager::ms_pInstance )
    {
      m_pTransformNodeComponent = (*v9)->m_pSimObject->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        UFG::qString::FormatEx(&result, "%u", prefabPropertySetId->mUID);
        m_NameUID = (*v9)->m_NameUID;
        mData = result.mData;
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        vfptr = v18->vfptr;
        v23 = UFG::qStringHashUpper32(mData, -1);
        ((void (__fastcall *)(UFG::NavManager *, UFG::qMatrix44 *, _QWORD, _QWORD, __int64))vfptr[1].__vecDelDtor)(
          v18,
          &m_pTransformNodeComponent->mWorldTransform,
          v23,
          m_NameUID,
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
UFG::SpawnedRacket *__fastcall UFG::TurfComponent::SpawnSafehouseRacket(
        UFG::TurfComponent *this,
        unsigned int racketId,
        const char *sceneObjID,
        const char *turfMarkerName)
{
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v6; // rcx
  const char *TypeName; // rax
  UFG::RacketInstanceData *RacketInstanceData; // rax
  UFG::qReflectHandleBase *RacketType; // rax
  UFG::SpawnedRacket *v10; // rsi
  UFG::RacketInstanceData *v11; // rax
  unsigned int level; // ebx
  char *mData; // rbx
  UFG::qMatrix44 *RacketTransform; // rdi
  UFG::qSymbol *v16; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *p_m_SafePointerList; // rdx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mPrev; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v19; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *mNext; // rax
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v21; // rcx
  UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *v22; // rax
  UFG::qSymbol isBusiness; // [rsp+20h] [rbp-C8h]
  UFG::SceneObjectProperties *prefabInstanceOut; // [rsp+30h] [rbp-B8h] BYREF
  UFG::qSymbol prefabPropertySetId; // [rsp+38h] [rbp-B0h] BYREF
  UFG::qReflectHandle<UFG::RacketType> v26; // [rsp+40h] [rbp-A8h] BYREF
  UFG::RacketInstance racket; // [rsp+68h] [rbp-80h] BYREF
  UFG::qSymbol v28; // [rsp+A0h] [rbp-48h] BYREF
  __int64 v29; // [rsp+A8h] [rbp-40h]
  UFG::qString result; // [rsp+B0h] [rbp-38h] BYREF
  UFG::qString v31; // [rsp+D8h] [rbp-10h] BYREF
  __int64 v32; // [rsp+148h] [rbp+60h]
  bool v33; // [rsp+150h] [rbp+68h]

  v29 = -2i64;
  UFG::qString::FormatEx(&result, "%s-%s", turfMarkerName, sceneObjID);
  prefabInstanceOut = (UFG::SceneObjectProperties *)&racket.mType;
  UFG::qReflectHandleBase::qReflectHandleBase(&racket.mType);
  TypeName = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v6);
  racket.mType.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  racket.mContainingBlock = 0i64;
  RacketInstanceData = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, racketId);
  racket.mData = RacketInstanceData;
  if ( RacketInstanceData )
  {
    RacketType = (UFG::qReflectHandleBase *)UFG::TurfManager::GetRacketType(
                                              (UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *)&v26,
                                              RacketInstanceData->type.mData);
    UFG::qReflectHandleBase::operator=(&racket.mType, RacketType);
    UFG::qReflectHandleBase::~qReflectHandleBase(&v26);
  }
  racket.mContainingBlock = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(
                              UFG::PlaceholderGameDB::ms_pSingleton,
                              racketId);
  LOBYTE(isBusiness.mUID) = 0;
  v10 = UFG::TurfComponent::SpawnRacket(this, &racket, result.mData, v33, isBusiness);
  v11 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, racketId);
  if ( v11 )
  {
    prefabInstanceOut = 0i64;
    level = *(_DWORD *)(v32 + 8) - 1;
    if ( v11->level < level )
      level = v11->level;
    UFG::qString::qString(&v31);
    prefabPropertySetId.mUID = *(_DWORD *)(200i64 * level + *(_QWORD *)v32 + 196);
    UFG::qString::Format(&v31, "TurfSafehouseRacketGround-%s", result.mData);
    mData = v31.mData;
    RacketTransform = UFG::TurfComponent::GetRacketTransform(this, (UFG::qMatrix44 *)&v26, &racket);
    v16 = UFG::qSymbol::create_from_string(&v28, mData);
    if ( UFG::TurfComponent::SpawnPrefab(this, &prefabPropertySetId, v16, RacketTransform, &prefabInstanceOut) )
    {
      v26.mPrev = &v26;
      v26.mNext = &v26;
      v26.mTypeUID = (unsigned __int64)prefabInstanceOut;
      if ( prefabInstanceOut )
      {
        p_m_SafePointerList = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)&prefabInstanceOut->m_SafePointerList;
        mPrev = (UFG::qNode<UFG::qReflectHandleBase,UFG::qReflectHandleBase> *)prefabInstanceOut->m_SafePointerList.mNode.UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::mPrev;
        mPrev->mNext = &v26;
        v26.mPrev = mPrev;
        v26.mNext = p_m_SafePointerList;
        p_m_SafePointerList->mPrev = &v26;
      }
      UFG::qArray<UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties>,0>::Add(
        &v10->m_PrefabInstances,
        (UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *)&v26,
        "qArray.Add");
      if ( v26.mTypeUID )
      {
        v19 = v26.mPrev;
        mNext = v26.mNext;
        v26.mPrev->mNext = v26.mNext;
        mNext->mPrev = v19;
        v26.mPrev = &v26;
        v26.mNext = &v26;
      }
      v26.mTypeUID = 0i64;
      v21 = v26.mPrev;
      v22 = v26.mNext;
      v26.mPrev->mNext = v26.mNext;
      v22->mPrev = v21;
      v26.mPrev = &v26;
      v26.mNext = &v26;
    }
    UFG::qString::~qString(&v31);
    prefabInstanceOut = (UFG::SceneObjectProperties *)&racket.mType;
    UFG::qReflectHandleBase::~qReflectHandleBase(&racket.mType);
    UFG::qString::~qString(&result);
    return v10;
  }
  else
  {
    prefabInstanceOut = (UFG::SceneObjectProperties *)&racket.mType;
    UFG::qReflectHandleBase::~qReflectHandleBase(&racket.mType);
    UFG::qString::~qString(&result);
    return 0i64;
  }
}

// File Line: 576
// RVA: 0x41E460
void __fastcall UFG::TurfComponent::SpawnSafehouseRackets(
        UFG::TurfComponent *this,
        const char *turfMarkerName,
        bool isLocalPlayer)
{
  UFG::qTree64Base::BaseNode **mNeighbours; // r9
  UFG::TurfInstanceData *mCurrentTurfInstanceData; // rax
  unsigned int triadTempleRacketId; // esi
  unsigned int safehouseRacketId; // r14d
  UFG::TurfInstanceData *v10; // rax
  unsigned int v11; // ebx
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v12; // rcx
  const char *TypeName; // rax
  UFG::RacketInstanceData *RacketInstanceData; // rax
  UFG::qReflectHandleBase *RacketType; // rax
  unsigned int level; // ecx
  unsigned __int64 v17; // rcx
  UFG::TurfInstanceData *v18; // rax
  unsigned int warehouseRacketId; // r14d
  UFG::TurfInstanceData *v20; // rax
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v21; // rcx
  const char *v22; // rax
  UFG::RacketInstanceData *v23; // rax
  UFG::qReflectHandleBase *v24; // rax
  unsigned int v25; // ecx
  UFG::qTree64Base::BaseNode **v26; // rcx
  UFG::TurfInstanceData *v27; // rax
  UFG::TurfInstanceData *v28; // rax
  UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *v29; // rcx
  const char *v30; // rax
  UFG::RacketInstanceData *v31; // rax
  UFG::qReflectHandleBase *v32; // rax
  UFG::qReflectHandle<UFG::RacketType> result; // [rsp+10h] [rbp-31h] BYREF
  UFG::RacketInstanceData *v34; // [rsp+38h] [rbp-9h]
  UFG::qReflectHandleBase v35; // [rsp+40h] [rbp-1h] BYREF
  UFG::TurfBlockInstanceData *TurfBlockInstanceDataForRacketId; // [rsp+68h] [rbp+27h]
  UFG::qReflectHandleBase *v37; // [rsp+A8h] [rbp+67h]

  mNeighbours = this->mCurrentTurfTemplate.mData[1].mBaseNode.mNeighbours[0][2].mChildren[0][4].mParent[2].mNeighbours;
  mCurrentTurfInstanceData = this->mCurrentTurfInstanceData;
  LOBYTE(result.mNameUID) = isLocalPlayer;
  result.mTypeUID = (unsigned __int64)mNeighbours;
  this->mSpawnedSafehouseRacket = UFG::TurfComponent::SpawnSafehouseRacket(
                                    this,
                                    mCurrentTurfInstanceData->safehouseRacketId,
                                    "Safehouse",
                                    turfMarkerName);
  triadTempleRacketId = -1;
  safehouseRacketId = -1;
  v10 = this->mCurrentTurfInstanceData;
  if ( v10 )
    safehouseRacketId = v10->safehouseRacketId;
  v11 = 0;
  v37 = &v35;
  UFG::qReflectHandleBase::qReflectHandleBase(&v35);
  TypeName = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v12);
  v35.mTypeUID = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  TurfBlockInstanceDataForRacketId = 0i64;
  RacketInstanceData = UFG::PlaceholderGameDB::GetRacketInstanceData(
                         UFG::PlaceholderGameDB::ms_pSingleton,
                         safehouseRacketId);
  v34 = RacketInstanceData;
  if ( RacketInstanceData )
  {
    RacketType = (UFG::qReflectHandleBase *)UFG::TurfManager::GetRacketType(
                                              (UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *)&result,
                                              RacketInstanceData->type.mData);
    UFG::qReflectHandleBase::operator=(&v35, RacketType);
    UFG::qReflectHandleBase::~qReflectHandleBase(&result);
  }
  TurfBlockInstanceDataForRacketId = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(
                                       UFG::PlaceholderGameDB::ms_pSingleton,
                                       safehouseRacketId);
  if ( v34 )
    level = v34->level;
  else
    level = 0;
  this->mSafehouseRacketLevel = level;
  v37 = &v35;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v35);
  v17 = *(_QWORD *)(this->mCurrentTurfTemplate.mData[1].mBaseNode.mNeighbours[0][4].mUID + 200) + 128i64;
  v18 = this->mCurrentTurfInstanceData;
  LOBYTE(result.mNameUID) = isLocalPlayer;
  result.mTypeUID = v17;
  this->mSpawnedWarehouseRacket = UFG::TurfComponent::SpawnSafehouseRacket(
                                    this,
                                    v18->warehouseRacketId,
                                    "SafehouseWarehouse",
                                    turfMarkerName);
  warehouseRacketId = -1;
  v20 = this->mCurrentTurfInstanceData;
  if ( v20 )
    warehouseRacketId = v20->warehouseRacketId;
  v34 = 0i64;
  v37 = &v35;
  UFG::qReflectHandleBase::qReflectHandleBase(&v35);
  v22 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v21);
  v35.mTypeUID = UFG::qStringHash64(v22, 0xFFFFFFFFFFFFFFFFui64);
  TurfBlockInstanceDataForRacketId = 0i64;
  v23 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, warehouseRacketId);
  v34 = v23;
  if ( v23 )
  {
    v24 = (UFG::qReflectHandleBase *)UFG::TurfManager::GetRacketType(
                                       (UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *)&result,
                                       v23->type.mData);
    UFG::qReflectHandleBase::operator=(&v35, v24);
    UFG::qReflectHandleBase::~qReflectHandleBase(&result);
  }
  TurfBlockInstanceDataForRacketId = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(
                                       UFG::PlaceholderGameDB::ms_pSingleton,
                                       warehouseRacketId);
  if ( v34 )
    v25 = v34->level;
  else
    v25 = 0;
  this->mWarehouseRacketLevel = v25;
  v37 = &v35;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v35);
  v26 = this->mCurrentTurfTemplate.mData[1].mBaseNode.mNeighbours[0][4].mNeighbours[1][4].mParent[2].mNeighbours;
  v27 = this->mCurrentTurfInstanceData;
  LOBYTE(result.mNameUID) = isLocalPlayer;
  result.mTypeUID = (unsigned __int64)v26;
  this->mSpawnedTriadTempleRacket = UFG::TurfComponent::SpawnSafehouseRacket(
                                      this,
                                      v27->triadTempleRacketId,
                                      "SafehouseTemple",
                                      turfMarkerName);
  v28 = this->mCurrentTurfInstanceData;
  if ( v28 )
    triadTempleRacketId = v28->triadTempleRacketId;
  v34 = 0i64;
  v37 = &v35;
  UFG::qReflectHandleBase::qReflectHandleBase(&v35);
  v30 = UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject>::GetTypeName(v29);
  v35.mTypeUID = UFG::qStringHash64(v30, 0xFFFFFFFFFFFFFFFFui64);
  TurfBlockInstanceDataForRacketId = 0i64;
  v31 = UFG::PlaceholderGameDB::GetRacketInstanceData(UFG::PlaceholderGameDB::ms_pSingleton, triadTempleRacketId);
  v34 = v31;
  if ( v31 )
  {
    v32 = (UFG::qReflectHandleBase *)UFG::TurfManager::GetRacketType(
                                       (UFG::qReflectObjectType<UFG::RacketType,UFG::qReflectObject> *)&result,
                                       v31->type.mData);
    UFG::qReflectHandleBase::operator=(&v35, v32);
    UFG::qReflectHandleBase::~qReflectHandleBase(&result);
  }
  TurfBlockInstanceDataForRacketId = UFG::PlaceholderGameDB::GetTurfBlockInstanceDataForRacketId(
                                       UFG::PlaceholderGameDB::ms_pSingleton,
                                       triadTempleRacketId);
  if ( v34 )
    v11 = v34->level;
  this->mTriadTempleRacketLevel = v11;
  v37 = &v35;
  UFG::qReflectHandleBase::~qReflectHandleBase(&v35);
}

// File Line: 604
// RVA: 0x41A880
void __fastcall UFG::TurfComponent::DeSpawn(UFG::TurfComponent *this)
{
  unsigned int size; // eax
  __int64 v3; // rdi
  __int64 v4; // rsi
  UFG::SceneObjectProperties *m_pPointer; // rcx
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p; // rcx
  UFG::SimComponent **p_m_pPointer; // rdi
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p_m_TurfGameplayPrefabInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  unsigned int i; // edi
  UFG::SpawnedRacket *v12; // rsi
  UFG::SpawnedRacket *mSpawnedWarehouseRacket; // rdx
  UFG::SpawnedRacket *mSpawnedTriadTempleRacket; // rdx
  UFG::SpawnedRacket **v15; // rcx
  UFG::RacketInstanceData **v16; // rcx
  unsigned int v17; // eax
  __int64 v18; // rdi
  __int64 v19; // rsi
  UFG::qPropertySet *v20; // rcx
  UFG::qPropertySet **v21; // rcx

  size = this->m_SpawnedTemplatePrefabs.size;
  if ( size )
  {
    v3 = 0i64;
    v4 = size;
    do
    {
      m_pPointer = (UFG::SceneObjectProperties *)this->m_SpawnedTemplatePrefabs.p[v3].m_pPointer;
      if ( m_pPointer )
        UFG::SceneObjectProperties::Deactivate(m_pPointer);
      ++v3;
      --v4;
    }
    while ( v4 );
  }
  p = this->m_SpawnedTemplatePrefabs.p;
  if ( p )
  {
    p_m_pPointer = &p[-1].m_pPointer;
    `eh vector destructor iterator(
      p,
      0x18ui64,
      (int)p[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
    operator delete[](p_m_pPointer);
  }
  p_m_TurfGameplayPrefabInstance = &this->m_TurfGameplayPrefabInstance;
  this->m_SpawnedTemplatePrefabs.p = 0i64;
  *(_QWORD *)&this->m_SpawnedTemplatePrefabs.size = 0i64;
  if ( this->m_TurfGameplayPrefabInstance.m_pPointer )
  {
    mPrev = p_m_TurfGameplayPrefabInstance->mPrev;
    mNext = this->m_TurfGameplayPrefabInstance.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_m_TurfGameplayPrefabInstance->mPrev = p_m_TurfGameplayPrefabInstance;
    this->m_TurfGameplayPrefabInstance.mNext = &this->m_TurfGameplayPrefabInstance;
  }
  this->m_TurfGameplayPrefabInstance.m_pPointer = 0i64;
  for ( i = 0; i < this->m_SpawnedRackets.size; ++i )
  {
    v12 = this->m_SpawnedRackets.p[i];
    UFG::TurfComponent::ClearRacket(this, v12);
    if ( v12 )
      v12->vfptr->__vecDelDtor(v12, 1u);
  }
  UFG::TurfComponent::ClearRacket(this, this->mSpawnedSafehouseRacket);
  mSpawnedWarehouseRacket = this->mSpawnedWarehouseRacket;
  this->mSpawnedSafehouseRacket = 0i64;
  UFG::TurfComponent::ClearRacket(this, mSpawnedWarehouseRacket);
  mSpawnedTriadTempleRacket = this->mSpawnedTriadTempleRacket;
  this->mSpawnedWarehouseRacket = 0i64;
  UFG::TurfComponent::ClearRacket(this, mSpawnedTriadTempleRacket);
  this->mSpawnedTriadTempleRacket = 0i64;
  v15 = this->m_SpawnedRackets.p;
  if ( v15 )
    operator delete[](v15);
  this->m_SpawnedRackets.p = 0i64;
  *(_QWORD *)&this->m_SpawnedRackets.size = 0i64;
  v16 = this->m_BusinessRackets.p;
  if ( v16 )
    operator delete[](v16);
  this->m_BusinessRackets.p = 0i64;
  *(_QWORD *)&this->m_BusinessRackets.size = 0i64;
  v17 = this->m_PrefabSceneObjs.size;
  if ( v17 )
  {
    v18 = 0i64;
    v19 = v17;
    do
    {
      v20 = this->m_PrefabSceneObjs.p[v18];
      if ( v20 )
        UFG::qPropertySet::Destroy(v20);
      ++v18;
      --v19;
    }
    while ( v19 );
  }
  v21 = this->m_PrefabSceneObjs.p;
  if ( v21 )
    operator delete[](v21);
  this->m_PrefabSceneObjs.p = 0i64;
  *(_QWORD *)&this->m_PrefabSceneObjs.size = 0i64;
  UFG::RemoveAltColorEffect(this->m_pSimObject->mNode.mUID);
}

// File Line: 646
// RVA: 0x41A650
void __fastcall UFG::TurfComponent::ClearRacket(UFG::TurfComponent *this, UFG::SpawnedRacket *spawnedRacket)
{
  unsigned int size; // eax
  __int64 v4; // rsi
  __int64 v5; // r14
  UFG::SceneObjectProperties *m_pPointer; // rdi
  void *m_pSimObject; // rcx
  __int16 v8; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  unsigned int v10; // ebx
  unsigned int v11; // r15d
  UFG::NavManager *v12; // rdi
  UFG::NavManagerVtbl *vfptr; // rbx
  unsigned int v14; // eax
  UFG::qSafePointer<UFG::SimComponent,UFG::SceneObjectProperties> *p; // rcx
  UFG::SimComponent **p_m_pPointer; // rbx
  UFG::qString result; // [rsp+28h] [rbp-40h] BYREF

  if ( spawnedRacket )
  {
    size = spawnedRacket->m_PrefabInstances.size;
    if ( size )
    {
      v4 = 0i64;
      v5 = size;
      do
      {
        m_pPointer = (UFG::SceneObjectProperties *)spawnedRacket->m_PrefabInstances.p[v4].m_pPointer;
        if ( m_pPointer )
        {
          m_pSimObject = m_pPointer->m_pSimObject;
          if ( m_pSimObject )
          {
            v8 = *((_WORD *)m_pSimObject + 38);
            if ( (v8 & 0x4000) != 0 || v8 < 0 || (v8 & 0x2000) != 0 || (v8 & 0x1000) != 0 )
              ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                    (UFG::SimObjectGame *)m_pSimObject,
                                    UFG::PrefabComponent::_TypeUID);
            else
              ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                    (UFG::SimObject *)m_pSimObject,
                                    UFG::PrefabComponent::_TypeUID);
            m_pSimObject = ComponentOfTypeHK;
          }
          v10 = **((_DWORD **)m_pSimObject + 10);
          v11 = *(_DWORD *)(*((_QWORD *)m_pSimObject + 5) + 64i64);
          UFG::SceneObjectProperties::Deactivate(m_pPointer);
          UFG::PrefabDB::Unload(v10);
          v12 = UFG::NavManager::ms_pInstance;
          if ( UFG::NavManager::ms_pInstance )
          {
            UFG::qString::FormatEx(&result, "%u", v10);
            vfptr = v12->vfptr;
            v14 = UFG::qStringHashUpper32(result.mData, -1);
            (*((void (__fastcall **)(UFG::NavManager *, _QWORD, _QWORD))&vfptr[1].__vecDelDtor + 1))(v12, v14, v11);
            UFG::qString::~qString(&result);
          }
        }
        ++v4;
        --v5;
      }
      while ( v5 );
    }
    p = spawnedRacket->m_PrefabInstances.p;
    if ( p )
    {
      p_m_pPointer = &p[-1].m_pPointer;
      `eh vector destructor iterator(
        p,
        0x18ui64,
        (int)p[-1].m_pPointer,
        (void (__fastcall *)(void *))UFG::qSafePointer<UFG::SimComponent,UFG::HealthComponent>::~qSafePointer<UFG::SimComponent,UFG::HealthComponent>);
      operator delete[](p_m_pPointer);
    }
    spawnedRacket->m_PrefabInstances.p = 0i64;
    *(_QWORD *)&spawnedRacket->m_PrefabInstances.size = 0i64;
  }
}

// File Line: 844
// RVA: 0x41ADF0
UFG::qMatrix44 *__fastcall UFG::TurfComponent::GetRacketTransform(
        UFG::TurfComponent *this,
        UFG::qMatrix44 *result,
        UFG::RacketInstance *racket)
{
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm3_4
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
  UFG::qReflectObject *mData; // r15
  unsigned int v21; // esi
  unsigned int v22; // ebx
  unsigned int *blockId; // rdi
  UFG::RacketType::eSize v24; // esi
  float x; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  UFG::qReflectObject *v28; // rax
  float v29; // xmm0_4
  __m128 v30; // xmm9
  __m128 v31; // xmm10
  __m128 v32; // xmm14
  __m128 v33; // xmm15
  __m128 v34; // xmm13
  __m128 v35; // xmm11
  __m128 v37; // [rsp+20h] [rbp-B8h] BYREF
  UFG::qVector3 outOffset; // [rsp+30h] [rbp-A8h] BYREF
  __m128 v39; // [rsp+40h] [rbp-98h] BYREF
  _BYTE v40[56]; // [rsp+50h] [rbp-88h]
  __m128 v41; // [rsp+88h] [rbp-50h]
  UFG::qMatrix44 dest; // [rsp+98h] [rbp-40h] BYREF
  UFG::qMatrix44 b; // [rsp+D8h] [rbp+0h] BYREF
  __m128 v44; // [rsp+118h] [rbp+40h]
  UFG::TurfBlockInstance resulta; // [rsp+128h] [rbp+50h] BYREF
  __int64 v46; // [rsp+160h] [rbp+88h]
  UFG::qVector2 outPosition; // [rsp+238h] [rbp+160h] BYREF

  v46 = -2i64;
  m_pTransformNodeComponent = this->m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  y = m_pTransformNodeComponent->mWorldTransform.v0.y;
  z = m_pTransformNodeComponent->mWorldTransform.v0.z;
  w = m_pTransformNodeComponent->mWorldTransform.v0.w;
  b.v0.x = m_pTransformNodeComponent->mWorldTransform.v0.x;
  b.v0.y = y;
  b.v0.z = z;
  b.v0.w = w;
  v9 = m_pTransformNodeComponent->mWorldTransform.v1.y;
  v10 = m_pTransformNodeComponent->mWorldTransform.v1.z;
  v11 = m_pTransformNodeComponent->mWorldTransform.v1.w;
  b.v1.x = m_pTransformNodeComponent->mWorldTransform.v1.x;
  b.v1.y = v9;
  b.v1.z = v10;
  b.v1.w = v11;
  v12 = m_pTransformNodeComponent->mWorldTransform.v2.y;
  v13 = m_pTransformNodeComponent->mWorldTransform.v2.z;
  v14 = m_pTransformNodeComponent->mWorldTransform.v2.w;
  b.v2.x = m_pTransformNodeComponent->mWorldTransform.v2.x;
  b.v2.y = v12;
  b.v2.z = v13;
  b.v2.w = v14;
  v15 = m_pTransformNodeComponent->mWorldTransform.v3.y;
  v16 = m_pTransformNodeComponent->mWorldTransform.v3.z;
  v17 = m_pTransformNodeComponent->mWorldTransform.v3.w;
  b.v3.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
  b.v3.y = v15;
  b.v3.z = v16;
  b.v3.w = v17;
  UFG::RacketInstance::ContainingBlock(racket, &resulta);
  outPosition = 0i64;
  UFG::TurfBlockInstance::GridPosition(&resulta, &outPosition);
  v18 = outPosition.x * UFG::TurfManager::TURF_LOT_SIZE;
  LODWORD(v19) = COERCE_UNSIGNED_INT(outPosition.y * UFG::TurfManager::TURF_LOT_SIZE) ^ _xmm[0];
  if ( resulta.mData && resulta.mTurfData && (mData = resulta.mTurfTemplate.mData) != 0i64 )
  {
    v21 = 0;
    v22 = 0;
    blockId = resulta.mTurfData->blockId;
    while ( *blockId != UFG::TurfBlockInstance::ID(&resulta) )
    {
      ++v22;
      ++blockId;
      if ( v22 >= 8 )
        goto LABEL_9;
    }
    v21 = v22;
LABEL_9:
    v24 = (UFG::RacketType::eSize)mData[1].mBaseNode.mNeighbours[1][1].mNeighbours[13 * v21];
  }
  else
  {
    v24 = SMALL;
  }
  UFG::RacketType::GetWorldSize(v24, (UFG::qVector3 *)&v37);
  v39 = (__m128)UFG::qMatrix44::msIdentity.v0;
  *(UFG::qVector4 *)v40 = UFG::qMatrix44::msIdentity.v1;
  *(UFG::qVector4 *)&v40[16] = UFG::qMatrix44::msIdentity.v2;
  *(float *)&v40[32] = (float)(v37.m128_f32[0] * 0.5) + v18;
  *(float *)&v40[36] = v19 - (float)(v37.m128_f32[1] * 0.5);
  *(float *)&v40[40] = v37.m128_f32[2] * 0.5;
  *(_DWORD *)&v40[44] = 1065353216;
  UFG::RacketInstance::BlockPosition(racket, (UFG::qVector3 *)&v37);
  x = UFG::qVector3::msZero.x;
  outOffset = UFG::qVector3::msZero;
  v26 = UFG::qVector3::msZero.y;
  v27 = UFG::qVector3::msZero.z;
  if ( racket->mData )
  {
    v28 = racket->mType.mData;
    if ( v28 )
    {
      UFG::RacketType::GetWorldPositionOffset((UFG::RacketType::eSize)v28[1].vfptr, &outOffset);
      v27 = outOffset.z;
      v26 = outOffset.y;
      x = outOffset.x;
    }
  }
  *(float *)&v40[8] = UFG::qMatrix44::msIdentity.v0.x;
  *(float *)&v40[12] = UFG::qMatrix44::msIdentity.v0.y;
  *(float *)&v40[16] = UFG::qMatrix44::msIdentity.v0.z;
  *(float *)&v40[20] = UFG::qMatrix44::msIdentity.v0.w;
  *(UFG::qVector4 *)&v40[24] = UFG::qMatrix44::msIdentity.v1;
  *(UFG::qVector4 *)&v40[40] = UFG::qMatrix44::msIdentity.v2;
  v41.m128_f32[0] = v37.m128_f32[0] + x;
  v41.m128_f32[1] = v37.m128_f32[1] + v26;
  v41.m128_f32[2] = v37.m128_f32[2] + v27;
  v41.m128_i32[3] = 1065353216;
  dest = UFG::qMatrix44::msIdentity;
  v29 = UFG::TurfBlockInstance::Rotation(&resulta);
  UFG::qRotationMatrixZ(&dest, v29);
  v44 = _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[8], *(__m128 *)&v40[8], 0), (__m128)dest.v0);
  v30 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[8], *(__m128 *)&v40[8], 255), (__m128)dest.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(v44, _xmm),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[8], *(__m128 *)&v40[8], 85), (__m128)dest.v1)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[8], *(__m128 *)&v40[8], 170), (__m128)dest.v2)));
  v31 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[24], *(__m128 *)&v40[24], 255), (__m128)dest.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[24], *(__m128 *)&v40[24], 0), (__m128)dest.v0),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[24], *(__m128 *)&v40[24], 85), (__m128)dest.v1)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[24], *(__m128 *)&v40[24], 170), (__m128)dest.v2)));
  v32 = _mm_add_ps(
          _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[40], *(__m128 *)&v40[40], 255), (__m128)dest.v3),
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[40], *(__m128 *)&v40[40], 0), (__m128)dest.v0),
                (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[40], *(__m128 *)&v40[40], 85), (__m128)dest.v1)),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v40[40], *(__m128 *)&v40[40], 170), (__m128)dest.v2)));
  v37 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v41, v41, 170), (__m128)dest.v2),
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v41, v41, 0), (__m128)dest.v0), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 85), (__m128)dest.v1))),
          _mm_mul_ps(_mm_shuffle_ps(v41, v41, 255), (__m128)dest.v3));
  v44 = _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v39);
  v33 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v39), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), *(__m128 *)v40)),
            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), *(__m128 *)&v40[16])),
          _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), *(__m128 *)&v40[32]));
  v34 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v39), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), *(__m128 *)v40)),
            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), *(__m128 *)&v40[16])),
          _mm_mul_ps(_mm_shuffle_ps(v32, v32, 255), *(__m128 *)&v40[32]));
  v35 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), v39), (__m128)0i64),
              _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), *(__m128 *)v40)),
            _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), *(__m128 *)&v40[16])),
          _mm_mul_ps(_mm_shuffle_ps(v37, v37, 255), *(__m128 *)&v40[32]));
  v39 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_add_ps(v44, _xmm), _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), *(__m128 *)v40)),
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), *(__m128 *)&v40[16])),
          _mm_mul_ps(_mm_shuffle_ps(v30, v30, 255), *(__m128 *)&v40[32]));
  *(__m128 *)v40 = v33;
  *(__m128 *)&v40[16] = v34;
  *(__m128 *)&v40[32] = v35;
  UFG::qMatrix44::operator*((UFG::qMatrix44 *)&v39, result, &b);
  outPosition = (UFG::qVector2)&resulta.mTurfTemplate;
  UFG::qReflectHandleBase::~qReflectHandleBase(&resulta.mTurfTemplate);
  return result;
}

