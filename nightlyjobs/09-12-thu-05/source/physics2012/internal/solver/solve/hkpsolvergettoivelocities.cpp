// File Line: 96
// RVA: 0xDE5360
__int64 __fastcall hkSolveGetToiViolatingConstraintVelocity(
        hkpSolverInfo *i,
        hkpJacobianSchema *schemas,
        hkpVelocityAccumulator *accums,
        int maxNumVelocities,
        float *velocitiesOut)
{
  unsigned int v5; // ebx
  int v9; // esi
  hkpVelocityAccumulator *v10; // r10
  hkpVelocityAccumulator *v11; // r11
  __m128 *v12; // rdx
  int v13; // r14d
  int v14; // r15d
  int v15; // r8d
  int v16; // r9d
  int m_gravityFactor_low; // xmm0_4
  char m_storage; // al
  __m128 v19; // xmm10
  int v20; // eax
  __int128 m_invMasses; // xmm0
  __m128 v22; // xmm7
  __int128 m_scratch3; // xmm1
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
  __m128 m_quad; // xmm0
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
  char v66[4]; // [rsp+0h] [rbp-100h] BYREF
  unsigned int m_deactivationClass; // [rsp+4h] [rbp-FCh]
  int v68; // [rsp+8h] [rbp-F8h]
  __m128 v69; // [rsp+10h] [rbp-F0h]
  __m128 v70; // [rsp+20h] [rbp-E0h]
  __int128 v71; // [rsp+30h] [rbp-D0h]
  __m128 v72; // [rsp+40h] [rbp-C0h]
  __m128 v73; // [rsp+50h] [rbp-B0h]
  hkVector4f v74; // [rsp+60h] [rbp-A0h]
  __int128 v75; // [rsp+70h] [rbp-90h]
  char v76[4]; // [rsp+80h] [rbp-80h] BYREF
  int v77; // [rsp+84h] [rbp-7Ch]
  float m_gravityFactor; // [rsp+88h] [rbp-78h]
  __m128 v79; // [rsp+90h] [rbp-70h]
  __m128 v80; // [rsp+A0h] [rbp-60h]
  hkVector4f v81; // [rsp+B0h] [rbp-50h]
  __m128 v82; // [rsp+C0h] [rbp-40h]
  __m128 v83; // [rsp+D0h] [rbp-30h]
  hkVector4f v84; // [rsp+E0h] [rbp-20h]
  __int128 v85; // [rsp+F0h] [rbp-10h]

  v5 = 0;
  if ( !*(_BYTE *)schemas )
    return 0i64;
  v9 = 1;
  v10 = &accums[(unsigned __int64)*(_WORD *)&schemas[4]];
  v11 = &accums[(unsigned __int64)*(_WORD *)&schemas[6]];
  v12 = (__m128 *)&schemas[32];
  v13 = 2;
  v14 = 3;
  while ( 2 )
  {
    LOBYTE(v15) = v12->m128_i8[0];
    v16 = (unsigned __int8)v12->m128_i8[0];
    switch ( v12->m128_i8[0] )
    {
      case 0:
      case 1:
      case 0x1A:
      case 0x1B:
      case 0x1C:
        return v5;
      case 2:
        v12 = (__m128 *)((char *)v12 + v12->m128_i64[1]);
        continue;
      case 3:
      case 8:
      case 9:
      case 0xA:
      case 0xC:
      case 0xD:
      case 0xE:
      case 0xF:
      case 0x1D:
      case 0x1E:
        do
        {
          v12 = (__m128 *)((char *)v12 + (unsigned __int8)hkpJacobianSchema::s_schemaSize[(unsigned __int8)v15]);
          v15 = (unsigned __int8)v12->m128_i8[0];
        }
        while ( v15 == v16 );
        continue;
      case 5:
      case 6:
        if ( v9 > maxNumVelocities )
          return v5;
        v62 = v12[2];
        ++velocitiesOut;
        ++v5;
        ++v14;
        ++v13;
        ++v9;
        v12 += 3;
        v63 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(v62, v11->m_angularVel.m_quad), _mm_mul_ps(v10->m_angularVel.m_quad, v12[-2])),
                _mm_mul_ps(_mm_sub_ps(v10->m_linearVel.m_quad, v11->m_linearVel.m_quad), v12[-3]));
        *(velocitiesOut - 1) = (float)(_mm_shuffle_ps(v63, v63, 85).m128_f32[0] + _mm_shuffle_ps(v63, v63, 0).m128_f32[0])
                             + _mm_shuffle_ps(v63, v63, 170).m128_f32[0];
        continue;
      case 7:
        if ( v9 > maxNumVelocities )
          return v5;
        v64 = v12[2];
        ++velocitiesOut;
        ++v5;
        ++v14;
        ++v13;
        ++v9;
        v12 += 4;
        v65 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(v64, v11->m_angularVel.m_quad), _mm_mul_ps(v10->m_angularVel.m_quad, v12[-3])),
                _mm_mul_ps(_mm_sub_ps(v10->m_linearVel.m_quad, v11->m_linearVel.m_quad), v12[-4]));
        *(velocitiesOut - 1) = (float)(_mm_shuffle_ps(v65, v65, 85).m128_f32[0] + _mm_shuffle_ps(v65, v65, 0).m128_f32[0])
                             + _mm_shuffle_ps(v65, v65, 170).m128_f32[0];
        continue;
      case 0x10:
        if ( v14 > maxNumVelocities )
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
        m_quad = v11->m_angularVel.m_quad;
        v39 = _mm_mul_ps(_mm_shuffle_ps(v35, v35, 201), m_quad);
        v40 = _mm_mul_ps(_mm_shuffle_ps(m_quad, m_quad, 201), v35);
        v41 = _mm_shuffle_ps(v37, v37, 201);
        v42 = v10->m_scratch2.m_quad;
        v43 = _mm_sub_ps(v39, v40);
        v44 = _mm_shuffle_ps(v42, v42, 255);
        v45 = _mm_mul_ps(v41, v42);
        v46 = _mm_shuffle_ps(v43, v43, 201);
        v47 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v42, v42, 201), v41), _mm_mul_ps(_mm_shuffle_ps(v41, v41, 201), v42));
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
        v52 = _mm_shuffle_ps(v49, v49, 255);
        v53 = _mm_sub_ps(_mm_mul_ps(_mm_shuffle_ps(v49, v49, 201), v46), _mm_mul_ps(_mm_shuffle_ps(v46, v46, 201), v49));
        v54 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_add_ps(
                      _mm_add_ps(_mm_shuffle_ps(v50, v50, 85), _mm_shuffle_ps(v50, v50, 0)),
                      _mm_shuffle_ps(v50, v50, 170)),
                    v49),
                  _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v52, v52), (__m128)xmmword_141A711B0), v46)),
                _mm_mul_ps(_mm_shuffle_ps(v53, v53, 201), v52));
        velocitiesOut += 3;
        v12 += 4;
        v55 = _mm_sub_ps(
                _mm_add_ps(_mm_sub_ps(v10->m_linearVel.m_quad, v11->m_linearVel.m_quad), _mm_add_ps(v51, v51)),
                _mm_add_ps(v54, v54));
        *(_QWORD *)(velocitiesOut - 3) = v55.m128_u64[0];
        *((_DWORD *)velocitiesOut - 1) = _mm_movehl_ps(v55, v55).m128_u32[0];
        continue;
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
        if ( v9 > maxNumVelocities )
          return v5;
        v56 = v12[2];
        ++velocitiesOut;
        ++v5;
        ++v14;
        ++v13;
        ++v9;
        v12 += 3;
        v57 = _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(v56, v11->m_angularVel.m_quad), _mm_mul_ps(v10->m_angularVel.m_quad, v12[-2])),
                _mm_mul_ps(_mm_sub_ps(v10->m_linearVel.m_quad, v11->m_linearVel.m_quad), v12[-3]));
        *(velocitiesOut - 1) = fmin(
                                 (float)(_mm_shuffle_ps(v57, v57, 85).m128_f32[0]
                                       + _mm_shuffle_ps(v57, v57, 0).m128_f32[0])
                               + _mm_shuffle_ps(v57, v57, 170).m128_f32[0],
                                 0.0);
        continue;
      case 0x18:
      case 0x19:
        if ( v13 <= maxNumVelocities )
        {
          velocitiesOut += 2;
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
          *(velocitiesOut - 2) = fmin(
                                   (float)(_mm_shuffle_ps(v60, v60, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v60, v60, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v60, v60, 170).m128_f32[0],
                                   0.0);
          v61 = _mm_add_ps(
                  _mm_add_ps(
                    _mm_mul_ps(v12[-2], v11->m_angularVel.m_quad),
                    _mm_mul_ps(v12[-3], v10->m_angularVel.m_quad)),
                  _mm_mul_ps(_mm_sub_ps(v10->m_linearVel.m_quad, v11->m_linearVel.m_quad), v12[-4]));
          *(velocitiesOut - 1) = fmin(
                                   (float)(_mm_shuffle_ps(v61, v61, 85).m128_f32[0]
                                         + _mm_shuffle_ps(v61, v61, 0).m128_f32[0])
                                 + _mm_shuffle_ps(v61, v61, 170).m128_f32[0],
                                   0.0);
          continue;
        }
        return v5;
      case 0x1F:
        v66[0] = v10->m_type.m_storage;
        v66[1] = v10->m_context.m_storage;
        m_deactivationClass = v10->m_deactivationClass;
        m_gravityFactor_low = LODWORD(v10->m_gravityFactor);
        v76[0] = v11->m_type.m_storage;
        m_storage = v11->m_context.m_storage;
        v68 = m_gravityFactor_low;
        v69 = v10->m_linearVel.m_quad;
        v19 = v10->m_angularVel.m_quad;
        v76[1] = m_storage;
        v20 = v11->m_deactivationClass;
        v70 = v19;
        m_invMasses = (__int128)v10->m_invMasses;
        v77 = v20;
        v71 = m_invMasses;
        v72 = v10->m_scratch0.m_quad;
        v73 = v10->m_scratch1.m_quad;
        v22 = _mm_mul_ps(_mm_shuffle_ps(v73, v73, 170), v12[2]);
        v74.m_quad = (__m128)v10->m_scratch2;
        m_scratch3 = (__int128)v10->m_scratch3;
        m_gravityFactor = v11->m_gravityFactor;
        v10 = (hkpVelocityAccumulator *)v66;
        v24 = v11->m_linearVel.m_quad;
        v75 = m_scratch3;
        v25 = _mm_mul_ps(_mm_shuffle_ps(v73, v73, 0), *v12);
        v26 = _mm_mul_ps(_mm_shuffle_ps(v73, v73, 85), v12[1]);
        v79 = v24;
        v80 = v11->m_angularVel.m_quad;
        v81.m_quad = (__m128)v11->m_invMasses;
        v82 = v11->m_scratch0.m_quad;
        v27 = v11->m_scratch1.m_quad;
        v72 = _mm_add_ps(v72, _mm_add_ps(_mm_add_ps(v25, v26), v22));
        v83 = v27;
        v28 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 170), v12[5]);
        v84.m_quad = (__m128)v11->m_scratch2;
        v29 = (__int128)v11->m_scratch3;
        v11 = (hkpVelocityAccumulator *)v76;
        v30 = _mm_mul_ps(_mm_shuffle_ps(v19, v19, 85), v12[1]);
        v85 = v29;
        v31 = _mm_mul_ps(_mm_shuffle_ps(v27, v27, 0), v12[3]);
        v69 = _mm_add_ps(
                v69,
                _mm_add_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v19, v19, 0), *v12), v30),
                  _mm_mul_ps(_mm_shuffle_ps(v19, v19, 170), v12[2])));
        v32 = _mm_mul_ps(_mm_shuffle_ps(v80, v80, 0), v12[3]);
        v33 = _mm_add_ps(_mm_add_ps(v31, _mm_mul_ps(_mm_shuffle_ps(v27, v27, 85), v12[4])), v28);
        v12 += 6;
        v82 = _mm_add_ps(v82, v33);
        v79 = _mm_add_ps(
                v24,
                _mm_add_ps(
                  _mm_add_ps(v32, _mm_mul_ps(_mm_shuffle_ps(v80, v80, 85), v12[-2])),
                  _mm_mul_ps(_mm_shuffle_ps(v80, v80, 170), v12[-1])));
        continue;
      default:
        continue;
    }
  }
}80, v80, 170), v12[-1])));
        continue;
      default:
        continue;
    }
  }
}

