// File Line: 17
// RVA: 0xBAA000
hkResult *__fastcall hkaiEdgeGeometryUtil::findUnwalkableFaces(hkResult *result, hkaiEdgeGeometry *geom, hkaiNavMeshGenerationSettings *settings, hkArray<unsigned int,hkContainerHeapAllocator> *unwalkableOut)
{
  hkaiEdgeGeometry *v4; // r13
  hkResult *v5; // r15
  hkArray<unsigned int,hkContainerHeapAllocator> *v6; // rbx
  int v7; // esi
  signed __int64 v8; // r12
  signed __int64 v9; // rdi
  signed __int64 v10; // r14
  hkaiEdgeGeometry::Face *v11; // rax
  hkVector4f centroidOut; // [rsp+20h] [rbp-39h]
  hkVector4f normalOut; // [rsp+30h] [rbp-29h]
  hkaiFaceEdges faceEdges; // [rsp+40h] [rbp-19h]
  hkArrayBase<hkVector4f> points; // [rsp+60h] [rbp+7h]
  __m128 v17; // [rsp+70h] [rbp+17h]
  hkResult *v18; // [rsp+C0h] [rbp+67h]
  hkaiNavMeshGenerationSettings *v19; // [rsp+D0h] [rbp+77h]
  hkResult resulta; // [rsp+D8h] [rbp+7Fh]

  v19 = settings;
  v18 = result;
  v4 = geom;
  v5 = result;
  v6 = unwalkableOut;
  unwalkableOut->m_size = 0;
  faceEdges.m_faceEdges.m_data = 0i64;
  faceEdges.m_faceEdges.m_size = 0;
  faceEdges.m_faceEdges.m_capacityAndFlags = 2147483648;
  faceEdges.m_faceStartEdges.m_data = 0i64;
  faceEdges.m_faceStartEdges.m_size = 0;
  faceEdges.m_faceStartEdges.m_capacityAndFlags = 2147483648;
  hkaiFaceEdges::setGeometry(&faceEdges, &resulta, geom);
  if ( resulta.m_enum )
  {
    v5->m_enum = 1;
  }
  else
  {
    v7 = 1;
    v8 = faceEdges.m_faceStartEdges.m_size - 1;
    v9 = 1i64;
    if ( v8 > 1 )
    {
      v10 = 1i64;
      do
      {
        hkaiEdgeGeometry::calculateFaceNormal(v4, &faceEdges, v7, &normalOut);
        hkaiEdgeGeometry::calculateFaceCentroid(
          v4,
          faceEdges.m_faceStartEdges.m_data[v9],
          faceEdges.m_faceStartEdges.m_data[v9 + 1],
          &centroidOut);
        points.m_capacityAndFlags = -2147483647;
        v17 = centroidOut.m_quad;
        points.m_data = (hkVector4f *)&v17;
        v11 = v4->m_faces.m_data;
        points.m_size = 1;
        if ( !(unsigned int)hkaiNavMeshGenerationSettings::isWalkableBySlope(v19, &normalOut, &points, v11[v10].m_data) )
        {
          if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 4);
          v6->m_data[v6->m_size++] = v7;
        }
        points.m_size = 0;
        if ( points.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            points.m_data,
            16 * points.m_capacityAndFlags);
        ++v9;
        ++v7;
        ++v10;
      }
      while ( v9 < v8 );
      v5 = v18;
    }
    v5->m_enum = 0;
  }
  faceEdges.m_faceStartEdges.m_size = 0;
  if ( faceEdges.m_faceStartEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      faceEdges.m_faceStartEdges.m_data,
      8 * faceEdges.m_faceStartEdges.m_capacityAndFlags);
  faceEdges.m_faceEdges.m_size = 0;
  faceEdges.m_faceStartEdges.m_capacityAndFlags = 2147483648;
  faceEdges.m_faceStartEdges.m_data = 0i64;
  if ( faceEdges.m_faceEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      faceEdges.m_faceEdges.m_data,
      8 * faceEdges.m_faceEdges.m_capacityAndFlags);
  return v5;
}

// File Line: 49
// RVA: 0xBAA230
hkResult *__fastcall hkaiEdgeGeometryUtil::removeUnwalkableFaces(hkResult *result, hkaiEdgeGeometry *geom, hkaiNavMeshGenerationSettings *settings)
{
  hkResult *v3; // rbx
  hkaiNavMeshGenerationSettings *v4; // rsi
  hkaiEdgeGeometry *v5; // rdi
  _QWORD *v6; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // rcx
  int v11; // er9
  _QWORD *v12; // r9
  unsigned __int64 v13; // r8
  unsigned __int64 v14; // rax
  hkResult v16; // [rsp+30h] [rbp-20h]
  unsigned int *array; // [rsp+38h] [rbp-18h]
  int numRemoveFaces; // [rsp+40h] [rbp-10h]
  int v19; // [rsp+44h] [rbp-Ch]
  hkResult resulta; // [rsp+78h] [rbp+28h]
  hkResult v21; // [rsp+88h] [rbp+38h]

  v3 = result;
  v4 = settings;
  v5 = geom;
  v6 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)v6[1];
  v8 = v6;
  if ( (unsigned __int64)v7 < v6[3] )
  {
    *v7 = "TtremoveUnwalkableFaces";
    v9 = __rdtsc();
    v10 = (signed __int64)(v7 + 2);
    *(_DWORD *)(v10 - 8) = v9;
    v8[1] = v10;
  }
  v11 = v5->m_faces.m_size;
  v19 = 2147483648;
  array = 0i64;
  numRemoveFaces = 0;
  if ( v11 <= 0 )
  {
    resulta.m_enum = 0;
  }
  else
  {
    if ( v11 < 0 )
      v11 = 0;
    hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v11, 4);
    if ( resulta.m_enum )
    {
      v3->m_enum = 1;
      goto LABEL_14;
    }
  }
  hkaiEdgeGeometryUtil::findUnwalkableFaces(&v21, v5, v4, (hkArray<unsigned int,hkContainerHeapAllocator> *)&array);
  if ( v21.m_enum )
  {
    v3->m_enum = 1;
  }
  else
  {
    hkaiEdgeGeometry::removeFaces(v5, &v16, array, numRemoveFaces);
    if ( v16.m_enum )
      v3->m_enum = 1;
    else
      v3->m_enum = 0;
  }
