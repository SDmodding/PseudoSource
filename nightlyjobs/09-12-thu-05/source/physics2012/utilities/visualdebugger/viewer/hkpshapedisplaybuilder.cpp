// File Line: 62
// RVA: 0xE1BD10
void __fastcall hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment::hkpShapeDisplayBuilderEnvironment(hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment *this)
{
  this->m_spherePhiRes = 8;
  this->m_sphereThetaRes = 8;
}

// File Line: 70
// RVA: 0xE1BD30
void __fastcall hkpShapeDisplayBuilder::hkpShapeDisplayBuilder(hkpShapeDisplayBuilder *this, hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment *env)
{
  hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment v2; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpShapeDisplayBuilder::`vftable';
  v2 = *env;
  this->m_currentGeometry = 0i64;
  this->m_environment = v2;
}

// File Line: 76
// RVA: 0xE1BD60
void __fastcall hkpShapeDisplayBuilder::buildDisplayGeometries(hkpShapeDisplayBuilder *this, hkpShape *shape, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v3; // rbx
  hkpShape *v4; // rdi
  hkpShapeDisplayBuilder *v5; // rsi
  hkTransformf transform; // [rsp+30h] [rbp-48h]

  v3 = displayGeometries;
  v4 = shape;
  v5 = this;
  transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
  transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  transform.m_translation = 0i64;
  hkpShapeDisplayBuilder::resetCurrentRawGeometry(this);
  v3->m_size = 0;
  hkpShapeDisplayBuilder::buildShapeDisplay(v5, v4, &transform, v3, 0i64);
}

// File Line: 89
// RVA: 0xE1F1B0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplayTriangleSubPartsCompress(hkpShapeDisplayBuilder *this, hkpExtendedMeshShape *extendedMeshShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpExtendedMeshShape *v4; // rbx
  hkGeometry *v5; // r13
  __int64 v6; // rax
  __int64 v7; // rcx
  hkpExtendedMeshShape::TrianglesSubpart *v8; // r15
  hkQsTransformf *v9; // r15
  int v10; // ecx
  int v11; // eax
  int v12; // er8
  _DWORD *v13; // rdx
  int v14; // eax
  __int64 v15; // rsi
  signed __int64 v16; // r12
  int v17; // ebx
  unsigned __int64 *v18; // r14
  int v19; // eax
  int v20; // ecx
  hkVector4f *v21; // rdi
  __int64 v22; // rbx
  int v23; // er9
  int v24; // eax
  int v25; // eax
  hkGeometry::Triangle *v26; // rcx
  int v27; // eax
  __m128 v28; // xmm2
  __int64 v29; // rsi
  signed __int64 v30; // r12
  int v31; // ebx
  unsigned __int64 *v32; // r14
  int v33; // eax
  int v34; // ecx
  hkVector4f *v35; // rbx
  __int64 v36; // rbx
  int v37; // er9
  int v38; // eax
  int v39; // eax
  int v40; // edx
  int v41; // er10
  int v42; // ecx
  int v43; // er9
  int v44; // er8
  int v45; // eax
  hkGeometry::Triangle *v46; // r11
  bool v47; // zf
  __int64 v48; // [rsp+30h] [rbp-59h]
  int v49; // [rsp+38h] [rbp-51h]
  int v50; // [rsp+40h] [rbp-49h]
  int v51; // [rsp+44h] [rbp-45h]
  hkResult v52; // [rsp+48h] [rbp-41h]
  hkResult result; // [rsp+4Ch] [rbp-3Dh]
  int v54; // [rsp+50h] [rbp-39h]
  int v55; // [rsp+54h] [rbp-35h]
  int v56; // [rsp+58h] [rbp-31h]
  int v57; // [rsp+5Ch] [rbp-2Dh]
  int v58; // [rsp+60h] [rbp-29h]
  int v59; // [rsp+64h] [rbp-25h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v60; // [rsp+68h] [rbp-21h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v61; // [rsp+78h] [rbp-11h]
  __int64 v62; // [rsp+88h] [rbp-1h]
  __int64 v63; // [rsp+90h] [rbp+7h]
  hkpExtendedMeshShape *v64; // [rsp+F8h] [rbp+6Fh]
  hkTransformf *a; // [rsp+100h] [rbp+77h]

  a = transform;
  v64 = extendedMeshShape;
  v4 = extendedMeshShape;
  v5 = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries)->m_geometry;
  v6 = v4->m_trianglesSubparts.m_size;
  v61.m_elem = 0i64;
  v61.m_numElems = 0;
  v61.m_hashMod = -1;
  v63 = v6;
  if ( v6 <= 0 )
    goto LABEL_39;
  v7 = 0i64;
  v62 = 0i64;
  do
  {
    v8 = v4->m_trianglesSubparts.m_data;
    v60.m_elem = 0i64;
    v60.m_numElems = 0;
    v9 = (hkQsTransformf *)((char *)v8 + v7);
    v60.m_hashMod = -1;
    v10 = 0;
    v11 = v9->m_scale.m_quad.m128_i32[0];
    v50 = 0;
    v51 = v11;
    if ( v11 <= 0 )
      goto LABEL_38;
    do
    {
      v12 = v10 & v9[1].m_rotation.m_vec.m_quad.m128_i8[11];
      v13 = (_DWORD *)(v9[1].m_translation.m_quad.m128_u64[1] + v10 * v9[1].m_rotation.m_vec.m_quad.m128_u16[4]);
      switch ( v9[1].m_rotation.m_vec.m_quad.m128_i8[10] )
      {
        case 1:
          LODWORD(v48) = *(unsigned __int8 *)v13;
          HIDWORD(v48) = *((unsigned __int8 *)v13 + v12 + 1);
          v14 = *((unsigned __int8 *)v13 + (v12 ^ 1i64) + 1);
          goto LABEL_11;
        case 2:
          LODWORD(v48) = *(unsigned __int16 *)v13;
          HIDWORD(v48) = *((unsigned __int16 *)v13 + v12 + 1);
          v14 = *((unsigned __int16 *)v13 + (v12 ^ 1i64) + 1);
          goto LABEL_11;
        case 3:
          LODWORD(v48) = *v13;
          HIDWORD(v48) = v13[v12 + 1];
          v14 = v13[(v12 ^ 1i64) + 1];
LABEL_11:
          v49 = v14;
          goto LABEL_12;
      }
      v48 = 0i64;
      v49 = 0;
LABEL_12:
      v15 = 0i64;
      v16 = 3i64;
      do
      {
        v17 = v5->m_vertices.m_size;
        v18 = (unsigned __int64 *)(v9->m_scale.m_quad.m128_u64[1]
                                 + v9[1].m_rotation.m_vec.m_quad.m128_u16[0] * *(_DWORD *)((char *)&v48 + v15));
        v19 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findOrInsertKey(
                &v61,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                (unsigned __int64)v18,
                v5->m_vertices.m_size);
        v20 = v61.m_elem[v19].val;
        *(int *)((char *)&v54 + v15) = v20;
        if ( v20 == v17 )
        {
          if ( v5->m_vertices.m_size == (v5->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v5->m_vertices,
              16);
          v21 = &v5->m_vertices.m_data[v5->m_vertices.m_size++];
          v21->m_quad = _mm_movelh_ps((__m128)*v18, (__m128)*((unsigned int *)v18 + 2));
          hkVector4f::setTransformedPos(v21, v9 + 2, v21);
          hkVector4f::setTransformedPos(v21, a, v21);
        }
        v15 += 4i64;
        --v16;
      }
      while ( v16 );
      v22 = v5->m_triangles.m_size;
      v23 = v22 + 1;
      v24 = v5->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v24 >= (signed int)v22 + 1 )
      {
        result.m_enum = 0;
      }
      else
      {
        v25 = 2 * v24;
        if ( v23 < v25 )
          v23 = v25;
        hkArrayUtil::_reserve(
          &result,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v5->m_triangles,
          v23,
          16);
      }
      ++v5->m_triangles.m_size;
      v26 = &v5->m_triangles.m_data[v22];
      v26->m_a = v54;
      v27 = v55;
      v26->m_material = -1;
      v26->m_b = v27;
      v26->m_c = v56;
      v28 = _mm_mul_ps(v9[1].m_scale.m_quad, v9[1].m_scale.m_quad);
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v28, v28, 170))) > 0.0 )
      {
        v29 = 0i64;
        v30 = 3i64;
        do
        {
          v31 = v5->m_vertices.m_size;
          v32 = (unsigned __int64 *)(v9->m_scale.m_quad.m128_u64[1]
                                   + v9[1].m_rotation.m_vec.m_quad.m128_u16[0] * *(_DWORD *)((char *)&v48 + v29));
          v33 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findOrInsertKey(
                  &v60,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  (unsigned __int64)v32,
                  v5->m_vertices.m_size);
          v34 = v60.m_elem[v33].val;
          *(int *)((char *)&v57 + v29) = v34;
          if ( v34 == v31 )
          {
            if ( v5->m_vertices.m_size == (v5->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v5->m_vertices,
                16);
            v35 = &v5->m_vertices.m_data[v5->m_vertices.m_size++];
            v35->m_quad = _mm_movelh_ps((__m128)*v32, (__m128)*((unsigned int *)v32 + 2));
            hkVector4f::setTransformedPos(v35, v9 + 2, v35);
            v35->m_quad = _mm_add_ps(v9[1].m_scale.m_quad, v35->m_quad);
            hkVector4f::setTransformedPos(v35, a, v35);
          }
          v29 += 4i64;
          --v30;
        }
        while ( v30 );
        v36 = v5->m_triangles.m_size;
        v37 = v36 + 7;
        v38 = v5->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v38 >= (signed int)v36 + 7 )
        {
          v52.m_enum = 0;
        }
        else
        {
          v39 = 2 * v38;
          if ( v37 < v39 )
            v37 = v39;
          hkArrayUtil::_reserve(
            &v52,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v5->m_triangles,
            v37,
            16);
        }
        v5->m_triangles.m_size += 7;
        v40 = v59;
        v41 = v57;
        v42 = v55;
        v43 = v54;
        v44 = v58;
        v45 = v56;
        v46 = &v5->m_triangles.m_data[v36];
        v46->m_a = v57;
        v46->m_b = v42;
        v46->m_c = v43;
        v46->m_material = -1;
        v46[1].m_a = v41;
        v46[1].m_b = v44;
        v46[1].m_c = v42;
        v46[1].m_material = -1;
        v46[2].m_a = v44;
        v46[2].m_b = v40;
        v46[2].m_c = v42;
        v46[2].m_material = -1;
        v46[3].m_a = v40;
        v46[3].m_b = v45;
        v46[3].m_c = v42;
        v46[3].m_material = -1;
        v46[4].m_a = v40;
        v46[4].m_b = v43;
        v46[4].m_c = v45;
        v46[4].m_material = -1;
        v46[5].m_a = v40;
        v46[5].m_b = v41;
        v46[5].m_c = v43;
        v46[5].m_material = -1;
        v46[6].m_a = v40;
        v46[6].m_b = v44;
        v46[6].m_c = v41;
        v46[6].m_material = -1;
      }
      v10 = v50 + 1;
      v50 = v10;
    }
    while ( v10 < v51 );
    v4 = v64;
LABEL_38:
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      &v60,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
    _((AMD_HD3D *)&v60);
    v7 = v62 + 144;
    v47 = v63-- == 1;
    v62 += 144i64;
  }
  while ( !v47 );
LABEL_39:
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v61,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v61);
}

// File Line: 218
// RVA: 0xE1F6F0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplayTriangleSubPartsStorage(hkpShapeDisplayBuilder *this, hkpStorageExtendedMeshShape *extendedMeshShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpStorageExtendedMeshShape *v4; // rbx
  hkDisplayGeometry *v5; // rax
  __int64 v6; // rcx
  __int64 v7; // r8
  __int64 v8; // rax
  signed int *v9; // r14
  __int64 v10; // rdx
  __int64 v11; // rdi
  int v12; // esi
  hkQsTransformf *v13; // rbp
  __int64 v14; // rdx
  __int64 v15; // r15
  signed int v16; // eax
  __m128 v17; // xmm2
  signed int v18; // er13
  int v19; // eax
  int v20; // ebx
  int v21; // er9
  int v22; // eax
  signed __int64 v23; // r12
  int v24; // er14
  signed __int64 v25; // rdi
  signed __int64 v26; // rcx
  __int64 v27; // rax
  char *v28; // r13
  hkVector4f *v29; // rbx
  signed int *v30; // r14
  __int64 v31; // rdi
  signed int v32; // ebx
  int v33; // eax
  int v34; // ebx
  int v35; // er9
  int v36; // eax
  int v37; // ebx
  int *v38; // rax
  int v39; // er9
  unsigned __int8 *v40; // r8
  int v41; // er11
  int v42; // er10
  int v43; // ecx
  int v44; // er11
  int v45; // er10
  int v46; // ecx
  int v47; // edx
  int v48; // er9
  int v49; // er8
  int v50; // edx
  signed int v51; // [rsp+30h] [rbp-A8h]
  hkResult v52; // [rsp+38h] [rbp-A0h]
  int v53; // [rsp+3Ch] [rbp-9Ch]
  hkResult result; // [rsp+40h] [rbp-98h]
  hkpStorageExtendedMeshShape::MeshSubpartStorage *v55; // [rsp+48h] [rbp-90h]
  __int64 v56; // [rsp+50h] [rbp-88h]
  __int64 v57; // [rsp+58h] [rbp-80h]
  signed int *v58; // [rsp+60h] [rbp-78h]
  __int64 v59; // [rsp+68h] [rbp-70h]
  __int64 v60; // [rsp+70h] [rbp-68h]
  __int64 v61; // [rsp+78h] [rbp-60h]
  signed int *v62; // [rsp+80h] [rbp-58h]
  hkpStorageExtendedMeshShape *v63; // [rsp+E8h] [rbp+10h]
  hkTransformf *a; // [rsp+F0h] [rbp+18h]

  a = transform;
  v63 = extendedMeshShape;
  v4 = extendedMeshShape;
  v5 = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries);
  v6 = 0i64;
  v7 = (__int64)v5->m_geometry;
  v8 = v4->m_trianglesSubparts.m_size;
  v56 = 0i64;
  v58 = (signed int *)v7;
  v60 = v8;
  if ( v8 > 0 )
  {
    v9 = (signed int *)(v7 + 16);
    v10 = 0i64;
    v62 = (signed int *)(v7 + 16);
    v57 = 0i64;
    while ( 1 )
    {
      v11 = v9[2];
      v12 = *(_DWORD *)(v7 + 24);
      v13 = (hkQsTransformf *)((char *)v4->m_trianglesSubparts.m_data + v10);
      v14 = (__int64)v4->m_meshstorage.m_data[v6];
      v15 = *(signed int *)(v14 + 24);
      v16 = v9[3];
      v17 = _mm_mul_ps(v13[1].m_scale.m_quad, v13[1].m_scale.m_quad);
      v18 = 0;
      v55 = v4->m_meshstorage.m_data[v6];
      v53 = v15;
      if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 0)))
                 + COERCE_FLOAT(_mm_shuffle_ps(v17, v17, 170))) > 0.0 )
        v18 = 1;
      v51 = v18;
      v19 = v16 & 0x3FFFFFFF;
      v20 = v15 * ((v18 != 0) + 1);
      v21 = v20 + v11;
      if ( v19 >= v20 + (signed int)v11 )
      {
        result.m_enum = 0;
      }
      else
      {
        v22 = 2 * v19;
        if ( v21 < v22 )
          v21 = v22;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v9, v21, 16);
        v14 = (__int64)v55;
      }
      v9[2] += v20;
      v23 = *(_QWORD *)v9 + 16 * v11;
      v24 = 0;
      if ( v15 > 0 )
      {
        v25 = 16 * v15 + v23;
        v26 = -16 * v15;
        v27 = -v25;
        v59 = -16 * v15;
        v61 = -v25;
        do
        {
          v28 = (char *)(v27 + v25);
          *(_OWORD *)(v26 + v25) = *(_OWORD *)(v27 + v25 + *(_QWORD *)(v14 + 16));
          v29 = (hkVector4f *)(v23 + 16i64 * v24);
          hkVector4f::setTransformedPos(v29, v13 + 2, (hkVector4f *)(v23 + 16i64 * v24));
          hkVector4f::setTransformedPos(v29, a, v29);
          if ( v51 )
          {
            *(_OWORD *)v25 = *(_OWORD *)&v28[(unsigned __int64)v55->m_vertices.m_data];
            hkVector4f::setTransformedPos((hkVector4f *)v25, v13 + 2, (hkVector4f *)v25);
            *(__m128 *)v25 = _mm_add_ps(*(__m128 *)v25, v13[1].m_scale.m_quad);
            hkVector4f::setTransformedPos((hkVector4f *)v25, a, (hkVector4f *)v25);
          }
          v26 = v59;
          v14 = (__int64)v55;
          v27 = v61;
          ++v24;
          v25 += 16i64;
          --v15;
        }
        while ( v15 );
        v18 = v51;
      }
      v30 = v58;
      v31 = v58[10];
      v32 = 1;
      if ( v18 )
        v32 = 8;
      v33 = v58[11] & 0x3FFFFFFF;
      v34 = v13->m_scale.m_quad.m128_i32[0] * v32;
      v35 = v34 + v31;
      if ( v33 >= v34 + (signed int)v31 )
      {
        v52.m_enum = 0;
      }
      else
      {
        v36 = 2 * v33;
        if ( v35 < v36 )
          v35 = v36;
        hkArrayUtil::_reserve(&v52, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v58 + 8, v35, 16);
      }
      v30[10] += v34;
      v37 = 0;
      v38 = (int *)(*((_QWORD *)v30 + 4) + 16 * v31);
      if ( v13->m_scale.m_quad.m128_i32[0] > 0 )
        break;
LABEL_35:
      v9 = v62;
      v7 = (__int64)v58;
      v4 = v63;
      v6 = v56 + 1;
      v10 = v57 + 144;
      v56 = v6;
      v57 += 144i64;
      if ( v6 >= v60 )
        return;
    }
    while ( 1 )
    {
      v39 = v37 & v13[1].m_rotation.m_vec.m_quad.m128_i8[11];
      v40 = (unsigned __int8 *)(v13[1].m_translation.m_quad.m128_u64[1]
                              + v37 * v13[1].m_rotation.m_vec.m_quad.m128_u16[4]);
      if ( v13[1].m_rotation.m_vec.m_quad.m128_i8[10] == 1 )
      {
        v44 = *v40;
        v45 = v40[v39 + 1];
        v46 = v40[(v39 ^ 1i64) + 1];
        goto LABEL_31;
      }
      if ( v13[1].m_rotation.m_vec.m_quad.m128_i8[10] == 2 )
        break;
      if ( v13[1].m_rotation.m_vec.m_quad.m128_i8[10] == 3 )
      {
        v44 = *(_DWORD *)v40;
        v45 = *(_DWORD *)&v40[4 * v39 + 4];
        v46 = *(_DWORD *)&v40[4 * (v39 ^ 1i64) + 4];
LABEL_31:
        v41 = v12 + v44;
        v42 = v12 + v45;
        v43 = v12 + v46;
        goto LABEL_32;
      }
      v41 = 0;
      v42 = 0;
      v43 = 0;
LABEL_32:
      *v38 = v41;
      v38[1] = v42;
      v38[2] = v43;
      v38[3] = -1;
      if ( v18 )
      {
        v47 = v53;
        v38[5] = v42;
        v38[6] = v41;
        v38[7] = -1;
        v48 = v41 + v47;
        v49 = v42 + v47;
        v38[4] = v41 + v47;
        v38[8] = v41 + v47;
        v38[9] = v42 + v47;
        v38[10] = v42;
        v38[11] = -1;
        v38[12] = v42 + v47;
        v38[14] = v42;
        v38[15] = -1;
        v50 = v43 + v47;
        v38[13] = v50;
        v38[16] = v50;
        v38[17] = v43;
        v38[18] = v42;
        v38[19] = -1;
        v38[20] = v50;
        v38[21] = v41;
        v38[22] = v43;
        v38[23] = -1;
        v38[24] = v50;
        v38[25] = v48;
        v38[26] = v41;
        v38[27] = -1;
        v38[28] = v50;
        v38[29] = v49;
        v38[30] = v48;
        v38[31] = -1;
        v38 += 28;
      }
      ++v37;
      v38 += 4;
      if ( v37 >= v13->m_scale.m_quad.m128_i32[0] )
        goto LABEL_35;
    }
    v44 = *(unsigned __int16 *)v40;
    v45 = *(unsigned __int16 *)&v40[2 * v39 + 2];
    v46 = *(unsigned __int16 *)&v40[2 * (v39 ^ 1i64) + 2];
    goto LABEL_31;
  }
}

// File Line: 328
// RVA: 0xE1FB70
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplayShapeSubParts(hkpShapeDisplayBuilder *this, hkpExtendedMeshShape *extendedMeshShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  __int64 v4; // r12
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v5; // rbp
  hkTransformf *v6; // rbx
  hkpExtendedMeshShape *v7; // r13
  hkpShapeDisplayBuilder *v8; // r15
  __int64 v9; // r14
  hkpExtendedMeshShape::ShapesSubpart *v10; // rdi
  __int64 v11; // rsi
  __int64 i; // rbx
  hkRotationf v13; // [rsp+30h] [rbp-A8h]
  hkVector4f v14; // [rsp+60h] [rbp-78h]
  hkTransformf transforma; // [rsp+70h] [rbp-68h]
  hkTransformf *v16; // [rsp+F0h] [rbp+18h]

  v16 = transform;
  v4 = extendedMeshShape->m_shapesSubparts.m_size;
  v5 = displayGeometries;
  v6 = transform;
  v7 = extendedMeshShape;
  v8 = this;
  if ( v4 > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = &v7->m_shapesSubparts.m_data[v9];
      hkRotationf::set(&v13, &v10->m_rotation);
      v14.m_quad = (__m128)v10->m_translation;
      hkTransformf::setMul(&transforma, v6, (hkTransformf *)&v13);
      v11 = v10->m_childShapes.m_size;
      for ( i = 0i64; i < v11; ++i )
        hkpShapeDisplayBuilder::buildShapeDisplay(
          v8,
          (hkpShape *)&v10->m_childShapes.m_data[i].m_pntr->vfptr,
          &transforma,
          v5,
          0i64);
      v6 = v16;
      ++v9;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 352
// RVA: 0xE1DB50
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_ExtendedMeshShape(hkpShapeDisplayBuilder *this, hkpExtendedMeshShape *extendedMeshShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpShapeDisplayBuilder *v4; // rbp
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v5; // rdi
  hkTransformf *v6; // rsi
  hkpStorageExtendedMeshShape *v7; // rbx
  __int64 v8; // rax
  hkpShapeContainer *v9; // rdx

  v4 = this;
  v5 = displayGeometries;
  v6 = transform;
  v7 = (hkpStorageExtendedMeshShape *)extendedMeshShape;
  v8 = ((__int64 (*)(void))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)();
  if ( (hkClass *)(*(__int64 (__fastcall **)(__int64, hkpStorageExtendedMeshShape *))(*(_QWORD *)v8 + 40i64))(v8, v7) == &hkpStorageExtendedMeshShapeClass )
  {
    hkpShapeDisplayBuilder::buildShapeDisplayTriangleSubPartsStorage(v4, v7, v6, v5);
    hkpShapeDisplayBuilder::buildShapeDisplayShapeSubParts(v4, (hkpExtendedMeshShape *)&v7->vfptr, v6, v5);
  }
  else
  {
    if ( v7 )
      v9 = (hkpShapeContainer *)&v7->vfptr;
    else
      v9 = 0i64;
    hkpShapeDisplayBuilder::buildShapeDisplay_ShapeContainer(v4, v9, v6, v5);
  }
}

// File Line: 377
// RVA: 0xE1DA00
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_BvCompressedMeshShape(hkpShapeDisplayBuilder *this, hkpBvCompressedMeshShape *bvCompressedMeshShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries, hkVector4f *scale)
{
  hkpBvCompressedMeshShape *v5; // rbx
  hkTransformf *v6; // rdi
  hkGeometry *v7; // rsi
  hkGeometry geometryOut; // [rsp+20h] [rbp-51h]
  hkQsTransformf qst; // [rsp+50h] [rbp-21h]
  hkMatrix4f transforma; // [rsp+80h] [rbp+Fh]

  v5 = bvCompressedMeshShape;
  v6 = transform;
  v7 = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries)->m_geometry;
  *(_DWORD *)&geometryOut.m_memSizeAndFlags = 0x1FFFF;
  geometryOut.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
  geometryOut.m_vertices.m_data = 0i64;
  geometryOut.m_vertices.m_size = 0;
  geometryOut.m_vertices.m_capacityAndFlags = 2147483648;
  geometryOut.m_triangles.m_data = 0i64;
  geometryOut.m_triangles.m_size = 0;
  geometryOut.m_triangles.m_capacityAndFlags = 2147483648;
  hkpBvCompressedMeshShape::convertToGeometry(v5, &geometryOut, 0i64, 0i64);
  hkQsTransformf::setFromTransformNoScale(&qst, v6);
  if ( scale )
    qst.m_scale = (hkVector4f)scale->m_quad;
  hkMatrix4f::set(&transforma, &qst);
  hkGeometryUtils::transformGeometry(&transforma, &geometryOut);
  hkGeometryUtils::appendGeometry(&geometryOut, v7);
  geometryOut.m_triangles.m_size = 0;
  if ( geometryOut.m_triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      geometryOut.m_triangles.m_data,
      16 * geometryOut.m_triangles.m_capacityAndFlags);
  geometryOut.m_triangles.m_data = 0i64;
  geometryOut.m_triangles.m_capacityAndFlags = 2147483648;
  geometryOut.m_vertices.m_size = 0;
  if ( geometryOut.m_vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      geometryOut.m_vertices.m_data,
      16 * geometryOut.m_vertices.m_capacityAndFlags);
}

// File Line: 407
// RVA: 0xE1D250
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_CompressedMeshShape(hkpShapeDisplayBuilder *this, hkpCompressedMeshShape *compressedMeshShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpCompressedMeshShape *v4; // rsi
  hkTransformf *v5; // r12
  hkDisplayGeometry *v6; // rax
  __int64 v7; // rbx
  __int64 v8; // r14
  __int64 v9; // rdi
  _DWORD *v10; // r13
  int v11; // eax
  int v12; // er9
  int v13; // eax
  signed __int64 v14; // rdi
  __int64 v15; // r15
  _DWORD *v16; // rbx
  __int64 v17; // r14
  hkVector4f *v18; // rcx
  unsigned __int16 *v19; // rdx
  unsigned __int16 v20; // ax
  hkQsTransformf *v21; // rdx
  int v22; // esi
  __int64 v23; // rax
  int v24; // ecx
  signed int *v25; // r15
  unsigned __int64 v26; // rax
  hkpCompressedMeshShape::Chunk *v27; // rdx
  hkResultEnum v28; // edi
  __int64 v29; // rsi
  unsigned __int64 v30; // r13
  int v31; // eax
  hkpCompressedMeshShape::Chunk *v32; // rbx
  int v33; // eax
  int v34; // er14
  int v35; // er9
  int v36; // eax
  hkVector4f *v37; // rsi
  __int64 v38; // r15
  __int64 v39; // r14
  unsigned __int16 v40; // ax
  int v41; // eax
  __int64 v42; // r14
  int v43; // er9
  int v44; // ecx
  int v45; // esi
  int v46; // ecx
  int v47; // er11
  __int64 v48; // r12
  signed __int64 v49; // r10
  int v50; // er14
  signed __int64 v51; // rax
  signed __int64 v52; // r10
  __int64 i; // r15
  int v54; // esi
  char v55; // r8
  __int64 v56; // r9
  int v57; // er8
  signed __int64 v58; // rdx
  signed __int64 v59; // r10
  signed __int64 v60; // rdx
  int v61; // ecx
  bool v62; // zf
  int v63; // er12
  _DWORD *v64; // rbx
  signed int *v65; // r15
  int v66; // esi
  __int64 v67; // r14
  __int64 v68; // rbx
  int v69; // er9
  int v70; // eax
  int v71; // eax
  signed __int64 v72; // rdi
  __int64 v73; // rbx
  __int64 v74; // rbx
  __int64 v75; // rdi
  int v76; // er9
  int v77; // eax
  int v78; // eax
  __int64 v79; // r9
  signed __int64 v80; // rdx
  __int64 v81; // r8
  hkResult result; // [rsp+30h] [rbp-69h]
  hkResult v83; // [rsp+34h] [rbp-65h]
  hkResult v84; // [rsp+38h] [rbp-61h]
  _DWORD *v85; // [rsp+40h] [rbp-59h]
  int v86; // [rsp+48h] [rbp-51h]
  _DWORD *v87; // [rsp+50h] [rbp-49h]
  hkVector4f b; // [rsp+60h] [rbp-39h]
  hkQsTransformf a; // [rsp+70h] [rbp-29h]
  hkVector4f v90; // [rsp+A0h] [rbp+7h]
  hkVector4f v91; // [rsp+B0h] [rbp+17h]
  hkpCompressedMeshShape *v92; // [rsp+108h] [rbp+6Fh]
  hkTransformf *v93; // [rsp+110h] [rbp+77h]

  v93 = transform;
  v92 = compressedMeshShape;
  v4 = compressedMeshShape;
  v5 = transform;
  v6 = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries);
  v7 = v4->m_bigTriangles.m_size;
  v8 = (__int64)v6->m_geometry;
  v9 = *(signed int *)(v8 + 40);
  v10 = (_DWORD *)(v8 + 32);
  v11 = *(_DWORD *)(v8 + 44) & 0x3FFFFFFF;
  v12 = v9 + v7;
  v85 = (_DWORD *)v8;
  v87 = (_DWORD *)(v8 + 32);
  if ( v11 < (signed int)v9 + (signed int)v7 )
  {
    v13 = 2 * v11;
    if ( v12 < v13 )
      v12 = v13;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      (void *)(v8 + 32),
      v12,
      16);
  }
  *(_DWORD *)(v8 + 40) += v7;
  v14 = *(_QWORD *)v10 + 16 * v9;
  v15 = v7;
  if ( (signed int)v7 > 0 )
  {
    v16 = (_DWORD *)(v8 + 16);
    v17 = 0i64;
    do
    {
      v18 = v92->m_bigVertices.m_data;
      v19 = &v92->m_bigTriangles.m_data[v17].m_a;
      b.m_quad = (__m128)v18[*v19];
      v90.m_quad = (__m128)v18[v19[1]];
      v91.m_quad = (__m128)v18[v19[2]];
      v20 = v19[7];
      if ( v20 != -1 )
      {
        v21 = v92->m_transforms.m_data;
        a.m_translation = v21[v20].m_translation;
        a.m_rotation = v21[v20].m_rotation;
        a.m_scale = v21[v20].m_scale;
        hkVector4f::setTransformedPos(&b, &a, &b);
        hkVector4f::setTransformedPos(&v90, &a, &v90);
        hkVector4f::setTransformedPos(&v91, &a, &v91);
      }
      hkVector4f::setTransformedPos(&b, v5, &b);
      hkVector4f::setTransformedPos(&v90, v5, &v90);
      hkVector4f::setTransformedPos(&v91, v5, &v91);
      v22 = v85[6];
      if ( v16[2] == (v16[3] & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
      *(hkVector4f *)(*(_QWORD *)v16 + 16i64 * (signed int)v16[2]++) = (hkVector4f)b.m_quad;
      if ( v16[2] == (v16[3] & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
      *(hkVector4f *)(*(_QWORD *)v16 + 16i64 * (signed int)v16[2]++) = (hkVector4f)v90.m_quad;
      if ( v16[2] == (v16[3] & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v16, 16);
      v14 += 16i64;
      ++v17;
      *(hkVector4f *)(*(_QWORD *)v16 + 16i64 * (signed int)v16[2]++) = (hkVector4f)v91.m_quad;
      *(_DWORD *)(v14 - 12) = v22 + 1;
      *(_DWORD *)(v14 - 16) = v22;
      *(_DWORD *)(v14 - 8) = v22 + 2;
      --v15;
    }
    while ( v15 );
    v10 = v87;
    v4 = v92;
    v8 = (__int64)v85;
  }
  v23 = v4->m_chunks.m_size;
  v24 = 0;
  v86 = 0;
  v87 = (_DWORD *)v23;
  if ( v23 > 0 )
  {
    v25 = (signed int *)(v8 + 16);
    v26 = 0i64;
    b.m_quad.m128_u64[0] = v8 + 16;
    v90.m_quad.m128_u64[0] = 0i64;
    while ( 1 )
    {
      v27 = v4->m_chunks.m_data;
      v28 = *(_DWORD *)(v8 + 24);
      v29 = v25[2];
      v30 = (unsigned __int64)v27 + v26;
      v84.m_enum = *(_DWORD *)(v8 + 24);
      v31 = *(unsigned __int16 *)((char *)&v27->m_reference + v26);
      if ( v31 != 0xFFFF )
        v24 = v31;
      v32 = &v27[v24];
      v33 = v25[3] & 0x3FFFFFFF;
      v34 = v32->m_vertices.m_size / 3;
      v35 = v29 + v34;
      if ( v33 >= (signed int)v29 + v34 )
      {
        v83.m_enum = 0;
      }
      else
      {
        v36 = 2 * v33;
        if ( v35 < v36 )
          v35 = v36;
        hkArrayUtil::_reserve(&v83, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v25, v35, 16);
      }
      v25[2] += v34;
      v37 = (hkVector4f *)(*(_QWORD *)v25 + 16 * v29);
      v38 = v34;
      if ( v34 > 0 )
      {
        v39 = 0i64;
        do
        {
          v37->m_quad = _mm_add_ps(
                          _mm_mul_ps(
                            _mm_cvtepi32_ps(
                              _mm_unpacklo_epi32(
                                _mm_unpacklo_epi32(
                                  _mm_cvtsi32_si128(v32->m_vertices.m_data[v39]),
                                  _mm_cvtsi32_si128(v32->m_vertices.m_data[v39 + 2])),
                                _mm_unpacklo_epi32(
                                  _mm_cvtsi32_si128(v32->m_vertices.m_data[v39 + 1]),
                                  _mm_cvtsi32_si128(0)))),
                            _mm_shuffle_ps((__m128)LODWORD(v92->m_error), (__m128)LODWORD(v92->m_error), 0)),
                          v32->m_offset.m_quad);
          v40 = *(_WORD *)(v30 + 86);
          if ( v40 != -1 )
            hkVector4f::setTransformedPos(v37, &v92->m_transforms.m_data[v40], v37);
          hkVector4f::setTransformedPos(v37, v5, v37);
          ++v37;
          v39 += 3i64;
          --v38;
        }
        while ( v38 );
        v28 = v84.m_enum;
      }
      v41 = hkpCompressedMeshShape::Chunk::getNumTriangles(v32);
      v42 = (signed int)v85[10];
      v10 = v85 + 8;
      v43 = v42 + v41;
      v44 = v85[11] & 0x3FFFFFFF;
      v45 = v41;
      if ( v44 >= (signed int)v42 + v41 )
      {
        v47 = 0;
        result.m_enum = 0;
      }
      else
      {
        v46 = 2 * v44;
        if ( v43 < v46 )
          v43 = v46;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v85 + 8, v43, 16);
        v47 = 0;
      }
      v10[2] += v45;
      v48 = v32->m_stripLengths.m_size;
      v49 = 16 * v42;
      v50 = 0;
      v51 = 0i64;
      v52 = *(_QWORD *)v10 + v49;
      for ( i = 0i64; i < v48; v47 = 0 )
      {
        v54 = v32->m_stripLengths.m_data[i] - 2;
        if ( v54 > 0 )
        {
          v50 += v54;
          do
          {
            v55 = v47++;
            v52 += 16i64;
            v56 = v55 & 1;
            *(_DWORD *)(v52 - 16) = v28 + v32->m_indices.m_data[v51];
            v57 = v32->m_indices.m_data[v56 + 1 + v51];
            v58 = v51++;
            *(_DWORD *)(v52 - 12) = v28 + v57;
            *(_DWORD *)(v52 - 8) = v28 + v32->m_indices.m_data[v58 - v56 + 2];
          }
          while ( v47 < v54 );
        }
        ++i;
        v50 += 2;
        v51 += 2i64;
      }
      if ( v50 < v32->m_indices.m_size - 2 )
      {
        v59 = v52 + 8;
        v60 = v51;
        do
        {
          v50 += 3;
          v59 += 16i64;
          v61 = v32->m_indices.m_data[v60];
          v60 += 3i64;
          *(_DWORD *)(v59 - 24) = v28 + v61;
          *(_DWORD *)(v59 - 20) = v28 + v32->m_indices.m_data[v60 - 2];
          *(_DWORD *)(v59 - 16) = v28 + v32->m_indices.m_data[v60 - 1];
        }
        while ( v50 < v32->m_indices.m_size - 2 );
      }
      v5 = v93;
      v4 = v92;
      v25 = (signed int *)b.m_quad.m128_u64[0];
      v24 = v86 + 1;
      v26 = v90.m_quad.m128_u64[0] + 96;
      v62 = v87 == (_DWORD *)1;
      v87 = (_DWORD *)((char *)v87 - 1);
      ++v86;
      v90.m_quad.m128_u64[0] += 96i64;
      if ( v62 )
        break;
      v8 = (__int64)v85;
    }
  }
  v63 = 0;
  v83.m_enum = v4->m_convexPieces.m_size;
  if ( (signed int)v83.m_enum > 0 )
  {
    v64 = v85;
    v65 = v85 + 4;
    b.m_quad.m128_u64[0] = (unsigned __int64)(v85 + 4);
    do
    {
      a.m_translation.m_quad.m128_i32[2] = 0x1FFFF;
      a.m_translation.m_quad.m128_u64[0] = (unsigned __int64)&hkGeometry::`vftable';
      a.m_rotation.m_vec.m_quad.m128_u64[0] = 0i64;
      a.m_rotation.m_vec.m_quad.m128_u64[1] = 0x8000000000000000i64;
      a.m_scale.m_quad.m128_u64[0] = 0i64;
      a.m_scale.m_quad.m128_u64[1] = 0x8000000000000000i64;
      hkpCompressedMeshShapeBuilder::convexPieceToGeometry(v4, v63, (hkGeometry *)&a);
      v66 = v64[6];
      v67 = a.m_rotation.m_vec.m_quad.m128_u32[2];
      v68 = v65[2];
      v69 = a.m_rotation.m_vec.m_quad.m128_i32[2] + v68;
      v70 = v65[3] & 0x3FFFFFFF;
      if ( v70 >= a.m_rotation.m_vec.m_quad.m128_i32[2] + (signed int)v68 )
      {
        result.m_enum = 0;
      }
      else
      {
        v71 = 2 * v70;
        if ( v69 < v71 )
          v69 = v71;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v65, v69, 16);
      }
      v65[2] += v67;
      v72 = *(_QWORD *)v65 + 16 * v68;
      if ( (signed int)v67 > 0 )
      {
        v73 = 0i64;
        do
        {
          hkVector4f::setTransformedPos(
            (hkVector4f *)(v73 + v72),
            v93,
            (hkVector4f *)(v73 + a.m_rotation.m_vec.m_quad.m128_u64[0]));
          v73 += 16i64;
          --v67;
        }
        while ( v67 );
        v65 = (signed int *)b.m_quad.m128_u64[0];
      }
      v74 = a.m_scale.m_quad.m128_i32[2];
      v75 = (signed int)v10[2];
      v76 = a.m_scale.m_quad.m128_i32[2] + v75;
      v77 = v10[3] & 0x3FFFFFFF;
      if ( v77 >= a.m_scale.m_quad.m128_i32[2] + (signed int)v75 )
      {
        v84.m_enum = 0;
      }
      else
      {
        v78 = 2 * v77;
        if ( v76 < v78 )
          v76 = v78;
        hkArrayUtil::_reserve(&v84, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, v76, 16);
      }
      v10[2] += v74;
      v79 = v74;
      v80 = *(_QWORD *)v10 + 16 * v75;
      if ( (signed int)v74 > 0 )
      {
        v81 = 0i64;
        do
        {
          v80 += 16i64;
          v81 += 16i64;
          *(_DWORD *)(v80 - 16) = v66 + *(_DWORD *)(a.m_scale.m_quad.m128_u64[0] + v81 - 16);
          *(_DWORD *)(v80 - 12) = v66 + *(_DWORD *)(a.m_scale.m_quad.m128_u64[0] + v81 - 12);
          *(_DWORD *)(v80 - 8) = v66 + *(_DWORD *)(a.m_scale.m_quad.m128_u64[0] + v81 - 8);
          --v79;
        }
        while ( v79 );
      }
      a.m_scale.m_quad.m128_i32[2] = 0;
      if ( a.m_scale.m_quad.m128_i32[3] >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          a.m_scale.m_quad.m128_u64[0],
          (unsigned int)(16 * a.m_scale.m_quad.m128_i32[3]),
          v79);
      a.m_scale.m_quad.m128_u64[0] = 0i64;
      a.m_scale.m_quad.m128_i32[3] = 2147483648;
      a.m_rotation.m_vec.m_quad.m128_i32[2] = 0;
      if ( a.m_rotation.m_vec.m_quad.m128_i32[3] >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          a.m_rotation.m_vec.m_quad.m128_u64[0],
          (unsigned int)(16 * a.m_rotation.m_vec.m_quad.m128_i32[3]),
          v79);
      v4 = v92;
      v64 = v85;
      ++v63;
    }
    while ( v63 < v83.m_enum );
  }
}

