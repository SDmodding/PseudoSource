// File Line: 40
// RVA: 0xE290C0
void __fastcall hkpVehicleLinearCastWheelCollide::hkpVehicleLinearCastWheelCollide(
        hkpVehicleLinearCastWheelCollide *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_alreadyUsed.m_bool = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleLinearCastWheelCollide::`vftable;
  this->m_wheelStates.m_capacityAndFlags = 0x80000000;
  this->m_wheelStates.m_data = 0i64;
  this->m_wheelStates.m_size = 0;
  *(_DWORD *)&this->m_rejectChassisListener.m_memSizeAndFlags = 0x1FFFF;
  this->m_rejectChassisListener.vfptr = (hkBaseObjectVtbl *)&hkpRejectChassisListener::`vftable{for `hkReferencedObject};
  this->m_rejectChassisListener.vfptr = (hkpPhantomOverlapListenerVtbl *)&hkpRejectChassisListener::`vftable{for `hkpPhantomOverlapListener};
  this->m_maxExtraPenetration = 0.00000011920929;
  this->m_startPointTolerance = 0.00000011920929;
  *(_WORD *)&this->m_alreadyUsed.m_bool = 512;
}

// File Line: 47
// RVA: 0xE29450
void __fastcall hkpVehicleLinearCastWheelCollide::setWheelShapes(
        hkpVehicleLinearCastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        hkArray<hkpShape *,hkContainerHeapAllocator> *shapes)
{
  hkArray<hkpVehicleLinearCastWheelCollide::WheelState,hkContainerHeapAllocator> *p_m_wheelStates; // rsi
  int m_numWheels; // edi
  int v6; // eax
  int v7; // eax
  int v8; // r9d
  unsigned __int8 v9; // bl
  __int64 v10; // r10
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  p_m_wheelStates = &this->m_wheelStates;
  m_numWheels = (unsigned __int8)vehicle->m_data->m_numWheels;
  v6 = this->m_wheelStates.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < m_numWheels )
  {
    v7 = 2 * v6;
    v8 = (unsigned __int8)vehicle->m_data->m_numWheels;
    if ( m_numWheels < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_wheelStates->m_data, v8, 96);
  }
  v9 = 0;
  for ( p_m_wheelStates->m_size = m_numWheels; v9 < m_numWheels; ++v9 )
  {
    v10 = v9;
    p_m_wheelStates->m_data[v9].m_shape = shapes->m_data[v10];
    hkReferencedObject::addReference(shapes->m_data[v10]);
  }
}

// File Line: 65
// RVA: 0xE293A0
// local variable allocation has failed, the output may be wrong!
void __fastcall hkpVehicleLinearCastWheelCollide::createWheelShape(
        hkpVehicleLinearCastWheelCollide *this,
        double width,
        float radius)
{
  _QWORD **Value; // rax
  hkpCylinderShape *v4; // rax
  hkVector4f vertexB; // [rsp+30h] [rbp-48h] BYREF
  hkVector4f vertexA; // [rsp+40h] [rbp-38h] BYREF

  *(float *)&width = *(float *)&width * 0.5;
  vertexA.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, *(__m128 *)&width), (__m128)0i64);
  vertexB.m_quad = _mm_xor_ps(
                     (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
                     vertexA.m_quad);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (hkpCylinderShape *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 112i64);
  if ( v4 )
    hkpCylinderShape::hkpCylinderShape(v4, &vertexA, &vertexB, radius, 0.0);
}

// File Line: 79
// RVA: 0xE29210
void __fastcall hkpVehicleLinearCastWheelCollide::init(
        hkpVehicleLinearCastWheelCollide *this,
        hkpVehicleInstance *vehicle)
{
  int m_numWheels; // esi
  int v5; // eax
  int v6; // eax
  int v7; // r9d
  unsigned __int8 v8; // bp
  hkpVehicleLinearCastWheelCollide::WheelState *v9; // rbx
  hkpCylinderShape *WheelShape; // rax
  unsigned __int8 v11; // bl
  _QWORD **Value; // rax
  hkpAabbPhantom *v13; // rax
  hkpAabbPhantom *v14; // rax
  hkpAabbPhantom *v15; // rcx
  hkpPhantomOverlapListener *v16; // rdx
  hkAabb aabbOut; // [rsp+30h] [rbp-38h] BYREF
  hkResult result; // [rsp+70h] [rbp+8h] BYREF

  m_numWheels = (unsigned __int8)vehicle->m_data->m_numWheels;
  if ( !this->m_wheelStates.m_size )
  {
    v5 = this->m_wheelStates.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v5 < m_numWheels )
    {
      v6 = 2 * v5;
      v7 = (unsigned __int8)vehicle->m_data->m_numWheels;
      if ( m_numWheels < v6 )
        v7 = v6;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->m_wheelStates.m_data,
        v7,
        96);
    }
    v8 = 0;
    for ( this->m_wheelStates.m_size = m_numWheels; v8 < m_numWheels; v9->m_shape = WheelShape )
    {
      v9 = &this->m_wheelStates.m_data[v8];
      WheelShape = hkpVehicleLinearCastWheelCollide::createWheelShape(
                     this,
                     vehicle->m_data->m_wheelParams.m_data[v8].m_width,
                     vehicle->m_data->m_wheelParams.m_data[v8].m_radius);
      ++v8;
    }
  }
  v11 = 0;
  for ( this->m_rejectChassisListener.m_chassis = &vehicle->m_entity->m_collidable; v11 < m_numWheels; ++v11 )
  {
    hkpVehicleLinearCastWheelCollide::updateWheelState(this, vehicle, v11);
    hkpVehicleLinearCastWheelCollide::calcAabbOfWheel(this, vehicle, v11, &aabbOut);
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 304i64);
    if ( v13 )
    {
      hkpAabbPhantom::hkpAabbPhantom(v13, &aabbOut, this->m_wheelCollisionFilterInfo);
      v15 = v14;
    }
    else
    {
      v15 = 0i64;
    }
    this->m_wheelStates.m_data[v11].m_phantom = v15;
    if ( this == (hkpVehicleLinearCastWheelCollide *)-48i64 )
      v16 = 0i64;
    else
      v16 = &this->m_rejectChassisListener.hkpPhantomOverlapListener;
    hkpPhantom::addPhantomOverlapListener(this->m_wheelStates.m_data[v11].m_phantom, v16);
  }
}

// File Line: 136
// RVA: 0xE29120
void __fastcall hkpVehicleLinearCastWheelCollide::~hkpVehicleLinearCastWheelCollide(
        hkpVehicleLinearCastWheelCollide *this)
{
  __int64 m_size; // rbp
  __int64 v3; // rsi
  hkpVehicleLinearCastWheelCollide::WheelState *m_data; // rdi
  hkpPhantom *m_phantom; // rdi
  hkpPhantomOverlapListener *v6; // rdx
  int m_capacityAndFlags; // eax

  m_size = this->m_wheelStates.m_size;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleLinearCastWheelCollide::`vftable;
  if ( m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      m_data = this->m_wheelStates.m_data;
      hkReferencedObject::removeReference(m_data[v3].m_shape);
      m_phantom = m_data[v3].m_phantom;
      if ( this->m_memSizeAndFlags && m_phantom->m_memSizeAndFlags )
      {
        if ( this == (hkpVehicleLinearCastWheelCollide *)-48i64 )
          v6 = 0i64;
        else
          v6 = &this->m_rejectChassisListener.hkpPhantomOverlapListener;
        hkpPhantom::removePhantomOverlapListener(m_phantom, v6);
      }
      hkReferencedObject::removeReference(m_phantom);
      ++v3;
      --m_size;
    }
    while ( m_size );
  }
  hkpRejectChassisListener::~hkpRejectChassisListener(&this->m_rejectChassisListener);
  m_capacityAndFlags = this->m_wheelStates.m_capacityAndFlags;
  this->m_wheelStates.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_wheelStates.m_data,
      96 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_wheelStates.m_data = 0i64;
  this->m_wheelStates.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 156
// RVA: 0xE29960
void __fastcall hkpVehicleLinearCastWheelCollide::collideWheels(
        hkpVehicleLinearCastWheelCollide *this,
        const float deltaTime,
        hkpVehicleInstance *vehicle,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfoOut)
{
  hkpVehicleData *m_data; // rax
  unsigned __int8 v5; // di
  int m_numWheels; // r14d
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v10; // rsi
  bool v11; // zf
  hkBaseObjectVtbl *vfptr; // rax
  char v13[64]; // [rsp+30h] [rbp-58h] BYREF
  char v14; // [rsp+A0h] [rbp+18h] BYREF

  m_data = vehicle->m_data;
  v5 = 0;
  m_numWheels = (unsigned __int8)m_data->m_numWheels;
  if ( m_data->m_numWheels )
  {
    do
    {
      v10 = &cdInfoOut[v5];
      v11 = *(_BYTE *)((__int64 (__fastcall *)(hkpVehicleLinearCastWheelCollide *, char *, hkpVehicleInstance *, _QWORD, char *))this->vfptr[8].__vecDelDtor)(
                        this,
                        &v14,
                        vehicle,
                        v5,
                        v13) == 0;
      vfptr = this->vfptr;
      if ( v11 )
        ((void (__fastcall *)(hkpVehicleLinearCastWheelCollide *, hkpVehicleInstance *, _QWORD, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))vfptr[9].__vecDelDtor)(
          this,
          vehicle,
          v5,
          v10);
      else
        ((void (__fastcall *)(hkpVehicleLinearCastWheelCollide *, hkpVehicleInstance *, _QWORD, char *, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))vfptr[8].__first_virtual_table_function__)(
          this,
          vehicle,
          v5,
          v13,
          v10);
      ((void (__fastcall *)(hkpVehicleLinearCastWheelCollide *, hkpVehicleInstance *, _QWORD, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))this->vfptr[5].__first_virtual_table_function__)(
        this,
        vehicle,
        v5++,
        v10);
    }
    while ( v5 < m_numWheels );
  }
}

// File Line: 178
// RVA: 0xE295B0
void __fastcall hkpVehicleLinearCastWheelCollide::updateBeforeCollisionDetection(
        hkpVehicleLinearCastWheelCollide *this,
        hkpVehicleInstance *vehicle)
{
  int m_size; // ebp
  unsigned __int8 i; // bl
  hkAabb aabbOut; // [rsp+20h] [rbp-28h] BYREF

  m_size = this->m_wheelStates.m_size;
  for ( i = 0; i < m_size; ++i )
  {
    hkpVehicleLinearCastWheelCollide::updateWheelState(this, vehicle, i);
    hkpVehicleLinearCastWheelCollide::calcAabbOfWheel(this, vehicle, i, &aabbOut);
    hkpAabbPhantom::setAabb(this->m_wheelStates.m_data[i].m_phantom, &aabbOut);
  }
}

// File Line: 202
// RVA: 0xE29650
hkpVehicleWheelCollide *__fastcall hkpVehicleLinearCastWheelCollide::clone(
        hkpVehicleLinearCastWheelCollide *this,
        hkpRigidBody *newChassis,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  _QWORD **Value; // rax
  hkpVehicleLinearCastWheelCollide *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbp
  int m_size; // r12d
  int v10; // eax
  int v11; // eax
  int v12; // r9d
  unsigned __int8 v13; // r15
  __int64 v14; // rbx
  unsigned __int64 v15; // rsi
  hkpShape *m_shape; // rcx
  hkpPhantom *v17; // rdi
  hkpPhantomOverlapListener *v18; // rdx
  hkpPhantomOverlapListener *v19; // rdx
  hkpLinkedCollidable *result; // [rsp+70h] [rbp+8h] BYREF
  hkArray<hkpPhantom *,hkContainerHeapAllocator> *v22; // [rsp+80h] [rbp+18h]

  v22 = newPhantoms;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpVehicleLinearCastWheelCollide *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                             Value[11],
                                             88i64);
  if ( v6 )
  {
    hkpVehicleLinearCastWheelCollide::hkpVehicleLinearCastWheelCollide(v6);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  m_size = this->m_wheelStates.m_size;
  v10 = *(_DWORD *)(v8 + 44) & 0x3FFFFFFF;
  if ( v10 < m_size )
  {
    v11 = 2 * v10;
    v12 = this->m_wheelStates.m_size;
    if ( m_size < v11 )
      v12 = v11;
    hkArrayUtil::_reserve((hkResult *)&result, &hkContainerHeapAllocator::s_alloc, (const void **)(v8 + 32), v12, 96);
  }
  v13 = 0;
  *(_DWORD *)(v8 + 40) = m_size;
  if ( m_size > 0 )
  {
    result = &newChassis->m_collidable;
    do
    {
      v14 = *(_QWORD *)(v8 + 32);
      v15 = 96i64 * v13;
      m_shape = this->m_wheelStates.m_data[v15 / 0x60].m_shape;
      *(_QWORD *)(v15 + v14 + 8) = m_shape;
      hkReferencedObject::addReference(m_shape);
      v17 = v22->m_data[v13];
      *(_QWORD *)(v15 + v14) = v17;
      hkReferencedObject::addReference(v17);
      if ( this == (hkpVehicleLinearCastWheelCollide *)-48i64 )
        v18 = 0i64;
      else
        v18 = &this->m_rejectChassisListener.hkpPhantomOverlapListener;
      hkpPhantom::removePhantomOverlapListener(v17, v18);
      if ( v8 == -48 )
        v19 = 0i64;
      else
        v19 = (hkpPhantomOverlapListener *)(v8 + 64);
      hkpPhantom::addPhantomOverlapListener(v17, v19);
      ++v13;
      *(_QWORD *)(v8 + 72) = result;
    }
    while ( v13 < m_size );
  }
  *(_DWORD *)(v8 + 24) = this->m_wheelCollisionFilterInfo;
  *(float *)(v8 + 80) = this->m_maxExtraPenetration;
  *(float *)(v8 + 84) = this->m_startPointTolerance;
  return (hkpVehicleWheelCollide *)v8;
}

// File Line: 281
// RVA: 0xE29A50
__int64 __fastcall hkpVehicleLinearCastWheelCollide::getTotalNumCommands(hkpVehicleLinearCastWheelCollide *this)
{
  int m_size; // ebp
  unsigned int v2; // edi
  unsigned __int8 i; // bl
  int v5; // eax

  m_size = this->m_wheelStates.m_size;
  v2 = 0;
  for ( i = 0; i < m_size; v2 += v5 )
    v5 = ((__int64 (__fastcall *)(hkpVehicleLinearCastWheelCollide *, _QWORD))this->vfptr[6].__first_virtual_table_function__)(
           this,
           i++);
  return v2;
}

// File Line: 293
// RVA: 0xE29AB0
__int64 __fastcall hkpVehicleLinearCastWheelCollide::getNumCommands(
        hkpVehicleLinearCastWheelCollide *this,
        unsigned __int8 numWheel)
{
  hkpAabbPhantom *m_phantom; // rbx

  m_phantom = this->m_wheelStates.m_data[numWheel].m_phantom;
  m_phantom->vfptr[5].__first_virtual_table_function__(m_phantom);
  return (unsigned int)m_phantom->m_overlappingCollidables.m_size;
}

// File Line: 301
// RVA: 0xE29AF0
__int64 __fastcall hkpVehicleLinearCastWheelCollide::buildLinearCastCommands(
        hkpVehicleLinearCastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        hkpAabbPhantom *collisionFilter,
        hkpCollidable *collidableStorage,
        hkpPairLinearCastCommand *commandStorage,
        hkpRootCdPoint *outputStorage)
{
  int m_size; // ebx
  char v7; // bp
  unsigned int v8; // r13d
  unsigned int *p_m_collisionFilterInfo; // rsi
  hkpCollidable *v12; // r15
  hkpVehicleLinearCastWheelCollide::WheelState *v13; // r14
  hkpShape *m_shape; // rax
  int v15; // r9d
  hkpCollidable *v16; // rcx
  hkVector4f v17; // xmm1
  int v19; // [rsp+20h] [rbp-38h]
  hkpVehicleLinearCastWheelCollide *v20; // [rsp+60h] [rbp+8h]

  v20 = this;
  m_size = this->m_wheelStates.m_size;
  v7 = 0;
  v8 = 0;
  v19 = m_size;
  if ( m_size > 0 )
  {
    p_m_collisionFilterInfo = &collidableStorage->m_broadPhaseHandle.m_collisionFilterInfo;
    do
    {
      v12 = (hkpCollidable *)(p_m_collisionFilterInfo - 11);
      v13 = &this->m_wheelStates.m_data[v7];
      if ( p_m_collisionFilterInfo != (unsigned int *)44 )
      {
        m_shape = v13->m_shape;
        *(_QWORD *)(p_m_collisionFilterInfo - 5) = 0i64;
        *(p_m_collisionFilterInfo - 9) = -1;
        v12->m_shape = m_shape;
        *((_BYTE *)p_m_collisionFilterInfo - 12) = 0;
        *(_QWORD *)(p_m_collisionFilterInfo - 7) = &v13->m_transform;
        *((_WORD *)p_m_collisionFilterInfo - 2) = 32512;
        *p_m_collisionFilterInfo = 0;
        *((_BYTE *)p_m_collisionFilterInfo - 2) = -1;
        *(p_m_collisionFilterInfo - 2) = 0;
        hkpCollidable::BoundingVolumeData::BoundingVolumeData((hkpCollidable::BoundingVolumeData *)(p_m_collisionFilterInfo
                                                                                                  + 1));
        m_size = v19;
        p_m_collisionFilterInfo[15] = -1082130432;
        *((_BYTE *)p_m_collisionFilterInfo - 3) = -36;
        *((_BYTE *)p_m_collisionFilterInfo - 11) = 8;
        *((_WORD *)p_m_collisionFilterInfo - 5) = 0;
      }
      ((void (__fastcall *)(hkpAabbPhantom *, hkpVehicleInstance *, hkpAabbPhantom *))v13->m_phantom->vfptr[5].__first_virtual_table_function__)(
        v13->m_phantom,
        vehicle,
        collisionFilter);
      collisionFilter = v13->m_phantom;
      LOBYTE(vehicle) = 0;
      v15 = v13->m_phantom->m_overlappingCollidables.m_size;
      if ( v15 > 0 )
      {
        do
        {
          commandStorage->m_collidableA = v12;
          v16 = collisionFilter->m_overlappingCollidables.m_data[(char)vehicle];
          LOBYTE(vehicle) = (_BYTE)vehicle + 1;
          ++commandStorage;
          commandStorage[-1].m_collidableB = v16;
          ++v8;
          commandStorage[-1].m_from = v13->m_transform.m_translation;
          v17.m_quad = (__m128)v13->m_to;
          commandStorage[-1].m_results = outputStorage;
          *(_QWORD *)&commandStorage[-1].m_resultsCapacity = 1i64;
          commandStorage[-1].m_startPointResultsCapacity = 0;
          ++outputStorage;
          commandStorage[-1].m_to = (hkVector4f)v17.m_quad;
        }
        while ( (char)vehicle < v15 );
      }
      ++v7;
      p_m_collisionFilterInfo += 28;
      this = v20;
    }
    while ( v7 < m_size );
  }
  return v8;
}

// File Line: 339
// RVA: 0xE29FA0
hkBool *__fastcall hkpVehicleLinearCastWheelCollide::castSingleWheel(
        hkpVehicleLinearCastWheelCollide *this,
        hkBool *result,
        hkpVehicleInstance *vehicle,
        unsigned __int8 wheelNum,
        hkpRootCdPoint *linearCastOutput)
{
  hkpVehicleLinearCastWheelCollide::WheelState *v7; // rdi
  hkpShape *m_shape; // rax
  float m_maxExtraPenetration; // xmm0_4
  char v10; // sp
  char v11; // al
  hkVector4f v12; // xmm1
  hkpCollidable *v13; // rax
  hkVector4f v14; // xmm0
  hkVector4f v15; // xmm1
  hkpLinearCastInput input; // [rsp+30h] [rbp-D0h] BYREF
  hkpCollidable toBeCast; // [rsp+50h] [rbp-B0h] BYREF
  hkpCdPointCollector castCollector; // [rsp+C0h] [rbp-40h] BYREF
  __m128 v20; // [rsp+D0h] [rbp-30h]
  __m128 v21; // [rsp+E0h] [rbp-20h]
  hkpCollidable *v22; // [rsp+F0h] [rbp-10h]
  unsigned int v23; // [rsp+F8h] [rbp-8h]
  hkpCollidable *v24; // [rsp+100h] [rbp+0h]
  unsigned int v25; // [rsp+108h] [rbp+8h]

  v7 = &this->m_wheelStates.m_data[wheelNum];
  m_shape = v7->m_shape;
  toBeCast.m_parent = 0i64;
  toBeCast.m_shapeKey = -1;
  toBeCast.m_shape = m_shape;
  toBeCast.m_ownerOffset = 0;
  toBeCast.m_broadPhaseHandle.m_id = 0;
  *(_WORD *)&toBeCast.m_broadPhaseHandle.m_type = 32512;
  toBeCast.m_broadPhaseHandle.m_collisionFilterInfo = 0;
  toBeCast.m_motion = &v7->m_transform;
  toBeCast.m_broadPhaseHandle.m_objectQualityType = -1;
  hkpCollidable::BoundingVolumeData::BoundingVolumeData(&toBeCast.m_boundingVolumeData);
  toBeCast.m_allowedPenetrationDepth = FLOAT_N1_0;
  m_maxExtraPenetration = this->m_maxExtraPenetration;
  input.m_maxExtraPenetration = 0.00000011920929;
  input.m_startPointTolerance = 0.00000011920929;
  v11 = v10 + 80;
  toBeCast.m_forceCollideOntoPpu = 8;
  toBeCast.m_shapeSizeOnSpu = 0;
  toBeCast.m_broadPhaseHandle.m_ownerOffset = v11 - (v10 + 116);
  toBeCast.m_broadPhaseHandle.m_collisionFilterInfo = this->m_wheelCollisionFilterInfo;
  v12.m_quad = (__m128)v7->m_to;
  input.m_maxExtraPenetration = m_maxExtraPenetration;
  input.m_to = (hkVector4f)v12.m_quad;
  castCollector.vfptr = (hkpCdPointCollectorVtbl *)&hkpClosestCdPointCollector::`vftable;
  v22 = 0i64;
  input.m_startPointTolerance = this->m_startPointTolerance;
  castCollector.m_earlyOutDistance = FLOAT_3_40282e38;
  v21 = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, (__m128)xmmword_141A712A0), 196);
  hkpAabbPhantom::linearCast(v7->m_phantom, &toBeCast, &input, &castCollector, 0i64);
  v13 = v22;
  if ( v22 )
  {
    v14.m_quad = v20;
    v15.m_quad = v21;
    result->m_bool = 1;
    linearCastOutput->m_contact.m_position = (hkVector4f)v14.m_quad;
    linearCastOutput->m_contact.m_separatingNormal = (hkVector4f)v15.m_quad;
    linearCastOutput->m_rootCollidableA = v13;
    linearCastOutput->m_shapeKeyA = v23;
    linearCastOutput->m_rootCollidableB = v24;
    linearCastOutput->m_shapeKeyB = v25;
  }
  else
  {
    result->m_bool = 0;
  }
  return result;
}

// File Line: 386
// RVA: 0xE29C80
hkpRootCdPoint *__fastcall hkpVehicleLinearCastWheelCollide::determineNearestHit(
        hkpVehicleLinearCastWheelCollide *this,
        __int64 numWheel,
        hkpPairLinearCastCommand *commandStorageOutput)
{
  int v4; // eax
  __m128 *v5; // rdx
  __int64 v6; // r9
  hkpRootCdPoint **p_m_results; // rcx

  v4 = ((__int64 (__fastcall *)(hkpVehicleLinearCastWheelCollide *, __int64))this->vfptr[6].__first_virtual_table_function__)(
         this,
         numWheel);
  v5 = 0i64;
  v6 = v4;
  if ( v4 > 0 )
  {
    p_m_results = &commandStorageOutput->m_results;
    do
    {
      if ( *((_DWORD *)p_m_results + 3)
        && (!v5
         || _mm_shuffle_ps(
              (*p_m_results)->m_contact.m_separatingNormal.m_quad,
              (*p_m_results)->m_contact.m_separatingNormal.m_quad,
              255).m128_f32[0] < _mm_shuffle_ps(v5[1], v5[1], 255).m128_f32[0]) )
      {
        v5 = (__m128 *)*p_m_results;
      }
      p_m_results += 10;
      --v6;
    }
    while ( v6 );
  }
  return (hkpRootCdPoint *)v5;
}

// File Line: 408
// RVA: 0xE2A130
void __fastcall hkpVehicleLinearCastWheelCollide::getCollisionOutputFromCastResult(
        hkpVehicleLinearCastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        unsigned __int8 wheelNum,
        hkpRootCdPoint *linearCastOutput,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *output)
{
  hkpVehicleInstance::WheelInfo *v5; // r10
  float m_length; // xmm1_4
  hkpCollidable *m_rootCollidableB; // rcx
  hkpRigidBody *v8; // rax
  unsigned int m_shapeKeyB; // eax
  hkVector4f v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm5
  hkpEntity *m_entity; // rcx
  hkpRigidBody *m_contactBody; // rax
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  __m128 v20; // xmm4
  float v21; // xmm6_4

  v5 = &vehicle->m_wheelsInfo.m_data[wheelNum];
  m_length = vehicle->m_suspension->m_wheelParams.m_data[wheelNum].m_length;
  output->m_contactPoint.m_position = linearCastOutput->m_contact.m_position;
  output->m_contactPoint.m_separatingNormal = linearCastOutput->m_contact.m_separatingNormal;
  m_rootCollidableB = linearCastOutput->m_rootCollidableB;
  if ( m_rootCollidableB->m_broadPhaseHandle.m_type == 1 )
    v8 = (hkpRigidBody *)((char *)m_rootCollidableB + m_rootCollidableB->m_ownerOffset);
  else
    v8 = 0i64;
  output->m_contactBody = v8;
  output->m_contactFriction = v8->m_material.m_friction;
  m_shapeKeyB = linearCastOutput->m_shapeKeyB;
  output->m_contactShapeKey[1] = -1;
  output->m_contactShapeKey[0] = m_shapeKeyB;
  v10.m_quad = (__m128)output->m_contactPoint.m_separatingNormal;
  output->m_currentSuspensionLength = m_length * linearCastOutput->m_contact.m_separatingNormal.m_quad.m128_f32[3];
  v11 = _mm_mul_ps(v5->m_suspensionDirectionWs.m_quad, v10.m_quad);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  if ( v12.m128_f32[0] >= (float)(0.0
                                - _mm_shuffle_ps(
                                    (__m128)LODWORD(vehicle->m_data->m_normalClippingAngleCos),
                                    (__m128)LODWORD(vehicle->m_data->m_normalClippingAngleCos),
                                    0).m128_f32[0]) )
  {
    output->m_suspensionClosingSpeed = 0.0;
    output->m_suspensionScalingFactor = 1.0 / vehicle->m_data->m_normalClippingAngleCos;
  }
  else
  {
    m_entity = vehicle->m_entity;
    m_contactBody = output->m_contactBody;
    v15 = _mm_sub_ps(
            output->m_contactPoint.m_position.m_quad,
            m_contactBody->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
    v16 = _mm_sub_ps(
            output->m_contactPoint.m_position.m_quad,
            m_entity->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
    v17 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), m_entity->m_motion.m_angularVelocity.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(
                m_entity->m_motion.m_angularVelocity.m_quad,
                m_entity->m_motion.m_angularVelocity.m_quad,
                201),
              v16));
    v18 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), m_contactBody->m_motion.m_angularVelocity.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(
                m_contactBody->m_motion.m_angularVelocity.m_quad,
                m_contactBody->m_motion.m_angularVelocity.m_quad,
                201),
              v15));
    v19 = _mm_sub_ps(
            _mm_add_ps(_mm_shuffle_ps(v17, v17, 201), m_entity->m_motion.m_linearVelocity.m_quad),
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), m_contactBody->m_motion.m_linearVelocity.m_quad));
    v18.m128_f32[0] = _mm_rcp_ps(v12).m128_f32[0];
    v20 = _mm_mul_ps(v19, v10.m_quad);
    v21 = 0.0 - (float)((float)(2.0 - (float)(v18.m128_f32[0] * v12.m128_f32[0])) * v18.m128_f32[0]);
    output->m_suspensionScalingFactor = v21;
    output->m_suspensionClosingSpeed = v21
                                     * (float)((float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0]
                                                     + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
                                             + _mm_shuffle_ps(v20, v20, 170).m128_f32[0]);
  }
}

// File Line: 453
// RVA: 0xE2A2F0
void __fastcall hkpVehicleLinearCastWheelCollide::getCollisionOutputWithoutHit(
        hkpVehicleLinearCastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        unsigned __int8 wheelNum,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  hkpVehicleInstance::WheelInfo *v4; // r10
  float m_length; // xmm3_4
  __m128 v6; // xmm2

  v4 = &vehicle->m_wheelsInfo.m_data[wheelNum];
  m_length = vehicle->m_suspension->m_wheelParams.m_data[wheelNum].m_length;
  cdInfo->m_currentSuspensionLength = m_length;
  cdInfo->m_contactBody = 0i64;
  cdInfo->m_suspensionClosingSpeed = 0.0;
  cdInfo->m_contactPoint.m_position = v4->m_rayEndPointWs;
  v6 = _mm_xor_ps(
         (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0),
         v4->m_suspensionDirectionWs.m_quad);
  cdInfo->m_contactPoint.m_separatingNormal.m_quad = _mm_shuffle_ps(
                                                       v6,
                                                       _mm_unpackhi_ps(
                                                         v6,
                                                         cdInfo->m_contactPoint.m_separatingNormal.m_quad),
                                                       196);
  cdInfo->m_contactFriction = 0.0;
  cdInfo->m_suspensionScalingFactor = 1.0;
  cdInfo->m_contactPoint.m_separatingNormal.m_quad.m128_f32[3] = m_length;
}

// File Line: 471
// RVA: 0xE29EC0
void __fastcall hkpVehicleLinearCastWheelCollide::calcAabbOfWheel(
        hkpVehicleLinearCastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        unsigned __int8 wheelNum,
        hkAabb *aabbOut)
{
  hkpVehicleData::WheelComponentParams *m_data; // rdx
  hkpVehicleLinearCastWheelCollide::WheelState *v5; // rax
  __int64 v6; // r10
  __int64 v7; // r8
  __m128 m_width_low; // xmm0
  __m128 v9; // xmm5
  __m128 m_quad; // xmm3
  __m128 v11; // xmm2

  m_data = vehicle->m_data->m_wheelParams.m_data;
  v5 = this->m_wheelStates.m_data;
  v6 = wheelNum;
  v7 = wheelNum;
  m_width_low = (__m128)LODWORD(m_data[v7].m_width);
  m_width_low.m128_f32[0] = m_width_low.m128_f32[0] * 0.5;
  v9 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(m_data[v7].m_radius), m_width_low),
         _mm_unpacklo_ps((__m128)LODWORD(m_data[v7].m_radius), (__m128)0i64));
  m_quad = v5[v6].m_to.m_quad;
  v11 = _mm_add_ps(
          _mm_add_ps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v5[v6].m_transform.m_rotation.m_col1.m_quad),
                        1u),
                      1u),
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), v5[v6].m_transform.m_rotation.m_col0.m_quad),
                        1u),
                      1u)),
          _mm_add_ps(
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), v5[v6].m_transform.m_rotation.m_col2.m_quad),
                        1u),
                      1u),
            ::aabbOut.m_quad));
  aabbOut->m_max.m_quad = _mm_add_ps(m_quad, v11);
  aabbOut->m_min.m_quad = _mm_add_ps(
                            _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v11),
                            m_quad);
}

// File Line: 489
// RVA: 0xE29CE0
void __fastcall hkpVehicleLinearCastWheelCollide::updateWheelState(
        hkpVehicleLinearCastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        unsigned __int8 wheelNum)
{
  __int64 v3; // rdi
  hkQuaternionf v5; // xmm6
  hkpVehicleData *m_data; // rax
  hkpVehicleInstance::WheelInfo *v7; // r14
  hkpVehicleLinearCastWheelCollide::WheelState *v8; // rbp
  __m128 v9; // xmm4
  __m128 m_quad; // xmm2
  __m128 v11; // xmm0
  __m128 v12; // xmm5
  __m128 v13; // xmm3
  __m128 v14; // xmm6
  __m128 v15; // xmm3
  __m128 v16; // xmm3
  __m128 v17; // xmm5
  __m128 v18; // xmm6
  __m128 v19; // xmm3
  __m128 v20; // xmm4
  __m128 v21; // xmm6
  __m128 m_length_low; // xmm0
  hkQuaternionf qi; // [rsp+20h] [rbp-68h] BYREF
  hkQuaternionf v24; // [rsp+30h] [rbp-58h] BYREF
  hkRotationf r; // [rsp+40h] [rbp-48h] BYREF

  v3 = wheelNum;
  v5.m_vec.m_quad = (__m128)vehicle->m_entity->m_motion.m_motionState.m_sweptTransform.m_rotation1;
  m_data = vehicle->m_data;
  v7 = &vehicle->m_wheelsInfo.m_data[wheelNum];
  v8 = &this->m_wheelStates.m_data[wheelNum];
  v9 = _mm_shuffle_ps(v5.m_vec.m_quad, v5.m_vec.m_quad, 255);
  m_quad = v7->m_steeringOrientationChassisSpace.m_vec.m_quad;
  v11 = _mm_mul_ps(_mm_shuffle_ps(v5.m_vec.m_quad, v5.m_vec.m_quad, 201), m_quad);
  v12 = _mm_shuffle_ps(m_quad, m_quad, 255);
  v13 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v5.m_vec.m_quad);
  v14 = _mm_mul_ps(v5.m_vec.m_quad, m_quad);
  v15 = _mm_sub_ps(v13, v11);
  v16 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v15, v15, 201), _mm_mul_ps(m_quad, v9)),
          _mm_mul_ps(vehicle->m_entity->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad, v12));
  qi.m_vec.m_quad = _mm_shuffle_ps(
                      v16,
                      _mm_unpackhi_ps(
                        v16,
                        _mm_sub_ps(
                          _mm_mul_ps(v12, v9),
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v14, v14, 85), _mm_shuffle_ps(v14, v14, 0)),
                            _mm_shuffle_ps(v14, v14, 170)))),
                      196);
  r.m_col0 = m_data->m_chassisOrientation.m_col1;
  r.m_col1 = m_data->m_chassisOrientation.m_col0;
  r.m_col2 = m_data->m_chassisOrientation.m_col2;
  hkQuaternionf::set(&v24, &r);
  v17 = _mm_shuffle_ps(v24.m_vec.m_quad, v24.m_vec.m_quad, 255);
  v18 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v24.m_vec.m_quad, v24.m_vec.m_quad, 201), qi.m_vec.m_quad),
          _mm_mul_ps(_mm_shuffle_ps(qi.m_vec.m_quad, qi.m_vec.m_quad, 201), v24.m_vec.m_quad));
  v19 = _mm_mul_ps(v24.m_vec.m_quad, qi.m_vec.m_quad);
  v20 = _mm_shuffle_ps(qi.m_vec.m_quad, qi.m_vec.m_quad, 255);
  v21 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), _mm_mul_ps(v24.m_vec.m_quad, v20)),
          _mm_mul_ps(qi.m_vec.m_quad, v17));
  qi.m_vec.m_quad = _mm_shuffle_ps(
                      v21,
                      _mm_unpackhi_ps(
                        v21,
                        _mm_sub_ps(
                          _mm_mul_ps(v17, v20),
                          _mm_add_ps(
                            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                            _mm_shuffle_ps(v19, v19, 170)))),
                      196);
  hkRotationf::set(&v8->m_transform.m_rotation, &qi);
  v8->m_transform.m_translation = v7->m_hardPointWs;
  m_length_low = (__m128)LODWORD(vehicle->m_suspension->m_wheelParams.m_data[v3].m_length);
  v8->m_to.m_quad = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(m_length_low, m_length_low, 0), v7->m_suspensionDirectionWs.m_quad),
                      v7->m_hardPointWs.m_quad);
}

// File Line: 509
// RVA: 0xE29510
void __fastcall hkpVehicleLinearCastWheelCollide::getPhantoms(
        hkpVehicleLinearCastWheelCollide *this,
        hkArray<hkpPhantom *,hkContainerHeapAllocator> *phantomsOut)
{
  __int64 m_size; // rsi
  __int64 v5; // rdi
  hkpAabbPhantom *m_phantom; // rbp

  m_size = this->m_wheelStates.m_size;
  if ( m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      m_phantom = this->m_wheelStates.m_data[v5].m_phantom;
      if ( phantomsOut->m_size == (phantomsOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&phantomsOut->m_data, 8);
      ++v5;
      phantomsOut->m_data[phantomsOut->m_size++] = m_phantom;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 519
// RVA: 0xE297C0
void __fastcall hkpVehicleLinearCastWheelCollide::addToWorld(hkpVehicleLinearCastWheelCollide *this, hkpWorld *world)
{
  __int64 m_size; // rdi
  __int64 v5; // rbx

  m_size = this->m_wheelStates.m_size;
  if ( m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      hkpWorld::addPhantom(world, this->m_wheelStates.m_data[v5++].m_phantom);
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 529
// RVA: 0xE29830
void __fastcall hkpVehicleLinearCastWheelCollide::removeFromWorld(hkpVehicleLinearCastWheelCollide *this)
{
  __int64 m_size; // rdi
  __int64 v3; // rbx

  m_size = this->m_wheelStates.m_size;
  if ( m_size > 0 )
  {
    v3 = 0i64;
    do
    {
      hkpWorld::removePhantom(
        this->m_wheelStates.m_data[v3].m_phantom->m_world,
        this->m_wheelStates.m_data[v3].m_phantom);
      ++v3;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 541
// RVA: 0xE29890
void __fastcall hkpVehicleLinearCastWheelCollide::setCollisionFilterInfo(
        hkpVehicleLinearCastWheelCollide *this,
        unsigned int filterInfo)
{
  __int64 m_size; // r9
  __int64 v4; // r8
  hkpAabbPhantom *m_phantom; // rdx

  m_size = this->m_wheelStates.m_size;
  this->m_wheelCollisionFilterInfo = filterInfo;
  if ( m_size > 0 )
  {
    v4 = 0i64;
    do
    {
      m_phantom = this->m_wheelStates.m_data[v4].m_phantom;
      if ( m_phantom )
        m_phantom->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = filterInfo;
      ++v4;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 556
// RVA: 0xE298D0
// attributes: thunk
void __fastcall hkpVehicleLinearCastWheelCollide::wheelCollideCallback(
        hkpVehicleLinearCastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        char wheelIndex,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  hkpVehicleLinearCastWheelCollide::centerWheelContactPoint(this, vehicle, wheelIndex, cdInfo);
}

// File Line: 562
// RVA: 0xE298E0
void __fastcall hkpVehicleLinearCastWheelCollide::centerWheelContactPoint(
        hkpVehicleLinearCastWheelCollide *this,
        hkpVehicleInstance *vehicle,
        unsigned __int8 wheelIndex,
        hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  hkpVehicleLinearCastWheelCollide::WheelState *v5; // rbx
  hkVector4f b; // [rsp+20h] [rbp-28h] BYREF
  hkVector4f v7; // [rsp+30h] [rbp-18h] BYREF

  v5 = &this->m_wheelStates.m_data[wheelIndex];
  hkVector4f::setTransformedInversePos(&b, &v5->m_transform, &cdInfo->m_contactPoint.m_position);
  b.m_quad = _mm_shuffle_ps(b.m_quad, _mm_unpackhi_ps(b.m_quad, (__m128)0i64), 180);
  hkVector4f::setTransformedPos(&v7, &v5->m_transform, &b);
  cdInfo->m_contactPoint.m_position = (hkVector4f)v7.m_quad;
}

