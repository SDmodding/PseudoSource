// File Line: 62
// RVA: 0xE1BD10
void __fastcall hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment::hkpShapeDisplayBuilderEnvironment(
        hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment *this)
{
  this->m_spherePhiRes = 8;
  this->m_sphereThetaRes = 8;
}

// File Line: 70
// RVA: 0xE1BD30
void __fastcall hkpShapeDisplayBuilder::hkpShapeDisplayBuilder(
        hkpShapeDisplayBuilder *this,
        hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment *env)
{
  hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment v2; // rax

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkpShapeDisplayBuilder::`vftable;
  v2 = *env;
  this->m_currentGeometry = 0i64;
  this->m_environment = v2;
}

// File Line: 76
// RVA: 0xE1BD60
void __fastcall hkpShapeDisplayBuilder::buildDisplayGeometries(
        hkpShapeDisplayBuilder *this,
        hkpShape *shape,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkTransformf transform; // [rsp+30h] [rbp-48h] BYREF

  transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
  transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  transform.m_translation = 0i64;
  hkpShapeDisplayBuilder::resetCurrentRawGeometry(this);
  displayGeometries->m_size = 0;
  hkpShapeDisplayBuilder::buildShapeDisplay(this, shape, &transform, displayGeometries, 0i64);
}

// File Line: 89
// RVA: 0xE1F1B0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplayTriangleSubPartsCompress(
        hkpShapeDisplayBuilder *this,
        hkpExtendedMeshShape *extendedMeshShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpExtendedMeshShape *v4; // rbx
  hkGeometry *m_geometry; // r13
  __int64 m_size; // rax
  __int64 v7; // rcx
  hkpExtendedMeshShape::TrianglesSubpart *m_data; // r15
  hkQsTransformf *v9; // r15
  int v10; // ecx
  int v11; // eax
  int v12; // r8d
  _DWORD *v13; // rdx
  int v14; // eax
  __int64 v15; // rsi
  __int64 v16; // r12
  int v17; // ebx
  unsigned __int64 *v18; // r14
  int inserted; // eax
  int vfptr; // ecx
  hkVector4f *v21; // rdi
  __int64 v22; // rbx
  int v23; // r9d
  int v24; // eax
  int v25; // eax
  hkGeometry::Triangle *v26; // rcx
  int v27; // eax
  __m128 v28; // xmm2
  __int64 v29; // rsi
  __int64 v30; // r12
  int v31; // ebx
  unsigned __int64 *v32; // r14
  int v33; // eax
  int v34; // ecx
  hkVector4f *v35; // rbx
  __int64 v36; // rbx
  int v37; // r9d
  int v38; // eax
  int v39; // eax
  int v40; // edx
  int v41; // r10d
  int v42; // ecx
  int v43; // r9d
  int v44; // r8d
  int v45; // eax
  hkGeometry::Triangle *v46; // r11
  bool v47; // zf
  __int64 v48; // [rsp+30h] [rbp-59h]
  int v49; // [rsp+38h] [rbp-51h]
  int v50; // [rsp+40h] [rbp-49h]
  int v51; // [rsp+44h] [rbp-45h]
  hkResult v52; // [rsp+48h] [rbp-41h] BYREF
  hkResult result; // [rsp+4Ch] [rbp-3Dh] BYREF
  int v54; // [rsp+50h] [rbp-39h]
  int v55; // [rsp+54h] [rbp-35h]
  int v56; // [rsp+58h] [rbp-31h]
  int v57[3]; // [rsp+5Ch] [rbp-2Dh]
  AMD_HD3D v58; // [rsp+68h] [rbp-21h] BYREF
  __int64 v59; // [rsp+88h] [rbp-1h]
  __int64 v60; // [rsp+90h] [rbp+7h]

  v4 = extendedMeshShape;
  m_geometry = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries)->m_geometry;
  m_size = v4->m_trianglesSubparts.m_size;
  v58.mStereo = 0i64;
  v58.mExtension = (IAmdDxExt *)0xFFFFFFFF00000000i64;
  v60 = m_size;
  if ( m_size <= 0 )
    goto LABEL_39;
  v7 = 0i64;
  v59 = 0i64;
  do
  {
    m_data = v4->m_trianglesSubparts.m_data;
    *(_QWORD *)&v58.mEnableStereo = 0i64;
    v58.mWidth = 0;
    v9 = (hkQsTransformf *)((char *)m_data + v7);
    v58.mHeight = -1;
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
        v17 = m_geometry->m_vertices.m_size;
        v18 = (unsigned __int64 *)(v9->m_scale.m_quad.m128_u64[1]
                                 + v9[1].m_rotation.m_vec.m_quad.m128_u16[0] * *(_DWORD *)((char *)&v48 + v15));
        inserted = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findOrInsertKey(
                     (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v58.mStereo,
                     &hkContainerHeapAllocator::s_alloc,
                     (unsigned __int64)v18,
                     v17);
        vfptr = (int)v58.mStereo[2 * inserted + 1].vfptr;
        *(int *)((char *)&v54 + v15) = vfptr;
        if ( vfptr == v17 )
        {
          if ( m_geometry->m_vertices.m_size == (m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&m_geometry->m_vertices.m_data,
              16);
          v21 = &m_geometry->m_vertices.m_data[m_geometry->m_vertices.m_size++];
          v21->m_quad = _mm_movelh_ps((__m128)*v18, (__m128)*((unsigned int *)v18 + 2));
          hkVector4f::setTransformedPos(v21, v9 + 2, v21);
          hkVector4f::setTransformedPos(v21, transform, v21);
        }
        v15 += 4i64;
        --v16;
      }
      while ( v16 );
      v22 = m_geometry->m_triangles.m_size;
      v23 = v22 + 1;
      v24 = m_geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v24 >= (int)v22 + 1 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        v25 = 2 * v24;
        if ( v23 < v25 )
          v23 = v25;
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&m_geometry->m_triangles.m_data,
          v23,
          16);
      }
      ++m_geometry->m_triangles.m_size;
      v26 = &m_geometry->m_triangles.m_data[v22];
      v26->m_a = v54;
      v27 = v55;
      v26->m_material = -1;
      v26->m_b = v27;
      v26->m_c = v56;
      v28 = _mm_mul_ps(v9[1].m_scale.m_quad, v9[1].m_scale.m_quad);
      if ( (float)((float)(_mm_shuffle_ps(v28, v28, 85).m128_f32[0] + _mm_shuffle_ps(v28, v28, 0).m128_f32[0])
                 + _mm_shuffle_ps(v28, v28, 170).m128_f32[0]) > 0.0 )
      {
        v29 = 0i64;
        v30 = 3i64;
        do
        {
          v31 = m_geometry->m_vertices.m_size;
          v32 = (unsigned __int64 *)(v9->m_scale.m_quad.m128_u64[1]
                                   + v9[1].m_rotation.m_vec.m_quad.m128_u16[0] * *(_DWORD *)((char *)&v48 + v29 * 4));
          v33 = hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findOrInsertKey(
                  (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v58,
                  &hkContainerHeapAllocator::s_alloc,
                  (unsigned __int64)v32,
                  v31);
          v34 = *(_DWORD *)(*(_QWORD *)&v58.mEnableStereo + 16i64 * v33 + 8);
          v57[v29] = v34;
          if ( v34 == v31 )
          {
            if ( m_geometry->m_vertices.m_size == (m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore(
                &hkContainerHeapAllocator::s_alloc,
                (const void **)&m_geometry->m_vertices.m_data,
                16);
            v35 = &m_geometry->m_vertices.m_data[m_geometry->m_vertices.m_size++];
            v35->m_quad = _mm_movelh_ps((__m128)*v32, (__m128)*((unsigned int *)v32 + 2));
            hkVector4f::setTransformedPos(v35, v9 + 2, v35);
            v35->m_quad = _mm_add_ps(v9[1].m_scale.m_quad, v35->m_quad);
            hkVector4f::setTransformedPos(v35, transform, v35);
          }
          ++v29;
          --v30;
        }
        while ( v30 );
        v36 = m_geometry->m_triangles.m_size;
        v37 = v36 + 7;
        v38 = m_geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v38 >= (int)v36 + 7 )
        {
          v52.m_enum = HK_SUCCESS;
        }
        else
        {
          v39 = 2 * v38;
          if ( v37 < v39 )
            v37 = v39;
          hkArrayUtil::_reserve(
            &v52,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&m_geometry->m_triangles.m_data,
            v37,
            16);
        }
        m_geometry->m_triangles.m_size += 7;
        v40 = v57[2];
        v41 = v57[0];
        v42 = v55;
        v43 = v54;
        v44 = v57[1];
        v45 = v56;
        v46 = &m_geometry->m_triangles.m_data[v36];
        v46->m_a = v57[0];
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
    v4 = extendedMeshShape;
LABEL_38:
    hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
      (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v58,
      &hkContainerHeapAllocator::s_alloc);
    _(&v58);
    v7 = v59 + 144;
    v47 = v60-- == 1;
    v59 += 144i64;
  }
  while ( !v47 );
LABEL_39:
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)&v58.mStereo,
    &hkContainerHeapAllocator::s_alloc);
  _((AMD_HD3D *)&v58.mStereo);
}

// File Line: 218
// RVA: 0xE1F6F0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplayTriangleSubPartsStorage(
        hkpShapeDisplayBuilder *this,
        hkpStorageExtendedMeshShape *extendedMeshShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpStorageExtendedMeshShape *v4; // rbx
  hkDisplayGeometry *CurrentRawGeometry; // rax
  __int64 v6; // rcx
  __int64 m_geometry; // r8
  __int64 m_size; // rax
  __int64 v9; // r14
  __int64 v10; // rdx
  __int64 v11; // rdi
  int v12; // esi
  hkQsTransformf *v13; // rbp
  __int64 v14; // rdx
  __int64 v15; // r15
  int v16; // eax
  __m128 v17; // xmm2
  int v18; // r13d
  int v19; // eax
  int v20; // ebx
  int v21; // r9d
  int v22; // eax
  __int64 v23; // r12
  int v24; // r14d
  __int64 v25; // rdi
  __int64 v26; // rcx
  __int64 v27; // rax
  char *v28; // r13
  hkVector4f *v29; // rbx
  __int64 v30; // r14
  __int64 v31; // rdi
  int v32; // ebx
  int v33; // eax
  int v34; // ebx
  int v35; // r9d
  int v36; // eax
  int v37; // ebx
  _DWORD *v38; // rax
  int v39; // r9d
  unsigned __int8 *v40; // r8
  int v41; // r11d
  int v42; // r10d
  int v43; // ecx
  int v44; // r11d
  int v45; // r10d
  int v46; // ecx
  int v47; // edx
  int v48; // r9d
  int v49; // r8d
  int v50; // edx
  int v51; // [rsp+30h] [rbp-A8h]
  hkResult v52; // [rsp+38h] [rbp-A0h] BYREF
  int v53; // [rsp+3Ch] [rbp-9Ch]
  hkResult result; // [rsp+40h] [rbp-98h] BYREF
  __int64 v55; // [rsp+48h] [rbp-90h]
  __int64 v56; // [rsp+50h] [rbp-88h]
  __int64 v57; // [rsp+58h] [rbp-80h]
  __int64 v58; // [rsp+60h] [rbp-78h]
  __int64 v59; // [rsp+68h] [rbp-70h]
  __int64 v60; // [rsp+70h] [rbp-68h]
  __int64 v61; // [rsp+78h] [rbp-60h]
  __int64 v62; // [rsp+80h] [rbp-58h]

  v4 = extendedMeshShape;
  CurrentRawGeometry = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries);
  v6 = 0i64;
  m_geometry = (__int64)CurrentRawGeometry->m_geometry;
  m_size = v4->m_trianglesSubparts.m_size;
  v56 = 0i64;
  v58 = m_geometry;
  v60 = m_size;
  if ( m_size > 0 )
  {
    v9 = m_geometry + 16;
    v10 = 0i64;
    v62 = m_geometry + 16;
    v57 = 0i64;
    while ( 1 )
    {
      v11 = *(int *)(v9 + 8);
      v12 = *(_DWORD *)(m_geometry + 24);
      v13 = (hkQsTransformf *)((char *)v4->m_trianglesSubparts.m_data + v10);
      v14 = (__int64)v4->m_meshstorage.m_data[v6];
      v15 = *(int *)(v14 + 24);
      v16 = *(_DWORD *)(v9 + 12);
      v17 = _mm_mul_ps(v13[1].m_scale.m_quad, v13[1].m_scale.m_quad);
      v18 = 0;
      v55 = v14;
      v53 = v15;
      if ( (float)((float)(_mm_shuffle_ps(v17, v17, 85).m128_f32[0] + _mm_shuffle_ps(v17, v17, 0).m128_f32[0])
                 + _mm_shuffle_ps(v17, v17, 170).m128_f32[0]) > 0.0 )
        v18 = 1;
      v51 = v18;
      v19 = v16 & 0x3FFFFFFF;
      v20 = v15 * ((v18 != 0) + 1);
      v21 = v20 + v11;
      if ( v19 >= v20 + (int)v11 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        v22 = 2 * v19;
        if ( v21 < v22 )
          v21 = v22;
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)v9, v21, 16);
        v14 = v55;
      }
      *(_DWORD *)(v9 + 8) += v20;
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
          hkVector4f::setTransformedPos(v29, v13 + 2, v29);
          hkVector4f::setTransformedPos(v29, transform, v29);
          if ( v51 )
          {
            *(_OWORD *)v25 = *(_OWORD *)&v28[*(_QWORD *)(v55 + 16)];
            hkVector4f::setTransformedPos((hkVector4f *)v25, v13 + 2, (hkVector4f *)v25);
            *(__m128 *)v25 = _mm_add_ps(*(__m128 *)v25, v13[1].m_scale.m_quad);
            hkVector4f::setTransformedPos((hkVector4f *)v25, transform, (hkVector4f *)v25);
          }
          v26 = v59;
          v14 = v55;
          v27 = v61;
          ++v24;
          v25 += 16i64;
          --v15;
        }
        while ( v15 );
        v18 = v51;
      }
      v30 = v58;
      v31 = *(int *)(v58 + 40);
      v32 = 1;
      if ( v18 )
        v32 = 8;
      v33 = *(_DWORD *)(v58 + 44) & 0x3FFFFFFF;
      v34 = v13->m_scale.m_quad.m128_i32[0] * v32;
      v35 = v34 + v31;
      if ( v33 >= v34 + (int)v31 )
      {
        v52.m_enum = HK_SUCCESS;
      }
      else
      {
        v36 = 2 * v33;
        if ( v35 < v36 )
          v35 = v36;
        hkArrayUtil::_reserve(&v52, &hkContainerHeapAllocator::s_alloc, (const void **)(v58 + 32), v35, 16);
      }
      *(_DWORD *)(v30 + 40) += v34;
      v37 = 0;
      v38 = (_DWORD *)(*(_QWORD *)(v30 + 32) + 16 * v31);
      if ( v13->m_scale.m_quad.m128_i32[0] > 0 )
        break;
LABEL_35:
      v9 = v62;
      m_geometry = v58;
      v4 = extendedMeshShape;
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
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplayShapeSubParts(
        hkpShapeDisplayBuilder *this,
        hkpExtendedMeshShape *extendedMeshShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  __int64 m_size; // r12
  hkTransformf *v6; // rbx
  __int64 v9; // r14
  hkpExtendedMeshShape::ShapesSubpart *v10; // rdi
  __int64 v11; // rsi
  __int64 i; // rbx
  hkTransformf v13; // [rsp+30h] [rbp-A8h] BYREF
  hkTransformf transforma; // [rsp+70h] [rbp-68h] BYREF

  m_size = extendedMeshShape->m_shapesSubparts.m_size;
  v6 = transform;
  if ( m_size > 0 )
  {
    v9 = 0i64;
    do
    {
      v10 = &extendedMeshShape->m_shapesSubparts.m_data[v9];
      hkRotationf::set(&v13.m_rotation, &v10->m_rotation);
      v13.m_translation = v10->m_translation;
      hkTransformf::setMul(&transforma, v6, &v13);
      v11 = v10->m_childShapes.m_size;
      for ( i = 0i64; i < v11; ++i )
        hkpShapeDisplayBuilder::buildShapeDisplay(
          this,
          v10->m_childShapes.m_data[i].m_pntr,
          &transforma,
          displayGeometries,
          0i64);
      v6 = transform;
      ++v9;
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 352
// RVA: 0xE1DB50
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_ExtendedMeshShape(
        hkpShapeDisplayBuilder *this,
        hkpStorageExtendedMeshShape *extendedMeshShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  __int64 v8; // rax
  hkpShapeContainer *v9; // rdx

  v8 = ((__int64 (__fastcall *)(hkBuiltinTypeRegistry *))hkSingleton<hkBuiltinTypeRegistry>::s_instance->vfptr[2].__first_virtual_table_function__)(hkSingleton<hkBuiltinTypeRegistry>::s_instance);
  if ( (hkClass *)(*(__int64 (__fastcall **)(__int64, hkpStorageExtendedMeshShape *))(*(_QWORD *)v8 + 40i64))(
                    v8,
                    extendedMeshShape) == &hkpStorageExtendedMeshShapeClass )
  {
    hkpShapeDisplayBuilder::buildShapeDisplayTriangleSubPartsStorage(
      this,
      extendedMeshShape,
      transform,
      displayGeometries);
    hkpShapeDisplayBuilder::buildShapeDisplayShapeSubParts(this, extendedMeshShape, transform, displayGeometries);
  }
  else
  {
    if ( extendedMeshShape )
      v9 = &extendedMeshShape->hkpShapeContainer;
    else
      v9 = 0i64;
    hkpShapeDisplayBuilder::buildShapeDisplay_ShapeContainer(this, v9, transform, displayGeometries);
  }
}

// File Line: 377
// RVA: 0xE1DA00
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_BvCompressedMeshShape(
        hkpShapeDisplayBuilder *this,
        hkpBvCompressedMeshShape *bvCompressedMeshShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries,
        hkVector4f *scale)
{
  hkGeometry *m_geometry; // rsi
  hkGeometry geometryOut; // [rsp+20h] [rbp-51h] BYREF
  hkQsTransformf qst; // [rsp+50h] [rbp-21h] BYREF
  hkMatrix4f transforma; // [rsp+80h] [rbp+Fh] BYREF

  m_geometry = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries)->m_geometry;
  *(_DWORD *)&geometryOut.m_memSizeAndFlags = 0x1FFFF;
  geometryOut.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  geometryOut.m_vertices.m_data = 0i64;
  geometryOut.m_vertices.m_size = 0;
  geometryOut.m_vertices.m_capacityAndFlags = 0x80000000;
  geometryOut.m_triangles.m_data = 0i64;
  geometryOut.m_triangles.m_size = 0;
  geometryOut.m_triangles.m_capacityAndFlags = 0x80000000;
  hkpBvCompressedMeshShape::convertToGeometry(bvCompressedMeshShape, &geometryOut, 0i64, 0i64);
  hkQsTransformf::setFromTransformNoScale(&qst, transform);
  if ( scale )
    qst.m_scale = (hkVector4f)scale->m_quad;
  hkMatrix4f::set(&transforma, &qst);
  hkGeometryUtils::transformGeometry(&transforma, &geometryOut);
  hkGeometryUtils::appendGeometry(&geometryOut, m_geometry);
  geometryOut.m_triangles.m_size = 0;
  if ( geometryOut.m_triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      geometryOut.m_triangles.m_data,
      16 * geometryOut.m_triangles.m_capacityAndFlags);
  geometryOut.m_triangles.m_data = 0i64;
  geometryOut.m_triangles.m_capacityAndFlags = 0x80000000;
  geometryOut.m_vertices.m_size = 0;
  if ( geometryOut.m_vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      geometryOut.m_vertices.m_data,
      16 * geometryOut.m_vertices.m_capacityAndFlags);
}

// File Line: 407
// RVA: 0xE1D250
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_CompressedMeshShape(
        hkpShapeDisplayBuilder *this,
        hkpCompressedMeshShape *compressedMeshShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpCompressedMeshShape *v4; // rsi
  hkTransformf *v5; // r12
  hkDisplayGeometry *CurrentRawGeometry; // rax
  __int64 m_size; // rbx
  __int64 m_geometry; // r14
  __int64 v9; // rdi
  __int64 v10; // r13
  int v11; // eax
  int v12; // r9d
  int v13; // eax
  __int64 v14; // rdi
  __int64 v15; // r15
  __int64 v16; // rbx
  __int64 v17; // r14
  hkVector4f *m_data; // rcx
  hkpCompressedMeshShape::BigTriangle *v19; // rdx
  unsigned __int16 m_transformIndex; // ax
  int v21; // esi
  __int64 v22; // rax
  int v23; // ecx
  unsigned __int64 v24; // r15
  unsigned __int64 v25; // rax
  hkpCompressedMeshShape::Chunk *v26; // rdx
  hkResultEnum m_enum; // edi
  __int64 v28; // rsi
  char *v29; // r13
  int v30; // eax
  hkpCompressedMeshShape::Chunk *v31; // rbx
  int v32; // eax
  int v33; // r14d
  int v34; // r9d
  int v35; // eax
  hkVector4f *v36; // rsi
  __int64 v37; // r15
  __int64 v38; // r14
  unsigned __int16 v39; // ax
  int NumTriangles; // eax
  __int64 v41; // r14
  int v42; // r9d
  int v43; // ecx
  int v44; // esi
  int v45; // ecx
  int v46; // r11d
  __int64 v47; // r12
  __int64 v48; // r10
  int v49; // r14d
  __int64 v50; // rax
  __int64 v51; // r10
  __int64 i; // r15
  int v53; // esi
  char v54; // r8
  __int64 v55; // r9
  int v56; // r8d
  __int64 v57; // rdx
  __int64 v58; // r10
  __int64 v59; // rdx
  int v60; // ecx
  bool v61; // zf
  int v62; // r12d
  __int64 v63; // rbx
  unsigned __int64 v64; // r15
  int v65; // esi
  __int64 v66; // r14
  __int64 v67; // rbx
  int v68; // r9d
  int v69; // eax
  int v70; // eax
  __int64 v71; // rdi
  __int64 v72; // rbx
  __int64 v73; // rbx
  __int64 v74; // rdi
  int v75; // r9d
  int v76; // eax
  int v77; // eax
  __int64 v78; // r9
  __int64 v79; // rdx
  __int64 v80; // r8
  hkResult result; // [rsp+30h] [rbp-69h] BYREF
  hkResult v82; // [rsp+34h] [rbp-65h] BYREF
  hkResult v83; // [rsp+38h] [rbp-61h] BYREF
  __int64 v84; // [rsp+40h] [rbp-59h]
  int v85; // [rsp+48h] [rbp-51h]
  __int64 v86; // [rsp+50h] [rbp-49h]
  hkVector4f b; // [rsp+60h] [rbp-39h] BYREF
  hkQsTransformf a; // [rsp+70h] [rbp-29h] BYREF
  hkVector4f v89; // [rsp+A0h] [rbp+7h] BYREF
  hkVector4f v90; // [rsp+B0h] [rbp+17h] BYREF

  v4 = compressedMeshShape;
  v5 = transform;
  CurrentRawGeometry = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries);
  m_size = v4->m_bigTriangles.m_size;
  m_geometry = (__int64)CurrentRawGeometry->m_geometry;
  v9 = *(int *)(m_geometry + 40);
  v10 = m_geometry + 32;
  v11 = *(_DWORD *)(m_geometry + 44) & 0x3FFFFFFF;
  v12 = v9 + m_size;
  v84 = m_geometry;
  v86 = m_geometry + 32;
  if ( v11 < (int)v9 + (int)m_size )
  {
    v13 = 2 * v11;
    if ( v12 < v13 )
      v12 = v13;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)(m_geometry + 32), v12, 16);
  }
  *(_DWORD *)(m_geometry + 40) += m_size;
  v14 = *(_QWORD *)v10 + 16 * v9;
  v15 = m_size;
  if ( (int)m_size > 0 )
  {
    v16 = m_geometry + 16;
    v17 = 0i64;
    do
    {
      m_data = compressedMeshShape->m_bigVertices.m_data;
      v19 = &compressedMeshShape->m_bigTriangles.m_data[v17];
      b.m_quad = (__m128)m_data[v19->m_a];
      v89.m_quad = (__m128)m_data[v19->m_b];
      v90.m_quad = (__m128)m_data[v19->m_c];
      m_transformIndex = v19->m_transformIndex;
      if ( m_transformIndex != 0xFFFF )
      {
        a = compressedMeshShape->m_transforms.m_data[m_transformIndex];
        hkVector4f::setTransformedPos(&b, &a, &b);
        hkVector4f::setTransformedPos(&v89, &a, &v89);
        hkVector4f::setTransformedPos(&v90, &a, &v90);
      }
      hkVector4f::setTransformedPos(&b, v5, &b);
      hkVector4f::setTransformedPos(&v89, v5, &v89);
      hkVector4f::setTransformedPos(&v90, v5, &v90);
      v21 = *(_DWORD *)(v84 + 24);
      if ( *(_DWORD *)(v16 + 8) == (*(_DWORD *)(v16 + 12) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v16, 16);
      *(hkVector4f *)(*(_QWORD *)v16 + 16i64 * (int)(*(_DWORD *)(v16 + 8))++) = (hkVector4f)b.m_quad;
      if ( *(_DWORD *)(v16 + 8) == (*(_DWORD *)(v16 + 12) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v16, 16);
      *(hkVector4f *)(*(_QWORD *)v16 + 16i64 * (int)(*(_DWORD *)(v16 + 8))++) = (hkVector4f)v89.m_quad;
      if ( *(_DWORD *)(v16 + 8) == (*(_DWORD *)(v16 + 12) & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)v16, 16);
      v14 += 16i64;
      ++v17;
      *(hkVector4f *)(*(_QWORD *)v16 + 16i64 * (int)(*(_DWORD *)(v16 + 8))++) = (hkVector4f)v90.m_quad;
      *(_DWORD *)(v14 - 12) = v21 + 1;
      *(_DWORD *)(v14 - 16) = v21;
      *(_DWORD *)(v14 - 8) = v21 + 2;
      --v15;
    }
    while ( v15 );
    v10 = v86;
    v4 = compressedMeshShape;
    m_geometry = v84;
  }
  v22 = v4->m_chunks.m_size;
  v23 = 0;
  v85 = 0;
  v86 = v22;
  if ( v22 > 0 )
  {
    v24 = m_geometry + 16;
    v25 = 0i64;
    b.m_quad.m128_u64[0] = m_geometry + 16;
    v89.m_quad.m128_u64[0] = 0i64;
    while ( 1 )
    {
      v26 = v4->m_chunks.m_data;
      m_enum = *(_DWORD *)(m_geometry + 24);
      v28 = *(int *)(v24 + 8);
      v29 = (char *)v26 + v25;
      v83.m_enum = m_enum;
      v30 = *(unsigned __int16 *)((char *)&v26->m_reference + v25);
      if ( v30 != 0xFFFF )
        v23 = v30;
      v31 = &v26[v23];
      v32 = *(_DWORD *)(v24 + 12) & 0x3FFFFFFF;
      v33 = v31->m_vertices.m_size / 3;
      v34 = v28 + v33;
      if ( v32 >= (int)v28 + v33 )
      {
        v82.m_enum = HK_SUCCESS;
      }
      else
      {
        v35 = 2 * v32;
        if ( v34 < v35 )
          v34 = v35;
        hkArrayUtil::_reserve(&v82, &hkContainerHeapAllocator::s_alloc, (const void **)v24, v34, 16);
      }
      *(_DWORD *)(v24 + 8) += v33;
      v36 = (hkVector4f *)(*(_QWORD *)v24 + 16 * v28);
      v37 = v33;
      if ( v33 > 0 )
      {
        v38 = 0i64;
        do
        {
          v36->m_quad = _mm_add_ps(
                          _mm_mul_ps(
                            _mm_cvtepi32_ps(
                              _mm_unpacklo_epi32(
                                _mm_unpacklo_epi32(
                                  _mm_cvtsi32_si128(v31->m_vertices.m_data[v38]),
                                  _mm_cvtsi32_si128(v31->m_vertices.m_data[v38 + 2])),
                                _mm_unpacklo_epi32(
                                  _mm_cvtsi32_si128(v31->m_vertices.m_data[v38 + 1]),
                                  _mm_cvtsi32_si128(0)))),
                            _mm_shuffle_ps(
                              (__m128)LODWORD(compressedMeshShape->m_error),
                              (__m128)LODWORD(compressedMeshShape->m_error),
                              0)),
                          v31->m_offset.m_quad);
          v39 = *((_WORD *)v29 + 43);
          if ( v39 != 0xFFFF )
            hkVector4f::setTransformedPos(v36, &compressedMeshShape->m_transforms.m_data[v39], v36);
          hkVector4f::setTransformedPos(v36, v5, v36);
          ++v36;
          v38 += 3i64;
          --v37;
        }
        while ( v37 );
        m_enum = v83.m_enum;
      }
      NumTriangles = hkpCompressedMeshShape::Chunk::getNumTriangles(v31);
      v41 = *(int *)(v84 + 40);
      v10 = v84 + 32;
      v42 = v41 + NumTriangles;
      v43 = *(_DWORD *)(v84 + 44) & 0x3FFFFFFF;
      v44 = NumTriangles;
      if ( v43 >= (int)v41 + NumTriangles )
      {
        v46 = 0;
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        v45 = 2 * v43;
        if ( v42 < v45 )
          v42 = v45;
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)(v84 + 32), v42, 16);
        v46 = 0;
      }
      *(_DWORD *)(v10 + 8) += v44;
      v47 = v31->m_stripLengths.m_size;
      v48 = 16 * v41;
      v49 = 0;
      v50 = 0i64;
      v51 = *(_QWORD *)v10 + v48;
      for ( i = 0i64; i < v47; v46 = 0 )
      {
        v53 = v31->m_stripLengths.m_data[i] - 2;
        if ( v53 > 0 )
        {
          v49 += v53;
          do
          {
            v54 = v46++;
            v51 += 16i64;
            v55 = v54 & 1;
            *(_DWORD *)(v51 - 16) = m_enum + v31->m_indices.m_data[v50];
            v56 = v31->m_indices.m_data[v55 + 1 + v50];
            v57 = v50++;
            *(_DWORD *)(v51 - 12) = m_enum + v56;
            *(_DWORD *)(v51 - 8) = m_enum + v31->m_indices.m_data[v57 - v55 + 2];
          }
          while ( v46 < v53 );
        }
        ++i;
        v49 += 2;
        v50 += 2i64;
      }
      if ( v49 < v31->m_indices.m_size - 2 )
      {
        v58 = v51 + 8;
        v59 = v50;
        do
        {
          v49 += 3;
          v58 += 16i64;
          v60 = v31->m_indices.m_data[v59];
          v59 += 3i64;
          *(_DWORD *)(v58 - 24) = m_enum + v60;
          *(_DWORD *)(v58 - 20) = m_enum + v31->m_indices.m_data[v59 - 2];
          *(_DWORD *)(v58 - 16) = m_enum + v31->m_indices.m_data[v59 - 1];
        }
        while ( v49 < v31->m_indices.m_size - 2 );
      }
      v5 = transform;
      v4 = compressedMeshShape;
      v24 = b.m_quad.m128_u64[0];
      v23 = v85 + 1;
      v25 = v89.m_quad.m128_u64[0] + 96;
      v61 = v86-- == 1;
      ++v85;
      v89.m_quad.m128_u64[0] += 96i64;
      if ( v61 )
        break;
      m_geometry = v84;
    }
  }
  v62 = 0;
  v82.m_enum = v4->m_convexPieces.m_size;
  if ( v82.m_enum > HK_SUCCESS )
  {
    v63 = v84;
    v64 = v84 + 16;
    b.m_quad.m128_u64[0] = v84 + 16;
    do
    {
      a.m_translation.m_quad.m128_i32[2] = 0x1FFFF;
      a.m_translation.m_quad.m128_u64[0] = (unsigned __int64)&hkGeometry::`vftable;
      a.m_rotation.m_vec.m_quad.m128_u64[0] = 0i64;
      a.m_rotation.m_vec.m_quad.m128_u64[1] = 0x8000000000000000ui64;
      a.m_scale.m_quad.m128_u64[0] = 0i64;
      a.m_scale.m_quad.m128_u64[1] = 0x8000000000000000ui64;
      hkpCompressedMeshShapeBuilder::convexPieceToGeometry(v4, v62, (hkGeometry *)&a);
      v65 = *(_DWORD *)(v63 + 24);
      v66 = a.m_rotation.m_vec.m_quad.m128_u32[2];
      v67 = *(int *)(v64 + 8);
      v68 = a.m_rotation.m_vec.m_quad.m128_i32[2] + v67;
      v69 = *(_DWORD *)(v64 + 12) & 0x3FFFFFFF;
      if ( v69 >= a.m_rotation.m_vec.m_quad.m128_i32[2] + (int)v67 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        v70 = 2 * v69;
        if ( v68 < v70 )
          v68 = v70;
        hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)v64, v68, 16);
      }
      *(_DWORD *)(v64 + 8) += v66;
      v71 = *(_QWORD *)v64 + 16 * v67;
      if ( (int)v66 > 0 )
      {
        v72 = 0i64;
        do
        {
          hkVector4f::setTransformedPos(
            (hkVector4f *)(v72 + v71),
            transform,
            (hkVector4f *)(v72 + a.m_rotation.m_vec.m_quad.m128_u64[0]));
          v72 += 16i64;
          --v66;
        }
        while ( v66 );
        v64 = b.m_quad.m128_u64[0];
      }
      v73 = a.m_scale.m_quad.m128_i32[2];
      v74 = *(int *)(v10 + 8);
      v75 = a.m_scale.m_quad.m128_i32[2] + v74;
      v76 = *(_DWORD *)(v10 + 12) & 0x3FFFFFFF;
      if ( v76 >= a.m_scale.m_quad.m128_i32[2] + (int)v74 )
      {
        v83.m_enum = HK_SUCCESS;
      }
      else
      {
        v77 = 2 * v76;
        if ( v75 < v77 )
          v75 = v77;
        hkArrayUtil::_reserve(&v83, &hkContainerHeapAllocator::s_alloc, (const void **)v10, v75, 16);
      }
      *(_DWORD *)(v10 + 8) += v73;
      v78 = v73;
      v79 = *(_QWORD *)v10 + 16 * v74;
      if ( (int)v73 > 0 )
      {
        v80 = 0i64;
        do
        {
          v79 += 16i64;
          v80 += 16i64;
          *(_DWORD *)(v79 - 16) = v65 + *(_DWORD *)(a.m_scale.m_quad.m128_u64[0] + v80 - 16);
          *(_DWORD *)(v79 - 12) = v65 + *(_DWORD *)(a.m_scale.m_quad.m128_u64[0] + v80 - 12);
          *(_DWORD *)(v79 - 8) = v65 + *(_DWORD *)(a.m_scale.m_quad.m128_u64[0] + v80 - 8);
          --v78;
        }
        while ( v78 );
      }
      a.m_scale.m_quad.m128_i32[2] = 0;
      if ( a.m_scale.m_quad.m128_i32[3] >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          a.m_scale.m_quad.m128_u64[0],
          (unsigned int)(16 * a.m_scale.m_quad.m128_i32[3]),
          v78);
      a.m_scale.m_quad.m128_u64[0] = 0i64;
      a.m_scale.m_quad.m128_i32[3] = 0x80000000;
      a.m_rotation.m_vec.m_quad.m128_i32[2] = 0;
      if ( a.m_rotation.m_vec.m_quad.m128_i32[3] >= 0 )
        ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
          &hkContainerHeapAllocator::s_alloc,
          a.m_rotation.m_vec.m_quad.m128_u64[0],
          (unsigned int)(16 * a.m_rotation.m_vec.m_quad.m128_i32[3]),
          v78);
      v4 = compressedMeshShape;
      v63 = v84;
      ++v62;
    }
    while ( v62 < v82.m_enum );
  }
}

