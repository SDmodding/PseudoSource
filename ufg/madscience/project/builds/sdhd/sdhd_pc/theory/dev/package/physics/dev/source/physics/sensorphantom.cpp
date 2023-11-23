// File Line: 68
// RVA: 0x9C910
void __fastcall UFG::PhantomBase::~PhantomBase(UFG::PhantomBase *this)
{
  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::PhantomBase::`vftable;
}

// File Line: 75
// RVA: 0x96830
void __fastcall UFG::AabbPhantom::AabbPhantom(
        UFG::AabbPhantom *this,
        hkAabb *aabb,
        unsigned int collisionFilterInfo,
        const char *name)
{
  _QWORD **Value; // rax
  hkpAabbPhantom *v8; // rax

  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::PhantomBase::`vftable;
  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::AabbPhantom::`vftable;
  this->mAabb = *aabb;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 304i64);
  if ( v8 )
    hkpAabbPhantom::hkpAabbPhantom(v8, aabb, collisionFilterInfo);
  this->mAabbPhantom = v8;
  UFG::AabbPhantom::SetTransform(this, &UFG::qMatrix44::msIdentity);
  UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, this->mAabbPhantom, 0);
}

// File Line: 93
// RVA: 0x9B1D0
void __fastcall UFG::AabbPhantom::~AabbPhantom(UFG::AabbPhantom *this)
{
  hkpAabbPhantom *mAabbPhantom; // rbx
  UFG::BasePhysicsSystem *v3; // r8
  __int64 v4; // r11
  int v5; // r9d
  __int64 v6; // r10
  __int64 v7; // rax
  hkpWorld *m_world; // rcx
  __int64 m_size; // rcx
  hkpPhantom **m_data; // rax
  hkArray<hkpPhantom *,hkContainerHeapAllocator> *p_mPhantomsToRemove; // rdi

  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::AabbPhantom::`vftable;
  mAabbPhantom = this->mAabbPhantom;
  v3 = UFG::BasePhysicsSystem::mInstance;
  v4 = 0i64;
  v5 = 0;
  if ( UFG::BasePhysicsSystem::mInstance->mPhantomsToAdd.m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      if ( v3->mPhantomsToAdd.m_data[v6] == mAabbPhantom )
      {
        v7 = --v3->mPhantomsToAdd.m_size;
        if ( (_DWORD)v7 != v5 )
          v3->mPhantomsToAdd.m_data[v6] = v3->mPhantomsToAdd.m_data[v7];
        --v5;
        --v6;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < v3->mPhantomsToAdd.m_size );
  }
  m_world = mAabbPhantom->m_world;
  if ( m_world )
  {
    if ( v3->mForceRemoveEntitiesToBeBatched )
    {
      m_size = v3->mPhantomsToRemove.m_size;
      if ( m_size <= 0 )
      {
LABEL_17:
        p_mPhantomsToRemove = &v3->mPhantomsToRemove;
        if ( v3->mPhantomsToRemove.m_size == (v3->mPhantomsToRemove.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_mPhantomsToRemove, 8);
        p_mPhantomsToRemove->m_data[p_mPhantomsToRemove->m_size++] = mAabbPhantom;
        hkReferencedObject::addReference(mAabbPhantom);
      }
      else
      {
        m_data = v3->mPhantomsToRemove.m_data;
        while ( *m_data != mAabbPhantom )
        {
          ++v4;
          ++m_data;
          if ( v4 >= m_size )
            goto LABEL_17;
        }
        UFG::qPrintf("ignoring duplicate call to PhysicsSystem::RemoveEntity(hkpPhantom) %x\n", mAabbPhantom);
      }
    }
    else
    {
      hkpWorld::removePhantom(m_world, mAabbPhantom);
    }
  }
  hkReferencedObject::removeReference(this->mAabbPhantom);
  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::PhantomBase::`vftable;
}

// File Line: 102
// RVA: 0xAAF00
hkArray<hkpCollidable *,hkContainerHeapAllocator> *__fastcall UFG::AabbPhantom::GetOverlappingCollidables(
        UFG::AabbPhantom *this)
{
  this->mAabbPhantom->vfptr[5].__first_virtual_table_function__(this->mAabbPhantom);
  return &this->mAabbPhantom->m_overlappingCollidables;
}

// File Line: 111
// RVA: 0xB2580
void __fastcall UFG::AabbPhantom::SetTransform(UFG::AabbPhantom *this, UFG::qMatrix44 *transform)
{
  hkVector4f v2; // xmm4
  hkVector4f v3; // xmm3
  hkVector4f v4; // xmm2
  hkpAabbPhantom *mAabbPhantom; // rcx
  __m128 v6; // xmm2
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm4
  hkAabb newAabb; // [rsp+20h] [rbp-28h] BYREF

  v2.m_quad = (__m128)this->mAabb.m_max;
  v3.m_quad = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)LODWORD(transform->v3.x), (__m128)LODWORD(transform->v3.z)),
                _mm_unpacklo_ps((__m128)LODWORD(transform->v3.y), (__m128)0i64));
  v4.m_quad = (__m128)this->mAabb.m_min;
  this->mPosition = (hkVector4f)v3.m_quad;
  mAabbPhantom = this->mAabbPhantom;
  newAabb.m_max.m_quad = _mm_add_ps(v2.m_quad, v3.m_quad);
  newAabb.m_min.m_quad = _mm_add_ps(v4.m_quad, v3.m_quad);
  v6 = _mm_sub_ps(newAabb.m_min.m_quad, mAabbPhantom->m_aabb.m_min.m_quad);
  v7 = _mm_sub_ps(newAabb.m_max.m_quad, mAabbPhantom->m_aabb.m_max.m_quad);
  v8 = _mm_mul_ps(v6, v6);
  if ( (float)((float)(_mm_shuffle_ps(v8, v8, 85).m128_f32[0] + _mm_shuffle_ps(v8, v8, 0).m128_f32[0])
             + _mm_shuffle_ps(v8, v8, 170).m128_f32[0]) > 1.0
    || (v9 = _mm_mul_ps(v7, v7),
        (float)((float)(_mm_shuffle_ps(v9, v9, 85).m128_f32[0] + _mm_shuffle_ps(v9, v9, 0).m128_f32[0])
              + _mm_shuffle_ps(v9, v9, 170).m128_f32[0]) > 1.0) )
  {
    hkpAabbPhantom::setAabb(mAabbPhantom, &newAabb);
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
  LODWORD(bmin->y) = _mm_shuffle_ps(v3, v3, 85).m128_u32[0];
  LODWORD(bmin->x) = v3.m128_i32[0];
  LODWORD(bmin->z) = _mm_shuffle_ps(v3, v3, 170).m128_u32[0];
  LODWORD(bmax->x) = v4.m128_i32[0];
  LODWORD(bmax->y) = _mm_shuffle_ps(v4, v4, 85).m128_u32[0];
  LODWORD(bmax->z) = _mm_shuffle_ps(v4, v4, 170).m128_u32[0];
}

// File Line: 164
// RVA: 0x99F60
void __fastcall UFG::ShapePhantom::ShapePhantom(
        UFG::ShapePhantom *this,
        hkpShape *shape,
        hkTransformf *xform,
        unsigned int collisionFilterInfo)
{
  hkpSimpleShapePhantom *v8; // rbx
  _QWORD **Value; // rax
  hkpSimpleShapePhantom *v10; // rax
  hkpSimpleShapePhantom *v11; // rax

  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::PhantomBase::`vftable;
  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::ShapePhantom::`vftable;
  this->mCollector.vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpCdBodyPairCollector::`vftable;
  this->mCollector.m_earlyOut.m_bool = 0;
  this->mCollector.vfptr = (hkpCdBodyPairCollectorVtbl *)&hkpAllCdBodyPairCollector::`vftable;
  this->mCollector.m_hits.m_data = this->mCollector.m_hits.m_storage;
  v8 = 0i64;
  this->mCollector.m_hits.m_size = 0;
  this->mCollector.m_hits.m_capacityAndFlags = -2147483632;
  this->mCollector.m_hits.m_size = 0;
  this->mCollector.m_earlyOut.m_bool = 0;
  this->mInternalOverlappingCollidables.m_data = 0i64;
  this->mInternalOverlappingCollidables.m_size = 0;
  this->mInternalOverlappingCollidables.m_capacityAndFlags = 0x80000000;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkpSimpleShapePhantom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 448i64);
  if ( v10 )
  {
    hkpSimpleShapePhantom::hkpSimpleShapePhantom(v10, shape, xform, collisionFilterInfo);
    v8 = v11;
  }
  this->mSimpleShapePhantom = v8;
  UFG::BasePhysicsSystem::AddEntity(UFG::BasePhysicsSystem::mInstance, v8, 0);
}

// File Line: 178
// RVA: 0x9D360
void __fastcall UFG::ShapePhantom::~ShapePhantom(UFG::ShapePhantom *this)
{
  hkpSimpleShapePhantom *mSimpleShapePhantom; // rbx
  UFG::BasePhysicsSystem *v3; // r8
  int v4; // r9d
  __int64 v5; // r10
  __int64 v6; // rax
  hkpWorld *m_world; // rcx
  __int64 v8; // rcx
  __int64 m_size; // rdx
  hkpPhantom **m_data; // rax
  hkArray<hkpPhantom *,hkContainerHeapAllocator> *p_mPhantomsToRemove; // rdi
  int m_capacityAndFlags; // r8d

  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::ShapePhantom::`vftable;
  mSimpleShapePhantom = this->mSimpleShapePhantom;
  v3 = UFG::BasePhysicsSystem::mInstance;
  v4 = 0;
  if ( UFG::BasePhysicsSystem::mInstance->mPhantomsToAdd.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      if ( v3->mPhantomsToAdd.m_data[v5] == mSimpleShapePhantom )
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
  m_world = mSimpleShapePhantom->m_world;
  if ( m_world )
  {
    if ( v3->mForceRemoveEntitiesToBeBatched )
    {
      v8 = 0i64;
      m_size = v3->mPhantomsToRemove.m_size;
      if ( m_size <= 0 )
      {
LABEL_17:
        p_mPhantomsToRemove = &v3->mPhantomsToRemove;
        if ( v3->mPhantomsToRemove.m_size == (v3->mPhantomsToRemove.m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_mPhantomsToRemove, 8);
        p_mPhantomsToRemove->m_data[p_mPhantomsToRemove->m_size++] = mSimpleShapePhantom;
        hkReferencedObject::addReference(mSimpleShapePhantom);
      }
      else
      {
        m_data = v3->mPhantomsToRemove.m_data;
        while ( *m_data != mSimpleShapePhantom )
        {
          ++v8;
          ++m_data;
          if ( v8 >= m_size )
            goto LABEL_17;
        }
        UFG::qPrintf("ignoring duplicate call to PhysicsSystem::RemoveEntity(hkpPhantom) %x\n", mSimpleShapePhantom);
      }
    }
    else
    {
      hkpWorld::removePhantom(m_world, mSimpleShapePhantom);
    }
  }
  hkReferencedObject::removeReference(this->mSimpleShapePhantom);
  this->mInternalOverlappingCollidables.m_size = 0;
  m_capacityAndFlags = this->mInternalOverlappingCollidables.m_capacityAndFlags;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->mInternalOverlappingCollidables.m_data,
      8 * m_capacityAndFlags);
  this->mInternalOverlappingCollidables.m_data = 0i64;
  this->mInternalOverlappingCollidables.m_capacityAndFlags = 0x80000000;
  hkpAllCdBodyPairCollector::~hkpAllCdBodyPairCollector(&this->mCollector);
  this->vfptr = (UFG::PhantomBaseVtbl *)&UFG::PhantomBase::`vftable;
}

// File Line: 203
// RVA: 0xAAF30
hkArray<hkpCollidable *,hkContainerHeapAllocator> *__fastcall UFG::ShapePhantom::GetOverlappingCollidables(
        UFG::ShapePhantom *this)
{
  hkpSimpleShapePhantom *mSimpleShapePhantom; // r15
  hkArray<hkpCollidable *,hkContainerHeapAllocator> *p_mInternalOverlappingCollidables; // rbx
  int m_capacityAndFlags; // r8d
  int m_size; // r9d
  int v6; // edi
  __int64 v7; // rsi
  hkpSimpleShapePhantom::CollisionDetail *m_data; // r14
  hkpCollidable *m_collidable; // rax
  hkpCollidable *i; // rcx
  __int64 v11; // r8
  __int64 v12; // rdx
  hkpRootCdBodyPair *v13; // rcx
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  this->mSimpleShapePhantom->vfptr[5].__first_virtual_table_function__(this->mSimpleShapePhantom);
  this->mCollector.vfptr->reset(&this->mCollector);
  ((void (__fastcall *)(hkpSimpleShapePhantom *, hkpAllCdBodyPairCollector *, _QWORD))this->mSimpleShapePhantom->vfptr[9].__vecDelDtor)(
    this->mSimpleShapePhantom,
    &this->mCollector,
    0i64);
  mSimpleShapePhantom = this->mSimpleShapePhantom;
  p_mInternalOverlappingCollidables = &this->mInternalOverlappingCollidables;
  m_capacityAndFlags = this->mInternalOverlappingCollidables.m_capacityAndFlags;
  this->mInternalOverlappingCollidables.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      p_mInternalOverlappingCollidables->m_data,
      8 * m_capacityAndFlags);
  p_mInternalOverlappingCollidables->m_data = 0i64;
  this->mInternalOverlappingCollidables.m_capacityAndFlags = 0x80000000;
  m_size = mSimpleShapePhantom->m_collisionDetails.m_size;
  if ( !m_size )
    return &this->mInternalOverlappingCollidables;
  if ( m_size > 0 )
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      &this->mInternalOverlappingCollidables,
      m_size,
      8);
  v6 = 0;
  if ( mSimpleShapePhantom->m_collisionDetails.m_size <= 0 )
    return &this->mInternalOverlappingCollidables;
  v7 = 0i64;
  do
  {
    m_data = mSimpleShapePhantom->m_collisionDetails.m_data;
    m_collidable = m_data[v7].m_collidable;
    for ( i = (hkpCollidable *)m_collidable->m_parent; i; i = (hkpCollidable *)i->m_parent )
      m_collidable = i;
    v11 = this->mCollector.m_hits.m_size;
    v12 = 0i64;
    if ( v11 > 0 )
    {
      v13 = this->mCollector.m_hits.m_data;
      while ( v13->m_rootCollidableA != m_collidable && v13->m_rootCollidableB != m_collidable )
      {
        ++v12;
        ++v13;
        if ( v12 >= v11 )
          goto LABEL_19;
      }
      if ( this->mInternalOverlappingCollidables.m_size == (this->mInternalOverlappingCollidables.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &this->mInternalOverlappingCollidables, 8);
      p_mInternalOverlappingCollidables->m_data[this->mInternalOverlappingCollidables.m_size++] = (hkpCollidable *)m_data[v7];
    }
LABEL_19:
    ++v6;
    ++v7;
  }
  while ( v6 < mSimpleShapePhantom->m_collisionDetails.m_size );
  return &this->mInternalOverlappingCollidables;
}

// File Line: 235
// RVA: 0xB26A0
void __fastcall UFG::ShapePhantom::SetTransform(UFG::ShapePhantom *this, UFG::qMatrix44 *mat)
{
  hkTransformf transform; // [rsp+20h] [rbp-48h] BYREF

  hkTransformf::set4x4ColumnMajor(&transform, &mat->v0.x);
  hkpShapePhantom::setTransform(this->mSimpleShapePhantom, &transform);
}

// File Line: 247
// RVA: 0xAA040
void __fastcall UFG::ShapePhantom::GetExtents(UFG::ShapePhantom *this, UFG::qVector3 *bmin, UFG::qVector3 *bmax)
{
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  int v10[10]; // [rsp+20h] [rbp-28h] BYREF

  ((void (__fastcall *)(hkpSimpleShapePhantom *, int *))this->mSimpleShapePhantom->vfptr[3].__first_virtual_table_function__)(
    this->mSimpleShapePhantom,
    v10);
  v5 = *(float *)&v10[1];
  LODWORD(bmin->x) = v10[0];
  v6 = *(float *)&v10[2];
  bmin->y = v5;
  v7 = *(float *)&v10[4];
  bmin->z = v6;
  v8 = *(float *)&v10[5];
  bmax->x = v7;
  v9 = *(float *)&v10[6];
  bmax->y = v8;
  bmax->z = v9;
}

// File Line: 259
// RVA: 0x99B50
void __fastcall UFG::SensorPhantom::SensorPhantom(
        UFG::SensorPhantom *this,
        hkAabb *aabb,
        unsigned int collisionFilterInfo,
        const char *name)
{
  __int64 v8; // rbx
  char v9; // dl
  char v10; // cl
  char *v11; // rax
  UFG::PhantomBase *v12; // rax
  UFG::PhantomBase *v13; // rcx
  char v14; // al

  this->vfptr = (UFG::SensorPhantomVtbl *)&UFG::SensorPhantom::`vftable;
  this->mType = AABB_PHANTOM;
  v8 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v9 = ++*(_BYTE *)(v8 + 80);
  *(_DWORD *)(v8 + 4i64 * v9) = 3;
  *(_QWORD *)(v8 + 8i64 * v9 + 16) = "AabbPhantom";
  *(_QWORD *)(v8 + 8i64 * v9 + 48) = 0i64;
  v10 = *(_BYTE *)(v8 + 81);
  if ( v9 > v10 )
    v10 = v9;
  *(_BYTE *)(v8 + 81) = v10;
  v11 = UFG::qMalloc(0x40ui64, UFG::gGlobalNewName, 0i64);
  if ( v11 )
  {
    UFG::AabbPhantom::AabbPhantom((UFG::AabbPhantom *)v11, aabb, collisionFilterInfo, name);
    v13 = v12;
  }
  else
  {
    v13 = 0i64;
  }
  v14 = *(_BYTE *)(v8 + 80);
  if ( v14 > 0 )
  {
    *(_BYTE *)(v8 + 80) = v14 - 1;
  }
  else
  {
    *(_BYTE *)(v8 + 80) = 0;
    *(_DWORD *)v8 = 3;
    *(_QWORD *)(v8 + 16) = 0i64;
    *(_QWORD *)(v8 + 48) = 0i64;
  }
  this->mPhantom = v13;
}

// File Line: 291
// RVA: 0x99C60
void __fastcall UFG::SensorPhantom::SensorPhantom(
        UFG::SensorPhantom *this,
        hkpShape *shape,
        UFG::qMatrix44 *mat,
        unsigned int collisionFilterInfo)
{
  __int64 v7; // rbx
  char v8; // dl
  char v9; // cl
  char *v10; // rax
  UFG::PhantomBase *v11; // rax
  UFG::PhantomBase *v12; // rcx
  char v13; // al
  hkTransformf xform; // [rsp+40h] [rbp-48h] BYREF

  this->vfptr = (UFG::SensorPhantomVtbl *)&UFG::SensorPhantom::`vftable;
  this->mType = SHAPE_PHANTOM;
  hkTransformf::set4x4ColumnMajor(&xform, &mat->v0.x);
  v7 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v8 = ++*(_BYTE *)(v7 + 80);
  *(_DWORD *)(v7 + 4i64 * v8) = 3;
  *(_QWORD *)(v7 + 8i64 * v8 + 16) = "ShapePhantom";
  *(_QWORD *)(v7 + 8i64 * v8 + 48) = 0i64;
  v9 = *(_BYTE *)(v7 + 81);
  if ( v8 > v9 )
    v9 = v8;
  *(_BYTE *)(v7 + 81) = v9;
  v10 = UFG::qMalloc(0x240ui64, UFG::gGlobalNewName, 0i64);
  if ( v10 )
  {
    UFG::ShapePhantom::ShapePhantom((UFG::ShapePhantom *)v10, shape, &xform, collisionFilterInfo);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v13 = *(_BYTE *)(v7 + 80);
  if ( v13 > 0 )
  {
    *(_BYTE *)(v7 + 80) = v13 - 1;
  }
  else
  {
    *(_BYTE *)(v7 + 80) = 0;
    *(_DWORD *)v7 = 3;
    *(_QWORD *)(v7 + 16) = 0i64;
    *(_QWORD *)(v7 + 48) = 0i64;
  }
  this->mPhantom = v12;
}

// File Line: 309
// RVA: 0x9D2A0
void __fastcall UFG::SensorPhantom::~SensorPhantom(UFG::SensorPhantom *this)
{
  UFG::PhantomBase *mPhantom; // rcx

  this->vfptr = (UFG::SensorPhantomVtbl *)&UFG::SensorPhantom::`vftable;
  mPhantom = this->mPhantom;
  if ( mPhantom )
    mPhantom->vfptr->__vecDelDtor(mPhantom, 1u);
}

// File Line: 320
// RVA: 0xB2690
void __fastcall UFG::SensorPhantom::SetTransform(UFG::SensorPhantom *this, UFG::qMatrix44 *transform)
{
  this->mPhantom->vfptr->SetTransform(this->mPhantom, transform);
}

// File Line: 920
// RVA: 0x99D90
void __fastcall UFG::SensorPhantomIterator::SensorPhantomIterator(
        UFG::SensorPhantomIterator *this,
        UFG::SensorPhantom *sensor,
        unsigned int iteratorType)
{
  hkArray<hkpCollidable *,hkContainerHeapAllocator> *v5; // rax
  hkArray<hkpCollidable *,hkContainerHeapAllocator> *v6; // r9
  __int64 mIndex; // r8
  hkpCollidable *v8; // rdx
  __int64 v9; // rax
  __int64 v10; // rax

  this->vfptr = (UFG::SensorPhantomIteratorVtbl *)&UFG::SensorPhantomIterator::`vftable;
  v5 = sensor->mPhantom->vfptr->GetOverlappingCollidables(sensor->mPhantom);
  this->mType = iteratorType;
  this->mIndex = -1;
  v6 = v5;
  this->mOverlappingCollidables = v5;
  if ( !iteratorType )
  {
    this->mIndex = 0;
    if ( v5->m_size > 0 )
    {
      do
      {
        mIndex = this->mIndex;
        v8 = v6->m_data[mIndex];
        if ( v8 )
        {
          v9 = *(__int64 *)((char *)&v8->m_parent + v8->m_ownerOffset);
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
        this->mIndex = mIndex + 1;
      }
      while ( (int)mIndex + 1 < v6->m_size );
    }
  }
}

// File Line: 932
// RVA: 0x9D2C0
void __fastcall UFG::SensorPhantomIterator::~SensorPhantomIterator(UFG::SensorPhantomIterator *this)
{
  this->vfptr = (UFG::SensorPhantomIteratorVtbl *)&UFG::SensorPhantomIterator::`vftable;
}

// File Line: 938
// RVA: 0x9E0F0
void *__fastcall UFG::SensorPhantomIterator::operator*(UFG::SensorPhantomIterator *this)
{
  hkArray<hkpCollidable *,hkContainerHeapAllocator> *mOverlappingCollidables; // rax
  __int64 mIndex; // rdx
  hkpCollidable *v3; // rdx
  __int64 v4; // rax
  __int64 v5; // rax

  if ( !this->mType
    && (mOverlappingCollidables = this->mOverlappingCollidables,
        mIndex = this->mIndex,
        (int)mIndex < mOverlappingCollidables->m_size)
    && (v3 = mOverlappingCollidables->m_data[mIndex]) != 0i64
    && (v4 = *(__int64 *)((char *)&v3->m_parent + v3->m_ownerOffset)) != 0
    && (v5 = *(_QWORD *)(v4 + 24)) != 0 )
  {
    return *(void **)(v5 + 40);
  }
  else
  {
    return 0i64;
  }
}

// File Line: 969
// RVA: 0x9E130
void __fastcall UFG::SensorPhantomIterator::operator++(UFG::SensorPhantomIterator *this)
{
  hkArray<hkpCollidable *,hkContainerHeapAllocator> *mOverlappingCollidables; // r10
  int v3; // eax
  hkpCollidable *v4; // r8
  __int64 v5; // rcx
  __int64 v6; // rcx

  if ( !this->mType )
  {
    mOverlappingCollidables = this->mOverlappingCollidables;
    v3 = this->mIndex + 1;
    for ( this->mIndex = v3; v3 < mOverlappingCollidables->m_size; this->mIndex = ++v3 )
    {
      v4 = mOverlappingCollidables->m_data[v3];
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

