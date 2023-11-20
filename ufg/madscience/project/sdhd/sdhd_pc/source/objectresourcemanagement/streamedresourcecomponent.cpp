// File Line: 58
// RVA: 0x150EB60
__int64 dynamic_initializer_for__UFG::StreamedResourceComponent::s_StreamedResourceComponentList__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::StreamedResourceComponent::s_StreamedResourceComponentList__);
}

// File Line: 59
// RVA: 0x43DF70
const char *__fastcall UFG::StreamedResourceComponent::GetTypeName(UFG::StreamedResourceComponent *this)
{
  return "StreamedResourceComponent";
}

// File Line: 69
// RVA: 0x150EB80
__int64 dynamic_initializer_for__UFG::StreamedResourceComponent::spPlayerTransformNode__()
{
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v2; // rcx
  UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *v3; // rdx

  UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent = 0i64;
  UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimObject = 0i64;
  UFG::StreamedResourceComponent::spPlayerTransformNode.m_Changed = 0;
  UFG::StreamedResourceComponent::spPlayerTransformNode.m_TypeUID = 0;
  if ( UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimObject )
  {
    v2 = UFG::StreamedResourceComponent::spPlayerTransformNode.mNext;
    v3 = UFG::StreamedResourceComponent::spPlayerTransformNode.mPrev;
    if ( (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)UFG::StreamedResourceComponent::spPlayerTransformNode.mPrev != &UFG::StreamedResourceComponent::spPlayerTransformNode
      || (UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0> *)UFG::StreamedResourceComponent::spPlayerTransformNode.mNext != &UFG::StreamedResourceComponent::spPlayerTransformNode )
    {
      UFG::StreamedResourceComponent::spPlayerTransformNode.mPrev->mNext = UFG::StreamedResourceComponent::spPlayerTransformNode.mNext;
      v2->mPrev = v3;
      UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimObject = 0i64;
      UFG::StreamedResourceComponent::spPlayerTransformNode.mNext = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&UFG::StreamedResourceComponent::spPlayerTransformNode;
      UFG::StreamedResourceComponent::spPlayerTransformNode.mPrev = (UFG::qNode<UFG::RebindingComponentHandleBase,UFG::RebindingComponentHandleBase> *)&UFG::StreamedResourceComponent::spPlayerTransformNode;
    }
  }
  UFG::StreamedResourceComponent::spPlayerTransformNode.m_Changed = 1;
  UFG::StreamedResourceComponent::spPlayerTransformNode.m_TypeUID = UFG::TransformNodeComponent::_TypeUID;
  return atexit(dynamic_atexit_destructor_for__UFG::StreamedResourceComponent::spPlayerTransformNode__);
}

// File Line: 70
// RVA: 0x1511CD0
__int64 UFG::_dynamic_initializer_for__hash_src__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SRC", 0xFFFFFFFF);
  hash_src = result;
  return result;
}

// File Line: 80
// RVA: 0x4373B0
void __fastcall UFG::StreamedResourceComponent::StreamedResourceComponent(UFG::StreamedResourceComponent *this, UFG::SceneObjectProperties *pSceneObj)
{
  UFG::SceneObjectProperties *v2; // rbp
  UFG::StreamedResourceComponent *v3; // rsi
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *v4; // rbx
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *v5; // rax
  UFG::qPropertySet *v6; // rax
  unsigned int v7; // eax
  UFG::qSymbol *v8; // rbx
  NISManager *v9; // rax
  bool v10; // bl
  bool v11; // r14
  UFG::qPropertySet *v12; // rax
  component_StreamedResource *v13; // rbp
  __int64 v14; // rax
  char *v15; // rcx
  unsigned int v16; // er15
  float *v17; // rcx
  signed __int64 v18; // rdx
  UFG::TrueCrowdSet::Instance *v19; // r8
  UFG::qPropertySet *v20; // rdx
  __int64 v21; // rax
  UFG::qPropertyList *v22; // r14
  unsigned int v23; // edi
  __int64 v24; // rax
  UFG::qPropertyList *v25; // rcx
  const char *v26; // rbx
  UFG::PartDatabase *v27; // rax
  UFG::qReflectObject *v28; // rax
  UFG::PartDefinition *v29; // rbx
  unsigned int v30; // er8
  unsigned int v31; // edx
  UFG::qSymbolUC textureSet; // [rsp+78h] [rbp+10h]
  UFG::qSymbolUC *v33; // [rsp+80h] [rbp+18h]

  v2 = pSceneObj;
  v3 = this;
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&this->vfptr, hash_src);
  v4 = (UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *)&v3->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  v3->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StreamedResourceComponent::`vftable;
  v3->mUseMeshLoader = 1;
  UFG::MeshResourceLoader::MeshResourceLoader(&v3->mMeshLoader);
  v3->mResourcesBound = 0;
  UFG::PartLoader::PartLoader(&v3->mPartLoader);
  v3->mPartsBound = 0;
  v3->mActivePriority = UFG::gNullQSymbol;
  v3->mPropertySet = 0i64;
  v3->mCameraDistance = 3.4028235e38;
  v5 = UFG::StreamedResourceComponent::s_StreamedResourceComponentList.mNode.mPrev;
  UFG::StreamedResourceComponent::s_StreamedResourceComponentList.mNode.mPrev->mNext = (UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *)&v3->mPrev;
  v4->mPrev = v5;
  v3->mNext = (UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *)&UFG::StreamedResourceComponent::s_StreamedResourceComponentList;
  UFG::StreamedResourceComponent::s_StreamedResourceComponentList.mNode.mPrev = (UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *)&v3->mPrev;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v3->vfptr,
    UFG::StreamedResourceComponent::_StreamedResourceComponentTypeUID,
    "StreamedResourceComponent");
  v3->mFirstResourceLoad = 0;
  v6 = v2->mpWritableProperties;
  if ( !v6 )
    v6 = v2->mpConstProperties;
  v3->mPropertySet = v6;
  v3->mSimObjectType = UFG::SimObjectPropertiesComponent::GetChildType(v2);
  UFG::StreamedResourceComponent::InitPriorityInfo(v3, v3->mPropertySet);
  v7 = v3->mActivePriority.mUID;
  v10 = 0;
  if ( v7 == qSymbol_Reserved.mUID || v7 == qSymbol_Critical.mUID )
  {
    v8 = &v2->m_pSimObject->m_Name;
    v9 = NISManager::GetInstance();
    if ( NISManager::UseHighDefModel(v9, v8) )
      v10 = 1;
  }
  v11 = v3->mActivePriority.mUID != qSymbol_Low.mUID;
  v12 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          v3->mPropertySet,
          (UFG::qSymbol *)&component_StreamedResource::sPropertyName.mUID,
          DEPTH_RECURSE);
  if ( v12 )
    v13 = (component_StreamedResource *)UFG::qPropertySet::GetMemImagePtr(v12);
  else
    v13 = 0i64;
  v14 = v13->PartList.mOffset;
  if ( v14 )
    v15 = (char *)&v13->PartList + v14;
  else
    v15 = 0i64;
  v16 = *((_DWORD *)v15 + 10);
  v17 = (float *)v3->mColourTints;
  v18 = 16i64;
  do
  {
    *v17 = UFG::qColour::White.r;
    v17[1] = UFG::qColour::White.g;
    v17[2] = UFG::qColour::White.b;
    v17[3] = UFG::qColour::White.a;
    v17 += 4;
    --v18;
  }
  while ( v18 );
  if ( v16 )
  {
    v3->mUseMeshLoader = 0;
  }
  else
  {
    v33 = &textureSet;
    textureSet.mUID = v3->mActivePriority.mUID;
    v3->mMeshLoader.mPropertySet = v3->mPropertySet;
    v3->mMeshLoader.mActivePriority.mUID = textureSet.mUID;
    v3->mMeshLoader.mHighDefinition = v10;
    v3->mMeshLoader.mTrueCrowdInstance.mSet = 0i64;
    v3->mMeshLoader.mTrueCrowdInstance.mNumParts = 0;
    v19 = &v3->mMeshLoader.mTrueCrowdInstance;
    v20 = v3->mMeshLoader.mPropertySet;
    if ( v11 )
      UFG::TrueCrowdDataBase::QueryInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, v20, v19);
    else
      UFG::TrueCrowdDataBase::QueryPreloadedInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, v20, v19);
  }
  v3->mMeshLoader.mOnLoadEventCallback = UFG::StreamedResourceComponent::OnLoadEventCallback;
  v3->mMeshLoader.mOnForceRemovedCallback = (void (__fastcall *)(void *, UFG::ResourceRequest *))UFG::StreamedResourceComponent::OnPartForceRemovedCallback;
  v3->mMeshLoader.mUserContext = v3;
  UFG::PartLoader::SetCallbacks(
    &v3->mPartLoader,
    UFG::StreamedResourceComponent::OnPartLoadEventCallback,
    UFG::StreamedResourceComponent::OnPartForceRemovedCallback,
    v3);
  v21 = v13->TextureSetList.mOffset;
  if ( v21 )
    v22 = (UFG::qPropertyList *)((char *)&v13->TextureSetList + v21);
  else
    v22 = 0i64;
  v23 = 0;
  if ( v16 )
  {
    do
    {
      v24 = v13->PartList.mOffset;
      if ( v24 )
        v25 = (UFG::qPropertyList *)((char *)&v13->PartList + v24);
      else
        v25 = 0i64;
      v26 = UFG::qPropertyList::Get<char const *>(v25, v23);
      v27 = UFG::PartDatabase::Instance();
      v28 = UFG::PartDatabase::GetPartByName(v27, v26);
      v29 = (UFG::PartDefinition *)v28;
      if ( v28 )
      {
        textureSet.mUID = UFG::gNullQSymbolUC.mUID;
        v30 = (unsigned int)v28[2].mBaseNode.mChildren[1];
        if ( v30 )
        {
          if ( v23 >= v22->mNumElements )
          {
            v31 = tex_variety++ % v30;
            textureSet.mUID = *((_DWORD *)&v28[2].mBaseNode.mChildren[0]->mUID + 20 * v31);
          }
          else
          {
            textureSet.mUID = UFG::qPropertyList::Get<UFG::qSymbolUC>(v22, v23)->mUID;
          }
        }
        UFG::PartLoader::AddPart(&v3->mPartLoader, v29, &textureSet);
      }
      ++v23;
    }
    while ( v23 < v16 );
  }
}

// File Line: 155
// RVA: 0x443200
void __fastcall UFG::StreamedResourceComponent::SetResourceSignature(UFG::StreamedResourceComponent *this, UFG::TrueCrowdSet::Instance *signature)
{
  UFG::TrueCrowdSet::Instance *v2; // rcx
  signed __int64 v3; // rax
  UFG::ModelTextureCombination v4; // xmm0

  v2 = &this->mMeshLoader.mTrueCrowdInstance;
  if ( ((unsigned __int8)v2 | (unsigned __int8)signature) & 0xF )
  {
    memmove(v2, signature, 0x118ui64);
  }
  else
  {
    v3 = 2i64;
    do
    {
      v4 = *(UFG::ModelTextureCombination *)&signature->mSet;
      v2 = (UFG::TrueCrowdSet::Instance *)((char *)v2 + 128);
      signature = (UFG::TrueCrowdSet::Instance *)((char *)signature + 128);
      v2[-1].mPart[8] = v4;
      v2[-1].mPart[9] = signature[-1].mPart[9];
      v2[-1].mPart[10] = signature[-1].mPart[10];
      v2[-1].mPart[11] = signature[-1].mPart[11];
      v2[-1].mPart[12] = signature[-1].mPart[12];
      v2[-1].mPart[13] = signature[-1].mPart[13];
      v2[-1].mPart[14] = signature[-1].mPart[14];
      v2[-1].mPart[15] = signature[-1].mPart[15];
      --v3;
    }
    while ( v3 );
    *(_OWORD *)&v2->mSet = *(_OWORD *)&signature->mSet;
    *(_QWORD *)&v2->mMorphWeights[1] = *(_QWORD *)&signature->mMorphWeights[1];
  }
}

// File Line: 160
// RVA: 0x43EFD0
void __fastcall UFG::StreamedResourceComponent::InitPriorityInfo(UFG::StreamedResourceComponent *this, UFG::qPropertySet *propertySet)
{
  unsigned int v2; // ebx
  UFG::StreamedResourceComponent *v3; // rdi
  UFG::qSymbol *v4; // rax
  UFG::qSymbol *v5; // rdx
  unsigned int v6; // eax
  UFG::qSymbol **v7; // rdx

  v2 = 0;
  v3 = this;
  *(_QWORD *)this->mSpawnPriorityReferenceCount = 0i64;
  *(_QWORD *)&this->mSpawnPriorityReferenceCount[2] = 0i64;
  v4 = UFG::qPropertySet::Get<UFG::qSymbol>(propertySet, (UFG::qSymbol *)&qSymbol_SpawnPriority.mUID, DEPTH_RECURSE);
  v5 = &UFG::gNullQSymbol;
  if ( v4 )
    v5 = v4;
  v6 = v5->mUID;
  if ( v5->mUID == UFG::gNullQSymbol.mUID )
  {
    v3->mActivePriority.mUID = qSymbol_Critical.mUID;
    ++v3->mSpawnPriorityReferenceCount[0];
  }
  else
  {
    v3->mActivePriority.mUID = v6;
    v7 = UFG::StreamedResourceComponent::sSpawnPrioritySymbols;
    while ( v6 != (*v7)->mUID )
    {
      ++v2;
      ++v7;
      if ( v2 >= 4 )
        goto LABEL_7;
    }
    if ( v2 >= 4 )
    {
LABEL_7:
      v3->mActivePriority = UFG::gNullQSymbol;
      return;
    }
    ++v3->mSpawnPriorityReferenceCount[v2];
  }
}

// File Line: 190
// RVA: 0x438000
void __fastcall UFG::StreamedResourceComponent::~StreamedResourceComponent(UFG::StreamedResourceComponent *this)
{
  UFG::StreamedResourceComponent *v1; // rdi
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *v2; // rbx
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *v3; // rcx
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *v4; // rax
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *v5; // rcx
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *v6; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StreamedResourceComponent::`vftable;
  if ( this == UFG::StreamedResourceComponent::s_StreamedResourceComponentpCurrentIterator )
    UFG::StreamedResourceComponent::s_StreamedResourceComponentpCurrentIterator = (UFG::StreamedResourceComponent *)&this->mPrev[-4];
  v2 = (UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *)&this->mPrev;
  v3 = this->mPrev;
  v4 = v2->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::PartLoader::~PartLoader(&v1->mPartLoader);
  UFG::MeshResourceLoader::Unload(&v1->mMeshLoader);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 195
// RVA: 0x442D40
void __fastcall UFG::StreamedResourceComponent::ResetPropertyPtr(UFG::StreamedResourceComponent *this)
{
  UFG::StreamedResourceComponent *v1; // rdi
  UFG::SimObject *v2; // rbx
  UFG::SceneObjectProperties *v3; // rax
  UFG::qPropertySet *v4; // rbp
  unsigned int v5; // eax
  NISManager *v6; // rax
  bool v7; // r14
  UFG::TrueCrowdSet::Instance *v8; // r8
  UFG::qPropertySet *v9; // rdx
  unsigned int v10; // [rsp+50h] [rbp+8h]
  int *v11; // [rsp+58h] [rbp+10h]

  v1 = this;
  if ( this->mUseMeshLoader )
  {
    v2 = this->m_pSimObject;
    if ( v2 )
      v3 = v2->m_pSceneObj;
    else
      v3 = 0i64;
    v4 = v3->mpWritableProperties;
    if ( !v4 )
      v4 = v3->mpConstProperties;
    if ( this->mPropertySet != v4 )
    {
      v5 = this->mActivePriority.mUID;
      v7 = 0;
      if ( v5 == qSymbol_Reserved.mUID || v5 == qSymbol_Critical.mUID )
      {
        v6 = NISManager::GetInstance();
        if ( NISManager::UseHighDefModel(v6, &v2->m_Name) )
          v7 = 1;
      }
      v1->mPropertySet = v4;
      UFG::MeshResourceLoader::Unload(&v1->mMeshLoader);
      v11 = (int *)&v10;
      v10 = v1->mActivePriority.mUID;
      v1->mMeshLoader.mPropertySet = v1->mPropertySet;
      v1->mMeshLoader.mActivePriority.mUID = v10;
      v1->mMeshLoader.mHighDefinition = v7;
      v8 = &v1->mMeshLoader.mTrueCrowdInstance;
      v8->mSet = 0i64;
      v8->mNumParts = 0;
      v9 = v1->mMeshLoader.mPropertySet;
      if ( v1->mActivePriority.mUID == qSymbol_Low.mUID )
        UFG::TrueCrowdDataBase::QueryPreloadedInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, v9, v8);
      else
        UFG::TrueCrowdDataBase::QueryInstance(UFG::TrueCrowdDataBase::sTrueCrowdDataBase, v9, v8);
    }
  }
  else
  {
    UFG::MeshResourceLoader::Unload(&this->mMeshLoader);
    if ( v1->mMeshLoader.mPropertySet )
    {
      v1->mMeshLoader.mPropertySet = 0i64;
      v1->mMeshLoader.mTrueCrowdInstance.mSet = 0i64;
      v1->mMeshLoader.mTrueCrowdInstance.mNumParts = 0;
    }
    v1->mPropertySet = 0i64;
  }
}

