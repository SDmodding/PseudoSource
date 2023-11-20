// File Line: 65
// RVA: 0x146F7A0
__int64 anonymous_namespace_::_dynamic_initializer_for__g_dprint_funcs__()
{
  return atexit(anonymous_namespace_::_dynamic_atexit_destructor_for__g_dprint_funcs__);
}

// File Line: 66
// RVA: 0x146F780
__int64 anonymous_namespace_::_dynamic_initializer_for__g_context_funcs__()
{
  return atexit(anonymous_namespace_::_dynamic_atexit_destructor_for__g_context_funcs__);
}

// File Line: 124
// RVA: 0x223310
void __fastcall AErrMsg::AErrMsg(AErrMsg *this, const char *desc_high_p, eAErrLevel err_level, const char *title_p, const char *desc_low_p)
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
void __fastcall AErrMsg::AErrMsg(AErrMsg *this, AErrMsg *err_msg, const char *desc_low_p, const char *func_name_p, const char *source_path_p, unsigned int source_line, unsigned int err_id)
{
  eAErrLevel v7; // eax

  this->i_title_p = err_msg->i_title_p;
  this->i_desc_high_p = err_msg->i_desc_high_p;
  if ( err_msg->i_desc_low_p )
    desc_low_p = err_msg->i_desc_low_p;
  this->i_desc_low_p = desc_low_p;
  v7 = err_msg->i_err_level;
  this->i_func_name_p = func_name_p;
  this->i_err_level = v7;
  this->i_err_id = err_id;
  this->i_source_path_p = source_path_p;
  this->i_source_line = source_line;
}

