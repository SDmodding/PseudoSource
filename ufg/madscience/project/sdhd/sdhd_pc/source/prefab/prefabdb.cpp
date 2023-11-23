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
  return atexit((int (__fastcall *)())UFG::PrefabDB::_dynamic_atexit_destructor_for__sDataHandles__);
}

// File Line: 123
// RVA: 0x513000
void __fastcall UFG::PrefabDB::DataHandle::Callback(UFG::DataStreamer::Handle *handle, _BYTE *param)
{
  param[48] = 1;
}

// File Line: 130
// RVA: 0x512AD0
void __fastcall UFG::PrefabDB::DataHandle::DataHandle(
        UFG::PrefabDB::DataHandle *this,
        unsigned int uid,
        const char *filePath,
        unsigned int symbol_uid)
{
  this->vfptr = (UFG::PrefabDB::RefObjectVtbl *)&UFG::PrefabDB::RefObject::`vftable;
  this->mRefCount = 0;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = uid;
  this->vfptr = (UFG::PrefabDB::RefObjectVtbl *)&UFG::PrefabDB::DataHandle::`vftable;
  this->mIsLoaded = 0;
  this->mHandle.mPrev = &this->mHandle;
  this->mHandle.mNext = &this->mHandle;
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
  return atexit((int (__fastcall *)())UFG::PrefabDB::_dynamic_atexit_destructor_for__sPrefabRequests__);
}

// File Line: 164
// RVA: 0x512B80
void __fastcall UFG::PrefabDB::PrefabRequest::PrefabRequest(
        UFG::PrefabDB::PrefabRequest *this,
        unsigned int sym_uid,
        UFG::PrefabEntry *prefabEntry)
{
  unsigned int *p_mUID; // rdi
  UFG::qArray<UFG::qReflectInventoryBase *,0> *p_mHandles; // r14
  unsigned int i; // ebp
  UFG::qReflectString *v8; // rax
  const char *mItems; // rbx
  bool v10; // zf
  unsigned int v11; // eax
  unsigned int v12; // esi
  UFG::qBaseTreeRB *v13; // rax
  UFG::allocator::free_link *v14; // rax
  unsigned int *v15; // rax
  __int64 size; // rsi
  unsigned int v17; // ebx
  unsigned int capacity; // edx
  unsigned int v19; // edx
  Render::RenderOutputParams outSettings; // [rsp+30h] [rbp-A8h] BYREF

  this->vfptr = (UFG::PrefabDB::RefObjectVtbl *)&UFG::PrefabDB::RefObject::`vftable;
  p_mUID = 0i64;
  this->mRefCount = 0;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = sym_uid;
  this->vfptr = (UFG::PrefabDB::RefObjectVtbl *)&UFG::PrefabDB::PrefabRequest::`vftable;
  p_mHandles = (UFG::qArray<UFG::qReflectInventoryBase *,0> *)&this->mHandles;
  this->mHandles.p = 0i64;
  *(_QWORD *)&this->mHandles.size = 0i64;
  UFG::qBaseTreeRB::Add(&UFG::PrefabDB::sPrefabRequests.mTree, &this->mNode);
  Render::RenderOutputParams::RenderOutputParams(&outSettings);
  Render::GetCurrentDisplaySettings(&outSettings);
  for ( i = 0; i < prefabEntry->mFilePaths.mData.mNumItems; ++i )
  {
    v8 = &prefabEntry->mFilePaths.mData.mItems[i];
    if ( v8->mText.mData.mNumItems )
      mItems = v8->mText.mData.mItems;
    else
      mItems = &customCaption;
    if ( !UFG::qStringFind(mItems, ".temp.bin") )
    {
      if ( UFG::qStringFind(mItems, "\\LD\\") )
      {
        v10 = outSettings.mTextureDetailLevel == TEXTURE_DETAIL_LOW;
      }
      else if ( UFG::qStringFind(mItems, "\\SD\\") )
      {
        v10 = outSettings.mTextureDetailLevel == TEXTURE_DETAIL_MEDIUM;
      }
      else
      {
        if ( !UFG::qStringFind(mItems, "\\HD\\") )
          goto LABEL_13;
        v10 = outSettings.mTextureDetailLevel == TEXTURE_DETAIL_HIGH;
      }
      if ( v10 )
      {
LABEL_13:
        v11 = UFG::qStringHashUpper32(mItems, -1);
        v12 = v11;
        if ( v11 )
        {
          v13 = UFG::qBaseTreeRB::Get(&UFG::PrefabDB::sDataHandles.mTree, v11);
          if ( v13 )
            p_mUID = &v13[-1].mNULL.mUID;
        }
        if ( !p_mUID )
        {
          v14 = UFG::qMalloc(0x68ui64, UFG::gGlobalNewName, 0i64);
          if ( v14 )
          {
            UFG::PrefabDB::DataHandle::DataHandle((UFG::PrefabDB::DataHandle *)v14, v12, mItems, sym_uid);
            p_mUID = v15;
          }
          else
          {
            p_mUID = 0i64;
          }
        }
        ++p_mUID[2];
        size = p_mHandles->size;
        v17 = size + 1;
        capacity = p_mHandles->capacity;
        if ( (int)size + 1 > capacity )
        {
          if ( capacity )
            v19 = 2 * capacity;
          else
            v19 = 1;
          for ( ; v19 < v17; v19 *= 2 )
            ;
          if ( v19 <= 2 )
            v19 = 2;
          if ( v19 - v17 > 0x10000 )
            v19 = size + 65537;
          UFG::qArray<UFG::CompositeDrawableComponent *,32>::Reallocate(p_mHandles, v19, "qArray.Add");
        }
        p_mHandles->size = v17;
        p_mHandles->p[size] = (UFG::qReflectInventoryBase *)p_mUID;
        p_mUID = 0i64;
      }
    }
  }
}

