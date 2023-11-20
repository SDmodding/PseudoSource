// File Line: 51
// RVA: 0xDF7460
hkBool *__usercall hkpMoppModifyVirtualMachine::queryModicationPointsRecursive@<rax>(hkpMoppModifyVirtualMachine *this@<rcx>, hkBool *result@<rdx>, hkpMoppObbVirtualMachineQuery *query@<r8>, const char *PC@<r9>, signed __int64 a5@<rax>, int chunkOffset)
{
  const char *v6; // r11
  hkpMoppObbVirtualMachineQuery *v7; // rsi
  hkpMoppModifyVirtualMachine *v8; // rdi
  __int64 v9; // rbx
  unsigned __int8 v10; // dl
  int v11; // er8
  unsigned __int8 v12; // r9
  int v13; // eax
  __int128 v14; // xmm1
  __int128 v15; // xmm1
  int v16; // ecx
  __int128 v17; // xmm1
  int v18; // edx
  __int64 v19; // rax
  __int128 v20; // xmm1
  int v21; // ecx
  int v22; // edx
  int v23; // er10
  int v24; // er10
  unsigned int v25; // eax
  __int64 v26; // r9
  signed __int64 v27; // r11
  int v28; // eax
  int v29; // er10
  int v30; // eax
  int v31; // er10
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  signed __int64 v36; // r11
  int v37; // ebx
  __int64 v38; // rbx
  __int64 v39; // rdi
  hkpMoppObbVirtualMachineQuery *v40; // r8
  hkpMoppModifyVirtualMachine *v41; // rsi
  hkBool *v42; // rax
  hkpMoppObbVirtualMachineQuery *v43; // r8
  hkBool *v44; // rdx
  const char *v45; // r9
  int v46; // edi
  hkBool *v47; // rax
  hkpMoppModifier *v48; // rcx
  hkpMoppCode *v49; // rax
  int v50; // esi
  int v51; // ecx
  int v52; // [rsp+20h] [rbp-60h]
  unsigned int v53; // [rsp+30h] [rbp-50h]
  hkBool v54; // [rsp+34h] [rbp-4Ch]
  char v55; // [rsp+35h] [rbp-4Bh]
  hkBool v56; // [rsp+36h] [rbp-4Ah]
  hkBool resulta; // [rsp+37h] [rbp-49h]
  const char *v58; // [rsp+38h] [rbp-48h]
  __int128 v59; // [rsp+40h] [rbp-40h]
  __int128 v60; // [rsp+50h] [rbp-30h]
  __int128 v61; // [rsp+60h] [rbp-20h]
  __int128 v62; // [rsp+70h] [rbp-10h]
  hkpMoppModifyVirtualMachine *v63; // [rsp+A0h] [rbp+20h]
  hkBool *v64; // [rsp+A8h] [rbp+28h]
  __int64 v65; // [rsp+B8h] [rbp+38h]

  v64 = result;
  v63 = this;
  v6 = PC;
  v7 = query;
  v8 = this;
  while ( 2 )
  {
    v9 = *(unsigned __int8 *)v6;
    v10 = v6[3];
    LOBYTE(v11) = v6[1];
    v12 = v6[2];
    LOBYTE(v65) = v6[3];
    v58 = (const char *)a5;
    a5 = 5368709120i64;
    switch ( (unsigned __int64)v6 )
    {
      case 0xFFFFFFFFFFFFFFFEui64:
        goto $end_of_function_12;
      case 0xFFFFFFFFFFFFFFFFui64:
      case 0ui64:
      case 1ui64:
      case 2ui64:
        LODWORD(v61) = ((unsigned __int8)v11 + v7->m_offset_x) << v9;
        DWORD1(v61) = (v12 + v7->m_offset_y) << v9;
        v13 = v8->m_xLo;
        DWORD2(v61) = (v10 + v7->m_offset_z) << v9;
        LODWORD(v62) = v9 + v7->m_shift;
        LODWORD(v60) = (v13 >> (16 - v62)) - v61;
        DWORD1(v60) = (v8->m_yLo >> (16 - v62)) - DWORD1(v61);
        DWORD2(v60) = (v8->m_zLo >> (16 - v62)) - DWORD2(v61);
        LODWORD(v59) = (v8->m_xHi >> (16 - v62)) - v61 + 1;
        DWORD1(v59) = (v8->m_yHi >> (16 - v62)) - DWORD1(v61) + 1;
        v6 += 4;
        DWORD2(v59) = (v8->m_zHi >> (16 - v62)) - DWORD2(v61) + 1;
        DWORD1(v62) = v7->m_properties[0];
        a5 = v7->m_primitiveOffset;
        v7 = (hkpMoppObbVirtualMachineQuery *)&v59;
        HIDWORD(v61) = a5;
        continue;
      case 3ui64:
        a5 = (unsigned __int8)v11;
        v6 += (unsigned __int8)v11 + 2;
        continue;
      case 4ui64:
        a5 = ((unsigned __int8)v11 << 8) + v12;
        v6 += a5 + 3;
        continue;
      case 5ui64:
        a5 = (v12 << 8) + ((unsigned __int8)v11 << 16) + (unsigned int)v10;
        v6 += a5 + 4;
        continue;
      case 6ui64:
        a5 = ((unsigned __int8)v11 << 24)
           + ((v10 + (v12 << 8)) << 8)
           + (unsigned int)*((unsigned __int8 *)v6 + 4)
           + 5i64;
        v6 += a5;
        continue;
      case 7ui64:
        a5 = (unsigned __int8)v11;
        if ( v7 != (hkpMoppObbVirtualMachineQuery *)&v59 )
        {
          v59 = *(_OWORD *)&v7->m_xHi;
          v60 = *(_OWORD *)&v7->m_xLo;
          v61 = *(_OWORD *)&v7->m_offset_x;
          v14 = *(_OWORD *)&v7->m_shift;
          v7 = (hkpMoppObbVirtualMachineQuery *)&v59;
          v62 = v14;
        }
        HIDWORD(v61) += (unsigned __int8)v11;
        v6 = v58;
        continue;
      case 8ui64:
        a5 = (signed __int64)&v59;
        if ( v7 != (hkpMoppObbVirtualMachineQuery *)&v59 )
        {
          v59 = *(_OWORD *)&v7->m_xHi;
          v60 = *(_OWORD *)&v7->m_xLo;
          v61 = *(_OWORD *)&v7->m_offset_x;
          v15 = *(_OWORD *)&v7->m_shift;
          v7 = (hkpMoppObbVirtualMachineQuery *)&v59;
          v62 = v15;
        }
        HIDWORD(v61) += v12 + ((unsigned __int8)v11 << 8);
        v6 += 3;
        continue;
      case 9ui64:
        v16 = *((unsigned __int8 *)v6 + 4) + ((unsigned __int8)v11 << 24) + (v12 << 16) + (v10 << 8);
        a5 = (signed __int64)&v59;
        if ( v7 != (hkpMoppObbVirtualMachineQuery *)&v59 )
        {
          v59 = *(_OWORD *)&v7->m_xHi;
          v60 = *(_OWORD *)&v7->m_xLo;
          v61 = *(_OWORD *)&v7->m_offset_x;
          v17 = *(_OWORD *)&v7->m_shift;
          v7 = (hkpMoppObbVirtualMachineQuery *)&v59;
          v62 = v17;
        }
        HIDWORD(v61) = v16;
        goto $LN28_68;
      case 0xAui64:
        a5 = (signed __int64)v8->m_code.m_storage;
        chunkOffset = (v12 | ((unsigned __int8)v11 << 8)) << 9;
        v6 = (const char *)(*(_QWORD *)(a5 + 32) + chunkOffset);
        continue;
      case 0xBui64:
$LN28_68:
        v6 += 5;
        continue;
      case 0xEui64:
      case 0xFui64:
      case 0x10ui64:
        v24 = (unsigned __int8)v11;
        v11 = v12;
        v21 = *((_DWORD *)v7 + (signed int)v9 - 12);
        v22 = *(&v7[-1].m_xHi + (signed int)v9);
        v25 = (unsigned __int8)v65;
        v26 = 0i64;
        v27 = (signed __int64)(v6 + 4);
        v53 = (unsigned __int8)v65;
        goto LABEL_47;
      case 0x11ui64:
        v21 = v7->m_yLo + v7->m_zLo;
        v22 = v7->m_yHi + v7->m_zHi;
        v23 = (unsigned __int8)v11;
        v11 = 2 * v12;
        v24 = 2 * v23;
        v25 = (unsigned __int8)v65;
        v26 = 0i64;
        v27 = (signed __int64)(v6 + 4);
        v53 = (unsigned __int8)v65;
        goto LABEL_47;
      case 0x12ui64:
        v21 = v7->m_yLo - v7->m_zHi;
        v22 = v7->m_yHi - v7->m_zLo;
        v24 = 2 * (unsigned __int8)v11 - 255;
        v28 = v12;
        v26 = 0i64;
        v27 = (signed __int64)(v6 + 4);
        v11 = 2 * v28 - 255;
        v25 = (unsigned __int8)v65;
        v53 = (unsigned __int8)v65;
        goto LABEL_47;
      case 0x13ui64:
        v21 = v7->m_xLo + v7->m_zLo;
        v22 = v7->m_xHi + v7->m_zHi;
        v29 = (unsigned __int8)v11;
        v11 = 2 * v12;
        v24 = 2 * v29;
        v25 = (unsigned __int8)v65;
        v26 = 0i64;
        v27 = (signed __int64)(v6 + 4);
        v53 = (unsigned __int8)v65;
        goto LABEL_47;
      case 0x14ui64:
        v21 = v7->m_xLo - v7->m_zHi;
        v22 = v7->m_xHi - v7->m_zLo;
        v24 = 2 * (unsigned __int8)v11 - 255;
        v30 = v12;
        v26 = 0i64;
        v27 = (signed __int64)(v6 + 4);
        v11 = 2 * v30 - 255;
        v25 = (unsigned __int8)v65;
        v53 = (unsigned __int8)v65;
        goto LABEL_47;
      case 0x15ui64:
        v21 = v7->m_xLo + v7->m_yLo;
        v22 = v7->m_xHi + v7->m_yHi;
        v31 = (unsigned __int8)v11;
        v11 = 2 * v12;
        v24 = 2 * v31;
        v25 = (unsigned __int8)v65;
        v26 = 0i64;
        v27 = (signed __int64)(v6 + 4);
        v53 = (unsigned __int8)v65;
        goto LABEL_47;
      case 0x16ui64:
        v21 = v7->m_xLo - v7->m_yHi;
        v22 = v7->m_xHi - v7->m_yLo;
        v24 = 2 * (unsigned __int8)v11 - 255;
        v32 = v12;
        v26 = 0i64;
        v27 = (signed __int64)(v6 + 4);
        v11 = 2 * v32 - 255;
        v25 = (unsigned __int8)v65;
        v53 = (unsigned __int8)v65;
        goto LABEL_47;
      case 0x17ui64:
        v24 = 3 * (unsigned __int8)v11;
        v21 = v7->m_xLo + v7->m_yLo + v7->m_zLo;
        v22 = v7->m_xHi + v7->m_yHi + v7->m_zHi;
        v11 = 3 * v12;
        v26 = 0i64;
        v25 = (unsigned __int8)v65;
        v27 = (signed __int64)(v6 + 4);
        v53 = (unsigned __int8)v65;
        goto LABEL_47;
      case 0x18ui64:
        v21 = v7->m_xLo + v7->m_yLo - v7->m_zHi;
        v22 = v7->m_xHi + v7->m_yHi - v7->m_zLo;
        v24 = 3 * ((unsigned __int8)v11 - 85);
        v33 = v12;
        v26 = 0i64;
        v27 = (signed __int64)(v6 + 4);
        v11 = 3 * (v33 - 85);
        v25 = (unsigned __int8)v65;
        v53 = (unsigned __int8)v65;
        goto LABEL_47;
      case 0x19ui64:
        v21 = v7->m_xLo + v7->m_zLo - v7->m_yHi;
        v22 = v7->m_xHi + v7->m_zHi - v7->m_yLo;
        v24 = 3 * ((unsigned __int8)v11 - 85);
        v34 = v12;
        v26 = 0i64;
        v27 = (signed __int64)(v6 + 4);
        v11 = 3 * (v34 - 85);
        v25 = (unsigned __int8)v65;
        v53 = (unsigned __int8)v65;
        goto LABEL_47;
      case 0x1Aui64:
        v21 = v7->m_xLo - v7->m_zHi - v7->m_yHi;
        v22 = v7->m_xHi - v7->m_zLo - v7->m_yLo;
        v24 = 3 * ((unsigned __int8)v11 - 170);
        v35 = v12;
        v26 = 0i64;
        v27 = (signed __int64)(v6 + 4);
        v11 = 3 * (v35 - 170);
        v25 = (unsigned __int8)v65;
        v53 = (unsigned __int8)v65;
        goto LABEL_47;
      case 0x1Eui64:
      case 0x1Fui64:
      case 0x20ui64:
        v36 = (signed __int64)(v6 - 1);
        v11 = (unsigned __int8)v11;
        v21 = *((_DWORD *)&v7[-1] + (signed int)v9 - 12);
        v22 = *(&v7[-2].m_xHi + (signed int)v9);
        v25 = *(unsigned __int8 *)(v36 + 3);
        v26 = 0i64;
        v24 = (unsigned __int8)v11 + 1;
        v53 = *(unsigned __int8 *)(v36 + 3);
        v27 = v36 + 4;
        goto LABEL_47;
      case 0x21ui64:
      case 0x22ui64:
      case 0x23ui64:
        v21 = *((_DWORD *)&v7[-1] + v9 - 15);
        v22 = *((_DWORD *)&v7[-2] + v9 - 3);
        v24 = (unsigned __int8)v11;
        v11 = v12;
        v26 = *((unsigned __int8 *)v6 + 4) + ((unsigned int)(unsigned __int8)v65 << 8);
        v37 = *((unsigned __int8 *)v6 + 6) + (*((unsigned __int8 *)v6 + 5) << 8);
        v27 = (signed __int64)(v6 + 7);
        v53 = v37;
        v25 = v37;
LABEL_47:
        LOBYTE(v38) = 0;
        LOBYTE(v39) = 0;
        v65 = v27;
        LODWORD(v58) = v26;
        if ( v22 > v11 )
        {
          v43 = v7;
          if ( v21 < v24 )
          {
            v46 = chunkOffset;
            v47 = hkpMoppModifyVirtualMachine::queryModicationPointsRecursive(
                    v63,
                    &v56,
                    v7,
                    (const char *)(v27 + v26),
                    chunkOffset);
            v52 = v46;
            v45 = (const char *)(v65 + v53);
            LOBYTE(v38) = (hkBool)v47->m_bool;
            v43 = v7;
            v44 = &v54;
          }
          else
          {
            v44 = (hkBool *)&v55;
            v52 = chunkOffset;
            v45 = (const char *)(v27 + v25);
          }
          v41 = v63;
          v39 = (unsigned __int8)hkpMoppModifyVirtualMachine::queryModicationPointsRecursive(v63, v44, v43, v45, v52)->m_bool;
        }
        else
        {
          if ( v21 >= v24 )
          {
LABEL_50:
            v42 = v64;
            v64->m_bool = 0;
            return v42;
          }
          v40 = v7;
          v41 = v63;
          v38 = (unsigned __int8)hkpMoppModifyVirtualMachine::queryModicationPointsRecursive(
                                   v63,
                                   &resulta,
                                   v40,
                                   (const char *)(v27 + v26),
                                   chunkOffset)->m_bool;
        }
        if ( (_BYTE)v39 == 0 && (_BYTE)v38 != 0 )
        {
          v48 = v41->m_modifier;
          v49 = v41->m_code.m_storage;
          v50 = v65;
          v48->vfptr->addTerminalRemoveInfo(v48, (_DWORD)v58 + v65 - LODWORD(v49->m_data.m_data));
        }
        else
        {
          v50 = v65;
        }
        if ( (_BYTE)v39 != 0 && (_BYTE)v38 == 0 )
          v63->m_modifier->vfptr->addTerminalRemoveInfo(
            v63->m_modifier,
            v53 + v50 - LODWORD(v63->m_code.m_storage->m_data.m_data));
        v42 = v64;
        v64->m_bool = (_BYTE)v38 != 0 && (_BYTE)v39 != 0;
        return v42;
      case 0x24ui64:
      case 0x25ui64:
      case 0x26ui64:
        if ( *((_DWORD *)&v7[-2] + (signed int)v9 - 6) < (signed int)(unsigned __int8)v11 )
          goto LABEL_50;
        a5 = v12;
        if ( *((_DWORD *)&v7[-2] + (signed int)v9 - 2) >= (signed int)v12 )
          goto LABEL_50;
        v6 += 3;
        continue;
      case 0x27ui64:
      case 0x28ui64:
      case 0x29ui64:
        if ( *((_DWORD *)&v8[-1] + (signed int)v9 - 5) < v10 + ((v12 + ((unsigned __int8)v11 << 8)) << 8) )
          goto LABEL_50;
        a5 = *((unsigned __int8 *)v6 + 6);
        if ( *((_DWORD *)&v8[-1] + (signed int)v9 - 1) > (signed int)(a5
                                                                    + ((*((unsigned __int8 *)v6 + 5)
                                                                      + (*((unsigned __int8 *)v6 + 4) << 8)) << 8)) )
          goto LABEL_50;
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
        v51 = *((unsigned __int8 *)v6 + 4) + ((v10 + ((v12 + ((unsigned __int8)v11 << 8)) << 8)) << 8);
$add_Terminal_12:
        v8->m_tempLastShouldTerminalBeRemoved.m_bool = *(_BYTE *)v8->m_modifier->vfptr->shouldTerminalBeRemoved(
                                                                   v8->m_modifier,
                                                                   (hkBool *)&v65,
                                                                   (v51 + v7->m_primitiveOffset) | v8->m_reindexingMask.m_storage & (chunkOffset >> 9 << 8),
                                                                   v7->m_properties);
$end_of_function_12:
        v64->m_bool = (char)v8->m_tempLastShouldTerminalBeRemoved;
        return v64;
      case 0x5Eui64:
      case 0x5Fui64:
      case 0x60ui64:
      case 0x61ui64:
        v6 = v58;
        *((_DWORD *)&v62 + (unsigned int)(v9 - 96) + 1) = (unsigned __int8)v11;
        goto $propertyCopy_12;
      case 0x62ui64:
      case 0x63ui64:
      case 0x64ui64:
      case 0x65ui64:
        v18 = v12 + ((unsigned __int8)v11 << 8);
        v19 = (unsigned int)(v9 - 100);
        v6 += 3;
        goto LABEL_29;
      case 0x66ui64:
      case 0x67ui64:
      case 0x68ui64:
      case 0x69ui64:
        v18 = *((unsigned __int8 *)v6 + 4) + ((unsigned __int8)v11 << 24) + (v12 << 16) + (v10 << 8);
        v19 = (unsigned int)(v9 - 104);
        v6 += 5;
LABEL_29:
        *((_DWORD *)&v62 + v19 + 1) = v18;
$propertyCopy_12:
        a5 = DWORD1(v62);
        if ( v7 != (hkpMoppObbVirtualMachineQuery *)&v59 )
        {
          v59 = *(_OWORD *)&v7->m_xHi;
          v60 = *(_OWORD *)&v7->m_xLo;
          v61 = *(_OWORD *)&v7->m_offset_x;
          v20 = *(_OWORD *)&v7->m_shift;
          v7 = (hkpMoppObbVirtualMachineQuery *)&v59;
          v62 = v20;
        }
        DWORD1(v62) = a5;
        continue;
      case 0x6Eui64:
        a5 = (signed __int64)v8->m_code.m_storage;
        chunkOffset = *((unsigned __int8 *)v6 + 4) + ((v10 + ((v12 + ((unsigned __int8)v11 << 8)) << 8)) << 8);
        v6 = (const char *)(*(_QWORD *)(a5 + 32) + chunkOffset);
        continue;
      default:
        __debugbreak();
        continue;
    }
  }
}

