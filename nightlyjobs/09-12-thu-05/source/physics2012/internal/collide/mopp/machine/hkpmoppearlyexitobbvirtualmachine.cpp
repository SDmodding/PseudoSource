// File Line: 39
// RVA: 0xDF68C0
void __fastcall hkpMoppEarlyExitObbVirtualMachine::queryOBBOnTree(hkpMoppEarlyExitObbVirtualMachine *this, hkpMoppEarlyExitObbVirtualMachineQuery *query, const char *PC)
{
  int v3; // er11
  bool v4; // zf
  const char *v5; // rdi
  unsigned __int8 v6; // r8
  unsigned __int8 v7; // r9
  hkpMoppEarlyExitObbVirtualMachineQuery *v8; // rbx
  hkpMoppEarlyExitObbVirtualMachine *v9; // rsi
  const char *v10; // r10
  int v11; // eax
  int v12; // er8
  int v13; // edx
  int v14; // edx
  int v15; // er10
  int v16; // er9
  __int64 v17; // rcx
  bool v18; // sf
  unsigned __int8 v19; // of
  int v20; // er10
  unsigned int v21; // ecx
  int v22; // eax
  signed __int64 v23; // rdi
  unsigned int v24; // er10
  int v25; // eax
  unsigned int v26; // eax
  __int64 v27; // xmm0_8
  __int64 v28; // xmm0_8
  int v29; // ecx
  __int64 v30; // xmm0_8
  int v31; // edx
  __int64 v32; // rax
  int v33; // eax
  __int64 v34; // xmm0_8
  __int128 v35; // [rsp+20h] [rbp-50h]
  __int128 v36; // [rsp+30h] [rbp-40h]
  __int128 v37; // [rsp+40h] [rbp-30h]
  __int128 v38; // [rsp+50h] [rbp-20h]
  __int64 v39; // [rsp+60h] [rbp-10h]
  unsigned __int8 v40; // [rsp+90h] [rbp+20h]
  signed __int64 i; // [rsp+A0h] [rbp+30h]

  v3 = *(unsigned __int8 *)PC;
  v4 = this->m_hitFound.m_bool == 0;
  v5 = PC;
  v6 = PC[1];
  v7 = v5[2];
  v8 = query;
  v9 = this;
  for ( i = (signed __int64)(v5 + 2); ; i = (signed __int64)(v5 + 2) )
  {
    v10 = v5 + 3;
    v40 = v5[3];
    if ( !v4 )
      break;
    switch ( v3 )
    {
      case 0:
        return;
      case 1:
      case 2:
      case 3:
      case 4:
        LODWORD(v38) = (v6 + v8->m_offset_x) << v3;
        DWORD1(v38) = (v7 + v8->m_offset_y) << v3;
        v25 = v9->m_xLo;
        DWORD2(v38) = (v40 + v8->m_offset_z) << v3;
        LODWORD(v39) = v3 + v8->m_shift;
        LODWORD(v36) = (v25 >> (16 - v39)) - v38;
        DWORD1(v36) = (v9->m_yLo >> (16 - v39)) - DWORD1(v38);
        DWORD2(v36) = (v9->m_zLo >> (16 - v39)) - DWORD2(v38);
        LODWORD(v35) = (v9->m_xHi >> (16 - v39)) + 1 - v38;
        DWORD1(v35) = (v9->m_yHi >> (16 - v39)) + 1 - DWORD1(v38);
        DWORD2(v35) = (v9->m_zHi >> (16 - v39)) + 1 - DWORD2(v38);
        LODWORD(v37) = (v9->m_cx >> (16 - v39)) - v38;
        DWORD1(v37) = (v9->m_cy >> (16 - v39)) - DWORD1(v38);
        DWORD2(v37) = (v9->m_cz >> (16 - v39)) - DWORD2(v38);
        v5 += 4;
        HIDWORD(v37) = (v9->m_cradius >> (16 - v39)) + 1;
        HIDWORD(v39) = v8->m_properties[0];
        v26 = v8->m_primitiveOffset;
        v8 = (hkpMoppEarlyExitObbVirtualMachineQuery *)&v35;
        HIDWORD(v38) = v26;
        break;
      case 5:
        v5 += v6 + 2;
        break;
      case 6:
        v5 += 256 * v6 + v7 + 3;
        break;
      case 7:
        v5 += 0x10000 * v6 + 256 * v7 + (unsigned int)v40 + 4;
        break;
      case 8:
        v5 += 0x1000000 * v6 + 256 * (v40 + (v7 << 8)) + (unsigned int)*((unsigned __int8 *)v5 + 4) + 5;
        break;
      case 9:
        if ( v8 != (hkpMoppEarlyExitObbVirtualMachineQuery *)&v35 )
        {
          v35 = *(_OWORD *)&v8->m_xHi;
          v36 = *(_OWORD *)&v8->m_xLo;
          v37 = *(_OWORD *)&v8->m_cx;
          v38 = *(_OWORD *)&v8->m_offset_x;
          v27 = *(_QWORD *)&v8->m_shift;
          v8 = (hkpMoppEarlyExitObbVirtualMachineQuery *)&v35;
          v39 = v27;
        }
        HIDWORD(v38) += v6;
        v5 = (const char *)i;
        break;
      case 10:
        if ( v8 != (hkpMoppEarlyExitObbVirtualMachineQuery *)&v35 )
        {
          v35 = *(_OWORD *)&v8->m_xHi;
          v36 = *(_OWORD *)&v8->m_xLo;
          v37 = *(_OWORD *)&v8->m_cx;
          v38 = *(_OWORD *)&v8->m_offset_x;
          v28 = *(_QWORD *)&v8->m_shift;
          v8 = (hkpMoppEarlyExitObbVirtualMachineQuery *)&v35;
          v39 = v28;
        }
        HIDWORD(v38) += v7 + (v6 << 8);
        v5 += 3;
        break;
      case 11:
        v29 = *((unsigned __int8 *)v5 + 4) + (v6 << 24) + (v7 << 16) + (v40 << 8);
        if ( v8 != (hkpMoppEarlyExitObbVirtualMachineQuery *)&v35 )
        {
          v35 = *(_OWORD *)&v8->m_xHi;
          v36 = *(_OWORD *)&v8->m_xLo;
          v37 = *(_OWORD *)&v8->m_cx;
          v38 = *(_OWORD *)&v8->m_offset_x;
          v30 = *(_QWORD *)&v8->m_shift;
          v8 = (hkpMoppEarlyExitObbVirtualMachineQuery *)&v35;
          v39 = v30;
        }
        HIDWORD(v38) = v29;
        v5 += 5;
        break;
      case 16:
      case 17:
      case 18:
        v17 = v40;
        v5 += 4;
        if ( *((_DWORD *)v8 + v3 - 16) <= (signed int)v7 )
          break;
        v5 += v40;
        v19 = __OFSUB__(*((_DWORD *)v8 + v3 - 12), v6);
        v18 = *((_DWORD *)v8 + v3 - 12) - v6 < 0;
        goto LABEL_21;
      case 19:
        v11 = v6;
        v12 = 2 * v7;
        v13 = v8->m_cy + v8->m_cz;
        goto LABEL_10;
      case 20:
        v11 = v6;
        v12 = 2 * v7;
        v13 = v8->m_cy - v8->m_cz + 255;
        goto LABEL_10;
      case 21:
        v14 = v8->m_cz;
        goto LABEL_9;
      case 22:
        v15 = 2 * v6;
        v12 = 2 * v7;
        v13 = v8->m_cx - v8->m_cz + 255;
        v16 = (v8->m_cradius >> 1) + v8->m_cradius + 1;
        goto $do_compare_8;
      case 23:
        v14 = v8->m_cy;
LABEL_9:
        v11 = v6;
        v12 = 2 * v7;
        v13 = v8->m_cx + v14;
LABEL_10:
        v15 = 2 * v11;
        v16 = (v8->m_cradius >> 1) + v8->m_cradius + 1;
        goto $do_compare_8;
      case 24:
        v15 = 2 * v6;
        v12 = 2 * v7;
        v13 = v8->m_cx - v8->m_cy + 255;
        v16 = (v8->m_cradius >> 1) + v8->m_cradius + 1;
        goto $do_compare_8;
      case 25:
        v13 = v8->m_cx + v8->m_cy + v8->m_cz;
        goto LABEL_16;
      case 26:
        v13 = v8->m_cy - v8->m_cz + v8->m_cx + 255;
        goto LABEL_16;
      case 27:
        v13 = v8->m_cz - v8->m_cy + v8->m_cx + 255;
        goto LABEL_16;
      case 28:
        v13 = v8->m_cx - v8->m_cz - v8->m_cy + 510;
LABEL_16:
        v15 = 3 * v6;
        v12 = 3 * v7;
        v16 = 4 * v8->m_cradius;
$do_compare_8:
        v17 = v40;
        v5 += 4;
        if ( v16 + v13 > v12 )
        {
          v5 += v40;
          v19 = __OFSUB__(v13, v16 + v15);
          v18 = v13 - (v16 + v15) < 0;
LABEL_21:
          if ( v18 ^ v19 )
            hkpMoppEarlyExitObbVirtualMachine::queryOBBOnTree(v9, v8, &v5[-v17]);
        }
        break;
      case 32:
      case 33:
      case 34:
        v5 += 3;
        if ( *((_DWORD *)&v8[-1] + v3 - 14) > (signed int)v6 )
        {
          v5 = &v10[v7];
          if ( *((_DWORD *)&v8[-1] + v3 - 10) <= (signed int)v6 )
            hkpMoppEarlyExitObbVirtualMachine::queryOBBOnTree(v9, v8, v10);
        }
        break;
      case 35:
      case 36:
      case 37:
        v20 = *((unsigned __int8 *)v5 + 5) << 8;
        v21 = *((unsigned __int8 *)v5 + 4) + (v40 << 8);
        v22 = *((unsigned __int8 *)v5 + 6);
        v23 = (signed __int64)(v5 + 7);
        v24 = v22 + v20;
        if ( *((_DWORD *)&v8[-1] + v3 - 17) > (signed int)v7 )
        {
          v5 = (const char *)(v24 + v23);
          if ( *((_DWORD *)&v8[-1] + v3 - 13) < (signed int)v6 )
            hkpMoppEarlyExitObbVirtualMachine::queryOBBOnTree(v9, v8, &v5[v21 - (unsigned __int64)v24]);
        }
        else
        {
          v5 = (const char *)(v21 + v23);
        }
        break;
      case 38:
      case 39:
      case 40:
        if ( *((_DWORD *)&v8[-2] + v3 - 2) < (signed int)v6 || *((_DWORD *)&v8[-1] + v3 - 16) >= (signed int)v7 )
          return;
        v5 += 3;
        break;
      case 41:
      case 42:
      case 43:
        if ( *((_DWORD *)&v9[-1] + v3 - 9) < v40 + ((v7 + (v6 << 8)) << 8)
          || *((_DWORD *)&v9[-1] + v3 - 5) > *((unsigned __int8 *)v5 + 6)
                                           + ((*((unsigned __int8 *)v5 + 5) + (*((unsigned __int8 *)v5 + 4) << 8)) << 8) )
        {
          return;
        }
        v5 += 7;
        break;
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
      case 80:
      case 81:
      case 82:
      case 83:
        v9->m_hitFound.m_bool = 1;
        return;
      case 96:
      case 97:
      case 98:
      case 99:
        v5 = (const char *)i;
        *((_DWORD *)&v39 + (unsigned int)(v3 - 96) + 1) = v6;
        goto $propertyCopy_11;
      case 100:
      case 101:
      case 102:
      case 103:
        v5 += 3;
        v31 = v7 + (v6 << 8);
        v32 = (unsigned int)(v3 - 100);
        goto LABEL_53;
      case 104:
      case 105:
      case 106:
      case 107:
        v31 = *((unsigned __int8 *)v5 + 4) + (v6 << 24) + (v7 << 16) + (v40 << 8);
        v32 = (unsigned int)(v3 - 104);
        v5 += 5;
LABEL_53:
        *((_DWORD *)&v39 + v32 + 1) = v31;
$propertyCopy_11:
        v33 = HIDWORD(v39);
        if ( v8 != (hkpMoppEarlyExitObbVirtualMachineQuery *)&v35 )
        {
          v35 = *(_OWORD *)&v8->m_xHi;
          v36 = *(_OWORD *)&v8->m_xLo;
          v37 = *(_OWORD *)&v8->m_cx;
          v38 = *(_OWORD *)&v8->m_offset_x;
          v34 = *(_QWORD *)&v8->m_shift;
          v8 = (hkpMoppEarlyExitObbVirtualMachineQuery *)&v35;
          v39 = v34;
        }
        HIDWORD(v39) = v33;
        break;
      default:
        __debugbreak();
        break;
    }
    v7 = v5[2];
    v3 = *(unsigned __int8 *)v5;
    v6 = v5[1];
    v4 = v9->m_hitFound.m_bool == 0;
  }
}

