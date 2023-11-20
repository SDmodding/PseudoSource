// File Line: 31
// RVA: 0xBA5F10
hkResult *__fastcall hkaiFaceEdges::setGeometry(hkaiFaceEdges *this, hkResult *result, hkaiEdgeGeometry *geom)
{
  __int64 v3; // rbp
  hkaiEdgeGeometry *v4; // r15
  int v5; // eax
  hkResult *v6; // r14
  hkaiFaceEdges *v7; // rsi
  int v8; // eax
  int v9; // er9
  __int64 v10; // r13
  int v11; // er12
  signed __int64 v12; // r9
  int v13; // eax
  int v14; // eax
  hkaiEdgeGeometry::Edge *const **v15; // rax
  int v16; // er9
  int v17; // er8
  hkaiEdgeGeometry::Edge *v18; // rcx
  EdgeFacePair *v19; // rdx
  signed int v20; // eax
  signed __int64 v21; // r8
  unsigned int v22; // eax
  __int64 v23; // r8
  hkaiEdgeGeometry::Edge *v24; // rcx
  int v25; // eax
  int v26; // eax
  int v27; // er9
  hkaiEdgeGeometry::Edge **v28; // rax
  unsigned int v29; // edx
  __int64 v30; // r8
  unsigned __int64 v31; // r9
  EdgeFacePair *array; // [rsp+30h] [rbp-38h]
  int v34; // [rsp+38h] [rbp-30h]
  int v35; // [rsp+3Ch] [rbp-2Ch]
  hkResult resulta; // [rsp+70h] [rbp+8h]

  v3 = geom->m_edges.m_size;
  v4 = geom;
  v5 = this->m_faceEdges.m_capacityAndFlags & 0x3FFFFFFF;
  v6 = result;
  v7 = this;
  if ( v5 < (signed int)v3 )
  {
    v8 = 2 * v5;
    v9 = geom->m_edges.m_size;
    if ( (signed int)v3 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, v9, 8);
  }
  v7->m_faceEdges.m_size = v3;
  v10 = v4->m_faces.m_size;
  v11 = v10 + 1;
  v12 = 2i64;
  if ( (signed int)v10 + 1 > 2 )
    v12 = (unsigned int)v11;
  v13 = v7->m_faceStartEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < (signed int)v12 )
  {
    v14 = 2 * v13;
    if ( (signed int)v12 < v14 )
      LODWORD(v12) = v14;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v7->m_faceStartEdges,
      v12,
      8);
  }
  if ( (v7->m_faceEdges.m_capacityAndFlags & 0x3FFFFFFF) > 0 && !v7->m_faceEdges.m_data
    || (v7->m_faceStartEdges.m_capacityAndFlags & 0x3FFFFFFF) > 0 && !v7->m_faceStartEdges.m_data )
  {
    v6->m_enum = 1;
    return v6;
  }
  if ( !(_DWORD)v3 )
  {
    v15 = v7->m_faceStartEdges.m_data;
    v7->m_faceStartEdges.m_size = 2;
    *v15 = 0i64;
    *((_QWORD *)v7->m_faceStartEdges.m_data + 1) = 0i64;
LABEL_47:
    v6->m_enum = 0;
    return v6;
  }
  array = 0i64;
  v34 = 0;
  v35 = 2147483648;
  if ( (signed int)v3 <= 0 )
  {
    resulta.m_enum = 0;
LABEL_25:
    v18 = v4->m_edges.m_data;
    v19 = array;
    v20 = v3;
    v21 = (signed __int64)&v18[v4->m_edges.m_size];
    v34 = v3;
    if ( v18 != (hkaiEdgeGeometry::Edge *)v21 )
    {
      do
      {
        v19->m_edge = v18;
        v22 = v18->m_face;
        ++v18;
        v19->m_face = v22;
        ++v19;
      }
      while ( v18 != (hkaiEdgeGeometry::Edge *)v21 );
      v20 = v34;
    }
    if ( v20 > 1 )
      hkAlgorithm::quickSortRecursive<EdgeFacePair,hkAlgorithm::less<EdgeFacePair>>(array, 0, v20 - 1, 0);
    v23 = 0i64;
    if ( (signed int)v3 > 0 )
    {
      v12 = 0i64;
      do
      {
        ++v23;
        v24 = *(hkaiEdgeGeometry::Edge **)((char *)&array->m_edge + v12);
        v12 += 16i64;
        v7->m_faceEdges.m_data[v23 - 1] = v24;
      }
      while ( v23 < v3 );
    }
    v34 = 0;
    if ( v35 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, EdgeFacePair *, _QWORD, signed __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        array,
        (unsigned int)(16 * v35),
        v12);
    v25 = v7->m_faceStartEdges.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v25 < v11 )
    {
      v26 = 2 * v25;
      v27 = v10 + 1;
      if ( v11 < v26 )
        v27 = v26;
      hkArrayUtil::_reserve(
        &resulta,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v7->m_faceStartEdges,
        v27,
        8);
    }
    v7->m_faceStartEdges.m_size = v11;
    v28 = v7->m_faceEdges.m_data;
    v29 = 0;
    v30 = 0i64;
    v31 = (unsigned __int64)&v7->m_faceEdges.m_data[v7->m_faceEdges.m_size];
    if ( (signed int)v10 > 0 )
    {
      do
      {
        for ( ; (*v28)->m_face > v29; v7->m_faceStartEdges.m_data[v30 - 1] = v28 )
        {
          ++v29;
          ++v30;
        }
        for ( v7->m_faceStartEdges.m_data[v30] = v28; (unsigned __int64)v28 < v31; ++v28 )
        {
          if ( (*v28)->m_face != v29 )
            break;
        }
        ++v30;
        ++v29;
      }
      while ( v30 < v10 );
    }
    v7->m_faceStartEdges.m_data[v10] = v28;
    goto LABEL_47;
  }
  v16 = v3;
  if ( (signed int)v3 < 0 )
    v16 = 0;
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v16, 16);
  if ( resulta.m_enum == HK_SUCCESS )
    goto LABEL_25;
  v17 = v35;
  v6->m_enum = 1;
  v34 = 0;
  if ( v17 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      array,
      16 * v17);
  return v6;
}

