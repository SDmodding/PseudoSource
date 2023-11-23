// File Line: 28
// RVA: 0xD0C860
void __fastcall hkpBvTreeShape::hkpBvTreeShape(hkpBvTreeShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpShape::hkpShape(this, flag);
  this->vfptr = (hkBaseObjectVtbl *)&hkpBvTreeShape::`vftable;
  if ( flag.m_finishing )
  {
    this->m_type.m_storage = 22;
    this->m_bvTreeType.m_storage = 4;
  }
}

// File Line: 154
// RVA: 0xD0C730
void __fastcall hkpBvTreeShape::castAabbImpl(
        hkpBvTreeShape *this,
        hkAabb *from,
        hkVector4f *to,
        hkpAabbCastCollector *collector)
{
  hkVector4f v4; // xmm3
  __m128 v7; // xmm0
  hkLifoAllocator *Value; // rax
  char *m_cur; // rdi
  char *v10; // rcx
  int v11; // ebp
  int v12; // eax
  __int64 i; // rbx
  hkLifoAllocator *v14; // rax
  __int128 v15[2]; // [rsp+20h] [rbp-28h] BYREF

  v4.m_quad = (__m128)from->m_min;
  v7 = _mm_sub_ps(to->m_quad, _mm_mul_ps(_mm_add_ps(from->m_max.m_quad, from->m_min.m_quad), (__m128)xmmword_141A711B0));
  v15[1] = (__int128)_mm_add_ps(from->m_max.m_quad, _mm_max_ps(v7, aabbOut.m_quad));
  v15[0] = (__int128)_mm_add_ps(v4.m_quad, _mm_min_ps(v7, aabbOut.m_quad));
  Value = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  m_cur = (char *)Value->m_cur;
  v10 = m_cur + 0x2000;
  if ( Value->m_slabSize < 0x2000 || v10 > Value->m_end )
    m_cur = (char *)hkLifoAllocator::allocateFromNewSlab(Value, 0x2000);
  else
    Value->m_cur = v10;
  v11 = 2048;
  v12 = ((__int64 (__fastcall *)(hkpBvTreeShape *, __int128 *, char *, __int64))this->vfptr[9].__first_virtual_table_function__)(
          this,
          v15,
          m_cur,
          2048i64);
  if ( v12 < 2048 )
    v11 = v12;
  if ( v11 )
  {
    for ( i = 0i64; i < v11; collector->vfptr->addHit(collector, *(unsigned int *)&m_cur[4 * i++]) )
      ;
  }
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v14->m_slabSize < 0x2000 || m_cur + 0x2000 != v14->m_cur || v14->m_firstNonLifoEnd == m_cur )
    hkLifoAllocator::slowBlockFree(v14, m_cur, 0x2000);
  else
    v14->m_cur = m_cur;
}

