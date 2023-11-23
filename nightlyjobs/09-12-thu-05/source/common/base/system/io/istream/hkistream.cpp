// File Line: 28
// RVA: 0x12FF7D0
void __fastcall hkIstream::hkIstream(hkIstream *this, hkStreamReader *sb)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkIstream::`vftable;
  if ( sb )
  {
    hkReferencedObject::addReference(sb);
    this->m_streamReader.m_pntr = sb;
  }
  else
  {
    this->m_streamReader.m_pntr = 0i64;
  }
}

// File Line: 33
// RVA: 0x12FF830
void __fastcall hkIstream::hkIstream(hkIstream *this, const char *fname)
{
  hkStreamReader **v3; // rax
  hkStreamReader *m_pntr; // rcx
  hkStreamReader *v5; // rbx
  char v6; // [rsp+30h] [rbp+8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkIstream::`vftable;
  this->m_streamReader.m_pntr = 0i64;
  v3 = (hkStreamReader **)((__int64 (__fastcall *)(hkFileSystem *, char *, const char *, __int64))hkSingleton<hkFileSystem>::s_instance->vfptr[1].__first_virtual_table_function__)(
                            hkSingleton<hkFileSystem>::s_instance,
                            &v6,
                            fname,
                            1i64);
  m_pntr = this->m_streamReader.m_pntr;
  v5 = *v3;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_streamReader.m_pntr = v5;
}

// File Line: 38
// RVA: 0x12FF8A0
void __fastcall hkIstream::hkIstream(hkIstream *this, const void *mem, int memSize)
{
  hkStreamReader *v4; // rdi
  _QWORD **Value; // rax
  hkMemoryStreamReader *v8; // rax
  hkStreamReader *v9; // rax
  hkStreamReader *m_pntr; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkIstream::`vftable;
  v4 = 0i64;
  this->m_streamReader.m_pntr = 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkMemoryStreamReader *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v8 )
  {
    hkMemoryStreamReader::hkMemoryStreamReader(v8, mem, memSize, MEMORY_INPLACE);
    v4 = v9;
  }
  m_pntr = this->m_streamReader.m_pntr;
  if ( m_pntr && m_pntr != v4 )
    hkReferencedObject::removeReference(m_pntr);
  this->m_streamReader.m_pntr = v4;
}

// File Line: 43
// RVA: 0x12FF940
void __fastcall hkIstream::hkIstream(hkIstream *this, hkMemoryTrack *track)
{
  hkStreamReader *v3; // rdi
  _QWORD **Value; // rax
  hkMemoryTrackStreamReader *v6; // rax
  hkStreamReader *v7; // rax
  hkStreamReader *m_pntr; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkIstream::`vftable;
  v3 = 0i64;
  this->m_streamReader.m_pntr = 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkMemoryTrackStreamReader *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v6 )
  {
    hkMemoryTrackStreamReader::hkMemoryTrackStreamReader(v6, track, MEMORY_INPLACE, 0);
    v3 = v7;
  }
  m_pntr = this->m_streamReader.m_pntr;
  if ( m_pntr && m_pntr != v3 )
    hkReferencedObject::removeReference(m_pntr);
  this->m_streamReader.m_pntr = v3;
}

