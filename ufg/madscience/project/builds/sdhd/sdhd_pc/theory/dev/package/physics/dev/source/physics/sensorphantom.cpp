// File Line: 68
// RVA: 0x9C910
void __fastcall UFG::PhantomBase::~PhantomBase(UFG::PhantomBase *this)
{
  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::PhantomBase::`vftable';
}

// File Line: 75
// RVA: 0x96830
void __fastcall UFG::AabbPhantom::AabbPhantom(UFG::AabbPhantom *this, hkAabb *aabb, unsigned int collisionFilterInfo, const char *name)
{
  unsigned int v4; // esi
  hkAabb *v5; // rdi
  UFG::AabbPhantom *v6; // rbx
  _QWORD **v7; // rax
  hkpAabbPhantom *v8; // rax

  v4 = collisionFilterInfo;
  v5 = aabb;
  v6 = this;
  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::PhantomBase::`vftable';
  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::AabbPhantom::`vftable';
  this->mAabb.m_min = aabb->m_min;
  this->mAabb.m_max = aabb->m_max;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 304i64);
  if ( v8 )
    hkpAabbPhantom::hkpAabbPhantom(v8, v5, v4);
  v6->mAabbPhantom = v8;
  UFG::AabbPhantom::SetTransform(v6, &UFG::qMatrix44::msIdentity);
  UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, (hkpPhantom *)&v6->mAabbPhantom->vfptr, 0);
}

// File Line: 93
// RVA: 0x9B1D0
void __fastcall UFG::AabbPhantom::~AabbPhantom(UFG::AabbPhantom *this)
{
  UFG::AabbPhantom *v1; // rsi
  hkpAabbPhantom *v2; // rbx
  UFG::BasePhysicsSystem *v3; // r8
  __int64 v4; // r11
  __int64 v5; // r9
  __int64 v6; // r10
  __int64 v7; // rax
  hkpWorld *v8; // rcx
  __int64 v9; // rcx
  hkpPhantom **v10; // rax
  hkArray<hkpPhantom *,hkContainerHeapAllocator> *v11; // rdi

  v1 = this;
  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::AabbPhantom::`vftable';
  v2 = this->mAabbPhantom;
  v3 = UFG::BasePhysicsSystem::mInstance;
  v4 = 0i64;
  v5 = 0i64;
  if ( UFG::BasePhysicsSystem::mInstance->mPhantomsToAdd.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      if ( (hkpAabbPhantom *)v3->mPhantomsToAdd.m_data[v6] == v2 )
      {
        v7 = --v3->mPhantomsToAdd.m_size;
        if ( (_DWORD)v7 != (_DWORD)v5 )
          v3->mPhantomsToAdd.m_data[v6] = v3->mPhantomsToAdd.m_data[v7];
        LODWORD(v5) = v5 - 1;
        --v6;
      }
      v5 = (unsigned int)(v5 + 1);
      ++v6;
    }
    while ( (signed int)v5 < v3->mPhantomsToAdd.m_size );
  }
  v8 = v2->m_world;
  if ( v8 )
  {
    if ( v3->mForceRemoveEntitiesToBeBatched )
    {
      v9 = v3->mPhantomsToRemove.m_size;
      if ( v9 <= 0 )
      {
LABEL_17:
        v11 = &v3->mPhantomsToRemove;
        if ( v3->mPhantomsToRemove.m_size == (v3->mPhantomsToRemove.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 8);
        v11->m_data[v11->m_size++] = (hkpPhantom *)&v2->vfptr;
        hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
      }
      else
      {
        v10 = v3->mPhantomsToRemove.m_data;
        while ( *v10 != (hkpPhantom *)v2 )
        {
          ++v4;
          ++v10;
          if ( v4 >= v9 )
            goto LABEL_17;
        }
        UFG::qPrintf("ignoring duplicate call to PhysicsSystem::RemoveEntity(hkpPhantom) %x\n", v2, v3, v5, -2i64);
      }
    }
    else
    {
      hkpWorld::removePhantom(v8, (hkpPhantom *)&v2->vfptr);
    }
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mAabbPhantom->vfptr);
  v1->vfptr = (UFG::PhantomBaseVtbl *)&UFG::PhantomBase::`vftable';
}

// File Line: 102
// RVA: 0xAAF00
hkArray<hkpCollidable *,hkContainerHeapAllocator> *__fastcall UFG::AabbPhantom::GetOverlappingCollidables(UFG::AabbPhantom *this)
{
  UFG::AabbPhantom *v1; // rbx

  v1 = this;
  ((void (*)(void))this->mAabbPhantom->vfptr[5].__first_virtual_table_function__)();
  return &v1->mAabbPhantom->m_overlappingCollidables;
}

// File Line: 111
// RVA: 0xB2580
void __fastcall UFG::AabbPhantom::SetTransform(UFG::AabbPhantom *this, UFG::qMatrix44 *transform)
{
  hkVector4f v2; // xmm4
  hkVector4f v3; // xmm3
  hkVector4f v4; // xmm2
  hkpAabbPhantom *v5; // rcx
  hkVector4f v6; // xmm2
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm2
  __m128 v10; // xmm4
  hkAabb newAabb; // [rsp+20h] [rbp-28h]

  v2.m_quad = (__m128)this->mAabb.m_max;
  v3.m_quad = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)LODWORD(transform->v3.x), (__m128)LODWORD(transform->v3.z)),
                _mm_unpacklo_ps((__m128)LODWORD(transform->v3.y), (__m128)0i64));
  v4.m_quad = (__m128)this->mAabb.m_min;
  this->mPosition = (hkVector4f)v3.m_quad;
  v5 = this->mAabbPhantom;
  v6.m_quad = _mm_add_ps(v4.m_quad, v3.m_quad);
  newAabb.m_max.m_quad = _mm_add_ps(v2.m_quad, v3.m_quad);
  newAabb.m_min = (hkVector4f)v6.m_quad;
  v7 = _mm_sub_ps(v6.m_quad, v5->m_aabb.m_min.m_quad);
  v8 = _mm_sub_ps(newAabb.m_max.m_quad, v5->m_aabb.m_max.m_quad);
  v9 = _mm_mul_ps(v7, v7);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v9, v9, 170))) > 1.0
    || (v10 = _mm_mul_ps(v8, v8),
        (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 0)))
              + COERCE_FLOAT(_mm_shuffle_ps(v10, v10, 170))) > 1.0) )
  {
    hkpAabbPhantom::setAabb(v5, &newAabb);
  }
}

// File Line: 144
// RVA: 0xB1240
void __fastcall UFG::AabbPhantom::SetExtents(UFG::AabbPhantom *this, UFG::qVector3 *bmin, UFG::qVector3 *bmax)
{
  this->mAabb.m_min.m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps((__m128)LODWORD(bmin->x), (__m128)LODWORD(bmin->z)),
                               _mm_unpacklo_ps((__m128)LODWORD(bmin->y), (__m128)0i64));
  this->mAabb.m_max.m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps((__m128)LODWORD(bmax->x), (__m128)LODWORD(bmax->z)),
                               _mm_unpacklo_ps((__m128)LODWORD(bmax->y), (__m128)0i64));
}

// File Line: 151
// RVA: 0xA9FF0
void __fastcall UFG::AabbPhantom::GetExtents(UFG::AabbPhantom *this, UFG::qVector3 *bmin, UFG::qVector3 *bmax)
{
  __m128 v3; // xmm1
  __m128 v4; // xmm2

  v3 = _mm_add_ps(this->mAabb.m_min.m_quad, this->mPosition.m_quad);
  v4 = _mm_add_ps(this->mAabb.m_max.m_quad, this->mPosition.m_quad);
  LODWORD(bmin->y) = (unsigned __int128)_mm_shuffle_ps(v3, v3, 85);
  LODWORD(bmin->x) = v3.m128_i32[0];
  LODWORD(bmin->z) = (unsigned __int128)_mm_shuffle_ps(v3, v3, 170);
  LODWORD(bmax->x) = v4.m128_i32[0];
  LODWORD(bmax->y) = (unsigned __int128)_mm_shuffle_ps(v4, v4, 85);
  LODWORD(bmax->z) = (unsigned __int128)_mm_shuffle_ps(v4, v4, 170);
}

// File Line: 164
// RVA: 0x99F60
void __fastcall UFG::ShapePhantom::ShapePhantom(UFG::ShapePhantom *this, hkpShape *shape, hkTransformf *xform, unsigned int collisionFilterInfo)
{
  unsigned int v4; // esi
  hkTransformf *v5; // rbp
  hkpShape *v6; // r14
  UFG::ShapePhantom *v7; // rdi
  hkpAllCdBodyPairCollector *v8; // ST28_8
  hkInplaceArray<hkpRootCdBodyPair,16,hkContainerHeapAllocator> *v9; // ST30_8
  hkpPhantom *v10; // rbx
  _QWORD **v11; // rax
  hkpSimpleShapePhantom *v12; // rax
  hkpPhantom *v13; // rax

  v4 = collisionFilterInfo;
  v5 = xform;
  v6 = shape;
  v7 = this;
  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::PhantomBase::`vftable';
  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::ShapePhantom::`vftable';
  v8 = &this->mCollector;
  v8->vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpCdBodyPairCollector::`vftable';
  v8->m_earlyOut.m_bool = 0;
  v8->vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpAllCdBodyPairCollector::`vftable';
  v9 = &this->mCollector.m_hits;
  v9->m_data = this->mCollector.m_hits.m_storage;
  v10 = 0i64;
  v9->m_size = 0;
  v9->m_capacityAndFlags = -2147483632;
  v8->m_hits.m_size = 0;
  v8->m_earlyOut.m_bool = 0;
  this->mInternalOverlappingCollidables.m_data = 0i64;
  this->mInternalOverlappingCollidables.m_size = 0;
  this->mInternalOverlappingCollidables.m_capacityAndFlags = 2147483648;
  v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkpSimpleShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(
                                   v11[11],
                                   448i64);
  if ( v12 )
  {
    hkpSimpleShapePhantom::hkpSimpleShapePhantom(v12, v6, v5, v4);
    v10 = v13;
  }
  v7->mSimpleShapePhantom = (hkpSimpleShapePhantom *)v10;
  UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, v10, 0);
}

// File Line: 178
// RVA: 0x9D360
void __fastcall UFG::ShapePhantom::~ShapePhantom(UFG::ShapePhantom *this)
{
  UFG::ShapePhantom *v1; // rsi
  hkpSimpleShapePhantom *v2; // rbx
  UFG::BasePhysicsSystem *v3; // r8
  int v4; // er9
  __int64 v5; // r10
  __int64 v6; // rax
  hkpWorld *v7; // rcx
  __int64 v8; // rcx
  __int64 v9; // rdx
  hkpPhantom **v10; // rax
  hkArray<hkpPhantom *,hkContainerHeapAllocator> *v11; // rdi
  int v12; // er8

  v1 = this;
  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::ShapePhantom::`vftable';
  v2 = this->mSimpleShapePhantom;
  v3 = UFG::BasePhysicsSystem::mInstance;
  v4 = 0;
  if ( UFG::BasePhysicsSystem::mInstance->mPhantomsToAdd.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      if ( (hkpSimpleShapePhantom *)v3->mPhantomsToAdd.m_data[v5] == v2 )
      {
        v6 = --v3->mPhantomsToAdd.m_size;
        if ( (_DWORD)v6 != v4 )
          v3->mPhantomsToAdd.m_data[v5] = v3->mPhantomsToAdd.m_data[v6];
        --v4;
        --v5;
      }
      ++v4;
      ++v5;
    }
    while ( v4 < v3->mPhantomsToAdd.m_size );
  }
  v7 = v2->m_world;
  if ( v7 )
  {
    if ( v3->mForceRemoveEntitiesToBeBatched )
    {
      v8 = 0i64;
      v9 = v3->mPhantomsToRemove.m_size;
      if ( v9 <= 0 )
      {
LABEL_17:
        v11 = &v3->mPhantomsToRemove;
        if ( v3->mPhantomsToRemove.m_size == (v3->mPhantomsToRemove.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 8);
        v11->m_data[v11->m_size++] = (hkpPhantom *)&v2->vfptr;
        hkReferencedObject::addReference((hkReferencedObject *)&v2->vfptr);
      }
      else
      {
        v10 = v3->mPhantomsToRemove.m_data;
        while ( *v10 != (hkpPhantom *)v2 )
        {
          ++v8;
          ++v10;
          if ( v8 >= v9 )
            goto LABEL_17;
        }
        UFG::qPrintf("ignoring duplicate call to PhysicsSystem::RemoveEntity(hkpPhantom) %x\n", v2);
      }
    }
    else
    {
      hkpWorld::removePhantom(v7, (hkpPhantom *)&v2->vfptr);
    }
  }
  hkReferencedObject::removeReference((hkReferencedObject *)&v1->mSimpleShapePhantom->vfptr);
  v1->mInternalOverlappingCollidables.m_size = 0;
  v12 = v1->mInternalOverlappingCollidables.m_capacityAndFlags;
  if ( v12 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->mInternalOverlappingCollidables.m_data,
      8 * v12);
  v1->mInternalOverlappingCollidables.m_data = 0i64;
  v1->mInternalOverlappingCollidables.m_capacityAndFlags = 2147483648;
  hkpAllCdBodyPairCollector::~hkpAllCdBodyPairCollector(&v1->mCollector);
  v1->vfptr = (UFG::PhantomBaseVtbl *)&UFG::PhantomBase::`vftable';
}

// File Line: 203
// RVA: 0xAAF30
hkArray<hkpCollidable *,hkContainerHeapAllocator> *__fastcall UFG::ShapePhantom::GetOverlappingCollidables(UFG::ShapePhantom *this)
{
  UFG::ShapePhantom *v1; // rbp
  hkpSimpleShapePhantom *v2; // r15
  void **v3; // rbx
  int v4; // er8
  int v5; // er9
  int v6; // edi
  __int64 v7; // rsi
  hkpSimpleShapePhantom::CollisionDetail *v8; // r14
  hkpCollidable *v9; // rax
  hkpCollidable *i; // rcx
  __int64 v11; // r8
  __int64 v12; // rdx
  hkpRootCdBodyPair *v13; // rcx
  hkResult result; // [rsp+50h] [rbp+8h]

  v1 = this;
  ((void (*)(void))this->mSimpleShapePhantom->vfptr[5].__first_virtual_table_function__)();
  v1->mCollector.vfptr->reset((hkpCdBodyPairCollector *)&v1->mCollector.vfptr);
  ((void (__fastcall *)(hkpSimpleShapePhantom *, hkpAllCdBodyPairCollector *, _QWORD))v1->mSimpleShapePhantom->vfptr[9].__vecDelDtor)(
    v1->mSimpleShapePhantom,
    &v1->mCollector,
    0i64);
  v2 = v1->mSimpleShapePhantom;
  v3 = (void **)&v1->mInternalOverlappingCollidables.m_data;
  v4 = v1->mInternalOverlappingCollidables.m_capacityAndFlags;
  v1->mInternalOverlappingCollidables.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      *v3,
      8 * v4);
  *v3 = 0i64;
  v1->mInternalOverlappingCollidables.m_capacityAndFlags = 2147483648;
  v5 = v2->m_collisionDetails.m_size;
  if ( !v5 )
    return &v1->mInternalOverlappingCollidables;
  if ( v5 > 0 )
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v1->mInternalOverlappingCollidables,
      v5,
      8);
  v6 = 0;
  if ( v2->m_collisionDetails.m_size <= 0 )
    return &v1->mInternalOverlappingCollidables;
  v7 = 0i64;
  do
  {
    v8 = v2->m_collisionDetails.m_data;
    v9 = v8[v7].m_collidable;
    for ( i = (hkpCollidable *)v9->m_parent; i; i = (hkpCollidable *)i->m_parent )
      v9 = i;
    v11 = v1->mCollector.m_hits.m_size;
    v12 = 0i64;
    if ( v11 > 0 )
    {
      v13 = v1->mCollector.m_hits.m_data;
      while ( v13->m_rootCollidableA != v9 && v13->m_rootCollidableB != v9 )
      {
        ++v12;
        ++v13;
        if ( v12 >= v11 )
          goto LABEL_19;
      }
      if ( v1->mInternalOverlappingCollidables.m_size == (v1->mInternalOverlappingCollidables.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v1->mInternalOverlappingCollidables,
          8);
      *((hkpSimpleShapePhantom::CollisionDetail *)*v3 + v1->mInternalOverlappingCollidables.m_size++) = v8[v7];
    }
LABEL_19:
    ++v6;
    ++v7;
  }
  while ( v6 < v2->m_collisionDetails.m_size );
  return &v1->mInternalOverlappingCollidables;
}

// File Line: 235
// RVA: 0xB26A0
void __fastcall UFG::ShapePhantom::SetTransform(UFG::ShapePhantom *this, UFG::qMatrix44 *mat)
{
  UFG::ShapePhantom *v2; // rbx
  hkTransformf transform; // [rsp+20h] [rbp-48h]

  v2 = this;
  hkTransformf::set4x4ColumnMajor(&transform, &mat->v0.x);
  hkpShapePhantom::setTransform((hkpShapePhantom *)&v2->mSimpleShapePhantom->vfptr, &transform);
}

// File Line: 247
// RVA: 0xAA040
void __fastcall UFG::ShapePhantom::GetExtents(UFG::ShapePhantom *this, UFG::qVector3 *bmin, UFG::qVector3 *bmax)
{
  UFG::qVector3 *v3; // rbx
  UFG::qVector3 *v4; // rdi
  int v5; // xmm1_4
  int v6; // xmm0_4
  int v7; // xmm1_4
  int v8; // xmm0_4
  int v9; // xmm1_4
  float v10; // [rsp+20h] [rbp-28h]
  int v11; // [rsp+24h] [rbp-24h]
  int v12; // [rsp+28h] [rbp-20h]
  int v13; // [rsp+30h] [rbp-18h]
  int v14; // [rsp+34h] [rbp-14h]
  int v15; // [rsp+38h] [rbp-10h]

  v3 = bmin;
  v4 = bmax;
  ((void (__fastcall *)(hkpSimpleShapePhantom *, float *))this->mSimpleShapePhantom->vfptr[3].__first_virtual_table_function__)(
    this->mSimpleShapePhantom,
    &v10);
  v5 = v11;
  v3->x = v10;
  v6 = v12;
  LODWORD(v3->y) = v5;
  v7 = v13;
  LODWORD(v3->z) = v6;
  v8 = v14;
  LODWORD(v4->x) = v7;
  v9 = v15;
  LODWORD(v4->y) = v8;
  LODWORD(v4->z) = v9;
}

// File Line: 259
// RVA: 0x99B50
void __fastcall UFG::SensorPhantom::SensorPhantom(UFG::SensorPhantom *this, hkAabb *aabb, unsigned int collisionFilterInfo, const char *name)
{
  const char *v4; // rsi
  unsigned int v5; // ebp
  hkAabb *v6; // r14
  UFG::SensorPhantom *v7; // rdi
  signed __int64 v8; // rbx
  char v9; // dl
  __int64 v10; // rax
  char v11; // cl
  char *v12; // rax
  UFG::PhantomBase *v13; // rax
  UFG::PhantomBase *v14; // rcx
  char v15; // al

  v4 = name;
  v5 = collisionFilterInfo;
  v6 = aabb;
  v7 = this;
  this->vfptr = (UFG::SensorPhantomVtbl *)&UFG::SensorPhantom::`vftable';
  this->mType = 0;
  v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v9 = ++*(_BYTE *)(v8 + 80);
  v10 = v9;
  *(_DWORD *)(v8 + 4 * v10) = 3;
  *(_QWORD *)(v8 + 8 * v10 + 16) = "AabbPhantom";
  *(_QWORD *)(v8 + 8 * v10 + 48) = 0i64;
  v11 = *(_BYTE *)(v8 + 81);
  if ( v9 > v11 )
    v11 = v9;
  *(_BYTE *)(v8 + 81) = v11;
  v12 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
  if ( v12 )
  {
    UFG::AabbPhantom::AabbPhantom((UFG::AabbPhantom *)v12, v6, v5, v4);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  v15 = *(_BYTE *)(v8 + 80);
  if ( v15 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v15 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  v7->mPhantom = v14;
}

// File Line: 291
// RVA: 0x99C60
void __fastcall UFG::SensorPhantom::SensorPhantom(UFG::SensorPhantom *this, hkpShape *shape, UFG::qMatrix44 *mat, unsigned int collisionFilterInfo)
{
  unsigned int v4; // esi
  hkpShape *v5; // rbp
  UFG::SensorPhantom *v6; // rdi
  signed __int64 v7; // rbx
  char v8; // dl
  __int64 v9; // rax
  char v10; // cl
  char *v11; // rax
  UFG::PhantomBase *v12; // rax
  UFG::PhantomBase *v13; // rcx
  char v14; // al
  hkTransformf xform; // [rsp+40h] [rbp-48h]

  v4 = collisionFilterInfo;
  v5 = shape;
  v6 = this;
  this->vfptr = (UFG::SensorPhantomVtbl *)&UFG::SensorPhantom::`vftable';
  this->mType = 1;
  hkTransformf::set4x4ColumnMajor(&xform, &mat->v0.x);
  v7 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v8 = ++*(_BYTE *)(v7 + 80);
  v9 = v8;
  *(_DWORD *)(v7 + 4 * v9) = 3;
  *(_QWORD *)(v7 + 8 * v9 + 16) = "ShapePhantom";
  *(_QWORD *)(v7 + 8 * v9 + 48) = 0i64;
  v10 = *(_BYTE *)(v7 + 81);
  if ( v8 > v10 )
    v10 = v8;
  *(_BYTE *)(v7 + 81) = v10;
  v11 = UFG::qMalloc(0x240ui64, UFG::gGlobalNewName, 0i64);
  if ( v11 )
  {
    UFG::ShapePhantom::ShapePhantom((UFG::ShapePhantom *)v11, v5, &xform, v4);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  v14 = *(_BYTE *)(v7 + 80);
  if ( v14 > 0 )
  {
    *(_BYTE *)(v7 + 80) = v14 - 1;
  }
  else
  {
    *(_BYTE *)(v7 + 80) = 0;
    *(_DWORD *)v7 = 3;
    *(_QWORD *)(v7 + 16) = 0i64;
    *(_QWORD *)(v7 + 48) = 0i64;
  }
  v6->mPhantom = v13;
}

// File Line: 309
// RVA: 0x9D2A0
void __fastcall UFG::SensorPhantom::~SensorPhantom(UFG::SensorPhantom *this)
{
  UFG::PhantomBase *v1; // rcx

  this->vfptr = (UFG::SensorPhantomVtbl *)&UFG::SensorPhantom::`vftable';
  v1 = this->mPhantom;
  if ( v1 )
    v1->vfptr->__vecDelDtor(v1, 1u);
}

// File Line: 320
// RVA: 0xB2690
void __fastcall UFG::SensorPhantom::SetTransform(UFG::SensorPhantom *this, UFG::qMatrix44 *transform)
{
  this->mPhantom->vfptr->SetTransform(this->mPhantom, transform);
}

// File Line: 920
// RVA: 0x99D90
void __fastcall UFG::SensorPhantomIterator::SensorPhantomIterator(UFG::SensorPhantomIterator *this, UFG::SensorPhantom *sensor, UFG::SensorPhantomIterator::Type iteratorType)
{
  UFG::SensorPhantomIterator *v3; // rbx
  UFG::SensorPhantomIterator::Type v4; // edi
  __int64 v5; // rax
  __int64 v6; // r9
  __int64 v7; // r8
  __int64 v8; // rdx
  __int64 v9; // rax
  __int64 v10; // rax

  v3 = this;
  v4 = iteratorType;
  this->vfptr = (UFG::SensorPhantomIteratorVtbl *)&UFG::SensorPhantomIterator::`vftable';
  v5 = ((__int64 (*)(void))sensor->mPhantom->vfptr->GetOverlappingCollidables)();
  v3->mType = v4;
  v3->mIndex = -1;
  v6 = v5;
  v3->mOverlappingCollidables = (hkArray<hkpCollidable *,hkContainerHeapAllocator> *)v5;
  if ( v4 == ITERATOR_SIM_OBJECT )
  {
    v3->mIndex = 0;
    if ( *(_DWORD *)(v5 + 8) > 0 )
    {
      do
      {
        v7 = v3->mIndex;
        v8 = *(_QWORD *)(*(_QWORD *)v6 + 8 * v7);
        if ( v8 )
        {
          v9 = *(_QWORD *)(*(char *)(v8 + 32) + v8 + 24);
          if ( v9 )
          {
            v10 = *(_QWORD *)(v9 + 24);
            if ( v10 )
            {
              if ( *(_QWORD *)(v10 + 40) )
                break;
            }
          }
        }
        v3->mIndex = v7 + 1;
      }
      while ( (signed int)v7 + 1 < *(_DWORD *)(v6 + 8) );
    }
  }
}

// File Line: 932
// RVA: 0x9D2C0
void __fastcall UFG::SensorPhantomIterator::~SensorPhantomIterator(UFG::SensorPhantomIterator *this)
{
  this->vfptr = (UFG::SensorPhantomIteratorVtbl *)&UFG::SensorPhantomIterator::`vftable';
}

// File Line: 938
// RVA: 0x9E0F0
void *__fastcall UFG::SensorPhantomIterator::operator*(UFG::SensorPhantomIterator *this)
{
  hkArray<hkpCollidable *,hkContainerHeapAllocator> *v1; // rax
  __int64 v2; // rdx
  hkpCollidable *v3; // rdx
  __int64 v4; // rax
  __int64 v5; // rax
  void *result; // rax

  if ( !this->mType
    && (v1 = this->mOverlappingCollidables, v2 = this->mIndex, (signed int)v2 < v1->m_size)
    && (v3 = v1->m_data[v2]) != 0i64
    && (v4 = *(__int64 *)((char *)&v3->m_parent + v3->m_ownerOffset)) != 0
    && (v5 = *(_QWORD *)(v4 + 24)) != 0 )
  {
    result = *(void **)(v5 + 40);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 969
// RVA: 0x9E130
void __fastcall UFG::SensorPhantomIterator::operator++(UFG::SensorPhantomIterator *this)
{
  UFG::SensorPhantomIterator *v1; // r9
  hkArray<hkpCollidable *,hkContainerHeapAllocator> *v2; // r10
  int v3; // eax
  hkpCollidable *v4; // r8
  __int64 v5; // rcx
  __int64 v6; // rcx

  v1 = this;
  if ( !this->mType )
  {
    v2 = this->mOverlappingCollidables;
    v3 = this->mIndex + 1;
    for ( this->mIndex = v3; v3 < v2->m_size; v1->mIndex = ++v3 )
    {
      v4 = v2->m_data[v3];
      if ( v4 )
      {
        v5 = *(__int64 *)((char *)&v4->m_parent + v4->m_ownerOffset);
        if ( v5 )
        {
          v6 = *(_QWORD *)(v5 + 24);
          if ( v6 )
          {
            if ( *(_QWORD *)(v6 + 40) )
              break;
          }
        }
      }
    }
  }
}

