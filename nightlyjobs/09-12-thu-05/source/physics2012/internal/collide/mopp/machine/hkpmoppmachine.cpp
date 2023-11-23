// File Line: 285
// RVA: 0xDB2AA0
_BOOL8 __fastcall hkMoppEarlyExitObbVirtualMachine_queryObb(
        hkpMoppCode *code,
        hkTransformf *BvToWorld,
        hkVector4f *extent,
        const float *radius)
{
  hkBool result; // [rsp+30h] [rbp-78h] BYREF
  hkpMoppEarlyExitObbVirtualMachine v6; // [rsp+40h] [rbp-68h] BYREF

  return hkpMoppEarlyExitObbVirtualMachine::queryObb(&v6, &result, code, BvToWorld, extent, radius)->m_bool != 0;
}

// File Line: 295
// RVA: 0xDB2AE0
void __fastcall hkMoppFindAllVirtualMachine_getAllKeys(
        hkpMoppCode *code,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *primitives_out)
{
  char *m_data; // r8
  hkpMoppFindAllVirtualMachine v3; // [rsp+20h] [rbp-28h] BYREF
  hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery query; // [rsp+50h] [rbp+8h] BYREF

  m_data = code->m_data.m_data;
  v3.m_primitives_out = primitives_out;
  query = 0i64;
  hkpMoppFindAllVirtualMachine::queryOnTree(&v3, &query, m_data);
}

// File Line: 301
// RVA: 0xDB2B10
void __fastcall hkMoppObbVirtualMachine_queryObb(
        hkpMoppCode *code,
        hkTransformf *BvToWorld,
        hkVector4f *extent,
        const float radius,
        hkArray<unsigned int,hkContainerHeapAllocator> *primitives_out)
{
  hkpMoppObbVirtualMachine v5; // [rsp+30h] [rbp-58h] BYREF

  hkpMoppObbVirtualMachine::queryObb(
    &v5,
    code,
    BvToWorld,
    extent,
    LODWORD(radius),
    (hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *)primitives_out);
}

// File Line: 307
// RVA: 0xDB2B50
void __fastcall hkMoppObbVirtualMachine_queryAabb(
        hkpMoppCode *code,
        hkAabb *aabb,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *primitives_out)
{
  hkpMoppObbVirtualMachine v3; // [rsp+20h] [rbp-58h] BYREF

  hkpMoppObbVirtualMachine::queryAabb(&v3, code, aabb, primitives_out);
}

// File Line: 313
// RVA: 0xDB2B80
void __fastcall hkMoppSphereVirtualMachine_querySphere(
        hkpMoppCode *code,
        hkSphere *sphere,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *primitives_out)
{
  hkpMoppSphereVirtualMachine v3; // [rsp+20h] [rbp-38h] BYREF

  hkpMoppSphereVirtualMachine::querySphere(&v3, code, sphere, primitives_out);
}

