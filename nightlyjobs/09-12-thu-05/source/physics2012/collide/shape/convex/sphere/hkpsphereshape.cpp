// File Line: 25
// RVA: 0xCF2290
void __fastcall hkpSphereShape::hkpSphereShape(hkpSphereShape *this, float radius)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  *(_DWORD *)&this->m_type.m_storage = 1024;
  this->m_radius = radius;
  this->vfptr = (hkBaseObjectVtbl *)&hkpSphereShape::`vftable';
  this->m_userData = 0i64;
}

// File Line: 32
// RVA: 0xCF2A70
void __fastcall hkpSphereShape::hkpSphereShape(hkpSphereShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpSphereShape *v2; // rbx

  v2 = this;
  hkpConvexShape::hkpConvexShape((hkpConvexShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpSphereShape::`vftable';
  v2->m_type.m_storage = 0;
}

// File Line: 37
// RVA: 0xCF2AA0
void __fastcall hkpSphereShape::getFirstVertex(hkpSphereShape *this, hkVector4f *v)
{
  *v = 0i64;
}

// File Line: 44
// RVA: 0xCF22C0
hkBool *__fastcall hkpSphereShape::castRay(hkpSphereShape *this, hkBool *result, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *results)
{
  hkpSphereShape *v4; // rbp
  __m128 *v5; // rdi
  hkpShapeRayCastInput *v6; // rsi
  hkBool *v7; // rbx
  _QWORD *v8; // r9
  _QWORD *v9; // rcx
  unsigned __int64 v10; // rax
  signed __int64 v11; // rcx
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
  signed int v28; // ecx
  signed int v29; // eax
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  __m128 v32; // xmm5
  __m128 v33; // xmm4
  __m128 v34; // xmm4
  __m128 v35; // xmm6
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm1
  __int64 v39; // rax
  _QWORD *v40; // rax
  _QWORD *v41; // rcx
  _QWORD *v42; // r8
  unsigned __int64 v43; // rax
  signed __int64 v44; // rcx

  v4 = this;
  v5 = &results->m_normal.m_quad;
  v6 = input;
  v7 = result;
  v8 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v9 = (_QWORD *)v8[1];
  if ( (unsigned __int64)v9 < v8[3] )
  {
    *v9 = "TtrcSphere";
    v10 = __rdtsc();
    v11 = (signed __int64)(v9 + 2);
    *(_DWORD *)(v11 - 8) = v10;
    v8[1] = v11;
  }
  LODWORD(v12) = (unsigned __int128)_mm_shuffle_ps((__m128)v5[1].m128_u32[0], (__m128)v5[1].m128_u32[0], 0);
  v13 = _mm_sub_ps(v6->m_to.m_quad, v6->m_from.m_quad);
  v14 = _mm_shuffle_ps(v13, _mm_unpackhi_ps(v13, query.m_quad), 196);
  v15 = _mm_shuffle_ps(
          aabbOut.m_quad,
          _mm_unpackhi_ps(
            aabbOut.m_quad,
            _mm_shuffle_ps((__m128)LODWORD(v4->m_radius), (__m128)LODWORD(v4->m_radius), 0)),
          196);
  v16 = _mm_sub_ps(v6->m_from.m_quad, v15);
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
  v23 = _mm_cmpeqps(v21, (__m128)0i64);
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
    goto LABEL_17;
  v27 = _mm_rsqrt_ps(v26);
  v28 = 0;
  v29 = 0;
  v30 = _mm_andnot_ps(
          _mm_cmpleps(v26, (__m128)0i64),
          _mm_mul_ps(
            _mm_mul_ps(
              _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v26, v27), v27)),
              _mm_mul_ps(v27, *(__m128 *)_xmm)),
            v26));
  v31 = _mm_add_ps(_mm_sub_ps((__m128)0i64, v30), (__m128)v19);
  v32 = _mm_and_ps(_mm_cmpltps(v31, (__m128)0i64), *(__m128 *)hkVector4fComparison_maskToComparison_339);
  v33 = _mm_or_ps(_mm_and_ps(_mm_add_ps(v30, (__m128)v19), v32), _mm_andnot_ps(v32, v31));
  if ( v33.m128_f32[0] >= (float)(v12 * v21.m128_f32[0]) )
    v29 = 1;
  if ( v33.m128_f32[0] < 0.0 )
    v28 = 1;
  if ( v28 | v29
    || (v34 = _mm_mul_ps(v33, _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v21)), v22)),
        v35 = _mm_sub_ps(_mm_add_ps(_mm_mul_ps(v14, v34), v6->m_from.m_quad), v15),
        v36 = _mm_mul_ps(v35, v35),
        v37 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v36, v36, 85), _mm_shuffle_ps(v36, v36, 0)),
                _mm_shuffle_ps(v36, v36, 170)),
        v38 = _mm_rsqrt_ps(v37),
        *v5 = _mm_mul_ps(
                _mm_andnot_ps(
                  _mm_cmpleps(v37, (__m128)0i64),
                  _mm_mul_ps(
                    _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v38, v37), v38)),
                    _mm_mul_ps(v38, *(__m128 *)_xmm))),
                v35),
        !(16 * _mm_movemask_ps(v32) | 1)) )
  {
LABEL_17:
    v7->m_bool = 0;
  }
  else
  {
    v5[1].m128_i32[0] = v34.m128_i32[0];
    v39 = v5[4].m128_i32[0];
    v7->m_bool = 1;
    v5[2].m128_i32[v39] = -1;
  }
  v40 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v41 = (_QWORD *)v40[1];
  v42 = v40;
  if ( (unsigned __int64)v41 < v40[3] )
  {
    *v41 = "Et";
    v43 = __rdtsc();
    v44 = (signed __int64)(v41 + 2);
    *(_DWORD *)(v44 - 8) = v43;
    v42[1] = v44;
  }
  return v7;
}

