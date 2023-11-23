// File Line: 44
// RVA: 0xDF5FE0
void __fastcall hkpMoppSphereVirtualMachine::querySphereOnTree(
        hkpMoppSphereVirtualMachine *this,
        hkpMoppSphereVirtualMachine::hkpMoppSphereVirtualMachineQuery *query,
        const char *PC)
{
  __int64 v5; // rsi
  unsigned __int8 v6; // r9
  unsigned __int8 v7; // r10
  unsigned __int8 v8; // r11
  int v9; // edx
  int v10; // edx
  int v11; // esi
  int v12; // r9d
  int v13; // r8d
  int v14; // ecx
  int v15; // eax
  int v16; // edx
  int v17; // r9d
  int v18; // r11d
  int v19; // esi
  int v20; // eax
  int v21; // r8d
  const char *v22; // rdi
  unsigned int v23; // edx
  unsigned int v24; // r8d
  int v25; // r11d
  int v26; // edx
  int v27; // r8d
  int v28; // esi
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // ecx
  int v36; // eax
  int v37; // edx
  __int64 v38; // rax
  int v39; // ecx
  int v40; // eax
  int v41; // esi
  unsigned int v42; // esi
  hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *m_primitives_out; // rbx
  __int64 m_size; // r8
  hkpMoppPrimitiveInfo *v45; // rdx
  int m_x; // [rsp+20h] [rbp-30h] BYREF
  int m_y; // [rsp+24h] [rbp-2Ch]
  int m_z; // [rsp+28h] [rbp-28h]
  int m_radius; // [rsp+2Ch] [rbp-24h]
  int m_offset_x; // [rsp+30h] [rbp-20h]
  int m_offset_y; // [rsp+34h] [rbp-1Ch]
  __int64 v52; // [rsp+38h] [rbp-18h]
  int m_shift; // [rsp+40h] [rbp-10h]
  int v54[3]; // [rsp+44h] [rbp-Ch]

  if ( HK_flyingcolors_mopp_3.m_bool
    || (hkpCheckKeycode(), hkpProcessFlyingColors(&HK_flyingcolors_mopp_3), HK_flyingcolors_mopp_3.m_bool) )
  {
    while ( 1 )
    {
      v5 = *(unsigned __int8 *)PC;
      v6 = PC[1];
      v7 = PC[2];
      v8 = PC[3];
      switch ( *PC )
      {
        case 0:
          return;
        case 1:
        case 2:
        case 3:
        case 4:
          m_shift = query->m_shift - v5;
          v29 = this->m_x >> m_shift;
          m_offset_x = (v6 + query->m_offset_x) << v5;
          m_x = v29 - m_offset_x;
          v30 = this->m_y >> m_shift;
          m_offset_y = (v7 + query->m_offset_y) << v5;
          m_y = v30 - m_offset_y;
          v31 = this->m_z >> m_shift;
          LODWORD(v52) = (v8 + query->m_offset_z) << v5;
          m_z = v31 - v52;
          PC += 4;
          m_radius = (this->m_radius >> m_shift) + 1;
          HIDWORD(v52) = query->m_primitiveOffset;
          v32 = query->m_properties[0];
          query = (hkpMoppSphereVirtualMachine::hkpMoppSphereVirtualMachineQuery *)&m_x;
          v54[0] = v32;
          continue;
        case 5:
          PC += v6 + 2;
          continue;
        case 6:
          PC += 256 * v6 + v7 + 3;
          continue;
        case 7:
          PC += 0x10000 * v6 + 256 * v7 + (unsigned int)v8 + 4;
          continue;
        case 8:
          PC += 0x1000000 * v6 + 256 * (v8 + (v7 << 8)) + (unsigned int)*((unsigned __int8 *)PC + 4) + 5;
          continue;
        case 9:
          if ( query != (hkpMoppSphereVirtualMachine::hkpMoppSphereVirtualMachineQuery *)&m_x )
          {
            m_x = query->m_x;
            m_y = query->m_y;
            m_z = query->m_z;
            m_radius = query->m_radius;
            m_offset_x = query->m_offset_x;
            m_offset_y = query->m_offset_y;
            v52 = *(_QWORD *)&query->m_offset_z;
            m_shift = query->m_shift;
            v33 = query->m_properties[0];
            query = (hkpMoppSphereVirtualMachine::hkpMoppSphereVirtualMachineQuery *)&m_x;
            v54[0] = v33;
          }
          PC += 2;
          HIDWORD(v52) += v6;
          continue;
        case 0xA:
          if ( query != (hkpMoppSphereVirtualMachine::hkpMoppSphereVirtualMachineQuery *)&m_x )
          {
            m_x = query->m_x;
            m_y = query->m_y;
            m_z = query->m_z;
            m_radius = query->m_radius;
            m_offset_x = query->m_offset_x;
            m_offset_y = query->m_offset_y;
            v52 = *(_QWORD *)&query->m_offset_z;
            m_shift = query->m_shift;
            v34 = query->m_properties[0];
            query = (hkpMoppSphereVirtualMachine::hkpMoppSphereVirtualMachineQuery *)&m_x;
            v54[0] = v34;
          }
          PC += 3;
          HIDWORD(v52) += v7 + (v6 << 8);
          continue;
        case 0xB:
          v35 = *((unsigned __int8 *)PC + 4) + (v6 << 24) + (v7 << 16) + (v8 << 8);
          if ( query != (hkpMoppSphereVirtualMachine::hkpMoppSphereVirtualMachineQuery *)&m_x )
          {
            m_x = query->m_x;
            m_y = query->m_y;
            m_z = query->m_z;
            m_radius = query->m_radius;
            m_offset_x = query->m_offset_x;
            m_offset_y = query->m_offset_y;
            v52 = *(_QWORD *)&query->m_offset_z;
            m_shift = query->m_shift;
            v36 = query->m_properties[0];
            query = (hkpMoppSphereVirtualMachine::hkpMoppSphereVirtualMachineQuery *)&m_x;
            v54[0] = v36;
          }
          HIDWORD(v52) = v35;
          PC += 5;
          continue;
        case 0x10:
        case 0x11:
        case 0x12:
          v13 = query->m_radius;
          v15 = v6;
          v12 = v7;
          v9 = *((_DWORD *)&query[-1] + *(unsigned __int8 *)PC - 6);
          v11 = v15;
          goto $do_compare_7;
        case 0x13:
          v9 = query->m_y + query->m_z;
          goto LABEL_10;
        case 0x14:
          v9 = query->m_y - query->m_z + 255;
          goto LABEL_10;
        case 0x15:
          v10 = query->m_z;
          goto LABEL_9;
        case 0x16:
          v11 = 2 * v6;
          v12 = 2 * v7;
          v9 = query->m_x - query->m_z + 255;
          v13 = (query->m_radius >> 1) + query->m_radius + 1;
          goto $do_compare_7;
        case 0x17:
          v10 = query->m_y;
LABEL_9:
          v9 = query->m_x + v10;
LABEL_10:
          v11 = 2 * v6;
          v12 = 2 * v7;
          v13 = (query->m_radius >> 1) + query->m_radius + 1;
          goto $do_compare_7;
        case 0x18:
          v11 = 2 * v6;
          v12 = 2 * v7;
          v9 = query->m_x - query->m_y + 255;
          v13 = (query->m_radius >> 1) + query->m_radius + 1;
          goto $do_compare_7;
        case 0x19:
          v9 = query->m_x + query->m_y + query->m_z;
          goto LABEL_16;
        case 0x1A:
          v14 = query->m_y - query->m_z;
          goto LABEL_15;
        case 0x1B:
          v14 = query->m_z - query->m_y;
LABEL_15:
          v9 = v14 + query->m_x + 255;
LABEL_16:
          v11 = 3 * v6;
          v12 = 3 * v7;
          v13 = 4 * query->m_radius;
          goto $do_compare_7;
        case 0x1C:
          v11 = 3 * v6;
          v12 = 3 * v7;
          v9 = query->m_x - query->m_z - query->m_y + 510;
          v13 = 4 * query->m_radius;
$do_compare_7:
          PC += 4;
          if ( v13 + v9 >= v12 )
          {
            PC += v8;
            if ( v9 <= v13 + v11 )
              hkpMoppSphereVirtualMachine::querySphereOnTree(this, query, &PC[-v8]);
          }
          continue;
        case 0x20:
        case 0x21:
        case 0x22:
          v16 = v6;
          v17 = query->m_radius;
          v18 = *((_DWORD *)&query[-3] + *(unsigned __int8 *)PC - 2);
          PC += 3;
          if ( v17 + v18 >= v16 )
          {
            PC += v7;
            if ( v18 <= v17 + v16 + 1 )
              hkpMoppSphereVirtualMachine::querySphereOnTree(this, query, &PC[-v7]);
          }
          continue;
        case 0x23:
        case 0x24:
        case 0x25:
          v19 = *((_DWORD *)&query[-3] + *(unsigned __int8 *)PC - 5);
          v20 = *((unsigned __int8 *)PC + 4);
          v21 = *((unsigned __int8 *)PC + 5) << 8;
          v22 = PC + 7;
          v23 = v20 + (v8 << 8);
          v24 = *((unsigned __int8 *)v22 - 1) + v21;
          if ( v19 + query->m_radius >= v7 )
          {
            PC = &v22[v24];
            if ( v19 <= query->m_radius + v6 )
              hkpMoppSphereVirtualMachine::querySphereOnTree(this, query, &PC[v23 - (unsigned __int64)v24]);
          }
          else
          {
            PC = &v22[v23];
          }
          continue;
        case 0x26:
        case 0x27:
        case 0x28:
          v25 = query->m_radius;
          v26 = *((_DWORD *)&query[-3] + *(unsigned __int8 *)PC - 8);
          if ( v25 + v26 < v6 || v26 > v25 + v7 )
            return;
          PC += 3;
          continue;
        case 0x29:
        case 0x2A:
        case 0x2B:
          v27 = *((_DWORD *)&this[-2] + v5 - 9);
          v28 = this->m_radius;
          if ( v28 + v27 < v8 + ((v7 + (v6 << 8)) << 8)
            || v27 > v28
                   + (((*((unsigned __int8 *)PC + 4) << 8) + *((unsigned __int8 *)PC + 5)) << 8)
                   + *((unsigned __int8 *)PC + 6) )
          {
            return;
          }
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
          v41 = v5 - 48;
          goto $add_Terminal_10;
        case 0x50:
          v41 = v6;
          goto $add_Terminal_10;
        case 0x51:
          v41 = v7 + (v6 << 8);
          goto $add_Terminal_10;
        case 0x52:
          v41 = v8 + ((v7 + (v6 << 8)) << 8);
          goto $add_Terminal_10;
        case 0x53:
          v41 = *((unsigned __int8 *)PC + 4) + ((v8 + ((v7 + (v6 << 8)) << 8)) << 8);
$add_Terminal_10:
          v42 = query->m_primitiveOffset + v41;
          m_primitives_out = this->m_primitives_out;
          if ( this->m_primitives_out->m_size == (this->m_primitives_out->m_capacityAndFlags & 0x3FFFFFFF) )
            hkArrayUtil::_reserveMore(
              &hkContainerHeapAllocator::s_alloc,
              (const void **)&this->m_primitives_out->m_data,
              4);
          m_size = m_primitives_out->m_size;
          v45 = &m_primitives_out->m_data[m_size];
          m_primitives_out->m_size = m_size + 1;
          v45->ID = v42;
          return;
        case 0x60:
        case 0x61:
        case 0x62:
        case 0x63:
          PC += 2;
          v54[(unsigned int)(v5 - 96)] = v6;
          goto $propertyCopy_10;
        case 0x64:
        case 0x65:
        case 0x66:
        case 0x67:
          v37 = v7 + (v6 << 8);
          v38 = (unsigned int)(v5 - 100);
          PC += 3;
          goto LABEL_52;
        case 0x68:
        case 0x69:
        case 0x6A:
        case 0x6B:
          v37 = *((unsigned __int8 *)PC + 4) + (v6 << 24) + (v7 << 16) + (v8 << 8);
          v38 = (unsigned int)(v5 - 104);
          PC += 5;
LABEL_52:
          v54[v38] = v37;
$propertyCopy_10:
          v39 = v54[0];
          if ( query != (hkpMoppSphereVirtualMachine::hkpMoppSphereVirtualMachineQuery *)&m_x )
          {
            m_x = query->m_x;
            m_y = query->m_y;
            m_z = query->m_z;
            m_radius = query->m_radius;
            m_offset_x = query->m_offset_x;
            m_offset_y = query->m_offset_y;
            v52 = *(_QWORD *)&query->m_offset_z;
            m_shift = query->m_shift;
            v40 = query->m_properties[0];
            query = (hkpMoppSphereVirtualMachine::hkpMoppSphereVirtualMachineQuery *)&m_x;
            v54[0] = v40;
          }
          v54[0] = v39;
          break;
        default:
          __debugbreak();
          continue;
      }
    }
  }
}  }
          v54[0] = v39;
          break;
        default:
          __debugbreak();
          continue;
      }
    }
  }
}

