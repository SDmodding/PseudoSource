// File Line: 61
// RVA: 0xDF7DC0
void __fastcall hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachine(
        hkpMoppKDopGeometriesVirtualMachine *this)
{
  this->m_visitedTerminals.m_capacityAndFlags = 0x80000000;
  this->m_visitedTerminals.m_data = 0i64;
  this->m_visitedTerminals.m_size = 0;
  this->m_queryObject.m_earlyExit.m_bool = 0;
  this->m_queryObject.m_kdopDepth = -1;
  this->m_queryObject.m_useSpecifiedID.m_bool = 0;
  this->m_queryObject.m_specifiedId = 0;
}

// File Line: 68
// RVA: 0xDF7E00
void __fastcall hkpMoppKDopGeometriesVirtualMachine::~hkpMoppKDopGeometriesVirtualMachine(
        hkpMoppKDopGeometriesVirtualMachine *this)
{
  int m_capacityAndFlags; // r8d

  m_capacityAndFlags = this->m_visitedTerminals.m_capacityAndFlags;
  this->m_visitedTerminals.m_size = 0;
  if ( m_capacityAndFlags < 0 )
  {
    this->m_visitedTerminals.m_data = 0i64;
    this->m_visitedTerminals.m_capacityAndFlags = 0x80000000;
  }
  else
  {
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_visitedTerminals.m_data,
      4 * m_capacityAndFlags);
    this->m_visitedTerminals.m_data = 0i64;
    this->m_visitedTerminals.m_capacityAndFlags = 0x80000000;
  }
}

