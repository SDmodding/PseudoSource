// File Line: 65
// RVA: 0xC31BB0
hkpShape *__fastcall hkpTraverseShapeHierarchy_transform(hkpShape *shape, hkQsTransformf *transform, hkQsTransformf *childTransform)
{
  hkQsTransformf *v3; // rbx
  hkQsTransformf *v4; // rdi
  hkpShape *v5; // rsi
  hkpShape *result; // rax
  __m128 v7; // xmm2
  __m128 v8; // xmm1
  __m128 v9; // xmm6
  __m128 v10; // xmm5
  hkQuaternionf v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm6
  __m128 v14; // xmm5
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm6
  __m128 v18; // xmm0
  __m128 v19; // xmm3
  __m128 v20; // xmm6
  hkQuaternionf v21; // xmm2
  __m128 v22; // xmm3
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
  hkQsTransformf v42; // [rsp+20h] [rbp-48h]

  v3 = childTransform;
  v4 = transform;
  v5 = shape;
  switch ( shape->m_type.m_storage )
  {
    case 0xA:
      childTransform->m_translation = transform->m_translation;
      childTransform->m_rotation = transform->m_rotation;
      childTransform->m_scale = transform->m_scale;
      v36.m_vec.m_quad = (__m128)transform->m_rotation;
      v37 = _mm_mul_ps(*(__m128 *)&shape[2].vfptr, transform->m_scale.m_quad);
      v38 = _mm_mul_ps(transform->m_rotation.m_vec.m_quad, v37);
      v39 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v37, v37, 201), v36.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v36.m_vec.m_quad, v36.m_vec.m_quad, 201), v37));
      v40 = _mm_shuffle_ps(transform->m_rotation.m_vec.m_quad, v36.m_vec.m_quad, 255);
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
      v22 = *(__m128 *)&shape[2].vfptr;
      v23 = _mm_mul_ps(*(__m128 *)&shape[2].vfptr, v21.m_vec.m_quad);
      v24 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v21.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v21.m_vec.m_quad, v21.m_vec.m_quad, 201), v22));
      v25 = _mm_shuffle_ps(transform->m_rotation.m_vec.m_quad, v21.m_vec.m_quad, 255);
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                    _mm_shuffle_ps(v23, v23, 170)),
                  v21.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v25, v25), (__m128)xmmword_141A711B0), v22)),
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), v25));
      childTransform->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v26, v26), transform->m_translation.m_quad);
      v27.m_vec.m_quad = (__m128)transform->m_rotation;
      v28 = *(__m128 *)&shape[2].m_type.m_storage;
      v29 = _mm_shuffle_ps(transform->m_rotation.m_vec.m_quad, transform->m_rotation.m_vec.m_quad, 255);
      v30 = _mm_mul_ps(_mm_shuffle_ps(v27.m_vec.m_quad, v27.m_vec.m_quad, 201), v28);
      v31 = _mm_shuffle_ps(*(__m128 *)&shape[2].m_type.m_storage, *(__m128 *)&shape[2].m_type.m_storage, 255);
      v32 = _mm_mul_ps(_mm_shuffle_ps(v28, v28, 201), v27.m_vec.m_quad);
      v33 = _mm_mul_ps(v27.m_vec.m_quad, v28);
      v34 = _mm_sub_ps(v32, v30);
      v35 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v34, v34, 201), _mm_mul_ps(*(__m128 *)&shape[2].m_type.m_storage, v29)),
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
      childTransform->m_scale.m_quad = _mm_mul_ps(*(__m128 *)&shape[3].vfptr, transform->m_scale.m_quad);
      return *(hkpShape **)&shape[1].m_type.m_storage;
    case 0xE:
      hkQsTransformf::setFromTransform(&v42, (hkTransformf *)&shape[2].m_type);
      v7 = v4->m_rotation.m_vec.m_quad;
      v8 = _mm_mul_ps(v42.m_translation.m_quad, v7);
      v9 = _mm_shuffle_ps(v4->m_rotation.m_vec.m_quad, v7, 255);
      v10 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v42.m_translation.m_quad, v42.m_translation.m_quad, 201), v7),
              _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), v42.m_translation.m_quad));
      v11.m_vec.m_quad = (__m128)v42.m_rotation;
      v12 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                    _mm_shuffle_ps(v8, v8, 170)),
                  v7),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v9, v9), (__m128)xmmword_141A711B0), v42.m_translation.m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v10, v10, 201), v9));
      v13 = _mm_shuffle_ps(v42.m_rotation.m_vec.m_quad, v42.m_rotation.m_vec.m_quad, 201);
      v14 = _mm_shuffle_ps(v42.m_rotation.m_vec.m_quad, v42.m_rotation.m_vec.m_quad, 255);
      v3->m_translation.m_quad = _mm_add_ps(_mm_add_ps(v12, v12), v4->m_translation.m_quad);
      v15 = v4->m_rotation.m_vec.m_quad;
      v16 = _mm_shuffle_ps(v4->m_rotation.m_vec.m_quad, v4->m_rotation.m_vec.m_quad, 255);
      v17 = _mm_sub_ps(
              _mm_mul_ps(v13, v15),
              _mm_mul_ps(_mm_shuffle_ps(v4->m_rotation.m_vec.m_quad, v15, 201), v11.m_vec.m_quad));
      v18 = _mm_mul_ps(v11.m_vec.m_quad, v16);
      v19 = _mm_mul_ps(v11.m_vec.m_quad, v15);
      v20 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v17, v17, 201), v18), _mm_mul_ps(v4->m_rotation.m_vec.m_quad, v14));
      v3->m_rotation.m_vec.m_quad = _mm_shuffle_ps(
                                      v20,
                                      _mm_unpackhi_ps(
                                        v20,
                                        _mm_sub_ps(
                                          _mm_mul_ps(v14, v16),
                                          _mm_add_ps(
                                            _mm_add_ps(_mm_shuffle_ps(v19, v19, 85), _mm_shuffle_ps(v19, v19, 0)),
                                            _mm_shuffle_ps(v19, v19, 170)))),
                                      196);
      v3->m_scale.m_quad = _mm_mul_ps(v4->m_scale.m_quad, v42.m_scale.m_quad);
      result = *(hkpShape **)&v5[1].m_memSizeAndFlags;
      break;
    default:
      result = 0i64;
      childTransform->m_translation = 0i64;
      childTransform->m_rotation = (hkQuaternionf)qi.m_vec.m_quad;
      childTransform->m_scale = (hkVector4f)query.m_quad;
      break;
  }
  return result;
} = (hkVector4f)query.m_quad;
      break;
  }
  return result;
}

