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
  return atexit(dynamic_atexit_destructor_for__Render::Skinning::gSkinning__);
}

// File Line: 96
// RVA: 0x1E780
UFG::qBaseNodeVariableRB<unsigned __int64> *__fastcall Render::PersistentSkinningCache::Store(Render::PersistentSkinningCache *this, unsigned __int64 uid, unsigned __int64 size)
{
  unsigned __int64 v3; // rsi
  Render::PersistentSkinningCache *v4; // rdi
  Render::PersistentSkinningCache *v5; // rbx
  bool i; // zf
  Render::PersistentSkinningCache *j; // rax
  UFG::qList<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode,1,0> *v8; // r14
  $CA91B2824B6F331601351B2AC7FEF5D9 *v9; // r13
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v10; // rdx
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v11; // rcx
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v12; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v13; // rbx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v14; // r8
  UFG::qBaseNodeVariableRB<unsigned __int64> *v15; // rdx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v16; // rax
  char *v18; // r12
  char *v19; // rax
  _QWORD *v20; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v21; // rcx
  UFG::qBaseNodeVariableRB<unsigned __int64> *v22; // rax
  unsigned __int64 sizea; // [rsp+80h] [rbp+18h]

  sizea = size;
  v3 = uid;
  v4 = this;
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
    v8 = &this->mCachedVertexDataList;
    v9 = &this->mCachedVertexDataTree.mTree.mNULL.8;
    if ( ($CA91B2824B6F331601351B2AC7FEF5D9 *)&this->mCachedVertexDataList.mNode.mNext[-2] != &this->mCachedVertexDataTree.mTree.mNULL.8 )
    {
      while ( UFG::qMemoryPool::GetLargestFree(&v4->mCachedVertexDataPool, 0i64) < (unsigned int)sizea )
      {
        v10 = v4->mCachedVertexDataList.mNode.mNext;
        if ( LODWORD(v10[2].mPrev) == Illusion::gEngine.mFrameCount )
          return 0i64;
        v11 = v10->mPrev;
        v12 = v10->mNext;
        v11->mNext = v12;
        v12->mPrev = v11;
        v10->mPrev = v10;
        v10->mNext = v10;
        v13 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)&v10[-2];
        UFG::qMemoryPool::Free(&v4->mCachedVertexDataPool, v10[1].mPrev);
        UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(&v4->mCachedVertexDataTree.mTree, v13);
        Render::gPersistentCacheUsageKB -= v13[1].mUID >> 10;
        --Render::gPersistentCacheUsageEntries;
        v14 = v13 + 1;
        v15 = v13[1].mParent;
        v16 = v13[1].mChild[0];
        v15->mChild[0] = v16;
        v16->mParent = v15;
        v14->mParent = v14;
        v14->mChild[0] = v14;
        operator delete[](v13);
        if ( ($CA91B2824B6F331601351B2AC7FEF5D9 *)&v8->mNode.mNext[-2] == v9 )
          break;
      }
    }
    v18 = UFG::qMemoryPool::Allocate(
            &v4->mCachedVertexDataPool,
            (unsigned int)sizea,
            "persistent_cache_alloc",
            0i64,
            1u);
    v19 = UFG::qMalloc(0x48ui64, "PersistentSkinningCacheNode", 0x800ui64);
    v5 = (Render::PersistentSkinningCache *)v19;
    if ( v19 )
    {
      *(_QWORD *)v19 = 0i64;
      *((_QWORD *)v19 + 1) = 0i64;
      *((_QWORD *)v19 + 2) = 0i64;
      *((_QWORD *)v19 + 3) = v3;
      v20 = v19 + 32;
      *v20 = v20;
      v20[1] = v20;
      v5->mCachedVertexDataTree.mTree.mNULL.mChild[1] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v18;
      v5->mCachedVertexDataTree.mTree.mNULL.mUID = (unsigned int)sizea;
      v5->mCachedVertexDataTree.mTree.mCount = Illusion::gEngine.mFrameCount;
    }
    else
    {
      v5 = 0i64;
    }
    v21 = &v5->mCachedVertexDataTree.mTree.mNULL;
    v22 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v8->mNode.mPrev;
    v22->mChild[0] = &v5->mCachedVertexDataTree.mTree.mNULL;
    v21->mParent = v22;
    v21->mChild[0] = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v8;
    v8->mNode.mPrev = (UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *)&v5->mCachedVertexDataTree.mTree.mNULL;
    UFG::qBaseTreeVariableRB<unsigned __int64>::Add(
      &v4->mCachedVertexDataTree.mTree,
      &v5->mCachedVertexDataTree.mTree.mRoot);
    Render::gPersistentCacheUsageKB += v5->mCachedVertexDataTree.mTree.mNULL.mUID >> 10;
    ++Render::gPersistentCacheUsageEntries;
  }
  return v5->mCachedVertexDataTree.mTree.mNULL.mChild[1];
}

