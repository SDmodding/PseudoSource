// File Line: 82
// RVA: 0x98F00
void __fastcall UFG::ParkourInstanceInventory::ParkourInstanceInventory(UFG::ParkourInstanceInventory *this)
{
  UFG::qResourceInventory::qResourceInventory(this, "ParkourInstanceInventory", 0x98CD09F8, 0xC31501A5, 0, 0);
  this->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::ParkourInstanceInventory::`vftable;
}

// File Line: 88
// RVA: 0x9FD80
void __fastcall UFG::ParkourInstanceInventory::Add(
        UFG::ParkourInstanceInventory *this,
        UFG::ParkourInstanceResource *res)
{
  if ( res )
    UFG::ParkourInstanceResource::ParkourInstanceResource(res);
  UFG::qResourceInventory::Add(this, res);
}

// File Line: 100
// RVA: 0xAF590
void __fastcall UFG::ParkourInstanceInventory::Remove(
        UFG::ParkourInstanceInventory *this,
        UFG::ParkourInstanceResource *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  UFG::ParkourInstanceResource::~ParkourInstanceResource(resource_data);
}

// File Line: 178
// RVA: 0x98DF0
void __fastcall UFG::ParkourHandle::ParkourHandle(
        UFG::ParkourHandle *this,
        unsigned __int64 uid,
        UFG::qVector3 *_v0,
        UFG::qVector3 *_v1,
        unsigned __int16 _flags)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm2_4

  this->mPrev = &this->UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle>;
  this->mNext = &this->UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle>;
  UFG::qSafePointerNode<UFG::ParkourHandle>::qSafePointerNode<UFG::ParkourHandle>(this);
  this->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::ParkourHandle::`vftable;
  this->mSimObject.mPrev = &this->mSimObject;
  this->mSimObject.mNext = &this->mSimObject;
  this->mSimObject.m_pPointer = 0i64;
  this->mCachedLeftNeighbor.mPrev = &this->mCachedLeftNeighbor;
  this->mCachedLeftNeighbor.mNext = &this->mCachedLeftNeighbor;
  this->mCachedLeftNeighbor.m_pPointer = 0i64;
  this->mCachedRightNeighbor.mPrev = &this->mCachedRightNeighbor;
  this->mCachedRightNeighbor.mNext = &this->mCachedRightNeighbor;
  this->mCachedRightNeighbor.m_pPointer = 0i64;
  y = _v0->y;
  z = _v0->z;
  this->v0.x = _v0->x;
  this->v0.y = y;
  this->v0.z = z;
  v11 = _v1->y;
  v12 = _v1->z;
  this->v1.x = _v1->x;
  this->v1.y = v11;
  this->v1.z = v12;
  this->mUid = uid;
  this->mFramesUntilDeleted = 10;
  this->mFlags = _flags;
  *((_DWORD *)this + 38) = *((_DWORD *)this + 38) & 0xFFFFFFE0 | 2;
}

