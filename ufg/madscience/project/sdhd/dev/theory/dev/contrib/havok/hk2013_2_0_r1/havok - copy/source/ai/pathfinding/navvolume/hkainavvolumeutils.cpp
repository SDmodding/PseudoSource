// File Line: 29
// RVA: 0x12FB4F0
void __fastcall hkaiNavVolumeUtils::calcRandomPointInCell(
        hkaiNavVolumeInstance *vol,
        int cellIndex,
        hkPseudoRandomGenerator *rand,
        hkVector4f *pointOut)
{
  hkaiNavVolume *m_pntr; // rax
  __m128i v5; // xmm2
  __m128i v6; // xmm0
  __m128 v7; // xmm3
  __m128i v8; // xmm0
  __m128 v9; // xmm2
  __m128 v10; // xmm0
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // [rsp+0h] [rbp-18h]

  m_pntr = vol->m_originalVolume.m_pntr;
  v5 = _mm_loadu_si128((const __m128i *)&vol->m_originalCells[cellIndex]);
  v6 = _mm_unpacklo_epi16(v5, (__m128i)0i64);
  v7 = _mm_add_ps(
         _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v6, 0x10u)), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
         _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v6, 0x10u), 0x10u)));
  v8 = _mm_unpackhi_epi16(v5, (__m128i)0i64);
  v9 = _mm_add_ps(
         _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v8, 0x10u)), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
         _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v8, 0x10u), 0x10u)));
  v10 = _mm_add_ps(m_pntr->m_quantizationOffset.m_quad, vol->m_translation.m_quad);
  v11 = _mm_add_ps(_mm_mul_ps(m_pntr->m_quantizationScale.m_quad, v9), v10);
  v12 = _mm_add_ps(_mm_mul_ps(m_pntr->m_quantizationScale.m_quad, v7), v10);
  LODWORD(m_pntr) = 1664525 * rand->m_current + 1013904223;
  v10.m128_f32[0] = (float)(int)m_pntr;
  LODWORD(m_pntr) = 1664525 * (_DWORD)m_pntr + 1013904223;
  v13.m128_f32[0] = v10.m128_f32[0] * 2.3283064e-10;
  v10.m128_f32[0] = (float)(int)m_pntr;
  LODWORD(m_pntr) = 1664525 * (_DWORD)m_pntr + 1013904223;
  v13.m128_f32[1] = v10.m128_f32[0] * 2.3283064e-10;
  v10.m128_f32[0] = (float)(int)m_pntr;
  LODWORD(m_pntr) = 1664525 * (_DWORD)m_pntr + 1013904223;
  rand->m_current = (unsigned int)m_pntr;
  v13.m128_f32[2] = v10.m128_f32[0] * 2.3283064e-10;
  v13.m128_f32[3] = (float)(int)m_pntr * 2.3283064e-10;
  pointOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v11, v12), v13), v12);
}

// File Line: 38
// RVA: 0x12FB620
void __fastcall hkaiNavVolumeUtils::getClosestPointOnCell(
        hkaiNavVolume *vol,
        hkVector4f *position,
        int cellIndex,
        hkVector4f *closestPointOut)
{
  __m128i v4; // xmm2
  __m128i v5; // xmm0
  __m128 v6; // xmm3
  __m128i v7; // xmm0
  __m128 v8; // xmm5
  __m128 m_quad; // xmm2
  __m128 v10; // xmm4
  __m128 v11; // xmm1

  v4 = _mm_loadu_si128((const __m128i *)&vol->m_cells.m_data[cellIndex]);
  v5 = _mm_unpacklo_epi16(v4, (__m128i)0i64);
  v6 = _mm_add_ps(
         _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v5, 0x10u)), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
         _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v5, 0x10u), 0x10u)));
  v7 = _mm_unpackhi_epi16(v4, (__m128i)0i64);
  v8 = _mm_add_ps(_mm_mul_ps(vol->m_quantizationScale.m_quad, v6), vol->m_quantizationOffset.m_quad);
  m_quad = position->m_quad;
  v10 = _mm_add_ps(
          _mm_mul_ps(
            vol->m_quantizationScale.m_quad,
            _mm_add_ps(
              _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v7, 0x10u)), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v7, 0x10u), 0x10u)))),
          vol->m_quantizationOffset.m_quad);
  if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmple_ps(v8, position->m_quad), _mm_cmple_ps(position->m_quad, v10))) & 7) == 7 )
  {
    *closestPointOut = (hkVector4f)m_quad;
  }
  else
  {
    v11 = _mm_min_ps(_mm_max_ps(position->m_quad, v8), v10);
    closestPointOut->m_quad = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, _mm_shuffle_ps(m_quad, m_quad, 255)), 196);
  }
}