// File Line: 353
// RVA: 0xDF6FC0
void __fastcall hkpMoppEarlyExitObbVirtualMachine::generateQueryFromNode(hkpMoppEarlyExitObbVirtualMachine *this, hkVector4f *extent, hkTransformf *BvToWorld, const float *radius, hkpMoppEarlyExitObbVirtualMachineQuery *query)
{
  hkpMoppCode *v5; // rax
  hkVector4f *v6; // rbx
  hkpMoppEarlyExitObbVirtualMachine *v7; // rdi
  __m128 v8; // xmm0
  __m128 v9; // xmm8
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 v15; // xmm2
  __m128 v16; // xmm0
  hkVector4f v17; // xmm4
  __m128 v18; // xmm7
  __m128 v19; // xmm6
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128i v22; // xmm3
  __m128i v23; // xmm5
  int v24; // er11
  int v25; // er10
  int v26; // er9
  int v27; // er8
  int v28; // edx
  int v29; // ecx
  __m128 v30; // xmm1
  __m128 v31; // xmm4
  __m128 v32; // xmm1

  v5 = this->m_code;
  v6 = extent;
  v7 = this;
  v8 = _mm_and_ps(extent->m_quad, (__m128)`hkVector4f::getComponent::`2::indexToMask[0]);
  v9 = _mm_shuffle_ps((__m128)*(unsigned int *)radius, (__m128)*(unsigned int *)radius, 0);
  v10 = _mm_or_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  v11 = _mm_and_ps(extent->m_quad, (__m128)xmmword_141687F10);
  v12 = _mm_and_ps(extent->m_quad, (__m128)xmmword_141687F20[0]);
  v13 = _mm_or_ps(_mm_shuffle_ps(v11, v11, 78), v11);
  v14 = _mm_or_ps(_mm_shuffle_ps(v12, v12, 78), v12);
  v15 = v5->m_info.m_offset.m_quad;
  v16 = _mm_or_ps(_mm_shuffle_ps(v10, v10, 177), v10);
  v17.m_quad = (__m128)BvToWorld->m_translation;
  v18 = _mm_shuffle_ps(
          (__m128)v5->m_info.m_offset.m_quad.m128_u32[3],
          (__m128)v5->m_info.m_offset.m_quad.m128_u32[3],
          0);
  v19 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32(
                          (__m128i)_mm_mul_ps(
                                     _mm_or_ps(_mm_shuffle_ps(v13, v13, 177), v13),
                                     BvToWorld->m_rotation.m_col1.m_quad),
                          1u),
                        1u),
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32((__m128i)_mm_mul_ps(v16, BvToWorld->m_rotation.m_col0.m_quad), 1u),
                        1u)),
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_mul_ps(
                                   _mm_or_ps(_mm_shuffle_ps(v14, v14, 177), v14),
                                   BvToWorld->m_rotation.m_col2.m_quad),
                        1u),
                      1u)),
          v9);
  v20 = _mm_mul_ps(
          _mm_sub_ps(
            _mm_add_ps(
              _mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v19),
              v17.m_quad),
            v15),
          v18);
  v21 = _mm_mul_ps(_mm_sub_ps(_mm_add_ps(v17.m_quad, v19), v15), v18);
  v22 = _mm_xor_si128(
          (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v20),
          _mm_cvttps_epi32(v20));
  v23 = _mm_xor_si128(
          (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v21),
          _mm_cvttps_epi32(v21));
  v24 = _mm_cvtsi128_si32(v22) - 1;
  this->m_xLo = v24;
  v25 = _mm_cvtsi128_si32(v23) + 1;
  this->m_xHi = v25;
  v26 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v22, 85)) - 1;
  this->m_yLo = v26;
  v27 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v23, 85)) + 1;
  this->m_yHi = v27;
  this->m_cx = (v25 + v24) >> 1;
  v28 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v22, 170)) - 1;
  this->m_cy = (v27 + v26) >> 1;
  this->m_zLo = v28;
  v29 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v23, 170)) + 1;
  v7->m_zHi = v29;
  v7->m_cz = (v29 + v28) >> 1;
  v30 = _mm_mul_ps(v6->m_quad, v6->m_quad);
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)), _mm_shuffle_ps(v30, v30, 170));
  v32 = _mm_rsqrt_ps(v31);
  v7->m_cradius = (signed int)(float)((float)(COERCE_FLOAT(
                                                _mm_andnot_ps(
                                                  _mm_cmpleps(v31, (__m128)0i64),
                                                  _mm_mul_ps(
                                                    _mm_mul_ps(
                                                      _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
                                                      _mm_mul_ps(*(__m128 *)_xmm, v32)),
                                                    v31)))
                                            + v9.m128_f32[0])
                                    * v18.m128_f32[0])
                + 1;
  query->m_xLo = v24 >> 16;
  query->m_xHi = SHIWORD(v7->m_xHi) + 1;
  query->m_yLo = SHIWORD(v7->m_yLo);
  query->m_yHi = SHIWORD(v7->m_yHi) + 1;
  query->m_zLo = SHIWORD(v7->m_zLo);
  query->m_zHi = SHIWORD(v7->m_zHi) + 1;
  query->m_cx = SHIWORD(v7->m_cx);
  query->m_cy = SHIWORD(v7->m_cy);
  query->m_cz = SHIWORD(v7->m_cz);
  query->m_cradius = SHIWORD(v7->m_cradius) + 1;
  *(_QWORD *)&query->m_offset_x = 0i64;
  *(_QWORD *)&query->m_offset_z = 0i64;
  *(_QWORD *)&query->m_shift = 0i64;
}

