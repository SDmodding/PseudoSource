// File Line: 121
// RVA: 0xDC1890
void __fastcall hkpMoppAabbCastVirtualMachine::queryRayOnTree(hkpMoppAabbCastVirtualMachine *this, hkpMoppAabbCastVirtualMachineQueryInt *query, const char *PC, hkpMoppAabbCastVirtualMachineQueryFloat *const fQuery)
{
  hkpMoppAabbCastVirtualMachineQueryInt *v4; // rsi
  __m128 *v5; // rdi
  const char *v6; // rbx
  hkpMoppAabbCastVirtualMachine *v7; // rdx
  float v8; // xmm1_4
  int v9; // er9
  int v10; // er11
  unsigned __int8 v11; // r10
  unsigned __int8 v12; // r8
  float v13; // xmm8_4
  float v14; // xmm9_4
  float v15; // xmm0_4
  float v16; // xmm6_4
  float v17; // xmm7_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  signed __int64 v23; // rbx
  signed int v24; // eax
  int v25; // ecx
  int v26; // er8
  __int64 v27; // rcx
  __m128 v28; // xmm2
  hkVector4f v29; // xmm0
  float v30; // xmm10_4
  float v31; // xmm8_4
  float v32; // xmm10_4
  float v33; // xmm12_4
  float v34; // xmm9_4
  float v35; // xmm12_4
  float v36; // xmm0_4
  hkpMoppAabbCastVirtualMachine::hkpAabbCastInput *v37; // rax
  __m128 v38; // xmm2
  __m128 v39; // xmm0
  float v40; // xmm0_4
  hkpMoppAabbCastVirtualMachine::hkpAabbCastInput *v41; // rax
  __m128 v42; // xmm2
  __m128 v43; // xmm0
  __int64 v44; // r11
  int v45; // ecx
  float v46; // xmm5_4
  float v47; // xmm4_4
  float v48; // xmm2_4
  float v49; // xmm3_4
  float v50; // xmm4_4
  float v51; // xmm5_4
  signed __int64 v52; // r8
  __m128 v53; // xmm8
  __m128 v54; // xmm7
  float v55; // xmm3_4
  float v56; // xmm2_4
  __m128 v57; // xmm3
  __m128 v58; // xmm2
  __m128 v59; // xmm2
  unsigned int v60; // eax
  int v61; // eax
  int v62; // eax
  int v63; // er11
  int v64; // eax
  int v65; // edx
  __int64 v66; // rax
  unsigned int v67; // eax
  int v68; // ecx
  unsigned __int64 v69; // rcx
  signed __int64 v70; // rdi
  hkLifoAllocator *v71; // rax
  char *v72; // rsi
  unsigned __int64 v73; // rcx
  __int64 v74; // rax
  hkpMoppAabbCastVirtualMachine *v75; // rdi
  hkpMoppAabbCastVirtualMachine::hkpAabbCastInput *v76; // r9
  hkpMoppAabbCastVirtualMachine::hkpAabbCastInput *v77; // rcx
  hkpCdPointCollector *v78; // r9
  unsigned __int64 v79; // rax
  unsigned __int64 v80; // rax
  __int64 v81; // rdx
  __int64 v82; // rax
  hkpCdPointCollector *v83; // rax
  hkLifoAllocator *v84; // rax
  unsigned __int8 *v85; // [rsp+40h] [rbp-A8h]
  int v86; // [rsp+48h] [rbp-A0h]
  __m128 v87; // [rsp+50h] [rbp-98h]
  __m128 v88; // [rsp+60h] [rbp-88h]
  float v89; // [rsp+70h] [rbp-78h]
  int v90; // [rsp+74h] [rbp-74h]
  unsigned __int64 v91; // [rsp+78h] [rbp-70h]
  hkpShapeContainer *v92; // [rsp+80h] [rbp-68h]
  hkpMoppAabbCastVirtualMachineQueryFloat fQuerya; // [rsp+88h] [rbp-60h]
  hkpMoppAabbCastVirtualMachine *v94; // [rsp+168h] [rbp+80h]
  int retaddr; // [rsp+178h] [rbp+90h]
  int v96; // [rsp+188h] [rbp+A0h]
  unsigned int v97; // [rsp+188h] [rbp+A0h]

  v4 = query;
  v5 = (__m128 *)fQuery;
  v6 = PC;
  v7 = this;
  v92 = 0i64;
LABEL_2:
  v8 = FLOAT_510_0;
LABEL_3:
  v9 = v96;
  while ( 2 )
  {
    v10 = *(unsigned __int8 *)v6;
    v11 = v6[2];
    v12 = v6[1];
    retaddr = 999;
    v85 = (unsigned __int8 *)(v6 + 3);
    switch ( v10 )
    {
      case 0:
        return;
      case 1:
      case 2:
      case 3:
      case 4:
        v57 = _mm_unpacklo_ps(
                _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v12), (__m128)COERCE_UNSIGNED_INT((float)*v85)),
                _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v11), (__m128)0i64));
        v58 = 0i64;
        v58.m128_f32[0] = (float)(1 << v10);
        v59 = _mm_shuffle_ps(v58, v58, 0);
        *v5 = _mm_sub_ps(*v5, v57);
        v5[1] = _mm_sub_ps(v5[1], v57);
        *v5 = _mm_mul_ps(*v5, v59);
        v5[1] = _mm_mul_ps(v59, v5[1]);
        v87 = _mm_mul_ps(_mm_add_ps(v4->m_FtoBoffset.m_quad, v57), v59);
        v6 += 4;
        v90 = v10 + v4->m_shift;
        *(float *)&v91 = v59.m128_f32[0] * v4->m_FtoBScale;
        v88 = _mm_mul_ps(v4->m_extents.m_quad, v59);
        v8 = FLOAT_510_0;
        v89 = v59.m128_f32[0] * v4->m_extentsSum3;
        v88.m128_i32[2] = v4->m_properties[0];
        v60 = v4->m_primitiveOffset;
        v4 = (hkpMoppAabbCastVirtualMachineQueryInt *)&v87;
        HIDWORD(v91) = v60;
        continue;
      case 5:
        v6 += v12 + 2;
        continue;
      case 6:
        v6 += 256 * v12 + v11 + 3;
        continue;
      case 7:
        v6 += 0x10000 * v12 + 256 * v11 + (unsigned int)*v85 + 4;
        continue;
      case 8:
        v6 += 0x1000000 * v12 + 256 * (*v85 + (v11 << 8)) + (unsigned int)*((unsigned __int8 *)v6 + 4) + 5;
        continue;
      case 9:
        if ( v4 != (hkpMoppAabbCastVirtualMachineQueryInt *)&v87 )
        {
          v87 = v4->m_FtoBoffset.m_quad;
          v88 = v4->m_extents.m_quad;
          v8 = FLOAT_510_0;
          v89 = v4->m_extentsSum3;
          v90 = v4->m_shift;
          v91 = *(_QWORD *)&v4->m_FtoBScale;
          v61 = v4->m_properties[0];
          v4 = (hkpMoppAabbCastVirtualMachineQueryInt *)&v87;
          v88.m128_i32[2] = v61;
        }
        HIDWORD(v91) += v12;
        v6 += 2;
        continue;
      case 10:
        if ( v4 != (hkpMoppAabbCastVirtualMachineQueryInt *)&v87 )
        {
          v87 = v4->m_FtoBoffset.m_quad;
          v88 = v4->m_extents.m_quad;
          v8 = FLOAT_510_0;
          v89 = v4->m_extentsSum3;
          v90 = v4->m_shift;
          v91 = *(_QWORD *)&v4->m_FtoBScale;
          v62 = v4->m_properties[0];
          v4 = (hkpMoppAabbCastVirtualMachineQueryInt *)&v87;
          v88.m128_i32[2] = v62;
        }
        HIDWORD(v91) += v11 + (v12 << 8);
        v6 += 3;
        continue;
      case 11:
        v63 = *((unsigned __int8 *)v6 + 4) + (v12 << 24) + (v11 << 16) + (*v85 << 8);
        if ( v4 != (hkpMoppAabbCastVirtualMachineQueryInt *)&v87 )
        {
          v87 = v4->m_FtoBoffset.m_quad;
          v88 = v4->m_extents.m_quad;
          v8 = FLOAT_510_0;
          v89 = v4->m_extentsSum3;
          v90 = v4->m_shift;
          v91 = *(_QWORD *)&v4->m_FtoBScale;
          v64 = v4->m_properties[0];
          v4 = (hkpMoppAabbCastVirtualMachineQueryInt *)&v87;
          v88.m128_i32[2] = v64;
        }
        HIDWORD(v91) = v63;
        goto $LN28_61;
      case 12:
        v9 = (v11 | (v12 << 8)) << 9;
        v96 = (v11 | (v12 << 8)) << 9;
        v6 = &v7->m_code->m_data.m_data[v9];
        continue;
      case 13:
