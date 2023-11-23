// File Line: 16
// RVA: 0xC80F10
hkResult *__fastcall hkClassEnum::decomposeFlags(
        hkClassEnum *this,
        hkResult *result,
        int flagValue,
        hkArray<char const *,hkContainerHeapAllocator> *bitsOut,
        int *bitsOver)
{
  hkResultEnum v5; // r12d
  int v9; // eax
  __int64 v10; // rbp
  __int64 v11; // r14
  hkClassEnum::Item *m_items; // rcx
  int m_value; // esi
  const char *m_name; // r15
  hkResult *v15; // rax
  hkResult *v16; // [rsp+58h] [rbp+10h]

  v16 = result;
  v5 = HK_SUCCESS;
  bitsOut->m_size = 0;
  v9 = this->m_numItems - 1;
  v10 = v9;
  if ( v9 >= 0 )
  {
    v11 = v9;
    do
    {
      if ( !flagValue )
        break;
      m_items = this->m_items;
      m_value = m_items[v11].m_value;
      if ( (flagValue & m_value) == m_value )
      {
        m_name = m_items[v11].m_name;
        if ( bitsOut->m_size == (bitsOut->m_capacityAndFlags & 0x3FFFFFFF) )
          hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&bitsOut->m_data, 8);
        bitsOut->m_data[bitsOut->m_size++] = m_name;
        flagValue &= ~m_value;
      }
      --v11;
      --v10;
    }
    while ( v10 >= 0 );
    result = v16;
  }
  LOBYTE(v5) = flagValue != 0;
  *bitsOver = flagValue;
  v15 = result;
  result->m_enum = v5;
  return v15;
}

// File Line: 46
// RVA: 0xC80E00
hkResult *__fastcall hkClassEnum::getNameOfValue(hkClassEnum *this, hkResult *result, int val, const char **name)
{
  __int64 m_numItems; // rbx
  int v5; // r11d
  __int64 v6; // r10
  hkClassEnum::Item *m_items; // rcx
  hkClassEnum::Item *v8; // rax

  m_numItems = this->m_numItems;
  v5 = 0;
  v6 = 0i64;
  if ( m_numItems <= 0 )
  {
LABEL_5:
    result->m_enum = HK_FAILURE;
    return result;
  }
  else
  {
    m_items = this->m_items;
    v8 = m_items;
    while ( v8->m_value != val )
    {
      ++v6;
      ++v5;
      ++v8;
      if ( v6 >= m_numItems )
        goto LABEL_5;
    }
    result->m_enum = HK_SUCCESS;
    *name = m_items[v5].m_name;
    return result;
  }
}

// File Line: 59
// RVA: 0xC80E70
hkResult *__fastcall hkClassEnum::getValueOfName(hkClassEnum *this, hkResult *result, const char *name, int *val)
{
  int v4; // ebx
  __int64 v9; // rdi
  hkClassEnum::Item *m_items; // rax

  v4 = 0;
  if ( this->m_numItems <= 0 )
  {
LABEL_5:
    result->m_enum = HK_FAILURE;
  }
  else
  {
    v9 = 0i64;
    while ( (unsigned int)hkString::strCasecmp(name, this->m_items[v9].m_name) )
    {
      ++v4;
      ++v9;
      if ( v4 >= this->m_numItems )
        goto LABEL_5;
    }
    m_items = this->m_items;
    result->m_enum = HK_SUCCESS;
    *val = m_items[v4].m_value;
  }
  return result;
}

// File Line: 72
// RVA: 0xC80FF0
__int64 __fastcall hkClassEnum::getSignature(hkClassEnum *this)
{
  hkCrcStreamWriter<unsigned int,3988292384> w; // [rsp+20h] [rbp-28h] BYREF

  *(_DWORD *)&w.m_memSizeAndFlags = 0x1FFFF;
  w.vfptr = (hkBaseObjectVtbl *)&hkCrc32StreamWriter::`vftable;
  w.m_crc = -1;
  hkClassEnum::writeSignature(this, &w);
  return hkCrcStreamWriter<unsigned int,3988292384>::getCrc(&w);
}

// File Line: 79
// RVA: 0xC81030
void __fastcall hkClassEnum::writeSignature(hkClassEnum *this, hkStreamWriter *w)
{
  const char *m_name; // rbx
  unsigned int v4; // eax
  __int64 m_numItems; // r15
  __int64 v6; // rbp
  __int64 v7; // rsi
  hkClassEnum::Item *m_items; // rdi
  const char *v9; // rbx
  unsigned int v10; // eax
  hkOArchive v11; // [rsp+20h] [rbp-38h] BYREF

  hkOArchive::hkOArchive(&v11, w, 0);
  m_name = this->m_name;
  v4 = hkString::strLen(this->m_name);
  hkOArchive::writeRaw(&v11, m_name, v4);
  m_numItems = this->m_numItems;
  v6 = m_numItems;
  if ( (int)m_numItems > 0 )
  {
    v7 = 0i64;
    do
    {
      m_items = this->m_items;
      v9 = m_items[v7].m_name;
      v10 = hkString::strLen(v9);
      hkOArchive::writeRaw(&v11, v9, v10);
      hkOArchive::write32(&v11, m_items[v7++].m_value);
      --v6;
    }
    while ( v6 );
  }
  hkOArchive::write32(&v11, m_numItems);
  hkOArchive::~hkOArchive(&v11);
}

// File Line: 95
// RVA: 0xC810F0
hkVariant *__fastcall hkClassEnum::getAttribute(hkClassEnum *this, const char *id)
{
  hkCustomAttributes *m_attributes; // rcx

  m_attributes = this->m_attributes;
  if ( m_attributes )
    return hkCustomAttributes::getAttribute(m_attributes, id);
  else
    return 0i64;
}