// File Line: 55
// RVA: 0x12FB790
hkSimdFloat32 *__fastcall hkaiNavVolumeUtils::calcCellVolume(
        hkSimdFloat32 *result,
        hkaiNavVolumeInstance *vol,
        int cellIndex)
{
  hkaiNavVolumeUtils::calcCellVolume(result, vol->m_originalVolume.m_pntr, cellIndex);
  return result;
}

// File Line: 60
// RVA: 0x12FB6E0
hkSimdFloat32 *__fastcall hkaiNavVolumeUtils::calcCellVolume(hkSimdFloat32 *result, hkaiNavVolume *vol, int cellIndex)
{
  hkSimdFloat32 *v3; // rax
  __m128i v4; // xmm2
  __m128i v5; // xmm0
  __m128 v6; // xmm4
  __m128i v7; // xmm0
  __m128 v8; // xmm3

  v3 = result;
  v4 = _mm_loadu_si128((const __m128i *)&vol->m_cells.m_data[cellIndex]);
  v5 = _mm_unpacklo_epi16(v4, (__m128i)0i64);
  v6 = _mm_add_ps(
         _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v5, 0x10u)), (__m128)`hkIntVector::convertU32ToF32::`2::two16),
         _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v5, 0x10u), 0x10u)));
  v7 = _mm_unpackhi_epi16(v4, (__m128i)0i64);
  v8 = _mm_sub_ps(
         _mm_add_ps(
           _mm_mul_ps(
             vol->m_quantizationScale.m_quad,
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srli_epi32(v7, 0x10u)),
                 (__m128)`hkIntVector::convertU32ToF32::`2::two16),
               _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v7, 0x10u), 0x10u)))),
           vol->m_quantizationOffset.m_quad),
         _mm_add_ps(_mm_mul_ps(vol->m_quantizationScale.m_quad, v6), vol->m_quantizationOffset.m_quad));
  result->m_real = _mm_mul_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                     _mm_shuffle_ps(v8, v8, 170));
  return v3;
}

