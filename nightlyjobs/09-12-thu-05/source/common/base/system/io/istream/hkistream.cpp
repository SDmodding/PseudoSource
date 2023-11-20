// File Line: 28
// RVA: 0x12FF7D0
void __fastcall hkIstream::hkIstream(hkIstream *this, hkStreamReader *sb)
{
  hkStreamReader *v2; // rdi
  hkIstream *v3; // rbx

  v2 = sb;
  v3 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkIstream::`vftable';
  if ( sb )
  {
    hkReferencedObject::addReference((hkReferencedObject *)&sb->vfptr);
    v3->m_streamReader.m_pntr = v2;
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
  hkIstream *v2; // rdi
  hkStreamReader **v3; // rax
  hkReferencedObject *v4; // rcx
  hkStreamReader *v5; // rbx
  char v6; // [rsp+30h] [rbp+8h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkIstream::`vftable';
  this->m_streamReader.m_pntr = 0i64;
  v3 = (hkStreamReader **)((__int64 (__fastcall *)(hkFileSystem *, char *, const char *, signed __int64))hkSingleton<hkFileSystem>::s_instance->vfptr[1].__first_virtual_table_function__)(
                            hkSingleton<hkFileSystem>::s_instance,
                            &v6,
                            fname,
                            1i64);
  v4 = (hkReferencedObject *)&v2->m_streamReader.m_pntr->vfptr;
  v5 = *v3;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v2->m_streamReader.m_pntr = v5;
}

// File Line: 38
// RVA: 0x12FF8A0
void __fastcall hkIstream::hkIstream(hkIstream *this, const void *mem, int memSize)
{
  hkIstream *v3; // rbx
  hkStreamReader *v4; // rdi
  int v5; // esi
  const void *v6; // rbp
  _QWORD **v7; // rax
  hkMemoryStreamReader *v8; // rax
  hkStreamReader *v9; // rax
  hkReferencedObject *v10; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v3 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkIstream::`vftable';
  v4 = 0i64;
  v5 = memSize;
  this->m_streamReader.m_pntr = 0i64;
  v6 = mem;
  v7 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v8 = (hkMemoryStreamReader *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v7[11] + 8i64))(v7[11], 40i64);
  if ( v8 )
  {
    hkMemoryStreamReader::hkMemoryStreamReader(v8, v6, v5, MEMORY_INPLACE);
    v4 = v9;
  }
  v10 = (hkReferencedObject *)&v3->m_streamReader.m_pntr->vfptr;
  if ( v10 && v10 != (hkReferencedObject *)v4 )
    hkReferencedObject::removeReference(v10);
  v3->m_streamReader.m_pntr = v4;
}

// File Line: 43
// RVA: 0x12FF940
void __fastcall hkIstream::hkIstream(hkIstream *this, hkMemoryTrack *track)
{
  hkIstream *v2; // rbx
  hkStreamReader *v3; // rdi
  hkMemoryTrack *v4; // rsi
  _QWORD **v5; // rax
  hkMemoryTrackStreamReader *v6; // rax
  hkStreamReader *v7; // rax
  hkReferencedObject *v8; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkIstream::`vftable';
  v3 = 0i64;
  v4 = track;
  this->m_streamReader.m_pntr = 0i64;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkMemoryTrackStreamReader *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(
                                      v5[11],
                                      40i64);
  if ( v6 )
  {
    hkMemoryTrackStreamReader::hkMemoryTrackStreamReader(v6, v4, MEMORY_INPLACE, 0);
    v3 = v7;
  }
  v8 = (hkReferencedObject *)&v2->m_streamReader.m_pntr->vfptr;
  if ( v8 && v8 != (hkReferencedObject *)v3 )
    hkReferencedObject::removeReference(v8);
  v2->m_streamReader.m_pntr = v3;
}

