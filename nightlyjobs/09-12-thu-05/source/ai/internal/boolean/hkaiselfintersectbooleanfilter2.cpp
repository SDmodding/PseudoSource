// File Line: 18
// RVA: 0xBA4980
void __fastcall createVertexMap(hkArray<hkVector4f,hkContainerHeapAllocator> *vertices, hkFindUniquePositionsUtil *uniquePosUtil, hkArray<int,hkContainerHeapAllocator> *vertexMap)
{
  __int64 v3; // rbx
  hkArray<int,hkContainerHeapAllocator> *v4; // r14
  int v5; // eax
  hkFindUniquePositionsUtil *v6; // r12
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // r15
  int v8; // eax
  int v9; // er9
  int v10; // esi
  __int64 v11; // rbp
  __int64 v12; // rdi
  int *v13; // rbx
  int v14; // eax
  hkResult result; // [rsp+60h] [rbp+8h]

  v3 = vertices->m_size;
  v4 = vertexMap;
  v5 = vertexMap->m_capacityAndFlags & 0x3FFFFFFF;
  v6 = uniquePosUtil;
  v7 = vertices;
  if ( v5 < (signed int)v3 )
  {
    v8 = 2 * v5;
    v9 = v3;
    if ( (signed int)v3 < v8 )
      v9 = v8;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, vertexMap, v9, 4);
  }
  v10 = 0;
  v4->m_size = v3;
  v11 = v3;
  v12 = 0i64;
  if ( (signed int)v3 > 0 )
  {
    do
    {
      v13 = &v4->m_data[v12];
      v14 = hkFindUniquePositionsUtil::addPosition(v6, &v7->m_data[v10]);
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
  this->m_vertexMapA.m_capacityAndFlags = 2147483648;
  this->m_vertexMapA.m_data = 0i64;
  this->m_vertexMapA.m_size = 0;
  this->m_vertexMapB.m_data = 0i64;
  this->m_vertexMapB.m_size = 0;
  this->m_vertexMapB.m_capacityAndFlags = 2147483648;
  this->m_face1Results.m_data = 0i64;
  this->m_face1Results.m_size = 0;
  this->m_face1Results.m_capacityAndFlags = 2147483648;
  hkaiSelfIntersectBooleanFilter2::reset(this);
}

// File Line: 36
// RVA: 0xBA4590
hkResult *__fastcall hkaiSelfIntersectBooleanFilter2::setEdgeGeoms(hkaiSelfIntersectBooleanFilter2 *this, hkResult *result, hkaiEdgeGeometry *geomA, hkaiEdgeGeometry *geomB)
{
  int v4; // edi
  int v5; // er13
  hkaiSelfIntersectBooleanFilter2 *v6; // r15
  hkaiEdgeGeometry *v7; // rsi
  hkResult *v8; // r14
  int v9; // eax
  signed int v10; // er8
  int v11; // ebx
  void *v12; // rdx
  int v13; // er9
  int v14; // eax
  int v15; // eax
  __int64 v16; // rdi
  int v17; // eax
  int v18; // eax
  hkResultEnum v19; // eax
  __int64 v20; // rbx
  int v21; // eax
  int v22; // eax
  int v23; // er9
  int v24; // esi
  __int64 v25; // r13
  __int64 v26; // r14
  int *v27; // rbx
  int v28; // eax
  __int64 v29; // rbx
  int v30; // eax
  int v31; // eax
  int v32; // er9
  __int64 v33; // r12
  int v34; // esi
  __int64 v35; // rdi
  __int64 v36; // r14
  int *v37; // rbx
  int v38; // eax
  hkResult v40; // [rsp+30h] [rbp-39h]
  hkResult v41; // [rsp+34h] [rbp-35h]
  int numPoints; // [rsp+38h] [rbp-31h]
  void *array; // [rsp+40h] [rbp-29h]
  int v44; // [rsp+48h] [rbp-21h]
  int v45; // [rsp+4Ch] [rbp-1Dh]
  hkFindUniquePositionsUtil v46; // [rsp+50h] [rbp-19h]
  hkResult resulta; // [rsp+D0h] [rbp+67h]
  hkResult *v48; // [rsp+D8h] [rbp+6Fh]
  hkaiEdgeGeometry *v49; // [rsp+E0h] [rbp+77h]
  hkaiEdgeGeometry *v50; // [rsp+E8h] [rbp+7Fh]

  v50 = geomB;
  v49 = geomA;
  v48 = result;
  this->m_geomA = geomA;
  this->m_geomB = geomB;
  v4 = geomA->m_vertices.m_size;
  v5 = geomB->m_vertices.m_size;
  v6 = this;
  v7 = geomA;
  v8 = result;
  numPoints = v4 + v5;
  v9 = hkFindUniquePositionsUtil::getSizeInBytesFor(v4 + v5);
  v10 = 2147483648;
  v11 = v9;
  v45 = 2147483648;
  v12 = 0i64;
  array = 0i64;
  v44 = 0;
  if ( v9 <= 0 )
  {
    resulta.m_enum = 0;
LABEL_7:
    v44 = v11;
    goto LABEL_8;
  }
  v13 = v9;
  if ( v9 < 0 )
    v13 = 0;
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v13, 1);
  v10 = v45;
  v12 = array;
  if ( resulta.m_enum == HK_SUCCESS )
    goto LABEL_7;
LABEL_8:
  v14 = v6->m_vertexMapA.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v14 >= v4 )
  {
    v16 = 0i64;
    v41.m_enum = 0;
  }
  else
  {
    v15 = 2 * v14;
    if ( v4 < v15 )
      v4 = v15;
    hkArrayUtil::_reserve(&v41, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_vertexMapA, v4, 4);
    v10 = v45;
    v12 = array;
    v16 = 0i64;
  }
  v17 = v6->m_vertexMapB.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v17 >= v5 )
  {
    v19 = 0;
    v40.m_enum = 0;
  }
  else
  {
    v18 = 2 * v17;
    if ( v5 < v18 )
      v5 = v18;
    hkArrayUtil::_reserve(&v40, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_vertexMapB, v5, 4);
    v10 = v45;
    v12 = array;
    v19 = v40.m_enum;
  }
  if ( resulta.m_enum || v41.m_enum || v19 )
  {
    v8->m_enum = 1;
    v44 = 0;
    if ( v10 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v12,
        v10 & 0x3FFFFFFF);
  }
  else
  {
    v46.m_positions.m_data = 0i64;
    v46.m_positions.m_size = 0;
    v46.m_positions.m_capacityAndFlags = 2147483648;
    v46.m_hashMap.m_map.m_elem = 0i64;
    v46.m_hashMap.m_map.m_numElems = 0;
    v46.m_hashMap.m_map.m_hashMod = -1;
    v46.m_entries.m_data = 0i64;
    v46.m_entries.m_size = 0;
    v46.m_entries.m_capacityAndFlags = 2147483648;
    hkFindUniquePositionsUtil::setBuffer(&v46, v12, numPoints);
    v20 = v7->m_vertices.m_size;
    v21 = v6->m_vertexMapA.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v21 < (signed int)v20 )
    {
      v22 = 2 * v21;
      v23 = v7->m_vertices.m_size;
      if ( (signed int)v20 < v22 )
        v23 = v22;
      hkArrayUtil::_reserve(
        (hkResult *)&numPoints,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v6->m_vertexMapA,
        v23,
        4);
    }
    v6->m_vertexMapA.m_size = v20;
    v24 = 0;
    v25 = v20;
    if ( (signed int)v20 > 0 )
    {
      v26 = (__int64)v49;
      do
      {
        v27 = &v6->m_vertexMapA.m_data[v16];
        v28 = hkFindUniquePositionsUtil::addPosition(&v46, (hkVector4f *)(*(_QWORD *)(v26 + 48) + 16i64 * v24));
        ++v16;
        ++v24;
        *v27 = v28;
      }
      while ( v16 < v25 );
      v8 = v48;
    }
    v29 = v50->m_vertices.m_size;
    v30 = v6->m_vertexMapB.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v30 < (signed int)v29 )
    {
      v31 = 2 * v30;
      v32 = v50->m_vertices.m_size;
      if ( (signed int)v29 < v31 )
        v32 = v31;
      hkArrayUtil::_reserve(
        (hkResult *)&v49,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v6->m_vertexMapB,
        v32,
        4);
    }
    v6->m_vertexMapB.m_size = v29;
    v33 = v29;
    v34 = 0;
    v35 = 0i64;
    if ( (signed int)v29 > 0 )
    {
      v36 = (__int64)v50;
      do
      {
        v37 = &v6->m_vertexMapB.m_data[v35];
        v38 = hkFindUniquePositionsUtil::addPosition(&v46, (hkVector4f *)(*(_QWORD *)(v36 + 48) + 16i64 * v34));
        ++v35;
        ++v34;
        *v37 = v38;
      }
      while ( v35 < v33 );
      v8 = v48;
    }
    hkFindUniquePositionsUtil::~hkFindUniquePositionsUtil(&v46);
    v44 = 0;
    if ( v45 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        v45 & 0x3FFFFFFF);
    v8->m_enum = 0;
  }
  return v8;
}

