// File Line: 51
// RVA: 0xBA58D0
char __fastcall ErosionWrapperCallbacks::stepStartedCallback(ErosionWrapperCallbacks *this, hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep stepType, hkaiNavMeshGenerationProgressCallbackContext *ctx)
{
  hkaiNavMeshGenerationProgressCallback::NavMeshGenerationStep v3; // edi
  ErosionWrapperCallbacks *v4; // rbx
  hkaiNavMeshGenerationProgressCallbackContext v6; // [rsp+30h] [rbp-78h]

  v3 = stepType;
  v4 = this;
  if ( !this->m_navGenCallbacks )
    return 1;
  hkaiNavMeshGenerationProgressCallbackContext::hkaiNavMeshGenerationProgressCallbackContext(&v6, ctx->m_settings);
  return ((__int64 (__fastcall *)(hkaiNavMeshGenerationProgressCallback *, signed __int64, _QWORD))v4->m_navGenCallbacks->vfptr->stepMiddleCallback)(
           v4->m_navGenCallbacks,
           9i64,
           (unsigned int)v3);
}

// File Line: 70
// RVA: 0xBA4E40
__int64 __fastcall hkaiNavMeshErosion::erode(hkaiNavMesh *mesh, hkaiNavMeshGenerationSettings *originalSettings, hkaiEdgeGeometryRaycaster *edgeConnectionRaycaster, hkaiNavMeshGenerationProgressCallback *callbacks)
{
  bool v4; // si
  hkaiEdgeGeometryRaycaster *v5; // r12
  hkVector4f *v6; // r8
  hkaiNavMeshGenerationProgressCallback *v7; // r14
  hkaiNavMeshGenerationSettings *v8; // rbx
  __m128 v9; // xmm14
  hkSimdFloat32 *v10; // r15
  int v11; // eax
  __m128 *v12; // rax
  __int64 v13; // rdx
  hkVector4f v14; // xmm0
  hkRefPtr<hkaiVolume const > *v15; // rdi
  __int64 i; // rbx
  hkReferencedObject *v17; // rcx
  hkRefPtr<hkaiMaterialPainter const > *v18; // rdi
  __int64 j; // rbx
  hkReferencedObject *v20; // rcx
  signed int v21; // eax
  __int128 *v22; // rcx
  __m128 v23; // xmm0
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  int v26; // ecx
  char *v27; // rdx
  __int64 v28; // rdi
  unsigned __int64 v29; // r14
  int v30; // er13
  __int64 v31; // rdx
  int v32; // esi
  int v33; // er8
  signed __int64 v34; // rbx
  int v35; // ecx
  unsigned __int64 v36; // r12
  __int64 v37; // rdx
  int v38; // ecx
  int v39; // eax
  hkGeometry::Triangle *v40; // rdx
  int v41; // er9
  __int64 v42; // rcx
  int v43; // er13
  __int64 v44; // r10
  float v45; // xmm7_4
  unsigned __int64 v46; // rdx
  __int64 v47; // rax
  int v48; // er8
  signed int *v49; // r11
  int v50; // edx
  int v51; // esi
  __m128 v52; // xmm6
  int v53; // er12
  unsigned __int64 v54; // rbx
  __m128 v55; // xmm8
  int v56; // eax
  int v57; // edx
  __m128 v58; // xmm1
  __m128 v59; // xmm0
  __m128 v60; // xmm5
  __m128 v61; // xmm5
  __m128 v62; // xmm1
  __m128 v63; // xmm3
  __m128 v64; // xmm2
  __m128 v65; // xmm4
  int v66; // ebx
  int v67; // er8
  int v68; // ecx
  unsigned __int64 v69; // r12
  signed __int64 v70; // rsi
  __int64 v71; // rdx
  int v72; // ecx
  hkGeometry::Triangle *v73; // rdx
  int v74; // eax
  __int64 v75; // r12
  signed __int64 v76; // rsi
  unsigned __int64 v77; // rdx
  unsigned __int64 v78; // rcx
  __m128 v79; // xmm6
  __m128 v80; // xmm7
  _QWORD **v81; // rax
  hkaiPlaneVolume *v82; // rax
  hkaiPlaneVolume *v83; // rax
  hkaiPlaneVolume *v84; // rbx
  __int64 v85; // rax
  signed __int64 v86; // rcx
  __m128 v87; // xmm2
  int v88; // edx
  hkRefPtr<hkaiVolume const > *v89; // r13
  unsigned int v90; // esi
  int v91; // ebx
  __int64 v92; // rdi
  hkVector4f *edgeConnectionRayCaster; // [rsp+20h] [rbp-D0h]
  hkaiNavMesh *mesha; // [rsp+30h] [rbp-C0h]
  __int64 v96; // [rsp+38h] [rbp-B8h]
  int v97; // [rsp+40h] [rbp-B0h]
  hkGeometry _triMeshIn; // [rsp+48h] [rbp-A8h]
  hkaiNavMeshGenerationProgressCallback _callbacks; // [rsp+78h] [rbp-78h]
  hkaiNavMeshGenerationProgressCallback *v100; // [rsp+80h] [rbp-70h]
  int faceIndex[4]; // [rsp+90h] [rbp-60h]
  hkStringBuf v102; // [rsp+A0h] [rbp-50h]
  hkaiNavMeshGenerationOutputs outputs; // [rsp+130h] [rbp+40h]
  char v104; // [rsp+160h] [rbp+70h]
  hkaiNavMeshGenerationSettings input; // [rsp+170h] [rbp+80h]
  hkaiNavMesh other; // [rsp+360h] [rbp+270h]
  __int128 v107[7]; // [rsp+410h] [rbp+320h]
  __int128 v108; // [rsp+480h] [rbp+390h]
  hkVector4f points; // [rsp+490h] [rbp+3A0h]
  __int128 v110[10]; // [rsp+500h] [rbp+410h]
  hkResult result[2]; // [rsp+670h] [rbp+580h]
  bool retaddr; // [rsp+678h] [rbp+588h]
  hkaiNavMesh *v113; // [rsp+680h] [rbp+590h]
  hkaiNavMeshGenerationProgressCallback *v114; // [rsp+688h] [rbp+598h]

  v113 = mesh;
  v4 = originalSettings->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  v5 = edgeConnectionRaycaster;
  v6 = 0i64;
  v7 = callbacks;
  v8 = originalSettings;
  v9 = (__m128)LODWORD(originalSettings->m_minCharacterWidth);
  v9.m128_f32[0] = v9.m128_f32[0] * 0.5;
  v10 = (hkSimdFloat32 *)mesh;
  retaddr = originalSettings->m_wallClimbingSettings.m_enableWallClimbing.m_bool != 0;
  _triMeshIn.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  v11 = mesh->m_vertices.m_size;
  *(_DWORD *)&_triMeshIn.m_memSizeAndFlags = 0x1FFFF;
  _triMeshIn.m_vertices.m_data = 0i64;
  _triMeshIn.m_vertices.m_size = 0;
  _triMeshIn.m_vertices.m_capacityAndFlags = 2147483648;
  _triMeshIn.m_triangles.m_data = 0i64;
  _triMeshIn.m_triangles.m_size = 0;
  _triMeshIn.m_triangles.m_capacityAndFlags = 2147483648;
  if ( v11 > 0 )
  {
    LODWORD(mesha) = 16 * v11;
    v6 = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                         (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                         (int *)&mesha);
    _triMeshIn.m_vertices.m_data = v6;
    _triMeshIn.m_vertices.m_capacityAndFlags = (signed int)mesha / 16;
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
  hkaiNavMeshGenerationSettings::operator=(&input, v8);
  v15 = input.m_carvers.m_data;
  for ( i = input.m_carvers.m_size - 1; i >= 0; v15[i--].m_pntr = 0i64 )
  {
    v17 = (hkReferencedObject *)&v15[i].m_pntr->vfptr;
    if ( v17 )
      hkReferencedObject::removeReference(v17);
  }
  v18 = input.m_painters.m_data;
  input.m_carvers.m_size = 0;
  for ( j = input.m_painters.m_size - 1; j >= 0; v18[j--].m_pntr = 0i64 )
  {
    v20 = (hkReferencedObject *)&v18[j].m_pntr->vfptr;
    if ( v20 )
      hkReferencedObject::removeReference(v20);
  }
  input.m_painters.m_size = 0;
  v21 = 0;
  v22 = v107;
  do
  {
    v23 = v9;
    if ( !(v21 & 4) )
      v23 = _mm_xor_ps(v9, (__m128)(unsigned int)_xmm[0]);
    v24 = v9;
    if ( !(v21 & 2) )
      v24 = _mm_xor_ps(v9, (__m128)(unsigned int)_xmm[0]);
    v25 = v9;
    if ( !(v21 & 1) )
      v25 = _mm_xor_ps(v9, (__m128)(unsigned int)_xmm[0]);
    ++v21;
    ++v22;
    *(v22 - 1) = (__int128)_mm_unpacklo_ps(_mm_unpacklo_ps(v25, v23), _mm_unpacklo_ps(v24, (__m128)0i64));
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
        v26 = (signed int)mesha;
      }
      else
      {
        v30 = 0;
      }
      v97 = v30;
      if ( v4 )
      {
        hkaiNavMeshUtils::calcFaceNormal<hkaiNavMesh>(
          (hkaiNavMeshUtils *)&v104,
          v10,
          (hkaiNavMesh *)(unsigned int)v26,
          (unsigned __int64)faceIndex,
          edgeConnectionRayCaster);
        v41 = *(signed __int16 *)(v28 + v29 + 8);
        v42 = 0i64;
        v43 = 0;
        v44 = 0i64;
        v96 = 0i64;
        v45 = 0.0 - 1.0;
        if ( v41 > 0 )
        {
          v46 = v10[2].m_real.m128_u64[0];
          v47 = *(signed int *)(v28 + v29);
          *(_QWORD *)&_triMeshIn.m_triangles.m_size = v46;
          v48 = 1;
          v49 = (signed int *)(v46 + 20 * v47);
          v50 = v41 - 2;
          do
          {
            v51 = v50 + v48;
            v52 = query.m_quad;
            v53 = v48;
            if ( v48 < v50 + v48 )
            {
              v54 = v10[3].m_real.m128_u64[0];
              v55 = *(__m128 *)(v54 + 16i64 * *v49);
              do
              {
                v56 = v53++;
                v57 = *(_DWORD *)(v28 + v29) + v56 % v41;
                v58 = _mm_sub_ps(
                        *(__m128 *)(v54
                                  + 16i64 * *(signed int *)(*(_QWORD *)&_triMeshIn.m_triangles.m_size + 20i64 * v57)),
                        v55);
                v59 = _mm_sub_ps(
                        *(__m128 *)(v54
                                  + 16i64 * *(signed int *)(*(_QWORD *)&_triMeshIn.m_triangles.m_size + 20i64 * v57 + 4)),
                        v55);
                v60 = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v59, v59, 201), v58),
                        _mm_mul_ps(_mm_shuffle_ps(v58, v58, 201), v59));
                v61 = _mm_shuffle_ps(v60, v60, 201);
                v62 = _mm_mul_ps(v61, v61);
                v63 = _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
                        _mm_shuffle_ps(v62, v62, 170));
                v64 = _mm_rsqrt_ps(v63);
                v65 = _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_andnot_ps(
                            _mm_cmpleps(v63, (__m128)0i64),
                            _mm_mul_ps(
                              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v64, v63), v64)),
                              _mm_mul_ps(*(__m128 *)_xmm, v64))),
                          v61),
                        *(__m128 *)faceIndex);
                v52 = _mm_min_ps(
                        v52,
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)),
                          _mm_shuffle_ps(v65, v65, 170)));
              }
              while ( v53 < v51 );
              v10 = *(hkSimdFloat32 **)&result[0].m_enum;
              v50 = v41 - 2;
            }
            if ( v52.m128_f32[0] <= v45 )
            {
              v42 = v96;
            }
            else
            {
              v42 = v44;
              v45 = v52.m128_f32[0];
              v43 = v48 - 1;
              v96 = v44;
            }
            ++v48;
            ++v44;
            v49 += 5;
          }
          while ( v48 - 1 < v41 );
        }
        v66 = v43 + 1;
        LODWORD(v96) = *(_DWORD *)(v10[2].m_real.m128_u64[0] + 20 * (v42 + *(signed int *)(v28 + v29)));
        if ( v43 + 1 < v41 + v43 - 1 )
        {
          v67 = v96;
          do
          {
            v68 = _triMeshIn.m_triangles.m_size;
            v69 = v10[2].m_real.m128_u64[0];
            v70 = 5i64 * (*(_DWORD *)(v28 + v29) + v66 % v41);
            if ( _triMeshIn.m_triangles.m_size == (_triMeshIn.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &_triMeshIn.m_triangles,
                16);
              v68 = _triMeshIn.m_triangles.m_size;
              v67 = v96;
            }
            v71 = v68;
            ++v66;
            _triMeshIn.m_triangles.m_size = v68 + 1;
            v72 = *(_DWORD *)(v69 + 4 * v70 + 4);
            v73 = &_triMeshIn.m_triangles.m_data[v71];
            v73->m_b = *(_DWORD *)(v69 + 4 * v70);
            v74 = v97;
            v73->m_a = v67;
            v73->m_material = v74;
            v73->m_c = v72;
            v41 = *(signed __int16 *)(v28 + v29 + 8);
          }
          while ( v66 < v41 + v43 - 1 );
        }
      }
      else
      {
        v31 = *(signed int *)(v28 + v29);
        v32 = v31 + 1;
        LODWORD(v96) = *(_DWORD *)(v10[2].m_real.m128_u64[0] + 20 * v31);
        if ( (signed int)v31 + 1 < *(signed __int16 *)(v28 + v29 + 8) + (signed int)v31 - 1 )
        {
          v33 = v96;
          v34 = 20i64 * v32;
          do
          {
            v35 = _triMeshIn.m_triangles.m_size;
            v36 = v10[2].m_real.m128_u64[0];
            if ( _triMeshIn.m_triangles.m_size == (_triMeshIn.m_triangles.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &_triMeshIn.m_triangles,
                16);
              v35 = _triMeshIn.m_triangles.m_size;
              v33 = v96;
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
          while ( v32 < *(_DWORD *)(v28 + v29) + *(signed __int16 *)(v28 + v29 + 8) - 1 );
        }
      }
      v75 = *(signed int *)(v28 + v29);
      if ( (signed int)v75 < (signed int)v75 + *(signed __int16 *)(v28 + v29 + 8) )
      {
        v76 = 20 * v75;
        do
        {
          v77 = v10[2].m_real.m128_u64[0];
          if ( *(_DWORD *)(v76 + v77 + 8) == -1 || *(_BYTE *)(v76 + v77 + 16) & 0x20 )
          {
            v78 = v10[3].m_real.m128_u64[0];
            v79 = *(__m128 *)(v78 + 16i64 * *(signed int *)(v76 + v77));
            v80 = *(__m128 *)(v78 + 16i64 * *(signed int *)(v76 + v77 + 4));
            v81 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v82 = (hkaiPlaneVolume *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v81[11] + 8i64))(
                                       v81[11],
                                       128i64);
            if ( v82 )
            {
              hkaiPlaneVolume::hkaiPlaneVolume(v82);
              v84 = v83;
            }
            else
            {
              v84 = 0i64;
            }
            v85 = 0i64;
            v86 = 8i64;
            do
            {
              v87 = (__m128)v107[v85];
              ++v85;
              *(__int128 *)((char *)&v108 + v85 * 16) = (__int128)_mm_add_ps(v79, v87);
              v110[v85] = (__int128)_mm_add_ps(v80, v87);
              --v86;
            }
            while ( v86 );
            hkaiPlaneVolume::createConvexVolume(&points, 16, v84);
            if ( v84 )
              hkReferencedObject::addReference((hkReferencedObject *)&v84->vfptr);
            v88 = input.m_carvers.m_size;
            if ( input.m_carvers.m_size == (input.m_carvers.m_capacityAndFlags & 0x3FFFFFFF) )
            {
              hkArrayUtil::_reserveMore(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &input.m_carvers,
                8);
              v88 = input.m_carvers.m_size;
            }
            v89 = &input.m_carvers.m_data[v88];
            if ( v89 )
            {
              if ( v84 )
                hkReferencedObject::addReference((hkReferencedObject *)&v84->vfptr);
              v89->m_pntr = (hkaiVolume *)&v84->vfptr;
              v88 = input.m_carvers.m_size;
            }
            input.m_carvers.m_size = v88 + 1;
            if ( v84 )
              hkReferencedObject::removeReference((hkReferencedObject *)&v84->vfptr);
          }
          LODWORD(v75) = v75 + 1;
          v76 += 20i64;
        }
        while ( (signed int)v75 < *(_DWORD *)(v28 + v29) + (signed int)*(signed __int16 *)(v28 + v29 + 8) );
      }
      v4 = retaddr;
      v26 = (_DWORD)mesha + 1;
      v27 = (char *)&_callbacks.vfptr->stepStartedCallback + 1;
      v28 += 16i64;
      LODWORD(mesha) = v26;
      ++_callbacks.vfptr;
    }
    while ( v26 < v10[1].m_real.m128_i32[2] );
    v7 = v114;
    v5 = (hkaiEdgeGeometryRaycaster *)v113;
  }
  v102.m_string.m_capacityAndFlags = -2147483520;
  v102.m_string.m_data = v102.m_string.m_storage;
  v102.m_string.m_size = 1;
  v102.m_string.m_storage[0] = 0;
  if ( input.m_saveInputSnapshot.m_bool && hkStringPtr::getLength(&input.m_snapshotFilename) )
  {
    hkStringBuf::operator=(
      &v102,
      (const char *)((_QWORD)input.m_snapshotFilename.m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64));
    hkStringBuf::chompEnd(&v102, 4);
    hkStringBuf::operator+=(&v102, ".erosion.hkt");
    hkStringPtr::operator=(&input.m_snapshotFilename, v102.m_string.m_data);
  }
  *(_WORD *)&input.m_characterWidthUsage.m_storage = 0;
  input.m_materialMap.m_size = 0;
  input.m_defaultConstructionProperties.m_storage = 1;
  v100 = v7;
  _callbacks.vfptr = (hkaiNavMeshGenerationProgressCallbackVtbl *)&ErosionWrapperCallbacks::`vftable;
  hkaiNavMesh::hkaiNavMesh(&other);
  hkaiNavMeshGenerationOutputs::hkaiNavMeshGenerationOutputs(&outputs);
  outputs.m_navMesh = &other;
  v90 = hkaiNavMeshGenerationUtils::_generateNavMesh(&input, &_triMeshIn, &outputs, &_callbacks, v5);
  if ( v90 == 5 )
  {
    hkaiNavMesh::copy((hkaiNavMesh *)v10, result, &other);
    v10[10].m_real.m128_i32[0] = v9.m128_i32[0];
  }
  else
  {
    hkaiNavMesh::clear((hkaiNavMesh *)v10);
  }
  v91 = 0;
  if ( input.m_carvers.m_size > 0 )
  {
    v92 = 0i64;
    do
    {
      hkReferencedObject::removeReference((hkReferencedObject *)&input.m_carvers.m_data[v92].m_pntr->vfptr);
      ++v91;
      ++v92;
    }
    while ( v91 < input.m_carvers.m_size );
  }
  hkaiNavMesh::~hkaiNavMesh(&other);
  v102.m_string.m_size = 0;
  _callbacks.vfptr = (hkaiNavMeshGenerationProgressCallbackVtbl *)&hkaiNavMeshGenerationProgressCallback::`vftable;
  if ( v102.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      v102.m_string.m_data,
      v102.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  v102.m_string.m_data = 0i64;
  v102.m_string.m_capacityAndFlags = 2147483648;
  hkaiNavMeshGenerationSettings::~hkaiNavMeshGenerationSettings(&input);
  _triMeshIn.m_triangles.m_size = 0;
  if ( _triMeshIn.m_triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      _triMeshIn.m_triangles.m_data,
      16 * _triMeshIn.m_triangles.m_capacityAndFlags);
  _triMeshIn.m_triangles.m_data = 0i64;
  _triMeshIn.m_triangles.m_capacityAndFlags = 2147483648;
  _triMeshIn.m_vertices.m_size = 0;
  if ( _triMeshIn.m_vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      _triMeshIn.m_vertices.m_data,
      16 * _triMeshIn.m_vertices.m_capacityAndFlags);
  return v90;
}

