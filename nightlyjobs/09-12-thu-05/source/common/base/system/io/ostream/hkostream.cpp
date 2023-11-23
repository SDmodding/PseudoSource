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
  hkBaseObjectVtbl *vfptr; // rbx
  unsigned int v5; // eax

  if ( s )
  {
    vfptr = sb->vfptr;
    v5 = hkString::strLen(s);
    ((void (__fastcall *)(hkStreamWriter *, const char *, _QWORD))vfptr[2].__vecDelDtor)(sb, s, v5);
  }
  else
  {
    ((void (__fastcall *)(hkStreamWriter *, const char *, __int64))sb->vfptr[2].__vecDelDtor)(sb, "(null)", 6i64);
  }
}

// File Line: 42
// RVA: 0xC65FE0
void __fastcall hkOstream::hkOstream(hkOstream *this, hkStreamWriter *sw)
{
  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkOstream::`vftable;
  if ( sw )
  {
    hkReferencedObject::addReference(sw);
    this->m_writer.m_pntr = sw;
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
  hkStreamWriter **v3; // rax
  hkStreamWriter *m_pntr; // rcx
  hkStreamWriter *v5; // rbx
  char v6; // [rsp+30h] [rbp+8h] BYREF

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkOstream::`vftable;
  this->m_writer.m_pntr = 0i64;
  v3 = (hkStreamWriter **)((__int64 (__fastcall *)(hkFileSystem *, char *, const char *, __int64))hkSingleton<hkFileSystem>::s_instance->vfptr[2].__vecDelDtor)(
                            hkSingleton<hkFileSystem>::s_instance,
                            &v6,
                            filename,
                            3i64);
  m_pntr = this->m_writer.m_pntr;
  v5 = *v3;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_writer.m_pntr = v5;
}

// File Line: 51
// RVA: 0xC660B0
void __fastcall hkOstream::hkOstream(hkOstream *this, void *mem, int memSize, hkBool isString)
{
  hkStreamWriter *v5; // rdi
  _QWORD **Value; // rax
  hkBufferedStreamWriter *v9; // rax
  hkStreamWriter *v10; // rax
  hkStreamWriter *m_pntr; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkOstream::`vftable;
  v5 = 0i64;
  this->m_writer.m_pntr = 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v9 = (hkBufferedStreamWriter *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 48i64);
  if ( v9 )
  {
    hkBufferedStreamWriter::hkBufferedStreamWriter(v9, mem, memSize, isString);
    v5 = v10;
  }
  m_pntr = this->m_writer.m_pntr;
  if ( m_pntr && m_pntr != v5 )
    hkReferencedObject::removeReference(m_pntr);
  this->m_writer.m_pntr = v5;
}

// File Line: 56
// RVA: 0xC66160
void __fastcall hkOstream::hkOstream(hkOstream *this, hkArray<char,hkContainerHeapAllocator> *buf)
{
  hkStreamWriter *v3; // rdi
  _QWORD **Value; // rax
  hkArrayStreamWriter *v6; // rax
  hkStreamWriter *v7; // rax
  hkStreamWriter *m_pntr; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkOstream::`vftable;
  v3 = 0i64;
  this->m_writer.m_pntr = 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v6 = (hkArrayStreamWriter *)(*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 40i64);
  if ( v6 )
  {
    hkArrayStreamWriter::hkArrayStreamWriter(v6, buf, ARRAY_BORROW);
    v3 = v7;
  }
  m_pntr = this->m_writer.m_pntr;
  if ( m_pntr && m_pntr != v3 )
    hkReferencedObject::removeReference(m_pntr);
  this->m_writer.m_pntr = v3;
}

