// File Line: 16
// RVA: 0xC80F10
hkResult *__fastcall hkClassEnum::decomposeFlags(hkClassEnum *this, hkResult *result, int flagValue, hkArray<char const *,hkContainerHeapAllocator> *bitsOut, int *bitsOver)
{
  hkResultEnum v5; // er12
  hkArray<char const *,hkContainerHeapAllocator> *v6; // rbx
  int v7; // edi
  hkClassEnum *v8; // r13
  int v9; // eax
  __int64 v10; // rbp
  signed __int64 v11; // r14
  hkClassEnum::Item *v12; // rcx
  int v13; // esi
  const char *v14; // r15
  hkResult *v15; // rax
  hkResult *v16; // [rsp+58h] [rbp+10h]

  v16 = result;
  v5 = 0;
  v6 = bitsOut;
  v7 = flagValue;
  bitsOut->m_size = 0;
  v8 = this;
  v9 = this->m_numItems - 1;
  v10 = v9;
  if ( v9 >= 0 )
  {
    v11 = v9;
    do
    {
      if ( !v7 )
        break;
      v12 = v8->m_items;
      v13 = v12[v11].m_value;
      if ( (v7 & v12[v11].m_value) == v13 )
      {
        v14 = v12[v11].m_name;
        if ( v6->m_size == (v6->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v6, 8);
        v6->m_data[v6->m_size++] = v14;
        v7 &= ~v13;
      }
      --v11;
      --v10;
    }
    while ( v10 >= 0 );
    result = v16;
  }
  LOBYTE(v5) = v7 != 0;
  *bitsOver = v7;
  v15 = result;
  result->m_enum = v5;
  return v15;
}

// File Line: 46
// RVA: 0xC80E00
hkResult *__fastcall hkClassEnum::getNameOfValue(hkClassEnum *this, hkResult *result, int val, const char **name)
{
  __int64 v4; // rbx
  int v5; // er11
  __int64 v6; // r10
  hkClassEnum::Item *v7; // rcx
  hkClassEnum::Item *v8; // rax
  hkResult *v9; // rax

  v4 = this->m_numItems;
  v5 = 0;
  v6 = 0i64;
  if ( v4 <= 0 )
  {
LABEL_5:
    result->m_enum = 1;
    v9 = result;
  }
  else
  {
    v7 = this->m_items;
    v8 = v7;
    while ( v8->m_value != val )
    {
      ++v6;
      ++v5;
      ++v8;
      if ( v6 >= v4 )
        goto LABEL_5;
    }
    result->m_enum = 0;
    *name = v7[v5].m_name;
    v9 = result;
  }
  return v9;
}

// File Line: 59
// RVA: 0xC80E70
hkResult *__fastcall hkClassEnum::getValueOfName(hkClassEnum *this, hkResult *result, const char *name, int *val)
{
  int v4; // ebx
  int *v5; // r15
  const char *v6; // rbp
  hkResult *v7; // r14
  hkClassEnum *v8; // rsi
  __int64 v9; // rdi
  hkClassEnum::Item *v11; // rax

  v4 = 0;
  v5 = val;
  v6 = name;
  v7 = result;
  v8 = this;
  if ( this->m_numItems <= 0 )
  {
LABEL_5:
    v7->m_enum = 1;
  }
  else
  {
    v9 = 0i64;
    while ( (unsigned int)hkString::strCasecmp(v6, v8->m_items[v9].m_name) )
    {
      ++v4;
      ++v9;
      if ( v4 >= v8->m_numItems )
        goto LABEL_5;
    }
    v11 = v8->m_items;
    v7->m_enum = 0;
    *v5 = v11[v4].m_value;
  }
  return v7;
}

// File Line: 72
// RVA: 0xC80FF0
__int64 __fastcall hkClassEnum::getSignature(hkClassEnum *this)
{
  hkStreamWriter w; // [rsp+20h] [rbp-28h]
  int v3; // [rsp+30h] [rbp-18h]

  *(_DWORD *)&w.m_memSizeAndFlags = 0x1FFFF;
  w.vfptr = (hkBaseObjectVtbl *)&hkCrc32StreamWriter::`vftable';
  v3 = -1;
  hkClassEnum::writeSignature(this, &w);
  return hkCrcStreamWriter<unsigned int,3988292384>::getCrc((hkCrcStreamWriter<unsigned int,3988292384> *)&w);
}

// File Line: 79
// RVA: 0xC81030
void __fastcall hkClassEnum::writeSignature(hkClassEnum *this, hkStreamWriter *w)
{
  hkClassEnum *v2; // r14
  const char *v3; // rbx
  unsigned int v4; // eax
  __int64 v5; // r15
  __int64 v6; // rbp
  __int64 v7; // rsi
  hkClassEnum::Item *v8; // rdi
  const char *v9; // rbx
  unsigned int v10; // eax
  hkOArchive v11; // [rsp+20h] [rbp-38h]

  v2 = this;
  hkOArchive::hkOArchive(&v11, w, 0);
  v3 = v2->m_name;
  v4 = hkString::strLen(v2->m_name);
  hkOArchive::writeRaw(&v11, v3, v4);
  v5 = v2->m_numItems;
  v6 = v5;
  if ( (signed int)v5 > 0 )
  {
    v7 = 0i64;
    do
    {
      v8 = v2->m_items;
      v9 = v8[v7].m_name;
      v10 = hkString::strLen(v8[v7].m_name);
      hkOArchive::writeRaw(&v11, v9, v10);
      hkOArchive::write32(&v11, v8[v7].m_value);
      ++v7;
      --v6;
    }
    while ( v6 );
  }
  hkOArchive::write32(&v11, v5);
  hkOArchive::~hkOArchive(&v11);
}

// File Line: 95
// RVA: 0xC810F0
hkVariant *__fastcall hkClassEnum::getAttribute(hkClassEnum *this, const char *id)
{
  JUMPOUT(this->m_attributes, 0i64, hkCustomAttributes::getAttribute);
  return 0i64;
}

