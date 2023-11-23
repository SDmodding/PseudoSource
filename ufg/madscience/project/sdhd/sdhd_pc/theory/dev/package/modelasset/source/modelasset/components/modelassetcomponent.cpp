// File Line: 26
// RVA: 0x220E30
__int64 __fastcall UFG::PrefabComponent::GetTypeSize(UFG::FrontEndPauseEffect *this)
{
  return 104i64;
}

// File Line: 33
// RVA: 0x220E40
void __fastcall UFG::ModelAssetComponent_PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v3; // rax
  char *MemImagePtr; // rsi
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // rdi
  UFG::allocator::free_link *v9; // rax
  UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject> *mNext; // rcx
  UFG::allocator::free_link *v11; // rbx
  UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject> **v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rax
  const char *TypeName; // rax
  unsigned __int64 v15; // rax
  UFG::SimObjectModifier v16; // [rsp+38h] [rbp-30h] BYREF

  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  v3 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         mpWritableProperties,
         (UFG::qArray<unsigned long,0> *)&component_ModelAsset::sPropertyName,
         DEPTH_RECURSE);
  if ( v3 )
  {
    MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v3);
    if ( MemImagePtr )
    {
      SimulationMemoryPool = UFG::GetSimulationMemoryPool();
      v6 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x68ui64, "ModelAssetComponent", 0i64, 1u);
      if ( v6 )
      {
        UFG::ModelAssetComponent::ModelAssetComponent((UFG::ModelAssetComponent *)v6, *((_QWORD *)MemImagePtr + 1));
        v8 = v7;
      }
      else
      {
        v8 = 0i64;
      }
      UFG::SimObjectModifier::SimObjectModifier(&v16, pSceneObj->m_pSimObject, 1);
      UFG::SimObjectModifier::AttachComponent(&v16, v8, 0xFFFFFFFFi64);
      UFG::SimObjectModifier::Close(&v16);
      UFG::SimObjectModifier::~SimObjectModifier(&v16);
      v9 = UFG::qMalloc(0x18ui64, UFG::gGlobalNewName, 0i64);
      v11 = v9;
      if ( v9 )
      {
        v9->mNext = v9;
        v9[1].mNext = v9;
        v9[2].mNext = 0i64;
      }
      else
      {
        v11 = 0i64;
      }
      if ( v11[2].mNext )
      {
        mNext = (UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject> *)v11->mNext;
        v12 = (UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject> **)v11[1].mNext;
        mNext->mBaseNode.mUID = (unsigned __int64)v12;
        *v12 = mNext;
        v11->mNext = v11;
        v11[1].mNext = v11;
      }
      v11[2].mNext = (UFG::allocator::free_link *)v8;
      if ( v8 )
      {
        mNext = (UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject> *)&v8->m_SafePointerList;
        mPrev = v8->m_SafePointerList.mNode.mPrev;
        mPrev->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v11;
        v11->mNext = (UFG::allocator::free_link *)mPrev;
        v11[1].mNext = (UFG::allocator::free_link *)&v8->m_SafePointerList;
        v8->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v11;
      }
      TypeName = UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject>::GetTypeName(mNext);
      v15 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectOnDemandLoader::LoadCachedReferences(
        v15,
        *((UFG::qReflectInventoryBaseVtbl **)MemImagePtr + 1),
        UFG::ModelAssetComponent::OnModelAssetLoaded,
        v11);
    }
  }
}

// File Line: 51
// RVA: 0x220C10
void __fastcall UFG::ModelAssetComponent::ModelAssetComponent(
        UFG::ModelAssetComponent *this,
        unsigned __int64 model_asset_uid)
{
  UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject> *v4; // rcx
  const char *TypeName; // rax
  unsigned __int64 v6; // rax

  UFG::SimComponent::SimComponent(this, 0);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ModelAssetComponent::`vftable;
  UFG::qReflectHandleBase::qReflectHandleBase(&this->mModelAssetHandle);
  TypeName = UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject>::GetTypeName(v4);
  v6 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init(&this->mModelAssetHandle, v6, model_asset_uid);
  UFG::SimComponent::AddType(this, UFG::ModelAssetComponent::_ModelAssetComponentTypeUID, "ModelAssetComponent");
}

// File Line: 61
// RVA: 0x220FC0
// attributes: thunk
void __fastcall UFG::ModelAssetComponent::OnAttach(UFG::ModelAssetComponent *this, UFG::SimObject *object)
{
  UFG::ModelAssetComponent::ComponentFactory(this);
}

// File Line: 66
// RVA: 0x220FD0
void __fastcall UFG::ModelAssetComponent::OnModelAssetLoaded(__int64 *ptr)
{
  UFG::ModelAssetComponent *v2; // rcx
  __int64 v3; // rcx
  _QWORD *v4; // rax
  __int64 v5; // rcx
  _QWORD *v6; // rax

  v2 = (UFG::ModelAssetComponent *)ptr[2];
  if ( v2 )
    UFG::ModelAssetComponent::ComponentFactory(v2);
  if ( ptr[2] )
  {
    v3 = *ptr;
    v4 = (_QWORD *)ptr[1];
    *(_QWORD *)(v3 + 8) = v4;
    *v4 = v3;
    *ptr = (__int64)ptr;
    ptr[1] = (__int64)ptr;
  }
  ptr[2] = 0i64;
  v5 = *ptr;
  v6 = (_QWORD *)ptr[1];
  *(_QWORD *)(v5 + 8) = v6;
  *v6 = v5;
  *ptr = (__int64)ptr;
  ptr[1] = (__int64)ptr;
  operator delete[](ptr);
}

// File Line: 78
// RVA: 0x221040
void __fastcall UFG::ModelAssetComponent::SetPostComponentFactory(void (__fastcall *func)(UFG::SimObject *))
{
  UFG::gModelAssetPostComponentFactory = func;
}

// File Line: 95
// RVA: 0x220D90
void __fastcall UFG::ModelAssetComponent::ComponentFactory(UFG::ModelAssetComponent *this)
{
  UFG::qReflectObject *mData; // rbx
  UFG::SimObject *m_pSimObject; // rsi
  __int64 i; // rdi
  __int64 v4; // rcx

  mData = this->mModelAssetHandle.mData;
  if ( mData )
  {
    m_pSimObject = this->m_pSimObject;
    UFG::SimObject::StartDeferringAttachment(m_pSimObject);
    for ( i = 0i64; (unsigned int)i < LODWORD(mData[2].mHandles.mNode.mPrev); i = (unsigned int)(i + 1) )
    {
      v4 = *(_QWORD *)(mData[2].mTypeUID + 8 * i);
      (*(void (__fastcall **)(__int64, UFG::SimObject *, UFG::qReflectObject *))(*(_QWORD *)v4 + 24i64))(
        v4,
        m_pSimObject,
        mData);
    }
    if ( UFG::gModelAssetPostComponentFactory )
      UFG::gModelAssetPostComponentFactory(m_pSimObject);
    UFG::SimObject::EndDeferringAttachment(m_pSimObject);
  }
}

