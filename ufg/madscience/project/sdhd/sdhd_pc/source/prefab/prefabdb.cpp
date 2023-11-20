// File Line: 90
// RVA: 0x512EE0
void __fastcall UFG::PrefabDB::RefObject::~RefObject(UFG::PrefabDB::RefObject *this)
{
  this->vfptr = (UFG::PrefabDB::RefObjectVtbl *)&UFG::PrefabDB::RefObject::`vftable;
}

// File Line: 120
// RVA: 0x1542EC0
__int64 UFG::PrefabDB::_dynamic_initializer_for__sDataHandles__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PrefabDB::sDataHandles.mTree);
  return atexit(UFG::PrefabDB::_dynamic_atexit_destructor_for__sDataHandles__);
}

// File Line: 123
// RVA: 0x513000
void __fastcall UFG::PrefabDB::DataHandle::Callback(UFG::DataStreamer::Handle *handle, void *param)
{
  *((_BYTE *)param + 48) = 1;
}

// File Line: 130
// RVA: 0x512AD0
void __fastcall UFG::PrefabDB::DataHandle::DataHandle(UFG::PrefabDB::DataHandle *this, unsigned int uid, const char *filePath, unsigned int symbol_uid)
{
  UFG::DataStreamer::Handle *v4; // ST48_8

  this->vfptr = (UFG::PrefabDB::RefObjectVtbl *)&UFG::PrefabDB::RefObject::`vftable;
  this->mRefCount = 0;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = uid;
  this->vfptr = (UFG::PrefabDB::RefObjectVtbl *)&UFG::PrefabDB::DataHandle::`vftable;
  this->mIsLoaded = 0;
  v4 = &this->mHandle;
  v4->mPrev = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v4->mPrev;
  v4->mNext = (UFG::qNode<UFG::DataStreamer::Handle,UFG::DataStreamer::Handle> *)&v4->mPrev;
  this->mHandle.mCallback = 0i64;
  this->mHandle.mCallbackParam = 0i64;
  this->mHandle.mImpl = 0i64;
  *(_DWORD *)&this->mHandle.mFlags = 536870915;
  this->mHandle._mTargetState.mValue = 1;
  UFG::DataStreamer::QueueStream(
    &this->mHandle,
    filePath,
    DATA_TURF,
    DEFAULT_PRIORITY,
    3u,
    UFG::PrefabDB::DataHandle::Callback,
    this);
}

// File Line: 160
// RVA: 0x1542EF0
__int64 UFG::PrefabDB::_dynamic_initializer_for__sPrefabRequests__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::PrefabDB::sPrefabRequests.mTree);
  return atexit(UFG::PrefabDB::_dynamic_atexit_destructor_for__sPrefabRequests__);
}

// File Line: 164
// RVA: 0x512B80
void __fastcall UFG::PrefabDB::PrefabRequest::PrefabRequest(UFG::PrefabDB::PrefabRequest *this, unsigned int sym_uid, UFG::PrefabEntry *prefabEntry)
{
  UFG::PrefabEntry *v3; // r12
  unsigned int v4; // er13
  signed __int64 v5; // rdi
  UFG::qNodeRB<UFG::PrefabDB::PrefabRequest> *v6; // rdx
  UFG::qArray<UFG::qReflectInventoryBase *,0> *v7; // r14
  unsigned int i; // ebp
  signed __int64 v9; // rax
  const char *v10; // rbx
  bool v11; // zf
  unsigned int v12; // eax
  unsigned int v13; // esi
  UFG::qBaseTreeRB *v14; // rax
  UFG::allocator::free_link *v15; // rax
  signed __int64 v16; // rax
  __int64 v17; // rsi
  unsigned int v18; // ebx
  unsigned int v19; // edx
  unsigned int v20; // edx
  Render::RenderOutputParams outSettings; // [rsp+30h] [rbp-A8h]

  v3 = prefabEntry;
  v4 = sym_uid;
  this->vfptr = (UFG::PrefabDB::RefObjectVtbl *)&UFG::PrefabDB::RefObject::`vftable;
  v5 = 0i64;
  this->mRefCount = 0;
  v6 = (UFG::qNodeRB<UFG::PrefabDB::PrefabRequest> *)&this->mNode;
  v6->mNode.mParent = 0i64;
  v6->mNode.mChild[0] = 0i64;
  v6->mNode.mChild[1] = 0i64;
  v6->mNode.mUID = v4;
  this->vfptr = (UFG::PrefabDB::RefObjectVtbl *)&UFG::PrefabDB::PrefabRequest::`vftable;
  v7 = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mHandles;
  v7->p = 0i64;
  *(_QWORD *)&v7->size = 0i64;
  UFG::qBaseTreeRB::Add(&UFG::PrefabDB::sPrefabRequests.mTree, &this->mNode);
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  for ( i = 0; i < v3->mFilePaths.mData.mNumItems; ++i )
  {
    v9 = (signed __int64)&v3->mFilePaths.mData.mItems[i];
    if ( *(_DWORD *)(v9 + 8) )
      v10 = *(const char **)v9;
    else
      v10 = &customWorldMapCaption;
    if ( !UFG::qStringFind(v10, ".temp.bin") )
    {
      if ( UFG::qStringFind(v10, "\\LD\\") )
      {
        v11 = outSettings.mTextureDetailLevel == 0;
      }
      else if ( UFG::qStringFind(v10, "\\SD\\") )
      {
        v11 = outSettings.mTextureDetailLevel == 1;
      }
      else
      {
        if ( !UFG::qStringFind(v10, "\\HD\\") )
          goto LABEL_13;
        v11 = outSettings.mTextureDetailLevel == 2;
      }
      if ( v11 == 1 )
      {
LABEL_13:
        v12 = UFG::qStringHashUpper32(v10, 0xFFFFFFFF);
        v13 = v12;
        if ( v12 )
        {
          v14 = UFG::qBaseTreeRB::Get(&UFG::PrefabDB::sDataHandles.mTree, v12);
          if ( v14 )
            v5 = (signed __int64)&v14[-1].mNULL.mUID;
        }
        if ( !v5 )
        {
          v15 = UFG::qMalloc(0x68ui64, UFG::gGlobalNewName, 0i64);
          if ( v15 )
          {
            UFG::PrefabDB::DataHandle::DataHandle((UFG::PrefabDB::DataHandle *)v15, v13, v10, v4);
            v5 = v16;
          }
          else
          {
            v5 = 0i64;
          }
        }
        ++*(_DWORD *)(v5 + 8);
        v17 = v7->size;
        v18 = v17 + 1;
        v19 = v7->capacity;
        if ( (signed int)v17 + 1 > v19 )
        {
          if ( v19 )
            v20 = 2 * v19;
          else
            v20 = 1;
          for ( ; v20 < v18; v20 *= 2 )
            ;
          if ( v20 <= 2 )
            v20 = 2;
          if ( v20 - v18 > 0x10000 )
            v20 = v17 + 65537;
          UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(v7, v20, "qArray.Add");
        }
        v7->size = v18;
        v7->p[v17] = (UFG::qReflectInventoryBase *)v5;
        v5 = 0i64;
        continue;
      }
    }
  }
}

// File Line: 205
// RVA: 0x512E40
void __fastcall UFG::PrefabDB::PrefabRequest::~PrefabRequest(UFG::PrefabDB::PrefabRequest *this)
{
  UFG::PrefabDB::PrefabRequest *v1; // rbx
  __int64 v2; // rdi
  UFG::PrefabDB::DataHandle *v3; // rcx
  bool v4; // zf
  UFG::PrefabDB::DataHandle **v5; // rcx

  v1 = this;
  this->vfptr = (UFG::PrefabDB::RefObjectVtbl *)&UFG::PrefabDB::PrefabRequest::`vftable;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::PrefabDB::sPrefabRequests,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->mNode);
  v2 = 0i64;
  if ( v1->mHandles.size )
  {
    do
    {
      v3 = v1->mHandles.p[v2];
      v4 = v3->mRefCount-- == 1;
      if ( v4 )
        v3->vfptr->__vecDelDtor((UFG::PrefabDB::RefObject *)&v3->vfptr, 1u);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v1->mHandles.size );
  }
  v5 = v1->mHandles.p;
  if ( v5 )
    operator delete[](v5);
  v1->mHandles.p = 0i64;
  *(_QWORD *)&v1->mHandles.size = 0i64;
  v1->vfptr = (UFG::PrefabDB::RefObjectVtbl *)&UFG::PrefabDB::RefObject::`vftable;
}

// File Line: 214
// RVA: 0x513030
bool __fastcall UFG::PrefabDB::PrefabRequest::IsLoaded(UFG::PrefabDB::PrefabRequest *this)
{
  unsigned int v1; // er10
  unsigned int v2; // edx
  bool result; // al
  __int64 v4; // r8

  v1 = this->mHandles.size;
  v2 = 0;
  result = 1;
  if ( v1 )
  {
    v4 = 0i64;
    do
    {
      if ( result != 1 )
        break;
      ++v2;
      ++v4;
      result = this->mHandles.p[v4 - 1]->mIsLoaded;
    }
    while ( v2 < v1 );
  }
  return result;
}

// File Line: 230
// RVA: 0x513070
void __fastcall UFG::PrefabDB::Load(unsigned int prefabId)
{
  unsigned int v1; // edi
  unsigned __int64 v2; // rbx
  UFG::qReflectWarehouse *v3; // rax
  UFG::qReflectInventoryBase *v4; // rax
  UFG::qTree64Base *v5; // rax
  UFG::PrefabEntry *v6; // rbx
  UFG::qBaseTreeRB *v7; // rax
  UFG::PrefabDB::PrefabRequest *v8; // rax

  v1 = prefabId;
  v2 = UFG::qStringHash64("UFG::PrefabEntry", 0xFFFFFFFFFFFFFFFFui64);
  v3 = UFG::qReflectWarehouse::Instance();
  v4 = UFG::qReflectWarehouse::GetInventory(v3, v2);
  v5 = UFG::qTree64Base::Get(&v4->mItems.mTree, v1);
  if ( v5 )
  {
    v6 = (UFG::PrefabEntry *)&v5[-1].mCount;
    if ( v5 != (UFG::qTree64Base *)8 )
    {
      if ( !v1
        || (v7 = UFG::qBaseTreeRB::Get(&UFG::PrefabDB::sPrefabRequests.mTree, v1)) == 0i64
        || (v8 = (UFG::PrefabDB::PrefabRequest *)&v7[-1].mNULL.mUID) == 0i64 )
      {
        v8 = (UFG::PrefabDB::PrefabRequest *)UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
        if ( v8 )
          UFG::PrefabDB::PrefabRequest::PrefabRequest(v8, v1, v6);
      }
      ++v8->mRefCount;
    }
  }
}

// File Line: 261
// RVA: 0x5131F0
void __fastcall UFG::PrefabDB::Unload(unsigned int prefabId)
{
  UFG::qBaseTreeRB *v1; // rax
  signed __int64 v2; // rcx
  bool v3; // zf

  if ( prefabId )
  {
    v1 = UFG::qBaseTreeRB::Get(&UFG::PrefabDB::sPrefabRequests.mTree, prefabId);
    if ( v1 )
    {
      v2 = (signed __int64)&v1[-1].mNULL.mUID;
      if ( v1 != (UFG::qBaseTreeRB *)16 )
      {
        v3 = (*(_DWORD *)(v2 + 8))-- == 1;
        if ( v3 )
          (**(void (__fastcall ***)(signed __int64, signed __int64))v2)(v2, 1i64);
      }
    }
  }
}

// File Line: 282
// RVA: 0x513230
void __fastcall UFG::PrefabDB::WaitForStreamer(unsigned int prefabId)
{
  UFG::qBaseTreeRB *v1; // rax
  UFG::PrefabDB::PrefabRequest *v2; // rbx
  UFG *v3; // rcx

  if ( prefabId )
  {
    v1 = UFG::qBaseTreeRB::Get(&UFG::PrefabDB::sPrefabRequests.mTree, prefabId);
    if ( v1 )
    {
      v2 = (UFG::PrefabDB::PrefabRequest *)&v1[-1].mNULL.mUID;
      if ( v1 != (UFG::qBaseTreeRB *)16
        && !UFG::PrefabDB::PrefabRequest::IsLoaded((UFG::PrefabDB::PrefabRequest *)&v1[-1].mNULL.mUID) )
      {
        do
        {
          UFG::qFileService(v3);
          UFG::DataStreamer::Service(0.1);
        }
        while ( !UFG::PrefabDB::PrefabRequest::IsLoaded(v2) );
      }
    }
  }
}