// File Line: 217
// RVA: 0x43A790
void __fastcall UFG::StreamedResourceComponent::ClearResources(UFG::StreamedResourceComponent *this)
{
  UFG::StreamedResourceComponent *v1; // rbx

  v1 = this;
  UFG::MeshResourceLoader::Unload(&this->mMeshLoader);
  UFG::PartLoader::Unload(&v1->mPartLoader);
}

// File Line: 223
// RVA: 0x442E90
void __fastcall UFG::StreamedResourceComponent::ResetResources(UFG::StreamedResourceComponent *this)
{
  UFG::PartLoader::Reset(&this->mPartLoader);
}

// File Line: 237
// RVA: 0x4385F0
void __fastcall UFG::StreamedResourceComponent::AddPart(UFG::StreamedResourceComponent *this, UFG::PartDefinition *part, UFG::qSymbolUC *textureSet)
{
  UFG::PartLoader::AddPart(&this->mPartLoader, part, textureSet);
}

// File Line: 247
// RVA: 0x43FEA0
UFG::SimComponent *__fastcall UFG::StreamedResourceComponent::PropertiesOnActivateNew(UFG::SceneObjectProperties *sceneObject, bool required)
{
  UFG::SceneObjectProperties *v2; // rbx
  UFG::qPropertySet *v3; // rcx
  UFG::qPropertySet *v4; // rax
  UFG::qMemoryPool *v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::SimComponent *v8; // rax
  UFG::SimComponent *v9; // rdi
  UFG::SimObject *v10; // rdx
  unsigned __int16 v11; // cx
  unsigned int v12; // ebx
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h]

  v2 = sceneObject;
  if ( !required )
  {
    v3 = sceneObject->mpWritableProperties;
    if ( !v3 )
      v3 = v2->mpConstProperties;
    v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           v3,
           (UFG::qSymbol *)&component_StreamedResource::sPropertyName.mUID,
           DEPTH_RECURSE);
    if ( !v4 || !UFG::qPropertySet::GetMemImagePtr(v4) )
      return 0i64;
  }
  v6 = UFG::GetSimulationMemoryPool();
  v7 = UFG::qMemoryPool::Allocate(v6, 0x630ui64, "StreamedResourceComponent", 0i64, 1u);
  if ( v7 )
  {
    UFG::StreamedResourceComponent::StreamedResourceComponent((UFG::StreamedResourceComponent *)v7, v2);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = v2->m_pSimObject;
  v11 = v10->m_Flags;
  if ( (v11 >> 14) & 1 || (v11 & 0x8000u) != 0 )
  {
    v12 = 10;
  }
  else if ( (v11 >> 13) & 1 )
  {
    v12 = 7;
  }
  else
  {
    v12 = -1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v13, v10, 1);
  UFG::SimObjectModifier::AttachComponent(&v13, v9, v12);
  UFG::SimObjectModifier::Close(&v13);
  UFG::SimObjectModifier::~SimObjectModifier(&v13);
  return v9;
}

// File Line: 264
// RVA: 0x43F6C0
void __fastcall UFG::StreamedResourceComponent::OnAttach(UFG::StreamedResourceComponent *this, UFG::SimObject *object)
{
  UFG::SimComponent *v2; // rdi
  UFG::TransformNodeComponent *v3; // rbp
  UFG::SimObjectGame *v4; // rbx
  UFG::StreamedResourceComponent *v5; // rsi
  float v6; // xmm7_4
  __m128 v7; // xmm6
  float v8; // xmm8_4
  UFG::BaseCameraComponent *v9; // rax
  UFG::BaseCameraComponent *v10; // rax
  UFG::SimObject *v11; // rax
  unsigned __int16 v12; // cx
  UFG::SimComponent *v13; // rax
  unsigned __int16 v14; // cx
  UFG::SimComponent *v15; // rdi
  UFG::CompositeDrawableComponent *v16; // rax

  v2 = UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent;
  v3 = 0i64;
  v4 = (UFG::SimObjectGame *)object;
  v5 = this;
  if ( UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent);
    v6 = *(float *)&v2[2].m_BoundComponentHandles.mNode.mPrev;
    v7 = (__m128)HIDWORD(v2[2].m_BoundComponentHandles.mNode.mPrev);
    v8 = *(float *)&v2[2].m_BoundComponentHandles.mNode.mNext;
  }
  else
  {
    v9 = UFG::Director::Get()->mCurrentCamera;
    if ( v9 )
      v10 = (UFG::BaseCameraComponent *)((char *)v9 + 80);
    else
      v10 = 0i64;
    v6 = v10->mCamera.mView.v2.x;
    v7 = (__m128)LODWORD(v10->mCamera.mView.v2.y);
    v8 = v10->mCamera.mView.v2.z;
  }
  v11 = v5->m_pSimObject;
  if ( v11 )
    v3 = v11->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(v3);
  v7.m128_f32[0] = (float)((float)((float)(v7.m128_f32[0] - v3->mWorldTransform.v3.y)
                                 * (float)(v7.m128_f32[0] - v3->mWorldTransform.v3.y))
                         + (float)((float)(v6 - v3->mWorldTransform.v3.x) * (float)(v6 - v3->mWorldTransform.v3.x)))
                 + (float)((float)(v8 - v3->mWorldTransform.v3.z) * (float)(v8 - v3->mWorldTransform.v3.z));
  LODWORD(v5->mCameraDistance) = (unsigned __int128)_mm_sqrt_ps(v7);
  UFG::StreamedResourceComponent::UpdateLoadState(v5, (UFG::SimObject *)&v4->vfptr);
  if ( v4 )
  {
    v12 = v4->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CompositeLookComponent::_TypeUID);
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CompositeLookComponent::_TypeUID);
      }
      else if ( (v12 >> 12) & 1 )
      {
        v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CompositeLookComponent::_TypeUID);
      }
      else
      {
        v13 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v4->vfptr, UFG::CompositeLookComponent::_TypeUID);
      }
    }
    else
    {
      v13 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CompositeLookComponent::_TypeUID);
    }
    v14 = v4->m_Flags;
    v15 = v13;
    if ( (v14 >> 14) & 1 )
    {
      v16 = (UFG::CompositeDrawableComponent *)v4->m_Components.p[14].m_pComponent;
    }
    else if ( (v14 & 0x8000u) == 0 )
    {
      if ( (v14 >> 13) & 1 )
      {
        v16 = (UFG::CompositeDrawableComponent *)v4->m_Components.p[9].m_pComponent;
      }
      else if ( (v14 >> 12) & 1 )
      {
        v16 = (UFG::CompositeDrawableComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                   v4,
                                                   UFG::CompositeDrawableComponent::_TypeUID);
      }
      else
      {
        v16 = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                   (UFG::SimObject *)&v4->vfptr,
                                                   UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      v16 = (UFG::CompositeDrawableComponent *)v4->m_Components.p[14].m_pComponent;
    }
    if ( v16 && v16 != (UFG::CompositeDrawableComponent *)-112i64 )
      UFG::StreamedResourceComponent::UpdateMaterialModifiers(v5, &v16->mMaterialModifier);
    if ( v15 )
      *(_QWORD *)&v15[1].m_Flags = (char *)v5 + 1292;
  }
  if ( !UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent )
  {
    if ( LocalPlayer )
      UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
        &UFG::StreamedResourceComponent::spPlayerTransformNode,
        (UFG::SimObject *)&LocalPlayer->vfptr);
  }
}

// File Line: 304
// RVA: 0x446220
void __fastcall UFG::StreamedResourceComponent::UpdateMaterialModifiers(UFG::StreamedResourceComponent *this, Illusion::MaterialModifierParams<10> *material_modifier)
{
  unsigned int v2; // er15
  Illusion::MaterialModifierParams<10> *v3; // r14
  UFG::StreamedResourceComponent *v4; // rdx
  unsigned int i; // er12
  signed __int64 v6; // rbx
  UFG::TrueCrowdModel *v7; // r8
  __int64 v8; // rax
  signed __int64 v9; // rax
  unsigned int v10; // ebp
  UFG::TrueCrowdTextureSet *v11; // r13
  __int64 v12; // rcx
  signed __int64 v13; // rdx
  signed __int64 v14; // rdi
  unsigned int *v15; // rsi
  unsigned int *v16; // rbx
  unsigned int v17; // edx
  unsigned int v18; // er8
  unsigned int original_name_uid; // ST20_4
  Illusion::ParamOverride *v20; // rcx
  UFG::qColour *v21; // rcx
  unsigned int v22; // esi
  UFG::PartLoader *v23; // rdi
  UFG::PartDefinition *v24; // rbx
  UFG::qSymbolUC *v25; // rax
  UFG::StreamedResourceComponent *v26; // [rsp+70h] [rbp+8h]
  signed __int64 v27; // [rsp+80h] [rbp+18h]

  v26 = this;
  v2 = 0;
  v3 = material_modifier;
  material_modifier->mNumOverrides = 0;
  v4 = this;
  for ( i = 0; i < v4->mMeshLoader.mTrueCrowdInstance.mNumParts; ++i )
  {
    v6 = i;
    v27 = (signed __int64)&v4->mMeshLoader.mTrueCrowdInstance.mPart[v6];
    if ( v4->mMeshLoader.mTrueCrowdInstance.mPart[v6].mModelIndex != -1 )
    {
      v7 = v4->mMeshLoader.mTrueCrowdInstance.mSet->mFiles[v6].p[*((unsigned int *)&v4->mMeshLoader.mHighDefinition
                                                                 + 4 * (i + 13i64))];
      if ( v4->mMeshLoader.mHighDefinition )
      {
        v8 = v7->mHighResolutionResource.mOffset;
        if ( v8 )
        {
          v9 = (signed __int64)&v7->mHighResolutionResource + v8;
          if ( v9 )
            v7 = (UFG::TrueCrowdModel *)v9;
        }
      }
      if ( v7->mNumTextureSets )
      {
        v10 = 0;
        v11 = UFG::MeshResourceLoader::GetTexture(&v4->mMeshLoader, i);
        if ( v11->mNumTextureOverrideParams > 0u )
        {
          do
          {
            v12 = v11->mTextureOverrideParams.mOffset;
            if ( v12 )
              v13 = (signed __int64)&v11->mTextureOverrideParams + v12;
            else
              v13 = 0i64;
            v14 = 3i64;
            v15 = (unsigned int *)(v13 + 24i64 * v10);
            v16 = v15 + 2;
            do
            {
              if ( *v16 )
              {
                v17 = *v15;
                v18 = v15[1];
                original_name_uid = *v16;
                v20 = &v3->mOverrides[v3->mNumOverrides++];
                Illusion::ParamOverride::SetTextureOverride(v20, v17, v18, OVERRIDE_EQUALS, original_name_uid);
              }
              ++v16;
              --v14;
            }
            while ( v14 );
            ++v10;
          }
          while ( v10 < v11->mNumTextureOverrideParams );
          v6 = i;
        }
      }
      v4 = v26;
      v21 = &UFG::qColour::White;
      if ( *(_QWORD *)(v27 + 8) )
        v21 = *(UFG::qColour **)(v27 + 8);
      v26->mColourTints[v6].r = v21->r;
      v26->mColourTints[v6].g = v21->g;
      v26->mColourTints[v6].b = v21->b;
      v26->mColourTints[v6].a = v21->a;
    }
  }
  v22 = v4->mPartLoader.mPartCount;
  if ( v22 )
  {
    v23 = &v4->mPartLoader;
    do
    {
      v24 = UFG::PartLoader::GetPart(v23, v2);
      if ( v24 )
      {
        v25 = UFG::PartLoader::GetPartTextureSet(v23, v2);
        UFG::StreamedResourceComponent::ApplyTextureOverrideForPart(v26, v3, v24, v25);
      }
      ++v2;
    }
    while ( v2 < v22 );
  }
}

// File Line: 349
// RVA: 0x446430
void __fastcall UFG::StreamedResourceComponent::UpdateMaterialModifiers(UFG::StreamedResourceComponent *this, Illusion::MaterialModifierParams<10> *material_modifier, UFG::PartTemplateInstance *partInstance)
{
  unsigned int v3; // eax
  Illusion::MaterialModifierParams<10> *v4; // rbp
  UFG::StreamedResourceComponent *v5; // r15
  __int64 v6; // r13
  __int64 v7; // r12
  UFG::PartTemplateInstance::SlotEntry *v8; // rbx
  UFG::PartDefinition *v9; // r14
  UFG::PartDefinition::TextureAlternate *v10; // rax
  UFG::PartDefinition::TextureAlternate *v11; // rsi
  unsigned int v12; // edi
  signed __int64 v13; // rbx
  unsigned __int16 v14; // ax
  __int64 v15; // r10
  int v16; // edx
  signed int v17; // eax
  Illusion::ParamOverride *v18; // rcx
  unsigned int v19; // edx
  unsigned int v20; // er8
  unsigned int original_name_uid; // ST20_4
  unsigned int v22; // er8
  unsigned int v23; // ebx
  unsigned int v24; // edx
  __int64 v25; // rsi
  UFG::qColour *v26; // rcx
  _DWORD *v27; // r8
  UFG::PartTemplateInstance *v28; // [rsp+70h] [rbp+18h]

  v28 = partInstance;
  v3 = partInstance->mSlots.mData.mNumItems;
  v4 = material_modifier;
  v5 = this;
  if ( v3 )
  {
    v6 = v3;
    v7 = 0i64;
    do
    {
      v8 = &partInstance->mSlots.mData.mItems[v7];
      v9 = (UFG::PartDefinition *)v8->mBasePart.mPart.mData;
      if ( v9 )
      {
        if ( !UFG::PartTemplateInstance::SlotEntry::IsComposited(&partInstance->mSlots.mData.mItems[v7]) )
        {
          v10 = UFG::PartDefinition::GetTextureAlternate(v9, &v8->mBasePart.mTextureSet);
          v11 = v10;
          if ( v10 )
          {
            v12 = 0;
            if ( v10->mTextures.mData.mNumItems )
            {
              do
              {
                v13 = (signed __int64)&v11->mTextures.mData.mItems[v12];
                if ( *(_QWORD *)(v13 + 40) && *(_QWORD *)(v13 + 80) )
                {
                  v14 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, *(_DWORD *)v13);
                  v15 = v4->mNumOverrides;
                  v16 = v14;
                  v17 = 0;
                  if ( (signed int)v15 <= 0 )
                    goto LABEL_13;
                  v18 = v4->mOverrides;
                  while ( v18->mStateParamIndex != v16 )
                  {
                    ++v17;
                    ++v18;
                    if ( v17 >= (signed int)v15 )
                      goto LABEL_13;
                  }
                  if ( v17 == -1 )
                  {
LABEL_13:
                    v19 = *(_DWORD *)v13;
                    v20 = *(_DWORD *)(*(_QWORD *)(v13 + 80) + 200i64);
                    original_name_uid = *(_DWORD *)(*(_QWORD *)(v13 + 40) + 200i64);
                    v4->mNumOverrides = v15 + 1;
                    Illusion::ParamOverride::SetTextureOverride(
                      &v4->mOverrides[v15],
                      v19,
                      v20,
                      OVERRIDE_EQUALS,
                      original_name_uid);
                  }
                  else
                  {
                    Illusion::ParamOverride::SetTextureOverride(
                      &v4->mOverrides[v17],
                      *(_DWORD *)v13,
                      *(_DWORD *)(*(_QWORD *)(v13 + 80) + 200i64),
                      OVERRIDE_EQUALS,
                      *(_DWORD *)(*(_QWORD *)(v13 + 40) + 200i64));
                  }
                }
                ++v12;
              }
              while ( v12 < v11->mTextures.mData.mNumItems );
            }
          }
          v22 = v9->mTintColours.mData.mNumItems;
          if ( v22 )
          {
            v23 = 0;
            v24 = colour_variety++ % v22;
            v25 = v24;
            if ( v5->mPartLoader.mPartCount )
            {
              while ( UFG::PartLoader::GetPart(&v5->mPartLoader, v23)->mSlotName.mUID != v9->mSlotName.mUID )
              {
                if ( ++v23 >= v5->mPartLoader.mPartCount )
                  goto LABEL_23;
              }
              v26 = v9->mTintColours.mData.mItems;
              v27 = (_DWORD *)((char *)v5 + 16 * v23);
              v27[323] = LODWORD(v26[v25].r);
              v27[324] = LODWORD(v26[v25].g);
              v27[325] = LODWORD(v26[v25].b);
              v27[326] = LODWORD(v26[v25].a);
            }
          }
        }
LABEL_23:
        partInstance = v28;
      }
      ++v7;
      --v6;
    }
    while ( v6 );
  }
}

