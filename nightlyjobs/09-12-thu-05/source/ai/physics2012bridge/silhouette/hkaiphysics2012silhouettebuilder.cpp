// File Line: 65
// RVA: 0xC31BB0
hkpShape *__fastcall hkpTraverseShapeHierarchy_transform(
        hkpShape *shape,
        hkQsTransformf *transform,
        hkQsTransformf *childTransform)
{
  hkpShape *result; // rax
  hkQuaternionf v7; // xmm2
  __m128 v8; // xmm1
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  hkQuaternionf v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm6
  __m128 v14; // xmm5
  hkQuaternionf v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm6
  __m128 v18; // xmm0
  __m128 v19; // xmm3
  __m128 v20; // xmm6
  hkQuaternionf v21; // xmm2
  hkReferencedObject v22; // xmm3
  __m128 v23; // xmm1
  __m128 v24; // xmm5
  __m128 v25; // xmm6
  __m128 v26; // xmm4
  hkQuaternionf v27; // xmm6
  __m128 v28; // xmm2
  __m128 v29; // xmm4
  __m128 v30; // xmm0
  __m128 v31; // xmm5
  __m128 v32; // xmm3
  __m128 v33; // xmm6
  __m128 v34; // xmm3
  __m128 v35; // xmm3
  hkQuaternionf v36; // xmm2
  __m128 v37; // xmm5
  __m128 v38; // xmm1
  __m128 v39; // xmm4
  __m128 v40; // xmm6
  __m128 v41; // xmm3
  hkQsTransformf v42; // [rsp+20h] [rbp-48h] BYREF

  switch ( shape->m_type.m_storage )
  {
    case 0xA:
      *childTransform = *transform;
      v36.m_vec.m_quad = (__m128)transform->m_rotation;
      v37 = _mm_mul_ps((__m128)shape[2].hkReferencedObject, transform->m_scale.m_quad);
      v38 = _mm_mul_ps(v36.m_vec.m_quad, v37);
      v39 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v36.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v36.m_vec.m_quad, v36.m_vec.m_quad, 201), v37));
      v40 = _mm_shuffle_ps(v36.m_vec.m_quad, v36.m_vec.m_quad, 255);
      v41 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
                    _mm_shuffle_ps(v38, v38, 170)),
                  v36.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v40, v40), (__m128)xmmword_141A711B0), v37)),
              _mm_mul_ps(_mm_shuffle_ps(v39, v39, 201), v40));
      childTransform->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v41, v41), transform->m_translation.m_quad);
      return *(hkpShape **)&shape[1].m_type.m_storage;
    case 0xB:
      v21.m_vec.m_quad = (__m128)transform->m_rotation;
      v22 = shape[2].hkReferencedObject;
      v23 = _mm_mul_ps((__m128)v22, v21.m_vec.m_quad);
      v24 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps((__m128)v22, (__m128)v22, 201), v21.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v21.m_vec.m_quad, v21.m_vec.m_quad, 201), (__m128)v22));
      v25 = _mm_shuffle_ps(v21.m_vec.m_quad, v21.m_vec.m_quad, 255);
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                    _mm_shuffle_ps(v23, v23, 170)),
                  v21.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v25, v25), (__m128)xmmword_141A711B0), (__m128)v22)),
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25));
      childTransform->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v26, v26), transform->m_translation.m_quad);
      v27.m_vec.m_quad = (__m128)transform->m_rotation;
      v28 = *(__m128 *)&shape[2].m_type.m_storage;
      v29 = _mm_shuffle_ps(v27.m_vec.m_quad, v27.m_vec.m_quad, 255);
      v30 = _mm_mul_ps(_mm_shuffle_ps(v27.m_vec.m_quad, v27.m_vec.m_quad, 201), v28);
      v31 = _mm_shuffle_ps(v28, v28, 255);
      v32 = _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v27.m_vec.m_quad);
      v33 = _mm_mul_ps(v27.m_vec.m_quad, v28);
      v34 = _mm_sub_ps(v32, v30);
      v35 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v34, v34, 201), _mm_mul_ps(v28, v29)),
              _mm_mul_ps(transform->m_rotation.m_vec.m_quad, v31));
      childTransform->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                  v35,
                                                  _mm_unpackhi_ps(
                                                    v35,
                                                    _mm_sub_ps(
                                                      _mm_mul_ps(v31, v29),
                                                      _mm_add_ps(
                                                        _mm_add_ps(
                                                          _mm_shuffle_ps(v33, v33, 85),
                                                          _mm_shuffle_ps(v33, v33, 0)),
                                                        _mm_shuffle_ps(v33, v33, 170)))),
                                                  196);
      childTransform->m_scale.m_quad = _mm_mul_ps((__m128)shape[3].hkReferencedObject, transform->m_scale.m_quad);
      return *(hkpShape **)&shape[1].m_type.m_storage;
    case 0xE:
      hkQsTransformf::setFromTransform(&v42, (hkTransformf *)&shape[2].m_type);
      v7.m_vec.m_quad = (__m128)transform->m_rotation;
      v8 = _mm_mul_ps(v42.m_translation.m_quad, v7.m_vec.m_quad);
      v9 = _mm_shuffle_ps(v7.m_vec.m_quad, v7.m_vec.m_quad, 255);
      v10 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v42.m_translation.m_quad, v42.m_translation.m_quad, 201), v7.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v7.m_vec.m_quad, v7.m_vec.m_quad, 201), v42.m_translation.m_quad));
      v11.m_vec.m_quad = (__m128)v42.m_rotation;
      v12 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                    _mm_shuffle_ps(v8, v8, 170)),
                  v7.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v9, v9), (__m128)xmmword_141A711B0), v42.m_translation.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v9));
      v13 = _mm_shuffle_ps(v42.m_rotation.m_vec.m_quad, v42.m_rotation.m_vec.m_quad, 201);
      v14 = _mm_shuffle_ps(v42.m_rotation.m_vec.m_quad, v42.m_rotation.m_vec.m_quad, 255);
      childTransform->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v12, v12), transform->m_translation.m_quad);
      v15.m_vec.m_quad = (__m128)transform->m_rotation;
      v16 = _mm_shuffle_ps(v15.m_vec.m_quad, v15.m_vec.m_quad, 255);
      v17 = _mm_sub_ps(
              _mm_mul_ps(v13, v15.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v15.m_vec.m_quad, v15.m_vec.m_quad, 201), v11.m_vec.m_quad));
      v18 = _mm_mul_ps(v11.m_vec.m_quad, v16);
      v19 = _mm_mul_ps(v11.m_vec.m_quad, v15.m_vec.m_quad);
      v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 201), v18), _mm_mul_ps(v15.m_vec.m_quad, v14));
      childTransform->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                                  v20,
                                                  _mm_unpackhi_ps(
                                                    v20,
                                                    _mm_sub_ps(
                                                      _mm_mul_ps(v14, v16),
                                                      _mm_add_ps(
                                                        _mm_add_ps(
                                                          _mm_shuffle_ps(v19, v19, 85),
                                                          _mm_shuffle_ps(v19, v19, 0)),
                                                        _mm_shuffle_ps(v19, v19, 170)))),
                                                  196);
      childTransform->m_scale.m_quad = _mm_mul_ps(transform->m_scale.m_quad, v42.m_scale.m_quad);
      return *(hkpShape **)&shape[1].m_memSizeAndFlags;
    default:
      result = 0i64;
      childTransform->m_translation = 0i64;
      childTransform->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
      childTransform->m_scale = (hkVector4f)query.m_quad;
      break;
  }
  return result;
}kVector4f)query.m_quad;
      break;
  }
  return result;
}

