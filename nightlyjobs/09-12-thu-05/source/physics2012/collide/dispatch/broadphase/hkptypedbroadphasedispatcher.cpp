// File Line: 23
// RVA: 0x131BFF0
void __fastcall hkpTypedBroadPhaseDispatcher::hkpTypedBroadPhaseDispatcher(hkpTypedBroadPhaseDispatcher *this)
{
  __int64 v1; // r9
  hkpBroadPhaseListener **v2; // rax
  hkpBroadPhaseListener *v3; // r8
  hkpBroadPhaseListener *v4; // r8
  hkpBroadPhaseListener *v5; // r8
  hkpBroadPhaseListener *v6; // r8
  hkpBroadPhaseListener *v7; // r8
  hkpBroadPhaseListener *v8; // r8
  hkpBroadPhaseListener *v9; // r8
  hkpBroadPhaseListener *v10; // r8

  v1 = 8i64;
  this->m_nullBroadPhaseListener.vfptr = (hkBaseObjectVtbl *)&hkpNullBroadPhaseListener::`vftable{for `hkReferencedObject};
  *(_DWORD *)&this->m_nullBroadPhaseListener.m_memSizeAndFlags = 0x1FFFF;
  this->m_nullBroadPhaseListener.vfptr = (hkpBroadPhaseListenerVtbl *)&hkpNullBroadPhaseListener::`vftable{for `hkpBroadPhaseListener};
  v2 = &this->m_broadPhaseListeners[0][2];
  do
  {
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v3 = 0i64;
    else
      v3 = &this->m_nullBroadPhaseListener.hkpBroadPhaseListener;
    *(v2 - 2) = v3;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v4 = 0i64;
    else
      v4 = &this->m_nullBroadPhaseListener.hkpBroadPhaseListener;
    *(v2 - 1) = v4;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v5 = 0i64;
    else
      v5 = &this->m_nullBroadPhaseListener.hkpBroadPhaseListener;
    *v2 = v5;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v6 = 0i64;
    else
      v6 = &this->m_nullBroadPhaseListener.hkpBroadPhaseListener;
    v2[1] = v6;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v7 = 0i64;
    else
      v7 = &this->m_nullBroadPhaseListener.hkpBroadPhaseListener;
    v2[2] = v7;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v8 = 0i64;
    else
      v8 = &this->m_nullBroadPhaseListener.hkpBroadPhaseListener;
    v2[3] = v8;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v9 = 0i64;
    else
      v9 = &this->m_nullBroadPhaseListener.hkpBroadPhaseListener;
    v2[4] = v9;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v10 = 0i64;
    else
      v10 = &this->m_nullBroadPhaseListener.hkpBroadPhaseListener;
    v2[5] = v10;
    v2 += 8;
    --v1;
  }
  while ( v1 );
}