// File Line: 405
// RVA: 0x438AB0
void __fastcall UFG::StreamedResourceComponent::ApplyTextureOverrideForPart(UFG::StreamedResourceComponent *this, Illusion::MaterialModifierParams<10> *material_modifier, UFG::PartDefinition *part, UFG::qSymbolUC *textureSet)
{
  UFG::StreamedResourceComponent *v4; // r15
  Illusion::MaterialModifierParams<10> *v5; // rbp
  UFG::PartDefinition *v6; // r13
  UFG::PartDefinition::TextureAlternate *v7; // rax
  unsigned int v8; // edi
  UFG::PartDefinition::TextureAlternate *v9; // r14
  unsigned int v10; // esi
  UFG::PartDefinition::TextureData *v11; // rbx
  unsigned __int16 v12; // ax
  __int64 v13; // r10
  int v14; // edx
  signed int v15; // eax
  Illusion::ParamOverride *v16; // rcx
  unsigned int v17; // edx
  unsigned int v18; // er8
  unsigned int original_name_uid; // ST20_4
  unsigned int v20; // er8
  unsigned int v21; // edx
  __int64 v22; // rsi
  UFG::qColour *v23; // rcx
  void *v24; // r8

  v4 = this;
  v5 = material_modifier;
  v6 = part;
  v7 = UFG::PartDefinition::GetTextureAlternate(part, textureSet);
  v8 = 0;
  v9 = v7;
  if ( v7 )
  {
    v10 = 0;
    if ( v7->mTextures.mData.mNumItems > 0 )
    {
      do
      {
        v11 = &v9->mTextures.mData.mItems[v10];
        if ( v11->mOriginalTexture.mData && v11->mOverrideTexture.mData )
        {
          v12 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, v11->mTextureSlot);
          v13 = v5->mNumOverrides;
          v14 = v12;
          v15 = 0;
          if ( (signed int)v13 <= 0 )
            goto LABEL_9;
          v16 = v5->mOverrides;
          while ( v16->mStateParamIndex != v14 )
          {
            ++v15;
            ++v16;
            if ( v15 >= (signed int)v13 )
              goto LABEL_9;
          }
          if ( v15 == -1 )
          {
LABEL_9:
            v17 = v11->mTextureSlot;
            v18 = (unsigned int)v11->mOverrideTexture.mData[2].mBaseNode.mNeighbours[0];
            original_name_uid = (unsigned int)v11->mOriginalTexture.mData[2].mBaseNode.mNeighbours[0];
            v5->mNumOverrides = v13 + 1;
            Illusion::ParamOverride::SetTextureOverride(
              &v5->mOverrides[v13],
              v17,
              v18,
              OVERRIDE_EQUALS,
              original_name_uid);
          }
          else
          {
            Illusion::ParamOverride::SetTextureOverride(
              &v5->mOverrides[v15],
              v11->mTextureSlot,
              (unsigned int)v11->mOverrideTexture.mData[2].mBaseNode.mNeighbours[0],
              OVERRIDE_EQUALS,
              (unsigned int)v11->mOriginalTexture.mData[2].mBaseNode.mNeighbours[0]);
          }
        }
        ++v10;
      }
      while ( v10 < v9->mTextures.mData.mNumItems );
    }
  }
  v20 = v6->mTintColours.mData.mNumItems;
  if ( v20 )
  {
    v21 = colour_variety++ % v20;
    v22 = v21;
    if ( v4->mPartLoader.mPartCount > 0 )
    {
      while ( UFG::PartLoader::GetPart(&v4->mPartLoader, v8)->mSlotName.mUID != v6->mSlotName.mUID )
      {
        if ( ++v8 >= v4->mPartLoader.mPartCount )
          return;
      }
      v23 = v6->mTintColours.mData.mItems;
      v24 = (char *)v4 + 16 * v8;
      *((_DWORD *)v24 + 323) = LODWORD(v23[v22].r);
      *((_DWORD *)v24 + 324) = LODWORD(v23[v22].g);
      *((_DWORD *)v24 + 325) = LODWORD(v23[v22].b);
      *((_DWORD *)v24 + 326) = LODWORD(v23[v22].a);
    }
  }
}

// File Line: 445
// RVA: 0x446130
void __fastcall UFG::StreamedResourceComponent::UpdateLoadState(UFG::StreamedResourceComponent *this, UFG::SimObject *object)
{
  UFG::StreamedResourceComponent *v2; // rbx
  float v3; // xmm0_4

  v2 = this;
  if ( this->mActivePriority.mUID == qSymbol_Low.mUID )
  {
    if ( this->mUseMeshLoader && !this->mMeshLoader.mResourceCount )
    {
      if ( UFG::TrueCrowdSet::Instance::IsLoaded(&this->mMeshLoader.mTrueCrowdInstance) )
        UFG::MeshResourceLoader::QueueLoad(&v2->mMeshLoader);
      else
        UFG::TrueCrowdDataBase::QueryPreloadedInstance(
          UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
          v2->mMeshLoader.mPropertySet,
          &v2->mMeshLoader.mTrueCrowdInstance);
    }
  }
  else
  {
    v3 = UFG::StreamedResourceComponent::sAssetLoadDistance;
    if ( this->mSimObjectType == eSIM_OBJ_TYPE_VEHICLE )
      v3 = FLOAT_3_4028235e38;
    if ( v3 <= this->mCameraDistance )
    {
      if ( this->mUseMeshLoader && this->mMeshLoader.mResourceCount )
        UFG::MeshResourceLoader::Unload(&this->mMeshLoader);
      if ( v2->mPartLoader.mPartRequestCount )
        UFG::PartLoader::Unload(&v2->mPartLoader);
    }
    else
    {
      if ( this->mUseMeshLoader && !this->mMeshLoader.mResourceCount )
        UFG::MeshResourceLoader::QueueLoad(&this->mMeshLoader);
      if ( !v2->mPartLoader.mPartRequestCount )
        UFG::PartLoader::QueueLoad(&v2->mPartLoader);
    }
  }
}

// File Line: 511
// RVA: 0x43F160
bool __fastcall UFG::StreamedResourceComponent::IsLoadActive(UFG::StreamedResourceComponent *this)
{
  return this->mMeshLoader.mResourceCount || this->mPartLoader.mPartRequestCount;
}

// File Line: 516
// RVA: 0x438CC0
char __fastcall UFG::StreamedResourceComponent::AreResourcesLoaded(UFG::StreamedResourceComponent *this)
{
  UFG::StreamedResourceComponent *v1; // r9
  unsigned int v2; // er8
  unsigned int v3; // edx
  UFG::ResourceRequest **v4; // rcx
  char result; // al

  v1 = this;
  if ( !this->mMeshLoader.mPropertySet )
    return 1;
  v2 = this->mMeshLoader.mResourceCount;
  if ( v2 )
  {
    v3 = 0;
    if ( !v2 )
      return 1;
    v4 = this->mMeshLoader.mResourceRequests;
    while ( (*v4)->mLoadStatus == 3 )
    {
      ++v3;
      ++v4;
      if ( v3 >= v2 )
        return 1;
    }
  }
  result = UFG::PartLoader::IsLoaded(&v1->mPartLoader);
  if ( result )
    return 1;
  return result;
}

// File Line: 521
// RVA: 0x438C90
bool __fastcall UFG::StreamedResourceComponent::AreResourcesBound(UFG::StreamedResourceComponent *this)
{
  return this->mMeshLoader.mResourceCount && this->mResourcesBound
      || this->mPartLoader.mPartRequestCount && this->mPartsBound;
}

// File Line: 536
// RVA: 0x447980
void __fastcall UFG::StreamedResourceComponent::UpgradeResolution(UFG::StreamedResourceComponent *this)
{
  UFG::MeshResourceLoader *v1; // rbx

  if ( this->mUseMeshLoader )
  {
    v1 = &this->mMeshLoader;
    if ( !this->mMeshLoader.mHighDefinition )
    {
      UFG::MeshResourceLoader::Unload(&this->mMeshLoader);
      v1->mHighDefinition = 1;
      UFG::MeshResourceLoader::QueueLoad(v1);
    }
  }
}

// File Line: 544
// RVA: 0x43C2C0
void __fastcall UFG::StreamedResourceComponent::DowngradeResolution(UFG::StreamedResourceComponent *this)
{
  UFG::MeshResourceLoader *v1; // rbx

  if ( this->mUseMeshLoader )
  {
    v1 = &this->mMeshLoader;
    if ( this->mMeshLoader.mHighDefinition == 1 )
    {
      UFG::MeshResourceLoader::Unload(&this->mMeshLoader);
      v1->mHighDefinition = 0;
      UFG::MeshResourceLoader::QueueLoad(v1);
    }
  }
}

// File Line: 557
// RVA: 0x445360
void __fastcall UFG::StreamedResourceComponent::UpdateActivePriority(UFG::StreamedResourceComponent *this)
{
  unsigned int v1; // edx
  unsigned int v2; // eax
  unsigned int v3; // ebp
  UFG::StreamedResourceComponent *v4; // rdi
  unsigned int v5; // er8
  unsigned int *v6; // r9
  UFG::SimObject *v7; // r8
  unsigned __int16 v8; // dx
  UFG::UIMapBlip *v9; // rbx
  UFG::SimObjectGame *v10; // rcx
  UFG::SimComponent *v11; // rax
  UFG::VehicleOccupantComponent *v12; // rax
  UFG::PartPriority::Type v13; // er15
  UFG::PartPriority::Type v14; // esi
  unsigned int v15; // er14
  UFG::PartDefinition *v16; // rbx
  UFG::PartDatabase *v17; // rax
  UFG::qSymbol newPriority; // [rsp+50h] [rbp+8h]
  UFG::qSymbol oldPriority; // [rsp+58h] [rbp+10h]

  v1 = this->mActivePriority.mUID;
  v2 = UFG::gNullQSymbol.mUID;
  v3 = 0;
  v4 = this;
  v5 = 0;
  v6 = this->mSpawnPriorityReferenceCount;
  oldPriority.mUID = this->mActivePriority.mUID;
  newPriority.mUID = UFG::gNullQSymbol.mUID;
  while ( *v6 <= 0 )
  {
    ++v5;
    ++v6;
    if ( v5 >= 4 )
      goto LABEL_6;
  }
  v2 = UFG::StreamedResourceComponent::sSpawnPrioritySymbols[v5]->mUID;
  newPriority.mUID = UFG::StreamedResourceComponent::sSpawnPrioritySymbols[v5]->mUID;
LABEL_6:
  if ( v1 != v2 )
  {
    if ( this->mUseMeshLoader )
    {
      if ( this->mMeshLoader.mResourceCount > 0 )
      {
        UFG::ObjectResourceManager::ChangeObjectPriority(UFG::ObjectResourceManager::sInstance, this, &newPriority);
        v2 = newPriority.mUID;
      }
      v7 = v4->m_pSimObject;
      if ( v7 )
      {
        v8 = v7->m_Flags;
        if ( (v8 >> 14) & 1 )
        {
          v9 = (UFG::UIMapBlip *)v7->m_Components.p[44].m_pComponent;
        }
        else
        {
          v10 = (UFG::SimObjectGame *)v4->m_pSimObject;
          if ( (v8 & 0x8000u) == 0 )
          {
            if ( (v8 >> 13) & 1 )
              v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::CharacterOccupantComponent::_TypeUID);
            else
              v11 = (v8 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                       v10,
                                       UFG::CharacterOccupantComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                      (UFG::SimObject *)&v10->vfptr,
                                                                                      UFG::CharacterOccupantComponent::_TypeUID);
          }
          else
          {
            v11 = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::CharacterOccupantComponent::_TypeUID);
          }
          v9 = (UFG::UIMapBlip *)v11;
          v2 = newPriority.mUID;
        }
        if ( v9 )
        {
          if ( SSInvokedMethod::get_invokable(v9) )
          {
            v12 = (UFG::VehicleOccupantComponent *)SSInvokedMethod::get_invokable(v9);
            UFG::VehicleOccupantComponent::UpdateOccupantPriority(v12, &oldPriority, &newPriority);
          }
          v2 = newPriority.mUID;
        }
      }
      v4->mMeshLoader.mActivePriority.mUID = v2;
    }
    v4->mActivePriority.mUID = v2;
    v13 = v4->mPartLoader.mPriority;
    v14 = v4->mPartLoader.mPriority;
    if ( v2 == qSymbol_Critical.mUID )
    {
      v14 = 2;
    }
    else if ( v2 == qSymbol_High.mUID )
    {
      v14 = 3;
    }
    else if ( v2 == qSymbol_Medium.mUID || v2 == qSymbol_Low.mUID )
    {
      v14 = 4;
    }
    else if ( v2 == qSymbol_Reserved.mUID )
    {
      v14 = 1;
    }
    if ( v4->mPartLoader.mPartRequestCount > 0 )
    {
      v15 = v4->mPartLoader.mPartCount;
      if ( v15 )
      {
        do
        {
          v16 = UFG::PartLoader::GetPart(&v4->mPartLoader, v3);
          v17 = UFG::PartDatabase::Instance();
          UFG::PartDatabase::ModifyPriorityForPart(v17, v16, v13, v14);
          ++v3;
        }
        while ( v3 < v15 );
      }
    }
    v4->mPartLoader.mPriority = v14;
  }
}, v14);
          ++v3;
        }
        while ( v3 < v15 );
      }
    }
    v4->mPartLoader.mPriority = v14

// File Line: 621
// RVA: 0x43DF90
void __fastcall UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(UFG::StreamedResourceComponent *this, UFG::qSymbol *symbol)
{
  __int64 v2; // rax
  UFG::qSymbol **v3; // r8

  v2 = 0i64;
  v3 = UFG::StreamedResourceComponent::sSpawnPrioritySymbols;
  while ( symbol->mUID != (*v3)->mUID )
  {
    v2 = (unsigned int)(v2 + 1);
    ++v3;
    if ( (unsigned int)v2 >= 4 )
      return;
  }
  if ( (unsigned int)v2 < 4 )
  {
    ++this->mSpawnPriorityReferenceCount[v2];
    UFG::StreamedResourceComponent::UpdateActivePriority(this);
  }
}

// File Line: 631
// RVA: 0x43B0F0
void __fastcall UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(UFG::StreamedResourceComponent *this, UFG::qSymbol *symbol)
{
  UFG::StreamedResourceComponent *v2; // r10
  __int64 v3; // rax
  UFG::qSymbol **v4; // r8
  __int64 v5; // rcx
  unsigned int v6; // eax

  v2 = this;
  v3 = 0i64;
  v4 = UFG::StreamedResourceComponent::sSpawnPrioritySymbols;
  while ( symbol->mUID != (*v4)->mUID )
  {
    v3 = (unsigned int)(v3 + 1);
    ++v4;
    if ( (unsigned int)v3 >= 4 )
      return;
  }
  if ( (unsigned int)v3 < 4 )
  {
    v5 = (unsigned int)v3;
    v6 = v2->mSpawnPriorityReferenceCount[v3];
    if ( v6 )
    {
      v2->mSpawnPriorityReferenceCount[v5] = v6 - 1;
      UFG::StreamedResourceComponent::UpdateActivePriority(v2);
    }
  }
}

