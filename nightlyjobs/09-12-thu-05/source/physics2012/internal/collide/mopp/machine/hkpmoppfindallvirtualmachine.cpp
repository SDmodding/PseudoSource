// File Line: 23
// RVA: 0xDF53A0
void __fastcall hkpMoppFindAllVirtualMachine::queryOnTree(hkpMoppFindAllVirtualMachine *this, hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *query, const char *PC)
{
  const char *v3; // rdi
  __int64 *v4; // rsi
  hkpMoppFindAllVirtualMachine *v5; // r11
  int v6; // ebx
  unsigned __int8 v7; // r10
  unsigned __int8 v8; // r8
  unsigned __int8 v9; // bp
  const char *v10; // rdi
  const char *v11; // rdi
  int v12; // eax
  int v13; // ebx
  signed __int64 v14; // rdi
  unsigned int v15; // ebx
  __int64 v16; // rax
  __int64 v17; // rax
  int v18; // ecx
  __int64 v19; // rax
  int v20; // edx
  __int64 v21; // rax
  int v22; // ecx
  __int64 v23; // rax
  int v24; // ebx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *v25; // rdi
  int v26; // ebx
  __int64 v27; // r8
  int *v28; // rdx
  __int64 v29; // [rsp+20h] [rbp-28h]
  hkpMoppFindAllVirtualMachine *v30; // [rsp+50h] [rbp+8h]
  unsigned __int8 v31; // [rsp+60h] [rbp+18h]

  v30 = this;
  v3 = PC;
  v4 = (__int64 *)query;
  v5 = this;
  while ( 1 )
  {
    v6 = *(unsigned __int8 *)v3;
    v7 = v3[3];
    v8 = v3[1];
    v9 = v3[2];
    v31 = v3[3];
    switch ( v6 )
    {
      case 0:
        return;
      case 1:
      case 2:
      case 3:
      case 4:
        v3 += 4;
        continue;
      case 5:
        v3 += v8 + 2;
        continue;
      case 6:
        v3 += 256 * v8 + v9 + 3;
        continue;
      case 7:
        v3 += 0x10000 * v8 + 256 * v9 + (unsigned int)v7 + 4;
        continue;
      case 8:
        v3 += 0x1000000 * v8 + 256 * (v7 + (v9 << 8)) + (unsigned int)*((unsigned __int8 *)v3 + 4) + 5;
        continue;
      case 9:
        if ( v4 != &v29 )
        {
          v16 = *v4;
          v4 = &v29;
          v29 = v16;
        }
        LODWORD(v29) = v8 + (_DWORD)v29;
        v3 += 2;
        continue;
      case 10:
        if ( v4 != &v29 )
        {
          v17 = *v4;
          v4 = &v29;
          v29 = v17;
        }
        LODWORD(v29) = v9 + (v8 << 8) + v29;
        goto $LN30_45;
      case 11:
        v18 = *((unsigned __int8 *)v3 + 4) + (v8 << 24) + (v9 << 16) + (v7 << 8);
        if ( v4 != &v29 )
        {
          v19 = *v4;
          v4 = &v29;
          v29 = v19;
        }
        LODWORD(v29) = v18;
        v3 += 5;
        continue;
      case 16:
      case 17:
      case 18:
      case 19:
      case 20:
      case 21:
      case 22:
      case 23:
      case 24:
      case 25:
      case 26:
      case 27:
      case 28:
        v10 = v3 + 4;
        hkpMoppFindAllVirtualMachine::queryOnTree(
          v5,
          (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v4,
          v10);
        v5 = v30;
        v3 = &v10[v31];
        continue;
      case 32:
      case 33:
      case 34:
        v11 = v3 + 3;
        hkpMoppFindAllVirtualMachine::queryOnTree(
          v5,
          (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v4,
          v11);
        v5 = v30;
        v3 = &v11[v9];
        continue;
      case 35:
      case 36:
      case 37:
        v12 = *((unsigned __int8 *)v3 + 4);
        v13 = *((unsigned __int8 *)v3 + 5);
        v14 = (signed __int64)(v3 + 7);
        v15 = *(unsigned __int8 *)(v14 - 1) + (v13 << 8);
        hkpMoppFindAllVirtualMachine::queryOnTree(
          v5,
          (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v4,
          (const char *)(v14 + v12 + ((unsigned int)v7 << 8)));
        v5 = v30;
        v3 = (const char *)(v15 + v14);
        continue;
      case 38:
      case 39:
      case 40:
$LN30_45:
        v3 += 3;
        continue;
      case 41:
      case 42:
      case 43:
        v3 += 7;
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
        v24 = v6 - 48;
        goto $add_Terminal_7;
      case 80:
        v24 = v8;
        goto $add_Terminal_7;
      case 81:
        v24 = v9 + (v8 << 8);
        goto $add_Terminal_7;
      case 82:
        v24 = v7 + ((v9 + (v8 << 8)) << 8);
        goto $add_Terminal_7;
      case 83:
        v24 = (v7 << 8) + ((v9 + (v8 << 8)) << 16) + *((unsigned __int8 *)v3 + 4);
$add_Terminal_7:
        v25 = v5->m_primitives_out;
        v26 = *(_DWORD *)v4 + v24;
        if ( v5->m_primitives_out->m_size == (v5->m_primitives_out->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
            v5->m_primitives_out,
            4);
        v27 = v25->m_size;
        v28 = (int *)&v25->m_data[v27];
        v25->m_size = v27 + 1;
        *v28 = v26;
        return;
      case 96:
      case 97:
      case 98:
      case 99:
        v3 += 2;
        *((_DWORD *)&v29 + (unsigned int)(v6 - 96) + 1) = v8;
        goto $propertyCopy_7;
      case 100:
      case 101:
      case 102:
      case 103:
        v3 += 3;
        v20 = v9 + (v8 << 8);
        v21 = (unsigned int)(v6 - 100);
        goto LABEL_25;
      case 104:
      case 105:
      case 106:
      case 107:
        v20 = *((unsigned __int8 *)v3 + 4) + (v8 << 24) + (v9 << 16) + (v7 << 8);
        v21 = (unsigned int)(v6 - 104);
        v3 += 5;
LABEL_25:
        *((_DWORD *)&v29 + v21 + 1) = v20;
$propertyCopy_7:
        v22 = HIDWORD(v29);
        if ( v4 != &v29 )
        {
          v23 = *v4;
          v4 = &v29;
          v29 = v23;
        }
        HIDWORD(v29) = v22;
        break;
      default:
        __debugbreak();
        break;
    }
  }
}

// File Line: 125
// RVA: 0xDF5B10
hkpMoppFindAllVirtualMachine::queryOnTreeRight

// File Line: 223
// RVA: 0xDF5790
hkpMoppFindAllVirtualMachine::queryOnTreeLeft

