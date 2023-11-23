// File Line: 58
// RVA: 0x150EB60
__int64 dynamic_initializer_for__UFG::StreamedResourceComponent::s_StreamedResourceComponentList__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StreamedResourceComponent::s_StreamedResourceComponentList__);
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
  UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent = 0i64;
  UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimObject = 0i64;
  UFG::StreamedResourceComponent::spPlayerTransformNode.m_Changed = 1;
  UFG::StreamedResourceComponent::spPlayerTransformNode.m_TypeUID = UFG::TransformNodeComponent::_TypeUID;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::StreamedResourceComponent::spPlayerTransformNode__);
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
void __fastcall UFG::StreamedResourceComponent::StreamedResourceComponent(
        UFG::StreamedResourceComponent *this,
        UFG::SceneObjectProperties *pSceneObj)
{
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *mPrev; // rax
  UFG::qPropertySet *mpWritableProperties; // rax
  unsigned int mUID; // eax
  UFG::qSymbol *p_m_Name; // rbx
  NISManager *Instance; // rax
  bool v9; // bl
  bool v10; // r14
  UFG::qPropertySet *v11; // rax
  component_StreamedResource *MemImagePtr; // rbp
  __int64 mOffset; // rax
  char *v14; // rcx
  unsigned int v15; // r15d
  UFG::qColour *mColourTints; // rcx
  __int64 v17; // rdx
  UFG::TrueCrowdSet::Instance *p_mTrueCrowdInstance; // r8
  UFG::qPropertySet *mPropertySet; // rdx
  __int64 v20; // rax
  UFG::qPropertyList *v21; // r14
  unsigned int i; // edi
  __int64 v23; // rax
  UFG::qPropertyList *v24; // rcx
  const char *v25; // rbx
  UFG::PartDatabase *v26; // rax
  UFG::PartDefinition *PartByName; // rax
  UFG::PartDefinition *v28; // rbx
  unsigned int mNumItems; // r8d
  unsigned int v30; // edx
  UFG::qSymbolUC textureSet; // [rsp+78h] [rbp+10h] BYREF
  UFG::qSymbolUC *p_textureSet; // [rsp+80h] [rbp+18h]

  UFG::SimComponent::SimComponent(this, hash_src);
  this->mPrev = &this->UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent>;
  this->mNext = &this->UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent>;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StreamedResourceComponent::`vftable;
  this->mUseMeshLoader = 1;
  UFG::MeshResourceLoader::MeshResourceLoader(&this->mMeshLoader);
  this->mResourcesBound = 0;
  UFG::PartLoader::PartLoader(&this->mPartLoader);
  this->mPartsBound = 0;
  this->mActivePriority = UFG::gNullQSymbol;
  this->mPropertySet = 0i64;
  this->mCameraDistance = 3.4028235e38;
  mPrev = UFG::StreamedResourceComponent::s_StreamedResourceComponentList.mNode.mPrev;
  UFG::StreamedResourceComponent::s_StreamedResourceComponentList.mNode.mPrev->mNext = &this->UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent>;
  this->mPrev = mPrev;
  this->mNext = (UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *)&UFG::StreamedResourceComponent::s_StreamedResourceComponentList;
  UFG::StreamedResourceComponent::s_StreamedResourceComponentList.mNode.mPrev = &this->UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent>;
  UFG::SimComponent::AddType(
    this,
    UFG::StreamedResourceComponent::_StreamedResourceComponentTypeUID,
    "StreamedResourceComponent");
  this->mFirstResourceLoad = 0;
  mpWritableProperties = pSceneObj->mpWritableProperties;
  if ( !mpWritableProperties )
    mpWritableProperties = pSceneObj->mpConstProperties;
  this->mPropertySet = mpWritableProperties;
  this->mSimObjectType = UFG::SimObjectPropertiesComponent::GetChildType(pSceneObj);
  UFG::StreamedResourceComponent::InitPriorityInfo(this, this->mPropertySet);
  mUID = this->mActivePriority.mUID;
  v9 = 0;
  if ( mUID == qSymbol_Reserved.mUID || mUID == qSymbol_Critical.mUID )
  {
    p_m_Name = &pSceneObj->m_pSimObject->m_Name;
    Instance = NISManager::GetInstance();
    if ( NISManager::UseHighDefModel(Instance, p_m_Name) )
      v9 = 1;
  }
  v10 = this->mActivePriority.mUID != qSymbol_Low.mUID;
  v11 = UFG::qPropertySet::Get<UFG::qPropertySet>(
          this->mPropertySet,
          (UFG::qArray<unsigned long,0> *)&component_StreamedResource::sPropertyName,
          DEPTH_RECURSE);
  if ( v11 )
    MemImagePtr = (component_StreamedResource *)UFG::qPropertySet::GetMemImagePtr(v11);
  else
    MemImagePtr = 0i64;
  mOffset = MemImagePtr->PartList.mOffset;
  if ( mOffset )
    v14 = (char *)&MemImagePtr->PartList + mOffset;
  else
    v14 = 0i64;
  v15 = *((_DWORD *)v14 + 10);
  mColourTints = this->mColourTints;
  v17 = 16i64;
  do
  {
    *mColourTints++ = UFG::qColour::White;
    --v17;
  }
  while ( v17 );
  if ( v15 )
  {
    this->mUseMeshLoader = 0;
  }
  else
  {
    p_textureSet = &textureSet;
    textureSet.mUID = this->mActivePriority.mUID;
    this->mMeshLoader.mPropertySet = this->mPropertySet;
    this->mMeshLoader.mActivePriority.mUID = textureSet.mUID;
    this->mMeshLoader.mHighDefinition = v9;
    this->mMeshLoader.mTrueCrowdInstance.mSet = 0i64;
    this->mMeshLoader.mTrueCrowdInstance.mNumParts = 0;
    p_mTrueCrowdInstance = &this->mMeshLoader.mTrueCrowdInstance;
    mPropertySet = this->mMeshLoader.mPropertySet;
    if ( v10 )
      UFG::TrueCrowdDataBase::QueryInstance(
        UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
        mPropertySet,
        p_mTrueCrowdInstance);
    else
      UFG::TrueCrowdDataBase::QueryPreloadedInstance(
        UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
        mPropertySet,
        p_mTrueCrowdInstance);
  }
  this->mMeshLoader.mOnLoadEventCallback = UFG::StreamedResourceComponent::OnLoadEventCallback;
  this->mMeshLoader.mOnForceRemovedCallback = (void (__fastcall *)(void *, UFG::ResourceRequest *))UFG::StreamedResourceComponent::OnPartForceRemovedCallback;
  this->mMeshLoader.mUserContext = this;
  UFG::PartLoader::SetCallbacks(
    &this->mPartLoader,
    UFG::StreamedResourceComponent::OnPartLoadEventCallback,
    UFG::StreamedResourceComponent::OnPartForceRemovedCallback,
    this);
  v20 = MemImagePtr->TextureSetList.mOffset;
  if ( v20 )
    v21 = (UFG::qPropertyList *)((char *)&MemImagePtr->TextureSetList + v20);
  else
    v21 = 0i64;
  for ( i = 0; i < v15; ++i )
  {
    v23 = MemImagePtr->PartList.mOffset;
    if ( v23 )
      v24 = (UFG::qPropertyList *)((char *)&MemImagePtr->PartList + v23);
    else
      v24 = 0i64;
    v25 = UFG::qPropertyList::Get<char const *>(v24, i);
    v26 = UFG::PartDatabase::Instance();
    PartByName = UFG::PartDatabase::GetPartByName(v26, v25);
    v28 = PartByName;
    if ( PartByName )
    {
      textureSet.mUID = UFG::gNullQSymbolUC.mUID;
      mNumItems = PartByName->mTextureAlternates.mData.mNumItems;
      if ( mNumItems )
      {
        if ( i >= v21->mNumElements )
        {
          v30 = tex_variety++ % mNumItems;
          textureSet.mUID = PartByName->mTextureAlternates.mData.mItems[v30].mId.mUID;
        }
        else
        {
          textureSet.mUID = UFG::qPropertyList::Get<UFG::qSymbolUC>(v21, i)->mUID;
        }
      }
      UFG::PartLoader::AddPart(&this->mPartLoader, v28, &textureSet);
    }
  }
}

// File Line: 155
// RVA: 0x443200
void __fastcall UFG::StreamedResourceComponent::SetResourceSignature(
        UFG::StreamedResourceComponent *this,
        UFG::TrueCrowdSet::Instance *signature)
{
  UFG::TrueCrowdSet::Instance *p_mTrueCrowdInstance; // rcx
  __int64 v3; // rax
  UFG::ModelTextureCombination v4; // xmm0

  p_mTrueCrowdInstance = &this->mMeshLoader.mTrueCrowdInstance;
  if ( (((unsigned __int8)p_mTrueCrowdInstance | (unsigned __int8)signature) & 0xF) != 0 )
  {
    memmove(p_mTrueCrowdInstance, signature, 0x118ui64);
  }
  else
  {
    v3 = 2i64;
    do
    {
      v4 = *(UFG::ModelTextureCombination *)&signature->mSet;
      p_mTrueCrowdInstance = (UFG::TrueCrowdSet::Instance *)((char *)p_mTrueCrowdInstance + 128);
      signature = (UFG::TrueCrowdSet::Instance *)((char *)signature + 128);
      p_mTrueCrowdInstance[-1].mPart[8] = v4;
      p_mTrueCrowdInstance[-1].mPart[9] = signature[-1].mPart[9];
      p_mTrueCrowdInstance[-1].mPart[10] = signature[-1].mPart[10];
      p_mTrueCrowdInstance[-1].mPart[11] = signature[-1].mPart[11];
      p_mTrueCrowdInstance[-1].mPart[12] = signature[-1].mPart[12];
      p_mTrueCrowdInstance[-1].mPart[13] = signature[-1].mPart[13];
      p_mTrueCrowdInstance[-1].mPart[14] = signature[-1].mPart[14];
      p_mTrueCrowdInstance[-1].mPart[15] = signature[-1].mPart[15];
      --v3;
    }
    while ( v3 );
    *(_OWORD *)&p_mTrueCrowdInstance->mSet = *(_OWORD *)&signature->mSet;
    *(_QWORD *)&p_mTrueCrowdInstance->mMorphWeights[1] = *(_QWORD *)&signature->mMorphWeights[1];
  }
}

// File Line: 160
// RVA: 0x43EFD0
void __fastcall UFG::StreamedResourceComponent::InitPriorityInfo(
        UFG::StreamedResourceComponent *this,
        UFG::qPropertySet *propertySet)
{
  int v2; // ebx
  UFG::qSymbol *v4; // rax
  UFG::qSymbol *v5; // rdx
  unsigned int mUID; // eax
  UFG::qSymbol **i; // rdx

  v2 = 0;
  *(_QWORD *)this->mSpawnPriorityReferenceCount = 0i64;
  *(_QWORD *)&this->mSpawnPriorityReferenceCount[2] = 0i64;
  v4 = UFG::qPropertySet::Get<UFG::qSymbol>(
         propertySet,
         (UFG::qArray<unsigned long,0> *)&qSymbol_SpawnPriority,
         DEPTH_RECURSE);
  v5 = &UFG::gNullQSymbol;
  if ( v4 )
    v5 = v4;
  mUID = v5->mUID;
  if ( v5->mUID == UFG::gNullQSymbol.mUID )
  {
    this->mActivePriority.mUID = qSymbol_Critical.mUID;
    ++this->mSpawnPriorityReferenceCount[0];
  }
  else
  {
    this->mActivePriority.mUID = mUID;
    for ( i = UFG::StreamedResourceComponent::sSpawnPrioritySymbols; mUID != (*i)->mUID; ++i )
    {
      if ( (unsigned int)++v2 >= 4 )
      {
        this->mActivePriority = UFG::gNullQSymbol;
        return;
      }
    }
    ++this->mSpawnPriorityReferenceCount[v2];
  }
}

// File Line: 190
// RVA: 0x438000
void __fastcall UFG::StreamedResourceComponent::~StreamedResourceComponent(UFG::StreamedResourceComponent *this)
{
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *v2; // rbx
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *mPrev; // rcx
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *mNext; // rax
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *v5; // rcx
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *v6; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StreamedResourceComponent::`vftable;
  if ( this == UFG::StreamedResourceComponent::s_StreamedResourceComponentpCurrentIterator )
    UFG::StreamedResourceComponent::s_StreamedResourceComponentpCurrentIterator = (UFG::StreamedResourceComponent *)&this->mPrev[-4];
  v2 = &this->UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent>;
  mPrev = this->mPrev;
  mNext = v2->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::PartLoader::~PartLoader(&this->mPartLoader);
  UFG::MeshResourceLoader::Unload(&this->mMeshLoader);
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = v2;
  v2->mNext = v2;
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 195
// RVA: 0x442D40
void __fastcall UFG::StreamedResourceComponent::ResetPropertyPtr(UFG::StreamedResourceComponent *this)
{
  UFG::SimObject *m_pSimObject; // rbx
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rbp
  unsigned int mUID; // eax
  NISManager *Instance; // rax
  bool v7; // r14
  UFG::TrueCrowdSet::Instance *p_mTrueCrowdInstance; // r8
  UFG::qPropertySet *mPropertySet; // rdx
  unsigned int v10; // [rsp+50h] [rbp+8h] BYREF
  unsigned int *v11; // [rsp+58h] [rbp+10h]

  if ( this->mUseMeshLoader )
  {
    m_pSimObject = this->m_pSimObject;
    if ( m_pSimObject )
      m_pSceneObj = m_pSimObject->m_pSceneObj;
    else
      m_pSceneObj = 0i64;
    mpWritableProperties = m_pSceneObj->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = m_pSceneObj->mpConstProperties;
    if ( this->mPropertySet != mpWritableProperties )
    {
      mUID = this->mActivePriority.mUID;
      v7 = 0;
      if ( mUID == qSymbol_Reserved.mUID || mUID == qSymbol_Critical.mUID )
      {
        Instance = NISManager::GetInstance();
        if ( NISManager::UseHighDefModel(Instance, &m_pSimObject->m_Name) )
          v7 = 1;
      }
      this->mPropertySet = mpWritableProperties;
      UFG::MeshResourceLoader::Unload(&this->mMeshLoader);
      v11 = &v10;
      v10 = this->mActivePriority.mUID;
      this->mMeshLoader.mPropertySet = this->mPropertySet;
      this->mMeshLoader.mActivePriority.mUID = v10;
      this->mMeshLoader.mHighDefinition = v7;
      p_mTrueCrowdInstance = &this->mMeshLoader.mTrueCrowdInstance;
      this->mMeshLoader.mTrueCrowdInstance.mSet = 0i64;
      this->mMeshLoader.mTrueCrowdInstance.mNumParts = 0;
      mPropertySet = this->mMeshLoader.mPropertySet;
      if ( this->mActivePriority.mUID == qSymbol_Low.mUID )
        UFG::TrueCrowdDataBase::QueryPreloadedInstance(
          UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
          mPropertySet,
          p_mTrueCrowdInstance);
      else
        UFG::TrueCrowdDataBase::QueryInstance(
          UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
          mPropertySet,
          p_mTrueCrowdInstance);
    }
  }
  else
  {
    UFG::MeshResourceLoader::Unload(&this->mMeshLoader);
    if ( this->mMeshLoader.mPropertySet )
    {
      this->mMeshLoader.mPropertySet = 0i64;
      this->mMeshLoader.mTrueCrowdInstance.mSet = 0i64;
      this->mMeshLoader.mTrueCrowdInstance.mNumParts = 0;
    }
    this->mPropertySet = 0i64;
  }
}

// File Line: 217
// RVA: 0x43A790
void __fastcall UFG::StreamedResourceComponent::ClearResources(UFG::StreamedResourceComponent *this)
{
  UFG::MeshResourceLoader::Unload(&this->mMeshLoader);
  UFG::PartLoader::Unload(&this->mPartLoader);
}

// File Line: 223
// RVA: 0x442E90
void __fastcall UFG::StreamedResourceComponent::ResetResources(UFG::StreamedResourceComponent *this)
{
  UFG::PartLoader::Reset(&this->mPartLoader);
}

// File Line: 237
// RVA: 0x4385F0
void __fastcall UFG::StreamedResourceComponent::AddPart(
        UFG::StreamedResourceComponent *this,
        UFG::PartDefinition *part,
        UFG::qSymbolUC *textureSet)
{
  UFG::PartLoader::AddPart(&this->mPartLoader, part, textureSet);
}

// File Line: 247
// RVA: 0x43FEA0
UFG::SimComponent *__fastcall UFG::StreamedResourceComponent::PropertiesOnActivateNew(
        UFG::SceneObjectProperties *sceneObject,
        bool required)
{
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v4; // rax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::SimComponent *v8; // rax
  UFG::SimComponent *v9; // rdi
  UFG::SimObject *m_pSimObject; // rdx
  __int16 m_Flags; // cx
  unsigned int v12; // ebx
  UFG::SimObjectModifier v13; // [rsp+38h] [rbp-30h] BYREF

  if ( !required )
  {
    mpWritableProperties = sceneObject->mpWritableProperties;
    if ( !mpWritableProperties )
      mpWritableProperties = sceneObject->mpConstProperties;
    v4 = UFG::qPropertySet::Get<UFG::qPropertySet>(
           mpWritableProperties,
           (UFG::qArray<unsigned long,0> *)&component_StreamedResource::sPropertyName,
           DEPTH_RECURSE);
    if ( !v4 || !UFG::qPropertySet::GetMemImagePtr(v4) )
      return 0i64;
  }
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v7 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x630ui64, "StreamedResourceComponent", 0i64, 1u);
  if ( v7 )
  {
    UFG::StreamedResourceComponent::StreamedResourceComponent((UFG::StreamedResourceComponent *)v7, sceneObject);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  m_pSimObject = sceneObject->m_pSimObject;
  m_Flags = m_pSimObject->m_Flags;
  if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 )
  {
    v12 = 10;
  }
  else if ( (m_Flags & 0x2000) != 0 )
  {
    v12 = 7;
  }
  else
  {
    v12 = -1;
  }
  UFG::SimObjectModifier::SimObjectModifier(&v13, m_pSimObject, 1);
  UFG::SimObjectModifier::AttachComponent(&v13, v9, v12);
  UFG::SimObjectModifier::Close(&v13);
  UFG::SimObjectModifier::~SimObjectModifier(&v13);
  return v9;
}

