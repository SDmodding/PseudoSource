// File Line: 19
// RVA: 0xD0EF90
void __fastcall hkpMultiSphereShape::hkpMultiSphereShape(
        hkpMultiSphereShape *this,
        hkVector4f *spheres,
        int numSpheres)
{
  __int64 v3; // r9
  __int64 v4; // r8
  signed __int64 v5; // rax
  __m128 m_quad; // xmm0

  v3 = numSpheres;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1049;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMultiSphereShape::`vftable;
  this->m_userData = 0i64;
  v4 = v3;
  if ( (int)v3 > 0 )
  {
    v5 = (char *)this - (char *)spheres;
    do
    {
      m_quad = spheres->m_quad;
      *(__m128 *)((char *)++spheres + v5 + 32) = m_quad;
      --v4;
    }
    while ( v4 );
  }
  this->m_numSpheres = v3;
}

// File Line: 40
// RVA: 0xD0EFE0
void __fastcall hkpMultiSphereShape::hkpMultiSphereShape(hkpMultiSphereShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpShape::hkpShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpMultiSphereShape::`vftable;
  this->m_type.m_storage = 25;
}

// File Line: 47
// RVA: 0xD0F060
void __fastcall hkpMultiSphereShape::getAabb(
        hkpMultiSphereShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  hkVector4f v4; // xmm3
  hkVector4f v5; // xmm4
  hkVector4f v6; // xmm5
  __int64 m_numSpheres; // r9
  hkVector4f v9; // xmm6
  __int64 v10; // rdx
  hkVector4f *v11; // rax
  __m128 m_quad; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  __m128 v16; // xmm1
  __m128 v17; // xmm3
  __m128 v18; // xmm4
  char *v19; // rax
  signed __int64 v20; // rcx
  __int64 v21; // rdx
  __m128 v22; // xmm0
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128 v25; // xmm2
  __m128 v26; // xmm0
  __m128 v27; // xmm1
  __m128 v28; // xmm1
  char v29[128]; // [rsp+0h] [rbp-A8h] BYREF

  v4.m_quad = (__m128)localToWorld->m_rotation.m_col0;
  v5.m_quad = (__m128)localToWorld->m_rotation.m_col1;
  v6.m_quad = (__m128)localToWorld->m_rotation.m_col2;
  m_numSpheres = (unsigned int)this->m_numSpheres;
  v9.m_quad = (__m128)localToWorld->m_translation;
  v10 = (int)m_numSpheres - 1;
  v11 = &this->m_spheres[v10];
  do
  {
    m_quad = v11->m_quad;
    --v11;
    --v10;
    v14 = _mm_shuffle_ps(m_quad, m_quad, 85);
    v15 = _mm_shuffle_ps(m_quad, m_quad, 0);
    v16 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 170), v6.m_quad);
    *(__m128 *)((char *)&v11[-2].m_quad + v29 - (char *)this) = _mm_add_ps(
                                                                  _mm_add_ps(
                                                                    _mm_add_ps(
                                                                      _mm_mul_ps(v14, v5.m_quad),
                                                                      _mm_mul_ps(v15, v4.m_quad)),
                                                                    v16),
                                                                  v9.m_quad);
  }
  while ( v10 >= 0 );
  v17 = _mm_shuffle_ps((__m128)xmmword_141A712A0, _mm_unpackhi_ps((__m128)xmmword_141A712A0, (__m128)0i64), 196);
  v18 = _mm_shuffle_ps((__m128)xmmword_141A712F0, _mm_unpackhi_ps((__m128)xmmword_141A712F0, (__m128)0i64), 196);
  if ( (int)m_numSpheres > 0 )
  {
    v19 = v29;
    v20 = (char *)this - v29;
    v21 = m_numSpheres;
    do
    {
      v22 = *(__m128 *)&v19[v20 + 48];
      v19 += 16;
      v23 = _mm_and_ps(v22, (__m128)xmmword_141687F30);
      v24 = _mm_or_ps(_mm_shuffle_ps(v23, v23, 78), v23);
      v25 = _mm_or_ps(_mm_shuffle_ps(v24, v24, 177), v24);
      v26 = *((__m128 *)v19 - 1);
      v16 = _mm_add_ps(v26, v25);
      v18 = _mm_max_ps(v18, v16);
      v17 = _mm_min_ps(v17, _mm_sub_ps(v26, v25));
      --v21;
    }
    while ( v21 );
  }
  v16.m128_f32[0] = tolerance;
  v27 = _mm_shuffle_ps(v16, v16, 0);
  v28 = _mm_shuffle_ps(v27, _mm_unpackhi_ps(v27, (__m128)0i64), 196);
  out->m_max.m_quad = _mm_add_ps(v28, v18);
  out->m_min.m_quad = _mm_sub_ps(v17, v28);
}

