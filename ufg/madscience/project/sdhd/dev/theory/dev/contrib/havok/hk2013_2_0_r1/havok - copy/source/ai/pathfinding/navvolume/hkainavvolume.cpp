// File Line: 21
// RVA: 0xBF3190
void __fastcall hkaiNavVolume::hkaiNavVolume(hkaiNavVolume *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavVolume::`vftable';
}

// File Line: 25
// RVA: 0xBF31D0
void __fastcall hkaiNavVolume::reset(hkaiNavVolume *this)
{
  int v1; // eax
  hkaiNavVolume *v2; // rbx
  int v3; // er8

  v1 = this->m_cells.m_capacityAndFlags;
  v2 = this;
  this->m_cells.m_size = 0;
  if ( v1 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      this->m_cells.m_data,
      24 * (v1 & 0x3FFFFFFF));
  v2->m_cells.m_data = 0i64;
  v2->m_cells.m_capacityAndFlags = 2147483648;
  v3 = v2->m_edges.m_capacityAndFlags;
  v2->m_edges.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
      v2->m_edges.m_data,
      8 * v3);
  v2->m_edges.m_data = 0i64;
  v2->m_edges.m_capacityAndFlags = 2147483648;
  *(_QWORD *)&v2->m_res[1] = -1i64;
  v2->m_res[0] = -1;
}

// File Line: 33
// RVA: 0xBF31B0
void __fastcall hkaiNavVolume::convertPointToWorld(hkaiNavVolume *this, hkVector4f *pointInOut)
{
  hkVector4f v2; // xmm1

  v2.m_quad = _mm_mul_ps(this->m_quantizationScale.m_quad, pointInOut->m_quad);
  *pointInOut = (hkVector4f)v2.m_quad;
  pointInOut->m_quad = _mm_add_ps(this->m_quantizationOffset.m_quad, v2.m_quad);
}

// File Line: 40
// RVA: 0xBF3590
void __fastcall hkaiNavVolume::setAabb(hkaiNavVolume *this, hkAabb *aabb, bool updateQuantization)
{
  this->m_aabb.m_min = aabb->m_min;
  this->m_aabb.m_max = aabb->m_max;
  JUMPOUT(updateQuantization, 0, hkaiNavVolume::_updateQuantizationValues);
}

// File Line: 48
// RVA: 0xBF35B0
void __fastcall hkaiNavVolume::setResolution(hkaiNavVolume *this, int x, int y, int z, bool updateQuantization)
{
  this->m_res[0] = x;
  this->m_res[1] = y;
  this->m_res[2] = z;
  JUMPOUT(updateQuantization != 0, hkaiNavVolume::_updateQuantizationValues);
}

// File Line: 58
// RVA: 0xBF3640
void __fastcall getWorldOffsetAndScale(hkaiNavVolume *volume, hkVector4f *offsetOut, hkVector4f *scaleOut)
{
  hkVector4f v3; // xmm6
  __m128 v4; // xmm5
  hkVector4f v5; // xmm6
  hkVector4f v6; // xmm4
  __m128 v7; // xmm3

  v3.m_quad = (__m128)volume->m_aabb.m_max;
  v4 = _mm_add_ps(volume->m_aabb.m_min.m_quad, v3.m_quad);
  v5.m_quad = _mm_mul_ps(_mm_sub_ps(v3.m_quad, volume->m_aabb.m_min.m_quad), (__m128)xmmword_141A711B0);
  *scaleOut = (hkVector4f)v5.m_quad;
  v6.m_quad = _mm_mul_ps(v5.m_quad, (__m128)xmmword_141A710D0);
  *scaleOut = (hkVector4f)v6.m_quad;
  v7 = (__m128)_mm_unpacklo_epi32(
                 _mm_unpacklo_epi32(_mm_cvtsi32_si128(volume->m_res[0]), _mm_cvtsi32_si128(volume->m_res[2])),
                 _mm_unpacklo_epi32(_mm_cvtsi32_si128(volume->m_res[1]), _mm_cvtsi32_si128(0)));
  scaleOut->m_quad = _mm_div_ps(
                       v6.m_quad,
                       _mm_cvtepi32_ps((__m128i)_mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, *(__m128 *)_xmm), 196)));
  offsetOut->m_quad = _mm_sub_ps(_mm_mul_ps(v4, (__m128)xmmword_141A711B0), v5.m_quad);
}

// File Line: 73
// RVA: 0xBF35F0
void __fastcall hkaiNavVolume::_updateQuantizationValues(hkaiNavVolume *this)
{
  __m128 v1; // xmm2
  __m128 *v2; // rcx
  hkVector4f offsetOut; // [rsp+20h] [rbp-28h]
  hkVector4f scaleOut; // [rsp+30h] [rbp-18h]

  getWorldOffsetAndScale(this, &offsetOut, &scaleOut);
  v1 = _mm_shuffle_ps(scaleOut.m_quad, _mm_unpackhi_ps(scaleOut.m_quad, (__m128)0i64), 196);
  v2[7] = _mm_shuffle_ps(offsetOut.m_quad, _mm_unpackhi_ps(offsetOut.m_quad, (__m128)0i64), 196);
  v2[6] = v1;
}

// File Line: 82
// RVA: 0xBF3700
void __fastcall swap_hkVector4f_(hkVector4f *x, hkVector4f *y)
{
  __m128 v2; // xmm1

  v2 = x->m_quad;
  *x = (hkVector4f)y->m_quad;
  *y = (hkVector4f)v2;
}

// File Line: 92
// RVA: 0xBF3280
void __fastcall hkaiNavVolume::swap(hkaiNavVolume *this, hkaiNavVolume *other)
{
  hkaiNavVolume *v2; // rdi
  hkaiNavVolume *v3; // rbx
  hkVector4f v4; // xmm3
  hkVector4f v5; // xmm2
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm1
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  unsigned __int64 v11; // rcx

  v2 = other;
  v3 = this;
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_cells,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_cells);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v3->m_edges,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_edges);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v3->m_streamingSets,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&v2->m_streamingSets);
  v4.m_quad = (__m128)v3->m_aabb.m_min;
  v5.m_quad = (__m128)v3->m_aabb.m_max;
  v3->m_aabb.m_min = v2->m_aabb.m_min;
  v3->m_aabb.m_max = v2->m_aabb.m_max;
  v2->m_aabb.m_min = (hkVector4f)v4.m_quad;
  v2->m_aabb.m_max = (hkVector4f)v5.m_quad;
  v6.m_quad = (__m128)v3->m_quantizationScale;
  v3->m_quantizationScale = v2->m_quantizationScale;
  v2->m_quantizationScale = (hkVector4f)v6.m_quad;
  v7.m_quad = (__m128)v3->m_quantizationOffset;
  v3->m_quantizationOffset = v2->m_quantizationOffset;
  v2->m_quantizationOffset = (hkVector4f)v7.m_quad;
  v8 = v3->m_res[0];
  v3->m_res[0] = v2->m_res[0];
  v2->m_res[0] = v8;
  v9 = v3->m_res[1];
  v3->m_res[1] = v2->m_res[1];
  v2->m_res[1] = v9;
  v10 = v3->m_res[2];
  v3->m_res[2] = v2->m_res[2];
  v2->m_res[2] = v10;
  v11 = v3->m_userData;
  v3->m_userData = v2->m_userData;
  v2->m_userData = v11;
}

// File Line: 107
// RVA: 0xBF3370
void __fastcall hkaiNavVolume::copy(hkaiNavVolume *this, hkaiNavVolume *other)
{
  int v2; // esi
  hkaiNavVolume *v3; // rbx
  int v4; // ebp
  hkaiNavVolume *v5; // rdi
  int v6; // eax
  int v7; // eax
  int v8; // er9
  hkaiNavVolume::Cell *v9; // rcx
  __int64 v10; // r9
  char *v11; // rdx
  __int64 v12; // r8
  int v13; // eax
  hkaiNavVolume::Cell *v14; // rax
  __int64 v15; // rdx
  signed __int64 v16; // r8
  __int64 v17; // r8
  __int64 v18; // rax
  hkaiNavVolume::Edge *v19; // rcx
  __int64 v20; // rdx
  char *v21; // r8
  hkaiNavVolume::Edge v22; // rax
  hkResult result; // [rsp+50h] [rbp+8h]

  v2 = other->m_cells.m_size;
  v3 = other;
  v4 = other->m_cells.m_size;
  v5 = this;
  if ( v2 > this->m_cells.m_size )
    v4 = this->m_cells.m_size;
  v6 = this->m_cells.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < v2 )
  {
    v7 = 2 * v6;
    v8 = other->m_cells.m_size;
    if ( v2 < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_cells,
      v8,
      24);
  }
  v9 = v5->m_cells.m_data;
  v10 = v4;
  if ( v4 > 0 )
  {
    v11 = (char *)((char *)v3->m_cells.m_data - (char *)v9);
    v12 = v4;
    do
    {
      v13 = *(_DWORD *)((char *)v9->m_min + (_QWORD)v11);
      ++v9;
      *(_DWORD *)v9[-1].m_min = v13;
      *(_DWORD *)&v9[-1].m_min[2] = *(_DWORD *)((char *)&v9->m_min[-10] + (_QWORD)v11);
      *(_DWORD *)v9[-1].m_max = *(_DWORD *)((char *)&v9->m_min[-8] + (_QWORD)v11);
      *(_DWORD *)&v9[-1].m_max[2] = *(_DWORD *)((char *)&v9->m_min[-6] + (_QWORD)v11);
      v9[-1].m_startEdgeIndex = *(_DWORD *)((char *)&v9->m_min[-4] + (_QWORD)v11);
      v9[-1].m_data = *(_DWORD *)((char *)&v9->m_min[-2] + (_QWORD)v11);
      --v12;
    }
    while ( v12 );
  }
  v14 = &v5->m_cells.m_data[v4];
  v15 = v2 - v4;
  if ( v2 - v4 > 0 )
  {
    v16 = (char *)&v3->m_cells.m_data[v4] - (char *)v14;
    do
    {
      if ( v14 )
      {
        *(_DWORD *)v14->m_min = *(_DWORD *)((char *)v14->m_min + v16);
        *(_DWORD *)&v14->m_min[2] = *(_DWORD *)((char *)&v14->m_min[2] + v16);
        *(_DWORD *)v14->m_max = *(_DWORD *)((char *)v14->m_max + v16);
        *(_DWORD *)&v14->m_max[2] = *(_DWORD *)((char *)&v14->m_max[2] + v16);
        v14->m_startEdgeIndex = *(int *)((char *)&v14->m_startEdgeIndex + v16);
        v14->m_data = *(int *)((char *)&v14->m_data + v16);
      }
      ++v14;
      --v15;
    }
    while ( v15 );
  }
  v5->m_cells.m_size = v2;
  v17 = v5->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( (signed int)v17 < v3->m_edges.m_size )
  {
    if ( v5->m_edges.m_capacityAndFlags >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkaiNavVolume::Edge *, _QWORD, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        v5->m_edges.m_data,
        (unsigned int)(8 * v17),
        v4);
    result.m_enum = 8 * v3->m_edges.m_size;
    v5->m_edges.m_data = (hkaiNavVolume::Edge *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                                                  &hkContainerHeapAllocator::s_alloc,
                                                  &result,
                                                  v17,
                                                  v10);
    v5->m_edges.m_capacityAndFlags = result.m_enum / 8;
  }
  v18 = v3->m_edges.m_size;
  v19 = v5->m_edges.m_data;
  v5->m_edges.m_size = v18;
  v20 = v18;
  if ( (signed int)v18 > 0 )
  {
    v21 = (char *)((char *)v3->m_edges.m_data - (char *)v19);
    do
    {
      v22 = *(hkaiNavVolume::Edge *)((char *)v19 + (_QWORD)v21);
      ++v19;
      v19[-1] = v22;
      --v20;
    }
    while ( v20 );
  }
  hkaiStreamingSet::_copy(&result, &v5->m_streamingSets, (hkArrayBase<hkaiStreamingSet> *)&v3->m_streamingSets.m_data);
  v5->m_aabb.m_min = v3->m_aabb.m_min;
  v5->m_aabb.m_max = v3->m_aabb.m_max;
  v5->m_quantizationScale = v3->m_quantizationScale;
  v5->m_quantizationOffset = v3->m_quantizationOffset;
  v5->m_res[0] = v3->m_res[0];
  v5->m_res[1] = v3->m_res[1];
  v5->m_res[2] = v3->m_res[2];
  v5->m_userData = v3->m_userData;
}

// File Line: 124
// RVA: 0xBF35E0
void __fastcall hkaiNavVolume::checkDeterminism(hkaiNavVolume *this)
{
  ;
}

