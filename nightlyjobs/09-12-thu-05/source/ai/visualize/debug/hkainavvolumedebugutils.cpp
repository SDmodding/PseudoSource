// File Line: 43
// RVA: 0xC4BBC0
void __fastcall hkaiNavVolumeDebugUtils::DebugInfo::DebugInfo(hkaiNavVolumeDebugUtils::DebugInfo *this)
{
  this->m_transparency = 0.69999999;
  this->m_shrinkCells.m_bool = 0;
  *(_DWORD *)&this->m_showCells.m_bool = 1;
  *(_DWORD *)&this->m_labelCells.m_bool = 0x10000;
  this->m_regionMap = 0i64;
  this->m_numMaterialColors = 0;
  this->m_materialColors = 0i64;
  this->m_showCellData.m_bool = 0;
  this->m_cellColor = hkColor::ORANGE;
  this->m_cellBorderColor = hkColor::WHITE;
  this->m_internalEdgeColor = hkColor::BLUE;
  *(_QWORD *)&this->m_showSingleRegionIndex = -1i64;
  this->m_externalEdgeColor = hkColor::CYAN;
  this->m_sliceAxis = 2;
  this->m_instanceEnabled.m_storage.m_words.m_data = 0i64;
  this->m_instanceEnabled.m_storage.m_words.m_size = 0;
  this->m_instanceEnabled.m_storage.m_words.m_capacityAndFlags = 2147483648;
  this->m_instanceEnabled.m_storage.m_numBits = 0;
  this->m_displayOffset = 0i64;
}

// File Line: 48
// RVA: 0xC4BC40
void __fastcall hkaiNavVolumeDebugUtils::showNavVolume(hkaiNavVolumeDebugUtils::DebugInfo *settings, hkaiNavVolume *navVolume)
{
  hkaiNavVolumeDebugUtils::DebugInfo *v2; // rdi
  hkaiNavVolume *v3; // rbx
  hkaiNavVolumeInstance navVolumea; // [rsp+20h] [rbp-88h]

  v2 = settings;
  v3 = navVolume;
  hkaiNavVolumeInstance::hkaiNavVolumeInstance(&navVolumea);
  hkaiNavVolumeInstance::tempInit(&navVolumea, v3);
  hkaiNavVolumeDebugUtils::showNavVolume(v2, &navVolumea);
  hkaiNavVolumeInstance::~hkaiNavVolumeInstance(&navVolumea);
}

// File Line: 55
// RVA: 0xC4BCA0
void __fastcall hkaiNavVolumeDebugUtils::showNavVolume(hkaiNavVolumeDebugUtils::DebugInfo *settings, hkaiNavVolumeInstance *navVolume)
{
  hkaiNavVolumeDebugUtils::DebugInfo *v2; // rdi
  hkaiNavVolumeInstance *v3; // rbx
  int v4; // er9
  hkaiStreamingCollection::InstanceInfo *v5; // rax
  __int64 v6; // rdx
  hkaiDirectedGraphInstance **v7; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-38h]
  hkResult result; // [rsp+78h] [rbp+10h]

  v2 = settings;
  v3 = navVolume;
  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) < 1 )
  {
    v4 = 1;
    if ( 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) > 1 )
      v4 = 2 * (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF);
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &array.m_instances,
      v4,
      48);
  }
  v5 = array.m_instances.m_data;
  v6 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    v7 = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( v7 != (hkaiDirectedGraphInstance **)16 )
      {
        *(v7 - 2) = 0i64;
        *(v7 - 1) = 0i64;
        *v7 = 0i64;
        v7[1] = 0i64;
        v7[2] = 0i64;
        *((_DWORD *)v7 + 6) = -1;
      }
      v7 += 6;
      --v6;
    }
    while ( v6 );
    v5 = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  v5->m_volumeInstancePtr = v3;
  array.m_instances.m_data->m_volumeMediator = 0i64;
  hkaiNavVolumeDebugUtils::showNavVolumeCollection(v2, &array);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
}

