// File Line: 19
// RVA: 0xD0EF90
void __fastcall hkpMultiSphereShape::hkpMultiSphereShape(hkpMultiSphereShape *this, hkVector4f *spheres, int numSpheres)
{
  __int64 v3; // r9
  __int64 v4; // r8
  signed __int64 v5; // rax
  __m128 v6; // xmm0

  v3 = numSpheres;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1049;
  this->vfptr = (hkBaseObjectVtbl *)&hkpMultiSphereShape::`vftable;
  this->m_userData = 0i64;
  v4 = v3;
  if ( (signed int)v3 > 0 )
  {
    v5 = (char *)this - (char *)spheres;
    do
    {
      v6 = spheres->m_quad;
      ++spheres;
      *(__m128 *)((char *)spheres + v5 + 32) = v6;
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
  hkpMultiSphereShape *v2; // rbx

  v2 = this;
  hkpShape::hkpShape((hkpShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpMultiSphereShape::`vftable;
  v2->m_type.m_storage = 25;
}

// File Line: 47
// RVA: 0xD0F060
void __fastcall hkpMultiSphereShape::getAabb(hkpMultiSphereShape *this, hkTransformf *localToWorld, float tolerance, hkAabb *out)
{
  hkVector4f v4; // xmm3
  hkVector4f v5; // xmm4
  hkVector4f v6; // xmm5
  hkAabb *v7; // r10
  __int64 v8; // r9
  hkVector4f v9; // xmm6
  __int64 v10; // rdx
  __m128 *v11; // rax
  float v12; // xmm7_4
  __m128 v13; // xmm1
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
  __m128 v26; // xmm1
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  __m128 v29; // xmm1
  char v30; // [rsp+0h] [rbp-A8h]

  v4.m_quad = (__m128)localToWorld->m_rotation.m_col0;
  v5.m_quad = (__m128)localToWorld->m_rotation.m_col1;
  v6.m_quad = (__m128)localToWorld->m_rotation.m_col2;
  v7 = out;
  v8 = (unsigned int)this->m_numSpheres;
  v9.m_quad = (__m128)localToWorld->m_translation;
  v10 = (signed int)v8 - 1;
  v11 = (__m128 *)&(&this->vfptr)[2 * (v10 + 3)];
  v12 = tolerance;
  do
  {
    v13 = *v11;
    --v11;
    --v10;
    v14 = _mm_shuffle_ps(v13, v13, 85);
    v15 = _mm_shuffle_ps(v13, v13, 0);
    v16 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v6.m_quad);
    *(__m128 *)((char *)v11 + &v30 - (char *)this - 32) = _mm_add_ps(
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
  if ( (signed int)v8 > 0 )
  {
    v19 = &v30;
    v20 = (char *)this - &v30;
    v21 = v8;
    do
    {
      v22 = *(__m128 *)&v19[v20 + 48];
      v19 += 16;
      v23 = _mm_and_ps(v22, (__m128)xmmword_141687F30);
      v24 = _mm_or_ps(_mm_shuffle_ps(v23, v23, 78), v23);
      v25 = _mm_or_ps(_mm_shuffle_ps(v24, v24, 177), v24);
      v26 = *((__m128 *)v19 - 1);
      v27 = v26;
      v16 = _mm_add_ps(v26, v25);
      v18 = _mm_max_ps(v18, v16);
      v17 = _mm_min_ps(v17, _mm_sub_ps(v27, v25));
      --v21;
    }
    while ( v21 );
  }
  v16.m128_f32[0] = v12;
  v28 = _mm_shuffle_ps(v16, v16, 0);
  v29 = _mm_shuffle_ps(v28, _mm_unpackhi_ps(v28, (__m128)0i64), 196);
  v7->m_max.m_quad = _mm_add_ps(v29, v18);
  v7->m_min.m_quad = _mm_sub_ps(v17, v29);
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
  int *v2; // r9
  int v3; // er8
  hkSphere *result; // rax
  signed __int64 v5; // rcx
  hkSphere v6; // xmm0

  v2 = &this->m_numSpheres;
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
    while ( v3 < *v2 );
    result = sphereBuffer;
  }
  return result;
}