$LN28_61:
        v6 += 5;
        continue;
      case 16:
      case 17:
      case 18:
        v27 = v10 - 16;
        retaddr = v10 - 16;
        v13 = *((float *)v5->m128_u64 + v27);
        v14 = v5[1].m128_f32[v27];
        v17 = (float)v11 - v4->m_extents.m_quad.m128_f32[v27];
        v16 = (float)v12 + v4->m_extents.m_quad.m128_f32[v27];
        goto $do_compareN4_1;
      case 19:
        v13 = *(float *)&v5->m128_u64[1] + *((float *)v5->m128_u64 + 1);
        v14 = v5[1].m128_f32[2] + v5[1].m128_f32[1];
        v15 = (float)(v4->m_extents.m_quad.m128_f32[2] + v4->m_extents.m_quad.m128_f32[1]) * 2.0;
        v16 = (float)((float)v12 * 2.0) + v15;
        v17 = (float)((float)v11 * 2.0) - v15;
        goto $do_compareN4_1;
      case 20:
        v13 = *((float *)v5->m128_u64 + 1) - *(float *)&v5->m128_u64[1];
        v14 = v5[1].m128_f32[1] - v5[1].m128_f32[2];
        v18 = (float)(v4->m_extents.m_quad.m128_f32[2] + v4->m_extents.m_quad.m128_f32[1]) * 2.0;
        v16 = (float)((float)((float)v12 * 2.0) - 255.0) + v18;
        v17 = (float)((float)((float)v11 * 2.0) - 255.0) - v18;
        goto $do_compareN4_1;
      case 21:
        v13 = *(float *)&v5->m128_u64[1] + *(float *)v5->m128_u64;
        v14 = v5[1].m128_f32[2] + v5[1].m128_f32[0];
        v19 = (float)(v4->m_extents.m_quad.m128_f32[2] + v4->m_extents.m_quad.m128_f32[0]) * 2.0;
        v16 = (float)((float)v12 * 2.0) + v19;
        v17 = (float)((float)v11 * 2.0) - v19;
        goto $do_compareN4_1;
      case 22:
        v13 = *(float *)v5->m128_u64 - *(float *)&v5->m128_u64[1];
        v14 = v5[1].m128_f32[0] - v5[1].m128_f32[2];
        v20 = (float)(v4->m_extents.m_quad.m128_f32[2] + v4->m_extents.m_quad.m128_f32[0]) * 2.0;
        v16 = (float)((float)((float)v12 * 2.0) - 255.0) + v20;
        v17 = (float)((float)((float)v11 * 2.0) - 255.0) - v20;
        goto $do_compareN4_1;
      case 23:
        v13 = *((float *)v5->m128_u64 + 1) + *(float *)v5->m128_u64;
        v14 = v5[1].m128_f32[1] + v5[1].m128_f32[0];
        v21 = (float)(v4->m_extents.m_quad.m128_f32[1] + v4->m_extents.m_quad.m128_f32[0]) * 2.0;
        v16 = (float)((float)v12 * 2.0) + v21;
        v17 = (float)((float)v11 * 2.0) - v21;
        goto $do_compareN4_1;
      case 24:
        v13 = *(float *)v5->m128_u64 - *((float *)v5->m128_u64 + 1);
        v14 = v5[1].m128_f32[0] - v5[1].m128_f32[1];
        v22 = (float)(v4->m_extents.m_quad.m128_f32[1] + v4->m_extents.m_quad.m128_f32[0]) * 2.0;
        v16 = (float)((float)((float)v12 * 2.0) - 255.0) + v22;
        v17 = (float)((float)((float)v11 * 2.0) - 255.0) - v22;
        goto $do_compareN4_1;
      case 25:
        v13 = (float)(*((float *)v5->m128_u64 + 1) + *(float *)v5->m128_u64) + *(float *)&v5->m128_u64[1];
        v14 = (float)(v5[1].m128_f32[1] + v5[1].m128_f32[0]) + v5[1].m128_f32[2];
        v17 = (float)((float)v11 * 3.0) - v4->m_extentsSum3;
        v16 = (float)((float)v12 * 3.0) + v4->m_extentsSum3;
        goto $do_compareN4_1;
      case 26:
        v13 = (float)(*((float *)v5->m128_u64 + 1) + *(float *)v5->m128_u64) - *(float *)&v5->m128_u64[1];
        v14 = (float)(v5[1].m128_f32[1] + v5[1].m128_f32[0]) - v5[1].m128_f32[2];
        v17 = (float)((float)((float)v11 * 3.0) - 255.0) - v4->m_extentsSum3;
        v16 = (float)((float)((float)v12 * 3.0) - 255.0) + v4->m_extentsSum3;
        goto $do_compareN4_1;
      case 27:
        v13 = (float)(*(float *)v5->m128_u64 - *((float *)v5->m128_u64 + 1)) + *(float *)&v5->m128_u64[1];
        v14 = (float)(v5[1].m128_f32[0] - v5[1].m128_f32[1]) + v5[1].m128_f32[2];
        v17 = (float)((float)((float)v11 * 3.0) - 255.0) - v4->m_extentsSum3;
        v16 = (float)((float)((float)v12 * 3.0) - 255.0) + v4->m_extentsSum3;
        goto $do_compareN4_1;
      case 28:
        v13 = (float)(*(float *)v5->m128_u64 - *((float *)v5->m128_u64 + 1)) - *(float *)&v5->m128_u64[1];
        v14 = (float)(v5[1].m128_f32[0] - v5[1].m128_f32[1]) - v5[1].m128_f32[2];
        v17 = (float)((float)((float)v11 * 3.0) - v8) - v4->m_extentsSum3;
        v16 = (float)((float)((float)v12 * 3.0) - v8) + v4->m_extentsSum3;