// File Line: 63
// RVA: 0xC4BDA0
void __usercall hkaiNavVolumeDebugUtils::showNavVolumeCollection(hkaiNavVolumeDebugUtils::DebugInfo *info@<rcx>, hkaiStreamingCollection *collection@<rdx>, __int64 a3@<rsi>)
{
  hkaiStreamingCollection *v3; // r8
  hkaiNavVolumeDebugUtils::DebugInfo *v4; // rbx
  int v5; // er12
  hkPseudoRandomGenerator v6; // r9
  __m128 *v7; // rsi
  bool v8; // zf
  __m128 *v9; // rax
  __m128 v10; // xmm1
  hkVector4f v11; // xmm2
  hkVector4f v12; // xmm1
  void **v13; // r14
  signed int v14; // er9
  int v15; // edi
  int v16; // er9
  hkaiNavVolume *v17; // rcx
  unsigned __int16 v18; // r15
  unsigned __int16 v19; // dx
  __int64 v20; // r10
  unsigned __int16 *v21; // r8
  unsigned __int16 v22; // ax
  int v23; // er13
  unsigned __int64 v24; // rcx
  __int64 v25; // r8
  unsigned int v26; // edx
  __m128i *v27; // rdi
  int v28; // ecx
  int v29; // ecx
  int v30; // eax
  int v31; // ecx
  unsigned int v32; // eax
  unsigned int v33; // er14
  __int64 v34; // rcx
  int v35; // eax
  signed int v36; // eax
  hkVector4f v37; // xmm7
  __m128i v38; // xmm2
  __m128 v39; // xmm6
  __m128i v40; // xmm0
  hkVector4f v41; // xmm6
  hkaiNavVolume *v42; // rcx
  __m128 *v43; // rax
  __m128i v44; // xmm3
  __m128 *v45; // rax
  signed int v46; // er15
  __m128i v47; // xmm1
  __m128i v48; // xmm3
  __m128i v49; // xmm1
  __m128 v50; // xmm0
  __m128 v51; // xmm9
  __m128 v52; // xmm8
  __m128 v53; // xmm10
  float v54; // ecx
  int v55; // er14
  unsigned __int64 v56; // rax
  __int64 v57; // rcx
  int v58; // er8
  unsigned int v59; // eax
  unsigned int v60; // er9
  __int64 v61; // r10
  __m128 *v62; // rdx
  __m128i v63; // xmm2
  __m128 *v64; // rax
  __m128i v65; // xmm1
  __m128i v66; // xmm2
  __m128i v67; // xmm1
  __m128 v68; // xmm0
  __m128 v69; // xmm6
  __m128 v70; // xmm7
  unsigned int v71; // er9
  __m128 v72; // xmm2
  __m128 v73; // xmm1
  void **v74; // [rsp+30h] [rbp-B8h]
  void *array; // [rsp+38h] [rbp-B0h]
  int v76; // [rsp+40h] [rbp-A8h]
  int v77; // [rsp+44h] [rbp-A4h]
  __m128i v78; // [rsp+48h] [rbp-A0h]
  __int64 v79; // [rsp+58h] [rbp-90h]
  __int64 v80; // [rsp+60h] [rbp-88h]
  hkPseudoRandomGenerator rand[2]; // [rsp+68h] [rbp-80h]
  hkVector4f pos; // [rsp+78h] [rbp-70h]
  hkVector4f start; // [rsp+88h] [rbp-60h]
  hkStringBuf v84; // [rsp+98h] [rbp-50h]
  hkVector4f end; // [rsp+128h] [rbp+40h]
  hkVector4f scale; // [rsp+138h] [rbp+50h]
  hkVector4f offset; // [rsp+148h] [rbp+60h]
  hkAabb aabb; // [rsp+158h] [rbp+70h]
  hkAabb _aabb; // [rsp+178h] [rbp+90h]
  hkStringBuf v90; // [rsp+198h] [rbp+B0h]
  hkaiStreamingCollection *vars0; // [rsp+2E0h] [rbp+1F8h]
  unsigned __int16 retaddr; // [rsp+2E8h] [rbp+200h]
  __int64 result; // [rsp+2F0h] [rbp+208h]
  hkaiStreamingCollection *v94; // [rsp+2F8h] [rbp+210h]

  v94 = collection;
  v3 = collection;
  v4 = info;
  v5 = 0;
  if ( collection->m_instances.m_size > 0 )
  {
    result = a3;
    v6 = 0i64;
    rand[0] = 0i64;
    do
    {
      if ( v5 >= v4->m_instanceEnabled.m_storage.m_numBits
        || (v4->m_instanceEnabled.m_storage.m_words.m_data[(signed __int64)v5 >> 5] >> (v5 & 0x1F)) & 1 )
      {
        v7 = *(__m128 **)((char *)&v3->m_instances.m_data->m_volumeInstancePtr + *(_QWORD *)&v6);
        if ( v7 )
        {
          v8 = v4->m_showAabb.m_bool == 0;
          v9 = (__m128 *)v7[3].m128_u64[0];
          v10 = v7[7];
          v11.m_quad = _mm_add_ps(v9[4], v10);
          v12.m_quad = _mm_add_ps(v10, v9[5]);
          aabb.m_max = (hkVector4f)v12.m_quad;
          aabb.m_min = (hkVector4f)v11.m_quad;
          if ( !v8 && !(_mm_movemask_ps(_mm_cmpleps(v12.m_quad, v11.m_quad)) & 7) )
            hkDebugDisplay::displayAabb(
              hkSingleton<hkDebugDisplay>::s_instance,
              &aabb,
              hkColor::WHITE,
              0,
              (int)hkDebugDisplayProcess::m_tag);
          v13 = (void **)&v4->m_regionMap->m_data;
          v14 = 2147483648;
          array = 0i64;
          v76 = 0;
          v77 = 2147483648;
          v74 = v13;
          if ( !v13 || *((_DWORD *)v13 + 2) != v7[1].m128_i32[2] )
          {
            if ( v4->m_colorRegions.m_bool || v4->m_showSingleRegionIndex != -1 )
            {
              v15 = v7[1].m128_i32[2];
              if ( v15 <= 0 )
              {
                LODWORD(result) = 0;
              }
              else
              {
                v16 = v7[1].m128_i32[2];
                if ( v15 < 0 )
                  v16 = 0;
                hkArrayUtil::_reserve(
                  (hkResult *)&result,
                  (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                  &array,
                  v16,
                  4);
              }
              v17 = (hkaiNavVolume *)v7[3].m128_u64[0];
              v76 = v15;
              hkaiNavVolumeUtils::computeRegions(v17, (hkArrayBase<int> *)&array);
              v14 = v77;
            }
            v13 = &array;
            v74 = &array;
          }
          v18 = v4->m_showSingleSliceIndex;
          v19 = -1;
          retaddr = v4->m_showSingleSliceIndex;
          if ( v4->m_showSingleSliceIndex != -1 )
          {
            v20 = v7[1].m128_i32[2];
            if ( v20 > 0 )
            {
              v21 = (unsigned __int16 *)(v7[1].m128_u64[0] + 2i64 * v4->m_sliceAxis);
              do
              {
                v22 = *v21;
                v21 += 12;
                if ( v19 < v22 )
                  v22 = v19;
                v19 = v22;
                --v20;
              }
              while ( v20 );
            }
            v18 += v19;
            retaddr = v18;
          }
          v23 = 0;
          if ( v7[1].m128_i32[2] > 0 )
          {
            v24 = 0i64;
            v25 = 0i64;
            v80 = 0i64;
            pos.m_quad.m128_u64[0] = 0i64;
            while ( 2 )
            {
              v26 = v4->m_cellColor;
              v27 = (__m128i *)(v24 + v7[1].m128_u64[0]);
              v28 = v4->m_showSingleRegionIndex;
              if ( v28 != -1 && *((_DWORD *)v13 + 2) && *(_DWORD *)((char *)*v13 + v25) != v28 )
                goto LABEL_77;
              if ( v4->m_colorCellsRandomly.m_bool )
              {
                v29 = 179 * WORD2(v27->m128i_i64[0]) + 764543 * WORD1(v27->m128i_i64[0]);
                v30 = 12345 * LOWORD(v27->m128i_i64[0]);
                rand[1].m_seed = v30 + v29;
                rand[1].m_current = v30 + v29;
                v26 = hkColor::getRandomColor(&rand[1]);
              }
              if ( v4->m_colorRegions.m_bool && *((_DWORD *)v13 + 2) == v7[1].m128_i32[2] )
                v26 = hkColor::getPaletteColor(*(_DWORD *)((char *)*v13 + v80), 255);
              v31 = v4->m_numMaterialColors;
              if ( v31 > 0 )
                v26 = v4->m_materialColors[v27[1].m128i_i32[1] % v31];
              v32 = hkColor::rgbFromFloats(
                      (float)BYTE2(v26) * 0.0039215689,
                      (float)BYTE1(v26) * 0.0039215689,
                      (float)(unsigned __int8)v26 * 0.0039215689,
                      (float)((float)(v26 >> 24) * 0.0039215689) * v4->m_transparency);
              v8 = v4->m_showSingleSliceIndex == -1;
              *(__int64 *)((char *)v78.m128i_i64 + 2) = 0i64;
              v78.m128i_i16[0] = 0;
              *(int *)((char *)&v78.m128i_i32[2] + 2) = 0;
              v33 = v32;
              v79 = 0i64;
              if ( v8 )
              {
LABEL_43:
                v36 = LOWORD(v27->m128i_i64[0]);
                v90.m_string.m_capacityAndFlags = -2147483520;
                v90.m_string.m_size = 1;
                v90.m_string.m_storage[0] = 0;
                v37.m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)COERCE_UNSIGNED_INT((float)v36),
                                 (__m128)COERCE_UNSIGNED_INT((float)WORD2(v27->m128i_i64[0]))),
                               _mm_unpacklo_ps(
                                 (__m128)COERCE_UNSIGNED_INT((float)WORD1(v27->m128i_i64[0])),
                                 (__m128)0i64));
                v38 = _mm_cvtsi32_si128(WORD1(v27->m128i_i64[1]));
                v39 = (__m128)COERCE_UNSIGNED_INT((float)LOWORD(v27->m128i_i64[1]));
                v40 = _mm_cvtsi32_si128(WORD2(v27->m128i_i64[1]));
                _aabb.m_min = (hkVector4f)v37.m_quad;
                v90.m_string.m_data = v90.m_string.m_storage;
                v41.m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(v39, _mm_cvtepi32_ps(v40)),
                               _mm_unpacklo_ps(_mm_cvtepi32_ps(v38), (__m128)0i64));
                _aabb.m_max = (hkVector4f)v41.m_quad;
                if ( v4->m_labelCells.m_bool )
                  hkStringBuf::printf(&v90, "%d(%d) ", (unsigned int)v23, (unsigned int)SHIWORD(v27->m128i_i64[0]));
                if ( v4->m_showCellData.m_bool )
                {
                  if ( v27[1].m128i_i32[1] )
                  {
                    v84.m_string.m_capacityAndFlags = -2147483520;
                    v84.m_string.m_size = 1;
                    v84.m_string.m_storage[0] = 0;
                    v84.m_string.m_data = v84.m_string.m_storage;
                    hkStringBuf::printf(&v84, "[%d]");
                    hkStringBuf::operator+=(&v90, v84.m_string.m_data);
                    v84.m_string.m_size = 0;
                    if ( v84.m_string.m_capacityAndFlags >= 0 )
                      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                        v84.m_string.m_data,
                        v84.m_string.m_capacityAndFlags & 0x3FFFFFFF);
                  }
                }
                if ( v90.m_string.m_size - 1 > 0 )
                {
                  v42 = (hkaiNavVolume *)v7[3].m128_u64[0];
                  *(__m128 *)&rand[0].m_seed = _mm_mul_ps(_mm_add_ps(v41.m_quad, v37.m_quad), (__m128)xmmword_141A711B0);
                  hkaiNavVolume::convertPointToWorld(v42, (hkVector4f *)rand);
                  *(__m128 *)&rand[0].m_seed = _mm_add_ps(*(__m128 *)&rand[0].m_seed, v4->m_displayOffset.m_quad);
                  hkDebugDisplay::display3dText(
                    hkSingleton<hkDebugDisplay>::s_instance,
                    v90.m_string.m_data,
                    (hkVector4f *)rand,
                    hkColor::ORANGE,
                    0,
                    (int)hkDebugDisplayProcess::m_tag);
                }
                v90.m_string.m_size = 0;
                if ( v90.m_string.m_capacityAndFlags >= 0 )
                  hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                    (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                    v90.m_string.m_data,
                    v90.m_string.m_capacityAndFlags & 0x3FFFFFFF);
                v43 = (__m128 *)v7[3].m128_u64[0];
                offset.m_quad = _mm_add_ps(v43[7], v7[7]);
                scale.m_quad = v43[6];
                hkaiNavVolumeDebugUtils::showCellAabb(v4, &_aabb, &offset, &scale, v33);
                if ( v4->m_showEdgeConnections.m_bool || v4->m_labelEdges.m_bool )
                {
                  v44 = _mm_loadu_si128(v27);
                  v45 = (__m128 *)v7[3].m128_u64[0];
                  v46 = 0;
                  v47 = v44;
                  v48 = _mm_unpackhi_epi16(v44, (__m128i)0i64);
                  v49 = _mm_unpacklo_epi16(v47, (__m128i)0i64);
                  v50 = _mm_add_ps(v45[7], v7[7]);
                  v51 = _mm_add_ps(
                          _mm_mul_ps(
                            v45[6],
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(_mm_srli_epi32(v49, 0x10u)),
                                (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v49, 0x10u), 0x10u)))),
                          v50);
                  v52 = _mm_add_ps(
                          _mm_mul_ps(
                            v45[6],
                            _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(_mm_srli_epi32(v48, 0x10u)),
                                (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v48, 0x10u), 0x10u)))),
                          v50);
                  if ( SHIWORD(v27->m128i_i64[0]) > 0 )
                  {
                    v53 = _mm_add_ps(v52, v51);
                    do
                    {
                      v54 = v7[2].m128_f32[2];
                      v55 = v46 + v27[1].m128i_i32[0];
                      if ( v55 >= SLODWORD(v54) )
                      {
                        v57 = v55 - LODWORD(v54);
                        v56 = v7[5].m128_u64[1];
                      }
                      else
                      {
                        v56 = v7[2].m128_u64[0];
                        v57 = v55;
                      }
                      v58 = *(_DWORD *)(v56 + 8 * v57 + 4);
                      if ( *(_BYTE *)(v56 + 8 * v57) & 0x40 )
                        v59 = v58 & 0xFFC00000;
                      else
                        v59 = v7[6].m128_i32[3] << 22;
                      v60 = v59 | v58 & 0x3FFFFF;
                      if ( v58 == -1 )
                        v60 = -1;
                      v61 = v60 >> 22;
                      v8 = v4->m_showEdgeConnections.m_bool == 0;
                      v62 = (__m128 *)vars0->m_instances.m_data[v61].m_volumeInstancePtr;
                      v63 = _mm_loadu_si128((const __m128i *)(v62[1].m128_u64[0] + 24i64 * (v58 & 0x3FFFFF)));
                      v64 = (__m128 *)v62[3].m128_u64[0];
                      v65 = v63;
                      v66 = _mm_unpackhi_epi16(v63, (__m128i)0i64);
                      v67 = _mm_unpacklo_epi16(v65, (__m128i)0i64);
                      v68 = _mm_add_ps(v64[7], v62[7]);
                      v69 = _mm_add_ps(
                              _mm_mul_ps(
                                v64[6],
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_cvtepi32_ps(_mm_srli_epi32(v66, 0x10u)),
                                    (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                                  _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v66, 0x10u), 0x10u)))),
                              v68);
                      v70 = _mm_add_ps(
                              _mm_mul_ps(
                                v64[6],
                                _mm_add_ps(
                                  _mm_mul_ps(
                                    _mm_cvtepi32_ps(_mm_srli_epi32(v67, 0x10u)),
                                    (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                                  _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v67, 0x10u), 0x10u)))),
                              v68);
                      start.m_quad = _mm_add_ps(_mm_mul_ps(v53, (__m128)xmmword_141A711B0), v4->m_displayOffset.m_quad);
                      end.m_quad = _mm_add_ps(
                                     _mm_mul_ps(_mm_add_ps(v69, v70), (__m128)xmmword_141A711B0),
                                     v4->m_displayOffset.m_quad);
                      if ( !v8 && (v23 | (unsigned int)(v5 << 22)) < v60 )
                      {
                        if ( (_DWORD)v61 == v5 )
                          v71 = v4->m_internalEdgeColor;
                        else
                          v71 = v4->m_externalEdgeColor;
                        hkDebugDisplay::displayLine(
                          hkSingleton<hkDebugDisplay>::s_instance,
                          &start,
                          &end,
                          v71,
                          0,
                          (int)hkDebugDisplayProcess::m_tag);
                      }
                      if ( v4->m_labelEdges.m_bool )
                      {
                        v72 = _mm_max_ps(v51, v70);
                        v73 = _mm_min_ps(v52, v69);
                        v84.m_string.m_data = v84.m_string.m_storage;
                        v84.m_string.m_capacityAndFlags = -2147483520;
                        v84.m_string.m_size = 1;
                        v84.m_string.m_storage[0] = 0;
                        pos.m_quad = _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_add_ps(_mm_max_ps(v72, v73), _mm_min_ps(v72, v73)),
                                         (__m128)xmmword_141A711B0),
                                       v4->m_displayOffset.m_quad);
                        hkStringBuf::printf(&v84, "%d", (unsigned int)v55);
                        pos.m_quad = _mm_add_ps(
                                       pos.m_quad,
                                       _mm_mul_ps(_mm_sub_ps(start.m_quad, pos.m_quad), (__m128)xmmword_141A711B0));
                        hkDebugDisplay::display3dText(
                          hkSingleton<hkDebugDisplay>::s_instance,
                          v84.m_string.m_data,
                          &pos,
                          hkColor::RED,
                          0,
                          (int)hkDebugDisplayProcess::m_tag);
                        v84.m_string.m_size = 0;
                        if ( v84.m_string.m_capacityAndFlags >= 0 )
                          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                            (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                            v84.m_string.m_data,
                            v84.m_string.m_capacityAndFlags & 0x3FFFFFFF);
                      }
                      ++v46;
                    }
                    while ( v46 < SHIWORD(v27->m128i_i64[0]) );
                  }
                  v18 = retaddr;
                }
              }
              else
              {
                v34 = v4->m_sliceAxis;
                if ( *((_WORD *)v27->m128i_i64 + v34) <= v18 && *((_WORD *)&v27->m128i_i64[1] + v34) > v18 )
                {
                  v78 = *v27;
                  LODWORD(v79) = v27[1].m128i_i32[0];
                  v35 = v27[1].m128i_i32[1];
                  v27 = &v78;
                  HIDWORD(v79) = v35;
                  v78.m128i_i16[v34] = v18;
                  v78.m128i_i16[v34 + 4] = v18 + 1;
                  goto LABEL_43;
                }
              }
              v13 = v74;
