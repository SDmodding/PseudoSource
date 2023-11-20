// File Line: 28
// RVA: 0x3DFEB0
void __fastcall NISInstance::NISInstance(NISInstance *this, const char *pathName)
{
  const char *v2; // rsi
  NISInstance *v3; // rbx
  UFG::qNode<NISInstance,NISInstanceMasterList> *v4; // rax
  NISNode *v5; // rdi
  ActionNode *v6; // rax
  NISNode *v7; // rsi
  __int64 v8; // rax
  UFG::qOffset64<ActionID *> *v9; // r8
  __int64 v10; // rax
  NISNode *v11; // rsi
  ActionPath absolutePath; // [rsp+28h] [rbp-18h]
  int v13; // [rsp+80h] [rbp+40h]
  int v14; // [rsp+88h] [rbp+48h]

  v2 = pathName;
  v3 = this;
  v4 = (UFG::qNode<NISInstance,NISInstanceMasterList> *)&this->mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
  UFG::qSafePointerNode<NISInstance>::qSafePointerNode<NISInstance>((UFG::qSafePointerNode<NISInstance> *)&this->vfptr);
  v3->vfptr = (UFG::qSafePointerNode<NISInstance>Vtbl *)&NISInstance::`vftable;
  v3->mSoundbankSymbol.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  AnimationGroupHandle::AnimationGroupHandle(&v3->mAnimationGroupHandle);
  AnimationGroupHandle::AnimationGroupHandle(&v3->mFacialAnimGroupHandle);
  AnimationGroupHandle::AnimationGroupHandle(&v3->mExtraFacialAnimGroupHandle);
  v3->mMeshResources.p = 0i64;
  *(_QWORD *)&v3->mMeshResources.size = 0i64;
  v5 = 0i64;
  absolutePath.mPath.mData.mOffset = 0i64;
  absolutePath.mPath.mCount = 0;
  ActionPath::Append(&absolutePath, v2);
  v6 = ActionNode::Find(&absolutePath, 0i64);
  v7 = (NISNode *)v6;
  if ( v6 && v6->vfptr->GetClassNameUID((Expression::IMemberMap *)&v6->vfptr) == NISNode::sClassNameUID )
  {
    v5 = v7;
  }
  else
  {
    v13 = UFG::qStringHashUpper32("NIS", 0xFFFFFFFF);
    v8 = ((__int64 (__fastcall *)(ActionNode *, int *, _QWORD))ActionNode::smRoot->vfptr[1].CreateClone)(
           ActionNode::smRoot,
           &v13,
           0i64);
    if ( v8 )
    {
      v9 = absolutePath.mPath.mData.mOffset ? (UFG::qOffset64<ActionID *> *)((char *)&absolutePath.mPath.mData
                                                                           + absolutePath.mPath.mData.mOffset) : 0i64;
      v14 = *((_DWORD *)&v9->mOffset + (absolutePath.mPath.mCount & 0x7FFFFFFFu) - 1);
      LOBYTE(v9) = 1;
      v10 = (*(__int64 (__fastcall **)(__int64, int *, UFG::qOffset64<ActionID *> *))(*(_QWORD *)v8 + 96i64))(
              v8,
              &v14,
              v9);
      v11 = (NISNode *)v10;
      if ( v10 )
      {
        if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v10 + 40i64))(v10) == NISNode::sClassNameUID )
          v5 = v11;
      }
    }
  }
  NISInstance::Init(v3, v5);
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
  NISInstance *v1; // rdi
  NISNode *v2; // rbx
  NISLightGroup *v3; // rbx
  UFG::MeshResourceLoader *v4; // rcx
  void **v5; // rbx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v6; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v7; // rax
  UFG::qNode<NISInstance,NISInstanceMasterList> *v8; // rdx
  UFG::qNode<NISInstance,NISInstanceMasterList> *v9; // rcx
  UFG::qNode<NISInstance,NISInstanceMasterList> *v10; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<NISInstance>Vtbl *)&NISInstance::`vftable;
  NISInstance::Unload(this, 0);
  v2 = v1->mpNISNode;
  if ( v2 )
  {
    v3 = v2->mLightGroupObject;
    if ( v3 )
    {
      NISLightGroup::~NISLightGroup(v3);
      operator delete[](v3);
      v1->mpNISNode->mLightGroupObject = 0i64;
    }
  }
  v4 = v1->mMeshResources.p;
  if ( v4 )
  {
    v5 = &v4[-1].mUserContext;
    `eh vector destructor iterator(
      v4,
      0x1E8ui64,
      (int)v4[-1].mUserContext,
      (void (__fastcall *)(void *))UFG::MeshResourceLoader::~MeshResourceLoader);
    operator delete[](v5);
  }
  v1->mMeshResources.p = 0i64;
  *(_QWORD *)&v1->mMeshResources.size = 0i64;
  AnimationGroupHandle::~AnimationGroupHandle(&v1->mExtraFacialAnimGroupHandle);
  AnimationGroupHandle::~AnimationGroupHandle(&v1->mFacialAnimGroupHandle);
  AnimationGroupHandle::~AnimationGroupHandle(&v1->mAnimationGroupHandle);
  _((AMD_HD3D *)v1->mSoundbankSymbol.mUID);
  v1->vfptr = (UFG::qSafePointerNode<NISInstance>Vtbl *)&UFG::qSafePointerNode<NISInstance>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)v1);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes((UFG::qList<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList,1,0> *)&v1->m_SafePointerList);
  v6 = v1->m_SafePointerList.mNode.mPrev;
  v7 = v1->m_SafePointerList.mNode.mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v1->m_SafePointerList.mNode.mPrev = &v1->m_SafePointerList.mNode;
  v1->m_SafePointerList.mNode.mNext = &v1->m_SafePointerList.mNode;
  v8 = (UFG::qNode<NISInstance,NISInstanceMasterList> *)&v1->mPrev;
  v9 = v1->mPrev;
  v10 = v1->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v8->mPrev = v8;
  v8->mNext = v8;
}

// File Line: 77
// RVA: 0x3E2D50
void __fastcall NISInstance::Init(NISInstance *this, NISNode *nisNode)
{
  NISInstance *v2; // rdi
  NISLightGroup *v3; // rbp
  UFG::qVector4 v4; // xmm1
  UFG::qVector4 v5; // xmm2
  UFG::qVector4 v6; // xmm3
  NISNode *v7; // rcx
  const char *v8; // rdx
  UFG::qSymbolUC *v9; // rax
  BinString *v10; // rax
  const char *v11; // rbx
  UFG::qSymbolUC *v12; // rax
  BinString *v13; // rax
  const char *v14; // rbx
  UFG::qSymbolUC *v15; // rax
  int v16; // eax
  UFG::qArray<UFG::MeshResourceLoader,0> *v17; // rsi
  unsigned int v18; // ecx
  int v19; // eax
  unsigned int v20; // ebx
  unsigned int v21; // edx
  unsigned int v22; // edx
  unsigned int v23; // eax
  UFG::allocator::free_link *v24; // rax
  BinString *v25; // rcx
  const char *v26; // rdx
  NISLightGroup *v27; // rax
  UFG::qSymbolUC result; // [rsp+50h] [rbp+8h]

  v2 = this;
  v3 = 0i64;
  this->mStatus = 0;
  this->mpNISNode = nisNode;
  UFG::qWiseSymbol::set_null(&this->mSoundbankSymbol);
  *(_WORD *)&v2->mbDestroyOnUnload = 0;
  v2->mbPostNISFadeIn = 1;
  v2->mpPostNISSceneSettings = 0i64;
  v2->mpNISAllowPlayerControlTask = 0i64;
  AnimationGroupHandle::Reset(&v2->mAnimationGroupHandle);
  AnimationGroupHandle::Reset(&v2->mFacialAnimGroupHandle);
  AnimationGroupHandle::Reset(&v2->mExtraFacialAnimGroupHandle);
  v2->mPlayRelativeToNISSceneRoot = 0;
  v4 = UFG::qMatrix44::msIdentity.v1;
  v5 = UFG::qMatrix44::msIdentity.v2;
  v6 = UFG::qMatrix44::msIdentity.v3;
  v2->mNISSceneRoot.v0 = UFG::qMatrix44::msIdentity.v0;
  v2->mNISSceneRoot.v1 = v4;
  v2->mNISSceneRoot.v2 = v5;
  v2->mNISSceneRoot.v3 = v6;
  v7 = v2->mpNISNode;
  if ( v7 )
  {
    if ( v7->mAnimationGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
      v8 = (char *)&v7->mAnimationGroupName + (v7->mAnimationGroupName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    else
      v8 = BinString::sEmptyString;
    v9 = UFG::qSymbolUC::create_from_string(&result, v8);
    AnimationGroupHandle::Init(&v2->mAnimationGroupHandle, v9, 0);
    v10 = &v2->mpNISNode->mFacialAnimGroupName;
    v11 = (char *)v10 + (v10->mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( !(v10->mOffset & 0xFFFFFFFFFFFFFFFEui64) )
      v11 = BinString::sEmptyString;
    if ( (signed int)UFG::qStringLength(v11) > 0 )
    {
      v12 = UFG::qSymbolUC::create_from_string(&result, v11);
      AnimationGroupHandle::Init(&v2->mFacialAnimGroupHandle, v12, 0);
    }
    v13 = &v2->mpNISNode->mExtraFacialAnimGroupName;
    v14 = (char *)v13 + (v13->mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( !(v13->mOffset & 0xFFFFFFFFFFFFFFFEui64) )
      v14 = BinString::sEmptyString;
    if ( (signed int)UFG::qStringLength(v14) > 0 )
    {
      v15 = UFG::qSymbolUC::create_from_string(&result, v14);
      AnimationGroupHandle::Init(&v2->mExtraFacialAnimGroupHandle, v15, 0);
    }
    v16 = ((__int64 (__cdecl *)(NISNode *))v2->mpNISNode->vfptr[1].GetClassname)(v2->mpNISNode);
    v17 = &v2->mMeshResources;
    v18 = v2->mMeshResources.size;
    v19 = v16 - v18;
    if ( v19 <= 0 )
    {
      v23 = -v19;
      if ( v23 )
      {
        if ( v23 < v18 )
          v17->size = v18 - v23;
        else
          v17->size = 0;
      }
    }
    else
    {
      v20 = v18 + v19;
      v21 = v2->mMeshResources.capacity;
      if ( v18 + v19 > v21 )
      {
        if ( v21 )
          v22 = 2 * v21;
        else
          v22 = 1;
        for ( ; v22 < v20; v22 *= 2 )
          ;
        if ( v22 - v20 > 0x10000 )
          v22 = v20 + 0x10000;
        UFG::qArray<UFG::MeshResourceLoader,0>::Reallocate(&v2->mMeshResources, v22, "qArray.Reallocate(Resize)");
      }
      v17->size = v20;
    }
    if ( !v2->mpNISNode->mLightGroupObject )
    {
      v24 = UFG::qMalloc(0xB8ui64, UFG::gGlobalNewName, 0i64);
      *(_QWORD *)&result.mUID = v24;
      if ( v24 )
      {
        v25 = &v2->mpNISNode->mAnimationGroupName;
        if ( v25->mOffset & 0xFFFFFFFFFFFFFFFEui64 )
          v26 = (char *)v25 + (v25->mOffset & 0xFFFFFFFFFFFFFFFEui64);
        else
          v26 = BinString::sEmptyString;
        NISLightGroup::NISLightGroup((NISLightGroup *)v24, v26);
        v3 = v27;
      }
      v2->mpNISNode->mLightGroupObject = v3;
    }
    v2->mStatus = 1;
  }
}

// File Line: 146
// RVA: 0x3E3FC0
void __fastcall NISInstance::Preload(NISInstance *this)
{
  NISInstance *v1; // rdi
  NISInstance::eStatusEnum v2; // ecx
  NISInstance *v3; // rax
  UFG::qSafePointer<NISInstance,NISInstance> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v6; // rax
  int v7; // ebp
  unsigned int v8; // esi
  UFG::qSymbol *v9; // rax
  UFG::qSymbol *v10; // rbx
  UFG::qPropertySet *v11; // rax
  UFG::qPropertySet *v12; // r14
  UFG::qPropertySet *v13; // rax
  bool v14; // r9
  signed __int64 v15; // rbx
  BinString *v16; // rax
  const char *v17; // rcx
  BinString *v18; // rax
  const char *v19; // rdx
  UFG::qWiseSymbol *v20; // rax
  NISLightGroup *v21; // rcx
  UFG::qSafePointer<NISInstance,NISInstance> *v22; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v23; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v24; // rax
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v25; // rax
  UFG::qSymbol priority; // [rsp+50h] [rbp+8h]
  UFG::qSymbol *v27; // [rsp+58h] [rbp+10h]

  v1 = this;
  if ( this->mpNISNode )
  {
    v2 = this->mStatus;
    if ( v2 != 3 )
    {
      v3 = NISManager::sInstance->mpPreloadInstance.m_pPointer;
      if ( v3 && v3 != v1 && v3->mStatus != 5 )
      {
        if ( v2 == 3 )
        {
          v4 = &NISManager::sInstance->mpPreloadInstance;
          if ( NISManager::sInstance->mpPreloadInstance.m_pPointer )
          {
            v5 = v4->mPrev;
            v6 = NISManager::sInstance->mpPreloadInstance.mNext;
            v5->mNext = v6;
            v6->mPrev = v5;
            v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v4->mPrev;
            v4->mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v4->mPrev;
          }
          v4->m_pPointer = 0i64;
        }
        v1->mStatus = 2;
      }
      else
      {
        AnimationGroupHandle::SetAnimationPriority(&v1->mAnimationGroupHandle, eANIM_PRIORITY_NIS_PRELOAD, 0);
        AnimationGroupHandle::Bind(&v1->mAnimationGroupHandle);
        if ( v1->mFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
        {
          AnimationGroupHandle::SetAnimationPriority(&v1->mFacialAnimGroupHandle, eANIM_PRIORITY_NIS_PRELOAD, 0);
          AnimationGroupHandle::Bind(&v1->mFacialAnimGroupHandle);
        }
        if ( v1->mExtraFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
        {
          AnimationGroupHandle::SetAnimationPriority(&v1->mExtraFacialAnimGroupHandle, eANIM_PRIORITY_NIS_PRELOAD, 0);
          AnimationGroupHandle::Bind(&v1->mExtraFacialAnimGroupHandle);
        }
        v7 = ((__int64 (__cdecl *)(NISNode *))v1->mpNISNode->vfptr[1].GetClassname)(v1->mpNISNode);
        v8 = 0;
        if ( v7 > 0 )
        {
          do
          {
            v9 = (UFG::qSymbol *)((__int64 (__fastcall *)(NISNode *, _QWORD))v1->mpNISNode->vfptr[1].Serialize)(
                                   v1->mpNISNode,
                                   v8);
            v10 = v9;
            v11 = UFG::PropertySetManager::GetPropertySet(v9 + 65);
            v12 = v11;
            v13 = UFG::qPropertySet::Get<UFG::qPropertySet>(
                    v11,
                    (UFG::qSymbol *)&component_StreamedResource::sPropertyName.mUID,
                    DEPTH_RECURSE);
            if ( v13 && UFG::qPropertySet::GetMemImagePtr(v13) )
            {
              v14 = BYTE1(v10[67].mUID) || NISManager::sInstance->mHighDefModelsEnabled;
              v27 = &priority;
              priority.mUID = qSymbol_Reserved.mUID;
              v15 = v8;
              UFG::MeshResourceLoader::Init(&v1->mMeshResources.p[v15], v12, (UFG::qSymbol)&priority, v14);
              UFG::MeshResourceLoader::PopulateTrueCrowdInstanceFromPropertySet(&v1->mMeshResources.p[v15], 1);
              UFG::MeshResourceLoader::QueueLoad(&v1->mMeshResources.p[v15]);
            }
            ++v8;
          }
          while ( (signed int)v8 < v7 );
        }
        if ( v1->mSoundbankSymbol.mUID == UFG::qWiseSymbol::get_null()->mUID )
        {
          v16 = &v1->mpNISNode->mSoundbank;
          v17 = (const char *)(v16->mOffset & 0xFFFFFFFFFFFFFFFEui64 ? (BinString *)((char *)v16
                                                                                   + (v16->mOffset & 0xFFFFFFFFFFFFFFFEui64)) : BinString::sEmptyString);
          if ( (signed int)UFG::qStringLength(v17) > 0 )
          {
            v18 = &v1->mpNISNode->mSoundbank;
            v19 = (char *)v18 + (v18->mOffset & 0xFFFFFFFFFFFFFFFEui64);
            if ( !(v18->mOffset & 0xFFFFFFFFFFFFFFFEui64) )
              v19 = BinString::sEmptyString;
            v20 = UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&priority, v19);
            UFG::qWiseSymbol::operator=(&v1->mSoundbankSymbol, v20);
            _((AMD_HD3D *)priority.mUID);
            UFG::TiDo::LoadWwiseBank(&v1->mSoundbankSymbol);
          }
        }
        v21 = v1->mpNISNode->mLightGroupObject;
        if ( v21 )
          NISLightGroup::PreLoadResource(v21);
        v22 = &NISManager::sInstance->mpPreloadInstance;
        if ( NISManager::sInstance->mpPreloadInstance.m_pPointer )
        {
          v23 = v22->mPrev;
          v24 = NISManager::sInstance->mpPreloadInstance.mNext;
          v23->mNext = v24;
          v24->mPrev = v23;
          v22->mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v22->mPrev;
          v22->mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v22->mPrev;
        }
        v22->m_pPointer = v1;
        v25 = v1->m_SafePointerList.mNode.mPrev;
        v25->mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v22->mPrev;
        v22->mPrev = v25;
        v22->mNext = &v1->m_SafePointerList.mNode;
        v1->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v22->mPrev;
        v1->mStatus = 3;
      }
    }
  }
}

// File Line: 229
// RVA: 0x3E34E0
void __fastcall NISInstance::LoadAnimations(NISInstance *this)
{
  NISInstance *v1; // rbx
  UFG::qSafePointer<NISInstance,NISInstance> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v4; // rax

  v1 = this;
  if ( this->mpNISNode )
  {
    AnimationGroupHandle::SetAnimationPriority(&this->mAnimationGroupHandle, eANIM_PRIORITY_ACTIVE_NIS, 0);
    AnimationGroupHandle::SetAnimationPriority(&v1->mFacialAnimGroupHandle, eANIM_PRIORITY_ACTIVE_NIS, 0);
    AnimationGroupHandle::SetAnimationPriority(&v1->mExtraFacialAnimGroupHandle, eANIM_PRIORITY_ACTIVE_NIS, 0);
    if ( !v1->mAnimationGroupHandle.m_AnimationGroup.m_pPointer )
      AnimationGroupHandle::Bind(&v1->mAnimationGroupHandle);
    if ( v1->mFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1
      && !v1->mFacialAnimGroupHandle.m_AnimationGroup.m_pPointer )
    {
      AnimationGroupHandle::Bind(&v1->mFacialAnimGroupHandle);
    }
    if ( v1->mExtraFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1
      && !v1->mExtraFacialAnimGroupHandle.m_AnimationGroup.m_pPointer )
    {
      AnimationGroupHandle::Bind(&v1->mExtraFacialAnimGroupHandle);
    }
    if ( v1->mStatus == 3 )
    {
      v2 = &NISManager::sInstance->mpPreloadInstance;
      if ( NISManager::sInstance->mpPreloadInstance.m_pPointer )
      {
        v3 = v2->mPrev;
        v4 = NISManager::sInstance->mpPreloadInstance.mNext;
        v3->mNext = v4;
        v4->mPrev = v3;
        v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v2->mPrev;
        v2->mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v2->mPrev;
      }
      v2->m_pPointer = 0i64;
    }
    v1->mStatus = 4;
  }
}

// File Line: 255
// RVA: 0x3E3310
void __fastcall NISInstance::LoadAllResources(NISInstance *this)
{
  NISInstance *v1; // rbp
  unsigned int v2; // esi
  int v3; // er14
  NISActorNode *v4; // rax
  UFG::qSymbol *v5; // rbx
  bool v6; // dl
  UFG::SimObjectCharacter *v7; // rax
  signed __int64 v8; // rdi
  unsigned __int16 v9; // dx
  UFG::StreamedResourceComponent *v10; // rbx
  UFG::SimComponent *v11; // rax
  UFG::qSafePointer<NISInstance,NISInstance> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v14; // rax

  v1 = this;
  if ( this->mpNISNode )
  {
    NISInstance::Preload(this);
    NISInstance::LoadAnimations(v1);
    v2 = 0;
    v3 = ((__int64 (*)(void))v1->mpNISNode->vfptr[1].GetClassname)();
    if ( v3 > 0 )
    {
      do
      {
        v4 = (NISActorNode *)((__int64 (__fastcall *)(NISNode *, _QWORD))v1->mpNISNode->vfptr[1].Serialize)(
                               v1->mpNISNode,
                               v2);
        v5 = (UFG::qSymbol *)v4;
        v6 = v4->mHighDef || NISManager::sInstance->mHighDefModelsEnabled;
        NISActorNode::SetupActor(v4, v6);
        v7 = (UFG::SimObjectCharacter *)UFG::Simulation::GetSimObject(&UFG::gSim, v5 + 64);
        if ( v7 != LocalPlayer )
        {
          v8 = (signed __int64)&v1->mMeshResources.p[v2];
          if ( v7 )
          {
            v9 = v7->m_Flags;
            if ( (v9 >> 14) & 1 )
            {
              v10 = (UFG::StreamedResourceComponent *)v7->m_Components.p[10].m_pComponent;
            }
            else if ( (v9 & 0x8000u) == 0 )
            {
              if ( (v9 >> 13) & 1 )
              {
                v10 = (UFG::StreamedResourceComponent *)v7->m_Components.p[7].m_pComponent;
              }
              else
              {
                v11 = (v9 >> 12) & 1 ? UFG::SimObjectGame::GetComponentOfTypeHK(
                                         (UFG::SimObjectGame *)&v7->vfptr,
                                         UFG::StreamedResourceComponent::_TypeUID) : UFG::SimObject::GetComponentOfType(
                                                                                       (UFG::SimObject *)&v7->vfptr,
                                                                                       UFG::StreamedResourceComponent::_TypeUID);
                v10 = (UFG::StreamedResourceComponent *)v11;
              }
            }
            else
            {
              v10 = (UFG::StreamedResourceComponent *)v7->m_Components.p[10].m_pComponent;
            }
            if ( v10
              && !UFG::TrueCrowdSet::Instance::IsEqual(
                    (UFG::TrueCrowdSet::Instance *)(v8 + 184),
                    &v10->mMeshLoader.mTrueCrowdInstance) )
            {
              UFG::StreamedResourceComponent::ClearResources(v10);
              UFG::StreamedResourceComponent::SetResourceSignature(v10, (UFG::TrueCrowdSet::Instance *)(v8 + 184));
            }
          }
        }
        ++v2;
      }
      while ( (signed int)v2 < v3 );
    }
    if ( v1->mStatus == 3 )
    {
      v12 = &NISManager::sInstance->mpPreloadInstance;
      if ( NISManager::sInstance->mpPreloadInstance.m_pPointer )
      {
        v13 = v12->mPrev;
        v14 = NISManager::sInstance->mpPreloadInstance.mNext;
        v13->mNext = v14;
        v14->mPrev = v13;
        v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v12->mPrev;
        v12->mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v12->mPrev;
      }
      v12->m_pPointer = 0i64;
    }
    v1->mStatus = 4;
  }
}

// File Line: 308
// RVA: 0x3E6230
void __fastcall NISInstance::Unload(NISInstance *this, bool bAllowDestroy)
{
  NISInstance *v2; // rdi
  bool v3; // r14
  unsigned int v4; // ebx
  int v5; // ebp
  __int64 v6; // rsi
  UFG::qBaseNodeRB *v7; // rax
  NISLightGroup *v8; // rdx
  UFG::SimObject *v9; // rdx
  UFG::qSafePointer<NISInstance,NISInstance> *v10; // r8
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v11; // rcx
  UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *v12; // rax

  v2 = this;
  v3 = bAllowDestroy;
  if ( this->mpNISNode )
  {
    AnimationGroupHandle::SetAnimationPriority(&this->mAnimationGroupHandle, 0, 0);
    AnimationGroupHandle::Unbind(&v2->mAnimationGroupHandle);
    if ( v2->mFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
    {
      AnimationGroupHandle::SetAnimationPriority(&v2->mFacialAnimGroupHandle, 0, 0);
      AnimationGroupHandle::Unbind(&v2->mFacialAnimGroupHandle);
    }
    if ( v2->mExtraFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
    {
      AnimationGroupHandle::SetAnimationPriority(&v2->mExtraFacialAnimGroupHandle, 0, 0);
      AnimationGroupHandle::Unbind(&v2->mExtraFacialAnimGroupHandle);
    }
    v4 = 0;
    v5 = ((__int64 (*)(void))v2->mpNISNode->vfptr[1].GetClassname)();
    if ( v5 > 0 )
    {
      do
      {
        v6 = ((__int64 (__fastcall *)(NISNode *, _QWORD))v2->mpNISNode->vfptr[1].Serialize)(v2->mpNISNode, v4);
        v7 = UFG::Simulation::GetSimObject(&UFG::gSim, (UFG::qSymbol *)(v6 + 256));
        if ( *(_BYTE *)(v6 + 267) && v7 )
        {
          *(_BYTE *)(v6 + 267) = 0;
          UFG::SimObjectUtility::DowngradeModelResolution((UFG::SimObject *)v7);
        }
        *(_WORD *)(v6 + 271) = 0;
        UFG::MeshResourceLoader::Unload(&v2->mMeshResources.p[v4++]);
      }
      while ( (signed int)v4 < v5 );
    }
    if ( v2->mSoundbankSymbol.mUID != UFG::qWiseSymbol::get_null()->mUID )
    {
      UFG::TiDo::UnloadWwiseBank(&v2->mSoundbankSymbol);
      UFG::qWiseSymbol::set_null(&v2->mSoundbankSymbol);
    }
    v8 = v2->mpNISNode->mLightGroupObject;
    if ( v8 )
    {
      v9 = v8->mSimObject.m_pPointer;
      if ( v9 )
        UFG::Simulation::DestroySimObject(&UFG::gSim, v9);
    }
    if ( v2->mStatus == 3 )
    {
      v10 = &NISManager::sInstance->mpPreloadInstance;
      if ( NISManager::sInstance->mpPreloadInstance.m_pPointer )
      {
        v11 = v10->mPrev;
        v12 = NISManager::sInstance->mpPreloadInstance.mNext;
        v11->mNext = v12;
        v12->mPrev = v11;
        v10->mPrev = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v10->mPrev;
        v10->mNext = (UFG::qNode<UFG::qSafePointerBase<NISInstance>,UFG::qSafePointerNodeList> *)&v10->mPrev;
      }
      v10->m_pPointer = 0i64;
    }
    v2->mStatus = 1;
  }
  if ( v3 )
  {
    if ( v2->mbDestroyOnUnload )
      v2->vfptr->__vecDelDtor((UFG::qSafePointerNode<NISInstance> *)&v2->vfptr, 1u);
  }
}

// File Line: 382
// RVA: 0x3E1820
char __fastcall NISInstance::AreAnimationsLoaded(NISInstance *this)
{
  NISInstance *v1; // rbx
  AnimationGroup *v2; // rcx
  bool v3; // dl
  AnimationGroup *v4; // rcx
  AnimationGroup *v5; // rcx

  v1 = this;
  v2 = this->mAnimationGroupHandle.m_AnimationGroup.m_pPointer;
  if ( v2 && AnimationGroup::IsStreamedIn(v2) )
  {
    v3 = 1;
    if ( v1->mpNISNode->mPrimaryCameraAnimationTrack )
      v3 = NISInstance::IsCameraAnimationValid(v1);
  }
  else
  {
    v3 = 0;
  }
  if ( v1->mFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID != -1 )
    v3 = v3 && (v4 = v1->mFacialAnimGroupHandle.m_AnimationGroup.m_pPointer) != 0i64 && AnimationGroup::IsStreamedIn(v4);
  if ( v1->mExtraFacialAnimGroupHandle.m_AnimationGroupSymbol.mUID == -1 )
    return v3;
  if ( v3 )
  {
    v5 = v1->mExtraFacialAnimGroupHandle.m_AnimationGroup.m_pPointer;
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
  NISInstance *v1; // rbp
  signed int v2; // edi
  signed int v3; // ebx
  char i; // si

  v1 = this;
  if ( !this->mpNISNode )
    return 0;
  v2 = this->mMeshResources.size;
  v3 = 0;
  for ( i = 1; v3 < v2; ++v3 )
  {
    i &= UFG::MeshResourceLoader::IsLoaded(&v1->mMeshResources.p[v3]);
    if ( !i )
      break;
  }
  return i;
}

// File Line: 450
// RVA: 0x3E3200
bool __fastcall NISInstance::IsLightGroupLoaded(NISInstance *this)
{
  NISNode *v1; // rax
  NISLightGroup *v2; // rax
  UFG::DataStreamer::Handle *v3; // rcx
  bool result; // al

  v1 = this->mpNISNode;
  result = 0;
  if ( v1 )
  {
    v2 = v1->mLightGroupObject;
    if ( !v2
      || !v2->mValid
      || (v3 = &v2->mLightRigHandle->mHandle) != 0i64 && (unsigned int)UFG::DataStreamer::GetStreamState(v3) == 6 )
    {
      result = 1;
    }
  }
  return result;
}

// File Line: 468
// RVA: 0x3E3140
char __fastcall NISInstance::IsAudioResourceLoaded(NISInstance *this, hkgpIndexedMeshDefinitions::Edge *a2)
{
  NISInstance *v2; // rdi
  bool v4; // bl
  UFG::qWiseSymbol *v5; // rax
  unsigned int v6; // ecx

  v2 = this;
  if ( Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat((hkgpIndexedMesh::EdgeBarrier *)this, a2) )
    return 1;
  v4 = 1;
  v5 = UFG::qWiseSymbol::get_null();
  v6 = v2->mSoundbankSymbol.mUID;
  if ( v6 != v5->mUID )
    v4 = UFG::TiDo::BankLoaded(v6);
  return v4;
}

// File Line: 482
// RVA: 0x3E3240
bool __fastcall NISInstance::IsLoaded(NISInstance *this)
{
  NISInstance *v1; // rsi
  char v2; // r14
  char v3; // al
  UFG::DataStreamer::Handle *v4; // rcx
  NISNode *v5; // rdx
  char v6; // bp
  bool v7; // bl
  bool v8; // di
  UFG::qWiseSymbol *v9; // rax
  unsigned int v10; // ecx

  v1 = this;
  v2 = NISInstance::AreAnimationsLoaded(this);
  v3 = NISInstance::AreAllActorsLoaded(v1);
  v5 = v1->mpNISNode;
  v6 = v3;
  v7 = 0;
  if ( v5 )
  {
    v5 = (NISNode *)v5->mLightGroupObject;
    if ( !v5
      || !LOBYTE(v5->mFirstCallback)
      || (v4 = *(UFG::DataStreamer::Handle **)&v5->mAllowLetterbox) != 0i64
      && (unsigned int)UFG::DataStreamer::GetStreamState(v4) == 6 )
    {
      v7 = 1;
    }
  }
  v8 = 1;
  if ( !Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
          (hkgpIndexedMesh::EdgeBarrier *)v4,
          (hkgpIndexedMeshDefinitions::Edge *)v5) )
  {
    v9 = UFG::qWiseSymbol::get_null();
    v10 = v1->mSoundbankSymbol.mUID;
    if ( v10 != v9->mUID )
      v8 = UFG::TiDo::BankLoaded(v10);
  }
  return v2 && v6 && v7 && v8;
}

// File Line: 493
// RVA: 0x3E3190
bool __fastcall NISInstance::IsCameraAnimationValid(NISInstance *this)
{
  CameraAnimationTrack *v1; // r8
  AnimationGroup *v2; // rdx
  unsigned int v3; // er11
  unsigned int v4; // er8
  _QWORD *v5; // rcx

  v1 = this->mpNISNode->mPrimaryCameraAnimationTrack;
  if ( !v1 )
    return 0;
  v2 = this->mAnimationGroupHandle.m_AnimationGroup.m_pPointer;
  if ( !v2 )
    return 0;
  v3 = v1->mAnimationName.mUID;
  v4 = 0;
  v5 = (__int64 *)((char *)&v2->mAnimations.mData.mOffset + v2->mAnimations.mData.mOffset);
  if ( !(v2->mAnimations.mCount & 0x7FFFFFFF) )
    return 0;
  while ( *(_DWORD *)((char *)v5 + *v5 + 168) != v3 )
  {
    ++v4;
    ++v5;
    if ( v4 >= (v2->mAnimations.mCount & 0x7FFFFFFFu) )
      return 0;
  }
  return *(_QWORD *)((char *)v5 + *v5 + 104) != 0i64;
}

// File Line: 512
// RVA: 0x3E1670
signed __int64 __fastcall NISInstance::AreActorsReady(NISInstance *this)
{
  NISInstance *v1; // r14
  NISNode *v2; // rcx
  unsigned __int8 v3; // si
  unsigned int v4; // edi
  unsigned int v5; // ebp
  UFG::qSymbol *v6; // rax
  UFG::SimObjectGame *v7; // rax
  unsigned __int16 v8; // cx
  UFG::StreamedResourceComponent *v9; // rbx
  UFG::SimComponent *v10; // rax
  char v11; // si

  v1 = this;
  v2 = this->mpNISNode;
  v3 = 1;
  if ( !v2 )
    return 1i64;
  v4 = 0;
  v5 = ((__int64 (*)(void))v2->vfptr[1].GetClassname)();
  if ( !v5 )
    return 1i64;
  do
  {
    v6 = (UFG::qSymbol *)((__int64 (__fastcall *)(NISNode *, _QWORD))v1->mpNISNode->vfptr[1].Serialize)(
                           v1->mpNISNode,
                           v4);
    v7 = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, v6 + 64);
    if ( v7 )
    {
      v8 = v7->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v9 = (UFG::StreamedResourceComponent *)v7->m_Components.p[10].m_pComponent;
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
        {
          v9 = (UFG::StreamedResourceComponent *)v7->m_Components.p[7].m_pComponent;
        }
        else
        {
          if ( (v8 >> 12) & 1 )
            v10 = UFG::SimObjectGame::GetComponentOfTypeHK(v7, UFG::StreamedResourceComponent::_TypeUID);
          else
            v10 = UFG::SimObject::GetComponentOfType(
                    (UFG::SimObject *)&v7->vfptr,
                    UFG::StreamedResourceComponent::_TypeUID);
          v9 = (UFG::StreamedResourceComponent *)v10;
        }
      }
      else
      {
        v9 = (UFG::StreamedResourceComponent *)v7->m_Components.p[10].m_pComponent;
      }
      if ( v9 )
      {
        v11 = UFG::StreamedResourceComponent::AreResourcesLoaded(v9) & v3;
        v3 = UFG::StreamedResourceComponent::AreResourcesBound(v9) & v11;
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
  NISInstance *v2; // r14
  NISNode *v3; // rcx
  float v4; // xmm6_4
  unsigned int v5; // esi
  unsigned int v6; // ebp
  UFG::qSymbol *v7; // rax
  UFG::SimObjectGame *v8; // rax
  UFG::SimObjectGame *v9; // rbx
  unsigned __int16 v10; // dx
  UFG::StreamedResourceComponent *v11; // rdi
  UFG::SimComponent *v12; // rax
  UFG::TransformNodeComponent *v13; // rbx
  float v14; // xmm1_4
  float v15; // xmm0_4
  UFG::qVector3 streamPosition; // [rsp+20h] [rbp-28h]

  v2 = this;
  v3 = this->mpNISNode;
  v4 = deltaSeconds;
  if ( v3 )
  {
    v5 = 0;
    v6 = ((__int64 (*)(void))v3->vfptr[1].GetClassname)();
    if ( v6 )
    {
      do
      {
        v7 = (UFG::qSymbol *)((__int64 (__fastcall *)(NISNode *, _QWORD))v2->mpNISNode->vfptr[1].Serialize)(
                               v2->mpNISNode,
                               v5);
        v8 = (UFG::SimObjectGame *)UFG::Simulation::GetSimObject(&UFG::gSim, v7 + 64);
        v9 = v8;
        if ( v8 )
        {
          v10 = v8->m_Flags;
          if ( (v10 >> 14) & 1 )
          {
            v11 = (UFG::StreamedResourceComponent *)v8->m_Components.p[10].m_pComponent;
          }
          else if ( (v10 & 0x8000u) == 0 )
          {
            if ( (v10 >> 13) & 1 )
            {
              v11 = (UFG::StreamedResourceComponent *)v8->m_Components.p[7].m_pComponent;
            }
            else
            {
              if ( (v10 >> 12) & 1 )
                v12 = UFG::SimObjectGame::GetComponentOfTypeHK(v8, UFG::StreamedResourceComponent::_TypeUID);
              else
                v12 = UFG::SimObject::GetComponentOfType(
                        (UFG::SimObject *)&v8->vfptr,
                        UFG::StreamedResourceComponent::_TypeUID);
              v11 = (UFG::StreamedResourceComponent *)v12;
            }
          }
          else
          {
            v11 = (UFG::StreamedResourceComponent *)v8->m_Components.p[10].m_pComponent;
          }
          v13 = v9->m_pTransformNodeComponent;
          if ( v11 )
          {
            if ( v13 )
            {
              UFG::TransformNodeComponent::UpdateWorldTransform(v13);
              v14 = v13->mWorldTransform.v3.y;
              streamPosition.x = v13->mWorldTransform.v3.x;
              v15 = v13->mWorldTransform.v3.z;
              streamPosition.y = v14;
              streamPosition.z = v15;
              UFG::StreamedResourceComponent::Update(v11, v4, &streamPosition);
            }
          }
        }
        ++v5;
      }
      while ( v5 < v6 );
    }
  }
}

