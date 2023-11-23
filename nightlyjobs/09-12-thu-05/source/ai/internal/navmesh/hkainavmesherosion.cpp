// File Line: 51
// RVA: 0xBA58D0
char __fastcall ErosionWrapperCallbacks::stepStartedCallback(
        ErosionWrapperCallbacks *this,
        unsigned int stepType,
        hkaiNavMeshGenerationProgressCallbackContext *ctx)
{
  hkaiNavMeshGenerationProgressCallbackContext v6; // [rsp+30h] [rbp-78h] BYREF

  if ( !this->m_navGenCallbacks )
    return 1;
  hkaiNavMeshGenerationProgressCallbackContext::hkaiNavMeshGenerationProgressCallbackContext(&v6, ctx->m_settings);
  return ((__int64 (__fastcall *)(hkaiNavMeshGenerationProgressCallback *, __int64, _QWORD))this->m_navGenCallbacks->vfptr->stepMiddleCallback)(
           this->m_navGenCallbacks,
           9i64,
           stepType);
}

// File Line: 70
// RVA: 0xBA4E40
__int64 __fastcall hkaiNavMeshErosion::erode(
        hkaiEdgeGeometryRaycaster *mesh,
        hkaiNavMeshGenerationSettings *originalSettings,
        hkaiEdgeGeometryRaycaster *edgeConnectionRaycaster,
        hkaiNavMeshGenerationProgressCallback *callbacks)
{
  char v4; // si
  hkVector4f *v6; // r8
  __m128 m_minCharacterWidth_low; // xmm14
  hkSimdFloat32 *v10; // r15
  int m_size; // eax
  __m128 *v12; // rax
  __int64 v13; // rdx
  hkVector4f v14; // xmm0
  hkRefPtr<hkaiVolume const > *m_data; // rdi
  __int64 i; // rbx
  hkReferencedObject *m_pntr; // rcx
  hkRefPtr<hkaiMaterialPainter const > *v18; // rdi
  __int64 j; // rbx
  hkReferencedObject *v20; // rcx
  int v21; // eax
  __int128 *v22; // rcx
  __m128 v23; // xmm0
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  int v26; // ecx
  char *v27; // rdx
  __int64 v28; // rdi
  unsigned __int64 v29; // r14
  int v30; // r13d
  __int64 v31; // rdx
  int v32; // esi
  int v33; // r8d
  __int64 v34; // rbx
  int v35; // ecx
  unsigned __int64 v36; // r12
  __int64 v37; // rdx
  int v38; // ecx
  int v39; // eax
  hkGeometry::Triangle *v40; // rdx
  int v41; // r9d
  __int64 v42; // rcx
  int v43; // r13d
  __int64 v44; // r10
  float v45; // xmm7_4
  __int64 v46; // rax
  int v47; // r8d
  int *v48; // r11
  int v49; // edx
  int v50; // esi
  __m128 m_quad; // xmm6
  int v52; // r12d
  unsigned __int64 v53; // rbx
  __m128 v54; // xmm8
  int v55; // eax
  int v56; // edx
  __m128 v57; // xmm1
  __m128 v58; // xmm0
  __m128 v59; // xmm5
  __m128 v60; // xmm5
  __m128 v61; // xmm1
  __m128 v62; // xmm3
  __m128 v63; // xmm2
  __m128 v64; // xmm4
  int v65; // ebx
  int v66; // r8d
  int v67; // ecx
  unsigned __int64 v68; // r12
  __int64 v69; // rsi
  __int64 v70; // rdx
  int v71; // ecx
  hkGeometry::Triangle *v72; // rdx
  int v73; // eax
  __int64 v74; // r12
  __int64 v75; // rsi
  unsigned __int64 v76; // rdx
  unsigned __int64 v77; // rcx
  __m128 v78; // xmm6
  __m128 v79; // xmm7
  _QWORD **Value; // rax
  hkaiPlaneVolume *v81; // rax
  hkaiPlaneVolume *v82; // rax
  hkaiPlaneVolume *v83; // rbx
  __int64 v84; // rax
  __int64 v85; // rcx
  __m128 v86; // xmm2
  int v87; // edx
  hkRefPtr<hkaiVolume const > *v88; // r13
  unsigned int v89; // esi
  int v90; // ebx
  __int64 v91; // rdi
  hkVector4f *edgeConnectionRayCaster; // [rsp+20h] [rbp-D0h]
  hkaiNavMesh *mesha; // [rsp+30h] [rbp-C0h] BYREF
  __int64 v95; // [rsp+38h] [rbp-B8h]
  int v96; // [rsp+40h] [rbp-B0h]
  hkGeometry _triMeshIn; // [rsp+48h] [rbp-A8h] BYREF
  hkaiNavMeshGenerationProgressCallback _callbacks; // [rsp+78h] [rbp-78h] BYREF
  hkaiNavMeshGenerationProgressCallback *v99; // [rsp+80h] [rbp-70h]
  int faceIndex[4]; // [rsp+90h] [rbp-60h] BYREF
  hkStringBuf v101; // [rsp+A0h] [rbp-50h] BYREF
  hkaiNavMeshGenerationOutputs outputs; // [rsp+130h] [rbp+40h] BYREF
  hkaiNavMeshUtils v103; // [rsp+160h] [rbp+70h] BYREF
  hkaiNavMeshGenerationSettings input; // [rsp+170h] [rbp+80h] BYREF
  hkaiNavMesh other; // [rsp+360h] [rbp+270h] BYREF
  __int128 v106[8]; // [rsp+410h] [rbp+320h] BYREF
  hkVector4f points; // [rsp+490h] [rbp+3A0h] BYREF
  __int128 v108[10]; // [rsp+500h] [rbp+410h]
  hkResult result[2]; // [rsp+670h] [rbp+580h] BYREF
  void *retaddr; // [rsp+678h] [rbp+588h]
  hkaiNavMeshGenerationProgressCallback *v112; // [rsp+688h] [rbp+598h]

  v4 = originalSettings->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  v6 = 0i64;
  m_minCharacterWidth_low = (__m128)LODWORD(originalSettings->m_minCharacterWidth);
  m_minCharacterWidth_low.m128_f32[0] = m_minCharacterWidth_low.m128_f32[0] * 0.5;
  v10 = (hkSimdFloat32 *)mesh;
  LOBYTE(retaddr) = v4;
  _triMeshIn.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  m_size = mesh->m_faceEdges.m_faceEdges.m_size;
  *(_DWORD *)&_triMeshIn.m_memSizeAndFlags = 0x1FFFF;
  _triMeshIn.m_vertices.m_data = 0i64;
  _triMeshIn.m_vertices.m_size = 0;
  _triMeshIn.m_vertices.m_capacityAndFlags = 0x80000000;
  _triMeshIn.m_triangles.m_data = 0i64;
  _triMeshIn.m_triangles.m_size = 0;
  _triMeshIn.m_triangles.m_capacityAndFlags = 0x80000000;
  if ( m_size > 0 )
  {
    LODWORD(mesha) = 16 * m_size;
    v6 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(&hkContainerHeapAllocator::s_alloc, &mesha);
    _triMeshIn.m_vertices.m_data = v6;
    _triMeshIn.m_vertices.m_capacityAndFlags = (int)mesha / 16;
  }
  v12 = (__m128 *)v10[3].m_real.m128_u64[0];
  _triMeshIn.m_vertices.m_size = v10[3].m_real.m128_i32[2];
  v13 = _triMeshIn.m_vertices.m_size;
  if ( _triMeshIn.m_vertices.m_size > 0 )
  {
    do
    {
      v14.m_quad = *v12;
      ++v6;
      ++v12;
      v6[-1] = (hkVector4f)v14.m_quad;
      --v13;
    }
    while ( v13 );
  }
  hkaiNavMeshGenerationSettings::hkaiNavMeshGenerationSettings(&input);
  hkaiNavMeshGenerationSettings::operator=(&input, originalSettings);
  m_data = input.m_carvers.m_data;
  for ( i = input.m_carvers.m_size - 1; i >= 0; m_data[i--].m_pntr = 0i64 )
  {
    m_pntr = m_data[i].m_pntr;
    if ( m_pntr )
      hkReferencedObject::removeReference(m_pntr);
  }
  v18 = input.m_painters.m_data;
  input.m_carvers.m_size = 0;
  for ( j = input.m_painters.m_size - 1; j >= 0; v18[j--].m_pntr = 0i64 )
  {
    v20 = v18[j].m_pntr;
    if ( v20 )
      hkReferencedObject::removeReference(v20);
  }
  input.m_painters.m_size = 0;
  v21 = 0;
  v22 = v106;
  do
  {
    v23 = m_minCharacterWidth_low;
    if ( (v21 & 4) == 0 )
      v23 = _mm_xor_ps(m_minCharacterWidth_low, (__m128)(unsigned int)_xmm[0]);
    v24 = m_minCharacterWidth_low;
    if ( (v21 & 2) == 0 )
      v24 = _mm_xor_ps(m_minCharacterWidth_low, (__m128)(unsigned int)_xmm[0]);
    v25 = m_minCharacterWidth_low;
    if ( (v21 & 1) == 0 )
      v25 = _mm_xor_ps(m_minCharacterWidth_low, (__m128)(unsigned int)_xmm[0]);
    ++v21;
    *v22++ = (__int128)_mm_unpacklo_ps(_mm_unpacklo_ps(v25, v23), _mm_unpacklo_ps(v24, (__m128)0i64));
  }
  while ( v21 < 8 );
  v26 = 0;
  v27 = 0i64;
  LODWORD(mesha) = 0;
  _callbacks.vfptr = 0i64;
  if ( v10[1].m_real.m128_i32[2] > 0 )
  {
    v28 = 0i64;
    do
    {
      v29 = v10[1].m_real.m128_u64[0];
      if ( v10[7].m_real.m128_i32[0] )
      {
        v30 = *(_DWORD *)(v10[5].m_real.m128_u64[0] + 4 * (_QWORD)v27 * v10[7].m_real.m128_i32[0]);
        v26 = (int)mesha;
      }
      else
      {
        v30 = 0;
      }
      v96 = v30;
      if ( v4 )
      {
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
          &v103,
          v10,
          (hkaiNavMesh *)(unsigned int)v26,
          (int)faceIndex,
          edgeConnectionRayCaster);
        v41 = *(__int16 *)(v28 + v29 + 8);
        v42 = 0i64;
        v43 = 0;
        v44 = 0i64;
        v95 = 0i64;
        v45 = 0.0 - 1.0;
        if ( v41 > 0 )
        {
          v46 = *(int *)(v28 + v29);
          *(_QWORD *)&_triMeshIn.m_triangles.m_size = v10[2].m_real.m128_u64[0];
          v47 = 1;
          v48 = (int *)(*(_QWORD *)&_triMeshIn.m_triangles.m_size + 20 * v46);
          v49 = v41 - 2;
          do
          {
            v50 = v49 + v47;
            m_quad = query.m_quad;
            v52 = v47;
            if ( v47 < v49 + v47 )
            {
              v53 = v10[3].m_real.m128_u64[0];
              v54 = *(__m128 *)(v53 + 16i64 * *v48);
              do
              {
                v55 = v52++;
                v56 = *(_DWORD *)(v28 + v29) + v55 % v41;
                v57 = _mm_sub_ps(
                        *(__m128 *)(v53 + 16i64 * *(int *)(*(_QWORD *)&_triMeshIn.m_triangles.m_size + 20i64 * v56)),
                        v54);
                v58 = _mm_sub_ps(
                        *(__m128 *)(v53 + 16i64 * *(int *)(*(_QWORD *)&_triMeshIn.m_triangles.m_size + 20i64 * v56 + 4)),
                        v54);
                v59 = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v57),
                        _mm_mul_ps(_mm_shuffle_ps(v57, v57, 201), v58));
                v60 = _mm_shuffle_ps(v59, v59, 201);
                v61 = _mm_mul_ps(v60, v60);
                v62 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v61, v61, 85), _mm_shuffle_ps(v61, v61, 0)),
                        _mm_shuffle_ps(v61, v61, 170));
                v63 = _mm_rsqrt_ps(v62);
                v64 = _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_andnot_ps(
                            _mm_cmple_ps(v62, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v63, v62), v63)),
                              _mm_mul_ps(*(__m128 *)_xmm, v63))),
                          v60),
                        *(__m128 *)faceIndex);
                m_quad = _mm_min_ps(
                           m_quad,
                           _mm_add_ps(
                             _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                             _mm_shuffle_ps(v64, v64, 170)));
              }
              while ( v52 < v50 );
              v10 = *(hkSimdFloat32 **)&result[0].m_enum;
              v49 = v41 - 2;
            }
            if ( m_quad.m128_f32[0] <= v45 )
            {
              v42 = v95;
            }
            else
            {
              v42 = v44;
              v45 = m_quad.m128_f32[0];
              v43 = v47 - 1;
              v95 = v44;
            }
            ++v47;
            ++v44;
            v48 += 5;
          }
          while ( v47 - 1 < v41 );
        }
        v65 = v43 + 1;
        LODWORD(v95) = *(_DWORD *)(v10[2].m_real.m128_u64[0] + 20 * (v42 + *(int *)(v28 + v29)));
        if ( v43 + 1 < v41 + v43 - 1 )
        {
          v66 = v95;
          do
          {
            v67 = _triMeshIn.m_triangles.m_size;
            v68 = v10[2].m_real.m128_u64[0];
            v69 = 5i64 * (*(_DWORD *)(v28 + v29) + v65 % v41);
            if ( _triMeshIn.m_triangles.m_size == (_triMeshIn.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &_triMeshIn.m_triangles, 16);
              v67 = _triMeshIn.m_triangles.m_size;
              v66 = v95;
            }
            v70 = v67;
            ++v65;
            _triMeshIn.m_triangles.m_size = v67 + 1;
            v71 = *(_DWORD *)(v68 + 4 * v69 + 4);
            v72 = &_triMeshIn.m_triangles.m_data[v70];
            v72->m_b = *(_DWORD *)(v68 + 4 * v69);
            v73 = v96;
            v72->m_a = v66;
            v72->m_material = v73;
            v72->m_c = v71;
            v41 = *(__int16 *)(v28 + v29 + 8);
          }
          while ( v65 < v41 + v43 - 1 );
        }
      }
      else
      {
        v31 = *(int *)(v28 + v29);
        v32 = v31 + 1;
        LODWORD(v95) = *(_DWORD *)(v10[2].m_real.m128_u64[0] + 20 * v31);
        if ( (int)v31 + 1 < *(__int16 *)(v28 + v29 + 8) + (int)v31 - 1 )
        {
          v33 = v95;
          v34 = 20i64 * v32;
          do
          {
            v35 = _triMeshIn.m_triangles.m_size;
            v36 = v10[2].m_real.m128_u64[0];
            if ( _triMeshIn.m_triangles.m_size == (_triMeshIn.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &_triMeshIn.m_triangles, 16);
              v35 = _triMeshIn.m_triangles.m_size;
              v33 = v95;
            }
            v37 = v35;
            ++v32;
            _triMeshIn.m_triangles.m_size = v35 + 1;
            v38 = *(_DWORD *)(v34 + v36 + 4);
            v39 = *(_DWORD *)(v34 + v36);
            v34 += 20i64;
            v40 = &_triMeshIn.m_triangles.m_data[v37];
            v40->m_c = v38;
            v40->m_a = v33;
            v40->m_b = v39;
            v40->m_material = v30;
          }
          while ( v32 < *(_DWORD *)(v28 + v29) + *(__int16 *)(v28 + v29 + 8) - 1 );
        }
      }
      v74 = *(int *)(v28 + v29);
      if ( (int)v74 < (int)v74 + *(__int16 *)(v28 + v29 + 8) )
      {
        v75 = 20 * v74;
        do
        {
          v76 = v10[2].m_real.m128_u64[0];
          if ( *(_DWORD *)(v75 + v76 + 8) == -1 || (*(_BYTE *)(v75 + v76 + 16) & 0x20) != 0 )
          {
            v77 = v10[3].m_real.m128_u64[0];
            v78 = *(__m128 *)(v77 + 16i64 * *(int *)(v75 + v76));
            v79 = *(__m128 *)(v77 + 16i64 * *(int *)(v75 + v76 + 4));
            Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v81 = (hkaiPlaneVolume *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                       Value[11],
                                       128i64);
            if ( v81 )
            {
              hkaiPlaneVolume::hkaiPlaneVolume(v81);
              v83 = v82;
            }
            else
            {
              v83 = 0i64;
            }
            v84 = 0i64;
            v85 = 8i64;
            do
            {
              v86 = (__m128)v106[v84++];
              v106[v84 + 7] = (__int128)_mm_add_ps(v78, v86);
              v108[v84] = (__int128)_mm_add_ps(v79, v86);
              --v85;
            }
            while ( v85 );
            hkaiPlaneVolume::createConvexVolume(&points, 16, v83);
            if ( v83 )
              hkReferencedObject::addReference(v83);
            v87 = input.m_carvers.m_size;
            if ( input.m_carvers.m_size == (input.m_carvers.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &input.m_carvers, 8);
              v87 = input.m_carvers.m_size;
            }
            v88 = &input.m_carvers.m_data[v87];
            if ( v88 )
            {
              if ( v83 )
                hkReferencedObject::addReference(v83);
              v88->m_pntr = v83;
              v87 = input.m_carvers.m_size;
            }
            input.m_carvers.m_size = v87 + 1;
            if ( v83 )
              hkReferencedObject::removeReference(v83);
          }
          LODWORD(v74) = v74 + 1;
          v75 += 20i64;
        }
        while ( (int)v74 < *(_DWORD *)(v28 + v29) + *(__int16 *)(v28 + v29 + 8) );
      }
      v4 = (char)retaddr;
      v26 = (_DWORD)mesha + 1;
      v27 = (char *)&_callbacks.vfptr->stepStartedCallback + 1;
      v28 += 16i64;
      LODWORD(mesha) = v26;
      ++_callbacks.vfptr;
    }
    while ( v26 < v10[1].m_real.m128_i32[2] );
    callbacks = v112;
    edgeConnectionRaycaster = mesh;
  }
  v101.m_string.m_capacityAndFlags = -2147483520;
  v101.m_string.m_data = v101.m_string.m_storage;
  v101.m_string.m_size = 1;
  v101.m_string.m_storage[0] = 0;
  if ( input.m_saveInputSnapshot.m_bool && hkStringPtr::getLength(&input.m_snapshotFilename) )
  {
    hkStringBuf::operator=(
      &v101,
      (const char *)((unsigned __int64)input.m_snapshotFilename.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
    hkStringBuf::chompEnd(&v101, 4);
    hkStringBuf::operator+=(&v101, ".erosion.hkt");
    hkStringPtr::operator=(&input.m_snapshotFilename, v101.m_string.m_data);
  }
  *(_WORD *)&input.m_characterWidthUsage.m_storage = 0;
  input.m_materialMap.m_size = 0;
  input.m_defaultConstructionProperties.m_storage = 1;
  v99 = callbacks;
  _callbacks.vfptr = (hkaiNavMeshGenerationProgressCallbackVtbl *)&ErosionWrapperCallbacks::`vftable;
  hkaiNavMesh::hkaiNavMesh(&other);
  hkaiNavMeshGenerationOutputs::hkaiNavMeshGenerationOutputs(&outputs);
  outputs.m_navMesh = &other;
  v89 = hkaiNavMeshGenerationUtils::_generateNavMesh(
          &input,
          &_triMeshIn,
          &outputs,
          &_callbacks,
          edgeConnectionRaycaster);
  if ( v89 == 5 )
  {
    hkaiNavMesh::copy((hkaiNavMesh *)v10, result, &other);
    v10[10].m_real.m128_i32[0] = m_minCharacterWidth_low.m128_i32[0];
  }
  else
  {
    hkaiNavMesh::clear((hkaiNavMesh *)v10);
  }
  v90 = 0;
  if ( input.m_carvers.m_size > 0 )
  {
    v91 = 0i64;
    do
    {
      hkReferencedObject::removeReference(input.m_carvers.m_data[v91].m_pntr);
      ++v90;
      ++v91;
    }
    while ( v90 < input.m_carvers.m_size );
  }
  hkaiNavMesh::~hkaiNavMesh(&other);
  v101.m_string.m_size = 0;
  _callbacks.vfptr = (hkaiNavMeshGenerationProgressCallbackVtbl *)&hkaiNavMeshGenerationProgressCallback::`vftable;
  if ( v101.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      v101.m_string.m_data,
      v101.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  v101.m_string.m_data = 0i64;
  v101.m_string.m_capacityAndFlags = 0x80000000;
  hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(&input);
  _triMeshIn.m_triangles.m_size = 0;
  if ( _triMeshIn.m_triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      _triMeshIn.m_triangles.m_data,
      16 * _triMeshIn.m_triangles.m_capacityAndFlags);
  _triMeshIn.m_triangles.m_data = 0i64;
  _triMeshIn.m_triangles.m_capacityAndFlags = 0x80000000;
  _triMeshIn.m_vertices.m_size = 0;
  if ( _triMeshIn.m_vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      _triMeshIn.m_vertices.m_data,
      16 * _triMeshIn.m_vertices.m_capacityAndFlags);
  return v89;
}

