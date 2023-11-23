// File Line: 23
// RVA: 0xB9AEB0
void __fastcall hkaiCarverTree::hkaiCarverTree(hkaiCarverTree *this)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiCarverTree::`vftable;
  this->m_carverTree.m_pntr = 0i64;
  this->m_painterTree.m_pntr = 0i64;
  this->m_carvers = 0i64;
  this->m_painters = 0i64;
}

// File Line: 29
// RVA: 0xB9AEE0
void __fastcall hkaiCarverTree::~hkaiCarverTree(hkaiCarverTree *this)
{
  hkcdDynamicAabbTree *m_pntr; // rcx
  hkcdDynamicAabbTree *v3; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkaiCarverTree::`vftable;
  m_pntr = this->m_painterTree.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_painterTree.m_pntr = 0i64;
  v3 = this->m_carverTree.m_pntr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  this->m_carverTree.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 57
// RVA: 0xB9BC20
_BOOL8 __fastcall PointQuery::processLeaf(PointQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  hkaiVolume *m_pntr; // rcx
  int *v5; // rdx
  BOOL v6; // ebx
  int *v8; // [rsp+20h] [rbp-28h] BYREF
  int v9; // [rsp+28h] [rbp-20h]
  int v10; // [rsp+2Ch] [rbp-1Ch]
  int v11[6]; // [rsp+30h] [rbp-18h] BYREF

  m_pntr = this->m_carvers->m_data[leafKey].m_pntr;
  v8 = v11;
  v10 = -2147483647;
  v11[2] = 1;
  v9 = 1;
  v11[0] = 0;
  ((void (__fastcall *)(hkaiVolume *, hkVector4f *, __int64, int **))m_pntr->vfptr[2].__vecDelDtor)(
    m_pntr,
    &this->m_point,
    1i64,
    &v8);
  v5 = v8;
  if ( (*(_BYTE *)v8 & 1) != 0 )
    this->m_containsPoint = 1;
  v9 = 0;
  v6 = !this->m_containsPoint;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v5, 4 * v10);
  return v6;
}

// File Line: 102
// RVA: 0xB9BCD0
_BOOL8 __fastcall TriangleQuery::processLeaf(TriangleQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  hkVector4f *p_m_c; // r9
  hkaiVolume *m_pntr; // rcx

  p_m_c = &this->m_c;
  m_pntr = this->m_carvers->m_data[leafKey].m_pntr;
  if ( ((unsigned int (__fastcall *)(hkaiVolume *, hkVector4f *, hkVector4f *, hkVector4f *))m_pntr->vfptr[3].__vecDelDtor)(
         m_pntr,
         &this->m_a,
         &this->m_b,
         p_m_c) )
  {
    this->m_containsTriangle = 1;
  }
  return !this->m_containsTriangle;
}

// File Line: 142
// RVA: 0xB9BA80
_BOOL8 __fastcall AabbQuery::processLeaf(AabbQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  hkaiVolume *m_pntr; // rcx

  m_pntr = this->m_carvers->m_data[leafKey].m_pntr;
  if ( ((unsigned int (__fastcall *)(hkaiVolume *, hkAabb *))m_pntr->vfptr[3].__first_virtual_table_function__)(
         m_pntr,
         &this->m_aabb) )
  {
    this->m_containsAABB = 1;
  }
  return !this->m_containsAABB;
}