// File Line: 545
// RVA: 0xE1DBF0
void __usercall hkpShapeDisplayBuilder::buildShapeDisplay_SampledHeightField(hkpShapeDisplayBuilder *this@<rcx>, hkpSampledHeightFieldShape *heightField@<rdx>, hkTransformf *transform@<r8>, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries@<r9>, __m128 a5@<xmm0>)
{
  hkpSampledHeightFieldShape *v5; // r15
  hkTransformf *v6; // r14
  hkDisplayGeometry *v7; // rax
  __m128 v8; // xmm7
  hkGeometry *v9; // rsi
  int v10; // edi
  int v11; // er13
  int v12; // eax
  int v13; // er9
  int v14; // eax
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *v15; // rdi
  signed __int64 v16; // rbp
  __int64 v17; // rsi
  int v18; // ebx
  int v19; // er9
  int v20; // eax
  int v21; // eax
  signed __int64 v22; // rbx
  signed int v23; // edi
  int v24; // eax
  signed int i; // esi
  hkVector4f *v26; // rcx
  int j; // ebp
  int v28; // eax
  int v29; // esi
  int v30; // edi
  int v31; // er12
  int v32; // er14
  int v33; // er13
  int v34; // er9
  int v35; // er8
  bool v36; // zf
  signed __int64 v37; // rcx
  int v38; // edx
  int v39; // [rsp+30h] [rbp-68h]
  hkResult v40; // [rsp+34h] [rbp-64h]
  hkVector4f b; // [rsp+40h] [rbp-58h]
  hkResult result; // [rsp+A8h] [rbp+10h]

  v5 = heightField;
  v6 = transform;
  v7 = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries);
  v8 = v5->m_intToFloatScale.m_quad;
  v9 = v7->m_geometry;
  v10 = v5->m_zRes * v5->m_xRes;
  v11 = v9->m_vertices.m_size;
  v12 = v9->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  v39 = v9->m_vertices.m_size;
  v13 = v11 + v10;
  if ( v12 >= v11 + v10 )
  {
    result.m_enum = 0;
  }
  else
  {
    v14 = 2 * v12;
    if ( v13 < v14 )
      v13 = v14;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v9->m_vertices,
      v13,
      16);
  }
  v9->m_vertices.m_size += v10;
  v15 = &v9->m_triangles;
  v16 = (signed __int64)&v9->m_vertices.m_data[v11];
  v17 = v9->m_triangles.m_size;
  v18 = (v5->m_xRes - 1) * (2 * v5->m_zRes - 2);
  v19 = v17 + v18;
  v20 = v15->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < (signed int)v17 + v18 )
  {
    v21 = 2 * v20;
    if ( v19 < v21 )
      v19 = v21;
    hkArrayUtil::_reserve(&v40, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v15, v19, 16);
  }
  v15->m_size += v18;
  v22 = (signed __int64)&v15->m_data[v17];
  v23 = 0;
  if ( v5->m_xRes > 0 )
  {
    v24 = v5->m_zRes;
    do
    {
      for ( i = 0; i < v24; ++i )
      {
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v5->vfptr[10].__vecDelDtor)(
          v5,
          (unsigned int)v23,
          (unsigned int)i);
        a5 = _mm_unpacklo_ps(a5, (__m128)0i64);
        v26 = (hkVector4f *)(v16 + 16i64 * (i + v5->m_zRes * v23));
        b.m_quad = _mm_mul_ps(
                     _mm_unpacklo_ps(
                       _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v23), (__m128)COERCE_UNSIGNED_INT((float)i)),
                       a5),
                     v8);
        hkVector4f::setTransformedPos(v26, v6, &b);
        v24 = v5->m_zRes;
      }
      ++v23;
    }
    while ( v23 < v5->m_xRes );
  }
  for ( j = 0; j < v5->m_xRes - 1; ++j )
  {
    v28 = v5->m_zRes;
    v29 = 0;
    v30 = v28 - 1;
    if ( v28 - 1 > 0 )
    {
      v31 = 0;
      do
      {
        v32 = v11 + j * v28;
        v33 = v28 + v32;
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkResult *))v5->vfptr[10].__first_virtual_table_function__)(
          v5,
          &result);
        v34 = v31 + 2 * j * v30;
        v35 = v29 + v33;
        v36 = LOBYTE(result.m_enum) == 0;
        *(_DWORD *)(v22 + 16i64 * v34 + 12) = -1;
        if ( v36 )
        {
          *(_DWORD *)(v22 + 16i64 * v34 + 8) = v35;
          *(_DWORD *)(v22 + 16i64 * v34) = v32 + v29;
          v38 = v32 + v29 + 1;
          *(_DWORD *)(v22 + 16i64 * v34 + 4) = v38;
          v37 = 2i64 * (v34 + 1);
          *(_DWORD *)(v22 + 16i64 * (v34 + 1)) = v38;
        }
        else
        {
          *(_DWORD *)(v22 + 16i64 * v34) = v32 + v29;
          *(_DWORD *)(v22 + 16i64 * v34 + 8) = v35 + 1;
          *(_DWORD *)(v22 + 16i64 * v34 + 4) = v32 + v29 + 1;
          v37 = 2i64 * (v34 + 1);
          *(_DWORD *)(v22 + 16i64 * (v34 + 1)) = v32 + v29;
        }
        *(_DWORD *)(v22 + 8 * v37 + 4) = v35 + 1;
        v11 = v39;
        *(_DWORD *)(v22 + 8 * v37 + 12) = -1;
        *(_DWORD *)(v22 + 8 * v37 + 8) = v35;
        v28 = v5->m_zRes;
        ++v29;
        v31 += 2;
        v30 = v28 - 1;
      }
      while ( v29 < v28 - 1 );
    }
  }
}

