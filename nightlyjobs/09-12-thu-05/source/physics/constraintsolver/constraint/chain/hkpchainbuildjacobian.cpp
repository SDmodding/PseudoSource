// File Line: 30
// RVA: 0x1329960
void __fastcall buildConstraintMatrixLuDecompositionForBallAndSocketChain(
        int numConstraints,
        float cfm,
        hkp1Lin2AngJacobian *j,
        hkpVelocityAccumulatorOffset *va,
        hkpVelocityAccumulator *accumBase,
        hkpConstraintChainMatrixTriple *triple,
        int bufferSize)
{
  __m128 v7; // xmm10
  __m128 v9; // xmm12
  __m128 v10; // xmm0
  __m128 v11; // xmm14
  __m128 v12; // xmm15
  __m128 v13; // xmm13
  int v14; // r12d
  __m128 *p_m_quad; // rbp
  __int64 m_offset; // rsi
  __int64 v17; // rdi
  hkpVelocityAccumulatorOffset *v18; // r15
  __int64 v19; // r10
  __m128 *v20; // r11
  __m128 *v21; // r9
  __int64 v22; // rbx
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __m128 v25; // xmm3
  __m128 *v26; // rcx
  __m128 *v27; // rdx
  __m128 *v28; // rax
  __int64 v29; // r8
  __m128 v30; // xmm7
  __m128 v31; // xmm4
  __m128 v32; // xmm1
  __m128 v33; // xmm1
  __m128 v34; // xmm2
  int v35; // ebx
  __m128 v36; // xmm6
  __m128 v37; // xmm7
  __m128 v38; // xmm4
  __m128 v39; // xmm11
  __m128 v40; // xmm8
  __m128 v41; // xmm9
  __m128 v42; // xmm6
  __m128 v43; // xmm10
  __m128 v44; // xmm11
  __int128 *v45; // rdx
  __int64 v46; // rax
  __m128 v47; // xmm12
  __m128 v48; // xmm13
  __m128 v49; // xmm14
  hkp1Lin2AngJacobian *v50; // rcx
  __m128 v51; // xmm15
  __m128 v52; // xmm7
  __m128 m_quad; // xmm1
  __m128 v54; // xmm2
  __m128 v55; // xmm5
  __m128 v56; // xmm3
  __m128 v57; // xmm1
  hkVector4f *v58; // rdi
  __m128 v59; // xmm0
  __m128 v60; // xmm1
  __m128 v61; // xmm5
  __m128 v62; // xmm3
  __m128 v63; // xmm11
  __m128 v64; // xmm8
  __m128 v65; // xmm9
  __m128 v66; // xmm2
  __m128 v67; // xmm3
  __m128 v68; // xmm1
  int v69; // [rsp+20h] [rbp-1E8h]
  hkMatrix3f *thisMatrix; // [rsp+28h] [rbp-1E0h]
  hkVector4f *p_m_col2; // [rsp+30h] [rbp-1D8h]
  __m128 v72; // [rsp+40h] [rbp-1C8h]
  __m128 v73; // [rsp+50h] [rbp-1B8h]
  __m128 v74; // [rsp+60h] [rbp-1A8h]
  __m128 v75; // [rsp+70h] [rbp-198h]
  __m128 v76; // [rsp+80h] [rbp-188h]
  __m128 v77; // [rsp+90h] [rbp-178h]
  __m128 v78; // [rsp+A0h] [rbp-168h] BYREF
  __m128 v79; // [rsp+B0h] [rbp-158h]
  __m128 v80; // [rsp+C0h] [rbp-148h]
  __m128 v81; // [rsp+D0h] [rbp-138h]
  __m128 v82; // [rsp+E0h] [rbp-128h]
  __m128 v83; // [rsp+F0h] [rbp-118h]
  __m128 v84; // [rsp+100h] [rbp-108h] BYREF
  __m128 v85; // [rsp+110h] [rbp-F8h]
  __m128 v86; // [rsp+120h] [rbp-E8h]

  v7 = 0i64;
  v9 = _mm_shuffle_ps((__m128)LODWORD(cfm), (__m128)LODWORD(cfm), 0);
  v72 = 0i64;
  v76 = 0i64;
  v10 = (__m128)LODWORD(FLOAT_1_1920929eN7);
  v73 = 0i64;
  v11 = 0i64;
  v69 = 0;
  v74 = 0i64;
  v12 = 0i64;
  v77 = 0i64;
  v13 = 0i64;
  v75 = 0i64;
  v82 = v9;
  v10.m128_f32[0] = fsqrt(0.00000011920929);
  v83 = _mm_shuffle_ps(v10, v10, 0);
  if ( numConstraints > 0 )
  {
    v14 = 0;
    p_m_quad = &j[1].m_angular[1].m_quad;
    p_m_col2 = &triple->m_diagonalInv.m_col2;
    thisMatrix = &triple->m_diagonalInv;
    do
    {
      m_offset = va->m_offset;
      v17 = va[1].m_offset;
      v18 = va + 1;
      v19 = 0i64;
      v20 = &v84;
      v21 = p_m_quad - 4;
      v22 = 3i64;
      do
      {
        if ( v19 < 3 )
        {
          v23 = v21[-1];
          v24 = v21[1];
          v25 = *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v17);
          v26 = v20;
          v27 = v20;
          v28 = v21;
          v29 = 3 - v19;
          v30 = *v21;
          v31 = *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + m_offset);
          do
          {
            v32 = v28[-1];
            v26 = (__m128 *)((char *)v26 + 4);
            v28 += 3;
            ++v27;
            v33 = _mm_mul_ps(v32, v23);
            v34 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v25, v25, 255), v33),
                      _mm_mul_ps(_mm_shuffle_ps(v31, v31, 255), v33)),
                    _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v28[-2], v24), v25), _mm_mul_ps(_mm_mul_ps(v30, v28[-3]), v31)));
            v33.m128_f32[0] = (float)(_mm_shuffle_ps(v34, v34, 85).m128_f32[0] + _mm_shuffle_ps(v34, v34, 0).m128_f32[0])
                            + _mm_shuffle_ps(v34, v34, 170).m128_f32[0];
            v27[-1].m128_i32[0] = v33.m128_i32[0];
            v26[-1].m128_i32[3] = v33.m128_i32[0];
            --v29;
          }
          while ( v29 );
        }
        ++v19;
        v21 += 3;
        v20 = (__m128 *)((char *)v20 + 20);
        --v22;
      }
      while ( v22 );
      v39 = v84;
      v35 = v69;
      v36 = v7;
      v37 = v7;
      v78 = v7;
      v80 = v7;
      v38 = _mm_add_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  *(__m128 *)&hkVector4fComparison_maskToComparison_576[16],
                  _mm_or_ps(
                    _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v84),
                    _mm_and_ps(v85, *(__m128 *)&hkVector4fComparison_maskToComparison_576[8]))),
                _mm_and_ps(v86, *(__m128 *)&hkVector4fComparison_maskToComparison_576[16])),
              v9);
      v39.m128_f32[0] = v38.m128_f32[0];
      v79 = v7;
      v81 = v39;
      v40 = _mm_or_ps(
              _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v38),
              _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v85));
      v41 = _mm_or_ps(
              _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v38),
              _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v86));
      if ( v69 < numConstraints - 1 )
      {
        v42 = *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v17);
        v43 = p_m_quad[1];
        v44 = p_m_quad[3];
        v45 = (__int128 *)&v78;
        v46 = 3i64;
        v47 = p_m_quad[-2];
        v48 = *p_m_quad;
        v49 = p_m_quad[-5];
        v50 = &j[v14 + 3];
        v51 = p_m_quad[-3];
        v52 = _mm_shuffle_ps(v42, v42, 255);
        do
        {
          m_quad = v50->m_linear0.m_quad;
          v54 = v50->m_angular[0].m_quad;
          ++v45;
          ++v50;
          v55 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v44, v54), v42), _mm_mul_ps(_mm_mul_ps(v43, m_quad), v52));
          v56 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v48, v54), v42), _mm_mul_ps(_mm_mul_ps(v47, m_quad), v52));
          v57 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v51, v54), v42), _mm_mul_ps(_mm_mul_ps(v49, m_quad), v52));
          *(v45 - 1) = (__int128)_mm_movelh_ps(
                                   _mm_unpacklo_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
                                       _mm_shuffle_ps(v57, v57, 170)),
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v56, v56, 85), _mm_shuffle_ps(v56, v56, 0)),
                                       _mm_shuffle_ps(v56, v56, 170))),
                                   _mm_unpacklo_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                                       _mm_shuffle_ps(v55, v55, 170)),
                                     aabbOut.m_quad));
          --v46;
        }
        while ( v46 );
        v7 = v80;
        v37 = v79;
        v36 = v78;
        v39 = v81;
        v9 = v82;
        v13 = v75;
        v11 = v74;
        v12 = v77;
      }
      v58 = p_m_col2;
      v59 = _mm_unpacklo_ps(v72, v76);
      v60 = _mm_shuffle_ps(_mm_unpackhi_ps(v72, v76), v73, 228);
      p_m_col2[-3] = (hkVector4f)v60;
      v61 = _mm_movelh_ps(v59, v73);
      p_m_col2[-5] = (hkVector4f)v61;
      v62 = _mm_shuffle_ps(_mm_movehl_ps(v61, v59), v73, 212);
      p_m_col2[-4] = (hkVector4f)v62;
      v63 = _mm_sub_ps(
              v39,
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v62), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v61)),
                _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v60)));
      p_m_col2[-2] = (hkVector4f)v63;
      v64 = _mm_sub_ps(
              v40,
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v62), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v61)),
                _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v60)));
      p_m_col2[-1] = (hkVector4f)v64;
      v65 = _mm_sub_ps(
              v41,
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v62), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v61)),
                _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v60)));
      *p_m_col2 = (hkVector4f)v65;
      v66 = _mm_max_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  *(__m128 *)&hkVector4fComparison_maskToComparison_576[16],
                  _mm_or_ps(
                    _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v64),
                    _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v63))),
                _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v65)),
              v83);
      v63.m128_f32[0] = v66.m128_f32[0];
      p_m_col2[-2] = (hkVector4f)v63;
      p_m_col2[-1].m_quad = _mm_or_ps(
                              _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v66),
                              _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v64));
      p_m_col2->m_quad = _mm_or_ps(
                           _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v66),
                           _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v65));
      hkMatrix3f_invertSymmetric(thisMatrix);
      thisMatrix += 3;
      v14 += 3;
      p_m_quad += 9;
      p_m_col2 += 9;
      ++v69;
      v72 = v36;
      v76 = v37;
      va = v18;
      v58[1].m_quad = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v36, v36, 0), v58[-2].m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v36, v36, 85), v58[-1].m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v36, v36, 170), v58->m_quad));
      v11 = v58[1].m_quad;
      v74 = v11;
      v67 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v37, v37, 0), v58[-2].m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v37, v37, 85), v58[-1].m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v37, v37, 170), v58->m_quad));
      v58[2] = (hkVector4f)v67;
      v12 = v67;
      v77 = v67;
      v13 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v58[-2].m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v58[-1].m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v58->m_quad));
      v68 = v7;
      v7 = 0i64;
      v73 = v68;
      v58[3] = (hkVector4f)v13;
      v75 = v13;
    }
    while ( v35 + 1 < numConstraints );
  }
}

