// File Line: 25
// RVA: 0xCF2290
void __fastcall hkpSphereShape::hkpSphereShape(hkpSphereShape *this, float radius)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1024;
  this->m_radius = radius;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSphereShape::`vftable;
  this->m_userData = 0i64;
}

// File Line: 32
// RVA: 0xCF2A70
void __fastcall hkpSphereShape::hkpSphereShape(hkpSphereShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpConvexShape::hkpConvexShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpSphereShape::`vftable;
  this->m_type.m_storage = 0;
}

// File Line: 37
// RVA: 0xCF2AA0
void __fastcall hkpSphereShape::getFirstVertex(hkpSphereShape *this, hkVector4f *v)
{
  *v = 0i64;
}

// File Line: 44
// RVA: 0xCF22C0
hkBool *__fastcall hkpSphereShape::castRay(
        hkpSphereShape *this,
        hkBool *result,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *results)
{
  _QWORD *Value; // r9
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  _QWORD *v11; // rcx
  float v12; // xmm10_4
  __m128 v13; // xmm6
  __m128 v14; // xmm6
  __m128 v15; // xmm15
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128i v19; // xmm13
  __m128 v20; // xmm1
  __m128 v21; // xmm12
  __m128 v22; // xmm14
  __m128 v23; // xmm2
  __m128 v24; // xmm3
  __m128 v25; // xmm3
  __m128 v26; // xmm5
  __m128 v27; // xmm2
  int v28; // ecx
  int v29; // eax
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  __m128 v32; // xmm5
  __m128 v33; // xmm4
  __m128 v34; // xmm4
  __m128 v35; // xmm6
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __int64 m_shapeKeyIndex; // rax
  _QWORD *v40; // rax
  _QWORD *v41; // rcx
  _QWORD *v42; // r8
  unsigned __int64 v43; // rax
  _QWORD *v44; // rcx

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v9 < Value[3] )
  {
    *v9 = "TtrcSphere";
    v10 = __rdtsc();
    v11 = v9 + 2;
    *((_DWORD *)v11 - 2) = v10;
    Value[1] = v11;
  }
  LODWORD(v12) = _mm_shuffle_ps((__m128)LODWORD(results->m_hitFraction), (__m128)LODWORD(results->m_hitFraction), 0).m128_u32[0];
  v13 = _mm_sub_ps(input->m_to.m_quad, input->m_from.m_quad);
  v14 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, query.m_quad), 196);
  v15 = _mm_shuffle_ps(
          aabbOut.m_quad,
          _mm_unpackhi_ps(
            aabbOut.m_quad,
            _mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0)),
          196);
  v16 = _mm_sub_ps(input->m_from.m_quad, v15);
  v17 = _mm_shuffle_ps(v15, v15, 255);
  v18 = _mm_mul_ps(v14, v16);
  v19 = (__m128i)_mm_sub_ps(
                   (__m128)0i64,
                   _mm_add_ps(
                     _mm_add_ps(_mm_shuffle_ps(v18, v18, 85), _mm_shuffle_ps(v18, v18, 0)),
                     _mm_shuffle_ps(v18, v18, 170)));
  v20 = _mm_mul_ps(v14, v14);
  v21 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v20, v20, 85), _mm_shuffle_ps(v20, v20, 0)), _mm_shuffle_ps(v20, v20, 170));
  v22 = _mm_rcp_ps(v21);
  v23 = _mm_cmpeq_ps(v21, (__m128)0i64);
  v24 = _mm_add_ps(
          _mm_mul_ps(
            _mm_or_ps(
              _mm_and_ps(_mm_xor_ps((__m128)_mm_slli_epi32(_mm_srli_epi32(v19, 0x1Fu), 0x1Fu), (__m128)_xmm), v23),
              _mm_andnot_ps(
                v23,
                _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v21)), v22), (__m128)v19))),
            v14),
          v16);
  v25 = _mm_mul_ps(v24, v24);
  v26 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_shuffle_ps(v25, v25, 85), _mm_shuffle_ps(v25, v25, 0)),
              _mm_shuffle_ps(v25, v25, 170)),
            _mm_mul_ps(v17, v17)),
          _mm_sub_ps((__m128)0i64, v21));
  if ( v26.m128_f32[0] < 0.0 )
    goto LABEL_11;
  v27 = _mm_rsqrt_ps(v26);
  v28 = 0;
  v29 = 0;
  v30 = _mm_andnot_ps(
          _mm_cmple_ps(v26, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v27), v27)),
              _mm_mul_ps(v27, *(__m128 *)_xmm)),
            v26));
  v31 = _mm_add_ps(_mm_sub_ps((__m128)0i64, v30), (__m128)v19);
  v32 = _mm_and_ps(_mm_cmplt_ps(v31, (__m128)0i64), *(__m128 *)hkVector4fComparison_maskToComparison_339);
  v33 = _mm_or_ps(_mm_and_ps(_mm_add_ps(v30, (__m128)v19), v32), _mm_andnot_ps(v32, v31));
  if ( v33.m128_f32[0] >= (float)(v12 * v21.m128_f32[0]) )
    v29 = 1;
  if ( v33.m128_f32[0] < 0.0 )
    v28 = 1;
  if ( v28 | v29
    || (v34 = _mm_mul_ps(v33, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v21)), v22)),
        v35 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v14, v34), input->m_from.m_quad), v15),
        v36 = _mm_mul_ps(v35, v35),
        v37 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                _mm_shuffle_ps(v36, v36, 170)),
        v38 = _mm_rsqrt_ps(v37),
        results->m_normal.m_quad = _mm_mul_ps(
                                     _mm_andnot_ps(
                                       _mm_cmple_ps(v37, (__m128)0i64),
                                       _mm_mul_ps(
                                         _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v38, v37), v38)),
                                         _mm_mul_ps(v38, *(__m128 *)_xmm))),
                                     v35),
        !((16 * _mm_movemask_ps(v32)) | 1)) )
  {
LABEL_11:
    result->m_bool = 0;
  }
  else
  {
    LODWORD(results->m_hitFraction) = v34.m128_i32[0];
    m_shapeKeyIndex = results->m_shapeKeyIndex;
    result->m_bool = 1;
    results->m_shapeKeys[m_shapeKeyIndex] = -1;
  }
  v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v41 = (_QWORD *)v40[1];
  v42 = v40;
  if ( (unsigned __int64)v41 < v40[3] )
  {
    *v41 = "Et";
    v43 = __rdtsc();
    v44 = v41 + 2;
    *((_DWORD *)v44 - 2) = v43;
    v42[1] = v44;
  }
  return result;
}