// File Line: 51
// RVA: 0xCF2630
__m128i *__fastcall hkpSphereShape::castRayBundle(hkpSphereShape *this, hkVector4fComparison *result, hkpShapeRayBundleCastInput *input, hkpShapeRayBundleCastOutput *results, hkVector4fComparison *mask)
{
  hkpSphereShape *v5; // rbp
  hkpShapeRayBundleCastOutput *v6; // rbx
  hkpShapeRayBundleCastInput *v7; // rsi
  __m128i *v8; // rdi
  _QWORD *v9; // r9
  _QWORD *v10; // rcx
  unsigned __int64 v11; // rax
  signed __int64 v12; // rcx
  __m128 v13; // xmm8
  __m128 v14; // xmm6
  __m128 v15; // xmm14
  __m128 v16; // xmm15
  __m128 v17; // xmm3
  __m128 v18; // ST20_16
  __m128 v19; // xmm2
  __m128 v20; // xmm4
  __m128 v21; // ST40_16
  __m128 v22; // xmm9
  __m128 v23; // xmm12
  __m128 v24; // xmm5
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm11
  __m128 v28; // xmm2
  __m128 v29; // xmm7
  __m128 v30; // xmm11
  __m128 v31; // xmm1
  __m128 v32; // ST30_16
  __m128 v33; // xmm7
  __m128 v34; // xmm8
  __m128 v35; // xmm1
  __m128 v36; // xmm0
  __m128 v37; // xmm3
  __m128 v38; // xmm6
  __m128 v39; // xmm2
  __m128 v40; // xmm6
  __m128 v41; // xmm4
  __m128 v42; // xmm1
  __m128 v43; // xmm5
  __m128 v44; // xmm4
  __m128 v45; // xmm1
  __m128 v46; // xmm0
  __m128 v47; // xmm4
  __m128 v48; // xmm10
  __m128 v49; // xmm2
  __m128 v50; // xmm3
  __m128 v51; // xmm1
  __m128 v52; // xmm0
  __m128 v53; // xmm3
  __m128 v54; // xmm0
  __m128 v55; // xmm13
  __m128 v56; // xmm2
  __m128 v57; // xmm5
  __m128 v58; // xmm3
  __m128 v59; // xmm1
  __m128 v60; // xmm5
  __m128 v61; // xmm0
  __m128 v62; // xmm2
  __m128 v63; // xmm3
  __m128 v64; // xmm1
  __m128 v65; // xmm6
  __m128 v66; // xmm5
  char v67; // cl
  _QWORD *v68; // r8
  _QWORD *v69; // rcx
  unsigned __int64 v70; // rax
  signed __int64 v71; // rcx

  v5 = this;
  v6 = results;
  v7 = input;
  v8 = (__m128i *)result;
  v9 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v10 = (_QWORD *)v9[1];
  if ( (unsigned __int64)v10 < v9[3] )
  {
    *v10 = "TtrcSphereBundle";
    v11 = __rdtsc();
    v12 = (signed __int64)(v10 + 2);
    *(_DWORD *)(v12 - 8) = v11;
    v9[1] = v12;
  }
  v13 = v7->m_from.m_vertices[0].m_quad;
  v14 = v7->m_from.m_vertices[1].m_quad;
  v15 = v7->m_to.m_vertices[0].m_quad;
  v16 = v7->m_to.m_vertices[1].m_quad;
  v17 = _mm_sub_ps(v7->m_to.m_vertices[2].m_quad, v7->m_from.m_vertices[2].m_quad);
  _mm_store_si128(v8, (__m128i)mask->m_mask);
  v18 = v13;
  v19 = _mm_sub_ps(v16, v14);
  v20 = _mm_sub_ps(v15, v13);
  v21 = _mm_shuffle_ps((__m128)LODWORD(v5->m_radius), (__m128)LODWORD(v5->m_radius), 0);
  v22 = _mm_mul_ps(v21, v21);
  v23 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v19, v19), _mm_mul_ps(v20, v20)), _mm_mul_ps(v17, v17));
  v24 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(v14, v19), _mm_mul_ps(v13, v20)),
          _mm_mul_ps(v7->m_from.m_vertices[2].m_quad, v17));
  v25 = _mm_mul_ps(v24, v24);
  v26 = (__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0);
  v27 = _mm_cmpltps(
          _mm_mul_ps(
            _mm_shuffle_ps((__m128)LODWORD(FLOAT_100_0), (__m128)LODWORD(FLOAT_100_0), 0),
            _mm_mul_ps(v23, v22)),
          v25);
  v28 = _mm_and_ps(_mm_xor_ps(v24, v26), v27);
  v29 = v27;
  v30 = _mm_andnot_ps(v27, v25);
  v31 = _mm_rcp_ps(v23);
  v32 = v28;
  v33 = _mm_andnot_ps(v29, v24);
  v34 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v31)), v31);
  v35 = _mm_mul_ps(v34, v28);
  v36 = _mm_sub_ps(query.m_quad, v35);
  v37 = _mm_add_ps(_mm_mul_ps(v18, v36), _mm_mul_ps(v15, v35));
  v38 = _mm_add_ps(_mm_mul_ps(v14, v36), _mm_mul_ps(v16, v35));
  v39 = _mm_add_ps(_mm_mul_ps(v7->m_from.m_vertices[2].m_quad, v36), _mm_mul_ps(v7->m_to.m_vertices[2].m_quad, v35));
  v40 = _mm_add_ps(
          _mm_mul_ps(
            _mm_sub_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v38, v38), _mm_mul_ps(v37, v37)), _mm_mul_ps(v39, v39)), v22),
            _mm_xor_ps(v23, v26)),
          v30);
  v41 = _mm_cmpltps((__m128)0i64, v40);
  v42 = _mm_rsqrt_ps(v40);
  v43 = _mm_and_ps(*(__m128 *)v8, v41);
  v44 = _mm_sub_ps(
          _mm_sub_ps(v32, v33),
          _mm_and_ps(
            _mm_andnot_ps(
              _mm_cmpleps(v40, (__m128)0i64),
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v40, v42), v42)),
                  _mm_mul_ps(*(__m128 *)_xmm, v42)),
                v40)),
            v41));
  v45 = v44;
  v46 = _mm_cmpleps((__m128)0i64, v44);
  v47 = _mm_mul_ps(v44, v34);
  v48 = _mm_sub_ps(query.m_quad, v47);
  v49 = _mm_mul_ps(v7->m_from.m_vertices[1].m_quad, v48);
  v50 = _mm_mul_ps(v7->m_from.m_vertices[2].m_quad, v48);
  v51 = _mm_and_ps(
          _mm_and_ps(
            _mm_cmpltps(
              v45,
              _mm_mul_ps(
                _mm_unpacklo_ps(
                  _mm_unpacklo_ps(
                    (__m128)LODWORD(v6->m_outputs[0].m_hitFraction),
                    (__m128)LODWORD(v6->m_outputs[2].m_hitFraction)),
                  _mm_unpacklo_ps(
                    (__m128)LODWORD(v6->m_outputs[1].m_hitFraction),
                    (__m128)LODWORD(v6->m_outputs[3].m_hitFraction))),
                v23)),
            v43),
          v46);
  v52 = v7->m_to.m_vertices[2].m_quad;
  *v8 = (__m128i)v51;
  v53 = _mm_add_ps(v50, _mm_mul_ps(v52, v47));
  v54 = _mm_rcp_ps(v21);
  v55 = _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v21, v54)), v54);
  v56 = _mm_mul_ps(_mm_add_ps(v49, _mm_mul_ps(v16, v47)), v55);
  v57 = _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v18, v48), _mm_mul_ps(v15, v47)), v55);
  v58 = _mm_mul_ps(v53, v55);
  v59 = _mm_shuffle_ps(v57, v56, 68);
  v60 = _mm_shuffle_ps(v57, v56, 238);
  v61 = _mm_shuffle_ps(v58, (__m128)0i64, 68);
  v62 = _mm_shuffle_ps(v59, v61, 136);
  v63 = _mm_shuffle_ps(v58, (__m128)0i64, 238);
  v64 = _mm_shuffle_ps(v59, v61, 221);
  v65 = _mm_shuffle_ps(v60, v63, 136);
  v66 = _mm_shuffle_ps(v60, v63, 221);
  v67 = _mm_movemask_ps(*(__m128 *)v8);
  if ( v67 & 1 )
  {
    LODWORD(v6->m_outputs[0].m_hitFraction) = v47.m128_i32[0];
    v6->m_outputs[0].m_normal.m_quad = v62;
    v6->m_outputs[0].m_shapeKeys[v6->m_outputs[0].m_shapeKeyIndex] = -1;
  }
  if ( v67 & 2 )
  {
    LODWORD(v6->m_outputs[1].m_hitFraction) = (unsigned __int128)_mm_shuffle_ps(v47, v47, 85);
    v6->m_outputs[1].m_normal.m_quad = v64;
    v6->m_outputs[1].m_shapeKeys[v6->m_outputs[1].m_shapeKeyIndex] = -1;
  }
  if ( v67 & 4 )
  {
    LODWORD(v6->m_outputs[2].m_hitFraction) = (unsigned __int128)_mm_shuffle_ps(v47, v47, 170);
    v6->m_outputs[2].m_normal.m_quad = v65;
    v6->m_outputs[2].m_shapeKeys[v6->m_outputs[2].m_shapeKeyIndex] = -1;
  }
  if ( v67 & 8 )
  {
    LODWORD(v6->m_outputs[3].m_hitFraction) = (unsigned __int128)_mm_shuffle_ps(v47, v47, 255);
    v6->m_outputs[3].m_normal.m_quad = v66;
    v6->m_outputs[3].m_shapeKeys[v6->m_outputs[3].m_shapeKeyIndex] = -1;
  }
  v68 = TlsGetValue(hkMonitorStream__m_instance.m_slotID);
  v69 = (_QWORD *)v68[1];
  if ( (unsigned __int64)v69 < v68[3] )
  {
    *v69 = "Et";
    v70 = __rdtsc();
    v71 = (signed __int64)(v69 + 2);
    *(_DWORD *)(v71 - 8) = v70;
    v68[1] = v71;
  }
  return v8;
}