// File Line: 68
// RVA: 0x12FB7C0
void __fastcall hkaiNavVolumeUtils::removeCells(
        hkaiNavVolume *volume,
        hkArray<int,hkContainerTempAllocator> *cellsToRemove)
{
  __int64 m_size; // rdi
  int v5; // r10d
  __int64 v6; // r9
  __int64 v7; // rdx
  int v8; // ebx
  __int64 v9; // r8
  int v10; // r12d
  __int64 v11; // r15
  __int64 v12; // rdi
  hkaiNavVolume::Cell *m_data; // rcx
  __int16 v14; // si
  char *v15; // rcx
  __int64 v16; // rdx
  unsigned __int64 v17; // rax
  __int64 v18; // r14
  __int64 v19; // rdi
  hkaiNavVolume::Edge v20; // rbx
  int v21; // ebx
  char *v22; // rdx
  signed int v23; // r10d
  __int64 v24; // r9
  __int64 v25; // rcx
  int v26; // esi
  int v27; // eax
  int v28; // eax
  int v29; // r9d
  hkaiNavVolume::Cell *v30; // rcx
  int *v31; // rdx
  __int64 v32; // r8
  int v33; // eax
  char *v34; // r9
  __int64 v35; // rdx
  __int64 v36; // rcx
  hkaiNavVolume::Edge *v37; // rax
  _QWORD *v38; // r9
  hkaiNavVolume::Edge *v39; // r10
  __int64 i; // rcx
  hkaiNavVolume::Edge v41; // rax
  _QWORD *v42; // [rsp+30h] [rbp-79h] BYREF
  unsigned int v43; // [rsp+38h] [rbp-71h]
  int v44; // [rsp+3Ch] [rbp-6Dh]
  char *array; // [rsp+40h] [rbp-69h] BYREF
  int v46; // [rsp+48h] [rbp-61h]
  int v47; // [rsp+4Ch] [rbp-5Dh]
  _DWORD *v48; // [rsp+50h] [rbp-59h] BYREF
  int v49; // [rsp+58h] [rbp-51h]
  int v50; // [rsp+5Ch] [rbp-4Dh]
  const void *v51; // [rsp+60h] [rbp-49h] BYREF
  int v52; // [rsp+68h] [rbp-41h]
  int v53; // [rsp+6Ch] [rbp-3Dh]
  int v54; // [rsp+70h] [rbp-39h]
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > v55; // [rsp+78h] [rbp-31h] BYREF
  __int64 v56; // [rsp+90h] [rbp-19h]
  __int64 v57; // [rsp+98h] [rbp-11h]
  unsigned __int64 v58; // [rsp+A0h] [rbp-9h]
  hkResult result; // [rsp+110h] [rbp+67h] BYREF
  int v60; // [rsp+118h] [rbp+6Fh]
  int v61; // [rsp+120h] [rbp+77h]
  int v62; // [rsp+128h] [rbp+7Fh]

  m_size = volume->m_cells.m_size;
  v55.m_storage.m_words.m_data = 0i64;
  v55.m_storage.m_words.m_size = 0;
  v55.m_storage.m_words.m_capacityAndFlags = 0x80000000;
  v55.m_storage.m_numBits = 0;
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(&v55, 0, m_size, 0);
  v5 = 0;
  if ( cellsToRemove->m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      ++v5;
      v7 = cellsToRemove->m_data[v6++];
      v55.m_storage.m_words.m_data[v7 >> 5] |= 1 << (v7 & 0x1F);
    }
    while ( v5 < cellsToRemove->m_size );
  }
  v8 = 0;
  array = 0i64;
  v47 = 0x80000000;
  v46 = 0;
  if ( (int)m_size > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&array, m_size, 24);
    v8 = v46;
  }
  v42 = 0i64;
  v9 = 0i64;
  v43 = 0;
  v44 = 0x80000000;
  if ( (int)m_size > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v42, m_size, 8);
    v8 = v46;
    v9 = v43;
  }
  v51 = 0i64;
  v52 = 0;
  v53 = 0x80000000;
  if ( (int)m_size > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &v51, m_size, 4);
    v8 = v46;
    v9 = v43;
  }
  v48 = 0i64;
  v49 = 0;
  v50 = 0x80000000;
  if ( (int)m_size > 0 )
  {
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&v48, m_size, 4);
    v8 = v46;
    v9 = v43;
  }
  v49 = m_size;
  v10 = 0;
  v11 = 0i64;
  v57 = m_size;
  if ( (int)m_size > 0 )
  {
    v12 = 0i64;
    v56 = 0i64;
    do
    {
      if ( ((v55.m_storage.m_words.m_data[(__int64)v10 >> 5] >> (v10 & 0x1F)) & 1) == 0 )
      {
        m_data = volume->m_cells.m_data;
        v14 = 0;
        v62 = v9;
        v15 = (char *)m_data + v12;
        v16 = *((int *)v15 + 4);
        result.m_enum = *(_DWORD *)v15;
        LODWORD(v58) = result;
        HIDWORD(v58) = *((_DWORD *)v15 + 1);
        v60 = *((_DWORD *)v15 + 2);
        v61 = *((_DWORD *)v15 + 3);
        v54 = *((_DWORD *)v15 + 5);
        v17 = v58;
        HIWORD(v58) = 0;
        v17 >>= 48;
        v18 = (__int16)v17;
        if ( (__int16)v17 > 0 )
        {
          v19 = v16;
          do
          {
            v20 = volume->m_edges.m_data[v19];
            if ( ((v55.m_storage.m_words.m_data[(__int64)(int)v20.m_oppositeCell >> 5] >> (v20.m_oppositeCell & 0x1F)) & 1) == 0 )
            {
              if ( (_DWORD)v9 == (v44 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v42, 8);
                LODWORD(v9) = v43;
              }
              v42[(int)v9] = v20;
              LODWORD(v9) = v43 + 1;
              ++v14;
              ++v43;
            }
            ++v19;
            --v18;
          }
          while ( v18 );
          v8 = v46;
          v12 = v56;
          HIWORD(v58) = v14;
        }
        v48[v11] = v8;
        v21 = v46;
        if ( v46 == (v47 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&array, 24);
          v21 = v46;
        }
        v22 = &array[24 * v21];
        if ( v22 )
        {
          *(hkResult *)v22 = result;
          *((_DWORD *)v22 + 1) = HIDWORD(v58);
          *((_DWORD *)v22 + 2) = v60;
          *((_DWORD *)v22 + 3) = v61;
          *((_DWORD *)v22 + 4) = v62;
          *((_DWORD *)v22 + 5) = v54;
          v21 = v46;
        }
        v9 = v43;
        v8 = v21 + 1;
        v46 = v8;
      }
      v12 += 24i64;
      ++v11;
      ++v10;
      v56 = v12;
    }
    while ( v11 < v57 );
  }
  v23 = 0;
  if ( (int)v9 > 0 )
  {
    v24 = 0i64;
    do
    {
      ++v23;
      v25 = SHIDWORD(v42[v24++]);
      HIDWORD(v42[v24 - 1]) = v48[v25];
      v9 = v43;
    }
    while ( v23 < (int)v43 );
    v8 = v46;
  }
  v26 = v8;
  if ( v8 > volume->m_cells.m_size )
    v26 = volume->m_cells.m_size;
  v27 = volume->m_cells.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v27 < v8 )
  {
    v28 = 2 * v27;
    v29 = v8;
    if ( v8 < v28 )
      v29 = v28;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, (const void **)&volume->m_cells.m_data, v29, 24);
    v9 = v43;
  }
  v30 = volume->m_cells.m_data;
  if ( v26 > 0 )
  {
    v31 = (int *)array;
    v32 = v26;
    do
    {
      v33 = *v31;
      ++v30;
      v31 += 6;
      *(_DWORD *)v30[-1].m_min = v33;
      *(_DWORD *)&v30[-1].m_min[2] = *(v31 - 5);
      *(_DWORD *)v30[-1].m_max = *(v31 - 4);
      *(_DWORD *)&v30[-1].m_max[2] = *(v31 - 3);
      v30[-1].m_startEdgeIndex = *(v31 - 2);
      v30[-1].m_data = *(v31 - 1);
      --v32;
    }
    while ( v32 );
    v9 = v43;
  }
  v34 = &array[24 * v26];
  v35 = (__int64)&volume->m_cells.m_data[v26];
  v36 = v8 - v26;
  if ( v8 - v26 > 0 )
  {
    v34 -= v35;
    do
    {
      if ( v35 )
      {
        *(_DWORD *)v35 = *(_DWORD *)&v34[v35];
        *(_DWORD *)(v35 + 4) = *(_DWORD *)&v34[v35 + 4];
        *(_DWORD *)(v35 + 8) = *(_DWORD *)&v34[v35 + 8];
        *(_DWORD *)(v35 + 12) = *(_DWORD *)&v34[v35 + 12];
        *(_DWORD *)(v35 + 16) = *(_DWORD *)&v34[v35 + 16];
        *(_DWORD *)(v35 + 20) = *(_DWORD *)&v34[v35 + 20];
      }
      v35 += 24i64;
      --v36;
    }
    while ( v36 );
    v9 = v43;
  }
  volume->m_cells.m_size = v8;
  if ( (volume->m_edges.m_capacityAndFlags & 0x3FFFFFFF) < (int)v9 )
  {
    if ( volume->m_edges.m_capacityAndFlags >= 0 )
    {
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkaiNavVolume::Edge *, _QWORD, char *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        volume->m_edges.m_data,
        (unsigned int)(8 * volume->m_edges.m_capacityAndFlags),
        v34);
      v9 = v43;
    }
    result.m_enum = 8 * v9;
    v37 = (hkaiNavVolume::Edge *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64, char *))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                                   &hkContainerHeapAllocator::s_alloc,
                                   &result,
                                   v9,
                                   v34);
    LODWORD(v9) = v43;
    volume->m_edges.m_data = v37;
    volume->m_edges.m_capacityAndFlags = result.m_enum / 8;
  }
  v38 = v42;
  v39 = volume->m_edges.m_data;
  volume->m_edges.m_size = v9;
  for ( i = 0i64; i < (int)v9; v39[i - 1] = v41 )
    v41 = (hkaiNavVolume::Edge)v38[i++];
  v49 = 0;
  if ( v50 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _DWORD *, _QWORD, _QWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v48,
      (unsigned int)(4 * v50),
      v38);
  v48 = 0i64;
  v50 = 0x80000000;
  v52 = 0;
  if ( v53 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, const void *, _QWORD, _QWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v51,
      (unsigned int)(4 * v53),
      v38);
  v51 = 0i64;
  v53 = 0x80000000;
  v43 = 0;
  if ( v44 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, _QWORD *, _QWORD, _QWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v42,
      (unsigned int)(8 * v44),
      v38);
  v42 = 0i64;
  v44 = 0x80000000;
  v46 = 0;
  if ( v47 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, char *, _QWORD, _QWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      24 * (v47 & 0x3FFFFFFFu),
      v38);
  array = 0i64;
  v47 = 0x80000000;
  v55.m_storage.m_words.m_size = 0;
  if ( v55.m_storage.m_words.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned int *, _QWORD, _QWORD *))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v55.m_storage.m_words.m_data,
      (unsigned int)(4 * v55.m_storage.m_words.m_capacityAndFlags),
      v38);
}