// File Line: 117
// RVA: 0xC31270
__int64 __fastcall hkpTraverseShapeHierarchy(hkpShape *shape, hkpShapeHierarchyWalker *callback, hkQsTransformf *transform)
{
  hkpShapeHierarchyWalker *v3; // rbp
  hkpShape *v4; // rsi
  hkQsTransformf *v5; // rbx
  __int64 result; // rax
  hkpShapeHierarchyWalker::WalkResult v7; // eax
  hkpShape *v8; // rax
  hkQsTransformf *v9; // r8
  hkpShape *v10; // rcx
  __int64 v11; // rbx
  unsigned int v12; // edi
  hkpShape *v13; // rax
  hkpShapeHierarchyWalker::WalkResult v14; // eax
  unsigned int v15; // ebx
  int v16; // edi
  __m128 *v17; // rcx
  hkQuaternionf v18; // xmm4
  __m128 v19; // xmm7
  __m128 v20; // xmm5
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  __m128 v23; // xmm6
  __m128 v24; // xmm2
  __m128 v25; // xmm2
  hkpShapeHierarchyWalker::WalkResult v26; // eax
  hkQsTransformf childTransform; // [rsp+20h] [rbp-2A8h]
  hkpSphereShape v28; // [rsp+50h] [rbp-278h]
  char v29; // [rsp+90h] [rbp-238h]
  signed __int64 v30; // [rsp+2D8h] [rbp+10h]
  hkQsTransformf *transforma; // [rsp+2E0h] [rbp+18h]

  transforma = transform;
  v3 = callback;
  v4 = shape;
  v5 = transform;
  result = ((__int64 (__fastcall *)(hkpShapeHierarchyWalker *, hkpShape *))callback->vfptr->preShapeCallback)(
             callback,
             shape);
  if ( (_DWORD)result != 1 )
  {
    if ( (_DWORD)result == 2 )
    {
      result = 0i64;
    }
    else
    {
      switch ( v4->m_type.m_storage )
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
          v11 = ((__int64 (__fastcall *)(hkpShape *))v4->vfptr[7].__vecDelDtor)(v4);
          v12 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 16i64))(v11);
          if ( v12 == -1 )
            goto LABEL_13;
          while ( 1 )
          {
            v13 = (hkpShape *)(*(__int64 (__fastcall **)(__int64, _QWORD, char *))(*(_QWORD *)v11 + 40i64))(
                                v11,
                                v12,
                                &v29);
            if ( v13 )
            {
              v14 = hkpTraverseShapeHierarchy(v13, v3, transforma);
              if ( v14 == 1 )
                return 1i64;
              if ( v14 == 2 )
                return 0i64;
            }
            v12 = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v11 + 24i64))(v11, v12);
            if ( v12 == -1 )
              goto LABEL_13;
          }
        case 0xA:
        case 0xB:
        case 0xE:
          v8 = hkpTraverseShapeHierarchy_transform(v4, v5, &childTransform);
          if ( !v8 )
            goto LABEL_14;
          v9 = &childTransform;
          v10 = v8;
          goto LABEL_17;
        case 0x19:
          v15 = 0;
          v16 = 0;
          if ( SLODWORD(v4[1].vfptr) <= 0 )
            goto LABEL_13;
          v17 = (__m128 *)&v4[1].m_type;
          v30 = (signed __int64)&v4[1].m_type;
          break;
        case 0x1E:
          v10 = *(hkpShape **)&v4[1].m_type.m_storage;
          v9 = v5;
