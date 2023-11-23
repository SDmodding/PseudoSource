// File Line: 31
// RVA: 0x436780
void __fastcall UFG::MeshResourceLoader::MeshResourceLoader(UFG::MeshResourceLoader *this)
{
  int v1; // edx
  UFG::qColour **p_mColourTint; // rax

  *(_WORD *)&this->mHighDefinition = 0;
  this->mResourceCount = 0;
  this->mRequestsLoadedFlags.mBits[0] = 0i64;
  this->mRequestsDispatchEventFlags.mBits[0] = 0i64;
  v1 = 15;
  this->mActivePriority = UFG::gNullQSymbol;
  this->mPropertySet = 0i64;
  p_mColourTint = &this->mTrueCrowdInstance.mPart[0].mColourTint;
  do
  {
    --v1;
    *(p_mColourTint - 1) = 0i64;
    *p_mColourTint = 0i64;
    p_mColourTint += 2;
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
// attributes: thunk
void __fastcall UFG::MeshResourceLoader::~MeshResourceLoader(UFG::MeshResourceLoader *this)
{
  UFG::MeshResourceLoader::Unload(this);
}

// File Line: 40
// RVA: 0x43DFD0
void __fastcall UFG::MeshResourceLoader::Init(
        UFG::MeshResourceLoader *this,
        UFG::qPropertySet *propertySet,
        unsigned int *priority,
        bool highDef)
{
  this->mPropertySet = propertySet;
  this->mActivePriority.mUID = *priority;
  this->mHighDefinition = highDef;
  this->mTrueCrowdInstance.mSet = 0i64;
  this->mTrueCrowdInstance.mNumParts = 0;
}

// File Line: 48
// RVA: 0x43F240
char __fastcall UFG::MeshResourceLoader::IsLoaded(UFG::MeshResourceLoader *this)
{
  unsigned int mResourceCount; // r8d
  int v4; // ecx
  UFG::ResourceRequest **i; // rdx

  if ( !this->mPropertySet )
    return 1;
  mResourceCount = this->mResourceCount;
  if ( mResourceCount )
  {
    v4 = 0;
    for ( i = this->mResourceRequests; (*i)->mLoadStatus == Loaded; ++i )
    {
      if ( ++v4 >= mResourceCount )
        return 1;
    }
  }
  return 0;
}

// File Line: 87
// RVA: 0x43FBB0
void __fastcall UFG::MeshResourceLoader::PopulateTrueCrowdInstanceFromPropertySet(
        UFG::MeshResourceLoader *this,
        bool forceSelection)
{
  bool v2; // zf
  UFG::qPropertySet *mPropertySet; // rdx
  UFG::TrueCrowdSet::Instance *p_mTrueCrowdInstance; // r8

  v2 = !forceSelection;
  mPropertySet = this->mPropertySet;
  p_mTrueCrowdInstance = &this->mTrueCrowdInstance;
  if ( v2 )
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

// File Line: 100
// RVA: 0x440EE0
void __fastcall UFG::MeshResourceLoader::QueueLoad(UFG::MeshResourceLoader *this)
{
  __int64 i; // rsi
  __int64 mModelIndex; // rcx
  UFG::TrueCrowdModel *v4; // rdx
  __int64 mOffset; // rax
  UFG::TrueCrowdModel *v6; // rax
  __int64 v7; // rcx
  UFG::TrueCrowdModel *v8; // rdx
  __int64 v9; // rax
  char *v10; // rcx
  char *v11; // rdx
  UFG::TrueCrowdResource *v12; // rdx
  __int64 v13; // rax
  UFG::TrueCrowdResource *v14; // rax
  UFG::TrueCrowdSet *mSet; // rax

  if ( this->mTrueCrowdInstance.mSet )
  {
    for ( i = 0i64; (unsigned int)i < this->mTrueCrowdInstance.mNumParts; i = (unsigned int)(i + 1) )
    {
      mModelIndex = this->mTrueCrowdInstance.mPart[i].mModelIndex;
      if ( (_DWORD)mModelIndex != -1 )
      {
        v4 = this->mTrueCrowdInstance.mSet->mFiles[(unsigned int)i].p[mModelIndex];
        if ( this->mHighDefinition )
        {
          mOffset = v4->mHighResolutionResource.mOffset;
          if ( mOffset )
          {
            v6 = (UFG::TrueCrowdModel *)((char *)&v4->mHighResolutionResource + mOffset);
            if ( v6 )
              v4 = v6;
          }
        }
        UFG::MeshResourceLoader::AddResource(this, v4, 0);
        v7 = this->mTrueCrowdInstance.mPart[i].mModelIndex;
        if ( (_DWORD)v7 != -1 )
        {
          v8 = this->mTrueCrowdInstance.mSet->mFiles[(unsigned int)i].p[v7];
          if ( v8->mNumTextureSets )
          {
            v9 = v8->mTextureSets.mOffset;
            if ( v9 )
              v10 = (char *)&v8->mTextureSets + v9;
            else
              v10 = 0i64;
            v11 = &v10[8 * this->mTrueCrowdInstance.mPart[(unsigned int)i].mTextureSetIndex];
            if ( *(_QWORD *)v11 )
              v12 = (UFG::TrueCrowdResource *)&v11[*(_QWORD *)v11];
            else
              v12 = 0i64;
            if ( this->mHighDefinition )
            {
              v13 = v12->mHighResolutionResource.mOffset;
              if ( v13 )
              {
                v14 = (UFG::TrueCrowdResource *)((char *)&v12->mHighResolutionResource + v13);
                if ( v14 )
                  v12 = v14;
              }
            }
            if ( v12 )
              UFG::MeshResourceLoader::AddResource(this, v12, 1);
          }
        }
      }
    }
    mSet = this->mTrueCrowdInstance.mSet;
    if ( mSet )
      ++mSet->mCurrentInstances;
  }
}

// File Line: 129
// RVA: 0x4444D0
void __fastcall UFG::MeshResourceLoader::Unload(UFG::MeshResourceLoader *this)
{
  unsigned int v2; // esi
  UFG::ResourceRequest *v3; // rdi
  void (__fastcall *mOnLoadEventCallback)(void *, UFG::ResourceRequest *, bool); // rax
  UFG::TrueCrowdResource *mResource; // rdx
  UFG::ObjectResourceManager *v6; // rdi
  UFG::ResourceRequest *v7; // r9
  UFG::ObjectResourceManager *mNext; // rax
  unsigned int v9; // edx
  UFG::PriorityBucket::Type v10; // edx
  UFG::TrueCrowdSet *mSet; // rax
  UFG::ResourceUser dependency; // [rsp+28h] [rbp-40h] BYREF
  unsigned int mUID; // [rsp+70h] [rbp+8h] BYREF
  unsigned int v14; // [rsp+78h] [rbp+10h] BYREF
  unsigned int *v15; // [rsp+80h] [rbp+18h]
  int *v16; // [rsp+88h] [rbp+20h]

  if ( this->mResourceCount )
  {
    v2 = 0;
    v15 = &mUID;
    v16 = (int *)&v14;
    do
    {
      v3 = this->mResourceRequests[v2];
      mOnLoadEventCallback = this->mOnLoadEventCallback;
      if ( mOnLoadEventCallback )
        mOnLoadEventCallback(this->mUserContext, this->mResourceRequests[v2], 0);
      mUID = this->mActivePriority.mUID;
      dependency.mMeshLoader = this;
      dependency.mType = MeshLoader;
      mResource = v3->mResource;
      v6 = UFG::ObjectResourceManager::sInstance;
      v14 = mUID;
      v7 = 0i64;
      mNext = (UFG::ObjectResourceManager *)UFG::ObjectResourceManager::sInstance->mPool.mRequestList.mNode.mNext;
      if ( mNext != (UFG::ObjectResourceManager *)&UFG::ObjectResourceManager::sInstance->mPool.mRequestList )
      {
        v9 = mResource->mPathSymbol.mUID;
        while ( mNext->mPool.mLoading.size != v9 )
        {
          mNext = (UFG::ObjectResourceManager *)mNext->mPool.mQueued.p;
          if ( mNext == (UFG::ObjectResourceManager *)&UFG::ObjectResourceManager::sInstance->mPool.mRequestList )
            goto LABEL_12;
        }
        v7 = (UFG::ResourceRequest *)mNext;
      }
LABEL_12:
      if ( v14 == qSymbol_Critical.mUID )
      {
        v10 = Critical;
      }
      else if ( v14 == qSymbol_High.mUID )
      {
        v10 = High;
      }
      else if ( v14 == qSymbol_Medium.mUID || v14 == qSymbol_Low.mUID )
      {
        v10 = Low;
      }
      else
      {
        v10 = Low;
        if ( v14 == qSymbol_Reserved.mUID )
          v10 = Reserved;
      }
      UFG::ResourceRequest::RemoveDependency(v7, v10, &dependency);
      v6->mPool.mDirty = 1;
      ++v2;
    }
    while ( v2 < this->mResourceCount );
    this->mRequestsLoadedFlags.mBits[0] = 0i64;
    this->mRequestsDispatchEventFlags.mBits[0] = 0i64;
    this->mResourceCount = 0;
    mSet = this->mTrueCrowdInstance.mSet;
    if ( mSet )
      --mSet->mCurrentInstances;
  }
}

// File Line: 151
// RVA: 0x43FE10
void __fastcall UFG::MeshResourceLoader::PropagateResourceEvents(UFG::MeshResourceLoader *this, __int64 a2, _BOOL8 a3)
{
  __int64 i; // rdi
  __int64 v5; // rax
  __int64 v6; // rdx
  void (__fastcall *mOnLoadEventCallback)(void *, UFG::ResourceRequest *, bool); // r9

  if ( this->mResourcesDirty )
  {
    for ( i = 0i64; (unsigned int)i < this->mResourceCount; i = (unsigned int)(i + 1) )
    {
      v5 = (__int64)(int)i >> 6;
      v6 = 1i64 << (i & 0x3F);
      if ( (v6 & this->mRequestsDispatchEventFlags.mBits[v5]) != 0 )
      {
        mOnLoadEventCallback = this->mOnLoadEventCallback;
        if ( mOnLoadEventCallback )
        {
          LOBYTE(a3) = (v6 & this->mRequestsLoadedFlags.mBits[v5]) != 0;
          mOnLoadEventCallback(this->mUserContext, this->mResourceRequests[i], a3);
        }
      }
    }
    this->mRequestsDispatchEventFlags.mBits[0] = 0i64;
    this->mResourcesDirty = 0;
  }
}

// File Line: 187
// RVA: 0x4387B0
void __fastcall UFG::MeshResourceLoader::AddResource(
        UFG::MeshResourceLoader *this,
        UFG::TrueCrowdResource *resource,
        bool isTexture)
{
  __int64 v4; // rbx
  UFG::ResourceRequest *v5; // rax
  UFG::ResourceRequest *v6; // rdx
  __int64 mResourceCount; // rax
  __int64 v8; // r8
  __int64 v9; // rax
  bool *v10; // rdx
  __int64 v11; // rcx
  UFG::ResourceUser v12; // [rsp+40h] [rbp-18h] BYREF
  unsigned int mUID; // [rsp+60h] [rbp+8h] BYREF
  unsigned int *v14; // [rsp+78h] [rbp+20h] BYREF

  v14 = &mUID;
  mUID = this->mActivePriority.mUID;
  v12.mMeshLoader = this;
  v4 = 0i64;
  v12.mType = MeshLoader;
  LODWORD(v14) = mUID;
  v5 = UFG::ResourcePool::RequestLoadResource(
         &UFG::ObjectResourceManager::sInstance->mPool,
         resource,
         isTexture,
         (__int64)&v14,
         &v12);
  v6 = v5;
  if ( v5->mLoadStatus == Loaded )
  {
    mResourceCount = this->mResourceCount;
    if ( (_DWORD)mResourceCount )
    {
      while ( this->mResourceRequests[v4] != v6 )
      {
        v4 = (unsigned int)(v4 + 1);
        if ( (unsigned int)v4 >= (unsigned int)mResourceCount )
          goto LABEL_7;
      }
      v8 = 1i64 << (v4 & 0x3F);
      v9 = (__int64)(int)v4 >> 6;
      this->mRequestsLoadedFlags.mBits[v9] |= v8;
      this->mRequestsDispatchEventFlags.mBits[v9] |= v8;
      this->mResourcesDirty = 1;
      return;
    }
LABEL_7:
    this->mResourceRequests[mResourceCount] = v6;
    v10 = &this->mHighDefinition + 8 * ((__int64)(int)this->mResourceCount >> 6);
    *((_QWORD *)v10 + 19) |= 1i64 << (this->mResourceCount & 0x3F);
    this->mRequestsDispatchEventFlags.mBits[(__int64)(int)this->mResourceCount >> 6] |= 1i64 << (this->mResourceCount & 0x3F);
    this->mResourcesDirty = 1;
LABEL_14:
    ++this->mResourceCount;
    return;
  }
  v11 = this->mResourceCount;
  if ( !(_DWORD)v11 )
  {
LABEL_13:
    this->mResourceRequests[v11] = v5;
    this->mRequestsLoadedFlags.mBits[(__int64)(int)this->mResourceCount >> 6] &= ~(1i64 << (this->mResourceCount & 0x3F));
    goto LABEL_14;
  }
  while ( this->mResourceRequests[v4] != v5 )
  {
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= (unsigned int)v11 )
      goto LABEL_13;
  }
  this->mRequestsLoadedFlags.mBits[(__int64)(int)v4 >> 6] &= ~(1i64 << (v4 & 0x3F));
}

// File Line: 299
// RVA: 0x43DEE0
UFG::TrueCrowdTextureSet *__fastcall UFG::MeshResourceLoader::GetTexture(
        UFG::MeshResourceLoader *this,
        unsigned int partIndex)
{
  __int64 mModelIndex; // rcx
  __int64 v5; // r9
  char *v6; // rdx
  UFG::TrueCrowdModel *v7; // r10
  __int64 mOffset; // rax
  char *v9; // rcx
  char *v10; // r9
  __int64 v11; // rax

  mModelIndex = this->mTrueCrowdInstance.mPart[partIndex].mModelIndex;
  if ( (_DWORD)mModelIndex == -1 )
    return 0i64;
  v5 = partIndex;
  v6 = 0i64;
  v7 = this->mTrueCrowdInstance.mSet->mFiles[v5].p[mModelIndex];
  if ( v7->mNumTextureSets )
  {
    mOffset = v7->mTextureSets.mOffset;
    if ( mOffset )
      v9 = (char *)&v7->mTextureSets + mOffset;
    else
      v9 = 0i64;
    v10 = &v9[8 * this->mTrueCrowdInstance.mPart[v5].mTextureSetIndex];
    if ( *(_QWORD *)v10 )
      v6 = &v10[*(_QWORD *)v10];
    if ( this->mHighDefinition )
    {
      v11 = *((_QWORD *)v6 + 6);
      if ( v11 )
      {
        if ( &v6[v11 + 48] )
          v6 += v11 + 48;
      }
    }
  }
  return (UFG::TrueCrowdTextureSet *)v6;
}

