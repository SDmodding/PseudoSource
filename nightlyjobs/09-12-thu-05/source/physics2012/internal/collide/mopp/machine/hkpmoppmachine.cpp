// File Line: 285
// RVA: 0xDB2AA0
_BOOL8 __fastcall hkMoppEarlyExitObbVirtualMachine_queryObb(hkpMoppCode *code, hkTransformf *BvToWorld, hkVector4f *extent, const float *radius)
{
  hkBool result; // [rsp+30h] [rbp-78h]
  hkpMoppEarlyExitObbVirtualMachine v6; // [rsp+40h] [rbp-68h]

  return hkpMoppEarlyExitObbVirtualMachine::queryObb(&v6, &result, code, BvToWorld, extent, radius)->m_bool != 0;
}

// File Line: 295
// RVA: 0xDB2AE0
void __fastcall hkMoppFindAllVirtualMachine_getAllKeys(hkpMoppCode *code, hkArray<unsigned int,hkContainerHeapAllocator> *primitives_out)
{
  char *v2; // r8
  hkpMoppFindAllVirtualMachine v3; // [rsp+20h] [rbp-28h]
  hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery query; // [rsp+50h] [rbp+8h]

  v2 = code->m_data.m_data;
  v3.m_primitives_out = (hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *)primitives_out;
  query = 0i64;
  hkpMoppFindAllVirtualMachine::queryOnTree(&v3, &query, v2);
}

// File Line: 301
// RVA: 0xDB2B10
void __fastcall hkMoppObbVirtualMachine_queryObb(hkpMoppCode *code, hkTransformf *BvToWorld, hkVector4f *extent, const float radius, hkArray<unsigned int,hkContainerHeapAllocator> *primitives_out)
{
  hkpMoppObbVirtualMachine v5; // [rsp+30h] [rbp-58h]

  hkpMoppObbVirtualMachine::queryObb(
    &v5,
    code,
    BvToWorld,
    extent,
    radius,
    (hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *)primitives_out);
}

// File Line: 307
// RVA: 0xDB2B50
void __fastcall hkMoppObbVirtualMachine_queryAabb(hkpMoppCode *code, hkAabb *aabb, hkArray<unsigned int,hkContainerHeapAllocator> *primitives_out)
{
  hkpMoppObbVirtualMachine v3; // [rsp+20h] [rbp-58h]

  hkpMoppObbVirtualMachine::queryAabb(
    &v3,
    code,
    aabb,
    (hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *)primitives_out);
}

// File Line: 313
// RVA: 0xDB2B80
void __fastcall hkMoppSphereVirtualMachine_querySphere(hkpMoppCode *code, hkSphere *sphere, hkArray<unsigned int,hkContainerHeapAllocator> *primitives_out)
{
  hkpMoppSphereVirtualMachine v3; // [rsp+20h] [rbp-38h]

  hkpMoppSphereVirtualMachine::querySphere(
    &v3,
    code,
    sphere,
    (hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *)primitives_out);
}