// File Line: 591
// RVA: 0xE1EAC0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_ShapeUnregistered(hkpShapeDisplayBuilder *this, hkpShape *shape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpShape *v4; // rbx
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v5; // rdi
  __int64 v6; // r8
  signed int v7; // esi
  __m128 v8; // xmm6
  __m128 v9; // xmm9
  __m128 v10; // xmm8
  __m128 v11; // xmm11
  __m128 v12; // xmm9
  __m128 v13; // xmm10
  __m128 v14; // xmm12
  _QWORD **v15; // rax
  hkDisplayBox *v16; // rax
  hkDisplayGeometry *v17; // rax
  hkDisplayGeometry *v18; // rbx
  __m128 *v19; // rcx
  __m128 *v20; // rax
  __m128 v21; // xmm4
  signed int v22; // esi
  _QWORD **v23; // rax
  hkDisplayBox *v24; // rax
  hkDisplayGeometry *v25; // rax
  hkDisplayGeometry *v26; // rbx
  __m128 *v27; // rcx
  __m128 *v28; // rax
  __m128 v29; // xmm4
  signed int v30; // esi
  __m128 v31; // xmm0
  __m128 v32; // xmm9
  _QWORD **v33; // rax
  hkDisplayBox *v34; // rax
  hkDisplayGeometry *v35; // rax
  hkDisplayGeometry *v36; // rbx
  __m128 *v37; // rcx
  __m128 *v38; // rax
  __m128 v39; // xmm3
  __m128 v40; // [rsp+20h] [rbp-D8h]
  hkVector4f halfExtents; // [rsp+30h] [rbp-C8h]
  hkErrStream v42; // [rsp+40h] [rbp-B8h]
  __m128 v43; // [rsp+60h] [rbp-98h]
  __m128 v44; // [rsp+70h] [rbp-88h]
  __m128 v45; // [rsp+88h] [rbp-70h]
  char buf; // [rsp+98h] [rbp-60h]
  __int64 v47; // [rsp+A0h] [rbp-58h]

  v4 = shape;
  v5 = displayGeometries;
  hkErrStream::hkErrStream(&v42, &v47, 512);
  hkOstream::operator<<((hkOstream *)&v42.vfptr, "Shape type unsupported. Using current aabb for display geometry");
  hkError::messageReport(-1, &buf, "VisualDebugger\\Viewer\\hkpShapeDisplayBuilder.cpp", 593);
  hkOstream::~hkOstream((hkOstream *)&v42.vfptr);
  ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, char *))v4->vfptr[2].__vecDelDtor)(
    v4,
    &::transform,
    v6,
    &v44.m128_i8[8]);
  v7 = 0;
  v8 = _mm_sub_ps(v45, *(__m128 *)((char *)&v44 + 8));
  v9 = _mm_mul_ps(v8, (__m128)xmmword_141A711B0);
  v10 = _mm_shuffle_ps(v9, v9, 0);
  v11 = _mm_shuffle_ps(v9, v9, 85);
  v12 = _mm_shuffle_ps(v9, v9, 170);
  v13 = _mm_mul_ps(_mm_min_ps(v12, _mm_min_ps(v11, v10)), (__m128)xmmword_141A711F0);
  v14 = _mm_unpacklo_ps(v13, v13);
  halfExtents.m_quad = _mm_movelh_ps(_mm_unpacklo_ps(_mm_add_ps(v13, v10), v13), v14);
  do
  {
    v15 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (hkDisplayBox *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v15[11] + 8i64))(v15[11], 128i64);
    if ( v16 )
    {
      hkDisplayBox::hkDisplayBox(v16, &halfExtents);
      v18 = v17;
    }
    else
    {
      v18 = 0i64;
    }
    if ( v7 & 2 )
    {
      v19 = &v44;
      v44 = _mm_shuffle_ps(v8, v8, 170);
    }
    else
    {
      _mm_store_si128((__m128i *)&v43, (__m128i)0i64);
      v19 = &v43;
    }
    if ( v7 & 1 )
    {
      v20 = &v40;
      v40 = _mm_shuffle_ps(v8, v8, 85);
    }
    else
    {
      _mm_store_si128((__m128i *)&v42, (__m128i)0i64);
      v20 = (__m128 *)&v42;
    }
    v21 = _mm_add_ps(
            _mm_movelh_ps(_mm_unpacklo_ps(v10, *v20), _mm_unpacklo_ps(*v19, (__m128)0i64)),
            *(__m128 *)((char *)&v44 + 8));
    v18->m_transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
    v18->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    v18->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    v18->m_transform.m_translation.m_quad = v21;
    if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
    ++v7;
    v5->m_data[v5->m_size++] = v18;
  }
  while ( v7 < 4 );
  v22 = 0;
  halfExtents.m_quad = _mm_movelh_ps(_mm_unpacklo_ps(v13, _mm_add_ps(v13, v11)), v14);
  do
  {
    v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v24 = (hkDisplayBox *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v23[11] + 8i64))(v23[11], 128i64);
    if ( v24 )
    {
      hkDisplayBox::hkDisplayBox(v24, &halfExtents);
      v26 = v25;
    }
    else
    {
      v26 = 0i64;
    }
    if ( v22 & 2 )
    {
      v27 = (__m128 *)&v42;
      *(__m128 *)&v42.vfptr = _mm_shuffle_ps(v8, v8, 170);
    }
    else
    {
      _mm_store_si128((__m128i *)&v40, (__m128i)0i64);
      v27 = &v40;
    }
    if ( v22 & 1 )
    {
      v28 = &v43;
      v43 = _mm_shuffle_ps(v8, v8, 0);
    }
    else
    {
      _mm_store_si128((__m128i *)&v44, (__m128i)0i64);
      v28 = &v44;
    }
    v29 = _mm_add_ps(
            _mm_movelh_ps(_mm_unpacklo_ps(*v28, v11), _mm_unpacklo_ps(*v27, (__m128)0i64)),
            *(__m128 *)((char *)&v44 + 8));
    v26->m_transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
    v26->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    v26->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    v26->m_transform.m_translation.m_quad = v29;
    if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
    ++v22;
    v5->m_data[v5->m_size++] = v26;
  }
  while ( v22 < 4 );
  v30 = 0;
  v31 = _mm_add_ps(v13, v12);
  v32 = _mm_unpacklo_ps(v12, (__m128)0i64);
  halfExtents.m_quad = _mm_movelh_ps(v14, _mm_unpacklo_ps(v31, v13));
  do
  {
    v33 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v34 = (hkDisplayBox *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v33[11] + 8i64))(v33[11], 128i64);
    if ( v34 )
    {
      hkDisplayBox::hkDisplayBox(v34, &halfExtents);
      v36 = v35;
    }
    else
    {
      v36 = 0i64;
    }
    if ( v30 & 2 )
    {
      v37 = (__m128 *)&v42;
      *(__m128 *)&v42.vfptr = _mm_shuffle_ps(v8, v8, 85);
    }
    else
    {
      _mm_store_si128((__m128i *)&v40, (__m128i)0i64);
      v37 = &v40;
    }
    if ( v30 & 1 )
    {
      v38 = &v43;
      v43 = _mm_shuffle_ps(v8, v8, 0);
    }
    else
    {
      _mm_store_si128((__m128i *)&v44, (__m128i)0i64);
      v38 = &v44;
    }
    v39 = _mm_add_ps(_mm_movelh_ps(_mm_unpacklo_ps(*v38, *v37), v32), *(__m128 *)((char *)&v44 + 8));
    v36->m_transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
    v36->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    v36->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    v36->m_transform.m_translation.m_quad = v39;
    if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
    ++v30;
    v5->m_data[v5->m_size++] = v36;
  }
  while ( v30 < 4 );
}

