// File Line: 65
// RVA: 0x146F7A0
__int64 anonymous_namespace_::_dynamic_initializer_for__g_dprint_funcs__()
{
  return atexit((int (__fastcall *)())anonymous_namespace_::_dynamic_atexit_destructor_for__g_dprint_funcs__);
}

// File Line: 66
// RVA: 0x146F780
__int64 anonymous_namespace_::_dynamic_initializer_for__g_context_funcs__()
{
  return atexit((int (__fastcall *)())anonymous_namespace_::_dynamic_atexit_destructor_for__g_context_funcs__);
}

// File Line: 124
// RVA: 0x223310
void __fastcall AErrMsg::AErrMsg(
        AErrMsg *this,
        const char *desc_high_p,
        eAErrLevel err_level,
        const char *title_p,
        const char *desc_low_p)
{
  this->i_title_p = title_p;
  this->i_desc_high_p = desc_high_p;
  this->i_desc_low_p = desc_low_p;
  this->i_err_level = err_level;
  this->i_func_name_p = 0i64;
  this->i_source_path_p = 0i64;
  this->i_source_line = 0;
  this->i_err_id = 1;
}

// File Line: 148
// RVA: 0x2232C0
void __fastcall AErrMsg::AErrMsg(
        AErrMsg *this,
        AErrMsg *err_msg,
        const char *desc_low_p,
        const char *func_name_p,
        const char *source_path_p,
        unsigned int source_line,
        unsigned int err_id)
{
  eAErrLevel i_err_level; // eax

  this->i_title_p = err_msg->i_title_p;
  this->i_desc_high_p = err_msg->i_desc_high_p;
  if ( err_msg->i_desc_low_p )
    desc_low_p = err_msg->i_desc_low_p;
  this->i_desc_low_p = desc_low_p;
  i_err_level = err_msg->i_err_level;
  this->i_func_name_p = func_name_p;
  this->i_err_level = i_err_level;
  this->i_err_id = err_id;
  this->i_source_path_p = source_path_p;
  this->i_source_line = source_line;
}

// File Line: 166
// RVA: 0x223730
void __fastcall AErrorOutputBase::~AErrorOutputBase(AErrorOutputBase *this)
{
  this->vfptr = (AErrorOutputBaseVtbl *)&AErrorOutputBase::`vftable;
}

// File Line: 186
// RVA: 0x225560
void ADebug::info(void)
{
  AFunctionArgBase<AString const &> **i_array_p; // rbx
  AFunctionArgBase<AString const &> **v1; // rdi
  AStringRef *v2; // rcx
  AMD_HD3D str_p; // [rsp+40h] [rbp+8h] BYREF

  if ( (_S2_8 & 1) == 0 )
  {
    _S2_8 |= 1u;
    s_empty.i_cstr_p = &customCaption;
    s_empty.i_length = 0;
    s_empty.i_size = 1;
    *(_DWORD *)&s_empty.i_ref_count = 16777218;
  }
  *(_QWORD *)&str_p.mEnableStereo = &s_empty;
  ++s_empty.i_ref_count;
  if ( ADebug::context_append((AString *)&str_p) )
  {
    _(&str_p);
    if ( `anonymous namespace::g_dprint_funcs.i_count )
    {
      i_array_p = `anonymous namespace::g_dprint_funcs.i_array_p;
      v1 = &`anonymous namespace::g_dprint_funcs.i_array_p[`anonymous namespace::g_dprint_funcs.i_count];
      if ( `anonymous namespace::g_dprint_funcs.i_array_p < v1 )
      {
        do
        {
          (*i_array_p)->vfptr->invoke(*i_array_p, (AString *)&str_p);
          ++i_array_p;
        }
        while ( i_array_p < v1 );
      }
    }
  }
  v2 = *(AStringRef **)&str_p.mEnableStereo;
  if ( (*(_WORD *)(*(_QWORD *)&str_p.mEnableStereo + 16i64))-- == 1 )
    AStringRef::pool_delete(v2);
}