// File Line: 113
// RVA: 0x132A060
void __fastcall buildConstraintMatrixLuDecompositionForBallAndSocketChain_outOfLine(
        int numConstraints,
        float cfm,
        hkp1Lin2AngJacobian *j,
        hkpVelocityAccumulatorOffset *va,
        hkpVelocityAccumulator *accumBase,
        hkpConstraintChainMatrixTriple *triple,
        int bufferSize)
{
  __m128 v7; // xmm10
  __m128 v9; // xmm12
  __m128 v10; // xmm0
  __m128 v11; // xmm14
  __m128 v12; // xmm15
  __m128 v13; // xmm13
  int v14; // r12d
  __m128 *p_m_quad; // rbp
  __int64 m_offset; // r11
  __int64 v17; // r10
  hkpVelocityAccumulatorOffset *v18; // r15
  __int64 v19; // rbx
  __m128 *v20; // rdi
  __m128 *v21; // r9
  __int64 v22; // rsi
  __m128 v23; // xmm5
  __m128 v24; // xmm6
  __m128 v25; // xmm7
  __m128 *v26; // rcx
  __m128 *v27; // rdx
  __int64 v28; // r8
  __m128 *v29; // rax
  __m128 v30; // xmm1
  __m128 v31; // xmm1
  __m128 v32; // xmm4
  int v33; // ebx
  __m128 v34; // xmm6
  __m128 v35; // xmm7
  __m128 v36; // xmm4
  __m128 v37; // xmm11
  __m128 v38; // xmm8
  __m128 v39; // xmm9
  __m128 v40; // xmm6
  __m128 v41; // xmm10
  __m128 v42; // xmm11
  __int128 *v43; // rdx
  __int64 v44; // rax
  __m128 v45; // xmm12
  __m128 v46; // xmm13
  __m128 v47; // xmm14
  hkp1Lin2AngJacobian *v48; // rcx
  __m128 v49; // xmm15
  __m128 v50; // xmm7
  __m128 m_quad; // xmm3
  __m128 v52; // xmm2
  __m128 v53; // xmm5
  __m128 v54; // xmm4
  __m128 v55; // xmm1
  hkVector4f *v56; // rdi
  __m128 v57; // xmm0
  __m128 v58; // xmm1
  __m128 v59; // xmm5
  __m128 v60; // xmm3
  __m128 v61; // xmm11
  __m128 v62; // xmm8
  __m128 v63; // xmm9
  __m128 v64; // xmm2
  __m128 v65; // xmm3
  __m128 v66; // xmm1
  hkMatrix3f *thisMatrix; // [rsp+20h] [rbp-1D8h]
  hkVector4f *p_m_col2; // [rsp+28h] [rbp-1D0h]
  __m128 v69; // [rsp+30h] [rbp-1C8h]
  __m128 v70; // [rsp+40h] [rbp-1B8h]
  __m128 v71; // [rsp+50h] [rbp-1A8h]
  __m128 v72; // [rsp+60h] [rbp-198h]
  __m128 v73; // [rsp+70h] [rbp-188h]
  __m128 v74; // [rsp+80h] [rbp-178h]
  __m128 v75; // [rsp+90h] [rbp-168h]
  __m128 v76; // [rsp+A0h] [rbp-158h] BYREF
  __m128 v77; // [rsp+B0h] [rbp-148h]
  __m128 v78; // [rsp+C0h] [rbp-138h]
  __m128 v79; // [rsp+D0h] [rbp-128h]
  __m128 v80; // [rsp+E0h] [rbp-118h]
  __m128 v81; // [rsp+F0h] [rbp-108h] BYREF
  __m128 v82; // [rsp+100h] [rbp-F8h]
  __m128 v83; // [rsp+110h] [rbp-E8h]
  int v85; // [rsp+208h] [rbp+10h]

  v7 = 0i64;
  v9 = _mm_shuffle_ps((__m128)LODWORD(cfm), (__m128)LODWORD(cfm), 0);
  v69 = 0i64;
  v72 = 0i64;
  v10 = (__m128)LODWORD(FLOAT_1_1920929eN7);
  v74 = 0i64;
  v85 = 0;
  v11 = 0i64;
  v71 = 0i64;
  v12 = 0i64;
  v73 = 0i64;
  v13 = 0i64;
  v75 = 0i64;
  v10.m128_f32[0] = fsqrt(0.00000011920929);
  v79 = v9;
  v80 = _mm_shuffle_ps(v10, v10, 0);
  if ( numConstraints > 0 )
  {
    v14 = 0;
    p_m_quad = &j[1].m_angular[1].m_quad;
    p_m_col2 = &triple->m_diagonalInv.m_col2;
    thisMatrix = &triple->m_diagonalInv;
    do
    {
      m_offset = va->m_offset;
      v17 = va[1].m_offset;
      v18 = va + 1;
      v19 = 0i64;
      v20 = &v81;
      v21 = p_m_quad - 4;
      v22 = 3i64;
      do
      {
        if ( v19 < 3 )
        {
          v23 = v21[-1];
          v24 = v21[1];
          v25 = *v21;
          v26 = v20;
          v27 = v20;
          v28 = 3 - v19;
          v29 = v21;
          do
          {
            v30 = v29[-1];
            v26 = (__m128 *)((char *)v26 + 4);
            v29 += 3;
            ++v27;
            v31 = _mm_mul_ps(v30, v23);
            v32 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + m_offset),
                          *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + m_offset),
                          255),
                        v31),
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v17),
                          *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v17),
                          255),
                        v31)),
                    _mm_add_ps(
                      _mm_mul_ps(_mm_mul_ps(v29[-2], v24), *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v17)),
                      _mm_mul_ps(
                        _mm_mul_ps(v25, v29[-3]),
                        *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + m_offset))));
            v31.m128_f32[0] = (float)(_mm_shuffle_ps(v32, v32, 85).m128_f32[0] + _mm_shuffle_ps(v32, v32, 0).m128_f32[0])
                            + _mm_shuffle_ps(v32, v32, 170).m128_f32[0];
            v27[-1].m128_i32[0] = v31.m128_i32[0];
            v26[-1].m128_i32[3] = v31.m128_i32[0];
            --v28;
          }
          while ( v28 );
        }
        ++v19;
        v21 += 3;
        v20 = (__m128 *)((char *)v20 + 20);
        --v22;
      }
      while ( v22 );
      v37 = v81;
      v33 = v85;
      v34 = v7;
      v35 = v7;
      v76 = v7;
      v78 = v7;
      v36 = _mm_add_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  *(__m128 *)&hkVector4fComparison_maskToComparison_576[16],
                  _mm_or_ps(
                    _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v81),
                    _mm_and_ps(v82, *(__m128 *)&hkVector4fComparison_maskToComparison_576[8]))),
                _mm_and_ps(v83, *(__m128 *)&hkVector4fComparison_maskToComparison_576[16])),
              v9);
      v37.m128_f32[0] = v36.m128_f32[0];
      v77 = v7;
      v70 = v37;
      v38 = _mm_or_ps(
              _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v36),
              _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v82));
      v39 = _mm_or_ps(
              _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v36),
              _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v83));
      if ( v85 < numConstraints - 1 )
      {
        v40 = *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v17);
        v41 = p_m_quad[1];
        v42 = p_m_quad[3];
        v43 = (__int128 *)&v76;
        v44 = 3i64;
        v45 = p_m_quad[-2];
        v46 = *p_m_quad;
        v47 = p_m_quad[-5];
        v48 = &j[v14 + 3];
        v49 = p_m_quad[-3];
        v50 = _mm_shuffle_ps(v40, v40, 255);
        do
        {
          m_quad = v48->m_linear0.m_quad;
          v52 = v48->m_angular[0].m_quad;
          ++v43;
          ++v48;
          v53 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v42, v52), v40), _mm_mul_ps(_mm_mul_ps(v41, m_quad), v50));
          v54 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v46, v52), v40), _mm_mul_ps(_mm_mul_ps(v45, m_quad), v50));
          v55 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v49, v52), v40), _mm_mul_ps(_mm_mul_ps(v47, m_quad), v50));
          *(v43 - 1) = (__int128)_mm_movelh_ps(
                                   _mm_unpacklo_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v55, v55, 85), _mm_shuffle_ps(v55, v55, 0)),
                                       _mm_shuffle_ps(v55, v55, 170)),
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v54, v54, 85), _mm_shuffle_ps(v54, v54, 0)),
                                       _mm_shuffle_ps(v54, v54, 170))),
                                   _mm_unpacklo_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v53, v53, 85), _mm_shuffle_ps(v53, v53, 0)),
                                       _mm_shuffle_ps(v53, v53, 170)),
                                     aabbOut.m_quad));
          --v44;
        }
        while ( v44 );
        v7 = v78;
        v35 = v77;
        v34 = v76;
        v37 = v70;
        v9 = v79;
        v13 = v75;
        v11 = v71;
        v12 = v73;
      }
      v56 = p_m_col2;
      v57 = _mm_unpacklo_ps(v69, v72);
      v58 = _mm_shuffle_ps(_mm_unpackhi_ps(v69, v72), v74, 228);
      p_m_col2[-3] = (hkVector4f)v58;
      v59 = _mm_movelh_ps(v57, v74);
      p_m_col2[-5] = (hkVector4f)v59;
      v60 = _mm_shuffle_ps(_mm_movehl_ps(v59, v57), v74, 212);
      p_m_col2[-4] = (hkVector4f)v60;
      v61 = _mm_sub_ps(
              v37,
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v60), _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), v59)),
                _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v58)));
      p_m_col2[-2] = (hkVector4f)v61;
      v62 = _mm_sub_ps(
              v38,
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), v60), _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v59)),
                _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), v58)));
      p_m_col2[-1] = (hkVector4f)v62;
      v63 = _mm_sub_ps(
              v39,
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v60), _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v59)),
                _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v58)));
      *p_m_col2 = (hkVector4f)v63;
      v64 = _mm_max_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  *(__m128 *)&hkVector4fComparison_maskToComparison_576[16],
                  _mm_or_ps(
                    _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v62),
                    _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v61))),
                _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v63)),
              v80);
      v61.m128_f32[0] = v64.m128_f32[0];
      p_m_col2[-2] = (hkVector4f)v61;
      p_m_col2[-1].m_quad = _mm_or_ps(
                              _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v64),
                              _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v62));
      p_m_col2->m_quad = _mm_or_ps(
                           _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v64),
                           _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v63));
      hkMatrix3f_invertSymmetric(thisMatrix);
      thisMatrix += 3;
      v14 += 3;
      p_m_quad += 9;
      p_m_col2 += 9;
      ++v85;
      v69 = v34;
      v72 = v35;
      va = v18;
      v56[1].m_quad = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v34, v34, 85), v56[-1].m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v34, v34, 0), v56[-2].m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v34, v34, 170), v56->m_quad));
      v11 = v56[1].m_quad;
      v71 = v11;
      v65 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v35, v35, 85), v56[-1].m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v35, v35, 0), v56[-2].m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v35, v35, 170), v56->m_quad));
      v56[2] = (hkVector4f)v65;
      v12 = v65;
      v73 = v65;
      v13 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), v56[-1].m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), v56[-2].m_quad)),
              _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), v56->m_quad));
      v66 = v7;
      v7 = 0i64;
      v74 = v66;
      v56[3] = (hkVector4f)v13;
      v75 = v13;
    }
    while ( v33 + 1 < numConstraints );
  }
}

