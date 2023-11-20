// File Line: 152
// RVA: 0xDB0EA0
void __fastcall hkpMoppLongRayVirtualMachine::queryRayOnTree(hkpMoppLongRayVirtualMachine *this, hkpMoppLongRayVirtualMachine::QueryInt *query, const char *PC, hkpMoppLongRayVirtualMachine::QueryFloat *const fQuery, int chunkOffset)
{
  __m128 *v5; // rdi
  const char *v6; // rbx
  hkpMoppLongRayVirtualMachine::QueryInt *v7; // r10
  hkpMoppLongRayVirtualMachine *v8; // r11
  int v9; // esi
  float v10; // xmm0_4
  int v11; // edx
  unsigned __int8 v12; // r9
  unsigned __int8 v13; // r8
  float v14; // xmm6_4
  float v15; // xmm9_4
  float v16; // xmm8_4
  float v17; // xmm7_4
  signed __int64 v18; // rbx
  __int64 v19; // rax
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  __m128 v24; // xmm2
  hkVector4f v25; // xmm0
  float v26; // xmm10_4
  float v27; // xmm6_4
  float v28; // xmm10_4
  float v29; // xmm11_4
  float v30; // xmm9_4
  float v31; // xmm11_4
  float v32; // xmm0_4
  __m128 v33; // xmm2
  __int64 v34; // rax
  __m128 v35; // xmm0
  float v36; // xmm0_4
  __m128 v37; // xmm2
  __int64 v38; // rax
  __m128 v39; // xmm0
  int v40; // edx
  float v41; // xmm2_4
  int v42; // ecx
  float v43; // xmm5_4
  float v44; // xmm4_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  signed __int64 v47; // rdx
  __m128 v48; // xmm8
  __m128 v49; // xmm7
  float v50; // xmm3_4
  float v51; // xmm2_4
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  __m128 v54; // xmm2
  int v55; // eax
  int v56; // eax
  int v57; // eax
  int v58; // edx
  int v59; // eax
  int v60; // edx
  __int64 v61; // rax
  int v62; // eax
  int v63; // ecx
  int v64; // eax
  hkpRayShapeCollectionFilter *v65; // rcx
  unsigned int v66; // esi
  hkLifoAllocator *v67; // rax
  char (*v68)[512]; // rdi
  unsigned __int64 v69; // rcx
  __int64 v70; // rcx
  hkpShapeRayCastOutput *v71; // rax
  hkpShapeRayCastOutput *v72; // rcx
  hkpRayHitCollector *v73; // r9
  __int64 v74; // rax
  hkLifoAllocator *v75; // rax
  __int64 v76[2]; // [rsp+20h] [rbp-E0h]
  unsigned __int8 *v77; // [rsp+30h] [rbp-D0h]
  int v78; // [rsp+38h] [rbp-C8h]
  int v79; // [rsp+38h] [rbp-C8h]
  char v80; // [rsp+3Ch] [rbp-C4h]
  int v81; // [rsp+40h] [rbp-C0h]
  __m128 v82; // [rsp+50h] [rbp-B0h]
  int v83; // [rsp+60h] [rbp-A0h]
  float v84; // [rsp+64h] [rbp-9Ch]
  unsigned int v85; // [rsp+68h] [rbp-98h]
  int v86; // [rsp+6Ch] [rbp-94h]
  const char *v87; // [rsp+70h] [rbp-90h]
  hkpMoppLongRayVirtualMachine::QueryFloat fQuerya; // [rsp+80h] [rbp-80h]
  hkpMoppLongRayVirtualMachine *v89; // [rsp+160h] [rbp+60h]
  __m128 *v90; // [rsp+168h] [rbp+68h]

  v90 = &query->m_FtoBoffset.m_quad;
  v89 = this;
  v5 = (__m128 *)fQuery;
  v6 = PC;
  v7 = query;
  v8 = this;
  if ( HK_flyingcolors_mopp.m_bool )
    goto LABEL_4;
  hkpCheckKeycode();
  hkpProcessFlyingColors(&HK_flyingcolors_mopp);
  if ( HK_flyingcolors_mopp.m_bool )
  {
    v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)v90;
    v8 = v89;
LABEL_4:
    v9 = chunkOffset;
    while ( 1 )
    {
      v10 = FLOAT_510_0;
LABEL_6:
      v11 = *(unsigned __int8 *)v6;
      v12 = v6[2];
      v13 = v6[1];
      v78 = *(unsigned __int8 *)v6;
      v81 = 999;
      v87 = v6 + 2;
      v77 = (unsigned __int8 *)(v6 + 3);
      switch ( v11 )
      {
        case 0:
          return;
        case 1:
        case 2:
        case 3:
        case 4:
          v52 = _mm_unpacklo_ps(
                  _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v13), (__m128)COERCE_UNSIGNED_INT((float)*v77)),
                  _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v12), (__m128)0i64));
          v53 = 0i64;
          v53.m128_f32[0] = (float)(1 << v11);
          v54 = _mm_shuffle_ps(v53, v53, 0);
          *v5 = _mm_sub_ps(*v5, v52);
          v5[1] = _mm_sub_ps(v5[1], v52);
          *v5 = _mm_mul_ps(*v5, v54);
          v5[1] = _mm_mul_ps(v5[1], v54);
          v82 = _mm_mul_ps(_mm_add_ps(v7->m_FtoBoffset.m_quad, v52), v54);
          v6 += 4;
          v83 = v11 + v7->m_shift;
          v84 = v54.m128_f32[0] * v7->m_FtoBScale;
          v86 = v7->m_properties[0];
          v55 = v7->m_primitiveOffset;
          v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)&v82;
          v85 = v55;
          v90 = &v82;
          continue;
        case 5:
          v6 += v13 + 2;
          goto LABEL_6;
        case 6:
          v6 += 256 * v13 + v12 + 3;
          goto LABEL_6;
        case 7:
          v6 += 0x10000 * v13 + 256 * v12 + (unsigned int)*v77 + 4;
          goto LABEL_6;
        case 8:
          v6 += 0x1000000 * v13 + 256 * (*v77 + (v12 << 8)) + (unsigned int)*((unsigned __int8 *)v6 + 4) + 5;
          goto LABEL_6;
        case 9:
          if ( v7 != (hkpMoppLongRayVirtualMachine::QueryInt *)&v82 )
          {
            v82 = v7->m_FtoBoffset.m_quad;
            v83 = v7->m_shift;
            v84 = v7->m_FtoBScale;
            v10 = FLOAT_510_0;
            v85 = v7->m_primitiveOffset;
            v56 = v7->m_properties[0];
            v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)&v82;
            v86 = v56;
            v90 = &v82;
          }
          v85 += v13;
          v6 = v87;
          goto LABEL_6;
        case 10:
          if ( v7 != (hkpMoppLongRayVirtualMachine::QueryInt *)&v82 )
          {
            v82 = v7->m_FtoBoffset.m_quad;
            v83 = v7->m_shift;
            v84 = v7->m_FtoBScale;
            v10 = FLOAT_510_0;
            v85 = v7->m_primitiveOffset;
            v57 = v7->m_properties[0];
            v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)&v82;
            v86 = v57;
            v90 = &v82;
          }
          v85 += v12 + (v13 << 8);
          v6 += 3;
          goto LABEL_6;
        case 11:
          v58 = *((unsigned __int8 *)v6 + 4) + (v13 << 24) + (v12 << 16) + (*v77 << 8);
          if ( v7 != (hkpMoppLongRayVirtualMachine::QueryInt *)&v82 )
          {
            v82 = v7->m_FtoBoffset.m_quad;
            v83 = v7->m_shift;
            v84 = v7->m_FtoBScale;
            v10 = FLOAT_510_0;
            v85 = v7->m_primitiveOffset;
            v59 = v7->m_properties[0];
            v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)&v82;
            v86 = v59;
            v90 = &v82;
          }
          v85 = v58;
          goto $LN28_54;
        case 12:
          v9 = (v12 | (v13 << 8)) << 9;
          v6 = &v8->m_code->m_data.m_data[v9];
          goto LABEL_6;
        case 13:
$LN28_54:
          v6 += 5;
          goto LABEL_6;
        case 16:
        case 17:
        case 18:
          v81 = v11 - 16;
          v17 = (float)v13;
          v14 = *((float *)v5->m128_u64 + v11 - 16);
          v15 = v5[-3].m128_f32[v11];
          v16 = (float)v12;
          goto $do_compareN4;
        case 19:
          v14 = *(float *)&v5->m128_u64[1] + *((float *)v5->m128_u64 + 1);
          v15 = v5[1].m128_f32[2] + v5[1].m128_f32[1];
          v16 = (float)v12 * 2.0;
          v17 = (float)v13 * 2.0;
          goto $do_compareN4;
        case 20:
          v14 = *((float *)v5->m128_u64 + 1) - *(float *)&v5->m128_u64[1];
          v15 = v5[1].m128_f32[1] - v5[1].m128_f32[2];
          v16 = (float)((float)v12 * 2.0) - 255.0;
          v17 = (float)((float)v13 * 2.0) - 255.0;
          goto $do_compareN4;
        case 21:
          v14 = *(float *)&v5->m128_u64[1] + *(float *)v5->m128_u64;
          v15 = v5[1].m128_f32[2] + v5[1].m128_f32[0];
          v16 = (float)v12 * 2.0;
          v17 = (float)v13 * 2.0;
          goto $do_compareN4;
        case 22:
          v14 = *(float *)v5->m128_u64 - *(float *)&v5->m128_u64[1];
          v15 = v5[1].m128_f32[0] - v5[1].m128_f32[2];
          v16 = (float)((float)v12 * 2.0) - 255.0;
          v17 = (float)((float)v13 * 2.0) - 255.0;
          goto $do_compareN4;
        case 23:
          v14 = *((float *)v5->m128_u64 + 1) + *(float *)v5->m128_u64;
          v15 = v5[1].m128_f32[1] + v5[1].m128_f32[0];
          v16 = (float)v12 * 2.0;
          v17 = (float)v13 * 2.0;
          goto $do_compareN4;
        case 24:
          v14 = *(float *)v5->m128_u64 - *((float *)v5->m128_u64 + 1);
          v15 = v5[1].m128_f32[0] - v5[1].m128_f32[1];
          v16 = (float)((float)v12 * 2.0) - 255.0;
          v17 = (float)((float)v13 * 2.0) - 255.0;
          goto $do_compareN4;
        case 25:
          v14 = (float)(*((float *)v5->m128_u64 + 1) + *(float *)v5->m128_u64) + *(float *)&v5->m128_u64[1];
          v15 = (float)(v5[1].m128_f32[1] + v5[1].m128_f32[0]) + v5[1].m128_f32[2];
          v17 = (float)v13 * 3.0;
          v16 = (float)v12 * 3.0;
          goto $do_compareN4;
        case 26:
          v14 = (float)(*((float *)v5->m128_u64 + 1) + *(float *)v5->m128_u64) - *(float *)&v5->m128_u64[1];
          v15 = (float)(v5[1].m128_f32[1] + v5[1].m128_f32[0]) - v5[1].m128_f32[2];
          v17 = (float)((float)v13 * 3.0) - 255.0;
          v16 = (float)((float)v12 * 3.0) - 255.0;
          goto $do_compareN4;
        case 27:
          v14 = (float)(*(float *)v5->m128_u64 - *((float *)v5->m128_u64 + 1)) + *(float *)&v5->m128_u64[1];
          v15 = (float)(v5[1].m128_f32[0] - v5[1].m128_f32[1]) + v5[1].m128_f32[2];
          v17 = (float)((float)v13 * 3.0) - 255.0;
          v16 = (float)((float)v12 * 3.0) - 255.0;
          goto $do_compareN4;
        case 28:
          v14 = (float)(*(float *)v5->m128_u64 - *((float *)v5->m128_u64 + 1)) - *(float *)&v5->m128_u64[1];
          v15 = (float)(v5[1].m128_f32[0] - v5[1].m128_f32[1]) - v5[1].m128_f32[2];
          v17 = (float)((float)v13 * 3.0) - v10;
          v16 = (float)((float)v12 * 3.0) - v10;