// File Line: 313
// RVA: 0xDF7260
void __fastcall hkpMoppModifyVirtualMachine::queryAabb(hkpMoppModifyVirtualMachine *this, hkpMoppCode *code, hkAabb *aabb, hkpMoppModifier *modifierOut)
{
  hkpMoppModifier *v4; // rdi
  hkAabb *v5; // r14
  hkpMoppCode *v6; // r15
  hkpMoppModifyVirtualMachine *v7; // rsi
  unsigned int v8; // ebx
  float v9; // xmm2_4
  float v10; // xmm1_4
  int v11; // er10
  int v12; // er9
  float v13; // xmm1_4
  int v14; // er8
  int v15; // edx
  float v16; // xmm1_4
  float v17; // xmm0_4
  int v18; // ecx
  int v19; // eax
  const char *v20; // r9
  hkBool result; // [rsp+30h] [rbp-50h]
  float v22; // [rsp+38h] [rbp-48h]
  hkpMoppObbVirtualMachineQuery query; // [rsp+40h] [rbp-40h]

  v4 = modifierOut;
  v5 = aabb;
  v6 = code;
  v7 = this;
  if ( HK_flyingcolors_mopp_5.m_bool
    || (hkpCheckKeycode(), hkpProcessFlyingColors(&HK_flyingcolors_mopp_5), HK_flyingcolors_mopp_5.m_bool) )
  {
    v7->m_code.m_storage = v6;
    v7->m_modifier = v4;
    v8 = 0;
    v7->m_primitives_out = 0i64;
    v9 = v6->m_info.m_offset.m_quad.m128_f32[3];
    v10 = v6->m_info.m_offset.m_quad.m128_f32[0];
    v22 = (float)(v5->m_min.m_quad.m128_f32[0] - v10) * v9;
    v11 = (signed int)v22 - 1;
    v7->m_xLo = v11;
    v22 = (float)(v5->m_max.m_quad.m128_f32[0] - v10) * v9;
    v12 = (signed int)v22 + 1;
    v7->m_xHi = v12;
    v13 = v6->m_info.m_offset.m_quad.m128_f32[1];
    v22 = (float)(v5->m_min.m_quad.m128_f32[1] - v13) * v9;
    v14 = (signed int)v22 - 1;
    v7->m_yLo = v14;
    v22 = (float)(v5->m_max.m_quad.m128_f32[1] - v13) * v9;
    v15 = (signed int)v22 + 1;
    v7->m_yHi = v15;
    v16 = v6->m_info.m_offset.m_quad.m128_f32[2];
    v17 = v5->m_min.m_quad.m128_f32[2];
    query.m_xLo = v11 >> 16;
    query.m_xHi = (v12 >> 16) + 1;
    query.m_yLo = v14 >> 16;
    query.m_yHi = (v15 >> 16) + 1;
    *(_QWORD *)&query.m_offset_x = 0i64;
    *(_QWORD *)&query.m_offset_z = 0i64;
    v22 = (float)(v17 - v16) * v9;
    *(_QWORD *)&query.m_shift = 0i64;
    v18 = (signed int)v22 - 1;
    v7->m_zLo = v18;
    query.m_zLo = v18 >> 16;
    v22 = (float)(v5->m_max.m_quad.m128_f32[2] - v16) * v9;
    v19 = (signed int)v22 + 1;
    v7->m_zHi = v19;
    query.m_zHi = (v19 >> 16) + 1;
    v20 = v6->m_data.m_data;
    v7->m_reindexingMask.m_storage = (*v20 != 13) - 1;
    hkpMoppModifyVirtualMachine::queryModicationPointsRecursive(v7, &result, &query, v20, 0);
    if ( result.m_bool )
    {
      if ( *v7->m_code.m_storage->m_data.m_data == 13 )
        v8 = 5;
      v4->vfptr->addTerminalRemoveInfo(v4, v8);
    }
  }
}

