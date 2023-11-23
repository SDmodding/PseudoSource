// File Line: 22
// RVA: 0xD8AD70
void __fastcall hkpEndOfStepCallbackUtil::hkpEndOfStepCallbackUtil(hkpEndOfStepCallbackUtil *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->hkReferencedObject::hkBaseObject::vfptr = (hkBaseObjectVtbl *)&hkpEndOfStepCallbackUtil::`vftable{for `hkReferencedObject};
  this->hkpWorldPostSimulationListener::vfptr = (hkpWorldPostSimulationListenerVtbl *)&hkpEndOfStepCallbackUtil::`vftable{for `hkpWorldPostSimulationListener};
  this->m_sequenceNumber = 0;
  this->m_deterministicOrder.m_bool = 0;
  this->m_collisions.m_data = 0i64;
  this->m_collisions.m_size = 0;
  this->m_collisions.m_capacityAndFlags = 0x80000000;
  this->m_newCollisions.m_data = 0i64;
  this->m_newCollisions.m_size = 0;
  this->m_newCollisions.m_capacityAndFlags = 0x80000000;
  this->m_removedCollisions.m_data = 0i64;
  this->m_removedCollisions.m_size = 0;
  this->m_removedCollisions.m_capacityAndFlags = 0x80000000;
}

