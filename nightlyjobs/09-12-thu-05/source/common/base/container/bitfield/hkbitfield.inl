// File Line: 198
// RVA: 0xB209D0
__int64 __fastcall hkBitFieldImpl::op_and(unsigned int a, unsigned int b)
{
  return b & a;
}

// File Line: 200
// RVA: 0xB209E0
__int64 __fastcall hkBitFieldImpl::op_or(unsigned int a, unsigned int b)
{
  return b | a;
}

// File Line: 206
// RVA: 0xB209F0
void __fastcall hkBitFieldImpl::inplaceBitwiseOp_hkBitFieldInplaceStorage_8__hkBitFieldInplaceStorage_8__unsigned_int____cdecl___unsigned_int_unsigned_int__(
        hkBitFieldBase<hkBitFieldInplaceStorage<8> > *ret,
        hkBitFieldBase<hkBitFieldInplaceStorage<8> > *a,
        unsigned int (__fastcall *op)(unsigned int, unsigned int))
{
  __int64 m_size; // rdi
  unsigned int *m_data; // rax
  char *v6; // rsi
  unsigned int *v7; // rbx
  __int64 v8; // rdx
  __int64 v9; // rcx

  m_size = a->m_storage.m_words.m_size;
  m_data = ret->m_storage.m_words.m_data;
  if ( a->m_storage.m_words.m_size )
  {
    v6 = (char *)((char *)a->m_storage.m_words.m_data - (char *)m_data);
    v7 = &m_data[m_size];
    do
    {
      v8 = *(unsigned int *)((char *)v7 + (_QWORD)v6 - 4);
      v9 = *--v7;
      *v7 = op(v9, v8);
      --m_size;
    }
    while ( m_size );
  }
}

// File Line: 554
// RVA: 0xB5AAF0
void __fastcall hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(
        hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *this,
        int startBit,
        int numNewBits,
        int fillValue)
{
  int m_numBits; // r14d
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // r9d
  unsigned int *m_data; // r11
  int v13; // r10d
  int v14; // edi
  int v15; // r8d
  int v16; // ebp
  int v17; // r8d
  int *v18; // rdi
  __int64 i; // rcx
  int v20; // edi
  hkResult result; // [rsp+60h] [rbp+18h] BYREF

  m_numBits = this->m_storage.m_numBits;
  if ( m_numBits > 0 && m_numBits < numNewBits )
    hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::fillUnusedBits(this, fillValue);
  this->m_storage.m_numBits = numNewBits;
  v8 = this->m_storage.m_words.m_capacityAndFlags & 0x3FFFFFFF;
  v9 = (numNewBits + 31) >> 5;
  if ( v8 < v9 )
  {
    v10 = 2 * v8;
    v11 = (numNewBits + 31) >> 5;
    if ( v9 < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, this, v11, 4);
  }
  this->m_storage.m_words.m_size = v9;
  if ( numNewBits > m_numBits )
  {
    m_data = this->m_storage.m_words.m_data;
    v13 = m_numBits >> 5;
    v14 = -1 << (m_numBits & 0x1F);
    v15 = numNewBits >> 5;
    v16 = -fillValue;
    if ( m_numBits >> 5 == numNewBits >> 5 )
    {
      v20 = ~(-1 << (numNewBits & 0x1F)) & v14;
      if ( v20 )
        m_data[v13] = v16 & v20 | m_data[v13] & ~v20;
    }
    else
    {
      m_data[v13] = v14 & v16 | m_data[v13] & ~v14;
      if ( -1 << (numNewBits & 0x1F) != -1 )
        m_data[v15] = ~(-1 << (numNewBits & 0x1F)) & v16 | m_data[v15] & (-1 << (numNewBits & 0x1F));
      v17 = v15 - v13 - 2;
      v18 = (int *)&m_data[v13 + 1];
      if ( v17 >= 0 )
      {
        for ( i = (unsigned int)(v17 + 1); i; --i )
          *v18++ = v16;
      }
    }
  }
}

// File Line: 574
// RVA: 0xB5A0E0
void __fastcall hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::fillUnusedBits(
        hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *this,
        int fillValue)
{
  int m_numBits; // r11d
  int v3; // r9d
  int v4; // r11d
  unsigned int *v5; // r10
  int v6; // eax

  m_numBits = this->m_storage.m_numBits;
  v3 = (m_numBits - 1) >> 5;
  v4 = m_numBits - 32 * v3;
  v5 = &this->m_storage.m_words.m_data[v3];
  if ( v4 < 32 )
  {
    v6 = -1 << v4;
    if ( fillValue )
      *v5 |= v6;
    else
      *v5 &= ~v6;
  }
}

// File Line: 604
// RVA: 0xB5AC20
hkResult *__fastcall hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(
        hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *this,
        hkResult *result,
        int startBit,
        int numBits,
        int fillValue)
{
  int v6; // eax
  int v7; // r9d
  int v11; // eax
  hkResult resulta; // [rsp+58h] [rbp+20h] BYREF

  v6 = this->m_storage.m_words.m_capacityAndFlags & 0x3FFFFFFF;
  v7 = (numBits + 31) >> 5;
  if ( v6 >= v7 )
  {
    resulta.m_enum = HK_SUCCESS;
LABEL_7:
    hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(
      this,
      startBit,
      numBits,
      fillValue);
    result->m_enum = HK_SUCCESS;
    return result;
  }
  v11 = 2 * v6;
  if ( v7 < v11 )
    v7 = v11;
  hkArrayUtil::_reserve(&resulta, &hkContainerHeapAllocator::s_alloc, this, v7, 4);
  if ( resulta.m_enum == HK_SUCCESS )
    goto LABEL_7;
  result->m_enum = HK_FAILURE;
  return result;
}