// File Line: 89
// RVA: 0xD0F3D0
__int64 __fastcall castRayInternal(hkpShapeRayCastInput *input, hkVector4f *m_spheres, int m_numSpheres, float *distOut, int *indexOut)
{
  hkpShapeRayCastInput *v5; // r14
  float *v6; // rbp
  int v7; // esi
  hkVector4f *v8; // rbx
  _QWORD *v9; // r8
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
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
  signed __int64 v34; // rcx

  v5 = input;
  v6 = distOut;
  v7 = m_numSpheres;
  v8 = m_spheres;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtrcMultiSpher";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  v13 = 0;
  v14 = 0;
  if ( v7 > 0 )
  {
    v15 = indexOut;
    v16 = (char *)v6 - (char *)indexOut;
    do
    {
      v17 = _mm_sub_ps(v5->m_from.m_quad, v8->m_quad);
      v18 = _mm_sub_ps(_mm_sub_ps(v5->m_to.m_quad, v8->m_quad), v17);
      v19 = _mm_shuffle_ps(v8->m_quad, v8->m_quad, 255);
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
          LODWORD(v27) = (unsigned __int128)_mm_rsqrt_ps(v26);
          v28 = (float)((float)(0.0 - v23.m128_f32[0])
                      - (float)((float)((float)(3.0 - (float)((float)(v27 * v26.m128_f32[0]) * v27)) * (float)(0.5 * v27))
                              * v26.m128_f32[0]))
              * 0.5;
          if ( v28 < v25.m128_f32[0] && v28 >= 0.0 )
          {
            LODWORD(v29) = (unsigned __int128)_mm_rcp_ps(v25);
            ++v13;
            ++v15;
            *(float *)((char *)v15 + v16 - 4) = (float)((float)(2.0 - (float)(v29 * v25.m128_f32[0])) * v29) * v28;
            *(v15 - 1) = v14;
          }
        }
      }
      ++v14;
      ++v8;
    }
    while ( v14 < v7 );
  }
  v30 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v31 = (_QWORD *)v30[1];
  v32 = v30;
  if ( (unsigned __int64)v31 < v30[3] )
  {
    *v31 = "Et";
    v33 = __rdtsc();
    v34 = (signed __int64)(v31 + 2);
    *(_DWORD *)(v34 - 8) = v33;
    v32[1] = v34;
  }
  return v13;
}

// File Line: 173
// RVA: 0xD0F5F0
signed __int64 __fastcall getBestHit(hkVector4f *m_spheres, int m_numSpheres, float *dist, int *sphereIndex, int nhit, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpShapeRayCastOutput *v7; // rdi
  int v8; // edx
  unsigned int v9; // er10
  float *v10; // rbx
  float v11; // xmm0_4
  hkVector4f *v12; // rsi
  signed __int64 v13; // rax
  signed int v14; // er8
  float *v15; // rcx
  float *v16; // rax
  __int64 v17; // rdx
  signed __int64 result; // rax
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  float resultsa; // [rsp+38h] [rbp+38h]

  v7 = results;
  v8 = 0;
  v9 = -1;
  v10 = dist;
  v11 = results->m_hitFraction;
  resultsa = results->m_hitFraction;
  v12 = m_spheres;
  v13 = 0i64;
  if ( nhit >= 4 )
  {
    v14 = 2;
    v15 = v10 + 2;
    v13 = 4i64 * (((unsigned int)(nhit - 4) >> 2) + 1);
    do
    {
      if ( *(v15 - 2) < v11 )
      {
        v11 = *(v15 - 2);
        v9 = v8;
        resultsa = *(v15 - 2);
      }
      if ( *(v15 - 1) < v11 )
      {
        v11 = *(v15 - 1);
        v9 = v14 - 1;
        resultsa = *(v15 - 1);
      }
      if ( *v15 < v11 )
      {
        v11 = *v15;
        v9 = v14;
        resultsa = *v15;
      }
      if ( v15[1] < v11 )
      {
        v11 = v15[1];
        v9 = v14 + 1;
        resultsa = v15[1];
      }
      v8 += 4;
      v15 += 4;
      v14 += 4;
    }
    while ( v8 < nhit - 3 );
  }
  if ( v8 < nhit )
  {
    v16 = &v10[v13];
    do
    {
      if ( *v16 < v11 )
      {
        v11 = *v16;
        v9 = v8;
      }
      ++v8;
      ++v16;
    }
    while ( v8 < nhit );
    resultsa = v11;
  }
  if ( v9 == -1 )
    return 0xFFFFFFFFi64;
  v7->m_shapeKeys[v7->m_shapeKeyIndex] = -1;
  v17 = sphereIndex[v9];
  v7->m_hitFraction = v11;
  result = v9;
  v19 = _mm_sub_ps(input->m_from.m_quad, v12[v17].m_quad);
  v20 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(_mm_sub_ps(input->m_to.m_quad, v12[v17].m_quad), v19),
            _mm_shuffle_ps((__m128)LODWORD(resultsa), (__m128)LODWORD(resultsa), 0)),
          v19);
  v7->m_normal.m_quad = v20;
  v21 = v12[v17].m_quad;
  v7->m_extraInfo = v17;
  v22 = _mm_shuffle_ps(v21, v21, 255);
  v23 = _mm_rcp_ps(v22);
  v7->m_normal.m_quad = _mm_mul_ps(v20, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v22)), v23));
  return result;
}