// File Line: 117
// RVA: 0xC31270
__int64 __fastcall hkpTraverseShapeHierarchy(
        hkpShape *shape,
        hkpShapeHierarchyWalker *callback,
        hkQsTransformf *transform)
{
  hkQsTransformf *v5; // rbx
  __int64 result; // rax
  hkpShapeHierarchyWalker::WalkResult v7; // eax
  hkpShape *v8; // rax
  hkQsTransformf *p_childTransform; // r8
  hkpShape *v10; // rcx
  __int64 v11; // rbx
  unsigned int v12; // edi
  hkpShape *v13; // rax
  hkpShapeHierarchyWalker::WalkResult v14; // eax
  unsigned int v15; // ebx
  int v16; // edi
  __m128 *p_m_type; // rcx
  __m128 m_quad; // xmm4
  hkVector4f v19; // xmm7
  __m128 v20; // xmm5
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm6
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  hkpShapeHierarchyWalker::WalkResult v26; // eax
  hkQsTransformf childTransform; // [rsp+20h] [rbp-2A8h] BYREF
  hkpSphereShape v28; // [rsp+50h] [rbp-278h] BYREF
  char v29[512]; // [rsp+90h] [rbp-238h] BYREF
  hkEnum<enum hkcdShapeType::ShapeTypeEnum,unsigned char> *v30; // [rsp+2D8h] [rbp+10h]

  v5 = transform;
  result = ((__int64 (__fastcall *)(hkpShapeHierarchyWalker *, hkpShape *))callback->vfptr->preShapeCallback)(
             callback,
             shape);
  if ( (_DWORD)result != 1 )
  {
    if ( (_DWORD)result == 2 )
    {
      return 0i64;
    }
    else
    {
      switch ( shape->m_type.m_storage )
      {
        case 6:
        case 7:
        case 8:
        case 9:
        case 0xD:
        case 0xF:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x16:
        case 0x1A:
        case 0x1B:
          v11 = ((__int64 (__fastcall *)(hkpShape *))shape->vfptr[7].__vecDelDtor)(shape);
          v12 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 16i64))(v11);
          if ( v12 == -1 )
            goto LABEL_13;
          while ( 1 )
          {
            v13 = (hkpShape *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v11 + 40i64))(
                                v11,
                                v12,
                                v29);
            if ( v13 )
            {
              v14 = hkpTraverseShapeHierarchy(v13, callback, transform);
              if ( v14 == RESULT_STOP )
                return 1i64;
              if ( v14 == RESULT_RETURN )
                return 0i64;
            }
            v12 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v11 + 24i64))(v11, v12);
            if ( v12 == -1 )
              goto LABEL_13;
          }
        case 0xA:
        case 0xB:
        case 0xE:
          v8 = hkpTraverseShapeHierarchy_transform(shape, v5, &childTransform);
          if ( !v8 )
            return ((__int64 (__fastcall *)(hkpShapeHierarchyWalker *, hkpShape *, hkQsTransformf *))callback->vfptr->postShapeCallback)(
                     callback,
                     shape,
                     v5);
          p_childTransform = &childTransform;
          v10 = v8;
