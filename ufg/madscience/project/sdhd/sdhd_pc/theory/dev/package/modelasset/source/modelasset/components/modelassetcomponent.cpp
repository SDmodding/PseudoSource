// File Line: 26
// RVA: 0x220E30
signed __int64 __fastcall UFG::PrefabComponent::GetTypeSize(UFG::FrontEndPauseEffect *this)
{
  return 104i64;
}

// File Line: 33
// RVA: 0x220E40
void __fastcall UFG::ModelAssetComponent_PropertiesOnActivate(UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v1; // rbx
  UFG::qPropertySet *v2; // rcx
  UFG::qPropertySet *v3; // rax
  char *v4; // rsi
  UFG::qMemoryPool *v5; // rax
  UFG::allocator::free_link *v6; // rax
  UFG::SimComponent *v7; // rax
  UFG::SimComponent *v8; // rdi
  UFG::allocator::free_link *v9; // rax
  UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject> *v10; // rcx
  UFG::allocator::free_link *v11; // rbx
  UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject> **v12; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v13; // rax
  const char *v14; // rax
  unsigned __int64 v15; // rax
  UFG::SimObjectModifier v16; // [rsp+38h] [rbp-30h]

  v1 = pSceneObj;
  v2 = pSceneObj->mpWritableProperties;
  if ( !v2 )
    v2 = v1->mpConstProperties;
  v3 = UFG::qPropertySet::Get<UFG::qPropertySet>(
         v2,
         (UFG::qSymbol *)&component_ModelAsset::sPropertyName.mUID,
         DEPTH_RECURSE);
  if ( v3 )
  {
    v4 = UFG::qPropertySet::GetMemImagePtr(v3);
    if ( v4 )
    {
      v5 = UFG::GetSimulationMemoryPool();
      v6 = UFG::qMemoryPool::Allocate(v5, 0x68ui64, "ModelAssetComponent", 0i64, 1u);
      if ( v6 )
      {
        UFG::ModelAssetComponent::ModelAssetComponent((UFG::ModelAssetComponent *)v6, *((_QWORD *)v4 + 1));
        v8 = v7;
      }
      else
      {
        v8 = 0i64;
      }
      UFG::SimObjectModifier::SimObjectModifier(&v16, v1->m_pSimObject, 1);
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
        v10 = (UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject> *)v11->mNext;
        v12 = (UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject> **)v11[1].mNext;
        v10->mBaseNode.mUID = (unsigned __int64)v12;
        *v12 = v10;
        v11->mNext = v11;
        v11[1].mNext = v11;
      }
      v11[2].mNext = (UFG::allocator::free_link *)v8;
      if ( v8 )
      {
        v10 = (UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject> *)&v8->m_SafePointerList;
        v13 = v8->m_SafePointerList.mNode.mPrev;
        v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v11;
        v11->mNext = (UFG::allocator::free_link *)v13;
        v11[1].mNext = (UFG::allocator::free_link *)&v8->m_SafePointerList;
        v8->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)v11;
      }
      v14 = UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject>::GetTypeName(v10);
      v15 = UFG::qStringHash64(v14, 0xFFFFFFFFFFFFFFFFui64);
      UFG::qReflectOnDemandLoader::LoadCachedReferences(
        v15,
        *((_QWORD *)v4 + 1),
        UFG::ModelAssetComponent::OnModelAssetLoaded,
        v11);
    }
  }
}

// File Line: 51
// RVA: 0x220C10
void __fastcall UFG::ModelAssetComponent::ModelAssetComponent(UFG::ModelAssetComponent *this, unsigned __int64 model_asset_uid)
{
  unsigned __int64 v2; // rdi
  UFG::ModelAssetComponent *v3; // rsi
  UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject> *v4; // rcx
  const char *v5; // rax
  unsigned __int64 v6; // rax

  v2 = model_asset_uid;
  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, 0);
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ModelAssetComponent::`vftable';
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qReflectHandleBase *)&v3->mModelAssetHandle.mPrev);
  v5 = UFG::qReflectObjectType<UFG::ModelAsset,UFG::qReflectObject>::GetTypeName(v4);
  v6 = UFG::qStringHash64(v5, 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectHandleBase::Init((UFG::qReflectHandleBase *)&v3->mModelAssetHandle.mPrev, v6, v2);
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::ModelAssetComponent::_ModelAssetComponentTypeUID,
    "ModelAssetComponent");
}

// File Line: 61
// RVA: 0x220FC0
void __fastcall UFG::ModelAssetComponent::OnAttach(UFG::ModelAssetComponent *this, UFG::SimObject *object)
{
  UFG::ModelAssetComponent::ComponentFactory(this);
}

// File Line: 66
// RVA: 0x220FD0
void __fastcall UFG::ModelAssetComponent::OnModelAssetLoaded(void *ptr)
{
  __int64 *v1; // rbx
  UFG::ModelAssetComponent *v2; // rcx
  __int64 v3; // rcx
  _QWORD *v4; // rax
  __int64 v5; // rcx
  _QWORD *v6; // rax

  v1 = (__int64 *)ptr;
  v2 = (UFG::ModelAssetComponent *)*((_QWORD *)ptr + 2);
  if ( v2 )
    UFG::ModelAssetComponent::ComponentFactory(v2);
  if ( v1[2] )
  {
    v3 = *v1;
    v4 = (_QWORD *)v1[1];
    *(_QWORD *)(v3 + 8) = v4;
    *v4 = v3;
    *v1 = (__int64)v1;
    v1[1] = (__int64)v1;
  }
  v1[2] = 0i64;
  v5 = *v1;
  v6 = (_QWORD *)v1[1];
  *(_QWORD *)(v5 + 8) = v6;
  *v6 = v5;
  *v1 = (__int64)v1;
  v1[1] = (__int64)v1;
  operator delete[](v1);
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
  UFG::qReflectObject *v1; // rbx
  UFG::SimObject *v2; // rsi
  __int64 v3; // rdi
  __int64 v4; // rcx

  v1 = this->mModelAssetHandle.mData;
  if ( v1 )
  {
    v2 = this->m_pSimObject;
    UFG::SimObject::StartDeferringAttachment(v2);
    v3 = 0i64;
    if ( LODWORD(v1[2].mHandles.mNode.mPrev) )
    {
      do
      {
        v4 = *(_QWORD *)(v1[2].mTypeUID + 8 * v3);
        (*(void (__fastcall **)(__int64, UFG::SimObject *, UFG::qReflectObject *))(*(_QWORD *)v4 + 24i64))(v4, v2, v1);
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < LODWORD(v1[2].mHandles.mNode.mPrev) );
    }
    if ( UFG::gModelAssetPostComponentFactory )
      UFG::gModelAssetPostComponentFactory(v2);
    UFG::SimObject::EndDeferringAttachment(v2);
  }
}

