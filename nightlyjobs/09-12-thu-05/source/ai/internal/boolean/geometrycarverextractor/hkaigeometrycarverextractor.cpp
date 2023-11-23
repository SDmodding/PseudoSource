// File Line: 20
// RVA: 0xB9BD10
hkResult *__fastcall hkaiGeometryCarverExtractor::addCarvers(
        hkResult *result,
        hkaiEdgeGeometry *extrudeGeom,
        hkArrayBase<hkRefPtr<hkaiVolume const > > *carvers,
        hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *painters)
{
  int v4; // edi
  __int64 v9; // rbx
  hkaiVolume *m_pntr; // r8
  int v11; // ebx
  __int64 v12; // rdi
  hkaiMaterialPainter *v13; // rcx
  hkaiVolume *v14; // r8
  hkResult resulta; // [rsp+50h] [rbp+18h] BYREF

  v4 = 0;
  if ( carvers->m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      m_pntr = carvers->m_data[v9].m_pntr;
      if ( m_pntr )
      {
        hkaiGeometryCarverExtractor::addVolume(
          &resulta,
          extrudeGeom,
          m_pntr,
          (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)4);
        if ( resulta.m_enum )
          goto LABEL_14;
      }
      ++v4;
      ++v9;
    }
    while ( v4 < carvers->m_size );
  }
  v11 = 0;
  if ( painters->m_size > 0 )
  {
    v12 = 0i64;
    while ( 1 )
    {
      v13 = painters->m_data[v12].m_pntr;
      if ( v13 )
      {
        v14 = v13->m_volume.m_pntr;
        if ( v14 )
        {
          hkaiGeometryCarverExtractor::addVolume(
            &resulta,
            extrudeGeom,
            v14,
            (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)2);
          if ( resulta.m_enum )
            break;
        }
      }
      ++v11;
      ++v12;
      if ( v11 >= painters->m_size )
        goto LABEL_12;
    }
LABEL_14:
    result->m_enum = HK_FAILURE;
    return result;
  }
