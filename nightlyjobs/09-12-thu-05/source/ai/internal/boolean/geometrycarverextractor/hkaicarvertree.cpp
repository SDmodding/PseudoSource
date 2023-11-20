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
  hkaiCarverTree *v1; // rbx
  hkcdDynamicAabbTree *v2; // rcx
  hkReferencedObject *v3; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkaiCarverTree::`vftable;
  v2 = this->m_painterTree.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_painterTree.m_pntr = 0i64;
  v3 = (hkReferencedObject *)&v1->m_carverTree.m_pntr->vfptr;
  if ( v3 )
    hkReferencedObject::removeReference(v3);
  v1->m_carverTree.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 57
// RVA: 0xB9BC20
__int64 __fastcall PointQuery::processLeaf(PointQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  PointQuery *v3; // rdi
  hkaiVolume *v4; // rcx
  int *v5; // rdx
  BOOL v6; // ebx
  int *v8; // [rsp+20h] [rbp-28h]
  int v9; // [rsp+28h] [rbp-20h]
  int v10; // [rsp+2Ch] [rbp-1Ch]
  int v11; // [rsp+30h] [rbp-18h]
  int v12; // [rsp+38h] [rbp-10h]

  v3 = this;
  v4 = this->m_carvers->m_data[leafKey].m_pntr;
  v8 = &v11;
  v10 = -2147483647;
  v12 = 1;
  v9 = 1;
  v11 = 0;
  ((void (__fastcall *)(hkaiVolume *, hkVector4f *, signed __int64, int **))v4->vfptr[2].__vecDelDtor)(
    v4,
    &v3->m_point,
    1i64,
    &v8);
  v5 = v8;
  if ( *(_BYTE *)v8 & 1 )
    v3->m_containsPoint = 1;
  v9 = 0;
  v6 = v3->m_containsPoint == 0;
  if ( v10 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v5,
      4 * v10);
  return (unsigned int)v6;
}

// File Line: 102
// RVA: 0xB9BCD0
_BOOL8 __fastcall TriangleQuery::processLeaf(TriangleQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  TriangleQuery *v3; // rbx
  hkVector4f *v4; // r9
  hkaiVolume *v5; // rcx

  v3 = this;
  v4 = &this->m_c;
  v5 = this->m_carvers->m_data[leafKey].m_pntr;
  if ( ((unsigned int (__fastcall *)(hkaiVolume *, hkVector4f *, hkVector4f *, hkVector4f *))v5->vfptr[3].__vecDelDtor)(
         v5,
         &v3->m_a,
         &v3->m_b,
         v4) )
  {
    v3->m_containsTriangle = 1;
  }
  return v3->m_containsTriangle == 0;
}

// File Line: 142
// RVA: 0xB9BA80
_BOOL8 __fastcall AabbQuery::processLeaf(AabbQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  AabbQuery *v3; // rbx
  hkaiVolume *v4; // rcx

  v3 = this;
  v4 = this->m_carvers->m_data[leafKey].m_pntr;
  if ( ((unsigned int (__fastcall *)(hkaiVolume *, hkAabb *))v4->vfptr[3].__first_virtual_table_function__)(
         v4,
         &v3->m_aabb) )
  {
    v3->m_containsAABB = 1;
  }
  return v3->m_containsAABB == 0;
}

// File Line: 203
// RVA: 0xB9BAC0
__int64 __fastcall PainterQuery::processLeaf(PainterQuery *this, unsigned int leafKey, hkAabb *leafAabb)
{
  unsigned int v3; // edi
  hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *v4; // rax
  signed int v5; // ebp
  PainterQuery *v6; // rsi
  hkaiMaterialPainter *v7; // r14
  int v8; // er9
  int v9; // eax
  int v10; // eax
  int *v12; // [rsp+30h] [rbp-38h]
  int v13; // [rsp+38h] [rbp-30h]
  int v14; // [rsp+3Ch] [rbp-2Ch]
  int v15; // [rsp+40h] [rbp-28h]
  int v16; // [rsp+48h] [rbp-20h]
  hkResult result; // [rsp+78h] [rbp+10h]

  v3 = 1;
  v12 = &v15;
  v4 = this->m_painters;
  v14 = -2147483647;
  v16 = 1;
  v13 = 1;
  v15 = 0;
  v5 = leafKey;
  v6 = this;
  v7 = v4->m_data[leafKey].m_pntr;
  ((void (__fastcall *)(hkaiVolume *, hkVector4f *, signed __int64, int **))v7->m_volume.m_pntr->vfptr[2].__vecDelDtor)(
    v7->m_volume.m_pntr,
    &this->m_point,
    1i64,
    &v12);
  if ( *(_BYTE *)v12 & 1 )
  {
    v8 = v6->m_overlappingPainters.m_size + 1;
    v9 = v6->m_overlappingPainters.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 >= v8 )
    {
      result.m_enum = 0;
    }
    else
    {
      v10 = 2 * v9;
      if ( v8 < v10 )
        v8 = v10;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &v6->m_overlappingPainters,
        v8,
        8);
      if ( result.m_enum )
      {
        v6->m_resultOut->m_enum = 1;
        v3 = 0;
        goto LABEL_13;
      }
    }
    if ( v6->m_overlappingPainters.m_size == (v6->m_overlappingPainters.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        &v6->m_overlappingPainters,
        8);
    v6->m_overlappingPainters.m_data[v6->m_overlappingPainters.m_size++] = v7;
    if ( v6->m_highestIndex > v5 )
      v5 = v6->m_highestIndex;
    v6->m_highestIndex = v5;
  }
LABEL_13:
  v13 = 0;
  if ( v14 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v12,
      4 * v14);
  return v3;
}

// File Line: 249
// RVA: 0xB9B9E0
__int64 __fastcall AabbCollector::processLeaf(AabbCollector *this, unsigned int leafKey, hkAabb *leafAabb)
{
  hkArray<int,hkContainerHeapAllocator> *v3; // r8
  unsigned int v4; // edi
  unsigned int v5; // esi
  AabbCollector *v6; // rbx
  int v7; // er9
  int v8; // eax
  int v9; // eax
  hkArray<int,hkContainerHeapAllocator> *v10; // r8
  hkResult result; // [rsp+40h] [rbp+8h]

  v3 = this->m_hits;
  v4 = 0;
  v5 = leafKey;
  v6 = this;
  v7 = v3->m_size + 1;
  v8 = v3->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v8 >= v7 )
  {
    result.m_enum = 0;
LABEL_7:
    v10 = v6->m_hits;
    v10->m_data[v10->m_size++] = v5;
    goto LABEL_8;
  }
  v9 = 2 * v8;
  if ( v7 < v9 )
    v7 = v9;
  hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, v7, 4);
  if ( result.m_enum == HK_SUCCESS )
    goto LABEL_7;
  v6->m_resultOut->m_enum = 1;
LABEL_8:
  LOBYTE(v4) = v6->m_resultOut->m_enum == 0;
  return v4;
}

// File Line: 270
// RVA: 0xB9AF40
hkResult *__fastcall hkaiCarverTree::init(hkaiCarverTree *this, hkResult *result, hkArrayBase<hkRefPtr<hkaiVolume const > > *carvers, hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *painters)
{
  hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *v4; // r15
  hkArrayBase<hkRefPtr<hkaiVolume const > > *v5; // r14
  hkResult *v6; // rdi
  hkaiCarverTree *v7; // rbp
  _QWORD **v8; // rax
  hkcdDynamicAabbTree *v9; // rax
  hkcdDynamicAabbTree *v10; // rax
  hkcdDynamicAabbTree *v11; // rbx
  hkReferencedObject *v12; // rcx
  signed int v13; // ebx
  __int64 v14; // rsi
  hkaiVolume *v15; // rcx
  _QWORD **v16; // rax
  hkcdDynamicAabbTree *v17; // rax
  hkcdDynamicAabbTree *v18; // rax
  hkcdDynamicAabbTree *v19; // rbx
  hkReferencedObject *v20; // rcx
  signed int v21; // ebx
  __int64 v22; // rsi
  hkaiVolume *v23; // rcx
  hkAabb aabb; // [rsp+20h] [rbp-38h]
  hkResult resulta; // [rsp+60h] [rbp+8h]

  this->m_carvers = carvers;
  this->m_painters = painters;
  v4 = painters;
  v5 = carvers;
  v6 = result;
  v7 = this;
  if ( carvers->m_size )
  {
    v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v9 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 32i64);
    if ( v9 )
    {
      hkcdDynamicAabbTree::hkcdDynamicAabbTree(v9);
      v11 = v10;
    }
    else
    {
      v11 = 0i64;
    }
    v12 = (hkReferencedObject *)&v7->m_carverTree.m_pntr->vfptr;
    if ( v12 && v12 != (hkReferencedObject *)v11 )
      hkReferencedObject::removeReference(v12);
    v7->m_carverTree.m_pntr = v11;
    if ( !v11 )
      goto LABEL_11;
    if ( !v11->m_treePtr )
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v11->vfptr);
      v7->m_carverTree.m_pntr = 0i64;
      goto LABEL_11;
    }
    hkcdDynamicAabbTree::reserveLeaves(v11, &resulta, v5->m_size);
    if ( resulta.m_enum )
      goto LABEL_11;
    v13 = 0;
    if ( v5->m_size > 0 )
    {
      v14 = 0i64;
      do
      {
        v15 = v5->m_data[v14].m_pntr;
        if ( v15 )
        {
          ((void (__fastcall *)(hkaiVolume *, hkAabb *))v15->vfptr[1].__first_virtual_table_function__)(v15, &aabb);
          hkcdDynamicAabbTree::insert(v7->m_carverTree.m_pntr, &aabb, v13);
        }
        ++v13;
        ++v14;
      }
      while ( v13 < v5->m_size );
    }
  }
  if ( !v4->m_size )
  {
LABEL_34:
    v6->m_enum = 0;
    return v6;
  }
  v16 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v17 = (hkcdDynamicAabbTree *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v16[11] + 8i64))(v16[11], 32i64);
  if ( v17 )
  {
    hkcdDynamicAabbTree::hkcdDynamicAabbTree(v17);
    v19 = v18;
  }
  else
  {
    v19 = 0i64;
  }
  v20 = (hkReferencedObject *)&v7->m_painterTree.m_pntr->vfptr;
  if ( v20 && v20 != (hkReferencedObject *)v19 )
    hkReferencedObject::removeReference(v20);
  v7->m_painterTree.m_pntr = v19;
  if ( v19 )
  {
    if ( !v19->m_treePtr )
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&v19->vfptr);
      v7->m_painterTree.m_pntr = 0i64;
      v6->m_enum = 1;
      return v6;
    }
    hkcdDynamicAabbTree::reserveLeaves(v19, &resulta, v4->m_size);
    if ( resulta.m_enum == HK_SUCCESS )
    {
      v21 = 0;
      if ( v4->m_size > 0 )
      {
        v22 = 0i64;
        do
        {
          v23 = v4->m_data[v22].m_pntr->m_volume.m_pntr;
          if ( v23 )
          {
            ((void (__fastcall *)(hkaiVolume *, hkAabb *))v23->vfptr[1].__first_virtual_table_function__)(v23, &aabb);
            hkcdDynamicAabbTree::insert(v7->m_painterTree.m_pntr, &aabb, v21);
          }
          ++v21;
          ++v22;
        }
        while ( v21 < v4->m_size );
      }
      goto LABEL_34;
    }
  }
LABEL_11:
  v6->m_enum = 1;
  return v6;
}

// File Line: 347
// RVA: 0xB9B140
hkResult *__fastcall hkaiCarverTree::queryAabbCarvers(hkaiCarverTree *this, hkResult *result, hkAabb *aabb, hkArray<hkRefPtr<hkaiVolume const >,hkContainerHeapAllocator> *carverHits)
{
  __int64 v4; // rbx
  hkaiCarverTree *v5; // r13
  hkcdDynamicAabbTree *v6; // rcx
  hkArray<hkRefPtr<hkaiVolume const >,hkContainerHeapAllocator> *v7; // rdi
  hkResult *v8; // r14
  int v9; // er8
  __int64 v10; // rsi
  int v11; // eax
  int v12; // eax
  int v13; // er9
  hkResultEnum v14; // eax
  __int64 v15; // r12
  hkReferencedObject **v16; // rsi
  _QWORD *v17; // r15
  hkResult resulta; // [rsp+30h] [rbp-30h]
  signed int *v20; // [rsp+38h] [rbp-28h]
  int v21; // [rsp+40h] [rbp-20h]
  int v22; // [rsp+44h] [rbp-1Ch]
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+48h] [rbp-18h]
  void **v24; // [rsp+50h] [rbp-10h]
  int *v25; // [rsp+58h] [rbp-8h]
  hkResultEnum v26; // [rsp+90h] [rbp+30h]

  v4 = 0i64;
  v5 = this;
  v6 = this->m_carverTree.m_pntr;
  v7 = carverHits;
  v8 = result;
  v26 = 0;
  if ( !v6 )
  {
LABEL_19:
    v8->m_enum = v26;
    return v8;
  }
  v20 = 0i64;
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&AabbCollector::`vftable;
  v21 = 0;
  v24 = (void **)&v20;
  v22 = 2147483648;
  v25 = (int *)&v26;
  hkcdDynamicAabbTree::queryAabb(v6, aabb, &collector);
  if ( v26 == HK_SUCCESS )
  {
    v10 = v21;
    v11 = v7->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v11 >= v21 )
    {
      v14 = 0;
    }
    else
    {
      v12 = 2 * v11;
      v13 = v21;
      if ( v21 < v12 )
        v13 = v12;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v13, 8);
      v14 = resulta.m_enum;
    }
    v26 = v14;
    if ( v14 == HK_SUCCESS )
    {
      v15 = v10;
      if ( (signed int)v10 > 0 )
      {
        do
        {
          v16 = (hkReferencedObject **)&v5->m_carvers->m_data[v20[v4]];
          v17 = &v7->m_data[v7->m_size].m_pntr;
          if ( v17 )
          {
            if ( *v16 )
              hkReferencedObject::addReference(*v16);
            *v17 = *v16;
          }
          ++v7->m_size;
          ++v4;
        }
        while ( v4 < v15 );
      }
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
      v21 = 0;
      if ( v22 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v20,
          4 * v22);
      goto LABEL_19;
    }
  }
  v9 = v22;
  v8->m_enum = 1;
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
  v21 = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v20,
      4 * v9);
  return v8;
}

