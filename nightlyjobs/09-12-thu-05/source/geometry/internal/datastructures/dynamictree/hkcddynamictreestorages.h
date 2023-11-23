// File Line: 46
// RVA: 0xDA6A70
void __fastcall hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::releaseAll(
        hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *this)
{
  int v2; // r8d
  hkcdDynamicTree::CodecRawUlong *v3; // rax
  __int64 v4; // r9
  unsigned __int64 v5; // rdx

  hkString::memSet(this, 0, 0x400u);
  v2 = 2;
  v3 = &this->m_nodes[1];
  v4 = 14i64;
  do
  {
    v5 = v2++;
    ++v3;
    v3[-1].m_aabb.m_min.m_quad.m128_u64[0] = v5;
    --v4;
  }
  while ( v4 );
  this->m_firstFree = 1i64;
  this->m_nodes[15].m_aabb.m_min.m_quad.m128_u64[0] = 0i64;
}

// File Line: 153
// RVA: 0xCC1A70
hkResult *__fastcall hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(
        hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *this,
        hkResult *result,
        int numAdditionalNodes)
{
  int m_size; // eax
  int v6; // ebp
  int v7; // r9d
  int v8; // eax
  int v9; // eax
  __int64 v11; // r14
  int v12; // eax
  __int64 v13; // rcx
  int v14; // r8d
  __int64 v15; // rdx
  bool v16; // cc
  unsigned __int64 m_firstFree; // r9
  hkResult resulta; // [rsp+60h] [rbp+18h] BYREF

  if ( numAdditionalNodes )
  {
    m_size = this->m_nodes.m_size;
    v6 = m_size;
    if ( m_size < 1 )
      v6 = 1;
    v7 = m_size + numAdditionalNodes + 1;
    v8 = this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < v7 )
    {
      v9 = 2 * v8;
      if ( v7 < v9 )
        v7 = v9;
      hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, (const void **)&this->m_nodes.m_data, v7, 64);
      if ( resulta.m_enum )
      {
        result->m_enum = HK_FAILURE;
        return result;
      }
    }
    v11 = this->m_nodes.m_size;
    this->m_nodes.m_size = this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
    hkString::memSet(&this->m_nodes.m_data[v11], 0, (this->m_nodes.m_size - (_DWORD)v11) << 6);
    v12 = this->m_nodes.m_size - 1;
    v13 = v6;
    if ( v6 <= (__int64)v12 )
    {
      v14 = v6 + 1;
      v15 = (__int64)v6 << 6;
      v16 = v6 < (__int64)v12;
      do
      {
        m_firstFree = v14;
        if ( !v16 )
          m_firstFree = this->m_firstFree;
        ++v13;
        v15 += 64i64;
        *(unsigned __int64 *)((char *)this->m_nodes.m_data[-1].m_aabb.m_min.m_quad.m128_u64 + v15) = m_firstFree;
        ++v14;
        v16 = v13 < v12;
      }
      while ( v13 <= v12 );
    }
    this->m_firstFree = v6;
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