// File Line: 647
// RVA: 0x43DE60
UFG::qSymbol *__fastcall UFG::StreamedResourceComponent::GetSpawnPriority(UFG::StreamedResourceComponent *this, UFG::SpawnInfoInterface::SpawnPriority *priority)
{
  UFG::SpawnInfoInterface::SpawnPriority v2; // er9
  unsigned int *v3; // rax
  signed __int64 v4; // r8

  if ( priority )
  {
    v2 = 0;
    v3 = this->mSpawnPriorityReferenceCount;
    v4 = 0i64;
    while ( !*v3 )
    {
      ++v4;
      ++v2;
      ++v3;
      if ( v4 >= 4 )
        return &this->mActivePriority;
    }
    *priority = v2;
  }
  return &this->mActivePriority;
}

// File Line: 676
// RVA: 0x444D00
void __fastcall UFG::StreamedResourceComponent::Update(UFG::StreamedResourceComponent *this, float seconds, UFG::qVector3 *streamPosition)
{
  UFG::SimObject *v3; // rax
  UFG::qVector3 *v4; // rsi
  UFG::StreamedResourceComponent *v5; // rbx
  UFG::TransformNodeComponent *v6; // rdi
  UFG::SimObject *v7; // rdx
  UFG::qVector3 *v8; // rbp
  __m128 v9; // xmm2
  float v10; // xmm0_4
  __int64 v11; // rdx
  _BOOL8 v12; // r8
  __int64 v13; // rdx
  _BOOL8 v14; // r8
  UFG::eSimObjectTypeEnum v15; // ecx
  bool v16; // si
  bool v17; // di
  unsigned int v18; // eax
  UFG::SimObjectCVBase *v19; // rbx
  UFG::AiDriverComponent *v20; // rax

  v3 = this->m_pSimObject;
  v4 = streamPosition;
  v5 = this;
  if ( v3 )
    v6 = v3->m_pTransformNodeComponent;
  else
    v6 = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(v6);
  v7 = v5->m_pSimObject;
  v8 = (UFG::qVector3 *)&v6->mWorldTransform.v3;
  v9 = (__m128)LODWORD(v4->y);
  v10 = v4->z - v6->mWorldTransform.v3.z;
  v9.m128_f32[0] = (float)((float)((float)(v9.m128_f32[0] - v6->mWorldTransform.v3.y)
                                 * (float)(v9.m128_f32[0] - v6->mWorldTransform.v3.y))
                         + (float)((float)(v4->x - v6->mWorldTransform.v3.x) * (float)(v4->x - v6->mWorldTransform.v3.x)))
                 + (float)(v10 * v10);
  LODWORD(v5->mCameraDistance) = (unsigned __int128)_mm_sqrt_ps(v9);
  UFG::StreamedResourceComponent::UpdateLoadState(v5, v7);
  UFG::MeshResourceLoader::PropagateResourceEvents(&v5->mMeshLoader, v11, v12);
  UFG::PartLoader::PropagatePartEvents(&v5->mPartLoader, v13, v14);
  v15 = v5->mSimObjectType;
  v16 = v15 == 5 && v5->mActivePriority.mUID == qSymbol_Low.mUID;
  v17 = v15 == 4 && v5->mActivePriority.mUID != qSymbol_Critical.mUID;
  if ( v16 || v17 )
  {
    v18 = UFG::SectionChooser::GetVisIndexAtPosition(v8, 0);
    if ( !UFG::SectionChooser::IsSectionVisible_VisIndex(v18, SCENERY_LAYER_STD, 0) )
    {
      if ( v16 )
        UFG::Simulation::QueueSimObjectToBeDestroyedRecursive(&UFG::gSim, v5->m_pSimObject);
      if ( v17 )
      {
        v19 = (UFG::SimObjectCVBase *)v5->m_pSimObject;
        if ( !v19
          || (v20 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v19)) == 0i64
          || !((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v20->vfptr[16].__vecDelDtor)(v20) )
        {
          UFG::WheeledVehicleManager::QueueDeletion(
            UFG::WheeledVehicleManager::m_Instance,
            (UFG::SimObject *)&v19->vfptr);
        }
      }
    }
  }
}

// File Line: 713
// RVA: 0x445580
void __fastcall UFG::StreamedResourceComponent::UpdateAll(float seconds)
{
  UFG::SimComponent *v1; // rbx
  float v2; // xmm6_4
  float v3; // xmm2_4
  float v4; // xmm1_4
  UFG::BaseCameraComponent *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm0_4
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *v8; // rcx
  UFG::qList<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent,1,0> *v9; // rbx
  UFG::qVector3 streamPosition; // [rsp+20h] [rbp-28h]

  v1 = UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent;
  v2 = seconds;
  if ( UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent);
    v3 = *((float *)&v1[2].m_BoundComponentHandles.mNode.mPrev + 1);
    streamPosition.x = *(float *)&v1[2].m_BoundComponentHandles.mNode.mPrev;
    v4 = *(float *)&v1[2].m_BoundComponentHandles.mNode.mNext;
    streamPosition.y = v3;
    streamPosition.z = v4;
  }
  else
  {
    v5 = UFG::Director::Get()->mCurrentCamera;
    if ( v5 )
      v5 = (UFG::BaseCameraComponent *)((char *)v5 + 80);
    v6 = v5->mCamera.mView.v2.y;
    streamPosition.x = v5->mCamera.mView.v2.x;
    v7 = v5->mCamera.mView.v2.z;
    streamPosition.y = v6;
    streamPosition.z = v7;
  }
  v8 = UFG::StreamedResourceComponent::s_StreamedResourceComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent,1,0> *)&UFG::StreamedResourceComponent::s_StreamedResourceComponentList.mNode.mNext[-4] != &UFG::StreamedResourceComponent::s_StreamedResourceComponentList - 4 )
  {
    do
    {
      v9 = (UFG::qList<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent,1,0> *)&v8[4].mNext[-4];
      if ( ((_QWORD)v8[2].mPrev & 3) == 1 )
        UFG::StreamedResourceComponent::Update((UFG::StreamedResourceComponent *)v8, v2, &streamPosition);
      v8 = &v9->mNode;
    }
    while ( v9 != &UFG::StreamedResourceComponent::s_StreamedResourceComponentList - 4 );
  }
}

// File Line: 739
// RVA: 0x43F9D0
void __fastcall UFG::StreamedResourceComponent::OnLoadEventCallback(void *context, UFG::ResourceRequest *request, bool loaded)
{
  JUMPOUT(context, 0i64, UFG::StreamedResourceComponent::DispatchResourceEvent);
}

// File Line: 748
// RVA: 0x43FAB0
void __fastcall UFG::StreamedResourceComponent::OnPartForceRemovedCallback(void *context, UFG::PartRequest *request)
{
  if ( context )
    UFG::Simulation::DestroySimObject(&UFG::gSim, *((UFG::SimObject **)context + 5));
}

// File Line: 781
// RVA: 0x4393C0
void __fastcall UFG::StreamedResourceComponent::BindPart(UFG::StreamedResourceComponent *this, UFG::CompositeDrawableComponent *composite_drawable, UFG::PartDefinition *part, unsigned int part_index)
{
  unsigned int v4; // er14
  UFG::PartDefinition *v5; // rbx
  UFG::CompositeDrawableComponent *v6; // rbp
  const char *v7; // rax
  unsigned __int64 v8; // r10
  UFG::qReflectObject *v9; // rsi
  unsigned int v10; // er8
  unsigned int v11; // edx
  unsigned __int64 v12; // rsi
  __int64 v13; // rsi
  unsigned int i; // edi
  signed __int64 v15; // rbx
  __int64 v16; // rax
  ModelType *v17; // rax
  __int64 v18; // rdx
  unsigned int v19; // edx
  UFG::qResourceInventory *v20; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  UFG::qResourceHandle v24; // [rsp+38h] [rbp-40h]
  __int64 v25; // [rsp+58h] [rbp-20h]

  v4 = part_index;
  v5 = part;
  v6 = composite_drawable;
  v7 = UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData>::GetTypeName((UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData> *)this);
  v8 = UFG::qStringHash64(v7, 0xFFFFFFFFFFFFFFFFui64);
  v9 = v5->mModelAsset.mData;
  v10 = 0;
  v11 = (unsigned int)v9[2].mHandles.mNode.mPrev;
  if ( v11 )
  {
    v12 = v9[2].mTypeUID;
    while ( *(_QWORD *)(*(_QWORD *)(v12 + 8i64 * v10) + 56i64) != v8 )
    {
      if ( ++v10 >= v11 )
        goto LABEL_7;
    }
    v13 = *(_QWORD *)(v12 + 8i64 * v10);
  }
  else
  {
LABEL_7:
    v13 = 0i64;
  }
  for ( i = 0; i < *(_DWORD *)(v13 + 88); ++i )
  {
    v15 = *(_QWORD *)(v13 + 80) + 112i64 * i;
    v16 = *(unsigned int *)(v15 + 32);
    if ( (signed int)v16 < 4 )
    {
      if ( !v6->mModelType[v16] )
      {
        v17 = UFG::CompositeDrawableComponent::CreateModelType(v6, 0);
        v18 = *(unsigned int *)(v15 + 32);
        v6->mModelType[v18] = v17;
        v19 = v18 + 1;
        if ( v6->mNumModelTypeLODs > v19 )
          v19 = v6->mNumModelTypeLODs;
        v6->mNumModelTypeLODs = v19;
      }
      UFG::qResourceHandle::qResourceHandle(&v24);
      v20 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v21 = UFG::qResourceWarehouse::Instance();
        v20 = UFG::qResourceWarehouse::GetInventory(v21, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v20;
      }
      UFG::qResourceHandle::Init(&v24, 0xA2ADCD77, 0, v20);
      v25 = v15;
      ModelType::AddModelBinding(
        v6->mModelType[*(unsigned int *)(v15 + 32)],
        (Illusion::ModelProxy *)&v24,
        &UFG::qMatrix44::msIdentity,
        v4,
        0);
      v22 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v23 = UFG::qResourceWarehouse::Instance();
        v22 = UFG::qResourceWarehouse::GetInventory(v23, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v22;
      }
      UFG::qResourceHandle::Close(&v24, v22);
      UFG::qResourceHandle::~qResourceHandle(&v24);
    }
  }
}

// File Line: 801
// RVA: 0x444350
void __fastcall UFG::StreamedResourceComponent::UnbindPart(UFG::StreamedResourceComponent *this, UFG::CompositeDrawableComponent *composite_drawable, UFG::PartDefinition *part)
{
  UFG::PartDefinition *v3; // rbx
  UFG::CompositeDrawableComponent *v4; // rsi
  const char *v5; // rax
  unsigned __int64 v6; // r10
  UFG::qReflectObject *v7; // rdx
  __int64 v8; // r8
  unsigned int v9; // er9
  unsigned __int64 v10; // rdx
  __int64 v11; // r14
  unsigned int v12; // ebp
  signed __int64 v13; // rdi
  __int64 v14; // rbx
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax
  UFG::qResourceHandle v19; // [rsp+28h] [rbp-40h]
  __int64 v20; // [rsp+48h] [rbp-20h]

  v3 = part;
  v4 = composite_drawable;
  v5 = UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData>::GetTypeName((UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData> *)this);
  v6 = UFG::qStringHash64(v5, 0xFFFFFFFFFFFFFFFFui64);
  v7 = v3->mModelAsset.mData;
  v8 = 0i64;
  v9 = (unsigned int)v7[2].mHandles.mNode.mPrev;
  if ( v9 )
  {
    v10 = v7[2].mTypeUID;
    while ( *(_QWORD *)(*(_QWORD *)(v10 + 8 * v8) + 56i64) != v6 )
    {
      v8 = (unsigned int)(v8 + 1);
      if ( (unsigned int)v8 >= v9 )
        goto LABEL_7;
    }
    v11 = *(_QWORD *)(v10 + 8 * v8);
  }
  else
  {
LABEL_7:
    v11 = 0i64;
  }
  v12 = 0;
  if ( *(_DWORD *)(v11 + 88) )
  {
    do
    {
      v13 = *(_QWORD *)(v11 + 80) + 112i64 * v12;
      v14 = 0i64;
      if ( v4->mNumModelTypeLODs )
      {
        do
        {
          UFG::qResourceHandle::qResourceHandle(&v19);
          v15 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
          if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
          {
            v16 = UFG::qResourceWarehouse::Instance();
            v15 = UFG::qResourceWarehouse::GetInventory(v16, 0xA2ADCD77);
            `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v15;
          }
          UFG::qResourceHandle::Init(&v19, 0xA2ADCD77, 0, v15);
          v20 = v13;
          ModelType::RemoveModelBinding(v4->mModelType[v14], (Illusion::ModelProxy *)&v19);
          v17 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
          if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
          {
            v18 = UFG::qResourceWarehouse::Instance();
            v17 = UFG::qResourceWarehouse::GetInventory(v18, 0xA2ADCD77);
            `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v17;
          }
          UFG::qResourceHandle::Close(&v19, v17);
          UFG::qResourceHandle::~qResourceHandle(&v19);
          v14 = (unsigned int)(v14 + 1);
        }
        while ( (unsigned int)v14 < v4->mNumModelTypeLODs );
      }
      ++v12;
    }
    while ( v12 < *(_DWORD *)(v11 + 88) );
  }
}

// File Line: 814
// RVA: 0x4441B0
void __fastcall UFG::StreamedResourceComponent::UnbindModelResource(UFG::StreamedResourceComponent *this, UFG::CompositeDrawableComponent *composite_drawable, UFG::TrueCrowdModel *model_resource)
{
  UFG::TrueCrowdModel *v3; // r13
  UFG::CompositeDrawableComponent *v4; // r12
  unsigned __int16 v5; // ax
  unsigned int v6; // er14
  __int64 v7; // rax
  signed __int64 v8; // rcx
  signed __int64 v9; // rdi
  unsigned int v10; // ebx
  __int64 v11; // rax
  signed __int64 v12; // rcx
  ModelType *v13; // rsi
  unsigned int v14; // ebp
  UFG::qResourceInventory *v15; // rax
  UFG::qResourceWarehouse *v16; // rax
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax
  UFG::qResourceHandle v19; // [rsp+28h] [rbp-50h]
  __int64 v20; // [rsp+48h] [rbp-30h]

  v3 = model_resource;
  v4 = composite_drawable;
  v5 = model_resource->mNumLODs;
  if ( v5 )
  {
    v6 = 0;
    if ( v5 > 0u )
    {
      do
      {
        v7 = v3->mLODModel.mOffset;
        if ( v7 )
          v8 = (signed __int64)&v3->mLODModel + v7;
        else
          v8 = 0i64;
        v9 = v8 + 16i64 * v6;
        v10 = 0;
        if ( *(_DWORD *)v9 )
        {
          do
          {
            v11 = *(_QWORD *)(v9 + 8);
            if ( v11 )
              v12 = v11 + v9 + 8;
            else
              v12 = 0i64;
            v13 = v4->mModelType[v6];
            if ( v13 )
            {
              v14 = *(_DWORD *)(v12 + 16i64 * v10 + 8);
              UFG::qResourceHandle::qResourceHandle(&v19);
              v15 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
              if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
              {
                v16 = UFG::qResourceWarehouse::Instance();
                v15 = UFG::qResourceWarehouse::GetInventory(v16, 0xA2ADCD77);
                `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v15;
              }
              UFG::qResourceHandle::Init(&v19, 0xA2ADCD77, v14, v15);
              v20 = 0i64;
              ModelType::RemoveModelBinding(v13, (Illusion::ModelProxy *)&v19);
              v17 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
              if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
              {
                v18 = UFG::qResourceWarehouse::Instance();
                v17 = UFG::qResourceWarehouse::GetInventory(v18, 0xA2ADCD77);
                `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v17;
              }
              UFG::qResourceHandle::Close(&v19, v17);
              UFG::qResourceHandle::~qResourceHandle(&v19);
            }
            ++v10;
          }
          while ( v10 < *(_DWORD *)v9 );
        }
        ++v6;
      }
      while ( v6 < v3->mNumLODs );
    }
  }
}

