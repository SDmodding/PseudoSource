// File Line: 31
// RVA: 0xBA5F10
hkResult *__fastcall hkaiFaceEdges::setGeometry(hkaiFaceEdges *this, hkResult *result, hkaiEdgeGeometry *geom)
{
  __int64 m_size; // rbp
  int v5; // eax
  int v8; // eax
  int v9; // r9d
  __int64 v10; // r13
  int v11; // r12d
  __int64 v12; // r9
  int v13; // eax
  int v14; // eax
  hkaiEdgeGeometry::Edge *const **m_data; // rax
  int v16; // r8d
  hkaiEdgeGeometry::Edge *v17; // rcx
  EdgeFacePair *v18; // rdx
  int v19; // eax
  hkaiEdgeGeometry::Edge *v20; // r8
  unsigned int m_face; // eax
  __int64 v22; // r8
  hkaiEdgeGeometry::Edge *v23; // rcx
  int v24; // eax
  int v25; // eax
  int v26; // r9d
  hkaiEdgeGeometry::Edge **v27; // rax
  unsigned int v28; // edx
  __int64 v29; // r8
  hkaiEdgeGeometry::Edge **v30; // r9
  EdgeFacePair *array; // [rsp+30h] [rbp-38h] BYREF
  int v33; // [rsp+38h] [rbp-30h]
  int v34; // [rsp+3Ch] [rbp-2Ch]
  hkResult resulta; // [rsp+70h] [rbp+8h] BYREF

  m_size = geom->m_edges.m_size;
  v5 = this->m_faceEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < (int)m_size )
  {
    v8 = 2 * v5;
    v9 = geom->m_edges.m_size;
    if ( (int)m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, this, v9, 8);
  }
  this->m_faceEdges.m_size = m_size;
  v10 = geom->m_faces.m_size;
  v11 = v10 + 1;
  v12 = 2i64;
  if ( (int)v10 + 1 > 2 )
    v12 = (unsigned int)v11;
  v13 = this->m_faceStartEdges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 < (int)v12 )
  {
    v14 = 2 * v13;
    if ( (int)v12 < v14 )
      LODWORD(v12) = v14;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_faceStartEdges, v12, 8);
  }
  if ( (this->m_faceEdges.m_capacityAndFlags & 0x3FFFFFFF) != 0 && !this->m_faceEdges.m_data
    || (this->m_faceStartEdges.m_capacityAndFlags & 0x3FFFFFFF) != 0 && !this->m_faceStartEdges.m_data )
  {
    result->m_enum = HK_FAILURE;
    return result;
  }
  if ( !(_DWORD)m_size )
  {
    m_data = this->m_faceStartEdges.m_data;
    this->m_faceStartEdges.m_size = 2;
    *m_data = 0i64;
    *((_QWORD *)this->m_faceStartEdges.m_data + 1) = 0i64;
LABEL_45:
    result->m_enum = HK_SUCCESS;
    return result;
  }
  array = 0i64;
  v33 = 0;
  v34 = 0x80000000;
  if ( (int)m_size <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
    goto LABEL_23;
  }
  hkArrayUtil::_reserve(&resulta, &hkContainerTempAllocator::s_alloc, &array, m_size, 16);
  if ( resulta.m_enum == HK_SUCCESS )
  {
LABEL_23:
    v17 = geom->m_edges.m_data;
    v18 = array;
    v19 = m_size;
    v20 = &v17[geom->m_edges.m_size];
    v33 = m_size;
    if ( v17 != v20 )
    {
      do
      {
        v18->m_edge = v17;
        m_face = v17->m_face;
        ++v17;
        v18->m_face = m_face;
        ++v18;
      }
      while ( v17 != v20 );
      v19 = v33;
    }
    if ( v19 > 1 )
      hkAlgorithm::quickSortRecursive<EdgeFacePair,hkAlgorithm::less<EdgeFacePair>>(array, 0, v19 - 1, 0);
    v22 = 0i64;
    if ( (int)m_size > 0 )
    {
      v12 = 0i64;
      do
      {
        ++v22;
        v23 = *(hkaiEdgeGeometry::Edge **)((char *)&array->m_edge + v12);
        v12 += 16i64;
        this->m_faceEdges.m_data[v22 - 1] = v23;
      }
      while ( v22 < m_size );
    }
    v33 = 0;
    if ( v34 >= 0 )
      ((void (__fastcall *)(hkContainerTempAllocator::Allocator *, EdgeFacePair *, _QWORD, __int64))hkContainerTempAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerTempAllocator::s_alloc,
        array,
        (unsigned int)(16 * v34),
        v12);
    v24 = this->m_faceStartEdges.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v24 < v11 )
    {
      v25 = 2 * v24;
      v26 = v10 + 1;
      if ( v11 < v25 )
        v26 = v25;
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_faceStartEdges, v26, 8);
    }
    this->m_faceStartEdges.m_size = v11;
    v27 = this->m_faceEdges.m_data;
    v28 = 0;
    v29 = 0i64;
    v30 = &this->m_faceEdges.m_data[this->m_faceEdges.m_size];
    if ( (int)v10 > 0 )
    {
      do
      {
        for ( ; (*v27)->m_face > v28; this->m_faceStartEdges.m_data[v29 - 1] = v27 )
        {
          ++v28;
          ++v29;
        }
        for ( this->m_faceStartEdges.m_data[v29] = v27; v27 < v30; ++v27 )
        {
          if ( (*v27)->m_face != v28 )
            break;
        }
        ++v29;
        ++v28;
      }
      while ( v29 < v10 );
    }
    this->m_faceStartEdges.m_data[v10] = v27;
    goto LABEL_45;
  }
  v16 = v34;
  result->m_enum = HK_FAILURE;
  v33 = 0;
  if ( v16 >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 16 * v16);
  return result;
}

// File Line: 175
// RVA: 0xBA6220
hkaiEdgeGeometry::Edge *__fastcall hkaiFaceEdges::findEdgeWithStartVertex(hkaiFaceEdges *this, int face, int a)
{
  hkaiEdgeGeometry::Edge *const **m_data; // rcx
  hkaiEdgeGeometry::Edge *const *v4; // rax
  hkaiEdgeGeometry::Edge *const *v5; // rdx

  m_data = this->m_faceStartEdges.m_data;
  v4 = m_data[face];
  v5 = m_data[face + 1];
  if ( v4 == v5 )
    return 0i64;
  while ( **(_DWORD **)v4 != a )
  {
    if ( ++v4 == v5 )
      return 0i64;
  }
  return *v4;
}

// File Line: 192
// RVA: 0xBA6260
hkaiEdgeGeometry::Edge *__fastcall hkaiFaceEdges::findEdgeWithEndVertex(hkaiFaceEdges *this, int face, int b)
{
  hkaiEdgeGeometry::Edge *const **m_data; // rcx
  hkaiEdgeGeometry::Edge *const *v4; // rax
  hkaiEdgeGeometry::Edge *const *v5; // rdx

  m_data = this->m_faceStartEdges.m_data;
  v4 = m_data[face];
  v5 = m_data[face + 1];
  if ( v4 == v5 )
    return 0i64;
  while ( (*v4)->m_b != b )
  {
    if ( ++v4 == v5 )
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

