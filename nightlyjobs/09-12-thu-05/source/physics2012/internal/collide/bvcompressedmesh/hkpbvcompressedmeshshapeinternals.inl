// File Line: 62
// RVA: 0xDF3160
void __fastcall hkpBvCompressedMeshShape_Internals::GeometryProvider::getCustomPrimitiveInfos(
        hkpBvCompressedMeshShape_Internals::GeometryProvider *this,
        int primitiveIndex,
        hkcdStaticMeshTreeBase::BuildCustomInfos *customPrimitive)
{
  __int64 v5; // r13
  hkpCylinderShape *v6; // r15
  float v7; // xmm9_4
  unsigned int m_storage; // ebx
  __m128 v9; // xmm8
  bool v10; // cl
  __int64 m_size; // rcx
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
  __m128 m_quad; // xmm1
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
  int v42; // eax
  _QWORD **v43; // rax
  __m128 *v44; // rax
  hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *v45; // rdi
  __int64 v46; // r15
  __m128 *p_verticesOut; // rax
  __m128 v48; // xmm0
  __m128 v49; // xmm1
  int v50; // r9d
  __m128 v51; // xmm1
  float v52; // xmm8_4
  float v53; // xmm8_4
  _QWORD **v54; // rax
  __m128 *v55; // rax
  int v56; // ebx
  hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *v57; // rdi
  __int64 v58; // rcx
  hkVector4f *m_data; // rax
  __m128 v60; // xmm5
  __m128 v61; // xmm6
  __m128 v62; // xmm1
  __m128 v63; // xmm4
  __m128 v64; // xmm3
  __int64 v65; // rcx
  _QWORD **Value; // rax
  __m128 *v67; // rax
  hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *v68; // rdi
  __m128 *p_m_quad; // rax
  hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *v70; // rcx
  hkReferencedObject *v71; // rcx
  hkErrStream v72; // [rsp+30h] [rbp-C8h] BYREF
  _BYTE v73[32]; // [rsp+50h] [rbp-A8h] BYREF
  unsigned int v74; // [rsp+70h] [rbp-88h]
  void **v75; // [rsp+78h] [rbp-80h]
  __m128 v76; // [rsp+88h] [rbp-70h]
  __m128 v77; // [rsp+98h] [rbp-60h]
  __m128 v78; // [rsp+A8h] [rbp-50h]
  __m128 v79; // [rsp+B8h] [rbp-40h]
  hkQsTransformf v80; // [rsp+C8h] [rbp-30h] BYREF
  hkpCylinderShape verticesOut; // [rsp+F8h] [rbp+0h] BYREF
  hkVector4f v82; // [rsp+168h] [rbp+70h]
  char buf[520]; // [rsp+178h] [rbp+80h] BYREF
  hkpCylinderShape *retaddr; // [rsp+3F8h] [rbp+300h] BYREF
  hkResult result; // [rsp+400h] [rbp+308h] BYREF

  v5 = primitiveIndex;
  this->m_meshCInfo->vfptr->getConvexShape(this->m_meshCInfo, primitiveIndex, &retaddr, &v80);
  if ( this->m_meshCInfo->m_maxConvexShapeError >= 3.40282e38 )
  {
    customPrimitive->m_compression = CM_LOCAL_4;
  }
  else
  {
    customPrimitive->m_compression = CM_AUTO;
    customPrimitive->m_maxError = this->m_meshCInfo->m_maxConvexShapeError;
  }
  hkpConvexTransformShape::hkpConvexTransformShape(
    (hkpConvexTransformShape *)v73,
    retaddr,
    &v80,
    REFERENCE_POLICY_INCREMENT);
  v6 = retaddr;
  v7 = *(float *)&v74;
  m_storage = (unsigned __int8)retaddr->m_type.m_storage;
  result.m_enum = (hkResultEnum)v74;
  v9 = _mm_shuffle_ps((__m128)v74, (__m128)v74, 0);
  v10 = (m_storage & 0xFFFFFFFA) == 0 && m_storage != 5;
  if ( *(float *)&v74 != this->m_meshCInfo->m_convexRadius || v10 )
  {
    m_size = customPrimitive->m_tags.m_size;
    customPrimitive->m_tags.m_size = m_size + 1;
    *(float *)&result.m_enum = 1.0039062 * v7;
    customPrimitive->m_tags.m_data[m_size] = COERCE_INT(1.0039062 * v7) >> 16;
    v6 = retaddr;
  }
  if ( !m_storage )
  {
    if ( !this->m_caches.m_data[v5] )
    {
      Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v67 = (__m128 *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
      v68 = (hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *)v67;
      if ( v67 )
      {
        v67[2].m128_u64[0] = 0i64;
        v67[2].m128_i32[2] = 0;
        v67[2].m128_i32[3] = 0x80000000;
        *v67 = (__m128)xmmword_141A712A0;
        v67[1] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), *v67);
      }
      else
      {
        v68 = 0i64;
      }
      this->m_caches.m_data[v5] = v68;
      if ( v68->m_vertices.m_size == (v68->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v68->m_vertices.m_data, 16);
      v68->m_vertices.m_data[v68->m_vertices.m_size++] = v80.m_translation;
      p_m_quad = &v68->m_vertices.m_data->m_quad;
      v68->m_aabb.m_min.m_quad = _mm_sub_ps(*p_m_quad, v9);
      v68->m_aabb.m_max.m_quad = _mm_add_ps(*p_m_quad, v9);
    }
    v42 = 2;
    goto LABEL_66;
  }
  if ( m_storage == 1 )
  {
    result.m_enum = (hkResultEnum)LODWORD(v80.m_scale.m_quad.m128_f32[0]);
    LODWORD(v52) = (unsigned int)(2 * v80.m_scale.m_quad.m128_i32[0]) >> 1;
    v53 = v52 * hkpCylinderShape::getCylinderRadius(v6);
    if ( !this->m_caches.m_data[v5] )
    {
      v54 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v55 = (__m128 *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v54[11] + 8i64))(v54[11], 48i64);
      v56 = 0;
      v57 = (hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *)v55;
      if ( v55 )
      {
        v55[2].m128_u64[0] = 0i64;
        v55[2].m128_i32[2] = 0;
        v55[2].m128_i32[3] = 0x80000000;
        *v55 = (__m128)xmmword_141A712A0;
        v55[1] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), *v55);
      }
      else
      {
        v57 = 0i64;
      }
      this->m_caches.m_data[v5] = v57;
      hkArrayBase<hkVector4f>::_append(&v57->m_vertices, &hkContainerHeapAllocator::s_alloc, &v6->m_vertexA, 2);
      if ( v57->m_vertices.m_size > 0 )
      {
        v58 = 0i64;
        do
        {
          m_data = v57->m_vertices.m_data;
          ++v56;
          ++v58;
          v60 = _mm_shuffle_ps(v77, v77, 255);
          v61 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(
                      m_data[v58 - 1].m_quad,
                      _mm_movelh_ps(
                        _mm_unpacklo_ps(_mm_shuffle_ps(v76, v76, 255), _mm_shuffle_ps(v78, v78, 255)),
                        _mm_unpacklo_ps(_mm_shuffle_ps(v79, v79, 255), aabbOut.m_quad))),
                    v79),
                  _mm_mul_ps(m_data[v58 - 1].m_quad, v78));
          v62 = _mm_mul_ps(v77, v61);
          v63 = _mm_sub_ps(
                  _mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), v77),
                  _mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), v61));
          v64 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_add_ps(
                        _mm_add_ps(_mm_shuffle_ps(v62, v62, 85), _mm_shuffle_ps(v62, v62, 0)),
                        _mm_shuffle_ps(v62, v62, 170)),
                      v77),
                    _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v60, v60), (__m128)xmmword_141A711B0), v61)),
                  _mm_mul_ps(_mm_shuffle_ps(v63, v63, 201), v60));
          m_data[v58 - 1].m_quad = _mm_add_ps(_mm_add_ps(v64, v64), v76);
        }
        while ( v56 < v57->m_vertices.m_size );
      }
      hkpCylinderShape::hkpCylinderShape(&verticesOut, v57->m_vertices.m_data, v57->m_vertices.m_data + 1, v53, v7);
      hkpCylinderShape::getAabb(&verticesOut, (hkTransformf *)&transform, 0.0, &v57->m_aabb);
    }
    v65 = customPrimitive->m_tags.m_size;
    customPrimitive->m_tags.m_size = v65 + 1;
    *(float *)&result.m_enum = 1.0039062 * v53;
    customPrimitive->m_tags.m_data[v65] = COERCE_INT(1.0039062 * v53) >> 16;
    customPrimitive->m_customType = 4;
  }
  else
  {
    if ( m_storage != 3 )
    {
      if ( m_storage != 4 )
      {
        if ( m_storage == 5 )
        {
          if ( !this->m_caches.m_data[v5] )
          {
            v14 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v15 = (__m128 *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v14[11] + 8i64))(v14[11], 48i64);
            v16 = 0;
            v17 = (hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *)v15;
            if ( v15 )
            {
              v15[2].m128_u64[0] = 0i64;
              v15[2].m128_i32[2] = 0;
              v15[2].m128_i32[3] = 0x80000000;
              *v15 = (__m128)xmmword_141A712A0;
              v15[1] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), *v15);
            }
            else
            {
              v17 = 0i64;
            }
            this->m_caches.m_data[v5] = v17;
            hkpConvexVerticesShape::getOriginalVertices((hkpConvexVerticesShape *)v6, &v17->m_vertices);
            if ( v17->m_vertices.m_size > 0 )
            {
              v18 = 0i64;
              do
              {
                v19 = v17->m_vertices.m_data;
                ++v16;
                ++v18;
                v20 = _mm_shuffle_ps(v77, v77, 255);
                v21 = _mm_add_ps(
                        _mm_mul_ps(
                          _mm_sub_ps(
                            v19[v18 - 1].m_quad,
                            _mm_movelh_ps(
                              _mm_unpacklo_ps(_mm_shuffle_ps(v76, v76, 255), _mm_shuffle_ps(v78, v78, 255)),
                              _mm_unpacklo_ps(_mm_shuffle_ps(v79, v79, 255), aabbOut.m_quad))),
                          v79),
                        _mm_mul_ps(v19[v18 - 1].m_quad, v78));
                v22 = _mm_mul_ps(v77, v21);
                v23 = _mm_sub_ps(
                        _mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v77),
                        _mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), v21));
                v24 = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                              _mm_shuffle_ps(v22, v22, 170)),
                            v77),
                          _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v20, v20), (__m128)xmmword_141A711B0), v21)),
                        _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v20));
                v19[v18 - 1].m_quad = _mm_add_ps(_mm_add_ps(v24, v24), v76);
                v25 = v17->m_vertices.m_data;
                m_quad = v17->m_aabb.m_max.m_quad;
                v17->m_aabb.m_min.m_quad = _mm_min_ps(v17->m_aabb.m_min.m_quad, v25[v18 - 1].m_quad);
                v17->m_aabb.m_max.m_quad = _mm_max_ps(m_quad, v25[v18 - 1].m_quad);
              }
              while ( v16 < v17->m_vertices.m_size );
            }
            v27 = _mm_sub_ps(v17->m_aabb.m_min.m_quad, v9);
            v17->m_aabb.m_max.m_quad = _mm_add_ps(v17->m_aabb.m_max.m_quad, v9);
            v17->m_aabb.m_min.m_quad = v27;
          }
          customPrimitive->m_customType = 1;
        }
        else
        {
          hkErrStream::hkErrStream(&v72, buf, 512);
          v12 = hkOstream::operator<<(&v72, "Shape type ");
          v13 = hkOstream::operator<<(v12, m_storage);
          hkOstream::operator<<(v13, " not supported");
          if ( (unsigned int)hkError::messageError(
                               0x531B61C8u,
                               buf,
                               "Y:\\NightlyJobs\\09-12-Thu-05\\Source\\Physics2012/Internal/Collide/BvCompressedMesh/hkpB"
                               "vCompressedMeshShapeInternals.inl",
                               216) )
            __debugbreak();
          hkOstream::~hkOstream(&v72);
        }
        goto LABEL_67;
      }
      if ( !this->m_caches.m_data[v5] )
      {
        v28 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v29 = (__m128 *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v28[11] + 8i64))(v28[11], 48i64);
        v30 = 0;
        v31 = (hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *)v29;
        if ( v29 )
        {
          v29[2].m128_u64[0] = 0i64;
          v29[2].m128_i32[2] = 0;
          v29[2].m128_i32[3] = 0x80000000;
          *v29 = (__m128)xmmword_141A712A0;
          v29[1] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), *v29);
        }
        else
        {
          v31 = 0i64;
        }
        this->m_caches.m_data[v5] = v31;
        hkArrayBase<hkVector4f>::_append(&v31->m_vertices, &hkContainerHeapAllocator::s_alloc, &v6->m_vertexA, 2);
        if ( v31->m_vertices.m_size > 0 )
        {
          v32 = 0i64;
          do
          {
            v33 = v31->m_vertices.m_data;
            ++v30;
            ++v32;
            v34 = _mm_shuffle_ps(v77, v77, 255);
            v35 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_sub_ps(
                        v33[v32 - 1].m_quad,
                        _mm_movelh_ps(
                          _mm_unpacklo_ps(_mm_shuffle_ps(v76, v76, 255), _mm_shuffle_ps(v78, v78, 255)),
                          _mm_unpacklo_ps(_mm_shuffle_ps(v79, v79, 255), aabbOut.m_quad))),
                      v79),
                    _mm_mul_ps(v33[v32 - 1].m_quad, v78));
            v36 = _mm_mul_ps(v77, v35);
            v37 = _mm_sub_ps(
                    _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v77),
                    _mm_mul_ps(_mm_shuffle_ps(v77, v77, 201), v35));
            v38 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                          _mm_shuffle_ps(v36, v36, 170)),
                        v77),
                      _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v34, v34), (__m128)xmmword_141A711B0), v35)),
                    _mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v34));
            v33[v32 - 1].m_quad = _mm_add_ps(_mm_add_ps(v38, v38), v76);
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
      customPrimitive->m_customType = v42;
      goto LABEL_67;
    }
    if ( !this->m_caches.m_data[v5] )
    {
      v43 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
      v44 = (__m128 *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*v43[11] + 8i64))(v43[11], 48i64);
      v45 = (hkpBvCompressedMeshShape_Internals::GeometryProvider::Cache *)v44;
      if ( v44 )
      {
        v44[2].m128_u64[0] = 0i64;
        v44[2].m128_i32[2] = 0;
        v44[2].m128_i32[3] = 0x80000000;
        *v44 = (__m128)xmmword_141A712A0;
        v44[1] = _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), *v44);
      }
      else
      {
        v45 = 0i64;
      }
      v46 = 8i64;
      this->m_caches.m_data[v5] = v45;
      v72.vfptr = (hkBaseObjectVtbl *)0x3000200010000i64;
      *(_DWORD *)&v72.m_memSizeAndFlags = 327684;
      *(_DWORD *)(&v72.m_referenceCount + 1) = 458758;
      hkpConvexTransformShape::convertVertexIdsToVertices(
        (hkpConvexTransformShape *)v73,
        (const unsigned __int16 *)&v72,
        8u,
        (hkcdVertex *)&verticesOut);
      p_verticesOut = (__m128 *)&verticesOut;
      v48 = v45->m_aabb.m_min.m_quad;
      v49 = v45->m_aabb.m_max.m_quad;
      do
      {
        v48 = _mm_min_ps(v48, *p_verticesOut++);
        v45->m_aabb.m_min.m_quad = v48;
        v49 = _mm_max_ps(v49, p_verticesOut[-1]);
        v45->m_aabb.m_max.m_quad = v49;
        --v46;
      }
      while ( v46 );
      if ( (v45->m_vertices.m_capacityAndFlags & 0x3FFFFFFFu) < 4 )
      {
        v50 = 4;
        if ( 2 * (v45->m_vertices.m_capacityAndFlags & 0x3FFFFFFF) > 4 )
          v50 = 2 * (v45->m_vertices.m_capacityAndFlags & 0x3FFFFFFF);
        hkArrayUtil::_reserve(
          &result,
          &hkContainerHeapAllocator::s_alloc,
          (const void **)&v45->m_vertices.m_data,
          v50,
          16);
      }
      v45->m_vertices.m_size = 4;
      *v45->m_vertices.m_data = (hkVector4f)v82.m_quad;
      v45->m_vertices.m_data[1] = verticesOut.m_perpendicular2;
      v45->m_vertices.m_data[2] = verticesOut.m_perpendicular1;
      v45->m_vertices.m_data[3] = verticesOut.m_vertexA;
      v51 = _mm_sub_ps(v45->m_aabb.m_min.m_quad, v9);
      v45->m_aabb.m_max.m_quad = _mm_add_ps(v45->m_aabb.m_max.m_quad, v9);
      v45->m_aabb.m_min.m_quad = v51;
    }
    customPrimitive->m_customType = 0;
  }
LABEL_67:
  v70 = this->m_caches.m_data[v5];
  customPrimitive->m_aabb.m_min = v70->m_aabb.m_min;
  customPrimitive->m_aabb.m_max = v70->m_aabb.m_max;
  v71 = (hkReferencedObject *)v75;
  customPrimitive->m_numVertices = this->m_caches.m_data[v5]->m_vertices.m_size;
  v75 = &hkpSingleShapeContainer::`vftable;
  if ( v71 )
    hkReferencedObject::removeReference(v71);
}

// File Line: 333
// RVA: 0xE00A70
hkBool *__fastcall isCollisionEnabled(
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeContainer *shapeContainer,
        unsigned int shapeKey)
{
  hkpRayShapeCollectionFilter *m_rayShapeCollectionFilter; // rcx
  char v7; // [rsp+40h] [rbp+8h] BYREF

  m_rayShapeCollectionFilter = input->m_rayShapeCollectionFilter;
  if ( !m_rayShapeCollectionFilter
    || *(_BYTE *)m_rayShapeCollectionFilter->vfptr->isCollisionEnabled(
                   m_rayShapeCollectionFilter,
                   (hkBool *)&v7,
                   input,
                   shapeContainer,
                   shapeKey) )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