$do_compareN4:
          v20 = 0;
          v18 = (signed __int64)(v6 + 4);
          v21 = *v77;
          goto LABEL_21;
        case 32:
        case 33:
        case 34:
          v18 = (signed __int64)(v6 + 3);
          v19 = v11 - 32;
          v81 = v11 - 32;
          v20 = 0;
          v21 = v12;
          v16 = (float)v13;
          v14 = *((float *)v5->m128_u64 + v19);
          v15 = v5[1].m128_f32[v19];
          v17 = v16 + 1.0;
          goto LABEL_21;
        case 35:
        case 36:
        case 37:
          v22 = v11 - 35;
          v23 = *((unsigned __int8 *)v6 + 5);
          v81 = v22;
          v17 = (float)v13;
          v16 = (float)v12;
          v14 = *((float *)v5->m128_u64 + v22);
          v15 = v5[1].m128_f32[v22];
          v20 = *((unsigned __int8 *)v6 + 4) + (*v77 << 8);
          v21 = *((unsigned __int8 *)v6 + 6) + (v23 << 8);
          v18 = (signed __int64)(v6 + 7);
LABEL_21:
          v79 = v20;
          if ( v15 < v16 && v14 < v16 )
          {
            v6 = (const char *)(v20 + v18);
            goto LABEL_6;
          }
          v6 = (const char *)(v21 + v18);
          v87 = (const char *)v21;
          if ( v14 > v17 && v15 > v17 )
            goto LABEL_6;
          v24 = *v5;
          v25.m_quad = v5[1];
          v26 = v14;
          v27 = v14 - v16;
          v28 = v26 - v17;
          v29 = v15;
          fQuerya.m_rayEnds[0].m_quad = *v5;
          fQuerya.m_rayEnds[1] = (hkVector4f)v25.m_quad;
          v30 = v15 - v16;
          v31 = v29 - v17;
          if ( v28 >= v31 )
          {
            if ( (float)(v30 * v27) < 0.0 )
              fQuerya.m_rayEnds[1].m_quad = _mm_add_ps(
                                              _mm_mul_ps(
                                                _mm_shuffle_ps(
                                                  (__m128)COERCE_UNSIGNED_INT(v27 / (float)(v27 - v30)),
                                                  (__m128)COERCE_UNSIGNED_INT(v27 / (float)(v27 - v30)),
                                                  0),
                                                _mm_sub_ps(v5[1], v24)),
                                              v24);
            hkpMoppLongRayVirtualMachine::queryRayOnTree(v8, v7, v6, &fQuerya, v9);
            if ( (float)(v31 * v28) < 0.0 )
              *v5 = _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          (__m128)COERCE_UNSIGNED_INT(v28 / (float)(v28 - v31)),
                          (__m128)COERCE_UNSIGNED_INT(v28 / (float)(v28 - v31)),
                          0),
                        _mm_sub_ps(v5[1], *v5)),
                      *v5);
            v8 = v89;
            v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)v90;
            v36 = v89->m_earlyOutHitFraction;
            if ( v36 < 1.0 )
            {
              v37 = _mm_sub_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_sub_ps(v89->m_ray.m_to.m_quad, v89->m_ray.m_from.m_quad),
                          _mm_shuffle_ps((__m128)LODWORD(v36), (__m128)LODWORD(v36), 0)),
                        v89->m_ray.m_from.m_quad),
                      v89->m_code->m_info.m_offset.m_quad);
              v38 = v81;
              v5[1] = v37;
              v39 = _mm_mul_ps(_mm_shuffle_ps((__m128)v90[1].m128_u32[1], (__m128)v90[1].m128_u32[1], 0), v37);
              v5[1] = v39;
              v5[1] = _mm_sub_ps(v39, *v90);
              if ( (signed int)v38 < 3 && v17 < v5[1].m128_f32[v38] )
                return;
            }
            v6 += v79 - (_QWORD)v87;
          }
          else
          {
            if ( (float)(v31 * v28) < 0.0 )
              fQuerya.m_rayEnds[1].m_quad = _mm_add_ps(
                                              _mm_mul_ps(
                                                _mm_shuffle_ps(
                                                  (__m128)COERCE_UNSIGNED_INT(v28 / (float)(v28 - v31)),
                                                  (__m128)COERCE_UNSIGNED_INT(v28 / (float)(v28 - v31)),
                                                  0),
                                                _mm_sub_ps(v5[1], v24)),
                                              v24);
            hkpMoppLongRayVirtualMachine::queryRayOnTree(v8, v7, &v6[v20 - (signed __int64)v21], &fQuerya, v9);
            if ( (float)(v30 * v27) < 0.0 )
              *v5 = _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          (__m128)COERCE_UNSIGNED_INT(v27 / (float)(v27 - v30)),
                          (__m128)COERCE_UNSIGNED_INT(v27 / (float)(v27 - v30)),
                          0),
                        _mm_sub_ps(v5[1], *v5)),
                      *v5);
            v8 = v89;
            v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)v90;
            v32 = v89->m_earlyOutHitFraction;
            if ( v32 < 1.0 )
            {
              v33 = _mm_sub_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_sub_ps(v89->m_ray.m_to.m_quad, v89->m_ray.m_from.m_quad),
                          _mm_shuffle_ps((__m128)LODWORD(v32), (__m128)LODWORD(v32), 0)),
                        v89->m_ray.m_from.m_quad),
                      v89->m_code->m_info.m_offset.m_quad);
              v34 = v81;
              v5[1] = v33;
              v35 = _mm_mul_ps(_mm_shuffle_ps((__m128)v90[1].m128_u32[1], (__m128)v90[1].m128_u32[1], 0), v33);
              v5[1] = v35;
              v5[1] = _mm_sub_ps(v35, *v90);
              if ( (signed int)v34 < 3 && v16 > v5[1].m128_f32[v34] )
                return;
            }
          }
          break;
        case 38:
        case 39:
        case 40:
          v6 += 3;
          v40 = v11 - 38;
          v43 = (float)v13;
          v44 = (float)v12;
          goto $doCut;
        case 41:
        case 42:
        case 43:
          v40 = v11 - 41;
          v41 = v7->m_FtoBoffset.m_quad.m128_f32[v40];
          v42 = *((unsigned __int8 *)v6 + 6)
              + ((*((unsigned __int8 *)v6 + 5) + (*((unsigned __int8 *)v6 + 4) << 8)) << 8);
          v6 += 7;
          v43 = (float)((float)((float)(*v77 + ((v12 + (v13 << 8)) << 8)) * v8->m_ItoFScale) * v7->m_FtoBScale) - v41;
          v44 = (float)((float)((float)v42 * v8->m_ItoFScale) * v7->m_FtoBScale) - v41;