// File Line: 545
// RVA: 0xE1DBF0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_SampledHeightField(
        hkpShapeDisplayBuilder *this,
        hkpSampledHeightFieldShape *heightField,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  __m128 v4; // xmm0
  hkDisplayGeometry *CurrentRawGeometry; // rax
  hkVector4f v8; // xmm7
  hkGeometry *m_geometry; // rsi
  int v10; // edi
  int m_size; // r13d
  int v12; // eax
  int v13; // r9d
  int v14; // eax
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *p_m_triangles; // rdi
  __int64 v16; // rbp
  __int64 v17; // rsi
  int v18; // ebx
  int v19; // r9d
  int v20; // eax
  int v21; // eax
  __int64 v22; // rbx
  int v23; // edi
  int m_zRes; // eax
  int i; // esi
  hkVector4f *v26; // rcx
  int j; // ebp
  int v28; // eax
  int v29; // esi
  int v30; // edi
  int v31; // r12d
  int v32; // r14d
  int v33; // r13d
  int v34; // r9d
  int v35; // r8d
  bool v36; // zf
  __int64 v37; // rcx
  int v38; // edx
  int v39; // [rsp+30h] [rbp-68h]
  hkResult v40; // [rsp+34h] [rbp-64h] BYREF
  hkVector4f b; // [rsp+40h] [rbp-58h] BYREF
  hkResult result; // [rsp+A8h] [rbp+10h] BYREF

  CurrentRawGeometry = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries);
  v8.m_quad = (__m128)heightField->m_intToFloatScale;
  m_geometry = CurrentRawGeometry->m_geometry;
  v10 = heightField->m_zRes * heightField->m_xRes;
  m_size = m_geometry->m_vertices.m_size;
  v12 = m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  v39 = m_size;
  v13 = m_size + v10;
  if ( v12 >= m_size + v10 )
  {
    result.m_enum = HK_SUCCESS;
  }
  else
  {
    v14 = 2 * v12;
    if ( v13 < v14 )
      v13 = v14;
    hkArrayUtil::_reserve(
      &result,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&m_geometry->m_vertices.m_data,
      v13,
      16);
  }
  m_geometry->m_vertices.m_size += v10;
  p_m_triangles = &m_geometry->m_triangles;
  v16 = (__int64)&m_geometry->m_vertices.m_data[m_size];
  v17 = m_geometry->m_triangles.m_size;
  v18 = (heightField->m_xRes - 1) * (2 * heightField->m_zRes - 2);
  v19 = v17 + v18;
  v20 = p_m_triangles->m_capacityAndFlags & 0x3FFFFFFF;
  if ( v20 < (int)v17 + v18 )
  {
    v21 = 2 * v20;
    if ( v19 < v21 )
      v19 = v21;
    hkArrayUtil::_reserve(&v40, &hkContainerHeapAllocator::s_alloc, (const void **)&p_m_triangles->m_data, v19, 16);
  }
  p_m_triangles->m_size += v18;
  v22 = (__int64)&p_m_triangles->m_data[v17];
  v23 = 0;
  if ( heightField->m_xRes > 0 )
  {
    m_zRes = heightField->m_zRes;
    do
    {
      for ( i = 0; i < m_zRes; ++i )
      {
        *(double *)v4.m128_u64 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))heightField->vfptr[10].__vecDelDtor)(
                                   heightField,
                                   (unsigned int)v23,
                                   (unsigned int)i);
        v4 = _mm_unpacklo_ps(v4, (__m128)0i64);
        v26 = (hkVector4f *)(v16 + 16i64 * (i + heightField->m_zRes * v23));
        b.m_quad = _mm_mul_ps(
                     _mm_unpacklo_ps(
                       _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v23), (__m128)COERCE_UNSIGNED_INT((float)i)),
                       v4),
                     v8.m_quad);
        hkVector4f::setTransformedPos(v26, transform, &b);
        m_zRes = heightField->m_zRes;
      }
      ++v23;
    }
    while ( v23 < heightField->m_xRes );
  }
  for ( j = 0; j < heightField->m_xRes - 1; ++j )
  {
    v28 = heightField->m_zRes;
    v29 = 0;
    v30 = v28 - 1;
    if ( v28 - 1 > 0 )
    {
      v31 = 0;
      do
      {
        v32 = m_size + j * v28;
        v33 = v28 + v32;
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkResult *))heightField->vfptr[10].__first_virtual_table_function__)(
          heightField,
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
        m_size = v39;
        *(_DWORD *)(v22 + 8 * v37 + 12) = -1;
        *(_DWORD *)(v22 + 8 * v37 + 8) = v35;
        v28 = heightField->m_zRes;
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
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_ShapeUnregistered(
        hkpShapeDisplayBuilder *this,
        hkpShape *shape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  __int64 v6; // r8
  int v7; // esi
  __m128 v8; // xmm6
  __m128 v9; // xmm9
  __m128 v10; // xmm8
  __m128 v11; // xmm11
  __m128 v12; // xmm9
  __m128 v13; // xmm10
  __m128 v14; // xmm12
  _QWORD **Value; // rax
  hkDisplayBox *v16; // rax
  hkDisplayGeometry *v17; // rax
  hkDisplayGeometry *v18; // rbx
  __m128 *v19; // rcx
  __m128 *v20; // rax
  __m128 v21; // xmm4
  int v22; // esi
  _QWORD **v23; // rax
  hkDisplayBox *v24; // rax
  hkDisplayGeometry *v25; // rax
  hkDisplayGeometry *v26; // rbx
  __m128 *v27; // rcx
  __m128 *v28; // rax
  __m128 v29; // xmm4
  int v30; // esi
  __m128 v31; // xmm0
  __m128 v32; // xmm9
  _QWORD **v33; // rax
  hkDisplayBox *v34; // rax
  hkDisplayGeometry *v35; // rax
  hkDisplayGeometry *v36; // rbx
  __m128 *v37; // rcx
  __m128 *v38; // rax
  __m128 v39; // xmm3
  __m128 v40; // [rsp+20h] [rbp-D8h] BYREF
  hkVector4f halfExtents; // [rsp+30h] [rbp-C8h] BYREF
  hkErrStream v42; // [rsp+40h] [rbp-B8h] BYREF
  __m128 v43; // [rsp+60h] [rbp-98h] BYREF
  _QWORD v44[5]; // [rsp+70h] [rbp-88h] BYREF
  char buf[8]; // [rsp+98h] [rbp-60h] BYREF
  char v46[624]; // [rsp+A0h] [rbp-58h] BYREF

  hkErrStream::hkErrStream(&v42, v46, 512);
  hkOstream::operator<<(&v42, "Shape type unsupported. Using current aabb for display geometry");
  hkError::messageReport(0xFFFFFFFF, buf, "VisualDebugger\\Viewer\\hkpShapeDisplayBuilder.cpp", 593);
  hkOstream::~hkOstream(&v42);
  ((void (__fastcall *)(hkpShape *, hkVector4f *, __int64, _QWORD *))shape->vfptr[2].__vecDelDtor)(
    shape,
    &::transform,
    v6,
    &v44[1]);
  v7 = 0;
  v8 = _mm_sub_ps(*(__m128 *)&v44[3], *(__m128 *)&v44[1]);
  v9 = _mm_mul_ps(v8, (__m128)xmmword_141A711B0);
  v10 = _mm_shuffle_ps(v9, v9, 0);
  v11 = _mm_shuffle_ps(v9, v9, 85);
  v12 = _mm_shuffle_ps(v9, v9, 170);
  v13 = _mm_mul_ps(_mm_min_ps(v12, _mm_min_ps(v11, v10)), (__m128)xmmword_141A711F0);
  v14 = _mm_unpacklo_ps(v13, v13);
  halfExtents.m_quad = _mm_movelh_ps(_mm_unpacklo_ps(_mm_add_ps(v13, v10), v13), v14);
  do
  {
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v16 = (hkDisplayBox *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 128i64);
    if ( v16 )
    {
      hkDisplayBox::hkDisplayBox(v16, &halfExtents);
      v18 = v17;
    }
    else
    {
      v18 = 0i64;
    }
    if ( (v7 & 2) != 0 )
    {
      v19 = (__m128 *)v44;
      *(__m128 *)v44 = _mm_shuffle_ps(v8, v8, 170);
    }
    else
    {
      v43 = 0i64;
      v19 = &v43;
    }
    if ( (v7 & 1) != 0 )
    {
      v20 = &v40;
      v40 = _mm_shuffle_ps(v8, v8, 85);
    }
    else
    {
      v42.hkReferencedObject = 0i64;
      v20 = (__m128 *)&v42;
    }
    v21 = _mm_add_ps(_mm_movelh_ps(_mm_unpacklo_ps(v10, *v20), _mm_unpacklo_ps(*v19, (__m128)0i64)), *(__m128 *)&v44[1]);
    v18->m_transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
    v18->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    v18->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    v18->m_transform.m_translation.m_quad = v21;
    if ( displayGeometries->m_size == (displayGeometries->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&displayGeometries->m_data, 8);
    ++v7;
    displayGeometries->m_data[displayGeometries->m_size++] = v18;
  }
  while ( v7 < 4 );
  v22 = 0;
  halfExtents.m_quad = _mm_movelh_ps(_mm_unpacklo_ps(v13, _mm_add_ps(v13, v11)), v14);
  do
  {
    v23 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v24 = (hkDisplayBox *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v23[11] + 8i64))(v23[11], 128i64);
    if ( v24 )
    {
      hkDisplayBox::hkDisplayBox(v24, &halfExtents);
      v26 = v25;
    }
    else
    {
      v26 = 0i64;
    }
    if ( (v22 & 2) != 0 )
    {
      v27 = (__m128 *)&v42;
      v42.hkReferencedObject = (hkReferencedObject)_mm_shuffle_ps(v8, v8, 170);
    }
    else
    {
      v40 = 0i64;
      v27 = &v40;
    }
    if ( (v22 & 1) != 0 )
    {
      v28 = &v43;
      v43 = _mm_shuffle_ps(v8, v8, 0);
    }
    else
    {
      *(_OWORD *)v44 = 0i64;
      v28 = (__m128 *)v44;
    }
    v29 = _mm_add_ps(_mm_movelh_ps(_mm_unpacklo_ps(*v28, v11), _mm_unpacklo_ps(*v27, (__m128)0i64)), *(__m128 *)&v44[1]);
    v26->m_transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
    v26->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    v26->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    v26->m_transform.m_translation.m_quad = v29;
    if ( displayGeometries->m_size == (displayGeometries->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&displayGeometries->m_data, 8);
    ++v22;
    displayGeometries->m_data[displayGeometries->m_size++] = v26;
  }
  while ( v22 < 4 );
  v30 = 0;
  v31 = _mm_add_ps(v13, v12);
  v32 = _mm_unpacklo_ps(v12, (__m128)0i64);
  halfExtents.m_quad = _mm_movelh_ps(v14, _mm_unpacklo_ps(v31, v13));
  do
  {
    v33 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v34 = (hkDisplayBox *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v33[11] + 8i64))(v33[11], 128i64);
    if ( v34 )
    {
      hkDisplayBox::hkDisplayBox(v34, &halfExtents);
      v36 = v35;
    }
    else
    {
      v36 = 0i64;
    }
    if ( (v30 & 2) != 0 )
    {
      v37 = (__m128 *)&v42;
      v42.hkReferencedObject = (hkReferencedObject)_mm_shuffle_ps(v8, v8, 85);
    }
    else
    {
      v40 = 0i64;
      v37 = &v40;
    }
    if ( (v30 & 1) != 0 )
    {
      v38 = &v43;
      v43 = _mm_shuffle_ps(v8, v8, 0);
    }
    else
    {
      *(_OWORD *)v44 = 0i64;
      v38 = (__m128 *)v44;
    }
    v39 = _mm_add_ps(_mm_movelh_ps(_mm_unpacklo_ps(*v38, *v37), v32), *(__m128 *)&v44[1]);
    v36->m_transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
    v36->m_transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
    v36->m_transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
    v36->m_transform.m_translation.m_quad = v39;
    if ( displayGeometries->m_size == (displayGeometries->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&displayGeometries->m_data, 8);
    ++v30;
    displayGeometries->m_data[displayGeometries->m_size++] = v36;
  }
  while ( v30 < 4 );
}

// File Line: 663
// RVA: 0xE1DEB0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_ShapeContainer(
        hkpShapeDisplayBuilder *this,
        hkpShapeContainer *shapeContainer,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  unsigned int i; // edi
  hkpShape *v9; // rax
  char v10[512]; // [rsp+30h] [rbp-218h] BYREF

  for ( i = shapeContainer->vfptr->getFirstKey(shapeContainer);
        i != -1;
        i = shapeContainer->vfptr->getNextKey(shapeContainer, i) )
  {
    v9 = shapeContainer->vfptr->getChildShape(shapeContainer, i, v10);
    hkpShapeDisplayBuilder::buildShapeDisplay(this, v9, transform, displayGeometries, 0i64);
  }
}

// File Line: 677
// RVA: 0xE1C4C0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_Sphere(
        hkpShapeDisplayBuilder *this,
        hkpSphereShape *sphereShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries,
        hkVector4f *scale)
{
  float m_radius; // xmm2_4
  _QWORD **Value; // rax
  hkDisplaySphere *v10; // rax
  hkDisplayGeometry *v11; // rax
  hkDisplayGeometry *v12; // rdi
  hkSphere sphere; // [rsp+20h] [rbp-18h] BYREF

  m_radius = sphereShape->m_radius;
  if ( scale )
    m_radius = m_radius * COERCE_FLOAT((unsigned int)(2 * scale->m_quad.m128_i32[0]) >> 1);
  sphere.m_pos.m_quad = aabbOut.m_quad;
  sphere.m_pos.m_quad.m128_f32[3] = m_radius;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v10 = (hkDisplaySphere *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 144i64);
  if ( v10 )
  {
    hkDisplaySphere::hkDisplaySphere(
      v10,
      &sphere,
      this->m_environment.m_sphereThetaRes,
      this->m_environment.m_spherePhiRes);
    v12 = v11;
  }
  else
  {
    v12 = 0i64;
  }
  v12->m_transform.m_rotation.m_col0 = transform->m_rotation.m_col0;
  v12->m_transform.m_rotation.m_col1 = transform->m_rotation.m_col1;
  v12->m_transform.m_rotation.m_col2 = transform->m_rotation.m_col2;
  v12->m_transform.m_translation = transform->m_translation;
  if ( displayGeometries->m_size == (displayGeometries->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&displayGeometries->m_data, 8);
  displayGeometries->m_data[displayGeometries->m_size++] = v12;
}

// File Line: 694
// RVA: 0xE1DF50
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_MultiSphere(
        hkpShapeDisplayBuilder *this,
        hkpMultiSphereShape *s,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  int v4; // ebp
  hkVector4f *i; // rsi
  int v9; // xmm1_4
  _QWORD **Value; // rax
  hkDisplaySphere *v11; // rax
  hkDisplayGeometry *v12; // rax
  hkDisplayGeometry *v13; // rdi
  hkSphere sphere; // [rsp+20h] [rbp-28h] BYREF

  v4 = 0;
  for ( i = s->m_spheres; v4 < s->m_numSpheres; ++i )
  {
    v9 = i->m_quad.m128_i32[3];
    sphere.m_pos.m_quad = aabbOut.m_quad;
    sphere.m_pos.m_quad.m128_i32[3] = v9;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v11 = (hkDisplaySphere *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 144i64);
    if ( v11 )
    {
      hkDisplaySphere::hkDisplaySphere(
        v11,
        &sphere,
        this->m_environment.m_sphereThetaRes,
        this->m_environment.m_spherePhiRes);
      v13 = v12;
    }
    else
    {
      v13 = 0i64;
    }
    v13->m_transform.m_translation = (hkVector4f)i->m_quad;
    if ( displayGeometries->m_size == (displayGeometries->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&displayGeometries->m_data, 8);
    ++v4;
    displayGeometries->m_data[displayGeometries->m_size++] = v13;
  }
}

// File Line: 707
// RVA: 0xE1E040
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_Plane(
        hkpShapeDisplayBuilder *this,
        hkpPlaneShape *planeShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  int v5; // r10d
  int v6; // r11d
  int *v7; // rbx
  __m128 v8; // xmm3
  __int64 v9; // rdi
  __int64 v10; // r15
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm6
  int v14; // eax
  hkVector4f *v15; // rcx
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // xmm3
  __m128 v19; // xmm2
  __m128 v20; // xmm2
  __m128 v21; // xmm0
  hkVector4f *v22; // rcx
  int v23; // edx
  __m128 v24; // xmm6
  int v25; // ebx
  __m128 v26; // xmm0
  hkVector4f v27; // xmm4
  int v28; // r9d
  __int64 v29; // rdi
  __m128 v30; // xmm4
  __m128 v31; // xmm3
  __m128 v32; // xmm2
  __m128 v33; // xmm1
  __m128 v34; // xmm9
  __m128 v35; // xmm10
  __m128 v36; // xmm2
  __m128 v37; // xmm5
  __int64 v38; // r8
  hkArrayBase<hkVector4f> *p_array; // rcx
  __int64 v40; // rax
  __int64 v41; // rdx
  __m128 v42; // xmm0
  __m128 v43; // xmm1
  __m128 v44; // xmm0
  __m128 v45; // xmm6
  __m128 v46; // xmm1
  __m128 v47; // xmm4
  __m128 v48; // xmm2
  __m128 v49; // xmm1
  __m128 v50; // xmm0
  __m128 v51; // xmm3
  hkVector4f *v52; // rcx
  int v53; // edx
  __int64 v54; // rdx
  unsigned __int64 v55; // rax
  hkDisplayGeometry *CurrentRawGeometry; // rax
  __int64 v57; // rdi
  hkGeometry *m_geometry; // r13
  signed int m_enum; // r15d
  int v60; // eax
  int v61; // r9d
  int v62; // eax
  __int64 m_size; // r12
  int v64; // r14d
  __int64 v65; // rsi
  int v66; // r9d
  int v67; // eax
  int v68; // eax
  __int64 v69; // r13
  __m128 v70; // xmm0
  __m128 v71; // xmm1
  BOOL v72; // r12d
  hkTransformf *v73; // r15
  __int64 v74; // rbx
  signed int v75; // edx
  __m128i si128; // xmm6
  __m128i v77; // xmm3
  __m128i v78; // xmm1
  int *v79; // rcx
  __m128i v80; // xmm0
  __m128i v81; // xmm4
  __m128i v82; // xmm5
  int v83; // r10d
  __m128i v84; // xmm0
  int v85; // r11d
  int v86; // ebx
  __m128i v87; // xmm2
  __m128i v88; // xmm2
  __m128i v89; // xmm0
  __m128i v90; // xmm1
  __m128i v91; // xmm0
  __m128i v92; // xmm1
  __m128i v93; // xmm0
  __m128i v94; // xmm1
  __int64 v95; // r10
  int *v96; // rcx
  int v97; // edx
  __int64 v98; // r8
  int v99; // eax
  __int64 sizeElem; // [rsp+20h] [rbp-79h]
  hkResult v101; // [rsp+28h] [rbp-71h] BYREF
  __m128 array; // [rsp+30h] [rbp-69h] BYREF
  hkResult result[4]; // [rsp+40h] [rbp-59h] BYREF
  hkVector4f t; // [rsp+50h] [rbp-49h] BYREF
  hkpShapeDisplayBuilder *v105; // [rsp+100h] [rbp+67h]
  __m128 *v106; // [rsp+108h] [rbp+6Fh]
  hkTransformf *a; // [rsp+110h] [rbp+77h]
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometriesa; // [rsp+118h] [rbp+7Fh]

  v5 = 0;
  v6 = 0x80000000;
  array.m128_u64[0] = 0i64;
  v7 = (int *)&signsForNonComponentAxes[0][1];
  v8 = (__m128)_mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)&planeShape->m_plane), 1u), 1u);
  array.m128_u64[1] = 0x8000000000000000ui64;
  v9 = (unsigned __int8)hkVector4Comparison_maskToLastIndex[_mm_movemask_ps(
                                                              _mm_and_ps(
                                                                _mm_cmple_ps(
                                                                  _mm_max_ps(
                                                                    _mm_shuffle_ps(v8, v8, 170),
                                                                    _mm_max_ps(
                                                                      _mm_shuffle_ps(v8, v8, 85),
                                                                      _mm_shuffle_ps(v8, v8, 0))),
                                                                  v8),
                                                                (__m128)xmmword_141AAA1D0))];
  v10 = v9;
  sizeElem = v9;
  v11 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[v9], planeShape->m_plane.m_quad);
  v12 = _mm_or_ps(_mm_shuffle_ps(v11, v11, 78), v11);
  v13 = _mm_sub_ps((__m128)0i64, _mm_div_ps(query.m_quad, _mm_or_ps(_mm_shuffle_ps(v12, v12, 177), v12)));
  while ( 1 )
  {
    if ( v5 == (v6 & 0x3FFFFFFF) )
    {
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
      v5 = array.m128_i32[2];
    }
    v14 = *(v7 - 1);
    t.m_quad.m128_i32[v9] = 1065353216;
    t.m_quad.m128_i32[((int)v9 + 1) % 3] = v14;
    v15 = (hkVector4f *)(array.m128_u64[0] + 16i64 * v5);
    t.m_quad.m128_i32[((int)v9 + 2) % 3] = *v7;
    array.m128_i32[2] = v5 + 1;
    v7 += 2;
    v16 = _mm_movelh_ps((__m128)t.m_quad.m128_u64[0], (__m128)t.m_quad.m128_u32[2]);
    *v15 = (hkVector4f)v16;
    v17 = _mm_mul_ps(planeShape->m_aabbHalfExtents.m_quad, v16);
    *v15 = (hkVector4f)v17;
    v18 = _mm_add_ps(planeShape->m_aabbCenter.m_quad, v17);
    *v15 = (hkVector4f)v18;
    v19 = _mm_mul_ps(planeShape->m_plane.m_quad, v18);
    v20 = _mm_shuffle_ps(v19, _mm_unpackhi_ps(v19, planeShape->m_plane.m_quad), 196);
    v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 78), v20);
    v15->m_quad = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(_mm_add_ps(_mm_shuffle_ps(v21, v21, 177), v21), v13),
                      *(__m128 *)((char *)&::transform.m_quad + v10 * 16)),
                    v18);
    if ( (__int64)v7 >= (__int64)"serShapeDisplayBuilder" )
      break;
    v6 = array.m128_i32[3];
    v5 = array.m128_i32[2];
  }
  v22 = (hkVector4f *)array.m128_u64[0];
  v23 = array.m128_i32[2];
  v24 = *(__m128 *)array.m128_u64[0];
  if ( array.m128_i32[2] == (array.m128_i32[3] & 0x3FFFFFFF) )
  {
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 16);
    v23 = array.m128_i32[2];
    v22 = (hkVector4f *)array.m128_u64[0];
  }
  v25 = 0;
  v22[v23] = (hkVector4f)v24;
  v26 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v10];
  v27.m_quad = (__m128)planeShape->m_aabbHalfExtents;
  v28 = array.m128_i32[2] + 1;
  v29 = 0i64;
  ++array.m128_i32[2];
  v30 = _mm_and_ps(v27.m_quad, v26);
  v31 = _mm_and_ps(planeShape->m_aabbCenter.m_quad, v26);
  v32 = _mm_or_ps(_mm_shuffle_ps(v30, v30, 78), v30);
  v33 = _mm_or_ps(_mm_shuffle_ps(v31, v31, 78), v31);
  v34 = _mm_sub_ps(_mm_or_ps(_mm_shuffle_ps(v33, v33, 177), v33), _mm_or_ps(_mm_shuffle_ps(v32, v32, 177), v32));
  array = v34;
  v35 = _mm_add_ps(_mm_or_ps(_mm_shuffle_ps(v33, v33, 177), v33), _mm_or_ps(_mm_shuffle_ps(v32, v32, 177), v32));
  *(__m128 *)&result[0].m_enum = v35;
  do
  {
    v36 = (__m128)`hkVector4f::getComponent::`2::indexToMask[v10];
    v37 = (__m128)xmmword_141A712A0;
    v38 = -1i64;
    p_array = (hkArrayBase<hkVector4f> *)&array;
    v40 = 0i64;
    v41 = 2i64;
    v42 = _mm_and_ps(*(__m128 *)(array.m128_u64[0] + v29), v36);
    v43 = _mm_or_ps(_mm_shuffle_ps(v42, v42, 78), v42);
    v44 = _mm_and_ps(*(__m128 *)(array.m128_u64[0] + v29 + 16), v36);
    v45 = _mm_or_ps(_mm_shuffle_ps(v43, v43, 177), v43);
    v46 = _mm_or_ps(_mm_shuffle_ps(v44, v44, 78), v44);
    v47 = _mm_or_ps(_mm_shuffle_ps(v46, v46, 177), v46);
    do
    {
      v48 = *(__m128 *)p_array;
      if ( v45.m128_f32[0] < COERCE_FLOAT(*p_array) && v48.m128_f32[0] < v47.m128_f32[0]
        || v47.m128_f32[0] < v48.m128_f32[0] && v48.m128_f32[0] < v45.m128_f32[0] )
      {
        v49 = _mm_sub_ps(v47, v45);
        v50 = _mm_rcp_ps(v49);
        v51 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v49, v50)), v50), _mm_sub_ps(v48, v45));
        if ( v51.m128_f32[0] < v37.m128_f32[0] )
        {
          v37 = v51;
          v38 = v40;
        }
      }
      ++v40;
      ++p_array;
      --v41;
    }
    while ( v41 );
    if ( v38 != -1 )
    {
      t.m_quad = _mm_or_ps(
                   _mm_andnot_ps(
                     (__m128)`hkVector4f::getComponent::`2::indexToMask[v10],
                     _mm_add_ps(
                       _mm_mul_ps(
                         _mm_sub_ps(*(__m128 *)(array.m128_u64[0] + v29 + 16), *(__m128 *)(array.m128_u64[0] + v29)),
                         v37),
                       *(__m128 *)(array.m128_u64[0] + v29))),
                   _mm_and_ps(*(&array + v38), (__m128)`hkVector4f::getComponent::`2::indexToMask[v10]));
      hkArrayBase<hkVector4f>::_insertAt(
        (hkArrayBase<hkVector4f> *)&array,
        &hkContainerHeapAllocator::s_alloc,
        v25 + 1,
        &t);
      v28 = array.m128_i32[2];
    }
    if ( v45.m128_f32[0] < v34.m128_f32[0] || v45.m128_f32[0] > v35.m128_f32[0] )
    {
      --v28;
      v52 = (hkVector4f *)(v29 + array.m128_u64[0]);
      array.m128_i32[2] = v28;
      v53 = 16 * (v28 - v25);
      if ( v53 > 0 )
      {
        v54 = ((unsigned int)(v53 - 1) >> 3) + 1;
        do
        {
          v55 = v52[1].m_quad.m128_u64[0];
          v52 = (hkVector4f *)((char *)v52 + 8);
          v52[-1].m_quad.m128_u64[1] = v55;
          --v54;
        }
        while ( v54 );
        v28 = array.m128_i32[2];
      }
    }
    else
    {
      ++v25;
      v29 += 16i64;
    }
  }
  while ( v25 < v28 - 1 );
  array.m128_i32[2] = v28 - 1;
  CurrentRawGeometry = hkpShapeDisplayBuilder::getCurrentRawGeometry(v105, displayGeometriesa);
  v57 = array.m128_u32[2];
  m_geometry = CurrentRawGeometry->m_geometry;
  v60 = m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  result[0] = (hkResult)m_geometry->m_vertices.m_size;
  m_enum = result[0].m_enum;
  v61 = array.m128_i32[2] + result[0].m_enum;
  if ( v60 >= array.m128_i32[2] + result[0].m_enum )
  {
    result[1].m_enum = HK_SUCCESS;
  }
  else
  {
    v62 = 2 * v60;
    if ( v61 < v62 )
      v61 = v62;
    hkArrayUtil::_reserve(
      &result[1],
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&m_geometry->m_vertices.m_data,
      v61,
      16);
  }
  m_geometry->m_vertices.m_size += v57;
  m_size = m_geometry->m_triangles.m_size;
  v64 = v57 - 2;
  v65 = (__int64)&m_geometry->m_vertices.m_data[m_enum];
  v66 = v57 - 2 + m_size;
  v67 = m_geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v67 < v66 )
  {
    v68 = 2 * v67;
    if ( v66 < v68 )
      v66 = v68;
    hkArrayUtil::_reserve(
      &v101,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&m_geometry->m_triangles.m_data,
      v66,
      16);
  }
  m_geometry->m_triangles.m_size += v64;
  v69 = (__int64)&m_geometry->m_triangles.m_data[m_size];
  v70 = _mm_and_ps((__m128)`hkVector4f::getComponent::`2::indexToMask[sizeElem], v106[2]);
  v71 = _mm_or_ps(_mm_shuffle_ps(v70, v70, 78), v70);
  v72 = COERCE_FLOAT(_mm_shuffle_ps(v71, v71, 177).m128_u32[0] | v71.m128_i32[0]) > 0.0;
  if ( (int)v57 > 0 )
  {
    v73 = a;
    v74 = 0i64;
    do
    {
      hkVector4f::setTransformedPos((hkVector4f *)(v74 + v65), v73, (hkVector4f *)(v74 + array.m128_u64[0]));
      v74 += 16i64;
      --v57;
    }
    while ( v57 );
    m_enum = result[0].m_enum;
  }
  v75 = 0;
  if ( v64 >= 4 )
  {
    si128 = _mm_load_si128((const __m128i *)&_xmm);
    v77 = _mm_shuffle_epi32(_mm_cvtsi32_si128(m_enum), 0);
    v78 = _mm_shuffle_epi32(_mm_cvtsi32_si128(v72), 0);
    v79 = (int *)(v69 + 32);
    v80 = _mm_srli_si128(v77, 4);
    v81 = _mm_add_epi32(_mm_load_si128((const __m128i *)_xmm), v78);
    v82 = _mm_sub_epi32(_mm_load_si128((const __m128i *)&_xmm), v78);
    v83 = _mm_cvtsi128_si32(v80);
    v84 = _mm_srli_si128(v80, 4);
    v85 = _mm_cvtsi128_si32(v84);
    v86 = _mm_cvtsi128_si32(_mm_srli_si128(v84, 4));
    do
    {
      v87 = _mm_cvtsi32_si128(v75);
      v75 += 4;
      *(v79 - 4) = v83;
      *v79 = v85;
      v79[4] = v86;
      *(v79 - 8) = _mm_cvtsi128_si32(v77);
      v88 = _mm_add_epi32(_mm_add_epi32(_mm_shuffle_epi32(v87, 0), si128), v77);
      v79 += 16;
      v89 = _mm_add_epi32(v81, v88);
      v90 = _mm_add_epi32(v82, v88);
      *(v79 - 23) = _mm_cvtsi128_si32(v89);
      *(v79 - 22) = _mm_cvtsi128_si32(v90);
      v91 = _mm_srli_si128(v89, 4);
      v92 = _mm_srli_si128(v90, 4);
      *(v79 - 19) = _mm_cvtsi128_si32(v91);
      v93 = _mm_srli_si128(v91, 4);
      *(v79 - 18) = _mm_cvtsi128_si32(v92);
      *(v79 - 15) = _mm_cvtsi128_si32(v93);
      v94 = _mm_srli_si128(v92, 4);
      *(v79 - 14) = _mm_cvtsi128_si32(v94);
      *(v79 - 11) = _mm_cvtsi128_si32(_mm_srli_si128(v93, 4));
      *(v79 - 10) = _mm_cvtsi128_si32(_mm_srli_si128(v94, 4));
    }
    while ( v75 < (int)(v64 - (v64 & 0x80000003)) );
  }
  v95 = v75;
  if ( v75 < (__int64)v64 )
  {
    v96 = (int *)(16i64 * v75 + v69 + 8);
    v97 = m_enum + v72 + v75 + 1;
    v98 = v64 - v95;
    do
    {
      v99 = 1 - 2 * v72 + v97;
      *(v96 - 1) = v97++;
      *(v96 - 2) = m_enum;
      *v96 = v99;
      v96 += 4;
      --v98;
    }
    while ( v98 );
  }
  array.m128_i32[2] = 0;
  if ( array.m128_i32[3] >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      (void *)array.m128_u64[0],
      16 * array.m128_i32[3]);
}

