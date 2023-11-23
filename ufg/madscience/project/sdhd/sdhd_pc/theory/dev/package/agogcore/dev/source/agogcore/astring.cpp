// File Line: 66
// RVA: 0x2235B0
void __fastcall AString::AString(AString *this, const char *cstr_p, bool persistent)
{
  __int64 v3; // rax

  v3 = -1i64;
  do
    ++v3;
  while ( cstr_p[v3] );
  if ( persistent )
    this->i_str_ref_p = AStringRef::pool_new(cstr_p, v3, (int)v3 + 1, 1u, 0, 1);
  else
    this->i_str_ref_p = AStringRef::pool_new_copy(cstr_p, v3, 1u, 0);
}

// File Line: 109
// RVA: 0x223530
void __fastcall AString::AString(AString *this, const char *cstr_p, unsigned int length, bool persistent)
{
  __int64 v4; // rax

  LODWORD(v4) = length;
  if ( length == -1 )
  {
    v4 = -1i64;
    do
      ++v4;
    while ( cstr_p[v4] );
  }
  if ( persistent )
    this->i_str_ref_p = AStringRef::pool_new(cstr_p, v4, (int)v4 + 1, 1u, 0, 1);
  else
    this->i_str_ref_p = AStringRef::pool_new_copy(cstr_p, v4, 1u, 0);
}

// File Line: 162
// RVA: 0x223470
void __fastcall AString::AString(
        AString *this,
        const char *buffer_p,
        unsigned int size,
        unsigned int length,
        bool deallocate)
{
  __int64 v5; // rbx
  AStringRef *v7; // rax
  unsigned int v8; // ebx
  const char *v9; // rax
  AStringRef *v10; // rax

  LODWORD(v5) = length;
  if ( buffer_p )
  {
    if ( length == -1 )
    {
      v5 = -1i64;
      do
        ++v5;
      while ( buffer_p[v5] );
    }
    v7 = AStringRef::pool_new(buffer_p, v5, size, 1u, deallocate, 0);
    this->i_str_ref_p = v7;
    v7->i_cstr_p[(unsigned int)v5] = 0;
  }
  else
  {
    v8 = AMemory::c_req_byte_size_func(size + 1);
    v9 = (const char *)AMemory::c_malloc_func(v8, "AStringRef.buffer");
    v10 = AStringRef::pool_new(v9, 0, v8, 1u, 1, 0);
    this->i_str_ref_p = v10;
    *v10->i_cstr_p = 0;
  }
}

// File Line: 220
// RVA: 0x223340
void AString::AString(AString *this, unsigned int max_size, const char *format_str_p, ...)
{
  __int64 v3; // rbx
  unsigned int v5; // ebp
  char *v6; // rdi
  unsigned int v7; // eax
  va_list ap; // [rsp+78h] [rbp+20h] BYREF

  va_start(ap, format_str_p);
  v3 = max_size;
  v5 = AMemory::c_req_byte_size_func(max_size + 1);
  v6 = (char *)AMemory::c_malloc_func(v5, "AStringRef.buffer");
  v7 = vsnprintf(v6, (unsigned int)v3, format_str_p, ap);
  if ( v7 == -1 || v7 == (_DWORD)v3 )
  {
    v7 = v3;
    v6[v3] = 0;
  }
  this->i_str_ref_p = AStringRef::pool_new(v6, v7, v5, 1u, 1, 0);
}

// File Line: 263
// RVA: 0x2233D0
void __fastcall AString::AString(AString *this, const void **source_stream_pp)
{
  __int64 v4; // rdi
  unsigned int v5; // ebx
  const char *v6; // rax
  AStringRef *v7; // rax

  v4 = *(unsigned int *)*source_stream_pp;
  *source_stream_pp = (char *)*source_stream_pp + 4;
  v5 = AMemory::c_req_byte_size_func(v4 + 1);
  v6 = (const char *)AMemory::c_malloc_func(v5, "AStringRef.buffer");
  v7 = AStringRef::pool_new(v6, v4, v5, 1u, 1, 0);
  this->i_str_ref_p = v7;
  memmove(v7->i_cstr_p, *source_stream_pp, (unsigned int)v4);
  this->i_str_ref_p->i_cstr_p[v4] = 0;
  *source_stream_pp = (char *)*source_stream_pp + v4;
}

// File Line: 394
// RVA: 0x224930
AString *__fastcall AString::ctor_int(AString *result, int integer, int base)
{
  unsigned int v6; // ebp
  char *v7; // rsi
  __int64 v8; // rdx
  AStringRef *v9; // rax

  v6 = AMemory::c_req_byte_size_func(0x29u);
  v7 = (char *)AMemory::c_malloc_func(v6, "AStringRef.buffer");
  itoa(integer, v7, base);
  v8 = -1i64;
  do
    ++v8;
  while ( v7[v8] );
  v9 = AStringRef::pool_new(v7, v8, v6, 0, 1, 0);
  result->i_str_ref_p = v9;
  ++v9->i_ref_count;
  return result;
}

// File Line: 425
// RVA: 0x2249F0
AString *__fastcall AString::ctor_uint(AString *result, unsigned int natural, int base)
{
  unsigned int v6; // ebp
  char *v7; // rsi
  __int64 v8; // rdx
  AStringRef *v9; // rax

  v6 = AMemory::c_req_byte_size_func(0x29u);
  v7 = (char *)AMemory::c_malloc_func(v6, "AStringRef.buffer");
  ultoa(natural, v7, base);
  v8 = -1i64;
  do
    ++v8;
  while ( v7[v8] );
  v9 = AStringRef::pool_new(v7, v8, v6, 0, 1, 0);
  result->i_str_ref_p = v9;
  ++v9->i_ref_count;
  return result;
}