// File Line: 156
// RVA: 0x12FBDF0
__int64 __fastcall hkaiNavVolumeUtils::computeRegions(hkaiNavVolume *volume, hkArrayBase<int> *regionsOut)
{
  int numRegionsOut; // [rsp+50h] [rbp+18h] BYREF
  hkResult result; // [rsp+58h] [rbp+20h] BYREF

  numRegionsOut = -1;
  hkaiComputeRegionUtils::computeRegions<hkaiNavVolume,float>(&result, volume, 0, regionsOut, &numRegionsOut, 0i64);
  return (unsigned int)numRegionsOut;
}

// File Line: 196
// RVA: 0x12FBEB0
void __fastcall hkaiNavVolumeUtils::validate(hkaiNavVolumeInstance *instance)
{
  hkaiNavVolumeUtils::validate(instance->m_originalVolume.m_pntr);
}

// File Line: 201
// RVA: 0x12FBEA0
// attributes: thunk
void __fastcall hkaiNavVolumeUtils::validate(hkaiNavVolume *vol)
{
  hkaiNavVolume::checkDeterminism(vol);
}

// File Line: 234
// RVA: 0x12FBE40
hkaiAabbTreeNavVolumeMediator *__fastcall hkaiNavVolumeUtils::setupMediator(hkaiNavVolume *vol)
{
  _QWORD **Value; // rax
  hkaiAabbTreeNavVolumeMediator *v3; // rax
  hkaiAabbTreeNavVolumeMediator *v4; // rax
  hkaiAabbTreeNavVolumeMediator *v5; // rbx

  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiAabbTreeNavVolumeMediator *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(
                                          Value[11],
                                          32i64);
  if ( v3 )
  {
    hkaiAabbTreeNavVolumeMediator::hkaiAabbTreeNavVolumeMediator(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  hkaiAabbTreeNavVolumeMediator::build(v5, vol);
  return v5;
}