// File Line: 119
// RVA: 0x1327E00
void __fastcall hkBallSocketChainBuildJacobian(
        int numConstraints,
        float tau,
        float damping,
        float cfm,
        hkpVelocityAccumulatorOffset *accumulators,
        hkpVelocityAccumulator *accumBase,
        hkp1Lin2AngJacobian *jacobiansEnd,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulatorOffset *v9; // r8
  hkpJacobianSchema *m_storage; // r14
  int v12; // r9d
  float v13; // xmm0_4
  __int64 v14; // rdx
  __int64 v15; // rcx
  hkpJacobianSchema *v16; // rdx
  unsigned int m_offset; // eax
  __int64 v18; // r8
  __m128 v19; // xmm10
  __m128 v20; // xmm14
  __int64 v21; // r9
  __m128 v22; // xmm12
  __m128 v23; // xmm0
  hkpJacobianSchema *v24; // r10
  __m128 v25; // xmm15
  __m128 v26; // xmm13
  __int64 v27; // rcx
  hkpJacobianSchema *v28; // rax
  hkpJacobianSchema *v29; // rdx
  hkMatrix3f *v30; // r8
  __m128 *v31; // rbp
  hkpJacobianSchema *v32; // r14
  __int64 v33; // r10
  __int64 v34; // r11
  unsigned int *v35; // r12
  __int64 v36; // rbx
  __m128 *v37; // rdi
  __m128 *v38; // r9
  __int64 v39; // rsi
  __m128 v40; // xmm5
  __m128 v41; // xmm6
  __m128 v42; // xmm7
  __m128 *v43; // rcx
  __m128 *v44; // rdx
  __int64 v45; // r8
  __m128 *v46; // rax
  __m128 v47; // xmm1
  __m128 v48; // xmm1
  __m128 v49; // xmm4
  int v50; // ebx
  __m128 v51; // xmm6
  __m128 v52; // xmm7
  __m128 v53; // xmm4
  __m128 v54; // xmm11
  __m128 v55; // xmm8
  __m128 v56; // xmm9
  __m128 v57; // xmm6
  __m128 v58; // xmm10
  __int128 *v59; // rdx
  __int64 v60; // rax
  __m128 v61; // xmm11
  __m128 v62; // xmm12
  __m128 v63; // xmm13
  __m128 *v64; // rcx
  __m128 v65; // xmm14
  __m128 v66; // xmm15
  __m128 v67; // xmm7
  __m128 v68; // xmm1
  __m128 v69; // xmm4
  __m128 v70; // xmm5
  __m128 v71; // xmm2
  __m128 v72; // xmm4
  __m128 *v73; // rdi
  __m128 v74; // xmm0
  __m128 v75; // xmm1
  __m128 v76; // xmm5
  __m128 v77; // xmm3
  __m128 v78; // xmm11
  __m128 v79; // xmm8
  __m128 v80; // xmm9
  __m128 v81; // xmm2
  __m128 v82; // xmm3
  __m128 v83; // xmm1
  __m128 v84; // [rsp+20h] [rbp-1E8h]
  __m128 *v85; // [rsp+30h] [rbp-1D8h]
  __m128 v86; // [rsp+40h] [rbp-1C8h]
  hkpJacobianSchema *v87; // [rsp+50h] [rbp-1B8h]
  __m128 v88; // [rsp+60h] [rbp-1A8h]
  __m128 v89; // [rsp+70h] [rbp-198h]
  __m128 v90; // [rsp+80h] [rbp-188h]
  __m128 v91; // [rsp+90h] [rbp-178h]
  __m128 v92; // [rsp+A0h] [rbp-168h]
  __m128 v93; // [rsp+B0h] [rbp-158h] BYREF
  __m128 v94; // [rsp+C0h] [rbp-148h]
  __m128 v95; // [rsp+D0h] [rbp-138h]
  __m128 v96; // [rsp+E0h] [rbp-128h]
  __m128 v97; // [rsp+F0h] [rbp-118h]
  __m128 v98; // [rsp+100h] [rbp-108h] BYREF
  __m128 v99; // [rsp+110h] [rbp-F8h]
  __m128 v100; // [rsp+120h] [rbp-E8h]
  int v101; // [rsp+210h] [rbp+8h]
  int v102; // [rsp+218h] [rbp+10h]
  hkMatrix3f *accumulatorsa; // [rsp+230h] [rbp+28h]

  v9 = accumulators;
  m_storage = out->m_jacobianSchemas.m_storage;
  v12 = (unsigned __int16)numConstraints + 1;
  v13 = *(float *)out->m_jacobianSchemas.m_storage;
  *(float *)&m_storage[12] = tau;
  *(float *)&m_storage[16] = damping;
  v87 = m_storage;
  *(float *)m_storage = v13 + 0.00000011920929;
  *m_storage = (hkpJacobianSchema)40;
  *(_WORD *)&m_storage[4] = numConstraints;
  *(_DWORD *)&m_storage[8] = (288 * (unsigned __int16)numConstraints + 20 * v12 + 47) & 0xFFFFFFF0;
  v14 = 3 * (3 * (unsigned __int16)numConstraints + 3i64 * (unsigned __int16)numConstraints);
  if ( numConstraints + 1 > 0 )
  {
    v15 = (unsigned int)(numConstraints + 1);
    v16 = &m_storage[16 * (v12 + 2i64 + v14) - (_QWORD)accumulators];
    do
    {
      m_offset = v9->m_offset;
      ++v9;
      *(unsigned int *)((char *)&v9[-1].m_offset + (_QWORD)v16) = m_offset;
      --v15;
    }
    while ( v15 );
  }
  v18 = *(unsigned __int16 *)&m_storage[4];
  v19 = 0i64;
  v20 = 0i64;
  v21 = 3 * (int)v18;
  v22 = _mm_shuffle_ps((__m128)LODWORD(cfm), (__m128)LODWORD(cfm), 0);
  v86 = 0i64;
  v91 = 0i64;
  v88 = 0i64;
  v23 = (__m128)0x34000000u;
  v24 = out->m_jacobianSchemas.m_storage + 32;
  v23.m128_f32[0] = fsqrt(0.00000011920929);
  v90 = 0i64;
  v25 = 0i64;
  v89 = 0i64;
  v102 = 0;
  v26 = 0i64;
  v92 = 0i64;
  v96 = v22;
  v27 = 48 * v21;
  v97 = _mm_shuffle_ps(v23, v23, 0);
  v28 = &m_storage[96 * v18 + 48 + 48 * v18 + 48 * v21 + 16 * (int)v18];
  if ( numConstraints <= 0 )
  {
    out->m_jacobianSchemas.m_storage += *(unsigned int *)&m_storage[8];
  }
  else
  {
    v29 = &m_storage[v27 + 112];
    v30 = (hkMatrix3f *)&m_storage[v27 + 80];
    v101 = 0;
    v31 = (__m128 *)&v24[80];
    v32 = v24;
    v85 = (__m128 *)v29;
    accumulatorsa = v30;
    do
    {
      v33 = *(unsigned int *)&v28[4];
      v34 = *(_DWORD *)v28;
      v35 = (unsigned int *)&v28[4];
      v36 = 0i64;
      v37 = &v98;
      v38 = v31 - 4;
      v39 = 3i64;
      do
      {
        if ( v36 < 3 )
        {
          v40 = v38[-1];
          v41 = v38[1];
          v42 = *v38;
          v43 = v37;
          v44 = v37;
          v45 = 3 - v36;
          v46 = v38;
          do
          {
            v47 = v46[-1];
            v43 = (__m128 *)((char *)v43 + 4);
            v46 += 3;
            ++v44;
            v48 = _mm_mul_ps(v47, v40);
            v49 = _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v34),
                          *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v34),
                          255),
                        v48),
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v33),
                          *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v33),
                          255),
                        v48)),
                    _mm_add_ps(
                      _mm_mul_ps(_mm_mul_ps(v46[-2], v41), *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v33)),
                      _mm_mul_ps(_mm_mul_ps(v46[-3], v42), *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v34))));
            v48.m128_f32[0] = (float)(_mm_shuffle_ps(v49, v49, 85).m128_f32[0] + _mm_shuffle_ps(v49, v49, 0).m128_f32[0])
                            + _mm_shuffle_ps(v49, v49, 170).m128_f32[0];
            v44[-1].m128_i32[0] = v48.m128_i32[0];
            v43[-1].m128_i32[3] = v48.m128_i32[0];
            --v45;
          }
          while ( v45 );
        }
        ++v36;
        v38 += 3;
        v37 = (__m128 *)((char *)v37 + 20);
        --v39;
      }
      while ( v39 );
      v54 = v98;
      v50 = v102;
      v51 = v19;
      v52 = v19;
      v93 = v19;
      v95 = v19;
      v53 = _mm_add_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  *(__m128 *)&hkVector4fComparison_maskToComparison_576[16],
                  _mm_or_ps(
                    _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v98),
                    _mm_and_ps(v99, *(__m128 *)&hkVector4fComparison_maskToComparison_576[8]))),
                _mm_and_ps(v100, *(__m128 *)&hkVector4fComparison_maskToComparison_576[16])),
              v22);
      v54.m128_f32[0] = v53.m128_f32[0];
      v94 = v19;
      v84 = v54;
      v55 = _mm_or_ps(
              _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v53),
              _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v99));
      v56 = _mm_or_ps(
              _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v53),
              _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v100));
      if ( v102 < numConstraints - 1 )
      {
        v57 = *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v33);
        v58 = v31[1];
        v59 = (__int128 *)&v93;
        v60 = 3i64;
        v61 = v31[3];
        v62 = v31[-2];
        v63 = *v31;
        v64 = (__m128 *)&v32[48 * v101 + 144];
        v65 = v31[-5];
        v66 = v31[-3];
        v67 = _mm_shuffle_ps(v57, v57, 255);
        do
        {
          v68 = *v64;
          v69 = v64[1];
          ++v59;
          v64 += 3;
          v70 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v69, v61), v57), _mm_mul_ps(_mm_mul_ps(v68, v58), v67));
          v71 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v69, v63), v57), _mm_mul_ps(_mm_mul_ps(v68, v62), v67));
          v72 = _mm_sub_ps(_mm_mul_ps(_mm_mul_ps(v69, v66), v57), _mm_mul_ps(_mm_mul_ps(v68, v65), v67));
          *(v59 - 1) = (__int128)_mm_movelh_ps(
                                   _mm_unpacklo_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v72, v72, 85), _mm_shuffle_ps(v72, v72, 0)),
                                       _mm_shuffle_ps(v72, v72, 170)),
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v71, v71, 85), _mm_shuffle_ps(v71, v71, 0)),
                                       _mm_shuffle_ps(v71, v71, 170))),
                                   _mm_unpacklo_ps(
                                     _mm_add_ps(
                                       _mm_add_ps(_mm_shuffle_ps(v70, v70, 85), _mm_shuffle_ps(v70, v70, 0)),
                                       _mm_shuffle_ps(v70, v70, 170)),
                                     aabbOut.m_quad));
          --v60;
        }
        while ( v60 );
        v19 = v95;
        v52 = v94;
        v51 = v93;
        v54 = v84;
        v22 = v96;
        v26 = v92;
        v20 = v90;
        v25 = v89;
      }
      v73 = v85;
      v74 = _mm_unpacklo_ps(v86, v91);
      v75 = _mm_shuffle_ps(_mm_unpackhi_ps(v86, v91), v88, 228);
      v85[-3] = v75;
      v76 = _mm_movelh_ps(v74, v88);
      v85[-5] = v76;
      v77 = _mm_shuffle_ps(_mm_movehl_ps(v76, v74), v88, 212);
      v85[-4] = v77;
      v78 = _mm_sub_ps(
              v54,
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v20, v20, 85), v77), _mm_mul_ps(_mm_shuffle_ps(v20, v20, 0), v76)),
                _mm_mul_ps(_mm_shuffle_ps(v20, v20, 170), v75)));
      v85[-2] = v78;
      v79 = _mm_sub_ps(
              v55,
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 85), v77), _mm_mul_ps(_mm_shuffle_ps(v25, v25, 0), v76)),
                _mm_mul_ps(_mm_shuffle_ps(v25, v25, 170), v75)));
      v85[-1] = v79;
      v80 = _mm_sub_ps(
              v56,
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 85), v77), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 0), v76)),
                _mm_mul_ps(_mm_shuffle_ps(v26, v26, 170), v75)));
      *v85 = v80;
      v81 = _mm_max_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  *(__m128 *)&hkVector4fComparison_maskToComparison_576[16],
                  _mm_or_ps(
                    _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v79),
                    _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v78))),
                _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v80)),
              v97);
      v78.m128_f32[0] = v81.m128_f32[0];
      v85[-2] = v78;
      v85[-1] = _mm_or_ps(
                  _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v81),
                  _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[8], v79));
      *v85 = _mm_or_ps(
               _mm_and_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v81),
               _mm_andnot_ps(*(__m128 *)&hkVector4fComparison_maskToComparison_576[16], v80));
      hkMatrix3f_invertSymmetric(accumulatorsa);
      v101 += 3;
      v31 += 9;
      v28 = (hkpJacobianSchema *)v35;
      v85 += 9;
      ++v102;
      v86 = v51;
      v91 = v52;
      accumulatorsa += 3;
      v73[1] = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v51, v51, 0), v73[-2]),
                   _mm_mul_ps(_mm_shuffle_ps(v51, v51, 85), v73[-1])),
                 _mm_mul_ps(_mm_shuffle_ps(v51, v51, 170), *v73));
      v20 = v73[1];
      v90 = v20;
      v82 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v52, v52, 0), v73[-2]),
                _mm_mul_ps(_mm_shuffle_ps(v52, v52, 85), v73[-1])),
              _mm_mul_ps(_mm_shuffle_ps(v52, v52, 170), *v73));
      v73[2] = v82;
      v25 = v82;
      v89 = v82;
      v26 = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), v73[-2]),
                _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v73[-1])),
              _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), *v73));
      v83 = v19;
      v19 = 0i64;
      v88 = v83;
      v73[3] = v26;
      v92 = v26;
    }
    while ( v50 + 1 < numConstraints );
    out->m_jacobianSchemas.m_storage += *(unsigned int *)&v87[8];
  }
}