// File Line: 319
// RVA: 0xDB2BB0
void __fastcall hkMoppUsingFloatAabbVirtualMachine_queryPlanes(hkpMoppCode *code, hkpMoppPlanesQueryInput *query, hkArray<unsigned int,hkContainerHeapAllocator> *partialHitsOut, hkArray<unsigned int,hkContainerHeapAllocator> *fullyIncludedHitsOut)
{
  __m128 v4; // xmm0
  char *v5; // rbp
  hkVector4f *v6; // r10
  int v7; // er8
  hkArray<unsigned int,hkContainerHeapAllocator> *v8; // rsi
  int v9; // er9
  hkpMoppCode *v10; // rdi
  hkTransformf *v11; // rcx
  int v12; // ebx
  __m128 *v13; // rdx
  unsigned int v14; // eax
  __int64 v15; // r11
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm5
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 *v24; // rdx
  __m128 *v25; // r11
  int v26; // er9
  int v27; // er9
  __m128 v28; // xmm5
  __m128 v29; // xmm4
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  unsigned __int64 v32; // rcx
  __m128i *i; // rdx
  __m128i v34; // xmm0
  __m128i v35; // xmm0
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObject>::hkpMoppUsingFloatAabbVirtualMachineQueryInt querya; // [rsp+20h] [rbp-498h]
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObject>::hkpMoppTempAabb fQueryL; // [rsp+40h] [rbp-478h]
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObject> v40; // [rsp+60h] [rbp-458h]

  v4 = (__m128)(unsigned int)FLOAT_1_0;
  v5 = code->m_data.m_data;
  v6 = query->m_planes;
  v40.m_primitives_out = (hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *)partialHitsOut;
  v7 = 0;
  v8 = fullyIncludedHitsOut;
  v4.m128_f32[0] = 1.0 / code->m_info.m_offset.m_quad.m128_f32[3];
  fQueryL.m_aabb.m_min = 0i64;
  v9 = query->m_numPlanes;
  v10 = code;
  querya.m_shift = 16;
  *(_QWORD *)&querya.m_offset_x = 0i64;
  querya.m_offset_z = 0;
  LODWORD(v40.m_ItoFScale) = v4.m128_i32[0];
  v4.m128_f32[0] = v4.m128_f32[0] * 16777216.0;
  querya.0 = 0i64;
  v11 = v40.m_queryObject.m_rotatedPlanes;
  v40.m_queryObject.m_numTransforms = 0;
  fQueryL.m_aabb.m_max.m_quad = _mm_shuffle_ps(v4, v4, 0);
  v12 = 0;
  if ( (signed int)(v9 & 0xFFFFFFFC) > 0 )
  {
    v13 = &v6[2].m_quad;
    v14 = (((v9 & 0xFFFFFFFC) - 1) >> 2) + 1;
    v15 = v14;
    v12 = 4 * v14;
    do
    {
      v16 = v6->m_quad;
      v17 = *v13;
      ++v11;
      v6 += 4;
      v13 += 4;
      v18 = v16;
      v19 = v17;
      v20 = _mm_shuffle_ps(v16, v13[-5], 238);
      v21 = _mm_shuffle_ps(v17, v13[-3], 238);
      v22 = _mm_shuffle_ps(v18, v13[-5], 68);
      v23 = _mm_shuffle_ps(v19, v13[-3], 68);
      v11[-1].m_rotation.m_col0.m_quad = _mm_shuffle_ps(v22, v23, 136);
      v11[-1].m_rotation.m_col1.m_quad = _mm_shuffle_ps(v22, v23, 221);
      v11[-1].m_rotation.m_col2.m_quad = _mm_shuffle_ps(v20, v21, 136);
      v11[-1].m_translation.m_quad = _mm_shuffle_ps(v20, v21, 221);
      v7 = v40.m_queryObject.m_numTransforms++ + 1;
      --v15;
    }
    while ( v15 );
  }
  v24 = &v6[1].m_quad;
  v25 = &v6[2].m_quad;
  v26 = v9 - v12 - 1;
  if ( !v26 )
  {
    v24 = &v6->m_quad;
    goto LABEL_9;
  }
  v27 = v26 - 1;
  if ( !v27 )
  {
LABEL_9:
    v25 = &v6->m_quad;
    goto LABEL_10;
  }
  if ( v27 == 1 )
  {
LABEL_10:
    ++v11;
    v28 = _mm_shuffle_ps(v6->m_quad, *v24, 238);
    v29 = _mm_shuffle_ps(*v25, v6->m_quad, 238);
    v30 = _mm_shuffle_ps(v6->m_quad, *v24, 68);
    v31 = _mm_shuffle_ps(*v25, v6->m_quad, 68);
    v11[-1].m_rotation.m_col0.m_quad = _mm_shuffle_ps(v30, v31, 136);
    v11[-1].m_rotation.m_col1.m_quad = _mm_shuffle_ps(v30, v31, 221);
    v11[-1].m_rotation.m_col2.m_quad = _mm_shuffle_ps(v28, v29, 136);
    v11[-1].m_translation.m_quad = _mm_shuffle_ps(v28, v29, 221);
    v7 = v40.m_queryObject.m_numTransforms++ + 1;
  }
  v32 = (unsigned __int64)&v11[-1];
  for ( i = (__m128i *)&v40.m_queryObject.m_rotatedPlanes[(signed __int64)v7 + 7];
        v32 >= (unsigned __int64)v40.m_queryObject.m_rotatedPlanes;
        *(__m128 *)(v32 + 112) = _mm_add_ps(v37, v37) )
  {
    v34 = _mm_load_si128((const __m128i *)v32);
    v32 -= 64i64;
    i -= 4;
    i[4] = _mm_srli_epi32(_mm_slli_epi32(v34, 1u), 1u);
    _mm_store_si128(i + 5, _mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)(v32 + 80)), 1u), 1u));
    v35 = _mm_load_si128((const __m128i *)(v32 + 96));
    i[7] = 0i64;
    _mm_store_si128(i + 6, _mm_srli_epi32(_mm_slli_epi32(v35, 1u), 1u));
    v36 = v10->m_info.m_offset.m_quad;
    v37 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v36, v36, 85), *(__m128 *)(v32 + 80)),
                _mm_mul_ps(_mm_shuffle_ps(v10->m_info.m_offset.m_quad, v36, 0), *(__m128 *)(v32 + 64))),
              _mm_mul_ps(_mm_shuffle_ps(v36, v36, 170), *(__m128 *)(v32 + 96))),
            *(__m128 *)(v32 + 112));
  }
  v40.m_queryObject.m_primitives_out = (hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *)v8;
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObject>::queryMoppTree(
    &v40,
    &querya,
    v5,
    &fQueryL);
}