// File Line: 203
// RVA: 0xB9BAC0
__int64 __fastcall PainterQuery::processLeaf(PainterQuery *this, int leafKey, hkAabb *leafAabb)
{
  unsigned int v3; // edi
  hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *m_painters; // rax
  signed int m_highestIndex; // ebp
  hkaiMaterialPainter *m_pntr; // r14
  int v8; // r9d
  int v9; // eax
  int v10; // eax
  int *v12; // [rsp+30h] [rbp-38h] BYREF
  int v13; // [rsp+38h] [rbp-30h]
  int v14; // [rsp+3Ch] [rbp-2Ch]
  int v15[4]; // [rsp+40h] [rbp-28h] BYREF
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  v3 = 1;
  v12 = v15;
  m_painters = this->m_painters;
  v14 = -2147483647;
  v15[2] = 1;
  v13 = 1;
  v15[0] = 0;
  m_highestIndex = leafKey;
  m_pntr = m_painters->m_data[leafKey].m_pntr;
  ((void (__fastcall *)(hkaiVolume *, hkVector4f *, __int64, int **))m_pntr->m_volume.m_pntr->vfptr[2].__vecDelDtor)(
    m_pntr->m_volume.m_pntr,
    &this->m_point,
    1i64,
    &v12);
  if ( (*(_BYTE *)v12 & 1) != 0 )
  {
    v8 = this->m_overlappingPainters.m_size + 1;
    v9 = this->m_overlappingPainters.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 >= v8 )
    {
      result.m_enum = HK_SUCCESS;
    }
    else
    {
      v10 = 2 * v9;
      if ( v8 < v10 )
        v8 = v10;
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &this->m_overlappingPainters, v8, 8);
      if ( result.m_enum )
      {
        this->m_resultOut->m_enum = HK_FAILURE;
        v3 = 0;
        goto LABEL_13;
      }
    }
    if ( this->m_overlappingPainters.m_size == (this->m_overlappingPainters.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, &this->m_overlappingPainters, 8);
    this->m_overlappingPainters.m_data[this->m_overlappingPainters.m_size++] = m_pntr;
    if ( this->m_highestIndex > m_highestIndex )
      m_highestIndex = this->m_highestIndex;
    this->m_highestIndex = m_highestIndex;
  }
LABEL_13:
  v13 = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v12, 4 * v14);
  return v3;
}

// File Line: 249
// RVA: 0xB9B9E0
__int64 __fastcall AabbCollector::processLeaf(AabbCollector *this, int leafKey, hkAabb *leafAabb)
{
  hkArray<int,hkContainerHeapAllocator> *m_hits; // r8
  unsigned int v4; // edi
  int v7; // r9d
  int v8; // eax
  int v9; // eax
  hkArray<int,hkContainerHeapAllocator> *v10; // r8
  hkResult result; // [rsp+40h] [rbp+8h] BYREF

  m_hits = this->m_hits;
  v4 = 0;
  v7 = m_hits->m_size + 1;
  v8 = m_hits->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 >= v7 )
  {
    result.m_enum = HK_SUCCESS;
LABEL_7:
    v10 = this->m_hits;
    v10->m_data[v10->m_size++] = leafKey;
    goto LABEL_8;
  }
  v9 = 2 * v8;
  if ( v7 < v9 )
    v7 = v9;
  hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, m_hits, v7, 4);
  if ( result.m_enum == HK_SUCCESS )
    goto LABEL_7;
  this->m_resultOut->m_enum = HK_FAILURE;
LABEL_8:
  LOBYTE(v4) = this->m_resultOut->m_enum == HK_SUCCESS;
  return v4;
}

