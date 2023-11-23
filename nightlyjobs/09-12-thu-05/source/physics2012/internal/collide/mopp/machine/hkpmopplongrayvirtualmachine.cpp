// File Line: 152
// RVA: 0xDB0EA0
void __fastcall hkpMoppLongRayVirtualMachine::queryRayOnTree(
        hkpMoppLongRayVirtualMachine *this,
        hkpMoppLongRayVirtualMachine::QueryInt *query,
        char *PC,
        hkpMoppLongRayVirtualMachine::QueryFloat *const fQuery,
        int chunkOffset)
{
  hkpMoppLongRayVirtualMachine::QueryInt *v7; // r10
  hkpMoppLongRayVirtualMachine *v8; // r11
  float v10; // xmm0_4
  int v11; // edx
  unsigned __int8 v12; // r9
  unsigned __int8 v13; // r8
  float v14; // xmm6_4
  float v15; // xmm9_4
  float v16; // xmm8_4
  float v17; // xmm7_4
  const char *v18; // rbx
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
  float m_earlyOutHitFraction; // xmm0_4
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
  __int64 v47; // rdx
  __m128 v48; // xmm8
  __m128 v49; // xmm7
  float v50; // xmm3_4
  float v51; // xmm2_4
  __m128 v52; // xmm3
  __m128 v53; // xmm2
  __m128 v54; // xmm2
  int m_primitiveOffset; // eax
  int v56; // eax
  int v57; // eax
  int v58; // edx
  int v59; // eax
  int v60; // edx
  __int64 v61; // rax
  int v62; // eax
  int v63; // ecx
  unsigned int v64; // eax
  hkpRayShapeCollectionFilter *m_rayShapeCollectionFilter; // rcx
  unsigned int v66; // esi
  hkLifoAllocator *Value; // rax
  char (*m_cur)[512]; // rdi
  char (*v69)[512]; // rcx
  hkpShape *v70; // rcx
  hkpShapeRayCastOutput *m_rayResultPtr; // rax
  hkpShapeRayCastOutput *v72; // rcx
  hkpRayHitCollector *m_collector; // r9
  hkBaseObjectVtbl *vfptr; // rax
  hkLifoAllocator *v75; // rax
  const char *v76; // [rsp+30h] [rbp-D0h]
  int v77; // [rsp+38h] [rbp-C8h]
  int v78; // [rsp+38h] [rbp-C8h]
  char v79[4]; // [rsp+3Ch] [rbp-C4h] BYREF
  int v80; // [rsp+40h] [rbp-C0h]
  __m128 m_quad; // [rsp+50h] [rbp-B0h] BYREF
  int m_shift; // [rsp+60h] [rbp-A0h]
  float m_FtoBScale; // [rsp+64h] [rbp-9Ch]
  unsigned int v84; // [rsp+68h] [rbp-98h]
  int v85; // [rsp+6Ch] [rbp-94h]
  char *v86; // [rsp+70h] [rbp-90h]
  hkpMoppLongRayVirtualMachine::QueryFloat fQuerya; // [rsp+80h] [rbp-80h] BYREF
  __m128 *p_m_quad; // [rsp+168h] [rbp+68h]

  p_m_quad = &query->m_FtoBoffset.m_quad;
  v7 = query;
  v8 = this;
  if ( !HK_flyingcolors_mopp.m_bool )
  {
    hkpCheckKeycode();
    hkpProcessFlyingColors(&HK_flyingcolors_mopp);
    if ( HK_flyingcolors_mopp.m_bool )
    {
      v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)p_m_quad;
      v8 = this;
      goto LABEL_4;
    }
    return;
  }