// File Line: 319
// RVA: 0xDB2BB0
void __fastcall hkMoppUsingFloatAabbVirtualMachine_queryPlanes(
        hkpMoppCode *code,
        hkpMoppPlanesQueryInput *query,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *partialHitsOut,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *fullyIncludedHitsOut)
{
  __m128 v4; // xmm0
  char *m_data; // rbp
  hkVector4f *m_planes; // r10
  int v7; // r8d
  int m_numPlanes; // r9d
  hkTransformf *m_rotatedPlanes; // rcx
  int v12; // ebx
  __m128 *p_m_quad; // rdx
  unsigned int v14; // eax
  __int64 v15; // r11
  __m128 m_quad; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm5
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 *v24; // rdx
  __m128 *v25; // r11
  int v26; // r9d
  int v27; // r9d
  __m128 v28; // xmm5
  __m128 v29; // xmm4
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  unsigned __int64 v32; // rcx
  hkTransformf *i; // rdx
  __m128i si128; // xmm0
  __m128i v35; // xmm0
  hkpMoppCode::CodeInfo v36; // xmm1
  __m128 v37; // xmm2
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObject>::hkpMoppUsingFloatAabbVirtualMachineQueryInt querya; // [rsp+20h] [rbp-498h] BYREF
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObject>::hkpMoppTempAabb fQueryL; // [rsp+40h] [rbp-478h] BYREF
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObject> v40; // [rsp+60h] [rbp-458h] BYREF

  v4 = (__m128)(unsigned int)FLOAT_1_0;
  m_data = code->m_data.m_data;
  m_planes = query->m_planes;
  v40.m_primitives_out = partialHitsOut;
  v7 = 0;
  v4.m128_f32[0] = 1.0 / code->m_info.m_offset.m_quad.m128_f32[3];
  fQueryL.m_aabb.m_min = 0i64;
  m_numPlanes = query->m_numPlanes;
  querya.m_shift = 16;
  LODWORD(v40.m_ItoFScale) = v4.m128_i32[0];
  v4.m128_f32[0] = v4.m128_f32[0] * 16777216.0;
  memset(&querya, 0, 20);
  m_rotatedPlanes = v40.m_queryObject.m_rotatedPlanes;
  v40.m_queryObject.m_numTransforms = 0;
  fQueryL.m_aabb.m_max.m_quad = _mm_shuffle_ps(v4, v4, 0);
  v12 = 0;
  if ( m_numPlanes >= 0 && (m_numPlanes & 0xFFFFFFFC) != 0 )
  {
    p_m_quad = &m_planes[2].m_quad;
    v14 = (((m_numPlanes & 0xFFFFFFFC) - 1) >> 2) + 1;
    v15 = v14;
    v12 = 4 * v14;
    do
    {
      m_quad = m_planes->m_quad;
      v17 = *p_m_quad;
      ++m_rotatedPlanes;
      m_planes += 4;
      p_m_quad += 4;
      v18 = m_quad;
      v19 = v17;
      v20 = _mm_shuffle_ps(m_quad, p_m_quad[-5], 238);
      v21 = _mm_shuffle_ps(v17, p_m_quad[-3], 238);
      v22 = _mm_shuffle_ps(v18, p_m_quad[-5], 68);
      v23 = _mm_shuffle_ps(v19, p_m_quad[-3], 68);
      m_rotatedPlanes[-1].m_rotation.m_col0.m_quad = _mm_shuffle_ps(v22, v23, 136);
      m_rotatedPlanes[-1].m_rotation.m_col1.m_quad = _mm_shuffle_ps(v22, v23, 221);
      m_rotatedPlanes[-1].m_rotation.m_col2.m_quad = _mm_shuffle_ps(v20, v21, 136);
      m_rotatedPlanes[-1].m_translation.m_quad = _mm_shuffle_ps(v20, v21, 221);
      v7 = ++v40.m_queryObject.m_numTransforms;
      --v15;
    }
    while ( v15 );
  }
  v24 = &m_planes[1].m_quad;
  v25 = &m_planes[2].m_quad;
  v26 = m_numPlanes - v12 - 1;
  if ( !v26 )
  {
    v24 = &m_planes->m_quad;
    goto LABEL_9;
  }
  v27 = v26 - 1;
  if ( !v27 )
  {
LABEL_9:
    v25 = &m_planes->m_quad;
    goto LABEL_10;
  }
  if ( v27 == 1 )
  {
LABEL_10:
    ++m_rotatedPlanes;
    v28 = _mm_shuffle_ps(m_planes->m_quad, *v24, 238);
    v29 = _mm_shuffle_ps(*v25, m_planes->m_quad, 238);
    v30 = _mm_shuffle_ps(m_planes->m_quad, *v24, 68);
    v31 = _mm_shuffle_ps(*v25, m_planes->m_quad, 68);
    m_rotatedPlanes[-1].m_rotation.m_col0.m_quad = _mm_shuffle_ps(v30, v31, 136);
    m_rotatedPlanes[-1].m_rotation.m_col1.m_quad = _mm_shuffle_ps(v30, v31, 221);
    m_rotatedPlanes[-1].m_rotation.m_col2.m_quad = _mm_shuffle_ps(v28, v29, 136);
    m_rotatedPlanes[-1].m_translation.m_quad = _mm_shuffle_ps(v28, v29, 221);
    v7 = ++v40.m_queryObject.m_numTransforms;
  }
  v32 = (unsigned __int64)&m_rotatedPlanes[-1];
  for ( i = &v40.m_queryObject.m_rotatedPlanes[(__int64)v7 + 7];
        v32 >= (unsigned __int64)v40.m_queryObject.m_rotatedPlanes;
        *(__m128 *)(v32 + 112) = _mm_add_ps(v37, v37) )
  {
    si128 = _mm_load_si128((const __m128i *)v32);
    v32 -= 64i64;
    --i;
    i[1].m_rotation.m_col0 = (hkVector4f)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u);
    i[1].m_rotation.m_col1 = (hkVector4f)_mm_srli_epi32(
                                           _mm_slli_epi32(_mm_load_si128((const __m128i *)(v32 + 80)), 1u),
                                           1u);
    v35 = _mm_load_si128((const __m128i *)(v32 + 96));
    i[1].m_translation = 0i64;
    i[1].m_rotation.m_col2 = (hkVector4f)_mm_srli_epi32(_mm_slli_epi32(v35, 1u), 1u);
    v36.m_offset.m_quad = (__m128)code->m_info;
    v37 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v36.m_offset.m_quad, v36.m_offset.m_quad, 85), *(__m128 *)(v32 + 80)),
                _mm_mul_ps(_mm_shuffle_ps(v36.m_offset.m_quad, v36.m_offset.m_quad, 0), *(__m128 *)(v32 + 64))),
              _mm_mul_ps(_mm_shuffle_ps(v36.m_offset.m_quad, v36.m_offset.m_quad, 170), *(__m128 *)(v32 + 96))),
            *(__m128 *)(v32 + 112));
  }
  v40.m_queryObject.m_primitives_out = fullyIncludedHitsOut;
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObject>::queryMoppTree(
    &v40,
    &querya,
    m_data,
    &fQueryL);
}

