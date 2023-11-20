// File Line: 44
// RVA: 0xBD4670
void __fastcall hkaiConvexSilhouetteSet::set(hkaiConvexSilhouetteSet *this, hkArrayBase<hkVector4f> *vertexPool, hkArrayBase<int> *silhouetteSizes, hkQTransformf *lastLocalTransform, hkVector4f *up)
{
  hkArrayBase<int> *v5; // r14
  hkQTransformf *v6; // rbp
  hkArrayBase<hkVector4f> *v7; // rbx
  hkaiConvexSilhouetteSet *v8; // rdi
  __int64 v9; // rax
  hkVector4f *v10; // rcx
  __int64 v11; // rdx
  char *v12; // r8
  hkVector4f v13; // xmm0
  __int64 v14; // rsi
  int v15; // eax
  int v16; // eax
  int v17; // er9
  int v18; // er8
  __int64 v19; // rdx
  int v20; // ecx
  hkVector4f *v21; // rax
  hkResult result; // [rsp+50h] [rbp+8h]

  v5 = silhouetteSizes;
  v6 = lastLocalTransform;
  v7 = vertexPool;
  v8 = this;
  if ( (this->m_vertexPool.m_capacityAndFlags & 0x3FFFFFFF) < vertexPool->m_size )
  {
    if ( this->m_vertexPool.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
        this->m_vertexPool.m_data,
        16 * this->m_vertexPool.m_capacityAndFlags);
    result.m_enum = 16 * v7->m_size;
    v8->m_vertexPool.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc,
                                              (int *)&result);
    v8->m_vertexPool.m_capacityAndFlags = result.m_enum / 16;
  }
  v9 = v7->m_size;
  v10 = v8->m_vertexPool.m_data;
  v8->m_vertexPool.m_size = v9;
  v11 = v9;
  if ( (signed int)v9 > 0 )
  {
    v12 = (char *)((char *)v7->m_data - (char *)v10);
    do
    {
      v13.m_quad = *(__m128 *)((char *)v10 + (_QWORD)v12);
      ++v10;
      v10[-1] = (hkVector4f)v13.m_quad;
      --v11;
    }
    while ( v11 );
  }
  v14 = v5->m_size;
  v15 = v8->m_silhouetteOffsets.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v15 < (signed int)v14 )
  {
    v16 = 2 * v15;
    v17 = v14;
    if ( (signed int)v14 < v16 )
      v17 = v16;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v8->m_silhouetteOffsets,
      v17,
      4);
  }
  v18 = 0;
  v8->m_silhouetteOffsets.m_size = v14;
  v19 = 0i64;
  if ( (signed int)v14 > 0 )
  {
    do
    {
      v20 = v5->m_data[++v19 - 1];
      v8->m_silhouetteOffsets.m_data[v19 - 1] = v18;
      v18 += v20;
    }
    while ( v19 < v14 );
  }
  v21 = up;
  v8->m_cachedTransform.m_rotation = v6->m_rotation;
  v8->m_cachedTransform.m_translation = v6->m_translation;
  v8->m_cachedUp = (hkVector4f)v21->m_quad;
}

