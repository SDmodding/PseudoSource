// File Line: 31
// RVA: 0x436780
void __fastcall UFG::MeshResourceLoader::MeshResourceLoader(UFG::MeshResourceLoader *this)
{
  signed int v1; // edx
  UFG::qColour **v2; // rax

  *(_WORD *)&this->mHighDefinition = 0;
  this->mResourceCount = 0;
  this->mRequestsLoadedFlags.mBits[0] = 0i64;
  this->mRequestsDispatchEventFlags.mBits[0] = 0i64;
  v1 = 15;
  this->mActivePriority = UFG::gNullQSymbol;
  this->mPropertySet = 0i64;
  v2 = &this->mTrueCrowdInstance.mPart[0].mColourTint;
  do
  {
    --v1;
    *(v2 - 1) = 0i64;
    *v2 = 0i64;
    v2 += 2;
  }
  while ( v1 >= 0 );
  this->mTrueCrowdInstance.mSet = 0i64;
  this->mTrueCrowdInstance.mNumParts = 0;
  this->mOnLoadEventCallback = 0i64;
  this->mOnForceRemovedCallback = 0i64;
  this->mUserContext = 0i64;
}

// File Line: 35
// RVA: 0x437C10
void __fastcall UFG::MeshResourceLoader::~MeshResourceLoader(UFG::MeshResourceLoader *this)
{
  UFG::MeshResourceLoader::Unload(this);
}

// File Line: 40
// RVA: 0x43DFD0
void __fastcall UFG::MeshResourceLoader::Init(UFG::MeshResourceLoader *this, UFG::qPropertySet *propertySet, __int64 priority, bool highDef)
{
  this->mPropertySet = propertySet;
  this->mActivePriority.mUID = *(_DWORD *)priority;
  this->mHighDefinition = highDef;
  this->mTrueCrowdInstance.mSet = 0i64;
  this->mTrueCrowdInstance.mNumParts = 0;
}

// File Line: 48
// RVA: 0x43F240
char __fastcall UFG::MeshResourceLoader::IsLoaded(UFG::MeshResourceLoader *this)
{
  UFG::MeshResourceLoader *v1; // rdx
  unsigned int v2; // er8
  unsigned int v4; // ecx
  signed __int64 v5; // rdx

  v1 = this;
  if ( this->mPropertySet )
  {
    v2 = this->mResourceCount;
    if ( !v2 )
      return 0;
    v4 = 0;
    if ( v2 )
    {
      v5 = (signed __int64)v1->mResourceRequests;
      while ( *(_DWORD *)(*(_QWORD *)v5 + 20i64) == 3 )
      {
        ++v4;
        v5 += 8i64;
        if ( v4 >= v2 )
          return 1;
      }
      return 0;
    }
  }
  return 1;
}

// File Line: 87
// RVA: 0x43FBB0
void __fastcall UFG::MeshResourceLoader::PopulateTrueCrowdInstanceFromPropertySet(UFG::MeshResourceLoader *this, bool forceSelection)
{
  JUMPOUT(forceSelection != 0, UFG::TrueCrowdDataBase::QueryInstance);
  UFG::TrueCrowdDataBase::QueryPreloadedInstance(
    UFG::TrueCrowdDataBase::sTrueCrowdDataBase,
    this->mPropertySet,
    &this->mTrueCrowdInstance);
}