// File Line: 102
// RVA: 0xBA48B0
char __fastcall hkaiSelfIntersectBooleanFilter2::_canFacesIntersectImpl(hkaiSelfIntersectBooleanFilter2 *this, int faceA, int faceB)
{
  __int64 v3; // r9
  hkaiEdgeGeometry::Edge *const **v4; // rdx
  signed int **v5; // rdi
  signed int **v6; // r15
  hkaiEdgeGeometry::Edge *const **v7; // rdx
  hkaiEdgeGeometry::Edge *const *v8; // rbp
  signed int **v9; // rbx
  int *v10; // rsi
  int v11; // er10
  int v12; // er9
  signed int **v13; // rax
  int *v14; // r11
  int v15; // er8
  int v16; // edx

  v3 = faceA;
  v4 = this->m_faceEdgesA->m_faceStartEdges.m_data;
  v5 = (signed int **)v4[v3];
  v6 = (signed int **)v4[v3 + 1];
  v7 = this->m_faceEdgesB->m_faceStartEdges.m_data;
  v8 = v7[faceB];
  v9 = (signed int **)v7[faceB + 1];
  if ( v5 == v6 )
    return 1;
  v10 = this->m_vertexMapA.m_data;
  while ( 1 )
  {
    v11 = v10[**v5];
    v12 = v10[(*v5)[1]];
    v13 = (signed int **)v8;
    if ( v8 != (hkaiEdgeGeometry::Edge *const *)v9 )
      break;
LABEL_10:
    ++v5;
    if ( v5 == v6 )
      return 1;
  }
  v14 = this->m_vertexMapB.m_data;
  while ( 1 )
  {
    v15 = v14[**v13];
    v16 = v14[(*v13)[1]];
    if ( v11 == v16 && v12 == v15 )
      return 0;
    if ( v11 == v15 && v12 == v16 )
      return 0;
    ++v13;
    if ( v13 == v9 )
      goto LABEL_10;
  }
}