LABEL_17:
          v7 = hkpTraverseShapeHierarchy(v10, callback, p_childTransform);
LABEL_18:
          if ( v7 == RESULT_STOP )
            return 1i64;
          if ( v7 != RESULT_RETURN )
            return ((__int64 (__fastcall *)(hkpShapeHierarchyWalker *, hkpShape *, hkQsTransformf *))callback->vfptr->postShapeCallback)(
                     callback,
                     shape,
                     v5);
          return 0i64;
        case 0x19:
          v15 = 0;
          v16 = 0;
          if ( SLODWORD(shape[1].vfptr) <= 0 )
            goto LABEL_13;
          p_m_type = (__m128 *)&shape[1].m_type;
          v30 = &shape[1].m_type;
          break;
        case 0x1E:
          v10 = *(hkpShape **)&shape[1].m_type.m_storage;
          p_childTransform = v5;
          goto LABEL_17;
        default:
          v7 = callback->vfptr->leafShapeCallback(callback, shape, v5);
          goto LABEL_18;
      }
      do
      {
        m_quad = transform->m_rotation.m_vec.m_quad;
        v19.m_quad = (__m128)transform->m_translation;
        v20 = _mm_mul_ps(*p_m_type, transform->m_scale.m_quad);
        childTransform.m_scale = transform->m_scale;
        childTransform.m_rotation.m_vec.m_quad = m_quad;
        v21 = _mm_mul_ps(m_quad, v20);
        v22 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), m_quad),
                _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v20));
        v23 = _mm_shuffle_ps(m_quad, m_quad, 255);
        v24 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                    _mm_shuffle_ps(v21, v21, 170)),
                  m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, v23), (__m128)xmmword_141A711B0), v20));
        v21.m128_i32[0] = p_m_type->m128_i32[3];
        v25 = _mm_add_ps(v24, _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v23));
        childTransform.m_translation.m_quad = _mm_add_ps(v19.m_quad, _mm_add_ps(v25, v25));
        hkpSphereShape::hkpSphereShape(&v28, v21.m128_f32[0]);
        v26 = callback->vfptr->leafShapeCallback(callback, &v28, &childTransform);
        if ( v26 == RESULT_STOP )
          return 1;
        if ( v26 == RESULT_RETURN )
          return v15;
        ++v16;
        p_m_type = (__m128 *)&v30[16];
        v30 += 16;
      }
      while ( v16 < SLODWORD(shape[1].vfptr) );