// File Line: 829
// RVA: 0xE1C5C0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_Capsule(
        hkpShapeDisplayBuilder *this,
        hkpCapsuleShape *s,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries,
        hkVector4f *scale)
{
  __m128 m_quad; // xmm1
  __m128 v6; // xmm2
  float m_radius; // xmm6_4
  __m128 v10; // xmm0
  _QWORD **Value; // rax
  hkDisplayCapsule *v12; // rax
  hkDisplayGeometry *v13; // rax
  hkDisplayGeometry *v14; // rdi
  hkVector4f bottom; // [rsp+30h] [rbp-38h] BYREF
  hkVector4f top; // [rsp+40h] [rbp-28h] BYREF

  m_quad = s->m_vertexA.m_quad;
  v6 = s->m_vertexB.m_quad;
  top.m_quad = m_quad;
  bottom.m_quad = v6;
  m_radius = s->m_radius;
  if ( scale )
  {
    v10 = _mm_shuffle_ps(scale->m_quad, scale->m_quad, 0);
    top.m_quad = _mm_mul_ps(m_quad, v10);
    bottom.m_quad = _mm_mul_ps(v6, v10);
    m_radius = m_radius * COERCE_FLOAT((unsigned int)(2 * v10.m128_i32[0]) >> 1);
  }
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkDisplayCapsule *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 160i64);
  if ( v12 )
  {
    hkDisplayCapsule::hkDisplayCapsule(v12, &top, &bottom, m_radius, 6, 1);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  v14->m_transform.m_rotation.m_col0 = transform->m_rotation.m_col0;
  v14->m_transform.m_rotation.m_col1 = transform->m_rotation.m_col1;
  v14->m_transform.m_rotation.m_col2 = transform->m_rotation.m_col2;
  v14->m_transform.m_translation = transform->m_translation;
  if ( displayGeometries->m_size == (displayGeometries->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&displayGeometries->m_data, 8);
  displayGeometries->m_data[displayGeometries->m_size++] = v14;
}

// File Line: 854
// RVA: 0xE1C6E0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_Cylinder(
        hkpShapeDisplayBuilder *this,
        hkpCylinderShape *s,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries,
        hkVector4f *scale)
{
  __m128 m_quad; // xmm1
  float CylinderRadius; // xmm0_4
  float v9; // xmm6_4
  __m128 v10; // xmm3
  _QWORD **Value; // rax
  hkDisplayCylinder *v12; // rax
  hkDisplayGeometry *v13; // rax
  hkDisplayGeometry *v14; // rdi
  hkVector4f bottom; // [rsp+30h] [rbp-38h] BYREF
  hkVector4f top; // [rsp+40h] [rbp-28h] BYREF

  m_quad = s->m_vertexB.m_quad;
  top.m_quad = (__m128)s->m_vertexA;
  bottom.m_quad = m_quad;
  CylinderRadius = hkpCylinderShape::getCylinderRadius(s);
  v9 = CylinderRadius;
  if ( scale )
  {
    v10 = _mm_shuffle_ps(scale->m_quad, scale->m_quad, 0);
    top.m_quad = _mm_mul_ps(top.m_quad, v10);
    bottom.m_quad = _mm_mul_ps(bottom.m_quad, v10);
    v9 = CylinderRadius * COERCE_FLOAT((unsigned int)(2 * v10.m128_i32[0]) >> 1);
  }
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v12 = (hkDisplayCylinder *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 160i64);
  if ( v12 )
  {
    hkDisplayCylinder::hkDisplayCylinder(v12, &top, &bottom, v9, 9, 1);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  v14->m_transform.m_rotation.m_col0 = transform->m_rotation.m_col0;
  v14->m_transform.m_rotation.m_col1 = transform->m_rotation.m_col1;
  v14->m_transform.m_rotation.m_col2 = transform->m_rotation.m_col2;
  v14->m_transform.m_translation = transform->m_translation;
  if ( displayGeometries->m_size == (displayGeometries->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&displayGeometries->m_data, 8);
  displayGeometries->m_data[displayGeometries->m_size++] = v14;
}

// File Line: 877
// RVA: 0xE1E7B0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_MultiRay(
        hkpShapeDisplayBuilder *this,
        hkpMultiRayShape *s,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  int v6; // r15d
  hkGeometry *m_geometry; // rdi
  int v8; // esi
  __int64 v9; // r14
  hkpMultiRayShape::Ray *m_data; // rax
  __int64 m_size; // rbp
  int v12; // r9d
  __m128 m_quad; // xmm6
  hkVector4f v14; // xmm7
  int v15; // eax
  int v16; // eax
  hkVector4f *v17; // r8
  __int64 v18; // rbp
  int v19; // r9d
  int v20; // eax
  int v21; // eax
  __int64 v22; // rbp
  int v23; // r9d
  int v24; // eax
  int v25; // eax
  hkVector4f *v26; // r8
  __int64 v27; // rbp
  int v28; // r9d
  int v29; // eax
  int v30; // eax
  hkGeometry::Triangle *v31; // rcx
  int v32; // eax
  hkResult v33; // [rsp+30h] [rbp-68h] BYREF
  hkResult v34; // [rsp+34h] [rbp-64h] BYREF
  hkResult v35; // [rsp+38h] [rbp-60h] BYREF
  hkResult result; // [rsp+A8h] [rbp+10h] BYREF

  v6 = 0;
  m_geometry = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries)->m_geometry;
  if ( s->m_rays.m_size > 0 )
  {
    v8 = 2;
    v9 = 0i64;
    do
    {
      m_data = s->m_rays.m_data;
      m_size = m_geometry->m_vertices.m_size;
      v12 = m_size + 1;
      m_quad = m_data[v9].m_start.m_quad;
      v14.m_quad = (__m128)m_data[v9].m_end;
      v15 = m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v15 >= (int)m_size + 1 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        v16 = 2 * v15;
        if ( v12 < v16 )
          v12 = v16;
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&m_geometry->m_vertices.m_data,
          v12,
          16);
      }
      ++m_geometry->m_vertices.m_size;
      v17 = &m_geometry->m_vertices.m_data[m_size];
      *v17 = (hkVector4f)m_quad;
      hkVector4f::setTransformedPos(v17, transform, v17);
      v18 = m_geometry->m_vertices.m_size;
      v19 = v18 + 1;
      v20 = m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v20 >= (int)v18 + 1 )
      {
        v33.m_enum = HK_SUCCESS;
      }
      else
      {
        v21 = 2 * v20;
        if ( v19 < v21 )
          v19 = v21;
        hkArrayUtil::_reserve(
          &v33,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&m_geometry->m_vertices.m_data,
          v19,
          16);
      }
      ++m_geometry->m_vertices.m_size;
      m_geometry->m_vertices.m_data[v18].m_quad = _mm_add_ps((__m128)_xmm, m_quad);
      v22 = m_geometry->m_vertices.m_size;
      v23 = v22 + 1;
      v24 = m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v24 >= (int)v22 + 1 )
      {
        v34.m_enum = HK_SUCCESS;
      }
      else
      {
        v25 = 2 * v24;
        if ( v23 < v25 )
          v23 = v25;
        hkArrayUtil::_reserve(
          &v34,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&m_geometry->m_vertices.m_data,
          v23,
          16);
      }
      ++m_geometry->m_vertices.m_size;
      v26 = &m_geometry->m_vertices.m_data[v22];
      *v26 = (hkVector4f)v14.m_quad;
      hkVector4f::setTransformedPos(v26, transform, v26);
      v27 = m_geometry->m_triangles.m_size;
      v28 = v27 + 1;
      v29 = m_geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v29 >= (int)v27 + 1 )
      {
        v35.m_enum = HK_SUCCESS;
      }
      else
      {
        v30 = 2 * v29;
        if ( v28 < v30 )
          v28 = v30;
        hkArrayUtil::_reserve(
          &v35,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&m_geometry->m_triangles.m_data,
          v28,
          16);
      }
      ++m_geometry->m_triangles.m_size;
      ++v6;
      ++v9;
      v31 = &m_geometry->m_triangles.m_data[v27];
      v31->m_a = v8 - 2;
      v32 = v8 - 1;
      v31->m_c = v8;
      v31->m_material = -1;
      v8 += 3;
      v31->m_b = v32;
    }
    while ( v6 < s->m_rays.m_size );
  }
} - 1;


