// File Line: 40
// RVA: 0xE290C0
void __fastcall hkpVehicleLinearCastWheelCollide::hkpVehicleLinearCastWheelCollide(hkpVehicleLinearCastWheelCollide *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->m_alreadyUsed.m_bool = 0;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleLinearCastWheelCollide::`vftable;
  this->m_wheelStates.m_capacityAndFlags = 2147483648;
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
void __fastcall hkpVehicleLinearCastWheelCollide::setWheelShapes(hkpVehicleLinearCastWheelCollide *this, hkpVehicleInstance *vehicle, hkArray<hkpShape *,hkContainerHeapAllocator> *shapes)
{
  hkArray<hkpVehicleLinearCastWheelCollide::WheelState,hkContainerHeapAllocator> *v3; // rsi
  hkArray<hkpShape *,hkContainerHeapAllocator> *v4; // r14
  signed int v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // er9
  unsigned __int8 v9; // bl
  signed __int64 v10; // r10
  hkResult result; // [rsp+40h] [rbp+8h]

  v3 = &this->m_wheelStates;
  v4 = shapes;
  v5 = (unsigned __int8)vehicle->m_data->m_numWheels;
  v6 = this->m_wheelStates.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < v5 )
  {
    v7 = 2 * v6;
    v8 = (unsigned __int8)vehicle->m_data->m_numWheels;
    if ( v5 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v8, 96);
  }
  v9 = 0;
  for ( v3->m_size = v5; v9 < v5; ++v9 )
  {
    v10 = v9;
    v3->m_data[v9].m_shape = v4->m_data[v10];
    hkReferencedObject::addReference((hkReferencedObject *)&v4->m_data[v10]->vfptr);
  }
}

// File Line: 65
// RVA: 0xE293A0
int hkpVehicleLinearCastWheelCollide::createWheelShape(...)
{
  _QWORD **v3; // rax
  hkpCylinderShape *v4; // rax
  hkVector4f vertexB; // [rsp+30h] [rbp-48h]
  hkVector4f vertexA; // [rsp+40h] [rbp-38h]

  *(float *)&width = *(float *)&width * 0.5;
  vertexA.m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)0i64, (__m128)width), (__m128)0i64);
  vertexB.m_quad = _mm_xor_ps(
                     (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 64),
                     vertexA.m_quad);
  v3 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v4 = (hkpCylinderShape *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v3[11] + 8i64))(v3[11], 112i64);
  if ( v4 )
    hkpCylinderShape::hkpCylinderShape(v4, &vertexA, &vertexB, radius, 0.0);
}

// File Line: 79
// RVA: 0xE29210
void __fastcall hkpVehicleLinearCastWheelCollide::init(hkpVehicleLinearCastWheelCollide *this, hkpVehicleInstance *vehicle)
{
  hkpVehicleInstance *v2; // r15
  signed int v3; // esi
  hkpVehicleLinearCastWheelCollide *v4; // rdi
  int v5; // eax
  int v6; // eax
  int v7; // er9
  unsigned __int8 v8; // bp
  signed __int64 v9; // rbx
  hkpCylinderShape *v10; // rax
  unsigned __int8 v11; // bl
  _QWORD **v12; // rax
  hkpAabbPhantom *v13; // rax
  hkpAabbPhantom *v14; // rax
  hkpAabbPhantom *v15; // rcx
  signed __int64 v16; // r8
  hkpPhantomOverlapListener *v17; // rdx
  hkAabb aabbOut; // [rsp+30h] [rbp-38h]
  hkResult result; // [rsp+70h] [rbp+8h]

  v2 = vehicle;
  v3 = (unsigned __int8)vehicle->m_data->m_numWheels;
  v4 = this;
  if ( !this->m_wheelStates.m_size )
  {
    v5 = this->m_wheelStates.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v5 < v3 )
    {
      v6 = 2 * v5;
      v7 = (unsigned __int8)vehicle->m_data->m_numWheels;
      if ( v3 < v6 )
        v7 = v6;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &this->m_wheelStates,
        v7,
        96);
    }
    v8 = 0;
    for ( v4->m_wheelStates.m_size = v3; v8 < v3; *(_QWORD *)(v9 + 8) = v10 )
    {
      v9 = (signed __int64)&v4->m_wheelStates.m_data[v8];
      v10 = hkpVehicleLinearCastWheelCollide::createWheelShape(
              v4,
              v2->m_data->m_wheelParams.m_data[v8].m_width,
              v2->m_data->m_wheelParams.m_data[v8].m_radius);
      ++v8;
    }
  }
  v11 = 0;
  for ( v4->m_rejectChassisListener.m_chassis = (hkpCollidable *)&v2->m_entity->m_collidable.m_shape; v11 < v3; ++v11 )
  {
    hkpVehicleLinearCastWheelCollide::updateWheelState(v4, v2, v11);
    hkpVehicleLinearCastWheelCollide::calcAabbOfWheel(v4, v2, v11, &aabbOut);
    v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (hkpAabbPhantom *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(v12[11], 304i64);
    if ( v13 )
    {
      hkpAabbPhantom::hkpAabbPhantom(v13, &aabbOut, v4->m_wheelCollisionFilterInfo);
      v15 = v14;
    }
    else
    {
      v15 = 0i64;
    }
    v16 = v11;
    v4->m_wheelStates.m_data[v16].m_phantom = v15;
    if ( v4 == (hkpVehicleLinearCastWheelCollide *)-48i64 )
      v17 = 0i64;
    else
      v17 = (hkpPhantomOverlapListener *)&v4->m_rejectChassisListener.vfptr;
    hkpPhantom::addPhantomOverlapListener((hkpPhantom *)&v4->m_wheelStates.m_data[v16].m_phantom->vfptr, v17);
  }
}

// File Line: 136
// RVA: 0xE29120
void __fastcall hkpVehicleLinearCastWheelCollide::~hkpVehicleLinearCastWheelCollide(hkpVehicleLinearCastWheelCollide *this)
{
  __int64 v1; // rbp
  hkpVehicleLinearCastWheelCollide *v2; // rbx
  __int64 v3; // rsi
  hkpVehicleLinearCastWheelCollide::WheelState *v4; // rdi
  hkpPhantom *v5; // rdi
  hkpPhantomOverlapListener *v6; // rdx
  int v7; // eax

  v1 = this->m_wheelStates.m_size;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleLinearCastWheelCollide::`vftable;
  if ( v1 > 0 )
  {
    v3 = 0i64;
    do
    {
      v4 = v2->m_wheelStates.m_data;
      hkReferencedObject::removeReference((hkReferencedObject *)&v4[v3].m_shape->vfptr);
      v5 = (hkpPhantom *)&v4[v3].m_phantom->vfptr;
      if ( v2->m_memSizeAndFlags && v5->m_memSizeAndFlags )
      {
        if ( v2 == (hkpVehicleLinearCastWheelCollide *)-48i64 )
          v6 = 0i64;
        else
          v6 = (hkpPhantomOverlapListener *)&v2->m_rejectChassisListener.vfptr;
        hkpPhantom::removePhantomOverlapListener(v5, v6);
      }
      hkReferencedObject::removeReference((hkReferencedObject *)&v5->vfptr);
      ++v3;
      --v1;
    }
    while ( v1 );
  }
  hkpRejectChassisListener::~hkpRejectChassisListener(&v2->m_rejectChassisListener);
  v7 = v2->m_wheelStates.m_capacityAndFlags;
  v2->m_wheelStates.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_wheelStates.m_data,
      96 * (v7 & 0x3FFFFFFF));
  v2->m_wheelStates.m_data = 0i64;
  v2->m_wheelStates.m_capacityAndFlags = 2147483648;
  v2->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 156
