// File Line: 22
// RVA: 0xD5EBC0
void __fastcall hkpBroadPhaseBorder::hkpBroadPhaseBorder(hkpBroadPhaseBorder *this, hkpWorld *world, hkpWorldCinfo::BroadPhaseBorderBehaviour type, hkBool postponeAndSortCallbacks)
{
  hkpPhantom *v4; // rsi
  hkpWorld *v5; // rbp
  hkpBroadPhaseBorder *v6; // r14
  hkpWorld *v7; // rax
  hkVector4f v8; // xmm7
  hkVector4f v9; // xmm6
  hkVector4f v10; // xmm0
  _QWORD **v11; // rax
  hkpAabbPhantom *v12; // rax
  hkpPhantom *v13; // rax
  hkpPhantom *v14; // rbx
  hkVector4f v15; // xmm0
  _QWORD **v16; // rax
  hkpAabbPhantom *v17; // rax
  hkpPhantom *v18; // rax
  hkpPhantom *v19; // rbx
  _QWORD **v20; // rax
  hkpAabbPhantom *v21; // rax
  hkpPhantom *v22; // rax
  hkpPhantom *v23; // rbx
  _QWORD **v24; // rax
  hkpAabbPhantom *v25; // rax
  hkpPhantom *v26; // rax
  hkpPhantom *v27; // rbx
  _QWORD **v28; // rax
  hkpAabbPhantom *v29; // rax
  hkpPhantom *v30; // rax
  hkpPhantom *v31; // rbx
  _QWORD **v32; // rax
  hkpAabbPhantom *v33; // rax
  hkpPhantom *v34; // rax
  hkAabb aabb; // [rsp+20h] [rbp-58h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v4 = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBroadPhaseBorder::`vftable{for `hkReferencedObject};
  this->vfptr = (hkpWorldDeletionListenerVtbl *)&hkpBroadPhaseBorder::`vftable{for `hkpWorldDeletionListener};
  v5 = world;
  this->vfptr = (hkpPhantomOverlapListenerVtbl *)&hkpBroadPhaseBorder::`vftable{for `hkpPhantomOverlapListener};
  v6 = this;
  this->vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpBroadPhaseBorder::`vftable{for `hkpWorldPostSimulationListener};
  this->m_entitiesExitingBroadPhase.m_data = 0i64;
  this->m_entitiesExitingBroadPhase.m_size = 0;
  this->m_entitiesExitingBroadPhase.m_capacityAndFlags = 2147483648;
  this->m_world = world;
  this->m_type = type;
  this->m_postponeAndSortCallbacks = postponeAndSortCallbacks;
  hkReferencedObject::addReference((hkReferencedObject *)&this->vfptr);
  hkpWorld::addWorldDeletionListener(v6->m_world, (hkpWorldDeletionListener *)&v6->vfptr);
  hkpWorld::addWorldPostSimulationListener(v6->m_world, (hkpWorldPostSimulationListener *)&v6->vfptr);
  v7 = v6->m_world;
  v8.m_quad = (__m128)v7->m_broadPhaseExtents[0];
  v9.m_quad = (__m128)v7->m_broadPhaseExtents[1];
  v10.m_quad = (__m128)v7->m_broadPhaseExtents[0];
  aabb.m_max = (hkVector4f)v9.m_quad;
  v10.m_quad.m128_f32[0] = v9.m_quad.m128_f32[0];
  aabb.m_min = (hkVector4f)v10.m_quad;
  v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(v11[11], 304i64);
  if ( v12 )
  {
    hkpAabbPhantom::hkpAabbPhantom(v12, &aabb, 0);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  v14->m_collidable.m_broadPhaseHandle.m_type = 3;
  hkpPhantom::addPhantomOverlapListener(v14, (hkpPhantomOverlapListener *)&v6->vfptr);
  v6->m_phantoms[0] = v14;
  hkpWorld::addPhantom(v5, v14);
  v15.m_quad = v9.m_quad;
  v15.m_quad.m128_f32[0] = v8.m_quad.m128_f32[0];
  aabb.m_min = (hkVector4f)v8.m_quad;
  aabb.m_max = (hkVector4f)v15.m_quad;
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(v16[11], 304i64);
  if ( v17 )
  {
    hkpAabbPhantom::hkpAabbPhantom(v17, &aabb, 0);
    v19 = v18;
  }
  else
  {
    v19 = 0i64;
  }
  v19->m_collidable.m_broadPhaseHandle.m_type = 3;
  hkpPhantom::addPhantomOverlapListener(v19, (hkpPhantomOverlapListener *)&v6->vfptr);
  v6->m_phantoms[1] = v19;
  hkpWorld::addPhantom(v5, v19);
  aabb.m_max = (hkVector4f)v9.m_quad;
  aabb.m_min.m_quad = _mm_or_ps(
                        _mm_andnot_ps((__m128)xmmword_141A99E40, v9.m_quad),
                        _mm_and_ps((__m128)xmmword_141A99E40, v8.m_quad));
  v20 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v21 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v20[11] + 8i64))(v20[11], 304i64);
  if ( v21 )
  {
    hkpAabbPhantom::hkpAabbPhantom(v21, &aabb, 0);
    v23 = v22;
  }
  else
  {
    v23 = 0i64;
  }
  v23->m_collidable.m_broadPhaseHandle.m_type = 3;
  hkpPhantom::addPhantomOverlapListener(v23, (hkpPhantomOverlapListener *)&v6->vfptr);
  v6->m_phantoms[2] = v23;
  hkpWorld::addPhantom(v5, v23);
  aabb.m_min = (hkVector4f)v8.m_quad;
  aabb.m_max.m_quad = _mm_or_ps(
                        _mm_and_ps((__m128)xmmword_141A99E40, v9.m_quad),
                        _mm_andnot_ps((__m128)xmmword_141A99E40, v8.m_quad));
  v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v25 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v24[11] + 8i64))(v24[11], 304i64);
  if ( v25 )
  {
    hkpAabbPhantom::hkpAabbPhantom(v25, &aabb, 0);
    v27 = v26;
  }
  else
  {
    v27 = 0i64;
  }
  v27->m_collidable.m_broadPhaseHandle.m_type = 3;
  hkpPhantom::addPhantomOverlapListener(v27, (hkpPhantomOverlapListener *)&v6->vfptr);
  v6->m_phantoms[3] = v27;
  hkpWorld::addPhantom(v5, v27);
  aabb.m_max = (hkVector4f)v9.m_quad;
  aabb.m_min.m_quad = _mm_shuffle_ps(v8.m_quad, v9.m_quad, 228);
  v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v29 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v28[11] + 8i64))(v28[11], 304i64);
  if ( v29 )
  {
    hkpAabbPhantom::hkpAabbPhantom(v29, &aabb, 0);
    v31 = v30;
  }
  else
  {
    v31 = 0i64;
  }
  v31->m_collidable.m_broadPhaseHandle.m_type = 3;
  hkpPhantom::addPhantomOverlapListener(v31, (hkpPhantomOverlapListener *)&v6->vfptr);
  v6->m_phantoms[4] = v31;
  hkpWorld::addPhantom(v5, v31);
  aabb.m_min = (hkVector4f)v8.m_quad;
  aabb.m_max.m_quad = _mm_shuffle_ps(v9.m_quad, v8.m_quad, 228);
  v32 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v33 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v32[11] + 8i64))(v32[11], 304i64);
  if ( v33 )
  {
    hkpAabbPhantom::hkpAabbPhantom(v33, &aabb, 0);
    v4 = v34;
  }
  v4->m_collidable.m_broadPhaseHandle.m_type = 3;
  hkpPhantom::addPhantomOverlapListener(v4, (hkpPhantomOverlapListener *)&v6->vfptr);
  v6->m_phantoms[5] = v4;
  hkpWorld::addPhantom(v5, v4);
}