// File Line: 264
// RVA: 0x43F6C0
void __fastcall UFG::StreamedResourceComponent::OnAttach(
        UFG::StreamedResourceComponent *this,
        UFG::SimObjectGame *object)
{
  UFG::SimComponent *m_pSimComponent; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbp
  float x; // xmm7_4
  __m128 mPrev_high; // xmm6
  float z; // xmm8_4
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  UFG::BaseCameraComponent *p_mCamera; // rax
  UFG::SimObject *m_pSimObject; // rax
  signed __int16 m_Flags; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  signed __int16 v14; // cx
  UFG::SimComponent *v15; // rdi
  UFG::CompositeDrawableComponent *m_pComponent; // rax

  m_pSimComponent = UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent;
  m_pTransformNodeComponent = 0i64;
  if ( UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent);
    x = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
    mPrev_high = (__m128)HIDWORD(m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev);
    z = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
  }
  else
  {
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      p_mCamera = (UFG::BaseCameraComponent *)&mCurrentCamera->mCamera;
    else
      p_mCamera = 0i64;
    x = p_mCamera->mCamera.mView.v2.x;
    mPrev_high = (__m128)LODWORD(p_mCamera->mCamera.mView.v2.y);
    z = p_mCamera->mCamera.mView.v2.z;
  }
  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  mPrev_high.m128_f32[0] = (float)((float)((float)(mPrev_high.m128_f32[0]
                                                 - m_pTransformNodeComponent->mWorldTransform.v3.y)
                                         * (float)(mPrev_high.m128_f32[0]
                                                 - m_pTransformNodeComponent->mWorldTransform.v3.y))
                                 + (float)((float)(x - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                         * (float)(x - m_pTransformNodeComponent->mWorldTransform.v3.x)))
                         + (float)((float)(z - m_pTransformNodeComponent->mWorldTransform.v3.z)
                                 * (float)(z - m_pTransformNodeComponent->mWorldTransform.v3.z));
  LODWORD(this->mCameraDistance) = _mm_sqrt_ps(mPrev_high).m128_u32[0];
  UFG::StreamedResourceComponent::UpdateLoadState(this, object);
  if ( object )
  {
    m_Flags = object->m_Flags;
    if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
      ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(object, UFG::CompositeLookComponent::_TypeUID);
    else
      ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(object, UFG::CompositeLookComponent::_TypeUID);
    v14 = object->m_Flags;
    v15 = ComponentOfTypeHK;
    if ( (v14 & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CompositeDrawableComponent *)object->m_Components.p[14].m_pComponent;
    }
    else if ( v14 >= 0 )
    {
      if ( (v14 & 0x2000) != 0 )
      {
        m_pComponent = (UFG::CompositeDrawableComponent *)object->m_Components.p[9].m_pComponent;
      }
      else if ( (v14 & 0x1000) != 0 )
      {
        m_pComponent = (UFG::CompositeDrawableComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                            object,
                                                            UFG::CompositeDrawableComponent::_TypeUID);
      }
      else
      {
        m_pComponent = (UFG::CompositeDrawableComponent *)UFG::SimObject::GetComponentOfType(
                                                            object,
                                                            UFG::CompositeDrawableComponent::_TypeUID);
      }
    }
    else
    {
      m_pComponent = (UFG::CompositeDrawableComponent *)object->m_Components.p[14].m_pComponent;
    }
    if ( m_pComponent && m_pComponent != (UFG::CompositeDrawableComponent *)-112i64 )
      UFG::StreamedResourceComponent::UpdateMaterialModifiers(this, &m_pComponent->mMaterialModifier);
    if ( v15 )
      *(_QWORD *)&v15[1].m_Flags = this->mColourTints;
  }
  if ( !UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent )
  {
    if ( LocalPlayer )
      UFG::RebindingComponentHandle<UFG::TransformNodeComponent,0>::Bind<UFG::SimObject>(
        &UFG::StreamedResourceComponent::spPlayerTransformNode,
        LocalPlayer);
  }
}

// File Line: 304
// RVA: 0x446220
void __fastcall UFG::StreamedResourceComponent::UpdateMaterialModifiers(
        UFG::StreamedResourceComponent *this,
        Illusion::MaterialModifierParams<10> *material_modifier)
{
  unsigned int v2; // r15d
  UFG::StreamedResourceComponent *v4; // rdx
  unsigned int i; // r12d
  __int64 v6; // rbx
  UFG::TrueCrowdModel *v7; // r8
  __int64 mOffset; // rax
  UFG::TrueCrowdModel *v9; // rax
  unsigned int v10; // ebp
  UFG::TrueCrowdTextureSet *Texture; // r13
  __int64 v12; // rcx
  char *v13; // rdx
  __int64 v14; // rdi
  unsigned int *v15; // rsi
  unsigned int *v16; // rbx
  unsigned int v17; // edx
  unsigned int v18; // r8d
  Illusion::ParamOverride *v19; // rcx
  UFG::qColour *v20; // rcx
  unsigned int mPartCount; // esi
  UFG::PartLoader *p_mPartLoader; // rdi
  UFG::PartDefinition *Part; // rbx
  UFG::qSymbolUC *PartTextureSet; // rax
  unsigned int original_name_uid; // [rsp+20h] [rbp-48h]
  __int64 v27; // [rsp+80h] [rbp+18h]

  v2 = 0;
  material_modifier->mNumOverrides = 0;
  v4 = this;
  for ( i = 0; i < v4->mMeshLoader.mTrueCrowdInstance.mNumParts; ++i )
  {
    v6 = i;
    v27 = (__int64)&v4->mMeshLoader.mTrueCrowdInstance.mPart[v6];
    if ( *(_DWORD *)v27 != -1 )
    {
      v7 = v4->mMeshLoader.mTrueCrowdInstance.mSet->mFiles[v6].p[v4->mMeshLoader.mTrueCrowdInstance.mPart[i].mModelIndex];
      if ( v4->mMeshLoader.mHighDefinition )
      {
        mOffset = v7->mHighResolutionResource.mOffset;
        if ( mOffset )
        {
          v9 = (UFG::TrueCrowdModel *)((char *)&v7->mHighResolutionResource + mOffset);
          if ( v9 )
            v7 = v9;
        }
      }
      if ( v7->mNumTextureSets )
      {
        v10 = 0;
        Texture = UFG::MeshResourceLoader::GetTexture(&v4->mMeshLoader, i);
        if ( Texture->mNumTextureOverrideParams )
        {
          do
          {
            v12 = Texture->mTextureOverrideParams.mOffset;
            if ( v12 )
              v13 = (char *)&Texture->mTextureOverrideParams + v12;
            else
              v13 = 0i64;
            v14 = 3i64;
            v15 = (unsigned int *)&v13[24 * v10];
            v16 = v15 + 2;
            do
            {
              if ( *v16 )
              {
                v17 = *v15;
                v18 = v15[1];
                original_name_uid = *v16;
                v19 = &material_modifier->mOverrides[material_modifier->mNumOverrides++];
                Illusion::ParamOverride::SetTextureOverride(v19, v17, v18, OVERRIDE_EQUALS, original_name_uid);
              }
              ++v16;
              --v14;
            }
            while ( v14 );
            ++v10;
          }
          while ( v10 < Texture->mNumTextureOverrideParams );
          v6 = i;
        }
      }
      v4 = this;
      v20 = &UFG::qColour::White;
      if ( *(_QWORD *)(v27 + 8) )
        v20 = *(UFG::qColour **)(v27 + 8);
      this->mColourTints[v6].r = v20->r;
      this->mColourTints[v6].g = v20->g;
      this->mColourTints[v6].b = v20->b;
      this->mColourTints[v6].a = v20->a;
    }
  }
  mPartCount = v4->mPartLoader.mPartCount;
  if ( mPartCount )
  {
    p_mPartLoader = &v4->mPartLoader;
    do
    {
      Part = UFG::PartLoader::GetPart(p_mPartLoader, v2);
      if ( Part )
      {
        PartTextureSet = UFG::PartLoader::GetPartTextureSet(p_mPartLoader, v2);
        UFG::StreamedResourceComponent::ApplyTextureOverrideForPart(this, material_modifier, Part, PartTextureSet);
      }
      ++v2;
    }
    while ( v2 < mPartCount );
  }
}

