// File Line: 24
// RVA: 0xCF7BD0
void __fastcall hkpCapsuleShape::hkpCapsuleShape(
        hkpCapsuleShape *this,
        hkVector4f *vertexA,
        hkVector4f *vertexB,
        float radius)
{
  __m128 v4; // xmm3

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1028;
  this->m_radius = radius;
  this->vfptr = (hkBaseObjectVtbl *)&hkpCapsuleShape::`vftable;
  this->m_userData = 0i64;
  v4 = _mm_shuffle_ps((__m128)LODWORD(radius), (__m128)LODWORD(radius), 0);
  this->m_vertexA.m_quad = _mm_shuffle_ps(vertexA->m_quad, _mm_unpackhi_ps(vertexA->m_quad, v4), 196);
  this->m_vertexB.m_quad = _mm_shuffle_ps(vertexB->m_quad, _mm_unpackhi_ps(vertexB->m_quad, v4), 196);
}

// File Line: 40
// RVA: 0xCF84C0
void __fastcall hkpCapsuleShape::hkpCapsuleShape(hkpCapsuleShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpConvexShape::hkpConvexShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpCapsuleShape::`vftable;
  this->m_type.m_storage = 4;
}

// File Line: 45
// RVA: 0xCF84F0
void __fastcall hkpCapsuleShape::getFirstVertex(hkpCapsuleShape *this, hkVector4f *v)
{
  *v = this->m_vertexB;
}

// File Line: 52
// RVA: 0xCF7C40
hkSphere *__fastcall hkpCapsuleShape::getCollisionSpheres(hkpCapsuleShape *this, hkSphere *sphereBuffer)
{
  hkSphere *result; // rax

  result = sphereBuffer;
  *sphereBuffer = (hkSphere)this->m_vertexA;
  sphereBuffer[1] = (hkSphere)this->m_vertexB;
  return result;
}

// File Line: 59
// RVA: 0xCF85E0
void __fastcall hkpCapsuleShape::closestInfLineSegInfLineSeg(
        hkVector4f *A,
        hkVector4f *dA,
        hkVector4f *B,
        hkVector4f *dB,
        float *distSquared,
        float *t,
        float *u,
        hkVector4f *p,
        hkVector4f *q)
{
  hkVector4f v9; // xmm1
  float m_storage; // xmm0_4
  float v11; // xmm0_4
  hkResult result; // [rsp+30h] [rbp-48h] BYREF
  hkLineSegmentUtil::ClosestPointInfLineInfLineResult v13; // [rsp+40h] [rbp-38h] BYREF

  hkLineSegmentUtil::closestPointInfLineInfLine(&result, A, dA, B, dB, &v13);
  v9.m_quad = (__m128)v13.m_closestPointB;
  *p = v13.m_closestPointA;
  m_storage = v13.m_fractionA.m_storage;
  *q = (hkVector4f)v9.m_quad;
  v9.m_quad.m128_i32[0] = LODWORD(v13.m_fractionB.m_storage);
  *t = m_storage;
  v11 = v13.m_distanceSquared.m_storage;
  *u = v9.m_quad.m128_f32[0];
  *distSquared = v11;
}

// File Line: 72
// RVA: 0xCF8500
void __fastcall hkpCapsuleShape::closestPointLineSeg(hkVector4f *A, hkVector4f *B, hkVector4f *B2, hkVector4f *pt)
{
  __m128 m_quad; // xmm7
  __m128 v5; // xmm4
  __m128 v6; // xmm3
  __m128 v7; // xmm1
  __m128 v8; // xmm6
  __m128 v9; // xmm5
  __m128 v10; // xmm2

  m_quad = B->m_quad;
  v5 = _mm_sub_ps(B2->m_quad, B->m_quad);
  v6 = _mm_mul_ps(_mm_sub_ps(B->m_quad, A->m_quad), v5);
  v7 = _mm_mul_ps(v5, v5);
  v8 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v7, v7, 85), _mm_shuffle_ps(v7, v7, 0)), _mm_shuffle_ps(v7, v7, 170));
  v9 = _mm_sub_ps(
         (__m128)0i64,
         _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v6, v6, 85), _mm_shuffle_ps(v6, v6, 0)), _mm_shuffle_ps(v6, v6, 170)));
  if ( v9.m128_f32[0] > 0.0 )
  {
    if ( v9.m128_f32[0] < v8.m128_f32[0] )
    {
      v10 = _mm_rcp_ps(v8);
      pt->m_quad = _mm_add_ps(
                     _mm_mul_ps(v5, _mm_mul_ps(v9, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v10, v8)), v10))),
                     m_quad);
    }
    else
    {
      *pt = (hkVector4f)B2->m_quad;
    }
  }
  else
  {
    *pt = (hkVector4f)m_quad;
  }
}