// File Line: 187
// RVA: 0x9C7D0
void __fastcall UFG::ParkourHandle::~ParkourHandle(UFG::ParkourHandle *this)
{
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_mCachedRightNeighbor; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mPrev; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *mNext; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v5; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v6; // rax
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p_mCachedLeftNeighbor; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v8; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v9; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v10; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v11; // rax
  UFG::qSafePointer<UFG::SimObject,UFG::SimObject> *p_mSimObject; // rdx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v13; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v14; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v15; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::SimObject>,UFG::qSafePointerNodeList> *v16; // rax
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v17; // rcx
  UFG::qNode<UFG::qSafePointerBase<UFG::ParkourHandle>,UFG::qSafePointerNodeList> *v18; // rax
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v19; // rcx
  UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle> *v20; // rax

  this->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::ParkourHandle::`vftable;
  p_mCachedRightNeighbor = &this->mCachedRightNeighbor;
  if ( this->mCachedRightNeighbor.m_pPointer )
  {
    mPrev = p_mCachedRightNeighbor->mPrev;
    mNext = p_mCachedRightNeighbor->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    p_mCachedRightNeighbor->mPrev = p_mCachedRightNeighbor;
    p_mCachedRightNeighbor->mNext = p_mCachedRightNeighbor;
  }
  p_mCachedRightNeighbor->m_pPointer = 0i64;
  v5 = p_mCachedRightNeighbor->mPrev;
  v6 = p_mCachedRightNeighbor->mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  p_mCachedRightNeighbor->mPrev = p_mCachedRightNeighbor;
  p_mCachedRightNeighbor->mNext = p_mCachedRightNeighbor;
  p_mCachedLeftNeighbor = &this->mCachedLeftNeighbor;
  if ( this->mCachedLeftNeighbor.m_pPointer )
  {
    v8 = p_mCachedLeftNeighbor->mPrev;
    v9 = this->mCachedLeftNeighbor.mNext;
    v8->mNext = v9;
    v9->mPrev = v8;
    p_mCachedLeftNeighbor->mPrev = p_mCachedLeftNeighbor;
    this->mCachedLeftNeighbor.mNext = &this->mCachedLeftNeighbor;
  }
  this->mCachedLeftNeighbor.m_pPointer = 0i64;
  v10 = p_mCachedLeftNeighbor->mPrev;
  v11 = this->mCachedLeftNeighbor.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mCachedLeftNeighbor->mPrev = p_mCachedLeftNeighbor;
  this->mCachedLeftNeighbor.mNext = &this->mCachedLeftNeighbor;
  p_mSimObject = &this->mSimObject;
  if ( this->mSimObject.m_pPointer )
  {
    v13 = p_mSimObject->mPrev;
    v14 = this->mSimObject.mNext;
    v13->mNext = v14;
    v14->mPrev = v13;
    p_mSimObject->mPrev = p_mSimObject;
    this->mSimObject.mNext = &this->mSimObject;
  }
  this->mSimObject.m_pPointer = 0i64;
  v15 = p_mSimObject->mPrev;
  v16 = this->mSimObject.mNext;
  v15->mNext = v16;
  v16->mPrev = v15;
  p_mSimObject->mPrev = p_mSimObject;
  this->mSimObject.mNext = &this->mSimObject;
  this->vfptr = (UFG::qSafePointerNode<UFG::ParkourHandle>Vtbl *)&UFG::qSafePointerNode<UFG::ParkourHandle>::`vftable;
  UFG::qSafePointerNode<UFG::DynamicCoverCorner>::SetAllPointersToNull(this);
  UFG::qList<UFG::qSafePointerBase<CanAttackConditionGroup>,UFG::qSafePointerNodeList,1,0>::DeleteNodes(&this->m_SafePointerList);
  v17 = this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev;
  v18 = this->m_SafePointerList.mNode.mNext;
  v17->mNext = v18;
  v18->mPrev = v17;
  this->m_SafePointerList.mNode.UFG::qSafePointerNode<UFG::ParkourHandle>::mPrev = &this->m_SafePointerList.mNode;
  this->m_SafePointerList.mNode.mNext = &this->m_SafePointerList.mNode;
  v19 = this->mPrev;
  v20 = this->mNext;
  v19->mNext = v20;
  v20->mPrev = v19;
  this->mPrev = &this->UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle>;
  this->mNext = &this->UFG::qNode<UFG::ParkourHandle,UFG::ParkourHandle>;
}

// File Line: 196
// RVA: 0xACC80
bool __fastcall UFG::ParkourHandle::IsEnabled(UFG::ParkourHandle *this)
{
  return (*((_DWORD *)this + 38) & 2) != 0;
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
  __m128 y_low; // xmm2
  float v2; // xmm0_4

  y_low = (__m128)LODWORD(this->v1.y);
  v2 = this->v1.z - this->v0.z;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->v0.y) * (float)(y_low.m128_f32[0] - this->v0.y))
                            + (float)((float)(this->v1.x - this->v0.x) * (float)(this->v1.x - this->v0.x)))
                    + (float)(v2 * v2);
  return _mm_sqrt_ps(y_low).m128_f32[0] * 0.5;
}

