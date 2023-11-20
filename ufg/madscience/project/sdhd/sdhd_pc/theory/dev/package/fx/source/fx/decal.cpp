// File Line: 73
// RVA: 0x146B110
__int64 Render::_dynamic_initializer_for__gClipQueryManager__()
{
  `eh vector constructor iterator'(
    Render::gClipQueryManager.mDecalClipQueryQueue,
    0x10ui64,
    2,
    (void (__fastcall *)(void *))UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>);
  return atexit(Render::_dynamic_atexit_destructor_for__gClipQueryManager__);
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
  return atexit(Render::_dynamic_atexit_destructor_for__gDecalManager__);
}

// File Line: 76
// RVA: 0x146BB80
__int64 Render::_dynamic_initializer_for__sSDTextureUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("V_BulletHole01_D", 0xFFFFFFFF);
  sSDTextureUID = result;
  return result;
}

// File Line: 77
// RVA: 0x146BB60
__int64 Render::_dynamic_initializer_for__sSDShaderUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("HK_Vehicle_Decal", 0xFFFFFFFF);
  sSDShaderUID = result;
  return result;
}

// File Line: 78
// RVA: 0x146BB20
__int64 Render::_dynamic_initializer_for__sSDMatUID__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("SDMat", 0xFFFFFFFF);
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
  return atexit(Render::_dynamic_atexit_destructor_for__sDebugDecalRadius__);
}

// File Line: 107
// RVA: 0x1C0F10
void __fastcall Render::DecalClipRequest::DecalClipRequest(Render::DecalClipRequest *this)
{
  Render::DecalClipRequest *v1; // rbx
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mSettingsHandle.mPrev);
  Illusion::ModelProxy::ModelProxy(&v1->mModelProxy);
  *(_QWORD *)&v1->mRadius = 0i64;
  *(_QWORD *)&v1->mOneOverNumPages = 0i64;
  v1->mBindIndex = 0;
  v2 = &v1->mComponentPtr;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v1->mComponentPtr.m_pPointer = 0i64;
  v1->mScenery = 0i64;
  *(_QWORD *)&v1->mSequenceId = 0i64;
  v1->mIsValid = 1;
}

// File Line: 111
// RVA: 0x1D5C20
void __fastcall Render::DecalClipRequest::Reset(Render::DecalClipRequest *this)
{
  UFG::qResourceInventory *v1; // rax
  Render::DecalClipRequest *v2; // rbx
  UFG::qResourceWarehouse *v3; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v4; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v6; // rax

  v1 = `UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result;
  v2 = this;
  if ( !`UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v1 = UFG::qResourceWarehouse::GetInventory(v3, 0xAE323146);
    `UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result = v1;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v2->mSettingsHandle.mPrev, v1);
  v4 = &v2->mComponentPtr;
  if ( v2->mComponentPtr.m_pPointer )
  {
    v5 = v4->mPrev;
    v6 = v2->mComponentPtr.mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v4->mPrev;
    v2->mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v2->mComponentPtr.mPrev;
  }
  v2->mComponentPtr.m_pPointer = 0i64;
  v2->mIsValid = 1;
}

