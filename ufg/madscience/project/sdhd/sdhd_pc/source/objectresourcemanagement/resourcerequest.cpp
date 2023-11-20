// File Line: 57
// RVA: 0x437290
void __fastcall UFG::ResourceRequest::ResourceRequest(UFG::ResourceRequest *this)
{
  UFG::ResourceRequest *v1; // rdi
  unsigned int v2; // ebx
  unsigned __int64 v3; // rax
  UFG::allocator::free_link *v4; // rax
  UFG::MeshResourceLoader **v5; // rsi
  UFG::DataStreamer::Handle *v6; // [rsp+58h] [rbp+10h]

  v1 = this;
  this->mPrev = (UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *)&this->mPrev;
  this->mNext = (UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *)&this->mPrev;
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
  v6 = &this->mDataStreamerHandle;
  v6->mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v6->mPrev;
  v6->mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v6->mPrev;
  this->mDataStreamerHandle.mCallback = 0i64;
  this->mDataStreamerHandle.mCallbackParam = 0i64;
  this->mDataStreamerHandle.mImpl = 0i64;
  *(_DWORD *)&this->mDataStreamerHandle.mFlags = 536870915;
  v6->_mTargetState.mValue = 1;
  this->mAssetName[0] = 0;
  if ( this->mInstances.capacity < 0x40 && this->mInstances.size != 64 )
  {
    v3 = 512i64;
    if ( !is_mul_ok(0x40ui64, 8ui64) )
      v3 = -1i64;
    v4 = UFG::qMalloc(v3, "ResourceRequest::mInstances", 0i64);
    v5 = (UFG::MeshResourceLoader **)v4;
    if ( v1->mInstances.p )
    {
      if ( v1->mInstances.size > 0 )
      {
        do
        {
          v4[v2] = (UFG::allocator::free_link)v1->mInstances.p[v2];
          ++v2;
        }
        while ( v2 < v1->mInstances.size );
      }
      operator delete[](v1->mInstances.p);
    }
    v1->mInstances.p = v5;
    v1->mInstances.capacity = 64;
  }
  UFG::qMemSet(v1->mPriorityRefCounts, 0, 0x14u);
}