// File Line: 34
// RVA: 0x131C0E0
void __fastcall hkpTypedBroadPhaseDispatcher::~hkpTypedBroadPhaseDispatcher(hkpTypedBroadPhaseDispatcher *this)
{
  this->m_nullBroadPhaseListener.vfptr = (hkpBroadPhaseListenerVtbl *)&hkpBroadPhaseListener::`vftable;
  this->m_nullBroadPhaseListener.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 38
// RVA: 0x131C560
void __fastcall hkpTypedBroadPhaseDispatcher::addPairs(
        hkpTypedBroadPhaseDispatcher *this,
        hkpTypedBroadPhaseHandlePair *newPairs,
        int numNewPairs,
        hkpCollidableCollidableFilter *filter)
{
  int i; // edi
  hkpBroadPhaseListener *v8; // rcx
  char v9; // [rsp+40h] [rbp+18h] BYREF

  for ( i = numNewPairs - 1; i >= 0; --i )
  {
    if ( filter->vfptr->isCollisionEnabled(
           filter,
           &v9,
           (char *)newPairs->m_a + SBYTE1(newPairs->m_a[1].m_id),
           (char *)newPairs->m_b + SBYTE1(newPairs->m_b[1].m_id))->m_bool )
    {
      v8 = this->m_broadPhaseListeners[SLOBYTE(newPairs->m_a[1].m_id)][SLOBYTE(newPairs->m_b[1].m_id)];
      v8->vfptr->addCollisionPair(v8, newPairs);
    }
    ++newPairs;
  }
}

// File Line: 57
// RVA: 0x131C600
void __fastcall hkpTypedBroadPhaseDispatcher::removePairs(
        hkpTypedBroadPhaseDispatcher *this,
        hkpTypedBroadPhaseHandlePair *deletedPairs,
        int numDeletedPairs)
{
  int i; // edi
  hkpBroadPhaseListener *v6; // rcx

  for ( i = numDeletedPairs - 1; i >= 0; --i )
  {
    v6 = this->m_broadPhaseListeners[SLOBYTE(deletedPairs->m_a[1].m_id)][SLOBYTE(deletedPairs->m_b[1].m_id)];
    v6->vfptr->removeCollisionPair(v6, deletedPairs++);
  }
}

// File Line: 84
// RVA: 0x131C660
unsigned __int64 __fastcall keyFromPair(hkpBroadPhaseHandlePair *pair)
{
  return __PAIR64__(pair->m_b->m_id, pair->m_a->m_id);
}

// File Line: 98
// RVA: 0x131C110
void __fastcall hkpTypedBroadPhaseDispatcher::removeDuplicates(
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs,
        hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *delPairs)
{
  int m_size; // ecx
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v4; // r13
  int v5; // r8d
  int v6; // eax
  int v7; // esi
  int v8; // r10d
  __int64 v9; // r12
  __int64 v10; // r8
  __int64 v11; // r11
  __int64 v12; // rdi
  int v13; // ebx
  int v14; // edx
  __int64 v15; // r9
  hkpBroadPhaseHandlePair *v16; // r10
  hkpBroadPhaseHandlePair *v17; // rcx
  hkpBroadPhaseHandle *v18; // r11
  hkpBroadPhaseHandlePair *v19; // rcx
  hkpBroadPhaseHandle **v20; // rdx
  hkpBroadPhaseHandlePair *v21; // rcx
  int v22; // ebx
  hkpBroadPhaseHandlePair *v23; // rcx
  int v24; // ebx
  __int64 v25; // rdx
  hkpBroadPhaseHandle *v26; // rax
  int v27; // eax
  int v28; // eax
  int v29; // r9d
  unsigned int SizeInBytesFor; // eax
  int v31; // r14d
  int v32; // ebx
  void *v33; // rdx
  unsigned int v34; // ecx
  int v35; // edi
  __int64 v36; // rsi
  hkpBroadPhaseHandle *m_a; // rcx
  hkpBroadPhaseHandle *m_b; // rdx
  unsigned __int64 v39; // rbx
  int v40; // eax
  int v41; // r12d
  int v42; // esi
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v43; // rax
  __int64 v44; // r13
  __int64 v45; // rdi
  hkpBroadPhaseHandlePair *m_data; // rax
  hkpBroadPhaseHandle *v47; // rcx
  hkpBroadPhaseHandle *v48; // rdx
  Dummy *v49; // rax
  __int64 v50; // r8
  __int64 v51; // rbx
  hkpBroadPhaseHandlePair *v52; // rdx
  hkpBroadPhaseHandlePair *v53; // rcx
  int v54; // eax
  int v55; // eax
  int v56; // r9d
  int v57; // edx
  __int64 v58; // r9
  __int64 v59; // rcx
  hkpBroadPhaseHandlePair *v60; // r8
  int v61; // eax
  int v62; // eax
  int v63; // r9d
  void *v64; // [rsp+30h] [rbp-28h]
  AMD_HD3D v65; // [rsp+38h] [rbp-20h] BYREF
  __int64 v66; // [rsp+A0h] [rbp+48h] BYREF
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *result; // [rsp+A8h] [rbp+50h] BYREF
  __int64 v68; // [rsp+B0h] [rbp+58h]
  unsigned __int64 key; // [rsp+B8h] [rbp+60h]

  result = delPairs;
  m_size = delPairs->m_size;
  v4 = delPairs;
  v5 = newPairs->m_size;
  v6 = m_size;
  if ( v5 < m_size )
    v6 = newPairs->m_size;
  if ( v6 >= 32 )
  {
    SizeInBytesFor = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(v5);
    v31 = 0;
    v32 = SizeInBytesFor;
    if ( SizeInBytesFor )
    {
      LODWORD(v66) = SizeInBytesFor;
      v33 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &v66);
      SizeInBytesFor = v66;
    }
    else
    {
      v33 = 0i64;
    }
    v34 = 0x80000000;
    if ( SizeInBytesFor )
      v34 = SizeInBytesFor;
    v64 = v33;
    LODWORD(v68) = v34;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v65,
      v33,
      v32);
    v35 = 0;
    if ( newPairs->m_size > 0 )
    {
      v36 = 0i64;
      do
      {
        m_a = newPairs->m_data[v36].m_a;
        m_b = newPairs->m_data[v36].m_b;
        if ( m_a > m_b )
        {
          m_a = newPairs->m_data[v36].m_b;
          m_b = newPairs->m_data[v36].m_a;
        }
        LODWORD(key) = (hkpBroadPhaseHandle)m_a->m_id;
        HIDWORD(key) = (hkpBroadPhaseHandle)m_b->m_id;
        v39 = key;
        v40 = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v65,
                              key);
        if ( v40 > (int)v65.mHeight )
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v65,
            &hkContainerHeapAllocator::s_alloc,
            v39,
            (v35 << 8) | 1i64);
        }
        else
        {
          ++*(_QWORD *)(*(_QWORD *)&v65.mEnableStereo + 16i64 * v40 + 8);
          newPairs->m_data[v36].m_a = 0i64;
        }
        ++v35;
        ++v36;
      }
      while ( v35 < newPairs->m_size );
    }
    v41 = 0;
    v42 = 0;
    if ( v4->m_size > 0 )
    {
      v43 = result;
      v44 = 0i64;
      v45 = 0i64;
      do
      {
        m_data = v43->m_data;
        v47 = m_data[v45].m_a;
        v48 = m_data[v45].m_b;
        if ( v47 > v48 )
        {
          v47 = m_data[v45].m_b;
          v48 = m_data[v45].m_a;
        }
        LODWORD(key) = (hkpBroadPhaseHandle)v47->m_id;
        HIDWORD(key) = (hkpBroadPhaseHandle)v48->m_id;
        v49 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v65,
                key);
        if ( (int)v49 > (int)v65.mHeight )
        {
          ++v41;
          v52 = &result->m_data[v44];
          v53 = &result->m_data[v45];
          ++v44;
          v52->m_a = v53->m_a;
          v52->m_b = v53->m_b;
        }
        else
        {
          v50 = *(_QWORD *)&v65.mEnableStereo + 16i64 * (int)v49;
          v51 = *(_QWORD *)(v50 + 8);
          if ( (unsigned __int8)v51 <= 1u )
          {
            hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v65,
              (__int64)v49);
            newPairs->m_data[(unsigned int)v51 >> 8].m_a = 0i64;
          }
          else
          {
            *(_QWORD *)(v50 + 8) = v51 - 1;
          }
        }
        v43 = result;
        ++v42;
        ++v45;
      }
      while ( v42 < result->m_size );
      v4 = result;
    }
    v54 = v4->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v54 < v41 )
    {
      v55 = 2 * v54;
      v56 = v41;
      if ( v41 < v55 )
        v56 = v55;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&v4->m_data,
        v56,
        16);
    }
    v57 = 0;
    v4->m_size = v41;
    if ( newPairs->m_size > 0 )
    {
      v58 = 0i64;
      v59 = 0i64;
      do
      {
        v60 = newPairs->m_data;
        if ( newPairs->m_data[v59].m_a )
        {
          ++v31;
          v60[v58++].m_a = v60[v59].m_a;
          v60[v58 - 1].m_b = v60[v59].m_b;
        }
        ++v57;
        ++v59;
      }
      while ( v57 < newPairs->m_size );
    }
    v61 = newPairs->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v61 < v31 )
    {
      v62 = 2 * v61;
      v63 = v31;
      if ( v31 < v62 )
        v63 = v62;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&newPairs->m_data,
        v63,
        16);
    }
    newPairs->m_size = v31;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v65,
      &hkContainerHeapAllocator::s_alloc);
    _(&v65);
    if ( (int)v68 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v64, v68 & 0x3FFFFFFF);
  }
  else
  {
    v7 = 0;
    v8 = 0;
    LODWORD(result) = 0;
    v9 = 0i64;
    v10 = 0i64;
    v66 = 0i64;
    if ( m_size > 0 )
    {
      v11 = 0i64;
      v68 = 0i64;
      v12 = 0i64;
      do
      {
        v13 = newPairs->m_size;
        v14 = 0;
        v15 = 0i64;
        if ( v13 > 0 )
        {
          v16 = v4->m_data;
          v17 = newPairs->m_data;
          v18 = v4->m_data[v12].m_a;
          do
          {
            if ( v17->m_a == v18 && v17->m_b == v16[v12].m_b )
              break;
            if ( v17->m_b == v18 && v17->m_a == v16[v12].m_b )
              break;
            ++v14;
            ++v15;
            ++v17;
          }
          while ( v14 < v13 );
          v10 = v66;
          v8 = (int)result;
          v11 = v68;
        }
        if ( v14 == v13 )
        {
          if ( v10 != v9 )
          {
            v19 = &v4->m_data[v12];
            v20 = (hkpBroadPhaseHandle **)((char *)&v4->m_data->m_a + v11);
            *v20 = v19->m_a;
            v20[1] = v19->m_b;
          }
          ++v10;
          ++v7;
          v11 += 16i64;
          v68 = v11;
          v66 = v10;
        }
        else
        {
          v21 = newPairs->m_data;
          v22 = v13 - 1;
          newPairs->m_size = v22;
          v23 = &v21[v15];
          v24 = 16 * (v22 - v14);
          if ( v24 > 0 )
          {
            v25 = ((unsigned int)(v24 - 1) >> 3) + 1;
            do
            {
              v26 = v23[1].m_a;
              v23 = (hkpBroadPhaseHandlePair *)((char *)v23 + 8);
              v23[-1].m_b = v26;
              --v25;
            }
            while ( v25 );
          }
          v10 = v66;
        }
        ++v8;
        ++v9;
        ++v12;
        LODWORD(result) = v8;
      }
      while ( v8 < v4->m_size );
    }
    v27 = v4->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v27 < v7 )
    {
      v28 = 2 * v27;
      v29 = v7;
      if ( v7 < v28 )
        v29 = v28;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&v4->m_data,
        v29,
        16);
    }
    v4->m_size = v7;
  }
}