// File Line: 155
// RVA: 0x1328650
void __fastcall hkStabilizedBallSocketChainBuildJacobian(
        int numConstraints,
        float tau,
        float damping,
        float cfm,
        hkpVelocityAccumulatorOffset *accumulators,
        hkpVelocityAccumulator *accumBase,
        hkpChainLinkData *linkDatasEnd,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulatorOffset *v9; // r10
  float m_storage; // xmm0_4
  hkpJacobianSchema *v11; // rbx
  int v12; // r8d
  __int64 v13; // rdx
  __int64 v14; // rcx
  hkpJacobianSchema *v15; // rdx
  unsigned int m_offset; // eax

  v9 = accumulators;
  m_storage = in->m_virtMassFactor.m_storage;
  v11 = out->m_jacobianSchemas.m_storage;
  v12 = (unsigned __int16)numConstraints + 1;
  *(_WORD *)&v11[4] = numConstraints;
  *(float *)&v11[12] = tau;
  *(float *)&v11[16] = damping;
  *(float *)&v11[20] = cfm;
  *(float *)&v11[24] = m_storage;
  *(_DWORD *)&v11[8] = (((unsigned __int16)numConstraints << 6) + 20 * v12 + 47) & 0xFFFFFFF0;
  if ( numConstraints + 1 > 0 )
  {
    v13 = 16 * (v12 + 4i64 * (unsigned __int16)numConstraints + 2) - (_QWORD)accumulators;
    v14 = (unsigned int)(numConstraints + 1);
    v15 = &v11[v13];
    do
    {
      m_offset = v9->m_offset;
      ++v9;
      *(unsigned int *)((char *)&v9[-1].m_offset + (_QWORD)v15) = m_offset;
      --v14;
    }
    while ( v14 );
  }
  out->m_jacobianSchemas.m_storage += *(unsigned int *)&v11[8];
}

// File Line: 191
// RVA: 0x132A760
void __fastcall buildConstraintMatrixLuDecompositionForStiffSpringChain(
        int numConstraints,
        float cfm,
        hkp1Lin2AngJacobian *j,
        hkpVelocityAccumulatorOffset *va,
        hkpVelocityAccumulator *accumBase,
        hkpConstraintChainTriple *triple,
        int bufferSize)
{
  int v8; // esi
  __m128 v9; // xmm7
  int v10; // r10d
  hkVector4f *m_angular; // rcx
  __m128 v12; // xmm6
  __m128 v13; // xmm4
  float *p_m_upper; // rdx
  __m128 m_quad; // xmm9
  __int64 m_offset; // rdi
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm5
  __m128 v24; // xmm3
  __m128 v25; // xmm5
  __m128 v26; // xmm5
  __m128 v27; // xmm1

  if ( numConstraints > 0 )
  {
    v8 = numConstraints - 1;
    v9 = _mm_shuffle_ps((__m128)LODWORD(cfm), (__m128)LODWORD(cfm), 0);
    v10 = 0;
    m_angular = j->m_angular;
    v12 = 0i64;
    v13 = 0i64;
    p_m_upper = &triple->m_upper;
    do
    {
      m_quad = m_angular[1].m_quad;
      m_offset = va[1].m_offset;
      v17 = *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + va->m_offset);
      v18 = _mm_add_ps(
              _mm_mul_ps(_mm_mul_ps(m_quad, m_quad), *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + m_offset)),
              _mm_mul_ps(_mm_mul_ps(m_angular->m_quad, m_angular->m_quad), v17));
      v19 = _mm_unpackhi_ps(
              v18,
              _mm_max_ps(
                _mm_add_ps(v17, *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + m_offset)),
                (__m128)xmmword_141A712D0));
      v20 = 0i64;
      v21 = _mm_shuffle_ps(v18, v19, 196);
      v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 78), v21);
      v23 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v22, v22, 177), v22), v9);
      if ( v10 < v8 )
      {
        v24 = _mm_sub_ps(
                _mm_mul_ps(
                  _mm_mul_ps(m_angular[3].m_quad, m_quad),
                  *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + m_offset)),
                _mm_mul_ps(
                  _mm_mul_ps(m_angular[2].m_quad, m_angular[-1].m_quad),
                  _mm_shuffle_ps(
                    *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + m_offset),
                    *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + m_offset),
                    255)));
        v20 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                _mm_shuffle_ps(v24, v24, 170));
      }
      *(p_m_upper - 2) = v12.m128_f32[0];
      ++v10;
      p_m_upper += 3;
      ++va;
      m_angular += 3;
      v25 = _mm_sub_ps(v23, _mm_mul_ps(v12, v13));
      v12 = v20;
      v26 = _mm_max_ps(v25, *(__m128 *)&epsilon);
      *(p_m_upper - 4) = v26.m128_f32[0];
      v27 = _mm_rcp_ps(v26);
      v13 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v27, v26)), v27), v20);
      *(p_m_upper - 3) = v13.m128_f32[0];
    }
    while ( v10 < numConstraints );
  }
}

