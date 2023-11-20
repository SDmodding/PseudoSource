// File Line: 23
// RVA: 0x131BFF0
void __fastcall hkpTypedBroadPhaseDispatcher::hkpTypedBroadPhaseDispatcher(hkpTypedBroadPhaseDispatcher *this)
{
  hkpNullBroadPhaseListener *v1; // rdx
  signed __int64 v2; // r9
  hkpBroadPhaseListener **v3; // rax
  hkpBroadPhaseListener *v4; // r8
  hkpBroadPhaseListener *v5; // r8
  hkpBroadPhaseListener *v6; // r8
  hkpBroadPhaseListener *v7; // r8
  hkpBroadPhaseListener *v8; // r8
  hkpBroadPhaseListener *v9; // r8
  hkpBroadPhaseListener *v10; // r8
  hkpBroadPhaseListener *v11; // r8

  v1 = &this->m_nullBroadPhaseListener;
  v2 = 8i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkpNullBroadPhaseListener::`vftable{for `hkReferencedObject};
  *(_DWORD *)&v1->m_memSizeAndFlags = 0x1FFFF;
  v1->vfptr = (hkpBroadPhaseListenerVtbl *)&hkpNullBroadPhaseListener::`vftable{for `hkpBroadPhaseListener};
  v3 = &this->m_broadPhaseListeners[0][2];
  do
  {
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v4 = 0i64;
    else
      v4 = (hkpBroadPhaseListener *)&this->m_nullBroadPhaseListener.vfptr;
    *(v3 - 2) = v4;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v5 = 0i64;
    else
      v5 = (hkpBroadPhaseListener *)&this->m_nullBroadPhaseListener.vfptr;
    *(v3 - 1) = v5;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v6 = 0i64;
    else
      v6 = (hkpBroadPhaseListener *)&this->m_nullBroadPhaseListener.vfptr;
    *v3 = v6;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v7 = 0i64;
    else
      v7 = (hkpBroadPhaseListener *)&this->m_nullBroadPhaseListener.vfptr;
    v3[1] = v7;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v8 = 0i64;
    else
      v8 = (hkpBroadPhaseListener *)&this->m_nullBroadPhaseListener.vfptr;
    v3[2] = v8;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v9 = 0i64;
    else
      v9 = (hkpBroadPhaseListener *)&this->m_nullBroadPhaseListener.vfptr;
    v3[3] = v9;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v10 = 0i64;
    else
      v10 = (hkpBroadPhaseListener *)&this->m_nullBroadPhaseListener.vfptr;
    v3[4] = v10;
    if ( this == (hkpTypedBroadPhaseDispatcher *)-512i64 )
      v11 = 0i64;
    else
      v11 = (hkpBroadPhaseListener *)&this->m_nullBroadPhaseListener.vfptr;
    v3[5] = v11;
    v3 += 8;
    --v2;
  }
  while ( v2 );
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
void __fastcall hkpTypedBroadPhaseDispatcher::addPairs(hkpTypedBroadPhaseDispatcher *this, hkpTypedBroadPhaseHandlePair *newPairs, int numNewPairs, hkpCollidableCollidableFilter *filter)
{
  hkpCollidableCollidableFilter *v4; // rsi
  hkpTypedBroadPhaseHandlePair *v5; // rbx
  int v6; // edi
  hkpTypedBroadPhaseDispatcher *i; // r14
  hkpBroadPhaseListener *v8; // rcx
  char v9; // [rsp+40h] [rbp+18h]

  v4 = filter;
  v5 = newPairs;
  v6 = numNewPairs - 1;
  for ( i = this; v6 >= 0; --v6 )
  {
    if ( *(_BYTE *)v4->vfptr->isCollisionEnabled(
                     v4,
                     (hkBool *)&v9,
                     (hkpCollidable *)((char *)v5->m_a + SBYTE1(v5->m_a[1].m_id)),
                     (hkpCollidable *)((char *)v5->m_b + SBYTE1(v5->m_b[1].m_id))) )
    {
      v8 = i->m_broadPhaseListeners[0][SLOBYTE(v5->m_b[1].m_id) + 8i64 * SLOBYTE(v5->m_a[1].m_id)];
      v8->vfptr->addCollisionPair(v8, v5);
    }
    ++v5;
  }
}

