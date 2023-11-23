// File Line: 17
// RVA: 0xBAA000
hkResult *__fastcall hkaiEdgeGeometryUtil::findUnwalkableFaces(
        hkResult *result,
        hkaiEdgeGeometry *geom,
        hkaiNavMeshGenerationSettings *settings,
        hkArray<unsigned int,hkContainerHeapAllocator> *unwalkableOut)
{
  hkResult *v5; // r15
  int v7; // esi
  __int64 v8; // r12
  __int64 v9; // rdi
  __int64 v10; // r14
  hkaiEdgeGeometry::Face *m_data; // rax
  hkVector4f centroidOut; // [rsp+20h] [rbp-39h] BYREF
  hkVector4f normalOut; // [rsp+30h] [rbp-29h] BYREF
  hkaiFaceEdges faceEdges; // [rsp+40h] [rbp-19h] BYREF
  hkArrayBase<hkVector4f> points; // [rsp+60h] [rbp+7h] BYREF
  __m128 m_quad; // [rsp+70h] [rbp+17h] BYREF
  hkResult resulta; // [rsp+D8h] [rbp+7Fh] BYREF

  v5 = result;
  unwalkableOut->m_size = 0;
  faceEdges.m_faceEdges.m_data = 0i64;
  faceEdges.m_faceEdges.m_size = 0;
  faceEdges.m_faceEdges.m_capacityAndFlags = 0x80000000;
  faceEdges.m_faceStartEdges.m_data = 0i64;
  faceEdges.m_faceStartEdges.m_size = 0;
  faceEdges.m_faceStartEdges.m_capacityAndFlags = 0x80000000;
  hkaiFaceEdges::setGeometry(&faceEdges, &resulta, geom);
  if ( resulta.m_enum )
  {
    v5->m_enum = HK_FAILURE;
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
        hkaiEdgeGeometry::calculateFaceNormal(geom, &faceEdges, v7, &normalOut);
        hkaiEdgeGeometry::calculateFaceCentroid(
          geom,
          faceEdges.m_faceStartEdges.m_data[v9],
          faceEdges.m_faceStartEdges.m_data[v9 + 1],
          &centroidOut);
        points.m_capacityAndFlags = -2147483647;
        m_quad = centroidOut.m_quad;
        points.m_data = (hkVector4f *)&m_quad;
        m_data = geom->m_faces.m_data;
        points.m_size = 1;
        if ( !hkaiNavMeshGenerationSettings::isWalkableBySlope(settings, &normalOut, &points, m_data[v10].m_data) )
        {
          if ( unwalkableOut->m_size == (unwalkableOut->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, unwalkableOut, 4);
          unwalkableOut->m_data[unwalkableOut->m_size++] = v7;
        }
        points.m_size = 0;
        if ( points.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            points.m_data,
            16 * points.m_capacityAndFlags);
        ++v9;
        ++v7;
        ++v10;
      }
      while ( v9 < v8 );
      v5 = result;
    }
    v5->m_enum = HK_SUCCESS;
  }
  faceEdges.m_faceStartEdges.m_size = 0;
  if ( faceEdges.m_faceStartEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      faceEdges.m_faceStartEdges.m_data,
      8 * faceEdges.m_faceStartEdges.m_capacityAndFlags);
  faceEdges.m_faceEdges.m_size = 0;
  faceEdges.m_faceStartEdges.m_capacityAndFlags = 0x80000000;
  faceEdges.m_faceStartEdges.m_data = 0i64;
  if ( faceEdges.m_faceEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      faceEdges.m_faceEdges.m_data,
      8 * faceEdges.m_faceEdges.m_capacityAndFlags);
  return v5;
}

// File Line: 49
// RVA: 0xBAA230
hkResult *__fastcall hkaiEdgeGeometryUtil::removeUnwalkableFaces(
        hkResult *result,
        hkaiEdgeGeometry *geom,
        hkaiNavMeshGenerationSettings *settings)
{
  _QWORD *Value; // rax
  _QWORD *v7; // rcx
  _QWORD *v8; // r9
  unsigned __int64 v9; // rax
  _QWORD *v10; // rcx
  int m_size; // r9d
  _QWORD *v12; // r9
  unsigned __int64 v13; // r8
  unsigned __int64 v14; // rax
  hkResult v16; // [rsp+30h] [rbp-20h] BYREF
  hkArray<unsigned int,hkContainerHeapAllocator> array; // [rsp+38h] [rbp-18h] BYREF
  hkResult resulta; // [rsp+78h] [rbp+28h] BYREF
  hkResult v19; // [rsp+88h] [rbp+38h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v7 = (_QWORD *)Value[1];
  v8 = Value;
  if ( (unsigned __int64)v7 < Value[3] )
  {
    *v7 = "TtremoveUnwalkableFaces";
    v9 = __rdtsc();
    v10 = v7 + 2;
    *((_DWORD *)v10 - 2) = v9;
    v8[1] = v10;
  }
  m_size = geom->m_faces.m_size;
  array.m_capacityAndFlags = 0x80000000;
  array.m_data = 0i64;
  array.m_size = 0;
  if ( m_size <= 0 )
  {
    resulta.m_enum = HK_SUCCESS;
  }
  else
  {
    hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, &array, m_size, 4);
    if ( resulta.m_enum )
    {
      result->m_enum = HK_FAILURE;
      goto LABEL_12;
    }
  }
  hkaiEdgeGeometryUtil::findUnwalkableFaces(&v19, geom, settings, &array);
  if ( v19.m_enum )
  {
    result->m_enum = HK_FAILURE;
  }
  else
  {
    hkaiEdgeGeometry::removeFaces(geom, &v16, array.m_data, array.m_size);
    if ( v16.m_enum )
      result->m_enum = HK_FAILURE;
    else
      result->m_enum = HK_SUCCESS;
  }
