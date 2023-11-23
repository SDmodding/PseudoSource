// File Line: 44
// RVA: 0xBD4670
void __fastcall hkaiConvexSilhouetteSet::set(
        hkaiConvexSilhouetteSet *this,
        hkArrayBase<hkVector4f> *vertexPool,
        hkArrayBase<int> *silhouetteSizes,
        hkQTransformf *lastLocalTransform,
        hkVector4f *up)
{
  __int64 m_size; // rax
  hkVector4f *m_data; // rcx
  __int64 v11; // rdx
  char *v12; // r8
  hkVector4f v13; // xmm0
  __int64 v14; // rsi
  int v15; // eax
  int v16; // eax
  int v17; // r9d
  int v18; // r8d
  __int64 v19; // rdx
  int v20; // ecx
  hkVector4f *v21; // rax
  hkResult result; // [rsp+50h] [rbp+8h] BYREF

  if ( (this->m_vertexPool.m_capacityAndFlags & 0x3FFFFFFF) < vertexPool->m_size )
  {
    if ( this->m_vertexPool.m_capacityAndFlags >= 0 )
      hkContainerHeapAllocator::s_alloc.vfptr->bufFree(
        &hkContainerHeapAllocator::s_alloc,
        this->m_vertexPool.m_data,
        16 * this->m_vertexPool.m_capacityAndFlags);
    result.m_enum = 16 * vertexPool->m_size;
    this->m_vertexPool.m_data = (hkVector4f *)hkContainerHeapAllocator::s_alloc.vfptr->bufAlloc(
                                                &hkContainerHeapAllocator::s_alloc,
                                                &result);
    this->m_vertexPool.m_capacityAndFlags = result.m_enum / 16;
  }
  m_size = vertexPool->m_size;
  m_data = this->m_vertexPool.m_data;
  this->m_vertexPool.m_size = m_size;
  v11 = m_size;
  if ( (int)m_size > 0 )
  {
    v12 = (char *)((char *)vertexPool->m_data - (char *)m_data);
    do
    {
      v13.m_quad = *(__m128 *)((char *)m_data++ + (_QWORD)v12);
      m_data[-1] = (hkVector4f)v13.m_quad;
      --v11;
    }
    while ( v11 );
  }
  v14 = silhouetteSizes->m_size;
  v15 = this->m_silhouetteOffsets.m_capacityAndFlags & 0x3FFFFFFF;
  if ( v15 < (int)v14 )
  {
    v16 = 2 * v15;
    v17 = silhouetteSizes->m_size;
    if ( (int)v14 < v16 )
      v17 = v16;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_silhouetteOffsets, v17, 4);
  }
  v18 = 0;
  this->m_silhouetteOffsets.m_size = v14;
  v19 = 0i64;
  if ( (int)v14 > 0 )
  {
    do
    {
      v20 = silhouetteSizes->m_data[v19++];
      this->m_silhouetteOffsets.m_data[v19 - 1] = v18;
      v18 += v20;
    }
    while ( v19 < v14 );
  }
  v21 = up;
  this->m_cachedTransform.m_rotation = lastLocalTransform->m_rotation;
  this->m_cachedTransform.m_translation = lastLocalTransform->m_translation;
  this->m_cachedUp = (hkVector4f)v21->m_quad;
}