// File Line: 118
// RVA: 0x1C4B40
Render::DecalClipRequest *__fastcall Render::DecalClipRequest::operator=(Render::DecalClipRequest *this, Render::DecalClipRequest *rhs)
{
  UFG::qVector4 v2; // xmm3
  UFG::qVector4 v3; // xmm2
  Render::DecalClipRequest *v4; // rdi
  Render::DecalClipRequest *v5; // rbx
  UFG::qVector4 v6; // xmm1
  UFG::qVector4 v7; // xmm3
  UFG::qVector4 v8; // xmm2
  UFG::qVector4 v9; // xmm1
  UFG::qResourceInventory *v10; // rax
  unsigned int v11; // esi
  UFG::qResourceWarehouse *v12; // rax
  UFG::qResourceInventory *v13; // rax
  unsigned int v14; // ebp
  UFG::qResourceWarehouse *v15; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v16; // rdx
  UFG::SimComponent *v17; // r8
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v18; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v19; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v20; // rax

  v2 = rhs->mMatrix.v1;
  v3 = rhs->mMatrix.v2;
  v4 = rhs;
  v5 = this;
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
  v10 = `UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result;
  v11 = rhs->mSettingsHandle.mNameUID;
  if ( !`UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result )
  {
    v12 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v12, 0xAE323146);
    `UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result = v10;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5->mSettingsHandle.mPrev, 0xAE323146, v11, v10);
  v13 = `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result;
  v14 = v4->mModelProxy.mModelHandle.mNameUID;
  if ( !`UFG::qGetResourceInventory<Illusion::Model>'::`2'::result )
  {
    v15 = UFG::qResourceWarehouse::Instance();
    v13 = UFG::qResourceWarehouse::GetInventory(v15, 0xA2ADCD77);
    `UFG::qGetResourceInventory<Illusion::Model>'::`2'::result = v13;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v5->mModelProxy.mModelHandle.mPrev, 0xA2ADCD77, v14, v13);
  v16 = &v5->mComponentPtr;
  v5->mModelProxy.mRModel = v4->mModelProxy.mRModel;
  v5->mRadius = v4->mRadius;
  v5->mTexOffset = v4->mTexOffset;
  v5->mOneOverNumPages = v4->mOneOverNumPages;
  v5->mTextureOrientation = v4->mTextureOrientation;
  v5->mBindIndex = v4->mBindIndex;
  v17 = v4->mComponentPtr.m_pPointer;
  if ( v5->mComponentPtr.m_pPointer )
  {
    v18 = v16->mPrev;
    v19 = v5->mComponentPtr.mNext;
    v18->mNext = v19;
    v19->mPrev = v18;
    v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    v5->mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v5->mComponentPtr.mPrev;
  }
  v5->mComponentPtr.m_pPointer = v17;
  if ( v17 )
  {
    v20 = v17->m_SafePointerList.mNode.mPrev;
    v20->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
    v16->mPrev = v20;
    v5->mComponentPtr.mNext = &v17->m_SafePointerList.mNode;
    v17->m_SafePointerList.mNode.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v16->mPrev;
  }
  v5->mScenery = v4->mScenery;
  v5->mMeshProcessIndex = v4->mMeshProcessIndex;
  v5->mSequenceId = v4->mSequenceId;
  return v5;
}

// File Line: 144
// RVA: 0x1CDDA0
void __fastcall Render::DecalClipRequestQueue::Init(Render::DecalClipRequestQueue *this, unsigned int size)
{
  unsigned int v2; // er8
  unsigned int v3; // eax
  __int64 v4; // rsi
  Render::DecalClipRequestQueue *v5; // rbp
  unsigned int v6; // edx
  unsigned int v7; // ebx
  unsigned int v8; // edx
  __int64 v9; // rdi
  UFG::qResourceInventory *v10; // rax
  Render::DecalClipRequest *v11; // rbx
  UFG::qResourceWarehouse *v12; // rax
  UFG::qSafePointer<UFG::SimComponent,UFG::SimComponent> *v13; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v14; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v15; // rax

  v2 = this->mQueue.size;
  v3 = size - v2;
  v4 = size;
  v5 = this;
  if ( (signed int)(size - v2) <= 0 )
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
    v6 = this->mQueue.capacity;
    v7 = v2 + v3;
    if ( v2 + v3 > v6 )
    {
      if ( v6 )
        v8 = 2 * v6;
      else
        v8 = 1;
      for ( ; v8 < v7; v8 *= 2 )
        ;
      if ( v8 - v7 > 0x10000 )
        v8 = v7 + 0x10000;
      UFG::qArray<Render::DecalClipRequest,0>::Reallocate(&this->mQueue, v8, "RequestQueue");
    }
    v5->mQueue.size = v7;
  }
  if ( (_DWORD)v4 )
  {
    v9 = 0i64;
    do
    {
      v10 = `UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result;
      v11 = v5->mQueue.p;
      if ( !`UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result )
      {
        v12 = UFG::qResourceWarehouse::Instance();
        v10 = UFG::qResourceWarehouse::GetInventory(v12, 0xAE323146);
        `UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result = v10;
      }
      UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v11[v9].mSettingsHandle.mPrev, v10);
      v13 = &v11[v9].mComponentPtr;
      if ( v13->m_pPointer )
      {
        v14 = v13->mPrev;
        v15 = v13->mNext;
        v14->mNext = v15;
        v15->mPrev = v14;
        v13->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
        v13->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v13->mPrev;
      }
      v13->m_pPointer = 0i64;
      v11[v9].mIsValid = 1;
      ++v9;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 174
// RVA: 0x1C68F0
void __fastcall Render::DecalClipRequestQueue::Add(Render::DecalClipRequestQueue *this, Render::DecalClipRequest *request)
{
  signed __int64 v2; // r9
  unsigned int v3; // er11
  Render::DecalClipRequest *v4; // rsi
  Render::DecalClipRequestQueue *v5; // rbx
  unsigned int v6; // ecx
  Render::DecalClipRequest *v7; // r8
  unsigned int v8; // er10
  unsigned int v9; // ecx
  Render::DecalClipRequest *v10; // rcx
  signed __int64 v11; // rdi
  unsigned int v12; // eax

  v2 = this->mTail;
  v3 = this->mQueue.size;
  v4 = request;
  v5 = this;
  v6 = this->mHead;
  if ( ((signed int)v2 + 1) % v3 == v6 )
  {
    v7 = v5->mQueue.p;
    v8 = v7[v6].mSequenceId;
    if ( v6 != (_DWORD)v2 )
    {
      do
      {
        v9 = v5->mHead;
        if ( v8 != v7[v5->mHead].mSequenceId )
          break;
        --v5->mCount;
        v5->mHead = (v9 + 1) % v3;
      }
      while ( (v9 + 1) % v3 != (_DWORD)v2 );
    }
  }
  v10 = v5->mQueue.p;
  v5->mTail = ((signed int)v2 + 1) % v3;
  v11 = v2;
  Render::DecalClipRequest::Reset(&v10[v2]);
  Render::DecalClipRequest::operator=(&v5->mQueue.p[v11], v4);
  v12 = ++v5->mCount;
  if ( v12 > v5->mHighWater )
    v5->mHighWater = v12;
}

// File Line: 220
// RVA: 0x1CDB00
void __fastcall Render::DecalClipQueryManager::Init(Render::DecalClipQueryManager *this, unsigned int maxInFlightQueries, unsigned int maxQueuedQueries)
{
  unsigned int v3; // er12
  __int64 v4; // r15
  Render::DecalClipQueryManager *v5; // rsi
  unsigned int v6; // er9
  unsigned int v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // edx
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // edx
  __int64 v14; // rbx
  __int64 v15; // rbp
  Render::DecalClipQuery *v16; // rdi
  Render::DecalClipQuery *v17; // r14
  UFG::allocator::free_link *v18; // rax
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // rax
  UFG::allocator::free_link *v21; // rax
  UFG::allocator::free_link *v22; // [rsp+88h] [rbp+20h]
  UFG::allocator::free_link *v23; // [rsp+88h] [rbp+20h]

  v3 = maxQueuedQueries;
  v4 = maxInFlightQueries;
  v5 = this;
  v6 = this->mDecalClipQueryQueue[0].size;
  v7 = maxInFlightQueries - v6;
  if ( (signed int)(maxInFlightQueries - v6) <= 0 )
  {
    if ( v6 != maxInFlightQueries )
    {
      if ( v6 - maxInFlightQueries < v6 )
        this->mDecalClipQueryQueue[0].size = maxInFlightQueries;
      else
        this->mDecalClipQueryQueue[0].size = 0;
    }
  }
  else
  {
    v8 = maxInFlightQueries;
    v9 = this->mDecalClipQueryQueue[0].capacity;
    if ( v6 + v7 > v9 )
    {
      if ( v9 )
        v10 = 2 * v9;
      else
        v10 = 1;
      for ( ; v10 < v8; v10 *= 2 )
        ;
      if ( v10 - v8 > 0x10000 )
        v10 = v8 + 0x10000;
      UFG::qArray<UFG::PartTextureData::Textures,0>::Reallocate(
        (UFG::qArray<UFG::PartTextureData::Textures,0> *)this->mDecalClipQueryQueue,
        v10,
        "DecalClipQueryManager");
    }
    v5->mDecalClipQueryQueue[0].size = v8;
  }
  v11 = v5->mDecalClipQueryQueue[1].size;
  if ( (signed int)(v4 - v11) <= 0 )
  {
    if ( v11 != (_DWORD)v4 )
    {
      if ( v11 - (unsigned int)v4 < v11 )
        v5->mDecalClipQueryQueue[1].size = v4;
      else
        v5->mDecalClipQueryQueue[1].size = 0;
    }
  }
  else
  {
    v12 = v5->mDecalClipQueryQueue[1].capacity;
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
        (UFG::qArray<UFG::PartTextureData::Textures,0> *)&v5->mDecalClipQueryQueue[1],
        v13,
        "DecalClipQueryManager");
    }
    v5->mDecalClipQueryQueue[1].size = v4;
  }
  if ( (_DWORD)v4 )
  {
    v14 = 0i64;
    v15 = v4;
    do
    {
      v16 = v5->mDecalClipQueryQueue[0].p;
      v17 = v5->mDecalClipQueryQueue[1].p;
      v18 = UFG::qMalloc(0x38ui64, "DecalClipInfo", 0x1000ui64);
      if ( v18 )
      {
        v22 = v18 + 1;
        v22->mNext = v22;
        v22[1].mNext = v22;
        v18[3].mNext = 0i64;
      }
      else
      {
        v18 = 0i64;
      }
      v16[v14].decal_info = (Render::DecalClipInfo *)v18;
      v16[v14].task_params = (Render::DecalClipTaskParams *)UFG::qMalloc(0xB0ui64, "DecalTaskParams", 0x1000ui64);
      v19 = UFG::qMalloc(0xC50ui64, "DecalTaskResult", 0x1000ui64);
      if ( v19 )
        BYTE4(v19[393].mNext) = 0;
      else
        v19 = 0i64;
      v16[v14].task_results = (Render::DecalClipTaskResults *)v19;
      v20 = UFG::qMalloc(0x38ui64, "DecalClipInfo", 0x1000ui64);
      if ( v20 )
      {
        v23 = v20 + 1;
        v23->mNext = v23;
        v23[1].mNext = v23;
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
      v17[v14].task_results = (Render::DecalClipTaskResults *)v21;
      ++v14;
      --v15;
    }
    while ( v15 );
  }
  v5->mWriteDCQQ = 0;
  v5->mReadDCQQ = 1;
  v5->mDCQQCapacity = v4;
  Render::DecalClipRequestQueue::Init(&v5->mClipQueue, v3);
  *(&v5->mClipQueue.mHead + 4 * (v5->mWriteDCQQ + 2i64)) = 0;
}

// File Line: 280
// RVA: 0x1CC560
UFG::PartTextureData::Textures *__fastcall Render::DecalClipQueryManager::GetNextWriteQuery(Render::DecalClipQueryManager *this)
{
  UFG::qArray<UFG::PartTextureData::Textures,0> *v1; // rdi
  __int64 v2; // rsi
  unsigned int v3; // edx
  unsigned int v4; // ebx
  unsigned int v5; // edx
  UFG::PartTextureData::Textures *v6; // rax

  v1 = (UFG::qArray<UFG::PartTextureData::Textures,0> *)((char *)this + 16 * (this->mWriteDCQQ + 2i64));
  v2 = v1->size;
  v3 = v1->capacity;
  if ( (_DWORD)v2 == v3 )
    return 0i64;
  v4 = v2 + 1;
  if ( (signed int)v2 + 1 > v3 )
  {
    if ( v3 )
      v5 = 2 * v3;
    else
      v5 = 1;
    for ( ; v5 < v4; v5 *= 2 )
      ;
    if ( v5 - v4 > 0x10000 )
      v5 = v2 + 65537;
    UFG::qArray<UFG::PartTextureData::Textures,0>::Reallocate(v1, v5, "qArray.Add");
  }
  v6 = v1->p;
  v1->size = v4;
  return &v6[v2];
}

// File Line: 343
// RVA: 0x1D1B00
char __fastcall Render::DecalClipQueryManager::ProcessClipRequest(Render::DecalClipQueryManager *this, Render::DecalClipRequest *clipRequest)
{
  Render::DecalClipRequest *v2; // r15
  Render::DecalClipQueryManager *v3; // r11
  UFG::qResourceData *v4; // r12
  int v5; // er9
  unsigned int v6; // er10
  unsigned int v7; // er8
  UFG::qResourceData *v8; // rax
  Illusion::rModel *v9; // rcx
  UFG::qBaseNodeRB *v10; // rcx
  UFG::qBaseNodeRB **v11; // rdx
  char *v12; // rsi
  Illusion::rModel *v13; // rax
  signed __int64 v14; // rbp
  signed __int64 v15; // rax
  __int64 v16; // rcx
  signed __int64 v17; // rax
  __int64 v18; // r13
  signed __int64 v19; // rax
  __int64 v20; // r14
  Illusion::Material *v21; // rdi
  __int64 v22; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v23; // rbx
  Illusion::Material *v24; // rax
  Illusion::Material *v25; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v26; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v27; // rcx
  signed __int64 v28; // rbx
  __int64 v29; // rax
  __int64 v30; // rax
  signed __int64 v31; // r12
  __int64 v32; // rax
  signed __int64 v33; // rcx
  __int64 v34; // rax
  signed __int64 v35; // rdi
  UFG::PartTextureData::Textures *v36; // rax
  Illusion::Target *v37; // r14
  Illusion::Target *v38; // r13
  Illusion::Target *v39; // rbx
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
  UFG::qSpuElf *v51; // rax
  void (__fastcall *v52)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v53)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v54)(void *, void *, void *, void *); // r9
  char *v55; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v56; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v57; // rax
  __int64 v59; // [rsp+20h] [rbp-78h]
  UFG::qResourceData *v60; // [rsp+28h] [rbp-70h]
  UFG::SimComponent *bind_ptr; // [rsp+30h] [rbp-68h]
  Render::DecalClipQueryManager *v62; // [rsp+A0h] [rbp+8h]
  int v63; // [rsp+A8h] [rbp+10h]
  unsigned int v64; // [rsp+B0h] [rbp+18h]
  unsigned int v65; // [rsp+B8h] [rbp+20h]

  v62 = this;
  v2 = clipRequest;
  v3 = this;
  if ( clipRequest->mIsValid )
  {
    v4 = clipRequest->mSettingsHandle.mData;
    v60 = clipRequest->mSettingsHandle.mData;
    bind_ptr = clipRequest->mComponentPtr.m_pPointer;
    if ( (clipRequest->mModelProxy.mModelHandle.mData || clipRequest->mModelProxy.mRModel)
      && v4
      && clipRequest->mComponentPtr.m_pPointer )
    {
      v5 = 0;
      v63 = 0;
      v6 = this->mDCQQCapacity - *(&this->mClipQueue.mHead + 4 * (this->mWriteDCQQ + 2i64));
      v65 = this->mDCQQCapacity - *(&this->mClipQueue.mHead + 4 * (this->mWriteDCQQ + 2i64));
      v7 = clipRequest->mMeshProcessIndex;
      while ( 1 )
      {
        v64 = v7;
        v8 = v2->mModelProxy.mModelHandle.mData;
        if ( v8 )
        {
          LODWORD(v9) = v8[2].mNode.mChild[1];
        }
        else
        {
          v9 = v2->mModelProxy.mRModel;
          if ( v9 )
            LODWORD(v9) = v9->mMeshes.mData.mNumItems;
        }
        if ( v7 >= (unsigned int)v9 )
          break;
        if ( !v8 )
          goto LABEL_84;
        v10 = v8[2].mNode.mChild[0];
        if ( v10 )
          v10 = (UFG::qBaseNodeRB *)((char *)v10 + (_QWORD)v8 + 184);
        v11 = &v10->mParent + v7;
        if ( *v11 )
          v12 = (char *)*v11 + (_QWORD)v11;
        else
LABEL_84:
          v12 = 0i64;
        v13 = v2->mModelProxy.mRModel;
        if ( v13 )
          v14 = (signed __int64)&v13->mMeshes.mData.mItems[v7];
        else
          v14 = 0i64;
        v15 = (signed __int64)(v12 + 96);
        if ( !v12 )
          v15 = v14 + 120;
        v16 = *(_QWORD *)(v15 + 16);
        v59 = *(_QWORD *)(v15 + 16);
        v17 = (signed __int64)(v12 + 64);
        if ( !v12 )
          v17 = v14 + 88;
        v18 = *(_QWORD *)(v17 + 16);
        v19 = (signed __int64)(v12 + 32);
        if ( !v12 )
          v19 = v14 + 56;
        v20 = *(_QWORD *)(v19 + 16);
        if ( v16 && v18 && v20 )
        {
          v21 = (Illusion::Material *)(v12 ? *((_QWORD *)v12 + 2) : 0i64);
          v22 = v14 ? *(_QWORD *)(v14 + 48) : 0i64;
          v23 = 0i64;
          if ( v21 )
          {
            v24 = Illusion::Material::GetParamByNameUID(v21, 0xEB98748F);
            if ( !v24 || (v23 = v24->mResourceHandles.mNode.mPrev) == 0i64 )
            {
              v25 = Illusion::Material::GetParamByNameUID(v21, 0xDCE06689);
              if ( v25 )
              {
                v26 = v25->mResourceHandles.mNode.mPrev;
                v27 = v26[7].mPrev;
                if ( v27 )
                  v28 = (signed __int64)&v27[7] + (_QWORD)v26;
                else
                  v28 = 0i64;
                v23 = *(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)(v28 + 16);
              }
            }
            v16 = v59;
            v7 = v64;
            v5 = v63;
            v6 = v65;
            v3 = v62;
          }
          else if ( v22 )
          {
            v23 = *(UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> **)(v22 + 128);
          }
          if ( (!HIDWORD(v4[2].mResourceHandles.mNode.mPrev) || v23 && LOBYTE(v23[5].mNext))
            && (!v23 || LODWORD(v23[1].mNext) != -303549566) )
          {
            if ( v5 == v6 )
            {
              v2->mMeshProcessIndex = v7;
              return 0;
            }
            v29 = *(_QWORD *)(v20 + 88);
            if ( v29 )
              v29 += v20 + 88;
            if ( *(_DWORD *)(v29 + 4) <= 1u )
            {
              v30 = *(_QWORD *)(v16 + 96);
              if ( v30 )
                v31 = v16 + v30 + 96;
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
              v37 = v36->mDiffuseTarget;
              v38 = v36->mNormTarget;
              v39 = v36->mSpecTarget;
              *(_QWORD *)&v39->mWidth = v60;
              LODWORD(v39->mTargetTexture[3]) = v2->mSequenceId;
              Render::DecalObjectLink::Set(
                (Render::DecalObjectLink *)&v39->mTargetPlat,
                v2->mBindIndex,
                bind_ptr,
                v2->mScenery);
              BYTE4(v39->mTargetTexture[3]) = v2->mIsValid;
              v40 = v2->mLocalToWorld.v1;
              v41 = v2->mLocalToWorld.v2;
              v42 = v2->mLocalToWorld.v3;
              *(UFG::qVector4 *)&v37->mNumTargetTextures = v2->mLocalToWorld.v0;
              *(UFG::qVector4 *)&v37->mTargetTexture[1] = v40;
              *(UFG::qVector4 *)&v37->mTargetTexture[3] = v41;
              *(UFG::qVector4 *)&v37->mDepthTexture = v42;
              v43 = v2->mMatrix.v1;
              v44 = v2->mMatrix.v2;
              v45 = v2->mMatrix.v3;
              *(UFG::qVector4 *)&v37->mOwnsDepthTexture = v2->mMatrix.v0;
              *(UFG::qVector4 *)&v37->mDescription[15] = v43;
              *(UFG::qVector4 *)&v37->mDescription[31] = v44;
              *(UFG::qVector4 *)&v37[1].mTargetPlat = v45;
              *(_QWORD *)&v37->mWidth = v35;
              v37->mTargetPlat = (Illusion::TargetPlat *)v31;
              LODWORD(v37[1].mTargetTexture[2]) = *(_DWORD *)(v59 + 104);
              *(float *)v37[1].mTargetTexture = v2->mTextureOrientation;
              HIDWORD(v37[1].mTargetTexture[0]) = LODWORD(v2->mTexOffset);
              *(float *)&v37[1].mTargetTexture[1] = v2->mOneOverNumPages;
              if ( v12 )
                v46 = *((_DWORD *)v12 + 58);
              else
                v46 = *(_DWORD *)(v14 + 256);
              HIDWORD(v37[1].mTargetTexture[1]) = v46;
              v4 = v60;
              v47 = *(float *)&v60[1].mDebugName[24];
              if ( v47 <= s_fMinDecalCutoffAdjust )
                v47 = s_fMinDecalCutoffAdjust;
              *((float *)&v37[1].mTargetTexture[2] + 1) = v47;
              HIDWORD(v37[1].mTargetTexture[3]) = *(_DWORD *)&v60[1].mDebugName[20];
              *(float *)&v37[1].mTargetTexture[3] = v2->mRadius;
              v48 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
              v49 = (UFG::qTask *)v48;
              if ( v48 )
              {
                *(_QWORD *)v48 = v48;
                *((_QWORD *)v48 + 1) = v48;
                v50 = v48 + 16;
                *v50 = v50;
                v50[1] = v50;
                v51 = Render::gTaskFunctionDeclData_DecalClipTask.mSpuElf;
                v52 = Render::gTaskFunctionDeclData_DecalClipTask.mTaskFunctionSPU;
                v53 = Render::gTaskFunctionDeclData_DecalClipTask.mTaskFunctionPPU;
                v54 = Render::gTaskFunctionDeclData_DecalClipTask.mTaskFunctionOffload;
                if ( !Render::gTaskFunctionDeclData_DecalClipTask.mCurrentSPUEnabled )
                {
                  v51 = 0i64;
                  v52 = 0i64;
                  v54 = 0i64;
                }
                v49->mTaskGroup = 0i64;
                v49->mFlags = 2;
                v49->mSyncVars.i64 = 0i64;
                v49->mSyncVars.v.mDependents = 0i64;
                v49->mFunctionDeclData = &Render::gTaskFunctionDeclData_DecalClipTask;
                if ( v51 )
                  v55 = v51->mAddress;
                else
                  v55 = 0i64;
                v49->mSPUElfAddress = v55;
                v49->mSPUFunction = v52;
                v49->mPPUFunction = v53;
                v49->mParam0 = v37;
                v49->mParam1 = v38;
                v49->mParam2 = 0i64;
                v49->mParam3 = 0i64;
                if ( v54 )
                {
                  v49->mFlags = 130;
                  v49->mOffloadThread = 0;
                }
              }
              v56 = UFG::gTaskManager.mSingleFrameTasks;
              v57 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
              v57->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v49->mPrev;
              v49->mPrev = v57;
              v49->mNext = &v56->mNode;
              v56->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v49->mPrev;
              UFG::qTaskManager::Queue(&UFG::gTaskManager, v49);
              v5 = v63++ + 1;
              v7 = v64;
            }
          }
        }
        ++v7;
        v6 = v65;
        v3 = v62;
      }
    }
  }
  return 1;
}

// File Line: 507
// RVA: 0x1DBD00
void __fastcall Render::DecalClipQueryManager::UpdateResults(Render::DecalClipQueryManager *this)
{
  Render::DecalClipQueryManager *v1; // r14
  signed __int64 v2; // rsi
  unsigned int v3; // eax
  __int64 v4; // rdi
  __int64 v5; // rbp
  Render::DecalClipQuery *v6; // rbx
  Render::DecalClipTaskResults *v7; // rax
  __int64 v8; // rax

  v1 = this;
  v2 = 2 * (this->mReadDCQQ + 2i64);
  v3 = *(&this->mClipQueue.mHead + 4 * (this->mReadDCQQ + 2i64));
  if ( v3 )
  {
    v4 = 0i64;
    v5 = v3;
    do
    {
      v6 = (Render::DecalClipQuery *)(v4 + *((_QWORD *)&v1->mClipQueue.mCount + v2));
      if ( v6 )
      {
        v7 = v6->task_results;
        if ( v7 )
        {
          if ( v7->mResultReady && v7->mNumPrims && v6->decal_info->mIsValid )
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
  v1->mWriteDCQQ ^= 1u;
  v8 = v1->mWriteDCQQ;
  v1->mReadDCQQ ^= 1u;
  *(&v1->mClipQueue.mHead + 4 * (v8 + 2)) = 0;
}

// File Line: 531
// RVA: 0x1D0E80
void __fastcall Render::DecalClipQueryManager::Invalidate(Render::DecalClipQueryManager *this, Render::IDecalScenery *decal_scenery, unsigned int bindIndex)
{
  unsigned int v3; // er10
  UFG::qArray<Render::DecalClipQuery,0> *v4; // r9
  signed __int64 v5; // rdi
  unsigned int v6; // er11
  unsigned int i; // eax
  Render::DecalClipInfo *v8; // r8
  Render::DecalClipRequest *v9; // rax

  v3 = bindIndex;
  v4 = this->mDecalClipQueryQueue;
  v5 = 2i64;
  v6 = 0;
  do
  {
    for ( i = 0; i < v4->size; ++i )
    {
      v8 = v4->p[i].decal_info;
      if ( v8->mStoredObjLink.mScenery == decal_scenery && (v3 == -1 || v8->mStoredObjLink.mIndex == v3) )
        v8->mIsValid = 0;
    }
    ++v4;
    --v5;
  }
  while ( v5 );
  if ( this->mClipQueue.mQueue.size > 0 )
  {
    do
    {
      v9 = &this->mClipQueue.mQueue.p[v6];
      if ( v9->mScenery == decal_scenery && (v3 == -1 || v9->mBindIndex == v3) )
        v9->mIsValid = 0;
      ++v6;
    }
    while ( v6 < this->mClipQueue.mQueue.size );
  }
}

// File Line: 561
// RVA: 0x1CDA50
void __fastcall Render::DecalArray::Init(Render::DecalArray *this, unsigned int numDecals, unsigned int fragmentsPerDecal)
{
  Render::DecalArray *v3; // rbx
  unsigned int v4; // eax
  unsigned int v5; // eax
  char *v6; // r8
  __int64 v7; // rdx
  _QWORD *v8; // rcx

  v3 = this;
  this->mDecalCount = numDecals;
  this->mFragmentsPerDecal = fragmentsPerDecal;
  v4 = 224 * fragmentsPerDecal + 64;
  this->mDecalStride = v4;
  this->mDecalDataBuffer = (char *)UFG::qMalloc(numDecals * v4, "DecalArray::Init", 0x1000ui64);
  v5 = 0;
  if ( v3->mDecalCount )
  {
    do
    {
      v6 = &v3->mDecalDataBuffer[v5 * v3->mDecalStride];
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
      ++v5;
    }
    while ( v5 < v3->mDecalCount );
  }
}

// File Line: 628
// RVA: 0x1D2620
void __fastcall Render::IDecalScenery::RemoveAttachedDecals(Render::IDecalScenery *this, unsigned int bind_index)
{
  unsigned int v2; // edi
  Render::IDecalScenery *v3; // rsi
  UFG::qNode<Render::Decal,Render::Decal> *v4; // rbx
  signed __int64 i; // rsi
  UFG::qNode<Render::Decal,Render::Decal> *v6; // rcx
  UFG::qNode<Render::Decal,Render::Decal> *v7; // rbp
  UFG::qNode<Render::Decal,Render::Decal> *v8; // rcx
  UFG::qNode<Render::Decal,Render::Decal> *v9; // rax

  v2 = bind_index;
  v3 = this;
  if ( bind_index != -1 )
    Render::DecalClipQueryManager::Invalidate(&Render::gClipQueryManager, this, bind_index);
  v4 = v3->mAttachedDecals.mNode.mNext;
  for ( i = (signed __int64)&v3->mAttachedDecals; v4 != (UFG::qNode<Render::Decal,Render::Decal> *)i; v4 = v4->mNext )
  {
    if ( v2 == -1 || LODWORD(v4[3].mPrev) == v2 )
    {
      v6 = v4[1].mNext;
      v7 = v4->mPrev;
      if ( v6 )
      {
        ((void (__fastcall *)(UFG::qNode<Render::Decal,Render::Decal> *, UFG::qNode<Render::Decal,Render::Decal> *))v6->mPrev->mNext)(
          v6,
          v4);
        v4[1].mNext = 0i64;
      }
      v8 = v4->mPrev;
      v9 = v4->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v4->mPrev = v4;
      v4->mNext = v4;
      HIDWORD(v4[3].mPrev) = -1;
      WORD2(v4[3].mNext) = 0;
      v4 = v7;
    }
  }
}

// File Line: 825
// RVA: 0x1D2830
void __fastcall Render::DecalArray::RemoveSequence(Render::DecalArray *this, unsigned int sequenceId)
{
  unsigned int v2; // ebp
  Render::DecalArray *v3; // rsi
  unsigned int v4; // edi
  char *v5; // rbx
  __int64 v6; // rcx
  __int64 v7; // rcx
  _QWORD *v8; // rax

  v2 = sequenceId;
  v3 = this;
  v4 = 0;
  if ( this->mDecalCount )
  {
    do
    {
      v5 = &v3->mDecalDataBuffer[v4 * v3->mDecalStride];
      if ( *((_DWORD *)v5 + 13) == v2 )
      {
        v6 = *((_QWORD *)v5 + 3);
        if ( v6 )
        {
          (*(void (__fastcall **)(__int64, char *))(*(_QWORD *)v6 + 8i64))(
            v6,
            &v3->mDecalDataBuffer[v4 * v3->mDecalStride]);
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
      ++v4;
    }
    while ( v4 < v3->mDecalCount );
  }
}

// File Line: 837
// RVA: 0x1D28D0
void __fastcall Render::DecalArray::RemoveSequenceAtIndex(Render::DecalArray *this, unsigned int startIndex)
{
  Render::DecalArray *v2; // rdi
  unsigned int v3; // er14
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

  v2 = this;
  v3 = startIndex;
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
  v9 = (v3 + 1) % v2->mDecalCount;
  for ( i = &v2->mDecalDataBuffer[v2->mDecalStride * v9];
        *((_WORD *)i + 30);
        i = &v2->mDecalDataBuffer[v2->mDecalStride * v9] )
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
    v9 = (v9 + 1) % v2->mDecalCount;
  }
  v14 = (v3 - 1) % v2->mDecalCount;
  for ( j = &v2->mDecalDataBuffer[v2->mDecalStride * v14];
        *((_WORD *)j + 30);
        j = &v2->mDecalDataBuffer[v2->mDecalStride * v14] )
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
    v14 = (v14 + 1) % v2->mDecalCount;
  }
}

// File Line: 865
// RVA: 0x1C7630
__int64 __fastcall Render::DecalArray::AttachDecal(Render::DecalArray *this, Render::DecalClipQuery *dcq)
{
  Render::DecalClipQuery *v2; // rbp
  unsigned int v3; // edx
  Render::DecalArray *v4; // r15
  char *v5; // r13
  unsigned int v6; // ebx
  int v7; // esi
  unsigned int v8; // er14
  Render::DecalClipTaskResults *v9; // rax
  int v10; // er12
  unsigned int v11; // ebx
  signed __int64 v12; // rdi
  Render::DecalClipInfo *v13; // rcx
  Render::IDecalScenery *v14; // rcx
  char **v15; // r8
  __int64 result; // rax
  unsigned int v17; // [rsp+50h] [rbp+8h]

  v2 = dcq;
  v3 = this->mCurDecal;
  v4 = this;
  v5 = &this->mDecalDataBuffer[this->mDecalStride * v3];
  v6 = *((_DWORD *)v5 + 13);
  v17 = *((_DWORD *)v5 + 13);
  Render::DecalArray::RemoveSequenceAtIndex(this, v3);
  *((_DWORD *)v5 + 13) = -1;
  *(_QWORD *)v5 = v5;
  *((_QWORD *)v5 + 1) = v5;
  *((_WORD *)v5 + 30) = 0;
  *((_QWORD *)v5 + 3) = 0i64;
  v7 = 0;
  v8 = 0;
  *((_DWORD *)v5 + 13) = v2->decal_info->mSequenceID;
  *((_WORD *)v5 + 30) = v2->task_results->mNumPrims;
  *((_DWORD *)v5 + 14) = v2->decal_info->mSettingsPtr->mNode.mUID;
  *((_QWORD *)v5 + 2) = v2->decal_info->mSettingsPtr;
  v9 = v2->task_results;
  if ( v9->mNumPrims )
  {
    do
    {
      v10 = (unsigned __int8)v9->mPrimVertCount[v8];
      v11 = 0;
      v12 = (signed __int64)&v4->mDecalDataBuffer[224 * v8 + 64 + v4->mCurDecal * v4->mDecalStride];
      *(_DWORD *)(v12 + 216) = v10;
      if ( v10 )
      {
        do
        {
          UFG::qMemCopy((void *)(v12 + 24i64 * v11), &v2->task_results->mVerts[v11 + v7], 0x18u);
          ++v11;
        }
        while ( v11 < *(_DWORD *)(v12 + 216) );
      }
      v9 = v2->task_results;
      ++v8;
      v7 += v10;
    }
    while ( v8 < v9->mNumPrims );
    v6 = v17;
  }
  v13 = v2->decal_info;
  if ( v13->mStoredObjLink.mComponentPtr.m_pPointer )
  {
    v14 = v13->mStoredObjLink.mScenery;
    *((_QWORD *)v5 + 3) = v14;
    v15 = (char **)v14->mAttachedDecals.mNode.mNext;
    v14->mAttachedDecals.mNode.mNext = (UFG::qNode<Render::Decal,Render::Decal> *)v5;
    *((_QWORD *)v5 + 1) = v15;
    *(_QWORD *)v5 = (char *)v14 + 8;
    *v15 = v5;
    v14->vfptr->OnAttachDecal(v14, (Render::Decal *)v5, v2);
  }
  result = v6;
  v4->mCurDecal = (v4->mCurDecal + 1) % v4->mDecalCount;
  return result;
}

// File Line: 958
// RVA: 0x1D3880
void __fastcall Render::DecalArray::Render(Render::DecalArray *this, Render::View *view, float fTime, Render::eFXDrawPass drawPass, unsigned int decalStateBlockIndex, Illusion::Material *decalMat)
{
  unsigned int v6; // er12
  Render::eFXDrawPass v7; // er8
  Render::View *v8; // r15
  Render::DecalArray *v9; // r14
  unsigned int v10; // ebp
  char *v11; // rbx
  unsigned __int8 (__fastcall ***v12)(_QWORD, char *, UFG::qMatrix44 *); // rcx
  char *v13; // rax
  _DWORD *v14; // rdx
  char *v15; // rsi
  Illusion::StateValues *v16; // rax
  unsigned int v17; // er8
  _WORD *v18; // rax
  unsigned int v19; // er8
  _WORD *v20; // rax
  unsigned int v21; // er8
  _WORD *v22; // rax
  unsigned int v23; // er8
  _WORD *v24; // rax
  unsigned int v25; // er8
  _WORD *v26; // rax
  unsigned __int16 i; // si
  signed __int64 v28; // r9
  UFG::qMatrix44 local_world; // [rsp+40h] [rbp-68h]
  Render::eFXDrawPass v30; // [rsp+C8h] [rbp+20h]

  v30 = drawPass;
  v6 = this->mDecalCount;
  v7 = drawPass;
  v8 = view;
  v9 = this;
  v10 = 0;
  if ( this->mDecalCount )
  {
    do
    {
      v11 = &v9->mDecalDataBuffer[v10 * v9->mDecalStride];
      if ( *((_WORD *)v11 + 30) )
      {
        if ( *(_DWORD *)(*((_QWORD *)v11 + 2) + 192i64) == v7 )
        {
          v12 = (unsigned __int8 (__fastcall ***)(_QWORD, char *, UFG::qMatrix44 *))*((_QWORD *)v11 + 3);
          if ( v12 )
          {
            if ( (**v12)(v12, &v9->mDecalDataBuffer[v10 * v9->mDecalStride], &local_world) )
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
              v16 = Render::View::GetStateValues(v8);
              if ( (unsigned int)(signed __int16)decalStateBlockIndex >= 0x40 )
                v16->mSetValueMask.mFlags[1] |= 1i64 << ((unsigned __int8)decalStateBlockIndex - 64);
              else
                v16->mSetValueMask.mFlags[0] |= 1i64 << decalStateBlockIndex;
              v16->mParamValues[(signed __int16)decalStateBlockIndex] = v15;
              v17 = *(_DWORD *)(*((_QWORD *)v11 + 2) + 128i64);
              if ( LODWORD(decalMat[1].mResourceHandles.mNode.mNext) != v17 )
              {
                UFG::qResourceHandle::Init(
                  (UFG::qResourceHandle *)&decalMat[1].mNode.mChild[1],
                  decalMat[1].mTypeUID,
                  v17);
                v18 = (_WORD *)decalMat->mMaterialUser.mOffset;
                if ( v18 )
                  v18 = (_WORD *)((char *)v18 + (_QWORD)decalMat + 120);
                *v18 |= 0x20u;
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
                  (unsigned int)decalMat[2].mResourceHandles.mNode.mPrev,
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
                  *((_DWORD *)&decalMat[2].0 + 22),
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
              for ( i = 0; i < *((_WORD *)v11 + 30); ++i )
              {
                v28 = (signed __int64)&v9->mDecalDataBuffer[224 * i + 64 + v10 * v9->mDecalStride];
                Render::DecalManager::DrawPrimitive(
                  &Render::gDecalManager,
                  v8,
                  TRIANGLEFAN,
                  (Render::vDecal *)v28,
                  *(_DWORD *)(v28 + 216),
                  decalMat,
                  &local_world);
              }
            }
            v7 = v30;
          }
        }
      }
      ++v10;
    }
    while ( v10 < v6 );
  }
}

// File Line: 1077
// RVA: 0x1CDF40
void __fastcall Render::DecalManager::Init(Render::DecalManager *this)
{
  Render::DecalManager *v1; // r14
  UFG::qArray<Render::DecalArray,0> *v2; // rdi
  unsigned int v3; // ecx
  signed __int64 v4; // rsi
  _WORD *v5; // rbp
  unsigned int v6; // edx
  unsigned int v7; // edx
  __int64 v8; // rdi
  Render::DecalManager::DecalBucketConfig *v9; // rbx
  UFG::allocator::free_link *v10; // rax
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
  __int64 v24; // rax
  _WORD *v25; // rax
  __int64 v26; // rax
  UFG::qResourceInventory *v27; // rax
  UFG::qResourceWarehouse *v28; // rax

  v1 = this;
  Render::DecalClipQueryManager::Init(&Render::gClipQueryManager, 0x2Du, 0x100u);
  v2 = &v1->mDecalBuckets;
  v1->mEnableDecals = 1;
  v3 = v1->mDecalBuckets.size;
  v4 = 7i64;
  v5 = 0i64;
  if ( (signed int)(7 - v3) <= 0 )
  {
    if ( v3 != 7 )
    {
      if ( v3 - 7 < v3 )
        v2->size = 7;
      else
        v2->size = 0;
    }
  }
  else
  {
    v6 = v1->mDecalBuckets.capacity;
    if ( v6 < 7 )
    {
      if ( v6 )
        v7 = 2 * v6;
      else
        v7 = 1;
      for ( ; v7 < 7; v7 *= 2 )
        ;
      if ( v7 - 7 > 0x10000 )
        v7 = 65543;
      UFG::qArray<Render::DecalArray,0>::Reallocate(v2, v7, "DecalBuckets");
    }
    v2->size = 7;
  }
  v8 = 0i64;
  v9 = Render::DecalManager::sDecalBucketConfig;
  do
  {
    Render::DecalArray::Init(
      &v1->mDecalBuckets.p[v8],
      458752 * v9->mMemoryPercentage / 0x64 / (224 * v9->mFragmentCount + 64),
      v9->mFragmentCount);
    ++v8;
    ++v9;
    --v4;
  }
  while ( v4 );
  v10 = UFG::qMalloc(0x1FA0ui64, "DecalManager::SequenceIdLookup", 0x1000ui64);
  v1->mSequenceIdToBucketMask = (char *)v10;
  UFG::qMemSet(v10, 0, 0x1FA0u);
  v11 = UFG::qStringHashUpper32("DecalMat", 0xFFFFFFFF);
  v12 = Illusion::Factory::NewMaterial("DecalMat", v11, 6u, 0i64, 0i64, 0i64);
  v13 = UFG::qStringHash32("DR_DECAL", 0xFFFFFFFF);
  LOWORD(v12[1].mNode.mChild[0]) = 0;
  HIDWORD(v12[1].mNode.mParent) = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v14 = UFG::qStringHash32("iShader", 0xFFFFFFFF);
  v12[1].mTypeUID = -1957338719;
  LODWORD(v12[1].mResourceHandles.mNode.mNext) = v13;
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
  LODWORD(v12[2].mResourceHandles.mNode.mPrev) = 1002903008;
  v12[2].mNode.mUID = -262489691;
  v12[1].mNumParams = v16;
  v17 = UFG::qStringHash32("DEFAULT", 0xFFFFFFFF);
  LOWORD(v12[2].mTypeUID) = 0;
  HIDWORD(v12[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v18 = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
  *((_DWORD *)&v12[2].0 + 22) = -1958479169;
  *(_DWORD *)&v12[2].mDebugName[28] = v17;
  LODWORD(v12[2].mResourceHandles.mNode.mNext) = v18;
  v19 = UFG::qStringHash32("DEFAULT", 0xFFFFFFFF);
  LOWORD(v12[2].mStateBlockMask.mFlags[1]) = 0;
  HIDWORD(v12[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
  v20 = UFG::qStringHash32("texNormal", 0xFFFFFFFF);
  LODWORD(v12[3].mNode.mChild[1]) = -1958479169;
  LODWORD(v12[3].mNode.mChild[0]) = v19;
  LODWORD(v12[2].mStateBlockMask.mFlags[0]) = v20;
  v21 = UFG::qStringHashUpper32("c8c29f94-7308-4cd9-ba62-736f78fdeda6", 0xFFFFFFFF);
  LOWORD(v12[3].mResourceHandles.mNode.mPrev) = 0;
  *(&v12[3].mNode.mUID + 1) = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  v22 = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
  *(_DWORD *)&v12[3].mDebugName[20] = 1292158962;
  *(_DWORD *)&v12[3].mDebugName[12] = v21;
  v12[3].mNode.mUID = v22;
  v23 = UFG::qResourceWarehouse::Instance();
  UFG::qResourceWarehouse::Add(v23, (UFG::qResourceData *)&v12->mNode);
  if ( LODWORD(v12[1].mStateBlockMask.mFlags[0]) != 662883558 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v12[1].mDebugName[20],
      v12[1].mStateBlockMask.mFlags[1],
      0x2782CCE6u);
    v24 = v12->mMaterialUser.mOffset;
    if ( v24 )
      v25 = (_WORD *)((char *)&v12->mMaterialUser + v24);
    else
      v25 = 0i64;
    *v25 |= 0x20u;
  }
  if ( v12[2].mNode.mUID != -262489691 )
  {
    UFG::qResourceHandle::Init(
      (UFG::qResourceHandle *)&v12[2],
      (unsigned int)v12[2].mResourceHandles.mNode.mPrev,
      0xF05AB9A5);
    v26 = v12->mMaterialUser.mOffset;
    if ( v26 )
      v5 = (_WORD *)((char *)&v12->mMaterialUser + v26);
    *v5 |= 0x20u;
  }
  v27 = `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Illusion::Material>'::`2'::result )
  {
    v28 = UFG::qResourceWarehouse::Instance();
    v27 = UFG::qResourceWarehouse::GetInventory(v28, 0xB4C26312);
    `UFG::qGetResourceInventory<Illusion::Material>'::`2'::result = v27;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v1->mDecalMat.mPrev, 0xB4C26312, v11, v27);
  v1->mStateBlockIndex = (unsigned __int16)Illusion::StateSystem::AddParam(
                                             &Illusion::gStateSystem,
                                             "cbDecalSettings",
                                             0);
  UFG::qMemSet(Render::DecalManager::sDecalFragmentCountHistogram, 0, 0xA8u);
}

// File Line: 1182
// RVA: 0x1CB0A0
void __fastcall Render::DecalManager::DestroyDecals(Render::DecalManager *this)
{
  unsigned int v1; // eax
  Render::DecalManager *v2; // r11
  __int64 v3; // r10
  __int64 v4; // r9
  unsigned int v5; // eax
  Render::DecalArray *v6; // r8
  __int64 v7; // rdx
  unsigned int v8; // edx
  unsigned int v9; // ecx

  v1 = this->mDecalBuckets.size;
  v2 = this;
  if ( v1 )
  {
    v3 = v1;
    v4 = 0i64;
    do
    {
      v5 = 0;
      v6 = &this->mDecalBuckets.p[v4];
      if ( v6->mDecalCount > 0 )
      {
        do
        {
          v7 = v5++ * v6->mDecalStride;
          *(_WORD *)&v6->mDecalDataBuffer[v7 + 60] = 0;
        }
        while ( v5 < v6->mDecalCount );
      }
      ++v4;
      --v3;
    }
    while ( v3 );
  }
  v8 = Render::gClipQueryManager.mClipQueue.mHead;
  if ( Render::gClipQueryManager.mClipQueue.mHead != Render::gClipQueryManager.mClipQueue.mTail )
  {
    v9 = Render::gClipQueryManager.mClipQueue.mCount;
    do
    {
      --v9;
      v8 = (v8 + 1) % Render::gClipQueryManager.mClipQueue.mQueue.size;
    }
    while ( v8 != Render::gClipQueryManager.mClipQueue.mTail );
    Render::gClipQueryManager.mClipQueue.mHead = v8;
    Render::gClipQueryManager.mClipQueue.mCount = v9;
  }
  UFG::qMemSet(v2->mSequenceIdToBucketMask, 0, 0x1FA0u);
}

// File Line: 1262
// RVA: 0x1C9520
void __fastcall Render::DecalManager::CreateDecal(Render::DecalManager *this, unsigned int decalId, UFG::qVector3 *vPos, UFG::qVector3 *vNormal)
{
  UFG::qVector3 *v4; // rbx
  UFG::qVector3 *v5; // r14
  unsigned int v6; // esi
  Render::DecalManager *v7; // rdi
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceData *v10; // rsi
  float v11; // xmm10_4
  __m128 v12; // xmm3
  float v13; // xmm9_4
  __m128 v14; // xmm2
  float v15; // xmm4_4
  float v16; // xmm1_4
  float v17; // xmm9_4
  float v18; // xmm10_4
  float v19; // xmm3_4
  float v20; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm8_4
  __m128 v23; // xmm14
  float v24; // xmm15_4
  __m128 v25; // xmm2
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
  unsigned int v40; // ecx
  int v41; // ecx
  float v42; // xmm8_4
  float v43; // xmm7_4
  float v44; // xmm6_4
  float v45; // xmm9_4
  float v46; // xmm1_4
  __int128 v47; // xmm6
  float v48; // xmm8_4
  float v49; // xmm2_4
  float v50; // xmm2_4
  int v51; // xmm2_4
  unsigned int v52; // ebx
  unsigned int v53; // esi
  UFG::qResourceInventory *v54; // rax
  UFG::qResourceWarehouse *v55; // rax
  __int64 v56; // rdx
  unsigned int v57; // ett
  UFG::qResourceInventory *v58; // rax
  UFG::qResourceWarehouse *v59; // rax
  float v60; // [rsp+20h] [rbp-C8h]
  float v61; // [rsp+24h] [rbp-C4h]
  UFG::qVector4 v62; // [rsp+30h] [rbp-B8h]
  UFG::qVector4 v63; // [rsp+40h] [rbp-A8h]
  UFG::qVector4 v64; // [rsp+50h] [rbp-98h]
  UFG::qVector4 v65; // [rsp+60h] [rbp-88h]
  UFG::qResourceHandle v66; // [rsp+70h] [rbp-78h]
  __int64 v67; // [rsp+90h] [rbp-58h]
  Render::DecalClipRequest v68; // [rsp+98h] [rbp-50h]
  void *v69; // [rsp+268h] [rbp+180h]
  float *v70; // [rsp+288h] [rbp+1A0h]

  v67 = -2i64;
  v4 = vNormal;
  v5 = vPos;
  v6 = decalId;
  v7 = this;
  if ( !this->mEnableDecals )
    return;
  UFG::qResourceHandle::qResourceHandle(&v66);
  v8 = `UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0xAE323146);
    `UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result = v8;
  }
  UFG::qResourceHandle::Init(&v66, 0xAE323146, v6, v8);
  v10 = v66.mData;
  if ( v66.mData )
  {
    v11 = v70[1];
    v12 = (__m128)*(unsigned int *)v70;
    v13 = v70[2];
    v14 = v12;
    v14.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
    v15 = 0.0;
    if ( v14.m128_f32[0] == 0.0 )
      v16 = 0.0;
    else
      v16 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
    v17 = v13 * v16;
    v18 = v11 * v16;
    v19 = v12.m128_f32[0] * v16;
    v60 = *((float *)&v66.mData[2].mNode.mUID + 1);
    v61 = *(float *)&v66.mData[2].mResourceHandles.mNode.mPrev;
    v20 = v4->y;
    v21 = v4->x;
    v22 = v4->z;
    v23 = (__m128)LODWORD(v4->x);
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(v19 * v4->x) + (float)(v4->y * v18)) + (float)(v4->z * v17)) & _xmm) >= 0.99000001 )
    {
      v25 = (__m128)LODWORD(v4->z);
      if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                          (float)((float)(v21 * UFG::qVector3::msAxisY.x) + (float)(v20 * UFG::qVector3::msAxisY.y))
                        + (float)(v22 * UFG::qVector3::msAxisY.z)) & _xmm) >= 0.99000001 )
      {
        v24 = (float)(v20 * UFG::qVector3::msAxisZ.x) - (float)(v21 * UFG::qVector3::msAxisZ.y);
        v23.m128_f32[0] = (float)(v23.m128_f32[0] * UFG::qVector3::msAxisZ.z) - (float)(v22 * UFG::qVector3::msAxisZ.x);
        v25.m128_f32[0] = (float)(v22 * UFG::qVector3::msAxisZ.y) - (float)(v20 * UFG::qVector3::msAxisZ.z);
        v26 = v23;
        v26.m128_f32[0] = v23.m128_f32[0] * v23.m128_f32[0];
        v27 = v25.m128_f32[0] * v25.m128_f32[0];
      }
      else
      {
        v24 = (float)(v20 * UFG::qVector3::msAxisY.x) - (float)(v21 * UFG::qVector3::msAxisY.y);
        v23.m128_f32[0] = (float)(v23.m128_f32[0] * UFG::qVector3::msAxisY.z) - (float)(v22 * UFG::qVector3::msAxisY.x);
        v25.m128_f32[0] = (float)(v22 * UFG::qVector3::msAxisY.y) - (float)(v20 * UFG::qVector3::msAxisY.z);
        v26 = v25;
        v26.m128_f32[0] = v25.m128_f32[0] * v25.m128_f32[0];
        v27 = v23.m128_f32[0] * v23.m128_f32[0];
      }
    }
    else
    {
      v24 = (float)(v19 * v20) - (float)(v21 * v18);
      v23.m128_f32[0] = (float)(v23.m128_f32[0] * v17) - (float)(v19 * v22);
      v25 = (__m128)LODWORD(v4->z);
      v25.m128_f32[0] = (float)(v22 * v18) - (float)(v20 * v17);
      v26 = v25;
      v26.m128_f32[0] = v25.m128_f32[0] * v25.m128_f32[0];
      v27 = v23.m128_f32[0] * v23.m128_f32[0];
    }
    v26.m128_f32[0] = (float)(v26.m128_f32[0] + v27) + (float)(v24 * v24);
    if ( v26.m128_f32[0] != 0.0 )
      v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
    v28 = v24 * v15;
    v29 = v23.m128_f32[0] * v15;
    *(float *)&v69 = v25.m128_f32[0] * v15;
    v30 = (float)((float)(v25.m128_f32[0] * v15) * v20) - (float)(v29 * v21);
    v31 = (float)(v28 * v21) - (float)((float)(v25.m128_f32[0] * v15) * v22);
    v32 = (float)(v29 * v22) - (float)(v28 * v20);
    v33 = (float)((float)(v61 - v60) * UFG::qRandom(1.0, &UFG::qDefaultSeed)) + v60;
    v34 = sinf(v33);
    v35 = cosf(v33);
    v36 = v4->z;
    *(_QWORD *)&v64.x = *(_QWORD *)&v4->x;
    *(_QWORD *)&v64.z = LODWORD(v36);
    v62.x = (float)(*(float *)&v69 * v35) - (float)(v32 * v34);
    v62.y = (float)(v29 * v35) - (float)(v31 * v34);
    v62.z = (float)(v28 * v35) - (float)(v30 * v34);
    v62.w = 0.0;
    v63.x = (float)(v32 * v35) + (float)(*(float *)&v69 * v34);
    v63.y = (float)(v29 * v34) + (float)(v31 * v35);
    *(_QWORD *)&v63.z = COERCE_UNSIGNED_INT((float)(v28 * v34) + (float)(v30 * v35));
    v37 = v5->z - (float)(v36 * 0.15000001);
    v38 = v5->y - (float)(COERCE_FLOAT(*(_QWORD *)&v4->x >> 32) * 0.15000001);
    v39 = v5->x - (float)(v4->x * 0.15000001);
    v65.x = v5->x - (float)(v4->x * 0.15000001);
    v65.y = v5->y - (float)(COERCE_FLOAT(*(_QWORD *)&v4->x >> 32) * 0.15000001);
    v40 = v10[2].mNode.mUID;
    if ( !v40 )
      goto LABEL_40;
    v41 = v40 - 1;
    if ( !v41 )
    {
      v43 = 0.0;
      v42 = *(float *)&FLOAT_1_0;
      goto LABEL_23;
    }
    if ( v41 == 2 )
    {
      v42 = *(float *)&FLOAT_1_0;
      if ( !(unsigned int)UFG::qRandom(2, &UFG::qDefaultSeed) )
      {
        v43 = 0.0;
LABEL_23:
        v44 = *(float *)&v10[1].mDebugName[12];
        v45 = (float)(UFG::qRandom(v42, &UFG::qDefaultSeed) * (float)(*(float *)&v10[1].mDebugName[16] - v44)) + v44;
        v46 = (float)SHIDWORD(v10[2].mNode.mChild[1]);
        if ( v46 < v42 )
          v46 = v42;
        v47 = COERCE_UNSIGNED_INT((float)(signed int)UFG::qRandom((signed int)v46, &UFG::qDefaultSeed));
        v48 = v42 / (float)(signed int)v46;
        v49 = *(float *)&v10[1].mDebugName[20];
        if ( v49 <= (float)(v45 * 2.0) )
          v49 = v45 * 2.0;
        v50 = v49 * 0.5;
        *((float *)&v66.mNext + 1) = v39 + v50;
        v65.z = v50 + v38;
        v65.w = v50 + v37;
        v51 = LODWORD(v50) ^ _xmm[0];
        *(float *)&v66.mPrev = v39 + *(float *)&v51;
        *((float *)&v66.mPrev + 1) = *(float *)&v51 + v38;
        *(float *)&v66.mNext = *(float *)&v51 + v37;
        v69 = &v68.mSettingsHandle;
        UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v68.mSettingsHandle.mPrev);
        Illusion::ModelProxy::ModelProxy(&v68.mModelProxy);
        *(_QWORD *)&v68.mRadius = 0i64;
        *(_QWORD *)&v68.mOneOverNumPages = 0i64;
        v52 = 0;
        v68.mBindIndex = 0;
        v69 = &v68.mComponentPtr;
        v68.mComponentPtr.mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v68.mComponentPtr.mPrev;
        v68.mComponentPtr.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *)&v68.mComponentPtr.mPrev;
        v68.mComponentPtr.m_pPointer = 0i64;
        v68.mScenery = 0i64;
        *(_QWORD *)&v68.mSequenceId = 0i64;
        v68.mIsValid = 1;
        v68.mMatrix.v0 = v62;
        v68.mMatrix.v1 = v63;
        v68.mMatrix.v2 = v64;
        v68.mMatrix.v3 = v65;
        v53 = v10->mNode.mUID;
        v54 = `UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result;
        if ( !`UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result )
        {
          v55 = UFG::qResourceWarehouse::Instance();
          v54 = UFG::qResourceWarehouse::GetInventory(v55, 0xAE323146);
          `UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result = v54;
        }
        UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v68.mSettingsHandle.mPrev, 0xAE323146, v53, v54);
        v68.mRadius = v45;
        LODWORD(v68.mTexOffset) = v47;
        v68.mOneOverNumPages = v48;
        v68.mTextureOrientation = v43;
        v68.mBindIndex = 0;
        v68.mSequenceId = v7->mCurSequenceID;
        Render::DecalManager::ProcessClipQueue(v7);
        if ( v7->mNumTestSceneryCallbacks )
        {
          do
          {
            v7->mTestSceneryCallback[v52](&v68, (UFG::qBox *)&v66);
            v56 = Render::gClipQueryManager.mClipQueue.mHead;
            if ( Render::gClipQueryManager.mClipQueue.mHead != Render::gClipQueryManager.mClipQueue.mTail )
            {
              do
              {
                if ( !Render::DecalClipQueryManager::ProcessClipRequest(
                        &Render::gClipQueryManager,
                        &Render::gClipQueryManager.mClipQueue.mQueue.p[v56]) )
                  break;
                v57 = Render::gClipQueryManager.mClipQueue.mHead + 1;
                v56 = (Render::gClipQueryManager.mClipQueue.mHead + 1)
                    % Render::gClipQueryManager.mClipQueue.mQueue.size;
                Render::gClipQueryManager.mClipQueue.mHead = (Render::gClipQueryManager.mClipQueue.mHead + 1)
                                                           % Render::gClipQueryManager.mClipQueue.mQueue.size;
                --Render::gClipQueryManager.mClipQueue.mCount;
              }
              while ( v57 % Render::gClipQueryManager.mClipQueue.mQueue.size != Render::gClipQueryManager.mClipQueue.mTail );
            }
            ++v52;
          }
          while ( v52 < v7->mNumTestSceneryCallbacks );
        }
        v7->mCurSequenceID = v68.mSequenceId;
        Render::DecalClipRequest::~DecalClipRequest(&v68);
        goto LABEL_35;
      }
    }
    else
    {
LABEL_40:
      v42 = *(float *)&FLOAT_1_0;
    }
    v43 = v42;
    goto LABEL_23;
  }
LABEL_35:
  v58 = `UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result )
  {
    v59 = UFG::qResourceWarehouse::Instance();
    v58 = UFG::qResourceWarehouse::GetInventory(v59, 0xAE323146);
    `UFG::qGetResourceInventory<Render::DecalSettings>'::`2'::result = v58;
  }
  UFG::qResourceHandle::Close(&v66, v58);
  UFG::qResourceHandle::~qResourceHandle(&v66);
}

