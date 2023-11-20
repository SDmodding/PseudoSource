// File Line: 29
// RVA: 0x12FB4F0
void __fastcall hkaiNavVolumeUtils::calcRandomPointInCell(hkaiNavVolumeInstance *vol, int cellIndex, hkPseudoRandomGenerator *rand, hkVector4f *pointOut)
{
  __m128i v4; // xmm4
  hkaiNavVolume *v5; // rax
  __m128i v6; // xmm2
  __m128 v7; // xmm3
  __m128i v8; // xmm0
  __m128 v9; // xmm2
  __m128 v10; // xmm0
  __m128 v11; // xmm5
  __m128 v12; // xmm4
  __m128 v13; // ST00_16

  v4 = _mm_loadu_si128((const __m128i *)&vol->m_originalCells[cellIndex]);
  v5 = vol->m_originalVolume.m_pntr;
  v6 = _mm_unpacklo_epi16(v4, (__m128i)0i64);
  v7 = _mm_add_ps(
         _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v6, 0x10u)), (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
         _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v6, 0x10u), 0x10u)));
  v8 = _mm_unpackhi_epi16(v4, (__m128i)0i64);
  v9 = _mm_add_ps(
         _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v8, 0x10u)), (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
         _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v8, 0x10u), 0x10u)));
  v10 = _mm_add_ps(v5->m_quantizationOffset.m_quad, vol->m_translation.m_quad);
  v11 = _mm_add_ps(_mm_mul_ps(v5->m_quantizationScale.m_quad, v9), v10);
  v12 = _mm_add_ps(_mm_mul_ps(v5->m_quantizationScale.m_quad, v7), v10);
  LODWORD(v5) = 1664525 * rand->m_current + 1013904223;
  v10.m128_f32[0] = (float)(signed int)v5;
  LODWORD(v5) = 1664525 * (_DWORD)v5 + 1013904223;
  v13.m128_f32[0] = v10.m128_f32[0] * 2.3283064e-10;
  v10.m128_f32[0] = (float)(signed int)v5;
  LODWORD(v5) = 1664525 * (_DWORD)v5 + 1013904223;
  v13.m128_f32[1] = v10.m128_f32[0] * 2.3283064e-10;
  v10.m128_f32[0] = (float)(signed int)v5;
  LODWORD(v5) = 1664525 * (_DWORD)v5 + 1013904223;
  rand->m_current = (unsigned int)v5;
  v13.m128_f32[2] = v10.m128_f32[0] * 2.3283064e-10;
  v13.m128_f32[3] = (float)(signed int)v5 * 2.3283064e-10;
  pointOut->m_quad = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(v11, v12), v13), v12);
}

// File Line: 38
// RVA: 0x12FB620
void __fastcall hkaiNavVolumeUtils::getClosestPointOnCell(hkaiNavVolume *vol, hkVector4f *position, int cellIndex, hkVector4f *closestPointOut)
{
  __m128i v4; // xmm4
  __m128i v5; // xmm2
  __m128i v6; // xmm4
  __m128i v7; // xmm2
  __m128 v8; // xmm5
  __m128 v9; // xmm2
  __m128 v10; // xmm4
  __m128 v11; // xmm1

  v4 = _mm_loadu_si128((const __m128i *)&vol->m_cells.m_data[cellIndex]);
  v5 = v4;
  v6 = _mm_unpackhi_epi16(v4, (__m128i)0i64);
  v7 = _mm_unpacklo_epi16(v5, (__m128i)0i64);
  v8 = _mm_add_ps(
         _mm_mul_ps(
           vol->m_quantizationScale.m_quad,
           _mm_add_ps(
             _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v7, 0x10u)), (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
             _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v7, 0x10u), 0x10u)))),
         vol->m_quantizationOffset.m_quad);
  v9 = position->m_quad;
  v10 = _mm_add_ps(
          _mm_mul_ps(
            vol->m_quantizationScale.m_quad,
            _mm_add_ps(
              _mm_mul_ps(_mm_cvtepi32_ps(_mm_srli_epi32(v6, 0x10u)), (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
              _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v6, 0x10u), 0x10u)))),
          vol->m_quantizationOffset.m_quad);
  if ( (_mm_movemask_ps(_mm_and_ps(_mm_cmpleps(v8, position->m_quad), _mm_cmpleps(position->m_quad, v10))) & 7) == 7 )
  {
    *closestPointOut = (hkVector4f)v9;
  }
  else
  {
    v11 = _mm_min_ps(_mm_max_ps(position->m_quad, v8), v10);
    closestPointOut->m_quad = _mm_shuffle_ps(v11, _mm_unpackhi_ps(v11, _mm_shuffle_ps(v9, v9, 255)), 196);
  }
}