// File Line: 75
// RVA: 0xD0F010
__int64 __fastcall hkpMultiSphereShape::getNumCollisionSpheres(hkpMultiSphereShape *this)
{
  return (unsigned int)this->m_numSpheres;
}

// File Line: 80
// RVA: 0xD0F020
hkSphere *__fastcall hkpMultiSphereShape::getCollisionSpheres(hkpMultiSphereShape *this, hkSphere *sphereBuffer)
{
  int *p_m_numSpheres; // r9
  int v3; // r8d
  hkSphere *result; // rax
  signed __int64 v5; // rcx
  hkSphere v6; // xmm0

  p_m_numSpheres = &this->m_numSpheres;
  v3 = 0;
  result = sphereBuffer;
  if ( this->m_numSpheres > 0 )
  {
    v5 = (char *)this - (char *)sphereBuffer;
    do
    {
      v6.m_pos.m_quad = *(__m128 *)((char *)&result[3] + v5);
      ++v3;
      ++result;
      result[-1] = (hkSphere)v6.m_pos.m_quad;
    }
    while ( v3 < *p_m_numSpheres );
    return sphereBuffer;
  }
  return result;
}

// File Line: 89
// RVA: 0xD0F3D0
__int64 __fastcall castRayInternal(
        hkpShapeRayCastInput *input,
        hkVector4f *m_spheres,
        int m_numSpheres,
        float *distOut,
        int *indexOut)
{
  _QWORD *Value; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  unsigned int v13; // edi
  int v14; // eax
  int *v15; // rcx
  signed __int64 v16; // rbp
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm8
  __m128 v20; // xmm7
  __m128 v21; // xmm1
  __m128 v22; // xmm4
  __m128 v23; // xmm4
  __m128 v24; // xmm3
  __m128 v25; // xmm5
  __m128 v26; // xmm3
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  _QWORD *v30; // rax
  _QWORD *v31; // rcx
  _QWORD *v32; // r8
  unsigned __int64 v33; // rax
  _QWORD *v34; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtrcMultiSpher";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  v13 = 0;
  v14 = 0;
  if ( m_numSpheres > 0 )
  {
    v15 = indexOut;
    v16 = (char *)distOut - (char *)indexOut;
    do
    {
      v17 = _mm_sub_ps(input->m_from.m_quad, m_spheres->m_quad);
      v18 = _mm_sub_ps(_mm_sub_ps(input->m_to.m_quad, m_spheres->m_quad), v17);
      v19 = _mm_shuffle_ps(m_spheres->m_quad, m_spheres->m_quad, 255);
      v20 = _mm_mul_ps(v17, v17);
      v21 = _mm_mul_ps(v18, v17);
      v22 = _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v21, v21, 85), _mm_shuffle_ps(v21, v21, 0)),
              _mm_shuffle_ps(v21, v21, 170));
      v23 = _mm_add_ps(v22, v22);
      if ( v23.m128_f32[0] < 0.0 )
      {
        v24 = _mm_mul_ps(v18, v18);
        v25 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170));
        v26 = _mm_sub_ps(
                _mm_mul_ps(v23, v23),
                _mm_mul_ps(
                  _mm_sub_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
                      _mm_shuffle_ps(v20, v20, 170)),
                    _mm_mul_ps(v19, v19)),
                  _mm_mul_ps(v25, (__m128)xmmword_141A710F0)));
        if ( v26.m128_f32[0] > 0.0 )
        {
          v27 = _mm_rsqrt_ps(v26).m128_f32[0];
          v28 = (float)((float)(0.0 - v23.m128_f32[0])
                      - (float)((float)((float)(3.0 - (float)((float)(v27 * v26.m128_f32[0]) * v27)) * (float)(0.5 * v27))
                              * v26.m128_f32[0]))
              * 0.5;
          if ( v28 < v25.m128_f32[0] && v28 >= 0.0 )
          {
            v29 = _mm_rcp_ps(v25).m128_f32[0];
            ++v13;
            *(float *)((char *)++v15 + v16 - 4) = (float)((float)(2.0 - (float)(v29 * v25.m128_f32[0])) * v29) * v28;
            *(v15 - 1) = v14;
          }
        }
      }
      ++v14;
      ++m_spheres;
    }
    while ( v14 < m_numSpheres );
  }
  v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v31 = (_QWORD *)v30[1];
  v32 = v30;
  if ( (unsigned __int64)v31 < v30[3] )
  {
    *v31 = "Et";
    v33 = __rdtsc();
    v34 = v31 + 2;
    *((_DWORD *)v34 - 2) = v33;
    v32[1] = v34;
  }
  return v13;
}

