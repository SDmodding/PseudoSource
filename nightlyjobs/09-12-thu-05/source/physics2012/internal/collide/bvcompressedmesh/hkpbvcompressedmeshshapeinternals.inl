// File Line: 62
// RVA: 0xDF3160
void __fastcall hkpBvCompressedMeshShape_Internals::GeometryProvider::getCustomPrimitiveInfos(hkpBvCompressedMeshShape_Internals::GeometryProvider *this, int primitiveIndex, hkcdStaticMeshTreeBase::BuildCustomInfos *customPrimitive)
{
  hkpBvCompressedMeshShape_Internals::GeometryProvider *v3; // r14
  hkcdStaticMeshTreeBase::BuildCustomInfos *v4; // rsi
  __int64 v5; // r13
  hkpCylinderShape *v6; // r15
  float v7; // xmm9_4
  int v8; // ebx
  __m128 v9; // xmm8
  bool v10; // cl
  __int64 v11; // rcx
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  _QWORD **v14; // rax
  __m128 *v15; // rax
  int v16; // ebx
  hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *v17; // rdi
  __int64 v18; // rcx
  hkVector4f *v19; // rax
  __m128 v20; // xmm5
  __m128 v21; // xmm6
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm3
  hkVector4f *v25; // rax
  __m128 v26; // xmm1
  __m128 v27; // xmm1
  _QWORD **v28; // rax
  __m128 *v29; // rax
  int v30; // ebx
  hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *v31; // rdi
  __int64 v32; // rcx
  hkVector4f *v33; // rax
  __m128 v34; // xmm5
  __m128 v35; // xmm6
  __m128 v36; // xmm1
  __m128 v37; // xmm4
  __m128 v38; // xmm3
  hkVector4f *v39; // rax
  __m128 v40; // xmm1
  __m128 v41; // xmm1
  signed int v42; // eax
  _QWORD **v43; // rax
  __m128 *v44; // rax
  __m128 *v45; // rdi
  signed __int64 v46; // r15
  hkcdVertex *v47; // rax
  __m128 v48; // xmm0
  __m128 v49; // xmm1
  int v50; // eax
  int v51; // eax
  int v52; // er9
  __m128 v53; // xmm1
  float v54; // xmm8_4
  float v55; // xmm8_4
  _QWORD **v56; // rax
  __m128 *v57; // rax
  int v58; // ebx
  hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *v59; // rdi
  __int64 v60; // rcx
  hkVector4f *v61; // rax
  __m128 v62; // xmm5
  __m128 v63; // xmm6
  __m128 v64; // xmm1
  __m128 v65; // xmm4
  __m128 v66; // xmm3
  __int64 v67; // rcx
  _QWORD **v68; // rax
  __m128 *v69; // rax
  __m128 *v70; // rdi
  __m128 *v71; // rax
  hkVector4f *v72; // rcx
  hkReferencedObject *v73; // rcx
  hkErrStream v74; // [rsp+30h] [rbp-C8h]
  hkpConvexTransformShape v75; // [rsp+50h] [rbp-A8h]
  hkResult v76; // [rsp+E8h] [rbp-10h]
  hkcdVertex verticesOut; // [rsp+F8h] [rbp+0h]
  __int128 v78; // [rsp+128h] [rbp+30h]
  __int128 v79; // [rsp+148h] [rbp+50h]
  __int128 v80; // [rsp+158h] [rbp+60h]
  __int128 v81; // [rsp+168h] [rbp+70h]
  char buf; // [rsp+178h] [rbp+80h]
  hkpConvexShape *retaddr; // [rsp+3F8h] [rbp+300h]
  hkResult result; // [rsp+400h] [rbp+308h]

  v3 = this;
  v4 = customPrimitive;
  v5 = primitiveIndex;
  this->m_meshCInfo->vfptr->getConvexShape(
    this->m_meshCInfo,
    primitiveIndex,
    &retaddr,
    (hkQsTransformf *)&v75.m_extraScale.m_quad.m128_u16[4]);
  if ( v3->m_meshCInfo->m_maxConvexShapeError >= 3.40282e38 )
  {
    v4->m_compression = 1;
  }
  else
  {
    v4->m_compression = 3;
    v4->m_maxError = v3->m_meshCInfo->m_maxConvexShapeError;
  }
  hkpConvexTransformShape::hkpConvexTransformShape(
    &v75,
    retaddr,
    (hkQsTransformf *)&v75.m_extraScale.m_quad.m128_u16[4],
    REFERENCE_POLICY_INCREMENT);
  v6 = (hkpCylinderShape *)retaddr;
  v7 = v75.m_radius;
  v8 = (unsigned __int8)retaddr->m_type.m_storage;
  result.m_enum = (hkResultEnum)LODWORD(v75.m_radius);
  v9 = _mm_shuffle_ps((__m128)LODWORD(v75.m_radius), (__m128)LODWORD(v75.m_radius), 0);
  v10 = !(v8 & 0xFFFFFFFA) && v8 != 5;
  if ( v75.m_radius != v3->m_meshCInfo->m_convexRadius || v10 )
  {
    v11 = v4->m_tags.m_size;
    v4->m_tags.m_size = v11 + 1;
    *(float *)&result.m_enum = 1.0039062 * v7;
    v4->m_tags.m_data[v11] = COERCE_UNSIGNED_INT(1.0039062 * v7) >> 16;
    v6 = (hkpCylinderShape *)retaddr;
  }
  if ( !v8 )
  {
    if ( !v3->m_caches.m_data[v5] )
    {
      v68 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v69 = (__m128 *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v68[11] + 8i64))(v68[11], 48i64);
      v70 = v69;
      if ( v69 )
      {
        v69[2].m128_u64[0] = 0i64;
        v69[2].m128_i32[2] = 0;
        v69[2].m128_i32[3] = 2147483648;
        *v69 = (__m128)xmmword_141A712A0;
        v69[1] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), *v69);
      }
      else
      {
        v70 = 0i64;
      }
      v3->m_caches.m_data[v5] = (hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *)v70;
      if ( v70[2].m128_i32[2] == (v70[2].m128_i32[3] & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v70[2], 16);
      *(hkVector4f *)(v70[2].m128_u64[0] + 16i64 * v70[2].m128_i32[2]++) = *(hkVector4f *)((char *)&v75.m_extraScale + 8);
      v71 = (__m128 *)v70[2].m128_u64[0];
      *v70 = _mm_sub_ps(*v71, v9);
      v70[1] = _mm_add_ps(*v71, v9);
    }
    v42 = 2;
    goto LABEL_66;
  }
  if ( v8 == 1 )
  {
    result.m_enum = v76.m_enum;
    LODWORD(v54) = (unsigned int)(2 * v76.m_enum) >> 1;
    v55 = v54 * hkpCylinderShape::getCylinderRadius(v6);
    if ( !v3->m_caches.m_data[v5] )
    {
      v56 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v57 = (__m128 *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v56[11] + 8i64))(v56[11], 48i64);
      v58 = 0;
      v59 = (hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *)v57;
      if ( v57 )
      {
        v57[2].m128_u64[0] = 0i64;
        v57[2].m128_i32[2] = 0;
        v57[2].m128_i32[3] = 2147483648;
        *v57 = (__m128)xmmword_141A712A0;
        v57[1] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), *v57);
      }
      else
      {
        v59 = 0i64;
      }
      v3->m_caches.m_data[v5] = v59;
      hkArrayBase<hkVector4f>::_append(
        (hkArrayBase<hkVector4f> *)&v59->m_vertices.m_data,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v6->m_vertexA,
        2);
      if ( v59->m_vertices.m_size > 0 )
      {
        v60 = 0i64;
        do
        {
          v61 = v59->m_vertices.m_data;
          ++v58;
          ++v60;
          v62 = _mm_shuffle_ps(
                  *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8),
                  *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8),
                  255);
          v63 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(
                      v61[v60 - 1].m_quad,
                      _mm_movelh_ps(
                        _mm_unpacklo_ps(
                          _mm_shuffle_ps(
                            *(__m128 *)&v75.m_childShapeSizeForSpu,
                            *(__m128 *)&v75.m_childShapeSizeForSpu,
                            255),
                          _mm_shuffle_ps(
                            *(__m128 *)((char *)&v75.m_transform.m_rotation.m_vec.m_quad + 8),
                            *(__m128 *)((char *)&v75.m_transform.m_rotation.m_vec.m_quad + 8),
                            255)),
                        _mm_unpacklo_ps(
                          _mm_shuffle_ps(
                            *(__m128 *)((char *)&v75.m_transform.m_scale.m_quad + 8),
                            *(__m128 *)((char *)&v75.m_transform.m_scale.m_quad + 8),
                            255),
                          aabbOut.m_quad))),
                    *(__m128 *)((char *)&v75.m_transform.m_scale.m_quad + 8)),
                  _mm_mul_ps(v61[v60 - 1].m_quad, *(__m128 *)((char *)&v75.m_transform.m_rotation.m_vec.m_quad + 8)));
          v64 = _mm_mul_ps(*(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8), v63);
          v65 = _mm_sub_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(v63, v63, 201),
                    *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8)),
                  _mm_mul_ps(
                    _mm_shuffle_ps(
                      *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8),
                      *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8),
                      201),
                    v63));
          v66 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v64, v64, 85), _mm_shuffle_ps(v64, v64, 0)),
                        _mm_shuffle_ps(v64, v64, 170)),
                      *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8)),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v62, v62), (__m128)xmmword_141A711B0), v63)),
                  _mm_mul_ps(_mm_shuffle_ps(v65, v65, 201), v62));
          v61[v60 - 1].m_quad = _mm_add_ps(_mm_add_ps(v66, v66), *(__m128 *)&v75.m_childShapeSizeForSpu);
        }
        while ( v58 < v59->m_vertices.m_size );
      }
      hkpCylinderShape::hkpCylinderShape(
        (hkpCylinderShape *)&verticesOut,
        v59->m_vertices.m_data,
        v59->m_vertices.m_data + 1,
        v55,
        v7);
      hkpCylinderShape::getAabb((hkpCylinderShape *)&verticesOut, (hkTransformf *)&transform, 0.0, &v59->m_aabb);
    }
    v67 = v4->m_tags.m_size;
    v4->m_tags.m_size = v67 + 1;
    *(float *)&result.m_enum = 1.0039062 * v55;
    v4->m_tags.m_data[v67] = COERCE_UNSIGNED_INT(1.0039062 * v55) >> 16;
    v4->m_customType = 4;
  }
  else
  {
    if ( v8 != 3 )
    {
      if ( v8 != 4 )
      {
        if ( v8 == 5 )
        {
          if ( !v3->m_caches.m_data[v5] )
          {
            v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v15 = (__m128 *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v14[11] + 8i64))(v14[11], 48i64);
            v16 = 0;
            v17 = (hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *)v15;
            if ( v15 )
            {
              v15[2].m128_u64[0] = 0i64;
              v15[2].m128_i32[2] = 0;
              v15[2].m128_i32[3] = 2147483648;
              *v15 = (__m128)xmmword_141A712A0;
              v15[1] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), *v15);
            }
            else
            {
              v17 = 0i64;
            }
            v3->m_caches.m_data[v5] = v17;
            hkpConvexVerticesShape::getOriginalVertices((hkpConvexVerticesShape *)v6, &v17->m_vertices);
            if ( v17->m_vertices.m_size > 0 )
            {
              v18 = 0i64;
              do
              {
                v19 = v17->m_vertices.m_data;
                ++v16;
                ++v18;
                v20 = _mm_shuffle_ps(
                        *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8),
                        *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8),
                        255);
                v21 = _mm_add_ps(
                        _mm_mul_ps(
                          _mm_sub_ps(
                            v19[v18 - 1].m_quad,
                            _mm_movelh_ps(
                              _mm_unpacklo_ps(
                                _mm_shuffle_ps(
                                  *(__m128 *)&v75.m_childShapeSizeForSpu,
                                  *(__m128 *)&v75.m_childShapeSizeForSpu,
                                  255),
                                _mm_shuffle_ps(
                                  *(__m128 *)((char *)&v75.m_transform.m_rotation.m_vec.m_quad + 8),
                                  *(__m128 *)((char *)&v75.m_transform.m_rotation.m_vec.m_quad + 8),
                                  255)),
                              _mm_unpacklo_ps(
                                _mm_shuffle_ps(
                                  *(__m128 *)((char *)&v75.m_transform.m_scale.m_quad + 8),
                                  *(__m128 *)((char *)&v75.m_transform.m_scale.m_quad + 8),
                                  255),
                                aabbOut.m_quad))),
                          *(__m128 *)((char *)&v75.m_transform.m_scale.m_quad + 8)),
                        _mm_mul_ps(
                          v19[v18 - 1].m_quad,
                          *(__m128 *)((char *)&v75.m_transform.m_rotation.m_vec.m_quad + 8)));
                v22 = _mm_mul_ps(*(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8), v21);
                v23 = _mm_sub_ps(
                        _mm_mul_ps(
                          _mm_shuffle_ps(v21, v21, 201),
                          *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8)),
                        _mm_mul_ps(
                          _mm_shuffle_ps(
                            *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8),
                            *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8),
                            201),
                          v21));
                v24 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                              _mm_shuffle_ps(v22, v22, 170)),
                            *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8)),
                          _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v20, v20), (__m128)xmmword_141A711B0), v21)),
                        _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v20));
                v19[v18 - 1].m_quad = _mm_add_ps(_mm_add_ps(v24, v24), *(__m128 *)&v75.m_childShapeSizeForSpu);
                v25 = v17->m_vertices.m_data;
                v26 = v17->m_aabb.m_max.m_quad;
                v17->m_aabb.m_min.m_quad = _mm_min_ps(v17->m_aabb.m_min.m_quad, v25[v18 - 1].m_quad);
                v17->m_aabb.m_max.m_quad = _mm_max_ps(v26, v25[v18 - 1].m_quad);
              }
              while ( v16 < v17->m_vertices.m_size );
            }
            v27 = _mm_sub_ps(v17->m_aabb.m_min.m_quad, v9);
            v17->m_aabb.m_max.m_quad = _mm_add_ps(v17->m_aabb.m_max.m_quad, v9);
            v17->m_aabb.m_min.m_quad = v27;
          }
          v4->m_customType = 1;
        }
        else
        {
          hkErrStream::hkErrStream(&v74, &buf, 512);
          v12 = hkOstream::operator<<((hkOstream *)&v74.vfptr, "Shape type ");
          v13 = hkOstream::operator<<(v12, v8, (int)v12);
          hkOstream::operator<<(v13, " not supported");
          if ( (unsigned int)hkError::messageError(
                               1394303432,
                               &buf,
                               "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Physics2012/Internal/Collide/BvCompressedMesh/hkpB"
                               "vCompressedMeshShapeInternals.inl",
                               216) )
            __debugbreak();
          hkOstream::~hkOstream((hkOstream *)&v74.vfptr);
        }
        goto LABEL_67;
      }
      if ( !v3->m_caches.m_data[v5] )
      {
        v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v29 = (__m128 *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v28[11] + 8i64))(v28[11], 48i64);
        v30 = 0;
        v31 = (hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *)v29;
        if ( v29 )
        {
          v29[2].m128_u64[0] = 0i64;
          v29[2].m128_i32[2] = 0;
          v29[2].m128_i32[3] = 2147483648;
          *v29 = (__m128)xmmword_141A712A0;
          v29[1] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), *v29);
        }
        else
        {
          v31 = 0i64;
        }
        v3->m_caches.m_data[v5] = v31;
        hkArrayBase<hkVector4f>::_append(
          (hkArrayBase<hkVector4f> *)&v31->m_vertices.m_data,
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
          &v6->m_vertexA,
          2);
        if ( v31->m_vertices.m_size > 0 )
        {
          v32 = 0i64;
          do
          {
            v33 = v31->m_vertices.m_data;
            ++v30;
            ++v32;
            v34 = _mm_shuffle_ps(
                    *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8),
                    *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8),
                    255);
            v35 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        v33[v32 - 1].m_quad,
                        _mm_movelh_ps(
                          _mm_unpacklo_ps(
                            _mm_shuffle_ps(
                              *(__m128 *)&v75.m_childShapeSizeForSpu,
                              *(__m128 *)&v75.m_childShapeSizeForSpu,
                              255),
                            _mm_shuffle_ps(
                              *(__m128 *)((char *)&v75.m_transform.m_rotation.m_vec.m_quad + 8),
                              *(__m128 *)((char *)&v75.m_transform.m_rotation.m_vec.m_quad + 8),
                              255)),
                          _mm_unpacklo_ps(
                            _mm_shuffle_ps(
                              *(__m128 *)((char *)&v75.m_transform.m_scale.m_quad + 8),
                              *(__m128 *)((char *)&v75.m_transform.m_scale.m_quad + 8),
                              255),
                            aabbOut.m_quad))),
                      *(__m128 *)((char *)&v75.m_transform.m_scale.m_quad + 8)),
                    _mm_mul_ps(v33[v32 - 1].m_quad, *(__m128 *)((char *)&v75.m_transform.m_rotation.m_vec.m_quad + 8)));
            v36 = _mm_mul_ps(*(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8), v35);
            v37 = _mm_sub_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps(v35, v35, 201),
                      *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8)),
                    _mm_mul_ps(
                      _mm_shuffle_ps(
                        *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8),
                        *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8),
                        201),
                      v35));
            v38 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                          _mm_shuffle_ps(v36, v36, 170)),
                        *(__m128 *)((char *)&v75.m_transform.m_translation.m_quad + 8)),
                      _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v34, v34), (__m128)xmmword_141A711B0), v35)),
                    _mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v34));
            v33[v32 - 1].m_quad = _mm_add_ps(_mm_add_ps(v38, v38), *(__m128 *)&v75.m_childShapeSizeForSpu);
            v39 = v31->m_vertices.m_data;
            v40 = v31->m_aabb.m_max.m_quad;
            v31->m_aabb.m_min.m_quad = _mm_min_ps(v31->m_aabb.m_min.m_quad, v39[v32 - 1].m_quad);
            v31->m_aabb.m_max.m_quad = _mm_max_ps(v40, v39[v32 - 1].m_quad);
          }
          while ( v30 < v31->m_vertices.m_size );
        }
        v41 = _mm_sub_ps(v31->m_aabb.m_min.m_quad, v9);
        v31->m_aabb.m_max.m_quad = _mm_add_ps(v31->m_aabb.m_max.m_quad, v9);
        v31->m_aabb.m_min.m_quad = v41;
      }
      v42 = 3;
