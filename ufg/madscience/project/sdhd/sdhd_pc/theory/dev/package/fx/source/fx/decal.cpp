// File Line: 73
// RVA: 0x146B110
__int64 Render::_dynamic_initializer_for__gClipQueryManager__()
{
  `eh vector constructor iterator(
    (char *)Render::gClipQueryManager.mDecalClipQueryQueue,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gClipQueryManager__);
}

// File Line: 74
// RVA: 0x146B210
__int64 Render::_dynamic_initializer_for__gDecalManager__()
{
  UFG::qResourceHandle::qResourceHandle(&stru_14203EF08);
  dword_14203EF28[0] = 0;
  qword_14203EF78 = 0i64;
  unk_14203EF70 = 0i64;
  UFG::qMemSet(&unk_14203EF30, 0, 0x40u);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gDecalManager__);
}

// File Line: 76
// RVA: 0x146BB80
__int64 Render::_dynamic_initializer_for__sSDTextureUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("V_BulletHole01_D", -1);
  sSDTextureUID = result;
  return result;
}

// File Line: 77
// RVA: 0x146BB60
__int64 Render::_dynamic_initializer_for__sSDShaderUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("HK_Vehicle_Decal", -1);
  sSDShaderUID = result;
  return result;
}

// File Line: 78
// RVA: 0x146BB20
__int64 Render::_dynamic_initializer_for__sSDMatUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("SDMat", -1);
  sSDMatUID = result;
  return result;
}

// File Line: 81
// RVA: 0x146BB00
__int64 Render::_dynamic_initializer_for__sSDAlphaStateUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32(sSDAlphaStateName, 0xFFFFFFFF);
  sSDAlphaStateUID = result;
  return result;
}

// File Line: 83
// RVA: 0x146BB40
__int64 Render::_dynamic_initializer_for__sSDRasterStateUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32(sSDRasterStateName, 0xFFFFFFFF);
  sSDRasterStateUID = result;
  return result;
}

// File Line: 92
// RVA: 0x146BAD0
__int64 Render::_dynamic_initializer_for__sDebugDecalRadius__()
{
  UFG::qArray<Render::DebugDecalRadius,0>::Reallocate(
    &Render::sDebugDecalRadius,
    0xAu,
    "qArray.Reallocate(Constructor)");
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__sDebugDecalRadius__);
}

// File Line: 107
// RVA: 0x1C0F10
void __fastcall Render::DecalClipRequest::DecalClipRequest(Render::DecalClipRequest *this)
{
  UFG::qResourceHandle::qResourceHandle(&this->mSettingsHandle);
  Illusion::ModelProxy::ModelProxy(&this->mModelProxy);
  *(_QWORD *)&this->mRadius = 0i64;
  *(_QWORD *)&this->mOneOverNumPages = 0i64;
  this->mBindIndex = 0;
  this->mComponentPtr.mPrev = &this->mComponentPtr;
  this->mComponentPtr.mNext = &this->mComponentPtr;
  this->mComponentPtr.m_pPointer = 0i64;
  this->mScenery = 0i64;
  *(_QWORD *)&this->mSequenceId = 0i64;
  this->mIsValid = 1;
}

// File Line: 111
// RVA: 0x1D5C20
void __fastcall Render::DecalClipRequest::Reset(Render::DecalClipRequest *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_mComponentPtr; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  Inventory = `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::DecalSettings>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0xAE323146);
    `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mSettingsHandle, Inventory);
  p_mComponentPtr = &this->mComponentPtr;
  if ( this->mComponentPtr.m_pPointer )
  {
    mPrev = p_mComponentPtr->mPrev;
    mNext = this->mComponentPtr.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mComponentPtr->mPrev = p_mComponentPtr;
    this->mComponentPtr.mNext = &this->mComponentPtr;
  }
  this->mComponentPtr.m_pPointer = 0i64;
  this->mIsValid = 1;
}

// File Line: 118
// RVA: 0x1C4B40
Render::DecalClipRequest *__fastcall Render::DecalClipRequest::operator=(
        Render::DecalClipRequest *this,
        Render::DecalClipRequest *rhs)
{
  UFG::qVector4 v2; // xmm3
  UFG::qVector4 v3; // xmm2
  UFG::qVector4 v6; // xmm1
  UFG::qVector4 v7; // xmm3
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm1
  UFG::qResourceInventory *Inventory; // rax
  unsigned int mNameUID; // esi
  UFG::qResourceWarehouse *v12; // rax
  UFG::qResourceInventory *v13; // rax
  unsigned int v14; // ebp
  UFG::qResourceWarehouse *v15; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_mComponentPtr; // rdx
  UFG::SimComponent *m_pPointer; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax

  v2 = rhs->mMatrix.v1;
  v3 = rhs->mMatrix.v2;
  v6 = rhs->mMatrix.v3;
  this->mMatrix.v0 = rhs->mMatrix.v0;
  this->mMatrix.v1 = v2;
  this->mMatrix.v2 = v3;
  this->mMatrix.v3 = v6;
  v7 = rhs->mLocalToWorld.v1;
  v8 = rhs->mLocalToWorld.v2;
  v9 = rhs->mLocalToWorld.v3;
  this->mLocalToWorld.v0 = rhs->mLocalToWorld.v0;
  this->mLocalToWorld.v1 = v7;
  this->mLocalToWorld.v2 = v8;
  this->mLocalToWorld.v3 = v9;
  Inventory = `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result;
  mNameUID = rhs->mSettingsHandle.mNameUID;
  if ( !`UFG::qGetResourceInventory<Render::DecalSettings>::`2::result )
  {
    v12 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v12, 0xAE323146);
    `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mSettingsHandle, 0xAE323146, mNameUID, Inventory);
  v13 = `UFG::qGetResourceInventory<Illusion::Model>::`2::result;
  v14 = rhs->mModelProxy.mModelHandle.mNameUID;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>::`2::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    v13 = UFG::qResourceWarehouse::GetInventory(v15, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>::`2::result = v13;
  }
  UFG::qResourceHandle::Init(&this->mModelProxy.mModelHandle, 0xA2ADCD77, v14, v13);
  p_mComponentPtr = &this->mComponentPtr;
  this->mModelProxy.mRModel = rhs->mModelProxy.mRModel;
  this->mRadius = rhs->mRadius;
  this->mTexOffset = rhs->mTexOffset;
  this->mOneOverNumPages = rhs->mOneOverNumPages;
  this->mTextureOrientation = rhs->mTextureOrientation;
  this->mBindIndex = rhs->mBindIndex;
  m_pPointer = rhs->mComponentPtr.m_pPointer;
  if ( this->mComponentPtr.m_pPointer )
  {
    mPrev = p_mComponentPtr->mPrev;
    mNext = this->mComponentPtr.mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mComponentPtr->mPrev = p_mComponentPtr;
    this->mComponentPtr.mNext = &this->mComponentPtr;
  }
  this->mComponentPtr.m_pPointer = m_pPointer;
  if ( m_pPointer )
  {
    v20 = m_pPointer->m_SafePointerList.mNode.mPrev;
    v20->mNext = p_mComponentPtr;
    p_mComponentPtr->mPrev = v20;
    this->mComponentPtr.mNext = &m_pPointer->m_SafePointerList.mNode;
    m_pPointer->m_SafePointerList.mNode.mPrev = p_mComponentPtr;
  }
  this->mScenery = rhs->mScenery;
  this->mMeshProcessIndex = rhs->mMeshProcessIndex;
  this->mSequenceId = rhs->mSequenceId;
  return this;
}

// File Line: 144
// RVA: 0x1CDDA0
void __fastcall Render::DecalClipRequestQueue::Init(Render::DecalClipRequestQueue *this, unsigned int size)
{
  unsigned int v2; // r8d
  int v3; // eax
  __int64 v4; // rsi
  unsigned int capacity; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  __int64 v9; // rdi
  UFG::qResourceInventory *Inventory; // rax
  Render::DecalClipRequest *p; // rbx
  UFG::qResourceWarehouse *v12; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *p_mComponentPtr; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  v2 = this->mQueue.size;
  v3 = size - v2;
  v4 = size;
  if ( (int)(size - v2) <= 0 )
  {
    if ( v2 != size )
    {
      if ( v2 - size < v2 )
        this->mQueue.size = size;
      else
        this->mQueue.size = 0;
    }
  }
  else
  {
    capacity = this->mQueue.capacity;
    v7 = v2 + v3;
    if ( v2 + v3 > capacity )
    {
      if ( capacity )
        v8 = 2 * capacity;
      else
        v8 = 1;
      for ( ; v8 < v7; v8 *= 2 )
        ;
      if ( v8 - v7 > 0x10000 )
        v8 = v7 + 0x10000;
      UFG::qArray<Render::DecalClipRequest,0>::Reallocate(&this->mQueue, v8, "RequestQueue");
    }
    this->mQueue.size = v7;
  }
  if ( (_DWORD)v4 )
  {
    v9 = 0i64;
    do
    {
      Inventory = `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result;
      p = this->mQueue.p;
      if ( !`UFG::qGetResourceInventory<Render::DecalSettings>::`2::result )
      {
        v12 = UFG::qResourceWarehouse::Instance();
        Inventory = UFG::qResourceWarehouse::GetInventory(v12, 0xAE323146);
        `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result = Inventory;
      }
      UFG::qResourceHandle::Close(&p[v9].mSettingsHandle, Inventory);
      p_mComponentPtr = &p[v9].mComponentPtr;
      if ( p_mComponentPtr->m_pPointer )
      {
        mPrev = p_mComponentPtr->mPrev;
        mNext = p_mComponentPtr->mNext;
        mPrev->mNext = mNext;
        mNext->mPrev = mPrev;
        p_mComponentPtr->mPrev = p_mComponentPtr;
        p_mComponentPtr->mNext = p_mComponentPtr;
      }
      p_mComponentPtr->m_pPointer = 0i64;
      p[v9++].mIsValid = 1;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 174
// RVA: 0x1C68F0
void __fastcall Render::DecalClipRequestQueue::Add(
        Render::DecalClipRequestQueue *this,
        Render::DecalClipRequest *request)
{
  __int64 mTail; // r9
  unsigned int size; // r11d
  unsigned int mHead; // ecx
  unsigned int v7; // edi
  Render::DecalClipRequest *p; // r8
  unsigned int mSequenceId; // r10d
  unsigned int v10; // ecx
  unsigned int v11; // edx
  Render::DecalClipRequest *v12; // rcx
  __int64 v13; // rdi
  unsigned int v14; // eax

  mTail = this->mTail;
  size = this->mQueue.size;
  mHead = this->mHead;
  v7 = ((int)mTail + 1) % size;
  if ( v7 == mHead )
  {
    p = this->mQueue.p;
    mSequenceId = p[mHead].mSequenceId;
    if ( mHead != (_DWORD)mTail )
    {
      do
      {
        v10 = this->mHead;
        if ( mSequenceId != p[this->mHead].mSequenceId )
          break;
        --this->mCount;
        v11 = (v10 + 1) % size;
        this->mHead = v11;
      }
      while ( v11 != (_DWORD)mTail );
    }
  }
  v12 = this->mQueue.p;
  this->mTail = v7;
  v13 = mTail;
  Render::DecalClipRequest::Reset(&v12[mTail]);
  Render::DecalClipRequest::operator=(&this->mQueue.p[v13], request);
  v14 = ++this->mCount;
  if ( v14 > this->mHighWater )
    this->mHighWater = v14;
}

// File Line: 220
// RVA: 0x1CDB00
void __fastcall Render::DecalClipQueryManager::Init(
        Render::DecalClipQueryManager *this,
        unsigned int maxInFlightQueries,
        unsigned int maxQueuedQueries)
{
  __int64 v4; // r15
  unsigned int size; // r9d
  int v7; // eax
  unsigned int capacity; // edx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // edx
  __int64 v14; // rbx
  __int64 v15; // rbp
  Render::DecalClipQuery *p; // rdi
  Render::DecalClipQuery *v17; // r14
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // rax

  v4 = maxInFlightQueries;
  size = this->mDecalClipQueryQueue[0].size;
  v7 = maxInFlightQueries - size;
  if ( (int)(maxInFlightQueries - size) <= 0 )
  {
    if ( size != maxInFlightQueries )
    {
      if ( size - maxInFlightQueries < size )
        this->mDecalClipQueryQueue[0].size = maxInFlightQueries;
      else
        this->mDecalClipQueryQueue[0].size = 0;
    }
  }
  else
  {
    capacity = this->mDecalClipQueryQueue[0].capacity;
    if ( size + v7 > capacity )
    {
      if ( capacity )
        v10 = 2 * capacity;
      else
        v10 = 1;
      for ( ; v10 < maxInFlightQueries; v10 *= 2 )
        ;
      if ( v10 - maxInFlightQueries > 0x10000 )
        v10 = maxInFlightQueries + 0x10000;
      UFG::qArray<UFG::PartTextureData::Textures,0>::Reallocate(
        (UFG::qArray<UFG::PartTextureData::Textures,0> *)this->mDecalClipQueryQueue,
        v10,
        "DecalClipQueryManager");
    }
    this->mDecalClipQueryQueue[0].size = maxInFlightQueries;
  }
  v11 = this->mDecalClipQueryQueue[1].size;
  if ( (int)(v4 - v11) <= 0 )
  {
    if ( v11 != (_DWORD)v4 )
    {
      if ( v11 - (unsigned int)v4 < v11 )
        this->mDecalClipQueryQueue[1].size = v4;
      else
        this->mDecalClipQueryQueue[1].size = 0;
    }
  }
  else
  {
    v12 = this->mDecalClipQueryQueue[1].capacity;
    if ( (unsigned int)v4 > v12 )
    {
      if ( v12 )
        v13 = 2 * v12;
      else
        v13 = 1;
      for ( ; v13 < (unsigned int)v4; v13 *= 2 )
        ;
      if ( v13 - (unsigned int)v4 > 0x10000 )
        v13 = v4 + 0x10000;
      UFG::qArray<UFG::PartTextureData::Textures,0>::Reallocate(
        (UFG::qArray<UFG::PartTextureData::Textures,0> *)&this->mDecalClipQueryQueue[1],
        v13,
        "DecalClipQueryManager");
    }
    this->mDecalClipQueryQueue[1].size = v4;
  }
  if ( (_DWORD)v4 )
  {
    v14 = 0i64;
    v15 = v4;
    do
    {
      p = this->mDecalClipQueryQueue[0].p;
      v17 = this->mDecalClipQueryQueue[1].p;
      v18 = UFG::qMalloc(0x38ui64, "DecalClipInfo", 0x1000ui64);
      if ( v18 )
      {
        v18[1].mNext = v18 + 1;
        v18[2].mNext = v18 + 1;
        v18[3].mNext = 0i64;
      }
      else
      {
        v18 = 0i64;
      }
      p[v14].decal_info = (Render::DecalClipInfo *)v18;
      p[v14].task_params = (Render::DecalClipTaskParams *)UFG::qMalloc(0xB0ui64, "DecalTaskParams", 0x1000ui64);
      v19 = UFG::qMalloc(0xC50ui64, "DecalTaskResult", 0x1000ui64);
      if ( v19 )
        BYTE4(v19[393].mNext) = 0;
      else
        v19 = 0i64;
      p[v14].task_results = (Render::DecalClipTaskResults *)v19;
      v20 = UFG::qMalloc(0x38ui64, "DecalClipInfo", 0x1000ui64);
      if ( v20 )
      {
        v20[1].mNext = v20 + 1;
        v20[2].mNext = v20 + 1;
        v20[3].mNext = 0i64;
      }
      else
      {
        v20 = 0i64;
      }
      v17[v14].decal_info = (Render::DecalClipInfo *)v20;
      v17[v14].task_params = (Render::DecalClipTaskParams *)UFG::qMalloc(0xB0ui64, "DecalTaskParams", 0x1000ui64);
      v21 = UFG::qMalloc(0xC50ui64, "DecalTaskResult", 0x1000ui64);
      if ( v21 )
        BYTE4(v21[393].mNext) = 0;
      else
        v21 = 0i64;
      v17[v14++].task_results = (Render::DecalClipTaskResults *)v21;
      --v15;
    }
    while ( v15 );
  }
  this->mWriteDCQQ = 0;
  this->mReadDCQQ = 1;
  this->mDCQQCapacity = v4;
  Render::DecalClipRequestQueue::Init(&this->mClipQueue, maxQueuedQueries);
  this->mDecalClipQueryQueue[this->mWriteDCQQ].size = 0;
}

// File Line: 280
// RVA: 0x1CC560
UFG::PartTextureData::Textures *__fastcall Render::DecalClipQueryManager::GetNextWriteQuery(
        Render::DecalClipQueryManager *this)
{
  UFG::qArray<UFG::PartTextureData::Textures,0> *v1; // rdi
  __int64 size; // rsi
  unsigned int capacity; // edx
  unsigned int v4; // ebx
  unsigned int v5; // edx
  UFG::PartTextureData::Textures *p; // rax

  v1 = (UFG::qArray<UFG::PartTextureData::Textures,0> *)&this->mDecalClipQueryQueue[this->mWriteDCQQ];
  size = v1->size;
  capacity = v1->capacity;
  if ( (_DWORD)size == capacity )
    return 0i64;
  v4 = size + 1;
  if ( (int)size + 1 > capacity )
  {
    if ( capacity )
      v5 = 2 * capacity;
    else
      v5 = 1;
    for ( ; v5 < v4; v5 *= 2 )
      ;
    if ( v5 - v4 > 0x10000 )
      v5 = size + 65537;
    UFG::qArray<UFG::PartTextureData::Textures,0>::Reallocate(v1, v5, "qArray.Add");
  }
  p = v1->p;
  v1->size = v4;
  return &p[size];
}

// File Line: 343
// RVA: 0x1D1B00
char __fastcall Render::DecalClipQueryManager::ProcessClipRequest(
        Render::DecalClipQueryManager *this,
        Render::DecalClipRequest *clipRequest)
{
  Render::DecalClipQueryManager *v3; // r11
  UFG::qResourceData *mData; // r12
  int v5; // r9d
  unsigned int v6; // r10d
  unsigned int i; // r8d
  UFG::qResourceData *v8; // rax
  Illusion::rModel *mRModel; // rcx
  UFG::qBaseNodeRB *v10; // rcx
  UFG::qBaseNodeRB **v11; // rdx
  char *v12; // rsi
  Illusion::rModel *v13; // rax
  __int64 v14; // rbp
  __int64 v15; // rax
  __int64 v16; // rcx
  __int64 v17; // rax
  __int64 v18; // r13
  __int64 v19; // rax
  __int64 v20; // r14
  Illusion::Material *v21; // rdi
  __int64 v22; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v23; // rbx
  Illusion::Material *ParamByNameUID; // rax
  Illusion::Material *v25; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v27; // rcx
  char *v28; // rbx
  __int64 v29; // rax
  __int64 v30; // rax
  Illusion::TargetPlat *v31; // r12
  __int64 v32; // rax
  __int64 v33; // rcx
  __int64 v34; // rax
  __int64 v35; // rdi
  UFG::PartTextureData::Textures *v36; // rax
  Illusion::Target *mDiffuseTarget; // r14
  Illusion::Target *mNormTarget; // r13
  Illusion::Target *mSpecTarget; // rbx
  UFG::qVector4 v40; // xmm2
  UFG::qVector4 v41; // xmm1
  UFG::qVector4 v42; // xmm0
  UFG::qVector4 v43; // xmm2
  UFG::qVector4 v44; // xmm1
  UFG::qVector4 v45; // xmm0
  int v46; // eax
  float v47; // xmm0_4
  char *v48; // rax
  UFG::qTask *v49; // rdx
  _QWORD *v50; // rax
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r9
  char *mAddress; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTasks; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v57; // rax
  __int64 v59; // [rsp+20h] [rbp-78h]
  UFG::qResourceData *v60; // [rsp+28h] [rbp-70h]
  UFG::SimComponent *bind_ptr; // [rsp+30h] [rbp-68h]
  int v63; // [rsp+A8h] [rbp+10h]
  unsigned int v64; // [rsp+B0h] [rbp+18h]
  unsigned int v65; // [rsp+B8h] [rbp+20h]

  v3 = this;
  if ( clipRequest->mIsValid )
  {
    mData = clipRequest->mSettingsHandle.mData;
    v60 = mData;
    bind_ptr = clipRequest->mComponentPtr.m_pPointer;
    if ( (clipRequest->mModelProxy.mModelHandle.mData || clipRequest->mModelProxy.mRModel)
      && mData
      && clipRequest->mComponentPtr.m_pPointer )
    {
      v5 = 0;
      v63 = 0;
      v6 = this->mDCQQCapacity - this->mDecalClipQueryQueue[this->mWriteDCQQ].size;
      v65 = v6;
      for ( i = clipRequest->mMeshProcessIndex; ; ++i )
      {
        v64 = i;
        v8 = clipRequest->mModelProxy.mModelHandle.mData;
        if ( v8 )
        {
          LODWORD(mRModel) = v8[2].mNode.mChild[1];
        }
        else
        {
          mRModel = clipRequest->mModelProxy.mRModel;
          if ( mRModel )
            LODWORD(mRModel) = mRModel->mMeshes.mData.mNumItems;
        }
        if ( i >= (unsigned int)mRModel )
          break;
        if ( !v8 )
          goto LABEL_17;
        v10 = v8[2].mNode.mChild[0];
        if ( v10 )
          v10 = (UFG::qBaseNodeRB *)((char *)v10 + (_QWORD)v8 + 184);
        v11 = &v10->mParent + i;
        if ( *v11 )
          v12 = (char *)*v11 + (_QWORD)v11;
        else
LABEL_17:
          v12 = 0i64;
        v13 = clipRequest->mModelProxy.mRModel;
        if ( v13 )
          v14 = (__int64)&v13->mMeshes.mData.mItems[i];
        else
          v14 = 0i64;
        v15 = (__int64)(v12 + 96);
        if ( !v12 )
          v15 = v14 + 120;
        v16 = *(_QWORD *)(v15 + 16);
        v59 = v16;
        v17 = (__int64)(v12 + 64);
        if ( !v12 )
          v17 = v14 + 88;
        v18 = *(_QWORD *)(v17 + 16);
        v19 = (__int64)(v12 + 32);
        if ( !v12 )
          v19 = v14 + 56;
        v20 = *(_QWORD *)(v19 + 16);
        if ( v16 && v18 && v20 )
        {
          v21 = v12 ? (Illusion::Material *)*((_QWORD *)v12 + 2) : 0i64;
          v22 = v14 ? *(_QWORD *)(v14 + 48) : 0i64;
          v23 = 0i64;
          if ( v21 )
          {
            ParamByNameUID = Illusion::Material::GetParamByNameUID(v21, 0xEB98748F);
            if ( !ParamByNameUID || (v23 = ParamByNameUID->mResourceHandles.UFG::qResourceData::mNode.mPrev) == 0i64 )
            {
              v25 = Illusion::Material::GetParamByNameUID(v21, 0xDCE06689);
              if ( v25 )
              {
                mPrev = v25->mResourceHandles.UFG::qResourceData::mNode.mPrev;
                v27 = mPrev[7].mPrev;
                if ( v27 )
                  v28 = (char *)&v27[7] + (_QWORD)mPrev;
                else
                  v28 = 0i64;
                v23 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)*((_QWORD *)v28 + 2);
              }
            }
            v16 = v59;
            i = v64;
            v5 = v63;
            v6 = v65;
            v3 = this;
          }
          else if ( v22 )
          {
            v23 = *(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)(v22 + 128);
          }
          if ( (!HIDWORD(mData[2].mResourceHandles.mNode.mPrev) || v23 && LOBYTE(v23[5].mNext))
            && (!v23 || LODWORD(v23[1].mNext) != -303549566) )
          {
            if ( v5 == v6 )
            {
              clipRequest->mMeshProcessIndex = i;
              return 0;
            }
            v29 = *(_QWORD *)(v20 + 88);
            if ( v29 )
              v29 += v20 + 88;
            if ( *(_DWORD *)(v29 + 4) <= 1u )
            {
              v30 = *(_QWORD *)(v16 + 96);
              if ( v30 )
                v31 = (Illusion::TargetPlat *)(v16 + v30 + 96);
              else
                v31 = 0i64;
              v32 = *(_QWORD *)(v18 + 96);
              if ( v32 )
                v33 = v18 + v32 + 96;
              else
                v33 = 0i64;
              if ( v12 )
                v34 = *((unsigned int *)v12 + 57);
              else
                v34 = *(unsigned int *)(v14 + 252);
              v35 = v33 + 2 * v34;
              v36 = Render::DecalClipQueryManager::GetNextWriteQuery(v3);
              mDiffuseTarget = v36->mDiffuseTarget;
              mNormTarget = v36->mNormTarget;
              mSpecTarget = v36->mSpecTarget;
              *(_QWORD *)&mSpecTarget->mWidth = v60;
              LODWORD(mSpecTarget->mTargetTexture[3]) = clipRequest->mSequenceId;
              Render::DecalObjectLink::Set(
                (Render::DecalObjectLink *)&mSpecTarget->mTargetPlat,
                clipRequest->mBindIndex,
                bind_ptr,
                clipRequest->mScenery);
              BYTE4(mSpecTarget->mTargetTexture[3]) = clipRequest->mIsValid;
              v40 = clipRequest->mLocalToWorld.v1;
              v41 = clipRequest->mLocalToWorld.v2;
              v42 = clipRequest->mLocalToWorld.v3;
              *(UFG::qVector4 *)&mDiffuseTarget->mNumTargetTextures = clipRequest->mLocalToWorld.v0;
              *(UFG::qVector4 *)&mDiffuseTarget->mTargetTexture[1] = v40;
              *(UFG::qVector4 *)&mDiffuseTarget->mTargetTexture[3] = v41;
              *(UFG::qVector4 *)&mDiffuseTarget->mDepthTexture = v42;
              v43 = clipRequest->mMatrix.v1;
              v44 = clipRequest->mMatrix.v2;
              v45 = clipRequest->mMatrix.v3;
              *(UFG::qVector4 *)&mDiffuseTarget->mOwnsDepthTexture = clipRequest->mMatrix.v0;
              *(UFG::qVector4 *)&mDiffuseTarget->mDescription[15] = v43;
              *(UFG::qVector4 *)&mDiffuseTarget->mDescription[31] = v44;
              *(UFG::qVector4 *)&mDiffuseTarget[1].mTargetPlat = v45;
              *(_QWORD *)&mDiffuseTarget->mWidth = v35;
              mDiffuseTarget->mTargetPlat = v31;
              LODWORD(mDiffuseTarget[1].mTargetTexture[2]) = *(_DWORD *)(v59 + 104);
              *(float *)mDiffuseTarget[1].mTargetTexture = clipRequest->mTextureOrientation;
              HIDWORD(mDiffuseTarget[1].mTargetTexture[0]) = LODWORD(clipRequest->mTexOffset);
              *(float *)&mDiffuseTarget[1].mTargetTexture[1] = clipRequest->mOneOverNumPages;
              if ( v12 )
                v46 = *((_DWORD *)v12 + 58);
              else
                v46 = *(_DWORD *)(v14 + 256);
              HIDWORD(mDiffuseTarget[1].mTargetTexture[1]) = v46;
              mData = v60;
              v47 = *(float *)&v60[1].mDebugName[24];
              if ( v47 <= s_fMinDecalCutoffAdjust )
                v47 = s_fMinDecalCutoffAdjust;
              *((float *)&mDiffuseTarget[1].mTargetTexture[2] + 1) = v47;
              HIDWORD(mDiffuseTarget[1].mTargetTexture[3]) = *(_DWORD *)&v60[1].mDebugName[20];
              *(float *)&mDiffuseTarget[1].mTargetTexture[3] = clipRequest->mRadius;
              v48 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
              v49 = (UFG::qTask *)v48;
              if ( v48 )
              {
                *(_QWORD *)v48 = v48;
                *((_QWORD *)v48 + 1) = v48;
                v50 = v48 + 16;
                *v50 = v50;
                v50[1] = v50;
                mSpuElf = Render::gTaskFunctionDeclData_DecalClipTask.mSpuElf;
                mTaskFunctionSPU = Render::gTaskFunctionDeclData_DecalClipTask.mTaskFunctionSPU;
                mTaskFunctionPPU = Render::gTaskFunctionDeclData_DecalClipTask.mTaskFunctionPPU;
                mTaskFunctionOffload = Render::gTaskFunctionDeclData_DecalClipTask.mTaskFunctionOffload;
                if ( !Render::gTaskFunctionDeclData_DecalClipTask.mCurrentSPUEnabled )
                {
                  mSpuElf = 0i64;
                  mTaskFunctionSPU = 0i64;
                  mTaskFunctionOffload = 0i64;
                }
                v49->mTaskGroup = 0i64;
                v49->mFlags = 2;
                v49->mSyncVars.i64 = 0i64;
                v49->mSyncVars.v.mDependents = 0i64;
                v49->mFunctionDeclData = &Render::gTaskFunctionDeclData_DecalClipTask;
                if ( mSpuElf )
                  mAddress = mSpuElf->mAddress;
                else
                  mAddress = 0i64;
                v49->mSPUElfAddress = mAddress;
                v49->mSPUFunction = mTaskFunctionSPU;
                v49->mPPUFunction = mTaskFunctionPPU;
                v49->mParam0 = mDiffuseTarget;
                v49->mParam1 = mNormTarget;
                v49->mParam2 = 0i64;
                v49->mParam3 = 0i64;
                if ( mTaskFunctionOffload )
                {
                  v49->mFlags = 130;
                  v49->mOffloadThread = 0;
                }
              }
              mSingleFrameTasks = UFG::gTaskManager.mSingleFrameTasks;
              v57 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
              v57->mNext = v49;
              v49->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = v57;
              v49->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mSingleFrameTasks->mNode;
              mSingleFrameTasks->mNode.mPrev = v49;
              UFG::qTaskManager::Queue(&UFG::gTaskManager, v49);
              v5 = ++v63;
              i = v64;
            }
          }
        }
        v6 = v65;
        v3 = this;
      }
    }
  }
  return 1;
}

// File Line: 507
// RVA: 0x1DBD00
void __fastcall Render::DecalClipQueryManager::UpdateResults(Render::DecalClipQueryManager *this)
{
  __int64 v2; // rsi
  unsigned int size; // eax
  __int64 v4; // rdi
  __int64 v5; // rbp
  Render::DecalClipQuery *v6; // rbx
  Render::DecalClipTaskResults *task_results; // rax
  __int64 mWriteDCQQ; // rax

  v2 = 2 * (this->mReadDCQQ + 2i64);
  size = this->mDecalClipQueryQueue[this->mReadDCQQ].size;
  if ( size )
  {
    v4 = 0i64;
    v5 = size;
    do
    {
      v6 = (Render::DecalClipQuery *)(v4 + *((_QWORD *)&this->mClipQueue.mCount + v2));
      if ( v6 )
      {
        task_results = v6->task_results;
        if ( task_results )
        {
          if ( task_results->mResultReady && task_results->mNumPrims && v6->decal_info->mIsValid )
          {
            Render::DecalManager::AttachDecal(&Render::gDecalManager, v6);
            v6->task_results->mResultReady = 0;
          }
        }
      }
      v4 += 24i64;
      --v5;
    }
    while ( v5 );
  }
  this->mWriteDCQQ ^= 1u;
  mWriteDCQQ = this->mWriteDCQQ;
  this->mReadDCQQ ^= 1u;
  this->mDecalClipQueryQueue[mWriteDCQQ].size = 0;
}

// File Line: 531
// RVA: 0x1D0E80
void __fastcall Render::DecalClipQueryManager::Invalidate(
        Render::DecalClipQueryManager *this,
        Render::IDecalScenery *decal_scenery,
        unsigned int bindIndex)
{
  UFG::qArray<Render::DecalClipQuery,0> *mDecalClipQueryQueue; // r9
  __int64 v5; // rdi
  unsigned int v6; // r11d
  unsigned int i; // eax
  Render::DecalClipInfo *decal_info; // r8
  Render::DecalClipRequest *v9; // rax

  mDecalClipQueryQueue = this->mDecalClipQueryQueue;
  v5 = 2i64;
  v6 = 0;
  do
  {
    for ( i = 0; i < mDecalClipQueryQueue->size; ++i )
    {
      decal_info = mDecalClipQueryQueue->p[i].decal_info;
      if ( decal_info->mStoredObjLink.mScenery == decal_scenery
        && (bindIndex == -1 || decal_info->mStoredObjLink.mIndex == bindIndex) )
      {
        decal_info->mIsValid = 0;
      }
    }
    ++mDecalClipQueryQueue;
    --v5;
  }
  while ( v5 );
  if ( this->mClipQueue.mQueue.size )
  {
    do
    {
      v9 = &this->mClipQueue.mQueue.p[v6];
      if ( v9->mScenery == decal_scenery && (bindIndex == -1 || v9->mBindIndex == bindIndex) )
        v9->mIsValid = 0;
      ++v6;
    }
    while ( v6 < this->mClipQueue.mQueue.size );
  }
}

// File Line: 561
// RVA: 0x1CDA50
void __fastcall Render::DecalArray::Init(
        Render::DecalArray *this,
        unsigned int numDecals,
        unsigned int fragmentsPerDecal)
{
  unsigned int v4; // eax
  unsigned int i; // eax
  char *v6; // r8
  __int64 v7; // rdx
  _QWORD *v8; // rcx

  this->mDecalCount = numDecals;
  this->mFragmentsPerDecal = fragmentsPerDecal;
  v4 = 224 * fragmentsPerDecal + 64;
  this->mDecalStride = v4;
  this->mDecalDataBuffer = (char *)UFG::qMalloc(numDecals * v4, "DecalArray::Init", 0x1000ui64);
  for ( i = 0; i < this->mDecalCount; ++i )
  {
    v6 = &this->mDecalDataBuffer[i * this->mDecalStride];
    if ( v6 )
    {
      *(_QWORD *)v6 = v6;
      *((_QWORD *)v6 + 1) = v6;
      *((_QWORD *)v6 + 3) = 0i64;
      v7 = *(_QWORD *)v6;
      v8 = (_QWORD *)*((_QWORD *)v6 + 1);
      *(_QWORD *)(v7 + 8) = v8;
      *v8 = v7;
      *(_QWORD *)v6 = v6;
      *((_QWORD *)v6 + 1) = v6;
      *((_DWORD *)v6 + 13) = -1;
      *((_WORD *)v6 + 30) = 0;
    }
  }
}

// File Line: 628
// RVA: 0x1D2620
void __fastcall Render::IDecalScenery::RemoveAttachedDecals(Render::IDecalScenery *this, unsigned int bind_index)
{
  UFG::qNode<Render::Decal,Render::Decal> *mNext; // rbx
  UFG::qList<Render::Decal,Render::Decal,0,0> *i; // rsi
  UFG::qNode<Render::Decal,Render::Decal> *v6; // rcx
  UFG::qNode<Render::Decal,Render::Decal> *mPrev; // rbp
  UFG::qNode<Render::Decal,Render::Decal> *v8; // rcx
  UFG::qNode<Render::Decal,Render::Decal> *v9; // rax

  if ( bind_index != -1 )
    Render::DecalClipQueryManager::Invalidate(&Render::gClipQueryManager, this, bind_index);
  mNext = this->mAttachedDecals.mNode.mNext;
  for ( i = &this->mAttachedDecals; mNext != (UFG::qNode<Render::Decal,Render::Decal> *)i; mNext = mNext->mNext )
  {
    if ( bind_index == -1 || LODWORD(mNext[3].mPrev) == bind_index )
    {
      v6 = mNext[1].mNext;
      mPrev = mNext->mPrev;
      if ( v6 )
      {
        ((void (__fastcall *)(UFG::qNode<Render::Decal,Render::Decal> *, UFG::qNode<Render::Decal,Render::Decal> *))v6->mPrev->mNext)(
          v6,
          mNext);
        mNext[1].mNext = 0i64;
      }
      v8 = mNext->mPrev;
      v9 = mNext->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      HIDWORD(mNext[3].mPrev) = -1;
      WORD2(mNext[3].mNext) = 0;
      mNext = mPrev;
    }
  }
}

// File Line: 825
// RVA: 0x1D2830
void __fastcall Render::DecalArray::RemoveSequence(Render::DecalArray *this, unsigned int sequenceId)
{
  unsigned int i; // edi
  char *v5; // rbx
  __int64 v6; // rcx
  __int64 v7; // rcx
  _QWORD *v8; // rax

  for ( i = 0; i < this->mDecalCount; ++i )
  {
    v5 = &this->mDecalDataBuffer[i * this->mDecalStride];
    if ( *((_DWORD *)v5 + 13) == sequenceId )
    {
      v6 = *((_QWORD *)v5 + 3);
      if ( v6 )
      {
        (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v6 + 8i64))(
          v6,
          &this->mDecalDataBuffer[i * this->mDecalStride]);
        *((_QWORD *)v5 + 3) = 0i64;
      }
      v7 = *(_QWORD *)v5;
      v8 = (_QWORD *)*((_QWORD *)v5 + 1);
      *(_QWORD *)(v7 + 8) = v8;
      *v8 = v7;
      *(_QWORD *)v5 = v5;
      *((_QWORD *)v5 + 1) = v5;
      *((_DWORD *)v5 + 13) = -1;
      *((_WORD *)v5 + 30) = 0;
    }
  }
}

// File Line: 837
// RVA: 0x1D28D0
void __fastcall Render::DecalArray::RemoveSequenceAtIndex(Render::DecalArray *this, unsigned int startIndex)
{
  char *v4; // rbx
  __int64 v5; // rcx
  int v6; // esi
  _QWORD *v7; // rax
  __int64 v8; // rcx
  unsigned int v9; // ebp
  char *i; // rbx
  __int64 v11; // rcx
  _QWORD *v12; // rax
  __int64 v13; // rcx
  unsigned int v14; // ebp
  char *j; // rbx
  __int64 v16; // rcx
  _QWORD *v17; // rax
  __int64 v18; // rcx

  v4 = &this->mDecalDataBuffer[this->mDecalStride * startIndex];
  v5 = *((_QWORD *)v4 + 3);
  v6 = *((_DWORD *)v4 + 13);
  if ( v5 )
  {
    (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v5 + 8i64))(v5, v4);
    *((_QWORD *)v4 + 3) = 0i64;
  }
  v7 = (_QWORD *)*((_QWORD *)v4 + 1);
  v8 = *(_QWORD *)v4;
  *(_QWORD *)(v8 + 8) = v7;
  *v7 = v8;
  *(_QWORD *)v4 = v4;
  *((_QWORD *)v4 + 1) = v4;
  *((_DWORD *)v4 + 13) = -1;
  *((_WORD *)v4 + 30) = 0;
  v9 = (startIndex + 1) % this->mDecalCount;
  for ( i = &this->mDecalDataBuffer[this->mDecalStride * v9];
        *((_WORD *)i + 30);
        i = &this->mDecalDataBuffer[this->mDecalStride * v9] )
  {
    if ( *((_DWORD *)i + 13) != v6 )
      break;
    v11 = *((_QWORD *)i + 3);
    if ( v11 )
    {
      (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v11 + 8i64))(v11, i);
      *((_QWORD *)i + 3) = 0i64;
    }
    v12 = (_QWORD *)*((_QWORD *)i + 1);
    v13 = *(_QWORD *)i;
    *(_QWORD *)(v13 + 8) = v12;
    *v12 = v13;
    *(_QWORD *)i = i;
    *((_QWORD *)i + 1) = i;
    *((_DWORD *)i + 13) = -1;
    *((_WORD *)i + 30) = 0;
    v9 = (v9 + 1) % this->mDecalCount;
  }
  v14 = (startIndex - 1) % this->mDecalCount;
  for ( j = &this->mDecalDataBuffer[this->mDecalStride * v14];
        *((_WORD *)j + 30);
        j = &this->mDecalDataBuffer[this->mDecalStride * v14] )
  {
    if ( *((_DWORD *)j + 13) != v6 )
      break;
    v16 = *((_QWORD *)j + 3);
    if ( v16 )
    {
      (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v16 + 8i64))(v16, j);
      *((_QWORD *)j + 3) = 0i64;
    }
    v17 = (_QWORD *)*((_QWORD *)j + 1);
    v18 = *(_QWORD *)j;
    *(_QWORD *)(v18 + 8) = v17;
    *v17 = v18;
    *(_QWORD *)j = j;
    *((_QWORD *)j + 1) = j;
    *((_DWORD *)j + 13) = -1;
    *((_WORD *)j + 30) = 0;
    v14 = (v14 + 1) % this->mDecalCount;
  }
}

// File Line: 865
// RVA: 0x1C7630
__int64 __fastcall Render::DecalArray::AttachDecal(Render::DecalArray *this, Render::DecalClipQuery *dcq)
{
  unsigned int mCurDecal; // edx
  char *v5; // r13
  unsigned int v6; // ebx
  int v7; // esi
  unsigned int v8; // r14d
  Render::DecalClipTaskResults *task_results; // rax
  int v10; // r12d
  unsigned int v11; // ebx
  char *v12; // rdi
  Render::DecalClipInfo *decal_info; // rcx
  Render::IDecalScenery *mScenery; // rcx
  char **mNext; // r8
  __int64 result; // rax
  unsigned int v17; // [rsp+50h] [rbp+8h]

  mCurDecal = this->mCurDecal;
  v5 = &this->mDecalDataBuffer[this->mDecalStride * mCurDecal];
  v6 = *((_DWORD *)v5 + 13);
  v17 = v6;
  Render::DecalArray::RemoveSequenceAtIndex(this, mCurDecal);
  *((_DWORD *)v5 + 13) = -1;
  *(_QWORD *)v5 = v5;
  *((_QWORD *)v5 + 1) = v5;
  *((_WORD *)v5 + 30) = 0;
  *((_QWORD *)v5 + 3) = 0i64;
  v7 = 0;
  v8 = 0;
  *((_DWORD *)v5 + 13) = dcq->decal_info->mSequenceID;
  *((_WORD *)v5 + 30) = dcq->task_results->mNumPrims;
  *((_DWORD *)v5 + 14) = dcq->decal_info->mSettingsPtr->mNode.mUID;
  *((_QWORD *)v5 + 2) = dcq->decal_info->mSettingsPtr;
  task_results = dcq->task_results;
  if ( task_results->mNumPrims )
  {
    do
    {
      v10 = (unsigned __int8)task_results->mPrimVertCount[v8];
      v11 = 0;
      v12 = &this->mDecalDataBuffer[224 * v8 + 64 + this->mCurDecal * this->mDecalStride];
      for ( *((_DWORD *)v12 + 54) = v10; v11 < *((_DWORD *)v12 + 54); ++v11 )
        UFG::qMemCopy(&v12[24 * v11], &dcq->task_results->mVerts[v11 + v7], 0x18u);
      task_results = dcq->task_results;
      ++v8;
      v7 += v10;
    }
    while ( v8 < task_results->mNumPrims );
    v6 = v17;
  }
  decal_info = dcq->decal_info;
  if ( decal_info->mStoredObjLink.mComponentPtr.m_pPointer )
  {
    mScenery = decal_info->mStoredObjLink.mScenery;
    *((_QWORD *)v5 + 3) = mScenery;
    mNext = (char **)mScenery->mAttachedDecals.mNode.mNext;
    mScenery->mAttachedDecals.mNode.mNext = (UFG::qNode<Render::Decal,Render::Decal> *)v5;
    *((_QWORD *)v5 + 1) = mNext;
    *(_QWORD *)v5 = &mScenery->mAttachedDecals;
    *mNext = v5;
    mScenery->vfptr->OnAttachDecal(mScenery, (Render::Decal *)v5, dcq);
  }
  result = v6;
  this->mCurDecal = (this->mCurDecal + 1) % this->mDecalCount;
  return result;
}

// File Line: 958
// RVA: 0x1D3880
void __fastcall Render::DecalArray::Render(
        Render::DecalArray *this,
        Render::View *view,
        float fTime,
        Render::eFXDrawPass drawPass,
        __int16 decalStateBlockIndex,
        Illusion::Material *decalMat)
{
  unsigned int mDecalCount; // r12d
  Render::eFXDrawPass v7; // r8d
  unsigned int i; // ebp
  char *v11; // rbx
  unsigned __int8 (__fastcall ***v12)(_QWORD, char *, UFG::qMatrix44 *); // rcx
  char *v13; // rax
  _DWORD *v14; // rdx
  char *v15; // rsi
  Illusion::StateValues *StateValues; // rax
  unsigned int v17; // r8d
  _WORD *mOffset; // rax
  unsigned int v19; // r8d
  _WORD *v20; // rax
  unsigned int v21; // r8d
  _WORD *v22; // rax
  unsigned int v23; // r8d
  _WORD *v24; // rax
  unsigned int v25; // r8d
  _WORD *v26; // rax
  unsigned __int16 j; // si
  char *v28; // r9
  UFG::qMatrix44 local_world; // [rsp+40h] [rbp-68h] BYREF

  mDecalCount = this->mDecalCount;
  v7 = drawPass;
  for ( i = 0; i < mDecalCount; ++i )
  {
    v11 = &this->mDecalDataBuffer[i * this->mDecalStride];
    if ( *((_WORD *)v11 + 30) )
    {
      if ( *(_DWORD *)(*((_QWORD *)v11 + 2) + 192i64) == v7 )
      {
        v12 = (unsigned __int8 (__fastcall ***)(_QWORD, char *, UFG::qMatrix44 *))*((_QWORD *)v11 + 3);
        if ( v12 )
        {
          if ( (**v12)(v12, &this->mDecalDataBuffer[i * this->mDecalStride], &local_world) )
          {
            v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x10u);
            v14 = (_DWORD *)*((_QWORD *)v11 + 2);
            v15 = v13;
            *(_DWORD *)v13 = v14[22];
            *((_DWORD *)v13 + 1) = v14[23];
            *((_DWORD *)v13 + 2) = v14[24];
            *((_DWORD *)v13 + 3) = v14[25];
            *((_DWORD *)v13 + 4) = v14[26];
            *((_DWORD *)v13 + 5) = v14[27];
            *((_DWORD *)v13 + 6) = v14[28];
            *((_DWORD *)v13 + 7) = v14[29];
            StateValues = Render::View::GetStateValues(view);
            if ( (unsigned int)decalStateBlockIndex >= 0x40 )
              StateValues->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)decalStateBlockIndex - 64);
            else
              StateValues->mSetValueMask.mFlags[0] |= 1i64 << decalStateBlockIndex;
            StateValues->mParamValues[decalStateBlockIndex] = v15;
            v17 = *(_DWORD *)(*((_QWORD *)v11 + 2) + 128i64);
            if ( LODWORD(decalMat[1].mResourceHandles.UFG::qResourceData::mNode.mNext) != v17 )
            {
              UFG::qResourceHandle::Init(
                (UFG::qResourceHandle *)&decalMat[1].mNode.mChild[1],
                decalMat[1].mTypeUID,
                v17);
              mOffset = (_WORD *)decalMat->mMaterialUser.mOffset;
              if ( mOffset )
                mOffset = (_WORD *)((char *)mOffset + (_QWORD)decalMat + 120);
              *mOffset |= 0x20u;
            }
            v19 = *(_DWORD *)(*((_QWORD *)v11 + 2) + 132i64);
            if ( LODWORD(decalMat[1].mStateBlockMask.mFlags[0]) != v19 )
            {
              UFG::qResourceHandle::Init(
                (UFG::qResourceHandle *)&decalMat[1].mDebugName[20],
                decalMat[1].mStateBlockMask.mFlags[1],
                v19);
              v20 = (_WORD *)decalMat->mMaterialUser.mOffset;
              if ( v20 )
                v20 = (_WORD *)((char *)v20 + (_QWORD)decalMat + 120);
              *v20 |= 0x20u;
            }
            v21 = *(_DWORD *)(*((_QWORD *)v11 + 2) + 136i64);
            if ( decalMat[2].mNode.mUID != v21 )
            {
              UFG::qResourceHandle::Init(
                (UFG::qResourceHandle *)&decalMat[2],
                (unsigned int)decalMat[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
                v21);
              v22 = (_WORD *)decalMat->mMaterialUser.mOffset;
              if ( v22 )
                v22 = (_WORD *)((char *)v22 + (_QWORD)decalMat + 120);
              *v22 |= 0x20u;
            }
            v23 = *(_DWORD *)(*((_QWORD *)v11 + 2) + 120i64);
            if ( *(_DWORD *)&decalMat[2].mDebugName[28] != v23 )
            {
              UFG::qResourceHandle::Init(
                (UFG::qResourceHandle *)&decalMat[2].mDebugName[4],
                *((_DWORD *)&decalMat[2].UFG::qResourceData + 22),
                v23);
              v24 = (_WORD *)decalMat->mMaterialUser.mOffset;
              if ( v24 )
                v24 = (_WORD *)((char *)v24 + (_QWORD)decalMat + 120);
              *v24 |= 0x20u;
            }
            v25 = *(_DWORD *)(*((_QWORD *)v11 + 2) + 124i64);
            if ( LODWORD(decalMat[3].mNode.mChild[0]) != v25 )
            {
              UFG::qResourceHandle::Init(
                (UFG::qResourceHandle *)&decalMat[2].mNumParams,
                (unsigned int)decalMat[3].mNode.mChild[1],
                v25);
              v26 = (_WORD *)decalMat->mMaterialUser.mOffset;
              if ( v26 )
                v26 = (_WORD *)((char *)v26 + (_QWORD)decalMat + 120);
              *v26 |= 0x20u;
            }
            for ( j = 0; j < *((_WORD *)v11 + 30); ++j )
            {
              v28 = &this->mDecalDataBuffer[224 * j + 64 + i * this->mDecalStride];
              Render::DecalManager::DrawPrimitive(
                &Render::gDecalManager,
                view,
                TRIANGLEFAN,
                (Render::vDecal *)v28,
                *((_DWORD *)v28 + 54),
                decalMat,
                &local_world);
            }
          }
          v7 = drawPass;
        }
      }
    }
  }
}

// File Line: 1077
// RVA: 0x1CDF40
void __fastcall Render::DecalManager::Init(Render::DecalManager *this)
{
  UFG::qArray<Render::DecalArray,0> *p_mDecalBuckets; // rdi
  unsigned int size; // ecx
  __int64 v4; // rsi
  _WORD *v5; // rbp
  unsigned int capacity; // edx
  unsigned int v7; // edx
  __int64 v8; // rdi
  Render::DecalManager::DecalBucketConfig *v9; // rbx
  char *v10; // rax
  unsigned int v11; // esi
  Illusion::Material *v12; // rdi
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  int v17; // ebx
  int v18; // eax
  int v19; // ebx
  int v20; // eax
  int v21; // ebx
  unsigned int v22; // eax
  UFG::qResourceWarehouse *v23; // rax
  __int64 mOffset; // rax
  _WORD *v25; // rax
  __int64 v26; // rax
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v28; // rax

  Render::DecalClipQueryManager::Init(&Render::gClipQueryManager, 0x2Du, 0x100u);
  p_mDecalBuckets = &this->mDecalBuckets;
  this->mEnableDecals = 1;
  size = this->mDecalBuckets.size;
  v4 = 7i64;
  v5 = 0i64;
  if ( (int)(7 - size) <= 0 )
  {
    if ( size != 7 )
    {
      if ( size - 7 < size )
        p_mDecalBuckets->size = 7;
      else
        p_mDecalBuckets->size = 0;
    }
  }
  else
  {
    capacity = this->mDecalBuckets.capacity;
    if ( capacity < 7 )
    {
      if ( capacity )
        v7 = 2 * capacity;
      else
        v7 = 1;
      for ( ; v7 < 7; v7 *= 2 )
        ;
      if ( v7 - 7 > 0x10000 )
        v7 = 65543;
      UFG::qArray<Render::DecalArray,0>::Reallocate(p_mDecalBuckets, v7, "DecalBuckets");
    }
    p_mDecalBuckets->size = 7;
  }
  v8 = 0i64;
  v9 = Render::DecalManager::sDecalBucketConfig;
  do
  {
    Render::DecalArray::Init(
      &this->mDecalBuckets.p[v8++],
      458752 * v9->mMemoryPercentage / 0x64 / (224 * v9->mFragmentCount + 64),
      v9->mFragmentCount);
    ++v9;
    --v4;
  }
  while ( v4 );
  v10 = (char *)UFG::qMalloc(0x1FA0ui64, "DecalManager::SequenceIdLookup", 0x1000ui64);
  this->mSequenceIdToBucketMask = v10;
  UFG::qMemSet(v10, 0, 0x1FA0u);
  v11 = UFG::qStringHashUpper32("DecalMat", -1);
  v12 = Illusion::Factory::NewMaterial("DecalMat", v11, 6u, 0i64, 0i64, 0i64);
  v13 = UFG::qStringHash32("DR_DECAL", 0xFFFFFFFF);
  LOWORD(v12[1].mNode.mChild[0]) = 0;
  HIDWORD(v12[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v14 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v12[1].mTypeUID = -1957338719;
  LODWORD(v12[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = v13;
  LODWORD(v12[1].mNode.mParent) = v14;
  *(_WORD *)&v12[1].mDebugName[12] = 0;
  *(_DWORD *)&v12[1].mDebugName[8] = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  v15 = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
  LODWORD(v12[1].mStateBlockMask.mFlags[1]) = 315097330;
  LODWORD(v12[1].mStateBlockMask.mFlags[0]) = -1551679522;
  *(_DWORD *)&v12[1].mDebugName[4] = v15;
  LOWORD(v12[1].mMaterialUser.mOffset) = 0;
  *(&v12[1].mNumParams + 1) = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  v16 = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
  LODWORD(v12[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 1002903008;
  v12[2].mNode.mUID = -262489691;
  v12[1].mNumParams = v16;
  v17 = UFG::qStringHash32("DEFAULT", 0xFFFFFFFF);
  LOWORD(v12[2].mTypeUID) = 0;
  HIDWORD(v12[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v18 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v12[2].UFG::qResourceData + 22) = -1958479169;
  *(_DWORD *)&v12[2].mDebugName[28] = v17;
  LODWORD(v12[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = v18;
  v19 = UFG::qStringHash32("DEFAULT", 0xFFFFFFFF);
  LOWORD(v12[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v12[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v20 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v12[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v12[3].mNode.mChild[0]) = v19;
  LODWORD(v12[2].mStateBlockMask.mFlags[0]) = v20;
  v21 = UFG::qStringHashUpper32("c8c29f94-7308-4cd9-ba62-736f78fdeda6", -1);
  LOWORD(v12[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
  *(&v12[3].mNode.mUID + 1) = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  v22 = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  *(_DWORD *)&v12[3].mDebugName[20] = 1292158962;
  *(_DWORD *)&v12[3].mDebugName[12] = v21;
  v12[3].mNode.mUID = v22;
  v23 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v23, v12);
  if ( LODWORD(v12[1].mStateBlockMask.mFlags[0]) != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v12[1].mDebugName[20],
      v12[1].mStateBlockMask.mFlags[1],
      0x2782CCE6u);
    mOffset = v12->mMaterialUser.mOffset;
    if ( mOffset )
      v25 = (_WORD *)((char *)&v12->mMaterialUser + mOffset);
    else
      v25 = 0i64;
    *v25 |= 0x20u;
  }
  if ( v12[2].mNode.mUID != -262489691 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v12[2],
      (unsigned int)v12[2].mResourceHandles.UFG::qResourceData::mNode.mPrev,
      0xF05AB9A5);
    v26 = v12->mMaterialUser.mOffset;
    if ( v26 )
      v5 = (_WORD *)((char *)&v12->mMaterialUser + v26);
    *v5 |= 0x20u;
  }
  Inventory = `UFG::qGetResourceInventory<Illusion::Material>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>::`2::result )
  {
    v28 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v28, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&this->mDecalMat, 0xB4C26312, v11, Inventory);
  this->mStateBlockIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                               &Illusion::gStateSystem,
                                               "cbDecalSettings",
                                               0);
  UFG::qMemSet(Render::DecalManager::sDecalFragmentCountHistogram, 0, 0xA8u);
}

// File Line: 1182
// RVA: 0x1CB0A0
void __fastcall Render::DecalManager::DestroyDecals(Render::DecalManager *this)
{
  unsigned int size; // eax
  __int64 v3; // r10
  __int64 v4; // r9
  unsigned int v5; // eax
  Render::DecalArray *v6; // r8
  __int64 v7; // rdx
  unsigned int mHead; // edx
  unsigned int mCount; // ecx

  size = this->mDecalBuckets.size;
  if ( size )
  {
    v3 = size;
    v4 = 0i64;
    do
    {
      v5 = 0;
      v6 = &this->mDecalBuckets.p[v4];
      if ( v6->mDecalCount )
      {
        do
        {
          v7 = v5 * v6->mDecalStride;
          ++v5;
          *(_WORD *)&v6->mDecalDataBuffer[v7 + 60] = 0;
        }
        while ( v5 < v6->mDecalCount );
      }
      ++v4;
      --v3;
    }
    while ( v3 );
  }
  mHead = Render::gClipQueryManager.mClipQueue.mHead;
  if ( Render::gClipQueryManager.mClipQueue.mHead != Render::gClipQueryManager.mClipQueue.mTail )
  {
    mCount = Render::gClipQueryManager.mClipQueue.mCount;
    do
    {
      --mCount;
      mHead = (mHead + 1) % Render::gClipQueryManager.mClipQueue.mQueue.size;
    }
    while ( mHead != Render::gClipQueryManager.mClipQueue.mTail );
    Render::gClipQueryManager.mClipQueue.mHead = mHead;
    Render::gClipQueryManager.mClipQueue.mCount = mCount;
  }
  UFG::qMemSet(this->mSequenceIdToBucketMask, 0, 0x1FA0u);
}

// File Line: 1262
// RVA: 0x1C9520
void __fastcall Render::DecalManager::CreateDecal(
        Render::DecalManager *this,
        unsigned int decalId,
        UFG::qVector3 *vPos,
        UFG::qVector3 *vNormal)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceData *mData; // rsi
  float v11; // xmm10_4
  __m128 v12; // xmm3
  float v13; // xmm9_4
  __m128 v14; // xmm2
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm9_4
  float v18; // xmm10_4
  float v19; // xmm3_4
  float y; // xmm6_4
  float x; // xmm7_4
  float z; // xmm8_4
  __m128 x_low; // xmm14
  float v24; // xmm15_4
  __m128 z_low; // xmm2
  __m128 v26; // xmm3
  float v27; // xmm0_4
  float v28; // xmm15_4
  float v29; // xmm14_4
  float v30; // xmm13_4
  float v31; // xmm12_4
  float v32; // xmm11_4
  float v33; // xmm6_4
  float v34; // xmm7_4
  float v35; // xmm0_4
  float v36; // xmm8_4
  float v37; // xmm12_4
  float v38; // xmm13_4
  float v39; // xmm11_4
  unsigned int mUID; // ecx
  unsigned int v41; // ecx
  float v42; // xmm8_4
  float v43; // xmm7_4
  float v44; // xmm6_4
  float v45; // xmm9_4
  float v46; // xmm1_4
  float v47; // xmm6_4
  float v48; // xmm8_4
  float v49; // xmm2_4
  float v50; // xmm2_4
  int v51; // xmm2_4
  unsigned int v52; // ebx
  unsigned int v53; // esi
  UFG::qResourceInventory *v54; // rax
  UFG::qResourceWarehouse *v55; // rax
  __int64 mHead; // rdx
  UFG::qResourceInventory *v57; // rax
  UFG::qResourceWarehouse *v58; // rax
  float v59; // [rsp+20h] [rbp-C8h]
  float v60; // [rsp+24h] [rbp-C4h]
  UFG::qVector4 v61; // [rsp+30h] [rbp-B8h]
  UFG::qVector4 v62; // [rsp+40h] [rbp-A8h]
  UFG::qVector4 v63; // [rsp+50h] [rbp-98h]
  UFG::qVector4 v64; // [rsp+60h] [rbp-88h]
  UFG::qResourceHandle v65; // [rsp+70h] [rbp-78h] BYREF
  __int64 v66; // [rsp+90h] [rbp-58h]
  Render::DecalClipRequest v67; // [rsp+98h] [rbp-50h] BYREF
  void *p_mSettingsHandle; // [rsp+268h] [rbp+180h]
  float *v69; // [rsp+288h] [rbp+1A0h]

  v66 = -2i64;
  if ( !this->mEnableDecals )
    return;
  UFG::qResourceHandle::qResourceHandle(&v65);
  Inventory = `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::DecalSettings>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v9, 0xAE323146);
    `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(&v65, 0xAE323146, decalId, Inventory);
  mData = v65.mData;
  if ( v65.mData )
  {
    v11 = v69[1];
    v12 = (__m128)*(unsigned int *)v69;
    v13 = v69[2];
    v14 = v12;
    v14.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
    v15 = 0.0;
    if ( v14.m128_f32[0] == 0.0 )
      v16 = 0.0;
    else
      v16 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
    v17 = v13 * v16;
    v18 = v11 * v16;
    v19 = v12.m128_f32[0] * v16;
    v59 = *((float *)&v65.mData[2].mNode.mUID + 1);
    v60 = *(float *)&v65.mData[2].mResourceHandles.mNode.mPrev;
    y = vNormal->y;
    x = vNormal->x;
    z = vNormal->z;
    x_low = (__m128)LODWORD(vNormal->x);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v19 * vNormal->x) + (float)(y * v18)) + (float)(z * v17)) & _xmm) >= 0.99000001 )
    {
      z_low = (__m128)LODWORD(vNormal->z);
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                          (float)((float)(x * UFG::qVector3::msAxisY.x) + (float)(y * UFG::qVector3::msAxisY.y))
                        + (float)(z * UFG::qVector3::msAxisY.z)) & _xmm) >= 0.99000001 )
      {
        v24 = (float)(y * UFG::qVector3::msAxisZ.x) - (float)(x * UFG::qVector3::msAxisZ.y);
        x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * UFG::qVector3::msAxisZ.z)
                          - (float)(z * UFG::qVector3::msAxisZ.x);
        z_low.m128_f32[0] = (float)(z * UFG::qVector3::msAxisZ.y) - (float)(y * UFG::qVector3::msAxisZ.z);
        v26 = x_low;
        v26.m128_f32[0] = x_low.m128_f32[0] * x_low.m128_f32[0];
        v27 = z_low.m128_f32[0] * z_low.m128_f32[0];
      }
      else
      {
        v24 = (float)(y * UFG::qVector3::msAxisY.x) - (float)(x * UFG::qVector3::msAxisY.y);
        x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * UFG::qVector3::msAxisY.z)
                          - (float)(z * UFG::qVector3::msAxisY.x);
        z_low.m128_f32[0] = (float)(z * UFG::qVector3::msAxisY.y) - (float)(y * UFG::qVector3::msAxisY.z);
        v26 = z_low;
        v26.m128_f32[0] = z_low.m128_f32[0] * z_low.m128_f32[0];
        v27 = x_low.m128_f32[0] * x_low.m128_f32[0];
      }
    }
    else
    {
      v24 = (float)(v19 * y) - (float)(x * v18);
      x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * v17) - (float)(v19 * z);
      z_low = (__m128)LODWORD(vNormal->z);
      z_low.m128_f32[0] = (float)(z * v18) - (float)(y * v17);
      v26 = z_low;
      v26.m128_f32[0] = z_low.m128_f32[0] * z_low.m128_f32[0];
      v27 = x_low.m128_f32[0] * x_low.m128_f32[0];
    }
    v26.m128_f32[0] = (float)(v26.m128_f32[0] + v27) + (float)(v24 * v24);
    if ( v26.m128_f32[0] != 0.0 )
      v15 = 1.0 / _mm_sqrt_ps(v26).m128_f32[0];
    v28 = v24 * v15;
    v29 = x_low.m128_f32[0] * v15;
    *(float *)&p_mSettingsHandle = z_low.m128_f32[0] * v15;
    v30 = (float)((float)(z_low.m128_f32[0] * v15) * y) - (float)(v29 * x);
    v31 = (float)(v28 * x) - (float)((float)(z_low.m128_f32[0] * v15) * z);
    v32 = (float)(v29 * z) - (float)(v28 * y);
    v33 = (float)((float)(v60 - v59) * UFG::qRandom(1.0, (unsigned int *)&UFG::qDefaultSeed)) + v59;
    v34 = sinf(v33);
    v35 = cosf(v33);
    v36 = vNormal->z;
    *(_QWORD *)&v63.x = *(_QWORD *)&vNormal->x;
    *(_QWORD *)&v63.z = LODWORD(v36);
    v61.x = (float)(*(float *)&p_mSettingsHandle * v35) - (float)(v32 * v34);
    v61.y = (float)(v29 * v35) - (float)(v31 * v34);
    v61.z = (float)(v28 * v35) - (float)(v30 * v34);
    v61.w = 0.0;
    v62.x = (float)(v32 * v35) + (float)(*(float *)&p_mSettingsHandle * v34);
    v62.y = (float)(v29 * v34) + (float)(v31 * v35);
    *(_QWORD *)&v62.z = COERCE_UNSIGNED_INT((float)(v28 * v34) + (float)(v30 * v35));
    v37 = vPos->z - (float)(v36 * 0.15000001);
    v38 = vPos->y - (float)(COERCE_FLOAT(HIDWORD(*(_QWORD *)&vNormal->x)) * 0.15000001);
    v39 = vPos->x - (float)(vNormal->x * 0.15000001);
    v64.x = v39;
    v64.y = v38;
    mUID = mData[2].mNode.mUID;
    if ( !mUID )
      goto LABEL_21;
    v41 = mUID - 1;
    if ( !v41 )
    {
      v43 = 0.0;
      v42 = *(float *)&FLOAT_1_0;
      goto LABEL_23;
    }
    if ( v41 == 2 )
    {
      v42 = *(float *)&FLOAT_1_0;
      if ( !(unsigned int)UFG::qRandom(2u, (unsigned int *)&UFG::qDefaultSeed) )
      {
        v43 = 0.0;
LABEL_23:
        v44 = *(float *)&mData[1].mDebugName[12];
        v45 = (float)(UFG::qRandom(v42, (unsigned int *)&UFG::qDefaultSeed)
                    * (float)(*(float *)&mData[1].mDebugName[16] - v44))
            + v44;
        v46 = (float)SHIDWORD(mData[2].mNode.mChild[1]);
        if ( v46 < v42 )
          v46 = v42;
        v47 = (float)(int)UFG::qRandom((int)v46, (unsigned int *)&UFG::qDefaultSeed);
        v48 = v42 / (float)(int)v46;
        v49 = *(float *)&mData[1].mDebugName[20];
        if ( v49 <= (float)(v45 * 2.0) )
          v49 = v45 * 2.0;
        v50 = v49 * 0.5;
        *((float *)&v65.mNext + 1) = v39 + v50;
        v64.z = v50 + v38;
        v64.w = v50 + v37;
        v51 = LODWORD(v50) ^ _xmm[0];
        *(float *)&v65.mPrev = v39 + *(float *)&v51;
        *((float *)&v65.mPrev + 1) = *(float *)&v51 + v38;
        *(float *)&v65.mNext = *(float *)&v51 + v37;
        p_mSettingsHandle = &v67.mSettingsHandle;
        UFG::qResourceHandle::qResourceHandle(&v67.mSettingsHandle);
        Illusion::ModelProxy::ModelProxy(&v67.mModelProxy);
        memset(&v67.mRadius, 0, 20);
        v52 = 0;
        p_mSettingsHandle = &v67.mComponentPtr;
        v67.mComponentPtr.mPrev = &v67.mComponentPtr;
        v67.mComponentPtr.mNext = &v67.mComponentPtr;
        memset(&v67.mComponentPtr.m_pPointer, 0, 24);
        v67.mIsValid = 1;
        v67.mMatrix.v0 = v61;
        v67.mMatrix.v1 = v62;
        v67.mMatrix.v2 = v63;
        v67.mMatrix.v3 = v64;
        v53 = mData->mNode.mUID;
        v54 = `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result;
        if ( !`UFG::qGetResourceInventory<Render::DecalSettings>::`2::result )
        {
          v55 = UFG::qResourceWarehouse::Instance();
          v54 = UFG::qResourceWarehouse::GetInventory(v55, 0xAE323146);
          `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result = v54;
        }
        UFG::qResourceHandle::Init(&v67.mSettingsHandle, 0xAE323146, v53, v54);
        v67.mRadius = v45;
        v67.mTexOffset = v47;
        v67.mOneOverNumPages = v48;
        v67.mTextureOrientation = v43;
        v67.mBindIndex = 0;
        v67.mSequenceId = this->mCurSequenceID;
        Render::DecalManager::ProcessClipQueue(this);
        if ( this->mNumTestSceneryCallbacks )
        {
          do
          {
            this->mTestSceneryCallback[v52](&v67, (UFG::qBox *)&v65);
            mHead = Render::gClipQueryManager.mClipQueue.mHead;
            if ( Render::gClipQueryManager.mClipQueue.mHead != Render::gClipQueryManager.mClipQueue.mTail )
            {
              do
              {
                if ( !Render::DecalClipQueryManager::ProcessClipRequest(
                        &Render::gClipQueryManager,
                        &Render::gClipQueryManager.mClipQueue.mQueue.p[mHead]) )
                  break;
                mHead = (Render::gClipQueryManager.mClipQueue.mHead + 1)
                      % Render::gClipQueryManager.mClipQueue.mQueue.size;
                Render::gClipQueryManager.mClipQueue.mHead = mHead;
                --Render::gClipQueryManager.mClipQueue.mCount;
              }
              while ( (_DWORD)mHead != Render::gClipQueryManager.mClipQueue.mTail );
            }
            ++v52;
          }
          while ( v52 < this->mNumTestSceneryCallbacks );
        }
        this->mCurSequenceID = v67.mSequenceId;
        Render::DecalClipRequest::~DecalClipRequest(&v67);
        goto LABEL_35;
      }
    }
    else
    {
LABEL_21:
      v42 = *(float *)&FLOAT_1_0;
    }
    v43 = v42;
    goto LABEL_23;
  }
LABEL_35:
  v57 = `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::DecalSettings>::`2::result )
  {
    v58 = UFG::qResourceWarehouse::Instance();
    v57 = UFG::qResourceWarehouse::GetInventory(v58, 0xAE323146);
    `UFG::qGetResourceInventory<Render::DecalSettings>::`2::result = v57;
  }
  UFG::qResourceHandle::Close(&v65, v57);
  UFG::qResourceHandle::~qResourceHandle(&v65);
}

// File Line: 1372
// RVA: 0x1C6B90
void __fastcall Render::DecalManager::AddClipQueue(Render::DecalManager *this, Render::DecalClipRequest *request)
{
  Render::DecalClipRequestQueue::Add(&Render::gClipQueryManager.mClipQueue, request);
  request->mSequenceId = (request->mSequenceId + 1) % 0x1FA0;
}

// File Line: 1379
// RVA: 0x1C77E0
void __fastcall Render::DecalManager::AttachDecal(Render::DecalManager *this, Render::DecalClipQuery *dcq)
{
  unsigned int size; // ebp
  __int64 v3; // rdi
  unsigned int mNumPrims; // r9d
  __int64 mSequenceID; // r14
  unsigned int v7; // ebx
  unsigned int v8; // eax
  Render::DecalManager::DecalBucketConfig *v9; // rcx
  unsigned int v10; // eax
  __int64 v11; // r15
  char v12; // r9
  int v13; // ebx

  size = this->mDecalBuckets.size;
  v3 = 0i64;
  mNumPrims = dcq->task_results->mNumPrims;
  mSequenceID = dcq->decal_info->mSequenceID;
  ++Render::DecalManager::sDecalFragmentCountHistogram[mNumPrims - 1];
  v7 = 0;
  v8 = 0;
  if ( size )
  {
    v9 = Render::DecalManager::sDecalBucketConfig;
    while ( mNumPrims > v9->mFragmentCount )
    {
      ++v8;
      ++v9;
      if ( v8 >= size )
        goto LABEL_7;
    }
    v7 = v8;
  }
LABEL_7:
  v10 = Render::DecalArray::AttachDecal(&this->mDecalBuckets.p[v7], dcq);
  v11 = v10;
  this->mSequenceIdToBucketMask[mSequenceID] |= 1 << v7;
  if ( v10 != -1 )
  {
    v12 = ~(1 << v7);
    v13 = 1;
    this->mSequenceIdToBucketMask[v10] &= v12;
    if ( size )
    {
      do
      {
        if ( ((unsigned __int8)v13 & this->mSequenceIdToBucketMask[v11]) != 0 )
        {
          Render::DecalArray::RemoveSequence(&this->mDecalBuckets.p[v3], v11);
          this->mSequenceIdToBucketMask[v11] &= ~(1 << v3);
        }
        v13 = __ROL4__(v13, 1);
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < size );
    }
  }
}

// File Line: 1432
// RVA: 0x1D1AA0
void __fastcall Render::DecalManager::ProcessClipQueue(Render::DecalManager *this)
{
  __int64 i; // rdx

  for ( i = Render::gClipQueryManager.mClipQueue.mHead;
        Render::gClipQueryManager.mClipQueue.mHead != Render::gClipQueryManager.mClipQueue.mTail;
        i = Render::gClipQueryManager.mClipQueue.mHead )
  {
    if ( !Render::DecalClipQueryManager::ProcessClipRequest(
            &Render::gClipQueryManager,
            &Render::gClipQueryManager.mClipQueue.mQueue.p[i]) )
      break;
    --Render::gClipQueryManager.mClipQueue.mCount;
    Render::gClipQueryManager.mClipQueue.mHead = (Render::gClipQueryManager.mClipQueue.mHead + 1)
                                               % Render::gClipQueryManager.mClipQueue.mQueue.size;
  }
}

// File Line: 1437
// RVA: 0x1D3B50
void __fastcall Render::DecalManager::Render(
        Render::DecalManager *this,
        Render::View *view,
        float fTime,
        Render::eFXDrawPass drawPass)
{
  Illusion::Material *decalMat; // rbp
  unsigned int size; // eax
  __int64 v9; // rdi
  __int64 v10; // rsi

  decalMat = (Illusion::Material *)this->mDecalMat.mData;
  if ( decalMat )
  {
    Render::DecalClipQueryManager::UpdateResults(&Render::gClipQueryManager);
    size = this->mDecalBuckets.size;
    if ( size )
    {
      v9 = 0i64;
      v10 = size;
      do
      {
        Render::DecalArray::Render(
          &this->mDecalBuckets.p[v9++],
          view,
          fTime,
          drawPass,
          this->mStateBlockIndex,
          decalMat);
        --v10;
      }
      while ( v10 );
    }
  }
}

// File Line: 1494
// RVA: 0x1CCF10
__int64 __fastcall Render::DecalManager::GetSkinnedDecalMaterialUID(Render::DecalManager *this)
{
  unsigned int v1; // ebx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceData *v4; // rbx
  UFG::qResourceWarehouse *v5; // rax
  Illusion::Material *v6; // rdi
  UFG::qResourceWarehouse *v7; // rax

  if ( (_S1_24 & 1) == 0 )
  {
    _S1_24 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&decal_tex);
    atexit(Render::DecalManager::GetSkinnedDecalMaterialUID_::_2_::_dynamic_atexit_destructor_for__decal_tex__);
  }
  if ( !material_init )
  {
    material_init = 1;
    v1 = sSDTextureUID;
    Inventory = `UFG::qGetResourceInventory<Illusion::Texture>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>::`2::result )
    {
      v3 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&decal_tex, 0x8B43FABF, v1, Inventory);
    v4 = Illusion::Factory::NewRasterState(sSDRasterStateName, sSDRasterStateUID, 0i64, 0i64, 0i64);
    LOWORD(v4[1].mNode.mParent) = 1;
    BYTE2(v4[1].mNode.mParent) = 3;
    HIWORD(v4[1].mNode.mParent) = 0;
    v5 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v5, v4);
    v6 = Illusion::Factory::NewMaterial(sSDMatName, sSDMatUID, 9u, 0i64, 0i64, 0i64);
    LODWORD(v4) = sSDShaderUID;
    LOWORD(v6[1].mNode.mChild[0]) = 0;
    HIDWORD(v6[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
    LODWORD(v6[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
    v6[1].mTypeUID = -1957338719;
    LODWORD(v6[1].mResourceHandles.UFG::qResourceData::mNode.mNext) = (_DWORD)v4;
    LODWORD(v4) = UFG::qStringHashUpper32("V_BulletHole01_D", -1);
    *(_WORD *)&v6[1].mDebugName[12] = 0;
    *(_DWORD *)&v6[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    *(_DWORD *)&v6[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
    LODWORD(v6[1].mStateBlockMask.mFlags[1]) = -1958479169;
    LODWORD(v6[1].mStateBlockMask.mFlags[0]) = (_DWORD)v4;
    LODWORD(v4) = UFG::qStringHashUpper32("V_BulletHole01_S", -1);
    LOWORD(v6[1].mMaterialUser.mOffset) = 0;
    *(&v6[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    v6[1].mNumParams = UFG::qStringHash32("texSpecular", 0xFFFFFFFF);
    LODWORD(v6[2].mResourceHandles.UFG::qResourceData::mNode.mPrev) = -1958479169;
    v6[2].mNode.mUID = (unsigned int)v4;
    LODWORD(v4) = UFG::qStringHashUpper32("V_BulletHole01_N", -1);
    LOWORD(v6[2].mTypeUID) = 0;
    HIDWORD(v6[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    LODWORD(v6[2].mResourceHandles.UFG::qResourceData::mNode.mNext) = UFG::qStringHash32("texBump", 0xFFFFFFFF);
    *((_DWORD *)&v6[2].UFG::qResourceData + 22) = -1958479169;
    *(_DWORD *)&v6[2].mDebugName[28] = (_DWORD)v4;
    LODWORD(v4) = UFG::qStringHash32("SPHERICALENVMAPMAIN", 0xFFFFFFFF);
    LOWORD(v6[2].mStateBlockMask.mFlags[1]) = 0;
    HIDWORD(v6[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    LODWORD(v6[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texSphericalMap", 0xFFFFFFFF);
    LODWORD(v6[3].mNode.mChild[1]) = -1958479169;
    LODWORD(v6[3].mNode.mChild[0]) = (_DWORD)v4;
    LOWORD(v6[3].mResourceHandles.UFG::qResourceData::mNode.mPrev) = 0;
    *(&v6[3].mNode.mUID + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    v6[3].mNode.mUID = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    *(_DWORD *)&v6[3].mDebugName[20] = 315097330;
    *(_DWORD *)&v6[3].mDebugName[12] = 662883558;
    LODWORD(v4) = sSDRasterStateUID;
    *((_WORD *)&v6[3].UFG::qResourceData + 44) = 0;
    *(_DWORD *)&v6[3].mDebugName[32] = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    *(_DWORD *)&v6[3].mDebugName[28] = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    LODWORD(v6[4].mNode.mParent) = 1002903008;
    LODWORD(v6[3].mMaterialUser.mOffset) = (_DWORD)v4;
    LODWORD(v4) = UFG::qStringHashUpper32("c8c29f94-7308-4cd9-ba62-736f78fdeda6", -1);
    LOWORD(v6[4].mNode.mChild[1]) = 0;
    HIDWORD(v6[4].mNode.mChild[0]) = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
    LODWORD(v6[4].mNode.mChild[0]) = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
    *(_DWORD *)&v6[4].mDebugName[4] = 1292158962;
    v6[4].mTypeUID = (unsigned int)v4;
    LODWORD(v4) = UFG::qStringHashUpper32("d513fc25-10a4-4480-84d0-13aeef7d27bd", -1);
    *(_WORD *)&v6[4].mDebugName[20] = 0;
    *(_DWORD *)&v6[4].mDebugName[16] = UFG::qStringHash32("sbVehicleLook", 0xFFFFFFFF);
    *(_DWORD *)&v6[4].mDebugName[12] = UFG::qStringHash32("sbVehicleLook", 0xFFFFFFFF);
    v6[4].mNumParams = 1292158962;
    LODWORD(v6[4].mStateBlockMask.mFlags[1]) = (_DWORD)v4;
    v7 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v7, v6);
  }
  return sSDMatUID;
}

// File Line: 1543
// RVA: 0x1CB7E0
void __fastcall Render::DecalManager::DrawPrimitive(
        Render::DecalManager *this,
        Render::View *view,
        Illusion::Primitive::Type prim_type,
        Render::vDecal *vertices,
        int num_vertices,
        Illusion::Material *material,
        UFG::qMatrix44 *local_world)
{
  Illusion::StateArgs *StateArgs; // r15
  unsigned int v10; // edi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v12; // rax
  Illusion::Primitive *v13; // r13
  char *v14; // rax
  Render::vDecal *v15; // rsi
  unsigned __int16 Param; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mPrev; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *mNext; // rax
  unsigned __int64 *v19; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v20; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v21; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rax
  Render::cbLocalTransformState arg; // [rsp+48h] [rbp-59h] BYREF
  Render::cbLocalProjectionState v27; // [rsp+70h] [rbp-31h] BYREF
  Illusion::SubmitContext *mSubmitContext; // [rsp+F8h] [rbp+57h]

  mSubmitContext = view->mSubmitContext;
  Render::View::GetStateValues(view);
  StateArgs = Render::View::GetStateArgs(view);
  if ( (_S2_7 & 1) == 0 )
  {
    _S2_7 |= 1u;
    UFG::qResourceHandle::qResourceHandle(&vertex_decl_handle_2);
    atexit(Render::DecalManager::DrawPrimitive_::_2_::_dynamic_atexit_destructor_for__vertex_decl_handle__);
  }
  if ( !vertex_decl_handle_2.mData )
  {
    v10 = UFG::qStringHash32("VertexDecl.Decal", 0xFFFFFFFF);
    Inventory = `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result;
    if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v12, 0x3E5FDA3Eu);
      `UFG::qGetResourceInventory<Illusion::VertexDecl>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(&vertex_decl_handle_2, 0x3E5FDA3Eu, v10, Inventory);
  }
  v13 = Illusion::Primitive::Create("DrawDecalPrimitive");
  if ( v13 && vertices )
  {
    if ( (unsigned __int8)UFG::qLinearAllocator::InFrame(Illusion::gEngine.FrameMemory, (__int64)vertices) )
    {
      v15 = vertices;
    }
    else
    {
      v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 24 * num_vertices, 0x10u);
      v15 = (Render::vDecal *)v14;
      if ( !v14 )
        return;
      UFG::qMemCopy(v14, vertices, 24 * num_vertices);
    }
    Illusion::Primitive::SetBuffers(
      v13,
      prim_type,
      v15,
      num_vertices,
      (Illusion::VertexDecl *)vertex_decl_handle_2.mData,
      0i64,
      0,
      1);
    Render::cbLocalTransformState::cbLocalTransformState(
      &arg,
      &view->mSettings->mWorldView,
      &view->mWorldViewProjection,
      local_world);
    v27.mPrev = &v27;
    v27.mNext = &v27;
    v27.mCallback = 0i64;
    v27.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
    *(_WORD *)&v27.mFlags = 1;
    if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == 0xFFFF )
    {
      Param = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
      Render::cbLocalProjectionState::sStateParamIndex = Param;
      v27.mStateParamIndex = Param;
    }
    v27.mCached_Remote.m_Stream = 0i64;
    v27.mWorldViewProjection = &view->mWorldViewProjection;
    v27.mLocalWorld = local_world;
    Illusion::StateArgs::Set<Render::cbLocalTransformState>(StateArgs, &arg);
    Illusion::StateArgs::Set<Render::cbLocalProjectionState>(StateArgs, &v27);
    Illusion::SubmitContext::Draw(mSubmitContext, v13, material);
    mPrev = v27.mPrev;
    mNext = v27.mNext;
    v27.mPrev->mNext = v27.mNext;
    mNext->mPrev = mPrev;
    v27.mPrev = &v27;
    v27.mNext = &v27;
    v27.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[v27.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[v27.mStateParamIndex] )
    {
      v19 = &StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)v27.mStateParamIndex >> 6];
      *v19 &= ~(1i64 << (v27.mStateParamIndex & 0x3F));
    }
    v20 = arg.mPrev;
    v21 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v21->mPrev = v20;
    arg.mPrev = &arg;
    arg.mNext = &arg;
    arg.mIsSet = 0;
    if ( (UFG::qList<Illusion::StateArg,Illusion::StateArg,0,0> *)StateArgs->mStateArgs[arg.mStateParamIndex].mNode.mNext == &StateArgs->mStateArgs[arg.mStateParamIndex] )
      StateArgs->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
    v22 = v27.mPrev;
    v23 = v27.mNext;
    v27.mPrev->mNext = v27.mNext;
    v23->mPrev = v22;
    v24 = arg.mPrev;
    v25 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v25->mPrev = v24;
  }
}

