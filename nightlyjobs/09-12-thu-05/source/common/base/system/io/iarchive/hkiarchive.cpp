// File Line: 16
// RVA: 0x1300530
void __fastcall hkIArchive::hkIArchive(hkIArchive *this, hkStreamReader *sb, hkBool bs)
{
  char m_bool; // [rsp+40h] [rbp+18h]

  m_bool = bs.m_bool;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkIArchive::`vftable;
  if ( sb )
  {
    hkReferencedObject::addReference(sb);
    bs.m_bool = m_bool;
  }
  this->m_streamReader.m_pntr = sb;
  this->m_byteSwap = bs;
}

// File Line: 21
// RVA: 0x1300590
void __fastcall hkIArchive::hkIArchive(hkIArchive *this, const char *filename, hkBool bs)
{
  hkStreamReader **v4; // rax
  hkStreamReader *m_pntr; // rcx
  hkStreamReader *v6; // rbx
  char v7; // [rsp+30h] [rbp+8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkIArchive::`vftable;
  this->m_streamReader.m_pntr = 0i64;
  this->m_byteSwap = bs;
  v4 = (hkStreamReader **)((__int64 (__fastcall *)(hkFileSystem *, char *, const char *, __int64))hkSingleton<hkFileSystem>::s_instance->vfptr[1].__first_virtual_table_function__)(
                            hkSingleton<hkFileSystem>::s_instance,
                            &v7,
                            filename,
                            1i64);
  m_pntr = this->m_streamReader.m_pntr;
  v6 = *v4;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_streamReader.m_pntr = v6;
}

