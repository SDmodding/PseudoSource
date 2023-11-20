// File Line: 69
// RVA: 0xDB21E0
void __usercall hkpMoppObbVirtualMachine::queryAabbOnTree(hkpMoppObbVirtualMachine *this@<rcx>, hkpMoppObbVirtualMachineQuery *query@<rdx>, const char *PC@<r8>, int chunkOffset@<r9d>, unsigned __int64 a5@<rax>)
{
  int v5; // esi
  const char *v6; // rbx
  hkpMoppObbVirtualMachineQuery *v7; // rdi
  __int64 v8; // r8
  int v9; // er9
  unsigned __int8 v10; // r10
  unsigned __int8 v11; // r11
  int v12; // er8
  int v13; // edx
  int v14; // ecx
  int v15; // ecx
  int v16; // eax
  __int64 v17; // rcx
  signed int v18; // er8
  __int64 v19; // rcx
  int v20; // er8
  int v21; // eax
  signed __int64 v22; // rbx
  unsigned int v23; // edx
  unsigned int v24; // er8
  int v25; // ecx
  int v26; // edx
  __int128 v27; // xmm1
  __int128 v28; // xmm1
  int v29; // ecx
  __int128 v30; // xmm1
  int v31; // edx
  __int64 v32; // rax
  __int128 v33; // xmm1
  int v34; // ecx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *v35; // rbx
  int v36; // esi
  __int64 v37; // r8
  int *v38; // rdx
  const char *v39; // [rsp+20h] [rbp-50h]
  unsigned int v40; // [rsp+20h] [rbp-50h]
  int v41; // [rsp+20h] [rbp-50h]
  __int128 v42; // [rsp+30h] [rbp-40h]
  __int128 v43; // [rsp+40h] [rbp-30h]
  __int128 v44; // [rsp+50h] [rbp-20h]
  __int128 v45; // [rsp+60h] [rbp-10h]
  hkpMoppObbVirtualMachine *v46; // [rsp+80h] [rbp+10h]

  v46 = this;
  v5 = chunkOffset;
  v6 = PC;
  v7 = query;
  if ( HK_flyingcolors_mopp_0.m_bool
    || (hkpCheckKeycode(), LODWORD(a5) = hkpProcessFlyingColors(&HK_flyingcolors_mopp_0), HK_flyingcolors_mopp_0.m_bool) )
  {
    while ( 1 )
    {
      v8 = *(unsigned __int8 *)v6;
      LOBYTE(v9) = v6[1];
      v10 = v6[2];
      v11 = v6[3];
      v39 = (const char *)a5;
      a5 = 5368709120i64;
      switch ( (unsigned __int64)v6 )
      {
        case 0xFFFFFFFFFFFFFFFEui64:
          return;
        case 0xFFFFFFFFFFFFFFFFui64:
        case 0ui64:
        case 1ui64:
        case 2ui64:
          LODWORD(v44) = ((unsigned __int8)v9 + v7->m_offset_x) << v8;
          DWORD1(v44) = (v10 + v7->m_offset_y) << v8;
          DWORD2(v44) = (v11 + v7->m_offset_z) << v8;
          v25 = v8 + v7->m_shift;
          v26 = v46->m_xLo;
          LODWORD(v45) = v25;
          LOBYTE(v25) = 16 - v25;
          LODWORD(v43) = (v26 >> v25) - v44;
          DWORD1(v43) = (v46->m_yLo >> v25) - DWORD1(v44);
          DWORD2(v43) = (v46->m_zLo >> v25) - DWORD2(v44);
          LODWORD(v42) = (v46->m_xHi >> v25) - v44 + 1;
          DWORD1(v42) = (v46->m_yHi >> v25) - DWORD1(v44) + 1;
          v6 += 4;
          DWORD2(v42) = (v46->m_zHi >> v25) - DWORD2(v44) + 1;
          DWORD1(v45) = v7->m_properties[0];
          a5 = v7->m_primitiveOffset;
          v7 = (hkpMoppObbVirtualMachineQuery *)&v42;
          HIDWORD(v44) = a5;
          continue;
        case 3ui64:
          a5 = (unsigned __int8)v9;
          v6 = &v39[(unsigned __int8)v9];
          continue;
        case 4ui64:
          a5 = v10;
          v6 += 256 * (unsigned __int8)v9 + v10 + 3;
          continue;
        case 5ui64:
          a5 = (v10 << 8) + ((unsigned __int8)v9 << 16) + (unsigned int)v11;
          v6 += a5 + 4;
          continue;
        case 6ui64:
          a5 = ((unsigned __int8)v9 << 24) + *((unsigned __int8 *)v6 + 4) + (((v10 << 8) + (unsigned int)v11) << 8);
          v6 += a5 + 5;
          continue;
        case 7ui64:
          a5 = (unsigned __int8)v9;
          if ( v7 != (hkpMoppObbVirtualMachineQuery *)&v42 )
          {
            v42 = *(_OWORD *)&v7->m_xHi;
            v43 = *(_OWORD *)&v7->m_xLo;
            v44 = *(_OWORD *)&v7->m_offset_x;
            v27 = *(_OWORD *)&v7->m_shift;
            v7 = (hkpMoppObbVirtualMachineQuery *)&v42;
            v45 = v27;
          }
          HIDWORD(v44) += a5;
          v6 = v39;
          continue;
        case 8ui64:
          a5 = (unsigned __int64)&v42;
          if ( v7 != (hkpMoppObbVirtualMachineQuery *)&v42 )
          {
            v42 = *(_OWORD *)&v7->m_xHi;
            v43 = *(_OWORD *)&v7->m_xLo;
            v44 = *(_OWORD *)&v7->m_offset_x;
            v28 = *(_OWORD *)&v7->m_shift;
            v7 = (hkpMoppObbVirtualMachineQuery *)&v42;
            v45 = v28;
          }
          HIDWORD(v44) += v10 + ((unsigned __int8)v9 << 8);
          v6 += 3;
          continue;
        case 9ui64:
          v29 = *((unsigned __int8 *)v6 + 4) + ((unsigned __int8)v9 << 24) + (v10 << 16) + (v11 << 8);
          a5 = (unsigned __int64)&v42;
          if ( v7 != (hkpMoppObbVirtualMachineQuery *)&v42 )
          {
            v42 = *(_OWORD *)&v7->m_xHi;
            v43 = *(_OWORD *)&v7->m_xLo;
            v44 = *(_OWORD *)&v7->m_offset_x;
            v30 = *(_OWORD *)&v7->m_shift;
            v7 = (hkpMoppObbVirtualMachineQuery *)&v42;
            v45 = v30;
          }
          HIDWORD(v44) = v29;
          goto $LN28_55;
        case 0xAui64:
          a5 = (unsigned __int64)v46->m_code.m_storage;
          v5 = (v10 | ((unsigned __int8)v9 << 8)) << 9;
          v6 = (const char *)(*(_QWORD *)(a5 + 32) + v5);
          continue;
        case 0xBui64:
$LN28_55:
          v6 += 5;
          continue;
        case 0xEui64:
        case 0xFui64:
        case 0x10ui64:
          v17 = (signed int)v8;
          a5 = v10;
          v6 += 4;
          v18 = *((_DWORD *)v7 + (signed int)v8 - 12);
          if ( *(&v7[-1].m_xHi + v17) > v10 )
          {
            v6 += v11;
            if ( v18 < (unsigned __int8)v9 )
              hkpMoppObbVirtualMachine::queryAabbOnTree(v46, v7, &v6[-v11], v5);
          }
          else if ( v18 >= (unsigned __int8)v9 )
          {
            return;
          }
          continue;
        case 0x11ui64:
          v12 = 2 * v10;
          v13 = 2 * (unsigned __int8)v9;
          a5 = (unsigned int)(v7->m_yLo + v7->m_zLo);
          v14 = v7->m_yHi + v7->m_zHi;
          goto $do_compare_0;
        case 0x12ui64:
          v13 = 2 * (unsigned __int8)v9 - 255;
          v12 = 2 * v10 - 255;
          a5 = (unsigned int)(v7->m_yLo - v7->m_zHi);
          v14 = v7->m_yHi - v7->m_zLo;
          goto $do_compare_0;
        case 0x13ui64:
          v12 = 2 * v10;
          v13 = 2 * (unsigned __int8)v9;
          a5 = (unsigned int)(v7->m_xLo + v7->m_zLo);
          v14 = v7->m_xHi + v7->m_zHi;
          goto $do_compare_0;
        case 0x14ui64:
          v13 = 2 * (unsigned __int8)v9 - 255;
          v12 = 2 * v10 - 255;
          a5 = (unsigned int)(v7->m_xLo - v7->m_zHi);
          v14 = v7->m_xHi - v7->m_zLo;
          goto $do_compare_0;
        case 0x15ui64:
          v12 = 2 * v10;
          v13 = 2 * (unsigned __int8)v9;
          a5 = (unsigned int)(v7->m_xLo + v7->m_yLo);
          v14 = v7->m_xHi + v7->m_yHi;
          goto $do_compare_0;
        case 0x16ui64:
          v15 = v7->m_xHi;
          v13 = 2 * (unsigned __int8)v9 - 255;
          v12 = 2 * v10 - 255;
          v16 = v7->m_xLo;
          goto LABEL_14;
        case 0x17ui64:
          v13 = 3 * (unsigned __int8)v9;
          v12 = 3 * v10;
          a5 = (unsigned int)(v7->m_xLo + v7->m_yLo + v7->m_zLo);
          v14 = v7->m_xHi + v7->m_yHi + v7->m_zHi;
          goto $do_compare_0;
        case 0x18ui64:
          v13 = 3 * ((unsigned __int8)v9 - 85);
          v12 = 3 * (v10 - 85);
          a5 = (unsigned int)(v7->m_xLo + v7->m_yLo - v7->m_zHi);
          v14 = v7->m_xHi + v7->m_yHi - v7->m_zLo;
          goto $do_compare_0;
        case 0x19ui64:
          v13 = 3 * ((unsigned __int8)v9 - 85);
          v12 = 3 * (v10 - 85);
          a5 = (unsigned int)(v7->m_xLo + v7->m_zLo - v7->m_yHi);
          v14 = v7->m_xHi + v7->m_zHi - v7->m_yLo;
          goto $do_compare_0;
        case 0x1Aui64:
          v13 = 3 * ((unsigned __int8)v9 - 170);
          v12 = 3 * (v10 - 170);
          v16 = v7->m_xLo - v7->m_zHi;
          v15 = v7->m_xHi - v7->m_zLo;
LABEL_14:
          a5 = (unsigned int)(v16 - v7->m_yHi);
          v14 = v15 - v7->m_yLo;
$do_compare_0:
          v6 += 4;
          v40 = v11;
          if ( v14 > v12 )
          {
            if ( (signed int)a5 < v13 )
            {
              hkpMoppObbVirtualMachine::queryAabbOnTree(v46, v7, v6, v5);
              a5 = v40;
              v6 += v40;
            }
            else
            {
              v6 += v11;
            }
          }
          else if ( (signed int)a5 >= v13 )
          {
            return;
          }
          continue;
        case 0x1Eui64:
        case 0x1Fui64:
        case 0x20ui64:
          v6 += 3;
          a5 = v10;
          if ( *(&v7[-2].m_xHi + (signed int)v8) > (unsigned __int8)v9 )
          {
            v6 += v10;
            if ( *((_DWORD *)&v7[-1] + (signed int)v8 - 12) <= (signed int)(unsigned __int8)v9 )
              hkpMoppObbVirtualMachine::queryAabbOnTree(v46, v7, &v6[-v10], v5);
          }
          continue;
        case 0x21ui64:
        case 0x22ui64:
        case 0x23ui64:
          v19 = (signed int)v8;
          v20 = *((unsigned __int8 *)v6 + 5) << 8;
          v41 = *((_DWORD *)&v7[-1] + v19 - 15);
          v21 = *((unsigned __int8 *)v6 + 4);
          v22 = (signed __int64)(v6 + 7);
          v23 = v21 + (v11 << 8);
          v9 = (unsigned __int8)v9;
          v24 = *(unsigned __int8 *)(v22 - 1) + v20;
          if ( *((_DWORD *)&v7[-2] + v19 - 3) > (signed int)v10 )
          {
            a5 = v24;
            v6 = (const char *)(v24 + v22);
            if ( v41 < v9 )
              hkpMoppObbVirtualMachine::queryAabbOnTree(v46, v7, &v6[v23 - (unsigned __int64)v24], v5);
          }
          else
          {
            if ( v41 >= v9 )
              return;
            a5 = v23;
            v6 = (const char *)(v23 + v22);
          }
          break;
        case 0x24ui64:
        case 0x25ui64:
        case 0x26ui64:
          if ( *((_DWORD *)&v7[-2] + (signed int)v8 - 6) < (signed int)(unsigned __int8)v9 )
            return;
          a5 = v10;
          if ( *((_DWORD *)&v7[-2] + (signed int)v8 - 2) >= (signed int)v10 )
            return;
          v6 += 3;
          continue;
        case 0x27ui64:
        case 0x28ui64:
        case 0x29ui64:
          if ( *((_DWORD *)&v46[-1] + v8 - 13) < v11 + ((v10 + ((unsigned __int8)v9 << 8)) << 8) )
            return;
          a5 = *((unsigned __int8 *)v6 + 6);
          if ( *((_DWORD *)&v46[-1] + v8 - 9) > (signed int)(a5
                                                           + ((*((unsigned __int8 *)v6 + 5)
                                                             + (*((unsigned __int8 *)v6 + 4) << 8)) << 8)) )
            return;
          v6 += 7;
          continue;
        case 0x2Eui64:
        case 0x2Fui64:
        case 0x30ui64:
        case 0x31ui64:
        case 0x32ui64:
        case 0x33ui64:
        case 0x34ui64:
        case 0x35ui64:
        case 0x36ui64:
        case 0x37ui64:
        case 0x38ui64:
        case 0x39ui64:
        case 0x3Aui64:
        case 0x3Bui64:
        case 0x3Cui64:
        case 0x3Dui64:
        case 0x3Eui64:
        case 0x3Fui64:
        case 0x40ui64:
        case 0x41ui64:
        case 0x42ui64:
        case 0x43ui64:
        case 0x44ui64:
        case 0x45ui64:
        case 0x46ui64:
        case 0x47ui64:
        case 0x48ui64:
        case 0x49ui64:
        case 0x4Aui64:
        case 0x4Bui64:
        case 0x4Cui64:
        case 0x4Dui64:
          v34 = v8 - 48;
          goto $add_Terminal_0;
        case 0x4Eui64:
          v34 = (unsigned __int8)v9;
          goto $add_Terminal_0;
        case 0x4Fui64:
          v34 = v10 + ((unsigned __int8)v9 << 8);
          goto $add_Terminal_0;
        case 0x50ui64:
          v34 = v11 + ((v10 + ((unsigned __int8)v9 << 8)) << 8);
          goto $add_Terminal_0;
        case 0x51ui64:
          v34 = *((unsigned __int8 *)v6 + 4) + ((v11 + ((v10 + ((unsigned __int8)v9 << 8)) << 8)) << 8);
$add_Terminal_0:
          v35 = v46->m_primitives_out;
          v36 = (v34 + v7->m_primitiveOffset) | v46->m_reindexingMask.m_storage & (v5 >> 9 << 8);
          if ( v46->m_primitives_out->m_size == (v46->m_primitives_out->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v46->m_primitives_out,
              4);
          v37 = v35->m_size;
          v38 = (int *)&v35->m_data[v37];
          v35->m_size = v37 + 1;
          *v38 = v36;
          return;
        case 0x5Eui64:
        case 0x5Fui64:
        case 0x60ui64:
        case 0x61ui64:
          v6 = v39;
          *((_DWORD *)&v45 + (unsigned int)(v8 - 96) + 1) = (unsigned __int8)v9;
          goto $propertyCopy_0;
        case 0x62ui64:
        case 0x63ui64:
        case 0x64ui64:
        case 0x65ui64:
          v6 += 3;
          v31 = v10 + ((unsigned __int8)v9 << 8);
          v32 = (unsigned int)(v8 - 100);
          goto LABEL_60;
        case 0x66ui64:
        case 0x67ui64:
        case 0x68ui64:
        case 0x69ui64:
          v31 = *((unsigned __int8 *)v6 + 4) + ((unsigned __int8)v9 << 24) + (v10 << 16) + (v11 << 8);
          v32 = (unsigned int)(v8 - 104);
          v6 += 5;
LABEL_60:
          *((_DWORD *)&v45 + v32 + 1) = v31;
$propertyCopy_0:
          a5 = DWORD1(v45);
          if ( v7 != (hkpMoppObbVirtualMachineQuery *)&v42 )
          {
            v42 = *(_OWORD *)&v7->m_xHi;
            v43 = *(_OWORD *)&v7->m_xLo;
            v44 = *(_OWORD *)&v7->m_offset_x;
            v33 = *(_OWORD *)&v7->m_shift;
            v7 = (hkpMoppObbVirtualMachineQuery *)&v42;
            v45 = v33;
          }
          DWORD1(v45) = a5;
          continue;
        case 0x6Eui64:
          v5 = *((unsigned __int8 *)v6 + 4) + ((v11 + ((v10 + ((unsigned __int8)v9 << 8)) << 8)) << 8);
          a5 = (unsigned __int64)v46->m_code.m_storage;
          v6 = (const char *)(*(_QWORD *)(a5 + 32) + v5);
          continue;
        default:
          __debugbreak();
          continue;
      }
    }
  }
}

// File Line: 559
// RVA: 0xDB1E50
void __fastcall hkpMoppObbVirtualMachine::queryObb(hkpMoppObbVirtualMachine *this, hkpMoppCode *code, hkTransformf *BvToWorld, hkVector4f *extent, const float radius, hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *primitives_out)
{
  hkpMoppObbVirtualMachine *v6; // rbx
  hkpMoppCode *v7; // r11
  __m128 v8; // xmm5
  __m128 v9; // xmm2
  __m128 v10; // xmm1
  __m128 v11; // xmm0
  __m128 v12; // xmm4
  __m128 v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm6
  __m128 v16; // xmm2
  __m128 v17; // xmm1
  __m128 v18; // xmm5
  __m128i v19; // xmm3
  __m128i v20; // xmm4
  int v21; // ecx
  int v22; // er9
  int v23; // edx
  int v24; // er10
  int v25; // er8
  int v26; // eax
  const char *v27; // r8
  hkpMoppObbVirtualMachineQuery query; // [rsp+20h] [rbp-58h]

  this->m_code.m_storage = code;
  this->m_primitives_out = primitives_out;
  v6 = this;
  v7 = code;
  v8 = _mm_sub_ps(BvToWorld->m_translation.m_quad, code->m_info.m_offset.m_quad);
  v9 = _mm_and_ps(extent->m_quad, (__m128)xmmword_141687F20[0]);
  v10 = _mm_and_ps(extent->m_quad, (__m128)`hkVector4f::getComponent::`2::indexToMask[0]);
  v11 = _mm_and_ps(extent->m_quad, (__m128)xmmword_141687F10);
  v12 = _mm_or_ps(_mm_shuffle_ps(v10, v10, 78), v10);
  v13 = _mm_or_ps(_mm_shuffle_ps(v9, v9, 78), v9);
  v14 = _mm_or_ps(_mm_shuffle_ps(v11, v11, 78), v11);
  v15 = _mm_add_ps(
          _mm_add_ps(
            _mm_add_ps(
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32(
                          (__m128i)_mm_mul_ps(
                                     _mm_or_ps(_mm_shuffle_ps(v14, v14, 177), v14),
                                     BvToWorld->m_rotation.m_col1.m_quad),
                          1u),
                        1u),
              (__m128)_mm_srli_epi32(
                        _mm_slli_epi32(
                          (__m128i)_mm_mul_ps(
                                     _mm_or_ps(_mm_shuffle_ps(v12, v12, 177), v12),
                                     BvToWorld->m_rotation.m_col0.m_quad),
                          1u),
                        1u)),
            (__m128)_mm_srli_epi32(
                      _mm_slli_epi32(
                        (__m128i)_mm_mul_ps(
                                   _mm_or_ps(_mm_shuffle_ps(v13, v13, 177), v13),
                                   BvToWorld->m_rotation.m_col2.m_quad),
                        1u),
                      1u)),
          _mm_shuffle_ps((__m128)LODWORD(radius), (__m128)LODWORD(radius), 0));
  v16 = _mm_shuffle_ps(
          (__m128)code->m_info.m_offset.m_quad.m128_u32[3],
          (__m128)code->m_info.m_offset.m_quad.m128_u32[3],
          0);
  v17 = _mm_mul_ps(
          _mm_add_ps(_mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v15), v8),
          v16);
  v18 = _mm_mul_ps(_mm_add_ps(v8, v15), v16);
  v19 = _mm_xor_si128(
          (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v17),
          _mm_cvttps_epi32(v17));
  v20 = _mm_xor_si128(
          (__m128i)_mm_cmpleps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v18),
          _mm_cvttps_epi32(v18));
  v21 = _mm_cvtsi128_si32(v19) - 1;
  v6->m_xLo = v21;
  v22 = _mm_cvtsi128_si32(v20) + 1;
  v6->m_xHi = v22;
  v23 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v19, 85)) - 1;
  v6->m_yLo = v23;
  v24 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v20, 85)) + 1;
  v6->m_yHi = v24;
  query.m_xLo = v21 >> 16;
  query.m_xHi = (v22 >> 16) + 1;
  query.m_yLo = v23 >> 16;
  v25 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v19, 170)) - 1;
  v26 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v20, 170)) + 1;
  v6->m_zHi = v26;
  v6->m_zLo = v25;
  query.m_zHi = (v26 >> 16) + 1;
  query.m_yHi = (v24 >> 16) + 1;
  *(_QWORD *)&query.m_offset_x = 0i64;
  *(_QWORD *)&query.m_offset_z = 0i64;
  *(_QWORD *)&query.m_shift = 0i64;
  query.m_zLo = v25 >> 16;
  v27 = v7->m_data.m_data;
  v6->m_reindexingMask.m_storage = (*v27 != 13) - 1;
  hkpMoppObbVirtualMachine::queryAabbOnTree(v6, &query, v27, 0);
}k.m_storage = (*v27 != 13) - 1;
  hkpMoppObbVirtua