$doCut:
          v45 = *((float *)v5->m128_u64 + v40);
          v46 = v5[1].m128_f32[v40];
          if ( v45 >= v46 )
          {
            if ( v45 < v43 || v46 > v44 )
              return;
            v47 = 1i64;
          }
          else
          {
            if ( v46 < v43 || v45 > v44 )
              return;
            v47 = 0i64;
          }
          v48 = *v5;
          v49 = v5[1];
          if ( (float)((float)(v46 - v44) * (float)(v45 - v44)) < 0.0 )
            v5[-v47 + 1] = _mm_add_ps(
                             _mm_mul_ps(
                               _mm_shuffle_ps(
                                 (__m128)COERCE_UNSIGNED_INT((float)(v45 - v44) / (float)((float)(v45 - v44)
                                                                                        - (float)(v46 - v44))),
                                 (__m128)COERCE_UNSIGNED_INT((float)(v45 - v44) / (float)((float)(v45 - v44)
                                                                                        - (float)(v46 - v44))),
                                 0),
                               _mm_sub_ps(v49, v48)),
                             v48);
          v50 = v46 - v43;
          v51 = v45 - v43;
          v10 = FLOAT_510_0;
          if ( (float)(v50 * v51) >= 0.0 )
            goto LABEL_6;
          v5[v47] = _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          (__m128)COERCE_UNSIGNED_INT(v51 / (float)(v51 - v50)),
                          (__m128)COERCE_UNSIGNED_INT(v51 / (float)(v51 - v50)),
                          0),
                        _mm_sub_ps(v49, v48)),
                      v48);
          continue;
        case 48:
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
        case 56:
        case 57:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 65:
        case 66:
        case 67:
        case 68:
        case 69:
        case 70:
        case 71:
        case 72:
        case 73:
        case 74:
        case 75:
        case 76:
        case 77:
        case 78:
        case 79:
          v63 = v11 - 48;
          goto $add_Terminal;
        case 80:
          v63 = v13;
          goto $add_Terminal;
        case 81:
          v63 = v12 + (v13 << 8);
          goto $add_Terminal;
        case 82:
          v63 = *v77 + ((v12 + (v13 << 8)) << 8);
          goto $add_Terminal;
        case 83:
          v63 = ((v12 + (v13 << 8)) << 16) + *((unsigned __int8 *)v6 + 4) + (*v77 << 8);
