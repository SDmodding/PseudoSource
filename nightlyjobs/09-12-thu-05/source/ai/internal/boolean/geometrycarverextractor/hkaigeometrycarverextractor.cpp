// File Line: 20
// RVA: 0xB9BD10
hkResult *__fastcall hkaiGeometryCarverExtractor::addCarvers(hkResult *result, hkaiEdgeGeometry *extrudeGeom, hkArrayBase<hkRefPtr<hkaiVolume const > > *carvers, hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *painters)
{
  int v4; // edi
  hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *v5; // r14
  hkArrayBase<hkRefPtr<hkaiVolume const > > *v6; // rsi
  hkaiEdgeGeometry *v7; // rbp
  hkResult *v8; // r15
  __int64 v9; // rbx
  hkaiVolume *v10; // r8
  int v11; // ebx
  __int64 v12; // rdi
  hkaiMaterialPainter *v13; // rcx
  hkaiVolume *v14; // r8
  hkResult resulta; // [rsp+50h] [rbp+18h]

  v4 = 0;
  v5 = painters;
  v6 = carvers;
  v7 = extrudeGeom;
  v8 = result;
  if ( carvers->m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = v6->m_data[v9].m_pntr;
      if ( v10 )
      {
        hkaiGeometryCarverExtractor::addVolume(
          &resulta,
          v7,
          v10,
          (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)4);
        if ( resulta.m_enum )
          goto LABEL_14;
      }
      ++v4;
      ++v9;
    }
    while ( v4 < v6->m_size );
  }
  v11 = 0;
  if ( v5->m_size > 0 )
  {
    v12 = 0i64;
    while ( 1 )
    {
      v13 = v5->m_data[v12].m_pntr;
      if ( v13 )
      {
        v14 = v13->m_volume.m_pntr;
        if ( v14 )
        {
          hkaiGeometryCarverExtractor::addVolume(
            &resulta,
            v7,
            v14,
            (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)2);
          if ( resulta.m_enum )
            break;
        }
      }
      ++v11;
      ++v12;
      if ( v11 >= v5->m_size )
        goto LABEL_12;
    }
LABEL_14:
    v8->m_enum = 1;
    return v8;
  }
LABEL_12:
  v8->m_enum = 0;
  return v8;
}