// File Line: 26
// RVA: 0xD8AC50
void __fastcall hkpEndOfStepCallbackUtil::registerCollision(
        hkpEndOfStepCallbackUtil *this,
        hkpSimpleConstraintContactMgr *mgr,
        hkpContactListener *listener,
        hkpCollisionEvent::CallbackSource source)
{
  hkpEndOfStepCallbackUtil::NewCollision *v8; // rcx

  if ( this->m_newCollisions.m_size == (this->m_newCollisions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_newCollisions.m_data, 32);
  v8 = &this->m_newCollisions.m_data[this->m_newCollisions.m_size++];
  v8->m_listener = listener;
  v8->m_source = source;
  v8->m_mgr = mgr;
  v8->m_sequenceNumber = this->m_sequenceNumber++;
}

// File Line: 37
// RVA: 0xD8ACF0
void __fastcall hkpEndOfStepCallbackUtil::unregisterCollision(
        hkpEndOfStepCallbackUtil *this,
        hkpSimpleConstraintContactMgr *mgr,
        hkpContactListener *listener,
        hkpCollisionEvent::CallbackSource source)
{
  hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *p_m_removedCollisions; // rbx
  __int64 m_size; // rdx
  __int64 v9; // r8

  p_m_removedCollisions = &this->m_removedCollisions;
  if ( this->m_removedCollisions.m_size == (this->m_removedCollisions.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_removedCollisions->m_data, 24);
  m_size = p_m_removedCollisions->m_size;
  v9 = (__int64)&p_m_removedCollisions->m_data[m_size];
  p_m_removedCollisions->m_size = m_size + 1;
  *(_QWORD *)v9 = mgr;
  *(_QWORD *)(v9 + 8) = listener;
  *(_DWORD *)(v9 + 16) = source;
}

// File Line: 45
// RVA: 0xD8B310
hkBool *__fastcall hkpEndOfStepCallbackUtil::Collision::operator==(
        hkpEndOfStepCallbackUtil::Collision *this,
        hkBool *result,
        hkpEndOfStepCallbackUtil::Collision *other)
{
  if ( other->m_mgr == this->m_mgr && other->m_listener == this->m_listener && other->m_source == this->m_source )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 69
// RVA: 0xD8B340
void __fastcall mergeArrays(
        hkArray<hkpEndOfStepCallbackUtil::NewCollision,hkContainerHeapAllocator> *source,
        hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *target)
{
  hkpEndOfStepCallbackUtil::NewCollision *m_data; // rbx
  int m_size; // r8d
  hkpEndOfStepCallbackUtil::NewCollision *v6; // rdi
  int v7; // edx
  bool v8; // zf
  int v9; // edx
  int v10; // esi
  hkRelocationInfo::Import *v11; // rcx
  hkpEndOfStepCallbackUtil::Collision *v12; // r11
  int v13; // eax
  hkpEndOfStepCallbackUtil::Collision *v14; // rsi
  hkpSimpleConstraintContactMgr *m_mgr; // rax
  __int64 v16; // rax
  hkpContactListener *m_listener; // rax
  hkpSimpleConstraintContactMgr *v18; // rax
  hkpSimpleConstraintContactMgr *v19; // rax
  int m_capacityAndFlags; // eax
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> a; // [rsp+20h] [rbp-28h] BYREF
  int v22; // [rsp+50h] [rbp+8h] BYREF

  m_data = source->m_data;
  m_size = source->m_size;
  v6 = &source->m_data[m_size];
  if ( source->m_data != v6 )
  {
    v7 = target->m_size;
    v8 = m_size + v7 == 0;
    v9 = m_size + v7;
    v10 = v9;
    if ( v8 )
    {
      v11 = 0i64;
    }
    else
    {
      v22 = 24 * v9;
      v11 = (hkRelocationInfo::Import *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                          &hkContainerHeapAllocator::s_alloc,
                                          &v22);
      v9 = v22 / 24;
    }
    v12 = (hkpEndOfStepCallbackUtil::Collision *)target->m_data;
    v13 = 0x80000000;
    if ( v9 )
      v13 = v9;
    a.m_size = v10;
    a.m_data = v11;
    a.m_capacityAndFlags = v13;
    v14 = &v12[target->m_size];
    if ( m_data < v6 )
    {
      while ( v12 < v14 )
      {
        if ( (m_data->m_mgr->m_constraint.m_entities[1]->m_uid | ((unsigned __int64)m_data->m_mgr->m_constraint.m_entities[0]->m_uid << 32)) >= (v12->m_mgr->m_constraint.m_entities[1]->m_uid | ((unsigned __int64)v12->m_mgr->m_constraint.m_entities[0]->m_uid << 32)) )
        {
          *(_QWORD *)&v11->m_fromOffset = v12->m_mgr;
          m_listener = v12->m_listener;
          ++v12;
          v11->m_identifier = (const char *)m_listener;
          v16 = *(_QWORD *)&v12[-1].m_source;
        }
        else
        {
          m_mgr = m_data->m_mgr;
          ++m_data;
          *(_QWORD *)&v11->m_fromOffset = m_mgr;
          v11->m_identifier = (const char *)m_data[-1].m_listener;
          v16 = *(_QWORD *)&m_data[-1].m_source;
        }
        *(_QWORD *)&v11[1].m_fromOffset = v16;
        v11 = (hkRelocationInfo::Import *)((char *)v11 + 24);
        if ( m_data >= v6 )
          goto LABEL_16;
      }
      for ( ; m_data < v6; v11[-1].m_identifier = *(const char **)&m_data[-1].m_source )
      {
        v18 = m_data->m_mgr;
        ++m_data;
        v11 = (hkRelocationInfo::Import *)((char *)v11 + 24);
        v11[-2].m_identifier = (const char *)v18;
        *(_QWORD *)&v11[-1].m_fromOffset = m_data[-1].m_listener;
      }
    }
LABEL_16:
    while ( v12 < v14 )
    {
      v19 = v12->m_mgr;
      ++v12;
      v11 = (hkRelocationInfo::Import *)((char *)v11 + 24);
      v11[-2].m_identifier = (const char *)v19;
      *(_QWORD *)&v11[-1].m_fromOffset = v12[-1].m_listener;
      v11[-1].m_identifier = *(const char **)&v12[-1].m_source;
    }
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(target, &a);
    m_capacityAndFlags = a.m_capacityAndFlags;
    source->m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        a.m_data,
        24 * (m_capacityAndFlags & 0x3FFFFFFF));
  }
}

// File Line: 118
// RVA: 0xD8B810
void __fastcall stripArray_hkpEndOfStepCallbackUtil::Collision_(
        hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *removals,
        hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *target,
        __int64 a3)
{
  __int64 m_size; // r15
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v4; // rbx
  hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *v5; // r9
  int v6; // edx
  __int64 v7; // rax
  hkRelocationInfo::Import *v8; // r8
  unsigned int m_capacityAndFlags; // eax
  int v10; // ecx
  __int64 v11; // rdx
  __int64 v12; // r15
  hkRelocationInfo::Import *m_data; // r12
  __int64 v14; // r13
  int v15; // edi
  __int64 v16; // rbx
  hkpEndOfStepCallbackUtil::Collision *v17; // rbp
  hkpEndOfStepCallbackUtil::Collision *v18; // r14
  hkRelocationInfo::Import *v19; // rcx
  __int64 v20; // rbx
  __int64 v21; // rdx
  hkpEndOfStepCallbackUtil::Collision *v22; // rax
  __int64 v23; // rcx
  int v24; // eax
  int v25; // r15d
  int v26; // eax
  int v27; // r9d
  int v28; // [rsp+30h] [rbp-78h]
  int v29; // [rsp+34h] [rbp-74h]
  __int64 v30; // [rsp+38h] [rbp-70h]
  __int64 v31; // [rsp+40h] [rbp-68h]
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> array[2]; // [rsp+48h] [rbp-60h] BYREF
  hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *v33; // [rsp+B0h] [rbp+8h] BYREF
  hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *v34; // [rsp+B8h] [rbp+10h]
  int result; // [rsp+C0h] [rbp+18h] BYREF
  int v36; // [rsp+C8h] [rbp+20h]

  v34 = target;
  v33 = removals;
  m_size = target->m_size;
  v4 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)target;
  v5 = removals;
  v29 = removals->m_size;
  v28 = target->m_size;
  if ( v29 )
  {
    array[0].m_data = 0i64;
    v6 = m_size;
    array[0].m_size = 0;
    array[0].m_capacityAndFlags = 0x80000000;
    if ( (_DWORD)m_size )
    {
      result = 24 * m_size;
      v7 = ((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, __int64, hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
             &hkContainerHeapAllocator::s_alloc,
             &result,
             a3,
             removals);
      v5 = v33;
      v8 = (hkRelocationInfo::Import *)v7;
      v6 = result / 24;
    }
    else
    {
      v8 = 0i64;
    }
    m_capacityAndFlags = 0x80000000;
    array[0].m_data = v8;
    if ( v6 )
      m_capacityAndFlags = v6;
    v10 = 0;
    v11 = m_size;
    v36 = 0;
    v30 = m_size;
    array[0].m_size = m_size;
    array[0].m_capacityAndFlags = m_capacityAndFlags;
    if ( (int)m_size > 0 )
    {
      v31 = 0i64;
      v12 = 0i64;
      do
      {
        m_data = v4->m_data;
        v14 = v5->m_size;
        v15 = 0;
        v16 = 0i64;
        v17 = (hkpEndOfStepCallbackUtil::Collision *)((char *)m_data + 24 * v10);
        if ( (int)v14 <= 0 )
        {
LABEL_14:
          v19 = array[0].m_data;
          *(_QWORD *)((char *)&array[0].m_data->m_fromOffset + v31) = *(_QWORD *)((char *)&m_data->m_fromOffset + v12);
          v20 = v31 + 24;
          *(_QWORD *)((char *)&v19[-1].m_fromOffset + v20) = *(const char **)((char *)&m_data->m_identifier + v12);
          v31 += 24i64;
          *(_QWORD *)((char *)v19 + v20 - 8) = *(_QWORD *)((char *)&m_data[1].m_fromOffset + v12);
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
            v5 = v33;
            goto LABEL_14;
          }
          v5 = v33;
          v33->m_size = v14 - 1;
          if ( (_DWORD)v14 - 1 != v15 )
          {
            v21 = 3i64;
            v22 = &v18[v16];
            do
            {
              v23 = *(__int64 *)((char *)&v22->m_mgr + 24i64 * ((int)v14 - 1) - 24 * v16);
              v22 = (hkpEndOfStepCallbackUtil::Collision *)((char *)v22 + 8);
              *(_QWORD *)&v22[-1].m_source = v23;
              --v21;
            }
            while ( v21 );
          }
          v11 = v30;
        }
        v4 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)v34;
        v12 += 24i64;
        v10 = v36 + 1;
        v30 = --v11;
        ++v36;
      }
      while ( v11 );
      m_capacityAndFlags = array[0].m_capacityAndFlags;
      LODWORD(m_size) = v28;
    }
    v24 = m_capacityAndFlags & 0x3FFFFFFF;
    v25 = v5->m_size + m_size - v29;
    if ( v24 < v25 )
    {
      v26 = 2 * v24;
      v27 = v25;
      if ( v25 < v26 )
        v27 = v26;
      hkArrayUtil::_reserve(
        (hkResult *)&v33,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&array[0].m_data,
        v27,
        24);
    }
    array[0].m_size = v25;
    hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(v4, array);
    array[0].m_size = 0;
    if ( array[0].m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        array[0].m_data,
        24 * (array[0].m_capacityAndFlags & 0x3FFFFFFF));
  }
}