// File Line: 270
// RVA: 0xA95F0
UFG::qVector3 *__fastcall UFG::ParkourHandle::GetAxis(UFG::ParkourHandle *this, UFG::qVector3 *result)
{
  float v2; // xmm2_4
  float v3; // xmm5_4
  float v4; // xmm3_4
  __m128 y_low; // xmm6
  __m128 v6; // xmm4
  UFG::qVector3 *v7; // rax

  v2 = 0.0;
  y_low = (__m128)LODWORD(this->v1.y);
  v3 = this->v1.x - this->v0.x;
  v4 = this->v1.z - this->v0.z;
  y_low.m128_f32[0] = y_low.m128_f32[0] - this->v0.y;
  v6 = y_low;
  v6.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v3 * v3)) + (float)(v4 * v4);
  if ( v6.m128_f32[0] != 0.0 )
    v2 = 1.0 / _mm_sqrt_ps(v6).m128_f32[0];
  v7 = result;
  result->z = v4 * v2;
  result->x = v2 * v3;
  result->y = v2 * y_low.m128_f32[0];
  return v7;
}

// File Line: 276
// RVA: 0xAA7D0
void __fastcall UFG::ParkourHandle::GetLayout(
        UFG::ParkourHandle *this,
        UFG::qVector3 *position,
        UFG::qVector3 *axis,
        float *halfLength)
{
  float v4; // xmm2_4
  float v5; // xmm1_4
  __m128 y_low; // xmm2
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
  y_low = (__m128)LODWORD(this->v1.y);
  v7 = this->v1.z - this->v0.z;
  v8 = this->v1.x - this->v0.x;
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - this->v0.y) * (float)(y_low.m128_f32[0] - this->v0.y))
                            + (float)(v8 * v8))
                    + (float)(v7 * v7);
  v9 = _mm_sqrt_ps(y_low).m128_f32[0];
  v10 = 0.0;
  *halfLength = v9 * 0.5;
  v12 = (__m128)LODWORD(this->v1.y);
  v11 = this->v1.x - this->v0.x;
  v12.m128_f32[0] = v12.m128_f32[0] - this->v0.y;
  v14 = v12;
  v13 = this->v1.z - this->v0.z;
  v14.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v13 * v13);
  if ( v14.m128_f32[0] != 0.0 )
    v10 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
  axis->x = v11 * v10;
  axis->y = v12.m128_f32[0] * v10;
  axis->z = v13 * v10;
}

// File Line: 285
// RVA: 0xACD60
bool __fastcall UFG::ParkourHandle::IsType(UFG::ParkourHandle *this, __int16 flags)
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
bool __fastcall UFG::ParkourHandle::GetNormal(UFG::ParkourHandle *this, UFG::qVector3 *out)
{
  __m128 v2; // xmm2
  __m128 x_low; // xmm5
  float v4; // xmm6_4
  __m128 v5; // xmm4
  float v6; // xmm4_4
  float v7; // xmm4_4
  __m128 v8; // xmm1
  float v9; // xmm0_4
  bool result; // al

  x_low = (__m128)LODWORD(this->v1.x);
  v2 = 0i64;
  x_low.m128_f32[0] = x_low.m128_f32[0] - this->v0.x;
  v5 = x_low;
  v4 = this->v1.y - this->v0.y;
  v5.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v4 * v4))
                 + (float)((float)(this->v1.z - this->v0.z) * (float)(this->v1.z - this->v0.z));
  if ( v5.m128_f32[0] != 0.0 )
  {
    v2 = (__m128)(unsigned int)FLOAT_1_0;
    v2.m128_f32[0] = 1.0 / _mm_sqrt_ps(v5).m128_f32[0];
  }
  v6 = v2.m128_f32[0];
  v2.m128_f32[0] = v2.m128_f32[0] * v4;
  v7 = v6 * x_low.m128_f32[0];
  v8 = v2;
  v8.m128_f32[0] = (float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(v7 * v7);
  if ( v8.m128_f32[0] <= 0.001 )
    return 0;
  v9 = _mm_sqrt_ps(v8).m128_f32[0];
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
  float y; // xmm0_4
  float z; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  y = this->v0.y;
  z = this->v0.z;
  p0->x = this->v0.x;
  p0->y = y;
  p0->z = z;
  v5 = this->v1.y;
  v6 = this->v1.z;
  p1->x = this->v1.x;
  p1->y = v5;
  p1->z = v6;
}

