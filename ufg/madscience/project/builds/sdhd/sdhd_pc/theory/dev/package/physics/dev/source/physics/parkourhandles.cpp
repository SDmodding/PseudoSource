// File Line: 82
// RVA: 0x98F00
void __fastcall UFG::ParkourInstanceInventory::ParkourInstanceInventory(UFG::ParkourInstanceInventory *this)
{
  UFG::ParkourInstanceInventory *v1; // rbx

  v1 = this;
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&this->vfptr,
    "ParkourInstanceInventory",
    0x98CD09F8,
    0xC31501A5,
    0,
    0);
  v1->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::ParkourInstanceInventory::`vftable';
}

// File Line: 88
// RVA: 0x9FD80
void __fastcall UFG::ParkourInstanceInventory::Add(UFG::ParkourInstanceInventory *this, UFG::qResourceData *res)
{
  UFG::qResourceData *v2; // rbx
  UFG::ParkourInstanceInventory *v3; // rdi

  v2 = res;
  v3 = this;
  if ( res )
    UFG::ParkourInstanceResource::ParkourInstanceResource((UFG::ParkourInstanceResource *)res);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 100
// RVA: 0xAF590
void __fastcall UFG::ParkourInstanceInventory::Remove(UFG::ParkourInstanceInventory *this, UFG::qResourceData *resource_data)
{
  UFG::ParkourInstanceResource *v2; // rbx

  v2 = (UFG::ParkourInstanceResource *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  UFG::ParkourInstanceResource::~ParkourInstanceResource(v2);
}

// File Line: 178
// RVA: 0x98DF0
void __fastcall UFG::ParkourHandle::ParkourHandle(UFG::ParkourHandle *this, unsigned __int64 uid, UFG::qVector3 *_v0, UFG::qVector3 *_v1, unsigned int _flags)
{
  UFG::qVector3 *v5; // rdi
  UFG::qVector3 *v6; // rbx
  unsigned __int64 v7; // rsi
  UFG::ParkourHandle *v8; // r14
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v9; // rax
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v14; // [rsp+58h] [rbp+10h]
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v15; // [rsp+58h] [rbp+10h]
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v16; // [rsp+58h] [rbp+10h]

  v5 = _v1;
  v6 = _v0;
  v7 = uid;
  v8 = this;
  v9 = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)&this->mPrev;
  v9->mPrev = v9;
  v9->mNext = v9;
  UFG::qSafePointerNode<UFG::ParkourHandle>::qSafePointerNode<UFG::ParkourHandle>((UFG::qSafePointerNode<UFG::ParkourHandle> *)&this->vfptr);
  v8->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::ParkourHandle::`vftable';
  v14 = &v8->mSimObject;
  v14->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v14->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v14->mPrev;
  v8->mSimObject.m_pPointer = 0i64;
  v15 = &v8->mCachedLeftNeighbor;
  v15->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  v15->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v15->mPrev;
  v8->mCachedLeftNeighbor.m_pPointer = 0i64;
  v16 = &v8->mCachedRightNeighbor;
  v16->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v16->mPrev;
  v16->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v16->mPrev;
  v8->mCachedRightNeighbor.m_pPointer = 0i64;
  v10 = v6->y;
  v11 = v6->z;
  v8->v0.x = v6->x;
  v8->v0.y = v10;
  v8->v0.z = v11;
  v12 = v5->y;
  v13 = v5->z;
  v8->v1.x = v5->x;
  v8->v1.y = v12;
  v8->v1.z = v13;
  v8->mUid = v7;
  v8->mFramesUntilDeleted = 10;
  v8->mFlags = _flags;
  *((_DWORD *)v8 + 38) = *((_DWORD *)v8 + 38) & 0xFFFFFFE2 | 2;
}