// File Line: 55
// RVA: 0x12FB790
hkSimdFloat32 *__fastcall hkaiNavVolumeUtils::calcCellVolume(hkSimdFloat32 *result, hkaiNavVolumeInstance *vol, int cellIndex)
{
  hkSimdFloat32 *v3; // rbx

  v3 = result;
  hkaiNavVolumeUtils::calcCellVolume(result, vol->m_originalVolume.m_pntr, cellIndex);
  return v3;
}

// File Line: 60
// RVA: 0x12FB6E0
hkSimdFloat32 *__fastcall hkaiNavVolumeUtils::calcCellVolume(hkSimdFloat32 *result, hkaiNavVolume *vol, int cellIndex)
{
  __m128i v3; // xmm3
  hkSimdFloat32 *v4; // rax
  __m128i v5; // xmm2
  __m128i v6; // xmm3
  __m128i v7; // xmm2
  __m128 v8; // xmm3

  v3 = _mm_loadu_si128((const __m128i *)&vol->m_cells.m_data[cellIndex]);
  v4 = result;
  v5 = v3;
  v6 = _mm_unpackhi_epi16(v3, (__m128i)0i64);
  v7 = _mm_unpacklo_epi16(v5, (__m128i)0i64);
  v8 = _mm_sub_ps(
         _mm_add_ps(
           _mm_mul_ps(
             vol->m_quantizationScale.m_quad,
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srli_epi32(v6, 0x10u)),
                 (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
               _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v6, 0x10u), 0x10u)))),
           vol->m_quantizationOffset.m_quad),
         _mm_add_ps(
           _mm_mul_ps(
             vol->m_quantizationScale.m_quad,
             _mm_add_ps(
               _mm_mul_ps(
                 _mm_cvtepi32_ps(_mm_srli_epi32(v7, 0x10u)),
                 (__m128)`hkIntVector::convertU32ToF32'::`2'::two16),
               _mm_cvtepi32_ps(_mm_srli_epi32(_mm_slli_epi32(v7, 0x10u), 0x10u)))),
           vol->m_quantizationOffset.m_quad));
  result->m_real = _mm_mul_ps(
                     _mm_mul_ps(_mm_shuffle_ps(v8, v8, 85), _mm_shuffle_ps(v8, v8, 0)),
                     _mm_shuffle_ps(v8, v8, 170));
  return v4;
}