// File Line: 349
// RVA: 0x446430
void __fastcall UFG::StreamedResourceComponent::UpdateMaterialModifiers(
        UFG::StreamedResourceComponent *this,
        Illusion::MaterialModifierParams<10> *material_modifier,
        UFG::PartTemplateInstance *partInstance)
{
  unsigned int mNumItems; // eax
  __int64 v6; // r13
  __int64 v7; // r12
  UFG::PartTemplateInstance::SlotEntry *v8; // rbx
  UFG::PartDefinition *mData; // r14
  UFG::PartDefinition::TextureAlternate *TextureAlternate; // rax
  UFG::PartDefinition::TextureAlternate *v11; // rsi
  unsigned int v12; // edi
  __int64 v13; // rbx
  unsigned __int16 Param; // ax
  __int64 mNumOverrides; // r10
  int v16; // edx
  int v17; // eax
  Illusion::ParamOverride *mOverrides; // rcx
  unsigned int v19; // edx
  unsigned int v20; // r8d
  unsigned int v21; // r8d
  unsigned int v22; // ebx
  unsigned int v23; // edx
  __int64 v24; // rsi
  UFG::qColour *mItems; // rcx
  _DWORD *v26; // r8
  unsigned int original_name_uid; // [rsp+20h] [rbp-38h]
  UFG::PartTemplateInstance *v28; // [rsp+70h] [rbp+18h]

  v28 = partInstance;
  mNumItems = partInstance->mSlots.mData.mNumItems;
  if ( mNumItems )
  {
    v6 = mNumItems;
    v7 = 0i64;
    do
    {
      v8 = &partInstance->mSlots.mData.mItems[v7];
      mData = (UFG::PartDefinition *)v8->mBasePart.mPart.mData;
      if ( mData )
      {
        if ( !UFG::PartTemplateInstance::SlotEntry::IsComposited(&partInstance->mSlots.mData.mItems[v7]) )
        {
          TextureAlternate = UFG::PartDefinition::GetTextureAlternate(mData, &v8->mBasePart.mTextureSet);
          v11 = TextureAlternate;
          if ( TextureAlternate )
          {
            v12 = 0;
            if ( TextureAlternate->mTextures.mData.mNumItems )
            {
              do
              {
                v13 = (__int64)&v11->mTextures.mData.mItems[v12];
                if ( *(_QWORD *)(v13 + 40) && *(_QWORD *)(v13 + 80) )
                {
                  Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, *(_DWORD *)v13);
                  mNumOverrides = material_modifier->mNumOverrides;
                  v16 = Param;
                  v17 = 0;
                  if ( (int)mNumOverrides <= 0 )
                    goto LABEL_13;
                  mOverrides = material_modifier->mOverrides;
                  while ( mOverrides->mStateParamIndex != v16 )
                  {
                    ++v17;
                    ++mOverrides;
                    if ( v17 >= (int)mNumOverrides )
                      goto LABEL_13;
                  }
                  if ( v17 == -1 )
                  {
LABEL_13:
                    v19 = *(_DWORD *)v13;
                    v20 = *(_DWORD *)(*(_QWORD *)(v13 + 80) + 200i64);
                    original_name_uid = *(_DWORD *)(*(_QWORD *)(v13 + 40) + 200i64);
                    material_modifier->mNumOverrides = mNumOverrides + 1;
                    Illusion::ParamOverride::SetTextureOverride(
                      &material_modifier->mOverrides[mNumOverrides],
                      v19,
                      v20,
                      OVERRIDE_EQUALS,
                      original_name_uid);
                  }
                  else
                  {
                    Illusion::ParamOverride::SetTextureOverride(
                      &material_modifier->mOverrides[v17],
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
          v21 = mData->mTintColours.mData.mNumItems;
          if ( v21 )
          {
            v22 = 0;
            v23 = colour_variety++ % v21;
            v24 = v23;
            if ( this->mPartLoader.mPartCount )
            {
              while ( UFG::PartLoader::GetPart(&this->mPartLoader, v22)->mSlotName.mUID != mData->mSlotName.mUID )
              {
                if ( ++v22 >= this->mPartLoader.mPartCount )
                  goto LABEL_23;
              }
              mItems = mData->mTintColours.mData.mItems;
              v26 = (_DWORD *)((char *)this + 16 * v22);
              v26[323] = LODWORD(mItems[v24].r);
              v26[324] = LODWORD(mItems[v24].g);
              v26[325] = LODWORD(mItems[v24].b);
              v26[326] = LODWORD(mItems[v24].a);
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
void __fastcall UFG::StreamedResourceComponent::ApplyTextureOverrideForPart(
        UFG::StreamedResourceComponent *this,
        Illusion::MaterialModifierParams<10> *material_modifier,
        UFG::PartDefinition *part,
        UFG::qSymbolUC *textureSet)
{
  UFG::PartDefinition::TextureAlternate *TextureAlternate; // rax
  unsigned int v8; // edi
  UFG::PartDefinition::TextureAlternate *v9; // r14
  unsigned int v10; // esi
  UFG::PartDefinition::TextureData *v11; // rbx
  unsigned __int16 Param; // ax
  __int64 mNumOverrides; // r10
  int v14; // edx
  int v15; // eax
  Illusion::ParamOverride *mOverrides; // rcx
  unsigned int mTextureSlot; // edx
  unsigned int v18; // r8d
  unsigned int mNumItems; // r8d
  unsigned int v20; // edx
  __int64 v21; // rsi
  UFG::qColour *mItems; // rcx
  void *v23; // r8
  unsigned int original_name_uid; // [rsp+20h] [rbp-28h]

  TextureAlternate = UFG::PartDefinition::GetTextureAlternate(part, textureSet);
  v8 = 0;
  v9 = TextureAlternate;
  if ( TextureAlternate )
  {
    v10 = 0;
    if ( TextureAlternate->mTextures.mData.mNumItems )
    {
      do
      {
        v11 = &v9->mTextures.mData.mItems[v10];
        if ( v11->mOriginalTexture.mData && v11->mOverrideTexture.mData )
        {
          Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, v11->mTextureSlot);
          mNumOverrides = material_modifier->mNumOverrides;
          v14 = Param;
          v15 = 0;
          if ( (int)mNumOverrides <= 0 )
            goto LABEL_9;
          mOverrides = material_modifier->mOverrides;
          while ( mOverrides->mStateParamIndex != v14 )
          {
            ++v15;
            ++mOverrides;
            if ( v15 >= (int)mNumOverrides )
              goto LABEL_9;
          }
          if ( v15 == -1 )
          {
LABEL_9:
            mTextureSlot = v11->mTextureSlot;
            v18 = (unsigned int)v11->mOverrideTexture.mData[2].mBaseNode.mNeighbours[0];
            original_name_uid = (unsigned int)v11->mOriginalTexture.mData[2].mBaseNode.mNeighbours[0];
            material_modifier->mNumOverrides = mNumOverrides + 1;
            Illusion::ParamOverride::SetTextureOverride(
              &material_modifier->mOverrides[mNumOverrides],
              mTextureSlot,
              v18,
              OVERRIDE_EQUALS,
              original_name_uid);
          }
          else
          {
            Illusion::ParamOverride::SetTextureOverride(
              &material_modifier->mOverrides[v15],
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
  mNumItems = part->mTintColours.mData.mNumItems;
  if ( mNumItems )
  {
    v20 = colour_variety++ % mNumItems;
    v21 = v20;
    if ( this->mPartLoader.mPartCount )
    {
      while ( UFG::PartLoader::GetPart(&this->mPartLoader, v8)->mSlotName.mUID != part->mSlotName.mUID )
      {
        if ( ++v8 >= this->mPartLoader.mPartCount )
          return;
      }
      mItems = part->mTintColours.mData.mItems;
      v23 = (char *)this + 16 * v8;
      *((_DWORD *)v23 + 323) = LODWORD(mItems[v21].r);
      *((_DWORD *)v23 + 324) = LODWORD(mItems[v21].g);
      *((_DWORD *)v23 + 325) = LODWORD(mItems[v21].b);
      *((_DWORD *)v23 + 326) = LODWORD(mItems[v21].a);
    }
  }
}

// File Line: 445
// RVA: 0x446130
void __fastcall UFG::StreamedResourceComponent::UpdateLoadState(
        UFG::StreamedResourceComponent *this,
        UFG::SimObject *object)
{
  float v3; // xmm0_4

  if ( this->mActivePriority.mUID == qSymbol_Low.mUID )
  {
    if ( this->mUseMeshLoader && !this->mMeshLoader.mResourceCount )
    {
      if ( UFG::TrueCrowdSet::Instance::IsLoaded(&this->mMeshLoader.mTrueCrowdInstance) )
        UFG::MeshResourceLoader::QueueLoad(&this->mMeshLoader);
      else
        UFG::TrueCrowdDataBase::QueryPreloadedInstance(
          UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
          this->mMeshLoader.mPropertySet,
          &this->mMeshLoader.mTrueCrowdInstance);
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
      if ( this->mPartLoader.mPartRequestCount )
        UFG::PartLoader::Unload(&this->mPartLoader);
    }
    else
    {
      if ( this->mUseMeshLoader && !this->mMeshLoader.mResourceCount )
        UFG::MeshResourceLoader::QueueLoad(&this->mMeshLoader);
      if ( !this->mPartLoader.mPartRequestCount )
        UFG::PartLoader::QueueLoad(&this->mPartLoader);
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
  unsigned int mResourceCount; // r8d
  int v3; // edx
  UFG::ResourceRequest **i; // rcx
  char result; // al

  if ( !this->mMeshLoader.mPropertySet )
    return 1;
  mResourceCount = this->mMeshLoader.mResourceCount;
  if ( mResourceCount )
  {
    v3 = 0;
    for ( i = this->mMeshLoader.mResourceRequests; (*i)->mLoadStatus == Loaded; ++i )
    {
      if ( ++v3 >= mResourceCount )
        return 1;
    }
  }
  result = UFG::PartLoader::IsLoaded(&this->mPartLoader);
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
  UFG::MeshResourceLoader *p_mMeshLoader; // rbx

  if ( this->mUseMeshLoader )
  {
    p_mMeshLoader = &this->mMeshLoader;
    if ( !this->mMeshLoader.mHighDefinition )
    {
      UFG::MeshResourceLoader::Unload(&this->mMeshLoader);
      p_mMeshLoader->mHighDefinition = 1;
      UFG::MeshResourceLoader::QueueLoad(p_mMeshLoader);
    }
  }
}

// File Line: 544
// RVA: 0x43C2C0
void __fastcall UFG::StreamedResourceComponent::DowngradeResolution(UFG::StreamedResourceComponent *this)
{
  UFG::MeshResourceLoader *p_mMeshLoader; // rbx

  if ( this->mUseMeshLoader )
  {
    p_mMeshLoader = &this->mMeshLoader;
    if ( this->mMeshLoader.mHighDefinition )
    {
      UFG::MeshResourceLoader::Unload(&this->mMeshLoader);
      p_mMeshLoader->mHighDefinition = 0;
      UFG::MeshResourceLoader::QueueLoad(p_mMeshLoader);
    }
  }
}

// File Line: 557
// RVA: 0x445360
void __fastcall UFG::StreamedResourceComponent::UpdateActivePriority(UFG::StreamedResourceComponent *this)
{
  unsigned int mUID; // edx
  unsigned int v2; // eax
  unsigned int v3; // ebp
  unsigned int v5; // r8d
  unsigned int *mSpawnPriorityReferenceCount; // r9
  UFG::SimObject *m_pSimObject; // r8
  __int16 m_Flags; // dx
  UFG::UIMapBlip *m_pComponent; // rbx
  UFG::SimObjectGame *v10; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::VehicleOccupantComponent *invokable; // rax
  int mPriority; // r15d
  int v14; // esi
  unsigned int mPartCount; // r14d
  UFG::PartDefinition *Part; // rbx
  UFG::PartDatabase *v17; // rax
  UFG::qSymbol newPriority; // [rsp+50h] [rbp+8h] BYREF
  UFG::qSymbol oldPriority; // [rsp+58h] [rbp+10h] BYREF

  mUID = this->mActivePriority.mUID;
  v2 = UFG::gNullQSymbol.mUID;
  v3 = 0;
  v5 = 0;
  mSpawnPriorityReferenceCount = this->mSpawnPriorityReferenceCount;
  oldPriority.mUID = mUID;
  newPriority.mUID = UFG::gNullQSymbol.mUID;
  while ( !*mSpawnPriorityReferenceCount )
  {
    ++v5;
    ++mSpawnPriorityReferenceCount;
    if ( v5 >= 4 )
      goto LABEL_6;
  }
  v2 = UFG::StreamedResourceComponent::sSpawnPrioritySymbols[v5]->mUID;
  newPriority.mUID = v2;
LABEL_6:
  if ( mUID != v2 )
  {
    if ( this->mUseMeshLoader )
    {
      if ( this->mMeshLoader.mResourceCount )
      {
        UFG::ObjectResourceManager::ChangeObjectPriority(UFG::ObjectResourceManager::sInstance, this, &newPriority);
        v2 = newPriority.mUID;
      }
      m_pSimObject = this->m_pSimObject;
      if ( m_pSimObject )
      {
        m_Flags = m_pSimObject->m_Flags;
        if ( (m_Flags & 0x4000) != 0 )
        {
          m_pComponent = (UFG::UIMapBlip *)m_pSimObject->m_Components.p[44].m_pComponent;
        }
        else
        {
          v10 = (UFG::SimObjectGame *)this->m_pSimObject;
          if ( m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v10, UFG::CharacterOccupantComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v10, UFG::CharacterOccupantComponent::_TypeUID);
          m_pComponent = (UFG::UIMapBlip *)ComponentOfTypeHK;
          v2 = newPriority.mUID;
        }
        if ( m_pComponent )
        {
          if ( SSInvokedMethod::get_invokable(m_pComponent) )
          {
            invokable = (UFG::VehicleOccupantComponent *)SSInvokedMethod::get_invokable(m_pComponent);
            UFG::VehicleOccupantComponent::UpdateOccupantPriority(invokable, &oldPriority, &newPriority);
          }
          v2 = newPriority.mUID;
        }
      }
      this->mMeshLoader.mActivePriority.mUID = v2;
    }
    this->mActivePriority.mUID = v2;
    mPriority = this->mPartLoader.mPriority;
    v14 = mPriority;
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
    if ( this->mPartLoader.mPartRequestCount )
    {
      mPartCount = this->mPartLoader.mPartCount;
      if ( mPartCount )
      {
        do
        {
          Part = UFG::PartLoader::GetPart(&this->mPartLoader, v3);
          v17 = UFG::PartDatabase::Instance();
          UFG::PartDatabase::ModifyPriorityForPart(v17, Part, mPriority, v14);
          ++v3;
        }
        while ( v3 < mPartCount );
      }
    }
    this->mPartLoader.mPriority = v14;
  }
}

// File Line: 621
// RVA: 0x43DF90
void __fastcall UFG::StreamedResourceComponent::IncrementPriorityReferenceCount(
        UFG::StreamedResourceComponent *this,
        UFG::qSymbol *symbol)
{
  __int64 v2; // rax
  UFG::qSymbol **i; // r8

  v2 = 0i64;
  for ( i = UFG::StreamedResourceComponent::sSpawnPrioritySymbols; symbol->mUID != (*i)->mUID; ++i )
  {
    v2 = (unsigned int)(v2 + 1);
    if ( (unsigned int)v2 >= 4 )
      return;
  }
  ++this->mSpawnPriorityReferenceCount[v2];
  UFG::StreamedResourceComponent::UpdateActivePriority(this);
}

// File Line: 631
// RVA: 0x43B0F0
void __fastcall UFG::StreamedResourceComponent::DecrementPriorityReferenceCount(
        UFG::StreamedResourceComponent *this,
        UFG::qSymbol *symbol)
{
  __int64 v3; // rax
  UFG::qSymbol **i; // r8
  __int64 v5; // rcx
  unsigned int v6; // eax

  v3 = 0i64;
  for ( i = UFG::StreamedResourceComponent::sSpawnPrioritySymbols; symbol->mUID != (*i)->mUID; ++i )
  {
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= 4 )
      return;
  }
  v5 = (unsigned int)v3;
  v6 = this->mSpawnPriorityReferenceCount[v3];
  if ( v6 )
  {
    this->mSpawnPriorityReferenceCount[v5] = v6 - 1;
    UFG::StreamedResourceComponent::UpdateActivePriority(this);
  }
}

// File Line: 647
// RVA: 0x43DE60
UFG::qSymbol *__fastcall UFG::StreamedResourceComponent::GetSpawnPriority(
        UFG::StreamedResourceComponent *this,
        UFG::SpawnInfoInterface::SpawnPriority *priority)
{
  UFG::SpawnInfoInterface::SpawnPriority v2; // r9d
  unsigned int *mSpawnPriorityReferenceCount; // rax
  __int64 v4; // r8

  if ( priority )
  {
    v2 = UnReferenced;
    mSpawnPriorityReferenceCount = this->mSpawnPriorityReferenceCount;
    v4 = 0i64;
    while ( !*mSpawnPriorityReferenceCount )
    {
      ++v4;
      ++v2;
      ++mSpawnPriorityReferenceCount;
      if ( v4 >= 4 )
        return &this->mActivePriority;
    }
    *priority = v2;
  }
  return &this->mActivePriority;
}

// File Line: 676
// RVA: 0x444D00
void __fastcall UFG::StreamedResourceComponent::Update(
        UFG::StreamedResourceComponent *this,
        float seconds,
        UFG::qVector3 *streamPosition)
{
  UFG::SimObject *m_pSimObject; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::SimObject *v7; // rdx
  UFG::qVector3 *v8; // rbp
  __m128 y_low; // xmm2
  float v10; // xmm0_4
  __int64 v11; // rdx
  _BOOL8 v12; // r8
  __int64 v13; // rdx
  _BOOL8 v14; // r8
  UFG::eSimObjectTypeEnum mSimObjectType; // ecx
  bool v16; // si
  bool v17; // di
  unsigned int VisIndexAtPosition; // eax
  UFG::SimObjectCVBase *v19; // rbx
  UFG::AiDriverComponent *v20; // rax

  m_pSimObject = this->m_pSimObject;
  if ( m_pSimObject )
    m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
  else
    m_pTransformNodeComponent = 0i64;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
  v7 = this->m_pSimObject;
  v8 = (UFG::qVector3 *)&m_pTransformNodeComponent->mWorldTransform.v3;
  y_low = (__m128)LODWORD(streamPosition->y);
  v10 = streamPosition->z - m_pTransformNodeComponent->mWorldTransform.v3.z;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.y)
                                    * (float)(y_low.m128_f32[0] - m_pTransformNodeComponent->mWorldTransform.v3.y))
                            + (float)((float)(streamPosition->x - m_pTransformNodeComponent->mWorldTransform.v3.x)
                                    * (float)(streamPosition->x - m_pTransformNodeComponent->mWorldTransform.v3.x)))
                    + (float)(v10 * v10);
  LODWORD(this->mCameraDistance) = _mm_sqrt_ps(y_low).m128_u32[0];
  UFG::StreamedResourceComponent::UpdateLoadState(this, v7);
  UFG::MeshResourceLoader::PropagateResourceEvents(&this->mMeshLoader, v11, v12);
  UFG::PartLoader::PropagatePartEvents(&this->mPartLoader, v13, v14);
  mSimObjectType = this->mSimObjectType;
  v16 = mSimObjectType == eSIM_OBJ_TYPE_INTERACTIVE_PROP && this->mActivePriority.mUID == qSymbol_Low.mUID;
  v17 = mSimObjectType == eSIM_OBJ_TYPE_VEHICLE && this->mActivePriority.mUID != qSymbol_Critical.mUID;
  if ( v16 || v17 )
  {
    VisIndexAtPosition = UFG::SectionChooser::GetVisIndexAtPosition(v8, 0);
    if ( !UFG::SectionChooser::IsSectionVisible_VisIndex(VisIndexAtPosition, SCENERY_LAYER_STD, 0) )
    {
      if ( v16 )
        UFG::Simulation::QueueSimObjectToBeDestroyedRecursive(&UFG::gSim, this->m_pSimObject);
      if ( v17 )
      {
        v19 = (UFG::SimObjectCVBase *)this->m_pSimObject;
        if ( !v19
          || (v20 = UFG::SimObjectCVBase::GetComponent<UFG::AiDriverComponent>(v19)) == 0i64
          || !((unsigned __int8 (__fastcall *)(UFG::AiDriverComponent *))v20->UFG::VehicleDriverInterface::UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(v20) )
        {
          UFG::WheeledVehicleManager::QueueDeletion(UFG::WheeledVehicleManager::m_Instance, v19);
        }
      }
    }
  }
}

// File Line: 713
// RVA: 0x445580
void __fastcall UFG::StreamedResourceComponent::UpdateAll(float seconds)
{
  UFG::SimComponent *m_pSimComponent; // rbx
  float v3; // xmm2_4
  float v4; // xmm1_4
  UFG::BaseCameraComponent *mCurrentCamera; // rax
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qNode<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent> *p_mNode; // rcx
  UFG::qList<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent,1,0> *v9; // rbx
  UFG::qVector3 streamPosition; // [rsp+20h] [rbp-28h] BYREF

  m_pSimComponent = UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent;
  if ( UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent )
  {
    UFG::TransformNodeComponent::UpdateWorldTransform((UFG::TransformNodeComponent *)UFG::StreamedResourceComponent::spPlayerTransformNode.m_pSimComponent);
    v3 = *((float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev + 1);
    streamPosition.x = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mPrev;
    v4 = *(float *)&m_pSimComponent[2].m_BoundComponentHandles.mNode.mNext;
    streamPosition.y = v3;
    streamPosition.z = v4;
  }
  else
  {
    mCurrentCamera = UFG::Director::Get()->mCurrentCamera;
    if ( mCurrentCamera )
      mCurrentCamera = (UFG::BaseCameraComponent *)((char *)mCurrentCamera + 80);
    y = mCurrentCamera->mCamera.mView.v2.y;
    streamPosition.x = mCurrentCamera->mCamera.mView.v2.x;
    z = mCurrentCamera->mCamera.mView.v2.z;
    streamPosition.y = y;
    streamPosition.z = z;
  }
  p_mNode = UFG::StreamedResourceComponent::s_StreamedResourceComponentList.mNode.mNext - 4;
  if ( (UFG::qList<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent,1,0> *)&UFG::StreamedResourceComponent::s_StreamedResourceComponentList.mNode.mNext[-4] != &UFG::StreamedResourceComponent::s_StreamedResourceComponentList - 4 )
  {
    do
    {
      v9 = (UFG::qList<UFG::StreamedResourceComponent,UFG::StreamedResourceComponent,1,0> *)&p_mNode[4].mNext[-4];
      if ( ((__int64)p_mNode[2].mPrev & 3) == 1 )
        UFG::StreamedResourceComponent::Update((UFG::StreamedResourceComponent *)p_mNode, seconds, &streamPosition);
      p_mNode = &v9->mNode;
    }
    while ( v9 != &UFG::StreamedResourceComponent::s_StreamedResourceComponentList - 4 );
  }
}

// File Line: 739
// RVA: 0x43F9D0
void __fastcall UFG::StreamedResourceComponent::OnLoadEventCallback(
        UFG::StreamedResourceComponent *context,
        UFG::ResourceRequest *request,
        bool loaded)
{
  if ( context )
    UFG::StreamedResourceComponent::DispatchResourceEvent(context, request, loaded);
}

// File Line: 748
// RVA: 0x43FAB0
void __fastcall UFG::StreamedResourceComponent::OnPartForceRemovedCallback(
        UFG::SimObject **context,
        UFG::PartRequest *request)
{
  if ( context )
    UFG::Simulation::DestroySimObject(&UFG::gSim, context[5]);
}

// File Line: 781
// RVA: 0x4393C0
void __fastcall UFG::StreamedResourceComponent::BindPart(
        UFG::StreamedResourceComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        UFG::PartDefinition *part,
        unsigned int part_index)
{
  const char *TypeName; // rax
  unsigned __int64 v8; // r10
  UFG::qReflectObject *mData; // rsi
  unsigned int v10; // r8d
  unsigned int mPrev; // edx
  unsigned __int64 mTypeUID; // rsi
  __int64 v13; // rsi
  unsigned int i; // edi
  __int64 v15; // rbx
  __int64 v16; // rax
  ModelType *ModelType; // rax
  __int64 v18; // rdx
  unsigned int mNumModelTypeLODs; // edx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v21; // rax
  UFG::qResourceInventory *v22; // rax
  UFG::qResourceWarehouse *v23; // rax
  Illusion::ModelProxy v24; // [rsp+38h] [rbp-40h] BYREF

  TypeName = UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData>::GetTypeName((UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData> *)this);
  v8 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  mData = part->mModelAsset.mData;
  v10 = 0;
  mPrev = (unsigned int)mData[2].mHandles.mNode.mPrev;
  if ( mPrev )
  {
    mTypeUID = mData[2].mTypeUID;
    while ( *(_QWORD *)(*(_QWORD *)(mTypeUID + 8i64 * v10) + 56i64) != v8 )
    {
      if ( ++v10 >= mPrev )
        goto LABEL_7;
    }
    v13 = *(_QWORD *)(mTypeUID + 8i64 * v10);
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
    if ( (int)v16 < 4 )
    {
      if ( !composite_drawable->mModelType[v16] )
      {
        ModelType = UFG::CompositeDrawableComponent::CreateModelType(composite_drawable, 0);
        v18 = *(unsigned int *)(v15 + 32);
        composite_drawable->mModelType[v18] = ModelType;
        mNumModelTypeLODs = v18 + 1;
        if ( composite_drawable->mNumModelTypeLODs > mNumModelTypeLODs )
          mNumModelTypeLODs = composite_drawable->mNumModelTypeLODs;
        composite_drawable->mNumModelTypeLODs = mNumModelTypeLODs;
      }
      UFG::qResourceHandle::qResourceHandle(&v24.mModelHandle);
      Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v21 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v21, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init(&v24.mModelHandle, 0xA2ADCD77, 0, Inventory);
      v24.mRModel = (Illusion::rModel *)v15;
      ModelType::AddModelBinding(
        composite_drawable->mModelType[*(unsigned int *)(v15 + 32)],
        &v24,
        &UFG::qMatrix44::msIdentity,
        part_index,
        0);
      v22 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v23 = UFG::qResourceWarehouse::Instance();
        v22 = UFG::qResourceWarehouse::GetInventory(v23, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v22;
      }
      UFG::qResourceHandle::Close(&v24.mModelHandle, v22);
      UFG::qResourceHandle::~qResourceHandle(&v24.mModelHandle);
    }
  }
}

// File Line: 801
// RVA: 0x444350
void __fastcall UFG::StreamedResourceComponent::UnbindPart(
        UFG::StreamedResourceComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        UFG::PartDefinition *part)
{
  const char *TypeName; // rax
  unsigned __int64 v6; // r10
  UFG::qReflectObject *mData; // rdx
  __int64 v8; // r8
  unsigned int mPrev; // r9d
  unsigned __int64 mTypeUID; // rdx
  __int64 v11; // r14
  unsigned int i; // ebp
  Illusion::rModel *v13; // rdi
  __int64 j; // rbx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v16; // rax
  UFG::qResourceInventory *v17; // rax
  UFG::qResourceWarehouse *v18; // rax
  Illusion::ModelProxy v19; // [rsp+28h] [rbp-40h] BYREF

  TypeName = UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData>::GetTypeName((UFG::qReflectObjectType<UFG::ModelData,UFG::ModelAssetData> *)this);
  v6 = UFG::qStringHash64(TypeName, 0xFFFFFFFFFFFFFFFFui64);
  mData = part->mModelAsset.mData;
  v8 = 0i64;
  mPrev = (unsigned int)mData[2].mHandles.mNode.mPrev;
  if ( mPrev )
  {
    mTypeUID = mData[2].mTypeUID;
    while ( *(_QWORD *)(*(_QWORD *)(mTypeUID + 8 * v8) + 56i64) != v6 )
    {
      v8 = (unsigned int)(v8 + 1);
      if ( (unsigned int)v8 >= mPrev )
        goto LABEL_7;
    }
    v11 = *(_QWORD *)(mTypeUID + 8 * v8);
  }
  else
  {
LABEL_7:
    v11 = 0i64;
  }
  for ( i = 0; i < *(_DWORD *)(v11 + 88); ++i )
  {
    v13 = (Illusion::rModel *)(*(_QWORD *)(v11 + 80) + 112i64 * i);
    for ( j = 0i64; (unsigned int)j < composite_drawable->mNumModelTypeLODs; j = (unsigned int)(j + 1) )
    {
      UFG::qResourceHandle::qResourceHandle(&v19.mModelHandle);
      Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v16 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v16, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Init(&v19.mModelHandle, 0xA2ADCD77, 0, Inventory);
      v19.mRModel = v13;
      ModelType::RemoveModelBinding(composite_drawable->mModelType[j], &v19);
      v17 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
      if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
      {
        v18 = UFG::qResourceWarehouse::Instance();
        v17 = UFG::qResourceWarehouse::GetInventory(v18, 0xA2ADCD77);
        `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v17;
      }
      UFG::qResourceHandle::Close(&v19.mModelHandle, v17);
      UFG::qResourceHandle::~qResourceHandle(&v19.mModelHandle);
    }
  }
}

// File Line: 814
// RVA: 0x4441B0
void __fastcall UFG::StreamedResourceComponent::UnbindModelResource(
        UFG::StreamedResourceComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        UFG::TrueCrowdModel *model_resource)
{
  unsigned int v5; // r14d
  __int64 mOffset; // rax
  char *v7; // rcx
  char *v8; // rdi
  unsigned int i; // ebx
  __int64 v10; // rax
  char *v11; // rcx
  ModelType *v12; // rsi
  unsigned int v13; // ebp
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v15; // rax
  UFG::qResourceInventory *v16; // rax
  UFG::qResourceWarehouse *v17; // rax
  Illusion::ModelProxy v18; // [rsp+28h] [rbp-50h] BYREF

  if ( model_resource->mNumLODs )
  {
    v5 = 0;
    do
    {
      mOffset = model_resource->mLODModel.mOffset;
      if ( mOffset )
        v7 = (char *)&model_resource->mLODModel + mOffset;
      else
        v7 = 0i64;
      v8 = &v7[16 * v5];
      for ( i = 0; i < *(_DWORD *)v8; ++i )
      {
        v10 = *((_QWORD *)v8 + 1);
        if ( v10 )
          v11 = &v8[v10 + 8];
        else
          v11 = 0i64;
        v12 = composite_drawable->mModelType[v5];
        if ( v12 )
        {
          v13 = *(_DWORD *)&v11[16 * i + 8];
          UFG::qResourceHandle::qResourceHandle(&v18.mModelHandle);
          Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
          if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
          {
            v15 = UFG::qResourceWarehouse::Instance();
            Inventory = UFG::qResourceWarehouse::GetInventory(v15, 0xA2ADCD77);
            `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
          }
          UFG::qResourceHandle::Init(&v18.mModelHandle, 0xA2ADCD77, v13, Inventory);
          v18.mRModel = 0i64;
          ModelType::RemoveModelBinding(v12, &v18);
          v16 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
          if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
          {
            v17 = UFG::qResourceWarehouse::Instance();
            v16 = UFG::qResourceWarehouse::GetInventory(v17, 0xA2ADCD77);
            `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v16;
          }
          UFG::qResourceHandle::Close(&v18.mModelHandle, v16);
          UFG::qResourceHandle::~qResourceHandle(&v18.mModelHandle);
        }
      }
      ++v5;
    }
    while ( v5 < model_resource->mNumLODs );
  }
}

// File Line: 837
// RVA: 0x4440F0
void __fastcall UFG::StreamedResourceComponent::UnbindAllModels(
        UFG::StreamedResourceComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable)
{
  unsigned int v2; // edi
  unsigned int i; // ebx
  __int64 mModelIndex; // rax
  unsigned int mPartCount; // ebx
  UFG::PartDefinition *Part; // rax

  v2 = 0;
  for ( i = 0; i < this->mMeshLoader.mTrueCrowdInstance.mNumParts; ++i )
  {
    mModelIndex = this->mMeshLoader.mTrueCrowdInstance.mPart[i].mModelIndex;
    if ( (_DWORD)mModelIndex != -1 )
      UFG::StreamedResourceComponent::UnbindModelResource(
        this,
        composite_drawable,
        this->mMeshLoader.mTrueCrowdInstance.mSet->mFiles[i].p[mModelIndex]);
  }
  mPartCount = this->mPartLoader.mPartCount;
  if ( mPartCount )
  {
    do
    {
      Part = UFG::PartLoader::GetPart(&this->mPartLoader, v2);
      UFG::StreamedResourceComponent::UnbindPart(this, composite_drawable, Part);
      ++v2;
    }
    while ( v2 < mPartCount );
  }
}

// File Line: 857
// RVA: 0x441470
void __fastcall UFG::StreamedResourceComponent::RefreshRenderState(
        UFG::StreamedResourceComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable)
{
  UFG::ICompositeLook *mCompositeLook; // rcx
  unsigned int v5; // r8d
  unsigned int mNumParts; // r9d
  UFG::ModelTextureCombination *mPart; // rdx
  __int64 mModelIndex; // rcx
  ModelType *v9; // rax
  ModelType::ModelBindingSkin *mNext; // rbx
  UFG::qList<ModelType::ModelBindingSkin,ModelType::ModelBindingSkin,1,0> *i; // rsi
  UFG::qResourceData *mData; // rax
  __int64 v13; // rcx
  char *v14; // rax

  UFG::StreamedResourceComponent::UpdateMaterialModifiers(this, &composite_drawable->mMaterialModifier);
  mCompositeLook = composite_drawable->mCompositeLook;
  if ( mCompositeLook )
    mCompositeLook->vfptr->OnUpdateMaterial(mCompositeLook, composite_drawable);
  v5 = 0;
  mNumParts = this->mMeshLoader.mTrueCrowdInstance.mNumParts;
  if ( mNumParts )
  {
    mPart = this->mMeshLoader.mTrueCrowdInstance.mPart;
    while ( 1 )
    {
      mModelIndex = mPart->mModelIndex;
      if ( (_DWORD)mModelIndex != -1 )
      {
        if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)((char *)&this->mMeshLoader.mTrueCrowdInstance.mSet->mResourceFilename.mUID
                                               + (unsigned __int64)mPart
                                               - (_QWORD)&this->mMeshLoader.mTrueCrowdInstance)
                                   + 8 * mModelIndex)
                       + 24i64) )
          break;
      }
      ++v5;
      ++mPart;
      if ( v5 >= mNumParts )
        goto LABEL_8;
    }
  }
  else
  {
LABEL_8:
    v9 = composite_drawable->mModelType[0];
    if ( v9 )
    {
      mNext = (ModelType::ModelBindingSkin *)v9->mModelBindingSkinTable.mNode.mNext;
      for ( i = &v9->mModelBindingSkinTable;
            mNext != (ModelType::ModelBindingSkin *)i;
            mNext = (ModelType::ModelBindingSkin *)mNext->mNext )
      {
        if ( !mNext->mSoftbody )
        {
          mData = mNext->mModelProxy.mModelHandle.mData;
          if ( mData )
          {
            v13 = *(_QWORD *)&mData[2].mNode.mUID;
            if ( v13 )
              v14 = (char *)&mData[2].mNode.mChild[2] + v13;
            else
              v14 = 0i64;
            if ( *((_DWORD *)v14 + 2) )
              Render::ISoftbody::GenerateSoftbody(&Render::gSoftbody, composite_drawable, mNext);
          }
        }
      }
    }
  }
  UFG::CompositeDrawableComponent::UpdateHasSoftBody(composite_drawable);
}

// File Line: 904
// RVA: 0x438F40
void __fastcall UFG::StreamedResourceComponent::BindModelResource(
        UFG::StreamedResourceComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        unsigned int index,
        UFG::TrueCrowdModel *model_resource,
        unsigned int *boneUIDs,
        unsigned int numBoneUIDs)
{
  UFG::TrueCrowdModel *v6; // r12
  UFG::CompositeDrawableComponent *v7; // rbx
  unsigned int v8; // edi
  unsigned int v9; // edx
  UFG::qSafePointerNode<UFG::SimComponent>Vtbl **v10; // r13
  unsigned int mNumModelTypeLODs; // ecx
  __int64 mOffset; // rax
  char *v13; // rcx
  char *v14; // r15
  unsigned int v15; // r12d
  __int64 v16; // rax
  __int64 v17; // rcx
  __int64 v18; // rbx
  unsigned int *v19; // rdi
  __int64 v20; // rsi
  unsigned int BoneID; // ebp
  unsigned int v22; // r14d
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v24; // rax
  UFG::qResourceInventory *v25; // rax
  UFG::qResourceWarehouse *v26; // rax
  unsigned int v27; // ebx
  UFG::qResourceInventory *v28; // rax
  UFG::qResourceWarehouse *v29; // rax
  ModelType::ModelBindingSkin *v30; // rbp
  UFG::qResourceInventory *v31; // rax
  UFG::qResourceWarehouse *v32; // rax
  unsigned int v33; // esi
  __int64 v34; // rax
  char *v35; // rcx
  char *v36; // rbx
  UFG::allocator::free_link *v37; // rax
  ModelType::SimpleMorphTargets *v38; // rax
  __int64 v39; // r14
  unsigned int v40; // ebx
  UFG::qResourceHandle *v41; // rdi
  UFG::qResourceInventory *v42; // rax
  UFG::qResourceWarehouse *v43; // rax
  unsigned int mNumModelBindings; // edx
  ModelType::SimpleMorphTargets *mMorphTargets; // rcx
  unsigned int lod; // [rsp+30h] [rbp-C8h]
  int v47; // [rsp+34h] [rbp-C4h]
  char *v48; // [rsp+40h] [rbp-B8h]
  Illusion::ModelProxy v49; // [rsp+48h] [rbp-B0h] BYREF
  Illusion::ModelProxy v50; // [rsp+70h] [rbp-88h] BYREF
  __int64 v51; // [rsp+98h] [rbp-60h]
  Illusion::ModelProxy *v52; // [rsp+A0h] [rbp-58h]

  v51 = -2i64;
  v6 = model_resource;
  v7 = composite_drawable;
  if ( !model_resource->mNumLODs )
    return;
  v8 = 0;
  lod = 0;
  v9 = numBoneUIDs;
  do
  {
    v10 = &(&v7->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr)[v8];
    if ( !v10[178] )
    {
      v10[178] = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)UFG::CompositeDrawableComponent::CreateModelType(v7, 0);
      mNumModelTypeLODs = v8 + 1;
      if ( v7->mNumModelTypeLODs > v8 + 1 )
        mNumModelTypeLODs = v7->mNumModelTypeLODs;
      v7->mNumModelTypeLODs = mNumModelTypeLODs;
      v9 = numBoneUIDs;
    }
    mOffset = v6->mLODModel.mOffset;
    if ( mOffset )
      v13 = (char *)&v6->mLODModel + mOffset;
    else
      v13 = 0i64;
    v14 = &v13[16 * v8];
    v48 = v14;
    v15 = 0;
    v47 = 0;
    if ( !*(_DWORD *)v14 )
      goto LABEL_53;
    while ( 1 )
    {
      v16 = *((_QWORD *)v14 + 1);
      v17 = v16 ? (__int64)&v14[v16 + 8] : 0i64;
      v18 = v17 + 16i64 * v15;
      if ( *(_WORD *)(v18 + 12) )
        break;
      if ( !*(_WORD *)(v18 + 14) )
      {
        if ( v9 )
        {
          v52 = &v50;
          v19 = boneUIDs;
          v20 = v9;
          do
          {
            BoneID = Skeleton::GetBoneID((Skeleton *)composite_drawable->mRigHandle.mData[3].mNode.mParent, *v19);
            v22 = *(_DWORD *)(v18 + 8);
            UFG::qResourceHandle::qResourceHandle(&v50.mModelHandle);
            Inventory = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
            if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
            {
              v24 = UFG::qResourceWarehouse::Instance();
              Inventory = UFG::qResourceWarehouse::GetInventory(v24, 0xA2ADCD77);
              `UFG::qGetResourceInventory<Illusion::Model>::`2::result = Inventory;
            }
            UFG::qResourceHandle::Init(&v50.mModelHandle, 0xA2ADCD77, v22, Inventory);
            v50.mRModel = 0i64;
            ModelType::AddRigidModelBinding((ModelType *)v10[178], &v50, BoneID, &UFG::qMatrix44::msIdentity, index);
            v25 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
            if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
            {
              v26 = UFG::qResourceWarehouse::Instance();
              v25 = UFG::qResourceWarehouse::GetInventory(v26, 0xA2ADCD77);
              `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v25;
            }
            UFG::qResourceHandle::Close(&v50.mModelHandle, v25);
            UFG::qResourceHandle::~qResourceHandle(&v50.mModelHandle);
            ++v19;
            --v20;
          }
          while ( v20 );
          v14 = v48;
          v15 = v47;
        }
        else
        {
          ModelType::buildModelBindingRigid((ModelType *)v10[178]);
        }
      }
LABEL_28:
      v47 = ++v15;
      if ( v15 >= *(_DWORD *)v14 )
        goto LABEL_51;
      v9 = numBoneUIDs;
    }
    if ( *(_WORD *)(v18 + 14) > 1u )
      goto LABEL_28;
    v27 = *(_DWORD *)(v18 + 8);
    UFG::qResourceHandle::qResourceHandle(&v49.mModelHandle);
    v28 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v29 = UFG::qResourceWarehouse::Instance();
      v28 = UFG::qResourceWarehouse::GetInventory(v29, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v28;
    }
    UFG::qResourceHandle::Init(&v49.mModelHandle, 0xA2ADCD77, v27, v28);
    v49.mRModel = 0i64;
    v8 = lod;
    v30 = ModelType::AddSkinModelBinding((ModelType *)v10[178], &v49, &UFG::qMatrix44::msIdentity, index, lod);
    v31 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
    {
      v32 = UFG::qResourceWarehouse::Instance();
      v31 = UFG::qResourceWarehouse::GetInventory(v32, 0xA2ADCD77);
      `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v31;
    }
    UFG::qResourceHandle::Close(&v49.mModelHandle, v31);
    UFG::qResourceHandle::~qResourceHandle(&v49.mModelHandle);
    if ( v30 )
    {
      v33 = 0;
      if ( *(_DWORD *)v14 )
      {
        do
        {
          v34 = *((_QWORD *)v14 + 1);
          if ( v34 )
            v35 = &v14[v34 + 8];
          else
            v35 = 0i64;
          v36 = &v35[16 * v33];
          if ( (unsigned int)(*((__int16 *)v36 + 7) - 2) <= 1 )
          {
            if ( !v30->mMorphTargets )
            {
              v37 = UFG::qMalloc(0x50ui64, "StreamedResourceComponent::BindModelResource::MorphTargets", 0i64);
              if ( v37 )
                ModelType::SimpleMorphTargets::SimpleMorphTargets((ModelType::SimpleMorphTargets *)v37);
              else
                v38 = 0i64;
              v30->mMorphTargets = v38;
              v38->mNumModelBindings = 0;
            }
            v39 = (unsigned int)(*((__int16 *)v36 + 7) - 2);
            v30->mMorphTargets->mMorphWeights[v39] = this->mMeshLoader.mTrueCrowdInstance.mMorphWeights[v39];
            v40 = *((_DWORD *)v36 + 2);
            v41 = &v30->mMorphTargets->mModelHandles[v39];
            v42 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
            if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
            {
              v43 = UFG::qResourceWarehouse::Instance();
              v42 = UFG::qResourceWarehouse::GetInventory(v43, 0xA2ADCD77);
              `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v42;
            }
            UFG::qResourceHandle::Init(v41, 0xA2ADCD77, v40, v42);
            mNumModelBindings = v39 + 1;
            mMorphTargets = v30->mMorphTargets;
            if ( mMorphTargets->mNumModelBindings > (unsigned int)(v39 + 1) )
              mNumModelBindings = mMorphTargets->mNumModelBindings;
            mMorphTargets->mNumModelBindings = mNumModelBindings;
          }
          ++v33;
        }
        while ( v33 < *(_DWORD *)v14 );
LABEL_51:
        v8 = lod;
      }
    }
    v7 = composite_drawable;
LABEL_53:
    lod = ++v8;
    v6 = model_resource;
    v9 = numBoneUIDs;
  }
  while ( v8 < model_resource->mNumLODs );
}< *(_DWORD *)

// File Line: 992
// RVA: 0x438DD0
void __fastcall UFG::StreamedResourceComponent::BindAllModels(
        UFG::StreamedResourceComponent *this,
        UFG::CompositeDrawableComponent *composite_drawable,
        bool using_temp_rig)
{
  unsigned int v3; // ebp
  unsigned int i; // esi
  unsigned int mModelIndex; // eax
  UFG::TrueCrowdModel *v8; // rbx
  __int64 mOffset; // rax
  UFG::TrueCrowdModel *v10; // rax
  ModelType *v11; // rcx
  UFG::ResourceRequest *mRequest; // rax
  char *v13; // rcx
  unsigned int mPartCount; // ebx
  UFG::PartDefinition *Part; // rax

  v3 = 0;
  if ( !using_temp_rig )
  {
    for ( i = 0; i < this->mMeshLoader.mTrueCrowdInstance.mNumParts; ++i )
    {
      mModelIndex = this->mMeshLoader.mTrueCrowdInstance.mPart[i].mModelIndex;
      if ( mModelIndex != -1 )
      {
        v8 = this->mMeshLoader.mTrueCrowdInstance.mSet->mFiles[i].p[mModelIndex];
        if ( this->mMeshLoader.mHighDefinition )
        {
          mOffset = v8->mHighResolutionResource.mOffset;
          if ( mOffset )
          {
            v10 = (UFG::TrueCrowdModel *)((char *)&v8->mHighResolutionResource + mOffset);
            if ( v10 )
              v8 = v10;
          }
        }
        if ( !this->mFirstResourceLoad && !v8->mType.mValue )
        {
          v11 = composite_drawable->mModelType[0];
          if ( v11 )
          {
            ModelType::RemoveAllSkinModelBindings(v11);
            this->mFirstResourceLoad = 1;
          }
        }
        mRequest = v8->mRequest;
        if ( mRequest && mRequest->mLoadStatus == Loaded )
        {
          v13 = (char *)UFG::TrueCrowdDataBase::sTrueCrowdDataBase
              + 1292 * this->mMeshLoader.mTrueCrowdInstance.mSet->mEntityIndex;
          UFG::StreamedResourceComponent::BindModelResource(
            this,
            composite_drawable,
            i,
            v8,
            (const unsigned int *)&v13[80 * i + 1016],
            *(_DWORD *)&v13[80 * i + 1080]);
        }
      }
    }
  }
  mPartCount = this->mPartLoader.mPartCount;
  if ( mPartCount )
  {
    do
    {
      Part = UFG::PartLoader::GetPart(&this->mPartLoader, v3);
      UFG::StreamedResourceComponent::BindPart(this, composite_drawable, Part, v3++);
    }
    while ( v3 < mPartCount );
  }
  UFG::StreamedResourceComponent::RefreshRenderState(this, composite_drawable);
}

// File Line: 1039
// RVA: 0x43B780
void __fastcall UFG::StreamedResourceComponent::DispatchResourceEvent(
        UFG::StreamedResourceComponent *this,
        UFG::ResourceRequest *request,
        bool loaded)
{
  UFG::SimObjectGame *m_pSimObject; // rbx
  const char *v4; // r14
  int v8; // ebp
  unsigned int mResourceCount; // r8d
  unsigned int v10; // edx
  UFG::ResourceRequest **mResourceRequests; // rcx
  __int16 m_Flags; // cx
  UFG::CompositeDrawableComponent *m_pComponent; // rdi
  UFG::SimComponent *v14; // rax
  __int16 v15; // cx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  bool v17; // zf
  bool v18; // al
  __int16 v19; // cx
  UFG::SimComponentHolder *p; // rdx
  UFG::SimComponent *v21; // rax
  UFG::SimComponent *v22; // rcx
  bool v23; // dl
  bool v24; // al
  UFG::SceneObjectProperties *m_pSceneObj; // rax
  UFG::qPropertySet *mpWritableProperties; // rcx
  UFG::qPropertySet *v27; // rax
  char *MemImagePtr; // rax
  __int64 v29; // rcx
  __int64 v30; // rdx
  const char *v31; // rax
  unsigned int v32; // eax
  __int16 v33; // cx
  UFG::PhysicsMoverInterface *v34; // rax
  __int16 v35; // cx
  UFG::VehicleEffectsComponent *ComponentOfType; // rax

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  v4 = 0i64;
  v8 = 0;
  if ( loaded )
  {
    if ( !this->mMeshLoader.mPropertySet )
      goto LABEL_9;
    mResourceCount = this->mMeshLoader.mResourceCount;
    if ( mResourceCount )
    {
      v10 = 0;
      mResourceRequests = this->mMeshLoader.mResourceRequests;
      while ( (*mResourceRequests)->mLoadStatus == Loaded )
      {
        ++v10;
        ++mResourceRequests;
        if ( v10 >= mResourceCount )
          goto LABEL_9;
      }
    }
    if ( UFG::PartLoader::IsLoaded(&this->mPartLoader) )
    {
LABEL_9:
      if ( !this->mResourcesBound )
      {
        v8 = 2;
        this->mResourcesBound = 1;
      }
    }
  }
  else if ( this->mResourcesBound )
  {
    v8 = 1;
    this->mResourcesBound = 0;
  }
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::CompositeDrawableComponent *)m_pSimObject->m_Components.p[14].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::CompositeDrawableComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
      }
      else
      {
        v14 = (m_Flags & 0x1000) != 0
            ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::CompositeDrawableComponent::_TypeUID)
            : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CompositeDrawableComponent::_TypeUID);
        m_pComponent = (UFG::CompositeDrawableComponent *)v14;
      }
    }
    else
    {
      m_pComponent = (UFG::CompositeDrawableComponent *)m_pSimObject->m_Components.p[14].m_pComponent;
    }
    if ( m_pComponent )
    {
      if ( v8 == 2 )
      {
        v15 = m_pSimObject->m_Flags;
        if ( (v15 & 0x4000) != 0 )
        {
          ComponentOfTypeHK = m_pSimObject->m_Components.p[9].m_pComponent;
        }
        else if ( v15 >= 0 )
        {
          if ( (v15 & 0x2000) != 0 )
          {
            ComponentOfTypeHK = m_pSimObject->m_Components.p[8].m_pComponent;
          }
          else if ( (v15 & 0x1000) != 0 )
          {
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  m_pSimObject,
                                  UFG::BaseAnimationComponent::_TypeUID);
          }
          else
          {
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::BaseAnimationComponent::_TypeUID);
          }
        }
        else
        {
          ComponentOfTypeHK = m_pSimObject->m_Components.p[9].m_pComponent;
        }
        if ( BYTE1(ComponentOfTypeHK[3].vfptr) || (v17 = *(_QWORD *)&ComponentOfTypeHK[1].m_Flags == 0i64, v18 = 0, v17) )
          v18 = 1;
        UFG::StreamedResourceComponent::BindAllModels(this, m_pComponent, v18);
      }
      else if ( v8 == 1 )
      {
        UFG::StreamedResourceComponent::UnbindAllModels(this, m_pComponent);
      }
    }
  }
  v19 = m_pSimObject->m_Flags;
  if ( v19 < 0 )
  {
    if ( v8 == 2 )
    {
      p = m_pSimObject->m_Components.p;
      v21 = p[9].m_pComponent;
      v17 = (v19 & 0x4000) == 0;
      v22 = 0i64;
      if ( v17 )
        v22 = p[34].m_pComponent;
      v23 = v21 && (BYTE1(v21[3].vfptr) || !*(_QWORD *)&v21[1].m_Flags);
      v24 = v22 && BYTE2(v22[14].m_SafePointerList.mNode.mNext);
      if ( v23 || v24 )
      {
        m_pSceneObj = m_pSimObject->m_pSceneObj;
        mpWritableProperties = m_pSceneObj->mpWritableProperties;
        if ( !mpWritableProperties )
          mpWritableProperties = m_pSceneObj->mpConstProperties;
        v27 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                mpWritableProperties,
                (UFG::qArray<unsigned long,0> *)&component_BaseAnimation::sPropertyName,
                DEPTH_RECURSE);
        if ( v27 )
          MemImagePtr = UFG::qPropertySet::GetMemImagePtr(v27);
        else
          MemImagePtr = 0i64;
        v29 = *((_QWORD *)MemImagePtr + 1);
        if ( v29 )
          v4 = &MemImagePtr[v29 + 8];
        if ( this->mMeshLoader.mHighDefinition )
        {
          v30 = *((_QWORD *)MemImagePtr + 4);
          if ( v30 )
          {
            v31 = &MemImagePtr[v30 + 32];
            if ( v31 )
            {
              if ( *v31 )
                v4 = v31;
            }
          }
        }
        v32 = UFG::qStringHashUpper32(v4, -1);
        if ( UFG::qResourceInventory::Get(&UFG::gRigInventory, v32) )
          UFG::StreamedResourceComponent::SwapVehicleRig(m_pSimObject);
      }
    }
    else if ( !v8 )
    {
      return;
    }
    v33 = m_pSimObject->m_Flags;
    if ( (v33 & 0x4000) != 0 )
      goto LABEL_80;
    if ( v33 >= 0 )
    {
      if ( (v33 & 0x2000) != 0 )
      {
LABEL_80:
        v35 = m_pSimObject->m_Flags;
        if ( (v35 & 0x4000) != 0 )
          goto LABEL_86;
        if ( v35 < 0 )
        {
          ComponentOfType = (UFG::VehicleEffectsComponent *)m_pSimObject->m_Components.p[32].m_pComponent;
          goto LABEL_88;
        }
        if ( (v35 & 0x2000) != 0 || (v35 & 0x1000) != 0 )
LABEL_86:
          ComponentOfType = (UFG::VehicleEffectsComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                              m_pSimObject,
                                                              UFG::VehicleEffectsComponent::_TypeUID);
        else
          ComponentOfType = (UFG::VehicleEffectsComponent *)UFG::SimObject::GetComponentOfType(
                                                              m_pSimObject,
                                                              UFG::VehicleEffectsComponent::_TypeUID);
LABEL_88:
        if ( ComponentOfType )
          UFG::VehicleEffectsComponent::HandleResourceLoadedEvent(ComponentOfType, request, loaded);
        return;
      }
      if ( (v33 & 0x1000) != 0 )
        v34 = (UFG::PhysicsMoverInterface *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                              m_pSimObject,
                                              UFG::PhysicsMoverInterface::_TypeUID);
      else
        v34 = (UFG::PhysicsMoverInterface *)UFG::SimObject::GetComponentOfType(
                                              m_pSimObject,
                                              UFG::PhysicsMoverInterface::_TypeUID);
    }
    else
    {
      v34 = (UFG::PhysicsMoverInterface *)m_pSimObject->m_Components.p[34].m_pComponent;
    }
    if ( v34 )
      UFG::PhysicsMoverInterface::HandleResourceLoadedEvent(v34, request, loaded);
    goto LABEL_80;
  }
}

// File Line: 1128
// RVA: 0x43FAD0
void __fastcall UFG::StreamedResourceComponent::OnPartLoadEventCallback(
        UFG::StreamedResourceComponent *context,
        UFG::PartRequest *request,
        bool loaded)
{
  if ( context )
    UFG::StreamedResourceComponent::DispatchPartEvent(context, request, loaded);
}

// File Line: 1147
// RVA: 0x43B2B0
void __fastcall UFG::StreamedResourceComponent::DispatchPartEvent(
        UFG::StreamedResourceComponent *this,
        UFG::PartRequest *request,
        bool loaded)
{
  UFG::SimObjectGame *m_pSimObject; // r14
  bool v5; // r12
  int v6; // ebp
  UFG::SimObjectGame *v7; // rcx
  UFG::SimComponent *m_pComponent; // rbx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::RigResource *v11; // rdi
  UFG::allocator::free_link *v12; // rax
  Creature *v13; // rax
  UFG::SimObject *v14; // rdi
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  UFG::SimObjectGame *v16; // rcx
  __int16 v17; // dx
  UFG::CompositeDrawableComponent *v18; // rcx
  UFG::SimComponent *v19; // rax
  UFG::SimObjectGame *v20; // rcx
  __int16 v21; // dx
  UFG::SimComponent *ComponentOfType; // rax
  unsigned int mPartCount; // r15d
  unsigned int i; // ebp
  UFG::qReflectObject *mData; // rdi
  unsigned int j; // ebx
  __int64 v27; // rcx
  __int16 v28; // cx
  UFG::CompositeDrawableComponent *v29; // rbx
  UFG::SimComponent *v30; // rax
  __int16 v31; // cx
  UFG::SimComponent *v32; // rax
  __int16 v33; // cx
  UFG::AIOutlineComponent *v34; // rax
  int v35; // [rsp+80h] [rbp+18h]

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
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
  if ( UFG::PartLoader::IsLoaded(&this->mPartLoader) && !this->mPartsBound )
  {
    v6 = 2;
    this->mPartsBound = 1;
LABEL_7:
    v35 = v6;
  }
LABEL_8:
  v7 = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( v7 )
  {
    m_Flags = v7->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = v7->m_Components.p[9].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = v7->m_Components.p[8].m_pComponent;
      }
      else
      {
        if ( (m_Flags & 0x1000) != 0 )
          ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::BaseAnimationComponent::_TypeUID);
        else
          ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v7, UFG::BaseAnimationComponent::_TypeUID);
        m_pComponent = ComponentOfTypeHK;
      }
    }
    else
    {
      m_pComponent = v7->m_Components.p[9].m_pComponent;
    }
  }
  else
  {
    m_pComponent = 0i64;
  }
  v11 = *(UFG::RigResource **)&m_pComponent[1].m_Flags;
  if ( v11 && !*(_QWORD *)&m_pComponent[2].m_TypeUID )
  {
    v12 = UFG::qMalloc(0x3A0ui64, "BaseAnimationComponent.mCreature", 0i64);
    if ( v12 )
      Creature::Creature((Creature *)v12, v11);
    else
      v13 = 0i64;
    *(_QWORD *)&m_pComponent[2].m_TypeUID = v13;
    v14 = this->m_pSimObject;
    if ( v14 )
    {
      m_pTransformNodeComponent = v14->m_pTransformNodeComponent;
      if ( m_pTransformNodeComponent )
      {
        Creature::SetTransformNodeComponentRoot(v13, m_pTransformNodeComponent);
        UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
        Creature::SetTransform(*(Creature **)&m_pComponent[2].m_TypeUID, &m_pTransformNodeComponent->mWorldTransform);
      }
    }
    v16 = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v16 )
    {
      v17 = v16->m_Flags;
      if ( (v17 & 0x4000) != 0 )
      {
        v18 = (UFG::CompositeDrawableComponent *)v16->m_Components.p[14].m_pComponent;
      }
      else if ( v17 >= 0 )
      {
        if ( (v17 & 0x2000) != 0 )
        {
          v18 = (UFG::CompositeDrawableComponent *)v16->m_Components.p[9].m_pComponent;
        }
        else
        {
          v19 = (v17 & 0x1000) != 0
              ? UFG::SimObjectGame::GetComponentOfTypeHK(v16, UFG::CompositeDrawableComponent::_TypeUID)
              : UFG::SimObject::GetComponentOfType(v16, UFG::CompositeDrawableComponent::_TypeUID);
          v18 = (UFG::CompositeDrawableComponent *)v19;
        }
      }
      else
      {
        v18 = (UFG::CompositeDrawableComponent *)v16->m_Components.p[14].m_pComponent;
      }
      if ( v18 )
      {
        v18->mPose = (SkeletalPose *)(*(_QWORD *)&m_pComponent[2].m_TypeUID + 240i64);
        UFG::CompositeDrawableComponent::SetRig(v18, HIDWORD(m_pComponent[3].vfptr));
      }
    }
    v20 = (UFG::SimObjectGame *)this->m_pSimObject;
    if ( v20 )
    {
      v21 = v20->m_Flags;
      if ( (v21 & 0x4000) != 0 || v21 < 0 || (v21 & 0x2000) != 0 || (v21 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v20, Render::FXSimComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v20, Render::FXSimComponent::_TypeUID);
      if ( ComponentOfType )
        *(_QWORD *)&ComponentOfType[1].m_Flags = *(_QWORD *)&m_pComponent[2].m_TypeUID + 240i64;
    }
  }
  if ( v6 == 2 && this->mPartsBound )
  {
    mPartCount = this->mPartLoader.mPartCount;
    for ( i = 0; i < mPartCount; ++i )
    {
      mData = UFG::PartLoader::GetPart(&this->mPartLoader, i)->mModelAsset.mData;
      for ( j = 0; j < LODWORD(mData[2].mHandles.mNode.mPrev); ++j )
      {
        v27 = *(_QWORD *)(mData[2].mTypeUID + 8i64 * j);
        (*(void (__fastcall **)(__int64, UFG::SimObject *, UFG::qReflectObject *))(*(_QWORD *)v27 + 24i64))(
          v27,
          this->m_pSimObject,
          mData);
      }
    }
    v6 = v35;
  }
  if ( m_pSimObject )
  {
    v28 = m_pSimObject->m_Flags;
    if ( (v28 & 0x4000) != 0 )
    {
      v29 = (UFG::CompositeDrawableComponent *)m_pSimObject->m_Components.p[14].m_pComponent;
    }
    else if ( v28 >= 0 )
    {
      if ( (v28 & 0x2000) != 0 )
      {
        v29 = (UFG::CompositeDrawableComponent *)m_pSimObject->m_Components.p[9].m_pComponent;
      }
      else
      {
        if ( (v28 & 0x1000) != 0 )
          v30 = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::CompositeDrawableComponent::_TypeUID);
        else
          v30 = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::CompositeDrawableComponent::_TypeUID);
        v29 = (UFG::CompositeDrawableComponent *)v30;
      }
    }
    else
    {
      v29 = (UFG::CompositeDrawableComponent *)m_pSimObject->m_Components.p[14].m_pComponent;
    }
    if ( v29 )
    {
      if ( v6 == 2 )
      {
        v31 = m_pSimObject->m_Flags;
        if ( (v31 & 0x4000) != 0 )
        {
          v32 = m_pSimObject->m_Components.p[9].m_pComponent;
        }
        else if ( v31 >= 0 )
        {
          if ( (v31 & 0x2000) != 0 )
          {
            v32 = m_pSimObject->m_Components.p[8].m_pComponent;
          }
          else if ( (v31 & 0x1000) != 0 )
          {
            v32 = UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::BaseAnimationComponent::_TypeUID);
          }
          else
          {
            v32 = UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::BaseAnimationComponent::_TypeUID);
          }
        }
        else
        {
          v32 = m_pSimObject->m_Components.p[9].m_pComponent;
        }
        if ( BYTE1(v32[3].vfptr) || !*(_QWORD *)&v32[1].m_Flags )
          v5 = 1;
        UFG::StreamedResourceComponent::BindAllModels(this, v29, v5);
      }
      else if ( v6 == 1 )
      {
        UFG::StreamedResourceComponent::UnbindAllModels(this, v29);
      }
    }
    v33 = m_pSimObject->m_Flags;
    if ( (v33 & 0x4000) != 0 )
      goto LABEL_92;
    if ( v33 < 0 )
    {
      v34 = (UFG::AIOutlineComponent *)m_pSimObject->m_Components.p[27].m_pComponent;
      goto LABEL_94;
    }
    if ( (v33 & 0x2000) != 0 || (v33 & 0x1000) != 0 )
