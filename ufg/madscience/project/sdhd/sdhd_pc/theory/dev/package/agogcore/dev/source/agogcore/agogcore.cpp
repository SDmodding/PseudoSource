// File Line: 95
// RVA: 0x223620
void __fastcall AgogCoreVals::AgogCoreVals(AgogCoreVals *this)
{
  this->i_using_defaults = 1;
  this->i_pool_init_datum = 256;
  this->i_pool_incr_datum = 64;
  this->i_pool_init_string_ref = 40960;
  this->i_pool_incr_string_ref = 256;
  this->i_pool_init_symbol_ref = 2048;
  this->i_pool_incr_symbol_ref = 256;
}

// File Line: 108
// RVA: 0x146F6C0
__int64 dynamic_initializer_for__AString::c_empty__()
{
  if ( !(_S2_8 & 1) )
  {
    _S2_8 |= 1u;
    s_empty.i_cstr_p = &customWorldMapCaption;
    s_empty.i_length = 0;
    s_empty.i_size = 1;
    *(_DWORD *)&s_empty.i_ref_count = 16777218;
  }
  AString::c_empty.i_str_ref_p = &s_empty;
  ++s_empty.i_ref_count;
  return atexit(dynamic_atexit_destructor_for__AString::c_empty__);
}

// File Line: 109
// RVA: 0x146F550
__int64 dynamic_initializer_for__AString::c_comma__()
{
  AObjReusePool<AStringRef> *v0; // rax
  AObjReusePool<AStringRef> *v1; // rbx
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  __int64 v5; // rcx
  AStringRef **v6; // rax
  AStringRef *v7; // rdx
  unsigned int v8; // eax

  v0 = AStringRef::get_pool();
  v1 = v0;
  v2 = v0->i_pool.i_count;
  if ( v2 )
  {
    v8 = v2 - 1;
    v1->i_pool.i_count = v8;
    v5 = v8;
    v6 = v1->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !v1->i_exp_pool.i_count )
    AObjReusePool<AStringRef>::append_block(v1, v1->i_expand_size);
  v3 = v1->i_exp_pool.i_count;
  if ( v3 )
  {
    v4 = v3 - 1;
    v1->i_exp_pool.i_count = v4;
    v5 = v4;
    v6 = v1->i_exp_pool.i_array_p;
LABEL_8:
    v7 = v6[v5];
    goto LABEL_9;
  }
  v7 = 0i64;
LABEL_9:
  v7->i_size = 2;
  *(_DWORD *)&v7->i_ref_count = 16777217;
  v7->i_cstr_p = ",";
  v7->i_length = 1;
  AString::c_comma.i_str_ref_p = v7;
  return atexit(dynamic_atexit_destructor_for__AString::c_comma__);
}

// File Line: 110
// RVA: 0x146F630
__int64 dynamic_initializer_for__AString::c_dos_break__()
{
  AObjReusePool<AStringRef> *v0; // rax
  AObjReusePool<AStringRef> *v1; // rbx
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  __int64 v5; // rcx
  AStringRef **v6; // rax
  AStringRef *v7; // rdx
  unsigned int v8; // eax

  v0 = AStringRef::get_pool();
  v1 = v0;
  v2 = v0->i_pool.i_count;
  if ( v2 )
  {
    v8 = v2 - 1;
    v1->i_pool.i_count = v8;
    v5 = v8;
    v6 = v1->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !v1->i_exp_pool.i_count )
    AObjReusePool<AStringRef>::append_block(v1, v1->i_expand_size);
  v3 = v1->i_exp_pool.i_count;
  if ( v3 )
  {
    v4 = v3 - 1;
    v1->i_exp_pool.i_count = v4;
    v5 = v4;
    v6 = v1->i_exp_pool.i_array_p;
LABEL_8:
    v7 = v6[v5];
    goto LABEL_9;
  }
  v7 = 0i64;
LABEL_9:
  v7->i_length = 2;
  v7->i_size = 3;
  *(_DWORD *)&v7->i_ref_count = 16777217;
  v7->i_cstr_p = "\r\n";
  AString::c_dos_break.i_str_ref_p = v7;
  return atexit(dynamic_atexit_destructor_for__AString::c_dos_break__);
}

// File Line: 111
// RVA: 0x146F5E0
__int64 dynamic_initializer_for__AString::c_construct_destruct__()
{
  if ( AString::init_match_table )
    AString::init_match_table();
  return atexit(dynamic_atexit_destructor_for__AString::c_construct_destruct__);
}

// File Line: 232
// RVA: 0x146F770
__int64 dynamic_initializer_for__ASymbol::c_null__()
{
  return atexit(dynamic_atexit_destructor_for__ASymbol::c_null__);
}

// File Line: 250
// RVA: 0x146F740
__int64 dynamic_initializer_for__ARandom::c_gen__()
{
  __int64 result; // rax

  result = 1664525 * (unsigned int)time64(0i64) + 1013904223;
  ARandom::c_gen.i_seed = result;
  return result;
}

// File Line: 288
// RVA: 0x223810
char *a_cstr_format(const char *format_cstr_p, ...)
{
  bool v1; // zf
  char v2; // al
  va_list ap; // [rsp+38h] [rbp+10h]

  va_start(ap, format_cstr_p);
  v1 = ((vsnprintf(`anonymous namespace'::g_cstr_p, 0x3FFui64, format_cstr_p, ap) + 1) & 0xFFFFFBFF) == 0;
  v2 = `anonymous namespace'::g_cstr_p[1023];
  if ( v1 )
    v2 = 0;
  `anonymous namespace'::g_cstr_p[1023] = v2;
  return `anonymous namespace'::g_cstr_p;
}

// File Line: 335
// RVA: 0x223870
AString *a_str_format(AString *result, const char *format_cstr_p, ...)
{
  AString *v2; // rbx
  unsigned int v3; // eax
  va_list va; // [rsp+60h] [rbp+18h]

  va_start(va, format_cstr_p);
  v2 = result;
  v3 = vsnprintf(`anonymous namespace'::g_cstr_p, 0x3FFui64, format_cstr_p, va);
  if ( v3 == -1 )
  {
    v3 = 1023;
    `anonymous namespace'::g_cstr_p[1023] = 0;
  }
  AString::AString(v2, `anonymous namespace'::g_cstr_p, 0x400u, v3, 0);
  return v2;
}

