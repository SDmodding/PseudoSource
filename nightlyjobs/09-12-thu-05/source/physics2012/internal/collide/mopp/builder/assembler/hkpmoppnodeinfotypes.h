// File Line: 104
// RVA: 0xDFE440
void __fastcall hkpMoppAssemblerNodeInfo::updateExtents(hkpMoppAssemblerNodeInfo *this, hkpMoppTreeNode *node, hkpMoppCode::CodeInfo *codeInfo)
{
  signed __int64 v3; // r10
  int (*v4)[2]; // r9
  signed __int64 v5; // rdx
  float v6; // xmm0_4
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  __m128i v9; // xmm3
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  unsigned int v12; // [rsp+20h] [rbp+20h]

  v3 = 0i64;
  v4 = this->m_extents;
  v5 = (char *)node - (char *)this;
  do
  {
    v6 = *(float *)((char *)&(*v4)[1] + v5) - codeInfo->m_offset.m_quad.m128_f32[++v3 - 1];
    ++v4;
    *(float *)&v12 = v6 * codeInfo->m_offset.m_quad.m128_f32[3];
    v7 = _mm_sub_ps(
           _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v12, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
           *(__m128 *)two23);
    v8 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32((__m128i)v12, 1u), 1u));
    (*v4)[-2] = (signed int)COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                                  v8,
                                                                  _mm_add_ps(
                                                                    _mm_cvtepi32_ps((__m128i)_mm_cmpltps(
                                                                                               (__m128)v12,
                                                                                               v7)),
                                                                    v7)) | v8.m128_i32[0] & v12);
    v9 = (__m128i)COERCE_UNSIGNED_INT(
                    (float)(*(float *)((char *)v4 + v5) - codeInfo->m_offset.m_quad.m128_f32[v3 - 1])
                  * codeInfo->m_offset.m_quad.m128_f32[3]);
    v10 = _mm_sub_ps(
            _mm_add_ps(_mm_add_ps(_mm_sub_ps((__m128)v9, *(__m128 *)two23), *(__m128 *)two23), *(__m128 *)two23),
            *(__m128 *)two23);
    v11 = _mm_cmpltps(*(__m128 *)two23, (__m128)_mm_srli_epi32(_mm_slli_epi32(v9, 1u), 1u));
    (*v4)[-1] = (signed int)COERCE_FLOAT(*(unsigned __int128 *)&_mm_andnot_ps(
                                                                  v11,
                                                                  _mm_add_ps(
                                                                    _mm_cvtepi32_ps((__m128i)_mm_cmpltps(
                                                                                               (__m128)v9,
                                                                                               v10)),
                                                                    v10)) | v11.m128_i32[0] & v9.m128i_i32[0])
              + 1;
  }
  while ( v3 < 3 );
}

// File Line: 145
// RVA: 0xDFE3C0
void __fastcall hkpMoppAssemblerNodeInfo::calcMaxExtentsSignificantBits(hkpMoppAssemblerNodeInfo *this)
{
  int v1; // edx
  hkpMoppAssemblerNodeInfo *v2; // r10
  int v3; // er8
  char v4; // cl
  unsigned int v5; // eax
  signed int v6; // edx
  signed __int64 v7; // r9
  int v8; // er8
  signed int v9; // ecx
  unsigned int v10; // eax

  v1 = this->m_extents[1][1] - this->m_extents[1][0];
  v2 = this;
  if ( this->m_extents[0][1] - this->m_extents[0][0] > v1 )
    v1 = this->m_extents[0][1] - this->m_extents[0][0];
  v3 = this->m_extents[2][1] - this->m_extents[2][0];
  if ( v1 > v3 )
    v3 = v1;
  v4 = 0;
  v5 = v3;
  if ( v3 )
  {
    do
    {
      ++v4;
      v5 >>= 1;
    }
    while ( v5 );
  }
  v6 = -1;
  v7 = 3i64;
  v8 = __ROR4__(__ROL4__(1, v4), 4) + v3;
  do
  {
    v9 = 0;
    v10 = v8;
    if ( v8 )
    {
      do
      {
        ++v9;
        v10 >>= 1;
      }
      while ( v10 );
    }
    if ( v9 > v6 )
      v6 = v9;
    --v7;
  }
  while ( v7 );
  if ( v6 > 24 )
    v6 = 24;
  v2->m_maxExtentsSignificantBits = v6;
}