// File Line: 151
// RVA: 0xD8AF40
void __fastcall hkpEndOfStepCallbackUtil::postSimulationCallback(hkpEndOfStepCallbackUtil *this, hkpWorld *world)
{
  _QWORD *Value; // r8
  _QWORD *v4; // rcx
  unsigned __int64 v5; // rax
  _QWORD *v6; // rcx
  int m_size; // r8d
  int v8; // ebx
  __int64 m_sequenceNumber; // rsi
  int v10; // r9d
  int v11; // eax
  int v12; // eax
  hkpWorldPostSimulationListenerVtbl *vfptr; // rax
  int v14; // r9d
  hkpWorldPostSimulationListenerVtbl *v15; // rdx
  __int64 v16; // r8
  hkpEndOfStepCallbackUtil::Collision *m_data; // rcx
  __int64 v18; // rbp
  char v19; // bl
  __int64 v20; // rsi
  hkpWorldPostSimulationListenerVtbl *v21; // rdi
  hkpSimpleConstraintContactMgr *vecDelDtor; // r14
  __int64 v23; // rax
  int inactiveEntityMovedCallback; // edx
  hkpConstraintInstance *v25; // r10
  __int64 v26; // rax
  __int64 v27; // r8
  int v28; // edx
  __int64 v29; // rcx
  void (__fastcall **v30)(hkpWorldPostSimulationListener *, hkpWorld *); // rax
  __int64 v31; // rdi
  __int32 v32; // edx
  hkRelocationInfo::Import *v33; // r10
  unsigned int m_capacityAndFlags; // eax
  int v35; // ebx
  __int64 v36; // r8
  __int64 v37; // r9
  __int64 v38; // rdx
  hkpWorldPostSimulationListenerVtbl *v39; // rcx
  int v40; // eax
  int v41; // eax
  int v42; // r9d
  _QWORD *v43; // rax
  _QWORD *v44; // rcx
  _QWORD *v45; // r8
  unsigned __int64 v46; // rax
  _QWORD *v47; // rcx
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> array; // [rsp+30h] [rbp-38h] BYREF
  hkResult result; // [rsp+70h] [rbp+8h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v4 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v4 < Value[3] )
  {
    *v4 = "TtEndOfStepCbs";
    v5 = __rdtsc();
    v6 = v4 + 2;
    *((_DWORD *)v6 - 2) = v5;
    Value[1] = v6;
  }
  stripArray_hkpEndOfStepCallbackUtil::NewCollision_(
    (hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *)&this->m_newCollisions,
    (hkArray<hkpEndOfStepCallbackUtil::NewCollision,hkContainerHeapAllocator> *)&this->m_collisions);
  stripArray_hkpEndOfStepCallbackUtil::Collision_(
    (hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *)&this->m_newCollisions,
    (hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *)&this->hkpWorldPostSimulationListener);
  if ( *((_BYTE *)&this->m_referenceCount + 2) )
  {
    m_size = this->m_collisions.m_size;
    if ( m_size > 1 )
      hkAlgorithm::quickSortRecursive<hkpEndOfStepCallbackUtil::NewCollision,hkAlgorithm::less<hkpEndOfStepCallbackUtil::NewCollision>>(
        (hkpEndOfStepCallbackUtil::NewCollision *)this->m_collisions.m_data,
        0,
        m_size - 1,
        0);
    mergeArrays(
      (hkArray<hkpEndOfStepCallbackUtil::NewCollision,hkContainerHeapAllocator> *)&this->m_collisions,
      (hkArray<hkpEndOfStepCallbackUtil::Collision,hkContainerHeapAllocator> *)&this->hkpWorldPostSimulationListener);
  }
  else
  {
    v8 = this->m_collisions.m_size;
    m_sequenceNumber = this->m_sequenceNumber;
    v10 = m_sequenceNumber + v8;
    v11 = *(_DWORD *)&this->m_deterministicOrder.m_bool & 0x3FFFFFFF;
    if ( v11 < (int)m_sequenceNumber + v8 )
    {
      v12 = 2 * v11;
      if ( v10 < v12 )
        v10 = v12;
      hkArrayUtil::_reserve(
        &result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&this->hkpWorldPostSimulationListener::vfptr,
        v10,
        24);
    }
    vfptr = this->hkpWorldPostSimulationListener::vfptr;
    this->m_sequenceNumber += v8;
    v14 = 0;
    v15 = &vfptr[m_sequenceNumber];
    if ( this->m_collisions.m_size > 0 )
    {
      v16 = 0i64;
      do
      {
        m_data = this->m_collisions.m_data;
        ++v14;
        v16 += 32i64;
        ++v15;
        v15[-1].__vecDelDtor = *(void *(__fastcall **)(hkpWorldPostSimulationListener *, unsigned int))((char *)&m_data[-1] + v16 - 8);
        v15[-1].postSimulationCallback = *(void (__fastcall **)(hkpWorldPostSimulationListener *, hkpWorld *))((char *)&m_data[-1].m_mgr + v16);
        v15[-1].inactiveEntityMovedCallback = *(void (__fastcall **)(hkpWorldPostSimulationListener *, hkpEntity *))((char *)m_data + v16 - 16);
      }
      while ( v14 < this->m_collisions.m_size );
    }
    this->m_collisions.m_size = 0;
  }
  v18 = this->m_sequenceNumber;
  v19 = 0;
  if ( v18 > 0 )
  {
    v20 = 0i64;
    while ( 1 )
    {
      v21 = &this->hkpWorldPostSimulationListener::vfptr[v20];
      vecDelDtor = (hkpSimpleConstraintContactMgr *)v21->__vecDelDtor;
      v23 = (*(__int64 (__fastcall **)(void *(__fastcall *)(hkpWorldPostSimulationListener *, unsigned int)))(*(_QWORD *)v21->__vecDelDtor + 128i64))(v21->__vecDelDtor);
      inactiveEntityMovedCallback = (int)v21->inactiveEntityMovedCallback;
      v25 = (hkpConstraintInstance *)v23;
      if ( inactiveEntityMovedCallback )
      {
        if ( inactiveEntityMovedCallback != 1 )
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
      if ( *(_WORD *)(v26 + 664) )
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
          if ( (*((_BYTE *)hkpConstraintInstance::getSimulationIsland(v25) + 50) & 0xC) != 0 )
            hkpEndOfStepCallbackUtil::fireContactPointEventsForCollision(
              vecDelDtor,
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
          v31 = this->m_sequenceNumber;
          array.m_data = 0i64;
          array.m_size = 0;
          v32 = v31;
          array.m_capacityAndFlags = 0x80000000;
          if ( (_DWORD)v31 )
          {
            result.m_enum = 24 * v31;
            v33 = (hkRelocationInfo::Import *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                &hkContainerHeapAllocator::s_alloc,
                                                &result);
            v32 = result.m_enum / 24;
          }
          else
          {
            v33 = 0i64;
          }
          m_capacityAndFlags = 0x80000000;
          array.m_data = v33;
          if ( v32 )
            m_capacityAndFlags = v32;
          array.m_size = v31;
          v35 = 0;
          array.m_capacityAndFlags = m_capacityAndFlags;
          v36 = v31;
          if ( (int)v31 > 0 )
          {
            v37 = 0i64;
            v38 = 0i64;
            do
            {
              v39 = &this->hkpWorldPostSimulationListener::vfptr[v38];
              if ( v39->postSimulationCallback )
              {
                ++v35;
                v37 += 24i64;
                *(_QWORD *)((char *)&v33[-1] + v37 - 8) = v39->__vecDelDtor;
                *(_QWORD *)((char *)&v33[-1].m_fromOffset + v37) = v39->postSimulationCallback;
                *(_QWORD *)((char *)v33 + v37 - 8) = v39->inactiveEntityMovedCallback;
                v33 = array.m_data;
              }
              ++v38;
              --v36;
            }
            while ( v36 );
            m_capacityAndFlags = array.m_capacityAndFlags;
          }
          v40 = m_capacityAndFlags & 0x3FFFFFFF;
          if ( v40 < v35 )
          {
            v41 = 2 * v40;
            v42 = v35;
            if ( v35 < v41 )
              v42 = v41;
            hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array.m_data, v42, 24);
          }
          array.m_size = v35;
          hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
            (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->hkpWorldPostSimulationListener,
            &array);
          array.m_size = 0;
          if ( array.m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              array.m_data,
              24 * (array.m_capacityAndFlags & 0x3FFFFFFF));
        }
        break;
      }
    }
  }
  *(_DWORD *)&this->m_memSizeAndFlags = 0;
  v43 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v44 = (_QWORD *)v43[1];
  v45 = v43;
  if ( (unsigned __int64)v44 < v43[3] )
  {
    *v44 = "Et";
    v46 = __rdtsc();
    v47 = v44 + 2;
    *((_DWORD *)v47 - 2) = v46;
    v45[1] = v47;
  }
}