// File Line: 229
// RVA: 0x1328700
void __fastcall hkStiffSpringChainBuildJacobian(
        int numConstraints,
        float tau,
        float damping,
        float cfm,
        hkpVelocityAccumulatorOffset *accumulators,
        hkpVelocityAccumulator *accumBase,
        hkp1Lin2AngJacobian *jacobiansEnd,
        hkpConstraintQueryIn *in,
        hkpConstraintQueryOut *out)
{
  hkpVelocityAccumulatorOffset *v9; // rdx
  hkpJacobianSchema *m_storage; // r8
  float v12; // xmm0_4
  __int64 v13; // rax
  __int64 v14; // rcx
  __int64 v15; // rax
  hkpJacobianSchema *v16; // r10
  unsigned int m_offset; // eax
  int v18; // r10d
  __m128 v19; // xmm6
  __m128 v20; // xmm4
  hkpJacobianSchema *v21; // rdi
  hkpJacobianSchema *v22; // rcx
  __m128 v23; // xmm7
  __int64 v24; // rdx
  __m128 v25; // xmm8
  __int64 v26; // rax
  __int64 v27; // rbp
  __m128 v28; // xmm2
  __m128 v29; // xmm3
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  __m128 v34; // xmm5
  __m128 v35; // xmm3
  __m128 v36; // xmm5
  __m128 v37; // xmm5
  __m128 v38; // xmm1

  v9 = accumulators;
  m_storage = out->m_jacobianSchemas.m_storage;
  *(_WORD *)&m_storage[4] = numConstraints;
  v12 = *(float *)m_storage;
  *(_DWORD *)&m_storage[8] = (68 * (unsigned __int16)numConstraints + 55) & 0xFFFFFFF0;
  v13 = (unsigned __int16)numConstraints;
  *(float *)&m_storage[12] = tau;
  *(float *)&m_storage[16] = damping;
  v14 = (unsigned int)(numConstraints + 1);
  v15 = v13 << 6;
  *(float *)m_storage = v12 + 0.00000011920929;
  *m_storage = (hkpJacobianSchema)39;
  if ( (int)v14 > 0 )
  {
    v16 = &m_storage[v15 - (_QWORD)accumulators];
    do
    {
      m_offset = v9->m_offset;
      ++v9;
      *(unsigned int *)((char *)&v9[8].m_offset + (_QWORD)v16) = m_offset;
      --v14;
    }
    while ( v14 );
  }
  v18 = 0;
  v19 = 0i64;
  v20 = 0i64;
  v21 = &m_storage[64 * (unsigned __int64)*(_WORD *)&m_storage[4] + 36];
  if ( numConstraints > 0 )
  {
    v22 = out->m_jacobianSchemas.m_storage + 48;
    v23 = _mm_shuffle_ps((__m128)LODWORD(cfm), (__m128)LODWORD(cfm), 0);
    v24 = (__int64)&m_storage[48 * *(unsigned __int16 *)&m_storage[4] + 40];
    do
    {
      v25 = *(__m128 *)&v22[16];
      v26 = *(_DWORD *)v21;
      v27 = *(unsigned int *)&v21[4];
      v28 = *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v27);
      v29 = _mm_add_ps(
              _mm_mul_ps(_mm_mul_ps(v25, v25), v28),
              _mm_mul_ps(
                _mm_mul_ps(*(__m128 *)v22, *(__m128 *)v22),
                *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v26)));
      v30 = _mm_unpackhi_ps(
              v29,
              _mm_max_ps(
                _mm_add_ps(v28, *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v26)),
                (__m128)xmmword_141A712D0));
      v31 = 0i64;
      v32 = _mm_shuffle_ps(v29, v30, 196);
      v33 = _mm_add_ps(_mm_shuffle_ps(v32, v32, 78), v32);
      v34 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v33, v33, 177), v33), v23);
      if ( v18 < numConstraints - 1 )
      {
        v35 = _mm_sub_ps(
                _mm_mul_ps(
                  _mm_mul_ps(*(__m128 *)&v22[48], v25),
                  *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v27)),
                _mm_mul_ps(
                  _mm_mul_ps(*(__m128 *)&v22[32], *(__m128 *)&v22[-16]),
                  _mm_shuffle_ps(
                    *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v27),
                    *(__m128 *)((char *)&accumBase->m_invMasses.m_quad + v27),
                    255)));
        v31 = _mm_add_ps(
                _mm_add_ps(_mm_shuffle_ps(v35, v35, 85), _mm_shuffle_ps(v35, v35, 0)),
                _mm_shuffle_ps(v35, v35, 170));
      }
      *(_DWORD *)(v24 - 8) = v19.m128_i32[0];
      ++v18;
      v24 += 12i64;
      v21 += 4;
      v22 += 48;
      v36 = _mm_sub_ps(v34, _mm_mul_ps(v19, v20));
      v19 = v31;
      v37 = _mm_max_ps(v36, *(__m128 *)&epsilon);
      *(_DWORD *)(v24 - 16) = v37.m128_i32[0];
      v38 = _mm_rcp_ps(v37);
      v20 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v38, v37)), v38), v31);
      *(_DWORD *)(v24 - 12) = v20.m128_i32[0];
    }
    while ( v18 < numConstraints );
  }
  out->m_jacobianSchemas.m_storage += *(unsigned int *)&m_storage[8];
}