// File Line: 326
// RVA: 0xDB2E50
void __fastcall hkMoppUsingFloatAabbVirtualMachine_queryPlanesOptimized(hkpMoppCode *code, hkpMoppPlanesQueryInput *query, hkArray<unsigned int,hkContainerHeapAllocator> *partialHitsOut, hkArray<unsigned int,hkContainerHeapAllocator> *fullyIncludedHitsOut)
{
  __m128 v4; // xmm0
  char *v5; // rbp
  hkVector4f *v6; // r10
  int v7; // er8
  hkArray<unsigned int,hkContainerHeapAllocator> *v8; // rsi
  int v9; // er9
  hkpMoppCode *v10; // rdi
  hkTransformf *v11; // rcx
  int v12; // ebx
  __m128 *v13; // rdx
  unsigned int v14; // eax
  __int64 v15; // r11
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm5
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 *v24; // rdx
  __m128 *v25; // r11
  int v26; // er9
  int v27; // er9
  __m128 v28; // xmm5
  __m128 v29; // xmm4
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  unsigned __int64 v32; // rcx
  hkTransformf *i; // rdx
  __m128i v34; // xmm0
  __m128i v35; // xmm0
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt querya; // [rsp+20h] [rbp-498h]
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppTempAabb fQueryL; // [rsp+40h] [rbp-478h]
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized> v40; // [rsp+60h] [rbp-458h]

  v4 = (__m128)(unsigned int)FLOAT_1_0;
  v5 = code->m_data.m_data;
  v6 = query->m_planes;
  v40.m_primitives_out = (hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *)partialHitsOut;
  v7 = 0;
  v8 = fullyIncludedHitsOut;
  v4.m128_f32[0] = 1.0 / code->m_info.m_offset.m_quad.m128_f32[3];
  fQueryL.m_aabb.m_min = 0i64;
  v9 = query->m_numPlanes;
  v10 = code;
  querya.m_shift = 16;
  *(_QWORD *)&querya.m_offset_x = 0i64;
  querya.m_offset_z = 0;
  LODWORD(v40.m_ItoFScale) = v4.m128_i32[0];
  v4.m128_f32[0] = v4.m128_f32[0] * 16777216.0;
  querya.0 = 0i64;
  v11 = v40.m_queryObject.m_rotatedPlanes;
  v40.m_queryObject.m_numTransforms = 0;
  fQueryL.m_aabb.m_max.m_quad = _mm_shuffle_ps(v4, v4, 0);
  v12 = 0;
  if ( (signed int)(v9 & 0xFFFFFFFC) > 0 )
  {
    v13 = &v6[2].m_quad;
    v14 = (((v9 & 0xFFFFFFFC) - 1) >> 2) + 1;
    v15 = v14;
    v12 = 4 * v14;
    do
    {
      v16 = v6->m_quad;
      v17 = *v13;
      ++v11;
      v6 += 4;
      v13 += 4;
      v18 = v16;
      v19 = v17;
      v20 = _mm_shuffle_ps(v16, v13[-5], 238);
      v21 = _mm_shuffle_ps(v17, v13[-3], 238);
      v22 = _mm_shuffle_ps(v18, v13[-5], 68);
      v23 = _mm_shuffle_ps(v19, v13[-3], 68);
      v11[-1].m_rotation.m_col0.m_quad = _mm_shuffle_ps(v22, v23, 136);
      v11[-1].m_rotation.m_col1.m_quad = _mm_shuffle_ps(v22, v23, 221);
      v11[-1].m_rotation.m_col2.m_quad = _mm_shuffle_ps(v20, v21, 136);
      v11[-1].m_translation.m_quad = _mm_shuffle_ps(v20, v21, 221);
      v7 = v40.m_queryObject.m_numTransforms++ + 1;
      --v15;
    }
    while ( v15 );
  }
  v24 = &v6[1].m_quad;
  v25 = &v6[2].m_quad;
  v26 = v9 - v12 - 1;
  if ( !v26 )
  {
    v24 = &v6->m_quad;
    goto LABEL_9;
  }
  v27 = v26 - 1;
  if ( !v27 )
  {
LABEL_9:
    v25 = &v6->m_quad;
    goto LABEL_10;
  }
  if ( v27 == 1 )
  {
LABEL_10:
    ++v11;
    v28 = _mm_shuffle_ps(v6->m_quad, *v24, 238);
    v29 = _mm_shuffle_ps(*v25, v6->m_quad, 238);
    v30 = _mm_shuffle_ps(v6->m_quad, *v24, 68);
    v31 = _mm_shuffle_ps(*v25, v6->m_quad, 68);
    v11[-1].m_rotation.m_col0.m_quad = _mm_shuffle_ps(v30, v31, 136);
    v11[-1].m_rotation.m_col1.m_quad = _mm_shuffle_ps(v30, v31, 221);
    v11[-1].m_rotation.m_col2.m_quad = _mm_shuffle_ps(v28, v29, 136);
    v11[-1].m_translation.m_quad = _mm_shuffle_ps(v28, v29, 221);
    v7 = v40.m_queryObject.m_numTransforms++ + 1;
  }
  v32 = (unsigned __int64)&v11[-1];
  for ( i = &v40.m_queryObject.m_rotatedPlanes[(signed __int64)v7 + 7];
        v32 >= (unsigned __int64)v40.m_queryObject.m_rotatedPlanes;
        *(__m128 *)(v32 + 112) = _mm_add_ps(v37, v37) )
  {
    v34 = _mm_load_si128((const __m128i *)v32);
    v32 -= 64i64;
    --i;
    i[1].m_rotation.m_col0 = (hkVector4f)_mm_srli_epi32(_mm_slli_epi32(v34, 1u), 1u);
    _mm_store_si128(
      (__m128i *)&i[1].m_rotation.m_col1,
      _mm_srli_epi32(_mm_slli_epi32(_mm_load_si128((const __m128i *)(v32 + 80)), 1u), 1u));
    v35 = _mm_load_si128((const __m128i *)(v32 + 96));
    i[1].m_translation = 0i64;
    _mm_store_si128((__m128i *)&i[1].m_rotation.m_col2, _mm_srli_epi32(_mm_slli_epi32(v35, 1u), 1u));
    v36 = v10->m_info.m_offset.m_quad;
    v37 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v36, v36, 85), *(__m128 *)(v32 + 80)),
                _mm_mul_ps(_mm_shuffle_ps(v10->m_info.m_offset.m_quad, v36, 0), *(__m128 *)(v32 + 64))),
              _mm_mul_ps(_mm_shuffle_ps(v36, v36, 170), *(__m128 *)(v32 + 96))),
            *(__m128 *)(v32 + 112));
  }
  v40.m_queryObject.m_primitives_out = (hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *)v8;
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::queryMoppTree(
    &v40,
    &querya,
    v5,
    &fQueryL);
}

