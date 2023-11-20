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
void __fastcall hkBitFieldImpl::inplaceBitwiseOp_hkBitFieldInplaceStorage_8__hkBitFieldInplaceStorage_8__unsigned_int____cdecl___unsigned_int_unsigned_int__(hkBitFieldBase<hkBitFieldInplaceStorage<8> > *ret, hkBitFieldBase<hkBitFieldInplaceStorage<8> > *a, unsigned int (__fastcall *op)(unsigned int, unsigned int))
{
  __int64 v3; // rdi
  unsigned int *v4; // rax
  unsigned int (__fastcall *v5)(unsigned int, unsigned int); // rbp
  char *v6; // rsi
  unsigned int *v7; // rbx
  __int64 v8; // rdx
  __int64 v9; // rcx

  v3 = a->m_storage.m_words.m_size;
  v4 = ret->m_storage.m_words.m_data;
  v5 = op;
  if ( a->m_storage.m_words.m_size )
  {
    v6 = (char *)((char *)a->m_storage.m_words.m_data - (char *)v4);
    v7 = &v4[v3];
    do
    {
      v8 = *(unsigned int *)((char *)v7 + (_QWORD)v6 - 4);
      v9 = *(v7 - 1);
      --v7;
      *v7 = v5(v9, v8);
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 554
// RVA: 0xB5AAF0
void __fastcall hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *this, int startBit, int numNewBits, int fillValue)
{
  int v4; // er14
  int v5; // ebp
  int v6; // esi
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *v7; // rbx
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int v11; // er9
  unsigned int *v12; // r11
  int v13; // er10
  signed int v14; // edi
  int v15; // er8
  int v16; // ebp
  int v17; // er8
  int *v18; // rdi
  __int64 i; // rcx
  int v20; // edi
  hkResult result; // [rsp+60h] [rbp+18h]

  v4 = this->m_storage.m_numBits;
  v5 = fillValue;
  v6 = numNewBits;
  v7 = this;
  if ( v4 > 0 && v4 < numNewBits )
    hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::fillUnusedBits(this, fillValue);
  v7->m_storage.m_numBits = v6;
  v8 = v7->m_storage.m_words.m_capacityAndFlags & 0x3FFFFFFF;
  v9 = (v6 + 31) >> 5;
  if ( v8 < v9 )
  {
    v10 = 2 * v8;
    v11 = (v6 + 31) >> 5;
    if ( v9 < v10 )
      v11 = v10;
    hkArrayUtil::_reserve(&result, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, v11, 4);
  }
  v7->m_storage.m_words.m_size = v9;
  if ( v6 > v4 )
  {
    v12 = v7->m_storage.m_words.m_data;
    v13 = v4 >> 5;
    v14 = -1 << (v4 & 0x1F);
    v15 = v6 >> 5;
    v16 = -v5;
    if ( v4 >> 5 == v6 >> 5 )
    {
      v20 = ~(-1 << (v6 & 0x1F)) & v14;
      if ( v20 )
        v12[v13] = v16 & v20 | v12[v13] & ~v20;
    }
    else
    {
      v12[v13] = v14 & v16 | v12[v13] & ~v14;
      if ( -1 << (v6 & 0x1F) != -1 )
        v12[v15] = ~(-1 << (v6 & 0x1F)) & v16 | v12[v15] & (-1 << (v6 & 0x1F));
      v17 = v15 - v13 - 2;
      v18 = (int *)&v12[v13 + 1];
      if ( v17 >= 0 )
      {
        for ( i = (unsigned int)(v17 + 1); i; --i )
        {
          *v18 = v16;
          ++v18;
        }
      }
    }
  }
}

// File Line: 574
// RVA: 0xB5A0E0
void __fastcall hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::fillUnusedBits(hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *this, int fillValue)
{
  int v2; // er11
  int v3; // er9
  int v4; // er11
  unsigned int *v5; // r10
  signed int v6; // eax

  v2 = this->m_storage.m_numBits;
  v3 = (v2 - 1) >> 5;
  v4 = v2 - 32 * v3;
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
hkResult *__fastcall hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::trySetSize(hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *this, hkResult *result, int startBit, int numBits, int fillValue)
{
  int v5; // esi
  int v6; // eax
  int v7; // er9
  int v8; // ebp
  hkResult *v9; // rbx
  hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator> > > *v10; // rdi
  int v11; // eax
  hkResult resulta; // [rsp+58h] [rbp+20h]

  v5 = numBits;
  v6 = this->m_storage.m_words.m_capacityAndFlags & 0x3FFFFFFF;
  v7 = (numBits + 31) >> 5;
  v8 = startBit;
  v9 = result;
  v10 = this;
  if ( v6 >= v7 )
  {
    resulta.m_enum = 0;
LABEL_7:
    hkBitFieldBase<hkBitFieldStorage<hkArray<unsigned int,hkContainerHeapAllocator>>>::setSizeAndFill(
      v10,
      v8,
      v5,
      fillValue);
    v9->m_enum = 0;
    return v9;
  }
  v11 = 2 * v6;
  if ( v7 < v11 )
    v7 = v11;
  hkArrayUtil::_reserve(&resulta, (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, this, v7, 4);
  if ( resulta.m_enum == HK_SUCCESS )
    goto LABEL_7;
  v9->m_enum = 1;
  return v9;
}

