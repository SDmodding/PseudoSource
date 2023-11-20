// File Line: 24
// RVA: 0x15C7630
void dynamic_initializer_for__hkOstreamClass__()
{
  hkClass::hkClass(&hkOstreamClass, "hkOstream", 0i64, 24, 0i64, 0, 0i64, 0, 0i64, 0, 0i64, 0i64, 0, 0);
}

// File Line: 28
// RVA: 0xC66BD0
void __fastcall writeString(hkStreamWriter *sb, const char *s)
{
  const char *v2; // rsi
  hkStreamWriter *v3; // rdi
  hkBaseObjectVtbl *v4; // rbx
  unsigned int v5; // eax

  v2 = s;
  v3 = sb;
  if ( s )
  {
    v4 = sb->vfptr;
    v5 = hkString::strLen(s);
    ((void (__fastcall *)(hkStreamWriter *, const char *, _QWORD))v4[2].__vecDelDtor)(v3, v2, v5);
  }
  else
  {
    ((void (__fastcall *)(hkStreamWriter *, const char *, signed __int64))sb->vfptr[2].__vecDelDtor)(sb, "(null)", 6i64);
  }
}

// File Line: 42
// RVA: 0xC65FE0
void __fastcall hkOstream::hkOstream(hkOstream *this, hkStreamWriter *sw)
{
  hkStreamWriter *v2; // rdi
  hkOstream *v3; // rbx

  v2 = sw;
  v3 = this;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkOstream::`vftable;
  if ( sw )
  {
    hkReferencedObject::addReference((hkReferencedObject *)&sw->vfptr);
    v3->m_writer.m_pntr = v2;
  }
  else
  {
    this->m_writer.m_pntr = 0i64;
  }
}

// File Line: 46
// RVA: 0xC66040
void __fastcall hkOstream::hkOstream(hkOstream *this, const char *filename)
{
  hkOstream *v2; // rdi
  hkStreamWriter **v3; // rax
  hkReferencedObject *v4; // rcx
  hkStreamWriter *v5; // rbx
  char v6; // [rsp+30h] [rbp+8h]

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkOstream::`vftable;
  this->m_writer.m_pntr = 0i64;
  v3 = (hkStreamWriter **)((__int64 (__fastcall *)(hkFileSystem *, char *, const char *, signed __int64))hkSingleton<hkFileSystem>::s_instance->vfptr[2].__vecDelDtor)(
                            hkSingleton<hkFileSystem>::s_instance,
                            &v6,
                            filename,
                            3i64);
  v4 = (hkReferencedObject *)&v2->m_writer.m_pntr->vfptr;
  v5 = *v3;
  if ( v4 )
    hkReferencedObject::removeReference(v4);
  v2->m_writer.m_pntr = v5;
}

// File Line: 51
// RVA: 0xC660B0
void __fastcall hkOstream::hkOstream(hkOstream *this, void *mem, int memSize, hkBool isString)
{
  hkOstream *v4; // rbx
  hkStreamWriter *v5; // rdi
  int v6; // esi
  void *v7; // rbp
  _QWORD **v8; // rax
  hkBufferedStreamWriter *v9; // rax
  hkStreamWriter *v10; // rax
  hkReferencedObject *v11; // rcx
  char v12; // [rsp+48h] [rbp+20h]

  v12 = isString.m_bool;
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v4 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkOstream::`vftable;
  v5 = 0i64;
  v6 = memSize;
  this->m_writer.m_pntr = 0i64;
  v7 = mem;
  v8 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkBufferedStreamWriter *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v8[11] + 8i64))(v8[11], 48i64);
  if ( v9 )
  {
    hkBufferedStreamWriter::hkBufferedStreamWriter(v9, v7, v6, (hkBool)v12);
    v5 = v10;
  }
  v11 = (hkReferencedObject *)&v4->m_writer.m_pntr->vfptr;
  if ( v11 && v11 != (hkReferencedObject *)v5 )
    hkReferencedObject::removeReference(v11);
  v4->m_writer.m_pntr = v5;
}

// File Line: 56
// RVA: 0xC66160
void __fastcall hkOstream::hkOstream(hkOstream *this, hkArray<char,hkContainerHeapAllocator> *buf)
{
  hkOstream *v2; // rbx
  hkStreamWriter *v3; // rdi
  hkArray<char,hkContainerHeapAllocator> *v4; // rsi
  _QWORD **v5; // rax
  hkArrayStreamWriter *v6; // rax
  hkStreamWriter *v7; // rax
  hkReferencedObject *v8; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkOstream::`vftable;
  v3 = 0i64;
  v4 = buf;
  this->m_writer.m_pntr = 0i64;
  v5 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkArrayStreamWriter *)(*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v5[11] + 8i64))(v5[11], 40i64);
  if ( v6 )
  {
    hkArrayStreamWriter::hkArrayStreamWriter(v6, v4, ARRAY_BORROW);
    v3 = v7;
  }
  v8 = (hkReferencedObject *)&v2->m_writer.m_pntr->vfptr;
  if ( v8 && v8 != (hkReferencedObject *)v3 )
    hkReferencedObject::removeReference(v8);
  v2->m_writer.m_pntr = v3;
}