// File Line: 68
// RVA: 0x12FB7C0
void __fastcall hkaiNavVolumeUtils::removeCells(hkaiNavVolume *volume, hkArray<int,hkContainerTempAllocator> *cellsToRemove)
{
  __int64 v2; // rdi
  hkaiNavVolume *v3; // r13
  hkArray<int,hkContainerTempAllocator> *v4; // rbx
  int v5; // er10
  __int64 v6; // r9
  __int64 v7; // rcx
  int v8; // ebx
  int v9; // er9
  __int64 v10; // r8
  int v11; // er9
  int v12; // er9
  int v13; // er9
  int v14; // er12
  __int64 v15; // r15
  __int64 v16; // rdi
  hkaiNavVolume::Cell *v17; // rcx
  __int16 v18; // si
  __int64 v19; // rcx
  signed __int64 v20; // rdx
  __int16 v21; // ah^5
  __int64 v22; // r14
  signed __int64 v23; // rdi
  hkaiNavVolume::Edge v24; // rbx
  __int64 v25; // rcx
  int v26; // ebx
  __int64 v27; // rdx
  signed int v28; // er10
  __int64 v29; // r9
  __int64 v30; // rcx
  int v31; // esi
  int v32; // eax
  int v33; // eax
  int v34; // er9
  hkaiNavVolume::Cell *v35; // rcx
  int *v36; // rdx
  __int64 v37; // r8
  int v38; // eax
  signed __int64 v39; // r9
  signed __int64 v40; // rdx
  __int64 v41; // rcx
  __int64 v42; // rax
  __int64 v43; // r9
  hkaiNavVolume::Edge *v44; // r10
  signed __int64 v45; // rcx
  hkaiNavVolume::Edge v46; // rax
  __int64 v47; // [rsp+30h] [rbp-79h]
  unsigned int v48; // [rsp+38h] [rbp-71h]
  int v49; // [rsp+3Ch] [rbp-6Dh]
  int *array; // [rsp+40h] [rbp-69h]
  int v51; // [rsp+48h] [rbp-61h]
  int v52; // [rsp+4Ch] [rbp-5Dh]
  __int64 v53; // [rsp+50h] [rbp-59h]
  int v54; // [rsp+58h] [rbp-51h]
  int v55; // [rsp+5Ch] [rbp-4Dh]
  __int64 v56; // [rsp+60h] [rbp-49h]
  int v57; // [rsp+68h] [rbp-41h]
  int v58; // [rsp+6Ch] [rbp-3Dh]
  int v59; // [rsp+70h] [rbp-39h]
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > v60; // [rsp+78h] [rbp-31h]
  __int64 v61; // [rsp+90h] [rbp-19h]
  __int64 v62; // [rsp+98h] [rbp-11h]
  __int64 v63; // [rsp+A0h] [rbp-9h]
  hkResult result; // [rsp+110h] [rbp+67h]
  int v65; // [rsp+118h] [rbp+6Fh]
  int v66; // [rsp+120h] [rbp+77h]
  int v67; // [rsp+128h] [rbp+7Fh]

  v2 = volume->m_cells.m_size;
  v3 = volume;
  v4 = cellsToRemove;
  v60.m_storage.m_words.m_data = 0i64;
  v60.m_storage.m_words.m_size = 0;
  v60.m_storage.m_words.m_capacityAndFlags = 2147483648;
  v60.m_storage.m_numBits = 0;
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(&v60, 0, v2, 0);
  v5 = 0;
  if ( v4->m_size > 0 )
  {
    v6 = 0i64;
    do
    {
      ++v5;
      ++v6;
      v7 = v4->m_data[v6 - 1];
      v60.m_storage.m_words.m_data[v7 >> 5] |= 1 << (v7 & 0x1F);
    }
    while ( v5 < v4->m_size );
  }
  v8 = 0;
  array = 0i64;
  v52 = 2147483648;
  v51 = 0;
  if ( (signed int)v2 > 0 )
  {
    v9 = v2;
    if ( (signed int)v2 < 0 )
      v9 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, v9, 24);
    v8 = v51;
  }
  v47 = 0i64;
  v10 = 0i64;
  v48 = 0;
  v49 = 2147483648;
  if ( (signed int)v2 > 0 )
  {
    v11 = v2;
    if ( (signed int)v2 < 0 )
      v11 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v47, v11, 8);
    v8 = v51;
    v10 = v48;
  }
  v56 = 0i64;
  v57 = 0;
  v58 = 2147483648;
  if ( (signed int)v2 > 0 )
  {
    v12 = v2;
    if ( (signed int)v2 < 0 )
      v12 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v56, v12, 4);
    v8 = v51;
    v10 = v48;
  }
  v53 = 0i64;
  v54 = 0;
  v55 = 2147483648;
  if ( (signed int)v2 > 0 )
  {
    v13 = v2;
    if ( (signed int)v2 < 0 )
      v13 = 0;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v53, v13, 4);
    v8 = v51;
    v10 = v48;
  }
  v54 = v2;
  v14 = 0;
  v15 = 0i64;
  v62 = v2;
  if ( (signed int)v2 > 0 )
  {
    v16 = 0i64;
    v61 = 0i64;
    do
    {
      if ( !((v60.m_storage.m_words.m_data[(signed __int64)v14 >> 5] >> (v14 & 0x1F)) & 1) )
      {
        v17 = v3->m_cells.m_data;
        v18 = 0;
        v67 = v10;
        v19 = (__int64)v17 + v16;
        v20 = *(signed int *)(v19 + 16);
        result.m_enum = *(_DWORD *)v19;
        LODWORD(v63) = result;
        HIDWORD(v63) = *(_DWORD *)(v19 + 4);
        v65 = *(_DWORD *)(v19 + 8);
        v66 = *(_DWORD *)(v19 + 12);
        v59 = *(_DWORD *)(v19 + 20);
        v21 = HIWORD(v63);
        HIWORD(v63) = 0;
        v22 = v21;
        if ( v21 > 0 )
        {
          v23 = v20;
          do
          {
            v24 = v3->m_edges.m_data[v23];
            v25 = *(_QWORD *)&v3->m_edges.m_data[v23] >> 32;
            if ( !((v60.m_storage.m_words.m_data[(signed __int64)(signed int)v25 >> 5] >> (v25 & 0x1F)) & 1) )
            {
              if ( (_DWORD)v10 == (v49 & 0x3FFFFFFF) )
              {
                hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v47, 8);
                LODWORD(v10) = v48;
              }
              *(hkaiNavVolume::Edge *)(v47 + 8i64 * (signed int)v10) = v24;
              LODWORD(v10) = v48 + 1;
              ++v18;
              ++v48;
            }
            ++v23;
            --v22;
          }
          while ( v22 );
          v8 = v51;
          v16 = v61;
          HIWORD(v63) = v18;
        }
        *(_DWORD *)(v53 + 4 * v15) = v8;
        v26 = v51;
        if ( v51 == (v52 & 0x3FFFFFFF) )
        {
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &array, 24);
          v26 = v51;
        }
        v27 = (__int64)&array[6 * v26];
        if ( v27 )
        {
          *(hkResult *)v27 = result;
          *(_DWORD *)(v27 + 4) = HIDWORD(v63);
          *(_DWORD *)(v27 + 8) = v65;
          *(_DWORD *)(v27 + 12) = v66;
          *(_DWORD *)(v27 + 16) = v67;
          *(_DWORD *)(v27 + 20) = v59;
          v26 = v51;
        }
        v10 = v48;
        v8 = v26 + 1;
        v51 = v8;
      }
      v16 += 24i64;
      ++v15;
      ++v14;
      v61 = v16;
    }
    while ( v15 < v62 );
  }
  v28 = 0;
  if ( (signed int)v10 > 0 )
  {
    v29 = 0i64;
    do
    {
      ++v28;
      v30 = *(signed int *)(v47 + v29 + 4);
      v29 += 8i64;
      *(_DWORD *)(v47 + v29 - 4) = *(_DWORD *)(v53 + 4 * v30);
      v10 = v48;
    }
    while ( v28 < (signed int)v48 );
    v8 = v51;
  }
  v31 = v8;
  if ( v8 > v3->m_cells.m_size )
    v31 = v3->m_cells.m_size;
  v32 = v3->m_cells.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v32 < v8 )
  {
    v33 = 2 * v32;
    v34 = v8;
    if ( v8 < v33 )
      v34 = v33;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_cells, v34, 24);
    v10 = v48;
  }
  v35 = v3->m_cells.m_data;
  if ( v31 > 0 )
  {
    v36 = array;
    v37 = v31;
    do
    {
      v38 = *v36;
      ++v35;
      v36 += 6;
      *(_DWORD *)v35[-1].m_min = v38;
      *(_DWORD *)&v35[-1].m_min[2] = *(v36 - 5);
      *(_DWORD *)v35[-1].m_max = *(v36 - 4);
      *(_DWORD *)&v35[-1].m_max[2] = *(v36 - 3);
      v35[-1].m_startEdgeIndex = *(v36 - 2);
      v35[-1].m_data = *(v36 - 1);
      --v37;
    }
    while ( v37 );
    v10 = v48;
  }
  v39 = (signed __int64)&array[6 * v31];
  v40 = (signed __int64)&v3->m_cells.m_data[v31];
  v41 = v8 - v31;
  if ( v8 - v31 > 0 )
  {
    v39 -= v40;
    do
    {
      if ( v40 )
      {
        *(_DWORD *)v40 = *(_DWORD *)(v39 + v40);
        *(_DWORD *)(v40 + 4) = *(_DWORD *)(v39 + v40 + 4);
        *(_DWORD *)(v40 + 8) = *(_DWORD *)(v39 + v40 + 8);
        *(_DWORD *)(v40 + 12) = *(_DWORD *)(v39 + v40 + 12);
        *(_DWORD *)(v40 + 16) = *(_DWORD *)(v39 + v40 + 16);
        *(_DWORD *)(v40 + 20) = *(_DWORD *)(v39 + v40 + 20);
      }
      v40 += 24i64;
      --v41;
    }
    while ( v41 );
    v10 = v48;
  }
  v3->m_cells.m_size = v8;
  if ( (v3->m_edges.m_capacityAndFlags & 0x3FFFFFFF) < (signed int)v10 )
  {
    if ( v3->m_edges.m_capacityAndFlags >= 0 )
    {
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkaiNavVolume::Edge *, _QWORD, signed __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        v3->m_edges.m_data,
        (unsigned int)(8 * v3->m_edges.m_capacityAndFlags),
        v39);
      v10 = v48;
    }
    result.m_enum = 8 * v10;
    v42 = ((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64, signed __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
            &hkContainerHeapAllocator::s_alloc,
            &result,
            v10,
            v39);
    LODWORD(v10) = v48;
    v3->m_edges.m_data = (hkaiNavVolume::Edge *)v42;
    v3->m_edges.m_capacityAndFlags = result.m_enum / 8;
  }
  v43 = v47;
  v44 = v3->m_edges.m_data;
  v3->m_edges.m_size = v10;
  v45 = 0i64;
  if ( (signed int)v10 > 0 )
  {
    do
    {
      v46 = *(hkaiNavVolume::Edge *)(v43 + 8 * v45++);
      v44[v45 - 1] = v46;
    }
    while ( v45 < (signed int)v10 );
  }
  v54 = 0;
  if ( v55 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v53,
      (unsigned int)(4 * v55),
      v43);
  v53 = 0i64;
  v55 = 2147483648;
  v57 = 0;
  if ( v58 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v56,
      (unsigned int)(4 * v58),
      v43);
  v56 = 0i64;
  v58 = 2147483648;
  v48 = 0;
  if ( v49 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, __int64, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v47,
      (unsigned int)(8 * v49),
      v43);
  v47 = 0i64;
  v49 = 2147483648;
  v51 = 0;
  if ( v52 >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, int *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      array,
      24 * (v52 & 0x3FFFFFFFu),
      v43);
  array = 0i64;
  v52 = 2147483648;
  v60.m_storage.m_words.m_size = 0;
  if ( v60.m_storage.m_words.m_capacityAndFlags >= 0 )
    ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, unsigned int *, _QWORD, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
      &hkContainerHeapAllocator::s_alloc,
      v60.m_storage.m_words.m_data,
      (unsigned int)(4 * v60.m_storage.m_words.m_capacityAndFlags),
      v43);
}

// File Line: 156
// RVA: 0x12FBDF0
__int64 __fastcall hkaiNavVolumeUtils::computeRegions(hkaiNavVolume *volume, hkArrayBase<int> *regionsOut)
{
  int numRegionsOut; // [rsp+50h] [rbp+18h]
  hkResult result; // [rsp+58h] [rbp+20h]

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
void __fastcall hkaiNavVolumeUtils::validate(hkaiNavVolume *vol)
{
  hkaiNavVolume::checkDeterminism(vol);
}

// File Line: 234
// RVA: 0x12FBE40
hkaiAabbTreeNavVolumeMediator *__fastcall hkaiNavVolumeUtils::setupMediator(hkaiNavVolume *vol)
{
  hkaiNavVolume *v1; // rdi
  _QWORD **v2; // rax
  hkaiAabbTreeNavVolumeMediator *v3; // rax
  hkaiAabbTreeNavVolumeMediator *v4; // rax
  hkaiAabbTreeNavVolumeMediator *v5; // rbx

  v1 = vol;
  v2 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v3 = (hkaiAabbTreeNavVolumeMediator *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v2[11] + 8i64))(
                                          v2[11],
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
  hkaiAabbTreeNavVolumeMediator::build(v5, v1);
  return v5;
}