LABEL_66:
      v4->m_customType = v42;
      goto LABEL_67;
    }
    if ( !v3->m_caches.m_data[v5] )
    {
      v43 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v44 = (__m128 *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v43[11] + 8i64))(v43[11], 48i64);
      v45 = v44;
      if ( v44 )
      {
        v44[2].m128_u64[0] = 0i64;
        v44[2].m128_i32[2] = 0;
        v44[2].m128_i32[3] = 2147483648;
        *v44 = (__m128)xmmword_141A712A0;
        v44[1] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), *v44);
      }
      else
      {
        v45 = 0i64;
      }
      v46 = 8i64;
      v3->m_caches.m_data[v5] = (hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *)v45;
      v74.vfptr = (hkBaseObjectVtbl *)844433520132096i64;
      *(_DWORD *)&v74.m_memSizeAndFlags = 327684;
      *(_DWORD *)(&v74.m_referenceCount + 1) = 458758;
      hkpConvexTransformShape::convertVertexIdsToVertices(&v75, (const unsigned __int16 *)&v74, 8, &verticesOut);
      v47 = &verticesOut;
      v48 = *v45;
      v49 = v45[1];
      do
      {
        v48 = _mm_min_ps(v48, v47->m_quad);
        ++v47;
        *v45 = v48;
        v49 = _mm_max_ps(v49, v47[-1].m_quad);
        v45[1] = v49;
        --v46;
      }
      while ( v46 );
      v50 = v45[2].m128_i32[3] & 0x3FFFFFFF;
      if ( v50 < 4 )
      {
        v51 = 2 * v50;
        v52 = 4;
        if ( v51 > 4 )
          v52 = v51;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v45[2], v52, 16);
      }
      v45[2].m128_i32[2] = 4;
      *(_OWORD *)v45[2].m128_u64[0] = v81;
      *(_OWORD *)(v45[2].m128_u64[0] + 16) = v80;
      *(_OWORD *)(v45[2].m128_u64[0] + 32) = v79;
      *(_OWORD *)(v45[2].m128_u64[0] + 48) = v78;
      v53 = _mm_sub_ps(*v45, v9);
      v45[1] = _mm_add_ps(v45[1], v9);
      *v45 = v53;
    }
    v4->m_customType = 0;
  }
