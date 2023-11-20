// File Line: 17
// RVA: 0xD0E990
void __fastcall hkpConvexVerticesConnectivity::clear(hkpConvexVerticesConnectivity *this)
{
  this->m_vertexIndices.m_size = 0;
  this->m_numVerticesPerFace.m_size = 0;
}

// File Line: 23
// RVA: 0xD0E9A0
void __fastcall hkpConvexVerticesConnectivity::addFace(hkpConvexVerticesConnectivity *this, int *indices, int numIndices)
{
  __int64 v3; // rsi
  int *v4; // rdi
  hkpConvexVerticesConnectivity *v5; // rbp
  hkArray<unsigned short,hkContainerHeapAllocator> *v6; // rbx
  __int64 v7; // rbp
  unsigned __int16 v8; // si

  v3 = (unsigned int)numIndices;
  v4 = indices;
  v5 = this;
  if ( this->m_numVerticesPerFace.m_size == (this->m_numVerticesPerFace.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &this->m_numVerticesPerFace,
      1);
  v5->m_numVerticesPerFace.m_data[v5->m_numVerticesPerFace.m_size++] = v3;
  if ( (signed int)v3 > 0 )
  {
    v6 = &v5->m_vertexIndices;
    v7 = v3;
    do
    {
      v8 = *(_WORD *)v4;
      if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 2);
      ++v4;
      v6->m_data[v6->m_size++] = v8;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 38
// RVA: 0xD0E780
hkBool *__fastcall hkpConvexVerticesConnectivity::isClosed(hkpConvexVerticesConnectivity *this, hkBool *result)
{
  int v2; // er14
  hkpConvexVerticesConnectivity *v3; // r8
  int v4; // er10
  __int64 v5; // rax
  int v6; // ecx
  hkBool *v7; // rbx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v8; // r9
  __int64 v9; // r13
  __int64 v10; // rsi
  __int64 v11; // rdx
  signed __int64 v12; // r12
  __int64 v13; // r15
  signed int v14; // ecx
  signed int v15; // ebx
  int v16; // eax
  unsigned int v17; // edi
  unsigned __int64 v18; // rbp
  int v19; // eax
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v20; // rdx
  unsigned int v21; // eax
  signed __int64 v22; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v23; // rax
  int v24; // ecx
  int v25; // edx
  signed __int64 v26; // rcx
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> >::Pair *v27; // rax
  __int64 v29; // [rsp+20h] [rbp-68h]
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > v30; // [rsp+28h] [rbp-60h]
  hkpConvexVerticesConnectivity *v31; // [rsp+90h] [rbp+8h]
  hkBool *v32; // [rsp+98h] [rbp+10h]
  int v33; // [rsp+A0h] [rbp+18h]

  v32 = result;
  v31 = this;
  v2 = 0;
  v3 = this;
  v4 = -1;
  v5 = this->m_numVerticesPerFace.m_size;
  v6 = 0;
  v7 = result;
  v8 = 0i64;
  v30.m_elem = 0i64;
  v30.m_numElems = 0;
  v30.m_hashMod = -1;
  v33 = 0;
  v9 = 0i64;
  v29 = v5;
  if ( v5 > 0 )
  {
    do
    {
      v10 = 0i64;
      v11 = (unsigned __int8)v3->m_numVerticesPerFace.m_data[v9];
      v12 = (signed __int64)&v3->m_vertexIndices.m_data[v6];
      v13 = (unsigned __int8)v3->m_numVerticesPerFace.m_data[v9];
      v14 = *(unsigned __int16 *)(v12 + 2 * v11 - 2);
      if ( (signed int)v11 > 0 )
      {
        while ( 1 )
        {
          v15 = *(unsigned __int16 *)(v12 + 2 * v10);
          if ( v14 >= v15 )
            v16 = v14 | (v15 << 16);
          else
            v16 = v15 | (v14 << 16);
          v17 = (v14 < *(unsigned __int16 *)(v12 + 2 * v10)) + 1;
          v18 = (unsigned int)(v16 + 1);
          v19 = (unsigned __int64)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                    &v30,
                                    v18);
          if ( v19 > v30.m_hashMod )
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              &v30,
              (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
              v18,
              v17);
          }
          else
          {
            v20 = &v30.m_elem[v19];
            v21 = v20->val;
            if ( v21 & v17 )
            {
              v7 = v32;
              v32->m_bool = 0;
              goto LABEL_26;
            }
            v20->val = v17 | (unsigned __int64)v21;
          }
          ++v10;
          v14 = v15;
          if ( v10 >= v13 )
          {
            v4 = v30.m_hashMod;
            v8 = v30.m_elem;
            v3 = v31;
            LODWORD(v11) = v13;
            break;
          }
        }
      }
      ++v9;
      v6 = v11 + v33;
      v33 += v11;
    }
    while ( v9 < v29 );
    v7 = v32;
  }
  v22 = 0i64;
  if ( v4 >= 0 )
  {
    v23 = v8;
    do
    {
      if ( v23->key != -1i64 )
        break;
      ++v22;
      ++v2;
      ++v23;
    }
    while ( v22 <= v4 );
  }
  v24 = v2;
  if ( v2 > v4 )
  {
LABEL_25:
    v7->m_bool = 1;
  }
  else
  {
    while ( LODWORD(v8[v24].val) == 3 )
    {
      v25 = v24 + 1;
      v26 = v25;
      if ( v25 <= (signed __int64)v4 )
      {
        v27 = &v8[v25];
        do
        {
          if ( v27->key != -1i64 )
            break;
          ++v26;
          ++v25;
          ++v27;
        }
        while ( v26 <= v4 );
      }
      v24 = v25;
      if ( v25 > v4 )
        goto LABEL_25;
    }
    v7->m_bool = 0;
  }
LABEL_26:
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    &v30,
    (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr);
  _((AMD_HD3D *)&v30);
  return v7;
}