// File Line: 911
// RVA: 0xE1C810
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_Box(
        hkpShapeDisplayBuilder *this,
        hkpBoxShape *boxShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries,
        hkVector4f *scale)
{
  __m128 m_quad; // xmm1
  _QWORD **Value; // rax
  hkDisplayBox *v9; // rax
  hkDisplayGeometry *v10; // rax
  hkDisplayGeometry *v11; // rdi
  hkVector4f halfExtents; // [rsp+20h] [rbp-18h] BYREF

  m_quad = boxShape->m_halfExtents.m_quad;
  halfExtents.m_quad = m_quad;
  if ( scale )
    halfExtents.m_quad = (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_mul_ps(scale->m_quad, m_quad), 1u), 1u);
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkDisplayBox *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 128i64);
  if ( v9 )
  {
    hkDisplayBox::hkDisplayBox(v9, &halfExtents);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v11->m_transform.m_rotation.m_col0 = transform->m_rotation.m_col0;
  v11->m_transform.m_rotation.m_col1 = transform->m_rotation.m_col1;
  v11->m_transform.m_rotation.m_col2 = transform->m_rotation.m_col2;
  v11->m_transform.m_translation = transform->m_translation;
  if ( displayGeometries->m_size == (displayGeometries->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&displayGeometries->m_data, 8);
  displayGeometries->m_data[displayGeometries->m_size++] = v11;
}

// File Line: 924
// RVA: 0xE1D1B0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_ListShape(
        hkpShapeDisplayBuilder *this,
        hkpListShape *listShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  unsigned int i; // ebx

  for ( i = listShape->hkpShapeCollection::hkpShapeContainer::vfptr->getFirstKey(&listShape->hkpShapeContainer);
        i != -1;
        i = listShape->hkpShapeCollection::hkpShapeContainer::vfptr->getNextKey(&listShape->hkpShapeContainer, i) )
  {
    hkpShapeDisplayBuilder::buildShapeDisplay(
      this,
      listShape->m_childInfo.m_data[i].m_shape,
      transform,
      displayGeometries,
      0i64);
  }
}