// File Line: 42
// RVA: 0xB9BDF0
hkResult *__fastcall hkaiGeometryCarverExtractor::addCarversInRegion(hkResult *result, hkaiEdgeGeometry *extrudeGeom, hkaiCarverTree *tree, hkAabb *aabb)
{
  hkAabb *v4; // rbx
  hkaiCarverTree *v5; // rdi
  hkaiEdgeGeometry *v6; // rsi
  hkResult *v7; // r14
  int v8; // eax
  hkRefPtr<hkaiMaterialPainter const > *v9; // rdi
  __int64 v10; // rbx
  hkReferencedObject *v11; // rcx
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
  hkResult resulta; // [rsp+20h] [rbp-30h]
  hkResult v34; // [rsp+24h] [rbp-2Ch]
  hkResult v35; // [rsp+28h] [rbp-28h]
  hkArray<hkRefPtr<hkaiMaterialPainter const >,hkContainerHeapAllocator> painterHits; // [rsp+30h] [rbp-20h]
  hkArray<hkRefPtr<hkaiVolume const >,hkContainerHeapAllocator> carverHits; // [rsp+40h] [rbp-10h]

  v4 = aabb;
  v5 = tree;
  v6 = extrudeGeom;
  v7 = result;
  carverHits.m_data = 0i64;
  carverHits.m_size = 0;
  carverHits.m_capacityAndFlags = 2147483648;
  painterHits.m_data = 0i64;
  painterHits.m_size = 0;
  painterHits.m_capacityAndFlags = 2147483648;
  hkaiCarverTree::queryAabbCarvers(tree, &resulta, aabb, &carverHits);
  if ( resulta.m_enum )
  {
    v8 = painterHits.m_size;
    v9 = painterHits.m_data;
    v7->m_enum = 1;
    v10 = --v8;
    if ( v8 >= 0 )
    {
      do
      {
        v11 = (hkReferencedObject *)&v9[v10].m_pntr->vfptr;
        if ( v11 )
          hkReferencedObject::removeReference(v11);
        v9[v10--].m_pntr = 0i64;
      }
      while ( v10 >= 0 );
      v9 = painterHits.m_data;
    }
    painterHits.m_size = 0;
    if ( painterHits.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v9,
        8 * painterHits.m_capacityAndFlags);
    v12 = carverHits.m_data;
    painterHits.m_data = 0i64;
    painterHits.m_capacityAndFlags = 2147483648;
    v13 = carverHits.m_size - 1;
    if ( carverHits.m_size - 1 >= 0 )
    {
      do
      {
        v14 = (hkReferencedObject *)&v12[v13].m_pntr->vfptr;
        if ( v14 )
          hkReferencedObject::removeReference(v14);
        v12[v13--].m_pntr = 0i64;
      }
      while ( v13 >= 0 );
LABEL_51:
      v12 = carverHits.m_data;
      goto LABEL_52;
    }
  }
  else
  {
    hkaiCarverTree::queryAabbPainters(v5, &v34, v4, &painterHits);
    if ( v34.m_enum )
    {
      v15 = painterHits.m_size;
      v16 = painterHits.m_data;
      v7->m_enum = 1;
      v17 = --v15;
      if ( v15 >= 0 )
      {
        do
        {
          v18 = (hkReferencedObject *)&v16[v17].m_pntr->vfptr;
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
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          v16,
          8 * painterHits.m_capacityAndFlags);
      v12 = carverHits.m_data;
      painterHits.m_data = 0i64;
      painterHits.m_capacityAndFlags = 2147483648;
      v19 = carverHits.m_size - 1;
      if ( carverHits.m_size - 1 >= 0 )
      {
        do
        {
          v20 = (hkReferencedObject *)&v12[v19].m_pntr->vfptr;
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
      hkaiGeometryCarverExtractor::addCarvers(
        &v35,
        v6,
        (hkArrayBase<hkRefPtr<hkaiVolume const > > *)&carverHits.m_data,
        (hkArrayBase<hkRefPtr<hkaiMaterialPainter const > > *)&painterHits.m_data);
      v21 = painterHits.m_data;
      if ( v35.m_enum )
      {
        v22 = painterHits.m_size - 1;
        v7->m_enum = 1;
        v23 = v22;
        if ( v22 >= 0 )
        {
          do
          {
            v24 = (hkReferencedObject *)&v21[v23].m_pntr->vfptr;
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
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v21,
            8 * painterHits.m_capacityAndFlags);
        v12 = carverHits.m_data;
        painterHits.m_data = 0i64;
        painterHits.m_capacityAndFlags = 2147483648;
        v25 = carverHits.m_size - 1;
        if ( carverHits.m_size - 1 >= 0 )
        {
          do
          {
            v26 = (hkReferencedObject *)&v12[v25].m_pntr->vfptr;
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
        v7->m_enum = 0;
        v28 = v27;
        if ( v27 >= 0 )
        {
          do
          {
            v29 = (hkReferencedObject *)&v21[v28].m_pntr->vfptr;
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
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
            v21,
            8 * painterHits.m_capacityAndFlags);
        v12 = carverHits.m_data;
        painterHits.m_data = 0i64;
        painterHits.m_capacityAndFlags = 2147483648;
        v30 = carverHits.m_size - 1;
        if ( carverHits.m_size - 1 >= 0 )
        {
          do
          {
            v31 = (hkReferencedObject *)&v12[v30].m_pntr->vfptr;
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
LABEL_52:
  carverHits.m_size = 0;
  if ( carverHits.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v12,
      8 * carverHits.m_capacityAndFlags);
  return v7;
}

// File Line: 61
// RVA: 0xB9C140
hkResult *__fastcall hkaiGeometryCarverExtractor::addVolume(hkResult *result, hkaiEdgeGeometry *extrudeGeom, hkaiVolume *volume, hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char> flags)
{
  hkResult *v4; // rdi
  hkaiVolume *v5; // rbx
  hkaiEdgeGeometry *v6; // rsi
  hkBaseObjectVtbl *v7; // rax
  int v8; // er8
  hkGeometry geom; // [rsp+30h] [rbp-59h]
  hkResult resulta; // [rsp+60h] [rbp-29h]
  hkaiEdgeGeometry v12; // [rsp+70h] [rbp-19h]
  int v13; // [rsp+100h] [rbp+77h]
  char v14; // [rsp+108h] [rbp+7Fh]

  v14 = flags.m_storage;
  v4 = result;
  v5 = volume;
  v6 = extrudeGeom;
  hkaiEdgeGeometry::hkaiEdgeGeometry(&v12);
  geom.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
  v7 = v5->vfptr;
  *(_DWORD *)&geom.m_memSizeAndFlags = 0x1FFFF;
  geom.m_vertices.m_data = 0i64;
  geom.m_vertices.m_size = 0;
  geom.m_vertices.m_capacityAndFlags = 2147483648;
  geom.m_triangles.m_data = 0i64;
  geom.m_triangles.m_size = 0;
  geom.m_triangles.m_capacityAndFlags = 2147483648;
  ((void (__fastcall *)(hkaiVolume *, int *, hkGeometry *))v7[2].__first_virtual_table_function__)(v5, &v13, &geom);
  if ( v13 )
  {
    v8 = geom.m_triangles.m_capacityAndFlags;
    v4->m_enum = 1;
    geom.m_triangles.m_size = 0;
    if ( v8 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        geom.m_triangles.m_data,
        16 * v8);
    geom.m_triangles.m_data = 0i64;
    geom.m_triangles.m_capacityAndFlags = 2147483648;
    geom.m_vertices.m_size = 0;
    if ( geom.m_vertices.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        geom.m_vertices.m_data,
        16 * geom.m_vertices.m_capacityAndFlags);
    geom.m_vertices.m_data = 0i64;
    geom.m_vertices.m_capacityAndFlags = 2147483648;
    geom.vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
  }
  else
  {
    hkaiEdgeGeometry::set(&v12, &resulta, &geom, (hkFlags<enum hkaiEdgeGeometry::FaceFlagBits,unsigned char>)v14, 0);
    if ( resulta.m_enum )
      v4->m_enum = 1;
    else
      hkaiEdgeGeometry::concat(v6, v4, &v12);
    hkGeometry::~hkGeometry(&geom);
  }
  hkaiEdgeGeometry::~hkaiEdgeGeometry(&v12);
  return v4;
}

