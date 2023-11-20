// File Line: 22
// RVA: 0xD8AD70
void __fastcall hkpEndOfStepCallbackUtil::hkpEndOfStepCallbackUtil(hkpEndOfStepCallbackUtil *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpEndOfStepCallbackUtil::`vftable{for `hkReferencedObject};
  this->vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpEndOfStepCallbackUtil::`vftable{for `hkpWorldPostSimulationListener};
  this->m_sequenceNumber = 0;
  this->m_deterministicOrder.m_bool = 0;
  this->m_collisions.m_data = 0i64;
  this->m_collisions.m_size = 0;
  this->m_collisions.m_capacityAndFlags = 2147483648;
  this->m_newCollisions.m_data = 0i64;
  this->m_newCollisions.m_size = 0;
  this->m_newCollisions.m_capacityAndFlags = 2147483648;
  this->m_removedCollisions.m_data = 0i64;
  this->m_removedCollisions.m_size = 0;
  this->m_removedCollisions.m_capacityAndFlags = 2147483648;
}

// File Line: 26
// RVA: 0xD8AC50
void __fastcall hkpEndOfStepCallbackUtil::registerCollision(hkpEndOfStepCallbackUtil *this, hkpSimpleConstraintContactMgr *mgr, hkpContactListener *listener, hkpCollisionEvent::CallbackSource source)
{
  hkpCollisionEvent::CallbackSource v4; // esi
  hkpContactListener *v5; // rbp
  hkpSimpleConstraintContactMgr *v6; // r14
  hkpEndOfStepCallbackUtil *v7; // rdi
  signed __int64 v8; // rcx

  v4 = source;
  v5 = listener;
  v6 = mgr;
  v7 = this;
  if ( this->m_newCollisions.m_size == (this->m_newCollisions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &this->m_newCollisions, 32);
  v8 = (signed __int64)&v7->m_newCollisions.m_data[v7->m_newCollisions.m_size++];
  *(_QWORD *)(v8 + 8) = v5;
  *(_DWORD *)(v8 + 16) = v4;
  *(_QWORD *)v8 = v6;
  *(_DWORD *)(v8 + 24) = v7->m_sequenceNumber++;
}

// File Line: 37
// RVA: 0xD8ACF0
void __fastcall hkpEndOfStepCallbackUtil::unregisterCollision(hkpEndOfStepCallbackUtil *this, hkpSimpleConstraintContactMgr *mgr, hkpContactListener *listener, hkpCollisionEvent::CallbackSource source)
{
  signed int *v4; // rbx
  hkpCollisionEvent::CallbackSource v5; // edi
  hkpContactListener *v6; // rsi
  hkpSimpleConstraintContactMgr *v7; // rbp
  __int64 v8; // rdx
  signed __int64 v9; // r8

  v4 = (signed int *)&this->m_removedCollisions;
  v5 = source;
  v6 = listener;
  v7 = mgr;
  if ( this->m_removedCollisions.m_size == (this->m_removedCollisions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 24);
  v8 = v4[2];
  v9 = *(_QWORD *)v4 + 24 * v8;
  v4[2] = v8 + 1;
  *(_QWORD *)v9 = v7;
  *(_QWORD *)(v9 + 8) = v6;
  *(_DWORD *)(v9 + 16) = v5;
}

// File Line: 45
// RVA: 0xD8B310
hkBool *__fastcall hkpEndOfStepCallbackUtil::Collision::operator==(hkpEndOfStepCallbackUtil::Collision *this, hkBool *result, hkpEndOfStepCallbackUtil::Collision *other)
{
  hkBool *v3; // rax

  if ( *(_OWORD *)&other->m_mgr != *(_OWORD *)&this->m_mgr || other->m_source != this->m_source )
  {
    result->m_bool = 0;
    v3 = result;
  }
  else
  {
    result->m_bool = 1;
    v3 = result;
  }
  return v3;
}

// File Line: 69
// RVA: 0xD8B340
void __fastcall mergeArrays(hkArray<hkpEndOfStepCallbackUtil::NewCollision,hkContainerHeapAllocator> *source, hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *target)
{
  hkpEndOfStepCallbackUtil::NewCollision *v2; // rbx
  int v3; // er8
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v4; // r14
  hkArray<hkpEndOfStepCallbackUtil::NewCollision,hkContainerHeapAllocator> *v5; // r15
  hkpEndOfStepCallbackUtil::NewCollision *v6; // rdi
  int v7; // edx
  bool v8; // zf
  int v9; // edx
  int v10; // esi
  hkRelocationInfo::Import *v11; // rcx
  hkRelocationInfo::Import *v12; // r11
  int v13; // eax
  unsigned __int64 v14; // rsi
  hkpSimpleConstraintContactMgr *v15; // rax
  const char *v16; // rax
  const char *v17; // rax
  hkpSimpleConstraintContactMgr *v18; // rax
  const char *v19; // rax
  int v20; // eax
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+20h] [rbp-28h]
  int v22; // [rsp+50h] [rbp+8h]

  v2 = source->m_data;
  v3 = source->m_size;
  v4 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)target;
  v5 = source;
  v6 = &source->m_data[source->m_size];
  if ( source->m_data != v6 )
  {
    v7 = target->m_size;
    v8 = v3 + v7 == 0;
    v9 = v3 + v7;
    v10 = v9;
    if ( v8 )
    {
      v11 = 0i64;
    }
    else
    {
      v22 = 24 * v9;
      v11 = (hkRelocationInfo::Import *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                          &v22);
      v9 = v22 / 24;
    }
    v12 = v4->m_data;
    v13 = 2147483648;
    if ( v9 )
      v13 = v9;
    a.m_size = v10;
    a.m_data = v11;
    a.m_capacityAndFlags = v13;
    v14 = (unsigned __int64)v12 + 24 * v4->m_size;
    if ( v2 < v6 )
    {
      while ( (unsigned __int64)v12 < v14 )
      {
        if ( (v2->m_mgr->m_constraint.m_entities[1]->m_uid | ((unsigned __int64)v2->m_mgr->m_constraint.m_entities[0]->m_uid << 32)) >= (*(unsigned int *)(*(_QWORD *)(*(_QWORD *)&v12->m_fromOffset + 168i64) + 308i64) | ((unsigned __int64)*(unsigned int *)(*(_QWORD *)(*(_QWORD *)&v12->m_fromOffset + 160i64) + 308i64) << 32)) )
        {
          *(_QWORD *)&v11->m_fromOffset = *(_QWORD *)&v12->m_fromOffset;
          v17 = v12->m_identifier;
          v12 = (hkRelocationInfo::Import *)((char *)v12 + 24);
          v11->m_identifier = v17;
          v16 = v12[-1].m_identifier;
        }
        else
        {
          v15 = v2->m_mgr;
          ++v2;
          *(_QWORD *)&v11->m_fromOffset = v15;
          v11->m_identifier = (const char *)v2[-1].m_listener;
          v16 = *(const char **)&v2[-1].m_source;
        }
        *(_QWORD *)&v11[1].m_fromOffset = v16;
        v11 = (hkRelocationInfo::Import *)((char *)v11 + 24);
        if ( v2 >= v6 )
          goto LABEL_16;
      }
      for ( ; v2 < v6; v11[-1].m_identifier = *(const char **)&v2[-1].m_source )
      {
        v18 = v2->m_mgr;
        ++v2;
        v11 = (hkRelocationInfo::Import *)((char *)v11 + 24);
        v11[-2].m_identifier = (const char *)v18;
        *(_QWORD *)&v11[-1].m_fromOffset = v2[-1].m_listener;
      }
    }
LABEL_16:
    while ( (unsigned __int64)v12 < v14 )
    {
      v19 = *(const char **)&v12->m_fromOffset;
      v12 = (hkRelocationInfo::Import *)((char *)v12 + 24);
      v11 = (hkRelocationInfo::Import *)((char *)v11 + 24);
      v11[-2].m_identifier = v19;
      *(_QWORD *)&v11[-1].m_fromOffset = *(_QWORD *)&v12[-1].m_fromOffset;
      v11[-1].m_identifier = v12[-1].m_identifier;
    }
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(v4, &a);
    v20 = a.m_capacityAndFlags;
    v5->m_size = 0;
    if ( v20 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        a.m_data,
        24 * (v20 & 0x3FFFFFFF));
  }
}