LABEL_4:
  while ( 2 )
  {
    v10 = FLOAT_510_0;
LABEL_5:
    v11 = (unsigned __int8)*PC;
    v12 = PC[2];
    v13 = PC[1];
    v77 = v11;
    v80 = 999;
    v86 = PC + 2;
    v76 = PC + 3;
    switch ( v11 )
    {
      case 0:
        return;
      case 1:
      case 2:
      case 3:
      case 4:
        v52 = _mm_unpacklo_ps(
                _mm_unpacklo_ps(
                  (__m128)COERCE_UNSIGNED_INT((float)v13),
                  (__m128)COERCE_UNSIGNED_INT((float)*(unsigned __int8 *)v76)),
                _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v12), (__m128)0i64));
        v53 = 0i64;
        v53.m128_f32[0] = (float)(1 << v11);
        v54 = _mm_shuffle_ps(v53, v53, 0);
        fQuery->m_rayEnds[0].m_quad = _mm_sub_ps(fQuery->m_rayEnds[0].m_quad, v52);
        fQuery->m_rayEnds[1].m_quad = _mm_sub_ps(fQuery->m_rayEnds[1].m_quad, v52);
        fQuery->m_rayEnds[0].m_quad = _mm_mul_ps(fQuery->m_rayEnds[0].m_quad, v54);
        fQuery->m_rayEnds[1].m_quad = _mm_mul_ps(fQuery->m_rayEnds[1].m_quad, v54);
        m_quad = _mm_mul_ps(_mm_add_ps(v7->m_FtoBoffset.m_quad, v52), v54);
        PC += 4;
        m_shift = v11 + v7->m_shift;
        m_FtoBScale = v54.m128_f32[0] * v7->m_FtoBScale;
        v85 = v7->m_properties[0];
        m_primitiveOffset = v7->m_primitiveOffset;
        v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)&m_quad;
        v84 = m_primitiveOffset;
        p_m_quad = &m_quad;
        continue;
      case 5:
        PC += v13 + 2;
        goto LABEL_5;
      case 6:
        PC += 256 * v13 + v12 + 3;
        goto LABEL_5;
      case 7:
        PC += 0x10000 * v13 + 256 * v12 + (unsigned int)*(unsigned __int8 *)v76 + 4;
        goto LABEL_5;
      case 8:
        PC += 0x1000000 * v13 + 256 * (*(unsigned __int8 *)v76 + (v12 << 8)) + (unsigned int)(unsigned __int8)PC[4] + 5;
        goto LABEL_5;
      case 9:
        if ( v7 != (hkpMoppLongRayVirtualMachine::QueryInt *)&m_quad )
        {
          m_quad = v7->m_FtoBoffset.m_quad;
          m_shift = v7->m_shift;
          m_FtoBScale = v7->m_FtoBScale;
          v10 = FLOAT_510_0;
          v84 = v7->m_primitiveOffset;
          v56 = v7->m_properties[0];
          v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)&m_quad;
          v85 = v56;
          p_m_quad = &m_quad;
        }
        v84 += v13;
        PC = v86;
        goto LABEL_5;
      case 10:
        if ( v7 != (hkpMoppLongRayVirtualMachine::QueryInt *)&m_quad )
        {
          m_quad = v7->m_FtoBoffset.m_quad;
          m_shift = v7->m_shift;
          m_FtoBScale = v7->m_FtoBScale;
          v10 = FLOAT_510_0;
          v84 = v7->m_primitiveOffset;
          v57 = v7->m_properties[0];
          v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)&m_quad;
          v85 = v57;
          p_m_quad = &m_quad;
        }
        v84 += v12 + (v13 << 8);
        PC += 3;
        goto LABEL_5;
      case 11:
        v58 = (unsigned __int8)PC[4] + (v13 << 24) + (v12 << 16) + (*(unsigned __int8 *)v76 << 8);
        if ( v7 != (hkpMoppLongRayVirtualMachine::QueryInt *)&m_quad )
        {
          m_quad = v7->m_FtoBoffset.m_quad;
          m_shift = v7->m_shift;
          m_FtoBScale = v7->m_FtoBScale;
          v10 = FLOAT_510_0;
          v84 = v7->m_primitiveOffset;
          v59 = v7->m_properties[0];
          v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)&m_quad;
          v85 = v59;
          p_m_quad = &m_quad;
        }
        v84 = v58;
        goto $LN28_54;
      case 12:
        chunkOffset = (v12 | (v13 << 8)) << 9;
        PC = &v8->m_code->m_data.m_data[chunkOffset];
        goto LABEL_5;
      case 13:
