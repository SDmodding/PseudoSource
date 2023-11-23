// File Line: 17
// RVA: 0xD0E990
void __fastcall hkpConvexVerticesConnectivity::clear(hkpConvexVerticesConnectivity *this)
{
  this->m_vertexIndices.m_size = 0;
  this->m_numVerticesPerFace.m_size = 0;
}

// File Line: 23
// RVA: 0xD0E9A0
void __fastcall hkpConvexVerticesConnectivity::addFace(
        hkpConvexVerticesConnectivity *this,
        int *indices,
        unsigned int numIndices)
{
  __int64 v3; // rsi
  hkArray<unsigned short,hkContainerHeapAllocator> *p_m_vertexIndices; // rbx
  __int64 v7; // rbp
  unsigned __int16 v8; // si

  v3 = numIndices;
  if ( this->m_numVerticesPerFace.m_size == (this->m_numVerticesPerFace.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&this->m_numVerticesPerFace.m_data, 1);
  this->m_numVerticesPerFace.m_data[this->m_numVerticesPerFace.m_size++] = v3;
  if ( (int)v3 > 0 )
  {
    p_m_vertexIndices = &this->m_vertexIndices;
    v7 = v3;
    do
    {
      v8 = *(_WORD *)indices;
      if ( p_m_vertexIndices->m_size == (p_m_vertexIndices->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_vertexIndices->m_data, 2);
      ++indices;
      p_m_vertexIndices->m_data[p_m_vertexIndices->m_size++] = v8;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 38
// RVA: 0xD0E780
hkBool *__fastcall hkpConvexVerticesConnectivity::isClosed(hkpConvexVerticesConnectivity *this, hkBool *result)
{
  signed int v2; // r14d
  hkpConvexVerticesConnectivity *v3; // r8
  signed int mHeight; // r10d
  __int64 m_size; // rax
  int v6; // ecx
  hkBool *v7; // rbx
  _QWORD *v8; // r9
  __int64 v9; // r13
  __int64 v10; // rsi
  __int64 v11; // rdx
  __int64 v12; // r12
  __int64 v13; // r15
  int v14; // ecx
  int v15; // ebx
  int v16; // eax
  unsigned int v17; // edi
  unsigned __int64 v18; // rbp
  int Key; // eax
  __int64 v20; // rdx
  unsigned int v21; // eax
  __int64 v22; // rcx
  _QWORD *v23; // rax
  signed int v24; // ecx
  signed int v25; // edx
  __int64 v26; // rcx
  _QWORD *v27; // rax
  __int64 v29; // [rsp+20h] [rbp-68h]
  AMD_HD3D v30[3]; // [rsp+28h] [rbp-60h] BYREF
  int v33; // [rsp+A0h] [rbp+18h]

  v2 = 0;
  v3 = this;
  mHeight = -1;
  m_size = this->m_numVerticesPerFace.m_size;
  v6 = 0;
  v7 = result;
  v8 = 0i64;
  *(_QWORD *)&v30[0].mEnableStereo = 0i64;
  v30[0].mWidth = 0;
  v30[0].mHeight = -1;
  v33 = 0;
  v9 = 0i64;
  v29 = m_size;
  if ( m_size > 0 )
  {
    do
    {
      v10 = 0i64;
      v11 = (unsigned __int8)v3->m_numVerticesPerFace.m_data[v9];
      v12 = (__int64)&v3->m_vertexIndices.m_data[v6];
      v13 = v11;
      v14 = *(unsigned __int16 *)(v12 + 2 * v11 - 2);
      if ( v3->m_numVerticesPerFace.m_data[v9] )
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
          Key = (unsigned int)hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::findKey(
                                (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v30,
                                v18);
          if ( Key > (int)v30[0].mHeight )
          {
            hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::insert(
              (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v30,
              &hkContainerHeapAllocator::s_alloc,
              v18,
              v17);
          }
          else
          {
            v20 = *(_QWORD *)&v30[0].mEnableStereo + 16i64 * Key;
            v21 = *(_DWORD *)(v20 + 8);
            if ( (v21 & v17) != 0 )
            {
              v7 = result;
              result->m_bool = 0;
              goto LABEL_26;
            }
            *(_QWORD *)(v20 + 8) = v17 | (unsigned __int64)v21;
          }
          ++v10;
          v14 = v15;
          if ( v10 >= v13 )
          {
            mHeight = v30[0].mHeight;
            v8 = *(_QWORD **)&v30[0].mEnableStereo;
            v3 = this;
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
    v7 = result;
  }
  v22 = 0i64;
  if ( mHeight >= 0 )
  {
    v23 = v8;
    do
    {
      if ( *v23 != -1i64 )
        break;
      ++v22;
      ++v2;
      v23 += 2;
    }
    while ( v22 <= mHeight );
  }
  v24 = v2;
  if ( v2 > mHeight )
  {
LABEL_25:
    v7->m_bool = 1;
  }
  else
  {
    while ( LODWORD(v8[2 * v24 + 1]) == 3 )
    {
      v25 = v24 + 1;
      v26 = v25;
      if ( v25 <= (__int64)mHeight )
      {
        v27 = &v8[2 * v25];
        do
        {
          if ( *v27 != -1i64 )
            break;
          ++v26;
          ++v25;
          v27 += 2;
        }
        while ( v26 <= mHeight );
      }
      v24 = v25;
      if ( v25 > mHeight )
        goto LABEL_25;
    }
    v7->m_bool = 0;
  }
LABEL_26:
  hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64>>::clearAndDeallocate(
    (hkMapBase<unsigned __int64,unsigned __int64,hkMapOperations<unsigned __int64> > *)v30,
    &hkContainerHeapAllocator::s_alloc);
  _(v30);
  return v7;
} (hkMapBase<unsigned __int64,unsigned __int