// File Line: 249
// RVA: 0xD8ADD0
void __fastcall hkpEndOfStepCallbackUtil::fireContactPointEventsForCollision(
        hkpSimpleConstraintContactMgr *mgr,
        hkpContactListener *listener,
        hkpCollisionEvent::CallbackSource source)
{
  __int64 v5; // rax
  hkpSimpleContactConstraintAtom *m_atom; // r9
  __int64 m_contactPointPropertiesStriding; // r15
  int m_numContactPoints; // r13d
  __int64 v9; // rsi
  __int64 v10; // rbx
  bool v11; // bp
  int v12; // r13d
  int i; // edi
  hkpContactListenerVtbl *vfptr; // rax
  hkpCollisionEvent::CallbackSource v15; // [rsp+20h] [rbp-A8h] BYREF
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
  __int64 v31; // [rsp+E8h] [rbp+20h]

  v29 = *(_QWORD *)(((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *))mgr->vfptr[8].__vecDelDtor)(mgr) + 40);
  v5 = ((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *))mgr->vfptr[8].__vecDelDtor)(mgr);
  m_atom = mgr->m_contactConstraintData.m_atom;
  m_contactPointPropertiesStriding = (unsigned __int8)m_atom->m_contactPointPropertiesStriding;
  m_numContactPoints = m_atom->m_numContactPoints;
  v31 = *(_QWORD *)(v5 + 48);
  v9 = (__int64)&m_atom[1];
  v10 = (__int64)&m_atom[1] + 32 * m_atom->m_numReservedContactPoints;
  v11 = (*(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(hkpSimpleConstraintContactMgr *))mgr->vfptr[8].__vecDelDtor)(mgr)
                              + 96)
                  + 34i64) & 8) != 0;
  v12 = m_numContactPoints - 1;
  for ( i = v12; i >= 0; --i )
  {
    if ( (*(_BYTE *)(v10 + 19) & 1) != 0 || v11 )
    {
      v15 = source;
      v25 = 0i64;
      v16 = v29;
      v24 = i == 0;
      v17 = v31;
      v18 = mgr;
      v23 = i == v12;
      v19 = 3;
      v26 = v10 + 32;
      vfptr = listener->vfptr;
      v20 = v9;
      v21 = v10;
      v22 = v11;
      v27 = 0i64;
      v28 = 0i64;
      vfptr->contactPointCallback(listener, (hkpContactPointEvent *)&v15);
    }
    v9 += 32i64;
    v10 += m_contactPointPropertiesStriding;
  }
}