// File Line: 57
// RVA: 0x131C600
void __fastcall hkpTypedBroadPhaseDispatcher::removePairs(hkpTypedBroadPhaseDispatcher *this, hkpTypedBroadPhaseHandlePair *deletedPairs, int numDeletedPairs)
{
  hkpTypedBroadPhaseHandlePair *v3; // rbx
  hkpTypedBroadPhaseDispatcher *v4; // rsi
  int i; // edi
  hkpBroadPhaseListener *v6; // rcx

  v3 = deletedPairs;
  v4 = this;
  for ( i = numDeletedPairs - 1; i >= 0; --i )
  {
    v6 = v4->m_broadPhaseListeners[0][SLOBYTE(v3->m_b[1].m_id) + 8i64 * SLOBYTE(v3->m_a[1].m_id)];
    v6->vfptr->removeCollisionPair(v6, v3);
    ++v3;
  }
}

// File Line: 84
// RVA: 0x131C660
unsigned __int64 __fastcall keyFromPair(hkpBroadPhaseHandlePair *pair)
{
  return __PAIR__(pair->m_b->m_id, pair->m_a->m_id);
}

// File Line: 98
// RVA: 0x131C110
void __fastcall hkpTypedBroadPhaseDispatcher::removeDuplicates(hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *newPairs, hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *delPairs)
{
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v2; // r15
  int v3; // ecx
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v4; // r13
  int v5; // er8
  signed int v6; // eax
  int v7; // esi
  int v8; // er10
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
  signed __int64 v23; // rcx
  int v24; // ebx
  __int64 v25; // rdx
  __int64 v26; // rax
  int v27; // eax
  int v28; // eax
  int v29; // er9
  unsigned int v30; // eax
  int v31; // er14
  int v32; // ebx
  void *v33; // rdx
  unsigned int v34; // ecx
  int v35; // edi
  __int64 v36; // rsi
  hkpBroadPhaseHandle *v37; // rcx
  hkpBroadPhaseHandle *v38; // rdx
  unsigned __int64 v39; // rbx
  int v40; // eax
  int v41; // er12
  int v42; // esi
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *v43; // rax
  __int64 v44; // r13
  __int64 v45; // rdi
  hkpBroadPhaseHandlePair *v46; // rax
  hkpBroadPhaseHandle *v47; // rcx
  hkpBroadPhaseHandle *v48; // rdx
  Dummy *v49; // rax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v50; // r8
  unsigned __int64 v51; // rbx
  hkpBroadPhaseHandlePair *v52; // rdx
  hkpBroadPhaseHandlePair *v53; // rcx
  int v54; // eax
  int v55; // eax
  int v56; // er9
  int v57; // edx
  __int64 v58; // r9
  __int64 v59; // rcx
  hkpBroadPhaseHandlePair *v60; // r8
  int v61; // eax
  int v62; // eax
  int v63; // er9
  void *v64; // [rsp+30h] [rbp-28h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v65; // [rsp+38h] [rbp-20h]
  __int64 v66; // [rsp+A0h] [rbp+48h]
  hkArray<hkpBroadPhaseHandlePair,hkContainerHeapAllocator> *result; // [rsp+A8h] [rbp+50h]
  __int64 v68; // [rsp+B0h] [rbp+58h]
  unsigned __int64 key; // [rsp+B8h] [rbp+60h]

  result = delPairs;
  v2 = newPairs;
  v3 = delPairs->m_size;
  v4 = delPairs;
  v5 = v2->m_size;
  v6 = v3;
  if ( v5 < v3 )
    v6 = v2->m_size;
  if ( v6 >= 32 )
  {
    v30 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::getSizeInBytesFor(v5);
    v31 = 0;
    v32 = v30;
    if ( v30 )
    {
      LODWORD(v66) = v30;
      v33 = hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
              (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
              (int *)&v66);
      v30 = v66;
    }
    else
    {
      v33 = 0i64;
    }
    v34 = 2147483648;
    if ( v30 )
      v34 = v30;
    v64 = v33;
    LODWORD(v68) = v34;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>(
      &v65,
      v33,
      v32);
    v35 = 0;
    if ( v2->m_size > 0 )
    {
      v36 = 0i64;
      do
      {
        v37 = v2->m_data[v36].m_a;
        v38 = v2->m_data[v36].m_b;
        if ( v37 > v38 )
        {
          v37 = v2->m_data[v36].m_b;
          v38 = v2->m_data[v36].m_a;
        }
        LODWORD(key) = (hkpBroadPhaseHandle)v37->m_id;
        HIDWORD(key) = (hkpBroadPhaseHandle)v38->m_id;
        v39 = key;
        v40 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                  &v65,
                                  key);
        if ( v40 > v65.m_hashMod )
        {
          hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
            &v65,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v39,
            (v35 << 8) | 1i64);
        }
        else
        {
          ++v65.m_elem[v40].val;
          v2->m_data[v36].m_a = 0i64;
        }
        ++v35;
        ++v36;
      }
      while ( v35 < v2->m_size );
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
        v46 = v43->m_data;
        v47 = v46[v45].m_a;
        v48 = v46[v45].m_b;
        if ( v47 > v48 )
        {
          v47 = v46[v45].m_b;
          v48 = v46[v45].m_a;
        }
        LODWORD(key) = (hkpBroadPhaseHandle)v47->m_id;
        HIDWORD(key) = (hkpBroadPhaseHandle)v48->m_id;
        v49 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(&v65, key);
        if ( (signed int)v49 > v65.m_hashMod )
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
          v50 = &v65.m_elem[(signed int)v49];
          v51 = v50->val;
          if ( (signed int)(unsigned __int8)v51 <= 1 )
          {
            hkMultiMap<unsigned __int64,unsigned __int64,hkMultiMapOperations<unsigned __int64>,hkContainerHeapAllocator>::remove(
              &v65,
              v49);
            v2->m_data[(unsigned int)v51 >> 8].m_a = 0i64;
          }
          else
          {
            v50->val = v51 - 1;
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
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v4,
        v56,
        16);
    }
    v57 = 0;
    v4->m_size = v41;
    if ( v2->m_size > 0 )
    {
      v58 = 0i64;
      v59 = 0i64;
      do
      {
        v60 = v2->m_data;
        if ( v2->m_data[v59].m_a )
        {
          ++v31;
          ++v58;
          v60[v58 - 1].m_a = v60[v59].m_a;
          *((_QWORD *)&v60[v58] - 1) = v60[v59].m_b;
        }
        ++v57;
        ++v59;
      }
      while ( v57 < v2->m_size );
    }
    v61 = v2->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v61 < v31 )
    {
      v62 = 2 * v61;
      v63 = v31;
      if ( v31 < v62 )
        v63 = v62;
      hkArrayUtil::_reserve(
        (hkResult *)&result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v2,
        v63,
        16);
    }
    v2->m_size = v31;
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v65,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v65);
    if ( (signed int)v68 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v64,
        v68 & 0x3FFFFFFF);
  }
  else
  {
    v7 = 0;
    v8 = 0;
    LODWORD(result) = 0;
    v9 = 0i64;
    v10 = 0i64;
    v66 = 0i64;
    if ( v3 > 0 )
    {
      v11 = 0i64;
      v68 = 0i64;
      v12 = 0i64;
      do
      {
        v13 = v2->m_size;
        v14 = 0;
        v15 = 0i64;
        if ( v13 > 0 )
        {
          v16 = v4->m_data;
          v17 = v2->m_data;
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
          v8 = (signed int)result;
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
          v21 = v2->m_data;
          v22 = v13 - 1;
          v2->m_size = v22;
          v23 = (signed __int64)&v21[v15];
          v24 = 16 * (v22 - v14);
          if ( v24 > 0 )
          {
            v25 = ((unsigned int)(v24 - 1) >> 3) + 1;
            do
            {
              v26 = *(_QWORD *)(v23 + 16);
              v23 += 8i64;
              *(_QWORD *)(v23 - 8) = v26;
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
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v4,
        v29,
        16);
    }
    v4->m_size = v7;
  }
}

