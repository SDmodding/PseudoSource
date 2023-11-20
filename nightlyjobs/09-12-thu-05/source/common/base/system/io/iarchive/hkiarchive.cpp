// File Line: 16
// RVA: 0x1300530
void __fastcall hkIArchive::hkIArchive(hkIArchive *this, hkStreamReader *sb, hkBool bs)
{
  hkStreamReader *v3; // rdi
  hkIArchive *v4; // rbx
  char v5; // [rsp+40h] [rbp+18h]

  v5 = bs.m_bool;
  v3 = sb;
  v4 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkIArchive::`vftable';
  if ( sb )
  {
    hkReferencedObject::addReference((hkReferencedObject *)&sb->vfptr);
    bs.m_bool = v5;
  }
  v4->m_streamReader.m_pntr = v3;
  v4->m_byteSwap = bs;
}

// File Line: 21
// RVA: 0x1300590
void __fastcall hkIArchive::hkIArchive(hkIArchive *this, const char *filename, hkBool bs)
{
  hkIArchive *v3; // rdi
  hkStreamReader **v4; // rax
  hkReferencedObject *v5; // rcx
  hkStreamReader *v6; // rbx
  char v7; // [rsp+30h] [rbp+8h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v3 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkIArchive::`vftable';
  this->m_streamReader.m_pntr = 0i64;
  this->m_byteSwap = bs;
  v4 = (hkStreamReader **)((__int64 (__fastcall *)(hkFileSystem *, char *, const char *, signed __int64))hkSingleton<hkFileSystem>::s_instance->vfptr[1].__first_virtual_table_function__)(
                            hkSingleton<hkFileSystem>::s_instance,
                            &v7,
                            filename,
                            1i64);
  v5 = (hkReferencedObject *)&v3->m_streamReader.m_pntr->vfptr;
  v6 = *v4;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v3->m_streamReader.m_pntr = v6;
}

// File Line: 27
// RVA: 0x1300600
void __fastcall hkIArchive::hkIArchive(hkIArchive *this, const void *mem, int memSize, hkBool byteswap)
{
  hkIArchive *v4; // rbx
  hkStreamReader *v5; // rdi
  int v6; // esi
  const void *v7; // rbp
  _QWORD **v8; // rax
  hkMemoryStreamReader *v9; // rax
  hkStreamReader *v10; // rax
  hkReferencedObject *v11; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v4 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkIArchive::`vftable';
  v5 = 0i64;
  v6 = memSize;
  this->m_streamReader.m_pntr = 0i64;
  this->m_byteSwap = byteswap;
  v7 = mem;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkMemoryStreamReader *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 40i64);
  if ( v9 )
  {
    hkMemoryStreamReader::hkMemoryStreamReader(v9, v7, v6, MEMORY_INPLACE);
    v5 = v10;
  }
  v11 = (hkReferencedObject *)&v4->m_streamReader.m_pntr->vfptr;
  if ( v11 && v11 != (hkReferencedObject *)v5 )
    hkReferencedObject::removeReference(v11);
  v4->m_streamReader.m_pntr = v5;
}

// File Line: 32
// RVA: 0x13006A0
void __fastcall hkIArchive::~hkIArchive(hkIArchive *this)
{
  hkIArchive *v1; // rbx
  hkStreamReader *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkIArchive::`vftable';
  v2 = this->m_streamReader.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_streamReader.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable';
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
  long double *v3; // rsi
  hkIArchive *v4; // rbp
  __int64 v5; // rbx
  __int64 v6; // rdi
  float array; // [rsp+40h] [rbp+18h]

  if ( nelem > 0 )
  {
    v3 = buf;
    v4 = this;
    v5 = 0i64;
    v6 = nelem;
    do
    {
      hkIArchive::readArrayGeneric(v4, &array, 4, 1);
      v3[++v5 - 1] = array;
    }
    while ( v5 < v6 );
  }
}