// File Line: 326
// RVA: 0xDB2E50
void __fastcall hkMoppUsingFloatAabbVirtualMachine_queryPlanesOptimized(
        hkpMoppCode *code,
        hkpMoppPlanesQueryInput *query,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *partialHitsOut,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *fullyIncludedHitsOut)
{
  __m128 v4; // xmm0
  char *m_data; // rbp
  hkVector4f *m_planes; // r10
  int v7; // r8d
  int m_numPlanes; // r9d
  hkTransformf *m_rotatedPlanes; // rcx
  int v12; // ebx
  __m128 *p_m_quad; // rdx
  unsigned int v14; // eax
  __int64 v15; // r11
  __m128 m_quad; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm5
  __m128 v21; // xmm4
  __m128 v22; // xmm3
  __m128 v23; // xmm1
  __m128 *v24; // rdx
  __m128 *v25; // r11
  int v26; // r9d
  int v27; // r9d
  __m128 v28; // xmm5
  __m128 v29; // xmm4
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  unsigned __int64 v32; // rcx
  hkTransformf *i; // rdx
  __m128i si128; // xmm0
  __m128i v35; // xmm0
  hkpMoppCode::CodeInfo v36; // xmm1
  __m128 v37; // xmm2
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt querya; // [rsp+20h] [rbp-498h] BYREF
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::hkpMoppTempAabb fQueryL; // [rsp+40h] [rbp-478h] BYREF
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized> v40; // [rsp+60h] [rbp-458h] BYREF

  v4 = (__m128)(unsigned int)FLOAT_1_0;
  m_data = code->m_data.m_data;
  m_planes = query->m_planes;
  v40.m_primitives_out = partialHitsOut;
  v7 = 0;
  v4.m128_f32[0] = 1.0 / code->m_info.m_offset.m_quad.m128_f32[3];
  fQueryL.m_aabb.m_min = 0i64;
  m_numPlanes = query->m_numPlanes;
  querya.m_shift = 16;
  LODWORD(v40.m_ItoFScale) = v4.m128_i32[0];
  v4.m128_f32[0] = v4.m128_f32[0] * 16777216.0;
  memset(&querya, 0, 20);
  m_rotatedPlanes = v40.m_queryObject.m_rotatedPlanes;
  v40.m_queryObject.m_numTransforms = 0;
  fQueryL.m_aabb.m_max.m_quad = _mm_shuffle_ps(v4, v4, 0);
  v12 = 0;
  if ( m_numPlanes >= 0 && (m_numPlanes & 0xFFFFFFFC) != 0 )
  {
    p_m_quad = &m_planes[2].m_quad;
    v14 = (((m_numPlanes & 0xFFFFFFFC) - 1) >> 2) + 1;
    v15 = v14;
    v12 = 4 * v14;
    do
    {
      m_quad = m_planes->m_quad;
      v17 = *p_m_quad;
      ++m_rotatedPlanes;
      m_planes += 4;
      p_m_quad += 4;
      v18 = m_quad;
      v19 = v17;
      v20 = _mm_shuffle_ps(m_quad, p_m_quad[-5], 238);
      v21 = _mm_shuffle_ps(v17, p_m_quad[-3], 238);
      v22 = _mm_shuffle_ps(v18, p_m_quad[-5], 68);
      v23 = _mm_shuffle_ps(v19, p_m_quad[-3], 68);
      m_rotatedPlanes[-1].m_rotation.m_col0.m_quad = _mm_shuffle_ps(v22, v23, 136);
      m_rotatedPlanes[-1].m_rotation.m_col1.m_quad = _mm_shuffle_ps(v22, v23, 221);
      m_rotatedPlanes[-1].m_rotation.m_col2.m_quad = _mm_shuffle_ps(v20, v21, 136);
      m_rotatedPlanes[-1].m_translation.m_quad = _mm_shuffle_ps(v20, v21, 221);
      v7 = ++v40.m_queryObject.m_numTransforms;
      --v15;
    }
    while ( v15 );
  }
  v24 = &m_planes[1].m_quad;
  v25 = &m_planes[2].m_quad;
  v26 = m_numPlanes - v12 - 1;
  if ( !v26 )
  {
    v24 = &m_planes->m_quad;
    goto LABEL_9;
  }
  v27 = v26 - 1;
  if ( !v27 )
  {
LABEL_9:
    v25 = &m_planes->m_quad;
    goto LABEL_10;
  }
  if ( v27 == 1 )
  {
LABEL_10:
    ++m_rotatedPlanes;
    v28 = _mm_shuffle_ps(m_planes->m_quad, *v24, 238);
    v29 = _mm_shuffle_ps(*v25, m_planes->m_quad, 238);
    v30 = _mm_shuffle_ps(m_planes->m_quad, *v24, 68);
    v31 = _mm_shuffle_ps(*v25, m_planes->m_quad, 68);
    m_rotatedPlanes[-1].m_rotation.m_col0.m_quad = _mm_shuffle_ps(v30, v31, 136);
    m_rotatedPlanes[-1].m_rotation.m_col1.m_quad = _mm_shuffle_ps(v30, v31, 221);
    m_rotatedPlanes[-1].m_rotation.m_col2.m_quad = _mm_shuffle_ps(v28, v29, 136);
    m_rotatedPlanes[-1].m_translation.m_quad = _mm_shuffle_ps(v28, v29, 221);
    v7 = ++v40.m_queryObject.m_numTransforms;
  }
  v32 = (unsigned __int64)&m_rotatedPlanes[-1];
  for ( i = &v40.m_queryObject.m_rotatedPlanes[(__int64)v7 + 7];
        v32 >= (unsigned __int64)v40.m_queryObject.m_rotatedPlanes;
        *(__m128 *)(v32 + 112) = _mm_add_ps(v37, v37) )
  {
    si128 = _mm_load_si128((const __m128i *)v32);
    v32 -= 64i64;
    --i;
    i[1].m_rotation.m_col0 = (hkVector4f)_mm_srli_epi32(_mm_slli_epi32(si128, 1u), 1u);
    i[1].m_rotation.m_col1 = (hkVector4f)_mm_srli_epi32(
                                           _mm_slli_epi32(_mm_load_si128((const __m128i *)(v32 + 80)), 1u),
                                           1u);
    v35 = _mm_load_si128((const __m128i *)(v32 + 96));
    i[1].m_translation = 0i64;
    i[1].m_rotation.m_col2 = (hkVector4f)_mm_srli_epi32(_mm_slli_epi32(v35, 1u), 1u);
    v36.m_offset.m_quad = (__m128)code->m_info;
    v37 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v36.m_offset.m_quad, v36.m_offset.m_quad, 85), *(__m128 *)(v32 + 80)),
                _mm_mul_ps(_mm_shuffle_ps(v36.m_offset.m_quad, v36.m_offset.m_quad, 0), *(__m128 *)(v32 + 64))),
              _mm_mul_ps(_mm_shuffle_ps(v36.m_offset.m_quad, v36.m_offset.m_quad, 170), *(__m128 *)(v32 + 96))),
            *(__m128 *)(v32 + 112));
  }
  v40.m_queryObject.m_primitives_out = fullyIncludedHitsOut;
  hkpMoppUsingFloatAabbVirtualMachine<hkpMoppPlanesQueryInput,hkMoppPlanesQueryObjectOptimized>::queryMoppTree(
    &v40,
    &querya,
    m_data,
    &fQueryL);
}

