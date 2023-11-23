// File Line: 69
// RVA: 0xDB21E0
void __fastcall hkpMoppObbVirtualMachine::queryAabbOnTree(
        hkpMoppObbVirtualMachine *this,
        hkpMoppObbVirtualMachineQuery *query,
        const char *PC,
        int chunkOffset)
{
  unsigned __int64 m_primitiveOffset; // rax
  __int64 v8; // r8
  unsigned __int8 v9; // r9
  unsigned __int8 v10; // r10
  unsigned __int8 v11; // r11
  int v12; // r8d
  int v13; // edx
  int v14; // ecx
  int m_xHi; // ecx
  int v16; // eax
  __int64 v17; // rcx
  int v18; // r8d
  __int64 v19; // rcx
  int v20; // r8d
  int v21; // eax
  const char *v22; // rbx
  unsigned int v23; // edx
  unsigned int v24; // r8d
  int m_xLo; // edx
  __int128 v26; // xmm1
  __int128 v27; // xmm1
  int v28; // ecx
  __int128 v29; // xmm1
  int v30; // edx
  __int64 v31; // rax
  __int128 v32; // xmm1
  int v33; // ecx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *m_primitives_out; // rbx
  unsigned int v35; // esi
  __int64 m_size; // r8
  hkpMoppPrimitiveInfo *v37; // rdx
  const char *v38; // [rsp+20h] [rbp-50h]
  unsigned int v39; // [rsp+20h] [rbp-50h]
  int v40; // [rsp+20h] [rbp-50h]
  __int128 v41; // [rsp+30h] [rbp-40h] BYREF
  __int128 v42; // [rsp+40h] [rbp-30h]
  __int128 v43; // [rsp+50h] [rbp-20h]
  __int128 v44; // [rsp+60h] [rbp-10h]

  if ( HK_flyingcolors_mopp_0.m_bool
    || (hkpCheckKeycode(),
        LODWORD(m_primitiveOffset) = hkpProcessFlyingColors(&HK_flyingcolors_mopp_0),
        HK_flyingcolors_mopp_0.m_bool) )
  {
    while ( 1 )
    {
      v8 = *(unsigned __int8 *)PC;
      v9 = PC[1];
      v10 = PC[2];
      v11 = PC[3];
      v38 = (const char *)m_primitiveOffset;
      m_primitiveOffset = 0x140000000ui64;
      switch ( (unsigned __int64)PC )
      {
        case 0xFFFFFFFFFFFFFFFEui64:
          return;
        case 0xFFFFFFFFFFFFFFFFui64:
        case 0ui64:
        case 1ui64:
        case 2ui64:
          LODWORD(v43) = (v9 + query->m_offset_x) << v8;
          DWORD1(v43) = (v10 + query->m_offset_y) << v8;
          DWORD2(v43) = (v11 + query->m_offset_z) << v8;
          m_xLo = this->m_xLo;
          LODWORD(v44) = v8 + query->m_shift;
          LODWORD(v42) = (m_xLo >> (16 - v44)) - v43;
          DWORD1(v42) = (this->m_yLo >> (16 - v44)) - DWORD1(v43);
          DWORD2(v42) = (this->m_zLo >> (16 - v44)) - DWORD2(v43);
          LODWORD(v41) = (this->m_xHi >> (16 - v44)) - v43 + 1;
          DWORD1(v41) = (this->m_yHi >> (16 - v44)) - DWORD1(v43) + 1;
          PC += 4;
          DWORD2(v41) = (this->m_zHi >> (16 - v44)) - DWORD2(v43) + 1;
          DWORD1(v44) = query->m_properties[0];
          m_primitiveOffset = query->m_primitiveOffset;
          query = (hkpMoppObbVirtualMachineQuery *)&v41;
          HIDWORD(v43) = m_primitiveOffset;
          continue;
        case 3ui64:
          m_primitiveOffset = v9;
          PC = &v38[v9];
          continue;
        case 4ui64:
          m_primitiveOffset = v10;
          PC += 256 * v9 + v10 + 3;
          continue;
        case 5ui64:
          m_primitiveOffset = (v10 << 8) + (v9 << 16) + (unsigned int)v11;
          PC += m_primitiveOffset + 4;
          continue;
        case 6ui64:
          m_primitiveOffset = (v9 << 24) + *((unsigned __int8 *)PC + 4) + (((v10 << 8) + (unsigned int)v11) << 8);
          PC += m_primitiveOffset + 5;
          continue;
        case 7ui64:
          m_primitiveOffset = v9;
          if ( query != (hkpMoppObbVirtualMachineQuery *)&v41 )
          {
            v41 = *(_OWORD *)&query->m_xHi;
            v42 = *(_OWORD *)&query->m_xLo;
            v43 = *(_OWORD *)&query->m_offset_x;
            v26 = *(_OWORD *)&query->m_shift;
            query = (hkpMoppObbVirtualMachineQuery *)&v41;
            v44 = v26;
          }
          HIDWORD(v43) += v9;
          PC = v38;
          continue;
        case 8ui64:
          m_primitiveOffset = (unsigned __int64)&v41;
          if ( query != (hkpMoppObbVirtualMachineQuery *)&v41 )
          {
            v41 = *(_OWORD *)&query->m_xHi;
            v42 = *(_OWORD *)&query->m_xLo;
            v43 = *(_OWORD *)&query->m_offset_x;
            v27 = *(_OWORD *)&query->m_shift;
            query = (hkpMoppObbVirtualMachineQuery *)&v41;
            v44 = v27;
          }
          HIDWORD(v43) += v10 + (v9 << 8);
          PC += 3;
          continue;
        case 9ui64:
          v28 = *((unsigned __int8 *)PC + 4) + (v9 << 24) + (v10 << 16) + (v11 << 8);
          m_primitiveOffset = (unsigned __int64)&v41;
          if ( query != (hkpMoppObbVirtualMachineQuery *)&v41 )
          {
            v41 = *(_OWORD *)&query->m_xHi;
            v42 = *(_OWORD *)&query->m_xLo;
            v43 = *(_OWORD *)&query->m_offset_x;
            v29 = *(_OWORD *)&query->m_shift;
            query = (hkpMoppObbVirtualMachineQuery *)&v41;
            v44 = v29;
          }
          HIDWORD(v43) = v28;
          goto $LN28_55;
        case 0xAui64:
          m_primitiveOffset = (unsigned __int64)this->m_code.m_storage;
          chunkOffset = (v10 | (v9 << 8)) << 9;
          PC = (const char *)(*(_QWORD *)(m_primitiveOffset + 32) + chunkOffset);
          continue;
        case 0xBui64:
$LN28_55:
          PC += 5;
          continue;
        case 0xEui64:
        case 0xFui64:
        case 0x10ui64:
          v17 = *(unsigned __int8 *)PC;
          m_primitiveOffset = v10;
          PC += 4;
          v18 = *((_DWORD *)query + (int)v8 - 12);
          if ( *(&query[-1].m_xHi + v17) > v10 )
          {
            PC += v11;
            if ( v18 < v9 )
              hkpMoppObbVirtualMachine::queryAabbOnTree(this, query, &PC[-v11], chunkOffset);
          }
          else if ( v18 >= v9 )
          {
            return;
          }
          continue;
        case 0x11ui64:
          v12 = 2 * v10;
          v13 = 2 * v9;
          m_primitiveOffset = (unsigned int)(query->m_yLo + query->m_zLo);
          v14 = query->m_yHi + query->m_zHi;
          goto $do_compare_0;
        case 0x12ui64:
          v13 = 2 * v9 - 255;
          v12 = 2 * v10 - 255;
          m_primitiveOffset = (unsigned int)(query->m_yLo - query->m_zHi);
          v14 = query->m_yHi - query->m_zLo;
          goto $do_compare_0;
        case 0x13ui64:
          v12 = 2 * v10;
          v13 = 2 * v9;
          m_primitiveOffset = (unsigned int)(query->m_xLo + query->m_zLo);
          v14 = query->m_xHi + query->m_zHi;
          goto $do_compare_0;
        case 0x14ui64:
          v13 = 2 * v9 - 255;
          v12 = 2 * v10 - 255;
          m_primitiveOffset = (unsigned int)(query->m_xLo - query->m_zHi);
          v14 = query->m_xHi - query->m_zLo;
          goto $do_compare_0;
        case 0x15ui64:
          v12 = 2 * v10;
          v13 = 2 * v9;
          m_primitiveOffset = (unsigned int)(query->m_xLo + query->m_yLo);
          v14 = query->m_xHi + query->m_yHi;
          goto $do_compare_0;
        case 0x16ui64:
          m_xHi = query->m_xHi;
          v13 = 2 * v9 - 255;
          v12 = 2 * v10 - 255;
          v16 = query->m_xLo;
          goto LABEL_14;
        case 0x17ui64:
          v13 = 3 * v9;
          v12 = 3 * v10;
          m_primitiveOffset = (unsigned int)(query->m_xLo + query->m_yLo + query->m_zLo);
          v14 = query->m_xHi + query->m_yHi + query->m_zHi;
          goto $do_compare_0;
        case 0x18ui64:
          v13 = 3 * (v9 - 85);
          v12 = 3 * (v10 - 85);
          m_primitiveOffset = (unsigned int)(query->m_xLo + query->m_yLo - query->m_zHi);
          v14 = query->m_xHi + query->m_yHi - query->m_zLo;
          goto $do_compare_0;
        case 0x19ui64:
          v13 = 3 * (v9 - 85);
          v12 = 3 * (v10 - 85);
          m_primitiveOffset = (unsigned int)(query->m_xLo + query->m_zLo - query->m_yHi);
          v14 = query->m_xHi + query->m_zHi - query->m_yLo;
          goto $do_compare_0;
        case 0x1Aui64:
          v13 = 3 * (v9 - 170);
          v12 = 3 * (v10 - 170);
          v16 = query->m_xLo - query->m_zHi;
          m_xHi = query->m_xHi - query->m_zLo;
LABEL_14:
          m_primitiveOffset = (unsigned int)(v16 - query->m_yHi);
          v14 = m_xHi - query->m_yLo;
$do_compare_0:
          PC += 4;
          v39 = v11;
          if ( v14 > v12 )
          {
            if ( (int)m_primitiveOffset < v13 )
            {
              hkpMoppObbVirtualMachine::queryAabbOnTree(this, query, PC, chunkOffset);
              m_primitiveOffset = v39;
              PC += v39;
            }
            else
            {
              PC += v11;
            }
          }
          else if ( (int)m_primitiveOffset >= v13 )
          {
            return;
          }
          continue;
        case 0x1Eui64:
        case 0x1Fui64:
        case 0x20ui64:
          PC += 3;
          m_primitiveOffset = v10;
          if ( *(&query[-2].m_xHi + (int)v8) > v9 )
          {
            PC += v10;
            if ( *((_DWORD *)&query[-1] + (int)v8 - 12) <= (int)v9 )
              hkpMoppObbVirtualMachine::queryAabbOnTree(this, query, &PC[-v10], chunkOffset);
          }
          continue;
        case 0x21ui64:
        case 0x22ui64:
        case 0x23ui64:
          v19 = *(unsigned __int8 *)PC;
          v20 = *((unsigned __int8 *)PC + 5) << 8;
          v40 = *((_DWORD *)&query[-1] + v19 - 15);
          v21 = *((unsigned __int8 *)PC + 4);
          v22 = PC + 7;
          v23 = v21 + (v11 << 8);
          v24 = *((unsigned __int8 *)v22 - 1) + v20;
          if ( *((_DWORD *)&query[-2] + v19 - 3) > (int)v10 )
          {
            m_primitiveOffset = v24;
            PC = &v22[v24];
            if ( v40 < v9 )
              hkpMoppObbVirtualMachine::queryAabbOnTree(this, query, &PC[v23 - (unsigned __int64)v24], chunkOffset);
          }
          else
          {
            if ( v40 >= v9 )
              return;
            m_primitiveOffset = v23;
            PC = &v22[v23];
          }
          break;
        case 0x24ui64:
        case 0x25ui64:
        case 0x26ui64:
          if ( *((_DWORD *)&query[-2] + *(unsigned __int8 *)PC - 6) < (int)v9 )
            return;
          m_primitiveOffset = v10;
          if ( *((_DWORD *)&query[-2] + *(unsigned __int8 *)PC - 2) >= (int)v10 )
            return;
          PC += 3;
          continue;
        case 0x27ui64:
        case 0x28ui64:
        case 0x29ui64:
          if ( *((_DWORD *)&this[-1] + v8 - 13) < v11 + ((v10 + (v9 << 8)) << 8) )
            return;
          m_primitiveOffset = *((unsigned __int8 *)PC + 6);
          if ( *((_DWORD *)&this[-1] + v8 - 9) > (signed int)(m_primitiveOffset
                                                            + ((*((unsigned __int8 *)PC + 5)
                                                              + (*((unsigned __int8 *)PC + 4) << 8)) << 8)) )
            return;
          PC += 7;
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
          v33 = v8 - 48;
          goto $add_Terminal_0;
        case 0x4Eui64:
          v33 = v9;
          goto $add_Terminal_0;
        case 0x4Fui64:
          v33 = v10 + (v9 << 8);
          goto $add_Terminal_0;
        case 0x50ui64:
          v33 = v11 + ((v10 + (v9 << 8)) << 8);
          goto $add_Terminal_0;
        case 0x51ui64:
          v33 = *((unsigned __int8 *)PC + 4) + ((v11 + ((v10 + (v9 << 8)) << 8)) << 8);
$add_Terminal_0:
          m_primitives_out = this->m_primitives_out;
          v35 = (v33 + query->m_primitiveOffset) | this->m_reindexingMask.m_storage & (chunkOffset >> 9 << 8);
          if ( this->m_primitives_out->m_size == (this->m_primitives_out->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&this->m_primitives_out->m_data,
              4);
          m_size = m_primitives_out->m_size;
          v37 = &m_primitives_out->m_data[m_size];
          m_primitives_out->m_size = m_size + 1;
          v37->ID = v35;
          return;
        case 0x5Eui64:
        case 0x5Fui64:
        case 0x60ui64:
        case 0x61ui64:
          PC = v38;
          *((_DWORD *)&v44 + (unsigned int)(v8 - 96) + 1) = v9;
          goto $propertyCopy_0;
        case 0x62ui64:
        case 0x63ui64:
        case 0x64ui64:
        case 0x65ui64:
          PC += 3;
          v30 = v10 + (v9 << 8);
          v31 = (unsigned int)(v8 - 100);
          goto LABEL_60;
        case 0x66ui64:
        case 0x67ui64:
        case 0x68ui64:
        case 0x69ui64:
          v30 = *((unsigned __int8 *)PC + 4) + (v9 << 24) + (v10 << 16) + (v11 << 8);
          v31 = (unsigned int)(v8 - 104);
          PC += 5;
LABEL_60:
          *((_DWORD *)&v44 + v31 + 1) = v30;
$propertyCopy_0:
          m_primitiveOffset = DWORD1(v44);
          if ( query != (hkpMoppObbVirtualMachineQuery *)&v41 )
          {
            v41 = *(_OWORD *)&query->m_xHi;
            v42 = *(_OWORD *)&query->m_xLo;
            v43 = *(_OWORD *)&query->m_offset_x;
            v32 = *(_OWORD *)&query->m_shift;
            query = (hkpMoppObbVirtualMachineQuery *)&v41;
            v44 = v32;
          }
          DWORD1(v44) = m_primitiveOffset;
          continue;
        case 0x6Eui64:
          chunkOffset = *((unsigned __int8 *)PC + 4) + ((v11 + ((v10 + (v9 << 8)) << 8)) << 8);
          m_primitiveOffset = (unsigned __int64)this->m_code.m_storage;
          PC = (const char *)(*(_QWORD *)(m_primitiveOffset + 32) + chunkOffset);
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
void __fastcall hkpMoppObbVirtualMachine::queryObb(
        hkpMoppObbVirtualMachine *this,
        hkpMoppCode *code,
        hkTransformf *BvToWorld,
        hkVector4f *extent,
        unsigned int radius,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *primitives_out)
{
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
  int v22; // r9d
  int v23; // edx
  int v24; // r10d
  int v25; // r8d
  int v26; // eax
  char *m_data; // r8
  hkpMoppObbVirtualMachineQuery query; // [rsp+20h] [rbp-58h] BYREF

  this->m_code.m_storage = code;
  this->m_primitives_out = primitives_out;
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
          _mm_shuffle_ps((__m128)radius, (__m128)radius, 0));
  v16 = _mm_shuffle_ps(
          (__m128)code->m_info.m_offset.m_quad.m128_u32[3],
          (__m128)code->m_info.m_offset.m_quad.m128_u32[3],
          0);
  v17 = _mm_mul_ps(
          _mm_add_ps(_mm_xor_ps((__m128)_mm_shuffle_epi32(_mm_insert_epi16((__m128i)0i64, 0x8000u, 1), 0), v15), v8),
          v16);
  v18 = _mm_mul_ps(_mm_add_ps(v8, v15), v16);
  v19 = _mm_xor_si128(
          (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v17),
          _mm_cvttps_epi32(v17));
  v20 = _mm_xor_si128(
          (__m128i)_mm_cmple_ps(*(__m128 *)`hkIntVector::setConvertF32toS32::`2::two31, v18),
          _mm_cvttps_epi32(v18));
  v21 = _mm_cvtsi128_si32(v19) - 1;
  this->m_xLo = v21;
  v22 = _mm_cvtsi128_si32(v20) + 1;
  this->m_xHi = v22;
  v23 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v19, 85)) - 1;
  this->m_yLo = v23;
  v24 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v20, 85)) + 1;
  this->m_yHi = v24;
  query.m_xLo = v21 >> 16;
  query.m_xHi = (v22 >> 16) + 1;
  query.m_yLo = v23 >> 16;
  v25 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v19, 170)) - 1;
  v26 = _mm_cvtsi128_si32(_mm_shuffle_epi32(v20, 170)) + 1;
  this->m_zHi = v26;
  this->m_zLo = v25;
  query.m_zHi = (v26 >> 16) + 1;
  query.m_yHi = (v24 >> 16) + 1;
  memset(&query.m_offset_x, 0, 24);
  query.m_zLo = v25 >> 16;
  m_data = code->m_data.m_data;
  this->m_reindexingMask.m_storage = (*m_data != 13) - 1;
  hkpMoppObbVirtualMachine::queryAabbOnTree(this, &query, m_data, 0);
}

