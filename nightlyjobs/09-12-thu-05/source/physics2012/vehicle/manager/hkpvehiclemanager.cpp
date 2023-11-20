// File Line: 15
// RVA: 0xE2B470
void __fastcall hkpVehicleManager::~hkpVehicleManager(hkpVehicleManager *this)
{
  __int64 v1; // rsi
  __int64 v2; // rbx
  hkpVehicleManager *v3; // rdi
  int v4; // er8

  v1 = this->m_registeredVehicles.m_size;
  v2 = 0i64;
  v3 = this;
  for ( this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleManager::`vftable; v2 < v1; ++v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v3->m_registeredVehicles.m_data[v2]->vfptr);
  v4 = v3->m_registeredVehicles.m_capacityAndFlags;
  v3->m_registeredVehicles.m_size = 0;
  if ( v4 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v3->m_registeredVehicles.m_data,
      8 * v4);
  v3->m_registeredVehicles.m_data = 0i64;
  v3->m_registeredVehicles.m_capacityAndFlags = 2147483648;
  v3->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 25
// RVA: 0xE2B520
void __fastcall hkpVehicleManager::addVehicle(hkpVehicleManager *this, hkpVehicleInstance *vehicle)
{
  hkpVehicleManager *v2; // rbx
  hkpVehicleInstance *v3; // rdi

  v2 = this;
  v3 = vehicle;
  hkReferencedObject::addReference((hkReferencedObject *)&vehicle->vfptr);
  if ( v2->m_registeredVehicles.m_size == (v2->m_registeredVehicles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v2->m_registeredVehicles,
      8);
  v2->m_registeredVehicles.m_data[v2->m_registeredVehicles.m_size++] = v3;
}

// File Line: 35
// RVA: 0xE2B580
void __fastcall hkpVehicleManager::removeVehicle(hkpVehicleManager *this, hkpVehicleInstance *vehicle)
{
  __int64 v2; // r11
  signed int v3; // er9
  __int64 v4; // r8
  hkpVehicleInstance **v5; // rax

  v2 = this->m_registeredVehicles.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (signed int)v2 <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    v5 = this->m_registeredVehicles.m_data;
    while ( *v5 != vehicle )
    {
      ++v4;
      ++v3;
      ++v5;
      if ( v4 >= v2 )
        goto LABEL_5;
    }
  }
  this->m_registeredVehicles.m_size = v2 - 1;
  if ( (_DWORD)v2 - 1 != v3 )
    this->m_registeredVehicles.m_data[v3] = this->m_registeredVehicles.m_data[(signed int)v2 - 1];
  hkReferencedObject::removeReference((hkReferencedObject *)&vehicle->vfptr);
}

// File Line: 43
// RVA: 0xE2B670
void __fastcall hkpVehicleManager::stepVehicles(hkpVehicleManager *this, hkStepInfo *updatedStepInfo)
{
  int v2; // ebx
  hkStepInfo *v3; // rsi
  hkpVehicleManager *v4; // rdi
  LPVOID v5; // rax
  hkLifoAllocator *v6; // rcx
  hkpVehicleInstance **v7; // rax
  int v8; // er8
  char *v9; // rdx
  int v10; // eax
  char *v11; // rdi
  signed int v12; // ebx
  hkLifoAllocator *v13; // rax
  int v14; // er8
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> activeVehicles; // [rsp+20h] [rbp-28h]
  void *p; // [rsp+30h] [rbp-18h]
  int v17; // [rsp+38h] [rbp-10h]

  v2 = this->m_registeredVehicles.m_size;
  v3 = updatedStepInfo;
  v4 = this;
  activeVehicles.m_capacityAndFlags = 2147483648;
  activeVehicles.m_data = 0i64;
  activeVehicles.m_size = 0;
  v17 = v2;
  if ( v2 )
  {
    v5 = TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v6 = (hkLifoAllocator *)v5;
    v7 = (hkpVehicleInstance **)*((_QWORD *)v5 + 3);
    v8 = (8 * v2 + 127) & 0xFFFFFF80;
    v9 = (char *)v7 + v8;
    if ( v8 > v6->m_slabSize || v9 > v6->m_end )
      v7 = (hkpVehicleInstance **)hkLifoAllocator::allocateFromNewSlab(v6, v8);
    else
      v6->m_cur = v9;
  }
  else
  {
    v7 = 0i64;
  }
  activeVehicles.m_data = v7;
  p = v7;
  activeVehicles.m_capacityAndFlags = v2 | 0x80000000;
  hkpVehicleManager::getActiveVehicles(v4, &activeVehicles);
  v10 = activeVehicles.m_size;
  if ( activeVehicles.m_size )
  {
    hkpVehicleManager::stepVehicleArray(&activeVehicles, v3);
    v10 = activeVehicles.m_size;
  }
  v11 = (char *)p;
  if ( p == activeVehicles.m_data )
    v10 = 0;
  activeVehicles.m_size = v10;
  v12 = (8 * v17 + 127) & 0xFFFFFF80;
  v13 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v14 = (v12 + 15) & 0xFFFFFFF0;
  if ( v12 > v13->m_slabSize || &v11[v14] != v13->m_cur || v13->m_firstNonLifoEnd == v11 )
    hkLifoAllocator::slowBlockFree(v13, v11, v14);
  else
    v13->m_cur = v11;
  activeVehicles.m_size = 0;
  if ( activeVehicles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      activeVehicles.m_data,
      8 * activeVehicles.m_capacityAndFlags);
}

// File Line: 54
// RVA: 0xE2B7D0
void __fastcall hkpVehicleManager::stepVehicleArray(hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles, hkStepInfo *updatedStepInfo)
{
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v2; // r15
  hkStepInfo *v3; // r12
  hkLifoAllocator *v4; // rax
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v5; // rdx
  unsigned __int64 v6; // rcx
  hkLifoAllocator *v7; // rax
  float *v8; // rcx
  unsigned __int64 v9; // rdx
  hkLifoAllocator *v10; // rax
  float *v11; // rdi
  unsigned __int64 v12; // rcx
  __int64 v13; // r14
  __int64 v14; // rsi
  hkpVehicleInstance *v15; // rbx
  int v16; // edi
  int v17; // er9
  int v18; // edi
  int v19; // er9
  int v20; // edi
  int v21; // er9
  unsigned __int64 v22; // rdx
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  signed __int64 v26; // rcx
  __int128 v27; // xmm1
  _QWORD *v28; // r8
  _QWORD *v29; // rcx
  unsigned __int64 v30; // rax
  signed __int64 v31; // rcx
  signed int v32; // ebx
  hkLifoAllocator *v33; // rax
  int v34; // er8
  int v35; // eax
  char *v36; // rdi
  signed int v37; // ebx
  hkLifoAllocator *v38; // rax
  int v39; // er8
  int v40; // eax
  char *v41; // rdi
  signed int v42; // ebx
  hkLifoAllocator *v43; // rax
  int v44; // er8
  hkArray<float,hkContainerHeapAllocator> suspensionForceAtWheel; // [rsp+30h] [rbp-59h]
  void *v46; // [rsp+40h] [rbp-49h]
  int v47; // [rsp+48h] [rbp-41h]
  hkArray<float,hkContainerHeapAllocator> v48; // [rsp+50h] [rbp-39h]
  void *p; // [rsp+60h] [rbp-29h]
  int v50; // [rsp+68h] [rbp-21h]
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *array; // [rsp+70h] [rbp-19h]
  int v52; // [rsp+78h] [rbp-11h]
  int v53; // [rsp+7Ch] [rbp-Dh]
  void *v54; // [rsp+80h] [rbp-9h]
  int v55; // [rsp+88h] [rbp-1h]
  hkpVehicleAerodynamics::AerodynamicsDragOutput aerodynamicsDragInfo; // [rsp+90h] [rbp+7h]
  hkResult result; // [rsp+F0h] [rbp+67h]
  hkResult v58; // [rsp+100h] [rbp+77h]
  hkResult v59; // [rsp+108h] [rbp+7Fh]

  v2 = activeVehicles;
  v3 = updatedStepInfo;
  v53 = 2147483648;
  v55 = 32;
  array = 0i64;
  v52 = 0;
  v4 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)v4->m_cur;
  v6 = (unsigned __int64)&v5[32];
  if ( v4->m_slabSize < 3072 || (void *)v6 > v4->m_end )
    v5 = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)hkLifoAllocator::allocateFromNewSlab(v4, 3072);
  else
    v4->m_cur = (void *)v6;
  array = v5;
  v53 = -2147483616;
  v54 = v5;
  suspensionForceAtWheel.m_data = 0i64;
  suspensionForceAtWheel.m_size = 0;
  suspensionForceAtWheel.m_capacityAndFlags = 2147483648;
  v47 = 32;
  v7 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (float *)v7->m_cur;
  v9 = (unsigned __int64)(v8 + 32);
  if ( v7->m_slabSize < 128 || (void *)v9 > v7->m_end )
    v8 = (float *)hkLifoAllocator::allocateFromNewSlab(v7, 128);
  else
    v7->m_cur = (void *)v9;
  suspensionForceAtWheel.m_data = v8;
  v46 = v8;
  suspensionForceAtWheel.m_capacityAndFlags = -2147483616;
  v48.m_data = 0i64;
  v48.m_size = 0;
  v48.m_capacityAndFlags = 2147483648;
  v50 = 32;
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (float *)v10->m_cur;
  v12 = (unsigned __int64)(v11 + 32);
  if ( v10->m_slabSize < 128 || (void *)v12 > v10->m_end )
    v11 = (float *)hkLifoAllocator::allocateFromNewSlab(v10, 128);
  else
    v10->m_cur = (void *)v12;
  v13 = v2->m_size;
  v48.m_data = v11;
  v48.m_capacityAndFlags = -2147483616;
  p = v11;
  v14 = 0i64;
  if ( v13 <= 0 )
    goto LABEL_63;
  do
  {
    v15 = v2->m_data[v14];
    v16 = (unsigned __int8)v15->m_data->m_numWheels;
    if ( (v53 & 0x3FFFFFFF) >= v16 )
    {
      result.m_enum = 0;
    }
    else
    {
      v17 = (unsigned __int8)v15->m_data->m_numWheels;
      if ( v16 < 2 * (v53 & 0x3FFFFFFF) )
        v17 = 2 * (v53 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v17, 96);
    }
    v52 = v16;
    v18 = (unsigned __int8)v15->m_data->m_numWheels;
    if ( (suspensionForceAtWheel.m_capacityAndFlags & 0x3FFFFFFF) >= v18 )
    {
      v58.m_enum = 0;
    }
    else
    {
      v19 = (unsigned __int8)v15->m_data->m_numWheels;
      if ( v18 < 2 * (suspensionForceAtWheel.m_capacityAndFlags & 0x3FFFFFFF) )
        v19 = 2 * (suspensionForceAtWheel.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        &v58,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &suspensionForceAtWheel,
        v19,
        4);
    }
    suspensionForceAtWheel.m_size = v18;
    v20 = (unsigned __int8)v15->m_data->m_numWheels;
    if ( (v48.m_capacityAndFlags & 0x3FFFFFFF) >= v20 )
    {
      v59.m_enum = 0;
    }
    else
    {
      v21 = (unsigned __int8)v15->m_data->m_numWheels;
      if ( v20 < 2 * (v48.m_capacityAndFlags & 0x3FFFFFFF) )
        v21 = 2 * (v48.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v59, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v48, v21, 4);
    }
    v48.m_size = v20;
    hkpVehicleInstance::updateBeforeCollisionDetection(v15);
    v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v24 = (_QWORD *)v23[1];
    if ( (unsigned __int64)v24 < v23[3] )
    {
      *v24 = "TtVehicleJob";
      v25 = __rdtsc();
      v22 = (unsigned __int64)HIDWORD(v25) << 32;
      v26 = (signed __int64)(v24 + 2);
      *(_DWORD *)(v26 - 8) = v25;
      v23[1] = v26;
    }
    v27 = LODWORD(v3->m_deltaTime.m_storage);
    ((void (__fastcall *)(hkpVehicleWheelCollide *, unsigned __int64, hkpVehicleInstance *, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))v15->m_wheelCollide->vfptr[2].__vecDelDtor)(
      v15->m_wheelCollide,
      v22,
      v15,
      array);
    hkpVehicleInstance::updateComponents(v15, v3, array, &aerodynamicsDragInfo);
    hkpVehicleInstance::simulateVehicle(v15, v3, &aerodynamicsDragInfo, &suspensionForceAtWheel, &v48, 0i64);
    v28 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v29 = (_QWORD *)v28[1];
    if ( (unsigned __int64)v29 < v28[3] )
    {
      *v29 = "Et";
      v30 = __rdtsc();
      v31 = (signed __int64)(v29 + 2);
      *(_DWORD *)(v31 - 8) = v30;
      v28[1] = v31;
    }
    ++v14;
  }
  while ( v14 < v13 );
  v11 = (float *)p;
  if ( p == v48.m_data )
LABEL_63:
    v48.m_size = 0;
  v32 = (4 * v50 + 127) & 0xFFFFFF80;
  v33 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v34 = (v32 + 15) & 0xFFFFFFF0;
  if ( v32 > v33->m_slabSize || (char *)v11 + v34 != v33->m_cur || v33->m_firstNonLifoEnd == v11 )
    hkLifoAllocator::slowBlockFree(v33, v11, v34);
  else
    v33->m_cur = v11;
  v48.m_size = 0;
  if ( v48.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v48.m_data,
      4 * v48.m_capacityAndFlags);
  v35 = suspensionForceAtWheel.m_size;
  v36 = (char *)v46;
  v48.m_data = 0i64;
  v48.m_capacityAndFlags = 2147483648;
  if ( v46 == suspensionForceAtWheel.m_data )
    v35 = 0;
  suspensionForceAtWheel.m_size = v35;
  v37 = (4 * v47 + 127) & 0xFFFFFF80;
  v38 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v39 = (v37 + 15) & 0xFFFFFFF0;
  if ( v37 > v38->m_slabSize || &v36[v39] != v38->m_cur || v38->m_firstNonLifoEnd == v36 )
    hkLifoAllocator::slowBlockFree(v38, v36, v39);
  else
    v38->m_cur = v36;
  suspensionForceAtWheel.m_size = 0;
  if ( suspensionForceAtWheel.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      suspensionForceAtWheel.m_data,
      4 * suspensionForceAtWheel.m_capacityAndFlags);
  v40 = v52;
  v41 = (char *)v54;
  suspensionForceAtWheel.m_data = 0i64;
  suspensionForceAtWheel.m_capacityAndFlags = 2147483648;
  if ( v54 == array )
    v40 = 0;
  v52 = v40;
  v42 = (96 * v55 + 127) & 0xFFFFFF80;
  v43 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v44 = (v42 + 15) & 0xFFFFFFF0;
  if ( v42 > v43->m_slabSize || &v41[v44] != v43->m_cur || v43->m_firstNonLifoEnd == v41 )
    hkLifoAllocator::slowBlockFree(v43, v41, v44);
  else
    v43->m_cur = v41;
  v52 = 0;
  if ( v53 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      96 * (v53 & 0x3FFFFFFF));
}

// File Line: 85
// RVA: 0xE2B5E0
void __fastcall hkpVehicleManager::getActiveVehicles(hkpVehicleManager *this, hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  int v2; // edi
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *v3; // rbx
  hkpVehicleManager *v4; // rbp
  __int64 v5; // rsi
  hkpVehicleInstance *v6; // r14
  hkBool result; // [rsp+40h] [rbp+8h]

  v2 = 0;
  v3 = activeVehicles;
  v4 = this;
  if ( this->m_registeredVehicles.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = v4->m_registeredVehicles.m_data[v5];
      if ( hkpEntity::isActive(v6->m_entity, &result)->m_bool )
      {
        if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 8);
        v3->m_data[v3->m_size++] = v6;
      }
      ++v2;
      ++v5;
    }
    while ( v2 < v4->m_registeredVehicles.m_size );
  }
}

// File Line: 97
// RVA: 0xE2BCB0
void __fastcall hkpVehicleManager::addToWorld(hkpVehicleManager *this, hkpWorld *world)
{
  __int64 v2; // rsi
  __int64 v3; // rbx
  hkpWorld *v4; // rbp
  hkpVehicleManager *i; // rdi
  hkpVehicleInstance *v6; // rcx

  v2 = this->m_registeredVehicles.m_size;
  v3 = 0i64;
  v4 = world;
  for ( i = this; v3 < v2; ++v3 )
  {
    v6 = i->m_registeredVehicles.m_data[v3];
    ((void (__fastcall *)(hkpVehicleInstance *, hkpWorld *))v6->vfptr[4].__first_virtual_table_function__)(v6, v4);
  }
}

// File Line: 106
// RVA: 0xE2BD20
void __fastcall hkpVehicleManager::removeFromWorld(hkpVehicleManager *this)
{
  __int64 v1; // rsi
  __int64 v2; // rbx
  hkpVehicleManager *i; // rdi

  v1 = this->m_registeredVehicles.m_size;
  v2 = 0i64;
  for ( i = this; v2 < v1; ++v2 )
    ((void (*)(void))i->m_registeredVehicles.m_data[v2]->vfptr[5].__vecDelDtor)();
}

