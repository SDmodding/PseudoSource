// File Line: 112
// RVA: 0x1461530
__int64 dynamic_initializer_for__SSParser::c_reserved_word_syms__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SSParser::c_reserved_word_syms__);
}

// File Line: 113
// RVA: 0x1461510
__int64 dynamic_initializer_for__SSParser::c_reserved_word_strs__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SSParser::c_reserved_word_strs__);
}

// File Line: 114
// RVA: 0x14614E0
__int64 dynamic_initializer_for__SSParser::c_operator_word_strs__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SSParser::c_operator_word_strs__);
}

// File Line: 117
// RVA: 0x1461490
__int64 dynamic_initializer_for__SSParser::c_error_str__()
{
  SSParser::c_error_str.i_str_ref_p = AStringRef::get_empty();
  ++SSParser::c_error_str.i_str_ref_p->i_ref_count;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__SSParser::c_error_str__);
}

// File Line: 162
// RVA: 0x10F510
ASymbol *__fastcall SSParser::as_symbol(SSParser *this, ASymbol *result, unsigned int start_pos, unsigned int end_pos)
{
  unsigned int v6; // r9d
  unsigned int v7; // r8d

  v6 = end_pos - start_pos;
  v7 = 255;
  if ( v6 < 0xFF )
    v7 = v6;
  ASymbol::create(result, &this->i_str_ref_p->i_cstr_p[start_pos], v7, ATerm_short);
  return result;
}

// File Line: 178
// RVA: 0x13C360
void __fastcall SSParser::set_class_scope(SSParser *this, SSClass *scope_p)
{
  SSClass *v2; // rax

  v2 = SSBrain::c_object_class_p;
  if ( scope_p )
    v2 = scope_p;
  this->i_context.i_obj_scope_p = v2;
}

// File Line: 236
// RVA: 0x127190
SSBind *__fastcall SSParser::parse_bind(SSParser *this, SSParser::Args *args, SSIdentifier *identifier_p)
{
  int v6; // eax
  __int64 v7; // rbx
  SSParser::eResult v8; // eax
  SSClassDescBase *i_type_p; // r15
  SSExpressionBase *v11; // rbp
  _QWORD *v12; // rax

  v6 = identifier_p->vfptr->get_type(identifier_p);
  v7 = 0i64;
  if ( v6 > 0 )
  {
    if ( v6 <= 3 )
    {
      v8 = Result_ok;
      goto LABEL_7;
    }
    if ( v6 == 5 )
    {
      v8 = Result_err_unexpected_reserved;
      goto LABEL_7;
    }
  }
  v8 = Result_err_unexpected_bind_expr;
LABEL_7:
  args->i_result = v8;
  if ( v8 )
    return 0i64;
  i_type_p = args->i_type_p;
  v11 = SSParser::parse_binding(this, args);
  if ( args->i_result == Result_ok )
    args->i_result = SSParser::validate_bind_type(this, identifier_p, i_type_p, args->i_type_p);
  if ( v11 && args->i_result == Result_ok )
  {
    v12 = AMemory::c_malloc_func(0x18ui64, "SSBind");
    if ( v12 )
    {
      *v12 = &SSExpressionBase::`vftable;
      *v12 = &SSBind::`vftable;
      v12[1] = identifier_p;
      v12[2] = v11;
      return (SSBind *)v12;
    }
  }
  return (SSBind *)v7;
}

// File Line: 292
// RVA: 0x127280
SSExpressionBase *__fastcall SSParser::parse_binding(SSParser *this, SSParser::Args *args)
{
  AStringRef *i_str_ref_p; // rax
  __int64 i_start_pos; // rdx
  SSParser::eResult v6; // eax
  unsigned int end_pos_p; // [rsp+30h] [rbp+8h] BYREF

  i_str_ref_p = this->i_str_ref_p;
  i_start_pos = args->i_start_pos;
  end_pos_p = i_start_pos;
  if ( i_str_ref_p->i_length > (unsigned int)i_start_pos && i_str_ref_p->i_cstr_p[i_start_pos] == 58 )
  {
    v6 = SSParser::parse_ws_any(this, i_start_pos + 1, &end_pos_p);
    args->i_result = v6;
    if ( v6 )
    {
      args->i_end_pos = end_pos_p;
      return 0i64;
    }
    else
    {
      args->i_start_pos = end_pos_p;
      return SSParser::parse_expression(this, args, SSInvokeTime_any);
    }
  }
  else
  {
    args->i_result = Result_err_expected_binding;
    args->i_end_pos = i_start_pos;
    return 0i64;
  }
}

// File Line: 350
// RVA: 0x127310
SSCase *__fastcall SSParser::parse_case_tail(SSParser *this, SSParser::Args *args)
{
  int v4; // r14d
  void (__fastcall ***v5)(_QWORD, __int64); // r15
  SSParser::eResult v6; // eax
  SSExpressionBase *v7; // rdi
  unsigned int i_end_pos; // r13d
  SSMethodBase *v9; // rax
  SSParameters *i_obj_p; // rax
  SSParameterBase *v11; // rcx
  AStringRef *i_str_ref_p; // rax
  char *i_cstr_p; // r12
  char *v14; // r15
  unsigned int v15; // edi
  unsigned __int64 v16; // r15
  SSParser::eResult v17; // eax
  SSExpressionBase *v18; // r13
  SSParser::eResult v19; // eax
  __int64 i_count; // r14
  unsigned int v21; // eax
  SSTypedName **i_array_p; // rax
  SSParser::eResult v23; // eax
  SSCode *v24; // r14
  SSClause *v25; // rax
  int v26; // r14d
  unsigned int v27; // eax
  unsigned int v28; // eax
  SSTypedName **v29; // r14
  SSClassUnaryBase *i_common_class_p; // rax
  unsigned int v32; // [rsp+20h] [rbp-79h] BYREF
  unsigned int v33; // [rsp+24h] [rbp-75h]
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > sorted; // [rsp+28h] [rbp-71h] BYREF
  unsigned int i_length; // [rsp+40h] [rbp-59h]
  char *v36; // [rsp+48h] [rbp-51h]
  APCompactArray<SSClause,SSClause,ACompareAddress<SSClause> > *v37; // [rsp+50h] [rbp-49h]
  SSClass *vfptr; // [rsp+58h] [rbp-41h]
  APSortedLogical<SSTypedName,ASymbol> merge_vars_p; // [rsp+60h] [rbp-39h] BYREF
  SSClassUnion class_union; // [rsp+78h] [rbp-21h] BYREF
  __int64 v41; // [rsp+A8h] [rbp+Fh]
  SSClause *v42; // [rsp+B0h] [rbp+17h]
  __int64 end_pos_p; // [rsp+108h] [rbp+6Fh] BYREF
  char *v44; // [rsp+110h] [rbp+77h]
  char *v45; // [rsp+118h] [rbp+7Fh]

  v41 = -2i64;
  v4 = 0;
  v5 = 0i64;
  v36 = 0i64;
  LODWORD(end_pos_p) = args->i_start_pos;
  v6 = SSParser::parse_ws_any(this, end_pos_p, (unsigned int *)&end_pos_p);
  args->i_result = v6;
  if ( v6 )
  {
    args->i_end_pos = end_pos_p;
    return (SSCase *)v5;
  }
  args->i_start_pos = end_pos_p;
  v7 = SSParser::parse_expression(this, args, SSInvokeTime_immediate);
  i_end_pos = args->i_end_pos;
  v33 = i_end_pos;
  if ( args->i_result )
    goto LABEL_81;
  vfptr = SSBrain::c_object_class_p;
  if ( (this->i_flags.i_flagset & 1) != 0 )
  {
    v9 = args->i_type_p->vfptr->get_method_inherited(args->i_type_p, &ASymbol_equals);
    if ( v9 )
    {
      i_obj_p = v9->i_params_p.i_obj_p;
      if ( i_obj_p->i_params.i_count )
        v11 = *i_obj_p->i_params.i_array_p;
      else
        v11 = 0i64;
      vfptr = (SSClass *)v11[1].vfptr;
    }
    else
    {
      args->i_result = Result_err_context_case_compare;
    }
  }
  if ( args->i_result )
    goto LABEL_81;
  i_str_ref_p = this->i_str_ref_p;
  i_length = this->i_str_ref_p->i_length;
  i_cstr_p = i_str_ref_p->i_cstr_p;
  class_union.i_ref_count = 0;
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
  class_union.i_common_class_p = 0i64;
  class_union.i_union.i_count = 0;
  class_union.i_union.i_array_p = 0i64;
  class_union.i_union.i_size = 0;
  merge_vars_p.i_count = 0;
  merge_vars_p.i_array_p = 0i64;
  merge_vars_p.i_size = 0;
  sorted.i_count = 0;
  sorted.i_array_p = 0i64;
  end_pos_p = 0i64;
  sorted.i_size = 0;
  if ( v7 )
  {
    v14 = (char *)AMemory::c_malloc_func(0x20ui64, "SSCase");
    v36 = v14;
    v44 = v14;
    if ( v14 )
    {
      *(_QWORD *)v14 = &SSExpressionBase::`vftable;
      *(_QWORD *)v14 = &SSCase::`vftable;
      *((_QWORD *)v14 + 1) = 0i64;
      v45 = v14 + 16;
      *((_DWORD *)v14 + 4) = 0;
      *((_QWORD *)v14 + 3) = 0i64;
    }
    else
    {
      v14 = 0i64;
      v36 = 0i64;
    }
    *((_QWORD *)v14 + 1) = v7;
    v37 = (APCompactArray<SSClause,SSClause,ACompareAddress<SSClause> > *)(v14 + 16);
  }
  else
  {
    v37 = 0i64;
  }
  LODWORD(v45) = 0;
  v15 = i_end_pos;
  v32 = i_end_pos;
  LOBYTE(v44) = 0;
  LODWORD(v16) = end_pos_p;
  do
  {
    v17 = SSParser::parse_ws_any(this, v15, &v32);
    args->i_result = v17;
    LOBYTE(end_pos_p) = 0;
    v18 = 0i64;
    if ( v17 )
    {
      v15 = v32;
      continue;
    }
    args->i_result = Result_err_expected_clause_block;
    v15 = v32;
    if ( i_length - v32 < 3 )
      break;
    if ( i_cstr_p[v32] == 101
      && i_cstr_p[v32 + 1] == 108
      && i_cstr_p[v32 + 2] == 115
      && i_cstr_p[v32 + 3] == 101
      && byte_14236F1C0[(unsigned __int8)i_cstr_p[v32 + 4]] )
    {
      v15 = v32 + 4;
      v32 += 4;
      v19 = Result_err_unexpected_else;
      if ( v4 )
        v19 = Result_ok;
      args->i_result = v19;
      LOBYTE(end_pos_p) = 1;
      LOBYTE(v44) = 1;
    }
    else
    {
      i_count = this->i_context.i_top_scope_old.i_count;
      sorted.i_count = i_count;
      if ( (unsigned int)i_count <= (unsigned int)v16 )
      {
        i_array_p = sorted.i_array_p;
      }
      else
      {
        AMemory::c_free_func(sorted.i_array_p);
        v21 = AMemory::c_req_byte_size_func(8 * i_count);
        v16 = (unsigned __int64)v21 >> 3;
        sorted.i_size = v21 >> 3;
        i_array_p = APArrayBase<SSTypedName>::alloc_array(v21 >> 3);
        sorted.i_array_p = i_array_p;
      }
      memmove(i_array_p, this->i_context.i_top_scope_old.i_array_p, 8 * i_count);
      args->i_start_pos = v15;
      v18 = SSParser::parse_expression(this, args, SSInvokeTime_immediate);
      v15 = args->i_end_pos;
      v32 = v15;
      if ( (this->i_flags.i_flagset & 1) != 0 )
      {
        if ( args->i_result )
          goto LABEL_53;
        if ( !args->i_type_p->vfptr->is_class_type(args->i_type_p, vfptr) )
        {
          args->i_result = Result_err_typecheck_case;
          goto LABEL_53;
        }
      }
    }
    if ( args->i_result == Result_ok )
    {
      v23 = SSParser::parse_ws_any(this, v15, &v32);
      args->i_result = v23;
      if ( v23 )
      {
        v15 = v32;
      }
      else
      {
        args->i_result = Result_err_expected_clause_block;
        v15 = v32;
        if ( i_cstr_p[v32] == 91 )
        {
          if ( (this->i_flags.i_flagset & 1) != 0 )
            SSTypeContext::nest_locals(&this->i_context);
          LOBYTE(end_pos_p) = 1;
          args->i_start_pos = v15;
          v24 = SSParser::parse_code_block_optimized(this, args, SSInvokeTime_any, ResultDesired_true);
          v15 = args->i_end_pos;
          v32 = v15;
          if ( args->i_result )
            goto LABEL_49;
          v33 = v15;
          LODWORD(v45) = (_DWORD)v45 + 1;
          if ( v37 )
          {
            v25 = (SSClause *)AMemory::c_malloc_func(0x18ui64, "SSClause");
            v42 = v25;
            if ( v25 )
            {
              v25->vfptr = (SSClauseVtbl *)&SSClause::`vftable;
              v25->i_test_p = v18;
              v25->i_clause_p = v24;
            }
            APCompactArray<SSClause,SSClause,ACompareAddress<SSClause>>::append(v37, v25);
          }
          if ( (this->i_flags.i_flagset & 1) != 0
            && ((SSClassUnion::merge_class(&class_union, (SSClassUnion *)args->i_type_p), merge_vars_p.i_count)
             || this->i_context.i_current_scope_p->i_count) )
          {
            v26 = (int)v45;
            SSTypeContext::merge_locals(&this->i_context, &merge_vars_p, (_DWORD)v45 == 1);
          }
          else
          {
LABEL_49:
            v26 = (int)v45;
          }
          if ( (this->i_flags.i_flagset & 1) != 0 )
          {
            AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>::free_last(&this->i_context.i_scope_stack);
            this->i_context.i_current_scope_p = (APSortedLogical<SSTypedName,ASymbol> *)&this->i_context.i_scope_stack.i_sentinel.i_prev_p[1];
          }
          goto LABEL_54;
        }
      }
    }
LABEL_53:
    v26 = (int)v45;
LABEL_54:
    if ( (_BYTE)v44 )
      goto LABEL_59;
    v4 = (int)v45;
  }
  while ( args->i_result == Result_ok );
  v26 = (int)v45;
LABEL_59:
  v5 = (void (__fastcall ***)(_QWORD, __int64))v36;
  if ( args->i_result == Result_ok )
  {
    i_end_pos = v33;
LABEL_70:
    v29 = sorted.i_array_p;
    goto LABEL_71;
  }
  if ( v18 )
    v18->vfptr->__vecDelDtor(v18, 1u);
  if ( (_BYTE)end_pos_p || !v26 )
  {
    i_end_pos = v15;
    if ( v5 )
    {
      (**v5)(v5, 1i64);
      v5 = 0i64;
    }
    goto LABEL_70;
  }
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::remove_all_all(
    &this->i_context.i_top_scope_old,
    &sorted,
    0,
    0xFFFFFFFF);
  APSizedArrayBase<SSTypedName>::free_all(&this->i_context.i_top_scope_old);
  v27 = sorted.i_count;
  this->i_context.i_top_scope_old.i_count = sorted.i_count;
  if ( v27 > this->i_context.i_top_scope_old.i_size )
  {
    AMemory::c_free_func(this->i_context.i_top_scope_old.i_array_p);
    v28 = AMemory::c_req_byte_size_func(8 * this->i_context.i_top_scope_old.i_count) >> 3;
    this->i_context.i_top_scope_old.i_size = v28;
    this->i_context.i_top_scope_old.i_array_p = APArrayBase<SSTypedName>::alloc_array(v28);
  }
  v29 = sorted.i_array_p;
  memmove(this->i_context.i_top_scope_old.i_array_p, sorted.i_array_p, 8i64 * this->i_context.i_top_scope_old.i_count);
  args->i_result = Result_ok;
  i_end_pos = v33;
LABEL_71:
  if ( (this->i_flags.i_flagset & 1) != 0 )
  {
    if ( args->i_result == Result_ok )
    {
      if ( !(_BYTE)v44 )
      {
        SSTypeContext::merge(&this->i_context, &merge_vars_p);
        SSClassUnion::merge_class(&class_union, SSBrain::c_none_class_p);
      }
      if ( class_union.i_union.i_count > 1 )
        i_common_class_p = (SSClassUnaryBase *)SSClassUnion::get_or_create(&class_union);
      else
        i_common_class_p = class_union.i_common_class_p;
      args->i_type_p = i_common_class_p;
      SSTypeContext::change_variable_types(&this->i_context, &merge_vars_p);
    }
    APSizedArrayBase<SSTypedName>::free_all(&merge_vars_p);
  }
  AMemory::c_free_func(v29);
  AMemory::c_free_func(merge_vars_p.i_array_p);
  SSClassUnion::~SSClassUnion(&class_union);
LABEL_81:
  args->i_end_pos = i_end_pos;
  return (SSCase *)v5;
}

// File Line: 634
// RVA: 0x1278A0
SSParser::eResult __fastcall SSParser::parse_class(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSClass **class_pp)
{
  SSParser::eResult result; // eax
  SSClass **i_array_p; // r8
  SSClass **v7; // r10
  SSClass **v8; // rdx
  unsigned int i_uid; // r9d
  ASymbol name_p; // [rsp+30h] [rbp-18h] BYREF

  name_p.i_uid = -1;
  result = SSParser::parse_name_class(this, start_pos, end_pos_p, &name_p, ClassCheck_no_validate_meta);
  if ( result == Result_ok )
  {
    if ( !SSBrain::c_classes.i_count )
      return 112;
    i_array_p = SSBrain::c_classes.i_array_p;
    v7 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v8 = &i_array_p[((char *)v7 - (char *)i_array_p) >> 4];
        i_uid = (*v8)->i_name.i_uid;
        if ( name_p.i_uid >= i_uid )
          break;
        if ( i_array_p == v8 )
          return 112;
        v7 = v8 - 1;
      }
      if ( name_p.i_uid == i_uid )
        break;
      if ( v7 == v8 )
        return 112;
      i_array_p = v8 + 1;
    }
    if ( *v8 )
    {
      result = Result_ok;
      if ( class_pp )
        *class_pp = *v8;
    }
    else
    {
      return 112;
    }
  }
  return result;
}

// File Line: 688
// RVA: 0x127D80
__int64 __fastcall SSParser::parse_class_instance(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSTypedClass **class_pp,
        bool *item_type_b_p)
{
  SSParser::eResult v8; // edi
  bool v9; // r13
  AStringRef *i_str_ref_p; // rax
  char *i_cstr_p; // rbx
  eSSInvokeTime v12; // r12d
  unsigned __int8 v13; // cl
  SSTypedClass *v14; // rax
  unsigned int v15; // eax
  SSParameters *p_params_p; // r9
  SSParameterBase **i_array_p; // rbx
  SSParameterBase **v18; // rsi
  SSParameters *v19; // rax
  unsigned int find_pos_p; // [rsp+30h] [rbp-50h] BYREF
  SSClass *class_ppa[2]; // [rsp+38h] [rbp-48h] BYREF
  SSParameters params_p; // [rsp+48h] [rbp-38h] BYREF
  unsigned int end_pos_pa; // [rsp+C0h] [rbp+40h] BYREF
  bool v25; // [rsp+C8h] [rbp+48h] BYREF
  unsigned int *v26; // [rsp+D0h] [rbp+50h]

  v26 = end_pos_p;
  class_ppa[1] = (SSClass *)-2i64;
  v8 = Result_err_unexpected_eof;
  end_pos_pa = start_pos;
  v9 = 0;
  v25 = 0;
  i_str_ref_p = this->i_str_ref_p;
  if ( this->i_str_ref_p->i_length <= start_pos )
    goto LABEL_36;
  v8 = Result_err_expected_class_instance;
  i_cstr_p = i_str_ref_p->i_cstr_p;
  v12 = SSInvokeTime_immediate;
  v13 = i_str_ref_p->i_cstr_p[start_pos];
  if ( v13 == 40 )
    goto LABEL_14;
  if ( v13 == 43 || v13 == 95 )
  {
    v12 = SSInvokeTime_durational;
    end_pos_pa = start_pos + 1;
LABEL_14:
    params_p.i_ref_count = 0;
    params_p.i_params.i_count = 0;
    params_p.i_params.i_array_p = 0i64;
    class_ppa[0] = (SSClass *)&params_p.i_return_params;
    params_p.i_return_params.i_count = 0;
    params_p.i_return_params.i_array_p = 0i64;
    params_p.i_result_type_p.i_obj_p = SSBrain::c_object_class_p;
    if ( SSBrain::c_object_class_p )
      (*(void (__fastcall **)(SSClass *, __int64))SSBrain::c_object_class_p->vfptr->gap8)(
        SSBrain::c_object_class_p,
        2i64);
    v15 = 0;
    if ( v12 == SSInvokeTime_durational )
      v15 = 2;
    p_params_p = &params_p;
    if ( !class_pp )
      p_params_p = 0i64;
    v8 = SSParser::parse_parameters(this, end_pos_pa, &end_pos_pa, p_params_p, v15);
    if ( v8 == Result_ok && class_pp )
    {
      if ( params_p.i_params.i_count )
      {
        i_array_p = params_p.i_params.i_array_p;
        v18 = &params_p.i_params.i_array_p[params_p.i_params.i_count];
        if ( params_p.i_params.i_array_p < v18 )
        {
          while ( !(*i_array_p)->vfptr->is_defaultable(*i_array_p) )
          {
            if ( ++i_array_p >= v18 )
              goto LABEL_29;
          }
          if ( SSParameters::is_generic(&params_p) )
            v8 = Result_err__start;
        }
      }
LABEL_29:
      v19 = SSParameters::get_or_create(&params_p);
      *class_pp = (SSTypedClass *)SSInvokableClass::get_or_create(SSBrain::c_closure_class_p, v19, v12);
    }
    APCompactArrayBase<SSParameterBase>::free_all(&params_p.i_params);
    APCompactArrayBase<SSTypedName>::free_all(&params_p.i_return_params);
    if ( params_p.i_result_type_p.i_obj_p )
      (*(void (__fastcall **)(SSClassDescBase *))&params_p.i_result_type_p.i_obj_p->vfptr->gap8[8])(params_p.i_result_type_p.i_obj_p);
    AMemory::c_free_func(params_p.i_return_params.i_array_p);
    class_ppa[0] = (SSClass *)&params_p.i_params;
    AMemory::c_free_func(params_p.i_params.i_array_p);
LABEL_33:
    if ( v8 )
      goto LABEL_36;
    goto LABEL_34;
  }
  if ( !AString::c_is_uppercase[v13] )
    goto LABEL_36;
  find_pos_p = start_pos + 1;
  AString::find(this, ACharMatch_not_identifier, 1u, &find_pos_p, start_pos + 1, 0xFFFFFFFF);
  if ( i_cstr_p[find_pos_p] == 123 )
  {
    v8 = SSParser::parse_class_typed(this, start_pos, &end_pos_pa, class_pp, &v25);
    v9 = v25;
    goto LABEL_33;
  }
  class_ppa[0] = 0i64;
  v8 = SSParser::parse_class(this, start_pos, &end_pos_pa, class_ppa);
  if ( v8 )
    goto LABEL_36;
  if ( class_pp )
  {
    v14 = (SSTypedClass *)class_ppa[0];
    if ( class_ppa[0] == SSBrain::c_list_class_p )
      v14 = SSTypedClass::get_or_create(SSBrain::c_list_class_p, SSBrain::c_object_class_p);
    *class_pp = v14;
  }
LABEL_34:
  if ( item_type_b_p )
    *item_type_b_p = v9;
LABEL_36:
  if ( v26 )
    *v26 = end_pos_pa;
  return (unsigned int)v8;
}

// File Line: 838
// RVA: 0x127CA0
__int64 __fastcall SSParser::parse_class_desc(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSMetaClass **type_pp)
{
  AStringRef *i_str_ref_p; // rbp
  SSParser::eResult v9; // r10d
  char *i_cstr_p; // rbp
  unsigned int find_pos_p; // [rsp+50h] [rbp+8h] BYREF
  unsigned int end_pos_pa; // [rsp+58h] [rbp+10h] BYREF

  i_str_ref_p = this->i_str_ref_p;
  v9 = Result_err_unexpected_eof;
  end_pos_pa = start_pos;
  if ( i_str_ref_p->i_length > start_pos )
  {
    i_cstr_p = i_str_ref_p->i_cstr_p;
    if ( i_cstr_p[start_pos] == 60 )
    {
      find_pos_p = start_pos + 1;
      AString::find(this, ACharMatch_not_identifier, 1u, &find_pos_p, start_pos + 1, 0xFFFFFFFF);
      if ( i_cstr_p[find_pos_p] == 62 )
        v9 = SSParser::parse_class_meta(this, start_pos, &end_pos_pa, type_pp);
      else
        v9 = SSParser::parse_class_union(this, start_pos, &end_pos_pa, (SSClassUnion **)type_pp);
    }
    else
    {
      v9 = SSParser::parse_class_instance(this, start_pos, &end_pos_pa, type_pp, 0i64);
      if ( end_pos_pa == start_pos && v9 == Result_err_expected_class_instance )
        v9 = Result_err_expected_class_desc;
    }
  }
  if ( end_pos_p )
    *end_pos_p = end_pos_pa;
  return (unsigned int)v9;
}

// File Line: 905
// RVA: 0x128010
__int64 __fastcall SSParser::parse_class_meta(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSMetaClass **mclass_pp)
{
  __int64 v4; // rdi
  AStringRef *i_str_ref_p; // rdx
  unsigned int i_length; // r10d
  unsigned int v10; // ebx
  char *i_cstr_p; // rbp
  unsigned int i_uid; // eax
  ASymbol *v13; // rax
  SSClass **i_array_p; // r8
  SSClass **v15; // r10
  SSClass **v16; // rcx
  unsigned int v17; // r9d
  __int64 v18; // rcx
  __int64 v19; // rax
  __int64 result; // [rsp+60h] [rbp+8h] BYREF
  unsigned int find_pos_p; // [rsp+68h] [rbp+10h] BYREF

  v4 = start_pos;
  i_str_ref_p = this->i_str_ref_p;
  i_length = this->i_str_ref_p->i_length;
  v10 = 82;
  if ( i_length - (unsigned int)v4 >= 3 )
  {
    i_cstr_p = i_str_ref_p->i_cstr_p;
    v10 = 20;
    if ( i_str_ref_p->i_cstr_p[v4] == 60 )
    {
      v4 = (unsigned int)(v4 + 1);
      i_uid = -1;
      v10 = 82;
      find_pos_p = v4;
      if ( i_length > (unsigned int)v4 )
      {
        v10 = 15;
        if ( AString::c_is_uppercase[(unsigned __int8)i_cstr_p[v4]] )
        {
          find_pos_p = i_length;
          AString::find(this, ACharMatch_not_identifier, 1u, &find_pos_p, v4 + 1, 0xFFFFFFFF);
          v13 = SSParser::as_symbol(this, (ASymbol *)&result, v4, find_pos_p);
          LODWORD(v4) = find_pos_p;
          v10 = 0;
          i_uid = v13->i_uid;
          if ( i_uid == ASymbol_Class.i_uid )
            v10 = 74;
        }
      }
      if ( v10 )
        goto LABEL_18;
      v10 = 112;
      if ( !SSBrain::c_classes.i_count )
        goto LABEL_18;
      i_array_p = SSBrain::c_classes.i_array_p;
      v15 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
      while ( 1 )
      {
        while ( 1 )
        {
          v16 = &i_array_p[((char *)v15 - (char *)i_array_p) >> 4];
          v17 = (*v16)->i_name.i_uid;
          if ( i_uid >= v17 )
            break;
          if ( i_array_p == v16 )
            goto LABEL_18;
          v15 = v16 - 1;
        }
        if ( i_uid == v17 )
          break;
        if ( v15 == v16 )
          goto LABEL_18;
        i_array_p = v16 + 1;
      }
      v18 = (__int64)*v16;
      if ( v18 )
        v10 = 0;
      else
LABEL_18:
        v18 = result;
      if ( !v10 )
      {
        v10 = 21;
        if ( i_cstr_p[(unsigned int)v4] == 62 )
        {
          LODWORD(v4) = v4 + 1;
          v10 = 0;
          if ( mclass_pp )
            *mclass_pp = (SSMetaClass *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v18 + 136i64))(v18);
        }
      }
    }
  }
  v19 = v10;
  if ( end_pos_p )
    *end_pos_p = v4;
  return v19;
}

// File Line: 977
// RVA: 0x1281B0
__int64 __fastcall SSParser::parse_class_typed(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSTypedClass **tclass_pp,
        bool *item_type_b_p)
{
  AStringRef *i_str_ref_p; // r10
  unsigned int v6; // esi
  unsigned int i_uid; // eax
  SSParser::eResult v10; // edi
  ASymbol *v11; // rax
  SSClass **i_array_p; // r8
  SSClass **v13; // r10
  SSClass **v14; // rdx
  unsigned int v15; // r9d
  SSClass *v16; // rbp
  SSClass *i_superclass_p; // rcx
  char *i_cstr_p; // r15
  SSMetaClass **v19; // r9
  bool v20; // r14
  SSParser::eResult v21; // eax
  ASymbol result[2]; // [rsp+30h] [rbp-48h] BYREF
  unsigned int i_length; // [rsp+80h] [rbp+8h] BYREF
  unsigned int end_pos_pa; // [rsp+88h] [rbp+10h] BYREF
  unsigned int *v26; // [rsp+90h] [rbp+18h]

  v26 = end_pos_p;
  i_str_ref_p = this->i_str_ref_p;
  v6 = start_pos;
  i_uid = -1;
  i_length = start_pos;
  v10 = Result_err_unexpected_eof;
  if ( i_str_ref_p->i_length > start_pos )
  {
    v10 = Result_err_expected_class;
    if ( AString::c_is_uppercase[(unsigned __int8)i_str_ref_p->i_cstr_p[start_pos]] )
    {
      i_length = start_pos + 1;
      i_length = i_str_ref_p->i_length;
      AString::find(this, ACharMatch_not_identifier, 1u, &i_length, start_pos + 1, 0xFFFFFFFF);
      v11 = SSParser::as_symbol(this, result, v6, i_length);
      v6 = i_length;
      v10 = Result_ok;
      i_uid = v11->i_uid;
      if ( i_uid == ASymbol_Class.i_uid )
        v10 = Result_err_unexpected_class_class;
    }
  }
  end_pos_pa = v6;
  if ( v10 )
    goto LABEL_16;
  v10 = Result_err_context_non_class;
  if ( !SSBrain::c_classes.i_count )
    goto LABEL_16;
  i_array_p = SSBrain::c_classes.i_array_p;
  v13 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
  while ( 1 )
  {
    while ( 1 )
    {
      v14 = &i_array_p[((char *)v13 - (char *)i_array_p) >> 4];
      v15 = (*v14)->i_name.i_uid;
      if ( i_uid >= v15 )
        break;
      if ( i_array_p == v14 )
        goto LABEL_16;
      v13 = v14 - 1;
    }
    if ( i_uid == v15 )
      break;
    if ( v13 == v14 )
      goto LABEL_16;
    i_array_p = v14 + 1;
  }
  v16 = *v14;
  if ( *v14 )
    v10 = Result_ok;
  else
LABEL_16:
    v16 = (SSClass *)v26;
  if ( v10 == Result_ok )
  {
    v10 = Result_err_typecheck_list;
    if ( SSBrain::c_list_class_p == v16
      || (i_superclass_p = v16->i_superclass_p) != 0i64 && SSClass::is_class(i_superclass_p, SSBrain::c_list_class_p) )
    {
      v10 = Result_err_expected_class_list_item;
      i_cstr_p = this->i_str_ref_p->i_cstr_p;
      if ( i_cstr_p[v6] == 123 )
      {
        v10 = SSParser::parse_ws_any(this, v6 + 1, &end_pos_pa);
        if ( v10 )
          goto LABEL_36;
        v19 = (SSMetaClass **)result;
        if ( !tclass_pp )
          v19 = 0i64;
        v20 = 1;
        *(_QWORD *)&result[0].i_uid = SSBrain::c_object_class_p;
        v21 = (unsigned int)SSParser::parse_class_desc(this, end_pos_pa, &i_length, v19);
        v6 = i_length;
        v10 = v21;
        if ( i_length == end_pos_pa )
        {
          v20 = 0;
          v10 = Result_ok;
        }
        end_pos_pa = i_length;
        if ( v10 == Result_ok )
        {
          if ( !v20 )
            goto LABEL_31;
          v10 = SSParser::parse_ws_any(this, i_length, &end_pos_pa);
          if ( v10 == Result_ok )
          {
            v6 = end_pos_pa;
LABEL_31:
            v10 = Result_err_expected_class_list_end;
            if ( i_cstr_p[v6] == 125 )
            {
              ++v6;
              v10 = Result_ok;
              if ( tclass_pp )
                *tclass_pp = SSTypedClass::get_or_create(v16, *(SSClassDescBase **)&result[0].i_uid);
              if ( item_type_b_p )
                *item_type_b_p = v20;
            }
            goto LABEL_37;
          }
LABEL_36:
          v6 = end_pos_pa;
        }
      }
    }
  }
LABEL_37:
  if ( v26 )
    *v26 = v6;
  return (unsigned int)v10;
}EL_36:
          v6 = end_pos_pa;
        }
      }
    }
  }
LABEL_37:
  if ( v26 )
    *v26 = v6;
  return (unsigned int)v1

// File Line: 1095
// RVA: 0x128450
__int64 __fastcall SSParser::parse_class_union(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSClassUnion **type_pp)
{
  unsigned int v6; // ebx
  unsigned int v8; // esi
  char *i_cstr_p; // rbp
  SSClassUnaryBase **p_new_class; // rdi
  unsigned int v11; // r14d
  __int64 v12; // rbx
  unsigned int v13; // eax
  SSClassUnaryBase **i_array_p; // r14
  __int64 *v15; // rdi
  SSClassUnaryBase **v16; // rbp
  __int64 result; // rax
  SSClassUnion class_union; // [rsp+38h] [rbp-70h] BYREF
  SSClassUnaryBase *new_class; // [rsp+B0h] [rbp+8h] BYREF
  unsigned int end_pos_pa; // [rsp+B8h] [rbp+10h] BYREF

  v6 = start_pos;
  v8 = 82;
  if ( this->i_str_ref_p->i_length - start_pos >= 3 )
  {
    i_cstr_p = this->i_str_ref_p->i_cstr_p;
    v8 = 22;
    if ( i_cstr_p[start_pos] == 60 )
    {
      class_union.i_ref_count = 0;
      class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
      class_union.i_common_class_p = 0i64;
      class_union.i_union.i_count = 0;
      class_union.i_union.i_array_p = 0i64;
      class_union.i_union.i_size = 0;
      new_class = 0i64;
      p_new_class = &new_class;
      if ( !type_pp )
        p_new_class = 0i64;
      v11 = 0;
      do
      {
        v12 = v6 + 1;
        end_pos_pa = v12;
        if ( i_cstr_p[v12] == 60 )
          v13 = SSParser::parse_class_meta(this, v12, &end_pos_pa, (SSMetaClass **)p_new_class);
        else
          v13 = SSParser::parse_class_instance(this, v12, &end_pos_pa, (SSTypedClass **)p_new_class, 0i64);
        v8 = v13;
        if ( v13 )
        {
          v6 = end_pos_pa;
          goto LABEL_19;
        }
        ++v11;
        if ( p_new_class )
          SSClassUnion::merge_class(&class_union, new_class);
        v6 = end_pos_pa;
      }
      while ( i_cstr_p[end_pos_pa] == 124 );
      v8 = 23;
      if ( i_cstr_p[end_pos_pa] == 62 )
      {
        v6 = end_pos_pa + 1;
        v8 = 91;
        if ( v11 >= 2 )
        {
          v8 = 0;
          if ( type_pp )
          {
            v8 = 139;
            if ( class_union.i_union.i_count > 1 )
            {
              v8 = 0;
              *type_pp = SSClassUnion::get_or_create(&class_union);
            }
          }
        }
      }
LABEL_19:
      class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
      if ( class_union.i_common_class_p )
        class_union.i_common_class_p->vfptr->dereference_delay(class_union.i_common_class_p);
      i_array_p = class_union.i_union.i_array_p;
      if ( class_union.i_union.i_count )
      {
        v15 = (__int64 *)class_union.i_union.i_array_p;
        v16 = &class_union.i_union.i_array_p[class_union.i_union.i_count];
        if ( class_union.i_union.i_array_p < v16 )
        {
          do
             SSClassDescBase::`vcall{24,{flat}}(*v15++);
          while ( v15 < (__int64 *)v16 );
        }
      }
      AMemory::c_free_func(i_array_p);
      class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
    }
  }
  result = v8;
  if ( end_pos_p )
    *end_pos_p = v6;
  return result;
}

// File Line: 1206
// RVA: 0x127960
SSExpressionBase *__fastcall SSParser::parse_class_cast(
        SSParser *this,
        SSParser::Args *args,
        SSExpressionBase *receiver_p)
{
  char *i_cstr_p; // rdx
  __int64 v7; // r10
  SSExpressionBase *v8; // rbx
  SSParser::eResult v9; // eax
  SSClassDescBase *v10; // rsi
  SSClassDescBase *v11; // rax
  SSExpressionBase *v12; // rax
  unsigned int end_pos_p; // [rsp+50h] [rbp+8h] BYREF
  SSClassDescBase *type_pp; // [rsp+58h] [rbp+10h] BYREF

  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  end_pos_p = args->i_start_pos;
  v7 = end_pos_p;
  v8 = 0i64;
  args->i_result = Result_err_expected_cast_op;
  if ( (unsigned int)(this->i_str_ref_p->i_length - v7) >= 2
    && i_cstr_p[v7] == 60
    && i_cstr_p[(unsigned int)(v7 + 1)] == 62 )
  {
    v9 = SSParser::parse_class_desc(this, v7 + 2, &end_pos_p, &type_pp);
    args->i_result = v9;
    if ( v9 == Result_ok )
    {
      if ( (this->i_flags.i_flagset & 1) != 0 )
      {
        if ( type_pp )
          v10 = type_pp->vfptr->as_finalized_generic(type_pp, this->i_context.i_obj_scope_p);
        else
          v10 = 0i64;
        if ( args->i_type_p->vfptr->is_class_type(args->i_type_p, v10) )
        {
          v8 = receiver_p;
          goto LABEL_17;
        }
        if ( !v10->vfptr->is_class_type(v10, args->i_type_p) )
        {
          args->i_result = Result_err_typecheck_cast;
          goto LABEL_17;
        }
      }
      else
      {
        v10 = type_pp;
      }
      args->i_type_p = v10;
      if ( (args->i_flags & 1) != 0 )
      {
        v11 = (SSClassDescBase *)AMemory::c_malloc_func(0x18ui64, "SSCast");
        type_pp = v11;
        if ( v11 )
        {
          SSCast::SSCast((SSCast *)v11, v10, receiver_p);
          v8 = v12;
        }
      }
    }
LABEL_17:
    LODWORD(v7) = end_pos_p;
  }
  args->i_end_pos = v7;
  return v8;
}

// File Line: 1308
// RVA: 0x127A90
SSExpressionBase *__fastcall SSParser::parse_class_conversion(
        SSParser *this,
        SSParser::Args *args,
        SSExpressionBase *receiver_p,
        __int64 a4)
{
  char *i_cstr_p; // rdx
  __int64 i_start_pos; // rbp
  SSExpressionBase *v9; // rbx
  char *i_str_ref_p; // r8
  unsigned int i_length; // r10d
  unsigned int i_uid; // eax
  SSParser::eResult v13; // r11d
  SSClass **v14; // r10
  char *v15; // rdx
  _BOOL8 v16; // rcx
  __int64 v17; // rdi
  SSExpressionBase *v18; // rax
  SSExpressionBase *find_pos_p; // [rsp+70h] [rbp+8h] BYREF
  ASymbol result; // [rsp+78h] [rbp+10h] BYREF

  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  i_start_pos = args->i_start_pos;
  v9 = 0i64;
  args->i_result = Result_err_expected_conversion_op;
  i_str_ref_p = (char *)this->i_str_ref_p;
  i_length = this->i_str_ref_p->i_length;
  if ( i_length - (unsigned int)i_start_pos >= 2
    && i_cstr_p[i_start_pos] == 62
    && i_cstr_p[(unsigned int)(i_start_pos + 1)] == 62 )
  {
    i_start_pos = (unsigned int)(i_start_pos + 2);
    i_uid = -1;
    v13 = Result_err_unexpected_eof;
    LODWORD(find_pos_p) = i_start_pos;
    if ( i_length > (unsigned int)i_start_pos )
    {
      i_str_ref_p = *(char **)i_str_ref_p;
      v13 = Result_err_expected_class;
      a4 = (unsigned __int8)i_str_ref_p[i_start_pos];
      if ( AString::c_is_uppercase[a4] )
      {
        LODWORD(find_pos_p) = i_length;
        AString::find(this, ACharMatch_not_identifier, 1u, (unsigned int *)&find_pos_p, i_start_pos + 1, 0xFFFFFFFF);
        i_uid = SSParser::as_symbol(this, &result, i_start_pos, (unsigned int)find_pos_p)->i_uid;
        v13 = Result_ok;
        if ( i_uid == ASymbol_Class.i_uid )
          v13 = Result_err_unexpected_class_class;
        LODWORD(i_start_pos) = (_DWORD)find_pos_p;
      }
    }
    if ( v13 )
      goto LABEL_20;
    v13 = Result_err_context_non_class;
    if ( !SSBrain::c_classes.i_count )
      goto LABEL_20;
    i_str_ref_p = (char *)SSBrain::c_classes.i_array_p;
    v14 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v15 = &i_str_ref_p[8 * (((char *)v14 - i_str_ref_p) >> 4)];
        a4 = *(unsigned int *)(*(_QWORD *)v15 + 8i64);
        if ( i_uid >= (unsigned int)a4 )
          break;
        if ( i_str_ref_p == v15 )
          goto LABEL_20;
        v14 = (SSClass **)(v15 - 8);
      }
      v16 = i_uid == (_DWORD)a4;
      a4 = i_uid != (_DWORD)a4;
      if ( v16 )
        break;
      if ( v14 == (SSClass **)v15 )
        goto LABEL_20;
      i_str_ref_p = v15 + 8;
    }
    v17 = *(_QWORD *)v15;
    if ( *(_QWORD *)v15 )
      v13 = Result_ok;
    else
LABEL_20:
      v17 = (__int64)find_pos_p;
    args->i_result = v13;
    if ( v13 == Result_ok )
    {
      if ( (this->i_flags.i_flagset & 1) != 0 )
      {
        if ( ((unsigned __int8 (__fastcall *)(SSClassDescBase *, __int64, char *, __int64))args->i_type_p->vfptr->is_class_type)(
               args->i_type_p,
               v17,
               i_str_ref_p,
               a4) )
        {
          v9 = receiver_p;
          goto LABEL_30;
        }
        if ( !SSParser::get_method_inherited(this, (SSClassUnion *)args->i_type_p, (ASymbol *)(v17 + 8)) )
        {
          args->i_result = Result_err_context_non_method;
          goto LABEL_30;
        }
      }
      args->i_type_p = (SSClassDescBase *)v17;
      if ( (args->i_flags & 1) != 0 )
      {
        v18 = (SSExpressionBase *)AMemory::c_malloc_func(0x18ui64, "SSConversion");
        find_pos_p = v18;
        if ( v18 )
        {
          v18->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
          v18->vfptr = (SSExpressionBaseVtbl *)&SSConversion::`vftable;
          v18[1].vfptr = (SSExpressionBaseVtbl *)v17;
          v18[2].vfptr = (SSExpressionBaseVtbl *)receiver_p;
          v9 = v18;
        }
      }
    }
  }
LABEL_30:
  args->i_end_pos = i_start_pos;
  return v9;
}

// File Line: 1741
// RVA: 0x128610
SSLiteralClosure *__fastcall SSParser::parse_closure(SSParser *this, SSParser::Args *args)
{
  unsigned int i_start_pos; // ecx
  __int64 v6; // rdi
  AStringRef *i_str_ref_p; // rcx
  char *i_cstr_p; // r15
  __int64 v9; // rdx
  char v10; // cl
  __int64 v11; // r9
  SSParser::eResult v12; // eax
  SSClassDescBase *i_type_p; // rcx
  __int64 v14; // rax
  SSClassUnaryBase *v15; // r14
  SSParser::eResult v16; // eax
  SSClass *v17; // rax
  SSParameters *p_params_p; // r12
  unsigned int v19; // ecx
  SSParser::eResult v20; // eax
  SSParser::eResult v21; // eax
  SSClass *v22; // r14
  SSClassDescBase *i_obj_p; // rdx
  bool v24; // r14
  SSExpressionBase *i_expr_p; // r14
  int v26; // r12d
  eSSExprType v27; // r15d
  __int64 v28; // rax
  SSParameters *v29; // rax
  char *v30; // rax
  __int64 v31; // rax
  SSClosureInfoBase *v32; // rax
  SSLiteralClosure closure_method_p; // [rsp+30h] [rbp-D0h] BYREF
  void **v35; // [rsp+50h] [rbp-B0h] BYREF
  int v36; // [rsp+58h] [rbp-A8h]
  AVCompactSortedLogical<ASymbol,ASymbol> captured_p; // [rsp+60h] [rbp-A0h] BYREF
  SSMethod v38; // [rsp+70h] [rbp-90h] BYREF
  SSParameters params_p; // [rsp+A0h] [rbp-60h] BYREF
  char v40[8]; // [rsp+D0h] [rbp-30h] BYREF
  SSParser *v41; // [rsp+D8h] [rbp-28h]
  SSClassUnaryBase *v42; // [rsp+E0h] [rbp-20h]
  eSSMember i_member_type; // [rsp+E8h] [rbp-18h]
  char v44; // [rsp+ECh] [rbp-14h]
  __int64 v45; // [rsp+F0h] [rbp-10h]
  unsigned int end_pos_p; // [rsp+150h] [rbp+50h] BYREF
  void *p_i_params; // [rsp+158h] [rbp+58h]
  void *p_i_return_params; // [rsp+160h] [rbp+60h]
  SSClassUnaryBase *i_obj_scope_p; // [rsp+168h] [rbp+68h]

  v45 = -2i64;
  i_start_pos = args->i_start_pos;
  end_pos_p = i_start_pos;
  if ( this->i_str_ref_p->i_length < i_start_pos )
  {
    args->i_end_pos = i_start_pos;
    args->i_result = Result_err_unexpected_eof;
    return 0i64;
  }
  LODWORD(p_i_params) = 3;
  closure_method_p.vfptr = (SSExpressionBaseVtbl *)&SSLiteralClosure::`vftable;
  v6 = 0i64;
  closure_method_p.i_receiver_p = 0i64;
  closure_method_p.i_info_p.i_obj_p = 0i64;
  captured_p.i_count = 0;
  captured_p.i_array_p = 0i64;
  p_i_return_params = &v38;
  v38.i_name = ASymbol_closure;
  v38.i_scope_p = SSBrain::c_object_class_p;
  v38.i_params_p.i_obj_p = 0i64;
  v38.i_expr_p = 0i64;
  v35 = &SSClosureInfoMethod::`vftable{for `SSClosureInfoBase};
  v38.vfptr = (SSInvokableBaseVtbl *)&SSClosureInfoMethod::`vftable{for `SSMethod};
  v36 = 1;
  if ( &v35 )
  {
    v36 = 2;
    closure_method_p.i_info_p.i_obj_p = (SSClosureInfoBase *)&v35;
  }
  v41 = this;
  i_obj_scope_p = this->i_context.i_obj_scope_p;
  v42 = i_obj_scope_p;
  i_member_type = this->i_member_type;
  v44 = 0;
  i_str_ref_p = this->i_str_ref_p;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  if ( i_cstr_p[end_pos_p] != 64 )
    goto LABEL_26;
  v9 = end_pos_p + 1;
  end_pos_p = v9;
  if ( i_str_ref_p->i_length >= (unsigned int)v9 )
  {
    v10 = i_cstr_p[v9];
    if ( v10 == 39 )
    {
      args->i_end_pos = v9;
      args->i_result = Result_err_unexpected_obj_identifier;
      goto LABEL_66;
    }
    if ( v10 == 95 )
    {
      v11 = (unsigned int)(v9 + 1);
      if ( !AString::c_is_lowercase[(unsigned __int8)i_cstr_p[v11]] )
      {
        end_pos_p = v9 + 1;
        LODWORD(p_i_params) = 2;
        v12 = SSParser::parse_ws_any(this, v11, &end_pos_p);
        args->i_result = v12;
        if ( v12 )
        {
          args->i_end_pos = end_pos_p;
          goto LABEL_66;
        }
        LODWORD(v9) = end_pos_p;
      }
    }
    args->i_start_pos = v9;
    if ( i_cstr_p[(unsigned int)v9] != 91 )
    {
      closure_method_p.i_receiver_p = SSParser::parse_expression(this, args, SSInvokeTime_immediate);
      if ( args->i_result )
        goto LABEL_66;
      i_type_p = args->i_type_p;
      if ( i_type_p )
        v14 = (__int64)i_type_p->vfptr->as_finalized_generic(i_type_p, this->i_context.i_obj_scope_p);
      else
        v14 = 0i64;
      v15 = (SSClassUnaryBase *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 40i64))(v14);
      v16 = SSParser::parse_ws_any(this, args->i_end_pos, &end_pos_p);
      args->i_result = v16;
      if ( v16 )
      {
        args->i_end_pos = end_pos_p;
        goto LABEL_66;
      }
      if ( this->i_context.i_obj_scope_p != v15 )
      {
        v17 = SSBrain::c_object_class_p;
        if ( v15 )
          v17 = (SSClass *)v15;
        this->i_context.i_obj_scope_p = v17;
      }
    }
LABEL_26:
    this->i_member_type = SSMember_coroutine;
    if ( (this->i_flags.i_flagset & 1) != 0 )
    {
      SSTypeContext::capture_locals(&this->i_context);
      v44 = 1;
    }
    params_p.i_ref_count = 0;
    params_p.i_params.i_count = 0;
    params_p.i_params.i_array_p = 0i64;
    p_i_return_params = &params_p.i_return_params;
    params_p.i_return_params.i_count = 0;
    params_p.i_return_params.i_array_p = 0i64;
    params_p.i_result_type_p.i_obj_p = SSBrain::c_object_class_p;
    if ( SSBrain::c_object_class_p )
      (*(void (__fastcall **)(SSClass *))SSBrain::c_object_class_p->vfptr->gap8)(SSBrain::c_object_class_p);
    p_params_p = &params_p;
    if ( (args->i_flags & 1) == 0 )
      p_params_p = 0i64;
    v19 = end_pos_p;
    LODWORD(p_i_return_params) = end_pos_p;
    if ( i_cstr_p[end_pos_p] == 40 )
    {
      v20 = SSParser::parse_parameters(this, end_pos_p, &end_pos_p, p_params_p, 1u);
      args->i_result = v20;
      if ( v20 )
      {
        args->i_end_pos = end_pos_p;
LABEL_63:
        APCompactArrayBase<SSParameterBase>::free_all(&params_p.i_params);
        APCompactArrayBase<SSTypedName>::free_all(&params_p.i_return_params);
        if ( params_p.i_result_type_p.i_obj_p )
          (*(void (__fastcall **)(SSClassDescBase *))&params_p.i_result_type_p.i_obj_p->vfptr->gap8[8])(params_p.i_result_type_p.i_obj_p);
        p_i_params = &params_p.i_return_params;
        AMemory::c_free_func(params_p.i_return_params.i_array_p);
        p_i_params = &params_p.i_params;
        AMemory::c_free_func(params_p.i_params.i_array_p);
        goto LABEL_66;
      }
      v21 = SSParser::parse_ws_any(this, end_pos_p, &end_pos_p);
      args->i_result = v21;
      if ( v21 )
      {
        args->i_end_pos = end_pos_p;
        goto LABEL_63;
      }
      v19 = end_pos_p;
    }
    else
    {
      v22 = SSBrain::c_auto_class_p;
      i_obj_p = params_p.i_result_type_p.i_obj_p;
      if ( params_p.i_result_type_p.i_obj_p != SSBrain::c_auto_class_p )
      {
        if ( SSBrain::c_auto_class_p )
        {
          (*(void (__fastcall **)(SSClass *))SSBrain::c_auto_class_p->vfptr->gap8)(SSBrain::c_auto_class_p);
          v19 = end_pos_p;
          i_obj_p = params_p.i_result_type_p.i_obj_p;
        }
        if ( i_obj_p )
        {
          (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
          v19 = end_pos_p;
        }
        params_p.i_result_type_p.i_obj_p = v22;
      }
    }
    args->i_start_pos = v19;
    v38.i_expr_p = SSParser::parse_code_block_optimized(this, args, SSInvokeTime_any, ResultDesired_true);
    v24 = 0;
    if ( args->i_result == Result_ok )
    {
      v24 = SSParser::typecheck_parameters(this, args, p_params_p, 1) && v38.i_expr_p;
      if ( SSParameters::is_generic(p_params_p) )
      {
        v24 = 0;
        args->i_end_pos = (unsigned int)p_i_return_params;
        args->i_result = Result_err_typecheck_closure_generics;
      }
    }
    if ( !v24 )
      goto LABEL_63;
    SSTypeContext::capture_locals_stop(&this->i_context, &captured_p);
    v44 = 0;
    i_expr_p = v38.i_expr_p;
    v26 = (int)p_i_params;
    if ( (_DWORD)p_i_params == 3 )
    {
      if ( !v38.i_expr_p )
      {
        v26 = 1;
        goto LABEL_57;
      }
      v26 = 2 - v38.i_expr_p->vfptr->is_immediate(v38.i_expr_p, 0i64);
    }
    if ( v26 != 1 )
    {
      v27 = SSExprType_closure_coroutine;
      if ( i_expr_p )
      {
        v28 = (__int64)i_expr_p->vfptr->find_expr_last_no_side_effect(i_expr_p);
        if ( v28 )
        {
          args->i_result = ((*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v28 + 24i64))(v28) == 1) + 6;
          goto LABEL_63;
        }
      }
LABEL_61:
      v38.i_scope_p = i_obj_scope_p->vfptr->get_key_class(i_obj_scope_p);
      v38.i_name.i_uid = this->i_context.i_scope_name.i_uid;
      v29 = SSParameters::get_or_create(&params_p);
      ARefPtr<SSParameters>::operator=(&v38.i_params_p, v29);
      args->i_type_p = SSInvokableClass::get_or_create(
                         SSBrain::c_closure_class_p,
                         v38.i_params_p.i_obj_p,
                         (eSSInvokeTime)v26);
      v30 = UFG::qMalloc(0x18ui64, "SSLiteralClosure", 0i64);
      p_i_params = v30;
      if ( v30 )
      {
        SSLiteralClosure::SSLiteralClosure((SSLiteralClosure *)v30, &closure_method_p, v27);
        v6 = v31;
      }
      goto LABEL_63;
    }
LABEL_57:
    v27 = SSExprType_closure_method;
    goto LABEL_61;
  }
  args->i_end_pos = v9;
  args->i_result = Result_err_unexpected_eof;
LABEL_66:
  SSParser::parse_closure_::_2_::NestedDtor::_NestedDtor((__int64)v40);
  v35 = &SSClosureInfoMethod::`vftable{for `SSClosureInfoBase};
  v38.vfptr = (SSInvokableBaseVtbl *)&SSClosureInfoMethod::`vftable{for `SSMethod};
  SSMethod::~SSMethod(&v38);
  v35 = &SSClosureInfoBase::`vftable;
  p_i_params = &captured_p;
  AMemory::c_free_func(captured_p.i_array_p);
  closure_method_p.vfptr = (SSExpressionBaseVtbl *)&SSLiteralClosure::`vftable;
  if ( closure_method_p.i_receiver_p )
    closure_method_p.i_receiver_p->vfptr->__vecDelDtor(closure_method_p.i_receiver_p, 1u);
  v32 = closure_method_p.i_info_p.i_obj_p;
  if ( closure_method_p.i_info_p.i_obj_p )
  {
    if ( closure_method_p.i_info_p.i_obj_p->i_ref_count-- == 1 )
    {
      v32->i_ref_count = 0x80000000;
      if ( v32 != (SSClosureInfoBase *)-8i64 )
      {
        if ( v32 )
          v32->vfptr->__vecDelDtor(v32, 1u);
      }
    }
  }
  return (SSLiteralClosure *)v6;
}

// File Line: 1769
// RVA: 0x1069F0
__int64 __fastcall SSParser::parse_closure_::_2_::NestedDtor::_NestedDtor(__int64 a1)
{
  AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v2; // rsi
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *i_next_p; // rbx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v4; // rcx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *i_prev_p; // rax
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v6; // rdx
  __int64 result; // rax

  if ( *(_BYTE *)(a1 + 28) )
  {
    v2 = *(AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> **)(a1 + 8);
    i_next_p = v2[8].i_sentinel.i_next_p;
    if ( i_next_p )
    {
      AMemory::c_free_func(i_next_p[1].i_prev_p);
      v4 = i_next_p->i_next_p;
      if ( i_next_p->i_next_p != i_next_p )
      {
        i_prev_p = i_next_p->i_prev_p;
        v4->i_prev_p = i_prev_p;
        i_prev_p->i_next_p = v4;
        i_next_p->i_prev_p = i_next_p;
        i_next_p->i_next_p = i_next_p;
      }
      operator delete[](i_next_p);
    }
    v6 = 0i64;
    if ( (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> **)v2[8].i_sentinel.i_next_p != &v2[7].i_sentinel.i_prev_p )
      v6 = v2[8].i_sentinel.i_next_p;
    v2[8].i_sentinel.i_prev_p = v6;
    AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>::free_last(v2 + 6);
    v2[7].i_sentinel.i_next_p = v2[6].i_sentinel.i_prev_p + 1;
  }
  *(_QWORD *)(*(_QWORD *)(a1 + 8) + 16i64) = *(_QWORD *)(a1 + 16);
  result = *(unsigned int *)(a1 + 24);
  *(_DWORD *)(*(_QWORD *)(a1 + 8) + 12i64) = result;
  return result;
}

// File Line: 2080
// RVA: 0x128BF0
SSCode *__fastcall SSParser::parse_code_block(
        SSParser *this,
        SSParser::Args *args,
        eSSInvokeTime desired_exec_time,
        SSParser::eResultDesired result)
{
  eSSInvokeTime v4; // ebp
  SSCode *v7; // rdi
  char *i_cstr_p; // r13
  unsigned int i_length; // r14d
  __int64 i_start_pos; // rbx
  SSParser::eResult v11; // eax
  SSCode *v12; // rax
  bool v13; // al
  int v14; // ebp
  SSParser::eResult v15; // eax
  char v16; // cl
  unsigned int i_count; // eax
  SSExpressionBaseVtbl *v18; // r14
  SSExpressionBase *v19; // rax
  unsigned int v20; // ebx
  SSParser::eResult v21; // eax
  unsigned int v22; // eax
  SSExpressionBase *v23; // rcx
  __int64 v24; // rax
  unsigned int v25; // eax
  SSExpressionBase *v26; // rcx
  __int64 v27; // rax
  SSExpressionBase *end_pos_p; // [rsp+A0h] [rbp+8h] BYREF
  unsigned int v30; // [rsp+A8h] [rbp+10h]
  eSSInvokeTime v31; // [rsp+B0h] [rbp+18h]
  SSParser::eResultDesired v32; // [rsp+B8h] [rbp+20h]

  v32 = result;
  v31 = desired_exec_time;
  v4 = desired_exec_time;
  args->i_result = Result_err_unexpected_eof;
  v7 = 0i64;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  i_length = this->i_str_ref_p->i_length;
  v30 = i_length;
  i_start_pos = args->i_start_pos;
  if ( i_length - (unsigned int)i_start_pos < 2 )
    goto LABEL_61;
  args->i_result = Result_err_expected_code_block;
  if ( i_cstr_p[i_start_pos] != 91 )
    goto LABEL_61;
  LODWORD(end_pos_p) = i_start_pos + 1;
  v11 = SSParser::parse_ws_any(this, i_start_pos + 1, (unsigned int *)&end_pos_p);
  args->i_result = v11;
  if ( v11 )
  {
    LODWORD(i_start_pos) = (_DWORD)end_pos_p;
    goto LABEL_61;
  }
  if ( (args->i_flags & 1) != 0 )
  {
    v12 = (SSCode *)AMemory::c_malloc_func(0x28ui64, "SSCode");
    v7 = v12;
    if ( v12 )
    {
      v12->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
      v12->vfptr = (SSExpressionBaseVtbl *)&SSCode::`vftable;
      v12->i_temp_vars.i_count = 0;
      v12->i_temp_vars.i_array_p = 0i64;
      v12->i_statements.i_count = 0;
      v12->i_statements.i_array_p = 0i64;
    }
    else
    {
      v7 = 0i64;
    }
  }
  LODWORD(i_start_pos) = (_DWORD)end_pos_p;
  if ( i_cstr_p[(unsigned int)end_pos_p] == 93 )
  {
    LODWORD(i_start_pos) = (_DWORD)end_pos_p + 1;
    args->i_type_p = SSBrain::c_none_class_p;
    args->i_result = Result_ok;
    goto LABEL_61;
  }
  args->i_result = Result_err_unexpected_eof;
  if ( (unsigned int)i_start_pos < i_length )
  {
    while ( 1 )
    {
      args->i_start_pos = i_start_pos;
      v13 = SSParser::parse_statement_append(this, args, v7, v4);
      LODWORD(i_start_pos) = args->i_end_pos;
      LODWORD(end_pos_p) = i_start_pos;
      if ( !v13 )
        break;
      v14 = i_start_pos;
      v15 = SSParser::parse_ws_any(this, i_start_pos, (unsigned int *)&end_pos_p);
      args->i_result = v15;
      if ( v15 )
      {
        args->i_start_pos = i_start_pos;
LABEL_42:
        LODWORD(i_start_pos) = (_DWORD)end_pos_p;
        break;
      }
      LODWORD(i_start_pos) = (_DWORD)end_pos_p;
      v16 = i_cstr_p[(unsigned int)end_pos_p];
      switch ( v16 )
      {
        case %:
          ++`anonymous namespace::SSParser_old_branch_delimiter;
          if ( v7 )
          {
            i_count = v7->i_statements.i_count;
            if ( i_count )
              v18 = (SSExpressionBaseVtbl *)v7->i_statements.i_array_p[i_count - 1];
            else
              v18 = 0i64;
            if ( (*((unsigned __int8 (__fastcall **)(SSExpressionBaseVtbl *, _QWORD))v18->__vecDelDtor + 9))(v18, 0i64) )
            {
              args->i_result = Result_err_unexpected_branch_expr;
              goto LABEL_43;
            }
            APCompactArrayBase<SSExpressionBase>::remove_last(&v7->i_statements);
            v19 = (SSExpressionBase *)AMemory::c_malloc_func(0x10ui64, "SSConcurrentBranch");
            end_pos_p = v19;
            if ( v19 )
            {
              v19->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
              v19->vfptr = (SSExpressionBaseVtbl *)&SSConcurrentBranch::`vftable;
              v19[1].vfptr = v18;
            }
            APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
              &v7->i_statements,
              v19);
            args->i_type_p = SSBrain::c_none_class_p;
            i_length = v30;
          }
          v20 = i_start_pos + 1;
          LODWORD(end_pos_p) = v20;
          args->i_start_pos = v20;
          v21 = SSParser::parse_ws_any(this, v20, (unsigned int *)&end_pos_p);
          args->i_result = v21;
          if ( v21 )
            goto LABEL_42;
          LODWORD(i_start_pos) = (_DWORD)end_pos_p;
          if ( i_cstr_p[(unsigned int)end_pos_p] == 93 )
            goto LABEL_40;
          break;
        case ,:
          args->i_result = Result_err_unexpected_deprecated;
          goto LABEL_43;
        case ;:
          args->i_result = Result_err_unexpected_cpp;
          goto LABEL_43;
        case ]:
LABEL_40:
          LODWORD(i_start_pos) = i_start_pos + 1;
          goto LABEL_43;
        default:
          if ( v14 == (_DWORD)end_pos_p )
          {
            args->i_result = Result_err_unexpected_statement;
            goto LABEL_43;
          }
          break;
      }
      if ( v7 )
      {
        v22 = v7->i_statements.i_count;
        if ( v22 )
        {
          v23 = v7->i_statements.i_array_p[v22 - 1];
          if ( v23 )
          {
            v24 = (__int64)v23->vfptr->find_expr_last_no_side_effect(v23);
            if ( v24 )
            {
              args->i_result = ((*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v24 + 24i64))(v24) == 1) + 6;
              break;
            }
          }
        }
      }
      args->i_result = Result_err_unexpected_eof;
      if ( (unsigned int)i_start_pos >= i_length )
        break;
      v4 = v31;
    }
  }
LABEL_43:
  if ( v32 == ResultDesired_false && v7 )
  {
    if ( args->i_result )
      goto LABEL_55;
    v25 = v7->i_statements.i_count;
    if ( v25 )
    {
      v26 = v7->i_statements.i_array_p[v25 - 1];
      if ( v26 )
      {
        v27 = (__int64)v26->vfptr->find_expr_last_no_side_effect(v26);
        if ( v27 )
          args->i_result = ((*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v27 + 24i64))(v27) == 1) + 6;
      }
    }
  }
  if ( args->i_result == Result_ok )
  {
    if ( (this->i_flags.i_flagset & 1) != 0 )
    {
      (*(void (__fastcall **)(SSClassDescBase *))args->i_type_p->vfptr->gap8)(args->i_type_p);
      if ( v7 )
        SSTypeContext::archive_locals(&this->i_context, &v7->i_temp_vars);
      args->i_type_p->vfptr->dereference_delay(args->i_type_p);
    }
    goto LABEL_61;
  }
LABEL_55:
  if ( (this->i_flags.i_flagset & 1) != 0 )
  {
    if ( !v7 )
      goto LABEL_61;
    APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::free_all(
      this->i_context.i_current_scope_p,
      v7->i_temp_vars.i_array_p,
      v7->i_temp_vars.i_count,
      0,
      0xFFFFFFFF);
  }
  if ( v7 )
  {
    v7->vfptr->__vecDelDtor(v7, 1u);
    v7 = 0i64;
  }
LABEL_61:
  args->i_end_pos = i_start_pos;
  return v7;
}

// File Line: 2435
// RVA: 0x128FD0
SSCode *__fastcall SSParser::parse_code_block_optimized(
        SSParser *this,
        SSParser::Args *args,
        eSSInvokeTime desired_exec_time,
        SSParser::eResultDesired result)
{
  SSExpressionBase *v5; // rbx
  SSCode *v6; // rax
  SSCode *v7; // rdi
  unsigned int i_count; // eax

  if ( (args->i_flags & 1) == 0 )
    return SSParser::parse_code_block(this, args, desired_exec_time, result);
  v5 = 0i64;
  v6 = SSParser::parse_code_block(this, args, desired_exec_time, result);
  v7 = v6;
  if ( v6 )
  {
    i_count = v6->i_statements.i_count;
    if ( i_count )
    {
      if ( i_count != 1 || v7->i_temp_vars.i_count )
      {
        return v7;
      }
      else
      {
        v5 = *v7->i_statements.i_array_p;
        AMemory::c_free_func(v7->i_statements.i_array_p);
        v7->i_statements.i_array_p = 0i64;
        v7->i_statements.i_count = 0;
        v7->vfptr->__vecDelDtor(v7, 1u);
      }
    }
    else
    {
      v5 = (SSExpressionBase *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
      if ( v5 )
      {
        v5->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
        v5->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
        v5[1].vfptr = 0i64;
        LODWORD(v5[2].vfptr) = 7;
      }
      else
      {
        v5 = 0i64;
      }
      v7->vfptr->__vecDelDtor(v7, 1u);
    }
  }
  return (SSCode *)v5;
}

// File Line: 2570
// RVA: 0x1290B0
__int64 __fastcall SSParser::parse_comment_multiline(SSParser *this, __int64 start_pos, unsigned int *end_pos_p)
{
  AStringRef *i_str_ref_p; // rbx
  unsigned int i_length; // esi
  char *i_cstr_p; // rbx
  __int64 v8; // rdx
  char v9; // cl
  SSParser::eResult v10; // eax
  unsigned int v11; // edx
  SSParser::eResult v12; // eax
  unsigned int end_pos_pa; // [rsp+38h] [rbp+10h] BYREF

  i_str_ref_p = this->i_str_ref_p;
  i_length = this->i_str_ref_p->i_length;
  end_pos_pa = start_pos;
  if ( (int)start_pos + 2 <= i_length )
  {
    i_cstr_p = i_str_ref_p->i_cstr_p;
    if ( i_cstr_p[(unsigned int)start_pos] == 47 )
    {
      start_pos = (unsigned int)(start_pos + 1);
      end_pos_pa = start_pos;
      if ( i_cstr_p[start_pos] == 42 )
      {
        v8 = (unsigned int)(start_pos + 2);
        end_pos_pa = v8;
        if ( (unsigned int)v8 >= i_length )
        {
LABEL_16:
          if ( end_pos_p )
            *end_pos_p = v8;
          return 26i64;
        }
        while ( 1 )
        {
          v9 = i_cstr_p[v8];
          if ( v9 == 42 )
          {
            v12 = SSParser::parse_comment_multiline(this, v8 - 1, &end_pos_pa);
            v11 = end_pos_pa;
            if ( v12 == Result_ok )
              goto LABEL_14;
            if ( i_cstr_p[end_pos_pa + 2] == 47 )
            {
              if ( end_pos_p )
                *end_pos_p = end_pos_pa + 3;
              return 0i64;
            }
            v8 = end_pos_pa + 3;
          }
          else if ( v9 == 47 )
          {
            if ( i_cstr_p[(unsigned int)(v8 - 1)] == 42 )
            {
              if ( end_pos_p )
                *end_pos_p = v8 + 1;
              return 0i64;
            }
            v10 = SSParser::parse_comment_multiline(this, v8, &end_pos_pa);
            v11 = end_pos_pa;
            if ( v10 == Result_ok )
            {
LABEL_14:
              v8 = v11 + 1;
              goto LABEL_15;
            }
            v8 = end_pos_pa + 2;
          }
          else
          {
            v8 = (unsigned int)(v8 + 2);
          }
LABEL_15:
          end_pos_pa = v8;
          if ( (unsigned int)v8 >= i_length )
            goto LABEL_16;
        }
      }
    }
  }
  if ( end_pos_p )
    *end_pos_p = start_pos;
  return 73i64;
}

// File Line: 2678
// RVA: 0x129550
SSConditional *__fastcall SSParser::parse_conditional_tail(SSParser *this, SSParser::Args *args)
{
  unsigned int i_start_pos; // ebx
  char *i_cstr_p; // r15
  SSExpressionBase *v6; // r12
  __int64 i_count; // r13
  unsigned int v8; // r14d
  char *v9; // rcx
  SSParser::eResult v10; // eax
  SSParser::eResult v11; // eax
  unsigned int v12; // eax
  SSTypedName **i_array_p; // rax
  SSParser::eResult v14; // eax
  SSCode *v15; // r14
  SSClause *v16; // rax
  char v17; // r14
  unsigned int v18; // eax
  void (__fastcall ***v19)(_QWORD, __int64); // r13
  SSTypedName **v20; // r12
  SSClassUnaryBase *i_common_class_p; // r14
  SSClassUnaryBase *v22; // rax
  SSTypedName **v23; // rdi
  SSTypedName **v24; // r15
  SSTypedName *v25; // rbx
  SSClassDescBase *i_obj_p; // rcx
  SSClassUnaryBase **v27; // rsi
  __int64 *v28; // rbx
  SSClassUnaryBase **v29; // rdi
  unsigned int v31; // [rsp+20h] [rbp-89h]
  void (__fastcall ***v32)(_QWORD, __int64); // [rsp+28h] [rbp-81h]
  APCompactArray<SSClause,SSClause,ACompareAddress<SSClause> > *v33; // [rsp+30h] [rbp-79h]
  unsigned int i_length; // [rsp+38h] [rbp-71h]
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > sorted; // [rsp+40h] [rbp-69h] BYREF
  APSortedLogical<SSTypedName,ASymbol> merge_vars_p; // [rsp+58h] [rbp-51h] BYREF
  SSClassUnion class_union; // [rsp+70h] [rbp-39h] BYREF
  unsigned __int64 v38; // [rsp+A0h] [rbp-9h]
  SSClause *v39; // [rsp+A8h] [rbp-1h]
  __int64 v40; // [rsp+B0h] [rbp+7h]
  char v41; // [rsp+110h] [rbp+67h]
  char v42; // [rsp+118h] [rbp+6Fh]
  unsigned int end_pos_p; // [rsp+120h] [rbp+77h] BYREF
  int v44; // [rsp+128h] [rbp+7Fh]

  v40 = -2i64;
  i_start_pos = args->i_start_pos;
  v31 = args->i_start_pos;
  i_length = this->i_str_ref_p->i_length;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  v6 = 0i64;
  class_union.i_ref_count = 0;
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
  class_union.i_common_class_p = 0i64;
  class_union.i_union.i_count = 0;
  class_union.i_union.i_array_p = 0i64;
  class_union.i_union.i_size = 0;
  merge_vars_p.i_count = 0;
  merge_vars_p.i_array_p = 0i64;
  merge_vars_p.i_size = 0;
  LODWORD(i_count) = 0;
  sorted.i_count = 0;
  sorted.i_array_p = 0i64;
  v8 = 0;
  v38 = 0i64;
  sorted.i_size = 0;
  v32 = 0i64;
  if ( (args->i_flags & 1) != 0
    && ((v9 = (char *)AMemory::c_malloc_func(0x18ui64, "SSConditional"),
         (v32 = (void (__fastcall ***)(_QWORD, __int64))v9) == 0i64)
      ? (v9 = 0i64, v32 = 0i64)
      : (void (__fastcall ***)(_QWORD, __int64))(*(_QWORD *)v9 = &SSExpressionBase::`vftable,
                                                 *(_QWORD *)v9 = &SSConditional::`vftable,
                                                 *((_DWORD *)v9 + 2) = 0,
                                                 *((_QWORD *)v9 + 2) = 0i64),
        v9) )
  {
    v33 = (APCompactArray<SSClause,SSClause,ACompareAddress<SSClause> > *)(v9 + 8);
  }
  else
  {
    v33 = 0i64;
  }
  v44 = 0;
  end_pos_p = i_start_pos;
  v41 = 0;
  while ( 1 )
  {
    v10 = SSParser::parse_ws_any(this, i_start_pos, &end_pos_p);
    args->i_result = v10;
    v42 = 0;
    if ( v10 )
    {
      i_start_pos = end_pos_p;
      goto LABEL_47;
    }
    args->i_result = Result_err_expected_clause_block;
    i_start_pos = end_pos_p;
    if ( i_length - end_pos_p < 3 )
      break;
    if ( i_cstr_p[end_pos_p] == 101
      && i_cstr_p[end_pos_p + 1] == 108
      && i_cstr_p[end_pos_p + 2] == 115
      && i_cstr_p[end_pos_p + 3] == 101
      && byte_14236F1C0[(unsigned __int8)i_cstr_p[end_pos_p + 4]] )
    {
      i_start_pos = end_pos_p + 4;
      end_pos_p += 4;
      v11 = Result_err_unexpected_else;
      if ( v44 )
        v11 = Result_ok;
      args->i_result = v11;
      v6 = 0i64;
      v42 = 1;
      v41 = 1;
    }
    else
    {
      i_count = this->i_context.i_top_scope_old.i_count;
      sorted.i_count = i_count;
      if ( (unsigned int)i_count <= v8 )
      {
        i_array_p = sorted.i_array_p;
      }
      else
      {
        AMemory::c_free_func(sorted.i_array_p);
        v12 = AMemory::c_req_byte_size_func(8 * i_count);
        v38 = (unsigned __int64)v12 >> 3;
        sorted.i_size = v12 >> 3;
        i_array_p = APArrayBase<SSTypedName>::alloc_array(v12 >> 3);
        sorted.i_array_p = i_array_p;
      }
      memmove(i_array_p, this->i_context.i_top_scope_old.i_array_p, 8 * i_count);
      args->i_start_pos = i_start_pos;
      v6 = SSParser::parse_expression(this, args, SSInvokeTime_immediate);
      i_start_pos = args->i_end_pos;
      end_pos_p = i_start_pos;
      if ( (this->i_flags.i_flagset & 1) != 0 )
      {
        if ( args->i_result )
          goto LABEL_44;
        if ( !args->i_type_p->vfptr->is_class_type(args->i_type_p, SSBrain::c_boolean_class_p) )
        {
          args->i_result = Result_err_typecheck_conditional;
          goto LABEL_44;
        }
      }
    }
    if ( args->i_result == Result_ok )
    {
      v14 = SSParser::parse_ws_any(this, i_start_pos, &end_pos_p);
      args->i_result = v14;
      if ( v14 )
      {
        i_start_pos = end_pos_p;
      }
      else
      {
        args->i_result = Result_err_expected_clause_block;
        i_start_pos = end_pos_p;
        if ( i_cstr_p[end_pos_p] == 91 )
        {
          if ( (this->i_flags.i_flagset & 1) != 0 )
            SSTypeContext::nest_locals(&this->i_context);
          v42 = 1;
          args->i_start_pos = i_start_pos;
          v15 = SSParser::parse_code_block_optimized(this, args, SSInvokeTime_any, ResultDesired_true);
          i_start_pos = args->i_end_pos;
          end_pos_p = i_start_pos;
          if ( args->i_result == Result_ok )
          {
            v31 = i_start_pos;
            ++v44;
            if ( v33 )
            {
              v16 = (SSClause *)AMemory::c_malloc_func(0x18ui64, "SSClause");
              v39 = v16;
              if ( v16 )
              {
                v16->vfptr = (SSClauseVtbl *)&SSClause::`vftable;
                v16->i_test_p = v6;
                v16->i_clause_p = v15;
              }
              APCompactArray<SSClause,SSClause,ACompareAddress<SSClause>>::append(v33, v16);
            }
            if ( (this->i_flags.i_flagset & 1) == 0 )
              goto LABEL_44;
            SSClassUnion::merge_class(&class_union, (SSClassUnion *)args->i_type_p);
            if ( merge_vars_p.i_count || this->i_context.i_current_scope_p->i_count )
              SSTypeContext::merge_locals(&this->i_context, &merge_vars_p, v44 == 1);
          }
          if ( (this->i_flags.i_flagset & 1) != 0 )
          {
            AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>::free_last(&this->i_context.i_scope_stack);
            this->i_context.i_current_scope_p = (APSortedLogical<SSTypedName,ASymbol> *)&this->i_context.i_scope_stack.i_sentinel.i_prev_p[1];
          }
        }
      }
    }
LABEL_44:
    v17 = v41;
    if ( v41 )
      goto LABEL_49;
    v8 = v38;
LABEL_47:
    if ( args->i_result )
      break;
    v6 = 0i64;
  }
  v17 = 0;
LABEL_49:
  if ( args->i_result )
  {
    if ( v6 )
      v6->vfptr->__vecDelDtor(v6, 1u);
    if ( !v42 && v44 )
    {
      APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::remove_all_all(
        &this->i_context.i_top_scope_old,
        &sorted,
        0,
        0xFFFFFFFF);
      APSizedArrayBase<SSTypedName>::free_all(&this->i_context.i_top_scope_old);
      this->i_context.i_top_scope_old.i_count = i_count;
      if ( (unsigned int)i_count > this->i_context.i_top_scope_old.i_size )
      {
        AMemory::c_free_func(this->i_context.i_top_scope_old.i_array_p);
        v18 = AMemory::c_req_byte_size_func(8 * this->i_context.i_top_scope_old.i_count) >> 3;
        this->i_context.i_top_scope_old.i_size = v18;
        this->i_context.i_top_scope_old.i_array_p = APArrayBase<SSTypedName>::alloc_array(v18);
      }
      memmove(
        this->i_context.i_top_scope_old.i_array_p,
        sorted.i_array_p,
        8i64 * this->i_context.i_top_scope_old.i_count);
      args->i_result = Result_ok;
      goto LABEL_59;
    }
    v31 = i_start_pos;
    v19 = v32;
    if ( v32 )
    {
      (**v32)(v32, 1i64);
      v19 = 0i64;
    }
  }
  else
  {
LABEL_59:
    v19 = v32;
  }
  v20 = merge_vars_p.i_array_p;
  if ( (this->i_flags.i_flagset & 1) != 0 )
  {
    if ( args->i_result )
    {
      i_common_class_p = class_union.i_common_class_p;
    }
    else
    {
      if ( !v17 )
      {
        SSTypeContext::merge(&this->i_context, &merge_vars_p);
        SSClassUnion::merge_class(&class_union, SSBrain::c_none_class_p);
      }
      if ( class_union.i_union.i_count > 1 )
      {
        v22 = (SSClassUnaryBase *)SSClassUnion::get_or_create(&class_union);
        i_common_class_p = class_union.i_common_class_p;
      }
      else
      {
        i_common_class_p = class_union.i_common_class_p;
        v22 = class_union.i_common_class_p;
      }
      args->i_type_p = v22;
      SSTypeContext::change_variable_types(&this->i_context, &merge_vars_p);
    }
    v23 = v20;
    v24 = &v20[merge_vars_p.i_count];
    merge_vars_p.i_count = 0;
    if ( v20 < v24 )
    {
      do
      {
        v25 = *v23;
        if ( *v23 )
        {
          i_obj_p = v25->i_type_p.i_obj_p;
          if ( i_obj_p )
            (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
          AMemory::c_free_func(v25);
        }
        ++v23;
      }
      while ( v23 < v24 );
    }
  }
  else
  {
    i_common_class_p = class_union.i_common_class_p;
  }
  args->i_end_pos = v31;
  AMemory::c_free_func(sorted.i_array_p);
  AMemory::c_free_func(v20);
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
  if ( i_common_class_p )
    i_common_class_p->vfptr->dereference_delay(i_common_class_p);
  v27 = class_union.i_union.i_array_p;
  if ( class_union.i_union.i_count )
  {
    v28 = (__int64 *)class_union.i_union.i_array_p;
    v29 = &class_union.i_union.i_array_p[class_union.i_union.i_count];
    if ( class_union.i_union.i_array_p < v29 )
    {
      do
         SSClassDescBase::`vcall{24,{flat}}(*v28++);
      while ( v28 < (__int64 *)v29 );
    }
  }
  AMemory::c_free_func(v27);
  return (SSConditional *)v19;
}

// File Line: 3022
// RVA: 0x129AC0
ASymbol *__fastcall SSParser::parse_data_member(SSParser *this, SSParser::Args *args, SSExpressionBase *owner_p)
{
  ASymbol *v6; // rbx
  SSParser::eResult v7; // eax
  SSClassDescBase *i_type_p; // rsi
  __int64 v9; // rax
  ASymbol *v10; // rcx
  ASymbol *v11; // rcx
  unsigned int end_pos_p; // [rsp+20h] [rbp-38h] BYREF
  __int64 v14; // [rsp+28h] [rbp-30h]
  ASymbol *v15; // [rsp+30h] [rbp-28h]
  ASymbol name_p; // [rsp+68h] [rbp+10h] BYREF
  int v17; // [rsp+78h] [rbp+20h] BYREF

  v14 = -2i64;
  v6 = 0i64;
  name_p.i_uid = -1;
  end_pos_p = args->i_start_pos;
  v7 = SSParser::parse_name_instance(this, end_pos_p, &end_pos_p, &name_p);
  args->i_result = v7;
  if ( v7 == Result_ok )
  {
    v17 = 2;
    if ( (this->i_flags.i_flagset & 1) != 0 )
    {
      i_type_p = args->i_type_p;
      v9 = (__int64)i_type_p->vfptr->get_data_type(i_type_p, &name_p, (eSSScope *)&v17);
      if ( v9 )
      {
        args->i_result = Result_ok;
        args->i_type_p = (SSClassDescBase *)(*(__int64 (__fastcall **)(__int64, SSClassDescBase *))(*(_QWORD *)v9 + 32i64))(
                                              v9,
                                              i_type_p);
      }
      else
      {
        args->i_result = Result_err_context_non_ident_member;
      }
    }
    if ( (args->i_flags & 1) != 0 && args->i_result == Result_ok )
    {
      if ( v17 == 2 )
      {
        v10 = (ASymbol *)AMemory::c_malloc_func(0x18ui64, "SSIdentifierMember");
        v15 = v10;
        if ( v10 )
        {
          *(_QWORD *)&v10->i_uid = &SSExpressionBase::`vftable;
          *(_QWORD *)&v10->i_uid = &SSIdentifier::`vftable;
          v10[2].i_uid = name_p.i_uid;
          *(_QWORD *)&v10->i_uid = &SSIdentifierMember::`vftable;
          *(_QWORD *)&v10[4].i_uid = owner_p;
          v6 = v10;
        }
      }
      else
      {
        v11 = (ASymbol *)AMemory::c_malloc_func(0x18ui64, "SSIdentifierClassMember");
        v15 = v11;
        if ( v11 )
        {
          *(_QWORD *)&v11->i_uid = &SSExpressionBase::`vftable;
          *(_QWORD *)&v11->i_uid = &SSIdentifier::`vftable;
          v11[2].i_uid = name_p.i_uid;
          *(_QWORD *)&v11->i_uid = &SSIdentifierMember::`vftable;
          *(_QWORD *)&v11[4].i_uid = owner_p;
          *(_QWORD *)&v11->i_uid = &SSIdentifierClassMember::`vftable;
          v6 = v11;
        }
      }
    }
  }
  args->i_end_pos = end_pos_p;
  return v6;
}

// File Line: 3269
// RVA: 0x129D10
SSLiteralList *__fastcall SSParser::parse_expression(
        SSParser *this,
        SSParser::Args *args,
        unsigned __int64 desired_exec_time)
{
  AStringRef *i_str_ref_p; // r10
  unsigned int i_length; // r9d
  __int64 i_start_pos; // r13
  SSLiteralList *result; // rax
  unsigned int i_end_pos; // esi
  char *i_cstr_p; // r10
  unsigned __int8 v11; // r11
  __int64 v12; // rdx
  SSLiteralList *v13; // rdi
  ASymbol *p_p_i_ctor_p; // r9
  SSParser::eResult v15; // eax
  AString *v16; // r9
  SSParser::eResult v17; // eax
  AStringRef *v18; // rsi
  AObjReusePool<AStringRef> *pool; // r8
  AObjBlock<AStringRef> *i_block_p; // rax
  unsigned __int64 i_objects_a; // rdx
  SSParser::eResult v23; // eax
  char v24; // r14
  SSCode *v25; // rax
  unsigned __int64 v26; // rcx
  int i_result; // ecx
  SSExpressionBase *v28; // rax
  unsigned int v29; // edx
  SSParser::eResult v30; // ecx
  SSParser::eResult v31; // eax
  AStringRef *elem[2]; // [rsp+30h] [rbp-38h] BYREF
  SSParser::Args argsa; // [rsp+40h] [rbp-28h] BYREF
  SSLiteralList *ch_p; // [rsp+B0h] [rbp+48h] BYREF
  unsigned int end_pos_p; // [rsp+B8h] [rbp+50h] BYREF
  eSSInvokeTime desired_exec_timea; // [rsp+C0h] [rbp+58h]
  SSMethodCall **p_i_ctor_p; // [rsp+C8h] [rbp+60h] BYREF

  desired_exec_timea = (int)desired_exec_time;
  elem[1] = (AStringRef *)-2i64;
  i_str_ref_p = this->i_str_ref_p;
  i_length = this->i_str_ref_p->i_length;
  i_start_pos = args->i_start_pos;
  if ( (unsigned int)i_start_pos < i_length )
  {
    i_end_pos = args->i_start_pos;
    end_pos_p = args->i_start_pos;
    i_cstr_p = i_str_ref_p->i_cstr_p;
    v11 = i_cstr_p[i_start_pos];
    v12 = (unsigned int)(i_start_pos + 1);
    if ( (unsigned int)v12 >= i_length )
      LOBYTE(desired_exec_time) = 0;
    else
      desired_exec_time = (unsigned __int8)i_cstr_p[v12];
    v13 = 0i64;
    switch ( v11 )
    {
      case !:
      case _:
        args->i_result = Result__implicit_this;
        goto LABEL_61;
      case ":
        elem[0] = AStringRef::get_empty();
        ++elem[0]->i_ref_count;
        v16 = (AString *)elem;
        if ( (args->i_flags & 1) == 0 )
          v16 = 0i64;
        v17 = SSParser::parse_literal_string(this, i_start_pos, &end_pos_p, v16);
        args->i_result = v17;
        if ( v17 == Result_ok )
        {
          args->i_type_p = SSBrain::c_string_class_p;
          if ( (args->i_flags & 1) != 0 )
          {
            v13 = (SSLiteralList *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
            ch_p = v13;
            if ( v13 )
            {
              v13->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
              v13->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
              v13->i_item_exprs.i_count = 4;
              p_i_ctor_p = &v13->i_ctor_p;
              if ( v13 != (SSLiteralList *)-8i64 )
              {
                v13->i_ctor_p = (SSMethodCall *)elem[0];
                ++elem[0]->i_ref_count;
              }
            }
            else
            {
              v13 = 0i64;
            }
          }
        }
        v18 = elem[0];
        if ( elem[0]->i_ref_count-- != 1 )
          goto LABEL_16;
        if ( v18->i_deallocate )
          AMemory::c_free_func(v18->i_cstr_p);
        pool = AStringRef::get_pool();
        i_block_p = pool->i_block_p;
        i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
        if ( (unsigned __int64)v18 < i_objects_a || (unsigned __int64)v18 >= i_objects_a + 24i64 * i_block_p->i_size )
        {
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&pool->i_exp_pool, v18);
          i_end_pos = end_pos_p;
        }
        else
        {
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&pool->i_pool, v18);
          i_end_pos = end_pos_p;
        }
        goto LABEL_61;
      case &:
      case *:
      case +:
      case /:
      case ::
      case <:
      case =:
      case >:
      case ^:
      case |:
      case ~:
        goto $LN18_1;
      case \:
        LODWORD(p_i_ctor_p) = -1;
        p_p_i_ctor_p = (ASymbol *)&p_i_ctor_p;
        if ( (args->i_flags & 1) == 0 )
          p_p_i_ctor_p = 0i64;
        v15 = SSParser::parse_literal_symbol(this, i_start_pos, &end_pos_p, p_p_i_ctor_p);
        args->i_result = v15;
        if ( v15 == Result_ok )
        {
          args->i_type_p = SSBrain::c_symbol_class_p;
          if ( (args->i_flags & 1) != 0 )
          {
            v13 = (SSLiteralList *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
            ch_p = v13;
            if ( v13 )
            {
              v13->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
              v13->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
              v13->i_item_exprs.i_count = 5;
              elem[0] = (AStringRef *)&v13->i_ctor_p;
              if ( v13 != (SSLiteralList *)-8i64 )
                LODWORD(v13->i_ctor_p) = (_DWORD)p_i_ctor_p;
            }
            else
            {
              v13 = 0i64;
            }
          }
        }
LABEL_16:
        i_end_pos = end_pos_p;
        goto LABEL_61;
      case (:
        goto $LN27_1;
      case -:
        if ( (_BYTE)desired_exec_time == 62 )
          goto $LN19_2;
        if ( AString::c_is_digit[(unsigned __int8)desired_exec_time] )
          goto LABEL_55;
$LN18_1:
        args->i_result = Result_err_unexpected_implicit_this;
        goto LABEL_61;
      case ?:
$LN19_2:
        args->i_result = Result_err_unexpected_deprecated;
        i_end_pos = i_start_pos + 1;
        goto LABEL_61;
      case @:
        if ( (unsigned __int8)desired_exec_time <= 0x3Fu
          && (v26 = 0xA000008000000000ui64, _bittest64((const __int64 *)&v26, desired_exec_time)) )
        {
          v25 = (SSCode *)SSParser::parse_object_id_tail(this, args, 0i64);
        }
        else
        {
$LN27_1:
          v25 = (SSCode *)SSParser::parse_closure(this, args);
        }
        goto LABEL_60;
      case [:
        v25 = SSParser::parse_code_block_optimized(this, args, SSInvokeTime_any, ResultDesired_true);
        goto LABEL_60;
      case `:
        v23 = Result_err_unexpected_eof;
        if ( i_length - (unsigned int)i_start_pos < 2 )
          goto LABEL_38;
        v23 = Result_err_expected_literal_char;
        if ( i_cstr_p[i_start_pos] != 96 )
          goto LABEL_38;
        end_pos_p = i_start_pos + 1;
        v24 = i_cstr_p[v12];
        LOBYTE(ch_p) = v24;
        if ( v24 == 92 )
        {
          v23 = SSParser::parse_literal_char_esc_seq(this, v12, &end_pos_p, (char *)&ch_p);
          i_end_pos = end_pos_p;
LABEL_38:
          v24 = (char)ch_p;
        }
        else
        {
          v23 = Result_ok;
          i_end_pos = i_start_pos + 2;
        }
        args->i_result = v23;
        if ( v23 == Result_ok )
        {
          args->i_type_p = SSBrain::c_char_class_p;
          if ( (args->i_flags & 1) != 0 )
          {
            v13 = (SSLiteralList *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
            ch_p = v13;
            if ( v13 )
            {
              v13->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
              v13->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
              v13->i_ctor_p = (SSMethodCall *)v24;
              v13->i_item_exprs.i_count = 1;
            }
            else
            {
              v13 = 0i64;
            }
          }
        }
        goto LABEL_61;
      case {:
        v13 = SSParser::parse_literal_list(this, args, 0i64, 0, 0i64);
        i_end_pos = args->i_end_pos;
        goto LABEL_61;
      default:
LABEL_55:
        if ( v11 == 45 || AString::c_is_digit[v11] )
        {
          v25 = (SSCode *)SSParser::parse_literal_number(this, args);
        }
        else
        {
          args->i_result = Result_err_unexpected_char;
          if ( !AString::c_char_match_table[0][v11] )
            goto LABEL_61;
          v25 = (SSCode *)SSParser::parse_expression_alpha(this, args);
        }
LABEL_60:
        i_end_pos = args->i_end_pos;
        v13 = (SSLiteralList *)v25;
LABEL_61:
        i_result = args->i_result;
        if ( i_result <= 2 )
        {
          argsa.i_flags = args->i_flags;
          argsa.i_result = i_result;
          argsa.i_end_pos = args->i_end_pos;
          argsa.i_type_p = args->i_type_p;
          argsa.i_start_pos = i_end_pos;
          if ( i_result == 2 )
            argsa.i_type_p = this->i_context.i_obj_scope_p;
          v28 = SSParser::parse_expression_string(this, &argsa, v13);
          v29 = argsa.i_end_pos;
          if ( i_end_pos == argsa.i_end_pos )
          {
            v31 = Result_ok;
            if ( args->i_result == Result__implicit_this )
              v31 = Result_err_expected_expression;
            args->i_result = v31;
          }
          else
          {
            v30 = argsa.i_result;
            if ( argsa.i_result )
            {
              if ( v13 )
              {
                v13->vfptr->__vecDelDtor(v13, 1u);
                v29 = argsa.i_end_pos;
                v30 = argsa.i_result;
              }
              v13 = 0i64;
            }
            else
            {
              v13 = (SSLiteralList *)v28;
            }
            args->i_start_pos = argsa.i_start_pos;
            args->i_flags = argsa.i_flags;
            args->i_result = v30;
            args->i_end_pos = v29;
            args->i_type_p = argsa.i_type_p;
            i_end_pos = v29;
          }
          args->i_end_pos = i_end_pos;
          if ( v13 )
          {
            if ( !SSParser::ensure_exec_time(this, v13, args, desired_exec_timea) )
            {
              args->i_start_pos = i_start_pos;
              args->i_end_pos = i_end_pos;
              v13->vfptr->__vecDelDtor(v13, 1u);
              v13 = 0i64;
            }
          }
          result = v13;
        }
        else
        {
          args->i_end_pos = i_end_pos;
          result = 0i64;
        }
        break;
    }
  }
  else
  {
    args->i_result = Result_err_unexpected_eof;
    args->i_end_pos = i_start_pos;
    return 0i64;
  }
  return result;
}

// File Line: 3587
// RVA: 0x12A290
SSObjectId *__fastcall SSParser::parse_expression_alpha(SSParser *this, SSParser::Args *args)
{
  __int64 i_start_pos; // r15
  unsigned int i_uid; // ebx
  SSObjectId *v6; // rsi
  AStringRef *i_str_ref_p; // r9
  char *i_cstr_p; // r8
  char v9; // r13
  SSClass *v10; // rdi
  SSParser::eResult v11; // r10d
  SSClass **i_array_p; // rdx
  SSClass **v13; // r9
  SSClass **v14; // rcx
  unsigned int v15; // r8d
  SSClassDescBase *v16; // rbx
  SSObjectId *v17; // rax
  __int64 v18; // rax
  unsigned int i_length; // edx
  unsigned __int64 v20; // rcx
  unsigned __int64 v21; // rax
  SSClass *v22; // rdi
  SSParser::eResult v23; // r10d
  ASymbol *v24; // rax
  SSClass **v25; // rdx
  SSClass **v26; // r9
  SSClass **v27; // rcx
  unsigned int v28; // r8d
  unsigned int start_pos; // edi
  unsigned int v31; // eax
  ASymbol **v32; // rdx
  ASymbol **v33; // r9
  bool i; // cc
  __int64 v35; // rdx
  int v36; // kr00_4
  unsigned __int64 v37; // rdx
  SSObjectId *v38; // rax
  SSClass *i_obj_scope_p; // rax
  SSObjectId *v40; // rax
  SSObjectId *v41; // rax
  SSObjectId *v42; // rax
  SSObjectId *v43; // rax
  eSSMember i_member_type; // ecx
  SSClass *v45; // rax
  SSObjectId *v46; // rax
  int variable; // ecx
  int v48; // ecx
  int v49; // ecx
  SSObjectId *v50; // rax
  SSObjectId *v51; // rax
  SSObjectId *v52; // rax
  unsigned int v53; // [rsp+90h] [rbp+48h] BYREF
  unsigned int find_pos_p; // [rsp+98h] [rbp+50h] BYREF
  SSObjectId *op_name; // [rsp+A0h] [rbp+58h] BYREF
  SSObjectId *result; // [rsp+A8h] [rbp+60h] BYREF

  i_start_pos = args->i_start_pos;
  v53 = i_start_pos;
  find_pos_p = i_start_pos + 1;
  find_pos_p = this->i_str_ref_p->i_length;
  i_uid = -1;
  AString::find(this, ACharMatch_not_identifier, 1u, &find_pos_p, i_start_pos + 1, 0xFFFFFFFF);
  args->i_result = Result__implicit_this;
  v6 = 0i64;
  i_str_ref_p = this->i_str_ref_p;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  v9 = i_cstr_p[find_pos_p];
  if ( AString::c_is_uppercase[(unsigned __int8)i_cstr_p[i_start_pos]] )
  {
    if ( v9 == 33 )
      return (SSObjectId *)SSParser::parse_instantiate_or_list(this, args);
    if ( v9 != 40 )
    {
      if ( v9 != 64 )
      {
        if ( v9 != 123 )
        {
          v10 = 0i64;
          LODWORD(i_start_pos) = v53;
          v11 = Result_err_unexpected_eof;
          LODWORD(op_name) = v53;
          if ( i_str_ref_p->i_length > v53 )
          {
            v11 = Result_err_expected_class;
            if ( AString::c_is_uppercase[(unsigned __int8)i_cstr_p[v53]] )
            {
              LODWORD(op_name) = v53 + 1;
              LODWORD(op_name) = i_str_ref_p->i_length;
              AString::find(this, ACharMatch_not_identifier, 1u, (unsigned int *)&op_name, v53 + 1, 0xFFFFFFFF);
              i_uid = SSParser::as_symbol(this, (ASymbol *)&result, i_start_pos, (unsigned int)op_name)->i_uid;
              v11 = Result_ok;
              if ( i_uid == ASymbol_Class.i_uid )
                v11 = Result_err_unexpected_class_class;
              LODWORD(i_start_pos) = (_DWORD)op_name;
            }
          }
          v53 = i_start_pos;
          if ( v11 == Result_ok )
          {
            v11 = Result_err_context_non_class;
            if ( SSBrain::c_classes.i_count )
            {
              i_array_p = SSBrain::c_classes.i_array_p;
              v13 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
              while ( 1 )
              {
                while ( 1 )
                {
                  v14 = &i_array_p[((char *)v13 - (char *)i_array_p) >> 4];
                  v15 = (*v14)->i_name.i_uid;
                  if ( i_uid >= v15 )
                    break;
                  if ( i_array_p == v14 )
                    goto LABEL_22;
                  v13 = v14 - 1;
                }
                if ( i_uid == v15 )
                  break;
                if ( v13 == v14 )
                  goto LABEL_22;
                i_array_p = v14 + 1;
              }
              if ( *v14 )
              {
                v11 = Result_ok;
                v10 = *v14;
              }
            }
          }
LABEL_22:
          args->i_result = v11;
          if ( !v10 )
            goto LABEL_118;
          v16 = v10->vfptr->get_metaclass(v10);
          args->i_type_p = v16;
          if ( (args->i_flags & 1) != 0 )
          {
            v17 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
            op_name = v17;
            if ( v17 )
            {
              v17->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
              v17->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
              *(_QWORD *)&v17->i_name.i_uid = v16;
              LODWORD(v17->i_class_p) = 6;
              v6 = v17;
            }
          }
          goto LABEL_117;
        }
        return (SSObjectId *)SSParser::parse_instantiate_or_list(this, args);
      }
      v18 = find_pos_p + 1;
      i_length = i_str_ref_p->i_length;
      if ( (unsigned int)v18 < i_length )
      {
        v20 = (unsigned __int8)i_cstr_p[v18];
        if ( (unsigned __int8)v20 <= 0x3Fu )
        {
          v21 = 0xA000008000000000ui64;
          if ( _bittest64((const __int64 *)&v21, v20) )
          {
            v22 = 0i64;
            LODWORD(i_start_pos) = v53;
            v23 = Result_err_unexpected_eof;
            LODWORD(op_name) = v53;
            if ( i_length > v53 )
            {
              v23 = Result_err_expected_class;
              if ( AString::c_is_uppercase[(unsigned __int8)i_cstr_p[v53]] )
              {
                LODWORD(op_name) = i_length;
                AString::find(this, ACharMatch_not_identifier, 1u, (unsigned int *)&op_name, v53 + 1, 0xFFFFFFFF);
                v24 = SSParser::as_symbol(this, (ASymbol *)&result, i_start_pos, (unsigned int)op_name);
                i_uid = v24->i_uid;
                v23 = Result_ok;
                if ( v24->i_uid == ASymbol_Class.i_uid )
                  v23 = Result_err_unexpected_class_class;
                LODWORD(i_start_pos) = (_DWORD)op_name;
              }
            }
            v53 = i_start_pos;
            if ( v23 == Result_ok )
            {
              v23 = Result_err_context_non_class;
              if ( SSBrain::c_classes.i_count )
              {
                v25 = SSBrain::c_classes.i_array_p;
                v26 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
                while ( 1 )
                {
                  while ( 1 )
                  {
                    v27 = &v25[((char *)v26 - (char *)v25) >> 4];
                    v28 = (*v27)->i_name.i_uid;
                    if ( i_uid >= v28 )
                      break;
                    if ( v25 == v27 )
                      goto LABEL_46;
                    v26 = v27 - 1;
                  }
                  if ( i_uid == v28 )
                    break;
                  if ( v26 == v27 )
                    goto LABEL_46;
                  v25 = v27 + 1;
                }
                if ( *v27 )
                {
                  v23 = Result_ok;
                  v22 = *v27;
                }
              }
            }
LABEL_46:
            args->i_result = v23;
            if ( v22 )
            {
              args->i_start_pos = i_start_pos;
              v6 = SSParser::parse_object_id_tail(this, args, v22);
              LODWORD(i_start_pos) = args->i_end_pos;
            }
            goto LABEL_118;
          }
        }
      }
    }
LABEL_117:
    LODWORD(i_start_pos) = v53;
    goto LABEL_118;
  }
  LODWORD(op_name) = -1;
  if ( (this->i_flags.i_flagset & 1) == 0 && v9 == 40 )
    goto LABEL_117;
  start_pos = v53;
  v53 = i_str_ref_p->i_length;
  AString::find(this, ACharMatch_not_identifier, 1u, &v53, start_pos, 0xFFFFFFFF);
  v31 = SSParser::as_symbol(this, (ASymbol *)&result, start_pos, v53)->i_uid;
  LODWORD(op_name) = v31;
  if ( v31 == -543273101 && v9 != 40 )
  {
    args->i_start_pos = v53;
    v6 = (SSObjectId *)SSParser::parse_prefix_operator_expr(this, (ASymbol *)&op_name, args);
    LODWORD(i_start_pos) = args->i_end_pos;
    goto LABEL_118;
  }
  if ( SSParser::c_reserved_word_syms.i_count )
  {
    v32 = SSParser::c_reserved_word_syms.i_array_p;
    v33 = &SSParser::c_reserved_word_syms.i_array_p[SSParser::c_reserved_word_syms.i_count - 1];
    for ( i = SSParser::c_reserved_word_syms.i_array_p <= v33; i; i = v32 <= v33 )
    {
      if ( v31 == (*v32)->i_uid )
      {
        v35 = v32 - SSParser::c_reserved_word_syms.i_array_p;
        args->i_result = Result_ok;
        v36 = v35;
        v37 = 0x140000000ui64;
        switch ( v36 )
        {
          case 0:
            args->i_start_pos = find_pos_p;
            v6 = (SSObjectId *)SSParser::parse_concurrent_branch_block(this, (unsigned __int64)args);
            LODWORD(i_start_pos) = args->i_end_pos;
            break;
          case 1:
            args->i_start_pos = v53;
            v6 = (SSObjectId *)SSParser::parse_case_tail(this, args);
            LODWORD(i_start_pos) = args->i_end_pos;
            break;
          case 2:
            args->i_start_pos = find_pos_p;
            v6 = (SSObjectId *)SSParser::parse_divert_block(this, (unsigned __int64)args);
            LODWORD(i_start_pos) = args->i_end_pos;
            break;
          case 3:
            args->i_result = Result_err_unexpected_else_statement;
            goto LABEL_117;
          case 4:
            LODWORD(i_start_pos) = v53 - 4;
            args->i_result = Result_err_unexpected_exit;
            break;
          case 5:
            if ( (args->i_flags & 1) != 0 )
            {
              v40 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
              result = v40;
              if ( v40 )
              {
                v40->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
                v40->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
                *(_QWORD *)&v40->i_name.i_uid = 0i64;
                LODWORD(v40->i_class_p) = 0;
                v6 = v40;
              }
            }
            i_obj_scope_p = SSBrain::c_boolean_class_p;
            goto LABEL_116;
          case 6:
            args->i_start_pos = v53;
            v6 = (SSObjectId *)SSParser::parse_conditional_tail(this, args);
            LODWORD(i_start_pos) = args->i_end_pos;
            break;
          case 7:
            args->i_start_pos = v53;
            v6 = (SSObjectId *)SSParser::parse_loop_tail(this, args);
            LODWORD(i_start_pos) = args->i_end_pos;
            break;
          case 9:
            args->i_start_pos = find_pos_p;
            v6 = (SSObjectId *)SSParser::parse_concurrent_race_block(this, (unsigned __int64)args);
            LODWORD(i_start_pos) = args->i_end_pos;
            break;
          case 10:
            args->i_start_pos = find_pos_p;
            v6 = (SSObjectId *)SSParser::parse_concurrent_sync_block(this, (unsigned __int64)args);
            LODWORD(i_start_pos) = args->i_end_pos;
            break;
          case 11:
            if ( (args->i_flags & 1) != 0 )
            {
              v41 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
              result = v41;
              if ( v41 )
              {
                v41->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
                v41->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
                *(_QWORD *)&v41->i_name.i_uid = 0i64;
                LODWORD(v41->i_class_p) = 8;
                v6 = v41;
              }
            }
            i_obj_scope_p = (SSClass *)this->i_context.i_obj_scope_p;
            goto LABEL_116;
          case 12:
            if ( (args->i_flags & 1) != 0 )
            {
              v42 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
              result = v42;
              if ( v42 )
              {
                v42->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
                v42->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
                *(_QWORD *)&v42->i_name.i_uid = 0i64;
                LODWORD(v42->i_class_p) = 9;
                v6 = v42;
              }
            }
            i_obj_scope_p = (SSClass *)((__int64 (__fastcall *)(SSClassUnaryBase *, unsigned __int64))this->i_context.i_obj_scope_p->vfptr->get_metaclass)(
                                         this->i_context.i_obj_scope_p,
                                         v37);
            goto LABEL_116;
          case 13:
            if ( (args->i_flags & 1) != 0 )
            {
              v43 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
              result = v43;
              if ( v43 )
              {
                v43->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
                v43->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
                *(_QWORD *)&v43->i_name.i_uid = 0i64;
                LODWORD(v43->i_class_p) = 10;
                v6 = v43;
              }
            }
            i_member_type = this->i_member_type;
            LODWORD(i_start_pos) = v53;
            if ( i_member_type )
            {
              v45 = SSBrain::c_invoked_coroutine_class_p;
              if ( i_member_type != SSMember_coroutine )
                v45 = SSBrain::c_none_class_p;
              args->i_type_p = v45;
            }
            else
            {
              args->i_type_p = SSBrain::c_invoked_method_class_p;
            }
            break;
          case 14:
            if ( (args->i_flags & 1) != 0 )
            {
              v38 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
              result = v38;
              if ( v38 )
              {
                v38->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
                v38->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
                *(_QWORD *)&v38->i_name.i_uid = 1i64;
                LODWORD(v38->i_class_p) = 0;
                v6 = v38;
              }
            }
            i_obj_scope_p = SSBrain::c_boolean_class_p;
            goto LABEL_116;
          default:
            if ( (args->i_flags & 1) != 0 )
            {
              v46 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
              result = v46;
              if ( v46 )
              {
                v46->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
                v46->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable;
                *(_QWORD *)&v46->i_name.i_uid = 0i64;
                LODWORD(v46->i_class_p) = 7;
                v6 = v46;
              }
            }
            i_obj_scope_p = SSBrain::c_none_class_p;
            goto LABEL_116;
        }
        goto LABEL_118;
      }
      ++v32;
    }
  }
  if ( (this->i_flags.i_flagset & 1) == 0 )
  {
    variable = 3;
LABEL_102:
    args->i_result = Result_ok;
    if ( (args->i_flags & 1) != 0 )
    {
      v48 = variable - 1;
      if ( v48 )
      {
        v49 = v48 - 1;
        if ( v49 )
        {
          if ( v49 == 1 )
          {
            v50 = (SSObjectId *)AMemory::c_malloc_func(0x10ui64, "SSIdentifier");
            result = v50;
            if ( v50 )
            {
              v50->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
              v50->vfptr = (SSExpressionBaseVtbl *)&SSIdentifier::`vftable;
              v50->i_name.i_uid = (unsigned int)op_name;
              v6 = v50;
            }
          }
        }
        else
        {
          v51 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSIdentifierMember");
          result = v51;
          if ( v51 )
          {
            v51->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
            v51->vfptr = (SSExpressionBaseVtbl *)&SSIdentifier::`vftable;
            v51->i_name.i_uid = (unsigned int)op_name;
            v51->vfptr = (SSExpressionBaseVtbl *)&SSIdentifierMember::`vftable;
            v51->i_class_p = 0i64;
            v6 = v51;
          }
        }
      }
      else
      {
        v52 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSIdentifierClassMember");
        result = v52;
        if ( v52 )
        {
          v52->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
          v52->vfptr = (SSExpressionBaseVtbl *)&SSIdentifier::`vftable;
          v52->i_name.i_uid = (unsigned int)op_name;
          v52->vfptr = (SSExpressionBaseVtbl *)&SSIdentifierMember::`vftable;
          v52->i_class_p = 0i64;
          v52->vfptr = (SSExpressionBaseVtbl *)&SSIdentifierClassMember::`vftable;
          v6 = v52;
        }
      }
      if ( (this->i_flags.i_flagset & 1) != 0 )
      {
        i_obj_scope_p = (SSClass *)SSTypeContext::get_variable_type(&this->i_context, (ASymbol *)&op_name, 0);
LABEL_116:
        args->i_type_p = i_obj_scope_p;
      }
    }
    goto LABEL_117;
  }
  variable = SSTypeContext::find_variable(&this->i_context, (ASymbol *)&op_name);
  if ( variable )
    goto LABEL_102;
  if ( v9 != 40 )
  {
    args->i_result = Result_err_context_non_identifier;
    goto LABEL_117;
  }
LABEL_118:
  args->i_end_pos = i_start_pos;
  return v6;
}

// File Line: 4024
// RVA: 0x12B060
SSLiteralList *__fastcall SSParser::parse_instantiate_or_list(SSParser *this, SSParser::Args *args)
{
  SSExpressionBase *v4; // rbx
  SSParser::eResult v5; // eax
  SSTypedClass *v6; // r14
  SSMethodCall *ctor_p; // rbp
  SSLiteralList *result; // rax
  SSExpressionBase *v9; // rdi
  __int64 v10; // rax
  _BOOL8 v11; // [rsp+78h] [rbp+10h] BYREF
  SSTypedClass *list_class_p; // [rsp+80h] [rbp+18h] BYREF

  v4 = 0i64;
  list_class_p = 0i64;
  LOBYTE(v11) = 0;
  v5 = (unsigned int)SSParser::parse_class_instance(
                       this,
                       args->i_start_pos,
                       &args->i_end_pos,
                       &list_class_p,
                       (bool *)&v11);
  args->i_result = v5;
  if ( v5 )
    return 0i64;
  v6 = list_class_p;
  args->i_type_p = list_class_p;
  args->i_start_pos = args->i_end_pos;
  ctor_p = SSParser::parse_invoke_ctor(this, args);
  if ( args->i_result )
    return 0i64;
  if ( this->i_str_ref_p->i_cstr_p[args->i_end_pos] == 123 && v6->vfptr->get_class_type(v6) )
  {
    args->i_start_pos = args->i_end_pos;
    return SSParser::parse_literal_list(this, args, v6, v11, ctor_p);
  }
  else
  {
    if ( ctor_p )
    {
      v9 = (SSExpressionBase *)AMemory::c_malloc_func(0x18ui64, "SSInstantiate");
      v11 = (_BOOL8)v9;
      if ( v9 )
      {
        v10 = (__int64)v6->vfptr->get_key_class(v6);
        v9->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
        v9->vfptr = (SSExpressionBaseVtbl *)&SSInstantiate::`vftable;
        v9[1].vfptr = (SSExpressionBaseVtbl *)v10;
        v9[2].vfptr = (SSExpressionBaseVtbl *)ctor_p;
        v4 = v9;
      }
    }
    result = (SSLiteralList *)v4;
    if ( (this->i_flags.i_flagset & 1) != 0 )
      args->i_type_p = v6;
  }
  return result;
}

// File Line: 4101
// RVA: 0x12ABA0
SSIdentifier *__fastcall SSParser::parse_expression_string(
        SSParser *this,
        SSParser::Args *args,
        SSIdentifier *receiver_p)
{
  bool v5; // r15
  unsigned int i_start_pos; // esi
  unsigned int v7; // r14d
  SSParser::eResult v8; // eax
  unsigned int i_end_pos; // ebx
  bool v11; // bp
  AStringRef *i_str_ref_p; // rcx
  unsigned int i_length; // eax
  __int64 i_cstr_p; // rcx
  SSIdentifier *v15; // r8
  SSIdentifier *v16; // rsi
  unsigned int v17; // r11d
  SSMethodCall *v18; // r10
  __int64 v19; // r9
  unsigned __int8 v20; // dl
  SSParser::eResult v21; // eax
  unsigned int v22; // ebx
  __int64 v23; // rbp
  unsigned __int8 v24; // cl
  SSInvokeCascade *v25; // rax
  bool v26; // dl
  SSMethodCall *v27; // rax
  SSIdentifier *v28; // r14
  SSIdentifier *v29; // rax
  char v30; // bp
  SSParser::eResult v31; // eax
  unsigned int v32; // [rsp+30h] [rbp-78h]
  SSMethodCall *v33; // [rsp+38h] [rbp-70h]
  SSInvokeCascade *v34; // [rsp+40h] [rbp-68h]
  unsigned int v35; // [rsp+48h] [rbp-60h]
  int v36; // [rsp+4Ch] [rbp-5Ch] BYREF
  unsigned int find_pos_p; // [rsp+50h] [rbp-58h] BYREF
  unsigned int v38; // [rsp+54h] [rbp-54h]
  __int64 v39; // [rsp+58h] [rbp-50h]
  __int64 v40; // [rsp+60h] [rbp-48h]
  char v41; // [rsp+B8h] [rbp+10h]
  unsigned int end_pos_p; // [rsp+C8h] [rbp+20h] BYREF

  v40 = -2i64;
  v5 = args->i_result == Result__implicit_this;
  i_start_pos = args->i_start_pos;
  v35 = args->i_start_pos;
  v33 = 0i64;
  v7 = args->i_start_pos;
  v8 = SSParser::parse_ws_any(this, args->i_start_pos, &args->i_end_pos);
  args->i_result = v8;
  if ( v8 )
    return 0i64;
  i_end_pos = args->i_end_pos;
  v11 = i_start_pos != i_end_pos;
  end_pos_p = i_end_pos;
  v32 = i_end_pos;
  if ( v5 )
  {
    args->i_start_pos = i_end_pos;
    v33 = SSParser::parse_invoke_selector(this, args, 0);
    i_end_pos = args->i_end_pos;
    end_pos_p = i_end_pos;
  }
  v41 = 0;
  i_str_ref_p = this->i_str_ref_p;
  i_length = this->i_str_ref_p->i_length;
  v38 = i_length;
  i_cstr_p = (__int64)i_str_ref_p->i_cstr_p;
  v39 = i_cstr_p;
  v15 = 0i64;
  v34 = 0i64;
  v16 = receiver_p;
  while ( 1 )
  {
    if ( v5 )
    {
LABEL_41:
      v18 = v33;
    }
    else
    {
      v17 = i_end_pos;
      v32 = i_end_pos;
      v18 = 0i64;
      v33 = 0i64;
      v15 = 0i64;
      v34 = 0i64;
      v19 = i_end_pos + 1;
      v20 = (unsigned int)v19 >= i_length ? 0 : *(_BYTE *)(v19 + i_cstr_p);
      switch ( *(_BYTE *)(i_end_pos + i_cstr_p) )
      {
        case %:
          if ( v20 == 62 )
          {
            args->i_start_pos = i_end_pos;
            v25 = (SSInvokeCascade *)SSParser::parse_invoke_race(this, args, v16);
            goto LABEL_40;
          }
          if ( v20 == 93 || v20 == 41 || v20 == 125 || !byte_14236F7C0[v20] )
            goto LABEL_39;
          args->i_start_pos = i_end_pos;
          v25 = (SSInvokeCascade *)SSParser::parse_invoke_apply(this, args, v16);
          goto LABEL_40;
        case (:
          if ( !v11 )
          {
            args->i_start_pos = i_end_pos;
            v25 = (SSInvokeCascade *)SSParser::parse_invoke_operator(this, args, v16);
            goto LABEL_40;
          }
          args->i_result = Result_err_expected_invoke_selector;
          goto LABEL_43;
        case -:
          if ( v20 != 62 )
            goto LABEL_39;
          args->i_result = Result_err_unexpected_deprecated;
          ++i_end_pos;
          end_pos_p = v19;
          goto LABEL_43;
        case .:
          v21 = SSParser::parse_ws_any(this, v19, &end_pos_p);
          args->i_result = v21;
          if ( v21 )
          {
            i_end_pos = end_pos_p;
            v15 = 0i64;
            v18 = 0i64;
            break;
          }
          v22 = end_pos_p;
          v23 = v39;
          v24 = *(_BYTE *)(end_pos_p + v39);
          if ( v24 == 91 )
          {
            args->i_start_pos = end_pos_p;
            v25 = SSParser::parse_invoke_cascade(this, args, v16);
LABEL_40:
            i_end_pos = args->i_end_pos;
            v15 = (SSIdentifier *)v25;
            v34 = v25;
            end_pos_p = i_end_pos;
            goto LABEL_41;
          }
          v26 = 0;
          if ( AString::c_is_lowercase[v24] )
          {
            AString::find(this, ACharMatch_not_identifier, 1u, &find_pos_p, end_pos_p + 1, 0xFFFFFFFF);
            v26 = *(_BYTE *)(find_pos_p + v23) != 40;
          }
          args->i_start_pos = v22;
          if ( v26 )
          {
            v25 = (SSInvokeCascade *)SSParser::parse_data_member(this, args, v16);
            goto LABEL_40;
          }
          v27 = SSParser::parse_invoke_selector(this, args, 0);
LABEL_19:
          v18 = v27;
          v33 = v27;
          i_end_pos = args->i_end_pos;
          end_pos_p = i_end_pos;
          v15 = 0i64;
          break;
        case ::
          if ( v20 == 61 )
            goto LABEL_39;
          args->i_start_pos = i_end_pos;
          v25 = (SSInvokeCascade *)SSParser::parse_bind(this, args, v16);
          goto LABEL_40;
        case <:
          if ( v20 != 62 )
            goto LABEL_39;
          args->i_start_pos = i_end_pos;
          v25 = (SSInvokeCascade *)SSParser::parse_class_cast(this, args, v16);
          goto LABEL_40;
        case >:
          if ( v20 != 62 )
            goto LABEL_39;
          args->i_start_pos = i_end_pos;
          v25 = (SSInvokeCascade *)SSParser::parse_class_conversion(this, args, v16, v19);
          goto LABEL_40;
        default:
LABEL_39:
          args->i_start_pos = i_end_pos;
          v27 = SSParser::parse_operator(this, args);
          goto LABEL_19;
      }
    }
    v17 = v32;
LABEL_43:
    v5 = 0;
    if ( args->i_result )
      break;
    v28 = v16;
    if ( v15 )
    {
      v16 = v15;
    }
    else if ( v18 )
    {
      v29 = (SSIdentifier *)AMemory::c_malloc_func(0x18ui64, "SSInvocation");
      if ( v29 )
      {
        v29->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
        v29->vfptr = (SSExpressionBaseVtbl *)&SSInvocation::`vftable;
        *(_QWORD *)&v29->i_ident_name.i_uid = v16;
        v29[1].vfptr = (SSExpressionBaseVtbl *)v33;
        v16 = v29;
      }
      else
      {
        v16 = 0i64;
      }
    }
    v30 = 1;
    v41 = 1;
    if ( v28
      && !v28->vfptr->is_immediate(v28, (unsigned int *)&v36)
      && this->i_str_ref_p->i_cstr_p[args->i_end_pos] != 37 )
    {
      args->i_end_pos = v36 + 4;
      args->i_result = Result_err_context_immediate;
      i_end_pos = v32;
      args->i_start_pos = v35;
      goto LABEL_61;
    }
    if ( args->i_result )
      goto LABEL_62;
    v7 = i_end_pos;
    v31 = SSParser::parse_ws_any(this, i_end_pos, &end_pos_p);
    args->i_result = v31;
    i_end_pos = end_pos_p;
    v11 = end_pos_p != v7;
    if ( v31 )
    {
      v30 = 1;
      goto LABEL_61;
    }
    v15 = (SSIdentifier *)v34;
    i_cstr_p = v39;
    i_length = v38;
  }
  v30 = v41;
  if ( i_end_pos == v17 )
  {
    i_end_pos = v7;
    if ( v41 )
      args->i_result = Result_ok;
  }
LABEL_61:
  if ( args->i_result )
  {
LABEL_62:
    if ( v30 && v16 && v16 != receiver_p )
    {
      v16->vfptr->null_receiver(v16, receiver_p);
      v16->vfptr->__vecDelDtor(v16, 1u);
    }
    v16 = 0i64;
  }
  args->i_end_pos = i_end_pos;
  return v16;
}

// File Line: 4465
// RVA: 0x12E500
__int64 __fastcall SSParser::parse_named_specifier(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSParameters *params_p,
        unsigned int *arg_idx_p,
        SSParameters::eType param_type)
{
  unsigned int i_length; // ecx
  __int64 v11; // rax
  char *i_cstr_p; // rbp
  unsigned int v13; // r9d
  unsigned int v14; // eax
  char *i_array_p; // r11
  char *v16; // r10
  char *v17; // rdx
  __int64 v18; // rax
  bool v19; // zf
  unsigned int i_count; // eax
  char *v21; // r10
  ASymbol result; // [rsp+50h] [rbp+8h] BYREF
  unsigned int find_pos_p; // [rsp+58h] [rbp+10h] BYREF

  i_length = this->i_str_ref_p->i_length;
  find_pos_p = i_length;
  if ( end_pos_p )
    *end_pos_p = start_pos;
  if ( start_pos + 1 >= i_length )
    return 54i64;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  if ( byte_14236F2C0[(unsigned __int8)i_cstr_p[start_pos]] )
    return 54i64;
  AString::find(this, ACharMatch_not_identifier, 1u, &find_pos_p, start_pos + 1, 0xFFFFFFFF);
  v13 = find_pos_p;
  if ( i_cstr_p[find_pos_p] != 35 )
    return 54i64;
  if ( end_pos_p )
    *end_pos_p = find_pos_p + 1;
  if ( v13 - start_pos > 0xFF )
    return 95i64;
  if ( !params_p )
    return 0i64;
  SSParser::as_symbol(this, &result, start_pos, v13);
  if ( param_type )
  {
    i_count = params_p->i_return_params.i_count;
    if ( i_count )
    {
      i_array_p = (char *)params_p->i_return_params.i_array_p;
      v21 = &i_array_p[8 * i_count - 8];
      v17 = i_array_p;
      if ( i_array_p <= v21 )
      {
        while ( result.i_uid != **(_DWORD **)v17 )
        {
          v17 += 8;
          if ( v17 > v21 )
            goto LABEL_19;
        }
        goto LABEL_28;
      }
    }
  }
  else
  {
    v14 = params_p->i_params.i_count;
    if ( v14 )
    {
      i_array_p = (char *)params_p->i_params.i_array_p;
      v16 = &i_array_p[8 * v14 - 8];
      v17 = i_array_p;
      if ( i_array_p <= v16 )
      {
        while ( result.i_uid != *(_DWORD *)(*(_QWORD *)v17 + 8i64) )
        {
          v17 += 8;
          if ( v17 > v16 )
            goto LABEL_19;
        }
LABEL_28:
        if ( arg_idx_p )
          *arg_idx_p = (v17 - i_array_p) >> 3;
        v18 = *(_QWORD *)v17;
        goto LABEL_20;
      }
    }
  }
LABEL_19:
  v18 = 0i64;
LABEL_20:
  v19 = v18 == 0;
  v11 = 107i64;
  if ( !v19 )
    return 0i64;
  return v11;
}

// File Line: 4589
// RVA: 0x12B3A0
__int64 __fastcall SSParser::parse_invoke_args(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *args_p,
        APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *ret_args_p,
        SSClassUnaryBase *receiver_type_p,
        SSParameters *params_p)
{
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v7; // r15
  unsigned int i_end_pos; // ebx
  SSParser::eResult i_result; // edi
  char *i_cstr_p; // rcx
  unsigned int v11; // esi
  unsigned int v12; // r13d
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v13; // r12
  SSParser *v14; // r14
  unsigned __int64 v15; // r14
  __int64 v16; // rax
  SSParameters *v17; // r14
  SSParser *v18; // rbx
  SSParser::eResult v19; // eax
  SSClassDescBase *v20; // r15
  unsigned int v21; // r13d
  __int64 v22; // rcx
  __int64 v23; // rax
  __int64 v24; // rdi
  unsigned int v25; // r14d
  unsigned int v26; // r15d
  __int64 v27; // rbx
  __int64 v28; // rax
  __int64 v29; // rax
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v30; // rbx
  unsigned int v31; // eax
  unsigned int v32; // ecx
  SSClass *v33; // rcx
  SSLiteralList *v34; // r14
  bool v35; // al
  char v36; // r15
  char v37; // cl
  APCompactArrayBase<SSParameterBase> *v38; // r13
  unsigned int v39; // r12d
  SSParameterBase **v40; // r14
  char *v41; // r15
  SSParameterBase **v42; // r14
  char v44; // [rsp+30h] [rbp-71h]
  char v45; // [rsp+31h] [rbp-70h]
  char v46; // [rsp+32h] [rbp-6Fh]
  int elem_count; // [rsp+34h] [rbp-6Dh]
  unsigned int v48; // [rsp+38h] [rbp-69h]
  unsigned int v49; // [rsp+3Ch] [rbp-65h]
  unsigned int i_count; // [rsp+40h] [rbp-61h]
  unsigned int v51; // [rsp+44h] [rbp-5Dh]
  unsigned int i_length; // [rsp+48h] [rbp-59h]
  SSParameterBase **i_array_p; // [rsp+50h] [rbp-51h]
  SSClassDescBase *v54; // [rsp+58h] [rbp-49h]
  unsigned int v55[2]; // [rsp+60h] [rbp-41h] BYREF
  __int64 v56; // [rsp+68h] [rbp-39h]
  SSParser::Args args; // [rsp+70h] [rbp-31h] BYREF
  char *v58; // [rsp+88h] [rbp-19h]
  __int64 v59; // [rsp+90h] [rbp-11h]
  unsigned int end_pos_pa; // [rsp+F8h] [rbp+57h] BYREF
  void *mem_p; // [rsp+100h] [rbp+5Fh]
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v63; // [rsp+108h] [rbp+67h]

  v63 = args_p;
  mem_p = end_pos_p;
  v59 = -2i64;
  v7 = args_p;
  i_end_pos = start_pos;
  i_result = Result_err_unexpected_eof;
  i_length = this->i_str_ref_p->i_length;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  v58 = i_cstr_p;
  if ( i_length - start_pos < 2 )
    goto LABEL_132;
  i_result = Result_err_expected_invoke_args;
  if ( i_cstr_p[start_pos] != 40 )
    goto LABEL_132;
  i_end_pos = start_pos + 1;
  end_pos_pa = start_pos + 1;
  v56 = 0i64;
  i_array_p = 0i64;
  i_count = -1;
  v46 = 0;
  if ( params_p )
  {
    i_count = params_p->i_params.i_count;
    i_array_p = params_p->i_params.i_array_p;
    if ( args_p )
      APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)args_p);
  }
  i_result = Result_err_unexpected_eof;
  v11 = 0;
  v49 = 0;
  v51 = 0;
  v12 = 0;
  elem_count = 0;
  v48 = 0;
  v44 = 0;
  v45 = 0;
  args.i_start_pos = i_end_pos;
  args.i_flags = v7 != 0i64;
  *(_QWORD *)&args.i_result = 0i64;
  args.i_type_p = 0i64;
  v13 = 0i64;
  v14 = this;
  if ( receiver_type_p )
    v54 = receiver_type_p->vfptr->as_finalized_generic(receiver_type_p, this->i_context.i_obj_scope_p);
  else
    v54 = 0i64;
  if ( i_end_pos < i_length )
  {
    while ( 1 )
    {
      i_result = SSParser::parse_ws_any(v14, i_end_pos, &end_pos_pa);
      if ( i_result )
        goto LABEL_114;
      i_end_pos = end_pos_pa;
      v15 = (unsigned __int8)v58[end_pos_pa];
      if ( (unsigned __int8)v15 <= 0x3Bu )
      {
        v16 = 0x800120000000000i64;
        if ( _bittest64(&v16, v15) )
        {
          i_end_pos = ++end_pos_pa;
          if ( !v11 && (_BYTE)v15 != 44 )
            goto LABEL_25;
          if ( v45 )
          {
            i_result = Result_err_context_invoke_arg_unnamed;
            goto LABEL_115;
          }
          if ( !v44 || (v44 = 0, ++v11, !v12) )
          {
            if ( v11 == i_count )
              goto LABEL_104;
            if ( i_array_p && !i_array_p[v11]->vfptr->is_defaultable(i_array_p[v11]) )
            {
              i_result = Result_err_context_invoke_arg_skipped;
              goto LABEL_115;
            }
            ++v11;
            if ( v7 )
              APCompactArrayBase<SSExpressionBase>::append_null(v7);
LABEL_25:
            if ( (_BYTE)v15 == 41 )
              goto LABEL_103;
            if ( (_BYTE)v15 == 59 )
            {
              v46 = 1;
LABEL_103:
              i_result = Result_ok;
              goto LABEL_115;
            }
LABEL_86:
            i_result = Result_err_unexpected_eof;
            goto LABEL_99;
          }
          i_end_pos = v48;
          end_pos_pa = v48;
          if ( v13 )
            APCompactArrayBase<SSExpressionBase>::free_all_last(v13 + 1, v12);
          goto LABEL_99;
        }
      }
      if ( v11 == i_count )
      {
LABEL_104:
        i_result = Result_err_context_invoke_arg_end;
        goto LABEL_115;
      }
      v55[0] = v11;
      v17 = params_p;
      v18 = this;
      v19 = SSParser::parse_named_specifier(this, end_pos_pa, &end_pos_pa, params_p, v55, Type_send);
      i_result = v19;
      v20 = 0i64;
      v21 = v55[0];
      if ( v19 != Result_err_expected_named_arg )
      {
        if ( v19 )
          goto LABEL_114;
        if ( v44 )
        {
          v44 = 0;
          ++v11;
          if ( elem_count )
          {
            i_end_pos = v48;
            end_pos_pa = v48;
            v12 = elem_count;
            if ( !v13 )
              goto LABEL_99;
LABEL_34:
            APCompactArrayBase<SSExpressionBase>::free_all_last(v13 + 1, elem_count);
            goto LABEL_99;
          }
        }
        v45 = 1;
        if ( v17 )
        {
          if ( v63 && v63->i_count > v55[0] && v63->i_array_p[v55[0]] )
          {
            i_result = Result_err_context_invoke_arg_preexist;
LABEL_114:
            i_end_pos = end_pos_pa;
            goto LABEL_115;
          }
          v22 = (__int64)v17->i_params.i_array_p[v55[0]];
          v56 = v22;
          if ( (this->i_flags.i_flagset & 1) != 0 )
          {
            v23 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v22 + 64i64))(v22);
            v20 = (SSClassDescBase *)(*(__int64 (__fastcall **)(__int64, SSClassDescBase *))(*(_QWORD *)v23 + 32i64))(
                                       v23,
                                       v54);
          }
        }
        i_result = SSParser::parse_ws_any(this, end_pos_pa, &end_pos_pa);
        if ( i_result )
          goto LABEL_114;
        goto LABEL_68;
      }
      if ( v45 )
      {
        i_result = Result_err_context_invoke_arg_unnamed;
        goto LABEL_114;
      }
      if ( v17 )
        break;
LABEL_68:
      args.i_start_pos = end_pos_pa;
      args.i_type_p = v20;
      v34 = SSParser::parse_expression(v18, &args, 1ui64);
      i_end_pos = args.i_end_pos;
      end_pos_pa = args.i_end_pos;
      i_result = args.i_result;
      if ( args.i_result )
        goto LABEL_115;
      if ( (this->i_flags.i_flagset & 1) == 0 || (v35 = args.i_type_p->vfptr->is_class_type(args.i_type_p, v20)) )
        v35 = 1;
      v36 = v44;
      if ( v44 )
      {
        if ( !v35 )
        {
          v44 = 0;
          ++v11;
          v12 = elem_count;
          if ( elem_count )
          {
            i_end_pos = v48;
            end_pos_pa = v48;
            if ( v13 )
              APCompactArrayBase<SSExpressionBase>::free_all_last(v13 + 1, elem_count);
          }
          if ( v34 )
            v34->vfptr->__vecDelDtor(v34, 1u);
          goto LABEL_99;
        }
        ++v49;
        if ( v13 )
          APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(v13 + 1, v34);
      }
      else
      {
        if ( !v35 )
        {
          i_result = Result_err_typecheck_invoke_arg;
          if ( v34 )
            v34->vfptr->__vecDelDtor(v34, 1u);
          goto LABEL_115;
        }
        if ( v63 )
          APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::set_at_expand(
            v63,
            v21,
            v34);
        if ( !v45 || !params_p )
          ++v11;
        v36 = 0;
      }
      i_result = SSParser::parse_ws_any(this, i_end_pos, &end_pos_pa);
      if ( i_result )
        goto LABEL_114;
      i_end_pos = end_pos_pa;
      v37 = v58[end_pos_pa];
      if ( v37 == 44 )
      {
        i_end_pos = ++end_pos_pa;
        v12 = elem_count;
        goto LABEL_86;
      }
      if ( v37 != 41 )
      {
        if ( v37 != 59 )
        {
          i_result = Result_err_expected_invoke_args_next;
          if ( v37 == 35 )
            i_result = Result_err_unexpected_named_spec;
          goto LABEL_115;
        }
        v46 = 1;
      }
      if ( !v36 || (v44 = 0, ++v11, (v12 = elem_count) == 0) )
      {
        i_end_pos = ++end_pos_pa;
        i_result = Result_ok;
        goto LABEL_115;
      }
      i_end_pos = v48;
      end_pos_pa = v48;
      if ( v13 )
        goto LABEL_34;
LABEL_99:
      if ( i_end_pos >= i_length )
        goto LABEL_115;
      v7 = v63;
      v14 = this;
    }
    if ( v44 )
    {
      v24 = v56;
      v25 = v49;
      v26 = v51;
    }
    else
    {
      v24 = (__int64)v17->i_params.i_array_p[v11];
      v56 = v24;
      if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v24 + 32i64))(v24) != 3 )
      {
        v27 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v24 + 64i64))(v24);
        if ( v54 )
          v28 = (__int64)v54->vfptr->as_finalized_generic(v54, this->i_context.i_obj_scope_p);
        else
          v28 = 0i64;
        v29 = (*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v27 + 32i64))(v27, v28);
LABEL_67:
        v18 = this;
        v20 = (SSClassDescBase *)v29;
        goto LABEL_68;
      }
      v44 = 1;
      v25 = 0;
      v49 = 0;
      v26 = 1;
      if ( *(_DWORD *)(v24 + 16) )
        v26 = *(_DWORD *)(v24 + 16);
      v51 = v26;
    }
    v30 = v63;
    if ( v63 && !v25 )
    {
      v13 = (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *)AMemory::c_malloc_func(0x20ui64, "SSLiteralList");
      *(_QWORD *)v55 = v13;
      if ( v13 )
      {
        *(_QWORD *)&v13->i_count = &SSExpressionBase::`vftable;
        *(_QWORD *)&v13->i_count = &SSLiteralList::`vftable;
        v13->i_array_p = 0i64;
        v13[1].i_count = 0;
        v13[1].i_array_p = 0i64;
      }
      else
      {
        v13 = 0i64;
      }
      APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
        v30,
        (SSExpressionBase *)v13);
    }
    elem_count = v25 % v26;
    v31 = v48;
    if ( !(v25 % v26) )
      v31 = end_pos_pa;
    v48 = v31;
    v32 = *(_DWORD *)(v24 + 16);
    if ( v32 )
      v33 = *(SSClass **)(*(_QWORD *)(v24 + 24) + 8i64 * (v25 % v32));
    else
      v33 = SSBrain::c_object_class_p;
    v29 = (__int64)v33->vfptr->as_finalized_generic(v33, v54);
    goto LABEL_67;
  }
LABEL_115:
  v38 = (APCompactArrayBase<SSParameterBase> *)v63;
  if ( v63 )
  {
    if ( i_result )
    {
LABEL_128:
      APCompactArrayBase<SSParameterBase>::free_all(v38);
      goto LABEL_129;
    }
    v39 = v63->i_count;
    if ( v11 < v63->i_count )
    {
      v40 = &i_array_p[v11];
      v41 = (char *)((char *)v63->i_array_p - (char *)i_array_p);
      while ( *(SSParameterBase **)((char *)v40 + (_QWORD)v41) || (*v40)->vfptr->is_defaultable(*v40) )
      {
        ++v11;
        ++v40;
        if ( v11 >= v39 )
          goto LABEL_122;
      }
      goto LABEL_127;
    }
LABEL_122:
    if ( v11 < i_count )
    {
      v42 = &i_array_p[v11];
      while ( (*v42)->vfptr->is_defaultable(*v42) )
      {
        ++v11;
        ++v42;
        if ( v11 >= i_count )
          goto LABEL_129;
      }
LABEL_127:
      i_result = Result_err_context_invoke_arg_missing;
      goto LABEL_128;
    }
  }
LABEL_129:
  if ( v46 && i_result == Result_ok )
  {
    i_result = SSParser::parse_invoke_return_args(this, i_end_pos, &end_pos_pa, ret_args_p, receiver_type_p, params_p);
    i_end_pos = end_pos_pa;
  }
LABEL_132:
  if ( mem_p )
    *(_DWORD *)mem_p = i_end_pos;
  return (unsigned int)i_result;
}

// File Line: 5205
// RVA: 0x12C760
__int64 __fastcall SSParser::parse_invoke_return_args(
        SSParser *this,
        unsigned int start_pos,
        SSParameters *end_pos_p,
        APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *ret_args_p,
        SSClassUnaryBase *receiver_type_p,
        SSParameters *params_p)
{
  unsigned int i_end_pos; // esi
  SSParser::eResult i_result; // ebx
  SSParameters *v10; // rdi
  int v11; // r12d
  char *i_cstr_p; // r15
  char v13; // r15
  SSParser::eResult v14; // eax
  __int64 v15; // r15
  SSClassDescBase *v16; // rsi
  SSClassDescBase *v17; // rcx
  SSClassDescBase *i_obj_p; // rbx
  __int64 v20; // rax
  SSLiteralList *v21; // rax
  SSIdentifier *v22; // rdi
  int v23; // eax
  char v24; // cl
  size_t i_count; // rbx
  SSIdentifier **i_array_p; // rdi
  SSIdentifier **v27; // rax
  int v28; // [rsp+18h] [rbp-29h]
  unsigned int v29; // [rsp+1Ch] [rbp-25h] BYREF
  unsigned int *v30; // [rsp+20h] [rbp-21h]
  SSParameters::eType param_type[2]; // [rsp+28h] [rbp-19h]
  char *v32; // [rsp+30h] [rbp-11h]
  SSParser::Args args; // [rsp+38h] [rbp-9h] BYREF
  char v34; // [rsp+98h] [rbp+57h]
  unsigned int end_pos_pa; // [rsp+A0h] [rbp+5Fh] BYREF
  unsigned int *retaddr; // [rsp+A8h] [rbp+67h]
  SSClassDescBase *v37; // [rsp+B8h] [rbp+77h]

  LODWORD(v37) = start_pos;
  i_end_pos = start_pos;
  LODWORD(v30) = this->i_str_ref_p->i_length;
  i_result = Result_err_unexpected_eof;
  if ( (_DWORD)v30 == start_pos )
    goto LABEL_23;
  v10 = end_pos_p;
  if ( end_pos_p && ret_args_p )
  {
    AMemory::c_free_func(ret_args_p->i_array_p);
    ret_args_p->i_array_p = 0i64;
    ret_args_p->i_count = 0;
  }
  v11 = 0;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  v34 = 0;
  args.i_start_pos = i_end_pos;
  args.i_end_pos = 0;
  v32 = i_cstr_p;
  *(_QWORD *)&args.i_flags = ret_args_p != 0i64;
  args.i_type_p = 0i64;
  if ( i_end_pos >= (unsigned int)v30 )
    goto LABEL_20;
  while ( 1 )
  {
    i_result = SSParser::parse_ws_any(this, i_end_pos, &end_pos_pa);
    if ( i_result )
      goto LABEL_19;
    i_end_pos = end_pos_pa;
    v13 = i_cstr_p[end_pos_pa];
    if ( v13 != 41 && v13 != 44 )
      break;
    i_end_pos = ++end_pos_pa;
    if ( v11 || v13 == 44 )
    {
      if ( v34 )
      {
        i_result = Result_err_context_invoke_arg_unnamed;
        goto LABEL_20;
      }
      if ( v11 == v28 )
      {
LABEL_65:
        i_result = Result_err_context_invoke_arg_end;
        goto LABEL_20;
      }
      ++v11;
      if ( ret_args_p )
      {
        i_count = ret_args_p->i_count;
        i_array_p = ret_args_p->i_array_p;
        v27 = APArrayBase<SSIdentifier>::alloc_array((int)i_count + 1);
        i_count *= 8i64;
        ret_args_p->i_array_p = v27;
        memmove(v27, i_array_p, i_count);
        AMemory::c_free_func(i_array_p);
        *(SSIdentifier **)((char *)ret_args_p->i_array_p + i_count) = 0i64;
        ++ret_args_p->i_count;
      }
    }
    if ( v13 == 41 )
      goto LABEL_62;
    i_cstr_p = v32;
LABEL_53:
    i_result = Result_err_unexpected_eof;
    if ( i_end_pos >= (unsigned int)v30 )
      goto LABEL_20;
    v10 = end_pos_p;
  }
  if ( v11 == v28 )
    goto LABEL_65;
  v14 = SSParser::parse_named_specifier(this, end_pos_pa, &end_pos_pa, v10, &v29, Type_return);
  v15 = v29;
  v16 = 0i64;
  i_result = v14;
  *(_QWORD *)param_type = 0i64;
  if ( v14 == Result_err_expected_named_arg )
  {
    if ( !v34 )
    {
      if ( v10 )
      {
        i_obj_p = v10->i_return_params.i_array_p[v11]->i_type_p.i_obj_p;
        if ( v37 )
          v20 = (__int64)v37->vfptr->as_finalized_generic(v37, this->i_context.i_obj_scope_p);
        else
          v20 = 0i64;
        v16 = i_obj_p->vfptr->as_finalized_generic(i_obj_p, (SSClassDescBase *)v20);
        *(_QWORD *)param_type = v16;
      }
      goto LABEL_32;
    }
    i_result = Result_err_context_invoke_arg_unnamed;
    goto LABEL_19;
  }
  if ( v14 )
    goto LABEL_19;
  v34 = 1;
  if ( v10 )
  {
    if ( !ret_args_p || ret_args_p->i_count <= v29 || !ret_args_p->i_array_p[v29] )
    {
      if ( (this->i_flags.i_flagset & 1) != 0 )
      {
        v17 = v10->i_return_params.i_array_p[v29]->i_type_p.i_obj_p;
        v16 = v17->vfptr->as_finalized_generic(v17, v37);
        *(_QWORD *)param_type = v16;
      }
      goto LABEL_18;
    }
    i_result = Result_err_context_invoke_arg_preexist;
LABEL_19:
    i_end_pos = end_pos_pa;
    goto LABEL_20;
  }
LABEL_18:
  i_result = SSParser::parse_ws_any(this, end_pos_pa, &end_pos_pa);
  if ( i_result )
    goto LABEL_19;
LABEL_32:
  args.i_type_p = v16;
  args.i_start_pos = end_pos_pa;
  v21 = SSParser::parse_expression(this, &args, 3ui64);
  i_result = args.i_result;
  i_end_pos = args.i_end_pos;
  v22 = (SSIdentifier *)v21;
  end_pos_pa = args.i_end_pos;
  if ( args.i_result )
    goto LABEL_20;
  if ( v21 )
  {
    v23 = v21->vfptr->get_type(v21);
    if ( v23 <= 0 )
      goto LABEL_59;
    if ( v23 > 3 )
    {
      if ( v23 == 5 )
        i_result = Result_err_unexpected_reserved;
      else
LABEL_59:
        i_result = Result_err_unexpected_bind_expr;
      goto LABEL_20;
    }
    i_result = SSParser::validate_bind_type(this, v22, args.i_type_p, *(SSClassDescBase **)param_type);
    if ( i_result )
    {
      v22->vfptr->__vecDelDtor(v22, 1u);
      goto LABEL_20;
    }
    if ( ret_args_p )
    {
      APCompactArrayBase<SSIdentifier>::ensure_length_null(ret_args_p, v15 + 1);
      ret_args_p->i_array_p[v15] = v22;
    }
  }
  if ( !v34 || !end_pos_p )
    ++v11;
  i_result = SSParser::parse_ws_any(this, i_end_pos, &end_pos_pa);
  if ( i_result )
    goto LABEL_19;
  i_end_pos = end_pos_pa;
  i_cstr_p = v32;
  v24 = v32[end_pos_pa];
  if ( v24 == 44 )
  {
    i_end_pos = ++end_pos_pa;
    goto LABEL_53;
  }
  if ( v24 == 41 )
  {
    i_end_pos = end_pos_pa + 1;
LABEL_62:
    i_result = Result_ok;
  }
  else
  {
    i_result = Result_err_expected_invoke_args_next;
  }
LABEL_20:
  if ( ret_args_p && i_result )
    APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)ret_args_p);
LABEL_23:
  if ( retaddr )
    *retaddr = i_end_pos;
  return (unsigned int)i_result;
}

// File Line: 5536
// RVA: 0x12B180
SSInvokeSync *__fastcall SSParser::parse_invoke_apply(
        SSParser *this,
        SSParser::Args *args,
        SSExpressionBase *receiver_p)
{
  SSExpressionBase *v3; // r15
  __int64 i_start_pos; // rbp
  unsigned int i_length; // r9d
  char *i_cstr_p; // rdx
  _QWORD *v9; // r14
  SSClassDescBase *i_type_p; // rcx
  SSClass *v11; // rdi
  char v12; // r12
  eSSClassType v13; // eax
  SSClassUnion *reduced; // rsi
  __int64 v15; // r15
  __int64 v16; // rax
  SSMethodCall *v17; // rsi
  _QWORD *v18; // rax

  v3 = receiver_p;
  i_start_pos = args->i_start_pos;
  i_length = this->i_str_ref_p->i_length;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  v9 = 0i64;
  args->i_result = Result_err_unexpected_eof;
  if ( i_length - (unsigned int)i_start_pos < 2 )
    goto LABEL_28;
  args->i_result = Result_err_expected_invoke_apply;
  if ( i_cstr_p[i_start_pos] != 37 || i_cstr_p[(unsigned int)(i_start_pos + 1)] == 62 )
    goto LABEL_28;
  LODWORD(i_start_pos) = i_start_pos + 1;
  i_type_p = args->i_type_p;
  v11 = i_type_p ? (SSClass *)i_type_p->vfptr->as_finalized_generic(i_type_p, this->i_context.i_obj_scope_p) : 0i64;
  args->i_result = Result_err_typecheck_invoke_apply_recv;
  if ( v11 == SSBrain::c_none_class_p )
    goto LABEL_28;
  v12 = 0;
  v13 = v11->vfptr->get_class_type(v11);
  if ( v13 )
  {
    if ( v13 == SSClassType_typed_class )
    {
      v16 = (__int64)v11->vfptr->get_key_class(v11);
      if ( (*(unsigned __int8 (__fastcall **)(__int64, SSClass *))(*(_QWORD *)v16 + 96i64))(
             v16,
             SSBrain::c_list_class_p) )
      {
        v12 = 1;
        reduced = (SSClassUnion *)v11->vfptr->get_item_type(v11);
        goto LABEL_21;
      }
    }
    else if ( v13 == SSClassType_class_union )
    {
      reduced = SSClassUnion::get_reduced((SSClassUnion *)v11, SSBrain::c_none_class_p);
      v15 = (__int64)reduced->vfptr->get_key_class(reduced);
      if ( (*(unsigned __int8 (__fastcall **)(__int64, SSClass *))(*(_QWORD *)v15 + 96i64))(
             v15,
             SSBrain::c_list_class_p) )
      {
        v12 = 1;
        if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v15 + 104i64))(v15) == 2 )
          reduced = (SSClassUnion *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 112i64))(v15);
        else
          reduced = (SSClassUnion *)SSBrain::c_object_class_p;
      }
      v3 = receiver_p;
      goto LABEL_21;
    }
    goto LABEL_17;
  }
  if ( !v11->vfptr->is_class_type(v11, SSBrain::c_list_class_p) )
  {
LABEL_17:
    reduced = (SSClassUnion *)v11;
    goto LABEL_21;
  }
  v12 = 1;
  reduced = (SSClassUnion *)SSBrain::c_object_class_p;
LABEL_21:
  args->i_type_p = reduced;
  args->i_start_pos = i_start_pos;
  v17 = SSParser::parse_invoke_selector(this, args, 1);
  LODWORD(i_start_pos) = args->i_end_pos;
  if ( args->i_result == Result_ok )
  {
    if ( v12 )
      args->i_type_p = v11;
    else
      args->i_type_p = SSClassUnion::get_merge((SSClassUnion *)args->i_type_p, (SSClassUnion *)SSBrain::c_none_class_p);
    if ( (args->i_flags & 1) != 0 )
    {
      v18 = AMemory::c_malloc_func(0x18ui64, "SSInvokeSync");
      if ( v18 )
      {
        *v18 = &SSExpressionBase::`vftable;
        *v18 = &SSInvocation::`vftable;
        v18[1] = v3;
        v18[2] = v17;
        *v18 = &SSInvokeSync::`vftable;
        v9 = v18;
      }
    }
  }
LABEL_28:
  args->i_end_pos = i_start_pos;
  return (SSInvokeSync *)v9;
}

// File Line: 5693
// RVA: 0x12C540
SSInvokeRace *__fastcall SSParser::parse_invoke_race(
        SSParser *this,
        SSParser::Args *args,
        SSExpressionBase *receiver_p)
{
  SSExpressionBase *v3; // r15
  __int64 i_start_pos; // rbp
  unsigned int i_length; // r9d
  char *i_cstr_p; // rdx
  _QWORD *v9; // r14
  SSClassDescBase *i_type_p; // rcx
  SSClass *v11; // rdi
  char v12; // r12
  eSSClassType v13; // eax
  SSClassUnion *reduced; // rsi
  __int64 v15; // r15
  __int64 v16; // rax
  SSMethodCall *v17; // rsi
  _QWORD *v18; // rax

  v3 = receiver_p;
  i_start_pos = args->i_start_pos;
  i_length = this->i_str_ref_p->i_length;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  v9 = 0i64;
  args->i_result = Result_err_unexpected_eof;
  if ( i_length - (unsigned int)i_start_pos < 3 )
    goto LABEL_28;
  args->i_result = Result_err_expected_invoke_apply;
  if ( i_cstr_p[i_start_pos] != 37 || i_cstr_p[(unsigned int)(i_start_pos + 1)] != 62 )
    goto LABEL_28;
  LODWORD(i_start_pos) = i_start_pos + 2;
  i_type_p = args->i_type_p;
  v11 = i_type_p ? (SSClass *)i_type_p->vfptr->as_finalized_generic(i_type_p, this->i_context.i_obj_scope_p) : 0i64;
  args->i_result = Result_err_typecheck_invoke_apply_recv;
  if ( v11 == SSBrain::c_none_class_p )
    goto LABEL_28;
  v12 = 0;
  v13 = v11->vfptr->get_class_type(v11);
  if ( v13 )
  {
    if ( v13 == SSClassType_typed_class )
    {
      v16 = (__int64)v11->vfptr->get_key_class(v11);
      if ( (*(unsigned __int8 (__fastcall **)(__int64, SSClass *))(*(_QWORD *)v16 + 96i64))(
             v16,
             SSBrain::c_list_class_p) )
      {
        v12 = 1;
        reduced = (SSClassUnion *)v11->vfptr->get_item_type(v11);
        goto LABEL_21;
      }
    }
    else if ( v13 == SSClassType_class_union )
    {
      reduced = SSClassUnion::get_reduced((SSClassUnion *)v11, SSBrain::c_none_class_p);
      v15 = (__int64)reduced->vfptr->get_key_class(reduced);
      if ( (*(unsigned __int8 (__fastcall **)(__int64, SSClass *))(*(_QWORD *)v15 + 96i64))(
             v15,
             SSBrain::c_list_class_p) )
      {
        v12 = 1;
        if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v15 + 104i64))(v15) == 2 )
          reduced = (SSClassUnion *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 112i64))(v15);
        else
          reduced = (SSClassUnion *)SSBrain::c_object_class_p;
      }
      v3 = receiver_p;
      goto LABEL_21;
    }
    goto LABEL_17;
  }
  if ( !v11->vfptr->is_class_type(v11, SSBrain::c_list_class_p) )
  {
LABEL_17:
    reduced = (SSClassUnion *)v11;
    goto LABEL_21;
  }
  v12 = 1;
  reduced = (SSClassUnion *)SSBrain::c_object_class_p;
LABEL_21:
  args->i_type_p = reduced;
  args->i_start_pos = i_start_pos;
  v17 = SSParser::parse_invoke_selector(this, args, 1);
  LODWORD(i_start_pos) = args->i_end_pos;
  if ( args->i_result == Result_ok )
  {
    if ( v12 )
      args->i_type_p = v11;
    else
      args->i_type_p = SSClassUnion::get_merge((SSClassUnion *)args->i_type_p, (SSClassUnion *)SSBrain::c_none_class_p);
    if ( (args->i_flags & 1) != 0 )
    {
      v18 = AMemory::c_malloc_func(0x18ui64, "SSInvokeRace");
      if ( v18 )
      {
        *v18 = &SSExpressionBase::`vftable;
        *v18 = &SSInvocation::`vftable;
        v18[1] = v3;
        v18[2] = v17;
        *v18 = &SSInvokeRace::`vftable;
        v9 = v18;
      }
    }
  }
LABEL_28:
  args->i_end_pos = i_start_pos;
  return (SSInvokeRace *)v9;
}

// File Line: 5858
// RVA: 0x12BA80
SSInvokeCascade *__fastcall SSParser::parse_invoke_cascade(
        SSParser *this,
        SSParser::Args *args,
        SSExpressionBase *receiver_p)
{
  char *i_cstr_p; // r12
  unsigned int i_length; // r15d
  __int64 i_start_pos; // rdx
  SSParser::eResult v10; // eax
  char *v11; // rsi
  unsigned int i_end_pos; // edi
  unsigned int v13; // ebp
  SSClassDescBase *i_type_p; // r13
  SSMethodCall *v15; // rax
  SSParser::eResult v16; // eax
  char *end_pos_p; // [rsp+70h] [rbp+8h] BYREF
  char *v18; // [rsp+78h] [rbp+10h]

  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  i_length = this->i_str_ref_p->i_length;
  i_start_pos = args->i_start_pos;
  LODWORD(end_pos_p) = i_start_pos;
  if ( i_cstr_p[i_start_pos] == 91 )
  {
    v10 = SSParser::parse_ws_any(this, i_start_pos + 1, (unsigned int *)&end_pos_p);
    args->i_result = v10;
    if ( v10 )
    {
      args->i_end_pos = (unsigned int)end_pos_p;
      return 0i64;
    }
    else
    {
      v11 = 0i64;
      i_end_pos = (unsigned int)end_pos_p;
      if ( (args->i_flags & 1) != 0 && (unsigned int)end_pos_p < i_length )
      {
        v11 = (char *)AMemory::c_malloc_func(0x28ui64, "SSInvokeCascade");
        end_pos_p = v11;
        if ( v11 )
        {
          *(_QWORD *)v11 = &SSExpressionBase::`vftable;
          *(_QWORD *)v11 = &SSInvokeCascade::`vftable;
          *((_QWORD *)v11 + 1) = receiver_p;
          v18 = v11 + 16;
          *((_DWORD *)v11 + 4) = 0;
          *((_QWORD *)v11 + 3) = 0i64;
          *((_DWORD *)v11 + 8) = 0;
        }
        else
        {
          v11 = 0i64;
        }
      }
      v13 = 0;
      i_type_p = args->i_type_p;
      args->i_result = Result_err_unexpected_eof;
      if ( i_end_pos < i_length )
      {
        while ( i_cstr_p[i_end_pos] != 93 )
        {
          args->i_type_p = i_type_p;
          args->i_start_pos = i_end_pos;
          v15 = SSParser::parse_invoke_selector(this, args, 1);
          i_end_pos = args->i_end_pos;
          LODWORD(end_pos_p) = i_end_pos;
          if ( args->i_result )
            goto LABEL_22;
          ++v13;
          if ( v11 )
            APArray<SSInvokeBase,SSInvokeBase,ACompareAddress<SSInvokeBase>>::append(
              (APArray<SSInvokeBase,SSInvokeBase,ACompareAddress<SSInvokeBase> > *)(v11 + 16),
              v15);
          v16 = SSParser::parse_ws_any(this, i_end_pos, (unsigned int *)&end_pos_p);
          args->i_result = v16;
          i_end_pos = (unsigned int)end_pos_p;
          if ( v16 == Result_ok )
          {
            args->i_result = Result_err_unexpected_eof;
            if ( i_end_pos < i_length )
              continue;
          }
          goto LABEL_19;
        }
        ++i_end_pos;
        args->i_result = Result_ok;
      }
LABEL_19:
      if ( args->i_result == Result_ok && v13 < 2 )
        args->i_result = (v13 != 0) + 38;
LABEL_22:
      if ( v11 )
      {
        if ( args->i_result )
        {
          *((_QWORD *)v11 + 1) = 0i64;
          (**(void (__fastcall ***)(void *, __int64))v11)(v11, 1i64);
          v11 = 0i64;
        }
      }
      args->i_end_pos = i_end_pos;
      return (SSInvokeCascade *)v11;
    }
  }
  else
  {
    args->i_result = Result_err_expected_invoke_cascade;
    args->i_end_pos = i_start_pos;
    return 0i64;
  }
}

// File Line: 6003
// RVA: 0x12C310
SSExpressionBase *__fastcall SSParser::parse_invoke_operator(
        SSParser *this,
        SSParser::Args *args,
        SSExpressionBase *receiver_p)
{
  SSClassDescBase *i_type_p; // rcx
  _QWORD *v7; // rdi
  __int64 v8; // rax
  __int64 v9; // rsi
  SSParser::eResult v10; // eax
  _QWORD *v11; // rcx
  _QWORD *v12; // rcx
  APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > ret_args_p; // [rsp+48h] [rbp-28h] BYREF
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > args_p; // [rsp+58h] [rbp-18h] BYREF

  if ( this->i_str_ref_p->i_cstr_p[args->i_start_pos] != 40 )
  {
    args->i_result = Result_err_expected_invoke_args;
    return 0i64;
  }
  i_type_p = args->i_type_p;
  v7 = 0i64;
  if ( i_type_p )
    v8 = (__int64)i_type_p->vfptr->as_finalized_generic(i_type_p, this->i_context.i_obj_scope_p);
  else
    v8 = 0i64;
  v9 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 40i64))(v8);
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v9 + 104i64))(v9) != 3 )
  {
    args->i_result = Result_err__start;
    args->i_end_pos = args->i_start_pos + 1;
    return 0i64;
  }
  if ( (args->i_flags & 1) != 0 )
  {
    args_p.i_count = 0;
    args_p.i_array_p = 0i64;
    ret_args_p.i_count = 0;
    ret_args_p.i_array_p = 0i64;
    v10 = (unsigned int)SSParser::parse_invoke_args(
                          this,
                          args->i_start_pos,
                          &args->i_end_pos,
                          &args_p,
                          &ret_args_p,
                          0i64,
                          *(SSParameters **)(v9 + 24));
    args->i_result = v10;
    if ( v10 == Result_ok )
    {
      if ( *(_DWORD *)(v9 + 32) == 1 )
      {
        v11 = AMemory::c_malloc_func(0x30ui64, "SSInvokeClosureMethod");
        if ( v11 )
        {
          *v11 = &SSExpressionBase::`vftable;
          *v11 = &SSInvokeClosureBase::`vftable;
          v11[1] = receiver_p;
          *((_DWORD *)v11 + 4) = args_p.i_count;
          v11[3] = args_p.i_array_p;
          args_p.i_count = 0;
          args_p.i_array_p = 0i64;
          *((_DWORD *)v11 + 8) = ret_args_p.i_count;
          v11[5] = ret_args_p.i_array_p;
          ret_args_p.i_count = 0;
          ret_args_p.i_array_p = 0i64;
          *v11 = &SSInvokeClosureMethod::`vftable;
          v7 = v11;
        }
      }
      else
      {
        v12 = AMemory::c_malloc_func(0x30ui64, "SSInvokeClosureCoroutine");
        if ( v12 )
        {
          *v12 = &SSExpressionBase::`vftable;
          *v12 = &SSInvokeClosureBase::`vftable;
          v12[1] = receiver_p;
          *((_DWORD *)v12 + 4) = args_p.i_count;
          v12[3] = args_p.i_array_p;
          args_p.i_count = 0;
          args_p.i_array_p = 0i64;
          *((_DWORD *)v12 + 8) = ret_args_p.i_count;
          v12[5] = ret_args_p.i_array_p;
          ret_args_p.i_count = 0;
          ret_args_p.i_array_p = 0i64;
          *v12 = &SSInvokeClosureCoroutine::`vftable;
          v7 = v12;
        }
      }
    }
    AMemory::c_free_func(ret_args_p.i_array_p);
    AMemory::c_free_func(args_p.i_array_p);
  }
  else
  {
    args->i_result = SSParser::parse_invoke_args(
                       this,
                       args->i_start_pos,
                       &args->i_end_pos,
                       0i64,
                       0i64,
                       0i64,
                       *(SSParameters **)(v9 + 24));
  }
  if ( args->i_result == Result_ok )
    args->i_type_p = *(SSClassDescBase **)(*(_QWORD *)(v9 + 24) + 40i64);
  return (SSExpressionBase *)v7;
}

// File Line: 6095
// RVA: 0x12BE80
SSMethodCall *__fastcall SSParser::parse_invoke_ctor(SSParser *this, SSParser::Args *args)
{
  void (__fastcall ***v4)(_QWORD, __int64); // rbx
  __int64 i_start_pos; // rsi
  char *i_cstr_p; // rdx
  ASymbol *v7; // r9
  SSParser::eResult v8; // eax
  SSParameters *params_p; // r14
  SSMethodBase *v10; // rax
  void (__fastcall ***v11)(_QWORD, __int64); // rax
  unsigned int v12; // ebp
  APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *ret_args_p; // rcx
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v14; // r9
  void *end_pos_p; // [rsp+90h] [rbp+8h] BYREF
  int v17; // [rsp+98h] [rbp+10h] BYREF
  unsigned int start_pos; // [rsp+A0h] [rbp+18h] BYREF

  v4 = 0i64;
  i_start_pos = args->i_start_pos;
  start_pos = args->i_start_pos;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  args->i_result = Result_err_expected_method_ctor_name;
  if ( this->i_str_ref_p->i_length >= 3
    && i_cstr_p[i_start_pos] == 33
    && i_cstr_p[(unsigned int)(i_start_pos + 1)] != 33 )
  {
    v17 = -1;
    v7 = (ASymbol *)&v17;
    if ( (args->i_flags & 1) == 0 )
      v7 = 0i64;
    v8 = (unsigned int)SSParser::parse_name_method(this, i_start_pos, &start_pos, v7);
    args->i_result = v8;
    if ( v8 )
      goto LABEL_27;
    params_p = 0i64;
    if ( (this->i_flags.i_flagset & 1) != 0 )
    {
      v10 = args->i_type_p->vfptr->get_method_inherited(args->i_type_p, &v17);
      if ( v10 )
      {
        args->i_result = Result_ok;
        params_p = v10->i_params_p.i_obj_p;
      }
      else
      {
        args->i_result = Result_err_context_non_method;
      }
    }
    if ( args->i_result )
    {
LABEL_27:
      LODWORD(i_start_pos) = start_pos;
    }
    else
    {
      if ( (args->i_flags & 1) != 0 )
      {
        v11 = (void (__fastcall ***)(_QWORD, __int64))AMemory::c_malloc_func(0x38ui64, "SSMethodCall");
        v4 = v11;
        end_pos_p = v11;
        if ( v11 )
        {
          *((_DWORD *)v11 + 2) = v17;
          v11[2] = 0i64;
          *v11 = (void (__fastcall **)(_QWORD, __int64))&SSInvokeBase::`vftable;
          *((_DWORD *)v11 + 6) = 0;
          v11[4] = 0i64;
          *((_DWORD *)v11 + 10) = 0;
          v11[6] = 0i64;
          *v11 = (void (__fastcall **)(_QWORD, __int64))&SSMethodCall::`vftable;
        }
        else
        {
          v4 = 0i64;
        }
      }
      v12 = start_pos;
      LODWORD(end_pos_p) = start_pos;
      args->i_start_pos = start_pos;
      if ( v4 )
      {
        ret_args_p = (APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *)(v4 + 5);
        v14 = (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *)(v4 + 3);
      }
      else
      {
        ret_args_p = 0i64;
        v14 = 0i64;
      }
      args->i_result = SSParser::parse_invoke_args(
                         this,
                         v12,
                         (unsigned int *)&end_pos_p,
                         v14,
                         ret_args_p,
                         (SSClassUnaryBase *)args->i_type_p,
                         params_p);
      LODWORD(i_start_pos) = (_DWORD)end_pos_p;
      if ( (_DWORD)end_pos_p == v12 )
      {
        args->i_result = Result_err_context_invoke_ctor_args;
        if ( params_p )
        {
          if ( !(unsigned int)SSParameters::get_arg_count_min(params_p) )
            args->i_result = Result_ok;
        }
      }
      if ( args->i_result )
      {
        if ( v4 )
          (**v4)(v4, 1i64);
        v4 = 0i64;
      }
    }
  }
  args->i_end_pos = i_start_pos;
  return (SSMethodCall *)v4;
}

// File Line: 6213
// RVA: 0x12C060
SSMethodCall *__fastcall SSParser::parse_invoke_method(SSParser *this, SSParser::Args *args)
{
  __int64 v4; // rdi
  void (__fastcall ***v5)(_QWORD, __int64); // rbx
  SSClass *v6; // r15
  unsigned int i_start_pos; // r12d
  SSClassDescBase *i_type_p; // r13
  SSParser::eResult v9; // r14d
  unsigned int v10; // ebp
  ASymbol *v12; // r9
  SSParser::eResult v13; // eax
  SSParameters *params_p; // r14
  SSClass *v15; // rbp
  SSClassDescBase *v16; // rbp
  SSClassUnion *v17; // r14
  char is_class_maybe; // al
  __int64 v19; // rax
  void (__fastcall ***v20)(_QWORD, __int64); // rax
  unsigned int v21; // edx
  APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *ret_args_p; // rcx
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v23; // r9
  SSParser::eResult v24; // eax
  void *v26; // [rsp+A8h] [rbp+10h] BYREF
  int v27; // [rsp+B0h] [rbp+18h] BYREF
  SSClass *v28; // [rsp+B8h] [rbp+20h] BYREF

  v4 = 0i64;
  v5 = 0i64;
  v6 = 0i64;
  i_start_pos = args->i_start_pos;
  i_type_p = args->i_type_p;
  v28 = 0i64;
  LODWORD(v26) = i_start_pos;
  v9 = SSParser::parse_class(this, i_start_pos, (unsigned int *)&v26, &v28);
  if ( v9 )
  {
    v10 = (unsigned int)v26;
    if ( (_DWORD)v26 != i_start_pos )
      goto LABEL_11;
    goto LABEL_9;
  }
  if ( this->i_str_ref_p->i_length <= (unsigned int)v26 || this->i_str_ref_p->i_cstr_p[(unsigned int)v26] != 64 )
  {
    v10 = i_start_pos;
LABEL_10:
    v9 = Result_ok;
    goto LABEL_11;
  }
  v10 = (_DWORD)v26 + 1;
  v9 = Result_err_typecheck_scope;
  if ( !i_type_p || SSClass::is_scope_qualifier(v28, i_type_p) )
  {
LABEL_9:
    v6 = v28;
    goto LABEL_10;
  }
LABEL_11:
  LODWORD(v28) = v10;
  args->i_result = v9;
  if ( v9 )
  {
    args->i_end_pos = v10;
    return 0i64;
  }
  v27 = -1;
  v12 = (ASymbol *)&v27;
  if ( (args->i_flags & 1) == 0 )
    v12 = 0i64;
  v13 = (unsigned int)SSParser::parse_name_method(this, v10, (unsigned int *)&v28, v12);
  args->i_result = v13;
  if ( v13 )
    goto LABEL_30;
  params_p = 0i64;
  v15 = SSBrain::c_object_class_p;
  if ( (this->i_flags.i_flagset & 1) == 0 )
  {
LABEL_32:
    if ( (args->i_flags & 1) != 0 )
    {
      v20 = (void (__fastcall ***)(_QWORD, __int64))AMemory::c_malloc_func(0x38ui64, "SSMethodCall");
      v5 = v20;
      v26 = v20;
      if ( v20 )
      {
        *((_DWORD *)v20 + 2) = v27;
        v20[2] = (void (__fastcall **)(_QWORD, __int64))v6;
        *v20 = (void (__fastcall **)(_QWORD, __int64))&SSInvokeBase::`vftable;
        *((_DWORD *)v20 + 6) = 0;
        v20[4] = 0i64;
        *((_DWORD *)v20 + 10) = 0;
        v20[6] = 0i64;
        *v20 = (void (__fastcall **)(_QWORD, __int64))&SSMethodCall::`vftable;
      }
      else
      {
        v5 = 0i64;
      }
    }
    v21 = (unsigned int)v28;
    args->i_start_pos = (unsigned int)v28;
    if ( v5 )
    {
      ret_args_p = (APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *)(v5 + 5);
      v23 = (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *)(v5 + 3);
    }
    else
    {
      ret_args_p = 0i64;
      v23 = 0i64;
    }
    v24 = (unsigned int)SSParser::parse_invoke_args(
                          this,
                          v21,
                          &args->i_end_pos,
                          v23,
                          ret_args_p,
                          (SSClassUnaryBase *)args->i_type_p,
                          params_p);
    args->i_result = v24;
    if ( v24 )
    {
      if ( v5 )
        (**v5)(v5, 1i64);
    }
    else
    {
      args->i_type_p = v15;
      return (SSMethodCall *)v5;
    }
    return (SSMethodCall *)v4;
  }
  v16 = args->i_type_p;
  if ( v6 )
  {
    if ( v16->vfptr->is_metaclass(args->i_type_p) )
      v17 = (SSClassUnion *)v6->vfptr->get_metaclass(v6);
    else
      v17 = (SSClassUnion *)v6;
  }
  else
  {
    v17 = (SSClassUnion *)args->i_type_p;
  }
  if ( (this->i_flags.i_flagset & 2) == 0
    || v27 != ASymbol_String.i_uid
    || (v17->vfptr->get_class_type(v17) != SSClassType_class_union
      ? (is_class_maybe = v17->vfptr->is_class_type(v17, SSBrain::c_symbol_class_p))
      : (is_class_maybe = SSClassUnion::is_class_maybe(v17, SSBrain::c_symbol_class_p)),
        !is_class_maybe) )
  {
    v19 = (__int64)v17->vfptr->get_method_inherited(v17, (ASymbol *)&v27);
    if ( v19 )
    {
      params_p = *(SSParameters **)(v19 + 24);
      v15 = (SSClass *)params_p->i_result_type_p.i_obj_p->vfptr->as_finalized_generic(
                         params_p->i_result_type_p.i_obj_p,
                         v16);
      goto LABEL_32;
    }
  }
  args->i_result = Result_err_context_non_method;
LABEL_30:
  args->i_end_pos = (unsigned int)v28;
  return (SSMethodCall *)v4;
}

// File Line: 6343
// RVA: 0x12E850
SSMethodCall *__fastcall SSParser::parse_operator(SSParser *this, SSParser::Args *args, __int64 a3, __int64 a4)
{
  _DWORD *v5; // r14
  __int64 v6; // rdi
  unsigned int i_length; // r15d
  char *i_cstr_p; // rbx
  char v9; // dl
  unsigned __int8 v10; // r10
  unsigned __int8 v11; // r11
  __int64 v12; // r8
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rbx
  SSClassDescBase *i_type_p; // r12
  SSClass *v18; // r13
  SSParser *v19; // rax
  __int64 v20; // rax
  SSLiteralList *v21; // r15
  SSParser::eResult v22; // eax
  __int64 v23; // rcx
  SSClassDescBaseVtbl *vfptr; // rbx
  __int64 v25; // rax
  _DWORD *v26; // rax
  char v29; // [rsp+88h] [rbp+50h]
  unsigned int end_pos_p; // [rsp+90h] [rbp+58h] BYREF
  unsigned int i_uid; // [rsp+98h] [rbp+60h] BYREF

  i_uid = -1;
  v5 = 0i64;
  end_pos_p = args->i_start_pos;
  v6 = end_pos_p;
  v29 = 1;
  args->i_result = Result_ok;
  i_length = this->i_str_ref_p->i_length;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  v9 = 0;
  v10 = 0;
  LOBYTE(a4) = 0;
  v11 = 0;
  v12 = (unsigned int)(v6 + 1);
  if ( (unsigned int)v12 < i_length )
  {
    v9 = i_cstr_p[v12];
    v13 = (unsigned int)(v6 + 2);
    if ( (unsigned int)v13 < i_length )
    {
      v10 = i_cstr_p[v13];
      v14 = (unsigned int)(v6 + 3);
      if ( (unsigned int)v14 < i_length )
      {
        a4 = (unsigned __int8)i_cstr_p[v14];
        v15 = (unsigned int)(v6 + 4);
        if ( (unsigned int)v15 < i_length )
          v11 = i_cstr_p[v15];
      }
    }
  }
  switch ( i_cstr_p[v6] )
  {
    case !:
      if ( v9 != 61 )
        goto LABEL_77;
      LODWORD(v6) = v6 + 1;
      end_pos_p = v12;
      args->i_result = Result_err_unexpected_cpp;
      goto LABEL_78;
    case &:
    case ^:
    case |:
      goto $LN22_2;
    case *:
      if ( v9 == 61 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        i_uid = ASymbol_multiply_assign.i_uid;
      }
      else
      {
        LODWORD(v6) = v6 + 1;
        end_pos_p = v12;
        i_uid = ASymbol_multiply.i_uid;
      }
      goto LABEL_78;
    case +:
      if ( v9 == 43 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        i_uid = ASymbol_increment.i_uid;
        v29 = 0;
      }
      else if ( v9 == 61 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        i_uid = ASymbol_add_assign.i_uid;
      }
      else
      {
        LODWORD(v6) = v6 + 1;
        end_pos_p = v12;
        i_uid = ASymbol_add.i_uid;
      }
      goto LABEL_78;
    case -:
      if ( v9 == 45 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        i_uid = ASymbol_decrement.i_uid;
        v29 = 0;
      }
      else if ( v9 == 61 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        i_uid = ASymbol_subtract_assign.i_uid;
      }
      else
      {
        LODWORD(v6) = v6 + 1;
        end_pos_p = v12;
        i_uid = ASymbol_subtract.i_uid;
      }
      goto LABEL_78;
    case /:
      if ( v9 == 61 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        i_uid = ASymbol_divide_assign.i_uid;
      }
      else
      {
        LODWORD(v6) = v6 + 1;
        end_pos_p = v12;
        i_uid = ASymbol_divide.i_uid;
      }
      goto LABEL_78;
    case ::
      if ( v9 != 61 )
        goto LABEL_77;
      LODWORD(v6) = v6 + 2;
      end_pos_p = v6;
      i_uid = ASymbol_assign.i_uid;
      goto LABEL_78;
    case <:
      if ( v9 == 60 )
      {
        LODWORD(v6) = v6 + 1;
        args->i_result = Result_err_unexpected_cpp;
      }
      else if ( v9 == 61 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        i_uid = ASymbol_less_or_equal.i_uid;
        goto LABEL_78;
      }
      LODWORD(v6) = v6 + 1;
      end_pos_p = v6;
      i_uid = ASymbol_less.i_uid;
      goto LABEL_78;
    case =:
      LODWORD(v6) = v6 + 1;
      end_pos_p = v12;
      if ( v9 == 61 )
        args->i_result = Result_err_unexpected_cpp;
      else
        i_uid = ASymbol_equals.i_uid;
      goto LABEL_78;
    case >:
      if ( v9 == 61 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        i_uid = ASymbol_greater_or_equal.i_uid;
      }
      else
      {
        LODWORD(v6) = v6 + 1;
        end_pos_p = v12;
        i_uid = ASymbol_greater.i_uid;
      }
      goto LABEL_78;
    case a:
      if ( v9 != 110 || v10 != 100 || (_BYTE)a4 == 40 || !byte_14236F1C0[(unsigned __int8)a4] )
        goto LABEL_77;
      LODWORD(v6) = v6 + 3;
      end_pos_p = v6;
      i_uid = ASymbol_and.i_uid;
      goto LABEL_78;
    case n:
      if ( v9 == 97 )
      {
        if ( v10 == 110 && (_BYTE)a4 == 100 && v11 != 40 && byte_14236F1C0[v11] )
        {
          LODWORD(v6) = v6 + 4;
          end_pos_p = v6;
          i_uid = ASymbol_nand.i_uid;
          goto LABEL_78;
        }
      }
      else if ( v9 == 111 )
      {
        if ( v10 == 114 && (_BYTE)a4 != 40 && byte_14236F1C0[(unsigned __int8)a4] )
        {
          LODWORD(v6) = v6 + 3;
          end_pos_p = v6;
          i_uid = ASymbol_nor.i_uid;
          goto LABEL_78;
        }
      }
      else if ( v9 == 120 && v10 == 111 && (_BYTE)a4 == 114 && v11 != 40 && byte_14236F1C0[v11] )
      {
        LODWORD(v6) = v6 + 4;
        end_pos_p = v6;
        i_uid = ASymbol_nxor.i_uid;
        goto LABEL_78;
      }
LABEL_77:
      args->i_result = Result_err_expected_operator;
      goto LABEL_78;
    case o:
      if ( v9 != 114 || v10 == 40 || !byte_14236F1C0[v10] )
        goto LABEL_77;
      LODWORD(v6) = v6 + 2;
      end_pos_p = v6;
      i_uid = ASymbol_or.i_uid;
      goto LABEL_78;
    case x:
      if ( v9 != 111 || v10 != 114 || (_BYTE)a4 == 40 || !byte_14236F1C0[(unsigned __int8)a4] )
        goto LABEL_77;
      LODWORD(v6) = v6 + 3;
      end_pos_p = v6;
      i_uid = ASymbol_xor.i_uid;
      goto LABEL_78;
    case ~:
      if ( v9 == 38 )
      {
$LN22_2:
        LODWORD(v6) = v6 + 1;
        end_pos_p = v12;
      }
      else
      {
        if ( v9 == 61 )
        {
          LODWORD(v6) = v6 + 2;
          end_pos_p = v6;
          i_uid = ASymbol_not_equal.i_uid;
          goto LABEL_78;
        }
        LODWORD(v6) = v6 + 1;
        end_pos_p = v12;
        if ( v9 != 94 && v9 != 124 )
        {
          i_uid = ASymbol_not.i_uid;
          v29 = 0;
          goto LABEL_78;
        }
      }
      args->i_result = Result_err_unexpected_deprecated;
LABEL_78:
      if ( args->i_result )
        goto LABEL_101;
      v16 = 0i64;
      i_type_p = args->i_type_p;
      v18 = SSBrain::c_object_class_p;
      v19 = this;
      if ( (this->i_flags.i_flagset & 1) != 0 )
      {
        v20 = ((__int64 (__fastcall *)(SSClassDescBase *, unsigned int *, __int64, __int64, __int64))i_type_p->vfptr->get_method_inherited)(
                args->i_type_p,
                &i_uid,
                v12,
                a4,
                -2i64);
        if ( v20 )
        {
          v16 = *(_QWORD *)(v20 + 24);
          v18 = (SSClass *)(*(__int64 (__fastcall **)(_QWORD, SSClassDescBase *))(**(_QWORD **)(v16 + 40) + 32i64))(
                             *(_QWORD *)(v16 + 40),
                             i_type_p);
        }
        else
        {
          args->i_result = Result_err_context_non_method;
        }
        v19 = this;
      }
      if ( args->i_result )
        goto LABEL_101;
      v21 = 0i64;
      if ( !v29 )
        goto LABEL_95;
      v22 = SSParser::parse_ws_any(v19, v6, &end_pos_p);
      args->i_result = v22;
      if ( v22 )
      {
        LODWORD(v6) = end_pos_p;
      }
      else
      {
        args->i_start_pos = end_pos_p;
        v21 = SSParser::parse_expression(this, args, 1ui64);
        LODWORD(v6) = args->i_end_pos;
        if ( (this->i_flags.i_flagset & 1) != 0 )
        {
          if ( args->i_result )
            goto LABEL_101;
          if ( *(_DWORD *)(v16 + 8) )
            v23 = **(_QWORD **)(v16 + 16);
          else
            v23 = 0i64;
          vfptr = args->i_type_p->vfptr;
          v25 = (*(__int64 (__fastcall **)(_QWORD, SSClassDescBase *))(**(_QWORD **)(v23 + 16) + 32i64))(
                  *(_QWORD *)(v23 + 16),
                  i_type_p);
          if ( !vfptr->is_class_type(args->i_type_p, (SSClassDescBase *)v25) )
            args->i_result = Result_err_typecheck_operand;
        }
      }
LABEL_95:
      if ( args->i_result == Result_ok )
      {
        args->i_type_p = v18;
        if ( (args->i_flags & 1) != 0 )
        {
          v26 = AMemory::c_malloc_func(0x38ui64, "SSMethodCall");
          if ( v26 )
          {
            v26[2] = i_uid;
            *((_QWORD *)v26 + 2) = 0i64;
            *(_QWORD *)v26 = &SSInvokeBase::`vftable;
            v26[6] = 0;
            *((_QWORD *)v26 + 4) = 0i64;
            v26[10] = 0;
            *((_QWORD *)v26 + 6) = 0i64;
            *(_QWORD *)v26 = &SSMethodCall::`vftable;
            v5 = v26;
          }
          if ( v21 )
            APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
              (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *)(v5 + 6),
              v21);
        }
      }
LABEL_101:
      args->i_end_pos = v6;
      return (SSMethodCall *)v5;
    default:
      goto LABEL_77;
  }
}

// File Line: 6813
// RVA: 0x12BC40
SSCoroutineCall *__fastcall SSParser::parse_invoke_coroutine(SSParser *this, SSParser::Args *args)
{
  __int64 v4; // rdi
  void (__fastcall ***v5)(_QWORD, __int64); // rbx
  SSClass *v6; // r15
  unsigned int i_start_pos; // r12d
  SSClassDescBase *i_type_p; // r13
  SSParser::eResult v9; // r14d
  unsigned int v10; // ebp
  ASymbol *v12; // r9
  SSParser::eResult v13; // eax
  SSParameters *params_p; // rbp
  SSClassDescBase *v15; // rcx
  bool v16; // al
  __int64 v17; // rax
  void (__fastcall ***v18)(_QWORD, __int64); // rax
  unsigned int v19; // edx
  APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *ret_args_p; // rcx
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v21; // r9
  SSParser::eResult v22; // eax
  void *v24; // [rsp+A8h] [rbp+10h] BYREF
  SSClass *v25; // [rsp+B0h] [rbp+18h] BYREF
  int v26; // [rsp+B8h] [rbp+20h] BYREF

  v4 = 0i64;
  v5 = 0i64;
  v6 = 0i64;
  i_start_pos = args->i_start_pos;
  i_type_p = args->i_type_p;
  v25 = 0i64;
  LODWORD(v24) = i_start_pos;
  v9 = SSParser::parse_class(this, i_start_pos, (unsigned int *)&v24, &v25);
  if ( v9 )
  {
    v10 = (unsigned int)v24;
    if ( (_DWORD)v24 != i_start_pos )
      goto LABEL_11;
    goto LABEL_9;
  }
  if ( this->i_str_ref_p->i_length <= (unsigned int)v24 || this->i_str_ref_p->i_cstr_p[(unsigned int)v24] != 64 )
  {
    v10 = i_start_pos;
LABEL_10:
    v9 = Result_ok;
    goto LABEL_11;
  }
  v10 = (_DWORD)v24 + 1;
  v9 = Result_err_typecheck_scope;
  if ( !i_type_p || SSClass::is_scope_qualifier(v25, i_type_p) )
  {
LABEL_9:
    v6 = v25;
    goto LABEL_10;
  }
LABEL_11:
  LODWORD(v25) = v10;
  args->i_result = v9;
  if ( v9 )
  {
    args->i_end_pos = v10;
    return 0i64;
  }
  v26 = -1;
  v12 = (ASymbol *)&v26;
  if ( (args->i_flags & 1) == 0 )
    v12 = 0i64;
  v13 = SSParser::parse_name_coroutine(this, v10, (unsigned int *)&v25, v12);
  args->i_result = v13;
  if ( v13 )
    goto LABEL_22;
  params_p = 0i64;
  if ( (this->i_flags.i_flagset & 1) == 0 )
  {
LABEL_24:
    if ( (args->i_flags & 1) != 0 )
    {
      v18 = (void (__fastcall ***)(_QWORD, __int64))AMemory::c_malloc_func(0x38ui64, "SSCoroutineCall");
      v5 = v18;
      v24 = v18;
      if ( v18 )
      {
        *((_DWORD *)v18 + 2) = v26;
        v18[2] = (void (__fastcall **)(_QWORD, __int64))v6;
        *v18 = (void (__fastcall **)(_QWORD, __int64))&SSInvokeBase::`vftable;
        *((_DWORD *)v18 + 6) = 0;
        v18[4] = 0i64;
        *((_DWORD *)v18 + 10) = 0;
        v18[6] = 0i64;
        *v18 = (void (__fastcall **)(_QWORD, __int64))&SSCoroutineCall::`vftable;
      }
      else
      {
        v5 = 0i64;
      }
    }
    v19 = (unsigned int)v25;
    args->i_start_pos = (unsigned int)v25;
    if ( v5 )
    {
      ret_args_p = (APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *)(v5 + 5);
      v21 = (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *)(v5 + 3);
    }
    else
    {
      ret_args_p = 0i64;
      v21 = 0i64;
    }
    v22 = (unsigned int)SSParser::parse_invoke_args(
                          this,
                          v19,
                          &args->i_end_pos,
                          v21,
                          ret_args_p,
                          (SSClassUnaryBase *)args->i_type_p,
                          params_p);
    args->i_result = v22;
    if ( v22 )
    {
      if ( v5 )
        (**v5)(v5, 1i64);
    }
    else
    {
      args->i_type_p = SSBrain::c_invoked_coroutine_class_p;
      return (SSCoroutineCall *)v5;
    }
    return (SSCoroutineCall *)v4;
  }
  v15 = args->i_type_p;
  if ( v6 )
  {
    v16 = v15->vfptr->is_metaclass(v15);
    v15 = v6;
    if ( v16 )
      v15 = v6->vfptr->get_metaclass(v6);
  }
  v17 = (__int64)v15->vfptr->get_coroutine_inherited(v15, (ASymbol *)&v26);
  if ( v17 )
  {
    params_p = *(SSParameters **)(v17 + 24);
    goto LABEL_24;
  }
  args->i_result = Result_err_context_non_coroutine;
LABEL_22:
  args->i_end_pos = (unsigned int)v25;
  return (SSCoroutineCall *)v4;
}

// File Line: 6922
// RVA: 0x12CB60
SSMethodCall *__fastcall SSParser::parse_invoke_selector(SSParser *this, SSParser::Args *args, bool test_op)
{
  unsigned int i_start_pos; // esi
  SSParser::eResult v7; // eax
  __int64 v8; // rdx
  char *i_cstr_p; // r8
  unsigned __int8 v10; // cl
  SSMethodCall *result; // rax
  unsigned int end_pos_p; // [rsp+48h] [rbp+10h] BYREF
  __int64 v13; // [rsp+58h] [rbp+20h]

  i_start_pos = args->i_start_pos;
  end_pos_p = i_start_pos;
  v13 = 0i64;
  v7 = SSParser::parse_class(this, i_start_pos, &end_pos_p, 0i64);
  if ( v7 )
  {
    LODWORD(v8) = end_pos_p;
    if ( end_pos_p == i_start_pos )
      v7 = Result_ok;
  }
  else if ( this->i_str_ref_p->i_length > end_pos_p && this->i_str_ref_p->i_cstr_p[end_pos_p] == 64 )
  {
    LODWORD(v8) = end_pos_p + 1;
    v7 = Result_ok;
  }
  else
  {
    v7 = Result_ok;
    LODWORD(v8) = i_start_pos;
  }
  args->i_result = v7;
  if ( v7 )
  {
LABEL_18:
    args->i_end_pos = v8;
    return 0i64;
  }
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  v10 = i_cstr_p[(unsigned int)v8];
  args->i_result = Result_err_expected_invoke_selector;
  if ( v10 == 95 )
  {
    v8 = (unsigned int)(v8 + 1);
    if ( AString::c_is_lowercase[(unsigned __int8)i_cstr_p[v8]] )
      return (SSMethodCall *)SSParser::parse_invoke_coroutine(this, args);
    goto LABEL_18;
  }
  if ( v10 == 33 || AString::c_char_match_table[0][v10] )
    return SSParser::parse_invoke_method(this, args);
  if ( !test_op )
    goto LABEL_18;
  result = SSParser::parse_operator(this, args);
  if ( args->i_end_pos == i_start_pos )
    args->i_result = Result_err_expected_invoke_select_op;
  return result;
}

// File Line: 7098
// RVA: 0x12CC70
__int64 __fastcall SSParser::parse_literal_char_esc_seq(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        char *ch_p)
{
  SSParser::eResult v6; // r10d
  char *i_cstr_p; // r11
  int v8; // edx
  int v9; // ebx
  __int64 result; // rax
  int int_p; // [rsp+50h] [rbp+8h] BYREF
  unsigned int end_pos_pa; // [rsp+58h] [rbp+10h] BYREF

  v6 = Result_err_unexpected_eof;
  if ( this->i_str_ref_p->i_length - start_pos >= 2 )
  {
    i_cstr_p = this->i_str_ref_p->i_cstr_p;
    v6 = Result_err_expected_char;
    if ( i_cstr_p[start_pos] == 92 )
    {
      v8 = start_pos + 1;
      v6 = Result_ok;
      v9 = i_cstr_p[v8];
      start_pos = v8 + 1;
      switch ( v9 )
      {
        case a:
          LOBYTE(v9) = 7;
          break;
        case b:
          LOBYTE(v9) = 8;
          break;
        case f:
          LOBYTE(v9) = 12;
          break;
        case n:
          LOBYTE(v9) = 10;
          break;
        case r:
          LOBYTE(v9) = 13;
          break;
        case t:
          LOBYTE(v9) = 9;
          break;
        case v:
          LOBYTE(v9) = 11;
          break;
        default:
          if ( AString::c_is_digit[(unsigned __int8)v9] )
          {
            end_pos_pa = start_pos - 1;
            v6 = SSParser::parse_literal_integer(this, start_pos - 1, &end_pos_pa, &int_p, 0i64);
            if ( v6 == Result_ok )
            {
              v6 = Result_err_expected_char_number;
              if ( (unsigned int)int_p <= 0xFF )
              {
                LOBYTE(v9) = int_p;
                v6 = Result_ok;
              }
            }
            start_pos = end_pos_pa;
          }
          break;
      }
      if ( ch_p && v6 == Result_ok )
        *ch_p = v9;
    }
  }
  result = (unsigned int)v6;
  if ( end_pos_p )
    *end_pos_p = start_pos;
  return result;
}

// File Line: 7211
// RVA: 0x12CDE0
__int64 __fastcall SSParser::parse_literal_integer(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        int *int_p,
        unsigned int *radix_p)
{
  AStringRef *i_str_ref_p; // rax
  unsigned int *v6; // r12
  __int64 v8; // rsi
  unsigned int v9; // r11d
  char *i_cstr_p; // r14
  int v11; // r10d
  char *v12; // rbx
  char *v13; // r9
  char v14; // dl
  __int64 v15; // rax
  int v16; // ecx
  __int64 i; // rax
  bool v18; // r15
  char v19; // dl
  unsigned int v20; // r8d
  bool v21; // bl
  int v22; // edi
  int v23; // ecx
  int v24; // eax
  __int64 result; // rax
  int v26; // [rsp+48h] [rbp+10h]

  i_str_ref_p = this->i_str_ref_p;
  v6 = end_pos_p;
  LODWORD(v8) = start_pos;
  v9 = 82;
  if ( this->i_str_ref_p->i_length > start_pos )
  {
    i_cstr_p = i_str_ref_p->i_cstr_p;
    v11 = 10;
    v12 = &i_str_ref_p->i_cstr_p[start_pos];
    v13 = v12;
    if ( *v12 == 45 )
    {
      v13 = v12 + 1;
      v14 = 1;
      v9 = 29;
    }
    else
    {
      v14 = 0;
      v9 = 33;
    }
    v15 = (unsigned __int8)*v13;
    if ( AString::c_is_digit[v15] )
    {
      ++v13;
      v16 = (char)v15 - 48;
      if ( (char)v15 != 48 )
      {
        for ( i = (unsigned __int8)*v13; AString::c_is_digit[i]; i = (unsigned __int8)*v13 )
        {
          ++v13;
          v16 = (char)i + 2 * (5 * v16 - 24);
        }
      }
      if ( v14 )
        v16 = -v16;
      v9 = 0;
    }
    else
    {
      v16 = v26;
    }
    v8 = (unsigned int)((_DWORD)v13 - (_DWORD)v12 + v8);
    if ( !v9 )
    {
      if ( i_cstr_p[v8] != 114 )
      {
LABEL_36:
        if ( int_p )
          *int_p = v16;
        if ( radix_p )
          *radix_p = v11;
        goto LABEL_40;
      }
      v11 = v16;
      v18 = v16 < 0;
      if ( v16 < 0 )
        v11 = -v16;
      v9 = 94;
      if ( v11 >= 2 )
      {
        v9 = 93;
        if ( v11 <= 36 )
        {
          v8 = (unsigned int)(v8 + 1);
          v16 = 0;
          v19 = i_cstr_p[v8];
          v9 = 9;
          v20 = v8;
          if ( v11 > 10 )
          {
            while ( 1 )
            {
              v21 = AString::c_is_digit[(unsigned __int8)v19];
              if ( !v21 )
              {
                v22 = AString::c_char2lower[(unsigned __int8)v19];
                if ( v22 < 97 || v22 > v11 + 86 )
                  break;
              }
              v23 = v11 * v16;
              if ( v21 )
                v24 = v19 - 48;
              else
                v24 = AString::c_char2lower[(unsigned __int8)v19] - 87;
              v16 = v24 + v23;
              v19 = i_cstr_p[++v20];
            }
            v6 = end_pos_p;
          }
          else
          {
            while ( v19 >= 48 && v19 <= (char)(v11 + 47) )
            {
              v16 = v19 + v11 * v16 - 48;
              v19 = i_cstr_p[++v20];
            }
          }
          if ( v20 > (unsigned int)v8 )
          {
            if ( !byte_14236F1C0[(unsigned __int8)v19] )
            {
              LODWORD(v8) = v20 + 1;
              goto LABEL_40;
            }
            if ( v18 )
              v16 = -v16;
            LODWORD(v8) = v20;
            v9 = 0;
            goto LABEL_36;
          }
        }
      }
    }
  }
LABEL_40:
  result = v9;
  if ( v6 )
    *v6 = v8;
  return result;
}

// File Line: 7336
// RVA: 0x12D010
SSLiteralList *__fastcall SSParser::parse_literal_list(
        SSParser *this,
        SSParser::Args *args,
        SSTypedClass *list_class_p,
        bool item_type_b,
        SSMethodCall *ctor_p)
{
  bool v5; // r12
  SSTypedClass *v6; // r13
  SSLiteralList *v9; // r15
  SSTypedClass *i_start_pos; // rbx
  char *i_cstr_p; // rcx
  SSParser::eResult v12; // eax
  SSClass *v13; // rsi
  SSClass *v14; // rax
  SSClass *i_superclass_p; // rcx
  SSMethodCall *v16; // rax
  SSMethodCall *v17; // rsi
  SSParser::eResult v18; // eax
  SSClassUnion *p_class_union; // r13
  bool v20; // cf
  SSLiteralList *v21; // rax
  SSParser::eResult v22; // eax
  char v23; // cl
  SSParser::eResult v24; // eax
  SSClass *v25; // rax
  SSTypedClass *v26; // rcx
  SSLiteralList *result; // rax
  char *v28; // [rsp+30h] [rbp-41h]
  SSClassUnion class_union; // [rsp+48h] [rbp-29h] BYREF
  unsigned int end_pos_p; // [rsp+D0h] [rbp+5Fh] BYREF
  SSClassUnaryBase *class_pp; // [rsp+D8h] [rbp+67h] BYREF
  SSTypedClass *v32; // [rsp+E0h] [rbp+6Fh]
  bool item_type_b_p; // [rsp+E8h] [rbp+77h] BYREF

  item_type_b_p = item_type_b;
  v32 = list_class_p;
  v5 = item_type_b;
  v6 = list_class_p;
  v9 = 0i64;
  i_start_pos = (SSTypedClass *)args->i_start_pos;
  end_pos_p = args->i_start_pos;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  v28 = i_cstr_p;
  args->i_result = Result_ok;
  if ( list_class_p || i_cstr_p[(_QWORD)i_start_pos] == 123 )
    goto LABEL_13;
  v12 = (unsigned int)SSParser::parse_class_instance(
                        this,
                        (unsigned int)i_start_pos,
                        &end_pos_p,
                        (SSTypedClass **)&class_pp,
                        &item_type_b_p);
  args->i_result = v12;
  if ( v12
    || (args->i_result = Result_err_typecheck_list,
        v13 = SSBrain::c_list_class_p,
        i_start_pos = (SSTypedClass *)class_pp,
        v14 = class_pp->vfptr->get_key_class(class_pp),
        v13 != v14)
    && ((i_superclass_p = v14->i_superclass_p) == 0i64 || !SSClass::is_class(i_superclass_p, v13)) )
  {
    i_cstr_p = v28;
    LODWORD(i_start_pos) = end_pos_p;
    v5 = item_type_b_p;
LABEL_13:
    v17 = ctor_p;
    goto LABEL_14;
  }
  v6 = i_start_pos;
  v32 = i_start_pos;
  args->i_type_p = i_start_pos;
  args->i_start_pos = end_pos_p;
  v16 = SSParser::parse_invoke_ctor(this, args);
  v17 = v16;
  LODWORD(i_start_pos) = args->i_end_pos;
  end_pos_p = (unsigned int)i_start_pos;
  if ( v16 && v16->i_name.i_uid == ASymbolX_ctor.i_uid && !v16->i_arguments.i_count )
  {
    v16->vfptr->__vecDelDtor(v16, 1u);
    v17 = 0i64;
  }
  v5 = item_type_b_p;
  i_cstr_p = v28;
LABEL_14:
  if ( args->i_result == Result_ok )
  {
    args->i_result = Result_err_unexpected_eof;
    LODWORD(class_pp) = this->i_str_ref_p->i_length;
    if ( (unsigned int)((_DWORD)class_pp - (_DWORD)i_start_pos) >= 2 )
    {
      args->i_result = Result_err_expected_literal_list;
      if ( i_cstr_p[(unsigned int)i_start_pos] == 123 )
      {
        v18 = SSParser::parse_ws_any(this, (_DWORD)i_start_pos + 1, &end_pos_p);
        args->i_result = v18;
        if ( v18 )
        {
          LODWORD(i_start_pos) = end_pos_p;
        }
        else
        {
          class_union.i_ref_count = 0;
          class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable;
          class_union.i_common_class_p = 0i64;
          class_union.i_union.i_count = 0;
          class_union.i_union.i_array_p = 0i64;
          class_union.i_union.i_size = 0;
          if ( v5 )
            p_class_union = (SSClassUnion *)v6->vfptr->get_item_type(v6);
          else
            p_class_union = &class_union;
          if ( (args->i_flags & 1) != 0 )
          {
            v9 = (SSLiteralList *)AMemory::c_malloc_func(0x20ui64, "SSLiteralList");
            if ( v9 )
            {
              v9->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
              v9->vfptr = (SSExpressionBaseVtbl *)&SSLiteralList::`vftable;
              v9->i_ctor_p = v17;
              v9->i_item_exprs.i_count = 0;
              v9->i_item_exprs.i_array_p = 0i64;
            }
            else
            {
              v9 = 0i64;
            }
            v17 = 0i64;
          }
          LODWORD(i_start_pos) = end_pos_p;
          if ( v28[end_pos_p] == 125 )
          {
            LODWORD(i_start_pos) = end_pos_p + 1;
            if ( !v5 )
              p_class_union = (SSClassUnion *)SSBrain::c_object_class_p;
          }
          else
          {
            while ( 1 )
            {
              v20 = (unsigned int)i_start_pos < (unsigned int)class_pp;
              args->i_result = Result_err_unexpected_eof;
              if ( !v20 )
                break;
              args->i_start_pos = (unsigned int)i_start_pos;
              v21 = SSParser::parse_expression(this, args, 1ui64);
              LODWORD(i_start_pos) = args->i_end_pos;
              end_pos_p = (unsigned int)i_start_pos;
              if ( args->i_result )
                break;
              if ( v21 )
                APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
                  &v9->i_item_exprs,
                  v21);
              if ( (this->i_flags.i_flagset & 1) != 0 )
              {
                if ( v5 )
                {
                  if ( !args->i_type_p->vfptr->is_class_type(args->i_type_p, p_class_union) )
                  {
                    args->i_result = Result_err_typecheck_list_item;
                    break;
                  }
                }
                else
                {
                  SSClassUnion::merge_class(&class_union, (SSClassUnion *)args->i_type_p);
                }
              }
              v22 = SSParser::parse_ws_any(this, (unsigned int)i_start_pos, &end_pos_p);
              args->i_result = v22;
              if ( v22 )
                goto LABEL_46;
              LODWORD(i_start_pos) = end_pos_p;
              v23 = v28[end_pos_p];
              if ( v23 == 125 )
              {
                LODWORD(i_start_pos) = end_pos_p + 1;
                break;
              }
              if ( v23 != 44 )
              {
                args->i_result = Result_err_expected_literal_list_end;
                break;
              }
              v24 = SSParser::parse_ws_any(this, end_pos_p + 1, &end_pos_p);
              args->i_result = v24;
              if ( v24 )
              {
LABEL_46:
                LODWORD(i_start_pos) = end_pos_p;
                break;
              }
              LODWORD(i_start_pos) = end_pos_p;
            }
          }
          if ( (this->i_flags.i_flagset & 1) != 0 && args->i_result == Result_ok )
          {
            if ( v5 )
            {
              v26 = v32;
            }
            else
            {
              if ( p_class_union == &class_union )
              {
                if ( class_union.i_union.i_count > 1 )
                  p_class_union = SSClassUnion::get_or_create(&class_union);
                else
                  p_class_union = (SSClassUnion *)class_union.i_common_class_p;
              }
              if ( v32 )
                v25 = v32->vfptr->get_key_class(v32);
              else
                v25 = SSBrain::c_list_class_p;
              v26 = SSTypedClass::get_or_create(v25, p_class_union);
            }
            args->i_type_p = v26;
          }
          SSClassUnion::~SSClassUnion(&class_union);
        }
      }
    }
  }
  if ( args->i_result )
  {
    if ( v17 )
      v17->vfptr->__vecDelDtor(v17, 1u);
    if ( v9 )
      v9->vfptr->__vecDelDtor(v9, 1u);
    result = 0i64;
  }
  else
  {
    result = v9;
  }
  args->i_end_pos = (unsigned int)i_start_pos;
  return result;
}

// File Line: 7589
// RVA: 0x12D3C0
SSLiteral *__fastcall SSParser::parse_literal_number(SSParser *this, SSParser::Args *args)
{
  unsigned int i_start_pos; // ebp
  _QWORD *v5; // rbx
  float *v6; // r9
  SSParser::eResult v7; // eax
  unsigned int v8; // eax
  int *v9; // r9
  SSParser::eResult v10; // edx
  __int64 v12[9]; // [rsp+30h] [rbp-48h] BYREF
  __int64 end_pos_p; // [rsp+88h] [rbp+10h] BYREF
  __int64 v14; // [rsp+90h] [rbp+18h] BYREF
  int v15; // [rsp+98h] [rbp+20h] BYREF

  v12[1] = -2i64;
  v15 = 0;
  i_start_pos = args->i_start_pos;
  v5 = 0i64;
  v6 = (float *)&v15;
  if ( (args->i_flags & 1) == 0 )
    v6 = 0i64;
  v7 = SSParser::parse_literal_real(this, i_start_pos, (unsigned int *)&v14, v6);
  args->i_result = v7;
  if ( v7 )
  {
    LODWORD(v12[0]) = 0;
    v9 = (int *)v12;
    if ( (args->i_flags & 1) == 0 )
      v9 = 0i64;
    v10 = (unsigned int)SSParser::parse_literal_integer(this, i_start_pos, (unsigned int *)&end_pos_p, v9, 0i64);
    if ( v10 )
    {
      v8 = v14;
      if ( (unsigned int)end_pos_p >= (unsigned int)v14 )
      {
        v8 = end_pos_p;
        args->i_result = v10;
      }
    }
    else
    {
      if ( (args->i_flags & 1) != 0 )
      {
        v5 = AMemory::c_malloc_func(0x18ui64, "SSLiteral");
        v12[2] = (__int64)v5;
        if ( v5 )
        {
          LODWORD(v14) = v12[0];
          *v5 = &SSExpressionBase::`vftable;
          *v5 = &SSLiteral::`vftable;
          v5[1] = v14;
          *((_DWORD *)v5 + 4) = 2;
        }
        else
        {
          v5 = 0i64;
        }
        args->i_type_p = SSBrain::c_integer_class_p;
      }
      v8 = end_pos_p;
      args->i_result = Result_ok;
    }
  }
  else
  {
    if ( (args->i_flags & 1) != 0 )
    {
      v5 = AMemory::c_malloc_func(0x18ui64, "SSLiteral");
      v12[0] = (__int64)v5;
      if ( v5 )
      {
        LODWORD(end_pos_p) = v15;
        *v5 = &SSExpressionBase::`vftable;
        *v5 = &SSLiteral::`vftable;
        v5[1] = end_pos_p;
        *((_DWORD *)v5 + 4) = 3;
      }
      else
      {
        v5 = 0i64;
      }
      args->i_type_p = SSBrain::c_real_class_p;
    }
    v8 = v14;
  }
  args->i_end_pos = v8;
  return (SSLiteral *)v5;
}

// File Line: 7670
// RVA: 0x12D550
__int64 __fastcall SSParser::parse_literal_real(
        SSParser *this,
        __int64 start_pos,
        unsigned int *end_pos_p,
        float *real_p)
{
  AStringRef *i_str_ref_p; // rax
  unsigned int v8; // r11d
  char *i_cstr_p; // rsi
  char *v10; // rdi
  char *v11; // r10
  char v12; // bp
  __int64 v13; // rax
  int v14; // r9d
  signed int v15; // ebx
  __int64 i; // rax
  char v17; // di
  char v18; // r14
  bool v19; // zf
  double v20; // xmm6_8
  __int64 v21; // rcx
  double v22; // xmm1_8
  int v23; // eax
  SSParser::eResult v24; // eax
  double v25; // xmm2_8
  double v26; // xmm2_8
  double v27; // xmm0_8
  unsigned int v28; // eax
  double v29; // xmm1_8
  double v30; // xmm7_8
  float v31; // xmm0_4
  __int64 result; // rax
  int int_p; // [rsp+90h] [rbp+8h] BYREF
  unsigned int end_pos_pa; // [rsp+98h] [rbp+10h] BYREF

  i_str_ref_p = this->i_str_ref_p;
  v8 = 82;
  if ( this->i_str_ref_p->i_length > (unsigned int)start_pos )
  {
    i_cstr_p = i_str_ref_p->i_cstr_p;
    v10 = &i_str_ref_p->i_cstr_p[(unsigned int)start_pos];
    v11 = v10;
    if ( *v10 == 45 )
    {
      v11 = v10 + 1;
      v12 = 1;
      v8 = 29;
    }
    else
    {
      v12 = 0;
      v8 = 33;
    }
    v13 = (unsigned __int8)*v11;
    v14 = 0;
    if ( AString::c_is_digit[v13] )
    {
      ++v11;
      v15 = (char)v13 - 48;
      if ( (char)v13 != 48 )
      {
        for ( i = (unsigned __int8)*v11; AString::c_is_digit[i]; i = (unsigned __int8)*v11 )
        {
          ++v11;
          v15 = (char)i + 2 * (5 * v15 - 24);
        }
      }
      if ( v12 )
        v15 = -v15;
      v8 = 0;
    }
    else
    {
      v12 = end_pos_pa;
      v15 = end_pos_pa;
    }
    start_pos = (unsigned int)((_DWORD)v11 - (_DWORD)v10 + start_pos);
    if ( !v8 )
    {
      v17 = 0;
      v18 = 0;
      v19 = i_cstr_p[start_pos] == 46;
      v20 = 0.0;
      int_p = 0;
      if ( v19 )
      {
        start_pos = (unsigned int)(start_pos + 1);
        v18 = 1;
        v8 = 29;
        v21 = (unsigned __int8)i_cstr_p[start_pos];
        if ( !AString::c_is_digit[v21] )
        {
LABEL_24:
          if ( real_p && !v8 )
          {
            v25 = (double)v15;
            if ( v12 )
              v26 = v25 - v20;
            else
              v26 = v25 + v20;
            if ( v17 )
            {
              v27 = DOUBLE_10_0;
              v28 = v14;
              if ( v14 < 0 )
                v28 = -v14;
              v29 = DOUBLE_1_0;
              while ( 1 )
              {
                if ( (v28 & 1) != 0 )
                  v29 = v29 * v27;
                v28 >>= 1;
                if ( !v28 )
                  break;
                v27 = v27 * v27;
              }
              if ( v14 >= 0 )
                v30 = v29;
              else
                v30 = 1.0 / v29;
              v26 = v26 * v30;
            }
            v31 = v26;
            *real_p = v31;
          }
          goto LABEL_42;
        }
        v22 = DOUBLE_1_0;
        do
        {
          v23 = (char)v21;
          start_pos = (unsigned int)(start_pos + 1);
          v22 = v22 * 0.1;
          v21 = (unsigned __int8)i_cstr_p[start_pos];
          v20 = v20 + (double)(v23 - 48) * v22;
        }
        while ( AString::c_is_digit[v21] );
        v8 = 0;
      }
      if ( ((i_cstr_p[start_pos] - 69) & 0xDF) == 0 )
      {
        v17 = 1;
        end_pos_pa = start_pos + 1;
        v24 = SSParser::parse_literal_simple_int(this, start_pos + 1, &end_pos_pa, &int_p, 0i64);
        LODWORD(start_pos) = end_pos_pa;
        v14 = int_p;
        v8 = v24;
      }
      if ( !v18 && !v17 )
        v8 = 60;
      goto LABEL_24;
    }
  }
LABEL_42:
  result = v8;
  if ( end_pos_p )
    *end_pos_p = start_pos;
  return result;
}

// File Line: 7776
// RVA: 0x12D7D0
__int64 __fastcall SSParser::parse_literal_simple_int(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        int *int_p,
        bool *negative_p)
{
  char *v6; // rbx
  unsigned int v8; // r11d
  char *v9; // r10
  bool v10; // r9
  __int64 v11; // rax
  int v12; // eax
  __int64 i; // rdx
  int v14; // ecx
  int v15; // eax
  __int64 result; // rax

  v6 = &this->i_str_ref_p->i_cstr_p[start_pos];
  v8 = 82;
  v9 = v6;
  if ( this->i_str_ref_p->i_length > start_pos )
  {
    if ( *v6 == 45 )
    {
      v9 = v6 + 1;
      v10 = 1;
      v8 = 29;
    }
    else
    {
      v10 = 0;
      v8 = 33;
    }
    v11 = (unsigned __int8)*v9;
    if ( AString::c_is_digit[v11] )
    {
      ++v9;
      v12 = (char)v11 - 48;
      if ( v12 )
      {
        for ( i = (unsigned __int8)*v9; AString::c_is_digit[i]; v12 = v15 + 2 * v14 - 48 )
        {
          v14 = 5 * v12;
          ++v9;
          v15 = (char)i;
          i = (unsigned __int8)*v9;
        }
      }
      if ( int_p )
      {
        if ( v10 )
          v12 = -v12;
        *int_p = v12;
      }
      if ( negative_p )
        *negative_p = v10;
      v8 = 0;
    }
  }
  result = v8;
  if ( end_pos_p )
    *end_pos_p = start_pos + (_DWORD)v9 - (_DWORD)v6;
  return result;
}

// File Line: 7862
// RVA: 0x12D8B0
__int64 __fastcall SSParser::parse_literal_simple_string(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        AString *str_p)
{
  __int64 v4; // rdi
  AStringRef *i_str_ref_p; // r9
  SSParser *v7; // r10
  unsigned int v8; // esi
  unsigned int i_length; // edx
  char *i_cstr_p; // r12
  unsigned int v11; // ebp
  unsigned int v12; // r13d
  unsigned int i; // ebx
  char v14; // cl
  unsigned int v15; // r8d
  int v16; // r15d
  unsigned int v17; // ebp
  char v18; // cl
  unsigned int v19; // eax
  unsigned int end_pos_pa; // [rsp+20h] [rbp-48h] BYREF
  char *v22; // [rsp+28h] [rbp-40h]
  char ch_p; // [rsp+78h] [rbp+10h] BYREF
  unsigned int *v25; // [rsp+80h] [rbp+18h]

  v25 = end_pos_p;
  v4 = start_pos;
  i_str_ref_p = this->i_str_ref_p;
  v7 = this;
  v8 = 82;
  i_length = this->i_str_ref_p->i_length;
  if ( i_length - (unsigned int)v4 >= 2 )
  {
    i_cstr_p = i_str_ref_p->i_cstr_p;
    v8 = 45;
    if ( i_str_ref_p->i_cstr_p[v4] == 34 )
    {
      v8 = 0;
      v11 = v4 + 1;
      v12 = 0;
      v22 = 0i64;
      for ( i = v4 + 1; i < i_length; ++i )
      {
        v14 = i_cstr_p[i];
        if ( v14 == 34 )
          break;
        if ( v14 == 92 )
          ++i;
      }
      if ( str_p )
      {
        v12 = str_p->i_str_ref_p->i_length;
        v15 = i + v12 - v4 - 1;
        if ( v15 >= str_p->i_str_ref_p->i_size || str_p->i_str_ref_p->i_ref_count + str_p->i_str_ref_p->i_read_only != 1 )
          AString::set_size(str_p, v15);
        if ( str_p->i_str_ref_p->i_ref_count + str_p->i_str_ref_p->i_read_only != 1 )
          AString::make_writeable(str_p);
        v7 = this;
        v22 = str_p->i_str_ref_p->i_cstr_p;
      }
      LODWORD(v4) = v4 + 1;
      end_pos_pa = v11;
      v16 = 0;
      if ( v11 >= i )
      {
LABEL_25:
        LODWORD(v4) = i + 1;
        v12 += v16;
      }
      else
      {
        v17 = v12;
        while ( !v8 )
        {
          v18 = i_cstr_p[(unsigned int)v4];
          ch_p = v18;
          if ( v18 == 92 )
          {
            v19 = SSParser::parse_literal_char_esc_seq(v7, v4, &end_pos_pa, &ch_p);
            LODWORD(v4) = end_pos_pa;
            v18 = ch_p;
            v8 = v19;
          }
          else
          {
            LODWORD(v4) = v4 + 1;
            end_pos_pa = v4;
          }
          if ( str_p )
            v22[v17] = v18;
          v7 = this;
          ++v16;
          ++v17;
          if ( (unsigned int)v4 >= i )
          {
            if ( v8 )
              break;
            goto LABEL_25;
          }
        }
      }
      if ( str_p )
        AString::set_length(str_p, v12);
    }
  }
  if ( v25 )
    *v25 = v4;
  return v8;
}

// File Line: 7990
// RVA: 0x12DA60
unsigned int __fastcall SSParser::parse_literal_string(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        AString *str_p)
{
  unsigned int result; // eax
  unsigned int v8; // ebx
  unsigned int i_length; // edi
  char *i_cstr_p; // rbp
  unsigned int v11; // edx
  unsigned int v12; // esi
  unsigned int v13[4]; // [rsp+20h] [rbp-38h] BYREF
  unsigned int start_posa; // [rsp+68h] [rbp+10h] BYREF
  unsigned int end_pos_pa; // [rsp+70h] [rbp+18h] BYREF

  start_posa = start_pos;
  result = SSParser::parse_literal_simple_string(this, start_pos, &start_posa, str_p);
  v8 = start_posa;
  if ( !result )
  {
    i_length = this->i_str_ref_p->i_length;
    i_cstr_p = this->i_str_ref_p->i_cstr_p;
    if ( start_posa < i_length )
    {
      do
      {
        result = SSParser::parse_ws_any(this, v8, &end_pos_pa);
        if ( result )
          break;
        v11 = end_pos_pa;
        if ( end_pos_pa >= i_length )
          break;
        if ( i_cstr_p[end_pos_pa] != 43 )
          break;
        ++end_pos_pa;
        result = SSParser::parse_ws_any(this, v11 + 1, &end_pos_pa);
        if ( result )
          break;
        v12 = end_pos_pa;
        if ( end_pos_pa >= i_length )
          break;
        result = SSParser::parse_literal_simple_string(this, end_pos_pa, v13, str_p);
        if ( result )
        {
          if ( v13[0] == v12 )
            result = 0;
          break;
        }
        v8 = v13[0];
      }
      while ( v13[0] < i_length );
    }
  }
  if ( end_pos_p )
    *end_pos_p = v8;
  return result;
}

// File Line: 8074
// RVA: 0x12DB50
__int64 __fastcall SSParser::parse_literal_symbol(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        ASymbol *sym_p)
{
  unsigned int i_length; // esi
  unsigned int v7; // ebx
  unsigned int v9; // edi
  char *i_cstr_p; // rbp
  unsigned int v11; // edx
  bool v12; // al
  __int64 v13; // rsi
  char i_uid; // cl
  unsigned int v15; // eax
  __int64 result; // rax
  char cstr_p[256]; // [rsp+30h] [rbp-138h] BYREF
  unsigned int find_pos_p; // [rsp+170h] [rbp+8h] BYREF
  ASymbol ch_p; // [rsp+178h] [rbp+10h] BYREF
  unsigned int end_pos_pa; // [rsp+180h] [rbp+18h] BYREF

  i_length = this->i_str_ref_p->i_length;
  v7 = start_pos;
  v9 = 46;
  if ( i_length - start_pos >= 2 )
  {
    i_cstr_p = this->i_str_ref_p->i_cstr_p;
    if ( i_cstr_p[start_pos] == 39 )
    {
      v7 = start_pos + 1;
      v11 = start_pos + 1;
      do
      {
        find_pos_p = i_length;
        v12 = AString::find(this, 39, 1u, &find_pos_p, v11, 0xFFFFFFFF);
        v11 = find_pos_p;
      }
      while ( find_pos_p != i_length && i_cstr_p[find_pos_p - 1] == 92 );
      v13 = 0i64;
      v9 = 47;
      if ( v12 )
        v9 = 0;
      end_pos_pa = v7;
      if ( v7 >= find_pos_p )
      {
LABEL_16:
        if ( !v9 )
        {
          v7 = v11 + 1;
          if ( sym_p )
          {
            cstr_p[v13] = 0;
            sym_p->i_uid = ASymbol::create(&ch_p, cstr_p, v13, ATerm_short)->i_uid;
          }
        }
      }
      else
      {
        while ( !v9 )
        {
          i_uid = i_cstr_p[v7];
          LOBYTE(ch_p.i_uid) = i_uid;
          if ( i_uid == 92 )
          {
            v15 = SSParser::parse_literal_char_esc_seq(this, v7, &end_pos_pa, (char *)&ch_p);
            v7 = end_pos_pa;
            v11 = find_pos_p;
            i_uid = ch_p.i_uid;
            v9 = v15;
          }
          else
          {
            end_pos_pa = ++v7;
          }
          cstr_p[v13] = i_uid;
          v13 = (unsigned int)(v13 + 1);
          if ( (unsigned int)v13 > 0xFF )
            v9 = 96;
          if ( v7 >= v11 )
            goto LABEL_16;
        }
      }
    }
  }
  result = v9;
  if ( end_pos_p )
    *end_pos_p = v7;
  return result;
}

// File Line: 8165
// RVA: 0x12DCF0
SSLoopExit *__fastcall SSParser::parse_loop_exit(SSParser *this, SSParser::Args *args)
{
  __int64 i_start_pos; // rdx
  char *i_cstr_p; // r8
  __int64 v6; // rsi
  _DWORD *v7; // rdi
  SSParser::eResult v8; // eax
  ASymbol *v9; // r9
  SSParser::eResult v10; // eax
  _DWORD *v11; // rcx
  unsigned int end_pos_p; // [rsp+58h] [rbp+10h] BYREF
  int v14; // [rsp+60h] [rbp+18h] BYREF

  args->i_result = Result_err_unexpected_eof;
  i_start_pos = args->i_start_pos;
  if ( (unsigned int)(this->i_str_ref_p->i_length - i_start_pos) >= 4
    && (args->i_result = Result_err_expected_loop_exit,
        i_cstr_p = this->i_str_ref_p->i_cstr_p,
        i_cstr_p[i_start_pos] == 101)
    && i_cstr_p[(unsigned int)(i_start_pos + 1)] == 120
    && i_cstr_p[(unsigned int)(i_start_pos + 2)] == 105
    && i_cstr_p[(unsigned int)(i_start_pos + 3)] == 116
    && (v6 = (unsigned int)(i_start_pos + 4), byte_14236F1C0[(unsigned __int8)i_cstr_p[v6]]) )
  {
    v7 = 0i64;
    end_pos_p = i_start_pos + 4;
    v8 = SSParser::parse_ws_any(this, v6, &end_pos_p);
    args->i_result = v8;
    if ( v8 == Result_ok )
    {
      v14 = -1;
      v9 = (ASymbol *)&v14;
      if ( (args->i_flags & 1) == 0 )
        v9 = 0i64;
      v10 = SSParser::parse_name_instance(this, end_pos_p, &end_pos_p, v9);
      args->i_result = v10;
      if ( v10 )
        args->i_result = Result_ok;
      else
        LODWORD(v6) = end_pos_p;
      if ( (args->i_flags & 1) != 0 )
      {
        v11 = AMemory::c_malloc_func(0x10ui64, "SSLoopExit");
        if ( v11 )
        {
          *(_QWORD *)v11 = &SSExpressionBase::`vftable;
          *(_QWORD *)v11 = &SSLoopExit::`vftable;
          v11[2] = v14;
          v7 = v11;
        }
      }
    }
    if ( args->i_result == Result_ok )
      args->i_type_p = SSBrain::c_none_class_p;
    args->i_end_pos = v6;
    return (SSLoopExit *)v7;
  }
  else
  {
    args->i_end_pos = i_start_pos;
    return 0i64;
  }
}

// File Line: 8258
// RVA: 0x12DE50
SSLoop *__fastcall SSParser::parse_loop_tail(SSParser *this, SSParser::Args *args)
{
  unsigned int i_start_pos; // edi
  SSParser::eResult v5; // eax
  ASymbol *v6; // r9
  __int64 v7; // rsi
  SSCode *v8; // rax
  SSCode *v9; // rdi
  _DWORD *v10; // rax
  _DWORD *start_pos; // [rsp+50h] [rbp+8h] BYREF
  unsigned int end_pos_p; // [rsp+58h] [rbp+10h] BYREF
  int v14; // [rsp+60h] [rbp+18h] BYREF

  args->i_result = Result_err_unexpected_eof;
  i_start_pos = args->i_start_pos;
  end_pos_p = i_start_pos;
  if ( this->i_str_ref_p->i_length - i_start_pos < 2 )
    goto LABEL_15;
  v5 = SSParser::parse_ws_any(this, i_start_pos, &end_pos_p);
  args->i_result = v5;
  i_start_pos = end_pos_p;
  args->i_end_pos = end_pos_p;
  if ( v5 )
    goto LABEL_15;
  v14 = -1;
  v6 = (ASymbol *)&v14;
  v7 = 0i64;
  if ( (args->i_flags & 1) == 0 )
    v6 = 0i64;
  if ( SSParser::parse_name_instance(this, i_start_pos, (unsigned int *)&start_pos, v6) )
  {
    args->i_result = Result_ok;
  }
  else
  {
    args->i_result = SSParser::parse_ws_any(this, (unsigned int)start_pos, &end_pos_p);
    i_start_pos = end_pos_p;
  }
  if ( args->i_result
    || (args->i_result = Result_err_expected_loop_block, this->i_str_ref_p->i_cstr_p[i_start_pos] != 91) )
  {
LABEL_15:
    args->i_end_pos = i_start_pos;
    return 0i64;
  }
  else
  {
    args->i_start_pos = i_start_pos;
    v8 = SSParser::parse_code_block_optimized(this, args, SSInvokeTime_any, ResultDesired_false);
    v9 = v8;
    if ( args->i_result == Result_ok )
    {
      args->i_type_p = SSBrain::c_none_class_p;
      if ( v8 )
      {
        v10 = AMemory::c_malloc_func(0x18ui64, "SSLoop");
        start_pos = v10;
        if ( v10 )
        {
          *(_QWORD *)v10 = &SSExpressionBase::`vftable;
          *(_QWORD *)v10 = &SSLoop::`vftable;
          v10[2] = v14;
          *((_QWORD *)v10 + 2) = v9;
          return (SSLoop *)v10;
        }
      }
    }
    return (SSLoop *)v7;
  }
}

// File Line: 8585
// RVA: 0x12DFA0
__int64 __fastcall SSParser::parse_name_class(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        ASymbol *name_p,
        SSParser::eClassCheck check)
{
  AStringRef *i_str_ref_p; // rcx
  unsigned int v10; // r11d
  unsigned int i_uid; // eax
  SSClass **i_array_p; // r8
  SSClass **v13; // r10
  SSClass **v14; // rcx
  unsigned int v15; // r9d
  _BOOL8 v16; // rdx
  _BOOL8 v17; // r9
  char v18; // cl
  __int64 v19; // rax
  ASymbol result; // [rsp+50h] [rbp+8h] BYREF
  unsigned int find_pos_p; // [rsp+58h] [rbp+10h] BYREF

  i_str_ref_p = this->i_str_ref_p;
  find_pos_p = start_pos;
  v10 = 82;
  if ( i_str_ref_p->i_length > start_pos )
  {
    v10 = 15;
    if ( AString::c_is_uppercase[(unsigned __int8)i_str_ref_p->i_cstr_p[start_pos]] )
    {
      find_pos_p = start_pos + 1;
      find_pos_p = i_str_ref_p->i_length;
      AString::find(this, ACharMatch_not_identifier, 1u, &find_pos_p, start_pos + 1, 0xFFFFFFFF);
      if ( (check & 1) != 0 )
      {
        i_uid = SSParser::as_symbol(this, &result, start_pos, find_pos_p)->i_uid;
        if ( (check & 2) != 0 && i_uid == ASymbol_Class.i_uid )
        {
          v10 = 74;
        }
        else
        {
          if ( SSBrain::c_classes.i_count )
          {
            i_array_p = SSBrain::c_classes.i_array_p;
            v13 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
            while ( 1 )
            {
              while ( 1 )
              {
                v14 = &i_array_p[((char *)v13 - (char *)i_array_p) >> 4];
                v15 = (*v14)->i_name.i_uid;
                if ( i_uid >= v15 )
                {
                  v16 = i_uid == v15;
                  v17 = i_uid != v15;
                  if ( 1 - v16 >= 0 )
                    break;
                }
                if ( i_array_p == v14 )
                  goto LABEL_17;
                v13 = v14 - 1;
              }
              if ( v17 <= 0 )
                break;
              if ( v13 == v14 )
                goto LABEL_17;
              i_array_p = v14 + 1;
            }
            v18 = 1;
          }
          else
          {
LABEL_17:
            v18 = 0;
          }
          v10 = 112;
          if ( v18 )
            v10 = 0;
        }
        if ( name_p )
          name_p->i_uid = i_uid;
      }
      else
      {
        if ( name_p )
          name_p->i_uid = SSParser::as_symbol(this, &result, start_pos, find_pos_p)->i_uid;
        if ( (check & 2) != 0 && name_p && name_p->i_uid == ASymbol_Class.i_uid )
          v10 = 74;
        else
          v10 = 0;
      }
    }
  }
  v19 = v10;
  if ( end_pos_p )
    *end_pos_p = find_pos_p;
  return v19;
}

// File Line: 8655
// RVA: 0x12E210
__int64 __fastcall SSParser::parse_name_instance(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        ASymbol *name_p)
{
  __int64 v4; // rbx
  AStringRef *i_str_ref_p; // rdx
  unsigned int v9; // r11d
  ASymbol *v10; // rax
  unsigned int i_uid; // eax
  ASymbol **i_array_p; // rcx
  ASymbol **v13; // r9
  __int64 v14; // rax
  ASymbol result; // [rsp+50h] [rbp+8h] BYREF
  unsigned int find_pos_p; // [rsp+58h] [rbp+10h] BYREF

  v4 = start_pos;
  i_str_ref_p = this->i_str_ref_p;
  find_pos_p = v4;
  v9 = 82;
  if ( i_str_ref_p->i_length > (unsigned int)v4 )
  {
    v9 = 32;
    if ( AString::c_is_lowercase[(unsigned __int8)i_str_ref_p->i_cstr_p[v4]] )
    {
      find_pos_p = v4 + 1;
      find_pos_p = i_str_ref_p->i_length;
      AString::find(this, ACharMatch_not_identifier, 1u, &find_pos_p, v4 + 1, 0xFFFFFFFF);
      v10 = SSParser::as_symbol(this, &result, v4, find_pos_p);
      v9 = 0;
      i_uid = v10->i_uid;
      if ( SSParser::c_reserved_word_syms.i_count
        && (i_array_p = SSParser::c_reserved_word_syms.i_array_p,
            v13 = &SSParser::c_reserved_word_syms.i_array_p[SSParser::c_reserved_word_syms.i_count - 1],
            SSParser::c_reserved_word_syms.i_array_p <= v13) )
      {
        while ( i_uid != (*i_array_p)->i_uid )
        {
          if ( ++i_array_p > v13 )
            goto LABEL_8;
        }
        v9 = 89;
      }
      else
      {
LABEL_8:
        if ( name_p )
          name_p->i_uid = i_uid;
      }
    }
  }
  v14 = v9;
  if ( end_pos_p )
    *end_pos_p = find_pos_p;
  return v14;
}

// File Line: 8731
// RVA: 0x12E310
__int64 __fastcall SSParser::parse_name_method(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        ASymbol *name_p)
{
  __int64 v4; // rsi
  __int64 v5; // r10
  AStringRef *i_str_ref_p; // rdx
  unsigned int v10; // ebx
  char *i_cstr_p; // rcx
  unsigned __int8 v12; // r8
  unsigned __int8 v13; // cl
  __int64 v14; // rax
  ASymbol result; // [rsp+50h] [rbp+8h] BYREF
  unsigned int end_pos_pa; // [rsp+58h] [rbp+10h] BYREF

  v4 = start_pos;
  LODWORD(v5) = start_pos;
  i_str_ref_p = this->i_str_ref_p;
  end_pos_pa = v4;
  v10 = 82;
  if ( i_str_ref_p->i_length <= (unsigned int)v4 )
    goto LABEL_17;
  i_cstr_p = i_str_ref_p->i_cstr_p;
  v10 = 53;
  v12 = i_str_ref_p->i_cstr_p[v4];
  if ( v12 != 33 )
  {
    if ( AString::c_is_lowercase[v12] )
    {
      end_pos_pa = v4 + 1;
      end_pos_pa = i_str_ref_p->i_length;
      AString::find(this, ACharMatch_not_identifier, 1u, &end_pos_pa, v4 + 1, 0xFFFFFFFF);
      if ( name_p )
        name_p->i_uid = SSParser::as_symbol(this, &result, v4, end_pos_pa)->i_uid;
      v10 = 0;
    }
    else
    {
      if ( !AString::c_is_uppercase[v12] )
        goto LABEL_17;
      v10 = SSParser::parse_name_class(this, v4, &end_pos_pa, name_p, (SSParser::eClassCheck)((name_p != 0i64) + 2));
    }
    goto LABEL_16;
  }
  v5 = (unsigned int)(v4 + 1);
  v10 = 0;
  end_pos_pa = v4 + 1;
  v13 = i_cstr_p[v5];
  if ( v13 == 33 )
  {
    LODWORD(v5) = v4 + 2;
    if ( name_p )
      name_p->i_uid = ASymbolX_dtor.i_uid;
    goto LABEL_17;
  }
  if ( AString::c_is_lowercase[v13] )
  {
    end_pos_pa = v4 + 2;
    SSParser::parse_name_symbol(this, v4, &end_pos_pa, name_p);
LABEL_16:
    LODWORD(v5) = end_pos_pa;
    goto LABEL_17;
  }
  if ( name_p )
    name_p->i_uid = ASymbolX_ctor.i_uid;
LABEL_17:
  v14 = v10;
  if ( end_pos_p )
    *end_pos_p = v5;
  return v14;
}

// File Line: 8831
// RVA: 0x12E130
__int64 __fastcall SSParser::parse_name_coroutine(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        ASymbol *name_p)
{
  AStringRef *i_str_ref_p; // r8
  __int64 v6; // rbx
  unsigned int v9; // r11d
  __int64 v10; // r10
  char *i_cstr_p; // rdx
  __int64 v12; // rax
  ASymbol result; // [rsp+50h] [rbp+8h] BYREF
  unsigned int find_pos_p; // [rsp+58h] [rbp+10h] BYREF

  i_str_ref_p = this->i_str_ref_p;
  v6 = start_pos;
  find_pos_p = start_pos;
  v9 = 82;
  LODWORD(v10) = start_pos;
  if ( i_str_ref_p->i_length - start_pos >= 2 )
  {
    i_cstr_p = i_str_ref_p->i_cstr_p;
    v9 = 61;
    if ( i_str_ref_p->i_cstr_p[v6] == 95 )
    {
      v10 = (unsigned int)(v6 + 1);
      find_pos_p = v6 + 1;
      if ( AString::c_is_lowercase[(unsigned __int8)i_cstr_p[v10]] )
      {
        find_pos_p = v6 + 2;
        find_pos_p = i_str_ref_p->i_length;
        AString::find(this, ACharMatch_not_identifier, 1u, &find_pos_p, v6 + 2, 0xFFFFFFFF);
        if ( name_p )
          name_p->i_uid = SSParser::as_symbol(this, &result, v6, find_pos_p)->i_uid;
        LODWORD(v10) = find_pos_p;
        v9 = 0;
      }
    }
  }
  v12 = v9;
  if ( end_pos_p )
    *end_pos_p = v10;
  return v12;
}

// File Line: 8930
// RVA: 0x12F100
__int64 __fastcall SSParser::parse_parameter(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSParameterBase **param_new_pp)
{
  char *i_cstr_p; // rax
  unsigned int i_count; // edi
  SSParser::eResult v10; // r14d
  SSParameterBase *v11; // rax
  SSParameterBase *v12; // rdx
  SSClassDescBase **i_array_p; // rsi
  __int64 *v14; // rbx
  SSClassDescBase **v15; // rdi
  SSParameterBase *v16; // rdi
  SSUnaryParam *v17; // rax
  SSParameterBase *v18; // rax
  SSParser::eResult v19; // eax
  SSGroupParam gparam_p; // [rsp+28h] [rbp-28h] BYREF
  unsigned int end_pos_pa; // [rsp+A0h] [rbp+50h] BYREF
  SSUnaryParam *v23; // [rsp+A8h] [rbp+58h]

  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  if ( param_new_pp )
  {
    if ( i_cstr_p[start_pos] == 123 )
    {
      gparam_p.i_name = (ASymbol)ASymbol::get_null()->i_uid;
      gparam_p.vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable;
      i_count = 0;
      gparam_p.i_class_pattern.i_count = 0;
      gparam_p.i_class_pattern.i_array_p = 0i64;
      gparam_p.i_class_pattern.i_size = 0;
      v10 = SSParser::parse_parameter_group(this, start_pos, &end_pos_pa, &gparam_p);
      if ( v10 )
      {
        i_array_p = gparam_p.i_class_pattern.i_array_p;
        i_count = gparam_p.i_class_pattern.i_count;
      }
      else
      {
        v11 = (SSParameterBase *)AMemory::c_malloc_func(0x28ui64, "SSGroupParam");
        v12 = v11;
        v23 = (SSUnaryParam *)v11;
        if ( v11 )
        {
          v11->i_name.i_uid = gparam_p.i_name.i_uid;
          v11->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable;
          v11->vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable;
          LODWORD(v11[1].vfptr) = gparam_p.i_class_pattern.i_count;
          *(_QWORD *)&v11[1].i_name.i_uid = gparam_p.i_class_pattern.i_array_p;
          LODWORD(v11[2].vfptr) = gparam_p.i_class_pattern.i_size;
          gparam_p.i_class_pattern.i_count = 0;
          gparam_p.i_class_pattern.i_size = 0;
          i_array_p = 0i64;
          gparam_p.i_class_pattern.i_array_p = 0i64;
        }
        else
        {
          v12 = 0i64;
          i_array_p = gparam_p.i_class_pattern.i_array_p;
          i_count = gparam_p.i_class_pattern.i_count;
        }
        *param_new_pp = v12;
      }
      gparam_p.vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable;
      if ( i_count )
      {
        v14 = (__int64 *)i_array_p;
        v15 = &i_array_p[i_count];
        if ( i_array_p < v15 )
        {
          do
             SSClassDescBase::`vcall{16,{flat}}(*v14++);
          while ( v14 < (__int64 *)v15 );
        }
      }
      AMemory::c_free_func(i_array_p);
      gparam_p.vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable;
    }
    else
    {
      gparam_p.i_name = (ASymbol)ASymbol::get_null()->i_uid;
      gparam_p.vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable;
      *(_QWORD *)&gparam_p.i_class_pattern.i_count = SSBrain::c_object_class_p;
      if ( SSBrain::c_object_class_p )
        (*(void (__fastcall **)(SSClass *))SSBrain::c_object_class_p->vfptr->gap8)(SSBrain::c_object_class_p);
      v16 = 0i64;
      gparam_p.i_class_pattern.i_array_p = 0i64;
      v10 = SSParser::parse_parameter_unary(this, start_pos, &end_pos_pa, (SSUnaryParam *)&gparam_p);
      if ( v10 == Result_ok )
      {
        v17 = (SSUnaryParam *)AMemory::c_malloc_func(0x20ui64, "SSUnaryParam");
        v23 = v17;
        if ( v17 )
        {
          SSUnaryParam::SSUnaryParam(v17, (SSUnaryParam *)&gparam_p);
          v16 = v18;
        }
        *param_new_pp = v16;
      }
      gparam_p.vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable;
      if ( gparam_p.i_class_pattern.i_array_p )
        (**(void (__fastcall ***)(SSClassDescBase **, __int64))gparam_p.i_class_pattern.i_array_p)(
          gparam_p.i_class_pattern.i_array_p,
          1i64);
      if ( *(_QWORD *)&gparam_p.i_class_pattern.i_count )
        (*(void (__fastcall **)(_QWORD))(**(_QWORD **)&gparam_p.i_class_pattern.i_count + 16i64))(*(_QWORD *)&gparam_p.i_class_pattern.i_count);
      gparam_p.vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable;
    }
  }
  else
  {
    if ( i_cstr_p[start_pos] == 123 )
      v19 = SSParser::parse_parameter_group(this, start_pos, &end_pos_pa, 0i64);
    else
      v19 = SSParser::parse_parameter_unary(this, start_pos, &end_pos_pa, 0i64);
    v10 = v19;
  }
  if ( end_pos_p )
    *end_pos_p = end_pos_pa;
  return (unsigned int)v10;
}

// File Line: 8997
// RVA: 0x12F520
__int64 __fastcall SSParser::parse_parameter_specifier(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSTypedName *tname_p,
        char param_flags)
{
  SSClassDescBase **p_obj_p; // r9
  SSParser::eResult v10; // ebx
  SSClass *v11; // rax
  SSClassDescBase *obj_p; // [rsp+20h] [rbp-38h] BYREF
  unsigned int end_pos_pa; // [rsp+70h] [rbp+18h] BYREF
  ASymbol name_p; // [rsp+78h] [rbp+20h] BYREF

  p_obj_p = &obj_p;
  if ( !tname_p )
    p_obj_p = 0i64;
  obj_p = SSBrain::c_object_class_p;
  v10 = (unsigned int)SSParser::parse_class_desc(this, start_pos, &end_pos_pa, (SSMetaClass **)p_obj_p);
  if ( v10 == Result_ok )
  {
    v10 = SSParser::parse_ws_required(this, end_pos_pa, &end_pos_pa);
    goto LABEL_5;
  }
  if ( end_pos_pa != start_pos )
  {
LABEL_5:
    if ( v10 )
      goto LABEL_17;
    goto LABEL_6;
  }
  v11 = SSBrain::c_object_class_p;
  if ( (param_flags & 1) != 0 )
    v11 = SSBrain::c_auto_class_p;
  obj_p = v11;
LABEL_6:
  name_p.i_uid = -1;
  if ( (unsigned int)SSParser::parse_name_instance(this, end_pos_pa, &end_pos_pa, &name_p) )
  {
    v10 = Result_err_expected_param_name;
  }
  else if ( (this->i_flags.i_flagset & 1) != 0 && SSTypeContext::is_previous_variable(&this->i_context, &name_p) )
  {
    v10 = Result_err_context_duped_variable;
  }
  else
  {
    v10 = Result_ok;
    if ( tname_p )
    {
      ARefPtr<SSClassDescBase>::operator=(&tname_p->i_type_p, obj_p);
      tname_p->i_name = name_p;
    }
  }
LABEL_17:
  if ( end_pos_p )
    *end_pos_p = end_pos_pa;
  return (unsigned int)v10;
}

// File Line: 9094
// RVA: 0x12F630
__int64 __fastcall SSParser::parse_parameter_unary(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSUnaryParam *uparam_p)
{
  SSLiteralList *v7; // r12
  SSClassDescBase *i_obj_p; // rdi
  SSParser::eResult i_result; // ebx
  unsigned int v10; // esi
  unsigned int v11; // r15d
  unsigned int i_end_pos; // eax
  SSClassDescBase *v13; // rcx
  SSExpressionBase *i_default_p; // rcx
  ASymbol name_p; // [rsp+20h] [rbp-40h] BYREF
  unsigned int i_uid; // [rsp+24h] [rbp-3Ch]
  SSClassDescBase *type_pp[2]; // [rsp+28h] [rbp-38h] BYREF
  ASymbol v19; // [rsp+38h] [rbp-28h] BYREF
  ARefPtr<SSClassDescBase> v20; // [rsp+40h] [rbp-20h] BYREF
  SSParser::Args args; // [rsp+48h] [rbp-18h] BYREF
  unsigned int end_pos_pa; // [rsp+A8h] [rbp+48h] BYREF
  unsigned int *v23; // [rsp+B0h] [rbp+50h]

  v23 = end_pos_p;
  type_pp[1] = (SSClassDescBase *)-2i64;
  i_uid = ASymbol::get_null()->i_uid;
  v19.i_uid = i_uid;
  v7 = 0i64;
  i_obj_p = 0i64;
  v20.i_obj_p = 0i64;
  type_pp[0] = SSBrain::c_object_class_p;
  i_result = (unsigned int)SSParser::parse_class_desc(this, start_pos, &end_pos_pa, (SSMetaClass **)type_pp);
  if ( i_result )
  {
    v10 = end_pos_pa;
    if ( end_pos_pa == start_pos )
    {
      type_pp[0] = SSBrain::c_object_class_p;
      goto LABEL_6;
    }
  }
  else
  {
    i_result = SSParser::parse_ws_required(this, end_pos_pa, &end_pos_pa);
    v10 = end_pos_pa;
  }
  if ( i_result )
    goto LABEL_40;
LABEL_6:
  name_p.i_uid = -1;
  if ( (unsigned int)SSParser::parse_name_instance(this, v10, &end_pos_pa, &name_p) )
  {
    i_result = Result_err_expected_param_name;
  }
  else if ( (this->i_flags.i_flagset & 1) != 0 && SSTypeContext::is_previous_variable(&this->i_context, &name_p) )
  {
    i_result = Result_err_context_duped_variable;
  }
  else
  {
    i_result = Result_ok;
    ARefPtr<SSClassDescBase>::operator=(&v20, type_pp[0]);
    i_uid = name_p.i_uid;
    v19.i_uid = name_p.i_uid;
    i_obj_p = v20.i_obj_p;
  }
  v10 = end_pos_pa;
  if ( i_result )
    goto LABEL_40;
  SSParser::parse_ws_any(this, end_pos_pa, &end_pos_pa);
  v11 = end_pos_pa;
  args.i_start_pos = end_pos_pa;
  args.i_flags = uparam_p != 0i64;
  *(_QWORD *)&args.i_result = 0i64;
  args.i_type_p = 0i64;
  if ( this->i_str_ref_p->i_length <= end_pos_pa || this->i_str_ref_p->i_cstr_p[end_pos_pa] != 58 )
  {
    args.i_result = Result_err_expected_binding;
    args.i_end_pos = end_pos_pa;
LABEL_27:
    i_result = Result_ok;
    goto LABEL_28;
  }
  i_result = SSParser::parse_ws_any(this, end_pos_pa + 1, &end_pos_pa);
  args.i_result = i_result;
  i_end_pos = end_pos_pa;
  if ( i_result )
  {
    args.i_end_pos = end_pos_pa;
  }
  else
  {
    args.i_start_pos = end_pos_pa;
    v7 = SSParser::parse_expression(this, &args, 3ui64);
    i_end_pos = args.i_end_pos;
    i_result = args.i_result;
  }
  if ( i_end_pos == v11 )
    goto LABEL_27;
  v10 = i_end_pos;
  if ( (this->i_flags.i_flagset & 1) != 0 )
  {
    if ( i_result )
      goto LABEL_40;
    if ( !args.i_type_p->vfptr->is_class_type(args.i_type_p, i_obj_p) )
    {
      i_result = Result_err_typecheck_default_param;
      if ( v7 )
        v7->vfptr->__vecDelDtor(v7, 1u);
      goto LABEL_40;
    }
  }
  else if ( i_result )
  {
    goto LABEL_40;
  }
LABEL_28:
  if ( uparam_p )
  {
    uparam_p->i_name.i_uid = i_uid;
    if ( uparam_p->i_type_p.i_obj_p != i_obj_p )
    {
      if ( i_obj_p )
        (*(void (__fastcall **)(SSClassDescBase *))i_obj_p->vfptr->gap8)(i_obj_p);
      v13 = uparam_p->i_type_p.i_obj_p;
      if ( v13 )
        (*(void (__fastcall **)(SSClassDescBase *))&v13->vfptr->gap8[8])(v13);
      uparam_p->i_type_p.i_obj_p = i_obj_p;
    }
    i_default_p = uparam_p->i_default_p;
    if ( i_default_p )
      i_default_p->vfptr->__vecDelDtor(i_default_p, 1u);
    uparam_p->i_default_p = v7;
  }
  if ( (this->i_flags.i_flagset & 1) != 0 )
    SSTypeContext::append_local(&this->i_context, &v19, i_obj_p);
LABEL_40:
  if ( v23 )
    *v23 = v10;
  if ( i_obj_p )
    (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
  return (unsigned int)i_result;
}

// File Line: 9178
// RVA: 0x12F340
__int64 __fastcall SSParser::parse_parameter_group(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSGroupParam *gparam_p)
{
  char *i_cstr_p; // r12
  unsigned int i_length; // r15d
  unsigned int v9; // ebx
  SSClassUnaryBase *merge; // rdi
  int v11; // ebp
  SSClassDescBase *v12; // rbx
  SSClass *v13; // rdx
  SSTypedClass *v14; // rax
  __int64 result; // rax
  SSClassDescBase *type_pp; // [rsp+60h] [rbp+8h] BYREF
  unsigned int end_pos_pa; // [rsp+68h] [rbp+10h] BYREF

  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  i_length = this->i_str_ref_p->i_length;
  v9 = 82;
  if ( i_length - start_pos >= 2 )
  {
    v9 = 31;
    if ( i_cstr_p[start_pos] == 123 )
    {
      ++start_pos;
      merge = 0i64;
      v11 = 0;
      end_pos_pa = start_pos;
      if ( start_pos < i_length )
      {
        while ( 1 )
        {
          SSParser::parse_ws_any(this, start_pos, &end_pos_pa);
          if ( i_cstr_p[end_pos_pa] == 125 )
            break;
          if ( (unsigned int)SSParser::parse_class_desc(this, end_pos_pa, &end_pos_pa, (SSMetaClass **)&type_pp) )
          {
            v9 = 75;
            goto LABEL_29;
          }
          if ( (unsigned int)++v11 > 0x3F )
          {
            v9 = 92;
LABEL_29:
            start_pos = end_pos_pa;
            goto LABEL_30;
          }
          v12 = type_pp;
          if ( (this->i_flags.i_flagset & 1) != 0 )
          {
            if ( merge )
              merge = SSClassUnion::get_merge((SSClassUnion *)merge, (SSClassUnion *)type_pp);
            else
              merge = (SSClassUnaryBase *)type_pp;
          }
          if ( gparam_p )
          {
            (*(void (__fastcall **)(SSClassDescBase *))v12->vfptr->gap8)(v12);
            APArray<SSClassDescBase,SSClassDescBase,ACompareAddress<SSClassDescBase>>::append(
              &gparam_p->i_class_pattern,
              v12);
          }
          start_pos = end_pos_pa;
          if ( end_pos_pa >= i_length )
            goto LABEL_18;
        }
        start_pos = ++end_pos_pa;
LABEL_18:
        SSParser::parse_ws_any(this, start_pos, &end_pos_pa);
        LODWORD(type_pp) = -1;
        if ( (unsigned int)SSParser::parse_name_instance(this, end_pos_pa, &end_pos_pa, (ASymbol *)&type_pp) )
        {
          v9 = 58;
          goto LABEL_29;
        }
        if ( (this->i_flags.i_flagset & 1) != 0
          && SSTypeContext::is_previous_variable(&this->i_context, (ASymbol *)&type_pp) )
        {
          v9 = 104;
          goto LABEL_29;
        }
        v9 = 0;
        if ( (this->i_flags.i_flagset & 1) != 0 )
        {
          v13 = SSBrain::c_object_class_p;
          if ( merge )
            v13 = (SSClass *)merge;
          v14 = SSTypedClass::get_or_create(SSBrain::c_list_class_p, v13);
          SSTypeContext::append_local(&this->i_context, (ASymbol *)&type_pp, v14);
        }
        start_pos = end_pos_pa;
        if ( gparam_p )
          gparam_p->i_name.i_uid = (unsigned int)type_pp;
      }
    }
  }
LABEL_30:
  result = v9;
  if ( end_pos_p )
    *end_pos_p = start_pos;
  return result;
}

// File Line: 9359
// RVA: 0x12F8C0
__int64 __fastcall SSParser::parse_parameters(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSParameters *params_p,
        char flags)
{
  SSClassDescBase **i_str_ref_p; // rax
  unsigned int i_length; // ecx
  unsigned int v11; // ebx
  char v12; // bp
  char v13; // si
  SSParser::eResult (__fastcall *v14)(SSParser *, unsigned int, unsigned int *, SSParameters *); // r13
  SSParser::eResult v15; // edi
  int v16; // eax
  char v17; // bp
  unsigned int v18; // esi
  SSClass *v19; // rdx
  unsigned int start_posa; // [rsp+30h] [rbp-48h] BYREF
  unsigned int v21; // [rsp+34h] [rbp-44h]
  SSClassDescBase *type_pp; // [rsp+38h] [rbp-40h] BYREF
  unsigned int v23; // [rsp+80h] [rbp+8h] BYREF
  unsigned int end_pos_pa; // [rsp+88h] [rbp+10h] BYREF

  end_pos_pa = start_pos;
  i_str_ref_p = (SSClassDescBase **)this->i_str_ref_p;
  i_length = this->i_str_ref_p->i_length;
  v21 = i_length;
  if ( i_length < start_pos )
  {
    if ( end_pos_p )
      *end_pos_p = start_pos;
    return 82i64;
  }
  type_pp = *i_str_ref_p;
  if ( *((_BYTE *)&type_pp->vfptr + start_pos) != 40 )
  {
    if ( end_pos_p )
      *end_pos_p = start_pos;
    return 57i64;
  }
  v11 = start_pos + 1;
  v12 = 0;
  v13 = 0;
  v14 = SSParser::parse_param_append;
  if ( (this->i_flags.i_flagset & 4) != 0 )
    v14 = (SSParser::eResult (__fastcall *)(SSParser *, unsigned int, unsigned int *, SSParameters *))SSParser::preparse_param_append;
  end_pos_pa = start_pos + 1;
  LOBYTE(v23) = 1;
  v15 = Result_err_unexpected_eof;
  start_posa = 0;
  if ( v11 < i_length )
  {
    while ( 1 )
    {
      v15 = SSParser::parse_ws_any(this, v11, &end_pos_pa);
      if ( v15 )
        goto LABEL_41;
      v11 = end_pos_pa;
      v16 = *((unsigned __int8 *)&type_pp->vfptr + end_pos_pa);
      if ( (_BYTE)v16 == 41 )
        break;
      if ( (_BYTE)v16 == 59 )
      {
        if ( v13 )
          goto LABEL_28;
        if ( !(_BYTE)v23 )
          goto LABEL_33;
        v11 = end_pos_pa + 1;
        v14 = (SSParser::eResult (__fastcall *)(SSParser *, unsigned int, unsigned int *, SSParameters *))SSParser::parse_param_return_append;
        LOBYTE(v23) = 0;
        v12 = 0;
        start_posa = 1;
        ++end_pos_pa;
      }
      else if ( (_BYTE)v16 == 44 )
      {
        if ( v13 || !v12 )
          goto LABEL_28;
        v11 = end_pos_pa + 1;
        v13 = 1;
        ++end_pos_pa;
      }
      else
      {
        v15 = ((unsigned int (__fastcall *)(SSParser *, _QWORD, unsigned int *, SSParameters *, unsigned int))v14)(
                this,
                end_pos_pa,
                &end_pos_pa,
                params_p,
                start_posa);
        if ( v15 )
          goto LABEL_41;
        v11 = end_pos_pa;
        v13 = 0;
        v12 = 1;
        v15 = Result_err_unexpected_eof;
      }
      if ( v11 >= v21 )
      {
        if ( v15 )
          goto LABEL_42;
        goto LABEL_30;
      }
    }
    if ( v13 )
    {
LABEL_28:
      v15 = Result_err_unexpected_parameter;
      goto LABEL_42;
    }
    v11 = ++end_pos_pa;
LABEL_30:
    SSParser::parse_ws_any(this, v11, &start_posa);
    v17 = flags;
    if ( (flags & 2) != 0 )
    {
      v11 = start_posa;
      SSParser::parse_class_desc(this, start_posa, &v23, 0i64);
      if ( v11 != v23 )
      {
LABEL_33:
        v15 = Result_err_unexpected_parameter_return;
        goto LABEL_42;
      }
      SSParameters::set_result_type(params_p, SSBrain::c_none_class_p);
      v15 = Result_ok;
      goto LABEL_41;
    }
    v18 = start_posa;
    v15 = (unsigned int)SSParser::parse_class_desc(this, start_posa, &v23, (SSMetaClass **)&type_pp);
    if ( v15 == Result_ok )
    {
      SSParameters::set_result_type(params_p, type_pp);
      v11 = v23;
      goto LABEL_42;
    }
    v11 = v23;
    if ( v18 == v23 )
    {
      v15 = Result_ok;
      if ( params_p )
      {
        v19 = SSBrain::c_object_class_p;
        if ( (v17 & 1) != 0 )
          v19 = SSBrain::c_auto_class_p;
        SSParameters::set_result_type(params_p, v19);
      }
LABEL_41:
      v11 = end_pos_pa;
    }
  }
LABEL_42:
  if ( end_pos_p )
    *end_pos_p = v11;
  return (unsigned int)v15;
}

// File Line: 9861
// RVA: 0x12FDD0
bool __fastcall SSParser::parse_temporary(
        SSParser *this,
        SSParser::Args *args,
        ASymbol *ident_p,
        SSExpressionBase **expr_pp)
{
  __int64 i_start_pos; // rbp
  char *i_cstr_p; // rbx
  __int64 v10; // rsi
  char v11; // cl
  SSParser::eResult v12; // eax
  SSParser::eResult v13; // eax
  unsigned int v14; // ebx
  SSExpressionBase *v15; // rax
  bool v16; // zf
  unsigned int end_pos_p; // [rsp+50h] [rbp+8h] BYREF

  i_start_pos = args->i_start_pos;
  args->i_result = Result_err_unexpected_eof;
  if ( (unsigned int)(this->i_str_ref_p->i_length - i_start_pos) >= 2 )
  {
    i_cstr_p = this->i_str_ref_p->i_cstr_p;
    args->i_result = Result_err_expected_temporary;
    if ( i_cstr_p[i_start_pos] == 33 )
    {
      v10 = (unsigned int)(i_start_pos + 1);
      args->i_result = Result_err_unexpected_cdtor;
      v11 = i_cstr_p[v10];
      end_pos_p = i_start_pos + 1;
      if ( v11 != 40 && v11 != 33 )
      {
        v12 = SSParser::parse_ws_any(this, v10, &end_pos_p);
        args->i_result = v12;
        if ( v12
          || (v13 = (unsigned int)SSParser::parse_name_instance(this, end_pos_p, &end_pos_p, ident_p),
              (args->i_result = v13) != Result_ok) )
        {
          LODWORD(v10) = end_pos_p;
        }
        else
        {
          v10 = end_pos_p;
          args->i_result = Result_err_unexpected_cdtor;
          if ( i_cstr_p[v10] != 40 )
          {
            if ( (this->i_flags.i_flagset & 1) != 0
              && ident_p
              && SSTypeContext::is_previous_variable(&this->i_context, ident_p) )
            {
              args->i_result = Result_err_context_duped_variable;
            }
            else if ( SSParser::parse_ws_any(this, v10, &end_pos_p)
                   || (v14 = end_pos_p,
                       args->i_start_pos = end_pos_p,
                       v15 = SSParser::parse_binding(this, args),
                       args->i_end_pos == v14) )
            {
              args->i_result = Result_ok;
              args->i_type_p = SSBrain::c_none_class_p;
            }
            else
            {
              LODWORD(v10) = args->i_end_pos;
              if ( expr_pp )
                *expr_pp = v15;
            }
          }
        }
      }
      if ( args->i_result == Result_err_unexpected_cdtor )
        LODWORD(v10) = i_start_pos;
      LODWORD(i_start_pos) = v10;
    }
  }
  v16 = args->i_result == Result_ok;
  args->i_end_pos = i_start_pos;
  return v16;
}

// File Line: 10028
// RVA: 0x130090
__int64 __fastcall SSParser::parse_ws_any(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p)
{
  unsigned int i_length; // esi
  unsigned int v5; // ebx
  unsigned int v7; // edi
  unsigned int v8; // edx
  char *i_cstr_p; // r8
  char *v10; // rax
  unsigned __int64 i; // rdx
  __int64 v12; // rdx
  __int64 result; // rax
  unsigned int find_pos_p; // [rsp+58h] [rbp+10h] BYREF

  i_length = this->i_str_ref_p->i_length;
  v5 = start_pos;
  v7 = 0;
  if ( start_pos < i_length )
  {
    while ( v5 < i_length )
    {
      find_pos_p = i_length;
      AString::find(this, ACharMatch_not_white_space, 1u, &find_pos_p, v5, 0xFFFFFFFF);
      v5 = find_pos_p;
      if ( find_pos_p >= i_length )
        break;
      v8 = this->i_str_ref_p->i_length;
      i_cstr_p = this->i_str_ref_p->i_cstr_p;
      v10 = &i_cstr_p[find_pos_p];
      if ( find_pos_p + 2 <= v8 && *v10 == 47 && (++v10, *v10 == 47) )
      {
        for ( i = (unsigned __int64)&i_cstr_p[v8 - 1]; (unsigned __int64)v10 <= i; ++v10 )
        {
          if ( *v10 == 10 )
            break;
        }
        v7 = 0;
        v5 = (_DWORD)v10 - (_DWORD)i_cstr_p + 1;
      }
      else
      {
        v12 = find_pos_p;
        find_pos_p = (_DWORD)v10 - (_DWORD)i_cstr_p;
        v7 = SSParser::parse_comment_multiline(this, v12, &find_pos_p);
        if ( v7 )
          break;
        v5 = find_pos_p;
      }
    }
    if ( v7 != 26 )
      v7 = 0;
  }
  result = v7;
  if ( end_pos_p )
    *end_pos_p = v5;
  return result;
}

// File Line: 10119
// RVA: 0x130190
__int64 __fastcall SSParser::parse_ws_required(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p)
{
  unsigned int v6; // ebx
  AStringRef *i_str_ref_p; // rax
  unsigned int i_length; // edx
  char *i_cstr_p; // r8
  char *v10; // rcx
  unsigned __int64 i; // rdx
  __int64 result; // rax
  AStringRef *v13; // rax
  AStringRef *v14; // rax
  unsigned int v15; // edx
  char *v16; // r8
  char *v17; // rax
  unsigned __int64 j; // rdx
  __int64 v19; // rdx
  unsigned int start_posa; // [rsp+20h] [rbp-28h]
  unsigned int end_pos_pa; // [rsp+50h] [rbp+8h] BYREF
  unsigned int find_pos_p; // [rsp+60h] [rbp+18h] BYREF

  find_pos_p = this->i_str_ref_p->i_length;
  AString::find(this, ACharMatch_not_white_space, 1u, &find_pos_p, start_pos, 0xFFFFFFFF);
  v6 = find_pos_p;
  i_str_ref_p = this->i_str_ref_p;
  end_pos_pa = find_pos_p;
  i_length = i_str_ref_p->i_length;
  i_cstr_p = i_str_ref_p->i_cstr_p;
  v10 = &i_str_ref_p->i_cstr_p[find_pos_p];
  if ( find_pos_p + 2 <= i_length && *v10 == 47 && *++v10 == 47 )
  {
    for ( i = (unsigned __int64)&i_cstr_p[i_length - 1]; (unsigned __int64)v10 <= i; ++v10 )
    {
      if ( *v10 == 10 )
        break;
    }
    end_pos_pa = (_DWORD)v10 - (_DWORD)i_cstr_p + 1;
    goto LABEL_9;
  }
  end_pos_pa = (_DWORD)v10 - (_DWORD)i_cstr_p;
  result = SSParser::parse_comment_multiline(this, find_pos_p, &end_pos_pa);
  if ( !(_DWORD)result )
  {
    do
    {
LABEL_9:
      while ( 1 )
      {
        v13 = this->i_str_ref_p;
        find_pos_p = end_pos_pa;
        start_posa = end_pos_pa;
        end_pos_pa = v13->i_length;
        AString::find(this, ACharMatch_not_white_space, 1u, &end_pos_pa, start_posa, 0xFFFFFFFF);
        v6 = end_pos_pa;
        v14 = this->i_str_ref_p;
        find_pos_p = end_pos_pa;
        v15 = v14->i_length;
        v16 = v14->i_cstr_p;
        v17 = &v14->i_cstr_p[end_pos_pa];
        if ( end_pos_pa + 2 > v15 )
          break;
        if ( *v17 != 47 )
          break;
        if ( *++v17 != 47 )
          break;
        for ( j = (unsigned __int64)&v16[v15 - 1]; (unsigned __int64)v17 <= j; ++v17 )
        {
          if ( *v17 == 10 )
            break;
        }
        end_pos_pa = (_DWORD)v17 - (_DWORD)v16 + 1;
      }
      v19 = end_pos_pa;
      end_pos_pa = (_DWORD)v17 - (_DWORD)v16;
    }
    while ( !(unsigned int)SSParser::parse_comment_multiline(this, v19, &end_pos_pa) );
    goto LABEL_17;
  }
  if ( (_DWORD)result == 26 )
  {
    v6 = end_pos_pa;
    goto LABEL_19;
  }
LABEL_17:
  result = 68i64;
  if ( v6 != start_pos )
    result = 0i64;
LABEL_19:
  if ( end_pos_p )
    *end_pos_p = v6;
  return result;
}

// File Line: 10299
// RVA: 0x131480
__int64 __fastcall SSParser::preparse_parameter_unary(
        SSParser *this,
        SSUnaryParam *uparam_p,
        unsigned int start_pos,
        unsigned int *end_pos_p)
{
  SSExpressionBase *v7; // r14
  SSClassDescBase *i_obj_p; // rdi
  SSParser::eResult i_result; // ebx
  unsigned int v10; // esi
  unsigned int v11; // r13d
  unsigned int i_end_pos; // eax
  SSClassDescBase *v13; // rax
  SSClassDescBase *v14; // rcx
  SSExpressionBase *i_default_p; // rcx
  ASymbol name_p; // [rsp+20h] [rbp-40h] BYREF
  unsigned int i_uid; // [rsp+24h] [rbp-3Ch]
  SSClassDescBase *type_pp[2]; // [rsp+28h] [rbp-38h] BYREF
  unsigned int v20; // [rsp+38h] [rbp-28h]
  ARefPtr<SSClassDescBase> v21; // [rsp+40h] [rbp-20h] BYREF
  SSParser::Args args; // [rsp+48h] [rbp-18h] BYREF
  unsigned int end_pos_pa; // [rsp+B0h] [rbp+50h] BYREF
  unsigned int *v24; // [rsp+B8h] [rbp+58h]

  v24 = end_pos_p;
  type_pp[1] = (SSClassDescBase *)-2i64;
  i_uid = ASymbol::get_null()->i_uid;
  v20 = i_uid;
  v7 = 0i64;
  i_obj_p = 0i64;
  v21.i_obj_p = 0i64;
  type_pp[0] = SSBrain::c_object_class_p;
  i_result = (unsigned int)SSParser::parse_class_desc(this, start_pos, &end_pos_pa, (SSMetaClass **)type_pp);
  if ( i_result )
  {
    v10 = end_pos_pa;
    if ( end_pos_pa == start_pos )
    {
      type_pp[0] = SSBrain::c_object_class_p;
      goto LABEL_6;
    }
  }
  else
  {
    i_result = (unsigned int)SSParser::parse_ws_required(this, end_pos_pa, &end_pos_pa);
    v10 = end_pos_pa;
  }
  if ( i_result )
    goto LABEL_34;
LABEL_6:
  name_p.i_uid = -1;
  if ( (unsigned int)SSParser::parse_name_instance(this, v10, &end_pos_pa, &name_p) )
  {
    i_result = Result_err_expected_param_name;
  }
  else if ( (this->i_flags.i_flagset & 1) != 0 && SSTypeContext::is_previous_variable(&this->i_context, &name_p) )
  {
    i_result = Result_err_context_duped_variable;
  }
  else
  {
    i_result = Result_ok;
    ARefPtr<SSClassDescBase>::operator=(&v21, type_pp[0]);
    i_uid = name_p.i_uid;
    v20 = name_p.i_uid;
    i_obj_p = v21.i_obj_p;
  }
  v10 = end_pos_pa;
  if ( i_result )
    goto LABEL_34;
  SSParser::parse_ws_any(this, end_pos_pa, &end_pos_pa);
  v11 = end_pos_pa;
  args.i_start_pos = end_pos_pa;
  memset(&args.i_flags, 0, 20);
  if ( this->i_str_ref_p->i_length > end_pos_pa && this->i_str_ref_p->i_cstr_p[end_pos_pa] == 58 )
  {
    i_result = (unsigned int)SSParser::parse_ws_any(this, end_pos_pa + 1, &end_pos_pa);
    args.i_result = i_result;
    i_end_pos = end_pos_pa;
    if ( i_result )
    {
      args.i_end_pos = end_pos_pa;
    }
    else
    {
      args.i_start_pos = end_pos_pa;
      SSParser::parse_expression(this, &args, 3ui64);
      i_end_pos = args.i_end_pos;
      i_result = args.i_result;
    }
    if ( i_end_pos != v11 )
    {
      v10 = i_end_pos;
      if ( i_result == Result_ok )
      {
        v13 = (SSClassDescBase *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
        type_pp[0] = v13;
        if ( v13 )
        {
          v13->vfptr = (SSClassDescBaseVtbl *)&SSExpressionBase::`vftable;
          v13->vfptr = (SSClassDescBaseVtbl *)&SSLiteral::`vftable;
          v13[1].vfptr = 0i64;
          LODWORD(v13[2].vfptr) = 7;
          v7 = (SSExpressionBase *)v13;
        }
      }
      goto LABEL_25;
    }
  }
  else
  {
    args.i_result = Result_err_expected_binding;
    args.i_end_pos = end_pos_pa;
  }
  i_result = Result_ok;
LABEL_25:
  uparam_p->i_name.i_uid = i_uid;
  if ( uparam_p->i_type_p.i_obj_p != i_obj_p )
  {
    if ( i_obj_p )
      (*(void (__fastcall **)(SSClassDescBase *))i_obj_p->vfptr->gap8)(i_obj_p);
    v14 = uparam_p->i_type_p.i_obj_p;
    if ( v14 )
      (*(void (__fastcall **)(SSClassDescBase *))&v14->vfptr->gap8[8])(v14);
    uparam_p->i_type_p.i_obj_p = i_obj_p;
  }
  i_default_p = uparam_p->i_default_p;
  if ( i_default_p )
    i_default_p->vfptr->__vecDelDtor(i_default_p, 1u);
  uparam_p->i_default_p = v7;
LABEL_34:
  if ( v24 )
    *v24 = v10;
  if ( i_obj_p )
    (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
  return (unsigned int)i_result;
} if ( i_obj_p

// File Line: 10371
// RVA: 0x131280
__int64 __fastcall SSParser::preparse_parameter(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSParameterBase **param_new_pp)
{
  unsigned int i_count; // edi
  SSParser::eResult v9; // r14d
  SSUnaryParam *v10; // rax
  SSParameterBase *v11; // rax
  unsigned int v12; // eax
  SSParameterBase *v13; // rax
  SSParameterBase *v14; // rdx
  SSClassDescBase **i_array_p; // rsi
  __int64 *v16; // rbx
  SSClassDescBase **v17; // rdi
  SSUnaryParam uparam_p; // [rsp+28h] [rbp-48h] BYREF
  SSGroupParam gparam_p; // [rsp+48h] [rbp-28h] BYREF
  unsigned int end_pos_pa; // [rsp+B8h] [rbp+48h] BYREF
  SSUnaryParam *v22; // [rsp+C0h] [rbp+50h]

  uparam_p.i_name = (ASymbol)ASymbol::get_null()->i_uid;
  uparam_p.vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable;
  uparam_p.i_type_p.i_obj_p = SSBrain::c_object_class_p;
  if ( SSBrain::c_object_class_p )
    (*(void (__fastcall **)(SSClass *))SSBrain::c_object_class_p->vfptr->gap8)(SSBrain::c_object_class_p);
  i_count = 0;
  uparam_p.i_default_p = 0i64;
  v9 = SSParser::preparse_parameter_unary(this, &uparam_p, start_pos, &end_pos_pa);
  if ( v9 == Result_ok )
  {
    v10 = (SSUnaryParam *)AMemory::c_malloc_func(0x20ui64, "SSUnaryParam");
    v22 = v10;
    if ( v10 )
      SSUnaryParam::SSUnaryParam(v10, &uparam_p);
    else
      v11 = 0i64;
    *param_new_pp = v11;
  }
  v12 = end_pos_pa;
  if ( end_pos_pa == start_pos )
  {
    gparam_p.i_name = (ASymbol)ASymbol::get_null()->i_uid;
    gparam_p.vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable;
    gparam_p.i_class_pattern.i_count = 0;
    gparam_p.i_class_pattern.i_array_p = 0i64;
    gparam_p.i_class_pattern.i_size = 0;
    v9 = (unsigned int)SSParser::parse_parameter_group(this, start_pos, &end_pos_pa, &gparam_p);
    if ( v9 )
    {
      i_array_p = gparam_p.i_class_pattern.i_array_p;
      i_count = gparam_p.i_class_pattern.i_count;
    }
    else
    {
      v13 = (SSParameterBase *)AMemory::c_malloc_func(0x28ui64, "SSGroupParam");
      v14 = v13;
      v22 = (SSUnaryParam *)v13;
      if ( v13 )
      {
        v13->i_name.i_uid = gparam_p.i_name.i_uid;
        v13->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable;
        v13->vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable;
        LODWORD(v13[1].vfptr) = gparam_p.i_class_pattern.i_count;
        *(_QWORD *)&v13[1].i_name.i_uid = gparam_p.i_class_pattern.i_array_p;
        LODWORD(v13[2].vfptr) = gparam_p.i_class_pattern.i_size;
        gparam_p.i_class_pattern.i_count = 0;
        gparam_p.i_class_pattern.i_size = 0;
        i_array_p = 0i64;
        gparam_p.i_class_pattern.i_array_p = 0i64;
      }
      else
      {
        v14 = 0i64;
        i_array_p = gparam_p.i_class_pattern.i_array_p;
        i_count = gparam_p.i_class_pattern.i_count;
      }
      *param_new_pp = v14;
    }
    gparam_p.vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable;
    if ( i_count )
    {
      v16 = (__int64 *)i_array_p;
      v17 = &i_array_p[i_count];
      if ( i_array_p < v17 )
      {
        do
           SSClassDescBase::`vcall{16,{flat}}(*v16++);
        while ( v16 < (__int64 *)v17 );
      }
    }
    AMemory::c_free_func(i_array_p);
    gparam_p.vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable;
    v12 = end_pos_pa;
  }
  if ( end_pos_p )
    *end_pos_p = v12;
  uparam_p.vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable;
  if ( uparam_p.i_default_p )
    uparam_p.i_default_p->vfptr->__vecDelDtor(uparam_p.i_default_p, 1u);
  if ( uparam_p.i_type_p.i_obj_p )
    (*(void (__fastcall **)(SSClassDescBase *))&uparam_p.i_type_p.i_obj_p->vfptr->gap8[8])(uparam_p.i_type_p.i_obj_p);
  return (unsigned int)v9;
}

// File Line: 10438
// RVA: 0x1311F0
SSParser::eResult __fastcall SSParser::preparse_param_append(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSParameters *params_p)
{
  SSParameterBase **p_elem; // r9
  SSParser::eResult result; // eax
  SSParser::eResult v7; // edi
  unsigned int i_count; // edx
  SSParameterBase **i_array_p; // rcx
  SSParameterBase **v10; // r8
  SSParameterBase *elem; // [rsp+48h] [rbp+20h] BYREF

  p_elem = &elem;
  elem = 0i64;
  if ( !params_p )
    p_elem = 0i64;
  result = SSParser::preparse_parameter(this, start_pos, end_pos_p, p_elem);
  v7 = result;
  if ( elem )
  {
    i_count = params_p->i_params.i_count;
    if ( i_count && (i_array_p = params_p->i_params.i_array_p, v10 = &i_array_p[i_count - 1], i_array_p <= v10) )
    {
      while ( elem->i_name.i_uid != (*i_array_p)->i_name.i_uid )
      {
        if ( ++i_array_p > v10 )
          goto LABEL_8;
      }
    }
    else
    {
LABEL_8:
      APCompactArray<SSParameterBase,ASymbol,ACompareLogical<ASymbol>>::append(&params_p->i_params, elem);
    }
    return v7;
  }
  return result;
}

// File Line: 11080
// RVA: 0x114160
char __fastcall SSParser::ensure_exec_time(
        SSParser *this,
        SSExpressionBase *expr,
        SSParser::Args *args,
        eSSInvokeTime desired_exec_time)
{
  unsigned int v8; // eax
  unsigned int v9; // [rsp+48h] [rbp+20h] BYREF

  if ( desired_exec_time != SSInvokeTime_any )
  {
    if ( expr->vfptr->is_immediate(expr, &v9) )
    {
      if ( desired_exec_time == SSInvokeTime_durational )
      {
        args->i_result = Result_err_context_deferred;
        return 0;
      }
    }
    else if ( desired_exec_time == SSInvokeTime_immediate && this->i_str_ref_p->i_cstr_p[args->i_end_pos] != 37 )
    {
      v8 = v9;
      args->i_result = Result_err_context_immediate;
      args->i_start_pos = v8;
      args->i_end_pos = v8 + 4;
      return 0;
    }
  }
  return 1;
}

// File Line: 11140
// RVA: 0x119120
AString *__fastcall SSParser::get_result_context_string(
        AString *result,
        AString *code,
        SSParser::eResult a3,
        unsigned int result_pos,
        unsigned int result_start,
        unsigned int start_pos)
{
  unsigned int end_pos; // edi
  unsigned int v10; // esi
  unsigned int i_length; // ecx
  unsigned int v12; // r12d
  const char *v13; // rdx
  AString *result_string; // rax
  AStringRef *i_str_ref_p; // r14
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v20; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  __int64 v22; // r14
  __int64 v23; // rbp
  bool v24; // bp
  unsigned int v25; // r13d
  unsigned int v26; // ecx
  __int64 v27; // rbp
  unsigned int v28; // edi
  unsigned int v29; // eax
  unsigned int v30; // r14d
  AStringRef *v31; // rax
  __int64 v32; // rbp
  __int64 v33; // rbp
  unsigned int v34; // r12d
  __int64 v35; // rbp
  __int64 v36; // rdi
  unsigned int v37; // edx
  __int64 v38; // r8
  __int64 v39; // rsi
  __int64 v40; // rdi
  __int64 v42; // [rsp+20h] [rbp-78h]
  AString resulta; // [rsp+38h] [rbp-60h] BYREF
  __int64 v44; // [rsp+40h] [rbp-58h]
  unsigned int v45; // [rsp+A8h] [rbp+10h] BYREF
  unsigned int last_counted_p; // [rsp+B0h] [rbp+18h] BYREF
  unsigned int find_pos_p; // [rsp+B8h] [rbp+20h] BYREF

  v44 = -2i64;
  end_pos = result_pos;
  v10 = 0;
  i_length = code->i_str_ref_p->i_length;
  find_pos_p = i_length;
  if ( result_pos >= i_length )
    end_pos = i_length - 1;
  v12 = result_start;
  if ( result_start > end_pos )
    v12 = end_pos;
  if ( AString::find_reverse(code, 10, 4u, &start_pos, start_pos, end_pos) && start_pos )
    ++start_pos;
  AString::find(code, 10, 4u, &find_pos_p, end_pos, 0xFFFFFFFF);
  AString::AString(result, 0i64, 0x400u, 0, 0);
  if ( a3 )
  {
    v13 = "ERROR: ";
    if ( a3 < Result_err__start )
      v13 = "WARNING: ";
  }
  else
  {
    v13 = "INFO: ";
  }
  AString::append(result, v13, 0xFFFFFFFF);
  result_string = SSParser::get_result_string(&resulta, a3);
  AString::append(result, result_string);
  i_str_ref_p = resulta.i_str_ref_p;
  if ( resulta.i_str_ref_p->i_ref_count-- == 1 )
  {
    if ( i_str_ref_p->i_deallocate )
      AMemory::c_free_func(i_str_ref_p->i_cstr_p);
    pool = AStringRef::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)i_str_ref_p < i_objects_a
      || (v20 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
          p_i_exp_pool = &pool->i_pool,
          !v20) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
  }
  AString::append(result, "\n", 0xFFFFFFFF);
  v22 = result->i_str_ref_p->i_length;
  v23 = (unsigned int)(v22 + 90);
  if ( (unsigned int)v23 >= result->i_str_ref_p->i_size
    || result->i_str_ref_p->i_ref_count + result->i_str_ref_p->i_read_only != 1 )
  {
    AString::set_size(result, v23);
  }
  memset(&result->i_str_ref_p->i_cstr_p[v22], 118, 0x5Aui64);
  result->i_str_ref_p->i_cstr_p[v23] = 0;
  result->i_str_ref_p->i_length = v23;
  AString::append(result, "\n", 0xFFFFFFFF);
  AString::append(result, &code->i_str_ref_p->i_cstr_p[start_pos], end_pos - start_pos);
  v45 = find_pos_p - 1;
  v24 = AString::find(code, 10, 1u, &v45, end_pos, 0xFFFFFFFF);
  LOBYTE(result_start) = v24;
  if ( v45 - end_pos != -1 )
    AString::append(result, &code->i_str_ref_p->i_cstr_p[end_pos], v45 - end_pos + 1);
  if ( code->i_str_ref_p->i_length )
  {
    last_counted_p = 0;
    v25 = AString::count(code, 10, 0, end_pos, &last_counted_p);
    v26 = last_counted_p;
    if ( v25 )
      v26 = last_counted_p + 1;
    if ( v26 < end_pos )
      v10 = end_pos - v26;
  }
  else
  {
    v25 = 0;
    v10 = result_start;
  }
  if ( !v24 )
  {
    v27 = result->i_str_ref_p->i_length + 1;
    if ( (unsigned int)v27 >= result->i_str_ref_p->i_size
      || result->i_str_ref_p->i_ref_count + result->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(result, v27);
    }
    result->i_str_ref_p->i_cstr_p[(unsigned int)(v27 - 1)] = 10;
    result->i_str_ref_p->i_cstr_p[v27] = 0;
    result->i_str_ref_p->i_length = v27;
  }
  if ( end_pos - v10 > v12 )
    v12 = end_pos - v10;
  v28 = end_pos - v12;
  v29 = v10;
  if ( v28 < v10 )
    v29 = v28;
  v30 = v10 - v29;
  if ( v10 - v29 >= 2 )
  {
    v31 = result->i_str_ref_p;
    last_counted_p = result->i_str_ref_p->i_length;
    v32 = v30 - 1 + last_counted_p;
    if ( (unsigned int)v32 >= v31->i_size || v31->i_ref_count + v31->i_read_only != 1 )
      AString::set_size(result, v32);
    memset(&result->i_str_ref_p->i_cstr_p[last_counted_p], 62, v30 - 1);
    result->i_str_ref_p->i_cstr_p[v32] = 0;
    result->i_str_ref_p->i_length = v32;
  }
  if ( v30 )
  {
    v33 = result->i_str_ref_p->i_length + 1;
    if ( (unsigned int)v33 >= result->i_str_ref_p->i_size
      || result->i_str_ref_p->i_ref_count + result->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(result, v33);
    }
    result->i_str_ref_p->i_cstr_p[(unsigned int)(v33 - 1)] = 32;
    result->i_str_ref_p->i_cstr_p[v33] = 0;
    result->i_str_ref_p->i_length = v33;
  }
  if ( v28 >= 2 )
  {
    v34 = v28 - 1;
    v35 = result->i_str_ref_p->i_length;
    v36 = v28 - 1 + (unsigned int)v35;
    if ( (unsigned int)v36 >= result->i_str_ref_p->i_size
      || result->i_str_ref_p->i_ref_count + result->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(result, v36);
    }
    memset(&result->i_str_ref_p->i_cstr_p[v35], 45, v34);
    result->i_str_ref_p->i_cstr_p[v36] = 0;
    result->i_str_ref_p->i_length = v36;
  }
  v37 = result->i_str_ref_p->i_length + 256;
  if ( v37 >= result->i_str_ref_p->i_size || result->i_str_ref_p->i_ref_count + result->i_str_ref_p->i_read_only != 1 )
    AString::set_size(result, v37);
  v38 = v25 + 1;
  if ( v30 == v10 )
  {
    AString::append_format(result, "^ <<<< Line: %u, column: %u\n", v38, v10 + 1);
  }
  else
  {
    LODWORD(v42) = v10 + 1;
    AString::append_format(result, "^ <<<< Line: %u, columns: %u-%u\n", v38, v30 + 1, v42);
  }
  if ( (_BYTE)result_start )
    AString::append(result, &code->i_str_ref_p->i_cstr_p[v45 + 1], find_pos_p - v45 - 1);
  AString::remove_all(result, 13, 0, 0xFFFFFFFF);
  AString::append(result, "\n", 0xFFFFFFFF);
  v39 = result->i_str_ref_p->i_length;
  v40 = (unsigned int)(v39 + 90);
  if ( (unsigned int)v40 >= result->i_str_ref_p->i_size
    || result->i_str_ref_p->i_ref_count + result->i_str_ref_p->i_read_only != 1 )
  {
    AString::set_size(result, v40);
  }
  memset(&result->i_str_ref_p->i_cstr_p[v39], 94, 0x5Aui64);
  result->i_str_ref_p->i_cstr_p[v40] = 0;
  result->i_str_ref_p->i_length = v40;
  AString::append(result, "\n", 0xFFFFFFFF);
  return result;
}

// File Line: 11278
// RVA: 0x119670
AString *__fastcall SSParser::get_result_string(AString *result, __int64 a2)
{
  const char *v3; // rdx

  switch ( (int)a2 )
  {
    case 0:
      AString::AString(result, "The text was parsed without error.");
      return result;
    case 3:
      v3 = "Identifier name is longer than the maximum.\n"
           "All characters greater than the maximum of 256 have been truncated.";
      goto LABEL_117;
    case 6:
      v3 = "The expression has no side effects so it does not seem useful as a statement\n"
           "on its own [not used as an argument or result (last expression) of a code block].";
      goto LABEL_117;
    case 7:
      v3 = "The expression has only sub-expressions with side effects - it does not seem\n"
           "useful as a statement on its own [not used as an argument or result (last\n"
           "expression) of a code block].";
      goto LABEL_117;
    case 9:
      v3 = "Expected a digit or letter [depending on the radix/base] but did not receive one.";
      goto LABEL_117;
    case 10:
      v3 = "A binding must begin with a colon :.";
      goto LABEL_117;
    case 11:
      v3 = "Expected a code block [ ], but did not find one.";
      goto LABEL_117;
    case 12:
      v3 = "Expected the class cast operator <>, but it was not found.";
      goto LABEL_117;
    case 13:
      v3 = "A character escape sequence must begin with a backslash character \\.";
      goto LABEL_117;
    case 14:
      v3 = "A character escape sequence that uses a number must have ASCII value between 0 and 255.";
      goto LABEL_117;
    case 15:
      v3 = "Class name must begin with an uppercase letter.";
      goto LABEL_117;
    case 16:
      v3 = "Expected class, list-class, invoke class, metaclass or class union and did not find one.";
      goto LABEL_117;
    case 17:
      v3 = "A List class descriptor must follow the list class type with braces/curly brackets {} optionally enclosed a"
           "round an item type.";
      goto LABEL_117;
    case 18:
      v3 = "A List class descriptor must end with a closing brace/curly bracket }.";
      goto LABEL_117;
    case 19:
      v3 = "Expected a class, list-class or invoke class and did not find one.";
      goto LABEL_117;
    case 20:
      v3 = "A metaclass descriptor must begin with an angle bracket <.";
      goto LABEL_117;
    case 21:
      v3 = "A metaclass descriptor must end with a closing angle bracket >.";
      goto LABEL_117;
    case 22:
      v3 = "A class union descriptor must begin with an opening angle bracket <.";
      goto LABEL_117;
    case 23:
      v3 = "A class union descriptor must end with a closing angle bracket >.";
      goto LABEL_117;
    case 24:
      v3 = "Expected a clause code block [ ], but did not receive one.";
      goto LABEL_117;
    case 25:
      v3 = "A code block must start with an opening square bracket [.";
      goto LABEL_117;
    case 26:
      v3 = "Multiple line comment missing closing delimiters *// .";
      goto LABEL_117;
    case 27:
      v3 = "Expected the class conversion operator >>, but it was not found.";
      goto LABEL_117;
    case 28:
      v3 = "A data definition statement must start with an exclamation mark !.";
      goto LABEL_117;
    case 29:
      v3 = "Expected a digit, but did not receive one.";
      goto LABEL_117;
    case 30:
      v3 = "Expected an expression, but did not find one.";
      goto LABEL_117;
    case 31:
      v3 = "A group parameter specification must begin with an opening brace {.";
      goto LABEL_117;
    case 32:
      v3 = "Instance name must begin with a lowercase letter.";
      goto LABEL_117;
    case 33:
      v3 = "Expected a negative sign - or a digit, but received neither.";
      goto LABEL_117;
    case 34:
      v3 = "An invocation apply must begin with a percent sign % character.";
      goto LABEL_117;
    case 35:
      v3 = "An invocation argument list must begin with an opening parenthesis (bracket) (.\n[Missing a period?]";
      goto LABEL_117;
    case 36:
      v3 = "An argument in an invocation argument list must be followed by a comma , argument delimiter, semi-colon ;"
           " return argument delimiter or an ending parenthesis (bracket) ).";
      goto LABEL_117;
    case 37:
      v3 = "An invocation return argument list must begin with an opening brace {.";
      goto LABEL_117;
    case 38:
      v3 = "Expected cascaded invocations - i.e. a receiver followed by . then [ then two or more invocations and end"
           "ing in ] and did not find any.";
      goto LABEL_117;
    case 39:
      v3 = "Expected cascaded invocations - i.e. a receiver followed . then [ then two or more invocations and ending"
           " in ] and only found one invocation.\n"
           "[If only one invocation is desired, then just use . - i.e. receiver.invoke()].\n";
      goto LABEL_117;
    case 40:
      v3 = "Expected an invocation selector - i.e. a method call or coroutine call,\nbut found neither.";
      goto LABEL_117;
    case 41:
      v3 = "Expected an invocation selector - i.e. a method call, an operator call\n"
           "or coroutine call, but found neither.";
      goto LABEL_117;
    case 42:
      v3 = "A character literal must begin with an accent [`] character - the one beneath the tilde ~.";
      goto LABEL_117;
    case 43:
      v3 = "Expected a List literal opening brace/curly bracket {, but did not receive one.";
      goto LABEL_117;
    case 44:
      v3 = "An item delimiter , or a closing brace/curly bracket } was expected while parsing a List literal, but did"
           " not receive either.";
      goto LABEL_117;
    case 45:
      v3 = "A string literal must begin with a double quote [\"]";
      goto LABEL_117;
    case 46:
      v3 = "A symbol literal must begin with a single quote [].";
      goto LABEL_117;
    case 47:
      v3 = "A symbol literal must end with a single quote [].";
      goto LABEL_117;
    case 48:
      v3 = "Expected a loop code block [ ], but did not receive one.";
      goto LABEL_117;
    case 49:
      v3 = "A loop exit must begin with exit.";
      goto LABEL_117;
    case 50:
      v3 = "Expected a class meta key name (demand_load or object_id_lookup).";
      goto LABEL_117;
    case 52:
      v3 = "A constructor method name must begin with an exclamation mark ! and be optionally followed by an identifier"
           " starting with a lowercase letter.";
      goto LABEL_117;
    case 53:
      v3 = "A method name must begin with a lowercase letter or an exclamation mark !";
      goto LABEL_117;
    case 54:
      v3 = "Expected a named argument specifier (arg_name#) and did not find one.";
      goto LABEL_117;
    case 55:
      v3 = "Expected an operator method call, but did not find one.";
      goto LABEL_117;
    case 56:
      v3 = "Expected an operator id, but did not find the @ or @? symbols.";
      goto LABEL_117;
    case 57:
      v3 = "A parameter list must start with an opening parenthesis (bracket) (.";
      goto LABEL_117;
    case 58:
      v3 = "Argument descriptors must be named and no name was found.";
      goto LABEL_117;
    case 59:
      v3 = "Expected a race code block [ ], but did not find one.";
      goto LABEL_117;
    case 60:
      v3 = "While parsing a real number, expected a fractional part (. digit {digit}),\n"
           "an exponent part (E | e [-] digits), or both, but received neither.";
      goto LABEL_117;
    case 61:
      v3 = "A script name must begin with an underscore _ and then a lowercase letter.";
      goto LABEL_117;
    case 62:
      v3 = "Expected a scope resolution operator to follow the given class scope.";
      goto LABEL_117;
    case 63:
      v3 = "String literal missing closing double quotation mark \".";
      goto LABEL_117;
    case 64:
      v3 = "A strategy name must begin with a dollar sign $ and then a lowercase letter.";
      goto LABEL_117;
    case 65:
      v3 = "String literal missing closing quotation mark ().";
      goto LABEL_117;
    case 66:
      v3 = "A create temporary variable statement must start with an exclamation mark !.";
      goto LABEL_117;
    case 67:
      v3 = "Expected a sync code block [ ], but did not find one.";
      goto LABEL_117;
    case 68:
      v3 = "Whitespace required - expected some combination of whitespace characters and/or comments.";
      goto LABEL_117;
    case 69:
      v3 = "Invocation expected , ) or an expression.";
      goto LABEL_117;
    case 70:
      v3 = "A variable rebind to an instance may only be applied to an identifier.";
      goto LABEL_117;
    case 71:
      v3 = "A concurrent branch only makes sense when used on an expression that is not immediate\n"
           "and may take more than one frame to execute such as a coroutine call.";
      goto LABEL_117;
    case 72:
      v3 = "While parsing for a create temporary variable statement, a constructor or a destructor call was found instead.";
      goto LABEL_117;
    case 73:
      v3 = "Expected a particular character or type of character, but did not receive it.";
      goto LABEL_117;
    case 74:
      v3 = "The metaclass <Object> should be used instead of the class instance Class.";
      goto LABEL_117;
    case 75:
      v3 = "Group parameter descriptor expected a class name or }, but neither were found.";
      goto LABEL_117;
    case 76:
      v3 = "Found a trailing concurrency delimiter , at the end of a code block.\n"
           "A concurrency delimiter is valid only when it is between two statements.";
      goto LABEL_117;
    case 79:
      v3 = "A divert only makes sense when used on expressions that are durational / non-immediate\n"
           "such as coroutine calls that may take more than one frame to execute and thereforerequire update calls.";
      goto LABEL_117;
    case 80:
      v3 = "An else / default clause may not be the sole clause - there must be at least one more prior to it.";
      goto LABEL_117;
    case 81:
      v3 = "Found an else without a matching if or case.";
      goto LABEL_117;
    case 82:
      v3 = "Hit end of file prior to the completion of a parse.\n[Mismatched brackets [] {} ()?]";
      goto LABEL_117;
    case 83:
      v3 = "Found a loop exit in an invalid location.";
      goto LABEL_117;
    case 84:
      v3 = "Operator calls may not be used with an implicit this - otherwise it is more error\n"
           "prone and even when used correctly code is more difficult to understand.";
      goto LABEL_117;
    case 85:
      v3 = "[A named specifier must appear before an argument rather than after - arg_name#arg.]\n"
           "An argument in an invocation argument list must be followed by a comma , argument delimiter, semi-colon ;"
           " return argument delimiter or an ending parenthesis (bracket) ).";
      goto LABEL_117;
    case 86:
      v3 = "Found an object-identifier when a closure was expected.";
      goto LABEL_117;
    case 87:
      v3 = "The parameter list expected , or ), but neither were found.";
      goto LABEL_117;
    case 88:
      v3 = "The parameter list did not expect an extra semi-colon ;!  Return parameters already started.";
      goto LABEL_117;
    case 90:
      v3 = "The code block expected another statement or the end of the code block ].";
      goto LABEL_117;
    case 91:
      v3 = "A class union descriptor must union two or more classes.";
      goto LABEL_117;
    case 92:
      AString::AString(
        result,
        0x100u,
        "The group parameter descriptor contained too many classes.\n"
        "There may not be more than %i classes in the pattern.",
        63i64);
      return result;
    case 93:
      v3 = "Radix too large - it must be between 2 and 36 inclusively.";
      goto LABEL_117;
    case 94:
      v3 = "Radix too small - it must be between 2 and 36 inclusively.";
      goto LABEL_117;
    case 95:
      v3 = "An identifier may be no more than 255 characters long.";
      goto LABEL_117;
    case 96:
      v3 = "A symbol literal may be no more than 255 characters long.";
      goto LABEL_117;
    case 97:
      v3 = "The case comparison expression must resolve to a class type that has an equals operator =.";
      goto LABEL_117;
    case 98:
      v3 = "A conversion method may not have any parameters [this may change in the future].";
      goto LABEL_117;
    case 99:
      v3 = "This data member name is a duplicate of one already existing in this class.";
      goto LABEL_117;
    case 100:
      v3 = "This data member name is a duplicate of one already existing in a superclass of this class.";
      goto LABEL_117;
    case 101:
      v3 = "This data member name is a duplicate of one already existing in a subclass of this class.";
      goto LABEL_117;
    case 102:
      v3 = "Argument with the same name already present in the parameter list.";
      goto LABEL_117;
    case 103:
      v3 = "Argument with the same name already present in the return parameter list.";
      goto LABEL_117;
    case 105:
      v3 = "Expected the end of the invocation list ), but did not find it.\n[Too many arguments supplied?]";
      goto LABEL_117;
    case 110:
      v3 = "Once a named argument is used, any following arguments must also be named.";
      goto LABEL_117;
    case 111:
      v3 = "The specified constructor method requires one or more arguments.";
      goto LABEL_117;
    case 112:
      v3 = "A class with the specified name does not exist - ensure that it is registered prior to this parse.";
      goto LABEL_117;
    case 119:
      v3 = "A deferred statement (such as a coroutine) was found where an immediate statement (such as a method) was expected.";
      goto LABEL_117;
    case 120:
      v3 = "An immediate statement (such as a method) was found where a deferred statement (such as a coroutine) was expected.";
      goto LABEL_117;
    case 121:
      v3 = "A concurrent block (sync or race) should have at least two durational expressions or running concurrently is redundant.";
      goto LABEL_117;
    case 122:
      v3 = "Expected an Actor class or subclass, but given a non-actor class.";
      goto LABEL_117;
    case 123:
      v3 = "The class scope for coroutines and strategies must be an Actor class or an Actor subclass.";
      goto LABEL_117;
    case 126:
      v3 = "The result class type of a case test expression must be compatible as an operand to the equals operator = o"
           "f the comparison expression.";
      goto LABEL_117;
    case 128:
      v3 = "Generic types are not supported in closure parameter lists and might never be - too many levels of indirectio"
           "n to wrap your head around";
      goto LABEL_117;
    case 129:
      v3 = "The result type of a conditional test expression must be a Boolean class.";
      goto LABEL_117;
    case 130:
      v3 = "The result type of a conversion method must be of the same type as or a subclass of the method name.";
      goto LABEL_117;
    case 131:
      v3 = "The result type of the default expression was not compatible with the specified parameter type.";
      goto LABEL_117;
    case 133:
      v3 = "Cannot do an invoke apply [receiver%invocation()] on a receiver that is guaranteed to be nil.";
      goto LABEL_117;
    case 134:
      v3 = "Expected a List class or subclass, but given a non-list class.";
      goto LABEL_117;
    case 135:
      v3 = "Supplied list item is not of the specified desired class type.";
      goto LABEL_117;
    case 138:
      v3 = "The specified class scope qualifier is not the same class or a superclass of the class of the receiver expres"
           "sion (or implied this).  Note that a NilClass may only have a scope qualifier of Object.";
      goto LABEL_117;
    case 139:
      v3 = "This class union descriptor is trivial.\n"
           "It is lexically correct, but it can be represented more simply as a single class instance or metaclass.";
      goto LABEL_117;
    default:
      v3 = a_cstr_format(
             "Parse error: #%u.\n[Use a build with additional error checking (SS_CODE_OUT defined) for more context.]",
             a2);
LABEL_117:
      AString::AString(result, v3);
      return result;
  }
}s lexically correct, but it can be

// File Line: 11548
// RVA: 0x11A870
void SSParser::initialize_pre_load(void)
{
  unsigned int v0; // eax
  ASymbol **i_array_p; // rbx
  unsigned int v2; // eax
  AString **v3; // rbx
  __int64 i_count; // rbx
  ASymbol **v5; // rdi
  unsigned int v6; // eax
  __int64 v7; // rbx
  ASymbol **v8; // rdi
  unsigned int v9; // eax
  __int64 v10; // rbx
  ASymbol **v11; // rdi
  unsigned int v12; // eax
  __int64 v13; // rbx
  ASymbol **v14; // rdi
  unsigned int v15; // eax
  __int64 v16; // rbx
  ASymbol **v17; // rdi
  unsigned int v18; // eax
  __int64 v19; // rbx
  ASymbol **v20; // rdi
  unsigned int v21; // eax
  __int64 v22; // rbx
  ASymbol **v23; // rdi
  unsigned int v24; // eax
  __int64 v25; // rbx
  ASymbol **v26; // rdi
  unsigned int v27; // eax
  __int64 v28; // rbx
  ASymbol **v29; // rdi
  unsigned int v30; // eax
  __int64 v31; // rbx
  ASymbol **v32; // rdi
  unsigned int v33; // eax
  __int64 v34; // rbx
  ASymbol **v35; // rdi
  unsigned int v36; // eax
  __int64 v37; // rbx
  ASymbol **v38; // rdi
  unsigned int v39; // eax
  __int64 v40; // rbx
  ASymbol **v41; // rdi
  unsigned int v42; // eax
  __int64 v43; // rbx
  ASymbol **v44; // rdi
  unsigned int v45; // eax
  __int64 v46; // rbx
  ASymbol **v47; // rdi
  unsigned int v48; // eax
  AString *v49; // rbx
  unsigned int v50; // eax
  AString *v51; // rbx
  unsigned int v52; // eax
  AString *v53; // rbx
  unsigned int v54; // eax
  AString *v55; // rbx
  unsigned int v56; // eax
  AString *v57; // rbx
  unsigned int v58; // eax
  AString *v59; // rbx
  unsigned int v60; // eax
  AString *v61; // rbx
  unsigned int v62; // eax
  AString *v63; // rbx
  unsigned int v64; // eax
  AString *v65; // rbx
  unsigned int v66; // eax
  AString *v67; // rbx
  unsigned int v68; // eax
  AString *v69; // rbx
  unsigned int v70; // eax
  AString *v71; // rbx
  unsigned int v72; // eax
  AString *v73; // rbx
  unsigned int v74; // eax
  AString *v75; // rbx
  unsigned int v76; // eax
  AString *v77; // rbx
  unsigned int v78; // eax
  unsigned int v79; // eax
  AString **v80; // rbx
  AString *v81; // rbx
  unsigned int v82; // eax
  AString *v83; // rbx
  unsigned int v84; // eax
  AString *v85; // rbx
  unsigned int v86; // eax
  AString *v87; // rbx
  unsigned int v88; // eax
  AString *v89; // rbx
  unsigned int v90; // eax
  AString *v91; // rbx
  unsigned int v92; // eax
  AString *v93; // rbx
  unsigned int v94; // eax

  SSParser::c_default_flags.i_flagset |= 1;
  if ( !SSParser::c_reserved_word_syms.i_count )
  {
    if ( SSParser::c_reserved_word_syms.i_size < 0xF )
    {
      v0 = AMemory::c_req_byte_size_func(0x78u) >> 3;
      SSParser::c_reserved_word_syms.i_size = v0;
      if ( SSParser::c_reserved_word_syms.i_count )
      {
        i_array_p = SSParser::c_reserved_word_syms.i_array_p;
        SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v0);
        memmove(SSParser::c_reserved_word_syms.i_array_p, i_array_p, 8i64 * SSParser::c_reserved_word_syms.i_count);
        AMemory::c_free_func(i_array_p);
      }
      else
      {
        AMemory::c_free_func(SSParser::c_reserved_word_syms.i_array_p);
        SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(SSParser::c_reserved_word_syms.i_size);
      }
    }
    if ( SSParser::c_reserved_word_strs.i_size < 0xF )
    {
      v2 = AMemory::c_req_byte_size_func(0x78u) >> 3;
      SSParser::c_reserved_word_strs.i_size = v2;
      if ( SSParser::c_reserved_word_strs.i_count )
      {
        v3 = SSParser::c_reserved_word_strs.i_array_p;
        SSParser::c_reserved_word_strs.i_array_p = APArrayBase<AString>::alloc_array(v2);
        memmove(SSParser::c_reserved_word_strs.i_array_p, v3, 8i64 * SSParser::c_reserved_word_strs.i_count);
        AMemory::c_free_func(v3);
      }
      else
      {
        AMemory::c_free_func(SSParser::c_reserved_word_strs.i_array_p);
        SSParser::c_reserved_word_strs.i_array_p = APArrayBase<AString>::alloc_array(SSParser::c_reserved_word_strs.i_size);
      }
    }
    i_count = SSParser::c_reserved_word_syms.i_count;
    if ( SSParser::c_reserved_word_syms.i_size < SSParser::c_reserved_word_syms.i_count + 1 )
    {
      v5 = SSParser::c_reserved_word_syms.i_array_p;
      if ( SSParser::c_reserved_word_syms.i_count == -1 )
        v6 = 0;
      else
        v6 = AMemory::c_req_byte_size_func(8 * (SSParser::c_reserved_word_syms.i_count & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v6;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v6);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v5, 8 * i_count);
      AMemory::c_free_func(v5);
    }
    SSParser::c_reserved_word_syms.i_array_p[i_count] = &ASymbol_branch;
    v7 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v7;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v7 + 1) )
    {
      v8 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v7 == -1 )
        v9 = 0;
      else
        v9 = AMemory::c_req_byte_size_func(8 * (v7 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v9;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v9);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v8, 8i64 * (unsigned int)v7);
      AMemory::c_free_func(v8);
    }
    SSParser::c_reserved_word_syms.i_array_p[v7] = &ASymbol_case;
    v10 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v10;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v10 + 1) )
    {
      v11 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v10 == -1 )
        v12 = 0;
      else
        v12 = AMemory::c_req_byte_size_func(8 * (v10 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v12;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v12);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v11, 8i64 * (unsigned int)v10);
      AMemory::c_free_func(v11);
    }
    SSParser::c_reserved_word_syms.i_array_p[v10] = &ASymbol_divert;
    v13 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v13;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v13 + 1) )
    {
      v14 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v13 == -1 )
        v15 = 0;
      else
        v15 = AMemory::c_req_byte_size_func(8 * (v13 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v15;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v15);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v14, 8i64 * (unsigned int)v13);
      AMemory::c_free_func(v14);
    }
    SSParser::c_reserved_word_syms.i_array_p[v13] = &ASymbol_else;
    v16 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v16;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v16 + 1) )
    {
      v17 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v16 == -1 )
        v18 = 0;
      else
        v18 = AMemory::c_req_byte_size_func(8 * (v16 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v18;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v18);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v17, 8i64 * (unsigned int)v16);
      AMemory::c_free_func(v17);
    }
    SSParser::c_reserved_word_syms.i_array_p[v16] = &ASymbol_exit;
    v19 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v19;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v19 + 1) )
    {
      v20 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v19 == -1 )
        v21 = 0;
      else
        v21 = AMemory::c_req_byte_size_func(8 * (v19 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v21;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v21);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v20, 8i64 * (unsigned int)v19);
      AMemory::c_free_func(v20);
    }
    SSParser::c_reserved_word_syms.i_array_p[v19] = &ASymbol_false;
    v22 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v22;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v22 + 1) )
    {
      v23 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v22 == -1 )
        v24 = 0;
      else
        v24 = AMemory::c_req_byte_size_func(8 * (v22 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v24;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v24);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v23, 8i64 * (unsigned int)v22);
      AMemory::c_free_func(v23);
    }
    SSParser::c_reserved_word_syms.i_array_p[v22] = &ASymbol_if;
    v25 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v25;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v25 + 1) )
    {
      v26 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v25 == -1 )
        v27 = 0;
      else
        v27 = AMemory::c_req_byte_size_func(8 * (v25 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v27;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v27);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v26, 8i64 * (unsigned int)v25);
      AMemory::c_free_func(v26);
    }
    SSParser::c_reserved_word_syms.i_array_p[v25] = &ASymbol_loop;
    v28 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v28;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v28 + 1) )
    {
      v29 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v28 == -1 )
        v30 = 0;
      else
        v30 = AMemory::c_req_byte_size_func(8 * (v28 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v30;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v30);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v29, 8i64 * (unsigned int)v28);
      AMemory::c_free_func(v29);
    }
    SSParser::c_reserved_word_syms.i_array_p[v28] = &ASymbol_nil;
    v31 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v31;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v31 + 1) )
    {
      v32 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v31 == -1 )
        v33 = 0;
      else
        v33 = AMemory::c_req_byte_size_func(8 * (v31 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v33;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v33);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v32, 8i64 * (unsigned int)v31);
      AMemory::c_free_func(v32);
    }
    SSParser::c_reserved_word_syms.i_array_p[v31] = &ASymbol_race;
    v34 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v34;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v34 + 1) )
    {
      v35 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v34 == -1 )
        v36 = 0;
      else
        v36 = AMemory::c_req_byte_size_func(8 * (v34 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v36;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v36);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v35, 8i64 * (unsigned int)v34);
      AMemory::c_free_func(v35);
    }
    SSParser::c_reserved_word_syms.i_array_p[v34] = &ASymbol_sync;
    v37 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v37;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v37 + 1) )
    {
      v38 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v37 == -1 )
        v39 = 0;
      else
        v39 = AMemory::c_req_byte_size_func(8 * (v37 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v39;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v39);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v38, 8i64 * (unsigned int)v37);
      AMemory::c_free_func(v38);
    }
    SSParser::c_reserved_word_syms.i_array_p[v37] = &ASymbol_this;
    v40 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v40;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v40 + 1) )
    {
      v41 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v40 == -1 )
        v42 = 0;
      else
        v42 = AMemory::c_req_byte_size_func(8 * (v40 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v42;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v42);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v41, 8i64 * (unsigned int)v40);
      AMemory::c_free_func(v41);
    }
    SSParser::c_reserved_word_syms.i_array_p[v40] = &ASymbol_this_class;
    v43 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v43;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v43 + 1) )
    {
      v44 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v43 == -1 )
        v45 = 0;
      else
        v45 = AMemory::c_req_byte_size_func(8 * (v43 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v45;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v45);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v44, 8i64 * (unsigned int)v43);
      AMemory::c_free_func(v44);
    }
    SSParser::c_reserved_word_syms.i_array_p[v43] = &ASymbol_this_code;
    v46 = SSParser::c_reserved_word_syms.i_count + 1;
    SSParser::c_reserved_word_syms.i_count = v46;
    if ( SSParser::c_reserved_word_syms.i_size < (unsigned int)(v46 + 1) )
    {
      v47 = SSParser::c_reserved_word_syms.i_array_p;
      if ( (_DWORD)v46 == -1 )
        v48 = 0;
      else
        v48 = AMemory::c_req_byte_size_func(8 * (v46 & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v48;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v48);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v47, 8i64 * (unsigned int)v46);
      AMemory::c_free_func(v47);
    }
    SSParser::c_reserved_word_syms.i_array_p[v46] = &ASymbol_true;
    ++SSParser::c_reserved_word_syms.i_count;
    v49 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v49 )
    {
      v50 = AMemory::c_req_byte_size_func(7u);
      v49->i_str_ref_p = AStringRef::pool_new("branch", 6u, v50, 1u, 0, 1);
    }
    else
    {
      v49 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v49, 0i64);
    v51 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v51 )
    {
      v52 = AMemory::c_req_byte_size_func(5u);
      v51->i_str_ref_p = AStringRef::pool_new("case", 4u, v52, 1u, 0, 1);
    }
    else
    {
      v51 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v51, 0i64);
    v53 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v53 )
    {
      v54 = AMemory::c_req_byte_size_func(7u);
      v53->i_str_ref_p = AStringRef::pool_new("divert", 6u, v54, 1u, 0, 1);
    }
    else
    {
      v53 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v53, 0i64);
    v55 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v55 )
    {
      v56 = AMemory::c_req_byte_size_func(5u);
      v55->i_str_ref_p = AStringRef::pool_new("else", 4u, v56, 1u, 0, 1);
    }
    else
    {
      v55 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v55, 0i64);
    v57 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v57 )
    {
      v58 = AMemory::c_req_byte_size_func(5u);
      v57->i_str_ref_p = AStringRef::pool_new("exit", 4u, v58, 1u, 0, 1);
    }
    else
    {
      v57 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v57, 0i64);
    v59 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v59 )
    {
      v60 = AMemory::c_req_byte_size_func(6u);
      v59->i_str_ref_p = AStringRef::pool_new("false", 5u, v60, 1u, 0, 1);
    }
    else
    {
      v59 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v59, 0i64);
    v61 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v61 )
    {
      v62 = AMemory::c_req_byte_size_func(3u);
      v61->i_str_ref_p = AStringRef::pool_new("if", 2u, v62, 1u, 0, 1);
    }
    else
    {
      v61 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v61, 0i64);
    v63 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v63 )
    {
      v64 = AMemory::c_req_byte_size_func(5u);
      v63->i_str_ref_p = AStringRef::pool_new("loop", 4u, v64, 1u, 0, 1);
    }
    else
    {
      v63 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v63, 0i64);
    v65 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v65 )
    {
      v66 = AMemory::c_req_byte_size_func(4u);
      v65->i_str_ref_p = AStringRef::pool_new("nil", 3u, v66, 1u, 0, 1);
    }
    else
    {
      v65 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v65, 0i64);
    v67 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v67 )
    {
      v68 = AMemory::c_req_byte_size_func(5u);
      v67->i_str_ref_p = AStringRef::pool_new("race", 4u, v68, 1u, 0, 1);
    }
    else
    {
      v67 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v67, 0i64);
    v69 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v69 )
    {
      v70 = AMemory::c_req_byte_size_func(5u);
      v69->i_str_ref_p = AStringRef::pool_new("sync", 4u, v70, 1u, 0, 1);
    }
    else
    {
      v69 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v69, 0i64);
    v71 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v71 )
    {
      v72 = AMemory::c_req_byte_size_func(5u);
      v71->i_str_ref_p = AStringRef::pool_new("this", 4u, v72, 1u, 0, 1);
    }
    else
    {
      v71 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v71, 0i64);
    v73 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v73 )
    {
      v74 = AMemory::c_req_byte_size_func(0xBu);
      v73->i_str_ref_p = AStringRef::pool_new("this_class", 0xAu, v74, 1u, 0, 1);
    }
    else
    {
      v73 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v73, 0i64);
    v75 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v75 )
    {
      v76 = AMemory::c_req_byte_size_func(0xAu);
      v75->i_str_ref_p = AStringRef::pool_new("this_code", 9u, v76, 1u, 0, 1);
    }
    else
    {
      v75 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v75, 0i64);
    v77 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v77 )
    {
      v78 = AMemory::c_req_byte_size_func(5u);
      v77->i_str_ref_p = AStringRef::pool_new("true", 4u, v78, 1u, 0, 1);
    }
    else
    {
      v77 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_reserved_word_strs, v77, 0i64);
    if ( SSParser::c_operator_word_strs.i_size < 7 )
    {
      v79 = AMemory::c_req_byte_size_func(0x38u) >> 3;
      SSParser::c_operator_word_strs.i_size = v79;
      if ( SSParser::c_operator_word_strs.i_count )
      {
        v80 = SSParser::c_operator_word_strs.i_array_p;
        SSParser::c_operator_word_strs.i_array_p = APArrayBase<AString>::alloc_array(v79);
        memmove(SSParser::c_operator_word_strs.i_array_p, v80, 8i64 * SSParser::c_operator_word_strs.i_count);
        AMemory::c_free_func(v80);
      }
      else
      {
        AMemory::c_free_func(SSParser::c_operator_word_strs.i_array_p);
        SSParser::c_operator_word_strs.i_array_p = APArrayBase<AString>::alloc_array(SSParser::c_operator_word_strs.i_size);
      }
    }
    v81 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v81 )
    {
      v82 = AMemory::c_req_byte_size_func(4u);
      v81->i_str_ref_p = AStringRef::pool_new("and", 3u, v82, 1u, 0, 1);
    }
    else
    {
      v81 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_operator_word_strs, v81, 0i64);
    v83 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v83 )
    {
      v84 = AMemory::c_req_byte_size_func(5u);
      v83->i_str_ref_p = AStringRef::pool_new("nand", 4u, v84, 1u, 0, 1);
    }
    else
    {
      v83 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_operator_word_strs, v83, 0i64);
    v85 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v85 )
    {
      v86 = AMemory::c_req_byte_size_func(4u);
      v85->i_str_ref_p = AStringRef::pool_new("nor", 3u, v86, 1u, 0, 1);
    }
    else
    {
      v85 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_operator_word_strs, v85, 0i64);
    v87 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v87 )
    {
      v88 = AMemory::c_req_byte_size_func(4u);
      v87->i_str_ref_p = AStringRef::pool_new("not", 3u, v88, 1u, 0, 1);
    }
    else
    {
      v87 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_operator_word_strs, v87, 0i64);
    v89 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v89 )
    {
      v90 = AMemory::c_req_byte_size_func(5u);
      v89->i_str_ref_p = AStringRef::pool_new("nxor", 4u, v90, 1u, 0, 1);
    }
    else
    {
      v89 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_operator_word_strs, v89, 0i64);
    v91 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v91 )
    {
      v92 = AMemory::c_req_byte_size_func(3u);
      v91->i_str_ref_p = AStringRef::pool_new("or", 2u, v92, 1u, 0, 1);
    }
    else
    {
      v91 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_operator_word_strs, v91, 0i64);
    v93 = (AString *)AMemory::c_malloc_func(8ui64, "AString");
    if ( v93 )
    {
      v94 = AMemory::c_req_byte_size_func(4u);
      v93->i_str_ref_p = AStringRef::pool_new("xor", 3u, v94, 1u, 0, 1);
    }
    else
    {
      v93 = 0i64;
    }
    APSorted<AString,AString,ACompareLogical<AString>>::append(&SSParser::c_operator_word_strs, v93, 0i64);
  }
}

// File Line: 11920
// RVA: 0x13C9E0
SSParser::string_to_esacpe_string

// File Line: 12057
// RVA: 0x12E480
void __fastcall SSParser::parse_name_symbol(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        ASymbol *name_p)
{
  unsigned int v4; // r11d
  ASymbol result; // [rsp+40h] [rbp+8h] BYREF

  v4 = *end_pos_p;
  *end_pos_p = this->i_str_ref_p->i_length;
  AString::find(this, ACharMatch_not_identifier, 1u, end_pos_p, v4, 0xFFFFFFFF);
  if ( name_p )
    name_p->i_uid = SSParser::as_symbol(this, &result, start_pos, *end_pos_p)->i_uid;
}

// File Line: 12087
// RVA: 0x129C30
SSDivert *__fastcall SSParser::parse_divert_block(SSParser *this, unsigned __int64 args)
{
  SSParser::Args *v2; // rbx
  SSParser::eResult v4; // eax
  SSCode *v5; // rax
  SSCode *v6; // rsi
  __int64 v7; // rdi
  _QWORD *v8; // rax
  _QWORD *end_pos_p; // [rsp+40h] [rbp+8h] BYREF

  v2 = (SSParser::Args *)args;
  *(_DWORD *)(args + 8) = 82;
  LODWORD(args) = *(_DWORD *)args;
  LODWORD(end_pos_p) = args;
  if ( (unsigned int)(this->i_str_ref_p->i_length - args) < 2
    || (v4 = SSParser::parse_ws_any(this, args, (unsigned int *)&end_pos_p),
        v2->i_result = v4,
        args = (unsigned int)end_pos_p,
        v2->i_end_pos = (unsigned int)end_pos_p,
        v4)
    || (v2->i_result = Result_err_expected_block, this->i_str_ref_p->i_cstr_p[args] != 91) )
  {
    v2->i_end_pos = args;
    return 0i64;
  }
  else
  {
    v2->i_start_pos = args;
    v5 = SSParser::parse_code_block_optimized(this, v2, SSInvokeTime_any, ResultDesired_true);
    v6 = v5;
    v7 = 0i64;
    if ( v2->i_result == Result_ok && v5 )
    {
      v8 = AMemory::c_malloc_func(0x10ui64, "SSDivert");
      end_pos_p = v8;
      if ( v8 )
      {
        *v8 = &SSExpressionBase::`vftable;
        *v8 = &SSDivert::`vftable;
        v8[1] = v6;
        return (SSDivert *)v8;
      }
    }
    return (SSDivert *)v7;
  }
}

// File Line: 12147
// RVA: 0x12E6A0
ASymbol *__fastcall SSParser::parse_object_id_tail(SSParser *this, SSParser::Args *args, SSActorClass *class_p)
{
  __int64 i_start_pos; // rdx
  char *i_cstr_p; // r8
  unsigned int v8; // edx
  ASymbol *v9; // rdi
  char v10; // cl
  SSParser::eResult v11; // eax
  __int64 v12; // r8
  SSClass *v13; // rax
  ASymbol *v14; // rax
  ASymbol *v15; // rdx
  void **v17; // [rsp+28h] [rbp-50h] BYREF
  ASymbol sym_p; // [rsp+30h] [rbp-48h] BYREF
  SSClass *v19; // [rsp+38h] [rbp-40h]
  __int64 v20; // [rsp+40h] [rbp-38h]
  unsigned int v21; // [rsp+48h] [rbp-30h]
  unsigned int v22; // [rsp+50h] [rbp-28h]

  i_start_pos = args->i_start_pos;
  i_cstr_p = this->i_str_ref_p->i_cstr_p;
  if ( (unsigned int)i_start_pos < this->i_str_ref_p->i_length && i_cstr_p[i_start_pos] == 64 )
  {
    v8 = i_start_pos + 1;
    v17 = &SSObjectId::`vftable;
    sym_p.i_uid = -1;
    v9 = 0i64;
    v19 = 0i64;
    v20 = 0i64;
    v21 = 0;
    v22 = 0;
    if ( !class_p )
      class_p = SSBrain::c_actor_class_p;
    v19 = class_p;
    v10 = i_cstr_p[v8];
    if ( v10 == 61 )
    {
      v22 |= 2u;
    }
    else
    {
      if ( v10 != 63 )
        goto LABEL_10;
      v22 |= 1u;
    }
    ++v8;
LABEL_10:
    v11 = (unsigned int)SSParser::parse_literal_symbol(this, v8, &args->i_end_pos, &sym_p);
    args->i_result = v11;
    if ( v11 == Result_ok )
    {
      if ( (class_p->i_flags & 0x10) != 0 )
      {
        v12 = this->i_flags.i_flagset >> 8;
        LOBYTE(v12) = BYTE1(this->i_flags.i_flagset) & 1;
        v13 = (SSClass *)((__int64 (__fastcall *)(SSClass *, void ***, __int64))v19->vfptr[1].is_actor_instance)(
                           v19,
                           &v17,
                           v12);
        if ( v13 )
        {
          if ( (v22 & 2) != 0 )
            v13 = SSBrain::c_symbol_class_p;
          args->i_type_p = v13;
          if ( (args->i_flags & 1) == 0 )
            goto LABEL_23;
          v14 = (ASymbol *)AMemory::c_malloc_func(0x30ui64, "SSObjectId");
          v15 = v14;
          if ( v14 )
          {
            *(_QWORD *)&v14->i_uid = &SSExpressionBase::`vftable;
            *(_QWORD *)&v14->i_uid = &SSObjectId::`vftable;
            v14[2].i_uid = sym_p.i_uid;
            *(_QWORD *)&v14[4].i_uid = v19;
            *(_QWORD *)&v14[6].i_uid = v20;
            v14[8].i_uid = v21;
            v14[10].i_uid = v22;
          }
          else
          {
            v15 = 0i64;
          }
LABEL_22:
          v9 = v15;
LABEL_23:
          v17 = &SSExpressionBase::`vftable;
          return v9;
        }
        args->i_result = Result_err_context_object_id_invalid;
      }
      else
      {
        args->i_result = Result_err_context_object_id_bad_class;
      }
    }
    v15 = 0i64;
    goto LABEL_22;
  }
  args->i_result = Result_err_expected_obj_id;
  return 0i64;
}

// File Line: 12264
// RVA: 0x12FB70
SSInvocation *__fastcall SSParser::parse_prefix_operator_expr(SSParser *this, ASymbol *op_name, SSParser::Args *args)
{
  SSParser::eResult v6; // eax
  SSLiteralList *v7; // rsi
  SSClassDescBase *i_type_p; // rdi
  __int64 v9; // rax
  __int64 v11; // rbx
  _QWORD *v12; // rdi
  ASymbol *v13; // rax

  v6 = SSParser::parse_ws_any(this, args->i_start_pos, &args->i_end_pos);
  args->i_result = v6;
  if ( v6 )
    return 0i64;
  args->i_start_pos = args->i_end_pos;
  v7 = SSParser::parse_expression(this, args, 1ui64);
  if ( args->i_result )
    return 0i64;
  i_type_p = args->i_type_p;
  if ( (this->i_flags.i_flagset & 1) != 0 )
  {
    v9 = (__int64)i_type_p->vfptr->get_method_inherited(args->i_type_p, op_name);
    if ( !v9 )
    {
      args->i_result = Result_err_context_non_method;
      if ( v7 )
        v7->vfptr->__vecDelDtor(v7, 1u);
      return 0i64;
    }
    (*(void (__fastcall **)(_QWORD, SSClassDescBase *))(**(_QWORD **)(*(_QWORD *)(v9 + 24) + 40i64) + 32i64))(
      *(_QWORD *)(*(_QWORD *)(v9 + 24) + 40i64),
      i_type_p);
  }
  v11 = 0i64;
  if ( v7 )
  {
    v12 = AMemory::c_malloc_func(0x18ui64, "SSInvocation");
    if ( v12 )
    {
      v13 = (ASymbol *)AMemory::c_malloc_func(0x38ui64, "SSMethodCall");
      if ( v13 )
      {
        v13[2].i_uid = op_name->i_uid;
        *(_QWORD *)&v13[4].i_uid = 0i64;
        *(_QWORD *)&v13->i_uid = &SSInvokeBase::`vftable;
        v13[6].i_uid = 0;
        *(_QWORD *)&v13[8].i_uid = 0i64;
        v13[10].i_uid = 0;
        *(_QWORD *)&v13[12].i_uid = 0i64;
        *(_QWORD *)&v13->i_uid = &SSMethodCall::`vftable;
      }
      else
      {
        v13 = 0i64;
      }
      *v12 = &SSExpressionBase::`vftable;
      *v12 = &SSInvocation::`vftable;
      v12[1] = v7;
      v12[2] = v13;
      return (SSInvocation *)v12;
    }
  }
  return (SSInvocation *)v11;
}

// File Line: 12342
// RVA: 0x1291D0
SSConcurrentBranch *__fastcall SSParser::parse_concurrent_branch_block(SSParser *this, unsigned __int64 args)
{
  SSParser::Args *v2; // rbx
  SSParser::eResult v4; // eax
  __int64 v5; // rsi
  SSCode *v6; // rax
  SSCode *v7; // rdi
  _QWORD *v8; // rax
  _QWORD *end_pos_p; // [rsp+40h] [rbp+8h] BYREF

  v2 = (SSParser::Args *)args;
  *(_DWORD *)(args + 8) = 82;
  LODWORD(args) = *(_DWORD *)args;
  LODWORD(end_pos_p) = args;
  if ( (unsigned int)(this->i_str_ref_p->i_length - args) < 2
    || (v4 = SSParser::parse_ws_any(this, args, (unsigned int *)&end_pos_p),
        v2->i_result = v4,
        args = (unsigned int)end_pos_p,
        v2->i_end_pos = (unsigned int)end_pos_p,
        v4)
    || (v2->i_result = Result_err_expected_block, this->i_str_ref_p->i_cstr_p[args] != 91) )
  {
    v2->i_end_pos = args;
    return 0i64;
  }
  else
  {
    v2->i_start_pos = args;
    v5 = 0i64;
    v6 = SSParser::parse_code_block_optimized(this, v2, SSInvokeTime_any, ResultDesired_false);
    v7 = v6;
    if ( v2->i_result == Result_ok )
    {
      if ( v6 && v6->vfptr->is_immediate(v6, 0i64) )
      {
        v2->i_result = Result_err_unexpected_branch_expr;
        v7->vfptr->__vecDelDtor(v7, 1u);
      }
      else
      {
        v2->i_type_p = SSBrain::c_none_class_p;
        if ( v7 )
        {
          v8 = AMemory::c_malloc_func(0x10ui64, "SSConcurrentBranch");
          end_pos_p = v8;
          if ( v8 )
          {
            *v8 = &SSExpressionBase::`vftable;
            *v8 = &SSConcurrentBranch::`vftable;
            v8[1] = v7;
            return (SSConcurrentBranch *)v8;
          }
        }
      }
    }
    return (SSConcurrentBranch *)v5;
  }
}

// File Line: 12415
// RVA: 0x129420
SSConcurrentSync *__fastcall SSParser::parse_concurrent_sync_block(SSParser *this, unsigned __int64 args)
{
  SSParser::Args *v2; // rbx
  SSParser::eResult v4; // eax
  SSCode *v5; // rax
  SSCode *v6; // rdi
  _DWORD *v7; // rsi
  _DWORD *v8; // r8
  SSExpressionBase **i_array_p; // rcx
  _DWORD *end_pos_p; // [rsp+40h] [rbp+8h] BYREF
  _DWORD *v12; // [rsp+48h] [rbp+10h]

  v2 = (SSParser::Args *)args;
  *(_DWORD *)(args + 8) = 82;
  LODWORD(args) = *(_DWORD *)args;
  LODWORD(end_pos_p) = args;
  if ( (unsigned int)(this->i_str_ref_p->i_length - args) < 2
    || (v4 = SSParser::parse_ws_any(this, args, (unsigned int *)&end_pos_p),
        v2->i_result = v4,
        args = (unsigned int)end_pos_p,
        v2->i_end_pos = (unsigned int)end_pos_p,
        v4)
    || (v2->i_result = Result_err_expected_sync_block, this->i_str_ref_p->i_cstr_p[args] != 91) )
  {
    v2->i_end_pos = args;
    return 0i64;
  }
  else
  {
    v2->i_start_pos = args;
    v5 = SSParser::parse_code_block(this, v2, SSInvokeTime_durational, ResultDesired_false);
    v6 = v5;
    v7 = 0i64;
    if ( v2->i_result == Result_ok )
    {
      v2->i_type_p = SSBrain::c_none_class_p;
      if ( v5 )
      {
        if ( v5->i_statements.i_count < 2 )
        {
          v2->i_result = Result_err_context_concurrent_redundant;
        }
        else
        {
          v8 = AMemory::c_malloc_func(0x18ui64, "SSConcurrentSync");
          end_pos_p = v8;
          if ( v8 )
          {
            *(_QWORD *)v8 = &SSExpressionBase::`vftable;
            *(_QWORD *)v8 = &SSConcurrentSync::`vftable;
            v12 = v8 + 2;
            i_array_p = v6->i_statements.i_array_p;
            v8[2] = v6->i_statements.i_count;
            *((_QWORD *)v8 + 2) = i_array_p;
            v6->i_statements.i_count = 0;
            v6->i_statements.i_array_p = 0i64;
            v7 = v8;
          }
        }
        v6->vfptr->__vecDelDtor(v6, 1u);
      }
    }
    return (SSConcurrentSync *)v7;
  }
}

// File Line: 12488
// RVA: 0x1292F0
SSConcurrentRace *__fastcall SSParser::parse_concurrent_race_block(SSParser *this, unsigned __int64 args)
{
  SSParser::Args *v2; // rbx
  SSParser::eResult v4; // eax
  SSCode *v5; // rax
  SSCode *v6; // rdi
  _DWORD *v7; // rsi
  _DWORD *v8; // r8
  SSExpressionBase **i_array_p; // rcx
  _DWORD *end_pos_p; // [rsp+40h] [rbp+8h] BYREF
  _DWORD *v12; // [rsp+48h] [rbp+10h]

  v2 = (SSParser::Args *)args;
  *(_DWORD *)(args + 8) = 82;
  LODWORD(args) = *(_DWORD *)args;
  LODWORD(end_pos_p) = args;
  if ( (unsigned int)(this->i_str_ref_p->i_length - args) < 2
    || (v4 = SSParser::parse_ws_any(this, args, (unsigned int *)&end_pos_p),
        v2->i_result = v4,
        args = (unsigned int)end_pos_p,
        v2->i_end_pos = (unsigned int)end_pos_p,
        v4)
    || (v2->i_result = Result_err_expected_race_block, this->i_str_ref_p->i_cstr_p[args] != 91) )
  {
    v2->i_end_pos = args;
    return 0i64;
  }
  else
  {
    v2->i_start_pos = args;
    v5 = SSParser::parse_code_block(this, v2, SSInvokeTime_durational, ResultDesired_false);
    v6 = v5;
    v7 = 0i64;
    if ( v2->i_result == Result_ok )
    {
      v2->i_type_p = SSBrain::c_none_class_p;
      if ( v5 )
      {
        if ( v5->i_statements.i_count < 2 )
        {
          v2->i_result = Result_err_context_concurrent_redundant;
        }
        else
        {
          v8 = AMemory::c_malloc_func(0x18ui64, "SSConcurrentRace");
          end_pos_p = v8;
          if ( v8 )
          {
            *(_QWORD *)v8 = &SSExpressionBase::`vftable;
            *(_QWORD *)v8 = &SSConcurrentRace::`vftable;
            v12 = v8 + 2;
            i_array_p = v6->i_statements.i_array_p;
            v8[2] = v6->i_statements.i_count;
            *((_QWORD *)v8 + 2) = i_array_p;
            v6->i_statements.i_count = 0;
            v6->i_statements.i_array_p = 0i64;
            v7 = v8;
          }
        }
        v6->vfptr->__vecDelDtor(v6, 1u);
      }
    }
    return (SSConcurrentRace *)v7;
  }
}

// File Line: 12577
// RVA: 0x12EEC0
SSParser::eResult __fastcall SSParser::parse_param_append(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSParameters *params_p)
{
  SSParser::eResult result; // eax
  SSParser::eResult v7; // ebx
  unsigned int i_count; // ecx
  SSParameterBase **i_array_p; // rdx
  SSParameterBase **v10; // r10
  SSParameterBase *param_new_pp; // [rsp+58h] [rbp+20h] BYREF

  if ( params_p )
  {
    result = SSParser::parse_parameter(this, start_pos, end_pos_p, &param_new_pp);
    v7 = result;
    if ( result == Result_ok )
    {
      i_count = params_p->i_params.i_count;
      if ( i_count && (i_array_p = params_p->i_params.i_array_p, v10 = &i_array_p[i_count - 1], i_array_p <= v10) )
      {
        while ( param_new_pp->i_name.i_uid != (*i_array_p)->i_name.i_uid )
        {
          if ( ++i_array_p > v10 )
            goto LABEL_8;
        }
        param_new_pp->vfptr->__vecDelDtor(param_new_pp, 1i64);
        return 102;
      }
      else
      {
LABEL_8:
        APCompactArray<SSParameterBase,ASymbol,ACompareLogical<ASymbol>>::append(&params_p->i_params, param_new_pp);
        return v7;
      }
    }
  }
  else
  {
    if ( this->i_str_ref_p->i_cstr_p[start_pos] == 123 )
      result = SSParser::parse_parameter_group(this, start_pos, (unsigned int *)&param_new_pp, 0i64);
    else
      result = SSParser::parse_parameter_unary(this, start_pos, (unsigned int *)&param_new_pp, 0i64);
    if ( end_pos_p )
      *end_pos_p = (unsigned int)param_new_pp;
  }
  return result;
}

// File Line: 12635
// RVA: 0x12EFA0
SSParser::eResult __fastcall SSParser::parse_param_return_append(
        SSParser *this,
        unsigned int start_pos,
        unsigned int *end_pos_p,
        SSParameters *params_p,
        unsigned int param_flags)
{
  SSParser::eResult v9; // ebp
  SSClassDescBase *i_obj_p; // rdi
  APCompactArrayLogical<SSTypedName,ASymbol> *p_i_return_params; // r15
  unsigned int i_count; // eax
  unsigned int i_uid; // esi
  SSTypedName **i_array_p; // rcx
  SSTypedName **v15; // r8
  SSTypedName *v16; // rax
  SSTypedName *v17; // rbx
  SSTypedName tname_p; // [rsp+38h] [rbp-30h] BYREF

  if ( !params_p )
    return SSParser::parse_parameter_specifier(this, start_pos, end_pos_p, 0i64, param_flags);
  tname_p.i_name = (ASymbol)ASymbol::get_null()->i_uid;
  tname_p.i_type_p.i_obj_p = 0i64;
  v9 = SSParser::parse_parameter_specifier(this, start_pos, end_pos_p, &tname_p, param_flags);
  i_obj_p = tname_p.i_type_p.i_obj_p;
  if ( v9 == Result_ok )
  {
    v9 = Result_err_context_duped_rparam_name;
    p_i_return_params = &params_p->i_return_params;
    i_count = params_p->i_return_params.i_count;
    i_uid = tname_p.i_name.i_uid;
    if ( i_count && (i_array_p = params_p->i_return_params.i_array_p, v15 = &i_array_p[i_count - 1], i_array_p <= v15) )
    {
      while ( tname_p.i_name.i_uid != (*i_array_p)->i_name.i_uid )
      {
        if ( ++i_array_p > v15 )
          goto LABEL_7;
      }
    }
    else
    {
LABEL_7:
      v9 = Result_ok;
      v16 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
      v17 = v16;
      if ( v16 )
      {
        v16->i_name.i_uid = i_uid;
        v16->i_type_p.i_obj_p = i_obj_p;
        if ( i_obj_p )
          (*(void (__fastcall **)(SSClassDescBase *))i_obj_p->vfptr->gap8)(i_obj_p);
      }
      else
      {
        v17 = 0i64;
      }
      APCompactArray<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(p_i_return_params, v17);
      if ( (this->i_flags.i_flagset & 1) != 0 )
        SSTypeContext::append_local(&this->i_context, &tname_p.i_name, SSBrain::c_none_class_p);
    }
  }
  if ( i_obj_p )
    (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
  return v9;
}

// File Line: 12698
// RVA: 0x12FF40
char __fastcall SSParser::parse_temporary_append(SSParser *this, SSParser::Args *args, SSCode *code_p)
{
  SSClassDescBase *i_type_p; // rdi
  SSTypedName *v7; // rbx
  SSExpressionBase *v8; // rdi
  SSExpressionBase *v9; // rax
  SSExpressionBaseVtbl *v10; // rbx
  SSExpressionBase *v11; // rax
  ASymbol ident_p; // [rsp+58h] [rbp+10h] BYREF
  SSExpressionBase *expr_pp; // [rsp+68h] [rbp+20h] BYREF

  ident_p.i_uid = -1;
  expr_pp = 0i64;
  if ( !SSParser::parse_temporary(this, args, &ident_p, &expr_pp) )
    return 0;
  AVCompactSorted<ASymbol,ASymbol,ACompareLogical<ASymbol>>::append(&code_p->i_temp_vars, &ident_p, 0i64);
  if ( (this->i_flags.i_flagset & 1) != 0 )
  {
    i_type_p = args->i_type_p;
    v7 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
    if ( v7 )
    {
      v7->i_name = ident_p;
      v7->i_type_p.i_obj_p = i_type_p;
      if ( i_type_p )
        (*(void (__fastcall **)(SSClassDescBase *))i_type_p->vfptr->gap8)(i_type_p);
    }
    else
    {
      v7 = 0i64;
    }
    APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(this->i_context.i_current_scope_p, v7, 0i64);
  }
  v8 = expr_pp;
  if ( expr_pp )
  {
    v9 = (SSExpressionBase *)AMemory::c_malloc_func(0x10ui64, "SSIdentifier");
    v10 = (SSExpressionBaseVtbl *)v9;
    expr_pp = v9;
    if ( v9 )
    {
      v9->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
      v9->vfptr = (SSExpressionBaseVtbl *)&SSIdentifier::`vftable;
      LODWORD(v9[1].vfptr) = ident_p;
    }
    else
    {
      v10 = 0i64;
    }
    v11 = (SSExpressionBase *)AMemory::c_malloc_func(0x18ui64, "SSBind");
    expr_pp = v11;
    if ( v11 )
    {
      v11->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
      v11->vfptr = (SSExpressionBaseVtbl *)&SSBind::`vftable;
      v11[1].vfptr = v10;
      v11[2].vfptr = (SSExpressionBaseVtbl *)v8;
    }
    APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
      &code_p->i_statements,
      v11);
  }
  return 1;
}

// File Line: 12761
// RVA: 0x12FCC0
bool __fastcall SSParser::parse_statement_append(
        SSParser *this,
        SSParser::Args *args,
        SSCode *code_p,
        eSSInvokeTime desired_exec_time)
{
  __int64 i_start_pos; // r15
  char v7; // cl
  SSExpressionBase *v10; // rdi
  SSLoopExit *v11; // rax
  bool v12; // r12
  unsigned int i_count; // eax
  SSLiteralList *v14; // rax
  unsigned int i_end_pos; // esi

  i_start_pos = args->i_start_pos;
  v7 = this->i_str_ref_p->i_cstr_p[i_start_pos];
  v10 = 0i64;
  if ( v7 == 33 )
  {
    if ( (args->i_flags & 1) != 0 )
    {
      if ( SSParser::parse_temporary_append(this, args, code_p) )
      {
        i_count = code_p->i_statements.i_count;
        if ( i_count )
          v10 = code_p->i_statements.i_array_p[i_count - 1];
      }
    }
    else
    {
      SSParser::parse_temporary(this, args, 0i64, 0i64);
    }
    v12 = args->i_end_pos != (_DWORD)i_start_pos;
  }
  else
  {
    if ( v7 != 101 )
      goto LABEL_12;
    v11 = SSParser::parse_loop_exit(this, args);
    v12 = args->i_end_pos != (_DWORD)i_start_pos;
    v10 = v11;
    if ( v11 )
      APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
        &code_p->i_statements,
        v11);
  }
  if ( !v12 )
  {
LABEL_12:
    v14 = SSParser::parse_expression(this, args, (unsigned int)desired_exec_time);
    if ( v14 )
      APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
        &code_p->i_statements,
        v14);
    return args->i_result == Result_ok;
  }
  i_end_pos = args->i_end_pos;
  if ( v10 && !SSParser::ensure_exec_time(this, v10, args, desired_exec_time) )
  {
    args->i_start_pos = i_start_pos;
    args->i_end_pos = i_end_pos;
  }
  return args->i_result == Result_ok;
}

// File Line: 12848
// RVA: 0x13E8D0
bool __fastcall SSParser::typecheck_parameters(
        SSParser *this,
        SSParser::Args *args,
        SSParameters *params_p,
        bool check_result)
{
  bool result; // al
  SSClass *i_obj_p; // rcx
  SSClassDescBase *i_type_p; // rbx
  SSClassDescBase *v10; // rcx
  __int64 i_count; // rax
  ASymbol **i_array_p; // rdi
  ASymbol **v13; // r15
  SSTypeContext *p_i_context; // r12
  ASymbol *v15; // rsi
  SSClass *variable_type; // rax
  SSClass *v17; // rcx
  SSClass *v18; // rbx
  __int64 v19; // rcx
  SSClassDescBase *v20; // rax
  __int64 v21; // rax

  if ( (this->i_flags.i_flagset & 1) == 0 )
  {
    args->i_result = Result_ok;
    return 1;
  }
  if ( check_result )
  {
    i_obj_p = (SSClass *)params_p->i_result_type_p.i_obj_p;
    if ( i_obj_p == SSBrain::c_auto_class_p )
    {
      i_type_p = args->i_type_p;
      if ( i_obj_p != i_type_p )
      {
        if ( i_type_p )
          (*(void (__fastcall **)(SSClassDescBase *))i_type_p->vfptr->gap8)(args->i_type_p);
        v10 = params_p->i_result_type_p.i_obj_p;
        if ( v10 )
          (*(void (__fastcall **)(SSClassDescBase *))&v10->vfptr->gap8[8])(v10);
        params_p->i_result_type_p.i_obj_p = i_type_p;
      }
    }
    else
    {
      if ( i_obj_p )
        v20 = i_obj_p->vfptr->as_finalized_generic(i_obj_p, this->i_context.i_obj_scope_p);
      else
        v20 = 0i64;
      result = args->i_type_p->vfptr->is_class_type(args->i_type_p, v20);
      if ( !result )
      {
        args->i_result = Result_err_typecheck_return_type;
        return result;
      }
    }
  }
  args->i_result = Result_ok;
  i_count = params_p->i_return_params.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = (ASymbol **)params_p->i_return_params.i_array_p;
    v13 = &i_array_p[i_count];
    if ( i_array_p < v13 )
    {
      p_i_context = &this->i_context;
      do
      {
        v15 = *i_array_p;
        variable_type = (SSClass *)SSTypeContext::get_variable_type(p_i_context, *i_array_p, 0);
        v17 = *(SSClass **)&v15[2].i_uid;
        v18 = variable_type;
        if ( v17 == SSBrain::c_auto_class_p )
        {
          if ( variable_type == SSBrain::c_none_class_p )
            goto LABEL_34;
          if ( v17 != variable_type )
          {
            if ( variable_type )
              (*(void (__fastcall **)(SSClass *))variable_type->vfptr->gap8)(variable_type);
            v19 = *(_QWORD *)&v15[2].i_uid;
            if ( v19 )
              (*(void (__fastcall **)(__int64))(*(_QWORD *)v19 + 16i64))(v19);
            *(_QWORD *)&v15[2].i_uid = v18;
          }
        }
        else
        {
          if ( v17 )
            v21 = (__int64)v17->vfptr->as_finalized_generic(v17, p_i_context->i_obj_scope_p);
          else
            v21 = 0i64;
          if ( !v18->vfptr->is_class_type(v18, (SSClassDescBase *)v21) )
          {
LABEL_34:
            args->i_result = Result_err_typecheck_rparam_type;
            return 0;
          }
        }
        ++i_array_p;
      }
      while ( i_array_p < v13 );
    }
  }
  args->i_result = Result_ok;
  return 1;
}

// File Line: 13022
// RVA: 0x13EC50
__int64 __fastcall SSParser::validate_bind_type(
        SSParser *this,
        SSIdentifier *identifier_p,
        SSClassDescBase *old_type_p,
        SSClassDescBase *new_type_p)
{
  if ( (this->i_flags.i_flagset & 1) != 0 && new_type_p != old_type_p )
  {
    if ( identifier_p->vfptr->get_type(identifier_p) != SSExprType_identifier
      && !new_type_p->vfptr->is_class_type(new_type_p, old_type_p) )
    {
      return 137i64;
    }
    if ( ((unsigned __int8 (__fastcall *)(SSIdentifier *))identifier_p->vfptr[1].__vecDelDtor)(identifier_p) )
      SSTypeContext::change_variable_type(&this->i_context, &identifier_p->i_ident_name, new_type_p);
  }
  return 0i64;
}

// File Line: 13070
// RVA: 0x1180C0
SSMethodBase *__fastcall SSParser::get_method_inherited(SSParser *this, SSClassUnion *class_p, ASymbol *method_name)
{
  if ( (this->i_flags.i_flagset & 2) != 0 && method_name->i_uid == ASymbol_String.i_uid )
  {
    if ( class_p->vfptr->get_class_type(class_p) == SSClassType_class_union )
    {
      if ( SSClassUnion::is_class_maybe(class_p, SSBrain::c_symbol_class_p) )
        return 0i64;
    }
    else if ( class_p->vfptr->is_class_type(class_p, SSBrain::c_symbol_class_p) )
    {
      return 0i64;
    }
  }
  return class_p->vfptr->get_method_inherited(class_p, method_name);
}