// File Line: 1372
// RVA: 0x1C6B90
void __fastcall Render::DecalManager::AddClipQueue(Render::DecalManager *this, Render::DecalClipRequest *request)
{
  Render::DecalClipRequest *v2; // rbx

  v2 = request;
  Render::DecalClipRequestQueue::Add(&Render::gClipQueryManager.mClipQueue, request);
  v2->mSequenceId = (v2->mSequenceId + 1) % 0x1FA0;
}

// File Line: 1379
// RVA: 0x1C77E0
void __fastcall Render::DecalManager::AttachDecal(Render::DecalManager *this, Render::DecalClipQuery *dcq)
{
  unsigned int v2; // ebp
  __int64 v3; // rdi
  unsigned int v4; // er9
  __int64 v5; // r14
  Render::DecalManager *v6; // rsi
  unsigned int v7; // ebx
  unsigned int v8; // eax
  Render::DecalManager::DecalBucketConfig *v9; // rcx
  unsigned int v10; // eax
  __int64 v11; // r15
  char v12; // r9
  signed int v13; // ebx

  v2 = this->mDecalBuckets.size;
  v3 = 0i64;
  v4 = dcq->task_results->mNumPrims;
  v5 = dcq->decal_info->mSequenceID;
  ++Render::DecalManager::sDecalFragmentCountHistogram[v4 - 1];
  v6 = this;
  v7 = 0;
  v8 = 0;
  if ( v2 )
  {
    v9 = Render::DecalManager::sDecalBucketConfig;
    while ( v4 > v9->mFragmentCount )
    {
      ++v8;
      ++v9;
      if ( v8 >= v2 )
        goto LABEL_7;
    }
    v7 = v8;
  }
LABEL_7:
  v10 = Render::DecalArray::AttachDecal(&v6->mDecalBuckets.p[v7], dcq);
  v11 = v10;
  v6->mSequenceIdToBucketMask[v5] |= 1 << v7;
  if ( v10 != -1 )
  {
    v12 = ~(1 << v7);
    v13 = 1;
    v6->mSequenceIdToBucketMask[v10] &= v12;
    if ( v2 )
    {
      do
      {
        if ( (unsigned __int8)v13 & v6->mSequenceIdToBucketMask[v11] )
        {
          Render::DecalArray::RemoveSequence(&v6->mDecalBuckets.p[v3], v11);
          v6->mSequenceIdToBucketMask[v11] &= ~(1 << v3);
        }
        v13 = __ROL4__(v13, 1);
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < v2 );
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
        Render::gClipQueryManager.mClipQueue.mHead = (Render::gClipQueryManager.mClipQueue.mHead + 1)
                                                   % Render::gClipQueryManager.mClipQueue.mQueue.size )
  {
    if ( !Render::DecalClipQueryManager::ProcessClipRequest(
            &Render::gClipQueryManager,
            &Render::gClipQueryManager.mClipQueue.mQueue.p[i]) )
      break;
    --Render::gClipQueryManager.mClipQueue.mCount;
    i = (Render::gClipQueryManager.mClipQueue.mHead + 1) % Render::gClipQueryManager.mClipQueue.mQueue.size;
  }
}

// File Line: 1437
// RVA: 0x1D3B50
void __fastcall Render::DecalManager::Render(Render::DecalManager *this, Render::View *view, float fTime, Render::eFXDrawPass drawPass)
{
  Illusion::Material *decalMat; // rbp
  Render::eFXDrawPass v5; // er14
  Render::View *v6; // r15
  Render::DecalManager *v7; // rbx
  unsigned int v8; // eax
  __int64 v9; // rdi
  __int64 v10; // rsi

  decalMat = (Illusion::Material *)this->mDecalMat.mData;
  v5 = drawPass;
  v6 = view;
  v7 = this;
  if ( decalMat )
  {
    Render::DecalClipQueryManager::UpdateResults(&Render::gClipQueryManager);
    v8 = v7->mDecalBuckets.size;
    if ( v8 )
    {
      v9 = 0i64;
      v10 = v8;
      do
      {
        Render::DecalArray::Render(&v7->mDecalBuckets.p[v9], v6, fTime, v5, v7->mStateBlockIndex, decalMat);
        ++v9;
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
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceData *v4; // rbx
  UFG::qResourceWarehouse *v5; // rax
  Illusion::Material *v6; // rdi
  UFG::qResourceWarehouse *v7; // rax

  if ( !(_S1_24 & 1) )
  {
    _S1_24 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&decal_tex.mPrev);
    atexit(Render::DecalManager::GetSkinnedDecalMaterialUID_::_2_::_dynamic_atexit_destructor_for__decal_tex__);
  }
  if ( !material_init )
  {
    material_init = 1;
    v1 = sSDTextureUID;
    v2 = `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result )
    {
      v3 = UFG::qResourceWarehouse::Instance();
      v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x8B43FABF);
      `UFG::qGetResourceInventory<Illusion::Texture>'::`2'::result = v2;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&decal_tex.mPrev, 0x8B43FABF, v1, v2);
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
    LODWORD(v6[1].mResourceHandles.mNode.mNext) = (_DWORD)v4;
    LODWORD(v4) = UFG::qStringHashUpper32("V_BulletHole01_D", 0xFFFFFFFF);
    *(_WORD *)&v6[1].mDebugName[12] = 0;
    *(_DWORD *)&v6[1].mDebugName[8] = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    *(_DWORD *)&v6[1].mDebugName[4] = UFG::qStringHash32("texDiffuse", 0xFFFFFFFF);
    LODWORD(v6[1].mStateBlockMask.mFlags[1]) = -1958479169;
    LODWORD(v6[1].mStateBlockMask.mFlags[0]) = (_DWORD)v4;
    LODWORD(v4) = UFG::qStringHashUpper32("V_BulletHole01_S", 0xFFFFFFFF);
    LOWORD(v6[1].mMaterialUser.mOffset) = 0;
    *(&v6[1].mNumParams + 1) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    v6[1].mNumParams = UFG::qStringHash32("texSpecular", 0xFFFFFFFF);
    LODWORD(v6[2].mResourceHandles.mNode.mPrev) = -1958479169;
    v6[2].mNode.mUID = (unsigned int)v4;
    LODWORD(v4) = UFG::qStringHashUpper32("V_BulletHole01_N", 0xFFFFFFFF);
    LOWORD(v6[2].mTypeUID) = 0;
    HIDWORD(v6[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    LODWORD(v6[2].mResourceHandles.mNode.mNext) = UFG::qStringHash32("texBump", 0xFFFFFFFF);
    *((_DWORD *)&v6[2].0 + 22) = -1958479169;
    *(_DWORD *)&v6[2].mDebugName[28] = (_DWORD)v4;
    LODWORD(v4) = UFG::qStringHash32("SPHERICALENVMAPMAIN", 0xFFFFFFFF);
    LOWORD(v6[2].mStateBlockMask.mFlags[1]) = 0;
    HIDWORD(v6[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("iTexture", 0xFFFFFFFF);
    LODWORD(v6[2].mStateBlockMask.mFlags[0]) = UFG::qStringHash32("texSphericalMap", 0xFFFFFFFF);
    LODWORD(v6[3].mNode.mChild[1]) = -1958479169;
    LODWORD(v6[3].mNode.mChild[0]) = (_DWORD)v4;
    LOWORD(v6[3].mResourceHandles.mNode.mPrev) = 0;
    *(&v6[3].mNode.mUID + 1) = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    v6[3].mNode.mUID = UFG::qStringHash32("iAlphaState", 0xFFFFFFFF);
    *(_DWORD *)&v6[3].mDebugName[20] = 315097330;
    *(_DWORD *)&v6[3].mDebugName[12] = 662883558;
    LODWORD(v4) = sSDRasterStateUID;
    *((_WORD *)&v6[3].0 + 44) = 0;
    *(_DWORD *)&v6[3].mDebugName[32] = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    *(_DWORD *)&v6[3].mDebugName[28] = UFG::qStringHash32("iRasterState", 0xFFFFFFFF);
    LODWORD(v6[4].mNode.mParent) = 1002903008;
    LODWORD(v6[3].mMaterialUser.mOffset) = (_DWORD)v4;
    LODWORD(v4) = UFG::qStringHashUpper32("c8c29f94-7308-4cd9-ba62-736f78fdeda6", 0xFFFFFFFF);
    LOWORD(v6[4].mNode.mChild[1]) = 0;
    HIDWORD(v6[4].mNode.mChild[0]) = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
    LODWORD(v6[4].mNode.mChild[0]) = UFG::qStringHash32("sbDepthBiasSortLayer", 0xFFFFFFFF);
    *(_DWORD *)&v6[4].mDebugName[4] = 1292158962;
    v6[4].mTypeUID = (unsigned int)v4;
    LODWORD(v4) = UFG::qStringHashUpper32("d513fc25-10a4-4480-84d0-13aeef7d27bd", 0xFFFFFFFF);
    *(_WORD *)&v6[4].mDebugName[20] = 0;
    *(_DWORD *)&v6[4].mDebugName[16] = UFG::qStringHash32("sbVehicleLook", 0xFFFFFFFF);
    *(_DWORD *)&v6[4].mDebugName[12] = UFG::qStringHash32("sbVehicleLook", 0xFFFFFFFF);
    v6[4].mNumParams = 1292158962;
    LODWORD(v6[4].mStateBlockMask.mFlags[1]) = (_DWORD)v4;
    v7 = UFG::qResourceWarehouse::Instance();
    UFG::qResourceWarehouse::Add(v7, (UFG::qResourceData *)&v6->mNode);
  }
  return sSDMatUID;
}

// File Line: 1543
// RVA: 0x1CB7E0
void __fastcall Render::DecalManager::DrawPrimitive(Render::DecalManager *this, Render::View *view, Illusion::Primitive::Type prim_type, Render::vDecal *vertices, const int num_vertices, Illusion::Material *material, UFG::qMatrix44 *local_world)
{
  Render::vDecal *v7; // rbx
  Render::View *v8; // r14
  Illusion::StateArgs *v9; // r15
  unsigned int v10; // edi
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceWarehouse *v12; // rax
  Illusion::Primitive *v13; // r13
  char *v14; // rax
  const void *v15; // rsi
  unsigned __int16 v16; // ax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v17; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v18; // rax
  unsigned __int64 *v19; // rdx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v20; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v21; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v22; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v23; // rax
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v24; // rcx
  UFG::qNode<Illusion::StateArg,Illusion::StateArg> *v25; // rax
  Render::cbLocalTransformState arg; // [rsp+48h] [rbp-59h]
  Render::cbLocalProjectionState v27; // [rsp+70h] [rbp-31h]
  Illusion::SubmitContext *v28; // [rsp+F8h] [rbp+57h]
  Illusion::Primitive::Type prim_typea; // [rsp+100h] [rbp+5Fh]

  prim_typea = prim_type;
  v7 = vertices;
  v8 = view;
  v28 = view->mSubmitContext;
  Render::View::GetStateValues(view);
  v9 = Render::View::GetStateArgs(v8);
  if ( !(_S2_7 & 1) )
  {
    _S2_7 |= 1u;
    UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&vertex_decl_handle_2.mPrev);
    atexit(Render::DecalManager::DrawPrimitive_::_2_::_dynamic_atexit_destructor_for__vertex_decl_handle__);
  }
  if ( !vertex_decl_handle_2.mData )
  {
    v10 = UFG::qStringHash32("VertexDecl.Decal", 0xFFFFFFFF);
    v11 = `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result;
    if ( !`UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result )
    {
      v12 = UFG::qResourceWarehouse::Instance();
      v11 = UFG::qResourceWarehouse::GetInventory(v12, 0x3E5FDA3Eu);
      `UFG::qGetResourceInventory<Illusion::VertexDecl>'::`2'::result = v11;
    }
    UFG::qResourceHandle::Init((UFG::qResourceHandle *)&vertex_decl_handle_2.mPrev, 0x3E5FDA3Eu, v10, v11);
  }
  v13 = Illusion::Primitive::Create("DrawDecalPrimitive");
  if ( v13 && v7 )
  {
    if ( (unsigned __int8)UFG::qLinearAllocator::InFrame(Illusion::gEngine.FrameMemory, v7) )
    {
      v15 = v7;
    }
    else
    {
      v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 24 * num_vertices, 0x10u);
      v15 = v14;
      if ( !v14 )
        return;
      UFG::qMemCopy(v14, v7, 24 * num_vertices);
    }
    Illusion::Primitive::SetBuffers(
      v13,
      prim_typea,
      v15,
      num_vertices,
      (Illusion::VertexDecl *)vertex_decl_handle_2.mData,
      0i64,
      0,
      1);
    Render::cbLocalTransformState::cbLocalTransformState(
      &arg,
      &v8->mSettings->mWorldView,
      &v8->mWorldViewProjection,
      local_world);
    v27.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
    v27.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
    v27.mCallback = 0i64;
    v27.mStateParamIndex = Render::cbLocalProjectionState::sStateParamIndex;
    *(_WORD *)&v27.mFlags = 1;
    if ( (_WORD)Render::cbLocalProjectionState::sStateParamIndex == -1 )
    {
      v16 = Illusion::StateSystem::GetParam(&Illusion::gStateSystem, "cbLocalProjection");
      Render::cbLocalProjectionState::sStateParamIndex = v16;
      v27.mStateParamIndex = v16;
    }
    v27.mCached_Remote.m_Stream = 0i64;
    v27.mWorldViewProjection = &v8->mWorldViewProjection;
    v27.mLocalWorld = local_world;
    Illusion::StateArgs::Set<Render::cbLocalTransformState>(v9, &arg);
    Illusion::StateArgs::Set<Render::cbLocalProjectionState>(v9, &v27);
    Illusion::SubmitContext::Draw(v28, v13, material);
    v17 = v27.mPrev;
    v18 = v27.mNext;
    v27.mPrev->mNext = v27.mNext;
    v18->mPrev = v17;
    v27.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
    v27.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&v27;
    v27.mIsSet = 0;
    if ( (Illusion::StateArgs *)v9->mStateArgsCreateMask.mFlags[2 * (v27.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v9 + 16 * (v27.mStateParamIndex + 3i64)) )
    {
      v19 = &v9->mStateArgsCreateMask.mFlags[(unsigned int)v27.mStateParamIndex >> 6];
      *v19 &= ~(1i64 << (v27.mStateParamIndex & 0x3F));
    }
    v20 = arg.mPrev;
    v21 = arg.mNext;
    arg.mPrev->mNext = arg.mNext;
    v21->mPrev = v20;
    arg.mPrev = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mNext = (UFG::qNode<Illusion::StateArg,Illusion::StateArg> *)&arg;
    arg.mIsSet = 0;
    if ( (Illusion::StateArgs *)v9->mStateArgsCreateMask.mFlags[2 * (arg.mStateParamIndex + 3i64) + 1] == (Illusion::StateArgs *)((char *)v9 + 16 * (arg.mStateParamIndex + 3i64)) )
      v9->mStateArgsCreateMask.mFlags[(unsigned int)arg.mStateParamIndex >> 6] &= ~(1i64 << (arg.mStateParamIndex & 0x3F));
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