$add_Terminal:
          v64 = v63 + v7->m_primitiveOffset;
          v65 = v89->m_ray.m_rayShapeCollectionFilter;
          v66 = v64 | v89->m_reindexingMask & (v9 >> 9 << 8);
          if ( !v65
            || (LODWORD(v76[0]) = v66,
                *(_BYTE *)v65->vfptr->isCollisionEnabled(v65, (hkBool *)&v80, &v89->m_ray, v89->m_collection, v76[0])) )
          {
            v67 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            v68 = (char (*)[512])v67->m_cur;
            v69 = (unsigned __int64)&(*v68)[512];
            if ( v67->m_slabSize < 512 || (void *)v69 > v67->m_end )
              v68 = (char (*)[512])hkLifoAllocator::allocateFromNewSlab(v67, 512);
            else
              v67->m_cur = (void *)v69;
            v70 = (__int64)v89->m_collection->vfptr->getChildShape(v89->m_collection, v66, v68);
            v71 = v89->m_rayResultPtr;
            if ( v71 )
            {
              ++v71->m_shapeKeyIndex;
              (*(void (__fastcall **)(__int64, char *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))(*(_QWORD *)v70 + 40i64))(
                v70,
                &v80,
                &v89->m_ray,
                v89->m_rayResultPtr);
              --v89->m_rayResultPtr->m_shapeKeyIndex;
              if ( v80 )
              {
                v72 = v89->m_rayResultPtr;
                v89->m_hitFound = 1;
                v89->m_earlyOutHitFraction = v72->m_hitFraction;
                v72->m_shapeKeys[v72->m_shapeKeyIndex] = v66;
              }
            }
            else
            {
              v73 = v89->m_collector;
              fQuerya.m_rayEnds[1].m_quad.m128_u64[1] = (unsigned __int64)v89->m_body;
              fQuerya.m_rayEnds[1].m_quad.m128_u64[0] = *(_QWORD *)(fQuerya.m_rayEnds[1].m_quad.m128_u64[1] + 16);
              v74 = *(_QWORD *)v70;
              fQuerya.m_rayEnds[0].m_quad.m128_u64[0] = v70;
              fQuerya.m_rayEnds[0].m_quad.m128_i32[2] = v66;
              (*(void (__fastcall **)(__int64, hkpShapeRayCastInput *, hkpMoppLongRayVirtualMachine::QueryFloat *, hkpRayHitCollector *))(v74 + 48))(
                v70,
                &v89->m_ray,
                &fQuerya,
                v73);
              v89->m_earlyOutHitFraction = v89->m_collector->m_earlyOutHitFraction;
            }
            v75 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
            if ( v75->m_slabSize < 512 || &(*v68)[512] != v75->m_cur || v75->m_firstNonLifoEnd == v68 )
              hkLifoAllocator::slowBlockFree(v75, v68, 512);
            else
              v75->m_cur = v68;
          }
          return;
        case 96:
        case 97:
        case 98:
        case 99:
          v6 = v87;
          *(&v86 + (unsigned int)(v11 - 96)) = v13;
          goto $propertyCopy;
        case 100:
        case 101:
        case 102:
        case 103:
          v6 += 3;
          v60 = v12 + (v13 << 8);
          v61 = (unsigned int)(v78 - 100);
          goto LABEL_76;
        case 104:
        case 105:
        case 106:
        case 107:
          v60 = *((unsigned __int8 *)v6 + 4) + (v13 << 24) + (v12 << 16) + (*v77 << 8);
          v61 = (unsigned int)(v78 - 104);
          v6 += 5;