$LN28_54:
        PC += 5;
        goto LABEL_5;
      case 16:
      case 17:
      case 18:
        v80 = v11 - 16;
        v17 = (float)v13;
        v14 = fQuery[-2].m_rayEnds[0].m_quad.m128_f32[v11];
        v15 = fQuery[-2].m_rayEnds[1].m_quad.m128_f32[v11];
        v16 = (float)v12;
        goto $do_compareN4;
      case 19:
        v14 = fQuery->m_rayEnds[0].m_quad.m128_f32[2] + fQuery->m_rayEnds[0].m_quad.m128_f32[1];
        v15 = fQuery->m_rayEnds[1].m_quad.m128_f32[2] + fQuery->m_rayEnds[1].m_quad.m128_f32[1];
        v16 = (float)v12 * 2.0;
        v17 = (float)v13 * 2.0;
        goto $do_compareN4;
      case 20:
        v14 = fQuery->m_rayEnds[0].m_quad.m128_f32[1] - fQuery->m_rayEnds[0].m_quad.m128_f32[2];
        v15 = fQuery->m_rayEnds[1].m_quad.m128_f32[1] - fQuery->m_rayEnds[1].m_quad.m128_f32[2];
        v16 = (float)((float)v12 * 2.0) - 255.0;
        v17 = (float)((float)v13 * 2.0) - 255.0;
        goto $do_compareN4;
      case 21:
        v14 = fQuery->m_rayEnds[0].m_quad.m128_f32[2] + fQuery->m_rayEnds[0].m_quad.m128_f32[0];
        v15 = fQuery->m_rayEnds[1].m_quad.m128_f32[2] + fQuery->m_rayEnds[1].m_quad.m128_f32[0];
        v16 = (float)v12 * 2.0;
        v17 = (float)v13 * 2.0;
        goto $do_compareN4;
      case 22:
        v14 = fQuery->m_rayEnds[0].m_quad.m128_f32[0] - fQuery->m_rayEnds[0].m_quad.m128_f32[2];
        v15 = fQuery->m_rayEnds[1].m_quad.m128_f32[0] - fQuery->m_rayEnds[1].m_quad.m128_f32[2];
        v16 = (float)((float)v12 * 2.0) - 255.0;
        v17 = (float)((float)v13 * 2.0) - 255.0;
        goto $do_compareN4;
      case 23:
        v14 = fQuery->m_rayEnds[0].m_quad.m128_f32[1] + fQuery->m_rayEnds[0].m_quad.m128_f32[0];
        v15 = fQuery->m_rayEnds[1].m_quad.m128_f32[1] + fQuery->m_rayEnds[1].m_quad.m128_f32[0];
        v16 = (float)v12 * 2.0;
        v17 = (float)v13 * 2.0;
        goto $do_compareN4;
      case 24:
        v14 = fQuery->m_rayEnds[0].m_quad.m128_f32[0] - fQuery->m_rayEnds[0].m_quad.m128_f32[1];
        v15 = fQuery->m_rayEnds[1].m_quad.m128_f32[0] - fQuery->m_rayEnds[1].m_quad.m128_f32[1];
        v16 = (float)((float)v12 * 2.0) - 255.0;
        v17 = (float)((float)v13 * 2.0) - 255.0;
        goto $do_compareN4;
      case 25:
        v14 = (float)(fQuery->m_rayEnds[0].m_quad.m128_f32[1] + fQuery->m_rayEnds[0].m_quad.m128_f32[0])
            + fQuery->m_rayEnds[0].m_quad.m128_f32[2];
        v15 = (float)(fQuery->m_rayEnds[1].m_quad.m128_f32[1] + fQuery->m_rayEnds[1].m_quad.m128_f32[0])
            + fQuery->m_rayEnds[1].m_quad.m128_f32[2];
        v17 = (float)v13 * 3.0;
        v16 = (float)v12 * 3.0;
        goto $do_compareN4;
      case 26:
        v14 = (float)(fQuery->m_rayEnds[0].m_quad.m128_f32[1] + fQuery->m_rayEnds[0].m_quad.m128_f32[0])
            - fQuery->m_rayEnds[0].m_quad.m128_f32[2];
        v15 = (float)(fQuery->m_rayEnds[1].m_quad.m128_f32[1] + fQuery->m_rayEnds[1].m_quad.m128_f32[0])
            - fQuery->m_rayEnds[1].m_quad.m128_f32[2];
        v17 = (float)((float)v13 * 3.0) - 255.0;
        v16 = (float)((float)v12 * 3.0) - 255.0;
        goto $do_compareN4;
      case 27:
        v14 = (float)(fQuery->m_rayEnds[0].m_quad.m128_f32[0] - fQuery->m_rayEnds[0].m_quad.m128_f32[1])
            + fQuery->m_rayEnds[0].m_quad.m128_f32[2];
        v15 = (float)(fQuery->m_rayEnds[1].m_quad.m128_f32[0] - fQuery->m_rayEnds[1].m_quad.m128_f32[1])
            + fQuery->m_rayEnds[1].m_quad.m128_f32[2];
        v17 = (float)((float)v13 * 3.0) - 255.0;
        v16 = (float)((float)v12 * 3.0) - 255.0;
        goto $do_compareN4;
      case 28:
        v14 = (float)(fQuery->m_rayEnds[0].m_quad.m128_f32[0] - fQuery->m_rayEnds[0].m_quad.m128_f32[1])
            - fQuery->m_rayEnds[0].m_quad.m128_f32[2];
        v15 = (float)(fQuery->m_rayEnds[1].m_quad.m128_f32[0] - fQuery->m_rayEnds[1].m_quad.m128_f32[1])
            - fQuery->m_rayEnds[1].m_quad.m128_f32[2];
        v17 = (float)((float)v13 * 3.0) - v10;
        v16 = (float)((float)v12 * 3.0) - v10;