// File Line: 51
// RVA: 0xCF2630
hkVector4fComparison *__fastcall hkpSphereShape::castRayBundle(
        hkpSphereShape *this,
        hkVector4fComparison *result,
        hkpShapeRayBundleCastInput *input,
        hkpShapeRayBundleCastOutput *results,
        hkVector4fComparison *mask)
{
  _QWORD *Value; // r9
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  _QWORD *v12; // rcx
  __m128 m_quad; // xmm8
  __m128 v14; // xmm6
  __m128 v15; // xmm14
  __m128 v16; // xmm15
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm4
  __m128 v20; // xmm9
  __m128 v21; // xmm12
  __m128 v22; // xmm5
  __m128 v23; // xmm1
  __m128 v24; // xmm4
  __m128 v25; // xmm11
  __m128 v26; // xmm2
  __m128 v27; // xmm7
  __m128 v28; // xmm11
  __m128 v29; // xmm1
  __m128 v30; // xmm7
  __m128 v31; // xmm8
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  __m128 v34; // xmm3
  __m128 v35; // xmm6
  __m128 v36; // xmm2
  __m128 v37; // xmm6
  __m128 v38; // xmm4
  __m128 v39; // xmm1
  __m128 v40; // xmm5
  __m128 v41; // xmm1
  __m128 v42; // xmm4
  __m128 v43; // xmm10
  __m128 v44; // xmm2
  __m128 v45; // xmm3
  __m128 v46; // xmm0
  __m128 v47; // xmm3
  __m128 v48; // xmm0
  __m128 v49; // xmm13
  __m128 v50; // xmm2
  __m128 v51; // xmm5
  __m128 v52; // xmm3
  __m128 v53; // xmm1
  __m128 v54; // xmm5
  __m128 v55; // xmm0
  hkVector4f v56; // xmm2
  __m128 v57; // xmm3
  hkVector4f v58; // xmm1
  hkVector4f v59; // xmm6
  hkVector4f v60; // xmm5
  char v61; // cl
  _QWORD *v62; // r8
  _QWORD *v63; // rcx
  unsigned __int64 v64; // rax
  _QWORD *v65; // rcx
  __m128 v67; // [rsp+20h] [rbp-D8h]
  __m128 v68; // [rsp+30h] [rbp-C8h]
  __m128 v69; // [rsp+40h] [rbp-B8h]

  Value = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)Value[1];
  if ( (unsigned __int64)v10 < Value[3] )
  {
    *v10 = "TtrcSphereBundle";
    v11 = __rdtsc();
    v12 = v10 + 2;
    *((_DWORD *)v12 - 2) = v11;
    Value[1] = v12;
  }
  m_quad = input->m_from.m_vertices[0].m_quad;
  v14 = input->m_from.m_vertices[1].m_quad;
  v15 = input->m_to.m_vertices[0].m_quad;
  v16 = input->m_to.m_vertices[1].m_quad;
  v17 = _mm_sub_ps(input->m_to.m_vertices[2].m_quad, input->m_from.m_vertices[2].m_quad);
  *result = (hkVector4fComparison)mask->m_mask;
  v67 = m_quad;
  v18 = _mm_sub_ps(v16, v14);
  v19 = _mm_sub_ps(v15, m_quad);
  v69 = _mm_shuffle_ps((__m128)LODWORD(this->m_radius), (__m128)LODWORD(this->m_radius), 0);
  v20 = _mm_mul_ps(v69, v69);
  v21 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v18, v18), _mm_mul_ps(v19, v19)), _mm_mul_ps(v17, v17));
  v22 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(v14, v18), _mm_mul_ps(m_quad, v19)),
          _mm_mul_ps(input->m_from.m_vertices[2].m_quad, v17));
  v23 = _mm_mul_ps(v22, v22);
  v24 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  v25 = _mm_cmplt_ps(
          _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(FLOAT_100_0), (__m128)LODWORD(FLOAT_100_0), 0),
            _mm_mul_ps(v21, v20)),
          v23);
  v26 = _mm_and_ps(_mm_xor_ps(v22, v24), v25);
  v27 = v25;
  v28 = _mm_andnot_ps(v25, v23);
  v29 = _mm_rcp_ps(v21);
  v68 = v26;
  v30 = _mm_andnot_ps(v27, v22);
  v31 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, v29)), v29);
  v32 = _mm_mul_ps(v31, v26);
  v33 = _mm_sub_ps(query.m_quad, v32);
  v34 = _mm_add_ps(_mm_mul_ps(v67, v33), _mm_mul_ps(v15, v32));
  v35 = _mm_add_ps(_mm_mul_ps(v14, v33), _mm_mul_ps(v16, v32));
  v36 = _mm_add_ps(
          _mm_mul_ps(input->m_from.m_vertices[2].m_quad, v33),
          _mm_mul_ps(input->m_to.m_vertices[2].m_quad, v32));
  v37 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v35, v35), _mm_mul_ps(v34, v34)), _mm_mul_ps(v36, v36)), v20),
            _mm_xor_ps(v21, v24)),
          v28);
  v38 = _mm_cmplt_ps((__m128)0i64, v37);
  v39 = _mm_rsqrt_ps(v37);
  v40 = _mm_and_ps(result->m_mask, v38);
  v41 = _mm_sub_ps(
          _mm_sub_ps(v68, v30),
          _mm_and_ps(
            _mm_andnot_ps(
              _mm_cmple_ps(v37, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v37, v39), v39)),
                  _mm_mul_ps(*(__m128 *)_xmm, v39)),
                v37)),
            v38));
  v42 = _mm_mul_ps(v41, v31);
  v43 = _mm_sub_ps(query.m_quad, v42);
  v44 = _mm_mul_ps(input->m_from.m_vertices[1].m_quad, v43);
  v45 = _mm_mul_ps(input->m_from.m_vertices[2].m_quad, v43);
  v46 = input->m_to.m_vertices[2].m_quad;
  result->m_mask = _mm_and_ps(
                     _mm_and_ps(
                       _mm_cmplt_ps(
                         v41,
                         _mm_mul_ps(
                           _mm_unpacklo_ps(
                             _mm_unpacklo_ps(
                               (__m128)LODWORD(results->m_outputs[0].m_hitFraction),
                               (__m128)LODWORD(results->m_outputs[2].m_hitFraction)),
                             _mm_unpacklo_ps(
                               (__m128)LODWORD(results->m_outputs[1].m_hitFraction),
                               (__m128)LODWORD(results->m_outputs[3].m_hitFraction))),
                           v21)),
                       v40),
                     _mm_cmple_ps((__m128)0i64, v41));
  v47 = _mm_add_ps(v45, _mm_mul_ps(v46, v42));
  v48 = _mm_rcp_ps(v69);
  v49 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v69, v48)), v48);
  v50 = _mm_mul_ps(_mm_add_ps(v44, _mm_mul_ps(v16, v42)), v49);
  v51 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v67, v43), _mm_mul_ps(v15, v42)), v49);
  v52 = _mm_mul_ps(v47, v49);
  v53 = _mm_shuffle_ps(v51, v50, 68);
  v54 = _mm_shuffle_ps(v51, v50, 238);
  v55 = _mm_shuffle_ps(v52, (__m128)0i64, 68);
  v56.m_quad = _mm_shuffle_ps(v53, v55, 136);
  v57 = _mm_shuffle_ps(v52, (__m128)0i64, 238);
  v58.m_quad = _mm_shuffle_ps(v53, v55, 221);
  v59.m_quad = _mm_shuffle_ps(v54, v57, 136);
  v60.m_quad = _mm_shuffle_ps(v54, v57, 221);
  v61 = _mm_movemask_ps(result->m_mask);
  if ( (v61 & 1) != 0 )
  {
    LODWORD(results->m_outputs[0].m_hitFraction) = v42.m128_i32[0];
    results->m_outputs[0].m_normal = (hkVector4f)v56.m_quad;
    results->m_outputs[0].m_shapeKeys[results->m_outputs[0].m_shapeKeyIndex] = -1;
  }
  if ( (v61 & 2) != 0 )
  {
    LODWORD(results->m_outputs[1].m_hitFraction) = _mm_shuffle_ps(v42, v42, 85).m128_u32[0];
    results->m_outputs[1].m_normal = (hkVector4f)v58.m_quad;
    results->m_outputs[1].m_shapeKeys[results->m_outputs[1].m_shapeKeyIndex] = -1;
  }
  if ( (v61 & 4) != 0 )
  {
    LODWORD(results->m_outputs[2].m_hitFraction) = _mm_shuffle_ps(v42, v42, 170).m128_u32[0];
    results->m_outputs[2].m_normal = (hkVector4f)v59.m_quad;
    results->m_outputs[2].m_shapeKeys[results->m_outputs[2].m_shapeKeyIndex] = -1;
  }
  if ( (v61 & 8) != 0 )
  {
    LODWORD(results->m_outputs[3].m_hitFraction) = _mm_shuffle_ps(v42, v42, 255).m128_u32[0];
    results->m_outputs[3].m_normal = (hkVector4f)v60.m_quad;
    results->m_outputs[3].m_shapeKeys[results->m_outputs[3].m_shapeKeyIndex] = -1;
  }
  v62 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v63 = (_QWORD *)v62[1];
  if ( (unsigned __int64)v63 < v62[3] )
  {
    *v63 = "Et";
    v64 = __rdtsc();
    v65 = v63 + 2;
    *((_DWORD *)v65 - 2) = v64;
    v62[1] = v65;
  }
  return result;
}

