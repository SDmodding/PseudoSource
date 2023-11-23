// File Line: 65
// RVA: 0x1453F20
__int64 dynamic_initializer_for__gDefaultCullLayer__()
{
  CullManager *v0; // rax
  UFG::qNode<CullLayer,CullLayer> *p_mNode; // rdx
  UFG::qNode<CullLayer,CullLayer> *mPrev; // rcx

  gDefaultCullLayer.mFrameCullBuckets.mNode.mPrev = &gDefaultCullLayer.mFrameCullBuckets.mNode;
  gDefaultCullLayer.mFrameCullBuckets.mNode.mNext = &gDefaultCullLayer.mFrameCullBuckets.mNode;
  gDefaultCullLayer.mPersistentCullBuckets.mNode.mPrev = &gDefaultCullLayer.mPersistentCullBuckets.mNode;
  gDefaultCullLayer.mPersistentCullBuckets.mNode.mNext = &gDefaultCullLayer.mPersistentCullBuckets.mNode;
  `eh vector constructor iterator(
    (char *)gDefaultCullLayer.mCullResultBuckets,
    8ui64,
    16,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  gDefaultCullLayer.mType = TYPE_CULL;
  gDefaultCullLayer.mName = "Default Cull Layer";
  gDefaultCullLayer.mDrawEnabled = 1;
  *(_QWORD *)&gDefaultCullLayer.pad0 = 0i64;
  gDefaultCullLayer.pad2 = 0;
  v0 = CullManager::Instance();
  p_mNode = &v0->mCullLayers[gDefaultCullLayer.mType].mNode;
  mPrev = p_mNode->mPrev;
  mPrev->mNext = &gDefaultCullLayer;
  gDefaultCullLayer.mPrev = mPrev;
  gDefaultCullLayer.mNext = p_mNode;
  p_mNode->mPrev = &gDefaultCullLayer;
  ++v0->mNumCullLayers;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDefaultCullLayer__);
}

// File Line: 66
// RVA: 0x1454000
__int64 dynamic_initializer_for__gDefaultOcclusionLayer__()
{
  CullManager *v0; // rax
  UFG::qNode<CullLayer,CullLayer> *p_mNode; // rdx
  UFG::qNode<CullLayer,CullLayer> *mPrev; // rcx

  gDefaultOcclusionLayer.mFrameCullBuckets.mNode.mPrev = &gDefaultOcclusionLayer.mFrameCullBuckets.mNode;
  gDefaultOcclusionLayer.mFrameCullBuckets.mNode.mNext = &gDefaultOcclusionLayer.mFrameCullBuckets.mNode;
  gDefaultOcclusionLayer.mPersistentCullBuckets.mNode.mPrev = &gDefaultOcclusionLayer.mPersistentCullBuckets.mNode;
  gDefaultOcclusionLayer.mPersistentCullBuckets.mNode.mNext = &gDefaultOcclusionLayer.mPersistentCullBuckets.mNode;
  `eh vector constructor iterator(
    (char *)gDefaultOcclusionLayer.mCullResultBuckets,
    8ui64,
    16,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  gDefaultOcclusionLayer.mType = TYPE_OCCLUSION;
  gDefaultOcclusionLayer.mName = "Default Occlusion Layer";
  gDefaultOcclusionLayer.mDrawEnabled = 1;
  *(_QWORD *)&gDefaultOcclusionLayer.pad0 = 0i64;
  gDefaultOcclusionLayer.pad2 = 0;
  v0 = CullManager::Instance();
  p_mNode = &v0->mCullLayers[gDefaultOcclusionLayer.mType].mNode;
  mPrev = p_mNode->mPrev;
  mPrev->mNext = &gDefaultOcclusionLayer;
  gDefaultOcclusionLayer.mPrev = mPrev;
  gDefaultOcclusionLayer.mNext = p_mNode;
  p_mNode->mPrev = &gDefaultOcclusionLayer;
  ++v0->mNumCullLayers;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gDefaultOcclusionLayer__);
}

// File Line: 80
// RVA: 0x27450
void __fastcall TransformAABB(UFG::qMatrix44 *m, UFG::qVector3 *min, UFG::qVector3 *max)
{
  float x; // eax
  float z; // xmm2_4
  float *p_z; // rcx
  float y; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // eax
  float v13; // xmm1_4
  __int64 v14; // rax
  __int64 v15; // r9
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm2_4
  float v28; // xmm1_4
  int v29[4]; // [rsp+0h] [rbp-28h]
  int v30[6]; // [rsp+10h] [rbp-18h]

  x = m->v3.x;
  z = m->v3.z;
  p_z = &m->v0.z;
  y = min->y;
  v29[0] = LODWORD(min->x);
  v29[2] = LODWORD(min->z);
  v7 = max->y;
  *(float *)&v29[1] = y;
  v8 = max->x;
  *(float *)&v30[1] = v7;
  v9 = p_z[11];
  *(float *)v30 = v8;
  v10 = max->z;
  min->y = v9;
  min->x = x;
  min->z = z;
  v11 = p_z[11];
  *(float *)&v30[2] = v10;
  v12 = p_z[10];
  v13 = p_z[12];
  max->y = v11;
  max->x = v12;
  v14 = 0i64;
  v15 = 3i64;
  max->z = v13;
  do
  {
    v16 = *(float *)&v29[v14];
    v17 = *(float *)&v30[v14];
    v18 = *(p_z - 2);
    v19 = v18 * v17;
    v20 = v18 * v16;
    if ( v20 >= v19 )
      v21 = v19;
    else
      v21 = v20;
    min->x = v21 + min->x;
    if ( v20 >= v19 )
      v19 = v20;
    max->x = v19 + max->x;
    v22 = *(p_z - 1);
    v23 = v22 * v17;
    v24 = v22 * v16;
    if ( v24 >= v23 )
      v25 = v23;
    else
      v25 = v24;
    min->y = v25 + min->y;
    if ( v24 >= v23 )
      v23 = v24;
    max->y = v23 + max->y;
    v26 = *p_z * v17;
    v27 = *p_z * v16;
    if ( v27 >= v26 )
      v28 = *p_z * v17;
    else
      v28 = *p_z * v16;
    min->z = v28 + min->z;
    if ( v27 >= v26 )
      v26 = v27;
    p_z += 4;
    ++v14;
    max->z = v26 + max->z;
    --v15;
  }
  while ( v15 );
}

// File Line: 149
// RVA: 0x27010
__int64 __fastcall InFrustum(UFG::qVector4 *planes, UFG::qVector3 *point)
{
  __int64 v2; // rax
  float *i; // rcx

  v2 = 0i64;
  for ( i = &planes->z;
        (float)((float)((float)((float)(point->y * *(i - 1)) + (float)(point->x * *(i - 2))) + (float)(point->z * *i))
              + i[1]) <= 0.0;
        i += 4 )
  {
    if ( ++v2 >= 6 )
      return 1i64;
  }
  return 0i64;
}

// File Line: 162
// RVA: 0x26B40
float __fastcall DistanceToFrustum(UFG::qVector4 *planes, UFG::qVector3 *point)
{
  float y; // xmm3_4
  float x; // xmm5_4
  float v4; // xmm2_4
  float z; // xmm6_4
  float v6; // xmm3_4

  y = point->y;
  x = point->x;
  v4 = 0.0;
  z = point->z;
  if ( (float)((float)((float)((float)(y * planes->y) + (float)(point->x * planes->x)) + (float)(z * planes->z))
             + planes->w) > 0.0 )
    v4 = (float)((float)((float)(point->y * planes->y) + (float)(point->x * planes->x)) + (float)(point->z * planes->z))
       + planes->w;
  if ( (float)((float)((float)((float)(y * planes[1].y) + (float)(x * planes[1].x)) + (float)(z * planes[1].z))
             + planes[1].w) > v4 )
    v4 = (float)((float)((float)(y * planes[1].y) + (float)(x * planes[1].x)) + (float)(z * planes[1].z)) + planes[1].w;
  if ( (float)((float)((float)((float)(y * planes[2].y) + (float)(x * planes[2].x)) + (float)(z * planes[2].z))
             + planes[2].w) > v4 )
    v4 = (float)((float)((float)(y * planes[2].y) + (float)(x * planes[2].x)) + (float)(z * planes[2].z)) + planes[2].w;
  if ( (float)((float)((float)((float)(y * planes[3].y) + (float)(x * planes[3].x)) + (float)(z * planes[3].z))
             + planes[3].w) > v4 )
    v4 = (float)((float)((float)(y * planes[3].y) + (float)(x * planes[3].x)) + (float)(z * planes[3].z)) + planes[3].w;
  if ( (float)((float)((float)((float)(y * planes[4].y) + (float)(x * planes[4].x)) + (float)(z * planes[4].z))
             + planes[4].w) > v4 )
    v4 = (float)((float)((float)(y * planes[4].y) + (float)(x * planes[4].x)) + (float)(z * planes[4].z)) + planes[4].w;
  v6 = (float)((float)((float)(y * planes[5].y) + (float)(x * planes[5].x)) + (float)(z * planes[5].z)) + planes[5].w;
  if ( v6 <= v4 )
    return v4;
  else
    return v6;
}