// File Line: 333
// RVA: 0xDB30F0
void __fastcall hkMoppUsingFloatAabbVirtualMachine_querySphere(hkpMoppCode *code, hkSphere *query, hkArray<unsigned int,hkContainerHeapAllocator> *partialHitsOut, hkArray<unsigned int,hkContainerHeapAllocator> *fullyIncludedHitsOut)
{
  __m128 v4; // xmm1
  char *v5; // r8
  __m128 v6; // xmm0
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm2
  hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObject>::hkpMoppUsingFloatAabbVirtualMachineQueryInt querya; // [rsp+20h] [rbp-98h]
  __int128 v12; // [rsp+40h] [rbp-78h]
  __m128 v13; // [rsp+50h] [rbp-68h]
  hkArray<unsigned int,hkContainerHeapAllocator> *v14; // [rsp+60h] [rbp-58h]
  int v15; // [rsp+78h] [rbp-40h]
  hkArray<unsigned int,hkContainerHeapAllocator> *v16; // [rsp+80h] [rbp-38h]
  __m128 v17; // [rsp+A0h] [rbp-18h]

  v4 = (__m128)(unsigned int)FLOAT_1_0;
  v14 = partialHitsOut;
  v4.m128_f32[0] = 1.0 / code->m_info.m_offset.m_quad.m128_f32[3];
  v5 = code->m_data.m_data;
  *(_QWORD *)&querya.m_offset_x = 0i64;
  querya.m_offset_z = 0;
  querya.m_shift = 16;
  v12 = 0i64;
  querya.0 = 0i64;
  v15 = v4.m128_i32[0];
  v4.m128_f32[0] = v4.m128_f32[0] * 16777216.0;
  v16 = fullyIncludedHitsOut;
  v6 = v4;
  v7 = query->m_pos.m_quad;
  v8 = query->m_pos.m_quad;
  v13 = _mm_shuffle_ps(v6, v6, 0);
  v9 = _mm_sub_ps(v8, code->m_info.m_offset.m_quad);
  v10 = _mm_add_ps(v9, v9);
  v17 = _mm_shuffle_ps(
          v10,
          _mm_unpackhi_ps(v10, _mm_mul_ps(_mm_shuffle_ps(v7, v7, 255), (__m128)xmmword_141A710D0)),
          196);
  hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObject>::queryMoppTree(
    (hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObject> *)&v14,
    &querya,
    v5,
    (hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObject>::hkpMoppTempAabb *)&v12);
}