// RVA: 0xE29960
void __fastcall hkpVehicleLinearCastWheelCollide::collideWheels(hkpVehicleLinearCastWheelCollide *this, const float deltaTime, hkpVehicleInstance *vehicle, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfoOut)
{
  unsigned __int8 v4; // di
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v5; // r15
  signed int v6; // er14
  hkpVehicleInstance *v7; // rbp
  hkpVehicleLinearCastWheelCollide *v8; // rbx
  signed __int64 v9; // rsi
  bool v10; // zf
  hkBaseObjectVtbl *v11; // rax
  char v12; // [rsp+30h] [rbp-58h]
  char v13; // [rsp+A0h] [rbp+18h]

  v4 = 0;
  v5 = cdInfoOut;
  v6 = (unsigned __int8)vehicle->m_data->m_numWheels;
  v7 = vehicle;
  v8 = this;
  if ( v6 > 0 )
  {
    do
    {
      v9 = (signed __int64)&v5[v4];
      v10 = *(_BYTE *)((__int64 (__fastcall *)(hkpVehicleLinearCastWheelCollide *, char *, hkpVehicleInstance *, _QWORD, char *))v8->vfptr[8].__vecDelDtor)(
                        v8,
                        &v13,
                        v7,
                        v4,
                        &v12) == 0;
      v11 = v8->vfptr;
      if ( v10 )
        ((void (__fastcall *)(hkpVehicleLinearCastWheelCollide *, hkpVehicleInstance *, _QWORD, signed __int64))v11[9].__vecDelDtor)(
          v8,
          v7,
          v4,
          v9);
      else
        ((void (__fastcall *)(hkpVehicleLinearCastWheelCollide *, hkpVehicleInstance *, _QWORD, char *, signed __int64))v11[8].__first_virtual_table_function__)(
          v8,
          v7,
          v4,
          &v12,
          v9);
      ((void (__fastcall *)(hkpVehicleLinearCastWheelCollide *, hkpVehicleInstance *, _QWORD, signed __int64))v8->vfptr[5].__first_virtual_table_function__)(
        v8,
        v7,
        v4++,
        v9);
    }
    while ( v4 < v6 );
  }
}