// File Line: 77
// RVA: 0xDF8C10
void __fastcall doubleCut(hkp26Dop *dop, hkp26Dop::DOP_AXIS axis, float newL, float newH, float *oldL, float *oldH)
{
  __int32 v6; // eax

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
void __fastcall hkpMoppKDopGeometriesVirtualMachine::queryMopp(
        hkpMoppKDopGeometriesVirtualMachine *this,
        hkpMoppCode *code,
        hkpMoppKDopQuery *queryInput,
        hkpMoppInfo *kDopGeometries)
{
  float m_ItoFScale; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  unsigned int m_specifiedId; // eax
  int i; // edx
  int v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery query; // [rsp+20h] [rbp-28h] BYREF

  this->m_kDopGeometries = kDopGeometries;
  this->m_ItoFScale = 1.0 / code->m_info.m_offset.m_quad.m128_f32[3];
  this->m_offset = (hkVector4f)code->m_info;
  this->m_hitFound.m_bool = 0;
  m_ItoFScale = this->m_ItoFScale;
  *(_DWORD *)&this->m_queryObject.m_earlyExit.m_bool = *(_DWORD *)&queryInput->m_earlyExit.m_bool;
  this->m_queryObject.m_kdopDepth = queryInput->m_kdopDepth;
  v6 = m_ItoFScale * 16777216.0;
  v7 = (float)(m_ItoFScale * 16777216.0) * 2.0;
  v8 = v6 * -2.0;
  *(_DWORD *)&this->m_queryObject.m_useSpecifiedID.m_bool = *(_DWORD *)&queryInput->m_useSpecifiedID.m_bool;
  m_specifiedId = queryInput->m_specifiedId;
  memset(&query, 0, 20);
  this->m_queryObject.m_specifiedId = m_specifiedId;
  this->m_terminaloffset = -1;
  this->m_level = 0;
  for ( i = 0; i < 13; ++i )
  {
    v11 = 2 * i;
    if ( i >= 3 )
    {
      if ( i >= 9 )
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
  }
  query.m_properties[0] = 0;
  hkpMoppKDopGeometriesVirtualMachine::queryMoppKDopGeometriesRecurse(this, &query, code->m_data.m_data);
}

// File Line: 181
// RVA: 0xDF8A00
void __fastcall hkpMoppKDopGeometriesVirtualMachine::addHit(
        hkpMoppKDopGeometriesVirtualMachine *this,
        unsigned int id,
        const unsigned int *properties)
{
  int v3; // r9d
  __int64 m_size; // rcx
  __int64 v7; // r8
  unsigned int *m_data; // rax
  char m_bool; // al
  bool v10; // bp
  bool v11; // al

  v3 = 0;
  m_size = this->m_visitedTerminals.m_size;
  v7 = 0i64;
  if ( m_size <= 0 )
    goto LABEL_7;
  m_data = this->m_visitedTerminals.m_data;
  while ( *m_data != id )
  {
    ++v7;
    ++v3;
    ++m_data;
    if ( v7 >= m_size )
      goto LABEL_7;
  }
  if ( v3 == -1 )
  {
LABEL_7:
    m_bool = this->m_queryObject.m_useSpecifiedID.m_bool;
    v10 = m_bool && id == this->m_queryObject.m_specifiedId;
    if ( !m_bool || v10 )
    {
      hkpMoppKDopGeometriesVirtualMachine::pushKDop(this, (hkBool)1, id);
      v11 = this->m_queryObject.m_earlyExit.m_bool || v10;
      this->m_queryObject.m_earlyExit.m_bool = v11;
    }
    if ( this->m_visitedTerminals.m_size == (this->m_visitedTerminals.m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_visitedTerminals.m_data, 4);
    this->m_visitedTerminals.m_data[this->m_visitedTerminals.m_size++] = id;
  }
  if ( this->m_queryObject.m_earlyExit.m_bool )
    this->m_hitFound.m_bool = 1;
}

// File Line: 203
// RVA: 0xDF8B00
void __fastcall hkpMoppKDopGeometriesVirtualMachine::pushKDop(
        hkpMoppKDopGeometriesVirtualMachine *this,
        hkBool isTerminal,
        unsigned int id)
{
  hkpMoppInfo *m_kDopGeometries; // r9

  m_kDopGeometries = this->m_kDopGeometries;
  m_kDopGeometries->m_isTerminal = isTerminal;
  if ( isTerminal.m_bool )
    m_kDopGeometries->m_shapeKey = id;
  m_kDopGeometries->m_level = this->m_level;
  m_kDopGeometries->m_dop = this->m_kdop;
  ++this->m_kDopGeometries;
}

// File Line: 231
// RVA: 0xDF7F90
void __fastcall hkpMoppKDopGeometriesVirtualMachine::queryMoppKDopGeometriesRecurse(
        hkpMoppKDopGeometriesVirtualMachine *this,
        hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *query,
        const char *PC)
{
  const char *v3; // r11
  unsigned __int8 v4; // r10
  unsigned __int8 v5; // di
  int v6; // r8d
  hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *p_m_offset_x; // rbx
  int m_primitiveOffset; // edx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // edx
  __int64 v14; // rax
  __m128i v15; // xmm1
  int v16; // ecx
  int v17; // r8d
  const char *v18; // r11
  __m128i v19; // xmm7
  int v20; // edx
  float v21; // xmm7_4
  float v22; // xmm1_4
  int v23; // edx
  int v24; // edx
  float v25; // xmm7_4
  __int64 v26; // rbx
  __int64 v27; // rdi
  int v28; // xmm6_4
  int v29; // xmm6_4
  int v30; // eax
  __int64 v31; // r8
  int m_kdopDepth; // eax
  float v33; // xmm6_4
  float v34; // xmm7_4
  int v35; // xmm8_4
  int v36; // xmm9_4
  __int64 v37; // rdi
  int v38; // ecx
  int v39; // edi
  int v40; // eax
  float v41; // xmm6_4
  float v42; // xmm7_4
  unsigned int v43; // eax
  int v44; // [rsp+20h] [rbp-39h]
  const char *v45; // [rsp+28h] [rbp-31h]
  const char *v46; // [rsp+30h] [rbp-29h]
  __int64 v47; // [rsp+30h] [rbp-29h]
  int m_offset_x; // [rsp+38h] [rbp-21h] BYREF
  int m_offset_y; // [rsp+3Ch] [rbp-1Dh]
  int m_offset_z; // [rsp+40h] [rbp-19h]
  int m_shift; // [rsp+44h] [rbp-15h]
  int v52; // [rsp+48h] [rbp-11h]
  int v53; // [rsp+4Ch] [rbp-Dh]
  unsigned __int8 v54; // [rsp+C0h] [rbp+67h]
  int v55; // [rsp+C0h] [rbp+67h]
  char v56; // [rsp+C0h] [rbp+67h]
  char v57; // [rsp+C0h] [rbp+67h]
  hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *querya; // [rsp+C8h] [rbp+6Fh]
  const char *v59; // [rsp+D0h] [rbp+77h]
  const char *v60; // [rsp+D0h] [rbp+77h]
  unsigned __int8 v61; // [rsp+D8h] [rbp+7Fh]
  int v62; // [rsp+D8h] [rbp+7Fh]
  int v63; // [rsp+D8h] [rbp+7Fh]

  v59 = PC;
  querya = query;
  v3 = PC;
  v4 = PC[2];
  v5 = PC[1];
  v44 = *(unsigned __int8 *)PC;
  v6 = v44;
  p_m_offset_x = query;
  v45 = v3 + 2;
  v46 = v3 + 3;
  v61 = v4;
  v54 = v3[3];
  if ( !this->m_hitFound.m_bool )
  {
    m_primitiveOffset = v52;
    while ( 1 )
    {
      switch ( v6 )
      {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
          m_offset_x = p_m_offset_x->m_offset_x + (v5 << (16 - LOBYTE(p_m_offset_x->m_shift)));
          m_offset_y = p_m_offset_x->m_offset_y + (v4 << (16 - LOBYTE(p_m_offset_x->m_shift)));
          m_offset_z = p_m_offset_x->m_offset_z + (v54 << (16 - LOBYTE(p_m_offset_x->m_shift)));
          v3 += 4;
          m_shift = v6 + p_m_offset_x->m_shift;
          v59 = v3;
          v53 = p_m_offset_x->m_properties[0];
          m_primitiveOffset = p_m_offset_x->m_primitiveOffset;
          p_m_offset_x = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x;
          v52 = m_primitiveOffset;
          querya = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x;
          break;
        case 5:
          v3 += v5 + 2;
          v59 = v3;
          break;
        case 6:
          v3 += 256 * v5 + v4 + 3;
          v59 = v3;
          break;
        case 7:
          v3 += 0x10000 * v5 + 256 * v4 + (unsigned int)v54 + 4;
          v59 = v3;
          break;
        case 9:
          if ( p_m_offset_x != (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x )
          {
            m_offset_x = p_m_offset_x->m_offset_x;
            m_offset_y = p_m_offset_x->m_offset_y;
            m_offset_z = p_m_offset_x->m_offset_z;
            m_shift = p_m_offset_x->m_shift;
            m_primitiveOffset = p_m_offset_x->m_primitiveOffset;
            v52 = m_primitiveOffset;
            v10 = p_m_offset_x->m_properties[0];
            p_m_offset_x = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x;
            v53 = v10;
            querya = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x;
          }
          v3 = v45;
          m_primitiveOffset += v5;
          v59 = v45;
          v52 = m_primitiveOffset;
          break;
        case 10:
          if ( p_m_offset_x != (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x )
          {
            m_offset_x = p_m_offset_x->m_offset_x;
            m_offset_y = p_m_offset_x->m_offset_y;
            m_offset_z = p_m_offset_x->m_offset_z;
            m_shift = p_m_offset_x->m_shift;
            m_primitiveOffset = p_m_offset_x->m_primitiveOffset;
            v52 = m_primitiveOffset;
            v11 = p_m_offset_x->m_properties[0];
            p_m_offset_x = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x;
            v53 = v11;
            querya = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x;
          }
          v3 = v46;
          m_primitiveOffset += v4 + (v5 << 8);
          v59 = v46;
          v52 = m_primitiveOffset;
          break;
        case 11:
          m_primitiveOffset = *((unsigned __int8 *)v3 + 4) + (v5 << 24) + (v4 << 16) + (v54 << 8);
          if ( p_m_offset_x != (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x )
          {
            m_offset_x = p_m_offset_x->m_offset_x;
            m_offset_y = p_m_offset_x->m_offset_y;
            m_offset_z = p_m_offset_x->m_offset_z;
            m_shift = p_m_offset_x->m_shift;
            v52 = p_m_offset_x->m_primitiveOffset;
            v12 = p_m_offset_x->m_properties[0];
            p_m_offset_x = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x;
            v53 = v12;
            querya = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x;
          }
          v3 += 5;
          v52 = m_primitiveOffset;
          v59 = v3;
          break;
        case 16:
        case 17:
        case 18:
          v17 = v6 - 16;
          v20 = *(&p_m_offset_x->m_offset_x + v17);
          v15 = _mm_cvtsi32_si128(v20 + (v5 << (16 - LOBYTE(p_m_offset_x->m_shift))));
          v16 = 0;
          v18 = v3 + 4;
          v19 = _mm_cvtsi32_si128(v20 + (v4 << (16 - LOBYTE(p_m_offset_x->m_shift))));
          v55 = v54;
          goto LABEL_39;
        case 19:
          v15 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_z
                + p_m_offset_x->m_offset_y
                + ((2 * (unsigned int)v5) << (16 - LOBYTE(p_m_offset_x->m_shift))));
          v16 = 0;
          v17 = 3;
          v18 = v3 + 4;
          v19 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_z
                + p_m_offset_x->m_offset_y
                + ((2 * (unsigned int)v4) << (16 - LOBYTE(p_m_offset_x->m_shift))));
          v55 = v54;
          goto LABEL_39;
        case 20:
          v17 = 4;
          v15 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_y
                + ((2 * (unsigned int)v5 - 255) << (16 - LOBYTE(p_m_offset_x->m_shift)))
                - p_m_offset_x->m_offset_z);
          v16 = 0;
          v18 = v3 + 4;
          v19 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_y
                + ((2 * (unsigned int)v4 - 255) << (16 - LOBYTE(p_m_offset_x->m_shift)))
                - p_m_offset_x->m_offset_z);
          v55 = v54;
          goto LABEL_39;
        case 21:
          v15 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_z
                + p_m_offset_x->m_offset_x
                + ((2 * (unsigned int)v5) << (16 - LOBYTE(p_m_offset_x->m_shift))));
          v16 = 0;
          v17 = 5;
          v18 = v3 + 4;
          v19 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_z
                + p_m_offset_x->m_offset_x
                + ((2 * (unsigned int)v4) << (16 - LOBYTE(p_m_offset_x->m_shift))));
          v55 = v54;
          goto LABEL_39;
        case 22:
          v15 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_x
                + ((2 * (unsigned int)v5 - 255) << (16 - LOBYTE(p_m_offset_x->m_shift)))
                - p_m_offset_x->m_offset_z);
          v16 = 0;
          v17 = 6;
          v18 = v3 + 4;
          v19 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_x
                + ((2 * (unsigned int)v4 - 255) << (16 - LOBYTE(p_m_offset_x->m_shift)))
                - p_m_offset_x->m_offset_z);
          v55 = v54;
          goto LABEL_39;
        case 23:
          v15 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_y
                + p_m_offset_x->m_offset_x
                + ((2 * (unsigned int)v5) << (16 - LOBYTE(p_m_offset_x->m_shift))));
          v16 = 0;
          v17 = 7;
          v18 = v3 + 4;
          v19 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_y
                + p_m_offset_x->m_offset_x
                + ((2 * (unsigned int)v4) << (16 - LOBYTE(p_m_offset_x->m_shift))));
          v55 = v54;
          goto LABEL_39;
        case 24:
          v15 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_x
                + ((2 * (unsigned int)v5 - 255) << (16 - LOBYTE(p_m_offset_x->m_shift)))
                - p_m_offset_x->m_offset_y);
          v16 = 0;
          v17 = 8;
          v18 = v3 + 4;
          v19 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_x
                + ((2 * (unsigned int)v4 - 255) << (16 - LOBYTE(p_m_offset_x->m_shift)))
                - p_m_offset_x->m_offset_y);
          v55 = v54;
          goto LABEL_39;
        case 25:
          v15 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_z
                + p_m_offset_x->m_offset_y
                + p_m_offset_x->m_offset_x
                + ((3 * (unsigned int)v5) << (16 - LOBYTE(p_m_offset_x->m_shift))));
          v16 = 0;
          v55 = v54;
          v17 = 9;
          v18 = v3 + 4;
          v19 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_z
                + p_m_offset_x->m_offset_y
                + p_m_offset_x->m_offset_x
                + ((3 * (unsigned int)v61) << (16 - LOBYTE(p_m_offset_x->m_shift))));
          goto LABEL_39;
        case 26:
          v15 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_y
                + p_m_offset_x->m_offset_x
                + ((3 * ((unsigned int)v5 - 85)) << (16 - LOBYTE(p_m_offset_x->m_shift)))
                - p_m_offset_x->m_offset_z);
          v16 = 0;
          v55 = v54;
          v17 = 10;
          v18 = v3 + 4;
          v19 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_y
                + p_m_offset_x->m_offset_x
                + ((3 * ((unsigned int)v61 - 85)) << (16 - LOBYTE(p_m_offset_x->m_shift)))
                - p_m_offset_x->m_offset_z);
          goto LABEL_39;
        case 27:
          v15 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_z
                + p_m_offset_x->m_offset_x
                + ((3 * ((unsigned int)v5 - 85)) << (16 - LOBYTE(p_m_offset_x->m_shift)))
                - p_m_offset_x->m_offset_y);
          v16 = 0;
          v55 = v54;
          v17 = 11;
          v18 = v3 + 4;
          v19 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_z
                + p_m_offset_x->m_offset_x
                + ((3 * ((unsigned int)v61 - 85)) << (16 - LOBYTE(p_m_offset_x->m_shift)))
                - p_m_offset_x->m_offset_y);
          goto LABEL_39;
        case 28:
          v15 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_x
                + ((3 * ((unsigned int)v5 - 170)) << (16 - LOBYTE(p_m_offset_x->m_shift)))
                - p_m_offset_x->m_offset_y
                - p_m_offset_x->m_offset_z);
          v16 = 0;
          v55 = v54;
          v17 = 12;
          v18 = v3 + 4;
          v19 = _mm_cvtsi32_si128(
                  p_m_offset_x->m_offset_x
                + ((3 * ((unsigned int)v61 - 170)) << (16 - LOBYTE(p_m_offset_x->m_shift)))
                - p_m_offset_x->m_offset_y
                - p_m_offset_x->m_offset_z);
          goto LABEL_39;
        case 32:
        case 33:
        case 34:
          v17 = v6 - 32;
          v16 = 0;
          v18 = v3 + 3;
          v21 = (float)((v5 << (16 - LOBYTE(p_m_offset_x->m_shift))) + *(&p_m_offset_x->m_offset_x + v17));
          v55 = v4;
          v22 = (float)(1 << (16 - LOBYTE(p_m_offset_x->m_shift))) + v21;
          goto LABEL_40;
        case 35:
        case 36:
        case 37:
          v17 = v6 - 35;
          v23 = *(&p_m_offset_x->m_offset_x + v17);
          v15 = _mm_cvtsi32_si128(v23 + (v5 << (16 - LOBYTE(p_m_offset_x->m_shift))));
          v19 = _mm_cvtsi32_si128(v23 + (v4 << (16 - LOBYTE(p_m_offset_x->m_shift))));
          v16 = *((unsigned __int8 *)v3 + 4) + (v54 << 8);
          v24 = *((unsigned __int8 *)v3 + 6) + (*((unsigned __int8 *)v3 + 5) << 8);
          v18 = v3 + 7;
          v55 = v24;
