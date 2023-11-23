// File Line: 57
// RVA: 0x437290
void __fastcall UFG::ResourceRequest::ResourceRequest(UFG::ResourceRequest *this)
{
  unsigned int v2; // ebx
  unsigned __int64 v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::MeshResourceLoader **v5; // rsi

  this->mPrev = this;
  this->mNext = this;
  this->mAssetSymbol.mUID = -1;
  v2 = 0;
  *(_QWORD *)&this->mLoadStatus = 0i64;
  this->mResource = 0i64;
  this->mInstances.p = 0i64;
  *(_QWORD *)&this->mInstances.size = 0i64;
  this->mPreloads.p = 0i64;
  *(_QWORD *)&this->mPreloads.size = 0i64;
  this->mProxies.p = 0i64;
  *(_QWORD *)&this->mProxies.size = 0i64;
  this->mModelNames = 0i64;
  this->mNumModels = 0;
  this->mLastReferencedFrame = 0;
  this->mDataStreamerHandle.mPrev = &this->mDataStreamerHandle;
  this->mDataStreamerHandle.mNext = &this->mDataStreamerHandle;
  this->mDataStreamerHandle.mCallback = 0i64;
  this->mDataStreamerHandle.mCallbackParam = 0i64;
  this->mDataStreamerHandle.mImpl = 0i64;
  *(_DWORD *)&this->mDataStreamerHandle.mFlags = 536870915;
  this->mDataStreamerHandle._mTargetState.mValue = 1;
  this->mAssetName[0] = 0;
  if ( this->mInstances.capacity < 0x40 && this->mInstances.size != 64 )
  {
    v3 = 512i64;
    if ( !is_mul_ok(0x40ui64, 8ui64) )
      v3 = -1i64;
    v4 = UFG::qMalloc(v3, "ResourceRequest::mInstances", 0i64);
    v5 = (UFG::MeshResourceLoader **)v4;
    if ( this->mInstances.p )
    {
      if ( this->mInstances.size )
      {
        do
        {
          v4[v2] = (UFG::allocator::free_link)this->mInstances.p[v2];
          ++v2;
        }
        while ( v2 < this->mInstances.size );
      }
      operator delete[](this->mInstances.p);
    }
    this->mInstances.p = v5;
    this->mInstances.capacity = 64;
  }
  UFG::qMemSet(this->mPriorityRefCounts, 0, 0x14u);
}