// File Line: 178
// RVA: 0xE295B0
void __fastcall hkpVehicleLinearCastWheelCollide::updateBeforeCollisionDetection(hkpVehicleLinearCastWheelCollide *this, hkpVehicleInstance *vehicle)
{
  int v2; // ebp
  unsigned __int8 v3; // bl
  hkpVehicleInstance *v4; // rsi
  hkpVehicleLinearCastWheelCollide *v5; // rdi
  hkAabb aabbOut; // [rsp+20h] [rbp-28h]

  v2 = this->m_wheelStates.m_size;
  v3 = 0;
  v4 = vehicle;
  v5 = this;
  while ( v3 < v2 )
  {
    hkpVehicleLinearCastWheelCollide::updateWheelState(v5, v4, v3);
    hkpVehicleLinearCastWheelCollide::calcAabbOfWheel(v5, v4, v3, &aabbOut);
    hkpAabbPhantom::setAabb(v5->m_wheelStates.m_data[v3++].m_phantom, &aabbOut);
  }
}

// File Line: 202
// RVA: 0xE29650
hkpVehicleWheelCollide *__fastcall hkpVehicleLinearCastWheelCollide::clone(hkpVehicleLinearCastWheelCollide *this, hkpRigidBody *newChassis, hkArray<hkpPhantom *,hkContainerHeapAllocator> *newPhantoms)
{
  hkpVehicleLinearCastWheelCollide *v3; // r14
  hkpRigidBody *v4; // rbx
  _QWORD **v5; // rax
  hkpVehicleLinearCastWheelCollide *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbp
  signed int v9; // er12
  int v10; // eax
  int v11; // eax
  int v12; // er9
  unsigned __int8 v13; // r15
  __int64 v14; // rbx
  signed __int64 v15; // rsi
  hkReferencedObject *v16; // rcx
  hkpPhantom *v17; // rdi
  hkpPhantomOverlapListener *v18; // rdx
  hkpPhantomOverlapListener *v19; // rdx
  hkResult result; // [rsp+70h] [rbp+8h]
  hkArray<hkpPhantom *,hkContainerHeapAllocator> *v22; // [rsp+80h] [rbp+18h]

  v22 = newPhantoms;
  v3 = this;
  v4 = newChassis;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkpVehicleLinearCastWheelCollide *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(
                                             v5[11],
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
  v9 = v3->m_wheelStates.m_size;
  v10 = *(_DWORD *)(v8 + 44) & 0x3FFFFFFF;
  if ( v10 < v9 )
  {
    v11 = 2 * v10;
    v12 = v3->m_wheelStates.m_size;
    if ( v9 < v11 )
      v12 = v11;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (void *)(v8 + 32),
      v12,
      96);
  }
  v13 = 0;
  *(_DWORD *)(v8 + 40) = v9;
  if ( v9 > 0 )
  {
    *(_QWORD *)&result.m_enum = (char *)v4 + 32;
    do
    {
      v14 = *(_QWORD *)(v8 + 32);
      v15 = 96i64 * v13;
      v16 = (hkReferencedObject *)&v3->m_wheelStates.m_data[(unsigned __int64)v15 / 0x60].m_shape->vfptr;
      *(_QWORD *)(v15 + v14 + 8) = v16;
      hkReferencedObject::addReference(v16);
      v17 = v22->m_data[v13];
      *(_QWORD *)(v15 + v14) = v17;
      hkReferencedObject::addReference((hkReferencedObject *)&v17->vfptr);
      if ( v3 == (hkpVehicleLinearCastWheelCollide *)-48i64 )
        v18 = 0i64;
      else
        v18 = (hkpPhantomOverlapListener *)&v3->m_rejectChassisListener.vfptr;
      hkpPhantom::removePhantomOverlapListener(v17, v18);
      if ( v8 == -48 )
        v19 = 0i64;
      else
        v19 = (hkpPhantomOverlapListener *)(v8 + 64);
      hkpPhantom::addPhantomOverlapListener(v17, v19);
      ++v13;
      *(_QWORD *)(v8 + 72) = *(_QWORD *)&result.m_enum;
    }
    while ( v13 < v9 );
  }
  *(_DWORD *)(v8 + 24) = v3->m_wheelCollisionFilterInfo;
  *(float *)(v8 + 80) = v3->m_maxExtraPenetration;
  *(float *)(v8 + 84) = v3->m_startPointTolerance;
  return (hkpVehicleWheelCollide *)v8;
}

// File Line: 281
// RVA: 0xE29A50
__int64 __fastcall hkpVehicleLinearCastWheelCollide::getTotalNumCommands(hkpVehicleLinearCastWheelCollide *this)
{
  int v1; // ebp
  unsigned int v2; // edi
  unsigned __int8 v3; // bl
  hkpVehicleLinearCastWheelCollide *i; // rsi
  int v5; // eax

  v1 = this->m_wheelStates.m_size;
  v2 = 0;
  v3 = 0;
  for ( i = this; v3 < v1; v2 += v5 )
    v5 = ((__int64 (__fastcall *)(hkpVehicleLinearCastWheelCollide *, _QWORD))i->vfptr[6].__first_virtual_table_function__)(
           i,
           v3++);
  return v2;
}

