// File Line: 61
// RVA: 0xDF7DC0
void __fastcall hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachine(hkpMoppKDopGeometriesVirtualMachine *this)
{
  this->m_visitedTerminals.m_capacityAndFlags = 2147483648;
  this->m_visitedTerminals.m_data = 0i64;
  this->m_visitedTerminals.m_size = 0;
  this->m_queryObject.m_earlyExit.m_bool = 0;
  this->m_queryObject.m_kdopDepth = -1;
  this->m_queryObject.m_useSpecifiedID.m_bool = 0;
  this->m_queryObject.m_specifiedId = 0;
}

// File Line: 68
// RVA: 0xDF7E00
void __fastcall hkpMoppKDopGeometriesVirtualMachine::~hkpMoppKDopGeometriesVirtualMachine(hkpMoppKDopGeometriesVirtualMachine *this)
{
  int v1; // er8
  hkpMoppKDopGeometriesVirtualMachine *v2; // rbx

  v1 = this->m_visitedTerminals.m_capacityAndFlags;
  v2 = this;
  this->m_visitedTerminals.m_size = 0;
  if ( v1 < 0 )
  {
    this->m_visitedTerminals.m_data = 0i64;
    this->m_visitedTerminals.m_capacityAndFlags = 2147483648;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_visitedTerminals.m_data,
      4 * v1);
    v2->m_visitedTerminals.m_data = 0i64;
    v2->m_visitedTerminals.m_capacityAndFlags = 2147483648;
  }
}

// File Line: 77
// RVA: 0xDF8C10
void __fastcall doubleCut(hkp26Dop *dop, hkp26Dop::DOP_AXIS axis, float newL, float newH, float *oldL, float *oldH)
{
  __int64 v6; // rdx

  *oldL = *(&dop->m_lx + 2 * axis);
  *oldH = *(&dop->m_hx + 2 * axis);
  v6 = 2 * axis;
  *(&dop->m_lx + v6) = newL;
  *(&dop->m_hx + v6) = newH;
}

// File Line: 91
// RVA: 0xDF8C50
float __fastcall shiftDopLow(hkp26Dop *dop, hkp26Dop::DOP_AXIS axis, float newOffsetLow)
{
  float result; // xmm0_4

  result = *(&dop->m_lx + 2 * axis);
  *(&dop->m_lx + 2 * axis) = newOffsetLow;
  return result;
}

// File Line: 104
// RVA: 0xDF8C70
float __fastcall shiftDopHigh(hkp26Dop *dop, hkp26Dop::DOP_AXIS axis, float newOffsetHigh)
{
  float result; // xmm0_4

  result = *(&dop->m_hx + 2 * axis);
  *(&dop->m_hx + 2 * axis) = newOffsetHigh;
  return result;
}

// File Line: 117
// RVA: 0xDF7E70
void __fastcall hkpMoppKDopGeometriesVirtualMachine::queryMopp(hkpMoppKDopGeometriesVirtualMachine *this, hkpMoppCode *code, hkpMoppKDopQuery *queryInput, hkpMoppInfo *kDopGeometries)
{
  hkpMoppCode *v4; // r11
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  unsigned int v9; // eax
  signed int v10; // edx
  int v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery query; // [rsp+20h] [rbp-28h]

  this->m_kDopGeometries = kDopGeometries;
  v4 = code;
  this->m_ItoFScale = 1.0 / code->m_info.m_offset.m_quad.m128_f32[3];
  this->m_offset = (hkVector4f)code->m_info;
  this->m_hitFound.m_bool = 0;
  v5 = this->m_ItoFScale;
  *(_DWORD *)&this->m_queryObject.m_earlyExit.m_bool = *(_DWORD *)&queryInput->m_earlyExit.m_bool;
  this->m_queryObject.m_kdopDepth = queryInput->m_kdopDepth;
  v6 = v5 * 16777216.0;
  v7 = (float)(v5 * 16777216.0) * 2.0;
  v8 = v6 * -2.0;
  *(_DWORD *)&this->m_queryObject.m_useSpecifiedID.m_bool = *(_DWORD *)&queryInput->m_useSpecifiedID.m_bool;
  v9 = queryInput->m_specifiedId;
  *(_QWORD *)&query.m_offset_x = 0i64;
  *(_QWORD *)&query.m_offset_z = 0i64;
  query.m_primitiveOffset = 0;
  this->m_queryObject.m_specifiedId = v9;
  this->m_terminaloffset = -1;
  this->m_level = 0;
  v10 = 0;
  do
  {
    v11 = 2 * v10;
    if ( v10 >= 3 )
    {
      if ( v10 >= 9 )
      {
        v12 = v8 * 1.7320508;
        v13 = v7 * 1.7320508;
      }
      else
      {
        v12 = v8 * 1.4142135;
        v13 = v7 * 1.4142135;
      }
      *(&this->m_kdop.m_lx + v11) = v12;
      *(&this->m_kdop.m_hx + v11) = v13;
    }
    else
    {
      *(&this->m_kdop.m_lx + v11) = v8;
      *(&this->m_kdop.m_hx + v11) = v7;
    }
    ++v10;
  }
  while ( v10 < 13 );
  query.m_properties[0] = 0;
  hkpMoppKDopGeometriesVirtualMachine::queryMoppKDopGeometriesRecurse(this, &query, v4->m_data.m_data);
}

