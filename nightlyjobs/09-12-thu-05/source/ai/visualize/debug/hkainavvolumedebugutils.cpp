// File Line: 43
// RVA: 0xC4BBC0
void __fastcall hkaiNavVolumeDebugUtils::DebugInfo::DebugInfo(hkaiNavVolumeDebugUtils::DebugInfo *this)
{
  strcpy((char *)this, "333?");
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
  this->m_instanceEnabled.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  this->m_instanceEnabled.m_storage.m_numBits = 0;
  this->m_displayOffset = 0i64;
}

// File Line: 48
// RVA: 0xC4BC40
void __fastcall hkaiNavVolumeDebugUtils::showNavVolume(
        hkaiNavVolumeDebugUtils::DebugInfo *settings,
        hkaiNavVolume *navVolume)
{
  hkaiNavVolumeInstance navVolumea; // [rsp+20h] [rbp-88h] BYREF

  hkaiNavVolumeInstance::hkaiNavVolumeInstance(&navVolumea);
  hkaiNavVolumeInstance::tempInit(&navVolumea, navVolume);
  hkaiNavVolumeDebugUtils::showNavVolume(settings, &navVolumea);
  hkaiNavVolumeInstance::~hkaiNavVolumeInstance(&navVolumea);
}

// File Line: 55
// RVA: 0xC4BCA0
void __fastcall hkaiNavVolumeDebugUtils::showNavVolume(
        hkaiNavVolumeDebugUtils::DebugInfo *settings,
        hkaiNavVolumeInstance *navVolume)
{
  hkaiStreamingCollection::InstanceInfo *m_data; // rax
  __int64 v5; // rdx
  hkaiDirectedGraphInstance **p_m_clusterGraphInstance; // rax
  hkaiStreamingCollection array; // [rsp+30h] [rbp-38h] BYREF
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  hkaiStreamingCollection::hkaiStreamingCollection(&array);
  array.m_isTemporary.m_bool = 1;
  if ( (array.m_instances.m_capacityAndFlags & 0x3FFFFFFF) == 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &array.m_instances, 1, 48);
  m_data = array.m_instances.m_data;
  v5 = 1 - array.m_instances.m_size;
  if ( 1 - array.m_instances.m_size > 0 )
  {
    p_m_clusterGraphInstance = &array.m_instances.m_data[array.m_instances.m_size].m_clusterGraphInstance;
    do
    {
      if ( p_m_clusterGraphInstance != (hkaiDirectedGraphInstance **)16 )
      {
        *(p_m_clusterGraphInstance - 2) = 0i64;
        *(p_m_clusterGraphInstance - 1) = 0i64;
        *p_m_clusterGraphInstance = 0i64;
        p_m_clusterGraphInstance[1] = 0i64;
        p_m_clusterGraphInstance[2] = 0i64;
        *((_DWORD *)p_m_clusterGraphInstance + 6) = -1;
      }
      p_m_clusterGraphInstance += 6;
      --v5;
    }
    while ( v5 );
    m_data = array.m_instances.m_data;
  }
  array.m_instances.m_size = 1;
  m_data->m_volumeInstancePtr = navVolume;
  array.m_instances.m_data->m_volumeMediator = 0i64;
  hkaiNavVolumeDebugUtils::showNavVolumeCollection(settings, &array);
  hkaiStreamingCollection::~hkaiStreamingCollection(&array);
}