// File Line: 934
// RVA: 0xE1C8F0
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_Triangle(
        hkpShapeDisplayBuilder *this,
        hkpTriangleShape *triangleShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries,
        hkVector4f *scale)
{
  hkGeometry *m_geometry; // rsi
  int m_size; // ebp
  int v9; // eax
  int v10; // r9d
  int v11; // eax
  hkVector4f *v12; // rbx
  __int64 v13; // rbx
  int v14; // r9d
  int v15; // eax
  int v16; // eax
  int v17; // r14d
  int v18; // r12d
  hkGeometry::Triangle *v19; // rax
  hkVector4f v20; // xmm3
  __m128 v21; // xmm2
  __int64 v22; // rbx
  hkVector4f v23; // xmm1
  int v24; // r9d
  int v25; // eax
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  int v28; // eax
  hkVector4f *v29; // rbx
  __int64 v30; // rbx
  int v31; // r9d
  int v32; // eax
  int v33; // eax
  hkGeometry::Triangle *v34; // r8
  hkVector4f b; // [rsp+30h] [rbp-88h] BYREF
  hkVector4f v36; // [rsp+40h] [rbp-78h] BYREF
  hkVector4f v37; // [rsp+50h] [rbp-68h] BYREF
  hkQsTransformf a; // [rsp+60h] [rbp-58h] BYREF

  m_geometry = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries)->m_geometry;
  hkQsTransformf::setFromTransformNoScale(&a, transform);
  if ( scale )
    a.m_scale = (hkVector4f)scale->m_quad;
  m_size = m_geometry->m_vertices.m_size;
  v9 = m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
  v10 = m_size + 3;
  if ( v9 >= m_size + 3 )
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
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&m_geometry->m_vertices.m_data,
      v10,
      16);
  }
  m_geometry->m_vertices.m_size += 3;
  v12 = &m_geometry->m_vertices.m_data[m_size];
  hkVector4f::setTransformedPos(v12, &a, &triangleShape->m_vertexA);
  hkVector4f::setTransformedPos(v12 + 1, &a, &triangleShape->m_vertexB);
  hkVector4f::setTransformedPos(v12 + 2, &a, &triangleShape->m_vertexC);
  v13 = m_geometry->m_triangles.m_size;
  v14 = v13 + 1;
  v15 = m_geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v15 < (int)v13 + 1 )
  {
    v16 = 2 * v15;
    if ( v14 < v16 )
      v14 = v16;
    hkArrayUtil::_reserve(
      (hkResult *)&scale,
      &hkContainerHeapAllocator::s_alloc,
      (const void **)&m_geometry->m_triangles.m_data,
      v14,
      16);
  }
  ++m_geometry->m_triangles.m_size;
  v17 = m_size + 1;
  v18 = m_size + 2;
  v19 = &m_geometry->m_triangles.m_data[v13];
  v19->m_a = m_size;
  v19->m_b = m_size + 1;
  v19->m_c = m_size + 2;
  v19->m_material = -1;
  v20.m_quad = (__m128)triangleShape->m_extrusion;
  v21 = _mm_mul_ps(v20.m_quad, v20.m_quad);
  if ( (float)((float)(_mm_shuffle_ps(v21, v21, 85).m128_f32[0] + _mm_shuffle_ps(v21, v21, 0).m128_f32[0])
             + _mm_shuffle_ps(v21, v21, 170).m128_f32[0]) > 0.0 )
  {
    v22 = m_geometry->m_vertices.m_size;
    v23.m_quad = (__m128)triangleShape->m_extrusion;
    v24 = v22 + 3;
    v25 = m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
    v26 = _mm_add_ps(v20.m_quad, triangleShape->m_vertexA.m_quad);
    v27 = _mm_add_ps(v20.m_quad, triangleShape->m_vertexC.m_quad);
    b.m_quad = v26;
    v37.m_quad = v27;
    v36.m_quad = _mm_add_ps(v23.m_quad, triangleShape->m_vertexB.m_quad);
    if ( v25 >= (int)v22 + 3 )
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
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&m_geometry->m_vertices.m_data,
        v24,
        16);
    }
    m_geometry->m_vertices.m_size += 3;
    v29 = &m_geometry->m_vertices.m_data[v22];
    hkVector4f::setTransformedPos(v29, &a, &b);
    hkVector4f::setTransformedPos(v29 + 1, &a, &v36);
    hkVector4f::setTransformedPos(v29 + 2, &a, &v37);
    v30 = m_geometry->m_triangles.m_size;
    v31 = v30 + 7;
    v32 = m_geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v32 < (int)v30 + 7 )
    {
      v33 = 2 * v32;
      if ( v31 < v33 )
        v31 = v33;
      hkArrayUtil::_reserve(
        (hkResult *)&scale,
        &hkContainerHeapAllocator::s_alloc,
        (const void **)&m_geometry->m_triangles.m_data,
        v31,
        16);
    }
    m_geometry->m_triangles.m_size += 7;
    v34 = &m_geometry->m_triangles.m_data[v30];
    v34->m_a = m_size + 3;
    v34->m_b = v17;
    v34->m_c = m_size;
    v34->m_material = -1;
    v34[1].m_a = m_size + 3;
    v34[1].m_b = m_size + 4;
    v34[1].m_c = v17;
    v34[1].m_material = -1;
    v34[2].m_a = m_size + 4;
    v34[2].m_b = m_size + 5;
    v34[2].m_c = v17;
    v34[2].m_material = -1;
    v34[3].m_a = m_size + 5;
    v34[3].m_b = v18;
    v34[3].m_c = v17;
    v34[3].m_material = -1;
    v34[4].m_a = m_size + 5;
    v34[4].m_b = m_size;
    v34[4].m_c = v18;
    v34[4].m_material = -1;
    v34[5].m_a = m_size + 5;
    v34[5].m_b = m_size + 3;
    v34[5].m_c = m_size;
    v34[5].m_material = -1;
    v34[6].m_a = m_size + 5;
    v34[6].m_b = m_size + 4;
    v34[6].m_c = m_size + 3;
    v34[6].m_material = -1;
  }
}

