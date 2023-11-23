// File Line: 55
// RVA: 0x1453980
__int64 Render::_dynamic_initializer_for__sDecalVertexDeclUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("VertexDecl.SkinnedDecal", 0xFFFFFFFF);
  sDecalVertexDeclUID = result;
  return result;
}

// File Line: 57
// RVA: 0x1453960
__int64 dynamic_initializer_for__Render::Skinning::gSkinning__()
{
  Render::Skinning::Skinning(&Render::Skinning::gSkinning);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::Skinning::gSkinning__);
}

// File Line: 96
// RVA: 0x1E780
UFG::qBaseNodeVariableRB<unsigned __int64> *__fastcall Render::PersistentSkinningCache::Store(
        Render::PersistentSkinningCache *this,
        unsigned __int64 uid,
        unsigned __int64 size)
{
  Render::PersistentSkinningCache *v5; // rbx
  bool i; // zf
  Render::PersistentSkinningCache *j; // rax
  UFG::qList<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode,1,0> *p_mCachedVertexDataList; // r14
  $CA91B2824B6F331601351B2AC7FEF5D9 *v9; // r13
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *mNext; // rdx
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *mPrev; // rcx
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v12; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v13; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *mParent; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v15; // rax
  char *v17; // r12
  char *v18; // rax
  _QWORD *v19; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v20; // rax
  unsigned int sizea; // [rsp+80h] [rbp+18h]

  sizea = size;
  if ( uid )
  {
    v5 = this;
    for ( i = this == (Render::PersistentSkinningCache *)&this->mCachedVertexDataTree.mTree.mNULL;
          !i;
          i = v5 == (Render::PersistentSkinningCache *)&this->mCachedVertexDataTree.mTree.mNULL )
    {
      if ( v5 != this && v5->mCachedVertexDataTree.mTree.mRoot.mUID == uid )
      {
        for ( j = (Render::PersistentSkinningCache *)v5->mCachedVertexDataTree.mTree.mRoot.mChild[0];
              j;
              j = (Render::PersistentSkinningCache *)j->mCachedVertexDataTree.mTree.mRoot.mChild[0] )
        {
          if ( j->mCachedVertexDataTree.mTree.mRoot.mUID != uid )
            break;
          v5 = j;
        }
        goto LABEL_15;
      }
      if ( uid > v5->mCachedVertexDataTree.mTree.mRoot.mUID )
        v5 = (Render::PersistentSkinningCache *)v5->mCachedVertexDataTree.mTree.mRoot.mChild[1];
      else
        v5 = (Render::PersistentSkinningCache *)v5->mCachedVertexDataTree.mTree.mRoot.mChild[0];
    }
  }
  v5 = 0i64;
LABEL_15:
  if ( !v5 )
  {
    p_mCachedVertexDataList = &this->mCachedVertexDataList;
    v9 = &this->mCachedVertexDataTree.mTree.mNULL.8;
    if ( ($CA91B2824B6F331601351B2AC7FEF5D9 *)&this->mCachedVertexDataList.mNode.mNext[-2] != &this->mCachedVertexDataTree.mTree.mNULL.8 )
    {
      while ( UFG::qMemoryPool::GetLargestFree(&this->mCachedVertexDataPool, 0i64) < sizea )
      {
        mNext = this->mCachedVertexDataList.mNode.mNext;
        if ( LODWORD(mNext[2].mPrev) == Illusion::gEngine.mFrameCount )
          return 0i64;
        mPrev = mNext->mPrev;
        v12 = mNext->mNext;
        mPrev->mNext = v12;
        v12->mPrev = mPrev;
        mNext->mPrev = mNext;
        mNext->mNext = mNext;
        v13 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&mNext[-2];
        UFG::qMemoryPool::Free(&this->mCachedVertexDataPool, mNext[1].mPrev);
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&this->mCachedVertexDataTree.mTree, v13);
        Render::gPersistentCacheUsageKB -= v13[1].mUID >> 10;
        --Render::gPersistentCacheUsageEntries;
        mParent = v13[1].mParent;
        v15 = v13[1].mChild[0];
        mParent->mChild[0] = v15;
        v15->mParent = mParent;
        v13[1].mParent = v13 + 1;
        v13[1].mChild[0] = v13 + 1;
        operator delete[](v13);
        if ( ($CA91B2824B6F331601351B2AC7FEF5D9 *)&p_mCachedVertexDataList->mNode.mNext[-2] == v9 )
          break;
      }
    }
    v17 = UFG::qMemoryPool::Allocate(&this->mCachedVertexDataPool, sizea, "persistent_cache_alloc", 0i64, 1u);
    v18 = UFG::qMalloc(0x48ui64, "PersistentSkinningCacheNode", 0x800ui64);
    v5 = (Render::PersistentSkinningCache *)v18;
    if ( v18 )
    {
      *(_QWORD *)v18 = 0i64;
      *((_QWORD *)v18 + 1) = 0i64;
      *((_QWORD *)v18 + 2) = 0i64;
      *((_QWORD *)v18 + 3) = uid;
      v19 = v18 + 32;
      *v19 = v19;
      v19[1] = v19;
      v5->mCachedVertexDataTree.mTree.mNULL.mChild[1] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v17;
      v5->mCachedVertexDataTree.mTree.mNULL.mUID = sizea;
      v5->mCachedVertexDataTree.mTree.mCount = Illusion::gEngine.mFrameCount;
    }
    else
    {
      v5 = 0i64;
    }
    v20 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)p_mCachedVertexDataList->mNode.mPrev;
    v20->mChild[0] = &v5->mCachedVertexDataTree.mTree.mNULL;
    v5->mCachedVertexDataTree.mTree.mNULL.mParent = v20;
    v5->mCachedVertexDataTree.mTree.mNULL.mChild[0] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)p_mCachedVertexDataList;
    p_mCachedVertexDataList->mNode.mPrev = (UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *)&v5->mCachedVertexDataTree.mTree.mNULL;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Add(
      &this->mCachedVertexDataTree.mTree,
      &v5->mCachedVertexDataTree.mTree.mRoot);
    Render::gPersistentCacheUsageKB += v5->mCachedVertexDataTree.mTree.mNULL.mUID >> 10;
    ++Render::gPersistentCacheUsageEntries;
  }
  return v5->mCachedVertexDataTree.mTree.mNULL.mChild[1];
}