// File Line: 456
// RVA: 0x224860
AString *__fastcall AString::ctor_float(AString *result, float real, int significant)
{
  unsigned int v5; // ebp
  char *v6; // rdi
  __int64 v7; // rbx
  AStringRef *v8; // rax

  v5 = AMemory::c_req_byte_size_func(significant + 11);
  v6 = (char *)AMemory::c_malloc_func(v5, "AStringRef.buffer");
  gcvt(real, significant, v6);
  v7 = -1i64;
  do
    ++v7;
  while ( v6[v7] );
  v8 = AStringRef::pool_new(v6, v7, v5, 0, 1, 0);
  if ( v6[(unsigned int)(v7 - 1)] == 46 )
  {
    v6[(unsigned int)v7] = 48;
    v6[(unsigned int)(v7 + 1)] = 0;
    ++v8->i_length;
  }
  result->i_str_ref_p = v8;
  ++v8->i_ref_count;
  return result;
}

// File Line: 881
// RVA: 0x2262E0
char __fastcall AString::is_equal(AString *this, AString *str)
{
  AStringRef *i_str_ref_p; // rax
  __int64 i_length; // rcx
  char *i_cstr_p; // rax
  char *v6; // r8
  char *v7; // rdx
  signed __int64 v8; // r8

  i_str_ref_p = this->i_str_ref_p;
  i_length = this->i_str_ref_p->i_length;
  if ( (_DWORD)i_length != str->i_str_ref_p->i_length )
    return 0;
  i_cstr_p = i_str_ref_p->i_cstr_p;
  v6 = str->i_str_ref_p->i_cstr_p;
  if ( i_cstr_p != v6 )
  {
    v7 = &i_cstr_p[i_length];
    if ( i_cstr_p < &i_cstr_p[i_length] )
    {
      v8 = v6 - i_cstr_p;
      while ( *i_cstr_p == i_cstr_p[v8] )
      {
        if ( ++i_cstr_p >= v7 )
          return 1;
      }
      return 0;
    }
  }
  return 1;
}

// File Line: 948
// RVA: 0x223F30
void __fastcall AString::append(AString *this, const char *cstr_p, unsigned int length)
{
  __int64 v3; // rbx
  __int64 v6; // rsi

  LODWORD(v3) = length;
  if ( length == -1 )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( cstr_p[v3] );
  }
  if ( (_DWORD)v3 )
  {
    v6 = (unsigned int)(v3 + this->i_str_ref_p->i_length);
    if ( (unsigned int)v6 >= this->i_str_ref_p->i_size
      || this->i_str_ref_p->i_ref_count + this->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(this, v6);
    }
    memmove(&this->i_str_ref_p->i_cstr_p[this->i_str_ref_p->i_length], cstr_p, (unsigned int)v3);
    this->i_str_ref_p->i_length = v6;
    this->i_str_ref_p->i_cstr_p[v6] = 0;
  }
}

// File Line: 1003
// RVA: 0x224270
void AString::append_format(AString *this, const char *format_str_p, ...)
{
  AStringRef *i_str_ref_p; // rax
  const char *v3; // r8
  __int64 i_length; // rsi
  int v6; // ebx
  unsigned int v7; // edx
  int v8; // eax
  int v9; // r8d
  va_list ap; // [rsp+50h] [rbp+18h] BYREF

  va_start(ap, format_str_p);
  i_str_ref_p = this->i_str_ref_p;
  v3 = format_str_p;
  i_length = this->i_str_ref_p->i_length;
  v6 = this->i_str_ref_p->i_size - i_length - 1;
  if ( v6 > 0 )
  {
    v7 = this->i_str_ref_p->i_size - 1;
    if ( v7 >= i_str_ref_p->i_size || i_str_ref_p->i_ref_count + i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(this, v7);
      v3 = format_str_p;
    }
    v8 = vsnprintf(&this->i_str_ref_p->i_cstr_p[i_length], v6, v3, ap);
    v9 = v8;
    if ( v8 == -1 || v8 == v6 )
    {
      v9 = v6;
      this->i_str_ref_p->i_cstr_p[(unsigned int)(v6 + i_length)] = 0;
    }
    this->i_str_ref_p->i_length += v9;
  }
}

// File Line: 1203
// RVA: 0x2250C0
void AString::format(AString *this, const char *format_str_p, ...)
{
  AStringRef *i_str_ref_p; // rax
  const char *v3; // r8
  signed int v5; // ebx
  int v6; // eax
  unsigned int v7; // edx
  va_list ap; // [rsp+50h] [rbp+18h] BYREF

  va_start(ap, format_str_p);
  i_str_ref_p = this->i_str_ref_p;
  v3 = format_str_p;
  v5 = this->i_str_ref_p->i_size - 1;
  if ( v5 > 0 )
  {
    if ( v5 >= i_str_ref_p->i_size || i_str_ref_p->i_ref_count + i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size_buffer(this, v5);
      v3 = format_str_p;
    }
    v6 = vsnprintf(this->i_str_ref_p->i_cstr_p, v5, v3, ap);
    v7 = v6;
    if ( v6 == -1 || v6 == v5 )
    {
      v7 = v5;
      this->i_str_ref_p->i_cstr_p[v5] = 0;
    }
    this->i_str_ref_p->i_length = v7;
  }
}

