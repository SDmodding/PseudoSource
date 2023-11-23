// File Line: 21
// RVA: 0xBF3190
void __fastcall hkaiNavVolume::hkaiNavVolume(hkaiNavVolume *this, hkFinishLoadedObjectFlag f)
{
  this->vfptr = (hkBaseObjectVtbl *)&hkaiNavVolume::`vftable;
}

// File Line: 25
// RVA: 0xBF31D0
void __fastcall hkaiNavVolume::reset(hkaiNavVolume *this)
{
  int m_capacityAndFlags; // eax
  int v3; // r8d

  m_capacityAndFlags = this->m_cells.m_capacityAndFlags;
  this->m_cells.m_size = 0;
  if ( m_capacityAndFlags >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
      &hkContainerHeapAllocator::s_alloc,
      this->m_cells.m_data,
      24 * (m_capacityAndFlags & 0x3FFFFFFF));
  this->m_cells.m_data = 0i64;
  this->m_cells.m_capacityAndFlags = 0x80000000;
  v3 = this->m_edges.m_capacityAndFlags;
  this->m_edges.m_size = 0;
  if ( v3 >= 0 )
    hkContainerHeapAllocator::s_alloc.vfptr->bufFree(&hkContainerHeapAllocator::s_alloc, this->m_edges.m_data, 8 * v3);
  this->m_edges.m_data = 0i64;
  this->m_edges.m_capacityAndFlags = 0x80000000;
  *(_QWORD *)&this->m_res[1] = -1i64;
  this->m_res[0] = -1;
}

// File Line: 33
// RVA: 0xBF31B0
void __fastcall hkaiNavVolume::convertPointToWorld(hkaiNavVolume *this, hkVector4f *pointInOut)
{
  __m128 v2; // xmm1

  v2 = _mm_mul_ps(this->m_quantizationScale.m_quad, pointInOut->m_quad);
  *pointInOut = (hkVector4f)v2;
  pointInOut->m_quad = _mm_add_ps(this->m_quantizationOffset.m_quad, v2);
}

// File Line: 40
// RVA: 0xBF3590
void __fastcall hkaiNavVolume::setAabb(hkaiNavVolume *this, hkAabb *aabb, bool updateQuantization)
{
  this->m_aabb = *aabb;
  if ( updateQuantization )
    hkaiNavVolume::_updateQuantizationValues(this);
}

// File Line: 48
// RVA: 0xBF35B0
void __fastcall hkaiNavVolume::setResolution(hkaiNavVolume *this, int x, int y, int z, bool updateQuantization)
{
  this->m_res[0] = x;
  this->m_res[1] = y;
  this->m_res[2] = z;
  if ( updateQuantization )
    hkaiNavVolume::_updateQuantizationValues(this);
}

// File Line: 58
// RVA: 0xBF3640
void __fastcall getWorldOffsetAndScale(hkaiNavVolume *volume, hkVector4f *offsetOut, hkVector4f *scaleOut)
{
  hkVector4f v3; // xmm6
  __m128 v4; // xmm5
  __m128 v5; // xmm6
  __m128 v6; // xmm4
  __m128 v7; // xmm3

  v3.m_quad = (__m128)volume->m_aabb.m_max;
  v4 = _mm_add_ps(volume->m_aabb.m_min.m_quad, v3.m_quad);
  v5 = _mm_mul_ps(_mm_sub_ps(v3.m_quad, volume->m_aabb.m_min.m_quad), (__m128)xmmword_141A711B0);
  *scaleOut = (hkVector4f)v5;
  v6 = _mm_mul_ps(v5, (__m128)xmmword_141A710D0);
  *scaleOut = (hkVector4f)v6;
  v7 = (__m128)_mm_unpacklo_epi32(
                 _mm_unpacklo_epi32(_mm_cvtsi32_si128(volume->m_res[0]), _mm_cvtsi32_si128(volume->m_res[2])),
                 _mm_unpacklo_epi32(_mm_cvtsi32_si128(volume->m_res[1]), _mm_cvtsi32_si128(0)));
  scaleOut->m_quad = _mm_div_ps(
                       v6,
                       _mm_cvtepi32_ps((__m128i)_mm_shuffle_ps(v7, _mm_unpackhi_ps(v7, *(__m128 *)_xmm), 196)));
  offsetOut->m_quad = _mm_sub_ps(_mm_mul_ps(v4, (__m128)xmmword_141A711B0), v5);
}

// File Line: 73
// RVA: 0xBF35F0
void __fastcall hkaiNavVolume::_updateQuantizationValues(hkaiNavVolume *this)
{
  __m128 v1; // xmm2
  __m128 *v2; // rcx
  hkVector4f offsetOut; // [rsp+20h] [rbp-28h] BYREF
  hkVector4f scaleOut; // [rsp+30h] [rbp-18h] BYREF

  getWorldOffsetAndScale(this, &offsetOut, &scaleOut);
  v1 = _mm_shuffle_ps(scaleOut.m_quad, _mm_unpackhi_ps(scaleOut.m_quad, (__m128)0i64), 196);
  v2[7] = _mm_shuffle_ps(offsetOut.m_quad, _mm_unpackhi_ps(offsetOut.m_quad, (__m128)0i64), 196);
  v2[6] = v1;
}

// File Line: 82
// RVA: 0xBF3700
void __fastcall swap_hkVector4f_(hkVector4f *x, hkVector4f *y)
{
  __m128 m_quad; // xmm1

  m_quad = x->m_quad;
  *x = (hkVector4f)y->m_quad;
  *y = (hkVector4f)m_quad;
}

// File Line: 92
// RVA: 0xBF3280
void __fastcall hkaiNavVolume::swap(hkaiNavVolume *this, hkaiNavVolume *other)
{
  hkVector4f v4; // xmm3
  hkVector4f v5; // xmm2
  hkVector4f v6; // xmm1
  hkVector4f v7; // xmm1
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  unsigned __int64 m_userData; // rcx

  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_cells,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_cells);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_edges,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_edges);
  hkArray<hkpTreeBroadPhase32::Handle,hkContainerHeapAllocator>::swap(
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&this->m_streamingSets,
    (hkArray<hkRelocationInfo::Import,hkContainerHeapAllocator> *)&other->m_streamingSets);
  v4.m_quad = (__m128)this->m_aabb.m_min;
  v5.m_quad = (__m128)this->m_aabb.m_max;
  this->m_aabb = other->m_aabb;
  other->m_aabb.m_min = (hkVector4f)v4.m_quad;
  other->m_aabb.m_max = (hkVector4f)v5.m_quad;
  v6.m_quad = (__m128)this->m_quantizationScale;
  this->m_quantizationScale = other->m_quantizationScale;
  other->m_quantizationScale = (hkVector4f)v6.m_quad;
  v7.m_quad = (__m128)this->m_quantizationOffset;
  this->m_quantizationOffset = other->m_quantizationOffset;
  other->m_quantizationOffset = (hkVector4f)v7.m_quad;
  v8 = this->m_res[0];
  this->m_res[0] = other->m_res[0];
  other->m_res[0] = v8;
  v9 = this->m_res[1];
  this->m_res[1] = other->m_res[1];
  other->m_res[1] = v9;
  v10 = this->m_res[2];
  this->m_res[2] = other->m_res[2];
  other->m_res[2] = v10;
  m_userData = this->m_userData;
  this->m_userData = other->m_userData;
  other->m_userData = m_userData;
}

// File Line: 107
// RVA: 0xBF3370
void __fastcall hkaiNavVolume::copy(hkaiNavVolume *this, hkaiNavVolume *other)
{
  int m_size; // esi
  int v4; // ebp
  int v6; // eax
  int v7; // eax
  int v8; // r9d
  hkaiNavVolume::Cell *m_data; // rcx
  __int64 v10; // r9
  char *v11; // rdx
  __int64 v12; // r8
  int v13; // eax
  hkaiNavVolume::Cell *v14; // rax
  __int64 v15; // rdx
  char *v16; // r8
  __int64 v17; // r8
  __int64 v18; // rax
  hkaiNavVolume::Edge *v19; // rcx
  __int64 v20; // rdx
  char *v21; // r8
  hkaiNavVolume::Edge v22; // rax
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  m_size = other->m_cells.m_size;
  v4 = m_size;
  if ( m_size > this->m_cells.m_size )
    v4 = this->m_cells.m_size;
  v6 = this->m_cells.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v6 < m_size )
  {
    v7 = 2 * v6;
    v8 = other->m_cells.m_size;
    if ( m_size < v7 )
      v8 = v7;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_cells, v8, 24);
  }
  m_data = this->m_cells.m_data;
  v10 = v4;
  if ( v4 > 0 )
  {
    v11 = (char *)((char *)other->m_cells.m_data - (char *)m_data);
    v12 = v4;
    do
    {
      v13 = *(_DWORD *)((char *)m_data->m_min + (_QWORD)v11);
      ++m_data;
      *(_DWORD *)m_data[-1].m_min = v13;
      *(_DWORD *)&m_data[-1].m_min[2] = *(_DWORD *)((char *)&m_data->m_min[-10] + (_QWORD)v11);
      *(_DWORD *)m_data[-1].m_max = *(_DWORD *)((char *)&m_data->m_min[-8] + (_QWORD)v11);
      *(_DWORD *)&m_data[-1].m_max[2] = *(_DWORD *)((char *)&m_data->m_min[-6] + (_QWORD)v11);
      m_data[-1].m_startEdgeIndex = *(_DWORD *)((char *)&m_data->m_min[-4] + (_QWORD)v11);
      m_data[-1].m_data = *(_DWORD *)((char *)&m_data->m_min[-2] + (_QWORD)v11);
      --v12;
    }
    while ( v12 );
  }
  v14 = &this->m_cells.m_data[v4];
  v15 = m_size - v4;
  if ( m_size - v4 > 0 )
  {
    v16 = (char *)((char *)&other->m_cells.m_data[v4] - (char *)v14);
    do
    {
      if ( v14 )
      {
        *(_DWORD *)v14->m_min = *(_DWORD *)((char *)v14->m_min + (_QWORD)v16);
        *(_DWORD *)&v14->m_min[2] = *(_DWORD *)((char *)&v14->m_min[2] + (_QWORD)v16);
        *(_DWORD *)v14->m_max = *(_DWORD *)((char *)v14->m_max + (_QWORD)v16);
        *(_DWORD *)&v14->m_max[2] = *(_DWORD *)((char *)&v14->m_max[2] + (_QWORD)v16);
        v14->m_startEdgeIndex = *(_DWORD *)((char *)&v14->m_max[4] + (_QWORD)v16);
        v14->m_data = *(int *)((char *)&v14->m_data + (_QWORD)v16);
      }
      ++v14;
      --v15;
    }
    while ( v15 );
  }
  this->m_cells.m_size = m_size;
  v17 = this->m_edges.m_capacityAndFlags & 0x3FFFFFFF;
  if ( (int)v17 < other->m_edges.m_size )
  {
    if ( this->m_edges.m_capacityAndFlags >= 0 )
      ((void (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkaiNavVolume::Edge *, _QWORD, _QWORD))hkContainerHeapAllocator::s_alloc.vfptr->bufFree)(
        &hkContainerHeapAllocator::s_alloc,
        this->m_edges.m_data,
        (unsigned int)(8 * this->m_edges.m_capacityAndFlags),
        v4);
    result.m_enum = 8 * other->m_edges.m_size;
    this->m_edges.m_data = (hkaiNavVolume::Edge *)((__int64 (__fastcall *)(hkContainerHeapAllocator::Allocator *, hkResult *, __int64, __int64))hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc)(
                                                    &hkContainerHeapAllocator::s_alloc,
                                                    &result,
                                                    v17,
                                                    v10);
    this->m_edges.m_capacityAndFlags = result.m_enum / 8;
  }
  v18 = other->m_edges.m_size;
  v19 = this->m_edges.m_data;
  this->m_edges.m_size = v18;
  v20 = v18;
  if ( (int)v18 > 0 )
  {
    v21 = (char *)((char *)other->m_edges.m_data - (char *)v19);
    do
    {
      v22 = *(hkaiNavVolume::Edge *)((char *)v19++ + (_QWORD)v21);
      v19[-1] = v22;
      --v20;
    }
    while ( v20 );
  }
  hkaiStreamingSet::_copy(&result, &this->m_streamingSets, &other->m_streamingSets);
  this->m_aabb.m_min = other->m_aabb.m_min;
  this->m_aabb.m_max = other->m_aabb.m_max;
  this->m_quantizationScale = other->m_quantizationScale;
  this->m_quantizationOffset = other->m_quantizationOffset;
  this->m_res[0] = other->m_res[0];
  this->m_res[1] = other->m_res[1];
  this->m_res[2] = other->m_res[2];
  this->m_userData = other->m_userData;
}

// File Line: 124
// RVA: 0xBF35E0
void __fastcall hkaiNavVolume::checkDeterminism(hkaiNavVolume *this)
{
  ;
}