// File Line: 100
// RVA: 0x440EE0
void __fastcall UFG::MeshResourceLoader::QueueLoad(UFG::MeshResourceLoader *this)
{
  UFG::MeshResourceLoader *v1; // rbx
  __int64 v2; // rsi
  __int64 v3; // rcx
  UFG::TrueCrowdResource *v4; // rdx
  __int64 v5; // rax
  signed __int64 v6; // rax
  __int64 v7; // rcx
  UFG::TrueCrowdModel *v8; // rdx
  __int64 v9; // rax
  signed __int64 v10; // rcx
  __int64 v11; // rax
  signed __int64 v12; // rdx
  __int64 v13; // rax
  UFG::TrueCrowdResource *v14; // rdx
  __int64 v15; // rax
  signed __int64 v16; // rax
  UFG::TrueCrowdSet *v17; // rax

  v1 = this;
  if ( this->mTrueCrowdInstance.mSet )
  {
    v2 = 0i64;
    if ( this->mTrueCrowdInstance.mNumParts )
    {
      do
      {
        v3 = *((unsigned int *)&v1->mHighDefinition + 4 * (v2 + 13));
        if ( (_DWORD)v3 != -1 )
        {
          v4 = (UFG::TrueCrowdResource *)&v1->mTrueCrowdInstance.mSet->mFiles[(unsigned int)v2].p[v3]->mName;
          if ( v1->mHighDefinition )
          {
            v5 = v4->mHighResolutionResource.mOffset;
            if ( v5 )
            {
              v6 = (signed __int64)&v4->mHighResolutionResource + v5;
              if ( v6 )
                v4 = (UFG::TrueCrowdResource *)v6;
            }
          }
          UFG::MeshResourceLoader::AddResource(v1, v4, 0);
          v7 = *((unsigned int *)&v1->mHighDefinition + 4 * (v2 + 13));
          if ( (_DWORD)v7 != -1 )
          {
            v8 = v1->mTrueCrowdInstance.mSet->mFiles[(unsigned int)v2].p[v7];
            if ( v8->mNumTextureSets )
            {
              v9 = v8->mTextureSets.mOffset;
              if ( v9 )
                v10 = (signed __int64)&v8->mTextureSets + v9;
              else
                v10 = 0i64;
              v11 = v1->mTrueCrowdInstance.mPart[(unsigned int)v2].mTextureSetIndex;
              v12 = v10 + 8 * v11;
              v13 = *(_QWORD *)(v10 + 8 * v11);
              if ( v13 )
                v14 = (UFG::TrueCrowdResource *)(v13 + v12);
              else
                v14 = 0i64;
              if ( v1->mHighDefinition )
              {
                v15 = v14->mHighResolutionResource.mOffset;
                if ( v15 )
                {
                  v16 = (signed __int64)&v14->mHighResolutionResource + v15;
                  if ( v16 )
                    v14 = (UFG::TrueCrowdResource *)v16;
                }
              }
              if ( v14 )
                UFG::MeshResourceLoader::AddResource(v1, v14, 1);
            }
          }
        }
        v2 = (unsigned int)(v2 + 1);
      }
      while ( (unsigned int)v2 < v1->mTrueCrowdInstance.mNumParts );
    }
    v17 = v1->mTrueCrowdInstance.mSet;
    if ( v17 )
      ++v17->mCurrentInstances;
  }
}

