// File Line: 51
// RVA: 0xDF7460
hkBool *__fastcall hkpMoppModifyVirtualMachine::queryModicationPointsRecursive(
        hkpMoppModifyVirtualMachine *this,
        hkBool *result,
        hkpMoppObbVirtualMachineQuery *query,
        const char *PC,
        int chunkOffset)
{
  __int64 m_primitiveOffset; // rax
  __int64 v9; // rbx
  unsigned __int8 v10; // dl
  int v11; // r8d
  unsigned __int8 v12; // r9
  int m_xLo; // eax
  __int128 v14; // xmm1
  __int128 v15; // xmm1
  int v16; // ecx
  __int128 v17; // xmm1
  int v18; // edx
  __int64 v19; // rax
  __int128 v20; // xmm1
  int v21; // ecx
  int v22; // edx
  int v23; // r10d
  int v24; // r10d
  unsigned int v25; // eax
  __int64 v26; // r9
  const char *v27; // r11
  int v28; // eax
  int v29; // r10d
  int v30; // eax
  int v31; // r10d
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  const char *v36; // r11
  int v37; // ebx
  char m_bool; // bl
  char v39; // di
  hkpMoppObbVirtualMachineQuery *v40; // r8
  hkpMoppModifyVirtualMachine *v41; // rsi
  hkBool *v42; // rax
  hkpMoppObbVirtualMachineQuery *v43; // r8
  hkBool *v44; // rdx
  const char *v45; // r9
  int v46; // edi
  hkBool *v47; // rax
  hkpMoppModifier *m_modifier; // rcx
  hkpMoppCode *m_storage; // rax
  int v50; // esi
  int v51; // ecx
  int v52; // [rsp+20h] [rbp-60h]
  unsigned int v53; // [rsp+30h] [rbp-50h]
  hkBool v54; // [rsp+34h] [rbp-4Ch] BYREF
  char v55; // [rsp+35h] [rbp-4Bh] BYREF
  hkBool v56; // [rsp+36h] [rbp-4Ah] BYREF
  hkBool resulta; // [rsp+37h] [rbp-49h] BYREF
  const char *v58; // [rsp+38h] [rbp-48h]
  __int128 v59; // [rsp+40h] [rbp-40h] BYREF
  __int128 v60; // [rsp+50h] [rbp-30h]
  __int128 v61; // [rsp+60h] [rbp-20h]
  __int128 v62; // [rsp+70h] [rbp-10h]
  const char *v65; // [rsp+B8h] [rbp+38h] BYREF

  while ( 2 )
  {
    v9 = *(unsigned __int8 *)PC;
    v10 = PC[3];
    LOBYTE(v11) = PC[1];
    v12 = PC[2];
    LOBYTE(v65) = v10;
    v58 = (const char *)m_primitiveOffset;
    m_primitiveOffset = 0x140000000ui64;
    switch ( (unsigned __int64)PC )
    {
      case 0xFFFFFFFFFFFFFFFEui64:
        goto $end_of_function_12;
      case 0xFFFFFFFFFFFFFFFFui64:
      case 0ui64:
      case 1ui64:
      case 2ui64:
        LODWORD(v61) = ((unsigned __int8)v11 + query->m_offset_x) << v9;
        DWORD1(v61) = (v12 + query->m_offset_y) << v9;
        m_xLo = this->m_xLo;
        DWORD2(v61) = (v10 + query->m_offset_z) << v9;
        LODWORD(v62) = v9 + query->m_shift;
        LODWORD(v60) = (m_xLo >> (16 - v62)) - v61;
        DWORD1(v60) = (this->m_yLo >> (16 - v62)) - DWORD1(v61);
        DWORD2(v60) = (this->m_zLo >> (16 - v62)) - DWORD2(v61);
        LODWORD(v59) = (this->m_xHi >> (16 - v62)) - v61 + 1;
        DWORD1(v59) = (this->m_yHi >> (16 - v62)) - DWORD1(v61) + 1;
        PC += 4;
        DWORD2(v59) = (this->m_zHi >> (16 - v62)) - DWORD2(v61) + 1;
        DWORD1(v62) = query->m_properties[0];
        m_primitiveOffset = query->m_primitiveOffset;
        query = (hkpMoppObbVirtualMachineQuery *)&v59;
        HIDWORD(v61) = m_primitiveOffset;
        continue;
      case 3ui64:
        m_primitiveOffset = (unsigned __int8)v11;
        PC += (unsigned __int8)v11 + 2;
        continue;
      case 4ui64:
        m_primitiveOffset = ((unsigned __int8)v11 << 8) + v12;
        PC += m_primitiveOffset + 3;
        continue;
      case 5ui64:
        m_primitiveOffset = (v12 << 8) + ((unsigned __int8)v11 << 16) + (unsigned int)v10;
        PC += m_primitiveOffset + 4;
        continue;
      case 6ui64:
        m_primitiveOffset = ((unsigned __int8)v11 << 24)
                          + ((v10 + (v12 << 8)) << 8)
                          + (unsigned int)*((unsigned __int8 *)PC + 4)
                          + 5i64;
        PC += m_primitiveOffset;
        continue;
      case 7ui64:
        m_primitiveOffset = (unsigned __int8)v11;
        if ( query != (hkpMoppObbVirtualMachineQuery *)&v59 )
        {
          v59 = *(_OWORD *)&query->m_xHi;
          v60 = *(_OWORD *)&query->m_xLo;
          v61 = *(_OWORD *)&query->m_offset_x;
          v14 = *(_OWORD *)&query->m_shift;
          query = (hkpMoppObbVirtualMachineQuery *)&v59;
          v62 = v14;
        }
        HIDWORD(v61) += (unsigned __int8)v11;
        PC = v58;
        continue;
      case 8ui64:
        m_primitiveOffset = (__int64)&v59;
        if ( query != (hkpMoppObbVirtualMachineQuery *)&v59 )
        {
          v59 = *(_OWORD *)&query->m_xHi;
          v60 = *(_OWORD *)&query->m_xLo;
          v61 = *(_OWORD *)&query->m_offset_x;
          v15 = *(_OWORD *)&query->m_shift;
          query = (hkpMoppObbVirtualMachineQuery *)&v59;
          v62 = v15;
        }
        HIDWORD(v61) += v12 + ((unsigned __int8)v11 << 8);
        PC += 3;
        continue;
      case 9ui64:
        v16 = *((unsigned __int8 *)PC + 4) + ((unsigned __int8)v11 << 24) + (v12 << 16) + (v10 << 8);
        m_primitiveOffset = (__int64)&v59;
        if ( query != (hkpMoppObbVirtualMachineQuery *)&v59 )
        {
          v59 = *(_OWORD *)&query->m_xHi;
          v60 = *(_OWORD *)&query->m_xLo;
          v61 = *(_OWORD *)&query->m_offset_x;
          v17 = *(_OWORD *)&query->m_shift;
          query = (hkpMoppObbVirtualMachineQuery *)&v59;
          v62 = v17;
        }
        HIDWORD(v61) = v16;
        goto $LN28_68;
      case 0xAui64:
        m_primitiveOffset = (__int64)this->m_code.m_storage;
        chunkOffset = (v12 | ((unsigned __int8)v11 << 8)) << 9;
        PC = (const char *)(*(_QWORD *)(m_primitiveOffset + 32) + chunkOffset);
        continue;
      case 0xBui64:
$LN28_68:
        PC += 5;
        continue;
      case 0xEui64:
      case 0xFui64:
      case 0x10ui64:
        v24 = (unsigned __int8)v11;
        v11 = v12;
        v21 = *((_DWORD *)query + (int)v9 - 12);
        v22 = *(&query[-1].m_xHi + (int)v9);
        v25 = (unsigned __int8)v65;
        v26 = 0i64;
        v27 = PC + 4;
        v53 = (unsigned __int8)v65;
        goto LABEL_46;
      case 0x11ui64:
        v21 = query->m_yLo + query->m_zLo;
        v22 = query->m_yHi + query->m_zHi;
        v23 = (unsigned __int8)v11;
        v11 = 2 * v12;
        v24 = 2 * v23;
        v25 = (unsigned __int8)v65;
        v26 = 0i64;
        v27 = PC + 4;
        v53 = (unsigned __int8)v65;
        goto LABEL_46;
      case 0x12ui64:
        v21 = query->m_yLo - query->m_zHi;
        v22 = query->m_yHi - query->m_zLo;
        v24 = 2 * (unsigned __int8)v11 - 255;
        v28 = v12;
        v26 = 0i64;
        v27 = PC + 4;
        v11 = 2 * v28 - 255;
        v25 = (unsigned __int8)v65;
        v53 = (unsigned __int8)v65;
        goto LABEL_46;
      case 0x13ui64:
        v21 = query->m_xLo + query->m_zLo;
        v22 = query->m_xHi + query->m_zHi;
        v29 = (unsigned __int8)v11;
        v11 = 2 * v12;
        v24 = 2 * v29;
        v25 = (unsigned __int8)v65;
        v26 = 0i64;
        v27 = PC + 4;
        v53 = (unsigned __int8)v65;
        goto LABEL_46;
      case 0x14ui64:
        v21 = query->m_xLo - query->m_zHi;
        v22 = query->m_xHi - query->m_zLo;
        v24 = 2 * (unsigned __int8)v11 - 255;
        v30 = v12;
        v26 = 0i64;
        v27 = PC + 4;
        v11 = 2 * v30 - 255;
        v25 = (unsigned __int8)v65;
        v53 = (unsigned __int8)v65;
        goto LABEL_46;
      case 0x15ui64:
        v21 = query->m_xLo + query->m_yLo;
        v22 = query->m_xHi + query->m_yHi;
        v31 = (unsigned __int8)v11;
        v11 = 2 * v12;
        v24 = 2 * v31;
        v25 = (unsigned __int8)v65;
        v26 = 0i64;
        v27 = PC + 4;
        v53 = (unsigned __int8)v65;
        goto LABEL_46;
      case 0x16ui64:
        v21 = query->m_xLo - query->m_yHi;
        v22 = query->m_xHi - query->m_yLo;
        v24 = 2 * (unsigned __int8)v11 - 255;
        v32 = v12;
        v26 = 0i64;
        v27 = PC + 4;
        v11 = 2 * v32 - 255;
        v25 = (unsigned __int8)v65;
        v53 = (unsigned __int8)v65;
        goto LABEL_46;
      case 0x17ui64:
        v24 = 3 * (unsigned __int8)v11;
        v21 = query->m_xLo + query->m_yLo + query->m_zLo;
        v22 = query->m_xHi + query->m_yHi + query->m_zHi;
        v11 = 3 * v12;
        v26 = 0i64;
        v25 = (unsigned __int8)v65;
        v27 = PC + 4;
        v53 = (unsigned __int8)v65;
        goto LABEL_46;
      case 0x18ui64:
        v21 = query->m_xLo + query->m_yLo - query->m_zHi;
        v22 = query->m_xHi + query->m_yHi - query->m_zLo;
        v24 = 3 * ((unsigned __int8)v11 - 85);
        v33 = v12;
        v26 = 0i64;
        v27 = PC + 4;
        v11 = 3 * (v33 - 85);
        v25 = (unsigned __int8)v65;
        v53 = (unsigned __int8)v65;
        goto LABEL_46;
      case 0x19ui64:
        v21 = query->m_xLo + query->m_zLo - query->m_yHi;
        v22 = query->m_xHi + query->m_zHi - query->m_yLo;
        v24 = 3 * ((unsigned __int8)v11 - 85);
        v34 = v12;
        v26 = 0i64;
        v27 = PC + 4;
        v11 = 3 * (v34 - 85);
        v25 = (unsigned __int8)v65;
        v53 = (unsigned __int8)v65;
        goto LABEL_46;
      case 0x1Aui64:
        v21 = query->m_xLo - query->m_zHi - query->m_yHi;
        v22 = query->m_xHi - query->m_zLo - query->m_yLo;
        v24 = 3 * ((unsigned __int8)v11 - 170);
        v35 = v12;
        v26 = 0i64;
        v27 = PC + 4;
        v11 = 3 * (v35 - 170);
        v25 = (unsigned __int8)v65;
        v53 = (unsigned __int8)v65;
        goto LABEL_46;
      case 0x1Eui64:
      case 0x1Fui64:
      case 0x20ui64:
        v36 = PC - 1;
        v11 = (unsigned __int8)v11;
        v21 = *((_DWORD *)&query[-1] + (int)v9 - 12);
        v22 = *(&query[-2].m_xHi + (int)v9);
        v25 = *((unsigned __int8 *)v36 + 3);
        v26 = 0i64;
        v24 = (unsigned __int8)v11 + 1;
        v53 = v25;
        v27 = v36 + 4;
        goto LABEL_46;
      case 0x21ui64:
      case 0x22ui64:
      case 0x23ui64:
        v21 = *((_DWORD *)&query[-1] + v9 - 15);
        v22 = *((_DWORD *)&query[-2] + v9 - 3);
        v24 = (unsigned __int8)v11;
        v11 = v12;
        v26 = *((unsigned __int8 *)PC + 4) + ((unsigned __int8)v65 << 8);
        v37 = *((unsigned __int8 *)PC + 6) + (*((unsigned __int8 *)PC + 5) << 8);
        v27 = PC + 7;
        v53 = v37;
        v25 = v37;
LABEL_46:
        m_bool = 0;
        v39 = 0;
        v65 = v27;
        LODWORD(v58) = v26;
        if ( v22 > v11 )
        {
          v43 = query;
          if ( v21 < v24 )
          {
            v46 = chunkOffset;
            v47 = hkpMoppModifyVirtualMachine::queryModicationPointsRecursive(this, &v56, query, &v27[v26], chunkOffset);
            v52 = v46;
            v45 = &v65[v53];
            m_bool = v47->m_bool;
            v43 = query;
            v44 = &v54;
          }
          else
          {
            v44 = (hkBool *)&v55;
            v52 = chunkOffset;
            v45 = &v27[v25];
          }
          v41 = this;
          v39 = hkpMoppModifyVirtualMachine::queryModicationPointsRecursive(this, v44, v43, v45, v52)->m_bool;
        }
        else
        {
          if ( v21 >= v24 )
          {
LABEL_49:
            v42 = result;
            result->m_bool = 0;
            return v42;
          }
          v40 = query;
          v41 = this;
          m_bool = hkpMoppModifyVirtualMachine::queryModicationPointsRecursive(
                     this,
                     &resulta,
                     v40,
                     &v27[v26],
                     chunkOffset)->m_bool;
        }
        if ( v39 == 0 && m_bool != 0 )
        {
          m_modifier = v41->m_modifier;
          m_storage = v41->m_code.m_storage;
          v50 = (int)v65;
          m_modifier->vfptr->addTerminalRemoveInfo(
            m_modifier,
            (_DWORD)v58 + (_DWORD)v65 - LODWORD(m_storage->m_data.m_data));
        }
        else
        {
          v50 = (int)v65;
        }
        if ( v39 != 0 && m_bool == 0 )
          this->m_modifier->vfptr->addTerminalRemoveInfo(
            this->m_modifier,
            v53 + v50 - LODWORD(this->m_code.m_storage->m_data.m_data));
        v42 = result;
        result->m_bool = m_bool != 0 && v39 != 0;
        return v42;
      case 0x24ui64:
      case 0x25ui64:
      case 0x26ui64:
        if ( *((_DWORD *)&query[-2] + (int)v9 - 6) < (int)(unsigned __int8)v11 )
          goto LABEL_49;
        m_primitiveOffset = v12;
        if ( *((_DWORD *)&query[-2] + (int)v9 - 2) >= (int)v12 )
          goto LABEL_49;
        PC += 3;
        continue;
      case 0x27ui64:
      case 0x28ui64:
      case 0x29ui64:
        if ( *((_DWORD *)&this[-1] + (int)v9 - 5) < v10 + ((v12 + ((unsigned __int8)v11 << 8)) << 8) )
          goto LABEL_49;
        m_primitiveOffset = *((unsigned __int8 *)PC + 6);
        if ( *((_DWORD *)&this[-1] + (int)v9 - 1) > (signed int)(m_primitiveOffset
                                                               + ((*((unsigned __int8 *)PC + 5)
                                                                 + (*((unsigned __int8 *)PC + 4) << 8)) << 8)) )
          goto LABEL_49;
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
        v51 = v9 - 48;
        goto $add_Terminal_12;
      case 0x4Eui64:
        v51 = (unsigned __int8)v11;
        goto $add_Terminal_12;
      case 0x4Fui64:
        v51 = v12 + ((unsigned __int8)v11 << 8);
        goto $add_Terminal_12;
      case 0x50ui64:
        v51 = v10 + ((v12 + ((unsigned __int8)v11 << 8)) << 8);
        goto $add_Terminal_12;
      case 0x51ui64:
        v51 = *((unsigned __int8 *)PC + 4) + ((v10 + ((v12 + ((unsigned __int8)v11 << 8)) << 8)) << 8);
$add_Terminal_12:
        this->m_tempLastShouldTerminalBeRemoved.m_bool = this->m_modifier->vfptr->shouldTerminalBeRemoved(
                                                           this->m_modifier,
                                                           &v65,
                                                           (v51 + query->m_primitiveOffset) | this->m_reindexingMask.m_storage & (chunkOffset >> 9 << 8),
                                                           query->m_properties)->m_bool;
$end_of_function_12:
        result->m_bool = (char)this->m_tempLastShouldTerminalBeRemoved;
        return result;
      case 0x5Eui64:
      case 0x5Fui64:
      case 0x60ui64:
      case 0x61ui64:
        PC = v58;
        *((_DWORD *)&v62 + (unsigned int)(v9 - 96) + 1) = (unsigned __int8)v11;
        goto $propertyCopy_12;
      case 0x62ui64:
      case 0x63ui64:
      case 0x64ui64:
      case 0x65ui64:
        v18 = v12 + ((unsigned __int8)v11 << 8);
        v19 = (unsigned int)(v9 - 100);
        PC += 3;
        goto LABEL_28;
      case 0x66ui64:
      case 0x67ui64:
      case 0x68ui64:
      case 0x69ui64:
        v18 = *((unsigned __int8 *)PC + 4) + ((unsigned __int8)v11 << 24) + (v12 << 16) + (v10 << 8);
        v19 = (unsigned int)(v9 - 104);
        PC += 5;
LABEL_28:
        *((_DWORD *)&v62 + v19 + 1) = v18;
$propertyCopy_12:
        m_primitiveOffset = DWORD1(v62);
        if ( query != (hkpMoppObbVirtualMachineQuery *)&v59 )
        {
          v59 = *(_OWORD *)&query->m_xHi;
          v60 = *(_OWORD *)&query->m_xLo;
          v61 = *(_OWORD *)&query->m_offset_x;
          v20 = *(_OWORD *)&query->m_shift;
          query = (hkpMoppObbVirtualMachineQuery *)&v59;
          v62 = v20;
        }
        DWORD1(v62) = m_primitiveOffset;
        continue;
      case 0x6Eui64:
        m_primitiveOffset = (__int64)this->m_code.m_storage;
        chunkOffset = *((unsigned __int8 *)PC + 4) + ((v10 + ((v12 + ((unsigned __int8)v11 << 8)) << 8)) << 8);
        PC = (const char *)(*(_QWORD *)(m_primitiveOffset + 32) + chunkOffset);
        continue;
      default:
        __debugbreak();
        continue;
    }
  }
}kpMoppObbVirtualMach