LABEL_76:
          *(&v86 + v61) = v60;
$propertyCopy:
          if ( v7 == (hkpMoppLongRayVirtualMachine::QueryInt *)&v82 )
            goto LABEL_6;
          v82 = v7->m_FtoBoffset.m_quad;
          v83 = v7->m_shift;
          v84 = v7->m_FtoBScale;
          v62 = v7->m_primitiveOffset;
          v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)&v82;
          v85 = v62;
          v90 = &v82;
          continue;
        case 112:
          v9 = *((unsigned __int8 *)v6 + 4) + ((*v77 + ((v12 + (v13 << 8)) << 8)) << 8);
          v6 = &v8->m_code->m_data.m_data[v9];
          goto LABEL_6;
        default:
          __debugbreak();
          goto LABEL_6;
      }
    }
  }
}

// File Line: 614
// RVA: 0xDB0C70
hkBool *__fastcall hkpMoppLongRayVirtualMachine::queryLongRay(hkpMoppLongRayVirtualMachine *this, hkBool *result, hkpShapeContainer *collection, hkpMoppCode *code, hkpShapeRayCastInput *input, hkpShapeRayCastOutput *rayResult)
{
  char *v6; // r8
  hkpMoppLongRayVirtualMachine *v7; // rbx
  hkBool *v8; // rdi
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  unsigned int v13; // eax
  hkpMoppLongRayVirtualMachine::QueryInt query; // [rsp+30h] [rbp-48h]
  hkpMoppLongRayVirtualMachine::QueryFloat fQuery; // [rsp+50h] [rbp-28h]

  this->m_code = code;
  this->m_rayResultPtr = rayResult;
  this->m_collection = collection;
  this->m_earlyOutHitFraction = 1.0;
  v6 = code->m_data.m_data;
  v7 = this;
  v8 = result;
  query.m_FtoBoffset = 0i64;
  this->m_ItoFScale = 1.0 / code->m_info.m_offset.m_quad.m128_f32[3];
  v9 = input->m_from.m_quad;
  v10 = _mm_sub_ps(input->m_to.m_quad, code->m_info.m_offset.m_quad);
  query.m_FtoBScale = code->m_info.m_offset.m_quad.m128_f32[3] * 0.000015258789;
  v11 = _mm_shuffle_ps((__m128)LODWORD(query.m_FtoBScale), (__m128)LODWORD(query.m_FtoBScale), 0);
  v12 = _mm_sub_ps(v9, code->m_info.m_offset.m_quad);
  this->m_ray.m_from.m_quad = v9;
  fQuery.m_rayEnds[1].m_quad = _mm_mul_ps(v10, v11);
  this->m_ray.m_to = input->m_to;
  v13 = input->m_filterInfo;
  fQuery.m_rayEnds[0].m_quad = _mm_mul_ps(v12, v11);
  this->m_ray.m_filterInfo = v13;
  this->m_ray.m_rayShapeCollectionFilter = input->m_rayShapeCollectionFilter;
  this->m_ray.m_collidable = input->m_collidable;
  this->m_ray.m_userData = input->m_userData;
  *(_QWORD *)&query.m_primitiveOffset = 0i64;
  query.m_shift = 0;
  this->m_hitFound = 0;
  this->m_reindexingMask = (*v6 != 13) - 1;
  hkpMoppLongRayVirtualMachine::queryRayOnTree(this, &query, v6, &fQuery, 0);
  v8->m_bool = v7->m_hitFound;
  return v8;
}