// File Line: 590
// RVA: 0xDB2060
void __fastcall hkpMoppObbVirtualMachine::queryAabb(hkpMoppObbVirtualMachine *this, hkpMoppCode *code, hkAabb *aabb, hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *primitives_out)
{
  float v4; // xmm2_4
  float v5; // xmm1_4
  hkAabb *v6; // r11
  hkpMoppCode *v7; // rbx
  hkpMoppObbVirtualMachine *v8; // rdi
  int v9; // er10
  int v10; // er9
  float v11; // xmm1_4
  int v12; // er8
  int v13; // edx
  float v14; // xmm1_4
  float v15; // xmm0_4
  int v16; // ecx
  float v17; // xmm0_4
  int v18; // eax
  const char *v19; // r8
  hkpMoppObbVirtualMachineQuery query; // [rsp+20h] [rbp-40h]

  this->m_code.m_storage = code;
  this->m_primitives_out = primitives_out;
  v4 = code->m_info.m_offset.m_quad.m128_f32[3];
  v5 = code->m_info.m_offset.m_quad.m128_f32[0];
  v6 = aabb;
  v7 = code;
  v8 = this;
  v9 = (signed int)(float)((float)(aabb->m_min.m_quad.m128_f32[0] - v5) * v4) - 1;
  this->m_xLo = v9;
  v10 = (signed int)(float)((float)(aabb->m_max.m_quad.m128_f32[0] - v5) * v4) + 1;
  this->m_xHi = v10;
  v11 = code->m_info.m_offset.m_quad.m128_f32[1];
  v12 = (signed int)(float)((float)(aabb->m_min.m_quad.m128_f32[1] - v11) * v4) - 1;
  this->m_yLo = v12;
  v13 = (signed int)(float)((float)(v6->m_max.m_quad.m128_f32[1] - v11) * v4) + 1;
  this->m_yHi = v13;
  v14 = v7->m_info.m_offset.m_quad.m128_f32[2];
  v15 = v6->m_min.m_quad.m128_f32[2];
  query.m_yLo = v12 >> 16;
  query.m_xLo = v9 >> 16;
  query.m_xHi = (v10 >> 16) + 1;
  query.m_yHi = (v13 >> 16) + 1;
  v16 = (signed int)(float)((float)(v15 - v14) * v4) - 1;
  v8->m_zLo = v16;
  v17 = v6->m_max.m_quad.m128_f32[2];
  query.m_zLo = v16 >> 16;
  v18 = (signed int)(float)((float)(v17 - v14) * v4) + 1;
  v8->m_zHi = v18;
  v19 = v7->m_data.m_data;
  query.m_zHi = (v18 >> 16) + 1;
  *(_QWORD *)&query.m_offset_x = 0i64;
  *(_QWORD *)&query.m_offset_z = 0i64;
  *(_QWORD *)&query.m_shift = 0i64;
  v8->m_reindexingMask.m_storage = (*v19 != 13) - 1;
  hkpMoppObbVirtualMachine::queryAabbOnTree(v8, &query, v19, 0);
}