LABEL_13:
      v5 = transform;
      return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))callback->vfptr->postShapeCallback)(callback, shape, v5);
    }
  }
  return result;
}

// File Line: 246
// RVA: 0xC31EB0
__int64 __fastcall hkaiSilhouetteHierarchyWalker::leafShapeCallback(
        hkaiSilhouetteHierarchyWalker *this,
        hkpCylinderShape *shape,
        hkQsTransformf *transform)
{
  hkArray<hkVector4f,hkContainerHeapAllocator> *v5; // rbx
  int m_size; // esi
  __int64 v7; // r14
  int v8; // r9d
  int v9; // eax
  int v10; // eax
  hkQuaternionf v11; // xmm5
  hkVector4f v12; // xmm9
  hkVector4f v13; // xmm10
  __int64 v14; // r8
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  __m128 *v17; // r9
  hkVector4f *v18; // rdx
  __m128 v19; // xmm8
  __m128 m_quad; // xmm3
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  hkArray<int,hkContainerHeapAllocator> *v25; // rbx
  int v26; // esi
  __m128 *v27; // rsi
  __int64 v28; // r14
  hkArray<hkVector4f,hkContainerHeapAllocator> *m_vertices; // rbx
  __m128 v30; // xmm6
  __m128 *p_m_quad; // rcx
  hkQuaternionf v32; // xmm2
  __m128 v33; // xmm5
  __m128 v34; // xmm6
  __m128 v35; // xmm1
  __m128 v36; // xmm4
  __m128 v37; // xmm3
  hkArray<int,hkContainerHeapAllocator> *m_sizes; // rbx
  hkArray<hkVector4f,hkContainerTempAllocator> vertsOut; // [rsp+30h] [rbp-88h] BYREF
  __m128 v41; // [rsp+40h] [rbp-78h]
  hkResult result; // [rsp+C8h] [rbp+10h] BYREF

  if ( shape->m_type.m_storage > 5u )
  {
    ((void (__fastcall *)(hkpCylinderShape *, hkVector4f *, hkQsTransformf *, hkArray<hkVector4f,hkContainerTempAllocator> *))shape->vfptr[2].__vecDelDtor)(
      shape,
      &::transform,
      transform,
      &vertsOut);
    v27 = (__m128 *)hkVector4fComparison_maskToComparison_254;
    v28 = 8i64;
    do
    {
      m_vertices = this->m_vertices;
      v30 = _mm_or_ps(_mm_andnot_ps(*v27, (__m128)vertsOut), _mm_and_ps(v41, *v27));
      if ( m_vertices->m_size == (m_vertices->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this->m_vertices, 16);
      ++v27;
      p_m_quad = &m_vertices->m_data[m_vertices->m_size++].m_quad;
      v32.m_vec.m_quad = (__m128)transform->m_rotation;
      v33 = _mm_mul_ps(transform->m_scale.m_quad, v30);
      v34 = _mm_shuffle_ps(v32.m_vec.m_quad, v32.m_vec.m_quad, 255);
      v35 = _mm_mul_ps(v33, v32.m_vec.m_quad);
      v36 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), v32.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v32.m_vec.m_quad, v32.m_vec.m_quad, 201), v33));
      v37 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v35, v35, 0), _mm_shuffle_ps(v35, v35, 85)),
                    _mm_shuffle_ps(v35, v35, 170)),
                  v32.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v34, v34), (__m128)xmmword_141A711B0), v33)),
              _mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), v34));
      *p_m_quad = _mm_add_ps(_mm_add_ps(v37, v37), transform->m_translation.m_quad);
      --v28;
    }
    while ( v28 );
    m_sizes = this->m_sizes;
    if ( m_sizes->m_size == (m_sizes->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this->m_sizes, 4);
    m_sizes->m_data[m_sizes->m_size++] = 8;
  }
  else
  {
    vertsOut.m_data = 0i64;
    vertsOut.m_size = 0;
    vertsOut.m_capacityAndFlags = 0x80000000;
    hkaiPhysics2012SilhouetteBuilder::getVertices(shape, &vertsOut);
    v5 = this->m_vertices;
    m_size = vertsOut.m_size;
    v7 = v5->m_size;
    v8 = v7 + vertsOut.m_size;
    v9 = v5->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < (int)v7 + vertsOut.m_size )
    {
      v10 = 2 * v9;
      if ( v8 < v10 )
        v8 = v10;
      hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, this->m_vertices, v8, 16);
    }
    v5->m_size += m_size;
    v11.m_vec.m_quad = (__m128)transform->m_rotation;
    v12.m_quad = (__m128)transform->m_translation;
    v13.m_quad = (__m128)transform->m_scale;
    v14 = vertsOut.m_size - 1;
    v15 = _mm_shuffle_ps(v11.m_vec.m_quad, v11.m_vec.m_quad, 255);
    v16 = _mm_shuffle_ps(v11.m_vec.m_quad, v11.m_vec.m_quad, 201);
    v17 = &v5->m_data[v7 + v14].m_quad;
    v18 = &vertsOut.m_data[v14];
    v19 = _mm_mul_ps(v15, v15);
    do
    {
      m_quad = v18->m_quad;
      --v17;
      --v18;
      --v14;
      v21 = _mm_mul_ps(m_quad, v13.m_quad);
      v22 = _mm_mul_ps(v11.m_vec.m_quad, v21);
      v23 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v11.m_vec.m_quad), _mm_mul_ps(v21, v16));
      v24 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                    _mm_shuffle_ps(v22, v22, 170)),
                  v11.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(v19, (__m128)xmmword_141A711B0), v21)),
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v15));
      v17[1] = _mm_add_ps(_mm_add_ps(v24, v24), v12.m_quad);
    }
    while ( v14 >= 0 );
    v25 = this->m_sizes;
    v26 = vertsOut.m_size;
    if ( v25->m_size == (v25->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, this->m_sizes, 4);
    v25->m_data[v25->m_size++] = v26;
    vertsOut.m_size = 0;
    if ( vertsOut.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        &hkContainerTempAllocator::s_alloc,
        vertsOut.m_data,
        16 * vertsOut.m_capacityAndFlags);
  }
  return 0i64;
}