// File Line: 333
// RVA: 0xDB30F0
void __fastcall hkMoppUsingFloatAabbVirtualMachine_querySphere(
        hkpMoppCode *code,
        hkSphere *query,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *partialHitsOut,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *fullyIncludedHitsOut)
{
  __int128 v4; // xmm1
  char *m_data; // r8
  __m128 v6; // xmm0
  __m128 m_quad; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm2
  hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObject>::hkpMoppUsingFloatAabbVirtualMachineQueryInt querya; // [rsp+20h] [rbp-98h] BYREF
  hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObject>::hkpMoppTempAabb v12; // [rsp+40h] [rbp-78h] BYREF
  hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObject> v13; // [rsp+60h] [rbp-58h] BYREF

  v4 = (unsigned int)FLOAT_1_0;
  v13.m_primitives_out = partialHitsOut;
  *(float *)&v4 = 1.0 / code->m_info.m_offset.m_quad.m128_f32[3];
  m_data = code->m_data.m_data;
  querya.m_shift = 16;
  v12.m_aabb.m_min = 0i64;
  memset(&querya, 0, 20);
  LODWORD(v13.m_ItoFScale) = v4;
  *(float *)&v4 = *(float *)&v4 * 16777216.0;
  v13.m_queryObject.m_primitives_out = fullyIncludedHitsOut;
  v6 = (__m128)v4;
  m_quad = query->m_pos.m_quad;
  v8 = query->m_pos.m_quad;
  v12.m_aabb.m_max.m_quad = _mm_shuffle_ps(v6, v6, 0);
  v9 = _mm_sub_ps(v8, code->m_info.m_offset.m_quad);
  v10 = _mm_add_ps(v9, v9);
  v13.m_queryObject.m_sphere2.m_pos.m_quad = _mm_shuffle_ps(
                                               v10,
                                               _mm_unpackhi_ps(
                                                 v10,
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(m_quad, m_quad, 255),
                                                   (__m128)xmmword_141A710D0)),
                                               196);
  hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObject>::queryMoppTree(&v13, &querya, m_data, &v12);
}

