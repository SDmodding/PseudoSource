// File Line: 65
// RVA: 0x1453F20
__int64 dynamic_initializer_for__gDefaultCullLayer__()
{
  CullManager *v0; // rax
  UFG::qNode<CullLayer,CullLayer> *v1; // rdx
  UFG::qNode<CullLayer,CullLayer> *v2; // rcx

  gDefaultCullLayer.mFrameCullBuckets.mNode.mPrev = &gDefaultCullLayer.mFrameCullBuckets.mNode;
  gDefaultCullLayer.mFrameCullBuckets.mNode.mNext = &gDefaultCullLayer.mFrameCullBuckets.mNode;
  gDefaultCullLayer.mPersistentCullBuckets.mNode.mPrev = &gDefaultCullLayer.mPersistentCullBuckets.mNode;
  gDefaultCullLayer.mPersistentCullBuckets.mNode.mNext = &gDefaultCullLayer.mPersistentCullBuckets.mNode;
  `eh vector constructor iterator'(
    gDefaultCullLayer.mCullResultBuckets,
    8ui64,
    16,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  gDefaultCullLayer.mType = 0;
  gDefaultCullLayer.mName = "Default Cull Layer";
  gDefaultCullLayer.mDrawEnabled = 1;
  *(_QWORD *)&gDefaultCullLayer.pad0 = 0i64;
  gDefaultCullLayer.pad2 = 0;
  v0 = CullManager::Instance();
  v1 = (UFG::qNode<CullLayer,CullLayer> *)((char *)v0 + 16 * ((signed int)gDefaultCullLayer.mType + 104i64));
  v2 = v1->mPrev;
  v2->mNext = (UFG::qNode<CullLayer,CullLayer> *)&gDefaultCullLayer;
  gDefaultCullLayer.mPrev = v2;
  gDefaultCullLayer.mNext = v1;
  v1->mPrev = (UFG::qNode<CullLayer,CullLayer> *)&gDefaultCullLayer;
  ++v0->mNumCullLayers;
  return atexit(dynamic_atexit_destructor_for__gDefaultCullLayer__);
}

// File Line: 66
// RVA: 0x1454000
__int64 dynamic_initializer_for__gDefaultOcclusionLayer__()
{
  CullManager *v0; // rax
  UFG::qNode<CullLayer,CullLayer> *v1; // rdx
  UFG::qNode<CullLayer,CullLayer> *v2; // rcx

  gDefaultOcclusionLayer.mFrameCullBuckets.mNode.mPrev = &gDefaultOcclusionLayer.mFrameCullBuckets.mNode;
  gDefaultOcclusionLayer.mFrameCullBuckets.mNode.mNext = &gDefaultOcclusionLayer.mFrameCullBuckets.mNode;
  gDefaultOcclusionLayer.mPersistentCullBuckets.mNode.mPrev = &gDefaultOcclusionLayer.mPersistentCullBuckets.mNode;
  gDefaultOcclusionLayer.mPersistentCullBuckets.mNode.mNext = &gDefaultOcclusionLayer.mPersistentCullBuckets.mNode;
  `eh vector constructor iterator'(
    gDefaultOcclusionLayer.mCullResultBuckets,
    8ui64,
    16,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  gDefaultOcclusionLayer.mType = 1;
  gDefaultOcclusionLayer.mName = "Default Occlusion Layer";
  gDefaultOcclusionLayer.mDrawEnabled = 1;
  *(_QWORD *)&gDefaultOcclusionLayer.pad0 = 0i64;
  gDefaultOcclusionLayer.pad2 = 0;
  v0 = CullManager::Instance();
  v1 = (UFG::qNode<CullLayer,CullLayer> *)((char *)v0 + 16 * ((signed int)gDefaultOcclusionLayer.mType + 104i64));
  v2 = v1->mPrev;
  v2->mNext = (UFG::qNode<CullLayer,CullLayer> *)&gDefaultOcclusionLayer;
  gDefaultOcclusionLayer.mPrev = v2;
  gDefaultOcclusionLayer.mNext = v1;
  v1->mPrev = (UFG::qNode<CullLayer,CullLayer> *)&gDefaultOcclusionLayer;
  ++v0->mNumCullLayers;
  return atexit(dynamic_atexit_destructor_for__gDefaultOcclusionLayer__);
}

// File Line: 80
// RVA: 0x27450
void __fastcall TransformAABB(UFG::qMatrix44 *m, UFG::qVector3 *min, UFG::qVector3 *max)
{
  float v3; // eax
  float v4; // xmm2_4
  float *v5; // rcx
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // eax
  float v13; // xmm1_4
  __int64 v14; // rax
  signed __int64 v15; // r9
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  float v31; // [rsp+0h] [rbp-28h]
  float v32; // [rsp+4h] [rbp-24h]
  float v33; // [rsp+8h] [rbp-20h]
  float v34; // [rsp+10h] [rbp-18h]
  float v35; // [rsp+14h] [rbp-14h]
  float v36; // [rsp+18h] [rbp-10h]

  v3 = m->v3.x;
  v4 = m->v3.z;
  v5 = &m->v0.z;
  v6 = min->y;
  v31 = min->x;
  v33 = min->z;
  v7 = max->y;
  v32 = v6;
  v8 = max->x;
  v35 = v7;
  v9 = v5[11];
  v34 = v8;
  v10 = max->z;
  min->y = v9;
  min->x = v3;
  min->z = v4;
  v11 = v5[11];
  v36 = v10;
  v12 = v5[10];
  v13 = v5[12];
  max->y = v11;
  max->x = v12;
  v14 = 0i64;
  v15 = 3i64;
  max->z = v13;
  do
  {
    v16 = *(v5 - 2);
    v17 = *(float *)((char *)&v31 + v14);
    v18 = *(float *)((char *)&v34 + v14);
    v19 = v16;
    v20 = v16 * v18;
    v21 = v19 * v17;
    if ( v21 >= v20 )
      v22 = v20;
    else
      v22 = v21;
    min->x = v22 + min->x;
    if ( v21 >= v20 )
      v20 = v21;
    max->x = v20 + max->x;
    v23 = *(v5 - 1);
    v24 = v23;
    v25 = v23 * v18;
    v26 = v24 * v17;
    if ( v26 >= v25 )
      v27 = v25;
    else
      v27 = v26;
    min->y = v27 + min->y;
    if ( v26 >= v25 )
      v25 = v26;
    max->y = v25 + max->y;
    v28 = *v5 * v18;
    v29 = *v5 * v17;
    if ( v29 >= v28 )
      v30 = *v5 * v18;
    else
      v30 = *v5 * v17;
    min->z = v30 + min->z;
    if ( v29 >= v28 )
      v28 = v29;
    v5 += 4;
    v14 += 4i64;
    max->z = v28 + max->z;
    --v15;
  }
  while ( v15 );
}

// File Line: 149
// RVA: 0x27010
signed __int64 __fastcall InFrustum(UFG::qVector4 *planes, UFG::qVector3 *point)
{
  signed __int64 v2; // rax
  float *v3; // rcx

  v2 = 0i64;
  v3 = &planes->z;
  while ( (float)((float)((float)((float)(point->y * *(v3 - 1)) + (float)(point->x * *(v3 - 2)))
                        + (float)(point->z * *v3))
                + v3[1]) <= 0.0 )
  {
    ++v2;
    v3 += 4;
    if ( v2 >= 6 )
      return 1i64;
  }
  return 0i64;
}