// File Line: 424
// RVA: 0xA9AD0
float __fastcall UFG::ParkourHandle::GetDropoffDistance(
        UFG::ParkourHandle *this,
        UFG::qVector3 *pointAlongHandle,
        float radius)
{
  float v4; // xmm6_4
  __m128 v5; // xmm9
  __m128 v6; // xmm8
  __m128 v7; // xmm7
  __m128 v8; // xmm10
  UFG::BasePhysicsSystem *v10; // rbx
  __m128 v11; // xmm6
  __m128 v12; // xmm10
  hkpWorld *mWorld; // rdi
  _BOOL8 v14; // r8
  __m128 mPrev_low; // xmm2
  hkpShapePhantom *mPhantom; // rcx
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *mPrev; // rcx
  UFG::qNode<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo> *mNext; // rax
  UFG::ShapeCasterCollector v19; // [rsp+30h] [rbp-B8h] BYREF
  __m128 v20; // [rsp+60h] [rbp-88h] BYREF
  void **v21; // [rsp+70h] [rbp-78h] BYREF
  __m128 v22; // [rsp+78h] [rbp-70h]
  __int64 v23; // [rsp+88h] [rbp-60h]
  __m128 v24; // [rsp+B8h] [rbp-30h] BYREF
  int v25; // [rsp+C8h] [rbp-20h]
  int v26; // [rsp+CCh] [rbp-1Ch]
  __int64 v27; // [rsp+D8h] [rbp-10h]
  UFG::RayCastData data; // [rsp+E8h] [rbp+0h] BYREF
  UFG::qList<UFG::ShapeCasterCollector::HitInfo,UFG::ShapeCasterCollector::HitInfo,1,0> *p_mHitList; // [rsp+250h] [rbp+168h]

  v27 = -2i64;
  v4 = FLOAT_5_0;
  UFG::ParkourHandle::GetNormal(this, (UFG::qVector3 *)&v20);
  v5 = (__m128)v20.m128_u32[2];
  v6 = (__m128)v20.m128_u32[1];
  v7 = (__m128)v20.m128_u32[0];
  v5.m128_f32[0] = (float)(v20.m128_f32[2] * 0.30000001) + pointAlongHandle->z;
  v6.m128_f32[0] = (float)(v20.m128_f32[1] * 0.30000001) + pointAlongHandle->y;
  v7.m128_f32[0] = (float)(v20.m128_f32[0] * 0.30000001) + pointAlongHandle->x;
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
    memset(&data.mHavokRigidBody, 0, 17);
    if ( UFG::BasePhysicsSystem::CastRay(UFG::BasePhysicsSystem::mInstance, &data) )
      return data.t * 5.0;
  }
  else
  {
    UFG::ShapeCasterCollector::ShapeCasterCollector(&v19, radius, 0xCu, PhantomBehaviour_Simple);
    v10 = UFG::BasePhysicsSystem::mInstance;
    v11 = _mm_unpacklo_ps(_mm_unpacklo_ps(v7, v5), _mm_unpacklo_ps(v6, (__m128)(unsigned int)FLOAT_1_0));
    v12 = _mm_unpacklo_ps(_mm_unpacklo_ps(v7, v8), _mm_unpacklo_ps(v6, (__m128)(unsigned int)FLOAT_1_0));
    UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v19.mHitList);
    mWorld = v10->mWorld;
    if ( mWorld )
    {
      if ( !v19.mPhantom->m_world )
        hkpWorld::addPhantom(mWorld, v19.mPhantom);
      v25 = 872415232;
      v26 = 872415232;
      v20 = v11;
      v24 = v12;
      v22.m128_i32[0] = 2139095022;
      v21 = &hkpClosestCdPointCollector::`vftable;
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
      v21 = &hkpCdPointCollector::`vftable;
      hkpWorld::removePhantom(mWorld, v19.mPhantom);
    }
    mPrev_low = (__m128)LODWORD(v19.mHitList.mNode.mNext[1].mPrev);
    mPrev_low.m128_f32[0] = (float)((float)((float)(mPrev_low.m128_f32[0] - v7.m128_f32[0])
                                          * (float)(mPrev_low.m128_f32[0] - v7.m128_f32[0]))
                                  + (float)((float)(*((float *)&v19.mHitList.mNode.mNext[1].mPrev + 1) - v6.m128_f32[0])
                                          * (float)(*((float *)&v19.mHitList.mNode.mNext[1].mPrev + 1) - v6.m128_f32[0])))
                          + (float)((float)(*(float *)&v19.mHitList.mNode.mNext[1].mNext - v5.m128_f32[0])
                                  * (float)(*(float *)&v19.mHitList.mNode.mNext[1].mNext - v5.m128_f32[0]));
    LODWORD(v4) = _mm_sqrt_ps(mPrev_low).m128_u32[0];
    v19.vfptr = (UFG::ShapeCasterCollectorVtbl *)&UFG::ShapeCasterCollector::`vftable;
    mPhantom = v19.mPhantom;
    if ( v19.mPhantom )
    {
      if ( v19.mPhantom->m_world )
      {
        hkpWorld::removePhantom(v19.mPhantom->m_world, v19.mPhantom);
        mPhantom = v19.mPhantom;
      }
      hkReferencedObject::removeReference(mPhantom);
      v19.mPhantom = 0i64;
    }
    UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v19.mHitList);
    p_mHitList = &v19.mHitList;
    UFG::qList<UFG::FractureConnectivity::Connection,UFG::FractureConnectivity::Connection,1,0>::DeleteNodes((UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *)&v19.mHitList);
    mPrev = v19.mHitList.mNode.mPrev;
    mNext = v19.mHitList.mNode.mNext;
    v19.mHitList.mNode.mPrev->mNext = v19.mHitList.mNode.mNext;
    mNext->mPrev = mPrev;
    v19.mHitList.mNode.mPrev = &v19.mHitList.mNode;
    v19.mHitList.mNode.mNext = &v19.mHitList.mNode;
  }
  return v4;
}

// File Line: 470
// RVA: 0xAB370
UFG::qVector3 *__fastcall UFG::ParkourHandle::GetShortestRayTo(
        UFG::ParkourHandle *this,
        UFG::qVector3 *result,
        UFG::qVector3 *position)
{
  float v3; // xmm2_4
  float y; // xmm11_4
  float x; // xmm10_4
  float z; // xmm12_4
  __m128 y_low; // xmm4
  __m128 x_low; // xmm5
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

  x_low = (__m128)LODWORD(this->v1.x);
  y_low = (__m128)LODWORD(this->v1.y);
  v3 = 0.0;
  y = this->v0.y;
  x = this->v0.x;
  z = this->v0.z;
  y_low.m128_f32[0] = y_low.m128_f32[0] - y;
  x_low.m128_f32[0] = x_low.m128_f32[0] - x;
  v9 = this->v1.z - z;
  v10 = x_low;
  v10.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0])
                          + (float)(y_low.m128_f32[0] * y_low.m128_f32[0]))
                  + (float)(v9 * v9);
  if ( v10.m128_f32[0] != 0.0 )
    v3 = 1.0 / _mm_sqrt_ps(v10).m128_f32[0];
  v11 = x_low.m128_f32[0] * v3;
  v12 = y_low.m128_f32[0] * v3;
  v13 = v3 * v9;
  y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0])
                            + (float)(x_low.m128_f32[0] * x_low.m128_f32[0]))
                    + (float)(v9 * v9);
  v14 = position->y - (float)((float)(y + this->v1.y) * 0.5);
  v15 = position->z - (float)((float)(z + this->v1.z) * 0.5);
  v16 = _mm_sqrt_ps(y_low).m128_f32[0];
  v17 = position->x - (float)((float)(x + this->v1.x) * 0.5);
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
UFG::qVector3 *__fastcall UFG::ParkourHandle::GetClosestPointOnHandle(
        UFG::ParkourHandle *this,
        UFG::qVector3 *result,
        UFG::qVector3 *position)
{
  UFG::qVector3 *v5; // rax
  float v6; // xmm1_4
  float z; // xmm0_4
  UFG::qVector3 resulta; // [rsp+20h] [rbp-18h] BYREF

  UFG::ParkourHandle::GetShortestRayTo(this, &resulta, position);
  v5 = result;
  v6 = position->y - resulta.y;
  result->x = position->x - resulta.x;
  z = position->z;
  result->y = v6;
  result->z = z - resulta.z;
  return v5;
}

// File Line: 490
// RVA: 0xA9A90
float __fastcall UFG::ParkourHandle::GetDistanceTo(UFG::ParkourHandle *this, UFG::qVector3 *position)
{
  __m128 x_low; // xmm2
  float v3; // xmm0_4
  UFG::qVector3 result; // [rsp+20h] [rbp-18h] BYREF

  UFG::ParkourHandle::GetShortestRayTo(this, &result, position);
  x_low = (__m128)LODWORD(result.x);
  x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(result.y * result.y))
                    + (float)(result.z * result.z);
  LODWORD(v3) = _mm_sqrt_ps(x_low).m128_u32[0];
  return v3;
}

// File Line: 498
// RVA: 0xACC30
bool __fastcall UFG::ParkourHandle::IsAttachedToVehicle(UFG::ParkourHandle *this)
{
  UFG::SimObject *m_pPointer; // rax

  m_pPointer = this->mSimObject.m_pPointer;
  return m_pPointer && (m_pPointer->m_Flags & 0x8000u) != 0;
}

// File Line: 583
// RVA: 0xA2FB0
void __fastcall UFG::ParkourHandle::CompareParkourHandles(
        UFG::ParkourHandle *this,
        __int16 checkTypes,
        UFG::qVector3 *position,
        UFG::qVector3 *orientation,
        float relativeAngle,
        float bufferZone,
        float distanceXYMin,
        float distanceXYMax,
        float distanceZMin,
        float distanceZMax,
        UFG::qVector3 *contactPosition,
        UFG::ParkourHandle **closestParkHandle,
        float *currentDistanceTo,
        bool *currentInSegment)
{
  unsigned __int16 mFlags; // ax
  __m128 x_low; // xmm2
  float y; // xmm1_4
  float z; // xmm0_4
  __m128 v20; // xmm11
  __m128 v21; // xmm4
  float v22; // xmm5_4
  __m128 y_low; // xmm12
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
  UFG::ParkourHandle *m_pPointer; // rax
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
  __int64 v52; // xmm9_8
  float v53; // xmm15_4
  float v54; // xmm9_4
  float v55; // xmm15_4
  double v56; // xmm0_8
  double v57; // xmm0_8
  float v58; // xmm4_4
  __m128 z_low; // xmm3
  __m128 v60; // xmm2
  float v61; // xmm1_4
  float v62; // xmm3_4
  __m128 v63; // xmm5
  float v64; // xmm4_4
  float v65; // xmm14_4
  float v66; // xmm3_4
  float v67; // xmm4_4
  bool v68; // al
  double v69; // xmm0_8
  double v70; // xmm0_8
  float v71; // xmm0_4
  float v72; // [rsp+20h] [rbp-D9h]
  float v73; // [rsp+24h] [rbp-D5h]
  float v74; // [rsp+28h] [rbp-D1h]
  UFG::qVector3 v75; // [rsp+40h] [rbp-B9h] BYREF
  UFG::qVector3 dest; // [rsp+50h] [rbp-A9h] BYREF
  float v77; // [rsp+120h] [rbp+27h]

  mFlags = this->mFlags;
  if ( ((checkTypes & 1) == 0 || (mFlags & 1) == 0)
    && ((checkTypes & 4) == 0 || (mFlags & 4) == 0)
    && ((checkTypes & 8) == 0 || (mFlags & 8) == 0)
    && ((checkTypes & 2) == 0 || (mFlags & 2) == 0)
    && ((checkTypes & 0x10) == 0 || (mFlags & 0x10) == 0)
    && ((checkTypes & 0x20) == 0 || (mFlags & 0x20) == 0)
    && ((checkTypes & 2) == 0 || (mFlags & 2) == 0)
    && ((checkTypes & 0x100) == 0 || (this->mFlags & 0x100) == 0)
    && ((checkTypes & 0x40) == 0 || (mFlags & 0x40) == 0)
    && ((checkTypes & 0x80u) == 0 || (mFlags & 0x80u) == 0) )
  {
    return;
  }
  x_low = (__m128)LODWORD(this->v0.x);
  y = this->v0.y;
  z = this->v0.z;
  v21 = x_low;
  v20 = (__m128)LODWORD(this->v1.x);
  v21.m128_f32[0] = x_low.m128_f32[0] + v20.m128_f32[0];
  v20.m128_f32[0] = v20.m128_f32[0] - x_low.m128_f32[0];
  v21.m128_f32[0] = v21.m128_f32[0] * 0.5;
  y_low = (__m128)LODWORD(this->v1.y);
  v22 = y + y_low.m128_f32[0];
  y_low.m128_f32[0] = y_low.m128_f32[0] - y;
  v24 = v22 * 0.5;
  v25 = this->v1.z;
  v26 = y_low;
  v27 = z + v25;
  v28 = v25 - z;
  v29 = v27 * 0.5;
  v26.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v20.m128_f32[0] * v20.m128_f32[0]))
                  + (float)(v28 * v28);
  v30 = _mm_sqrt_ps(v26).m128_f32[0];
  v32 = y_low;
  v31 = v30 * 0.5;
  v32.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v20.m128_f32[0] * v20.m128_f32[0]))
                  + (float)(v28 * v28);
  if ( v32.m128_f32[0] == 0.0 )
    v33 = 0.0;
  else
    v33 = 1.0 / _mm_sqrt_ps(v32).m128_f32[0];
  v34 = y_low.m128_f32[0] * v33;
  v20.m128_f32[0] = v20.m128_f32[0] * v33;
  v44 = v21;
  v35 = 0;
  m_pPointer = 0i64;
  v37 = v31 * 2.0;
  v38 = v28 * v33;
  v41 = v20;
  v39 = v34 * v31;
  v40 = v38 * v31;
  v41.m128_f32[0] = v20.m128_f32[0] * v31;
  v42 = v24 - (float)(v34 * v31);
  v43 = v29 - (float)(v38 * v31);
  v44.m128_f32[0] = v21.m128_f32[0] - v41.m128_f32[0];
  v77 = v21.m128_f32[0] - v41.m128_f32[0];
  v45 = (float)((float)((float)(position->y - (float)(v24 - v39)) * v34)
              + (float)((float)(position->x - (float)(v21.m128_f32[0] - v41.m128_f32[0])) * v20.m128_f32[0]))
      + (float)((float)(position->z - (float)(v29 - v40)) * v38);
  v72 = v24 - v39;
  v73 = v29 - v40;
  if ( v45 < 0.0 )
  {
    if ( v45 <= v37 )
    {
      if ( v45 < 0.0 )
      {
        m_pPointer = this->mCachedRightNeighbor.m_pPointer;
        v44 = v21;
        v42 = v24;
        v43 = v29;
      }
      goto LABEL_31;
    }
    goto LABEL_28;
  }
  if ( v45 > v37 )
  {
LABEL_28:
    m_pPointer = this->mCachedLeftNeighbor.m_pPointer;
    v44 = v41;
    v42 = v39 + v24;
    v43 = v40 + v29;
    v44.m128_f32[0] = v41.m128_f32[0] + v21.m128_f32[0];
    goto LABEL_31;
  }
  v44 = v20;
  v35 = 1;
  v44.m128_f32[0] = (float)(v20.m128_f32[0] * v45) + v77;
  v42 = (float)(v34 * v45) + v72;
  v43 = (float)(v38 * v45) + v73;
LABEL_31:
  v44.m128_f32[0] = v44.m128_f32[0] - position->x;
  v46 = v42 - position->y;
  v47 = v43 - position->z;
  v48 = 1;
  if ( !v35 )
    v35 = m_pPointer != 0i64;
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
      if ( v49.m128_f32[0] == 0.0 )
      {
        v52 = 0i64;
      }
      else
      {
        v52 = (unsigned int)FLOAT_1_0;
        *(float *)&v52 = 1.0 / _mm_sqrt_ps(v49).m128_f32[0];
      }
      v53 = *(float *)&v52;
      *(float *)&v52 = *(float *)&v52 * v46;
      v55 = v53 * v44.m128_f32[0];
      HIDWORD(v56) = HIDWORD(v52);
      *(float *)&v56 = (float)(*(float *)&v52 * orientation->y) + (float)(v55 * orientation->x);
      v57 = UFG::qACos(v56);
      if ( relativeAngle >= *(float *)&v57 )
        goto LABEL_67;
      if ( bufferZone > 0.0 )
      {
        UFG::qRotateVectorZ(&dest, orientation, relativeAngle);
        UFG::qRotateVectorZ(&v75, orientation, COERCE_FLOAT(LODWORD(relativeAngle) ^ _xmm[0]));
        z_low = (__m128)LODWORD(dest.z);
        v58 = (float)(dest.y * UFG::qVector3::msDirUp.z) - (float)(dest.z * UFG::qVector3::msDirUp.y);
        z_low.m128_f32[0] = (float)(dest.z * UFG::qVector3::msDirUp.x) - (float)(dest.x * UFG::qVector3::msDirUp.z);
        v60 = z_low;
        v60.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(v58 * v58))
                        + (float)((float)((float)(dest.x * UFG::qVector3::msDirUp.y)
                                        - (float)(dest.y * UFG::qVector3::msDirUp.x))
                                * (float)((float)(dest.x * UFG::qVector3::msDirUp.y)
                                        - (float)(dest.y * UFG::qVector3::msDirUp.x)));
        if ( v60.m128_f32[0] == 0.0 )
          v61 = 0.0;
        else
          v61 = 1.0 / _mm_sqrt_ps(v60).m128_f32[0];
        v62 = z_low.m128_f32[0] * v61;
        v74 = v58 * v61;
        v63 = (__m128)LODWORD(v75.z);
        v63.m128_f32[0] = (float)(v75.z * UFG::qVector3::msDirUp.y) - (float)(v75.y * UFG::qVector3::msDirUp.z);
        v64 = (float)(v75.x * UFG::qVector3::msDirUp.z) - (float)(v75.z * UFG::qVector3::msDirUp.x);
        if ( (float)((float)((float)(v64 * v64) + (float)(v63.m128_f32[0] * v63.m128_f32[0]))
                   + (float)((float)((float)(v75.y * UFG::qVector3::msDirUp.x)
                                   - (float)(v75.x * UFG::qVector3::msDirUp.y))
                           * (float)((float)(v75.y * UFG::qVector3::msDirUp.x)
                                   - (float)(v75.x * UFG::qVector3::msDirUp.y)))) == 0.0 )
          v65 = 0.0;
        else
          v65 = 1.0 / _mm_sqrt_ps(v63).m128_f32[0];
        v66 = (float)(v62 * v54) + (float)(v74 * v55);
        v67 = (float)((float)(v64 * v65) * v54) + (float)((float)(v63.m128_f32[0] * v65) * v55);
        v68 = (float)((float)(dest.y * v54) + (float)(dest.x * v55)) > 0.0 && v66 > 0.0 && v66 < bufferZone;
        if ( (float)((float)(v75.y * v54) + (float)(v75.x * v55)) <= 0.0 || v67 <= 0.0 || v67 >= bufferZone )
          v48 = 0;
        if ( (unsigned __int8)v48 | v68 )
        {
LABEL_67:
          if ( !UFG::ParkourHandle::GetNormal(this, &dest)
            || (*(_QWORD *)&v69 = LODWORD(dest.y),
                *(float *)&v69 = (float)(dest.y * orientation->y) + (float)(dest.x * orientation->x),
                v70 = UFG::qACos(v69),
                *(float *)&v70 > (float)(3.1415927 - relativeAngle)) )
          {
            v51.m128_f32[0] = (float)(v51.m128_f32[0] * v51.m128_f32[0]) + (float)(v47 * v47);
            LODWORD(v71) = _mm_sqrt_ps(v51).m128_u32[0];
            if ( v35 && v71 < *currentDistanceTo )
            {
              *currentDistanceTo = v71;
              *closestParkHandle = this;
              *currentInSegment = v35;
              if ( contactPosition )
              {
                contactPosition->x = (float)(v20.m128_f32[0] * v45) + v77;
                contactPosition->y = (float)(v34 * v45) + v72;
                contactPosition->z = (float)(v38 * v45) + v73;
              }
            }
          }
        }
      }
    }
  }
}

