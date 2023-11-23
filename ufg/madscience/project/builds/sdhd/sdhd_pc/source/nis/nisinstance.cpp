// File Line: 28
// RVA: 0x3DFEB0
void __fastcall NISInstance::NISInstance(NISInstance *this, const char *pathName)
{
  NISNode *v4; // rdi
  ActionNode *v5; // rax
  NISNode *v6; // rsi
  __int64 v7; // rax
  char *v8; // r8
  __int64 v9; // rax
  NISNode *v10; // rsi
  ActionPath absolutePath; // [rsp+28h] [rbp-18h] BYREF
  int v12; // [rsp+80h] [rbp+40h] BYREF
  int v13; // [rsp+88h] [rbp+48h] BYREF

  this->mPrev = &this->UFG::qNode<NISInstance,NISInstanceMasterList>;
  this->mNext = &this->UFG::qNode<NISInstance,NISInstanceMasterList>;
  UFG::qSafePointerNode<NISInstance>::qSafePointerNode<NISInstance>(this);
  this->vfptr = (UFG::qSafePointerNode<NISInstance>Vtbl *)&NISInstance::`vftable;
  this->mSoundbankSymbol.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  AnimationGroupHandle::AnimationGroupHandle(&this->mAnimationGroupHandle);
  AnimationGroupHandle::AnimationGroupHandle(&this->mFacialAnimGroupHandle);
  AnimationGroupHandle::AnimationGroupHandle(&this->mExtraFacialAnimGroupHandle);
  this->mMeshResources.p = 0i64;
  *(_QWORD *)&this->mMeshResources.size = 0i64;
  v4 = 0i64;
  absolutePath.mPath.mData.mOffset = 0i64;
  absolutePath.mPath.mCount = 0;
  ActionPath::Append(&absolutePath, pathName);
  v5 = ActionNode::Find(&absolutePath, 0i64);
  v6 = (NISNode *)v5;
  if ( v5 && v5->vfptr->GetClassNameUID(v5) == NISNode::sClassNameUID )
  {
    v4 = v6;
  }
  else
  {
    v12 = UFG::qStringHashUpper32("NIS", -1);
    v7 = ((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))ActionNode::smRoot->vfptr[1].CreateClone)(
           ActionNode::smRoot,
           &v12,
           0i64);
    if ( v7 )
    {
      v8 = absolutePath.mPath.mData.mOffset
         ? (char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset
         : 0i64;
      v13 = *(_DWORD *)&v8[4 * (absolutePath.mPath.mCount & 0x7FFFFFFF) - 4];
      LOBYTE(v8) = 1;
      v9 = (*(__int64 (__fastcall **)(__int64, int *, char *))(*(_QWORD *)v7 + 96i64))(v7, &v13, v8);
      v10 = (NISNode *)v9;
      if ( v9 )
      {
        if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v9 + 40i64))(v9) == NISNode::sClassNameUID )
          v4 = v10;
      }
    }
  }
  NISInstance::Init(this, v4);
  if ( absolutePath.mPath.mCount >= 0 && absolutePath.mPath.mData.mOffset )
  {
    if ( (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset) )
      operator delete[]((char *)&absolutePath.mPath.mData + absolutePath.mPath.mData.mOffset);
  }
}

// File Line: 64
// RVA: 0x3E0890
void __fastcall NISInstance::~NISInstance(NISInstance *this)
{
  NISNode *mpNISNode; // rbx
  NISLightGroup *mLightGroupObject; // rbx
  UFG::MeshResourceLoader *p; // rcx
  void **p_mUserContext; // rbx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<NISInstance,NISInstanceMasterList> *v8; // rcx
  UFG::qNode<NISInstance,NISInstanceMasterList> *v9; // rax

  this->vfptr = (UFG::qSafePointerNode<NISInstance>Vtbl *)&NISInstance::`vftable;
  NISInstance::Unload(this, 0);
  mpNISNode = this->mpNISNode;
  if ( mpNISNode )
  {
    mLightGroupObject = mpNISNode->mLightGroupObject;
    if ( mLightGroupObject )
    {
      NISLightGroup::~NISLightGroup(mLightGroupObject);
      operator delete[](mLightGroupObject);
      this->mpNISNode->mLightGroupObject = 0i64;
    }
  }
  p = this->mMeshResources.p;
  if ( p )
  {
    p_mUserContext = &p[-1].mUserContext;
    `eh vector destructor iterator(
      p,
      0x1E8ui64,
      (int)p[-1].mUserContext,
      (void (__fastcall *)(void *))UFG::MeshResourceLoader::~MeshResourceLoader);
    operator delete[](p_mUserContext);
  }
  this->mMeshResources.p = 0i64;
  *(_QWORD *)&this->mMeshResources.size = 0i64;
  AnimationGroupHandle::~AnimationGroupHandle(&this->mExtraFacialAnimGroupHandle);
  AnimationGroupHandle::~AnimationGroupHandle(&this->mFacialAnimGroupHandle);
  AnimationGroupHandle::~AnimationGroupHandle(&this->mAnimationGroupHandle);
  _((AMD_HD3D *)this->mSoundbankSymbol.mUID);
  this->vfptr = (UFG::qSafePointerNode<NISInstance>Vtbl *)&UFG::qSafePointerNode<NISInstance>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&this->m_SafePointerList);
  mPrev = this->m_SafePointerList.mNode.UFG::qSafePointerNode<NISInstance>::mPrev;
  mNext = this->m_SafePointerList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->m_SafePointerList.mNode.UFG::qSafePointerNode<NISInstance>::mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
  v8 = this->mPrev;
  v9 = this->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  this->mPrev = &this->UFG::qNode<NISInstance,NISInstanceMasterList>;
  this->mNext = &this->UFG::qNode<NISInstance,NISInstanceMasterList>;
}

// File Line: 77
// RVA: 0x3E2D50
void __fastcall NISInstance::Init(NISInstance *this, NISNode *nisNode)
{
  NISLightGroup *v3; // rbp
  UFG::qVector4 v4; // xmm1
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm3
  NISNode *mpNISNode; // rcx
  const char *v8; // rdx
  UFG::qSymbolUC *v9; // rax
  BinString *p_mFacialAnimGroupName; // rax
  const char *v11; // rbx
  UFG::qSymbolUC *v12; // rax
  BinString *p_mExtraFacialAnimGroupName; // rax
  const char *v14; // rbx
  UFG::qSymbolUC *v15; // rax
  int v16; // eax
  UFG::qArray<UFG::MeshResourceLoader,0> *p_mMeshResources; // rsi
  unsigned int size; // ecx
  int v19; // eax
  unsigned int v20; // ebx
  unsigned int capacity; // edx
  unsigned int v22; // edx
  unsigned int v23; // eax
  UFG::allocator::free_link *v24; // rax
  BinString *p_mAnimationGroupName; // rcx
  const char *v26; // rdx
  NISLightGroup *v27; // rax
  UFG::allocator::free_link *result; // [rsp+50h] [rbp+8h] BYREF

  v3 = 0i64;
  this->mStatus = eSTATUS_INVALID;
  this->mpNISNode = nisNode;
  UFG::qWiseSymbol::set_null(&this->mSoundbankSymbol);
  *(_WORD *)&this->mbDestroyOnUnload = 0;
  this->mbPostNISFadeIn = 1;
  this->mpPostNISSceneSettings = 0i64;
  this->mpNISAllowPlayerControlTask = 0i64;
  AnimationGroupHandle::Reset(&this->mAnimationGroupHandle);
  AnimationGroupHandle::Reset(&this->mFacialAnimGroupHandle);
  AnimationGroupHandle::Reset(&this->mExtraFacialAnimGroupHandle);
  this->mPlayRelativeToNISSceneRoot = 0;
  v4 = UFG::qMatrix44::msIdentity.v1;
  v5 = UFG::qMatrix44::msIdentity.v2;
  v6 = UFG::qMatrix44::msIdentity.v3;
  this->mNISSceneRoot.v0 = UFG::qMatrix44::msIdentity.v0;
  this->mNISSceneRoot.v1 = v4;
  this->mNISSceneRoot.v2 = v5;
  this->mNISSceneRoot.v3 = v6;
  mpNISNode = this->mpNISNode;
  if ( mpNISNode )
  {
    if ( (mpNISNode->mAnimationGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
      v8 = (char *)&mpNISNode->mAnimationGroupName + (mpNISNode->mAnimationGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    else
      v8 = BinString::sEmptyString;
    v9 = UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&result, v8);
    AnimationGroupHandle::Init(&this->mAnimationGroupHandle, v9, eANIM_PRIORITY_INACTIVE_NIS);
    p_mFacialAnimGroupName = &this->mpNISNode->mFacialAnimGroupName;
    v11 = (char *)p_mFacialAnimGroupName + (p_mFacialAnimGroupName->mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( (p_mFacialAnimGroupName->mOffset & 0xFFFFFFFFFFFFFFFEui64) == 0 )
      v11 = BinString::sEmptyString;
    if ( (int)UFG::qStringLength(v11) > 0 )
    {
      v12 = UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&result, v11);
      AnimationGroupHandle::Init(&this->mFacialAnimGroupHandle, v12, eANIM_PRIORITY_INACTIVE_NIS);
    }
    p_mExtraFacialAnimGroupName = &this->mpNISNode->mExtraFacialAnimGroupName;
    v14 = (char *)p_mExtraFacialAnimGroupName + (p_mExtraFacialAnimGroupName->mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( (p_mExtraFacialAnimGroupName->mOffset & 0xFFFFFFFFFFFFFFFEui64) == 0 )
      v14 = BinString::sEmptyString;
    if ( (int)UFG::qStringLength(v14) > 0 )
    {
      v15 = UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&result, v14);
      AnimationGroupHandle::Init(&this->mExtraFacialAnimGroupHandle, v15, eANIM_PRIORITY_INACTIVE_NIS);
    }
    v16 = (int)this->mpNISNode->vfptr[1].GetClassname(this->mpNISNode);
    p_mMeshResources = &this->mMeshResources;
    size = this->mMeshResources.size;
    v19 = v16 - size;
    if ( v19 <= 0 )
    {
      v23 = -v19;
      if ( v23 )
      {
        if ( v23 < size )
          p_mMeshResources->size = size - v23;
        else
          p_mMeshResources->size = 0;
      }
    }
    else
    {
      v20 = size + v19;
      capacity = this->mMeshResources.capacity;
      if ( size + v19 > capacity )
      {
        if ( capacity )
          v22 = 2 * capacity;
        else
          v22 = 1;
        for ( ; v22 < v20; v22 *= 2 )
          ;
        if ( v22 - v20 > 0x10000 )
          v22 = v20 + 0x10000;
        UFG::qArray<UFG::MeshResourceLoader,0>::Reallocate(&this->mMeshResources, v22, "qArray.Reallocate(Resize)");
      }
      p_mMeshResources->size = v20;
    }
    if ( !this->mpNISNode->mLightGroupObject )
    {
      v24 = UFG::qMalloc(0xB8ui64, UFG::gGlobalNewName, 0i64);
      result = v24;
      if ( v24 )
      {
        p_mAnimationGroupName = &this->mpNISNode->mAnimationGroupName;
        if ( (p_mAnimationGroupName->mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
          v26 = (char *)p_mAnimationGroupName + (p_mAnimationGroupName->mOffset & 0xFFFFFFFFFFFFFFFEui64);
        else
          v26 = BinString::sEmptyString;
        NISLightGroup::NISLightGroup((NISLightGroup *)v24, v26);
        v3 = v27;
      }
      this->mpNISNode->mLightGroupObject = v3;
    }
    this->mStatus = eSTATUS_IDLE;
  }
}

// File Line: 146
// RVA: 0x3E3FC0
void __fastcall NISInstance::Preload(NISInstance *this)
{
  NISInstance *m_pPointer; // rax
  int v3; // ebp
  unsigned int i; // esi
  __int64 v5; // rbx
  UFG::qPropertySet *PropertySet; // r14
  UFG::qPropertySet *v7; // rax
  bool v8; // r9
  __int64 v9; // rbx
  BinString *p_mSoundbank; // rax
  const char *v11; // rcx
  BinString *v12; // rax
  const char *v13; // rdx
  UFG::qWiseSymbol *v14; // rax
  NISLightGroup *mLightGroupObject; // rcx
  UFG::qSafePointer<NISInstance,NISInstance> *p_mpPreloadInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qSymbol priority; // [rsp+50h] [rbp+8h] BYREF
  UFG::qSymbol *p_priority; // [rsp+58h] [rbp+10h]

  if ( this->mpNISNode && this->mStatus != eSTATUS_PRELOADING )
  {
    m_pPointer = NISManager::sInstance->mpPreloadInstance.m_pPointer;
    if ( !m_pPointer || m_pPointer == this || m_pPointer->mStatus == eSTATUS_PLAYING )
    {
      AnimationGroupHandle::SetAnimationPriority(&this->mAnimationGroupHandle, eANIM_PRIORITY_NIS_PRELOAD, 0);
      AnimationGroupHandle::Bind(&this->mAnimationGroupHandle);
      if ( this->mFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
      {
        AnimationGroupHandle::SetAnimationPriority(&this->mFacialAnimGroupHandle, eANIM_PRIORITY_NIS_PRELOAD, 0);
        AnimationGroupHandle::Bind(&this->mFacialAnimGroupHandle);
      }
      if ( this->mExtraFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
      {
        AnimationGroupHandle::SetAnimationPriority(&this->mExtraFacialAnimGroupHandle, eANIM_PRIORITY_NIS_PRELOAD, 0);
        AnimationGroupHandle::Bind(&this->mExtraFacialAnimGroupHandle);
      }
      v3 = (int)this->mpNISNode->vfptr[1].GetClassname(this->mpNISNode);
      for ( i = 0; (int)i < v3; ++i )
      {
        v5 = ((__int64 (__fastcall *)(NISNode *, _QWORD))this->mpNISNode->vfptr[1].Serialize)(this->mpNISNode, i);
        PropertySet = UFG::PropertySetManager::GetPropertySet((UFG::qSymbol *)(v5 + 260));
        v7 = UFG::qPropertySet::Get<UFG::qPropertySet>(
               PropertySet,
               (UFG::qArray<unsigned long,0> *)&component_StreamedResource::sPropertyName,
               DEPTH_RECURSE);
        if ( v7 && UFG::qPropertySet::GetMemImagePtr(v7) )
        {
          v8 = *(_BYTE *)(v5 + 269) || NISManager::sInstance->mHighDefModelsEnabled;
          p_priority = &priority;
          priority.mUID = qSymbol_Reserved.mUID;
          v9 = i;
          UFG::MeshResourceLoader::Init(&this->mMeshResources.p[v9], PropertySet, (UFG::qSymbol)&priority, v8);
          UFG::MeshResourceLoader::PopulateTrueCrowdInstanceFromPropertySet(&this->mMeshResources.p[v9], 1);
          UFG::MeshResourceLoader::QueueLoad(&this->mMeshResources.p[v9]);
        }
      }
      if ( this->mSoundbankSymbol.mUID == UFG::qWiseSymbol::get_null()->mUID )
      {
        p_mSoundbank = &this->mpNISNode->mSoundbank;
        v11 = (p_mSoundbank->mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0
            ? (char *)p_mSoundbank + (p_mSoundbank->mOffset & 0xFFFFFFFFFFFFFFFEui64)
            : BinString::sEmptyString;
        if ( (int)UFG::qStringLength(v11) > 0 )
        {
          v12 = &this->mpNISNode->mSoundbank;
          v13 = (char *)v12 + (v12->mOffset & 0xFFFFFFFFFFFFFFFEui64);
          if ( (v12->mOffset & 0xFFFFFFFFFFFFFFFEui64) == 0 )
            v13 = BinString::sEmptyString;
          v14 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&priority, v13);
          UFG::qWiseSymbol::operator=(&this->mSoundbankSymbol, v14);
          _((AMD_HD3D *)priority.mUID);
          UFG::TiDo::LoadWwiseBank(&this->mSoundbankSymbol);
        }
      }
      mLightGroupObject = this->mpNISNode->mLightGroupObject;
      if ( mLightGroupObject )
        NISLightGroup::PreLoadResource(mLightGroupObject);
      p_mpPreloadInstance = &NISManager::sInstance->mpPreloadInstance;
      if ( NISManager::sInstance->mpPreloadInstance.m_pPointer )
      {
        mPrev = p_mpPreloadInstance->mPrev;
        mNext = NISManager::sInstance->mpPreloadInstance.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mpPreloadInstance->mPrev = p_mpPreloadInstance;
        p_mpPreloadInstance->mNext = p_mpPreloadInstance;
      }
      p_mpPreloadInstance->m_pPointer = this;
      v19 = this->m_SafePointerList.mNode.UFG::qSafePointerNode<NISInstance>::mPrev;
      v19->mNext = p_mpPreloadInstance;
      p_mpPreloadInstance->mPrev = v19;
      p_mpPreloadInstance->mNext = &this->m_SafePointerList.mNode;
      this->m_SafePointerList.mNode.UFG::qSafePointerNode<NISInstance>::mPrev = p_mpPreloadInstance;
      this->mStatus = eSTATUS_PRELOADING;
    }
    else
    {
      this->mStatus = eSTATUS_QUEUED_FOR_PRELOADING;
    }
  }
}

// File Line: 229
// RVA: 0x3E34E0
void __fastcall NISInstance::LoadAnimations(NISInstance *this)
{
  UFG::qSafePointer<NISInstance,NISInstance> *p_mpPreloadInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mNext; // rax

  if ( this->mpNISNode )
  {
    AnimationGroupHandle::SetAnimationPriority(&this->mAnimationGroupHandle, eANIM_PRIORITY_ACTIVE_NIS, 0);
    AnimationGroupHandle::SetAnimationPriority(&this->mFacialAnimGroupHandle, eANIM_PRIORITY_ACTIVE_NIS, 0);
    AnimationGroupHandle::SetAnimationPriority(&this->mExtraFacialAnimGroupHandle, eANIM_PRIORITY_ACTIVE_NIS, 0);
    if ( !this->mAnimationGroupHandle.m_AnimationGroup.m_pPointer )
      AnimationGroupHandle::Bind(&this->mAnimationGroupHandle);
    if ( this->mFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1
      && !this->mFacialAnimGroupHandle.m_AnimationGroup.m_pPointer )
    {
      AnimationGroupHandle::Bind(&this->mFacialAnimGroupHandle);
    }
    if ( this->mExtraFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1
      && !this->mExtraFacialAnimGroupHandle.m_AnimationGroup.m_pPointer )
    {
      AnimationGroupHandle::Bind(&this->mExtraFacialAnimGroupHandle);
    }
    if ( this->mStatus == eSTATUS_PRELOADING )
    {
      p_mpPreloadInstance = &NISManager::sInstance->mpPreloadInstance;
      if ( NISManager::sInstance->mpPreloadInstance.m_pPointer )
      {
        mPrev = p_mpPreloadInstance->mPrev;
        mNext = NISManager::sInstance->mpPreloadInstance.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mpPreloadInstance->mPrev = p_mpPreloadInstance;
        p_mpPreloadInstance->mNext = p_mpPreloadInstance;
      }
      p_mpPreloadInstance->m_pPointer = 0i64;
    }
    this->mStatus = eSTATUS_LOADING;
  }
}

// File Line: 255
// RVA: 0x3E3310
void __fastcall NISInstance::LoadAllResources(NISInstance *this)
{
  int v2; // esi
  int v3; // r14d
  NISActorNode *v4; // rax
  UFG::qSymbol *v5; // rbx
  bool v6; // dl
  UFG::SimObjectCharacter *SimObject; // rax
  UFG::MeshResourceLoader *v8; // rdi
  __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rbx
  UFG::SimComponent *v11; // rax
  UFG::qSafePointer<NISInstance,NISInstance> *p_mpPreloadInstance; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mNext; // rax

  if ( this->mpNISNode )
  {
    NISInstance::Preload(this);
    NISInstance::LoadAnimations(this);
    v2 = 0;
    v3 = (int)this->mpNISNode->vfptr[1].GetClassname(this->mpNISNode);
    if ( v3 > 0 )
    {
      do
      {
        v4 = (NISActorNode *)((__int64 (__fastcall *)(NISNode *, _QWORD))this->mpNISNode->vfptr[1].Serialize)(
                               this->mpNISNode,
                               (unsigned int)v2);
        v5 = (UFG::qSymbol *)v4;
        v6 = v4->mHighDef || NISManager::sInstance->mHighDefModelsEnabled;
        NISActorNode::SetupActor(v4, v6);
        SimObject = (UFG::SimObjectCharacter *)UFG::Simulation::GetSimObject(&UFG::gSim, v5 + 64);
        if ( SimObject != LocalPlayer )
        {
          v8 = &this->mMeshResources.p[v2];
          if ( SimObject )
          {
            m_Flags = SimObject->m_Flags;
            if ( (m_Flags & 0x4000) != 0 )
            {
              m_pComponent = (UFG::StreamedResourceComponent *)SimObject->m_Components.p[10].m_pComponent;
            }
            else if ( m_Flags >= 0 )
            {
              if ( (m_Flags & 0x2000) != 0 )
              {
                m_pComponent = (UFG::StreamedResourceComponent *)SimObject->m_Components.p[7].m_pComponent;
              }
              else
              {
                v11 = (m_Flags & 0x1000) != 0
                    ? UFG::SimObjectGame::GetComponentOfTypeHK(SimObject, UFG::StreamedResourceComponent::_TypeUID)
                    : UFG::SimObject::GetComponentOfType(SimObject, UFG::StreamedResourceComponent::_TypeUID);
                m_pComponent = (UFG::StreamedResourceComponent *)v11;
              }
            }
            else
            {
              m_pComponent = (UFG::StreamedResourceComponent *)SimObject->m_Components.p[10].m_pComponent;
            }
            if ( m_pComponent
              && !UFG::TrueCrowdSet::Instance::IsEqual(
                    &v8->mTrueCrowdInstance,
                    &m_pComponent->mMeshLoader.mTrueCrowdInstance) )
            {
              UFG::StreamedResourceComponent::ClearResources(m_pComponent);
              UFG::StreamedResourceComponent::SetResourceSignature(m_pComponent, &v8->mTrueCrowdInstance);
            }
          }
        }
        ++v2;
      }
      while ( v2 < v3 );
    }
    if ( this->mStatus == eSTATUS_PRELOADING )
    {
      p_mpPreloadInstance = &NISManager::sInstance->mpPreloadInstance;
      if ( NISManager::sInstance->mpPreloadInstance.m_pPointer )
      {
        mPrev = p_mpPreloadInstance->mPrev;
        mNext = NISManager::sInstance->mpPreloadInstance.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mpPreloadInstance->mPrev = p_mpPreloadInstance;
        p_mpPreloadInstance->mNext = p_mpPreloadInstance;
      }
      p_mpPreloadInstance->m_pPointer = 0i64;
    }
    this->mStatus = eSTATUS_LOADING;
  }
}

// File Line: 308
// RVA: 0x3E6230
void __fastcall NISInstance::Unload(NISInstance *this, bool bAllowDestroy)
{
  int v4; // ebx
  int v5; // ebp
  __int64 v6; // rsi
  UFG::qBaseNodeRB *SimObject; // rax
  NISLightGroup *mLightGroupObject; // rdx
  UFG::SimObject *m_pPointer; // rdx
  UFG::qSafePointer<NISInstance,NISInstance> *p_mpPreloadInstance; // r8
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *mNext; // rax

  if ( this->mpNISNode )
  {
    AnimationGroupHandle::SetAnimationPriority(&this->mAnimationGroupHandle, eANIM_PRIORITY_INACTIVE_NIS, 0);
    AnimationGroupHandle::Unbind(&this->mAnimationGroupHandle);
    if ( this->mFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
    {
      AnimationGroupHandle::SetAnimationPriority(&this->mFacialAnimGroupHandle, eANIM_PRIORITY_INACTIVE_NIS, 0);
      AnimationGroupHandle::Unbind(&this->mFacialAnimGroupHandle);
    }
    if ( this->mExtraFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
    {
      AnimationGroupHandle::SetAnimationPriority(&this->mExtraFacialAnimGroupHandle, eANIM_PRIORITY_INACTIVE_NIS, 0);
      AnimationGroupHandle::Unbind(&this->mExtraFacialAnimGroupHandle);
    }
    v4 = 0;
    v5 = (int)this->mpNISNode->vfptr[1].GetClassname(this->mpNISNode);
    if ( v5 > 0 )
    {
      do
      {
        v6 = ((__int64 (__fastcall *)(NISNode *, _QWORD))this->mpNISNode->vfptr[1].Serialize)(
               this->mpNISNode,
               (unsigned int)v4);
        SimObject = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)(v6 + 256));
        if ( *(_BYTE *)(v6 + 267) && SimObject )
        {
          *(_BYTE *)(v6 + 267) = 0;
          UFG::SimObjectUtility::DowngradeModelResolution((UFG::SimObject *)SimObject);
        }
        *(_WORD *)(v6 + 271) = 0;
        UFG::MeshResourceLoader::Unload(&this->mMeshResources.p[v4++]);
      }
      while ( v4 < v5 );
    }
    if ( this->mSoundbankSymbol.mUID != UFG::qWiseSymbol::get_null()->mUID )
    {
      UFG::TiDo::UnloadWwiseBank(&this->mSoundbankSymbol);
      UFG::qWiseSymbol::set_null(&this->mSoundbankSymbol);
    }
    mLightGroupObject = this->mpNISNode->mLightGroupObject;
    if ( mLightGroupObject )
    {
      m_pPointer = mLightGroupObject->mSimObject.m_pPointer;
      if ( m_pPointer )
        UFG::Simulation::DestroySimObject(&UFG::gSim, m_pPointer);
    }
    if ( this->mStatus == eSTATUS_PRELOADING )
    {
      p_mpPreloadInstance = &NISManager::sInstance->mpPreloadInstance;
      if ( NISManager::sInstance->mpPreloadInstance.m_pPointer )
      {
        mPrev = p_mpPreloadInstance->mPrev;
        mNext = NISManager::sInstance->mpPreloadInstance.mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mpPreloadInstance->mPrev = p_mpPreloadInstance;
        p_mpPreloadInstance->mNext = p_mpPreloadInstance;
      }
      p_mpPreloadInstance->m_pPointer = 0i64;
    }
    this->mStatus = eSTATUS_IDLE;
  }
  if ( bAllowDestroy && this->mbDestroyOnUnload )
    this->vfptr->__vecDelDtor(this, 1i64);
}

// File Line: 382
// RVA: 0x3E1820
char __fastcall NISInstance::AreAnimationsLoaded(NISInstance *this)
{
  AnimationGroup *m_pPointer; // rcx
  bool IsCameraAnimationValid; // dl
  AnimationGroup *v4; // rcx
  AnimationGroup *v5; // rcx

  m_pPointer = this->mAnimationGroupHandle.m_AnimationGroup.m_pPointer;
  if ( m_pPointer && AnimationGroup::IsStreamedIn(m_pPointer) )
  {
    IsCameraAnimationValid = 1;
    if ( this->mpNISNode->mPrimaryCameraAnimationTrack )
      IsCameraAnimationValid = NISInstance::IsCameraAnimationValid(this);
  }
  else
  {
    IsCameraAnimationValid = 0;
  }
  if ( this->mFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
    IsCameraAnimationValid = IsCameraAnimationValid
                          && (v4 = this->mFacialAnimGroupHandle.m_AnimationGroup.m_pPointer) != 0i64
                          && AnimationGroup::IsStreamedIn(v4);
  if ( this->mExtraFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID == -1 )
    return IsCameraAnimationValid;
  if ( IsCameraAnimationValid )
  {
    v5 = this->mExtraFacialAnimGroupHandle.m_AnimationGroup.m_pPointer;
    if ( v5 )
    {
      if ( AnimationGroup::IsStreamedIn(v5) )
        return 1;
    }
  }
  return 0;
}

// File Line: 431
// RVA: 0x3E17A0
char __fastcall NISInstance::AreAllActorsLoaded(NISInstance *this)
{
  signed int size; // edi
  signed int v3; // ebx
  char i; // si

  if ( !this->mpNISNode )
    return 0;
  size = this->mMeshResources.size;
  v3 = 0;
  for ( i = 1; v3 < size; ++v3 )
  {
    i &= UFG::MeshResourceLoader::IsLoaded(&this->mMeshResources.p[v3]);
    if ( !i )
      break;
  }
  return i;
}

// File Line: 450
// RVA: 0x3E3200
bool __fastcall NISInstance::IsLightGroupLoaded(NISInstance *this)
{
  NISNode *mpNISNode; // rax
  NISLightGroup *mLightGroupObject; // rax
  UFG::DataStreamer::Handle *p_mHandle; // rcx
  bool result; // al

  mpNISNode = this->mpNISNode;
  result = 0;
  if ( mpNISNode )
  {
    mLightGroupObject = mpNISNode->mLightGroupObject;
    if ( !mLightGroupObject )
      return 1;
    if ( !mLightGroupObject->mValid )
      return 1;
    p_mHandle = &mLightGroupObject->mLightRigHandle->mHandle;
    if ( p_mHandle )
    {
      if ( (unsigned int)UFG::DataStreamer::GetStreamState(p_mHandle) == 6 )
        return 1;
    }
  }
  return result;
}

// File Line: 468
// RVA: 0x3E3140
char __fastcall NISInstance::IsAudioResourceLoaded(NISInstance *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  char v4; // bl
  UFG::qWiseSymbol *null; // rax
  unsigned int mUID; // ecx

  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
    return 1;
  v4 = 1;
  null = UFG::qWiseSymbol::get_null();
  mUID = this->mSoundbankSymbol.mUID;
  if ( mUID != null->mUID )
    return UFG::TiDo::BankLoaded(mUID);
  return v4;
}

// File Line: 482
// RVA: 0x3E3240
bool __fastcall NISInstance::IsLoaded(NISInstance *this)
{
  char v2; // r14
  char v3; // al
  UFG::DataStreamer::Handle *v4; // rcx
  NISNode *mpNISNode; // rdx
  char v6; // bp
  bool v7; // bl
  bool v8; // di
  UFG::qWiseSymbol *null; // rax
  unsigned int mUID; // ecx

  v2 = NISInstance::AreAnimationsLoaded(this);
  v3 = NISInstance::AreAllActorsLoaded(this);
  mpNISNode = this->mpNISNode;
  v6 = v3;
  v7 = 0;
  if ( mpNISNode )
  {
    mpNISNode = (NISNode *)mpNISNode->mLightGroupObject;
    if ( !mpNISNode
      || !LOBYTE(mpNISNode->mFirstCallback)
      || (v4 = *(UFG::DataStreamer::Handle **)&mpNISNode->mAllowLetterbox) != 0i64
      && (unsigned int)UFG::DataStreamer::GetStreamState(v4) == 6 )
    {
      v7 = 1;
    }
  }
  v8 = 1;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)v4,
          (hkgpIndexedMeshDefinitions::Edge *)mpNISNode) )
  {
    null = UFG::qWiseSymbol::get_null();
    mUID = this->mSoundbankSymbol.mUID;
    if ( mUID != null->mUID )
      v8 = UFG::TiDo::BankLoaded(mUID);
  }
  return v2 && v6 && v7 && v8;
}

// File Line: 493
// RVA: 0x3E3190
bool __fastcall NISInstance::IsCameraAnimationValid(NISInstance *this)
{
  CameraAnimationTrack *mPrimaryCameraAnimationTrack; // r8
  AnimationGroup *m_pPointer; // rdx
  unsigned int mUID; // r11d
  unsigned int v4; // r8d
  _QWORD *v5; // rcx

  mPrimaryCameraAnimationTrack = this->mpNISNode->mPrimaryCameraAnimationTrack;
  if ( !mPrimaryCameraAnimationTrack )
    return 0;
  m_pPointer = this->mAnimationGroupHandle.m_AnimationGroup.m_pPointer;
  if ( !m_pPointer )
    return 0;
  mUID = mPrimaryCameraAnimationTrack->mAnimationName.mUID;
  v4 = 0;
  v5 = (__int64 *)((char *)&m_pPointer->mAnimations.mData.mOffset + m_pPointer->mAnimations.mData.mOffset);
  if ( (m_pPointer->mAnimations.mCount & 0x7FFFFFFF) == 0 )
    return 0;
  while ( *(_DWORD *)((char *)v5 + *v5 + 168) != mUID )
  {
    ++v4;
    ++v5;
    if ( v4 >= (m_pPointer->mAnimations.mCount & 0x7FFFFFFFu) )
      return 0;
  }
  return *(_QWORD *)((char *)v5 + *v5 + 104) != 0i64;
}

// File Line: 512
// RVA: 0x3E1670
__int64 __fastcall NISInstance::AreActorsReady(NISInstance *this)
{
  NISNode *mpNISNode; // rcx
  unsigned __int8 v3; // si
  unsigned int v4; // edi
  unsigned int v5; // ebp
  UFG::qSymbol *v6; // rax
  UFG::SimObjectGame *SimObject; // rax
  __int16 m_Flags; // cx
  UFG::StreamedResourceComponent *m_pComponent; // rbx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  char v11; // si

  mpNISNode = this->mpNISNode;
  v3 = 1;
  if ( !mpNISNode )
    return 1i64;
  v4 = 0;
  v5 = ((__int64 (*)(void))mpNISNode->vfptr[1].GetClassname)();
  if ( !v5 )
    return 1i64;
  do
  {
    v6 = (UFG::qSymbol *)((__int64 (__fastcall *)(NISNode *, _QWORD))this->mpNISNode->vfptr[1].Serialize)(
                           this->mpNISNode,
                           v4);
    SimObject = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, v6 + 64);
    if ( SimObject )
    {
      m_Flags = SimObject->m_Flags;
      if ( (m_Flags & 0x4000) != 0 )
      {
        m_pComponent = (UFG::StreamedResourceComponent *)SimObject->m_Components.p[10].m_pComponent;
      }
      else if ( m_Flags >= 0 )
      {
        if ( (m_Flags & 0x2000) != 0 )
        {
          m_pComponent = (UFG::StreamedResourceComponent *)SimObject->m_Components.p[7].m_pComponent;
        }
        else
        {
          if ( (m_Flags & 0x1000) != 0 )
            ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                  SimObject,
                                  UFG::StreamedResourceComponent::_TypeUID);
          else
            ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(SimObject, UFG::StreamedResourceComponent::_TypeUID);
          m_pComponent = (UFG::StreamedResourceComponent *)ComponentOfTypeHK;
        }
      }
      else
      {
        m_pComponent = (UFG::StreamedResourceComponent *)SimObject->m_Components.p[10].m_pComponent;
      }
      if ( m_pComponent )
      {
        v11 = UFG::StreamedResourceComponent::AreResourcesLoaded(m_pComponent) & v3;
        v3 = UFG::StreamedResourceComponent::AreResourcesBound(m_pComponent) & v11;
      }
    }
    ++v4;
  }
  while ( v4 < v5 );
  return v3;
}

// File Line: 534
// RVA: 0x3E6B70
void __fastcall NISInstance::UpdateActorResources(NISInstance *this, float deltaSeconds)
{
  NISNode *mpNISNode; // rcx
  unsigned int v5; // esi
  unsigned int v6; // ebp
  UFG::qSymbol *v7; // rax
  UFG::SimObjectGame *SimObject; // rax
  UFG::SimObjectGame *v9; // rbx
  __int16 m_Flags; // dx
  UFG::StreamedResourceComponent *m_pComponent; // rdi
  UFG::SimComponent *ComponentOfTypeHK; // rax
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rbx
  float y; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 streamPosition; // [rsp+20h] [rbp-28h] BYREF

  mpNISNode = this->mpNISNode;
  if ( mpNISNode )
  {
    v5 = 0;
    v6 = ((__int64 (*)(void))mpNISNode->vfptr[1].GetClassname)();
    if ( v6 )
    {
      do
      {
        v7 = (UFG::qSymbol *)((__int64 (__fastcall *)(NISNode *, _QWORD))this->mpNISNode->vfptr[1].Serialize)(
                               this->mpNISNode,
                               v5);
        SimObject = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, v7 + 64);
        v9 = SimObject;
        if ( SimObject )
        {
          m_Flags = SimObject->m_Flags;
          if ( (m_Flags & 0x4000) != 0 )
          {
            m_pComponent = (UFG::StreamedResourceComponent *)SimObject->m_Components.p[10].m_pComponent;
          }
          else if ( m_Flags >= 0 )
          {
            if ( (m_Flags & 0x2000) != 0 )
            {
              m_pComponent = (UFG::StreamedResourceComponent *)SimObject->m_Components.p[7].m_pComponent;
            }
            else
            {
              if ( (m_Flags & 0x1000) != 0 )
                ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(
                                      SimObject,
                                      UFG::StreamedResourceComponent::_TypeUID);
              else
                ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(
                                      SimObject,
                                      UFG::StreamedResourceComponent::_TypeUID);
              m_pComponent = (UFG::StreamedResourceComponent *)ComponentOfTypeHK;
            }
          }
          else
          {
            m_pComponent = (UFG::StreamedResourceComponent *)SimObject->m_Components.p[10].m_pComponent;
          }
          m_pTransformNodeComponent = v9->m_pTransformNodeComponent;
          if ( m_pComponent )
          {
            if ( m_pTransformNodeComponent )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
              y = m_pTransformNodeComponent->mWorldTransform.v3.y;
              streamPosition.x = m_pTransformNodeComponent->mWorldTransform.v3.x;
              z = m_pTransformNodeComponent->mWorldTransform.v3.z;
              streamPosition.y = y;
              streamPosition.z = z;
              UFG::StreamedResourceComponent::Update(m_pComponent, deltaSeconds, &streamPosition);
            }
          }
        }
        ++v5;
      }
      while ( v5 < v6 );
    }
  }
}