// File Line: 370
// RVA: 0xB9B300
hkResult *__fastcall hkaiCarverTree::queryAabbPainters(hkaiCarverTree *this, hkResult *result, hkAabb *aabb, hkArray<hkRefPtr<hkaiMaterialPainter const >,hkContainerHeapAllocator> *painterHits)
{
  __int64 v4; // rbx
  hkaiCarverTree *v5; // r13
  hkcdDynamicAabbTree *v6; // rcx
  hkArray<hkRefPtr<hkaiMaterialPainter const >,hkContainerHeapAllocator> *v7; // rdi
  hkResult *v8; // r14
  int v9; // er8
  __int64 v10; // rsi
  int v11; // eax
  int v12; // eax
  int v13; // er9
  hkResultEnum v14; // eax
  __int64 v15; // r12
  hkReferencedObject **v16; // rsi
  _QWORD *v17; // r15
  hkResult resulta; // [rsp+30h] [rbp-30h]
  signed int *v20; // [rsp+38h] [rbp-28h]
  int v21; // [rsp+40h] [rbp-20h]
  int v22; // [rsp+44h] [rbp-1Ch]
  hkcdAabbTreeQueries::AabbCollector collector; // [rsp+48h] [rbp-18h]
  void **v24; // [rsp+50h] [rbp-10h]
  int *v25; // [rsp+58h] [rbp-8h]
  hkResultEnum v26; // [rsp+90h] [rbp+30h]

  v4 = 0i64;
  v5 = this;
  v6 = this->m_painterTree.m_pntr;
  v7 = painterHits;
  v8 = result;
  v26 = 0;
  if ( !v6 )
  {
LABEL_19:
    v8->m_enum = v26;
    return v8;
  }
  v20 = 0i64;
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&AabbCollector::`vftable;
  v21 = 0;
  v24 = (void **)&v20;
  v22 = 2147483648;
  v25 = (int *)&v26;
  hkcdDynamicAabbTree::queryAabb(v6, aabb, &collector);
  if ( v26 == HK_SUCCESS )
  {
    v10 = v21;
    v11 = v7->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v11 >= v21 )
    {
      v14 = 0;
    }
    else
    {
      v12 = 2 * v11;
      v13 = v21;
      if ( v21 < v12 )
        v13 = v12;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v13, 8);
      v14 = resulta.m_enum;
    }
    v26 = v14;
    if ( v14 == HK_SUCCESS )
    {
      v15 = v10;
      if ( (signed int)v10 > 0 )
      {
        do
        {
          v16 = (hkReferencedObject **)&v5->m_painters->m_data[v20[v4]];
          v17 = &v7->m_data[v7->m_size].m_pntr;
          if ( v17 )
          {
            if ( *v16 )
              hkReferencedObject::addReference(*v16);
            *v17 = *v16;
          }
          ++v7->m_size;
          ++v4;
        }
        while ( v4 < v15 );
      }
      collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
      v21 = 0;
      if ( v22 >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v20,
          4 * v22);
      goto LABEL_19;
    }
  }
  v9 = v22;
  v8->m_enum = 1;
  collector.vfptr = (hkcdAabbTreeQueries::AabbCollectorVtbl *)&hkcdAabbTreeQueries::AabbCollector::`vftable;
  v21 = 0;
  if ( v9 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v20,
      4 * v9);
  return v8;
}