$do_compareN4_1:
        v25 = 0;
        v23 = (signed __int64)(v6 + 4);
        v26 = *v85;
        goto LABEL_19;
      case 32:
      case 33:
      case 34:
        v23 = (signed __int64)(v6 + 3);
        v24 = v12;
        v25 = 0;
        v26 = v11;
        retaddr = v10 - 32;
        v17 = (float)v24 - v4->m_extents.m_quad.m128_f32[v10 - 32];
        v13 = *((float *)v5->m128_u64 + v10 - 32);
        v14 = v5[-7].m128_f32[v10];
        v16 = (float)((float)v24 + 1.0) + v4->m_extents.m_quad.m128_f32[v10 - 32];
        goto LABEL_19;
      case 35:
      case 36:
      case 37:
        retaddr = v10 - 35;
        v13 = *((float *)v5->m128_u64 + v10 - 35);
        v14 = *((float *)&v5[-7] + v10 - 3);
        v17 = (float)v11 - v4->m_extents.m_quad.m128_f32[v10 - 35];
        v16 = (float)v12 + v4->m_extents.m_quad.m128_f32[v10 - 35];
        v25 = *((unsigned __int8 *)v6 + 4) + (*v85 << 8);
        v26 = *((unsigned __int8 *)v6 + 6) + (*((unsigned __int8 *)v6 + 5) << 8);
        v23 = (signed __int64)(v6 + 7);