// File Line: 663
// RVA: 0xE1DEB0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_ShapeContainer(hkpShapeDisplayBuilder *this, hkpShapeContainer *shapeContainer, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpShapeDisplayBuilder *v4; // r14
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v5; // rsi
  hkTransformf *v6; // rbp
  hkpShapeContainer *v7; // rbx
  unsigned int i; // edi
  hkpShape *v9; // rax
  char v10; // [rsp+30h] [rbp-218h]

  v4 = this;
  v5 = displayGeometries;
  v6 = transform;
  v7 = shapeContainer;
  for ( i = shapeContainer->vfptr->getFirstKey(shapeContainer); i != -1; i = v7->vfptr->getNextKey(v7, i) )
  {
    v9 = v7->vfptr->getChildShape(v7, i, (char (*)[512])&v10);
    hkpShapeDisplayBuilder::buildShapeDisplay(v4, v9, v6, v5, 0i64);
  }
}

// File Line: 677
// RVA: 0xE1C4C0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_Sphere(hkpShapeDisplayBuilder *this, hkpSphereShape *sphereShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries, hkVector4f *scale)
{
  float v5; // xmm2_4
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v6; // rbx
  hkTransformf *v7; // rsi
  hkpShapeDisplayBuilder *v8; // rdi
  _QWORD **v9; // rax
  hkDisplaySphere *v10; // rax
  hkDisplayGeometry *v11; // rax
  hkDisplayGeometry *v12; // rdi
  hkSphere sphere; // [rsp+20h] [rbp-18h]

  v5 = sphereShape->m_radius;
  v6 = displayGeometries;
  v7 = transform;
  v8 = this;
  if ( scale )
    v5 = v5 * COERCE_FLOAT((unsigned int)(2 * scale->m_quad.m128_i32[0]) >> 1);
  sphere.m_pos.m_quad = aabbOut.m_quad;
  sphere.m_pos.m_quad.m128_f32[3] = v5;
  v9 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkDisplaySphere *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v9[11] + 8i64))(v9[11], 144i64);
  if ( v10 )
  {
    hkDisplaySphere::hkDisplaySphere(v10, &sphere, v8->m_environment.m_sphereThetaRes, v8->m_environment.m_spherePhiRes);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v12->m_transform.m_rotation.m_col0 = v7->m_rotation.m_col0;
  v12->m_transform.m_rotation.m_col1 = v7->m_rotation.m_col1;
  v12->m_transform.m_rotation.m_col2 = v7->m_rotation.m_col2;
  v12->m_transform.m_translation = v7->m_translation;
  if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 8);
  v6->m_data[v6->m_size++] = v12;
}

// File Line: 694
// RVA: 0xE1DF50
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_MultiSphere(hkpShapeDisplayBuilder *this, hkpMultiSphereShape *s, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  int v4; // ebp
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v5; // rbx
  hkpMultiSphereShape *v6; // r14
  hkpShapeDisplayBuilder *v7; // r15
  hkVector4f *i; // rsi
  int v9; // xmm1_4
  _QWORD **v10; // rax
  hkDisplaySphere *v11; // rax
  hkDisplayGeometry *v12; // rax
  hkDisplayGeometry *v13; // rdi
  hkSphere sphere; // [rsp+20h] [rbp-28h]

  v4 = 0;
  v5 = displayGeometries;
  v6 = s;
  v7 = this;
  for ( i = s->m_spheres; v4 < v6->m_numSpheres; ++i )
  {
    v9 = i->m_quad.m128_i32[3];
    sphere.m_pos.m_quad = aabbOut.m_quad;
    sphere.m_pos.m_quad.m128_i32[3] = v9;
    v10 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkDisplaySphere *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v10[11] + 8i64))(v10[11], 144i64);
    if ( v11 )
    {
      hkDisplaySphere::hkDisplaySphere(
        v11,
        &sphere,
        v7->m_environment.m_sphereThetaRes,
        v7->m_environment.m_spherePhiRes);
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    v13->m_transform.m_translation = (hkVector4f)i->m_quad;
    if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
    ++v4;
    v5->m_data[v5->m_size++] = v13;
  }
}

// File Line: 707
// RVA: 0xE1E040
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_Plane(hkpShapeDisplayBuilder *this, hkpPlaneShape *planeShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpPlaneShape *v4; // r12
  float v5; // er10
  unsigned int v6; // er11
  int *v7; // rbx
  __m128 v8; // xmm3
  int v9; // eax
  int v10; // er9
  __int64 v11; // rdi
  __m128 *v12; // r15
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __int64 v15; // rsi
  __int64 v16; // r14
  __m128 v17; // xmm6
  int v18; // eax
  __m128 *v19; // rcx
  __m128 v20; // xmm1
  __m128 v21; // xmm0
  __m128 v22; // xmm3
  __m128 v23; // xmm2
  __m128 v24; // xmm2
  __m128 v25; // xmm0
  unsigned __int64 v26; // rcx
  float v27; // edx
  __int128 v28; // xmm6
  int v29; // ebx
  __m128 v30; // xmm0
  __m128 v31; // xmm4
  int v32; // er9
  __int64 v33; // rdi
  __m128 v34; // xmm4
  __m128 v35; // xmm3
  __m128 v36; // xmm2
  __m128 v37; // xmm1
  __m128 v38; // xmm9
  __m128 v39; // xmm0
  __m128 v40; // xmm10
  __m128 v41; // xmm2
  __m128 v42; // xmm5
  signed __int64 v43; // r8
  __int128 *v44; // rcx
  signed __int64 v45; // rax
  signed __int64 v46; // rdx
  __m128 v47; // xmm0
  __m128 v48; // xmm1
  __m128 v49; // xmm0
  __m128 v50; // xmm6
  __m128 v51; // xmm1
  __m128 v52; // xmm4
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm0
  __m128 v56; // xmm3
  unsigned __int64 v57; // rcx
  int v58; // edx
  __int64 v59; // rdx
  __int64 v60; // rax
  hkDisplayGeometry *v61; // rax
  __int64 v62; // rdi
  hkGeometry *v63; // r13
  signed int v64; // er15
  int v65; // eax
  int v66; // er9
  int v67; // eax
  __int64 v68; // r12
  signed int v69; // er14
  signed __int64 v70; // rsi
  int v71; // er9
  int v72; // eax
  int v73; // eax
  signed __int64 v74; // r13
  __m128 v75; // xmm0
  __m128 v76; // xmm1
  BOOL v77; // er12
  hkTransformf *v78; // r15
  __int64 v79; // rbx
  signed int v80; // edx
  __m128i v81; // xmm6
  __m128i v82; // xmm3
  __m128i v83; // xmm1
  int *v84; // rcx
  __m128i v85; // xmm0
  __m128i v86; // xmm4
  __m128i v87; // xmm5
  int v88; // er10
  __m128i v89; // xmm0
  int v90; // er11
  int v91; // ebx
  __m128i v92; // xmm2
  __m128i v93; // xmm2
  __m128i v94; // xmm0
  __m128i v95; // xmm1
  __m128i v96; // xmm0
  __m128i v97; // xmm1
  __int64 v98; // r10
  int *v99; // rcx
  int v100; // edx
  __int64 v101; // r8
  int v102; // eax
  __m128 *sizeElem; // [rsp+20h] [rbp-79h]
  hkResult v104; // [rsp+28h] [rbp-71h]
  __m128 array; // [rsp+30h] [rbp-69h]
  hkResult result[4]; // [rsp+40h] [rbp-59h]
  hkVector4f t; // [rsp+50h] [rbp-49h]
  hkpShapeDisplayBuilder *v108; // [rsp+100h] [rbp+67h]
  __m128 *v109; // [rsp+108h] [rbp+6Fh]
  hkTransformf *a; // [rsp+110h] [rbp+77h]
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometriesa; // [rsp+118h] [rbp+7Fh]

  v4 = planeShape;
  v5 = 0.0;
  v6 = 2147483648;
  array.m128_u64[0] = 0i64;
  v7 = (int *)&signsForNonComponentAxes[0][1];
  v8 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&planeShape->m_plane), 1u), 1u);
  array.m128_u64[1] = 0x8000000000000000i64;
  v9 = _mm_movemask_ps(
         _mm_and_ps(
           _mm_cmpleps(
             _mm_max_ps(_mm_shuffle_ps(v8, v8, 170), _mm_max_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0))),
             v8),
           (__m128)xmmword_141AAA1D0));
  v10 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[v9];
  v11 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[v9];
  v12 = (__m128 *)(16 * v11);
  sizeElem = (__m128 *)(16 * v11);
  v13 = _mm_and_ps((__m128)`hkVector4f::getComponent'::`2'::indexToMask[v11], planeShape->m_plane.m_quad);
  v14 = _mm_or_ps(_mm_shuffle_ps(v13, v13, 78), v13);
  v15 = (v10 + 1) % 3;
  v16 = (v10 + 2) % 3;
  v17 = _mm_sub_ps((__m128)0i64, _mm_div_ps(query.m_quad, _mm_or_ps(_mm_shuffle_ps(v14, v14, 177), v14)));
  while ( 1 )
  {
    if ( LODWORD(v5) == (v6 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
      v5 = array.m128_f32[2];
    }
    v18 = *(v7 - 1);
    t.m_quad.m128_i32[v11] = 1065353216;
    t.m_quad.m128_i32[v15] = v18;
    v19 = (__m128 *)(array.m128_u64[0] + 16i64 * SLODWORD(v5));
    t.m_quad.m128_i32[v16] = *v7;
    array.m128_i32[2] = LODWORD(v5) + 1;
    v7 += 2;
    v20 = _mm_movelh_ps((__m128)t.m_quad.m128_u64[0], (__m128)t.m_quad.m128_u32[2]);
    *v19 = v20;
    v21 = _mm_mul_ps(v4->m_aabbHalfExtents.m_quad, v20);
    *v19 = v21;
    v22 = _mm_add_ps(v4->m_aabbCenter.m_quad, v21);
    *v19 = v22;
    v23 = _mm_mul_ps(v4->m_plane.m_quad, v22);
    v24 = _mm_shuffle_ps(v23, _mm_unpackhi_ps(v23, v4->m_plane.m_quad), 196);
    v25 = _mm_add_ps(_mm_shuffle_ps(v24, v24, 78), v24);
    *v19 = _mm_add_ps(
             _mm_mul_ps(_mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v25, v25, 177), v25), v17), *(&::transform.m_quad + v11)),
             v22);
    if ( (signed __int64)v7 >= (signed __int64)"serShapeDisplayBuilder" )
      break;
    v6 = array.m128_u32[3];
    v5 = array.m128_f32[2];
  }
  v26 = array.m128_u64[0];
  v27 = array.m128_f32[2];
  v28 = *(_OWORD *)array.m128_u64[0];
  if ( array.m128_i32[2] == (array.m128_i32[3] & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 16);
    v27 = array.m128_f32[2];
    v26 = array.m128_u64[0];
  }
  v29 = 0;
  *(_OWORD *)(v26 + 16i64 * SLODWORD(v27)) = v28;
  v30 = (__m128)`hkVector4f::getComponent'::`2'::indexToMask[v11];
  v31 = v4->m_aabbHalfExtents.m_quad;
  v32 = array.m128_i32[2] + 1;
  v33 = 0i64;
  ++array.m128_i32[2];
  v34 = _mm_and_ps(v31, v30);
  v35 = _mm_and_ps(v4->m_aabbCenter.m_quad, v30);
  v36 = _mm_or_ps(_mm_shuffle_ps(v34, v34, 78), v34);
  v37 = _mm_or_ps(_mm_shuffle_ps(v35, v35, 78), v35);
  v38 = _mm_sub_ps(_mm_or_ps(_mm_shuffle_ps(v37, v37, 177), v37), _mm_or_ps(_mm_shuffle_ps(v36, v36, 177), v36));
  array = v38;
  v39 = v37;
  v40 = _mm_add_ps(_mm_or_ps(_mm_shuffle_ps(v39, v39, 177), v39), _mm_or_ps(_mm_shuffle_ps(v36, v36, 177), v36));
  *(__m128 *)&result[0].m_enum = v40;
  do
  {
    v41 = v12[337020912];
    v42 = (__m128)xmmword_141A712A0;
    v43 = -1i64;
    v44 = (__int128 *)&array;
    v45 = 0i64;
    v46 = 2i64;
    v47 = _mm_and_ps(*(__m128 *)(array.m128_u64[0] + v33), v41);
    v48 = _mm_or_ps(_mm_shuffle_ps(v47, v47, 78), v47);
    v49 = _mm_and_ps(*(__m128 *)(array.m128_u64[0] + v33 + 16), v41);
    v50 = _mm_or_ps(_mm_shuffle_ps(v48, v48, 177), v48);
    v51 = _mm_or_ps(_mm_shuffle_ps(v49, v49, 78), v49);
    v52 = _mm_or_ps(_mm_shuffle_ps(v51, v51, 177), v51);
    do
    {
      v53 = (__m128)*v44;
      if ( v50.m128_f32[0] < COERCE_FLOAT(*v44) && v53.m128_f32[0] < v52.m128_f32[0]
        || v52.m128_f32[0] < v53.m128_f32[0] && v53.m128_f32[0] < v50.m128_f32[0] )
      {
        v54 = _mm_sub_ps(v52, v50);
        v55 = _mm_rcp_ps(v54);
        v56 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v54, v55)), v55), _mm_sub_ps(v53, v50));
        if ( v56.m128_f32[0] < v42.m128_f32[0] )
        {
          v42 = v56;
          v43 = v45;
        }
      }
      ++v45;
      ++v44;
      --v46;
    }
    while ( v46 );
    if ( v43 != -1 )
    {
      t.m_quad = _mm_or_ps(
                   _mm_andnot_ps(
                     v12[337020912],
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_sub_ps(*(__m128 *)(array.m128_u64[0] + v33 + 16), *(__m128 *)(array.m128_u64[0] + v33)),
                         v42),
                       *(__m128 *)(array.m128_u64[0] + v33))),
                   _mm_and_ps(*(&array + v43), v12[337020912]));
      hkArrayBase<hkVector4f>::_insertAt(
        (hkArrayBase<hkVector4f> *)&array,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v29 + 1,
        &t);
      v32 = array.m128_i32[2];
    }
    if ( v50.m128_f32[0] < v38.m128_f32[0] || v50.m128_f32[0] > v40.m128_f32[0] )
    {
      --v32;
      v57 = v33 + array.m128_u64[0];
      array.m128_i32[2] = v32;
      v58 = 16 * (v32 - v29);
      if ( v58 > 0 )
      {
        v59 = ((unsigned int)(v58 - 1) >> 3) + 1;
        do
        {
          v60 = *(_QWORD *)(v57 + 16);
          v57 += 8i64;
          *(_QWORD *)(v57 - 8) = v60;
          --v59;
        }
        while ( v59 );
        v32 = array.m128_i32[2];
      }
    }
    else
    {
      ++v29;
      v33 += 16i64;
    }
  }
  while ( v29 < v32 - 1 );
  array.m128_i32[2] = v32 - 1;
  v61 = hkpShapeDisplayBuilder::getCurrentRawGeometry(v108, displayGeometriesa);
  v62 = array.m128_u32[2];
  v63 = v61->m_geometry;
  v65 = v63->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  result[0] = (hkResult)v63->m_vertices.m_size;
  v64 = result[0].m_enum;
  v66 = array.m128_i32[2] + result[0].m_enum;
  if ( v65 >= array.m128_i32[2] + result[0].m_enum )
  {
    result[1].m_enum = 0;
  }
  else
  {
    v67 = 2 * v65;
    if ( v66 < v67 )
      v66 = v67;
    hkArrayUtil::_reserve(
      &result[1],
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v63->m_vertices,
      v66,
      16);
  }
  v63->m_vertices.m_size += v62;
  v68 = v63->m_triangles.m_size;
  v69 = v62 - 2;
  v70 = (signed __int64)&v63->m_vertices.m_data[v64];
  v71 = v62 - 2 + v68;
  v72 = v63->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v72 < v71 )
  {
    v73 = 2 * v72;
    if ( v71 < v73 )
      v71 = v73;
    hkArrayUtil::_reserve(
      &v104,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v63->m_triangles,
      v71,
      16);
  }
  v63->m_triangles.m_size += v69;
  v74 = (signed __int64)&v63->m_triangles.m_data[v68];
  v75 = _mm_and_ps(sizeElem[337020912], v109[2]);
  v76 = _mm_or_ps(_mm_shuffle_ps(v75, v75, 78), v75);
  v75.m128_i32[0] = *(unsigned __int128 *)&_mm_shuffle_ps(v76, v76, 177) | v76.m128_i32[0];
  v77 = v75.m128_f32[0] <= 0.0;
  LOBYTE(v77) = v75.m128_f32[0] > 0.0;
  if ( (signed int)v62 > 0 )
  {
    v78 = a;
    v79 = 0i64;
    do
    {
      hkVector4f::setTransformedPos((hkVector4f *)(v79 + v70), v78, (hkVector4f *)(v79 + array.m128_u64[0]));
      v79 += 16i64;
      --v62;
    }
    while ( v62 );
    v64 = result[0].m_enum;
  }
  v80 = 0;
  if ( v69 > 0 && (unsigned int)v69 >= 4 )
  {
    v81 = _mm_load_si128((const __m128i *)&_xmm);
    v82 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v64), 0);
    v83 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v77), 0);
    v84 = (int *)(v74 + 32);
    v85 = _mm_srli_si128(v82, 4);
    v86 = _mm_add_epi32(_mm_load_si128((const __m128i *)_xmm), v83);
    v87 = _mm_sub_epi32(_mm_load_si128((const __m128i *)&_xmm), v83);
    v88 = _mm_cvtsi128_si32(v85);
    v89 = _mm_srli_si128(v85, 4);
    v90 = _mm_cvtsi128_si32(v89);
    v91 = v90;
    do
    {
      v92 = _mm_cvtsi32_si128(v80);
      v80 += 4;
      *(v84 - 4) = v88;
      *v84 = v90;
      v84[4] = v91;
      *(v84 - 8) = _mm_cvtsi128_si32(v82);
      v93 = _mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v92, 0), v81), v82);
      v84 += 16;
      v94 = _mm_add_epi32(v86, v93);
      v95 = _mm_add_epi32(v87, v93);
      *(v84 - 23) = _mm_cvtsi128_si32(v94);
      *(v84 - 22) = _mm_cvtsi128_si32(v95);
      v96 = _mm_srli_si128(v94, 4);
      v97 = _mm_srli_si128(v95, 4);
      *(v84 - 19) = _mm_cvtsi128_si32(v96);
      *(v84 - 18) = _mm_cvtsi128_si32(v97);
      *(v84 - 15) = _mm_cvtsi128_si32(v96);
      *(v84 - 14) = _mm_cvtsi128_si32(v97);
      *(v84 - 11) = _mm_cvtsi128_si32(v96);
      *(v84 - 10) = _mm_cvtsi128_si32(v97);
    }
    while ( v80 < v69 - v69 % 4 );
  }
  v98 = v80;
  if ( v80 < (signed __int64)v69 )
  {
    v99 = (int *)(16i64 * v80 + v74 + 8);
    v100 = v64 + v77 + v80 + 1;
    v101 = v69 - v98;
    do
    {
      v102 = 1 - 2 * v77 + v100;
      *(v99 - 1) = v100++;
      *(v99 - 2) = v64;
      *v99 = v102;
      v99 += 4;
      --v101;
    }
    while ( v101 );
  }
  array.m128_i32[2] = 0;
  if ( array.m128_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      (void *)array.m128_u64[0],
      16 * array.m128_i32[3]);
}+ v100;
      *(v99 - 1) = v100++;
      *(v99 - 2) = v64;
      *v99 = v102;
      v99 += 4;
      --v1