LABEL_77:
              v80 += 4i64;
              ++v23;
              v25 = v80;
              v24 = pos.m_quad.m128_u64[0] + 24;
              pos.m_quad.m128_u64[0] += 24i64;
              if ( v23 >= v7[1].m128_i32[2] )
              {
                v14 = v77;
                break;
              }
              continue;
            }
          }
          v76 = 0;
          if ( v14 >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
              array,
              4 * v14);
          v3 = vars0;
          v6 = rand[0];
          array = 0i64;
          v77 = 2147483648;
        }
      }
      *(_QWORD *)&v6 += 48i64;
      ++v5;
      rand[0] = v6;
    }
    while ( v5 < v3->m_instances.m_size );
  }
}

// File Line: 258
// RVA: 0xC4C730
void __fastcall hkaiNavVolumeDebugUtils::showCell(hkaiNavVolumeDebugUtils::DebugInfo *info, hkaiNavVolume *navVolume, int cellIndex, unsigned int color)
{
  bool v4; // zf
  hkaiNavVolume::Cell *v5; // r10
  __m128 v6; // xmm0
  unsigned int v7; // esi
  unsigned int v8; // ebx
  hkaiNavVolumeDebugUtils::DebugInfo *v9; // rdi
  signed int v10; // eax
  __m128 v11; // xmm0
  unsigned int v12; // eax
  hkVector4f pointInOut; // [rsp+30h] [rbp-E8h]
  hkVector4f offset; // [rsp+40h] [rbp-D8h]
  hkVector4f scale; // [rsp+50h] [rbp-C8h]
  hkAabb _aabb; // [rsp+60h] [rbp-B8h]
  hkStringBuf v17; // [rsp+80h] [rbp-98h]

  v4 = info->m_labelCells.m_bool == 0;
  v5 = navVolume->m_cells.m_data;
  v6 = navVolume->m_quantizationOffset.m_quad;
  scale.m_quad = (__m128)navVolume->m_quantizationScale;
  v7 = cellIndex;
  v8 = color;
  v9 = info;
  offset.m_quad = v6;
  v10 = v5[cellIndex].m_max[0];
  _aabb.m_min.m_quad = _mm_unpacklo_ps(
                         _mm_unpacklo_ps(
                           (__m128)COERCE_UNSIGNED_INT((float)v5[cellIndex].m_min[0]),
                           (__m128)COERCE_UNSIGNED_INT((float)v5[cellIndex].m_min[2])),
                         _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v5[cellIndex].m_min[1]), (__m128)0i64));
  _aabb.m_max.m_quad = _mm_unpacklo_ps(
                         _mm_unpacklo_ps(
                           (__m128)COERCE_UNSIGNED_INT((float)v10),
                           (__m128)COERCE_UNSIGNED_INT((float)v5[cellIndex].m_max[2])),
                         _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v5[cellIndex].m_max[1]), (__m128)0i64));
  if ( !v4 )
  {
    pointInOut.m_quad = _mm_mul_ps(
                          _mm_add_ps(
                            _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)COERCE_UNSIGNED_INT((float)v5[cellIndex].m_max[0]),
                                (__m128)COERCE_UNSIGNED_INT((float)v5[cellIndex].m_max[2])),
                              _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v5[cellIndex].m_max[1]), (__m128)0i64)),
                            _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)COERCE_UNSIGNED_INT((float)v5[cellIndex].m_min[0]),
                                (__m128)COERCE_UNSIGNED_INT((float)v5[cellIndex].m_min[2])),
                              _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v5[cellIndex].m_min[1]), (__m128)0i64))),
                          (__m128)xmmword_141A711B0);
    hkaiNavVolume::convertPointToWorld(navVolume, &pointInOut);
    v11 = _mm_add_ps(pointInOut.m_quad, v9->m_displayOffset.m_quad);
    v17.m_string.m_capacityAndFlags = -2147483520;
    v17.m_string.m_size = 1;
    pointInOut.m_quad = v11;
    v17.m_string.m_data = v17.m_string.m_storage;
    v17.m_string.m_storage[0] = 0;
    hkStringBuf::printf(&v17, "%d", v7);
    hkDebugDisplay::display3dText(
      hkSingleton<hkDebugDisplay>::s_instance,
      v17.m_string.m_data,
      &pointInOut,
      hkColor::ORANGE,
      0,
      (int)hkDebugDisplayProcess::m_tag);
    v17.m_string.m_size = 0;
    if ( v17.m_string.m_capacityAndFlags >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        v17.m_string.m_data,
        v17.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  }
  v12 = hkColor::rgbFromFloats(
          (float)BYTE2(v8) * 0.0039215689,
          (float)BYTE1(v8) * 0.0039215689,
          (float)(unsigned __int8)v8 * 0.0039215689,
          v9->m_transparency);
  hkaiNavVolumeDebugUtils::showCellAabb(v9, &_aabb, &offset, &scale, v12);
}

// File Line: 292
// RVA: 0xC4E270
void __fastcall hkaiNavVolumeDebugUtils::showCellAabb(hkaiNavVolumeDebugUtils::DebugInfo *info, hkAabb *_aabb, hkVector4f *offset, hkVector4f *scale, unsigned int color)
{
  hkVector4f v5; // xmm3
  hkaiNavVolumeDebugUtils::DebugInfo *v6; // rbx
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  bool v9; // zf
  hkAabb aabb; // [rsp+30h] [rbp-28h]

  v5.m_quad = (__m128)_aabb->m_max;
  v6 = info;
  v7 = _mm_mul_ps(scale->m_quad, _mm_mul_ps(_mm_sub_ps(v5.m_quad, _aabb->m_min.m_quad), (__m128)xmmword_141A711B0));
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_mul_ps(_mm_add_ps(v5.m_quad, _aabb->m_min.m_quad), (__m128)xmmword_141A711B0), scale->m_quad),
           offset->m_quad),
         info->m_displayOffset.m_quad);
  if ( info->m_shrinkCells.m_bool )
    v7 = _mm_mul_ps(v7, (__m128)_xmm);
  v9 = info->m_showCells.m_bool == 0;
  aabb.m_max.m_quad = _mm_add_ps(v7, v8);
  aabb.m_min.m_quad = _mm_sub_ps(v8, v7);
  if ( !v9 )
    hkaiNavVolumeDebugUtils::displayAabb(&aabb, color);
  if ( v6->m_showCellBorders.m_bool )
    hkDebugDisplay::displayAabb(
      hkSingleton<hkDebugDisplay>::s_instance,
      &aabb,
      v6->m_cellBorderColor,
      0,
      (int)hkDebugDisplayProcess::m_tag);
}

// File Line: 322
// RVA: 0xC4C990
void __fastcall hkaiNavVolumeDebugUtils::displayAabb(hkAabb *aabb, unsigned int color)
{
  unsigned int v2; // edi
  hkAabb *v3; // rbx
  hkVector4f *v4; // rax
  __int32 v5; // ecx
  int v6; // er9
  __m128i v7; // xmm0
  __m128i v8; // xmm1
  int v9; // eax
  int v10; // ecx
  int v11; // er9
  __m128 v12; // xmm10
  __m128 v13; // xmm6
  __m128 v14; // xmm7
  int v15; // eax
  int v16; // er9
  __int64 v17; // rbx
  __m128 v18; // xmm8
  int v19; // eax
  int v20; // er9
  __int64 v21; // rbx
  __m128 v22; // xmm9
  int v23; // eax
  int v24; // er9
  __int64 v25; // rbx
  int v26; // eax
  int v27; // er9
  __int64 v28; // rbx
  __m128 v29; // xmm6
  int v30; // eax
  int v31; // er9
  __int64 v32; // rbx
  int v33; // eax
  int v34; // er9
  __int64 v35; // rbx
  int v36; // ecx
  int v37; // er9
  __int64 v38; // rbx
  hkVector4f *array; // [rsp+28h] [rbp-29h]
  int v40; // [rsp+30h] [rbp-21h]
  int v41; // [rsp+34h] [rbp-1Dh]
  __int128 v42; // [rsp+38h] [rbp-19h]
  __m128i v43; // [rsp+48h] [rbp-9h]
  hkResult result; // [rsp+C0h] [rbp+6Fh]

  v2 = color;
  v3 = aabb;
  if ( HIBYTE(color) )
  {
    array = 0i64;
    v40 = 0;
    v41 = 2147483648;
    result.m_enum = 128;
    v4 = (hkVector4f *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(
                         (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
                         (int *)&result);
    v40 = 8;
    array = v4;
    v5 = 2147483648;
    if ( result.m_enum / 16 )
      v5 = result.m_enum / 16;
    v41 = v5;
    if ( (v5 & 0x3FFFFFFF) < 0 )
    {
      v6 = 0;
      if ( 2 * (v5 & 0x3FFFFFFF) > 0 )
        v6 = 2 * (v5 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v6, 16);
      v5 = v41;
    }
    v7 = (__m128i)v3->m_min;
    v8 = (__m128i)v3->m_max;
    v9 = 0;
    v10 = v5 & 0x3FFFFFFF;
    v40 = 0;
    _mm_store_si128((__m128i *)&v42, v7);
    _mm_store_si128(&v43, v8);
    if ( v10 < 1 )
    {
      v11 = 1;
      if ( 2 * v10 > 1 )
        v11 = 2 * v10;
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v11, 16);
      v9 = v40;
    }
    v12 = (__m128)DWORD2(v42);
    v13 = (__m128)DWORD1(v42);
    v14 = (__m128)(unsigned int)v42;
    v40 = v9 + 1;
    array->m_quad = _mm_unpacklo_ps(
                      _mm_unpacklo_ps((__m128)(unsigned int)v42, (__m128)DWORD2(v42)),
                      _mm_unpacklo_ps((__m128)DWORD1(v42), (__m128)0i64));
    v15 = v40;
    v16 = v40 + 1;
    v17 = v40;
    if ( (v41 & 0x3FFFFFFF) < v40 + 1 )
    {
      if ( v16 < 2 * (v41 & 0x3FFFFFFF) )
        v16 = 2 * (v41 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v16, 16);
      v15 = v40;
    }
    v18 = (__m128)v43.m128i_u32[2];
    v40 = v15 + 1;
    array[v17].m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps(v14, (__m128)v43.m128i_u32[2]),
                          _mm_unpacklo_ps(v13, (__m128)0i64));
    v19 = v40;
    v20 = v40 + 1;
    v21 = v40;
    if ( (v41 & 0x3FFFFFFF) < v40 + 1 )
    {
      if ( v20 < 2 * (v41 & 0x3FFFFFFF) )
        v20 = 2 * (v41 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v20, 16);
      v19 = v40;
    }
    v22 = (__m128)v43.m128i_u32[0];
    v40 = v19 + 1;
    array[v21].m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps((__m128)v43.m128i_u32[0], v18),
                          _mm_unpacklo_ps(v13, (__m128)0i64));
    v23 = v40;
    v24 = v40 + 1;
    v25 = v40;
    if ( (v41 & 0x3FFFFFFF) < v40 + 1 )
    {
      if ( v24 < 2 * (v41 & 0x3FFFFFFF) )
        v24 = 2 * (v41 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v24, 16);
      v23 = v40;
    }
    v40 = v23 + 1;
    array[v25].m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v22, v12), _mm_unpacklo_ps(v13, (__m128)0i64));
    v26 = v40;
    v27 = v40 + 1;
    v28 = v40;
    if ( (v41 & 0x3FFFFFFF) < v40 + 1 )
    {
      if ( v27 < 2 * (v41 & 0x3FFFFFFF) )
        v27 = 2 * (v41 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v27, 16);
      v26 = v40;
    }
    v29 = (__m128)v43.m128i_u32[1];
    v40 = v26 + 1;
    array[v28].m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps(v14, v12),
                          _mm_unpacklo_ps((__m128)v43.m128i_u32[1], (__m128)0i64));
    v30 = v40;
    v31 = v40 + 1;
    v32 = v40;
    if ( (v41 & 0x3FFFFFFF) < v40 + 1 )
    {
      if ( v31 < 2 * (v41 & 0x3FFFFFFF) )
        v31 = 2 * (v41 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v31, 16);
      v30 = v40;
    }
    v40 = v30 + 1;
    array[v32].m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v14, v18), _mm_unpacklo_ps(v29, (__m128)0i64));
    v33 = v40;
    v34 = v40 + 1;
    v35 = v40;
    if ( (v41 & 0x3FFFFFFF) < v40 + 1 )
    {
      if ( v34 < 2 * (v41 & 0x3FFFFFFF) )
        v34 = 2 * (v41 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v34, 16);
      v33 = v40;
    }
    v40 = v33 + 1;
    array[v35].m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v22, v18), _mm_unpacklo_ps(v29, (__m128)0i64));
    v36 = v40;
    v37 = v40 + 1;
    v38 = v40;
    if ( (v41 & 0x3FFFFFFF) < v40 + 1 )
    {
      if ( v37 < 2 * (v41 & 0x3FFFFFFF) )
        v37 = 2 * (v41 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, &array, v37, 16);
      v36 = v40;
    }
    v40 = v36 + 1;
    array[v38].m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v22, v12), _mm_unpacklo_ps(v29, (__m128)0i64));
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array, array + 3, array + 1, v2);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 1, array + 3, array + 2, v2);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 2, array + 6, array + 5, v2);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 5, array + 1, array + 2, v2);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 5, array + 6, array + 4, v2);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 4, array + 6, array + 7, v2);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 7, array + 3, array, v2);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array, array + 4, array + 7, v2);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array, array + 1, array + 4, v2);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 4, array + 1, array + 5, v2);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 2, array + 3, array + 6, v2);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 6, array + 3, array + 7, v2);
    v40 = 0;
    if ( v41 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
        array,
        16 * v41);
  }
}