LABEL_19:
        v86 = v25;
        if ( v14 < v17 && v13 < v17 )
        {
          v6 = (const char *)(v25 + v23);
          continue;
        }
        v6 = (const char *)(v26 + v23);
        v91 = v26;
        if ( v13 > v16 && v14 > v16 )
          continue;
        v28 = *v5;
        v29.m_quad = v5[1];
        v30 = v13;
        v31 = v13 - v17;
        v32 = v30 - v16;
        v33 = v14;
        fQuerya.m_rayEnds[0].m_quad = *v5;
        fQuerya.m_rayEnds[1] = (hkVector4f)v29.m_quad;
        v34 = v14 - v17;
        v35 = v33 - v16;
        if ( v32 >= v35 )
        {
          if ( (float)(v34 * v31) < 0.0 )
            fQuerya.m_rayEnds[1].m_quad = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_shuffle_ps(
                                                (__m128)COERCE_UNSIGNED_INT(v31 / (float)(v31 - v34)),
                                                (__m128)COERCE_UNSIGNED_INT(v31 / (float)(v31 - v34)),
                                                0),
                                              _mm_sub_ps(v5[1], v28)),
                                            v28);
          hkpMoppAabbCastVirtualMachine::queryRayOnTree(v94, v4, v6, &fQuerya, v9);
          if ( (float)(v35 * v32) < 0.0 )
            *v5 = _mm_add_ps(
                    _mm_mul_ps(
                      _mm_shuffle_ps(
                        (__m128)COERCE_UNSIGNED_INT(v32 / (float)(v32 - v35)),
                        (__m128)COERCE_UNSIGNED_INT(v32 / (float)(v32 - v35)),
                        0),
                      _mm_sub_ps(v5[1], *v5)),
                    *v5);
          v7 = v94;
          v40 = v94->m_earlyOutFraction;
          if ( v40 < v94->m_refEarlyOutFraction )
          {
            v41 = v94->m_input;
            v94->m_refEarlyOutFraction = v40;
            v42 = _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_sub_ps(v41->m_to.m_quad, v41->m_from.m_quad),
                        _mm_shuffle_ps((__m128)LODWORD(v40), (__m128)LODWORD(v40), 0)),
                      v41->m_from.m_quad),
                    v7->m_code->m_info.m_offset.m_quad);
            v5[1] = v42;
            v43 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v4->m_FtoBScale), (__m128)LODWORD(v4->m_FtoBScale), 0), v42);
            v5[1] = v43;
            v5[1] = _mm_sub_ps(v43, v4->m_FtoBoffset.m_quad);
            if ( retaddr < 3 && v16 < v5[1].m128_f32[retaddr] )
              return;
          }
          v6 += v86 - v91;
          goto LABEL_2;
        }
        if ( (float)(v35 * v32) < 0.0 )
          fQuerya.m_rayEnds[1].m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(
                                              (__m128)COERCE_UNSIGNED_INT(v32 / (float)(v32 - v35)),
                                              (__m128)COERCE_UNSIGNED_INT(v32 / (float)(v32 - v35)),
                                              0),
                                            _mm_sub_ps(v5[1], v28)),
                                          v28);
        hkpMoppAabbCastVirtualMachine::queryRayOnTree(v94, v4, &v6[v25 - (signed __int64)v26], &fQuerya, v9);
        if ( (float)(v34 * v31) < 0.0 )
          *v5 = _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(
                      (__m128)COERCE_UNSIGNED_INT(v31 / (float)(v31 - v34)),
                      (__m128)COERCE_UNSIGNED_INT(v31 / (float)(v31 - v34)),
                      0),
                    _mm_sub_ps(v5[1], *v5)),
                  *v5);
        v7 = v94;
        v36 = v94->m_earlyOutFraction;
        if ( v36 >= v94->m_refEarlyOutFraction )
          goto LABEL_2;
        v37 = v94->m_input;
        v94->m_refEarlyOutFraction = v36;
        v38 = _mm_sub_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(v37->m_to.m_quad, v37->m_from.m_quad),
                    _mm_shuffle_ps((__m128)LODWORD(v36), (__m128)LODWORD(v36), 0)),
                  v37->m_from.m_quad),
                v7->m_code->m_info.m_offset.m_quad);
        v5[1] = v38;
        v39 = _mm_mul_ps(_mm_shuffle_ps((__m128)LODWORD(v4->m_FtoBScale), (__m128)LODWORD(v4->m_FtoBScale), 0), v38);
        v5[1] = v39;
        v5[1] = _mm_sub_ps(v39, v4->m_FtoBoffset.m_quad);
        if ( retaddr >= 3 || v17 <= v5[1].m128_f32[retaddr] )
          goto LABEL_2;
        return;
      case 38:
      case 39:
      case 40:
        v6 += 3;
        v44 = v10 - 38;
        v46 = (float)v12;
        v47 = (float)v11;
        goto LABEL_43;
      case 41:
      case 42:
      case 43:
        v44 = v10 - 41;
        v45 = *((unsigned __int8 *)v6 + 6) + ((*((unsigned __int8 *)v6 + 5) + (*((unsigned __int8 *)v6 + 4) << 8)) << 8);
        v6 += 7;
        v46 = (float)((float)((float)(*v85 + ((v11 + (v12 << 8)) << 8)) * v7->m_ItoFScale) * v4->m_FtoBScale)
            - v4->m_FtoBoffset.m_quad.m128_f32[v44];
        v47 = (float)((float)((float)v45 * v7->m_ItoFScale) * v4->m_FtoBScale) - v4->m_FtoBoffset.m_quad.m128_f32[v44];