// File Line: 187
// RVA: 0x9C7D0
void __fastcall UFG::ParkourHandle::~ParkourHandle(UFG::ParkourHandle *this)
{
  UFG::ParkourHandle *v1; // rdi
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v2; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v3; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v4; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v7; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *v12; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v19; // rdx
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v20; // rcx
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v21; // rax

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::ParkourHandle::`vftable';
  v2 = &this->mCachedRightNeighbor;
  if ( this->mCachedRightNeighbor.m_pPointer )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  }
  v2->m_pPointer = 0i64;
  v5 = v2->mPrev;
  v6 = v2->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v2->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v2->mPrev;
  v7 = &v1->mCachedLeftNeighbor;
  if ( v1->mCachedLeftNeighbor.m_pPointer )
  {
    v8 = v7->mPrev;
    v9 = v1->mCachedLeftNeighbor.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v7->mPrev;
    v1->mCachedLeftNeighbor.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1->mCachedLeftNeighbor.mPrev;
  }
  v1->mCachedLeftNeighbor.m_pPointer = 0i64;
  v10 = v7->mPrev;
  v11 = v1->mCachedLeftNeighbor.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v7->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v7->mPrev;
  v1->mCachedLeftNeighbor.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *)&v1->mCachedLeftNeighbor.mPrev;
  v12 = &v1->mSimObject;
  if ( v1->mSimObject.m_pPointer )
  {
    v13 = v12->mPrev;
    v14 = v1->mSimObject.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
    v1->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
  }
  v1->mSimObject.m_pPointer = 0i64;
  v15 = v12->mPrev;
  v16 = v1->mSimObject.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  v12->mPrev = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v12->mPrev;
  v1->mSimObject.mNext = (UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *)&v1->mSimObject.mPrev;
  v1->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::ParkourHandle>::`vftable';
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull((UFG::qSafePointerNode<UFG::ParkourHandle> *)&v1->vfptr);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&v1->m_SafePointerList);
  v17 = v1->m_SafePointerList.mNode.mPrev;
  v18 = v1->m_SafePointerList.mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  v1->m_SafePointerList.mNode.mPrev = &v1->m_SafePointerList.mNode;
  v1->m_SafePointerList.mNode.mNext = &v1->m_SafePointerList.mNode;
  v19 = (UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *)&v1->mPrev;
  v20 = v1->mPrev;
  v21 = v1->mNext;
  v20->mNext = v21;
  v21->mPrev = v20;
  v19->mPrev = v19;
  v19->mNext = v19;
}

// File Line: 196
// RVA: 0xACC80
bool __fastcall UFG::ParkourHandle::IsEnabled(UFG::ParkourHandle *this)
{
  return (*((_DWORD *)this + 38) >> 1) & 1;
}

// File Line: 256
// RVA: 0xAB220
UFG::qVector3 *__fastcall UFG::ParkourHandle::GetPosition(UFG::ParkourHandle *this, UFG::qVector3 *result)
{
  UFG::qVector3 *v2; // rax
  float v3; // xmm2_4
  float v4; // xmm3_4

  v2 = result;
  v3 = (float)(this->v0.y + this->v1.y) * 0.5;
  v4 = this->v0.z + this->v1.z;
  result->x = (float)(this->v0.x + this->v1.x) * 0.5;
  result->y = v3;
  result->z = v4 * 0.5;
  return v2;
}

// File Line: 263
// RVA: 0xAA0C0
float __fastcall UFG::ParkourHandle::GetHalfLength(UFG::ParkourHandle *this)
{
  __m128 v1; // xmm2
  float v2; // xmm0_4

  v1 = (__m128)LODWORD(this->v1.y);
  v2 = this->v1.z - this->v0.z;
  v1.m128_f32[0] = (float)((float)((float)(v1.m128_f32[0] - this->v0.y) * (float)(v1.m128_f32[0] - this->v0.y))
                         + (float)((float)(this->v1.x - this->v0.x) * (float)(this->v1.x - this->v0.x)))
                 + (float)(v2 * v2);
  return COERCE_FLOAT(_mm_sqrt_ps(v1)) * 0.5;
}

// File Line: 270
// RVA: 0xA95F0
UFG::qVector3 *__fastcall UFG::ParkourHandle::GetAxis(UFG::ParkourHandle *this, UFG::qVector3 *result)
{
  float v2; // xmm2_4
  float v3; // xmm5_4
  float v4; // xmm3_4
  __m128 v5; // xmm6
  __m128 v6; // xmm4
  UFG::qVector3 *v7; // rax

  v2 = 0.0;
  v5 = (__m128)LODWORD(this->v1.y);
  v3 = this->v1.x - this->v0.x;
  v4 = this->v1.z - this->v0.z;
  v5.m128_f32[0] = v5.m128_f32[0] - this->v0.y;
  v6 = v5;
  v6.m128_f32[0] = (float)((float)(v5.m128_f32[0] * v5.m128_f32[0]) + (float)(v3 * v3)) + (float)(v4 * v4);
  if ( v6.m128_f32[0] != 0.0 )
    v2 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v6));
  v7 = result;
  result->z = v4 * v2;
  result->x = v2 * v3;
  result->y = v2 * v5.m128_f32[0];
  return v7;
}