// File Line: 48
// RVA: 0x12FF9D0
void __fastcall hkIstream::~hkIstream(hkIstream *this)
{
  hkStreamReader *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkIstream::`vftable;
  m_pntr = this->m_streamReader.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_streamReader.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 52
// RVA: 0x12FFA10
hkBool *__fastcall hkIstream::isOk(hkIstream *this, hkBool *result)
{
  hkStreamReader *m_pntr; // rcx

  m_pntr = this->m_streamReader.m_pntr;
  if ( m_pntr )
  {
    m_pntr->vfptr[1].__first_virtual_table_function__(m_pntr);
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 71
// RVA: 0x13000E0
void __fastcall eatWhiteSpace(hkStreamReader *reader)
{
  int v2; // r9d
  __int64 v3; // rdi
  __int64 v4; // rdx
  __int64 v5; // rcx
  char v6; // al
  char v7[72]; // [rsp+20h] [rbp-48h] BYREF

  v2 = ((__int64 (__fastcall *)(hkStreamReader *, char *, __int64))reader->vfptr[3].__vecDelDtor)(reader, v7, 64i64);
  if ( v2 )
  {
    v3 = 0x100002600i64;
    while ( 1 )
    {
      v4 = 0i64;
      v5 = 0i64;
      if ( v2 > 0 )
        break;
LABEL_7:
      ((void (__fastcall *)(hkStreamReader *, _QWORD, _QWORD))reader->vfptr[2].__first_virtual_table_function__)(
        reader,
        (unsigned int)v2,
        v2);
      v2 = ((__int64 (__fastcall *)(hkStreamReader *, char *, __int64))reader->vfptr[3].__vecDelDtor)(reader, v7, 64i64);
      if ( !v2 )
        return;
    }
    while ( 1 )
    {
      v6 = v7[v5];
      if ( (unsigned __int8)v6 > 0x20u || !_bittest64(&v3, v6) )
        break;
      ++v5;
      v4 = (unsigned int)(v4 + 1);
      if ( v5 >= v2 )
        goto LABEL_7;
    }
    ((void (__fastcall *)(hkStreamReader *, __int64, _QWORD))reader->vfptr[2].__first_virtual_table_function__)(
      reader,
      v4,
      v2);
  }
}

// File Line: 93
// RVA: 0x1300190
__int64 __fastcall readInteger64(hkStreamReader *reader, hkBool *negOut)
{
  __int64 v4; // rdi
  int v5; // ebx
  int v6; // eax
  __int64 v7; // r8
  unsigned __int64 v8; // rax
  __int64 v9; // rcx
  unsigned int v10; // r10d
  __int64 i; // r9
  char v12; // dl
  unsigned int v13; // eax
  char v15[256]; // [rsp+20h] [rbp-108h] BYREF

  eatWhiteSpace(reader);
  negOut->m_bool = 0;
  v4 = 0i64;
  v5 = 0;
  v6 = ((__int64 (__fastcall *)(hkStreamReader *, char *, __int64))reader->vfptr[3].__vecDelDtor)(reader, v15, 255i64);
  v7 = v6;
  if ( !v6 )
  {
    ((void (__fastcall *)(hkStreamReader *, __int64, _QWORD))reader->vfptr[2].__first_virtual_table_function__)(
      reader,
      1i64,
      0i64);
    return 0i64;
  }
  if ( v15[0] != 43 )
  {
    if ( v15[0] != 45 )
      goto LABEL_6;
    negOut->m_bool = 1;
  }
  v5 = 1;
LABEL_6:
  if ( v5 + 3 < v6
    && v15[v5] == 48
    && ((v15[v5 + 1] - 88) & 0xDF) == 0
    && (v8 = (unsigned __int8)v15[v5 + 2], LOBYTE(v8) = v8 - 48, (unsigned __int8)v8 <= 0x36u)
    && (v9 = 0x7E0000007E03FFi64, _bittest64(&v9, v8)) )
  {
    v10 = 16;
    v5 += 2;
  }
  else if ( v5 + 2 < (int)v7 && v15[v5] == 48 && (unsigned __int8)(v15[v5 + 1] - 48) <= 9u )
  {
    v10 = 8;
    ++v5;
  }
  else
  {
    v10 = 10;
  }
  for ( i = v5; i < v7; v4 = v4 * v10 + v13 )
  {
    v12 = v15[i];
    v13 = -1;
    if ( (unsigned __int8)(v12 - 48) > 9u )
    {
      if ( (unsigned __int8)(v12 - 66) > 4u )
      {
        if ( (unsigned __int8)(v12 - 98) <= 4u )
          v13 = v12 - 87;
      }
      else
      {
        v13 = v12 - 55;
      }
    }
    else
    {
      v13 = v12 - 48;
    }
    if ( v13 >= v10 )
      break;
    ++i;
    ++v5;
  }
  ((void (__fastcall *)(hkStreamReader *, _QWORD))reader->vfptr[2].__first_virtual_table_function__)(
    reader,
    (unsigned int)v5);
  return v4;
}

// File Line: 181
// RVA: 0x1300310
float __fastcall readFloat(hkStreamReader *reader)
{
  int v2; // ebx
  int v3; // eax
  __int64 v4; // rcx
  __int64 v5; // r9
  char v6; // dl
  __int64 v7; // rdx
  char nptr[264]; // [rsp+20h] [rbp-108h] BYREF

  eatWhiteSpace(reader);
  v2 = 0;
  v3 = ((__int64 (__fastcall *)(hkStreamReader *, char *, __int64))reader->vfptr[3].__vecDelDtor)(reader, nptr, 255i64);
  if ( v3 && ((unsigned __int8)(nptr[0] - 48) <= 9u || (unsigned __int8)(nptr[0] - 43) <= 3u) )
  {
    v4 = 1i64;
    v2 = 1;
    if ( v3 > 1i64 )
    {
      v5 = 0x400000004007FE5i64;
      do
      {
        v6 = nptr[v4];
        if ( (unsigned __int8)(v6 - 43) > 0x3Au || !_bittest64(&v5, (char)(v6 - 43)) )
        {
          if ( v6 == 46 )
            goto LABEL_11;
          if ( v6 != 44 )
            break;
        }
        if ( ((v6 - 44) & 0xFD) == 0 )
LABEL_11:
          nptr[v4] = 46;
        ++v4;
        ++v2;
      }
      while ( v4 < v3 );
    }
    v7 = (unsigned int)v2;
  }
  else
  {
    v7 = 1i64;
  }
  ((void (__fastcall *)(hkStreamReader *, __int64))reader->vfptr[2].__first_virtual_table_function__)(reader, v7);
  nptr[v2] = 0;
  if ( v2 <= 0 )
    return FLOAT_N1_0;
  else
    return strtod(nptr, 0i64);
}

// File Line: 225
// RVA: 0x12FFA50
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, hkBool *b)
{
  __int64 v4; // rbp
  int v5; // edi
  char a; // [rsp+30h] [rbp+8h] BYREF
  unsigned __int8 v8; // [rsp+34h] [rbp+Ch]
  unsigned __int8 v9; // [rsp+35h] [rbp+Dh]

  eatWhiteSpace(this->m_streamReader.m_pntr);
  v4 = 0x100002600i64;
  v5 = ((__int64 (__fastcall *)(hkStreamReader *, char *, __int64))this->m_streamReader.m_pntr->vfptr[3].__vecDelDtor)(
         this->m_streamReader.m_pntr,
         &a,
         6i64);
  if ( v5 >= 4 && !hkString::strNcmp(&a, "true", 4u) && (v5 == 4 || v8 <= 0x20u && _bittest64(&v4, (char)v8)) )
  {
    b->m_bool = 1;
    ((void (__fastcall *)(hkStreamReader *, __int64))this->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
      this->m_streamReader.m_pntr,
      4i64);
  }
  else if ( v5 >= 5 && !hkString::strNcmp(&a, "false", 4u) && (v5 == 5 || v9 <= 0x20u && _bittest64(&v4, (char)v9)) )
  {
    b->m_bool = 0;
    ((void (__fastcall *)(hkStreamReader *, __int64))this->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
      this->m_streamReader.m_pntr,
      5i64);
  }
  else
  {
    if ( !v5 )
      ((void (__fastcall *)(hkStreamReader *, __int64))this->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
        this->m_streamReader.m_pntr,
        1i64);
    b->m_bool = 0;
  }
  return this;
}

// File Line: 259
// RVA: 0x12FFB60
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, char *c)
{
  ((void (__fastcall *)(hkStreamReader *, char *, __int64))this->m_streamReader.m_pntr->vfptr[2].__vecDelDtor)(
    this->m_streamReader.m_pntr,
    c,
    1i64);
  return this;
}

// File Line: 281
// RVA: 0x12FFB90
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, __int16 *s)
{
  __int16 v4; // ax
  hkBool negOut; // [rsp+30h] [rbp+8h] BYREF

  v4 = readInteger64(this->m_streamReader.m_pntr, &negOut);
  if ( negOut.m_bool )
    v4 = -v4;
  *s = v4;
  return this;
}

// File Line: 287
// RVA: 0x12FFBD0
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, unsigned __int16 *s)
{
  unsigned __int16 v4; // ax
  hkBool negOut; // [rsp+30h] [rbp+8h] BYREF

  v4 = readInteger64(this->m_streamReader.m_pntr, &negOut);
  if ( negOut.m_bool )
    v4 = -v4;
  *s = v4;
  return this;
}

// File Line: 294
// RVA: 0x12FFC10
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, int *i)
{
  int v4; // eax
  hkBool negOut; // [rsp+30h] [rbp+8h] BYREF

  v4 = readInteger64(this->m_streamReader.m_pntr, &negOut);
  if ( negOut.m_bool )
    v4 = -v4;
  *i = v4;
  return this;
}

// File Line: 300
// RVA: 0x12FFC50
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, unsigned int *i)
{
  int v4; // eax
  hkBool negOut; // [rsp+30h] [rbp+8h] BYREF

  v4 = readInteger64(this->m_streamReader.m_pntr, &negOut);
  if ( negOut.m_bool )
    v4 = -v4;
  *i = v4;
  return this;
}

// File Line: 306
// RVA: 0x12FFC90
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, float *f)
{
  float Float; // xmm0_4
  hkIstream *result; // rax

  Float = readFloat(this->m_streamReader.m_pntr);
  result = this;
  *f = Float;
  return result;
}

// File Line: 312
// RVA: 0x12FFCD0
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, long double *d)
{
  float Float; // xmm0_4
  hkIstream *result; // rax

  Float = readFloat(this->m_streamReader.m_pntr);
  result = this;
  *d = Float;
  return result;
}

// File Line: 320
// RVA: 0x12FFD10
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, __int64 *i)
{
  __int64 v4; // rax
  hkBool negOut; // [rsp+30h] [rbp+8h] BYREF

  v4 = readInteger64(this->m_streamReader.m_pntr, &negOut);
  if ( negOut.m_bool )
    v4 = -v4;
  *i = v4;
  return this;
}

// File Line: 326
// RVA: 0x12FFD50
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, unsigned __int64 *i)
{
  unsigned __int64 v4; // rax
  hkBool negOut; // [rsp+30h] [rbp+8h] BYREF

  v4 = readInteger64(this->m_streamReader.m_pntr, &negOut);
  if ( negOut.m_bool )
    v4 = -(__int64)v4;
  *i = v4;
  return this;
}

// File Line: 332
// RVA: 0x12FFD90
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, hkStringBuf *str)
{
  hkStringBuf *Array; // rdi
  int v5; // esi
  __int64 v6; // r14
  unsigned int v7; // ebx
  __int64 v8; // rcx
  char v9; // al
  char a[64]; // [rsp+20h] [rbp-48h] BYREF

  hkStringBuf::clear(str);
  Array = hkStringBuf::getArray(str);
  eatWhiteSpace(this->m_streamReader.m_pntr);
  v5 = ((__int64 (__fastcall *)(hkStreamReader *, char *, __int64))this->m_streamReader.m_pntr->vfptr[3].__vecDelDtor)(
         this->m_streamReader.m_pntr,
         a,
         64i64);
  if ( v5 )
  {
    v6 = 0x100002600i64;
    while ( 1 )
    {
      v7 = 0;
      v8 = 0i64;
      if ( v5 > 0 )
        break;
LABEL_7:
      ((void (__fastcall *)(hkStreamReader *, _QWORD))this->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
        this->m_streamReader.m_pntr,
        (unsigned int)v5);
      hkArrayBase<char>::_append(&Array->m_string, &hkContainerTempAllocator::s_alloc, a, v5);
      v5 = ((__int64 (__fastcall *)(hkStreamReader *, char *, __int64))this->m_streamReader.m_pntr->vfptr[3].__vecDelDtor)(
             this->m_streamReader.m_pntr,
             a,
             64i64);
      if ( !v5 )
        goto LABEL_8;
    }
    while ( 1 )
    {
      v9 = a[v8];
      if ( (unsigned __int8)v9 <= 0x20u )
      {
        if ( _bittest64(&v6, v9) )
          break;
      }
      ++v8;
      ++v7;
      if ( v8 >= v5 )
        goto LABEL_7;
    }
    ((void (__fastcall *)(hkStreamReader *, _QWORD))this->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
      this->m_streamReader.m_pntr,
      v7);
    hkArrayBase<char>::_append(&Array->m_string, &hkContainerTempAllocator::s_alloc, a, v7);
  }
  else
  {
LABEL_8:
    if ( !Array->m_string.m_size )
      ((void (__fastcall *)(hkStreamReader *, __int64))this->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
        this->m_streamReader.m_pntr,
        1i64);
  }
  if ( Array->m_string.m_size == (Array->m_string.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerTempAllocator::s_alloc, (const void **)&Array->m_string.m_data, 1);
  Array->m_string.m_data[Array->m_string.m_size++] = 0;
  return this;
}

// File Line: 370
// RVA: 0x12FFEF0
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, hkStringPtr *str)
{
  hkStringBuf stra; // [rsp+20h] [rbp-98h] BYREF

  stra.m_string.m_capacityAndFlags = -2147483520;
  stra.m_string.m_size = 1;
  stra.m_string.m_data = stra.m_string.m_storage;
  stra.m_string.m_storage[0] = 0;
  hkIstream::operator>>(this, &stra);
  hkStringPtr::operator=(str, stra.m_string.m_data);
  stra.m_string.m_size = 0;
  if ( stra.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      &hkContainerTempAllocator::s_alloc,
      stra.m_string.m_data,
      stra.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return this;
}

// File Line: 378
// RVA: 0x12FFF90
__int64 __fastcall hkIstream::getline(hkIstream *this, char *str, int maxlen, char delim)
{
  int v8; // eax
  unsigned int v9; // ebx
  __int64 v10; // rsi
  __int64 v11; // rdx
  bool v12; // zf

  eatWhiteSpace(this->m_streamReader.m_pntr);
  v8 = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))this->m_streamReader.m_pntr->vfptr[3].__vecDelDtor)(
         this->m_streamReader.m_pntr,
         str,
         (unsigned int)maxlen);
  v9 = 0;
  v10 = v8;
  v11 = 0i64;
  v12 = v8 == 0;
  if ( v8 > 0 )
  {
    do
    {
      if ( str[v11] == delim )
      {
        str[v9] = 0;
        ((void (__fastcall *)(hkStreamReader *, _QWORD))this->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
          this->m_streamReader.m_pntr,
          v9 + 1);
        return v9;
      }
      ++v11;
      ++v9;
    }
    while ( v11 < v8 );
    if ( v8 < maxlen )
    {
      ((void (__fastcall *)(hkStreamReader *, _QWORD))this->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
        this->m_streamReader.m_pntr,
        (unsigned int)v8);
      str[v10] = 0;
      return (unsigned int)v10;
    }
    v12 = v8 == 0;
  }
  if ( v12 && maxlen > 0 )
    ((void (__fastcall *)(hkStreamReader *, __int64))this->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
      this->m_streamReader.m_pntr,
      1i64);
  ((void (__fastcall *)(hkStreamReader *, _QWORD))this->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
    this->m_streamReader.m_pntr,
    (unsigned int)v10);
  if ( maxlen )
    *str = 0;
  return 0xFFFFFFFFi64;
}

// File Line: 413
// RVA: 0x1300080
__int64 __fastcall hkIstream::read(hkIstream *this, void *buf, __int64 nbytes)
{
  return ((__int64 (__fastcall *)(hkStreamReader *, void *, __int64))this->m_streamReader.m_pntr->vfptr[2].__vecDelDtor)(
           this->m_streamReader.m_pntr,
           buf,
           nbytes);
}

// File Line: 418
// RVA: 0x13000A0
void __fastcall hkIstream::setStreamReader(hkIstream *this, hkStreamReader *newReader)
{
  hkStreamReader *m_pntr; // rcx

  if ( newReader )
    hkReferencedObject::addReference(newReader);
  m_pntr = this->m_streamReader.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_streamReader.m_pntr = newReader;
}