// File Line: 985
// RVA: 0xE1CC30
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_ConvexVertices(
        hkpShapeDisplayBuilder *this,
        hkpConvexVerticesShape *cvShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries,
        hkVector4f *scale)
{
  unsigned int v8; // eax
  __int64 v9; // rdi
  hkLifoAllocator *Value; // rax
  char *m_cur; // rcx
  int v12; // edx
  char *v13; // r8
  int v14; // r9d
  hkBaseObjectVtbl *vfptr; // rax
  __int64 v16; // r14
  __int64 v17; // rbx
  _QWORD **v18; // rax
  __int64 v19; // rax
  hkGeometry *v20; // rbx
  _QWORD **v21; // rax
  hkDisplayConvex *v22; // rax
  hkDisplayGeometry *v23; // rax
  hkDisplayGeometry *v24; // rbx
  int v25; // r8d
  int v26; // eax
  char *v27; // rdi
  signed int v28; // ebx
  hkLifoAllocator *v29; // rax
  int v30; // r8d
  float *v31; // [rsp+30h] [rbp-41h] BYREF
  int v32; // [rsp+38h] [rbp-39h]
  int v33; // [rsp+3Ch] [rbp-35h]
  hkStridedVertices stridedVertsIn; // [rsp+40h] [rbp-31h] BYREF
  char *array; // [rsp+50h] [rbp-21h] BYREF
  int v36; // [rsp+58h] [rbp-19h]
  int v37; // [rsp+5Ch] [rbp-15h]
  void *p; // [rsp+60h] [rbp-11h]
  unsigned int v39; // [rsp+68h] [rbp-9h]
  hkQsTransformf a; // [rsp+70h] [rbp-1h] BYREF
  hkResult result; // [rsp+D8h] [rbp+67h] BYREF

  v8 = ((__int64 (__fastcall *)(hkpConvexVerticesShape *))cvShape->vfptr[5].__first_virtual_table_function__)(cvShape);
  v9 = v8;
  if ( v8 )
  {
    array = 0i64;
    v36 = 0;
    v37 = 0x80000000;
    v39 = v8;
    Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    m_cur = (char *)Value->m_cur;
    v12 = (16 * v9 + 127) & 0xFFFFFF80;
    v13 = &m_cur[v12];
    if ( v12 > Value->m_slabSize || v13 > Value->m_end )
      m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, v12);
    else
      Value->m_cur = v13;
    array = m_cur;
    p = m_cur;
    v37 = v9 | 0x80000000;
    if ( (v9 & 0x3FFFFFFF) < (int)v9 )
    {
      v14 = v9;
      if ( (int)v9 < (int)(2 * (v9 & 0x3FFFFFFF)) )
        v14 = 2 * (v9 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, v14, 16);
      m_cur = array;
    }
    vfptr = cvShape->vfptr;
    v36 = v9;
    v16 = (__int64)vfptr[6].__vecDelDtor(cvShape, (unsigned int)m_cur);
    hkQsTransformf::setFromTransformNoScale(&a, transform);
    if ( scale )
      a.m_scale = (hkVector4f)scale->m_quad;
    v31 = 0i64;
    v32 = 0;
    v33 = 0x80000000;
    if ( (int)v9 > 0 )
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v31, v9, 16);
    v32 = v9;
    if ( (int)v9 > 0 )
    {
      v17 = 0i64;
      do
      {
        hkVector4f::setTransformedPos((hkVector4f *)&v31[v17], &a, (hkVector4f *)(v17 * 4 + v16));
        v17 += 4i64;
        --v9;
      }
      while ( v9 );
    }
    v18 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v19 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*v18[11] + 8i64))(v18[11], 48i64);
    v20 = (hkGeometry *)v19;
    if ( v19 )
    {
      *(_DWORD *)(v19 + 8) = 0x1FFFF;
      *(_QWORD *)v19 = &hkGeometry::`vftable;
      *(_QWORD *)(v19 + 16) = 0i64;
      *(_DWORD *)(v19 + 24) = 0;
      *(_DWORD *)(v19 + 28) = 0x80000000;
      *(_QWORD *)(v19 + 32) = 0i64;
      *(_DWORD *)(v19 + 40) = 0;
      *(_DWORD *)(v19 + 44) = 0x80000000;
    }
    else
    {
      v20 = 0i64;
    }
    stridedVertsIn.m_vertices = v31;
    stridedVertsIn.m_striding = 16;
    stridedVertsIn.m_numVertices = v32;
    hkGeometryUtility::createConvexGeometry(&stridedVertsIn, v20);
    v21 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v22 = (hkDisplayConvex *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v21[11] + 8i64))(v21[11], 112i64);
    if ( v22 )
    {
      hkDisplayConvex::hkDisplayConvex(v22, v20);
      v24 = v23;
    }
    else
    {
      v24 = 0i64;
    }
    if ( displayGeometries->m_size == (displayGeometries->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&displayGeometries->m_data, 8);
    displayGeometries->m_data[displayGeometries->m_size] = v24;
    v25 = v33;
    ++displayGeometries->m_size;
    v32 = 0;
    if ( v25 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, v31, 16 * v25);
    v26 = v36;
    v27 = (char *)p;
    v31 = 0i64;
    if ( p == array )
      v26 = 0;
    v33 = 0x80000000;
    v36 = v26;
    v28 = (16 * v39 + 127) & 0xFFFFFF80;
    v29 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v30 = (v28 + 15) & 0xFFFFFFF0;
    if ( v28 > v29->m_slabSize || &v27[v30] != v29->m_cur || v29->m_firstNonLifoEnd == v27 )
      hkLifoAllocator::slowBlockFree(v29, v27, v30);
    else
      v29->m_cur = v27;
    v36 = 0;
    if ( v37 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, array, 16 * v37);
  }
}

// File Line: 1019
// RVA: 0xE1EF20
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_ConvexPiece(
        hkpShapeDisplayBuilder *this,
        hkpConvexPieceShape *triangulatedConvexShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v4; // r13
  hkpConvexPieceShape *v5; // rdi
  _QWORD **Value; // rax
  __int64 v7; // rax
  hkDisplayGeometry *v8; // rsi
  hkGeometry *v9; // r15
  int v10; // r12d
  __int64 v11; // rdx
  hkArray<hkGeometry::Triangle,hkContainerHeapAllocator> *p_m_triangles; // r14
  __int64 v13; // rax
  __int64 m_size; // rdi
  int v15; // r9d
  int v16; // ecx
  hkVector4f *v17; // rbp
  int v18; // ecx
  int v19; // ecx
  hkGeometry::Triangle *v20; // rdx
  hkVector4f *v21; // rbp
  __int64 v22; // r14
  __int64 v23; // rdi
  int v24; // r9d
  int v25; // eax
  int v26; // eax
  _QWORD **v27; // rax
  hkDisplayConvex *v28; // rax
  hkDisplayGeometry *v29; // rax
  hkResult v30; // [rsp+30h] [rbp-248h] BYREF
  hkResult result; // [rsp+34h] [rbp-244h] BYREF
  __int64 v32; // [rsp+38h] [rbp-240h]
  char v33[512]; // [rsp+40h] [rbp-238h] BYREF

  v4 = displayGeometries;
  v5 = triangulatedConvexShape;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v8 = 0i64;
  v9 = (hkGeometry *)v7;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 8) = 0x1FFFF;
    *(_QWORD *)v7 = &hkGeometry::`vftable;
    *(_QWORD *)(v7 + 16) = 0i64;
    *(_DWORD *)(v7 + 24) = 0;
    *(_DWORD *)(v7 + 28) = 0x80000000;
    *(_QWORD *)(v7 + 32) = 0i64;
    *(_DWORD *)(v7 + 40) = 0;
    *(_DWORD *)(v7 + 44) = 0x80000000;
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
    p_m_triangles = &v9->m_triangles;
    do
    {
      v13 = (__int64)v5->m_displayMesh->vfptr->getChildShape(
                       &v5->m_displayMesh->hkpShapeContainer,
                       *(const unsigned int *)((char *)v5->m_displayShapeKeys + v11),
                       (char (*)[512])v33);
      m_size = p_m_triangles->m_size;
      v15 = m_size + 1;
      v16 = p_m_triangles->m_capacityAndFlags & 0x3FFFFFFF;
      v17 = (hkVector4f *)v13;
      if ( v16 >= (int)m_size + 1 )
      {
        result.m_enum = HK_SUCCESS;
      }
      else
      {
        v18 = 2 * v16;
        if ( v15 < v18 )
          v15 = v18;
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&p_m_triangles->m_data,
          v15,
          16);
      }
      ++p_m_triangles->m_size;
      v19 = v9->m_vertices.m_size;
      v20 = &p_m_triangles->m_data[m_size];
      v21 = v17 + 3;
      v22 = 3i64;
      v20->m_b = v19 + 1;
      v20->m_a = v19;
      v20->m_c = v19 + 2;
      v20->m_material = -1;
      do
      {
        v23 = v9->m_vertices.m_size;
        v24 = v23 + 1;
        v25 = v9->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
        if ( v25 >= (int)v23 + 1 )
        {
          v30.m_enum = HK_SUCCESS;
        }
        else
        {
          v26 = 2 * v25;
          if ( v24 < v26 )
            v24 = v26;
          hkArrayUtil::_reserve(
            &v30,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&v9->m_vertices.m_data,
            v24,
            16);
        }
        ++v9->m_vertices.m_size;
        hkVector4f::setTransformedPos(&v9->m_vertices.m_data[v23], transform, v21++);
        --v22;
      }
      while ( v22 );
      v5 = triangulatedConvexShape;
      ++v10;
      v11 = v32 + 4;
      p_m_triangles = &v9->m_triangles;
      v32 += 4i64;
    }
    while ( v10 < triangulatedConvexShape->m_numDisplayShapeKeys );
    v4 = displayGeometries;
  }
  v27 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v28 = (hkDisplayConvex *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v27[11] + 8i64))(v27[11], 112i64);
  if ( v28 )
  {
    hkDisplayConvex::hkDisplayConvex(v28, v9);
    v8 = v29;
  }
  if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v4->m_data, 8);
  v4->m_data[v4->m_size++] = v8;
}

// File Line: 1048
// RVA: 0xE1EA10
hkBool *__fastcall hkpShapeDisplayBuilder::buildShapeDisplay_UserShapes(
        hkpShapeDisplayBuilder *this,
        hkBool *result,
        hkpShape *shape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkpUserShapeDisplayBuilder *v5; // r10
  int v6; // ebx
  __int64 v11; // rdi
  hkpUserShapeDisplayBuilder::UserShapeBuilder *m_data; // r11

  v5 = hkSingleton<hkpUserShapeDisplayBuilder>::s_instance;
  v6 = 0;
  result->m_bool = 0;
  if ( v5->m_userShapeBuilders.m_size > 0 )
  {
    v11 = 0i64;
    do
    {
      m_data = v5->m_userShapeBuilders.m_data;
      if ( m_data[v11].type == (unsigned __int8)shape->m_type.m_storage )
      {
        m_data[v11].f(shape, transform, displayGeometries, this);
        v5 = hkSingleton<hkpUserShapeDisplayBuilder>::s_instance;
        result->m_bool = 1;
      }
      ++v6;
      ++v11;
    }
    while ( v6 < v5->m_userShapeBuilders.m_size );
  }
  return result;
}

// File Line: 1066
// RVA: 0xE1CF60
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay_StaticCompound(
        hkpShapeDisplayBuilder *this,
        hkpStaticCompoundShape *staticCompoundShape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries,
        hkVector4f *scale)
{
  __m128 m_quad; // xmm9
  int v9; // esi
  __int64 v10; // rbx
  hkpStaticCompoundShape::Instance *m_data; // rax
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
  hkpShape *m_shape; // rdx
  hkQsTransformf v25; // [rsp+30h] [rbp-F8h] BYREF
  hkQsTransformf v26; // [rsp+60h] [rbp-C8h] BYREF
  hkTransformf transformOut; // [rsp+90h] [rbp-98h] BYREF

  hkQsTransformf::setFromTransformNoScale(&v25, transform);
  if ( scale )
  {
    m_quad = scale->m_quad;
    v25.m_scale = (hkVector4f)scale->m_quad;
  }
  else
  {
    m_quad = v25.m_scale.m_quad;
  }
  v9 = 0;
  if ( staticCompoundShape->m_instances.m_size > 0 )
  {
    v10 = 0i64;
    while ( 1 )
    {
      m_data = staticCompoundShape->m_instances.m_data;
      v12 = _mm_shuffle_ps(v25.m_rotation.m_vec.m_quad, v25.m_rotation.m_vec.m_quad, 255);
      v13 = _mm_shuffle_ps(v25.m_rotation.m_vec.m_quad, v25.m_rotation.m_vec.m_quad, 201);
      v14 = _mm_mul_ps(m_data[v10].m_transform.m_translation.m_quad, m_quad);
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
      v18 = m_data[v10].m_transform.m_rotation.m_vec.m_quad;
      v19 = _mm_shuffle_ps(v18, v18, 255);
      v20 = _mm_mul_ps(v25.m_rotation.m_vec.m_quad, v18);
      v21 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v18, v18, 201), v25.m_rotation.m_vec.m_quad), _mm_mul_ps(v13, v18));
      v22 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v21, v21, 201), _mm_mul_ps(v18, v12)),
              _mm_mul_ps(v25.m_rotation.m_vec.m_quad, v19));
      v23 = m_data[v10].m_transform.m_scale.m_quad;
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
      v26.m_scale.m_quad = _mm_mul_ps(v23, m_quad);
      hkQsTransformf::copyToTransformNoScale(&v26, &transformOut);
      m_shape = staticCompoundShape->m_instances.m_data[v10].m_shape;
      if ( (_mm_movemask_ps(
              _mm_cmplt_ps(
                (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)_mm_sub_ps(v26.m_scale.m_quad, query.m_quad), 1u), 1u),
                *(__m128 *)&epsilon)) & 7) == 7 )
        hkpShapeDisplayBuilder::buildShapeDisplay(this, m_shape, &transformOut, displayGeometries, 0i64);
      else
        hkpShapeDisplayBuilder::buildShapeDisplay(this, m_shape, &transformOut, displayGeometries, &v26.m_scale);
      ++v9;
      ++v10;
      if ( v9 >= staticCompoundShape->m_instances.m_size )
        break;
      m_quad = v25.m_scale.m_quad;
    }
  }
}