// File Line: 162
// RVA: 0x26B40
float __fastcall DistanceToFrustum(UFG::qVector4 *planes, UFG::qVector3 *point)
{
  float v2; // xmm3_4
  float v3; // xmm5_4
  float v4; // xmm2_4
  float v5; // xmm6_4
  float v6; // xmm3_4
  float result; // xmm0_4

  v2 = point->y;
  v3 = point->x;
  v4 = 0.0;
  v5 = point->z;
  if ( (float)((float)((float)((float)(point->y * planes->y) + (float)(point->x * planes->x))
                     + (float)(point->z * planes->z))
             + planes->w) > 0.0 )
    v4 = (float)((float)((float)(point->y * planes->y) + (float)(point->x * planes->x)) + (float)(point->z * planes->z))
       + planes->w;
  if ( (float)((float)((float)((float)(v2 * planes[1].y) + (float)(v3 * planes[1].x)) + (float)(v5 * planes[1].z))
             + planes[1].w) > v4 )
    v4 = (float)((float)((float)(v2 * planes[1].y) + (float)(v3 * planes[1].x)) + (float)(v5 * planes[1].z))
       + planes[1].w;
  if ( (float)((float)((float)((float)(v2 * planes[2].y) + (float)(v3 * planes[2].x)) + (float)(v5 * planes[2].z))
             + planes[2].w) > v4 )
    v4 = (float)((float)((float)(v2 * planes[2].y) + (float)(v3 * planes[2].x)) + (float)(v5 * planes[2].z))
       + planes[2].w;
  if ( (float)((float)((float)((float)(v2 * planes[3].y) + (float)(v3 * planes[3].x)) + (float)(v5 * planes[3].z))
             + planes[3].w) > v4 )
    v4 = (float)((float)((float)(v2 * planes[3].y) + (float)(v3 * planes[3].x)) + (float)(v5 * planes[3].z))
       + planes[3].w;
  if ( (float)((float)((float)((float)(v2 * planes[4].y) + (float)(v3 * planes[4].x)) + (float)(v5 * planes[4].z))
             + planes[4].w) > v4 )
    v4 = (float)((float)((float)(v2 * planes[4].y) + (float)(v3 * planes[4].x)) + (float)(v5 * planes[4].z))
       + planes[4].w;
  v6 = (float)((float)((float)(v2 * planes[5].y) + (float)(v3 * planes[5].x)) + (float)(v5 * planes[5].z)) + planes[5].w;
  if ( v6 <= v4 )
    result = v4;
  else
    result = v6;
  return result;
}

// File Line: 188
// RVA: 0x25610
void __fastcall CullLayer::CullLayer(CullLayer *this, CullLayer::CullLayerType type, const char *name)
{
  const char *v3; // rdi
  CullLayer::CullLayerType v4; // ebx
  CullLayer *v5; // rsi
  UFG::qList<CullBucket,CullBucket,1,0> *v6; // rax
  UFG::qList<CullBucket,CullBucket,1,0> *v7; // rax
  CullManager *v8; // rax
  UFG::qNode<CullLayer,CullLayer> *v9; // rdx
  UFG::qNode<CullLayer,CullLayer> *v10; // rcx

  v3 = name;
  v4 = type;
  v5 = this;
  this->mPrev = (UFG::qNode<CullLayer,CullLayer> *)&this->mPrev;
  this->mNext = (UFG::qNode<CullLayer,CullLayer> *)&this->mPrev;
  v6 = &this->mFrameCullBuckets;
  v6->mNode.mPrev = &v6->mNode;
  v6->mNode.mNext = &v6->mNode;
  v7 = &this->mPersistentCullBuckets;
  v7->mNode.mPrev = &v7->mNode;
  v7->mNode.mNext = &v7->mNode;
  `eh vector constructor iterator'(
    this->mCullResultBuckets,
    8ui64,
    16,
    (void (__fastcall *)(void *))Scaleform::Ptr<Scaleform::Render::Texture>::Ptr<Scaleform::Render::Texture>);
  v5->mType = v4;
  v5->mName = v3;
  v5->mDrawEnabled = 1;
  *(_QWORD *)&v5->pad0 = 0i64;
  v5->pad2 = 0;
  v8 = CullManager::Instance();
  v9 = (UFG::qNode<CullLayer,CullLayer> *)((char *)v8 + 16 * ((signed int)v5->mType + 104i64));
  v10 = v9->mPrev;
  v10->mNext = (UFG::qNode<CullLayer,CullLayer> *)&v5->mPrev;
  v5->mPrev = v10;
  v5->mNext = v9;
  v9->mPrev = (UFG::qNode<CullLayer,CullLayer> *)&v5->mPrev;
  ++v8->mNumCullLayers;
}

// File Line: 202
// RVA: 0x25990
void __fastcall CullLayer::~CullLayer(CullLayer *this)
{
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v1; // rdi
  CullManager *v2; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v3; // rdx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v4; // rcx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v5; // rcx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v6; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v7; // rcx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v8; // rax
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v9; // rcx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v10; // rax

  v1 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)this;
  v2 = CullManager::Instance();
  if ( v1 )
  {
    v3 = v1->mNode.mPrev;
    v4 = v1->mNode.mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v1->mNode.mPrev = &v1->mNode;
    v1->mNode.mNext = &v1->mNode;
    --v2->mNumCullLayers;
  }
  `eh vector destructor iterator'(
    &v1[5],
    8ui64,
    16,
    (void (__fastcall *)(void *))UFG::qSList<CullResultBucket,CullResultBucket,1>::~qSList<CullResultBucket,CullResultBucket,1>);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes(v1 + 4);
  v5 = v1[4].mNode.mPrev;
  v6 = v1[4].mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1[4].mNode.mPrev = &v1[4].mNode;
  v1[4].mNode.mNext = &v1[4].mNode;
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes(v1 + 3);
  v7 = v1[3].mNode.mPrev;
  v8 = v1[3].mNode.mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  v1[3].mNode.mPrev = &v1[3].mNode;
  v1[3].mNode.mNext = &v1[3].mNode;
  v9 = v1->mNode.mPrev;
  v10 = v1->mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 225
// RVA: 0x256D0
void __fastcall PersistentCullBucket::PersistentCullBucket(PersistentCullBucket *this, int alloc_results, int num_cull_infos, int sizeof_cull_info)
{
  int v4; // er13
  int v5; // er12
  int v6; // ebx
  PersistentCullBucket *v7; // rdi
  char *v8; // rsi
  unsigned int v9; // ebp
  unsigned int v10; // er14
  char *v11; // rbx
  char *v12; // r15
  char *v13; // rax

  v4 = sizeof_cull_info;
  v5 = num_cull_infos;
  v6 = alloc_results;
  v7 = this;
  this->mPrev = (UFG::qNode<CullBucket,CullBucket> *)&this->mPrev;
  this->mNext = (UFG::qNode<CullBucket,CullBucket> *)&this->mPrev;
  v8 = 0i64;
  this->mCullInfos = 0i64;
  this->mFullCullInfos = 0i64;
  this->mResults = 0i64;
  *(_QWORD *)&this->mType = 0i64;
  this->mCullInfosAlloced = 0;
  UFG::qFixedAllocator::qFixedAllocator(&this->mFixedAllocator);
  v9 = ((v5 << 6) + 31) & 0xFFFFFFE0;
  v10 = v4 * v5;
  if ( v6 )
    v11 = UFG::qMalloc(v9, "PersistentCullBucket_mCullResults", 0x2000ui64);
  else
    v11 = 0i64;
  v12 = UFG::qMalloc(v10, "PersistentCullBucket_mCullInfos", 0x2000ui64);
  if ( v11 )
    UFG::qMemSet(v11, 0, v9);
  UFG::qMemSet(v12, 0, v10);
  v7->mType = 2;
  v7->mResults = (CullResults *)v11;
  v13 = 0i64;
  if ( v4 == 128 )
    v13 = v12;
  v7->mFullCullInfos = (CullInfoFull *)v13;
  if ( v4 == 64 )
    v8 = v12;
  v7->mCullInfos = (CullInfo *)v8;
  v7->mMax = v5;
  v7->mCullInfosAlloced = v5;
  UFG::qFixedAllocator::Init(&v7->mFixedAllocator, v12, v10, v4, "PersistentCullBucket");
}