// File Line: 1246
// RVA: 0x2253D0
__int64 __fastcall AString::increment(AString *this, unsigned int increment_by, unsigned int min_digits)
{
  int v3; // ebx
  AStringRef *i_str_ref_p; // r8
  unsigned int i_length; // r13d
  unsigned int v7; // r15d
  int v10; // r14d
  unsigned int v11; // ebp
  char *i_cstr_p; // rdx
  char *v13; // rcx
  unsigned int v14; // r14d
  unsigned int v15; // ebp
  unsigned int i; // edx
  AStringRef *v17; // rax
  unsigned int v18; // edx
  unsigned int v19; // edx
  unsigned int v20; // esi
  __int64 v21; // r14
  __int64 v22; // rbx
  char *endptr; // [rsp+50h] [rbp+8h] BYREF

  v3 = 0;
  i_str_ref_p = this->i_str_ref_p;
  i_length = this->i_str_ref_p->i_length;
  v7 = 1;
  v10 = 0;
  v11 = 0;
  if ( i_length )
  {
    i_cstr_p = i_str_ref_p->i_cstr_p;
    v13 = &i_str_ref_p->i_cstr_p[i_length - 1];
    if ( i_str_ref_p->i_cstr_p <= v13 )
    {
      while ( !byte_14236F0C0[(unsigned __int8)*v13] )
      {
        if ( i_cstr_p > --v13 )
          goto LABEL_6;
      }
      v10 = (_DWORD)v13 - (_DWORD)i_cstr_p;
    }
  }
LABEL_6:
  v14 = v10 + 1;
  if ( v14 < i_length )
  {
    min_digits = i_length - v14;
    v11 = strtoul(&i_str_ref_p->i_cstr_p[v14], &endptr, 10);
    i_length = v14;
    this->i_str_ref_p->i_length = v14;
  }
  v15 = increment_by + v11;
  if ( v15 >= 0xA )
  {
    for ( i = v15; i >= 0xA; i /= 0xAu )
      ++v3;
    v7 = v3 + 1;
  }
  v17 = this->i_str_ref_p;
  v18 = v7;
  if ( min_digits > v7 )
    v18 = min_digits;
  v19 = i_length + v18;
  if ( v19 >= v17->i_size || v17->i_ref_count + v17->i_read_only != 1 )
    AString::set_size(this, v19);
  if ( v7 < min_digits )
  {
    v20 = min_digits - v7;
    v21 = this->i_str_ref_p->i_length;
    v22 = v20 + (unsigned int)v21;
    if ( (unsigned int)v22 >= this->i_str_ref_p->i_size
      || this->i_str_ref_p->i_ref_count + this->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(this, v22);
    }
    memset(&this->i_str_ref_p->i_cstr_p[v21], 48, v20);
    this->i_str_ref_p->i_cstr_p[v22] = 0;
    this->i_str_ref_p->i_length = v22;
  }
  AString::append_format(this, "%d", v15);
  return v15;
}

// File Line: 1340
// RVA: 0x226180
void __fastcall AString::insert(AString *this, AString *str, unsigned int pos)
{
  __int64 v4; // rbp
  unsigned int v6; // edx

  v4 = pos;
  v6 = this->i_str_ref_p->i_length + str->i_str_ref_p->i_length;
  if ( v6 >= this->i_str_ref_p->i_size || this->i_str_ref_p->i_ref_count + this->i_str_ref_p->i_read_only != 1 )
    AString::set_size(this, v6);
  memmove(
    &this->i_str_ref_p->i_cstr_p[str->i_str_ref_p->i_length + v4],
    &this->i_str_ref_p->i_cstr_p[v4],
    (unsigned int)(this->i_str_ref_p->i_length - v4 + 1));
  memmove(&this->i_str_ref_p->i_cstr_p[v4], str->i_str_ref_p->i_cstr_p, str->i_str_ref_p->i_length);
  this->i_str_ref_p->i_length += str->i_str_ref_p->i_length;
}

// File Line: 1495
// RVA: 0x226890
__int64 __fastcall AString::remove_all(AString *this, char ch, unsigned int start_pos, unsigned int end_pos)
{
  __int64 v5; // rbp
  unsigned int i_length; // r9d
  char *v9; // rdx
  char *v10; // r10
  unsigned int v11; // r9d
  char *i; // r8
  int v13; // eax
  unsigned int v14; // eax

  v5 = start_pos;
  i_length = this->i_str_ref_p->i_length;
  if ( !i_length )
    return 0i64;
  if ( end_pos == -1 )
    end_pos = i_length - 1;
  if ( this->i_str_ref_p->i_ref_count + this->i_str_ref_p->i_read_only != 1 )
    AString::make_writeable(this);
  v9 = &this->i_str_ref_p->i_cstr_p[v5];
  v10 = &this->i_str_ref_p->i_cstr_p[end_pos];
  v11 = this->i_str_ref_p->i_length;
  for ( i = v9; v9 <= v10; ++v9 )
  {
    v13 = (unsigned __int8)*v9;
    if ( v13 == ch )
      --v11;
    else
      *i++ = v13;
  }
  *i = 0;
  v14 = this->i_str_ref_p->i_length;
  this->i_str_ref_p->i_length = v11;
  return v14 - v11;
}