// File Line: 393
// RVA: 0xB9B4C0
__int64 __fastcall hkaiCarverTree::carversContainTriangle(hkaiCarverTree *this, hkVector4f *A, hkVector4f *B, hkVector4f *C)
{
  hkaiCarverTree *v4; // rax
  hkcdDynamicAabbTree *v5; // rcx
  __m128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __int64 v9; // rax
  hkAabb aabb; // [rsp+20h] [rbp-88h]
  void **v12; // [rsp+40h] [rbp-68h]
  hkcdDynamicAabbTree *v13; // [rsp+48h] [rbp-60h]
  __int64 v14; // [rsp+50h] [rbp-58h]
  __m128 v15; // [rsp+60h] [rbp-48h]
  __m128 v16; // [rsp+70h] [rbp-38h]
  __m128 v17; // [rsp+80h] [rbp-28h]
  unsigned __int8 v18; // [rsp+90h] [rbp-18h]

  v4 = this;
  v5 = this->m_carverTree.m_pntr;
  if ( !v5 )
    return 0i64;
  v6 = A->m_quad;
  v7 = B->m_quad;
  v8 = C->m_quad;
  v9 = (__int64)v4->m_carvers;
  v13 = v5;
  v12 = &TriangleQuery::`vftable;
  v14 = v9;
  v15 = v6;
  v16 = v7;
  v18 = 0;
  v17 = v8;
  aabb.m_max.m_quad = _mm_max_ps(_mm_max_ps(v6, v7), v8);
  aabb.m_min.m_quad = _mm_min_ps(_mm_min_ps(v6, v7), v8);
  hkcdDynamicAabbTree::queryAabb(v5, &aabb, (hkcdAabbTreeQueries::AabbCollector *)&v12);
  return v18;
}

// File Line: 403
// RVA: 0xB9B560
__int64 __fastcall hkaiCarverTree::carversContainPoint(hkaiCarverTree *this, hkVector4f *p)
{
  hkaiCarverTree *v2; // rax
  hkcdDynamicAabbTree *v3; // rcx
  __m128 v4; // xmm2
  __int64 v5; // rax
  __m128 v6; // xmm1
  __m128 v8; // [rsp+20h] [rbp-68h]
  __m128 v9; // [rsp+30h] [rbp-58h]
  void **v10; // [rsp+40h] [rbp-48h]
  hkcdDynamicAabbTree *v11; // [rsp+48h] [rbp-40h]
  __int64 v12; // [rsp+50h] [rbp-38h]
  __m128 v13; // [rsp+60h] [rbp-28h]
  unsigned __int8 v14; // [rsp+70h] [rbp-18h]

  v2 = this;
  v3 = this->m_carverTree.m_pntr;
  if ( !v3 )
    return 0i64;
  v4 = p->m_quad;
  v5 = (__int64)v2->m_carvers;
  v11 = v3;
  v12 = v5;
  v10 = &PointQuery::`vftable;
  v6 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0099999998), (__m128)LODWORD(FLOAT_0_0099999998), 0);
  v14 = 0;
  v13 = v4;
  v9 = _mm_add_ps(v4, v6);
  v8 = _mm_sub_ps(v4, v6);
  hkcdDynamicAabbTree::queryAabb(v3, (hkAabb *)&v8, (hkcdAabbTreeQueries::AabbCollector *)&v10);
  return v14;
}