// File Line: 292
// RVA: 0xC30FF0
void __fastcall hkaiPhysics2012SilhouetteBuilder::createPointCloudFromShapeRecursive(
        hkpShape *shape,
        hkQsTransformf *transform,
        hkArray<hkVector4f,hkContainerHeapAllocator> *verticesOut,
        hkArray<int,hkContainerHeapAllocator> *sizesOut)
{
  hkpShapeHierarchyWalker callback; // [rsp+20h] [rbp-28h] BYREF
  hkArray<hkVector4f,hkContainerHeapAllocator> *v5; // [rsp+28h] [rbp-20h]
  hkArray<int,hkContainerHeapAllocator> *v6; // [rsp+30h] [rbp-18h]

  v5 = verticesOut;
  v6 = sizesOut;
  callback.vfptr = (hkpShapeHierarchyWalkerVtbl *)&hkaiSilhouetteHierarchyWalker::`vftable;
  hkpTraverseShapeHierarchy(shape, &callback, transform);
}

// File Line: 298
// RVA: 0xC31550
// attributes: thunk
void __fastcall case_sphere(
        hkVector4f *p,
        hkSimdFloat32 *radius,
        hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  hkaiPhysicsBodySilhouetteGeneratorBase::getPointsForSphere(p, radius, vertsOut);
}

// File Line: 303
// RVA: 0xC31560
void __fastcall case_cylinder(
        hkVector4f *p0,
        hkVector4f *p1,
        hkSimdFloat32 *radius,
        hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  __m128 v8; // xmm11
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm2
  __m128 v12; // xmm11
  __m128 v13; // xmm2
  __m128 v14; // xmm11
  __m128 v15; // xmm5
  __m128 v16; // xmm11
  __m128 v17; // xmm1
  __m128 v18; // xmm4
  __m128 v19; // xmm2
  __m128 v20; // xmm11
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm11
  __m128i si128; // xmm6
  __m128 v26; // xmm10
  __m128i v27; // xmm9
  __m128 v28; // xmm2
  __m128i v29; // xmm6
  __m128 v30; // xmm5
  __m128 v31; // xmm4
  __m128 m_quad; // xmm6
  __m128 v33; // xmm4
  __m128 v34; // xmm2
  unsigned int v35; // xmm0_4
  __m128 v36; // xmm9
  __m128 v37; // xmm8
  __int64 v38; // rsi
  __m128 v39; // xmm1
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm7
  __m128 v43; // xmm7
  __m128 v44; // xmm7
  hkVector4f *v45; // rcx
  hkVector4f *v46; // rcx
  __m128 v47; // xmm5
  __m128 v48; // xmm6
  __m128 v49; // xmm3
  __m128 v50; // xmm4
  __m128 v51; // xmm6
  hkQuaternionf v52; // [rsp+20h] [rbp-98h] BYREF
  hkVector4f axis; // [rsp+30h] [rbp-88h] BYREF
  hkQuaternionf v54; // [rsp+40h] [rbp-78h] BYREF

  v8 = _mm_sub_ps(p1->m_quad, p0->m_quad);
  v9 = _mm_mul_ps(v8, v8);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  v12 = _mm_mul_ps(
          v8,
          _mm_andnot_ps(
            _mm_cmple_ps(v10, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
              _mm_mul_ps(*(__m128 *)_xmm, v11))));
  axis.m_quad = v12;
  v13 = _mm_mul_ps(v12, v12);
  if ( (float)((float)(_mm_shuffle_ps(v13, v13, 85).m128_f32[0] + _mm_shuffle_ps(v13, v13, 0).m128_f32[0])
             + _mm_shuffle_ps(v13, v13, 170).m128_f32[0]) >= 0.5 )
  {
    v14 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, (__m128)0i64), 196);
    v15 = _mm_shuffle_ps(v14, v14, 241);
    v16 = _mm_shuffle_ps(v14, v14, 206);
    v17 = _mm_mul_ps(v16, v16);
    v18 = _mm_mul_ps(v15, v15);
    v19 = _mm_cmplt_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
              _mm_shuffle_ps(v18, v18, 170)),
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v17, v17, 85), _mm_shuffle_ps(v17, v17, 0)),
              _mm_shuffle_ps(v17, v17, 170)));
    v20 = _mm_xor_ps(
            _mm_or_ps(_mm_and_ps(v16, v19), _mm_andnot_ps(v19, v15)),
            (__m128)_mm_insert_epi16((__m128i)0i64, 0x8000u, 1));
    v21 = _mm_mul_ps(v20, v20);
    v22 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
            _mm_shuffle_ps(v21, v21, 170));
    v23 = _mm_rsqrt_ps(v22);
    v24 = _mm_mul_ps(
            v20,
            _mm_andnot_ps(
              _mm_cmple_ps(v22, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                _mm_mul_ps(*(__m128 *)_xmm, v23))));
    hkQuaternionf::setAxisAngle(&v54, &axis, 0.69813174);
    hkQuaternionf::setAxisAngle(&v52, &axis, 0.0);
    si128 = _mm_load_si128((const __m128i *)_xmm);
    v26 = _mm_add_ps((__m128)LODWORD(FLOAT_0_34906587), *(__m128 *)_xmm);
    v27 = _mm_add_epi32(si128, si128);
    v28 = _mm_andnot_ps(*(__m128 *)_xmm, v26);
    v29 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v28, *(__m128 *)_xmm)), si128));
    v30 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v29, v27), (__m128i)0i64);
    v31 = _mm_cvtepi32_ps(v29);
    v27.m128i_i32[0] = _mm_and_si128(_mm_add_epi32(v27, v27), v29).m128i_u32[0];
    m_quad = v52.m_vec.m_quad;
    v33 = _mm_add_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(v31, *(__m128 *)DP1_0), v28), _mm_mul_ps(v31, *(__m128 *)DP2)),
            _mm_mul_ps(v31, *(__m128 *)DP3));
    v34 = _mm_mul_ps(v33, v33);
    *(float *)&v35 = 1.0
                   / COERCE_FLOAT((_mm_andnot_ps(
                                     v30,
                                     _mm_add_ps(
                                       _mm_sub_ps(
                                         _mm_mul_ps(
                                           _mm_mul_ps(
                                             _mm_add_ps(
                                               _mm_mul_ps(
                                                 _mm_add_ps(
                                                   _mm_mul_ps(v34, *(__m128 *)cosCoeff0_0),
                                                   *(__m128 *)cosCoeff1),
                                                 v34),
                                               *(__m128 *)cosCoeff2_0),
                                             v34),
                                           v34),
                                         _mm_mul_ps(v34, *(__m128 *)_xmm)),
                                       *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                                                         (float)((float)((float)((float)((float)((float)(v34.m128_f32[0] * -0.00019515296) + 0.0083321612) * v34.m128_f32[0])
                                                                                               + -0.16666655)
                                                                                       * v34.m128_f32[0])
                                                                               * v33.m128_f32[0])
                                                                       + v33.m128_f32[0]) & v30.m128_i32[0]) ^ (v27.m128i_i32[0] << 29) ^ v26.m128_i32[0] & _xmm[0]);
    v36 = _mm_shuffle_ps(v24, v24, 201);
    v37 = _mm_mul_ps(_mm_shuffle_ps((__m128)v35, (__m128)v35, 0), radius->m_real);
    v38 = 9i64;
    do
    {
      v39 = _mm_mul_ps(m_quad, v24);
      v40 = _mm_shuffle_ps(m_quad, m_quad, 255);
      v41 = _mm_sub_ps(_mm_mul_ps(m_quad, v36), _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v24));
      v42 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                    _mm_shuffle_ps(v39, v39, 170)),
                  m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v40, v40), (__m128)xmmword_141A711B0), v24)),
              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v40));
      v43 = _mm_add_ps(v42, v42);
      if ( vertsOut->m_size == (vertsOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, vertsOut, 16);
      v44 = _mm_mul_ps(v43, v37);
      v45 = &vertsOut->m_data[vertsOut->m_size++];
      v45->m_quad = _mm_add_ps(p0->m_quad, v44);
      if ( vertsOut->m_size == (vertsOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, vertsOut, 16);
      v46 = &vertsOut->m_data[vertsOut->m_size++];
      v46->m_quad = _mm_add_ps(v44, p1->m_quad);
      v47 = _mm_shuffle_ps(v54.m_vec.m_quad, v54.m_vec.m_quad, 255);
      v48 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v54.m_vec.m_quad, v54.m_vec.m_quad, 201), v52.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v52.m_vec.m_quad, v52.m_vec.m_quad, 201), v54.m_vec.m_quad));
      v49 = _mm_mul_ps(v54.m_vec.m_quad, v52.m_vec.m_quad);
      v50 = _mm_shuffle_ps(v52.m_vec.m_quad, v52.m_vec.m_quad, 255);
      v51 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v48, v48, 201), _mm_mul_ps(v54.m_vec.m_quad, v50)),
              _mm_mul_ps(v52.m_vec.m_quad, v47));
      m_quad = _mm_shuffle_ps(
                 v51,
                 _mm_unpackhi_ps(
                   v51,
                   _mm_sub_ps(
                     _mm_mul_ps(v47, v50),
                     _mm_add_ps(
                       _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                       _mm_shuffle_ps(v49, v49, 170)))),
                 196);
      v52.m_vec.m_quad = m_quad;
      --v38;
    }
    while ( v38 );
  }
  else
  {
    case_sphere(p0, radius, vertsOut);
  }
}

// File Line: 344
// RVA: 0xC31A30
// attributes: thunk
void __fastcall case_capsule(
        hkVector4f *p0,
        hkVector4f *p1,
        hkSimdFloat32 *radius,
        hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  hkaiPhysicsBodySilhouetteGeneratorBase::getPointsForCapsule(p0, p1, radius, vertsOut);
}

// File Line: 349
// RVA: 0xC31A40
void __fastcall case_triangle(
        hkVector4f *p,
        hkSimdFloat32 *radius,
        hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  hkVector4f *v5; // rdi
  __int64 v6; // rbx
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm6
  __m128 v10; // xmm6
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm6
  int v15; // r9d
  __int64 v16; // rcx
  hkResult result; // [rsp+60h] [rbp+8h] BYREF

  v5 = p;
  v6 = 1i64;
  v7 = _mm_sub_ps(p->m_quad, p[2].m_quad);
  v8 = _mm_sub_ps(p[2].m_quad, p[1].m_quad);
  v9 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v8), _mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v7));
  v10 = _mm_shuffle_ps(v9, v9, 201);
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_mul_ps(
          v10,
          _mm_andnot_ps(
            _mm_cmple_ps(v12, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)),
              _mm_mul_ps(*(__m128 *)_xmm, v13))));
  if ( (vertsOut->m_capacityAndFlags & 0x3FFFFFFFu) < 6 )
  {
    v15 = 6;
    if ( 2 * (vertsOut->m_capacityAndFlags & 0x3FFFFFFF) > 6 )
      v15 = 2 * (vertsOut->m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, vertsOut, v15, 16);
  }
  vertsOut->m_size = 6;
  v16 = 0i64;
  do
  {
    v6 += 2i64;
    v16 += 2i64;
    ++v5;
    vertsOut->m_data[v16 - 2].m_quad = _mm_add_ps(_mm_mul_ps(radius->m_real, v14), v5[-1].m_quad);
    vertsOut->m_data[v6 - 2].m_quad = _mm_add_ps(
                                        _mm_mul_ps(_mm_sub_ps((__m128)0i64, radius->m_real), v14),
                                        v5[-1].m_quad);
  }
  while ( v6 < 7 );
}

// File Line: 364
// RVA: 0xC31030
void __fastcall hkaiPhysics2012SilhouetteBuilder::getVertices(
        hkpCylinderShape *s,
        hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  int v7; // r14d
  int v8; // ecx
  int v9; // r9d
  hkVector4f *m_data; // rdx
  hkVector4f *v11; // rax
  __int128 v12; // xmm1
  hkSimdFloat32 radius; // [rsp+30h] [rbp-19h] BYREF
  hkVector4f p; // [rsp+40h] [rbp-9h] BYREF
  hkVector4f p0; // [rsp+50h] [rbp+7h] BYREF
  hkVector4f v16; // [rsp+60h] [rbp+17h] BYREF
  __int128 v17; // [rsp+70h] [rbp+27h]
  hkVector4f v18; // [rsp+80h] [rbp+37h]
  hkResult result; // [rsp+B0h] [rbp+67h] BYREF

  switch ( s->m_type.m_storage )
  {
    case 0:
      result.m_enum = (hkResultEnum)LODWORD(s->m_radius);
      p.m_quad = 0i64;
      p0.m_quad = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
      case_sphere(&p, (hkSimdFloat32 *)&p0, vertsOut);
      break;
    case 1:
      *(float *)&result.m_enum = hkpCylinderShape::getCylinderRadius(s);
      p0.m_quad = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
      case_cylinder(&s->m_vertexA, &s->m_vertexB, (hkSimdFloat32 *)&p0, vertsOut);
      break;
    case 2:
      *(float *)&result.m_enum = s->m_radius + 0.0099999998;
      p0.m_quad = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
      case_triangle(&s->m_vertexA, (hkSimdFloat32 *)&p0, vertsOut);
      break;
    case 3:
    case 5:
      v4 = ((__int64 (__fastcall *)(hkpCylinderShape *))s->vfptr[5].__first_virtual_table_function__)(s);
      v5 = ((__int64 (__fastcall *)(hkpCylinderShape *))s->vfptr[5].__first_virtual_table_function__)(s);
      v6 = vertsOut->m_capacityAndFlags & 0x3FFFFFFF;
      v7 = v5;
      if ( v6 < v5 )
      {
        v8 = 2 * v6;
        v9 = v5;
        if ( v5 < v8 )
          v9 = v8;
        hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, vertsOut, v9, 16);
      }
      m_data = vertsOut->m_data;
      vertsOut->m_size = v7;
      s->vfptr[6].__vecDelDtor(s, (unsigned int)m_data);
      if ( (unsigned int)(v4 - 1) <= 2 )
      {
        v11 = vertsOut->m_data;
        radius.m_real = _mm_shuffle_ps(vertsOut->m_data->m_quad, vertsOut->m_data->m_quad, 255);
        if ( v4 == 1 )
        {
          p.m_quad = v11->m_quad;
          case_sphere(&p, &radius, vertsOut);
        }
        else if ( v4 == 2 )
        {
          p0.m_quad = v11->m_quad;
          p.m_quad = (__m128)v11[1];
          case_capsule(&p0, &p, &radius, vertsOut);
        }
        else
        {
          v12 = (__int128)v11[1];
          v16.m_quad = v11->m_quad;
          v18.m_quad = (__m128)v11[2];
          v17 = v12;
          case_triangle(&v16, &radius, vertsOut);
        }
      }
      break;
    case 4:
      p0.m_quad = _mm_shuffle_ps(s->m_vertexA.m_quad, s->m_vertexA.m_quad, 255);
      case_capsule(&s->m_vertexA, &s->m_vertexB, (hkSimdFloat32 *)&p0, vertsOut);
      break;
    default:
      return;
  }
}