// File Line: 837
// RVA: 0x4440F0
void __fastcall UFG::StreamedResourceComponent::UnbindAllModels(UFG::StreamedResourceComponent *this, UFG::CompositeDrawableComponent *composite_drawable)
{
  unsigned int v2; // edi
  UFG::CompositeDrawableComponent *v3; // rbp
  UFG::StreamedResourceComponent *v4; // rsi
  unsigned int v5; // ebx
  __int64 v6; // rax
  unsigned int v7; // ebx
  UFG::PartDefinition *v8; // rax

  v2 = 0;
  v3 = composite_drawable;
  v4 = this;
  v5 = 0;
  if ( this->mMeshLoader.mTrueCrowdInstance.mNumParts )
  {
    do
    {
      v6 = v4->mMeshLoader.mTrueCrowdInstance.mPart[v5].mModelIndex;
      if ( (_DWORD)v6 != -1 )
        UFG::StreamedResourceComponent::UnbindModelResource(
          v4,
          v3,
          v4->mMeshLoader.mTrueCrowdInstance.mSet->mFiles[v5].p[v6]);
      ++v5;
    }
    while ( v5 < v4->mMeshLoader.mTrueCrowdInstance.mNumParts );
  }
  v7 = v4->mPartLoader.mPartCount;
  if ( v7 )
  {
    do
    {
      v8 = UFG::PartLoader::GetPart(&v4->mPartLoader, v2);
      UFG::StreamedResourceComponent::UnbindPart(v4, v3, v8);
      ++v2;
    }
    while ( v2 < v7 );
  }
}

// File Line: 857
// RVA: 0x441470
void __fastcall UFG::StreamedResourceComponent::RefreshRenderState(UFG::StreamedResourceComponent *this, UFG::CompositeDrawableComponent *composite_drawable)
{
  UFG::CompositeDrawableComponent *v2; // rdi
  UFG::StreamedResourceComponent *v3; // rbx
  UFG::ICompositeLook *v4; // rcx
  unsigned int v5; // er8
  unsigned int v6; // er9
  UFG::ModelTextureCombination *v7; // rdx
  __int64 v8; // rcx
  ModelType *v9; // rax
  ModelType::ModelBindingSkin *v10; // rbx
  signed __int64 i; // rsi
  UFG::qResourceData *v12; // rax
  __int64 v13; // rcx
  signed __int64 v14; // rax

  v2 = composite_drawable;
  v3 = this;
  UFG::StreamedResourceComponent::UpdateMaterialModifiers(this, &composite_drawable->mMaterialModifier);
  v4 = v2->mCompositeLook;
  if ( v4 )
    v4->vfptr->OnUpdateMaterial(v4, v2);
  v5 = 0;
  v6 = v3->mMeshLoader.mTrueCrowdInstance.mNumParts;
  if ( v6 )
  {
    v7 = v3->mMeshLoader.mTrueCrowdInstance.mPart;
    while ( 1 )
    {
      v8 = v7->mModelIndex;
      if ( (_DWORD)v8 != -1 )
      {
        if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)((char *)&v3->mMeshLoader.mTrueCrowdInstance.mSet->mResourceFilename.mUID
                                               + (unsigned __int64)v7
                                               - ((_QWORD)v3
                                                + 272))
                                   + 8 * v8)
                       + 24i64) )
          break;
      }
      ++v5;
      ++v7;
      if ( v5 >= v6 )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    v9 = v2->mModelType[0];
    if ( v9 )
    {
      v10 = (ModelType::ModelBindingSkin *)v9->mModelBindingSkinTable.mNode.mNext;
      for ( i = (signed __int64)&v9->mModelBindingSkinTable;
            v10 != (ModelType::ModelBindingSkin *)i;
            v10 = (ModelType::ModelBindingSkin *)v10->mNext )
      {
        if ( !v10->mSoftbody )
        {
          v12 = v10->mModelProxy.mModelHandle.mData;
          if ( v12 )
          {
            v13 = *(_QWORD *)&v12[2].mNode.mUID;
            if ( v13 )
              v14 = (signed __int64)&v12[2].mNode.mUID + v13;
            else
              v14 = 0i64;
            if ( *(_DWORD *)(v14 + 8) )
              Render::ISoftbody::GenerateSoftbody(&Render::gSoftbody, v2, v10);
          }
        }
      }
    }
  }
  UFG::CompositeDrawableComponent::UpdateHasSoftBody(v2);
}