// File Line: 61
// RVA: 0xC66200
void __fastcall hkOstream::hkOstream(hkOstream *this, hkMemoryTrack *buf)
{
  _QWORD **Value; // rax
  __int64 v5; // rax
  hkStreamWriter *v6; // rbx
  hkStreamWriter *m_pntr; // rcx

  *(_DWORD *)&this->m_memSizeAndFlags = 0x1FFFF;
  this->vfptr = (hkBaseObjectVtbl *)&hkOstream::`vftable;
  this->m_writer.m_pntr = 0i64;
  Value = (_QWORD **)TlsGetValue(hkMemoryRouter::s_memoryRouter.m_slotID);
  v5 = (*(__int64 (__fastcall **)(_QWORD *, __int64))(*Value[11] + 8i64))(Value[11], 32i64);
  v6 = (hkStreamWriter *)v5;
  if ( v5 )
  {
    *(_DWORD *)(v5 + 8) = 0x1FFFF;
    *(_QWORD *)(v5 + 16) = buf;
    *(_QWORD *)v5 = &hkMemoryTrackStreamWriter::`vftable;
    *(_DWORD *)(v5 + 24) = 1;
  }
  else
  {
    v6 = 0i64;
  }
  m_pntr = this->m_writer.m_pntr;
  if ( m_pntr && m_pntr != v6 )
    hkReferencedObject::removeReference(m_pntr);
  this->m_writer.m_pntr = v6;
}

// File Line: 67
// RVA: 0xC662C0
void __fastcall hkOstream::~hkOstream(hkOstream *this)
{
  hkStreamWriter *m_pntr; // rcx

  this->vfptr = (hkBaseObjectVtbl *)&hkOstream::`vftable;
  m_pntr = this->m_writer.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_writer.m_pntr = 0i64;
  this->vfptr = (hkBaseObjectVtbl *)&hkBaseObject::`vftable;
}

// File Line: 71
// RVA: 0xC66300
hkBool *__fastcall hkOstream::isOk(hkOstream *this, hkBool *result)
{
  hkStreamWriter *m_pntr; // rcx
  char v5; // [rsp+30h] [rbp+8h] BYREF

  m_pntr = this->m_writer.m_pntr;
  if ( m_pntr
    && *(_BYTE *)((__int64 (__fastcall *)(hkStreamWriter *, char *))m_pntr->vfptr[1].__first_virtual_table_function__)(
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

// File Line: 76
// RVA: 0xC66340
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, const void *p)
{
  int v2; // eax
  char buf[10040]; // [rsp+20h] [rbp-2738h] BYREF

  hkString::snprintf(buf, v2 - 40, "%p", p);
  writeString(this->m_writer.m_pntr, buf);
  return this;
}

// File Line: 84
// RVA: 0xC66390
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkBool b)
{
  const char *v3; // rax

  v3 = "false";
  if ( b.m_bool )
    v3 = "true";
  writeString(this->m_writer.m_pntr, v3);
  return this;
}

// File Line: 90
// RVA: 0xC663D0
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, char c)
{
  char v4; // [rsp+38h] [rbp+10h] BYREF

  v4 = c;
  ((void (__fastcall *)(hkStreamWriter *, char *, __int64))this->m_writer.m_pntr->vfptr[2].__vecDelDtor)(
    this->m_writer.m_pntr,
    &v4,
    1i64);
  return this;
}

// File Line: 96
// RVA: 0xC66400
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, const char *s)
{
  writeString(this->m_writer.m_pntr, s);
  return this;
}

// File Line: 102
// RVA: 0xC66430
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, __int16 s)
{
  int v2; // eax
  char buf[10040]; // [rsp+20h] [rbp-2738h] BYREF

  hkString::snprintf(buf, v2 - 40, "%i", (unsigned int)s);
  writeString(this->m_writer.m_pntr, buf);
  return this;
}

// File Line: 110
// RVA: 0xC66480
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, unsigned __int16 s)
{
  int v2; // eax
  char buf[10040]; // [rsp+20h] [rbp-2738h] BYREF

  hkString::snprintf(buf, v2 - 40, "%u", s);
  writeString(this->m_writer.m_pntr, buf);
  return this;
}

// File Line: 118
// RVA: 0xC664D0
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, unsigned int i)
{
  int v2; // eax
  char buf[10040]; // [rsp+20h] [rbp-2738h] BYREF

  hkString::snprintf(buf, v2 - 40, "%i", i);
  writeString(this->m_writer.m_pntr, buf);
  return this;
}

// File Line: 126
// RVA: 0xC66520
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, unsigned int u)
{
  int v2; // eax
  char buf[10040]; // [rsp+20h] [rbp-2738h] BYREF

  hkString::snprintf(buf, v2 - 40, "%u", u);
  writeString(this->m_writer.m_pntr, buf);
  return this;
}