// File Line: 293
// RVA: 0xE29AB0
__int64 __fastcall hkpVehicleLinearCastWheelCollide::getNumCommands(hkpVehicleLinearCastWheelCollide *this, char numWheel)
{
  hkpAabbPhantom *v2; // rbx

  v2 = this->m_wheelStates.m_data[(unsigned __int8)numWheel].m_phantom;
  v2->vfptr[5].__first_virtual_table_function__((hkBaseObject *)&v2->vfptr);
  return (unsigned int)v2->m_overlappingCollidables.m_size;
}

// File Line: 301
// RVA: 0xE29AF0
__int64 __fastcall hkpVehicleLinearCastWheelCollide::buildLinearCastCommands(hkpVehicleLinearCastWheelCollide *this, hkpVehicleInstance *vehicle, hkpCollisionFilter *collisionFilter, hkpCollidable *collidableStorage, hkpPairLinearCastCommand *commandStorage, hkpRootCdPoint *outputStorage)
{
  int v6; // ebx
  char v7; // bp
  unsigned int v8; // er13
  hkpPairLinearCastCommand *v9; // rdi
  hkpRootCdPoint *v10; // r12
  unsigned int *v11; // rsi
  hkpCollidable *v12; // r15
  hkpVehicleLinearCastWheelCollide::WheelState *v13; // r14
  hkpShape *v14; // rax
  signed int v15; // er9
  hkpCollidable *v16; // rcx
  hkVector4f v17; // xmm1
  int v19; // [rsp+20h] [rbp-38h]
  hkpVehicleLinearCastWheelCollide *v20; // [rsp+60h] [rbp+8h]

  v20 = this;
  v6 = this->m_wheelStates.m_size;
  v7 = 0;
  v8 = 0;
  v19 = v6;
  if ( v6 > 0 )
  {
    v9 = commandStorage;
    v10 = outputStorage;
    v11 = &collidableStorage->m_broadPhaseHandle.m_collisionFilterInfo;
    do
    {
      v12 = (hkpCollidable *)(v11 - 11);
      v13 = &this->m_wheelStates.m_data[v7];
      if ( v11 != (unsigned int *)44 )
      {
        v14 = v13->m_shape;
        *(_QWORD *)(v11 - 5) = 0i64;
        *(v11 - 9) = -1;
        v12->m_shape = v14;
        *((_BYTE *)v11 - 12) = 0;
        *(_QWORD *)(v11 - 7) = (char *)v13 + 16;
        *((_WORD *)v11 - 2) = 32512;
        *v11 = 0;
        *((_BYTE *)v11 - 2) = -1;
        *(v11 - 2) = 0;
        hkpCollidable::BoundingVolumeData::BoundingVolumeData((hkpCollidable::BoundingVolumeData *)(v11 + 1));
        v6 = v19;
        v11[15] = -1082130432;
        *((_BYTE *)v11 - 3) = -36;
        *((_BYTE *)v11 - 11) = 8;
        *((_WORD *)v11 - 5) = 0;
      }
      ((void (__fastcall *)(hkpAabbPhantom *, hkpVehicleInstance *, hkpCollisionFilter *))v13->m_phantom->vfptr[5].__first_virtual_table_function__)(
        v13->m_phantom,
        vehicle,
        collisionFilter);
      collisionFilter = (hkpCollisionFilter *)v13->m_phantom;
      LOBYTE(vehicle) = 0;
      v15 = v13->m_phantom->m_overlappingCollidables.m_size;
      if ( v15 > 0 )
      {
        do
        {
          v9->m_collidableA = v12;
          v16 = *(hkpCollidable **)(*(_QWORD *)&collisionFilter[3].m_type.m_storage + 8i64 * (char)vehicle);
          LOBYTE(vehicle) = (_BYTE)vehicle + 1;
          ++v9;
          v9[-1].m_collidableB = v16;
          ++v8;
          v9[-1].m_from = v13->m_transform.m_translation;
          v17.m_quad = (__m128)v13->m_to;
          v9[-1].m_results = v10;
          *(_QWORD *)&v9[-1].m_resultsCapacity = 1i64;
          v9[-1].m_startPointResultsCapacity = 0;
          ++v10;
          v9[-1].m_to = (hkVector4f)v17.m_quad;
        }
        while ( (char)vehicle < v15 );
      }
      ++v7;
      v11 += 28;
      this = v20;
    }
    while ( v7 < v6 );
  }
  return v8;
}