// File Line: 2165
// RVA: 0x226A00
void __fastcall AString::set_cstr(AString *this, char *cstr_p, unsigned int length, bool persistent)
{
  __int64 v4; // rdi

  LODWORD(v4) = length;
  if ( length == -1 )
  {
    v4 = -1i64;
    do
      ++v4;
    while ( cstr_p[v4] );
  }
  if ( persistent )
  {
    AStringRef::dereference(this->i_str_ref_p);
    this->i_str_ref_p = AStringRef::pool_new(cstr_p, v4, (int)v4 + 1, 1u, 0, 1);
  }
  else
  {
    if ( (unsigned int)v4 >= this->i_str_ref_p->i_size
      || this->i_str_ref_p->i_ref_count + this->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size_buffer(this, v4);
    }
    memmove(this->i_str_ref_p->i_cstr_p, cstr_p, (unsigned int)v4);
    this->i_str_ref_p->i_cstr_p[(unsigned int)v4] = 0;
    this->i_str_ref_p->i_length = v4;
  }
}

// File Line: 2449
// RVA: 0x224720
__int64 __fastcall AString::count(
        AString *this,
        char ch,
        unsigned int start_pos,
        unsigned int end_pos,
        unsigned int *last_counted_p)
{
  unsigned int v5; // r10d
  char *i_cstr_p; // rbx
  unsigned int i_length; // ecx
  char *v8; // r11
  char *v9; // rcx
  char *v10; // rax

  v5 = 0;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  i_length = this->i_str_ref_p->i_length;
  v8 = &i_cstr_p[start_pos];
  if ( i_length )
  {
    if ( end_pos == -1 )
      end_pos = i_length - 1;
    v9 = &i_cstr_p[start_pos];
    v10 = &i_cstr_p[end_pos];
    if ( v8 <= v10 )
    {
      do
      {
        if ( *v9 == ch )
        {
          LODWORD(v8) = (_DWORD)v9;
          ++v5;
        }
        ++v9;
      }
      while ( v9 <= v10 );
    }
  }
  if ( last_counted_p )
    *last_counted_p = (_DWORD)v8 - (_DWORD)i_cstr_p;
  return v5;
}

// File Line: 2585
// RVA: 0x224E10
char __fastcall AString::find(
        AString *this,
        char ch,
        unsigned int instance,
        unsigned int *find_pos_p,
        unsigned int start_pos,
        unsigned int end_pos)
{
  AStringRef *i_str_ref_p; // rbx
  unsigned int i_length; // eax
  unsigned int v9; // r10d
  char *v10; // rax
  char *v11; // rdx

  i_str_ref_p = this->i_str_ref_p;
  i_length = this->i_str_ref_p->i_length;
  if ( !i_length )
    return 0;
  v9 = end_pos;
  if ( end_pos == -1 )
    v9 = i_length - 1;
  v10 = &i_str_ref_p->i_cstr_p[start_pos];
  v11 = &i_str_ref_p->i_cstr_p[v9];
  if ( v10 > v11 )
    return 0;
  while ( *v10 != ch )
  {
LABEL_8:
    if ( ++v10 > v11 )
      return 0;
  }
  if ( instance != 1 )
  {
    --instance;
    goto LABEL_8;
  }
  if ( find_pos_p )
    *find_pos_p = (_DWORD)v10 - (unsigned __int64)i_str_ref_p->i_cstr_p;
  return 1;
}

// File Line: 2652
// RVA: 0x224E80
char __fastcall AString::find(
        AString *this,
        int match_type,
        unsigned int instance,
        unsigned int *find_pos_p,
        unsigned int start_pos,
        unsigned int end_pos)
{
  AStringRef *i_str_ref_p; // rbx
  unsigned int i_length; // eax
  unsigned int v9; // r10d
  char *v10; // rax
  char *v11; // r9
  bool *v12; // rdx

  i_str_ref_p = this->i_str_ref_p;
  i_length = this->i_str_ref_p->i_length;
  if ( !i_length )
    return 0;
  v9 = end_pos;
  if ( end_pos == -1 )
    v9 = i_length - 1;
  v10 = &i_str_ref_p->i_cstr_p[start_pos];
  v11 = &i_str_ref_p->i_cstr_p[v9];
  v12 = AString::c_char_match_table[(__int64)match_type];
  if ( v10 > v11 )
    return 0;
  while ( !v12[(unsigned __int8)*v10] )
  {
LABEL_8:
    if ( ++v10 > v11 )
      return 0;
  }
  if ( instance != 1 )
  {
    --instance;
    goto LABEL_8;
  }
  if ( find_pos_p )
    *find_pos_p = (_DWORD)v10 - LODWORD(i_str_ref_p->i_cstr_p);
  return 1;
}

// File Line: 3091
// RVA: 0x225070
char __fastcall AString::find_reverse(
        AString *this,
        char ch,
        unsigned int instance,
        unsigned int *find_pos_p,
        unsigned int start_pos,
        unsigned int end_pos)
{
  AStringRef *i_str_ref_p; // r11
  unsigned int i_length; // ecx
  __int64 v8; // rax
  char *i; // rax

  i_str_ref_p = this->i_str_ref_p;
  i_length = this->i_str_ref_p->i_length;
  if ( i_length )
  {
    v8 = end_pos;
    if ( end_pos == -1 )
      v8 = i_length - 1;
    for ( i = &i_str_ref_p->i_cstr_p[v8]; &i_str_ref_p->i_cstr_p[(unsigned __int64)start_pos] <= i; --i )
    {
      if ( *i == ch )
      {
        if ( instance == 1 )
        {
          if ( find_pos_p )
            *find_pos_p = (_DWORD)i - (unsigned __int64)i_str_ref_p->i_cstr_p;
          return 1;
        }
        --instance;
      }
    }
  }
  return 0;
}