// File Line: 904
// RVA: 0x438F40
void __fastcall UFG::StreamedResourceComponent::BindModelResource(UFG::StreamedResourceComponent *this, UFG::CompositeDrawableComponent *composite_drawable, unsigned int index, UFG::TrueCrowdModel *model_resource, const unsigned int *boneUIDs, unsigned int numBoneUIDs)
{
  UFG::TrueCrowdModel *v6; // r12
  UFG::CompositeDrawableComponent *v7; // rbx
  unsigned __int16 v8; // ax
  unsigned int v9; // edi
  unsigned int v10; // edx
  signed __int64 v11; // r13
  int v12; // ecx
  __int64 v13; // rax
  signed __int64 v14; // rcx
  signed __int64 v15; // r15
  unsigned int v16; // er12
  __int64 v17; // rax
  signed __int64 v18; // rcx
  signed __int64 v19; // rbx
  const unsigned int *v20; // rdi
  __int64 v21; // rsi
  unsigned int v22; // ebp
  unsigned int v23; // er14
  UFG::qResourceInventory *v24; // rax
  UFG::qResourceWarehouse *v25; // rax
  UFG::qResourceInventory *v26; // rax
  UFG::qResourceWarehouse *v27; // rax
  unsigned int v28; // ebx
  UFG::qResourceInventory *v29; // rax
  UFG::qResourceWarehouse *v30; // rax
  ModelType::ModelBindingSkin *v31; // rbp
  UFG::qResourceInventory *v32; // rax
  UFG::qResourceWarehouse *v33; // rax
  unsigned int v34; // esi
  __int64 v35; // rax
  signed __int64 v36; // rcx
  signed __int64 v37; // rbx
  UFG::allocator::free_link *v38; // rax
  ModelType::SimpleMorphTargets *v39; // rax
  __int64 v40; // r14
  __int64 v41; // rdi
  unsigned int v42; // ebx
  UFG::qResourceHandle *v43; // rdi
  UFG::qResourceInventory *v44; // rax
  UFG::qResourceWarehouse *v45; // rax
  unsigned int v46; // edx
  ModelType::SimpleMorphTargets *v47; // rcx
  unsigned int lod; // [rsp+30h] [rbp-C8h]
  int v49; // [rsp+34h] [rbp-C4h]
  signed __int64 v50; // [rsp+40h] [rbp-B8h]
  UFG::qResourceHandle v51; // [rsp+48h] [rbp-B0h]
  __int64 v52; // [rsp+68h] [rbp-90h]
  UFG::qResourceHandle v53; // [rsp+70h] [rbp-88h]
  __int64 v54; // [rsp+90h] [rbp-68h]
  __int64 v55; // [rsp+98h] [rbp-60h]
  UFG::qResourceHandle *v56; // [rsp+A0h] [rbp-58h]
  UFG::StreamedResourceComponent *v57; // [rsp+100h] [rbp+8h]
  UFG::CompositeDrawableComponent *v58; // [rsp+108h] [rbp+10h]
  unsigned int model_index; // [rsp+110h] [rbp+18h]
  UFG::TrueCrowdModel *v60; // [rsp+118h] [rbp+20h]

  v60 = model_resource;
  model_index = index;
  v58 = composite_drawable;
  v57 = this;
  v55 = -2i64;
  v6 = model_resource;
  v7 = composite_drawable;
  v8 = model_resource->mNumLODs;
  if ( !v8 )
    return;
  v9 = 0;
  lod = 0;
  if ( v8 <= 0u )
    return;
  v10 = numBoneUIDs;
  do
  {
    v11 = (signed __int64)v7 + 8 * v9;
    if ( !*(_QWORD *)(v11 + 1424) )
    {
      *(_QWORD *)(v11 + 1424) = UFG::CompositeDrawableComponent::CreateModelType(v7, 0);
      v12 = v9 + 1;
      if ( v7->mNumModelTypeLODs > v9 + 1 )
        v12 = v7->mNumModelTypeLODs;
      v7->mNumModelTypeLODs = v12;
      v10 = numBoneUIDs;
    }
    v13 = v6->mLODModel.mOffset;
    if ( v13 )
      v14 = (signed __int64)&v6->mLODModel + v13;
    else
      v14 = 0i64;
    v15 = v14 + 16i64 * v9;
    v50 = v15;
    v16 = 0;
    v49 = 0;
    if ( !*(_DWORD *)v15 )
      goto LABEL_53;
    while ( 1 )
    {
      v17 = *(_QWORD *)(v15 + 8);
      v18 = v17 ? v17 + v15 + 8 : 0i64;
      v19 = v18 + 16i64 * v16;
      if ( *(_WORD *)(v19 + 12) )
        break;
      if ( !*(_WORD *)(v19 + 14) )
      {
        if ( v10 )
        {
          v56 = &v53;
          v20 = boneUIDs;
          v21 = v10;
          do
          {
            v22 = Skeleton::GetBoneID((Skeleton *)v58->mRigHandle.mData[3].mNode.mParent, *v20);
            v23 = *(_DWORD *)(v19 + 8);
            UFG::qResourceHandle::qResourceHandle(&v53);
            v24 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
            if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
            {
              v25 = UFG::qResourceWarehouse::Instance();
              v24 = UFG::qResourceWarehouse::GetInventory(v25, 0xA2ADCD77);
              `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v24;
            }
            UFG::qResourceHandle::Init(&v53, 0xA2ADCD77, v23, v24);
            v54 = 0i64;
            ModelType::AddRigidModelBinding(
              *(ModelType **)(v11 + 1424),
              (Illusion::ModelProxy *)&v53,
              v22,
              &UFG::qMatrix44::msIdentity,
              model_index);
            v26 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
            if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
            {
              v27 = UFG::qResourceWarehouse::Instance();
              v26 = UFG::qResourceWarehouse::GetInventory(v27, 0xA2ADCD77);
              `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v26;
            }
            UFG::qResourceHandle::Close(&v53, v26);
            UFG::qResourceHandle::~qResourceHandle(&v53);
            ++v20;
            --v21;
          }
          while ( v21 );
          v15 = v50;
          v16 = v49;
        }
        else
        {
          ModelType::buildModelBindingRigid(*(ModelType **)(v11 + 1424));
        }
      }
LABEL_28:
      v49 = ++v16;
      if ( v16 >= *(_DWORD *)v15 )
        goto LABEL_51;
      v10 = numBoneUIDs;
    }
    if ( *(_WORD *)(v19 + 14) > 1u )
      goto LABEL_28;
    v28 = *(_DWORD *)(v19 + 8);
    UFG::qResourceHandle::qResourceHandle(&v51);
    v29 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v30 = UFG::qResourceWarehouse::Instance();
      v29 = UFG::qResourceWarehouse::GetInventory(v30, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v29;
    }
    UFG::qResourceHandle::Init(&v51, 0xA2ADCD77, v28, v29);
    v52 = 0i64;
    v9 = lod;
    v31 = ModelType::AddSkinModelBinding(
            *(ModelType **)(v11 + 1424),
            (Illusion::ModelProxy *)&v51,
            &UFG::qMatrix44::msIdentity,
            model_index,
            lod);
    v32 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v33 = UFG::qResourceWarehouse::Instance();
      v32 = UFG::qResourceWarehouse::GetInventory(v33, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v32;
    }
    UFG::qResourceHandle::Close(&v51, v32);
    UFG::qResourceHandle::~qResourceHandle(&v51);
    if ( v31 )
    {
      v34 = 0;
      if ( *(_DWORD *)v15 )
      {
        do
        {
          v35 = *(_QWORD *)(v15 + 8);
          if ( v35 )
            v36 = v35 + v15 + 8;
          else
            v36 = 0i64;
          v37 = v36 + 16i64 * v34;
          if ( (unsigned int)(*(signed __int16 *)(v37 + 14) - 2) <= 1 )
          {
            if ( !v31->mMorphTargets )
            {
              v38 = UFG::qMalloc(0x50ui64, "StreamedResourceComponent::BindModelResource::MorphTargets", 0i64);
              if ( v38 )
                ModelType::SimpleMorphTargets::SimpleMorphTargets((ModelType::SimpleMorphTargets *)v38);
              else
                v39 = 0i64;
              v31->mMorphTargets = v39;
              v39->mNumModelBindings = 0;
            }
            v40 = (unsigned int)(*(signed __int16 *)(v37 + 14) - 2);
            v41 = (unsigned int)(*(signed __int16 *)(v37 + 14) - 2);
            v31->mMorphTargets->mMorphWeights[v40] = v57->mMeshLoader.mTrueCrowdInstance.mMorphWeights[v40];
            v42 = *(_DWORD *)(v37 + 8);
            v43 = (UFG::qResourceHandle *)&v31->mMorphTargets->mModelHandles[v41].mPrev;
            v44 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
            if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
            {
              v45 = UFG::qResourceWarehouse::Instance();
              v44 = UFG::qResourceWarehouse::GetInventory(v45, 0xA2ADCD77);
              `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v44;
            }
            UFG::qResourceHandle::Init(v43, 0xA2ADCD77, v42, v44);
            v46 = v40 + 1;
            v47 = v31->mMorphTargets;
            if ( v47->mNumModelBindings > (unsigned int)(v40 + 1) )
              v46 = v47->mNumModelBindings;
            v47->mNumModelBindings = v46;
          }
          ++v34;
        }
        while ( v34 < *(_DWORD *)v15 );
LABEL_51:
        v9 = lod;
        goto LABEL_52;
      }
    }
LABEL_52:
    v7 = v58;
LABEL_53:
    lod = ++v9;
    v6 = v60;
    v10 = numBoneUIDs;
  }
  while ( v9 < v60->mNumLODs );
}

// File Line: 992
// RVA: 0x438DD0
void __fastcall UFG::StreamedResourceComponent::BindAllModels(UFG::StreamedResourceComponent *this, UFG::CompositeDrawableComponent *composite_drawable, bool using_temp_rig)
{
  unsigned int v3; // ebp
  UFG::CompositeDrawableComponent *v4; // r14
  UFG::StreamedResourceComponent *v5; // rdi
  unsigned int v6; // esi
  unsigned int v7; // eax
  UFG::TrueCrowdModel *v8; // rbx
  __int64 v9; // rax
  signed __int64 v10; // rax
  ModelType *v11; // rcx
  UFG::ResourceRequest *v12; // rax
  char *v13; // rcx
  unsigned int v14; // ebx
  UFG::PartDefinition *v15; // rax

  v3 = 0;
  v4 = composite_drawable;
  v5 = this;
  if ( !using_temp_rig )
  {
    v6 = 0;
    if ( this->mMeshLoader.mTrueCrowdInstance.mNumParts > 0 )
    {
      do
      {
        v7 = v5->mMeshLoader.mTrueCrowdInstance.mPart[v6].mModelIndex;
        if ( v7 != -1 )
        {
          v8 = v5->mMeshLoader.mTrueCrowdInstance.mSet->mFiles[v6].p[v7];
          if ( v5->mMeshLoader.mHighDefinition )
          {
            v9 = v8->mHighResolutionResource.mOffset;
            if ( v9 )
            {
              v10 = (signed __int64)&v8->mHighResolutionResource + v9;
              if ( v10 )
                v8 = (UFG::TrueCrowdModel *)v10;
            }
          }
          if ( !v5->mFirstResourceLoad && !v8->mType.mValue )
          {
            v11 = v4->mModelType[0];
            if ( v11 )
            {
              ModelType::RemoveAllSkinModelBindings(v11);
              v5->mFirstResourceLoad = 1;
            }
          }
          v12 = v8->mRequest;
          if ( v12 && v12->mLoadStatus == 3 )
          {
            v13 = (char *)UFG::TrueCrowdDataBase::sTrueCrowdDataBase
                + 1292 * v5->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex;
            UFG::StreamedResourceComponent::BindModelResource(
              v5,
              v4,
              v6,
              v8,
              (const unsigned int *)&v13[80 * v6 + 1016],
              *(_DWORD *)&v13[80 * v6 + 1080]);
          }
        }
        ++v6;
      }
      while ( v6 < v5->mMeshLoader.mTrueCrowdInstance.mNumParts );
    }
  }
  v14 = v5->mPartLoader.mPartCount;
  if ( v14 )
  {
    do
    {
      v15 = UFG::PartLoader::GetPart(&v5->mPartLoader, v3);
      UFG::StreamedResourceComponent::BindPart(v5, v4, v15, v3++);
    }
    while ( v3 < v14 );
  }
  UFG::StreamedResourceComponent::RefreshRenderState(v5, v4);
}

// File Line: 1039
// RVA: 0x43B780
void __fastcall UFG::StreamedResourceComponent::DispatchResourceEvent(UFG::StreamedResourceComponent *this, UFG::ResourceRequest *request, bool loaded)
{
  UFG::SimObjectGame *v3; // rbx
  const char *v4; // r14
  bool v5; // r15
  UFG::ResourceRequest *v6; // r12
  UFG::StreamedResourceComponent *v7; // rsi
  signed int v8; // ebp
  unsigned int v9; // er8
  unsigned int v10; // edx
  UFG::ResourceRequest **v11; // rcx
  unsigned __int16 v12; // cx
  UFG::CompositeDrawableComponent *v13; // rdi
  UFG::SimComponent *v14; // rax
  unsigned __int16 v15; // cx
  UFG::SimComponent *v16; // rax
  bool v17; // zf
  bool v18; // al
  unsigned __int16 v19; // cx
  UFG::SimComponentHolder *v20; // rdx
  UFG::SimComponent *v21; // rax
  UFG::SimComponent *v22; // rcx
  bool v23; // dl
  bool v24; // al
  UFG::SceneObjectProperties *v25; // rax
  UFG::qPropertySet *v26; // rcx
  UFG::qPropertySet *v27; // rax
  char *v28; // rax
  __int64 v29; // rcx
  __int64 v30; // rdx
  const char *v31; // rax
  unsigned int v32; // eax
  unsigned __int16 v33; // cx
  UFG::PhysicsMoverInterface *v34; // rax
  unsigned __int16 v35; // cx
  UFG::VehicleEffectsComponent *v36; // rax

  v3 = (UFG::SimObjectGame *)this->m_pSimObject;
  v4 = 0i64;
  v5 = loaded;
  v6 = request;
  v7 = this;
  v8 = 0;
  if ( loaded )
  {
    if ( !this->mMeshLoader.mPropertySet )
      goto LABEL_9;
    v9 = this->mMeshLoader.mResourceCount;
    if ( v9 )
    {
      v10 = 0;
      v11 = this->mMeshLoader.mResourceRequests;
      while ( (*v11)->mLoadStatus == 3 )
      {
        ++v10;
        ++v11;
        if ( v10 >= v9 )
          goto LABEL_9;
      }
    }
    if ( UFG::PartLoader::IsLoaded(&v7->mPartLoader) )
    {
LABEL_9:
      if ( !v7->mResourcesBound )
      {
        v8 = 2;
        v7->mResourcesBound = 1;
      }
    }
  }
  else if ( this->mResourcesBound )
  {
    v8 = 1;
    this->mResourcesBound = 0;
  }
  if ( v3 )
  {
    v12 = v3->m_Flags;
    if ( (v12 >> 14) & 1 )
    {
      v13 = (UFG::CompositeDrawableComponent *)v3->m_Components.p[14].m_pComponent;
    }
    else if ( (v12 & 0x8000u) == 0 )
    {
      if ( (v12 >> 13) & 1 )
      {
        v13 = (UFG::CompositeDrawableComponent *)v3->m_Components.p[9].m_pComponent;
      }
      else
      {
        v14 = (v12 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::CompositeDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v3->vfptr, UFG::CompositeDrawableComponent::_TypeUID);
        v13 = (UFG::CompositeDrawableComponent *)v14;
      }
    }
    else
    {
      v13 = (UFG::CompositeDrawableComponent *)v3->m_Components.p[14].m_pComponent;
    }
    if ( v13 )
    {
      if ( v8 == 2 )
      {
        v15 = v3->m_Flags;
        if ( (v15 >> 14) & 1 )
        {
          v16 = v3->m_Components.p[9].m_pComponent;
        }
        else if ( (v15 & 0x8000u) == 0 )
        {
          if ( (v15 >> 13) & 1 )
          {
            v16 = v3->m_Components.p[8].m_pComponent;
          }
          else if ( (v15 >> 12) & 1 )
          {
            v16 = UFG::SimObjectGame::GetComponentOfTypeHK(v3, UFG::BaseAnimationComponent::_TypeUID);
          }
          else
          {
            v16 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v3->vfptr,
                    UFG::BaseAnimationComponent::_TypeUID);
          }
        }
        else
        {
          v16 = v3->m_Components.p[9].m_pComponent;
        }
        if ( BYTE1(v16[3].vfptr) || (v17 = *(_QWORD *)&v16[1].m_Flags == 0i64, v18 = 0, v17) )
          v18 = 1;
        UFG::StreamedResourceComponent::BindAllModels(v7, v13, v18);
      }
      else if ( v8 == 1 )
      {
        UFG::StreamedResourceComponent::UnbindAllModels(v7, v13);
      }
    }
  }
  v19 = v3->m_Flags;
  if ( (v19 & 0x8000u) != 0 )
  {
    if ( v8 == 2 )
    {
      v20 = v3->m_Components.p;
      v21 = v20[9].m_pComponent;
      v17 = ((v19 >> 14) & 1) == 0;
      v22 = 0i64;
      if ( v17 )
        v22 = v20[34].m_pComponent;
      v23 = v21 && (BYTE1(v21[3].vfptr) || !*(_QWORD *)&v21[1].m_Flags);
      v24 = v22 && BYTE2(v22[14].m_SafePointerList.mNode.mNext);
      if ( v23 || v24 )
      {
        v25 = v3->m_pSceneObj;
        v26 = v25->mpWritableProperties;
        if ( !v26 )
          v26 = v25->mpConstProperties;
        v27 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                v26,
                (UFG::qSymbol *)&component_BaseAnimation::sPropertyName.mUID,
                DEPTH_RECURSE);
        if ( v27 )
          v28 = UFG::qPropertySet::GetMemImagePtr(v27);
        else
          v28 = 0i64;
        v29 = *((_QWORD *)v28 + 1);
        if ( v29 )
          v4 = &v28[v29 + 8];
        if ( v7->mMeshLoader.mHighDefinition )
        {
          v30 = *((_QWORD *)v28 + 4);
          if ( v30 )
          {
            v31 = &v28[v30 + 32];
            if ( v31 )
            {
              if ( *v31 )
                v4 = v31;
            }
          }
        }
        v32 = UFG::qStringHashUpper32(v4, 0xFFFFFFFF);
        if ( UFG::qResourceInventory::Get((UFG::qResourceInventory *)&UFG::gRigInventory.vfptr, v32) )
          UFG::StreamedResourceComponent::SwapVehicleRig((UFG::SimObject *)&v3->vfptr);
      }
    }
    else if ( !v8 )
    {
      return;
    }
    v33 = v3->m_Flags;
    if ( (v33 >> 14) & 1 )
      goto LABEL_80;
    if ( (v33 & 0x8000u) == 0 )
    {
      if ( (v33 >> 13) & 1 )
      {
LABEL_80:
        v35 = v3->m_Flags;
        if ( (v35 >> 14) & 1 )
        {
          v36 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v3,
                                                  UFG::VehicleEffectsComponent::_TypeUID);
        }
        else if ( (v35 & 0x8000u) == 0 )
        {
          if ( (v35 >> 13) & 1 )
          {
            v36 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v3,
                                                    UFG::VehicleEffectsComponent::_TypeUID);
          }
          else if ( (v35 >> 12) & 1 )
          {
            v36 = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                    v3,
                                                    UFG::VehicleEffectsComponent::_TypeUID);
          }
          else
          {
            v36 = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                    (UFG::SimObject *)&v3->vfptr,
                                                    UFG::VehicleEffectsComponent::_TypeUID);
          }
        }
        else
        {
          v36 = (UFG::VehicleEffectsComponent *)v3->m_Components.p[32].m_pComponent;
        }
        if ( v36 )
          UFG::VehicleEffectsComponent::HandleResourceLoadedEvent(v36, v6, v5);
        return;
      }
      if ( (v33 >> 12) & 1 )
        v34 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              v3,
                                              UFG::PhysicsMoverInterface::_TypeUID);
      else
        v34 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                              (UFG::SimObject *)&v3->vfptr,
                                              UFG::PhysicsMoverInterface::_TypeUID);
    }
    else
    {
      v34 = (UFG::PhysicsMoverInterface *)v3->m_Components.p[34].m_pComponent;
    }
    if ( v34 )
      UFG::PhysicsMoverInterface::HandleResourceLoadedEvent(v34, v6, v5);
    goto LABEL_80;
  }
}

// File Line: 1128
// RVA: 0x43FAD0
void __fastcall UFG::StreamedResourceComponent::OnPartLoadEventCallback(void *context, UFG::PartRequest *request, bool loaded)
{
  JUMPOUT(context, 0i64, UFG::StreamedResourceComponent::DispatchPartEvent);
}

// File Line: 1147
// RVA: 0x43B2B0
void __fastcall UFG::StreamedResourceComponent::DispatchPartEvent(UFG::StreamedResourceComponent *this, UFG::PartRequest *request, bool loaded)
{
  UFG::StreamedResourceComponent *v3; // rsi
  UFG::SimObjectGame *v4; // r14
  bool v5; // r12
  signed int v6; // ebp
  UFG::SimObjectGame *v7; // rcx
  UFG::SimComponent *v8; // rbx
  unsigned __int16 v9; // dx
  UFG::SimComponent *v10; // rax
  UFG::RigResource *v11; // rdi
  UFG::allocator::free_link *v12; // rax
  Creature *v13; // rax
  UFG::SimObject *v14; // rdi
  UFG::TransformNodeComponent *v15; // rdi
  UFG::SimObjectGame *v16; // rcx
  unsigned __int16 v17; // dx
  UFG::CompositeDrawableComponent *v18; // rcx
  UFG::SimComponent *v19; // rax
  UFG::SimObjectGame *v20; // rcx
  unsigned __int16 v21; // dx
  UFG::SimComponent *v22; // rax
  unsigned int v23; // er15
  unsigned int v24; // ebp
  UFG::qReflectObject *v25; // rdi
  unsigned int i; // ebx
  __int64 v27; // rcx
  unsigned __int16 v28; // cx
  UFG::CompositeDrawableComponent *v29; // rbx
  UFG::SimComponent *v30; // rax
  unsigned __int16 v31; // cx
  UFG::SimComponent *v32; // rax
  unsigned __int16 v33; // cx
  UFG::AIOutlineComponent *v34; // rax
  signed int v35; // [rsp+80h] [rbp+18h]

  v3 = this;
  v4 = (UFG::SimObjectGame *)this->m_pSimObject;
  v5 = 0;
  v6 = 0;
  v35 = 0;
  if ( !loaded )
  {
    if ( !this->mPartsBound )
      goto LABEL_8;
    v6 = 1;
    this->mPartsBound = 0;
    goto LABEL_7;
  }
  if ( UFG::PartLoader::IsLoaded(&this->mPartLoader) && !v3->mPartsBound )
  {
    v6 = 2;
    v3->mPartsBound = 1;
LABEL_7:
    v35 = v6;
  }
LABEL_8:
  v7 = (UFG::SimObjectGame *)v3->m_pSimObject;
  if ( v7 )
  {
    v9 = v7->m_Flags;
    if ( (v9 >> 14) & 1 )
    {
      v8 = v7->m_Components.p[9].m_pComponent;
    }
    else if ( (v9 & 0x8000u) == 0 )
    {
      if ( (v9 >> 13) & 1 )
      {
        v8 = v7->m_Components.p[8].m_pComponent;
      }
      else
      {
        if ( (v9 >> 12) & 1 )
          v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::BaseAnimationComponent::_TypeUID);
        else
          v10 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v7->vfptr, UFG::BaseAnimationComponent::_TypeUID);
        v8 = v10;
      }
    }
    else
    {
      v8 = v7->m_Components.p[9].m_pComponent;
    }
  }
  else
  {
    v8 = 0i64;
  }
  v11 = *(UFG::RigResource **)&v8[1].m_Flags;
  if ( v11 && !*(_QWORD *)&v8[2].m_TypeUID )
  {
    v12 = UFG::qMalloc(0x3A0ui64, "BaseAnimationComponent.mCreature", 0i64);
    if ( v12 )
      Creature::Creature((Creature *)v12, v11);
    else
      v13 = 0i64;
    *(_QWORD *)&v8[2].m_TypeUID = v13;
    v14 = v3->m_pSimObject;
    if ( v14 )
    {
      v15 = v14->m_pTransformNodeComponent;
      if ( v15 )
      {
        Creature::SetTransformNodeComponentRoot(v13, v15);
        UFG::TransformNodeComponent::UpdateWorldTransform(v15);
        Creature::SetTransform(*(Creature **)&v8[2].m_TypeUID, &v15->mWorldTransform);
      }
    }
    v16 = (UFG::SimObjectGame *)v3->m_pSimObject;
    if ( v16 )
    {
      v17 = v16->m_Flags;
      if ( (v17 >> 14) & 1 )
      {
        v18 = (UFG::CompositeDrawableComponent *)v16->m_Components.p[14].m_pComponent;
      }
      else if ( (v17 & 0x8000u) == 0 )
      {
        if ( (v17 >> 13) & 1 )
        {
          v18 = (UFG::CompositeDrawableComponent *)v16->m_Components.p[9].m_pComponent;
        }
        else
        {
          v19 = (v17 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                    v16,
                                    UFG::CompositeDrawableComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                   (UFG::SimObject *)&v16->vfptr,
                                                                                   UFG::CompositeDrawableComponent::_TypeUID);
          v18 = (UFG::CompositeDrawableComponent *)v19;
        }
      }
      else
      {
        v18 = (UFG::CompositeDrawableComponent *)v16->m_Components.p[14].m_pComponent;
      }
      if ( v18 )
      {
        v18->mPose = (SkeletalPose *)(*(_QWORD *)&v8[2].m_TypeUID + 240i64);
        UFG::CompositeDrawableComponent::SetRig(v18, HIDWORD(v8[3].vfptr));
      }
    }
    v20 = (UFG::SimObjectGame *)v3->m_pSimObject;
    if ( v20 )
    {
      v21 = v20->m_Flags;
      if ( (v21 >> 14) & 1 )
      {
        v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, Render::FXSimComponent::_TypeUID);
      }
      else if ( (v21 & 0x8000u) == 0 )
      {
        if ( (v21 >> 13) & 1 )
          v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, Render::FXSimComponent::_TypeUID);
        else
          v22 = (v21 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v20, Render::FXSimComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v20->vfptr, Render::FXSimComponent::_TypeUID);
      }
      else
      {
        v22 = UFG::SimObjectGame::GetComponentOfTypeHK(v20, Render::FXSimComponent::_TypeUID);
      }
      if ( v22 )
        *(_QWORD *)&v22[1].m_Flags = *(_QWORD *)&v8[2].m_TypeUID + 240i64;
    }
  }
  if ( v6 == 2 && v3->mPartsBound )
  {
    v23 = v3->mPartLoader.mPartCount;
    v24 = 0;
    if ( v23 )
    {
      do
      {
        v25 = UFG::PartLoader::GetPart(&v3->mPartLoader, v24)->mModelAsset.mData;
        for ( i = 0; i < LODWORD(v25[2].mHandles.mNode.mPrev); ++i )
        {
          v27 = *(_QWORD *)(v25[2].mTypeUID + 8i64 * i);
          (*(void (__fastcall **)(__int64, UFG::SimObject *, UFG::qReflectObject *))(*(_QWORD *)v27 + 24i64))(
            v27,
            v3->m_pSimObject,
            v25);
        }
        ++v24;
      }
      while ( v24 < v23 );
    }
    v6 = v35;
  }
  if ( v4 )
  {
    v28 = v4->m_Flags;
    if ( (v28 >> 14) & 1 )
    {
      v29 = (UFG::CompositeDrawableComponent *)v4->m_Components.p[14].m_pComponent;
    }
    else if ( (v28 & 0x8000u) == 0 )
    {
      if ( (v28 >> 13) & 1 )
      {
        v29 = (UFG::CompositeDrawableComponent *)v4->m_Components.p[9].m_pComponent;
      }
      else
      {
        if ( (v28 >> 12) & 1 )
          v30 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::CompositeDrawableComponent::_TypeUID);
        else
          v30 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v4->vfptr,
                  UFG::CompositeDrawableComponent::_TypeUID);
        v29 = (UFG::CompositeDrawableComponent *)v30;
      }
    }
    else
    {
      v29 = (UFG::CompositeDrawableComponent *)v4->m_Components.p[14].m_pComponent;
    }
    if ( v29 )
    {
      if ( v6 == 2 )
      {
        v31 = v4->m_Flags;
        if ( (v31 >> 14) & 1 )
        {
          v32 = v4->m_Components.p[9].m_pComponent;
        }
        else if ( (v31 & 0x8000u) == 0 )
        {
          if ( (v31 >> 13) & 1 )
          {
            v32 = v4->m_Components.p[8].m_pComponent;
          }
          else if ( (v31 >> 12) & 1 )
          {
            v32 = UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::BaseAnimationComponent::_TypeUID);
          }
          else
          {
            v32 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v4->vfptr,
                    UFG::BaseAnimationComponent::_TypeUID);
          }
        }
        else
        {
          v32 = v4->m_Components.p[9].m_pComponent;
        }
        if ( BYTE1(v32[3].vfptr) || !*(_QWORD *)&v32[1].m_Flags )
          v5 = 1;
        UFG::StreamedResourceComponent::BindAllModels(v3, v29, v5);
      }
      else if ( v6 == 1 )
      {
        UFG::StreamedResourceComponent::UnbindAllModels(v3, v29);
      }
    }
    v33 = v4->m_Flags;
    if ( (v33 >> 14) & 1 )
    {
      v34 = (UFG::AIOutlineComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AIOutlineComponent::_TypeUID);
    }
    else if ( (v33 & 0x8000u) == 0 )
    {
      if ( (v33 >> 13) & 1 )
      {
        v34 = (UFG::AIOutlineComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AIOutlineComponent::_TypeUID);
      }
      else if ( (v33 >> 12) & 1 )
      {
        v34 = (UFG::AIOutlineComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(v4, UFG::AIOutlineComponent::_TypeUID);
      }
      else
      {
        v34 = (UFG::AIOutlineComponent *)UFG::SimObject::GetComponentOfType(
                                           (UFG::SimObject *)&v4->vfptr,
                                           UFG::AIOutlineComponent::_TypeUID);
      }
    }
    else
    {
      v34 = (UFG::AIOutlineComponent *)v4->m_Components.p[27].m_pComponent;
    }
    if ( v34 )
    {
      if ( v6 == 2 )
        UFG::AIOutlineComponent::Init(v34);
    }
  }
}

// File Line: 1248
// RVA: 0x43D0D0
UFG::qPropertySet *__fastcall UFG::StreamedResourceComponent::GetAssetPropertySet(UFG::StreamedResourceComponent *this, UFG::qSymbol *propName)
{
  UFG::TrueCrowdSet::Instance *v2; // rdi
  int v3; // ebx
  UFG::qSymbol *v4; // rsi
  __int64 v5; // rcx
  UFG::qPropertySet *v6; // rcx
  UFG::qPropertySet *result; // rax

  v2 = &this->mMeshLoader.mTrueCrowdInstance;
  v3 = 0;
  v4 = propName;
  if ( !this->mMeshLoader.mTrueCrowdInstance.mNumParts )
    return 0i64;
  while ( 1 )
  {
    v5 = v2->mPart[v3].mModelIndex;
    if ( (_DWORD)v5 != -1 )
    {
      v6 = v2->mSet->mFiles[v3].p[v5]->mPropSet;
      if ( v6 )
      {
        result = UFG::qPropertySet::Get<UFG::qPropertySet>(v6, v4, DEPTH_RECURSE);
        if ( result )
          break;
      }
    }
    if ( ++v3 >= v2->mNumParts )
      return 0i64;
  }
  return result;
}

// File Line: 1270
// RVA: 0x443550
void __fastcall UFG::StreamedResourceComponent::SwapResource(UFG::StreamedResourceComponent *this, unsigned int componentIndex, UFG::qSymbol *modelPathSymbol, UFG::qSymbol *textureSetPathSymbol, const int *colourTintIndex)
{
  UFG::qSymbol *v5; // r15
  UFG::TrueCrowdSet *v6; // rdi
  signed __int64 v7; // rbx
  unsigned __int64 v8; // r9
  unsigned int v9; // eax
  signed __int64 v10; // r14
  UFG::TrueCrowdModel *v11; // r12
  UFG::TrueCrowdModel *v12; // rsi
  UFG::qSymbol *v13; // rcx
  UFG::qSymbol *v14; // rax
  unsigned int v15; // eax
  signed __int64 v16; // r13
  unsigned int v17; // ecx
  __int64 v18; // r8
  __int64 v19; // r9
  signed __int64 v20; // rax
  signed __int64 v21; // rdx
  __int64 v22; // rax
  signed __int64 v23; // rax
  signed __int64 v24; // rdx
  __int64 v25; // rax
  __int64 v26; // rax
  _QWORD *v27; // rax
  bool v28; // bp
  unsigned int v29; // ecx
  __int64 v30; // rdx
  signed __int64 v31; // rdx
  __int64 v32; // rcx
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> **v33; // rdi
  __int64 v34; // rbp
  unsigned int v35; // edx
  unsigned int v36; // ebx
  unsigned int v37; // edx
  UFG::qNode<UFG::TrueCrowdSet,UFG::TrueCrowdSet> *v38; // rax
  __int64 v39; // [rsp+20h] [rbp-58h]
  UFG::StreamPriorityHandle *item; // [rsp+28h] [rbp-50h]
  unsigned __int64 v41; // [rsp+30h] [rbp-48h]
  __int64 v42; // [rsp+38h] [rbp-40h]
  UFG::StreamedResourceComponent *v43; // [rsp+80h] [rbp+8h]

  v43 = this;
  v5 = textureSetPathSymbol;
  if ( !this->mMeshLoader.mHighDefinition )
  {
    v6 = this->mMeshLoader.mTrueCrowdInstance.mSet;
    v7 = 0i64;
    v8 = componentIndex;
    v9 = this->mMeshLoader.mTrueCrowdInstance.mPart[v8].mModelIndex;
    v39 = componentIndex;
    v10 = componentIndex;
    v41 = 16i64 * componentIndex;
    HIDWORD(v42) = 0;
    v11 = 0i64;
    item = 0i64;
    if ( v9 != -1 )
    {
      v11 = v6->mFiles[v8].p[v9];
      item = (UFG::StreamPriorityHandle *)v6->mFiles[v8].p[v9];
    }
    v12 = v11;
    v13 = &UFG::gNullQSymbol;
    v14 = &v11->mPathSymbol;
    if ( !v11 )
      v14 = &UFG::gNullQSymbol;
    v15 = v14->mUID;
    if ( modelPathSymbol )
      v13 = modelPathSymbol;
    if ( v13->mUID != v15 )
    {
      v12 = 0i64;
      if ( modelPathSymbol )
      {
        if ( modelPathSymbol->mUID != UFG::gNullQSymbol.mUID )
          v12 = UFG::TrueCrowdDataBase::QueryModelFromPath(
                  UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                  v6->mEntityIndex,
                  componentIndex,
                  modelPathSymbol);
      }
    }
    v16 = 0i64;
    *(_WORD *)&v6->mComponentDetails[v10].mbSpecificModel = 1;
    v6->mComponentDetails[v10].mbColourTintIndexValid = 0;
    if ( v12 )
    {
      LODWORD(v42) = 0;
      if ( v5 && v5->mUID != UFG::gNullQSymbol.mUID )
      {
        v17 = 0;
        if ( v12->mNumTextureSets )
        {
          v18 = v12->mTextureSets.mOffset;
          v19 = 0i64;
          while ( 1 )
          {
            v20 = (signed __int64)(v18 ? (UFG::qOffset64<UFG::qOffset64<UFG::TrueCrowdTextureSet *> *> *)((char *)&v12->mTextureSets + v18) : 0i64);
            v21 = v19 + v20;
            v22 = *(_QWORD *)(v19 + v20);
            v23 = v22 ? v21 + v22 : 0i64;
            if ( *(_DWORD *)(v23 + 28) == v5->mUID )
              break;
            ++v17;
            v19 += 8i64;
            if ( v17 >= v12->mNumTextureSets )
              goto LABEL_40;
          }
          if ( v18 )
            v24 = (signed __int64)&v12->mTextureSets + v18;
          else
            v24 = 0i64;
          v25 = *(_QWORD *)(v24 + 8i64 * v17);
          if ( v25 )
            v16 = v25 + v24 + 8i64 * v17;
          HIDWORD(v42) = v17;
          v6->mComponentDetails[v10].mTextureSetIndex = v17;
          v6->mComponentDetails[v10].mbTextureSetIndexValid = 1;
        }
      }
      else if ( v12->mNumTextureSets )
      {
        v26 = v12->mTextureSets.mOffset;
        if ( v26 )
          v27 = (__int64 *)((char *)&v12->mTextureSets.mOffset + v26);
        else
          v27 = 0i64;
        if ( *v27 )
          v16 = (signed __int64)v27 + *v27;
        HIDWORD(v42) = 0;
        v6->mComponentDetails[v10].mTextureSetIndex = 0;
        v6->mComponentDetails[v10].mbTextureSetIndexValid = 1;
      }
    }
    else
    {
      LODWORD(v42) = -1;
    }
LABEL_40:
    v28 = v11 != v12;
    if ( v11 && v28 )
      UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(
        (UFG::qArray<UFG::StreamPriorityHandle *,0> *)&v43->mMeshLoader.mTrueCrowdInstance.mSet->mPrev + v39 + 3,
        &item);
    if ( v16 )
    {
      if ( colourTintIndex )
        v29 = *colourTintIndex;
      else
        v29 = 0;
      if ( *(_DWORD *)(v16 + 72) )
      {
        v30 = *(_QWORD *)(v16 + 56);
        if ( v30 )
          v31 = v16 + v30 + 56;
        else
          v31 = 0i64;
        v7 = v31 + 16i64 * v29;
      }
      if ( colourTintIndex )
      {
        v6->mComponentDetails[v10].mbColourTintIndexValid = 1;
        v6->mComponentDetails[v10].mColourTintIndex = v29;
      }
    }
    v32 = v41;
    *(_QWORD *)&v43->mMeshLoader.mTrueCrowdInstance.mPart[v41 / 0x10].mModelIndex = v42;
    *(UFG::qColour **)((char *)&v43->mMeshLoader.mTrueCrowdInstance.mPart[0].mColourTint + v32) = (UFG::qColour *)v7;
    if ( v12 && v28 )
    {
      v33 = &v43->mMeshLoader.mTrueCrowdInstance.mSet->mPrev + 2 * (v39 + 3);
      v34 = *(unsigned int *)v33;
      v35 = *((_DWORD *)v33 + 1);
      v36 = v34 + 1;
      if ( (signed int)v34 + 1 > v35 )
      {
        if ( v35 )
          v37 = 2 * v35;
        else
          v37 = 1;
        for ( ; v37 < v36; v37 *= 2 )
          ;
        if ( v37 <= 2 )
          v37 = 2;
        if ( v37 - v36 > 0x10000 )
          v37 = v34 + 65537;
        UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
          (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&v43->mMeshLoader.mTrueCrowdInstance.mSet->mPrev + v39 + 3,
          v37,
          "qArray.Add");
      }
      v38 = v33[1];
      *(_DWORD *)v33 = v36;
      *((_QWORD *)&v38->mPrev + v34) = v12;
    }
  }
}

// File Line: 1420
// RVA: 0x436660
void __fastcall UFG::AttachmentRecord::AttachmentRecord(UFG::AttachmentRecord *this)
{
  UFG::AttachmentRecord *v1; // rbx

  v1 = this;
  `eh vector constructor iterator(this->mRegularAttachment, 4ui64, 10, (void (__fastcall *)(void *))BackInfo::BackInfo);
  `eh vector constructor iterator(
    v1->mEffectorAttachment,
    0xCui64,
    10,
    (void (__fastcall *)(void *))UFG::EffectorAttachmentInfo::EffectorAttachmentInfo);
  v1->mNumRegularAttachments = 0;
  v1->mNumEffectorAttachments = 0;
}

// File Line: 1424
// RVA: 0x443880
void __fastcall UFG::StreamedResourceComponent::SwapVehicleRig(UFG::SimObject *pUpgradingObject)
{
  UFG::SimObjectGame *v1; // rbp
  unsigned int v2; // er15
  unsigned int v3; // er13
  unsigned __int16 v4; // cx
  UFG::SimComponent *v5; // rax
  UFG::VehicleOccupantComponent *v6; // rbx
  unsigned __int16 v7; // cx
  UFG::SimComponent *v8; // rsi
  UFG::SimComponent *v9; // rax
  UFG::SimObject *v10; // rax
  UFG::SimObjectCVBase *v11; // rdi
  __int64 v12; // r13
  UFG::SimComponent *v13; // rax
  signed __int64 v14; // r12
  UFG::CharacterAnimationComponent *v15; // rax
  unsigned int v16; // esi
  signed __int64 v17; // rbx
  __int64 v18; // rbp
  int v19; // ecx
  _QWORD *v20; // r14
  __int64 v21; // rcx
  signed __int64 v22; // rsi
  __int64 v23; // rbx
  __int64 v24; // rdi
  unsigned int v25; // er12
  int *v26; // rdi
  unsigned int v27; // esi
  UFG::qSymbolUC *v28; // rax
  unsigned int v29; // ebx
  UFG::SimComponent *v30; // rdi
  UFG::SimComponent *v31; // rbx
  UFG::CompositeDrawableComponent *v32; // r12
  unsigned __int16 v33; // cx
  UFG::SimComponent *v34; // rax
  unsigned __int16 v35; // cx
  UFG::SimComponent *v36; // rax
  unsigned __int16 v37; // cx
  UFG::SimComponent *v38; // rax
  unsigned __int16 v39; // cx
  UFG::StreamedResourceComponent *v40; // rax
  UFG::SimComponent *v41; // rsi
  unsigned int v42; // er14
  int *v43; // rdi
  unsigned int v44; // esi
  UFG::qSymbolUC *v45; // rax
  unsigned int v46; // ebx
  UFG::SimComponent *v47; // [rsp+90h] [rbp-7C8h]
  UFG::VehicleOccupantComponent *v48; // [rsp+98h] [rbp-7C0h]
  __int64 v49; // [rsp+A0h] [rbp-7B8h]
  UFG::qWiseSymbol v50; // [rsp+A8h] [rbp-7B0h]
  UFG::qWiseSymbol v51; // [rsp+ACh] [rbp-7ACh]
  __int64 v52; // [rsp+B0h] [rbp-7A8h]
  __int64 ptr; // [rsp+C0h] [rbp-798h]
  __int64 v54; // [rsp+C8h] [rbp-790h]
  int v55; // [rsp+D0h] [rbp-788h]
  int v56[10]; // [rsp+D4h] [rbp-784h]
  int v57; // [rsp+FCh] [rbp-75Ch]
  int v58; // [rsp+100h] [rbp-758h]
  int v59; // [rsp+104h] [rbp-754h]
  int v60[442]; // [rsp+108h] [rbp-750h]
  UFG::SimObject *v61; // [rsp+860h] [rbp+8h]
  UFG::StreamedResourceComponent *v62; // [rsp+868h] [rbp+10h]
  int v63; // [rsp+870h] [rbp+18h]
  UFG::qWiseSymbol result; // [rsp+878h] [rbp+20h]

  v61 = pUpgradingObject;
  v52 = -2i64;
  v1 = (UFG::SimObjectGame *)pUpgradingObject;
  `eh vector constructor iterator(
    &ptr,
    0xB8ui64,
    10,
    (void (__fastcall *)(void *))UFG::AttachmentRecord::AttachmentRecord);
  v2 = 0;
  v3 = 0;
  LODWORD(v62) = 0;
  if ( !v1 )
  {
    v47 = 0i64;
    goto LABEL_46;
  }
  v4 = v1->m_Flags;
  if ( (v4 >> 14) & 1 )
  {
    v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::VehicleOccupantComponent::_TypeUID);
  }
  else
  {
    if ( (v4 & 0x8000u) != 0 )
    {
      v6 = (UFG::VehicleOccupantComponent *)v1->m_Components.p[30].m_pComponent;
      goto LABEL_12;
    }
    if ( (v4 >> 13) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else if ( (v4 >> 12) & 1 )
    {
      v5 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::VehicleOccupantComponent::_TypeUID);
    }
    else
    {
      v5 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::VehicleOccupantComponent::_TypeUID);
    }
  }
  v6 = (UFG::VehicleOccupantComponent *)v5;
LABEL_12:
  v48 = v6;
  v7 = v1->m_Flags;
  if ( (v7 >> 14) & 1 )
  {
    v8 = v1->m_Components.p[9].m_pComponent;
  }
  else if ( (v7 & 0x8000u) == 0 )
  {
    if ( (v7 >> 13) & 1 )
    {
      v8 = v1->m_Components.p[8].m_pComponent;
    }
    else
    {
      if ( (v7 >> 12) & 1 )
        v9 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::BaseAnimationComponent::_TypeUID);
      else
        v9 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::BaseAnimationComponent::_TypeUID);
      v8 = v9;
    }
  }
  else
  {
    v8 = v1->m_Components.p[9].m_pComponent;
  }
  v47 = v8;
  if ( v6 && (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(v6) )
  {
    do
    {
      if ( v3 >= 0xA )
        break;
      v10 = UFG::VehicleOccupantComponent::GetOccupant(v6, v3, 0i64);
      v11 = (UFG::SimObjectCVBase *)v10;
      v12 = *(_QWORD *)&v8[2].m_TypeUID;
      if ( v10 )
        v13 = v10->m_Components.p[9].m_pComponent;
      else
        v13 = 0i64;
      v49 = *(_QWORD *)&v13[2].m_TypeUID;
      v14 = 184i64 * (unsigned int)v62;
      *(&ptr + 23 * (unsigned int)v62) = (__int64)v11;
      if ( v11 )
        v15 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v11);
      else
        v15 = 0i64;
      *(__int64 *)((char *)&v54 + v14) = (__int64)v15;
      v16 = 0;
      v17 = *(_QWORD *)(v12 + 184) - 8i64;
      if ( v17 != v12 + 168 )
      {
        v18 = (unsigned int)v62;
        do
        {
          if ( *(UFG::SimObjectCVBase **)(v17 + 104) == v11 )
            v56[v16++ + 46 * v18] = UFG::qSymbol::qSymbol(
                                      &result,
                                      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v12 + 480) + 24i64)
                                                + 4i64 * *(signed int *)(v17 + 32)))->mUID;
          v17 = *(_QWORD *)(v17 + 16) - 8i64;
        }
        while ( v17 != v12 + 168 );
        v1 = (UFG::SimObjectGame *)v61;
      }
      *(int *)((char *)&v55 + v14) = v16;
      v19 = 0;
      v20 = (_QWORD *)(*(_QWORD *)(v49 + 184) - 8i64);
      if ( v20 != (_QWORD *)(v49 + 168) )
      {
        v21 = v49;
        do
        {
          if ( (UFG::SimObjectGame *)v20[13] == v1 )
          {
            v22 = v14 + 12i64 * v2;
            *(int *)((char *)&v58 + v22) = *(_DWORD *)((*(__int64 (__fastcall **)(_QWORD *))(*v20 + 48i64))(v20) + 44);
            v23 = (*(signed int (__fastcall **)(_QWORD *))(*v20 + 56i64))(v20);
            v24 = (*(signed int (__fastcall **)(_QWORD *))(*v20 + 64i64))(v20);
            *(int *)((char *)&v59 + v22) = UFG::qSymbol::qSymbol(
                                             &v51,
                                             *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v12 + 480) + 24i64) + 4 * v23))->mUID;
            *(int *)((char *)v60 + v22) = UFG::qSymbol::qSymbol(
                                            &v50,
                                            *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v12 + 480) + 24i64) + 4 * v24))->mUID;
            ++v2;
            v21 = v49;
          }
          v20 = (_QWORD *)(v20[2] - 8i64);
        }
        while ( v20 != (_QWORD *)(v21 + 168) );
        v63 = v2;
        v2 = 0;
        v19 = v63;
      }
      *(int *)((char *)&v57 + v14) = v19;
      LODWORD(v62) = (_DWORD)v62 + 1;
      v3 = (unsigned int)v62;
      v6 = v48;
      v8 = v47;
    }
    while ( v3 < (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(v48) );
  }