// File Line: 175
// RVA: 0xBA6220
hkaiEdgeGeometry::Edge *__fastcall hkaiFaceEdges::findEdgeWithStartVertex(hkaiFaceEdges *this, int face, int a)
{
  hkaiEdgeGeometry::Edge *const **v3; // rcx
  hkaiEdgeGeometry::Edge *const *v4; // rax
  hkaiEdgeGeometry::Edge *const *v5; // rdx

  v3 = this->m_faceStartEdges.m_data;
  v4 = v3[face];
  v5 = v3[face + 1];
  if ( v4 == v5 )
    return 0i64;
  while ( **(_DWORD **)v4 != a )
  {
    ++v4;
    if ( v4 == v5 )
      return 0i64;
  }
  return *v4;
}

// File Line: 192
// RVA: 0xBA6260
hkaiEdgeGeometry::Edge *__fastcall hkaiFaceEdges::findEdgeWithEndVertex(hkaiFaceEdges *this, int face, int b)
{
  hkaiEdgeGeometry::Edge *const **v3; // rcx
  hkaiEdgeGeometry::Edge *const *v4; // rax
  hkaiEdgeGeometry::Edge *const *v5; // rdx

  v3 = this->m_faceStartEdges.m_data;
  v4 = v3[face];
  v5 = v3[face + 1];
  if ( v4 == v5 )
    return 0i64;
  while ( (*v4)->m_b != b )
  {
    ++v4;
    if ( v4 == v5 )
      return 0i64;
  }
  return *v4;
}

// File Line: 209
// RVA: 0xBA62A0
void __fastcall hkaiFaceEdges::clear(hkaiFaceEdges *this)
{
  this->m_faceEdges.m_size = 0;
  this->m_faceStartEdges.m_size = 0;
}

