// File Line: 96
// RVA: 0xDE5360
__int64 __fastcall hkSolveGetToiViolatingConstraintVelocity(hkpSolverInfo *i, hkpJacobianSchema *schemas, hkpVelocityAccumulator *accums, int maxNumVelocities, float *velocitiesOut)
{
  unsigned int v5; // ebx
  int v6; // er12
  float *v8; // rdi
  signed int v9; // esi
  hkpVelocityAccumulator *v10; // r10
  hkpVelocityAccumulator *v11; // r11
  __m128 *v12; // rdx
  signed int v13; // er14
  signed int v14; // er15
  int v15; // er8
  int v16; // er9
  int v17; // xmm0_4
  char v18; // al
  __m128 v19; // xmm10
  int v20; // eax
  __int128 v21; // xmm0
  __m128 v22; // xmm7
  __int128 v23; // xmm1
  __m128 v24; // xmm14
  __m128 v25; // xmm6
  __m128 v26; // xmm3
  __m128 v27; // xmm4
  __m128 v28; // xmm9
  __int128 v29; // xmm1
  __m128 v30; // xmm0
  __m128 v31; // xmm8
  __m128 v32; // xmm1
  __m128 v33; // xmm8
  __m128 v34; // xmm0
  __m128 v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm5
  __m128 v38; // xmm0
  __m128 v39; // xmm8
  __m128 v40; // xmm0
  __m128 v41; // xmm5
  __m128 v42; // xmm2
  __m128 v43; // xmm8
  __m128 v44; // xmm4
  __m128 v45; // xmm1
  __m128 v46; // xmm8
  __m128 v47; // xmm3
  __m128 v48; // xmm7
  __m128 v49; // xmm2
  __m128 v50; // xmm1
  __m128 v51; // xmm7
  __m128 v52; // xmm5
  __m128 v53; // xmm3
  __m128 v54; // xmm4
  __m128 v55; // xmm0
  __m128 v56; // xmm2
  __m128 v57; // xmm2
  __m128 v58; // xmm2
  __m128 v59; // xmm0
  __m128 v60; // xmm2
  __m128 v61; // xmm2
  __m128 v62; // xmm2
  __m128 v63; // xmm2
  __m128 v64; // xmm2
  __m128 v65; // xmm2
  char v66; // [rsp+0h] [rbp-100h]
  char v67; // [rsp+1h] [rbp-FFh]
  unsigned int v68; // [rsp+4h] [rbp-FCh]
  int v69; // [rsp+8h] [rbp-F8h]
  __m128 v70; // [rsp+10h] [rbp-F0h]
  __m128 v71; // [rsp+20h] [rbp-E0h]
  __int128 v72; // [rsp+30h] [rbp-D0h]
  __m128 v73; // [rsp+40h] [rbp-C0h]
  __m128 v74; // [rsp+50h] [rbp-B0h]
  hkVector4f v75; // [rsp+60h] [rbp-A0h]
  __int128 v76; // [rsp+70h] [rbp-90h]
  char v77; // [rsp+80h] [rbp-80h]
  char v78; // [rsp+81h] [rbp-7Fh]
  int v79; // [rsp+84h] [rbp-7Ch]
  float v80; // [rsp+88h] [rbp-78h]
  __m128 v81; // [rsp+90h] [rbp-70h]
  __m128 v82; // [rsp+A0h] [rbp-60h]
  hkVector4f v83; // [rsp+B0h] [rbp-50h]
  __m128 v84; // [rsp+C0h] [rbp-40h]
  __m128 v85; // [rsp+D0h] [rbp-30h]
  hkVector4f v86; // [rsp+E0h] [rbp-20h]
  __int128 v87; // [rsp+F0h] [rbp-10h]

  v5 = 0;
  v6 = maxNumVelocities;
  if ( !*(_BYTE *)schemas )
    return 0i64;
  v8 = velocitiesOut;
  v9 = 1;
  v10 = &accums[(unsigned __int64)*(unsigned __int16 *)&schemas[4]];
  v11 = &accums[(unsigned __int64)*(unsigned __int16 *)&schemas[6]];
  v12 = (__m128 *)&schemas[32];
  v13 = 2;
  v14 = 3;
  while ( 2 )
  {
    v15 = LOBYTE(v12->m128_u64[0]);
    v16 = LOBYTE(v12->m128_u64[0]);
    switch ( v15 )
    {
      case 0:
      case 1:
      case 26:
      case 27:
      case 28:
        return v5;
      case 2:
        v12 = (__m128 *)((char *)v12 + v12->m128_u64[1]);
        continue;
      case 3:
      case 8:
      case 9:
      case 10:
      case 12:
      case 13:
      case 14:
      case 15:
      case 29:
      case 30:
        do
        {
          v12 = (__m128 *)((char *)v12 + (unsigned __int8)hkpJacobianSchema::s_schemaSize[(unsigned __int8)v15]);
          v15 = LOBYTE(v12->m128_u64[0]);
        }
        while ( v15 == v16 );
        continue;
      case 5:
      case 6:
        if ( v9 > v6 )
          return v5;
        v62 = v12[2];
        ++v8;
        ++v5;
        ++v14;
        ++v13;
        ++v9;
        v12 += 3;
        v63 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(v62, v11->m_angularVel.m_quad), _mm_mul_ps(v10->m_angularVel.m_quad, v12[-2])),
                _mm_mul_ps(_mm_sub_ps(v10->m_linearVel.m_quad, v11->m_linearVel.m_quad), v12[-3]));
        *(v8 - 1) = (float)(COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 0)))
                  + COERCE_FLOAT(_mm_shuffle_ps(v63, v63, 170));
        continue;
      case 7:
        if ( v9 > v6 )
          return v5;
        v64 = v12[2];
        ++v8;
        ++v5;
        ++v14;
        ++v13;
        ++v9;
        v12 += 4;
        v65 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(v64, v11->m_angularVel.m_quad), _mm_mul_ps(v10->m_angularVel.m_quad, v12[-3])),
                _mm_mul_ps(_mm_sub_ps(v10->m_linearVel.m_quad, v11->m_linearVel.m_quad), v12[-4]));
        *(v8 - 1) = (float)(COERCE_FLOAT(_mm_shuffle_ps(v65, v65, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v65, v65, 0)))
                  + COERCE_FLOAT(_mm_shuffle_ps(v65, v65, 170));
        continue;
      case 16:
        if ( v14 > v6 )
          return v5;
        v5 += 3;
        v14 += 3;
        v13 += 3;
        v9 += 3;
        v34 = _mm_shuffle_ps(v12[1], v12[1], 255);
        v35 = _mm_mul_ps(v12[2], v34);
        v36 = _mm_mul_ps(v34, v12[1]);
        v37 = _mm_sub_ps(
                _mm_mul_ps(_mm_shuffle_ps(v36, v36, 201), v10->m_angularVel.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v10->m_angularVel.m_quad, v10->m_angularVel.m_quad, 201), v36));
        v38 = v11->m_angularVel.m_quad;
        v39 = _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), v38);
        v40 = _mm_mul_ps(_mm_shuffle_ps(v38, v38, 201), v35);
        v41 = _mm_shuffle_ps(v37, v37, 201);
        v42 = v10->m_scratch2.m_quad;
        v43 = _mm_sub_ps(v39, v40);
        v44 = _mm_shuffle_ps(v10->m_scratch2.m_quad, v42, 255);
        v45 = _mm_mul_ps(v41, v42);
        v46 = _mm_shuffle_ps(v43, v43, 201);
        v47 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v41), _mm_mul_ps(v41, v42));
        v48 = _mm_mul_ps(
                _mm_add_ps(
                  _mm_add_ps(_mm_shuffle_ps(v45, v45, 85), _mm_shuffle_ps(v45, v45, 0)),
                  _mm_shuffle_ps(v45, v45, 170)),
                v42);
        v49 = v11->m_scratch2.m_quad;
        v50 = _mm_mul_ps(v46, v49);
        v51 = _mm_add_ps(
                _mm_add_ps(v48, _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v44, v44), (__m128)xmmword_141A711B0), v41)),
                _mm_mul_ps(_mm_shuffle_ps(v47, v47, 201), v44));
        v52 = _mm_shuffle_ps(v11->m_scratch2.m_quad, v49, 255);
        v53 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v11->m_scratch2.m_quad, v49, 201), v46), _mm_mul_ps(v46, v49));
        v54 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                      _mm_shuffle_ps(v50, v50, 170)),
                    v49),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v52, v52), (__m128)xmmword_141A711B0), v46)),
                _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v52));
        v8 += 3;
        v12 += 4;
        v55 = _mm_sub_ps(
                _mm_add_ps(_mm_sub_ps(v10->m_linearVel.m_quad, v11->m_linearVel.m_quad), _mm_add_ps(v51, v51)),
                _mm_add_ps(v54, v54));
        *(_QWORD *)(v8 - 3) = v55.m128_u64[0];
        *((_DWORD *)v8 - 1) = (unsigned __int128)_mm_movehl_ps(v55, v55);
        continue;
      case 20:
      case 21:
      case 22:
      case 23:
        if ( v9 > v6 )
          return v5;
        v56 = v12[2];
        ++v8;
        ++v5;
        ++v14;
        ++v13;
        ++v9;
        v12 += 3;
        v57 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(v56, v11->m_angularVel.m_quad), _mm_mul_ps(v10->m_angularVel.m_quad, v12[-2])),
                _mm_mul_ps(_mm_sub_ps(v10->m_linearVel.m_quad, v11->m_linearVel.m_quad), v12[-3]));
        *(v8 - 1) = fmin(
                      (float)(COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 0)))
                    + COERCE_FLOAT(_mm_shuffle_ps(v57, v57, 170)),
                      0.0);
        continue;
      case 24:
      case 25:
        if ( v13 <= v6 )
        {
          v8 += 2;
          v5 += 2;
          v58 = _mm_mul_ps(v12[2], v11->m_angularVel.m_quad);
          v59 = _mm_mul_ps(v10->m_angularVel.m_quad, v12[1]);
          v14 += 2;
          v13 += 2;
          v9 += 2;
          v12 += 7;
          v60 = _mm_add_ps(
                  _mm_add_ps(v58, v59),
                  _mm_mul_ps(_mm_sub_ps(v10->m_linearVel.m_quad, v11->m_linearVel.m_quad), v12[-7]));
          *(v8 - 2) = fmin(
                        (float)(COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v60, v60, 170)),
                        0.0);
          v61 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(v12[-2], v11->m_angularVel.m_quad),
                    _mm_mul_ps(v12[-3], v10->m_angularVel.m_quad)),
                  _mm_mul_ps(_mm_sub_ps(v10->m_linearVel.m_quad, v11->m_linearVel.m_quad), v12[-4]));
          *(v8 - 1) = fmin(
                        (float)(COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 0)))
                      + COERCE_FLOAT(_mm_shuffle_ps(v61, v61, 170)),
                        0.0);
          continue;
        }
        return v5;
      case 31:
        v66 = v10->m_type.m_storage;
        v67 = v10->m_context.m_storage;
        v68 = v10->m_deactivationClass;
        v17 = LODWORD(v10->m_gravityFactor);
        v77 = v11->m_type.m_storage;
        v18 = v11->m_context.m_storage;
        v69 = v17;
        v70 = v10->m_linearVel.m_quad;
        v19 = v10->m_angularVel.m_quad;
        v78 = v18;
        v20 = v11->m_deactivationClass;
        v71 = v19;
        v21 = (__int128)v10->m_invMasses;
        v79 = v20;
        v72 = v21;
        v73 = v10->m_scratch0.m_quad;
        v74 = v10->m_scratch1.m_quad;
        v22 = _mm_mul_ps(_mm_shuffle_ps(v74, v74, 170), v12[2]);
        v75.m_quad = (__m128)v10->m_scratch2;
        v23 = (__int128)v10->m_scratch3;
        v80 = v11->m_gravityFactor;
        v10 = (hkpVelocityAccumulator *)&v66;
        v24 = v11->m_linearVel.m_quad;
        v76 = v23;
        v25 = _mm_mul_ps(_mm_shuffle_ps(v74, v74, 0), *v12);
        v26 = _mm_mul_ps(_mm_shuffle_ps(v74, v74, 85), v12[1]);
        v81 = v24;
        v82 = v11->m_angularVel.m_quad;
        v83.m_quad = (__m128)v11->m_invMasses;
        v84 = v11->m_scratch0.m_quad;
        v27 = v11->m_scratch1.m_quad;
        v73 = _mm_add_ps(v73, _mm_add_ps(_mm_add_ps(v25, v26), v22));
        v85 = v27;
        v28 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v12[5]);
        v86.m_quad = (__m128)v11->m_scratch2;
        v29 = (__int128)v11->m_scratch3;
        v11 = (hkpVelocityAccumulator *)&v77;
        v30 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v12[1]);
        v87 = v29;
        v31 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v12[3]);
        v70 = _mm_add_ps(
                v70,
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), *v12), v30),
                  _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v12[2])));
        v32 = _mm_mul_ps(_mm_shuffle_ps(v82, v82, 0), v12[3]);
        v33 = _mm_add_ps(_mm_add_ps(v31, _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), v12[4])), v28);
        v12 += 6;
        v84 = _mm_add_ps(v84, v33);
        v81 = _mm_add_ps(
                v24,
                _mm_add_ps(
                  _mm_add_ps(v32, _mm_mul_ps(_mm_shuffle_ps(v82, v82, 85), v12[-2])),
                  _mm_mul_ps(_mm_shuffle_ps(v82, v82, 170), v12[-1])));
        continue;
      default:
        continue;
    }
  }
}