// File Line: 173
// RVA: 0xD0F5F0
__int64 __fastcall getBestHit(
        hkVector4f *m_spheres,
        int m_numSpheres,
        float *dist,
        int *sphereIndex,
        int nhit,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  int v8; // edx
  unsigned int v9; // r10d
  float m_hitFraction; // xmm0_4
  __int64 v13; // rax
  int v14; // r8d
  float *v15; // rcx
  float *v16; // rax
  __int64 v17; // rdx
  __int64 result; // rax
  __m128 v19; // xmm2
  hkVector4f v20; // xmm4
  __m128 m_quad; // xmm1
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  float resultsa; // [rsp+38h] [rbp+38h]

  v8 = 0;
  v9 = -1;
  m_hitFraction = results->m_hitFraction;
  resultsa = m_hitFraction;
  v13 = 0i64;
  if ( nhit >= 4 )
  {
    v14 = 2;
    v15 = dist + 2;
    v13 = 4i64 * (((unsigned int)(nhit - 4) >> 2) + 1);
    do
    {
      if ( *(v15 - 2) < m_hitFraction )
      {
        m_hitFraction = *(v15 - 2);
        v9 = v8;
        resultsa = m_hitFraction;
      }
      if ( *(v15 - 1) < m_hitFraction )
      {
        m_hitFraction = *(v15 - 1);
        v9 = v14 - 1;
        resultsa = m_hitFraction;
      }
      if ( *v15 < m_hitFraction )
      {
        m_hitFraction = *v15;
        v9 = v14;
        resultsa = *v15;
      }
      if ( v15[1] < m_hitFraction )
      {
        m_hitFraction = v15[1];
        v9 = v14 + 1;
        resultsa = m_hitFraction;
      }
      v8 += 4;
      v15 += 4;
      v14 += 4;
    }
    while ( v8 < nhit - 3 );
  }
  if ( v8 < nhit )
  {
    v16 = &dist[v13];
    do
    {
      if ( *v16 < m_hitFraction )
      {
        m_hitFraction = *v16;
        v9 = v8;
      }
      ++v8;
      ++v16;
    }
    while ( v8 < nhit );
    resultsa = m_hitFraction;
  }
  if ( v9 == -1 )
    return 0xFFFFFFFFi64;
  results->m_shapeKeys[results->m_shapeKeyIndex] = -1;
  v17 = sphereIndex[v9];
  results->m_hitFraction = m_hitFraction;
  result = v9;
  v19 = _mm_sub_ps(input->m_from.m_quad, m_spheres[v17].m_quad);
  v20.m_quad = _mm_add_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(_mm_sub_ps(input->m_to.m_quad, m_spheres[v17].m_quad), v19),
                   _mm_shuffle_ps((__m128)LODWORD(resultsa), (__m128)LODWORD(resultsa), 0)),
                 v19);
  results->m_normal = (hkVector4f)v20.m_quad;
  m_quad = m_spheres[v17].m_quad;
  results->m_extraInfo = v17;
  v22 = _mm_shuffle_ps(m_quad, m_quad, 255);
  v23 = _mm_rcp_ps(v22);
  results->m_normal.m_quad = _mm_mul_ps(v20.m_quad, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v22)), v23));
  return result;
}

