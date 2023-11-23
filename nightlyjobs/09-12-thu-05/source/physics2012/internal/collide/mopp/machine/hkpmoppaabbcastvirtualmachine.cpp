// File Line: 121
// RVA: 0xDC1890
void __fastcall hkpMoppAabbCastVirtualMachine::queryRayOnTree(
        hkpMoppAabbCastVirtualMachine *this,
        hkpMoppAabbCastVirtualMachineQueryInt *query,
        char *PC,
        hkpMoppAabbCastVirtualMachineQueryFloat *const fQuery)
{
  float v8; // xmm1_4
  int v9; // r9d
  int v10; // r11d
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
  const char *v23; // rbx
  int v24; // eax
  int v25; // ecx
  int v26; // r8d
  __int64 v27; // rcx
  __m128 m_quad; // xmm2
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
  float m_earlyOutFraction; // xmm0_4
  hkpMoppAabbCastVirtualMachine::hkpAabbCastInput *m_input; // rax
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
  __int64 v52; // r8
  __m128 v53; // xmm8
  __m128 v54; // xmm7
  float v55; // xmm3_4
  float v56; // xmm2_4
  __m128 v57; // xmm3
  __m128 v58; // xmm2
  __m128 v59; // xmm2
  unsigned int m_primitiveOffset; // eax
  unsigned int v61; // eax
  unsigned int v62; // eax
  int v63; // r11d
  unsigned int v64; // eax
  int v65; // edx
  __int64 v66; // rax
  unsigned int v67; // eax
  int v68; // ecx
  unsigned __int64 m_userData; // rcx
  unsigned __int64 v70; // rdi
  hkLifoAllocator *Value; // rax
  char *m_cur; // rsi
  char *v73; // rcx
  __int64 v74; // rax
  hkpMoppAabbCastVirtualMachine *v75; // rdi
  hkpMoppAabbCastVirtualMachine::hkpAabbCastInput *v76; // r9
  hkpMoppAabbCastVirtualMachine::hkpAabbCastInput *v77; // rcx
  hkpCdPointCollector *m_castCollector; // r9
  unsigned __int64 v79; // rax
  __int64 v80; // rdx
  __int64 m_castObjectType; // rax
  hkLifoAllocator *v82; // rax
  const char *v83; // [rsp+40h] [rbp-A8h]
  int v84; // [rsp+48h] [rbp-A0h]
  hkVector4f v85; // [rsp+50h] [rbp-98h] BYREF
  hkVector4f v86; // [rsp+60h] [rbp-88h]
  float m_extentsSum3; // [rsp+70h] [rbp-78h]
  int m_shift; // [rsp+74h] [rbp-74h]
  unsigned __int64 v89; // [rsp+78h] [rbp-70h]
  hkpShapeContainer *v90; // [rsp+80h] [rbp-68h]
  hkpMoppAabbCastVirtualMachineQueryFloat fQuerya; // [rsp+88h] [rbp-60h] BYREF
  hkpMoppAabbCastVirtualMachine *v92; // [rsp+168h] [rbp+80h]
  void *retaddr; // [rsp+178h] [rbp+90h] BYREF
  int v94; // [rsp+188h] [rbp+A0h]
  unsigned int v95; // [rsp+188h] [rbp+A0h]

  v90 = 0i64;
LABEL_2:
  v8 = FLOAT_510_0;
LABEL_3:
  v9 = v94;
  while ( 2 )
  {
    v10 = (unsigned __int8)*PC;
    v11 = PC[2];
    v12 = PC[1];
    LODWORD(retaddr) = 999;
    v83 = PC + 3;
    switch ( *PC )
    {
      case 0:
        return;
      case 1:
      case 2:
      case 3:
      case 4:
        v57 = _mm_unpacklo_ps(
                _mm_unpacklo_ps(
                  (__m128)COERCE_UNSIGNED_INT((float)v12),
                  (__m128)COERCE_UNSIGNED_INT((float)*(unsigned __int8 *)v83)),
                _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v11), (__m128)0i64));
        v58 = 0i64;
        v58.m128_f32[0] = (float)(1 << v10);
        v59 = _mm_shuffle_ps(v58, v58, 0);
        fQuery->m_rayEnds[0].m_quad = _mm_sub_ps(fQuery->m_rayEnds[0].m_quad, v57);
        fQuery->m_rayEnds[1].m_quad = _mm_sub_ps(fQuery->m_rayEnds[1].m_quad, v57);
        fQuery->m_rayEnds[0].m_quad = _mm_mul_ps(fQuery->m_rayEnds[0].m_quad, v59);
        fQuery->m_rayEnds[1].m_quad = _mm_mul_ps(v59, fQuery->m_rayEnds[1].m_quad);
        v85.m_quad = _mm_mul_ps(_mm_add_ps(query->m_FtoBoffset.m_quad, v57), v59);
        PC += 4;
        m_shift = v10 + query->m_shift;
        *(float *)&v89 = v59.m128_f32[0] * query->m_FtoBScale;
        v86.m_quad = _mm_mul_ps(query->m_extents.m_quad, v59);
        v8 = FLOAT_510_0;
        m_extentsSum3 = v59.m128_f32[0] * query->m_extentsSum3;
        v86.m_quad.m128_i32[2] = query->m_properties[0];
        m_primitiveOffset = query->m_primitiveOffset;
        query = (hkpMoppAabbCastVirtualMachineQueryInt *)&v85;
        HIDWORD(v89) = m_primitiveOffset;
        continue;
      case 5:
        PC += v12 + 2;
        continue;
      case 6:
        PC += 256 * v12 + v11 + 3;
        continue;
      case 7:
        PC += 0x10000 * v12 + 256 * v11 + (unsigned int)*(unsigned __int8 *)v83 + 4;
        continue;
      case 8:
        PC += 0x1000000 * v12 + 256 * (*(unsigned __int8 *)v83 + (v11 << 8)) + (unsigned int)(unsigned __int8)PC[4] + 5;
        continue;
      case 9:
        if ( query != (hkpMoppAabbCastVirtualMachineQueryInt *)&v85 )
        {
          v85.m_quad = (__m128)query->m_FtoBoffset;
          v86.m_quad = (__m128)query->m_extents;
          v8 = FLOAT_510_0;
          m_extentsSum3 = query->m_extentsSum3;
          m_shift = query->m_shift;
          v89 = *(_QWORD *)&query->m_FtoBScale;
          v61 = query->m_properties[0];
          query = (hkpMoppAabbCastVirtualMachineQueryInt *)&v85;
          v86.m_quad.m128_i32[2] = v61;
        }
        HIDWORD(v89) += v12;
        PC += 2;
        continue;
      case 10:
        if ( query != (hkpMoppAabbCastVirtualMachineQueryInt *)&v85 )
        {
          v85.m_quad = (__m128)query->m_FtoBoffset;
          v86.m_quad = (__m128)query->m_extents;
          v8 = FLOAT_510_0;
          m_extentsSum3 = query->m_extentsSum3;
          m_shift = query->m_shift;
          v89 = *(_QWORD *)&query->m_FtoBScale;
          v62 = query->m_properties[0];
          query = (hkpMoppAabbCastVirtualMachineQueryInt *)&v85;
          v86.m_quad.m128_i32[2] = v62;
        }
        HIDWORD(v89) += v11 + (v12 << 8);
        PC += 3;
        continue;
      case 11:
        v63 = (unsigned __int8)PC[4] + (v12 << 24) + (v11 << 16) + (*(unsigned __int8 *)v83 << 8);
        if ( query != (hkpMoppAabbCastVirtualMachineQueryInt *)&v85 )
        {
          v85.m_quad = (__m128)query->m_FtoBoffset;
          v86.m_quad = (__m128)query->m_extents;
          v8 = FLOAT_510_0;
          m_extentsSum3 = query->m_extentsSum3;
          m_shift = query->m_shift;
          v89 = *(_QWORD *)&query->m_FtoBScale;
          v64 = query->m_properties[0];
          query = (hkpMoppAabbCastVirtualMachineQueryInt *)&v85;
          v86.m_quad.m128_i32[2] = v64;
        }
        HIDWORD(v89) = v63;
        goto $LN28_61;
      case 12:
        v9 = (v11 | (v12 << 8)) << 9;
        v94 = v9;
        PC = &this->m_code->m_data.m_data[v9];
        continue;
      case 13:
$LN28_61:
        PC += 5;
        continue;
      case 16:
      case 17:
      case 18:
        v27 = v10 - 16;
        LODWORD(retaddr) = v10 - 16;
        v13 = fQuery->m_rayEnds[0].m_quad.m128_f32[v27];
        v14 = fQuery->m_rayEnds[1].m_quad.m128_f32[v27];
        v17 = (float)v11 - query->m_extents.m_quad.m128_f32[v27];
        v16 = (float)v12 + query->m_extents.m_quad.m128_f32[v27];
        goto $do_compareN4_1;
      case 19:
        v13 = fQuery->m_rayEnds[0].m_quad.m128_f32[2] + fQuery->m_rayEnds[0].m_quad.m128_f32[1];
        v14 = fQuery->m_rayEnds[1].m_quad.m128_f32[2] + fQuery->m_rayEnds[1].m_quad.m128_f32[1];
        v15 = (float)(query->m_extents.m_quad.m128_f32[2] + query->m_extents.m_quad.m128_f32[1]) * 2.0;
        v16 = (float)((float)v12 * 2.0) + v15;
        v17 = (float)((float)v11 * 2.0) - v15;
        goto $do_compareN4_1;
      case 20:
        v13 = fQuery->m_rayEnds[0].m_quad.m128_f32[1] - fQuery->m_rayEnds[0].m_quad.m128_f32[2];
        v14 = fQuery->m_rayEnds[1].m_quad.m128_f32[1] - fQuery->m_rayEnds[1].m_quad.m128_f32[2];
        v18 = (float)(query->m_extents.m_quad.m128_f32[2] + query->m_extents.m_quad.m128_f32[1]) * 2.0;
        v16 = (float)((float)((float)v12 * 2.0) - 255.0) + v18;
        v17 = (float)((float)((float)v11 * 2.0) - 255.0) - v18;
        goto $do_compareN4_1;
      case 21:
        v13 = fQuery->m_rayEnds[0].m_quad.m128_f32[2] + fQuery->m_rayEnds[0].m_quad.m128_f32[0];
        v14 = fQuery->m_rayEnds[1].m_quad.m128_f32[2] + fQuery->m_rayEnds[1].m_quad.m128_f32[0];
        v19 = (float)(query->m_extents.m_quad.m128_f32[2] + query->m_extents.m_quad.m128_f32[0]) * 2.0;
        v16 = (float)((float)v12 * 2.0) + v19;
        v17 = (float)((float)v11 * 2.0) - v19;
        goto $do_compareN4_1;
      case 22:
        v13 = fQuery->m_rayEnds[0].m_quad.m128_f32[0] - fQuery->m_rayEnds[0].m_quad.m128_f32[2];
        v14 = fQuery->m_rayEnds[1].m_quad.m128_f32[0] - fQuery->m_rayEnds[1].m_quad.m128_f32[2];
        v20 = (float)(query->m_extents.m_quad.m128_f32[2] + query->m_extents.m_quad.m128_f32[0]) * 2.0;
        v16 = (float)((float)((float)v12 * 2.0) - 255.0) + v20;
        v17 = (float)((float)((float)v11 * 2.0) - 255.0) - v20;
        goto $do_compareN4_1;
      case 23:
        v13 = fQuery->m_rayEnds[0].m_quad.m128_f32[1] + fQuery->m_rayEnds[0].m_quad.m128_f32[0];
        v14 = fQuery->m_rayEnds[1].m_quad.m128_f32[1] + fQuery->m_rayEnds[1].m_quad.m128_f32[0];
        v21 = (float)(query->m_extents.m_quad.m128_f32[1] + query->m_extents.m_quad.m128_f32[0]) * 2.0;
        v16 = (float)((float)v12 * 2.0) + v21;
        v17 = (float)((float)v11 * 2.0) - v21;
        goto $do_compareN4_1;
      case 24:
        v13 = fQuery->m_rayEnds[0].m_quad.m128_f32[0] - fQuery->m_rayEnds[0].m_quad.m128_f32[1];
        v14 = fQuery->m_rayEnds[1].m_quad.m128_f32[0] - fQuery->m_rayEnds[1].m_quad.m128_f32[1];
        v22 = (float)(query->m_extents.m_quad.m128_f32[1] + query->m_extents.m_quad.m128_f32[0]) * 2.0;
        v16 = (float)((float)((float)v12 * 2.0) - 255.0) + v22;
        v17 = (float)((float)((float)v11 * 2.0) - 255.0) - v22;
        goto $do_compareN4_1;
      case 25:
        v13 = (float)(fQuery->m_rayEnds[0].m_quad.m128_f32[1] + fQuery->m_rayEnds[0].m_quad.m128_f32[0])
            + fQuery->m_rayEnds[0].m_quad.m128_f32[2];
        v14 = (float)(fQuery->m_rayEnds[1].m_quad.m128_f32[1] + fQuery->m_rayEnds[1].m_quad.m128_f32[0])
            + fQuery->m_rayEnds[1].m_quad.m128_f32[2];
        v17 = (float)((float)v11 * 3.0) - query->m_extentsSum3;
        v16 = (float)((float)v12 * 3.0) + query->m_extentsSum3;
        goto $do_compareN4_1;
      case 26:
        v13 = (float)(fQuery->m_rayEnds[0].m_quad.m128_f32[1] + fQuery->m_rayEnds[0].m_quad.m128_f32[0])
            - fQuery->m_rayEnds[0].m_quad.m128_f32[2];
        v14 = (float)(fQuery->m_rayEnds[1].m_quad.m128_f32[1] + fQuery->m_rayEnds[1].m_quad.m128_f32[0])
            - fQuery->m_rayEnds[1].m_quad.m128_f32[2];
        v17 = (float)((float)((float)v11 * 3.0) - 255.0) - query->m_extentsSum3;
        v16 = (float)((float)((float)v12 * 3.0) - 255.0) + query->m_extentsSum3;
        goto $do_compareN4_1;
      case 27:
        v13 = (float)(fQuery->m_rayEnds[0].m_quad.m128_f32[0] - fQuery->m_rayEnds[0].m_quad.m128_f32[1])
            + fQuery->m_rayEnds[0].m_quad.m128_f32[2];
        v14 = (float)(fQuery->m_rayEnds[1].m_quad.m128_f32[0] - fQuery->m_rayEnds[1].m_quad.m128_f32[1])
            + fQuery->m_rayEnds[1].m_quad.m128_f32[2];
        v17 = (float)((float)((float)v11 * 3.0) - 255.0) - query->m_extentsSum3;
        v16 = (float)((float)((float)v12 * 3.0) - 255.0) + query->m_extentsSum3;
        goto $do_compareN4_1;
      case 28:
        v13 = (float)(fQuery->m_rayEnds[0].m_quad.m128_f32[0] - fQuery->m_rayEnds[0].m_quad.m128_f32[1])
            - fQuery->m_rayEnds[0].m_quad.m128_f32[2];
        v14 = (float)(fQuery->m_rayEnds[1].m_quad.m128_f32[0] - fQuery->m_rayEnds[1].m_quad.m128_f32[1])
            - fQuery->m_rayEnds[1].m_quad.m128_f32[2];
        v17 = (float)((float)((float)v11 * 3.0) - v8) - query->m_extentsSum3;
        v16 = (float)((float)((float)v12 * 3.0) - v8) + query->m_extentsSum3;
$do_compareN4_1:
        v25 = 0;
        v23 = PC + 4;
        v26 = *(unsigned __int8 *)v83;
        goto LABEL_19;
      case 32:
      case 33:
      case 34:
        v23 = PC + 3;
        v24 = v12;
        v25 = 0;
        v26 = v11;
        LODWORD(retaddr) = v10 - 32;
        v17 = (float)v24 - query[-2].m_extents.m_quad.m128_f32[v10];
        v13 = fQuery[-4].m_rayEnds[0].m_quad.m128_f32[v10];
        v14 = fQuery[-4].m_rayEnds[1].m_quad.m128_f32[v10];
        v16 = (float)((float)v24 + 1.0) + query[-2].m_extents.m_quad.m128_f32[v10];
        goto LABEL_19;
      case 35:
      case 36:
      case 37:
        LODWORD(retaddr) = v10 - 35;
        v13 = *((float *)&fQuery[-4] + v10 - 3);
        v14 = *((float *)&fQuery[-3] + v10 - 7);
        v17 = (float)v11 - *((float *)&query[-1] + v10 - 15);
        v16 = (float)v12 + *((float *)&query[-1] + v10 - 15);
        v25 = (unsigned __int8)PC[4] + (*(unsigned __int8 *)v83 << 8);
        v26 = (unsigned __int8)PC[6] + ((unsigned __int8)PC[5] << 8);
        v23 = PC + 7;
LABEL_19:
        v84 = v25;
        if ( v14 < v17 && v13 < v17 )
        {
          PC = (char *)&v23[v25];
          continue;
        }
        PC = (char *)&v23[v26];
        v89 = v26;
        if ( v13 > v16 && v14 > v16 )
          continue;
        m_quad = fQuery->m_rayEnds[0].m_quad;
        v29.m_quad = (__m128)fQuery->m_rayEnds[1];
        v30 = v13;
        v31 = v13 - v17;
        v32 = v30 - v16;
        v33 = v14;
        fQuerya.m_rayEnds[0] = fQuery->m_rayEnds[0];
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
                                              _mm_sub_ps(fQuery->m_rayEnds[1].m_quad, m_quad)),
                                            m_quad);
          hkpMoppAabbCastVirtualMachine::queryRayOnTree(v92, query, PC, &fQuerya, v9);
          if ( (float)(v35 * v32) < 0.0 )
            fQuery->m_rayEnds[0].m_quad = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_shuffle_ps(
                                                (__m128)COERCE_UNSIGNED_INT(v32 / (float)(v32 - v35)),
                                                (__m128)COERCE_UNSIGNED_INT(v32 / (float)(v32 - v35)),
                                                0),
                                              _mm_sub_ps(fQuery->m_rayEnds[1].m_quad, fQuery->m_rayEnds[0].m_quad)),
                                            fQuery->m_rayEnds[0].m_quad);
          this = v92;
          m_earlyOutFraction = v92->m_earlyOutFraction;
          if ( m_earlyOutFraction < v92->m_refEarlyOutFraction )
          {
            m_input = v92->m_input;
            v92->m_refEarlyOutFraction = m_earlyOutFraction;
            v42 = _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_sub_ps(m_input->m_to.m_quad, m_input->m_from.m_quad),
                        _mm_shuffle_ps((__m128)LODWORD(m_earlyOutFraction), (__m128)LODWORD(m_earlyOutFraction), 0)),
                      m_input->m_from.m_quad),
                    this->m_code->m_info.m_offset.m_quad);
            fQuery->m_rayEnds[1].m_quad = v42;
            v43 = _mm_mul_ps(
                    _mm_shuffle_ps((__m128)LODWORD(query->m_FtoBScale), (__m128)LODWORD(query->m_FtoBScale), 0),
                    v42);
            fQuery->m_rayEnds[1].m_quad = v43;
            fQuery->m_rayEnds[1].m_quad = _mm_sub_ps(v43, query->m_FtoBoffset.m_quad);
            if ( (int)retaddr < 3 && v16 < fQuery->m_rayEnds[1].m_quad.m128_f32[(int)retaddr] )
              return;
          }
          PC += v84 - v89;
          goto LABEL_2;
        }
        if ( (float)(v35 * v32) < 0.0 )
          fQuerya.m_rayEnds[1].m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(
                                              (__m128)COERCE_UNSIGNED_INT(v32 / (float)(v32 - v35)),
                                              (__m128)COERCE_UNSIGNED_INT(v32 / (float)(v32 - v35)),
                                              0),
                                            _mm_sub_ps(fQuery->m_rayEnds[1].m_quad, m_quad)),
                                          m_quad);
        hkpMoppAabbCastVirtualMachine::queryRayOnTree(v92, query, &PC[v25 - (__int64)v26], &fQuerya, v9);
        if ( (float)(v34 * v31) < 0.0 )
          fQuery->m_rayEnds[0].m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(
                                              (__m128)COERCE_UNSIGNED_INT(v31 / (float)(v31 - v34)),
                                              (__m128)COERCE_UNSIGNED_INT(v31 / (float)(v31 - v34)),
                                              0),
                                            _mm_sub_ps(fQuery->m_rayEnds[1].m_quad, fQuery->m_rayEnds[0].m_quad)),
                                          fQuery->m_rayEnds[0].m_quad);
        this = v92;
        v36 = v92->m_earlyOutFraction;
        if ( v36 >= v92->m_refEarlyOutFraction )
          goto LABEL_2;
        v37 = v92->m_input;
        v92->m_refEarlyOutFraction = v36;
        v38 = _mm_sub_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(v37->m_to.m_quad, v37->m_from.m_quad),
                    _mm_shuffle_ps((__m128)LODWORD(v36), (__m128)LODWORD(v36), 0)),
                  v37->m_from.m_quad),
                this->m_code->m_info.m_offset.m_quad);
        fQuery->m_rayEnds[1].m_quad = v38;
        v39 = _mm_mul_ps(
                _mm_shuffle_ps((__m128)LODWORD(query->m_FtoBScale), (__m128)LODWORD(query->m_FtoBScale), 0),
                v38);
        fQuery->m_rayEnds[1].m_quad = v39;
        fQuery->m_rayEnds[1].m_quad = _mm_sub_ps(v39, query->m_FtoBoffset.m_quad);
        if ( (int)retaddr >= 3 || v17 <= fQuery->m_rayEnds[1].m_quad.m128_f32[(int)retaddr] )
          goto LABEL_2;
        return;
      case 38:
      case 39:
      case 40:
        PC += 3;
        v44 = v10 - 38;
        v46 = (float)v12;
        v47 = (float)v11;
        goto LABEL_43;
      case 41:
      case 42:
      case 43:
        v44 = v10 - 41;
        v45 = (unsigned __int8)PC[6] + (((unsigned __int8)PC[5] + ((unsigned __int8)PC[4] << 8)) << 8);
        PC += 7;
        v46 = (float)((float)((float)(*(unsigned __int8 *)v83 + ((v11 + (v12 << 8)) << 8)) * this->m_ItoFScale)
                    * query->m_FtoBScale)
            - query->m_FtoBoffset.m_quad.m128_f32[v44];
        v47 = (float)((float)((float)v45 * this->m_ItoFScale) * query->m_FtoBScale)
            - query->m_FtoBoffset.m_quad.m128_f32[v44];