// File Line: 590
// RVA: 0xDB2060
void __fastcall hkpMoppObbVirtualMachine::queryAabb(
        hkpMoppObbVirtualMachine *this,
        hkpMoppCode *code,
        hkAabb *aabb,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *primitives_out)
{
  float v4; // xmm2_4
  float v5; // xmm1_4
  int v9; // r10d
  int v10; // r9d
  float v11; // xmm1_4
  int v12; // r8d
  int v13; // edx
  float v14; // xmm1_4
  float v15; // xmm0_4
  int v16; // ecx
  float v17; // xmm0_4
  int v18; // eax
  char *m_data; // r8
  hkpMoppObbVirtualMachineQuery query; // [rsp+20h] [rbp-40h] BYREF

  this->m_code.m_storage = code;
  this->m_primitives_out = primitives_out;
  v4 = code->m_info.m_offset.m_quad.m128_f32[3];
  v5 = code->m_info.m_offset.m_quad.m128_f32[0];
  v9 = (int)(float)((float)(aabb->m_min.m_quad.m128_f32[0] - v5) * v4) - 1;
  this->m_xLo = v9;
  v10 = (int)(float)((float)(aabb->m_max.m_quad.m128_f32[0] - v5) * v4) + 1;
  this->m_xHi = v10;
  v11 = code->m_info.m_offset.m_quad.m128_f32[1];
  v12 = (int)(float)((float)(aabb->m_min.m_quad.m128_f32[1] - v11) * v4) - 1;
  this->m_yLo = v12;
  v13 = (int)(float)((float)(aabb->m_max.m_quad.m128_f32[1] - v11) * v4) + 1;
  this->m_yHi = v13;
  v14 = code->m_info.m_offset.m_quad.m128_f32[2];
  v15 = aabb->m_min.m_quad.m128_f32[2];
  query.m_yLo = v12 >> 16;
  query.m_xLo = v9 >> 16;
  query.m_xHi = (v10 >> 16) + 1;
  query.m_yHi = (v13 >> 16) + 1;
  v16 = (int)(float)((float)(v15 - v14) * v4) - 1;
  this->m_zLo = v16;
  v17 = aabb->m_max.m_quad.m128_f32[2];
  query.m_zLo = v16 >> 16;
  v18 = (int)(float)((float)(v17 - v14) * v4) + 1;
  this->m_zHi = v18;
  m_data = code->m_data.m_data;
  query.m_zHi = (v18 >> 16) + 1;
  memset(&query.m_offset_x, 0, 24);
  this->m_reindexingMask.m_storage = (*m_data != 13) - 1;
  hkpMoppObbVirtualMachine::queryAabbOnTree(this, &query, m_data, 0);
}