// File Line: 64
// RVA: 0x437F30
void __fastcall UFG::ResourceRequest::~ResourceRequest(UFG::ResourceRequest *this)
{
  UFG::qSymbolUC *mModelNames; // rcx
  UFG::qSymbolUC *v3; // rbx
  UFG::PedSpawningInfo **p; // rcx
  UFG::PreloadRequest **v5; // rcx
  UFG::MeshResourceLoader **v6; // rcx
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *mPrev; // rcx
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *mNext; // rax

  mModelNames = this->mModelNames;
  if ( mModelNames )
  {
    v3 = mModelNames - 1;
    `eh vector destructor iterator(mModelNames, 4ui64, mModelNames[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
    this->mModelNames = 0i64;
  }
  UFG::DataStreamer::Handle::~Handle(&this->mDataStreamerHandle);
  p = this->mProxies.p;
  if ( p )
    operator delete[](p);
  this->mProxies.p = 0i64;
  *(_QWORD *)&this->mProxies.size = 0i64;
  v5 = this->mPreloads.p;
  if ( v5 )
    operator delete[](v5);
  this->mPreloads.p = 0i64;
  *(_QWORD *)&this->mPreloads.size = 0i64;
  v6 = this->mInstances.p;
  if ( v6 )
    operator delete[](v6);
  this->mInstances.p = 0i64;
  *(_QWORD *)&this->mInstances.size = 0i64;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 73
// RVA: 0x438570
void __fastcall UFG::ResourceRequest::AddDependency(
        UFG::ResourceRequest *this,
        UFG::PriorityBucket::Type priority,
        UFG::ResourceUser *dependency)
{
  __int64 v3; // rdi

  v3 = priority;
  if ( dependency->mType )
  {
    if ( dependency->mType == Preload )
    {
      UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
        (UFG::qArray<UFG::qPropertySet *,0> *)&this->mPreloads,
        (UFG::qPropertySet **)&dependency->8,
        "ResourceRequest::AddDependency");
    }
    else if ( dependency->mType == Proxy )
    {
      UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
        (UFG::qArray<UFG::qPropertySet *,0> *)&this->mProxies,
        (UFG::qPropertySet **)&dependency->8,
        "ResourceRequest::AddDependency");
    }
  }
  else
  {
    UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
      (UFG::qArray<UFG::qPropertySet *,0> *)&this->mInstances,
      (UFG::qPropertySet **)&dependency->8,
      "ResourceRequest::AddDependency");
  }
  ++this->mPriorityRefCounts[v3];
  this->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
}

// File Line: 90
// RVA: 0x442120
void __fastcall UFG::ResourceRequest::RemoveDependency(
        UFG::ResourceRequest *this,
        UFG::PriorityBucket::Type priority,
        UFG::ResourceUser *dependency)
{
  __int64 v4; // rbx
  __int64 v5; // rcx
  unsigned int v6; // edx
  UFG::PedSpawningInfo **v7; // r10
  unsigned int v8; // eax
  unsigned int size; // edx
  __int64 v10; // rcx
  UFG::PreloadRequest **p; // r10
  unsigned int v12; // eax
  unsigned int v13; // edx
  __int64 v14; // rcx
  UFG::MeshResourceLoader **v15; // r10
  unsigned int v16; // eax

  v4 = priority;
  if ( dependency->mType )
  {
    if ( dependency->mType == Preload )
    {
      size = this->mPreloads.size;
      v10 = 0i64;
      if ( size )
      {
        p = this->mPreloads.p;
        while ( dependency->mPreload != p[v10] )
        {
          v10 = (unsigned int)(v10 + 1);
          if ( (unsigned int)v10 >= size )
            goto LABEL_31;
        }
        if ( (int)v10 >= 0 )
        {
          p[v10] = p[size - 1];
          v12 = this->mPreloads.size;
          if ( v12 > 1 )
            this->mPreloads.size = v12 - 1;
          else
            this->mPreloads.size = 0;
        }
      }
    }
    else
    {
      v5 = (unsigned int)(dependency->mType - 2);
      if ( dependency->mType == Proxy )
      {
        v6 = this->mProxies.size;
        if ( v6 )
        {
          v7 = this->mProxies.p;
          while ( dependency->mProxy != v7[v5] )
          {
            v5 = (unsigned int)(v5 + 1);
            if ( (unsigned int)v5 >= v6 )
              goto LABEL_31;
          }
          if ( (int)v5 >= 0 )
          {
            v7[v5] = v7[v6 - 1];
            v8 = this->mProxies.size;
            if ( v8 > 1 )
              this->mProxies.size = v8 - 1;
            else
              this->mProxies.size = 0;
          }
        }
      }
    }
  }
  else
  {
    v13 = this->mInstances.size;
    v14 = 0i64;
    if ( v13 )
    {
      v15 = this->mInstances.p;
      while ( dependency->mMeshLoader != v15[v14] )
      {
        v14 = (unsigned int)(v14 + 1);
        if ( (unsigned int)v14 >= v13 )
          goto LABEL_31;
      }
      if ( (int)v14 >= 0 )
      {
        v15[v14] = v15[v13 - 1];
        v16 = this->mInstances.size;
        if ( v16 > 1 )
          this->mInstances.size = v16 - 1;
        else
          this->mInstances.size = 0;
      }
    }
  }
LABEL_31:
  --this->mPriorityRefCounts[v4];
  this->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
}

// File Line: 153
// RVA: 0x43F9E0
void __fastcall UFG::ResourceRequest::OnLoaded(UFG::ResourceRequest *this)
{
  __int64 i; // r9
  UFG::MeshResourceLoader *v3; // r8
  __int64 v4; // rax
  __int64 mResourceCount; // rdx
  __int64 v6; // rdx
  __int64 v7; // rcx

  UFG::ResourceRequest::FindModelNames(this);
  for ( i = 0i64; (unsigned int)i < this->mInstances.size; v3->mResourcesDirty = 1 )
  {
    v3 = this->mInstances.p[i];
    v4 = 0i64;
    mResourceCount = v3->mResourceCount;
    if ( (_DWORD)mResourceCount )
    {
      while ( v3->mResourceRequests[v4] != this )
      {
        v4 = (unsigned int)(v4 + 1);
        if ( (unsigned int)v4 >= (unsigned int)mResourceCount )
          goto LABEL_5;
      }
      v6 = 1i64 << (v4 & 0x3F);
      v7 = (__int64)(int)v4 >> 6;
      v3->mRequestsLoadedFlags.mBits[v7] |= v6;
      v3->mRequestsDispatchEventFlags.mBits[v7] |= v6;
    }
    else
    {
LABEL_5:
      v3->mResourceRequests[mResourceCount] = this;
      v3->mRequestsLoadedFlags.mBits[(__int64)(int)v3->mResourceCount >> 6] |= 1i64 << (v3->mResourceCount & 0x3F);
      v3->mRequestsDispatchEventFlags.mBits[(__int64)(int)v3->mResourceCount >> 6] |= 1i64 << (v3->mResourceCount & 0x3F);
      ++v3->mResourceCount;
    }
    i = (unsigned int)(i + 1);
  }
}

// File Line: 164
// RVA: 0x43CB80
void __fastcall UFG::ResourceRequest::FindModelNames(UFG::ResourceRequest *this)
{
  UFG::qResourceWarehouse *v2; // rax
  UFG::qString *v3; // rax
  unsigned int mStringHashUpper32; // r15d
  unsigned int v5; // esi
  const char **v6; // rbx
  __int64 v7; // rbp
  __int64 v8; // r14
  UFG::qResourceData *v9; // rax
  UFG::qWiseSymbol *v10; // rax
  __int64 mNumModels; // rcx
  UFG::qSymbolUC *mModelNames; // rcx
  UFG::qSymbolUC *v13; // rbx
  unsigned int v14; // eax
  int v15; // ebp
  __int64 v16; // rax
  unsigned __int64 v17; // kr00_8
  bool v18; // cf
  unsigned __int64 v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::qSymbolUC *v21; // rbx
  UFG::qString result; // [rsp+30h] [rbp-188h] BYREF
  __int64 v23; // [rsp+58h] [rbp-160h]
  UFG::qString v24; // [rsp+60h] [rbp-158h] BYREF
  int ptr[64]; // [rsp+90h] [rbp-128h] BYREF
  UFG::allocator::free_link *v26; // [rsp+1C0h] [rbp+8h] BYREF

  v23 = -2i64;
  if ( (_S4_8 & 1) == 0 )
  {
    _S4_8 |= 1u;
    v2 = UFG::qResourceWarehouse::Instance();
    model_inventory = UFG::qResourceWarehouse::GetInventory(v2, 0xA2ADCD77);
  }
  UFG::qString::qString(&v24, this->mAssetName);
  UFG::qString::GetFilenameWithoutExtension(v3, &result);
  UFG::qString::~qString(&v24);
  `eh vector constructor iterator(ptr, 4ui64, 64, (void (__fastcall *)(void *))BackInfo::BackInfo);
  mStringHashUpper32 = result.mStringHashUpper32;
  if ( result.mStringHashUpper32 == -1 )
  {
    mStringHashUpper32 = UFG::qStringHashUpper32(result.mData, -1);
    result.mStringHashUpper32 = mStringHashUpper32;
  }
  v5 = 0;
  this->mNumModels = 0;
  v6 = possibleExtensions;
  v7 = 9i64;
  do
  {
    v8 = (unsigned int)UFG::qStringHash32(*v6, mStringHashUpper32);
    v9 = model_inventory->vfptr->Get(model_inventory, v8);
    if ( v9 && v9 != model_inventory->mDefaultResourceData )
    {
      v10 = UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&v26, v8);
      mNumModels = this->mNumModels;
      ptr[mNumModels] = v10->mUID;
      this->mNumModels = mNumModels + 1;
    }
    ++v6;
    --v7;
  }
  while ( v7 );
  mModelNames = this->mModelNames;
  if ( mModelNames )
  {
    v13 = mModelNames - 1;
    `eh vector destructor iterator(mModelNames, 4ui64, mModelNames[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v13);
    this->mModelNames = 0i64;
  }
  v14 = this->mNumModels;
  if ( v14 )
  {
    v15 = this->mNumModels;
    v17 = v14;
    v16 = 4i64 * v14;
    if ( !is_mul_ok(v17, 4ui64) )
      v16 = -1i64;
    v18 = __CFADD__(v16, 4i64);
    v19 = v16 + 4;
    if ( v18 )
      v19 = -1i64;
    v20 = UFG::qMalloc(v19, "ModelNames", 0i64);
    v26 = v20;
    if ( v20 )
    {
      LODWORD(v20->mNext) = v15;
      v21 = (UFG::qSymbolUC *)&v20->mNext + 1;
      `eh vector constructor iterator(
        (char *)&v20->mNext + 4,
        4ui64,
        v15,
        (void (__fastcall *)(void *))BackInfo::BackInfo);
    }
    else
    {
      v21 = 0i64;
    }
    this->mModelNames = v21;
    if ( this->mNumModels )
    {
      do
      {
        this->mModelNames[v5].mUID = ptr[v5];
        ++v5;
      }
      while ( v5 < this->mNumModels );
    }
  }
  `eh vector destructor iterator(ptr, 4ui64, 64, (void (__fastcall *)(void *))_);
  UFG::qString::~qString(&result);
}