// File Line: 829
// RVA: 0xE1C5C0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_Capsule(hkpShapeDisplayBuilder *this, hkpCapsuleShape *s, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries, hkVector4f *scale)
{
  hkVector4f v5; // xmm1
  __m128 v6; // xmm2
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v7; // rbx
  hkTransformf *v8; // rsi
  float v9; // xmm6_4
  __m128 v10; // xmm0
  _QWORD **v11; // rax
  hkDisplayCapsule *v12; // rax
  hkDisplayGeometry *v13; // rax
  hkDisplayGeometry *v14; // rdi
  hkVector4f bottom; // [rsp+30h] [rbp-38h]
  hkVector4f top; // [rsp+40h] [rbp-28h]

  v5.m_quad = (__m128)s->m_vertexA;
  v6 = s->m_vertexB.m_quad;
  v7 = displayGeometries;
  v8 = transform;
  top.m_quad = (__m128)s->m_vertexA;
  bottom.m_quad = v6;
  v9 = s->m_radius;
  if ( scale )
  {
    v10 = _mm_shuffle_ps(scale->m_quad, scale->m_quad, 0);
    top.m_quad = _mm_mul_ps(v5.m_quad, v10);
    bottom.m_quad = _mm_mul_ps(v6, v10);
    v9 = v9 * COERCE_FLOAT((unsigned int)(2 * v10.m128_i32[0]) >> 1);
  }
  v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkDisplayCapsule *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(v11[11], 160i64);
  if ( v12 )
  {
    hkDisplayCapsule::hkDisplayCapsule(v12, &top, &bottom, v9, 6, 1);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  v14->m_transform.m_rotation.m_col0 = v8->m_rotation.m_col0;
  v14->m_transform.m_rotation.m_col1 = v8->m_rotation.m_col1;
  v14->m_transform.m_rotation.m_col2 = v8->m_rotation.m_col2;
  v14->m_transform.m_translation = v8->m_translation;
  if ( v7->m_size == (v7->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 8);
  v7->m_data[v7->m_size++] = v14;
}

// File Line: 854
// RVA: 0xE1C6E0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_Cylinder(hkpShapeDisplayBuilder *this, hkpCylinderShape *s, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries, hkVector4f *scale)
{
  hkVector4f v5; // xmm1
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v6; // rbx
  hkTransformf *v7; // rsi
  float v8; // xmm0_4
  float v9; // xmm6_4
  __m128 v10; // xmm3
  _QWORD **v11; // rax
  hkDisplayCylinder *v12; // rax
  hkDisplayGeometry *v13; // rax
  hkDisplayGeometry *v14; // rdi
  hkVector4f bottom; // [rsp+30h] [rbp-38h]
  hkVector4f top; // [rsp+40h] [rbp-28h]

  v5.m_quad = (__m128)s->m_vertexB;
  v6 = displayGeometries;
  v7 = transform;
  _mm_store_si128((__m128i *)&top, (__m128i)s->m_vertexA.m_quad);
  _mm_store_si128((__m128i *)&bottom, (__m128i)v5.m_quad);
  v8 = hkpCylinderShape::getCylinderRadius(s);
  v9 = v8;
  if ( scale )
  {
    v10 = _mm_shuffle_ps(scale->m_quad, scale->m_quad, 0);
    top.m_quad = _mm_mul_ps(top.m_quad, v10);
    bottom.m_quad = _mm_mul_ps(bottom.m_quad, v10);
    v9 = v8 * COERCE_FLOAT((unsigned int)(2 * v10.m128_i32[0]) >> 1);
  }
  v11 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkDisplayCylinder *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v11[11] + 8i64))(v11[11], 160i64);
  if ( v12 )
  {
    hkDisplayCylinder::hkDisplayCylinder(v12, &top, &bottom, v9, 9, 1);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  v14->m_transform.m_rotation.m_col0 = v7->m_rotation.m_col0;
  v14->m_transform.m_rotation.m_col1 = v7->m_rotation.m_col1;
  v14->m_transform.m_rotation.m_col2 = v7->m_rotation.m_col2;
  v14->m_transform.m_translation = v7->m_translation;
  if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 8);
  v6->m_data[v6->m_size++] = v14;
}

// File Line: 877
// RVA: 0xE1E7B0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_MultiRay(hkpShapeDisplayBuilder *this, hkpMultiRayShape *s, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpMultiRayShape *v4; // r13
  hkTransformf *v5; // r12
  int v6; // er15
  hkGeometry *v7; // rdi
  signed int v8; // esi
  __int64 v9; // r14
  hkpMultiRayShape::Ray *v10; // rax
  __int64 v11; // rbp
  int v12; // er9
  __m128 v13; // xmm6
  hkVector4f v14; // xmm7
  int v15; // eax
  int v16; // eax
  hkVector4f *v17; // r8
  __int64 v18; // rbp
  int v19; // er9
  int v20; // eax
  int v21; // eax
  __int64 v22; // rbp
  int v23; // er9
  int v24; // eax
  int v25; // eax
  hkVector4f *v26; // r8
  __int64 v27; // rbp
  int v28; // er9
  int v29; // eax
  int v30; // eax
  hkGeometry::Triangle *v31; // rcx
  int v32; // eax
  hkResult v33; // [rsp+30h] [rbp-68h]
  hkResult v34; // [rsp+34h] [rbp-64h]
  hkResult v35; // [rsp+38h] [rbp-60h]
  hkResult result; // [rsp+A8h] [rbp+10h]

  v4 = s;
  v5 = transform;
  v6 = 0;
  v7 = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries)->m_geometry;
  if ( v4->m_rays.m_size > 0 )
  {
    v8 = 2;
    v9 = 0i64;
    do
    {
      v10 = v4->m_rays.m_data;
      v11 = v7->m_vertices.m_size;
      v12 = v11 + 1;
      v13 = v10[v9].m_start.m_quad;
      v14.m_quad = (__m128)v10[v9].m_end;
      v15 = v7->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v15 >= (signed int)v11 + 1 )
      {
        result.m_enum = 0;
      }
      else
      {
        v16 = 2 * v15;
        if ( v12 < v16 )
          v12 = v16;
        hkArrayUtil::_reserve(
          &result,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v7->m_vertices,
          v12,
          16);
      }
      ++v7->m_vertices.m_size;
      v17 = &v7->m_vertices.m_data[v11];
      *v17 = (hkVector4f)v13;
      hkVector4f::setTransformedPos(v17, v5, v17);
      v18 = v7->m_vertices.m_size;
      v19 = v18 + 1;
      v20 = v7->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v20 >= (signed int)v18 + 1 )
      {
        v33.m_enum = 0;
      }
      else
      {
        v21 = 2 * v20;
        if ( v19 < v21 )
          v19 = v21;
        hkArrayUtil::_reserve(
          &v33,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v7->m_vertices,
          v19,
          16);
      }
      ++v7->m_vertices.m_size;
      v7->m_vertices.m_data[v18].m_quad = _mm_add_ps((__m128)_xmm, v13);
      v22 = v7->m_vertices.m_size;
      v23 = v22 + 1;
      v24 = v7->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v24 >= (signed int)v22 + 1 )
      {
        v34.m_enum = 0;
      }
      else
      {
        v25 = 2 * v24;
        if ( v23 < v25 )
          v23 = v25;
        hkArrayUtil::_reserve(
          &v34,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v7->m_vertices,
          v23,
          16);
      }
      ++v7->m_vertices.m_size;
      v26 = &v7->m_vertices.m_data[v22];
      *v26 = (hkVector4f)v14.m_quad;
      hkVector4f::setTransformedPos(v26, v5, v26);
      v27 = v7->m_triangles.m_size;
      v28 = v27 + 1;
      v29 = v7->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v29 >= (signed int)v27 + 1 )
      {
        v35.m_enum = 0;
      }
      else
      {
        v30 = 2 * v29;
        if ( v28 < v30 )
          v28 = v30;
        hkArrayUtil::_reserve(
          &v35,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v7->m_triangles,
          v28,
          16);
      }
      ++v7->m_triangles.m_size;
      ++v6;
      ++v9;
      v31 = &v7->m_triangles.m_data[v27];
      v31->m_a = v8 - 2;
      v32 = v8 - 1;
      v31->m_c = v8;
      v31->m_material = -1;
      v8 += 3;
      v31->m_b = v32;
    }
    while ( v6 < v4->m_rays.m_size );
  }
}

// File Line: 911
// RVA: 0xE1C810
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_Box(hkpShapeDisplayBuilder *this, hkpBoxShape *boxShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries, hkVector4f *scale)
{
  hkVector4f v5; // xmm1
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v6; // rbx
  hkTransformf *v7; // rsi
  _QWORD **v8; // rax
  hkDisplayBox *v9; // rax
  hkDisplayGeometry *v10; // rax
  hkDisplayGeometry *v11; // rdi
  hkVector4f halfExtents; // [rsp+20h] [rbp-18h]

  v5.m_quad = (__m128)boxShape->m_halfExtents;
  v6 = displayGeometries;
  v7 = transform;
  halfExtents.m_quad = (__m128)boxShape->m_halfExtents;
  if ( scale )
    halfExtents.m_quad = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_mul_ps(scale->m_quad, v5.m_quad), 1u), 1u);
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkDisplayBox *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 128i64);
  if ( v9 )
  {
    hkDisplayBox::hkDisplayBox(v9, &halfExtents);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v11->m_transform.m_rotation.m_col0 = v7->m_rotation.m_col0;
  v11->m_transform.m_rotation.m_col1 = v7->m_rotation.m_col1;
  v11->m_transform.m_rotation.m_col2 = v7->m_rotation.m_col2;
  v11->m_transform.m_translation = v7->m_translation;
  if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 8);
  v6->m_data[v6->m_size++] = v11;
}

// File Line: 924
// RVA: 0xE1D1B0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_ListShape(hkpShapeDisplayBuilder *this, hkpListShape *listShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpShapeDisplayBuilder *v4; // r15
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v5; // rbp
  hkTransformf *v6; // r14
  hkpListShape *v7; // rsi
  unsigned int i; // ebx

  v4 = this;
  v5 = displayGeometries;
  v6 = transform;
  v7 = listShape;
  for ( i = listShape->vfptr->getFirstKey((hkpShapeContainer *)&listShape->vfptr);
        i != -1;
        i = v7->vfptr->getNextKey((hkpShapeContainer *)&v7->vfptr, i) )
  {
    hkpShapeDisplayBuilder::buildShapeDisplay(v4, v7->m_childInfo.m_data[i].m_shape, v6, v5, 0i64);
  }
}

// File Line: 934
// RVA: 0xE1C8F0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_Triangle(hkpShapeDisplayBuilder *this, hkpTriangleShape *triangleShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries, hkVector4f *scale)
{
  hkpTriangleShape *v5; // r15
  hkTransformf *v6; // rbx
  hkGeometry *v7; // rsi
  int v8; // ebp
  int v9; // eax
  int v10; // er9
  int v11; // eax
  hkVector4f *v12; // rbx
  __int64 v13; // rbx
  int v14; // er9
  int v15; // eax
  int v16; // eax
  int v17; // er14
  int v18; // er12
  hkGeometry::Triangle *v19; // rax
  __m128 v20; // xmm3
  __m128 v21; // xmm2
  __int64 v22; // rbx
  __m128 v23; // xmm1
  int v24; // er9
  int v25; // eax
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  int v28; // eax
  hkVector4f *v29; // rbx
  __int64 v30; // rbx
  int v31; // er9
  int v32; // eax
  int v33; // eax
  hkGeometry::Triangle *v34; // r8
  hkVector4f b; // [rsp+30h] [rbp-88h]
  hkVector4f v36; // [rsp+40h] [rbp-78h]
  hkVector4f v37; // [rsp+50h] [rbp-68h]
  hkQsTransformf a; // [rsp+60h] [rbp-58h]

  v5 = triangleShape;
  v6 = transform;
  v7 = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries)->m_geometry;
  hkQsTransformf::setFromTransformNoScale(&a, v6);
  if ( scale )
    a.m_scale = (hkVector4f)scale->m_quad;
  v8 = v7->m_vertices.m_size;
  v9 = v7->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  v10 = v8 + 3;
  if ( v9 >= v8 + 3 )
  {
    LODWORD(scale) = 0;
  }
  else
  {
    v11 = 2 * v9;
    if ( v10 < v11 )
      v10 = v11;
    hkArrayUtil::_reserve(
      (hkResult *)&scale,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v7->m_vertices,
      v10,
      16);
  }
  v7->m_vertices.m_size += 3;
  v12 = &v7->m_vertices.m_data[v8];
  hkVector4f::setTransformedPos(v12, &a, &v5->m_vertexA);
  hkVector4f::setTransformedPos(v12 + 1, &a, &v5->m_vertexB);
  hkVector4f::setTransformedPos(v12 + 2, &a, &v5->m_vertexC);
  v13 = v7->m_triangles.m_size;
  v14 = v13 + 1;
  v15 = v7->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v15 < (signed int)v13 + 1 )
  {
    v16 = 2 * v15;
    if ( v14 < v16 )
      v14 = v16;
    hkArrayUtil::_reserve(
      (hkResult *)&scale,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v7->m_triangles,
      v14,
      16);
  }
  ++v7->m_triangles.m_size;
  v17 = v8 + 1;
  v18 = v8 + 2;
  v19 = &v7->m_triangles.m_data[v13];
  v19->m_a = v8;
  v19->m_b = v8 + 1;
  v19->m_c = v8 + 2;
  v19->m_material = -1;
  v20 = v5->m_extrusion.m_quad;
  v21 = _mm_mul_ps(v20, v20);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v21, v21, 170))) > 0.0 )
  {
    v22 = v7->m_vertices.m_size;
    v23 = v5->m_extrusion.m_quad;
    v24 = v22 + 3;
    v25 = v7->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    v26 = _mm_add_ps(v20, v5->m_vertexA.m_quad);
    v27 = _mm_add_ps(v20, v5->m_vertexC.m_quad);
    b.m_quad = v26;
    v37.m_quad = v27;
    v36.m_quad = _mm_add_ps(v23, v5->m_vertexB.m_quad);
    if ( v25 >= (signed int)v22 + 3 )
    {
      LODWORD(scale) = 0;
    }
    else
    {
      v28 = 2 * v25;
      if ( v24 < v28 )
        v24 = v28;
      hkArrayUtil::_reserve(
        (hkResult *)&scale,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v7->m_vertices,
        v24,
        16);
    }
    v7->m_vertices.m_size += 3;
    v29 = &v7->m_vertices.m_data[v22];
    hkVector4f::setTransformedPos(v29, &a, &b);
    hkVector4f::setTransformedPos(v29 + 1, &a, &v36);
    hkVector4f::setTransformedPos(v29 + 2, &a, &v37);
    v30 = v7->m_triangles.m_size;
    v31 = v30 + 7;
    v32 = v7->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v32 < (signed int)v30 + 7 )
    {
      v33 = 2 * v32;
      if ( v31 < v33 )
        v31 = v33;
      hkArrayUtil::_reserve(
        (hkResult *)&scale,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v7->m_triangles,
        v31,
        16);
    }
    v7->m_triangles.m_size += 7;
    v34 = &v7->m_triangles.m_data[v30];
    v34->m_a = v8 + 3;
    v34->m_b = v17;
    v34->m_c = v8;
    v34->m_material = -1;
    v34[1].m_a = v8 + 3;
    v34[1].m_b = v8 + 4;
    v34[1].m_c = v17;
    v34[1].m_material = -1;
    v34[2].m_a = v8 + 4;
    v34[2].m_b = v8 + 5;
    v34[2].m_c = v17;
    v34[2].m_material = -1;
    v34[3].m_a = v8 + 5;
    v34[3].m_b = v18;
    v34[3].m_c = v17;
    v34[3].m_material = -1;
    v34[4].m_a = v8 + 5;
    v34[4].m_b = v8;
    v34[4].m_c = v18;
    v34[4].m_material = -1;
    v34[5].m_a = v8 + 5;
    v34[5].m_b = v8 + 3;
    v34[5].m_c = v8;
    v34[5].m_material = -1;
    v34[6].m_a = v8 + 5;
    v34[6].m_b = v8 + 4;
    v34[6].m_c = v8 + 3;
    v34[6].m_material = -1;
  }
}