LABEL_17:
          v7 = hkpTraverseShapeHierarchy(v10, v3, v9);
          goto LABEL_18;
        default:
          v7 = (unsigned int)v3->vfptr->leafShapeCallback(v3, v4, v5);
LABEL_18:
          if ( v7 == 1 )
            return 1i64;
          if ( v7 != 2 )
            goto LABEL_14;
          return 0i64;
      }
      do
      {
        v18.m_vec.m_quad = (__m128)transforma->m_rotation;
        v19 = transforma->m_translation.m_quad;
        v20 = _mm_mul_ps(*v17, transforma->m_scale.m_quad);
        childTransform.m_scale = transforma->m_scale;
        childTransform.m_rotation = (hkQuaternionf)v18.m_vec.m_quad;
        v21 = _mm_mul_ps(v18.m_vec.m_quad, v20);
        v22 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 201), v18.m_vec.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v18.m_vec.m_quad, v18.m_vec.m_quad, 201), v20));
        v23 = _mm_shuffle_ps(v18.m_vec.m_quad, v18.m_vec.m_quad, 255);
        v24 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
                    _mm_shuffle_ps(v21, v21, 170)),
                  v18.m_vec.m_quad),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v23, v23), (__m128)xmmword_141A711B0), v20));
        v21.m128_i32[0] = HIDWORD(v17->m128_u64[1]);
        v25 = _mm_add_ps(v24, _mm_mul_ps(_mm_shuffle_ps(v22, v22, 201), v23));
        childTransform.m_translation.m_quad = _mm_add_ps(v19, _mm_add_ps(v25, v25));
        hkpSphereShape::hkpSphereShape(&v28, v21.m128_f32[0]);
        v26 = (unsigned int)v3->vfptr->leafShapeCallback(v3, (hkpShape *)&v28.vfptr, &childTransform);
        if ( v26 == 1 )
          return 1;
        if ( v26 == 2 )
          return v15;
        ++v16;
        v17 = (__m128 *)(v30 + 16);
        v30 += 16i64;
      }
      while ( v16 < SLODWORD(v4[1].vfptr) );
LABEL_13:
      v5 = transforma;
LABEL_14:
      result = v3->vfptr->postShapeCallback(v3, v4, v5);
    }
  }
  return result;
}