// File Line: 144
// RVA: 0xBA4420
bool __fastcall hkaiSelfIntersectBooleanFilter2::canFacesIntersect(hkaiSelfIntersectBooleanFilter2 *this, int faceA, int faceB)
{
  bool result; // al

  if ( faceA == 1 )
    result = this->m_face1Results.m_data[faceB];
  else
    result = hkaiSelfIntersectBooleanFilter2::_canFacesIntersectImpl(this, faceA, faceB);
  return result;
}

// File Line: 178
// RVA: 0xBA4440
hkResult *__fastcall hkaiSelfIntersectBooleanFilter2::setFaceEdges(hkaiSelfIntersectBooleanFilter2 *this, hkResult *result, hkaiFaceEdges *faceEdgesA, hkaiFaceEdges *faceEdgesB)
{
  hkaiEdgeGeometry *v4; // rax
  signed __int64 v5; // rbp
  hkResult *v6; // rsi
  int v7; // eax
  hkaiSelfIntersectBooleanFilter2 *v8; // r15
  int v9; // eax
  int v10; // er9
  int v12; // edi
  signed __int64 i; // rbx
  hkResult resulta; // [rsp+50h] [rbp+8h]

  v4 = this->m_geomB;
  this->m_faceEdgesA = faceEdgesA;
  this->m_faceEdgesB = faceEdgesB;
  v5 = v4->m_faces.m_size;
  v6 = result;
  v7 = this->m_face1Results.m_capacityAndFlags & 0x3FFFFFFF;
  v8 = this;
  if ( v7 >= (signed int)v5 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    v9 = 2 * v7;
    v10 = v5;
    if ( (signed int)v5 < v9 )
      v10 = v9;
    hkArrayUtil::_reserve(
      &resulta,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_face1Results,
      v10,
      1);
    if ( resulta.m_enum )
    {
      v6->m_enum = 1;
      return v6;
    }
  }
  v8->m_face1Results.m_size = v5;
  v12 = 1;
  *v8->m_face1Results.m_data = 0;
  for ( i = 1i64; i < v5; ++v12 )
    v8->m_face1Results.m_data[++i - 1] = hkaiSelfIntersectBooleanFilter2::_canFacesIntersectImpl(v8, 1, v12);
  v6->m_enum = 0;
  return v6;
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