// File Line: 262
// RVA: 0x1328DF0
void __fastcall hkBallSocketConstraintBuildJacobian_noSchema_Proj(
        hkVector4f *posA,
        hkVector4f *posB,
        hkpConstraintQueryIn *in,
        hkp1Lin2AngJacobian *jac)
{
  hkpVelocityAccumulator *m_storage; // rax
  hkpVelocityAccumulator *v5; // r10
  __m128 v6; // xmm7
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128 v9; // xmm5
  __m128 v10; // xmm3
  __m128 v11; // xmm5
  __m128 v12; // xmm5
  __m128 v13; // xmm2
  __m128 v14; // xmm2
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 m_quad; // xmm2
  __m128 v19; // xmm3
  __m128 v20; // xmm3
  __m128 v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  __m128 v24; // xmm1
  __m128 v25; // xmm5
  __m128 v26; // xmm3
  __m128 v27; // xmm2
  __m128 v28; // xmm5
  __m128 v29; // xmm5
  __m128 v30; // xmm4
  __m128 v31; // xmm4
  __m128 v32; // xmm1
  __m128 v33; // xmm5
  __m128 v34; // xmm4
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  __m128 v37; // xmm3
  __m128 v38; // xmm0
  __m128 v39; // xmm1
  __m128 v40; // xmm2
  __m128 v41; // xmm1
  __m128 v42; // xmm4
  __m128 v43; // xmm7
  __m128 v44; // xmm2
  __m128 v45; // xmm4
  __m128 v46; // xmm4
  __m128 v47; // xmm3
  __m128 v48; // xmm1
  __m128 v49; // xmm3
  __m128 v50; // xmm5
  __m128 v51; // xmm4
  __m128 v52; // xmm2
  __m128 v53; // xmm3
  __m128 v54; // xmm3
  __m128 v55; // xmm0
  __m128 v56; // xmm3
  __m128 v57; // xmm1
  __m128 v58; // xmm1
  float v59; // [rsp+30h] [rbp+8h]
  float v60; // [rsp+30h] [rbp+8h]
  float v61; // [rsp+30h] [rbp+8h]

  m_storage = in->m_bodyA.m_storage;
  v5 = in->m_bodyB.m_storage;
  v59 = in->m_virtMassFactor.m_storage;
  v6 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(posB->m_quad, posA->m_quad), (__m128)xmmword_141A711B0), posA->m_quad);
  jac->m_linear0 = (hkVector4f)transform.m_quad;
  v7 = _mm_sub_ps(v6, m_storage->m_scratch3.m_quad);
  v8 = _mm_sub_ps(v6, v5->m_scratch3.m_quad);
  v9 = _mm_shuffle_ps(transform.m_quad, transform.m_quad, 201);
  v10 = _mm_mul_ps(v9, v8);
  v11 = _mm_sub_ps(_mm_mul_ps(v9, v7), _mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), transform.m_quad));
  v12 = _mm_shuffle_ps(v11, v11, 201);
  v13 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v8, v8, 201), transform.m_quad), v10);
  v14 = _mm_shuffle_ps(v13, v13, 201);
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), m_storage->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), m_storage->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v12, v12, 170), m_storage->m_scratch2.m_quad));
  jac->m_angular[0].m_quad = v15;
  v16 = v15;
  v17 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 85), v5->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v14, v14, 0), v5->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v14, v14, 170), v5->m_scratch2.m_quad));
  jac->m_angular[1].m_quad = v17;
  m_quad = v5->m_invMasses.m_quad;
  v19 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v15, v15), m_storage->m_invMasses.m_quad),
          _mm_mul_ps(_mm_mul_ps(v17, v17), m_quad));
  v20 = _mm_shuffle_ps(
          v19,
          _mm_unpackhi_ps(v19, _mm_max_ps(_mm_add_ps(m_quad, m_storage->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 78), v20);
  v22 = _mm_add_ps(_mm_shuffle_ps(v21, v21, 177), v21);
  v23 = _mm_rcp_ps(v22);
  jac->m_angular[1].m_quad = _mm_shuffle_ps(v17, _mm_unpackhi_ps(v17, v22), 196);
  jac->m_angular[0].m_quad = _mm_shuffle_ps(
                               v16,
                               _mm_unpackhi_ps(
                                 v16,
                                 _mm_mul_ps(
                                   _mm_shuffle_ps((__m128)LODWORD(v59), (__m128)LODWORD(v59), 0),
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v23, v22)), v23))),
                               196);
  v24 = _mm_mul_ps(_mm_sub_ps(posB->m_quad, posA->m_quad), transform.m_quad);
  jac->m_linear0.m_quad = _mm_shuffle_ps(
                            jac->m_linear0.m_quad,
                            _mm_unpackhi_ps(
                              jac->m_linear0.m_quad,
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v24, v24, 85), _mm_shuffle_ps(v24, v24, 0)),
                                  _mm_shuffle_ps(v24, v24, 170)),
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                  (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                  0))),
                            196);
  v60 = in->m_virtMassFactor.m_storage;
  jac[1].m_linear0 = (hkVector4f)direction.m_quad;
  v25 = _mm_sub_ps(v6, m_storage->m_scratch3.m_quad);
  v26 = _mm_sub_ps(v6, v5->m_scratch3.m_quad);
  v27 = _mm_shuffle_ps(direction.m_quad, direction.m_quad, 201);
  v28 = _mm_sub_ps(_mm_mul_ps(v25, v27), _mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), direction.m_quad));
  v29 = _mm_shuffle_ps(v28, v28, 201);
  v30 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), direction.m_quad), _mm_mul_ps(v26, v27));
  v31 = _mm_shuffle_ps(v30, v30, 201);
  v32 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v29, v29, 85), m_storage->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v29, v29, 0), m_storage->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v29, v29, 170), m_storage->m_scratch2.m_quad));
  jac[1].m_angular[0].m_quad = v32;
  v33 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 85), v5->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v31, v31, 0), v5->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v31, v31, 170), v5->m_scratch2.m_quad));
  v34 = v32;
  jac[1].m_angular[1].m_quad = v33;
  v35 = v5->m_invMasses.m_quad;
  v36 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v32, v32), m_storage->m_invMasses.m_quad),
          _mm_mul_ps(_mm_mul_ps(v33, v33), v35));
  v37 = _mm_shuffle_ps(
          v36,
          _mm_unpackhi_ps(v36, _mm_max_ps(_mm_add_ps(v35, m_storage->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 78), v37);
  v39 = _mm_add_ps(_mm_shuffle_ps(v38, v38, 177), v38);
  v40 = _mm_rcp_ps(v39);
  jac[1].m_angular[1].m_quad = _mm_shuffle_ps(v33, _mm_unpackhi_ps(v33, v39), 196);
  jac[1].m_angular[0].m_quad = _mm_shuffle_ps(
                                 v34,
                                 _mm_unpackhi_ps(
                                   v34,
                                   _mm_mul_ps(
                                     _mm_shuffle_ps((__m128)LODWORD(v60), (__m128)LODWORD(v60), 0),
                                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v40, v39)), v40))),
                                 196);
  v41 = _mm_mul_ps(_mm_sub_ps(posB->m_quad, posA->m_quad), direction.m_quad);
  jac[1].m_linear0.m_quad = _mm_shuffle_ps(
                              jac[1].m_linear0.m_quad,
                              _mm_unpackhi_ps(
                                jac[1].m_linear0.m_quad,
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v41, v41, 85), _mm_shuffle_ps(v41, v41, 0)),
                                    _mm_shuffle_ps(v41, v41, 170)),
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                    (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                    0))),
                              196);
  v61 = in->m_virtMassFactor.m_storage;
  jac[2].m_linear0 = (hkVector4f)stru_141A71280.m_quad;
  v42 = _mm_sub_ps(v6, m_storage->m_scratch3.m_quad);
  v43 = _mm_sub_ps(v6, v5->m_scratch3.m_quad);
  v44 = _mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201);
  v45 = _mm_sub_ps(_mm_mul_ps(v42, v44), _mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), stru_141A71280.m_quad));
  v46 = _mm_shuffle_ps(v45, v45, 201);
  v47 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), stru_141A71280.m_quad), _mm_mul_ps(v43, v44));
  v48 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v46, v46, 85), m_storage->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v46, v46, 0), m_storage->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v46, v46, 170), m_storage->m_scratch2.m_quad));
  jac[2].m_angular[0].m_quad = v48;
  v49 = _mm_shuffle_ps(v47, v47, 201);
  v50 = v48;
  v51 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v49, v49, 85), v5->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v49, v49, 0), v5->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v49, v49, 170), v5->m_scratch2.m_quad));
  jac[2].m_angular[1].m_quad = v51;
  v52 = v5->m_invMasses.m_quad;
  v53 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v48, v48), m_storage->m_invMasses.m_quad),
          _mm_mul_ps(_mm_mul_ps(v51, v51), v52));
  v54 = _mm_shuffle_ps(
          v53,
          _mm_unpackhi_ps(v53, _mm_max_ps(_mm_add_ps(v52, m_storage->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v55 = _mm_add_ps(_mm_shuffle_ps(v54, v54, 78), v54);
  v56 = _mm_add_ps(_mm_shuffle_ps(v55, v55, 177), v55);
  v57 = _mm_rcp_ps(v56);
  jac[2].m_angular[1].m_quad = _mm_shuffle_ps(v51, _mm_unpackhi_ps(v51, v56), 196);
  jac[2].m_angular[0].m_quad = _mm_shuffle_ps(
                                 v50,
                                 _mm_unpackhi_ps(
                                   v50,
                                   _mm_mul_ps(
                                     _mm_shuffle_ps((__m128)LODWORD(v61), (__m128)LODWORD(v61), 0),
                                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v57, v56)), v57))),
                                 196);
  v58 = _mm_mul_ps(_mm_sub_ps(posB->m_quad, posA->m_quad), stru_141A71280.m_quad);
  jac[2].m_linear0.m_quad = _mm_shuffle_ps(
                              jac[2].m_linear0.m_quad,
                              _mm_unpackhi_ps(
                                jac[2].m_linear0.m_quad,
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v58, v58, 85), _mm_shuffle_ps(v58, v58, 0)),
                                    _mm_shuffle_ps(v58, v58, 170)),
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                    (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                    0))),
                              196);
}