// File Line: 97
// RVA: 0xD5EF20
void __fastcall hkpBroadPhaseBorder::~hkpBroadPhaseBorder(hkpBroadPhaseBorder *this)
{
  hkpBroadPhaseBorder *v1; // rsi
  hkReferencedObject **v2; // rbx
  signed __int64 v3; // rdi
  int v4; // er8

  v1 = this;
  v2 = (hkReferencedObject **)this->m_phantoms;
  this->vfptr = (hkBaseObjectVtbl *)&hkpBroadPhaseBorder::`vftable{for `hkReferencedObject};
  v3 = 6i64;
  this->vfptr = (hkpWorldDeletionListenerVtbl *)&hkpBroadPhaseBorder::`vftable{for `hkpWorldDeletionListener};
  this->vfptr = (hkpPhantomOverlapListenerVtbl *)&hkpBroadPhaseBorder::`vftable{for `hkpPhantomOverlapListener};
  this->vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpBroadPhaseBorder::`vftable{for `hkpWorldPostSimulationListener};
  do
  {
    if ( *v2 )
    {
      hkReferencedObject::removeReference(*v2);
      *v2 = 0i64;
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  v4 = v1->m_entitiesExitingBroadPhase.m_capacityAndFlags;
  v1->m_entitiesExitingBroadPhase.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v1->m_entitiesExitingBroadPhase.m_data,
      8 * v4);
  v1->m_entitiesExitingBroadPhase.m_data = 0i64;
  v1->m_entitiesExitingBroadPhase.m_capacityAndFlags = 2147483648;
  v1->vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpWorldPostSimulationListener::`vftable;
  v1->vfptr = (hkpPhantomOverlapListenerVtbl *)&hkpPhantomOverlapListener::`vftable;
  v1->vfptr = (hkpWorldDeletionListenerVtbl *)&hkpWorldDeletionListener::`vftable;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 110
// RVA: 0xD5F110
void __fastcall hkpBroadPhaseBorder::collidableAddedCallback(hkpBroadPhaseBorder *this, hkpCollidableAddedEvent *event)
{
  hkpCollidable *v2; // rax
  hkReferencedObject *v3; // rbx
  hkpPhantom **v4; // rdi

  v2 = event->m_collidable;
  if ( v2->m_broadPhaseHandle.m_type == 1 )
  {
    v3 = (hkReferencedObject *)((char *)v2 + v2->m_ownerOffset);
    if ( v3 )
    {
      if ( BYTE4(this->m_phantoms[3]) )
      {
        v4 = &this->m_phantoms[4];
        if ( LODWORD(this->m_phantoms[5]) == (HIDWORD(this->m_phantoms[5]) & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
        *((_QWORD *)&(*v4)->vfptr + (signed int)(*((_DWORD *)v4 + 2))++) = v3;
        hkReferencedObject::addReference(v3);
      }
      else
      {
        (*(void (__fastcall **)(hkpWorldCinfo::BroadPhaseBorderBehaviour *, hkReferencedObject *))(*(_QWORD *)&this[-1].m_type
                                                                                                 + 24i64))(
          &this[-1].m_type,
          v3);
      }
    }
  }
}

// File Line: 133
// RVA: 0xD5F1B0
void __fastcall hkpBroadPhaseBorder::collidableRemovedCallback(hkpBroadPhaseBorder *this, hkpCollidableRemovedEvent *event)
{
  ;
}

// File Line: 137
// RVA: 0xD5F2D0
bool __fastcall hkpBroadPhaseBorder_EntityCmpLess(hkpEntity *a, hkpEntity *b)
{
  return a->m_uid < b->m_uid;
}

// File Line: 142
// RVA: 0xD5F1C0
void __fastcall hkpBroadPhaseBorder::postSimulationCallback(hkpBroadPhaseBorder *this, hkpWorld *world)
{
  signed int v2; // er8
  hkpBroadPhaseBorder *v3; // rbx
  int v4; // edi
  __int64 v5; // rsi

  v2 = (signed int)this->m_phantoms[4];
  v3 = this;
  if ( v2 )
  {
    if ( v2 > 1 )
      hkAlgorithm::quickSortRecursive<hkMonitorStreamAnalyzerPrintByTypeInfo *,bool (*)(hkMonitorStreamAnalyzerPrintByTypeInfo const *,hkMonitorStreamAnalyzerPrintByTypeInfo const *)>(
        (hkpEntity **)this->m_phantoms[3],
        0,
        v2 - 1,
        hkpBroadPhaseBorder_EntityCmpLess);
    v4 = 0;
    if ( SLODWORD(v3->m_phantoms[4]) > 0 )
    {
      v5 = 0i64;
      do
      {
        ((void (__fastcall *)(hkpPhantom **, _QWORD))v3[-1].m_phantoms[5]->m_userData)(
          &v3[-1].m_phantoms[5],
          *(hkBaseObjectVtbl **)((char *)&v3->m_phantoms[3]->vfptr + v5));
        ++v4;
        v5 += 8i64;
      }
      while ( v4 < SLODWORD(v3->m_phantoms[4]) );
    }
    hkReferencedObject::removeReferences((hkReferencedObject *const *)v3->m_phantoms[3], (int)v3->m_phantoms[4], 8);
    LODWORD(v3->m_phantoms[4]) = 0;
  }
}

// File Line: 159
// RVA: 0xD5F010
void __fastcall hkpBroadPhaseBorder::maxPositionExceededCallback(hkpBroadPhaseBorder *this, hkpEntity *entity)
{
  hkpWorldCinfo::BroadPhaseBorderBehaviour v2; // er8
  int v3; // er8
  hkpWorld *v4; // rcx
  hkBool result; // [rsp+30h] [rbp+8h]

  v2 = this->m_type;
  if ( v2 && (v3 = v2 - 1) != 0 )
  {
    if ( v3 == 1 )
    {
      v4 = this->m_world;
      if ( entity->m_world == v4 )
        hkpWorld::removeEntity(v4, &result, entity);
    }
  }
  else
  {
    hkpRigidBody::setMotionType((hkpRigidBody *)entity, MOTION_FIXED, HK_ENTITY_ACTIVATION_DO_ACTIVATE, 0);
  }
}

// File Line: 187
// RVA: 0xD5F270
void __fastcall hkpBroadPhaseBorder::worldDeletedCallback(hkpBroadPhaseBorder *this, hkpWorld *world)
{
  hkReferencedObject *v2; // rsi
  hkpWorldPostSimulationListener *v3; // rdi
  hkpBroadPhaseBorder *v4; // rbx
  hkpWorldDeletionListener *v5; // rdx

  v2 = (hkReferencedObject *)&this[-1].m_entitiesExitingBroadPhase;
  v3 = 0i64;
  v4 = this;
  v5 = 0i64;
  if ( this != (hkpBroadPhaseBorder *)16 )
    v5 = (hkpWorldDeletionListener *)this;
  hkpWorld::removeWorldDeletionListener((hkpWorld *)this->vfptr, v5);
  if ( v2 )
    v3 = (hkpWorldPostSimulationListener *)&v4->vfptr;
  hkpWorld::removeWorldPostSimulationListener((hkpWorld *)v4->vfptr, v3);
  hkReferencedObject::removeReference(v2);
}

// File Line: 194
// RVA: 0xD5F070
void __fastcall hkpBroadPhaseBorder::deactivate(hkpBroadPhaseBorder *this)
{
  hkpBroadPhaseBorder *v1; // rsi
  hkpWorld *v2; // rcx
  hkpPhantom **v3; // rbx
  signed __int64 v4; // rdi

  v1 = this;
  v2 = this->m_world;
  if ( v2 )
  {
    v3 = v1->m_phantoms;
    v4 = 6i64;
    hkpWorld::removePhantomBatch(v2, v1->m_phantoms, 6);
    do
    {
      hkpPhantom::removePhantomOverlapListener(*v3, (hkpPhantomOverlapListener *)&v1->vfptr);
      hkReferencedObject::removeReference((hkReferencedObject *)&(*v3)->vfptr);
      *v3 = 0i64;
      ++v3;
      --v4;
    }
    while ( v4 );
    v1->vfptr->worldDeletedCallback((hkpWorldDeletionListener *)&v1->vfptr, v1->m_world);
    v1->m_world = 0i64;
  }
}