// File Line: 134
// RVA: 0xC665D0
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkSimdFloat32 *f)
{
  int v2; // eax
  char buf[10040]; // [rsp+20h] [rbp-2738h] BYREF

  hkString::snprintf(buf, v2 - 40, "%f", f->m_real.m128_f32[0]);
  writeString(this->m_writer.m_pntr, buf);
  return this;
}

// File Line: 142
// RVA: 0xC667A0
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkSimdDouble64 *f)
{
  int v2; // eax
  char buf[10040]; // [rsp+20h] [rbp-2738h] BYREF

  hkString::snprintf(buf, v2 - 40, "%f", (double)f->m_real.m128d_f64[0]);
  writeString(this->m_writer.m_pntr, buf);
  return this;
}

// File Line: 151
// RVA: 0xC66570
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, float f)
{
  int v2; // eax
  char buf[10040]; // [rsp+20h] [rbp-2738h] BYREF

  hkString::snprintf(buf, v2 - 40, "%f", f);
  writeString(this->m_writer.m_pntr, buf);
  return this;
}

// File Line: 159
// RVA: 0xC66970
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, __int64 i)
{
  int v2; // eax
  char buf[10040]; // [rsp+20h] [rbp-2738h] BYREF

  hkString::snprintf(buf, v2 - 40, "%I64i", i);
  writeString(this->m_writer.m_pntr, buf);
  return this;
}

// File Line: 166
// RVA: 0xC669C0
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, unsigned __int64 i)
{
  int v2; // eax
  char buf[10040]; // [rsp+20h] [rbp-2738h] BYREF

  hkString::snprintf(buf, v2 - 40, "%I64u", i);
  writeString(this->m_writer.m_pntr, buf);
  return this;
}

// File Line: 174
// RVA: 0xC66630
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkVector4f *v)
{
  hkOstream::printf(
    this,
    "[%g,%g,%g,%g]",
    v->m_quad.m128_f32[0],
    v->m_quad.m128_f32[1],
    v->m_quad.m128_f32[2],
    v->m_quad.m128_f32[3]);
  return this;
}

// File Line: 180
// RVA: 0xC66810
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkVector4d *v)
{
  hkOstream::printf(
    this,
    "[%g,%g,%g,%g]",
    (double)v->m_quad.xy.m128d_f64[0],
    (double)v->m_quad.xy.m128d_f64[1],
    (double)v->m_quad.zw.m128d_f64[0],
    (double)v->m_quad.zw.m128d_f64[1]);
  return this;
}

// File Line: 188
// RVA: 0xC66690
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkQuaternionf *q)
{
  hkOstream::printf(
    this,
    "[%f,%f,%f,(%f)]",
    q->m_vec.m_quad.m128_f32[0],
    q->m_vec.m_quad.m128_f32[1],
    q->m_vec.m_quad.m128_f32[2],
    q->m_vec.m_quad.m128_f32[3]);
  return this;
}

// File Line: 194
// RVA: 0xC66860
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkQuaterniond *q)
{
  hkOstream::printf(
    this,
    "[%f,%f,%f,(%f)]",
    (double)q->m_vec.m_quad.xy.m128d_f64[0],
    (double)q->m_vec.m_quad.xy.m128d_f64[1],
    (double)q->m_vec.m_quad.zw.m128d_f64[0],
    (double)q->m_vec.m_quad.zw.m128d_f64[1]);
  return this;
}

// File Line: 200
// RVA: 0xC666F0
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkMatrix3f *m)
{
  hkVector4f *p_m_col1; // rbx
  __int64 v4; // rdi

  p_m_col1 = &m->m_col1;
  v4 = 3i64;
  do
  {
    hkOstream::printf(
      this,
      "|%f,%f,%f|\n",
      p_m_col1[-1].m_quad.m128_f32[0],
      p_m_col1->m_quad.m128_f32[0],
      p_m_col1[1].m_quad.m128_f32[0]);
    p_m_col1 = (hkVector4f *)((char *)p_m_col1 + 4);
    --v4;
  }
  while ( v4 );
  return this;
}