// File Line: 340
// RVA: 0xDB31A0
void __fastcall hkMoppUsingFloatAabbVirtualMachine_querySphereOptimized(hkpMoppCode *code, hkSphere *query, hkArray<unsigned int,hkContainerHeapAllocator> *partialHitsOut, hkArray<unsigned int,hkContainerHeapAllocator> *fullyIncludedHitsOut)
{
  __m128 v4; // xmm1
  char *v5; // r8
  __m128 v6; // xmm0
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm2
  hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt querya; // [rsp+20h] [rbp-98h]
  __int128 v12; // [rsp+40h] [rbp-78h]
  __m128 v13; // [rsp+50h] [rbp-68h]
  hkArray<unsigned int,hkContainerHeapAllocator> *v14; // [rsp+60h] [rbp-58h]
  int v15; // [rsp+78h] [rbp-40h]
  hkArray<unsigned int,hkContainerHeapAllocator> *v16; // [rsp+80h] [rbp-38h]
  __m128 v17; // [rsp+A0h] [rbp-18h]

  v4 = (__m128)(unsigned int)FLOAT_1_0;
  v14 = partialHitsOut;
  v4.m128_f32[0] = 1.0 / code->m_info.m_offset.m_quad.m128_f32[3];
  v5 = code->m_data.m_data;
  *(_QWORD *)&querya.m_offset_x = 0i64;
  querya.m_offset_z = 0;
  querya.m_shift = 16;
  v12 = 0i64;
  querya.0 = 0i64;
  v15 = v4.m128_i32[0];
  v4.m128_f32[0] = v4.m128_f32[0] * 16777216.0;
  v16 = fullyIncludedHitsOut;
  v6 = v4;
  v7 = query->m_pos.m_quad;
  v8 = query->m_pos.m_quad;
  v13 = _mm_shuffle_ps(v6, v6, 0);
  v9 = _mm_sub_ps(v8, code->m_info.m_offset.m_quad);
  v10 = _mm_add_ps(v9, v9);
  v17 = _mm_shuffle_ps(
          v10,
          _mm_unpackhi_ps(v10, _mm_mul_ps(_mm_shuffle_ps(v7, v7, 255), (__m128)xmmword_141A710D0)),
          196);
  hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObjectOptimized>::queryMoppTree(
    (hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObjectOptimized> *)&v14,
    &querya,
    v5,
    (hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObjectOptimized>::hkpMoppTempAabb *)&v12);
}

// File Line: 347
// RVA: 0xDB3250
void __fastcall hkMoppModifyVirtualMachine_queryAabb(hkpMoppCode *code, hkAabb *aabb, hkpMoppModifier *modifierOut)
{
  hkpMoppModifyVirtualMachine v3; // [rsp+20h] [rbp-78h]

  hkpMoppModifyVirtualMachine::queryAabb(&v3, code, aabb, modifierOut);
}

// File Line: 353
// RVA: 0xDB3280
void __fastcall hkMoppKDopGeometriesVirtualMachine_query(hkpMoppCode *code, hkpMoppKDopQuery *query, hkpMoppInfo *kDopGeometries)
{
  hkpMoppCode *v3; // rsi
  hkpMoppInfo *v4; // rbx
  hkpMoppKDopQuery *v5; // rdi
  hkpMoppKDopGeometriesVirtualMachine v6; // [rsp+20h] [rbp-D8h]

  v3 = code;
  v4 = kDopGeometries;
  v5 = query;
  hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachine(&v6);
  hkpMoppKDopGeometriesVirtualMachine::queryMopp(&v6, v3, v5, v4);
  hkpMoppKDopGeometriesVirtualMachine::~hkpMoppKDopGeometriesVirtualMachine(&v6);
}