// File Line: 985
// RVA: 0xE1CC30
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_ConvexVertices(hkpShapeDisplayBuilder *this, hkpConvexVerticesShape *cvShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries, hkVector4f *scale)
{
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v5; // rsi
  hkTransformf *v6; // r15
  hkpConvexVerticesShape *v7; // rbx
  unsigned int v8; // eax
  __int64 v9; // rdi
  hkLifoAllocator *v10; // rax
  char *v11; // rcx
  int v12; // edx
  char *v13; // r8
  signed int v14; // eax
  int v15; // eax
  int v16; // er9
  hkBaseObjectVtbl *v17; // rax
  __int64 v18; // r14
  int v19; // er9
  __int64 v20; // rbx
  _QWORD **v21; // rax
  __int64 v22; // rax
  hkGeometry *v23; // rbx
  _QWORD **v24; // rax
  hkDisplayConvex *v25; // rax
  hkDisplayGeometry *v26; // rax
  hkDisplayGeometry *v27; // rbx
  int v28; // er8
  int v29; // eax
  char *v30; // rdi
  signed int v31; // ebx
  hkLifoAllocator *v32; // rax
  int v33; // er8
  float *v34; // [rsp+30h] [rbp-41h]
  int v35; // [rsp+38h] [rbp-39h]
  int v36; // [rsp+3Ch] [rbp-35h]
  hkStridedVertices stridedVertsIn; // [rsp+40h] [rbp-31h]
  char *array; // [rsp+50h] [rbp-21h]
  int v39; // [rsp+58h] [rbp-19h]
  int v40; // [rsp+5Ch] [rbp-15h]
  void *p; // [rsp+60h] [rbp-11h]
  unsigned int v42; // [rsp+68h] [rbp-9h]
  hkQsTransformf a; // [rsp+70h] [rbp-1h]
  hkResult result; // [rsp+D8h] [rbp+67h]

  v5 = displayGeometries;
  v6 = transform;
  v7 = cvShape;
  v8 = ((__int64 (__fastcall *)(hkpConvexVerticesShape *))cvShape->vfptr[5].__first_virtual_table_function__)(cvShape);
  v9 = v8;
  if ( v8 )
  {
    array = 0i64;
    v39 = 0;
    v40 = 2147483648;
    v42 = v8;
    v10 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (char *)v10->m_cur;
    v12 = (16 * v9 + 127) & 0xFFFFFF80;
    v13 = &v11[v12];
    if ( v12 > v10->m_slabSize || v13 > v10->m_end )
      v11 = (char *)hkLifoAllocator::allocateFromNewSlab(v10, v12);
    else
      v10->m_cur = v13;
    array = v11;
    p = v11;
    v40 = v9 | 0x80000000;
    v14 = (v9 | 0x80000000) & 0x3FFFFFFF;
    if ( v14 < (signed int)v9 )
    {
      v15 = 2 * v14;
      v16 = v9;
      if ( (signed int)v9 < v15 )
        v16 = v15;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v16, 16);
      v11 = array;
    }
    v17 = v7->vfptr;
    v39 = v9;
    v18 = (__int64)v17[6].__vecDelDtor((hkBaseObject *)&v7->vfptr, (unsigned int)v11);
    hkQsTransformf::setFromTransformNoScale(&a, v6);
    if ( scale )
      a.m_scale = (hkVector4f)scale->m_quad;
    v34 = 0i64;
    v35 = 0;
    v36 = 2147483648;
    if ( (signed int)v9 > 0 )
    {
      v19 = v9;
      if ( (signed int)v9 < 0 )
        v19 = 0;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v34, v19, 16);
    }
    v35 = v9;
    if ( (signed int)v9 > 0 )
    {
      v20 = 0i64;
      do
      {
        hkVector4f::setTransformedPos((hkVector4f *)&v34[v20], &a, (hkVector4f *)(v20 * 4 + v18));
        v20 += 4i64;
        --v9;
      }
      while ( v9 );
    }
    v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v21[11] + 8i64))(v21[11], 48i64);
    v23 = (hkGeometry *)v22;
    if ( v22 )
    {
      *(_DWORD *)(v22 + 8) = 0x1FFFF;
      *(_QWORD *)v22 = &hkGeometry::`vftable';
      *(_QWORD *)(v22 + 16) = 0i64;
      *(_DWORD *)(v22 + 24) = 0;
      *(_DWORD *)(v22 + 28) = 2147483648;
      *(_QWORD *)(v22 + 32) = 0i64;
      *(_DWORD *)(v22 + 40) = 0;
      *(_DWORD *)(v22 + 44) = 2147483648;
    }
    else
    {
      v23 = 0i64;
    }
    stridedVertsIn.m_vertices = v34;
    stridedVertsIn.m_striding = 16;
    stridedVertsIn.m_numVertices = v35;
    hkGeometryUtility::createConvexGeometry(&stridedVertsIn, v23);
    v24 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v25 = (hkDisplayConvex *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v24[11] + 8i64))(v24[11], 112i64);
    if ( v25 )
    {
      hkDisplayConvex::hkDisplayConvex(v25, v23);
      v27 = v26;
    }
    else
    {
      v27 = 0i64;
    }
    if ( v5->m_size == (v5->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v5, 8);
    v5->m_data[v5->m_size] = v27;
    v28 = v36;
    ++v5->m_size;
    v35 = 0;
    if ( v28 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        v34,
        16 * v28);
    v29 = v39;
    v30 = (char *)p;
    v34 = 0i64;
    if ( p == array )
      v29 = 0;
    v36 = 2147483648;
    v39 = v29;
    v31 = (16 * v42 + 127) & 0xFFFFFF80;
    v32 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v33 = (v31 + 15) & 0xFFFFFFF0;
    if ( v31 > v32->m_slabSize || &v30[v33] != v32->m_cur || v32->m_firstNonLifoEnd == v30 )
      hkLifoAllocator::slowBlockFree(v32, v30, v33);
    else
      v32->m_cur = v30;
    v39 = 0;
    if ( v40 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        array,
        16 * v40);
  }
}

// File Line: 1019
// RVA: 0xE1EF20
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_ConvexPiece(hkpShapeDisplayBuilder *this, hkpConvexPieceShape *triangulatedConvexShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v4; // r13
  hkpConvexPieceShape *v5; // rdi
  _QWORD **v6; // rax
  __int64 v7; // rax
  hkDisplayGeometry *v8; // rsi
  hkGeometry *v9; // r15
  int v10; // er12
  __int64 v11; // rdx
  signed int *v12; // r14
  __int64 v13; // rax
  __int64 v14; // rdi
  int v15; // er9
  int v16; // ecx
  hkVector4f *v17; // rbp
  int v18; // ecx
  int v19; // ecx
  int *v20; // rdx
  hkVector4f *v21; // rbp
  signed __int64 v22; // r14
  __int64 v23; // rdi
  int v24; // er9
  int v25; // eax
  int v26; // eax
  _QWORD **v27; // rax
  hkDisplayConvex *v28; // rax
  hkDisplayGeometry *v29; // rax
  hkResult v30; // [rsp+30h] [rbp-248h]
  hkResult result; // [rsp+34h] [rbp-244h]
  __int64 v32; // [rsp+38h] [rbp-240h]
  char v33; // [rsp+40h] [rbp-238h]
  hkpConvexPieceShape *v34; // [rsp+288h] [rbp+10h]
  hkTransformf *a; // [rsp+290h] [rbp+18h]
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v36; // [rsp+298h] [rbp+20h]

  v36 = displayGeometries;
  a = transform;
  v34 = triangulatedConvexShape;
  v4 = displayGeometries;
  v5 = triangulatedConvexShape;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 48i64);
  v8 = 0i64;
  v9 = (hkGeometry *)v7;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 8) = 0x1FFFF;
    *(_QWORD *)v7 = &hkGeometry::`vftable';
    *(_QWORD *)(v7 + 16) = 0i64;
    *(_DWORD *)(v7 + 24) = 0;
    *(_DWORD *)(v7 + 28) = 2147483648;
    *(_QWORD *)(v7 + 32) = 0i64;
    *(_DWORD *)(v7 + 40) = 0;
    *(_DWORD *)(v7 + 44) = 2147483648;
  }
  else
  {
    v9 = 0i64;
  }
  v10 = 0;
  if ( v5->m_numDisplayShapeKeys > 0 )
  {
    v11 = 0i64;
    v32 = 0i64;
    v12 = (signed int *)&v9->m_triangles;
    do
    {
      v13 = (__int64)v5->m_displayMesh->vfptr->getChildShape(
                       (hkpShapeContainer *)&v5->m_displayMesh->vfptr,
                       *(const unsigned int *)((char *)v5->m_displayShapeKeys + v11),
                       (char (*)[512])&v33);
      v14 = v12[2];
      v15 = v14 + 1;
      v16 = v12[3] & 0x3FFFFFFF;
      v17 = (hkVector4f *)v13;
      if ( v16 >= (signed int)v14 + 1 )
      {
        result.m_enum = 0;
      }
      else
      {
        v18 = 2 * v16;
        if ( v15 < v18 )
          v15 = v18;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12, v15, 16);
      }
      ++v12[2];
      v19 = v9->m_vertices.m_size;
      v20 = (int *)(*(_QWORD *)v12 + 16 * v14);
      v21 = v17 + 3;
      v22 = 3i64;
      v20[1] = v19 + 1;
      *v20 = v19;
      v20[2] = v19 + 2;
      v20[3] = -1;
      do
      {
        v23 = v9->m_vertices.m_size;
        v24 = v23 + 1;
        v25 = v9->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v25 >= (signed int)v23 + 1 )
        {
          v30.m_enum = 0;
        }
        else
        {
          v26 = 2 * v25;
          if ( v24 < v26 )
            v24 = v26;
          hkArrayUtil::_reserve(
            &v30,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v9->m_vertices,
            v24,
            16);
        }
        ++v9->m_vertices.m_size;
        hkVector4f::setTransformedPos(&v9->m_vertices.m_data[v23], a, v21);
        ++v21;
        --v22;
      }
      while ( v22 );
      v5 = v34;
      ++v10;
      v11 = v32 + 4;
      v12 = (signed int *)&v9->m_triangles;
      v32 += 4i64;
    }
    while ( v10 < v34->m_numDisplayShapeKeys );
    v4 = v36;
  }
  v27 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v28 = (hkDisplayConvex *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v27[11] + 8i64))(v27[11], 112i64);
  if ( v28 )
  {
    hkDisplayConvex::hkDisplayConvex(v28, v9);
    v8 = v29;
  }
  if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 8);
  v4->m_data[v4->m_size++] = v8;
}

// File Line: 1048
// RVA: 0xE1EA10
hkBool *__fastcall hkpShapeDisplayBuilder::buildShapeDisplay_UserShapes(hkpShapeDisplayBuilder *this, hkBool *result, hkpShape *shape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpUserShapeDisplayBuilder *v5; // r10
  int v6; // ebx
  hkTransformf *v7; // r15
  hkpShape *v8; // rbp
  hkBool *v9; // rsi
  hkpShapeDisplayBuilder *v10; // r12
  __int64 v11; // rdi
  hkpUserShapeDisplayBuilder::UserShapeBuilder *v12; // r11

  v5 = hkSingleton<hkpUserShapeDisplayBuilder>::s_instance;
  v6 = 0;
  v7 = transform;
  v8 = shape;
  v9 = result;
  v10 = this;
  result->m_bool = 0;
  if ( v5->m_userShapeBuilders.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      v12 = v5->m_userShapeBuilders.m_data;
      if ( v12[v11].type == (unsigned __int8)v8->m_type.m_storage )
      {
        v12[v11].f(v8, v7, displayGeometries, v10);
        v5 = hkSingleton<hkpUserShapeDisplayBuilder>::s_instance;
        v9->m_bool = 1;
      }
      ++v6;
      ++v11;
    }
    while ( v6 < v5->m_userShapeBuilders.m_size );
  }
  return v9;
}

// File Line: 1066
// RVA: 0xE1CF60
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_StaticCompound(hkpShapeDisplayBuilder *this, hkpStaticCompoundShape *staticCompoundShape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries, hkVector4f *scale)
{
  hkpShapeDisplayBuilder *v5; // r14
  hkpStaticCompoundShape *v6; // rdi
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v7; // rbp
  __m128 v8; // xmm9
  int v9; // esi
  __int64 v10; // rbx
  hkpStaticCompoundShape::Instance *v11; // rax
  __m128 v12; // xmm8
  __m128 v13; // xmm5
  __m128 v14; // xmm3
  __m128 v15; // xmm1
  __m128 v16; // xmm2
  __m128 v17; // xmm6
  __m128 v18; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // xmm7
  __m128 v21; // xmm4
  __m128 v22; // xmm4
  __m128 v23; // xmm0
  hkpShape *v24; // rdx
  hkQsTransformf v25; // [rsp+30h] [rbp-F8h]
  hkQsTransformf v26; // [rsp+60h] [rbp-C8h]
  hkTransformf transformOut; // [rsp+90h] [rbp-98h]

  v5 = this;
  v6 = staticCompoundShape;
  v7 = displayGeometries;
  hkQsTransformf::setFromTransformNoScale(&v25, transform);
  if ( scale )
  {
    v8 = scale->m_quad;
    v25.m_scale = (hkVector4f)scale->m_quad;
  }
  else
  {
    v8 = v25.m_scale.m_quad;
  }
  v9 = 0;
  if ( v6->m_instances.m_size > 0 )
  {
    v10 = 0i64;
    while ( 1 )
    {
      v11 = v6->m_instances.m_data;
      v12 = _mm_shuffle_ps(v25.m_rotation.m_vec.m_quad, v25.m_rotation.m_vec.m_quad, 255);
      v13 = _mm_shuffle_ps(v25.m_rotation.m_vec.m_quad, v25.m_rotation.m_vec.m_quad, 201);
      v14 = _mm_mul_ps(v11[v10].m_transform.m_translation.m_quad, v8);
      v15 = _mm_mul_ps(v25.m_rotation.m_vec.m_quad, v14);
      v16 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v14, v14, 201), v25.m_rotation.m_vec.m_quad), _mm_mul_ps(v13, v14));
      v17 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v15, v15, 85), _mm_shuffle_ps(v15, v15, 0)),
                    _mm_shuffle_ps(v15, v15, 170)),
                  v25.m_rotation.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v12, v12), (__m128)xmmword_141A711B0), v14)),
              _mm_mul_ps(_mm_shuffle_ps(v16, v16, 201), v12));
      v18 = v11[v10].m_transform.m_rotation.m_vec.m_quad;
      v19 = _mm_shuffle_ps(
              v11[v10].m_transform.m_rotation.m_vec.m_quad,
              v11[v10].m_transform.m_rotation.m_vec.m_quad,
              255);
      v20 = _mm_mul_ps(v25.m_rotation.m_vec.m_quad, v18);
      v21 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v25.m_rotation.m_vec.m_quad), _mm_mul_ps(v13, v18));
      v22 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v21, v21, 201), _mm_mul_ps(v11[v10].m_transform.m_rotation.m_vec.m_quad, v12)),
              _mm_mul_ps(v25.m_rotation.m_vec.m_quad, v19));
      v23 = v11[v10].m_transform.m_scale.m_quad;
      v26.m_translation.m_quad = _mm_add_ps(_mm_add_ps(v17, v17), v25.m_translation.m_quad);
      v26.m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                      v22,
                                      _mm_unpackhi_ps(
                                        v22,
                                        _mm_sub_ps(
                                          _mm_mul_ps(v19, v12),
                                          _mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                                            _mm_shuffle_ps(v20, v20, 170)))),
                                      196);
      v26.m_scale.m_quad = _mm_mul_ps(v23, v8);
      hkQsTransformf::copyToTransformNoScale(&v26, &transformOut);
      v24 = v6->m_instances.m_data[v10].m_shape;
      if ( (_mm_movemask_ps(
              _mm_cmpltps(
                (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v26.m_scale.m_quad, query.m_quad), 1u), 1u),
                *(__m128 *)&epsilon)) & 7) == 7 )
        hkpShapeDisplayBuilder::buildShapeDisplay(v5, v24, &transformOut, v7, 0i64);
      else
        hkpShapeDisplayBuilder::buildShapeDisplay(v5, v24, &transformOut, v7, &v26.m_scale);
      ++v9;
      ++v10;
      if ( v9 >= v6->m_instances.m_size )
        break;
      v8 = v25.m_scale.m_quad;
    }
  }
}

// File Line: 1095
// RVA: 0xE1BF00
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay(hkpShapeDisplayBuilder *this, hkpShape *shape, hkTransformf *transform, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries, hkVector4f *scale)
{
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v5; // rsi
  hkTransformf *v6; // rbp
  hkpShape *v7; // rdi
  hkpShapeDisplayBuilder *v8; // rbx
  hkVector4f v9; // xmm2
  hkpShapeContainer *v10; // rax
  hkBool result; // [rsp+30h] [rbp-98h]
  hkTransformf bTc; // [rsp+40h] [rbp-88h]
  hkTransformf transforma; // [rsp+80h] [rbp-48h]
  hkpShapeDisplayBuilder *v14; // [rsp+D0h] [rbp+8h]

  v14 = this;
  v5 = displayGeometries;
  v6 = transform;
  v7 = shape;
  v8 = this;
  if ( !hkpShapeDisplayBuilder::buildShapeDisplay_UserShapes(this, &result, shape, transform, displayGeometries)->m_bool )
  {
    while ( 2 )
    {
      switch ( v7->m_type.m_storage )
      {
        case 0:
          hkpShapeDisplayBuilder::buildShapeDisplay_Sphere(v8, (hkpSphereShape *)v7, v6, v5, scale);
          return;
        case 1:
          hkpShapeDisplayBuilder::buildShapeDisplay_Cylinder(v8, (hkpCylinderShape *)v7, v6, v5, scale);
          return;
        case 2:
          hkpShapeDisplayBuilder::buildShapeDisplay_Triangle(v8, (hkpTriangleShape *)v7, v6, v5, scale);
          return;
        case 3:
          hkpShapeDisplayBuilder::buildShapeDisplay_Box(v8, (hkpBoxShape *)v7, v6, v5, scale);
          return;
        case 4:
          hkpShapeDisplayBuilder::buildShapeDisplay_Capsule(v8, (hkpCapsuleShape *)v7, v6, v5, scale);
          return;
        case 5:
          hkpShapeDisplayBuilder::buildShapeDisplay_ConvexVertices(v8, (hkpConvexVerticesShape *)v7, v6, v5, scale);
          return;
        case 6:
        case 7:
        case 0x12:
        case 0x16:
        case 0x1A:
        case 0x1B:
          v10 = (hkpShapeContainer *)v7->vfptr[7].__vecDelDtor((hkBaseObject *)&v7->vfptr, 1073741824u);
          hkpShapeDisplayBuilder::buildShapeDisplay_ShapeContainer(v8, v10, v6, v5);
          return;
        case 8:
          hkpShapeDisplayBuilder::buildShapeDisplay_ListShape(v8, (hkpListShape *)v7, v6, v5);
          return;
        case 9:
          v7 = (hkpShape *)v7[2].m_userData;
          scale = 0i64;
          goto LABEL_5;
        case 0xA:
          v9.m_quad = *(__m128 *)&v7[2].vfptr;
          if ( scale )
            v9.m_quad = _mm_mul_ps(v9.m_quad, scale->m_quad);
          bTc.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
          bTc.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
          bTc.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
          bTc.m_translation = (hkVector4f)v9.m_quad;
          hkTransformf::setMul(&transforma, v6, &bTc);
          hkpShapeDisplayBuilder::buildShapeDisplay(v8, *(hkpShape **)&v7[1].m_type.m_storage, &transforma, v5, scale);
          return;
        case 0xB:
          hkQsTransformf::copyToTransformNoScale((hkQsTransformf *)&v7[2], &transforma);
          hkTransformf::setMul(&bTc, v6, &transforma);
          hkpShapeDisplayBuilder::buildShapeDisplay(
            v14,
            *(hkpShape **)&v7[1].m_type.m_storage,
            &bTc,
            v5,
            (hkVector4f *)&v7[3]);
          return;
        case 0xC:
          hkpShapeDisplayBuilder::buildShapeDisplay_SampledHeightField(v8, (hkpSampledHeightFieldShape *)v7, v6, v5);
          return;
        case 0xD:
          hkpShapeDisplayBuilder::buildShapeDisplay_ExtendedMeshShape(v8, (hkpExtendedMeshShape *)v7, v6, v5);
          return;
        case 0xE:
          hkTransformf::setMul(&transforma, v6, (hkTransformf *)&v7[2].m_type);
          hkpShapeDisplayBuilder::buildShapeDisplay(v8, *(hkpShape **)&v7[1].m_memSizeAndFlags, &transforma, v5, 0i64);
          return;
        case 0xF:
          hkpShapeDisplayBuilder::buildShapeDisplay_CompressedMeshShape(v8, (hkpCompressedMeshShape *)v7, v6, v5);
          return;
        case 0x10:
          hkpShapeDisplayBuilder::buildShapeDisplay_StaticCompound(v8, (hkpStaticCompoundShape *)v7, v6, v5, scale);
          return;
        case 0x11:
          hkpShapeDisplayBuilder::buildShapeDisplay_BvCompressedMeshShape(
            v8,
            (hkpBvCompressedMeshShape *)v7,
            v6,
            v5,
            scale);
          return;
        case 0x18:
          hkpShapeDisplayBuilder::buildShapeDisplay_ConvexPiece(v8, (hkpConvexPieceShape *)v7, v6, v5);
          return;
        case 0x19:
          hkpShapeDisplayBuilder::buildShapeDisplay_MultiSphere(v8, (hkpMultiSphereShape *)v7, v6, v5);
          return;
        case 0x1E:
          v7 = (hkpShape *)v7[1].vfptr;
          scale = 0i64;
LABEL_5:
          if ( hkpShapeDisplayBuilder::buildShapeDisplay_UserShapes(v8, &result, v7, v6, v5)->m_bool )
            return;
          continue;
        case 0x1F:
          hkpShapeDisplayBuilder::buildShapeDisplay_Plane(v8, (hkpPlaneShape *)v7, v6, v5);
          break;
        case 0x21:
          hkpShapeDisplayBuilder::buildShapeDisplay_MultiRay(v8, (hkpMultiRayShape *)v7, v6, v5);
          break;
        default:
          hkpShapeDisplayBuilder::buildShapeDisplay_ShapeUnregistered(v8, v7, v6, v5);
          break;
      }
      break;
    }
  }
}