// File Line: 203
// RVA: 0xD0F1B0
hkBool *__fastcall hkpMultiSphereShape::castRay(
        hkpMultiSphereShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  int nhit; // eax
  int sphereIndex[8]; // [rsp+40h] [rbp-48h] BYREF
  float dist[8]; // [rsp+60h] [rbp-28h] BYREF

  nhit = castRayInternal(input, this->m_spheres, this->m_numSpheres, dist, sphereIndex);
  result->m_bool = getBestHit(this->m_spheres, this->m_numSpheres, dist, sphereIndex, nhit, input, results) != -1;
  return result;
}

// File Line: 211
// RVA: 0xD0F250
void __fastcall hkpMultiSphereShape::castRayWithCollector(
        hkpMultiSphereShape *this,
        hkpShapeRayCastInput *inputLocal,
        hkpCdBody *cdBody,
        hkpRayHitCollector *collector)
{
  int v8; // eax
  int v9; // edi
  __int64 v10; // rsi
  int m_numSpheres; // edx
  __int64 BestHit; // rbx
  hkpRayHitCollectorVtbl *vfptr; // rax
  int v14; // eax
  hkpShapeRayCastOutput results; // [rsp+40h] [rbp-B8h] BYREF
  int sphereIndex[8]; // [rsp+90h] [rbp-68h] BYREF
  float dist[8]; // [rsp+B0h] [rbp-48h] BYREF

  v8 = castRayInternal(inputLocal, this->m_spheres, this->m_numSpheres, dist, sphereIndex);
  results.m_hitFraction = 1.0;
  results.m_extraInfo = -1;
  results.m_shapeKeyIndex = 0;
  results.m_shapeKeys[0] = -1;
  v9 = v8;
  if ( v8 )
  {
    v10 = v8;
    do
    {
      m_numSpheres = this->m_numSpheres;
      results.m_hitFraction = 1.0;
      results.m_extraInfo = -1;
      results.m_shapeKeyIndex = 0;
      results.m_shapeKeys[0] = -1;
      BestHit = getBestHit(this->m_spheres, m_numSpheres, dist, sphereIndex, v9, inputLocal, &results);
      vfptr = collector->vfptr;
      results.m_normal.m_quad = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(results.m_normal.m_quad, results.m_normal.m_quad, 85),
                                      *((__m128 *)cdBody->m_motion + 1)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(results.m_normal.m_quad, results.m_normal.m_quad, 0),
                                      *(__m128 *)cdBody->m_motion)),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(results.m_normal.m_quad, results.m_normal.m_quad, 170),
                                    *((__m128 *)cdBody->m_motion + 2)));
      vfptr->addRayHit(collector, cdBody, &results);
      v14 = sphereIndex[v10 + 7];
      --v10;
      LODWORD(dist[BestHit]) = v14;
      sphereIndex[BestHit] = sphereIndex[v10];
      --v9;
    }
    while ( v9 );
  }
}