// File Line: 1095
// RVA: 0xE1BF00
void __fastcall hkpShapeDisplayBuilder::buildShapeDisplay(
        hkpShapeDisplayBuilder *this,
        hkpShape *shape,
        hkTransformf *transform,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries,
        hkVector4f *scale)
{
  hkpShape *m_userData; // rdi
  hkVector4f v9; // xmm2
  hkpShapeContainer *v10; // rax
  hkBool result; // [rsp+30h] [rbp-98h] BYREF
  hkTransformf bTc; // [rsp+40h] [rbp-88h] BYREF
  hkTransformf transforma; // [rsp+80h] [rbp-48h] BYREF

  m_userData = shape;
  if ( !hkpShapeDisplayBuilder::buildShapeDisplay_UserShapes(this, &result, shape, transform, displayGeometries)->m_bool )
  {
    while ( 2 )
    {
      switch ( m_userData->m_type.m_storage )
      {
        case 0:
          hkpShapeDisplayBuilder::buildShapeDisplay_Sphere(
            this,
            (hkpSphereShape *)m_userData,
            transform,
            displayGeometries,
            scale);
          return;
        case 1:
          hkpShapeDisplayBuilder::buildShapeDisplay_Cylinder(
            this,
            (hkpCylinderShape *)m_userData,
            transform,
            displayGeometries,
            scale);
          return;
        case 2:
          hkpShapeDisplayBuilder::buildShapeDisplay_Triangle(
            this,
            (hkpTriangleShape *)m_userData,
            transform,
            displayGeometries,
            scale);
          return;
        case 3:
          hkpShapeDisplayBuilder::buildShapeDisplay_Box(
            this,
            (hkpBoxShape *)m_userData,
            transform,
            displayGeometries,
            scale);
          return;
        case 4:
          hkpShapeDisplayBuilder::buildShapeDisplay_Capsule(
            this,
            (hkpCapsuleShape *)m_userData,
            transform,
            displayGeometries,
            scale);
          return;
        case 5:
          hkpShapeDisplayBuilder::buildShapeDisplay_ConvexVertices(
            this,
            (hkpConvexVerticesShape *)m_userData,
            transform,
            displayGeometries,
            scale);
          return;
        case 6:
        case 7:
        case 0x12:
        case 0x16:
        case 0x1A:
        case 0x1B:
          v10 = (hkpShapeContainer *)m_userData->vfptr[7].__vecDelDtor(m_userData, 0x40000000u);
          hkpShapeDisplayBuilder::buildShapeDisplay_ShapeContainer(this, v10, transform, displayGeometries);
          return;
        case 8:
          hkpShapeDisplayBuilder::buildShapeDisplay_ListShape(
            this,
            (hkpListShape *)m_userData,
            transform,
            displayGeometries);
          return;
        case 9:
          m_userData = (hkpShape *)m_userData[2].m_userData;
          scale = 0i64;
          goto LABEL_5;
        case 0xA:
          v9.m_quad = (__m128)m_userData[2].hkReferencedObject;
          if ( scale )
            v9.m_quad = _mm_mul_ps(v9.m_quad, scale->m_quad);
          bTc.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
          bTc.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
          bTc.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
          bTc.m_translation = (hkVector4f)v9.m_quad;
          hkTransformf::setMul(&transforma, transform, &bTc);
          hkpShapeDisplayBuilder::buildShapeDisplay(
            this,
            *(hkpShape **)&m_userData[1].m_type.m_storage,
            &transforma,
            displayGeometries,
            scale);
          return;
        case 0xB:
          hkQsTransformf::copyToTransformNoScale((hkQsTransformf *)&m_userData[2], &transforma);
          hkTransformf::setMul(&bTc, transform, &transforma);
          hkpShapeDisplayBuilder::buildShapeDisplay(
            this,
            *(hkpShape **)&m_userData[1].m_type.m_storage,
            &bTc,
            displayGeometries,
            (hkVector4f *)&m_userData[3]);
          return;
        case 0xC:
          hkpShapeDisplayBuilder::buildShapeDisplay_SampledHeightField(
            this,
            (hkpSampledHeightFieldShape *)m_userData,
            transform,
            displayGeometries);
          return;
        case 0xD:
          hkpShapeDisplayBuilder::buildShapeDisplay_ExtendedMeshShape(
            this,
            (hkpExtendedMeshShape *)m_userData,
            transform,
            displayGeometries);
          return;
        case 0xE:
          hkTransformf::setMul(&transforma, transform, (hkTransformf *)&m_userData[2].m_type);
          hkpShapeDisplayBuilder::buildShapeDisplay(
            this,
            *(hkpShape **)&m_userData[1].m_memSizeAndFlags,
            &transforma,
            displayGeometries,
            0i64);
          return;
        case 0xF:
          hkpShapeDisplayBuilder::buildShapeDisplay_CompressedMeshShape(
            this,
            (hkpCompressedMeshShape *)m_userData,
            transform,
            displayGeometries);
          return;
        case 0x10:
          hkpShapeDisplayBuilder::buildShapeDisplay_StaticCompound(
            this,
            (hkpStaticCompoundShape *)m_userData,
            transform,
            displayGeometries,
            scale);
          return;
        case 0x11:
          hkpShapeDisplayBuilder::buildShapeDisplay_BvCompressedMeshShape(
            this,
            (hkpBvCompressedMeshShape *)m_userData,
            transform,
            displayGeometries,
            scale);
          return;
        case 0x18:
          hkpShapeDisplayBuilder::buildShapeDisplay_ConvexPiece(
            this,
            (hkpConvexPieceShape *)m_userData,
            transform,
            displayGeometries);
          return;
        case 0x19:
          hkpShapeDisplayBuilder::buildShapeDisplay_MultiSphere(
            this,
            (hkpMultiSphereShape *)m_userData,
            transform,
            displayGeometries);
          return;
        case 0x1E:
          m_userData = (hkpShape *)m_userData[1].vfptr;
          scale = 0i64;
LABEL_5:
          if ( hkpShapeDisplayBuilder::buildShapeDisplay_UserShapes(
                 this,
                 &result,
                 m_userData,
                 transform,
                 displayGeometries)->m_bool )
            return;
          continue;
        case 0x1F:
          hkpShapeDisplayBuilder::buildShapeDisplay_Plane(
            this,
            (hkpPlaneShape *)m_userData,
            transform,
            displayGeometries);
          return;
        case 0x21:
          hkpShapeDisplayBuilder::buildShapeDisplay_MultiRay(
            this,
            (hkpMultiRayShape *)m_userData,
            transform,
            displayGeometries);
          return;
        default:
          hkpShapeDisplayBuilder::buildShapeDisplay_ShapeUnregistered(this, m_userData, transform, displayGeometries);
          return;
      }
    }
  }
}

// File Line: 1316
// RVA: 0xE20310
hkBool *__fastcall hkpShapeDisplayBuilder::buildPartialShapeDisplay_MultiSphere(
        hkpShapeDisplayBuilder *this,
        hkBool *result,
        hkpMultiSphereShape *s,
        hkTransformf *transform,
        int branchDepth,
        int *numSimpleShapes,
        hkpShapeContinueData *continueData,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  int v11; // xmm1_4
  _QWORD **Value; // rax
  hkDisplaySphere *v13; // rax
  hkDisplayGeometry *v14; // rax
  hkDisplayGeometry *v15; // rsi
  hkBool *v16; // rax
  hkSphere sphere; // [rsp+20h] [rbp-28h] BYREF

  if ( continueData->m_i == -1 )
    continueData->m_i = 0;
  for ( ; continueData->m_i < s->m_numSpheres; --*numSimpleShapes )
  {
    if ( *numSimpleShapes <= 0 )
      break;
    v11 = s->m_spheres[continueData->m_i].m_quad.m128_i32[3];
    sphere.m_pos.m_quad = aabbOut.m_quad;
    sphere.m_pos.m_quad.m128_i32[3] = v11;
    Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
    v13 = (hkDisplaySphere *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 144i64);
    if ( v13 )
    {
      hkDisplaySphere::hkDisplaySphere(
        v13,
        &sphere,
        this->m_environment.m_sphereThetaRes,
        this->m_environment.m_spherePhiRes);
      v15 = v14;
    }
    else
    {
      v15 = 0i64;
    }
    v15->m_transform.m_translation = s->m_spheres[continueData->m_i];
    if ( displayGeometries->m_size == (displayGeometries->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&displayGeometries->m_data, 8);
    displayGeometries->m_data[displayGeometries->m_size++] = v15;
    ++continueData->m_i;
  }
  v16 = result;
  if ( continueData->m_i == s->m_numSpheres )
  {
    continueData->m_i = -1;
    result->m_bool = 1;
  }
  else
  {
    result->m_bool = 0;
  }
  return v16;
}

// File Line: 1351
// RVA: 0xE20890
hkBool *__fastcall hkpShapeDisplayBuilder::buildPartialShapeDisplay_MultiRay(
        hkpShapeDisplayBuilder *this,
        hkBool *result,
        hkpMultiRayShape *s,
        hkTransformf *transform,
        int branchDepth,
        int *numSimpleShapes,
        hkpShapeContinueData *continueData,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkBool *v8; // r12
  hkDisplayGeometry *CurrentRawGeometry; // rax
  hkpShapeContinueData *v11; // rdi
  hkGeometry *m_geometry; // r13
  hkTransformf *v13; // r12
  int *v14; // r14
  int v15; // esi
  hkpMultiRayShape::Ray *m_data; // rax
  __int64 m_size; // rbp
  __int64 m_i; // rcx
  int v19; // r9d
  __m128 m_quad; // xmm6
  hkVector4f v21; // xmm7
  int v22; // eax
  int v23; // eax
  hkVector4f *v24; // r8
  __int64 v25; // rbp
  int v26; // r9d
  int v27; // eax
  int v28; // eax
  __int64 v29; // rbp
  int v30; // r9d
  int v31; // eax
  int v32; // eax
  hkVector4f *v33; // r8
  __int64 v34; // rbp
  int v35; // r9d
  int v36; // eax
  int v37; // eax
  hkGeometry::Triangle *v38; // rcx
  int v39; // eax
  hkBool *v40; // rax
  hkResult v41; // [rsp+30h] [rbp-68h] BYREF
  hkResult v42; // [rsp+34h] [rbp-64h] BYREF
  hkResult resulta; // [rsp+B0h] [rbp+18h] BYREF
  hkTransformf *a; // [rsp+B8h] [rbp+20h]

  a = transform;
  v8 = result;
  CurrentRawGeometry = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries);
  v11 = continueData;
  m_geometry = CurrentRawGeometry->m_geometry;
  if ( continueData->m_i == -1 )
    continueData->m_i = 0;
  if ( v11->m_i < s->m_rays.m_size )
  {
    v13 = a;
    v14 = numSimpleShapes;
    v15 = 2;
    do
    {
      if ( *v14 <= 0 )
        break;
      m_data = s->m_rays.m_data;
      m_size = m_geometry->m_vertices.m_size;
      m_i = v11->m_i;
      v19 = m_size + 1;
      m_quad = m_data[m_i].m_start.m_quad;
      v21.m_quad = (__m128)m_data[m_i].m_end;
      v22 = m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v22 >= (int)m_size + 1 )
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
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&m_geometry->m_vertices.m_data,
          v19,
          16);
      }
      ++m_geometry->m_vertices.m_size;
      v24 = &m_geometry->m_vertices.m_data[m_size];
      *v24 = (hkVector4f)m_quad;
      hkVector4f::setTransformedPos(v24, v13, v24);
      v25 = m_geometry->m_vertices.m_size;
      v26 = v25 + 1;
      v27 = m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v27 >= (int)v25 + 1 )
      {
        resulta.m_enum = HK_SUCCESS;
      }
      else
      {
        v28 = 2 * v27;
        if ( v26 < v28 )
          v26 = v28;
        hkArrayUtil::_reserve(
          &resulta,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&m_geometry->m_vertices.m_data,
          v26,
          16);
      }
      ++m_geometry->m_vertices.m_size;
      m_geometry->m_vertices.m_data[v25].m_quad = _mm_add_ps((__m128)_xmm, m_quad);
      v29 = m_geometry->m_vertices.m_size;
      v30 = v29 + 1;
      v31 = m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v31 >= (int)v29 + 1 )
      {
        v41.m_enum = HK_SUCCESS;
      }
      else
      {
        v32 = 2 * v31;
        if ( v30 < v32 )
          v30 = v32;
        hkArrayUtil::_reserve(
          &v41,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&m_geometry->m_vertices.m_data,
          v30,
          16);
      }
      ++m_geometry->m_vertices.m_size;
      v33 = &m_geometry->m_vertices.m_data[v29];
      *v33 = (hkVector4f)v21.m_quad;
      hkVector4f::setTransformedPos(v33, v13, v33);
      v34 = m_geometry->m_triangles.m_size;
      v35 = v34 + 1;
      v36 = m_geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
      if ( v36 >= (int)v34 + 1 )
      {
        v42.m_enum = HK_SUCCESS;
      }
      else
      {
        v37 = 2 * v36;
        if ( v35 < v37 )
          v35 = v37;
        hkArrayUtil::_reserve(
          &v42,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&m_geometry->m_triangles.m_data,
          v35,
          16);
      }
      ++m_geometry->m_triangles.m_size;
      v38 = &m_geometry->m_triangles.m_data[v34];
      v38->m_a = v15 - 2;
      v38->m_c = v15;
      v38->m_material = -1;
      v39 = v15 - 1;
      v15 += 3;
      v38->m_b = v39;
      ++v11->m_i;
      --*v14;
    }
    while ( v11->m_i < s->m_rays.m_size );
    v8 = result;
  }
  v40 = v8;
  if ( v11->m_i == s->m_rays.m_size )
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
hkBool *__fastcall hkpShapeDisplayBuilder::buildPartialShapeDisplay_ShapeContainer(
        hkpShapeDisplayBuilder *this,
        hkBool *result,
        hkpShapeContainer *shapeContainer,
        hkTransformf *transform,
        int branchDepth,
        int *numSimpleShapes,
        hkpShapeContinueData *continueData,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries,
        hkVector4f *scale)
{
  hkpShapeContinueData *v9; // rdi
  __int64 v10; // r13
  __int64 m_size; // rdx
  unsigned int *v14; // rbx
  unsigned int v15; // ebx
  hkVector4f *v16; // r12
  int *v17; // rbp
  hkpSphereShape *v18; // rax
  char v20[512]; // [rsp+50h] [rbp-238h] BYREF

  v9 = continueData;
  v10 = branchDepth;
  if ( continueData->m_shapeKeys.m_size == branchDepth )
  {
    if ( continueData->m_shapeKeys.m_size == (continueData->m_shapeKeys.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&continueData->m_shapeKeys.m_data, 4);
    m_size = v9->m_shapeKeys.m_size;
    v14 = &v9->m_shapeKeys.m_data[m_size];
    v9->m_shapeKeys.m_size = m_size + 1;
    *v14 = shapeContainer->vfptr->getFirstKey(shapeContainer);
  }
  v15 = v9->m_shapeKeys.m_data[v10];
  if ( v15 == -1 )
  {
LABEL_13:
    --v9->m_shapeKeys.m_size;
    result->m_bool = 1;
  }
  else
  {
    v16 = scale;
    v17 = numSimpleShapes;
    while ( *v17 > 0 )
    {
      v18 = (hkpSphereShape *)shapeContainer->vfptr->getChildShape(shapeContainer, v15, v20);
      if ( !hkpShapeDisplayBuilder::buildPartialShapeDisplay(
              this,
              (hkBool *)&branchDepth,
              v18,
              transform,
              (int)v10 + 1,
              v17,
              v9,
              displayGeometries,
              v16)->m_bool )
        break;
      v15 = shapeContainer->vfptr->getNextKey(shapeContainer, v15);
      v9->m_shapeKeys.m_data[v10] = v15;
      if ( v15 == -1 )
        goto LABEL_13;
    }
    result->m_bool = 0;
  }
  return result;
}

// File Line: 1452
// RVA: 0xE20470
hkBool *__fastcall hkpShapeDisplayBuilder::buildPartialShapeDisplay_SampledHeightField(
        hkpShapeDisplayBuilder *this,
        hkBool *result,
        hkpSampledHeightFieldShape *heightField,
        hkTransformf *transform,
        int branchDepth,
        int *numSimpleShapes,
        hkpShapeContinueData *continueData,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  __m128 v8; // xmm0
  hkBool *v9; // rbx
  hkDisplayGeometry *CurrentRawGeometry; // rax
  hkpShapeContinueData *v13; // rsi
  hkVector4f v14; // xmm7
  hkGeometry *m_geometry; // r13
  int *v16; // r15
  int m_j; // r8d
  __int64 m_i; // rdx
  __m128 v19; // xmm0
  hkBaseObjectVtbl *vfptr; // rax
  int v21; // edx
  hkBaseObjectVtbl *v22; // rax
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  int v25; // edx
  int v26; // r8d
  hkBaseObjectVtbl *v27; // rax
  __m128 v28; // xmm0
  __m128 v29; // xmm3
  int m_size; // edi
  __m128 v31; // xmm4
  int v32; // eax
  int v33; // r9d
  __m128 v34; // xmm1
  int v35; // eax
  hkVector4f *v36; // rbx
  __int64 v37; // rbp
  int v38; // eax
  int v39; // r9d
  int v40; // eax
  hkGeometry::Triangle *v41; // rcx
  int v42; // eax
  hkGeometry::Triangle *v43; // r8
  hkBool *v44; // rax
  hkResult v45; // [rsp+30h] [rbp-A8h] BYREF
  hkResult v46; // [rsp+34h] [rbp-A4h] BYREF
  hkVector4f b; // [rsp+40h] [rbp-98h] BYREF
  hkVector4f v48; // [rsp+50h] [rbp-88h] BYREF
  hkVector4f v49; // [rsp+60h] [rbp-78h] BYREF
  hkVector4f v50; // [rsp+70h] [rbp-68h] BYREF
  hkResult resulta; // [rsp+F0h] [rbp+18h] BYREF

  v9 = result;
  CurrentRawGeometry = hkpShapeDisplayBuilder::getCurrentRawGeometry(this, displayGeometries);
  v13 = continueData;
  v14.m_quad = (__m128)heightField->m_intToFloatScale;
  m_geometry = CurrentRawGeometry->m_geometry;
  if ( continueData->m_i == -1 )
    continueData->m_i = 0;
  if ( v13->m_i >= heightField->m_xRes - 1 )
  {
LABEL_32:
    v44 = v9;
    if ( v13->m_i == heightField->m_xRes - 1 )
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
        v9 = result;
        goto LABEL_32;
      }
      if ( v13->m_j == -1 )
        v13->m_j = 0;
      for ( ; v13->m_j < heightField->m_zRes - 1; --*v16 )
      {
        if ( *v16 <= 0 )
          break;
        *(double *)v8.m128_u64 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))heightField->vfptr[10].__vecDelDtor)(
                                   heightField,
                                   (unsigned int)v13->m_i,
                                   (unsigned int)v13->m_j);
        m_j = v13->m_j;
        m_i = (unsigned int)v13->m_i;
        v19 = _mm_unpacklo_ps(v8, (__m128)0i64);
        vfptr = heightField->vfptr;
        b.m_quad = _mm_mul_ps(
                     _mm_unpacklo_ps(
                       _mm_unpacklo_ps(
                         (__m128)COERCE_UNSIGNED_INT((float)v13->m_i),
                         (__m128)COERCE_UNSIGNED_INT((float)m_j)),
                       v19),
                     v14.m_quad);
        *(double *)v19.m128_u64 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, __int64, _QWORD))vfptr[10].__vecDelDtor)(
                                    heightField,
                                    m_i,
                                    (unsigned int)(m_j + 1));
        v21 = v13->m_i;
        v22 = heightField->vfptr;
        v23 = _mm_unpacklo_ps(v19, (__m128)0i64);
        v24 = (__m128)COERCE_UNSIGNED_INT((float)v13->m_j);
        v24.m128_f32[0] = v24.m128_f32[0] + 1.0;
        v48.m_quad = _mm_mul_ps(
                       _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v21), v24), v23),
                       v14.m_quad);
        *(double *)v23.m128_u64 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD))v22[10].__vecDelDtor)(
                                    heightField,
                                    (unsigned int)(v21 + 1));
        v25 = v13->m_i;
        v26 = v13->m_j;
        v27 = heightField->vfptr;
        v28 = _mm_unpacklo_ps(v23, (__m128)0i64);
        v29 = (__m128)COERCE_UNSIGNED_INT((float)v25);
        v29.m128_f32[0] = v29.m128_f32[0] + 1.0;
        v49.m_quad = _mm_mul_ps(
                       _mm_unpacklo_ps(_mm_unpacklo_ps(v29, (__m128)COERCE_UNSIGNED_INT((float)v26)), v28),
                       v14.m_quad);
        *(double *)v28.m128_u64 = ((double (__fastcall *)(hkpSampledHeightFieldShape *, _QWORD, _QWORD))v27[10].__vecDelDtor)(
                                    heightField,
                                    (unsigned int)(v25 + 1),
                                    (unsigned int)(v26 + 1));
        m_size = m_geometry->m_vertices.m_size;
        v8 = _mm_unpacklo_ps(v28, (__m128)0i64);
        v31 = (__m128)COERCE_UNSIGNED_INT((float)v13->m_i);
        v32 = m_geometry->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
        v31.m128_f32[0] = v31.m128_f32[0] + 1.0;
        v33 = m_size + 4;
        v34 = (__m128)COERCE_UNSIGNED_INT((float)v13->m_j);
        v34.m128_f32[0] = v34.m128_f32[0] + 1.0;
        v50.m_quad = _mm_mul_ps(_mm_unpacklo_ps(_mm_unpacklo_ps(v31, v34), v8), v14.m_quad);
        if ( v32 >= m_size + 4 )
        {
          resulta.m_enum = HK_SUCCESS;
        }
        else
        {
          v35 = 2 * v32;
          if ( v33 < v35 )
            v33 = v35;
          hkArrayUtil::_reserve(
            &resulta,
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&m_geometry->m_vertices.m_data,
            v33,
            16);
        }
        m_geometry->m_vertices.m_size += 4;
        v36 = &m_geometry->m_vertices.m_data[m_size];
        hkVector4f::setTransformedPos(v36, transform, &b);
        hkVector4f::setTransformedPos(v36 + 1, transform, &v48);
        hkVector4f::setTransformedPos(v36 + 2, transform, &v49);
        hkVector4f::setTransformedPos(v36 + 3, transform, &v50);
        ((void (__fastcall *)(hkpSampledHeightFieldShape *, hkpShapeContinueData **))heightField->vfptr[10].__first_virtual_table_function__)(
          heightField,
          &continueData);
        v37 = m_geometry->m_triangles.m_size;
        v38 = m_geometry->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
        v39 = v37 + 2;
        if ( (_BYTE)continueData )
        {
          if ( v38 >= v39 )
          {
            v45.m_enum = HK_SUCCESS;
          }
          else
          {
            v40 = 2 * v38;
            if ( v39 < v40 )
              v39 = v40;
            hkArrayUtil::_reserve(
              &v45,
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&m_geometry->m_triangles.m_data,
              v39,
              16);
          }
          m_geometry->m_triangles.m_size += 2;
          v41 = &m_geometry->m_triangles.m_data[v37];
          v41->m_b = m_size + 1;
          v41->m_a = m_size;
          v41->m_material = -1;
          v41->m_c = m_size + 3;
          v41[1].m_b = m_size + 3;
          v41[1].m_a = m_size;
          v41[1].m_material = -1;
          v41[1].m_c = m_size + 2;
        }
        else
        {
          if ( v38 >= v39 )
          {
            v46.m_enum = HK_SUCCESS;
          }
          else
          {
            v42 = 2 * v38;
            if ( v39 < v42 )
              v39 = v42;
            hkArrayUtil::_reserve(
              &v46,
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&m_geometry->m_triangles.m_data,
              v39,
              16);
          }
          m_geometry->m_triangles.m_size += 2;
          v43 = &m_geometry->m_triangles.m_data[v37];
          v43->m_a = m_size;
          v43->m_b = m_size + 1;
          v43->m_c = m_size + 2;
          v43->m_material = -1;
          v43[1].m_a = m_size + 3;
          v43[1].m_b = m_size + 2;
          v43[1].m_c = m_size + 1;
          v43[1].m_material = -1;
        }
        ++v13->m_j;
      }
      if ( v13->m_j != heightField->m_zRes - 1 )
        break;
      ++v13->m_i;
      v13->m_j = -1;
      if ( v13->m_i >= heightField->m_xRes - 1 )
        goto LABEL_31;
    }
    v44 = result;
    result->m_bool = 0;
  }
  return v44;
}