// File Line: 129
// RVA: 0x4444D0
void __fastcall UFG::MeshResourceLoader::Unload(UFG::MeshResourceLoader *this)
{
  UFG::MeshResourceLoader *v1; // rbx
  unsigned int v2; // eax
  unsigned int v3; // esi
  UFG::ResourceRequest *v4; // rdi
  void (__fastcall *v5)(void *, UFG::ResourceRequest *, bool); // rax
  UFG::TrueCrowdResource *v6; // rdx
  UFG::ObjectResourceManager *v7; // rdi
  UFG::ResourceRequest *v8; // r9
  UFG::ObjectResourceManager *v9; // rax
  unsigned int v10; // edx
  UFG::PriorityBucket::Type v11; // edx
  UFG::TrueCrowdSet *v12; // rax
  UFG::ResourceUser dependency; // [rsp+28h] [rbp-40h]
  unsigned int v14; // [rsp+70h] [rbp+8h]
  unsigned int v15; // [rsp+78h] [rbp+10h]
  int *v16; // [rsp+80h] [rbp+18h]
  int *v17; // [rsp+88h] [rbp+20h]

  v1 = this;
  v2 = this->mResourceCount;
  if ( v2 )
  {
    v3 = 0;
    if ( v2 )
    {
      v16 = (int *)&v14;
      v17 = (int *)&v15;
      do
      {
        v4 = v1->mResourceRequests[v3];
        v5 = v1->mOnLoadEventCallback;
        if ( v5 )
          v5(v1->mUserContext, v1->mResourceRequests[v3], 0);
        v14 = v1->mActivePriority.mUID;
        dependency.mMeshLoader = v1;
        dependency.mType = 0;
        v6 = v4->mResource;
        v7 = UFG::ObjectResourceManager::sInstance;
        v15 = v14;
        v8 = 0i64;
        v9 = (UFG::ObjectResourceManager *)UFG::ObjectResourceManager::sInstance->mPool.mRequestList.mNode.mNext;
        if ( v9 != (UFG::ObjectResourceManager *)&UFG::ObjectResourceManager::sInstance->mPool.mRequestList )
        {
          v10 = v6->mPathSymbol.mUID;
          while ( v9->mPool.mLoading.size != v10 )
          {
            v9 = (UFG::ObjectResourceManager *)v9->mPool.mQueued.p;
            if ( v9 == (UFG::ObjectResourceManager *)&UFG::ObjectResourceManager::sInstance->mPool.mRequestList )
              goto LABEL_12;
          }
          v8 = (UFG::ResourceRequest *)v9;
        }
LABEL_12:
        if ( v15 == qSymbol_Critical.mUID )
        {
          v11 = 2;
        }
        else if ( v15 == qSymbol_High.mUID )
        {
          v11 = 3;
        }
        else if ( v15 == qSymbol_Medium.mUID || v15 == qSymbol_Low.mUID )
        {
          v11 = 4;
        }
        else
        {
          v11 = 4;
          if ( v15 == qSymbol_Reserved.mUID )
            v11 = 1;
        }
        UFG::ResourceRequest::RemoveDependency(v8, v11, &dependency);
        v7->mPool.mDirty = 1;
        ++v3;
      }
      while ( v3 < v1->mResourceCount );
    }
    v1->mRequestsLoadedFlags.mBits[0] = 0i64;
    v1->mRequestsDispatchEventFlags.mBits[0] = 0i64;
    v1->mResourceCount = 0;
    v12 = v1->mTrueCrowdInstance.mSet;
    if ( v12 )
      --v12->mCurrentInstances;
  }
}

// File Line: 151
// RVA: 0x43FE10
void __fastcall UFG::MeshResourceLoader::PropagateResourceEvents(UFG::MeshResourceLoader *this, __int64 a2, _BOOL8 a3)
{
  UFG::MeshResourceLoader *v3; // rbx
  __int64 v4; // rdi
  signed __int64 v5; // rax
  signed __int64 v6; // rdx
  void (__fastcall *v7)(void *, UFG::ResourceRequest *, bool); // r9

  v3 = this;
  if ( this->mResourcesDirty )
  {
    v4 = 0i64;
    if ( this->mResourceCount )
    {
      do
      {
        v5 = (signed __int64)(signed int)v4 >> 6;
        v6 = 1i64 << (v4 & 0x3F);
        if ( v6 & v3->mRequestsDispatchEventFlags.mBits[v5] )
        {
          v7 = v3->mOnLoadEventCallback;
          if ( v7 )
          {
            LOBYTE(a3) = (v6 & v3->mRequestsLoadedFlags.mBits[v5]) != 0;
            v7(v3->mUserContext, v3->mResourceRequests[v4], a3);
          }
        }
        v4 = (unsigned int)(v4 + 1);
      }
      while ( (unsigned int)v4 < v3->mResourceCount );
    }
    v3->mRequestsDispatchEventFlags.mBits[0] = 0i64;
    v3->mResourcesDirty = 0;
  }
}