// File Line: 413
// RVA: 0xB9B5F0
__int64 __fastcall hkaiCarverTree::carversContainAABB(hkaiCarverTree *this, hkAabb *aabb)
{
  hkaiCarverTree *v2; // rax
  hkcdDynamicAabbTree *v3; // rcx
  hkVector4f v4; // xmm0
  hkVector4f v5; // xmm1
  __int64 v6; // rax
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  __m128 v10; // [rsp+20h] [rbp-78h]
  __m128 v11; // [rsp+30h] [rbp-68h]
  void **v12; // [rsp+40h] [rbp-58h]
  hkcdDynamicAabbTree *v13; // [rsp+48h] [rbp-50h]
  __int64 v14; // [rsp+50h] [rbp-48h]
  __m128 v15; // [rsp+60h] [rbp-38h]
  __m128 v16; // [rsp+70h] [rbp-28h]
  unsigned __int8 v17; // [rsp+80h] [rbp-18h]

  v2 = this;
  v3 = this->m_carverTree.m_pntr;
  if ( !v3 )
    return 0i64;
  v4.m_quad = (__m128)aabb->m_min;
  v5.m_quad = (__m128)aabb->m_max;
  v6 = (__int64)v2->m_carvers;
  v13 = v3;
  v14 = v6;
  v7 = v5.m_quad;
  v12 = &AabbQuery::`vftable;
  v16 = v5.m_quad;
  v15 = v4.m_quad;
  v17 = 0;
  v8 = _mm_shuffle_ps((__m128)LODWORD(FLOAT_0_0099999998), (__m128)LODWORD(FLOAT_0_0099999998), 0);
  v11 = _mm_add_ps(v7, v8);
  v10 = _mm_sub_ps(v4.m_quad, v8);
  hkcdDynamicAabbTree::queryAabb(v3, (hkAabb *)&v10, (hkcdAabbTreeQueries::AabbCollector *)&v12);
  return v17;
}

// File Line: 423
// RVA: 0xB9B690
__int64 __fastcall hkaiCarverTree::getPaintedMaterialForPoint(hkaiCarverTree *this, hkVector4f *p, int originalMaterial, hkaiMaterialPainter::ResolveOverlapCallback *overlapCallback, hkResult *resultOut)
{
  unsigned int v5; // ebx
  hkaiCarverTree *v6; // rax
  hkcdDynamicAabbTree *v7; // rcx
  hkaiMaterialPainter::ResolveOverlapCallback *v8; // rdi
  hkVector4f *v9; // rsi
  __m128 v10; // xmm2
  hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *v11; // rax
  __m128 v13; // [rsp+20h] [rbp-78h]
  __m128 v14; // [rsp+30h] [rbp-68h]
  void **v15; // [rsp+40h] [rbp-58h]
  __m128 v16; // [rsp+50h] [rbp-48h]
  void *v17; // [rsp+60h] [rbp-38h]
  int v18; // [rsp+68h] [rbp-30h]
  int v19; // [rsp+6Ch] [rbp-2Ch]
  hkcdDynamicAabbTree *v20; // [rsp+70h] [rbp-28h]
  hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *v21; // [rsp+78h] [rbp-20h]
  int v22; // [rsp+80h] [rbp-18h]
  hkResult *v23; // [rsp+88h] [rbp-10h]

  v5 = originalMaterial;
  v6 = this;
  resultOut->m_enum = 0;
  v7 = this->m_painterTree.m_pntr;
  v8 = overlapCallback;
  v9 = p;
  if ( v7 )
  {
    v10 = p->m_quad;
    v11 = v6->m_painters;
    v17 = 0i64;
    v15 = &PainterQuery::`vftable;
    v19 = 2147483648;
    v23 = resultOut;
    v20 = v7;
    v21 = v11;
    v18 = 0;
    v14 = _mm_add_ps(v10, *(__m128 *)&epsilon);
    v16 = v10;
    v22 = -1;
    v13 = _mm_sub_ps(v10, *(__m128 *)&epsilon);
    hkcdDynamicAabbTree::queryAabb(v7, (hkAabb *)&v13, (hkcdAabbTreeQueries::AabbCollector *)&v15);
    if ( v22 != -1 && v23->m_enum == HK_SUCCESS )
    {
      if ( (v18 > 1 || v5 && v18 > 0) && v8 )
        v5 = v8->vfptr->resolveOverlappingPainters(v8, v9, v5, (hkArrayBase<hkaiMaterialPainter const *> *)&v17);
      else
        v5 = v21->m_data[v22].m_pntr->m_material;
    }
    v18 = 0;
    if ( v19 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v17,
        8 * v19);
  }
  return v5;
}