LABEL_12:
  array.m_size = 0;
  if ( array.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      array.m_data,
      4 * array.m_capacityAndFlags);
  array.m_data = 0i64;
  array.m_capacityAndFlags = 0x80000000;
  v12 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v13 = v12[1];
  if ( v13 < v12[3] )
  {
    v14 = __rdtsc();
    *(_DWORD *)(v13 + 8) = v14;
    *(_QWORD *)v13 = "Et";
    v12[1] = v13 + 16;
  }
  return result;
}

// File Line: 66
// RVA: 0xBA9DB0
void __fastcall hkaiEdgeGeometryUtil::removeSmallFaces(hkaiEdgeGeometry *geom, hkSimdFloat32 *minFaceArea)
{
  _QWORD *Value; // rax
  _QWORD *v5; // rcx
  _QWORD *v6; // r8
  unsigned __int64 v7; // rax
  _QWORD *v8; // rcx
  int v9; // ebx
  __int64 v10; // rcx
  __int64 v11; // rdi
  int v12; // ecx
  _QWORD *v13; // rax
  _QWORD *v14; // rcx
  _QWORD *v15; // r8
  unsigned __int64 v16; // rax
  _QWORD *v17; // rcx
  unsigned int *array; // [rsp+20h] [rbp-50h] BYREF
  int numRemoveFaces; // [rsp+28h] [rbp-48h]
  int v20; // [rsp+2Ch] [rbp-44h]
  hkSimdFloat32 v21; // [rsp+30h] [rbp-40h] BYREF
  hkaiFaceEdges v22; // [rsp+40h] [rbp-30h] BYREF
  hkResult result; // [rsp+90h] [rbp+20h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v5 = (_QWORD *)Value[1];
  v6 = Value;
  if ( (unsigned __int64)v5 < Value[3] )
  {
    *v5 = "TtremoveSmallFaces";
    v7 = __rdtsc();
    v8 = v5 + 2;
    *((_DWORD *)v8 - 2) = v7;
    v6[1] = v8;
  }
  v20 = 0x80000000;
  v22.m_faceEdges.m_capacityAndFlags = 0x80000000;
  array = 0i64;
  numRemoveFaces = 0;
  v22.m_faceEdges.m_data = 0i64;
  v22.m_faceEdges.m_size = 0;
  v22.m_faceStartEdges.m_data = 0i64;
  v22.m_faceStartEdges.m_size = 0;
  v22.m_faceStartEdges.m_capacityAndFlags = 0x80000000;
  hkaiFaceEdges::setGeometry(&v22, &result, geom);
  v9 = 1;
  if ( v22.m_faceStartEdges.m_size - 1 > 1 )
  {
    v10 = 8i64;
    do
    {
      v11 = v10 + 8;
      hkaiEdgeGeometry::calculateFaceArea(
        geom,
        &v21,
        *(hkaiEdgeGeometry::Edge *const **)((char *)v22.m_faceStartEdges.m_data + v10),
        *(hkaiEdgeGeometry::Edge *const **)((char *)v22.m_faceStartEdges.m_data + v10 + 8));
      if ( v21.m_real.m128_f32[0] < minFaceArea->m_real.m128_f32[0] )
      {
        v12 = numRemoveFaces;
        if ( numRemoveFaces == (v20 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 4);
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
  hkaiEdgeGeometry::removeFaces(geom, &result, array, numRemoveFaces);
  v22.m_faceStartEdges.m_size = 0;
  if ( v22.m_faceStartEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v22.m_faceStartEdges.m_data,
      8 * v22.m_faceStartEdges.m_capacityAndFlags);
  v22.m_faceStartEdges.m_data = 0i64;
  v22.m_faceStartEdges.m_capacityAndFlags = 0x80000000;
  v22.m_faceEdges.m_size = 0;
  if ( v22.m_faceEdges.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v22.m_faceEdges.m_data,
      8 * v22.m_faceEdges.m_capacityAndFlags);
  v22.m_faceEdges.m_data = 0i64;
  v22.m_faceEdges.m_capacityAndFlags = 0x80000000;
  numRemoveFaces = 0;
  if ( v20 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 4 * v20);
  array = 0i64;
  v20 = 0x80000000;
  v13 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v14 = (_QWORD *)v13[1];
  v15 = v13;
  if ( (unsigned __int64)v14 < v13[3] )
  {
    *v14 = "Et";
    v16 = __rdtsc();
    v17 = v14 + 2;
    *((_DWORD *)v17 - 2) = v16;
    v15[1] = v17;
  }
}

