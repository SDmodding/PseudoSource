// File Line: 18
// RVA: 0xBA4980
void __fastcall createVertexMap(
        hkArray<hkVector4f,hkContainerHeapAllocator> *vertices,
        hkFindUniquePositionsUtil *uniquePosUtil,
        hkArray<int,hkContainerHeapAllocator> *vertexMap)
{
  __int64 m_size; // rbx
  int v5; // eax
  int v8; // eax
  int v9; // r9d
  int v10; // esi
  __int64 v11; // rbp
  __int64 v12; // rdi
  int *v13; // rbx
  int v14; // eax
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  m_size = vertices->m_size;
  v5 = vertexMap->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v5 < (int)m_size )
  {
    v8 = 2 * v5;
    v9 = vertices->m_size;
    if ( (int)m_size < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, vertexMap, v9, 4);
  }
  v10 = 0;
  vertexMap->m_size = m_size;
  v11 = m_size;
  v12 = 0i64;
  if ( (int)m_size > 0 )
  {
    do
    {
      v13 = &vertexMap->m_data[v12];
      v14 = hkFindUniquePositionsUtil::addPosition(uniquePosUtil, &vertices->m_data[v10]);
      ++v12;
      ++v10;
      *v13 = v14;
    }
    while ( v12 < v11 );
  }
}