// File Line: 637
// RVA: 0xDB0D90
void __fastcall hkpMoppLongRayVirtualMachine::queryLongRay(hkpMoppLongRayVirtualMachine *this, hkpShapeContainer *collection, hkpMoppCode *code, hkpShapeRayCastInput *input, hkpCdBody *body, hkpRayHitCollector *collector)
{
  char *v6; // rdx
  float v7; // xmm0_4
  hkVector4f v8; // xmm4
  hkVector4f v9; // xmm2
  hkVector4f v10; // xmm3
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm0
  unsigned int v14; // eax
  hkpMoppLongRayVirtualMachine::QueryInt query; // [rsp+30h] [rbp-48h]
  hkpMoppLongRayVirtualMachine::QueryFloat fQuery; // [rsp+50h] [rbp-28h]

  this->m_collection = collection;
  this->m_body = body;
  this->m_collector = collector;
  this->m_rayResultPtr = 0i64;
  this->m_earlyOutHitFraction = collector->m_earlyOutHitFraction;
  this->m_code = code;
  v6 = code->m_data.m_data;
  query.m_FtoBoffset = 0i64;
  this->m_ItoFScale = 1.0 / code->m_info.m_offset.m_quad.m128_f32[3];
  v7 = code->m_info.m_offset.m_quad.m128_f32[3];
  v8.m_quad = (__m128)input->m_from;
  v9.m_quad = (__m128)input->m_to;
  v10.m_quad = (__m128)input->m_from;
  *(_QWORD *)&query.m_primitiveOffset = 0i64;
  query.m_shift = 0;
  v11 = _mm_sub_ps(v10.m_quad, code->m_info.m_offset.m_quad);
  v12 = _mm_sub_ps(v9.m_quad, code->m_info.m_offset.m_quad);
  query.m_FtoBScale = v7 * 0.000015258789;
  this->m_ray.m_from = (hkVector4f)v8.m_quad;
  v13 = _mm_shuffle_ps(
          (__m128)COERCE_UNSIGNED_INT(v7 * 0.000015258789),
          (__m128)COERCE_UNSIGNED_INT(v7 * 0.000015258789),
          0);
  this->m_ray.m_to = input->m_to;
  v14 = input->m_filterInfo;
  fQuery.m_rayEnds[0].m_quad = _mm_mul_ps(v11, v13);
  fQuery.m_rayEnds[1].m_quad = _mm_mul_ps(v12, v13);
  this->m_ray.m_filterInfo = v14;
  this->m_ray.m_rayShapeCollectionFilter = input->m_rayShapeCollectionFilter;
  this->m_ray.m_collidable = input->m_collidable;
  this->m_ray.m_userData = input->m_userData;
  this->m_hitFound = 0;
  this->m_reindexingMask = (*v6 != 13) - 1;
  hkpMoppLongRayVirtualMachine::queryRayOnTree(this, &query, v6, &fQuery, 0);
}