LABEL_92:
      v34 = (UFG::AIOutlineComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                         m_pSimObject,
                                         UFG::AIOutlineComponent::_TypeUID);
    else
      v34 = (UFG::AIOutlineComponent *)UFG::SimObject::GetComponentOfType(
                                         m_pSimObject,
                                         UFG::AIOutlineComponent::_TypeUID);
LABEL_94:
    if ( v34 )
    {
      if ( v6 == 2 )
        UFG::AIOutlineComponent::Init(v34);
    }
  }
}tOfType(
                                         m_pSimObject,
 

// File Line: 1248
// RVA: 0x43D0D0
UFG::qPropertySet *__fastcall UFG::StreamedResourceComponent::GetAssetPropertySet(
        UFG::StreamedResourceComponent *this,
        UFG::qArray<unsigned long,0> *propName)
{
  UFG::TrueCrowdSet::Instance *p_mTrueCrowdInstance; // rdi
  int v3; // ebx
  __int64 mModelIndex; // rcx
  UFG::qPropertySet *mPropSet; // rcx
  UFG::qPropertySet *result; // rax

  p_mTrueCrowdInstance = &this->mMeshLoader.mTrueCrowdInstance;
  v3 = 0;
  if ( !this->mMeshLoader.mTrueCrowdInstance.mNumParts )
    return 0i64;
  while ( 1 )
  {
    mModelIndex = p_mTrueCrowdInstance->mPart[v3].mModelIndex;
    if ( (_DWORD)mModelIndex != -1 )
    {
      mPropSet = p_mTrueCrowdInstance->mSet->mFiles[v3].p[mModelIndex]->mPropSet;
      if ( mPropSet )
      {
        result = UFG::qPropertySet::Get<UFG::qPropertySet>(mPropSet, propName, DEPTH_RECURSE);
        if ( result )
          break;
      }
    }
    if ( ++v3 >= p_mTrueCrowdInstance->mNumParts )
      return 0i64;
  }
  return result;
}

// File Line: 1270
// RVA: 0x443550
void __fastcall UFG::StreamedResourceComponent::SwapResource(
        UFG::StreamedResourceComponent *this,
        unsigned int componentIndex,
        UFG::qSymbol *modelPathSymbol,
        UFG::qSymbol *textureSetPathSymbol,
        unsigned int *colourTintIndex)
{
  UFG::TrueCrowdSet *mSet; // rdi
  UFG::qColour *v7; // rbx
  unsigned __int64 v8; // r9
  unsigned int mModelIndex; // eax
  __int64 v10; // r14
  UFG::StreamPriorityHandle *v11; // r12
  UFG::TrueCrowdModel *ModelFromPath; // rsi
  UFG::qSymbol *v13; // rcx
  UFG::qSymbol *v14; // rax
  unsigned int mUID; // eax
  char *v16; // r13
  unsigned int v17; // ecx
  __int64 v18; // r8
  __int64 v19; // r9
  __int64 v20; // rax
  __int64 v21; // rdx
  __int64 v22; // rax
  __int64 v23; // rax
  char *v24; // rdx
  char *v25; // r8
  __int64 mOffset; // rax
  _QWORD *v27; // rax
  unsigned int v28; // ecx
  __int64 v29; // rdx
  char *v30; // rdx
  __int64 v31; // rcx
  UFG::qArray<UFG::TrueCrowdModel *,0> *v32; // rdi
  __int64 size; // rbp
  unsigned int capacity; // edx
  unsigned int v35; // ebx
  unsigned int v36; // edx
  UFG::TrueCrowdModel **p; // rax
  __int64 v38; // [rsp+20h] [rbp-58h]
  UFG::StreamPriorityHandle *item; // [rsp+28h] [rbp-50h] BYREF
  __int64 v40; // [rsp+30h] [rbp-48h]
  __int64 v41; // [rsp+38h] [rbp-40h]

  if ( !this->mMeshLoader.mHighDefinition )
  {
    mSet = this->mMeshLoader.mTrueCrowdInstance.mSet;
    v7 = 0i64;
    v8 = componentIndex;
    mModelIndex = this->mMeshLoader.mTrueCrowdInstance.mPart[v8].mModelIndex;
    v38 = componentIndex;
    v10 = componentIndex;
    v40 = v8 * 16;
    HIDWORD(v41) = 0;
    v11 = 0i64;
    item = 0i64;
    if ( mModelIndex != -1 )
    {
      v11 = (UFG::StreamPriorityHandle *)mSet->mFiles[v8].p[mModelIndex];
      item = v11;
    }
    ModelFromPath = (UFG::TrueCrowdModel *)v11;
    v13 = &UFG::gNullQSymbol;
    v14 = (UFG::qSymbol *)&v11->mHandle.mCallbackParam + 1;
    if ( !v11 )
      v14 = &UFG::gNullQSymbol;
    mUID = v14->mUID;
    if ( modelPathSymbol )
      v13 = modelPathSymbol;
    if ( v13->mUID != mUID )
    {
      ModelFromPath = 0i64;
      if ( modelPathSymbol )
      {
        if ( modelPathSymbol->mUID != UFG::gNullQSymbol.mUID )
          ModelFromPath = UFG::TrueCrowdDataBase::QueryModelFromPath(
                            UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
                            mSet->mEntityIndex,
                            componentIndex,
                            modelPathSymbol);
      }
    }
    v16 = 0i64;
    *(_WORD *)&mSet->mComponentDetails[v10].mbSpecificModel = 1;
    mSet->mComponentDetails[v10].mbColourTintIndexValid = 0;
    if ( ModelFromPath )
    {
      LODWORD(v41) = 0;
      if ( !textureSetPathSymbol || textureSetPathSymbol->mUID == UFG::gNullQSymbol.mUID )
      {
        if ( ModelFromPath->mNumTextureSets )
        {
          mOffset = ModelFromPath->mTextureSets.mOffset;
          if ( mOffset )
            v27 = (__int64 *)((char *)&ModelFromPath->mTextureSets.mOffset + mOffset);
          else
            v27 = 0i64;
          if ( *v27 )
            v16 = (char *)v27 + *v27;
          HIDWORD(v41) = 0;
          mSet->mComponentDetails[v10].mTextureSetIndex = 0;
          mSet->mComponentDetails[v10].mbTextureSetIndexValid = 1;
        }
      }
      else
      {
        v17 = 0;
        if ( ModelFromPath->mNumTextureSets )
        {
          v18 = ModelFromPath->mTextureSets.mOffset;
          v19 = 0i64;
          while ( 1 )
          {
            v20 = v18 ? (__int64)&ModelFromPath->mTextureSets + v18 : 0i64;
            v21 = v19 + v20;
            v22 = *(_QWORD *)(v19 + v20);
            v23 = v22 ? v21 + v22 : 0i64;
            if ( *(_DWORD *)(v23 + 28) == textureSetPathSymbol->mUID )
              break;
            ++v17;
            v19 += 8i64;
            if ( v17 >= ModelFromPath->mNumTextureSets )
              goto LABEL_40;
          }
          if ( v18 )
            v24 = (char *)&ModelFromPath->mTextureSets + v18;
          else
            v24 = 0i64;
          v25 = &v24[8 * v17];
          if ( *(_QWORD *)v25 )
            v16 = &v25[*(_QWORD *)v25];
          HIDWORD(v41) = v17;
          mSet->mComponentDetails[v10].mTextureSetIndex = v17;
          mSet->mComponentDetails[v10].mbTextureSetIndexValid = 1;
        }
      }
    }
    else
    {
      LODWORD(v41) = -1;
    }
LABEL_40:
    if ( v11 && v11 != (UFG::StreamPriorityHandle *)ModelFromPath )
      UFG::qArray<UFG::StreamPriorityHandle *,0>::Erase(
        (UFG::qArray<UFG::StreamPriorityHandle *,0> *)&this->mMeshLoader.mTrueCrowdInstance.mSet->mFiles[v38],
        &item);
    if ( v16 )
    {
      if ( colourTintIndex )
        v28 = *colourTintIndex;
      else
        v28 = 0;
      if ( *((_DWORD *)v16 + 18) )
      {
        v29 = *((_QWORD *)v16 + 7);
        if ( v29 )
          v30 = &v16[v29 + 56];
        else
          v30 = 0i64;
        v7 = (UFG::qColour *)&v30[16 * v28];
      }
      if ( colourTintIndex )
      {
        mSet->mComponentDetails[v10].mbColourTintIndexValid = 1;
        mSet->mComponentDetails[v10].mColourTintIndex = v28;
      }
    }
    v31 = v40;
    *(_QWORD *)((char *)&this->mMeshLoader.mTrueCrowdInstance.mPart[0].mModelIndex + v40) = v41;
    *(UFG::qColour **)((char *)&this->mMeshLoader.mTrueCrowdInstance.mPart[0].mColourTint + v31) = v7;
    if ( ModelFromPath && v11 != (UFG::StreamPriorityHandle *)ModelFromPath )
    {
      v32 = &this->mMeshLoader.mTrueCrowdInstance.mSet->mFiles[v38];
      size = v32->size;
      capacity = v32->capacity;
      v35 = size + 1;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v36 = 2 * capacity;
        else
          v36 = 1;
        for ( ; v36 < v35; v36 *= 2 )
          ;
        if ( v36 <= 2 )
          v36 = 2;
        if ( v36 - v35 > 0x10000 )
          v36 = size + 65537;
        UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(
          (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mMeshLoader.mTrueCrowdInstance.mSet->mFiles[v38],
          v36,
          "qArray.Add");
      }
      p = v32->p;
      v32->size = v35;
      p[size] = ModelFromPath;
    }
  }
}

// File Line: 1420
// RVA: 0x436660
void __fastcall UFG::AttachmentRecord::AttachmentRecord(UFG::AttachmentRecord *this)
{
  `eh vector constructor iterator(this->mRegularAttachment, 4ui64, 10, (void (__fastcall *)(void *))BackInfo::BackInfo);
  `eh vector constructor iterator(
    this->mEffectorAttachment,
    0xCui64,
    10,
    (void (__fastcall *)(void *))UFG::EffectorAttachmentInfo::EffectorAttachmentInfo);
  this->mNumRegularAttachments = 0;
  this->mNumEffectorAttachments = 0;
}

// File Line: 1424
// RVA: 0x443880
void __fastcall UFG::StreamedResourceComponent::SwapVehicleRig(UFG::SimObjectGame *pUpgradingObject)
{
  UFG::SimObjectGame *v1; // rbp
  unsigned int v2; // r15d
  unsigned int v3; // r13d
  __int16 m_Flags; // cx
  UFG::VehicleOccupantComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 v7; // cx
  UFG::SimComponent *v8; // rsi
  UFG::SimComponent *ComponentOfType; // rax
  UFG::SimObject *Occupant; // rax
  UFG::SimObjectCVBase *v11; // rdi
  __int64 v12; // r13
  UFG::SimComponent *v13; // rax
  unsigned __int64 v14; // r12
  UFG::CharacterAnimationComponent *v15; // rax
  unsigned int v16; // esi
  __int64 v17; // rbx
  __int64 v18; // rbp
  int v19; // ecx
  _QWORD *v20; // r14
  __int64 v21; // rcx
  __int64 v22; // rsi
  __int64 v23; // rbx
  __int64 v24; // rdi
  unsigned int v25; // r12d
  int *v26; // rdi
  unsigned int i; // esi
  UFG::qSymbolUC *v28; // rax
  unsigned int j; // ebx
  UFG::SimComponent *v30; // rdi
  UFG::SimComponent *v31; // rbx
  UFG::CompositeDrawableComponent *v32; // r12
  __int16 v33; // cx
  UFG::SimComponent *v34; // rax
  __int16 v35; // cx
  UFG::SimComponent *v36; // rax
  __int16 v37; // cx
  UFG::SimComponent *v38; // rax
  __int16 v39; // cx
  UFG::StreamedResourceComponent *v40; // rax
  UFG::SimComponent *v41; // rsi
  unsigned int v42; // r14d
  int *v43; // rdi
  unsigned int k; // esi
  UFG::qSymbolUC *v45; // rax
  unsigned int m; // ebx
  UFG::SimComponent *v47; // [rsp+90h] [rbp-7C8h]
  UFG::VehicleOccupantComponent *v48; // [rsp+98h] [rbp-7C0h]
  __int64 v49; // [rsp+A0h] [rbp-7B8h]
  UFG::qWiseSymbol v50; // [rsp+A8h] [rbp-7B0h] BYREF
  UFG::qWiseSymbol v51; // [rsp+ACh] [rbp-7ACh] BYREF
  __int64 v52; // [rsp+B0h] [rbp-7A8h]
  __int64 ptr[2]; // [rsp+C0h] [rbp-798h] BYREF
  int v54[456]; // [rsp+D0h] [rbp-788h] BYREF
  UFG::SimObject *v55; // [rsp+860h] [rbp+8h] BYREF
  UFG::StreamedResourceComponent *v56; // [rsp+868h] [rbp+10h]
  int v57; // [rsp+870h] [rbp+18h]
  UFG::qWiseSymbol result; // [rsp+878h] [rbp+20h] BYREF

  v55 = pUpgradingObject;
  v52 = -2i64;
  v1 = pUpgradingObject;
  `eh vector constructor iterator(
    ptr,
    0xB8ui64,
    10,
    (void (__fastcall *)(void *))UFG::AttachmentRecord::AttachmentRecord);
  v2 = 0;
  v3 = 0;
  LODWORD(v56) = 0;
  if ( !v1 )
  {
    v47 = 0i64;
    goto LABEL_45;
  }
  m_Flags = v1->m_Flags;
  if ( (m_Flags & 0x4000) != 0 )
    goto LABEL_8;
  if ( m_Flags < 0 )
  {
    m_pComponent = (UFG::VehicleOccupantComponent *)v1->m_Components.p[30].m_pComponent;
    goto LABEL_11;
  }
  if ( (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
LABEL_8:
    ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::VehicleOccupantComponent::_TypeUID);
  else
    ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(v1, UFG::VehicleOccupantComponent::_TypeUID);
  m_pComponent = (UFG::VehicleOccupantComponent *)ComponentOfTypeHK;
LABEL_11:
  v48 = m_pComponent;
  v7 = v1->m_Flags;
  if ( (v7 & 0x4000) != 0 )
  {
    v8 = v1->m_Components.p[9].m_pComponent;
  }
  else if ( v7 >= 0 )
  {
    if ( (v7 & 0x2000) != 0 )
    {
      v8 = v1->m_Components.p[8].m_pComponent;
    }
    else
    {
      if ( (v7 & 0x1000) != 0 )
        ComponentOfType = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::BaseAnimationComponent::_TypeUID);
      else
        ComponentOfType = UFG::SimObject::GetComponentOfType(v1, UFG::BaseAnimationComponent::_TypeUID);
      v8 = ComponentOfType;
    }
  }
  else
  {
    v8 = v1->m_Components.p[9].m_pComponent;
  }
  v47 = v8;
  if ( m_pComponent && (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(m_pComponent) )
  {
    do
    {
      if ( v3 >= 0xA )
        break;
      Occupant = UFG::VehicleOccupantComponent::GetOccupant(m_pComponent, v3, 0i64);
      v11 = (UFG::SimObjectCVBase *)Occupant;
      v12 = *(_QWORD *)&v8[2].m_TypeUID;
      if ( Occupant )
        v13 = Occupant->m_Components.p[9].m_pComponent;
      else
        v13 = 0i64;
      v49 = *(_QWORD *)&v13[2].m_TypeUID;
      v14 = 46i64 * (unsigned int)v56;
      ptr[v14 / 2] = (__int64)v11;
      if ( v11 )
        v15 = UFG::SimObjectCVBase::GetComponent<UFG::CharacterAnimationComponent>(v11);
      else
        v15 = 0i64;
      ptr[v14 / 2 + 1] = (__int64)v15;
      v16 = 0;
      v17 = *(_QWORD *)(v12 + 184) - 8i64;
      if ( v17 != v12 + 168 )
      {
        v18 = (unsigned int)v56;
        do
        {
          if ( *(UFG::SimObjectCVBase **)(v17 + 104) == v11 )
            v54[46 * v18 + 1 + v16++] = UFG::qSymbol::qSymbol(
                                          &result,
                                          *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v12 + 480) + 24i64)
                                                    + 4i64 * *(int *)(v17 + 32)))->mUID;
          v17 = *(_QWORD *)(v17 + 16) - 8i64;
        }
        while ( v17 != v12 + 168 );
        v1 = (UFG::SimObjectGame *)v55;
      }
      v54[v14] = v16;
      v19 = 0;
      v20 = (_QWORD *)(*(_QWORD *)(v49 + 184) - 8i64);
      if ( v20 != (_QWORD *)(v49 + 168) )
      {
        v21 = v49;
        do
        {
          if ( (UFG::SimObjectGame *)v20[13] == v1 )
          {
            v22 = v14 * 4 + 12i64 * v2;
            *(int *)((char *)&v54[12] + v22) = *(_DWORD *)((*(__int64 (__fastcall **)(_QWORD *))(*v20 + 48i64))(v20) + 44);
            v23 = (*(int (__fastcall **)(_QWORD *))(*v20 + 56i64))(v20);
            v24 = (*(int (__fastcall **)(_QWORD *))(*v20 + 64i64))(v20);
            *(int *)((char *)&v54[13] + v22) = UFG::qSymbol::qSymbol(
                                                 &v51,
                                                 *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v12 + 480) + 24i64) + 4 * v23))->mUID;
            *(int *)((char *)&v54[14] + v22) = UFG::qSymbol::qSymbol(
                                                 &v50,
                                                 *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v12 + 480) + 24i64) + 4 * v24))->mUID;
            ++v2;
            v21 = v49;
          }
          v20 = (_QWORD *)(v20[2] - 8i64);
        }
        while ( v20 != (_QWORD *)(v21 + 168) );
        v57 = v2;
        v2 = 0;
        v19 = v57;
      }
      v54[v14 + 11] = v19;
      LODWORD(v56) = (_DWORD)v56 + 1;
      v3 = (unsigned int)v56;
      m_pComponent = v48;
      v8 = v47;
    }
    while ( v3 < (unsigned int)UFG::VehicleOccupantComponent::GetNumberOfOccupants(v48) );
  }
LABEL_45:
  v25 = 0;
  if ( v3 )
  {
    v26 = v54;
    do
    {
      for ( i = 0; i < *v26; ++i )
      {
        v28 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&v55, qSymbol_SYNC01.mUID);
        UFG::TargetDetach(
          *((UFG::SimObject **)v26 - 2),
          eTARGET_TYPE_VEHICLE,
          0i64,
          v28,
          (UFG::qSymbolUC *)&v54[46 * v25 + 1 + i],
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
      for ( j = 0; j < v26[11]; ++j )
        UFG::TargetDetachEffector(
          *((UFG::SimObject **)v26 - 2),
          *((UFG::CharacterAnimationComponent **)v26 - 1),
          eTARGET_TYPE_VEHICLE,
          (UFG::qSymbolUC *)&v54[46 * v25 + 12 + 3 * j],
          0.0);
      ++v25;
      v26 += 46;
    }
    while ( v25 < v3 );
  }
  if ( v1 )
  {
    v33 = v1->m_Flags;
    if ( (v33 & 0x4000) != 0 || v33 < 0 || (v33 & 0x2000) != 0 || (v33 & 0x1000) != 0 )
      v34 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::RigidBodyComponent::_TypeUID);
    else
      v34 = UFG::SimObject::GetComponentOfType(v1, UFG::RigidBodyComponent::_TypeUID);
    v30 = v34;
    v35 = v1->m_Flags;
    if ( (v35 & 0x4000) != 0 )
    {
      v31 = 0i64;
    }
    else if ( v35 >= 0 )
    {
      if ( (v35 & 0x2000) != 0 )
      {
        v31 = 0i64;
      }
      else
      {
        if ( (v35 & 0x1000) != 0 )
          v36 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::PhysicsMoverInterface::_TypeUID);
        else
          v36 = UFG::SimObject::GetComponentOfType(v1, UFG::PhysicsMoverInterface::_TypeUID);
        v31 = v36;
      }
    }
    else
    {
      v31 = v1->m_Components.p[34].m_pComponent;
    }
    v37 = v1->m_Flags;
    if ( (v37 & 0x4000) != 0 )
    {
      v32 = (UFG::CompositeDrawableComponent *)v1->m_Components.p[14].m_pComponent;
    }
    else if ( v37 >= 0 )
    {
      if ( (v37 & 0x2000) != 0 )
      {
        v32 = (UFG::CompositeDrawableComponent *)v1->m_Components.p[9].m_pComponent;
      }
      else
      {
        if ( (v37 & 0x1000) != 0 )
          v38 = UFG::SimObjectGame::GetComponentOfTypeHK(v1, UFG::CompositeDrawableComponent::_TypeUID);
        else
          v38 = UFG::SimObject::GetComponentOfType(v1, UFG::CompositeDrawableComponent::_TypeUID);
        v32 = (UFG::CompositeDrawableComponent *)v38;
      }
    }
    else
    {
      v32 = (UFG::CompositeDrawableComponent *)v1->m_Components.p[14].m_pComponent;
    }
    v39 = v1->m_Flags;
    if ( (v39 & 0x4000) != 0 )
    {
      v40 = (UFG::StreamedResourceComponent *)v1->m_Components.p[10].m_pComponent;
    }
    else if ( v39 >= 0 )
    {
      if ( (v39 & 0x2000) != 0 )
      {
        v40 = (UFG::StreamedResourceComponent *)v1->m_Components.p[7].m_pComponent;
      }
      else if ( (v39 & 0x1000) != 0 )
      {
        v40 = (UFG::StreamedResourceComponent *)UFG::SimObjectGame::GetComponentOfTypeHK(
                                                  v1,
                                                  UFG::StreamedResourceComponent::_TypeUID);
      }
      else
      {
        v40 = (UFG::StreamedResourceComponent *)UFG::SimObject::GetComponentOfType(
                                                  v1,
                                                  UFG::StreamedResourceComponent::_TypeUID);
      }
    }
    else
    {
      v40 = (UFG::StreamedResourceComponent *)v1->m_Components.p[10].m_pComponent;
    }
    v56 = v40;
  }
  else
  {
    v30 = 0i64;
    v31 = 0i64;
    v32 = 0i64;
    v56 = 0i64;
  }
  v41 = v47;
  if ( v47 )
    ((void (__fastcall *)(UFG::SimComponent *))v47->vfptr[17].__vecDelDtor)(v47);
  if ( v32 )
    UFG::CompositeDrawableComponent::ResetModelType(v32);
  if ( v30 )
  {
    ((void (__fastcall *)(UFG::SimComponent *))v30->vfptr[10].__vecDelDtor)(v30);
    v30->vfptr[6].__vecDelDtor(v30, (unsigned int)v1);
  }
  if ( v31 )
  {
    ((void (__fastcall *)(UFG::SimComponent *))v31->vfptr[10].__vecDelDtor)(v31);
    v31->vfptr[6].__vecDelDtor(v31, (unsigned int)v1);
  }
  v42 = 0;
  if ( v3 )
  {
    v43 = v54;
    do
    {
      for ( k = 0; k < *v43; ++k )
      {
        v45 = (UFG::qSymbolUC *)UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&v55, qSymbol_SYNC01.mUID);
        UFG::TargetAttach(
          *((UFG::SimObject **)v43 - 2),
          eTARGET_TYPE_VEHICLE,
          0i64,
          0i64,
          v45,
          (UFG::qSymbolUC *)&v54[46 * v42 + 1 + k],
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
      for ( m = 0; m < v43[11]; ++m )
        UFG::TargetAttachEffector(
          *((UFG::SimObject **)v43 - 2),
          *((UFG::CharacterAnimationComponent **)v43 - 1),
          eTARGET_TYPE_VEHICLE,
          (UFG::qSymbolUC *)&v54[46 * v42 + 12 + 3 * m],
          (UFG::qSymbolUC *)&v54[46 * v42 + 13 + 3 * m],
          (UFG::qSymbolUC *)&v54[46 * v42 + 14 + 3 * m],
          0.0,
          0);
      ++v42;
      v43 += 46;
    }
    while ( v42 < v3 );
    v41 = v47;
  }
  if ( BYTE1(v41[3].vfptr) || !*(_QWORD *)&v41[1].m_Flags )
    LOBYTE(v2) = 1;
  UFG::StreamedResourceComponent::BindAllModels(v56, v32, v2);
  `eh vector destructor iterator(
    ptr,
    0xB8ui64,
    10,
    (void (__fastcall *)(void *))UFG::AttachmentRecord::~AttachmentRecord);
}or destructor iterator(
    ptr,
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
void __fastcall UFG::ResourcePriorityLockComponent::ResourcePriorityLockComponent(
        UFG::ResourcePriorityLockComponent *this)
{
  unsigned int v2; // eax

  v2 = UFG::qStringHash32("ResourcePriorityLockComponent", 0xFFFFFFFF);
  UFG::SimComponent::SimComponent(this, v2);
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::ResourcePriorityLockComponent::`vftable;
  UFG::SimComponent::AddType(
    this,
    UFG::ResourcePriorityLockComponent::_ResourcePriorityLockComponentTypeUID,
    "ResourcePriorityLockComponent");
}

// File Line: 1594
// RVA: 0x43F5F0
void __fastcall UFG::ResourcePriorityLockComponent::OnAttach(
        UFG::ResourcePriorityLockComponent *this,
        UFG::SimObjectGame *object)
{
  signed __int16 m_Flags; // cx
  UFG::StreamedResourceComponent *m_pComponent; // r9
  UFG::SimComponent *v4; // rax
  __int64 v5; // rdx
  UFG::qSymbol **i; // r8

  if ( object )
  {
    m_Flags = object->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)object->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)object->m_Components.p[7].m_pComponent;
      }
      else
      {
        v4 = (m_Flags & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(object, UFG::StreamedResourceComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(object, UFG::StreamedResourceComponent::_TypeUID);
        m_pComponent = (UFG::StreamedResourceComponent *)v4;
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)object->m_Components.p[10].m_pComponent;
    }
    if ( m_pComponent )
    {
      v5 = 0i64;
      for ( i = UFG::StreamedResourceComponent::sSpawnPrioritySymbols; qSymbol_Critical.mUID != (*i)->mUID; ++i )
      {
        v5 = (unsigned int)(v5 + 1);
        if ( (unsigned int)v5 >= 4 )
          return;
      }
      ++m_pComponent->mSpawnPriorityReferenceCount[v5];
      UFG::StreamedResourceComponent::UpdateActivePriority(m_pComponent);
    }
  }
}

// File Line: 1603
// RVA: 0x43F8F0
void __fastcall UFG::ResourcePriorityLockComponent::OnDetach(UFG::ResourcePriorityLockComponent *this)
{
  UFG::SimObjectGame *m_pSimObject; // rcx
  __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // r9
  UFG::SimComponent *v4; // rax
  __int64 v5; // rdx
  UFG::qSymbol **i; // r8
  char *v7; // rcx
  int v8; // eax

  m_pSimObject = (UFG::SimObjectGame *)this->m_pSimObject;
  if ( m_pSimObject )
  {
    m_Flags = m_pSimObject->m_Flags;
    if ( (m_Flags & 0x4000) != 0 )
    {
      m_pComponent = (UFG::StreamedResourceComponent *)m_pSimObject->m_Components.p[10].m_pComponent;
    }
    else if ( m_Flags >= 0 )
    {
      if ( (m_Flags & 0x2000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)m_pSimObject->m_Components.p[7].m_pComponent;
      }
      else
      {
        v4 = (m_Flags & 0x1000) != 0
           ? UFG::SimObjectGame::GetComponentOfTypeHK(m_pSimObject, UFG::StreamedResourceComponent::_TypeUID)
           : UFG::SimObject::GetComponentOfType(m_pSimObject, UFG::StreamedResourceComponent::_TypeUID);
        m_pComponent = (UFG::StreamedResourceComponent *)v4;
      }
    }
    else
    {
      m_pComponent = (UFG::StreamedResourceComponent *)m_pSimObject->m_Components.p[10].m_pComponent;
    }
    if ( m_pComponent )
    {
      v5 = 0i64;
      for ( i = UFG::StreamedResourceComponent::sSpawnPrioritySymbols; qSymbol_Critical.mUID != (*i)->mUID; ++i )
      {
        v5 = (unsigned int)(v5 + 1);
        if ( (unsigned int)v5 >= 4 )
          return;
      }
      v7 = (char *)m_pComponent + 4 * v5;
      v8 = *((_DWORD *)v7 + 390);
      if ( v8 )
      {
        *((_DWORD *)v7 + 390) = v8 - 1;
        UFG::StreamedResourceComponent::UpdateActivePriority(m_pComponent);
      }
    }
  }
}