// File Line: 253
// RVA: 0x25A60
void __fastcall PersistentCullBucket::~PersistentCullBucket(PersistentCullBucket *this)
{
  PersistentCullBucket *v1; // rsi
  CullInfoFull *v2; // rbx
  CullInfo *v3; // rdi
  UFG::qNode<CullBucket,CullBucket> *v4; // rcx
  UFG::qNode<CullBucket,CullBucket> *v5; // rax

  v1 = this;
  v2 = this->mFullCullInfos;
  v3 = this->mCullInfos;
  operator delete[](this->mResults);
  operator delete[](v2);
  operator delete[](v3);
  v1->mResults = 0i64;
  v1->mFullCullInfos = 0i64;
  v1->mCullInfos = 0i64;
  UFG::qFixedAllocator::Close(&v1->mFixedAllocator);
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<CullBucket,CullBucket> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<CullBucket,CullBucket> *)&v1->mPrev;
}

// File Line: 424
// RVA: 0x27380
void __fastcall CullManager::CullSettings::SetFromViewSettings(CullManager::CullSettings *this, Render::ViewSettings *view_settings)
{
  float v2; // xmm0_4
  CullManager::CullSettings *v3; // rdi
  Render::ViewSettings *v4; // rbx
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  UFG::qMatrix44 *v10; // rax
  UFG::qVector4 v11; // xmm3
  UFG::qVector4 v12; // xmm2
  UFG::qVector4 v13; // xmm1
  UFG::qMatrix44 d; // [rsp+20h] [rbp-A8h]
  UFG::qMatrix44 result; // [rsp+60h] [rbp-68h]

  v2 = view_settings->mProjection.v2.z;
  v3 = this;
  v4 = view_settings;
  v5 = view_settings->mProjection.v3.z / v2;
  v6 = (float)(view_settings->mProjection.v3.z - view_settings->mProjection.v3.w)
     / (float)(v2 - view_settings->mProjection.v2.w);
  UFG::qInverseAffine(&d, &view_settings->mWorldView);
  v7 = d.v3.x;
  v8 = d.v3.y;
  v3->mFarPlane = v6;
  v3->mNearPlane = v5;
  v3->mPixelDensityThreshold = v4->mCullPixelDensityThreshold;
  v3->mPixelDistanceBias = v4->mCullPixelDistanceBias;
  v3->mViewWorldPos.x = v7;
  v9 = d.v3.z;
  v3->mViewWorldPos.y = v8;
  v3->mViewWorldPos.z = v9;
  v10 = UFG::qMatrix44::operator*(&v4->mWorldView, &result, &v4->mProjection);
  v11 = v10->v1;
  v12 = v10->v2;
  v13 = v10->v3;
  v3->mWorldViewProjection.v0 = v10->v0;
  v3->mWorldViewProjection.v1 = v11;
  v3->mWorldViewProjection.v2 = v12;
  v3->mWorldViewProjection.v3 = v13;
}