LABEL_46:
  v25 = 0;
  if ( v3 )
  {
    v26 = &v55;
    do
    {
      v27 = 0;
      if ( *v26 )
      {
        do
        {
          v28 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&v61, qSymbol_SYNC01.mUID);
          UFG::TargetDetach(
            *((UFG::SimObject **)v26 - 2),
            eTARGET_TYPE_VEHICLE,
            0i64,
            v28,
            (UFG::qSymbolUC *)&v56[46i64 * v25 + v27++],
            0.0,
            1,
            0,
            0,
            0,
            1,
            0,
            0.0,
            -1.0,
            0);
        }
        while ( v27 < *v26 );
      }
      v29 = 0;
      if ( v26[11] )
      {
        do
          UFG::TargetDetachEffector(
            *((UFG::SimObject **)v26 - 2),
            *((UFG::CharacterAnimationComponent **)v26 - 1),
            eTARGET_TYPE_VEHICLE,
            (UFG::qSymbolUC *)&v58 + 46 * v25 + 3 * v29++,
            0.0);
        while ( v29 < v26[11] );
      }
      ++v25;
      v26 += 46;
    }
    while ( v25 < v3 );
  }
  if ( v1 )
  {
    v33 = v1->m_Flags;
    if ( (v33 >> 14) & 1 )
    {
      v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RigidBodyComponent::_TypeUID);
    }
    else if ( (v33 & 0x8000u) == 0 )
    {
      if ( (v33 >> 13) & 1 )
      {
        v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RigidBodyComponent::_TypeUID);
      }
      else if ( (v33 >> 12) & 1 )
      {
        v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RigidBodyComponent::_TypeUID);
      }
      else
      {
        v34 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::RigidBodyComponent::_TypeUID);
      }
    }
    else
    {
      v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RigidBodyComponent::_TypeUID);
    }
    v30 = v34;
    v35 = v1->m_Flags;
    if ( (v35 >> 14) & 1 )
    {
      v31 = 0i64;
    }
    else if ( (v35 & 0x8000u) == 0 )
    {
      if ( (v35 >> 13) & 1 )
      {
        v31 = 0i64;
      }
      else
      {
        if ( (v35 >> 12) & 1 )
          v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v36 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::PhysicsMoverInterface::_TypeUID);
        v31 = v36;
      }
    }
    else
    {
      v31 = v1->m_Components.p[34].m_pComponent;
    }
    v37 = v1->m_Flags;
    if ( (v37 >> 14) & 1 )
    {
      v32 = (UFG::CompositeDrawableComponent *)v1->m_Components.p[14].m_pComponent;
    }
    else if ( (v37 & 0x8000u) == 0 )
    {
      if ( (v37 >> 13) & 1 )
      {
        v32 = (UFG::CompositeDrawableComponent *)v1->m_Components.p[9].m_pComponent;
      }
      else
      {
        if ( (v37 >> 12) & 1 )
          v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::CompositeDrawableComponent::_TypeUID);
        else
          v38 = UFG::SimObject::GetComponentOfType(
                  (UFG::SimObject *)&v1->vfptr,
                  UFG::CompositeDrawableComponent::_TypeUID);
        v32 = (UFG::CompositeDrawableComponent *)v38;
      }
    }
    else
    {
      v32 = (UFG::CompositeDrawableComponent *)v1->m_Components.p[14].m_pComponent;
    }
    v39 = v1->m_Flags;
    if ( (v39 >> 14) & 1 )
    {
      v40 = (UFG::StreamedResourceComponent *)v1->m_Components.p[10].m_pComponent;
    }
    else if ( (v39 & 0x8000u) == 0 )
    {
      if ( (v39 >> 13) & 1 )
      {
        v40 = (UFG::StreamedResourceComponent *)v1->m_Components.p[7].m_pComponent;
      }
      else if ( (v39 >> 12) & 1 )
      {
        v40 = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v1,
                                                  UFG::StreamedResourceComponent::_TypeUID);
      }
      else
      {
        v40 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                  (UFG::SimObject *)&v1->vfptr,
                                                  UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      v40 = (UFG::StreamedResourceComponent *)v1->m_Components.p[10].m_pComponent;
    }
    v62 = v40;
  }
  else
  {
    v30 = 0i64;
    v31 = 0i64;
    v32 = 0i64;
    v62 = 0i64;
  }
  v41 = v47;
  if ( v47 )
    ((void (__fastcall *)(UFG::SimComponent *))v47->vfptr[17].__vecDelDtor)(v47);
  if ( v32 )
    UFG::CompositeDrawableComponent::ResetModelType(v32);
  if ( v30 )
  {
    ((void (__fastcall *)(UFG::SimComponent *))v30->vfptr[10].__vecDelDtor)(v30);
    v30->vfptr[6].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v30->vfptr, (unsigned int)v1);
  }
  if ( v31 )
  {
    ((void (__fastcall *)(UFG::SimComponent *))v31->vfptr[10].__vecDelDtor)(v31);
    v31->vfptr[6].__vecDelDtor((UFG::qSafePointerNode<UFG::SimComponent> *)&v31->vfptr, (unsigned int)v1);
  }
  v42 = 0;
  if ( v3 )
  {
    v43 = &v55;
    do
    {
      v44 = 0;
      if ( *v43 )
      {
        do
        {
          v45 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&v61, qSymbol_SYNC01.mUID);
          UFG::TargetAttach(
            *((UFG::SimObject **)v43 - 2),
            eTARGET_TYPE_VEHICLE,
            0i64,
            0i64,
            v45,
            (UFG::qSymbolUC *)&v56[46i64 * v42 + v44++],
            0.0,
            0,
            -1.0,
            1,
            0,
            0,
            eTARGET_TYPE_EQUIPPED,
            0,
            0,
            0,
            0i64);
        }
        while ( v44 < *v43 );
      }
      v46 = 0;
      if ( v43[11] )
      {
        do
        {
          UFG::TargetAttachEffector(
            *((UFG::SimObject **)v43 - 2),
            *((UFG::CharacterAnimationComponent **)v43 - 1),
            eTARGET_TYPE_VEHICLE,
            (UFG::qSymbolUC *)&v58 + 46 * v42 + 3 * v46,
            (UFG::qSymbolUC *)&v59 + 46 * v42 + 3 * v46,
            (UFG::qSymbolUC *)&v60[46 * v42 + 3 * v46],
            0.0,
            0);
          ++v46;
        }
        while ( v46 < v43[11] );
      }
      ++v42;
      v43 += 46;
    }
    while ( v42 < v3 );
    v41 = v47;
  }
  if ( BYTE1(v41[3].vfptr) || !*(_QWORD *)&v41[1].m_Flags )
    LOBYTE(v2) = 1;
  UFG::StreamedResourceComponent::BindAllModels(v62, v32, v2);
  `eh vector destructor iterator(
    &ptr,
    0xB8ui64,
    10,
    (void (__fastcall *)(void *))UFG::AttachmentRecord::~AttachmentRecord);
}

// File Line: 1585
// RVA: 0x43D930
UFG::ComponentIDDesc *__fastcall UFG::ResourcePriorityLockComponent::GetDesc(UFG::ResourcePriorityLockComponent *this)
{
  return &UFG::ResourcePriorityLockComponent::_TypeIDesc;
}

// File Line: 1589
// RVA: 0x437230
void __fastcall UFG::ResourcePriorityLockComponent::ResourcePriorityLockComponent(UFG::ResourcePriorityLockComponent *this)
{
  UFG::ResourcePriorityLockComponent *v1; // rbx
  unsigned int v2; // eax

  v1 = this;
  v2 = UFG::qStringHash32("ResourcePriorityLockComponent", 0xFFFFFFFF);
  UFG::SimComponent::SimComponent((UFG::SimComponent *)&v1->vfptr, v2);
  v1->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ResourcePriorityLockComponent::`vftable;
  UFG::SimComponent::AddType(
    (UFG::SimComponent *)&v1->vfptr,
    UFG::ResourcePriorityLockComponent::_ResourcePriorityLockComponentTypeUID,
    "ResourcePriorityLockComponent");
}