// File Line: 246
// RVA: 0xC31EB0
__int64 __fastcall hkaiSilhouetteHierarchyWalker::leafShapeCallback(hkaiSilhouetteHierarchyWalker *this, hkpShape *shape, hkQsTransformf *transform)
{
  hkaiSilhouetteHierarchyWalker *v3; // rdi
  hkQsTransformf *v4; // rbp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v5; // rbx
  int v6; // esi
  __int64 v7; // r14
  int v8; // er9
  int v9; // eax
  int v10; // eax
  __m128 v11; // xmm5
  __m128 v12; // xmm9
  __m128 v13; // xmm10
  __int64 v14; // r8
  __m128 v15; // xmm6
  __m128 v16; // xmm7
  __m128 *v17; // r9
  hkVector4f *v18; // rdx
  __m128 v19; // xmm8
  __m128 v20; // xmm3
  __m128 v21; // xmm3
  __m128 v22; // xmm1
  __m128 v23; // xmm4
  __m128 v24; // xmm2
  hkArray<int,hkContainerHeapAllocator> *v25; // rbx
  int v26; // esi
  __m128 *v27; // rsi
  signed __int64 v28; // r14
  hkArray<hkVector4f,hkContainerHeapAllocator> *v29; // rbx
  __m128 v30; // xmm6
  __m128 *v31; // rcx
  __m128 v32; // xmm2
  __m128 v33; // xmm5
  __m128 v34; // xmm6
  __m128 v35; // xmm1
  __m128 v36; // xmm4
  __m128 v37; // xmm3
  hkArray<int,hkContainerHeapAllocator> *v38; // rbx
  hkArray<hkVector4f,hkContainerTempAllocator> vertsOut; // [rsp+30h] [rbp-88h]
  __m128 v41; // [rsp+40h] [rbp-78h]
  hkResult result; // [rsp+C8h] [rbp+10h]

  v3 = this;
  v4 = transform;
  if ( shape->m_type.m_storage > 5u )
  {
    ((void (__fastcall *)(hkpShape *, hkVector4f *, hkQsTransformf *, hkArray<hkVector4f,hkContainerTempAllocator> *))shape->vfptr[2].__vecDelDtor)(
      shape,
      &::transform,
      transform,
      &vertsOut);
    v27 = (__m128 *)hkVector4fComparison_maskToComparison_254;
    v28 = 8i64;
    do
    {
      v29 = v3->m_vertices;
      v30 = _mm_or_ps(_mm_andnot_ps(*v27, (__m128)vertsOut), _mm_and_ps(v41, *v27));
      if ( v29->m_size == (v29->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3->m_vertices, 16);
      ++v27;
      v31 = &v29->m_data[v29->m_size++].m_quad;
      v32 = v4->m_rotation.m_vec.m_quad;
      v33 = _mm_mul_ps(v4->m_scale.m_quad, v30);
      v34 = _mm_shuffle_ps(v4->m_rotation.m_vec.m_quad, v32, 255);
      v35 = _mm_mul_ps(v33, v32);
      v36 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v33, v33, 201), v32), _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v33));
      v37 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v35, v35, 0), _mm_shuffle_ps(v35, v35, 85)),
                    _mm_shuffle_ps(v35, v35, 170)),
                  v32),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v34, v34), (__m128)xmmword_141A711B0), v33)),
              _mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), v34));
      *v31 = _mm_add_ps(_mm_add_ps(v37, v37), v4->m_translation.m_quad);
      --v28;
    }
    while ( v28 );
    v38 = v3->m_sizes;
    if ( v38->m_size == (v38->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3->m_sizes, 4);
    v38->m_data[v38->m_size++] = 8;
  }
  else
  {
    vertsOut.m_data = 0i64;
    vertsOut.m_size = 0;
    vertsOut.m_capacityAndFlags = 2147483648;
    hkaiPhysics2012SilhouetteBuilder::getVertices(shape, &vertsOut);
    v5 = v3->m_vertices;
    v6 = vertsOut.m_size;
    v7 = v5->m_size;
    v8 = v7 + vertsOut.m_size;
    v9 = v5->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v9 < (signed int)v7 + vertsOut.m_size )
    {
      v10 = 2 * v9;
      if ( v8 < v10 )
        v8 = v10;
      hkArrayUtil::_reserve(
        &result,
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        v3->m_vertices,
        v8,
        16);
    }
    v5->m_size += v6;
    v11 = v4->m_rotation.m_vec.m_quad;
    v12 = v4->m_translation.m_quad;
    v13 = v4->m_scale.m_quad;
    v14 = vertsOut.m_size - 1;
    v15 = _mm_shuffle_ps(v11, v11, 255);
    v16 = _mm_shuffle_ps(v4->m_rotation.m_vec.m_quad, v11, 201);
    v17 = &v5->m_data[v7 + v14].m_quad;
    v18 = &vertsOut.m_data[v14];
    v19 = _mm_mul_ps(v15, v15);
    do
    {
      v20 = v18->m_quad;
      --v17;
      --v18;
      --v14;
      v21 = _mm_mul_ps(v20, v13);
      v22 = _mm_mul_ps(v11, v21);
      v23 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v21, v21, 201), v11), _mm_mul_ps(v21, v16));
      v24 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v22, v22, 85), _mm_shuffle_ps(v22, v22, 0)),
                    _mm_shuffle_ps(v22, v22, 170)),
                  v11),
                _mm_mul_ps(_mm_sub_ps(v19, (__m128)xmmword_141A711B0), v21)),
              _mm_mul_ps(_mm_shuffle_ps(v23, v23, 201), v15));
      v17[1] = _mm_add_ps(_mm_add_ps(v24, v24), v12);
    }
    while ( v14 >= 0 );
    v25 = v3->m_sizes;
    v26 = vertsOut.m_size;
    if ( v25->m_size == (v25->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3->m_sizes, 4);
    v25->m_data[v25->m_size++] = v26;
    vertsOut.m_size = 0;
    if ( vertsOut.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        vertsOut.m_data,
        16 * vertsOut.m_capacityAndFlags);
  }
  return 0i64;
}