// File Line: 339
// RVA: 0xE29FA0
hkBool *__fastcall hkpVehicleLinearCastWheelCollide::castSingleWheel(hkpVehicleLinearCastWheelCollide *this, hkBool *result, hkpVehicleInstance *vehicle, char wheelNum, hkpRootCdPoint *linearCastOutput)
{
  hkpVehicleLinearCastWheelCollide *v5; // rbx
  hkBool *v6; // rsi
  hkpVehicleLinearCastWheelCollide::WheelState *v7; // rdi
  hkpShape *v8; // rax
  float v9; // xmm0_4
  char v10; // sp
  char v11; // al
  hkVector4f v12; // xmm1
  hkpCollidable *v13; // rax
  hkVector4f v14; // xmm0
  hkVector4f v15; // xmm1
  hkpLinearCastInput input; // [rsp+30h] [rbp-D0h]
  hkpCollidable toBeCast; // [rsp+50h] [rbp-B0h]
  hkpCdPointCollector castCollector; // [rsp+C0h] [rbp-40h]
  __m128 v20; // [rsp+D0h] [rbp-30h]
  __m128 v21; // [rsp+E0h] [rbp-20h]
  hkpCollidable *v22; // [rsp+F0h] [rbp-10h]
  unsigned int v23; // [rsp+F8h] [rbp-8h]
  hkpCollidable *v24; // [rsp+100h] [rbp+0h]
  unsigned int v25; // [rsp+108h] [rbp+8h]

  v5 = this;
  v6 = result;
  v7 = &this->m_wheelStates.m_data[(unsigned __int8)wheelNum];
  v8 = v7->m_shape;
  toBeCast.m_parent = 0i64;
  toBeCast.m_shapeKey = -1;
  toBeCast.m_shape = v8;
  toBeCast.m_ownerOffset = 0;
  toBeCast.m_broadPhaseHandle.m_id = 0;
  *(_WORD *)&toBeCast.m_broadPhaseHandle.m_type = 32512;
  toBeCast.m_broadPhaseHandle.m_collisionFilterInfo = 0;
  toBeCast.m_motion = &v7->m_transform;
  toBeCast.m_broadPhaseHandle.m_objectQualityType = -1;
  hkpCollidable::BoundingVolumeData::BoundingVolumeData(&toBeCast.m_boundingVolumeData);
  toBeCast.m_allowedPenetrationDepth = FLOAT_N1_0;
  v9 = v5->m_maxExtraPenetration;
  input.m_maxExtraPenetration = 0.00000011920929;
  input.m_startPointTolerance = 0.00000011920929;
  v11 = v10 + 80;
  toBeCast.m_forceCollideOntoPpu = 8;
  toBeCast.m_shapeSizeOnSpu = 0;
  toBeCast.m_broadPhaseHandle.m_ownerOffset = v11 - (v10 + 116);
  toBeCast.m_broadPhaseHandle.m_collisionFilterInfo = v5->m_wheelCollisionFilterInfo;
  v12.m_quad = (__m128)v7->m_to;
  input.m_maxExtraPenetration = v9;
  input.m_to = (hkVector4f)v12.m_quad;
  castCollector.vfptr = (hkpCdPointCollectorVtbl *)&hkpClosestCdPointCollector::`vftable;
  v22 = 0i64;
  input.m_startPointTolerance = v5->m_startPointTolerance;
  castCollector.m_earlyOutDistance = FLOAT_3_40282e38;
  v21 = _mm_shuffle_ps(v21, _mm_unpackhi_ps(v21, (__m128)xmmword_141A712A0), 196);
  hkpAabbPhantom::linearCast(v7->m_phantom, &toBeCast, &input, &castCollector, 0i64);
  v13 = v22;
  if ( v22 )
  {
    v14.m_quad = v20;
    v15.m_quad = v21;
    v6->m_bool = 1;
    linearCastOutput->m_contact.m_position = (hkVector4f)v14.m_quad;
    linearCastOutput->m_contact.m_separatingNormal = (hkVector4f)v15.m_quad;
    linearCastOutput->m_rootCollidableA = v13;
    linearCastOutput->m_shapeKeyA = v23;
    linearCastOutput->m_rootCollidableB = v24;
    linearCastOutput->m_shapeKeyB = v25;
  }
  else
  {
    v6->m_bool = 0;
  }
  return v6;
}

// File Line: 386
// RVA: 0xE29C80
__m128 *__fastcall hkpVehicleLinearCastWheelCollide::determineNearestHit(hkpVehicleLinearCastWheelCollide *this, __int64 numWheel, hkpPairLinearCastCommand *commandStorageOutput)
{
  hkpPairLinearCastCommand *v3; // rbx
  int v4; // eax
  __m128 *v5; // rdx
  __int64 v6; // r9
  __m128 **v7; // rcx

  v3 = commandStorageOutput;
  v4 = ((__int64 (__fastcall *)(hkpVehicleLinearCastWheelCollide *, __int64))this->vfptr[6].__first_virtual_table_function__)(
         this,
         numWheel);
  v5 = 0i64;
  v6 = v4;
  if ( v4 > 0 )
  {
    v7 = (__m128 **)&v3->m_results;
    do
    {
      if ( *((_DWORD *)v7 + 3)
        && (!v5
         || COERCE_FLOAT(_mm_shuffle_ps((*v7)[1], (*v7)[1], 255)) < COERCE_FLOAT(_mm_shuffle_ps(v5[1], v5[1], 255))) )
      {
        v5 = *v7;
      }
      v7 += 10;
      --v6;
    }
    while ( v6 );
  }
  return v5;
}

// File Line: 408
// RVA: 0xE2A130
void __fastcall hkpVehicleLinearCastWheelCollide::getCollisionOutputFromCastResult(hkpVehicleLinearCastWheelCollide *this, hkpVehicleInstance *vehicle, char wheelNum, hkpRootCdPoint *linearCastOutput, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *output)
{
  hkpVehicleInstance::WheelInfo *v5; // r10
  float v6; // xmm1_4
  hkpCollidable *v7; // rcx
  hkpRigidBody *v8; // rax
  unsigned int v9; // eax
  hkVector4f v10; // xmm3
  __m128 v11; // xmm1
  __m128 v12; // xmm5
  hkpEntity *v13; // rcx
  hkpRigidBody *v14; // rax
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  __m128 v20; // xmm4
  float v21; // xmm6_4

  v5 = &vehicle->m_wheelsInfo.m_data[(unsigned __int8)wheelNum];
  v6 = vehicle->m_suspension->m_wheelParams.m_data[(unsigned __int8)wheelNum].m_length;
  output->m_contactPoint.m_position = linearCastOutput->m_contact.m_position;
  output->m_contactPoint.m_separatingNormal = linearCastOutput->m_contact.m_separatingNormal;
  v7 = linearCastOutput->m_rootCollidableB;
  if ( v7->m_broadPhaseHandle.m_type == 1 )
    v8 = (hkpRigidBody *)((char *)v7 + v7->m_ownerOffset);
  else
    v8 = 0i64;
  output->m_contactBody = v8;
  output->m_contactFriction = v8->m_material.m_friction;
  v9 = linearCastOutput->m_shapeKeyB;
  output->m_contactShapeKey[1] = -1;
  output->m_contactShapeKey[0] = v9;
  v10.m_quad = (__m128)output->m_contactPoint.m_separatingNormal;
  output->m_currentSuspensionLength = v6 * linearCastOutput->m_contact.m_separatingNormal.m_quad.m128_f32[3];
  v11 = _mm_mul_ps(v5->m_suspensionDirectionWs.m_quad, v10.m_quad);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  if ( v12.m128_f32[0] >= (float)(0.0
                                - COERCE_FLOAT(
                                    _mm_shuffle_ps(
                                      (__m128)LODWORD(vehicle->m_data->m_normalClippingAngleCos),
                                      (__m128)LODWORD(vehicle->m_data->m_normalClippingAngleCos),
                                      0))) )
  {
    output->m_suspensionClosingSpeed = 0.0;
    output->m_suspensionScalingFactor = 1.0 / vehicle->m_data->m_normalClippingAngleCos;
  }
  else
  {
    v13 = vehicle->m_entity;
    v14 = output->m_contactBody;
    v15 = _mm_sub_ps(
            output->m_contactPoint.m_position.m_quad,
            v14->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
    v16 = _mm_sub_ps(
            output->m_contactPoint.m_position.m_quad,
            v13->m_motion.m_motionState.m_sweptTransform.m_centerOfMass1.m_quad);
    v17 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v13->m_motion.m_angularVelocity.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(v13->m_motion.m_angularVelocity.m_quad, v13->m_motion.m_angularVelocity.m_quad, 201),
              v16));
    v18 = _mm_sub_ps(
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 201), v14->m_motion.m_angularVelocity.m_quad),
            _mm_mul_ps(
              _mm_shuffle_ps(v14->m_motion.m_angularVelocity.m_quad, v14->m_motion.m_angularVelocity.m_quad, 201),
              v15));
    v19 = _mm_sub_ps(
            _mm_add_ps(_mm_shuffle_ps(v17, v17, 201), v13->m_motion.m_linearVelocity.m_quad),
            _mm_add_ps(_mm_shuffle_ps(v18, v18, 201), v14->m_motion.m_linearVelocity.m_quad));
    v18.m128_i32[0] = (unsigned __int128)_mm_rcp_ps(v12);
    v20 = _mm_mul_ps(v19, v10.m_quad);
    v21 = 0.0 - (float)((float)(2.0 - (float)(v18.m128_f32[0] * v12.m128_f32[0])) * v18.m128_f32[0]);
    output->m_suspensionScalingFactor = v21;
    output->m_suspensionClosingSpeed = v21
                                     * (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 85))
                                                     + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 0)))
                                             + COERCE_FLOAT(_mm_shuffle_ps(v20, v20, 170)));
  }
}

// File Line: 453
// RVA: 0xE2A2F0
void __fastcall hkpVehicleLinearCastWheelCollide::getCollisionOutputWithoutHit(hkpVehicleLinearCastWheelCollide *this, hkpVehicleInstance *vehicle, char wheelNum, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  hkpVehicleInstance::WheelInfo *v4; // r10
  float v5; // xmm3_4
  __m128 v6; // xmm2

  v4 = &vehicle->m_wheelsInfo.m_data[(unsigned __int8)wheelNum];
  v5 = vehicle->m_suspension->m_wheelParams.m_data[(unsigned __int8)wheelNum].m_length;
  cdInfo->m_currentSuspensionLength = v5;
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
  cdInfo->m_contactPoint.m_separatingNormal.m_quad.m128_f32[3] = v5;
}

// File Line: 471
// RVA: 0xE29EC0
void __fastcall hkpVehicleLinearCastWheelCollide::calcAabbOfWheel(hkpVehicleLinearCastWheelCollide *this, hkpVehicleInstance *vehicle, char wheelNum, hkAabb *aabbOut)
{
  hkpVehicleData::WheelComponentParams *v4; // rdx
  hkpVehicleLinearCastWheelCollide::WheelState *v5; // rax
  __int64 v6; // r10
  signed __int64 v7; // r8
  __m128 v8; // xmm0
  __m128 v9; // xmm5
  __m128 v10; // xmm3
  hkVector4f v11; // ST30_16
  __m128 v12; // xmm2

  v4 = vehicle->m_data->m_wheelParams.m_data;
  v5 = this->m_wheelStates.m_data;
  v6 = (unsigned __int8)wheelNum;
  v7 = (unsigned __int8)wheelNum;
  v8 = (__m128)LODWORD(v4[v7].m_width);
  v8.m128_f32[0] = v8.m128_f32[0] * 0.5;
  v9 = _mm_unpacklo_ps(
         _mm_unpacklo_ps((__m128)LODWORD(v4[v7].m_radius), v8),
         _mm_unpacklo_ps((__m128)LODWORD(v4[v7].m_radius), (__m128)0i64));
  v10 = v5[v6].m_to.m_quad;
  v11.m_quad = (__m128)v5[v6].m_transform.m_translation;
  v12 = _mm_add_ps(
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
  aabbOut->m_max.m_quad = _mm_add_ps(v10, v12);
  aabbOut->m_min.m_quad = _mm_add_ps(
                            _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v12),
                            v10);
}

// File Line: 489
// RVA: 0xE29CE0
void __fastcall hkpVehicleLinearCastWheelCollide::updateWheelState(hkpVehicleLinearCastWheelCollide *this, hkpVehicleInstance *vehicle, char wheelNum)
{
  __int64 v3; // rdi
  hkpVehicleInstance *v4; // rsi
  hkQuaternionf v5; // xmm6
  hkpVehicleData *v6; // rax
  hkpVehicleInstance::WheelInfo *v7; // r14
  hkpVehicleLinearCastWheelCollide::WheelState *v8; // rbp
  __m128 v9; // xmm4
  __m128 v10; // xmm2
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
  __m128 v22; // xmm0
  hkQuaternionf qi; // [rsp+20h] [rbp-68h]
  hkQuaternionf v24; // [rsp+30h] [rbp-58h]
  hkRotationf r; // [rsp+40h] [rbp-48h]

  v3 = (unsigned __int8)wheelNum;
  v4 = vehicle;
  v5.m_vec.m_quad = (__m128)vehicle->m_entity->m_motion.m_motionState.m_sweptTransform.m_rotation1;
  v6 = vehicle->m_data;
  v7 = &vehicle->m_wheelsInfo.m_data[(unsigned __int8)wheelNum];
  v8 = &this->m_wheelStates.m_data[(unsigned __int8)wheelNum];
  v9 = _mm_shuffle_ps(
         vehicle->m_entity->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
         vehicle->m_entity->m_motion.m_motionState.m_sweptTransform.m_rotation1.m_vec.m_quad,
         255);
  v10 = v7->m_steeringOrientationChassisSpace.m_vec.m_quad;
  v11 = _mm_mul_ps(_mm_shuffle_ps(v5.m_vec.m_quad, v5.m_vec.m_quad, 201), v10);
  v12 = _mm_shuffle_ps(
          v7->m_steeringOrientationChassisSpace.m_vec.m_quad,
          v7->m_steeringOrientationChassisSpace.m_vec.m_quad,
          255);
  v13 = _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v5.m_vec.m_quad);
  v14 = _mm_mul_ps(v5.m_vec.m_quad, v10);
  v15 = _mm_sub_ps(v13, v11);
  v16 = _mm_add_ps(
          _mm_add_ps(_mm_shuffle_ps(v15, v15, 201), _mm_mul_ps(v7->m_steeringOrientationChassisSpace.m_vec.m_quad, v9)),
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
  r.m_col0 = v6->m_chassisOrientation.m_col1;
  r.m_col1 = v6->m_chassisOrientation.m_col0;
  r.m_col2 = v6->m_chassisOrientation.m_col2;
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
  v22 = (__m128)LODWORD(v4->m_suspension->m_wheelParams.m_data[v3].m_length);
  v8->m_to.m_quad = _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v22, v22, 0), v7->m_suspensionDirectionWs.m_quad),
                      v7->m_hardPointWs.m_quad);
}

// File Line: 509
// RVA: 0xE29510
void __fastcall hkpVehicleLinearCastWheelCollide::getPhantoms(hkpVehicleLinearCastWheelCollide *this, hkArray<hkpPhantom *,hkContainerHeapAllocator> *phantomsOut)
{
  __int64 v2; // rsi
  hkArray<hkpPhantom *,hkContainerHeapAllocator> *v3; // rbx
  hkpVehicleLinearCastWheelCollide *v4; // r14
  __int64 v5; // rdi
  hkpAabbPhantom *v6; // rbp

  v2 = this->m_wheelStates.m_size;
  v3 = phantomsOut;
  v4 = this;
  if ( v2 > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v4->m_wheelStates.m_data[v5].m_phantom;
      if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 8);
      ++v5;
      v3->m_data[v3->m_size++] = (hkpPhantom *)&v6->vfptr;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 519
// RVA: 0xE297C0
void __fastcall hkpVehicleLinearCastWheelCollide::addToWorld(hkpVehicleLinearCastWheelCollide *this, hkpWorld *world)
{
  __int64 v2; // rdi
  hkpWorld *v3; // rbp
  hkpVehicleLinearCastWheelCollide *v4; // rsi
  __int64 v5; // rbx

  v2 = this->m_wheelStates.m_size;
  v3 = world;
  v4 = this;
  if ( v2 > 0 )
  {
    v5 = 0i64;
    do
    {
      hkpWorld::addPhantom(v3, (hkpPhantom *)&v4->m_wheelStates.m_data[v5].m_phantom->vfptr);
      ++v5;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 529
// RVA: 0xE29830
void __fastcall hkpVehicleLinearCastWheelCollide::removeFromWorld(hkpVehicleLinearCastWheelCollide *this)
{
  __int64 v1; // rdi
  hkpVehicleLinearCastWheelCollide *v2; // rsi
  __int64 v3; // rbx

  v1 = this->m_wheelStates.m_size;
  v2 = this;
  if ( v1 > 0 )
  {
    v3 = 0i64;
    do
    {
      hkpWorld::removePhantom(
        v2->m_wheelStates.m_data[v3].m_phantom->m_world,
        (hkpPhantom *)&v2->m_wheelStates.m_data[v3].m_phantom->vfptr);
      ++v3;
      --v1;
    }
    while ( v1 );
  }
}

// File Line: 541
// RVA: 0xE29890
void __fastcall hkpVehicleLinearCastWheelCollide::setCollisionFilterInfo(hkpVehicleLinearCastWheelCollide *this, unsigned int filterInfo)
{
  __int64 v2; // r9
  unsigned int v3; // er10
  __int64 v4; // r8
  hkpAabbPhantom *v5; // rdx

  v2 = this->m_wheelStates.m_size;
  v3 = filterInfo;
  this->m_wheelCollisionFilterInfo = filterInfo;
  if ( v2 > 0 )
  {
    v4 = 0i64;
    do
    {
      v5 = this->m_wheelStates.m_data[v4].m_phantom;
      if ( v5 )
        v5->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo = v3;
      ++v4;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 556
// RVA: 0xE298D0
void __fastcall hkpVehicleLinearCastWheelCollide::wheelCollideCallback(hkpVehicleLinearCastWheelCollide *this, hkpVehicleInstance *vehicle, char wheelIndex, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  hkpVehicleLinearCastWheelCollide::centerWheelContactPoint(this, vehicle, wheelIndex, cdInfo);
}

// File Line: 562
// RVA: 0xE298E0
void __fastcall hkpVehicleLinearCastWheelCollide::centerWheelContactPoint(hkpVehicleLinearCastWheelCollide *this, hkpVehicleInstance *vehicle, char wheelIndex, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *cdInfo)
{
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v4; // rdi
  hkpVehicleLinearCastWheelCollide::WheelState *v5; // rbx
  hkVector4f b; // [rsp+20h] [rbp-28h]
  hkVector4f v7; // [rsp+30h] [rbp-18h]

  v4 = cdInfo;
  v5 = &this->m_wheelStates.m_data[(unsigned __int8)wheelIndex];
  hkVector4f::setTransformedInversePos(&b, &v5->m_transform, &cdInfo->m_contactPoint.m_position);
  b.m_quad = _mm_shuffle_ps(b.m_quad, _mm_unpackhi_ps(b.m_quad, (__m128)0i64), 180);
  hkVector4f::setTransformedPos(&v7, &v5->m_transform, &b);
  v4->m_contactPoint.m_position = (hkVector4f)v7.m_quad;
}