// File Line: 187
// RVA: 0x4387B0
void __fastcall UFG::MeshResourceLoader::AddResource(UFG::MeshResourceLoader *this, UFG::TrueCrowdResource *resource, bool isTexture)
{
  UFG::MeshResourceLoader *v3; // rdi
  __int64 v4; // rbx
  UFG::ResourceRequest *v5; // rax
  UFG::ResourceRequest *v6; // rdx
  __int64 v7; // rax
  signed __int64 v8; // r8
  signed __int64 v9; // rax
  signed __int64 v10; // rdx
  __int64 v11; // rcx
  int v12; // [rsp+40h] [rbp-18h]
  UFG::MeshResourceLoader *v13; // [rsp+48h] [rbp-10h]
  unsigned int v14; // [rsp+60h] [rbp+8h]
  unsigned int *v15; // [rsp+78h] [rbp+20h]

  v3 = this;
  v15 = &v14;
  v14 = this->mActivePriority.mUID;
  v13 = this;
  v4 = 0i64;
  v12 = 0;
  LODWORD(v15) = v14;
  v5 = UFG::ResourcePool::RequestLoadResource(
         &UFG::ObjectResourceManager::sInstance->mPool,
         resource,
         isTexture,
         (__int64)&v15,
         (UFG::ResourceUser *)&v12);
  v6 = v5;
  if ( v5->mLoadStatus == 3 )
  {
    v7 = v3->mResourceCount;
    if ( (_DWORD)v7 )
    {
      while ( v3->mResourceRequests[v4] != v6 )
      {
        v4 = (unsigned int)(v4 + 1);
        if ( (unsigned int)v4 >= (unsigned int)v7 )
          goto LABEL_7;
      }
      v8 = 1i64 << (v4 & 0x3F);
      v9 = (signed __int64)(signed int)v4 >> 6;
      v3->mRequestsLoadedFlags.mBits[v9] |= v8;
      v3->mRequestsDispatchEventFlags.mBits[v9] |= v8;
      v3->mResourcesDirty = 1;
      return;
    }
LABEL_7:
    v3->mResourceRequests[v7] = v6;
    v10 = (signed __int64)v3 + 8 * ((signed __int64)(signed int)v3->mResourceCount >> 6);
    *(_QWORD *)(v10 + 152) |= 1i64 << (v3->mResourceCount & 0x3F);
    v3->mRequestsDispatchEventFlags.mBits[(signed __int64)(signed int)v3->mResourceCount >> 6] |= 1i64 << (v3->mResourceCount & 0x3F);
    v3->mResourcesDirty = 1;
LABEL_14:
    ++v3->mResourceCount;
    return;
  }
  v11 = v3->mResourceCount;
  if ( !(_DWORD)v11 )
  {
LABEL_13:
    v3->mResourceRequests[v11] = v5;
    v3->mRequestsLoadedFlags.mBits[(signed __int64)(signed int)v3->mResourceCount >> 6] &= ~(1i64 << (v3->mResourceCount & 0x3F));
    goto LABEL_14;
  }
  while ( v3->mResourceRequests[v4] != v5 )
  {
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= (unsigned int)v11 )
      goto LABEL_13;
  }
  v3->mRequestsLoadedFlags.mBits[(signed __int64)(signed int)v4 >> 6] &= ~(1i64 << (v4 & 0x3F));
}

// File Line: 299
// RVA: 0x43DEE0
UFG::TrueCrowdTextureSet *__fastcall UFG::MeshResourceLoader::GetTexture(UFG::MeshResourceLoader *this, unsigned int partIndex)
{
  UFG::MeshResourceLoader *v2; // r8
  __int64 v3; // rcx
  signed __int64 v5; // r9
  signed __int64 v6; // rdx
  UFG::TrueCrowdModel *v7; // r10
  __int64 v8; // rax
  signed __int64 v9; // rcx
  __int64 v10; // rax
  signed __int64 v11; // r9
  __int64 v12; // rax
  __int64 v13; // rax

  v2 = this;
  v3 = *((unsigned int *)&this->mHighDefinition + 4 * (partIndex + 13i64));
  if ( (_DWORD)v3 == -1 )
    return 0i64;
  v5 = partIndex;
  v6 = 0i64;
  v7 = v2->mTrueCrowdInstance.mSet->mFiles[v5].p[v3];
  if ( v7->mNumTextureSets )
  {
    v8 = v7->mTextureSets.mOffset;
    if ( v8 )
      v9 = (signed __int64)&v7->mTextureSets + v8;
    else
      v9 = 0i64;
    v10 = v2->mTrueCrowdInstance.mPart[v5].mTextureSetIndex;
    v11 = v9 + 8 * v10;
    v12 = *(_QWORD *)(v9 + 8 * v10);
    if ( v12 )
      v6 = v12 + v11;
    if ( v2->mHighDefinition )
    {
      v13 = *(_QWORD *)(v6 + 48);
      if ( v13 )
      {
        if ( v13 + v6 + 48 )
          v6 += v13 + 48;
      }
    }
  }
  return (UFG::TrueCrowdTextureSet *)v6;
}