LABEL_39:
          LODWORD(v21) = _mm_cvtepi32_ps(v19).m128_u32[0];
          LODWORD(v22) = _mm_cvtepi32_ps(v15).m128_u32[0];
LABEL_40:
          v25 = v21 * this->m_ItoFScale;
          v26 = v17;
          v62 = v16;
          v27 = 2 * v17;
          v28 = *((_DWORD *)&this->m_kdop.m_hx + 2 * v17);
          v60 = &v18[v16];
          *(&this->m_kdop.m_hx + v27) = v22 * this->m_ItoFScale;
          hkpMoppKDopGeometriesVirtualMachine::queryMoppKDopGeometriesRecurse(this, querya, v60);
          *((_DWORD *)&this->m_kdop.m_hx + v27) = v28;
          v29 = *((_DWORD *)&this->m_kdop.m_lx + 2 * v26);
          *(&this->m_kdop.m_lx + v27) = v25;
          hkpMoppKDopGeometriesVirtualMachine::queryMoppKDopGeometriesRecurse(this, querya, &v60[-(v62 - v55)]);
          *((_DWORD *)&this->m_kdop.m_lx + v27) = v29;
          return;
        case 38:
        case 39:
        case 40:
          v30 = v6 - 38;
          v31 = v6 - 38;
          v63 = v30;
          v47 = v31;
          m_kdopDepth = this->m_queryObject.m_kdopDepth;
          v33 = (float)(*(&p_m_offset_x->m_offset_x + v31) + (v5 << (16 - LOBYTE(p_m_offset_x->m_shift))))
              * this->m_ItoFScale;
          v34 = (float)(*(&p_m_offset_x->m_offset_x + v31) + (v4 << (16 - LOBYTE(p_m_offset_x->m_shift))))
              * this->m_ItoFScale;
          if ( m_kdopDepth && this->m_level >= m_kdopDepth )
          {
            v56 = 0;
          }
          else
          {
            v56 = 1;
            hkpMoppKDopGeometriesVirtualMachine::pushKDop(this, 0, 0xFFFFFFFF);
            v3 = v59;
            v31 = v47;
          }
          v35 = *((_DWORD *)&this->m_kdop.m_lx + 2 * v31);
          v36 = *((_DWORD *)&this->m_kdop.m_hx + 2 * v31);
          v37 = 2 * v63;
          *(&this->m_kdop.m_lx + v37) = v33;
          *(&this->m_kdop.m_hx + v37) = v34;
          ++this->m_level;
          hkpMoppKDopGeometriesVirtualMachine::queryMoppKDopGeometriesRecurse(this, p_m_offset_x, v3 + 3);
          --this->m_level;
          if ( v56 && this->m_queryObject.m_useSpecifiedID.m_bool && !this->m_hitFound.m_bool )
            goto LABEL_55;
          goto LABEL_56;
        case 41:
        case 42:
        case 43:
          v38 = v5;
          v39 = v6 - 41;
          v40 = this->m_queryObject.m_kdopDepth;
          v41 = (float)(v54 + ((v4 + (v38 << 8)) << 8)) * this->m_ItoFScale;
          v42 = (float)(*((unsigned __int8 *)v3 + 6)
                      + ((*((unsigned __int8 *)v3 + 5) + (*((unsigned __int8 *)v3 + 4) << 8)) << 8))
              * this->m_ItoFScale;
          if ( v40 && this->m_level >= v40 )
          {
            v57 = 0;
          }
          else
          {
            v57 = 1;
            hkpMoppKDopGeometriesVirtualMachine::pushKDop(this, 0, 0xFFFFFFFF);
            v3 = v59;
          }
          v35 = *((_DWORD *)&this->m_kdop.m_lx + 2 * v39);
          v36 = *((_DWORD *)&this->m_kdop.m_hx + 2 * v39);
          v37 = 2 * v39;
          *(&this->m_kdop.m_lx + v37) = v41;
          *(&this->m_kdop.m_hx + v37) = v42;
          ++this->m_level;
          hkpMoppKDopGeometriesVirtualMachine::queryMoppKDopGeometriesRecurse(this, p_m_offset_x, v3 + 7);
          --this->m_level;
          if ( v57 && this->m_queryObject.m_useSpecifiedID.m_bool )