LABEL_12:
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 42
// RVA: 0xB9BDF0
hkResult *__fastcall hkaiGeometryCarverExtractor::addCarversInRegion(
        hkResult *result,
        hkaiEdgeGeometry *extrudeGeom,
        hkaiCarverTree *tree,
        hkAabb *aabb)
{
  int m_size; // eax
  hkRefPtr<hkaiMaterialPainter const > *m_data; // rdi
  __int64 v10; // rbx
  hkReferencedObject *m_pntr; // rcx
  hkRefPtr<hkaiVolume const > *v12; // rdi
  __int64 v13; // rbx
  hkReferencedObject *v14; // rcx
  int v15; // eax
  hkRefPtr<hkaiMaterialPainter const > *v16; // rdi
  __int64 v17; // rbx
  hkReferencedObject *v18; // rcx
  __int64 v19; // rbx
  hkReferencedObject *v20; // rcx
  hkRefPtr<hkaiMaterialPainter const > *v21; // rdi
  int v22; // eax
  __int64 v23; // rbx
  hkReferencedObject *v24; // rcx
  __int64 v25; // rbx
  hkReferencedObject *v26; // rcx
  int v27; // eax
  __int64 v28; // rbx
  hkReferencedObject *v29; // rcx
  __int64 v30; // rbx
  hkReferencedObject *v31; // rcx
  hkResult resulta; // [rsp+20h] [rbp-30h] BYREF
  hkResult v34; // [rsp+24h] [rbp-2Ch] BYREF
  hkResult v35; // [rsp+28h] [rbp-28h] BYREF
  hkArray<hkRefPtr<hkaiMaterialPainter const >,hkContainerHeapAllocator> painterHits; // [rsp+30h] [rbp-20h] BYREF
  hkArray<hkRefPtr<hkaiVolume const >,hkContainerHeapAllocator> carverHits; // [rsp+40h] [rbp-10h] BYREF

  carverHits.m_data = 0i64;
  carverHits.m_size = 0;
  carverHits.m_capacityAndFlags = 0x80000000;
  painterHits.m_data = 0i64;
  painterHits.m_size = 0;
  painterHits.m_capacityAndFlags = 0x80000000;
  hkaiCarverTree::queryAabbCarvers(tree, &resulta, aabb, &carverHits);
  if ( resulta.m_enum )
  {
    m_size = painterHits.m_size;
    m_data = painterHits.m_data;
    result->m_enum = HK_FAILURE;
    v10 = --m_size;
    if ( m_size >= 0 )
    {
      do
      {
        m_pntr = m_data[v10].m_pntr;
        if ( m_pntr )
          hkReferencedObject::removeReference(m_pntr);
        m_data[v10--].m_pntr = 0i64;
      }
      while ( v10 >= 0 );
      m_data = painterHits.m_data;
    }
    painterHits.m_size = 0;
    if ( painterHits.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        m_data,
        8 * painterHits.m_capacityAndFlags);
    v12 = carverHits.m_data;
    painterHits.m_data = 0i64;
    painterHits.m_capacityAndFlags = 0x80000000;
    v13 = carverHits.m_size - 1;
    if ( carverHits.m_size - 1 >= 0 )
    {
      do
      {
        v14 = v12[v13].m_pntr;
        if ( v14 )
          hkReferencedObject::removeReference(v14);
        v12[v13--].m_pntr = 0i64;
      }
      while ( v13 >= 0 );
LABEL_51:
      v12 = carverHits.m_data;
    }
  }
  else
  {
    hkaiCarverTree::queryAabbPainters(tree, &v34, aabb, &painterHits);
    if ( v34.m_enum )
    {
      v15 = painterHits.m_size;
      v16 = painterHits.m_data;
      result->m_enum = HK_FAILURE;
      v17 = --v15;
      if ( v15 >= 0 )
      {
        do
        {
          v18 = v16[v17].m_pntr;
          if ( v18 )
            hkReferencedObject::removeReference(v18);
          v16[v17--].m_pntr = 0i64;
        }
        while ( v17 >= 0 );
        v16 = painterHits.m_data;
      }
      painterHits.m_size = 0;
      if ( painterHits.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          v16,
          8 * painterHits.m_capacityAndFlags);
      v12 = carverHits.m_data;
      painterHits.m_data = 0i64;
      painterHits.m_capacityAndFlags = 0x80000000;
      v19 = carverHits.m_size - 1;
      if ( carverHits.m_size - 1 >= 0 )
      {
        do
        {
          v20 = v12[v19].m_pntr;
          if ( v20 )
            hkReferencedObject::removeReference(v20);
          v12[v19--].m_pntr = 0i64;
        }
        while ( v19 >= 0 );
        goto LABEL_51;
      }
    }
    else
    {
      hkaiGeometryCarverExtractor::addCarvers(&v35, extrudeGeom, &carverHits, &painterHits);
      v21 = painterHits.m_data;
      if ( v35.m_enum )
      {
        v22 = painterHits.m_size - 1;
        result->m_enum = HK_FAILURE;
        v23 = v22;
        if ( v22 >= 0 )
        {
          do
          {
            v24 = v21[v23].m_pntr;
            if ( v24 )
              hkReferencedObject::removeReference(v24);
            v21[v23--].m_pntr = 0i64;
          }
          while ( v23 >= 0 );
          v21 = painterHits.m_data;
        }
        painterHits.m_size = 0;
        if ( painterHits.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v21,
            8 * painterHits.m_capacityAndFlags);
        v12 = carverHits.m_data;
        painterHits.m_data = 0i64;
        painterHits.m_capacityAndFlags = 0x80000000;
        v25 = carverHits.m_size - 1;
        if ( carverHits.m_size - 1 >= 0 )
        {
          do
          {
            v26 = v12[v25].m_pntr;
            if ( v26 )
              hkReferencedObject::removeReference(v26);
            v12[v25--].m_pntr = 0i64;
          }
          while ( v25 >= 0 );
          goto LABEL_51;
        }
      }
      else
      {
        v27 = painterHits.m_size - 1;
        result->m_enum = HK_SUCCESS;
        v28 = v27;
        if ( v27 >= 0 )
        {
          do
          {
            v29 = v21[v28].m_pntr;
            if ( v29 )
              hkReferencedObject::removeReference(v29);
            v21[v28--].m_pntr = 0i64;
          }
          while ( v28 >= 0 );
          v21 = painterHits.m_data;
        }
        painterHits.m_size = 0;
        if ( painterHits.m_capacityAndFlags >= 0 )
          hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
            &hkContainerHeapAllocator::s_alloc,
            v21,
            8 * painterHits.m_capacityAndFlags);
        v12 = carverHits.m_data;
        painterHits.m_data = 0i64;
        painterHits.m_capacityAndFlags = 0x80000000;
        v30 = carverHits.m_size - 1;
        if ( carverHits.m_size - 1 >= 0 )
        {
          do
          {
            v31 = v12[v30].m_pntr;
            if ( v31 )
              hkReferencedObject::removeReference(v31);
            v12[v30--].m_pntr = 0i64;
          }
          while ( v30 >= 0 );
          goto LABEL_51;
        }
      }
    }
  }
  carverHits.m_size = 0;
  if ( carverHits.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      v12,
      8 * carverHits.m_capacityAndFlags);
  return result;
}