// File Line: 276
// RVA: 0xAA7D0
void __fastcall UFG::ParkourHandle::GetLayout(UFG::ParkourHandle *this, UFG::qVector3 *position, UFG::qVector3 *axis, float *halfLength)
{
  float v4; // xmm2_4
  float v5; // xmm1_4
  __m128 v6; // xmm2
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm4_4
  __m128 v12; // xmm3
  float v13; // xmm5_4
  __m128 v14; // xmm6

  v4 = (float)(this->v0.x + this->v1.x) * 0.5;
  v5 = (float)(this->v1.y + this->v0.y) * 0.5;
  position->z = (float)(this->v0.z + this->v1.z) * 0.5;
  position->x = v4;
  position->y = v5;
  v6 = (__m128)LODWORD(this->v1.y);
  v7 = this->v1.z - this->v0.z;
  v8 = this->v1.x - this->v0.x;
  v6.m128_f32[0] = (float)((float)((float)(v6.m128_f32[0] - this->v0.y) * (float)(v6.m128_f32[0] - this->v0.y))
                         + (float)(v8 * v8))
                 + (float)(v7 * v7);
  LODWORD(v9) = (unsigned __int128)_mm_sqrt_ps(v6);
  v10 = 0.0;
  *halfLength = v9 * 0.5;
  v12 = (__m128)LODWORD(this->v1.y);
  v11 = this->v1.x - this->v0.x;
  v12.m128_f32[0] = v12.m128_f32[0] - this->v0.y;
  v14 = v12;
  v13 = this->v1.z - this->v0.z;
  v14.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
  if ( v14.m128_f32[0] != 0.0 )
    v10 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
  axis->x = v11 * v10;
  axis->y = v12.m128_f32[0] * v10;
  axis->z = v13 * v10;
}

// File Line: 285
// RVA: 0xACD60
bool __fastcall UFG::ParkourHandle::IsType(UFG::ParkourHandle *this, unsigned int flags)
{
  return (unsigned __int16)(this->mFlags & flags) != 0;
}

// File Line: 292
// RVA: 0xAA0B0
__int64 __fastcall UFG::ParkourHandle::GetFlags(UFG::ParkourHandle *this)
{
  return this->mFlags;
}

// File Line: 387
// RVA: 0xAAB40
char __fastcall UFG::ParkourHandle::GetNormal(UFG::ParkourHandle *this, UFG::qVector3 *out)
{
  __m128 v2; // xmm2
  __m128 v3; // xmm5
  float v4; // xmm6_4
  __m128 v5; // xmm4
  float v6; // xmm4_4
  float v7; // xmm4_4
  __m128 v8; // xmm1
  float v9; // xmm0_4
  char result; // al

  v3 = (__m128)LODWORD(this->v1.x);
  v2 = 0i64;
  v3.m128_f32[0] = v3.m128_f32[0] - this->v0.x;
  v5 = v3;
  v4 = this->v1.y - this->v0.y;
  v5.m128_f32[0] = (float)((float)(v3.m128_f32[0] * v3.m128_f32[0]) + (float)(v4 * v4))
                 + (float)((float)(this->v1.z - this->v0.z) * (float)(this->v1.z - this->v0.z));
  if ( v5.m128_f32[0] != 0.0 )
  {
    v2 = (__m128)(unsigned int)FLOAT_1_0;
    v2.m128_f32[0] = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v5));
  }
  v6 = v2.m128_f32[0];
  v2.m128_f32[0] = v2.m128_f32[0] * v4;
  v7 = v6 * v3.m128_f32[0];
  v8 = v2;
  v8.m128_f32[0] = (float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(v7 * v7);
  if ( v8.m128_f32[0] <= 0.001 )
    return 0;
  LODWORD(v9) = (unsigned __int128)_mm_sqrt_ps(v8);
  out->z = 0.0;
  result = 1;
  out->x = (float)(1.0 / v9) * v2.m128_f32[0];
  LODWORD(out->y) = COERCE_UNSIGNED_INT((float)(1.0 / v9) * v7) ^ _xmm[0];
  return result;
}

// File Line: 408
// RVA: 0xA9E70
void __fastcall UFG::ParkourHandle::GetEndpoints(UFG::ParkourHandle *this, UFG::qVector3 *p0, UFG::qVector3 *p1)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  v3 = this->v0.y;
  v4 = this->v0.z;
  p0->x = this->v0.x;
  p0->y = v3;
  p0->z = v4;
  v5 = this->v1.y;
  v6 = this->v1.z;
  p1->x = this->v1.x;
  p1->y = v5;
  p1->z = v6;
}