// File Line: 27
// RVA: 0x1300600
void __fastcall hkIArchive::hkIArchive(hkIArchive *this, const void *mem, int memSize, hkBool byteswap)
{
  hkStreamReader *v5; // rdi
  _QWORD **Value; // rax
  hkMemoryStreamReader *v9; // rax
  hkStreamReader *v10; // rax
  hkStreamReader *m_pntr; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkIArchive::`vftable;
  v5 = 0i64;
  this->m_streamReader.m_pntr = 0i64;
  this->m_byteSwap = byteswap;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkMemoryStreamReader *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v9 )
  {
    hkMemoryStreamReader::hkMemoryStreamReader(v9, mem, memSize, MEMORY_INPLACE);
    v5 = v10;
  }
  m_pntr = this->m_streamReader.m_pntr;
  if ( m_pntr && m_pntr != v5 )
    hkReferencedObject::removeReference(m_pntr);
  this->m_streamReader.m_pntr = v5;
}

// File Line: 32
// RVA: 0x13006A0
void __fastcall hkIArchive::~hkIArchive(hkIArchive *this)
{
  hkStreamReader *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkIArchive::`vftable;
  m_pntr = this->m_streamReader.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_streamReader.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 36
// RVA: 0x1300930
void __fastcall byteswap(char *a, char *b)
{
  char v2; // r8

  v2 = *a;
  *a = *b;
  *b = v2;
}

// File Line: 43
// RVA: 0x13006E0
void __fastcall hkIArchive::readArrayFloat32(hkIArchive *this, long double *buf, int nelem)
{
  __int64 v5; // rbx
  __int64 v6; // rdi
  float array; // [rsp+40h] [rbp+18h] BYREF

  if ( nelem > 0 )
  {
    v5 = 0i64;
    v6 = nelem;
    do
    {
      hkIArchive::readArrayGeneric(this, &array, 4, 1);
      buf[v5++] = array;
    }
    while ( v5 < v6 );
  }
}

// File Line: 53
// RVA: 0x1300760
void __fastcall hkIArchive::readArrayGeneric(hkIArchive *this, char *array, int elemsize, unsigned int arraySize)
{
  __int64 v6; // rsi
  char *v7; // rdi
  _BYTE *v8; // rdi
  __int64 v9; // rdx
  char v10; // al
  char v11; // cl
  char v12; // cl
  char v13; // cl
  char v14; // cl
  _BYTE *v15; // rax
  __int64 v16; // r8
  char v17; // cl
  char v18; // dl
  char v19; // dl
  __int64 v20; // rdx
  char v21; // al
  char v22; // cl

  v6 = arraySize;
  v7 = array;
  ((void (__fastcall *)(hkStreamReader *, char *, _QWORD))this->m_streamReader.m_pntr->vfptr[2].__vecDelDtor)(
    this->m_streamReader.m_pntr,
    array,
    arraySize * elemsize);
  if ( this->m_byteSwap.m_bool )
  {
    if ( elemsize == 2 )
    {
      if ( (int)v6 > 0 )
      {
        v20 = v6;
        do
        {
          v21 = v7[1];
          v22 = *v7;
          v7 += 2;
          *(v7 - 2) = v21;
          *(v7 - 1) = v22;
          --v20;
        }
        while ( v20 );
      }
    }
    else if ( elemsize == 4 )
    {
      if ( (int)v6 > 0 )
      {
        v15 = v7 + 2;
        v16 = v6;
        do
        {
          v17 = v15[1];
          v18 = *(v15 - 2);
          v15 += 4;
          *(v15 - 6) = v17;
          *(v15 - 3) = v18;
          v19 = *(v15 - 5);
          *(v15 - 5) = *(v15 - 4);
          *(v15 - 4) = v19;
          --v16;
        }
        while ( v16 );
      }
    }
    else if ( elemsize == 8 && (int)v6 > 0 )
    {
      v8 = v7 + 6;
      v9 = (unsigned int)v6;
      do
      {
        v10 = v8[1];
        v11 = *(v8 - 6);
        v8 += 8;
        *(v8 - 14) = v10;
        *(v8 - 7) = v11;
        v12 = *(v8 - 13);
        *(v8 - 13) = *(v8 - 8);
        *(v8 - 8) = v12;
        v13 = *(v8 - 12);
        *(v8 - 12) = *(v8 - 9);
        *(v8 - 9) = v13;
        v14 = *(v8 - 11);
        *(v8 - 11) = *(v8 - 10);
        *(v8 - 10) = v14;
        --v9;
      }
      while ( v9 );
    }
  }
}

// File Line: 119
// RVA: 0x1300880
__int64 __fastcall hkIArchive::readRaw(hkIArchive *this, void *buf, __int64 nbytes)
{
  return ((__int64 (__fastcall *)(hkStreamReader *, void *, __int64))this->m_streamReader.m_pntr->vfptr[2].__vecDelDtor)(
           this->m_streamReader.m_pntr,
           buf,
           nbytes);
}

// File Line: 124
// RVA: 0x13008A0
hkBool *__fastcall hkIArchive::isOk(hkIArchive *this, hkBool *result)
{
  hkStreamReader *m_pntr; // rcx
  char v5; // [rsp+30h] [rbp+8h] BYREF

  m_pntr = this->m_streamReader.m_pntr;
  if ( m_pntr
    && *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, char *))m_pntr->vfptr[1].__first_virtual_table_function__)(
                   m_pntr,
                   &v5) )
  {
    result->m_bool = 1;
    return result;
  }
  else
  {
    result->m_bool = 0;
    return result;
  }
}

// File Line: 129
// RVA: 0x13008E0
hkStreamReader *__fastcall hkIArchive::getStreamReader(hkIArchive *this)
{
  return this->m_streamReader.m_pntr;
}

// File Line: 134
// RVA: 0x13008F0
void __fastcall hkIArchive::setStreamReader(hkIArchive *this, hkStreamReader *newBuf)
{
  hkStreamReader *m_pntr; // rcx

  if ( newBuf )
    hkReferencedObject::addReference(newBuf);
  m_pntr = this->m_streamReader.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_streamReader.m_pntr = newBuf;
}