// File Line: 159
// RVA: 0xDFDEE0
void __fastcall hkpMoppAssemblerNodeInfo::hkpMoppAssemblerNodeInfo(hkpMoppAssemblerNodeInfo *this, hkpMoppAssemblerNodeInfo *parentInfo, hkpMoppTreeNode *node, hkpMoppCode::CodeInfo *codeInfo)
{
  hkpMoppTreeNode *v4; // r10
  hkpMoppCode::CodeInfo *v5; // rsi
  hkpMoppAssemblerNodeInfo *v6; // rdi
  hkpMoppAssemblerNodeInfo *v7; // rbx
  int v8; // eax
  int v9; // er8
  char *v10; // rcx
  unsigned int *v11; // rax
  signed __int64 v12; // r9
  signed __int64 v13; // r11
  unsigned int v14; // ecx

  v4 = node;
  v5 = codeInfo;
  this->m_level = parentInfo->m_level;
  v6 = parentInfo;
  *(_DWORD *)&this->m_ignoreBandControlCode.m_bool = *(_DWORD *)&parentInfo->m_ignoreBandControlCode.m_bool;
  v7 = this;
  this->m_maxExtentsSignificantBits = parentInfo->m_maxExtentsSignificantBits;
  this->m_extents[0][0] = parentInfo->m_extents[0][0];
  this->m_extents[0][1] = parentInfo->m_extents[0][1];
  this->m_extents[1][0] = parentInfo->m_extents[1][0];
  this->m_extents[1][1] = parentInfo->m_extents[1][1];
  this->m_extents[2][0] = parentInfo->m_extents[2][0];
  this->m_extents[2][1] = parentInfo->m_extents[2][1];
  this->m_currentBitsResolution = parentInfo->m_currentBitsResolution;
  this->m_accumOffset[0] = parentInfo->m_accumOffset[0];
  this->m_accumOffset[1] = parentInfo->m_accumOffset[1];
  this->m_accumOffset[2] = parentInfo->m_accumOffset[2];
  this->m_terminalOffset = parentInfo->m_terminalOffset;
  this->m_terminalSpread = parentInfo->m_terminalSpread;
  this->m_numProperties = parentInfo->m_numProperties;
  this->m_propertiesOffset[0] = parentInfo->m_propertiesOffset[0];
  this->m_propertiesSpread[0] = parentInfo->m_propertiesSpread[0];
  this->m_terminalSpread = node->m_maxPrimitiveId - node->m_minPrimitiveId;
  v8 = node->m_numProperties;
  v9 = 0;
  this->m_numProperties = v8;
  if ( v4->m_numProperties > 0 )
  {
    v10 = (char *)((char *)this - (char *)v4);
    v11 = v4->m_minPropertyValue;
    v12 = (signed __int64)(v10 + 8);
    v13 = (signed __int64)(v10 + 16);
    do
    {
      v14 = *v11;
      ++v9;
      ++v11;
      *(unsigned int *)((char *)v11 + v12) = v14;
      *(unsigned int *)((char *)v11 + v13 - 4) = *v11 - *(v11 - 1);
    }
    while ( v9 < v4->m_numProperties );
  }
  hkpMoppAssemblerNodeInfo::updateExtents(v7, v4, v5);
  v7->m_level = v6->m_level + 1;
  v7->m_ignoreBandControlCode.m_bool = 0;
  hkpMoppAssemblerNodeInfo::calcMaxExtentsSignificantBits(v7);
}

