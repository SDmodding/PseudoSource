// File Line: 18
// RVA: 0xC73860
void __fastcall hkOArchive::hkOArchive(hkOArchive *this, hkStreamWriter *sw, hkBool bs)
{
  hkStreamWriter *v3; // rdi
  hkOArchive *v4; // rbx
  char v5; // [rsp+40h] [rbp+18h]

  v5 = bs.m_bool;
  v3 = sw;
  v4 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkOArchive::`vftable;
  if ( sw )
  {
    hkReferencedObject::addReference((hkReferencedObject *)&sw->vfptr);
    bs.m_bool = v5;
  }
  v4->m_writer.m_pntr = v3;
  v4->m_byteSwap = bs;
}

// File Line: 23
// RVA: 0xC738C0
void __fastcall hkOArchive::hkOArchive(hkOArchive *this, const char *filename, hkBool bs)
{
  hkOArchive *v3; // rdi
  hkStreamWriter **v4; // rax
  hkReferencedObject *v5; // rcx
  hkStreamWriter *v6; // rbx
  char v7; // [rsp+30h] [rbp+8h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v3 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkOArchive::`vftable;
  this->m_writer.m_pntr = 0i64;
  this->m_byteSwap = bs;
  v4 = (hkStreamWriter **)((__int64 (__fastcall *)(hkFileSystem *, char *, const char *, signed __int64))hkSingleton<hkFileSystem>::s_instance->vfptr[2].__vecDelDtor)(
                            hkSingleton<hkFileSystem>::s_instance,
                            &v7,
                            filename,
                            3i64);
  v5 = (hkReferencedObject *)&v3->m_writer.m_pntr->vfptr;
  v6 = *v4;
  if ( v5 )
    hkReferencedObject::removeReference(v5);
  v3->m_writer.m_pntr = v6;
}

// File Line: 29
// RVA: 0xC73930
void __fastcall hkOArchive::hkOArchive(hkOArchive *this, void *mem, int memSize, hkBool bs)
{
  hkOArchive *v4; // rbx
  hkStreamWriter *v5; // rdi
  int v6; // esi
  void *v7; // rbp
  _QWORD **v8; // rax
  hkBufferedStreamWriter *v9; // rax
  hkStreamWriter *v10; // rax
  hkReferencedObject *v11; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v4 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkOArchive::`vftable;
  v5 = 0i64;
  v6 = memSize;
  this->m_writer.m_pntr = 0i64;
  this->m_byteSwap = bs;
  v7 = mem;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkBufferedStreamWriter *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 48i64);
  if ( v9 )
  {
    hkBufferedStreamWriter::hkBufferedStreamWriter(v9, v7, v6, 0);
    v5 = v10;
  }
  v11 = (hkReferencedObject *)&v4->m_writer.m_pntr->vfptr;
  if ( v11 && v11 != (hkReferencedObject *)v5 )
    hkReferencedObject::removeReference(v11);
  v4->m_writer.m_pntr = v5;
}

// File Line: 35
// RVA: 0xC739D0
void __fastcall hkOArchive::hkOArchive(hkOArchive *this, hkArray<char,hkContainerHeapAllocator> *arr, hkBool bs)
{
  hkOArchive *v3; // rbx
  hkStreamWriter *v4; // rdi
  hkArray<char,hkContainerHeapAllocator> *v5; // rsi
  _QWORD **v6; // rax
  hkArrayStreamWriter *v7; // rax
  hkStreamWriter *v8; // rax
  hkReferencedObject *v9; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v3 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkOArchive::`vftable;
  v4 = 0i64;
  v5 = arr;
  this->m_writer.m_pntr = 0i64;
  this->m_byteSwap = bs;
  v6 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v7 = (hkArrayStreamWriter *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v6[11] + 8i64))(v6[11], 40i64);
  if ( v7 )
  {
    hkArrayStreamWriter::hkArrayStreamWriter(v7, v5, ARRAY_BORROW);
    v4 = v8;
  }
  v9 = (hkReferencedObject *)&v3->m_writer.m_pntr->vfptr;
  if ( v9 && v9 != (hkReferencedObject *)v4 )
    hkReferencedObject::removeReference(v9);
  v3->m_writer.m_pntr = v4;
}