// File Line: 64
// RVA: 0x437F30
void __fastcall UFG::ResourceRequest::~ResourceRequest(UFG::ResourceRequest *this)
{
  UFG::ResourceRequest *v1; // rdi
  UFG::qSymbolUC *v2; // rcx
  UFG::qSymbolUC *v3; // rbx
  UFG::PedSpawningInfo **v4; // rcx
  UFG::PreloadRequest **v5; // rcx
  UFG::MeshResourceLoader **v6; // rcx
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *v7; // rcx
  UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *v8; // rax

  v1 = this;
  v2 = this->mModelNames;
  if ( v2 )
  {
    v3 = v2 - 1;
    `eh vector destructor iterator(v2, 4ui64, v2[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
    v1->mModelNames = 0i64;
  }
  UFG::DataStreamer::Handle::~Handle(&v1->mDataStreamerHandle);
  v4 = v1->mProxies.p;
  if ( v4 )
    operator delete[](v4);
  v1->mProxies.p = 0i64;
  *(_QWORD *)&v1->mProxies.size = 0i64;
  v5 = v1->mPreloads.p;
  if ( v5 )
    operator delete[](v5);
  v1->mPreloads.p = 0i64;
  *(_QWORD *)&v1->mPreloads.size = 0i64;
  v6 = v1->mInstances.p;
  if ( v6 )
    operator delete[](v6);
  v1->mInstances.p = 0i64;
  *(_QWORD *)&v1->mInstances.size = 0i64;
  v7 = v1->mPrev;
  v8 = v1->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1->mPrev = (UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::ResourceRequest,UFG::ResourceRequest> *)&v1->mPrev;
}

// File Line: 73
// RVA: 0x438570
void __fastcall UFG::ResourceRequest::AddDependency(UFG::ResourceRequest *this, UFG::PriorityBucket::Type priority, UFG::ResourceUser *dependency)
{
  __int64 v3; // rdi
  UFG::ResourceRequest *v4; // rbx

  v3 = priority;
  v4 = this;
  if ( dependency->mType )
  {
    if ( dependency->mType == 1 )
    {
      UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
        (UFG::qArray<UFG::qPropertySet *,0> *)&this->mPreloads,
        (UFG::qPropertySet *const *)&dependency->8,
        "ResourceRequest::AddDependency");
    }
    else if ( dependency->mType == 2 )
    {
      UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
        (UFG::qArray<UFG::qPropertySet *,0> *)&this->mProxies,
        (UFG::qPropertySet *const *)&dependency->8,
        "ResourceRequest::AddDependency");
    }
  }
  else
  {
    UFG::qArray<UFG::PedSpawningInfo *,0>::Add(
      (UFG::qArray<UFG::qPropertySet *,0> *)&this->mInstances,
      (UFG::qPropertySet *const *)&dependency->8,
      "ResourceRequest::AddDependency");
  }
  ++v4->mPriorityRefCounts[v3];
  v4->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
}

// File Line: 90
// RVA: 0x442120
void __fastcall UFG::ResourceRequest::RemoveDependency(UFG::ResourceRequest *this, UFG::PriorityBucket::Type priority, UFG::ResourceUser *dependency)
{
  UFG::ResourceRequest *v3; // r9
  __int64 v4; // rbx
  __int64 v5; // rcx
  unsigned int v6; // edx
  UFG::PedSpawningInfo **v7; // r10
  unsigned int v8; // eax
  unsigned int v9; // edx
  __int64 v10; // rcx
  UFG::PreloadRequest **v11; // r10
  unsigned int v12; // eax
  unsigned int v13; // edx
  __int64 v14; // rcx
  UFG::MeshResourceLoader **v15; // r10
  unsigned int v16; // eax

  v3 = this;
  v4 = priority;
  if ( dependency->mType )
  {
    if ( dependency->mType == 1 )
    {
      v9 = this->mPreloads.size;
      v10 = 0i64;
      if ( v9 )
      {
        v11 = v3->mPreloads.p;
        while ( dependency->mPreload != v11[v10] )
        {
          v10 = (unsigned int)(v10 + 1);
          if ( (unsigned int)v10 >= v9 )
            goto LABEL_31;
        }
        if ( (signed int)v10 >= 0 )
        {
          v11[v10] = v11[v9 - 1];
          v12 = v3->mPreloads.size;
          if ( v12 > 1 )
            v3->mPreloads.size = v12 - 1;
          else
            v3->mPreloads.size = 0;
        }
      }
    }
    else
    {
      v5 = (unsigned int)(dependency->mType - 2);
      if ( dependency->mType == 2 )
      {
        v6 = v3->mProxies.size;
        if ( v6 )
        {
          v7 = v3->mProxies.p;
          while ( dependency->mProxy != v7[v5] )
          {
            v5 = (unsigned int)(v5 + 1);
            if ( (unsigned int)v5 >= v6 )
              goto LABEL_31;
          }
          if ( (signed int)v5 >= 0 )
          {
            v7[v5] = v7[v6 - 1];
            v8 = v3->mProxies.size;
            if ( v8 > 1 )
              v3->mProxies.size = v8 - 1;
            else
              v3->mProxies.size = 0;
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
      v15 = v3->mInstances.p;
      while ( dependency->mMeshLoader != v15[v14] )
      {
        v14 = (unsigned int)(v14 + 1);
        if ( (unsigned int)v14 >= v13 )
          goto LABEL_31;
      }
      if ( (signed int)v14 >= 0 )
      {
        v15[v14] = v15[v13 - 1];
        v16 = v3->mInstances.size;
        if ( v16 > 1 )
          v3->mInstances.size = v16 - 1;
        else
          v3->mInstances.size = 0;
      }
    }
  }
LABEL_31:
  --v3->mPriorityRefCounts[v4];
  v3->mLastReferencedFrame = Illusion::gEngine.mFrameCount;
}

// File Line: 153
// RVA: 0x43F9E0
void __fastcall UFG::ResourceRequest::OnLoaded(UFG::ResourceRequest *this)
{
  UFG::ResourceRequest *v1; // rbx
  __int64 v2; // r9
  UFG::MeshResourceLoader *v3; // r8
  __int64 v4; // rax
  __int64 v5; // rdx
  signed __int64 v6; // rdx
  signed __int64 v7; // rcx

  v1 = this;
  UFG::ResourceRequest::FindModelNames(this);
  v2 = 0i64;
  if ( v1->mInstances.size )
  {
    do
    {
      v3 = v1->mInstances.p[v2];
      v4 = 0i64;
      v5 = v3->mResourceCount;
      if ( (_DWORD)v5 )
      {
        while ( v3->mResourceRequests[v4] != v1 )
        {
          v4 = (unsigned int)(v4 + 1);
          if ( (unsigned int)v4 >= (unsigned int)v5 )
            goto LABEL_5;
        }
        v6 = 1i64 << (v4 & 0x3F);
        v7 = (signed __int64)(signed int)v4 >> 6;
        v3->mRequestsLoadedFlags.mBits[v7] |= v6;
        v3->mRequestsDispatchEventFlags.mBits[v7] |= v6;
      }
      else
      {
LABEL_5:
        v3->mResourceRequests[v5] = v1;
        v3->mRequestsLoadedFlags.mBits[(signed __int64)(signed int)v3->mResourceCount >> 6] |= 1i64 << (v3->mResourceCount & 0x3F);
        v3->mRequestsDispatchEventFlags.mBits[(signed __int64)(signed int)v3->mResourceCount >> 6] |= 1i64 << (v3->mResourceCount & 0x3F);
        ++v3->mResourceCount;
      }
      v2 = (unsigned int)(v2 + 1);
      v3->mResourcesDirty = 1;
    }
    while ( (unsigned int)v2 < v1->mInstances.size );
  }
}

// File Line: 164
// RVA: 0x43CB80
void __fastcall UFG::ResourceRequest::FindModelNames(UFG::ResourceRequest *this)
{
  UFG::ResourceRequest *v1; // rdi
  UFG::qResourceWarehouse *v2; // rax
  UFG::qString *v3; // rax
  int v4; // edx
  unsigned int v5; // er15
  unsigned int v6; // esi
  const char **v7; // rbx
  signed __int64 v8; // rbp
  unsigned int v9; // eax
  unsigned int v10; // er14
  UFG::qResourceData *v11; // rax
  UFG::qWiseSymbol *v12; // rax
  __int64 v13; // rcx
  UFG::qSymbolUC *v14; // rcx
  UFG::qSymbolUC *v15; // rbx
  unsigned int v16; // eax
  int v17; // ebp
  signed __int64 v18; // rax
  unsigned __int64 v19; // kr00_8
  unsigned __int8 v20; // cf
  unsigned __int64 v21; // rax
  UFG::allocator::free_link *v22; // rax
  signed __int64 v23; // rbx
  UFG::qString result; // [rsp+30h] [rbp-188h]
  __int64 v25; // [rsp+58h] [rbp-160h]
  UFG::qString v26; // [rsp+60h] [rbp-158h]
  int ptr[64]; // [rsp+90h] [rbp-128h]
  UFG::qWiseSymbol v28; // [rsp+1C0h] [rbp+8h]

  v25 = -2i64;
  v1 = this;
  if ( !(_S4_8 & 1) )
  {
    _S4_8 |= 1u;
    v2 = UFG::qResourceWarehouse::Instance();
    model_inventory = UFG::qResourceWarehouse::GetInventory(v2, 0xA2ADCD77);
  }
  UFG::qString::qString(&v26, v1->mAssetName);
  UFG::qString::GetFilenameWithoutExtension(v3, &result);
  UFG::qString::~qString(&v26);
  `eh vector constructor iterator(ptr, 4ui64, 64, (void (__fastcall *)(void *))BackInfo::BackInfo);
  v5 = result.mStringHashUpper32;
  if ( result.mStringHashUpper32 == -1 )
  {
    v5 = UFG::qStringHashUpper32(result.mData, result.mStringHashUpper32 | v4);
    result.mStringHashUpper32 = v5;
  }
  v6 = 0;
  v1->mNumModels = 0;
  v7 = possibleExtensions;
  v8 = 9i64;
  do
  {
    v9 = UFG::qStringHash32(*v7, v5);
    v10 = v9;
    v11 = model_inventory->vfptr->Get(model_inventory, v9);
    if ( v11 && v11 != model_inventory->mDefaultResourceData )
    {
      v12 = UFG::qSymbol::qSymbol(&v28, v10);
      v13 = v1->mNumModels;
      ptr[v13] = v12->mUID;
      v1->mNumModels = v13 + 1;
    }
    ++v7;
    --v8;
  }
  while ( v8 );
  v14 = v1->mModelNames;
  if ( v14 )
  {
    v15 = v14 - 1;
    `eh vector destructor iterator(v14, 4ui64, v14[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v15);
    v1->mModelNames = 0i64;
  }
  v16 = v1->mNumModels;
  if ( v16 )
  {
    v17 = v1->mNumModels;
    v19 = v16;
    v18 = 4i64 * v16;
    if ( !is_mul_ok(v19, 4ui64) )
      v18 = -1i64;
    v20 = __CFADD__(v18, 4i64);
    v21 = v18 + 4;
    if ( v20 )
      v21 = -1i64;
    v22 = UFG::qMalloc(v21, "ModelNames", 0i64);
    *(_QWORD *)&v28.mUID = v22;
    if ( v22 )
    {
      LODWORD(v22->mNext) = v17;
      v23 = (signed __int64)&v22->mNext + 4;
      `eh vector constructor iterator(
        (char *)&v22->mNext + 4,
        4ui64,
        v17,
        (void (__fastcall *)(void *))BackInfo::BackInfo);
    }
    else
    {
      v23 = 0i64;
    }
    v1->mModelNames = (UFG::qSymbolUC *)v23;
    if ( v1->mNumModels )
    {
      do
      {
        v1->mModelNames[v6].mUID = ptr[v6];
        ++v6;
      }
      while ( v6 < v1->mNumModels );
    }
  }
  `eh vector destructor iterator(ptr, 4ui64, 64, (void (__fastcall *)(void *))_);
  UFG::qString::~qString(&result);
}