// File Line: 205
// RVA: 0x512E40
void __fastcall UFG::PrefabDB::PrefabRequest::~PrefabRequest(UFG::PrefabDB::PrefabRequest *this)
{
  __int64 i; // rdi
  UFG::PrefabDB::DataHandle *v3; // rcx
  UFG::PrefabDB::DataHandle **p; // rcx

  this->vfptr = (UFG::PrefabDB::RefObjectVtbl *)&UFG::PrefabDB::PrefabRequest::`vftable;
  UFG::qBaseTreeVariableRB<unsigned __int64>::Remove(
    (UFG::qBaseTreeVariableRB<unsigned __int64> *)&UFG::PrefabDB::sPrefabRequests,
    (UFG::qBaseNodeVariableRB<unsigned __int64> *)&this->UFG::qNodeRB<UFG::PrefabDB::PrefabRequest>);
  for ( i = 0i64; (unsigned int)i < this->mHandles.size; i = (unsigned int)(i + 1) )
  {
    v3 = this->mHandles.p[i];
    if ( v3->mRefCount-- == 1 )
      v3->vfptr->__vecDelDtor(v3, 1u);
  }
  p = this->mHandles.p;
  if ( p )
    operator delete[](p);
  this->mHandles.p = 0i64;
  *(_QWORD *)&this->mHandles.size = 0i64;
  this->vfptr = (UFG::PrefabDB::RefObjectVtbl *)&UFG::PrefabDB::RefObject::`vftable;
}

// File Line: 214
// RVA: 0x513030
bool __fastcall UFG::PrefabDB::PrefabRequest::IsLoaded(UFG::PrefabDB::PrefabRequest *this)
{
  unsigned int size; // r10d
  unsigned int v2; // edx
  bool result; // al
  __int64 v4; // r8

  size = this->mHandles.size;
  v2 = 0;
  result = 1;
  if ( size )
  {
    v4 = 0i64;
    do
    {
      if ( !result )
        break;
      ++v2;
      result = this->mHandles.p[v4++]->mIsLoaded;
    }
    while ( v2 < size );
  }
  return result;
}

// File Line: 230
// RVA: 0x513070
void __fastcall UFG::PrefabDB::Load(unsigned int prefabId)
{
  unsigned __int64 v2; // rbx
  UFG::qReflectWarehouse *v3; // rax
  UFG::qReflectInventoryBase *Inventory; // rax
  UFG::qTree64Base *v5; // rax
  UFG::PrefabEntry *p_mCount; // rbx
  UFG::qBaseTreeRB *v7; // rax
  UFG::PrefabDB::PrefabRequest *p_mUID; // rax

  v2 = UFG::qStringHash64("UFG::PrefabEntry", 0xFFFFFFFFFFFFFFFFui64);
  v3 = UFG::qReflectWarehouse::Instance();
  Inventory = UFG::qReflectWarehouse::GetInventory(v3, v2);
  v5 = UFG::qTree64Base::Get(&Inventory->mItems.mTree, prefabId);
  if ( v5 )
  {
    p_mCount = (UFG::PrefabEntry *)&v5[-1].mCount;
    if ( v5 != (UFG::qTree64Base *)8 )
    {
      if ( !prefabId
        || (v7 = UFG::qBaseTreeRB::Get(&UFG::PrefabDB::sPrefabRequests.mTree, prefabId)) == 0i64
        || (p_mUID = (UFG::PrefabDB::PrefabRequest *)&v7[-1].mNULL.mUID) == 0i64 )
      {
        p_mUID = (UFG::PrefabDB::PrefabRequest *)UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
        if ( p_mUID )
          UFG::PrefabDB::PrefabRequest::PrefabRequest(p_mUID, prefabId, p_mCount);
      }
      ++p_mUID->mRefCount;
    }
  }
}

// File Line: 261
// RVA: 0x5131F0
void __fastcall UFG::PrefabDB::Unload(unsigned int prefabId)
{
  UFG::qBaseTreeRB *v1; // rax
  char *p_mUID; // rcx

  if ( prefabId )
  {
    v1 = UFG::qBaseTreeRB::Get(&UFG::PrefabDB::sPrefabRequests.mTree, prefabId);
    if ( v1 )
    {
      p_mUID = (char *)&v1[-1].mNULL.mUID;
      if ( v1 != (UFG::qBaseTreeRB *)16 && (*((_DWORD *)p_mUID + 2))-- == 1 )
        (**(void (__fastcall ***)(char *, __int64))p_mUID)(p_mUID, 1i64);
    }
  }
}

// File Line: 282
// RVA: 0x513230
void __fastcall UFG::PrefabDB::WaitForStreamer(unsigned int prefabId)
{
  UFG::qBaseTreeRB *v1; // rax
  UFG::PrefabDB::PrefabRequest *p_mUID; // rbx
  UFG *v3; // rcx

  if ( prefabId )
  {
    v1 = UFG::qBaseTreeRB::Get(&UFG::PrefabDB::sPrefabRequests.mTree, prefabId);
    if ( v1 )
    {
      p_mUID = (UFG::PrefabDB::PrefabRequest *)&v1[-1].mNULL.mUID;
      if ( v1 != (UFG::qBaseTreeRB *)16
        && !UFG::PrefabDB::PrefabRequest::IsLoaded((UFG::PrefabDB::PrefabRequest *)&v1[-1].mNULL.mUID) )
      {
        do
        {
          UFG::qFileService(v3);
          UFG::DataStreamer::Service(0.1);
        }
        while ( !UFG::PrefabDB::PrefabRequest::IsLoaded(p_mUID) );
      }
    }
  }
}