// File Line: 203
// RVA: 0x2243B0
char __fastcall ADebug::context_append(AString *str_p)
{
  AFunctionArgBase<AString *> **i_array_p; // rbx
  __int64 i_length; // rbp
  AFunctionArgBase<AString *> **v4; // rsi
  AStringRef *i_str_ref_p; // rax
  unsigned int v6; // ecx

  if ( !`anonymous namespace::g_context_funcs.i_count )
    return 0;
  i_array_p = `anonymous namespace::g_context_funcs.i_array_p;
  i_length = str_p->i_str_ref_p->i_length;
  v4 = &`anonymous namespace::g_context_funcs.i_array_p[`anonymous namespace::g_context_funcs.i_count];
  if ( `anonymous namespace::g_context_funcs.i_array_p < v4 )
  {
    do
    {
      (*i_array_p)->vfptr->invoke(*i_array_p, str_p);
      ++i_array_p;
    }
    while ( i_array_p < v4 );
  }
  i_str_ref_p = str_p->i_str_ref_p;
  v6 = str_p->i_str_ref_p->i_length;
  if ( v6 <= (unsigned int)i_length )
    return 0;
  if ( v6 + 1 >= i_str_ref_p->i_size || i_str_ref_p->i_ref_count + i_str_ref_p->i_read_only != 1 )
    AString::set_size(str_p, v6 + 1);
  memmove(
    &str_p->i_str_ref_p->i_cstr_p[i_length + 1],
    &str_p->i_str_ref_p->i_cstr_p[i_length],
    (unsigned int)(str_p->i_str_ref_p->i_length - i_length + 1));
  str_p->i_str_ref_p->i_cstr_p[i_length] = 10;
  ++str_p->i_str_ref_p->i_length;
  return 1;
}

// File Line: 239
// RVA: 0x224490
AString *__fastcall ADebug::context_string(AString *result)
{
  if ( (_S2_8 & 1) == 0 )
  {
    _S2_8 |= 1u;
    s_empty.i_cstr_p = &customCaption;
    s_empty.i_length = 0;
    s_empty.i_size = 1;
    *(_DWORD *)&s_empty.i_ref_count = 16777218;
  }
  result->i_str_ref_p = &s_empty;
  ++s_empty.i_ref_count;
  ADebug::context_append(result);
  return result;
}

// File Line: 262
// RVA: 0x226590
void __fastcall ADebug::print(AMD_HD3D *str, bool call_print_funcs_b)
{
  __int64 i_count; // rax
  AFunctionArgBase<AString const &> **i_array_p; // rbx
  AFunctionArgBase<AString const &> **v6; // rdi

  _(str);
  i_count = 0i64;
  if ( call_print_funcs_b )
    i_count = `anonymous namespace::g_dprint_funcs.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = `anonymous namespace::g_dprint_funcs.i_array_p;
    v6 = &`anonymous namespace::g_dprint_funcs.i_array_p[i_count];
    if ( `anonymous namespace::g_dprint_funcs.i_array_p < v6 )
    {
      do
      {
        (*i_array_p)->vfptr->invoke(*i_array_p, (AString *)str);
        ++i_array_p;
      }
      while ( i_array_p < v6 );
    }
  }
}

// File Line: 297
// RVA: 0x226600
void __fastcall ADebug::print(char *cstr_p, bool call_print_funcs_b)
{
  __int64 v4; // rbx
  __int64 v5; // rdi
  unsigned int v6; // eax
  AStringRef *v7; // rcx
  bool v8; // zf
  __int64 i_count; // rdi
  unsigned int v10; // eax
  AFunctionArgBase<AString const &> **i_array_p; // rbx
  AFunctionArgBase<AString const &> **v12; // rdi
  AStringRef *v13; // rcx
  AStringRef *v14; // [rsp+70h] [rbp+18h] BYREF

  v4 = -1i64;
  v5 = -1i64;
  do
    ++v5;
  while ( cstr_p[v5] );
  v6 = AMemory::c_req_byte_size_func(v5 + 1);
  v14 = AStringRef::pool_new(cstr_p, v5, v6, 1u, 0, 1);
  _((AMD_HD3D *)&v14);
  v7 = v14;
  v8 = v14->i_ref_count-- == 1;
  if ( v8 )
    AStringRef::pool_delete(v7);
  i_count = 0i64;
  if ( call_print_funcs_b )
    i_count = `anonymous namespace::g_dprint_funcs.i_count;
  if ( (_DWORD)i_count )
  {
    do
      ++v4;
    while ( cstr_p[v4] );
    v10 = AMemory::c_req_byte_size_func(v4 + 1);
    v14 = AStringRef::pool_new(cstr_p, v4, v10, 1u, 0, 1);
    i_array_p = `anonymous namespace::g_dprint_funcs.i_array_p;
    v12 = &`anonymous namespace::g_dprint_funcs.i_array_p[i_count];
    if ( `anonymous namespace::g_dprint_funcs.i_array_p < v12 )
    {
      do
      {
        (*i_array_p)->vfptr->invoke(*i_array_p, (AString *)&v14);
        ++i_array_p;
      }
      while ( i_array_p < v12 );
    }
    v13 = v14;
    v8 = v14->i_ref_count-- == 1;
    if ( v8 )
      AStringRef::pool_delete(v13);
  }
}

// File Line: 343
// RVA: 0x226720
void __fastcall ADebug::print_args(const char *format_cstr_p, char *args)
{
  int v2; // eax
  __int64 v3; // rbx
  char v4; // cl
  __int64 v5; // rdi
  AObjReusePool<AStringRef> *pool; // rsi
  unsigned int i_count; // eax
  unsigned int v8; // eax
  __int64 v9; // rcx
  AStringRef **i_array_p; // rax
  unsigned int v11; // eax
  AFunctionArgBase<AString const &> **v12; // rbx
  AFunctionArgBase<AString const &> **v13; // rdi
  AStringRef *v14; // rcx
  char string[2047]; // [rsp+30h] [rbp-808h] BYREF
  char v17; // [rsp+82Fh] [rbp-9h]
  AStringRef *v18; // [rsp+850h] [rbp+18h] BYREF

  v2 = vsnprintf(string, 0x7FFui64, format_cstr_p, args);
  LODWORD(v3) = v2;
  v4 = v17;
  v5 = 0i64;
  if ( ((v2 + 1) & 0xFFFFF7FF) == 0 )
    v4 = 0;
  v17 = v4;
  if ( v2 == -1 )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( string[v3] );
  }
  pool = AStringRef::get_pool();
  if ( pool->i_pool.i_count )
  {
    v11 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v11;
    v9 = v11;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_12;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<AStringRef>::append_block(pool, pool->i_expand_size);
  i_count = pool->i_exp_pool.i_count;
  if ( i_count )
  {
    v8 = i_count - 1;
    pool->i_exp_pool.i_count = v8;
    v9 = v8;
    i_array_p = pool->i_exp_pool.i_array_p;
LABEL_12:
    v5 = (__int64)i_array_p[v9];
  }
  *(_QWORD *)v5 = string;
  *(_DWORD *)(v5 + 8) = v3;
  *(_DWORD *)(v5 + 12) = v3 + 1;
  *(_DWORD *)(v5 + 16) = 16777217;
  v18 = (AStringRef *)v5;
  _((AMD_HD3D *)&v18);
  if ( `anonymous namespace::g_dprint_funcs.i_count )
  {
    v12 = `anonymous namespace::g_dprint_funcs.i_array_p;
    v13 = &`anonymous namespace::g_dprint_funcs.i_array_p[`anonymous namespace::g_dprint_funcs.i_count];
    if ( `anonymous namespace::g_dprint_funcs.i_array_p < v13 )
    {
      do
      {
        (*v12)->vfptr->invoke(*v12, (AString *)&v18);
        ++v12;
      }
      while ( v12 < v13 );
    }
  }
  v14 = v18;
  if ( v18->i_ref_count-- == 1 )
    AStringRef::pool_delete(v14);
}

// File Line: 400
// RVA: 0x226860
void ADebug::print_format(const char *format_cstr_p, ...)
{
  va_list args; // [rsp+38h] [rbp+10h] BYREF

  va_start(args, format_cstr_p);
  ADebug::print_args(format_cstr_p, args);
}

// File Line: 494
// RVA: 0x226950
_BOOL8 __fastcall ADebug::resolve_error(AErrMsg *msg, eAErrAction *action_p, bool *test_again_p)
{
  bool v6; // bl
  AErrorOutputBase *v7; // rax
  bool v8; // al
  __int64 v9; // rcx
  bool v10; // bl
  AMD_HD3D *v11; // rcx
  eAErrAction action_pa; // [rsp+38h] [rbp+10h] BYREF

  v6 = std::uncaught_exception();
  v7 = Agog::on_error_pre(v6);
  if ( !v7 || v6 )
    v8 = ADebug::determine_choice(msg, &action_pa);
  else
    v8 = v7->vfptr->determine_choice(v7, msg, &action_pa);
  v9 = (unsigned int)action_pa;
  v10 = v8;
  if ( action_pa == AErrAction_ignore_all )
  {
    if ( test_again_p )
      *test_again_p = 0;
    v9 = 3i64;
    action_pa = AErrAction_ignore;
  }
  if ( action_p )
    *action_p = v9;
  _((AMD_HD3D *)v9);
  if ( action_pa == AErrAction_quit )
    _(v11);
  return v10;
}

// File Line: 541
// RVA: 0x224AB0
bool __fastcall ADebug::determine_choice(AErrMsg *msg, eAErrAction *action_p)
{
  bool v4; // al
  eAErrAction v5; // ecx
  const char *i_source_path_p; // r10
  char *i_func_name_p; // r9
  char *i_title_p; // rdx
  char *i_desc_low_p; // rcx
  const char *i_desc_high_p; // r8

  v4 = std::uncaught_exception();
  if ( v4 || msg->i_err_level <= AErrLevel_notify )
    v5 = AErrAction_ignore;
  else
    v5 = AErrAction_quit;
  *action_p = v5;
  if ( v4 )
    ADebug::print("### Had another exception while a previous exception is being handled: ###", 1);
  i_source_path_p = msg->i_source_path_p;
  i_func_name_p = &customCaption;
  i_title_p = &customCaption;
  i_desc_low_p = &customCaption;
  if ( msg->i_title_p )
    i_title_p = (char *)msg->i_title_p;
  i_desc_high_p = "An error has occurred.";
  if ( msg->i_desc_high_p )
    i_desc_high_p = msg->i_desc_high_p;
  if ( msg->i_desc_low_p )
    i_desc_low_p = (char *)msg->i_desc_low_p;
  if ( msg->i_func_name_p )
    i_func_name_p = (char *)msg->i_func_name_p;
  if ( i_source_path_p )
    ADebug::print_format(
      "\n%s : %s\n\n  Internal Info:\n    %s\n    %s(%u) : %s\n    Exception Id: %u\n",
      i_title_p,
      i_desc_high_p,
      i_func_name_p,
      i_source_path_p,
      msg->i_source_line,
      i_desc_low_p,
      msg->i_err_id);
  else
    ADebug::print_format(
      "\n%s : %s\n\n  Internal Info:\n    %s\n    %s\n    Exception Id: %u\n",
      i_title_p,
      i_desc_high_p,
      i_func_name_p,
      i_desc_low_p,
      msg->i_err_id);
  ADebug::info();
  return 0;
}