// File Line: 203
// RVA: 0xD0F1B0
hkBool *__fastcall hkpMultiSphereShape::castRay(hkpMultiSphereShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpShapeRayCastInput *v4; // rdi
  hkpShapeRayCastOutput *v5; // rbx
  hkBool *v6; // r14
  hkpMultiSphereShape *v7; // rbp
  int nhit; // eax
  int sphereIndex; // [rsp+40h] [rbp-48h]
  float dist; // [rsp+60h] [rbp-28h]

  v4 = input;
  v5 = results;
  v6 = result;
  v7 = this;
  nhit = castRayInternal(input, this->m_spheres, this->m_numSpheres, &dist, &sphereIndex);
  v6->m_bool = getBestHit(v7->m_spheres, v7->m_numSpheres, &dist, &sphereIndex, nhit, v4, v5) != -1;
  return v6;
}

// File Line: 211
// RVA: 0xD0F250
void __fastcall hkpMultiSphereShape::castRayWithCollector(hkpMultiSphereShape *this, hkpShapeRayCastInput *inputLocal, hkpCdBody *cdBody, hkpRayHitCollector *collector)
{
  hkpShapeRayCastInput *input; // r14
  hkpCdBody *v5; // r13
  hkpRayHitCollector *v6; // r12
  hkpMultiSphereShape *v7; // rbp
  int v8; // eax
  int v9; // edi
  __int64 v10; // rsi
  int v11; // edx
  __int64 v12; // rbx
  hkpRayHitCollectorVtbl *v13; // rax
  float v14; // eax
  hkpShapeRayCastOutput results; // [rsp+40h] [rbp-B8h]
  int sphereIndex[7]; // [rsp+90h] [rbp-68h]
  int v17; // [rsp+ACh] [rbp-4Ch]
  float dist[8]; // [rsp+B0h] [rbp-48h]

  input = inputLocal;
  v5 = cdBody;
  v6 = collector;
  v7 = this;
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
      v11 = v7->m_numSpheres;
      results.m_hitFraction = 1.0;
      results.m_extraInfo = -1;
      results.m_shapeKeyIndex = 0;
      results.m_shapeKeys[0] = -1;
      v12 = getBestHit(v7->m_spheres, v11, dist, sphereIndex, v9, input, &results);
      v13 = v6->vfptr;
      results.m_normal.m_quad = _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(results.m_normal.m_quad, results.m_normal.m_quad, 85),
                                      *((__m128 *)v5->m_motion + 1)),
                                    _mm_mul_ps(
                                      _mm_shuffle_ps(results.m_normal.m_quad, results.m_normal.m_quad, 0),
                                      *(__m128 *)v5->m_motion)),
                                  _mm_mul_ps(
                                    _mm_shuffle_ps(results.m_normal.m_quad, results.m_normal.m_quad, 170),
                                    *((__m128 *)v5->m_motion + 2)));
      v13->addRayHit(v6, v5, (hkpShapeRayCastCollectorOutput *)&results.m_normal);
      v14 = *(float *)((char *)&v17 + v10 * 4);
      --v10;
      dist[v12] = v14;
      sphereIndex[v12] = sphereIndex[v10];
      --v9;
    }
    while ( v9 );
  }
}