// File Line: 313
// RVA: 0xDF7260
void __fastcall hkpMoppModifyVirtualMachine::queryAabb(
        hkpMoppModifyVirtualMachine *this,
        hkpMoppCode *code,
        hkAabb *aabb,
        hkpMoppModifier *modifierOut)
{
  int v8; // ebx
  float v9; // xmm2_4
  float v10; // xmm1_4
  int v11; // r10d
  int v12; // r9d
  float v13; // xmm1_4
  int v14; // r8d
  int v15; // edx
  float v16; // xmm1_4
  float v17; // xmm0_4
  int v18; // ecx
  int v19; // eax
  char *m_data; // r9
  hkBool result; // [rsp+30h] [rbp-50h] BYREF
  float v22; // [rsp+38h] [rbp-48h]
  hkpMoppObbVirtualMachineQuery query; // [rsp+40h] [rbp-40h] BYREF

  if ( HK_flyingcolors_mopp_5.m_bool
    || (hkpCheckKeycode(), hkpProcessFlyingColors(&HK_flyingcolors_mopp_5), HK_flyingcolors_mopp_5.m_bool) )
  {
    this->m_code.m_storage = code;
    this->m_modifier = modifierOut;
    v8 = 0;
    this->m_primitives_out = 0i64;
    v9 = code->m_info.m_offset.m_quad.m128_f32[3];
    v10 = code->m_info.m_offset.m_quad.m128_f32[0];
    v22 = (float)(aabb->m_min.m_quad.m128_f32[0] - v10) * v9;
    v11 = (int)v22 - 1;
    this->m_xLo = v11;
    v22 = (float)(aabb->m_max.m_quad.m128_f32[0] - v10) * v9;
    v12 = (int)v22 + 1;
    this->m_xHi = v12;
    v13 = code->m_info.m_offset.m_quad.m128_f32[1];
    v22 = (float)(aabb->m_min.m_quad.m128_f32[1] - v13) * v9;
    v14 = (int)v22 - 1;
    this->m_yLo = v14;
    v22 = (float)(aabb->m_max.m_quad.m128_f32[1] - v13) * v9;
    v15 = (int)v22 + 1;
    this->m_yHi = v15;
    v16 = code->m_info.m_offset.m_quad.m128_f32[2];
    v17 = aabb->m_min.m_quad.m128_f32[2];
    query.m_xLo = v11 >> 16;
    query.m_xHi = (v12 >> 16) + 1;
    query.m_yLo = v14 >> 16;
    query.m_yHi = (v15 >> 16) + 1;
    memset(&query.m_offset_x, 0, 24);
    v22 = (float)(v17 - v16) * v9;
    v18 = (int)v22 - 1;
    this->m_zLo = v18;
    query.m_zLo = v18 >> 16;
    v22 = (float)(aabb->m_max.m_quad.m128_f32[2] - v16) * v9;
    v19 = (int)v22 + 1;
    this->m_zHi = v19;
    query.m_zHi = (v19 >> 16) + 1;
    m_data = code->m_data.m_data;
    this->m_reindexingMask.m_storage = (*m_data != 13) - 1;
    hkpMoppModifyVirtualMachine::queryModicationPointsRecursive(this, &result, &query, m_data, 0);
    if ( result.m_bool )
    {
      if ( *this->m_code.m_storage->m_data.m_data == 13 )
        v8 = 5;
      modifierOut->vfptr->addTerminalRemoveInfo(modifierOut, v8);
    }
  }
}