// File Line: 3517
// RVA: 0x226330
void __fastcall AString::make_writeable(AString *this)
{
  AStringRef *i_str_ref_p; // rdi
  __int64 i_length; // r14
  unsigned int v4; // ebp
  void *v5; // rsi

  i_str_ref_p = this->i_str_ref_p;
  i_length = this->i_str_ref_p->i_length;
  v4 = AMemory::c_req_byte_size_func(i_length + 1);
  v5 = AMemory::c_malloc_func(v4, "AStringRef.buffer");
  memmove(v5, i_str_ref_p->i_cstr_p, (unsigned int)i_length);
  *((_BYTE *)v5 + i_length) = 0;
  if ( i_str_ref_p->i_ref_count == 1 )
  {
    i_str_ref_p->i_cstr_p = (char *)v5;
    i_str_ref_p->i_size = v4;
    *(_WORD *)&i_str_ref_p->i_deallocate = 1;
  }
  else
  {
    AStringRef::dereference(i_str_ref_p);
    this->i_str_ref_p = AStringRef::pool_new((const char *)v5, i_length, v4, 1u, 1, 0);
  }
}

// File Line: 3556
// RVA: 0x226AD0
void __fastcall AString::set_size(AString *this, unsigned int needed_chars)
{
  AStringRef *i_str_ref_p; // rdi
  unsigned int v4; // eax
  unsigned int v5; // esi
  __int64 i_length; // r14
  void *v7; // rbp
  unsigned __int16 i_ref_count; // cx
  unsigned __int16 v9; // cx

  i_str_ref_p = this->i_str_ref_p;
  v4 = AMemory::c_req_byte_size_func(needed_chars + 1);
  v5 = v4;
  i_length = v4 - 1;
  if ( i_str_ref_p->i_length < (unsigned int)i_length )
    i_length = i_str_ref_p->i_length;
  v7 = AMemory::c_malloc_func(v4, "AStringRef.buffer");
  memmove(v7, i_str_ref_p->i_cstr_p, (unsigned int)i_length);
  *((_BYTE *)v7 + i_length) = 0;
  i_ref_count = i_str_ref_p->i_ref_count;
  if ( i_ref_count == 1 )
  {
    if ( i_str_ref_p->i_deallocate )
      AMemory::c_free_func(i_str_ref_p->i_cstr_p);
    i_str_ref_p->i_cstr_p = (char *)v7;
    i_str_ref_p->i_size = v5;
    *(_WORD *)&i_str_ref_p->i_deallocate = 1;
  }
  else
  {
    v9 = i_ref_count - 1;
    i_str_ref_p->i_ref_count = v9;
    if ( !v9 )
      AStringRef::pool_delete(i_str_ref_p);
    this->i_str_ref_p = AStringRef::pool_new((char *)v7, i_length, v5, 1u, 1, 0);
  }
}

// File Line: 3601
// RVA: 0x226BA0
void __fastcall AString::set_size_buffer(AString *this, unsigned int needed_chars)
{
  AStringRef *i_str_ref_p; // rbx
  unsigned __int64 v4; // rdi
  char *v5; // rax
  char *v6; // rax

  i_str_ref_p = this->i_str_ref_p;
  v4 = AMemory::c_req_byte_size_func(needed_chars + 1);
  if ( i_str_ref_p->i_ref_count == 1 )
  {
    if ( i_str_ref_p->i_deallocate )
      AMemory::c_free_func(i_str_ref_p->i_cstr_p);
    v5 = (char *)AMemory::c_malloc_func(v4, "AStringRef.buffer");
    i_str_ref_p->i_size = v4;
    *(_WORD *)&i_str_ref_p->i_deallocate = 1;
    i_str_ref_p->i_cstr_p = v5;
  }
  else
  {
    AStringRef::dereference(i_str_ref_p);
    v6 = (char *)AMemory::c_malloc_func(v4, "AStringRef.buffer");
    this->i_str_ref_p = AStringRef::pool_new(v6, 0, v4, 1u, 1, 0);
  }
}