// File Line: 181
// RVA: 0xDF8A00
void __fastcall hkpMoppKDopGeometriesVirtualMachine::addHit(hkpMoppKDopGeometriesVirtualMachine *this, unsigned int id, const unsigned int *properties)
{
  int v3; // er9
  hkpMoppKDopGeometriesVirtualMachine *v4; // rdi
  __int64 v5; // rcx
  unsigned int v6; // esi
  __int64 v7; // r8
  unsigned int *v8; // rax
  char v9; // al
  bool v10; // bp
  bool v11; // al

  v3 = 0;
  v4 = this;
  v5 = this->m_visitedTerminals.m_size;
  v6 = id;
  v7 = 0i64;
  if ( v5 <= 0 )
    goto LABEL_7;
  v8 = v4->m_visitedTerminals.m_data;
  while ( *v8 != id )
  {
    ++v7;
    ++v3;
    ++v8;
    if ( v7 >= v5 )
      goto LABEL_7;
  }
  if ( v3 == -1 )
  {
LABEL_7:
    v9 = v4->m_queryObject.m_useSpecifiedID.m_bool;
    v10 = v9 && id == v4->m_queryObject.m_specifiedId;
    if ( !v9 || v10 )
    {
      hkpMoppKDopGeometriesVirtualMachine::pushKDop(v4, (hkBool)1, id);
      v11 = v4->m_queryObject.m_earlyExit.m_bool || v10;
      v4->m_queryObject.m_earlyExit.m_bool = v11;
    }
    if ( v4->m_visitedTerminals.m_size == (v4->m_visitedTerminals.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
        &v4->m_visitedTerminals,
        4);
    v4->m_visitedTerminals.m_data[v4->m_visitedTerminals.m_size++] = v6;
  }
  if ( v4->m_queryObject.m_earlyExit.m_bool )
    v4->m_hitFound.m_bool = 1;
}

// File Line: 203
// RVA: 0xDF8B00
void __fastcall hkpMoppKDopGeometriesVirtualMachine::pushKDop(hkpMoppKDopGeometriesVirtualMachine *this, hkBool isTerminal, unsigned int id)
{
  hkpMoppInfo *v3; // r9

  v3 = this->m_kDopGeometries;
  v3->m_isTerminal = isTerminal;
  if ( isTerminal.m_bool )
    v3->m_shapeKey = id;
  v3->m_level = this->m_level;
  v3->m_dop.m_lx = this->m_kdop.m_lx;
  v3->m_dop.m_hx = this->m_kdop.m_hx;
  v3->m_dop.m_ly = this->m_kdop.m_ly;
  v3->m_dop.m_hy = this->m_kdop.m_hy;
  v3->m_dop.m_lz = this->m_kdop.m_lz;
  v3->m_dop.m_hz = this->m_kdop.m_hz;
  v3->m_dop.m_lyz = this->m_kdop.m_lyz;
  v3->m_dop.m_hyz = this->m_kdop.m_hyz;
  v3->m_dop.m_lymz = this->m_kdop.m_lymz;
  v3->m_dop.m_hymz = this->m_kdop.m_hymz;
  v3->m_dop.m_lxz = this->m_kdop.m_lxz;
  v3->m_dop.m_hxz = this->m_kdop.m_hxz;
  v3->m_dop.m_lxmz = this->m_kdop.m_lxmz;
  v3->m_dop.m_hxmz = this->m_kdop.m_hxmz;
  v3->m_dop.m_lxy = this->m_kdop.m_lxy;
  v3->m_dop.m_hxy = this->m_kdop.m_hxy;
  v3->m_dop.m_lxmy = this->m_kdop.m_lxmy;
  v3->m_dop.m_hxmy = this->m_kdop.m_hxmy;
  v3->m_dop.m_lxyz = this->m_kdop.m_lxyz;
  v3->m_dop.m_hxyz = this->m_kdop.m_hxyz;
  v3->m_dop.m_lxymz = this->m_kdop.m_lxymz;
  v3->m_dop.m_hxymz = this->m_kdop.m_hxymz;
  v3->m_dop.m_lxmyz = this->m_kdop.m_lxmyz;
  v3->m_dop.m_hxmyz = this->m_kdop.m_hxmyz;
  v3->m_dop.m_lxmymz = this->m_kdop.m_lxmymz;
  v3->m_dop.m_hxmymz = this->m_kdop.m_hxmymz;
  ++this->m_kDopGeometries;
}

// File Line: 231
// RVA: 0xDF7F90
void __fastcall hkpMoppKDopGeometriesVirtualMachine::queryMoppKDopGeometriesRecurse(hkpMoppKDopGeometriesVirtualMachine *this, hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *query, const char *PC)
{
  const char *v3; // r11
  unsigned __int8 v4; // r10
  unsigned __int8 v5; // di
  int v6; // er8
  hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *v7; // rbx
  hkpMoppKDopGeometriesVirtualMachine *v8; // rsi
  int v9; // edx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // edx
  __int64 v14; // rax
  __int64 v15; // rax
  __m128i v16; // xmm1
  int v17; // ecx
  int v18; // er8
  signed __int64 v19; // r11
  __m128i v20; // xmm7
  int v21; // edx
  float v22; // xmm7_4
  float v23; // xmm1_4
  int v24; // edx
  int v25; // edx
  float v26; // xmm7_4
  __int64 v27; // rbx
  __int64 v28; // rdi
  int v29; // xmm6_4
  int v30; // xmm6_4
  int v31; // eax
  __int64 v32; // r8
  int v33; // eax
  float v34; // xmm6_4
  float v35; // xmm7_4
  int v36; // xmm8_4
  int v37; // xmm9_4
  __int64 v38; // rdi
  int v39; // ecx
  int v40; // edi
  int v41; // eax
  float v42; // xmm6_4
  float v43; // xmm7_4
  unsigned int v44; // eax
  int v45; // [rsp+20h] [rbp-39h]
  signed __int64 v46; // [rsp+28h] [rbp-31h]
  signed __int64 v47; // [rsp+30h] [rbp-29h]
  __int64 v48; // [rsp+30h] [rbp-29h]
  int v49; // [rsp+38h] [rbp-21h]
  int v50; // [rsp+3Ch] [rbp-1Dh]
  int v51; // [rsp+40h] [rbp-19h]
  int v52; // [rsp+44h] [rbp-15h]
  int v53; // [rsp+48h] [rbp-11h]
  int v54; // [rsp+4Ch] [rbp-Dh]
  unsigned __int8 v55; // [rsp+C0h] [rbp+67h]
  int v56; // [rsp+C0h] [rbp+67h]
  char v57; // [rsp+C0h] [rbp+67h]
  char v58; // [rsp+C0h] [rbp+67h]
  hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *querya; // [rsp+C8h] [rbp+6Fh]
  const char *v60; // [rsp+D0h] [rbp+77h]
  const char *v61; // [rsp+D0h] [rbp+77h]
  unsigned __int8 v62; // [rsp+D8h] [rbp+7Fh]
  int v63; // [rsp+D8h] [rbp+7Fh]
  int v64; // [rsp+D8h] [rbp+7Fh]

  v60 = PC;
  querya = query;
  v3 = PC;
  v4 = PC[2];
  v5 = PC[1];
  v45 = *(unsigned __int8 *)PC;
  v6 = *(unsigned __int8 *)PC;
  v7 = query;
  v46 = (signed __int64)(v3 + 2);
  v8 = this;
  v47 = (signed __int64)(v3 + 3);
  v62 = v4;
  v55 = v3[3];
  if ( !this->m_hitFound.m_bool )
  {
    v9 = v53;
    while ( 1 )
    {
      switch ( v6 )
      {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
          v49 = v7->m_offset_x + (v5 << (16 - LOBYTE(v7->m_shift)));
          v50 = v7->m_offset_y + (v4 << (16 - LOBYTE(v7->m_shift)));
          v51 = v7->m_offset_z + (v55 << (16 - LOBYTE(v7->m_shift)));
          v3 += 4;
          v52 = v6 + v7->m_shift;
          v60 = v3;
          v54 = v7->m_properties[0];
          v9 = v7->m_primitiveOffset;
          v7 = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49;
          v53 = v9;
          querya = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49;
          break;
        case 5:
          v3 += v5 + 2;
          v60 = v3;
          break;
        case 6:
          v3 += 256 * v5 + v4 + 3;
          v60 = v3;
          break;
        case 7:
          v3 += 0x10000 * v5 + 256 * v4 + (unsigned int)v55 + 4;
          v60 = v3;
          break;
        case 9:
          if ( v7 != (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49 )
          {
            v49 = v7->m_offset_x;
            v50 = v7->m_offset_y;
            v51 = v7->m_offset_z;
            v52 = v7->m_shift;
            v9 = v7->m_primitiveOffset;
            v53 = v7->m_primitiveOffset;
            v10 = v7->m_properties[0];
            v7 = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49;
            v54 = v10;
            querya = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49;
          }
          v3 = (const char *)v46;
          v9 += v5;
          v60 = (const char *)v46;
          v53 = v9;
          break;
        case 10:
          if ( v7 != (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49 )
          {
            v49 = v7->m_offset_x;
            v50 = v7->m_offset_y;
            v51 = v7->m_offset_z;
            v52 = v7->m_shift;
            v9 = v7->m_primitiveOffset;
            v53 = v7->m_primitiveOffset;
            v11 = v7->m_properties[0];
            v7 = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49;
            v54 = v11;
            querya = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49;
          }
          v3 = (const char *)v47;
          v9 += v4 + (v5 << 8);
          v60 = (const char *)v47;
          v53 = v9;
          break;
        case 11:
          v9 = *((unsigned __int8 *)v3 + 4) + (v5 << 24) + (v4 << 16) + (v55 << 8);
          if ( v7 != (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49 )
          {
            v49 = v7->m_offset_x;
            v50 = v7->m_offset_y;
            v51 = v7->m_offset_z;
            v52 = v7->m_shift;
            v53 = v7->m_primitiveOffset;
            v12 = v7->m_properties[0];
            v7 = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49;
            v54 = v12;
            querya = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49;
          }
          v3 += 5;
          v53 = v9;
          v60 = v3;
          break;
        case 16:
        case 17:
        case 18:
          v18 = v6 - 16;
          v21 = *(&v7->m_offset_x + v18);
          v16 = _mm_cvtsi32_si128(v21 + ((unsigned int)v5 << (16 - LOBYTE(v7->m_shift))));
          v17 = 0;
          v19 = (signed __int64)(v3 + 4);
          v20 = _mm_cvtsi32_si128(v21 + ((unsigned int)v4 << (16 - LOBYTE(v7->m_shift))));
          v56 = v55;
          goto LABEL_39;
        case 19:
          v16 = _mm_cvtsi32_si128(v7->m_offset_z + v7->m_offset_y + (2 * (unsigned int)v5 << (16 - LOBYTE(v7->m_shift))));
          v17 = 0;
          v18 = 3;
          v19 = (signed __int64)(v3 + 4);
          v20 = _mm_cvtsi32_si128(v7->m_offset_z + v7->m_offset_y + (2 * (unsigned int)v4 << (16 - LOBYTE(v7->m_shift))));
          v56 = v55;
          goto LABEL_39;
        case 20:
          v18 = 4;
          v16 = _mm_cvtsi32_si128(v7->m_offset_y + ((2 * (unsigned int)v5 - 255) << (16 - LOBYTE(v7->m_shift)))
                                                 - v7->m_offset_z);
          v17 = 0;
          v19 = (signed __int64)(v3 + 4);
          v20 = _mm_cvtsi32_si128(v7->m_offset_y + ((2 * (unsigned int)v4 - 255) << (16 - LOBYTE(v7->m_shift)))
                                                 - v7->m_offset_z);
          v56 = v55;
          goto LABEL_39;
        case 21:
          v16 = _mm_cvtsi32_si128(v7->m_offset_z + v7->m_offset_x + (2 * (unsigned int)v5 << (16 - LOBYTE(v7->m_shift))));
          v17 = 0;
          v18 = 5;
          v19 = (signed __int64)(v3 + 4);
          v20 = _mm_cvtsi32_si128(v7->m_offset_z + v7->m_offset_x + (2 * (unsigned int)v4 << (16 - LOBYTE(v7->m_shift))));
          v56 = v55;
          goto LABEL_39;
        case 22:
          v16 = _mm_cvtsi32_si128(v7->m_offset_x + ((2 * (unsigned int)v5 - 255) << (16 - LOBYTE(v7->m_shift)))
                                                 - v7->m_offset_z);
          v17 = 0;
          v18 = 6;
          v19 = (signed __int64)(v3 + 4);
          v20 = _mm_cvtsi32_si128(v7->m_offset_x + ((2 * (unsigned int)v4 - 255) << (16 - LOBYTE(v7->m_shift)))
                                                 - v7->m_offset_z);
          v56 = v55;
          goto LABEL_39;
        case 23:
          v16 = _mm_cvtsi32_si128(v7->m_offset_y + v7->m_offset_x + (2 * (unsigned int)v5 << (16 - LOBYTE(v7->m_shift))));
          v17 = 0;
          v18 = 7;
          v19 = (signed __int64)(v3 + 4);
          v20 = _mm_cvtsi32_si128(v7->m_offset_y + v7->m_offset_x + (2 * (unsigned int)v4 << (16 - LOBYTE(v7->m_shift))));
          v56 = v55;
          goto LABEL_39;
        case 24:
          v16 = _mm_cvtsi32_si128(v7->m_offset_x + ((2 * (unsigned int)v5 - 255) << (16 - LOBYTE(v7->m_shift)))
                                                 - v7->m_offset_y);
          v17 = 0;
          v18 = 8;
          v19 = (signed __int64)(v3 + 4);
          v20 = _mm_cvtsi32_si128(v7->m_offset_x + ((2 * (unsigned int)v4 - 255) << (16 - LOBYTE(v7->m_shift)))
                                                 - v7->m_offset_y);
          v56 = v55;
          goto LABEL_39;
        case 25:
          v16 = _mm_cvtsi32_si128(
                  v7->m_offset_z
                + v7->m_offset_y
                + v7->m_offset_x
                + (3 * (unsigned int)v5 << (16 - LOBYTE(v7->m_shift))));
          v17 = 0;
          v56 = v55;
          v18 = 9;
          v19 = (signed __int64)(v3 + 4);
          v20 = _mm_cvtsi32_si128(
                  v7->m_offset_z
                + v7->m_offset_y
                + v7->m_offset_x
                + (3 * (unsigned int)v62 << (16 - LOBYTE(v7->m_shift))));
          goto LABEL_39;
        case 26:
          v16 = _mm_cvtsi32_si128(
                  v7->m_offset_y
                + v7->m_offset_x
                + (3 * ((unsigned int)v5 - 85) << (16 - LOBYTE(v7->m_shift)))
                - v7->m_offset_z);
          v17 = 0;
          v56 = v55;
          v18 = 10;
          v19 = (signed __int64)(v3 + 4);
          v20 = _mm_cvtsi32_si128(
                  v7->m_offset_y
                + v7->m_offset_x
                + (3 * ((unsigned int)v62 - 85) << (16 - LOBYTE(v7->m_shift)))
                - v7->m_offset_z);
          goto LABEL_39;
        case 27:
          v16 = _mm_cvtsi32_si128(
                  v7->m_offset_z
                + v7->m_offset_x
                + (3 * ((unsigned int)v5 - 85) << (16 - LOBYTE(v7->m_shift)))
                - v7->m_offset_y);
          v17 = 0;
          v56 = v55;
          v18 = 11;
          v19 = (signed __int64)(v3 + 4);
          v20 = _mm_cvtsi32_si128(
                  v7->m_offset_z
                + v7->m_offset_x
                + (3 * ((unsigned int)v62 - 85) << (16 - LOBYTE(v7->m_shift)))
                - v7->m_offset_y);
          goto LABEL_39;
        case 28:
          v16 = _mm_cvtsi32_si128(
                  v7->m_offset_x
                + (3 * ((unsigned int)v5 - 170) << (16 - LOBYTE(v7->m_shift)))
                - v7->m_offset_y
                - v7->m_offset_z);
          v17 = 0;
          v56 = v55;
          v18 = 12;
          v19 = (signed __int64)(v3 + 4);
          v20 = _mm_cvtsi32_si128(
                  v7->m_offset_x
                + (3 * ((unsigned int)v62 - 170) << (16 - LOBYTE(v7->m_shift)))
                - v7->m_offset_y
                - v7->m_offset_z);
          goto LABEL_39;
        case 32:
        case 33:
        case 34:
          v18 = v6 - 32;
          v17 = 0;
          v19 = (signed __int64)(v3 + 3);
          v22 = (float)((v5 << (16 - LOBYTE(v7->m_shift))) + *(&v7->m_offset_x + v18));
          v56 = v4;
          v23 = (float)(1 << (16 - LOBYTE(v7->m_shift))) + v22;
          goto LABEL_40;
        case 35:
        case 36:
        case 37:
          v18 = v6 - 35;
          v24 = *(&v7->m_offset_x + v18);
          v16 = _mm_cvtsi32_si128(v24 + ((unsigned int)v5 << (16 - LOBYTE(v7->m_shift))));
          v20 = _mm_cvtsi32_si128(v24 + ((unsigned int)v4 << (16 - LOBYTE(v7->m_shift))));
          v17 = *((unsigned __int8 *)v3 + 4) + (v55 << 8);
          v25 = *((unsigned __int8 *)v3 + 6) + (*((unsigned __int8 *)v3 + 5) << 8);
          v19 = (signed __int64)(v3 + 7);
          v56 = v25;
LABEL_39:
          LODWORD(v22) = (unsigned __int128)_mm_cvtepi32_ps(v20);
          LODWORD(v23) = (unsigned __int128)_mm_cvtepi32_ps(v16);
LABEL_40:
          v26 = v22 * v8->m_ItoFScale;
          v27 = v18;
          v63 = v17;
          v28 = 2 * v18;
          v29 = *((_DWORD *)&v8->m_kdop.m_hx + 2 * v18);
          v61 = (const char *)(v17 + v19);
          *(&v8->m_kdop.m_hx + v28) = v23 * v8->m_ItoFScale;
          hkpMoppKDopGeometriesVirtualMachine::queryMoppKDopGeometriesRecurse(v8, querya, v61);
          *((_DWORD *)&v8->m_kdop.m_hx + v28) = v29;
          v30 = *((_DWORD *)&v8->m_kdop.m_lx + 2 * v27);
          *(&v8->m_kdop.m_lx + v28) = v26;
          hkpMoppKDopGeometriesVirtualMachine::queryMoppKDopGeometriesRecurse(v8, querya, &v61[-(v63 - v56)]);
          *((_DWORD *)&v8->m_kdop.m_lx + v28) = v30;
          return;
        case 38:
        case 39:
        case 40:
          v31 = v6 - 38;
          v32 = v6 - 38;
          v64 = v31;
          v48 = v32;
          v33 = this->m_queryObject.m_kdopDepth;
          v34 = (float)(*(&v7->m_offset_x + v32) + (v5 << (16 - LOBYTE(v7->m_shift)))) * this->m_ItoFScale;
          v35 = (float)(*(&v7->m_offset_x + v32) + (v4 << (16 - LOBYTE(v7->m_shift)))) * this->m_ItoFScale;
          if ( v33 && this->m_level >= v33 )
          {
            v57 = 0;
          }
          else
          {
            v57 = 1;
            hkpMoppKDopGeometriesVirtualMachine::pushKDop(this, 0, 0xFFFFFFFF);
            v3 = v60;
            v32 = v48;
          }
          v36 = *((_DWORD *)&v8->m_kdop.m_lx + 2 * v32);
          v37 = *((_DWORD *)&v8->m_kdop.m_hx + 2 * v32);
          v38 = 2 * v64;
          *(&v8->m_kdop.m_lx + v38) = v34;
          *(&v8->m_kdop.m_hx + v38) = v35;
          ++v8->m_level;
          hkpMoppKDopGeometriesVirtualMachine::queryMoppKDopGeometriesRecurse(v8, v7, v3 + 3);
          --v8->m_level;
          if ( v57 && v8->m_queryObject.m_useSpecifiedID.m_bool && !v8->m_hitFound.m_bool )
            goto LABEL_55;
          goto LABEL_56;
        case 41:
        case 42:
        case 43:
          v39 = v5;
          v40 = v6 - 41;
          v41 = v8->m_queryObject.m_kdopDepth;
          v42 = (float)(v55 + ((v4 + (v39 << 8)) << 8)) * v8->m_ItoFScale;
          v43 = (float)(*((unsigned __int8 *)v3 + 6)
                      + ((*((unsigned __int8 *)v3 + 5) + (*((unsigned __int8 *)v3 + 4) << 8)) << 8))
              * v8->m_ItoFScale;
          if ( v41 && v8->m_level >= v41 )
          {
            v58 = 0;
          }
          else
          {
            v58 = 1;
            hkpMoppKDopGeometriesVirtualMachine::pushKDop(v8, 0, 0xFFFFFFFF);
            v3 = v60;
          }
          v36 = *((_DWORD *)&v8->m_kdop.m_lx + 2 * v40);
          v37 = *((_DWORD *)&v8->m_kdop.m_hx + 2 * v40);
          v38 = 2 * v40;
          *(&v8->m_kdop.m_lx + v38) = v42;
          *(&v8->m_kdop.m_hx + v38) = v43;
          ++v8->m_level;
          hkpMoppKDopGeometriesVirtualMachine::queryMoppKDopGeometriesRecurse(v8, v7, v3 + 7);
          --v8->m_level;
          if ( v58 && v8->m_queryObject.m_useSpecifiedID.m_bool )
LABEL_55:
            --v8->m_kDopGeometries;
LABEL_56:
          *((_DWORD *)&v8->m_kdop.m_lx + v38) = v36;
          *((_DWORD *)&v8->m_kdop.m_hx + v38) = v37;
          return;
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
          v44 = v6 - 48;
          goto LABEL_61;
        case 80:
          v44 = v5;
LABEL_61:
          this->m_terminaloffset = v44;
          goto $add_Terminal_13;
        case 81:
          this->m_terminaloffset = v4 + (v5 << 8);
          goto $add_Terminal_13;
        case 82:
          this->m_terminaloffset = v55 + (v4 << 8) + (v5 << 16);
$add_Terminal_13:
          this->m_terminaloffset += v7->m_primitiveOffset;
          hkpMoppKDopGeometriesVirtualMachine::addHit(this, this->m_terminaloffset, v7->m_properties);
          v8->m_terminaloffset = -1;
          return;
        case 96:
        case 97:
        case 98:
        case 99:
          v3 = (const char *)v46;
          *(&v54 + (unsigned int)(v45 - 96)) = v5;
          goto LABEL_21;
        case 100:
        case 101:
        case 102:
        case 103:
          v3 = (const char *)v47;
          v13 = v4 + (v5 << 8);
          v14 = (unsigned int)(v45 - 100);
          goto LABEL_20;
        case 104:
        case 105:
        case 106:
        case 107:
          v13 = *((unsigned __int8 *)v3 + 4) + (v5 << 24) + (v4 << 16) + (v55 << 8);
          v14 = (unsigned int)*(unsigned __int8 *)v3 - 104;
          v3 += 5;
LABEL_20:
          *(&v54 + v14) = v13;
LABEL_21:
          v60 = v3;
          if ( v7 == (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49 )
          {
            v9 = v53;
          }
          else
          {
            v49 = v7->m_offset_x;
            v50 = v7->m_offset_y;
            v51 = v7->m_offset_z;
            v52 = v7->m_shift;
            v9 = v7->m_primitiveOffset;
            v53 = v7->m_primitiveOffset;
            v15 = v7->m_properties[0];
            v7 = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49;
            querya = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&v49;
          }
          break;
        default:
          __debugbreak();
          break;
      }
      v4 = v3[2];
      v5 = v3[1];
      v45 = *(unsigned __int8 *)v3;
      v6 = *(unsigned __int8 *)v3;
      v55 = v3[3];
      v62 = v3[2];
      v46 = (signed __int64)(v3 + 2);
      v47 = (signed __int64)(v3 + 3);
    }
  }
}