$do_compareN4:
        v20 = 0;
        v18 = PC + 4;
        v21 = *(unsigned __int8 *)v76;
        goto LABEL_20;
      case 32:
      case 33:
      case 34:
        v18 = PC + 3;
        v19 = v11 - 32;
        v80 = v11 - 32;
        v20 = 0;
        v21 = v12;
        v16 = (float)v13;
        v14 = fQuery->m_rayEnds[0].m_quad.m128_f32[v19];
        v15 = fQuery->m_rayEnds[1].m_quad.m128_f32[v19];
        v17 = v16 + 1.0;
        goto LABEL_20;
      case 35:
      case 36:
      case 37:
        v22 = v11 - 35;
        v23 = (unsigned __int8)PC[5];
        v80 = v22;
        v17 = (float)v13;
        v16 = (float)v12;
        v14 = fQuery->m_rayEnds[0].m_quad.m128_f32[v22];
        v15 = fQuery->m_rayEnds[1].m_quad.m128_f32[v22];
        v20 = (unsigned __int8)PC[4] + (*(unsigned __int8 *)v76 << 8);
        v21 = (unsigned __int8)PC[6] + (v23 << 8);
        v18 = PC + 7;
LABEL_20:
        v78 = v20;
        if ( v15 < v16 && v14 < v16 )
        {
          PC = (char *)&v18[v20];
          goto LABEL_5;
        }
        PC = (char *)&v18[v21];
        v86 = (char *)v21;
        if ( v14 > v17 && v15 > v17 )
          goto LABEL_5;
        v24 = fQuery->m_rayEnds[0].m_quad;
        v25.m_quad = (__m128)fQuery->m_rayEnds[1];
        v26 = v14;
        v27 = v14 - v16;
        v28 = v26 - v17;
        v29 = v15;
        fQuerya.m_rayEnds[0] = fQuery->m_rayEnds[0];
        fQuerya.m_rayEnds[1] = (hkVector4f)v25.m_quad;
        v30 = v15 - v16;
        v31 = v29 - v17;
        if ( v28 < v31 )
        {
          if ( (float)(v31 * v28) < 0.0 )
            fQuerya.m_rayEnds[1].m_quad = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_shuffle_ps(
                                                (__m128)COERCE_UNSIGNED_INT(v28 / (float)(v28 - v31)),
                                                (__m128)COERCE_UNSIGNED_INT(v28 / (float)(v28 - v31)),
                                                0),
                                              _mm_sub_ps(fQuery->m_rayEnds[1].m_quad, v24)),
                                            v24);
          hkpMoppLongRayVirtualMachine::queryRayOnTree(v8, v7, &PC[v20 - (__int64)v21], &fQuerya, chunkOffset);
          if ( (float)(v30 * v27) < 0.0 )
            fQuery->m_rayEnds[0].m_quad = _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_shuffle_ps(
                                                (__m128)COERCE_UNSIGNED_INT(v27 / (float)(v27 - v30)),
                                                (__m128)COERCE_UNSIGNED_INT(v27 / (float)(v27 - v30)),
                                                0),
                                              _mm_sub_ps(fQuery->m_rayEnds[1].m_quad, fQuery->m_rayEnds[0].m_quad)),
                                            fQuery->m_rayEnds[0].m_quad);
          v8 = this;
          v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)p_m_quad;
          m_earlyOutHitFraction = this->m_earlyOutHitFraction;
          if ( m_earlyOutHitFraction < 1.0 )
          {
            v33 = _mm_sub_ps(
                    _mm_add_ps(
                      _mm_mul_ps(
                        _mm_sub_ps(this->m_ray.m_to.m_quad, this->m_ray.m_from.m_quad),
                        _mm_shuffle_ps(
                          (__m128)LODWORD(m_earlyOutHitFraction),
                          (__m128)LODWORD(m_earlyOutHitFraction),
                          0)),
                      this->m_ray.m_from.m_quad),
                    this->m_code->m_info.m_offset.m_quad);
            v34 = v80;
            fQuery->m_rayEnds[1].m_quad = v33;
            v35 = _mm_mul_ps(_mm_shuffle_ps((__m128)p_m_quad[1].m128_u32[1], (__m128)p_m_quad[1].m128_u32[1], 0), v33);
            fQuery->m_rayEnds[1].m_quad = v35;
            fQuery->m_rayEnds[1].m_quad = _mm_sub_ps(v35, *p_m_quad);
            if ( (int)v34 < 3 && v16 > fQuery->m_rayEnds[1].m_quad.m128_f32[v34] )
              return;
          }
          continue;
        }
        if ( (float)(v30 * v27) < 0.0 )
          fQuerya.m_rayEnds[1].m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(
                                              (__m128)COERCE_UNSIGNED_INT(v27 / (float)(v27 - v30)),
                                              (__m128)COERCE_UNSIGNED_INT(v27 / (float)(v27 - v30)),
                                              0),
                                            _mm_sub_ps(fQuery->m_rayEnds[1].m_quad, v24)),
                                          v24);
        hkpMoppLongRayVirtualMachine::queryRayOnTree(v8, v7, PC, &fQuerya, chunkOffset);
        if ( (float)(v31 * v28) < 0.0 )
          fQuery->m_rayEnds[0].m_quad = _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(
                                              (__m128)COERCE_UNSIGNED_INT(v28 / (float)(v28 - v31)),
                                              (__m128)COERCE_UNSIGNED_INT(v28 / (float)(v28 - v31)),
                                              0),
                                            _mm_sub_ps(fQuery->m_rayEnds[1].m_quad, fQuery->m_rayEnds[0].m_quad)),
                                          fQuery->m_rayEnds[0].m_quad);
        v8 = this;
        v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)p_m_quad;
        v36 = this->m_earlyOutHitFraction;
        if ( v36 >= 1.0
          || (v37 = _mm_sub_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_sub_ps(this->m_ray.m_to.m_quad, this->m_ray.m_from.m_quad),
                          _mm_shuffle_ps((__m128)LODWORD(v36), (__m128)LODWORD(v36), 0)),
                        this->m_ray.m_from.m_quad),
                      this->m_code->m_info.m_offset.m_quad),
              v38 = v80,
              fQuery->m_rayEnds[1].m_quad = v37,
              v39 = _mm_mul_ps(_mm_shuffle_ps((__m128)p_m_quad[1].m128_u32[1], (__m128)p_m_quad[1].m128_u32[1], 0), v37),
              fQuery->m_rayEnds[1].m_quad = v39,
              fQuery->m_rayEnds[1].m_quad = _mm_sub_ps(v39, *p_m_quad),
              (int)v38 >= 3)
          || v17 >= fQuery->m_rayEnds[1].m_quad.m128_f32[v38] )
        {
          PC += v78 - (_QWORD)v86;
          continue;
        }
        return;
      case 38:
      case 39:
      case 40:
        PC += 3;
        v40 = v11 - 38;
        v43 = (float)v13;
        v44 = (float)v12;
        goto $doCut;
      case 41:
      case 42:
      case 43:
        v40 = v11 - 41;
        v41 = v7->m_FtoBoffset.m_quad.m128_f32[v40];
        v42 = (unsigned __int8)PC[6] + (((unsigned __int8)PC[5] + ((unsigned __int8)PC[4] << 8)) << 8);
        PC += 7;
        v43 = (float)((float)((float)(*(unsigned __int8 *)v76 + ((v12 + (v13 << 8)) << 8)) * v8->m_ItoFScale)
                    * v7->m_FtoBScale)
            - v41;
        v44 = (float)((float)((float)v42 * v8->m_ItoFScale) * v7->m_FtoBScale) - v41;