LABEL_55:
            --this->m_kDopGeometries;
LABEL_56:
          *((_DWORD *)&this->m_kdop.m_lx + v37) = v35;
          *((_DWORD *)&this->m_kdop.m_hx + v37) = v36;
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
          v43 = v6 - 48;
          goto LABEL_61;
        case 80:
          v43 = v5;
LABEL_61:
          this->m_terminaloffset = v43;
          goto $add_Terminal_13;
        case 81:
          this->m_terminaloffset = v4 + (v5 << 8);
          goto $add_Terminal_13;
        case 82:
          this->m_terminaloffset = v54 + (v4 << 8) + (v5 << 16);
$add_Terminal_13:
          this->m_terminaloffset += p_m_offset_x->m_primitiveOffset;
          hkpMoppKDopGeometriesVirtualMachine::addHit(this, this->m_terminaloffset, p_m_offset_x->m_properties);
          this->m_terminaloffset = -1;
          return;
        case 96:
        case 97:
        case 98:
        case 99:
          v3 = v45;
          *(&v53 + (unsigned int)(v44 - 96)) = v5;
          goto LABEL_21;
        case 100:
        case 101:
        case 102:
        case 103:
          v3 = v46;
          v13 = v4 + (v5 << 8);
          v14 = (unsigned int)(v44 - 100);
          goto LABEL_20;
        case 104:
        case 105:
        case 106:
        case 107:
          v13 = *((unsigned __int8 *)v3 + 4) + (v5 << 24) + (v4 << 16) + (v54 << 8);
          v14 = (unsigned int)*(unsigned __int8 *)v3 - 104;
          v3 += 5;
LABEL_20:
          *(&v53 + v14) = v13;
LABEL_21:
          v59 = v3;
          if ( p_m_offset_x == (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x )
          {
            m_primitiveOffset = v52;
          }
          else
          {
            m_offset_x = p_m_offset_x->m_offset_x;
            m_offset_y = p_m_offset_x->m_offset_y;
            m_offset_z = p_m_offset_x->m_offset_z;
            m_shift = p_m_offset_x->m_shift;
            m_primitiveOffset = p_m_offset_x->m_primitiveOffset;
            v52 = m_primitiveOffset;
            p_m_offset_x = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x;
            querya = (hkpMoppKDopGeometriesVirtualMachine::hkpMoppKDopGeometriesVirtualMachineQuery *)&m_offset_x;
          }
          break;
        default:
          __debugbreak();
          break;
      }
      v4 = v3[2];
      v5 = v3[1];
      v44 = *(unsigned __int8 *)v3;
      v6 = v44;
      v54 = v3[3];
      v61 = v4;
      v45 = v3 + 2;
      v46 = v3 + 3;
    }
  }
}__int8 *)v3;
      v6 = v44;
      v54 = v3[3];
      v61 = v4;
      v45 = v3 + 2;
      v46 = v3 + 3;
    }
  }
}