// File Line: 40
// RVA: 0xC73A70
void __fastcall hkOArchive::~hkOArchive(hkOArchive *this)
{
  hkOArchive *v1; // rbx
  hkStreamWriter *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkOArchive::`vftable;
  v2 = this->m_writer.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_writer.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 48
// RVA: 0xC73AB0
void __fastcall hkOArchive::write8(hkOArchive *this, char c)
{
  char v2; // [rsp+38h] [rbp+10h]

  v2 = c;
  ((void (__fastcall *)(hkStreamWriter *, char *, signed __int64))this->m_writer.m_pntr->vfptr[2].__vecDelDtor)(
    this->m_writer.m_pntr,
    &v2,
    1i64);
}

// File Line: 53
// RVA: 0xC73AE0
void __fastcall hkOArchive::write8u(hkOArchive *this, char u)
{
  char v2; // [rsp+38h] [rbp+10h]

  v2 = u;
  ((void (__fastcall *)(hkStreamWriter *, char *, signed __int64))this->m_writer.m_pntr->vfptr[2].__vecDelDtor)(
    this->m_writer.m_pntr,
    &v2,
    1i64);
}

// File Line: 58
// RVA: 0xC73B10
void __fastcall hkOArchive::write16(hkOArchive *this, __int16 i)
{
  __int16 ptr; // [rsp+38h] [rbp+10h]

  ptr = i;
  hkOArchive::writeArrayGeneric(this, &ptr, 2, 1);
}

// File Line: 63
// RVA: 0xC73B40
void __fastcall hkOArchive::write16u(hkOArchive *this, unsigned __int16 u)
{
  unsigned __int16 ptr; // [rsp+38h] [rbp+10h]

  ptr = u;
  hkOArchive::writeArrayGeneric(this, &ptr, 2, 1);
}

// File Line: 68
// RVA: 0xC73B70
void __fastcall hkOArchive::write32(hkOArchive *this, int i)
{
  int ptr; // [rsp+38h] [rbp+10h]

  ptr = i;
  hkOArchive::writeArrayGeneric(this, &ptr, 4, 1);
}

// File Line: 73
// RVA: 0xC73BA0
void __fastcall hkOArchive::write32u(hkOArchive *this, unsigned int u)
{
  unsigned int ptr; // [rsp+38h] [rbp+10h]

  ptr = u;
  hkOArchive::writeArrayGeneric(this, &ptr, 4, 1);
}

// File Line: 78
// RVA: 0xC73BD0
void __fastcall hkOArchive::write64(hkOArchive *this, __int64 i)
{
  __int64 ptr; // [rsp+38h] [rbp+10h]

  ptr = i;
  hkOArchive::writeArrayGeneric(this, &ptr, 8, 1);
}

// File Line: 83
// RVA: 0xC73C00
void __fastcall hkOArchive::write64u(hkOArchive *this, unsigned __int64 u)
{
  unsigned __int64 ptr; // [rsp+38h] [rbp+10h]

  ptr = u;
  hkOArchive::writeArrayGeneric(this, &ptr, 8, 1);
}

// File Line: 88
// RVA: 0xC73C30
void __fastcall hkOArchive::writeFloat32(hkOArchive *this, float f)
{
  float ptr; // [rsp+38h] [rbp+10h]

  ptr = f;
  hkOArchive::writeArrayGeneric(this, &ptr, 4, 1);
}

// File Line: 93
// RVA: 0xC73C60
void __fastcall hkOArchive::writeDouble64(hkOArchive *this, long double d)
{
  long double ptr; // [rsp+38h] [rbp+10h]

  ptr = d;
  hkOArchive::writeArrayGeneric(this, &ptr, 8, 1);
}

// File Line: 102
// RVA: 0xC73C90
void __fastcall hkOArchive::writeArray8(hkOArchive *this, const char *array, int nelem)
{
  hkOArchive::writeArrayGeneric(this, array, 1, nelem);
}

// File Line: 107
// RVA: 0xC73CB0
void __fastcall hkOArchive::writeArray8u(hkOArchive *this, const char *array, int nelem)
{
  hkOArchive::writeArrayGeneric(this, array, 1, nelem);
}

// File Line: 112
// RVA: 0xC73CD0
void __fastcall hkOArchive::writeArray16(hkOArchive *this, const __int16 *array, int nelem)
{
  hkOArchive::writeArrayGeneric(this, array, 2, nelem);
}

// File Line: 117
// RVA: 0xC73CF0
void __fastcall hkOArchive::writeArray16u(hkOArchive *this, const unsigned __int16 *array, int nelem)
{
  hkOArchive::writeArrayGeneric(this, array, 2, nelem);
}

// File Line: 122
// RVA: 0xC73D10
void __fastcall hkOArchive::writeArray32(hkOArchive *this, const int *array, int nelem)
{
  hkOArchive::writeArrayGeneric(this, array, 4, nelem);
}

// File Line: 127
// RVA: 0xC73D30
void __fastcall hkOArchive::writeArray32u(hkOArchive *this, const unsigned int *array, int nelem)
{
  hkOArchive::writeArrayGeneric(this, array, 4, nelem);
}

// File Line: 132
// RVA: 0xC73D50
void __fastcall hkOArchive::writeArray64(hkOArchive *this, const __int64 *array, int nelem)
{
  hkOArchive::writeArrayGeneric(this, array, 8, nelem);
}

// File Line: 137
// RVA: 0xC73D70
void __fastcall hkOArchive::writeArray64u(hkOArchive *this, const unsigned __int64 *array, int nelem)
{
  hkOArchive::writeArrayGeneric(this, array, 8, nelem);
}

// File Line: 142
// RVA: 0xC73D90
void __fastcall hkOArchive::writeArrayFloat32(hkOArchive *this, const float *array, int nelem)
{
  hkOArchive::writeArrayGeneric(this, array, 4, nelem);
}

// File Line: 147
// RVA: 0xC73DB0
void __fastcall hkOArchive::writeArrayFloat32(hkOArchive *this, const long double *array, int nelem)
{
  const long double *v3; // rsi
  hkOArchive *v4; // rbp
  __int64 v5; // rbx
  __int64 v6; // rdi

  if ( nelem > 0 )
  {
    v3 = array;
    v4 = this;
    v5 = 0i64;
    v6 = nelem;
    do
      hkOArchive::writeFloat32(v4, v3[v5++]);
    while ( v5 < v6 );
  }
}

// File Line: 156
// RVA: 0xC73E10
void __fastcall hkOArchive::writeArrayDouble64(hkOArchive *this, const long double *array, int nelem)
{
  hkOArchive::writeArrayGeneric(this, array, 8, nelem);
}

// File Line: 165
// RVA: 0xC740F0
void __fastcall localbyteswap(char *a, char *b)
{
  char v2; // r8

  v2 = *a;
  *a = *b;
  *b = v2;
}

// File Line: 172
// RVA: 0xC73E30
void __fastcall hkOArchive::writeArrayGeneric(hkOArchive *this, const void *ptr, int elemSize, int arraySize)
{
  int v4; // edi
  char *v5; // r15
  hkOArchive *v6; // r13
  int v7; // esi
  int v8; // ebp
  int v9; // ebx
  int i; // er14
  char *v11; // rdx
  __int64 v12; // r8
  char v13; // al
  char v14; // cl
  char v15; // cl
  char v16; // cl
  char v17; // cl
  char *v18; // rax
  __int64 v19; // r8
  char v20; // cl
  char v21; // dl
  char v22; // dl
  char *v23; // rdx
  __int64 v24; // r8
  char v25; // al
  char v26; // cl
  char dst; // [rsp+20h] [rbp-228h]
  char v28; // [rsp+22h] [rbp-226h]
  char v29; // [rsp+26h] [rbp-222h]

  v4 = elemSize;
  v5 = (char *)ptr;
  v6 = this;
  if ( this->m_byteSwap.m_bool )
  {
    v7 = 512;
    v8 = arraySize * elemSize;
    v9 = 512 / elemSize;
    for ( i = arraySize * elemSize % 512; v8 > 0; v5 += v7 )
    {
      if ( v8 < 512 )
      {
        v7 = i;
        v9 = i / v4;
      }
      hkString::memCpy(&dst, v5, v7);
      if ( v4 == 2 )
      {
        v23 = &dst;
        if ( v9 > 0 )
        {
          v24 = (unsigned int)v9;
          do
          {
            v25 = v23[1];
            v26 = *v23;
            v23 += 2;
            *(v23 - 2) = v25;
            *(v23 - 1) = v26;
            --v24;
          }
          while ( v24 );
        }
      }
      else if ( v4 == 4 )
      {
        if ( v9 > 0 )
        {
          v18 = &v28;
          v19 = (unsigned int)v9;
          do
          {
            v20 = v18[1];
            v21 = *(v18 - 2);
            v18 += 4;
            *(v18 - 6) = v20;
            *(v18 - 3) = v21;
            v22 = *(v18 - 5);
            *(v18 - 5) = *(v18 - 4);
            *(v18 - 4) = v22;
            --v19;
          }
          while ( v19 );
        }
      }
      else if ( v4 == 8 && v9 > 0 )
      {
        v11 = &v29;
        v12 = (unsigned int)v9;
        do
        {
          v13 = v11[1];
          v14 = *(v11 - 6);
          v11 += 8;
          *(v11 - 14) = v13;
          *(v11 - 7) = v14;
          v15 = *(v11 - 13);
          *(v11 - 13) = *(v11 - 8);
          *(v11 - 8) = v15;
          v16 = *(v11 - 12);
          *(v11 - 12) = *(v11 - 9);
          *(v11 - 9) = v16;
          v17 = *(v11 - 11);
          *(v11 - 11) = *(v11 - 10);
          *(v11 - 10) = v17;
          --v12;
        }
        while ( v12 );
      }
      ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD))v6->m_writer.m_pntr->vfptr[2].__vecDelDtor)(
        v6->m_writer.m_pntr,
        &dst,
        (unsigned int)v7);
      v8 -= v7;
    }
  }
  else
  {
    ((void (__fastcall *)(hkStreamWriter *, const void *, _QWORD))this->m_writer.m_pntr->vfptr[2].__vecDelDtor)(
      this->m_writer.m_pntr,
      ptr,
      (unsigned int)(arraySize * elemSize));
  }
}

// File Line: 262
// RVA: 0xC74030
__int64 __fastcall hkOArchive::writeRaw(hkOArchive *this, const void *buf, __int64 nbytes)
{
  return ((__int64 (__fastcall *)(hkStreamWriter *, const void *, __int64))this->m_writer.m_pntr->vfptr[2].__vecDelDtor)(
           this->m_writer.m_pntr,
           buf,
           nbytes);
}

// File Line: 267
// RVA: 0xC74050
void __fastcall hkOArchive::setByteSwap(hkOArchive *this, hkBool on)
{
  this->m_byteSwap = on;
}

// File Line: 272
// RVA: 0xC74060
hkBool *__fastcall hkOArchive::getByteSwap(hkOArchive *this, hkBool *result)
{
  result->m_bool = (char)this->m_byteSwap;
  return result;
}

// File Line: 277
// RVA: 0xC74070
hkBool *__fastcall hkOArchive::isOk(hkOArchive *this, hkBool *result)
{
  hkBool *v2; // rbx

  v2 = result;
  ((void (*)(void))this->m_writer.m_pntr->vfptr[1].__first_virtual_table_function__)();
  return v2;
}

// File Line: 282
// RVA: 0xC740A0
hkStreamWriter *__fastcall hkOArchive::getStreamWriter(hkOArchive *this)
{
  return this->m_writer.m_pntr;
}

// File Line: 287
// RVA: 0xC740B0
void __fastcall hkOArchive::setStreamWriter(hkOArchive *this, hkStreamWriter *newWriter)
{
  hkStreamWriter *v2; // rbx
  hkOArchive *v3; // rdi
  hkReferencedObject *v4; // rcx

  v2 = newWriter;
  v3 = this;
  if ( newWriter )
    hkReferencedObject::addReference((hkReferencedObject *)&newWriter->vfptr);
  v4 = (hkReferencedObject *)&v3->m_writer.m_pntr->vfptr;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v3->m_writer.m_pntr = v2;
}