// File Line: 270
// RVA: 0xB9AF40
hkResult *__fastcall hkaiCarverTree::init(
        hkaiCarverTree *this,
        hkResult *result,
        hkArrayBase<hkRefPtr<hkaiVolume const > > *carvers,
        hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *painters)
{
  _QWORD **Value; // rax
  hkcdDynamicAabbTree *v9; // rax
  hkcdDynamicAabbTree *v10; // rax
  hkcdDynamicAabbTree *v11; // rbx
  hkcdDynamicAabbTree *m_pntr; // rcx
  int v13; // ebx
  __int64 v14; // rsi
  hkaiVolume *v15; // rcx
  _QWORD **v16; // rax
  hkcdDynamicAabbTree *v17; // rax
  hkcdDynamicAabbTree *v18; // rax
  hkcdDynamicAabbTree *v19; // rbx
  hkcdDynamicAabbTree *v20; // rcx
  int v21; // ebx
  __int64 v22; // rsi
  hkaiVolume *v23; // rcx
  hkAabb aabb; // [rsp+20h] [rbp-38h] BYREF
  hkResult resulta; // [rsp+60h] [rbp+8h] BYREF

  this->m_carvers = carvers;
  this->m_painters = painters;
  if ( carvers->m_size )
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
    if ( v9 )
    {
      hkcdDynamicAabbTree::hkcdDynamicAabbTree(v9);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    m_pntr = this->m_carverTree.m_pntr;
    if ( m_pntr && m_pntr != v11 )
      hkReferencedObject::removeReference(m_pntr);
    this->m_carverTree.m_pntr = v11;
    if ( !v11 )
      goto LABEL_11;
    if ( !v11->m_treePtr )
    {
      hkReferencedObject::removeReference(v11);
      this->m_carverTree.m_pntr = 0i64;
      goto LABEL_11;
    }
    hkcdDynamicAabbTree::reserveLeaves(v11, &resulta, carvers->m_size);
    if ( resulta.m_enum )
      goto LABEL_11;
    v13 = 0;
    if ( carvers->m_size > 0 )
    {
      v14 = 0i64;
      do
      {
        v15 = carvers->m_data[v14].m_pntr;
        if ( v15 )
        {
          ((void (__fastcall *)(hkaiVolume *, hkAabb *))v15->vfptr[1].__first_virtual_table_function__)(v15, &aabb);
          hkcdDynamicAabbTree::insert(this->m_carverTree.m_pntr, &aabb, v13);
        }
        ++v13;
        ++v14;
      }
      while ( v13 < carvers->m_size );
    }
  }
  if ( !painters->m_size )
  {
LABEL_34:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v16[11] + 8i64))(v16[11], 32i64);
  if ( v17 )
  {
    hkcdDynamicAabbTree::hkcdDynamicAabbTree(v17);
    v19 = v18;
  }
  else
  {
    v19 = 0i64;
  }
  v20 = this->m_painterTree.m_pntr;
  if ( v20 && v20 != v19 )
    hkReferencedObject::removeReference(v20);
  this->m_painterTree.m_pntr = v19;
  if ( v19 )
  {
    if ( !v19->m_treePtr )
    {
      hkReferencedObject::removeReference(v19);
      this->m_painterTree.m_pntr = 0i64;
      result->m_enum = HK_FAILURE;
      return result;
    }
    hkcdDynamicAabbTree::reserveLeaves(v19, &resulta, painters->m_size);
    if ( resulta.m_enum == HK_SUCCESS )
    {
      v21 = 0;
      if ( painters->m_size > 0 )
      {
        v22 = 0i64;
        do
        {
          v23 = painters->m_data[v22].m_pntr->m_volume.m_pntr;
          if ( v23 )
          {
            ((void (__fastcall *)(hkaiVolume *, hkAabb *))v23->vfptr[1].__first_virtual_table_function__)(v23, &aabb);
            hkcdDynamicAabbTree::insert(this->m_painterTree.m_pntr, &aabb, v21);
          }
          ++v21;
          ++v22;
        }
        while ( v21 < painters->m_size );
      }
      goto LABEL_34;
    }
  }
LABEL_11:
  result->m_enum = HK_FAILURE;
  return result;
}

