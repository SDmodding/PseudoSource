// File Line: 23
// RVA: 0xDF53A0
void __fastcall hkpMoppFindAllVirtualMachine::queryOnTree(
        hkpMoppFindAllVirtualMachine *this,
        hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *query,
        const char *PC)
{
  hkpMoppFindAllVirtualMachine *v5; // r11
  int v6; // ebx
  unsigned __int8 v7; // r10
  unsigned __int8 v8; // r8
  unsigned __int8 v9; // bp
  const char *v10; // rdi
  const char *v11; // rdi
  int v12; // eax
  int v13; // ebx
  const char *v14; // rdi
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
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *m_primitives_out; // rdi
  unsigned int v26; // ebx
  __int64 m_size; // r8
  hkpMoppPrimitiveInfo *v28; // rdx
  __int64 v29[5]; // [rsp+20h] [rbp-28h] BYREF
  unsigned __int8 v31; // [rsp+60h] [rbp+18h]

  v5 = this;
  while ( 1 )
  {
    v6 = *(unsigned __int8 *)PC;
    v7 = PC[3];
    v8 = PC[1];
    v9 = PC[2];
    v31 = v7;
    switch ( *PC )
    {
      case 0:
        return;
      case 1:
      case 2:
      case 3:
      case 4:
        PC += 4;
        continue;
      case 5:
        PC += v8 + 2;
        continue;
      case 6:
        PC += 256 * v8 + v9 + 3;
        continue;
      case 7:
        PC += 0x10000 * v8 + 256 * v9 + (unsigned int)v7 + 4;
        continue;
      case 8:
        PC += 0x1000000 * v8 + 256 * (v7 + (v9 << 8)) + (unsigned int)*((unsigned __int8 *)PC + 4) + 5;
        continue;
      case 9:
        if ( query != (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v29 )
        {
          v16 = (__int64)*query;
          query = (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v29;
          v29[0] = v16;
        }
        LODWORD(v29[0]) += v8;
        PC += 2;
        continue;
      case 0xA:
        if ( query != (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v29 )
        {
          v17 = (__int64)*query;
          query = (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v29;
          v29[0] = v17;
        }
        LODWORD(v29[0]) += v9 + (v8 << 8);
        goto $LN30_45;
      case 0xB:
        v18 = *((unsigned __int8 *)PC + 4) + (v8 << 24) + (v9 << 16) + (v7 << 8);
        if ( query != (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v29 )
        {
          v19 = (__int64)*query;
          query = (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v29;
          v29[0] = v19;
        }
        LODWORD(v29[0]) = v18;
        PC += 5;
        continue;
      case 0x10:
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1A:
      case 0x1B:
      case 0x1C:
        v10 = PC + 4;
        hkpMoppFindAllVirtualMachine::queryOnTree(v5, query, v10);
        v5 = this;
        PC = &v10[v31];
        continue;
      case 0x20:
      case 0x21:
      case 0x22:
        v11 = PC + 3;
        hkpMoppFindAllVirtualMachine::queryOnTree(v5, query, v11);
        v5 = this;
        PC = &v11[v9];
        continue;
      case 0x23:
      case 0x24:
      case 0x25:
        v12 = *((unsigned __int8 *)PC + 4);
        v13 = *((unsigned __int8 *)PC + 5);
        v14 = PC + 7;
        v15 = *((unsigned __int8 *)v14 - 1) + (v13 << 8);
        hkpMoppFindAllVirtualMachine::queryOnTree(v5, query, &v14[256 * v7 + v12]);
        v5 = this;
        PC = &v14[v15];
        continue;
      case 0x26:
      case 0x27:
      case 0x28:
$LN30_45:
        PC += 3;
        continue;
      case 0x29:
      case 0x2A:
      case 0x2B:
        PC += 7;
        continue;
      case 0x30:
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
      case 0x37:
      case 0x38:
      case 0x39:
      case 0x3A:
      case 0x3B:
      case 0x3C:
      case 0x3D:
      case 0x3E:
      case 0x3F:
      case 0x40:
      case 0x41:
      case 0x42:
      case 0x43:
      case 0x44:
      case 0x45:
      case 0x46:
      case 0x47:
      case 0x48:
      case 0x49:
      case 0x4A:
      case 0x4B:
      case 0x4C:
      case 0x4D:
      case 0x4E:
      case 0x4F:
        v24 = v6 - 48;
        goto $add_Terminal_7;
      case 0x50:
        v24 = v8;
        goto $add_Terminal_7;
      case 0x51:
        v24 = v9 + (v8 << 8);
        goto $add_Terminal_7;
      case 0x52:
        v24 = v7 + ((v9 + (v8 << 8)) << 8);
        goto $add_Terminal_7;
      case 0x53:
        v24 = (v7 << 8) + ((v9 + (v8 << 8)) << 16) + *((unsigned __int8 *)PC + 4);
$add_Terminal_7:
        m_primitives_out = v5->m_primitives_out;
        v26 = query->m_primitiveOffset + v24;
        if ( v5->m_primitives_out->m_size == (v5->m_primitives_out->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v5->m_primitives_out->m_data, 4);
        m_size = m_primitives_out->m_size;
        v28 = &m_primitives_out->m_data[m_size];
        m_primitives_out->m_size = m_size + 1;
        v28->ID = v26;
        return;
      case 0x60:
      case 0x61:
      case 0x62:
      case 0x63:
        PC += 2;
        *((_DWORD *)v29 + (unsigned int)(v6 - 96) + 1) = v8;
        goto $propertyCopy_7;
      case 0x64:
      case 0x65:
      case 0x66:
      case 0x67:
        PC += 3;
        v20 = v9 + (v8 << 8);
        v21 = (unsigned int)(v6 - 100);
        goto LABEL_25;
      case 0x68:
      case 0x69:
      case 0x6A:
      case 0x6B:
        v20 = *((unsigned __int8 *)PC + 4) + (v8 << 24) + (v9 << 16) + (v7 << 8);
        v21 = (unsigned int)(v6 - 104);
        PC += 5;
LABEL_25:
        *((_DWORD *)v29 + v21 + 1) = v20;
$propertyCopy_7:
        v22 = HIDWORD(v29[0]);
        if ( query != (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v29 )
        {
          v23 = (__int64)*query;
          query = (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v29;
          v29[0] = v23;
        }
        HIDWORD(v29[0]) = v22;
        break;
      default:
        __debugbreak();
        continue;
    }
  }
}

// File Line: 125
// RVA: 0xDF5B10
void __fastcall hkpMoppFindAllVirtualMachine::queryOnTreeRight(
        hkpMoppFindAllVirtualMachine *this,
        hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *query,
        const char *PC)
{
  __int64 v3; // r14
  __int64 v6; // rbx
  unsigned __int8 v7; // r9
  unsigned __int8 v8; // r11
  unsigned __int8 v9; // si
  __int64 v10; // rax
  __int64 v11; // rax
  int v12; // ecx
  __int64 v13; // rax
  int v14; // edx
  __int64 v15; // rax
  int v16; // ecx
  __int64 v17; // rax
  int v18; // ebx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *m_primitives_out; // rdi
  unsigned int v20; // ebx
  __int64 m_size; // r8
  hkpMoppPrimitiveInfo *v22; // rdx
  __int64 v23[3]; // [rsp+20h] [rbp-18h] BYREF

  v23[2] = v3;
  while ( 1 )
  {
    v6 = *(unsigned __int8 *)PC;
    v7 = PC[1];
    v8 = PC[2];
    v9 = PC[3];
    switch ( *((_BYTE *)&off_140DF5DEC[23] + v6) )
    {
      case 0:
        return;
      case 1:
        PC += 4;
        continue;
      case 2:
        PC += v7 + 2;
        continue;
      case 3:
        PC += 256 * v7 + v8 + 3;
        continue;
      case 4:
        PC += 0x10000 * v7 + 256 * v8 + (unsigned int)v9 + 4;
        continue;
      case 5:
        PC += 0x1000000 * v7 + 256 * (v9 + (v8 << 8)) + (unsigned int)*((unsigned __int8 *)PC + 4) + 5;
        continue;
      case 6:
        if ( query != (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v23 )
        {
          v10 = (__int64)*query;
          query = (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v23;
          v23[0] = v10;
        }
        LODWORD(v23[0]) += v7;
        PC += 2;
        continue;
      case 7:
        if ( query != (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v23 )
        {
          v11 = (__int64)*query;
          query = (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v23;
          v23[0] = v11;
        }
        LODWORD(v23[0]) += v8 + (v7 << 8);
        goto $LN30_47;
      case 8:
        v12 = *((unsigned __int8 *)PC + 4) + (v7 << 24) + (v8 << 16) + (v9 << 8);
        if ( query != (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v23 )
        {
          v13 = (__int64)*query;
          query = (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v23;
          v23[0] = v13;
        }
        LODWORD(v23[0]) = v12;
        PC += 5;
        continue;
      case 9:
        PC += v9 + 4;
        continue;
      case 0xA:
        PC += v8 + 3;
        continue;
      case 0xB:
        PC += 256 * *((unsigned __int8 *)PC + 5) + (unsigned int)*((unsigned __int8 *)PC + 6) + 7;
        continue;
      case 0xC:
$LN30_47:
        PC += 3;
        continue;
      case 0xD:
        PC += 7;
        continue;
      case 0xE:
        v18 = v6 - 48;
        goto $add_Terminal_9;
      case 0xF:
        v18 = v7;
        goto $add_Terminal_9;
      case 0x10:
        v18 = v8 + (v7 << 8);
        goto $add_Terminal_9;
      case 0x11:
        v18 = v9 + ((v8 + (v7 << 8)) << 8);
        goto $add_Terminal_9;
      case 0x12:
        v18 = (v9 << 8) + ((v8 + (v7 << 8)) << 16) + *((unsigned __int8 *)PC + 4);
$add_Terminal_9:
        m_primitives_out = this->m_primitives_out;
        v20 = query->m_primitiveOffset + v18;
        if ( this->m_primitives_out->m_size == (this->m_primitives_out->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&this->m_primitives_out->m_data,
            4);
        m_size = m_primitives_out->m_size;
        v22 = &m_primitives_out->m_data[m_size];
        m_primitives_out->m_size = m_size + 1;
        v22->ID = v20;
        return;
      case 0x13:
        PC += 2;
        *((_DWORD *)v23 + (unsigned int)(v6 - 96) + 1) = v7;
        goto $propertyCopy_9;
      case 0x14:
        v14 = v8 + (v7 << 8);
        v15 = (unsigned int)(v6 - 100);
        PC += 3;
        goto LABEL_25;
      case 0x15:
        v14 = *((unsigned __int8 *)PC + 4) + (v7 << 24) + (v8 << 16) + (v9 << 8);
        v15 = (unsigned int)(v6 - 104);
        PC += 5;
LABEL_25:
        *((_DWORD *)v23 + v15 + 1) = v14;
$propertyCopy_9:
        v16 = HIDWORD(v23[0]);
        if ( query != (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v23 )
        {
          v17 = (__int64)*query;
          query = (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v23;
          v23[0] = v17;
        }
        HIDWORD(v23[0]) = v16;
        break;
      case 0x17:
        JUMPOUT(0x141010100i64);
      default:
        __debugbreak();
        break;
    }
  }
}

// File Line: 223
// RVA: 0xDF5790
void __fastcall hkpMoppFindAllVirtualMachine::queryOnTreeLeft(
        hkpMoppFindAllVirtualMachine *this,
        hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *query,
        const char *PC)
{
  __int64 v5; // rbx
  unsigned __int8 v6; // r9
  unsigned __int8 v7; // di
  unsigned __int8 v8; // si
  __int64 v9; // rax
  __int64 v10; // rax
  int v11; // ecx
  __int64 v12; // rax
  int v13; // edx
  __int64 v14; // rax
  int v15; // ecx
  __int64 v16; // rax
  int v17; // ebx
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *m_primitives_out; // rdi
  unsigned int v19; // ebx
  __int64 m_size; // r8
  hkpMoppPrimitiveInfo *v21; // rdx
  __int64 v22[3]; // [rsp+20h] [rbp-18h] BYREF

  while ( 1 )
  {
    v5 = *(unsigned __int8 *)PC;
    v6 = PC[1];
    v7 = PC[2];
    v8 = PC[3];
    switch ( *((_BYTE *)&off_140DF5A48[21] + v5) )
    {
      case 0:
        return;
      case 1:
        PC += 4;
        continue;
      case 2:
        PC += v6 + 2;
        continue;
      case 3:
        PC += 256 * v6 + v7 + 3;
        continue;
      case 4:
        PC += 0x10000 * v6 + 256 * v7 + (unsigned int)v8 + 4;
        continue;
      case 5:
        PC += 0x1000000 * v6 + 256 * (v8 + (v7 << 8)) + (unsigned int)*((unsigned __int8 *)PC + 4) + 5;
        continue;
      case 6:
        if ( query != (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v22 )
        {
          v9 = (__int64)*query;
          query = (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v22;
          v22[0] = v9;
        }
        LODWORD(v22[0]) += v6;
        PC += 2;
        continue;
      case 7:
        if ( query != (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v22 )
        {
          v10 = (__int64)*query;
          query = (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v22;
          v22[0] = v10;
        }
        LODWORD(v22[0]) += v7 + (v6 << 8);
        goto $LN30_46;
      case 8:
        v11 = *((unsigned __int8 *)PC + 4) + (v6 << 24) + (v7 << 16) + (v8 << 8);
        if ( query != (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v22 )
        {
          v12 = (__int64)*query;
          query = (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v22;
          v22[0] = v12;
        }
        LODWORD(v22[0]) = v11;
        PC += 5;
        continue;
      case 9:
$LN30_46:
        PC += 3;
        continue;
      case 0xA:
        PC += 256 * v8 + (unsigned int)*((unsigned __int8 *)PC + 4) + 7;
        continue;
      case 0xB:
        PC += 7;
        continue;
      case 0xC:
        v17 = v5 - 48;
        goto $add_Terminal_8;
      case 0xD:
        v17 = v6;
        goto $add_Terminal_8;
      case 0xE:
        v17 = v7 + (v6 << 8);
        goto $add_Terminal_8;
      case 0xF:
        v17 = v8 + ((v7 + (v6 << 8)) << 8);
        goto $add_Terminal_8;
      case 0x10:
        v17 = (v8 << 8) + ((v7 + (v6 << 8)) << 16) + *((unsigned __int8 *)PC + 4);
$add_Terminal_8:
        m_primitives_out = this->m_primitives_out;
        v19 = query->m_primitiveOffset + v17;
        if ( this->m_primitives_out->m_size == (this->m_primitives_out->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(
            &hkContainerHeapAllocator::s_alloc,
            (const void **)&this->m_primitives_out->m_data,
            4);
        m_size = m_primitives_out->m_size;
        v21 = &m_primitives_out->m_data[m_size];
        m_primitives_out->m_size = m_size + 1;
        v21->ID = v19;
        return;
      case 0x11:
        PC += 2;
        *((_DWORD *)v22 + (unsigned int)(v5 - 96) + 1) = v6;
        goto $propertyCopy_8;
      case 0x12:
        v13 = v7 + (v6 << 8);
        v14 = (unsigned int)(v5 - 100);
        PC += 3;
        goto LABEL_22;
      case 0x13:
        v13 = *((unsigned __int8 *)PC + 4) + (v6 << 24) + (v7 << 16) + (v8 << 8);
        v14 = (unsigned int)(v5 - 104);
        PC += 5;
LABEL_22:
        *((_DWORD *)v22 + v14 + 1) = v13;
$propertyCopy_8:
        v15 = HIDWORD(v22[0]);
        if ( query != (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v22 )
        {
          v16 = (__int64)*query;
          query = (hkpMoppFindAllVirtualMachine::hkpMoppFindAllVirtualMachineQuery *)v22;
          v22[0] = v16;
        }
        HIDWORD(v22[0]) = v15;
        break;
      case 0x15:
        JUMPOUT(0x141010100i64);
      default:
        __debugbreak();
        break;
    }
  }
}