// File Line: 106
// RVA: 0xCF7D20
hkBool *__fastcall hkpCapsuleShape::castRay(
        hkpCapsuleShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // rax
  _QWORD *v9; // rcx
  _QWORD *v10; // r8
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  hkVector4f v13; // xmm3
  __m128 v14; // xmm2
  __m128 v15; // xmm2
  hkVector4f v16; // xmm1
  __m128 v17; // xmm0
  float m_radius; // xmm14_4
  float v19; // xmm12_4
  __m128 v20; // xmm4
  __m128 v21; // xmm3
  __m128 v22; // xmm2
  __m128 v23; // xmm11
  __m128 v24; // xmm5
  __m128 v25; // xmm11
  __m128 v26; // xmm2
  __m128 v27; // xmm4
  __m128 v28; // xmm4
  float v29; // xmm1_4
  float v30; // xmm8_4
  bool v31; // cf
  hkVector4f v32; // xmm13
  hkVector4f v33; // xmm4
  hkVector4f v34; // xmm10
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  __m128 v37; // xmm9
  __m128 v38; // xmm1
  __m128 v39; // xmm7
  __int64 m_shapeKeyIndex; // rax
  __m128 v41; // xmm1
  hkVector4f v42; // xmm0
  __m128 v43; // xmm9
  __m128 v44; // xmm1
  __m128 v45; // xmm3
  __m128 v46; // xmm2
  __m128 v47; // xmm1
  __m128 v48; // xmm3
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  hkVector4f v51; // xmm3
  __m128 v52; // xmm2
  __m128 v53; // xmm2
  __m128 v54; // xmm1
  __m128 v55; // xmm1
  __m128 v56; // xmm13
  __m128 v57; // xmm10
  __m128 v58; // xmm10
  __m128 v59; // xmm3
  __m128 v60; // xmm0
  __m128 v61; // xmm5
  __m128 v62; // xmm4
  __m128 v63; // xmm2
  __m128i v64; // xmm14
  __m128 v65; // xmm1
  __m128 v66; // xmm12
  __m128 v67; // xmm15
  __m128 v68; // xmm2
  __m128 v69; // xmm3
  __m128 v70; // xmm3
  __m128 v71; // xmm5
  __m128 v72; // xmm2
  int v73; // edx
  int v74; // ecx
  int v75; // eax
  __m128 v76; // xmm4
  __m128 v77; // xmm1
  __m128 v78; // xmm5
  __m128 v79; // xmm4
  __m128 v80; // xmm4
  __m128 v81; // xmm10
  __m128 v82; // xmm1
  __m128 v83; // xmm2
  __m128 v84; // xmm1
  __int64 v85; // rax
  _QWORD *v86; // r9
  unsigned __int64 v87; // r8
  unsigned __int64 v88; // rax
  float u[4]; // [rsp+50h] [rbp-118h] BYREF
  hkVector4f dB; // [rsp+60h] [rbp-108h] BYREF
  hkVector4f dA; // [rsp+70h] [rbp-F8h] BYREF
  hkVector4f pt; // [rsp+80h] [rbp-E8h] BYREF
  hkVector4f q; // [rsp+90h] [rbp-D8h] BYREF
  float distSquared; // [rsp+170h] [rbp+8h] BYREF
  float t; // [rsp+180h] [rbp+18h] BYREF

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  v10 = Value;
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcCapsule";
    v11 = __rdtsc();
    v12 = v9 + 2;
    *((_DWORD *)v12 - 2) = v11;
    v10[1] = v12;
  }
  hkpCapsuleShape::closestPointLineSeg(&input->m_from, &this->m_vertexA, &this->m_vertexB, &pt);
  v13.m_quad = (__m128)input->m_from;
  v14 = _mm_sub_ps(input->m_from.m_quad, pt.m_quad);
  v15 = _mm_mul_ps(v14, v14);
  if ( (float)((float)(_mm_shuffle_ps(v15, v15, 85).m128_f32[0] + _mm_shuffle_ps(v15, v15, 0).m128_f32[0])
             + _mm_shuffle_ps(v15, v15, 170).m128_f32[0]) < (float)(this->m_radius * this->m_radius) )
    goto $returnFalse;
  v16.m_quad = (__m128)input->m_to;
  distSquared = FLOAT_3_40282e38;
  v17 = _mm_sub_ps(this->m_vertexB.m_quad, this->m_vertexA.m_quad);
  dA.m_quad = _mm_sub_ps(v16.m_quad, v13.m_quad);
  dB.m_quad = v17;
  hkpCapsuleShape::closestInfLineSegInfLineSeg(&input->m_from, &dA, &this->m_vertexA, &dB, &distSquared, &t, u, &pt, &q);
  m_radius = this->m_radius;
  v19 = m_radius * m_radius;
  if ( distSquared > (float)(m_radius * m_radius) )
    goto $returnFalse;
  v20 = _mm_mul_ps(dB.m_quad, dB.m_quad);
  if ( (float)((float)(_mm_shuffle_ps(v20, v20, 85).m128_f32[0] + _mm_shuffle_ps(v20, v20, 0).m128_f32[0])
             + _mm_shuffle_ps(v20, v20, 170).m128_f32[0]) <= 0.00000011920929 )
  {
    v24 = 0i64;
    v25 = 0i64;
  }
  else
  {
    v21 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)),
            _mm_shuffle_ps(v20, v20, 170));
    v22 = _mm_rsqrt_ps(v21);
    v23 = _mm_andnot_ps(
            _mm_cmple_ps(v21, (__m128)0i64),
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v22, v21), v22)),
              _mm_mul_ps(*(__m128 *)_xmm, v22)));
    v24 = _mm_mul_ps(v23, v21);
    v25 = _mm_mul_ps(v23, dB.m_quad);
  }
  v26 = _mm_mul_ps(v25, dA.m_quad);
  v27 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(
              (__m128)0i64,
              _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v26, v26, 85), _mm_shuffle_ps(v26, v26, 0)),
                _mm_shuffle_ps(v26, v26, 170))),
            v25),
          dA.m_quad);
  v28 = _mm_mul_ps(v27, v27);
  v29 = (float)(_mm_shuffle_ps(v28, v28, 85).m128_f32[0] + _mm_shuffle_ps(v28, v28, 0).m128_f32[0])
      + _mm_shuffle_ps(v28, v28, 170).m128_f32[0];
  if ( v29 == 0.0 )
  {
    v30 = FLOAT_N1_0;
  }
  else
  {
    distSquared = (float)(v19 - distSquared) / v29;
    v30 = t - fsqrt(distSquared);
  }
  v31 = v30 < results->m_hitFraction;
  distSquared = v30;
  if ( !v31 )
    goto $returnFalse;
  v32.m_quad = (__m128)input->m_from;
  v33.m_quad = (__m128)this->m_vertexA;
  v34.m_quad = (__m128)input->m_to;
  v35 = _mm_mul_ps(v33.m_quad, v25);
  v36 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)), _mm_shuffle_ps(v35, v35, 170));
  v37 = _mm_add_ps(
          _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(distSquared), (__m128)LODWORD(distSquared), 0),
            _mm_sub_ps(v34.m_quad, input->m_from.m_quad)),
          input->m_from.m_quad);
  v38 = _mm_mul_ps(v37, v25);
  v39 = _mm_sub_ps(
          _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v38, v38, 85), _mm_shuffle_ps(v38, v38, 0)),
            _mm_shuffle_ps(v38, v38, 170)),
          v36);
  if ( v30 >= 0.0 && v39.m128_f32[0] > 0.0 && v39.m128_f32[0] < v24.m128_f32[0] )
  {
    m_shapeKeyIndex = results->m_shapeKeyIndex;
    v41 = _mm_rcp_ps(v24);
    result->m_bool = 1;
    v42.m_quad = (__m128)this->m_vertexB;
    results->m_hitFraction = v30;
    results->m_extraInfo = 2;
    v43 = _mm_sub_ps(
            v37,
            _mm_add_ps(
              _mm_mul_ps(
                _mm_sub_ps(v42.m_quad, v33.m_quad),
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v41, v24)), v41), v39)),
              v33.m_quad));
    v44 = _mm_mul_ps(v43, v43);
    v45 = _mm_add_ps(
            _mm_add_ps(_mm_shuffle_ps(v44, v44, 85), _mm_shuffle_ps(v44, v44, 0)),
            _mm_shuffle_ps(v44, v44, 170));
    v46 = _mm_rsqrt_ps(v45);
    results->m_normal.m_quad = _mm_mul_ps(
                                 _mm_andnot_ps(
                                   _mm_cmple_ps(v45, (__m128)0i64),
                                   _mm_mul_ps(
                                     _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v46, v45), v46)),
                                     _mm_mul_ps(*(__m128 *)_xmm, v46))),
                                 v43);
    results->m_shapeKeys[m_shapeKeyIndex] = -1;
    goto LABEL_27;
  }
  v47 = _mm_mul_ps(v32.m_quad, v25);
  v48 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v47, v47, 85), _mm_shuffle_ps(v47, v47, 0)), _mm_shuffle_ps(v47, v47, 170));
  v49 = _mm_rcp_ps(v24);
  v50 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v49, v24)), v49), _mm_sub_ps(v48, v36));
  v51.m_quad = (__m128)this->m_vertexB;
  v52 = _mm_sub_ps(v32.m_quad, _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v51.m_quad, v33.m_quad), v50), v33.m_quad));
  if ( v30 < 0.0 )
  {
    v53 = _mm_mul_ps(v52, v52);
    if ( (float)((float)(_mm_shuffle_ps(v53, v53, 85).m128_f32[0] + _mm_shuffle_ps(v53, v53, 0).m128_f32[0])
               + _mm_shuffle_ps(v53, v53, 170).m128_f32[0]) > v19 )
      goto $returnFalse;
  }
  distSquared = m_radius;
  v54 = _mm_cmple_ps(v39, (__m128)0i64);
  v55 = _mm_or_ps(_mm_and_ps(v54, v33.m_quad), _mm_andnot_ps(v54, v51.m_quad));
  v56 = _mm_sub_ps(v32.m_quad, v55);
  v57 = _mm_sub_ps(_mm_sub_ps(v34.m_quad, v55), v56);
  v58 = _mm_shuffle_ps(v57, _mm_unpackhi_ps(v57, query.m_quad), 196);
  v59 = _mm_shuffle_ps(
          aabbOut.m_quad,
          _mm_unpackhi_ps(aabbOut.m_quad, _mm_shuffle_ps((__m128)LODWORD(distSquared), (__m128)LODWORD(distSquared), 0)),
          196);
  v60 = _mm_shuffle_ps((__m128)LODWORD(results->m_hitFraction), (__m128)LODWORD(results->m_hitFraction), 0);
  v61 = _mm_sub_ps(v56, v59);
  q.m_quad = v59;
  v62 = _mm_shuffle_ps(v59, v59, 255);
  pt.m_quad = v60;
  v63 = _mm_mul_ps(v58, v61);
  v64 = (__m128i)_mm_sub_ps(
                   (__m128)0i64,
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v63, v63, 85), _mm_shuffle_ps(v63, v63, 0)),
                     _mm_shuffle_ps(v63, v63, 170)));
  v65 = _mm_mul_ps(v58, v58);
  v66 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v65, v65, 85), _mm_shuffle_ps(v65, v65, 0)), _mm_shuffle_ps(v65, v65, 170));
  v67 = _mm_rcp_ps(v66);
  v68 = _mm_cmpeq_ps(v66, (__m128)0i64);
  v69 = _mm_add_ps(
          _mm_mul_ps(
            _mm_or_ps(
              _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v64, 0x1Fu), 0x1Fu), (__m128)_xmm), v68),
              _mm_andnot_ps(
                v68,
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v67, v66)), v67), (__m128)v64))),
            v58),
          v61);
  v70 = _mm_mul_ps(v69, v69);
  v71 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
              _mm_shuffle_ps(v70, v70, 170)),
            _mm_mul_ps(v62, v62)),
          _mm_sub_ps((__m128)0i64, v66));
  if ( v71.m128_f32[0] < 0.0 )
    goto $returnFalse;
  v72 = _mm_rsqrt_ps(v71);
  v73 = 0;
  v74 = 0;
  v75 = 0;
  v76 = _mm_andnot_ps(
          _mm_cmple_ps(v71, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v72, v71), v72)),
              _mm_mul_ps(v72, *(__m128 *)_xmm)),
            v71));
  v77 = _mm_add_ps(_mm_sub_ps((__m128)0i64, v76), (__m128)v64);
  v78 = _mm_and_ps(_mm_cmplt_ps(v77, (__m128)0i64), *(__m128 *)hkVector4fComparison_maskToComparison_343);
  v79 = _mm_or_ps(_mm_and_ps(_mm_add_ps(v76, (__m128)v64), v78), _mm_andnot_ps(v78, v77));
  if ( v79.m128_f32[0] >= (float)(v66.m128_f32[0] * pt.m_quad.m128_f32[0]) )
    v74 = 1;
  if ( v79.m128_f32[0] < 0.0 )
    v75 = 1;
  if ( !(v75 | v74)
    && (v80 = _mm_mul_ps(v79, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v67, v66)), v67)),
        v81 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v58, v80), v56), q.m_quad),
        v82 = _mm_mul_ps(v81, v81),
        v83 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v82, v82, 85), _mm_shuffle_ps(v82, v82, 0)),
                _mm_shuffle_ps(v82, v82, 170)),
        v84 = _mm_rsqrt_ps(v83),
        results->m_normal.m_quad = _mm_mul_ps(
                                     _mm_andnot_ps(
                                       _mm_cmple_ps(v83, (__m128)0i64),
                                       _mm_mul_ps(
                                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v84, v83), v84)),
                                         _mm_mul_ps(*(__m128 *)_xmm, v84))),
                                     v81),
        (16 * _mm_movemask_ps(v78)) | 1) )
  {
    LODWORD(results->m_hitFraction) = v80.m128_i32[0];
    v85 = results->m_shapeKeyIndex;
    LOBYTE(v73) = v39.m128_f32[0] > 0.0;
    result->m_bool = 1;
    results->m_shapeKeys[v85] = -1;
    results->m_extraInfo = v73;
  }
  else
  {
$returnFalse:
    result->m_bool = 0;
  }