// File Line: 347
// RVA: 0xB9B140
hkResult *__fastcall hkaiCarverTree::queryAabbCarvers(
        hkaiCarverTree *this,
        hkResult *result,
        hkAabb *aabb,
        hkArray<hkRefPtr<hkaiVolume const >,hkContainerHeapAllocator> *carverHits)
{
  __int64 v4; // rbx
  hkcdDynamicAabbTree *m_pntr; // rcx
  int v9; // r8d
  __int64 v10; // rsi
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  hkResultEnum m_enum; // eax
  __int64 v15; // r12
  hkRefPtr<hkaiVolume const > *v16; // rsi
  hkRefPtr<hkaiVolume const > *v17; // r15
  hkResult resulta; // [rsp+30h] [rbp-30h] BYREF
  int *v20; // [rsp+38h] [rbp-28h] BYREF
  int v21; // [rsp+40h] [rbp-20h]
  int v22; // [rsp+44h] [rbp-1Ch]
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+48h] [rbp-18h] BYREF
  void **v24; // [rsp+50h] [rbp-10h]
  hkResultEnum *v25; // [rsp+58h] [rbp-8h]
  hkResultEnum v26; // [rsp+90h] [rbp+30h] BYREF

  v4 = 0i64;
  m_pntr = this->m_carverTree.m_pntr;
  v26 = HK_SUCCESS;
  if ( !m_pntr )
  {
LABEL_19:
    result->m_enum = v26;
    return result;
  }
  v20 = 0i64;
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&AabbCollector::`vftable;
  v21 = 0;
  v24 = (void **)&v20;
  v22 = 0x80000000;
  v25 = &v26;
  hkcdDynamicAabbTree::queryAabb(m_pntr, aabb, &collector);
  if ( v26 == HK_SUCCESS )
  {
    v10 = v21;
    v11 = carverHits->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v11 >= v21 )
    {
      m_enum = HK_SUCCESS;
    }
    else
    {
      v12 = 2 * v11;
      v13 = v21;
      if ( v21 < v12 )
        v13 = v12;
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, carverHits, v13, 8);
      m_enum = resulta.m_enum;
    }
    v26 = m_enum;
    if ( m_enum == HK_SUCCESS )
    {
      v15 = v10;
      if ( (int)v10 > 0 )
      {
        do
        {
          v16 = &this->m_carvers->m_data[v20[v4]];
          v17 = &carverHits->m_data[carverHits->m_size];
          if ( v17 )
          {
            if ( v16->m_pntr )
              hkReferencedObject::addReference(v16->m_pntr);
            v17->m_pntr = v16->m_pntr;
          }
          ++carverHits->m_size;
          ++v4;
        }
        while ( v4 < v15 );
      }
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
      v21 = 0;
      if ( v22 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v20, 4 * v22);
      goto LABEL_19;
    }
  }
  v9 = v22;
  result->m_enum = HK_FAILURE;
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
  v21 = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v20, 4 * v9);
  return result;
}

// File Line: 370
// RVA: 0xB9B300
hkResult *__fastcall hkaiCarverTree::queryAabbPainters(
        hkaiCarverTree *this,
        hkResult *result,
        hkAabb *aabb,
        hkArray<hkRefPtr<hkaiMaterialPainter const >,hkContainerHeapAllocator> *painterHits)
{
  __int64 v4; // rbx
  hkcdDynamicAabbTree *m_pntr; // rcx
  int v9; // r8d
  __int64 v10; // rsi
  int v11; // eax
  int v12; // eax
  int v13; // r9d
  hkResultEnum m_enum; // eax
  __int64 v15; // r12
  hkRefPtr<hkaiMaterialPainter const > *v16; // rsi
  hkRefPtr<hkaiMaterialPainter const > *v17; // r15
  hkResult resulta; // [rsp+30h] [rbp-30h] BYREF
  int *v20; // [rsp+38h] [rbp-28h] BYREF
  int v21; // [rsp+40h] [rbp-20h]
  int v22; // [rsp+44h] [rbp-1Ch]
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+48h] [rbp-18h] BYREF
  void **v24; // [rsp+50h] [rbp-10h]
  hkResultEnum *v25; // [rsp+58h] [rbp-8h]
  hkResultEnum v26; // [rsp+90h] [rbp+30h] BYREF

  v4 = 0i64;
  m_pntr = this->m_painterTree.m_pntr;
  v26 = HK_SUCCESS;
  if ( !m_pntr )
  {
LABEL_19:
    result->m_enum = v26;
    return result;
  }
  v20 = 0i64;
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&AabbCollector::`vftable;
  v21 = 0;
  v24 = (void **)&v20;
  v22 = 0x80000000;
  v25 = &v26;
  hkcdDynamicAabbTree::queryAabb(m_pntr, aabb, &collector);
  if ( v26 == HK_SUCCESS )
  {
    v10 = v21;
    v11 = painterHits->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v11 >= v21 )
    {
      m_enum = HK_SUCCESS;
    }
    else
    {
      v12 = 2 * v11;
      v13 = v21;
      if ( v21 < v12 )
        v13 = v12;
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, painterHits, v13, 8);
      m_enum = resulta.m_enum;
    }
    v26 = m_enum;
    if ( m_enum == HK_SUCCESS )
    {
      v15 = v10;
      if ( (int)v10 > 0 )
      {
        do
        {
          v16 = &this->m_painters->m_data[v20[v4]];
          v17 = &painterHits->m_data[painterHits->m_size];
          if ( v17 )
          {
            if ( v16->m_pntr )
              hkReferencedObject::addReference(v16->m_pntr);
            v17->m_pntr = v16->m_pntr;
          }
          ++painterHits->m_size;
          ++v4;
        }
        while ( v4 < v15 );
      }
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
      v21 = 0;
      if ( v22 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v20, 4 * v22);
      goto LABEL_19;
    }
  }
  v9 = v22;
  result->m_enum = HK_FAILURE;
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
  v21 = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v20, 4 * v9);
  return result;
}