// File Line: 3728
// RVA: 0x225640
void AString::init_match_table(void)
{
  bool (*v0)[256]; // rdi
  __int128 *v1; // rbx
  _OWORD *v2; // rcx
  bool (*v3)[256]; // rdx
  __int64 v4; // rsi
  __int64 v5; // rax
  __int128 v6; // xmm0
  _OWORD *v7; // rcx
  __int64 v8; // rax
  __int128 v9; // xmm0
  _OWORD *v10; // rcx
  __int64 v11; // rax
  __int128 v12; // xmm0
  __int128 *v13; // rdi
  __int128 *v14; // rbx
  _OWORD *v15; // rcx
  __int128 *v16; // rdx
  __int64 v17; // rax
  __int128 v18; // xmm0
  _OWORD *v19; // rcx
  __int64 v20; // rax
  __int128 v21; // xmm0
  _BYTE *v22; // rcx
  __int128 v23; // xmm0

  v0 = AString::c_char_match_table;
  memset(AString::c_char_match_table, 0, 0xB00ui64);
  v1 = (__int128 *)&unk_14236E3C0;
  qword_14236E301 = 0x101010101010101i64;
  qword_14236E309 = 0x101010101010101i64;
  qword_14236E311 = 0x101010101010101i64;
  word_14236E319 = 257;
  qword_14236E321 = 0x101010101010101i64;
  qword_14236E329 = 0x101010101010101i64;
  qword_14236E331 = 0x101010101010101i64;
  word_14236E339 = 257;
  byte_14236E34A = 1;
  byte_14236E34C = 1;
  byte_14236E35A = 1;
  byte_14236E35C = 1;
  byte_14236E35F = 1;
  qword_14236E380 = 0x101010101010101i64;
  qword_14236E388 = 0x101010101010101i64;
  dword_14236E390 = 16843009;
  word_14236E394 = 257;
  byte_14236E396 = 1;
  dword_14236E398 = 16843009;
  word_14236E39C = 257;
  qword_14236E3A0 = 0x101010101010101i64;
  qword_14236E3A8 = 0x101010101010101i64;
  dword_14236E3B0 = 16843009;
  word_14236E3B4 = 257;
  byte_14236E3B6 = 1;
  dword_14236E3B8 = 16843009;
  word_14236E3BC = 257;
  byte_14236E3BF = 1;
  v2 = &unk_14236E3C0;
  v3 = AString::c_char_match_table;
  v4 = 2i64;
  if ( (((unsigned __int8)&unk_14236E3C0 | (unsigned __int8)AString::c_char_match_table) & 0xF) != 0 )
  {
    memmove(&unk_14236E3C0, AString::c_char_match_table, 0x100ui64);
  }
  else
  {
    v5 = 2i64;
    do
    {
      v6 = *(_OWORD *)v3;
      v2 += 8;
      v3 = (bool (*)[256])((char *)v3 + 128);
      *(v2 - 8) = v6;
      *(v2 - 7) = *(_OWORD *)&(*v3)[-112];
      *(v2 - 6) = *(_OWORD *)&(*v3)[-96];
      *(v2 - 5) = *(_OWORD *)&(*v3)[-80];
      *(v2 - 4) = *(_OWORD *)&(*v3)[-64];
      *(v2 - 3) = *(_OWORD *)&(*v3)[-48];
      *(v2 - 2) = *(_OWORD *)&(*v3)[-32];
      *(v2 - 1) = *(_OWORD *)&(*v3)[-16];
      --v5;
    }
    while ( v5 );
  }
  v7 = &unk_14236E4C0;
  qword_14236E3F0 = 0x101010101010101i64;
  word_14236E3F8 = 257;
  if ( (((unsigned __int8)&unk_14236E4C0 | (unsigned __int8)AString::c_char_match_table) & 0xF) != 0 )
  {
    memmove(&unk_14236E4C0, AString::c_char_match_table, 0x100ui64);
  }
  else
  {
    v8 = 2i64;
    do
    {
      v9 = *(_OWORD *)v0;
      v7 += 8;
      v0 = (bool (*)[256])((char *)v0 + 128);
      *(v7 - 8) = v9;
      *(v7 - 7) = *(_OWORD *)&(*v0)[-112];
      *(v7 - 6) = *(_OWORD *)&(*v0)[-96];
      *(v7 - 5) = *(_OWORD *)&(*v0)[-80];
      *(v7 - 4) = *(_OWORD *)&(*v0)[-64];
      *(v7 - 3) = *(_OWORD *)&(*v0)[-48];
      *(v7 - 2) = *(_OWORD *)&(*v0)[-32];
      *(v7 - 1) = *(_OWORD *)&(*v0)[-16];
      --v8;
    }
    while ( v8 );
  }
  v10 = &unk_14236E6C0;
  byte_14236E51F = 1;
  qword_14236E5F0 = 0x101010101010101i64;
  word_14236E5F8 = 257;
  if ( (((unsigned __int8)&unk_14236E6C0 | (unsigned __int8)&unk_14236E3C0) & 0xF) != 0 )
  {
    memmove(&unk_14236E6C0, &unk_14236E3C0, 0x100ui64);
  }
  else
  {
    v11 = 2i64;
    do
    {
      v12 = *v1;
      v10 += 8;
      v1 += 8;
      *(v10 - 8) = v12;
      *(v10 - 7) = *(v1 - 7);
      *(v10 - 6) = *(v1 - 6);
      *(v10 - 5) = *(v1 - 5);
      *(v10 - 4) = *(v1 - 4);
      *(v10 - 3) = *(v1 - 3);
      *(v10 - 2) = *(v1 - 2);
      *(v10 - 1) = *(v1 - 1);
      --v11;
    }
    while ( v11 );
  }
  byte_14236E71F = 1;
  qword_14236E821 = 0x101010101010101i64;
  qword_14236E829 = 0x101010101010101i64;
  qword_14236E831 = 0x101010101010101i64;
  word_14236E839 = 257;
  byte_14236E85A = 1;
  byte_14236E85C = 1;
  qword_14236E8A0 = 0x101010101010101i64;
  qword_14236E8A8 = 0x101010101010101i64;
  dword_14236E8B0 = 16843009;
  word_14236E8B4 = 257;
  byte_14236E8B6 = 1;
  dword_14236E8B8 = 16843009;
  word_14236E8BC = 257;
  byte_14236E8BF = 1;
  word_14236E8E1 = 257;
  word_14236E8E7 = 257;
  byte_14236E8E9 = 1;
  word_14236E8EC = 257;
  byte_14236E8EE = 1;
  word_14236E8FA = 257;
  byte_14236E8FF = 1;
  byte_14236E91B = 1;
  byte_14236E91D = 1;
  byte_14236E93B = 1;
  byte_14236E93D = 1;
  byte_14236E942 = 1;
  word_14236E944 = 257;
  dword_14236E951 = 16843009;
  dword_14236E9E3 = 16843009;
  word_14236E9EA = 257;
  byte_14236E9ED = 1;
  byte_14236E9EF = 1;
  word_14236E9FC = 257;
  byte_14236E9FE = 1;
  byte_14236EA00 = 1;
  byte_14236EA1C = 1;
  word_14236EA1E = 257;
  byte_14236EA20 = 1;
  byte_14236EA3C = 1;
  byte_14236EA3E = 1;
  byte_14236EA43 = 1;
  dword_14236EA46 = 16843009;
  byte_14236EA4B = 1;
  dword_14236EA55 = 16843009;
  byte_14236EA59 = 1;
  byte_14236EA5B = 1;
  qword_14236EA61 = 0x101010101010101i64;
  qword_14236EA69 = 0x101010101010101i64;
  qword_14236EA71 = 0x101010101010101i64;
  dword_14236EA79 = 16843009;
  word_14236EA7D = 257;
  byte_14236EA7F = 1;
  byte_14236EA97 = 1;
  word_14236EA9E = 257;
  byte_14236EAB7 = 1;
  byte_14236EABE = 1;
  qword_14236EAE1 = 0x101010101010101i64;
  dword_14236EAE9 = 16843009;
  word_14236EAED = 257;
  byte_14236EAEF = 1;
  dword_14236EAFA = 16843009;
  word_14236EAFE = 257;
  byte_14236EB00 = 1;
  dword_14236EB1B = 16843009;
  word_14236EB1F = 257;
  dword_14236EB3B = 16843009;
  qword_14236EB42 = 0x101010101010101i64;
  byte_14236EB4B = 1;
  qword_14236EB51 = 0x101010101010101i64;
  byte_14236EB59 = 1;
  byte_14236EB5B = 1;
  qword_14236EB61 = 0x101010101010101i64;
  qword_14236EB69 = 0x101010101010101i64;
  qword_14236EB71 = 0x101010101010101i64;
  dword_14236EB79 = 16843009;
  word_14236EB7D = 257;
  byte_14236EB7F = 1;
  byte_14236EB97 = 1;
  word_14236EB9E = 257;
  byte_14236EBB7 = 1;
  byte_14236EBBE = 1;
  qword_14236EC01 = 0x101010101010101i64;
  qword_14236EC09 = 0x101010101010101i64;
  qword_14236EC11 = 0x101010101010101i64;
  word_14236EC19 = 257;
  byte_14236EC4A = 1;
  byte_14236EC4C = 1;
  byte_14236EC5F = 1;
  qword_14236EC80 = 0x101010101010101i64;
  qword_14236EC88 = 0x101010101010101i64;
  dword_14236EC90 = 16843009;
  word_14236EC94 = 257;
  byte_14236EC96 = 1;
  dword_14236EC98 = 16843009;
  word_14236EC9C = 257;
  dword_14236ECC9 = 16843009;
  byte_14236ECCD = 1;
  byte_14236ECE0 = 1;
  memset(&unk_14236EDC0, 1, 0xB00ui64);
  v13 = (__int128 *)&unk_14236EDC0;
  qword_14236EE01 = 0i64;
  qword_14236EE09 = 0i64;
  qword_14236EE11 = 0i64;
  word_14236EE19 = 0;
  qword_14236EE21 = 0i64;
  qword_14236EE29 = 0i64;
  qword_14236EE31 = 0i64;
  word_14236EE39 = 0;
  byte_14236EE4A = 0;
  byte_14236EE4C = 0;
  byte_14236EE5A = 0;
  byte_14236EE5C = 0;
  byte_14236EE5F = 0;
  qword_14236EE80 = 0i64;
  qword_14236EE88 = 0i64;
  dword_14236EE90 = 0;
  word_14236EE94 = 0;
  byte_14236EE96 = 0;
  dword_14236EE98 = 0;
  word_14236EE9C = 0;
  qword_14236EEA0 = 0i64;
  qword_14236EEA8 = 0i64;
  dword_14236EEB0 = 0;
  word_14236EEB4 = 0;
  byte_14236EEB6 = 0;
  dword_14236EEB8 = 0;
  word_14236EEBC = 0;
  byte_14236EEBF = 0;
  v14 = (__int128 *)&unk_14236EEC0;
  v15 = &unk_14236EEC0;
  v16 = (__int128 *)&unk_14236EDC0;
  if ( (((unsigned __int8)&unk_14236EEC0 | (unsigned __int8)&unk_14236EDC0) & 0xF) != 0 )
  {
    memmove(&unk_14236EEC0, &unk_14236EDC0, 0x100ui64);
  }
  else
  {
    v17 = 2i64;
    do
    {
      v18 = *v16;
      v15 += 8;
      v16 += 8;
      *(v15 - 8) = v18;
      *(v15 - 7) = *(v16 - 7);
      *(v15 - 6) = *(v16 - 6);
      *(v15 - 5) = *(v16 - 5);
      *(v15 - 4) = *(v16 - 4);
      *(v15 - 3) = *(v16 - 3);
      *(v15 - 2) = *(v16 - 2);
      *(v15 - 1) = *(v16 - 1);
      --v17;
    }
    while ( v17 );
  }
  v19 = &unk_14236EFC0;
  qword_14236EEF0 = 0i64;
  word_14236EEF8 = 0;
  if ( (((unsigned __int8)&unk_14236EFC0 | (unsigned __int8)&unk_14236EDC0) & 0xF) != 0 )
  {
    memmove(&unk_14236EFC0, &unk_14236EDC0, 0x100ui64);
  }
  else
  {
    v20 = 2i64;
    do
    {
      v21 = *v13;
      v19 += 8;
      v13 += 8;
      *(v19 - 8) = v21;
      *(v19 - 7) = *(v13 - 7);
      *(v19 - 6) = *(v13 - 6);
      *(v19 - 5) = *(v13 - 5);
      *(v19 - 4) = *(v13 - 4);
      *(v19 - 3) = *(v13 - 3);
      *(v19 - 2) = *(v13 - 2);
      *(v19 - 1) = *(v13 - 1);
      --v20;
    }
    while ( v20 );
  }
  v22 = byte_14236F1C0;
  byte_14236F01F = 0;
  qword_14236F0F0 = 0i64;
  word_14236F0F8 = 0;
  if ( (((unsigned __int8)byte_14236F1C0 | (unsigned __int8)&unk_14236EEC0) & 0xF) != 0 )
  {
    memmove(byte_14236F1C0, &unk_14236EEC0, 0x100ui64);
  }
  else
  {
    do
    {
      v23 = *v14;
      v22 += 128;
      v14 += 8;
      *((_OWORD *)v22 - 8) = v23;
      *((_OWORD *)v22 - 7) = *(v14 - 7);
      *((_OWORD *)v22 - 6) = *(v14 - 6);
      *((_OWORD *)v22 - 5) = *(v14 - 5);
      *((_OWORD *)v22 - 4) = *(v14 - 4);
      *((_OWORD *)v22 - 3) = *(v14 - 3);
      *((_OWORD *)v22 - 2) = *(v14 - 2);
      *((_OWORD *)v22 - 1) = *(v14 - 1);
      --v4;
    }
    while ( v4 );
  }
  byte_14236F21F = 0;
  qword_14236F321 = 0i64;
  qword_14236F329 = 0i64;
  qword_14236F331 = 0i64;
  word_14236F339 = 0;
  byte_14236F35A = 0;
  byte_14236F35C = 0;
  qword_14236F3A0 = 0i64;
  qword_14236F3A8 = 0i64;
  dword_14236F3B0 = 0;
  word_14236F3B4 = 0;
  byte_14236F3B6 = 0;
  dword_14236F3B8 = 0;
  word_14236F3BC = 0;
  byte_14236F3BF = 0;
  word_14236F3E1 = 0;
  word_14236F3E7 = 0;
  byte_14236F3E9 = 0;
  word_14236F3EC = 0;
  byte_14236F3EE = 0;
  word_14236F3FA = 0;
  byte_14236F3FF = 0;
  byte_14236F41B = 0;
  byte_14236F41D = 0;
  byte_14236F43B = 0;
  byte_14236F43D = 0;
  byte_14236F442 = 0;
  word_14236F444 = 0;
  dword_14236F451 = 0;
  dword_14236F4E3 = 0;
  word_14236F4EA = 0;
  byte_14236F4ED = 0;
  byte_14236F4EF = 0;
  word_14236F4FC = 0;
  byte_14236F4FE = 0;
  byte_14236F500 = 0;
  byte_14236F51C = 0;
  word_14236F51E = 0;
  byte_14236F520 = 0;
  byte_14236F53C = 0;
  byte_14236F53E = 0;
  byte_14236F543 = 0;
  dword_14236F546 = 0;
  byte_14236F54B = 0;
  dword_14236F555 = 0;
  byte_14236F559 = 0;
  byte_14236F55B = 0;
  qword_14236F561 = 0i64;
  qword_14236F569 = 0i64;
  qword_14236F571 = 0i64;
  dword_14236F579 = 0;
  word_14236F57D = 0;
  byte_14236F57F = 0;
  byte_14236F597 = 0;
  word_14236F59E = 0;
  byte_14236F5B7 = 0;
  byte_14236F5BE = 0;
  qword_14236F5E1 = 0i64;
  dword_14236F5E9 = 0;
  word_14236F5ED = 0;
  byte_14236F5EF = 0;
  dword_14236F5FA = 0;
  word_14236F5FE = 0;
  byte_14236F600 = 0;
  dword_14236F61B = 0;
  word_14236F61F = 0;
  dword_14236F63B = 0;
  qword_14236F642 = 0i64;
  byte_14236F64B = 0;
  qword_14236F651 = 0i64;
  byte_14236F659 = 0;
  byte_14236F65B = 0;
  qword_14236F661 = 0i64;
  qword_14236F669 = 0i64;
  qword_14236F671 = 0i64;
  dword_14236F679 = 0;
  word_14236F67D = 0;
  byte_14236F67F = 0;
  byte_14236F697 = 0;
  word_14236F69E = 0;
  byte_14236F6B7 = 0;
  byte_14236F6BE = 0;
  qword_14236F701 = 0i64;
  qword_14236F709 = 0i64;
  qword_14236F711 = 0i64;
  word_14236F719 = 0;
  byte_14236F74A = 0;
  byte_14236F74C = 0;
  byte_14236F75F = 0;
  qword_14236F780 = 0i64;
  qword_14236F788 = 0i64;
  dword_14236F790 = 0;
  word_14236F794 = 0;
  byte_14236F796 = 0;
  dword_14236F798 = 0;
  word_14236F79C = 0;
  dword_14236F7C9 = 0;
  byte_14236F7CD = 0;
  byte_14236F7E0 = 0;
}

