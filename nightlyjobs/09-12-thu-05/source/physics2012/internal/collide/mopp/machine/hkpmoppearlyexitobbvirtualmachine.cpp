// File Line: 39
// RVA: 0xDF68C0
void __fastcall hkpMoppEarlyExitObbVirtualMachine::queryOBBOnTree(
        hkpMoppEarlyExitObbVirtualMachine *this,
        hkpMoppEarlyExitObbVirtualMachineQuery *query,
        const char *PC)
{
  int v3; // r11d
  bool v4; // zf
  const char *v5; // rdi
  unsigned __int8 v6; // r8
  unsigned __int8 v7; // r9
  const char *v10; // r10
  int v11; // eax
  int v12; // r8d
  int v13; // edx
  int m_cz; // edx
  int v15; // r10d
  int v16; // r9d
  __int64 v17; // rcx
  bool v18; // cc
  int v19; // r10d
  unsigned int v20; // ecx
  int v21; // eax
  const char *v22; // rdi
  unsigned int v23; // r10d
  int m_xLo; // eax
  unsigned int m_primitiveOffset; // eax
  __int64 v26; // xmm0_8
  __int64 v27; // xmm0_8
  int v28; // ecx
  __int64 v29; // xmm0_8
  int v30; // edx
  __int64 v31; // rax
  int v32; // eax
  __int64 v33; // xmm0_8
  __int128 v34; // [rsp+20h] [rbp-50h] BYREF
  __int128 v35; // [rsp+30h] [rbp-40h]
  __int128 v36; // [rsp+40h] [rbp-30h]
  __int128 v37; // [rsp+50h] [rbp-20h]
  __int64 v38[2]; // [rsp+60h] [rbp-10h]
  unsigned __int8 v39; // [rsp+90h] [rbp+20h]
  const char *i; // [rsp+A0h] [rbp+30h]

  v3 = *(unsigned __int8 *)PC;
  v4 = this->m_hitFound.m_bool == 0;
  v5 = PC;
  v6 = PC[1];
  v7 = v5[2];
  for ( i = v5 + 2; ; i = v5 + 2 )
  {
    v10 = v5 + 3;
    v39 = v5[3];
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
        LODWORD(v37) = (v6 + query->m_offset_x) << v3;
        DWORD1(v37) = (v7 + query->m_offset_y) << v3;
        m_xLo = this->m_xLo;
        DWORD2(v37) = (v39 + query->m_offset_z) << v3;
        LODWORD(v38[0]) = v3 + query->m_shift;
        LODWORD(v35) = (m_xLo >> (16 - LOBYTE(v38[0]))) - v37;
        DWORD1(v35) = (this->m_yLo >> (16 - LOBYTE(v38[0]))) - DWORD1(v37);
        DWORD2(v35) = (this->m_zLo >> (16 - LOBYTE(v38[0]))) - DWORD2(v37);
        LODWORD(v34) = (this->m_xHi >> (16 - LOBYTE(v38[0]))) + 1 - v37;
        DWORD1(v34) = (this->m_yHi >> (16 - LOBYTE(v38[0]))) + 1 - DWORD1(v37);
        DWORD2(v34) = (this->m_zHi >> (16 - LOBYTE(v38[0]))) + 1 - DWORD2(v37);
        LODWORD(v36) = (this->m_cx >> (16 - LOBYTE(v38[0]))) - v37;
        DWORD1(v36) = (this->m_cy >> (16 - LOBYTE(v38[0]))) - DWORD1(v37);
        DWORD2(v36) = (this->m_cz >> (16 - LOBYTE(v38[0]))) - DWORD2(v37);
        v5 += 4;
        HIDWORD(v36) = (this->m_cradius >> (16 - LOBYTE(v38[0]))) + 1;
        HIDWORD(v38[0]) = query->m_properties[0];
        m_primitiveOffset = query->m_primitiveOffset;
        query = (hkpMoppEarlyExitObbVirtualMachineQuery *)&v34;
        HIDWORD(v37) = m_primitiveOffset;
        break;
      case 5:
        v5 += v6 + 2;
        break;
      case 6:
        v5 += 256 * v6 + v7 + 3;
        break;
      case 7:
        v5 += 0x10000 * v6 + 256 * v7 + (unsigned int)v39 + 4;
        break;
      case 8:
        v5 += 0x1000000 * v6 + 256 * (v39 + (v7 << 8)) + (unsigned int)*((unsigned __int8 *)v5 + 4) + 5;
        break;
      case 9:
        if ( query != (hkpMoppEarlyExitObbVirtualMachineQuery *)&v34 )
        {
          v34 = *(_OWORD *)&query->m_xHi;
          v35 = *(_OWORD *)&query->m_xLo;
          v36 = *(_OWORD *)&query->m_cx;
          v37 = *(_OWORD *)&query->m_offset_x;
          v26 = *(_QWORD *)&query->m_shift;
          query = (hkpMoppEarlyExitObbVirtualMachineQuery *)&v34;
          v38[0] = v26;
        }
        HIDWORD(v37) += v6;
        v5 = i;
        break;
      case 10:
        if ( query != (hkpMoppEarlyExitObbVirtualMachineQuery *)&v34 )
        {
          v34 = *(_OWORD *)&query->m_xHi;
          v35 = *(_OWORD *)&query->m_xLo;
          v36 = *(_OWORD *)&query->m_cx;
          v37 = *(_OWORD *)&query->m_offset_x;
          v27 = *(_QWORD *)&query->m_shift;
          query = (hkpMoppEarlyExitObbVirtualMachineQuery *)&v34;
          v38[0] = v27;
        }
        HIDWORD(v37) += v7 + (v6 << 8);
        v5 += 3;
        break;
      case 11:
        v28 = *((unsigned __int8 *)v5 + 4) + (v6 << 24) + (v7 << 16) + (v39 << 8);
        if ( query != (hkpMoppEarlyExitObbVirtualMachineQuery *)&v34 )
        {
          v34 = *(_OWORD *)&query->m_xHi;
          v35 = *(_OWORD *)&query->m_xLo;
          v36 = *(_OWORD *)&query->m_cx;
          v37 = *(_OWORD *)&query->m_offset_x;
          v29 = *(_QWORD *)&query->m_shift;
          query = (hkpMoppEarlyExitObbVirtualMachineQuery *)&v34;
          v38[0] = v29;
        }
        HIDWORD(v37) = v28;
        v5 += 5;
        break;
      case 16:
      case 17:
      case 18:
        v17 = v39;
        v5 += 4;
        if ( *((_DWORD *)query + v3 - 16) <= (int)v7 )
          break;
        v5 += v39;
        v18 = *((_DWORD *)query + v3 - 12) < (int)v6;
        goto LABEL_21;
      case 19:
        v11 = v6;
        v12 = 2 * v7;
        v13 = query->m_cy + query->m_cz;
        goto LABEL_10;
      case 20:
        v11 = v6;
        v12 = 2 * v7;
        v13 = query->m_cy - query->m_cz + 255;
        goto LABEL_10;
      case 21:
        m_cz = query->m_cz;
        goto LABEL_9;
      case 22:
        v15 = 2 * v6;
        v12 = 2 * v7;
        v13 = query->m_cx - query->m_cz + 255;
        v16 = (query->m_cradius >> 1) + query->m_cradius + 1;
        goto $do_compare_8;
      case 23:
        m_cz = query->m_cy;
LABEL_9:
        v11 = v6;
        v12 = 2 * v7;
        v13 = query->m_cx + m_cz;
LABEL_10:
        v15 = 2 * v11;
        v16 = (query->m_cradius >> 1) + query->m_cradius + 1;
        goto $do_compare_8;
      case 24:
        v15 = 2 * v6;
        v12 = 2 * v7;
        v13 = query->m_cx - query->m_cy + 255;
        v16 = (query->m_cradius >> 1) + query->m_cradius + 1;
        goto $do_compare_8;
      case 25:
        v13 = query->m_cx + query->m_cy + query->m_cz;
        goto LABEL_16;
      case 26:
        v13 = query->m_cy - query->m_cz + query->m_cx + 255;
        goto LABEL_16;
      case 27:
        v13 = query->m_cz - query->m_cy + query->m_cx + 255;
        goto LABEL_16;
      case 28:
        v13 = query->m_cx - query->m_cz - query->m_cy + 510;
LABEL_16:
        v15 = 3 * v6;
        v12 = 3 * v7;
        v16 = 4 * query->m_cradius;
$do_compare_8:
        v17 = v39;
        v5 += 4;
        if ( v16 + v13 > v12 )
        {
          v5 += v39;
          v18 = v13 < v16 + v15;
LABEL_21:
          if ( v18 )
            hkpMoppEarlyExitObbVirtualMachine::queryOBBOnTree(this, query, &v5[-v17]);
        }
        break;
      case 32:
      case 33:
      case 34:
        v5 += 3;
        if ( *((_DWORD *)&query[-1] + v3 - 14) > (int)v6 )
        {
          v5 = &v10[v7];
          if ( *((_DWORD *)&query[-1] + v3 - 10) <= (int)v6 )
            hkpMoppEarlyExitObbVirtualMachine::queryOBBOnTree(this, query, v10);
        }
        break;
      case 35:
      case 36:
      case 37:
        v19 = *((unsigned __int8 *)v5 + 5) << 8;
        v20 = *((unsigned __int8 *)v5 + 4) + (v39 << 8);
        v21 = *((unsigned __int8 *)v5 + 6);
        v22 = v5 + 7;
        v23 = v21 + v19;
        if ( *((_DWORD *)&query[-1] + v3 - 17) > (int)v7 )
        {
          v5 = &v22[v23];
          if ( *((_DWORD *)&query[-1] + v3 - 13) < (int)v6 )
            hkpMoppEarlyExitObbVirtualMachine::queryOBBOnTree(this, query, &v5[v20 - (unsigned __int64)v23]);
        }
        else
        {
          v5 = &v22[v20];
        }
        break;
      case 38:
      case 39:
      case 40:
        if ( *((_DWORD *)&query[-2] + v3 - 2) < (int)v6 || *((_DWORD *)&query[-1] + v3 - 16) >= (int)v7 )
          return;
        v5 += 3;
        break;
      case 41:
      case 42:
      case 43:
        if ( *((_DWORD *)&this[-1] + v3 - 9) < v39 + ((v7 + (v6 << 8)) << 8)
          || *((_DWORD *)&this[-1] + v3 - 5) > *((unsigned __int8 *)v5 + 6)
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
        this->m_hitFound.m_bool = 1;
        return;
      case 96:
      case 97:
      case 98:
      case 99:
        v5 = i;
        *((_DWORD *)v38 + (unsigned int)(v3 - 96) + 1) = v6;
        goto $propertyCopy_11;
      case 100:
      case 101:
      case 102:
      case 103:
        v5 += 3;
        v30 = v7 + (v6 << 8);
        v31 = (unsigned int)(v3 - 100);
        goto LABEL_53;
      case 104:
      case 105:
      case 106:
      case 107:
        v30 = *((unsigned __int8 *)v5 + 4) + (v6 << 24) + (v7 << 16) + (v39 << 8);
        v31 = (unsigned int)(v3 - 104);
        v5 += 5;
LABEL_53:
        *((_DWORD *)v38 + v31 + 1) = v30;
$propertyCopy_11:
        v32 = HIDWORD(v38[0]);
        if ( query != (hkpMoppEarlyExitObbVirtualMachineQuery *)&v34 )
        {
          v34 = *(_OWORD *)&query->m_xHi;
          v35 = *(_OWORD *)&query->m_xLo;
          v36 = *(_OWORD *)&query->m_cx;
          v37 = *(_OWORD *)&query->m_offset_x;
          v33 = *(_QWORD *)&query->m_shift;
          query = (hkpMoppEarlyExitObbVirtualMachineQuery *)&v34;
          v38[0] = v33;
        }
        HIDWORD(v38[0]) = v32;
        break;
      default:
        __debugbreak();
        break;
    }
    v7 = v5[2];
    v3 = *(unsigned __int8 *)v5;
    v6 = v5[1];
    v4 = this->m_hitFound.m_bool == 0;
  }
}

