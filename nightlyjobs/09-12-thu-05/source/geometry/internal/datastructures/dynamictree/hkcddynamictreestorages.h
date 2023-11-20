// File Line: 46
// RVA: 0xDA6A70
void __fastcall hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::releaseAll(hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *this)
{
  hkcdDynamicTree::InplaceStorage<8,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *v1; // rbx
  signed int v2; // er8
  signed __int64 v3; // rax
  signed __int64 v4; // r9
  __int64 v5; // rdx

  v1 = this;
  hkString::memSet(this, 0, 1024);
  v2 = 2;
  v3 = (signed __int64)&v1->m_nodes[1];
  v4 = 14i64;
  do
  {
    v5 = v2++;
    v3 += 64i64;
    *(_QWORD *)(v3 - 64) = v5;
    --v4;
  }
  while ( v4 );
  v1->m_firstFree = 1i64;
  v1->m_nodes[15].m_aabb.m_min.m_quad.m128_u64[0] = 0i64;
}

// File Line: 153
// RVA: 0xCC1A70
hkResult *__fastcall hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong>::reserveNodes(hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *this, hkResult *result, int numAdditionalNodes)
{
  hkResult *v3; // rdi
  hkcdDynamicTree::DynamicStorage<0,hkcdDynamicTree::AnisotropicMetric,hkcdDynamicTree::CodecRawUlong> *v4; // rbx
  int v5; // eax
  int v6; // ebp
  int v7; // er9
  int v8; // eax
  int v9; // eax
  __int64 v11; // r14
  int v12; // eax
  __int64 v13; // rcx
  int v14; // er8
  signed __int64 v15; // rdx
  bool v16; // sf
  unsigned __int8 v17; // of
  unsigned __int64 v18; // r9
  hkResult resulta; // [rsp+60h] [rbp+18h]

  v3 = result;
  v4 = this;
  if ( numAdditionalNodes )
  {
    v5 = this->m_nodes.m_size;
    v6 = this->m_nodes.m_size;
    if ( v5 < 1 )
      v6 = 1;
    v7 = v5 + numAdditionalNodes + 1;
    v8 = this->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
    if ( v8 < v7 )
    {
      v9 = 2 * v8;
      if ( v7 < v9 )
        v7 = v9;
      hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, v7, 64);
      if ( resulta.m_enum )
      {
        v3->m_enum = 1;
        return v3;
      }
    }
    v11 = v4->m_nodes.m_size;
    v4->m_nodes.m_size = v4->m_nodes.m_capacityAndFlags & 0x3FFFFFFF;
    hkString::memSet(&v4->m_nodes.m_data[v11], 0, (v4->m_nodes.m_size - (_DWORD)v11) << 6);
    v12 = v4->m_nodes.m_size - 1;
    v13 = v6;
    if ( v6 <= (signed __int64)v12 )
    {
      v14 = v6 + 1;
      v15 = (signed __int64)v6 << 6;
      v17 = __OFSUB__(v6, v12);
      v16 = v6 - (signed __int64)v12 < 0;
      do
      {
        v18 = v14;
        if ( !(v16 ^ v17) )
          v18 = v4->m_firstFree;
        ++v13;
        v15 += 64i64;
        *(unsigned __int64 *)((char *)v4->m_nodes.m_data[-1].m_aabb.m_min.m_quad.m128_u64 + v15) = v18;
        ++v14;
        v17 = __OFSUB__(v13, v12);
        v16 = v13 - v12 < 0;
      }
      while ( v13 <= v12 );
    }
    v4->m_firstFree = v6;
  }
  v3->m_enum = 0;
  return v3;
}

