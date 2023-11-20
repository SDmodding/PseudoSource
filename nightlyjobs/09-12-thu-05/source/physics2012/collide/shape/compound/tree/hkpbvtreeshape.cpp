// File Line: 28
// RVA: 0xD0C860
void __fastcall hkpBvTreeShape::hkpBvTreeShape(hkpBvTreeShape *this, hkFinishLoadedObjectFlag flag)
{
  hkpBvTreeShape *v2; // rbx
  int v3; // [rsp+38h] [rbp+10h]

  v3 = flag.m_finishing;
  v2 = this;
  hkpShape::hkpShape((hkpShape *)&this->vfptr, flag);
  v2->vfptr = (hkBaseObjectVtbl *)&hkpBvTreeShape::`vftable';
  if ( v3 )
  {
    v2->m_type.m_storage = 22;
    v2->m_bvTreeType.m_storage = 4;
  }
}

// File Line: 154
// RVA: 0xD0C730
void __fastcall hkpBvTreeShape::castAabbImpl(hkpBvTreeShape *this, hkAabb *from, hkVector4f *to, hkpAabbCastCollector *collector)
{
  hkVector4f v4; // xmm3
  hkpBvTreeShape *v5; // rbx
  hkpAabbCastCollector *v6; // rsi
  __m128 v7; // xmm2
  hkLifoAllocator *v8; // rax
  char *v9; // rdi
  unsigned __int64 v10; // rcx
  __int64 v11; // rbp
  signed int v12; // eax
  __int64 i; // rbx
  hkLifoAllocator *v14; // rax
  __m128 v15; // [rsp+20h] [rbp-28h]
  __m128 v16; // [rsp+30h] [rbp-18h]

  v4.m_quad = (__m128)from->m_min;
  v5 = this;
  v6 = collector;
  v7 = _mm_sub_ps(to->m_quad, _mm_mul_ps(_mm_add_ps(from->m_max.m_quad, from->m_min.m_quad), (__m128)xmmword_141A711B0));
  v16 = _mm_add_ps(from->m_max.m_quad, _mm_max_ps(v7, aabbOut.m_quad));
  v15 = _mm_add_ps(v4.m_quad, _mm_min_ps(v7, aabbOut.m_quad));
  v8 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (char *)v8->m_cur;
  v10 = (unsigned __int64)(v9 + 0x2000);
  if ( v8->m_slabSize < 0x2000 || (void *)v10 > v8->m_end )
    v9 = (char *)hkLifoAllocator::allocateFromNewSlab(v8, 0x2000);
  else
    v8->m_cur = (void *)v10;
  LODWORD(v11) = 2048;
  v12 = ((__int64 (__fastcall *)(hkpBvTreeShape *, __m128 *, char *, signed __int64, unsigned __int64, unsigned __int64, unsigned __int64, unsigned __int64))v5->vfptr[9].__first_virtual_table_function__)(
          v5,
          &v15,
          v9,
          2048i64,
          v15.m128_u64[0],
          v15.m128_u64[1],
          v16.m128_u64[0],
          v16.m128_u64[1]);
  if ( v12 < 2048 )
    LODWORD(v11) = v12;
  if ( (_DWORD)v11 )
  {
    v11 = (signed int)v11;
    for ( i = 0i64; i < v11; ++i )
      v6->vfptr->addHit(v6, *(_DWORD *)&v9[4 * i]);
  }
  v14 = (hkLifoAllocator *)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  if ( v14->m_slabSize < 0x2000 || v9 + 0x2000 != v14->m_cur || v14->m_firstNonLifoEnd == v9 )
    hkLifoAllocator::slowBlockFree(v14, v9, 0x2000);
  else
    v14->m_cur = v9;
}