// File Line: 188
// RVA: 0x25610
void __fastcall CullLayer::CullLayer(CullLayer *this, CullLayer::CullLayerType type, const char *name)
{
  CullManager *v6; // rax
  UFG::qNode<CullLayer,CullLayer> *p_mNode; // rdx
  UFG::qNode<CullLayer,CullLayer> *mPrev; // rcx

  this->mPrev = this;
  this->mNext = this;
  this->mFrameCullBuckets.mNode.mPrev = &this->mFrameCullBuckets.mNode;
  this->mFrameCullBuckets.mNode.mNext = &this->mFrameCullBuckets.mNode;
  this->mPersistentCullBuckets.mNode.mPrev = &this->mPersistentCullBuckets.mNode;
  this->mPersistentCullBuckets.mNode.mNext = &this->mPersistentCullBuckets.mNode;
  `eh vector constructor iterator(
    this->mCullResultBuckets,
    8ui64,
    16,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  this->mType = type;
  this->mName = name;
  this->mDrawEnabled = 1;
  *(_QWORD *)&this->pad0 = 0i64;
  this->pad2 = 0;
  v6 = CullManager::Instance();
  p_mNode = &v6->mCullLayers[this->mType].mNode;
  mPrev = p_mNode->mPrev;
  mPrev->mNext = this;
  this->mPrev = mPrev;
  this->mNext = p_mNode;
  p_mNode->mPrev = this;
  ++v6->mNumCullLayers;
}

// File Line: 202
// RVA: 0x25990
void __fastcall CullLayer::~CullLayer(CullLayer *this)
{
  CullManager *v2; // rax
  UFG::qNode<CullLayer,CullLayer> *mPrev; // rdx
  UFG::qNode<CullLayer,CullLayer> *mNext; // rcx
  UFG::qNode<CullBucket,CullBucket> *v5; // rcx
  UFG::qNode<CullBucket,CullBucket> *v6; // rax
  UFG::qNode<CullBucket,CullBucket> *v7; // rcx
  UFG::qNode<CullBucket,CullBucket> *v8; // rax
  UFG::qNode<CullLayer,CullLayer> *v9; // rcx
  UFG::qNode<CullLayer,CullLayer> *v10; // rax

  v2 = CullManager::Instance();
  if ( this )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
    --v2->mNumCullLayers;
  }
  `eh vector destructor iterator(
    this->mCullResultBuckets,
    8ui64,
    16,
    (void (__fastcall *)(void *))UFG::qSList<CullResultBucket,CullResultBucket,1>::~qSList<CullResultBucket,CullResultBucket,1>);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&this->mPersistentCullBuckets);
  v5 = this->mPersistentCullBuckets.mNode.mPrev;
  v6 = this->mPersistentCullBuckets.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->mPersistentCullBuckets.mNode.mPrev = &this->mPersistentCullBuckets.mNode;
  this->mPersistentCullBuckets.mNode.mNext = &this->mPersistentCullBuckets.mNode;
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes((UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&this->mFrameCullBuckets);
  v7 = this->mFrameCullBuckets.mNode.mPrev;
  v8 = this->mFrameCullBuckets.mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mFrameCullBuckets.mNode.mPrev = &this->mFrameCullBuckets.mNode;
  this->mFrameCullBuckets.mNode.mNext = &this->mFrameCullBuckets.mNode;
  v9 = this->mPrev;
  v10 = this->mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 225
// RVA: 0x256D0
void __fastcall PersistentCullBucket::PersistentCullBucket(
        PersistentCullBucket *this,
        int alloc_results,
        unsigned int num_cull_infos,
        int sizeof_cull_info)
{
  CullInfo *v8; // rsi
  unsigned int v9; // ebp
  unsigned int v10; // r14d
  CullResults *v11; // rbx
  char *v12; // r15
  CullInfoFull *v13; // rax

  this->mPrev = this;
  this->mNext = this;
  v8 = 0i64;
  this->mCullInfos = 0i64;
  this->mFullCullInfos = 0i64;
  this->mResults = 0i64;
  *(_QWORD *)&this->mType = 0i64;
  this->mCullInfosAlloced = 0;
  UFG::qFixedAllocator::qFixedAllocator(&this->mFixedAllocator);
  v9 = ((num_cull_infos << 6) + 31) & 0xFFFFFFE0;
  v10 = sizeof_cull_info * num_cull_infos;
  if ( alloc_results )
    v11 = (CullResults *)UFG::qMalloc(v9, "PersistentCullBucket_mCullResults", 0x2000ui64);
  else
    v11 = 0i64;
  v12 = UFG::qMalloc(v10, "PersistentCullBucket_mCullInfos", 0x2000ui64);
  if ( v11 )
    UFG::qMemSet(v11, 0, v9);
  UFG::qMemSet(v12, 0, v10);
  this->mType = 2;
  this->mResults = v11;
  v13 = 0i64;
  if ( sizeof_cull_info == 128 )
    v13 = (CullInfoFull *)v12;
  this->mFullCullInfos = v13;
  if ( sizeof_cull_info == 64 )
    v8 = (CullInfo *)v12;
  this->mCullInfos = v8;
  this->mMax = num_cull_infos;
  this->mCullInfosAlloced = num_cull_infos;
  UFG::qFixedAllocator::Init(&this->mFixedAllocator, v12, v10, sizeof_cull_info, "PersistentCullBucket");
}

// File Line: 253
// RVA: 0x25A60
void __fastcall PersistentCullBucket::~PersistentCullBucket(PersistentCullBucket *this)
{
  CullInfoFull *mFullCullInfos; // rbx
  CullInfo *mCullInfos; // rdi
  UFG::qNode<CullBucket,CullBucket> *mPrev; // rcx
  UFG::qNode<CullBucket,CullBucket> *mNext; // rax

  mFullCullInfos = this->mFullCullInfos;
  mCullInfos = this->mCullInfos;
  operator delete[](this->mResults);
  operator delete[](mFullCullInfos);
  operator delete[](mCullInfos);
  this->mResults = 0i64;
  this->mFullCullInfos = 0i64;
  this->mCullInfos = 0i64;
  UFG::qFixedAllocator::Close(&this->mFixedAllocator);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 424
// RVA: 0x27380
void __fastcall CullManager::CullSettings::SetFromViewSettings(
        CullManager::CullSettings *this,
        Render::ViewSettings *view_settings)
{
  float z; // xmm0_4
  float v5; // xmm6_4
  float v6; // xmm7_4
  float x; // xmm0_4
  float y; // xmm1_4
  float v9; // xmm0_4
  UFG::qMatrix44 *v10; // rax
  UFG::qVector4 v11; // xmm3
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::qMatrix44 d; // [rsp+20h] [rbp-A8h] BYREF
  UFG::qMatrix44 result; // [rsp+60h] [rbp-68h] BYREF

  z = view_settings->mProjection.v2.z;
  v5 = view_settings->mProjection.v3.z / z;
  v6 = (float)(view_settings->mProjection.v3.z - view_settings->mProjection.v3.w)
     / (float)(z - view_settings->mProjection.v2.w);
  UFG::qInverseAffine(&d, &view_settings->mWorldView);
  x = d.v3.x;
  y = d.v3.y;
  this->mFarPlane = v6;
  this->mNearPlane = v5;
  this->mPixelDensityThreshold = view_settings->mCullPixelDensityThreshold;
  this->mPixelDistanceBias = view_settings->mCullPixelDistanceBias;
  this->mViewWorldPos.x = x;
  v9 = d.v3.z;
  this->mViewWorldPos.y = y;
  this->mViewWorldPos.z = v9;
  v10 = UFG::qMatrix44::operator*(&view_settings->mWorldView, &result, &view_settings->mProjection);
  v11 = v10->v1;
  v12 = v10->v2;
  v13 = v10->v3;
  this->mWorldViewProjection.v0 = v10->v0;
  this->mWorldViewProjection.v1 = v11;
  this->mWorldViewProjection.v2 = v12;
  this->mWorldViewProjection.v3 = v13;
}

// File Line: 460
// RVA: 0x27210
CullManager *__fastcall CullManager::Instance()
{
  if ( (_S1_2 & 1) == 0 )
  {
    _S1_2 |= 1u;
    `eh vector constructor iterator(
      sCullManager.mCullLayers,
      0x10ui64,
      2,
      (void (__fastcall *)(void *))UFG::qReflectHandleBase::qReflectHandleBase);
    TheCullManager = &sCullManager;
    *(_QWORD *)&sCullManager.mNumCullLayers = 0i64;
    sCullManager.mNumOcclusionBuckets = 0;
    atexit(CullManager::Instance_::_2_::_dynamic_atexit_destructor_for__sCullManager__);
  }
  return &sCullManager;
}

// File Line: 467
// RVA: 0x27080
void __fastcall CullManager::Init(CullManager *this, UFG::qMemoryPool *texture_pool)
{
  UFG::qNode<CullLayer,CullLayer> **p_mNext; // rsi
  UFG::qList<CullLayer,CullLayer,1,0> *mCullLayers; // rdi
  __int64 v5; // rbp
  UFG::qNode<CullLayer,CullLayer> *i; // rbx
  UFG::qString v7; // [rsp+28h] [rbp-30h] BYREF

  *(_QWORD *)this->mViewSlots = 0i64;
  *(_QWORD *)&this->mViewSlots[2] = 0i64;
  *(_QWORD *)&this->mViewSlots[4] = 0i64;
  *(_QWORD *)&this->mViewSlots[6] = 0i64;
  *(_QWORD *)&this->mViewSlots[8] = 0i64;
  *(_QWORD *)&this->mViewSlots[10] = 0i64;
  *(_QWORD *)&this->mViewSlots[12] = 0i64;
  *(_QWORD *)&this->mViewSlots[14] = 0i64;
  this->mPixelDensityDynamicBias = 1;
  this->mZbuffer1 = UFG::qMalloc(0x10080ui64, "CullManager::mZbuffer", 0x8000ui64);
  this->mZbuffer2 = UFG::qMalloc(0x10080ui64, "CullManager::mZbuffer", 0x8000ui64);
  this->mZbuffer3 = UFG::qMalloc(0x10080ui64, "CullManager::mZbuffer", 0x8000ui64);
  this->mZbuffer4 = UFG::qMalloc(0x10080ui64, "CullManager::mZbuffer", 0x8000ui64);
  this->mOcclusionDebugTexture = 0i64;
  *(_WORD *)&this->mEnableOcclusionCulling = 1;
  *(_QWORD *)&this->mDrawCullInfoNum = 0i64;
  this->mDrawOcclusionMapScale = 0;
  this->mDrawOcclusionMapOpacity = 0.30000001;
  this->mDetailedCullInfoIndex = 0;
  this->mDetailedCullInfoLocked = 0;
  p_mNext = &this->mCullLayers[0].mNode.mNext;
  mCullLayers = this->mCullLayers;
  v5 = 2i64;
  do
  {
    for ( i = *p_mNext; i != (UFG::qNode<CullLayer,CullLayer> *)mCullLayers; i = i->mNext )
    {
      UFG::qString::qString(&v7);
      UFG::qString::Format(&v7, "\\Rendering\\Culling\\Layers\\%s", (const char *)i[1].mNext);
      UFG::qString::~qString(&v7);
    }
    ++mCullLayers;
    p_mNext += 2;
    --v5;
  }
  while ( v5 );
  _((AMD_HD3D *)this);
}

// File Line: 896
// RVA: 0x272A0
__int64 __fastcall CullManager::RegisterView(CullManager *this, CullManager::CullSettings *view_settings)
{
  unsigned int v2; // r8d
  __int64 v4; // rax
  __int64 result; // rax
  UFG::qVector4 v6; // xmm1
  __int64 v7; // rdx
  UFG::qVector4 v8; // xmm3
  UFG::qVector4 v9; // xmm2
  float y; // xmm0_4

  v2 = 0;
  v4 = 0i64;
  while ( this->mViewSlots[v4] )
  {
    ++v4;
    ++v2;
    if ( v4 >= 16 )
      return 0i64;
  }
  if ( v2 == -1 )
    return 0i64;
  this->mViewSlots[v2] = VIEW_SLOT_ALLOCATED;
  v6 = view_settings->mWorldViewProjection.v3;
  v7 = (int)v2;
  v8 = view_settings->mWorldViewProjection.v1;
  v9 = view_settings->mWorldViewProjection.v2;
  this->mViewSettings[v7].mWorldViewProjection.v0 = view_settings->mWorldViewProjection.v0;
  this->mViewSettings[v7].mWorldViewProjection.v1 = v8;
  this->mViewSettings[v7].mWorldViewProjection.v2 = v9;
  this->mViewSettings[v7].mWorldViewProjection.v3 = v6;
  this->mViewSettings[v7].mNearPlane = view_settings->mNearPlane;
  this->mViewSettings[v7].mFarPlane = view_settings->mFarPlane;
  this->mViewSettings[v7].mPixelDensityThreshold = view_settings->mPixelDensityThreshold;
  result = v2;
  this->mViewSettings[v7].mPixelDistanceBias = view_settings->mPixelDistanceBias;
  this->mViewSettings[v7].mViewFlags = view_settings->mViewFlags;
  this->mViewSettings[v7].mViewUserFilter = view_settings->mViewUserFilter;
  y = view_settings->mViewWorldPos.y;
  v6.x = view_settings->mViewWorldPos.z;
  this->mViewSettings[v7].mViewWorldPos.x = view_settings->mViewWorldPos.x;
  this->mViewSettings[v7].mViewWorldPos.y = y;
  this->mViewSettings[v7].mViewWorldPos.z = v6.x;
  return result;
}

// File Line: 921
// RVA: 0x26AE0
void __fastcall CullManager::DeregisterView(CullManager *this, int view_index)
{
  Render::RasterizeZ *mRasterizers; // rcx
  __int64 v4; // rbx

  if ( view_index != -1 )
  {
    mRasterizers = this->mRasterizers;
    v4 = view_index;
    *((_DWORD *)&mRasterizers[-32] + view_index - 12) = 0;
    Render::RasterizeZ::Init(&mRasterizers[view_index], 0i64, 1);
    Render::OcclusionMap::Init(&this->mOcclusionMaps[v4], 0i64);
  }
}

// File Line: 933
// RVA: 0x26A60
void __fastcall CullManager::DeregisterAllViews(CullManager *this)
{
  CullManager *v1; // rdi
  Render::OcclusionMap *mOcclusionMaps; // rsi
  int v3; // ebx
  Render::RasterizeZ *mRasterizers; // rbp

  v1 = this;
  mOcclusionMaps = this->mOcclusionMaps;
  v3 = 0;
  mRasterizers = this->mRasterizers;
  do
  {
    if ( v3 != -1 )
    {
      v1->mViewSlots[0] = VIEW_SLOT_AVAILABLE;
      Render::RasterizeZ::Init(mRasterizers, 0i64, 1);
      Render::OcclusionMap::Init(mOcclusionMaps, 0i64);
    }
    ++v3;
    ++mRasterizers;
    ++mOcclusionMaps;
    v1 = (CullManager *)((char *)v1 + 4);
  }
  while ( v3 < 16 );
}

// File Line: 966
// RVA: 0x26F60
UFG::qList<CullBucket,CullBucket,1,0> *__fastcall GetEmptyCullBucket(
        UFG::qList<CullBucket,CullBucket,1,0> *bucket_list,
        int alloc_results,
        unsigned int max_cull_infos,
        int sizeof_cull_info)
{
  UFG::qList<CullBucket,CullBucket,1,0> *result; // rax
  char *v9; // rax
  UFG::qNode<CullBucket,CullBucket> *v10; // rax
  UFG::qNode<CullBucket,CullBucket> *v11; // rcx
  UFG::qNode<CullBucket,CullBucket> *mNext; // rax

  result = (UFG::qList<CullBucket,CullBucket,1,0> *)bucket_list->mNode.mNext;
  if ( result != bucket_list )
  {
    while ( result[5].mNode.mNext )
    {
      if ( !alloc_results || result[2].mNode.mPrev )
        return result;
      result = (UFG::qList<CullBucket,CullBucket,1,0> *)result->mNode.mNext;
      if ( result == bucket_list )
        break;
    }
  }
  v9 = UFG::qMalloc(0x70ui64, "PersistentCullBucket", 0x800ui64);
  if ( v9 )
  {
    PersistentCullBucket::PersistentCullBucket(
      (PersistentCullBucket *)v9,
      alloc_results,
      max_cull_infos,
      sizeof_cull_info);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  mNext = bucket_list->mNode.mNext;
  bucket_list->mNode.mNext = v11;
  v11->mPrev = &bucket_list->mNode;
  v11->mNext = mNext;
  mNext->mPrev = v11;
  return (UFG::qList<CullBucket,CullBucket,1,0> *)v11;
}

// File Line: 1008
// RVA: 0x25B90
void __fastcall CullManager::AllocPersistentCullInfo(
        CullManager *this,
        CullResults **cull_result,
        CullInfo **cull_info,
        CullLayer *cull_layer,
        void *cull_info_param0,
        void *cull_info_param1)
{
  CullLayer *v8; // r13
  UFG::qList<CullBucket,CullBucket,1,0> *p_mPersistentCullBuckets; // r14
  PersistentCullBucket *EmptyCullBucket; // rax
  PersistentCullBucket *v11; // rbx
  char *mFreeListHead; // rdi
  char *v13; // rcx
  unsigned int mMostSlotsAllocated; // edx
  unsigned __int64 v15; // rdx
  UFG::qNode<CullBucket,CullBucket> *mNext; // rax
  UFG::qNode<CullBucket,CullBucket> *mPrev; // rcx
  UFG::qNode<CullBucket,CullBucket> *v18; // rax

  if ( cull_info )
  {
    v8 = &gDefaultCullLayer;
    if ( cull_layer )
      v8 = cull_layer;
    p_mPersistentCullBuckets = &v8->mPersistentCullBuckets;
    EmptyCullBucket = GetEmptyCullBucket(&v8->mPersistentCullBuckets, cull_result != 0i64, 256, 64);
    v11 = EmptyCullBucket;
    mFreeListHead = EmptyCullBucket->mFixedAllocator.mFreeListHead;
    if ( mFreeListHead )
    {
      v13 = *(char **)mFreeListHead;
      mMostSlotsAllocated = ++EmptyCullBucket->mFixedAllocator.mNumSlotsAllocated;
      EmptyCullBucket->mFixedAllocator.mFreeListHead = v13;
      if ( EmptyCullBucket->mFixedAllocator.mMostSlotsAllocated > mMostSlotsAllocated )
        mMostSlotsAllocated = EmptyCullBucket->mFixedAllocator.mMostSlotsAllocated;
      EmptyCullBucket->mFixedAllocator.mMostSlotsAllocated = mMostSlotsAllocated;
    }
    else
    {
      UFG::qFixedAllocator::ReportFull(&EmptyCullBucket->mFixedAllocator);
    }
    v15 = (unsigned __int64)(unsigned int)((mFreeListHead - v11->mFixedAllocator.mBuffer)
                                         / v11->mFixedAllocator.mSlotSize) << 6;
    *cull_info = (CullInfo *)((char *)v11->mCullInfos + v15);
    if ( cull_result )
      *cull_result = (CullResults *)((char *)v11->mResults + v15);
    *((_QWORD *)mFreeListHead + 4) = v8;
    *((_QWORD *)mFreeListHead + 5) = cull_info_param0;
    *((_QWORD *)mFreeListHead + 7) = 0i64;
    *((_QWORD *)mFreeListHead + 6) = cull_info_param1;
    if ( !v11->mFixedAllocator.mFreeListHead )
    {
      mNext = v11->mNext;
      mPrev = v11->mPrev;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      v11->mPrev = v11;
      v11->mNext = v11;
      v18 = p_mPersistentCullBuckets->mNode.mPrev;
      v18->mNext = v11;
      v11->mPrev = v18;
      v11->mNext = &p_mPersistentCullBuckets->mNode;
      p_mPersistentCullBuckets->mNode.mPrev = v11;
    }
  }
}

// File Line: 1048
// RVA: 0x25CC0
void __fastcall CullManager::AllocPersistentOcclusionInfo(
        CullManager *this,
        CullInfoFull **occlusion_info,
        CullLayer *cull_layer)
{
  CullLayer *v4; // rbp
  UFG::qList<CullBucket,CullBucket,1,0> *p_mPersistentCullBuckets; // r14
  UFG::qList<CullBucket,CullBucket,1,0> *mNext; // rsi
  char *v7; // rax
  char *v8; // rbx
  UFG::qNode<CullBucket,CullBucket> *v9; // rax
  CullInfoFull *v10; // rbx
  unsigned int v11; // ecx
  UFG::qNode<CullBucket,CullBucket> *mPrev; // rcx
  UFG::qNode<CullBucket,CullBucket> *v13; // rax
  UFG::qNode<CullBucket,CullBucket> *v14; // rax

  if ( occlusion_info )
  {
    v4 = &gDefaultOcclusionLayer;
    if ( cull_layer )
      v4 = cull_layer;
    p_mPersistentCullBuckets = &v4->mPersistentCullBuckets;
    mNext = (UFG::qList<CullBucket,CullBucket,1,0> *)v4->mPersistentCullBuckets.mNode.mNext;
    if ( mNext == &v4->mPersistentCullBuckets || !mNext[5].mNode.mNext )
    {
      v7 = UFG::qMalloc(0x70ui64, "PersistentCullBucket", 0x800ui64);
      mNext = (UFG::qList<CullBucket,CullBucket,1,0> *)v7;
      if ( v7 )
      {
        *(_QWORD *)v7 = v7;
        *((_QWORD *)v7 + 1) = v7;
        *((_QWORD *)v7 + 2) = 0i64;
        *((_QWORD *)v7 + 3) = 0i64;
        *((_QWORD *)v7 + 4) = 0i64;
        *((_QWORD *)v7 + 5) = 0i64;
        *((_DWORD *)v7 + 12) = 0;
        UFG::qFixedAllocator::qFixedAllocator((UFG::qFixedAllocator *)(v7 + 64));
        v8 = UFG::qMalloc(0x8000ui64, "PersistentCullBucket_mCullInfos", 0x2000ui64);
        UFG::qMemSet(v8, 0, 0x8000u);
        LODWORD(mNext[2].mNode.mNext) = 2;
        mNext[2].mNode.mPrev = 0i64;
        mNext[1].mNode.mNext = (UFG::qNode<CullBucket,CullBucket> *)v8;
        mNext[1].mNode.mPrev = 0i64;
        HIDWORD(mNext[2].mNode.mNext) = 256;
        LODWORD(mNext[3].mNode.mPrev) = 256;
        UFG::qFixedAllocator::Init((UFG::qFixedAllocator *)&mNext[4], v8, 0x8000, 128, "PersistentCullBucket");
      }
      else
      {
        mNext = 0i64;
      }
      v9 = v4->mPersistentCullBuckets.mNode.mNext;
      v4->mPersistentCullBuckets.mNode.mNext = &mNext->mNode;
      mNext->mNode.mPrev = &p_mPersistentCullBuckets->mNode;
      mNext->mNode.mNext = v9;
      v9->mPrev = &mNext->mNode;
    }
    v10 = (CullInfoFull *)mNext[5].mNode.mNext;
    if ( v10 )
    {
      mNext[5].mNode.mNext = *(UFG::qNode<CullBucket,CullBucket> **)v10->mAABBMin;
      v11 = ++HIDWORD(mNext[6].mNode.mPrev);
      if ( LODWORD(mNext[6].mNode.mNext) > v11 )
        v11 = (unsigned int)mNext[6].mNode.mNext;
      LODWORD(mNext[6].mNode.mNext) = v11;
    }
    else
    {
      UFG::qFixedAllocator::ReportFull((UFG::qFixedAllocator *)&mNext[4]);
    }
    *occlusion_info = v10;
    v10->mCullLayer = v4;
    if ( !mNext[5].mNode.mNext )
    {
      mPrev = mNext->mNode.mPrev;
      v13 = mNext->mNode.mNext;
      mPrev->mNext = v13;
      v13->mPrev = mPrev;
      mNext->mNode.mPrev = &mNext->mNode;
      mNext->mNode.mNext = &mNext->mNode;
      v14 = p_mPersistentCullBuckets->mNode.mPrev;
      v14->mNext = &mNext->mNode;
      mNext->mNode.mPrev = v14;
      mNext->mNode.mNext = &p_mPersistentCullBuckets->mNode;
      p_mPersistentCullBuckets->mNode.mPrev = &mNext->mNode;
    }
  }
}

// File Line: 1077
// RVA: 0x26D40
void __fastcall CullManager::FreePersistentCullInfo(CullManager *this, CullResults *cull_result, CullInfo *cull_info)
{
  CullLayer *mCullLayer; // rsi
  PersistentCullBucket *mNext; // rbx
  PersistentCullBucket *p_mPersistentCullBuckets; // rsi
  unsigned __int64 mBuffer; // rcx
  __int64 v9; // r14
  CullResults *mResults; // rax
  UFG::qNode<CullBucket,CullBucket> *v11; // rax
  UFG::qNode<CullBucket,CullBucket> *mPrev; // rcx
  PersistentCullBucket **v13; // rax

  if ( cull_info )
  {
    mCullLayer = cull_info->mCullLayer;
    mNext = (PersistentCullBucket *)mCullLayer->mPersistentCullBuckets.mNode.mNext;
    p_mPersistentCullBuckets = (PersistentCullBucket *)&mCullLayer->mPersistentCullBuckets;
    if ( mNext != p_mPersistentCullBuckets )
    {
      while ( 1 )
      {
        mBuffer = (unsigned __int64)mNext->mFixedAllocator.mBuffer;
        if ( (unsigned __int64)cull_info < mBuffer + mNext->mFixedAllocator.mBufferSize
          && (unsigned __int64)cull_info >= mBuffer )
        {
          break;
        }
        mNext = (PersistentCullBucket *)mNext->mNext;
        if ( mNext == p_mPersistentCullBuckets )
          return;
      }
      if ( mNext )
      {
        v9 = (__int64)(int)((__int64)((__int64)cull_info - mBuffer) / mNext->mFixedAllocator.mSlotSize) << 6;
        UFG::qMemSet((char *)mNext->mCullInfos + v9, 0, 0x40u);
        mResults = mNext->mResults;
        if ( mResults )
          UFG::qMemSet(&mResults->mViewResult[v9], 0, 0x40u);
        *(_QWORD *)cull_info->mAABBMin = mNext->mFixedAllocator.mFreeListHead;
        --mNext->mFixedAllocator.mNumSlotsAllocated;
        mNext->mFixedAllocator.mFreeListHead = (char *)cull_info;
        if ( mNext->mFixedAllocator.mNumSlotsAllocated )
        {
          v11 = mNext->mNext;
          mPrev = mNext->mPrev;
          mPrev->mNext = v11;
          v11->mPrev = mPrev;
          mNext->mPrev = mNext;
          mNext->mNext = mNext;
          v13 = (PersistentCullBucket **)p_mPersistentCullBuckets->mNext;
          p_mPersistentCullBuckets->mNext = mNext;
          mNext->mNext = (UFG::qNode<CullBucket,CullBucket> *)v13;
          mNext->mPrev = p_mPersistentCullBuckets;
          *v13 = mNext;
        }
        else
        {
          PersistentCullBucket::~PersistentCullBucket(mNext);
          operator delete[](mNext);
          --this->mNumCullBuckets;
        }
      }
    }
  }
}

// File Line: 1124
// RVA: 0x26E70
void __fastcall CullManager::FreePersistentOcclusionInfo(CullManager *this, CullInfoFull *occlusion_info)
{
  CullLayer *mCullLayer; // rdi
  PersistentCullBucket *mNext; // rbx
  PersistentCullBucket *p_mPersistentCullBuckets; // rdi
  UFG::qNode<CullBucket,CullBucket> *v7; // rax
  UFG::qNode<CullBucket,CullBucket> *mPrev; // rcx
  PersistentCullBucket **v9; // rax

  if ( occlusion_info )
  {
    mCullLayer = occlusion_info->mCullLayer;
    mNext = (PersistentCullBucket *)mCullLayer->mPersistentCullBuckets.mNode.mNext;
    p_mPersistentCullBuckets = (PersistentCullBucket *)&mCullLayer->mPersistentCullBuckets;
    if ( mNext != p_mPersistentCullBuckets )
    {
      while ( (char *)occlusion_info >= &mNext->mFixedAllocator.mBuffer[(unsigned __int64)mNext->mFixedAllocator.mBufferSize]
           || (char *)occlusion_info < mNext->mFixedAllocator.mBuffer )
      {
        mNext = (PersistentCullBucket *)mNext->mNext;
        if ( mNext == p_mPersistentCullBuckets )
          return;
      }
      if ( mNext )
      {
        UFG::qMemSet(occlusion_info, 0, 0x80u);
        *(_QWORD *)occlusion_info->mAABBMin = mNext->mFixedAllocator.mFreeListHead;
        --mNext->mFixedAllocator.mNumSlotsAllocated;
        mNext->mFixedAllocator.mFreeListHead = (char *)occlusion_info;
        if ( mNext->mFixedAllocator.mNumSlotsAllocated )
        {
          v7 = mNext->mNext;
          mPrev = mNext->mPrev;
          mPrev->mNext = v7;
          v7->mPrev = mPrev;
          mNext->mPrev = mNext;
          mNext->mNext = mNext;
          v9 = (PersistentCullBucket **)p_mPersistentCullBuckets->mNext;
          p_mPersistentCullBuckets->mNext = mNext;
          mNext->mNext = (UFG::qNode<CullBucket,CullBucket> *)v9;
          mNext->mPrev = p_mPersistentCullBuckets;
          *v9 = mNext;
        }
        else
        {
          PersistentCullBucket::~PersistentCullBucket(mNext);
          operator delete[](mNext);
          --this->mNumOcclusionBuckets;
        }
      }
    }
  }
}

// File Line: 1164
// RVA: 0x25B40
CullInfo *__fastcall CullManager::AllocFrameCullInfos(CullManager *this, int num_infos)
{
  unsigned int v2; // edi
  CullInfo *result; // rax
  CullInfo *v4; // rbx

  v2 = num_infos << 6;
  result = (CullInfo *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, num_infos << 6, 0x20u);
  v4 = result;
  if ( result )
  {
    UFG::qMemSet(result, 0, v2);
    return v4;
  }
  return result;
}

// File Line: 1194
// RVA: 0x25E70
void __fastcall CullManager::AllocPrebuiltFrameCullInfos(
        CullManager *this,
        CullResults **cull_results,
        int num_infos,
        CullInfo *prebuilt_cull_infos,
        CullLayer *cull_layer)
{
  __int64 v6; // rbx
  CullLayer *v8; // rbp
  unsigned int v9; // edi
  CullResults *v10; // rax
  __int64 v11; // rdi
  char *v12; // rdx
  __int64 *p_mFrameCullBuckets; // r8
  unsigned int v14; // ecx
  __int64 v15; // rax
  __int64 v16; // rax

  if ( num_infos )
  {
    v6 = num_infos;
    v8 = &gDefaultCullLayer;
    if ( cull_layer )
      v8 = cull_layer;
    if ( cull_results )
    {
      v9 = ((num_infos << 6) + 31) & 0xFFFFFFE0;
      v10 = (CullResults *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, v9, 0x20u);
      *cull_results = v10;
      if ( !v10 )
        return;
      UFG::qMemSet(v10, 0, v9);
    }
    if ( cull_results )
      v11 = (__int64)*cull_results;
    else
      v11 = 0i64;
    v12 = UFG::qLinearAllocator::Malloc(
            Illusion::gEngine.FrameMemory,
            (unsigned int)((__int64)((v6 + 255) & 0xFFFFFFFFFFFFFF00ui64) / 256) << 6,
            0x10u);
    if ( v12 && (_DWORD)v6 )
    {
      p_mFrameCullBuckets = (__int64 *)&v8->mFrameCullBuckets;
      do
      {
        v14 = 256;
        if ( (unsigned int)v6 < 0x100 )
          v14 = v6;
        if ( v12 )
        {
          *(_QWORD *)v12 = v12;
          *((_QWORD *)v12 + 1) = v12;
          *((_QWORD *)v12 + 2) = 0i64;
          *((_QWORD *)v12 + 3) = 0i64;
          *((_QWORD *)v12 + 4) = 0i64;
          *((_QWORD *)v12 + 5) = 0i64;
          *((_DWORD *)v12 + 12) = 0;
        }
        *((_DWORD *)v12 + 10) = 0;
        *((_DWORD *)v12 + 11) = v14;
        *((_QWORD *)v12 + 4) = v11;
        *((_QWORD *)v12 + 2) = prebuilt_cull_infos;
        *((_DWORD *)v12 + 12) = v14;
        v15 = *p_mFrameCullBuckets;
        *(_QWORD *)(v15 + 8) = v12;
        *(_QWORD *)v12 = v15;
        *((_QWORD *)v12 + 1) = p_mFrameCullBuckets;
        *p_mFrameCullBuckets = (__int64)v12;
        prebuilt_cull_infos += v14;
        v16 = 0i64;
        if ( cull_results )
          v16 = v14;
        v11 += v16 << 6;
        v12 += 64;
        LODWORD(v6) = v6 - v14;
      }
      while ( (_DWORD)v6 );
    }
  }
}

// File Line: 1260
// RVA: 0x25FF0
void __fastcall CullManager::AllocPrebuiltFrameOcclusionInfos(
        CullManager *this,
        int num_infos,
        CullInfoFull *prebuilt_occlusion_infos,
        CullLayer *cull_layer)
{
  int v5; // ebx
  CullLayer *v6; // rsi
  char *v7; // rdx
  __int64 *p_mFrameCullBuckets; // r8
  float v9; // xmm0_4
  unsigned int v10; // ecx
  __int64 v11; // rax

  if ( num_infos )
  {
    v5 = num_infos;
    v6 = &gDefaultOcclusionLayer;
    if ( cull_layer )
      v6 = cull_layer;
    v7 = UFG::qLinearAllocator::Malloc(
           Illusion::gEngine.FrameMemory,
           (unsigned int)((__int64)((num_infos + 255i64) & 0xFFFFFFFFFFFFFF00ui64) / 256) << 6,
           0x10u);
    if ( v7 )
    {
      p_mFrameCullBuckets = (__int64 *)&v6->mFrameCullBuckets;
      do
      {
        v9 = (float)v5;
        if ( (float)v5 >= 256.0 )
          v9 = FLOAT_256_0;
        v10 = (int)v9;
        if ( v7 )
        {
          *(_QWORD *)v7 = v7;
          *((_QWORD *)v7 + 1) = v7;
          *((_QWORD *)v7 + 2) = 0i64;
          *((_QWORD *)v7 + 3) = 0i64;
          *((_QWORD *)v7 + 4) = 0i64;
          *((_QWORD *)v7 + 5) = 0i64;
          *((_DWORD *)v7 + 12) = 0;
        }
        *((_DWORD *)v7 + 10) = 0;
        *((_DWORD *)v7 + 11) = v10;
        *((_QWORD *)v7 + 4) = 0i64;
        *((_QWORD *)v7 + 3) = prebuilt_occlusion_infos;
        *((_DWORD *)v7 + 12) = v10;
        v11 = *p_mFrameCullBuckets;
        *(_QWORD *)(v11 + 8) = v7;
        *(_QWORD *)v7 = v11;
        *((_QWORD *)v7 + 1) = p_mFrameCullBuckets;
        *p_mFrameCullBuckets = (__int64)v7;
        prebuilt_occlusion_infos += v10;
        v7 += 64;
        v5 -= v10;
      }
      while ( v5 );
    }
  }
}

// File Line: 1306
// RVA: 0x26110
void __fastcall CullManager::BeginFrame(CullManager *this)
{
  UFG::qNode<CullLayer,CullLayer> *mNext; // rbx
  __int64 i; // rbp
  UFG::qNode<CullLayer,CullLayer> *v4; // rax
  UFG::qNode<CullLayer,CullLayer> *mPrev; // rcx
  UFG::qNode<CullLayer,CullLayer> *v6; // rdi
  Render::OcclusionMap *mOcclusionMaps; // rdi
  Render::RasterizeZ *mRasterizers; // rbx
  Render::RasterizeZ v9; // [rsp+20h] [rbp-58h] BYREF

  this->mDoCullingTiming = 0.0;
  this->mPrevOcclusionTask = 0i64;
  this->mPrevCullingTask = 0i64;
  UFG::qMemSet(this->mFinalTasks, 0, 0x80u);
  mNext = this->mCullLayers[0].mNode.mNext;
  for ( i = 16i64; mNext != (UFG::qNode<CullLayer,CullLayer> *)this->mCullLayers; mNext = mNext->mNext )
  {
    memset(&mNext[5], 0, 0x80ui64);
    v4 = mNext[4].mNext;
    if ( v4 != &mNext[4] )
    {
      do
      {
        mPrev = v4[2].mPrev;
        v6 = v4->mNext;
        if ( mPrev )
          UFG::qMemSet(mPrev, 0, HIDWORD(v4[2].mNext) << 6);
        v4 = v6;
      }
      while ( v6 != &mNext[4] );
    }
  }
  mOcclusionMaps = this->mOcclusionMaps;
  mRasterizers = this->mRasterizers;
  do
  {
    Render::RasterizeZ::Init(mRasterizers, 0i64, 1);
    Render::OcclusionMap::Init(mOcclusionMaps, 0i64);
    ++mRasterizers;
    ++mOcclusionMaps;
    --i;
  }
  while ( i );
  Render::RasterizeZ::Init(&v9, (unsigned int *)this->mZbuffer1, 0);
  *v9.mZBufferTag = -1;
  Render::RasterizeZ::Init(&v9, (unsigned int *)this->mZbuffer2, 0);
  *v9.mZBufferTag = -1;
  Render::RasterizeZ::Init(&v9, (unsigned int *)this->mZbuffer3, 0);
  *v9.mZBufferTag = -1;
  Render::RasterizeZ::Init(&v9, (unsigned int *)this->mZbuffer4, 0);
  *v9.mZBufferTag = -1;
}

// File Line: 1361
// RVA: 0x26C80
void __fastcall CullManager::EndFrame(CullManager *this)
{
  UFG::qTaskGroup *mPrevCullingTask; // rdx
  Illusion::eCastShadow *v3; // rcx
  UFG::qNode<CullLayer,CullLayer> *i; // rdx
  UFG::qNode<CullLayer,CullLayer> *j; // rcx

  mPrevCullingTask = this->mPrevCullingTask;
  if ( mPrevCullingTask )
    UFG::qTaskManager::Sync(&UFG::gTaskManager, mPrevCullingTask);
  CullManager::DeregisterAllViews(this);
  Illusion::eCastShadow::ClearCastShadowViewFilter(v3);
  for ( i = this->mCullLayers[0].mNode.mNext; i != (UFG::qNode<CullLayer,CullLayer> *)this->mCullLayers; i = i->mNext )
  {
    i[3].mPrev = i + 3;
    i[3].mNext = i + 3;
  }
  for ( j = this->mCullLayers[1].mNode.mNext; j != (UFG::qNode<CullLayer,CullLayer> *)&this->mCullLayers[1]; j = j->mNext )
  {
    j[3].mPrev = j + 3;
    j[3].mNext = j + 3;
  }
}

// File Line: 1400
// RVA: 0x262B0
char __fastcall CullManager::BeginView(CullManager *this, int view_index, UFG::qTaskGroup *dependent)
{
  __int64 v3; // r13
  CullManager::CullSettings *v6; // r12
  int MaxWorkers; // eax
  __int64 v8; // rbp
  int v9; // eax
  UFG::qTask *v10; // rbx
  __int64 v11; // r14
  unsigned int *v12; // rbx
  char *v13; // rdi
  char *v14; // r15
  char *v15; // rax
  void *mZbuffer1; // rcx
  void *mZbuffer2; // rdx
  void *mZbuffer3; // r8
  void *mZbuffer4; // r9
  UFG::qVector4 v20; // xmm2
  UFG::qVector4 v21; // xmm1
  UFG::qVector4 v22; // xmm0
  char *v23; // rax
  UFG::qTaskGroup *v24; // rdi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *mSingleFrameTaskGroups; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *mPrev; // rax
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *p_mTasks; // rbx
  UFG::qNode<CullLayer,CullLayer> *mNext; // r14
  char *v29; // rax
  char *v30; // rdx
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r9
  char *mAddress; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v36; // rax
  Render::OcclusionMap *v37; // r14
  void *mOBuffer0; // rbp
  char *v39; // rax
  _QWORD *v40; // rax
  UFG::qSpuElf *v41; // rax
  void (__fastcall *v42)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rdx
  void (__fastcall *v43)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r9
  unsigned int (__fastcall *v44)(void *, void *, void *, void *); // r8
  char *v45; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *mSingleFrameTasks; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v47; // rax
  char *v48; // rax
  char *v49; // r15
  UFG::qVector4 v50; // xmm2
  UFG::qVector4 v51; // xmm1
  UFG::qVector4 v52; // xmm0
  UFG::qLinearAllocator *FrameMemory; // rcx
  char *v54; // rax
  char *v55; // rax
  UFG::qTaskGroup *v56; // rdi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v57; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v58; // rax
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v59; // rbx
  __int64 v60; // rbp
  UFG::qNode<CullLayer,CullLayer> *v61; // r14
  char *v62; // rax
  char *v63; // rdx
  UFG::qSpuElf *v64; // rax
  void (__fastcall *v65)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v66)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v67)(void *, void *, void *, void *); // r9
  char *v68; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v69; // rax
  Render::OcclusionMap *v70; // [rsp+20h] [rbp-68h]
  int v73; // [rsp+A8h] [rbp+20h]

  v3 = view_index;
  if ( view_index == -1 || this->mViewSlots[view_index] != VIEW_SLOT_ALLOCATED )
    return 0;
  v6 = &this->mViewSettings[view_index];
  MaxWorkers = UFG::qTaskManager::GetMaxWorkers(&UFG::gTaskManager);
  v8 = (unsigned int)MaxWorkers;
  if ( MaxWorkers < 1 )
    v8 = 1i64;
  v9 = UFG::qTaskManager::GetMaxWorkers(&UFG::gTaskManager);
  if ( v9 < 1 )
    v9 = 1;
  v73 = v9;
  v10 = 0i64;
  v11 = v3;
  v70 = &this->mOcclusionMaps[v3];
  if ( (v6->mViewFlags & 1) != 0 && this->mEnableOcclusionCulling )
  {
    v12 = (unsigned int *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10080u, 0x20u);
    v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x9000u, 0x20u);
    if ( v12 == 0i64 || v13 == 0i64 )
      return 0;
    Render::RasterizeZ::Init(&this->mRasterizers[v11], v12, 0);
    *this->mRasterizers[v11].mZBufferTag = -1;
    UFG::CoverObjectBase::SetCoverObjectGroup((hkDynamicClassNameRegistry *)&this->mRasterizers[v11], (const char *)v6);
    Render::OcclusionMap::Init(&this->mOcclusionMaps[v3], v13);
    Render::OcclusionMap::BeginFrame(&this->mOcclusionMaps[v3], &v6->mWorldViewProjection);
    v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x80u);
    v15 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x20u);
    mZbuffer1 = this->mZbuffer1;
    mZbuffer2 = this->mZbuffer2;
    mZbuffer3 = this->mZbuffer3;
    mZbuffer4 = this->mZbuffer4;
    if ( !v14 || !v15 )
      return 0;
    v20 = v6->mWorldViewProjection.v1;
    v21 = v6->mWorldViewProjection.v2;
    v22 = v6->mWorldViewProjection.v3;
    *(UFG::qVector4 *)v14 = v6->mWorldViewProjection.v0;
    *((UFG::qVector4 *)v14 + 1) = v20;
    *((UFG::qVector4 *)v14 + 2) = v21;
    *((UFG::qVector4 *)v14 + 3) = v22;
    *((_QWORD *)v14 + 8) = v12;
    *((_QWORD *)v14 + 9) = mZbuffer1;
    *((_QWORD *)v14 + 10) = mZbuffer2;
    *((_QWORD *)v14 + 11) = mZbuffer3;
    *((_QWORD *)v14 + 12) = mZbuffer4;
    *((_DWORD *)v14 + 26) = v3;
    *((_QWORD *)v14 + 14) = v15;
    *(_DWORD *)v15 = -1;
    v23 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
    v24 = (UFG::qTaskGroup *)v23;
    if ( v23 )
      UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v23, "RasterizeBucket");
    mSingleFrameTaskGroups = UFG::gTaskManager.mSingleFrameTaskGroups;
    mPrev = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
    mPrev->mNext = v24;
    v24->mPrev = mPrev;
    v24->mNext = &mSingleFrameTaskGroups->mNode;
    mSingleFrameTaskGroups->mNode.mPrev = v24;
    if ( (int)v8 > 0 )
    {
      p_mTasks = &v24->mTasks;
      do
      {
        mNext = this->mCullLayers[1].mNode.mNext;
        v29 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
        v30 = v29;
        if ( v29 )
        {
          *(_QWORD *)v29 = v29;
          *((_QWORD *)v29 + 1) = v29;
          *((_QWORD *)v29 + 2) = v29 + 16;
          *((_QWORD *)v29 + 3) = v29 + 16;
          mSpuElf = Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer.mSpuElf;
          mTaskFunctionSPU = Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer.mTaskFunctionSPU;
          mTaskFunctionPPU = Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer.mTaskFunctionPPU;
          mTaskFunctionOffload = Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer.mTaskFunctionOffload;
          if ( !Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer.mCurrentSPUEnabled )
          {
            mSpuElf = 0i64;
            mTaskFunctionSPU = 0i64;
            mTaskFunctionOffload = 0i64;
          }
          *((_QWORD *)v30 + 6) = v24;
          *((_DWORD *)v30 + 14) = 2;
          *((_QWORD *)v30 + 4) = 0i64;
          *((_QWORD *)v30 + 5) = 0i64;
          *((_QWORD *)v30 + 8) = &Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer;
          if ( mSpuElf )
            mAddress = mSpuElf->mAddress;
          else
            mAddress = 0i64;
          *((_QWORD *)v30 + 9) = mAddress;
          *((_QWORD *)v30 + 10) = mTaskFunctionSPU;
          *((_QWORD *)v30 + 11) = mTaskFunctionPPU;
          *((_QWORD *)v30 + 12) = v14;
          *((_QWORD *)v30 + 13) = mNext;
          *((_QWORD *)v30 + 14) = &this->mCullLayers[1];
          *((_QWORD *)v30 + 15) = 0i64;
          if ( mTaskFunctionOffload )
          {
            *((_DWORD *)v30 + 14) = 130;
            *((_DWORD *)v30 + 12) = 0;
          }
        }
        v36 = p_mTasks->mNode.mPrev;
        v36->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v30;
        *(_QWORD *)v30 = v36;
        *((_QWORD *)v30 + 1) = p_mTasks;
        p_mTasks->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)v30;
        ++v24->mNumTasks;
        *((_DWORD *)v30 + 14) &= 0xFFFFFFF0;
        --v8;
      }
      while ( v8 );
      LODWORD(v3) = view_index;
    }
    UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v24, dependent);
    UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v24, this->mPrevCullingTask);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v24);
    v37 = v70;
    mOBuffer0 = v70->mOBuffer0;
    v39 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
    v10 = (UFG::qTask *)v39;
    if ( v39 )
    {
      *(_QWORD *)v39 = v39;
      *((_QWORD *)v39 + 1) = v39;
      v40 = v39 + 16;
      *v40 = v40;
      v40[1] = v40;
      v41 = Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap.mSpuElf;
      v42 = Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap.mTaskFunctionSPU;
      v43 = Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap.mTaskFunctionPPU;
      v44 = Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap.mTaskFunctionOffload;
      if ( !Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap.mCurrentSPUEnabled )
      {
        v41 = 0i64;
        v42 = 0i64;
        v44 = 0i64;
      }
      v10->mTaskGroup = 0i64;
      v10->mFlags = 2;
      v10->mSyncVars.i64 = 0i64;
      v10->mSyncVars.v.mDependents = 0i64;
      v10->mFunctionDeclData = &Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap;
      if ( v41 )
        v45 = v41->mAddress;
      else
        v45 = 0i64;
      v10->mSPUElfAddress = v45;
      v10->mSPUFunction = v42;
      v10->mPPUFunction = v43;
      v10->mParam0 = v14;
      v10->mParam1 = mOBuffer0;
      v10->mParam2 = 0i64;
      v10->mParam3 = 0i64;
      if ( v44 )
      {
        v10->mFlags = 130;
        v10->mOffloadThread = 0;
      }
    }
    mSingleFrameTasks = UFG::gTaskManager.mSingleFrameTasks;
    v47 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
    v47->mNext = v10;
    v10->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = v47;
    v10->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = &mSingleFrameTasks->mNode;
    mSingleFrameTasks->mNode.mPrev = v10;
    v10->mFlags &= 0xFFFFFFF0;
    UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v10, v24);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v10);
  }
  else
  {
    v37 = &this->mOcclusionMaps[v3];
  }
  v48 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x98u, 0x10u);
  v49 = v48;
  if ( !v48 )
    return 0;
  *((_DWORD *)v48 + 19) = -1;
  *((_WORD *)v48 + 37) = v3;
  *((_DWORD *)v48 + 20) = LODWORD(v6->mPixelDensityThreshold);
  *((_DWORD *)v48 + 21) = LODWORD(v6->mPixelDistanceBias);
  v50 = v6->mWorldViewProjection.v1;
  v51 = v6->mWorldViewProjection.v2;
  v52 = v6->mWorldViewProjection.v3;
  *(UFG::qVector4 *)v48 = v6->mWorldViewProjection.v0;
  *((UFG::qVector4 *)v48 + 1) = v50;
  *((UFG::qVector4 *)v48 + 2) = v51;
  *((UFG::qVector4 *)v48 + 3) = v52;
  *((_DWORD *)v48 + 22) = LODWORD(v6->mNearPlane);
  *((_DWORD *)v48 + 23) = LODWORD(v6->mFarPlane);
  *((_QWORD *)v48 + 8) = v37->mOBuffer0;
  *((_WORD *)v48 + 36) = 128;
  FrameMemory = Illusion::gEngine.FrameMemory;
  *((_QWORD *)v48 + 12) = Illusion::gEngine.FrameMemory;
  v54 = UFG::qLinearAllocator::Malloc(FrameMemory, 0x20u, 0x20u);
  *((_QWORD *)v49 + 13) = v54;
  *(_DWORD *)v54 = -1;
  *((_DWORD *)v49 + 34) = LODWORD(v6->mViewWorldPos.x);
  *((_DWORD *)v49 + 35) = LODWORD(v6->mViewWorldPos.y);
  *((_DWORD *)v49 + 36) = LODWORD(v6->mViewWorldPos.z);
  v55 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
  v56 = (UFG::qTaskGroup *)v55;
  if ( v55 )
    UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v55, "CullView");
  v57 = UFG::gTaskManager.mSingleFrameTaskGroups;
  v58 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
  v58->mNext = v56;
  v56->mPrev = v58;
  v56->mNext = &v57->mNode;
  v57->mNode.mPrev = v56;
  UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v56, v10);
  UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v56, this->mPrevCullingTask);
  if ( v73 > 0 )
  {
    v59 = &v56->mTasks;
    v60 = (unsigned int)v73;
    do
    {
      v61 = this->mCullLayers[0].mNode.mNext;
      v62 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
      v63 = v62;
      if ( v62 )
      {
        *(_QWORD *)v62 = v62;
        *((_QWORD *)v62 + 1) = v62;
        *((_QWORD *)v62 + 2) = v62 + 16;
        *((_QWORD *)v62 + 3) = v62 + 16;
        v64 = Render::gTaskFunctionDeclData_CullManager_CullBucketTask.mSpuElf;
        v65 = Render::gTaskFunctionDeclData_CullManager_CullBucketTask.mTaskFunctionSPU;
        v66 = Render::gTaskFunctionDeclData_CullManager_CullBucketTask.mTaskFunctionPPU;
        v67 = Render::gTaskFunctionDeclData_CullManager_CullBucketTask.mTaskFunctionOffload;
        if ( !Render::gTaskFunctionDeclData_CullManager_CullBucketTask.mCurrentSPUEnabled )
        {
          v64 = 0i64;
          v65 = 0i64;
          v67 = 0i64;
        }
        *((_QWORD *)v63 + 6) = v56;
        *((_DWORD *)v63 + 14) = 2;
        *((_QWORD *)v63 + 4) = 0i64;
        *((_QWORD *)v63 + 5) = 0i64;
        *((_QWORD *)v63 + 8) = &Render::gTaskFunctionDeclData_CullManager_CullBucketTask;
        if ( v64 )
          v68 = v64->mAddress;
        else
          v68 = 0i64;
        *((_QWORD *)v63 + 9) = v68;
        *((_QWORD *)v63 + 10) = v65;
        *((_QWORD *)v63 + 11) = v66;
        *((_QWORD *)v63 + 12) = v49;
        *((_QWORD *)v63 + 13) = v61;
        *((_QWORD *)v63 + 14) = this->mCullLayers;
        *((_QWORD *)v63 + 15) = 0i64;
        if ( v67 )
        {
          *((_DWORD *)v63 + 14) = 130;
          *((_DWORD *)v63 + 12) = 0;
        }
      }
      v69 = v59->mNode.mPrev;
      v69->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v63;
      *(_QWORD *)v63 = v69;
      *((_QWORD *)v63 + 1) = v59;
      v59->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)v63;
      ++v56->mNumTasks;
      *((_DWORD *)v63 + 14) &= 0xFFFFFFF0;
      --v60;
    }
    while ( v60 );
    LODWORD(v3) = view_index;
  }
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v56);
  this->mFinalTasks[(int)v3] = v56;
  this->mPrevCullingTask = v56;
  return 1;
}

// File Line: 1603
// RVA: 0x26D10
void __fastcall CullManager::EndView(CullManager *this, __int64 view_index)
{
  if ( (_DWORD)view_index != -1 && this->mViewSlots[(int)view_index] == VIEW_SLOT_ALLOCATED )
    UFG::qTaskManager::Sync(&UFG::gTaskManager, this->mFinalTasks[(int)view_index]);
}