// File Line: 1594
// RVA: 0x43F5F0
void __fastcall UFG::ResourcePriorityLockComponent::OnAttach(UFG::ResourcePriorityLockComponent *this, UFG::SimObject *object)
{
  unsigned __int16 v2; // cx
  UFG::StreamedResourceComponent *v3; // r9
  UFG::SimComponent *v4; // rax
  __int64 v5; // rdx
  UFG::qSymbol **v6; // r8

  if ( object )
  {
    v2 = object->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::StreamedResourceComponent *)object->m_Components.p[10].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = (UFG::StreamedResourceComponent *)object->m_Components.p[7].m_pComponent;
      }
      else
      {
        v4 = (v2 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                (UFG::SimObjectGame *)object,
                                UFG::StreamedResourceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                              object,
                                                                              UFG::StreamedResourceComponent::_TypeUID);
        v3 = (UFG::StreamedResourceComponent *)v4;
      }
    }
    else
    {
      v3 = (UFG::StreamedResourceComponent *)object->m_Components.p[10].m_pComponent;
    }
    if ( v3 )
    {
      v5 = 0i64;
      v6 = UFG::StreamedResourceComponent::sSpawnPrioritySymbols;
      while ( qSymbol_Critical.mUID != (*v6)->mUID )
      {
        v5 = (unsigned int)(v5 + 1);
        ++v6;
        if ( (unsigned int)v5 >= 4 )
          return;
      }
      if ( (unsigned int)v5 < 4 )
      {
        ++v3->mSpawnPriorityReferenceCount[v5];
        UFG::StreamedResourceComponent::UpdateActivePriority(v3);
      }
    }
  }
}

// File Line: 1603
// RVA: 0x43F8F0
void __fastcall UFG::ResourcePriorityLockComponent::OnDetach(UFG::ResourcePriorityLockComponent *this)
{
  UFG::SimObjectGame *v1; // rcx
  unsigned __int16 v2; // dx
  UFG::StreamedResourceComponent *v3; // r9
  UFG::SimComponent *v4; // rax
  __int64 v5; // rdx
  UFG::qSymbol **v6; // r8
  signed __int64 v7; // rcx
  int v8; // eax

  v1 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v1 )
  {
    v2 = v1->m_Flags;
    if ( (v2 >> 14) & 1 )
    {
      v3 = (UFG::StreamedResourceComponent *)v1->m_Components.p[10].m_pComponent;
    }
    else if ( (v2 & 0x8000u) == 0 )
    {
      if ( (v2 >> 13) & 1 )
      {
        v3 = (UFG::StreamedResourceComponent *)v1->m_Components.p[7].m_pComponent;
      }
      else
      {
        v4 = (v2 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::StreamedResourceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v1->vfptr, UFG::StreamedResourceComponent::_TypeUID);
        v3 = (UFG::StreamedResourceComponent *)v4;
      }
    }
    else
    {
      v3 = (UFG::StreamedResourceComponent *)v1->m_Components.p[10].m_pComponent;
    }
    if ( v3 )
    {
      v5 = 0i64;
      v6 = UFG::StreamedResourceComponent::sSpawnPrioritySymbols;
      while ( qSymbol_Critical.mUID != (*v6)->mUID )
      {
        v5 = (unsigned int)(v5 + 1);
        ++v6;
        if ( (unsigned int)v5 >= 4 )
          return;
      }
      if ( (unsigned int)v5 < 4 )
      {
        v7 = (signed __int64)v3 + 4 * v5;
        v8 = *(_DWORD *)(v7 + 1560);
        if ( v8 )
        {
          *(_DWORD *)(v7 + 1560) = v8 - 1;
          UFG::StreamedResourceComponent::UpdateActivePriority(v3);
        }
      }
    }
  }
}