// File Line: 460
// RVA: 0x27210
CullManager *__fastcall CullManager::Instance()
{
  if ( !(_S1_2 & 1) )
  {
    _S1_2 |= 1u;
    `eh vector constructor iterator'(
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
  CullManager *v2; // r14
  UFG::qNode<CullLayer,CullLayer> **v3; // rsi
  signed __int64 v4; // rdi
  signed __int64 v5; // rbp
  UFG::qNode<CullLayer,CullLayer> *i; // rbx
  UFG::qString v7; // [rsp+28h] [rbp-30h]

  v2 = this;
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
  v2->mZbuffer2 = UFG::qMalloc(0x10080ui64, "CullManager::mZbuffer", 0x8000ui64);
  v2->mZbuffer3 = UFG::qMalloc(0x10080ui64, "CullManager::mZbuffer", 0x8000ui64);
  v2->mZbuffer4 = UFG::qMalloc(0x10080ui64, "CullManager::mZbuffer", 0x8000ui64);
  v2->mOcclusionDebugTexture = 0i64;
  *(_WORD *)&v2->mEnableOcclusionCulling = 1;
  *(_QWORD *)&v2->mDrawCullInfoNum = 0i64;
  v2->mDrawOcclusionMapScale = 0;
  v2->mDrawOcclusionMapOpacity = 0.30000001;
  v2->mDetailedCullInfoIndex = 0;
  v2->mDetailedCullInfoLocked = 0;
  v3 = &v2->mCullLayers[0].mNode.mNext;
  v4 = (signed __int64)v2->mCullLayers;
  v5 = 2i64;
  do
  {
    for ( i = *v3; i != (UFG::qNode<CullLayer,CullLayer> *)v4; i = i->mNext )
    {
      UFG::qString::qString(&v7);
      UFG::qString::Format(&v7, "\\Rendering\\Culling\\Layers\\%s", i[1].mNext);
      UFG::qString::~qString(&v7);
    }
    v4 += 16i64;
    v3 += 2;
    --v5;
  }
  while ( v5 );
  _((AMD_HD3D *)v2);
}

// File Line: 896
// RVA: 0x272A0
__int64 __fastcall CullManager::RegisterView(CullManager *this, CullManager::CullSettings *view_settings)
{
  unsigned int v2; // er8
  CullManager::CullSettings *v3; // r10
  signed __int64 v4; // rax
  __int64 result; // rax
  UFG::qVector4 v6; // xmm1
  __int64 v7; // rdx
  UFG::qVector4 v8; // xmm3
  UFG::qVector4 v9; // xmm2
  float v10; // xmm0_4

  v2 = 0;
  v3 = view_settings;
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
  this->mViewSlots[v2] = 2;
  v6 = view_settings->mWorldViewProjection.v3;
  v7 = (signed int)v2;
  v8 = v3->mWorldViewProjection.v1;
  v9 = v3->mWorldViewProjection.v2;
  this->mViewSettings[v7].mWorldViewProjection.v0 = v3->mWorldViewProjection.v0;
  this->mViewSettings[v7].mWorldViewProjection.v1 = v8;
  this->mViewSettings[v7].mWorldViewProjection.v2 = v9;
  this->mViewSettings[v7].mWorldViewProjection.v3 = v6;
  this->mViewSettings[v7].mNearPlane = v3->mNearPlane;
  this->mViewSettings[v7].mFarPlane = v3->mFarPlane;
  this->mViewSettings[v7].mPixelDensityThreshold = v3->mPixelDensityThreshold;
  result = v2;
  this->mViewSettings[v7].mPixelDistanceBias = v3->mPixelDistanceBias;
  this->mViewSettings[v7].mViewFlags = v3->mViewFlags;
  this->mViewSettings[v7].mViewUserFilter = v3->mViewUserFilter;
  v10 = v3->mViewWorldPos.y;
  v6.x = v3->mViewWorldPos.z;
  this->mViewSettings[v7].mViewWorldPos.x = v3->mViewWorldPos.x;
  this->mViewSettings[v7].mViewWorldPos.y = v10;
  this->mViewSettings[v7].mViewWorldPos.z = v6.x;
  return result;
}

// File Line: 921
// RVA: 0x26AE0
void __fastcall CullManager::DeregisterView(CullManager *this, int view_index)
{
  CullManager *v2; // rdi
  Render::RasterizeZ *v3; // rcx
  __int64 v4; // rbx

  if ( view_index != -1 )
  {
    v2 = this;
    v3 = this->mRasterizers;
    v4 = view_index;
    *((_DWORD *)&v3[-32] + view_index - 12) = 0;
    Render::RasterizeZ::Init(&v3[view_index], 0i64, 1u);
    Render::OcclusionMap::Init(&v2->mOcclusionMaps[v4], 0i64);
  }
}

// File Line: 933
// RVA: 0x26A60
void __fastcall CullManager::DeregisterAllViews(CullManager *this)
{
  CullManager *v1; // rdi
  Render::OcclusionMap *v2; // rsi
  signed int v3; // ebx
  Render::RasterizeZ *v4; // rbp

  v1 = this;
  v2 = this->mOcclusionMaps;
  v3 = 0;
  v4 = this->mRasterizers;
  do
  {
    if ( v3 != -1 )
    {
      v1->mViewSlots[0] = 0;
      Render::RasterizeZ::Init(v4, 0i64, 1u);
      Render::OcclusionMap::Init(v2, 0i64);
    }
    ++v3;
    ++v4;
    ++v2;
    v1 = (CullManager *)((char *)v1 + 4);
  }
  while ( v3 < 16 );
}

// File Line: 966
// RVA: 0x26F60
UFG::qList<CullBucket,CullBucket,1,0> *__fastcall GetEmptyCullBucket(UFG::qList<CullBucket,CullBucket,1,0> *bucket_list, int alloc_results, int max_cull_infos, int sizeof_cull_info)
{
  int v4; // esi
  int v5; // ebp
  int v6; // edi
  UFG::qList<CullBucket,CullBucket,1,0> *v7; // rbx
  UFG::qList<CullBucket,CullBucket,1,0> *result; // rax
  char *v9; // rax
  UFG::qList<CullBucket,CullBucket,1,0> **v10; // rax
  UFG::qList<CullBucket,CullBucket,1,0> **v11; // rcx
  UFG::qNode<CullBucket,CullBucket> *v12; // rax

  v4 = sizeof_cull_info;
  v5 = max_cull_infos;
  v6 = alloc_results;
  v7 = bucket_list;
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
    PersistentCullBucket::PersistentCullBucket((PersistentCullBucket *)v9, v6, v5, v4);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = v7->mNode.mNext;
  v7->mNode.mNext = (UFG::qNode<CullBucket,CullBucket> *)v11;
  *v11 = v7;
  v11[1] = (UFG::qList<CullBucket,CullBucket,1,0> *)v12;
  v12->mPrev = (UFG::qNode<CullBucket,CullBucket> *)v11;
  return (UFG::qList<CullBucket,CullBucket,1,0> *)v11;
}

// File Line: 1008
// RVA: 0x25B90
void __fastcall CullManager::AllocPersistentCullInfo(CullManager *this, CullResults **cull_result, CullInfo **cull_info, CullLayer *cull_layer, void *cull_info_param0, void *cull_info_param1)
{
  CullResults **v6; // r15
  CullInfo **v7; // rbp
  CullLayer *v8; // r13
  UFG::qList<CullBucket,CullBucket,1,0> *v9; // r14
  PersistentCullBucket *v10; // rax
  PersistentCullBucket *v11; // rbx
  char *v12; // rdi
  char *v13; // rcx
  unsigned int v14; // edx
  unsigned __int64 v15; // rdx
  UFG::qNode<CullBucket,CullBucket> *v16; // rax
  UFG::qNode<CullBucket,CullBucket> *v17; // rcx
  UFG::qNode<CullBucket,CullBucket> *v18; // rax

  if ( cull_info )
  {
    v6 = cull_result;
    v7 = cull_info;
    v8 = &gDefaultCullLayer;
    if ( cull_layer )
      v8 = cull_layer;
    v9 = &v8->mPersistentCullBuckets;
    v10 = GetEmptyCullBucket(&v8->mPersistentCullBuckets, cull_result != 0i64, 256, 64);
    v11 = v10;
    v12 = v10->mFixedAllocator.mFreeListHead;
    if ( v12 )
    {
      v13 = *(char **)v12;
      v14 = ++v10->mFixedAllocator.mNumSlotsAllocated;
      v10->mFixedAllocator.mFreeListHead = v13;
      if ( v10->mFixedAllocator.mMostSlotsAllocated > v14 )
        v14 = v10->mFixedAllocator.mMostSlotsAllocated;
      v10->mFixedAllocator.mMostSlotsAllocated = v14;
    }
    else
    {
      UFG::qFixedAllocator::ReportFull(&v10->mFixedAllocator);
    }
    v15 = (unsigned __int64)(unsigned int)((v12 - v11->mFixedAllocator.mBuffer) / v11->mFixedAllocator.mSlotSize) << 6;
    *v7 = (CullInfo *)((char *)v11->mCullInfos + v15);
    if ( v6 )
      *v6 = (CullResults *)((char *)v11->mResults + v15);
    *((_QWORD *)v12 + 4) = v8;
    *((_QWORD *)v12 + 5) = cull_info_param0;
    *((_QWORD *)v12 + 7) = 0i64;
    *((_QWORD *)v12 + 6) = cull_info_param1;
    if ( !v11->mFixedAllocator.mFreeListHead )
    {
      v16 = v11->mNext;
      v17 = v11->mPrev;
      v17->mNext = v16;
      v16->mPrev = v17;
      v11->mPrev = (UFG::qNode<CullBucket,CullBucket> *)&v11->mPrev;
      v11->mNext = (UFG::qNode<CullBucket,CullBucket> *)&v11->mPrev;
      v18 = v9->mNode.mPrev;
      v18->mNext = (UFG::qNode<CullBucket,CullBucket> *)&v11->mPrev;
      v11->mPrev = v18;
      v11->mNext = &v9->mNode;
      v9->mNode.mPrev = (UFG::qNode<CullBucket,CullBucket> *)&v11->mPrev;
    }
  }
}

// File Line: 1048
// RVA: 0x25CC0
void __fastcall CullManager::AllocPersistentOcclusionInfo(CullManager *this, CullInfoFull **occlusion_info, CullLayer *cull_layer)
{
  CullInfoFull **v3; // r12
  CullLayer *v4; // rbp
  UFG::qList<CullBucket,CullBucket,1,0> *v5; // r14
  UFG::qList<CullBucket,CullBucket,1,0> *v6; // rsi
  char *v7; // rax
  char *v8; // rbx
  UFG::qNode<CullBucket,CullBucket> *v9; // rax
  CullInfoFull *v10; // rbx
  unsigned int v11; // ecx
  UFG::qNode<CullBucket,CullBucket> *v12; // rcx
  UFG::qNode<CullBucket,CullBucket> *v13; // rax
  UFG::qNode<CullBucket,CullBucket> *v14; // rax

  if ( occlusion_info )
  {
    v3 = occlusion_info;
    v4 = &gDefaultOcclusionLayer;
    if ( cull_layer )
      v4 = cull_layer;
    v5 = &v4->mPersistentCullBuckets;
    v6 = (UFG::qList<CullBucket,CullBucket,1,0> *)v4->mPersistentCullBuckets.mNode.mNext;
    if ( v6 == &v4->mPersistentCullBuckets || !v6[5].mNode.mNext )
    {
      v7 = UFG::qMalloc(0x70ui64, "PersistentCullBucket", 0x800ui64);
      v6 = (UFG::qList<CullBucket,CullBucket,1,0> *)v7;
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
        LODWORD(v6[2].mNode.mNext) = 2;
        v6[2].mNode.mPrev = 0i64;
        v6[1].mNode.mNext = (UFG::qNode<CullBucket,CullBucket> *)v8;
        v6[1].mNode.mPrev = 0i64;
        HIDWORD(v6[2].mNode.mNext) = 256;
        LODWORD(v6[3].mNode.mPrev) = 256;
        UFG::qFixedAllocator::Init((UFG::qFixedAllocator *)&v6[4], v8, 0x8000, 128, "PersistentCullBucket");
      }
      else
      {
        v6 = 0i64;
      }
      v9 = v4->mPersistentCullBuckets.mNode.mNext;
      v4->mPersistentCullBuckets.mNode.mNext = &v6->mNode;
      v6->mNode.mPrev = &v5->mNode;
      v6->mNode.mNext = v9;
      v9->mPrev = &v6->mNode;
    }
    v10 = (CullInfoFull *)v6[5].mNode.mNext;
    if ( v10 )
    {
      v6[5].mNode.mNext = *(UFG::qNode<CullBucket,CullBucket> **)v10->mAABBMin;
      v11 = ++HIDWORD(v6[6].mNode.mPrev);
      if ( LODWORD(v6[6].mNode.mNext) > v11 )
        v11 = (unsigned int)v6[6].mNode.mNext;
      LODWORD(v6[6].mNode.mNext) = v11;
    }
    else
    {
      UFG::qFixedAllocator::ReportFull((UFG::qFixedAllocator *)&v6[4]);
    }
    *v3 = v10;
    v10->mCullLayer = v4;
    if ( !v6[5].mNode.mNext )
    {
      v12 = v6->mNode.mPrev;
      v13 = v6->mNode.mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      v6->mNode.mPrev = &v6->mNode;
      v6->mNode.mNext = &v6->mNode;
      v14 = v5->mNode.mPrev;
      v14->mNext = &v6->mNode;
      v6->mNode.mPrev = v14;
      v6->mNode.mNext = &v5->mNode;
      v5->mNode.mPrev = &v6->mNode;
    }
  }
}

// File Line: 1077
// RVA: 0x26D40
void __fastcall CullManager::FreePersistentCullInfo(CullManager *this, CullResults *cull_result, CullInfo *cull_info)
{
  CullLayer *v3; // rsi
  PersistentCullBucket *v4; // rbx
  signed __int64 v5; // rsi
  CullInfo *v6; // rdi
  CullManager *v7; // rbp
  unsigned __int64 v8; // rcx
  signed __int64 v9; // r14
  CullResults *v10; // rax
  UFG::qNode<CullBucket,CullBucket> *v11; // rax
  UFG::qNode<CullBucket,CullBucket> *v12; // rcx
  PersistentCullBucket **v13; // rax

  if ( cull_info )
  {
    v3 = cull_info->mCullLayer;
    v4 = (PersistentCullBucket *)v3->mPersistentCullBuckets.mNode.mNext;
    v5 = (signed __int64)&v3->mPersistentCullBuckets;
    v6 = cull_info;
    v7 = this;
    if ( v4 != (PersistentCullBucket *)v5 )
    {
      while ( 1 )
      {
        v8 = (unsigned __int64)v4->mFixedAllocator.mBuffer;
        if ( (unsigned __int64)cull_info < v8 + v4->mFixedAllocator.mBufferSize && (unsigned __int64)cull_info >= v8 )
          break;
        v4 = (PersistentCullBucket *)v4->mNext;
        if ( v4 == (PersistentCullBucket *)v5 )
          return;
      }
      if ( v4 )
      {
        v9 = (signed __int64)(signed int)(((char *)cull_info - v4->mFixedAllocator.mBuffer)
                                        / v4->mFixedAllocator.mSlotSize) << 6;
        UFG::qMemSet((char *)v4->mCullInfos + v9, 0, 0x40u);
        v10 = v4->mResults;
        if ( v10 )
          UFG::qMemSet(&v10->mViewResult[v9], 0, 0x40u);
        *(_QWORD *)v6->mAABBMin = v4->mFixedAllocator.mFreeListHead;
        --v4->mFixedAllocator.mNumSlotsAllocated;
        v4->mFixedAllocator.mFreeListHead = (char *)v6;
        if ( v4->mFixedAllocator.mNumSlotsAllocated )
        {
          v11 = v4->mNext;
          v12 = v4->mPrev;
          v12->mNext = v11;
          v11->mPrev = v12;
          v4->mPrev = (UFG::qNode<CullBucket,CullBucket> *)&v4->mPrev;
          v4->mNext = (UFG::qNode<CullBucket,CullBucket> *)&v4->mPrev;
          v13 = *(PersistentCullBucket ***)(v5 + 8);
          *(_QWORD *)(v5 + 8) = v4;
          v4->mNext = (UFG::qNode<CullBucket,CullBucket> *)v13;
          v4->mPrev = (UFG::qNode<CullBucket,CullBucket> *)v5;
          *v13 = v4;
        }
        else
        {
          PersistentCullBucket::~PersistentCullBucket(v4);
          operator delete[](v4);
          --v7->mNumCullBuckets;
        }
      }
    }
  }
}

// File Line: 1124
// RVA: 0x26E70
void __fastcall CullManager::FreePersistentOcclusionInfo(CullManager *this, CullInfoFull *occlusion_info)
{
  CullLayer *v2; // rdi
  PersistentCullBucket *v3; // rbx
  signed __int64 v4; // rdi
  CullInfoFull *v5; // rsi
  CullManager *v6; // rbp
  UFG::qNode<CullBucket,CullBucket> *v7; // rax
  UFG::qNode<CullBucket,CullBucket> *v8; // rcx
  PersistentCullBucket **v9; // rax

  if ( occlusion_info )
  {
    v2 = occlusion_info->mCullLayer;
    v3 = (PersistentCullBucket *)v2->mPersistentCullBuckets.mNode.mNext;
    v4 = (signed __int64)&v2->mPersistentCullBuckets;
    v5 = occlusion_info;
    v6 = this;
    if ( v3 != (PersistentCullBucket *)v4 )
    {
      while ( (char *)occlusion_info >= &v3->mFixedAllocator.mBuffer[(unsigned __int64)v3->mFixedAllocator.mBufferSize]
           || (char *)occlusion_info < v3->mFixedAllocator.mBuffer )
      {
        v3 = (PersistentCullBucket *)v3->mNext;
        if ( v3 == (PersistentCullBucket *)v4 )
          return;
      }
      if ( v3 )
      {
        UFG::qMemSet(occlusion_info, 0, 0x80u);
        *(_QWORD *)v5->mAABBMin = v3->mFixedAllocator.mFreeListHead;
        --v3->mFixedAllocator.mNumSlotsAllocated;
        v3->mFixedAllocator.mFreeListHead = (char *)v5;
        if ( v3->mFixedAllocator.mNumSlotsAllocated )
        {
          v7 = v3->mNext;
          v8 = v3->mPrev;
          v8->mNext = v7;
          v7->mPrev = v8;
          v3->mPrev = (UFG::qNode<CullBucket,CullBucket> *)&v3->mPrev;
          v3->mNext = (UFG::qNode<CullBucket,CullBucket> *)&v3->mPrev;
          v9 = *(PersistentCullBucket ***)(v4 + 8);
          *(_QWORD *)(v4 + 8) = v3;
          v3->mNext = (UFG::qNode<CullBucket,CullBucket> *)v9;
          v3->mPrev = (UFG::qNode<CullBucket,CullBucket> *)v4;
          *v9 = v3;
        }
        else
        {
          PersistentCullBucket::~PersistentCullBucket(v3);
          operator delete[](v3);
          --v6->mNumOcclusionBuckets;
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
    result = v4;
  }
  return result;
}

// File Line: 1194
// RVA: 0x25E70
void __fastcall CullManager::AllocPrebuiltFrameCullInfos(CullManager *this, CullResults **cull_results, int num_infos, CullInfo *prebuilt_cull_infos, CullLayer *cull_layer)
{
  CullInfo *v5; // rsi
  __int64 v6; // rbx
  CullResults **v7; // r14
  CullLayer *v8; // rbp
  unsigned int v9; // edi
  char *v10; // rax
  CullResults *v11; // rdi
  char *v12; // rdx
  __int64 *v13; // r8
  unsigned int v14; // ecx
  __int64 v15; // rax
  __int64 v16; // rax

  if ( num_infos )
  {
    v5 = prebuilt_cull_infos;
    v6 = num_infos;
    v7 = cull_results;
    v8 = &gDefaultCullLayer;
    if ( cull_layer )
      v8 = cull_layer;
    if ( cull_results )
    {
      v9 = ((num_infos << 6) + 31) & 0xFFFFFFE0;
      v10 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, v9, 0x20u);
      *v7 = (CullResults *)v10;
      if ( !v10 )
        return;
      UFG::qMemSet(v10, 0, v9);
    }
    if ( v7 )
      v11 = *v7;
    else
      v11 = 0i64;
    v12 = UFG::qLinearAllocator::Malloc(
            Illusion::gEngine.FrameMemory,
            (unsigned int)((signed __int64)((v6 + 255) & 0xFFFFFFFFFFFFFF00ui64) / 256) << 6,
            0x10u);
    if ( v12 && (_DWORD)v6 )
    {
      v13 = (__int64 *)&v8->mFrameCullBuckets;
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
        *((_QWORD *)v12 + 2) = v5;
        *((_DWORD *)v12 + 12) = v14;
        v15 = *v13;
        *(_QWORD *)(v15 + 8) = v12;
        *(_QWORD *)v12 = v15;
        *((_QWORD *)v12 + 1) = v13;
        *v13 = (__int64)v12;
        v5 += v14;
        v16 = 0i64;
        if ( v7 )
          v16 = v14;
        v11 += v16;
        v12 += 64;
        LODWORD(v6) = v6 - v14;
      }
      while ( (_DWORD)v6 );
    }
  }
}

// File Line: 1260
// RVA: 0x25FF0
void __fastcall CullManager::AllocPrebuiltFrameOcclusionInfos(CullManager *this, int num_infos, CullInfoFull *prebuilt_occlusion_infos, CullLayer *cull_layer)
{
  CullInfoFull *v4; // rdi
  int v5; // ebx
  CullLayer *v6; // rsi
  char *v7; // rdx
  __int64 *v8; // r8
  float v9; // xmm0_4
  unsigned int v10; // ecx
  __int64 v11; // rax

  if ( num_infos )
  {
    v4 = prebuilt_occlusion_infos;
    v5 = num_infos;
    v6 = &gDefaultOcclusionLayer;
    if ( cull_layer )
      v6 = cull_layer;
    v7 = UFG::qLinearAllocator::Malloc(
           Illusion::gEngine.FrameMemory,
           (unsigned int)((signed __int64)((num_infos + 255i64) & 0xFFFFFFFFFFFFFF00ui64) / 256) << 6,
           0x10u);
    if ( v7 && v5 )
    {
      v8 = (__int64 *)&v6->mFrameCullBuckets;
      do
      {
        v9 = (float)v5;
        if ( (float)v5 >= 256.0 )
          v9 = FLOAT_256_0;
        v10 = (signed int)v9;
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
        *((_QWORD *)v7 + 3) = v4;
        *((_DWORD *)v7 + 12) = v10;
        v11 = *v8;
        *(_QWORD *)(v11 + 8) = v7;
        *(_QWORD *)v7 = v11;
        *((_QWORD *)v7 + 1) = v8;
        *v8 = (__int64)v7;
        v4 += v10;
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
  CullManager *v1; // r14
  UFG::qList<CullLayer,CullLayer,1,0> *v2; // rbx
  signed __int64 i; // rbp
  UFG::qList<CullLayer,CullLayer,1,0> *v4; // rax
  UFG::qNode<CullLayer,CullLayer> *v5; // rcx
  UFG::qList<CullLayer,CullLayer,1,0> *v6; // rdi
  Render::OcclusionMap *v7; // rdi
  Render::RasterizeZ *v8; // rbx
  Render::RasterizeZ v9; // [rsp+20h] [rbp-58h]

  v1 = this;
  this->mDoCullingTiming = 0.0;
  this->mPrevOcclusionTask = 0i64;
  this->mPrevCullingTask = 0i64;
  UFG::qMemSet(this->mFinalTasks, 0, 0x80u);
  v2 = (UFG::qList<CullLayer,CullLayer,1,0> *)v1->mCullLayers[0].mNode.mNext;
  for ( i = 16i64; v2 != v1->mCullLayers; v2 = (UFG::qList<CullLayer,CullLayer,1,0> *)v2->mNode.mNext )
  {
    memset(&v2[5], 0, 0x80ui64);
    v4 = (UFG::qList<CullLayer,CullLayer,1,0> *)v2[4].mNode.mNext;
    if ( v4 != &v2[4] )
    {
      do
      {
        v5 = v4[2].mNode.mPrev;
        v6 = (UFG::qList<CullLayer,CullLayer,1,0> *)v4->mNode.mNext;
        if ( v5 )
          UFG::qMemSet(v5, 0, HIDWORD(v4[2].mNode.mNext) << 6);
        v4 = v6;
      }
      while ( v6 != &v2[4] );
    }
  }
  v7 = v1->mOcclusionMaps;
  v8 = v1->mRasterizers;
  do
  {
    Render::RasterizeZ::Init(v8, 0i64, 1u);
    Render::OcclusionMap::Init(v7, 0i64);
    ++v8;
    ++v7;
    --i;
  }
  while ( i );
  Render::RasterizeZ::Init(&v9, v1->mZbuffer1, 0);
  *v9.mZBufferTag = -1;
  Render::RasterizeZ::Init(&v9, v1->mZbuffer2, 0);
  *v9.mZBufferTag = -1;
  Render::RasterizeZ::Init(&v9, v1->mZbuffer3, 0);
  *v9.mZBufferTag = -1;
  Render::RasterizeZ::Init(&v9, v1->mZbuffer4, 0);
  *v9.mZBufferTag = -1;
}

// File Line: 1361
// RVA: 0x26C80
void __fastcall CullManager::EndFrame(CullManager *this)
{
  UFG::qTaskGroup *v1; // rdx
  CullManager *v2; // rbx
  Illusion::eCastShadow *v3; // rcx
  UFG::qNode<CullLayer,CullLayer> *i; // rdx
  UFG::qNode<CullLayer,CullLayer> *v5; // rax
  UFG::qNode<CullLayer,CullLayer> *j; // rcx
  UFG::qNode<CullLayer,CullLayer> *v7; // rax

  v1 = this->mPrevCullingTask;
  v2 = this;
  if ( v1 )
    UFG::qTaskManager::Sync(&UFG::gTaskManager, v1);
  CullManager::DeregisterAllViews(v2);
  Illusion::eCastShadow::ClearCastShadowViewFilter(v3);
  for ( i = v2->mCullLayers[0].mNode.mNext; i != (UFG::qNode<CullLayer,CullLayer> *)v2->mCullLayers; i = i->mNext )
  {
    v5 = i + 3;
    v5->mPrev = v5;
    v5->mNext = v5;
  }
  for ( j = v2->mCullLayers[1].mNode.mNext; j != (UFG::qNode<CullLayer,CullLayer> *)&v2->mCullLayers[1]; j = j->mNext )
  {
    v7 = j + 3;
    v7->mPrev = v7;
    v7->mNext = v7;
  }
}

// File Line: 1400
// RVA: 0x262B0
char __fastcall CullManager::BeginView(CullManager *this, int view_index, UFG::qTaskGroup *dependent)
{
  signed __int64 v3; // r13
  CullManager *v4; // rsi
  char *v6; // r12
  int v7; // eax
  signed __int64 v8; // rbp
  int v9; // eax
  UFG::qTask *v10; // rbx
  signed __int64 v11; // r14
  char *v12; // rbx
  char *v13; // rdi
  char *v14; // r15
  char *v15; // rax
  void *v16; // rcx
  void *v17; // rdx
  void *v18; // r8
  void *v19; // r9
  __int128 v20; // xmm2
  __int128 v21; // xmm1
  __int128 v22; // xmm0
  char *v23; // rax
  UFG::qTaskGroup *v24; // rdi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v25; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v26; // rax
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v27; // rbx
  UFG::qNode<CullLayer,CullLayer> *v28; // r14
  char *v29; // rax
  char *v30; // rdx
  _QWORD *v31; // rcx
  UFG::qSpuElf *v32; // rax
  void (__fastcall *v33)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v34)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v35)(void *, void *, void *, void *); // r9
  char *v36; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v37; // rax
  Render::OcclusionMap *v38; // r14
  void *v39; // rbp
  char *v40; // rax
  _QWORD *v41; // rax
  UFG::qSpuElf *v42; // rax
  void (__fastcall *v43)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // rdx
  void (__fastcall *v44)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r9
  unsigned int (__fastcall *v45)(void *, void *, void *, void *); // r8
  char *v46; // rcx
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v47; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v48; // rax
  char *v49; // rax
  char *v50; // r15
  __int128 v51; // xmm2
  __int128 v52; // xmm1
  __int128 v53; // xmm0
  UFG::qLinearAllocator *v54; // rcx
  char *v55; // rax
  char *v56; // rax
  UFG::qTaskGroup *v57; // rdi
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v58; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v59; // rax
  UFG::qList<UFG::qTask,UFG::qTask,0,0> *v60; // rbx
  __int64 v61; // rbp
  UFG::qNode<CullLayer,CullLayer> *v62; // r14
  char *v63; // rax
  char *v64; // rdx
  _QWORD *v65; // rcx
  UFG::qSpuElf *v66; // rax
  void (__fastcall *v67)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v68)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v69)(void *, void *, void *, void *); // r9
  char *v70; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v71; // rax
  Render::OcclusionMap *v72; // [rsp+20h] [rbp-68h]
  CullManager::CullSettings *v73; // [rsp+28h] [rbp-60h]
  int v74; // [rsp+98h] [rbp+10h]
  UFG::qTaskGroup *dependenta; // [rsp+A0h] [rbp+18h]
  int v76; // [rsp+A8h] [rbp+20h]

  dependenta = dependent;
  v74 = view_index;
  v3 = view_index;
  v4 = this;
  if ( view_index == -1 || this->mViewSlots[view_index] != 2 )
    return 0;
  v6 = (char *)&this->mViewSettings[view_index];
  v73 = &this->mViewSettings[view_index];
  v7 = UFG::qTaskManager::GetMaxWorkers(&UFG::gTaskManager);
  v8 = (unsigned int)v7;
  if ( v7 < 1 )
    v8 = 1i64;
  v9 = UFG::qTaskManager::GetMaxWorkers(&UFG::gTaskManager);
  if ( v9 < 1 )
    v9 = 1;
  v76 = v9;
  v10 = 0i64;
  v11 = v3;
  v72 = &v4->mOcclusionMaps[v3];
  if ( v6[80] & 1 && v4->mEnableOcclusionCulling )
  {
    v12 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x10080u, 0x20u);
    v13 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x9000u, 0x20u);
    if ( v12 == 0i64 || v13 == 0i64 )
      return 0;
    Render::RasterizeZ::Init(&v4->mRasterizers[v11], v12, 0);
    *v4->mRasterizers[v11].mZBufferTag = -1;
    UFG::CoverObjectBase::SetCoverObjectGroup((hkDynamicClassNameRegistry *)&v4->mRasterizers[v11], v6);
    Render::OcclusionMap::Init(&v4->mOcclusionMaps[v3], v13);
    Render::OcclusionMap::BeginFrame(&v4->mOcclusionMaps[v3], (UFG::qMatrix44 *)v6);
    v14 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x80u, 0x80u);
    v15 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x20u, 0x20u);
    v16 = v4->mZbuffer1;
    v17 = v4->mZbuffer2;
    v18 = v4->mZbuffer3;
    v19 = v4->mZbuffer4;
    if ( !v14 || !v15 )
      return 0;
    v20 = *((_OWORD *)v6 + 1);
    v21 = *((_OWORD *)v6 + 2);
    v22 = *((_OWORD *)v6 + 3);
    *(_OWORD *)v14 = *(_OWORD *)v6;
    *((_OWORD *)v14 + 1) = v20;
    *((_OWORD *)v14 + 2) = v21;
    *((_OWORD *)v14 + 3) = v22;
    *((_QWORD *)v14 + 8) = v12;
    *((_QWORD *)v14 + 9) = v16;
    *((_QWORD *)v14 + 10) = v17;
    *((_QWORD *)v14 + 11) = v18;
    *((_QWORD *)v14 + 12) = v19;
    *((_DWORD *)v14 + 26) = v3;
    *((_QWORD *)v14 + 14) = v15;
    *(_DWORD *)v15 = -1;
    v23 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
    v24 = (UFG::qTaskGroup *)v23;
    if ( v23 )
      UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v23, "RasterizeBucket");
    v25 = UFG::gTaskManager.mSingleFrameTaskGroups;
    v26 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
    v26->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v24->mPrev;
    v24->mPrev = v26;
    v24->mNext = &v25->mNode;
    v25->mNode.mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v24->mPrev;
    if ( (signed int)v8 > 0 )
    {
      v27 = &v24->mTasks;
      do
      {
        v28 = v4->mCullLayers[1].mNode.mNext;
        v29 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
        v30 = v29;
        if ( v29 )
        {
          *(_QWORD *)v29 = v29;
          *((_QWORD *)v29 + 1) = v29;
          v31 = v29 + 16;
          *v31 = v31;
          v31[1] = v31;
          v32 = Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer.mSpuElf;
          v33 = Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer.mTaskFunctionSPU;
          v34 = Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer.mTaskFunctionPPU;
          v35 = Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer.mTaskFunctionOffload;
          if ( !Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer.mCurrentSPUEnabled )
          {
            v32 = 0i64;
            v33 = 0i64;
            v35 = 0i64;
          }
          *((_QWORD *)v30 + 6) = v24;
          *((_DWORD *)v30 + 14) = 2;
          *((_QWORD *)v30 + 4) = 0i64;
          *((_QWORD *)v30 + 5) = 0i64;
          *((_QWORD *)v30 + 8) = &Render::gTaskFunctionDeclData_CullManager_RasterizeZBuffer;
          if ( v32 )
            v36 = v32->mAddress;
          else
            v36 = 0i64;
          *((_QWORD *)v30 + 9) = v36;
          *((_QWORD *)v30 + 10) = v33;
          *((_QWORD *)v30 + 11) = v34;
          *((_QWORD *)v30 + 12) = v14;
          *((_QWORD *)v30 + 13) = v28;
          *((_QWORD *)v30 + 14) = (char *)v4 + 1680;
          *((_QWORD *)v30 + 15) = 0i64;
          if ( v35 )
          {
            *((_DWORD *)v30 + 14) = 130;
            *((_DWORD *)v30 + 12) = 0;
          }
        }
        v37 = v27->mNode.mPrev;
        v37->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v30;
        *(_QWORD *)v30 = v37;
        *((_QWORD *)v30 + 1) = v27;
        v27->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)v30;
        ++v24->mNumTasks;
        *((_DWORD *)v30 + 14) &= 0xFFFFFFF0;
        --v8;
      }
      while ( v8 );
      LODWORD(v3) = v74;
      v6 = (char *)v73;
    }
    UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v24, dependenta);
    UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v24, v4->mPrevCullingTask);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v24);
    v38 = v72;
    v39 = v72->mOBuffer0;
    v40 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
    v10 = (UFG::qTask *)v40;
    if ( v40 )
    {
      *(_QWORD *)v40 = v40;
      *((_QWORD *)v40 + 1) = v40;
      v41 = v40 + 16;
      *v41 = v41;
      v41[1] = v41;
      v42 = Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap.mSpuElf;
      v43 = Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap.mTaskFunctionSPU;
      v44 = Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap.mTaskFunctionPPU;
      v45 = Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap.mTaskFunctionOffload;
      if ( !Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap.mCurrentSPUEnabled )
      {
        v42 = 0i64;
        v43 = 0i64;
        v45 = 0i64;
      }
      v10->mTaskGroup = 0i64;
      v10->mFlags = 2;
      v10->mSyncVars.i64 = 0i64;
      v10->mSyncVars.v.mDependents = 0i64;
      v10->mFunctionDeclData = &Render::gTaskFunctionDeclData_CullManager_CreateOcclusionMap;
      if ( v42 )
        v46 = v42->mAddress;
      else
        v46 = 0i64;
      v10->mSPUElfAddress = v46;
      v10->mSPUFunction = v43;
      v10->mPPUFunction = v44;
      v10->mParam0 = v14;
      v10->mParam1 = v39;
      v10->mParam2 = 0i64;
      v10->mParam3 = 0i64;
      if ( v45 )
      {
        v10->mFlags = 130;
        v10->mOffloadThread = 0;
      }
    }
    v47 = UFG::gTaskManager.mSingleFrameTasks;
    v48 = UFG::gTaskManager.mSingleFrameTasks->mNode.mPrev;
    v48->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v10->mPrev;
    v10->mPrev = v48;
    v10->mNext = &v47->mNode;
    v47->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v10->mPrev;
    v10->mFlags &= 0xFFFFFFF0;
    UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v10, v24);
    UFG::qTaskManager::Queue(&UFG::gTaskManager, v10);
  }
  else
  {
    v38 = &v4->mOcclusionMaps[v3];
  }
  v49 = UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x98u, 0x10u);
  v50 = v49;
  if ( !v49 )
    return 0;
  *((_DWORD *)v49 + 19) = -1;
  *((_WORD *)v49 + 37) = v3;
  *((_DWORD *)v49 + 20) = *((_DWORD *)v6 + 18);
  *((_DWORD *)v49 + 21) = *((_DWORD *)v6 + 19);
  v51 = *((_OWORD *)v6 + 1);
  v52 = *((_OWORD *)v6 + 2);
  v53 = *((_OWORD *)v6 + 3);
  *(_OWORD *)v49 = *(_OWORD *)v6;
  *((_OWORD *)v49 + 1) = v51;
  *((_OWORD *)v49 + 2) = v52;
  *((_OWORD *)v49 + 3) = v53;
  *((_DWORD *)v49 + 22) = *((_DWORD *)v6 + 16);
  *((_DWORD *)v49 + 23) = *((_DWORD *)v6 + 17);
  *((_QWORD *)v49 + 8) = v38->mOBuffer0;
  *((_WORD *)v49 + 36) = 128;
  v54 = Illusion::gEngine.FrameMemory;
  *((_QWORD *)v49 + 12) = Illusion::gEngine.FrameMemory;
  v55 = UFG::qLinearAllocator::Malloc(v54, 0x20u, 0x20u);
  *((_QWORD *)v50 + 13) = v55;
  *(_DWORD *)v55 = -1;
  *((_DWORD *)v50 + 34) = *((_DWORD *)v6 + 22);
  *((_DWORD *)v50 + 35) = *((_DWORD *)v6 + 23);
  *((_DWORD *)v50 + 36) = *((_DWORD *)v6 + 24);
  v56 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
  v57 = (UFG::qTaskGroup *)v56;
  if ( v56 )
    UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v56, "CullView");
  v58 = UFG::gTaskManager.mSingleFrameTaskGroups;
  v59 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
  v59->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v57->mPrev;
  v57->mPrev = v59;
  v57->mNext = &v58->mNode;
  v58->mNode.mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)&v57->mPrev;
  UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v57, v10);
  UFG::qTaskManager::AddDependent(&UFG::gTaskManager, v57, v4->mPrevCullingTask);
  if ( v76 > 0 )
  {
    v60 = &v57->mTasks;
    v61 = (unsigned int)v76;
    do
    {
      v62 = v4->mCullLayers[0].mNode.mNext;
      v63 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
      v64 = v63;
      if ( v63 )
      {
        *(_QWORD *)v63 = v63;
        *((_QWORD *)v63 + 1) = v63;
        v65 = v63 + 16;
        *v65 = v65;
        v65[1] = v65;
        v66 = Render::gTaskFunctionDeclData_CullManager_CullBucketTask.mSpuElf;
        v67 = Render::gTaskFunctionDeclData_CullManager_CullBucketTask.mTaskFunctionSPU;
        v68 = Render::gTaskFunctionDeclData_CullManager_CullBucketTask.mTaskFunctionPPU;
        v69 = Render::gTaskFunctionDeclData_CullManager_CullBucketTask.mTaskFunctionOffload;
        if ( !Render::gTaskFunctionDeclData_CullManager_CullBucketTask.mCurrentSPUEnabled )
        {
          v66 = 0i64;
          v67 = 0i64;
          v69 = 0i64;
        }
        *((_QWORD *)v64 + 6) = v57;
        *((_DWORD *)v64 + 14) = 2;
        *((_QWORD *)v64 + 4) = 0i64;
        *((_QWORD *)v64 + 5) = 0i64;
        *((_QWORD *)v64 + 8) = &Render::gTaskFunctionDeclData_CullManager_CullBucketTask;
        if ( v66 )
          v70 = v66->mAddress;
        else
          v70 = 0i64;
        *((_QWORD *)v64 + 9) = v70;
        *((_QWORD *)v64 + 10) = v67;
        *((_QWORD *)v64 + 11) = v68;
        *((_QWORD *)v64 + 12) = v50;
        *((_QWORD *)v64 + 13) = v62;
        *((_QWORD *)v64 + 14) = (char *)v4 + 1664;
        *((_QWORD *)v64 + 15) = 0i64;
        if ( v69 )
        {
          *((_DWORD *)v64 + 14) = 130;
          *((_DWORD *)v64 + 12) = 0;
        }
      }
      v71 = v60->mNode.mPrev;
      v71->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)v64;
      *(_QWORD *)v64 = v71;
      *((_QWORD *)v64 + 1) = v60;
      v60->mNode.mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)v64;
      ++v57->mNumTasks;
      *((_DWORD *)v64 + 14) &= 0xFFFFFFF0;
      --v61;
    }
    while ( v61 );
    LODWORD(v3) = v74;
  }
  UFG::qTaskManager::Queue(&UFG::gTaskManager, v57);
  v4->mFinalTasks[(signed int)v3] = v57;
  v4->mPrevCullingTask = v57;
  return 1;
}

// File Line: 1603
// RVA: 0x26D10
void __fastcall CullManager::EndView(CullManager *this, __int64 view_index)
{
  if ( (_DWORD)view_index != -1 )
  {
    view_index = (signed int)view_index;
    if ( this->mViewSlots[(signed int)view_index] == 2 )
      UFG::qTaskManager::Sync(&UFG::gTaskManager, this->mFinalTasks[view_index]);
  }
}