LABEL_43:
        v48 = *((float *)v5->m128_u64 + v44);
        v49 = v5[1].m128_f32[v44];
        v50 = v47 + v4->m_extents.m_quad.m128_f32[v44];
        v51 = v46 - v4->m_extents.m_quad.m128_f32[v44];
        if ( v48 >= v49 )
        {
          if ( v48 < v51 || v49 > v50 )
            return;
          v52 = 1i64;
        }
        else
        {
          if ( v49 < v51 || v48 > v50 )
            return;
          v52 = 0i64;
        }
        v53 = *v5;
        v54 = v5[1];
        if ( (float)((float)(v49 - v50) * (float)(v48 - v50)) < 0.0 )
          v5[-v52 + 1] = _mm_add_ps(
                           _mm_mul_ps(
                             _mm_shuffle_ps(
                               (__m128)COERCE_UNSIGNED_INT((float)(v48 - v50) / (float)((float)(v48 - v50)
                                                                                      - (float)(v49 - v50))),
                               (__m128)COERCE_UNSIGNED_INT((float)(v48 - v50) / (float)((float)(v48 - v50)
                                                                                      - (float)(v49 - v50))),
                               0),
                             _mm_sub_ps(v54, v53)),
                           v53);
        v8 = FLOAT_510_0;
        v55 = v49 - v51;
        v56 = v48 - v51;
        if ( (float)(v55 * v56) < 0.0 )
        {
          v5[v52] = _mm_add_ps(
                      _mm_mul_ps(
                        _mm_shuffle_ps(
                          (__m128)COERCE_UNSIGNED_INT(v56 / (float)(v56 - v55)),
                          (__m128)COERCE_UNSIGNED_INT(v56 / (float)(v56 - v55)),
                          0),
                        _mm_sub_ps(v54, v53)),
                      v53);
          v8 = FLOAT_510_0;
        }
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
        v68 = v10 - 48;
        goto $add_Terminal_6;
      case 80:
        v68 = v12;
        goto $add_Terminal_6;
      case 81:
        v68 = v11 + (v12 << 8);
        goto $add_Terminal_6;
      case 82:
        v68 = *v85 + ((v11 + (v12 << 8)) << 8);
        goto $add_Terminal_6;
      case 83:
        v7 = v94;
        v68 = ((v11 + (v12 << 8)) << 16) + *((unsigned __int8 *)v6 + 4) + (*v85 << 8);