// File Line: 292
// RVA: 0xC30FF0
void __fastcall hkaiPhysics2012SilhouetteBuilder::createPointCloudFromShapeRecursive(hkpShape *shape, hkQsTransformf *transform, hkArray<hkVector4f,hkContainerHeapAllocator> *verticesOut, hkArray<int,hkContainerHeapAllocator> *sizesOut)
{
  hkpShapeHierarchyWalker callback; // [rsp+20h] [rbp-28h]
  hkArray<hkVector4f,hkContainerHeapAllocator> *v5; // [rsp+28h] [rbp-20h]
  hkArray<int,hkContainerHeapAllocator> *v6; // [rsp+30h] [rbp-18h]

  v5 = verticesOut;
  v6 = sizesOut;
  callback.vfptr = (hkpShapeHierarchyWalkerVtbl *)&hkaiSilhouetteHierarchyWalker::`vftable;
  hkpTraverseShapeHierarchy(shape, &callback, transform);
}

// File Line: 298
// RVA: 0xC31550
void __fastcall case_sphere(hkVector4f *p, hkSimdFloat32 *radius, hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  hkaiPhysicsBodySilhouetteGeneratorBase::getPointsForSphere(p, radius, vertsOut);
}

// File Line: 303
// RVA: 0xC31560
void __fastcall case_cylinder(hkVector4f *p0, hkVector4f *p1, hkSimdFloat32 *radius, hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  hkArray<hkVector4f,hkContainerTempAllocator> *v4; // rbx
  hkSimdFloat32 *v5; // rsi
  hkVector4f *v6; // rbp
  hkVector4f *v7; // rdi
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
  __m128i v25; // xmm6
  __m128 v26; // xmm10
  __m128i v27; // xmm9
  __m128 v28; // xmm2
  __m128i v29; // xmm6
  __m128 v30; // xmm5
  __m128 v31; // xmm4
  __m128 v32; // xmm6
  __m128 v33; // xmm4
  __m128 v34; // xmm2
  float v35; // xmm3_4
  __m128 v36; // xmm9
  __m128 v37; // xmm8
  signed __int64 v38; // rsi
  __m128 v39; // xmm1
  __m128 v40; // xmm3
  __m128 v41; // xmm2
  __m128 v42; // xmm7
  __m128 v43; // xmm7
  __m128 v44; // xmm7
  __m128 *v45; // rcx
  __m128 *v46; // rcx
  __m128 v47; // xmm5
  __m128 v48; // xmm6
  __m128 v49; // xmm3
  __m128 v50; // xmm4
  __m128 v51; // xmm6
  hkQuaternionf v52; // [rsp+20h] [rbp-98h]
  hkVector4f axis; // [rsp+30h] [rbp-88h]
  hkQuaternionf v54; // [rsp+40h] [rbp-78h]

  v4 = vertsOut;
  v5 = radius;
  v6 = p1;
  v7 = p0;
  v8 = _mm_sub_ps(p1->m_quad, p0->m_quad);
  v9 = _mm_mul_ps(v8, v8);
  v10 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v9, v9, 85), _mm_shuffle_ps(v9, v9, 0)), _mm_shuffle_ps(v9, v9, 170));
  v11 = _mm_rsqrt_ps(v10);
  v12 = _mm_mul_ps(
          v8,
          _mm_andnot_ps(
            _mm_cmpleps(v10, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v11, v10), v11)),
              _mm_mul_ps(*(__m128 *)_xmm, v11))));
  axis.m_quad = v12;
  v13 = _mm_mul_ps(v12, v12);
  if ( (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 0)))
             + COERCE_FLOAT(_mm_shuffle_ps(v13, v13, 170))) >= 0.5 )
  {
    v14 = _mm_shuffle_ps(v12, _mm_unpackhi_ps(v12, (__m128)0i64), 196);
    v15 = _mm_shuffle_ps(v14, v14, 241);
    v16 = _mm_shuffle_ps(v14, v14, 206);
    v17 = _mm_mul_ps(v16, v16);
    v18 = _mm_mul_ps(v15, v15);
    v19 = _mm_cmpltps(
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
              _mm_cmpleps(v22, (__m128)0i64),
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v23, v22), v23)),
                _mm_mul_ps(*(__m128 *)_xmm, v23))));
    hkQuaternionf::setAxisAngle(&v54, &axis, 0.69813174);
    hkQuaternionf::setAxisAngle(&v52, &axis, 0.0);
    v25 = _mm_load_si128((const __m128i *)_xmm);
    v26 = _mm_add_ps((__m128)LODWORD(FLOAT_0_34906587), *(__m128 *)_xmm);
    v27 = _mm_add_epi32(v25, v25);
    v28 = _mm_andnot_ps(*(__m128 *)_xmm, v26);
    v29 = _mm_andnot_si128(v25, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v28, *(__m128 *)_xmm)), v25));
    v30 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v29, v27), (__m128i)0i64);
    v31 = _mm_cvtepi32_ps(v29);
    v27.m128i_i32[0] = (unsigned __int128)_mm_and_si128(_mm_add_epi32(v27, v27), v29);
    v32 = v52.m_vec.m_quad;
    v33 = _mm_add_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(v31, *(__m128 *)DP1_0), v28), _mm_mul_ps(v31, *(__m128 *)DP2)),
            _mm_mul_ps(v31, *(__m128 *)DP3));
    v34 = _mm_mul_ps(v33, v33);
    LODWORD(v35) = (*(unsigned __int128 *)&_mm_andnot_ps(
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
                                               *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                                     (float)((float)((float)((float)((float)((float)(v34.m128_f32[0] * -0.00019515296) + 0.0083321612) * v34.m128_f32[0])
                                                                                           + -0.16666655)
                                                                                   * v34.m128_f32[0])
                                                                           * v33.m128_f32[0])
                                                                   + v33.m128_f32[0]) & v30.m128_i32[0]) ^ (v27.m128i_i32[0] << 29) ^ v26.m128_i32[0] & _xmm[0];
    v36 = _mm_shuffle_ps(v24, v24, 201);
    v37 = _mm_mul_ps(
            _mm_shuffle_ps((__m128)COERCE_UNSIGNED_INT(1.0 / v35), (__m128)COERCE_UNSIGNED_INT(1.0 / v35), 0),
            v5->m_real);
    v38 = 9i64;
    do
    {
      v39 = _mm_mul_ps(v32, v24);
      v40 = _mm_shuffle_ps(v32, v32, 255);
      v41 = _mm_sub_ps(_mm_mul_ps(v32, v36), _mm_mul_ps(_mm_shuffle_ps(v32, v32, 201), v24));
      v42 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v39, v39, 85), _mm_shuffle_ps(v39, v39, 0)),
                    _mm_shuffle_ps(v39, v39, 170)),
                  v32),
                _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v40, v40), (__m128)xmmword_141A711B0), v24)),
              _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v40));
      v43 = _mm_add_ps(v42, v42);
      if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, 16);
      v44 = _mm_mul_ps(v43, v37);
      v45 = &v4->m_data[v4->m_size++].m_quad;
      *v45 = _mm_add_ps(v7->m_quad, v44);
      if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, 16);
      v46 = &v4->m_data[v4->m_size++].m_quad;
      *v46 = _mm_add_ps(v44, v6->m_quad);
      v47 = _mm_shuffle_ps(v54.m_vec.m_quad, v54.m_vec.m_quad, 255);
      v48 = _mm_sub_ps(
              _mm_mul_ps(_mm_shuffle_ps(v54.m_vec.m_quad, v54.m_vec.m_quad, 201), v52.m_vec.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v52.m_vec.m_quad, v52.m_vec.m_quad, 201), v54.m_vec.m_quad));
      v49 = _mm_mul_ps(v54.m_vec.m_quad, v52.m_vec.m_quad);
      v50 = _mm_shuffle_ps(v52.m_vec.m_quad, v52.m_vec.m_quad, 255);
      v51 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v48, v48, 201), _mm_mul_ps(v54.m_vec.m_quad, v50)),
              _mm_mul_ps(v52.m_vec.m_quad, v47));
      v32 = _mm_shuffle_ps(
              v51,
              _mm_unpackhi_ps(
                v51,
                _mm_sub_ps(
                  _mm_mul_ps(v47, v50),
                  _mm_add_ps(
                    _mm_add_ps(_mm_shuffle_ps(v49, v49, 85), _mm_shuffle_ps(v49, v49, 0)),
                    _mm_shuffle_ps(v49, v49, 170)))),
              196);
      v52.m_vec.m_quad = v32;
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
void __fastcall case_capsule(hkVector4f *p0, hkVector4f *p1, hkSimdFloat32 *radius, hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  hkaiPhysicsBodySilhouetteGeneratorBase::getPointsForCapsule(p0, p1, radius, vertsOut);
}

// File Line: 349
// RVA: 0xC31A40
void __fastcall case_triangle(hkVector4f *p, hkSimdFloat32 *radius, hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  int v3; // eax
  hkArray<hkVector4f,hkContainerTempAllocator> *v4; // rsi
  hkSimdFloat32 *v5; // rbp
  hkVector4f *v6; // rdi
  signed __int64 v7; // rbx
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm6
  __m128 v11; // xmm6
  __m128 v12; // xmm1
  __m128 v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm6
  int v16; // eax
  int v17; // er9
  __int64 v18; // rcx
  hkResult result; // [rsp+60h] [rbp+8h]

  v3 = vertsOut->m_capacityAndFlags & 0x3FFFFFFF;
  v4 = vertsOut;
  v5 = radius;
  v6 = p;
  v7 = 1i64;
  v8 = _mm_sub_ps(p->m_quad, p[2].m_quad);
  v9 = _mm_sub_ps(p[2].m_quad, p[1].m_quad);
  v10 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), v9), _mm_mul_ps(_mm_shuffle_ps(v9, v9, 201), v8));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_mul_ps(v11, v11);
  v13 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(v12, v12, 0)), _mm_shuffle_ps(v12, v12, 170));
  v14 = _mm_rsqrt_ps(v13);
  v15 = _mm_mul_ps(
          v11,
          _mm_andnot_ps(
            _mm_cmpleps(v13, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v14, v13), v14)),
              _mm_mul_ps(*(__m128 *)_xmm, v14))));
  if ( v3 < 6 )
  {
    v16 = 2 * v3;
    v17 = 6;
    if ( v16 > 6 )
      v17 = v16;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, vertsOut, v17, 16);
  }
  v4->m_size = 6;
  v18 = 0i64;
  do
  {
    v7 += 2i64;
    v18 += 2i64;
    ++v6;
    v4->m_data[v18 - 2].m_quad = _mm_add_ps(_mm_mul_ps(v5->m_real, v15), v6[-1].m_quad);
    v4->m_data[v7 - 2].m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps((__m128)0i64, v5->m_real), v15), v6[-1].m_quad);
  }
  while ( v7 < 7 );
}

// File Line: 364
// RVA: 0xC31030
void __fastcall hkaiPhysics2012SilhouetteBuilder::getVertices(hkpShape *s, hkArray<hkVector4f,hkContainerTempAllocator> *vertsOut)
{
  hkArray<hkVector4f,hkContainerTempAllocator> *v2; // rdi
  hkVector4f *v3; // rbx
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  int v7; // er14
  int v8; // ecx
  int v9; // er9
  hkVector4f *v10; // rdx
  __m128i *v11; // rax
  __m128i v12; // xmm0
  __m128i v13; // xmm1
  hkSimdFloat32 radius; // [rsp+30h] [rbp-19h]
  hkVector4f p; // [rsp+40h] [rbp-9h]
  hkVector4f p0; // [rsp+50h] [rbp+7h]
  hkVector4f v17; // [rsp+60h] [rbp+17h]
  __int128 v18; // [rsp+70h] [rbp+27h]
  __int128 v19; // [rsp+80h] [rbp+37h]
  hkResult result; // [rsp+B0h] [rbp+67h]

  v2 = vertsOut;
  v3 = (hkVector4f *)s;
  switch ( s->m_type.m_storage )
  {
    case 0:
      result.m_enum = (hkResultEnum)s[1].vfptr;
      p.m_quad = 0i64;
      p0.m_quad = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
      case_sphere(&p, (hkSimdFloat32 *)&p0, vertsOut);
      break;
    case 1:
      *(float *)&result.m_enum = hkpCylinderShape::getCylinderRadius((hkpCylinderShape *)s);
      p0.m_quad = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
      case_cylinder(v3 + 3, v3 + 4, (hkSimdFloat32 *)&p0, v2);
      break;
    case 2:
      *(float *)&result.m_enum = *(float *)&s[1].vfptr + 0.0099999998;
      p0.m_quad = _mm_shuffle_ps((__m128)(unsigned int)result.m_enum, (__m128)(unsigned int)result.m_enum, 0);
      case_triangle((hkVector4f *)&s[1].m_type, (hkSimdFloat32 *)&p0, vertsOut);
      break;
    case 3:
    case 5:
      v4 = ((__int64 (__fastcall *)(hkpShape *))s->vfptr[5].__first_virtual_table_function__)(s);
      v5 = (*(__int64 (__fastcall **)(hkVector4f *))(v3->m_quad.m128_u64[0] + 88))(v3);
      v6 = v2->m_capacityAndFlags & 0x3FFFFFFF;
      v7 = v5;
      if ( v6 < v5 )
      {
        v8 = 2 * v6;
        v9 = v5;
        if ( v5 < v8 )
          v9 = v8;
        hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v2, v9, 16);
      }
      v10 = v2->m_data;
      v2->m_size = v7;
      (*(void (__fastcall **)(hkVector4f *, hkVector4f *))(v3->m_quad.m128_u64[0] + 96))(v3, v10);
      if ( (unsigned int)(v4 - 1) <= 2 )
      {
        v11 = (__m128i *)v2->m_data;
        radius.m_real = _mm_shuffle_ps(v2->m_data->m_quad, v2->m_data->m_quad, 255);
        v12 = *v11;
        if ( v4 == 1 )
        {
          _mm_store_si128((__m128i *)&p, v12);
          case_sphere(&p, &radius, v2);
        }
        else if ( v4 == 2 )
        {
          _mm_store_si128((__m128i *)&p0, v12);
          _mm_store_si128((__m128i *)&p, v11[1]);
          case_capsule(&p0, &p, &radius, v2);
        }
        else
        {
          v13 = v11[1];
          _mm_store_si128((__m128i *)&v17, v12);
          _mm_store_si128((__m128i *)&v19, v11[2]);
          _mm_store_si128((__m128i *)&v18, v13);
          case_triangle(&v17, &radius, v2);
        }
      }
      break;
    case 4:
      p0.m_quad = _mm_shuffle_ps(*(__m128 *)&s[1].m_type.m_storage, *(__m128 *)&s[1].m_type.m_storage, 255);
      case_capsule((hkVector4f *)&s[1].m_type, (hkVector4f *)&s[2], (hkSimdFloat32 *)&p0, vertsOut);
      break;
    default:
      return;
  }
}