// File Line: 53
// RVA: 0x1300760
void __fastcall hkIArchive::readArrayGeneric(hkIArchive *this, void *array, int elemsize, int arraySize)
{
  hkIArchive *v4; // rbx
  int v5; // ebp
  __int64 v6; // rsi
  char *v7; // rdi
  signed __int64 v8; // rdi
  __int64 v9; // rdx
  char v10; // al
  char v11; // cl
  char v12; // cl
  char v13; // cl
  char v14; // cl
  signed __int64 v15; // rax
  __int64 v16; // r8
  char v17; // cl
  char v18; // dl
  char v19; // dl
  __int64 v20; // rdx
  char v21; // al
  char v22; // cl

  v4 = this;
  v5 = elemsize;
  v6 = (unsigned int)arraySize;
  v7 = (char *)array;
  ((void (__fastcall *)(hkStreamReader *, void *, _QWORD))this->m_streamReader.m_pntr->vfptr[2].__vecDelDtor)(
    this->m_streamReader.m_pntr,
    array,
    (unsigned int)(arraySize * elemsize));
  if ( v4->m_byteSwap.m_bool )
  {
    if ( v5 == 2 )
    {
      if ( (signed int)v6 > 0 )
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
    else if ( v5 == 4 )
    {
      if ( (signed int)v6 > 0 )
      {
        v15 = (signed __int64)(v7 + 2);
        v16 = v6;
        do
        {
          v17 = *(_BYTE *)(v15 + 1);
          v18 = *(_BYTE *)(v15 - 2);
          v15 += 4i64;
          *(_BYTE *)(v15 - 6) = v17;
          *(_BYTE *)(v15 - 3) = v18;
          v19 = *(_BYTE *)(v15 - 5);
          *(_BYTE *)(v15 - 5) = *(_BYTE *)(v15 - 4);
          *(_BYTE *)(v15 - 4) = v19;
          --v16;
        }
        while ( v16 );
      }
    }
    else if ( v5 == 8 && (signed int)v6 > 0 )
    {
      v8 = (signed __int64)(v7 + 6);
      v9 = (unsigned int)v6;
      do
      {
        v10 = *(_BYTE *)(v8 + 1);
        v11 = *(_BYTE *)(v8 - 6);
        v8 += 8i64;
        *(_BYTE *)(v8 - 14) = v10;
        *(_BYTE *)(v8 - 7) = v11;
        v12 = *(_BYTE *)(v8 - 13);
        *(_BYTE *)(v8 - 13) = *(_BYTE *)(v8 - 8);
        *(_BYTE *)(v8 - 8) = v12;
        v13 = *(_BYTE *)(v8 - 12);
        *(_BYTE *)(v8 - 12) = *(_BYTE *)(v8 - 9);
        *(_BYTE *)(v8 - 9) = v13;
        v14 = *(_BYTE *)(v8 - 11);
        *(_BYTE *)(v8 - 11) = *(_BYTE *)(v8 - 10);
        *(_BYTE *)(v8 - 10) = v14;
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
  hkStreamReader *v2; // rcx
  hkBool *v3; // rbx
  hkBool *v4; // rax
  char v5; // [rsp+30h] [rbp+8h]

  v2 = this->m_streamReader.m_pntr;
  v3 = result;
  if ( v2
    && *(_BYTE *)((__int64 (__fastcall *)(hkStreamReader *, char *))v2->vfptr[1].__first_virtual_table_function__)(
                   v2,
                   &v5) )
  {
    v3->m_bool = 1;
    v4 = v3;
  }
  else
  {
    v3->m_bool = 0;
    v4 = v3;
  }
  return v4;
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
  hkStreamReader *v2; // rbx
  hkIArchive *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = newBuf;
  v3 = this;
  if ( newBuf )
    hkReferencedObject::addReference((hkReferencedObject *)&newBuf->vfptr);
  v4 = (hkReferencedObject *)&v3->m_streamReader.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_streamReader.m_pntr = v2;
}