// File Line: 1316
// RVA: 0xE20310
hkBool *__fastcall hkpShapeDisplayBuilder::buildPartialShapeDisplay_MultiSphere(hkpShapeDisplayBuilder *this, hkBool *result, hkpMultiSphereShape *s, hkTransformf *transform, int branchDepth, int *numSimpleShapes, hkpShapeContinueData *continueData, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpMultiSphereShape *v8; // rbp
  hkBool *v9; // r15
  hkpShapeDisplayBuilder *v10; // r13
  int v11; // xmm1_4
  _QWORD **v12; // rax
  hkDisplaySphere *v13; // rax
  hkDisplayGeometry *v14; // rax
  hkDisplayGeometry *v15; // rsi
  hkBool *v16; // rax
  hkSphere sphere; // [rsp+20h] [rbp-28h]

  v8 = s;
  v9 = result;
  v10 = this;
  if ( continueData->m_i == -1 )
    continueData->m_i = 0;
  if ( continueData->m_i < s->m_numSpheres )
  {
    do
    {
      if ( *numSimpleShapes <= 0 )
        break;
      v11 = v8->m_spheres[continueData->m_i].m_quad.m128_i32[3];
      sphere.m_pos.m_quad = aabbOut.m_quad;
      sphere.m_pos.m_quad.m128_i32[3] = v11;
      v12 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v13 = (hkDisplaySphere *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v12[11] + 8i64))(v12[11], 144i64);
      if ( v13 )
      {
        hkDisplaySphere::hkDisplaySphere(
          v13,
          &sphere,
          v10->m_environment.m_sphereThetaRes,
          v10->m_environment.m_spherePhiRes);
        v15 = v14;
      }
      else
      {
        v15 = 0i64;
      }
      v15->m_transform.m_translation = v8->m_spheres[continueData->m_i];
      if ( displayGeometries->m_size == (displayGeometries->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, displayGeometries, 8);
      displayGeometries->m_data[displayGeometries->m_size++] = v15;
      ++continueData->m_i;
      --*numSimpleShapes;
    }
    while ( continueData->m_i < v8->m_numSpheres );
  }
  v16 = v9;
  if ( continueData->m_i == v8->m_numSpheres )
  {
    continueData->m_i = -1;
    v9->m_bool = 1;
  }
  else
  {
    v9->m_bool = 0;
  }
  return v16;
}

// File Line: 1351
// RVA: 0xE20890
hkBool *__fastcall hkpShapeDisplayBuilder::buildPartialShapeDisplay_MultiRay(hkpShapeDisplayBuilder *this, hkBool *result, hkpMultiRayShape *s, hkTransformf *transform, int branchDepth, int *numSimpleShapes, hkpShapeContinueData *continueData, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkBool *v8; // r12
  hkpMultiRayShape *v9; // r15
  hkDisplayGeometry *v10; // rax
  hkpShapeContinueData *v11; // rdi
  signed int *v12; // r13
  hkTransformf *v13; // r12
  int *v14; // r14
  signed int v15; // esi
  hkpMultiRayShape::Ray *v16; // rax
  __int64 v17; // rbp
  signed __int64 v18; // rcx
  int v19; // er9
  __m128 v20; // xmm6
  hkVector4f v21; // xmm7
  int v22; // eax
  int v23; // eax
  hkVector4f *v24; // r8
  __int64 v25; // rbp
  int v26; // er9
  int v27; // eax
  int v28; // eax
  __int64 v29; // rbp
  int v30; // er9
  int v31; // eax
  int v32; // eax
  hkVector4f *v33; // r8
  __int64 v34; // rbp
  int v35; // er9
  int v36; // eax
  int v37; // eax
  _DWORD *v38; // rcx
  int v39; // eax
  hkBool *v40; // rax
  hkResult v41; // [rsp+30h] [rbp-68h]
  hkResult v42; // [rsp+34h] [rbp-64h]
  hkBool *v43; // [rsp+A8h] [rbp+10h]
  hkResult resulta; // [rsp+B0h] [rbp+18h]
  hkTransformf *a; // [rsp+B8h] [rbp+20h]

  a = transform;
  v43 = result;
  v8 = result;
  v9 = s;
  v10 = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries);
  v11 = continueData;
  v12 = (signed int *)v10->m_geometry;
  if ( continueData->m_i == -1 )
    continueData->m_i = 0;
  if ( v11->m_i < v9->m_rays.m_size )
  {
    v13 = a;
    v14 = numSimpleShapes;
    v15 = 2;
    do
    {
      if ( *v14 <= 0 )
        break;
      v16 = v9->m_rays.m_data;
      v17 = v12[6];
      v18 = v11->m_i;
      v19 = v17 + 1;
      v20 = v16[v18].m_start.m_quad;
      v21.m_quad = (__m128)v16[v18].m_end;
      v22 = v12[7] & 0x3FFFFFFF;
      if ( v22 >= (signed int)v17 + 1 )
      {
        LODWORD(continueData) = 0;
      }
      else
      {
        v23 = 2 * v22;
        if ( v19 < v23 )
          v19 = v23;
        hkArrayUtil::_reserve(
          (hkResult *)&continueData,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          v12 + 4,
          v19,
          16);
      }
      ++v12[6];
      v24 = (hkVector4f *)(*((_QWORD *)v12 + 2) + 16 * v17);
      *v24 = (hkVector4f)v20;
      hkVector4f::setTransformedPos(v24, v13, v24);
      v25 = v12[6];
      v26 = v25 + 1;
      v27 = v12[7] & 0x3FFFFFFF;
      if ( v27 >= (signed int)v25 + 1 )
      {
        resulta.m_enum = 0;
      }
      else
      {
        v28 = 2 * v27;
        if ( v26 < v28 )
          v26 = v28;
        hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12 + 4, v26, 16);
      }
      ++v12[6];
      *(__m128 *)(*((_QWORD *)v12 + 2) + 16 * v25) = _mm_add_ps((__m128)_xmm, v20);
      v29 = v12[6];
      v30 = v29 + 1;
      v31 = v12[7] & 0x3FFFFFFF;
      if ( v31 >= (signed int)v29 + 1 )
      {
        v41.m_enum = 0;
      }
      else
      {
        v32 = 2 * v31;
        if ( v30 < v32 )
          v30 = v32;
        hkArrayUtil::_reserve(&v41, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12 + 4, v30, 16);
      }
      ++v12[6];
      v33 = (hkVector4f *)(*((_QWORD *)v12 + 2) + 16 * v29);
      *v33 = (hkVector4f)v21.m_quad;
      hkVector4f::setTransformedPos(v33, v13, v33);
      v34 = v12[10];
      v35 = v34 + 1;
      v36 = v12[11] & 0x3FFFFFFF;
      if ( v36 >= (signed int)v34 + 1 )
      {
        v42.m_enum = 0;
      }
      else
      {
        v37 = 2 * v36;
        if ( v35 < v37 )
          v35 = v37;
        hkArrayUtil::_reserve(&v42, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v12 + 8, v35, 16);
      }
      ++v12[10];
      v38 = (_DWORD *)(*((_QWORD *)v12 + 4) + 16 * v34);
      *v38 = v15 - 2;
      v38[2] = v15;
      v38[3] = -1;
      v39 = v15 - 1;
      v15 += 3;
      v38[1] = v39;
      ++v11->m_i;
      --*v14;
    }
    while ( v11->m_i < v9->m_rays.m_size );
    v8 = v43;
  }
  v40 = v8;
  if ( v11->m_i == v9->m_rays.m_size )
  {
    v11->m_i = -1;
    v8->m_bool = 1;
  }
  else
  {
    v8->m_bool = 0;
  }
  return v40;
}

// File Line: 1412
// RVA: 0xE201A0
hkBool *__fastcall hkpShapeDisplayBuilder::buildPartialShapeDisplay_ShapeContainer(hkpShapeDisplayBuilder *this, hkBool *result, hkpShapeContainer *shapeContainer, hkTransformf *transform, int branchDepth, int *numSimpleShapes, hkpShapeContinueData *continueData, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries, hkVector4f *scale)
{
  hkpShapeContinueData *v9; // rdi
  __int64 v10; // r13
  hkpShapeContainer *v11; // rsi
  hkBool *v12; // r14
  __int64 v13; // rdx
  unsigned int *v14; // rbx
  unsigned int v15; // ebx
  hkVector4f *v16; // r12
  int *v17; // rbp
  hkpShape *v18; // rax
  char v20; // [rsp+50h] [rbp-238h]
  hkpShapeDisplayBuilder *v21; // [rsp+290h] [rbp+8h]
  hkTransformf *transforma; // [rsp+2A8h] [rbp+20h]

  transforma = transform;
  v21 = this;
  v9 = continueData;
  v10 = branchDepth;
  v11 = shapeContainer;
  v12 = result;
  if ( continueData->m_shapeKeys.m_size == branchDepth )
  {
    if ( continueData->m_shapeKeys.m_size == (continueData->m_shapeKeys.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &continueData->m_shapeKeys,
        4);
    v13 = v9->m_shapeKeys.m_size;
    v14 = &v9->m_shapeKeys.m_data[v13];
    v9->m_shapeKeys.m_size = v13 + 1;
    *v14 = v11->vfptr->getFirstKey(v11);
  }
  v15 = v9->m_shapeKeys.m_data[v10];
  if ( v15 != -1 )
  {
    v16 = scale;
    v17 = numSimpleShapes;
    while ( *v17 > 0 )
    {
      v18 = v11->vfptr->getChildShape(v11, v15, (char (*)[512])&v20);
      if ( !hkpShapeDisplayBuilder::buildPartialShapeDisplay(
              v21,
              (hkBool *)&branchDepth,
              v18,
              transforma,
              (signed int)v10 + 1,
              v17,
              v9,
              displayGeometries,
              v16)->m_bool )
        goto LABEL_11;
      v15 = v11->vfptr->getNextKey(v11, v15);
      v9->m_shapeKeys.m_data[v10] = v15;
      if ( v15 == -1 )
        goto LABEL_13;
    }
    if ( v15 != -1 )
    {
LABEL_11:
      v12->m_bool = 0;
      return v12;
    }
  }
LABEL_13:
  --v9->m_shapeKeys.m_size;
  v12->m_bool = 1;
  return v12;
}

// File Line: 1452
// RVA: 0xE20470
hkBool *__usercall hkpShapeDisplayBuilder::buildPartialShapeDisplay_SampledHeightField@<rax>(hkpShapeDisplayBuilder *this@<rcx>, hkBool *result@<rdx>, hkpSampledHeightFieldShape *heightField@<r8>, hkTransformf *transform@<r9>, __m128 a5@<xmm0>, int branchDepth, int *numSimpleShapes, hkpShapeContinueData *continueData, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkBool *v9; // rbx
  hkTransformf *v10; // r12
  hkpSampledHeightFieldShape *v11; // r14
  hkDisplayGeometry *v12; // rax
  hkpShapeContinueData *v13; // rsi
  __m128 v14; // xmm7
  hkGeometry *v15; // r13
  int *v16; // r15
  signed int v17; // er8
  __int64 v18; // rdx
  hkBaseObjectVtbl *v19; // rax
  signed int v20; // edx
  hkBaseObjectVtbl *v21; // rax
  __m128 v22; // xmm1
  int v23; // edx
  signed int v24; // er8
  hkBaseObjectVtbl *v25; // rax
  __m128 v26; // xmm3
  int v27; // edi
  __m128 v28; // xmm4
  int v29; // eax
  int v30; // er9
  __m128 v31; // xmm1
  int v32; // eax
  hkVector4f *v33; // rbx
  __int64 v34; // rbp
  int v35; // eax
  int v36; // er9
  int v37; // eax
  hkGeometry::Triangle *v38; // rcx
  int v39; // eax
  hkGeometry::Triangle *v40; // r8
  hkBool *v41; // rax
  hkResult v42; // [rsp+30h] [rbp-A8h]
  hkResult v43; // [rsp+34h] [rbp-A4h]
  hkVector4f b; // [rsp+40h] [rbp-98h]
  hkVector4f v45; // [rsp+50h] [rbp-88h]
  hkVector4f v46; // [rsp+60h] [rbp-78h]
  hkVector4f v47; // [rsp+70h] [rbp-68h]
  hkBool *v48; // [rsp+E8h] [rbp+10h]
  hkResult resulta; // [rsp+F0h] [rbp+18h]

  v48 = result;
  v9 = result;
  v10 = transform;
  v11 = heightField;
  v12 = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries);
  v13 = continueData;
  v14 = v11->m_intToFloatScale.m_quad;
  v15 = v12->m_geometry;
  if ( continueData->m_i == -1 )
    continueData->m_i = 0;
  if ( v13->m_i >= v11->m_xRes - 1 )
  {
LABEL_32:
    v41 = v9;
    if ( v13->m_i == v11->m_xRes - 1 )
    {
      v13->m_i = -1;
      v9->m_bool = 1;
    }
    else
    {
      v9->m_bool = 0;
    }
  }
  else
  {
    v16 = numSimpleShapes;
    while ( 1 )
    {
      if ( *v16 <= 0 )
      {
LABEL_31:
        v9 = v48;
        goto LABEL_32;
      }
      if ( v13->m_j == -1 )
        v13->m_j = 0;
      for ( ; v13->m_j < v11->m_zRes - 1; --*v16 )
      {
        if ( *v16 <= 0 )
          break;
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v11->vfptr[10].__vecDelDtor)(
          v11,
          (unsigned int)v13->m_i,
          (unsigned int)v13->m_j);
        v17 = v13->m_j;
        v18 = (unsigned int)v13->m_i;
        a5 = _mm_unpacklo_ps(a5, (__m128)0i64);
        v19 = v11->vfptr;
        b.m_quad = _mm_mul_ps(
                     _mm_unpacklo_ps(
                       _mm_unpacklo_ps(
                         (__m128)COERCE_UNSIGNED_INT((float)v13->m_i),
                         (__m128)COERCE_UNSIGNED_INT((float)v17)),
                       a5),
                     v14);
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, __int64, _QWORD))v19[10].__vecDelDtor)(
          v11,
          v18,
          (unsigned int)(v17 + 1));
        v20 = v13->m_i;
        v21 = v11->vfptr;
        v22 = (__m128)COERCE_UNSIGNED_INT((float)v13->m_j);
        v22.m128_f32[0] = v22.m128_f32[0] + 1.0;
        v45.m_quad = _mm_mul_ps(_mm_unpacklo_ps(_mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v20), v22), a5), v14);
        v21[10].__vecDelDtor((hkBaseObject *)&v11->vfptr, v20 + 1);
        v23 = v13->m_i;
        v24 = v13->m_j;
        v25 = v11->vfptr;
        v26 = (__m128)COERCE_UNSIGNED_INT((float)v13->m_i);
        v26.m128_f32[0] = v26.m128_f32[0] + 1.0;
        v46.m_quad = _mm_mul_ps(_mm_unpacklo_ps(_mm_unpacklo_ps(v26, (__m128)COERCE_UNSIGNED_INT((float)v24)), a5), v14);
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v25[10].__vecDelDtor)(
          v11,
          (unsigned int)(v23 + 1),
          (unsigned int)(v24 + 1));
        v27 = v15->m_vertices.m_size;
        v28 = (__m128)COERCE_UNSIGNED_INT((float)v13->m_i);
        v29 = v15->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
        v28.m128_f32[0] = v28.m128_f32[0] + 1.0;
        v30 = v27 + 4;
        v31 = (__m128)COERCE_UNSIGNED_INT((float)v13->m_j);
        v31.m128_f32[0] = v31.m128_f32[0] + 1.0;
        v47.m_quad = _mm_mul_ps(_mm_unpacklo_ps(_mm_unpacklo_ps(v28, v31), a5), v14);
        if ( v29 >= v27 + 4 )
        {
          resulta.m_enum = 0;
        }
        else
        {
          v32 = 2 * v29;
          if ( v30 < v32 )
            v30 = v32;
          hkArrayUtil::_reserve(
            &resulta,
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            &v15->m_vertices,
            v30,
            16);
        }
        v15->m_vertices.m_size += 4;
        v33 = &v15->m_vertices.m_data[v27];
        hkVector4f::setTransformedPos(v33, v10, &b);
        hkVector4f::setTransformedPos(v33 + 1, v10, &v45);
        hkVector4f::setTransformedPos(v33 + 2, v10, &v46);
        hkVector4f::setTransformedPos(v33 + 3, v10, &v47);
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkpShapeContinueData **))v11->vfptr[10].__first_virtual_table_function__)(
          v11,
          &continueData);
        v34 = v15->m_triangles.m_size;
        v35 = v15->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
        v36 = v34 + 2;
        if ( (_BYTE)continueData )
        {
          if ( v35 >= v36 )
          {
            v42.m_enum = 0;
          }
          else
          {
            v37 = 2 * v35;
            if ( v36 < v37 )
              v36 = v37;
            hkArrayUtil::_reserve(
              &v42,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v15->m_triangles,
              v36,
              16);
          }
          v15->m_triangles.m_size += 2;
          v38 = &v15->m_triangles.m_data[v34];
          v38->m_b = v27 + 1;
          v38->m_a = v27;
          v38->m_material = -1;
          v38->m_c = v27 + 3;
          v38[1].m_b = v27 + 3;
          v38[1].m_a = v27;
          v38[1].m_material = -1;
          v38[1].m_c = v27 + 2;
        }
        else
        {
          if ( v35 >= v36 )
          {
            v43.m_enum = 0;
          }
          else
          {
            v39 = 2 * v35;
            if ( v36 < v39 )
              v36 = v39;
            hkArrayUtil::_reserve(
              &v43,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              &v15->m_triangles,
              v36,
              16);
          }
          v15->m_triangles.m_size += 2;
          v40 = &v15->m_triangles.m_data[v34];
          v40->m_a = v27;
          v40->m_b = v27 + 1;
          v40->m_c = v27 + 2;
          v40->m_material = -1;
          v40[1].m_a = v27 + 3;
          v40[1].m_b = v27 + 2;
          v40[1].m_c = v27 + 1;
          v40[1].m_material = -1;
        }
        ++v13->m_j;
      }
      if ( v13->m_j != v11->m_zRes - 1 )
        break;
      ++v13->m_i;
      v13->m_j = -1;
      if ( v13->m_i >= v11->m_xRes - 1 )
        goto LABEL_31;
    }
    v41 = v48;
    v48->m_bool = 0;
  }
  return v41;
}