// File Line: 458
// RVA: 0xDF6800
hkBool *__fastcall hkpMoppEarlyExitObbVirtualMachine::queryObb(hkpMoppEarlyExitObbVirtualMachine *this, hkBool *result, hkpMoppCode *code, hkTransformf *BvToWorld, hkVector4f *extent, const float *radius)
{
  hkTransformf *v6; // rbp
  hkpMoppCode *v7; // rbx
  hkBool *v8; // rdi
  hkpMoppEarlyExitObbVirtualMachine *v9; // rsi
  const char *v10; // rbx
  hkpMoppEarlyExitObbVirtualMachineQuery query; // [rsp+30h] [rbp-58h]

  v6 = BvToWorld;
  v7 = code;
  v8 = result;
  v9 = this;
  if ( HK_flyingcolors_mopp_4.m_bool
    || (hkpCheckKeycode(), hkpProcessFlyingColors(&HK_flyingcolors_mopp_4), HK_flyingcolors_mopp_4.m_bool) )
  {
    v9->m_code = v7;
    v10 = v7->m_data.m_data;
    hkpMoppEarlyExitObbVirtualMachine::generateQueryFromNode(v9, extent, v6, radius, &query);
    query.m_properties[0] = 0;
    v9->m_hitFound.m_bool = 0;
    hkpMoppEarlyExitObbVirtualMachine::queryOBBOnTree(v9, &query, v10);
    v8->m_bool = (char)v9->m_hitFound;
  }
  else
  {
    v8->m_bool = 0;
  }
  return v8;
}