$add_Terminal_6:
        v97 = (v68 + v4->m_primitiveOffset) | v7->m_reindexingMask & (v9 >> 9 << 8);
        v69 = v7->m_input->m_moppBody->m_shape[2].m_userData;
        if ( v69 )
        {
          v70 = v69 + 32;
          v92 = (hkpShapeContainer *)(v69 + 32);
        }
        else
        {
          v70 = 0i64;
        }
        v71 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        v72 = (char *)v71->m_cur;
        v73 = (unsigned __int64)(v72 + 512);
        if ( v71->m_slabSize < 512 || (void *)v73 > v71->m_end )
          v72 = (char *)hkLifoAllocator::allocateFromNewSlab(v71, 512);
        else
          v71->m_cur = (void *)v73;
        v74 = (*(__int64 (__fastcall **)(signed __int64, _QWORD, char *))(*(_QWORD *)v70 + 40i64))(v70, v97, v72);
        v75 = v94;
        v76 = v94->m_input;
        v91 = v74;
        if ( *(_BYTE *)v76->m_collisionInput->m_filter.m_storage->vfptr->isCollisionEnabled(
                         (hkpShapeCollectionFilter *)&v76->m_collisionInput->m_filter.m_storage->vfptr,
                         (hkBool *)&retaddr,
                         (hkpCollisionInput *)&v76->m_collisionInput->m_dispatcher,
                         v76->m_castBody,
                         v76->m_moppBody,
                         v92,
                         v97) )
        {
          v77 = v75->m_input;
          v78 = v75->m_castCollector;
          v79 = (unsigned __int64)v77->m_moppBody;
          fQuerya.m_rayEnds[1].m_quad.m128_u64[1] = v79;
          v80 = *(_QWORD *)(v79 + 16);
          fQuerya.m_rayEnds[0].m_quad.m128_u64[0] = v91;
          v81 = *(unsigned __int8 *)(v91 + 16);
          fQuerya.m_rayEnds[1].m_quad.m128_u64[0] = v80;
          v82 = (signed int)v75->m_castObjectType;
          fQuerya.m_rayEnds[0].m_quad.m128_i32[2] = v97;
          v77->m_collisionInput->m_dispatcher.m_storage->m_agent2Func[(unsigned __int8)v77->m_collisionInput->m_dispatcher.m_storage->m_agent2Types[v82][v81]].m_linearCastFunc(
            v77->m_castBody,
            (hkpCdBody *)&fQuerya,
            v77->m_collisionInput,
            v78,
            v75->m_startPointCollector);
          v83 = v75->m_castCollector;
          retaddr = LODWORD(v83->m_earlyOutDistance);
          v75->m_earlyOutFraction = fminf(v75->m_earlyOutFraction, v83->m_earlyOutDistance);
        }
        v84 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        if ( v84->m_slabSize < 512 || v72 + 512 != v84->m_cur || v84->m_firstNonLifoEnd == v72 )
          hkLifoAllocator::slowBlockFree(v84, v72, 512);
        else
          v84->m_cur = v72;
        return;
      case 96:
      case 97:
      case 98:
      case 99:
        v6 += 2;
        v88.m128_i32[v10 - 96 + 2] = v12;
        goto $propertyCopy_6;
      case 100:
      case 101:
      case 102:
      case 103:
        v6 += 3;
        v65 = v11 + (v12 << 8);
        v66 = (unsigned int)(v10 - 100);
        goto LABEL_74;
      case 104:
      case 105:
      case 106:
      case 107:
        v65 = *((unsigned __int8 *)v6 + 4) + (v12 << 24) + (v11 << 16) + (*v85 << 8);
        v66 = (unsigned int)(v10 - 104);
        v6 += 5;