// File Line: 1544
// RVA: 0xE1FD80
hkBool *__fastcall hkpShapeDisplayBuilder::buildPartialShapeDisplay(
        hkpShapeDisplayBuilder *this,
        hkBool *result,
        hkpSphereShape *shape,
        hkTransformf *transform,
        int branchDepth,
        int *numSimpleShapes,
        hkpShapeContinueData *continueData,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries,
        hkVector4f *scale)
{
  hkBool *v12; // rax
  hkReferencedObject v13; // xmm2
  hkpShape *v14; // r8
  hkpShapeContainer *v15; // rax
  hkVector4f *v16; // [rsp+40h] [rbp-81h]
  hkBool v17; // [rsp+50h] [rbp-71h] BYREF
  hkTransformf bTc; // [rsp+60h] [rbp-61h] BYREF
  hkTransformf transforma; // [rsp+A0h] [rbp-21h] BYREF
  hkBool resulta; // [rsp+110h] [rbp+4Fh] BYREF

  switch ( shape->m_type.m_storage )
  {
    case 0:
      hkpShapeDisplayBuilder::buildShapeDisplay_Sphere(this, shape, transform, displayGeometries, scale);
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
      v15 = (hkpShapeContainer *)((__int64 (__fastcall *)(hkpSphereShape *))shape->vfptr[7].__vecDelDtor)(shape);
      hkpShapeDisplayBuilder::buildPartialShapeDisplay_ShapeContainer(
        this,
        result,
        v15,
        transform,
        branchDepth,
        numSimpleShapes,
        continueData,
        displayGeometries,
        scale);
      return result;
    case 9:
      hkpShapeDisplayBuilder::buildPartialShapeDisplay(
        this,
        result,
        *(hkpShape **)&shape[1].m_radius,
        transform,
        branchDepth,
        numSimpleShapes,
        continueData,
        displayGeometries,
        0i64);
      return result;
    case 0xA:
      v13 = *(hkReferencedObject *)&shape[1].m_memSizeAndFlags;
      if ( scale )
        v13 = (hkReferencedObject)_mm_mul_ps((__m128)v13, scale->m_quad);
      bTc.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
      bTc.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
      bTc.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
      bTc.m_translation = (hkVector4f)v13;
      hkTransformf::setMul(&transforma, transform, &bTc);
      v14 = *(hkpShape **)&shape->m_pad16[2];
      v16 = scale;
      goto LABEL_12;
    case 0xB:
      hkQsTransformf::copyToTransformNoScale((hkQsTransformf *)&shape[1].m_memSizeAndFlags, &transforma);
      hkTransformf::setMul(&bTc, transform, &transforma);
      hkpShapeDisplayBuilder::buildPartialShapeDisplay(
        this,
        result,
        *(hkpShape **)&shape->m_pad16[2],
        &bTc,
        branchDepth,
        numSimpleShapes,
        continueData,
        displayGeometries,
        (hkVector4f *)shape[1].m_pad16);
      return result;
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
      return result;
    case 0xE:
      hkTransformf::setMul(&transforma, transform, (hkTransformf *)&shape[1].m_userData);
      v14 = *(hkpShape **)shape->m_pad16;
      v16 = 0i64;
LABEL_12:
      hkpShapeDisplayBuilder::buildPartialShapeDisplay(
        this,
        result,
        v14,
        &transforma,
        branchDepth,
        numSimpleShapes,
        continueData,
        displayGeometries,
        v16);
      return result;
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
        *(hkpShape **)&shape->m_radius,
        transform,
        branchDepth,
        numSimpleShapes,
        continueData,
        displayGeometries,
        0i64);
      return result;
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
      return result;
    default:
      if ( hkpShapeDisplayBuilder::buildShapeDisplay_UserShapes(this, &v17, shape, transform, displayGeometries)->m_bool )
LABEL_24:
        --*numSimpleShapes;
LABEL_25:
      v12 = result;
      result->m_bool = 1;
      return v12;
  }
}

// File Line: 1708
// RVA: 0xE1C450
hkReferencedObject *__fastcall hkpShapeDisplayBuilder::getInitialContinueData(
        hkpShapeDisplayBuilder *this,
        hkReferencedObject *source)
{
  _QWORD **Value; // rax
  hkReferencedObject *result; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkReferencedObject *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpShapeContinueData::`vftable;
    result[1].vfptr = 0i64;
    *(_DWORD *)&result[1].m_memSizeAndFlags = 0;
    *(_QWORD *)(&result[1].m_referenceCount + 1) = 0xFFFFFFFF80000000ui64;
    HIDWORD(result[2].vfptr) = -1;
  }
  return result;
}

// File Line: 1714
// RVA: 0xE1FC60
hkDisplayGeometry *__fastcall hkpShapeDisplayBuilder::getCurrentRawGeometry(
        hkpShapeDisplayBuilder *this,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  _QWORD **Value; // rax
  __int64 v5; // rax
  hkDisplayGeometry *v6; // rsi
  hkGeometry *v7; // rbx
  _QWORD **v8; // rax
  hkDisplayConvex *v9; // rax
  hkDisplayGeometry *v10; // rax

  if ( this->m_currentGeometry )
    return this->m_currentGeometry;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  v6 = 0i64;
  v7 = (hkGeometry *)v5;
  if ( v5 )
  {
    *(_DWORD *)(v5 + 8) = 0x1FFFF;
    *(_QWORD *)v5 = &hkGeometry::`vftable;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_DWORD *)(v5 + 24) = 0;
    *(_DWORD *)(v5 + 28) = 0x80000000;
    *(_QWORD *)(v5 + 32) = 0i64;
    *(_DWORD *)(v5 + 40) = 0;
    *(_DWORD *)(v5 + 44) = 0x80000000;
  }
  else
  {
    v7 = 0i64;
  }
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkDisplayConvex *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v8[11] + 8i64))(v8[11], 112i64);
  if ( v9 )
  {
    hkDisplayConvex::hkDisplayConvex(v9, v7);
    v6 = v10;
  }
  this->m_currentGeometry = v6;
  if ( displayGeometries->m_size == (displayGeometries->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&displayGeometries->m_data, 8);
  displayGeometries->m_data[displayGeometries->m_size++] = this->m_currentGeometry;
  return this->m_currentGeometry;
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
  _QWORD **Value; // rax
  hkReferencedObject *result; // rax

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  result = (hkReferencedObject *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  if ( result )
  {
    *(_DWORD *)&result->m_memSizeAndFlags = 0x1FFFF;
    result->vfptr = (hkBaseObjectVtbl *)&hkpUserShapeDisplayBuilder::`vftable;
    result[1].vfptr = 0i64;
    *(_DWORD *)&result[1].m_memSizeAndFlags = 0;
    *(_DWORD *)(&result[1].m_referenceCount + 1) = 0x80000000;
  }
  return result;
}

// File Line: 1735
// RVA: 0xE20B70
void __fastcall hkpUserShapeDisplayBuilder::registerUserShapeDisplayBuilder(
        hkpUserShapeDisplayBuilder *this,
        void (__fastcall *f)(hkpShape *, hkTransformf *, hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *, hkpShapeDisplayBuilder *),
        hkcdShapeType::ShapeTypeEnum type)
{
  __int64 m_size; // r10
  __int64 v4; // r9
  hkcdShapeType::ShapeTypeEnum *p_type; // rax
  hkArray<hkpUserShapeDisplayBuilder::UserShapeBuilder,hkContainerHeapAllocator> *p_m_userShapeBuilders; // rbx
  hkpUserShapeDisplayBuilder::UserShapeBuilder *v8; // rcx
  __int64 v9; // [rsp+28h] [rbp-10h]

  m_size = this->m_userShapeBuilders.m_size;
  v4 = 0i64;
  if ( m_size <= 0 )
  {
LABEL_5:
    p_m_userShapeBuilders = &this->m_userShapeBuilders;
    LODWORD(v9) = type;
    if ( this->m_userShapeBuilders.m_size == (this->m_userShapeBuilders.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_userShapeBuilders->m_data, 16);
    v8 = &p_m_userShapeBuilders->m_data[p_m_userShapeBuilders->m_size];
    if ( v8 )
    {
      v8->f = f;
      *(_QWORD *)&v8->type = v9;
    }
    ++p_m_userShapeBuilders->m_size;
  }
  else
  {
    p_type = &this->m_userShapeBuilders.m_data->type;
    while ( *p_type != type )
    {
      ++v4;
      p_type += 4;
      if ( v4 >= m_size )
        goto LABEL_5;
    }
  }
}

// File Line: 1752
// RVA: 0xE1BDE0
void __fastcall hkpShapeDisplayBuilder::addObjectToDebugDisplay(hkpShape *shape, hkTransformf *t, unsigned __int64 id)
{
  int m_size; // eax
  hkDisplayGeometry **m_data; // rdx
  int v8; // eax
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> displayGeometries; // [rsp+30h] [rbp-38h] BYREF
  hkpShapeDisplayBuilder v10; // [rsp+40h] [rbp-28h] BYREF
  hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment env; // [rsp+88h] [rbp+20h] BYREF

  hkpShapeDisplayBuilder::hkpShapeDisplayBuilderEnvironment::hkpShapeDisplayBuilderEnvironment(&env);
  hkpShapeDisplayBuilder::hkpShapeDisplayBuilder(&v10, &env);
  displayGeometries.m_data = 0i64;
  displayGeometries.m_size = 0;
  displayGeometries.m_capacityAndFlags = 0x80000000;
  hkpShapeDisplayBuilder::buildDisplayGeometries(&v10, shape, &displayGeometries);
  hkDebugDisplay::addGeometry(
    hkSingleton<hkDebugDisplay>::s_instance,
    &displayGeometries,
    t,
    id,
    0,
    (unsigned __int64)shape);
  m_size = displayGeometries.m_size;
  if ( displayGeometries.m_size )
  {
    while ( 1 )
    {
      m_data = displayGeometries.m_data;
      if ( *displayGeometries.m_data )
      {
        (*displayGeometries.m_data)->vfptr->__vecDelDtor(*displayGeometries.m_data, 1u);
        m_size = displayGeometries.m_size;
        m_data = displayGeometries.m_data;
      }
      v8 = m_size - 1;
      displayGeometries.m_size = v8;
      if ( !v8 )
        break;
      *m_data = m_data[v8];
      m_size = displayGeometries.m_size;
      if ( !displayGeometries.m_size )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    m_data = displayGeometries.m_data;
  }
  displayGeometries.m_size = 0;
  if ( displayGeometries.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      m_data,
      8 * displayGeometries.m_capacityAndFlags);
}

// File Line: 1771
// RVA: 0xE1C360
// attributes: thunk
void __fastcall hkpShapeDisplayBuilder::buildDisplayGeometries(
        hkpShapeDisplayBuilder *this,
        hkpShape *source,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  ?buildDisplayGeometries@hkpShapeDisplayBuilder@@QEAAXPEBVhkpShape@@AEAV?$hkArray@PEAVhkDisplayGeometry@@UhkContainerHeapAllocator@@@@@Z(
    this,
    source,
    displayGeometries);
}

// File Line: 1776
// RVA: 0xE1C370
hkBool *__fastcall hkpShapeDisplayBuilder::buildPartialDisplayGeometries(
        hkpShapeDisplayBuilder *this,
        hkBool *result,
        hkpShape *source,
        int *numSimpleShapes,
        hkpShapeContinueData *continueData,
        hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *displayGeometries)
{
  hkArray<hkDisplayGeometry *,hkContainerHeapAllocator> *v11; // [rsp+38h] [rbp-60h]
  hkTransformf transform; // [rsp+50h] [rbp-48h] BYREF

  transform.m_rotation.m_col0 = (hkVector4f)::transform.m_quad;
  transform.m_rotation.m_col1 = (hkVector4f)direction.m_quad;
  transform.m_rotation.m_col2 = (hkVector4f)stru_141A71280.m_quad;
  transform.m_translation = 0i64;
  hkpShapeDisplayBuilder::resetCurrentRawGeometry(this);
  v11 = displayGeometries;
  displayGeometries->m_size = 0;
  if ( hkpShapeDisplayBuilder::buildPartialShapeDisplay(
         this,
         (hkBool *)&displayGeometries,
         source,
         &transform,
         0,
         numSimpleShapes,
         continueData,
         v11,
         0i64)->m_bool )
  {
    hkReferencedObject::removeReference(continueData);
    result->m_bool = 1;
  }
  else
  {
    result->m_bool = 0;
  }
  return result;
}