// File Line: 30
// RVA: 0xBA4530
void __fastcall hkaiSelfIntersectBooleanFilter2::hkaiSelfIntersectBooleanFilter2(hkaiSelfIntersectBooleanFilter2 *this)
{
  this->vfptr = (hkaiBooleanFilterVtbl *)&hkaiSelfIntersectBooleanFilter2::`vftable;
  this->m_vertexMapA.m_capacityAndFlags = 0x80000000;
  this->m_vertexMapA.m_data = 0i64;
  this->m_vertexMapA.m_size = 0;
  this->m_vertexMapB.m_data = 0i64;
  this->m_vertexMapB.m_size = 0;
  this->m_vertexMapB.m_capacityAndFlags = 0x80000000;
  this->m_face1Results.m_data = 0i64;
  this->m_face1Results.m_size = 0;
  this->m_face1Results.m_capacityAndFlags = 0x80000000;
  hkaiSelfIntersectBooleanFilter2::reset(this);
}

// File Line: 36
// RVA: 0xBA4590
hkResult *__fastcall hkaiSelfIntersectBooleanFilter2::setEdgeGeoms(
        hkaiSelfIntersectBooleanFilter2 *this,
        hkResult *result,
        hkaiEdgeGeometry *geomA,
        hkaiEdgeGeometry *geomB)
{
  int m_size; // edi
  int v5; // r13d
  hkResult *v8; // r14
  int SizeInBytesFor; // eax
  int v10; // r8d
  int v11; // ebx
  void *v12; // rdx
  int v13; // eax
  int v14; // eax
  __int64 v15; // rdi
  int v16; // eax
  int v17; // eax
  hkResultEnum m_enum; // eax
  __int64 v19; // rbx
  int v20; // eax
  int v21; // eax
  int v22; // r9d
  int v23; // esi
  __int64 v24; // r13
  __int64 v25; // r14
  int *v26; // rbx
  int v27; // eax
  __int64 v28; // rbx
  int v29; // eax
  int v30; // eax
  int v31; // r9d
  __int64 v32; // r12
  int v33; // esi
  __int64 v34; // rdi
  __int64 v35; // r14
  int *v36; // rbx
  int v37; // eax
  hkResult v39; // [rsp+30h] [rbp-39h] BYREF
  hkResult v40; // [rsp+34h] [rbp-35h] BYREF
  int numPoints; // [rsp+38h] [rbp-31h] BYREF
  void *array; // [rsp+40h] [rbp-29h] BYREF
  int v43; // [rsp+48h] [rbp-21h]
  int v44; // [rsp+4Ch] [rbp-1Dh]
  hkFindUniquePositionsUtil v45; // [rsp+50h] [rbp-19h] BYREF
  hkResult resulta; // [rsp+D0h] [rbp+67h] BYREF
  hkResult *v47; // [rsp+D8h] [rbp+6Fh]
  hkaiEdgeGeometry *v48; // [rsp+E0h] [rbp+77h] BYREF
  hkaiEdgeGeometry *v49; // [rsp+E8h] [rbp+7Fh]

  v49 = geomB;
  v48 = geomA;
  v47 = result;
  this->m_geomA = geomA;
  this->m_geomB = geomB;
  m_size = geomA->m_vertices.m_size;
  v5 = geomB->m_vertices.m_size;
  v8 = result;
  numPoints = m_size + v5;
  SizeInBytesFor = hkFindUniquePositionsUtil::getSizeInBytesFor(m_size + v5);
  v10 = 0x80000000;
  v11 = SizeInBytesFor;
  v44 = 0x80000000;
  v12 = 0i64;
  array = 0i64;
  v43 = 0;
  if ( SizeInBytesFor <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
    goto LABEL_5;
  }
  hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, SizeInBytesFor, 1);
  v10 = v44;
  v12 = array;
  if ( resulta.m_enum == HK_SUCCESS )
LABEL_5:
    v43 = v11;
  v13 = this->m_vertexMapA.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v13 >= m_size )
  {
    v15 = 0i64;
    v40.m_enum = HK_SUCCESS;
  }
  else
  {
    v14 = 2 * v13;
    if ( m_size < v14 )
      m_size = v14;
    hkArrayUtil::_reserve(&v40, &hkContainerHeapAllocator::s_alloc, &this->m_vertexMapA, m_size, 4);
    v10 = v44;
    v12 = array;
    v15 = 0i64;
  }
  v16 = this->m_vertexMapB.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v16 >= v5 )
  {
    m_enum = HK_SUCCESS;
    v39.m_enum = HK_SUCCESS;
  }
  else
  {
    v17 = 2 * v16;
    if ( v5 < v17 )
      v5 = v17;
    hkArrayUtil::_reserve(&v39, &hkContainerHeapAllocator::s_alloc, &this->m_vertexMapB, v5, 4);
    v10 = v44;
    v12 = array;
    m_enum = v39.m_enum;
  }
  if ( resulta.m_enum || v40.m_enum || m_enum )
  {
    v8->m_enum = HK_FAILURE;
    v43 = 0;
    if ( v10 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v12, v10 & 0x3FFFFFFF);
  }
  else
  {
    v45.m_positions.m_data = 0i64;
    v45.m_positions.m_size = 0;
    v45.m_positions.m_capacityAndFlags = 0x80000000;
    v45.m_hashMap.m_map.m_elem = 0i64;
    v45.m_hashMap.m_map.m_numElems = 0;
    v45.m_hashMap.m_map.m_hashMod = -1;
    v45.m_entries.m_data = 0i64;
    v45.m_entries.m_size = 0;
    v45.m_entries.m_capacityAndFlags = 0x80000000;
    hkFindUniquePositionsUtil::setBuffer(&v45, v12, numPoints);
    v19 = geomA->m_vertices.m_size;
    v20 = this->m_vertexMapA.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v20 < (int)v19 )
    {
      v21 = 2 * v20;
      v22 = geomA->m_vertices.m_size;
      if ( (int)v19 < v21 )
        v22 = v21;
      hkArrayUtil::_reserve((hkResult *)&numPoints, &hkContainerHeapAllocator::s_alloc, &this->m_vertexMapA, v22, 4);
    }
    this->m_vertexMapA.m_size = v19;
    v23 = 0;
    v24 = v19;
    if ( (int)v19 > 0 )
    {
      v25 = (__int64)v48;
      do
      {
        v26 = &this->m_vertexMapA.m_data[v15];
        v27 = hkFindUniquePositionsUtil::addPosition(&v45, (hkVector4f *)(*(_QWORD *)(v25 + 48) + 16i64 * v23));
        ++v15;
        ++v23;
        *v26 = v27;
      }
      while ( v15 < v24 );
      v8 = v47;
    }
    v28 = v49->m_vertices.m_size;
    v29 = this->m_vertexMapB.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v29 < (int)v28 )
    {
      v30 = 2 * v29;
      v31 = v49->m_vertices.m_size;
      if ( (int)v28 < v30 )
        v31 = v30;
      hkArrayUtil::_reserve((hkResult *)&v48, &hkContainerHeapAllocator::s_alloc, &this->m_vertexMapB, v31, 4);
    }
    this->m_vertexMapB.m_size = v28;
    v32 = v28;
    v33 = 0;
    v34 = 0i64;
    if ( (int)v28 > 0 )
    {
      v35 = (__int64)v49;
      do
      {
        v36 = &this->m_vertexMapB.m_data[v34];
        v37 = hkFindUniquePositionsUtil::addPosition(&v45, (hkVector4f *)(*(_QWORD *)(v35 + 48) + 16i64 * v33));
        ++v34;
        ++v33;
        *v36 = v37;
      }
      while ( v34 < v32 );
      v8 = v47;
    }
    hkFindUniquePositionsUtil::~hkFindUniquePositionsUtil(&v45);
    v43 = 0;
    if ( v44 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, v44 & 0x3FFFFFFF);
    v8->m_enum = HK_SUCCESS;
  }
  return v8;
}

// File Line: 102
// RVA: 0xBA48B0
char __fastcall hkaiSelfIntersectBooleanFilter2::_canFacesIntersectImpl(
        hkaiSelfIntersectBooleanFilter2 *this,
        int faceA,
        int faceB)
{
  __int64 v3; // r9
  hkaiEdgeGeometry::Edge *const **m_data; // rdx
  int **v5; // rdi
  int **v6; // r15
  hkaiEdgeGeometry::Edge *const **v7; // rdx
  hkaiEdgeGeometry::Edge *const *v8; // rbp
  int **v9; // rbx
  int *v10; // rsi
  int v11; // r10d
  int v12; // r9d
  hkaiEdgeGeometry::Edge *const *v13; // rax
  int *v14; // r11
  int v15; // r8d
  int v16; // edx

  v3 = faceA;
  m_data = this->m_faceEdgesA->m_faceStartEdges.m_data;
  v5 = (int **)m_data[v3];
  v6 = (int **)m_data[v3 + 1];
  v7 = this->m_faceEdgesB->m_faceStartEdges.m_data;
  v8 = v7[faceB];
  v9 = (int **)v7[faceB + 1];
  if ( v5 == v6 )
    return 1;
  v10 = this->m_vertexMapA.m_data;
  while ( 1 )
  {
    v11 = v10[**v5];
    v12 = v10[(*v5)[1]];
    v13 = v8;
    if ( v8 != (hkaiEdgeGeometry::Edge *const *)v9 )
      break;
LABEL_10:
    if ( ++v5 == v6 )
      return 1;
  }
  v14 = this->m_vertexMapB.m_data;
  while ( 1 )
  {
    v15 = v14[**(int **)v13];
    v16 = v14[(*v13)->m_b];
    if ( v11 == v16 && v12 == v15 )
      return 0;
    if ( v11 == v15 && v12 == v16 )
      return 0;
    if ( ++v13 == (hkaiEdgeGeometry::Edge *const *)v9 )
      goto LABEL_10;
  }
}

// File Line: 144
// RVA: 0xBA4420
bool __fastcall hkaiSelfIntersectBooleanFilter2::canFacesIntersect(
        hkaiSelfIntersectBooleanFilter2 *this,
        int faceA,
        int faceB)
{
  if ( faceA == 1 )
    return this->m_face1Results.m_data[faceB];
  else
    return hkaiSelfIntersectBooleanFilter2::_canFacesIntersectImpl(this, faceA, faceB);
}

// File Line: 178
// RVA: 0xBA4440
hkResult *__fastcall hkaiSelfIntersectBooleanFilter2::setFaceEdges(
        hkaiSelfIntersectBooleanFilter2 *this,
        hkResult *result,
        hkaiFaceEdges *faceEdgesA,
        hkaiFaceEdges *faceEdgesB)
{
  hkaiEdgeGeometry *m_geomB; // rax
  __int64 m_size; // rbp
  int v7; // eax
  int v9; // eax
  int v10; // r9d
  int v12; // edi
  __int64 i; // rbx
  hkResult resulta; // [rsp+50h] [rbp+8h] BYREF

  m_geomB = this->m_geomB;
  this->m_faceEdgesA = faceEdgesA;
  this->m_faceEdgesB = faceEdgesB;
  m_size = m_geomB->m_faces.m_size;
  v7 = this->m_face1Results.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v7 >= (int)m_size )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    v9 = 2 * v7;
    v10 = m_size;
    if ( (int)m_size < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &this->m_face1Results, v10, 1);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      return result;
    }
  }
  this->m_face1Results.m_size = m_size;
  v12 = 1;
  *this->m_face1Results.m_data = 0;
  for ( i = 1i64; i < m_size; ++v12 )
    this->m_face1Results.m_data[i++] = hkaiSelfIntersectBooleanFilter2::_canFacesIntersectImpl(this, 1, v12);
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 195
// RVA: 0xBA4880
void __fastcall hkaiSelfIntersectBooleanFilter2::reset(hkaiSelfIntersectBooleanFilter2 *this)
{
  this->m_geomA = 0i64;
  this->m_geomB = 0i64;
  this->m_faceEdgesA = 0i64;
  this->m_faceEdgesB = 0i64;
  this->m_vertexMapA.m_size = 0;
  this->m_vertexMapB.m_size = 0;
  this->m_face1Results.m_size = 0;
}