// File Line: 274
// RVA: 0x1328950
void __fastcall hkBallSocketConstraintBuildJacobian_noSchema_noProj(
        hkVector4f *posA,
        hkVector4f *posB,
        hkpConstraintQueryIn *in,
        hkp1Lin2AngJacobian *jac)
{
  hkpVelocityAccumulator *m_storage; // rax
  hkpVelocityAccumulator *v5; // r10
  __m128 v6; // xmm2
  __m128 v7; // xmm4
  __m128 v8; // xmm5
  __m128 v9; // xmm3
  __m128 v10; // xmm5
  __m128 v11; // xmm5
  __m128 v12; // xmm2
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm5
  __m128 v16; // xmm4
  __m128 m_quad; // xmm2
  __m128 v18; // xmm3
  __m128 v19; // xmm3
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm2
  __m128 v23; // xmm1
  __m128 v24; // xmm5
  __m128 v25; // xmm2
  __m128 v26; // xmm3
  __m128 v27; // xmm5
  __m128 v28; // xmm5
  __m128 v29; // xmm4
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  __m128 v32; // xmm5
  __m128 v33; // xmm4
  __m128 v34; // xmm2
  __m128 v35; // xmm3
  __m128 v36; // xmm3
  __m128 v37; // xmm0
  __m128 v38; // xmm1
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __m128 v41; // xmm5
  __m128 v42; // xmm2
  __m128 v43; // xmm3
  __m128 v44; // xmm5
  __m128 v45; // xmm5
  __m128 v46; // xmm4
  __m128 v47; // xmm4
  __m128 v48; // xmm1
  __m128 v49; // xmm5
  __m128 v50; // xmm4
  __m128 v51; // xmm2
  __m128 v52; // xmm3
  __m128 v53; // xmm3
  __m128 v54; // xmm0
  __m128 v55; // xmm3
  __m128 v56; // xmm1
  __m128 v57; // xmm1
  float v58; // [rsp+20h] [rbp+8h]
  float v59; // [rsp+20h] [rbp+8h]
  float v60; // [rsp+20h] [rbp+8h]

  m_storage = in->m_bodyA.m_storage;
  v5 = in->m_bodyB.m_storage;
  v58 = in->m_virtMassFactor.m_storage;
  jac->m_linear0 = (hkVector4f)transform.m_quad;
  v6 = _mm_sub_ps(posA->m_quad, m_storage->m_scratch3.m_quad);
  v7 = _mm_sub_ps(posB->m_quad, v5->m_scratch3.m_quad);
  v8 = _mm_shuffle_ps(transform.m_quad, transform.m_quad, 201);
  v9 = _mm_mul_ps(v8, v7);
  v10 = _mm_sub_ps(_mm_mul_ps(v8, v6), _mm_mul_ps(_mm_shuffle_ps(v6, v6, 201), transform.m_quad));
  v11 = _mm_shuffle_ps(v10, v10, 201);
  v12 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v7, v7, 201), transform.m_quad), v9);
  v13 = _mm_shuffle_ps(v12, v12, 201);
  v14 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), m_storage->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v11, v11, 0), m_storage->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), m_storage->m_scratch2.m_quad));
  jac->m_angular[0].m_quad = v14;
  v15 = v14;
  v16 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v5->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v13, v13, 0), v5->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v5->m_scratch2.m_quad));
  jac->m_angular[1].m_quad = v16;
  m_quad = v5->m_invMasses.m_quad;
  v18 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v14, v14), m_storage->m_invMasses.m_quad),
          _mm_mul_ps(_mm_mul_ps(v16, v16), m_quad));
  v19 = _mm_shuffle_ps(
          v18,
          _mm_unpackhi_ps(v18, _mm_max_ps(_mm_add_ps(m_quad, m_storage->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v20 = _mm_add_ps(_mm_shuffle_ps(v19, v19, 78), v19);
  v21 = _mm_add_ps(_mm_shuffle_ps(v20, v20, 177), v20);
  v22 = _mm_rcp_ps(v21);
  jac->m_angular[1].m_quad = _mm_shuffle_ps(v16, _mm_unpackhi_ps(v16, v21), 196);
  jac->m_angular[0].m_quad = _mm_shuffle_ps(
                               v15,
                               _mm_unpackhi_ps(
                                 v15,
                                 _mm_mul_ps(
                                   _mm_shuffle_ps((__m128)LODWORD(v58), (__m128)LODWORD(v58), 0),
                                   _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v22, v21)), v22))),
                               196);
  v23 = _mm_mul_ps(_mm_sub_ps(posB->m_quad, posA->m_quad), transform.m_quad);
  jac->m_linear0.m_quad = _mm_shuffle_ps(
                            jac->m_linear0.m_quad,
                            _mm_unpackhi_ps(
                              jac->m_linear0.m_quad,
                              _mm_mul_ps(
                                _mm_add_ps(
                                  _mm_add_ps(_mm_shuffle_ps(v23, v23, 85), _mm_shuffle_ps(v23, v23, 0)),
                                  _mm_shuffle_ps(v23, v23, 170)),
                                _mm_shuffle_ps(
                                  (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                  (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                  0))),
                            196);
  v59 = in->m_virtMassFactor.m_storage;
  jac[1].m_linear0 = (hkVector4f)direction.m_quad;
  v24 = _mm_sub_ps(posA->m_quad, m_storage->m_scratch3.m_quad);
  v25 = _mm_shuffle_ps(direction.m_quad, direction.m_quad, 201);
  v26 = _mm_sub_ps(posB->m_quad, v5->m_scratch3.m_quad);
  v27 = _mm_sub_ps(_mm_mul_ps(v24, v25), _mm_mul_ps(_mm_shuffle_ps(v24, v24, 201), direction.m_quad));
  v28 = _mm_shuffle_ps(v27, v27, 201);
  v29 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), direction.m_quad), _mm_mul_ps(v26, v25));
  v30 = _mm_shuffle_ps(v29, v29, 201);
  v31 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v28, v28, 85), m_storage->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), m_storage->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), m_storage->m_scratch2.m_quad));
  jac[1].m_angular[0].m_quad = v31;
  v32 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v5->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v5->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v5->m_scratch2.m_quad));
  v33 = v31;
  jac[1].m_angular[1].m_quad = v32;
  v34 = v5->m_invMasses.m_quad;
  v35 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v31, v31), m_storage->m_invMasses.m_quad),
          _mm_mul_ps(_mm_mul_ps(v32, v32), v34));
  v36 = _mm_shuffle_ps(
          v35,
          _mm_unpackhi_ps(v35, _mm_max_ps(_mm_add_ps(v34, m_storage->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v37 = _mm_add_ps(_mm_shuffle_ps(v36, v36, 78), v36);
  v38 = _mm_add_ps(_mm_shuffle_ps(v37, v37, 177), v37);
  v39 = _mm_rcp_ps(v38);
  jac[1].m_angular[1].m_quad = _mm_shuffle_ps(v32, _mm_unpackhi_ps(v32, v38), 196);
  jac[1].m_angular[0].m_quad = _mm_shuffle_ps(
                                 v33,
                                 _mm_unpackhi_ps(
                                   v33,
                                   _mm_mul_ps(
                                     _mm_shuffle_ps((__m128)LODWORD(v59), (__m128)LODWORD(v59), 0),
                                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v39, v38)), v39))),
                                 196);
  v40 = _mm_mul_ps(_mm_sub_ps(posB->m_quad, posA->m_quad), direction.m_quad);
  jac[1].m_linear0.m_quad = _mm_shuffle_ps(
                              jac[1].m_linear0.m_quad,
                              _mm_unpackhi_ps(
                                jac[1].m_linear0.m_quad,
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v40, v40, 85), _mm_shuffle_ps(v40, v40, 0)),
                                    _mm_shuffle_ps(v40, v40, 170)),
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                    (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                    0))),
                              196);
  v60 = in->m_virtMassFactor.m_storage;
  jac[2].m_linear0 = (hkVector4f)stru_141A71280.m_quad;
  v41 = _mm_sub_ps(posA->m_quad, m_storage->m_scratch3.m_quad);
  v42 = _mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201);
  v43 = _mm_sub_ps(posB->m_quad, v5->m_scratch3.m_quad);
  v44 = _mm_sub_ps(_mm_mul_ps(v41, v42), _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), stru_141A71280.m_quad));
  v45 = _mm_shuffle_ps(v44, v44, 201);
  v46 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v43, v43, 201), stru_141A71280.m_quad), _mm_mul_ps(v43, v42));
  v47 = _mm_shuffle_ps(v46, v46, 201);
  v48 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v45, v45, 85), m_storage->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v45, v45, 0), m_storage->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v45, v45, 170), m_storage->m_scratch2.m_quad));
  jac[2].m_angular[0].m_quad = v48;
  v49 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v47, v47, 85), v5->m_scratch1.m_quad),
            _mm_mul_ps(_mm_shuffle_ps(v47, v47, 0), v5->m_scratch0.m_quad)),
          _mm_mul_ps(_mm_shuffle_ps(v47, v47, 170), v5->m_scratch2.m_quad));
  v50 = v48;
  jac[2].m_angular[1].m_quad = v49;
  v51 = v5->m_invMasses.m_quad;
  v52 = _mm_add_ps(
          _mm_mul_ps(_mm_mul_ps(v48, v48), m_storage->m_invMasses.m_quad),
          _mm_mul_ps(_mm_mul_ps(v49, v49), v51));
  v53 = _mm_shuffle_ps(
          v52,
          _mm_unpackhi_ps(v52, _mm_max_ps(_mm_add_ps(v51, m_storage->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
          196);
  v54 = _mm_add_ps(_mm_shuffle_ps(v53, v53, 78), v53);
  v55 = _mm_add_ps(_mm_shuffle_ps(v54, v54, 177), v54);
  v56 = _mm_rcp_ps(v55);
  jac[2].m_angular[1].m_quad = _mm_shuffle_ps(v49, _mm_unpackhi_ps(v49, v55), 196);
  jac[2].m_angular[0].m_quad = _mm_shuffle_ps(
                                 v50,
                                 _mm_unpackhi_ps(
                                   v50,
                                   _mm_mul_ps(
                                     _mm_shuffle_ps((__m128)LODWORD(v60), (__m128)LODWORD(v60), 0),
                                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v56, v55)), v56))),
                                 196);
  v57 = _mm_mul_ps(_mm_sub_ps(posB->m_quad, posA->m_quad), stru_141A71280.m_quad);
  jac[2].m_linear0.m_quad = _mm_shuffle_ps(
                              jac[2].m_linear0.m_quad,
                              _mm_unpackhi_ps(
                                jac[2].m_linear0.m_quad,
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v57, v57, 85), _mm_shuffle_ps(v57, v57, 0)),
                                    _mm_shuffle_ps(v57, v57, 170)),
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                    (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                    0))),
                              196);
}