LABEL_43:
        v48 = fQuery->m_rayEnds[0].m_quad.m128_f32[v44];
        v49 = fQuery->m_rayEnds[1].m_quad.m128_f32[v44];
        v50 = v47 + query->m_extents.m_quad.m128_f32[v44];
        v51 = v46 - query->m_extents.m_quad.m128_f32[v44];
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
        v53 = fQuery->m_rayEnds[0].m_quad;
        v54 = fQuery->m_rayEnds[1].m_quad;
        if ( (float)((float)(v49 - v50) * (float)(v48 - v50)) < 0.0 )
          fQuery->m_rayEnds[-v52 + 1].m_quad = _mm_add_ps(
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(
                                                     (__m128)COERCE_UNSIGNED_INT(
                                                               (float)(v48 - v50)
                                                             / (float)((float)(v48 - v50) - (float)(v49 - v50))),
                                                     (__m128)COERCE_UNSIGNED_INT(
                                                               (float)(v48 - v50)
                                                             / (float)((float)(v48 - v50) - (float)(v49 - v50))),
                                                     0),
                                                   _mm_sub_ps(v54, v53)),
                                                 v53);
        v8 = FLOAT_510_0;
        v55 = v49 - v51;
        v56 = v48 - v51;
        if ( (float)(v55 * v56) < 0.0 )
        {
          fQuery->m_rayEnds[v52].m_quad = _mm_add_ps(
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
        v68 = *(unsigned __int8 *)v83 + ((v11 + (v12 << 8)) << 8);
        goto $add_Terminal_6;
      case 83:
        this = v92;
        v68 = ((v11 + (v12 << 8)) << 16) + (unsigned __int8)PC[4] + (*(unsigned __int8 *)v83 << 8);
$add_Terminal_6:
        v95 = (v68 + query->m_primitiveOffset) | this->m_reindexingMask & (v9 >> 9 << 8);
        m_userData = this->m_input->m_moppBody->m_shape[2].m_userData;
        if ( m_userData )
        {
          v70 = m_userData + 32;
          v90 = (hkpShapeContainer *)(m_userData + 32);
        }
        else
        {
          v70 = 0i64;
        }
        Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        m_cur = (char *)Value->m_cur;
        v73 = m_cur + 512;
        if ( Value->m_slabSize < 512 || v73 > Value->m_end )
          m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, 512);
        else
          Value->m_cur = v73;
        v74 = (*(__int64 (__fastcall **)(unsigned __int64, _QWORD, char *))(*(_QWORD *)v70 + 40i64))(v70, v95, m_cur);
        v75 = v92;
        v76 = v92->m_input;
        v89 = v74;
        if ( v76->m_collisionInput->m_filter.m_storage->vfptr->isCollisionEnabled(
               &v76->m_collisionInput->m_filter.m_storage->hkpShapeCollectionFilter,
               (hkBool *)&retaddr,
               v76->m_collisionInput,
               v76->m_castBody,
               v76->m_moppBody,
               v90,
               v95)->m_bool )
        {
          v77 = v75->m_input;
          m_castCollector = v75->m_castCollector;
          fQuerya.m_rayEnds[1].m_quad.m128_u64[1] = (unsigned __int64)v77->m_moppBody;
          v79 = *(_QWORD *)(fQuerya.m_rayEnds[1].m_quad.m128_u64[1] + 16);
          fQuerya.m_rayEnds[0].m_quad.m128_u64[0] = v89;
          v80 = *(unsigned __int8 *)(v89 + 16);
          fQuerya.m_rayEnds[1].m_quad.m128_u64[0] = v79;
          m_castObjectType = v75->m_castObjectType;
          fQuerya.m_rayEnds[0].m_quad.m128_i32[2] = v95;
          v77->m_collisionInput->m_dispatcher.m_storage->m_agent2Func[(unsigned __int8)v77->m_collisionInput->m_dispatcher.m_storage->m_agent2Types[m_castObjectType][v80]].m_linearCastFunc(
            v77->m_castBody,
            (hkpCdBody *)&fQuerya,
            v77->m_collisionInput,
            m_castCollector,
            v75->m_startPointCollector);
          *(float *)&retaddr = v75->m_castCollector->m_earlyOutDistance;
          v75->m_earlyOutFraction = fminf(v75->m_earlyOutFraction, *(float *)&retaddr);
        }
        v82 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
        if ( v82->m_slabSize < 512 || m_cur + 512 != v82->m_cur || v82->m_firstNonLifoEnd == m_cur )
          hkLifoAllocator::slowBlockFree(v82, m_cur, 512);
        else
          v82->m_cur = m_cur;
        return;
      case 96:
      case 97:
      case 98:
      case 99:
        PC += 2;
        v86.m_quad.m128_i32[v10 - 96 + 2] = v12;
        goto $propertyCopy_6;
      case 100:
      case 101:
      case 102:
      case 103:
        PC += 3;
        v65 = v11 + (v12 << 8);
        v66 = (unsigned int)(v10 - 100);
        goto LABEL_74;
      case 104:
      case 105:
      case 106:
      case 107:
        v65 = (unsigned __int8)PC[4] + (v12 << 24) + (v11 << 16) + (*(unsigned __int8 *)v83 << 8);
        v66 = (unsigned int)(v10 - 104);
        PC += 5;
LABEL_74:
        v86.m_quad.m128_i32[v66 + 2] = v65;
        this = v92;
$propertyCopy_6:
        if ( query == (hkpMoppAabbCastVirtualMachineQueryInt *)&v85 )
          goto LABEL_3;
        v85.m_quad = (__m128)query->m_FtoBoffset;
        v86.m_quad = (__m128)query->m_extents;
        v8 = FLOAT_510_0;
        m_extentsSum3 = query->m_extentsSum3;
        m_shift = query->m_shift;
        *(float *)&v89 = query->m_FtoBScale;
        v67 = query->m_primitiveOffset;
        query = (hkpMoppAabbCastVirtualMachineQueryInt *)&v85;
        HIDWORD(v89) = v67;
        continue;
      case 112:
        v9 = (unsigned __int8)PC[4] + ((*(unsigned __int8 *)v83 + ((v11 + (v12 << 8)) << 8)) << 8);
        v94 = v9;
        PC = &this->m_code->m_data.m_data[v9];
        continue;
      default:
        __debugbreak();
        continue;
    }
  }
}

