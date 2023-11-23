// File Line: 15
// RVA: 0xE2B470
void __fastcall hkpVehicleManager::~hkpVehicleManager(hkpVehicleManager *this)
{
  __int64 m_size; // rsi
  __int64 v2; // rbx
  int m_capacityAndFlags; // r8d

  m_size = this->m_registeredVehicles.m_size;
  v2 = 0i64;
  for ( this->vfptr = (hkBaseObjectVtbl *)&hkpVehicleManager::`vftable; v2 < m_size; ++v2 )
    hkReferencedObject::removeReference(this->m_registeredVehicles.m_data[v2]);
  m_capacityAndFlags = this->m_registeredVehicles.m_capacityAndFlags;
  this->m_registeredVehicles.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_registeredVehicles.m_data,
      8 * m_capacityAndFlags);
  this->m_registeredVehicles.m_data = 0i64;
  this->m_registeredVehicles.m_capacityAndFlags = 0x80000000;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 25
// RVA: 0xE2B520
void __fastcall hkpVehicleManager::addVehicle(hkpVehicleManager *this, hkpVehicleInstance *vehicle)
{
  hkReferencedObject::addReference(vehicle);
  if ( this->m_registeredVehicles.m_size == (this->m_registeredVehicles.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_registeredVehicles.m_data, 8);
  this->m_registeredVehicles.m_data[this->m_registeredVehicles.m_size++] = vehicle;
}

// File Line: 35
// RVA: 0xE2B580
void __fastcall hkpVehicleManager::removeVehicle(hkpVehicleManager *this, hkpVehicleInstance *vehicle)
{
  __int64 m_size; // r11
  int v3; // r9d
  __int64 v4; // r8
  hkpVehicleInstance **m_data; // rax

  m_size = this->m_registeredVehicles.m_size;
  v3 = 0;
  v4 = 0i64;
  if ( (int)m_size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_data = this->m_registeredVehicles.m_data;
    while ( *m_data != vehicle )
    {
      ++v4;
      ++v3;
      ++m_data;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
  this->m_registeredVehicles.m_size = m_size - 1;
  if ( (_DWORD)m_size - 1 != v3 )
    this->m_registeredVehicles.m_data[v3] = this->m_registeredVehicles.m_data[(int)m_size - 1];
  hkReferencedObject::removeReference(vehicle);
}

// File Line: 43
// RVA: 0xE2B670
void __fastcall hkpVehicleManager::stepVehicles(hkpVehicleManager *this, hkStepInfo *updatedStepInfo)
{
  int m_size; // ebx
  hkLifoAllocator *Value; // rcx
  hkpVehicleInstance **m_cur; // rax
  int v7; // r8d
  char *v8; // rdx
  int v9; // eax
  char *v10; // rdi
  signed int v11; // ebx
  hkLifoAllocator *v12; // rax
  int v13; // r8d
  hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> activeVehicles; // [rsp+20h] [rbp-28h] BYREF
  void *p; // [rsp+30h] [rbp-18h]
  int v16; // [rsp+38h] [rbp-10h]

  m_size = this->m_registeredVehicles.m_size;
  activeVehicles.m_capacityAndFlags = 0x80000000;
  activeVehicles.m_data = 0i64;
  activeVehicles.m_size = 0;
  v16 = m_size;
  if ( m_size )
  {
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (hkpVehicleInstance **)Value->m_cur;
    v7 = (8 * m_size + 127) & 0xFFFFFF80;
    v8 = (char *)m_cur + v7;
    if ( v7 > Value->m_slabSize || v8 > Value->m_end )
      m_cur = (hkpVehicleInstance **)hkLifoAllocator::allocateFromNewSlab(Value, v7);
    else
      Value->m_cur = v8;
  }
  else
  {
    m_cur = 0i64;
  }
  activeVehicles.m_data = m_cur;
  p = m_cur;
  activeVehicles.m_capacityAndFlags = m_size | 0x80000000;
  hkpVehicleManager::getActiveVehicles(this, &activeVehicles);
  v9 = activeVehicles.m_size;
  if ( activeVehicles.m_size )
  {
    hkpVehicleManager::stepVehicleArray(&activeVehicles, updatedStepInfo);
    v9 = activeVehicles.m_size;
  }
  v10 = (char *)p;
  if ( p == activeVehicles.m_data )
    v9 = 0;
  activeVehicles.m_size = v9;
  v11 = (8 * v16 + 127) & 0xFFFFFF80;
  v12 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v13 = (v11 + 15) & 0xFFFFFFF0;
  if ( v11 > v12->m_slabSize || &v10[v13] != v12->m_cur || v12->m_firstNonLifoEnd == v10 )
    hkLifoAllocator::slowBlockFree(v12, v10, v13);
  else
    v12->m_cur = v10;
  activeVehicles.m_size = 0;
  if ( activeVehicles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      activeVehicles.m_data,
      8 * activeVehicles.m_capacityAndFlags);
}

// File Line: 54
// RVA: 0xE2B7D0
void __fastcall hkpVehicleManager::stepVehicleArray(
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles,
        hkStepInfo *updatedStepInfo)
{
  hkLifoAllocator *Value; // rax
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *m_cur; // rdx
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *v6; // rcx
  hkLifoAllocator *v7; // rax
  float *v8; // rcx
  float *v9; // rdx
  hkLifoAllocator *v10; // rax
  float *v11; // rdi
  float *v12; // rcx
  __int64 m_size; // r14
  __int64 v14; // rsi
  hkpVehicleInstance *v15; // rbx
  int m_numWheels; // edi
  int v17; // r9d
  int v18; // edi
  int v19; // r9d
  int v20; // edi
  int v21; // r9d
  unsigned __int64 v22; // rdx
  _QWORD *v23; // r8
  _QWORD *v24; // rcx
  unsigned __int64 v25; // rax
  _QWORD *v26; // rcx
  _QWORD *v27; // r8
  _QWORD *v28; // rcx
  unsigned __int64 v29; // rax
  _QWORD *v30; // rcx
  signed int v31; // ebx
  hkLifoAllocator *v32; // rax
  int v33; // r8d
  int v34; // eax
  char *v35; // rdi
  signed int v36; // ebx
  hkLifoAllocator *v37; // rax
  int v38; // r8d
  int v39; // eax
  char *v40; // rdi
  signed int v41; // ebx
  hkLifoAllocator *v42; // rax
  int v43; // r8d
  hkArray<float,hkContainerHeapAllocator> suspensionForceAtWheel; // [rsp+30h] [rbp-59h] BYREF
  void *v45; // [rsp+40h] [rbp-49h]
  int v46; // [rsp+48h] [rbp-41h]
  hkArray<float,hkContainerHeapAllocator> v47; // [rsp+50h] [rbp-39h] BYREF
  void *p; // [rsp+60h] [rbp-29h]
  int v49; // [rsp+68h] [rbp-21h]
  hkpVehicleWheelCollide::CollisionDetectionWheelOutput *array; // [rsp+70h] [rbp-19h] BYREF
  int v51; // [rsp+78h] [rbp-11h]
  int v52; // [rsp+7Ch] [rbp-Dh]
  void *v53; // [rsp+80h] [rbp-9h]
  int v54; // [rsp+88h] [rbp-1h]
  hkpVehicleAerodynamics::AerodynamicsDragOutput aerodynamicsDragInfo; // [rsp+90h] [rbp+7h] BYREF
  hkResult result; // [rsp+F0h] [rbp+67h] BYREF
  hkResult v57; // [rsp+100h] [rbp+77h] BYREF
  hkResult v58; // [rsp+108h] [rbp+7Fh] BYREF

  v52 = 0x80000000;
  v54 = 32;
  array = 0i64;
  v51 = 0;
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)Value->m_cur;
  v6 = m_cur + 32;
  if ( Value->m_slabSize < 3072 || v6 > Value->m_end )
    m_cur = (hkpVehicleWheelCollide::CollisionDetectionWheelOutput *)hkLifoAllocator::allocateFromNewSlab(Value, 3072);
  else
    Value->m_cur = v6;
  array = m_cur;
  v52 = -2147483616;
  v53 = m_cur;
  suspensionForceAtWheel.m_data = 0i64;
  suspensionForceAtWheel.m_size = 0;
  suspensionForceAtWheel.m_capacityAndFlags = 0x80000000;
  v46 = 32;
  v7 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (float *)v7->m_cur;
  v9 = v8 + 32;
  if ( v7->m_slabSize < 128 || v9 > v7->m_end )
    v8 = (float *)hkLifoAllocator::allocateFromNewSlab(v7, 128);
  else
    v7->m_cur = v9;
  suspensionForceAtWheel.m_data = v8;
  v45 = v8;
  suspensionForceAtWheel.m_capacityAndFlags = -2147483616;
  v47.m_data = 0i64;
  v47.m_size = 0;
  v47.m_capacityAndFlags = 0x80000000;
  v49 = 32;
  v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v11 = (float *)v10->m_cur;
  v12 = v11 + 32;
  if ( v10->m_slabSize < 128 || v12 > v10->m_end )
    v11 = (float *)hkLifoAllocator::allocateFromNewSlab(v10, 128);
  else
    v10->m_cur = v12;
  m_size = activeVehicles->m_size;
  v47.m_data = v11;
  v47.m_capacityAndFlags = -2147483616;
  p = v11;
  v14 = 0i64;
  if ( m_size <= 0 )
    goto LABEL_35;
  do
  {
    v15 = activeVehicles->m_data[v14];
    m_numWheels = (unsigned __int8)v15->m_data->m_numWheels;
    if ( (v52 & 0x3FFFFFFF) >= m_numWheels )
    {
      result.m_enum = HK_SUCCESS;
    }
    else
    {
      v17 = (unsigned __int8)v15->m_data->m_numWheels;
      if ( m_numWheels < 2 * (v52 & 0x3FFFFFFF) )
        v17 = 2 * (v52 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v17, 96);
    }
    v51 = m_numWheels;
    v18 = (unsigned __int8)v15->m_data->m_numWheels;
    if ( (suspensionForceAtWheel.m_capacityAndFlags & 0x3FFFFFFF) >= v18 )
    {
      v57.m_enum = HK_SUCCESS;
    }
    else
    {
      v19 = (unsigned __int8)v15->m_data->m_numWheels;
      if ( v18 < 2 * (suspensionForceAtWheel.m_capacityAndFlags & 0x3FFFFFFF) )
        v19 = 2 * (suspensionForceAtWheel.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(
        &v57,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&suspensionForceAtWheel.m_data,
        v19,
        4);
    }
    suspensionForceAtWheel.m_size = v18;
    v20 = (unsigned __int8)v15->m_data->m_numWheels;
    if ( (v47.m_capacityAndFlags & 0x3FFFFFFF) >= v20 )
    {
      v58.m_enum = HK_SUCCESS;
    }
    else
    {
      v21 = (unsigned __int8)v15->m_data->m_numWheels;
      if ( v20 < 2 * (v47.m_capacityAndFlags & 0x3FFFFFFF) )
        v21 = 2 * (v47.m_capacityAndFlags & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&v58, &hkContainerHeapAllocator::s_alloc, (const void **)&v47.m_data, v21, 4);
    }
    v47.m_size = v20;
    hkpVehicleInstance::updateBeforeCollisionDetection(v15);
    v23 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v24 = (_QWORD *)v23[1];
    if ( (unsigned __int64)v24 < v23[3] )
    {
      *v24 = "TtVehicleJob";
      v25 = __rdtsc();
      v22 = (unsigned __int64)HIDWORD(v25) << 32;
      v26 = v24 + 2;
      *((_DWORD *)v26 - 2) = v25;
      v23[1] = v26;
    }
    ((void (__fastcall *)(hkpVehicleWheelCollide *, unsigned __int64, hkpVehicleInstance *, hkpVehicleWheelCollide::CollisionDetectionWheelOutput *))v15->m_wheelCollide->vfptr[2].__vecDelDtor)(
      v15->m_wheelCollide,
      v22,
      v15,
      array);
    hkpVehicleInstance::updateComponents(v15, updatedStepInfo, array, &aerodynamicsDragInfo);
    hkpVehicleInstance::simulateVehicle(
      v15,
      updatedStepInfo,
      &aerodynamicsDragInfo,
      &suspensionForceAtWheel,
      &v47,
      0i64);
    v27 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
    v28 = (_QWORD *)v27[1];
    if ( (unsigned __int64)v28 < v27[3] )
    {
      *v28 = "Et";
      v29 = __rdtsc();
      v30 = v28 + 2;
      *((_DWORD *)v30 - 2) = v29;
      v27[1] = v30;
    }
    ++v14;
  }
  while ( v14 < m_size );
  v11 = (float *)p;
  if ( p == v47.m_data )
LABEL_35:
    v47.m_size = 0;
  v31 = (4 * v49 + 127) & 0xFFFFFF80;
  v32 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v33 = (v31 + 15) & 0xFFFFFFF0;
  if ( v31 > v32->m_slabSize || (char *)v11 + v33 != v32->m_cur || v32->m_firstNonLifoEnd == v11 )
    hkLifoAllocator::slowBlockFree(v32, (char *)v11, v33);
  else
    v32->m_cur = v11;
  v47.m_size = 0;
  if ( v47.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v47.m_data,
      4 * v47.m_capacityAndFlags);
  v34 = suspensionForceAtWheel.m_size;
  v35 = (char *)v45;
  v47.m_data = 0i64;
  v47.m_capacityAndFlags = 0x80000000;
  if ( v45 == suspensionForceAtWheel.m_data )
    v34 = 0;
  suspensionForceAtWheel.m_size = v34;
  v36 = (4 * v46 + 127) & 0xFFFFFF80;
  v37 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v38 = (v36 + 15) & 0xFFFFFFF0;
  if ( v36 > v37->m_slabSize || &v35[v38] != v37->m_cur || v37->m_firstNonLifoEnd == v35 )
    hkLifoAllocator::slowBlockFree(v37, v35, v38);
  else
    v37->m_cur = v35;
  suspensionForceAtWheel.m_size = 0;
  if ( suspensionForceAtWheel.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      suspensionForceAtWheel.m_data,
      4 * suspensionForceAtWheel.m_capacityAndFlags);
  v39 = v51;
  v40 = (char *)v53;
  suspensionForceAtWheel.m_data = 0i64;
  suspensionForceAtWheel.m_capacityAndFlags = 0x80000000;
  if ( v53 == array )
    v39 = 0;
  v51 = v39;
  v41 = (96 * v54 + 127) & 0xFFFFFF80;
  v42 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v43 = (v41 + 15) & 0xFFFFFFF0;
  if ( v41 > v42->m_slabSize || &v40[v43] != v42->m_cur || v42->m_firstNonLifoEnd == v40 )
    hkLifoAllocator::slowBlockFree(v42, v40, v43);
  else
    v42->m_cur = v40;
  v51 = 0;
  if ( v52 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 96 * (v52 & 0x3FFFFFFF));
}

// File Line: 85
// RVA: 0xE2B5E0
void __fastcall hkpVehicleManager::getActiveVehicles(
        hkpVehicleManager *this,
        hkArray<hkpVehicleInstance *,hkContainerHeapAllocator> *activeVehicles)
{
  int v2; // edi
  __int64 v5; // rsi
  hkpVehicleInstance *v6; // r14
  hkBool result; // [rsp+40h] [rbp+8h] BYREF

  v2 = 0;
  if ( this->m_registeredVehicles.m_size > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = this->m_registeredVehicles.m_data[v5];
      if ( hkpEntity::isActive(v6->m_entity, &result)->m_bool )
      {
        if ( activeVehicles->m_size == (activeVehicles->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&activeVehicles->m_data, 8);
        activeVehicles->m_data[activeVehicles->m_size++] = v6;
      }
      ++v2;
      ++v5;
    }
    while ( v2 < this->m_registeredVehicles.m_size );
  }
}

// File Line: 97
// RVA: 0xE2BCB0
void __fastcall hkpVehicleManager::addToWorld(hkpVehicleManager *this, hkpWorld *world)
{
  __int64 m_size; // rsi
  __int64 i; // rbx
  hkpVehicleInstance *v6; // rcx

  m_size = this->m_registeredVehicles.m_size;
  for ( i = 0i64; i < m_size; ++i )
  {
    v6 = this->m_registeredVehicles.m_data[i];
    ((void (__fastcall *)(hkpVehicleInstance *, hkpWorld *))v6->vfptr[4].__first_virtual_table_function__)(v6, world);
  }
}

// File Line: 106
// RVA: 0xE2BD20
void __fastcall hkpVehicleManager::removeFromWorld(hkpVehicleManager *this)
{
  __int64 m_size; // rsi
  __int64 i; // rbx
  hkpVehicleInstance *v4; // rcx

  m_size = this->m_registeredVehicles.m_size;
  for ( i = 0i64; i < m_size; ++i )
  {
    v4 = this->m_registeredVehicles.m_data[i];
    ((void (__fastcall *)(hkpVehicleInstance *))v4->vfptr[5].__vecDelDtor)(v4);
  }
}