// File Line: 393
// RVA: 0xB9B4C0
__int64 __fastcall hkaiCarverTree::carversContainTriangle(
        hkaiCarverTree *this,
        hkVector4f *A,
        hkVector4f *B,
        hkVector4f *C)
{
  hkcdDynamicAabbTree *m_pntr; // rcx
  __m128 m_quad; // xmm3
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  hkArrayBase<hkRefPtr<hkaiVolume const > > *m_carvers; // rax
  hkAabb aabb; // [rsp+20h] [rbp-88h] BYREF
  hkcdAabbTreeQueries::AabbCollector v12[4]; // [rsp+40h] [rbp-68h] BYREF
  __m128 v13; // [rsp+60h] [rbp-48h]
  __m128 v14; // [rsp+70h] [rbp-38h]
  __m128 v15; // [rsp+80h] [rbp-28h]
  unsigned __int8 v16; // [rsp+90h] [rbp-18h]

  m_pntr = this->m_carverTree.m_pntr;
  if ( !m_pntr )
    return 0i64;
  m_quad = A->m_quad;
  v7 = B->m_quad;
  v8 = C->m_quad;
  m_carvers = this->m_carvers;
  v12[1].vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)m_pntr;
  v12[0].vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&TriangleQuery::`vftable;
  v12[2].vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)m_carvers;
  v13 = m_quad;
  v14 = v7;
  v16 = 0;
  v15 = v8;
  aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(m_quad, v7), v8);
  aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(m_quad, v7), v8);
  hkcdDynamicAabbTree::queryAabb(m_pntr, &aabb, v12);
  return v16;
}

// File Line: 403
// RVA: 0xB9B560
__int64 __fastcall hkaiCarverTree::carversContainPoint(hkaiCarverTree *this, hkVector4f *p)
{
  hkcdDynamicAabbTree *m_pntr; // rcx
  __m128 m_quad; // xmm2
  hkArrayBase<hkRefPtr<hkaiVolume const > > *m_carvers; // rax
  __m128 v6; // xmm1
  hkAabb v8; // [rsp+20h] [rbp-68h] BYREF
  hkcdAabbTreeQueries::AabbCollector v9[4]; // [rsp+40h] [rbp-48h] BYREF
  __m128 v10; // [rsp+60h] [rbp-28h]
  unsigned __int8 v11; // [rsp+70h] [rbp-18h]

  m_pntr = this->m_carverTree.m_pntr;
  if ( !m_pntr )
    return 0i64;
  m_quad = p->m_quad;
  m_carvers = this->m_carvers;
  v9[1].vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)m_pntr;
  v9[2].vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)m_carvers;
  v9[0].vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&PointQuery::`vftable;
  v6 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0099999998), (__m128)LODWORD(FLOAT_0_0099999998), 0);
  v11 = 0;
  v10 = m_quad;
  v8.m_max.m_quad = _mm_add_ps(m_quad, v6);
  v8.m_min.m_quad = _mm_sub_ps(m_quad, v6);
  hkcdDynamicAabbTree::queryAabb(m_pntr, &v8, v9);
  return v11;
}