// File Line: 48
// RVA: 0x12FF9D0
void __fastcall hkIstream::~hkIstream(hkIstream *this)
{
  hkIstream *v1; // rbx
  hkStreamReader *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkIstream::`vftable';
  v2 = this->m_streamReader.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_streamReader.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
}

// File Line: 52
// RVA: 0x12FFA10
hkBool *__fastcall hkIstream::isOk(hkIstream *this, hkBool *result)
{
  hkStreamReader *v2; // rcx
  hkBool *v3; // rbx
  hkBool *v4; // rax

  v2 = this->m_streamReader.m_pntr;
  v3 = result;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr[1].__first_virtual_table_function__)();
    v4 = v3;
  }
  else
  {
    result->m_bool = 0;
    v4 = result;
  }
  return v4;
}

// File Line: 71
// RVA: 0x13000E0
void __fastcall eatWhiteSpace(hkStreamReader *reader)
{
  hkStreamReader *v1; // rbx
  unsigned int v2; // er9
  signed __int64 v3; // rdi
  __int64 v4; // rdx
  signed __int64 v5; // rcx
  char v6; // al
  char v7[72]; // [rsp+20h] [rbp-48h]

  v1 = reader;
  v2 = ((__int64 (__fastcall *)(hkStreamReader *, char *, signed __int64))reader->vfptr[3].__vecDelDtor)(
         reader,
         v7,
         64i64);
  if ( v2 )
  {
    v3 = 4294977024i64;
    while ( 1 )
    {
      v4 = 0i64;
      v5 = 0i64;
      if ( (signed int)v2 > 0 )
        break;
LABEL_7:
      ((void (__fastcall *)(hkStreamReader *, _QWORD, _QWORD))v1->vfptr[2].__first_virtual_table_function__)(
        v1,
        v2,
        (signed int)v2);
      v2 = ((__int64 (__fastcall *)(hkStreamReader *, char *, signed __int64))v1->vfptr[3].__vecDelDtor)(v1, v7, 64i64);
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
      if ( v5 >= (signed int)v2 )
        goto LABEL_7;
    }
    ((void (__fastcall *)(hkStreamReader *, __int64, _QWORD))v1->vfptr[2].__first_virtual_table_function__)(
      v1,
      v4,
      (signed int)v2);
  }
}

// File Line: 93
// RVA: 0x1300190
__int64 __fastcall readInteger64(hkStreamReader *reader, hkBool *negOut)
{
  hkBool *v2; // rsi
  hkStreamReader *v3; // r14
  __int64 v4; // rdi
  signed int v5; // ebx
  int v6; // eax
  __int64 v7; // r8
  unsigned __int64 v8; // rax
  signed __int64 v9; // rcx
  unsigned int v10; // er10
  __int64 i; // r9
  char v12; // dl
  unsigned int v13; // eax
  char v15; // [rsp+20h] [rbp-108h]
  char v16; // [rsp+21h] [rbp-107h]
  char v17[254]; // [rsp+22h] [rbp-106h]

  v2 = negOut;
  v3 = reader;
  eatWhiteSpace(reader);
  v2->m_bool = 0;
  v4 = 0i64;
  v5 = 0;
  v6 = ((__int64 (__fastcall *)(hkStreamReader *, char *, signed __int64))v3->vfptr[3].__vecDelDtor)(v3, &v15, 255i64);
  v7 = v6;
  if ( !v6 )
  {
    ((void (__fastcall *)(hkStreamReader *, signed __int64, _QWORD))v3->vfptr[2].__first_virtual_table_function__)(
      v3,
      1i64,
      0i64);
    return 0i64;
  }
  if ( v15 != 43 )
  {
    if ( v15 != 45 )
      goto LABEL_6;
    v2->m_bool = 1;
  }
  v5 = 1;
LABEL_6:
  if ( v5 + 3 >= v6
    || *(&v15 + v5) != 48
    || (*(&v16 + v5) - 88) & 0xDF
    || (v8 = (unsigned __int8)v17[v5], LOBYTE(v8) = v8 - 48, (unsigned __int8)v8 > 0x36u)
    || (v9 = 35465847073801215i64, !_bittest64(&v9, v8)) )
  {
    if ( v5 + 2 >= (signed int)v7 || *(&v15 + v5) != 48 || (unsigned __int8)(*(&v16 + v5) - 48) > 9u )
    {
      v10 = 10;
    }
    else
    {
      v10 = 8;
      ++v5;
    }
  }
  else
  {
    v10 = 16;
    v5 += 2;
  }
  for ( i = v5; i < v7; v4 = v4 * v10 + v13 )
  {
    v12 = *(&v15 + i);
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
  ((void (__fastcall *)(hkStreamReader *, _QWORD))v3->vfptr[2].__first_virtual_table_function__)(v3, (unsigned int)v5);
  return v4;
}

// File Line: 181
// RVA: 0x1300310
float __usercall readFloat@<xmm0>(hkStreamReader *reader@<rcx>, double a2@<xmm0>)
{
  hkStreamReader *v2; // rdi
  signed int v3; // ebx
  int v4; // eax
  signed __int64 v5; // rcx
  signed __int64 v6; // r9
  char v7; // dl
  signed __int64 v8; // rdx
  char nptr[264]; // [rsp+20h] [rbp-108h]

  v2 = reader;
  eatWhiteSpace(reader);
  v3 = 0;
  v4 = ((__int64 (__fastcall *)(hkStreamReader *, char *, signed __int64))v2->vfptr[3].__vecDelDtor)(v2, nptr, 255i64);
  if ( v4 && ((unsigned __int8)(nptr[0] - 48) <= 9u || (unsigned __int8)(nptr[0] - 43) <= 3u) )
  {
    v5 = 1i64;
    v3 = 1;
    if ( v4 > 1i64 )
    {
      v6 = 288230376218853349i64;
      do
      {
        v7 = nptr[v5];
        if ( (unsigned __int8)(v7 - 43) > 0x3Au || !_bittest64(&v6, (char)(v7 - 43)) )
        {
          if ( v7 == 46 )
            goto LABEL_11;
          if ( v7 != 44 )
            break;
        }
        if ( !((v7 - 44) & 0xFD) )
LABEL_11:
          nptr[v5] = 46;
        ++v5;
        ++v3;
      }
      while ( v5 < v4 );
    }
    v8 = (unsigned int)v3;
  }
  else
  {
    v8 = 1i64;
  }
  ((void (__fastcall *)(hkStreamReader *, signed __int64))v2->vfptr[2].__first_virtual_table_function__)(v2, v8);
  nptr[v3] = 0;
  if ( v3 <= 0 )
    return FLOAT_N1_0;
  strtod(nptr, 0i64);
  return a2;
}

// File Line: 225
// RVA: 0x12FFA50
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, hkBool *b)
{
  hkIstream *v2; // rbx
  hkBool *v3; // rsi
  signed __int64 v4; // rbp
  signed int v5; // edi
  char a; // [rsp+30h] [rbp+8h]
  unsigned __int8 v8; // [rsp+34h] [rbp+Ch]
  unsigned __int8 v9; // [rsp+35h] [rbp+Dh]

  v2 = this;
  v3 = b;
  eatWhiteSpace(this->m_streamReader.m_pntr);
  v4 = 4294977024i64;
  v5 = ((__int64 (__fastcall *)(hkStreamReader *, char *, signed __int64))v2->m_streamReader.m_pntr->vfptr[3].__vecDelDtor)(
         v2->m_streamReader.m_pntr,
         &a,
         6i64);
  if ( v5 < 4 || hkString::strNcmp(&a, "true", 4) || v5 != 4 && (v8 > 0x20u || !_bittest64(&v4, (char)v8)) )
  {
    if ( v5 < 5 || hkString::strNcmp(&a, "false", 4) || v5 != 5 && (v9 > 0x20u || !_bittest64(&v4, (char)v9)) )
    {
      if ( !v5 )
        ((void (__fastcall *)(hkStreamReader *, signed __int64))v2->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
          v2->m_streamReader.m_pntr,
          1i64);
      v3->m_bool = 0;
    }
    else
    {
      v3->m_bool = 0;
      ((void (__fastcall *)(hkStreamReader *, signed __int64))v2->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
        v2->m_streamReader.m_pntr,
        5i64);
    }
  }
  else
  {
    v3->m_bool = 1;
    ((void (__fastcall *)(hkStreamReader *, signed __int64))v2->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
      v2->m_streamReader.m_pntr,
      4i64);
  }
  return v2;
}

// File Line: 259
// RVA: 0x12FFB60
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, char *c)
{
  hkIstream *v2; // rbx

  v2 = this;
  ((void (__fastcall *)(hkStreamReader *, char *, signed __int64))this->m_streamReader.m_pntr->vfptr[2].__vecDelDtor)(
    this->m_streamReader.m_pntr,
    c,
    1i64);
  return v2;
}

// File Line: 281
// RVA: 0x12FFB90
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, __int16 *s)
{
  hkIstream *v2; // rbx
  __int16 *v3; // rdi
  __int16 v4; // ax
  hkBool negOut; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = s;
  v4 = readInteger64(this->m_streamReader.m_pntr, &negOut);
  if ( negOut.m_bool )
    v4 = -v4;
  *v3 = v4;
  return v2;
}

// File Line: 287
// RVA: 0x12FFBD0
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, unsigned __int16 *s)
{
  hkIstream *v2; // rbx
  unsigned __int16 *v3; // rdi
  unsigned __int16 v4; // ax
  hkBool negOut; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = s;
  v4 = readInteger64(this->m_streamReader.m_pntr, &negOut);
  if ( negOut.m_bool )
    v4 = -v4;
  *v3 = v4;
  return v2;
}

// File Line: 294
// RVA: 0x12FFC10
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, int *i)
{
  hkIstream *v2; // rbx
  int *v3; // rdi
  int v4; // eax
  hkBool negOut; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = i;
  v4 = readInteger64(this->m_streamReader.m_pntr, &negOut);
  if ( negOut.m_bool )
    v4 = -v4;
  *v3 = v4;
  return v2;
}

// File Line: 300
// RVA: 0x12FFC50
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, unsigned int *i)
{
  hkIstream *v2; // rbx
  unsigned int *v3; // rdi
  int v4; // eax
  hkBool negOut; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = i;
  v4 = readInteger64(this->m_streamReader.m_pntr, &negOut);
  if ( negOut.m_bool )
    v4 = -v4;
  *v3 = v4;
  return v2;
}

// File Line: 306
// RVA: 0x12FFC90
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, float *f)
{
  hkIstream *v2; // rdi
  float *v3; // rbx
  float v4; // xmm0_4
  hkIstream *result; // rax

  v2 = this;
  v3 = f;
  v4 = readFloat(this->m_streamReader.m_pntr);
  result = v2;
  *v3 = v4;
  return result;
}

// File Line: 312
// RVA: 0x12FFCD0
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, long double *d)
{
  hkIstream *v2; // rdi
  long double *v3; // rbx
  float v4; // xmm0_4
  hkIstream *result; // rax

  v2 = this;
  v3 = d;
  v4 = readFloat(this->m_streamReader.m_pntr);
  result = v2;
  *v3 = v4;
  return result;
}

// File Line: 320
// RVA: 0x12FFD10
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, __int64 *i)
{
  hkIstream *v2; // rbx
  __int64 *v3; // rdi
  unsigned __int64 v4; // rax
  hkBool negOut; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = i;
  v4 = readInteger64(this->m_streamReader.m_pntr, &negOut);
  if ( negOut.m_bool )
    v4 = -(signed __int64)v4;
  *v3 = v4;
  return v2;
}

// File Line: 326
// RVA: 0x12FFD50
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, unsigned __int64 *i)
{
  hkIstream *v2; // rbx
  unsigned __int64 *v3; // rdi
  unsigned __int64 v4; // rax
  hkBool negOut; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = i;
  v4 = readInteger64(this->m_streamReader.m_pntr, &negOut);
  if ( negOut.m_bool )
    v4 = -(signed __int64)v4;
  *v3 = v4;
  return v2;
}

// File Line: 332
// RVA: 0x12FFD90
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, hkStringBuf *str)
{
  hkIstream *v2; // rbp
  hkStringBuf *v3; // rbx
  hkStringBuf *v4; // rdi
  int v5; // esi
  signed __int64 v6; // r14
  unsigned int v7; // ebx
  signed __int64 v8; // rcx
  char v9; // al
  char a[64]; // [rsp+20h] [rbp-48h]

  v2 = this;
  v3 = str;
  hkStringBuf::clear(str);
  v4 = hkStringBuf::getArray(v3);
  eatWhiteSpace(v2->m_streamReader.m_pntr);
  v5 = ((__int64 (__fastcall *)(hkStreamReader *, char *, signed __int64))v2->m_streamReader.m_pntr->vfptr[3].__vecDelDtor)(
         v2->m_streamReader.m_pntr,
         a,
         64i64);
  if ( v5 )
  {
    v6 = 4294977024i64;
    while ( 1 )
    {
      v7 = 0;
      v8 = 0i64;
      if ( v5 > 0 )
        break;
LABEL_7:
      ((void (__fastcall *)(hkStreamReader *, _QWORD))v2->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
        v2->m_streamReader.m_pntr,
        (unsigned int)v5);
      hkArrayBase<char>::_append(
        (hkArrayBase<char> *)&v4->m_string.m_data,
        (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
        a,
        v5);
      v5 = ((__int64 (__fastcall *)(hkStreamReader *, char *, signed __int64))v2->m_streamReader.m_pntr->vfptr[3].__vecDelDtor)(
             v2->m_streamReader.m_pntr,
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
    ((void (__fastcall *)(hkStreamReader *, _QWORD))v2->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
      v2->m_streamReader.m_pntr,
      v7);
    hkArrayBase<char>::_append(
      (hkArrayBase<char> *)&v4->m_string.m_data,
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr,
      a,
      v7);
  }
  else
  {
LABEL_8:
    if ( !v4->m_string.m_size )
      ((void (__fastcall *)(hkStreamReader *, signed __int64))v2->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
        v2->m_streamReader.m_pntr,
        1i64);
  }
  if ( v4->m_string.m_size == (v4->m_string.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc.vfptr, v4, 1);
  v4->m_string.m_data[v4->m_string.m_size++] = 0;
  return v2;
}

// File Line: 370
// RVA: 0x12FFEF0
hkIstream *__fastcall hkIstream::operator>>(hkIstream *this, hkStringPtr *str)
{
  hkStringPtr *v2; // rbx
  hkIstream *v3; // rdi
  hkStringBuf stra; // [rsp+20h] [rbp-98h]

  v2 = str;
  v3 = this;
  stra.m_string.m_capacityAndFlags = -2147483520;
  stra.m_string.m_size = 1;
  stra.m_string.m_data = stra.m_string.m_storage;
  stra.m_string.m_storage[0] = 0;
  hkIstream::operator>>(this, &stra);
  hkStringPtr::operator=(v2, stra.m_string.m_data);
  stra.m_string.m_size = 0;
  if ( stra.m_string.m_capacityAndFlags >= 0 )
    hkContainerTempAllocator::s_alloc.vfptr->bufFree(
      (hkMemoryAllocator *)&hkContainerTempAllocator::s_alloc,
      stra.m_string.m_data,
      stra.m_string.m_capacityAndFlags & 0x3FFFFFFF);
  return v3;
}

// File Line: 378
// RVA: 0x12FFF90
signed __int64 __fastcall hkIstream::getline(hkIstream *this, char *str, int maxlen, char delim)
{
  hkIstream *v4; // rbp
  char v5; // r15
  int v6; // er12
  char *v7; // rdi
  signed int v8; // eax
  unsigned int v9; // ebx
  __int64 v10; // rsi
  signed __int64 v11; // rdx
  bool v12; // zf

  v4 = this;
  v5 = delim;
  v6 = maxlen;
  v7 = str;
  eatWhiteSpace(this->m_streamReader.m_pntr);
  v8 = ((__int64 (__fastcall *)(hkStreamReader *, char *, _QWORD))v4->m_streamReader.m_pntr->vfptr[3].__vecDelDtor)(
         v4->m_streamReader.m_pntr,
         v7,
         (unsigned int)v6);
  v9 = 0;
  v10 = v8;
  v11 = 0i64;
  v12 = v8 == 0;
  if ( v8 > 0 )
  {
    do
    {
      if ( v7[v11] == v5 )
      {
        v7[v9] = 0;
        ((void (__fastcall *)(hkStreamReader *, _QWORD))v4->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
          v4->m_streamReader.m_pntr,
          v9 + 1);
        return v9;
      }
      ++v11;
      ++v9;
    }
    while ( v11 < v8 );
    v12 = v8 == 0;
    if ( v8 <= 0 )
      goto LABEL_9;
    if ( (signed int)v10 < v6 )
    {
      ((void (__fastcall *)(hkStreamReader *, _QWORD))v4->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
        v4->m_streamReader.m_pntr,
        (unsigned int)v8);
      v7[v10] = 0;
      return (unsigned int)v10;
    }
    v12 = v8 == 0;
  }
LABEL_9:
  if ( v12 && v6 > 0 )
    ((void (__fastcall *)(hkStreamReader *, signed __int64))v4->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
      v4->m_streamReader.m_pntr,
      1i64);
  ((void (__fastcall *)(hkStreamReader *, _QWORD))v4->m_streamReader.m_pntr->vfptr[2].__first_virtual_table_function__)(
    v4->m_streamReader.m_pntr,
    (unsigned int)v10);
  if ( v6 )
    *v7 = 0;
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
  hkStreamReader *v2; // rbx
  hkIstream *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = newReader;
  v3 = this;
  if ( newReader )
    hkReferencedObject::addReference((hkReferencedObject *)&newReader->vfptr);
  v4 = (hkReferencedObject *)&v3->m_streamReader.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_streamReader.m_pntr = v2;
}