// File Line: 424
// RVA: 0xA9AD0
float __fastcall UFG::ParkourHandle::GetDropoffDistance(UFG::ParkourHandle *this, UFG::qVector3 *pointAlongHandle, float radius)
{
  UFG::qVector3 *v3; // rbx
  float v4; // xmm6_4
  __m128 v5; // xmm9
  __m128 v6; // xmm8
  __m128 v7; // xmm7
  __m128 v8; // xmm10
  UFG::BasePhysicsSystem *v10; // rbx
  __m128 v11; // xmm6
  __m128 v12; // xmm10
  hkpWorld *v13; // rdi
  _BOOL8 v14; // r8
  __m128 v15; // xmm2
  hkpShapePhantom *v16; // rcx
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v17; // rcx
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *v18; // rax
  UFG::ShapeCasterCollector v19; // [rsp+30h] [rbp-B8h]
  __m128 v20; // [rsp+60h] [rbp-88h]
  void **v21; // [rsp+70h] [rbp-78h]
  __m128 v22; // [rsp+78h] [rbp-70h]
  __int64 v23; // [rsp+88h] [rbp-60h]
  __m128 v24; // [rsp+B8h] [rbp-30h]
  int v25; // [rsp+C8h] [rbp-20h]
  int v26; // [rsp+CCh] [rbp-1Ch]
  __int64 v27; // [rsp+D8h] [rbp-10h]
  UFG::RayCastData data; // [rsp+E8h] [rbp+0h]
  UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *vars0; // [rsp+250h] [rbp+168h]

  v27 = -2i64;
  v3 = pointAlongHandle;
  v4 = FLOAT_5_0;
  UFG::ParkourHandle::GetNormal(this, (UFG::qVector3 *)&v20);
  v5 = (__m128)v20.m128_u32[2];
  v6 = (__m128)v20.m128_u32[1];
  v7 = (__m128)v20.m128_u32[0];
  v5.m128_f32[0] = (float)(v20.m128_f32[2] * 0.30000001) + v3->z;
  v6.m128_f32[0] = (float)(v20.m128_f32[1] * 0.30000001) + v3->y;
  v7.m128_f32[0] = (float)(v20.m128_f32[0] * 0.30000001) + v3->x;
  v8 = v5;
  v8.m128_f32[0] = v5.m128_f32[0] - 5.0;
  if ( radius == 0.0 )
  {
    data.mInput.m_userData = 0i64;
    LODWORD(data.mOutput.m_hitFraction) = (_DWORD)FLOAT_1_0;
    data.mOutput.m_extraInfo = -1;
    data.mOutput.m_shapeKeyIndex = 0;
    data.mOutput.m_shapeKeys[0] = -1;
    data.mOutput.m_rootCollidable = 0i64;
    data.mDebugName = 0i64;
    data.mCollisionModelName.mUID = -1;
    data.mInput.m_from.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v7, v5), _mm_unpacklo_ps(v6, (__m128)0i64));
    data.mInput.m_to.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v7, v8), _mm_unpacklo_ps(v6, (__m128)0i64));
    data.mInput.m_filterInfo = 12;
    data.mInput.m_enableShapeCollectionFilter.m_bool = 1;
    data.hit = 0;
    data.mHavokRigidBody = 0i64;
    data.mHavokPhantom = 0i64;
    if ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
      return data.t * 5.0;
  }
  else
  {
    UFG::ShapeCasterCollector::ShapeCasterCollector(&v19, radius, 0xCu, 0);
    v10 = UFG::BasePhysicsSystem::mInstance;
    v11 = _mm_unpacklo_ps(_mm_unpacklo_ps(v7, v5), _mm_unpacklo_ps(v6, (__m128)(unsigned int)FLOAT_1_0));
    v12 = _mm_unpacklo_ps(_mm_unpacklo_ps(v7, v8), _mm_unpacklo_ps(v6, (__m128)(unsigned int)FLOAT_1_0));
    UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v19.mHitList);
    v13 = v10->mWorld;
    if ( v13 )
    {
      if ( !v19.mPhantom->m_world )
        hkpWorld::addPhantom(v13, (hkpPhantom *)&v19.mPhantom->vfptr);
      v25 = 872415232;
      v26 = 872415232;
      v20 = v11;
      v24 = v12;
      v22.m128_i32[0] = 2139095022;
      v21 = &hkpClosestCdPointCollector::`vftable';
      v23 = 0i64;
      v22 = _mm_shuffle_ps(v22, _mm_unpackhi_ps(v22, (__m128)xmmword_141A712A0), 196);
      v22.m128_i32[0] = 2139095022;
      ((void (__fastcall *)(hkpShapePhantom *, __m128 *, __m128 *, void ***, void ***))v19.mPhantom->vfptr[7].__first_virtual_table_function__)(
        v19.mPhantom,
        &v20,
        &v24,
        &v21,
        &v21);
      if ( v23 )
      {
        LOBYTE(v14) = 1;
        v19.vfptr->AddHit(&v19, (hkpRootCdPoint *)&v20.m128_u16[4], v14);
      }
      v21 = &hkpCdPointCollector::`vftable';
      hkpWorld::removePhantom(v13, (hkpPhantom *)&v19.mPhantom->vfptr);
    }
    v15 = (__m128)LODWORD(v19.mHitList.mNode.mNext[1].mPrev);
    v15.m128_f32[0] = (float)((float)((float)(v15.m128_f32[0] - v7.m128_f32[0])
                                    * (float)(v15.m128_f32[0] - v7.m128_f32[0]))
                            + (float)((float)(*((float *)&v19.mHitList.mNode.mNext[1].mPrev + 1) - v6.m128_f32[0])
                                    * (float)(*((float *)&v19.mHitList.mNode.mNext[1].mPrev + 1) - v6.m128_f32[0])))
                    + (float)((float)(*(float *)&v19.mHitList.mNode.mNext[1].mNext - v5.m128_f32[0])
                            * (float)(*(float *)&v19.mHitList.mNode.mNext[1].mNext - v5.m128_f32[0]));
    LODWORD(v4) = (unsigned __int128)_mm_sqrt_ps(v15);
    v19.vfptr = (UFG::ShapeCasterCollectorVtbl *)&UFG::ShapeCasterCollector::`vftable';
    v16 = v19.mPhantom;
    if ( v19.mPhantom )
    {
      if ( v19.mPhantom->m_world )
      {
        hkpWorld::removePhantom(v19.mPhantom->m_world, (hkpPhantom *)&v19.mPhantom->vfptr);
        v16 = v19.mPhantom;
      }
      hkReferencedObject::removeReference((hkReferencedObject *)&v16->vfptr);
      v19.mPhantom = 0i64;
    }
    UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v19.mHitList);
    vars0 = &v19.mHitList;
    UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v19.mHitList);
    v17 = v19.mHitList.mNode.mPrev;
    v18 = v19.mHitList.mNode.mNext;
    v19.mHitList.mNode.mPrev->mNext = v19.mHitList.mNode.mNext;
    v18->mPrev = v17;
    v19.mHitList.mNode.mPrev = &v19.mHitList.mNode;
    v19.mHitList.mNode.mNext = &v19.mHitList.mNode;
  }
  return v4;
}

// File Line: 470
// RVA: 0xAB370
UFG::qVector3 *__fastcall UFG::ParkourHandle::GetShortestRayTo(UFG::ParkourHandle *this, UFG::qVector3 *result, UFG::qVector3 *position)
{
  float v3; // xmm2_4
  float v4; // xmm11_4
  float v5; // xmm10_4
  float v6; // xmm12_4
  __m128 v7; // xmm4
  __m128 v8; // xmm5
  float v9; // xmm6_4
  __m128 v10; // xmm3
  float v11; // xmm7_4
  float v12; // xmm8_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm9_4
  float v17; // xmm4_4
  float v18; // xmm9_4
  int v19; // xmm3_4
  UFG::qVector3 *v20; // rax

  v8 = (__m128)LODWORD(this->v1.x);
  v7 = (__m128)LODWORD(this->v1.y);
  v3 = 0.0;
  v4 = this->v0.y;
  v5 = this->v0.x;
  v6 = this->v0.z;
  v7.m128_f32[0] = v7.m128_f32[0] - v4;
  v8.m128_f32[0] = v8.m128_f32[0] - v5;
  v9 = this->v1.z - v6;
  v10 = v8;
  v10.m128_f32[0] = (float)((float)(v8.m128_f32[0] * v8.m128_f32[0]) + (float)(v7.m128_f32[0] * v7.m128_f32[0]))
                  + (float)(v9 * v9);
  if ( v10.m128_f32[0] != 0.0 )
    v3 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v10));
  v11 = v8.m128_f32[0] * v3;
  v12 = v7.m128_f32[0] * v3;
  v13 = v3 * v9;
  v7.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v8.m128_f32[0] * v8.m128_f32[0]))
                 + (float)(v9 * v9);
  v14 = position->y - (float)((float)(v4 + this->v1.y) * 0.5);
  v15 = position->z - (float)((float)(v6 + this->v1.z) * 0.5);
  LODWORD(v16) = (unsigned __int128)_mm_sqrt_ps(v7);
  v17 = position->x - (float)((float)(v5 + this->v1.x) * 0.5);
  v18 = v16 * 0.5;
  *(float *)&v19 = (float)((float)(v14 * v12) + (float)(v17 * v11)) + (float)(v15 * v13);
  if ( *(float *)&v19 <= COERCE_FLOAT(LODWORD(v18) ^ _xmm[0]) )
    v19 = LODWORD(v18) ^ _xmm[0];
  if ( *(float *)&v19 >= v18 )
    *(float *)&v19 = v18;
  v20 = result;
  result->z = v15 - (float)(v13 * *(float *)&v19);
  result->x = v17 - (float)(v11 * *(float *)&v19);
  result->y = v14 - (float)(v12 * *(float *)&v19);
  return v20;
}

// File Line: 480
// RVA: 0xA97A0
UFG::qVector3 *__fastcall UFG::ParkourHandle::GetClosestPointOnHandle(UFG::ParkourHandle *this, UFG::qVector3 *result, UFG::qVector3 *position)
{
  UFG::qVector3 *v3; // rdi
  UFG::qVector3 *v4; // rbx
  UFG::qVector3 *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm0_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-18h]

  v3 = result;
  v4 = position;
  UFG::ParkourHandle::GetShortestRayTo(this, &resulta, position);
  v5 = v3;
  v6 = v4->y - resulta.y;
  v3->x = v4->x - resulta.x;
  v7 = v4->z;
  v3->y = v6;
  v3->z = v7 - resulta.z;
  return v5;
}

// File Line: 490
// RVA: 0xA9A90
float __fastcall UFG::ParkourHandle::GetDistanceTo(UFG::ParkourHandle *this, UFG::qVector3 *position)
{
  __m128 v2; // xmm2
  float v3; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-18h]

  UFG::ParkourHandle::GetShortestRayTo(this, &result, position);
  v2 = (__m128)LODWORD(result.x);
  v2.m128_f32[0] = (float)((float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(result.y * result.y))
                 + (float)(result.z * result.z);
  LODWORD(v3) = (unsigned __int128)_mm_sqrt_ps(v2);
  return v3;
}

// File Line: 498
// RVA: 0xACC30
bool __fastcall UFG::ParkourHandle::IsAttachedToVehicle(UFG::ParkourHandle *this)
{
  UFG::SimObject *v1; // rax

  v1 = this->mSimObject.m_pPointer;
  return v1 && (v1->m_Flags & 0x8000u) != 0;
}

// File Line: 583
// RVA: 0xA2FB0
void __fastcall UFG::ParkourHandle::CompareParkourHandles(UFG::ParkourHandle *this, unsigned int checkTypes, UFG::qVector3 *position, UFG::qVector3 *orientation, const float relativeAngle, const float bufferZone, const float distanceXYMin, const float distanceXYMax, const float distanceZMin, const float distanceZMax, UFG::qVector3 *contactPosition, UFG::ParkourHandle **closestParkHandle, float *currentDistanceTo, bool *currentInSegment)
{
  int v14; // eax
  UFG::qVector3 *v15; // r14
  UFG::ParkourHandle *v16; // rdi
  __m128 v17; // xmm2
  float v18; // xmm1_4
  float v19; // xmm0_4
  __m128 v20; // xmm11
  __m128 v21; // xmm4
  float v22; // xmm5_4
  __m128 v23; // xmm12
  float v24; // xmm5_4
  float v25; // xmm13_4
  __m128 v26; // xmm2
  float v27; // xmm8_4
  float v28; // xmm13_4
  float v29; // xmm8_4
  float v30; // xmm6_4
  float v31; // xmm6_4
  __m128 v32; // xmm2
  float v33; // xmm1_4
  float v34; // xmm12_4
  bool v35; // bl
  UFG::ParkourHandle *v36; // rax
  float v37; // xmm9_4
  float v38; // xmm13_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  __m128 v41; // xmm15
  float v42; // xmm3_4
  float v43; // xmm6_4
  __m128 v44; // xmm2
  float v45; // xmm10_4
  float v46; // xmm3_4
  float v47; // xmm6_4
  char v48; // si
  __m128 v49; // xmm1
  __m128 v50; // xmm0
  __m128 v51; // xmm8
  float v52; // xmm9_4
  float v53; // xmm15_4
  float v54; // xmm9_4
  float v55; // xmm15_4
  float v56; // xmm0_4
  float v57; // xmm4_4
  __m128 v58; // xmm3
  __m128 v59; // xmm2
  float v60; // xmm1_4
  float v61; // xmm3_4
  __m128 v62; // xmm5
  float v63; // xmm4_4
  __m128 v64; // xmm0
  float v65; // xmm14_4
  float v66; // xmm3_4
  float v67; // xmm4_4
  bool v68; // al
  float v69; // xmm0_4
  float v70; // xmm0_4
  float v71; // [rsp+20h] [rbp-D9h]
  float v72; // [rsp+24h] [rbp-D5h]
  float v73; // [rsp+28h] [rbp-D1h]
  UFG::qVector3 v74; // [rsp+40h] [rbp-B9h]
  UFG::qVector3 dest; // [rsp+50h] [rbp-A9h]
  float v76; // [rsp+120h] [rbp+27h]

  v14 = this->mFlags;
  v15 = orientation;
  v16 = this;
  if ( (!(checkTypes & 1) || !(v14 & 1))
    && (!(checkTypes & 4) || !(v14 & 4))
    && (!(checkTypes & 8) || !(v14 & 8))
    && (!(checkTypes & 2) || !(v14 & 2))
    && (!(checkTypes & 0x10) || !(v14 & 0x10))
    && (!(checkTypes & 0x20) || !(v14 & 0x20))
    && (!(checkTypes & 2) || !(v14 & 2))
    && (!_bittest((const signed int *)&checkTypes, 8u) || !_bittest(&v14, 8u))
    && (!(checkTypes & 0x40) || !(v14 & 0x40))
    && ((checkTypes & 0x80u) == 0 || (v14 & 0x80u) == 0) )
  {
    return;
  }
  v17 = (__m128)LODWORD(this->v0.x);
  v18 = this->v0.y;
  v19 = this->v0.z;
  v21 = v17;
  v20 = (__m128)LODWORD(this->v1.x);
  v21.m128_f32[0] = v17.m128_f32[0] + v20.m128_f32[0];
  v20.m128_f32[0] = v20.m128_f32[0] - v17.m128_f32[0];
  v21.m128_f32[0] = v21.m128_f32[0] * 0.5;
  v23 = (__m128)LODWORD(this->v1.y);
  v22 = v18 + v23.m128_f32[0];
  v23.m128_f32[0] = v23.m128_f32[0] - v18;
  v24 = v22 * 0.5;
  v25 = this->v1.z;
  v26 = v23;
  v27 = v19 + v25;
  v28 = v25 - v19;
  v29 = v27 * 0.5;
  v26.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v20.m128_f32[0] * v20.m128_f32[0]))
                  + (float)(v28 * v28);
  LODWORD(v30) = (unsigned __int128)_mm_sqrt_ps(v26);
  v32 = v23;
  v31 = v30 * 0.5;
  v32.m128_f32[0] = (float)((float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v20.m128_f32[0] * v20.m128_f32[0]))
                  + (float)(v28 * v28);
  if ( v32.m128_f32[0] == 0.0 )
    v33 = 0.0;
  else
    v33 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v32));
  v34 = v23.m128_f32[0] * v33;
  v20.m128_f32[0] = v20.m128_f32[0] * v33;
  v44 = v21;
  v35 = 0;
  v36 = 0i64;
  v37 = v31 * 2.0;
  v38 = v28 * v33;
  v41 = v20;
  v39 = v34 * v31;
  v40 = v38 * v31;
  v41.m128_f32[0] = v20.m128_f32[0] * v31;
  v42 = v24 - (float)(v34 * v31);
  v43 = v29 - (float)(v38 * v31);
  v44.m128_f32[0] = v21.m128_f32[0] - v41.m128_f32[0];
  v76 = v21.m128_f32[0] - v41.m128_f32[0];
  v45 = (float)((float)((float)(position->y - (float)(v24 - v39)) * v34)
              + (float)((float)(position->x - (float)(v21.m128_f32[0] - v41.m128_f32[0])) * v20.m128_f32[0]))
      + (float)((float)(position->z - (float)(v29 - v40)) * v38);
  v71 = v24 - v39;
  v72 = v29 - v40;
  if ( v45 < 0.0 )
  {
    if ( v45 <= v37 )
    {
      if ( v45 < 0.0 )
      {
        v36 = this->mCachedRightNeighbor.m_pPointer;
        v44 = v21;
        v42 = v24;
        v43 = v29;
      }
      goto LABEL_31;
    }
  }
  else if ( v45 <= v37 )
  {
    v44 = v20;
    v35 = 1;
    v44.m128_f32[0] = (float)(v20.m128_f32[0] * v45) + v76;
    v42 = (float)(v34 * v45) + v71;
    v43 = (float)(v38 * v45) + v72;
    goto LABEL_31;
  }
  v36 = this->mCachedLeftNeighbor.m_pPointer;
  v44 = v41;
  v42 = v39 + v24;
  v43 = v40 + v29;
  v44.m128_f32[0] = v41.m128_f32[0] + v21.m128_f32[0];
LABEL_31:
  v44.m128_f32[0] = v44.m128_f32[0] - position->x;
  v46 = v42 - position->y;
  v47 = v43 - position->z;
  v48 = 1;
  if ( !v35 )
  {
    v35 = 0;
    if ( v36 )
      v35 = 1;
  }
  if ( distanceZMin <= v47 && distanceZMax >= v47 )
  {
    v49 = v44;
    v49.m128_f32[0] = v44.m128_f32[0] * v44.m128_f32[0];
    v50 = v49;
    v50.m128_f32[0] = (float)(v44.m128_f32[0] * v44.m128_f32[0]) + (float)(v46 * v46);
    v51 = _mm_sqrt_ps(v50);
    if ( v51.m128_f32[0] > 0.000099999997 && distanceXYMin <= v51.m128_f32[0] && distanceXYMax >= v51.m128_f32[0] )
    {
      v49.m128_f32[0] = v49.m128_f32[0] + (float)(v46 * v46);
      v52 = v49.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v49));
      v53 = v52;
      v54 = v52 * v46;
      v55 = v53 * v44.m128_f32[0];
      v56 = (float)(v54 * orientation->y) + (float)(v55 * orientation->x);
      UFG::qACos(v56);
      if ( relativeAngle >= v56 )
        goto LABEL_68;
      if ( bufferZone > 0.0 )
      {
        UFG::qRotateVectorZ(&dest, v15, relativeAngle);
        UFG::qRotateVectorZ(&v74, v15, COERCE_FLOAT(LODWORD(relativeAngle) ^ _xmm[0]));
        v58 = (__m128)LODWORD(dest.z);
        v57 = (float)(dest.y * UFG::qVector3::msDirUp.z) - (float)(dest.z * UFG::qVector3::msDirUp.y);
        v58.m128_f32[0] = (float)(dest.z * UFG::qVector3::msDirUp.x) - (float)(dest.x * UFG::qVector3::msDirUp.z);
        v59 = v58;
        v59.m128_f32[0] = (float)((float)(v58.m128_f32[0] * v58.m128_f32[0]) + (float)(v57 * v57))
                        + (float)((float)((float)(dest.x * UFG::qVector3::msDirUp.y)
                                        - (float)(dest.y * UFG::qVector3::msDirUp.x))
                                * (float)((float)(dest.x * UFG::qVector3::msDirUp.y)
                                        - (float)(dest.y * UFG::qVector3::msDirUp.x)));
        if ( v59.m128_f32[0] == 0.0 )
          v60 = 0.0;
        else
          v60 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v59));
        v61 = v58.m128_f32[0] * v60;
        v73 = v57 * v60;
        v62 = (__m128)LODWORD(v74.z);
        v62.m128_f32[0] = (float)(v74.z * UFG::qVector3::msDirUp.y) - (float)(v74.y * UFG::qVector3::msDirUp.z);
        v63 = (float)(v74.x * UFG::qVector3::msDirUp.z) - (float)(v74.z * UFG::qVector3::msDirUp.x);
        v64 = v62;
        v64.m128_f32[0] = (float)((float)(v63 * v63) + (float)(v62.m128_f32[0] * v62.m128_f32[0]))
                        + (float)((float)((float)(v74.y * UFG::qVector3::msDirUp.x)
                                        - (float)(v74.x * UFG::qVector3::msDirUp.y))
                                * (float)((float)(v74.y * UFG::qVector3::msDirUp.x)
                                        - (float)(v74.x * UFG::qVector3::msDirUp.y)));
        if ( v64.m128_f32[0] == 0.0 )
          v65 = 0.0;
        else
          v65 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v64));
        v66 = (float)(v61 * v54) + (float)(v73 * v55);
        v67 = (float)((float)(v63 * v65) * v54) + (float)((float)(v62.m128_f32[0] * v65) * v55);
        v68 = (float)((float)(dest.y * v54) + (float)(dest.x * v55)) > 0.0 && v66 > 0.0 && v66 < bufferZone;
        if ( (float)((float)(v74.y * v54) + (float)(v74.x * v55)) <= 0.0 || v67 <= 0.0 || v67 >= bufferZone )
          v48 = 0;
        if ( (unsigned __int8)v48 | v68 )
        {
LABEL_68:
          if ( !UFG::ParkourHandle::GetNormal(v16, &dest)
            || (v69 = (float)(dest.y * v15->y) + (float)(dest.x * v15->x),
                UFG::qACos(v69),
                v69 > (float)(3.1415927 - relativeAngle)) )
          {
            v51.m128_f32[0] = (float)(v51.m128_f32[0] * v51.m128_f32[0]) + (float)(v47 * v47);
            LODWORD(v70) = (unsigned __int128)_mm_sqrt_ps(v51);
            if ( v35 && v70 < *currentDistanceTo )
            {
              *currentDistanceTo = v70;
              *closestParkHandle = v16;
              *currentInSegment = v35;
              if ( contactPosition )
              {
                contactPosition->x = (float)(v20.m128_f32[0] * v45) + v76;
                contactPosition->y = (float)(v34 * v45) + v71;
                contactPosition->z = (float)(v38 * v45) + v72;
              }
            }
          }
        }
      }
    }
  }
}