LABEL_74:
        v88.m128_i32[v66 + 2] = v65;
        v7 = v94;
$propertyCopy_6:
        if ( v4 == (hkpMoppAabbCastVirtualMachineQueryInt *)&v87 )
          goto LABEL_3;
        v87 = v4->m_FtoBoffset.m_quad;
        v88 = v4->m_extents.m_quad;
        v8 = FLOAT_510_0;
        v89 = v4->m_extentsSum3;
        v90 = v4->m_shift;
        *(float *)&v91 = v4->m_FtoBScale;
        v67 = v4->m_primitiveOffset;
        v4 = (hkpMoppAabbCastVirtualMachineQueryInt *)&v87;
        HIDWORD(v91) = v67;
        continue;
      case 112:
        v9 = *((unsigned __int8 *)v6 + 4) + ((*v85 + ((v11 + (v12 << 8)) << 8)) << 8);
        v96 = v9;
        v6 = &v7->m_code->m_data.m_data[v9];
        continue;
      default:
        __debugbreak();
        continue;
    }
  }
}
        continue;
      default:
        __debugbreak();
        continue;
    }
  }
}

// File Line: 535
// RVA: 0xDC1730
void __fastcall hkpMoppAabbCastVirtualMachine::aabbCast(hkpMoppAabbCastVirtualMachine *this, hkpMoppAabbCastVirtualMachine::hkpAabbCastInput *input, hkpCdPointCollector *castCollector, hkpCdPointCollector *startCollector)
{
  hkpCdPointCollector *v4; // rsi
  hkpCdPointCollector *v5; // rbp
  hkpMoppAabbCastVirtualMachine::hkpAabbCastInput *v6; // rdi
  hkpMoppAabbCastVirtualMachine *v7; // rbx
  __m128 *v8; // rdx
  hkcdShapeType::ShapeTypeEnum v9; // eax
  const char *v10; // r8
  __m128 v11; // xmm2
  __m128 v12; // xmm3
  __m128 v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  bool v16; // zf
  hkpMoppAabbCastVirtualMachineQueryFloat fQuery; // [rsp+30h] [rbp-68h]
  hkpMoppAabbCastVirtualMachineQueryInt query; // [rsp+50h] [rbp-48h]

  v4 = startCollector;
  v5 = castCollector;
  v6 = input;
  v7 = this;
  if ( HK_flyingcolors_mopp_2.m_bool
    || (hkpCheckKeycode(), hkpProcessFlyingColors(&HK_flyingcolors_mopp_2), HK_flyingcolors_mopp_2.m_bool) )
  {
    v7->m_input = v6;
    v8 = *(__m128 **)&v6->m_moppBody->m_shape[1].m_memSizeAndFlags;
    v7->m_castCollector = v5;
    v7->m_startPointCollector = v4;
    v7->m_code = (hkpMoppCode *)v8;
    v9 = (unsigned __int8)v6->m_castBody->m_shape->m_type.m_storage;
    v7->m_earlyOutFraction = 1.0;
    v7->m_refEarlyOutFraction = 1.0;
    v7->m_castObjectType = v9;
    v10 = (const char *)v8[2].m128_u64[0];
    query.m_FtoBoffset = 0i64;
    v7->m_ItoFScale = 1.0 / v8[1].m128_f32[3];
    v11 = v6->m_extents.m_quad;
    query.m_FtoBScale = v8[1].m128_f32[3] * 0.000015258789;
    v12 = _mm_shuffle_ps((__m128)LODWORD(query.m_FtoBScale), (__m128)LODWORD(query.m_FtoBScale), 0);
    query.m_extents.m_quad = _mm_mul_ps(v11, v12);
    v13 = v6->m_from.m_quad;
    query.m_extentsSum3 = (float)((float)(COERCE_FLOAT(_mm_shuffle_ps(query.m_extents.m_quad, query.m_extents.m_quad, 85))
                                        + COERCE_FLOAT(_mm_shuffle_ps(query.m_extents.m_quad, query.m_extents.m_quad, 0)))
                                + COERCE_FLOAT(_mm_shuffle_ps(query.m_extents.m_quad, query.m_extents.m_quad, 170)))
                        * 3.0;
    v14 = _mm_sub_ps(v6->m_to.m_quad, v8[1]);
    v15 = _mm_mul_ps(_mm_sub_ps(v13, v8[1]), v12);
    *(_QWORD *)&query.m_primitiveOffset = 0i64;
    query.m_shift = 0;
    v16 = *v10 == 13;
    fQuery.m_rayEnds[0].m_quad = v15;
    fQuery.m_rayEnds[1].m_quad = _mm_mul_ps(v14, v12);
    v7->m_reindexingMask = !v16 - 1;
    hkpMoppAabbCastVirtualMachine::queryRayOnTree(v7, &query, v10, &fQuery, 0);
  }
}