// File Line: 340
// RVA: 0xDB31A0
void __fastcall hkMoppUsingFloatAabbVirtualMachine_querySphereOptimized(
        hkpMoppCode *code,
        hkSphere *query,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *partialHitsOut,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *fullyIncludedHitsOut)
{
  __int128 v4; // xmm1
  char *m_data; // r8
  __m128 v6; // xmm0
  __m128 m_quad; // xmm1
  __m128 v8; // xmm2
  __m128 v9; // xmm2
  __m128 v10; // xmm2
  hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObjectOptimized>::hkpMoppUsingFloatAabbVirtualMachineQueryInt querya; // [rsp+20h] [rbp-98h] BYREF
  hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObjectOptimized>::hkpMoppTempAabb v12; // [rsp+40h] [rbp-78h] BYREF
  hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObjectOptimized> v13; // [rsp+60h] [rbp-58h] BYREF

  v4 = (unsigned int)FLOAT_1_0;
  v13.m_primitives_out = partialHitsOut;
  *(float *)&v4 = 1.0 / code->m_info.m_offset.m_quad.m128_f32[3];
  m_data = code->m_data.m_data;
  querya.m_shift = 16;
  v12.m_aabb.m_min = 0i64;
  memset(&querya, 0, 20);
  LODWORD(v13.m_ItoFScale) = v4;
  *(float *)&v4 = *(float *)&v4 * 16777216.0;
  v13.m_queryObject.m_primitives_out = fullyIncludedHitsOut;
  v6 = (__m128)v4;
  m_quad = query->m_pos.m_quad;
  v8 = query->m_pos.m_quad;
  v12.m_aabb.m_max.m_quad = _mm_shuffle_ps(v6, v6, 0);
  v9 = _mm_sub_ps(v8, code->m_info.m_offset.m_quad);
  v10 = _mm_add_ps(v9, v9);
  v13.m_queryObject.m_sphere2.m_pos.m_quad = _mm_shuffle_ps(
                                               v10,
                                               _mm_unpackhi_ps(
                                                 v10,
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(m_quad, m_quad, 255),
                                                   (__m128)xmmword_141A710D0)),
                                               196);
  hkpMoppUsingFloatAabbVirtualMachine<hkSphere,hkMoppSphereQueryObjectOptimized>::queryMoppTree(
    &v13,
    &querya,
    m_data,
    &v12);
}

// File Line: 347
// RVA: 0xDB3250
void __fastcall hkMoppModifyVirtualMachine_queryAabb(hkpMoppCode *code, hkAabb *aabb, hkpMoppModifier *modifierOut)
{
  hkpMoppModifyVirtualMachine v3; // [rsp+20h] [rbp-78h] BYREF

  hkpMoppModifyVirtualMachine::queryAabb(&v3, code, aabb, modifierOut);
}

// File Line: 353
// RVA: 0xDB3280
void __fastcall hkMoppKDopGeometriesVirtualMachine_query(
        hkpMoppCode *code,
        hkpMoppKDopQuery *query,
        hkpMoppInfo *kDopGeometries)
{
  hkpMoppKDopGeometriesVirtualMachine v6; // [rsp+20h] [rbp-D8h] BYREF

  hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachine(&v6);
  hkpMoppKDopGeometriesVirtualMachine::queryMopp(&v6, code, query, kDopGeometries);
  hkpMoppKDopGeometriesVirtualMachine::~hkpMoppKDopGeometriesVirtualMachine(&v6);
}