// File Line: 166
// RVA: 0x223730
void __fastcall AErrorOutputBase::~AErrorOutputBase(AErrorOutputBase *this)
{
  this->vfptr = (AErrorOutputBaseVtbl *)&AErrorOutputBase::`vftable';
}

// File Line: 186
// RVA: 0x225560
void ADebug::info(void)
{
  AFunctionArgBase<AString const &> **v0; // rbx
  AFunctionArgBase<AString const &> **v1; // rdi
  AStringRef *v2; // rcx
  bool v3; // zf
  AString str_p; // [rsp+40h] [rbp+8h]

  if ( !(_S2_8 & 1) )
  {
    _S2_8 |= 1u;
    s_empty.i_cstr_p = &customWorldMapCaption;
    s_empty.i_length = 0;
    s_empty.i_size = 1;
    *(_DWORD *)&s_empty.i_ref_count = 16777218;
  }
  str_p.i_str_ref_p = &s_empty;
  ++s_empty.i_ref_count;
  if ( ADebug::context_append(&str_p) )
  {
    _((AMD_HD3D *)&str_p);
    if ( `anonymous namespace'::g_dprint_funcs.i_count )
    {
      v0 = `anonymous namespace'::g_dprint_funcs.i_array_p;
      v1 = &`anonymous namespace'::g_dprint_funcs.i_array_p[`anonymous namespace'::g_dprint_funcs.i_count];
      if ( `anonymous namespace'::g_dprint_funcs.i_array_p < v1 )
      {
        do
        {
          (*v0)->vfptr->invoke(*v0, &str_p);
          ++v0;
        }
        while ( v0 < v1 );
      }
    }
  }
  v2 = str_p.i_str_ref_p;
  v3 = str_p.i_str_ref_p->i_ref_count == 1;
  --v2->i_ref_count;
  if ( v3 )
    AStringRef::pool_delete(v2);
}

// File Line: 203
// RVA: 0x2243B0
char __fastcall ADebug::context_append(AString *str_p)
{
  AString *v1; // rdi
  AFunctionArgBase<AString *> **v2; // rbx
  __int64 v3; // rbp
  AFunctionArgBase<AString *> **v4; // rsi
  AStringRef *v5; // rax
  unsigned int v6; // ecx

  v1 = str_p;
  if ( !`anonymous namespace'::g_context_funcs.i_count )
    return 0;
  v2 = `anonymous namespace'::g_context_funcs.i_array_p;
  v3 = str_p->i_str_ref_p->i_length;
  v4 = &`anonymous namespace'::g_context_funcs.i_array_p[`anonymous namespace'::g_context_funcs.i_count];
  if ( `anonymous namespace'::g_context_funcs.i_array_p < v4 )
  {
    do
    {
      (*v2)->vfptr->invoke(*v2, v1);
      ++v2;
    }
    while ( v2 < v4 );
  }
  v5 = v1->i_str_ref_p;
  v6 = v1->i_str_ref_p->i_length;
  if ( v6 <= (unsigned int)v3 )
    return 0;
  if ( v6 + 1 >= v5->i_size || v5->i_ref_count + v5->i_read_only != 1 )
    AString::set_size(v1, v6 + 1);
  memmove(
    &v1->i_str_ref_p->i_cstr_p[v3 + 1],
    &v1->i_str_ref_p->i_cstr_p[v3],
    (unsigned int)(v1->i_str_ref_p->i_length - v3 + 1));
  v1->i_str_ref_p->i_cstr_p[v3] = 10;
  ++v1->i_str_ref_p->i_length;
  return 1;
}

// File Line: 239
// RVA: 0x224490
AString *__fastcall ADebug::context_string(AString *result)
{
  AString *v1; // rbx

  v1 = result;
  if ( !(_S2_8 & 1) )
  {
    _S2_8 |= 1u;
    s_empty.i_cstr_p = &customWorldMapCaption;
    s_empty.i_length = 0;
    s_empty.i_size = 1;
    *(_DWORD *)&s_empty.i_ref_count = 16777218;
  }
  result->i_str_ref_p = &s_empty;
  ++s_empty.i_ref_count;
  ADebug::context_append(result);
  return v1;
}

// File Line: 262
// RVA: 0x226590
void __fastcall ADebug::print(AString *str, bool call_print_funcs_b)
{
  bool v2; // bl
  AString *v3; // rsi
  __int64 v4; // rax
  AFunctionArgBase<AString const &> **v5; // rbx
  AFunctionArgBase<AString const &> **v6; // rdi

  v2 = call_print_funcs_b;
  v3 = str;
  _((AMD_HD3D *)str);
  v4 = 0i64;
  if ( v2 )
    v4 = `anonymous namespace'::g_dprint_funcs.i_count;
  if ( (_DWORD)v4 )
  {
    v5 = `anonymous namespace'::g_dprint_funcs.i_array_p;
    v6 = &`anonymous namespace'::g_dprint_funcs.i_array_p[v4];
    if ( `anonymous namespace'::g_dprint_funcs.i_array_p < v6 )
    {
      do
      {
        (*v5)->vfptr->invoke(*v5, v3);
        ++v5;
      }
      while ( v5 < v6 );
    }
  }
}

// File Line: 297
// RVA: 0x226600
void __fastcall ADebug::print(const char *cstr_p, bool call_print_funcs_b)
{
  bool v2; // bp
  const char *v3; // rsi
  signed __int64 v4; // rbx
  signed __int64 v5; // rdi
  unsigned int v6; // eax
  AStringRef *v7; // rcx
  bool v8; // zf
  __int64 v9; // rdi
  unsigned int v10; // eax
  AFunctionArgBase<AString const &> **v11; // rbx
  AFunctionArgBase<AString const &> **v12; // rdi
  AStringRef *v13; // rcx
  AStringRef *v14; // [rsp+70h] [rbp+18h]

  v2 = call_print_funcs_b;
  v3 = cstr_p;
  v4 = -1i64;
  v5 = -1i64;
  do
    ++v5;
  while ( cstr_p[v5] );
  v6 = AMemory::c_req_byte_size_func(v5 + 1);
  v14 = AStringRef::pool_new(v3, v5, v6, 1u, 0, 1);
  _((AMD_HD3D *)&v14);
  v7 = v14;
  v8 = v14->i_ref_count == 1;
  --v7->i_ref_count;
  if ( v8 )
    AStringRef::pool_delete(v7);
  v9 = 0i64;
  if ( v2 )
    v9 = `anonymous namespace'::g_dprint_funcs.i_count;
  if ( (_DWORD)v9 )
  {
    do
      ++v4;
    while ( v3[v4] );
    v10 = AMemory::c_req_byte_size_func(v4 + 1);
    v14 = AStringRef::pool_new(v3, v4, v10, 1u, 0, 1);
    v11 = `anonymous namespace'::g_dprint_funcs.i_array_p;
    v12 = &`anonymous namespace'::g_dprint_funcs.i_array_p[v9];
    if ( `anonymous namespace'::g_dprint_funcs.i_array_p < v12 )
    {
      do
      {
        (*v11)->vfptr->invoke(*v11, (AString *)&v14);
        ++v11;
      }
      while ( v11 < v12 );
    }
    v13 = v14;
    v8 = v14->i_ref_count == 1;
    --v13->i_ref_count;
    if ( v8 )
      AStringRef::pool_delete(v13);
  }
}

// File Line: 343
// RVA: 0x226720
void __fastcall ADebug::print_args(const char *format_cstr_p, char *args)
{
  int v2; // eax
  signed __int64 v3; // rbx
  char v4; // cl
  __int64 v5; // rdi
  AObjReusePool<AStringRef> *v6; // rax
  AObjReusePool<AStringRef> *v7; // rsi
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  __int64 v11; // rcx
  AStringRef **v12; // rax
  unsigned int v13; // eax
  AFunctionArgBase<AString const &> **v14; // rbx
  AFunctionArgBase<AString const &> **v15; // rdi
  AStringRef *v16; // rcx
  bool v17; // zf
  char string[2047]; // [rsp+30h] [rbp-808h]
  char v19; // [rsp+82Fh] [rbp-9h]
  AStringRef *v20; // [rsp+850h] [rbp+18h]

  v2 = vsnprintf(string, 0x7FFui64, format_cstr_p, args);
  LODWORD(v3) = v2;
  v4 = v19;
  v5 = 0i64;
  if ( !((v2 + 1) & 0xFFFFF7FF) )
    v4 = 0;
  v19 = v4;
  if ( v2 == -1 )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( string[v3] );
  }
  v6 = AStringRef::get_pool();
  v7 = v6;
  v8 = v6->i_pool.i_count;
  if ( v8 )
  {
    v13 = v8 - 1;
    v7->i_pool.i_count = v13;
    v11 = v13;
    v12 = v7->i_pool.i_array_p;
    goto LABEL_12;
  }
  if ( !v7->i_exp_pool.i_count )
    AObjReusePool<AStringRef>::append_block(v7, v7->i_expand_size);
  v9 = v7->i_exp_pool.i_count;
  if ( v9 )
  {
    v10 = v9 - 1;
    v7->i_exp_pool.i_count = v10;
    v11 = v10;
    v12 = v7->i_exp_pool.i_array_p;
LABEL_12:
    v5 = (__int64)v12[v11];
  }
  *(_QWORD *)v5 = string;
  *(_DWORD *)(v5 + 8) = v3;
  *(_DWORD *)(v5 + 12) = v3 + 1;
  *(_DWORD *)(v5 + 16) = 16777217;
  v20 = (AStringRef *)v5;
  _((AMD_HD3D *)&v20);
  if ( `anonymous namespace'::g_dprint_funcs.i_count )
  {
    v14 = `anonymous namespace'::g_dprint_funcs.i_array_p;
    v15 = &`anonymous namespace'::g_dprint_funcs.i_array_p[`anonymous namespace'::g_dprint_funcs.i_count];
    if ( `anonymous namespace'::g_dprint_funcs.i_array_p < v15 )
    {
      do
      {
        (*v14)->vfptr->invoke(*v14, (AString *)&v20);
        ++v14;
      }
      while ( v14 < v15 );
    }
  }
  v16 = v20;
  v17 = v20->i_ref_count == 1;
  --v16->i_ref_count;
  if ( v17 )
    AStringRef::pool_delete(v16);
}

// File Line: 400
// RVA: 0x226860
void ADebug::print_format(const char *format_cstr_p, ...)
{
  va_list args; // [rsp+38h] [rbp+10h]

  va_start(args, format_cstr_p);
  ADebug::print_args(format_cstr_p, args);
}

// File Line: 494
// RVA: 0x226950
_BOOL8 __fastcall ADebug::resolve_error(AErrMsg *msg, eAErrAction *action_p, bool *test_again_p)
{
  bool *v3; // rdi
  eAErrAction *v4; // rsi
  AErrMsg *v5; // rbp
  bool v6; // al
  bool v7; // bl
  AErrorOutputBase *v8; // rax
  bool v9; // al
  unsigned __int64 v10; // rcx
  bool v11; // bl
  AMD_HD3D *v12; // rcx
  eAErrAction action_pa; // [rsp+38h] [rbp+10h]

  v3 = test_again_p;
  v4 = action_p;
  v5 = msg;
  v6 = std::uncaught_exception();
  v7 = v6;
  v8 = Agog::on_error_pre(v6);
  if ( !v8 || v7 )
    v9 = ADebug::determine_choice(v5, &action_pa);
  else
    v9 = v8->vfptr->determine_choice(v8, v5, &action_pa);
  v10 = (unsigned int)action_pa;
  v11 = v9;
  if ( action_pa == 4 )
  {
    if ( v3 )
      *v3 = 0;
    v10 = 3i64;
    action_pa = 3;
  }
  if ( v4 )
    *v4 = v10;
  _((AMD_HD3D *)v10);
  if ( action_pa == AErrAction_quit )
    _(v12);
  return v11;
}

// File Line: 541
// RVA: 0x224AB0
bool __fastcall ADebug::determine_choice(AErrMsg *msg, eAErrAction *action_p)
{
  eAErrAction *v2; // rdi
  AErrMsg *v3; // rbx
  bool v4; // al
  signed int v5; // ecx
  char *v6; // rdx
  const char *v7; // r8
  unsigned int v8; // eax
  unsigned int v9; // ST28_4

  v2 = action_p;
  v3 = msg;
  v4 = std::uncaught_exception();
  if ( v4 || v3->i_err_level <= 1 )
    v5 = 3;
  else
    v5 = 0;
  *v2 = v5;
  if ( v4 )
    ADebug::print("### Had another exception while a previous exception is being handled: ###", 1);
  v6 = &customWorldMapCaption;
  if ( v3->i_title_p )
    v6 = (char *)v3->i_title_p;
  v7 = "An error has occurred.";
  if ( v3->i_desc_high_p )
    v7 = v3->i_desc_high_p;
  v3->i_desc_low_p;
  v3->i_func_name_p;
  v8 = v3->i_err_id;
  if ( v3->i_source_path_p )
  {
    v9 = v3->i_source_line;
    ADebug::print_format("\n%s : %s\n\n  Internal Info:\n    %s\n    %s(%u) : %s\n    Exception Id: %u\n", v6, v7);
  }
  else
  {
    ADebug::print_format("\n%s : %s\n\n  Internal Info:\n    %s\n    %s\n    Exception Id: %u\n", v6, v7);
  }
  ADebug::info();
  return 0;
}