// File Line: 1544
// RVA: 0xE1FD80
hkBool *__fastcall hkpShapeDisplayBuilder::buildPartialShapeDisplay(hkpShapeDisplayBuilder *this, hkBool *result, hkpShape *shape, hkTransformf *transform, int branchDepth, int *numSimpleShapes, hkpShapeContinueData *continueData, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries, hkVector4f *scale)
{
  hkTransformf *v9; // rsi
  hkpShape *v10; // rdi
  hkpShapeDisplayBuilder *v11; // rbx
  hkBool *v12; // rax
  hkVector4f v13; // xmm2
  hkpShape *v14; // r8
  hkpShapeContainer *v15; // rax
  hkVector4f *v16; // [rsp+40h] [rbp-81h]
  hkBool v17; // [rsp+50h] [rbp-71h]
  hkTransformf bTc; // [rsp+60h] [rbp-61h]
  hkTransformf transforma; // [rsp+A0h] [rbp-21h]
  hkpShapeDisplayBuilder *v20; // [rsp+100h] [rbp+3Fh]
  hkBool *v21; // [rsp+108h] [rbp+47h]
  hkBool resulta; // [rsp+110h] [rbp+4Fh]

  v21 = result;
  v20 = this;
  v9 = transform;
  v10 = shape;
  v11 = this;
  switch ( shape->m_type.m_storage )
  {
    case 0:
      hkpShapeDisplayBuilder::buildShapeDisplay_Sphere(
        this,
        (hkpSphereShape *)shape,
        transform,
        displayGeometries,
        scale);
      goto LABEL_24;
    case 1:
      hkpShapeDisplayBuilder::buildShapeDisplay_Cylinder(
        this,
        (hkpCylinderShape *)shape,
        transform,
        displayGeometries,
        scale);
      goto LABEL_24;
    case 2:
      hkpShapeDisplayBuilder::buildShapeDisplay_Triangle(
        this,
        (hkpTriangleShape *)shape,
        transform,
        displayGeometries,
        scale);
      goto LABEL_24;
    case 3:
      hkpShapeDisplayBuilder::buildShapeDisplay_Box(this, (hkpBoxShape *)shape, transform, displayGeometries, scale);
      goto LABEL_24;
    case 4:
      hkpShapeDisplayBuilder::buildShapeDisplay_Capsule(
        this,
        (hkpCapsuleShape *)shape,
        transform,
        displayGeometries,
        scale);
      goto LABEL_24;
    case 5:
      hkpShapeDisplayBuilder::buildShapeDisplay_ConvexVertices(
        this,
        (hkpConvexVerticesShape *)shape,
        transform,
        displayGeometries,
        scale);
      goto LABEL_24;
    case 6:
    case 7:
    case 8:
    case 0xD:
    case 0xF:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x16:
    case 0x1A:
    case 0x1B:
      v15 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpShape *))shape->vfptr[7].__vecDelDtor)(shape);
      hkpShapeDisplayBuilder::buildPartialShapeDisplay_ShapeContainer(
        v11,
        v21,
        v15,
        v9,
        branchDepth,
        numSimpleShapes,
        continueData,
        displayGeometries,
        scale);
      return v21;
    case 9:
      hkpShapeDisplayBuilder::buildPartialShapeDisplay(
        this,
        result,
        (hkpShape *)shape[2].m_userData,
        transform,
        branchDepth,
        numSimpleShapes,
        continueData,
        displayGeometries,
        0i64);
      return v21;
    case 0xA:
      v13.m_quad = *(__m128 *)&shape[2].vfptr;
      if ( scale )
        v13.m_quad = _mm_mul_ps(v13.m_quad, scale->m_quad);
      bTc.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
      bTc.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
      bTc.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
      bTc.m_translation = (hkVector4f)v13.m_quad;
      hkTransformf::setMul(&transforma, transform, &bTc);
      v14 = *(hkpShape **)&v10[1].m_type.m_storage;
      v16 = scale;
      goto LABEL_12;
    case 0xB:
      hkQsTransformf::copyToTransformNoScale((hkQsTransformf *)&shape[2], &transforma);
      hkTransformf::setMul(&bTc, v9, &transforma);
      hkpShapeDisplayBuilder::buildPartialShapeDisplay(
        v20,
        v21,
        *(hkpShape **)&v10[1].m_type.m_storage,
        &bTc,
        branchDepth,
        numSimpleShapes,
        continueData,
        displayGeometries,
        (hkVector4f *)&v10[3]);
      return v21;
    case 0xC:
      hkpShapeDisplayBuilder::buildPartialShapeDisplay_SampledHeightField(
        this,
        result,
        (hkpSampledHeightFieldShape *)shape,
        transform,
        branchDepth,
        numSimpleShapes,
        continueData,
        displayGeometries);
      return v21;
    case 0xE:
      hkTransformf::setMul(&transforma, transform, (hkTransformf *)&shape[2].m_type);
      v14 = *(hkpShape **)&v10[1].m_memSizeAndFlags;
      v16 = 0i64;
LABEL_12:
      hkpShapeDisplayBuilder::buildPartialShapeDisplay(
        v11,
        v21,
        v14,
        &transforma,
        branchDepth,
        numSimpleShapes,
        continueData,
        displayGeometries,
        v16);
      return v21;
    case 0x18:
      hkpShapeDisplayBuilder::buildShapeDisplay_ConvexPiece(
        this,
        (hkpConvexPieceShape *)shape,
        transform,
        displayGeometries);
      goto LABEL_24;
    case 0x19:
      hkpShapeDisplayBuilder::buildPartialShapeDisplay_MultiSphere(
        this,
        &resulta,
        (hkpMultiSphereShape *)shape,
        transform,
        branchDepth,
        numSimpleShapes,
        continueData,
        displayGeometries);
      goto LABEL_25;
    case 0x1E:
      hkpShapeDisplayBuilder::buildPartialShapeDisplay(
        this,
        result,
        (hkpShape *)shape[1].vfptr,
        transform,
        branchDepth,
        numSimpleShapes,
        continueData,
        displayGeometries,
        0i64);
      return v21;
    case 0x1F:
      hkpShapeDisplayBuilder::buildShapeDisplay_Plane(this, (hkpPlaneShape *)shape, transform, displayGeometries);
      goto LABEL_24;
    case 0x21:
      hkpShapeDisplayBuilder::buildPartialShapeDisplay_MultiRay(
        this,
        result,
        (hkpMultiRayShape *)shape,
        transform,
        branchDepth,
        numSimpleShapes,
        continueData,
        displayGeometries);
      v12 = v21;
      break;
    default:
      if ( hkpShapeDisplayBuilder::buildShapeDisplay_UserShapes(this, &v17, shape, transform, displayGeometries)->m_bool )
LABEL_24:
        --*numSimpleShapes;
LABEL_25:
      v12 = v21;
      v21->m_bool = 1;
      break;
  }
  return v12;
}

// File Line: 1708
// RVA: 0xE1C450
hkReferencedObject *__fastcall hkpShapeDisplayBuilder::getInitialContinueData(hkpShapeDisplayBuilder *this, hkReferencedObject *source)
{
  _QWORD **v2; // rax
  hkReferencedObject *result; // rax

  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkReferencedObject *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(v2[11], 40i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpShapeContinueData::`vftable';
    result[1].vfptr = 0i64;
    *(_DWORD *)&result[1].m_memSizeAndFlags = 0;
    *(_QWORD *)(&result[1].m_referenceCount + 1) = -2147483648i64;
    HIDWORD(result[2].vfptr) = -1;
  }
  return result;
}

// File Line: 1714
// RVA: 0xE1FC60
hkDisplayGeometry *__fastcall hkpShapeDisplayBuilder::getCurrentRawGeometry(hkpShapeDisplayBuilder *this, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v2; // rdi
  hkpShapeDisplayBuilder *v3; // rbp
  _QWORD **v4; // rax
  __int64 v5; // rax
  hkDisplayGeometry *v6; // rsi
  hkGeometry *v7; // rbx
  _QWORD **v8; // rax
  hkDisplayConvex *v9; // rax
  hkDisplayGeometry *v10; // rax

  v2 = displayGeometries;
  v3 = this;
  if ( this->m_currentGeometry )
    return this->m_currentGeometry;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 48i64);
  v6 = 0i64;
  v7 = (hkGeometry *)v5;
  if ( v5 )
  {
    *(_DWORD *)(v5 + 8) = 0x1FFFF;
    *(_QWORD *)v5 = &hkGeometry::`vftable';
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_DWORD *)(v5 + 24) = 0;
    *(_DWORD *)(v5 + 28) = 2147483648;
    *(_QWORD *)(v5 + 32) = 0i64;
    *(_DWORD *)(v5 + 40) = 0;
    *(_DWORD *)(v5 + 44) = 2147483648;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkDisplayConvex *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 112i64);
  if ( v9 )
  {
    hkDisplayConvex::hkDisplayConvex(v9, v7);
    v6 = v10;
  }
  v3->m_currentGeometry = v6;
  if ( v2->m_size == (v2->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v2, 8);
  v2->m_data[v2->m_size++] = v3->m_currentGeometry;
  return v3->m_currentGeometry;
}

// File Line: 1726
// RVA: 0xE1C350
void __fastcall hkpShapeDisplayBuilder::resetCurrentRawGeometry(hkpShapeDisplayBuilder *this)
{
  this->m_currentGeometry = 0i64;
}

// File Line: 1731
// RVA: 0xE20C00
hkReferencedObject *__fastcall hkpUserShapeDisplayBuildercreate()
{
  _QWORD **v0; // rax
  hkReferencedObject *result; // rax

  v0 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkReferencedObject *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v0[11] + 8i64))(v0[11], 32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpUserShapeDisplayBuilder::`vftable';
    result[1].vfptr = 0i64;
    *(_DWORD *)&result[1].m_memSizeAndFlags = 0;
    *(_DWORD *)(&result[1].m_referenceCount + 1) = 2147483648;
  }
  return result;
}

// File Line: 1735
// RVA: 0xE20B70
void __fastcall hkpUserShapeDisplayBuilder::registerUserShapeDisplayBuilder(hkpUserShapeDisplayBuilder *this, void (__fastcall *f)(hkpShape *, hkTransformf *, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *, hkpShapeDisplayBuilder *), hkcdShapeType::ShapeTypeEnum type)
{
  __int64 v3; // r10
  __int64 v4; // r9
  void (__fastcall *v5)(hkpShape *, hkTransformf *, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *, hkpShapeDisplayBuilder *); // rdi
  hkcdShapeType::ShapeTypeEnum *v6; // rax
  signed int *v7; // rbx
  void (__fastcall **v8)(hkpShape *, hkTransformf *, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *, hkpShapeDisplayBuilder *); // rcx
  void (__fastcall *v9)(hkpShape *, hkTransformf *, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *, hkpShapeDisplayBuilder *); // [rsp+28h] [rbp-10h]

  v3 = this->m_userShapeBuilders.m_size;
  v4 = 0i64;
  v5 = f;
  if ( v3 <= 0 )
  {
LABEL_5:
    v7 = (signed int *)&this->m_userShapeBuilders;
    LODWORD(v9) = type;
    if ( this->m_userShapeBuilders.m_size == (this->m_userShapeBuilders.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
    v8 = (void (__fastcall **)(hkpShape *, hkTransformf *, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *, hkpShapeDisplayBuilder *))(*(_QWORD *)v7 + 16i64 * v7[2]);
    if ( v8 )
    {
      *v8 = v5;
      v8[1] = v9;
    }
    ++v7[2];
  }
  else
  {
    v6 = &this->m_userShapeBuilders.m_data->type;
    while ( *v6 != type )
    {
      ++v4;
      v6 += 4;
      if ( v4 >= v3 )
        goto LABEL_5;
    }
  }
}

// File Line: 1752
// RVA: 0xE1BDE0
void __fastcall hkpShapeDisplayBuilder::addObjectToDebugDisplay(hkpShape *shape, hkTransformf *t, unsigned __int64 id)
{
  hkpShape *shapeIdHint; // rbx
  unsigned __int64 v4; // rdi
  hkTransformf *v5; // rsi
  int v6; // eax
  hkDisplayGeometry **v7; // rdx
  int v8; // eax
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> displayGeometries; // [rsp+30h] [rbp-38h]
  hkpShapeDisplayBuilder v10; // [rsp+40h] [rbp-28h]
  hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment env; // [rsp+88h] [rbp+20h]

  shapeIdHint = shape;
  v4 = id;
  v5 = t;
  hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment::hkpShapeDisplayBuilderEnvironment(&env);
  hkpShapeDisplayBuilder::hkpShapeDisplayBuilder(&v10, &env);
  displayGeometries.m_data = 0i64;
  displayGeometries.m_size = 0;
  displayGeometries.m_capacityAndFlags = 2147483648;
  hkpShapeDisplayBuilder::buildDisplayGeometries(&v10, shapeIdHint, &displayGeometries);
  hkDebugDisplay::addGeometry(
    hkSingleton<hkDebugDisplay>::s_instance,
    &displayGeometries,
    v5,
    v4,
    0,
    (unsigned __int64)shapeIdHint);
  v6 = displayGeometries.m_size;
  if ( displayGeometries.m_size )
  {
    while ( 1 )
    {
      v7 = displayGeometries.m_data;
      if ( *displayGeometries.m_data )
      {
        (*displayGeometries.m_data)->vfptr->__vecDelDtor((hkBaseObject *)*displayGeometries.m_data, 1u);
        v6 = displayGeometries.m_size;
        v7 = displayGeometries.m_data;
      }
      v8 = v6 - 1;
      displayGeometries.m_size = v8;
      if ( !v8 )
        break;
      *v7 = v7[v8];
      v6 = displayGeometries.m_size;
      if ( !displayGeometries.m_size )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v7 = displayGeometries.m_data;
  }
  displayGeometries.m_size = 0;
  if ( displayGeometries.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v7,
      8 * displayGeometries.m_capacityAndFlags);
}

// File Line: 1771
// RVA: 0xE1C360
void __fastcall hkpShapeDisplayBuilder::buildDisplayGeometries(hkpShapeDisplayBuilder *this, hkReferencedObject *source, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpShapeDisplayBuilder::buildDisplayGeometries(this, (hkpShape *)source, displayGeometries);
}

// File Line: 1776
// RVA: 0xE1C370
hkBool *__fastcall hkpShapeDisplayBuilder::buildPartialDisplayGeometries(hkpShapeDisplayBuilder *this, hkBool *result, hkReferencedObject *source, int *numSimpleShapes, hkReferencedObject *continueData, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  int *v6; // rbx
  hkpShape *v7; // rdi
  hkBool *v8; // r14
  hkpShapeDisplayBuilder *v9; // rsi
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v10; // ST38_8
  hkTransformf transform; // [rsp+50h] [rbp-48h]

  v6 = numSimpleShapes;
  v7 = (hkpShape *)source;
  v8 = result;
  v9 = this;
  transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
  transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  transform.m_translation = 0i64;
  hkpShapeDisplayBuilder::resetCurrentRawGeometry(this);
  v10 = displayGeometries;
  displayGeometries->m_size = 0;
  if ( hkpShapeDisplayBuilder::buildPartialShapeDisplay(
         v9,
         (hkBool *)&displayGeometries,
         v7,
         &transform,
         0,
         v6,
         (hkpShapeContinueData *)continueData,
         v10,
         0i64)->m_bool )
  {
    hkReferencedObject::removeReference(continueData);
    v8->m_bool = 1;
  }
  else
  {
    v8->m_bool = 0;
  }
  return v8;
}