LABEL_67:
  v72 = &v3->m_caches.m_data[v5]->m_aabb.m_min;
  v4->m_aabb.m_min = (hkVector4f)v72->m_quad;
  v4->m_aabb.m_max = (hkVector4f)v72[1].m_quad;
  v73 = (hkReferencedObject *)v75.m_childShape.vfptr;
  v4->m_numVertices = v3->m_caches.m_data[v5]->m_vertices.m_size;
  v75.m_childShape.vfptr = (hkpShapeContainerVtbl *)&hkpSingleShapeContainer::`vftable;
  if ( v73 )
    hkReferencedObject::removeReference(v73);
}

// File Line: 333
// RVA: 0xE00A70
hkBool *__fastcall isCollisionEnabled(hkBool *result, hkpShapeRayCastInput *input, hkpShapeContainer *shapeContainer, unsigned int shapeKey)
{
  hkBool *v4; // rbx
  hkpRayShapeCollectionFilter *v5; // rcx
  unsigned int v6; // ST20_4
  hkBool *v7; // rax
  char v8; // [rsp+40h] [rbp+8h]

  v4 = result;
  v5 = input->m_rayShapeCollectionFilter;
  if ( !v5 || (v6 = shapeKey, *(_BYTE *)v5->vfptr->isCollisionEnabled(v5, (hkBool *)&v8, input, shapeContainer, v6)) )
  {
    v4->m_bool = 1;
    v7 = v4;
  }
  else
  {
    v4->m_bool = 0;
    v7 = v4;
  }
  return v7;
}