// File Line: 63
// RVA: 0xC4BDA0
void __fastcall hkaiNavVolumeDebugUtils::showNavVolumeCollection(
        hkaiNavVolumeDebugUtils::DebugInfo *info,
        hkaiStreamingCollection *collection)
{
  __int64 v2; // rsi
  hkaiStreamingCollection *v3; // r8
  int v5; // r12d
  hkPseudoRandomGenerator v6; // r9
  __m128 *v7; // rsi
  bool v8; // zf
  __m128 *v9; // rax
  __m128 v10; // xmm1
  hkVector4f v11; // xmm2
  hkVector4f v12; // xmm1
  hkArray<int,hkContainerHeapAllocator> *m_regionMap; // r14
  int m_capacityAndFlags; // r9d
  int v15; // edi
  hkaiNavVolume *v16; // rcx
  unsigned __int16 m_showSingleSliceIndex; // r15
  unsigned __int16 v18; // dx
  __int64 v19; // r10
  unsigned __int16 *v20; // r8
  unsigned __int16 v21; // ax
  int v22; // r13d
  unsigned __int64 v23; // rcx
  __int64 v24; // r8
  unsigned int m_cellColor; // edx
  __m128i *v26; // rdi
  int m_showSingleRegionIndex; // ecx
  int m_numMaterialColors; // ecx
  unsigned int v29; // eax
  unsigned int v30; // r14d
  __int64 m_sliceAxis; // rcx
  int v32; // eax
  int v33; // eax
  hkVector4f v34; // xmm7
  __m128i v35; // xmm2
  __m128 v36; // xmm6
  __m128i v37; // xmm0
  hkVector4f v38; // xmm6
  __int64 v39; // r8
  hkaiNavVolume *v40; // rcx
  __m128 *v41; // rax
  __m128 *v42; // rax
  int v43; // r15d
  __m128i v44; // xmm1
  __m128i v45; // xmm0
  __m128 v46; // xmm2
  __m128i v47; // xmm0
  __m128 v48; // xmm1
  __m128 v49; // xmm0
  __m128 v50; // xmm9
  __m128 v51; // xmm8
  __m128 v52; // xmm10
  int v53; // ecx
  unsigned int v54; // r14d
  unsigned __int64 v55; // rax
  __int64 v56; // rcx
  int v57; // r8d
  unsigned int v58; // eax
  unsigned int v59; // r9d
  __int64 v60; // r10
  __m128 *m_volumeInstancePtr; // rdx
  __m128 *v62; // rax
  __m128i v63; // xmm1
  __m128i v64; // xmm0
  __m128 v65; // xmm3
  __m128i v66; // xmm0
  __m128 v67; // xmm1
  __m128 v68; // xmm0
  __m128 v69; // xmm6
  __m128 v70; // xmm7
  unsigned int m_internalEdgeColor; // r9d
  __m128 v72; // xmm1
  __m128 v73; // xmm0
  hkArrayBase<int> *p_array; // [rsp+30h] [rbp-B8h]
  hkArrayBase<int> array; // [rsp+38h] [rbp-B0h] BYREF
  __m128i v76; // [rsp+48h] [rbp-A0h] BYREF
  __int64 v77; // [rsp+58h] [rbp-90h]
  unsigned __int64 v78; // [rsp+60h] [rbp-88h]
  hkPseudoRandomGenerator rand[2]; // [rsp+68h] [rbp-80h] BYREF
  hkVector4f pos; // [rsp+78h] [rbp-70h] BYREF
  hkVector4f start; // [rsp+88h] [rbp-60h] BYREF
  hkStringBuf v82; // [rsp+98h] [rbp-50h] BYREF
  hkVector4f end; // [rsp+128h] [rbp+40h] BYREF
  hkVector4f scale; // [rsp+138h] [rbp+50h] BYREF
  hkVector4f offset; // [rsp+148h] [rbp+60h] BYREF
  hkAabb aabb; // [rsp+158h] [rbp+70h] BYREF
  hkAabb _aabb; // [rsp+178h] [rbp+90h] BYREF
  hkStringBuf v88; // [rsp+198h] [rbp+B0h] BYREF
  hkaiStreamingCollection *vars0; // [rsp+2E0h] [rbp+1F8h]
  void *retaddr; // [rsp+2E8h] [rbp+200h]
  __int64 result; // [rsp+2F0h] [rbp+208h] BYREF
  hkaiStreamingCollection *v92; // [rsp+2F8h] [rbp+210h]

  v92 = collection;
  v3 = collection;
  v5 = 0;
  if ( collection->m_instances.m_size > 0 )
  {
    result = v2;
    v6 = 0i64;
    rand[0] = 0i64;
    do
    {
      if ( v5 >= info->m_instanceEnabled.m_storage.m_numBits
        || ((info->m_instanceEnabled.m_storage.m_words.m_data[(__int64)v5 >> 5] >> (v5 & 0x1F)) & 1) != 0 )
      {
        v7 = *(__m128 **)((char *)&v3->m_instances.m_data->m_volumeInstancePtr + *(_QWORD *)&v6);
        if ( v7 )
        {
          v8 = info->m_showAabb.m_bool == 0;
          v9 = (__m128 *)v7[3].m128_u64[0];
          v10 = v7[7];
          v11.m_quad = _mm_add_ps(v9[4], v10);
          v12.m_quad = _mm_add_ps(v10, v9[5]);
          aabb.m_max = (hkVector4f)v12.m_quad;
          aabb.m_min = (hkVector4f)v11.m_quad;
          if ( !v8 && (_mm_movemask_ps(_mm_cmple_ps(v12.m_quad, v11.m_quad)) & 7) == 0 )
            hkDebugDisplay::displayAabb(
              hkSingleton<hkDebugDisplay>::s_instance,
              &aabb,
              hkColor::WHITE,
              0,
              (int)hkDebugDisplayProcess::m_tag);
          m_regionMap = info->m_regionMap;
          m_capacityAndFlags = 0x80000000;
          array.m_data = 0i64;
          array.m_size = 0;
          array.m_capacityAndFlags = 0x80000000;
          p_array = m_regionMap;
          if ( !m_regionMap || m_regionMap->m_size != v7[1].m128_i32[2] )
          {
            if ( info->m_colorRegions.m_bool || info->m_showSingleRegionIndex != -1 )
            {
              v15 = v7[1].m128_i32[2];
              if ( v15 <= 0 )
                LODWORD(result) = 0;
              else
                hkArrayUtil::_reserve(
                  (hkResult *)&result,
                  &hkContainerHeapAllocator::s_alloc,
                  &array,
                  v7[1].m128_i32[2],
                  4);
              v16 = (hkaiNavVolume *)v7[3].m128_u64[0];
              array.m_size = v15;
              hkaiNavVolumeUtils::computeRegions(v16, &array);
              m_capacityAndFlags = array.m_capacityAndFlags;
            }
            m_regionMap = (hkArray<int,hkContainerHeapAllocator> *)&array;
            p_array = &array;
          }
          m_showSingleSliceIndex = info->m_showSingleSliceIndex;
          v18 = -1;
          LOWORD(retaddr) = m_showSingleSliceIndex;
          if ( info->m_showSingleSliceIndex != -1 )
          {
            v19 = v7[1].m128_i32[2];
            if ( v19 > 0 )
            {
              v20 = (unsigned __int16 *)(v7[1].m128_u64[0] + 2i64 * info->m_sliceAxis);
              do
              {
                v21 = *v20;
                v20 += 12;
                if ( v18 < v21 )
                  v21 = v18;
                v18 = v21;
                --v19;
              }
              while ( v19 );
            }
            m_showSingleSliceIndex += v18;
            LOWORD(retaddr) = m_showSingleSliceIndex;
          }
          v22 = 0;
          if ( v7[1].m128_i32[2] > 0 )
          {
            v23 = 0i64;
            v24 = 0i64;
            v78 = 0i64;
            pos.m_quad.m128_u64[0] = 0i64;
            while ( 2 )
            {
              m_cellColor = info->m_cellColor;
              v26 = (__m128i *)(v23 + v7[1].m128_u64[0]);
              m_showSingleRegionIndex = info->m_showSingleRegionIndex;
              if ( m_showSingleRegionIndex != -1
                && m_regionMap->m_size
                && *(int *)((char *)m_regionMap->m_data + v24) != m_showSingleRegionIndex )
              {
                goto LABEL_75;
              }
              if ( info->m_colorCellsRandomly.m_bool )
              {
                rand[1].m_seed = 12345 * v26->m128i_u16[0] + 179 * v26->m128i_u16[2] + 764543 * v26->m128i_u16[1];
                rand[1].m_current = rand[1].m_seed;
                m_cellColor = hkColor::getRandomColor(&rand[1]);
              }
              if ( info->m_colorRegions.m_bool && m_regionMap->m_size == v7[1].m128_i32[2] )
                m_cellColor = hkColor::getPaletteColor(m_regionMap->m_data[v78 / 4], 255);
              m_numMaterialColors = info->m_numMaterialColors;
              if ( m_numMaterialColors > 0 )
                m_cellColor = info->m_materialColors[v26[1].m128i_i32[1] % m_numMaterialColors];
              v29 = hkColor::rgbFromFloats(
                      (float)BYTE2(m_cellColor) * 0.0039215689,
                      (float)BYTE1(m_cellColor) * 0.0039215689,
                      (float)(unsigned __int8)m_cellColor * 0.0039215689,
                      (float)((float)HIBYTE(m_cellColor) * 0.0039215689) * info->m_transparency);
              v8 = info->m_showSingleSliceIndex == -1;
              *(__int64 *)((char *)v76.m128i_i64 + 2) = 0i64;
              v76.m128i_i16[0] = 0;
              *(int *)((char *)&v76.m128i_i32[2] + 2) = 0;
              v30 = v29;
              v77 = 0i64;
              if ( v8 )
              {
LABEL_41:
                v33 = v26->m128i_u16[0];
                v88.m_string.m_capacityAndFlags = -2147483520;
                v88.m_string.m_size = 1;
                v88.m_string.m_storage[0] = 0;
                v34.m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(
                                 (__m128)COERCE_UNSIGNED_INT((float)v33),
                                 (__m128)COERCE_UNSIGNED_INT((float)v26->m128i_u16[2])),
                               _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)v26->m128i_u16[1]), (__m128)0i64));
                v35 = _mm_cvtsi32_si128(v26->m128i_u16[5]);
                v36 = (__m128)COERCE_UNSIGNED_INT((float)v26->m128i_u16[4]);
                v37 = _mm_cvtsi32_si128(v26->m128i_u16[6]);
                _aabb.m_min = (hkVector4f)v34.m_quad;
                v88.m_string.m_data = v88.m_string.m_storage;
                v38.m_quad = _mm_unpacklo_ps(
                               _mm_unpacklo_ps(v36, _mm_cvtepi32_ps(v37)),
                               _mm_unpacklo_ps(_mm_cvtepi32_ps(v35), (__m128)0i64));
                _aabb.m_max = (hkVector4f)v38.m_quad;
                if ( info->m_labelCells.m_bool )
                  hkStringBuf::printf(&v88, "%d(%d) ", (unsigned int)v22, (unsigned int)v26->m128i_i16[3]);
                if ( info->m_showCellData.m_bool )
                {
                  v39 = v26[1].m128i_u32[1];
                  if ( (_DWORD)v39 )
                  {
                    v82.m_string.m_capacityAndFlags = -2147483520;
                    v82.m_string.m_size = 1;
                    v82.m_string.m_storage[0] = 0;
                    v82.m_string.m_data = v82.m_string.m_storage;
                    hkStringBuf::printf(&v82, "[%d]", v39);
                    hkStringBuf::operator+=(&v88, v82.m_string.m_data);
                    v82.m_string.m_size = 0;
                    if ( v82.m_string.m_capacityAndFlags >= 0 )
                      hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                        &hkContainerTempAllocator::s_alloc,
                        v82.m_string.m_data,
                        v82.m_string.m_capacityAndFlags & 0x3FFFFFFF);
                  }
                }
                if ( v88.m_string.m_size - 1 > 0 )
                {
                  v40 = (hkaiNavVolume *)v7[3].m128_u64[0];
                  *(__m128 *)&rand[0].m_seed = _mm_mul_ps(_mm_add_ps(v38.m_quad, v34.m_quad), (__m128)xmmword_141A711B0);
                  hkaiNavVolume::convertPointToWorld(v40, (hkVector4f *)rand);
                  *(__m128 *)&rand[0].m_seed = _mm_add_ps(*(__m128 *)&rand[0].m_seed, info->m_displayOffset.m_quad);
                  hkDebugDisplay::display3dText(
                    hkSingleton<hkDebugDisplay>::s_instance,
                    v88.m_string.m_data,
                    (hkVector4f *)rand,
                    hkColor::ORANGE,
                    0,
                    (int)hkDebugDisplayProcess::m_tag);
                }
                v88.m_string.m_size = 0;
                if ( v88.m_string.m_capacityAndFlags >= 0 )
                  hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                    &hkContainerTempAllocator::s_alloc,
                    v88.m_string.m_data,
                    v88.m_string.m_capacityAndFlags & 0x3FFFFFFF);
                v41 = (__m128 *)v7[3].m128_u64[0];
                offset.m_quad = _mm_add_ps(v41[7], v7[7]);
                scale.m_quad = v41[6];
                hkaiNavVolumeDebugUtils::showCellAabb(info, &_aabb, &offset, &scale, v30);
                if ( info->m_showEdgeConnections.m_bool || info->m_labelEdges.m_bool )
                {
                  v42 = (__m128 *)v7[3].m128_u64[0];
                  v43 = 0;
                  v44 = _mm_loadu_si128(v26);
                  v45 = _mm_unpacklo_epi16(v44, (__m128i)0i64);
                  v46 = _mm_add_ps(
                          _mm_mul_ps(
                            _mm_cvtepi32_ps(_mm_srli_epi32(v45, 0x10u)),
                            (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                          _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v45, 0x10u), 0x10u)));
                  v47 = _mm_unpackhi_epi16(v44, (__m128i)0i64);
                  v48 = _mm_add_ps(
                          _mm_mul_ps(
                            _mm_cvtepi32_ps(_mm_srli_epi32(v47, 0x10u)),
                            (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                          _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v47, 0x10u), 0x10u)));
                  v49 = _mm_add_ps(v42[7], v7[7]);
                  v50 = _mm_add_ps(_mm_mul_ps(v42[6], v46), v49);
                  v51 = _mm_add_ps(_mm_mul_ps(v42[6], v48), v49);
                  if ( v26->m128i_i16[3] > 0 )
                  {
                    v52 = _mm_add_ps(v51, v50);
                    do
                    {
                      v53 = v7[2].m128_i32[2];
                      v54 = v43 + v26[1].m128i_i32[0];
                      if ( (int)v54 >= v53 )
                      {
                        v56 = (int)(v54 - v53);
                        v55 = v7[5].m128_u64[1];
                      }
                      else
                      {
                        v55 = v7[2].m128_u64[0];
                        v56 = (int)v54;
                      }
                      v57 = *(_DWORD *)(v55 + 8 * v56 + 4);
                      if ( (*(_BYTE *)(v55 + 8 * v56) & 0x40) != 0 )
                        v58 = v57 & 0xFFC00000;
                      else
                        v58 = v7[6].m128_i32[3] << 22;
                      v59 = v58 | v57 & 0x3FFFFF;
                      if ( v57 == -1 )
                        v59 = -1;
                      v60 = v59 >> 22;
                      v8 = info->m_showEdgeConnections.m_bool == 0;
                      m_volumeInstancePtr = (__m128 *)vars0->m_instances.m_data[v60].m_volumeInstancePtr;
                      v62 = (__m128 *)m_volumeInstancePtr[3].m128_u64[0];
                      v63 = _mm_loadu_si128((const __m128i *)(m_volumeInstancePtr[1].m128_u64[0]
                                                            + 24i64 * (v57 & 0x3FFFFF)));
                      v64 = _mm_unpacklo_epi16(v63, (__m128i)0i64);
                      v65 = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(_mm_srli_epi32(v64, 0x10u)),
                                (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v64, 0x10u), 0x10u)));
                      v66 = _mm_unpackhi_epi16(v63, (__m128i)0i64);
                      v67 = _mm_add_ps(
                              _mm_mul_ps(
                                _mm_cvtepi32_ps(_mm_srli_epi32(v66, 0x10u)),
                                (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v66, 0x10u), 0x10u)));
                      v68 = _mm_add_ps(v62[7], m_volumeInstancePtr[7]);
                      v69 = _mm_add_ps(_mm_mul_ps(v62[6], v67), v68);
                      v70 = _mm_add_ps(_mm_mul_ps(v62[6], v65), v68);
                      start.m_quad = _mm_add_ps(
                                       _mm_mul_ps(v52, (__m128)xmmword_141A711B0),
                                       info->m_displayOffset.m_quad);
                      end.m_quad = _mm_add_ps(
                                     _mm_mul_ps(_mm_add_ps(v69, v70), (__m128)xmmword_141A711B0),
                                     info->m_displayOffset.m_quad);
                      if ( !v8 && (v22 | (unsigned int)(v5 << 22)) < v59 )
                      {
                        if ( (_DWORD)v60 == v5 )
                          m_internalEdgeColor = info->m_internalEdgeColor;
                        else
                          m_internalEdgeColor = info->m_externalEdgeColor;
                        hkDebugDisplay::displayLine(
                          hkSingleton<hkDebugDisplay>::s_instance,
                          &start,
                          &end,
                          m_internalEdgeColor,
                          0,
                          (int)hkDebugDisplayProcess::m_tag);
                      }
                      if ( info->m_labelEdges.m_bool )
                      {
                        v72 = _mm_min_ps(v51, v69);
                        v82.m_string.m_data = v82.m_string.m_storage;
                        v82.m_string.m_capacityAndFlags = -2147483520;
                        v82.m_string.m_size = 1;
                        v73 = _mm_max_ps(v50, v70);
                        v82.m_string.m_storage[0] = 0;
                        pos.m_quad = _mm_add_ps(
                                       _mm_mul_ps(
                                         _mm_add_ps(_mm_max_ps(v73, v72), _mm_min_ps(v73, v72)),
                                         (__m128)xmmword_141A711B0),
                                       info->m_displayOffset.m_quad);
                        hkStringBuf::printf(&v82, "%d", v54);
                        pos.m_quad = _mm_add_ps(
                                       pos.m_quad,
                                       _mm_mul_ps(_mm_sub_ps(start.m_quad, pos.m_quad), (__m128)xmmword_141A711B0));
                        hkDebugDisplay::display3dText(
                          hkSingleton<hkDebugDisplay>::s_instance,
                          v82.m_string.m_data,
                          &pos,
                          hkColor::RED,
                          0,
                          (int)hkDebugDisplayProcess::m_tag);
                        v82.m_string.m_size = 0;
                        if ( v82.m_string.m_capacityAndFlags >= 0 )
                          hkContainerTempAllocator::s_alloc.vfptr->bufFree(
                            &hkContainerTempAllocator::s_alloc,
                            v82.m_string.m_data,
                            v82.m_string.m_capacityAndFlags & 0x3FFFFFFF);
                      }
                      ++v43;
                    }
                    while ( v43 < v26->m128i_i16[3] );
                  }
                  m_showSingleSliceIndex = (unsigned __int16)retaddr;
                }
              }
              else
              {
                m_sliceAxis = info->m_sliceAxis;
                if ( (unsigned int)v26->m128i_i16[m_sliceAxis] <= m_showSingleSliceIndex
                  && (unsigned int)v26->m128i_i16[m_sliceAxis + 4] > m_showSingleSliceIndex )
                {
                  v76 = *v26;
                  LODWORD(v77) = v26[1].m128i_i32[0];
                  v32 = v26[1].m128i_i32[1];
                  v26 = &v76;
                  HIDWORD(v77) = v32;
                  v76.m128i_i16[m_sliceAxis] = m_showSingleSliceIndex;
                  v76.m128i_i16[m_sliceAxis + 4] = m_showSingleSliceIndex + 1;
                  goto LABEL_41;
                }
              }
              m_regionMap = (hkArray<int,hkContainerHeapAllocator> *)p_array;