// File Line: 285
// RVA: 0x13292B0
void __fastcall hkStabilizedBallSocketConstraintBuildJacobian_noSchema(
        hkVector4f *posA,
        hkVector4f *posB,
        float maxAllowedErrorDistance,
        hkpConstraintQueryIn *in,
        hkp1Lin2AngJacobian *jac)
{
  hkpVelocityAccumulator *m_storage; // r14
  hkpVelocityAccumulator *v6; // r15
  __m128 v10; // xmm11
  __m128 v11; // xmm1
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm3
  __m128 v19; // xmm1
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  __m128 v22; // xmm10
  __m128 v23; // xmm8
  __m128 v24; // xmm7
  __m128 v25; // xmm4
  __m128 v26; // xmm2
  __m128 v27; // xmm5
  __m128 v28; // xmm3
  __m128 v29; // xmm5
  __m128 v30; // xmm5
  __m128 v31; // xmm2
  __m128 v32; // xmm2
  __m128 v33; // xmm1
  __m128 v34; // xmm4
  __m128 v35; // xmm6
  __m128 v36; // xmm5
  __m128 m_quad; // xmm2
  __m128 v38; // xmm3
  __m128 v39; // xmm3
  __m128 v40; // xmm0
  __m128 v41; // xmm1
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm2
  __m128 v45; // xmm4
  __m128 v46; // xmm3
  __m128 v47; // xmm5
  __m128 v48; // xmm5
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm5
  __m128 v53; // xmm4
  __m128 v54; // xmm2
  __m128 v55; // xmm3
  __m128 v56; // xmm3
  __m128 v57; // xmm0
  __m128 v58; // xmm1
  __m128 v59; // xmm2
  __m128 v60; // xmm1
  __m128 v61; // xmm7
  __m128 v62; // xmm8
  __m128 v63; // xmm2
  __m128 v64; // xmm3
  __m128 v65; // xmm3
  __m128 v66; // xmm4
  __m128 v67; // xmm1
  __m128 v68; // xmm4
  __m128 v69; // xmm5
  __m128 v70; // xmm4
  __m128 v71; // xmm2
  __m128 v72; // xmm3
  __m128 v73; // xmm3
  __m128 v74; // xmm0
  __m128 v75; // xmm3
  __m128 v76; // xmm1
  __m128 v77; // xmm6
  __m128 v78; // xmm11
  unsigned int v79; // [rsp+B0h] [rbp+18h]
  float v80; // [rsp+B0h] [rbp+18h]
  float v81; // [rsp+B0h] [rbp+18h]
  float v82; // [rsp+B0h] [rbp+18h]

  m_storage = in->m_bodyA.m_storage;
  v6 = in->m_bodyB.m_storage;
  hkBallSocketConstraintBuildJacobian_noSchema_noProj(posA, posB, in, jac);
  *(float *)&v79 = maxAllowedErrorDistance * in->m_rhsFactor.m_storage;
  v10 = _mm_movelh_ps(
          _mm_unpacklo_ps(
            _mm_shuffle_ps(jac->m_linear0.m_quad, jac->m_linear0.m_quad, 255),
            _mm_shuffle_ps(jac[1].m_linear0.m_quad, jac[1].m_linear0.m_quad, 255)),
          _mm_unpacklo_ps(_mm_shuffle_ps(jac[2].m_linear0.m_quad, jac[2].m_linear0.m_quad, 255), (__m128)0i64));
  v11 = _mm_mul_ps(v10, v10);
  v12 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v11, v11, 85), _mm_shuffle_ps(v11, v11, 0)), _mm_shuffle_ps(v11, v11, 170));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_mul_ps(
          _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v13, v12), v13)), _mm_mul_ps(*(__m128 *)_xmm, v13)),
          v12);
  v15 = _mm_shuffle_ps((__m128)v79, (__m128)v79, 0);
  v16 = _mm_andnot_ps(_mm_cmple_ps(v12, (__m128)0i64), v14);
  if ( v16.m128_f32[0] > v15.m128_f32[0] )
  {
    v17 = _mm_rcp_ps(v16);
    v18 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v17, v16)), v17), v15);
    v19 = _mm_rsqrt_ps(v18);
    v20 = _mm_andnot_ps(
            _mm_cmple_ps(v18, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v19, v18), v19)),
                _mm_mul_ps(*(__m128 *)_xmm, v19)),
              v18));
    v21 = _mm_rsqrt_ps(v20);
    v80 = in->m_virtMassFactor.m_storage;
    v22 = _mm_andnot_ps(
            _mm_cmple_ps(v20, (__m128)0i64),
            _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v20, v21), v21)),
                _mm_mul_ps(*(__m128 *)_xmm, v21)),
              v20));
    v23 = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(posB->m_quad, v6->m_scratch3.m_quad), v22), v6->m_scratch3.m_quad);
    v24 = _mm_add_ps(
            _mm_mul_ps(_mm_sub_ps(posA->m_quad, m_storage->m_scratch3.m_quad), v22),
            m_storage->m_scratch3.m_quad);
    jac->m_linear0 = (hkVector4f)transform.m_quad;
    v25 = _mm_sub_ps(v23, v6->m_scratch3.m_quad);
    v26 = _mm_sub_ps(v24, m_storage->m_scratch3.m_quad);
    v27 = _mm_shuffle_ps(transform.m_quad, transform.m_quad, 201);
    v28 = _mm_mul_ps(v27, v25);
    v29 = _mm_sub_ps(_mm_mul_ps(v27, v26), _mm_mul_ps(_mm_shuffle_ps(v26, v26, 201), transform.m_quad));
    v30 = _mm_shuffle_ps(v29, v29, 201);
    v31 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v25, v25, 201), transform.m_quad), v28);
    v32 = _mm_shuffle_ps(v31, v31, 201);
    v33 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), m_storage->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), m_storage->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), m_storage->m_scratch2.m_quad));
    jac->m_angular[0].m_quad = v33;
    v34 = v33;
    v35 = _mm_sub_ps(v23, v24);
    v36 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v6->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v6->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), v6->m_scratch2.m_quad));
    jac->m_angular[1].m_quad = v36;
    m_quad = m_storage->m_invMasses.m_quad;
    v38 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v33, v33), m_quad), _mm_mul_ps(_mm_mul_ps(v36, v36), v6->m_invMasses.m_quad));
    v39 = _mm_shuffle_ps(
            v38,
            _mm_unpackhi_ps(v38, _mm_max_ps(_mm_add_ps(m_quad, v6->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v40 = _mm_add_ps(_mm_shuffle_ps(v39, v39, 78), v39);
    v41 = _mm_add_ps(_mm_shuffle_ps(v40, v40, 177), v40);
    v42 = _mm_rcp_ps(v41);
    jac->m_angular[1].m_quad = _mm_shuffle_ps(v36, _mm_unpackhi_ps(v36, v41), 196);
    jac->m_angular[0].m_quad = _mm_shuffle_ps(
                                 v34,
                                 _mm_unpackhi_ps(
                                   v34,
                                   _mm_mul_ps(
                                     _mm_shuffle_ps((__m128)LODWORD(v80), (__m128)LODWORD(v80), 0),
                                     _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v42, v41)), v42))),
                                 196);
    v43 = _mm_mul_ps(v35, transform.m_quad);
    jac->m_linear0.m_quad = _mm_shuffle_ps(
                              jac->m_linear0.m_quad,
                              _mm_unpackhi_ps(
                                jac->m_linear0.m_quad,
                                _mm_mul_ps(
                                  _mm_add_ps(
                                    _mm_add_ps(_mm_shuffle_ps(v43, v43, 85), _mm_shuffle_ps(v43, v43, 0)),
                                    _mm_shuffle_ps(v43, v43, 170)),
                                  _mm_shuffle_ps(
                                    (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                    (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                    0))),
                              196);
    v81 = in->m_virtMassFactor.m_storage;
    jac[1].m_linear0 = (hkVector4f)direction.m_quad;
    v44 = _mm_sub_ps(v24, m_storage->m_scratch3.m_quad);
    v45 = _mm_sub_ps(v23, v6->m_scratch3.m_quad);
    v46 = _mm_shuffle_ps(direction.m_quad, direction.m_quad, 201);
    v47 = _mm_sub_ps(_mm_mul_ps(v46, v44), _mm_mul_ps(_mm_shuffle_ps(v44, v44, 201), direction.m_quad));
    v48 = _mm_shuffle_ps(v47, v47, 201);
    v49 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v45, v45, 201), direction.m_quad), _mm_mul_ps(v46, v45));
    v50 = _mm_shuffle_ps(v49, v49, 201);
    v51 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v48, v48, 85), m_storage->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v48, v48, 0), m_storage->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v48, v48, 170), m_storage->m_scratch2.m_quad));
    jac[1].m_angular[0].m_quad = v51;
    v52 = v51;
    v53 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), v6->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), v6->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), v6->m_scratch2.m_quad));
    jac[1].m_angular[1].m_quad = v53;
    v54 = m_storage->m_invMasses.m_quad;
    v55 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v51, v51), v54), _mm_mul_ps(_mm_mul_ps(v53, v53), v6->m_invMasses.m_quad));
    v56 = _mm_shuffle_ps(
            v55,
            _mm_unpackhi_ps(v55, _mm_max_ps(_mm_add_ps(v54, v6->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v57 = _mm_add_ps(_mm_shuffle_ps(v56, v56, 78), v56);
    v58 = _mm_add_ps(_mm_shuffle_ps(v57, v57, 177), v57);
    v59 = _mm_rcp_ps(v58);
    jac[1].m_angular[1].m_quad = _mm_shuffle_ps(v53, _mm_unpackhi_ps(v53, v58), 196);
    jac[1].m_angular[0].m_quad = _mm_shuffle_ps(
                                   v52,
                                   _mm_unpackhi_ps(
                                     v52,
                                     _mm_mul_ps(
                                       _mm_shuffle_ps((__m128)LODWORD(v81), (__m128)LODWORD(v81), 0),
                                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v59, v58)), v59))),
                                   196);
    v60 = _mm_mul_ps(v35, direction.m_quad);
    jac[1].m_linear0.m_quad = _mm_shuffle_ps(
                                jac[1].m_linear0.m_quad,
                                _mm_unpackhi_ps(
                                  jac[1].m_linear0.m_quad,
                                  _mm_mul_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_shuffle_ps(v60, v60, 85), _mm_shuffle_ps(v60, v60, 0)),
                                      _mm_shuffle_ps(v60, v60, 170)),
                                    _mm_shuffle_ps(
                                      (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                      (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                      0))),
                                196);
    v82 = in->m_virtMassFactor.m_storage;
    jac[2].m_linear0 = (hkVector4f)stru_141A71280.m_quad;
    v61 = _mm_sub_ps(v24, m_storage->m_scratch3.m_quad);
    v62 = _mm_sub_ps(v23, v6->m_scratch3.m_quad);
    v63 = _mm_shuffle_ps(stru_141A71280.m_quad, stru_141A71280.m_quad, 201);
    v64 = _mm_sub_ps(_mm_mul_ps(v63, v61), _mm_mul_ps(_mm_shuffle_ps(v61, v61, 201), stru_141A71280.m_quad));
    v65 = _mm_shuffle_ps(v64, v64, 201);
    v66 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v62, v62, 201), stru_141A71280.m_quad), _mm_mul_ps(v63, v62));
    v67 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v65, v65, 85), m_storage->m_scratch1.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v65, v65, 0), m_storage->m_scratch0.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v65, v65, 170), m_storage->m_scratch2.m_quad));
    jac[2].m_angular[0].m_quad = v67;
    v68 = _mm_shuffle_ps(v66, v66, 201);
    v69 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v68, v68, 0), v6->m_scratch0.m_quad),
              _mm_mul_ps(_mm_shuffle_ps(v68, v68, 85), v6->m_scratch1.m_quad)),
            _mm_mul_ps(_mm_shuffle_ps(v68, v68, 170), v6->m_scratch2.m_quad));
    v70 = v67;
    jac[2].m_angular[1].m_quad = v69;
    v71 = m_storage->m_invMasses.m_quad;
    v72 = _mm_add_ps(_mm_mul_ps(_mm_mul_ps(v67, v67), v71), _mm_mul_ps(_mm_mul_ps(v69, v69), v6->m_invMasses.m_quad));
    v73 = _mm_shuffle_ps(
            v72,
            _mm_unpackhi_ps(v72, _mm_max_ps(_mm_add_ps(v71, v6->m_invMasses.m_quad), (__m128)xmmword_141A712D0)),
            196);
    v74 = _mm_add_ps(_mm_shuffle_ps(v73, v73, 78), v73);
    v75 = _mm_add_ps(_mm_shuffle_ps(v74, v74, 177), v74);
    v76 = _mm_rcp_ps(v75);
    jac[2].m_angular[1].m_quad = _mm_shuffle_ps(v69, _mm_unpackhi_ps(v69, v75), 196);
    jac[2].m_angular[0].m_quad = _mm_shuffle_ps(
                                   v70,
                                   _mm_unpackhi_ps(
                                     v70,
                                     _mm_mul_ps(
                                       _mm_shuffle_ps((__m128)LODWORD(v82), (__m128)LODWORD(v82), 0),
                                       _mm_mul_ps(_mm_sub_ps((__m128)_xmm, _mm_mul_ps(v76, v75)), v76))),
                                   196);
    v77 = _mm_mul_ps(v35, stru_141A71280.m_quad);
    v78 = _mm_mul_ps(v10, v22);
    jac[2].m_linear0.m_quad = _mm_shuffle_ps(
                                jac[2].m_linear0.m_quad,
                                _mm_unpackhi_ps(
                                  jac[2].m_linear0.m_quad,
                                  _mm_mul_ps(
                                    _mm_add_ps(
                                      _mm_add_ps(_mm_shuffle_ps(v77, v77, 85), _mm_shuffle_ps(v77, v77, 0)),
                                      _mm_shuffle_ps(v77, v77, 170)),
                                    _mm_shuffle_ps(
                                      (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                      (__m128)LODWORD(in->m_rhsFactor.m_storage),
                                      0))),
                                196);
    jac->m_linear0.m_quad = _mm_shuffle_ps(
                              jac->m_linear0.m_quad,
                              _mm_unpackhi_ps(jac->m_linear0.m_quad, _mm_shuffle_ps(v78, v78, 0)),
                              196);
    jac[1].m_linear0.m_quad = _mm_shuffle_ps(
                                jac[1].m_linear0.m_quad,
                                _mm_unpackhi_ps(jac[1].m_linear0.m_quad, _mm_shuffle_ps(v78, v78, 85)),
                                196);
    jac[2].m_linear0.m_quad = _mm_shuffle_ps(
                                jac[2].m_linear0.m_quad,
                                _mm_unpackhi_ps(jac[2].m_linear0.m_quad, _mm_shuffle_ps(v78, v78, 170)),
                                196);
  }
}