$doCut:
        v45 = fQuery->m_rayEnds[0].m_quad.m128_f32[v40];
        v46 = fQuery->m_rayEnds[1].m_quad.m128_f32[v40];
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
        v48 = fQuery->m_rayEnds[0].m_quad;
        v49 = fQuery->m_rayEnds[1].m_quad;
        if ( (float)((float)(v46 - v44) * (float)(v45 - v44)) < 0.0 )
          fQuery->m_rayEnds[-v47 + 1].m_quad = _mm_add_ps(
                                                 _mm_mul_ps(
                                                   _mm_shuffle_ps(
                                                     (__m128)COERCE_UNSIGNED_INT(
                                                               (float)(v45 - v44)
                                                             / (float)((float)(v45 - v44) - (float)(v46 - v44))),
                                                     (__m128)COERCE_UNSIGNED_INT(
                                                               (float)(v45 - v44)
                                                             / (float)((float)(v45 - v44) - (float)(v46 - v44))),
                                                     0),
                                                   _mm_sub_ps(v49, v48)),
                                                 v48);
        v50 = v46 - v43;
        v51 = v45 - v43;
        v10 = FLOAT_510_0;
        if ( (float)(v50 * v51) >= 0.0 )
          goto LABEL_5;
        fQuery->m_rayEnds[v47].m_quad = _mm_add_ps(
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
        v63 = *(unsigned __int8 *)v76 + ((v12 + (v13 << 8)) << 8);
        goto $add_Terminal;
      case 83:
        v63 = ((v12 + (v13 << 8)) << 16) + (unsigned __int8)PC[4] + (*(unsigned __int8 *)v76 << 8);
$add_Terminal:
        v64 = v63 + v7->m_primitiveOffset;
        m_rayShapeCollectionFilter = this->m_ray.m_rayShapeCollectionFilter;
        v66 = v64 | this->m_reindexingMask & (chunkOffset >> 9 << 8);
        if ( !m_rayShapeCollectionFilter
          || *(_BYTE *)m_rayShapeCollectionFilter->vfptr->isCollisionEnabled(
                         m_rayShapeCollectionFilter,
                         (hkBool *)v79,
                         &this->m_ray,
                         this->m_collection,
                         v66) )
        {
          Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          m_cur = (char (*)[512])Value->m_cur;
          v69 = m_cur + 1;
          if ( Value->m_slabSize < 512 || v69 > Value->m_end )
            m_cur = (char (*)[512])hkLifoAllocator::allocateFromNewSlab(Value, 512);
          else
            Value->m_cur = v69;
          v70 = this->m_collection->vfptr->getChildShape(this->m_collection, v66, m_cur);
          m_rayResultPtr = this->m_rayResultPtr;
          if ( m_rayResultPtr )
          {
            ++m_rayResultPtr->m_shapeKeyIndex;
            ((void (__fastcall *)(hkpShape *, char *, hkpShapeRayCastInput *, hkpShapeRayCastOutput *))v70->vfptr[2].__first_virtual_table_function__)(
              v70,
              v79,
              &this->m_ray,
              this->m_rayResultPtr);
            --this->m_rayResultPtr->m_shapeKeyIndex;
            if ( v79[0] )
            {
              v72 = this->m_rayResultPtr;
              this->m_hitFound = 1;
              this->m_earlyOutHitFraction = v72->m_hitFraction;
              v72->m_shapeKeys[v72->m_shapeKeyIndex] = v66;
            }
          }
          else
          {
            m_collector = this->m_collector;
            fQuerya.m_rayEnds[1].m_quad.m128_u64[1] = (unsigned __int64)this->m_body;
            fQuerya.m_rayEnds[1].m_quad.m128_u64[0] = *(_QWORD *)(fQuerya.m_rayEnds[1].m_quad.m128_u64[1] + 16);
            vfptr = v70->vfptr;
            fQuerya.m_rayEnds[0].m_quad.m128_u64[0] = (unsigned __int64)v70;
            fQuerya.m_rayEnds[0].m_quad.m128_i32[2] = v66;
            ((void (__fastcall *)(hkpShape *, hkpShapeRayCastInput *, hkpMoppLongRayVirtualMachine::QueryFloat *, hkpRayHitCollector *))vfptr[3].__vecDelDtor)(
              v70,
              &this->m_ray,
              &fQuerya,
              m_collector);
            this->m_earlyOutHitFraction = this->m_collector->m_earlyOutHitFraction;
          }
          v75 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
          if ( v75->m_slabSize < 512 || &(*m_cur)[512] != v75->m_cur || v75->m_firstNonLifoEnd == m_cur )
            hkLifoAllocator::slowBlockFree(v75, (char *)m_cur, 512);
          else
            v75->m_cur = m_cur;
        }
        return;
      case 96:
      case 97:
      case 98:
      case 99:
        PC = v86;
        *(&v85 + (unsigned int)(v11 - 96)) = v13;
        goto $propertyCopy;
      case 100:
      case 101:
      case 102:
      case 103:
        PC += 3;
        v60 = v12 + (v13 << 8);
        v61 = (unsigned int)(v77 - 100);
        goto LABEL_75;
      case 104:
      case 105:
      case 106:
      case 107:
        v60 = (unsigned __int8)PC[4] + (v13 << 24) + (v12 << 16) + (*(unsigned __int8 *)v76 << 8);
        v61 = (unsigned int)(v77 - 104);
        PC += 5;
LABEL_75:
        *(&v85 + v61) = v60;
$propertyCopy:
        if ( v7 == (hkpMoppLongRayVirtualMachine::QueryInt *)&m_quad )
          goto LABEL_5;
        m_quad = v7->m_FtoBoffset.m_quad;
        m_shift = v7->m_shift;
        m_FtoBScale = v7->m_FtoBScale;
        v62 = v7->m_primitiveOffset;
        v7 = (hkpMoppLongRayVirtualMachine::QueryInt *)&m_quad;
        v84 = v62;
        p_m_quad = &m_quad;
        continue;
      case 112:
        chunkOffset = (unsigned __int8)PC[4] + ((*(unsigned __int8 *)v76 + ((v12 + (v13 << 8)) << 8)) << 8);
        PC = &v8->m_code->m_data.m_data[chunkOffset];
        goto LABEL_5;
      default:
        __debugbreak();
        goto LABEL_5;
    }
  }
}