// File Line: 535
// RVA: 0xDC1730
void __fastcall hkpMoppAabbCastVirtualMachine::aabbCast(
        hkpMoppAabbCastVirtualMachine *this,
        hkpMoppAabbCastVirtualMachine::hkpAabbCastInput *input,
        hkpCdPointCollector *castCollector,
        hkpCdPointCollector *startCollector)
{
  hkpMoppCode *v8; // rdx
  hkcdShapeType::ShapeTypeEnum m_storage; // eax
  const char *m_data; // r8
  hkVector4f v11; // xmm2
  __m128 v12; // xmm3
  hkVector4f v13; // xmm2
  __m128 v14; // xmm1
  __m128 v15; // xmm2
  bool v16; // zf
  hkpMoppAabbCastVirtualMachineQueryFloat fQuery; // [rsp+30h] [rbp-68h] BYREF
  hkpMoppAabbCastVirtualMachineQueryInt query; // [rsp+50h] [rbp-48h] BYREF

  if ( HK_flyingcolors_mopp_2.m_bool
    || (hkpCheckKeycode(), hkpProcessFlyingColors(&HK_flyingcolors_mopp_2), HK_flyingcolors_mopp_2.m_bool) )
  {
    this->m_input = input;
    v8 = *(hkpMoppCode **)&input->m_moppBody->m_shape[1].m_memSizeAndFlags;
    this->m_castCollector = castCollector;
    this->m_startPointCollector = startCollector;
    this->m_code = v8;
    m_storage = (unsigned __int8)input->m_castBody->m_shape->m_type.m_storage;
    this->m_earlyOutFraction = 1.0;
    this->m_refEarlyOutFraction = 1.0;
    this->m_castObjectType = m_storage;
    m_data = v8->m_data.m_data;
    query.m_FtoBoffset = 0i64;
    this->m_ItoFScale = 1.0 / v8->m_info.m_offset.m_quad.m128_f32[3];
    v11.m_quad = (__m128)input->m_extents;
    query.m_FtoBScale = v8->m_info.m_offset.m_quad.m128_f32[3] * 0.000015258789;
    v12 = _mm_shuffle_ps((__m128)LODWORD(query.m_FtoBScale), (__m128)LODWORD(query.m_FtoBScale), 0);
    query.m_extents.m_quad = _mm_mul_ps(v11.m_quad, v12);
    v13.m_quad = (__m128)input->m_from;
    query.m_extentsSum3 = (float)((float)(_mm_shuffle_ps(query.m_extents.m_quad, query.m_extents.m_quad, 85).m128_f32[0]
                                        + _mm_shuffle_ps(query.m_extents.m_quad, query.m_extents.m_quad, 0).m128_f32[0])
                                + _mm_shuffle_ps(query.m_extents.m_quad, query.m_extents.m_quad, 170).m128_f32[0])
                        * 3.0;
    v14 = _mm_sub_ps(input->m_to.m_quad, v8->m_info.m_offset.m_quad);
    v15 = _mm_mul_ps(_mm_sub_ps(v13.m_quad, v8->m_info.m_offset.m_quad), v12);
    *(_QWORD *)&query.m_primitiveOffset = 0i64;
    query.m_shift = 0;
    v16 = *m_data == 13;
    fQuery.m_rayEnds[0].m_quad = v15;
    fQuery.m_rayEnds[1].m_quad = _mm_mul_ps(v14, v12);
    this->m_reindexingMask = !v16 - 1;
    hkpMoppAabbCastVirtualMachine::queryRayOnTree(this, &query, m_data, &fQuery, 0);
  }
}