// File Line: 61
// RVA: 0xB9C140
hkResult *__fastcall hkaiGeometryCarverExtractor::addVolume(
        hkResult *result,
        hkaiEdgeGeometry *extrudeGeom,
        hkaiVolume *volume,
        hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> flags)
{
  hkBaseObjectVtbl *vfptr; // rax
  int m_capacityAndFlags; // r8d
  hkGeometry geom; // [rsp+30h] [rbp-59h] BYREF
  hkResult resulta; // [rsp+60h] [rbp-29h] BYREF
  hkaiEdgeGeometry v12; // [rsp+70h] [rbp-19h] BYREF
  int v13; // [rsp+100h] [rbp+77h] BYREF
  hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> v14; // [rsp+108h] [rbp+7Fh]

  v14.m_storage = flags.m_storage;
  hkaiEdgeGeometry::hkaiEdgeGeometry(&v12);
  geom.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  vfptr = volume->vfptr;
  *(_DWORD *)&geom.m_memSizeAndFlags = 0x1FFFF;
  geom.m_vertices.m_data = 0i64;
  geom.m_vertices.m_size = 0;
  geom.m_vertices.m_capacityAndFlags = 0x80000000;
  geom.m_triangles.m_data = 0i64;
  geom.m_triangles.m_size = 0;
  geom.m_triangles.m_capacityAndFlags = 0x80000000;
  ((void (__fastcall *)(hkaiVolume *, int *, hkGeometry *))vfptr[2].__first_virtual_table_function__)(
    volume,
    &v13,
    &geom);
  if ( v13 )
  {
    m_capacityAndFlags = geom.m_triangles.m_capacityAndFlags;
    result->m_enum = HK_FAILURE;
    geom.m_triangles.m_size = 0;
    if ( m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        geom.m_triangles.m_data,
        16 * m_capacityAndFlags);
    geom.m_triangles.m_data = 0i64;
    geom.m_triangles.m_capacityAndFlags = 0x80000000;
    geom.m_vertices.m_size = 0;
    if ( geom.m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        geom.m_vertices.m_data,
        16 * geom.m_vertices.m_capacityAndFlags);
    geom.m_vertices.m_data = 0i64;
    geom.m_vertices.m_capacityAndFlags = 0x80000000;
    geom.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
  }
  else
  {
    hkaiEdgeGeometry::set(&v12, &resulta, &geom, v14, 0);
    if ( resulta.m_enum )
      result->m_enum = HK_FAILURE;
    else
      hkaiEdgeGeometry::concat(extrudeGeom, result, &v12);
    hkGeometry::~hkGeometry(&geom);
  }
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&v12);
  return result;
}