// File Line: 130
// RVA: 0x1BF40
void __fastcall Render::SkinClipInfo::SkinClipInfo(Render::SkinClipInfo *this, unsigned int num_results)
{
  unsigned int i; // ebp
  char *v4; // rax
  Render::SkinClipInfo::ClipResult *v5; // rdi
  int v6; // esi
  char *v7; // rbx

  *(_WORD *)&this->mQueryReady = 0;
  this->mMaxResults = num_results;
  for ( i = 0; i < this->mMaxResults; ++i )
  {
    v4 = UFG::qMalloc(0x588ui64, "ClipResult", 0x1000ui64);
    v5 = (Render::SkinClipInfo::ClipResult *)v4;
    if ( v4 )
    {
      v6 = 31;
      v7 = v4 + 40;
      do
      {
        `vector constructor iterator(v7, 2ui64, 2, (void *(__fastcall *)(void *))UFG::qHalfFloat::qHalfFloat);
        v7 += 44;
        --v6;
      }
      while ( v6 >= 0 );
    }
    else
    {
      v5 = 0i64;
    }
    v5->mResultVertNum = 0;
    v5->mResultReady = 0;
    this->mResults[i] = v5;
  }
}

// File Line: 153
// RVA: 0x1C5B0
char __fastcall Render::SkinClipInfo::AllResultsReady(Render::SkinClipInfo *this)
{
  unsigned int mMaxResults; // r8d
  unsigned int v2; // edx

  mMaxResults = this->mMaxResults;
  v2 = 0;
  if ( !mMaxResults )
    return 1;
  while ( this->mResults[0]->mResultReady )
  {
    ++v2;
    this = (Render::SkinClipInfo *)((char *)this + 8);
    if ( v2 >= mMaxResults )
      return 1;
  }
  return 0;
}

// File Line: 183
// RVA: 0x1E9B0
char __fastcall Render::SkinClipInfo::SubmitClipQuery(
        Render::SkinClipInfo *this,
        UFG::qMatrix44 *decal_world,
        UFG::qMatrix44 *model_local_world,
        float radius,
        UFG::qVector4 *aabb_min,
        UFG::qVector4 *aabb_max,
        float cutoff,
        float decal_depth)
{
  unsigned int mMaxResults; // r11d
  int v11; // r10d
  UFG::qVector4 v12; // xmm3
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  unsigned int v15; // edx
  UFG::qVector4 v16; // xmm2
  UFG::qVector4 v17; // xmm1
  UFG::qVector4 v18; // xmm3
  float y; // xmm0_4
  float v20; // xmm0_4
  __int64 v21; // rcx

  if ( this->mQueryReady )
    return 0;
  mMaxResults = this->mMaxResults;
  v11 = 0;
  if ( mMaxResults )
  {
    while ( !this->mResults[v11]->mResultReady )
    {
      if ( ++v11 >= mMaxResults )
        goto LABEL_5;
    }
    return 0;
  }
LABEL_5:
  v12 = decal_world->v1;
  v13 = decal_world->v2;
  v14 = decal_world->v3;
  this->mDecalWorld.v0 = decal_world->v0;
  this->mDecalWorld.v1 = v12;
  v15 = 0;
  this->mDecalWorld.v2 = v13;
  this->mDecalWorld.v3 = v14;
  v16 = model_local_world->v2;
  v17 = model_local_world->v3;
  v18 = model_local_world->v1;
  this->mModelLocalWorld.v0 = model_local_world->v0;
  this->mModelLocalWorld.v1 = v18;
  this->mModelLocalWorld.v2 = v16;
  this->mModelLocalWorld.v3 = v17;
  this->mRadius = radius;
  y = aabb_min->y;
  v17.x = aabb_min->z;
  v16.x = aabb_min->w;
  this->mModelAABBMin.x = aabb_min->x;
  this->mModelAABBMin.y = y;
  this->mModelAABBMin.z = v17.x;
  this->mModelAABBMin.w = v16.x;
  v20 = aabb_max->y;
  v17.x = aabb_max->z;
  v16.x = aabb_max->w;
  this->mModelAABBMax.x = aabb_max->x;
  this->mModelAABBMax.y = v20;
  this->mModelAABBMax.z = v17.x;
  this->mModelAABBMax.w = v16.x;
  this->mDecalCutoff = cutoff;
  this->mDecalDepth = decal_depth;
  if ( mMaxResults )
  {
    do
    {
      v21 = v15++;
      this->mResults[v21]->mResultReady = 0;
      this->mResults[v21]->mResultVertNum = 0;
    }
    while ( v15 < this->mMaxResults );
  }
  *(_WORD *)&this->mQueryReady = 1;
  return 1;
}

// File Line: 209
// RVA: 0x1DFF0
__int64 __fastcall Render::SkinClipInfo::GetResultVertexCount(Render::SkinClipInfo *this)
{
  signed int mMaxResults; // r11d
  int v2; // edx
  int v3; // r9d
  unsigned int mResultVertNum; // ebx
  unsigned int v5; // edi
  __int64 v6; // r8
  unsigned int v7; // eax
  __int64 v8; // r10
  Render::SkinClipInfo::ClipResult *v9; // rax

  mMaxResults = this->mMaxResults;
  v2 = 0;
  v3 = 0;
  mResultVertNum = 0;
  v5 = 0;
  v6 = 0i64;
  if ( mMaxResults >= 2 )
  {
    v7 = ((unsigned int)(mMaxResults - 2) >> 1) + 1;
    v8 = v7;
    v5 = 2 * v7;
    do
    {
      v9 = this->mResults[v6];
      v6 += 2i64;
      v2 += v9->mResultVertNum;
      v3 += this->mResults[v6 - 1]->mResultVertNum;
      --v8;
    }
    while ( v8 );
  }
  if ( v5 < mMaxResults )
    mResultVertNum = this->mResults[v6]->mResultVertNum;
  return mResultVertNum + v3 + v2;
}

// File Line: 219
// RVA: 0x1E110
char __fastcall Render::SkinClipInfo::ReadQueryResult(
        Render::SkinClipInfo *this,
        Render::SkinClipInfo::ClipOutputVertex *clip_verts,
        unsigned int clip_vert_num,
        unsigned int *result_verts_written)
{
  unsigned int mMaxResults; // ecx
  int v9; // eax
  unsigned int v10; // ebx
  const void **v11; // rsi
  unsigned int v12; // ebp

  *result_verts_written = 0;
  mMaxResults = this->mMaxResults;
  v9 = 0;
  if ( mMaxResults )
  {
    while ( this->mResults[v9]->mResultReady )
    {
      if ( ++v9 >= mMaxResults )
        goto LABEL_4;
    }
    return 0;
  }
  else
  {
LABEL_4:
    v10 = 0;
    if ( mMaxResults )
    {
      do
      {
        v11 = (const void **)&this->mResults[v10];
        v12 = *((_DWORD *)*v11 + 353);
        if ( clip_vert_num >= v12 )
        {
          UFG::qMemCopy(clip_verts, *v11, 44 * v12);
          *result_verts_written += v12;
          clip_verts += v12;
          clip_vert_num -= v12;
        }
        ++v10;
        *((_BYTE *)*v11 + 1408) = 0;
        *((_DWORD *)*v11 + 353) = 0;
      }
      while ( v10 < this->mMaxResults );
    }
    *(_WORD *)&this->mQueryReady = 0;
    return 1;
  }
}

// File Line: 253
// RVA: 0x1C840
UFG::BitFlags128 *__fastcall Render::DefaultRenderMeshFunc(
        UFG::BitFlags128 *result,
        Render::View *view,
        Illusion::Mesh *mesh,
        UFG::qMatrix44 *local_world)
{
  Render::View::Draw(view, result, mesh, local_world);
  return result;
}

// File Line: 258
// RVA: 0x1C8A0
UFG::BitFlags128 *__fastcall Render::DefaultRenderRMeshFunc(
        UFG::BitFlags128 *result,
        Render::View *view,
        Illusion::rMesh *rmesh,
        UFG::qMatrix44 *local_world,
        Illusion::rMaterial *rmaterial,
        UFG::BitFlags128 *already_called_funcs_mask)
{
  Illusion::StateArgs *StateArgs; // rbx
  Render::ViewSettings *mSettings; // r15
  unsigned __int16 Param; // ax
  unsigned __int16 v13; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v16; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v17; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rax
  unsigned __int64 *v19; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v20; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v21; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v26; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v27; // rax
  Render::cbLocalProjectionState v29; // [rsp+30h] [rbp-A1h] BYREF
  Render::cbLocalTransformInverseState arg; // [rsp+68h] [rbp-69h] BYREF
  Render::cbLocalTransformState v31; // [rsp+A0h] [rbp-31h] BYREF
  UFG::BitFlags128 v32; // [rsp+D0h] [rbp-1h] BYREF
  __int64 v33; // [rsp+E0h] [rbp+Fh]

  v33 = -2i64;
  StateArgs = Render::View::GetStateArgs(view);
  mSettings = view->mSettings;
  Render::cbLocalTransformState::cbLocalTransformState(
    &v31,
    &view->mSettings->mWorldView,
    &view->mWorldViewProjection,
    local_world);
  v29.mPrev = &v29;
  v29.mNext = &v29;
  v29.mCallback = 0i64;
  v29.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
  *(_WORD *)&v29.mFlags = 1;
  if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == 0xFFFF )
  {
    Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
    Render::cbLocalProjectionState::sStateParamIndex = Param;
    v29.mStateParamIndex = Param;
  }
  v29.mCached_Remote.m_Stream = 0i64;
  v29.mWorldViewProjection = &view->mWorldViewProjection;
  v29.mLocalWorld = local_world;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mCallback = 0i64;
  arg.mStateParamIndex = Render::cbLocalTransformInverseState::sStateParamIndex;
  *(_WORD *)&arg.mFlags = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == 0xFFFF )
  {
    v13 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v13;
    arg.mStateParamIndex = v13;
  }
  arg.mCached_Remote.m_Stream = 0i64;
  arg.mWorldView = &mSettings->mWorldView;
  arg.mLocalWorld = local_world;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(StateArgs, &v31);
  Illusion::StateArgs::Set<Render::cbLocalProjectionState>(StateArgs, &v29);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(StateArgs, &arg);
  v32 = *already_called_funcs_mask;
  Illusion::SubmitContext::Draw(view->mSubmitContext, result, rmesh, rmaterial, &v32, rmesh);
  mPrev = arg.mPrev;
  mNext = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  mNext->mPrev = mPrev;
  arg.mPrev = &arg;
  arg.mNext = &arg;
  arg.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
  {
    v16 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6];
    *v16 &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  }
  v17 = v29.mPrev;
  v18 = v29.mNext;
  v29.mPrev->mNext = v29.mNext;
  v18->mPrev = v17;
  v29.mPrev = &v29;
  v29.mNext = &v29;
  v29.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v29.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v29.mStateParamIndex] )
  {
    v19 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v29.mStateParamIndex >> 6];
    *v19 &= ~(1i64 << (v29.mStateParamIndex & 0x3F));
  }
  v20 = v31.mPrev;
  v21 = v31.mNext;
  v31.mPrev->mNext = v31.mNext;
  v21->mPrev = v20;
  v31.mPrev = &v31;
  v31.mNext = &v31;
  v31.mIsSet = 0;
  if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v31.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v31.mStateParamIndex] )
    StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v31.mStateParamIndex >> 6] &= ~(1i64 << (v31.mStateParamIndex & 0x3F));
  v22 = arg.mPrev;
  v23 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v23->mPrev = v22;
  v24 = v29.mPrev;
  v25 = v29.mNext;
  v29.mPrev->mNext = v29.mNext;
  v25->mPrev = v24;
  v26 = v31.mPrev;
  v27 = v31.mNext;
  v31.mPrev->mNext = v31.mNext;
  v27->mPrev = v26;
  return result;
}

// File Line: 280
// RVA: 0x1C830
// attributes: thunk
void __fastcall Render::DefaultRenderDecalFunc(
        Render::View *view,
        Illusion::Primitive *prim,
        Illusion::Material *material,
        UFG::qMatrix44 *local_world)
{
  Render::View::Draw(view, prim, material, local_world);
}

// File Line: 285
// RVA: 0x1E060
void __fastcall Render::Skinning::Init(Render::Skinning *this)
{
  unsigned int v1; // edi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v4; // rax

  v1 = sDecalVertexDeclUID;
  this->mTaskGroup = 0i64;
  this->mRenderMeshFunc = (UFG::BitFlags128 *(__fastcall *)(UFG::BitFlags128 *, Render::View *, Illusion::Mesh *, UFG::qMatrix44 *, Illusion::Material *, UFG::BitFlags128, const char *))Render::DefaultRenderMeshFunc;
  this->mEnablePersistentCache = 0;
  this->mRenderRMeshFunc = (UFG::BitFlags128 *(__fastcall *)(UFG::BitFlags128 *, Render::View *, Illusion::rMesh *, UFG::qMatrix44 *, Illusion::rMaterial *, UFG::BitFlags128, const char *))Render::DefaultRenderRMeshFunc;
  this->mRenderDecalFunc = Render::DefaultRenderDecalFunc;
  Inventory = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v4, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mDecalVertexDecl, 0x3E5FDA3Eu, v1, Inventory);
}

// File Line: 335
// RVA: 0x1E770
void __fastcall Render::Skinning::SetCurrentTaskGroup(Render::Skinning *this, UFG::qTaskGroup *task_group)
{
  this->mTaskGroup = task_group;
}

// File Line: 346
// RVA: 0x1C6A0
Illusion::Buffer *__fastcall Render::Skinning::AllocateVertexBuffer(
        Render::Skinning *this,
        Illusion::Buffer *source_buffer,
        unsigned int instance_uid,
        bool use_vram)
{
  unsigned __int64 v6; // r10
  Render::Skinning *v7; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *p_mNULL; // rcx
  bool i; // zf
  Render::Skinning *j; // rcx
  _DWORD *mParent; // rbx
  unsigned int v12; // edx
  UFG::qLinearAllocator *FrameWriteMemory; // rcx
  char *v14; // rsi
  unsigned int v16; // eax
  Illusion::Buffer *v17; // rax
  UFG::qOffset64<void *> *p_mData; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v19; // rdx
  __int64 v20; // rax
  __int64 data; // [rsp+88h] [rbp+10h] BYREF

  v6 = (unsigned int)source_buffer | ((unsigned __int64)instance_uid << 32);
  data = v6;
  if ( v6 )
  {
    v7 = this;
    p_mNULL = &this->mSkinnedVertexBuffers.mTree.mNULL;
    for ( i = v7 == (Render::Skinning *)p_mNULL; !i; i = v7 == (Render::Skinning *)p_mNULL )
    {
      if ( v7 != this && v7->mSkinnedVertexBuffers.mTree.mRoot.mUID == v6 )
      {
        for ( j = (Render::Skinning *)v7->mSkinnedVertexBuffers.mTree.mRoot.mChild[0];
              j;
              j = (Render::Skinning *)j->mSkinnedVertexBuffers.mTree.mRoot.mChild[0] )
        {
          if ( j->mSkinnedVertexBuffers.mTree.mRoot.mUID != v6 )
            break;
          v7 = j;
        }
        if ( v7 )
        {
          mParent = v7->mSkinnedVertexBuffers.mTree.mNULL.mParent;
          if ( mParent )
            return (Illusion::Buffer *)mParent;
        }
        break;
      }
      if ( v6 > v7->mSkinnedVertexBuffers.mTree.mRoot.mUID )
        v7 = (Render::Skinning *)v7->mSkinnedVertexBuffers.mTree.mRoot.mChild[1];
      else
        v7 = (Render::Skinning *)v7->mSkinnedVertexBuffers.mTree.mRoot.mChild[0];
    }
  }
  v12 = (source_buffer->mNumElements * source_buffer->mElementByteSize + 127) & 0xFFFFFF7F;
  FrameWriteMemory = Illusion::gEngine.FrameWriteMemory;
  if ( !use_vram )
    FrameWriteMemory = Illusion::gEngine.FrameMemory;
  v14 = UFG::qLinearAllocator::Malloc(FrameWriteMemory, v12, 0x10u);
  if ( !v14 )
    return 0i64;
  v16 = UFG::qDataHash32(&data, 8ui64, 0xFFFFFFFF);
  v17 = Illusion::Factory::NewBuffer(0i64, v16, 0x30u, 0i64, 0i64, Illusion::gEngine.FrameMemory, 0i64);
  mParent = v17;
  if ( !v17 )
    return 0i64;
  v17->mFlags |= 4u;
  p_mData = &v17->mData;
  v19 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((char *)p_mData + p_mData->mOffset);
  if ( !p_mData->mOffset )
    v19 = 0i64;
  p_mData->mOffset = v14 - (char *)p_mData;
  mParent[23] = source_buffer->mDataByteSize;
  *((_BYTE *)mParent + 88) = source_buffer->mBufferType;
  mParent[26] = source_buffer->mElementByteSize;
  mParent[27] = source_buffer->mNumElements;
  if ( v19 )
  {
    v20 = data;
    v19->mParent = 0i64;
    v19->mChild[0] = 0i64;
    v19->mChild[1] = 0i64;
    v19->mUID = v20;
    v19[1].mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)mParent;
  }
  UFG::qBaseTreeVariableRB<unsigned __int64>::Add(&this->mSkinnedVertexBuffers.mTree, v19);
  return (Illusion::Buffer *)mParent;
}

// File Line: 414
// RVA: 0x1C5E0
Illusion::Buffer *__fastcall Render::Skinning::AllocateDecalVertexBuffer(
        Render::Skinning *this,
        unsigned int decal_count)
{
  unsigned int v3; // ebx
  char *v4; // rdi
  Illusion::Buffer *result; // rax
  unsigned int v6; // eax

  v3 = (28 * decal_count + 127) & 0xFFFFFF7F;
  v4 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameWriteMemory, v3, 0x10u);
  if ( !v4 )
    return 0i64;
  v6 = UFG::qStringHashUpper32("TempSkinnedDecalWriteBuffer", 0xFFFFFFFF);
  result = Illusion::Factory::NewBuffer(
             "TempSkinnedDecalWriteBuffer",
             v6,
             0x10u,
             0i64,
             0i64,
             Illusion::gEngine.FrameMemory,
             0i64);
  if ( !result )
    return 0i64;
  result->mFlags |= 4u;
  result->mData.mOffset = v4 - (char *)&result->mData;
  result->mDataByteSize = v3;
  result->mNumElements = decal_count;
  result->mBufferType = 0;
  result->mElementByteSize = 28;
  return result;
}

// File Line: 462
// RVA: 0x1EB30
bool __fastcall Render::Skinning::SupportsSkinnedDecals(
        Render::Skinning *this,
        Illusion::ModelProxy *model_proxy,
        unsigned int *task_uid,
        unsigned int *mesh_count)
{
  unsigned int i; // edi
  UFG::qResourceData *mData; // rax
  UFG::qBaseNodeRB *v11; // rcx
  char *v12; // rcx
  char *v13; // rdx
  Illusion::Material **v14; // rcx
  Illusion::rModel *mRModel; // rdx
  __int64 v16; // rax
  unsigned int mNext; // edx
  __int64 v18; // rax
  UFG::qBaseTreeRB *v19; // rax

  if ( !model_proxy->mModelHandle.mData && !model_proxy->mRModel )
    return 0;
  if ( (_S1_1 & 1) == 0 )
  {
    _S1_1 |= 1u;
    material_shader_uid = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  }
  *mesh_count = 0;
  for ( i = 0; i < (unsigned int)Illusion::ModelProxy::GetNumMeshes(model_proxy); ++i )
  {
    mData = model_proxy->mModelHandle.mData;
    if ( !mData
      || ((v11 = mData[2].mNode.mChild[0]) == 0i64 ? (v12 = 0i64) : (v12 = (char *)&v11[5].mChild[2] + (_QWORD)mData),
          v13 = &v12[8 * i],
          v14 = (Illusion::Material **)&v13[*(_QWORD *)v13],
          !*(_QWORD *)v13) )
    {
      v14 = 0i64;
    }
    mRModel = model_proxy->mRModel;
    if ( mRModel )
      v16 = (__int64)&mRModel->mMeshes.mData.mItems[i];
    else
      v16 = 0i64;
    if ( v14 )
    {
      mNext = (unsigned int)Illusion::Material::GetParamByNameUID(v14[2], 0x5C19C934u)->mResourceHandles.UFG::qResourceData::mNode.mNext;
    }
    else
    {
      v18 = *(_QWORD *)(v16 + 48);
      if ( !v18 )
      {
        mNext = -1;
LABEL_23:
        v19 = UFG::qBaseTreeRB::Get(&this->mUserSkinningTasks.mTree, mNext);
        if ( v19 && (*(_QWORD *)&v19->mNULL.mUID || *(_QWORD *)&v19->mCount) )
        {
          *task_uid = v19->mRoot.mUID;
          ++*mesh_count;
        }
        continue;
      }
      mNext = *(_DWORD *)(*(_QWORD *)(v18 + 104) + 24i64);
    }
    if ( mNext )
      goto LABEL_23;
  }
  return *mesh_count != 0;
}

// File Line: 511
// RVA: 0x1E5B0
void __fastcall Render::Skinning::SelectSkinningTask(
        Render::Skinning *this,
        UFG::qTaskFunctionDeclData **skinning_task_decl,
        Illusion::MeshProxy *mesh_proxy,
        Illusion::Mesh *morph_mesh,
        unsigned int *task_uid,
        Render::SkinningParams *skinning_params,
        bool decal_pass)
{
  Illusion::Mesh *mMesh; // rcx
  Illusion::BufferHandle *mVertexBufferHandles; // rax
  UFG::qResourceData *mData; // r9
  Illusion::BufferHandle *v13; // rax
  UFG::qResourceData *v14; // rdx
  Illusion::BufferHandle *v15; // rax
  bool v16; // bp
  bool v17; // r15
  bool v18; // r14
  bool v19; // di
  bool v20; // si
  unsigned int mNext; // edx
  UFG::qReflectObject *v22; // rax
  UFG::qBaseTreeRB *v23; // rax
  UFG::qTaskFunctionDeclData *mParent; // rcx
  UFG::qTaskFunctionDeclData *v25; // rax

  mMesh = mesh_proxy->mMesh;
  if ( mesh_proxy->mMesh )
    mVertexBufferHandles = mMesh->mVertexBufferHandles;
  else
    mVertexBufferHandles = mesh_proxy->mRMesh->mVertexBufferHandles;
  mData = mVertexBufferHandles->mData;
  if ( mMesh )
    v13 = &mMesh->mVertexBufferHandles[1];
  else
    v13 = &mesh_proxy->mRMesh->mVertexBufferHandles[1];
  v14 = v13->mData;
  if ( mMesh )
    v15 = &mMesh->mVertexBufferHandles[2];
  else
    v15 = &mesh_proxy->mRMesh->mVertexBufferHandles[2];
  v16 = mData && v14 && v15->mData;
  v17 = morph_mesh != 0i64;
  v18 = skinning_params->morph_weights_count != 0;
  v19 = morph_mesh || skinning_params->morph_weights_count;
  v20 = skinning_params->mUsePersistentCache && this->mEnablePersistentCache;
  if ( mMesh )
  {
    mNext = (unsigned int)Illusion::Material::GetParamByNameUID(
                            (Illusion::Material *)mMesh->mMaterialHandle.mData,
                            0x5C19C934u)->mResourceHandles.UFG::qResourceData::mNode.mNext;
    goto LABEL_27;
  }
  v22 = mesh_proxy->mRMesh->mMaterial.mData;
  if ( v22 )
  {
    mNext = (unsigned int)v22[1].mBaseNode.mChildren[0]->mChildren[1];
LABEL_27:
    if ( !mNext )
      goto LABEL_41;
    goto LABEL_30;
  }
  mNext = -1;
LABEL_30:
  v23 = UFG::qBaseTreeRB::Get(&this->mUserSkinningTasks.mTree, mNext);
  if ( v23 )
  {
    if ( decal_pass )
    {
      if ( v19 )
        mParent = *(UFG::qTaskFunctionDeclData **)&v23->mCount;
      else
        mParent = *(UFG::qTaskFunctionDeclData **)&v23->mNULL.mUID;
    }
    else if ( v20 )
    {
      mParent = (UFG::qTaskFunctionDeclData *)v23->mNULL.mChild[1];
    }
    else if ( v19 )
    {
      mParent = (UFG::qTaskFunctionDeclData *)v23->mNULL.mChild[0];
    }
    else
    {
      mParent = (UFG::qTaskFunctionDeclData *)v23->mNULL.mParent;
    }
    *skinning_task_decl = mParent;
    *task_uid = v23->mRoot.mUID;
  }
LABEL_41:
  if ( !*skinning_task_decl && v16 )
  {
    if ( v17 )
    {
      v25 = &Render::gTaskFunctionDeclData_SkinMorphBufferTask;
    }
    else if ( v18 )
    {
      v25 = &Render::gTaskFunctionDeclData_MultiMorphSkinBufferTask;
    }
    else
    {
      v25 = &Render::gTaskFunctionDeclData_SkinCacheBufferTask;
      if ( !v20 )
        v25 = &Render::gTaskFunctionDeclData_SkinBufferTask;
    }
    *skinning_task_decl = v25;
  }
}

// File Line: 585
// RVA: 0x1E200
char __fastcall Render::Skinning::RegisterUserSkinningTask(
        Render::Skinning *this,
        unsigned int shader_uid,
        UFG::qTaskFunctionDeclData *skin_task_decl,
        UFG::qTaskFunctionDeclData *morph_skin_task_decl,
        UFG::qTaskFunctionDeclData *cache_skin_task_decl,
        UFG::qTaskFunctionDeclData *skin_decal_task_decl,
        UFG::qTaskFunctionDeclData *morph_skin_decal_task_decl)
{
  char *v12; // rax
  UFG::qBaseNodeRB *v13; // rdx

  if ( shader_uid && UFG::qBaseTreeRB::Get(&this->mUserSkinningTasks.mTree, shader_uid) )
    return 0;
  v12 = UFG::qMalloc(0x48ui64, "SkinningTaskNode", 0x800ui64);
  v13 = (UFG::qBaseNodeRB *)v12;
  if ( v12 )
  {
    *(_QWORD *)v12 = 0i64;
    *((_QWORD *)v12 + 1) = 0i64;
    *((_QWORD *)v12 + 2) = 0i64;
    *((_DWORD *)v12 + 6) = shader_uid;
    *((_QWORD *)v12 + 4) = skin_task_decl;
    *((_QWORD *)v12 + 5) = morph_skin_task_decl;
    *((_QWORD *)v12 + 6) = cache_skin_task_decl;
    *((_QWORD *)v12 + 7) = skin_decal_task_decl;
    *((_QWORD *)v12 + 8) = morph_skin_decal_task_decl;
  }
  else
  {
    v13 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&this->mUserSkinningTasks.mTree, v13);
  return 1;
}

// File Line: 607
// RVA: 0x1D2B0
char __fastcall Render::Skinning::DrawSkinnedModel(Render::Skinning *this, Render::SkinningParams *skinning_params)
{
  Render::Skinning *v3; // r15
  char *mDebugName; // r14
  Illusion::ModelProxy *skin_model_proxy; // rcx
  UFG::qResourceData *mData; // rdx
  Illusion::rModel *mRModel; // rcx
  Illusion::rModel *v8; // rcx
  __int64 v9; // r12
  __int128 v10; // xmm6
  Illusion::ModelProxy *v11; // rcx
  _DWORD *v12; // rax
  UFG::qResourceData *v13; // rax
  UFG::qBaseNodeRB *v14; // rdx
  UFG::qBaseNodeRB **v15; // r8
  char *v16; // rsi
  Illusion::rModel *v17; // rax
  __int64 v18; // r13
  Illusion::Mesh *v19; // rbx
  Illusion::Model *simple_morph_target; // rax
  __int64 mOffset; // rcx
  _QWORD *v22; // rdx
  Illusion::Material *v23; // r8
  UFG::qMatrix44 *mRigidTransform; // rcx
  int *v25; // rax
  int *local_transform; // rax
  int v27; // xmm1_4
  int v28; // xmm2_4
  int v29; // xmm3_4
  int v30; // xmm1_4
  int v31; // xmm2_4
  int v32; // xmm3_4
  int v33; // xmm1_4
  int v34; // xmm2_4
  int v35; // xmm3_4
  int v36; // xmm1_4
  int v37; // xmm2_4
  int v38; // xmm3_4
  unsigned int v39; // r9d
  __int128 *v40; // rax
  __int64 v41; // rax
  Illusion::Buffer *v42; // r10
  __int64 v43; // rax
  __int64 v44; // rax
  unsigned int instance_uid; // r8d
  __int64 v46; // r14
  unsigned __int64 v47; // rdx
  Render::Skinning *v48; // rax
  bool i; // zf
  Render::Skinning *j; // rcx
  Illusion::Buffer *mParent; // rbx
  bool v52; // zf
  bool v53; // r12
  unsigned __int64 v54; // r15
  unsigned int v55; // r14d
  Render::PersistentSkinningCacheNode *v56; // rax
  Render::PersistentSkinningCacheNode *v57; // r9
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v58; // r8
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *mPrev; // rdx
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *mNext; // rcx
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v61; // rax
  __int64 v62; // rax
  char *v63; // rcx
  unsigned int v64; // ebx
  char *v65; // rbx
  __int64 v66; // rax
  char *v67; // rax
  __int64 v68; // r12
  char *v69; // rax
  __int64 v70; // rdx
  __int64 v71; // rax
  char *v72; // rax
  __int64 v73; // rax
  __int64 v74; // rax
  __int64 v75; // rax
  char *v76; // rcx
  __int64 v77; // rax
  UFG::qResourceData *v78; // rax
  UFG::qBaseNodeRB *v79; // rcx
  __int64 v80; // rax
  unsigned int morph_weights_count; // ecx
  UFG::qResourceData *v82; // r14
  __int64 v83; // r14
  unsigned int v84; // r15d
  __int64 v85; // rcx
  __int64 v86; // rax
  int v87; // eax
  __int64 v88; // r9
  int v89; // r11d
  __int64 v90; // r8
  unsigned int v91; // r10d
  float v92; // xmm0_4
  int v93; // eax
  Render::SkinClipInfo *clip_info; // rcx
  int v95; // edx
  UFG::qTaskGroup *mTaskGroup; // r14
  char *v97; // rax
  UFG::qTask *v98; // rdx
  UFG::qTaskFunctionDeclData *v99; // rcx
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r9
  char *mAddress; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v105; // rax
  _QWORD *v106; // rax
  UFG::qTaskFunctionDeclData *v107; // rcx
  UFG::qSpuElf *v108; // rax
  void (__fastcall *v109)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v110)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v111)(void *, void *, void *, void *); // r9
  char *v112; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTasks; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v114; // rax
  Illusion::StateArgs *StateArgs; // rbx
  unsigned __int16 Param; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v117; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v118; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v119; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v120; // rax
  __int128 v122; // [rsp+40h] [rbp-C0h]
  const char *v123; // [rsp+50h] [rbp-B0h]
  Illusion::Buffer *v124; // [rsp+58h] [rbp-A8h]
  Render::cbSkinnedVertexStreamState arg; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qTaskFunctionDeclData *skinning_task_decl; // [rsp+88h] [rbp-78h] BYREF
  Illusion::Mesh *v127; // [rsp+90h] [rbp-70h]
  Illusion::Buffer *v128; // [rsp+98h] [rbp-68h]
  char *v129; // [rsp+A0h] [rbp-60h]
  Illusion::MeshProxy mesh_proxy; // [rsp+A8h] [rbp-58h] BYREF
  void *v131; // [rsp+B8h] [rbp-48h]
  void *dest; // [rsp+C0h] [rbp-40h]
  int v133[16]; // [rsp+D0h] [rbp-30h] BYREF
  int v134[16]; // [rsp+110h] [rbp+10h] BYREF
  __int64 v135; // [rsp+150h] [rbp+50h]
  __int128 v136; // [rsp+160h] [rbp+60h] BYREF
  __int64 v137; // [rsp+170h] [rbp+70h]
  __int128 v138; // [rsp+180h] [rbp+80h] BYREF
  __int128 v139; // [rsp+190h] [rbp+90h] BYREF
  AMD_HD3D *v140[2]; // [rsp+1A0h] [rbp+A0h] BYREF
  char v141[16]; // [rsp+1B0h] [rbp+B0h] BYREF
  char v142[16]; // [rsp+1C0h] [rbp+C0h] BYREF
  char v143[16]; // [rsp+1D0h] [rbp+D0h] BYREF
  char v144[16]; // [rsp+1E0h] [rbp+E0h] BYREF
  UFG::qMatrix44 result; // [rsp+1F0h] [rbp+F0h] BYREF
  int v147; // [rsp+298h] [rbp+198h]
  char *task_uid; // [rsp+2A0h] [rbp+1A0h] BYREF
  int v149; // [rsp+2A8h] [rbp+1A8h]

  v137 = -2i64;
  v3 = this;
  v122 = 0ui64;
  mDebugName = "NULL";
  v123 = "NULL";
  skin_model_proxy = skinning_params->skin_model_proxy;
  mData = skin_model_proxy->mModelHandle.mData;
  if ( mData )
  {
    HIDWORD(mData[2].mResourceHandles.mNode.mPrev) = Illusion::gEngine.mFrameCount;
    mDebugName = skinning_params->skin_model_proxy->mModelHandle.mData->mDebugName;
LABEL_7:
    v123 = mDebugName;
    goto LABEL_8;
  }
  mRModel = skin_model_proxy->mRModel;
  if ( mRModel )
  {
    mRModel->mLastUsedFrameNum = Illusion::gEngine.mFrameCount;
    v8 = skinning_params->skin_model_proxy->mRModel;
    if ( v8->mModelName.mText.mData.mNumItems )
      mDebugName = v8->mModelName.mText.mData.mItems;
    else
      mDebugName = &customCaption;
    goto LABEL_7;
  }
LABEL_8:
  v149 = 0;
  v9 = 0i64;
  v10 = v122;
  while ( 1 )
  {
    v147 = v9;
    v11 = skinning_params->skin_model_proxy;
    v12 = v11->mModelHandle.mData;
    if ( v12 )
    {
      LODWORD(v12) = v12[48];
    }
    else
    {
      v12 = v11->mRModel;
      if ( v12 )
        LODWORD(v12) = v12[6];
    }
    if ( (unsigned int)v9 >= (unsigned int)v12 )
      return 1;
    v13 = v11->mModelHandle.mData;
    if ( !v13 )
      goto LABEL_19;
    v14 = v13[2].mNode.mChild[0];
    if ( v14 )
      v14 = (UFG::qBaseNodeRB *)((char *)v14 + (_QWORD)v13 + 184);
    v15 = &v14->mParent + v9;
    if ( *v15 )
      v16 = (char *)*v15 + (_QWORD)v15;
    else
LABEL_19:
      v16 = 0i64;
    mesh_proxy.mMesh = (Illusion::Mesh *)v16;
    v17 = v11->mRModel;
    if ( v17 )
      v18 = (__int64)&v17->mMeshes.mData.mItems[(unsigned int)v9];
    else
      v18 = 0i64;
    mesh_proxy.mRMesh = (Illusion::rMesh *)v18;
    v19 = 0i64;
    v127 = 0i64;
    simple_morph_target = skinning_params->simple_morph_target;
    if ( simple_morph_target )
    {
      mOffset = simple_morph_target->mMeshOffsetTable.mOffset;
      if ( mOffset )
        mOffset += (__int64)&simple_morph_target->mMeshOffsetTable;
      v22 = (_QWORD *)(mOffset + 8 * v9);
      if ( *v22 )
        v19 = (Illusion::Mesh *)((char *)v22 + *v22);
      v127 = v19;
    }
    if ( v16 )
    {
      if ( !Illusion::IEnginePlat::IsValidDrawCall(
              &Illusion::gEngine,
              (Illusion::Mesh *)v16,
              *((Illusion::Material **)v16 + 2),
              0i64,
              0i64) )
        return 0;
      if ( !v19 )
        goto LABEL_38;
      v23 = (Illusion::Material *)*((_QWORD *)v16 + 2);
    }
    else
    {
      if ( !v18 )
        goto LABEL_38;
      if ( !Illusion::IEnginePlat::IsValidDrawCall(
              &Illusion::gEngine,
              (Illusion::rMesh *)v18,
              *(Illusion::rMaterial **)(v18 + 48),
              0i64,
              0i64) )
        return 0;
      if ( !v19 )
        goto LABEL_38;
      v23 = 0i64;
    }
    if ( !Illusion::IEnginePlat::IsValidDrawCall(&Illusion::gEngine, v19, v23, 0i64, 0i64) )
      return 0;
LABEL_38:
    skinning_task_decl = 0i64;
    LODWORD(task_uid) = 0;
    Render::Skinning::SelectSkinningTask(
      v3,
      &skinning_task_decl,
      &mesh_proxy,
      v19,
      (unsigned int *)&task_uid,
      skinning_params,
      0);
    if ( !skinning_task_decl )
    {
      mRigidTransform = skinning_params->mRigidTransform;
      if ( mRigidTransform )
      {
        v25 = (int *)UFG::qMatrix44::operator*(mRigidTransform, &result, skinning_params->local_transform);
      }
      else
      {
        local_transform = (int *)skinning_params->local_transform;
        v134[0] = *local_transform;
        v134[1] = local_transform[1];
        v134[2] = local_transform[2];
        v134[3] = local_transform[3];
        v134[4] = local_transform[4];
        v134[5] = local_transform[5];
        v134[6] = local_transform[6];
        v134[7] = local_transform[7];
        v134[8] = local_transform[8];
        v134[9] = local_transform[9];
        v134[10] = local_transform[10];
        v134[11] = local_transform[11];
        v134[12] = local_transform[12];
        v134[13] = local_transform[13];
        v134[14] = local_transform[14];
        v134[15] = local_transform[15];
        v25 = v134;
      }
      v27 = v25[1];
      v28 = v25[2];
      v29 = v25[3];
      v133[0] = *v25;
      v133[1] = v27;
      v133[2] = v28;
      v133[3] = v29;
      v30 = v25[5];
      v31 = v25[6];
      v32 = v25[7];
      v133[4] = v25[4];
      v133[5] = v30;
      v133[6] = v31;
      v133[7] = v32;
      v33 = v25[9];
      v34 = v25[10];
      v35 = v25[11];
      v133[8] = v25[8];
      v133[9] = v33;
      v133[10] = v34;
      v133[11] = v35;
      v36 = v25[13];
      v37 = v25[14];
      v38 = v25[15];
      v133[12] = v25[12];
      v133[13] = v36;
      v133[14] = v37;
      v133[15] = v38;
      v39 = Render::cbLocalTransformState::sStateParamIndex;
      if ( skinning_params->mRigidTransform )
      {
        *((_QWORD *)&v122 + ((unsigned int)Render::cbLocalTransformState::sStateParamIndex >> 6)) &= ~(1i64 << (Render::cbLocalTransformState::sStateParamIndex & 0x3F));
        v10 = v122;
      }
      if ( v16 )
      {
        v138 = v10;
        v40 = (__int128 *)((__int64 (__fastcall *)(char *, Render::View *, char *, int *, _QWORD, __int128 *, char *))v3->mRenderMeshFunc)(
                            v141,
                            skinning_params->view,
                            v16,
                            v133,
                            *((_QWORD *)v16 + 2),
                            &v138,
                            mDebugName);
        goto LABEL_48;
      }
      if ( v18 )
      {
        v136 = v10;
        v40 = (__int128 *)((__int64 (__fastcall *)(char *, Render::View *, __int64, int *, _QWORD, __int128 *, char *))v3->mRenderRMeshFunc)(
                            v144,
                            skinning_params->view,
                            v18,
                            v133,
                            *(_QWORD *)(v18 + 48),
                            &v136,
                            mDebugName);
LABEL_48:
        v10 = *v40;
        v39 = Render::cbLocalTransformState::sStateParamIndex;
        v122 = *v40;
      }
      if ( skinning_params->mRigidTransform )
      {
        *((_QWORD *)&v122 + (v39 >> 6)) &= ~(1i64 << (v39 & 0x3F));
        v10 = v122;
      }
      goto LABEL_162;
    }
    v41 = (__int64)(v16 + 96);
    if ( !v16 )
      v41 = v18 + 120;
    v42 = *(Illusion::Buffer **)(v41 + 16);
    v128 = v42;
    v43 = (__int64)(v16 + 128);
    if ( !v16 )
      v43 = v18 + 152;
    v135 = *(_QWORD *)(v43 + 16);
    v44 = (__int64)(v16 + 64);
    if ( !v16 )
      v44 = v18 + 88;
    v129 = *(char **)(v44 + 16);
    instance_uid = skinning_params->instance_uid;
    v46 = (unsigned int)v42;
    v47 = (unsigned int)v42 | ((unsigned __int64)instance_uid << 32);
    if ( v47 )
    {
      v48 = v3;
      for ( i = v3 == (Render::Skinning *)&v3->mSkinnedVertexBuffers.mTree.mNULL;
            !i;
            i = v48 == (Render::Skinning *)&v3->mSkinnedVertexBuffers.mTree.mNULL )
      {
        if ( v48 != v3 && v48->mSkinnedVertexBuffers.mTree.mRoot.mUID == v47 )
        {
          for ( j = (Render::Skinning *)v48->mSkinnedVertexBuffers.mTree.mRoot.mChild[0];
                j;
                j = (Render::Skinning *)j->mSkinnedVertexBuffers.mTree.mRoot.mChild[0] )
          {
            if ( j->mSkinnedVertexBuffers.mTree.mRoot.mUID != v47 )
              break;
            v48 = j;
          }
          if ( !v48 )
            break;
          mParent = (Illusion::Buffer *)v48->mSkinnedVertexBuffers.mTree.mNULL.mParent;
          v124 = mParent;
          v52 = mParent == 0i64;
          if ( !mParent )
            goto LABEL_75;
          if ( !skinning_params->clip_info )
            goto LABEL_153;
          goto LABEL_74;
        }
        if ( v47 > v48->mSkinnedVertexBuffers.mTree.mRoot.mUID )
          v48 = (Render::Skinning *)v48->mSkinnedVertexBuffers.mTree.mRoot.mChild[1];
        else
          v48 = (Render::Skinning *)v48->mSkinnedVertexBuffers.mTree.mRoot.mChild[0];
      }
    }
    mParent = 0i64;
    v124 = 0i64;
LABEL_74:
    v52 = mParent == 0i64;
LABEL_75:
    v53 = !v52;
    if ( !mParent )
    {
      mParent = Render::Skinning::AllocateVertexBuffer(v3, v42, instance_uid, 1);
      v124 = mParent;
      if ( !mParent )
        return 0;
    }
    Illusion::Buffer::OnLoad(mParent);
    v54 = v46 | ((unsigned __int64)skinning_params->instance_uid << 32);
    v55 = (v128->mNumElements * v128->mElementByteSize + 127) & 0xFFFFFF7F;
    if ( skinning_params->mUsePersistentCache
      && this->mEnablePersistentCache
      && (v56 = Render::PersistentSkinningCache::Find(&this->mPersistentSkinningCache, v54), (v57 = v56) != 0i64) )
    {
      v58 = &v56->UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode>;
      mPrev = v56->mPrev;
      mNext = v56->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v56->mPrev = &v56->UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode>;
      v56->mNext = &v56->UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode>;
      v3 = this;
      v61 = this->mPersistentSkinningCache.mCachedVertexDataList.mNode.mPrev;
      v61->mNext = v58;
      v58->mPrev = v61;
      v58->mNext = &this->mPersistentSkinningCache.mCachedVertexDataList.mNode;
      this->mPersistentSkinningCache.mCachedVertexDataList.mNode.mPrev = v58;
      v62 = mParent->mData.mOffset;
      if ( v62 )
        v63 = (char *)&mParent->mData + v62;
      else
        v63 = 0i64;
      UFG::qMemCopy(v63, v57->mCachedDataPtr, v57->mSize);
    }
    else
    {
      v64 = 48 * skinning_params->transform_count;
      dest = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, skinning_params->bone_matrix_count, 0x10u);
      v131 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, v64, 0x10u);
      UFG::qMemCopy(dest, skinning_params->bone_remap_array, skinning_params->bone_matrix_count);
      UFG::qMemCopy(v131, skinning_params->transform_array, v64);
      v65 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xB0u, 0x10u);
      if ( v53 || (v66 = v124->mData.mOffset) == 0 )
      {
        v68 = 0i64;
        v67 = 0i64;
      }
      else
      {
        v67 = (char *)&v124->mData + v66;
        v68 = 0i64;
      }
      *(_QWORD *)v65 = v67;
      if ( skinning_params->mUsePersistentCache && this->mEnablePersistentCache )
        v69 = Render::PersistentSkinningCache::Store(&this->mPersistentSkinningCache, v54, v55);
      else
        v69 = 0i64;
      *((_QWORD *)v65 + 18) = v69;
      v70 = (__int64)v128;
      v71 = v128->mData.mOffset;
      if ( v71 )
        v72 = (char *)&v128->mData + v71;
      else
        v72 = 0i64;
      *((_QWORD *)v65 + 1) = v72;
      v73 = *(_QWORD *)(v135 + 96);
      if ( v73 )
        v74 = v135 + v73 + 96;
      else
        v74 = 0i64;
      *((_QWORD *)v65 + 2) = v74;
      v75 = *((_QWORD *)v129 + 12);
      if ( v75 )
        v76 = &v129[v75 + 96];
      else
        v76 = 0i64;
      if ( v16 )
        v77 = *((unsigned int *)v16 + 57);
      else
        v77 = *(unsigned int *)(v18 + 252);
      *((_QWORD *)v65 + 3) = &v76[2 * v77];
      *((_QWORD *)v65 + 12) = skinning_params->bone_inverse_array;
      *((_QWORD *)v65 + 13) = dest;
      *((_QWORD *)v65 + 4) = v131;
      *((_WORD *)v65 + 20) = skinning_params->bone_matrix_count;
      *((_WORD *)v65 + 21) = 200;
      if ( v127 && (v78 = v127->mVertexBufferHandles[0].mData, (v79 = v78[1].mNode.mChild[0]) != 0i64) )
        v80 = (__int64)v78[1].mNode.mChild + (_QWORD)v79;
      else
        v80 = 0i64;
      *((_QWORD *)v65 + 6) = v80;
      *((_DWORD *)v65 + 14) = LODWORD(skinning_params->simple_morph_weight);
      morph_weights_count = skinning_params->morph_weights_count;
      if ( morph_weights_count
        && ((v82 = skinning_params->skin_model_proxy->mModelHandle.mData) == 0i64
          ? (v83 = 0i64)
          : (v83 = *(_QWORD *)&v82[2].mDebugName[20]),
            v83 && *(_DWORD *)(v83 + 120)) )
      {
        v84 = 20;
        if ( morph_weights_count < 0x14 )
          v84 = skinning_params->morph_weights_count;
        *((_QWORD *)v65 + 19) = UFG::qLinearAllocator::Malloc(
                                  Illusion::gEngine.FrameMemory,
                                  (8 * v84 + 127) & 0xFFFFFF80,
                                  0x80u);
        *((_QWORD *)v65 + 20) = UFG::qLinearAllocator::Malloc(
                                  Illusion::gEngine.FrameMemory,
                                  (4 * v84 + 127) & 0xFFFFFF80,
                                  0x80u);
        v85 = *(_QWORD *)(v83 + 104);
        v86 = *(_QWORD *)(v85 + 96);
        if ( v86 )
          v68 = v86 + v85 + 96;
        v87 = *(_DWORD *)(v85 + 108) / *(_DWORD *)(v83 + 120);
        *((_DWORD *)v65 + 43) = v87;
        v88 = 0i64;
        v89 = v87 * *(_DWORD *)(v85 + 104);
        v90 = 0i64;
        if ( skinning_params->morph_weights_count )
        {
          v91 = 0;
          do
          {
            if ( (unsigned int)v88 >= v84 )
              break;
            v92 = skinning_params->morph_weights_array[v90];
            if ( v92 >= 0.0099999998 )
            {
              *(_QWORD *)(*((_QWORD *)v65 + 19) + 8 * v88) = v68 + v91;
              *(float *)(*((_QWORD *)v65 + 20) + 4 * v88) = v92;
              v88 = (unsigned int)(v88 + 1);
            }
            v90 = (unsigned int)(v90 + 1);
            v91 += v89;
          }
          while ( (unsigned int)v90 < skinning_params->morph_weights_count );
        }
        *((_DWORD *)v65 + 42) = v88;
        v70 = (__int64)v128;
      }
      else
      {
        *((_QWORD *)v65 + 21) = 0i64;
        *((_QWORD *)v65 + 20) = 0i64;
        *((_QWORD *)v65 + 19) = 0i64;
      }
      if ( v16 )
        v93 = *((_DWORD *)v16 + 58);
      else
        v93 = *(_DWORD *)(v18 + 256);
      *((_DWORD *)v65 + 15) = 3 * v93;
      *((_DWORD *)v65 + 16) = *(_DWORD *)(v70 + 108);
      *((_QWORD *)v65 + 9) = skinning_params->user_data_0;
      *((_QWORD *)v65 + 10) = skinning_params->user_data_1;
      clip_info = skinning_params->clip_info;
      if ( clip_info && skinning_params->mDecalTaskUID == (_DWORD)task_uid )
      {
        *((_QWORD *)v65 + 14) = clip_info;
        v95 = v149;
        *((_QWORD *)v65 + 17) = skinning_params->clip_info->mResults[v149];
        v149 = v95 + 1;
      }
      else
      {
        *((_QWORD *)v65 + 14) = 0i64;
        *((_QWORD *)v65 + 17) = 0i64;
      }
      *((_QWORD *)v65 + 15) = 0i64;
      *((_DWORD *)v65 + 32) = 0;
      v3 = this;
      mTaskGroup = this->mTaskGroup;
      v97 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
      v98 = (UFG::qTask *)v97;
      task_uid = v97;
      v129 = v97;
      if ( mTaskGroup )
      {
        if ( v97 )
        {
          *(_QWORD *)v97 = v97;
          *((_QWORD *)v97 + 1) = v97;
          *((_QWORD *)v97 + 2) = v97 + 16;
          *((_QWORD *)v97 + 3) = v97 + 16;
          v99 = skinning_task_decl;
          mSpuElf = skinning_task_decl->mSpuElf;
          mTaskFunctionSPU = skinning_task_decl->mTaskFunctionSPU;
          mTaskFunctionPPU = skinning_task_decl->mTaskFunctionPPU;
          mTaskFunctionOffload = skinning_task_decl->mTaskFunctionOffload;
          if ( !skinning_task_decl->mCurrentSPUEnabled )
          {
            mSpuElf = 0i64;
            mTaskFunctionSPU = 0i64;
            mTaskFunctionOffload = 0i64;
          }
          v98->mTaskGroup = mTaskGroup;
          v98->mFlags = 2;
          v98->mSyncVars.i64 = 0i64;
          v98->mSyncVars.v.mDependents = 0i64;
          v98->mFunctionDeclData = v99;
          if ( mSpuElf )
            mAddress = mSpuElf->mAddress;
          else
            mAddress = 0i64;
          v98->mSPUElfAddress = mAddress;
          v98->mSPUFunction = mTaskFunctionSPU;
          v98->mPPUFunction = mTaskFunctionPPU;
          v98->mParam0 = v65;
          v98->mParam1 = 0i64;
          v98->mParam2 = 0i64;
          v98->mParam3 = 0i64;
          if ( mTaskFunctionOffload )
          {
            v98->mFlags = 130;
            v98->mOffloadThread = 0;
          }
        }
        v105 = mTaskGroup->mTasks.mNode.mPrev;
        v105->mNext = v98;
        v98->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = v105;
        v98->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mTaskGroup->mTasks.mNode;
        mTaskGroup->mTasks.mNode.mPrev = v98;
        ++mTaskGroup->mNumTasks;
      }
      else
      {
        if ( v97 )
        {
          *(_QWORD *)v97 = v97;
          *((_QWORD *)v97 + 1) = v97;
          v106 = v97 + 16;
          *v106 = v106;
          v106[1] = v106;
          v107 = skinning_task_decl;
          v108 = skinning_task_decl->mSpuElf;
          v109 = skinning_task_decl->mTaskFunctionSPU;
          v110 = skinning_task_decl->mTaskFunctionPPU;
          v111 = skinning_task_decl->mTaskFunctionOffload;
          if ( !skinning_task_decl->mCurrentSPUEnabled )
          {
            v108 = 0i64;
            v109 = 0i64;
            v111 = 0i64;
          }
          v98->mTaskGroup = 0i64;
          v98->mFlags = 2;
          v98->mSyncVars.i64 = 0i64;
          v98->mSyncVars.v.mDependents = 0i64;
          v98->mFunctionDeclData = v107;
          if ( v108 )
            v112 = v108->mAddress;
          else
            v112 = 0i64;
          v98->mSPUElfAddress = v112;
          v98->mSPUFunction = v109;
          v98->mPPUFunction = v110;
          v98->mParam0 = v65;
          v98->mParam1 = 0i64;
          v98->mParam2 = 0i64;
          v98->mParam3 = 0i64;
          if ( v111 )
          {
            v98->mFlags = 130;
            v98->mOffloadThread = 0;
          }
        }
        mSingleFrameTasks = UFG::gTaskManager.mSingleFrameTasks;
        v114 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
        v114->mNext = v98;
        v98->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = v114;
        v98->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mSingleFrameTasks->mNode;
        mSingleFrameTasks->mNode.mPrev = v98;
        UFG::qTaskManager::Queue(&UFG::gTaskManager, v98);
      }
    }
    LODWORD(v9) = v147;
LABEL_153:
    StateArgs = Render::View::GetStateArgs(skinning_params->view);
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbSkinnedVertexStreamState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 2;
    if ( (_WORD)Render::cbSkinnedVertexStreamState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "iVertexBuffer0");
      Render::cbSkinnedVertexStreamState::sStateParamIndex = Param;
      arg.mStateParamIndex = Param;
    }
    arg.mVertexStreamBuffer = v124;
    Illusion::StateArgs::Set<Render::cbSkinnedVertexStreamState>(StateArgs, &arg);
    if ( v16 )
    {
      *(_OWORD *)v140 = v10;
      v10 = *(_OWORD *)((__int64 (__fastcall *)(char *, Render::View *, char *, UFG::qMatrix44 *, _QWORD, AMD_HD3D **, const char *))v3->mRenderMeshFunc)(
                         v142,
                         skinning_params->view,
                         v16,
                         skinning_params->local_transform,
                         *((_QWORD *)v16 + 2),
                         v140,
                         v123);
      v122 = v10;
    }
    else if ( v18 )
    {
      v139 = v10;
      v122 = *(_OWORD *)((__int64 (__fastcall *)(char *, Render::View *, __int64, UFG::qMatrix44 *, _QWORD, __int128 *, const char *))v3->mRenderRMeshFunc)(
                          v143,
                          skinning_params->view,
                          v18,
                          skinning_params->local_transform,
                          *(_QWORD *)(v18 + 48),
                          &v139,
                          v123);
      v10 = v122;
    }
    v117 = arg.mPrev;
    v118 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v118->mPrev = v117;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v119 = arg.mPrev;
    v120 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v120->mPrev = v119;
    arg.mPrev = &arg;
    arg.mNext = &arg;
LABEL_162:
    v9 = (unsigned int)(v9 + 1);
    mDebugName = (char *)v123;
  }
}

// File Line: 919
// RVA: 0x1CC20
char __fastcall Render::Skinning::DrawSkinnedDecal(Render::Skinning *this, Render::SkinningParams *skinning_params)
{
  Render::Skinning *v3; // r15
  unsigned int i; // r14d
  Illusion::ModelProxy *skin_model_proxy; // rcx
  UFG::qResourceData *mData; // rax
  unsigned int mNumItems; // eax
  Illusion::rModel *mRModel; // rax
  UFG::qResourceData *v10; // rax
  UFG::qBaseNodeRB *v11; // rdx
  char *v12; // rdx
  char *v13; // r8
  char *v14; // rbx
  Illusion::rModel *v15; // rax
  __int64 v16; // rdi
  Illusion::Mesh *v17; // rsi
  Illusion::Model *simple_morph_target; // rax
  __int64 mOffset; // rcx
  __int64 v20; // rcx
  _QWORD *v21; // rdx
  Illusion::Material *v22; // r8
  UFG::qTaskFunctionDeclData *v23; // r15
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // r13
  __int64 v27; // rax
  char *v28; // r14
  __int64 v29; // rax
  UFG::qTaskFunctionDeclData *v30; // rdx
  __int64 v31; // rax
  __int64 v32; // rax
  __int64 v33; // rax
  char *v34; // rcx
  __int64 v35; // rax
  UFG::qResourceData *v36; // rax
  UFG::qBaseNodeRB *v37; // rcx
  char *v38; // rax
  int v39; // eax
  UFG::qTaskGroup *mTaskGroup; // rbx
  char *v41; // rax
  UFG::qTask *v42; // rdx
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r9
  char *mAddress; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *mPrev; // rax
  _QWORD *v49; // rax
  UFG::qSpuElf *v50; // rax
  void (__fastcall *v51)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v52)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v53)(void *, void *, void *, void *); // r9
  char *v54; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTasks; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v56; // rax
  Illusion::Primitive *v57; // rdi
  Illusion::Buffer *v58; // rsi
  __int64 v59; // rcx
  char *v60; // r8
  Illusion::StateArgs *StateArgs; // rbx
  unsigned __int16 Param; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v63; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v65; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v66; // rax
  Illusion::MeshProxy mesh_proxy; // [rsp+48h] [rbp-21h] BYREF
  Render::cbSkinnedVertexStreamState arg; // [rsp+58h] [rbp-11h] BYREF
  Illusion::Buffer *task_uid; // [rsp+D8h] [rbp+6Fh] BYREF
  UFG::qTaskFunctionDeclData *skinning_task_decl; // [rsp+E0h] [rbp+77h] BYREF
  char *v72; // [rsp+E8h] [rbp+7Fh]

  v3 = this;
  if ( !skinning_params->mDecalVertNum )
    return 0;
  for ( i = 0; ; ++i )
  {
    skin_model_proxy = skinning_params->skin_model_proxy;
    mData = skin_model_proxy->mModelHandle.mData;
    if ( mData )
    {
      mNumItems = (unsigned int)mData[2].mNode.mChild[1];
    }
    else
    {
      mRModel = skin_model_proxy->mRModel;
      if ( mRModel )
        mNumItems = mRModel->mMeshes.mData.mNumItems;
      else
        mNumItems = 0;
    }
    if ( i >= mNumItems )
      return 1;
    v10 = skin_model_proxy->mModelHandle.mData;
    if ( !v10
      || ((v11 = v10[2].mNode.mChild[0]) == 0i64 ? (v12 = 0i64) : (v12 = (char *)&v11[5].mChild[2] + (_QWORD)v10),
          v13 = &v12[8 * i],
          v14 = &v13[*(_QWORD *)v13],
          !*(_QWORD *)v13) )
    {
      v14 = 0i64;
    }
    mesh_proxy.mMesh = (Illusion::Mesh *)v14;
    v15 = skin_model_proxy->mRModel;
    if ( v15 )
    {
      v16 = (__int64)&v15->mMeshes.mData.mItems[i];
      mesh_proxy.mRMesh = (Illusion::rMesh *)v16;
    }
    else
    {
      v16 = 0i64;
      mesh_proxy.mRMesh = 0i64;
    }
    v17 = 0i64;
    simple_morph_target = skinning_params->simple_morph_target;
    if ( simple_morph_target )
    {
      mOffset = simple_morph_target->mMeshOffsetTable.mOffset;
      v20 = mOffset ? (__int64)&simple_morph_target->mMeshOffsetTable + mOffset : 0i64;
      v21 = (_QWORD *)(v20 + 8i64 * i);
      if ( *v21 )
        v17 = (Illusion::Mesh *)((char *)v21 + *v21);
    }
    if ( v14 )
    {
      if ( !Illusion::IEnginePlat::IsValidDrawCall(
              &Illusion::gEngine,
              (Illusion::Mesh *)v14,
              *((Illusion::Material **)v14 + 2),
              0i64,
              0i64) )
        return 0;
      if ( !v17 )
        goto LABEL_34;
      v22 = (Illusion::Material *)*((_QWORD *)v14 + 2);
    }
    else
    {
      if ( !v16 )
        goto LABEL_34;
      if ( !Illusion::IEnginePlat::IsValidDrawCall(
              &Illusion::gEngine,
              (Illusion::rMesh *)v16,
              *(Illusion::rMaterial **)(v16 + 48),
              0i64,
              0i64) )
        return 0;
      if ( !v17 )
        goto LABEL_34;
      v22 = 0i64;
    }
    if ( !Illusion::IEnginePlat::IsValidDrawCall(&Illusion::gEngine, v17, v22, 0i64, 0i64) )
      return 0;
LABEL_34:
    skinning_task_decl = 0i64;
    LODWORD(task_uid) = 0;
    Render::Skinning::SelectSkinningTask(
      v3,
      &skinning_task_decl,
      &mesh_proxy,
      v17,
      (unsigned int *)&task_uid,
      skinning_params,
      1);
    v23 = skinning_task_decl;
    if ( skinning_task_decl )
    {
      if ( (_DWORD)task_uid == skinning_params->mDecalTaskUID )
        break;
    }
    v3 = this;
  }
  v24 = (__int64)(v14 + 96);
  if ( !v14 )
    v24 = v16 + 120;
  skinning_task_decl = *(UFG::qTaskFunctionDeclData **)(v24 + 16);
  v25 = (__int64)(v14 + 128);
  if ( !v14 )
    v25 = v16 + 152;
  v26 = *(_QWORD *)(v25 + 16);
  v27 = (__int64)(v14 + 64);
  if ( !v14 )
    v27 = v16 + 88;
  v72 = *(char **)(v27 + 16);
  task_uid = Render::Skinning::AllocateDecalVertexBuffer(this, skinning_params->mDecalVertNum);
  if ( task_uid )
  {
    v28 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xB0u, 0x10u);
    Illusion::Buffer::OnLoad(task_uid);
    v29 = task_uid->mData.mOffset;
    if ( v29 )
      v29 += (__int64)&task_uid->mData;
    *(_QWORD *)v28 = v29;
    v30 = skinning_task_decl;
    v31 = *(_QWORD *)(&skinning_task_decl->mRequestedSPUEnabled + 7);
    if ( v31 )
      v31 += (__int64)(&skinning_task_decl->mRequestedSPUEnabled + 7);
    *((_QWORD *)v28 + 1) = v31;
    v32 = *(_QWORD *)(v26 + 96);
    if ( v32 )
      v32 += v26 + 96;
    *((_QWORD *)v28 + 2) = v32;
    v33 = *((_QWORD *)v72 + 12);
    if ( v33 )
      v34 = &v72[v33 + 96];
    else
      v34 = 0i64;
    if ( v14 )
      v35 = *((unsigned int *)v14 + 57);
    else
      v35 = *(unsigned int *)(v16 + 252);
    *((_QWORD *)v28 + 3) = &v34[2 * v35];
    *((_QWORD *)v28 + 12) = skinning_params->bone_inverse_array;
    *((_QWORD *)v28 + 13) = skinning_params->bone_remap_array;
    *((_QWORD *)v28 + 4) = skinning_params->transform_array;
    *((_WORD *)v28 + 20) = skinning_params->bone_matrix_count;
    *((_WORD *)v28 + 21) = 200;
    if ( v17 && (v36 = v17->mVertexBufferHandles[0].mData, (v37 = v36[1].mNode.mChild[0]) != 0i64) )
      v38 = (char *)v36[1].mNode.mChild + (_QWORD)v37;
    else
      v38 = 0i64;
    *((_QWORD *)v28 + 6) = v38;
    *((_DWORD *)v28 + 14) = LODWORD(skinning_params->simple_morph_weight);
    if ( v14 )
      v39 = *((_DWORD *)v14 + 58);
    else
      v39 = *(_DWORD *)(v16 + 256);
    *((_DWORD *)v28 + 15) = 3 * v39;
    *((_DWORD *)v28 + 16) = *(&v30->mRequestedSPUEnabled + 10);
    *((_QWORD *)v28 + 9) = skinning_params->user_data_0;
    *((_QWORD *)v28 + 10) = skinning_params->user_data_1;
    *((_QWORD *)v28 + 14) = 0i64;
    *((_QWORD *)v28 + 17) = 0i64;
    *((_QWORD *)v28 + 15) = skinning_params->mDecalVerts;
    *((_DWORD *)v28 + 32) = skinning_params->mDecalVertNum;
    mTaskGroup = this->mTaskGroup;
    v41 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
    v42 = (UFG::qTask *)v41;
    skinning_task_decl = (UFG::qTaskFunctionDeclData *)v41;
    v72 = v41;
    if ( mTaskGroup )
    {
      if ( v41 )
      {
        *(_QWORD *)v41 = v41;
        *((_QWORD *)v41 + 1) = v41;
        *((_QWORD *)v41 + 2) = v41 + 16;
        *((_QWORD *)v41 + 3) = v41 + 16;
        mSpuElf = v23->mSpuElf;
        mTaskFunctionSPU = v23->mTaskFunctionSPU;
        mTaskFunctionPPU = v23->mTaskFunctionPPU;
        mTaskFunctionOffload = v23->mTaskFunctionOffload;
        if ( !v23->mCurrentSPUEnabled )
        {
          mSpuElf = 0i64;
          mTaskFunctionSPU = 0i64;
          mTaskFunctionOffload = 0i64;
        }
        v42->mTaskGroup = mTaskGroup;
        v42->mFlags = 2;
        v42->mSyncVars.i64 = 0i64;
        v42->mSyncVars.v.mDependents = 0i64;
        v42->mFunctionDeclData = v23;
        if ( mSpuElf )
          mAddress = mSpuElf->mAddress;
        else
          mAddress = 0i64;
        v42->mSPUElfAddress = mAddress;
        v42->mSPUFunction = mTaskFunctionSPU;
        v42->mPPUFunction = mTaskFunctionPPU;
        v42->mParam0 = v28;
        v42->mParam1 = 0i64;
        v42->mParam2 = 0i64;
        v42->mParam3 = 0i64;
        if ( mTaskFunctionOffload )
        {
          v42->mFlags = 130;
          v42->mOffloadThread = 0;
        }
      }
      mPrev = mTaskGroup->mTasks.mNode.mPrev;
      mPrev->mNext = v42;
      v42->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = mPrev;
      v42->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mTaskGroup->mTasks.mNode;
      mTaskGroup->mTasks.mNode.mPrev = v42;
      ++mTaskGroup->mNumTasks;
    }
    else
    {
      if ( v41 )
      {
        *(_QWORD *)v41 = v41;
        *((_QWORD *)v41 + 1) = v41;
        v49 = v41 + 16;
        *v49 = v49;
        v49[1] = v49;
        v50 = v23->mSpuElf;
        v51 = v23->mTaskFunctionSPU;
        v52 = v23->mTaskFunctionPPU;
        v53 = v23->mTaskFunctionOffload;
        if ( !v23->mCurrentSPUEnabled )
        {
          v50 = 0i64;
          v51 = 0i64;
          v53 = 0i64;
        }
        v42->mTaskGroup = 0i64;
        v42->mFlags = 2;
        v42->mSyncVars.i64 = 0i64;
        v42->mSyncVars.v.mDependents = 0i64;
        v42->mFunctionDeclData = v23;
        if ( v50 )
          v54 = v50->mAddress;
        else
          v54 = 0i64;
        v42->mSPUElfAddress = v54;
        v42->mSPUFunction = v51;
        v42->mPPUFunction = v52;
        v42->mParam0 = v28;
        v42->mParam1 = 0i64;
        v42->mParam2 = 0i64;
        v42->mParam3 = 0i64;
        if ( v53 )
        {
          v42->mFlags = 130;
          v42->mOffloadThread = 0;
        }
      }
      mSingleFrameTasks = UFG::gTaskManager.mSingleFrameTasks;
      v56 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
      v56->mNext = v42;
      v42->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = v56;
      v42->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mSingleFrameTasks->mNode;
      mSingleFrameTasks->mNode.mPrev = v42;
      UFG::qTaskManager::Queue(&UFG::gTaskManager, v42);
    }
    v57 = Illusion::Primitive::Create("SkinningDecal");
    v58 = task_uid;
    v59 = task_uid->mData.mOffset;
    if ( v59 )
      v60 = (char *)&task_uid->mData + v59;
    else
      v60 = 0i64;
    Illusion::Primitive::SetBuffers(
      v57,
      TRIANGLELIST,
      v60,
      skinning_params->mDecalVertNum,
      (Illusion::VertexDecl *)this->mDecalVertexDecl.mData,
      0i64,
      0,
      0);
    StateArgs = Render::View::GetStateArgs(skinning_params->view);
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbSkinnedVertexStreamState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 2;
    if ( (_WORD)Render::cbSkinnedVertexStreamState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "iVertexBuffer0");
      Render::cbSkinnedVertexStreamState::sStateParamIndex = Param;
      arg.mStateParamIndex = Param;
    }
    arg.mVertexStreamBuffer = v58;
    Illusion::StateArgs::Set<Render::cbSkinnedVertexStreamState>(StateArgs, &arg);
    this->mRenderDecalFunc(
      skinning_params->view,
      v57,
      skinning_params->mDecalMaterial,
      skinning_params->local_transform);
    v63 = arg.mPrev;
    mNext = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    mNext->mPrev = v63;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v65 = arg.mPrev;
    v66 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v66->mPrev = v65;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    return 1;
  }
  return 0;
}