// File Line: 118
// RVA: 0xD8B810
void __fastcall stripArray_hkpEndOfStepCallbackUtil::Collision_(hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *removals, hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *target, __int64 a3)
{
  __int64 v3; // r15
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v4; // rbx
  hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *v5; // r9
  int v6; // edx
  __int64 v7; // rax
  char *v8; // r8
  unsigned int v9; // eax
  int v10; // ecx
  __int64 v11; // rdx
  __int64 v12; // r15
  hkRelocationInfo::Import *v13; // r12
  __int64 v14; // r13
  int v15; // edi
  __int64 v16; // rbx
  hkpEndOfStepCallbackUtil::Collision *v17; // rbp
  hkpEndOfStepCallbackUtil::Collision *v18; // r14
  char *v19; // rcx
  signed __int64 v20; // rbx
  signed __int64 v21; // rdx
  signed __int64 v22; // rax
  __int64 v23; // rcx
  int v24; // eax
  int v25; // er15
  int v26; // eax
  int v27; // er9
  int v28; // [rsp+30h] [rbp-78h]
  int v29; // [rsp+34h] [rbp-74h]
  __int64 v30; // [rsp+38h] [rbp-70h]
  __int64 v31; // [rsp+40h] [rbp-68h]
  char *array; // [rsp+48h] [rbp-60h]
  int v33; // [rsp+50h] [rbp-58h]
  int v34; // [rsp+54h] [rbp-54h]
  hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *v35; // [rsp+B0h] [rbp+8h]
  hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *v36; // [rsp+B8h] [rbp+10h]
  int result; // [rsp+C0h] [rbp+18h]
  int v38; // [rsp+C8h] [rbp+20h]

  v36 = target;
  v35 = removals;
  v3 = target->m_size;
  v4 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)target;
  v5 = removals;
  v29 = removals->m_size;
  v28 = target->m_size;
  if ( v29 )
  {
    array = 0i64;
    v6 = v3;
    v33 = 0;
    v34 = 2147483648;
    if ( (_DWORD)v3 )
    {
      result = 24 * v3;
      v7 = ((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, __int64, hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
             &hkContainerHeapAllocator::s_alloc,
             &result,
             a3,
             removals);
      v5 = v35;
      v8 = (char *)v7;
      v6 = result / 24;
    }
    else
    {
      v8 = 0i64;
    }
    v9 = 2147483648;
    array = v8;
    if ( v6 )
      v9 = v6;
    v10 = 0;
    v11 = v3;
    v38 = 0;
    v30 = v3;
    v33 = v3;
    v34 = v9;
    if ( (signed int)v3 > 0 )
    {
      v31 = 0i64;
      v12 = 0i64;
      do
      {
        v13 = v4->m_data;
        v14 = v5->m_size;
        v15 = 0;
        v16 = 0i64;
        v17 = (hkpEndOfStepCallbackUtil::Collision *)((char *)v13 + 24 * v10);
        if ( (signed int)v14 <= 0 )
        {
LABEL_14:
          v19 = array;
          *(_QWORD *)&array[v31] = *(_QWORD *)((char *)&v13->m_fromOffset + v12);
          v20 = v31 + 24;
          *(_QWORD *)&v19[v20 - 16] = *(const char **)((char *)&v13->m_identifier + v12);
          v31 += 24i64;
          *(_QWORD *)&v19[v20 - 8] = *(_QWORD *)((char *)&v13[1].m_fromOffset + v12);
        }
        else
        {
          v18 = v5->m_data;
          while ( !hkpEndOfStepCallbackUtil::Collision::operator==(&v18[v15], (hkBool *)&result, v17)->m_bool )
          {
            ++v16;
            ++v15;
            if ( v16 >= v14 )
              goto LABEL_13;
          }
          if ( v16 == -1 )
          {
LABEL_13:
            v11 = v30;
            v5 = v35;
            goto LABEL_14;
          }
          v5 = v35;
          v35->m_size = v14 - 1;
          if ( (_DWORD)v14 - 1 != v15 )
          {
            v21 = 3i64;
            v22 = (signed __int64)&v18[v16];
            do
            {
              v23 = *(_QWORD *)(24i64 * ((signed int)v14 - 1) - 24 * v16 + v22);
              v22 += 8i64;
              *(_QWORD *)(v22 - 8) = v23;
              --v21;
            }
            while ( v21 );
          }
          v11 = v30;
        }
        v4 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v36;
        v12 += 24i64;
        v10 = v38 + 1;
        v30 = --v11;
        ++v38;
      }
      while ( v11 );
      v9 = v34;
      LODWORD(v3) = v28;
    }
    v24 = v9 & 0x3FFFFFFF;
    v25 = v5->m_size + v3 - v29;
    if ( v24 < v25 )
    {
      v26 = 2 * v24;
      v27 = v25;
      if ( v25 < v26 )
        v27 = v26;
      hkArrayUtil::_reserve(
        (hkResult *)&v35,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &array,
        v27,
        24);
    }
    v33 = v25;
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
      v4,
      (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
    v33 = 0;
    if ( v34 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        24 * (v34 & 0x3FFFFFFF));
  }
}

// File Line: 151
// RVA: 0xD8AF40
void __fastcall hkpEndOfStepCallbackUtil::postSimulationCallback(hkpEndOfStepCallbackUtil *this, hkpWorld *world)
{
  hkpEndOfStepCallbackUtil *v2; // r13
  _QWORD *v3; // r8
  _QWORD *v4; // rcx
  unsigned __int64 v5; // rax
  signed __int64 v6; // rcx
  signed int v7; // er8
  int v8; // ebx
  __int64 v9; // rsi
  int v10; // er9
  int v11; // eax
  int v12; // eax
  hkpWorldPostSimulationListenerVtbl *v13; // rax
  int v14; // er9
  signed __int64 v15; // rdx
  __int64 v16; // r8
  hkpEndOfStepCallbackUtil::Collision *v17; // rcx
  __int64 v18; // rbp
  char v19; // bl
  __int64 v20; // rsi
  hkpWorldPostSimulationListenerVtbl *v21; // rdi
  hkpSimpleConstraintContactMgr *v22; // r14
  __int64 v23; // rax
  int v24; // edx
  hkpConstraintInstance *v25; // r10
  __int64 v26; // rax
  __int64 v27; // r8
  int v28; // edx
  __int64 v29; // rcx
  void (__fastcall **v30)(hkpWorldPostSimulationListener *, hkpWorld *); // rax
  __int64 v31; // rdi
  __int32 v32; // edx
  char *v33; // r10
  unsigned int v34; // eax
  int v35; // ebx
  __int64 v36; // r8
  __int64 v37; // r9
  __int64 v38; // rdx
  hkpWorldPostSimulationListenerVtbl *v39; // rcx
  int v40; // eax
  int v41; // eax
  int v42; // er9
  _QWORD *v43; // rax
  _QWORD *v44; // rcx
  _QWORD *v45; // r8
  unsigned __int64 v46; // rax
  signed __int64 v47; // rcx
  char *array; // [rsp+30h] [rbp-38h]
  int v49; // [rsp+38h] [rbp-30h]
  int v50; // [rsp+3Ch] [rbp-2Ch]
  hkResult result; // [rsp+70h] [rbp+8h]

  v2 = this;
  v3 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v4 = (_QWORD *)v3[1];
  if ( (unsigned __int64)v4 < v3[3] )
  {
    *v4 = "TtEndOfStepCbs";
    v5 = __rdtsc();
    v6 = (signed __int64)(v4 + 2);
    *(_DWORD *)(v6 - 8) = v5;
    v3[1] = v6;
  }
  stripArray_hkpEndOfStepCallbackUtil::NewCollision_(
    (hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *)&v2->m_newCollisions,
    (hkArray<hkpEndOfStepCallbackUtil::NewCollision,hkContainerHeapAllocator> *)&v2->m_collisions);
  stripArray_hkpEndOfStepCallbackUtil::Collision_(
    (hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *)&v2->m_newCollisions,
    (hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *)&v2->vfptr);
  if ( *((_BYTE *)&v2->m_referenceCount + 2) )
  {
    v7 = v2->m_collisions.m_size;
    if ( v7 > 1 )
      hkAlgorithm::quickSortRecursive<hkpEndOfStepCallbackUtil::NewCollision,hkAlgorithm::less<hkpEndOfStepCallbackUtil::NewCollision>>(
        (hkpEndOfStepCallbackUtil::NewCollision *)v2->m_collisions.m_data,
        0,
        v7 - 1,
        0);
    mergeArrays(
      (hkArray<hkpEndOfStepCallbackUtil::NewCollision,hkContainerHeapAllocator> *)&v2->m_collisions,
      (hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *)&v2->vfptr);
  }
  else
  {
    v8 = v2->m_collisions.m_size;
    v9 = v2->m_sequenceNumber;
    v10 = v9 + v8;
    v11 = *(_DWORD *)&v2->m_deterministicOrder.m_bool & 0x3FFFFFFF;
    if ( v11 < (signed int)v9 + v8 )
    {
      v12 = 2 * v11;
      if ( v10 < v12 )
        v10 = v12;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->vfptr, v10, 24);
    }
    v13 = v2->vfptr;
    v2->m_sequenceNumber += v8;
    v14 = 0;
    v15 = (signed __int64)&v13[v9];
    if ( v2->m_collisions.m_size > 0 )
    {
      v16 = 0i64;
      do
      {
        v17 = v2->m_collisions.m_data;
        ++v14;
        v16 += 32i64;
        v15 += 24i64;
        *(_QWORD *)(v15 - 24) = *(_QWORD *)((char *)&v17[-1] + v16 - 8);
        *(_QWORD *)(v15 - 16) = *(hkpSimpleConstraintContactMgr **)((char *)&v17[-1].m_mgr + v16);
        *(_QWORD *)(v15 - 8) = *(_QWORD *)((char *)v17 + v16 - 16);
      }
      while ( v14 < v2->m_collisions.m_size );
    }
    v2->m_collisions.m_size = 0;
  }
  v18 = v2->m_sequenceNumber;
  v19 = 0;
  if ( v18 > 0 )
  {
    v20 = 0i64;
    while ( 1 )
    {
      v21 = &v2->vfptr[v20];
      v22 = (hkpSimpleConstraintContactMgr *)v21->__vecDelDtor;
      v23 = (*(__int64 (__fastcall **)(void *(__fastcall *)(hkpWorldPostSimulationListener *, unsigned int)))(*(_QWORD *)v21->__vecDelDtor + 128i64))(v21->__vecDelDtor);
      v24 = (int)v21->inactiveEntityMovedCallback;
      v25 = (hkpConstraintInstance *)v23;
      if ( v24 )
      {
        if ( v24 != 1 )
          goto LABEL_29;
        v26 = *(_QWORD *)(v23 + 48);
      }
      else
      {
        v26 = *(_QWORD *)(v23 + 40);
      }
      if ( !v26 )
        goto LABEL_29;
      v27 = *(unsigned __int16 *)(v26 + 664);
      v28 = 0;
      v29 = 0i64;
      if ( v27 > 0 )
      {
        v30 = *(void (__fastcall ***)(hkpWorldPostSimulationListener *, hkpWorld *))(v26 + 656);
        while ( *v30 != v21->postSimulationCallback )
        {
          ++v29;
          ++v28;
          ++v30;
          if ( v29 >= v27 )
          {
            v19 = 1;
            v21->postSimulationCallback = 0i64;
            goto LABEL_31;
          }
        }
        if ( v28 != -1 )
        {
LABEL_29:
          if ( *((_BYTE *)hkpConstraintInstance::getSimulationIsland(v25) + 50) & 0xC )
            hkpEndOfStepCallbackUtil::fireContactPointEventsForCollision(
              v22,
              (hkpContactListener *)v21->postSimulationCallback,
              (hkpCollisionEvent::CallbackSource)v21->inactiveEntityMovedCallback);
          goto LABEL_31;
        }
      }
      v19 = 1;
      v21->postSimulationCallback = 0i64;
LABEL_31:
      ++v20;
      if ( !--v18 )
      {
        if ( v19 )
        {
          v31 = v2->m_sequenceNumber;
          array = 0i64;
          v49 = 0;
          v32 = v31;
          v50 = 2147483648;
          if ( (_DWORD)v31 )
          {
            result.m_enum = 24 * v31;
            v33 = (char *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                            (int *)&result);
            v32 = result.m_enum / 24;
          }
          else
          {
            v33 = 0i64;
          }
          v34 = 2147483648;
          array = v33;
          if ( v32 )
            v34 = v32;
          v49 = v31;
          v35 = 0;
          v50 = v34;
          v36 = v31;
          if ( (signed int)v31 > 0 )
          {
            v37 = 0i64;
            v38 = 0i64;
            do
            {
              v39 = &v2->vfptr[v38];
              if ( v39->postSimulationCallback )
              {
                ++v35;
                v37 += 24i64;
                *(_QWORD *)&v33[v37 - 24] = v39->__vecDelDtor;
                *(_QWORD *)&v33[v37 - 16] = v39->postSimulationCallback;
                *(_QWORD *)&v33[v37 - 8] = v39->inactiveEntityMovedCallback;
                v33 = array;
              }
              ++v38;
              --v36;
            }
            while ( v36 );
            v34 = v50;
          }
          v40 = v34 & 0x3FFFFFFF;
          if ( v40 < v35 )
          {
            v41 = 2 * v40;
            v42 = v35;
            if ( v35 < v41 )
              v42 = v41;
            hkArrayUtil::_reserve(
              &result,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &array,
              v42,
              24);
          }
          v49 = v35;
          hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->vfptr,
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&array);
          v49 = 0;
          if ( v50 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              array,
              24 * (v50 & 0x3FFFFFFF));
        }
        break;
      }
    }
  }
  *(_DWORD *)&v2->m_memSizeAndFlags = 0;
  v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v44 = (_QWORD *)v43[1];
  v45 = v43;
  if ( (unsigned __int64)v44 < v43[3] )
  {
    *v44 = "Et";
    v46 = __rdtsc();
    v47 = (signed __int64)(v44 + 2);
    *(_DWORD *)(v47 - 8) = v46;
    v45[1] = v47;
  }
}ue(hkMonitorStream__m_instance.m_slo

// File Line: 249
// RVA: 0xD8ADD0
void __fastcall hkpEndOfStepCallbackUtil::fireContactPointEventsForCollision(hkpSimpleConstraintContactMgr *mgr, hkpContactListener *listener, hkpCollisionEvent::CallbackSource source)
{
  hkpContactListener *v3; // r14
  hkpSimpleConstraintContactMgr *v4; // r12
  __int64 v5; // rax
  hkpSimpleContactConstraintAtom *v6; // r9
  __int64 v7; // r15
  int v8; // er13
  signed __int64 v9; // rsi
  signed __int64 v10; // rbx
  bool v11; // bp
  int v12; // er13
  int i; // edi
  hkpContactListenerVtbl *v14; // rax
  hkpCollisionEvent::CallbackSource v15; // [rsp+20h] [rbp-A8h]
  __int64 v16; // [rsp+28h] [rbp-A0h]
  __int64 v17; // [rsp+30h] [rbp-98h]
  hkpSimpleConstraintContactMgr *v18; // [rsp+38h] [rbp-90h]
  int v19; // [rsp+40h] [rbp-88h]
  __int64 v20; // [rsp+48h] [rbp-80h]
  __int64 v21; // [rsp+50h] [rbp-78h]
  bool v22; // [rsp+58h] [rbp-70h]
  bool v23; // [rsp+59h] [rbp-6Fh]
  bool v24; // [rsp+5Ah] [rbp-6Eh]
  __int128 v25; // [rsp+60h] [rbp-68h]
  __int64 v26; // [rsp+70h] [rbp-58h]
  __int64 v27; // [rsp+78h] [rbp-50h]
  __int64 v28; // [rsp+80h] [rbp-48h]
  __int64 v29; // [rsp+D0h] [rbp+8h]
  hkpCollisionEvent::CallbackSource v30; // [rsp+E0h] [rbp+18h]
  __int64 v31; // [rsp+E8h] [rbp+20h]

  v30 = source;
  v3 = listener;
  v4 = mgr;
  v29 = *(_QWORD *)(((__int64 (*)(void))mgr->vfptr[8].__vecDelDtor)() + 40);
  v5 = ((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *))v4->vfptr[8].__vecDelDtor)(v4);
  v6 = v4->m_contactConstraintData.m_atom;
  v7 = (unsigned __int8)v6->m_contactPointPropertiesStriding;
  v8 = v6->m_numContactPoints;
  v31 = *(_QWORD *)(v5 + 48);
  v9 = (signed __int64)&v6[1];
  v10 = (signed __int64)&v6[1] + 32 * v6->m_numReservedContactPoints;
  v11 = (*(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *))v4->vfptr[8].__vecDelDtor)(v4)
                              + 96)
                  + 34i64) & 8) != 0;
  v12 = v8 - 1;
  for ( i = v12; i >= 0; --i )
  {
    if ( *(_BYTE *)(v10 + 19) & 1 || v11 )
    {
      v15 = v30;
      _mm_store_si128((__m128i *)&v25, (__m128i)0i64);
      v16 = v29;
      v24 = i == 0;
      v17 = v31;
      v18 = v4;
      v23 = i == v12;
      v19 = 3;
      v26 = v10 + 32;
      v14 = v3->vfptr;
      v20 = v9;
      v21 = v10;
      v22 = v11;
      v27 = 0i64;
      v28 = 0i64;
      v14->contactPointCallback(v3, (hkpContactPointEvent *)&v15);
    }
    v9 += 32i64;
    v10 += v7;
  }
}