LABEL_75:
              v78 += 4i64;
              ++v22;
              v24 = v78;
              v23 = pos.m_quad.m128_u64[0] + 24;
              pos.m_quad.m128_u64[0] += 24i64;
              if ( v22 >= v7[1].m128_i32[2] )
              {
                m_capacityAndFlags = array.m_capacityAndFlags;
                break;
              }
              continue;
            }
          }
          array.m_size = 0;
          if ( m_capacityAndFlags >= 0 )
            hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
              &hkContainerHeapAllocator::s_alloc,
              array.m_data,
              4 * m_capacityAndFlags);
          v3 = vars0;
          v6 = rand[0];
          array.m_data = 0i64;
          array.m_capacityAndFlags = 0x80000000;
        }
      }
      *(_QWORD *)&v6 += 48i64;
      ++v5;
      rand[0] = v6;
    }
    while ( v5 < v3->m_instances.m_size );
  }
}
      ++v5;
      rand[0] = v6;
    }
    while ( v5 < v3->m_instances.m_size );
  }
}

// File Line: 258
// RVA: 0xC4C730
void __fastcall hkaiNavVolumeDebugUtils::showCell(
        hkaiNavVolumeDebugUtils::DebugInfo *info,
        hkaiNavVolume *navVolume,
        unsigned int cellIndex,
        unsigned int color)
{
  bool v4; // zf
  hkaiNavVolume::Cell *m_data; // r10
  __m128 m_quad; // xmm0
  int v10; // eax
  __m128 v11; // xmm0
  unsigned int v12; // eax
  hkVector4f pointInOut; // [rsp+30h] [rbp-E8h] BYREF
  hkVector4f offset; // [rsp+40h] [rbp-D8h] BYREF
  hkVector4f scale; // [rsp+50h] [rbp-C8h] BYREF
  hkAabb _aabb; // [rsp+60h] [rbp-B8h] BYREF
  hkStringBuf v17; // [rsp+80h] [rbp-98h] BYREF

  v4 = info->m_labelCells.m_bool == 0;
  m_data = navVolume->m_cells.m_data;
  m_quad = navVolume->m_quantizationOffset.m_quad;
  scale.m_quad = (__m128)navVolume->m_quantizationScale;
  offset.m_quad = m_quad;
  v10 = m_data[cellIndex].m_max[0];
  _aabb.m_min.m_quad = _mm_unpacklo_ps(
                         _mm_unpacklo_ps(
                           (__m128)COERCE_UNSIGNED_INT((float)m_data[cellIndex].m_min[0]),
                           (__m128)COERCE_UNSIGNED_INT((float)m_data[cellIndex].m_min[2])),
                         _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)m_data[cellIndex].m_min[1]), (__m128)0i64));
  _aabb.m_max.m_quad = _mm_unpacklo_ps(
                         _mm_unpacklo_ps(
                           (__m128)COERCE_UNSIGNED_INT((float)v10),
                           (__m128)COERCE_UNSIGNED_INT((float)m_data[cellIndex].m_max[2])),
                         _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)m_data[cellIndex].m_max[1]), (__m128)0i64));
  if ( !v4 )
  {
    pointInOut.m_quad = _mm_mul_ps(
                          _mm_add_ps(
                            _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)COERCE_UNSIGNED_INT((float)m_data[cellIndex].m_max[0]),
                                (__m128)COERCE_UNSIGNED_INT((float)m_data[cellIndex].m_max[2])),
                              _mm_unpacklo_ps(
                                (__m128)COERCE_UNSIGNED_INT((float)m_data[cellIndex].m_max[1]),
                                (__m128)0i64)),
                            _mm_unpacklo_ps(
                              _mm_unpacklo_ps(
                                (__m128)COERCE_UNSIGNED_INT((float)m_data[cellIndex].m_min[0]),
                                (__m128)COERCE_UNSIGNED_INT((float)m_data[cellIndex].m_min[2])),
                              _mm_unpacklo_ps(
                                (__m128)COERCE_UNSIGNED_INT((float)m_data[cellIndex].m_min[1]),
                                (__m128)0i64))),
                          (__m128)xmmword_141A711B0);
    hkaiNavVolume::convertPointToWorld(navVolume, &pointInOut);
    v11 = _mm_add_ps(pointInOut.m_quad, info->m_displayOffset.m_quad);
    v17.m_string.m_capacityAndFlags = -2147483520;
    v17.m_string.m_size = 1;
    pointInOut.m_quad = v11;
    v17.m_string.m_data = v17.m_string.m_storage;
    v17.m_string.m_storage[0] = 0;
    hkStringBuf::printf(&v17, "%d", cellIndex);
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
        &hkContainerTempAllocator::s_alloc,
        v17.m_string.m_data,
        v17.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  }
  v12 = hkColor::rgbFromFloats(
          (float)BYTE2(color) * 0.0039215689,
          (float)BYTE1(color) * 0.0039215689,
          (float)(unsigned __int8)color * 0.0039215689,
          info->m_transparency);
  hkaiNavVolumeDebugUtils::showCellAabb(info, &_aabb, &offset, &scale, v12);
}

// File Line: 292
// RVA: 0xC4E270
void __fastcall hkaiNavVolumeDebugUtils::showCellAabb(
        hkaiNavVolumeDebugUtils::DebugInfo *info,
        hkAabb *_aabb,
        hkVector4f *offset,
        hkVector4f *scale,
        unsigned int color)
{
  hkVector4f v6; // xmm4
  __m128 v7; // xmm2
  __m128 v8; // xmm4
  bool v9; // zf
  hkAabb aabb; // [rsp+30h] [rbp-28h] BYREF

  v6.m_quad = (__m128)_aabb->m_max;
  v7 = _mm_mul_ps(scale->m_quad, _mm_mul_ps(_mm_sub_ps(v6.m_quad, _aabb->m_min.m_quad), (__m128)xmmword_141A711B0));
  v8 = _mm_add_ps(
         _mm_add_ps(
           _mm_mul_ps(_mm_mul_ps(_mm_add_ps(v6.m_quad, _aabb->m_min.m_quad), (__m128)xmmword_141A711B0), scale->m_quad),
           offset->m_quad),
         info->m_displayOffset.m_quad);
  if ( info->m_shrinkCells.m_bool )
    v7 = _mm_mul_ps(v7, (__m128)_xmm);
  v9 = info->m_showCells.m_bool == 0;
  aabb.m_max.m_quad = _mm_add_ps(v7, v8);
  aabb.m_min.m_quad = _mm_sub_ps(v8, v7);
  if ( !v9 )
    hkaiNavVolumeDebugUtils::displayAabb(&aabb, color);
  if ( info->m_showCellBorders.m_bool )
    hkDebugDisplay::displayAabb(
      hkSingleton<hkDebugDisplay>::s_instance,
      &aabb,
      info->m_cellBorderColor,
      0,
      (int)hkDebugDisplayProcess::m_tag);
}

// File Line: 322
// RVA: 0xC4C990
void __fastcall hkaiNavVolumeDebugUtils::displayAabb(hkAabb *aabb, unsigned int color)
{
  hkVector4f *v4; // rax
  __int32 v5; // ecx
  hkVector4f v6; // xmm0
  hkVector4f v7; // xmm1
  int v8; // eax
  int v9; // ecx
  int v10; // r9d
  __m128 v11; // xmm10
  __m128 v12; // xmm6
  __m128 v13; // xmm7
  int v14; // eax
  int v15; // r9d
  __int64 v16; // rbx
  __m128 v17; // xmm8
  int v18; // eax
  int v19; // r9d
  __int64 v20; // rbx
  __m128 v21; // xmm9
  int v22; // eax
  int v23; // r9d
  __int64 v24; // rbx
  int v25; // eax
  int v26; // r9d
  __int64 v27; // rbx
  __m128 v28; // xmm6
  int v29; // eax
  int v30; // r9d
  __int64 v31; // rbx
  int v32; // eax
  int v33; // r9d
  __int64 v34; // rbx
  int v35; // ecx
  int v36; // r9d
  __int64 v37; // rbx
  hkVector4f *array; // [rsp+28h] [rbp-29h] BYREF
  int v39; // [rsp+30h] [rbp-21h]
  int v40; // [rsp+34h] [rbp-1Dh]
  __m128 m_quad; // [rsp+38h] [rbp-19h]
  hkVector4f v42; // [rsp+48h] [rbp-9h]
  hkResult result; // [rsp+C0h] [rbp+6Fh] BYREF

  if ( HIBYTE(color) )
  {
    array = 0i64;
    v39 = 0;
    v40 = 0x80000000;
    result.m_enum = 128;
    v4 = (hkVector4f *)hkContainerTempAllocator::s_alloc.vfptr->bufAlloc(&hkContainerTempAllocator::s_alloc, &result);
    v39 = 8;
    array = v4;
    v5 = 0x80000000;
    if ( result.m_enum / 16 )
      v5 = result.m_enum / 16;
    v40 = v5;
    v6.m_quad = (__m128)aabb->m_min;
    v7.m_quad = (__m128)aabb->m_max;
    v8 = 0;
    v9 = v5 & 0x3FFFFFFF;
    v39 = 0;
    m_quad = v6.m_quad;
    v42.m_quad = v7.m_quad;
    if ( v9 < 1 )
    {
      v10 = 1;
      if ( 2 * v9 > 1 )
        v10 = 2 * v9;
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v10, 16);
      v8 = v39;
    }
    v11 = (__m128)m_quad.m128_u32[2];
    v12 = (__m128)m_quad.m128_u32[1];
    v13 = (__m128)m_quad.m128_u32[0];
    v39 = v8 + 1;
    array->m_quad = _mm_unpacklo_ps(
                      _mm_unpacklo_ps((__m128)m_quad.m128_u32[0], (__m128)m_quad.m128_u32[2]),
                      _mm_unpacklo_ps((__m128)m_quad.m128_u32[1], (__m128)0i64));
    v14 = v39;
    v15 = v39 + 1;
    v16 = v39;
    if ( (v40 & 0x3FFFFFFF) < v39 + 1 )
    {
      if ( v15 < 2 * (v40 & 0x3FFFFFFF) )
        v15 = 2 * (v40 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v15, 16);
      v14 = v39;
    }
    v17 = (__m128)v42.m_quad.m128_u32[2];
    v39 = v14 + 1;
    array[v16].m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps(v13, (__m128)v42.m_quad.m128_u32[2]),
                          _mm_unpacklo_ps(v12, (__m128)0i64));
    v18 = v39;
    v19 = v39 + 1;
    v20 = v39;
    if ( (v40 & 0x3FFFFFFF) < v39 + 1 )
    {
      if ( v19 < 2 * (v40 & 0x3FFFFFFF) )
        v19 = 2 * (v40 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v19, 16);
      v18 = v39;
    }
    v21 = (__m128)v42.m_quad.m128_u32[0];
    v39 = v18 + 1;
    array[v20].m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps((__m128)v42.m_quad.m128_u32[0], v17),
                          _mm_unpacklo_ps(v12, (__m128)0i64));
    v22 = v39;
    v23 = v39 + 1;
    v24 = v39;
    if ( (v40 & 0x3FFFFFFF) < v39 + 1 )
    {
      if ( v23 < 2 * (v40 & 0x3FFFFFFF) )
        v23 = 2 * (v40 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v23, 16);
      v22 = v39;
    }
    v39 = v22 + 1;
    array[v24].m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v21, v11), _mm_unpacklo_ps(v12, (__m128)0i64));
    v25 = v39;
    v26 = v39 + 1;
    v27 = v39;
    if ( (v40 & 0x3FFFFFFF) < v39 + 1 )
    {
      if ( v26 < 2 * (v40 & 0x3FFFFFFF) )
        v26 = 2 * (v40 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v26, 16);
      v25 = v39;
    }
    v28 = (__m128)v42.m_quad.m128_u32[1];
    v39 = v25 + 1;
    array[v27].m_quad = _mm_unpacklo_ps(
                          _mm_unpacklo_ps(v13, v11),
                          _mm_unpacklo_ps((__m128)v42.m_quad.m128_u32[1], (__m128)0i64));
    v29 = v39;
    v30 = v39 + 1;
    v31 = v39;
    if ( (v40 & 0x3FFFFFFF) < v39 + 1 )
    {
      if ( v30 < 2 * (v40 & 0x3FFFFFFF) )
        v30 = 2 * (v40 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v30, 16);
      v29 = v39;
    }
    v39 = v29 + 1;
    array[v31].m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v13, v17), _mm_unpacklo_ps(v28, (__m128)0i64));
    v32 = v39;
    v33 = v39 + 1;
    v34 = v39;
    if ( (v40 & 0x3FFFFFFF) < v39 + 1 )
    {
      if ( v33 < 2 * (v40 & 0x3FFFFFFF) )
        v33 = 2 * (v40 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v33, 16);
      v32 = v39;
    }
    v39 = v32 + 1;
    array[v34].m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v21, v17), _mm_unpacklo_ps(v28, (__m128)0i64));
    v35 = v39;
    v36 = v39 + 1;
    v37 = v39;
    if ( (v40 & 0x3FFFFFFF) < v39 + 1 )
    {
      if ( v36 < 2 * (v40 & 0x3FFFFFFF) )
        v36 = 2 * (v40 & 0x3FFFFFFF);
      hkArrayUtil::_reserve(&result, &hkContainerTempAllocator::s_alloc, &array, v36, 16);
      v35 = v39;
    }
    v39 = v35 + 1;
    array[v37].m_quad = _mm_unpacklo_ps(_mm_unpacklo_ps(v21, v11), _mm_unpacklo_ps(v28, (__m128)0i64));
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array, array + 3, array + 1, color);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 1, array + 3, array + 2, color);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 2, array + 6, array + 5, color);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 5, array + 1, array + 2, color);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 5, array + 6, array + 4, color);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 4, array + 6, array + 7, color);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 7, array + 3, array, color);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array, array + 4, array + 7, color);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array, array + 1, array + 4, color);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 4, array + 1, array + 5, color);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 2, array + 3, array + 6, color);
    hkDebugDisplay::displayLitTriangle(hkSingleton<hkDebugDisplay>::s_instance, array + 6, array + 3, array + 7, color);
    v39 = 0;
    if ( v40 >= 0 )
      hkContainerTempAllocator::s_alloc.vfptr->bufFree(&hkContainerTempAllocator::s_alloc, array, 16 * v40);
  }
}