// File Line: 209
// RVA: 0xC668B0
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkMatrix3d *m)
{
  hkVector4d *p_m_col1; // rdi
  int i; // ebx

  p_m_col1 = &m->m_col1;
  for ( i = 0; i < 3; ++i )
  {
    hkOstream::printf(
      this,
      "|%f,%f,%f|\n",
      (double)p_m_col1[-1].m_quad.xy.m128d_f64[0],
      (double)p_m_col1->m_quad.xy.m128d_f64[0],
      (double)p_m_col1[1].m_quad.xy.m128d_f64[0]);
    p_m_col1 = (hkVector4d *)((char *)p_m_col1 + 8);
  }
  return this;
}

// File Line: 218
// RVA: 0xC66770
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkTransformf *t)
{
  hkVector4f *p_m_translation; // rbx
  hkOstream *v3; // rax

  p_m_translation = &t->m_translation;
  v3 = hkOstream::operator<<(this, &t->m_rotation);
  return hkOstream::operator<<(v3, p_m_translation);
}

// File Line: 223
// RVA: 0xC66940
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkTransformd *t)
{
  hkVector4d *p_m_translation; // rbx
  hkOstream *v3; // rax

  p_m_translation = &t->m_translation;
  v3 = hkOstream::operator<<(this, &t->m_rotation);
  return hkOstream::operator<<(v3, p_m_translation);
}

// File Line: 230
// RVA: 0xC66B00
void hkOstream::printf(hkOstream *this, const char *fmt, ...)
{
  int v2; // eax
  char buf[10040]; // [rsp+20h] [rbp-2738h] BYREF
  va_list hkargs; // [rsp+2770h] [rbp+18h] BYREF

  va_start(hkargs, fmt);
  hkString::vsnprintf(buf, v2 - 40, fmt, hkargs);
  writeString(this->m_writer.m_pntr, buf);
}

// File Line: 240
// RVA: 0xC66A10
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkStringPtr *str)
{
  unsigned __int64 v3; // rbp
  hkStreamWriter *m_pntr; // rdi
  hkBaseObjectVtbl *vfptr; // rbx
  unsigned int Length; // eax

  v3 = (unsigned __int64)str->m_stringAndFlag & 0xFFFFFFFFFFFFFFFEui64;
  if ( v3 )
  {
    m_pntr = this->m_writer.m_pntr;
    vfptr = m_pntr->vfptr;
    Length = hkStringPtr::getLength(str);
    ((void (__fastcall *)(hkStreamWriter *, unsigned __int64, _QWORD))vfptr[2].__vecDelDtor)(m_pntr, v3, Length);
  }
  else
  {
    ((void (__fastcall *)(hkStreamWriter *, const char *, __int64))this->m_writer.m_pntr->vfptr[2].__vecDelDtor)(
      this->m_writer.m_pntr,
      "(null)",
      6i64);
  }
  return this;
}

// File Line: 253
// RVA: 0xC66A90
hkOstream *__fastcall hkOstream::operator<<(hkOstream *this, hkStringBuf *str)
{
  hkStreamWriter *m_pntr; // rcx
  hkBaseObjectVtbl *vfptr; // rax

  m_pntr = this->m_writer.m_pntr;
  vfptr = m_pntr->vfptr;
  if ( str->m_string.m_data )
    ((void (__fastcall *)(hkStreamWriter *, char *, _QWORD))vfptr[2].__vecDelDtor)(
      m_pntr,
      str->m_string.m_data,
      (unsigned int)(str->m_string.m_size - 1));
  else
    ((void (__fastcall *)(hkStreamWriter *, const char *, __int64))vfptr[2].__vecDelDtor)(m_pntr, "(null)", 6i64);
  return this;
}

// File Line: 266
// RVA: 0xC66B60
void __fastcall hkOstream::flush(hkOstream *this)
{
  this->m_writer.m_pntr->vfptr[2].__first_virtual_table_function__(this->m_writer.m_pntr);
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
  hkStreamWriter *m_pntr; // rcx

  if ( newWriter )
    hkReferencedObject::addReference(newWriter);
  m_pntr = this->m_writer.m_pntr;
  if ( m_pntr )
    hkReferencedObject::removeReference(m_pntr);
  this->m_writer.m_pntr = newWriter;
}

// File Line: 283
// RVA: 0xC66BC0
hkClass *__fastcall hkOstream::getClassType(hkOstream *this)
{
  return &hkOstreamClass;
}