// File Line: 130
// RVA: 0x1BF40
void __fastcall Render::SkinClipInfo::SkinClipInfo(Render::SkinClipInfo *this, const unsigned int num_results)
{
  Render::SkinClipInfo *v2; // r14
  unsigned int v3; // ebp
  char *v4; // rax
  Render::SkinClipInfo::ClipResult *v5; // rdi
  signed int v6; // esi
  char *v7; // rbx

  v2 = this;
  *(_WORD *)&this->mQueryReady = 0;
  this->mMaxResults = num_results;
  v3 = 0;
  if ( num_results )
  {
    do
    {
      v4 = UFG::qMalloc(0x588ui64, "ClipResult", 0x1000ui64);
      v5 = (Render::SkinClipInfo::ClipResult *)v4;
      if ( v4 )
      {
        v6 = 31;
        v7 = v4 + 40;
        do
        {
          `vector constructor iterator'(v7, 2ui64, 2, (void *(__fastcall *)(void *))UFG::qHalfFloat::qHalfFloat);
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
      v2->mResults[v3++] = v5;
    }
    while ( v3 < v2->mMaxResults );
  }
}

// File Line: 153
// RVA: 0x1C5B0
char __fastcall Render::SkinClipInfo::AllResultsReady(Render::SkinClipInfo *this)
{
  unsigned int v1; // er8
  unsigned int v2; // edx

  v1 = this->mMaxResults;
  v2 = 0;
  if ( !v1 )
    return 1;
  while ( this->mResults[0]->mResultReady )
  {
    ++v2;
    this = (Render::SkinClipInfo *)((char *)this + 8);
    if ( v2 >= v1 )
      return 1;
  }
  return 0;
}

// File Line: 183
// RVA: 0x1E9B0
char __fastcall Render::SkinClipInfo::SubmitClipQuery(Render::SkinClipInfo *this, UFG::qMatrix44 *decal_world, UFG::qMatrix44 *model_local_world, float radius, UFG::qVector4 *aabb_min, UFG::qVector4 *aabb_max, float cutoff, float decal_depth)
{
  float v8; // xmm4_4
  Render::SkinClipInfo *v9; // r9
  unsigned int v10; // er11
  int v11; // er10
  UFG::qVector4 v12; // xmm3
  UFG::qVector4 v13; // xmm2
  UFG::qVector4 v14; // xmm1
  unsigned int v15; // edx
  UFG::qVector4 v16; // xmm2
  UFG::qVector4 v17; // xmm1
  UFG::qVector4 v18; // xmm3
  float v19; // xmm0_4
  float v20; // xmm0_4
  __int64 v21; // rcx

  v8 = radius;
  v9 = this;
  if ( this->mQueryReady )
    return 0;
  v10 = this->mMaxResults;
  v11 = 0;
  if ( v10 )
  {
    while ( !this->mResults[v11]->mResultReady )
    {
      if ( ++v11 >= v10 )
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
  this->mRadius = v8;
  v19 = aabb_min->y;
  v17.x = aabb_min->z;
  v16.x = aabb_min->w;
  this->mModelAABBMin.x = aabb_min->x;
  this->mModelAABBMin.y = v19;
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
  if ( v10 > 0 )
  {
    do
    {
      v21 = v15++;
      v9->mResults[v21]->mResultReady = 0;
      v9->mResults[v21]->mResultVertNum = 0;
    }
    while ( v15 < v9->mMaxResults );
  }
  *(_WORD *)&v9->mQueryReady = 1;
  return 1;
}

// File Line: 209
// RVA: 0x1DFF0
__int64 __fastcall Render::SkinClipInfo::GetResultVertexCount(Render::SkinClipInfo *this)
{
  unsigned int v1; // er11
  int v2; // edx
  int v3; // er9
  unsigned int v4; // ebx
  unsigned int v5; // edi
  __int64 v6; // r8
  unsigned int v7; // eax
  __int64 v8; // r10
  Render::SkinClipInfo::ClipResult *v9; // rax

  v1 = this->mMaxResults;
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = 0i64;
  if ( (signed int)v1 >= 2 )
  {
    v7 = ((v1 - 2) >> 1) + 1;
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
  if ( v5 < v1 )
    v4 = this->mResults[v6]->mResultVertNum;
  return v4 + v3 + v2;
}

// File Line: 219
// RVA: 0x1E110
char __fastcall Render::SkinClipInfo::ReadQueryResult(Render::SkinClipInfo *this, Render::SkinClipInfo::ClipOutputVertex *clip_verts, unsigned int clip_vert_num, unsigned int *result_verts_written)
{
  Render::SkinClipInfo *v4; // rdi
  unsigned int *v5; // r12
  unsigned int v6; // ecx
  unsigned int v7; // er14
  Render::SkinClipInfo::ClipOutputVertex *v8; // r15
  int v9; // eax
  unsigned int v10; // ebx
  const void **v11; // rsi
  unsigned int v12; // ebp
  char result; // al

  v4 = this;
  v5 = result_verts_written;
  *result_verts_written = 0;
  v6 = this->mMaxResults;
  v7 = clip_vert_num;
  v8 = clip_verts;
  v9 = 0;
  if ( v6 )
  {
    while ( v4->mResults[v9]->mResultReady )
    {
      if ( ++v9 >= v6 )
        goto LABEL_4;
    }
    result = 0;
  }
  else
  {
LABEL_4:
    v10 = 0;
    if ( v6 )
    {
      do
      {
        v11 = (const void **)&v4->mResults[v10];
        v12 = *((_DWORD *)*v11 + 353);
        if ( v7 >= v12 )
        {
          UFG::qMemCopy(v8, *v11, 44 * v12);
          *v5 += v12;
          v8 += v12;
          v7 -= v12;
        }
        ++v10;
        *((_BYTE *)*v11 + 1408) = 0;
        *((_DWORD *)*v11 + 353) = 0;
      }
      while ( v10 < v4->mMaxResults );
    }
    *(_WORD *)&v4->mQueryReady = 0;
    result = 1;
  }
  return result;
}

// File Line: 253
// RVA: 0x1C840
UFG::BitFlags128 *__fastcall Render::DefaultRenderMeshFunc(UFG::BitFlags128 *result, Render::View *view, Illusion::Mesh *mesh, UFG::qMatrix44 *local_world, Illusion::Material *material, UFG::BitFlags128 *already_called_funcs_mask)
{
  UFG::BitFlags128 *v6; // rbx
  UFG::BitFlags128 v8; // [rsp+40h] [rbp-18h]

  v6 = result;
  v8 = *already_called_funcs_mask;
  Render::View::Draw(view, result, mesh, local_world);
  return v6;
}

// File Line: 258
// RVA: 0x1C8A0
UFG::BitFlags128 *__fastcall Render::DefaultRenderRMeshFunc(UFG::BitFlags128 *result, Render::View *view, Illusion::rMesh *rmesh, UFG::qMatrix44 *local_world)
{
  UFG::qMatrix44 *v4; // rsi
  Illusion::rMesh *v5; // r13
  Render::View *v6; // rdi
  UFG::BitFlags128 *v7; // r12
  Illusion::StateArgs *v8; // rbx
  UFG::qMatrix44 *v9; // r15
  unsigned __int16 v10; // ax
  unsigned __int16 v11; // ax
  void (__fastcall *v12)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v13)(Illusion::StateArg *, Illusion::StateValues *); // rax
  unsigned __int64 *v14; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v15; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v16; // rax
  unsigned __int64 *v17; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v19; // rax
  void (__fastcall *v20)(Illusion::StateArg *, Illusion::StateValues *); // rcx
  void (__fastcall **v21)(Illusion::StateArg *, Illusion::StateValues *); // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rax
  Render::cbLocalProjectionState v27; // [rsp+30h] [rbp-79h]
  UFG::qMatrix44 *v28; // [rsp+68h] [rbp-41h]
  __int64 v29; // [rsp+70h] [rbp-39h]
  Render::cbLocalTransformState arg; // [rsp+78h] [rbp-31h]
  __int128 v31; // [rsp+A8h] [rbp-1h]
  __int64 v32; // [rsp+B8h] [rbp+Fh]
  Illusion::rMaterial *retaddr; // [rsp+118h] [rbp+6Fh]
  __int128 *v34; // [rsp+120h] [rbp+77h]

  v32 = -2i64;
  v4 = local_world;
  v5 = rmesh;
  v6 = view;
  v7 = result;
  v8 = Render::View::GetStateArgs(view);
  v9 = &v6->mSettings->mWorldView;
  Render::cbLocalTransformState::cbLocalTransformState(&arg, &v6->mSettings->mWorldView, &v6->mWorldViewProjection, v4);
  v27.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
  v27.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
  v27.mCallback = 0i64;
  v27.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
  *(_WORD *)&v27.mFlags = 1;
  if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == -1 )
  {
    v10 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
    Render::cbLocalProjectionState::sStateParamIndex = v10;
    v27.mStateParamIndex = v10;
  }
  v27.mNext = 0i64;
  v27.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)v4;
  v27.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v27.mCallback;
  *(_QWORD *)&v27.mStateParamIndex = (char *)&v27 + 16;
  v27.mWorldViewProjection = 0i64;
  LOWORD(v27.mLocalWorld) = Render::cbLocalTransformInverseState::sStateParamIndex;
  WORD1(v27.mLocalWorld) = 1;
  if ( (_WORD)Render::cbLocalTransformInverseState::sStateParamIndex == -1 )
  {
    v11 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalTransformInverse");
    Render::cbLocalTransformInverseState::sStateParamIndex = v11;
    LOWORD(v27.mLocalWorld) = v11;
  }
  v29 = 0i64;
  v27.mCached_Remote.m_Stream = v9;
  v28 = v4;
  Illusion::StateArgs::Set<Render::cbLocalTransformState>(v8, &arg);
  Illusion::StateArgs::Set<Render::cbLocalProjectionState>(v8, &v27);
  Illusion::StateArgs::Set<Render::cbLocalTransformInverseState>(
    v8,
    (Render::cbLocalTransformInverseState *)&v27.mCallback);
  v31 = *v34;
  Illusion::SubmitContext::Draw(v6->mSubmitContext, v7, v5, retaddr, (UFG::BitFlags128 *)&v31, v5);
  v12 = v27.mCallback;
  v13 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v27.mStateParamIndex;
  *((_QWORD *)v27.mCallback + 1) = *(_QWORD *)&v27.mStateParamIndex;
  *v13 = v12;
  v27.mCallback = (void (__fastcall *)(Illusion::StateArg *, Illusion::StateValues *))&v27.mCallback;
  *(_QWORD *)&v27.mStateParamIndex = (char *)&v27 + 16;
  BYTE3(v27.mLocalWorld) = 0;
  if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (SLOWORD(v27.mLocalWorld) + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (SLOWORD(v27.mLocalWorld) + 3i64)) )
  {
    v14 = &v8->mStateArgsCreateMask.mFlags[(unsigned int)SLOWORD(v27.mLocalWorld) >> 6];
    *v14 &= ~(1i64 << ((_QWORD)v27.mLocalWorld & 0x3F));
  }
  v15 = v27.mPrev;
  v16 = v27.mNext;
  v27.mPrev->mNext = v27.mNext;
  v16->mPrev = v15;
  v27.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
  v27.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
  v27.mIsSet = 0;
  if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (v27.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (v27.mStateParamIndex + 3i64)) )
  {
    v17 = &v8->mStateArgsCreateMask.mFlags[(unsigned int)v27.mStateParamIndex >> 6];
    *v17 &= ~(1i64 << (v27.mStateParamIndex & 0x3F));
  }
  v18 = arg.mPrev;
  v19 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v19->mPrev = v18;
  arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
  arg.mIsSet = 0;
  if ( (Illusion::StateArgs *)v8->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v8 + 16 * (arg.mStateParamIndex + 3i64)) )
    v8->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
  v20 = v27.mCallback;
  v21 = *(void (__fastcall ***)(Illusion::StateArg *, Illusion::StateValues *))&v27.mStateParamIndex;
  *((_QWORD *)v27.mCallback + 1) = *(_QWORD *)&v27.mStateParamIndex;
  *v21 = v20;
  v22 = v27.mPrev;
  v23 = v27.mNext;
  v27.mPrev->mNext = v27.mNext;
  v23->mPrev = v22;
  v24 = arg.mPrev;
  v25 = arg.mNext;
  arg.mPrev->mNext = arg.mNext;
  v25->mPrev = v24;
  return v7;
}

// File Line: 280
// RVA: 0x1C830
void __fastcall Render::DefaultRenderDecalFunc(Render::View *view, Illusion::Primitive *prim, Illusion::Material *material, UFG::qMatrix44 *local_world)
{
  Render::View::Draw(view, prim, material, local_world);
}

// File Line: 285
// RVA: 0x1E060
void __fastcall Render::Skinning::Init(Render::Skinning *this)
{
  unsigned int v1; // edi
  Render::Skinning *v2; // rbx
  UFG::qResourceInventory *v3; // rax
  UFG::qResourceWarehouse *v4; // rax

  v1 = sDecalVertexDeclUID;
  this->mTaskGroup = 0i64;
  this->mRenderMeshFunc = (UFG::BitFlags128 *(__fastcall *)(UFG::BitFlags128 *, Render::View *, Illusion::Mesh *, UFG::qMatrix44 *, Illusion::Material *, UFG::BitFlags128, const char *))Render::DefaultRenderMeshFunc;
  this->mEnablePersistentCache = 0;
  this->mRenderRMeshFunc = (UFG::BitFlags128 *(__fastcall *)(UFG::BitFlags128 *, Render::View *, Illusion::rMesh *, UFG::qMatrix44 *, Illusion::rMaterial *, UFG::BitFlags128, const char *))Render::DefaultRenderRMeshFunc;
  v2 = this;
  this->mRenderDecalFunc = Render::DefaultRenderDecalFunc;
  v3 = `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result )
  {
    v4 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v4, 0x3E5FDA3Eu);
    `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result = v3;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v2->mDecalVertexDecl.mPrev, 0x3E5FDA3Eu, v1, v3);
}

// File Line: 335
// RVA: 0x1E770
void __fastcall Render::Skinning::SetCurrentTaskGroup(Render::Skinning *this, UFG::qTaskGroup *task_group)
{
  this->mTaskGroup = task_group;
}

// File Line: 346
// RVA: 0x1C6A0
Illusion::Buffer *__fastcall Render::Skinning::AllocateVertexBuffer(Render::Skinning *this, Illusion::Buffer *source_buffer, unsigned int instance_uid, bool use_vram)
{
  Illusion::Buffer *v4; // rbp
  Render::Skinning *v5; // rdi
  unsigned __int64 v6; // r10
  Render::Skinning *v7; // rax
  Render::Skinning *v8; // rcx
  bool i; // zf
  Render::Skinning *j; // rcx
  _DWORD *v11; // rbx
  unsigned int v12; // edx
  UFG::qLinearAllocator *v13; // rcx
  char *v14; // rsi
  unsigned int v16; // eax
  Illusion::Buffer *v17; // rax
  UFG::qOffset64<void *> *v18; // rax
  UFG::qBaseNodeVariableRB<unsigned __int64> *v19; // rdx
  unsigned __int64 v20; // rax
  unsigned __int64 data; // [rsp+88h] [rbp+10h]

  v4 = source_buffer;
  v5 = this;
  v6 = (unsigned int)source_buffer | ((unsigned __int64)instance_uid << 32);
  data = (unsigned int)source_buffer | ((unsigned __int64)instance_uid << 32);
  if ( v6 )
  {
    v7 = this;
    v8 = (Render::Skinning *)((char *)this + 32);
    for ( i = v7 == v8; !i; i = v7 == v8 )
    {
      if ( v7 != v5 && v7->mSkinnedVertexBuffers.mTree.mRoot.mUID == v6 )
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
          v11 = v7->mSkinnedVertexBuffers.mTree.mNULL.mParent;
          if ( v11 )
            return (Illusion::Buffer *)v11;
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
  v13 = Illusion::gEngine.FrameWriteMemory;
  if ( !use_vram )
    v13 = Illusion::gEngine.FrameMemory;
  v14 = UFG::qLinearAllocator::Malloc(v13, v12, 0x10u);
  if ( !v14 )
    return 0i64;
  v16 = UFG::qDataHash32(&data, 8ui64, 0xFFFFFFFF);
  v17 = Illusion::Factory::NewBuffer(0i64, v16, 0x30u, 0i64, 0i64, Illusion::gEngine.FrameMemory, 0i64);
  v11 = v17;
  if ( !v17 )
    return 0i64;
  v17->mFlags |= 4u;
  v18 = &v17->mData;
  v19 = (UFG::qBaseNodeVariableRB<unsigned __int64> *)((char *)v18 + v18->mOffset);
  if ( !v18->mOffset )
    v19 = 0i64;
  v18->mOffset = v14 - (char *)v18;
  v11[23] = v4->mDataByteSize;
  *((_BYTE *)v11 + 88) = v4->mBufferType;
  v11[26] = v4->mElementByteSize;
  v11[27] = v4->mNumElements;
  if ( v19 )
  {
    v20 = data;
    v19->mParent = 0i64;
    v19->mChild[0] = 0i64;
    v19->mChild[1] = 0i64;
    v19->mUID = v20;
    v19[1].mParent = (UFG::qBaseNodeVariableRB<unsigned __int64> *)v11;
  }
  UFG::qBaseTreeVariableRB<unsigned __int64>::Add(&v5->mSkinnedVertexBuffers.mTree, v19);
  return (Illusion::Buffer *)v11;
}

// File Line: 414
// RVA: 0x1C5E0
Illusion::Buffer *__fastcall Render::Skinning::AllocateDecalVertexBuffer(Render::Skinning *this, unsigned int decal_count)
{
  unsigned int v2; // esi
  unsigned int v3; // ebx
  char *v4; // rdi
  Illusion::Buffer *result; // rax
  unsigned int v6; // eax

  v2 = decal_count;
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
  result->mNumElements = v2;
  result->mBufferType = 0;
  result->mElementByteSize = 28;
  return result;
}

// File Line: 462
// RVA: 0x1EB30
bool __fastcall Render::Skinning::SupportsSkinnedDecals(Render::Skinning *this, Illusion::ModelProxy *model_proxy, unsigned int *task_uid, unsigned int *mesh_count)
{
  unsigned int *v4; // r14
  unsigned int *v5; // r15
  Illusion::ModelProxy *v6; // rsi
  Render::Skinning *v7; // rbp
  unsigned int v9; // edi
  UFG::qResourceData *v10; // rax
  UFG::qBaseNodeRB *v11; // rcx
  signed __int64 v12; // rcx
  _QWORD *v13; // rdx
  Illusion::Material **v14; // rcx
  Illusion::rModel *v15; // rdx
  signed __int64 v16; // rax
  unsigned int v17; // edx
  __int64 v18; // rax
  UFG::qBaseTreeRB *v19; // rax

  v4 = mesh_count;
  v5 = task_uid;
  v6 = model_proxy;
  v7 = this;
  if ( !model_proxy->mModelHandle.mData && !model_proxy->mRModel )
    return 0;
  if ( !(_S1_1 & 1) )
  {
    _S1_1 |= 1u;
    material_shader_uid = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  }
  *v4 = 0;
  v9 = 0;
  if ( (unsigned int)Illusion::ModelProxy::GetNumMeshes(v6) )
  {
    do
    {
      v10 = v6->mModelHandle.mData;
      if ( !v10
        || ((v11 = v10[2].mNode.mChild[0]) == 0i64 ? (v12 = 0i64) : (v12 = (signed __int64)&v11[5].mUID + (_QWORD)v10),
            v13 = (_QWORD *)(v12 + 8i64 * v9),
            v14 = (Illusion::Material **)((char *)v13 + *v13),
            !*v13) )
      {
        v14 = 0i64;
      }
      v15 = v6->mRModel;
      if ( v15 )
        v16 = (signed __int64)&v15->mMeshes.mData.mItems[v9];
      else
        v16 = 0i64;
      if ( v14 )
      {
        v17 = (unsigned int)Illusion::Material::GetParamByNameUID(v14[2], 0x5C19C934u)->mResourceHandles.mNode.mNext;
      }
      else
      {
        v18 = *(_QWORD *)(v16 + 48);
        if ( !v18 )
        {
          v17 = -1;
LABEL_23:
          v19 = UFG::qBaseTreeRB::Get(&v7->mUserSkinningTasks.mTree, v17);
          if ( v19 && (*(_QWORD *)&v19->mNULL.mUID || *(_QWORD *)&v19->mCount) )
          {
            *v5 = v19->mRoot.mUID;
            ++*v4;
          }
          goto LABEL_27;
        }
        v17 = *(_DWORD *)(*(_QWORD *)(v18 + 104) + 24i64);
      }
      if ( v17 )
        goto LABEL_23;
LABEL_27:
      ++v9;
    }
    while ( v9 < (unsigned int)Illusion::ModelProxy::GetNumMeshes(v6) );
  }
  return *v4 != 0;
}

// File Line: 511
// RVA: 0x1E5B0
void __fastcall Render::Skinning::SelectSkinningTask(Render::Skinning *this, UFG::qTaskFunctionDeclData **skinning_task_decl, Illusion::MeshProxy *mesh_proxy, Illusion::Mesh *morph_mesh, unsigned int *task_uid, Render::SkinningParams *skinning_params, const bool decal_pass)
{
  Render::Skinning *v7; // r13
  Illusion::Mesh *v8; // rcx
  Illusion::Mesh *v9; // r10
  UFG::qTaskFunctionDeclData **v10; // rbx
  Illusion::BufferHandle *v11; // rax
  UFG::qResourceData *v12; // r9
  Illusion::BufferHandle *v13; // rax
  UFG::qResourceData *v14; // rdx
  Illusion::BufferHandle *v15; // rax
  bool v16; // bp
  bool v17; // r15
  bool v18; // r14
  bool v19; // di
  bool v20; // si
  unsigned int v21; // edx
  UFG::qReflectObject *v22; // rax
  UFG::qBaseTreeRB *v23; // rax
  UFG::qBaseNodeRB *v24; // rcx
  UFG::qTaskFunctionDeclData *v25; // rax

  v7 = this;
  v8 = mesh_proxy->mMesh;
  v9 = morph_mesh;
  v10 = skinning_task_decl;
  if ( mesh_proxy->mMesh )
    v11 = v8->mVertexBufferHandles;
  else
    v11 = mesh_proxy->mRMesh->mVertexBufferHandles;
  v12 = v11->mData;
  if ( v8 )
    v13 = &v8->mVertexBufferHandles[1];
  else
    v13 = &mesh_proxy->mRMesh->mVertexBufferHandles[1];
  v14 = v13->mData;
  if ( v8 )
    v15 = &v8->mVertexBufferHandles[2];
  else
    v15 = &mesh_proxy->mRMesh->mVertexBufferHandles[2];
  v16 = v12 && v14 && v15->mData;
  v17 = v9 != 0i64;
  v18 = skinning_params->morph_weights_count != 0;
  v19 = v9 || v18;
  v20 = skinning_params->mUsePersistentCache && v7->mEnablePersistentCache;
  if ( v8 )
  {
    v21 = (unsigned int)Illusion::Material::GetParamByNameUID(
                          (Illusion::Material *)v8->mMaterialHandle.mData,
                          0x5C19C934u)->mResourceHandles.mNode.mNext;
    goto LABEL_27;
  }
  v22 = mesh_proxy->mRMesh->mMaterial.mData;
  if ( v22 )
  {
    v21 = (unsigned int)v22[1].mBaseNode.mChildren[0]->mChildren[1];
LABEL_27:
    if ( !v21 )
      goto LABEL_41;
    goto LABEL_30;
  }
  v21 = -1;
LABEL_30:
  v23 = UFG::qBaseTreeRB::Get(&v7->mUserSkinningTasks.mTree, v21);
  if ( v23 )
  {
    if ( decal_pass )
    {
      if ( v19 )
        v24 = *(UFG::qBaseNodeRB **)&v23->mCount;
      else
        v24 = *(UFG::qBaseNodeRB **)&v23->mNULL.mUID;
    }
    else if ( v20 )
    {
      v24 = v23->mNULL.mChild[1];
    }
    else if ( v19 )
    {
      v24 = v23->mNULL.mChild[0];
    }
    else
    {
      v24 = v23->mNULL.mParent;
    }
    *v10 = (UFG::qTaskFunctionDeclData *)v24;
    *task_uid = v23->mRoot.mUID;
  }
LABEL_41:
  if ( !*v10 && v16 )
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
    *v10 = v25;
  }
}

// File Line: 585
// RVA: 0x1E200
char __fastcall Render::Skinning::RegisterUserSkinningTask(Render::Skinning *this, unsigned int shader_uid, UFG::qTaskFunctionDeclData *skin_task_decl, UFG::qTaskFunctionDeclData *morph_skin_task_decl, UFG::qTaskFunctionDeclData *cache_skin_task_decl, UFG::qTaskFunctionDeclData *skin_decal_task_decl, UFG::qTaskFunctionDeclData *morph_skin_decal_task_decl)
{
  UFG::qTaskFunctionDeclData *v7; // rsi
  UFG::qTaskFunctionDeclData *v8; // rbp
  unsigned int v9; // ebx
  Render::Skinning *v10; // rdi
  char *v12; // rax
  UFG::qBaseNodeRB *v13; // rdx

  v7 = morph_skin_task_decl;
  v8 = skin_task_decl;
  v9 = shader_uid;
  v10 = this;
  if ( shader_uid && UFG::qBaseTreeRB::Get(&this->mUserSkinningTasks.mTree, shader_uid) )
    return 0;
  v12 = UFG::qMalloc(0x48ui64, "SkinningTaskNode", 0x800ui64);
  v13 = (UFG::qBaseNodeRB *)v12;
  if ( v12 )
  {
    *(_QWORD *)v12 = 0i64;
    *((_QWORD *)v12 + 1) = 0i64;
    *((_QWORD *)v12 + 2) = 0i64;
    *((_DWORD *)v12 + 6) = v9;
    *((_QWORD *)v12 + 4) = v8;
    *((_QWORD *)v12 + 5) = v7;
    *((_QWORD *)v12 + 6) = cache_skin_task_decl;
    *((_QWORD *)v12 + 7) = skin_decal_task_decl;
    *((_QWORD *)v12 + 8) = morph_skin_decal_task_decl;
  }
  else
  {
    v13 = 0i64;
  }
  UFG::qBaseTreeRB::Add(&v10->mUserSkinningTasks.mTree, v13);
  return 1;
}

// File Line: 607
// RVA: 0x1D2B0
char __fastcall Render::Skinning::DrawSkinnedModel(Render::Skinning *this, Render::SkinningParams *skinning_params)
{
  Render::SkinningParams *v2; // rdi
  Render::Skinning *v3; // r15
  char *v4; // r14
  Illusion::ModelProxy *v5; // rcx
  UFG::qResourceData *v6; // rdx
  Illusion::rModel *v7; // rcx
  Illusion::rModel *v8; // rcx
  __int64 v9; // r12
  __m128i v10; // xmm6
  Illusion::ModelProxy *v11; // rcx
  _DWORD *v12; // rax
  UFG::qResourceData *v13; // rax
  UFG::qBaseNodeRB *v14; // rdx
  UFG::qBaseNodeRB **v15; // r8
  char *v16; // rsi
  Illusion::rModel *v17; // rax
  signed __int64 v18; // r13
  Illusion::Mesh *v19; // rbx
  Illusion::Model *v20; // rax
  __int64 v21; // rcx
  _QWORD *v22; // rdx
  Illusion::Material *v23; // r8
  UFG::qMatrix44 *v24; // rcx
  int *v25; // rax
  int *v26; // rax
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
  unsigned int v39; // er9
  __m128i *v40; // rax
  signed __int64 v41; // rax
  Illusion::Buffer *v42; // r10
  signed __int64 v43; // rax
  signed __int64 v44; // rax
  unsigned int v45; // er8
  __int64 v46; // r14
  unsigned __int64 v47; // rdx
  Render::Skinning *v48; // rax
  bool i; // zf
  Render::Skinning *j; // rcx
  Illusion::Buffer *v51; // rbx
  bool v52; // zf
  bool v53; // r12
  unsigned __int64 v54; // r15
  unsigned int v55; // er14
  Render::PersistentSkinningCacheNode *v56; // rax
  Render::PersistentSkinningCacheNode *v57; // r9
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v58; // r8
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v59; // rdx
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v60; // rcx
  UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *v61; // rax
  __int64 v62; // rax
  char *v63; // rcx
  unsigned int v64; // ebx
  char *v65; // rbx
  __int64 v66; // rax
  __int64 v67; // rax
  signed __int64 v68; // r12
  char *v69; // rax
  __int64 v70; // rdx
  __int64 v71; // rax
  __int64 v72; // rax
  __int64 v73; // rax
  __int64 v74; // rax
  __int64 v75; // rax
  __int64 v76; // rcx
  __int64 v77; // rax
  UFG::qResourceData *v78; // rax
  UFG::qBaseNodeRB *v79; // rcx
  signed __int64 v80; // rax
  unsigned int v81; // ecx
  UFG::qResourceData *v82; // r14
  __int64 v83; // r14
  unsigned int v84; // er15
  __int64 v85; // rcx
  __int64 v86; // rax
  int v87; // eax
  __int64 v88; // r9
  int v89; // er11
  __int64 v90; // r8
  unsigned int v91; // er10
  float v92; // xmm0_4
  int v93; // eax
  Render::SkinClipInfo *v94; // rcx
  unsigned int v95; // edx
  UFG::qTaskGroup *v96; // r14
  char *v97; // rax
  UFG::qTask *v98; // rdx
  _QWORD *v99; // rcx
  UFG::qTaskFunctionDeclData *v100; // rcx
  UFG::qSpuElf *v101; // rax
  void (__fastcall *v102)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v103)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v104)(void *, void *, void *, void *); // r9
  char *v105; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v106; // rax
  _QWORD *v107; // rax
  UFG::qTaskFunctionDeclData *v108; // rcx
  UFG::qSpuElf *v109; // rax
  void (__fastcall *v110)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v111)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v112)(void *, void *, void *, void *); // r9
  char *v113; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v114; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v115; // rax
  Illusion::StateArgs *v116; // rbx
  unsigned __int16 v117; // ax
  __m128i *v118; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v119; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v120; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v121; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v122; // rax
  __m128i v124; // [rsp+40h] [rbp-C0h]
  const char *v125; // [rsp+50h] [rbp-B0h]
  Illusion::Buffer *v126; // [rsp+58h] [rbp-A8h]
  Render::cbSkinnedVertexStreamState arg; // [rsp+60h] [rbp-A0h]
  UFG::qTaskFunctionDeclData *skinning_task_decl; // [rsp+88h] [rbp-78h]
  Illusion::Mesh *v129; // [rsp+90h] [rbp-70h]
  __int64 v130; // [rsp+98h] [rbp-68h]
  char *v131; // [rsp+A0h] [rbp-60h]
  Illusion::MeshProxy mesh_proxy; // [rsp+A8h] [rbp-58h]
  void *v133; // [rsp+B8h] [rbp-48h]
  void *dest; // [rsp+C0h] [rbp-40h]
  int v135; // [rsp+D0h] [rbp-30h]
  int v136; // [rsp+D4h] [rbp-2Ch]
  int v137; // [rsp+D8h] [rbp-28h]
  int v138; // [rsp+DCh] [rbp-24h]
  int v139; // [rsp+E0h] [rbp-20h]
  int v140; // [rsp+E4h] [rbp-1Ch]
  int v141; // [rsp+E8h] [rbp-18h]
  int v142; // [rsp+ECh] [rbp-14h]
  int v143; // [rsp+F0h] [rbp-10h]
  int v144; // [rsp+F4h] [rbp-Ch]
  int v145; // [rsp+F8h] [rbp-8h]
  int v146; // [rsp+FCh] [rbp-4h]
  int v147; // [rsp+100h] [rbp+0h]
  int v148; // [rsp+104h] [rbp+4h]
  int v149; // [rsp+108h] [rbp+8h]
  int v150; // [rsp+10Ch] [rbp+Ch]
  int v151; // [rsp+110h] [rbp+10h]
  int v152; // [rsp+114h] [rbp+14h]
  int v153; // [rsp+118h] [rbp+18h]
  int v154; // [rsp+11Ch] [rbp+1Ch]
  int v155; // [rsp+120h] [rbp+20h]
  int v156; // [rsp+124h] [rbp+24h]
  int v157; // [rsp+128h] [rbp+28h]
  int v158; // [rsp+12Ch] [rbp+2Ch]
  int v159; // [rsp+130h] [rbp+30h]
  int v160; // [rsp+134h] [rbp+34h]
  int v161; // [rsp+138h] [rbp+38h]
  int v162; // [rsp+13Ch] [rbp+3Ch]
  int v163; // [rsp+140h] [rbp+40h]
  int v164; // [rsp+144h] [rbp+44h]
  int v165; // [rsp+148h] [rbp+48h]
  int v166; // [rsp+14Ch] [rbp+4Ch]
  __int64 v167; // [rsp+150h] [rbp+50h]
  __int128 v168; // [rsp+160h] [rbp+60h]
  __int64 v169; // [rsp+170h] [rbp+70h]
  __int128 v170; // [rsp+180h] [rbp+80h]
  __int128 v171; // [rsp+190h] [rbp+90h]
  AMD_HD3D *v172[2]; // [rsp+1A0h] [rbp+A0h]
  char v173; // [rsp+1B0h] [rbp+B0h]
  char v174; // [rsp+1C0h] [rbp+C0h]
  char v175; // [rsp+1D0h] [rbp+D0h]
  char v176; // [rsp+1E0h] [rbp+E0h]
  UFG::qMatrix44 result; // [rsp+1F0h] [rbp+F0h]
  Render::Skinning *v178; // [rsp+290h] [rbp+190h]
  int v179; // [rsp+298h] [rbp+198h]
  unsigned int task_uid; // [rsp+2A0h] [rbp+1A0h]
  unsigned int v181; // [rsp+2A8h] [rbp+1A8h]

  v178 = this;
  v169 = -2i64;
  v2 = skinning_params;
  v3 = this;
  v124 = 0ui64;
  v4 = "NULL";
  v125 = "NULL";
  v5 = skinning_params->skin_model_proxy;
  v6 = v5->mModelHandle.mData;
  if ( v6 )
  {
    HIDWORD(v6[2].mResourceHandles.mNode.mPrev) = Illusion::gEngine.mFrameCount;
    v4 = v2->skin_model_proxy->mModelHandle.mData->mDebugName;
LABEL_7:
    v125 = v4;
    goto LABEL_8;
  }
  v7 = v5->mRModel;
  if ( v7 )
  {
    v7->mLastUsedFrameNum = Illusion::gEngine.mFrameCount;
    v8 = v2->skin_model_proxy->mRModel;
    if ( v8->mModelName.mText.mData.mNumItems )
      v4 = v8->mModelName.mText.mData.mItems;
    else
      v4 = &customWorldMapCaption;
    goto LABEL_7;
  }
LABEL_8:
  v181 = 0;
  v9 = 0i64;
  v10 = v124;
  while ( 1 )
  {
    v179 = v9;
    v11 = v2->skin_model_proxy;
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
      goto LABEL_167;
    v14 = v13[2].mNode.mChild[0];
    if ( v14 )
      v14 = (UFG::qBaseNodeRB *)((char *)v14 + (_QWORD)v13 + 184);
    v15 = &v14->mParent + v9;
    if ( *v15 )
      v16 = (char *)*v15 + (_QWORD)v15;
    else
LABEL_167:
      v16 = 0i64;
    mesh_proxy.mMesh = (Illusion::Mesh *)v16;
    v17 = v11->mRModel;
    if ( v17 )
      v18 = (signed __int64)&v17->mMeshes.mData.mItems[(unsigned int)v9];
    else
      v18 = 0i64;
    mesh_proxy.mRMesh = (Illusion::rMesh *)v18;
    v19 = 0i64;
    v129 = 0i64;
    v20 = v2->simple_morph_target;
    if ( v20 )
    {
      v21 = v20->mMeshOffsetTable.mOffset;
      if ( v21 )
        v21 += (__int64)&v20->mMeshOffsetTable;
      v22 = (_QWORD *)(v21 + 8 * v9);
      if ( *v22 )
        v19 = (Illusion::Mesh *)((char *)v22 + *v22);
      v129 = v19;
    }
    if ( v16 )
    {
      if ( !Illusion::IEnginePlat::IsValidDrawCall(
              (Illusion::IEnginePlat *)&Illusion::gEngine,
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
              (Illusion::IEnginePlat *)&Illusion::gEngine,
              (Illusion::rMesh *)v18,
              *(Illusion::rMaterial **)(v18 + 48),
              0i64,
              0i64) )
        return 0;
      if ( !v19 )
        goto LABEL_38;
      v23 = 0i64;
    }
    if ( !Illusion::IEnginePlat::IsValidDrawCall((Illusion::IEnginePlat *)&Illusion::gEngine, v19, v23, 0i64, 0i64) )
      return 0;
LABEL_38:
    skinning_task_decl = 0i64;
    task_uid = 0;
    Render::Skinning::SelectSkinningTask(v3, &skinning_task_decl, &mesh_proxy, v19, &task_uid, v2, 0);
    if ( !skinning_task_decl )
    {
      v24 = v2->mRigidTransform;
      if ( v24 )
      {
        v25 = (int *)UFG::qMatrix44::operator*(v24, &result, v2->local_transform);
      }
      else
      {
        v26 = (int *)v2->local_transform;
        v151 = *v26;
        v152 = v26[1];
        v153 = v26[2];
        v154 = v26[3];
        v155 = v26[4];
        v156 = v26[5];
        v157 = v26[6];
        v158 = v26[7];
        v159 = v26[8];
        v160 = v26[9];
        v161 = v26[10];
        v162 = v26[11];
        v163 = v26[12];
        v164 = v26[13];
        v165 = v26[14];
        v166 = v26[15];
        v25 = &v151;
      }
      v27 = v25[1];
      v28 = v25[2];
      v29 = v25[3];
      v135 = *v25;
      v136 = v27;
      v137 = v28;
      v138 = v29;
      v30 = v25[5];
      v31 = v25[6];
      v32 = v25[7];
      v139 = v25[4];
      v140 = v30;
      v141 = v31;
      v142 = v32;
      v33 = v25[9];
      v34 = v25[10];
      v35 = v25[11];
      v143 = v25[8];
      v144 = v33;
      v145 = v34;
      v146 = v35;
      v36 = v25[13];
      v37 = v25[14];
      v38 = v25[15];
      v147 = v25[12];
      v148 = v36;
      v149 = v37;
      v150 = v38;
      v39 = Render::cbLocalTransformState::sStateParamIndex;
      if ( v2->mRigidTransform )
      {
        v124.m128i_i64[(unsigned int)Render::cbLocalTransformState::sStateParamIndex >> 6] &= ~(1i64 << (Render::cbLocalTransformState::sStateParamIndex & 0x3F));
        v10 = v124;
      }
      if ( v16 )
      {
        _mm_store_si128((__m128i *)&v170, v10);
        v40 = (__m128i *)((__int64 (__fastcall *)(char *, Render::View *, char *, int *, _QWORD, __int128 *, char *))v3->mRenderMeshFunc)(
                           &v173,
                           v2->view,
                           v16,
                           &v135,
                           *((_QWORD *)v16 + 2),
                           &v170,
                           v4);
        goto LABEL_48;
      }
      if ( v18 )
      {
        _mm_store_si128((__m128i *)&v168, v10);
        v40 = (__m128i *)((__int64 (__fastcall *)(char *, Render::View *, signed __int64, int *, _QWORD, __int128 *, char *))v3->mRenderRMeshFunc)(
                           &v176,
                           v2->view,
                           v18,
                           &v135,
                           *(_QWORD *)(v18 + 48),
                           &v168,
                           v4);
LABEL_48:
        v10 = *v40;
        v39 = Render::cbLocalTransformState::sStateParamIndex;
        v124 = *v40;
      }
      if ( v2->mRigidTransform )
      {
        v124.m128i_i64[v39 >> 6] &= ~(1i64 << (v39 & 0x3F));
        v10 = v124;
      }
      goto LABEL_162;
    }
    v41 = (signed __int64)(v16 + 96);
    if ( !v16 )
      v41 = v18 + 120;
    v42 = *(Illusion::Buffer **)(v41 + 16);
    v130 = *(_QWORD *)(v41 + 16);
    v43 = (signed __int64)(v16 + 128);
    if ( !v16 )
      v43 = v18 + 152;
    v167 = *(_QWORD *)(v43 + 16);
    v44 = (signed __int64)(v16 + 64);
    if ( !v16 )
      v44 = v18 + 88;
    v131 = *(char **)(v44 + 16);
    v45 = v2->instance_uid;
    v46 = (unsigned int)v42;
    v47 = (unsigned int)v42 | ((unsigned __int64)v2->instance_uid << 32);
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
          v51 = (Illusion::Buffer *)v48->mSkinnedVertexBuffers.mTree.mNULL.mParent;
          v126 = v51;
          v52 = v51 == 0i64;
          if ( !v51 )
            goto LABEL_75;
          if ( !v2->clip_info )
            goto LABEL_153;
          goto LABEL_74;
        }
        if ( v47 > v48->mSkinnedVertexBuffers.mTree.mRoot.mUID )
          v48 = (Render::Skinning *)v48->mSkinnedVertexBuffers.mTree.mRoot.mChild[1];
        else
          v48 = (Render::Skinning *)v48->mSkinnedVertexBuffers.mTree.mRoot.mChild[0];
      }
    }
    v51 = 0i64;
    v126 = 0i64;
LABEL_74:
    v52 = v51 == 0i64;
LABEL_75:
    v53 = !v52;
    if ( !v51 )
    {
      v51 = Render::Skinning::AllocateVertexBuffer(v3, v42, v45, 1);
      v126 = v51;
      if ( !v51 )
        return 0;
    }
    Illusion::Buffer::OnLoad(v51);
    v54 = v46 | ((unsigned __int64)v2->instance_uid << 32);
    v55 = (*(_DWORD *)(v130 + 108) * *(_DWORD *)(v130 + 104) + 127) & 0xFFFFFF7F;
    if ( v2->mUsePersistentCache
      && v178->mEnablePersistentCache
      && (v56 = Render::PersistentSkinningCache::Find(&v178->mPersistentSkinningCache, v54), (v57 = v56) != 0i64) )
    {
      v58 = (UFG::qNode<Render::PersistentSkinningCacheNode,Render::PersistentSkinningCacheNode> *)&v56->mPrev;
      v59 = v56->mPrev;
      v60 = v56->mNext;
      v59->mNext = v60;
      v60->mPrev = v59;
      v58->mPrev = v58;
      v58->mNext = v58;
      v3 = v178;
      v61 = v178->mPersistentSkinningCache.mCachedVertexDataList.mNode.mPrev;
      v61->mNext = v58;
      v58->mPrev = v61;
      v58->mNext = &v178->mPersistentSkinningCache.mCachedVertexDataList.mNode;
      v178->mPersistentSkinningCache.mCachedVertexDataList.mNode.mPrev = v58;
      v62 = v51->mData.mOffset;
      if ( v62 )
        v63 = (char *)&v51->mData + v62;
      else
        v63 = 0i64;
      UFG::qMemCopy(v63, v57->mCachedDataPtr, v57->mSize);
    }
    else
    {
      v64 = 48 * v2->transform_count;
      dest = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, v2->bone_matrix_count, 0x10u);
      v133 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, v64, 0x10u);
      UFG::qMemCopy(dest, v2->bone_remap_array, v2->bone_matrix_count);
      UFG::qMemCopy(v133, v2->transform_array, v64);
      v65 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0xB0u, 0x10u);
      if ( v53 || (v66 = v126->mData.mOffset) == 0 )
      {
        v68 = 0i64;
        v67 = 0i64;
      }
      else
      {
        v67 = (__int64)&v126->mData + v66;
        v68 = 0i64;
      }
      *(_QWORD *)v65 = v67;
      if ( v2->mUsePersistentCache && v178->mEnablePersistentCache )
        v69 = Render::PersistentSkinningCache::Store(&v178->mPersistentSkinningCache, v54, v55);
      else
        v69 = 0i64;
      *((_QWORD *)v65 + 18) = v69;
      v70 = v130;
      v71 = *(_QWORD *)(v130 + 96);
      if ( v71 )
        v72 = v130 + v71 + 96;
      else
        v72 = 0i64;
      *((_QWORD *)v65 + 1) = v72;
      v73 = *(_QWORD *)(v167 + 96);
      if ( v73 )
        v74 = v167 + v73 + 96;
      else
        v74 = 0i64;
      *((_QWORD *)v65 + 2) = v74;
      v75 = *((_QWORD *)v131 + 12);
      if ( v75 )
        v76 = (__int64)&v131[v75 + 96];
      else
        v76 = 0i64;
      if ( v16 )
        v77 = *((unsigned int *)v16 + 57);
      else
        v77 = *(unsigned int *)(v18 + 252);
      *((_QWORD *)v65 + 3) = v76 + 2 * v77;
      *((_QWORD *)v65 + 12) = v2->bone_inverse_array;
      *((_QWORD *)v65 + 13) = dest;
      *((_QWORD *)v65 + 4) = v133;
      *((_WORD *)v65 + 20) = v2->bone_matrix_count;
      *((_WORD *)v65 + 21) = 200;
      if ( v129 && (v78 = v129->mVertexBufferHandles[0].mData, (v79 = v78[1].mNode.mChild[0]) != 0i64) )
        v80 = (signed __int64)v78[1].mNode.mChild + (_QWORD)v79;
      else
        v80 = 0i64;
      *((_QWORD *)v65 + 6) = v80;
      *((_DWORD *)v65 + 14) = LODWORD(v2->simple_morph_weight);
      v81 = v2->morph_weights_count;
      if ( v81
        && ((v82 = v2->skin_model_proxy->mModelHandle.mData) == 0i64 ? (v83 = 0i64) : (v83 = *(_QWORD *)&v82[2].mDebugName[20]),
            v83 && *(_DWORD *)(v83 + 120)) )
      {
        v84 = 20;
        if ( v81 < 0x14 )
          v84 = v2->morph_weights_count;
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
        if ( v2->morph_weights_count )
        {
          v91 = 0;
          do
          {
            if ( (unsigned int)v88 >= v84 )
              break;
            v92 = v2->morph_weights_array[v90];
            if ( v92 >= 0.0099999998 )
            {
              *(_QWORD *)(*((_QWORD *)v65 + 19) + 8 * v88) = v68 + v91;
              *(float *)(*((_QWORD *)v65 + 20) + 4 * v88) = v92;
              v88 = (unsigned int)(v88 + 1);
            }
            v90 = (unsigned int)(v90 + 1);
            v91 += v89;
          }
          while ( (unsigned int)v90 < v2->morph_weights_count );
        }
        *((_DWORD *)v65 + 42) = v88;
        v70 = v130;
        LODWORD(v68) = 0;
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
      *((_QWORD *)v65 + 9) = v2->user_data_0;
      *((_QWORD *)v65 + 10) = v2->user_data_1;
      v94 = v2->clip_info;
      if ( v94 && v2->mDecalTaskUID == task_uid )
      {
        *((_QWORD *)v65 + 14) = v94;
        v95 = v181;
        *((_QWORD *)v65 + 17) = v2->clip_info->mResults[v181];
        v181 = v95 + 1;
      }
      else
      {
        *((_QWORD *)v65 + 14) = 0i64;
        *((_QWORD *)v65 + 17) = 0i64;
      }
      *((_QWORD *)v65 + 15) = 0i64;
      *((_DWORD *)v65 + 32) = 0;
      v3 = v178;
      v96 = v178->mTaskGroup;
      v97 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
      v98 = (UFG::qTask *)v97;
      *(_QWORD *)&task_uid = v97;
      v131 = v97;
      if ( v96 )
      {
        if ( v97 )
        {
          *(_QWORD *)v97 = v97;
          *((_QWORD *)v97 + 1) = v97;
          v99 = v97 + 16;
          *v99 = v99;
          v99[1] = v99;
          v100 = skinning_task_decl;
          v101 = skinning_task_decl->mSpuElf;
          v102 = skinning_task_decl->mTaskFunctionSPU;
          v103 = skinning_task_decl->mTaskFunctionPPU;
          v104 = skinning_task_decl->mTaskFunctionOffload;
          if ( !skinning_task_decl->mCurrentSPUEnabled )
          {
            v101 = 0i64;
            v102 = 0i64;
            v104 = 0i64;
          }
          v98->mTaskGroup = v96;
          v98->mFlags = 2;
          v98->mSyncVars.i64 = 0i64;
          v98->mSyncVars.v.mDependents = 0i64;
          v98->mFunctionDeclData = v100;
          if ( v101 )
            v105 = v101->mAddress;
          else
            v105 = 0i64;
          v98->mSPUElfAddress = v105;
          v98->mSPUFunction = v102;
          v98->mPPUFunction = v103;
          v98->mParam0 = v65;
          v98->mParam1 = 0i64;
          v98->mParam2 = 0i64;
          v98->mParam3 = 0i64;
          if ( v104 )
          {
            v98->mFlags = 130;
            v98->mOffloadThread = v68;
          }
        }
        v106 = v96->mTasks.mNode.mPrev;
        v106->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v98->mPrev;
        v98->mPrev = v106;
        v98->mNext = &v96->mTasks.mNode;
        v96->mTasks.mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v98->mPrev;
        ++v96->mNumTasks;
      }
      else
      {
        if ( v97 )
        {
          *(_QWORD *)v97 = v97;
          *((_QWORD *)v97 + 1) = v97;
          v107 = v97 + 16;
          *v107 = v107;
          v107[1] = v107;
          v108 = skinning_task_decl;
          v109 = skinning_task_decl->mSpuElf;
          v110 = skinning_task_decl->mTaskFunctionSPU;
          v111 = skinning_task_decl->mTaskFunctionPPU;
          v112 = skinning_task_decl->mTaskFunctionOffload;
          if ( !skinning_task_decl->mCurrentSPUEnabled )
          {
            v109 = 0i64;
            v110 = 0i64;
            v112 = 0i64;
          }
          v98->mTaskGroup = 0i64;
          v98->mFlags = 2;
          v98->mSyncVars.i64 = 0i64;
          v98->mSyncVars.v.mDependents = 0i64;
          v98->mFunctionDeclData = v108;
          if ( v109 )
            v113 = v109->mAddress;
          else
            v113 = 0i64;
          v98->mSPUElfAddress = v113;
          v98->mSPUFunction = v110;
          v98->mPPUFunction = v111;
          v98->mParam0 = v65;
          v98->mParam1 = 0i64;
          v98->mParam2 = 0i64;
          v98->mParam3 = 0i64;
          if ( v112 )
          {
            v98->mFlags = 130;
            v98->mOffloadThread = v68;
          }
        }
        v114 = UFG::gTaskManager.mSingleFrameTasks;
        v115 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
        v115->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v98->mPrev;
        v98->mPrev = v115;
        v98->mNext = &v114->mNode;
        v114->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v98->mPrev;
        UFG::qTaskManager::Queue(&UFG::gTaskManager, v98);
      }
    }
    LODWORD(v9) = v179;
LABEL_153:
    v116 = Render::View::GetStateArgs(v2->view);
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbSkinnedVertexStreamState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 2;
    if ( (_WORD)Render::cbSkinnedVertexStreamState::sStateParamIndex == -1 )
    {
      v117 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "iVertexBuffer0");
      Render::cbSkinnedVertexStreamState::sStateParamIndex = v117;
      arg.mStateParamIndex = v117;
    }
    arg.mVertexStreamBuffer = v126;
    Illusion::StateArgs::Set<Render::cbSkinnedVertexStreamState>(v116, &arg);
    if ( v16 )
    {
      _mm_store_si128((__m128i *)v172, v10);
      v118 = (__m128i *)((__int64 (__fastcall *)(char *, Render::View *, char *, UFG::qMatrix44 *, _QWORD, AMD_HD3D **, const char *))v3->mRenderMeshFunc)(
                          &v174,
                          v2->view,
                          v16,
                          v2->local_transform,
                          *((_QWORD *)v16 + 2),
                          v172,
                          v125);
      v10 = *v118;
      v124 = *v118;
    }
    else if ( v18 )
    {
      _mm_store_si128((__m128i *)&v171, v10);
      v124 = *(__m128i *)((__int64 (__fastcall *)(char *, Render::View *, signed __int64, UFG::qMatrix44 *, _QWORD, __int128 *, const char *))v3->mRenderRMeshFunc)(
                           &v175,
                           v2->view,
                           v18,
                           v2->local_transform,
                           *(_QWORD *)(v18 + 48),
                           &v171,
                           v125);
      v10 = v124;
    }
    v119 = arg.mPrev;
    v120 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v120->mPrev = v119;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v116->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v116 + 16 * (arg.mStateParamIndex + 3i64)) )
      v116->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v121 = arg.mPrev;
    v122 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v122->mPrev = v121;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
LABEL_162:
    v9 = (unsigned int)(v9 + 1);
    v4 = (char *)v125;
  }
}

// File Line: 919
// RVA: 0x1CC20
char __fastcall Render::Skinning::DrawSkinnedDecal(Render::Skinning *this, Render::SkinningParams *skinning_params)
{
  Render::SkinningParams *v2; // r12
  Render::Skinning *v3; // r15
  unsigned int v5; // er14
  Illusion::ModelProxy *v6; // rcx
  UFG::qResourceData *v7; // rax
  unsigned int v8; // eax
  Illusion::rModel *v9; // rax
  UFG::qResourceData *v10; // rax
  UFG::qBaseNodeRB *v11; // rdx
  signed __int64 v12; // rdx
  _QWORD *v13; // r8
  char *v14; // rbx
  Illusion::rModel *v15; // rax
  signed __int64 v16; // rdi
  Illusion::Mesh *v17; // rsi
  Illusion::Model *v18; // rax
  __int64 v19; // rcx
  signed __int64 v20; // rcx
  _QWORD *v21; // rdx
  Illusion::Material *v22; // r8
  UFG::qTaskFunctionDeclData *v23; // r15
  signed __int64 v24; // rax
  signed __int64 v25; // rax
  __int64 v26; // r13
  signed __int64 v27; // rax
  char *v28; // r14
  __int64 v29; // rax
  UFG::qTaskFunctionDeclData *v30; // rdx
  __int64 v31; // rax
  __int64 v32; // rax
  __int64 v33; // rax
  __int64 v34; // rcx
  __int64 v35; // rax
  UFG::qResourceData *v36; // rax
  UFG::qBaseNodeRB *v37; // rcx
  signed __int64 v38; // rax
  int v39; // eax
  UFG::qTaskGroup *v40; // rbx
  char *v41; // rax
  UFG::qTask *v42; // rdx
  _QWORD *v43; // rcx
  UFG::qSpuElf *v44; // rax
  void (__fastcall *v45)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v46)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v47)(void *, void *, void *, void *); // r9
  char *v48; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v49; // rax
  _QWORD *v50; // rax
  UFG::qSpuElf *v51; // rax
  void (__fastcall *v52)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v53)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v54)(void *, void *, void *, void *); // r9
  char *v55; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v56; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v57; // rax
  Illusion::Primitive *v58; // rdi
  Illusion::Buffer *v59; // rsi
  __int64 v60; // rcx
  char *v61; // r8
  Illusion::StateArgs *v62; // rbx
  unsigned __int16 v63; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v64; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v65; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v66; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v67; // rax
  Illusion::MeshProxy mesh_proxy; // [rsp+48h] [rbp-21h]
  Render::cbSkinnedVertexStreamState arg; // [rsp+58h] [rbp-11h]
  Render::Skinning *v70; // [rsp+D0h] [rbp+67h]
  Illusion::Buffer *task_uid; // [rsp+D8h] [rbp+6Fh]
  UFG::qTaskFunctionDeclData *skinning_task_decl; // [rsp+E0h] [rbp+77h]
  char *v73; // [rsp+E8h] [rbp+7Fh]

  v70 = this;
  v2 = skinning_params;
  v3 = this;
  if ( !skinning_params->mDecalVertNum )
    return 0;
  v5 = 0;
  while ( 1 )
  {
    v6 = v2->skin_model_proxy;
    v7 = v6->mModelHandle.mData;
    if ( v7 )
    {
      v8 = (unsigned int)v7[2].mNode.mChild[1];
    }
    else
    {
      v9 = v6->mRModel;
      if ( v9 )
        v8 = v9->mMeshes.mData.mNumItems;
      else
        v8 = 0;
    }
    if ( v5 >= v8 )
      return 1;
    v10 = v6->mModelHandle.mData;
    if ( !v10
      || ((v11 = v10[2].mNode.mChild[0]) == 0i64 ? (v12 = 0i64) : (v12 = (signed __int64)&v11[5].mUID + (_QWORD)v10),
          v13 = (_QWORD *)(v12 + 8i64 * v5),
          v14 = (char *)v13 + *v13,
          !*v13) )
    {
      v14 = 0i64;
    }
    mesh_proxy.mMesh = (Illusion::Mesh *)v14;
    v15 = v6->mRModel;
    if ( v15 )
    {
      v16 = (signed __int64)&v15->mMeshes.mData.mItems[v5];
      mesh_proxy.mRMesh = &v15->mMeshes.mData.mItems[v5];
    }
    else
    {
      v16 = 0i64;
      mesh_proxy.mRMesh = 0i64;
    }
    v17 = 0i64;
    v18 = v2->simple_morph_target;
    if ( v18 )
    {
      v19 = v18->mMeshOffsetTable.mOffset;
      v20 = (signed __int64)(v19 ? (UFG::qOffset64<UFG::qOffset64<Illusion::Mesh *> *> *)((char *)&v18->mMeshOffsetTable
                                                                                        + v19) : 0i64);
      v21 = (_QWORD *)(v20 + 8i64 * v5);
      if ( *v21 )
        v17 = (Illusion::Mesh *)((char *)v21 + *v21);
    }
    if ( v14 )
    {
      if ( !Illusion::IEnginePlat::IsValidDrawCall(
              (Illusion::IEnginePlat *)&Illusion::gEngine,
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
              (Illusion::IEnginePlat *)&Illusion::gEngine,
              (Illusion::rMesh *)v16,
              *(Illusion::rMaterial **)(v16 + 48),
              0i64,
              0i64) )
        return 0;
      if ( !v17 )
        goto LABEL_34;
      v22 = 0i64;
    }
    if ( !Illusion::IEnginePlat::IsValidDrawCall((Illusion::IEnginePlat *)&Illusion::gEngine, v17, v22, 0i64, 0i64) )
      return 0;
LABEL_34:
    skinning_task_decl = 0i64;
    LODWORD(task_uid) = 0;
    Render::Skinning::SelectSkinningTask(v3, &skinning_task_decl, &mesh_proxy, v17, (unsigned int *)&task_uid, v2, 1);
    v23 = skinning_task_decl;
    if ( skinning_task_decl )
    {
      if ( (_DWORD)task_uid == v2->mDecalTaskUID )
        break;
    }
    ++v5;
    v3 = v70;
  }
  v24 = (signed __int64)(v14 + 96);
  if ( !v14 )
    v24 = v16 + 120;
  skinning_task_decl = *(UFG::qTaskFunctionDeclData **)(v24 + 16);
  v25 = (signed __int64)(v14 + 128);
  if ( !v14 )
    v25 = v16 + 152;
  v26 = *(_QWORD *)(v25 + 16);
  v27 = (signed __int64)(v14 + 64);
  if ( !v14 )
    v27 = v16 + 88;
  v73 = *(char **)(v27 + 16);
  task_uid = Render::Skinning::AllocateDecalVertexBuffer(v70, v2->mDecalVertNum);
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
    v33 = *((_QWORD *)v73 + 12);
    if ( v33 )
      v34 = (__int64)&v73[v33 + 96];
    else
      v34 = 0i64;
    if ( v14 )
      v35 = *((unsigned int *)v14 + 57);
    else
      v35 = *(unsigned int *)(v16 + 252);
    *((_QWORD *)v28 + 3) = v34 + 2 * v35;
    *((_QWORD *)v28 + 12) = v2->bone_inverse_array;
    *((_QWORD *)v28 + 13) = v2->bone_remap_array;
    *((_QWORD *)v28 + 4) = v2->transform_array;
    *((_WORD *)v28 + 20) = v2->bone_matrix_count;
    *((_WORD *)v28 + 21) = 200;
    if ( v17 && (v36 = v17->mVertexBufferHandles[0].mData, (v37 = v36[1].mNode.mChild[0]) != 0i64) )
      v38 = (signed __int64)v36[1].mNode.mChild + (_QWORD)v37;
    else
      v38 = 0i64;
    *((_QWORD *)v28 + 6) = v38;
    *((_DWORD *)v28 + 14) = LODWORD(v2->simple_morph_weight);
    if ( v14 )
      v39 = *((_DWORD *)v14 + 58);
    else
      v39 = *(_DWORD *)(v16 + 256);
    *((_DWORD *)v28 + 15) = 3 * v39;
    *((_DWORD *)v28 + 16) = *(&v30->mRequestedSPUEnabled + 10);
    *((_QWORD *)v28 + 9) = v2->user_data_0;
    *((_QWORD *)v28 + 10) = v2->user_data_1;
    *((_QWORD *)v28 + 14) = 0i64;
    *((_QWORD *)v28 + 17) = 0i64;
    *((_QWORD *)v28 + 15) = v2->mDecalVerts;
    *((_DWORD *)v28 + 32) = v2->mDecalVertNum;
    v40 = v70->mTaskGroup;
    v41 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
    v42 = (UFG::qTask *)v41;
    skinning_task_decl = (UFG::qTaskFunctionDeclData *)v41;
    v73 = v41;
    if ( v40 )
    {
      if ( v41 )
      {
        *(_QWORD *)v41 = v41;
        *((_QWORD *)v41 + 1) = v41;
        v43 = v41 + 16;
        *v43 = v43;
        v43[1] = v43;
        v44 = v23->mSpuElf;
        v45 = v23->mTaskFunctionSPU;
        v46 = v23->mTaskFunctionPPU;
        v47 = v23->mTaskFunctionOffload;
        if ( !v23->mCurrentSPUEnabled )
        {
          v44 = 0i64;
          v45 = 0i64;
          v47 = 0i64;
        }
        v42->mTaskGroup = v40;
        v42->mFlags = 2;
        v42->mSyncVars.i64 = 0i64;
        v42->mSyncVars.v.mDependents = 0i64;
        v42->mFunctionDeclData = v23;
        if ( v44 )
          v48 = v44->mAddress;
        else
          v48 = 0i64;
        v42->mSPUElfAddress = v48;
        v42->mSPUFunction = v45;
        v42->mPPUFunction = v46;
        v42->mParam0 = v28;
        v42->mParam1 = 0i64;
        v42->mParam2 = 0i64;
        v42->mParam3 = 0i64;
        if ( v47 )
        {
          v42->mFlags = 130;
          v42->mOffloadThread = 0;
        }
      }
      v49 = v40->mTasks.mNode.mPrev;
      v49->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v42->mPrev;
      v42->mPrev = v49;
      v42->mNext = &v40->mTasks.mNode;
      v40->mTasks.mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v42->mPrev;
      ++v40->mNumTasks;
    }
    else
    {
      if ( v41 )
      {
        *(_QWORD *)v41 = v41;
        *((_QWORD *)v41 + 1) = v41;
        v50 = v41 + 16;
        *v50 = v50;
        v50[1] = v50;
        v51 = v23->mSpuElf;
        v52 = v23->mTaskFunctionSPU;
        v53 = v23->mTaskFunctionPPU;
        v54 = v23->mTaskFunctionOffload;
        if ( !v23->mCurrentSPUEnabled )
        {
          v51 = 0i64;
          v52 = 0i64;
          v54 = 0i64;
        }
        v42->mTaskGroup = 0i64;
        v42->mFlags = 2;
        v42->mSyncVars.i64 = 0i64;
        v42->mSyncVars.v.mDependents = 0i64;
        v42->mFunctionDeclData = v23;
        if ( v51 )
          v55 = v51->mAddress;
        else
          v55 = 0i64;
        v42->mSPUElfAddress = v55;
        v42->mSPUFunction = v52;
        v42->mPPUFunction = v53;
        v42->mParam0 = v28;
        v42->mParam1 = 0i64;
        v42->mParam2 = 0i64;
        v42->mParam3 = 0i64;
        if ( v54 )
        {
          v42->mFlags = 130;
          v42->mOffloadThread = 0;
        }
      }
      v56 = UFG::gTaskManager.mSingleFrameTasks;
      v57 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
      v57->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v42->mPrev;
      v42->mPrev = v57;
      v42->mNext = &v56->mNode;
      v56->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v42->mPrev;
      UFG::qTaskManager::Queue(&UFG::gTaskManager, v42);
    }
    v58 = Illusion::Primitive::Create("SkinningDecal");
    v59 = task_uid;
    v60 = task_uid->mData.mOffset;
    if ( v60 )
      v61 = (char *)&task_uid->mData + v60;
    else
      v61 = 0i64;
    Illusion::Primitive::SetBuffers(
      v58,
      TRIANGLELIST,
      v61,
      v2->mDecalVertNum,
      (Illusion::VertexDecl *)v70->mDecalVertexDecl.mData,
      0i64,
      0,
      0);
    v62 = Render::View::GetStateArgs(v2->view);
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mCallback = 0i64;
    arg.mStateParamIndex = Render::cbSkinnedVertexStreamState::sStateParamIndex;
    *(_WORD *)&arg.mFlags = 2;
    if ( (_WORD)Render::cbSkinnedVertexStreamState::sStateParamIndex == -1 )
    {
      v63 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "iVertexBuffer0");
      Render::cbSkinnedVertexStreamState::sStateParamIndex = v63;
      arg.mStateParamIndex = v63;
    }
    arg.mVertexStreamBuffer = v59;
    Illusion::StateArgs::Set<Render::cbSkinnedVertexStreamState>(v62, &arg);
    v70->mRenderDecalFunc(v2->view, v58, v2->mDecalMaterial, v2->local_transform);
    v64 = arg.mPrev;
    v65 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v65->mPrev = v64;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v62->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v62 + 16 * (arg.mStateParamIndex + 3i64)) )
      v62->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v66 = arg.mPrev;
    v67 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v67->mPrev = v66;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    return 1;
  }
  return 0;
}