// File Line: 413
// RVA: 0xB9B5F0
__int64 __fastcall hkaiCarverTree::carversContainAABB(hkaiCarverTree *this, hkAabb *aabb)
{
  hkcdDynamicAabbTree *m_pntr; // rcx
  hkVector4f v4; // xmm0
  hkVector4f v5; // xmm1
  hkArrayBase<hkRefPtr<hkaiVolume const > > *m_carvers; // rax
  __m128 m_quad; // xmm2
  __m128 v8; // xmm1
  hkAabb v10; // [rsp+20h] [rbp-78h] BYREF
  hkcdAabbTreeQueries::AabbCollector v11[4]; // [rsp+40h] [rbp-58h] BYREF
  __m128 v12; // [rsp+60h] [rbp-38h]
  __m128 v13; // [rsp+70h] [rbp-28h]
  unsigned __int8 v14; // [rsp+80h] [rbp-18h]

  m_pntr = this->m_carverTree.m_pntr;
  if ( !m_pntr )
    return 0i64;
  v4.m_quad = (__m128)aabb->m_min;
  v5.m_quad = (__m128)aabb->m_max;
  m_carvers = this->m_carvers;
  v11[1].vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)m_pntr;
  v11[2].vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)m_carvers;
  m_quad = v5.m_quad;
  v11[0].vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&AabbQuery::`vftable;
  v13 = v5.m_quad;
  v12 = v4.m_quad;
  v14 = 0;
  v8 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0099999998), (__m128)LODWORD(FLOAT_0_0099999998), 0);
  v10.m_max.m_quad = _mm_add_ps(m_quad, v8);
  v10.m_min.m_quad = _mm_sub_ps(v4.m_quad, v8);
  hkcdDynamicAabbTree::queryAabb(m_pntr, &v10, v11);
  return v14;
}

// File Line: 423
// RVA: 0xB9B690
__int64 __fastcall hkaiCarverTree::getPaintedMaterialForPoint(
        hkaiCarverTree *this,
        hkVector4f *p,
        unsigned int originalMaterial,
        hkaiMaterialPainter::ResolveOverlapCallback *overlapCallback,
        hkResult *resultOut)
{
  hkcdDynamicAabbTree *m_pntr; // rcx
  __m128 m_quad; // xmm2
  hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *m_painters; // rax
  hkAabb v13; // [rsp+20h] [rbp-78h] BYREF
  hkcdAabbTreeQueries::AabbCollector v14; // [rsp+40h] [rbp-58h] BYREF
  __m128 v15; // [rsp+50h] [rbp-48h]
  void *v16; // [rsp+60h] [rbp-38h] BYREF
  int v17; // [rsp+68h] [rbp-30h]
  int v18; // [rsp+6Ch] [rbp-2Ch]
  hkcdDynamicAabbTree *v19; // [rsp+70h] [rbp-28h]
  hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *v20; // [rsp+78h] [rbp-20h]
  int v21; // [rsp+80h] [rbp-18h]
  hkResult *v22; // [rsp+88h] [rbp-10h]

  resultOut->m_enum = HK_SUCCESS;
  m_pntr = this->m_painterTree.m_pntr;
  if ( m_pntr )
  {
    m_quad = p->m_quad;
    m_painters = this->m_painters;
    v16 = 0i64;
    v14.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&PainterQuery::`vftable;
    v18 = 0x80000000;
    v22 = resultOut;
    v19 = m_pntr;
    v20 = m_painters;
    v17 = 0;
    v13.m_max.m_quad = _mm_add_ps(m_quad, *(__m128 *)&epsilon);
    v15 = m_quad;
    v21 = -1;
    v13.m_min.m_quad = _mm_sub_ps(m_quad, *(__m128 *)&epsilon);
    hkcdDynamicAabbTree::queryAabb(m_pntr, &v13, &v14);
    if ( v21 != -1 && v22->m_enum == HK_SUCCESS )
    {
      if ( (v17 > 1 || originalMaterial && v17 > 0) && overlapCallback )
        originalMaterial = overlapCallback->vfptr->resolveOverlappingPainters(
                             overlapCallback,
                             p,
                             originalMaterial,
                             (hkArrayBase<hkaiMaterialPainter const *> *)&v16);
      else
        originalMaterial = v20->m_data[v21].m_pntr->m_material;
    }
    v17 = 0;
    if ( v18 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, v16, 8 * v18);
  }
  return originalMaterial;
}