LABEL_27:
  v86 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v87 = v86[1];
  if ( v87 < v86[3] )
  {
    v88 = __rdtsc();
    *(_DWORD *)(v87 + 8) = v88;
    *(_QWORD *)v87 = "Et";
    v86[1] = v87 + 16;
  }
  return result;
} *)(v87 + 8) = v88;
    *(_QWORD *)v87 = "Et";
    v86[1] = v87 + 16;
  }
  return result;
}

// File Line: 268
// RVA: 0xCF7C60
void __fastcall hkpCapsuleShape::getAabb(
        hkpCapsuleShape *this,
        hkTransformf *localToWorld,
        float tolerance,
        hkAabb *out)
{
  __m128 v4; // xmm3
  hkVector4f v5; // xmm4
  hkVector4f v6; // xmm5
  hkVector4f *p_m_vertexB; // rax
  hkVector4f v8; // xmm6
  __m128 v9; // xmm3
  hkVector4f v10; // xmm7
  __int64 i; // rdx
  __m128 m_quad; // xmm1
  __m128 v13; // xmm0
  __m128 v14; // [rsp+0h] [rbp-48h]
  __m128 v15; // [rsp+10h] [rbp-38h] BYREF

  v5.m_quad = (__m128)localToWorld->m_rotation.m_col0;
  v6.m_quad = (__m128)localToWorld->m_rotation.m_col1;
  p_m_vertexB = &this->m_vertexB;
  v4.m128_f32[0] = tolerance + this->m_radius;
  v8.m_quad = (__m128)localToWorld->m_rotation.m_col2;
  v9 = (__m128)_mm_srli_si128(_mm_slli_si128((__m128i)_mm_shuffle_ps(v4, v4, 0), 4), 4);
  v10.m_quad = (__m128)localToWorld->m_translation;
  for ( i = 1i64; i >= 0; --i )
  {
    m_quad = p_m_vertexB->m_quad;
    --p_m_vertexB;
    *(__m128 *)((char *)&p_m_vertexB[-3].m_quad + (char *)&v15 - (char *)this) = _mm_add_ps(
                                                                                   _mm_add_ps(
                                                                                     _mm_add_ps(
                                                                                       _mm_mul_ps(
                                                                                         _mm_shuffle_ps(
                                                                                           m_quad,
                                                                                           m_quad,
                                                                                           85),
                                                                                         v6.m_quad),
                                                                                       _mm_mul_ps(
                                                                                         _mm_shuffle_ps(
                                                                                           m_quad,
                                                                                           m_quad,
                                                                                           0),
                                                                                         v5.m_quad)),
                                                                                     _mm_mul_ps(
                                                                                       _mm_shuffle_ps(
                                                                                         m_quad,
                                                                                         m_quad,
                                                                                         170),
                                                                                       v8.m_quad)),
                                                                                   v10.m_quad);
  }
  v13 = _mm_min_ps(v14, v15);
  out->m_max.m_quad = _mm_add_ps(_mm_max_ps(v14, v15), v9);
  out->m_min.m_quad = _mm_sub_ps(v13, v9);
}