// File Line: 614
// RVA: 0xDB0C70
hkBool *__fastcall hkpMoppLongRayVirtualMachine::queryLongRay(
        hkpMoppLongRayVirtualMachine *this,
        hkBool *result,
        hkpShapeContainer *collection,
        hkpMoppCode *code,
        hkpShapeRayCastInput *input,
        hkpShapeRayCastOutput *rayResult)
{
  char *m_data; // r8
  __m128 m_quad; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm0
  __m128 v12; // xmm3
  unsigned int m_filterInfo; // eax
  hkpMoppLongRayVirtualMachine::QueryInt query; // [rsp+30h] [rbp-48h] BYREF
  hkpMoppLongRayVirtualMachine::QueryFloat fQuery; // [rsp+50h] [rbp-28h] BYREF

  this->m_code = code;
  this->m_rayResultPtr = rayResult;
  this->m_collection = collection;
  this->m_earlyOutHitFraction = 1.0;
  m_data = code->m_data.m_data;
  query.m_FtoBoffset = 0i64;
  this->m_ItoFScale = 1.0 / code->m_info.m_offset.m_quad.m128_f32[3];
  m_quad = input->m_from.m_quad;
  v10 = _mm_sub_ps(input->m_to.m_quad, code->m_info.m_offset.m_quad);
  query.m_FtoBScale = code->m_info.m_offset.m_quad.m128_f32[3] * 0.000015258789;
  v11 = _mm_shuffle_ps((__m128)LODWORD(query.m_FtoBScale), (__m128)LODWORD(query.m_FtoBScale), 0);
  v12 = _mm_sub_ps(m_quad, code->m_info.m_offset.m_quad);
  this->m_ray.m_from.m_quad = m_quad;
  fQuery.m_rayEnds[1].m_quad = _mm_mul_ps(v10, v11);
  this->m_ray.m_to = input->m_to;
  m_filterInfo = input->m_filterInfo;
  fQuery.m_rayEnds[0].m_quad = _mm_mul_ps(v12, v11);
  this->m_ray.m_filterInfo = m_filterInfo;
  this->m_ray.m_rayShapeCollectionFilter = input->m_rayShapeCollectionFilter;
  this->m_ray.m_collidable = input->m_collidable;
  this->m_ray.m_userData = input->m_userData;
  *(_QWORD *)&query.m_primitiveOffset = 0i64;
  query.m_shift = 0;
  this->m_hitFound = 0;
  this->m_reindexingMask = (*m_data != 13) - 1;
  hkpMoppLongRayVirtualMachine::queryRayOnTree(this, &query, m_data, &fQuery, 0);
  result->m_bool = this->m_hitFound;
  return result;
}