// File Line: 307
// RVA: 0xDF5EE0
void __fastcall hkpMoppSphereVirtualMachine::querySphere(
        hkpMoppSphereVirtualMachine *this,
        hkpMoppCode *code,
        hkSphere *sphere,
        hkArray<hkpMoppPrimitiveInfo,hkContainerHeapAllocator> *primitiveResults)
{
  char *m_data; // r11
  float v5; // xmm0_4
  int v8; // r9d
  float v9; // xmm0_4
  int v10; // edx
  float v11; // xmm0_4
  int v12; // ecx
  float v13; // xmm0_4
  int v14; // eax
  hkpMoppSphereVirtualMachine::hkpMoppSphereVirtualMachineQuery query; // [rsp+20h] [rbp-38h] BYREF

  m_data = code->m_data.m_data;
  this->m_primitives_out = primitiveResults;
  v5 = sphere->m_pos.m_quad.m128_f32[0] - code->m_info.m_offset.m_quad.m128_f32[0];
  *(_QWORD *)&query.m_shift = 16i64;
  v8 = (int)(float)(v5 * code->m_info.m_offset.m_quad.m128_f32[3]) - 1;
  this->m_x = v8;
  v9 = sphere->m_pos.m_quad.m128_f32[1];
  query.m_x = v8 >> 16;
  v10 = (int)(float)((float)(v9 - code->m_info.m_offset.m_quad.m128_f32[1]) * code->m_info.m_offset.m_quad.m128_f32[3])
      - 1;
  this->m_y = v10;
  v11 = sphere->m_pos.m_quad.m128_f32[2];
  query.m_y = v10 >> 16;
  v12 = (int)(float)((float)(v11 - code->m_info.m_offset.m_quad.m128_f32[2]) * code->m_info.m_offset.m_quad.m128_f32[3])
      - 1;
  this->m_z = v12;
  v13 = sphere->m_pos.m_quad.m128_f32[3];
  query.m_z = v12 >> 16;
  v14 = (int)(float)(v13 * code->m_info.m_offset.m_quad.m128_f32[3]) + 2;
  this->m_radius = v14;
  query.m_radius = (v14 >> 16) + 1;
  *(_QWORD *)&query.m_offset_x = 0i64;
  *(_QWORD *)&query.m_offset_z = 0i64;
  hkpMoppSphereVirtualMachine::querySphereOnTree(this, &query, m_data);
}