// File Line: 353
// RVA: 0xDF6FC0
void __fastcall hkpMoppEarlyExitObbVirtualMachine::generateQueryFromNode(
        hkpMoppEarlyExitObbVirtualMachine *this,
        hkVector4f *extent,
        hkTransformf *BvToWorld,
        const float *radius,
        hkpMoppEarlyExitObbVirtualMachineQuery *query)
{
  hkpMoppCode *m_code; // rax
  __m128 v8; // xmm0
  __m128 v9; // xmm8
  __m128 v10; // xmm4
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  __m128 v14; // xmm3
  __m128 m_quad; // xmm2
  __m128 v16; // xmm0
  hkVector4f v17; // xmm4
  __m128 v18; // xmm7
  __m128 v19; // xmm6
  __m128 v20; // xmm1
  __m128 v21; // xmm4
  __m128i v22; // xmm3
  __m128i v23; // xmm5
  int v24; // r11d
  int v25; // r10d
  int v26; // r9d
  int v27; // r8d
  int v28; // edx
  int v29; // ecx
  __m128 v30; // xmm1
  __m128 v31; // xmm4
  __m128 v32; // xmm1

  m_code = this->m_code;
  v8 = _mm_and_ps(extent->m_quad, (__m128)`hkVector4f::getComponent::`2::indexToMask[0]);
  v9 = _mm_shuffle_ps((__m128)*(unsigned int *)radius, (__m128)*(unsigned int *)radius, 0);
  v10 = _mm_or_ps(_mm_shuffle_ps(v8, v8, 78), v8);
  v11 = _mm_and_ps(extent->m_quad, (__m128)xmmword_141687F10);
  v12 = _mm_and_ps(extent->m_quad, (__m128)xmmword_141687F20[0]);
  v13 = _mm_or_ps(_mm_shuffle_ps(v11, v11, 78), v11);
  v14 = _mm_or_ps(_mm_shuffle_ps(v12, v12, 78), v12);
  m_quad = m_code->m_info.m_offset.m_quad;
  v16 = _mm_or_ps(_mm_shuffle_ps(v10, v10, 177), v10);
  v17.m_quad = (__m128)BvToWorld->m_translation;
  v18 = _mm_shuffle_ps(
          (__m128)m_code->m_info.m_offset.m_quad.m128_u32[3],
          (__m128)m_code->m_info.m_offset.m_quad.m128_u32[3],
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
            m_quad),
          v18);
  v21 = _mm_mul_ps(_mm_sub_ps(_mm_add_ps(v17.m_quad, v19), m_quad), v18);
  v22 = _mm_xor_si128(
          (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v20),
          _mm_cvttps_epi32(v20));
  v23 = _mm_xor_si128(
          (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v21),
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
  this->m_zHi = v29;
  this->m_cz = (v29 + v28) >> 1;
  v30 = _mm_mul_ps(extent->m_quad, extent->m_quad);
  v31 = _mm_add_ps(_mm_add_ps(_mm_shuffle_ps(v30, v30, 85), _mm_shuffle_ps(v30, v30, 0)), _mm_shuffle_ps(v30, v30, 170));
  v32 = _mm_rsqrt_ps(v31);
  this->m_cradius = (int)(float)((float)(_mm_andnot_ps(
                                           _mm_cmple_ps(v31, (__m128)0i64),
                                           _mm_mul_ps(
                                             _mm_mul_ps(
                                               _mm_sub_ps((__m128)_xmm, _mm_mul_ps(_mm_mul_ps(v32, v31), v32)),
                                               _mm_mul_ps(*(__m128 *)_xmm, v32)),
                                             v31)).m128_f32[0]
                                       + v9.m128_f32[0])
                               * v18.m128_f32[0])
                  + 1;
  query->m_xLo = v24 >> 16;
  query->m_xHi = SHIWORD(this->m_xHi) + 1;
  query->m_yLo = SHIWORD(this->m_yLo);
  query->m_yHi = SHIWORD(this->m_yHi) + 1;
  query->m_zLo = SHIWORD(this->m_zLo);
  query->m_zHi = SHIWORD(this->m_zHi) + 1;
  query->m_cx = SHIWORD(this->m_cx);
  query->m_cy = SHIWORD(this->m_cy);
  query->m_cz = SHIWORD(this->m_cz);
  query->m_cradius = SHIWORD(this->m_cradius) + 1;
  *(_QWORD *)&query->m_offset_x = 0i64;
  *(_QWORD *)&query->m_offset_z = 0i64;
  *(_QWORD *)&query->m_shift = 0i64;
}

// File Line: 458
// RVA: 0xDF6800
hkBool *__fastcall hkpMoppEarlyExitObbVirtualMachine::queryObb(
        hkpMoppEarlyExitObbVirtualMachine *this,
        hkBool *result,
        hkpMoppCode *code,
        hkTransformf *BvToWorld,
        hkVector4f *extent,
        const float *radius)
{
  char *m_data; // rbx
  hkpMoppEarlyExitObbVirtualMachineQuery query; // [rsp+30h] [rbp-58h] BYREF

  if ( HK_flyingcolors_mopp_4.m_bool
    || (hkpCheckKeycode(), hkpProcessFlyingColors(&HK_flyingcolors_mopp_4), HK_flyingcolors_mopp_4.m_bool) )
  {
    this->m_code = code;
    m_data = code->m_data.m_data;
    hkpMoppEarlyExitObbVirtualMachine::generateQueryFromNode(this, extent, BvToWorld, radius, &query);
    query.m_properties[0] = 0;
    this->m_hitFound.m_bool = 0;
    hkpMoppEarlyExitObbVirtualMachine::queryOBBOnTree(this, &query, m_data);
    result->m_bool = (char)this->m_hitFound;
  }
  else
  {
    result->m_bool = 0;
  }
  return result;
}