// File Line: 360
// RVA: 0xC4CFC0
void __fastcall hkaiNavVolumeDebugUtils::displayCellCenter(hkaiNavVolume *navVolume, int cellIndex, hkVector4f *displayOffset)
{
  __int64 v3; // rax
  hkaiNavVolume::Cell *v4; // rdx
  hkVector4f position; // [rsp+30h] [rbp-18h]

  v3 = cellIndex;
  v4 = navVolume->m_cells.m_data;
  position.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_unpacklo_ps(
                                _mm_unpacklo_ps(
                                  (__m128)COERCE_UNSIGNED_INT((float)navVolume->m_cells.m_data[v3].m_max[0]),
                                  (__m128)COERCE_UNSIGNED_INT((float)v4[v3].m_max[2])),
                                _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v4[v3].m_max[1]), (__m128)0i64)),
                              _mm_unpacklo_ps(
                                _mm_unpacklo_ps(
                                  (__m128)COERCE_UNSIGNED_INT((float)navVolume->m_cells.m_data[v3].m_min[0]),
                                  (__m128)COERCE_UNSIGNED_INT((float)navVolume->m_cells.m_data[v3].m_min[2])),
                                _mm_unpacklo_ps(
                                  (__m128)COERCE_UNSIGNED_INT((float)navVolume->m_cells.m_data[v3].m_min[1]),
                                  (__m128)0i64))),
                            (__m128)xmmword_141A711B0),
                          navVolume->m_quantizationScale.m_quad),
                        navVolume->m_quantizationOffset.m_quad),
                      displayOffset->m_quad);
  hkDebugDisplay::displayStar(
    hkSingleton<hkDebugDisplay>::s_instance,
    &position,
    0.30000001,
    hkColor::YELLOW,
    0,
    (int)hkDebugDisplayProcess::m_tag);
}