// File Line: 637
// RVA: 0xDB0D90
void __fastcall hkpMoppLongRayVirtualMachine::queryLongRay(
        hkpMoppLongRayVirtualMachine *this,
        hkpShapeContainer *collection,
        hkpMoppCode *code,
        hkpShapeRayCastInput *input,
        hkpCdBody *body,
        hkpRayHitCollector *collector)
{
  char *m_data; // rdx
  float v7; // xmm0_4
  hkVector4f v8; // xmm4
  hkVector4f v9; // xmm2
  hkVector4f v10; // xmm3
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm0
  unsigned int m_filterInfo; // eax
  hkpMoppLongRayVirtualMachine::QueryInt query; // [rsp+30h] [rbp-48h] BYREF
  hkpMoppLongRayVirtualMachine::QueryFloat fQuery; // [rsp+50h] [rbp-28h] BYREF

  this->m_collection = collection;
  this->m_body = body;
  this->m_collector = collector;
  this->m_rayResultPtr = 0i64;
  this->m_earlyOutHitFraction = collector->m_earlyOutHitFraction;
  this->m_code = code;
  m_data = code->m_data.m_data;
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
  m_filterInfo = input->m_filterInfo;
  fQuery.m_rayEnds[0].m_quad = _mm_mul_ps(v11, v13);
  fQuery.m_rayEnds[1].m_quad = _mm_mul_ps(v12, v13);
  this->m_ray.m_filterInfo = m_filterInfo;
  this->m_ray.m_rayShapeCollectionFilter = input->m_rayShapeCollectionFilter;
  this->m_ray.m_collidable = input->m_collidable;
  this->m_ray.m_userData = input->m_userData;
  this->m_hitFound = 0;
  this->m_reindexingMask = (*m_data != 13) - 1;
  hkpMoppLongRayVirtualMachine::queryRayOnTree(this, &query, m_data, &fQuery, 0);
}