// File Line: 61
// RVA: 0xC66200
void __fastcall hkOstream::hkOstream(hkOstream *this, hkMemoryTrack *buf)
{
  hkOstream *v2; // rdi
  hkMemoryTrack *v3; // rsi
  _QWORD **v4; // rax
  __int64 v5; // rax
  hkStreamWriter *v6; // rbx
  hkReferencedObject *v7; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  v2 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkOstream::`vftable;
  this->m_writer.m_pntr = 0i64;
  v3 = buf;
  v4 = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, signed __int64))(*v4[11] + 8i64))(v4[11], 32i64);
  v6 = (hkStreamWriter *)v5;
  if ( v5 )
  {
    *(_DWORD *)(v5 + 8) = 0x1FFFF;
    *(_QWORD *)(v5 + 16) = v3;
    *(_QWORD *)v5 = &hkMemoryTrackStreamWriter::`vftable;
    *(_DWORD *)(v5 + 24) = 1;
  }
  else
  {
    v6 = 0i64;
  }
  v7 = (hkReferencedObject *)&v2->m_writer.m_pntr->vfptr;
  if ( v7 && v7 != (hkReferencedObject *)v6 )
    hkReferencedObject::removeReference(v7);
  v2->m_writer.m_pntr = v6;
}

// File Line: 67
// RVA: 0xC662C0
void __fastcall hkOstream::~hkOstream(hkOstream *this)
{
  hkOstream *v1; // rbx
  hkStreamWriter *v2; // rcx

  v1 = this;
  this->vfptr = (hkBaseObjectVtbl *)&hkOstream::`vftable;
  v2 = this->m_writer.m_pntr;
  if ( v2 )
    hkReferencedObject::removeReference((hkReferencedObject *)&v2->vfptr);
  v1->m_writer.m_pntr = 0i64;
  v1->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 71
// RVA: 0xC66300
hkBool *__fastcall hkOstream::isOk(hkOstream *this, hkBool *result)
{
  hkStreamWriter *v2; // rcx
  hkBool *v3; // rbx
  hkBool *v4; // rax
  char v5; // [rsp+30h] [rbp+8h]

  v2 = this->m_writer.m_pntr;
  v3 = result;
  if ( v2
    && *(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, char *))v2->vfptr[1].__first_virtual_table_function__)(
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

// File Line: 76
// RVA: 0xC66340
hkOstream *__usercall hkOstream::operator<<@<rax>(hkOstream *this@<rcx>, const void *p@<rdx>, int a3@<eax>)
{
  hkOstream *v3; // rbx
  char buf; // [rsp+20h] [rbp-2738h]

  v3 = this;
  hkString::snprintf(&buf, a3 - 40, "%p", p);
  writeString(v3->m_writer.m_pntr, &buf);
  return v3;
}

// File Line: 84
// RVA: 0xC66390
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkBool b)
{
  hkOstream *v2; // rbx
  const char *v3; // rax

  v2 = this;
  v3 = "false";
  if ( b.m_bool )
    v3 = "true";
  writeString(this->m_writer.m_pntr, v3);
  return v2;
}

// File Line: 90
// RVA: 0xC663D0
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, char c)
{
  hkOstream *v2; // rbx
  char v4; // [rsp+38h] [rbp+10h]

  v4 = c;
  v2 = this;
  ((void (__fastcall *)(hkStreamWriter *, char *, signed __int64))this->m_writer.m_pntr->vfptr[2].__vecDelDtor)(
    this->m_writer.m_pntr,
    &v4,
    1i64);
  return v2;
}

// File Line: 96
// RVA: 0xC66400
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, const char *s)
{
  hkOstream *v2; // rbx

  v2 = this;
  writeString(this->m_writer.m_pntr, s);
  return v2;
}

// File Line: 102
// RVA: 0xC66430
hkOstream *__usercall hkOstream::operator<<@<rax>(hkOstream *this@<rcx>, __int16 s@<dx>, int a3@<eax>)
{
  hkOstream *v3; // rbx
  char buf; // [rsp+20h] [rbp-2738h]

  v3 = this;
  hkString::snprintf(&buf, a3 - 40, "%i", (unsigned int)s);
  writeString(v3->m_writer.m_pntr, &buf);
  return v3;
}

// File Line: 110
// RVA: 0xC66480
hkOstream *__usercall hkOstream::operator<<@<rax>(hkOstream *this@<rcx>, unsigned __int16 s@<dx>, int a3@<eax>)
{
  hkOstream *v3; // rbx
  char buf; // [rsp+20h] [rbp-2738h]

  v3 = this;
  hkString::snprintf(&buf, a3 - 40, "%u", s);
  writeString(v3->m_writer.m_pntr, &buf);
  return v3;
}

// File Line: 118
// RVA: 0xC664D0
hkOstream *__usercall hkOstream::operator<<@<rax>(hkOstream *this@<rcx>, int i@<edx>, int a3@<eax>)
{
  hkOstream *v3; // rbx
  char buf; // [rsp+20h] [rbp-2738h]

  v3 = this;
  hkString::snprintf(&buf, a3 - 40, "%i", (unsigned int)i);
  writeString(v3->m_writer.m_pntr, &buf);
  return v3;
}

// File Line: 126
// RVA: 0xC66520
hkOstream *__usercall hkOstream::operator<<@<rax>(hkOstream *this@<rcx>, unsigned int u@<edx>, int a3@<eax>)
{
  hkOstream *v3; // rbx
  char buf; // [rsp+20h] [rbp-2738h]

  v3 = this;
  hkString::snprintf(&buf, a3 - 40, "%u", u);
  writeString(v3->m_writer.m_pntr, &buf);
  return v3;
}

// File Line: 134
// RVA: 0xC665D0
hkOstream *__usercall hkOstream::operator<<@<rax>(hkOstream *this@<rcx>, hkSimdFloat32 *f@<rdx>, int a3@<eax>)
{
  hkOstream *v3; // rbx
  char buf; // [rsp+20h] [rbp-2738h]

  v3 = this;
  hkString::snprintf(&buf, a3 - 40, "%f", f->m_real.m128_f32[0]);
  writeString(v3->m_writer.m_pntr, &buf);
  return v3;
}

// File Line: 142
// RVA: 0xC667A0
hkOstream *__usercall hkOstream::operator<<@<rax>(hkOstream *this@<rcx>, hkSimdDouble64 *f@<rdx>, int a3@<eax>)
{
  hkOstream *v3; // rbx
  char buf; // [rsp+20h] [rbp-2738h]

  v3 = this;
  hkString::snprintf(&buf, a3 - 40, "%f", (unsigned __int64)*(_OWORD *)f);
  writeString(v3->m_writer.m_pntr, &buf);
  return v3;
}

// File Line: 151
// RVA: 0xC66570
hkOstream *__usercall hkOstream::operator<<@<rax>(hkOstream *this@<rcx>, float f@<xmm1>, int a3@<eax>)
{
  hkOstream *v3; // rbx
  char buf; // [rsp+20h] [rbp-2738h]

  v3 = this;
  hkString::snprintf(&buf, a3 - 40, "%f", f);
  writeString(v3->m_writer.m_pntr, &buf);
  return v3;
}

// File Line: 159
// RVA: 0xC66970
hkOstream *__usercall hkOstream::operator<<@<rax>(hkOstream *this@<rcx>, __int64 i@<rdx>, int a3@<eax>)
{
  hkOstream *v3; // rbx
  char buf; // [rsp+20h] [rbp-2738h]

  v3 = this;
  hkString::snprintf(&buf, a3 - 40, "%I64i", i);
  writeString(v3->m_writer.m_pntr, &buf);
  return v3;
}

// File Line: 166
// RVA: 0xC669C0
hkOstream *__usercall hkOstream::operator<<@<rax>(hkOstream *this@<rcx>, unsigned __int64 i@<rdx>, int a3@<eax>)
{
  hkOstream *v3; // rbx
  char buf; // [rsp+20h] [rbp-2738h]

  v3 = this;
  hkString::snprintf(&buf, a3 - 40, "%I64u", i);
  writeString(v3->m_writer.m_pntr, &buf);
  return v3;
}

// File Line: 174
// RVA: 0xC66630
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkVector4f *v)
{
  hkOstream *v2; // rbx

  v2 = this;
  hkOstream::printf(
    this,
    "[%g,%g,%g,%g]",
    v->m_quad.m128_f32[0],
    v->m_quad.m128_f32[1],
    v->m_quad.m128_f32[2],
    v->m_quad.m128_f32[3]);
  return v2;
}

// File Line: 180
// RVA: 0xC66810
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkVector4d *v)
{
  hkOstream *v2; // rbx

  v2 = this;
  hkOstream::printf(
    this,
    "[%g,%g,%g,%g]",
    v->m_quad.xy.m128d_f64[0],
    v->m_quad.xy.m128d_f64[1],
    v->m_quad.zw.m128d_f64[0],
    v->m_quad.zw.m128d_f64[1]);
  return v2;
}

// File Line: 188
// RVA: 0xC66690
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkQuaternionf *q)
{
  hkOstream *v2; // rbx

  v2 = this;
  hkOstream::printf(
    this,
    "[%f,%f,%f,(%f)]",
    q->m_vec.m_quad.m128_f32[0],
    q->m_vec.m_quad.m128_f32[1],
    q->m_vec.m_quad.m128_f32[2],
    q->m_vec.m_quad.m128_f32[3]);
  return v2;
}

// File Line: 194
// RVA: 0xC66860
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkQuaterniond *q)
{
  hkOstream *v2; // rbx

  v2 = this;
  hkOstream::printf(
    this,
    "[%f,%f,%f,(%f)]",
    q->m_vec.m_quad.xy.m128d_f64[0],
    q->m_vec.m_quad.xy.m128d_f64[1],
    q->m_vec.m_quad.zw.m128d_f64[0],
    q->m_vec.m_quad.zw.m128d_f64[1]);
  return v2;
}

// File Line: 200
// RVA: 0xC666F0
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkMatrix3f *m)
{
  hkOstream *v2; // rsi
  float *v3; // rbx
  signed __int64 v4; // rdi

  v2 = this;
  v3 = m->m_col1.m_quad.m128_f32;
  v4 = 3i64;
  do
  {
    hkOstream::printf(v2, "|%f,%f,%f|\n", *(v3 - 4), *v3, v3[4]);
    ++v3;
    --v4;
  }
  while ( v4 );
  return v2;
}

// File Line: 209
// RVA: 0xC668B0
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkMatrix3d *m)
{
  _QWORD *v2; // rdi
  signed int v3; // ebx
  hkOstream *v4; // rbp

  v2 = (_QWORD *)m->m_col1.m_quad.xy.m128d_f64;
  v3 = 0;
  v4 = this;
  do
  {
    hkOstream::printf(v4, "|%f,%f,%f|\n", *(v2 - 4), *v2, v2[4]);
    ++v3;
    ++v2;
  }
  while ( v3 < 3 );
  return v4;
}

// File Line: 218
// RVA: 0xC66770
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkTransformf *t)
{
  hkVector4f *v2; // rbx
  hkOstream *v3; // rax

  v2 = &t->m_translation;
  v3 = hkOstream::operator<<(this, (hkMatrix3f *)&t->m_rotation.m_col0);
  return hkOstream::operator<<(v3, v2);
}

// File Line: 223
// RVA: 0xC66940
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkTransformd *t)
{
  hkVector4d *v2; // rbx
  hkOstream *v3; // rax

  v2 = &t->m_translation;
  v3 = hkOstream::operator<<(this, (hkMatrix3d *)&t->m_rotation.m_col0);
  return hkOstream::operator<<(v3, v2);
}

// File Line: 230
// RVA: 0xC66B00
void __usercall hkOstream::printf(hkOstream *this@<rcx>, const char *fmt@<rdx>, int a3@<eax>, ...)
{
  hkOstream *v3; // rbx
  char buf; // [rsp+20h] [rbp-2738h]
  va_list hkargs; // [rsp+2770h] [rbp+18h]

  va_start(hkargs, a3);
  v3 = this;
  hkString::vsnprintf(&buf, a3 - 40, fmt, hkargs);
  writeString(v3->m_writer.m_pntr, &buf);
}

// File Line: 240
// RVA: 0xC66A10
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkStringPtr *str)
{
  hkOstream *v2; // rsi
  unsigned __int64 v3; // rbp
  hkStreamWriter *v4; // rdi
  hkBaseObjectVtbl *v5; // rbx
  unsigned int v6; // eax

  v2 = this;
  v3 = (_QWORD)str->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  if ( v3 )
  {
    v4 = this->m_writer.m_pntr;
    v5 = v4->vfptr;
    v6 = hkStringPtr::getLength(str);
    ((void (__fastcall *)(hkStreamWriter *, unsigned __int64, _QWORD))v5[2].__vecDelDtor)(v4, v3, v6);
  }
  else
  {
    ((void (__fastcall *)(hkStreamWriter *, const char *, signed __int64))this->m_writer.m_pntr->vfptr[2].__vecDelDtor)(
      this->m_writer.m_pntr,
      "(null)",
      6i64);
  }
  return v2;
}

// File Line: 253
// RVA: 0xC66A90
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkStringBuf *str)
{
  hkOstream *v2; // rbx
  hkStreamWriter *v3; // rcx
  hkBaseObjectVtbl *v4; // rax

  v2 = this;
  v3 = this->m_writer.m_pntr;
  v4 = v3->vfptr;
  if ( str->m_string.m_data )
    ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD))v4[2].__vecDelDtor)(
      v3,
      str->m_string.m_data,
      (unsigned int)(str->m_string.m_size - 1));
  else
    ((void (__fastcall *)(hkStreamWriter *, const char *, signed __int64))v4[2].__vecDelDtor)(v3, "(null)", 6i64);
  return v2;
}

// File Line: 266
// RVA: 0xC66B60
void __fastcall hkOstream::flush(hkOstream *this)
{
  ((void (*)(void))this->m_writer.m_pntr->vfptr[2].__first_virtual_table_function__)();
}

// File Line: 272
// RVA: 0xC66AE0
__int64 __fastcall hkOstream::write(hkOstream *this, const char *buf, __int64 nbytes)
{
  return ((__int64 (__fastcall *)(hkStreamWriter *, const char *, __int64))this->m_writer.m_pntr->vfptr[2].__vecDelDtor)(
           this->m_writer.m_pntr,
           buf,
           nbytes);
}

// File Line: 277
// RVA: 0xC66B80
void __fastcall hkOstream::setStreamWriter(hkOstream *this, hkStreamWriter *newWriter)
{
  hkStreamWriter *v2; // rbx
  hkOstream *v3; // rdi
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

// File Line: 283
// RVA: 0xC66BC0
hkClass *__fastcall hkOstream::getClassType(hkOstream *this)
{
  return &hkOstreamClass;
}