// File Line: 374
// RVA: 0xC4D090
void __fastcall hkaiNavVolumeDebugUtils::reportMemoryUsed(hkaiNavVolume *navVolume)
{
  hkaiNavVolume *v1; // rbx
  int v2; // ebp
  int v3; // er14
  int v4; // edi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkErrStream v14; // [rsp+20h] [rbp-228h]
  char buf; // [rsp+40h] [rbp-208h]

  v1 = navVolume;
  v2 = 24 * navVolume->m_cells.m_size;
  v3 = 8 * navVolume->m_edges.m_size;
  ((void (__fastcall *)(hkError *, signed __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    1367214621i64,
    "hkaiNavMeshDebugUtils::reportMemoryUsed");
  hkErrStream::hkErrStream(&v14, &buf, 512);
  v4 = v1->m_edges.m_size;
  LODWORD(v1) = v1->m_cells.m_size;
  v5 = hkOstream::operator<<((hkOstream *)&v14.vfptr, "\nMemory:\n Cells ( ");
  v6 = hkOstream::operator<<(v5, (int)v1);
  v7 = hkOstream::operator<<(v6, " )\t:");
  v8 = hkOstream::operator<<(v7, v2);
  v9 = hkOstream::operator<<(v8, "\n Edges ( ");
  v10 = hkOstream::operator<<(v9, v4);
  v11 = hkOstream::operator<<(v10, " )\t:");
  v12 = hkOstream::operator<<(v11, v3);
  v13 = hkOstream::operator<<(v12, "\n Total:");
  hkOstream::operator<<(v13, v3 + v2 + 160);
  hkError::messageReport(-1, &buf, "Debug\\hkaiNavVolumeDebugUtils.cpp", 383);
  hkOstream::~hkOstream((hkOstream *)&v14.vfptr);
  ((void (*)(void))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)();
}

// File Line: 469
// RVA: 0xC4E340
void __fastcall `anonymous namespace'::cutSquareVertically(Square *square, Square *cutter, hkArray<Square,hkContainerHeapAllocator> *squaresOut)
{
  float v3; // xmm6_4
  hkArray<Square,hkContainerHeapAllocator> *v4; // rbx
  Square *v5; // rsi
  Square *v6; // rdi
  float v7; // xmm6_4
  int v8; // eax
  _DWORD *v9; // rcx
  float v10; // xmm7_4
  float v11; // xmm8_4
  float v12; // xmm9_4
  signed __int64 v13; // rax
  float v14; // xmm0_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  float v17; // xmm9_4
  signed __int64 v18; // rax
  float v19; // xmm7_4
  float v20; // xmm8_4
  float v21; // xmm9_4
  signed __int64 v22; // rax
  __int128 v23; // xmm0
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm8_4
  float v27; // xmm9_4
  float *v28; // rax

  v3 = cutter->minX;
  v4 = squaresOut;
  v5 = cutter;
  v6 = square;
  if ( cutter->minX > square->minX )
  {
    v14 = square->maxX;
    v8 = squaresOut->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v14 > cutter->maxX )
    {
      v19 = square->minX;
      v20 = square->minY;
      v21 = square->maxY;
      if ( squaresOut->m_size == v8 )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, squaresOut, 16);
      v22 = (signed __int64)&v4->m_data[v4->m_size];
      if ( v22 )
      {
        *(float *)v22 = v19;
        *(float *)(v22 + 4) = v20;
        *(float *)(v22 + 8) = v3;
        *(float *)(v22 + 12) = v21;
      }
      ++v4->m_size;
      v23 = LODWORD(v6->minX);
      v24 = v6->minY;
      v25 = v6->maxX;
      v26 = v6->maxY;
      v27 = v5->maxX;
      if ( v4->m_size == (v4->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
      v28 = &v4->m_data[v4->m_size].minX;
      if ( v28 )
      {
        *v28 = v27;
        v28[1] = v24;
        v28[2] = v25;
        v28[3] = v26;
      }
      goto LABEL_27;
    }
    if ( v3 <= v14 )
    {
      v15 = square->minX;
      v16 = square->minY;
      v17 = square->maxY;
      if ( squaresOut->m_size == v8 )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, squaresOut, 16);
      v18 = (signed __int64)&v4->m_data[v4->m_size];
      if ( v18 )
      {
        *(float *)v18 = v15;
        *(float *)(v18 + 4) = v16;
        *(float *)(v18 + 8) = v3;
        *(float *)(v18 + 12) = v17;
      }
      goto LABEL_27;
    }
    goto LABEL_4;
  }
  v7 = cutter->maxX;
  if ( v7 <= square->minX )
  {
    v8 = squaresOut->m_capacityAndFlags & 0x3FFFFFFF;
LABEL_4:
    if ( squaresOut->m_size == v8 )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, squaresOut, 16);
    v9 = (_DWORD *)&v4->m_data[v4->m_size].minX;
    if ( v9 )
    {
      *v9 = LODWORD(v6->minX);
      v9[1] = LODWORD(v6->minY);
      v9[2] = LODWORD(v6->maxX);
      v9[3] = LODWORD(v6->maxY);
    }
    goto LABEL_27;
  }
  if ( v7 >= square->maxX )
    return;
  v10 = square->minY;
  v11 = square->maxX;
  v12 = square->maxY;
  if ( squaresOut->m_size == (squaresOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, squaresOut, 16);
  v13 = (signed __int64)&v4->m_data[v4->m_size];
  if ( v13 )
  {
    *(float *)v13 = v7;
    *(float *)(v13 + 4) = v10;
    *(float *)(v13 + 8) = v11;
    *(float *)(v13 + 12) = v12;
  }
LABEL_27:
  ++v4->m_size;
}

// File Line: 519
// RVA: 0xC4E5B0
void __fastcall `anonymous namespace'::cutSquare(Square *_square, Square *_cutter, hkArray<Square,hkContainerHeapAllocator> *squaresOut)
{
  Square v3; // xmm6
  hkArray<Square,hkContainerHeapAllocator> *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm0_4
  int v14; // eax
  Square *v15; // rax
  signed __int64 v16; // rax
  float v17; // xmm1_4
  float v18; // xmm0_4
  signed __int64 v19; // rax
  float v20; // xmm1_4
  float v21; // xmm0_4
  Square *v22; // rax
  int v23; // eax
  signed __int64 v24; // rax
  float v25; // xmm1_4
  float v26; // xmm0_4
  Square cutter; // [rsp+20h] [rbp-50h]
  Square square; // [rsp+30h] [rbp-40h]

  v4 = squaresOut;
  cutter = *_square;
  v3 = cutter;
  LODWORD(v5) = (unsigned __int128)_mm_shuffle_ps((__m128)v3, (__m128)v3, 170);
  if ( cutter.minX > v5 )
  {
    cutter.minX = v5;
    cutter.maxX = v3.minX;
    v3 = cutter;
  }
  LODWORD(v6) = (unsigned __int128)_mm_shuffle_ps((__m128)v3, (__m128)v3, 85);
  LODWORD(v7) = (unsigned __int128)_mm_shuffle_ps((__m128)v3, (__m128)v3, 255);
  if ( v6 > v7 )
  {
    v8 = v6;
    v6 = v7;
    v7 = v8;
    cutter.minY = v6;
    cutter.maxY = v8;
    v3 = cutter;
  }
  v10 = _cutter->maxX;
  v11 = _cutter->minY;
  v12 = _cutter->maxY;
  cutter.minX = _cutter->minX;
  v9 = cutter.minX;
  cutter.minY = v11;
  cutter.maxX = v10;
  cutter.maxY = v12;
  if ( cutter.minX > v10 )
  {
    cutter.minX = v10;
    cutter.maxX = v9;
  }
  if ( v11 > v12 )
  {
    v13 = v11;
    v11 = v12;
    v12 = v13;
    cutter.minY = v11;
    cutter.maxY = v13;
  }
  if ( v11 > v6 )
  {
    v14 = squaresOut->m_capacityAndFlags & 0x3FFFFFFF;
    if ( v12 >= v7 )
    {
      if ( v11 > v7 )
        goto LABEL_12;
      _mm_store_si128((__m128i *)&square, (__m128i)v3);
      if ( squaresOut->m_size == v14 )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, squaresOut, 16);
      v19 = (signed __int64)&v4->m_data[v4->m_size];
      if ( v19 )
      {
        v20 = square.minY;
        *(float *)v19 = square.minX;
        v21 = square.maxX;
        *(float *)(v19 + 4) = v20;
        *(float *)(v19 + 8) = v21;
        *(float *)(v19 + 12) = v11;
      }
      _mm_store_si128((__m128i *)&square, (__m128i)v3);
      square.minY = v11;
      goto LABEL_40;
    }
    _mm_store_si128((__m128i *)&square, (__m128i)v3);
    square.maxY = v11;
    if ( squaresOut->m_size == v14 )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, squaresOut, 16);
    v22 = &v4->m_data[v4->m_size];
    if ( v22 )
      *v22 = square;
    v23 = v4->m_capacityAndFlags;
    ++v4->m_size;
    _mm_store_si128((__m128i *)&square, (__m128i)v3);
    if ( v4->m_size == (v23 & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v4, 16);
    v24 = (signed __int64)&v4->m_data[v4->m_size];
    if ( v24 )
    {
      v25 = square.maxY;
      *(float *)v24 = square.minX;
      v26 = square.maxX;
      *(float *)(v24 + 4) = v12;
      *(float *)(v24 + 8) = v26;
      *(float *)(v24 + 12) = v25;
    }
    _mm_store_si128((__m128i *)&square, (__m128i)v3);
    square.minY = v11;
LABEL_39:
    square.maxY = v12;
LABEL_40:
    ++v4->m_size;
    squaresOut = v4;
    goto LABEL_41;
  }
  if ( v12 > v6 )
  {
    _mm_store_si128((__m128i *)&square, (__m128i)v3);
    if ( v12 >= v7 )
    {
LABEL_41:
      `anonymous namespace'::cutSquareVertically(&square, &cutter, squaresOut);
      return;
    }
    if ( squaresOut->m_size == (squaresOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, squaresOut, 16);
    v16 = (signed __int64)&v4->m_data[v4->m_size];
    if ( v16 )
    {
      v17 = square.maxY;
      *(float *)v16 = square.minX;
      v18 = square.maxX;
      *(float *)(v16 + 4) = v12;
      *(float *)(v16 + 8) = v18;
      *(float *)(v16 + 12) = v17;
    }
    _mm_store_si128((__m128i *)&square, (__m128i)v3);
    goto LABEL_39;
  }
  v14 = squaresOut->m_capacityAndFlags & 0x3FFFFFFF;
LABEL_12:
  if ( squaresOut->m_size == v14 )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, squaresOut, 16);
  v15 = &v4->m_data[v4->m_size];
  if ( v15 )
    *v15 = v3;
  ++v4->m_size;
}

// File Line: 595
// RVA: 0xC4E880
void __fastcall `anonymous namespace'::cutSquaresFromSquare(Square *square, hkArray<Square,hkContainerHeapAllocator> *cutters, hkArray<Square,hkContainerHeapAllocator> *squaresOut)
{
  hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *v3; // rdi
  hkArray<Square,hkContainerHeapAllocator> *v4; // r14
  Square *v5; // rbx
  hkRelocationInfo::Import *v6; // rcx
  int v7; // er8
  Square *v8; // rdx
  int v9; // ebp
  int v10; // ebx
  hkArray<Square,hkContainerHeapAllocator> squaresOuta; // [rsp+20h] [rbp-28h]

  v3 = (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)squaresOut;
  v4 = cutters;
  v5 = square;
  if ( squaresOut->m_size == (squaresOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, squaresOut, 16);
  v6 = &v3->m_data[v3->m_size];
  if ( v6 )
  {
    v6->m_fromOffset = LODWORD(v5->minX);
    *(&v6->m_fromOffset + 1) = LODWORD(v5->minY);
    *(float *)&v6->m_identifier = v5->maxX;
    HIDWORD(v6->m_identifier) = LODWORD(v5->maxY);
  }
  ++v3->m_size;
  v7 = 2147483648;
  v8 = 0i64;
  squaresOuta.m_capacityAndFlags = 2147483648;
  v9 = 0;
  squaresOuta.m_data = 0i64;
  if ( v4->m_size > 0 )
  {
    do
    {
      v10 = 0;
      for ( squaresOuta.m_size = 0; v10 < v3->m_size; ++v10 )
        `anonymous namespace'::cutSquare((Square *)&v3->m_data[v10], &v4->m_data[v9], &squaresOuta);
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        v3,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&squaresOuta);
      ++v9;
    }
    while ( v9 < v4->m_size );
    v7 = squaresOuta.m_capacityAndFlags;
    v8 = squaresOuta.m_data;
  }
  squaresOuta.m_size = 0;
  if ( v7 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v8,
      16 * v7);
}

// File Line: 611
// RVA: 0xC4E9D0
void __fastcall `anonymous namespace'::convertAabbFaceToSquare(hkAabb *aabb, int face, Square *squareOut)
{
  switch ( face )
  {
    case 0:
    case 1:
      *(_QWORD *)&squareOut->minX = *(unsigned __int64 *)((char *)aabb->m_min.m_quad.m128_u64 + 4);
      *(_QWORD *)&squareOut->maxX = *(unsigned __int64 *)((char *)aabb->m_max.m_quad.m128_u64 + 4);
      break;
    case 2:
    case 3:
      LODWORD(squareOut->minX) = aabb->m_min.m_quad.m128_i32[0];
      squareOut->minY = aabb->m_min.m_quad.m128_f32[2];
      squareOut->maxX = aabb->m_max.m_quad.m128_f32[0];
      squareOut->maxY = aabb->m_max.m_quad.m128_f32[2];
      break;
    case 4:
    case 5:
      *(_QWORD *)&squareOut->minX = aabb->m_min.m_quad.m128_u64[0];
      *(_QWORD *)&squareOut->maxX = aabb->m_max.m_quad.m128_u64[0];
      break;
    default:
      return;
  }
}

// File Line: 641
// RVA: 0xC4EA60
void __fastcall `anonymous namespace'::processCutSquares(hkArray<Square,hkContainerHeapAllocator> *squares, hkAabb *aabb, int face, hkGeometry *geometryOut)
{
  int v4; // er15
  hkGeometry *v5; // rbp
  int v6; // er13
  hkArray<Square,hkContainerHeapAllocator> *v7; // r12
  __m128 v8; // xmm8
  __int64 v9; // rsi
  __m128 v10; // xmm9
  __m128 v11; // xmm10
  __m128 v12; // xmm11
  Square *v13; // rax
  __m128 v14; // xmm5
  __m128 v15; // xmm4
  __m128 v16; // xmm7
  __m128 v17; // xmm6
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm11
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm3
  int v24; // edi
  int v25; // eax
  int v26; // er9
  int v27; // eax
  __m128 *v28; // rax
  __int64 v29; // r14
  int v30; // er9
  int v31; // eax
  int v32; // eax
  hkGeometry::Triangle *v33; // rdx
  hkResult result; // [rsp+40h] [rbp-C8h]
  hkResult v35; // [rsp+44h] [rbp-C4h]
  __m128 v36; // [rsp+50h] [rbp-B8h]
  hkAabb *v37; // [rsp+118h] [rbp+10h]

  v37 = aabb;
  v4 = 0;
  v5 = geometryOut;
  v6 = face;
  v7 = squares;
  if ( squares->m_size > 0 )
  {
    v8 = v36;
    v9 = 0i64;
    v10 = v36;
    v11 = v36;
    v12 = v36;
    do
    {
      v13 = v7->m_data;
      v14 = (__m128)LODWORD(v7->m_data[v9].minX);
      v15 = (__m128)LODWORD(v7->m_data[v9].maxX);
      if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v7->m_data[v9].minX - v15.m128_f32[0])) >> 1) > 0.000001 )
      {
        v16 = (__m128)LODWORD(v13[v9].minY);
        v17 = (__m128)LODWORD(v13[v9].maxY);
        if ( COERCE_FLOAT((unsigned int)(2 * COERCE_SIGNED_INT(v16.m128_f32[0] - v17.m128_f32[0])) >> 1) > 0.000001 )
        {
          switch ( v6 )
          {
            case 0:
              v18 = 0i64;
              v19 = (__m128)LODWORD(v13[v9].minY);
              v20 = (__m128)aabb->m_min.m_quad.m128_u32[0];
              v8 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, v16), _mm_unpacklo_ps(v14, (__m128)0i64));
              v10 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, v17), _mm_unpacklo_ps(v14, (__m128)0i64));
              v11 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, v17), _mm_unpacklo_ps(v15, (__m128)0i64));
              v21 = (__m128)LODWORD(v7->m_data[v9].maxX);
              goto LABEL_13;
            case 1:
              v18 = 0i64;
              v19 = (__m128)LODWORD(v13[v9].maxY);
              v20 = (__m128)aabb->m_max.m_quad.m128_u32[0];
              v8 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, v16), _mm_unpacklo_ps(v14, (__m128)0i64));
              v10 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, v16), _mm_unpacklo_ps(v15, (__m128)0i64));
              v11 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, v17), _mm_unpacklo_ps(v15, (__m128)0i64));
              v21 = (__m128)LODWORD(v7->m_data[v9].minX);
              goto LABEL_13;
            case 2:
              v18 = 0i64;
              v19 = (__m128)LODWORD(v13[v9].maxY);
              v8 = _mm_unpacklo_ps(
                     _mm_unpacklo_ps(v14, v16),
                     _mm_unpacklo_ps((__m128)aabb->m_min.m_quad.m128_u32[1], (__m128)0i64));
              v10 = _mm_unpacklo_ps(
                      _mm_unpacklo_ps(v15, v16),
                      _mm_unpacklo_ps((__m128)aabb->m_min.m_quad.m128_u32[1], (__m128)0i64));
              v11 = _mm_unpacklo_ps(
                      _mm_unpacklo_ps(v15, v17),
                      _mm_unpacklo_ps((__m128)aabb->m_min.m_quad.m128_u32[1], (__m128)0i64));
              v21 = (__m128)aabb->m_min.m_quad.m128_u32[1];
              goto LABEL_12;
            case 3:
              v18 = 0i64;
              v19 = (__m128)LODWORD(v13[v9].minY);
              v20 = (__m128)LODWORD(v7->m_data[v9].maxX);
              v8 = _mm_unpacklo_ps(
                     _mm_unpacklo_ps(v14, v16),
                     _mm_unpacklo_ps((__m128)aabb->m_max.m_quad.m128_u32[1], (__m128)0i64));
              v10 = _mm_unpacklo_ps(
                      _mm_unpacklo_ps(v14, v17),
                      _mm_unpacklo_ps((__m128)aabb->m_max.m_quad.m128_u32[1], (__m128)0i64));
              v11 = _mm_unpacklo_ps(
                      _mm_unpacklo_ps(v15, v17),
                      _mm_unpacklo_ps((__m128)aabb->m_max.m_quad.m128_u32[1], (__m128)0i64));
              v21 = (__m128)aabb->m_max.m_quad.m128_u32[1];
              goto LABEL_13;
            case 4:
              v22 = (__m128)aabb->m_min.m_quad.m128_u32[2];
              v18 = 0i64;
              v19 = (__m128)aabb->m_min.m_quad.m128_u32[2];
              v20 = (__m128)LODWORD(v7->m_data[v9].maxX);
              v8 = _mm_unpacklo_ps(_mm_unpacklo_ps(v14, v22), _mm_unpacklo_ps(v16, (__m128)0i64));
              v10 = _mm_unpacklo_ps(_mm_unpacklo_ps(v14, v22), _mm_unpacklo_ps(v17, (__m128)0i64));
              v11 = _mm_unpacklo_ps(_mm_unpacklo_ps(v15, v22), _mm_unpacklo_ps(v17, (__m128)0i64));
              v21 = (__m128)LODWORD(v13[v9].minY);
              goto LABEL_13;
            case 5:
              v23 = (__m128)aabb->m_max.m_quad.m128_u32[2];
              v18 = 0i64;
              v19 = (__m128)aabb->m_max.m_quad.m128_u32[2];
              v8 = _mm_unpacklo_ps(_mm_unpacklo_ps(v14, v23), _mm_unpacklo_ps(v16, (__m128)0i64));
              v10 = _mm_unpacklo_ps(_mm_unpacklo_ps(v15, v23), _mm_unpacklo_ps(v16, (__m128)0i64));
              v11 = _mm_unpacklo_ps(_mm_unpacklo_ps(v15, v23), _mm_unpacklo_ps(v17, (__m128)0i64));
              v21 = (__m128)LODWORD(v13[v9].maxY);
LABEL_12:
              v20 = (__m128)LODWORD(v7->m_data[v9].minX);
LABEL_13:
              v12 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, v19), _mm_unpacklo_ps(v21, v18));
              break;
            default:
              break;
          }
          if ( v5 )
          {
            v24 = v5->m_vertices.m_size;
            v25 = v5->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
            v26 = v24 + 4;
            if ( v25 >= v24 + 4 )
            {
              result.m_enum = 0;
            }
            else
            {
              v27 = 2 * v25;
              if ( v26 < v27 )
                v26 = v27;
              hkArrayUtil::_reserve(
                &result,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v5->m_vertices,
                v26,
                16);
            }
            v5->m_vertices.m_size += 4;
            v28 = &v5->m_vertices.m_data[v24].m_quad;
            *v28 = v8;
            v28[1] = v10;
            v28[2] = v11;
            v28[3] = v12;
            v29 = v5->m_triangles.m_size;
            v30 = v29 + 2;
            v31 = v5->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
            if ( v31 >= (signed int)v29 + 2 )
            {
              v35.m_enum = 0;
            }
            else
            {
              v32 = 2 * v31;
              if ( v30 < v32 )
                v30 = v32;
              hkArrayUtil::_reserve(
                &v35,
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                &v5->m_triangles,
                v30,
                16);
            }
            v5->m_triangles.m_size += 2;
            v33 = &v5->m_triangles.m_data[v29];
            v33->m_b = v24 + 1;
            v33->m_a = v24 + 2;
            v33->m_c = v24;
            v33->m_material = -1;
            v33[1].m_a = v24;
            v33[1].m_c = v24 + 2;
            v33[1].m_material = -1;
            v33[1].m_b = v24 + 3;
            aabb = v37;
          }
        }
      }
      ++v4;
      ++v9;
    }
    while ( v4 < v7->m_size );
  }
}

// File Line: 715
// RVA: 0xC4D260
void __fastcall hkaiNavVolumeDebugUtils::GeomteryBuildSettings::GeomteryBuildSettings(hkaiNavVolumeDebugUtils::GeomteryBuildSettings *this)
{
  this->m_skipBoundingFaces = 1;
  this->m_filter.m_pntr = 0i64;
}

// File Line: 728
// RVA: 0xC4D280
void __fastcall hkaiNavVolumeDebugUtils::GeomteryDisplaySettings::GeomteryDisplaySettings(hkaiNavVolumeDebugUtils::GeomteryDisplaySettings *this)
{
  this->m_drawLines = 1;
  this->m_lineColor = -1;
  this->m_colorVariance = 0.0;
  this->m_sortGeometry = 0;
  this->m_color = hkColor::ROYALBLUE & 0xFFFFFF | (hkColor::ROYALBLUE >> 1) & 0x7F000000;
  this->m_sortDirection = (hkVector4f)stru_141A71280.m_quad;
  this->m_displayOffset = (hkVector4f)aabbOut.m_quad;
}

// File Line: 733
// RVA: 0xC4D2D0
void __fastcall hkaiNavVolumeDebugUtils::GeomteryDisplaySettings::setColorWithVariance(hkaiNavVolumeDebugUtils::GeomteryDisplaySettings *this, unsigned int color, float variance)
{
  this->m_color = color;
  this->m_colorVariance = variance;
  this->m_lineColor = color & 0xFF000000 | (color >> 2) & 0x3F3F3F;
}

// File Line: 740
// RVA: 0xC4D300
void __fastcall hkaiNavVolumeDebugUtils::GeomteryDisplaySettings::setTranslucent(hkaiNavVolumeDebugUtils::GeomteryDisplaySettings *this, unsigned int color, hkVector4f *sortDir, int lineColor)
{
  __m128 v4; // xmm0

  this->m_color = color;
  v4 = sortDir->m_quad;
  this->m_sortGeometry = 1;
  this->m_sortDirection.m_quad = v4;
  this->m_lineColor = lineColor;
}

// File Line: 748
// RVA: 0xC4D320
void __fastcall hkaiNavVolumeDebugUtils::buildNavVolumeGeometry(hkaiNavVolumeDebugUtils::GeomteryBuildSettings *buildSettings, hkaiNavVolume *navVolume, hkGeometry *geometryOut)
{
  hkaiNavVolume *v3; // r15
  unsigned int v4; // edx
  __int64 v5; // rax
  hkGeometry *v6; // rsi
  hkaiNavVolumeDebugUtils::GeomteryBuildSettings *v7; // rdi
  __int64 v8; // r12
  hkaiNavVolumeDebugUtils::GeometryBuildFilter *v9; // rcx
  hkaiNavVolume::Cell *v10; // r13
  __m128 v11; // xmm10
  __m128 v12; // xmm11
  int v13; // ebx
  int *v14; // r14
  __m128i v15; // xmm3
  __m128i v16; // xmm1
  __m128i v17; // xmm3
  __m128i v18; // xmm1
  hkVector4f v19; // xmm11
  hkVector4f v20; // xmm10
  float v21; // xmm14_4
  float v22; // xmm7_4
  float v23; // xmm8_4
  float v24; // xmm9_4
  __m128 v25; // xmm2
  hkVector4f v26; // xmm1
  signed __int64 v27; // rdi
  signed __int64 v28; // rsi
  hkaiNavVolume::Edge *v29; // r14
  hkaiNavVolumeDebugUtils::GeometryBuildFilter *v30; // rcx
  __m128i v31; // xmm2
  __m128i v32; // xmm1
  __m128i v33; // xmm2
  __m128i v34; // xmm1
  hkVector4f v35; // xmm2
  __m128 v36; // xmm1
  __m128 v37; // xmm0
  __m128 v38; // xmm2
  __m128 v39; // xmm2
  bool v40; // zf
  bool v41; // cf
  Square *v42; // r8
  __int64 v43; // r8
  __m128i v44; // xmm1
  int v45; // ebx
  hkArray<Square,hkContainerHeapAllocator> *v46; // rdi
  signed int v47; // er8
  signed int v48; // edi
  int *v49; // rbx
  int v50; // er8
  hkArray<Square,hkContainerHeapAllocator> squaresOut; // [rsp+20h] [rbp-C0h]
  Square *array; // [rsp+30h] [rbp-B0h]
  int v53; // [rsp+38h] [rbp-A8h]
  int v54; // [rsp+3Ch] [rbp-A4h]
  Square squareOut; // [rsp+40h] [rbp-A0h]
  __int64 v56; // [rsp+50h] [rbp-90h]
  int *v57; // [rsp+58h] [rbp-88h]
  hkAabb aabb; // [rsp+60h] [rbp-80h]
  __m128 v59; // [rsp+80h] [rbp-60h]
  __m128 v60; // [rsp+90h] [rbp-50h]
  hkArray<Square,hkContainerHeapAllocator> cutters; // [rsp+A0h] [rbp-40h]
  __int64 v62; // [rsp+B0h] [rbp-30h]
  int v63; // [rsp+B8h] [rbp-28h]
  int v64; // [rsp+BCh] [rbp-24h]
  __int64 v65; // [rsp+C0h] [rbp-20h]
  int v66; // [rsp+C8h] [rbp-18h]
  int v67; // [rsp+CCh] [rbp-14h]
  __int64 v68; // [rsp+D0h] [rbp-10h]
  int v69; // [rsp+D8h] [rbp-8h]
  int v70; // [rsp+DCh] [rbp-4h]
  __int64 v71; // [rsp+E0h] [rbp+0h]
  int v72; // [rsp+E8h] [rbp+8h]
  int v73; // [rsp+ECh] [rbp+Ch]
  __int64 v74; // [rsp+F0h] [rbp+10h]
  int v75; // [rsp+F8h] [rbp+18h]
  int v76; // [rsp+FCh] [rbp+1Ch]
  hkAabb v77; // [rsp+100h] [rbp+20h]
  __m128 v78; // [rsp+120h] [rbp+40h]
  hkaiNavVolumeDebugUtils::GeomteryBuildSettings *v79; // [rsp+220h] [rbp+140h]
  int v80; // [rsp+228h] [rbp+148h]
  hkGeometry *geometryOuta; // [rsp+230h] [rbp+150h]
  int retaddr; // [rsp+238h] [rbp+158h]

  v3 = navVolume;
  v4 = 0;
  v5 = v3->m_cells.m_size;
  v6 = geometryOut;
  v7 = buildSettings;
  cutters.m_data = 0i64;
  cutters.m_size = 0;
  cutters.m_capacityAndFlags = 2147483648;
  v62 = 0i64;
  v63 = 0;
  v64 = 2147483648;
  v65 = 0i64;
  v66 = 0;
  v67 = 2147483648;
  v68 = 0i64;
  v69 = 0;
  v70 = 2147483648;
  v71 = 0i64;
  v72 = 0;
  v73 = 2147483648;
  v74 = 0i64;
  v75 = 0;
  v76 = 2147483648;
  v80 = 0;
  v56 = v5;
  if ( v5 > 0 )
  {
    v8 = 0i64;
    do
    {
      v9 = v7->m_filter.m_pntr;
      if ( !v9
        || ((unsigned __int8 (__fastcall *)(hkaiNavVolumeDebugUtils::GeometryBuildFilter *, hkaiNavVolume *, _QWORD))v9->vfptr[1].__first_virtual_table_function__)(
             v9,
             v3,
             v4) )
      {
        v10 = v3->m_cells.m_data;
        v11 = v3->m_quantizationScale.m_quad;
        v12 = v3->m_quantizationScale.m_quad;
        v13 = 0;
        v14 = &cutters.m_size;
        v57 = &cutters.m_size;
        v15 = _mm_loadu_si128((const __m128i *)&v10[v8]);
        v16 = v15;
        v17 = _mm_unpackhi_epi16(v15, (__m128i)0i64);
        v18 = _mm_unpacklo_epi16(v16, (__m128i)0i64);
        v19.m_quad = _mm_add_ps(
                       _mm_mul_ps(
                         v12,
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(_mm_srli_epi32(v18, 0x10u)),
                             (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                           _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v18, 0x10u), 0x10u)))),
                       v3->m_quantizationOffset.m_quad);
        aabb.m_min = (hkVector4f)v19.m_quad;
        v20.m_quad = _mm_add_ps(
                       _mm_mul_ps(
                         v11,
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(_mm_srli_epi32(v17, 0x10u)),
                             (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                           _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v17, 0x10u), 0x10u)))),
                       v3->m_quantizationOffset.m_quad);
        aabb.m_max = (hkVector4f)v20.m_quad;
        v21 = aabb.m_max.m_quad.m128_f32[1];
        v59 = _mm_mul_ps(_mm_add_ps(v20.m_quad, v19.m_quad), (__m128)xmmword_141A711B0);
        v22 = v59.m128_f32[2];
        v23 = v59.m128_f32[1];
        v24 = v59.m128_f32[0];
        do
        {
          if ( !v7->m_skipBoundingFaces )
            goto LABEL_8;
          v25 = _mm_mul_ps((__m128)_xmm, v3->m_quantizationScale.m_quad);
          v26.m_quad = _mm_sub_ps(v3->m_aabb.m_max.m_quad, v25);
          aabb.m_min.m_quad = _mm_add_ps(v3->m_aabb.m_min.m_quad, v25);
          aabb.m_max = (hkVector4f)v26.m_quad;
          switch ( v13 )
          {
            case 0:
            case 2:
            case 4:
              goto LABEL_19;
            case 1:
              v41 = v20.m_quad.m128_f32[0] < aabb.m_max.m_quad.m128_f32[0];
              break;
            case 3:
              v41 = v21 < aabb.m_max.m_quad.m128_f32[1];
              break;
            case 5:
              v41 = v20.m_quad.m128_f32[2] < aabb.m_max.m_quad.m128_f32[2];
              break;
            default:
              goto LABEL_8;
          }
          if ( v41 )
          {
LABEL_8:
            *(_QWORD *)&squareOut.minX = 0i64;
            *(_QWORD *)&squareOut.maxX = 0i64;
            `anonymous namespace'::convertAabbFaceToSquare(&aabb, v13, &squareOut);
            v27 = v10[v8].m_startEdgeIndex;
            v54 = 2147483648;
            array = 0i64;
            v53 = 0;
            if ( (signed int)v27 < (signed int)v27 + v10[v8].m_numEdges )
            {
              v28 = v27;
              do
              {
                v29 = v3->m_edges.m_data;
                v30 = v79->m_filter.m_pntr;
                if ( !v30
                  || ((unsigned __int8 (__fastcall *)(hkaiNavVolumeDebugUtils::GeometryBuildFilter *, hkaiNavVolume *, _QWORD))v30->vfptr[1].__first_virtual_table_function__)(
                       v30,
                       v3,
                       v29[v28].m_oppositeCell & 0x3FFFFF) )
                {
                  v31 = _mm_loadu_si128((const __m128i *)&v3->m_cells.m_data[v29[v28].m_oppositeCell & 0x3FFFFF]);
                  v32 = v31;
                  v33 = _mm_unpackhi_epi16(v31, (__m128i)0i64);
                  v34 = _mm_unpacklo_epi16(v32, (__m128i)0i64);
                  v35.m_quad = _mm_add_ps(
                                 _mm_mul_ps(
                                   v3->m_quantizationScale.m_quad,
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_cvtepi32_ps(_mm_srli_epi32(v33, 0x10u)),
                                       (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                                     _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v33, 0x10u), 0x10u)))),
                                 v3->m_quantizationOffset.m_quad);
                  v77.m_min.m_quad = _mm_add_ps(
                                       _mm_mul_ps(
                                         v3->m_quantizationScale.m_quad,
                                         _mm_add_ps(
                                           _mm_mul_ps(
                                             _mm_cvtepi32_ps(_mm_srli_epi32(v34, 0x10u)),
                                             (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
                                           _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v34, 0x10u), 0x10u)))),
                                       v3->m_quantizationOffset.m_quad);
                  v36 = _mm_min_ps(v20.m_quad, v35.m_quad);
                  v37 = _mm_add_ps(v35.m_quad, v77.m_min.m_quad);
                  v77.m_max = (hkVector4f)v35.m_quad;
                  v38 = _mm_max_ps(v19.m_quad, v77.m_min.m_quad);
                  v60 = _mm_mul_ps(v37, (__m128)xmmword_141A711B0);
                  v39 = _mm_mul_ps(_mm_sub_ps(_mm_max_ps(v38, v36), _mm_min_ps(v38, v36)), (__m128)xmmword_141A711B0);
                  retaddr = v39.m128_i32[0];
                  v78 = v39;
                  if ( COERCE_FLOAT((unsigned int)(2 * v39.m128_i32[0]) >> 1) >= 0.0000099999997 )
                  {
                    retaddr = v78.m128_i32[1];
                    if ( COERCE_FLOAT((unsigned int)(2 * v78.m128_i32[1]) >> 1) >= 0.0000099999997 )
                      v40 = v60.m128_f32[2] >= v22 ? v13 == 5 : v13 == 4;
                    else
                      v40 = v60.m128_f32[1] >= v23 ? v13 == 3 : v13 == 2;
                  }
                  else
                  {
                    v40 = v60.m128_f32[0] >= v24 ? v13 == 1 : v13 == 0;
                  }
                  if ( v40 )
                  {
                    if ( v53 == (v54 & 0x3FFFFFFF) )
                      hkArrayUtil::_reserveMore(
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                        &array,
                        16);
                    v43 = v53++;
                    `anonymous namespace'::convertAabbFaceToSquare(&v77, v13, &array[v43]);
                  }
                }
                LODWORD(v27) = v27 + 1;
                ++v28;
              }
              while ( (signed int)v27 < v10[v8].m_startEdgeIndex + v10[v8].m_numEdges );
              v14 = v57;
            }
            squaresOut.m_capacityAndFlags = 2147483648;
            squaresOut.m_data = 0i64;
            squaresOut.m_size = 0;
            `anonymous namespace'::cutSquaresFromSquare(
              &squareOut,
              (hkArray<Square,hkContainerHeapAllocator> *)&array,
              &squaresOut);
            v6 = geometryOuta;
            `anonymous namespace'::processCutSquares(&squaresOut, &aabb, v13, geometryOuta);
            squaresOut.m_size = 0;
            if ( squaresOut.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                squaresOut.m_data,
                16 * squaresOut.m_capacityAndFlags);
            squaresOut.m_data = 0i64;
            squaresOut.m_capacityAndFlags = 2147483648;
            v53 = 0;
            if ( v54 >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                array,
                16 * v54);
            array = 0i64;
            v7 = v79;
            v54 = 2147483648;
          }
          else
          {
LABEL_19:
            if ( *v14 == (v14[1] & 0x3FFFFFFF) )
              hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v14 - 2, 16);
            v42 = (Square *)(*((_QWORD *)v14 - 1) + 16i64 * (*v14)++);
            `anonymous namespace'::convertAabbFaceToSquare(&aabb, v13, v42);
          }
          v14 += 4;
          ++v13;
          v57 = v14;
        }
        while ( v13 < 6 );
      }
      ++v8;
      v4 = v80 + 1;
      v40 = v56-- == 1;
      ++v80;
    }
    while ( !v40 );
  }
  if ( v7->m_skipBoundingFaces )
  {
    v44 = (__m128i)v3->m_aabb.m_min;
    v45 = 0;
    v46 = &cutters;
    _mm_store_si128((__m128i *)&v77, (__m128i)v3->m_aabb.m_max.m_quad);
    _mm_store_si128((__m128i *)&v77.m_max, v44);
    do
    {
      *(_QWORD *)&squareOut.minX = 0i64;
      *(_QWORD *)&squareOut.maxX = 0i64;
      `anonymous namespace'::convertAabbFaceToSquare(&v3->m_aabb, v45, &squareOut);
      squaresOut.m_data = 0i64;
      squaresOut.m_size = 0;
      squaresOut.m_capacityAndFlags = 2147483648;
      `anonymous namespace'::cutSquaresFromSquare(&squareOut, v46, &squaresOut);
      v47 = 1;
      if ( v45 & 1 )
        v47 = -1;
      `anonymous namespace'::processCutSquares(&squaresOut, &v77, v45 + v47, v6);
      squaresOut.m_size = 0;
      if ( squaresOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
          squaresOut.m_data,
          16 * squaresOut.m_capacityAndFlags);
      ++v45;
      ++v46;
      squaresOut.m_data = 0i64;
      squaresOut.m_capacityAndFlags = 2147483648;
    }
    while ( v45 < 6 );
  }
  if ( v6 )
    hkGeometryUtils::weldVertices(v6, 0.001);
  v48 = 5;
  v49 = &v77.m_min.m_quad.m128_i32[3];
  do
  {
    v50 = *(v49 - 4);
    v49 -= 4;
    *(v49 - 1) = 0;
    if ( v50 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        *(void **)(v49 - 3),
        16 * v50);
    --v48;
    *(_QWORD *)(v49 - 3) = 0i64;
    *v49 = 2147483648;
  }
  while ( v48 >= 0 );
}

// File Line: 941
// RVA: 0xC4EF10
__int64 __fastcall realToOrderedUint_0(const float *in)
{
  return *(_DWORD *)in ^ ((*(_DWORD *)in >> 31) | 0x80000000);
}

// File Line: 947
// RVA: 0xC4DC10
void __fastcall hkaiNavVolumeDebugUtils::displayNavVolumeGeometry(hkaiNavVolumeDebugUtils::GeomteryDisplaySettings *settings, hkGeometry *surfaceGeometry)
{
  unsigned __int64 v2; // r12
  float v3; // xmm8_4
  unsigned int v4; // er15
  hkGeometry *v5; // r14
  hkaiNavVolumeDebugUtils::GeomteryDisplaySettings *v6; // rsi
  __int64 v7; // r9
  int v8; // ebx
  unsigned int v9; // eax
  __int64 v10; // rax
  hkRadixSort::SortData32 *v11; // rdi
  signed int v12; // er13
  signed int v13; // er11
  unsigned __int64 v14; // r8
  __int64 v15; // r10
  hkGeometry::Triangle *v16; // rdx
  hkVector4f *v17; // rcx
  __m128 v18; // xmm1
  __int64 v19; // rax
  __m128 v20; // xmm3
  __m128 v21; // xmm0
  __int64 v22; // rdx
  __m128 v23; // xmm3
  signed __int64 v24; // rax
  unsigned int i; // ecx
  unsigned int v26; // eax
  hkRadixSort::SortData32 *v27; // rcx
  signed int v28; // er14
  __int64 v29; // r8
  int v30; // ebx
  __int64 v31; // r13
  int v32; // er14
  unsigned int color; // er12
  int v34; // xmm4_4
  int v35; // edx
  signed int v36; // eax
  int v37; // edx
  float v38; // xmm6_4
  float v39; // xmm5_4
  __int64 v40; // r9
  __int64 v41; // r8
  __m128 v42; // xmm1
  unsigned int v43; // [rsp+30h] [rbp-B8h]
  signed int v44; // [rsp+34h] [rbp-B4h]
  hkRadixSort::SortData32 *v45; // [rsp+38h] [rbp-B0h]
  int v46; // [rsp+40h] [rbp-A8h]
  signed int v47; // [rsp+44h] [rbp-A4h]
  hkVector4f c; // [rsp+68h] [rbp-80h]
  hkVector4f b; // [rsp+78h] [rbp-70h]
  hkVector4f end; // [rsp+88h] [rbp-60h]
  unsigned int v51; // [rsp+158h] [rbp+70h]
  __int64 vars0; // [rsp+160h] [rbp+78h]
  void *retaddr; // [rsp+168h] [rbp+80h]
  float v54; // [rsp+170h] [rbp+88h]
  hkGeometry *v55; // [rsp+178h] [rbp+90h]

  v55 = surfaceGeometry;
  v2 = surfaceGeometry->m_triangles.m_size;
  v3 = settings->m_colorVariance;
  v4 = settings->m_lineColor;
  v5 = surfaceGeometry;
  v43 = settings->m_color;
  v44 = settings->m_color;
  v6 = settings;
  v46 = v2;
  v7 = (signed int)v2 / 2;
  v51 = (signed int)v2 / 2;
  v8 = ((signed int)v2 / 2 + 3) & 0xFFFFFFFC;
  v9 = ((signed int)v2 / 2 + 3) & 0xFFFFFFFC;
  if ( v8 )
  {
    v10 = ((__int64 (__fastcall *)(hkContainerDebugAllocator::Allocator *, void **, hkMemoryAllocatorVtbl *, __int64))hkContainerDebugAllocator::s_alloc.vfptr->bufAlloc)(
            &hkContainerDebugAllocator::s_alloc,
            &retaddr,
            hkContainerDebugAllocator::s_alloc.vfptr,
            v7);
    v7 = v51;
    v11 = (hkRadixSort::SortData32 *)v10;
    v9 = 8 * v8 / 8;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = 2147483648;
  if ( v9 )
    v12 = v9;
  v47 = v12;
  if ( v6->m_sortGeometry )
  {
    v13 = 0;
    v14 = v2;
    if ( (signed int)v2 > 0 )
    {
      v15 = 0i64;
      v14 = ((v2 - 1) >> 1) + 1;
      do
      {
        v16 = v5->m_triangles.m_data;
        v17 = v5->m_vertices.m_data;
        v18 = v6->m_displayOffset.m_quad;
        v19 = v16[v15].m_b;
        v15 += 2i64;
        v20 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_add_ps(v17[v19].m_quad, v18), (__m128)xmmword_141A711D0),
                  _mm_mul_ps(_mm_add_ps(v17[v16[v15 - 2].m_a].m_quad, v18), (__m128)xmmword_141A711D0)),
                _mm_mul_ps(_mm_add_ps(v17[*((signed int *)&v16[v15 - 1] - 2)].m_quad, v18), (__m128)xmmword_141A711D0));
        v21 = _mm_add_ps(v17[*((signed int *)&v16[v15] - 3)].m_quad, v18);
        v22 = v13 / 2;
        v11[v22].m_userData = v13;
        v13 += 2;
        v23 = _mm_mul_ps(_mm_add_ps(v20, _mm_mul_ps(v21, (__m128)xmmword_141A711D0)), v6->m_sortDirection.m_quad);
        v54 = (float)(COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 85)) + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 0)))
            + COERCE_FLOAT(_mm_shuffle_ps(v23, v23, 170));
        v11[v22].m_key = (LODWORD(v54) ^ ((SLODWORD(v54) >> 31) | 0x80000001)) >> 1;
        --v14;
      }
      while ( v14 );
    }
    v24 = (signed int)v7;
    for ( i = v7; v24 < v8; ++i )
    {
      v11[v24].m_userData = i;
      v11[v24++].m_key = 0x7FFFFFFF;
    }
    v26 = ((signed int)v2 / 2 + 3) & 0xFFFFFFFC;
    if ( v8 )
    {
      LODWORD(v54) = 8 * v8;
      v27 = (hkRadixSort::SortData32 *)((__int64 (__fastcall *)(hkContainerDebugAllocator::Allocator *, float *, unsigned __int64))hkContainerDebugAllocator::s_alloc.vfptr->bufAlloc)(
                                         &hkContainerDebugAllocator::s_alloc,
                                         &v54,
                                         v14);
      v26 = SLODWORD(v54) / 8;
    }
    else
    {
      v27 = 0i64;
    }
    v45 = v27;
    v28 = 2147483648;
    if ( v26 )
      v28 = v26;
    hkRadixSort::sort32(v11, v8, v27);
    if ( v28 >= 0 )
      hkContainerDebugAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerDebugAllocator::s_alloc,
        v45,
        8 * v28);
  }
  v29 = (signed int)v51;
  v30 = 0;
  if ( (signed int)v2 > 0 )
  {
    v31 = vars0;
    do
    {
      if ( v6->m_sortGeometry )
        v32 = *((_DWORD *)&v11[v29 + v30 / -2] - 1);
      else
        v32 = v30;
      if ( v3 == 0.0 )
      {
        color = v43;
      }
      else
      {
        v54 = 0.0;
        v34 = LODWORD(v3) ^ _xmm[0];
        v35 = 1664525 * v44 + 1013904223;
        v36 = v35;
        v37 = 1664525 * v35 + 1013904223;
        v44 = 1664525 * v37 + 1013904223;
        *(float *)&vars0 = (float)((float)((float)((float)v36 * 2.3283064e-10) * (float)(v3 - *(float *)&v34))
                                 + *(float *)&v34)
                         + (float)((float)BYTE2(v43) * 0.0039215689);
        v38 = fminf(fmaxf(*(float *)&vars0, 0.0), 1.0);
        *(float *)&vars0 = (float)((float)((float)((float)v37 * 2.3283064e-10) * (float)(v3 - *(float *)&v34))
                                 + *(float *)&v34)
                         + (float)((float)BYTE1(v43) * 0.0039215689);
        v39 = fminf(fmaxf(*(float *)&vars0, 0.0), 1.0);
        *(float *)&vars0 = (float)((float)((float)((float)v44 * 2.3283064e-10) * (float)(v3 - *(float *)&v34))
                                 + *(float *)&v34)
                         + (float)((float)(unsigned __int8)v43 * 0.0039215689);
        color = hkColor::rgbFromFloats(v38, v39, fminf(fmaxf(*(float *)&vars0, 0.0), 1.0), 1.0);
      }
      v40 = *(_QWORD *)(v31 + 32);
      v41 = *(_QWORD *)(v31 + 16);
      v42 = v6->m_displayOffset.m_quad;
      c.m_quad = _mm_add_ps(*(__m128 *)(v41 + 16i64 * *(signed int *)(v40 + 16i64 * v32)), v42);
      b.m_quad = _mm_add_ps(*(__m128 *)(v41 + 16i64 * *(signed int *)(v40 + 16i64 * v32 + 4)), v42);
      *(hkVector4f *)((char *)&c + 8) = (hkVector4f)_mm_add_ps(
                                                      *(__m128 *)(v41 + 16i64 * *(signed int *)(v40 + 16i64 * v32 + 8)),
                                                      v42);
      end.m_quad = _mm_add_ps(*(__m128 *)(v41 + 16i64 * *(signed int *)(v40 + 16i64 * v32 + 20)), v42);
      hkDebugDisplay::displayLitTriangle(
        hkSingleton<hkDebugDisplay>::s_instance,
        &c,
        &b,
        (hkVector4f *)((char *)&c + 8),
        color);
      hkDebugDisplay::displayLitTriangle(
        hkSingleton<hkDebugDisplay>::s_instance,
        (hkVector4f *)((char *)&c + 8),
        &end,
        &c,
        color);
      if ( v6->m_drawLines )
      {
        hkDebugDisplay::displayLine(
          hkSingleton<hkDebugDisplay>::s_instance,
          &c,
          &b,
          v4,
          0,
          (int)hkDebugDisplayProcess::m_tag);
        hkDebugDisplay::displayLine(
          hkSingleton<hkDebugDisplay>::s_instance,
          &b,
          (hkVector4f *)((char *)&c + 8),
          v4,
          0,
          (int)hkDebugDisplayProcess::m_tag);
        hkDebugDisplay::displayLine(
          hkSingleton<hkDebugDisplay>::s_instance,
          (hkVector4f *)((char *)&c + 8),
          &end,
          v4,
          0,
          (int)hkDebugDisplayProcess::m_tag);
        hkDebugDisplay::displayLine(
          hkSingleton<hkDebugDisplay>::s_instance,
          &end,
          &c,
          v4,
          0,
          (int)hkDebugDisplayProcess::m_tag);
      }
      v29 = (signed int)v51;
      v30 += 2;
    }
    while ( v30 < v46 );
    v12 = v47;
  }
  if ( v12 >= 0 )
    ((void (__fastcall *)(hkContainerDebugAllocator::Allocator *, hkRadixSort::SortData32 *, _QWORD, __int64))hkContainerDebugAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerDebugAllocator::s_alloc,
      v11,
      (unsigned int)(8 * v12),
      v7);
}

// File Line: 1044
// RVA: 0xC4DB30
void __fastcall hkaiNavVolumeDebugUtils::displayNavVolumeGeometry(hkaiNavVolumeDebugUtils::GeomteryBuildSettings *buildSettings, hkaiNavVolumeDebugUtils::GeomteryDisplaySettings *displaySettings, hkaiNavVolume *navVolume)
{
  hkaiNavVolumeDebugUtils::GeomteryDisplaySettings *v3; // rbx
  hkGeometry geometryOut; // [rsp+20h] [rbp-38h]

  v3 = displaySettings;
  *(_DWORD *)&geometryOut.m_memSizeAndFlags = 0x1FFFF;
  geometryOut.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable';
  geometryOut.m_vertices.m_data = 0i64;
  geometryOut.m_vertices.m_size = 0;
  geometryOut.m_vertices.m_capacityAndFlags = 2147483648;
  geometryOut.m_triangles.m_data = 0i64;
  geometryOut.m_triangles.m_size = 0;
  geometryOut.m_triangles.m_capacityAndFlags = 2147483648;
  hkaiNavVolumeDebugUtils::buildNavVolumeGeometry(buildSettings, navVolume, &geometryOut);
  hkaiNavVolumeDebugUtils::displayNavVolumeGeometry(v3, &geometryOut);
  geometryOut.m_triangles.m_size = 0;
  if ( geometryOut.m_triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      geometryOut.m_triangles.m_data,
      16 * geometryOut.m_triangles.m_capacityAndFlags);
  geometryOut.m_triangles.m_data = 0i64;
  geometryOut.m_triangles.m_capacityAndFlags = 2147483648;
  geometryOut.m_vertices.m_size = 0;
  if ( geometryOut.m_vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      geometryOut.m_vertices.m_data,
      16 * geometryOut.m_vertices.m_capacityAndFlags);
}

// File Line: 1053
// RVA: 0xC4D1E0
bool __fastcall hkaiNavVolumeDebugUtils::SetFilter::shouldIncludeCell(hkaiNavVolumeDebugUtils::SetFilter *this, hkaiNavVolume *volume, int cellIndex)
{
  int v3; // er9
  int *v4; // r10
  int v5; // eax
  int v6; // edx

  v3 = this->m_allowedCells.m_elem.m_size - 1;
  if ( v3 <= 0 )
    return this->m_allowedCells.m_elem.m_size <= this->m_allowedCells.m_elem.m_size - 1
        || this->m_allowedCells.m_elem.m_size == this->m_allowedCells.m_elem.m_size - 1;
  v4 = this->m_allowedCells.m_elem.m_data;
  v5 = v3 & -1640531535 * cellIndex;
  v6 = v4[v5];
  if ( v6 == -1 )
    return this->m_allowedCells.m_elem.m_size <= this->m_allowedCells.m_elem.m_size - 1
        || this->m_allowedCells.m_elem.m_size == this->m_allowedCells.m_elem.m_size - 1;
  while ( v6 != cellIndex )
  {
    v5 = v3 & (v5 + 1);
    v6 = v4[v5];
    if ( v6 == -1 )
      return this->m_allowedCells.m_elem.m_size <= this->m_allowedCells.m_elem.m_size - 1
          || this->m_allowedCells.m_elem.m_size == this->m_allowedCells.m_elem.m_size - 1;
  }
  return v5 <= v3;
}

// File Line: 1058
// RVA: 0xC4D240
bool __fastcall hkaiNavVolumeDebugUtils::MaterialFilter::shouldIncludeCell(hkaiNavVolumeDebugUtils::MaterialFilter *this, hkaiNavVolume *volume, int cellIndex)
{
  return this->m_cellData == volume->m_cells.m_data[cellIndex].m_data;
}