// File Line: 360
// RVA: 0xC4CFC0
void __fastcall hkaiNavVolumeDebugUtils::displayCellCenter(
        hkaiNavVolume *navVolume,
        int cellIndex,
        hkVector4f *displayOffset)
{
  __int64 v3; // rax
  hkaiNavVolume::Cell *m_data; // rdx
  hkVector4f position; // [rsp+30h] [rbp-18h] BYREF

  v3 = cellIndex;
  m_data = navVolume->m_cells.m_data;
  position.m_quad = _mm_add_ps(
                      _mm_add_ps(
                        _mm_mul_ps(
                          _mm_mul_ps(
                            _mm_add_ps(
                              _mm_unpacklo_ps(
                                _mm_unpacklo_ps(
                                  (__m128)COERCE_UNSIGNED_INT((float)m_data[v3].m_max[0]),
                                  (__m128)COERCE_UNSIGNED_INT((float)m_data[v3].m_max[2])),
                                _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)m_data[v3].m_max[1]), (__m128)0i64)),
                              _mm_unpacklo_ps(
                                _mm_unpacklo_ps(
                                  (__m128)COERCE_UNSIGNED_INT((float)m_data[v3].m_min[0]),
                                  (__m128)COERCE_UNSIGNED_INT((float)m_data[v3].m_min[2])),
                                _mm_unpacklo_ps((__m128)COERCE_UNSIGNED_INT((float)m_data[v3].m_min[1]), (__m128)0i64))),
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
  int v3; // r14d
  int m_size; // edi
  hkOstream *v5; // rax
  hkOstream *v6; // rax
  hkOstream *v7; // rax
  hkOstream *v8; // rax
  hkOstream *v9; // rax
  hkOstream *v10; // rax
  hkOstream *v11; // rax
  hkOstream *v12; // rax
  hkOstream *v13; // rax
  hkErrStream v14; // [rsp+20h] [rbp-228h] BYREF
  char buf[512]; // [rsp+40h] [rbp-208h] BYREF

  v1 = navVolume;
  v2 = 24 * navVolume->m_cells.m_size;
  v3 = 8 * navVolume->m_edges.m_size;
  ((void (__fastcall *)(hkError *, __int64, const char *))hkSingleton<hkError>::s_instance->vfptr[4].__first_virtual_table_function__)(
    hkSingleton<hkError>::s_instance,
    1367214621i64,
    "hkaiNavMeshDebugUtils::reportMemoryUsed");
  hkErrStream::hkErrStream(&v14, buf, 512);
  m_size = v1->m_edges.m_size;
  LODWORD(v1) = v1->m_cells.m_size;
  v5 = hkOstream::operator<<(&v14, "\nMemory:\n Cells ( ");
  v6 = hkOstream::operator<<(v5, (int)v1);
  v7 = hkOstream::operator<<(v6, " )\t:");
  v8 = hkOstream::operator<<(v7, v2);
  v9 = hkOstream::operator<<(v8, "\n Edges ( ");
  v10 = hkOstream::operator<<(v9, m_size);
  v11 = hkOstream::operator<<(v10, " )\t:");
  v12 = hkOstream::operator<<(v11, v3);
  v13 = hkOstream::operator<<(v12, "\n Total:");
  hkOstream::operator<<(v13, v3 + v2 + 160);
  hkError::messageReport(-1, buf, "Debug\\hkaiNavVolumeDebugUtils.cpp", 383);
  hkOstream::~hkOstream(&v14);
  ((void (__fastcall *)(hkError *))hkSingleton<hkError>::s_instance->vfptr[5].__vecDelDtor)(hkSingleton<hkError>::s_instance);
}

// File Line: 469
// RVA: 0xC4E340
void __fastcall `anonymous namespace::cutSquareVertically(
        Square *square,
        Square *cutter,
        hkArray<Square,hkContainerHeapAllocator> *squaresOut)
{
  float minX; // xmm6_4
  float v7; // xmm6_4
  int v8; // eax
  Square *v9; // rcx
  float v10; // xmm7_4
  float v11; // xmm8_4
  float v12; // xmm9_4
  Square *v13; // rax
  float maxX; // xmm0_4
  float v15; // xmm7_4
  float v16; // xmm8_4
  float v17; // xmm9_4
  Square *v18; // rax
  float v19; // xmm7_4
  float minY; // xmm8_4
  float maxY; // xmm9_4
  Square *v22; // rax
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm8_4
  float v26; // xmm9_4
  Square *v27; // rax

  minX = cutter->minX;
  if ( cutter->minX > square->minX )
  {
    maxX = square->maxX;
    v8 = squaresOut->m_capacityAndFlags & 0x3FFFFFFF;
    if ( maxX > cutter->maxX )
    {
      v19 = square->minX;
      minY = square->minY;
      maxY = square->maxY;
      if ( squaresOut->m_size == v8 )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, squaresOut, 16);
      v22 = &squaresOut->m_data[squaresOut->m_size];
      if ( v22 )
      {
        v22->minX = v19;
        v22->minY = minY;
        v22->maxX = minX;
        v22->maxY = maxY;
      }
      ++squaresOut->m_size;
      v23 = square->minY;
      v24 = square->maxX;
      v25 = square->maxY;
      v26 = cutter->maxX;
      if ( squaresOut->m_size == (squaresOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, squaresOut, 16);
      v27 = &squaresOut->m_data[squaresOut->m_size];
      if ( v27 )
      {
        v27->minX = v26;
        v27->minY = v23;
        v27->maxX = v24;
        v27->maxY = v25;
      }
      goto LABEL_27;
    }
    if ( minX <= maxX )
    {
      v15 = square->minX;
      v16 = square->minY;
      v17 = square->maxY;
      if ( squaresOut->m_size == v8 )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, squaresOut, 16);
      v18 = &squaresOut->m_data[squaresOut->m_size];
      if ( v18 )
      {
        v18->minX = v15;
        v18->minY = v16;
        v18->maxX = minX;
        v18->maxY = v17;
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
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, squaresOut, 16);
    v9 = &squaresOut->m_data[squaresOut->m_size];
    if ( v9 )
    {
      v9->minX = square->minX;
      v9->minY = square->minY;
      v9->maxX = square->maxX;
      v9->maxY = square->maxY;
    }
    goto LABEL_27;
  }
  if ( v7 >= square->maxX )
    return;
  v10 = square->minY;
  v11 = square->maxX;
  v12 = square->maxY;
  if ( squaresOut->m_size == (squaresOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, squaresOut, 16);
  v13 = &squaresOut->m_data[squaresOut->m_size];
  if ( v13 )
  {
    v13->minX = v7;
    v13->minY = v10;
    v13->maxX = v11;
    v13->maxY = v12;
  }
LABEL_27:
  ++squaresOut->m_size;
}

// File Line: 519
// RVA: 0xC4E5B0
void __fastcall `anonymous namespace::cutSquare(
        Square *_square,
        Square *_cutter,
        hkArray<Square,hkContainerHeapAllocator> *squaresOut)
{
  Square v3; // xmm6
  hkArray<Square,hkContainerHeapAllocator> *v4; // rbx
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float minX; // xmm3_4
  float maxX; // xmm0_4
  float minY; // xmm8_4
  float maxY; // xmm7_4
  float v13; // xmm0_4
  int v14; // eax
  Square *v15; // rax
  __int64 v16; // rax
  float v17; // xmm1_4
  float v18; // xmm0_4
  __int64 v19; // rax
  float v20; // xmm1_4
  float v21; // xmm0_4
  Square *v22; // rax
  int m_capacityAndFlags; // eax
  __int64 v24; // rax
  float v25; // xmm1_4
  float v26; // xmm0_4
  Square cutter; // [rsp+20h] [rbp-50h] BYREF
  Square square; // [rsp+30h] [rbp-40h] BYREF

  v4 = squaresOut;
  cutter = *_square;
  v3 = cutter;
  v5 = _mm_shuffle_ps((__m128)v3, (__m128)v3, 170).m128_f32[0];
  if ( cutter.minX > v5 )
  {
    cutter.minX = v5;
    cutter.maxX = v3.minX;
    v3 = cutter;
  }
  v6 = _mm_shuffle_ps((__m128)v3, (__m128)v3, 85).m128_f32[0];
  v7 = _mm_shuffle_ps((__m128)v3, (__m128)v3, 255).m128_f32[0];
  if ( v6 > v7 )
  {
    v8 = v6;
    v6 = v7;
    v7 = v8;
    cutter.minY = v6;
    cutter.maxY = v8;
    v3 = cutter;
  }
  maxX = _cutter->maxX;
  minY = _cutter->minY;
  maxY = _cutter->maxY;
  cutter.minX = _cutter->minX;
  minX = cutter.minX;
  cutter.minY = minY;
  cutter.maxX = maxX;
  cutter.maxY = maxY;
  if ( cutter.minX > maxX )
  {
    cutter.minX = maxX;
    cutter.maxX = minX;
  }
  if ( minY > maxY )
  {
    v13 = minY;
    minY = maxY;
    maxY = v13;
    cutter.minY = minY;
    cutter.maxY = v13;
  }
  if ( minY > v6 )
  {
    v14 = squaresOut->m_capacityAndFlags & 0x3FFFFFFF;
    if ( maxY >= v7 )
    {
      if ( minY > v7 )
        goto LABEL_12;
      square = v3;
      if ( squaresOut->m_size == v14 )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, squaresOut, 16);
      v19 = (__int64)&v4->m_data[v4->m_size];
      if ( v19 )
      {
        v20 = square.minY;
        *(float *)v19 = square.minX;
        v21 = square.maxX;
        *(float *)(v19 + 4) = v20;
        *(float *)(v19 + 8) = v21;
        *(float *)(v19 + 12) = minY;
      }
      square = v3;
      square.minY = minY;
      goto LABEL_40;
    }
    square = v3;
    square.maxY = minY;
    if ( squaresOut->m_size == v14 )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, squaresOut, 16);
    v22 = &v4->m_data[v4->m_size];
    if ( v22 )
      *v22 = square;
    m_capacityAndFlags = v4->m_capacityAndFlags;
    ++v4->m_size;
    square = v3;
    if ( v4->m_size == (m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, v4, 16);
    v24 = (__int64)&v4->m_data[v4->m_size];
    if ( v24 )
    {
      v25 = square.maxY;
      *(float *)v24 = square.minX;
      v26 = square.maxX;
      *(float *)(v24 + 4) = maxY;
      *(float *)(v24 + 8) = v26;
      *(float *)(v24 + 12) = v25;
    }
    square = v3;
    square.minY = minY;
LABEL_39:
    square.maxY = maxY;
LABEL_40:
    ++v4->m_size;
    squaresOut = v4;
    goto LABEL_41;
  }
  if ( maxY > v6 )
  {
    square = v3;
    if ( maxY >= v7 )
    {
LABEL_41:
      `anonymous namespace::cutSquareVertically(&square, &cutter, squaresOut);
      return;
    }
    if ( squaresOut->m_size == (squaresOut->m_capacityAndFlags & 0x3FFFFFFF) )
      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, squaresOut, 16);
    v16 = (__int64)&v4->m_data[v4->m_size];
    if ( v16 )
    {
      v17 = square.maxY;
      *(float *)v16 = square.minX;
      v18 = square.maxX;
      *(float *)(v16 + 4) = maxY;
      *(float *)(v16 + 8) = v18;
      *(float *)(v16 + 12) = v17;
    }
    square = v3;
    goto LABEL_39;
  }
  v14 = squaresOut->m_capacityAndFlags & 0x3FFFFFFF;
LABEL_12:
  if ( squaresOut->m_size == v14 )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, squaresOut, 16);
  v15 = &v4->m_data[v4->m_size];
  if ( v15 )
    *v15 = v3;
  ++v4->m_size;
}

// File Line: 595
// RVA: 0xC4E880
void __fastcall `anonymous namespace::cutSquaresFromSquare(
        Square *square,
        hkArray<Square,hkContainerHeapAllocator> *cutters,
        hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *squaresOut)
{
  Square *v6; // rcx
  int m_capacityAndFlags; // r8d
  Square *m_data; // rdx
  int v9; // ebp
  int v10; // ebx
  hkArray<Square,hkContainerHeapAllocator> squaresOuta; // [rsp+20h] [rbp-28h] BYREF

  if ( squaresOut->m_size == (squaresOut->m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, squaresOut, 16);
  v6 = (Square *)&squaresOut->m_data[squaresOut->m_size];
  if ( v6 )
  {
    v6->minX = square->minX;
    v6->minY = square->minY;
    v6->maxX = square->maxX;
    v6->maxY = square->maxY;
  }
  ++squaresOut->m_size;
  m_capacityAndFlags = 0x80000000;
  m_data = 0i64;
  squaresOuta.m_capacityAndFlags = 0x80000000;
  v9 = 0;
  squaresOuta.m_data = 0i64;
  if ( cutters->m_size > 0 )
  {
    do
    {
      v10 = 0;
      for ( squaresOuta.m_size = 0; v10 < squaresOut->m_size; ++v10 )
        `anonymous namespace::cutSquare((Square *)&squaresOut->m_data[v10], &cutters->m_data[v9], &squaresOuta);
      hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
        squaresOut,
        (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&squaresOuta);
      ++v9;
    }
    while ( v9 < cutters->m_size );
    m_capacityAndFlags = squaresOuta.m_capacityAndFlags;
    m_data = squaresOuta.m_data;
  }
  squaresOuta.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      m_data,
      16 * m_capacityAndFlags);
}

// File Line: 611
// RVA: 0xC4E9D0
void __fastcall `anonymous namespace::convertAabbFaceToSquare(hkAabb *aabb, int face, Square *squareOut)
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
      LODWORD(squareOut->minY) = aabb->m_min.m_quad.m128_i32[2];
      LODWORD(squareOut->maxX) = aabb->m_max.m_quad.m128_i32[0];
      LODWORD(squareOut->maxY) = aabb->m_max.m_quad.m128_i32[2];
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
void __fastcall `anonymous namespace::processCutSquares(
        hkArray<Square,hkContainerHeapAllocator> *squares,
        hkAabb *aabb,
        int face,
        hkGeometry *geometryOut)
{
  int v4; // r15d
  __m128 v8; // xmm8
  __int64 v9; // rsi
  __m128 v10; // xmm9
  __m128 v11; // xmm10
  __m128 v12; // xmm11
  Square *m_data; // rax
  __m128 minX_low; // xmm5
  __m128 maxX_low; // xmm4
  __m128 minY_low; // xmm7
  __m128 maxY_low; // xmm6
  __m128 v18; // xmm1
  __m128 v19; // xmm0
  __m128 v20; // xmm11
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm3
  int m_size; // edi
  int v25; // eax
  int v26; // r9d
  int v27; // eax
  hkVector4f *v28; // rax
  __int64 v29; // r14
  int v30; // r9d
  int v31; // eax
  int v32; // eax
  hkGeometry::Triangle *v33; // rdx
  hkResult result; // [rsp+40h] [rbp-C8h] BYREF
  hkResult v35; // [rsp+44h] [rbp-C4h] BYREF
  __m128 v36; // [rsp+50h] [rbp-B8h]
  hkAabb *v37; // [rsp+118h] [rbp+10h]

  v37 = aabb;
  v4 = 0;
  if ( squares->m_size > 0 )
  {
    v8 = v36;
    v9 = 0i64;
    v10 = v36;
    v11 = v36;
    v12 = v36;
    do
    {
      m_data = squares->m_data;
      minX_low = (__m128)LODWORD(squares->m_data[v9].minX);
      maxX_low = (__m128)LODWORD(squares->m_data[v9].maxX);
      if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(squares->m_data[v9].minX - maxX_low.m128_f32[0])) >> 1) > 0.000001 )
      {
        minY_low = (__m128)LODWORD(m_data[v9].minY);
        maxY_low = (__m128)LODWORD(m_data[v9].maxY);
        if ( COERCE_FLOAT((unsigned int)(2 * COERCE_INT(minY_low.m128_f32[0] - maxY_low.m128_f32[0])) >> 1) > 0.000001 )
        {
          switch ( face )
          {
            case 0:
              v18 = 0i64;
              v19 = (__m128)LODWORD(m_data[v9].minY);
              v20 = (__m128)aabb->m_min.m_quad.m128_u32[0];
              v8 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, minY_low), _mm_unpacklo_ps(minX_low, (__m128)0i64));
              v10 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, maxY_low), _mm_unpacklo_ps(minX_low, (__m128)0i64));
              v11 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, maxY_low), _mm_unpacklo_ps(maxX_low, (__m128)0i64));
              v21 = (__m128)LODWORD(squares->m_data[v9].maxX);
              goto LABEL_13;
            case 1:
              v18 = 0i64;
              v19 = (__m128)LODWORD(m_data[v9].maxY);
              v20 = (__m128)aabb->m_max.m_quad.m128_u32[0];
              v8 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, minY_low), _mm_unpacklo_ps(minX_low, (__m128)0i64));
              v10 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, minY_low), _mm_unpacklo_ps(maxX_low, (__m128)0i64));
              v11 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, maxY_low), _mm_unpacklo_ps(maxX_low, (__m128)0i64));
              v21 = (__m128)LODWORD(squares->m_data[v9].minX);
              goto LABEL_13;
            case 2:
              v18 = 0i64;
              v19 = (__m128)LODWORD(m_data[v9].maxY);
              v8 = _mm_unpacklo_ps(
                     _mm_unpacklo_ps(minX_low, minY_low),
                     _mm_unpacklo_ps((__m128)aabb->m_min.m_quad.m128_u32[1], (__m128)0i64));
              v10 = _mm_unpacklo_ps(
                      _mm_unpacklo_ps(maxX_low, minY_low),
                      _mm_unpacklo_ps((__m128)aabb->m_min.m_quad.m128_u32[1], (__m128)0i64));
              v11 = _mm_unpacklo_ps(
                      _mm_unpacklo_ps(maxX_low, maxY_low),
                      _mm_unpacklo_ps((__m128)aabb->m_min.m_quad.m128_u32[1], (__m128)0i64));
              v21 = (__m128)aabb->m_min.m_quad.m128_u32[1];
              goto LABEL_12;
            case 3:
              v18 = 0i64;
              v19 = (__m128)LODWORD(m_data[v9].minY);
              v20 = (__m128)LODWORD(squares->m_data[v9].maxX);
              v8 = _mm_unpacklo_ps(
                     _mm_unpacklo_ps(minX_low, minY_low),
                     _mm_unpacklo_ps((__m128)aabb->m_max.m_quad.m128_u32[1], (__m128)0i64));
              v10 = _mm_unpacklo_ps(
                      _mm_unpacklo_ps(minX_low, maxY_low),
                      _mm_unpacklo_ps((__m128)aabb->m_max.m_quad.m128_u32[1], (__m128)0i64));
              v11 = _mm_unpacklo_ps(
                      _mm_unpacklo_ps(maxX_low, maxY_low),
                      _mm_unpacklo_ps((__m128)aabb->m_max.m_quad.m128_u32[1], (__m128)0i64));
              v21 = (__m128)aabb->m_max.m_quad.m128_u32[1];
              goto LABEL_13;
            case 4:
              v22 = (__m128)aabb->m_min.m_quad.m128_u32[2];
              v18 = 0i64;
              v19 = v22;
              v20 = (__m128)LODWORD(squares->m_data[v9].maxX);
              v8 = _mm_unpacklo_ps(_mm_unpacklo_ps(minX_low, v22), _mm_unpacklo_ps(minY_low, (__m128)0i64));
              v10 = _mm_unpacklo_ps(_mm_unpacklo_ps(minX_low, v22), _mm_unpacklo_ps(maxY_low, (__m128)0i64));
              v11 = _mm_unpacklo_ps(_mm_unpacklo_ps(maxX_low, v22), _mm_unpacklo_ps(maxY_low, (__m128)0i64));
              v21 = (__m128)LODWORD(m_data[v9].minY);
              goto LABEL_13;
            case 5:
              v23 = (__m128)aabb->m_max.m_quad.m128_u32[2];
              v18 = 0i64;
              v19 = v23;
              v8 = _mm_unpacklo_ps(_mm_unpacklo_ps(minX_low, v23), _mm_unpacklo_ps(minY_low, (__m128)0i64));
              v10 = _mm_unpacklo_ps(_mm_unpacklo_ps(maxX_low, v23), _mm_unpacklo_ps(minY_low, (__m128)0i64));
              v11 = _mm_unpacklo_ps(_mm_unpacklo_ps(maxX_low, v23), _mm_unpacklo_ps(maxY_low, (__m128)0i64));
              v21 = (__m128)LODWORD(m_data[v9].maxY);
LABEL_12:
              v20 = (__m128)LODWORD(squares->m_data[v9].minX);
LABEL_13:
              v12 = _mm_unpacklo_ps(_mm_unpacklo_ps(v20, v19), _mm_unpacklo_ps(v21, v18));
              break;
            default:
              break;
          }
          if ( geometryOut )
          {
            m_size = geometryOut->m_vertices.m_size;
            v25 = geometryOut->m_vertices.m_capacityAndFlags & 0x3FFFFFFF;
            v26 = m_size + 4;
            if ( v25 >= m_size + 4 )
            {
              result.m_enum = HK_SUCCESS;
            }
            else
            {
              v27 = 2 * v25;
              if ( v26 < v27 )
                v26 = v27;
              hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &geometryOut->m_vertices, v26, 16);
            }
            geometryOut->m_vertices.m_size += 4;
            v28 = &geometryOut->m_vertices.m_data[m_size];
            *v28 = (hkVector4f)v8;
            v28[1] = (hkVector4f)v10;
            v28[2] = (hkVector4f)v11;
            v28[3] = (hkVector4f)v12;
            v29 = geometryOut->m_triangles.m_size;
            v30 = v29 + 2;
            v31 = geometryOut->m_triangles.m_capacityAndFlags & 0x3FFFFFFF;
            if ( v31 >= (int)v29 + 2 )
            {
              v35.m_enum = HK_SUCCESS;
            }
            else
            {
              v32 = 2 * v31;
              if ( v30 < v32 )
                v30 = v32;
              hkArrayUtil::_reserve(&v35, &hkContainerHeapAllocator::s_alloc, &geometryOut->m_triangles, v30, 16);
            }
            geometryOut->m_triangles.m_size += 2;
            v33 = &geometryOut->m_triangles.m_data[v29];
            v33->m_b = m_size + 1;
            v33->m_a = m_size + 2;
            v33->m_c = m_size;
            v33->m_material = -1;
            v33[1].m_a = m_size;
            v33[1].m_c = m_size + 2;
            v33[1].m_material = -1;
            v33[1].m_b = m_size + 3;
            aabb = v37;
          }
        }
      }
      ++v4;
      ++v9;
    }
    while ( v4 < squares->m_size );
  }
}

// File Line: 715
// RVA: 0xC4D260
void __fastcall hkaiNavVolumeDebugUtils::GeomteryBuildSettings::GeomteryBuildSettings(
        hkaiNavVolumeDebugUtils::GeomteryBuildSettings *this)
{
  this->m_skipBoundingFaces = 1;
  this->m_filter.m_pntr = 0i64;
}

// File Line: 728
// RVA: 0xC4D280
void __fastcall hkaiNavVolumeDebugUtils::GeomteryDisplaySettings::GeomteryDisplaySettings(
        hkaiNavVolumeDebugUtils::GeomteryDisplaySettings *this)
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
void __fastcall hkaiNavVolumeDebugUtils::GeomteryDisplaySettings::setColorWithVariance(
        hkaiNavVolumeDebugUtils::GeomteryDisplaySettings *this,
        unsigned int color,
        float variance)
{
  this->m_color = color;
  this->m_colorVariance = variance;
  this->m_lineColor = color & 0xFF000000 | (color >> 2) & 0x3F3F3F;
}

// File Line: 740
// RVA: 0xC4D300
void __fastcall hkaiNavVolumeDebugUtils::GeomteryDisplaySettings::setTranslucent(
        hkaiNavVolumeDebugUtils::GeomteryDisplaySettings *this,
        unsigned int color,
        hkVector4f *sortDir,
        unsigned int lineColor)
{
  __m128 m_quad; // xmm0

  this->m_color = color;
  m_quad = sortDir->m_quad;
  this->m_sortGeometry = 1;
  this->m_sortDirection.m_quad = m_quad;
  this->m_lineColor = lineColor;
}

// File Line: 748
// RVA: 0xC4D320
void __fastcall hkaiNavVolumeDebugUtils::buildNavVolumeGeometry(
        hkaiNavVolumeDebugUtils::GeomteryBuildSettings *buildSettings,
        hkaiNavVolume *navVolume,
        hkGeometry *geometryOut)
{
  unsigned int v4; // edx
  __int64 m_size; // rax
  __int64 v8; // r12
  hkaiNavVolumeDebugUtils::GeometryBuildFilter *m_pntr; // rcx
  hkaiNavVolume::Cell *m_data; // r13
  hkVector4f v11; // xmm10
  int v12; // ebx
  int *p_m_size; // r14
  __m128i v14; // xmm1
  __m128i v15; // xmm0
  __m128 v16; // xmm2
  __m128i v17; // xmm0
  hkVector4f v18; // xmm11
  hkVector4f v19; // xmm10
  float v20; // xmm7_4
  float v21; // xmm8_4
  float v22; // xmm9_4
  __m128 v23; // xmm2
  hkVector4f v24; // xmm1
  __int64 m_startEdgeIndex; // rdi
  __int64 v26; // rsi
  hkaiNavVolume::Edge *v27; // r14
  hkaiNavVolumeDebugUtils::GeometryBuildFilter *v28; // rcx
  __m128i v29; // xmm1
  __m128i v30; // xmm0
  __m128 v31; // xmm3
  __m128i v32; // xmm0
  hkVector4f v33; // xmm2
  __m128 v34; // xmm1
  __m128 v35; // xmm0
  __m128 v36; // xmm2
  bool v37; // zf
  bool v38; // cf
  Square *v39; // r8
  __int64 v40; // r8
  hkVector4f v41; // xmm1
  int v42; // ebx
  hkArray<Square,hkContainerHeapAllocator> *p_cutters; // rdi
  int v44; // r8d
  int v45; // edi
  int *v46; // rbx
  int v47; // r8d
  hkArray<Square,hkContainerHeapAllocator> squaresOut; // [rsp+20h] [rbp-C0h] BYREF
  hkArray<Square,hkContainerHeapAllocator> array; // [rsp+30h] [rbp-B0h] BYREF
  Square squareOut; // [rsp+40h] [rbp-A0h] BYREF
  __int64 v51; // [rsp+50h] [rbp-90h]
  int *v52; // [rsp+58h] [rbp-88h]
  hkAabb aabb; // [rsp+60h] [rbp-80h] BYREF
  __m128 v54; // [rsp+80h] [rbp-60h]
  __m128 v55; // [rsp+90h] [rbp-50h]
  hkArray<Square,hkContainerHeapAllocator> cutters; // [rsp+A0h] [rbp-40h] BYREF
  __int64 v57; // [rsp+B0h] [rbp-30h]
  int v58; // [rsp+B8h] [rbp-28h]
  int v59; // [rsp+BCh] [rbp-24h]
  __int64 v60; // [rsp+C0h] [rbp-20h]
  int v61; // [rsp+C8h] [rbp-18h]
  int v62; // [rsp+CCh] [rbp-14h]
  __int64 v63; // [rsp+D0h] [rbp-10h]
  int v64; // [rsp+D8h] [rbp-8h]
  int v65; // [rsp+DCh] [rbp-4h]
  __int64 v66; // [rsp+E0h] [rbp+0h]
  int v67; // [rsp+E8h] [rbp+8h]
  int v68; // [rsp+ECh] [rbp+Ch]
  __int64 v69; // [rsp+F0h] [rbp+10h]
  int v70; // [rsp+F8h] [rbp+18h]
  int v71; // [rsp+FCh] [rbp+1Ch]
  hkAabb v72; // [rsp+100h] [rbp+20h] BYREF
  __m128 v73; // [rsp+120h] [rbp+40h]
  hkaiNavVolumeDebugUtils::GeomteryBuildSettings *v74; // [rsp+220h] [rbp+140h]
  int v75; // [rsp+228h] [rbp+148h]
  hkGeometry *geometryOuta; // [rsp+230h] [rbp+150h]
  void *retaddr; // [rsp+238h] [rbp+158h]

  v4 = 0;
  m_size = navVolume->m_cells.m_size;
  cutters.m_data = 0i64;
  cutters.m_size = 0;
  cutters.m_capacityAndFlags = 0x80000000;
  v57 = 0i64;
  v58 = 0;
  v59 = 0x80000000;
  v60 = 0i64;
  v61 = 0;
  v62 = 0x80000000;
  v63 = 0i64;
  v64 = 0;
  v65 = 0x80000000;
  v66 = 0i64;
  v67 = 0;
  v68 = 0x80000000;
  v69 = 0i64;
  v70 = 0;
  v71 = 0x80000000;
  v75 = 0;
  v51 = m_size;
  if ( m_size > 0 )
  {
    v8 = 0i64;
    do
    {
      m_pntr = buildSettings->m_filter.m_pntr;
      if ( !m_pntr
        || ((unsigned __int8 (__fastcall *)(hkaiNavVolumeDebugUtils::GeometryBuildFilter *, hkaiNavVolume *, _QWORD))m_pntr->vfptr[1].__first_virtual_table_function__)(
             m_pntr,
             navVolume,
             v4) )
      {
        m_data = navVolume->m_cells.m_data;
        v11.m_quad = (__m128)navVolume->m_quantizationScale;
        v12 = 0;
        p_m_size = &cutters.m_size;
        v52 = &cutters.m_size;
        v14 = _mm_loadu_si128((const __m128i *)&m_data[v8]);
        v15 = _mm_unpacklo_epi16(v14, (__m128i)0i64);
        v16 = _mm_add_ps(
                _mm_mul_ps(
                  _mm_cvtepi32_ps(_mm_srli_epi32(v15, 0x10u)),
                  (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v15, 0x10u), 0x10u)));
        v17 = _mm_unpackhi_epi16(v14, (__m128i)0i64);
        v18.m_quad = _mm_add_ps(_mm_mul_ps(v11.m_quad, v16), navVolume->m_quantizationOffset.m_quad);
        aabb.m_min = (hkVector4f)v18.m_quad;
        v19.m_quad = _mm_add_ps(
                       _mm_mul_ps(
                         v11.m_quad,
                         _mm_add_ps(
                           _mm_mul_ps(
                             _mm_cvtepi32_ps(_mm_srli_epi32(v17, 0x10u)),
                             (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                           _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v17, 0x10u), 0x10u)))),
                       navVolume->m_quantizationOffset.m_quad);
        aabb.m_max = (hkVector4f)v19.m_quad;
        v54 = _mm_mul_ps(_mm_add_ps(v19.m_quad, v18.m_quad), (__m128)xmmword_141A711B0);
        v20 = v54.m128_f32[2];
        v21 = v54.m128_f32[1];
        v22 = v54.m128_f32[0];
        do
        {
          if ( buildSettings->m_skipBoundingFaces )
          {
            v23 = _mm_mul_ps((__m128)_xmm, navVolume->m_quantizationScale.m_quad);
            v24.m_quad = _mm_sub_ps(navVolume->m_aabb.m_max.m_quad, v23);
            aabb.m_min.m_quad = _mm_add_ps(navVolume->m_aabb.m_min.m_quad, v23);
            aabb.m_max = (hkVector4f)v24.m_quad;
            switch ( v12 )
            {
              case 0:
              case 2:
              case 4:
                goto LABEL_19;
              case 1:
                v38 = v19.m_quad.m128_f32[0] < aabb.m_max.m_quad.m128_f32[0];
                goto LABEL_18;
              case 3:
                v38 = v19.m_quad.m128_f32[1] < aabb.m_max.m_quad.m128_f32[1];
                goto LABEL_18;
              case 5:
                v38 = v19.m_quad.m128_f32[2] < aabb.m_max.m_quad.m128_f32[2];
LABEL_18:
                if ( v38 )
                  goto LABEL_8;
LABEL_19:
                if ( *p_m_size == (p_m_size[1] & 0x3FFFFFFF) )
                  hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, p_m_size - 2, 16);
                v39 = (Square *)(*((_QWORD *)p_m_size - 1) + 16i64 * (*p_m_size)++);
                `anonymous namespace::convertAabbFaceToSquare(&aabb, v12, v39);
                break;
              default:
                goto LABEL_8;
            }
          }
          else
          {
LABEL_8:
            *(_QWORD *)&squareOut.minX = 0i64;
            *(_QWORD *)&squareOut.maxX = 0i64;
            `anonymous namespace::convertAabbFaceToSquare(&aabb, v12, &squareOut);
            m_startEdgeIndex = m_data[v8].m_startEdgeIndex;
            array.m_capacityAndFlags = 0x80000000;
            array.m_data = 0i64;
            array.m_size = 0;
            if ( (int)m_startEdgeIndex < (int)m_startEdgeIndex + m_data[v8].m_numEdges )
            {
              v26 = m_startEdgeIndex;
              do
              {
                v27 = navVolume->m_edges.m_data;
                v28 = v74->m_filter.m_pntr;
                if ( !v28
                  || ((unsigned __int8 (__fastcall *)(hkaiNavVolumeDebugUtils::GeometryBuildFilter *, hkaiNavVolume *, _QWORD))v28->vfptr[1].__first_virtual_table_function__)(
                       v28,
                       navVolume,
                       v27[v26].m_oppositeCell & 0x3FFFFF) )
                {
                  v29 = _mm_loadu_si128((const __m128i *)&navVolume->m_cells.m_data[v27[v26].m_oppositeCell & 0x3FFFFF]);
                  v30 = _mm_unpacklo_epi16(v29, (__m128i)0i64);
                  v31 = _mm_add_ps(
                          _mm_mul_ps(
                            _mm_cvtepi32_ps(_mm_srli_epi32(v30, 0x10u)),
                            (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                          _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v30, 0x10u), 0x10u)));
                  v32 = _mm_unpackhi_epi16(v29, (__m128i)0i64);
                  v33.m_quad = _mm_add_ps(
                                 _mm_mul_ps(
                                   navVolume->m_quantizationScale.m_quad,
                                   _mm_add_ps(
                                     _mm_mul_ps(
                                       _mm_cvtepi32_ps(_mm_srli_epi32(v32, 0x10u)),
                                       (__m128)`hkIntVector::convertU32ToF32::`2::two16),
                                     _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v32, 0x10u), 0x10u)))),
                                 navVolume->m_quantizationOffset.m_quad);
                  v72.m_min.m_quad = _mm_add_ps(
                                       _mm_mul_ps(navVolume->m_quantizationScale.m_quad, v31),
                                       navVolume->m_quantizationOffset.m_quad);
                  v34 = _mm_min_ps(v19.m_quad, v33.m_quad);
                  v72.m_max = (hkVector4f)v33.m_quad;
                  v55 = _mm_mul_ps(_mm_add_ps(v33.m_quad, v72.m_min.m_quad), (__m128)xmmword_141A711B0);
                  v35 = _mm_max_ps(v18.m_quad, v72.m_min.m_quad);
                  v36 = _mm_mul_ps(_mm_sub_ps(_mm_max_ps(v35, v34), _mm_min_ps(v35, v34)), (__m128)xmmword_141A711B0);
                  LODWORD(retaddr) = v36.m128_i32[0];
                  v73 = v36;
                  if ( COERCE_FLOAT((unsigned int)(2 * v36.m128_i32[0]) >> 1) >= 0.0000099999997 )
                  {
                    LODWORD(retaddr) = v73.m128_i32[1];
                    if ( COERCE_FLOAT((unsigned int)(2 * v73.m128_i32[1]) >> 1) >= 0.0000099999997 )
                      v37 = v55.m128_f32[2] >= v20 ? v12 == 5 : v12 == 4;
                    else
                      v37 = v55.m128_f32[1] >= v21 ? v12 == 3 : v12 == 2;
                  }
                  else
                  {
                    v37 = v55.m128_f32[0] >= v22 ? v12 == 1 : v12 == 0;
                  }
                  if ( v37 )
                  {
                    if ( array.m_size == (array.m_capacityAndFlags & 0x3FFFFFFF) )
                      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, &array, 16);
                    v40 = array.m_size++;
                    `anonymous namespace::convertAabbFaceToSquare(&v72, v12, &array.m_data[v40]);
                  }
                }
                LODWORD(m_startEdgeIndex) = m_startEdgeIndex + 1;
                ++v26;
              }
              while ( (int)m_startEdgeIndex < m_data[v8].m_startEdgeIndex + m_data[v8].m_numEdges );
              p_m_size = v52;
            }
            squaresOut.m_capacityAndFlags = 0x80000000;
            squaresOut.m_data = 0i64;
            squaresOut.m_size = 0;
            `anonymous namespace::cutSquaresFromSquare(&squareOut, &array, &squaresOut);
            geometryOut = geometryOuta;
            `anonymous namespace::processCutSquares(&squaresOut, &aabb, v12, geometryOuta);
            squaresOut.m_size = 0;
            if ( squaresOut.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                squaresOut.m_data,
                16 * squaresOut.m_capacityAndFlags);
            squaresOut.m_data = 0i64;
            squaresOut.m_capacityAndFlags = 0x80000000;
            array.m_size = 0;
            if ( array.m_capacityAndFlags >= 0 )
              hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
                &hkContainerHeapAllocator::s_alloc,
                array.m_data,
                16 * array.m_capacityAndFlags);
            array.m_data = 0i64;
            buildSettings = v74;
            array.m_capacityAndFlags = 0x80000000;
          }
          p_m_size += 4;
          ++v12;
          v52 = p_m_size;
        }
        while ( v12 < 6 );
      }
      ++v8;
      v4 = v75 + 1;
      v37 = v51-- == 1;
      ++v75;
    }
    while ( !v37 );
  }
  if ( buildSettings->m_skipBoundingFaces )
  {
    v41.m_quad = (__m128)navVolume->m_aabb.m_min;
    v42 = 0;
    p_cutters = &cutters;
    v72.m_min = navVolume->m_aabb.m_max;
    v72.m_max = (hkVector4f)v41.m_quad;
    do
    {
      *(_QWORD *)&squareOut.minX = 0i64;
      *(_QWORD *)&squareOut.maxX = 0i64;
      `anonymous namespace::convertAabbFaceToSquare(&navVolume->m_aabb, v42, &squareOut);
      squaresOut.m_data = 0i64;
      squaresOut.m_size = 0;
      squaresOut.m_capacityAndFlags = 0x80000000;
      `anonymous namespace::cutSquaresFromSquare(&squareOut, p_cutters, &squaresOut);
      v44 = 1;
      if ( (v42 & 1) != 0 )
        v44 = -1;
      `anonymous namespace::processCutSquares(&squaresOut, &v72, v42 + v44, geometryOut);
      squaresOut.m_size = 0;
      if ( squaresOut.m_capacityAndFlags >= 0 )
        hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
          &hkContainerHeapAllocator::s_alloc,
          squaresOut.m_data,
          16 * squaresOut.m_capacityAndFlags);
      ++v42;
      ++p_cutters;
      squaresOut.m_data = 0i64;
      squaresOut.m_capacityAndFlags = 0x80000000;
    }
    while ( v42 < 6 );
  }
  if ( geometryOut )
    hkGeometryUtils::weldVertices(geometryOut, 0.001);
  v45 = 5;
  v46 = &v72.m_min.m_quad.m128_i32[3];
  do
  {
    v47 = *(v46 - 4);
    v46 -= 4;
    *(v46 - 1) = 0;
    if ( v47 >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        *(void **)(v46 - 3),
        16 * v47);
    --v45;
    *(_QWORD *)(v46 - 3) = 0i64;
    *v46 = 0x80000000;
  }
  while ( v45 >= 0 );
}

// File Line: 941
// RVA: 0xC4EF10
__int64 __fastcall realToOrderedUint_0(const float *in)
{
  return *(_DWORD *)in ^ ((*(int *)in >> 31) | 0x80000000);
}

// File Line: 947
// RVA: 0xC4DC10
void __fastcall hkaiNavVolumeDebugUtils::displayNavVolumeGeometry(
        hkaiNavVolumeDebugUtils::GeomteryDisplaySettings *settings,
        hkGeometry *surfaceGeometry)
{
  unsigned __int64 m_size; // r12
  float m_colorVariance; // xmm8_4
  unsigned int m_lineColor; // r15d
  __int64 v7; // r9
  int v8; // ebx
  int v9; // eax
  hkRadixSort::SortData32 *v10; // rax
  hkRadixSort::SortData32 *v11; // rdi
  int v12; // r13d
  signed int v13; // r11d
  unsigned __int64 v14; // r8
  __int64 v15; // r10
  hkGeometry::Triangle *m_data; // rdx
  hkVector4f *v17; // rcx
  hkVector4f v18; // xmm1
  __int64 m_b; // rax
  __m128 v20; // xmm3
  __m128 v21; // xmm0
  __int64 v22; // rdx
  __m128 v23; // xmm3
  __int64 v24; // rax
  unsigned int v25; // ecx
  int v26; // eax
  hkRadixSort::SortData32 *v27; // rcx
  int v28; // r14d
  __int64 v29; // r8
  signed int v30; // ebx
  __int64 v31; // r13
  signed int m_userData; // r14d
  unsigned int color; // r12d
  int v34; // xmm4_4
  int v35; // eax
  float v36; // xmm1_4
  int v37; // eax
  float v38; // xmm6_4
  float v39; // xmm5_4
  __int64 v40; // r9
  __int64 v41; // r8
  hkVector4f v42; // xmm1
  unsigned int m_color; // [rsp+30h] [rbp-B8h]
  signed int v44; // [rsp+34h] [rbp-B4h]
  hkRadixSort::SortData32 *v45; // [rsp+38h] [rbp-B0h]
  signed int v46; // [rsp+40h] [rbp-A8h]
  int v47; // [rsp+44h] [rbp-A4h]
  __m256i c; // [rsp+68h] [rbp-80h] BYREF
  hkVector4f end; // [rsp+88h] [rbp-60h] BYREF
  unsigned int v50; // [rsp+158h] [rbp+70h]
  __int64 vars0; // [rsp+160h] [rbp+78h]
  void *retaddr; // [rsp+168h] [rbp+80h] BYREF
  float v53; // [rsp+170h] [rbp+88h] BYREF
  hkGeometry *v54; // [rsp+178h] [rbp+90h]

  v54 = surfaceGeometry;
  m_size = surfaceGeometry->m_triangles.m_size;
  m_colorVariance = settings->m_colorVariance;
  m_lineColor = settings->m_lineColor;
  m_color = settings->m_color;
  v44 = settings->m_color;
  v46 = m_size;
  v7 = (unsigned int)((int)m_size / 2);
  v50 = v7;
  v8 = (v7 + 3) & 0xFFFFFFFC;
  v9 = v8;
  if ( v8 )
  {
    v10 = (hkRadixSort::SortData32 *)hkContainerDebugAllocator::s_alloc.vfptr->bufAlloc(
                                       &hkContainerDebugAllocator::s_alloc,
                                       &retaddr);
    v7 = v50;
    v11 = v10;
    v9 = 8 * v8 / 8;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = 0x80000000;
  if ( v9 )
    v12 = v9;
  v47 = v12;
  if ( settings->m_sortGeometry )
  {
    v13 = 0;
    v14 = m_size;
    if ( (int)m_size > 0 )
    {
      v15 = 0i64;
      v14 = ((m_size - 1) >> 1) + 1;
      do
      {
        m_data = surfaceGeometry->m_triangles.m_data;
        v17 = surfaceGeometry->m_vertices.m_data;
        v18.m_quad = (__m128)settings->m_displayOffset;
        m_b = m_data[v15].m_b;
        v15 += 2i64;
        v20 = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_add_ps(v17[m_b].m_quad, v18.m_quad), (__m128)xmmword_141A711D0),
                  _mm_mul_ps(_mm_add_ps(v17[m_data[v15 - 2].m_a].m_quad, v18.m_quad), (__m128)xmmword_141A711D0)),
                _mm_mul_ps(
                  _mm_add_ps(v17[*((int *)&m_data[v15 - 1] - 2)].m_quad, v18.m_quad),
                  (__m128)xmmword_141A711D0));
        v21 = _mm_add_ps(v17[m_data[v15 - 1].m_b].m_quad, v18.m_quad);
        v22 = v13 / 2;
        v11[v22].m_userData = v13;
        v13 += 2;
        v23 = _mm_mul_ps(_mm_add_ps(v20, _mm_mul_ps(v21, (__m128)xmmword_141A711D0)), settings->m_sortDirection.m_quad);
        v53 = (float)(_mm_shuffle_ps(v23, v23, 85).m128_f32[0] + _mm_shuffle_ps(v23, v23, 0).m128_f32[0])
            + _mm_shuffle_ps(v23, v23, 170).m128_f32[0];
        v11[v22].m_key = (LODWORD(v53) ^ ((SLODWORD(v53) >> 31) | 0x80000001)) >> 1;
        --v14;
      }
      while ( v14 );
    }
    v24 = (int)v7;
    v25 = v7;
    if ( (int)v7 < (__int64)v8 )
    {
      do
      {
        v11[v24].m_userData = v25;
        v11[v24++].m_key = 0x7FFFFFFF;
        ++v25;
      }
      while ( v24 < v8 );
    }
    v26 = v8;
    if ( v8 )
    {
      LODWORD(v53) = 8 * v8;
      v27 = (hkRadixSort::SortData32 *)((__int64 (__fastcall *)(hkContainerDebugAllocator::Allocator *, float *, unsigned __int64))hkContainerDebugAllocator::s_alloc.vfptr->bufAlloc)(
                                         &hkContainerDebugAllocator::s_alloc,
                                         &v53,
                                         v14);
      v26 = SLODWORD(v53) / 8;
    }
    else
    {
      v27 = 0i64;
    }
    v45 = v27;
    v28 = 0x80000000;
    if ( v26 )
      v28 = v26;
    hkRadixSort::sort32(v11, v8, v27);
    if ( v28 >= 0 )
      hkContainerDebugAllocator::s_alloc.vfptr->bufFree(&hkContainerDebugAllocator::s_alloc, v45, 8 * v28);
  }
  v29 = (int)v50;
  v30 = 0;
  if ( (int)m_size > 0 )
  {
    v31 = vars0;
    do
    {
      if ( settings->m_sortGeometry )
        m_userData = v11[v29 - 1 + v30 / -2].m_userData;
      else
        m_userData = v30;
      if ( m_colorVariance == 0.0 )
      {
        color = m_color;
      }
      else
      {
        v53 = 0.0;
        v34 = LODWORD(m_colorVariance) ^ _xmm[0];
        v35 = 1664525 * v44 + 1013904223;
        v36 = (float)v35;
        v37 = 1664525 * v35 + 1013904223;
        v44 = 1664525 * v37 + 1013904223;
        *(float *)&vars0 = (float)((float)((float)(v36 * 2.3283064e-10) * (float)(m_colorVariance - *(float *)&v34))
                                 + *(float *)&v34)
                         + (float)((float)BYTE2(m_color) * 0.0039215689);
        v38 = fminf(fmaxf(*(float *)&vars0, 0.0), 1.0);
        *(float *)&vars0 = (float)((float)((float)((float)v37 * 2.3283064e-10)
                                         * (float)(m_colorVariance - *(float *)&v34))
                                 + *(float *)&v34)
                         + (float)((float)BYTE1(m_color) * 0.0039215689);
        v39 = fminf(fmaxf(*(float *)&vars0, 0.0), 1.0);
        *(float *)&vars0 = (float)((float)((float)((float)v44 * 2.3283064e-10)
                                         * (float)(m_colorVariance - *(float *)&v34))
                                 + *(float *)&v34)
                         + (float)((float)(unsigned __int8)m_color * 0.0039215689);
        color = hkColor::rgbFromFloats(v38, v39, fminf(fmaxf(*(float *)&vars0, 0.0), 1.0), 1.0);
      }
      v40 = *(_QWORD *)(v31 + 32);
      v41 = *(_QWORD *)(v31 + 16);
      v42.m_quad = (__m128)settings->m_displayOffset;
      *(__m128 *)c.m256i_i8 = _mm_add_ps(*(__m128 *)(v41 + 16i64 * *(int *)(v40 + 16i64 * m_userData)), v42.m_quad);
      *(__m128 *)&c.m256i_u64[2] = _mm_add_ps(
                                     *(__m128 *)(v41 + 16i64 * *(int *)(v40 + 16i64 * m_userData + 4)),
                                     v42.m_quad);
      *(__m128 *)&c.m256i_u64[1] = _mm_add_ps(
                                     *(__m128 *)(v41 + 16i64 * *(int *)(v40 + 16i64 * m_userData + 8)),
                                     v42.m_quad);
      end.m_quad = _mm_add_ps(*(__m128 *)(v41 + 16i64 * *(int *)(v40 + 16i64 * m_userData + 20)), v42.m_quad);
      hkDebugDisplay::displayLitTriangle(
        hkSingleton<hkDebugDisplay>::s_instance,
        (hkVector4f *)&c,
        (hkVector4f *)&c.m256i_u64[2],
        (hkVector4f *)&c.m256i_u64[1],
        color);
      hkDebugDisplay::displayLitTriangle(
        hkSingleton<hkDebugDisplay>::s_instance,
        (hkVector4f *)&c.m256i_u64[1],
        &end,
        (hkVector4f *)&c,
        color);
      if ( settings->m_drawLines )
      {
        hkDebugDisplay::displayLine(
          hkSingleton<hkDebugDisplay>::s_instance,
          (hkVector4f *)&c,
          (hkVector4f *)&c.m256i_u64[2],
          m_lineColor,
          0,
          (int)hkDebugDisplayProcess::m_tag);
        hkDebugDisplay::displayLine(
          hkSingleton<hkDebugDisplay>::s_instance,
          (hkVector4f *)&c.m256i_u64[2],
          (hkVector4f *)&c.m256i_u64[1],
          m_lineColor,
          0,
          (int)hkDebugDisplayProcess::m_tag);
        hkDebugDisplay::displayLine(
          hkSingleton<hkDebugDisplay>::s_instance,
          (hkVector4f *)&c.m256i_u64[1],
          &end,
          m_lineColor,
          0,
          (int)hkDebugDisplayProcess::m_tag);
        hkDebugDisplay::displayLine(
          hkSingleton<hkDebugDisplay>::s_instance,
          &end,
          (hkVector4f *)&c,
          m_lineColor,
          0,
          (int)hkDebugDisplayProcess::m_tag);
      }
      v29 = (int)v50;
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
void __fastcall hkaiNavVolumeDebugUtils::displayNavVolumeGeometry(
        hkaiNavVolumeDebugUtils::GeomteryBuildSettings *buildSettings,
        hkaiNavVolumeDebugUtils::GeomteryDisplaySettings *displaySettings,
        hkaiNavVolume *navVolume)
{
  hkGeometry geometryOut; // [rsp+20h] [rbp-38h] BYREF

  *(_DWORD *)&geometryOut.m_memSizeAndFlags = 0x1FFFF;
  geometryOut.vfptr = (hkBaseObjectVtbl *)&hkGeometry::`vftable;
  geometryOut.m_vertices.m_data = 0i64;
  geometryOut.m_vertices.m_size = 0;
  geometryOut.m_vertices.m_capacityAndFlags = 0x80000000;
  geometryOut.m_triangles.m_data = 0i64;
  geometryOut.m_triangles.m_size = 0;
  geometryOut.m_triangles.m_capacityAndFlags = 0x80000000;
  hkaiNavVolumeDebugUtils::buildNavVolumeGeometry(buildSettings, navVolume, &geometryOut);
  hkaiNavVolumeDebugUtils::displayNavVolumeGeometry(displaySettings, &geometryOut);
  geometryOut.m_triangles.m_size = 0;
  if ( geometryOut.m_triangles.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      geometryOut.m_triangles.m_data,
      16 * geometryOut.m_triangles.m_capacityAndFlags);
  geometryOut.m_triangles.m_data = 0i64;
  geometryOut.m_triangles.m_capacityAndFlags = 0x80000000;
  geometryOut.m_vertices.m_size = 0;
  if ( geometryOut.m_vertices.m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      geometryOut.m_vertices.m_data,
      16 * geometryOut.m_vertices.m_capacityAndFlags);
}

// File Line: 1053
// RVA: 0xC4D1E0
bool __fastcall hkaiNavVolumeDebugUtils::SetFilter::shouldIncludeCell(
        hkaiNavVolumeDebugUtils::SetFilter *this,
        hkaiNavVolume *volume,
        int cellIndex)
{
  int v3; // r9d
  int *m_data; // r10
  int v5; // eax
  int v6; // edx

  v3 = this->m_allowedCells.m_elem.m_size - 1;
  if ( v3 <= 0 )
    return this->m_allowedCells.m_elem.m_size <= this->m_allowedCells.m_elem.m_size - 1
        || this->m_allowedCells.m_elem.m_size == this->m_allowedCells.m_elem.m_size - 1;
  m_data = this->m_allowedCells.m_elem.m_data;
  v5 = v3 & (-1640531535 * cellIndex);
  v6 = m_data[v5];
  if ( v6 == -1 )
    return this->m_allowedCells.m_elem.m_size <= this->m_allowedCells.m_elem.m_size - 1
        || this->m_allowedCells.m_elem.m_size == this->m_allowedCells.m_elem.m_size - 1;
  while ( v6 != cellIndex )
  {
    v5 = v3 & (v5 + 1);
    v6 = m_data[v5];
    if ( v6 == -1 )
      return this->m_allowedCells.m_elem.m_size <= this->m_allowedCells.m_elem.m_size - 1
          || this->m_allowedCells.m_elem.m_size == this->m_allowedCells.m_elem.m_size - 1;
  }
  return v5 <= v3;
}

// File Line: 1058
// RVA: 0xC4D240
bool __fastcall hkaiNavVolumeDebugUtils::MaterialFilter::shouldIncludeCell(
        hkaiNavVolumeDebugUtils::MaterialFilter *this,
        hkaiNavVolume *volume,
        int cellIndex)
{
  return this->m_cellData == volume->m_cells.m_data[cellIndex].m_data;
}