LABEL_14:
  numRemoveFaces = 0;
  if ( v19 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v19);
  array = 0i64;
  v19 = 2147483648;
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = v12[1];
  if ( v13 < v12[3] )
  {
    v14 = __rdtsc();
    *(_DWORD *)(v13 + 8) = v14;
    *(_QWORD *)v13 = "Et";
    v12[1] = v13 + 16;
  }
  return v3;
}

// File Line: 66
// RVA: 0xBA9DB0
void __fastcall hkaiEdgeGeometryUtil::removeSmallFaces(hkaiEdgeGeometry *geom, hkSimdFloat32 *minFaceArea)
{
  hkaiEdgeGeometry *v2; // rsi
  hkSimdFloat32 *v3; // r14
  _QWORD *v4; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  signed __int64 v8; // rcx
  int v9; // ebx
  signed __int64 v10; // rcx
  signed __int64 v11; // rdi
  int v12; // ecx
  _QWORD *v13; // rax
  _QWORD *v14; // rcx
  _QWORD *v15; // r8
  unsigned __int64 v16; // rax
  signed __int64 v17; // rcx
  unsigned int *array; // [rsp+20h] [rbp-50h]
  int numRemoveFaces; // [rsp+28h] [rbp-48h]
  int v20; // [rsp+2Ch] [rbp-44h]
  hkSimdFloat32 v21; // [rsp+30h] [rbp-40h]
  hkaiFaceEdges v22; // [rsp+40h] [rbp-30h]
  hkResult result; // [rsp+90h] [rbp+20h]

  v2 = geom;
  v3 = minFaceArea;
  v4 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)v4[1];
  v6 = v4;
  if ( (unsigned __int64)v5 < v4[3] )
  {
    *v5 = "TtremoveSmallFaces";
    v7 = __rdtsc();
    v8 = (signed __int64)(v5 + 2);
    *(_DWORD *)(v8 - 8) = v7;
    v6[1] = v8;
  }
  v20 = 2147483648;
  v22.m_faceEdges.m_capacityAndFlags = 2147483648;
  array = 0i64;
  numRemoveFaces = 0;
  v22.m_faceEdges.m_data = 0i64;
  v22.m_faceEdges.m_size = 0;
  v22.m_faceStartEdges.m_data = 0i64;
  v22.m_faceStartEdges.m_size = 0;
  v22.m_faceStartEdges.m_capacityAndFlags = 2147483648;
  hkaiFaceEdges::setGeometry(&v22, &result, v2);
  v9 = 1;
  if ( v22.m_faceStartEdges.m_size - 1 > 1 )
  {
    v10 = 8i64;
    do
    {
      v11 = v10 + 8;
      hkaiEdgeGeometry::calculateFaceArea(
        v2,
        &v21,
        *(hkaiEdgeGeometry::Edge *const **)((char *)v22.m_faceStartEdges.m_data + v10),
        *(hkaiEdgeGeometry::Edge *const **)((char *)v22.m_faceStartEdges.m_data + v10 + 8));
      if ( v21.m_real.m128_f32[0] < v3->m_real.m128_f32[0] )
      {
        v12 = numRemoveFaces;
        if ( numRemoveFaces == (v20 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 4);
          v12 = numRemoveFaces;
        }
        array[v12] = v9;
        ++numRemoveFaces;
      }
      ++v9;
      v10 = v11;
    }
    while ( v9 < v22.m_faceStartEdges.m_size - 1 );
  }
  hkaiEdgeGeometry::removeFaces(v2, &result, array, numRemoveFaces);
  v22.m_faceStartEdges.m_size = 0;
  if ( v22.m_faceStartEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v22.m_faceStartEdges.m_data,
      8 * v22.m_faceStartEdges.m_capacityAndFlags);
  v22.m_faceStartEdges.m_data = 0i64;
  v22.m_faceStartEdges.m_capacityAndFlags = 2147483648;
  v22.m_faceEdges.m_size = 0;
  if ( v22.m_faceEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v22.m_faceEdges.m_data,
      8 * v22.m_faceEdges.m_capacityAndFlags);
  v22.m_faceEdges.m_data = 0i64;
  v22.m_faceEdges.m_capacityAndFlags = 2147483648;
  numRemoveFaces = 0;
  if ( v20 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      array,
      4 * v20);
  array = 0i64;
  v20 = 2147483648;
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  v15 = v13;
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "Et";
    v16 = __rdtsc();
    v17 = (signed __int64)(v14 + 2);
    *(_DWORD *)(v17 - 8) = v16;
    v15[1] = v17;
  }
}

