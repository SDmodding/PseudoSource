// File Line: 112
// RVA: 0x1461530
__int64 dynamic_initializer_for__SSParser::c_reserved_word_syms__()
{
  return atexit(dynamic_atexit_destructor_for__SSParser::c_reserved_word_syms__);
}

// File Line: 113
// RVA: 0x1461510
__int64 dynamic_initializer_for__SSParser::c_reserved_word_strs__()
{
  return atexit(dynamic_atexit_destructor_for__SSParser::c_reserved_word_strs__);
}

// File Line: 114
// RVA: 0x14614E0
__int64 dynamic_initializer_for__SSParser::c_operator_word_strs__()
{
  return atexit(dynamic_atexit_destructor_for__SSParser::c_operator_word_strs__);
}

// File Line: 117
// RVA: 0x1461490
__int64 dynamic_initializer_for__SSParser::c_error_str__()
{
  AStringRef *v0; // rax

  v0 = AStringRef::get_empty();
  SSParser::c_error_str.i_str_ref_p = v0;
  ++v0->i_ref_count;
  return atexit(dynamic_atexit_destructor_for__SSParser::c_error_str__);
}

// File Line: 162
// RVA: 0x10F510
ASymbol *__fastcall SSParser::as_symbol(SSParser *this, ASymbol *result, unsigned int start_pos, unsigned int end_pos)
{
  unsigned int v4; // er10
  ASymbol *v5; // rbx
  unsigned int v6; // er9
  unsigned int v7; // er8

  v4 = start_pos;
  v5 = result;
  v6 = end_pos - start_pos;
  v7 = 255;
  if ( v6 < 0xFF )
    v7 = v6;
  ASymbol::create(result, &this->i_str_ref_p->i_cstr_p[v4], v7, 0);
  return v5;
}

// File Line: 178
// RVA: 0x13C360
void __fastcall SSParser::set_class_scope(SSParser *this, SSClassUnaryBase *scope_p)
{
  SSClass *v2; // rax

  v2 = SSBrain::c_object_class_p;
  if ( scope_p )
    v2 = (SSClass *)scope_p;
  this->i_context.i_obj_scope_p = (SSClassUnaryBase *)&v2->vfptr;
}

// File Line: 236
// RVA: 0x127190
SSBind *__fastcall SSParser::parse_bind(SSParser *this, SSParser::Args *args, SSExpressionBase *identifier_p)
{
  SSIdentifier *v3; // rsi
  SSParser::Args *v4; // rdi
  SSParser *v5; // r14
  eSSExprType v6; // eax
  _QWORD *v7; // rbx
  signed int v8; // eax
  SSClassDescBase *v10; // r15
  SSExpressionBase *v11; // rbp
  _QWORD *v12; // rax

  v3 = (SSIdentifier *)identifier_p;
  v4 = args;
  v5 = this;
  v6 = (unsigned int)identifier_p->vfptr->get_type(identifier_p);
  v7 = 0i64;
  if ( (signed int)v6 > 0 )
  {
    if ( (signed int)v6 <= 3 )
    {
      v8 = 0;
      goto LABEL_7;
    }
    if ( v6 == 5 )
    {
      v8 = 89;
      goto LABEL_7;
    }
  }
  v8 = 70;
LABEL_7:
  v4->i_result = v8;
  if ( v8 )
    return 0i64;
  v10 = v4->i_type_p;
  v11 = SSParser::parse_binding(v5, v4);
  if ( v4->i_result == Result_ok )
    v4->i_result = SSParser::validate_bind_type(v5, v3, v10, v4->i_type_p);
  if ( v11 && v4->i_result == Result_ok )
  {
    v12 = AMemory::c_malloc_func(0x18ui64, "SSBind");
    if ( v12 )
    {
      *v12 = &SSExpressionBase::`vftable';
      *v12 = &SSBind::`vftable';
      v12[1] = v3;
      v12[2] = v11;
      v7 = v12;
    }
  }
  return (SSBind *)v7;
}

// File Line: 292
// RVA: 0x127280
SSExpressionBase *__fastcall SSParser::parse_binding(SSParser *this, SSParser::Args *args)
{
  AStringRef *v2; // rax
  SSParser::Args *v3; // rbx
  __int64 v4; // rdx
  SSParser *v5; // rdi
  SSParser::eResult v6; // eax
  SSExpressionBase *result; // rax
  unsigned int end_pos_p; // [rsp+30h] [rbp+8h]

  v2 = this->i_str_ref_p;
  v3 = args;
  v4 = args->i_start_pos;
  v5 = this;
  end_pos_p = v4;
  if ( v2->i_length <= (unsigned int)v4 || v2->i_cstr_p[v4] != 58 )
  {
    v3->i_result = 10;
    v3->i_end_pos = v4;
    result = 0i64;
  }
  else
  {
    v6 = SSParser::parse_ws_any(this, v4 + 1, &end_pos_p);
    v3->i_result = v6;
    if ( v6 )
    {
      v3->i_end_pos = end_pos_p;
      result = 0i64;
    }
    else
    {
      v3->i_start_pos = end_pos_p;
      result = SSParser::parse_expression(v5, v3, SSInvokeTime_any);
    }
  }
  return result;
}

// File Line: 350
// RVA: 0x127310
SSCase *__fastcall SSParser::parse_case_tail(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // rbx
  SSParser *v3; // rsi
  int v4; // er14
  void (__fastcall ***v5)(_QWORD, signed __int64); // r15
  SSParser::eResult v6; // eax
  SSExpressionBase *v7; // rdi
  unsigned int v8; // er13
  __int64 v9; // rax
  __int64 v10; // rax
  __int64 v11; // rcx
  AStringRef *v12; // rax
  char *v13; // r12
  char *v14; // r15
  signed __int64 v15; // rax
  unsigned int v16; // edi
  unsigned __int64 v17; // r15
  SSParser::eResult v18; // eax
  SSExpressionBase *v19; // r13
  __int64 v20; // rdx
  signed int v21; // eax
  __int64 v22; // r14
  unsigned int v23; // eax
  SSTypedName **v24; // rax
  SSParser::eResult v25; // eax
  SSCode *v26; // r14
  SSClause *v27; // rax
  unsigned int v28; // er14
  unsigned int v29; // eax
  unsigned int v30; // eax
  SSTypedName **v31; // r14
  SSClassUnaryBase *v32; // rax
  unsigned int v34; // [rsp+20h] [rbp-79h]
  unsigned int v35; // [rsp+24h] [rbp-75h]
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > sorted; // [rsp+28h] [rbp-71h]
  unsigned int v37; // [rsp+40h] [rbp-59h]
  char *v38; // [rsp+48h] [rbp-51h]
  APCompactArray<SSClause,SSClause,ACompareAddress<SSClause> > *v39; // [rsp+50h] [rbp-49h]
  SSClass *v40; // [rsp+58h] [rbp-41h]
  APSortedLogical<SSTypedName,ASymbol> merge_vars_p; // [rsp+60h] [rbp-39h]
  SSClassUnion class_union; // [rsp+78h] [rbp-21h]
  __int64 v43; // [rsp+A8h] [rbp+Fh]
  SSClause *v44; // [rsp+B0h] [rbp+17h]
  unsigned int end_pos_p; // [rsp+108h] [rbp+6Fh]
  char *v46; // [rsp+110h] [rbp+77h]
  __int64 v47; // [rsp+118h] [rbp+7Fh]

  v43 = -2i64;
  v2 = args;
  v3 = this;
  v4 = 0;
  v5 = 0i64;
  v38 = 0i64;
  end_pos_p = args->i_start_pos;
  v6 = SSParser::parse_ws_any(this, end_pos_p, &end_pos_p);
  v2->i_result = v6;
  if ( v6 )
  {
    v2->i_end_pos = end_pos_p;
    return (SSCase *)v5;
  }
  v2->i_start_pos = end_pos_p;
  v7 = SSParser::parse_expression(v3, v2, SSInvokeTime_immediate);
  v8 = v2->i_end_pos;
  v35 = v2->i_end_pos;
  if ( v2->i_result )
    goto LABEL_81;
  v40 = SSBrain::c_object_class_p;
  if ( v3->i_flags.i_flagset & 1 )
  {
    v9 = (__int64)v2->i_type_p->vfptr->get_method_inherited(v2->i_type_p, &ASymbol_equals);
    if ( v9 )
    {
      v10 = *(_QWORD *)(v9 + 24);
      if ( *(_DWORD *)(v10 + 8) )
        v11 = **(_QWORD **)(v10 + 16);
      else
        v11 = 0i64;
      v40 = *(SSClass **)(v11 + 16);
    }
    else
    {
      v2->i_result = 97;
    }
  }
  if ( v2->i_result )
    goto LABEL_81;
  v12 = v3->i_str_ref_p;
  v37 = v3->i_str_ref_p->i_length;
  v13 = v12->i_cstr_p;
  class_union.i_ref_count = 0;
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
  class_union.i_common_class_p = 0i64;
  class_union.i_union.i_count = 0;
  class_union.i_union.i_array_p = 0i64;
  class_union.i_union.i_size = 0;
  merge_vars_p.i_count = 0;
  merge_vars_p.i_array_p = 0i64;
  merge_vars_p.i_size = 0;
  sorted.i_count = 0;
  sorted.i_array_p = 0i64;
  *(_QWORD *)&end_pos_p = 0i64;
  sorted.i_size = 0;
  if ( v7 )
  {
    v14 = (char *)AMemory::c_malloc_func(0x20ui64, "SSCase");
    v38 = v14;
    v46 = v14;
    if ( v14 )
    {
      *(_QWORD *)v14 = &SSExpressionBase::`vftable';
      *(_QWORD *)v14 = &SSCase::`vftable';
      *((_QWORD *)v14 + 1) = 0i64;
      v15 = (signed __int64)(v14 + 16);
      v47 = v15;
      *(_DWORD *)v15 = 0;
      *(_QWORD *)(v15 + 8) = 0i64;
    }
    else
    {
      v14 = 0i64;
      v38 = 0i64;
    }
    *((_QWORD *)v14 + 1) = v7;
    v39 = (APCompactArray<SSClause,SSClause,ACompareAddress<SSClause> > *)(v14 + 16);
  }
  else
  {
    v39 = 0i64;
  }
  LODWORD(v47) = 0;
  v16 = v8;
  v34 = v8;
  LOBYTE(v46) = 0;
  LODWORD(v17) = end_pos_p;
  do
  {
    v18 = SSParser::parse_ws_any(v3, v16, &v34);
    v2->i_result = v18;
    LOBYTE(end_pos_p) = 0;
    v19 = 0i64;
    if ( v18 )
    {
      v16 = v34;
      continue;
    }
    v2->i_result = 24;
    v16 = v34;
    if ( v37 - v34 < 3 )
      break;
    if ( v13[v34] == 101
      && v13[v34 + 1] == 108
      && v13[v34 + 2] == 115
      && v13[v34 + 3] == 101
      && (v20 = v34 + 4, byte_14236F1C0[(unsigned __int8)v13[v20]]) )
    {
      v16 = v34 + 4;
      v34 += 4;
      v21 = 80;
      if ( v4 )
        v21 = 0;
      v2->i_result = v21;
      LOBYTE(end_pos_p) = 1;
      LOBYTE(v46) = 1;
    }
    else
    {
      v22 = v3->i_context.i_top_scope_old.i_count;
      sorted.i_count = v22;
      if ( (unsigned int)v22 <= (unsigned int)v17 )
      {
        v24 = sorted.i_array_p;
      }
      else
      {
        AMemory::c_free_func(sorted.i_array_p);
        v23 = AMemory::c_req_byte_size_func(8 * v22);
        v17 = (unsigned __int64)v23 >> 3;
        sorted.i_size = v23 >> 3;
        v24 = APArrayBase<SSTypedName>::alloc_array(v23 >> 3);
        sorted.i_array_p = v24;
      }
      memmove(v24, v3->i_context.i_top_scope_old.i_array_p, 8 * v22);
      v2->i_start_pos = v16;
      v19 = SSParser::parse_expression(v3, v2, SSInvokeTime_immediate);
      v16 = v2->i_end_pos;
      v34 = v2->i_end_pos;
      if ( v3->i_flags.i_flagset & 1 )
      {
        if ( v2->i_result )
          goto LABEL_53;
        if ( !v2->i_type_p->vfptr->is_class_type(v2->i_type_p, (SSClassDescBase *)&v40->vfptr) )
        {
          v2->i_result = 126;
          goto LABEL_53;
        }
      }
    }
    if ( v2->i_result == Result_ok )
    {
      v25 = SSParser::parse_ws_any(v3, v16, &v34);
      v2->i_result = v25;
      if ( v25 )
      {
        v16 = v34;
      }
      else
      {
        v2->i_result = 24;
        v16 = v34;
        if ( v13[v34] == 91 )
        {
          if ( v3->i_flags.i_flagset & 1 )
            SSTypeContext::nest_locals(&v3->i_context);
          LOBYTE(end_pos_p) = 1;
          v2->i_start_pos = v16;
          v26 = SSParser::parse_code_block_optimized(v3, v2, SSInvokeTime_any, ResultDesired_true);
          v16 = v2->i_end_pos;
          v34 = v2->i_end_pos;
          if ( v2->i_result )
            goto LABEL_86;
          v35 = v16;
          LODWORD(v47) = v47 + 1;
          if ( v39 )
          {
            v27 = (SSClause *)AMemory::c_malloc_func(0x18ui64, "SSClause");
            v44 = v27;
            if ( v27 )
            {
              v27->vfptr = (SSClauseVtbl *)&SSClause::`vftable';
              v27->i_test_p = v19;
              v27->i_clause_p = (SSExpressionBase *)&v26->vfptr;
            }
            APCompactArray<SSClause,SSClause,ACompareAddress<SSClause>>::append(v39, v27);
          }
          if ( v3->i_flags.i_flagset & 1
            && ((SSClassUnion::merge_class(&class_union, v2->i_type_p), merge_vars_p.i_count)
             || v3->i_context.i_current_scope_p->i_count) )
          {
            v28 = v47;
            SSTypeContext::merge_locals(&v3->i_context, &merge_vars_p, (_DWORD)v47 == 1);
          }
          else
          {
LABEL_86:
            v28 = v47;
          }
          if ( v3->i_flags.i_flagset & 1 )
          {
            AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>::free_last(&v3->i_context.i_scope_stack);
            v3->i_context.i_current_scope_p = (APSortedLogical<SSTypedName,ASymbol> *)&v3->i_context.i_scope_stack.i_sentinel.i_prev_p[1];
          }
          goto LABEL_54;
        }
      }
    }
LABEL_53:
    v28 = v47;
LABEL_54:
    if ( (_BYTE)v46 )
      goto LABEL_59;
    v4 = v47;
  }
  while ( v2->i_result == Result_ok );
  v28 = v47;
LABEL_59:
  v5 = (void (__fastcall ***)(_QWORD, signed __int64))v38;
  if ( v2->i_result == Result_ok )
  {
    v8 = v35;
LABEL_70:
    v31 = sorted.i_array_p;
    goto LABEL_71;
  }
  if ( v19 )
    v19->vfptr->__vecDelDtor(v19, 1u);
  if ( (_BYTE)end_pos_p || v28 < 1 )
  {
    v8 = v16;
    if ( v5 )
    {
      (**v5)(v5, 1i64);
      v5 = 0i64;
    }
    goto LABEL_70;
  }
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::remove_all_all(
    (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v3->i_context.i_top_scope_old.i_count,
    &sorted,
    0,
    0xFFFFFFFF);
  APSizedArrayBase<SSTypedName>::free_all((APSizedArrayBase<SSTypedName> *)&v3->i_context.i_top_scope_old.i_count);
  v29 = sorted.i_count;
  v3->i_context.i_top_scope_old.i_count = sorted.i_count;
  if ( v29 > v3->i_context.i_top_scope_old.i_size )
  {
    AMemory::c_free_func(v3->i_context.i_top_scope_old.i_array_p);
    v30 = AMemory::c_req_byte_size_func(8 * v3->i_context.i_top_scope_old.i_count) >> 3;
    v3->i_context.i_top_scope_old.i_size = v30;
    v3->i_context.i_top_scope_old.i_array_p = APArrayBase<SSTypedName>::alloc_array(v30);
  }
  v31 = sorted.i_array_p;
  memmove(v3->i_context.i_top_scope_old.i_array_p, sorted.i_array_p, 8i64 * v3->i_context.i_top_scope_old.i_count);
  v2->i_result = 0;
  v8 = v35;
LABEL_71:
  if ( v3->i_flags.i_flagset & 1 )
  {
    if ( v2->i_result == Result_ok )
    {
      if ( !(_BYTE)v46 )
      {
        SSTypeContext::merge(&v3->i_context, &merge_vars_p);
        SSClassUnion::merge_class(&class_union, (SSClassUnaryBase *)&SSBrain::c_none_class_p->vfptr);
      }
      if ( class_union.i_union.i_count > 1 )
        v32 = (SSClassUnaryBase *)SSClassUnion::get_or_create(&class_union);
      else
        v32 = class_union.i_common_class_p;
      v2->i_type_p = (SSClassDescBase *)&v32->vfptr;
      SSTypeContext::change_variable_types(&v3->i_context, &merge_vars_p);
    }
    APSizedArrayBase<SSTypedName>::free_all((APSizedArrayBase<SSTypedName> *)&merge_vars_p.i_count);
  }
  AMemory::c_free_func(v31);
  AMemory::c_free_func(merge_vars_p.i_array_p);
  SSClassUnion::~SSClassUnion(&class_union);
LABEL_81:
  v2->i_end_pos = v8;
  return (SSCase *)v5;
}

// File Line: 634
// RVA: 0x1278A0
SSParser::eResult __fastcall SSParser::parse_class(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSClass **class_pp)
{
  SSClass **v4; // rbx
  SSParser::eResult result; // eax
  SSClass **v6; // r8
  SSClass **v7; // r10
  signed __int64 v8; // rdx
  unsigned int v9; // er9
  _BOOL8 v10; // r9
  ASymbol name_p; // [rsp+30h] [rbp-18h]

  v4 = class_pp;
  name_p.i_uid = -1;
  result = SSParser::parse_name_class(this, start_pos, end_pos_p, &name_p, ClassCheck_no_validate_meta);
  if ( result == Result_ok )
  {
    if ( !SSBrain::c_classes.i_count )
      return 112;
    v6 = SSBrain::c_classes.i_array_p;
    v7 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
    while ( 1 )
    {
      v8 = (signed __int64)&v6[((char *)v7 - (char *)v6) >> 4];
      v9 = *(_DWORD *)(*(_QWORD *)v8 + 8i64);
      if ( name_p.i_uid < v9 )
        goto LABEL_17;
      v10 = name_p.i_uid != v9;
      if ( !v10 )
      {
        if ( *(_QWORD *)v8 )
        {
          result = 0;
          if ( v4 )
            *v4 = *(SSClass **)v8;
          return result;
        }
        return 112;
      }
      if ( v10 < 0 )
      {
LABEL_17:
        if ( v6 == (SSClass **)v8 )
          return 112;
        v7 = (SSClass **)(v8 - 8);
      }
      else
      {
        if ( v7 == (SSClass **)v8 )
          return 112;
        v6 = (SSClass **)(v8 + 8);
      }
    }
  }
  return result;
}

// File Line: 688
// RVA: 0x127D80
__int64 __fastcall SSParser::parse_class_instance(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSClassUnaryBase **class_pp, bool *item_type_b_p)
{
  SSTypedClass **v5; // r14
  unsigned int v6; // esi
  SSParser *v7; // r15
  SSParser::eResult v8; // edi
  bool v9; // r13
  AStringRef *v10; // rax
  char *v11; // rbx
  eSSInvokeTime v12; // er12
  unsigned __int8 v13; // cl
  SSClass *v14; // rax
  unsigned int v15; // eax
  SSParameters *v16; // r9
  SSParameterBase **v17; // rbx
  SSParameterBase **v18; // rsi
  SSParameters *v19; // rax
  unsigned int find_pos_p; // [rsp+30h] [rbp-50h]
  SSClass *class_ppa; // [rsp+38h] [rbp-48h]
  __int64 v23; // [rsp+40h] [rbp-40h]
  SSParameters params_p; // [rsp+48h] [rbp-38h]
  unsigned int end_pos_pa; // [rsp+C0h] [rbp+40h]
  bool v26; // [rsp+C8h] [rbp+48h]
  unsigned int *v27; // [rsp+D0h] [rbp+50h]

  v27 = end_pos_p;
  v23 = -2i64;
  v5 = (SSTypedClass **)class_pp;
  v6 = start_pos;
  v7 = this;
  v8 = 82;
  end_pos_pa = start_pos;
  v9 = 0;
  v26 = 0;
  v10 = this->i_str_ref_p;
  if ( this->i_str_ref_p->i_length <= start_pos )
    goto LABEL_36;
  v8 = 19;
  v11 = v10->i_cstr_p;
  v12 = 1;
  v13 = v10->i_cstr_p[start_pos];
  if ( v13 == 40 )
    goto LABEL_14;
  if ( v13 == 43 || v13 == 95 )
  {
    v12 = 2;
    end_pos_pa = start_pos + 1;
LABEL_14:
    params_p.i_ref_count = 0;
    params_p.i_params.i_count = 0;
    params_p.i_params.i_array_p = 0i64;
    class_ppa = (SSClass *)&params_p.i_return_params;
    params_p.i_return_params.i_count = 0;
    params_p.i_return_params.i_array_p = 0i64;
    params_p.i_result_type_p.i_obj_p = (SSClassDescBase *)&SSBrain::c_object_class_p->vfptr;
    if ( SSBrain::c_object_class_p )
      (*(void (__fastcall **)(SSClass *, signed __int64))SSBrain::c_object_class_p->vfptr->gap8)(
        SSBrain::c_object_class_p,
        2i64);
    v15 = 0;
    if ( v12 == 2 )
      v15 = 2;
    v16 = &params_p;
    if ( !v5 )
      v16 = 0i64;
    v8 = SSParser::parse_parameters(v7, end_pos_pa, &end_pos_pa, v16, v15);
    if ( v8 == Result_ok && v5 )
    {
      if ( params_p.i_params.i_count )
      {
        v17 = params_p.i_params.i_array_p;
        v18 = &params_p.i_params.i_array_p[params_p.i_params.i_count];
        if ( params_p.i_params.i_array_p < v18 )
        {
          while ( !((unsigned __int8 (*)(void))(*v17)->vfptr->is_defaultable)() )
          {
            ++v17;
            if ( v17 >= v18 )
              goto LABEL_29;
          }
          if ( SSParameters::is_generic(&params_p) )
            v8 = 8;
        }
      }
LABEL_29:
      v19 = SSParameters::get_or_create(&params_p);
      *v5 = (SSTypedClass *)SSInvokableClass::get_or_create(SSBrain::c_closure_class_p, v19, v12);
    }
    APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&params_p.i_params.i_count);
    APCompactArrayBase<SSTypedName>::free_all((APCompactArrayBase<SSTypedName> *)&params_p.i_return_params.i_count);
    if ( params_p.i_result_type_p.i_obj_p )
      (*(void (**)(void))&params_p.i_result_type_p.i_obj_p->vfptr->gap8[8])();
    AMemory::c_free_func(params_p.i_return_params.i_array_p);
    class_ppa = (SSClass *)&params_p.i_params;
    AMemory::c_free_func(params_p.i_params.i_array_p);
LABEL_33:
    if ( v8 )
      goto LABEL_36;
    goto LABEL_34;
  }
  if ( !AString::c_is_uppercase[v13] )
    goto LABEL_36;
  find_pos_p = start_pos + 1;
  AString::find((AString *)&v7->i_str_ref_p, ACharMatch_not_identifier, 1u, &find_pos_p, start_pos + 1, 0xFFFFFFFF);
  if ( v11[find_pos_p] == 123 )
  {
    v8 = SSParser::parse_class_typed(v7, v6, &end_pos_pa, v5, &v26);
    v9 = v26;
    goto LABEL_33;
  }
  class_ppa = 0i64;
  v8 = SSParser::parse_class(v7, v6, &end_pos_pa, &class_ppa);
  if ( v8 )
    goto LABEL_36;
  if ( v5 )
  {
    v14 = class_ppa;
    if ( class_ppa == SSBrain::c_list_class_p )
      v14 = (SSClass *)SSTypedClass::get_or_create(
                         SSBrain::c_list_class_p,
                         (SSClassDescBase *)&SSBrain::c_object_class_p->vfptr);
    *v5 = (SSTypedClass *)v14;
  }
LABEL_34:
  if ( item_type_b_p )
    *item_type_b_p = v9;
LABEL_36:
  if ( v27 )
    *v27 = end_pos_pa;
  return (unsigned int)v8;
}

// File Line: 838
// RVA: 0x127CA0
__int64 __fastcall SSParser::parse_class_desc(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSClassDescBase **type_pp)
{
  AStringRef *v4; // rbp
  unsigned int v5; // ebx
  SSClassDescBase **v6; // r14
  unsigned int *v7; // rsi
  SSParser *v8; // rdi
  SSParser::eResult v9; // er10
  char *v10; // rbp
  unsigned int find_pos_p; // [rsp+50h] [rbp+8h]
  unsigned int end_pos_pa; // [rsp+58h] [rbp+10h]

  v4 = this->i_str_ref_p;
  v5 = start_pos;
  v6 = type_pp;
  v7 = end_pos_p;
  v8 = this;
  v9 = 82;
  end_pos_pa = start_pos;
  if ( v4->i_length > start_pos )
  {
    v10 = v4->i_cstr_p;
    if ( v10[start_pos] == 60 )
    {
      find_pos_p = start_pos + 1;
      AString::find(
        (AString *)&this->i_str_ref_p,
        ACharMatch_not_identifier,
        1u,
        &find_pos_p,
        start_pos + 1,
        0xFFFFFFFF);
      if ( v10[find_pos_p] == 62 )
        v9 = SSParser::parse_class_meta(v8, v5, &end_pos_pa, (SSMetaClass **)v6);
      else
        v9 = SSParser::parse_class_union(v8, v5, &end_pos_pa, (SSClassUnion **)v6);
    }
    else
    {
      v9 = SSParser::parse_class_instance(this, start_pos, &end_pos_pa, (SSClassUnaryBase **)type_pp, 0i64);
      if ( end_pos_pa == v5 && v9 == 19 )
        v9 = 16;
    }
  }
  if ( v7 )
    *v7 = end_pos_pa;
  return (unsigned int)v9;
}

// File Line: 905
// RVA: 0x128010
__int64 __fastcall SSParser::parse_class_meta(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSMetaClass **mclass_pp)
{
  __int64 v4; // rdi
  AStringRef *v5; // rdx
  unsigned int v6; // er10
  unsigned int *v7; // r14
  SSMetaClass **v8; // r15
  SSParser *v9; // rsi
  unsigned int v10; // ebx
  char *v11; // rbp
  unsigned int v12; // eax
  ASymbol *v13; // rax
  SSClass **v14; // r8
  SSClass **v15; // r10
  signed __int64 v16; // rcx
  unsigned int v17; // er9
  _BOOL8 v18; // r9
  __int64 v19; // rcx
  __int64 v20; // rax
  ASymbol result; // [rsp+60h] [rbp+8h]
  unsigned int find_pos_p; // [rsp+68h] [rbp+10h]

  v4 = start_pos;
  v5 = this->i_str_ref_p;
  v6 = this->i_str_ref_p->i_length;
  v7 = end_pos_p;
  v8 = mclass_pp;
  v9 = this;
  v10 = 82;
  if ( v6 - (unsigned int)v4 < 3 )
    goto LABEL_24;
  v11 = v5->i_cstr_p;
  v10 = 20;
  if ( v5->i_cstr_p[v4] != 60 )
    goto LABEL_24;
  v4 = (unsigned int)(v4 + 1);
  v12 = -1;
  v10 = 82;
  find_pos_p = v4;
  if ( v6 > (unsigned int)v4 )
  {
    v10 = 15;
    if ( AString::c_is_uppercase[(unsigned __int8)v11[v4]] )
    {
      find_pos_p = v6;
      AString::find((AString *)&this->i_str_ref_p, ACharMatch_not_identifier, 1u, &find_pos_p, v4 + 1, 0xFFFFFFFF);
      v13 = SSParser::as_symbol(v9, &result, v4, find_pos_p);
      LODWORD(v4) = find_pos_p;
      v10 = 0;
      v12 = v13->i_uid;
      if ( v12 == ASymbol_Class.i_uid )
        v10 = 74;
    }
  }
  if ( v10 )
    goto LABEL_19;
  v10 = 112;
  if ( !SSBrain::c_classes.i_count )
    goto LABEL_19;
  v14 = SSBrain::c_classes.i_array_p;
  v15 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
  while ( 1 )
  {
    v16 = (signed __int64)&v14[((char *)v15 - (char *)v14) >> 4];
    v17 = *(_DWORD *)(*(_QWORD *)v16 + 8i64);
    if ( v12 < v17 )
      goto LABEL_15;
    v18 = v12 != v17;
    if ( !v18 )
      break;
    if ( v18 < 0 )
    {
LABEL_15:
      if ( v14 == (SSClass **)v16 )
        goto LABEL_19;
      v15 = (SSClass **)(v16 - 8);
    }
    else
    {
      if ( v15 == (SSClass **)v16 )
        goto LABEL_19;
      v14 = (SSClass **)(v16 + 8);
    }
  }
  v19 = *(_QWORD *)v16;
  if ( v19 )
  {
    v10 = 0;
    goto LABEL_20;
  }
LABEL_19:
  v19 = *(_QWORD *)&result.i_uid;
LABEL_20:
  if ( !v10 )
  {
    v10 = 21;
    if ( v11[(unsigned int)v4] == 62 )
    {
      LODWORD(v4) = v4 + 1;
      v10 = 0;
      if ( v8 )
        *v8 = (SSMetaClass *)(*(__int64 (**)(void))(*(_QWORD *)v19 + 136i64))();
    }
  }
LABEL_24:
  v20 = v10;
  if ( v7 )
    *v7 = v4;
  return v20;
}

// File Line: 977
// RVA: 0x1281B0
__int64 __fastcall SSParser::parse_class_typed(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSTypedClass **tclass_pp, bool *item_type_b_p)
{
  AStringRef *v5; // r10
  unsigned int v6; // esi
  unsigned int v7; // eax
  SSParser *v8; // r12
  SSTypedClass **v9; // r13
  SSParser::eResult v10; // edi
  ASymbol *v11; // rax
  SSClass **v12; // r8
  SSClass **v13; // r10
  signed __int64 v14; // rdx
  unsigned int v15; // er9
  _BOOL8 v16; // rcx
  _BOOL8 v17; // r9
  SSClass *v18; // rbp
  SSClass *v19; // rcx
  char *v20; // r15
  SSClassDescBase **v21; // r9
  bool v22; // r14
  SSParser::eResult v23; // eax
  ASymbol result[2]; // [rsp+30h] [rbp-48h]
  unsigned int v26; // [rsp+80h] [rbp+8h]
  unsigned int end_pos_pa; // [rsp+88h] [rbp+10h]
  unsigned int *v28; // [rsp+90h] [rbp+18h]

  v28 = end_pos_p;
  v5 = this->i_str_ref_p;
  v6 = start_pos;
  v7 = -1;
  v26 = start_pos;
  v8 = this;
  v9 = tclass_pp;
  v10 = 82;
  if ( v5->i_length > start_pos )
  {
    v10 = 15;
    if ( AString::c_is_uppercase[(unsigned __int8)v5->i_cstr_p[start_pos]] )
    {
      v26 = start_pos + 1;
      v26 = v5->i_length;
      AString::find((AString *)&this->i_str_ref_p, ACharMatch_not_identifier, 1u, &v26, start_pos + 1, 0xFFFFFFFF);
      v11 = SSParser::as_symbol(v8, result, v6, v26);
      v6 = v26;
      v10 = 0;
      v7 = v11->i_uid;
      if ( v7 == ASymbol_Class.i_uid )
        v10 = 74;
    }
  }
  end_pos_pa = v6;
  if ( v10 )
    goto LABEL_17;
  v10 = 112;
  if ( !SSBrain::c_classes.i_count )
    goto LABEL_17;
  v12 = SSBrain::c_classes.i_array_p;
  v13 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
  while ( 1 )
  {
    v14 = (signed __int64)&v12[((char *)v13 - (char *)v12) >> 4];
    v15 = *(_DWORD *)(*(_QWORD *)v14 + 8i64);
    if ( v7 < v15 )
      goto LABEL_13;
    v16 = v7 == v15;
    v17 = v7 != v15;
    if ( v16 == 1 )
      break;
    if ( v17 < 0 )
    {
LABEL_13:
      if ( v12 == (SSClass **)v14 )
        goto LABEL_17;
      v13 = (SSClass **)(v14 - 8);
    }
    else
    {
      if ( v13 == (SSClass **)v14 )
        goto LABEL_17;
      v12 = (SSClass **)(v14 + 8);
    }
  }
  v18 = *(SSClass **)v14;
  if ( *(_QWORD *)v14 )
  {
    v10 = 0;
    goto LABEL_18;
  }
LABEL_17:
  v18 = (SSClass *)v28;
LABEL_18:
  if ( v10 == Result_ok )
  {
    v10 = 134;
    if ( SSBrain::c_list_class_p == v18
      || (v19 = v18->i_superclass_p) != 0i64 && SSClass::is_class(v19, SSBrain::c_list_class_p) )
    {
      v10 = 17;
      v20 = v8->i_str_ref_p->i_cstr_p;
      if ( v8->i_str_ref_p->i_cstr_p[v6] == 123 )
      {
        v10 = SSParser::parse_ws_any(v8, v6 + 1, &end_pos_pa);
        if ( v10 )
          goto LABEL_37;
        v21 = (SSClassDescBase **)result;
        if ( !v9 )
          v21 = 0i64;
        v22 = 1;
        *(_QWORD *)&result[0].i_uid = SSBrain::c_object_class_p;
        v23 = (unsigned int)SSParser::parse_class_desc(v8, end_pos_pa, &v26, v21);
        v6 = v26;
        v10 = v23;
        if ( v26 == end_pos_pa )
        {
          v22 = 0;
          v10 = 0;
        }
        end_pos_pa = v26;
        if ( v10 == Result_ok )
        {
          if ( v22 )
          {
            v10 = SSParser::parse_ws_any(v8, v26, &end_pos_pa);
            if ( v10 == Result_ok )
            {
              v6 = end_pos_pa;
              goto LABEL_32;
            }
LABEL_37:
            v6 = end_pos_pa;
          }
          else
          {
LABEL_32:
            v10 = 18;
            if ( v20[v6] == 125 )
            {
              ++v6;
              v10 = 0;
              if ( v9 )
                *v9 = SSTypedClass::get_or_create(v18, *(SSClassDescBase **)&result[0].i_uid);
              if ( item_type_b_p )
                *item_type_b_p = v22;
            }
          }
        }
      }
    }
  }
  if ( v28 )
    *v28 = v6;
  return (unsigned int)v10;
}

// File Line: 1095
// RVA: 0x128450
__int64 __fastcall SSParser::parse_class_union(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSClassUnion **type_pp)
{
  SSClassUnion **v4; // r12
  unsigned int *v5; // r13
  unsigned int v6; // ebx
  SSParser *v7; // r15
  unsigned int v8; // esi
  char *v9; // rbp
  SSClassUnaryBase **v10; // rdi
  unsigned int v11; // er14
  __int64 v12; // rbx
  unsigned int v13; // eax
  SSClassUnaryBase **v14; // r14
  __int64 *v15; // rdi
  SSClassUnaryBase **v16; // rbp
  __int64 result; // rax
  SSClassUnion class_union; // [rsp+38h] [rbp-70h]
  SSClassUnaryBase *new_class; // [rsp+B0h] [rbp+8h]
  unsigned int end_pos_pa; // [rsp+B8h] [rbp+10h]

  v4 = type_pp;
  v5 = end_pos_p;
  v6 = start_pos;
  v7 = this;
  v8 = 82;
  if ( this->i_str_ref_p->i_length - start_pos >= 3 )
  {
    v9 = this->i_str_ref_p->i_cstr_p;
    v8 = 22;
    if ( v9[start_pos] == 60 )
    {
      class_union.i_ref_count = 0;
      class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
      class_union.i_common_class_p = 0i64;
      class_union.i_union.i_count = 0;
      class_union.i_union.i_array_p = 0i64;
      class_union.i_union.i_size = 0;
      new_class = 0i64;
      v10 = &new_class;
      if ( !type_pp )
        v10 = 0i64;
      v11 = 0;
      do
      {
        v12 = v6 + 1;
        end_pos_pa = v12;
        if ( v9[v12] == 60 )
          v13 = SSParser::parse_class_meta(v7, v12, &end_pos_pa, (SSMetaClass **)v10);
        else
          v13 = SSParser::parse_class_instance(v7, v12, &end_pos_pa, v10, 0i64);
        v8 = v13;
        if ( v13 )
        {
          v6 = end_pos_pa;
          goto LABEL_19;
        }
        ++v11;
        if ( v10 )
          SSClassUnion::merge_class(&class_union, new_class);
        v6 = end_pos_pa;
      }
      while ( v9[end_pos_pa] == 124 );
      v8 = 23;
      if ( v9[end_pos_pa] == 62 )
      {
        v6 = end_pos_pa + 1;
        v8 = 91;
        if ( v11 >= 2 )
        {
          v8 = 0;
          if ( v4 )
          {
            v8 = 139;
            if ( class_union.i_union.i_count > 1 )
            {
              v8 = 0;
              *v4 = SSClassUnion::get_or_create(&class_union);
            }
          }
        }
      }
LABEL_19:
      class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
      if ( class_union.i_common_class_p )
        ((void (*)(void))class_union.i_common_class_p->vfptr->dereference_delay)();
      v14 = class_union.i_union.i_array_p;
      if ( class_union.i_union.i_count )
      {
        v15 = (__int64 *)class_union.i_union.i_array_p;
        v16 = &class_union.i_union.i_array_p[class_union.i_union.i_count];
        if ( class_union.i_union.i_array_p < v16 )
        {
          do
          {
             SSClassDescBase::`vcall'{24,{flat}}(*v15);
            ++v15;
          }
          while ( v15 < (__int64 *)v16 );
        }
      }
      AMemory::c_free_func(v14);
      class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable';
    }
  }
  result = v8;
  if ( v5 )
    *v5 = v6;
  return result;
}

// File Line: 1206
// RVA: 0x127960
SSExpressionBase *__fastcall SSParser::parse_class_cast(SSParser *this, SSParser::Args *args, SSExpressionBase *receiver_p)
{
  SSExpressionBase *v3; // rbp
  SSParser::Args *v4; // rdi
  SSParser *v5; // rsi
  char *v6; // rdx
  __int64 v7; // r10
  SSExpressionBase *v8; // rbx
  SSParser::eResult v9; // eax
  SSClassDescBase *v10; // rsi
  SSClassDescBase *v11; // rax
  SSExpressionBase *v12; // rax
  unsigned int end_pos_p; // [rsp+50h] [rbp+8h]
  SSClassDescBase *type_pp; // [rsp+58h] [rbp+10h]

  v3 = receiver_p;
  v4 = args;
  v5 = this;
  v6 = this->i_str_ref_p->i_cstr_p;
  end_pos_p = v4->i_start_pos;
  v7 = end_pos_p;
  v8 = 0i64;
  v4->i_result = 12;
  if ( (unsigned int)(this->i_str_ref_p->i_length - v7) >= 2 && v6[v7] == 60 && v6[(unsigned int)(v7 + 1)] == 62 )
  {
    v9 = SSParser::parse_class_desc(this, v7 + 2, &end_pos_p, &type_pp);
    v4->i_result = v9;
    if ( v9 == Result_ok )
    {
      if ( v5->i_flags.i_flagset & 1 )
      {
        if ( type_pp )
          v10 = type_pp->vfptr->as_finalized_generic(type_pp, (SSClassDescBase *)v5->i_context.i_obj_scope_p);
        else
          v10 = 0i64;
        if ( v4->i_type_p->vfptr->is_class_type(v4->i_type_p, v10) )
        {
          v8 = v3;
          goto LABEL_17;
        }
        if ( !v10->vfptr->is_class_type(v10, v4->i_type_p) )
        {
          v4->i_result = 127;
          goto LABEL_17;
        }
      }
      else
      {
        v10 = type_pp;
      }
      v4->i_type_p = v10;
      if ( v4->i_flags & 1 )
      {
        v11 = (SSClassDescBase *)AMemory::c_malloc_func(0x18ui64, "SSCast");
        type_pp = v11;
        if ( v11 )
        {
          SSCast::SSCast((SSCast *)v11, v10, v3);
          v8 = v12;
        }
      }
    }
LABEL_17:
    LODWORD(v7) = end_pos_p;
  }
  v4->i_end_pos = v7;
  return v8;
}

// File Line: 1308
// RVA: 0x127A90
SSExpressionBase *__fastcall SSParser::parse_class_conversion(SSParser *this, SSParser::Args *args, SSExpressionBase *receiver_p, __int64 a4)
{
  SSExpressionBase *v4; // r15
  SSParser::Args *v5; // rsi
  SSParser *v6; // r14
  char *v7; // rdx
  __int64 v8; // rbp
  SSExpressionBase *v9; // rbx
  char *v10; // r8
  unsigned int v11; // er10
  unsigned int v12; // eax
  signed int v13; // er11
  SSClass **v14; // r10
  signed __int64 v15; // rdx
  _BOOL8 v16; // rcx
  ASymbol *v17; // rdi
  SSExpressionBase *v18; // rax
  unsigned int find_pos_p; // [rsp+70h] [rbp+8h]
  ASymbol result; // [rsp+78h] [rbp+10h]

  v4 = receiver_p;
  v5 = args;
  v6 = this;
  v7 = this->i_str_ref_p->i_cstr_p;
  v8 = v5->i_start_pos;
  v9 = 0i64;
  v5->i_result = 27;
  v10 = (char *)this->i_str_ref_p;
  v11 = this->i_str_ref_p->i_length;
  if ( (unsigned int)(this->i_str_ref_p->i_length - v8) < 2 || v7[v8] != 62 || v7[(unsigned int)(v8 + 1)] != 62 )
    goto LABEL_31;
  v8 = (unsigned int)(v8 + 2);
  v12 = -1;
  v13 = 82;
  find_pos_p = v8;
  if ( v11 > (unsigned int)v8 )
  {
    v10 = *(char **)v10;
    v13 = 15;
    a4 = (unsigned __int8)v10[v8];
    if ( AString::c_is_uppercase[a4] )
    {
      find_pos_p = v11;
      AString::find((AString *)&this->i_str_ref_p, ACharMatch_not_identifier, 1u, &find_pos_p, v8 + 1, 0xFFFFFFFF);
      v12 = SSParser::as_symbol(v6, &result, v8, find_pos_p)->i_uid;
      v13 = 0;
      if ( v12 == ASymbol_Class.i_uid )
        v13 = 74;
      LODWORD(v8) = find_pos_p;
    }
  }
  if ( v13 )
    goto LABEL_21;
  v13 = 112;
  if ( !SSBrain::c_classes.i_count )
    goto LABEL_21;
  v10 = (char *)SSBrain::c_classes.i_array_p;
  v14 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
  while ( 1 )
  {
    v15 = (signed __int64)&v10[8 * (((char *)v14 - v10) >> 4)];
    a4 = *(unsigned int *)(*(_QWORD *)v15 + 8i64);
    if ( v12 < (unsigned int)a4 )
      goto LABEL_17;
    v16 = v12 == (_DWORD)a4;
    a4 = v12 != (_DWORD)a4;
    if ( v16 == 1 )
      break;
    if ( a4 < 0 )
    {
LABEL_17:
      if ( v10 == (char *)v15 )
        goto LABEL_21;
      v14 = (SSClass **)(v15 - 8);
    }
    else
    {
      if ( v14 == (SSClass **)v15 )
        goto LABEL_21;
      v10 = (char *)(v15 + 8);
    }
  }
  v17 = *(ASymbol **)v15;
  if ( *(_QWORD *)v15 )
  {
    v13 = 0;
    goto LABEL_22;
  }
LABEL_21:
  v17 = *(ASymbol **)&find_pos_p;
LABEL_22:
  v5->i_result = v13;
  if ( !v13 )
  {
    if ( v6->i_flags.i_flagset & 1 )
    {
      if ( ((unsigned __int8 (__fastcall *)(SSClassDescBase *, ASymbol *, char *, __int64))v5->i_type_p->vfptr->is_class_type)(
             v5->i_type_p,
             v17,
             v10,
             a4) )
      {
        v9 = v4;
        goto LABEL_31;
      }
      if ( !SSParser::get_method_inherited(v6, v5->i_type_p, v17 + 2) )
      {
        v5->i_result = 115;
        goto LABEL_31;
      }
    }
    v5->i_type_p = (SSClassDescBase *)v17;
    if ( v5->i_flags & 1 )
    {
      v18 = (SSExpressionBase *)AMemory::c_malloc_func(0x18ui64, "SSConversion");
      *(_QWORD *)&find_pos_p = v18;
      if ( v18 )
      {
        v18->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
        v18->vfptr = (SSExpressionBaseVtbl *)&SSConversion::`vftable';
        v18[1].vfptr = (SSExpressionBaseVtbl *)v17;
        v18[2].vfptr = (SSExpressionBaseVtbl *)v4;
        v9 = v18;
      }
    }
  }
LABEL_31:
  v5->i_end_pos = v8;
  return v9;
}

// File Line: 1741
// RVA: 0x128610
SSLiteralClosure *__fastcall SSParser::parse_closure(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // rbx
  SSParser *v3; // rsi
  unsigned int v4; // ecx
  __int64 v6; // rdi
  bool v7; // zf
  AStringRef *v8; // rcx
  char *v9; // r15
  __int64 v10; // rdx
  char v11; // cl
  __int64 v12; // r9
  SSParser::eResult v13; // eax
  SSClassDescBase *v14; // rcx
  __int64 v15; // rax
  __int64 v16; // r14
  SSParser::eResult v17; // eax
  SSClass *v18; // rax
  SSParameters *v19; // r12
  unsigned int v20; // ecx
  SSParser::eResult v21; // eax
  SSParser::eResult v22; // eax
  SSClass *v23; // r14
  SSClassDescBase *v24; // rdx
  char v25; // r14
  SSExpressionBase *v26; // r14
  int v27; // er12
  eSSExprType v28; // er15
  __int64 v29; // rax
  SSParameters *v30; // rax
  char *v31; // rax
  __int64 v32; // rax
  SSClosureInfoBase *v33; // rax
  SSLiteralClosure closure_method_p; // [rsp+30h] [rbp-D0h]
  void **v35; // [rsp+50h] [rbp-B0h]
  int v36; // [rsp+58h] [rbp-A8h]
  AVCompactSortedLogical<ASymbol,ASymbol> captured_p; // [rsp+60h] [rbp-A0h]
  SSMethod v38; // [rsp+70h] [rbp-90h]
  SSParameters params_p; // [rsp+A0h] [rbp-60h]
  char v40; // [rsp+D0h] [rbp-30h]
  SSParser *v41; // [rsp+D8h] [rbp-28h]
  SSClassUnaryBase *v42; // [rsp+E0h] [rbp-20h]
  eSSMember v43; // [rsp+E8h] [rbp-18h]
  char v44; // [rsp+ECh] [rbp-14h]
  __int64 v45; // [rsp+F0h] [rbp-10h]
  unsigned int end_pos_p; // [rsp+150h] [rbp+50h]
  void *v47; // [rsp+158h] [rbp+58h]
  void *v48; // [rsp+160h] [rbp+60h]
  SSClassUnaryBase *v49; // [rsp+168h] [rbp+68h]

  v45 = -2i64;
  v2 = args;
  v3 = this;
  v4 = args->i_start_pos;
  end_pos_p = v4;
  if ( v3->i_str_ref_p->i_length < v4 )
  {
    args->i_end_pos = v4;
    args->i_result = 82;
    return 0i64;
  }
  LODWORD(v47) = 3;
  closure_method_p.vfptr = (SSExpressionBaseVtbl *)&SSLiteralClosure::`vftable';
  v6 = 0i64;
  closure_method_p.i_receiver_p = 0i64;
  closure_method_p.i_info_p.i_obj_p = 0i64;
  captured_p.i_count = 0;
  captured_p.i_array_p = 0i64;
  v48 = &v38;
  v38.i_name = ASymbol_closure;
  v38.i_scope_p = SSBrain::c_object_class_p;
  v38.i_params_p.i_obj_p = 0i64;
  v38.i_expr_p = 0i64;
  v35 = &SSClosureInfoMethod::`vftable'{for `SSClosureInfoBase'};
  v38.vfptr = (SSInvokableBaseVtbl *)&SSClosureInfoMethod::`vftable'{for `SSMethod'};
  v36 = 1;
  if ( 0i64 != &v35 )
  {
    v36 = 2;
    if ( closure_method_p.i_info_p.i_obj_p )
    {
      v7 = closure_method_p.i_info_p.i_obj_p->i_ref_count-- == 1;
      if ( v7 )
        MEMORY[8] = 2147483648;
    }
    closure_method_p.i_info_p.i_obj_p = (SSClosureInfoBase *)&v35;
  }
  v41 = v3;
  v49 = v3->i_context.i_obj_scope_p;
  v42 = v49;
  v43 = v3->i_member_type;
  v44 = 0;
  v8 = v3->i_str_ref_p;
  v9 = v3->i_str_ref_p->i_cstr_p;
  if ( v9[end_pos_p] != 64 )
    goto LABEL_31;
  v10 = end_pos_p + 1;
  end_pos_p = v10;
  if ( v8->i_length >= (unsigned int)v10 )
  {
    v11 = v9[v10];
    if ( v11 == 39 )
    {
      v2->i_end_pos = v10;
      v2->i_result = 86;
      goto LABEL_71;
    }
    if ( v11 == 95 )
    {
      v12 = (unsigned int)(v10 + 1);
      if ( !AString::c_is_lowercase[(unsigned __int8)v9[v12]] )
      {
        end_pos_p = v10 + 1;
        LODWORD(v47) = 2;
        v13 = SSParser::parse_ws_any(v3, v12, &end_pos_p);
        v2->i_result = v13;
        if ( v13 )
        {
          v2->i_end_pos = end_pos_p;
          goto LABEL_71;
        }
        LODWORD(v10) = end_pos_p;
      }
    }
    v2->i_start_pos = v10;
    if ( v9[(unsigned int)v10] != 91 )
    {
      closure_method_p.i_receiver_p = SSParser::parse_expression(v3, v2, SSInvokeTime_immediate);
      if ( v2->i_result )
        goto LABEL_71;
      v14 = v2->i_type_p;
      if ( v14 )
        v15 = (__int64)v14->vfptr->as_finalized_generic(v14, (SSClassDescBase *)&v3->i_context.i_obj_scope_p->vfptr);
      else
        v15 = 0i64;
      v16 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 40i64))(v15);
      v17 = SSParser::parse_ws_any(v3, v2->i_end_pos, &end_pos_p);
      v2->i_result = v17;
      if ( v17 )
      {
        v2->i_end_pos = end_pos_p;
        goto LABEL_71;
      }
      if ( v3->i_context.i_obj_scope_p != (SSClassUnaryBase *)v16 )
      {
        v18 = SSBrain::c_object_class_p;
        if ( v16 )
          v18 = (SSClass *)v16;
        v3->i_context.i_obj_scope_p = (SSClassUnaryBase *)&v18->vfptr;
      }
    }
LABEL_31:
    v3->i_member_type = 3;
    if ( v3->i_flags.i_flagset & 1 )
    {
      SSTypeContext::capture_locals(&v3->i_context);
      v44 = 1;
    }
    params_p.i_ref_count = 0;
    params_p.i_params.i_count = 0;
    params_p.i_params.i_array_p = 0i64;
    v48 = &params_p.i_return_params;
    params_p.i_return_params.i_count = 0;
    params_p.i_return_params.i_array_p = 0i64;
    params_p.i_result_type_p.i_obj_p = (SSClassDescBase *)&SSBrain::c_object_class_p->vfptr;
    if ( SSBrain::c_object_class_p )
      (*(void (**)(void))SSBrain::c_object_class_p->vfptr->gap8)();
    v19 = &params_p;
    if ( !(v2->i_flags & 1) )
      v19 = 0i64;
    v20 = end_pos_p;
    LODWORD(v48) = end_pos_p;
    if ( v9[end_pos_p] == 40 )
    {
      v21 = SSParser::parse_parameters(v3, end_pos_p, &end_pos_p, v19, 1u);
      v2->i_result = v21;
      if ( v21 )
      {
        v2->i_end_pos = end_pos_p;
LABEL_68:
        APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&params_p.i_params.i_count);
        APCompactArrayBase<SSTypedName>::free_all((APCompactArrayBase<SSTypedName> *)&params_p.i_return_params.i_count);
        if ( params_p.i_result_type_p.i_obj_p )
          (*(void (**)(void))&params_p.i_result_type_p.i_obj_p->vfptr->gap8[8])();
        v47 = &params_p.i_return_params;
        AMemory::c_free_func(params_p.i_return_params.i_array_p);
        v47 = &params_p.i_params;
        AMemory::c_free_func(params_p.i_params.i_array_p);
        goto LABEL_71;
      }
      v22 = SSParser::parse_ws_any(v3, end_pos_p, &end_pos_p);
      v2->i_result = v22;
      if ( v22 )
      {
        v2->i_end_pos = end_pos_p;
        goto LABEL_68;
      }
      v20 = end_pos_p;
    }
    else
    {
      v23 = SSBrain::c_auto_class_p;
      v24 = params_p.i_result_type_p.i_obj_p;
      if ( (SSClass *)params_p.i_result_type_p.i_obj_p != SSBrain::c_auto_class_p )
      {
        if ( SSBrain::c_auto_class_p )
        {
          (*(void (__fastcall **)(SSClass *))SSBrain::c_auto_class_p->vfptr->gap8)(SSBrain::c_auto_class_p);
          v20 = end_pos_p;
          v24 = params_p.i_result_type_p.i_obj_p;
        }
        if ( v24 )
        {
          (*(void (__fastcall **)(SSClassDescBase *))&v24->vfptr->gap8[8])(v24);
          v20 = end_pos_p;
        }
        params_p.i_result_type_p.i_obj_p = (SSClassDescBase *)&v23->vfptr;
      }
    }
    v2->i_start_pos = v20;
    v38.i_expr_p = (SSExpressionBase *)SSParser::parse_code_block_optimized(
                                         v3,
                                         v2,
                                         SSInvokeTime_any,
                                         ResultDesired_true);
    v25 = 0;
    if ( v2->i_result == Result_ok )
    {
      v25 = SSParser::typecheck_parameters(v3, v2, v19, 1) && v38.i_expr_p ? 1 : 0;
      if ( SSParameters::is_generic(v19) )
      {
        v25 = 0;
        v2->i_end_pos = (unsigned int)v48;
        v2->i_result = 128;
      }
    }
    if ( !v25 )
      goto LABEL_68;
    SSTypeContext::capture_locals_stop(&v3->i_context, &captured_p);
    v44 = 0;
    v26 = v38.i_expr_p;
    v27 = (signed int)v47;
    if ( (_DWORD)v47 == 3 )
    {
      if ( !v38.i_expr_p )
      {
        v27 = 1;
        goto LABEL_62;
      }
      v27 = 2 - (v38.i_expr_p->vfptr->is_immediate(v38.i_expr_p, 0i64) != 0);
    }
    if ( v27 != 1 )
    {
      v28 = 8;
      if ( v26 )
      {
        v29 = (__int64)v26->vfptr->find_expr_last_no_side_effect(v26);
        if ( v29 )
        {
          v2->i_result = ((*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v29 + 24i64))(v29) == 1) + 6;
          goto LABEL_68;
        }
      }
LABEL_66:
      v38.i_scope_p = (SSClass *)((__int64 (*)(void))v49->vfptr->get_key_class)();
      v38.i_name.i_uid = v3->i_context.i_scope_name.i_uid;
      v30 = SSParameters::get_or_create(&params_p);
      ARefPtr<SSParameters>::operator=(&v38.i_params_p, v30);
      v2->i_type_p = (SSClassDescBase *)SSInvokableClass::get_or_create(
                                          SSBrain::c_closure_class_p,
                                          v38.i_params_p.i_obj_p,
                                          (eSSInvokeTime)v27);
      v31 = UFG::qMalloc(0x18ui64, "SSLiteralClosure", 0i64);
      v47 = v31;
      if ( v31 )
      {
        SSLiteralClosure::SSLiteralClosure((SSLiteralClosure *)v31, &closure_method_p, v28);
        v6 = v32;
      }
      goto LABEL_68;
    }
LABEL_62:
    v28 = 7;
    goto LABEL_66;
  }
  v2->i_end_pos = v10;
  v2->i_result = 82;
LABEL_71:
  SSParser::parse_closure_::_2_::NestedDtor::_NestedDtor((__int64)&v40);
  v35 = &SSClosureInfoMethod::`vftable'{for `SSClosureInfoBase'};
  v38.vfptr = (SSInvokableBaseVtbl *)&SSClosureInfoMethod::`vftable'{for `SSMethod'};
  SSMethod::~SSMethod(&v38);
  v35 = &SSClosureInfoBase::`vftable';
  v47 = &captured_p;
  AMemory::c_free_func(captured_p.i_array_p);
  closure_method_p.vfptr = (SSExpressionBaseVtbl *)&SSLiteralClosure::`vftable';
  if ( closure_method_p.i_receiver_p )
    closure_method_p.i_receiver_p->vfptr->__vecDelDtor(closure_method_p.i_receiver_p, 1u);
  v33 = closure_method_p.i_info_p.i_obj_p;
  if ( closure_method_p.i_info_p.i_obj_p )
  {
    v7 = closure_method_p.i_info_p.i_obj_p->i_ref_count-- == 1;
    if ( v7 )
    {
      v33->i_ref_count = 2147483648;
      if ( v33 != (SSClosureInfoBase *)-8i64 && &v33->i_ref_count != (unsigned int *)8 )
        v33->vfptr->__vecDelDtor(v33, 1u);
    }
  }
  return (SSLiteralClosure *)v6;
}

// File Line: 1769
// RVA: 0x1069F0
__int64 __fastcall SSParser::parse_closure_::_2_::NestedDtor::_NestedDtor(__int64 a1)
{
  __int64 v1; // rdi
  AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v2; // rsi
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v3; // rbx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v4; // rcx
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v5; // rax
  AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> *v6; // rdx
  __int64 result; // rax

  v1 = a1;
  if ( *(_BYTE *)(a1 + 28) )
  {
    v2 = *(AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> **)(a1 + 8);
    v3 = v2[8].i_sentinel.i_next_p;
    if ( v3 )
    {
      AMemory::c_free_func(v3[1].i_prev_p);
      v4 = v3->i_next_p;
      if ( v3->i_next_p != v3 )
      {
        v5 = v3->i_prev_p;
        v4->i_prev_p = v5;
        v5->i_next_p = v4;
        v3->i_prev_p = v3;
        v3->i_next_p = v3;
      }
      operator delete[](v3);
    }
    v6 = 0i64;
    if ( (AListNode<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars> **)v2[8].i_sentinel.i_next_p != &v2[7].i_sentinel.i_prev_p )
      v6 = v2[8].i_sentinel.i_next_p;
    v2[8].i_sentinel.i_prev_p = v6;
    AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>::free_last(v2 + 6);
    v2[7].i_sentinel.i_next_p = v2[6].i_sentinel.i_prev_p + 1;
  }
  *(_QWORD *)(*(_QWORD *)(v1 + 8) + 16i64) = *(_QWORD *)(v1 + 16);
  result = *(unsigned int *)(v1 + 24);
  *(_DWORD *)(*(_QWORD *)(v1 + 8) + 12i64) = result;
  return result;
}

// File Line: 2080
// RVA: 0x128BF0
SSCode *__fastcall SSParser::parse_code_block(SSParser *this, SSParser::Args *args, eSSInvokeTime desired_exec_time, SSParser::eResultDesired result)
{
  eSSInvokeTime v4; // ebp
  SSParser::Args *v5; // rsi
  SSParser *v6; // r12
  SSCode *v7; // rdi
  char *v8; // r13
  unsigned int v9; // er14
  __int64 v10; // rbx
  SSParser::eResult v11; // eax
  SSCode *v12; // rax
  signed __int64 v13; // ST40_8
  signed __int64 v14; // ST40_8
  bool v15; // al
  int v16; // ebp
  SSParser::eResult v17; // eax
  char v18; // cl
  unsigned int v19; // eax
  SSExpressionBaseVtbl *v20; // r14
  SSExpressionBase *v21; // rax
  unsigned int v22; // ebx
  SSParser::eResult v23; // eax
  unsigned int v24; // eax
  SSExpressionBase *v25; // rcx
  __int64 v26; // rax
  unsigned int v27; // eax
  SSExpressionBase *v28; // rcx
  __int64 v29; // rax
  unsigned int end_pos_p; // [rsp+A0h] [rbp+8h]
  unsigned int v32; // [rsp+A8h] [rbp+10h]
  eSSInvokeTime v33; // [rsp+B0h] [rbp+18h]
  SSParser::eResultDesired v34; // [rsp+B8h] [rbp+20h]

  v34 = result;
  v33 = desired_exec_time;
  v4 = desired_exec_time;
  v5 = args;
  v6 = this;
  args->i_result = 82;
  v7 = 0i64;
  v8 = this->i_str_ref_p->i_cstr_p;
  v9 = this->i_str_ref_p->i_length;
  v32 = v9;
  v10 = args->i_start_pos;
  if ( v9 - (unsigned int)v10 < 2 )
    goto LABEL_61;
  args->i_result = 25;
  if ( v8[v10] != 91 )
    goto LABEL_61;
  end_pos_p = v10 + 1;
  v11 = SSParser::parse_ws_any(this, v10 + 1, &end_pos_p);
  v5->i_result = v11;
  if ( v11 )
  {
    LODWORD(v10) = end_pos_p;
    goto LABEL_61;
  }
  if ( v5->i_flags & 1 )
  {
    v12 = (SSCode *)AMemory::c_malloc_func(0x28ui64, "SSCode");
    v7 = v12;
    if ( v12 )
    {
      v12->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
      v12->vfptr = (SSExpressionBaseVtbl *)&SSCode::`vftable';
      v13 = (signed __int64)&v12->i_temp_vars;
      *(_DWORD *)v13 = 0;
      *(_QWORD *)(v13 + 8) = 0i64;
      v14 = (signed __int64)&v12->i_statements;
      *(_DWORD *)v14 = 0;
      *(_QWORD *)(v14 + 8) = 0i64;
    }
    else
    {
      v7 = 0i64;
    }
  }
  LODWORD(v10) = end_pos_p;
  if ( v8[end_pos_p] == 93 )
  {
    LODWORD(v10) = end_pos_p + 1;
    v5->i_type_p = (SSClassDescBase *)&SSBrain::c_none_class_p->vfptr;
    v5->i_result = 0;
    goto LABEL_61;
  }
  v5->i_result = 82;
  if ( (unsigned int)v10 < v9 )
  {
    while ( 1 )
    {
      v5->i_start_pos = v10;
      v15 = SSParser::parse_statement_append(v6, v5, v7, v4);
      LODWORD(v10) = v5->i_end_pos;
      end_pos_p = v5->i_end_pos;
      if ( !v15 )
        break;
      v16 = v10;
      v17 = SSParser::parse_ws_any(v6, v10, &end_pos_p);
      v5->i_result = v17;
      if ( v17 )
      {
        v5->i_start_pos = v10;
LABEL_42:
        LODWORD(v10) = end_pos_p;
        break;
      }
      LODWORD(v10) = end_pos_p;
      v18 = v8[end_pos_p];
      switch ( v18 )
      {
        case 37:
          ++`anonymous namespace'::SSParser_old_branch_delimiter;
          if ( v7 )
          {
            v19 = v7->i_statements.i_count;
            if ( v19 )
              v20 = (SSExpressionBaseVtbl *)v7->i_statements.i_array_p[v19 - 1];
            else
              v20 = 0i64;
            if ( (*((unsigned __int8 (__fastcall **)(SSExpressionBaseVtbl *, _QWORD))v20->__vecDelDtor + 9))(v20, 0i64) )
            {
              v5->i_result = 71;
              goto LABEL_43;
            }
            APCompactArrayBase<SSExpressionBase>::remove_last((APCompactArrayBase<SSExpressionBase> *)&v7->i_statements.i_count);
            v21 = (SSExpressionBase *)AMemory::c_malloc_func(0x10ui64, "SSConcurrentBranch");
            *(_QWORD *)&end_pos_p = v21;
            if ( v21 )
            {
              v21->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
              v21->vfptr = (SSExpressionBaseVtbl *)&SSConcurrentBranch::`vftable';
              v21[1].vfptr = v20;
            }
            APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
              (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *)&v7->i_statements.i_count,
              v21);
            v5->i_type_p = (SSClassDescBase *)&SSBrain::c_none_class_p->vfptr;
            v9 = v32;
          }
          v22 = v10 + 1;
          end_pos_p = v22;
          v5->i_start_pos = v22;
          v23 = SSParser::parse_ws_any(v6, v22, &end_pos_p);
          v5->i_result = v23;
          if ( v23 )
            goto LABEL_42;
          LODWORD(v10) = end_pos_p;
          if ( v8[end_pos_p] == 93 )
            goto LABEL_40;
          break;
        case 44:
          v5->i_result = 78;
          goto LABEL_43;
        case 59:
          v5->i_result = 77;
          goto LABEL_43;
        case 93:
LABEL_40:
          LODWORD(v10) = v10 + 1;
          goto LABEL_43;
        default:
          if ( v16 == end_pos_p )
          {
            v5->i_result = 90;
            goto LABEL_43;
          }
          break;
      }
      if ( v7 )
      {
        v24 = v7->i_statements.i_count;
        if ( v24 )
        {
          v25 = v7->i_statements.i_array_p[v24 - 1];
          if ( v25 )
          {
            v26 = ((__int64 (*)(void))v25->vfptr->find_expr_last_no_side_effect)();
            if ( v26 )
            {
              v5->i_result = ((*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v26 + 24i64))(v26) == 1) + 6;
              break;
            }
          }
        }
      }
      v5->i_result = 82;
      if ( (unsigned int)v10 >= v9 )
        break;
      v4 = v33;
    }
  }
LABEL_43:
  if ( v34 == ResultDesired_false && v7 )
  {
    if ( v5->i_result )
      goto LABEL_55;
    v27 = v7->i_statements.i_count;
    if ( v27 )
    {
      v28 = v7->i_statements.i_array_p[v27 - 1];
      if ( v28 )
      {
        v29 = ((__int64 (*)(void))v28->vfptr->find_expr_last_no_side_effect)();
        if ( v29 )
          v5->i_result = ((*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v29 + 24i64))(v29) == 1) + 6;
      }
    }
  }
  if ( v5->i_result == Result_ok )
  {
    if ( v6->i_flags.i_flagset & 1 )
    {
      (*(void (**)(void))v5->i_type_p->vfptr->gap8)();
      if ( v7 )
        SSTypeContext::archive_locals(&v6->i_context, (AVCompactArrayBase<ASymbol> *)&v7->i_temp_vars.i_count);
      ((void (*)(void))v5->i_type_p->vfptr->dereference_delay)();
    }
    goto LABEL_61;
  }
LABEL_55:
  if ( v6->i_flags.i_flagset & 1 )
  {
    if ( !v7 )
      goto LABEL_61;
    APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::free_all(
      (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v6->i_context.i_current_scope_p->i_count,
      v7->i_temp_vars.i_array_p,
      v7->i_temp_vars.i_count,
      0,
      0xFFFFFFFF);
  }
  if ( v7 )
  {
    v7->vfptr->__vecDelDtor((SSExpressionBase *)&v7->vfptr, 1u);
    v7 = 0i64;
  }
LABEL_61:
  v5->i_end_pos = v10;
  return v7;
}

// File Line: 2435
// RVA: 0x128FD0
SSCode *__fastcall SSParser::parse_code_block_optimized(SSParser *this, SSParser::Args *args, eSSInvokeTime desired_exec_time, SSParser::eResultDesired result)
{
  SSCode *v5; // rbx
  SSCode *v6; // rax
  SSCode *v7; // rdi
  unsigned int v8; // eax

  if ( !(args->i_flags & 1) )
    return SSParser::parse_code_block(this, args, desired_exec_time, result);
  v5 = 0i64;
  v6 = SSParser::parse_code_block(this, args, desired_exec_time, result);
  v7 = v6;
  if ( v6 )
  {
    v8 = v6->i_statements.i_count;
    if ( v8 )
    {
      if ( v8 != 1 || v7->i_temp_vars.i_count )
      {
        v5 = v7;
      }
      else
      {
        v5 = (SSCode *)*v7->i_statements.i_array_p;
        AMemory::c_free_func(v7->i_statements.i_array_p);
        v7->i_statements.i_array_p = 0i64;
        v7->i_statements.i_count = 0;
        v7->vfptr->__vecDelDtor((SSExpressionBase *)&v7->vfptr, 1u);
      }
    }
    else
    {
      v5 = (SSCode *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
      if ( v5 )
      {
        v5->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
        v5->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable';
        *(_QWORD *)&v5->i_temp_vars.i_count = 0i64;
        LODWORD(v5->i_temp_vars.i_array_p) = 7;
      }
      else
      {
        v5 = 0i64;
      }
      v7->vfptr->__vecDelDtor((SSExpressionBase *)&v7->vfptr, 1u);
    }
  }
  return v5;
}

// File Line: 2570
// RVA: 0x1290B0
signed __int64 __fastcall SSParser::parse_comment_multiline(SSParser *this, __int64 start_pos, unsigned int *end_pos_p)
{
  AStringRef *v3; // rbx
  unsigned int *v4; // rdi
  unsigned int v5; // esi
  SSParser *v6; // rbp
  char *v7; // rbx
  __int64 v8; // rdx
  char v9; // cl
  SSParser::eResult v10; // eax
  unsigned int v11; // edx
  SSParser::eResult v12; // eax
  unsigned int end_pos_pa; // [rsp+38h] [rbp+10h]

  v3 = this->i_str_ref_p;
  v4 = end_pos_p;
  v5 = this->i_str_ref_p->i_length;
  v6 = this;
  end_pos_pa = start_pos;
  if ( (signed int)start_pos + 2 <= v5 )
  {
    v7 = v3->i_cstr_p;
    if ( v7[(unsigned int)start_pos] == 47 )
    {
      start_pos = (unsigned int)(start_pos + 1);
      end_pos_pa = start_pos;
      if ( v7[start_pos] == 42 )
      {
        v8 = (unsigned int)(start_pos + 2);
        end_pos_pa = v8;
        if ( (unsigned int)v8 >= v5 )
        {
LABEL_16:
          if ( v4 )
            *v4 = v8;
          return 26i64;
        }
        while ( 1 )
        {
          v9 = v7[v8];
          if ( v9 == 42 )
          {
            v12 = SSParser::parse_comment_multiline(v6, v8 - 1, &end_pos_pa);
            v11 = end_pos_pa;
            if ( v12 == Result_ok )
              goto LABEL_14;
            if ( v7[end_pos_pa + 2] == 47 )
            {
              if ( v4 )
                *v4 = end_pos_pa + 3;
              return 0i64;
            }
            v8 = end_pos_pa + 3;
          }
          else if ( v9 == 47 )
          {
            if ( v7[(unsigned int)(v8 - 1)] == 42 )
            {
              if ( v4 )
                *v4 = v8 + 1;
              return 0i64;
            }
            v10 = SSParser::parse_comment_multiline(v6, v8, &end_pos_pa);
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
          if ( (unsigned int)v8 >= v5 )
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
  SSParser::Args *v2; // rsi
  SSParser *v3; // rdi
  unsigned int v4; // ebx
  char *v5; // r15
  SSExpressionBase *v6; // r12
  __int64 v7; // r13
  unsigned int v8; // er14
  _QWORD *v9; // rcx
  SSParser::eResult v10; // eax
  __int64 v11; // rdx
  signed int v12; // eax
  unsigned int v13; // eax
  SSTypedName **v14; // rax
  SSParser::eResult v15; // eax
  SSCode *v16; // r14
  SSClause *v17; // rax
  char v18; // r14
  unsigned int v19; // eax
  void (__fastcall ***v20)(_QWORD, signed __int64); // r13
  SSTypedName **v21; // r12
  SSClassUnaryBase *v22; // r14
  SSClassUnaryBase *v23; // rax
  SSTypedName **v24; // rdi
  unsigned __int64 v25; // r15
  SSTypedName *v26; // rbx
  SSClassDescBase *v27; // rcx
  SSClassUnaryBase **v28; // rsi
  __int64 *v29; // rbx
  SSClassUnaryBase **v30; // rdi
  unsigned int v32; // [rsp+20h] [rbp-89h]
  void (__fastcall ***v33)(_QWORD, signed __int64); // [rsp+28h] [rbp-81h]
  APCompactArray<SSClause,SSClause,ACompareAddress<SSClause> > *v34; // [rsp+30h] [rbp-79h]
  unsigned int v35; // [rsp+38h] [rbp-71h]
  APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > sorted; // [rsp+40h] [rbp-69h]
  APSortedLogical<SSTypedName,ASymbol> merge_vars_p; // [rsp+58h] [rbp-51h]
  SSClassUnion class_union; // [rsp+70h] [rbp-39h]
  unsigned __int64 v39; // [rsp+A0h] [rbp-9h]
  SSClause *v40; // [rsp+A8h] [rbp-1h]
  __int64 v41; // [rsp+B0h] [rbp+7h]
  char v42; // [rsp+110h] [rbp+67h]
  signed __int64 v43; // [rsp+118h] [rbp+6Fh]
  char v44; // [rsp+118h] [rbp+6Fh]
  unsigned int end_pos_p; // [rsp+120h] [rbp+77h]
  unsigned int v46; // [rsp+128h] [rbp+7Fh]

  v41 = -2i64;
  v2 = args;
  v3 = this;
  v4 = args->i_start_pos;
  v32 = args->i_start_pos;
  v35 = this->i_str_ref_p->i_length;
  v5 = this->i_str_ref_p->i_cstr_p;
  v6 = 0i64;
  class_union.i_ref_count = 0;
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
  class_union.i_common_class_p = 0i64;
  class_union.i_union.i_count = 0;
  class_union.i_union.i_array_p = 0i64;
  class_union.i_union.i_size = 0;
  merge_vars_p.i_count = 0;
  merge_vars_p.i_array_p = 0i64;
  merge_vars_p.i_size = 0;
  LODWORD(v7) = 0;
  sorted.i_count = 0;
  sorted.i_array_p = 0i64;
  v8 = 0;
  v39 = 0i64;
  sorted.i_size = 0;
  v33 = 0i64;
  if ( !(args->i_flags & 1) )
    goto LABEL_85;
  v9 = AMemory::c_malloc_func(0x18ui64, "SSConditional");
  v33 = (void (__fastcall ***)(_QWORD, signed __int64))v9;
  if ( v9 )
  {
    *v9 = &SSExpressionBase::`vftable';
    *v9 = &SSConditional::`vftable';
    v43 = (signed __int64)(v9 + 1);
    *(_DWORD *)v43 = 0;
    *(_QWORD *)(v43 + 8) = 0i64;
  }
  else
  {
    v9 = 0i64;
    v33 = 0i64;
  }
  if ( v9 )
    v34 = (APCompactArray<SSClause,SSClause,ACompareAddress<SSClause> > *)(v9 + 1);
  else
LABEL_85:
    v34 = 0i64;
  v46 = 0;
  end_pos_p = v4;
  v42 = 0;
  while ( 1 )
  {
    v10 = SSParser::parse_ws_any(v3, v4, &end_pos_p);
    v2->i_result = v10;
    v44 = 0;
    if ( v10 )
    {
      v4 = end_pos_p;
      goto LABEL_47;
    }
    v2->i_result = 24;
    v4 = end_pos_p;
    if ( v35 - end_pos_p < 3 )
      break;
    if ( v5[end_pos_p] == 101
      && v5[end_pos_p + 1] == 108
      && v5[end_pos_p + 2] == 115
      && v5[end_pos_p + 3] == 101
      && (v11 = end_pos_p + 4, byte_14236F1C0[(unsigned __int8)v5[v11]]) )
    {
      v4 = end_pos_p + 4;
      end_pos_p += 4;
      v12 = 80;
      if ( v46 )
        v12 = 0;
      v2->i_result = v12;
      v6 = 0i64;
      v44 = 1;
      v42 = 1;
    }
    else
    {
      v7 = v3->i_context.i_top_scope_old.i_count;
      sorted.i_count = v7;
      if ( (unsigned int)v7 <= v8 )
      {
        v14 = sorted.i_array_p;
      }
      else
      {
        AMemory::c_free_func(sorted.i_array_p);
        v13 = AMemory::c_req_byte_size_func(8 * v7);
        v39 = (unsigned __int64)v13 >> 3;
        sorted.i_size = v13 >> 3;
        v14 = APArrayBase<SSTypedName>::alloc_array(v13 >> 3);
        sorted.i_array_p = v14;
      }
      memmove(v14, v3->i_context.i_top_scope_old.i_array_p, 8 * v7);
      v2->i_start_pos = v4;
      v6 = SSParser::parse_expression(v3, v2, SSInvokeTime_immediate);
      v4 = v2->i_end_pos;
      end_pos_p = v2->i_end_pos;
      if ( v3->i_flags.i_flagset & 1 )
      {
        if ( v2->i_result )
          goto LABEL_44;
        if ( !v2->i_type_p->vfptr->is_class_type(v2->i_type_p, (SSClassDescBase *)&SSBrain::c_boolean_class_p->vfptr) )
        {
          v2->i_result = 129;
          goto LABEL_44;
        }
      }
    }
    if ( v2->i_result == Result_ok )
    {
      v15 = SSParser::parse_ws_any(v3, v4, &end_pos_p);
      v2->i_result = v15;
      if ( v15 )
      {
        v4 = end_pos_p;
      }
      else
      {
        v2->i_result = 24;
        v4 = end_pos_p;
        if ( v5[end_pos_p] == 91 )
        {
          if ( v3->i_flags.i_flagset & 1 )
            SSTypeContext::nest_locals(&v3->i_context);
          v44 = 1;
          v2->i_start_pos = v4;
          v16 = SSParser::parse_code_block_optimized(v3, v2, SSInvokeTime_any, ResultDesired_true);
          v4 = v2->i_end_pos;
          end_pos_p = v2->i_end_pos;
          if ( v2->i_result == Result_ok )
          {
            v32 = v4;
            ++v46;
            if ( v34 )
            {
              v17 = (SSClause *)AMemory::c_malloc_func(0x18ui64, "SSClause");
              v40 = v17;
              if ( v17 )
              {
                v17->vfptr = (SSClauseVtbl *)&SSClause::`vftable';
                v17->i_test_p = v6;
                v17->i_clause_p = (SSExpressionBase *)&v16->vfptr;
              }
              APCompactArray<SSClause,SSClause,ACompareAddress<SSClause>>::append(v34, v17);
            }
            if ( !(v3->i_flags.i_flagset & 1) )
              goto LABEL_44;
            SSClassUnion::merge_class(&class_union, v2->i_type_p);
            if ( merge_vars_p.i_count || v3->i_context.i_current_scope_p->i_count )
              SSTypeContext::merge_locals(&v3->i_context, &merge_vars_p, v46 == 1);
          }
          if ( v3->i_flags.i_flagset & 1 )
          {
            AList<SSTypeContext::ScopeVars,SSTypeContext::ScopeVars>::free_last(&v3->i_context.i_scope_stack);
            v3->i_context.i_current_scope_p = (APSortedLogical<SSTypedName,ASymbol> *)&v3->i_context.i_scope_stack.i_sentinel.i_prev_p[1];
          }
        }
      }
    }
LABEL_44:
    v18 = v42;
    if ( v42 )
      goto LABEL_49;
    v8 = v39;
LABEL_47:
    if ( v2->i_result )
      break;
    v6 = 0i64;
  }
  v18 = v42;
LABEL_49:
  if ( v2->i_result )
  {
    if ( v6 )
      v6->vfptr->__vecDelDtor(v6, 1u);
    if ( !v44 && v46 >= 1 )
    {
      APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::remove_all_all(
        (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v3->i_context.i_top_scope_old.i_count,
        &sorted,
        0,
        0xFFFFFFFF);
      APSizedArrayBase<SSTypedName>::free_all((APSizedArrayBase<SSTypedName> *)&v3->i_context.i_top_scope_old.i_count);
      v3->i_context.i_top_scope_old.i_count = v7;
      if ( (unsigned int)v7 > v3->i_context.i_top_scope_old.i_size )
      {
        AMemory::c_free_func(v3->i_context.i_top_scope_old.i_array_p);
        v19 = AMemory::c_req_byte_size_func(8 * v3->i_context.i_top_scope_old.i_count) >> 3;
        v3->i_context.i_top_scope_old.i_size = v19;
        v3->i_context.i_top_scope_old.i_array_p = APArrayBase<SSTypedName>::alloc_array(v19);
      }
      memmove(v3->i_context.i_top_scope_old.i_array_p, sorted.i_array_p, 8i64 * v3->i_context.i_top_scope_old.i_count);
      v2->i_result = 0;
      goto LABEL_59;
    }
    v32 = v4;
    v20 = v33;
    if ( v33 )
    {
      (**v33)(v33, 1i64);
      v20 = 0i64;
    }
  }
  else
  {
LABEL_59:
    v20 = v33;
  }
  v21 = merge_vars_p.i_array_p;
  if ( v3->i_flags.i_flagset & 1 )
  {
    if ( v2->i_result )
    {
      v22 = class_union.i_common_class_p;
    }
    else
    {
      if ( !v18 )
      {
        SSTypeContext::merge(&v3->i_context, &merge_vars_p);
        SSClassUnion::merge_class(&class_union, (SSClassUnaryBase *)&SSBrain::c_none_class_p->vfptr);
      }
      if ( class_union.i_union.i_count > 1 )
      {
        v23 = (SSClassUnaryBase *)SSClassUnion::get_or_create(&class_union);
        v22 = class_union.i_common_class_p;
      }
      else
      {
        v22 = class_union.i_common_class_p;
        v23 = class_union.i_common_class_p;
      }
      v2->i_type_p = (SSClassDescBase *)&v23->vfptr;
      SSTypeContext::change_variable_types(&v3->i_context, &merge_vars_p);
    }
    v24 = v21;
    v25 = (unsigned __int64)&v21[merge_vars_p.i_count];
    merge_vars_p.i_count = 0;
    if ( (unsigned __int64)v21 < v25 )
    {
      do
      {
        v26 = *v24;
        if ( *v24 )
        {
          v27 = v26->i_type_p.i_obj_p;
          if ( v27 )
            (*(void (**)(void))&v27->vfptr->gap8[8])();
          AMemory::c_free_func(v26);
        }
        ++v24;
      }
      while ( (unsigned __int64)v24 < v25 );
    }
  }
  else
  {
    v22 = class_union.i_common_class_p;
  }
  v2->i_end_pos = v32;
  AMemory::c_free_func(sorted.i_array_p);
  AMemory::c_free_func(v21);
  class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
  if ( v22 )
    v22->vfptr->dereference_delay((SSClassDescBase *)&v22->vfptr);
  v28 = class_union.i_union.i_array_p;
  if ( class_union.i_union.i_count )
  {
    v29 = (__int64 *)class_union.i_union.i_array_p;
    v30 = &class_union.i_union.i_array_p[class_union.i_union.i_count];
    if ( class_union.i_union.i_array_p < v30 )
    {
      do
      {
         SSClassDescBase::`vcall'{24,{flat}}(*v29);
        ++v29;
      }
      while ( v29 < (__int64 *)v30 );
    }
  }
  AMemory::c_free_func(v28);
  return (SSConditional *)v20;
}

// File Line: 3022
// RVA: 0x129AC0
ASymbol *__fastcall SSParser::parse_data_member(SSParser *this, SSParser::Args *args, SSExpressionBase *owner_p)
{
  SSExpressionBase *v3; // rbp
  SSParser::Args *v4; // rdi
  SSParser *v5; // rsi
  ASymbol *v6; // rbx
  SSParser::eResult v7; // eax
  SSClassDescBase *v8; // rsi
  __int64 v9; // rax
  ASymbol *v10; // rcx
  ASymbol *v11; // rcx
  unsigned int end_pos_p; // [rsp+20h] [rbp-38h]
  __int64 v14; // [rsp+28h] [rbp-30h]
  ASymbol *v15; // [rsp+30h] [rbp-28h]
  ASymbol name_p; // [rsp+68h] [rbp+10h]
  int v17; // [rsp+78h] [rbp+20h]

  v14 = -2i64;
  v3 = owner_p;
  v4 = args;
  v5 = this;
  v6 = 0i64;
  name_p.i_uid = -1;
  end_pos_p = args->i_start_pos;
  v7 = SSParser::parse_name_instance(this, end_pos_p, &end_pos_p, &name_p);
  v4->i_result = v7;
  if ( v7 == Result_ok )
  {
    v17 = 2;
    if ( v5->i_flags.i_flagset & 1 )
    {
      v8 = v4->i_type_p;
      v9 = (__int64)v8->vfptr->get_data_type(v4->i_type_p, &name_p, (eSSScope *)&v17);
      if ( v9 )
      {
        v4->i_result = 0;
        v4->i_type_p = (SSClassDescBase *)(*(__int64 (__fastcall **)(__int64, SSClassDescBase *))(*(_QWORD *)v9 + 32i64))(
                                            v9,
                                            v8);
      }
      else
      {
        v4->i_result = 114;
      }
    }
    if ( v4->i_flags & 1 && v4->i_result == Result_ok )
    {
      if ( v17 == 2 )
      {
        v10 = (ASymbol *)AMemory::c_malloc_func(0x18ui64, "SSIdentifierMember");
        v15 = v10;
        if ( v10 )
        {
          *(_QWORD *)&v10->i_uid = &SSExpressionBase::`vftable';
          *(_QWORD *)&v10->i_uid = &SSIdentifier::`vftable';
          v10[2].i_uid = name_p.i_uid;
          *(_QWORD *)&v10->i_uid = &SSIdentifierMember::`vftable';
          *(_QWORD *)&v10[4].i_uid = v3;
          v6 = v10;
        }
      }
      else
      {
        v11 = (ASymbol *)AMemory::c_malloc_func(0x18ui64, "SSIdentifierClassMember");
        v15 = v11;
        if ( v11 )
        {
          *(_QWORD *)&v11->i_uid = &SSExpressionBase::`vftable';
          *(_QWORD *)&v11->i_uid = &SSIdentifier::`vftable';
          v11[2].i_uid = name_p.i_uid;
          *(_QWORD *)&v11->i_uid = &SSIdentifierMember::`vftable';
          *(_QWORD *)&v11[4].i_uid = v3;
          *(_QWORD *)&v11->i_uid = &SSIdentifierClassMember::`vftable';
          v6 = v11;
        }
      }
    }
  }
  v4->i_end_pos = end_pos_p;
  return v6;
}

// File Line: 3269
// RVA: 0x129D10
SSLiteralList *__fastcall SSParser::parse_expression(SSParser *this, SSParser::Args *args, __int64 desired_exec_time)
{
  SSParser::Args *v3; // rbx
  SSParser *v4; // r15
  AStringRef *v5; // r10
  unsigned int v6; // er9
  __int64 v7; // r13
  SSLiteralList *result; // rax
  unsigned int v9; // esi
  char *v10; // r10
  unsigned __int8 v11; // r11
  __int64 v12; // rdx
  SSLiteralList *v13; // rdi
  ASymbol *v14; // r9
  SSParser::eResult v15; // eax
  AString *v16; // r9
  SSParser::eResult v17; // eax
  AStringRef *v18; // rsi
  bool v19; // zf
  AObjReusePool<AStringRef> *v20; // rax
  AObjReusePool<AStringRef> *v21; // r8
  AObjBlock<AStringRef> *v22; // rax
  unsigned __int64 v23; // rdx
  SSParser::eResult v24; // eax
  char v25; // r14
  SSCode *v26; // rax
  signed __int64 v27; // rcx
  SSParser::eResult v28; // ecx
  SSExpressionBase *v29; // rax
  unsigned int v30; // edx
  SSParser::eResult v31; // ecx
  signed int v32; // eax
  AStringRef *elem; // [rsp+30h] [rbp-38h]
  __int64 v34; // [rsp+38h] [rbp-30h]
  SSParser::Args argsa; // [rsp+40h] [rbp-28h]
  SSLiteralList *ch_p; // [rsp+B0h] [rbp+48h]
  unsigned int end_pos_p; // [rsp+B8h] [rbp+50h]
  eSSInvokeTime desired_exec_timea; // [rsp+C0h] [rbp+58h]
  SSMethodCall **v39; // [rsp+C8h] [rbp+60h]

  desired_exec_timea = (signed int)desired_exec_time;
  v34 = -2i64;
  v3 = args;
  v4 = this;
  v5 = this->i_str_ref_p;
  v6 = this->i_str_ref_p->i_length;
  v7 = args->i_start_pos;
  if ( (unsigned int)v7 < v6 )
  {
    v9 = args->i_start_pos;
    end_pos_p = args->i_start_pos;
    v10 = v5->i_cstr_p;
    v11 = v10[v7];
    v12 = (unsigned int)(v7 + 1);
    if ( (unsigned int)v12 >= v6 )
      LOBYTE(desired_exec_time) = 0;
    else
      desired_exec_time = (unsigned __int8)v10[v12];
    v13 = 0i64;
    switch ( 0x40000000 )
    {
      case 33:
      case 95:
        v3->i_result = 2;
        goto LABEL_62;
      case 34:
        elem = AStringRef::get_empty();
        ++elem->i_ref_count;
        v16 = (AString *)&elem;
        if ( !(v3->i_flags & 1) )
          v16 = 0i64;
        v17 = SSParser::parse_literal_string(v4, v7, &end_pos_p, v16);
        v3->i_result = v17;
        if ( v17 == Result_ok )
        {
          v3->i_type_p = (SSClassDescBase *)&SSBrain::c_string_class_p->vfptr;
          if ( v3->i_flags & 1 )
          {
            v13 = (SSLiteralList *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
            ch_p = v13;
            if ( v13 )
            {
              v13->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
              v13->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable';
              v13->i_item_exprs.i_count = 4;
              v39 = &v13->i_ctor_p;
              if ( v13 != (SSLiteralList *)-8i64 )
              {
                v13->i_ctor_p = (SSMethodCall *)elem;
                ++elem->i_ref_count;
              }
            }
            else
            {
              v13 = 0i64;
            }
          }
        }
        v18 = elem;
        v19 = elem->i_ref_count == 1;
        --v18->i_ref_count;
        if ( !v19 )
          goto LABEL_16;
        if ( v18->i_deallocate )
          AMemory::c_free_func(v18->i_cstr_p);
        v20 = AStringRef::get_pool();
        v21 = v20;
        v22 = v20->i_block_p;
        v23 = (unsigned __int64)v22->i_objects_a;
        if ( (unsigned __int64)v18 < v23 || (unsigned __int64)v18 >= v23 + 24i64 * v22->i_size )
        {
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&v21->i_exp_pool, v18);
          v9 = end_pos_p;
        }
        else
        {
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(&v21->i_pool, v18);
          v9 = end_pos_p;
        }
        goto LABEL_62;
      case 38:
      case 42:
      case 43:
      case 47:
      case 58:
      case 60:
      case 61:
      case 62:
      case 94:
      case 124:
      case 126:
        goto $LN18_1;
      case 39:
        LODWORD(v39) = -1;
        v14 = (ASymbol *)&v39;
        if ( !(v3->i_flags & 1) )
          v14 = 0i64;
        v15 = SSParser::parse_literal_symbol(this, v7, &end_pos_p, v14);
        v3->i_result = v15;
        if ( v15 == Result_ok )
        {
          v3->i_type_p = (SSClassDescBase *)&SSBrain::c_symbol_class_p->vfptr;
          if ( v3->i_flags & 1 )
          {
            v13 = (SSLiteralList *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
            ch_p = v13;
            if ( v13 )
            {
              v13->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
              v13->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable';
              v13->i_item_exprs.i_count = 5;
              elem = (AStringRef *)&v13->i_ctor_p;
              if ( v13 != (SSLiteralList *)-8i64 )
                LODWORD(v13->i_ctor_p) = (_DWORD)v39;
            }
            else
            {
              v13 = 0i64;
            }
          }
        }
LABEL_16:
        v9 = end_pos_p;
        goto LABEL_62;
      case 40:
        goto $LN27_1;
      case 45:
        if ( (_BYTE)desired_exec_time == 62 )
          goto $LN19_2;
        if ( AString::c_is_digit[(unsigned __int8)desired_exec_time] )
          goto LABEL_56;
$LN18_1:
        v3->i_result = 84;
        goto LABEL_62;
      case 63:
$LN19_2:
        v3->i_result = 78;
        v9 = v7 + 1;
        goto LABEL_62;
      case 64:
        if ( (unsigned __int8)desired_exec_time <= 0x3Fu
          && (v27 = -6917528477885267968i64, _bittest64(&v27, desired_exec_time)) )
        {
          v26 = (SSCode *)SSParser::parse_object_id_tail(v4, v3, 0i64);
        }
        else
        {
$LN27_1:
          v26 = (SSCode *)SSParser::parse_closure(v4, v3);
        }
        goto LABEL_61;
      case 91:
        v26 = SSParser::parse_code_block_optimized(this, v3, SSInvokeTime_any, ResultDesired_true);
        goto LABEL_61;
      case 96:
        v24 = 82;
        if ( v6 - (unsigned int)v7 < 2 )
          goto LABEL_38;
        v24 = 42;
        if ( v10[v7] != 96 )
          goto LABEL_38;
        end_pos_p = v7 + 1;
        v25 = v10[v12];
        LOBYTE(ch_p) = v25;
        if ( v25 == 92 )
        {
          v24 = SSParser::parse_literal_char_esc_seq(this, v12, &end_pos_p, (char *)&ch_p);
          v9 = end_pos_p;
LABEL_38:
          v25 = (char)ch_p;
        }
        else
        {
          v24 = 0;
          v9 = v7 + 2;
        }
        v3->i_result = v24;
        if ( v24 == Result_ok )
        {
          v3->i_type_p = (SSClassDescBase *)&SSBrain::c_char_class_p->vfptr;
          if ( v3->i_flags & 1 )
          {
            v13 = (SSLiteralList *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
            ch_p = v13;
            if ( v13 )
            {
              v13->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
              v13->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable';
              v13->i_ctor_p = (SSMethodCall *)v25;
              v13->i_item_exprs.i_count = 1;
            }
            else
            {
              v13 = 0i64;
            }
          }
        }
        goto LABEL_62;
      case 123:
        v13 = SSParser::parse_literal_list(this, v3, 0i64, 0, 0i64);
        v9 = v3->i_end_pos;
        goto LABEL_62;
      default:
LABEL_56:
        if ( v11 == 45 || AString::c_is_digit[v11] )
        {
          v26 = (SSCode *)SSParser::parse_literal_number(this, v3);
        }
        else
        {
          v3->i_result = 73;
          if ( !AString::c_char_match_table[0][v11] )
            goto LABEL_62;
          v26 = (SSCode *)SSParser::parse_expression_alpha(this, v3);
        }
LABEL_61:
        v9 = v3->i_end_pos;
        v13 = (SSLiteralList *)v26;
LABEL_62:
        v28 = v3->i_result;
        if ( (signed int)v28 <= 2 )
        {
          argsa.i_flags = v3->i_flags;
          argsa.i_result = v28;
          argsa.i_end_pos = v3->i_end_pos;
          argsa.i_type_p = v3->i_type_p;
          argsa.i_start_pos = v9;
          if ( v28 == 2 )
            argsa.i_type_p = (SSClassDescBase *)&v4->i_context.i_obj_scope_p->vfptr;
          v29 = SSParser::parse_expression_string(v4, &argsa, (SSExpressionBase *)&v13->vfptr);
          v30 = argsa.i_end_pos;
          if ( v9 == argsa.i_end_pos )
          {
            v32 = 0;
            if ( v3->i_result == 2 )
              v32 = 30;
            v3->i_result = v32;
          }
          else
          {
            v31 = argsa.i_result;
            if ( argsa.i_result )
            {
              if ( v13 )
              {
                v13->vfptr->__vecDelDtor((SSExpressionBase *)&v13->vfptr, 1u);
                v30 = argsa.i_end_pos;
                v31 = argsa.i_result;
              }
              v13 = 0i64;
            }
            else
            {
              v13 = (SSLiteralList *)v29;
            }
            v3->i_start_pos = argsa.i_start_pos;
            v3->i_flags = argsa.i_flags;
            v3->i_result = v31;
            v3->i_end_pos = v30;
            v3->i_type_p = argsa.i_type_p;
            v9 = v30;
          }
          v3->i_end_pos = v9;
          if ( v13 )
          {
            if ( !SSParser::ensure_exec_time(v4, (SSExpressionBase *)&v13->vfptr, v3, desired_exec_timea) )
            {
              v3->i_start_pos = v7;
              v3->i_end_pos = v9;
              v13->vfptr->__vecDelDtor((SSExpressionBase *)&v13->vfptr, 1u);
              v13 = 0i64;
            }
          }
          result = v13;
        }
        else
        {
          v3->i_end_pos = v9;
          result = 0i64;
        }
        break;
    }
  }
  else
  {
    args->i_result = 82;
    args->i_end_pos = v7;
    result = 0i64;
  }
  return result;
}

// File Line: 3587
// RVA: 0x12A290
SSObjectId *__fastcall SSParser::parse_expression_alpha(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // r14
  SSParser *v3; // r12
  __int64 v4; // r15
  unsigned int v5; // ebx
  SSObjectId *v6; // rsi
  AStringRef *v7; // r9
  char *v8; // r8
  char v9; // r13
  __int64 v10; // rdi
  signed int v11; // er10
  SSClass **v12; // rdx
  SSClass **v13; // r9
  signed __int64 v14; // rcx
  unsigned int v15; // er8
  _BOOL8 v16; // rax
  _BOOL8 v17; // r8
  __int64 v18; // rbx
  SSObjectId *v19; // rax
  __int64 v20; // rax
  unsigned int v21; // edx
  unsigned __int64 v22; // rcx
  signed __int64 v23; // rax
  SSClass *v24; // rdi
  signed int v25; // er10
  SSClass **v26; // rdx
  SSClass **v27; // r9
  signed __int64 v28; // rcx
  unsigned int v29; // er8
  _BOOL8 v30; // rax
  _BOOL8 v31; // r8
  unsigned int start_pos; // edi
  unsigned int v34; // eax
  unsigned int v35; // er8
  ASymbol **v36; // rdx
  ASymbol **v37; // r9
  bool v38; // cf
  bool i; // zf
  signed __int64 v40; // rdx
  SSObjectId *v41; // rax
  SSClass *v42; // rax
  SSObjectId *v43; // rax
  SSObjectId *v44; // rax
  SSObjectId *v45; // rax
  SSObjectId *v46; // rax
  eSSMember v47; // ecx
  SSClass *v48; // rax
  SSObjectId *v49; // rax
  signed int v50; // ecx
  int v51; // ecx
  int v52; // ecx
  ASymbol *v53; // rax
  ASymbol *v54; // rax
  ASymbol *v55; // rax
  unsigned int v56; // [rsp+90h] [rbp+48h]
  unsigned int find_pos_p; // [rsp+98h] [rbp+50h]
  ASymbol op_name; // [rsp+A0h] [rbp+58h]
  ASymbol result; // [rsp+A8h] [rbp+60h]

  v2 = args;
  v3 = this;
  v4 = args->i_start_pos;
  v56 = v4;
  find_pos_p = v4 + 1;
  find_pos_p = this->i_str_ref_p->i_length;
  v5 = -1;
  AString::find((AString *)&this->i_str_ref_p, ACharMatch_not_identifier, 1u, &find_pos_p, v4 + 1, 0xFFFFFFFF);
  v2->i_result = 2;
  v6 = 0i64;
  v7 = v3->i_str_ref_p;
  v8 = v3->i_str_ref_p->i_cstr_p;
  v9 = v8[find_pos_p];
  if ( AString::c_is_uppercase[(unsigned __int8)v8[v4]] )
  {
    if ( v9 == 33 )
      return (SSObjectId *)SSParser::parse_instantiate_or_list(v3, v2);
    if ( v9 != 40 )
    {
      if ( v9 != 64 )
      {
        if ( v9 != 123 )
        {
          v10 = 0i64;
          LODWORD(v4) = v56;
          v11 = 82;
          op_name.i_uid = v56;
          if ( v7->i_length > v56 )
          {
            v11 = 15;
            if ( AString::c_is_uppercase[(unsigned __int8)v8[v56]] )
            {
              op_name.i_uid = v56 + 1;
              op_name.i_uid = v7->i_length;
              AString::find(
                (AString *)&v3->i_str_ref_p,
                ACharMatch_not_identifier,
                1u,
                &op_name.i_uid,
                v56 + 1,
                0xFFFFFFFF);
              v5 = SSParser::as_symbol(v3, &result, v4, op_name.i_uid)->i_uid;
              v11 = 0;
              if ( v5 == ASymbol_Class.i_uid )
                v11 = 74;
              LODWORD(v4) = op_name;
            }
          }
          v56 = v4;
          if ( !v11 )
          {
            v11 = 112;
            if ( SSBrain::c_classes.i_count )
            {
              v12 = SSBrain::c_classes.i_array_p;
              v13 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
              while ( 1 )
              {
                v14 = (signed __int64)&v12[((char *)v13 - (char *)v12) >> 4];
                v15 = *(_DWORD *)(*(_QWORD *)v14 + 8i64);
                if ( v5 < v15 )
                  goto LABEL_125;
                v16 = v5 == v15;
                v17 = v5 != v15;
                if ( v16 == 1 )
                {
                  if ( *(_QWORD *)v14 )
                  {
                    v11 = 0;
                    v10 = *(_QWORD *)v14;
                  }
                  break;
                }
                if ( v17 < 0 )
                {
LABEL_125:
                  if ( v12 == (SSClass **)v14 )
                    break;
                  v13 = (SSClass **)(v14 - 8);
                }
                else
                {
                  if ( v13 == (SSClass **)v14 )
                    break;
                  v12 = (SSClass **)(v14 + 8);
                }
              }
            }
          }
          v2->i_result = v11;
          if ( !v10 )
            goto LABEL_122;
          v18 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 136i64))(v10);
          v2->i_type_p = (SSClassDescBase *)v18;
          if ( v2->i_flags & 1 )
          {
            v19 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
            *(_QWORD *)&op_name.i_uid = v19;
            if ( v19 )
            {
              v19->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
              v19->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable';
              *(_QWORD *)&v19->i_name.i_uid = v18;
              LODWORD(v19->i_class_p) = 6;
              v6 = v19;
            }
          }
          goto LABEL_121;
        }
        return (SSObjectId *)SSParser::parse_instantiate_or_list(v3, v2);
      }
      v20 = find_pos_p + 1;
      v21 = v7->i_length;
      if ( (unsigned int)v20 < v21 )
      {
        v22 = (unsigned __int8)v8[v20];
        if ( (unsigned __int8)v22 <= 0x3Fu )
        {
          v23 = -6917528477885267968i64;
          if ( _bittest64(&v23, v22) )
          {
            v24 = 0i64;
            LODWORD(v4) = v56;
            v25 = 82;
            op_name.i_uid = v56;
            if ( v21 > v56 )
            {
              v25 = 15;
              if ( AString::c_is_uppercase[(unsigned __int8)v8[v56]] )
              {
                op_name.i_uid = v21;
                AString::find(
                  (AString *)&v3->i_str_ref_p,
                  ACharMatch_not_identifier,
                  1u,
                  &op_name.i_uid,
                  v56 + 1,
                  0xFFFFFFFF);
                v5 = SSParser::as_symbol(v3, &result, v4, op_name.i_uid)->i_uid;
                v25 = 0;
                if ( v5 == ASymbol_Class.i_uid )
                  v25 = 74;
                LODWORD(v4) = op_name;
              }
            }
            v56 = v4;
            if ( !v25 )
            {
              v25 = 112;
              if ( SSBrain::c_classes.i_count )
              {
                v26 = SSBrain::c_classes.i_array_p;
                v27 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1i64];
                while ( 1 )
                {
                  v28 = (signed __int64)&v26[((char *)v27 - (char *)v26) >> 4];
                  v29 = *(_DWORD *)(*(_QWORD *)v28 + 8i64);
                  if ( v5 < v29 )
                    goto LABEL_126;
                  v30 = v5 == v29;
                  v31 = v5 != v29;
                  if ( v30 == 1 )
                  {
                    if ( *(_QWORD *)v28 )
                    {
                      v25 = 0;
                      v24 = *(SSClass **)v28;
                    }
                    break;
                  }
                  if ( v31 < 0 )
                  {
LABEL_126:
                    if ( v26 == (SSClass **)v28 )
                      break;
                    v27 = (SSClass **)(v28 - 8);
                  }
                  else
                  {
                    if ( v27 == (SSClass **)v28 )
                      break;
                    v26 = (SSClass **)(v28 + 8);
                  }
                }
              }
            }
            v2->i_result = v25;
            if ( v24 )
            {
              v2->i_start_pos = v4;
              v6 = SSParser::parse_object_id_tail(v3, v2, v24);
              LODWORD(v4) = v2->i_end_pos;
            }
            goto LABEL_122;
          }
        }
      }
    }
LABEL_121:
    LODWORD(v4) = v56;
    goto LABEL_122;
  }
  op_name.i_uid = -1;
  if ( !(v3->i_flags.i_flagset & 1) && v9 == 40 )
    goto LABEL_121;
  start_pos = v56;
  v56 = v7->i_length;
  AString::find((AString *)&v3->i_str_ref_p, ACharMatch_not_identifier, 1u, &v56, start_pos, 0xFFFFFFFF);
  v34 = SSParser::as_symbol(v3, &result, start_pos, v56)->i_uid;
  op_name.i_uid = v34;
  if ( v34 == -543273101 && v9 != 40 )
  {
    v2->i_start_pos = v56;
    v6 = (SSObjectId *)SSParser::parse_prefix_operator_expr(v3, &op_name, v2);
    LODWORD(v4) = v2->i_end_pos;
    goto LABEL_122;
  }
  v35 = 0;
  if ( SSParser::c_reserved_word_syms.i_count )
  {
    v36 = SSParser::c_reserved_word_syms.i_array_p;
    v37 = &SSParser::c_reserved_word_syms.i_array_p[SSParser::c_reserved_word_syms.i_count - 1];
    v38 = SSParser::c_reserved_word_syms.i_array_p < v37;
    for ( i = SSParser::c_reserved_word_syms.i_array_p == v37; v38 || i; i = v36 == v37 )
    {
      if ( v34 == (*v36)->i_uid )
      {
        if ( v35 < 2 )
        {
          v2->i_result = 0;
          v40 = 5368709120i64;
          switch ( 0x40000000 )
          {
            case 0:
              v2->i_start_pos = find_pos_p;
              v6 = (SSObjectId *)SSParser::parse_concurrent_branch_block(v3, v2);
              LODWORD(v4) = v2->i_end_pos;
              goto LABEL_122;
            case 1:
              v2->i_start_pos = v56;
              v6 = (SSObjectId *)SSParser::parse_case_tail(v3, v2);
              LODWORD(v4) = v2->i_end_pos;
              goto LABEL_122;
            case 2:
              v2->i_start_pos = find_pos_p;
              v6 = (SSObjectId *)SSParser::parse_divert_block(v3, v2);
              LODWORD(v4) = v2->i_end_pos;
              goto LABEL_122;
            case 3:
              v2->i_result = 81;
              goto LABEL_121;
            case 4:
              LODWORD(v4) = v56 - 4;
              v2->i_result = 83;
              goto LABEL_122;
            case 5:
              if ( v2->i_flags & 1 )
              {
                v43 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
                *(_QWORD *)&result.i_uid = v43;
                if ( v43 )
                {
                  v43->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
                  v43->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable';
                  *(_QWORD *)&v43->i_name.i_uid = 0i64;
                  LODWORD(v43->i_class_p) = 0;
                  v6 = v43;
                }
              }
              v42 = SSBrain::c_boolean_class_p;
              goto LABEL_120;
            case 6:
              v2->i_start_pos = v56;
              v6 = (SSObjectId *)SSParser::parse_conditional_tail(v3, v2);
              LODWORD(v4) = v2->i_end_pos;
              goto LABEL_122;
            case 7:
              v2->i_start_pos = v56;
              v6 = (SSObjectId *)SSParser::parse_loop_tail(v3, v2);
              LODWORD(v4) = v2->i_end_pos;
              goto LABEL_122;
            case 9:
              v2->i_start_pos = find_pos_p;
              v6 = (SSObjectId *)SSParser::parse_concurrent_race_block(v3, v2);
              LODWORD(v4) = v2->i_end_pos;
              goto LABEL_122;
            case 10:
              v2->i_start_pos = find_pos_p;
              v6 = (SSObjectId *)SSParser::parse_concurrent_sync_block(v3, v2);
              LODWORD(v4) = v2->i_end_pos;
              goto LABEL_122;
            case 11:
              if ( v2->i_flags & 1 )
              {
                v44 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
                *(_QWORD *)&result.i_uid = v44;
                if ( v44 )
                {
                  v44->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
                  v44->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable';
                  *(_QWORD *)&v44->i_name.i_uid = 0i64;
                  LODWORD(v44->i_class_p) = 8;
                  v6 = v44;
                }
              }
              v42 = (SSClass *)v3->i_context.i_obj_scope_p;
              goto LABEL_120;
            case 12:
              if ( v2->i_flags & 1 )
              {
                v45 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
                *(_QWORD *)&result.i_uid = v45;
                if ( v45 )
                {
                  v45->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
                  v45->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable';
                  *(_QWORD *)&v45->i_name.i_uid = 0i64;
                  LODWORD(v45->i_class_p) = 9;
                  v6 = v45;
                }
              }
              v42 = (SSClass *)((__int64 (__fastcall *)(SSClassUnaryBase *, signed __int64))v3->i_context.i_obj_scope_p->vfptr->get_metaclass)(
                                 v3->i_context.i_obj_scope_p,
                                 v40);
              goto LABEL_120;
            case 13:
              if ( v2->i_flags & 1 )
              {
                v46 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
                *(_QWORD *)&result.i_uid = v46;
                if ( v46 )
                {
                  v46->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
                  v46->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable';
                  *(_QWORD *)&v46->i_name.i_uid = 0i64;
                  LODWORD(v46->i_class_p) = 10;
                  v6 = v46;
                }
              }
              v47 = v3->i_member_type;
              LODWORD(v4) = v56;
              if ( v47 )
              {
                v48 = SSBrain::c_invoked_coroutine_class_p;
                if ( v47 != 3 )
                  v48 = SSBrain::c_none_class_p;
                v2->i_type_p = (SSClassDescBase *)&v48->vfptr;
              }
              else
              {
                v2->i_type_p = (SSClassDescBase *)&SSBrain::c_invoked_method_class_p->vfptr;
              }
              goto LABEL_122;
            case 14:
              if ( v2->i_flags & 1 )
              {
                v41 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
                *(_QWORD *)&result.i_uid = v41;
                if ( v41 )
                {
                  v41->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
                  v41->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable';
                  *(_QWORD *)&v41->i_name.i_uid = 1i64;
                  LODWORD(v41->i_class_p) = 0;
                  v6 = v41;
                }
              }
              v42 = SSBrain::c_boolean_class_p;
              break;
            default:
              if ( v2->i_flags & 1 )
              {
                v49 = (SSObjectId *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
                *(_QWORD *)&result.i_uid = v49;
                if ( v49 )
                {
                  v49->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
                  v49->vfptr = (SSExpressionBaseVtbl *)&SSLiteral::`vftable';
                  *(_QWORD *)&v49->i_name.i_uid = 0i64;
                  LODWORD(v49->i_class_p) = 7;
                  v6 = v49;
                }
              }
              v42 = SSBrain::c_none_class_p;
              break;
          }
          goto LABEL_120;
        }
        --v35;
      }
      ++v36;
      v38 = v36 < v37;
    }
  }
  if ( !(v3->i_flags.i_flagset & 1) )
  {
    v50 = 3;
    goto LABEL_106;
  }
  v50 = SSTypeContext::find_variable(&v3->i_context, &op_name);
  if ( v50 )
  {
LABEL_106:
    v2->i_result = 0;
    if ( v2->i_flags & 1 )
    {
      v51 = v50 - 1;
      if ( v51 )
      {
        v52 = v51 - 1;
        if ( v52 )
        {
          if ( v52 == 1 )
          {
            v53 = (ASymbol *)AMemory::c_malloc_func(0x10ui64, "SSIdentifier");
            *(_QWORD *)&result.i_uid = v53;
            if ( v53 )
            {
              *(_QWORD *)&v53->i_uid = &SSExpressionBase::`vftable';
              *(_QWORD *)&v53->i_uid = &SSIdentifier::`vftable';
              v53[2].i_uid = op_name.i_uid;
              v6 = (SSObjectId *)v53;
            }
          }
        }
        else
        {
          v54 = (ASymbol *)AMemory::c_malloc_func(0x18ui64, "SSIdentifierMember");
          *(_QWORD *)&result.i_uid = v54;
          if ( v54 )
          {
            *(_QWORD *)&v54->i_uid = &SSExpressionBase::`vftable';
            *(_QWORD *)&v54->i_uid = &SSIdentifier::`vftable';
            v54[2].i_uid = op_name.i_uid;
            *(_QWORD *)&v54->i_uid = &SSIdentifierMember::`vftable';
            *(_QWORD *)&v54[4].i_uid = 0i64;
            v6 = (SSObjectId *)v54;
          }
        }
      }
      else
      {
        v55 = (ASymbol *)AMemory::c_malloc_func(0x18ui64, "SSIdentifierClassMember");
        *(_QWORD *)&result.i_uid = v55;
        if ( v55 )
        {
          *(_QWORD *)&v55->i_uid = &SSExpressionBase::`vftable';
          *(_QWORD *)&v55->i_uid = &SSIdentifier::`vftable';
          v55[2].i_uid = op_name.i_uid;
          *(_QWORD *)&v55->i_uid = &SSIdentifierMember::`vftable';
          *(_QWORD *)&v55[4].i_uid = 0i64;
          *(_QWORD *)&v55->i_uid = &SSIdentifierClassMember::`vftable';
          v6 = (SSObjectId *)v55;
        }
      }
      if ( v3->i_flags.i_flagset & 1 )
      {
        v42 = (SSClass *)SSTypeContext::get_variable_type(&v3->i_context, &op_name, 0);
LABEL_120:
        v2->i_type_p = (SSClassDescBase *)&v42->vfptr;
      }
    }
    goto LABEL_121;
  }
  if ( v9 != 40 )
  {
    v2->i_result = 113;
    goto LABEL_121;
  }
LABEL_122:
  v2->i_end_pos = v4;
  return v6;
}

// File Line: 4024
// RVA: 0x12B060
SSLiteralList *__fastcall SSParser::parse_instantiate_or_list(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // rsi
  SSParser *v3; // r15
  SSExpressionBase *v4; // rbx
  SSParser::eResult v5; // eax
  SSTypedClass *v6; // r14
  SSMethodCall *ctor_p; // rbp
  SSLiteralList *result; // rax
  SSExpressionBase *v9; // rdi
  __int64 v10; // rax
  _BOOL8 v11; // [rsp+78h] [rbp+10h]
  SSTypedClass *list_class_p; // [rsp+80h] [rbp+18h]

  v2 = args;
  v3 = this;
  v4 = 0i64;
  list_class_p = 0i64;
  LOBYTE(v11) = 0;
  v5 = (unsigned int)SSParser::parse_class_instance(
                       this,
                       args->i_start_pos,
                       &args->i_end_pos,
                       (SSClassUnaryBase **)&list_class_p,
                       (bool *)&v11);
  v2->i_result = v5;
  if ( v5 )
    return 0i64;
  v6 = list_class_p;
  v2->i_type_p = (SSClassDescBase *)&list_class_p->vfptr;
  v2->i_start_pos = v2->i_end_pos;
  ctor_p = SSParser::parse_invoke_ctor(v3, v2);
  if ( v2->i_result )
    return 0i64;
  if ( v3->i_str_ref_p->i_cstr_p[v2->i_end_pos] == 123
    && (unsigned int)v6->vfptr->get_class_type((SSClassDescBase *)&v6->vfptr) )
  {
    v2->i_start_pos = v2->i_end_pos;
    result = SSParser::parse_literal_list(v3, v2, v6, v11, ctor_p);
  }
  else
  {
    if ( ctor_p )
    {
      v9 = (SSExpressionBase *)AMemory::c_malloc_func(0x18ui64, "SSInstantiate");
      v11 = (_BOOL8)v9;
      if ( v9 )
      {
        v10 = (__int64)v6->vfptr->get_key_class((SSClassDescBase *)&v6->vfptr);
        v9->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
        v9->vfptr = (SSExpressionBaseVtbl *)&SSInstantiate::`vftable';
        v9[1].vfptr = (SSExpressionBaseVtbl *)v10;
        v9[2].vfptr = (SSExpressionBaseVtbl *)ctor_p;
        v4 = v9;
      }
    }
    result = (SSLiteralList *)v4;
    if ( v3->i_flags.i_flagset & 1 )
      v2->i_type_p = (SSClassDescBase *)&v6->vfptr;
  }
  return result;
}

// File Line: 4101
// RVA: 0x12ABA0
SSExpressionBase *__fastcall SSParser::parse_expression_string(SSParser *this, SSParser::Args *args, SSExpressionBase *receiver_p)
{
  SSParser::Args *v3; // rdi
  SSParser *v4; // r13
  bool v5; // r15
  unsigned int v6; // esi
  unsigned int v7; // er14
  SSParser::eResult v8; // eax
  unsigned int v10; // ebx
  bool v11; // bp
  AStringRef *v12; // rcx
  unsigned int v13; // eax
  __int64 v14; // rcx
  SSBind *v15; // r8
  SSExpressionBase *v16; // rsi
  unsigned int v17; // er11
  SSMethodCall *v18; // r10
  __int64 v19; // r9
  unsigned __int8 v20; // dl
  SSParser::eResult v21; // eax
  unsigned int v22; // ebx
  __int64 v23; // rbp
  unsigned __int8 v24; // cl
  SSBind *v25; // rax
  bool v26; // dl
  SSMethodCall *v27; // rax
  SSExpressionBase *v28; // r14
  SSExpressionBase *v29; // rax
  char v30; // bp
  SSParser::eResult v31; // eax
  unsigned int v32; // [rsp+30h] [rbp-78h]
  SSMethodCall *v33; // [rsp+38h] [rbp-70h]
  SSBind *v34; // [rsp+40h] [rbp-68h]
  unsigned int v35; // [rsp+48h] [rbp-60h]
  int v36; // [rsp+4Ch] [rbp-5Ch]
  unsigned int find_pos_p; // [rsp+50h] [rbp-58h]
  unsigned int v38; // [rsp+54h] [rbp-54h]
  __int64 v39; // [rsp+58h] [rbp-50h]
  __int64 v40; // [rsp+60h] [rbp-48h]
  char v41; // [rsp+B8h] [rbp+10h]
  SSExpressionBase *receiver_pa; // [rsp+C0h] [rbp+18h]
  unsigned int end_pos_p; // [rsp+C8h] [rbp+20h]

  receiver_pa = receiver_p;
  v40 = -2i64;
  v3 = args;
  v4 = this;
  v5 = args->i_result == 2;
  v6 = args->i_start_pos;
  v35 = args->i_start_pos;
  v33 = 0i64;
  v7 = args->i_start_pos;
  v8 = SSParser::parse_ws_any(this, args->i_start_pos, &args->i_end_pos);
  v3->i_result = v8;
  if ( v8 )
    return 0i64;
  v10 = v3->i_end_pos;
  v11 = v6 != v10;
  end_pos_p = v3->i_end_pos;
  v32 = v10;
  if ( v5 )
  {
    v3->i_start_pos = v10;
    v33 = SSParser::parse_invoke_selector(v4, v3, 0);
    v10 = v3->i_end_pos;
    end_pos_p = v3->i_end_pos;
  }
  v41 = 0;
  v12 = v4->i_str_ref_p;
  v13 = v4->i_str_ref_p->i_length;
  v38 = v4->i_str_ref_p->i_length;
  v14 = (__int64)v12->i_cstr_p;
  v39 = v14;
  v15 = 0i64;
  v34 = 0i64;
  v16 = receiver_pa;
  while ( 1 )
  {
    if ( v5 )
    {
LABEL_41:
      v18 = v33;
    }
    else
    {
      v17 = v10;
      v32 = v10;
      v18 = 0i64;
      v33 = 0i64;
      v15 = 0i64;
      v34 = 0i64;
      v19 = v10 + 1;
      v20 = (unsigned int)v19 >= v13 ? 0 : *(_BYTE *)(v19 + v14);
      switch ( *(char *)(v10 + v14) )
      {
        case 37:
          if ( v20 == 62 )
          {
            v3->i_start_pos = v10;
            v25 = (SSBind *)SSParser::parse_invoke_race(v4, v3, v16);
            goto LABEL_40;
          }
          if ( v20 == 93 || v20 == 41 || v20 == 125 || !byte_14236F7C0[v20] )
            goto LABEL_39;
          v3->i_start_pos = v10;
          v25 = (SSBind *)SSParser::parse_invoke_apply(v4, v3, v16);
          goto LABEL_40;
        case 40:
          if ( !v11 )
          {
            v3->i_start_pos = v10;
            v25 = (SSBind *)SSParser::parse_invoke_operator(v4, v3, v16);
            goto LABEL_40;
          }
          v3->i_result = 40;
          goto LABEL_43;
        case 45:
          if ( v20 != 62 )
            goto LABEL_39;
          v3->i_result = 78;
          ++v10;
          end_pos_p = v19;
          goto LABEL_43;
        case 46:
          v21 = SSParser::parse_ws_any(v4, v19, &end_pos_p);
          v3->i_result = v21;
          if ( v21 )
          {
            v10 = end_pos_p;
            v15 = 0i64;
            v18 = 0i64;
            break;
          }
          v22 = end_pos_p;
          v23 = v39;
          v24 = *(_BYTE *)(end_pos_p + v39);
          if ( v24 == 91 )
          {
            v3->i_start_pos = end_pos_p;
            v25 = (SSBind *)SSParser::parse_invoke_cascade(v4, v3, v16);
LABEL_40:
            v10 = v3->i_end_pos;
            v15 = v25;
            v34 = v25;
            end_pos_p = v3->i_end_pos;
            goto LABEL_41;
          }
          v26 = 0;
          if ( AString::c_is_lowercase[v24] )
          {
            AString::find(
              (AString *)&v4->i_str_ref_p,
              ACharMatch_not_identifier,
              1u,
              &find_pos_p,
              end_pos_p + 1,
              0xFFFFFFFF);
            v26 = *(_BYTE *)(find_pos_p + v23) != 40;
          }
          v3->i_start_pos = v22;
          if ( v26 )
          {
            v25 = (SSBind *)SSParser::parse_data_member(v4, v3, v16);
            goto LABEL_40;
          }
          v27 = SSParser::parse_invoke_selector(v4, v3, 0);
LABEL_19:
          v18 = v27;
          v33 = v27;
          v10 = v3->i_end_pos;
          end_pos_p = v3->i_end_pos;
          v15 = 0i64;
          break;
        case 58:
          if ( v20 == 61 )
            goto LABEL_39;
          v3->i_start_pos = v10;
          v25 = SSParser::parse_bind(v4, v3, v16);
          goto LABEL_40;
        case 60:
          if ( v20 != 62 )
            goto LABEL_39;
          v3->i_start_pos = v10;
          v25 = (SSBind *)SSParser::parse_class_cast(v4, v3, v16);
          goto LABEL_40;
        case 62:
          if ( v20 != 62 )
            goto LABEL_39;
          v3->i_start_pos = v10;
          v25 = (SSBind *)SSParser::parse_class_conversion(v4, v3, v16, v19);
          goto LABEL_40;
        default:
LABEL_39:
          v3->i_start_pos = v10;
          v27 = SSParser::parse_operator(v4, v3);
          goto LABEL_19;
      }
    }
    v17 = v32;
LABEL_43:
    v5 = 0;
    if ( v3->i_result )
      break;
    v28 = v16;
    if ( v15 )
    {
      v16 = (SSExpressionBase *)&v15->vfptr;
    }
    else if ( v18 )
    {
      v29 = (SSExpressionBase *)AMemory::c_malloc_func(0x18ui64, "SSInvocation");
      if ( v29 )
      {
        v29->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
        v29->vfptr = (SSExpressionBaseVtbl *)&SSInvocation::`vftable';
        v29[1].vfptr = (SSExpressionBaseVtbl *)v16;
        v29[2].vfptr = (SSExpressionBaseVtbl *)v33;
        v16 = v29;
      }
      else
      {
        v16 = 0i64;
      }
    }
    v30 = 1;
    v41 = 1;
    if ( v28 && !v28->vfptr->is_immediate(v28, (unsigned int *)&v36) && v4->i_str_ref_p->i_cstr_p[v3->i_end_pos] != 37 )
    {
      v3->i_end_pos = v36 + 4;
      v3->i_result = 119;
      v10 = v32;
      v3->i_start_pos = v35;
      goto LABEL_61;
    }
    if ( v3->i_result )
      goto LABEL_62;
    v7 = v10;
    v31 = SSParser::parse_ws_any(v4, v10, &end_pos_p);
    v3->i_result = v31;
    v10 = end_pos_p;
    v11 = end_pos_p != v7;
    if ( v31 )
    {
      v30 = 1;
      goto LABEL_61;
    }
    v15 = v34;
    v14 = v39;
    v13 = v38;
  }
  v30 = v41;
  if ( v10 == v17 )
  {
    v10 = v7;
    if ( v41 )
      v3->i_result = 0;
  }
LABEL_61:
  if ( v3->i_result )
  {
LABEL_62:
    if ( v30 && v16 && v16 != receiver_pa )
    {
      v16->vfptr->null_receiver(v16, receiver_pa);
      v16->vfptr->__vecDelDtor(v16, 1u);
    }
    v16 = 0i64;
  }
  v3->i_end_pos = v10;
  return v16;
}

// File Line: 4465
// RVA: 0x12E500
signed __int64 __fastcall SSParser::parse_named_specifier(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSParameters *params_p, unsigned int *arg_idx_p, SSParameters::eType param_type)
{
  SSParser *v6; // r14
  SSParameters *v7; // rdi
  unsigned int v8; // ecx
  unsigned int *v9; // rsi
  unsigned int v10; // ebx
  signed __int64 v11; // rax
  char *v12; // rbp
  unsigned int v13; // er9
  unsigned int v14; // er8
  unsigned int v15; // eax
  _BYTE *v16; // r11
  unsigned __int64 v17; // r10
  _BYTE *v18; // rdx
  __int64 v19; // rax
  bool v20; // zf
  unsigned int v21; // eax
  unsigned __int64 v22; // r10
  ASymbol result; // [rsp+50h] [rbp+8h]
  unsigned int find_pos_p; // [rsp+58h] [rbp+10h]

  v6 = this;
  v7 = params_p;
  v8 = this->i_str_ref_p->i_length;
  v9 = end_pos_p;
  v10 = start_pos;
  find_pos_p = v8;
  if ( end_pos_p )
    *end_pos_p = start_pos;
  if ( start_pos + 1 >= v8 )
    return 54i64;
  v12 = v6->i_str_ref_p->i_cstr_p;
  if ( byte_14236F2C0[(unsigned __int8)v6->i_str_ref_p->i_cstr_p[start_pos]] )
    return 54i64;
  AString::find((AString *)&v6->i_str_ref_p, ACharMatch_not_identifier, 1u, &find_pos_p, start_pos + 1, 0xFFFFFFFF);
  v13 = find_pos_p;
  if ( v12[find_pos_p] != 35 )
    return 54i64;
  if ( v9 )
    *v9 = find_pos_p + 1;
  if ( v13 - v10 > 0xFF )
    return 95i64;
  if ( !v7 )
    return 0i64;
  SSParser::as_symbol(v6, &result, v10, v13);
  v14 = 0;
  if ( param_type == Type_send )
  {
    v15 = v7->i_params.i_count;
    if ( v15 )
    {
      v16 = v7->i_params.i_array_p;
      v17 = (unsigned __int64)&v16[8 * (v15 - 1)];
      v18 = v7->i_params.i_array_p;
      if ( (unsigned __int64)v16 <= v17 )
      {
        do
        {
          if ( result.i_uid == *(_DWORD *)(*(_QWORD *)v18 + 8i64) )
          {
            if ( v14 < 2 )
              goto LABEL_32;
            --v14;
          }
          v18 += 8;
        }
        while ( (unsigned __int64)v18 <= v17 );
      }
    }
    goto LABEL_21;
  }
  v21 = v7->i_return_params.i_count;
  if ( !v21
    || (v16 = v7->i_return_params.i_array_p,
        v22 = (unsigned __int64)&v16[8 * (v21 - 1)],
        v18 = v7->i_return_params.i_array_p,
        (unsigned __int64)v16 > v22) )
  {
LABEL_21:
    v19 = 0i64;
    goto LABEL_22;
  }
  while ( result.i_uid != **(_DWORD **)v18 )
  {
LABEL_30:
    v18 += 8;
    if ( (unsigned __int64)v18 > v22 )
      goto LABEL_21;
  }
  if ( v14 >= 2 )
  {
    --v14;
    goto LABEL_30;
  }
LABEL_32:
  if ( arg_idx_p )
    *arg_idx_p = (v18 - v16) >> 3;
  v19 = *(_QWORD *)v18;
LABEL_22:
  v20 = v19 == 0;
  v11 = 107i64;
  if ( !v20 )
    v11 = 0i64;
  return v11;
}

// File Line: 4589
// RVA: 0x12B3A0
__int64 __fastcall SSParser::parse_invoke_args(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *args_p, APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *ret_args_p, SSClassUnaryBase *receiver_type_p, SSParameters *params_p)
{
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v7; // r15
  unsigned int v8; // ebx
  SSParser::eResult v9; // edi
  AStringRef *v10; // rax
  char *v11; // rcx
  unsigned int v12; // esi
  unsigned int v13; // er13
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v14; // r12
  SSParser *v15; // r14
  unsigned __int64 v16; // r14
  signed __int64 v17; // rax
  SSParameters *v18; // r14
  SSParser *v19; // rbx
  SSParser::eResult v20; // eax
  SSClassDescBase *v21; // r15
  unsigned int v22; // er13
  SSParameterBase **v23; // rax
  SSParameterBase *v24; // rcx
  __int64 v25; // rax
  __int64 v26; // rdi
  unsigned int v27; // er14
  unsigned int v28; // er15
  __int64 v29; // rbx
  __int64 v30; // rax
  __int64 v31; // rax
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v32; // rbx
  unsigned int v33; // eax
  unsigned int v34; // ecx
  SSClass *v35; // rcx
  SSLiteralList *v36; // r14
  bool v37; // al
  char v38; // r15
  char v39; // cl
  APCompactArrayBase<SSParameterBase> *v40; // r13
  unsigned int v41; // er12
  signed __int64 v42; // r14
  char *v43; // r15
  signed __int64 v44; // r14
  char v46; // [rsp+30h] [rbp-71h]
  char v47; // [rsp+31h] [rbp-70h]
  char v48; // [rsp+32h] [rbp-6Fh]
  int elem_count; // [rsp+34h] [rbp-6Dh]
  unsigned int v50; // [rsp+38h] [rbp-69h]
  unsigned int v51; // [rsp+3Ch] [rbp-65h]
  unsigned int v52; // [rsp+40h] [rbp-61h]
  unsigned int v53; // [rsp+44h] [rbp-5Dh]
  unsigned int v54; // [rsp+48h] [rbp-59h]
  SSParameterBase **v55; // [rsp+50h] [rbp-51h]
  SSClassDescBase *v56; // [rsp+58h] [rbp-49h]
  unsigned int v57[2]; // [rsp+60h] [rbp-41h]
  SSParameterBase *v58; // [rsp+68h] [rbp-39h]
  SSParser::Args args; // [rsp+70h] [rbp-31h]
  char *v60; // [rsp+88h] [rbp-19h]
  __int64 v61; // [rsp+90h] [rbp-11h]
  SSParser *v62; // [rsp+F0h] [rbp+4Fh]
  unsigned int end_pos_pa; // [rsp+F8h] [rbp+57h]
  void *mem_p; // [rsp+100h] [rbp+5Fh]
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v65; // [rsp+108h] [rbp+67h]

  v65 = args_p;
  mem_p = end_pos_p;
  v62 = this;
  v61 = -2i64;
  v7 = args_p;
  v8 = start_pos;
  v9 = 82;
  v10 = this->i_str_ref_p;
  v54 = this->i_str_ref_p->i_length;
  v11 = this->i_str_ref_p->i_cstr_p;
  v60 = v10->i_cstr_p;
  if ( v54 - start_pos < 2 )
    goto LABEL_132;
  v9 = 35;
  if ( v11[start_pos] != 40 )
    goto LABEL_132;
  v8 = start_pos + 1;
  end_pos_pa = start_pos + 1;
  v58 = 0i64;
  v55 = 0i64;
  v52 = -1;
  v48 = 0;
  if ( params_p )
  {
    v52 = params_p->i_params.i_count;
    v55 = params_p->i_params.i_array_p;
    if ( args_p )
      APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)args_p);
  }
  v9 = 82;
  v12 = 0;
  v51 = 0;
  v53 = 0;
  v13 = 0;
  elem_count = 0;
  v50 = 0;
  v46 = 0;
  v47 = 0;
  args.i_start_pos = v8;
  args.i_flags = v7 != 0i64;
  *(_QWORD *)&args.i_result = 0i64;
  args.i_type_p = 0i64;
  v14 = 0i64;
  v15 = v62;
  if ( receiver_type_p )
    v56 = receiver_type_p->vfptr->as_finalized_generic(
            (SSClassDescBase *)receiver_type_p,
            (SSClassDescBase *)v62->i_context.i_obj_scope_p);
  else
    v56 = 0i64;
  if ( v8 < v54 )
  {
    while ( 1 )
    {
      v9 = SSParser::parse_ws_any(v15, v8, &end_pos_pa);
      if ( v9 )
        goto LABEL_114;
      v8 = end_pos_pa;
      v16 = (unsigned __int8)v60[end_pos_pa];
      if ( (unsigned __int8)v16 <= 0x3Bu )
      {
        v17 = 576480543512723456i64;
        if ( _bittest64(&v17, v16) )
        {
          v8 = end_pos_pa++ + 1;
          if ( !v12 && (_BYTE)v16 != 44 )
            goto LABEL_25;
          if ( v47 )
          {
            v9 = 110;
            goto LABEL_115;
          }
          if ( !v46 || (v46 = 0, ++v12, !v13) )
          {
            if ( v12 == v52 )
              goto LABEL_104;
            if ( v55 && !((unsigned __int8 (*)(void))v55[v12]->vfptr->is_defaultable)() )
            {
              v9 = 109;
              goto LABEL_115;
            }
            ++v12;
            if ( v7 )
              APCompactArrayBase<SSExpressionBase>::append_null((APCompactArrayBase<SSExpressionBase> *)&v7->i_count);
LABEL_25:
            if ( (_BYTE)v16 == 41 )
              goto LABEL_103;
            if ( (_BYTE)v16 == 59 )
            {
              v48 = 1;
LABEL_103:
              v9 = 0;
              goto LABEL_115;
            }
LABEL_86:
            v9 = 82;
            goto LABEL_99;
          }
          v8 = v50;
          end_pos_pa = v50;
          if ( v14 )
            APCompactArrayBase<SSExpressionBase>::free_all_last(
              (APCompactArrayBase<SSExpressionBase> *)&v14[1].i_count,
              v13);
          goto LABEL_99;
        }
      }
      if ( v12 == v52 )
      {
LABEL_104:
        v9 = 105;
        goto LABEL_115;
      }
      v57[0] = v12;
      v18 = params_p;
      v19 = v62;
      v20 = SSParser::parse_named_specifier(v62, end_pos_pa, &end_pos_pa, params_p, v57, 0);
      v9 = v20;
      v21 = 0i64;
      v22 = v57[0];
      if ( v20 != 54 )
      {
        if ( v20 )
          goto LABEL_114;
        if ( v46 )
        {
          v46 = 0;
          ++v12;
          if ( elem_count )
          {
            v8 = v50;
            end_pos_pa = v50;
            v13 = elem_count;
            if ( v14 )
              APCompactArrayBase<SSExpressionBase>::free_all_last(
                (APCompactArrayBase<SSExpressionBase> *)&v14[1].i_count,
                elem_count);
            goto LABEL_99;
          }
        }
        v47 = 1;
        if ( v18 )
        {
          if ( v65 && v65->i_count > v57[0] && v65->i_array_p[v57[0]] )
          {
            v9 = 108;
LABEL_114:
            v8 = end_pos_pa;
            goto LABEL_115;
          }
          v23 = v18->i_params.i_array_p;
          v24 = v23[v57[0]];
          v58 = v23[v57[0]];
          if ( v62->i_flags.i_flagset & 1 )
          {
            v25 = ((__int64 (*)(void))v24->vfptr->get_expected_type)();
            v21 = (SSClassDescBase *)(*(__int64 (__fastcall **)(__int64, SSClassDescBase *))(*(_QWORD *)v25 + 32i64))(
                                       v25,
                                       v56);
          }
        }
        v9 = SSParser::parse_ws_any(v62, end_pos_pa, &end_pos_pa);
        if ( v9 )
          goto LABEL_114;
        goto LABEL_68;
      }
      if ( v47 )
      {
        v9 = 110;
        goto LABEL_114;
      }
      if ( v18 )
        break;
LABEL_68:
      args.i_start_pos = end_pos_pa;
      args.i_type_p = v21;
      v36 = SSParser::parse_expression(v19, &args, 1i64);
      v8 = args.i_end_pos;
      end_pos_pa = args.i_end_pos;
      v9 = args.i_result;
      if ( args.i_result )
        goto LABEL_115;
      if ( !(v62->i_flags.i_flagset & 1) || (v37 = args.i_type_p->vfptr->is_class_type(args.i_type_p, v21)) != 0 )
        v37 = 1;
      v38 = v46;
      if ( v46 )
      {
        if ( !v37 )
        {
          v46 = 0;
          ++v12;
          v13 = elem_count;
          if ( elem_count )
          {
            v8 = v50;
            end_pos_pa = v50;
            if ( v14 )
              APCompactArrayBase<SSExpressionBase>::free_all_last(
                (APCompactArrayBase<SSExpressionBase> *)&v14[1].i_count,
                elem_count);
          }
          if ( v36 )
            v36->vfptr->__vecDelDtor((SSExpressionBase *)&v36->vfptr, 1u);
          goto LABEL_99;
        }
        ++v51;
        if ( v14 )
          APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
            v14 + 1,
            (SSExpressionBase *)&v36->vfptr);
      }
      else
      {
        if ( !v37 )
        {
          v9 = 132;
          if ( v36 )
            v36->vfptr->__vecDelDtor((SSExpressionBase *)&v36->vfptr, 1u);
          goto LABEL_115;
        }
        if ( v65 )
          APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::set_at_expand(
            v65,
            v22,
            (SSExpressionBase *)&v36->vfptr);
        if ( !v47 || !params_p )
          ++v12;
        v38 = 0;
      }
      v9 = SSParser::parse_ws_any(v62, v8, &end_pos_pa);
      if ( v9 )
        goto LABEL_114;
      v8 = end_pos_pa;
      v39 = v60[end_pos_pa];
      if ( v39 == 44 )
      {
        v8 = end_pos_pa++ + 1;
        v13 = elem_count;
        goto LABEL_86;
      }
      if ( v39 != 41 )
      {
        if ( v39 != 59 )
        {
          v9 = 36;
          if ( v39 == 35 )
            v9 = 85;
          goto LABEL_115;
        }
        v48 = 1;
      }
      if ( !v38 || (v46 = 0, ++v12, (v13 = elem_count) == 0) )
      {
        v8 = end_pos_pa++ + 1;
        v9 = 0;
        goto LABEL_115;
      }
      v8 = v50;
      end_pos_pa = v50;
      if ( v14 )
        APCompactArrayBase<SSExpressionBase>::free_all_last(
          (APCompactArrayBase<SSExpressionBase> *)&v14[1].i_count,
          elem_count);
LABEL_99:
      if ( v8 >= v54 )
        goto LABEL_115;
      v7 = v65;
      v15 = v62;
    }
    if ( v46 )
    {
      v26 = (__int64)v58;
      v27 = v51;
      v28 = v53;
    }
    else
    {
      v26 = (__int64)v18->i_params.i_array_p[v12];
      v58 = (SSParameterBase *)v26;
      if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v26 + 32i64))(v26) != 3 )
      {
        v29 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v26 + 64i64))(v26);
        if ( v56 )
          v30 = (__int64)v56->vfptr->as_finalized_generic(v56, (SSClassDescBase *)&v62->i_context.i_obj_scope_p->vfptr);
        else
          v30 = 0i64;
        v31 = (*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v29 + 32i64))(v29, v30);
LABEL_67:
        v19 = v62;
        v21 = (SSClassDescBase *)v31;
        goto LABEL_68;
      }
      v46 = 1;
      v27 = 0;
      v51 = 0;
      v28 = 1;
      if ( *(_DWORD *)(v26 + 16) )
        v28 = *(_DWORD *)(v26 + 16);
      v53 = v28;
    }
    v32 = v65;
    if ( v65 && !v27 )
    {
      v14 = (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *)AMemory::c_malloc_func(0x20ui64, "SSLiteralList");
      *(_QWORD *)v57 = v14;
      if ( v14 )
      {
        *(_QWORD *)&v14->i_count = &SSExpressionBase::`vftable';
        *(_QWORD *)&v14->i_count = &SSLiteralList::`vftable';
        v14->i_array_p = 0i64;
        v14[1].i_count = 0;
        v14[1].i_array_p = 0i64;
      }
      else
      {
        v14 = 0i64;
      }
      APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
        v32,
        (SSExpressionBase *)v14);
    }
    elem_count = v27 % v28;
    v33 = v50;
    if ( !(v27 % v28) )
      v33 = end_pos_pa;
    v50 = v33;
    v34 = *(_DWORD *)(v26 + 16);
    if ( v34 )
      v35 = *(SSClass **)(*(_QWORD *)(v26 + 24) + 8i64 * (v27 % v34));
    else
      v35 = SSBrain::c_object_class_p;
    v31 = (__int64)v35->vfptr->as_finalized_generic((SSClassDescBase *)&v35->vfptr, v56);
    goto LABEL_67;
  }
LABEL_115:
  v40 = (APCompactArrayBase<SSParameterBase> *)v65;
  if ( v65 )
  {
    if ( v9 )
    {
LABEL_128:
      APCompactArrayBase<SSParameterBase>::free_all(v40);
      goto LABEL_129;
    }
    v41 = v65->i_count;
    if ( v12 < v65->i_count )
    {
      v42 = (signed __int64)&v55[v12];
      v43 = (char *)((char *)v65->i_array_p - (char *)v55);
      while ( *(_QWORD *)&v43[v42] || (*(unsigned __int8 (**)(void))(**(_QWORD **)v42 + 40i64))() )
      {
        ++v12;
        v42 += 8i64;
        if ( v12 >= v41 )
          goto LABEL_122;
      }
      goto LABEL_127;
    }
LABEL_122:
    if ( v12 < v52 )
    {
      v44 = (signed __int64)&v55[v12];
      while ( (*(unsigned __int8 (**)(void))(**(_QWORD **)v44 + 40i64))() )
      {
        ++v12;
        v44 += 8i64;
        if ( v12 >= v52 )
          goto LABEL_129;
      }
LABEL_127:
      v9 = 106;
      goto LABEL_128;
    }
  }
LABEL_129:
  if ( v48 && v9 == Result_ok )
  {
    v9 = SSParser::parse_invoke_return_args(v62, v8, &end_pos_pa, ret_args_p, receiver_type_p, params_p);
    v8 = end_pos_pa;
  }
LABEL_132:
  if ( mem_p )
    *(_DWORD *)mem_p = v8;
  return (unsigned int)v9;
}

// File Line: 5205
// RVA: 0x12C760
__int64 __fastcall SSParser::parse_invoke_return_args(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *ret_args_p, SSClassUnaryBase *receiver_type_p, SSParameters *params_p)
{
  APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *v6; // r14
  unsigned int v7; // esi
  SSParser *v8; // r13
  SSParser::eResult v9; // ebx
  SSParameters *v10; // rdi
  unsigned int v11; // ST18_4
  int v12; // er12
  __int64 v13; // r15
  char v14; // r15
  SSParser::eResult v15; // eax
  __int64 v16; // r15
  SSClassDescBase *v17; // rsi
  SSClassDescBase *v18; // rcx
  SSClassDescBase *v20; // rbx
  __int64 v21; // rax
  SSLiteralList *v22; // rax
  SSIdentifier *v23; // rdi
  signed int v24; // eax
  char v25; // cl
  size_t v26; // rbx
  SSIdentifier **v27; // rdi
  SSIdentifier **v28; // rax
  int v29; // [rsp+18h] [rbp-29h]
  unsigned int v30; // [rsp+1Ch] [rbp-25h]
  unsigned int *v31; // [rsp+20h] [rbp-21h]
  SSParameters::eType param_type[2]; // [rsp+28h] [rbp-19h]
  __int64 v33; // [rsp+30h] [rbp-11h]
  SSParser::Args args; // [rsp+38h] [rbp-9h]
  char v35; // [rsp+98h] [rbp+57h]
  unsigned int end_pos_pa; // [rsp+A0h] [rbp+5Fh]
  unsigned int *retaddr; // [rsp+A8h] [rbp+67h]
  SSClassDescBase *v38; // [rsp+B8h] [rbp+77h]
  SSParameters *v39; // [rsp+C0h] [rbp+7Fh]

  v39 = (SSParameters *)end_pos_p;
  LODWORD(v38) = start_pos;
  v6 = ret_args_p;
  v7 = start_pos;
  LODWORD(v31) = this->i_str_ref_p->i_length;
  v8 = this;
  v9 = 82;
  if ( (unsigned int)v31 - start_pos < 1 )
    goto LABEL_23;
  v10 = (SSParameters *)end_pos_p;
  if ( end_pos_p )
  {
    v11 = end_pos_p[6];
    if ( ret_args_p )
    {
      AMemory::c_free_func(ret_args_p->i_array_p);
      v6->i_array_p = 0i64;
      v6->i_count = 0;
    }
  }
  v12 = 0;
  v13 = (__int64)v8->i_str_ref_p->i_cstr_p;
  v35 = 0;
  args.i_start_pos = v7;
  *(_QWORD *)&args.i_result = 0i64;
  v33 = v13;
  *(_QWORD *)&args.i_flags = v6 != 0i64;
  args.i_type_p = 0i64;
  if ( v7 >= (unsigned int)v31 )
    goto LABEL_20;
  while ( 1 )
  {
    v9 = SSParser::parse_ws_any(v8, v7, &end_pos_pa);
    if ( v9 )
      goto LABEL_19;
    v7 = end_pos_pa;
    v14 = *(_BYTE *)(end_pos_pa + v13);
    if ( v14 != 41 && v14 != 44 )
      break;
    v7 = end_pos_pa++ + 1;
    if ( v12 || v14 == 44 )
    {
      if ( v35 )
      {
        v9 = 110;
        goto LABEL_20;
      }
      if ( v12 == v29 )
      {
LABEL_65:
        v9 = 105;
        goto LABEL_20;
      }
      ++v12;
      if ( v6 )
      {
        v26 = v6->i_count;
        v27 = v6->i_array_p;
        v28 = APArrayBase<SSIdentifier>::alloc_array((signed int)v26 + 1);
        v26 *= 8i64;
        v6->i_array_p = v28;
        memmove(v28, v27, v26);
        AMemory::c_free_func(v27);
        *(SSIdentifier **)((char *)v6->i_array_p + v26) = 0i64;
        ++v6->i_count;
      }
    }
    if ( v14 == 41 )
      goto LABEL_62;
    v13 = v33;
LABEL_53:
    v9 = 82;
    if ( v7 >= (unsigned int)v31 )
      goto LABEL_20;
    v10 = v39;
  }
  if ( v12 == v29 )
    goto LABEL_65;
  v15 = SSParser::parse_named_specifier(v8, end_pos_pa, &end_pos_pa, v10, &v30, Type_return);
  v16 = v30;
  v17 = 0i64;
  v9 = v15;
  *(_QWORD *)param_type = 0i64;
  if ( v15 == 54 )
  {
    if ( !v35 )
    {
      if ( v10 )
      {
        v20 = v10->i_return_params.i_array_p[v12]->i_type_p.i_obj_p;
        if ( v38 )
          v21 = (__int64)v38->vfptr->as_finalized_generic(v38, (SSClassDescBase *)&v8->i_context.i_obj_scope_p->vfptr);
        else
          v21 = 0i64;
        v17 = v20->vfptr->as_finalized_generic(v20, (SSClassDescBase *)v21);
        *(_QWORD *)param_type = v17;
      }
      goto LABEL_32;
    }
    v9 = 110;
    goto LABEL_19;
  }
  if ( v15 )
    goto LABEL_19;
  v35 = 1;
  if ( v10 )
  {
    if ( !v6 || v6->i_count <= v30 || !v6->i_array_p[v30] )
    {
      if ( v8->i_flags.i_flagset & 1 )
      {
        v18 = v10->i_return_params.i_array_p[v30]->i_type_p.i_obj_p;
        v17 = v18->vfptr->as_finalized_generic(v18, v38);
        *(_QWORD *)param_type = v17;
      }
      goto LABEL_18;
    }
    v9 = 108;
LABEL_19:
    v7 = end_pos_pa;
    goto LABEL_20;
  }
LABEL_18:
  v9 = SSParser::parse_ws_any(v8, end_pos_pa, &end_pos_pa);
  if ( v9 )
    goto LABEL_19;
LABEL_32:
  args.i_type_p = v17;
  args.i_start_pos = end_pos_pa;
  v22 = SSParser::parse_expression(v8, &args, 3i64);
  v9 = args.i_result;
  v7 = args.i_end_pos;
  v23 = (SSIdentifier *)v22;
  end_pos_pa = args.i_end_pos;
  if ( args.i_result )
    goto LABEL_20;
  if ( v22 )
  {
    v24 = v22->vfptr->get_type((SSExpressionBase *)&v22->vfptr);
    if ( v24 <= 0 )
      goto LABEL_59;
    if ( v24 > 3 )
    {
      if ( v24 == 5 )
        v9 = 89;
      else
LABEL_59:
        v9 = 70;
      goto LABEL_20;
    }
    v9 = SSParser::validate_bind_type(v8, v23, args.i_type_p, *(SSClassDescBase **)param_type);
    if ( v9 )
    {
      v23->vfptr->__vecDelDtor((SSExpressionBase *)&v23->vfptr, 1u);
      goto LABEL_20;
    }
    if ( v6 )
    {
      APCompactArrayBase<SSIdentifier>::ensure_length_null((APCompactArrayBase<SSIdentifier> *)&v6->i_count, v16 + 1);
      v6->i_array_p[v16] = v23;
    }
  }
  if ( !v35 || !v39 )
    ++v12;
  v9 = SSParser::parse_ws_any(v8, v7, &end_pos_pa);
  if ( v9 )
    goto LABEL_19;
  v7 = end_pos_pa;
  v13 = v33;
  v25 = *(_BYTE *)(end_pos_pa + v33);
  if ( v25 == 44 )
  {
    v7 = end_pos_pa++ + 1;
    goto LABEL_53;
  }
  if ( v25 == 41 )
  {
    v7 = end_pos_pa + 1;
LABEL_62:
    v9 = 0;
  }
  else
  {
    v9 = 36;
  }
LABEL_20:
  if ( v6 && v9 )
    APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)v6);
LABEL_23:
  if ( retaddr )
    *retaddr = v7;
  return (unsigned int)v9;
}

// File Line: 5536
// RVA: 0x12B180
SSInvokeSync *__fastcall SSParser::parse_invoke_apply(SSParser *this, SSParser::Args *args, SSExpressionBase *receiver_p)
{
  SSExpressionBase *v3; // r15
  SSParser::Args *v4; // rbx
  SSParser *v5; // r13
  __int64 v6; // rbp
  unsigned int v7; // er9
  char *v8; // rdx
  _QWORD *v9; // r14
  __int64 v10; // rcx
  SSClassDescBase *v11; // rcx
  SSClass *v12; // rdi
  char v13; // r12
  eSSClassType v14; // eax
  SSClassUnion *v15; // rsi
  __int64 v16; // r15
  __int64 v17; // rax
  SSMethodCall *v18; // rsi
  __int64 v19; // r8
  _QWORD *v20; // rax
  SSExpressionBase *v22; // [rsp+80h] [rbp+18h]

  v22 = receiver_p;
  v3 = receiver_p;
  v4 = args;
  v5 = this;
  v6 = args->i_start_pos;
  v7 = this->i_str_ref_p->i_length;
  v8 = this->i_str_ref_p->i_cstr_p;
  v9 = 0i64;
  v4->i_result = 82;
  if ( v7 - (unsigned int)v6 < 2 )
    goto LABEL_28;
  v4->i_result = 34;
  if ( v8[v6] != 37 )
    goto LABEL_28;
  v10 = (unsigned int)(v6 + 1);
  if ( v8[v10] == 62 )
    goto LABEL_28;
  LODWORD(v6) = v6 + 1;
  v11 = v4->i_type_p;
  v12 = (SSClass *)(v11 ? v11->vfptr->as_finalized_generic(v11, (SSClassDescBase *)&v5->i_context.i_obj_scope_p->vfptr) : 0i64);
  v4->i_result = 133;
  if ( v12 == SSBrain::c_none_class_p )
    goto LABEL_28;
  v13 = 0;
  v14 = (unsigned int)v12->vfptr->get_class_type((SSClassDescBase *)&v12->vfptr);
  if ( v14 )
  {
    if ( v14 == 2 )
    {
      v17 = (__int64)v12->vfptr->get_key_class((SSClassDescBase *)&v12->vfptr);
      if ( (*(unsigned __int8 (__fastcall **)(__int64, SSClass *))(*(_QWORD *)v17 + 96i64))(
             v17,
             SSBrain::c_list_class_p) )
      {
        v13 = 1;
        v15 = (SSClassUnion *)v12->vfptr->get_item_type((SSClassDescBase *)&v12->vfptr);
        goto LABEL_21;
      }
    }
    else if ( v14 == 4 )
    {
      v15 = SSClassUnion::get_reduced((SSClassUnion *)v12, (SSClassUnaryBase *)&SSBrain::c_none_class_p->vfptr);
      v16 = (__int64)v15->vfptr->get_key_class((SSClassDescBase *)&v15->vfptr);
      if ( (*(unsigned __int8 (__fastcall **)(__int64, SSClass *))(*(_QWORD *)v16 + 96i64))(
             v16,
             SSBrain::c_list_class_p) )
      {
        v13 = 1;
        if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v16 + 104i64))(v16) == 2 )
          v15 = (SSClassUnion *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v16 + 112i64))(v16);
        else
          v15 = (SSClassUnion *)SSBrain::c_object_class_p;
      }
      v3 = v22;
      goto LABEL_21;
    }
    goto LABEL_17;
  }
  if ( !v12->vfptr->is_class_type((SSClassDescBase *)&v12->vfptr, (SSClassDescBase *)&SSBrain::c_list_class_p->vfptr) )
  {
LABEL_17:
    v15 = (SSClassUnion *)v12;
    goto LABEL_21;
  }
  v13 = 1;
  v15 = (SSClassUnion *)SSBrain::c_object_class_p;
LABEL_21:
  v4->i_type_p = (SSClassDescBase *)&v15->vfptr;
  v4->i_start_pos = v6;
  v18 = SSParser::parse_invoke_selector(v5, v4, 1);
  LODWORD(v6) = v4->i_end_pos;
  if ( v4->i_result == Result_ok )
  {
    if ( v13 )
      v4->i_type_p = (SSClassDescBase *)&v12->vfptr;
    else
      v4->i_type_p = (SSClassDescBase *)SSClassUnion::get_merge(
                                          v4->i_type_p,
                                          (SSClassDescBase *)&SSBrain::c_none_class_p->vfptr,
                                          v19);
    if ( v4->i_flags & 1 )
    {
      v20 = AMemory::c_malloc_func(0x18ui64, "SSInvokeSync");
      if ( v20 )
      {
        *v20 = &SSExpressionBase::`vftable';
        *v20 = &SSInvocation::`vftable';
        v20[1] = v3;
        v20[2] = v18;
        *v20 = &SSInvokeSync::`vftable';
        v9 = v20;
      }
    }
  }
LABEL_28:
  v4->i_end_pos = v6;
  return (SSInvokeSync *)v9;
}

// File Line: 5693
// RVA: 0x12C540
SSInvokeRace *__fastcall SSParser::parse_invoke_race(SSParser *this, SSParser::Args *args, SSExpressionBase *receiver_p)
{
  SSExpressionBase *v3; // r15
  SSParser::Args *v4; // rbx
  SSParser *v5; // r13
  __int64 v6; // rbp
  unsigned int v7; // er9
  char *v8; // rdx
  _QWORD *v9; // r14
  SSClassDescBase *v10; // rcx
  SSClass *v11; // rdi
  char v12; // r12
  eSSClassType v13; // eax
  SSClassUnion *v14; // rsi
  __int64 v15; // r15
  __int64 v16; // rax
  SSMethodCall *v17; // rsi
  __int64 v18; // r8
  _QWORD *v19; // rax
  SSExpressionBase *v21; // [rsp+80h] [rbp+18h]

  v21 = receiver_p;
  v3 = receiver_p;
  v4 = args;
  v5 = this;
  v6 = args->i_start_pos;
  v7 = this->i_str_ref_p->i_length;
  v8 = this->i_str_ref_p->i_cstr_p;
  v9 = 0i64;
  v4->i_result = 82;
  if ( v7 - (unsigned int)v6 < 3 )
    goto LABEL_28;
  v4->i_result = 34;
  if ( v8[v6] != 37 || v8[(unsigned int)(v6 + 1)] != 62 )
    goto LABEL_28;
  LODWORD(v6) = v6 + 2;
  v10 = v4->i_type_p;
  v11 = (SSClass *)(v10 ? v10->vfptr->as_finalized_generic(v10, (SSClassDescBase *)&v5->i_context.i_obj_scope_p->vfptr) : 0i64);
  v4->i_result = 133;
  if ( v11 == SSBrain::c_none_class_p )
    goto LABEL_28;
  v12 = 0;
  v13 = (unsigned int)v11->vfptr->get_class_type((SSClassDescBase *)&v11->vfptr);
  if ( v13 )
  {
    if ( v13 == 2 )
    {
      v16 = (__int64)v11->vfptr->get_key_class((SSClassDescBase *)&v11->vfptr);
      if ( (*(unsigned __int8 (__fastcall **)(__int64, SSClass *))(*(_QWORD *)v16 + 96i64))(
             v16,
             SSBrain::c_list_class_p) )
      {
        v12 = 1;
        v14 = (SSClassUnion *)v11->vfptr->get_item_type((SSClassDescBase *)&v11->vfptr);
        goto LABEL_21;
      }
    }
    else if ( v13 == 4 )
    {
      v14 = SSClassUnion::get_reduced((SSClassUnion *)v11, (SSClassUnaryBase *)&SSBrain::c_none_class_p->vfptr);
      v15 = (__int64)v14->vfptr->get_key_class((SSClassDescBase *)&v14->vfptr);
      if ( (*(unsigned __int8 (__fastcall **)(__int64, SSClass *))(*(_QWORD *)v15 + 96i64))(
             v15,
             SSBrain::c_list_class_p) )
      {
        v12 = 1;
        if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v15 + 104i64))(v15) == 2 )
          v14 = (SSClassUnion *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 112i64))(v15);
        else
          v14 = (SSClassUnion *)SSBrain::c_object_class_p;
      }
      v3 = v21;
      goto LABEL_21;
    }
    goto LABEL_17;
  }
  if ( !v11->vfptr->is_class_type((SSClassDescBase *)&v11->vfptr, (SSClassDescBase *)&SSBrain::c_list_class_p->vfptr) )
  {
LABEL_17:
    v14 = (SSClassUnion *)v11;
    goto LABEL_21;
  }
  v12 = 1;
  v14 = (SSClassUnion *)SSBrain::c_object_class_p;
LABEL_21:
  v4->i_type_p = (SSClassDescBase *)&v14->vfptr;
  v4->i_start_pos = v6;
  v17 = SSParser::parse_invoke_selector(v5, v4, 1);
  LODWORD(v6) = v4->i_end_pos;
  if ( v4->i_result == Result_ok )
  {
    if ( v12 )
      v4->i_type_p = (SSClassDescBase *)&v11->vfptr;
    else
      v4->i_type_p = (SSClassDescBase *)SSClassUnion::get_merge(
                                          v4->i_type_p,
                                          (SSClassDescBase *)&SSBrain::c_none_class_p->vfptr,
                                          v18);
    if ( v4->i_flags & 1 )
    {
      v19 = AMemory::c_malloc_func(0x18ui64, "SSInvokeRace");
      if ( v19 )
      {
        *v19 = &SSExpressionBase::`vftable';
        *v19 = &SSInvocation::`vftable';
        v19[1] = v3;
        v19[2] = v17;
        *v19 = &SSInvokeRace::`vftable';
        v9 = v19;
      }
    }
  }
LABEL_28:
  v4->i_end_pos = v6;
  return (SSInvokeRace *)v9;
}

// File Line: 5858
// RVA: 0x12BA80
SSInvokeCascade *__fastcall SSParser::parse_invoke_cascade(SSParser *this, SSParser::Args *args, SSExpressionBase *receiver_p)
{
  SSExpressionBase *v3; // rbp
  SSParser::Args *v4; // rbx
  SSParser *v5; // r14
  char *v6; // r12
  unsigned int v7; // er15
  __int64 v8; // rdx
  SSInvokeCascade *result; // rax
  SSParser::eResult v10; // eax
  SSInvokeCascade *v11; // rsi
  unsigned int v12; // edi
  signed __int64 v13; // rax
  unsigned int v14; // ebp
  SSClassDescBase *v15; // r13
  SSMethodCall *v16; // rax
  SSParser::eResult v17; // eax
  unsigned int end_pos_p; // [rsp+70h] [rbp+8h]
  __int64 v19; // [rsp+78h] [rbp+10h]

  v3 = receiver_p;
  v4 = args;
  v5 = this;
  v6 = this->i_str_ref_p->i_cstr_p;
  v7 = this->i_str_ref_p->i_length;
  v8 = args->i_start_pos;
  end_pos_p = v8;
  if ( v6[v8] == 91 )
  {
    v10 = SSParser::parse_ws_any(this, v8 + 1, &end_pos_p);
    v4->i_result = v10;
    if ( v10 )
    {
      v4->i_end_pos = end_pos_p;
      result = 0i64;
    }
    else
    {
      v11 = 0i64;
      v12 = end_pos_p;
      if ( v4->i_flags & 1 && end_pos_p < v7 )
      {
        v11 = (SSInvokeCascade *)AMemory::c_malloc_func(0x28ui64, "SSInvokeCascade");
        *(_QWORD *)&end_pos_p = v11;
        if ( v11 )
        {
          v11->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
          v11->vfptr = (SSExpressionBaseVtbl *)&SSInvokeCascade::`vftable';
          v11->i_receiver_p = v3;
          v13 = (signed __int64)&v11->i_invoke_calls;
          v19 = v13;
          *(_DWORD *)v13 = 0;
          *(_QWORD *)(v13 + 8) = 0i64;
          *(_DWORD *)(v13 + 16) = 0;
        }
        else
        {
          v11 = 0i64;
        }
      }
      v14 = 0;
      v15 = v4->i_type_p;
      v4->i_result = 82;
      if ( v12 < v7 )
      {
        while ( v6[v12] != 93 )
        {
          v4->i_type_p = v15;
          v4->i_start_pos = v12;
          v16 = SSParser::parse_invoke_selector(v5, v4, 1);
          v12 = v4->i_end_pos;
          end_pos_p = v4->i_end_pos;
          if ( v4->i_result )
            goto LABEL_22;
          ++v14;
          if ( v11 )
            APArray<SSInvokeBase,SSInvokeBase,ACompareAddress<SSInvokeBase>>::append(
              (APArray<SSInvokeBase,SSInvokeBase,ACompareAddress<SSInvokeBase> > *)&v11->i_invoke_calls.i_count,
              (SSInvokeBase *)&v16->vfptr);
          v17 = SSParser::parse_ws_any(v5, v12, &end_pos_p);
          v4->i_result = v17;
          v12 = end_pos_p;
          if ( v17 == Result_ok )
          {
            v4->i_result = 82;
            if ( v12 < v7 )
              continue;
          }
          goto LABEL_19;
        }
        ++v12;
        v4->i_result = 0;
      }
LABEL_19:
      if ( v4->i_result == Result_ok && v14 < 2 )
        v4->i_result = (v14 != 0) + 38;
LABEL_22:
      if ( v11 )
      {
        if ( v4->i_result )
        {
          v11->i_receiver_p = 0i64;
          v11->vfptr->__vecDelDtor((SSExpressionBase *)&v11->vfptr, 1u);
          v11 = 0i64;
        }
      }
      v4->i_end_pos = v12;
      result = v11;
    }
  }
  else
  {
    v4->i_result = 38;
    v4->i_end_pos = v8;
    result = 0i64;
  }
  return result;
}

// File Line: 6003
// RVA: 0x12C310
APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *__fastcall SSParser::parse_invoke_operator(SSParser *this, SSParser::Args *args, SSExpressionBase *receiver_p)
{
  SSExpressionBase *v3; // r15
  SSParser::Args *v4; // rbx
  SSParser *v5; // r14
  SSClassDescBase *v6; // rcx
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v7; // rdi
  __int64 v8; // rax
  __int64 v9; // rsi
  SSParser::eResult v10; // eax
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v11; // rcx
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v12; // rcx
  APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > ret_args_p; // [rsp+48h] [rbp-28h]
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > args_p; // [rsp+58h] [rbp-18h]

  v3 = receiver_p;
  v4 = args;
  v5 = this;
  if ( this->i_str_ref_p->i_cstr_p[args->i_start_pos] != 40 )
  {
    args->i_result = 35;
    return 0i64;
  }
  v6 = args->i_type_p;
  v7 = 0i64;
  if ( v6 )
    v8 = (__int64)v6->vfptr->as_finalized_generic(v6, (SSClassDescBase *)&v5->i_context.i_obj_scope_p->vfptr);
  else
    v8 = 0i64;
  v9 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v8 + 40i64))(v8);
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v9 + 104i64))(v9) != 3 )
  {
    v4->i_result = 8;
    v4->i_end_pos = v4->i_start_pos + 1;
    return 0i64;
  }
  if ( v4->i_flags & 1 )
  {
    args_p.i_count = 0;
    args_p.i_array_p = 0i64;
    ret_args_p.i_count = 0;
    ret_args_p.i_array_p = 0i64;
    v10 = (unsigned int)SSParser::parse_invoke_args(
                          v5,
                          v4->i_start_pos,
                          &v4->i_end_pos,
                          &args_p,
                          &ret_args_p,
                          0i64,
                          *(SSParameters **)(v9 + 24));
    v4->i_result = v10;
    if ( v10 == Result_ok )
    {
      if ( *(_DWORD *)(v9 + 32) == 1 )
      {
        v11 = (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *)AMemory::c_malloc_func(0x30ui64, "SSInvokeClosureMethod");
        if ( v11 )
        {
          *(_QWORD *)&v11->i_count = &SSExpressionBase::`vftable';
          *(_QWORD *)&v11->i_count = &SSInvokeClosureBase::`vftable';
          v11->i_array_p = (SSExpressionBase **)v3;
          v11[1] = args_p;
          args_p.i_count = 0;
          args_p.i_array_p = 0i64;
          v11[2] = (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> >)ret_args_p;
          ret_args_p.i_count = 0;
          ret_args_p.i_array_p = 0i64;
          *(_QWORD *)&v11->i_count = &SSInvokeClosureMethod::`vftable';
          v7 = v11;
        }
      }
      else
      {
        v12 = (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *)AMemory::c_malloc_func(0x30ui64, "SSInvokeClosureCoroutine");
        if ( v12 )
        {
          *(_QWORD *)&v12->i_count = &SSExpressionBase::`vftable';
          *(_QWORD *)&v12->i_count = &SSInvokeClosureBase::`vftable';
          v12->i_array_p = (SSExpressionBase **)v3;
          v12[1] = args_p;
          args_p.i_count = 0;
          args_p.i_array_p = 0i64;
          v12[2] = (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> >)ret_args_p;
          ret_args_p.i_count = 0;
          ret_args_p.i_array_p = 0i64;
          *(_QWORD *)&v12->i_count = &SSInvokeClosureCoroutine::`vftable';
          v7 = v12;
        }
      }
    }
    AMemory::c_free_func(ret_args_p.i_array_p);
    AMemory::c_free_func(args_p.i_array_p);
  }
  else
  {
    v4->i_result = SSParser::parse_invoke_args(
                     v5,
                     v4->i_start_pos,
                     &v4->i_end_pos,
                     0i64,
                     0i64,
                     0i64,
                     *(SSParameters **)(v9 + 24));
  }
  if ( v4->i_result == Result_ok )
    v4->i_type_p = *(SSClassDescBase **)(*(_QWORD *)(v9 + 24) + 40i64);
  return v7;
}

// File Line: 6095
// RVA: 0x12BE80
SSMethodCall *__fastcall SSParser::parse_invoke_ctor(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // rdi
  SSParser *v3; // r15
  void (__fastcall ***v4)(_QWORD, signed __int64); // rbx
  __int64 v5; // rsi
  char *v6; // rdx
  ASymbol *v7; // r9
  SSParser::eResult v8; // eax
  SSParameters *params_p; // r14
  __int64 v10; // rax
  void (__fastcall ***v11)(_QWORD, signed __int64); // rax
  unsigned int v12; // ebp
  APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *ret_args_p; // rcx
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v14; // r9
  void *end_pos_p; // [rsp+90h] [rbp+8h]
  int v17; // [rsp+98h] [rbp+10h]
  unsigned int start_pos; // [rsp+A0h] [rbp+18h]

  v2 = args;
  v3 = this;
  v4 = 0i64;
  v5 = args->i_start_pos;
  start_pos = args->i_start_pos;
  v6 = this->i_str_ref_p->i_cstr_p;
  v2->i_result = 52;
  if ( this->i_str_ref_p->i_length >= 3 && v6[v5] == 33 && v6[(unsigned int)(v5 + 1)] != 33 )
  {
    v17 = -1;
    v7 = (ASymbol *)&v17;
    if ( !(v2->i_flags & 1) )
      v7 = 0i64;
    v8 = (unsigned int)SSParser::parse_name_method(this, v5, &start_pos, v7);
    v2->i_result = v8;
    if ( v8 )
      goto LABEL_31;
    params_p = 0i64;
    if ( v3->i_flags.i_flagset & 1 )
    {
      v10 = (__int64)v2->i_type_p->vfptr->get_method_inherited(v2->i_type_p, (ASymbol *)&v17);
      if ( v10 )
      {
        v2->i_result = 0;
        params_p = *(SSParameters **)(v10 + 24);
      }
      else
      {
        v2->i_result = 115;
      }
    }
    if ( v2->i_result )
    {
LABEL_31:
      LODWORD(v5) = start_pos;
    }
    else
    {
      if ( v2->i_flags & 1 )
      {
        v11 = (void (__fastcall ***)(_QWORD, signed __int64))AMemory::c_malloc_func(0x38ui64, "SSMethodCall");
        v4 = v11;
        end_pos_p = v11;
        if ( v11 )
        {
          *((_DWORD *)v11 + 2) = v17;
          v11[2] = 0i64;
          *v11 = (void (__fastcall **)(_QWORD, signed __int64))&SSInvokeBase::`vftable';
          *((_DWORD *)v11 + 6) = 0;
          v11[4] = 0i64;
          *((_DWORD *)v11 + 10) = 0;
          v11[6] = 0i64;
          *v11 = (void (__fastcall **)(_QWORD, signed __int64))&SSMethodCall::`vftable';
        }
        else
        {
          v4 = 0i64;
        }
      }
      v12 = start_pos;
      LODWORD(end_pos_p) = start_pos;
      v2->i_start_pos = start_pos;
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
      v2->i_result = SSParser::parse_invoke_args(
                       v3,
                       v12,
                       (unsigned int *)&end_pos_p,
                       v14,
                       ret_args_p,
                       (SSClassUnaryBase *)v2->i_type_p,
                       params_p);
      LODWORD(v5) = (_DWORD)end_pos_p;
      if ( (_DWORD)end_pos_p == v12 )
      {
        v2->i_result = 111;
        if ( params_p )
        {
          if ( !(unsigned int)SSParameters::get_arg_count_min(params_p) )
            v2->i_result = 0;
        }
      }
      if ( v2->i_result )
      {
        if ( v4 )
          (**v4)(v4, 1i64);
        v4 = 0i64;
      }
    }
  }
  v2->i_end_pos = v5;
  return (SSMethodCall *)v4;
}

// File Line: 6213
// RVA: 0x12C060
SSMethodCall *__fastcall SSParser::parse_invoke_method(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // rsi
  SSParser *v3; // rbp
  void (__fastcall ***v4)(_QWORD, signed __int64); // rdi
  void (__fastcall ***v5)(_QWORD, signed __int64); // rbx
  SSClass *v6; // r15
  unsigned int v7; // er12
  SSClassDescBase *v8; // r13
  SSParser::eResult v9; // er14
  unsigned int v10; // ebp
  ASymbol *v12; // r9
  SSParser::eResult v13; // eax
  __int64 params_p; // r14
  SSClass *v15; // rbp
  SSClassDescBase *v16; // rbp
  SSClassUnion *v17; // r14
  char v18; // al
  __int64 v19; // rax
  void (__fastcall ***v20)(_QWORD, signed __int64); // rax
  unsigned int v21; // edx
  APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *ret_args_p; // rcx
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v23; // r9
  SSParser::eResult v24; // eax
  SSParser *v25; // [rsp+A0h] [rbp+8h]
  void *v26; // [rsp+A8h] [rbp+10h]
  int v27; // [rsp+B0h] [rbp+18h]
  SSClass *v28; // [rsp+B8h] [rbp+20h]

  v25 = this;
  v2 = args;
  v3 = this;
  v4 = 0i64;
  v5 = 0i64;
  v6 = 0i64;
  v7 = args->i_start_pos;
  v8 = args->i_type_p;
  v28 = 0i64;
  LODWORD(v26) = v7;
  v9 = SSParser::parse_class(this, v7, (unsigned int *)&v26, &v28);
  if ( v9 )
  {
    v10 = (unsigned int)v26;
    if ( (_DWORD)v26 != v7 )
      goto LABEL_11;
    goto LABEL_9;
  }
  if ( v3->i_str_ref_p->i_length <= (unsigned int)v26 || v3->i_str_ref_p->i_cstr_p[(unsigned int)v26] != 64 )
  {
    v10 = v7;
LABEL_10:
    v9 = 0;
    goto LABEL_11;
  }
  v10 = (_DWORD)v26 + 1;
  v9 = 138;
  if ( !v8 || SSClass::is_scope_qualifier(v28, v8) )
  {
LABEL_9:
    v6 = v28;
    goto LABEL_10;
  }
LABEL_11:
  LODWORD(v28) = v10;
  v2->i_result = v9;
  if ( v9 )
  {
    v2->i_end_pos = v10;
    return 0i64;
  }
  v27 = -1;
  v12 = (ASymbol *)&v27;
  if ( !(v2->i_flags & 1) )
    v12 = 0i64;
  v13 = (unsigned int)SSParser::parse_name_method(v25, v10, (unsigned int *)&v28, v12);
  v2->i_result = v13;
  if ( v13 )
    goto LABEL_30;
  params_p = 0i64;
  v15 = SSBrain::c_object_class_p;
  if ( !(v25->i_flags.i_flagset & 1) )
  {
LABEL_32:
    if ( v2->i_flags & 1 )
    {
      v20 = (void (__fastcall ***)(_QWORD, signed __int64))AMemory::c_malloc_func(0x38ui64, "SSMethodCall");
      v5 = v20;
      v26 = v20;
      if ( v20 )
      {
        *((_DWORD *)v20 + 2) = v27;
        v20[2] = (void (__fastcall **)(_QWORD, signed __int64))v6;
        *v20 = (void (__fastcall **)(_QWORD, signed __int64))&SSInvokeBase::`vftable';
        *((_DWORD *)v20 + 6) = 0;
        v20[4] = 0i64;
        *((_DWORD *)v20 + 10) = 0;
        v20[6] = 0i64;
        *v20 = (void (__fastcall **)(_QWORD, signed __int64))&SSMethodCall::`vftable';
      }
      else
      {
        v5 = 0i64;
      }
    }
    v21 = (unsigned int)v28;
    v2->i_start_pos = (unsigned int)v28;
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
                          v25,
                          v21,
                          &v2->i_end_pos,
                          v23,
                          ret_args_p,
                          (SSClassUnaryBase *)v2->i_type_p,
                          (SSParameters *)params_p);
    v2->i_result = v24;
    if ( v24 )
    {
      if ( v5 )
        (**v5)(v5, 1i64);
    }
    else
    {
      v2->i_type_p = (SSClassDescBase *)&v15->vfptr;
      v4 = v5;
    }
    return (SSMethodCall *)v4;
  }
  v16 = v2->i_type_p;
  if ( v6 )
  {
    if ( v16->vfptr->is_metaclass(v2->i_type_p) )
      v17 = (SSClassUnion *)v6->vfptr->get_metaclass((SSClassDescBase *)&v6->vfptr);
    else
      v17 = (SSClassUnion *)v6;
  }
  else
  {
    v17 = (SSClassUnion *)v2->i_type_p;
  }
  if ( !((v25->i_flags.i_flagset >> 1) & 1)
    || v27 != ASymbol_String.i_uid
    || (v17->vfptr->get_class_type((SSClassDescBase *)&v17->vfptr) != 4 ? (v18 = v17->vfptr->is_class_type(
                                                                                   (SSClassDescBase *)&v17->vfptr,
                                                                                   (SSClassDescBase *)&SSBrain::c_symbol_class_p->vfptr)) : (v18 = SSClassUnion::is_class_maybe(v17, (SSClassDescBase *)&SSBrain::c_symbol_class_p->vfptr)),
        !v18) )
  {
    v19 = (__int64)v17->vfptr->get_method_inherited((SSClassDescBase *)&v17->vfptr, (ASymbol *)&v27);
    if ( v19 )
    {
      params_p = *(_QWORD *)(v19 + 24);
      v15 = (SSClass *)(*(__int64 (__fastcall **)(_QWORD, SSClassDescBase *))(**(_QWORD **)(params_p + 40) + 32i64))(
                         *(_QWORD *)(params_p + 40),
                         v16);
      goto LABEL_32;
    }
  }
  v2->i_result = 115;
LABEL_30:
  v2->i_end_pos = (unsigned int)v28;
  return (SSMethodCall *)v4;
}

// File Line: 6343
// RVA: 0x12E850
SSMethodCall *__fastcall SSParser::parse_operator(SSParser *this, SSParser::Args *args, __int64 a3, __int64 a4)
{
  SSParser::Args *v4; // rsi
  _DWORD *v5; // r14
  __int64 v6; // rdi
  unsigned int v7; // er15
  char *v8; // rbx
  char v9; // dl
  unsigned __int8 v10; // r10
  unsigned __int8 v11; // r11
  __int64 v12; // r8
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rbx
  SSClassDescBase *v17; // r12
  SSClass *v18; // r13
  SSParser *v19; // rax
  __int64 v20; // rax
  SSLiteralList *v21; // r15
  SSParser::eResult v22; // eax
  __int64 v23; // rcx
  SSClassDescBaseVtbl *v24; // rbx
  __int64 v25; // rax
  _DWORD *v26; // rax
  SSParser *v28; // [rsp+80h] [rbp+48h]
  char v29; // [rsp+88h] [rbp+50h]
  unsigned int end_pos_p; // [rsp+90h] [rbp+58h]
  unsigned int v31; // [rsp+98h] [rbp+60h]

  v28 = this;
  v4 = args;
  v31 = -1;
  v5 = 0i64;
  end_pos_p = args->i_start_pos;
  v6 = end_pos_p;
  v29 = 1;
  args->i_result = 0;
  v7 = this->i_str_ref_p->i_length;
  v8 = this->i_str_ref_p->i_cstr_p;
  v9 = 0;
  v10 = 0;
  LOBYTE(a4) = 0;
  v11 = 0;
  v12 = (unsigned int)(v6 + 1);
  if ( (unsigned int)v12 < v7 )
  {
    v9 = v8[v12];
    v13 = (unsigned int)(v6 + 2);
    if ( (unsigned int)v13 < v7 )
    {
      v10 = v8[v13];
      v14 = (unsigned int)(v6 + 3);
      if ( (unsigned int)v14 < v7 )
      {
        a4 = (unsigned __int8)v8[v14];
        v15 = (unsigned int)(v6 + 4);
        if ( (unsigned int)v15 < v7 )
          v11 = v8[v15];
      }
    }
  }
  switch ( v8[v6] )
  {
    case 33:
      if ( v9 != 61 )
        goto LABEL_77;
      LODWORD(v6) = v6 + 1;
      end_pos_p = v12;
      v4->i_result = 77;
      goto LABEL_78;
    case 38:
    case 94:
    case 124:
      goto $LN22_2;
    case 42:
      if ( v9 == 61 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        v31 = ASymbol_multiply_assign.i_uid;
      }
      else
      {
        LODWORD(v6) = v6 + 1;
        end_pos_p = v12;
        v31 = ASymbol_multiply.i_uid;
      }
      goto LABEL_78;
    case 43:
      if ( v9 == 43 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        v31 = ASymbol_increment.i_uid;
        v29 = 0;
      }
      else if ( v9 == 61 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        v31 = ASymbol_add_assign.i_uid;
      }
      else
      {
        LODWORD(v6) = v6 + 1;
        end_pos_p = v12;
        v31 = ASymbol_add.i_uid;
      }
      goto LABEL_78;
    case 45:
      if ( v9 == 45 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        v31 = ASymbol_decrement.i_uid;
        v29 = 0;
      }
      else if ( v9 == 61 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        v31 = ASymbol_subtract_assign.i_uid;
      }
      else
      {
        LODWORD(v6) = v6 + 1;
        end_pos_p = v12;
        v31 = ASymbol_subtract.i_uid;
      }
      goto LABEL_78;
    case 47:
      if ( v9 == 61 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        v31 = ASymbol_divide_assign.i_uid;
      }
      else
      {
        LODWORD(v6) = v6 + 1;
        end_pos_p = v12;
        v31 = ASymbol_divide.i_uid;
      }
      goto LABEL_78;
    case 58:
      if ( v9 != 61 )
        goto LABEL_77;
      LODWORD(v6) = v6 + 2;
      end_pos_p = v6;
      v31 = ASymbol_assign.i_uid;
      goto LABEL_78;
    case 60:
      if ( v9 == 60 )
      {
        LODWORD(v6) = v6 + 1;
        v4->i_result = 77;
      }
      else if ( v9 == 61 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        v31 = ASymbol_less_or_equal.i_uid;
        goto LABEL_78;
      }
      LODWORD(v6) = v6 + 1;
      end_pos_p = v6;
      v31 = ASymbol_less.i_uid;
      goto LABEL_78;
    case 61:
      LODWORD(v6) = v6 + 1;
      end_pos_p = v12;
      if ( v9 == 61 )
        v4->i_result = 77;
      else
        v31 = ASymbol_equals.i_uid;
      goto LABEL_78;
    case 62:
      if ( v9 == 61 )
      {
        LODWORD(v6) = v6 + 2;
        end_pos_p = v6;
        v31 = ASymbol_greater_or_equal.i_uid;
      }
      else
      {
        LODWORD(v6) = v6 + 1;
        end_pos_p = v12;
        v31 = ASymbol_greater.i_uid;
      }
      goto LABEL_78;
    case 97:
      if ( v9 != 110 || v10 != 100 || (_BYTE)a4 == 40 || !byte_14236F1C0[(unsigned __int8)a4] )
        goto LABEL_77;
      LODWORD(v6) = v6 + 3;
      end_pos_p = v6;
      v31 = ASymbol_and.i_uid;
      goto LABEL_78;
    case 110:
      if ( v9 == 97 )
      {
        if ( v10 == 110 && (_BYTE)a4 == 100 && v11 != 40 && byte_14236F1C0[v11] )
        {
          LODWORD(v6) = v6 + 4;
          end_pos_p = v6;
          v31 = ASymbol_nand.i_uid;
          goto LABEL_78;
        }
      }
      else if ( v9 == 111 )
      {
        if ( v10 == 114 && (_BYTE)a4 != 40 && byte_14236F1C0[(unsigned __int8)a4] )
        {
          LODWORD(v6) = v6 + 3;
          end_pos_p = v6;
          v31 = ASymbol_nor.i_uid;
          goto LABEL_78;
        }
      }
      else if ( v9 == 120 && v10 == 111 && (_BYTE)a4 == 114 && v11 != 40 && byte_14236F1C0[v11] )
      {
        LODWORD(v6) = v6 + 4;
        end_pos_p = v6;
        v31 = ASymbol_nxor.i_uid;
        goto LABEL_78;
      }
LABEL_77:
      v4->i_result = 55;
      goto LABEL_78;
    case 111:
      if ( v9 != 114 || v10 == 40 || !byte_14236F1C0[v10] )
        goto LABEL_77;
      LODWORD(v6) = v6 + 2;
      end_pos_p = v6;
      v31 = ASymbol_or.i_uid;
      goto LABEL_78;
    case 120:
      if ( v9 != 111 || v10 != 114 || (_BYTE)a4 == 40 || !byte_14236F1C0[(unsigned __int8)a4] )
        goto LABEL_77;
      LODWORD(v6) = v6 + 3;
      end_pos_p = v6;
      v31 = ASymbol_xor.i_uid;
      goto LABEL_78;
    case 126:
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
          v31 = ASymbol_not_equal.i_uid;
          goto LABEL_78;
        }
        LODWORD(v6) = v6 + 1;
        end_pos_p = v12;
        if ( v9 != 94 && v9 != 124 )
        {
          v31 = ASymbol_not.i_uid;
          v29 = 0;
          goto LABEL_78;
        }
      }
      v4->i_result = 78;
LABEL_78:
      if ( v4->i_result )
        goto LABEL_101;
      v16 = 0i64;
      v17 = v4->i_type_p;
      v18 = SSBrain::c_object_class_p;
      v19 = this;
      if ( this->i_flags.i_flagset & 1 )
      {
        v20 = ((__int64 (__fastcall *)(SSClassDescBase *, unsigned int *, __int64, __int64, signed __int64))v17->vfptr->get_method_inherited)(
                v4->i_type_p,
                &v31,
                v12,
                a4,
                -2i64);
        if ( v20 )
        {
          v16 = *(_QWORD *)(v20 + 24);
          v18 = (SSClass *)(*(__int64 (__fastcall **)(_QWORD, SSClassDescBase *))(**(_QWORD **)(v16 + 40) + 32i64))(
                             *(_QWORD *)(v16 + 40),
                             v17);
        }
        else
        {
          v4->i_result = 115;
        }
        v19 = v28;
      }
      if ( v4->i_result )
        goto LABEL_101;
      v21 = 0i64;
      if ( !v29 )
        goto LABEL_95;
      v22 = SSParser::parse_ws_any(v19, v6, &end_pos_p);
      v4->i_result = v22;
      if ( v22 )
      {
        LODWORD(v6) = end_pos_p;
      }
      else
      {
        v4->i_start_pos = end_pos_p;
        v21 = SSParser::parse_expression(v28, v4, 1i64);
        LODWORD(v6) = v4->i_end_pos;
        if ( v28->i_flags.i_flagset & 1 )
        {
          if ( v4->i_result )
            goto LABEL_101;
          if ( *(_DWORD *)(v16 + 8) )
            v23 = **(_QWORD **)(v16 + 16);
          else
            v23 = 0i64;
          v24 = v4->i_type_p->vfptr;
          v25 = (*(__int64 (__fastcall **)(_QWORD, SSClassDescBase *))(**(_QWORD **)(v23 + 16) + 32i64))(
                  *(_QWORD *)(v23 + 16),
                  v17);
          if ( !v24->is_class_type(v4->i_type_p, (SSClassDescBase *)v25) )
            v4->i_result = 136;
        }
      }
LABEL_95:
      if ( v4->i_result == Result_ok )
      {
        v4->i_type_p = (SSClassDescBase *)&v18->vfptr;
        if ( v4->i_flags & 1 )
        {
          v26 = AMemory::c_malloc_func(0x38ui64, "SSMethodCall");
          if ( v26 )
          {
            v26[2] = v31;
            *((_QWORD *)v26 + 2) = 0i64;
            *(_QWORD *)v26 = &SSInvokeBase::`vftable';
            v26[6] = 0;
            *((_QWORD *)v26 + 4) = 0i64;
            v26[10] = 0;
            *((_QWORD *)v26 + 6) = 0i64;
            *(_QWORD *)v26 = &SSMethodCall::`vftable';
            v5 = v26;
          }
          if ( v21 )
            APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
              (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *)(v5 + 6),
              (SSExpressionBase *)&v21->vfptr);
        }
      }
LABEL_101:
      v4->i_end_pos = v6;
      return (SSMethodCall *)v5;
    default:
      goto LABEL_77;
  }
}

// File Line: 6813
// RVA: 0x12BC40
SSCoroutineCall *__fastcall SSParser::parse_invoke_coroutine(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // rsi
  SSParser *v3; // rbp
  void (__fastcall ***v4)(_QWORD, signed __int64); // rdi
  void (__fastcall ***v5)(_QWORD, signed __int64); // rbx
  SSClass *v6; // r15
  unsigned int v7; // er12
  SSClassDescBase *v8; // r13
  SSParser::eResult v9; // er14
  unsigned int v10; // ebp
  ASymbol *v12; // r9
  SSParser::eResult v13; // eax
  SSParameters *params_p; // rbp
  __int64 v15; // rcx
  char v16; // al
  __int64 v17; // rax
  void (__fastcall ***v18)(_QWORD, signed __int64); // rax
  unsigned int v19; // edx
  APCompactArray<SSIdentifier,SSIdentifier,ACompareAddress<SSIdentifier> > *ret_args_p; // rcx
  APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v21; // r9
  SSParser::eResult v22; // eax
  SSParser *v23; // [rsp+A0h] [rbp+8h]
  void *v24; // [rsp+A8h] [rbp+10h]
  SSClass *v25; // [rsp+B0h] [rbp+18h]
  int v26; // [rsp+B8h] [rbp+20h]

  v23 = this;
  v2 = args;
  v3 = this;
  v4 = 0i64;
  v5 = 0i64;
  v6 = 0i64;
  v7 = args->i_start_pos;
  v8 = args->i_type_p;
  v25 = 0i64;
  LODWORD(v24) = v7;
  v9 = SSParser::parse_class(this, v7, (unsigned int *)&v24, &v25);
  if ( v9 )
  {
    v10 = (unsigned int)v24;
    if ( (_DWORD)v24 != v7 )
      goto LABEL_11;
    goto LABEL_9;
  }
  if ( v3->i_str_ref_p->i_length <= (unsigned int)v24 || v3->i_str_ref_p->i_cstr_p[(unsigned int)v24] != 64 )
  {
    v10 = v7;
LABEL_10:
    v9 = 0;
    goto LABEL_11;
  }
  v10 = (_DWORD)v24 + 1;
  v9 = 138;
  if ( !v8 || SSClass::is_scope_qualifier(v25, v8) )
  {
LABEL_9:
    v6 = v25;
    goto LABEL_10;
  }
LABEL_11:
  LODWORD(v25) = v10;
  v2->i_result = v9;
  if ( v9 )
  {
    v2->i_end_pos = v10;
    return 0i64;
  }
  v26 = -1;
  v12 = (ASymbol *)&v26;
  if ( !(v2->i_flags & 1) )
    v12 = 0i64;
  v13 = SSParser::parse_name_coroutine(v23, v10, (unsigned int *)&v25, v12);
  v2->i_result = v13;
  if ( v13 )
    goto LABEL_22;
  params_p = 0i64;
  if ( !(v23->i_flags.i_flagset & 1) )
  {
LABEL_24:
    if ( v2->i_flags & 1 )
    {
      v18 = (void (__fastcall ***)(_QWORD, signed __int64))AMemory::c_malloc_func(0x38ui64, "SSCoroutineCall");
      v5 = v18;
      v24 = v18;
      if ( v18 )
      {
        *((_DWORD *)v18 + 2) = v26;
        v18[2] = (void (__fastcall **)(_QWORD, signed __int64))v6;
        *v18 = (void (__fastcall **)(_QWORD, signed __int64))&SSInvokeBase::`vftable';
        *((_DWORD *)v18 + 6) = 0;
        v18[4] = 0i64;
        *((_DWORD *)v18 + 10) = 0;
        v18[6] = 0i64;
        *v18 = (void (__fastcall **)(_QWORD, signed __int64))&SSCoroutineCall::`vftable';
      }
      else
      {
        v5 = 0i64;
      }
    }
    v19 = (unsigned int)v25;
    v2->i_start_pos = (unsigned int)v25;
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
                          v23,
                          v19,
                          &v2->i_end_pos,
                          v21,
                          ret_args_p,
                          (SSClassUnaryBase *)v2->i_type_p,
                          params_p);
    v2->i_result = v22;
    if ( v22 )
    {
      if ( v5 )
        (**v5)(v5, 1i64);
    }
    else
    {
      v2->i_type_p = (SSClassDescBase *)&SSBrain::c_invoked_coroutine_class_p->vfptr;
      v4 = v5;
    }
    return (SSCoroutineCall *)v4;
  }
  v15 = (__int64)v2->i_type_p;
  if ( v6 )
  {
    v16 = (*(__int64 (**)(void))(*(_QWORD *)v15 + 88i64))();
    v15 = (__int64)v6;
    if ( v16 )
      v15 = (__int64)v6->vfptr->get_metaclass((SSClassDescBase *)&v6->vfptr);
  }
  v17 = (*(__int64 (__fastcall **)(__int64, int *))(*(_QWORD *)v15 + 184i64))(v15, &v26);
  if ( v17 )
  {
    params_p = *(SSParameters **)(v17 + 24);
    goto LABEL_24;
  }
  v2->i_result = 116;
LABEL_22:
  v2->i_end_pos = (unsigned int)v25;
  return (SSCoroutineCall *)v4;
}

// File Line: 6922
// RVA: 0x12CB60
SSMethodCall *__fastcall SSParser::parse_invoke_selector(SSParser *this, SSParser::Args *args, bool test_op)
{
  unsigned int v3; // esi
  bool v4; // bp
  SSParser::Args *v5; // rbx
  SSParser *v6; // rdi
  SSParser::eResult v7; // eax
  __int64 v8; // rdx
  char *v9; // r8
  unsigned __int8 v10; // cl
  SSMethodCall *result; // rax
  unsigned int end_pos_p; // [rsp+48h] [rbp+10h]
  __int64 v13; // [rsp+58h] [rbp+20h]

  v3 = args->i_start_pos;
  v4 = test_op;
  v5 = args;
  v6 = this;
  end_pos_p = v3;
  v13 = 0i64;
  v7 = SSParser::parse_class(this, v3, &end_pos_p, 0i64);
  if ( v7 )
  {
    LODWORD(v8) = end_pos_p;
    if ( end_pos_p == v3 )
      v7 = 0;
  }
  else if ( v6->i_str_ref_p->i_length <= end_pos_p || v6->i_str_ref_p->i_cstr_p[end_pos_p] != 64 )
  {
    v7 = 0;
    LODWORD(v8) = v3;
  }
  else
  {
    LODWORD(v8) = end_pos_p + 1;
    v7 = 0;
  }
  v5->i_result = v7;
  if ( v7 )
  {
LABEL_18:
    v5->i_end_pos = v8;
    return 0i64;
  }
  v9 = v6->i_str_ref_p->i_cstr_p;
  v10 = v9[(unsigned int)v8];
  v5->i_result = 40;
  if ( v10 == 95 )
  {
    v8 = (unsigned int)(v8 + 1);
    if ( AString::c_is_lowercase[(unsigned __int8)v9[v8]] )
      return (SSMethodCall *)SSParser::parse_invoke_coroutine(v6, v5);
    goto LABEL_18;
  }
  if ( v10 == 33 || AString::c_char_match_table[0][v10] )
    return SSParser::parse_invoke_method(v6, v5);
  if ( !v4 )
    goto LABEL_18;
  result = SSParser::parse_operator(v6, v5);
  if ( v5->i_end_pos == v3 )
    v5->i_result = 41;
  return result;
}

// File Line: 7098
// RVA: 0x12CC70
__int64 __fastcall SSParser::parse_literal_char_esc_seq(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, char *ch_p)
{
  char *v4; // rsi
  unsigned int *v5; // rdi
  SSParser::eResult v6; // er10
  char *v7; // r11
  unsigned int v8; // edx
  int v9; // ebx
  __int64 result; // rax
  int int_p; // [rsp+50h] [rbp+8h]
  unsigned int end_pos_pa; // [rsp+58h] [rbp+10h]

  v4 = ch_p;
  v5 = end_pos_p;
  v6 = 82;
  if ( this->i_str_ref_p->i_length - start_pos >= 2 )
  {
    v7 = this->i_str_ref_p->i_cstr_p;
    v6 = 13;
    if ( v7[start_pos] == 92 )
    {
      v8 = start_pos + 1;
      v6 = 0;
      v9 = v7[v8];
      start_pos = v8 + 1;
      switch ( v9 )
      {
        case 97:
          LOBYTE(v9) = 7;
          break;
        case 98:
          LOBYTE(v9) = 8;
          break;
        case 102:
          LOBYTE(v9) = 12;
          break;
        case 110:
          LOBYTE(v9) = 10;
          break;
        case 114:
          LOBYTE(v9) = 13;
          break;
        case 116:
          LOBYTE(v9) = 9;
          break;
        case 118:
          LOBYTE(v9) = 11;
          break;
        default:
          if ( AString::c_is_digit[(unsigned __int8)v9] )
          {
            end_pos_pa = start_pos - 1;
            v6 = SSParser::parse_literal_integer(this, start_pos - 1, &end_pos_pa, &int_p, 0i64);
            if ( v6 == Result_ok )
            {
              v6 = 14;
              if ( (unsigned int)int_p <= 0xFF )
              {
                LOBYTE(v9) = int_p;
                v6 = 0;
              }
            }
            start_pos = end_pos_pa;
          }
          break;
      }
      if ( v4 && v6 == Result_ok )
        *v4 = v9;
    }
  }
  result = (unsigned int)v6;
  if ( v5 )
    *v5 = start_pos;
  return result;
}

// File Line: 7211
// RVA: 0x12CDE0
__int64 __fastcall SSParser::parse_literal_integer(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, int *int_p, unsigned int *radix_p)
{
  AStringRef *v5; // rax
  unsigned int *v6; // r12
  int *v7; // r13
  __int64 v8; // rsi
  unsigned int v9; // er11
  char *v10; // r14
  signed int v11; // er10
  char *v12; // rbx
  char *v13; // r9
  char v14; // dl
  __int64 v15; // rax
  int v16; // ecx
  __int64 i; // rax
  bool v18; // r15
  unsigned __int8 v19; // dl
  unsigned int v20; // er8
  bool v21; // bl
  int v22; // edi
  int v23; // ecx
  int v24; // eax
  __int64 result; // rax
  int v26; // [rsp+48h] [rbp+10h]
  unsigned int *v27; // [rsp+50h] [rbp+18h]

  v27 = end_pos_p;
  v5 = this->i_str_ref_p;
  v6 = end_pos_p;
  v7 = int_p;
  LODWORD(v8) = start_pos;
  v9 = 82;
  if ( this->i_str_ref_p->i_length > start_pos )
  {
    v10 = v5->i_cstr_p;
    v11 = 10;
    v12 = &v5->i_cstr_p[start_pos];
    v13 = &v5->i_cstr_p[start_pos];
    if ( *v12 != 45 )
    {
      v14 = 0;
      v9 = 33;
    }
    else
    {
      v13 = v12 + 1;
      v14 = 1;
      v9 = 29;
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
      if ( v10[v8] != 114 )
      {
LABEL_36:
        if ( v7 )
          *v7 = v16;
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
          v19 = v10[v8];
          v9 = 9;
          v20 = v8;
          if ( v11 > 10 )
          {
            while ( 1 )
            {
              v21 = AString::c_is_digit[v19];
              if ( !v21 )
              {
                v22 = AString::c_char2lower[v19];
                if ( v22 < 97 || v22 > v11 + 86 )
                  break;
              }
              v23 = v11 * v16;
              if ( v21 )
                v24 = (char)v19 - 48;
              else
                v24 = AString::c_char2lower[v19] - 87;
              v16 = v24 + v23;
              v19 = v10[++v20];
            }
            v6 = v27;
          }
          else
          {
            while ( (char)v19 >= 48 && (char)v19 <= (char)(v11 + 47) )
            {
              v16 = (char)v19 + v11 * v16 - 48;
              v19 = v10[++v20];
            }
          }
          if ( v20 > (unsigned int)v8 )
          {
            if ( !byte_14236F1C0[v19] )
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
SSLiteralList *__fastcall SSParser::parse_literal_list(SSParser *this, SSParser::Args *args, SSTypedClass *list_class_p, bool item_type_b, SSMethodCall *ctor_p)
{
  bool v5; // r12
  SSTypedClass *v6; // r13
  SSParser::Args *v7; // rdi
  SSParser *v8; // r14
  SSLiteralList *v9; // r15
  SSTypedClass *v10; // rbx
  char *v11; // rcx
  SSParser::eResult v12; // eax
  SSClass *v13; // rsi
  SSClass *v14; // rax
  SSClass *v15; // rcx
  SSMethodCall *v16; // rax
  SSMethodCall *v17; // rsi
  SSParser::eResult v18; // eax
  SSClassUnion *v19; // r13
  bool v20; // cf
  SSLiteralList *v21; // rax
  SSParser::eResult v22; // eax
  char v23; // cl
  SSParser::eResult v24; // eax
  SSClass *v25; // rax
  SSTypedClass *v26; // rcx
  SSLiteralList *result; // rax
  char *v28; // [rsp+30h] [rbp-41h]
  SSClassUnion class_union; // [rsp+48h] [rbp-29h]
  unsigned int end_pos_p; // [rsp+D0h] [rbp+5Fh]
  SSClassUnaryBase *class_pp; // [rsp+D8h] [rbp+67h]
  SSTypedClass *v32; // [rsp+E0h] [rbp+6Fh]
  bool item_type_b_p; // [rsp+E8h] [rbp+77h]

  item_type_b_p = item_type_b;
  v32 = list_class_p;
  v5 = item_type_b;
  v6 = list_class_p;
  v7 = args;
  v8 = this;
  v9 = 0i64;
  v10 = (SSTypedClass *)args->i_start_pos;
  end_pos_p = args->i_start_pos;
  v11 = this->i_str_ref_p->i_cstr_p;
  v28 = v11;
  args->i_result = 0;
  if ( list_class_p || v11[(_QWORD)v10] == 123 )
    goto LABEL_13;
  v12 = (unsigned int)SSParser::parse_class_instance(v8, (unsigned int)v10, &end_pos_p, &class_pp, &item_type_b_p);
  v7->i_result = v12;
  if ( v12
    || (v7->i_result = 134,
        v13 = SSBrain::c_list_class_p,
        v10 = (SSTypedClass *)class_pp,
        v14 = class_pp->vfptr->get_key_class((SSClassDescBase *)class_pp),
        v13 != v14)
    && ((v15 = v14->i_superclass_p) == 0i64 || !SSClass::is_class(v15, v13)) )
  {
    v11 = v28;
    LODWORD(v10) = end_pos_p;
    v5 = item_type_b_p;
LABEL_13:
    v17 = ctor_p;
    goto LABEL_14;
  }
  v6 = v10;
  v32 = v10;
  v7->i_type_p = (SSClassDescBase *)&v10->vfptr;
  v7->i_start_pos = end_pos_p;
  v16 = SSParser::parse_invoke_ctor(v8, v7);
  v17 = v16;
  LODWORD(v10) = v7->i_end_pos;
  end_pos_p = v7->i_end_pos;
  if ( v16 && v16->i_name.i_uid == ASymbolX_ctor.i_uid && !v16->i_arguments.i_count )
  {
    v16->vfptr->__vecDelDtor((SSInvokeBase *)&v16->vfptr, 1u);
    v17 = 0i64;
  }
  v5 = item_type_b_p;
  v11 = v28;
LABEL_14:
  if ( v7->i_result == Result_ok )
  {
    v7->i_result = 82;
    LODWORD(class_pp) = v8->i_str_ref_p->i_length;
    if ( (unsigned int)((_DWORD)class_pp - (_DWORD)v10) >= 2 )
    {
      v7->i_result = 43;
      if ( v11[(unsigned int)v10] == 123 )
      {
        v18 = SSParser::parse_ws_any(v8, (_DWORD)v10 + 1, &end_pos_p);
        v7->i_result = v18;
        if ( v18 )
        {
          LODWORD(v10) = end_pos_p;
        }
        else
        {
          class_union.i_ref_count = 0;
          class_union.vfptr = (SSClassDescBaseVtbl *)&SSClassUnion::`vftable';
          class_union.i_common_class_p = 0i64;
          class_union.i_union.i_count = 0;
          class_union.i_union.i_array_p = 0i64;
          class_union.i_union.i_size = 0;
          if ( v5 )
            v19 = (SSClassUnion *)v6->vfptr->get_item_type((SSClassDescBase *)&v6->vfptr);
          else
            v19 = &class_union;
          if ( v7->i_flags & 1 )
          {
            v9 = (SSLiteralList *)AMemory::c_malloc_func(0x20ui64, "SSLiteralList");
            if ( v9 )
            {
              v9->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
              v9->vfptr = (SSExpressionBaseVtbl *)&SSLiteralList::`vftable';
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
          LODWORD(v10) = end_pos_p;
          if ( v28[end_pos_p] == 125 )
          {
            LODWORD(v10) = end_pos_p + 1;
            if ( !v5 )
              v19 = (SSClassUnion *)SSBrain::c_object_class_p;
          }
          else
          {
            while ( 1 )
            {
              v20 = (unsigned int)v10 < (unsigned int)class_pp;
              v7->i_result = 82;
              if ( !v20 )
                break;
              v7->i_start_pos = (unsigned int)v10;
              v21 = SSParser::parse_expression(v8, v7, 1i64);
              LODWORD(v10) = v7->i_end_pos;
              end_pos_p = v7->i_end_pos;
              if ( v7->i_result )
                break;
              if ( v21 )
                APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
                  &v9->i_item_exprs,
                  (SSExpressionBase *)&v21->vfptr);
              if ( v8->i_flags.i_flagset & 1 )
              {
                if ( v5 )
                {
                  if ( !v7->i_type_p->vfptr->is_class_type(v7->i_type_p, (SSClassDescBase *)&v19->vfptr) )
                  {
                    v7->i_result = 135;
                    break;
                  }
                }
                else
                {
                  SSClassUnion::merge_class(&class_union, v7->i_type_p);
                }
              }
              v22 = SSParser::parse_ws_any(v8, (unsigned int)v10, &end_pos_p);
              v7->i_result = v22;
              if ( v22 )
                goto LABEL_72;
              LODWORD(v10) = end_pos_p;
              v23 = v28[end_pos_p];
              if ( v23 == 125 )
              {
                LODWORD(v10) = end_pos_p + 1;
                break;
              }
              if ( v23 != 44 )
              {
                v7->i_result = 44;
                break;
              }
              v24 = SSParser::parse_ws_any(v8, end_pos_p + 1, &end_pos_p);
              v7->i_result = v24;
              if ( v24 )
              {
LABEL_72:
                LODWORD(v10) = end_pos_p;
                break;
              }
              LODWORD(v10) = end_pos_p;
            }
          }
          if ( v8->i_flags.i_flagset & 1 && v7->i_result == Result_ok )
          {
            if ( v5 )
            {
              v26 = v32;
            }
            else
            {
              if ( v19 == &class_union )
              {
                if ( class_union.i_union.i_count > 1 )
                  v19 = SSClassUnion::get_or_create(&class_union);
                else
                  v19 = (SSClassUnion *)class_union.i_common_class_p;
              }
              if ( v32 )
                v25 = (SSClass *)((__int64 (*)(void))v32->vfptr->get_key_class)();
              else
                v25 = SSBrain::c_list_class_p;
              v26 = SSTypedClass::get_or_create(v25, (SSClassDescBase *)&v19->vfptr);
            }
            v7->i_type_p = (SSClassDescBase *)&v26->vfptr;
          }
          SSClassUnion::~SSClassUnion(&class_union);
        }
      }
    }
  }
  if ( v7->i_result )
  {
    if ( v17 )
      v17->vfptr->__vecDelDtor((SSInvokeBase *)&v17->vfptr, 1u);
    if ( v9 )
      v9->vfptr->__vecDelDtor((SSExpressionBase *)&v9->vfptr, 1u);
    result = 0i64;
  }
  else
  {
    result = v9;
  }
  v7->i_end_pos = (unsigned int)v10;
  return result;
}

// File Line: 7589
// RVA: 0x12D3C0
SSLiteral *__fastcall SSParser::parse_literal_number(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // rdi
  SSParser *v3; // rsi
  unsigned int v4; // ebp
  _QWORD *v5; // rbx
  float *v6; // r9
  SSParser::eResult v7; // eax
  unsigned int v8; // eax
  int *v9; // r9
  SSParser::eResult v10; // edx
  _QWORD *v12; // [rsp+30h] [rbp-48h]
  __int64 v13; // [rsp+38h] [rbp-40h]
  _QWORD *v14; // [rsp+40h] [rbp-38h]
  unsigned int end_pos_p; // [rsp+88h] [rbp+10h]
  __int64 v16; // [rsp+90h] [rbp+18h]
  unsigned int v17; // [rsp+98h] [rbp+20h]

  v13 = -2i64;
  v2 = args;
  v3 = this;
  v17 = 0;
  v4 = args->i_start_pos;
  v5 = 0i64;
  v6 = (float *)&v17;
  if ( !(args->i_flags & 1) )
    v6 = 0i64;
  v7 = SSParser::parse_literal_real(this, v4, (unsigned int *)&v16, v6);
  v2->i_result = v7;
  if ( v7 )
  {
    LODWORD(v12) = 0;
    v9 = (int *)&v12;
    if ( !(v2->i_flags & 1) )
      v9 = 0i64;
    v10 = (unsigned int)SSParser::parse_literal_integer(v3, v4, &end_pos_p, v9, 0i64);
    if ( v10 )
    {
      v8 = v16;
      if ( end_pos_p >= (unsigned int)v16 )
      {
        v8 = end_pos_p;
        v2->i_result = v10;
      }
    }
    else
    {
      if ( v2->i_flags & 1 )
      {
        v5 = AMemory::c_malloc_func(0x18ui64, "SSLiteral");
        v14 = v5;
        if ( v5 )
        {
          LODWORD(v16) = (_DWORD)v12;
          *v5 = &SSExpressionBase::`vftable';
          *v5 = &SSLiteral::`vftable';
          v5[1] = v16;
          *((_DWORD *)v5 + 4) = 2;
        }
        else
        {
          v5 = 0i64;
        }
        v2->i_type_p = (SSClassDescBase *)&SSBrain::c_integer_class_p->vfptr;
      }
      v8 = end_pos_p;
      v2->i_result = 0;
    }
  }
  else
  {
    if ( v2->i_flags & 1 )
    {
      v5 = AMemory::c_malloc_func(0x18ui64, "SSLiteral");
      v12 = v5;
      if ( v5 )
      {
        end_pos_p = v17;
        *v5 = &SSExpressionBase::`vftable';
        *v5 = &SSLiteral::`vftable';
        v5[1] = *(_QWORD *)&end_pos_p;
        *((_DWORD *)v5 + 4) = 3;
      }
      else
      {
        v5 = 0i64;
      }
      v2->i_type_p = (SSClassDescBase *)&SSBrain::c_real_class_p->vfptr;
    }
    v8 = v16;
  }
  v2->i_end_pos = v8;
  return (SSLiteral *)v5;
}

// File Line: 7670
// RVA: 0x12D550
__int64 __fastcall SSParser::parse_literal_real(SSParser *this, __int64 start_pos, unsigned int *end_pos_p, float *real_p)
{
  AStringRef *v4; // rax
  float *v5; // r13
  unsigned int *v6; // r12
  SSParser *v7; // r15
  unsigned int v8; // er11
  char *v9; // rsi
  char *v10; // rdi
  char *v11; // r10
  char v12; // bp
  __int64 v13; // rax
  int v14; // er9
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
  int int_p; // [rsp+90h] [rbp+8h]
  unsigned int end_pos_pa; // [rsp+98h] [rbp+10h]

  v4 = this->i_str_ref_p;
  v5 = real_p;
  v6 = end_pos_p;
  v7 = this;
  v8 = 82;
  if ( this->i_str_ref_p->i_length > (unsigned int)start_pos )
  {
    v9 = v4->i_cstr_p;
    v10 = &v4->i_cstr_p[(unsigned int)start_pos];
    v11 = v10;
    if ( *v10 != 45 )
    {
      v12 = 0;
      v8 = 33;
    }
    else
    {
      v11 = v10 + 1;
      v12 = 1;
      v8 = 29;
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
      v19 = v9[start_pos] == 46;
      v20 = 0.0;
      int_p = 0;
      if ( v19 )
      {
        start_pos = (unsigned int)(start_pos + 1);
        v18 = 1;
        v8 = 29;
        v21 = (unsigned __int8)v9[start_pos];
        if ( !AString::c_is_digit[v21] )
        {
LABEL_24:
          if ( v5 && !v8 )
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
                if ( v28 & 1 )
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
            *v5 = v31;
          }
          goto LABEL_42;
        }
        v22 = DOUBLE_1_0;
        do
        {
          v23 = (char)v21;
          start_pos = (unsigned int)(start_pos + 1);
          v22 = v22 * 0.1;
          v21 = (unsigned __int8)v9[start_pos];
          v20 = v20 + (double)(v23 - 48) * v22;
        }
        while ( AString::c_is_digit[v21] );
        v8 = 0;
      }
      if ( !((v9[start_pos] - 69) & 0xDF) )
      {
        v17 = 1;
        end_pos_pa = start_pos + 1;
        v24 = SSParser::parse_literal_simple_int(v7, start_pos + 1, &end_pos_pa, &int_p, 0i64);
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
  if ( v6 )
    *v6 = start_pos;
  return result;
}

// File Line: 7776
// RVA: 0x12D7D0
__int64 __fastcall SSParser::parse_literal_simple_int(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, int *int_p, bool *negative_p)
{
  int *v5; // rdi
  char *v6; // rbx
  unsigned int v7; // ebp
  unsigned int v8; // er11
  char *v9; // r10
  bool v10; // r9
  __int64 v11; // rax
  int v12; // eax
  __int64 i; // rdx
  int v14; // ecx
  int v15; // eax
  __int64 result; // rax

  v5 = int_p;
  v6 = &this->i_str_ref_p->i_cstr_p[start_pos];
  v7 = start_pos;
  v8 = 82;
  v9 = &this->i_str_ref_p->i_cstr_p[start_pos];
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
      if ( v5 )
      {
        if ( v10 )
          v12 = -v12;
        *v5 = v12;
      }
      if ( negative_p )
        *negative_p = v10;
      v8 = 0;
    }
  }
  result = v8;
  if ( end_pos_p )
    *end_pos_p = v7 + (_DWORD)v9 - (_DWORD)v6;
  return result;
}

// File Line: 7862
// RVA: 0x12D8B0
__int64 __fastcall SSParser::parse_literal_simple_string(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, AString *str_p)
{
  __int64 v4; // rdi
  AString *v5; // r14
  AStringRef *v6; // r9
  SSParser *v7; // r10
  unsigned int v8; // esi
  unsigned int v9; // edx
  char *v10; // r12
  unsigned int v11; // ebp
  unsigned int v12; // er13
  unsigned int i; // ebx
  char v14; // cl
  unsigned int v15; // er8
  int v16; // er15
  unsigned int v17; // ebp
  char v18; // cl
  unsigned int v19; // eax
  unsigned int end_pos_pa; // [rsp+20h] [rbp-48h]
  char *v22; // [rsp+28h] [rbp-40h]
  SSParser *v23; // [rsp+70h] [rbp+8h]
  char ch_p; // [rsp+78h] [rbp+10h]
  unsigned int *v25; // [rsp+80h] [rbp+18h]

  v25 = end_pos_p;
  v23 = this;
  v4 = start_pos;
  v5 = str_p;
  v6 = this->i_str_ref_p;
  v7 = this;
  v8 = 82;
  v9 = this->i_str_ref_p->i_length;
  if ( (unsigned int)(this->i_str_ref_p->i_length - v4) >= 2 )
  {
    v10 = v6->i_cstr_p;
    v8 = 45;
    if ( v6->i_cstr_p[v4] == 34 )
    {
      v8 = 0;
      v11 = v4 + 1;
      v12 = 0;
      v22 = 0i64;
      for ( i = v4 + 1; i < v9; ++i )
      {
        v14 = v10[i];
        if ( v14 == 34 )
          break;
        if ( v14 == 92 )
          ++i;
      }
      if ( v5 )
      {
        v12 = v5->i_str_ref_p->i_length;
        v15 = i + v5->i_str_ref_p->i_length - v4 - 1;
        if ( v15 >= v5->i_str_ref_p->i_size || v5->i_str_ref_p->i_ref_count + v5->i_str_ref_p->i_read_only != 1 )
          AString::set_size(v5, v15);
        if ( v5->i_str_ref_p->i_ref_count + v5->i_str_ref_p->i_read_only != 1 )
          AString::make_writeable(v5);
        v7 = v23;
        v22 = v5->i_str_ref_p->i_cstr_p;
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
          v18 = v10[(unsigned int)v4];
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
          if ( v5 )
            v22[v17] = v18;
          v7 = v23;
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
      if ( v5 )
        AString::set_length(v5, v12);
    }
  }
  if ( v25 )
    *v25 = v4;
  return v8;
}

// File Line: 7990
// RVA: 0x12DA60
unsigned int __fastcall SSParser::parse_literal_string(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, AString *str_p)
{
  unsigned int *v4; // r12
  AString *v5; // r15
  SSParser *v6; // r14
  unsigned int result; // eax
  unsigned int v8; // ebx
  unsigned int v9; // edi
  char *v10; // rbp
  unsigned int v11; // edx
  unsigned int v12; // esi
  unsigned int v13; // [rsp+20h] [rbp-38h]
  unsigned int start_posa; // [rsp+68h] [rbp+10h]
  unsigned int end_pos_pa; // [rsp+70h] [rbp+18h]

  start_posa = start_pos;
  v4 = end_pos_p;
  v5 = str_p;
  v6 = this;
  result = SSParser::parse_literal_simple_string(this, start_pos, &start_posa, str_p);
  v8 = start_posa;
  if ( !result )
  {
    v9 = v6->i_str_ref_p->i_length;
    v10 = v6->i_str_ref_p->i_cstr_p;
    if ( start_posa < v9 )
    {
      do
      {
        result = SSParser::parse_ws_any(v6, v8, &end_pos_pa);
        if ( result )
          break;
        v11 = end_pos_pa;
        if ( end_pos_pa >= v9 )
          break;
        if ( v10[end_pos_pa] != 43 )
          break;
        ++end_pos_pa;
        result = SSParser::parse_ws_any(v6, v11 + 1, &end_pos_pa);
        if ( result )
          break;
        v12 = end_pos_pa;
        if ( end_pos_pa >= v9 )
          break;
        result = SSParser::parse_literal_simple_string(v6, end_pos_pa, &v13, v5);
        if ( result )
        {
          if ( v13 == v12 )
            result = 0;
          break;
        }
        v8 = v13;
      }
      while ( v13 < v9 );
    }
  }
  if ( v4 )
    *v4 = v8;
  return result;
}

// File Line: 8074
// RVA: 0x12DB50
__int64 __fastcall SSParser::parse_literal_symbol(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, ASymbol *sym_p)
{
  unsigned int v4; // esi
  ASymbol *v5; // r12
  unsigned int *v6; // r15
  unsigned int v7; // ebx
  SSParser *v8; // r14
  unsigned int v9; // edi
  char *v10; // rbp
  unsigned int v11; // edx
  bool v12; // al
  __int64 v13; // rsi
  char v14; // cl
  unsigned int v15; // eax
  __int64 result; // rax
  char cstr_p[256]; // [rsp+30h] [rbp-138h]
  unsigned int find_pos_p; // [rsp+170h] [rbp+8h]
  char ch_p; // [rsp+178h] [rbp+10h]
  unsigned int end_pos_pa; // [rsp+180h] [rbp+18h]

  v4 = this->i_str_ref_p->i_length;
  v5 = sym_p;
  v6 = end_pos_p;
  v7 = start_pos;
  v8 = this;
  v9 = 46;
  if ( v4 - start_pos >= 2 )
  {
    v10 = this->i_str_ref_p->i_cstr_p;
    if ( v10[start_pos] == 39 )
    {
      v7 = start_pos + 1;
      v11 = start_pos + 1;
      do
      {
        find_pos_p = v4;
        v12 = AString::find((AString *)&v8->i_str_ref_p, 39, 1u, &find_pos_p, v11, 0xFFFFFFFF);
        v11 = find_pos_p;
      }
      while ( find_pos_p != v4 && v10[find_pos_p - 1] == 92 );
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
          if ( v5 )
          {
            cstr_p[v13] = 0;
            v5->i_uid = ASymbol::create((ASymbol *)&ch_p, cstr_p, v13, 0)->i_uid;
          }
        }
      }
      else
      {
        while ( !v9 )
        {
          v14 = v10[v7];
          ch_p = v14;
          if ( v14 == 92 )
          {
            v15 = SSParser::parse_literal_char_esc_seq(v8, v7, &end_pos_pa, &ch_p);
            v7 = end_pos_pa;
            v11 = find_pos_p;
            v14 = ch_p;
            v9 = v15;
          }
          else
          {
            end_pos_pa = ++v7;
          }
          cstr_p[v13] = v14;
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
  if ( v6 )
    *v6 = v7;
  return result;
}

// File Line: 8165
// RVA: 0x12DCF0
SSLoopExit *__fastcall SSParser::parse_loop_exit(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // rbx
  SSParser *v3; // r14
  __int64 v4; // rdx
  char *v5; // r8
  __int64 v6; // rsi
  SSLoopExit *v7; // rdi
  SSParser::eResult v8; // eax
  ASymbol *v9; // r9
  SSParser::eResult v10; // eax
  SSLoopExit *v11; // rcx
  SSLoopExit *result; // rax
  unsigned int end_pos_p; // [rsp+58h] [rbp+10h]
  unsigned int v14; // [rsp+60h] [rbp+18h]

  v2 = args;
  v3 = this;
  args->i_result = 82;
  v4 = args->i_start_pos;
  if ( (unsigned int)(this->i_str_ref_p->i_length - v4) >= 4
    && (v2->i_result = 49, v5 = this->i_str_ref_p->i_cstr_p, v5[v4] == 101)
    && v5[(unsigned int)(v4 + 1)] == 120
    && v5[(unsigned int)(v4 + 2)] == 105
    && v5[(unsigned int)(v4 + 3)] == 116
    && (v6 = (unsigned int)(v4 + 4), byte_14236F1C0[(unsigned __int8)v5[v6]]) )
  {
    v7 = 0i64;
    end_pos_p = v4 + 4;
    v8 = SSParser::parse_ws_any(this, v6, &end_pos_p);
    v2->i_result = v8;
    if ( v8 == Result_ok )
    {
      v14 = -1;
      v9 = (ASymbol *)&v14;
      if ( !(v2->i_flags & 1) )
        v9 = 0i64;
      v10 = SSParser::parse_name_instance(v3, end_pos_p, &end_pos_p, v9);
      v2->i_result = v10;
      if ( v10 )
        v2->i_result = 0;
      else
        LODWORD(v6) = end_pos_p;
      if ( v2->i_flags & 1 )
      {
        v11 = (SSLoopExit *)AMemory::c_malloc_func(0x10ui64, "SSLoopExit");
        if ( v11 )
        {
          v11->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
          v11->vfptr = (SSExpressionBaseVtbl *)&SSLoopExit::`vftable';
          v11->i_name.i_uid = v14;
          v7 = v11;
        }
      }
    }
    if ( v2->i_result == Result_ok )
      v2->i_type_p = (SSClassDescBase *)&SSBrain::c_none_class_p->vfptr;
    v2->i_end_pos = v6;
    result = v7;
  }
  else
  {
    v2->i_end_pos = v4;
    result = 0i64;
  }
  return result;
}

// File Line: 8258
// RVA: 0x12DE50
SSLoop *__fastcall SSParser::parse_loop_tail(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // rbx
  SSParser *v3; // r14
  unsigned int v4; // edi
  SSParser::eResult v5; // eax
  ASymbol *v6; // r9
  SSLoop *v7; // rsi
  SSCode *v8; // rax
  SSCode *v9; // rdi
  SSLoop *v10; // rax
  SSLoop *result; // rax
  unsigned int start_pos; // [rsp+50h] [rbp+8h]
  unsigned int end_pos_p; // [rsp+58h] [rbp+10h]
  unsigned int v14; // [rsp+60h] [rbp+18h]

  v2 = args;
  v3 = this;
  args->i_result = 82;
  v4 = args->i_start_pos;
  end_pos_p = v4;
  if ( this->i_str_ref_p->i_length - v4 < 2 )
    goto LABEL_18;
  v5 = SSParser::parse_ws_any(this, v4, &end_pos_p);
  v2->i_result = v5;
  v4 = end_pos_p;
  v2->i_end_pos = end_pos_p;
  if ( v5 )
    goto LABEL_18;
  v14 = -1;
  v6 = (ASymbol *)&v14;
  v7 = 0i64;
  if ( !(v2->i_flags & 1) )
    v6 = 0i64;
  if ( SSParser::parse_name_instance(v3, v4, &start_pos, v6) )
  {
    v2->i_result = 0;
  }
  else
  {
    v2->i_result = SSParser::parse_ws_any(v3, start_pos, &end_pos_p);
    v4 = end_pos_p;
  }
  if ( v2->i_result || (v2->i_result = 48, v3->i_str_ref_p->i_cstr_p[v4] != 91) )
  {
LABEL_18:
    v2->i_end_pos = v4;
    result = 0i64;
  }
  else
  {
    v2->i_start_pos = v4;
    v8 = SSParser::parse_code_block_optimized(v3, v2, SSInvokeTime_any, 0);
    v9 = v8;
    if ( v2->i_result == Result_ok )
    {
      v2->i_type_p = (SSClassDescBase *)&SSBrain::c_none_class_p->vfptr;
      if ( v8 )
      {
        v10 = (SSLoop *)AMemory::c_malloc_func(0x18ui64, "SSLoop");
        *(_QWORD *)&start_pos = v10;
        if ( v10 )
        {
          v10->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
          v10->vfptr = (SSExpressionBaseVtbl *)&SSLoop::`vftable';
          v10->i_name.i_uid = v14;
          v10->i_expr_p = (SSExpressionBase *)&v9->vfptr;
          v7 = v10;
        }
      }
    }
    result = v7;
  }
  return result;
}

// File Line: 8585
// RVA: 0x12DFA0
__int64 __fastcall SSParser::parse_name_class(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, ASymbol *name_p, SSParser::eClassCheck check)
{
  SSParser *v5; // rsi
  AStringRef *v6; // rcx
  unsigned int v7; // ebx
  ASymbol *v8; // rdi
  unsigned int *v9; // r14
  unsigned int v10; // er11
  unsigned int v11; // eax
  SSClass **v12; // r8
  SSClass **v13; // r10
  signed __int64 v14; // rcx
  unsigned int v15; // er9
  _BOOL8 v16; // rdx
  _BOOL8 v17; // r9
  char v18; // cl
  __int64 v19; // rax
  ASymbol result; // [rsp+50h] [rbp+8h]
  unsigned int find_pos_p; // [rsp+58h] [rbp+10h]

  v5 = this;
  v6 = this->i_str_ref_p;
  v7 = start_pos;
  find_pos_p = start_pos;
  v8 = name_p;
  v9 = end_pos_p;
  v10 = 82;
  if ( v6->i_length > start_pos )
  {
    v10 = 15;
    if ( AString::c_is_uppercase[(unsigned __int8)v6->i_cstr_p[start_pos]] )
    {
      find_pos_p = start_pos + 1;
      find_pos_p = v6->i_length;
      AString::find((AString *)&v5->i_str_ref_p, ACharMatch_not_identifier, 1u, &find_pos_p, start_pos + 1, 0xFFFFFFFF);
      if ( check & 1 )
      {
        v11 = SSParser::as_symbol(v5, &result, v7, find_pos_p)->i_uid;
        if ( check & 2 && v11 == ASymbol_Class.i_uid )
        {
          v10 = 74;
        }
        else
        {
          if ( SSBrain::c_classes.i_count )
          {
            v12 = SSBrain::c_classes.i_array_p;
            v13 = &SSBrain::c_classes.i_array_p[SSBrain::c_classes.i_count - 1];
            while ( 1 )
            {
              while ( 1 )
              {
                v14 = (signed __int64)&v12[((char *)v13 - (char *)v12) >> 4];
                v15 = *(_DWORD *)(*(_QWORD *)v14 + 8i64);
                if ( v11 >= v15 )
                {
                  v16 = v11 == v15;
                  v17 = v11 != v15;
                  if ( 1 - v16 >= 0 )
                    break;
                }
                if ( v12 == (SSClass **)v14 )
                  goto LABEL_17;
                v13 = (SSClass **)(v14 - 8);
              }
              if ( v17 <= 0 )
                break;
              if ( v13 == (SSClass **)v14 )
                goto LABEL_17;
              v12 = (SSClass **)(v14 + 8);
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
        if ( v8 )
          v8->i_uid = v11;
      }
      else
      {
        if ( v8 )
          v8->i_uid = SSParser::as_symbol(v5, &result, v7, find_pos_p)->i_uid;
        if ( check & 2 && v8 && v8->i_uid == ASymbol_Class.i_uid )
          v10 = 74;
        else
          v10 = 0;
      }
    }
  }
  v19 = v10;
  if ( v9 )
    *v9 = find_pos_p;
  return v19;
}

// File Line: 8655
// RVA: 0x12E210
__int64 __fastcall SSParser::parse_name_instance(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, ASymbol *name_p)
{
  __int64 v4; // rbx
  AStringRef *v5; // rdx
  ASymbol *v6; // r14
  unsigned int *v7; // rsi
  SSParser *v8; // rdi
  unsigned int v9; // er11
  ASymbol *v10; // rax
  unsigned int v11; // eax
  unsigned int v12; // er8
  ASymbol **v13; // rcx
  ASymbol **v14; // r9
  __int64 v15; // rax
  ASymbol result; // [rsp+50h] [rbp+8h]
  unsigned int find_pos_p; // [rsp+58h] [rbp+10h]

  v4 = start_pos;
  v5 = this->i_str_ref_p;
  v6 = name_p;
  find_pos_p = v4;
  v7 = end_pos_p;
  v8 = this;
  v9 = 82;
  if ( v5->i_length <= (unsigned int)v4 )
    goto LABEL_11;
  v9 = 32;
  if ( !AString::c_is_lowercase[(unsigned __int8)v5->i_cstr_p[v4]] )
    goto LABEL_11;
  find_pos_p = v4 + 1;
  find_pos_p = v5->i_length;
  AString::find((AString *)&this->i_str_ref_p, ACharMatch_not_identifier, 1u, &find_pos_p, v4 + 1, 0xFFFFFFFF);
  v10 = SSParser::as_symbol(v8, &result, v4, find_pos_p);
  v9 = 0;
  v11 = v10->i_uid;
  v12 = 0;
  if ( SSParser::c_reserved_word_syms.i_count )
  {
    v13 = SSParser::c_reserved_word_syms.i_array_p;
    v14 = &SSParser::c_reserved_word_syms.i_array_p[SSParser::c_reserved_word_syms.i_count - 1];
    if ( SSParser::c_reserved_word_syms.i_array_p <= v14 )
    {
      do
      {
        if ( v11 == (*v13)->i_uid )
        {
          if ( v12 < 2 )
          {
            v9 = 89;
            goto LABEL_11;
          }
          --v12;
        }
        ++v13;
      }
      while ( v13 <= v14 );
    }
  }
  if ( v6 )
    v6->i_uid = v11;
LABEL_11:
  v15 = v9;
  if ( v7 )
    *v7 = find_pos_p;
  return v15;
}

// File Line: 8731
// RVA: 0x12E310
__int64 __fastcall SSParser::parse_name_method(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, ASymbol *name_p)
{
  __int64 v4; // rsi
  __int64 v5; // r10
  AStringRef *v6; // rdx
  ASymbol *v7; // rdi
  unsigned int *v8; // r15
  SSParser *v9; // r14
  unsigned int v10; // ebx
  char *v11; // rcx
  unsigned __int8 v12; // r8
  unsigned __int8 v13; // cl
  __int64 v14; // rax
  ASymbol result; // [rsp+50h] [rbp+8h]
  unsigned int end_pos_pa; // [rsp+58h] [rbp+10h]

  v4 = start_pos;
  LODWORD(v5) = start_pos;
  v6 = this->i_str_ref_p;
  end_pos_pa = v4;
  v7 = name_p;
  v8 = end_pos_p;
  v9 = this;
  v10 = 82;
  if ( v6->i_length <= (unsigned int)v4 )
    goto LABEL_17;
  v11 = v6->i_cstr_p;
  v10 = 53;
  v12 = v6->i_cstr_p[v4];
  if ( v12 != 33 )
  {
    if ( AString::c_is_lowercase[v12] )
    {
      end_pos_pa = v4 + 1;
      end_pos_pa = v6->i_length;
      AString::find((AString *)&v9->i_str_ref_p, ACharMatch_not_identifier, 1u, &end_pos_pa, v4 + 1, 0xFFFFFFFF);
      if ( v7 )
        v7->i_uid = SSParser::as_symbol(v9, &result, v4, end_pos_pa)->i_uid;
      v10 = 0;
    }
    else
    {
      if ( !AString::c_is_uppercase[v12] )
        goto LABEL_17;
      v10 = SSParser::parse_name_class(v9, v4, &end_pos_pa, name_p, (SSParser::eClassCheck)((name_p != 0i64) + 2));
    }
    goto LABEL_16;
  }
  v5 = (unsigned int)(v4 + 1);
  v10 = 0;
  end_pos_pa = v4 + 1;
  v13 = v11[v5];
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
    SSParser::parse_name_symbol(v9, v4, &end_pos_pa, name_p);
LABEL_16:
    LODWORD(v5) = end_pos_pa;
    goto LABEL_17;
  }
  if ( name_p )
    name_p->i_uid = ASymbolX_ctor.i_uid;
LABEL_17:
  v14 = v10;
  if ( v8 )
    *v8 = v5;
  return v14;
}

// File Line: 8831
// RVA: 0x12E130
__int64 __fastcall SSParser::parse_name_coroutine(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, ASymbol *name_p)
{
  unsigned int *v4; // rdi
  AStringRef *v5; // r8
  __int64 v6; // rbx
  ASymbol *v7; // r14
  SSParser *v8; // rsi
  unsigned int v9; // er11
  __int64 v10; // r10
  char *v11; // rdx
  unsigned int v12; // er10
  __int64 v13; // rax
  ASymbol result; // [rsp+50h] [rbp+8h]
  unsigned int find_pos_p; // [rsp+58h] [rbp+10h]

  v4 = end_pos_p;
  v5 = this->i_str_ref_p;
  v6 = start_pos;
  find_pos_p = start_pos;
  v7 = name_p;
  v8 = this;
  v9 = 82;
  LODWORD(v10) = start_pos;
  if ( v5->i_length - start_pos >= 2 )
  {
    v11 = v5->i_cstr_p;
    v9 = 61;
    if ( v5->i_cstr_p[v6] == 95 )
    {
      v10 = (unsigned int)(v6 + 1);
      find_pos_p = v6 + 1;
      if ( AString::c_is_lowercase[(unsigned __int8)v11[v10]] )
      {
        v12 = v10 + 1;
        find_pos_p = v12;
        find_pos_p = v5->i_length;
        AString::find((AString *)&this->i_str_ref_p, ACharMatch_not_identifier, 1u, &find_pos_p, v12, 0xFFFFFFFF);
        if ( v7 )
          v7->i_uid = SSParser::as_symbol(v8, &result, v6, find_pos_p)->i_uid;
        LODWORD(v10) = find_pos_p;
        v9 = 0;
      }
    }
  }
  v13 = v9;
  if ( v4 )
    *v4 = v10;
  return v13;
}

// File Line: 8930
// RVA: 0x12F100
__int64 __fastcall SSParser::parse_parameter(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSParameterBase **param_new_pp)
{
  SSParameterBase **v4; // r12
  unsigned int *v5; // r13
  unsigned int v6; // ebx
  SSParser *v7; // rsi
  char *v8; // rax
  unsigned int v9; // edi
  SSParser::eResult v10; // er14
  SSUnaryParam *v11; // rax
  SSParameterBase *v12; // rdx
  SSClassDescBase **v13; // rsi
  __int64 *v14; // rbx
  unsigned __int64 v15; // rdi
  __int64 v16; // rdx
  __int64 v17; // r8
  SSParameterBase *v18; // rdi
  __int64 v19; // rdx
  __int64 v20; // r8
  SSUnaryParam *v21; // rax
  SSParameterBase *v22; // rax
  SSParser::eResult v23; // eax
  SSGroupParam gparam_p; // [rsp+28h] [rbp-28h]
  unsigned int end_pos_pa; // [rsp+A0h] [rbp+50h]
  SSUnaryParam *v27; // [rsp+A8h] [rbp+58h]

  v4 = param_new_pp;
  v5 = end_pos_p;
  v6 = start_pos;
  v7 = this;
  v8 = this->i_str_ref_p->i_cstr_p;
  if ( param_new_pp )
  {
    if ( v8[start_pos] == 123 )
    {
      gparam_p.i_name = (ASymbol)ASymbol::get_null()->i_uid;
      gparam_p.vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable';
      v9 = 0;
      gparam_p.i_class_pattern.i_count = 0;
      gparam_p.i_class_pattern.i_array_p = 0i64;
      gparam_p.i_class_pattern.i_size = 0;
      v10 = SSParser::parse_parameter_group(v7, v6, &end_pos_pa, &gparam_p);
      if ( v10 )
      {
        v13 = gparam_p.i_class_pattern.i_array_p;
        v9 = gparam_p.i_class_pattern.i_count;
      }
      else
      {
        v11 = (SSUnaryParam *)AMemory::c_malloc_func(0x28ui64, "SSGroupParam");
        v12 = (SSParameterBase *)&v11->vfptr;
        v27 = v11;
        if ( v11 )
        {
          v11->i_name.i_uid = gparam_p.i_name.i_uid;
          v11->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable';
          v11->vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable';
          LODWORD(v11->i_type_p.i_obj_p) = gparam_p.i_class_pattern.i_count;
          v11->i_default_p = (SSExpressionBase *)gparam_p.i_class_pattern.i_array_p;
          LODWORD(v11[1].vfptr) = gparam_p.i_class_pattern.i_size;
          gparam_p.i_class_pattern.i_count = 0;
          gparam_p.i_class_pattern.i_size = 0;
          v13 = 0i64;
          gparam_p.i_class_pattern.i_array_p = 0i64;
        }
        else
        {
          v12 = 0i64;
          v13 = gparam_p.i_class_pattern.i_array_p;
          v9 = gparam_p.i_class_pattern.i_count;
        }
        *v4 = v12;
      }
      gparam_p.vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable';
      if ( v9 )
      {
        v14 = (__int64 *)v13;
        v15 = (unsigned __int64)&v13[v9];
        if ( (unsigned __int64)v13 < v15 )
        {
          do
          {
             SSClassDescBase::`vcall'{16,{flat}}(*v14);
            ++v14;
          }
          while ( (unsigned __int64)v14 < v15 );
        }
      }
      AMemory::c_free_func(v13);
      gparam_p.vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable';
    }
    else
    {
      gparam_p.i_name = (ASymbol)ASymbol::get_null()->i_uid;
      gparam_p.vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable';
      *(_QWORD *)&gparam_p.i_class_pattern.i_count = SSBrain::c_object_class_p;
      if ( SSBrain::c_object_class_p )
        (*(void (__cdecl **)(SSClass *, __int64, __int64))SSBrain::c_object_class_p->vfptr->gap8)(
          SSBrain::c_object_class_p,
          v16,
          v17);
      v18 = 0i64;
      gparam_p.i_class_pattern.i_array_p = 0i64;
      v10 = SSParser::parse_parameter_unary(v7, v6, &end_pos_pa, (SSUnaryParam *)&gparam_p);
      if ( v10 == Result_ok )
      {
        v21 = (SSUnaryParam *)AMemory::c_malloc_func(0x20ui64, "SSUnaryParam");
        v27 = v21;
        if ( v21 )
        {
          SSUnaryParam::SSUnaryParam(v21, (SSUnaryParam *)&gparam_p);
          v18 = v22;
        }
        *v4 = v18;
      }
      gparam_p.vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable';
      if ( gparam_p.i_class_pattern.i_array_p )
        (**(void (__fastcall ***)(SSClassDescBase **, signed __int64))gparam_p.i_class_pattern.i_array_p)(
          gparam_p.i_class_pattern.i_array_p,
          1i64);
      if ( *(_QWORD *)&gparam_p.i_class_pattern.i_count )
        (*(void (__cdecl **)(_QWORD, __int64, __int64))(**(_QWORD **)&gparam_p.i_class_pattern.i_count + 16i64))(
          *(_QWORD *)&gparam_p.i_class_pattern.i_count,
          v19,
          v20);
      gparam_p.vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable';
    }
  }
  else
  {
    if ( v8[start_pos] == 123 )
      v23 = SSParser::parse_parameter_group(this, start_pos, &end_pos_pa, 0i64);
    else
      v23 = SSParser::parse_parameter_unary(this, start_pos, &end_pos_pa, 0i64);
    v10 = v23;
  }
  if ( v5 )
    *v5 = end_pos_pa;
  return (unsigned int)v10;
}

// File Line: 8997
// RVA: 0x12F520
__int64 __fastcall SSParser::parse_parameter_specifier(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSTypedName *tname_p, unsigned int param_flags)
{
  SSTypedName *v5; // rsi
  unsigned int *v6; // r14
  SSClassDescBase **v7; // r9
  unsigned int v8; // ebp
  SSParser *v9; // rdi
  SSParser::eResult v10; // ebx
  SSClass *v11; // rax
  SSClassDescBase *obj_p; // [rsp+20h] [rbp-38h]
  unsigned int end_pos_pa; // [rsp+70h] [rbp+18h]
  ASymbol name_p; // [rsp+78h] [rbp+20h]

  v5 = tname_p;
  v6 = end_pos_p;
  v7 = &obj_p;
  if ( !v5 )
    v7 = 0i64;
  v8 = start_pos;
  v9 = this;
  obj_p = (SSClassDescBase *)&SSBrain::c_object_class_p->vfptr;
  v10 = (unsigned int)SSParser::parse_class_desc(this, start_pos, &end_pos_pa, v7);
  if ( v10 == Result_ok )
  {
    v10 = SSParser::parse_ws_required(v9, end_pos_pa, &end_pos_pa);
    goto LABEL_5;
  }
  if ( end_pos_pa != v8 )
  {
LABEL_5:
    if ( v10 )
      goto LABEL_17;
    goto LABEL_6;
  }
  v11 = SSBrain::c_object_class_p;
  if ( param_flags & 1 )
    v11 = SSBrain::c_auto_class_p;
  obj_p = (SSClassDescBase *)&v11->vfptr;
LABEL_6:
  name_p.i_uid = -1;
  if ( (unsigned int)SSParser::parse_name_instance(v9, end_pos_pa, &end_pos_pa, &name_p) )
  {
    v10 = 58;
  }
  else if ( v9->i_flags.i_flagset & 1 && SSTypeContext::is_previous_variable(&v9->i_context, &name_p) )
  {
    v10 = 104;
  }
  else
  {
    v10 = 0;
    if ( v5 )
    {
      ARefPtr<SSClassDescBase>::operator=(&v5->i_type_p, obj_p);
      v5->i_name = name_p;
    }
  }
LABEL_17:
  if ( v6 )
    *v6 = end_pos_pa;
  return (unsigned int)v10;
}

// File Line: 9094
// RVA: 0x12F630
__int64 __fastcall SSParser::parse_parameter_unary(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSUnaryParam *uparam_p)
{
  SSUnaryParam *v4; // r13
  unsigned int v5; // er15
  SSParser *v6; // r14
  int v7; // er12
  SSLiteralList *v8; // r12
  SSClassDescBase *v9; // rdi
  SSParser::eResult v10; // ebx
  unsigned int v11; // esi
  unsigned int v12; // er15
  SSParser::eResult v13; // eax
  bool v14; // zf
  unsigned int v15; // eax
  SSClassDescBase *v16; // rcx
  SSExpressionBase *v17; // rcx
  ASymbol name_p; // [rsp+20h] [rbp-40h]
  unsigned int v20; // [rsp+24h] [rbp-3Ch]
  SSClassDescBase *type_pp; // [rsp+28h] [rbp-38h]
  __int64 v22; // [rsp+30h] [rbp-30h]
  ASymbol v23; // [rsp+38h] [rbp-28h]
  ARefPtr<SSClassDescBase> v24; // [rsp+40h] [rbp-20h]
  SSParser::Args args; // [rsp+48h] [rbp-18h]
  unsigned int end_pos_pa; // [rsp+A8h] [rbp+48h]
  unsigned int *v27; // [rsp+B0h] [rbp+50h]

  v27 = end_pos_p;
  v22 = -2i64;
  v4 = uparam_p;
  v5 = start_pos;
  v6 = this;
  v7 = ASymbol::get_null()->i_uid;
  v20 = v7;
  v23.i_uid = v7;
  v8 = 0i64;
  v9 = 0i64;
  v24.i_obj_p = 0i64;
  type_pp = (SSClassDescBase *)&SSBrain::c_object_class_p->vfptr;
  v10 = (unsigned int)SSParser::parse_class_desc(v6, v5, &end_pos_pa, &type_pp);
  if ( v10 )
  {
    v11 = end_pos_pa;
    if ( end_pos_pa == v5 )
    {
      type_pp = (SSClassDescBase *)&SSBrain::c_object_class_p->vfptr;
      goto LABEL_6;
    }
  }
  else
  {
    v10 = SSParser::parse_ws_required(v6, end_pos_pa, &end_pos_pa);
    v11 = end_pos_pa;
  }
  if ( v10 )
    goto LABEL_40;
LABEL_6:
  name_p.i_uid = -1;
  if ( (unsigned int)SSParser::parse_name_instance(v6, v11, &end_pos_pa, &name_p) )
  {
    v10 = 58;
  }
  else if ( v6->i_flags.i_flagset & 1 && SSTypeContext::is_previous_variable(&v6->i_context, &name_p) )
  {
    v10 = 104;
  }
  else
  {
    v10 = 0;
    ARefPtr<SSClassDescBase>::operator=(&v24, type_pp);
    v20 = name_p.i_uid;
    v23.i_uid = name_p.i_uid;
    v9 = v24.i_obj_p;
  }
  v11 = end_pos_pa;
  if ( v10 )
    goto LABEL_40;
  SSParser::parse_ws_any(v6, end_pos_pa, &end_pos_pa);
  v12 = end_pos_pa;
  args.i_start_pos = end_pos_pa;
  args.i_flags = v4 != 0i64;
  *(_QWORD *)&args.i_result = 0i64;
  args.i_type_p = 0i64;
  if ( v6->i_str_ref_p->i_length <= end_pos_pa || v6->i_str_ref_p->i_cstr_p[end_pos_pa] != 58 )
  {
    args.i_result = 10;
    args.i_end_pos = end_pos_pa;
LABEL_27:
    v10 = 0;
    goto LABEL_28;
  }
  v13 = SSParser::parse_ws_any(v6, end_pos_pa + 1, &end_pos_pa);
  v10 = v13;
  args.i_result = v13;
  v14 = v13 == 0;
  v15 = end_pos_pa;
  if ( v14 )
  {
    args.i_start_pos = end_pos_pa;
    v8 = SSParser::parse_expression(v6, &args, 3i64);
    v15 = args.i_end_pos;
    v10 = args.i_result;
  }
  else
  {
    args.i_end_pos = end_pos_pa;
  }
  if ( v15 == v12 )
    goto LABEL_27;
  v11 = v15;
  if ( v6->i_flags.i_flagset & 1 )
  {
    if ( v10 )
      goto LABEL_40;
    if ( !args.i_type_p->vfptr->is_class_type(args.i_type_p, v9) )
    {
      v10 = 131;
      if ( v8 )
        v8->vfptr->__vecDelDtor((SSExpressionBase *)&v8->vfptr, 1u);
      goto LABEL_40;
    }
  }
  else if ( v10 )
  {
    goto LABEL_40;
  }
LABEL_28:
  if ( v4 )
  {
    v4->i_name.i_uid = v20;
    if ( v4->i_type_p.i_obj_p != v9 )
    {
      if ( v9 )
        (*(void (__fastcall **)(SSClassDescBase *))v9->vfptr->gap8)(v9);
      v16 = v4->i_type_p.i_obj_p;
      if ( v16 )
        (*(void (**)(void))&v16->vfptr->gap8[8])();
      v4->i_type_p.i_obj_p = v9;
    }
    v17 = v4->i_default_p;
    if ( v17 )
      v17->vfptr->__vecDelDtor(v17, 1u);
    v4->i_default_p = (SSExpressionBase *)&v8->vfptr;
  }
  if ( v6->i_flags.i_flagset & 1 )
    SSTypeContext::append_local(&v6->i_context, &v23, v9);
LABEL_40:
  if ( v27 )
    *v27 = v11;
  if ( v9 )
    (*(void (__fastcall **)(SSClassDescBase *))&v9->vfptr->gap8[8])(v9);
  return (unsigned int)v10;
}

// File Line: 9178
// RVA: 0x12F340
__int64 __fastcall SSParser::parse_parameter_group(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSGroupParam *gparam_p)
{
  char *v4; // r12
  unsigned int v5; // er15
  SSGroupParam *v6; // r14
  unsigned int *v7; // r13
  SSParser *v8; // rsi
  unsigned int v9; // ebx
  SSClassUnaryBase *v10; // rdi
  int v11; // ebp
  __int64 v12; // r8
  SSClassDescBase *v13; // rbx
  SSClass *v14; // rdx
  SSTypedClass *v15; // rax
  __int64 result; // rax
  SSClassDescBase *type_pp; // [rsp+60h] [rbp+8h]
  unsigned int end_pos_pa; // [rsp+68h] [rbp+10h]

  v4 = this->i_str_ref_p->i_cstr_p;
  v5 = this->i_str_ref_p->i_length;
  v6 = gparam_p;
  v7 = end_pos_p;
  v8 = this;
  v9 = 82;
  if ( this->i_str_ref_p->i_length - start_pos >= 2 )
  {
    v9 = 31;
    if ( v4[start_pos] == 123 )
    {
      ++start_pos;
      v10 = 0i64;
      v11 = 0;
      end_pos_pa = start_pos;
      if ( start_pos < v5 )
      {
        while ( 1 )
        {
          SSParser::parse_ws_any(v8, start_pos, &end_pos_pa);
          if ( v4[end_pos_pa] == 125 )
            break;
          if ( (unsigned int)SSParser::parse_class_desc(v8, end_pos_pa, &end_pos_pa, &type_pp) )
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
          v13 = type_pp;
          if ( v8->i_flags.i_flagset & 1 )
          {
            if ( v10 )
              v10 = SSClassUnion::get_merge((SSClassDescBase *)&v10->vfptr, type_pp, v12);
            else
              v10 = (SSClassUnaryBase *)type_pp;
          }
          if ( v6 )
          {
            (*(void (__fastcall **)(SSClassDescBase *))v13->vfptr->gap8)(v13);
            APArray<SSClassDescBase,SSClassDescBase,ACompareAddress<SSClassDescBase>>::append(&v6->i_class_pattern, v13);
          }
          start_pos = end_pos_pa;
          if ( end_pos_pa >= v5 )
            goto LABEL_18;
        }
        start_pos = end_pos_pa++ + 1;
LABEL_18:
        SSParser::parse_ws_any(v8, start_pos, &end_pos_pa);
        LODWORD(type_pp) = -1;
        if ( (unsigned int)SSParser::parse_name_instance(v8, end_pos_pa, &end_pos_pa, (ASymbol *)&type_pp) )
        {
          v9 = 58;
          goto LABEL_29;
        }
        if ( v8->i_flags.i_flagset & 1 && SSTypeContext::is_previous_variable(&v8->i_context, (ASymbol *)&type_pp) )
        {
          v9 = 104;
          goto LABEL_29;
        }
        v9 = 0;
        if ( v8->i_flags.i_flagset & 1 )
        {
          v14 = SSBrain::c_object_class_p;
          if ( v10 )
            v14 = (SSClass *)v10;
          v15 = SSTypedClass::get_or_create(SSBrain::c_list_class_p, (SSClassDescBase *)&v14->vfptr);
          SSTypeContext::append_local(&v8->i_context, (ASymbol *)&type_pp, (SSClassDescBase *)&v15->vfptr);
        }
        start_pos = end_pos_pa;
        if ( v6 )
          v6->i_name.i_uid = (unsigned int)type_pp;
      }
    }
  }
LABEL_30:
  result = v9;
  if ( v7 )
    *v7 = start_pos;
  return result;
}

// File Line: 9359
// RVA: 0x12F8C0
signed __int64 __fastcall SSParser::parse_parameters(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSParameters *params_p, unsigned int flags)
{
  SSClassDescBase **v5; // rax
  SSParser *v6; // r14
  SSParameters *v7; // r12
  unsigned int v8; // ecx
  unsigned int *v9; // r15
  unsigned int v11; // ebx
  char v12; // bp
  char v13; // si
  SSParser::eResult (__fastcall *v14)(SSParser *, unsigned int, unsigned int *, SSParameters *); // r13
  SSParser::eResult v15; // edi
  int v16; // eax
  char v17; // bp
  unsigned int v18; // esi
  SSClass *v19; // rdx
  _QWORD v20[2]; // [rsp+20h] [rbp-58h]
  unsigned int start_posa; // [rsp+30h] [rbp-48h]
  unsigned int v22; // [rsp+34h] [rbp-44h]
  SSClassDescBase *type_pp; // [rsp+38h] [rbp-40h]
  unsigned int v24; // [rsp+80h] [rbp+8h]
  unsigned int end_pos_pa; // [rsp+88h] [rbp+10h]

  end_pos_pa = start_pos;
  v5 = (SSClassDescBase **)this->i_str_ref_p;
  v6 = this;
  v7 = params_p;
  v8 = this->i_str_ref_p->i_length;
  v9 = end_pos_p;
  v22 = v8;
  if ( v8 < start_pos )
  {
    if ( end_pos_p )
      *end_pos_p = start_pos;
    return 82i64;
  }
  type_pp = *v5;
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
  if ( (v6->i_flags.i_flagset >> 2) & 1 )
    v14 = (SSParser::eResult (__fastcall *)(SSParser *, unsigned int, unsigned int *, SSParameters *))SSParser::preparse_param_append;
  end_pos_pa = start_pos + 1;
  LOBYTE(v24) = 1;
  v15 = 82;
  start_posa = 0;
  if ( v11 < v8 )
  {
    while ( 1 )
    {
      v15 = SSParser::parse_ws_any(v6, v11, &end_pos_pa);
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
        if ( !(_BYTE)v24 )
          goto LABEL_33;
        v11 = end_pos_pa + 1;
        v14 = (SSParser::eResult (__fastcall *)(SSParser *, unsigned int, unsigned int *, SSParameters *))SSParser::parse_param_return_append;
        LOBYTE(v24) = 0;
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
        LODWORD(v20[0]) = start_posa;
        v15 = ((unsigned int (__fastcall *)(SSParser *, _QWORD, unsigned int *, SSParameters *, _QWORD))v14)(
                v6,
                end_pos_pa,
                &end_pos_pa,
                v7,
                v20[0]);
        if ( v15 )
          goto LABEL_41;
        v11 = end_pos_pa;
        v13 = 0;
        v12 = 1;
        v15 = 82;
      }
      if ( v11 >= v22 )
      {
        if ( v15 )
          goto LABEL_42;
        goto LABEL_30;
      }
    }
    if ( v13 )
    {
LABEL_28:
      v15 = 87;
      goto LABEL_42;
    }
    v11 = end_pos_pa++ + 1;
LABEL_30:
    SSParser::parse_ws_any(v6, v11, &start_posa);
    v17 = flags;
    if ( flags & 2 )
    {
      v11 = start_posa;
      SSParser::parse_class_desc(v6, start_posa, &v24, 0i64);
      if ( v11 != v24 )
      {
LABEL_33:
        v15 = 88;
        goto LABEL_42;
      }
      SSParameters::set_result_type(v7, (SSClassDescBase *)&SSBrain::c_none_class_p->vfptr);
      v15 = 0;
      goto LABEL_41;
    }
    v18 = start_posa;
    v15 = (unsigned int)SSParser::parse_class_desc(v6, start_posa, &v24, &type_pp);
    if ( v15 == Result_ok )
    {
      SSParameters::set_result_type(v7, type_pp);
      v11 = v24;
      goto LABEL_42;
    }
    v11 = v24;
    if ( v18 == v24 )
    {
      v15 = 0;
      if ( v7 )
      {
        v19 = SSBrain::c_object_class_p;
        if ( v17 & 1 )
          v19 = SSBrain::c_auto_class_p;
        SSParameters::set_result_type(v7, (SSClassDescBase *)&v19->vfptr);
      }
LABEL_41:
      v11 = end_pos_pa;
      goto LABEL_42;
    }
  }
LABEL_42:
  if ( v9 )
    *v9 = v11;
  return (unsigned int)v15;
}

// File Line: 9861
// RVA: 0x12FDD0
bool __fastcall SSParser::parse_temporary(SSParser *this, SSParser::Args *args, ASymbol *ident_p, SSExpressionBase **expr_pp)
{
  __int64 v4; // rbp
  SSExpressionBase **v5; // r13
  ASymbol *v6; // r12
  SSParser::Args *v7; // rdi
  SSParser *v8; // r14
  char *v9; // rbx
  __int64 v10; // rsi
  char v11; // cl
  SSParser::eResult v12; // eax
  SSParser::eResult v13; // eax
  unsigned int v14; // ebx
  SSExpressionBase *v15; // rax
  bool v16; // zf
  unsigned int end_pos_p; // [rsp+50h] [rbp+8h]

  v4 = args->i_start_pos;
  args->i_result = 82;
  v5 = expr_pp;
  v6 = ident_p;
  v7 = args;
  v8 = this;
  if ( (unsigned int)(this->i_str_ref_p->i_length - v4) >= 2 )
  {
    v9 = this->i_str_ref_p->i_cstr_p;
    args->i_result = 66;
    if ( v9[v4] == 33 )
    {
      v10 = (unsigned int)(v4 + 1);
      args->i_result = 72;
      v11 = v9[v10];
      end_pos_p = v4 + 1;
      if ( v11 != 40 && v11 != 33 )
      {
        v12 = SSParser::parse_ws_any(v8, v10, &end_pos_p);
        v7->i_result = v12;
        if ( v12
          || (v13 = (unsigned int)SSParser::parse_name_instance(v8, end_pos_p, &end_pos_p, v6), (v7->i_result = v13) != 0) )
        {
          LODWORD(v10) = end_pos_p;
        }
        else
        {
          v10 = end_pos_p;
          v7->i_result = 72;
          if ( v9[v10] != 40 )
          {
            if ( v8->i_flags.i_flagset & 1 && v6 && SSTypeContext::is_previous_variable(&v8->i_context, v6) )
            {
              v7->i_result = 104;
            }
            else if ( SSParser::parse_ws_any(v8, v10, &end_pos_p)
                   || (v14 = end_pos_p,
                       v7->i_start_pos = end_pos_p,
                       v15 = SSParser::parse_binding(v8, v7),
                       v7->i_end_pos == v14) )
            {
              v7->i_result = 0;
              v7->i_type_p = (SSClassDescBase *)&SSBrain::c_none_class_p->vfptr;
            }
            else
            {
              LODWORD(v10) = v7->i_end_pos;
              if ( v5 )
                *v5 = v15;
            }
          }
        }
      }
      if ( v7->i_result == 72 )
        LODWORD(v10) = v4;
      LODWORD(v4) = v10;
    }
  }
  v16 = v7->i_result == 0;
  v7->i_end_pos = v4;
  return v16;
}

// File Line: 10028
// RVA: 0x130090
__int64 __fastcall SSParser::parse_ws_any(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p)
{
  unsigned int *v3; // r15
  unsigned int v4; // esi
  unsigned int v5; // ebx
  SSParser *v6; // r14
  unsigned int v7; // edi
  unsigned int v8; // edx
  char *v9; // r8
  char *v10; // rax
  unsigned __int64 i; // rdx
  __int64 v12; // rdx
  __int64 result; // rax
  unsigned int find_pos_p; // [rsp+58h] [rbp+10h]

  v3 = end_pos_p;
  v4 = this->i_str_ref_p->i_length;
  v5 = start_pos;
  v6 = this;
  v7 = 0;
  if ( start_pos < v4 )
  {
    while ( v5 < v4 )
    {
      find_pos_p = v4;
      AString::find((AString *)&v6->i_str_ref_p, ACharMatch_not_white_space, 1u, &find_pos_p, v5, 0xFFFFFFFF);
      v5 = find_pos_p;
      if ( find_pos_p >= v4 )
        break;
      v8 = v6->i_str_ref_p->i_length;
      v9 = v6->i_str_ref_p->i_cstr_p;
      v10 = &v9[find_pos_p];
      if ( find_pos_p + 2 > v8 || *v10 != 47 || (++v10, *v10 != 47) )
      {
        v12 = find_pos_p;
        find_pos_p = (_DWORD)v10 - (_DWORD)v9;
        v7 = SSParser::parse_comment_multiline(v6, v12, &find_pos_p);
        if ( v7 )
          break;
        v5 = find_pos_p;
      }
      else
      {
        for ( i = (unsigned __int64)&v9[v8 - 1]; (unsigned __int64)v10 <= i; ++v10 )
        {
          if ( *v10 == 10 )
            break;
        }
        v7 = 0;
        v5 = (_DWORD)v10 - (_DWORD)v9 + 1;
      }
    }
    if ( v7 != 26 )
      v7 = 0;
  }
  result = v7;
  if ( v3 )
    *v3 = v5;
  return result;
}

// File Line: 10119
// RVA: 0x130190
signed __int64 __fastcall SSParser::parse_ws_required(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p)
{
  unsigned int v3; // ebp
  unsigned int *v4; // rsi
  SSParser *v5; // rdi
  unsigned int v6; // ebx
  AStringRef *v7; // rax
  unsigned int v8; // edx
  char *v9; // r8
  char *v10; // rcx
  unsigned __int64 i; // rdx
  signed __int64 result; // rax
  AStringRef *v13; // rax
  unsigned int v14; // ST20_4
  AStringRef *v15; // rax
  unsigned int v16; // edx
  char *v17; // r8
  char *v18; // rax
  unsigned __int64 j; // rdx
  __int64 v20; // rdx
  unsigned int end_pos_pa; // [rsp+50h] [rbp+8h]
  unsigned int find_pos_p; // [rsp+60h] [rbp+18h]

  v3 = start_pos;
  v4 = end_pos_p;
  find_pos_p = this->i_str_ref_p->i_length;
  v5 = this;
  AString::find((AString *)&this->i_str_ref_p, ACharMatch_not_white_space, 1u, &find_pos_p, start_pos, 0xFFFFFFFF);
  v6 = find_pos_p;
  v7 = v5->i_str_ref_p;
  end_pos_pa = find_pos_p;
  v8 = v7->i_length;
  v9 = v7->i_cstr_p;
  v10 = &v7->i_cstr_p[find_pos_p];
  if ( find_pos_p + 2 <= v8 && *v10 == 47 && *++v10 == 47 )
  {
    for ( i = (unsigned __int64)&v9[v8 - 1]; (unsigned __int64)v10 <= i; ++v10 )
    {
      if ( *v10 == 10 )
        break;
    }
    end_pos_pa = (_DWORD)v10 - (_DWORD)v9 + 1;
    goto LABEL_9;
  }
  end_pos_pa = (_DWORD)v10 - (_DWORD)v9;
  result = SSParser::parse_comment_multiline(v5, find_pos_p, &end_pos_pa);
  if ( !(_DWORD)result )
  {
    do
    {
LABEL_9:
      while ( 1 )
      {
        v13 = v5->i_str_ref_p;
        find_pos_p = end_pos_pa;
        v14 = end_pos_pa;
        end_pos_pa = v13->i_length;
        AString::find((AString *)&v5->i_str_ref_p, ACharMatch_not_white_space, 1u, &end_pos_pa, v14, 0xFFFFFFFF);
        v6 = end_pos_pa;
        v15 = v5->i_str_ref_p;
        find_pos_p = end_pos_pa;
        v16 = v15->i_length;
        v17 = v15->i_cstr_p;
        v18 = &v15->i_cstr_p[end_pos_pa];
        if ( end_pos_pa + 2 > v16 )
          break;
        if ( *v18 != 47 )
          break;
        if ( *++v18 != 47 )
          break;
        for ( j = (unsigned __int64)&v17[v16 - 1]; (unsigned __int64)v18 <= j; ++v18 )
        {
          if ( *v18 == 10 )
            break;
        }
        end_pos_pa = (_DWORD)v18 - (_DWORD)v17 + 1;
      }
      v20 = end_pos_pa;
      end_pos_pa = (_DWORD)v18 - (_DWORD)v17;
    }
    while ( !(unsigned int)SSParser::parse_comment_multiline(v5, v20, &end_pos_pa) );
    goto LABEL_17;
  }
  if ( (_DWORD)result == 26 )
  {
    v6 = end_pos_pa;
    goto LABEL_19;
  }
LABEL_17:
  result = 68i64;
  if ( v6 != v3 )
    result = 0i64;
LABEL_19:
  if ( v4 )
    *v4 = v6;
  return result;
}

// File Line: 10299
// RVA: 0x131480
__int64 __fastcall SSParser::preparse_parameter_unary(SSParser *this, SSUnaryParam *uparam_p, unsigned int start_pos, unsigned int *end_pos_p)
{
  unsigned int v4; // er13
  SSUnaryParam *v5; // r12
  SSParser *v6; // r15
  SSExpressionBase *v7; // r14
  SSClassDescBase *v8; // rdi
  unsigned int v9; // ebx
  unsigned int v10; // esi
  unsigned int v11; // er13
  SSParser::eResult v12; // eax
  bool v13; // zf
  unsigned int v14; // eax
  SSClassDescBase *v15; // rax
  SSClassDescBase *v16; // rcx
  SSExpressionBase *v17; // rcx
  ASymbol name_p; // [rsp+20h] [rbp-40h]
  unsigned int v20; // [rsp+24h] [rbp-3Ch]
  SSClassDescBase *type_pp; // [rsp+28h] [rbp-38h]
  __int64 v22; // [rsp+30h] [rbp-30h]
  unsigned int v23; // [rsp+38h] [rbp-28h]
  ARefPtr<SSClassDescBase> v24; // [rsp+40h] [rbp-20h]
  SSParser::Args args; // [rsp+48h] [rbp-18h]
  unsigned int end_pos_pa; // [rsp+B0h] [rbp+50h]
  unsigned int *v27; // [rsp+B8h] [rbp+58h]

  v27 = end_pos_p;
  v22 = -2i64;
  v4 = start_pos;
  v5 = uparam_p;
  v6 = this;
  v20 = ASymbol::get_null()->i_uid;
  v23 = v20;
  v7 = 0i64;
  v8 = 0i64;
  v24.i_obj_p = 0i64;
  type_pp = (SSClassDescBase *)&SSBrain::c_object_class_p->vfptr;
  v9 = SSParser::parse_class_desc(v6, v4, &end_pos_pa, &type_pp);
  if ( v9 )
  {
    v10 = end_pos_pa;
    if ( end_pos_pa == v4 )
    {
      type_pp = (SSClassDescBase *)&SSBrain::c_object_class_p->vfptr;
      goto LABEL_6;
    }
  }
  else
  {
    v9 = SSParser::parse_ws_required(v6, end_pos_pa, &end_pos_pa);
    v10 = end_pos_pa;
  }
  if ( v9 )
    goto LABEL_34;
LABEL_6:
  name_p.i_uid = -1;
  if ( (unsigned int)SSParser::parse_name_instance(v6, v10, &end_pos_pa, &name_p) )
  {
    v9 = 58;
  }
  else if ( v6->i_flags.i_flagset & 1 && SSTypeContext::is_previous_variable(&v6->i_context, &name_p) )
  {
    v9 = 104;
  }
  else
  {
    v9 = 0;
    ARefPtr<SSClassDescBase>::operator=(&v24, type_pp);
    v20 = name_p.i_uid;
    v23 = name_p.i_uid;
    v8 = v24.i_obj_p;
  }
  v10 = end_pos_pa;
  if ( v9 )
    goto LABEL_34;
  SSParser::parse_ws_any(v6, end_pos_pa, &end_pos_pa);
  v11 = end_pos_pa;
  args.i_start_pos = end_pos_pa;
  *(_QWORD *)&args.i_flags = 0i64;
  args.i_end_pos = 0;
  args.i_type_p = 0i64;
  if ( v6->i_str_ref_p->i_length <= end_pos_pa || v6->i_str_ref_p->i_cstr_p[end_pos_pa] != 58 )
  {
    args.i_result = 10;
    args.i_end_pos = end_pos_pa;
  }
  else
  {
    v12 = (unsigned int)SSParser::parse_ws_any(v6, end_pos_pa + 1, &end_pos_pa);
    v9 = v12;
    args.i_result = v12;
    v13 = v12 == 0;
    v14 = end_pos_pa;
    if ( v13 )
    {
      args.i_start_pos = end_pos_pa;
      SSParser::parse_expression(v6, &args, 3i64);
      v14 = args.i_end_pos;
      v9 = args.i_result;
    }
    else
    {
      args.i_end_pos = end_pos_pa;
    }
    if ( v14 != v11 )
    {
      v10 = v14;
      if ( !v9 )
      {
        v15 = (SSClassDescBase *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
        type_pp = v15;
        if ( v15 )
        {
          v15->vfptr = (SSClassDescBaseVtbl *)&SSExpressionBase::`vftable';
          v15->vfptr = (SSClassDescBaseVtbl *)&SSLiteral::`vftable';
          v15[1].vfptr = 0i64;
          LODWORD(v15[2].vfptr) = 7;
          v7 = (SSExpressionBase *)v15;
        }
      }
      goto LABEL_25;
    }
  }
  v9 = 0;
LABEL_25:
  v5->i_name.i_uid = v20;
  if ( v5->i_type_p.i_obj_p != v8 )
  {
    if ( v8 )
      (*(void (__fastcall **)(SSClassDescBase *))v8->vfptr->gap8)(v8);
    v16 = v5->i_type_p.i_obj_p;
    if ( v16 )
      (*(void (**)(void))&v16->vfptr->gap8[8])();
    v5->i_type_p.i_obj_p = v8;
  }
  v17 = v5->i_default_p;
  if ( v17 )
    v17->vfptr->__vecDelDtor(v17, 1u);
  v5->i_default_p = v7;
LABEL_34:
  if ( v27 )
    *v27 = v10;
  if ( v8 )
    (*(void (__fastcall **)(SSClassDescBase *))&v8->vfptr->gap8[8])(v8);
  return v9;
}

// File Line: 10371
// RVA: 0x131280
__int64 __fastcall SSParser::preparse_parameter(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSParameterBase **param_new_pp)
{
  SSParameterBase **v4; // r15
  unsigned int *v5; // r12
  unsigned int v6; // ebx
  SSParser *v7; // rsi
  __int64 v8; // rdx
  __int64 v9; // r8
  unsigned int v10; // edi
  __int64 v11; // rdx
  __int64 v12; // r8
  SSParser::eResult v13; // er14
  SSUnaryParam *v14; // rax
  SSParameterBase *v15; // rax
  unsigned int v16; // eax
  SSUnaryParam *v17; // rax
  SSParameterBase *v18; // rdx
  SSClassDescBase **v19; // rsi
  __int64 *v20; // rbx
  unsigned __int64 v21; // rdi
  SSUnaryParam uparam_p; // [rsp+28h] [rbp-48h]
  SSGroupParam gparam_p; // [rsp+48h] [rbp-28h]
  unsigned int end_pos_pa; // [rsp+B8h] [rbp+48h]
  SSUnaryParam *v26; // [rsp+C0h] [rbp+50h]

  v4 = param_new_pp;
  v5 = end_pos_p;
  v6 = start_pos;
  v7 = this;
  uparam_p.i_name = (ASymbol)ASymbol::get_null()->i_uid;
  uparam_p.vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable';
  uparam_p.i_type_p.i_obj_p = (SSClassDescBase *)&SSBrain::c_object_class_p->vfptr;
  if ( SSBrain::c_object_class_p )
    (*(void (__cdecl **)(SSClass *, __int64, __int64))SSBrain::c_object_class_p->vfptr->gap8)(
      SSBrain::c_object_class_p,
      v8,
      v9);
  v10 = 0;
  uparam_p.i_default_p = 0i64;
  v13 = SSParser::preparse_parameter_unary(v7, &uparam_p, v6, &end_pos_pa);
  if ( v13 == Result_ok )
  {
    v14 = (SSUnaryParam *)AMemory::c_malloc_func(0x20ui64, "SSUnaryParam");
    v26 = v14;
    if ( v14 )
      SSUnaryParam::SSUnaryParam(v14, &uparam_p);
    else
      v15 = 0i64;
    *v4 = v15;
  }
  v16 = end_pos_pa;
  if ( end_pos_pa == v6 )
  {
    gparam_p.i_name = (ASymbol)ASymbol::get_null()->i_uid;
    gparam_p.vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable';
    gparam_p.i_class_pattern.i_count = 0;
    gparam_p.i_class_pattern.i_array_p = 0i64;
    gparam_p.i_class_pattern.i_size = 0;
    v13 = (unsigned int)SSParser::parse_parameter_group(v7, v6, &end_pos_pa, &gparam_p);
    if ( v13 )
    {
      v19 = gparam_p.i_class_pattern.i_array_p;
      v10 = gparam_p.i_class_pattern.i_count;
    }
    else
    {
      v17 = (SSUnaryParam *)AMemory::c_malloc_func(0x28ui64, "SSGroupParam");
      v18 = (SSParameterBase *)&v17->vfptr;
      v26 = v17;
      if ( v17 )
      {
        v17->i_name.i_uid = gparam_p.i_name.i_uid;
        v17->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable';
        v17->vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable';
        LODWORD(v17->i_type_p.i_obj_p) = gparam_p.i_class_pattern.i_count;
        v17->i_default_p = (SSExpressionBase *)gparam_p.i_class_pattern.i_array_p;
        LODWORD(v17[1].vfptr) = gparam_p.i_class_pattern.i_size;
        gparam_p.i_class_pattern.i_count = 0;
        gparam_p.i_class_pattern.i_size = 0;
        v19 = 0i64;
        gparam_p.i_class_pattern.i_array_p = 0i64;
      }
      else
      {
        v18 = 0i64;
        v19 = gparam_p.i_class_pattern.i_array_p;
        v10 = gparam_p.i_class_pattern.i_count;
      }
      *v4 = v18;
    }
    gparam_p.vfptr = (SSParameterBaseVtbl *)&SSGroupParam::`vftable';
    if ( v10 )
    {
      v20 = (__int64 *)v19;
      v21 = (unsigned __int64)&v19[v10];
      if ( (unsigned __int64)v19 < v21 )
      {
        do
        {
           SSClassDescBase::`vcall'{16,{flat}}(*v20);
          ++v20;
        }
        while ( (unsigned __int64)v20 < v21 );
      }
    }
    AMemory::c_free_func(v19);
    gparam_p.vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable';
    v16 = end_pos_pa;
  }
  if ( v5 )
    *v5 = v16;
  uparam_p.vfptr = (SSParameterBaseVtbl *)&SSUnaryParam::`vftable';
  if ( uparam_p.i_default_p )
    uparam_p.i_default_p->vfptr->__vecDelDtor(uparam_p.i_default_p, 1u);
  if ( uparam_p.i_type_p.i_obj_p )
    (*(void (__cdecl **)(SSClassDescBase *, __int64, __int64))&uparam_p.i_type_p.i_obj_p->vfptr->gap8[8])(
      uparam_p.i_type_p.i_obj_p,
      v11,
      v12);
  return (unsigned int)v13;
}e_p.i_obj_p->vfptr->gap8[8])(
      uparam_p.i_type_p.i_obj_p,
      v11,
      

// File Line: 10438
// RVA: 0x1311F0
SSParser::eResult __fastcall SSParser::preparse_param_append(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSParameters *params_p)
{
  SSParameters *v4; // rsi
  unsigned int v5; // ebx
  SSParameterBase **v6; // r9
  SSParser::eResult result; // eax
  SSParser::eResult v8; // edi
  unsigned int v9; // edx
  SSParameterBase **v10; // rcx
  unsigned __int64 i; // r8
  SSParameterBase *elem; // [rsp+48h] [rbp+20h]

  v4 = params_p;
  v5 = 0;
  v6 = &elem;
  elem = 0i64;
  if ( !v4 )
    v6 = 0i64;
  result = SSParser::preparse_parameter(this, start_pos, end_pos_p, v6);
  v8 = result;
  if ( elem )
  {
    v9 = v4->i_params.i_count;
    if ( v9 )
    {
      v10 = v4->i_params.i_array_p;
      for ( i = (unsigned __int64)&v10[v9 - 1]; (unsigned __int64)v10 <= i; ++v10 )
      {
        if ( elem->i_name.i_uid == (*v10)->i_name.i_uid )
        {
          if ( v5 < 2 )
            goto LABEL_11;
          --v5;
        }
      }
    }
    APCompactArray<SSParameterBase,ASymbol,ACompareLogical<ASymbol>>::append(
      (APCompactArray<SSParameterBase,ASymbol,ACompareLogical<ASymbol> > *)&v4->i_params.i_count,
      elem);
LABEL_11:
    result = v8;
  }
  return result;
}

// File Line: 11080
// RVA: 0x114160
char __fastcall SSParser::ensure_exec_time(SSParser *this, SSExpressionBase *expr, SSParser::Args *args, eSSInvokeTime desired_exec_time)
{
  SSParser::Args *v4; // rbx
  eSSInvokeTime v5; // edi
  SSParser *v6; // rsi
  int v8; // eax
  int v9; // [rsp+48h] [rbp+20h]

  v4 = args;
  v5 = desired_exec_time;
  v6 = this;
  if ( desired_exec_time != 3 )
  {
    if ( expr->vfptr->is_immediate(expr, (unsigned int *)&v9) )
    {
      if ( v5 == 2 )
      {
        v4->i_result = 120;
        return 0;
      }
    }
    else if ( v5 == 1 && v6->i_str_ref_p->i_cstr_p[v4->i_end_pos] != 37 )
    {
      v8 = v9;
      v4->i_result = 119;
      v4->i_start_pos = v8;
      v4->i_end_pos = v8 + 4;
      return 0;
    }
  }
  return 1;
}

// File Line: 11140
// RVA: 0x119120
AString *__fastcall SSParser::get_result_context_string(AString *result, AString *code, SSParser::eResult a3, unsigned int result_pos, unsigned int result_start, unsigned int start_pos)
{
  unsigned int end_pos; // edi
  SSParser::eResult v7; // ebp
  AString *v8; // r15
  AString *v9; // rbx
  unsigned int v10; // esi
  unsigned int v11; // ecx
  unsigned int v12; // er12
  const char *v13; // rdx
  AString *v14; // rax
  AStringRef *v15; // r14
  bool v16; // zf
  AObjReusePool<AStringRef> *v17; // rax
  AObjBlock<AStringRef> *v18; // rcx
  unsigned __int64 v19; // rdx
  bool v20; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v21; // rcx
  __int64 v22; // r14
  __int64 v23; // rbp
  bool v24; // bp
  unsigned int v25; // er13
  unsigned int v26; // ecx
  __int64 v27; // rbp
  unsigned int v28; // edi
  unsigned int v29; // eax
  unsigned int v30; // er14
  AString v31; // rax
  __int64 v32; // rbp
  __int64 v33; // rbp
  unsigned int v34; // er12
  __int64 v35; // rbp
  __int64 v36; // rdi
  unsigned int v37; // edx
  __int64 v38; // r8
  __int64 v39; // rsi
  __int64 v40; // rdi
  __int64 v42; // [rsp+20h] [rbp-78h]
  AString resulta; // [rsp+38h] [rbp-60h]
  __int64 v44; // [rsp+40h] [rbp-58h]
  unsigned int v45; // [rsp+A8h] [rbp+10h]
  unsigned int last_counted_p; // [rsp+B0h] [rbp+18h]
  unsigned int find_pos_p; // [rsp+B8h] [rbp+20h]

  v44 = -2i64;
  end_pos = result_pos;
  v7 = a3;
  v8 = code;
  v9 = result;
  v10 = 0;
  v11 = code->i_str_ref_p->i_length;
  find_pos_p = v11;
  if ( result_pos >= v11 )
    end_pos = v11 - 1;
  v12 = result_start;
  if ( result_start > end_pos )
    v12 = end_pos;
  if ( AString::find_reverse(code, 10, 4u, &start_pos, start_pos, end_pos) && start_pos )
    ++start_pos;
  AString::find(v8, 10, 4u, &find_pos_p, end_pos, 0xFFFFFFFF);
  AString::AString(v9, 0i64, 0x400u, 0, 0);
  if ( v7 )
  {
    v13 = "ERROR: ";
    if ( (signed int)v7 < 8 )
      v13 = "WARNING: ";
  }
  else
  {
    v13 = "INFO: ";
  }
  AString::append(v9, v13, 0xFFFFFFFF);
  v14 = SSParser::get_result_string(&resulta, v7);
  AString::append(v9, v14);
  v15 = resulta.i_str_ref_p;
  v16 = resulta.i_str_ref_p->i_ref_count == 1;
  --v15->i_ref_count;
  if ( v16 )
  {
    if ( v15->i_deallocate )
      AMemory::c_free_func(v15->i_cstr_p);
    v17 = AStringRef::get_pool();
    v18 = v17->i_block_p;
    v19 = (unsigned __int64)v18->i_objects_a;
    if ( (unsigned __int64)v15 < v19
      || (v20 = (unsigned __int64)v15 < v19 + 24i64 * v18->i_size, v21 = &v17->i_pool, !v20) )
    {
      v21 = &v17->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v21, v15);
  }
  AString::append(v9, "\n", 0xFFFFFFFF);
  v22 = v9->i_str_ref_p->i_length;
  v23 = (unsigned int)(v22 + 90);
  if ( (unsigned int)v23 >= v9->i_str_ref_p->i_size || v9->i_str_ref_p->i_ref_count + v9->i_str_ref_p->i_read_only != 1 )
    AString::set_size(v9, v23);
  memset(&v9->i_str_ref_p->i_cstr_p[v22], 118, 0x5Aui64);
  v9->i_str_ref_p->i_cstr_p[v23] = 0;
  v9->i_str_ref_p->i_length = v23;
  AString::append(v9, "\n", 0xFFFFFFFF);
  AString::append(v9, &v8->i_str_ref_p->i_cstr_p[start_pos], end_pos - start_pos);
  v45 = find_pos_p - 1;
  v24 = AString::find(v8, 10, 1u, &v45, end_pos, 0xFFFFFFFF);
  LOBYTE(result_start) = v24;
  if ( v45 - end_pos != -1 )
    AString::append(v9, &v8->i_str_ref_p->i_cstr_p[end_pos], v45 - end_pos + 1);
  if ( v8->i_str_ref_p->i_length )
  {
    last_counted_p = 0;
    v25 = AString::count(v8, 10, 0, end_pos, &last_counted_p);
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
    v27 = v9->i_str_ref_p->i_length + 1;
    if ( (unsigned int)v27 >= v9->i_str_ref_p->i_size
      || v9->i_str_ref_p->i_ref_count + v9->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(v9, v27);
    }
    v9->i_str_ref_p->i_cstr_p[(unsigned int)(v27 - 1)] = 10;
    v9->i_str_ref_p->i_cstr_p[v27] = 0;
    v9->i_str_ref_p->i_length = v27;
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
    v31.i_str_ref_p = v9->i_str_ref_p;
    last_counted_p = v9->i_str_ref_p->i_length;
    v32 = v30 - 1 + last_counted_p;
    if ( (unsigned int)v32 >= v31.i_str_ref_p->i_size
      || v31.i_str_ref_p->i_ref_count + v31.i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(v9, v32);
    }
    memset(&v9->i_str_ref_p->i_cstr_p[last_counted_p], 62, v30 - 1);
    v9->i_str_ref_p->i_cstr_p[v32] = 0;
    v9->i_str_ref_p->i_length = v32;
  }
  if ( v30 >= 1 )
  {
    v33 = v9->i_str_ref_p->i_length + 1;
    if ( (unsigned int)v33 >= v9->i_str_ref_p->i_size
      || v9->i_str_ref_p->i_ref_count + v9->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(v9, v33);
    }
    v9->i_str_ref_p->i_cstr_p[(unsigned int)(v33 - 1)] = 32;
    v9->i_str_ref_p->i_cstr_p[v33] = 0;
    v9->i_str_ref_p->i_length = v33;
  }
  if ( v28 >= 2 )
  {
    v34 = v28 - 1;
    v35 = v9->i_str_ref_p->i_length;
    v36 = v28 - 1 + (unsigned int)v35;
    if ( (unsigned int)v36 >= v9->i_str_ref_p->i_size
      || v9->i_str_ref_p->i_ref_count + v9->i_str_ref_p->i_read_only != 1 )
    {
      AString::set_size(v9, v36);
    }
    memset(&v9->i_str_ref_p->i_cstr_p[v35], 45, v34);
    v9->i_str_ref_p->i_cstr_p[v36] = 0;
    v9->i_str_ref_p->i_length = v36;
  }
  v37 = v9->i_str_ref_p->i_length + 256;
  if ( v37 >= v9->i_str_ref_p->i_size || v9->i_str_ref_p->i_ref_count + v9->i_str_ref_p->i_read_only != 1 )
    AString::set_size(v9, v37);
  v38 = v25 + 1;
  if ( v30 == v10 )
  {
    AString::append_format(v9, "^ <<<< Line: %u, column: %u\n", v38, v10 + 1);
  }
  else
  {
    LODWORD(v42) = v10 + 1;
    AString::append_format(v9, "^ <<<< Line: %u, columns: %u-%u\n", v38, v30 + 1, v42);
  }
  if ( (_BYTE)result_start )
    AString::append(v9, &v8->i_str_ref_p->i_cstr_p[v45 + 1], find_pos_p - v45 - 1);
  AString::remove_all(v9, 13, 0, 0xFFFFFFFF);
  AString::append(v9, "\n", 0xFFFFFFFF);
  v39 = v9->i_str_ref_p->i_length;
  v40 = (unsigned int)(v39 + 90);
  if ( (unsigned int)v40 >= v9->i_str_ref_p->i_size || v9->i_str_ref_p->i_ref_count + v9->i_str_ref_p->i_read_only != 1 )
    AString::set_size(v9, v40);
  memset(&v9->i_str_ref_p->i_cstr_p[v39], 94, 0x5Aui64);
  v9->i_str_ref_p->i_cstr_p[v40] = 0;
  v9->i_str_ref_p->i_length = v40;
  AString::append(v9, "\n", 0xFFFFFFFF);
  return v9;
}

// File Line: 11278
// RVA: 0x119670
AString *__fastcall SSParser::get_result_string(AString *result, SSParser::eResult a2)
{
  AString *v2; // rbx
  const char *v3; // rdx
  __int64 v5; // [rsp+20h] [rbp-10h]

  v2 = result;
  LODWORD(v5) = 0;
  switch ( a2 )
  {
    case 0:
      AString::AString(result, "The text was parsed without error.");
      return v2;
    case 3:
      v3 = "Identifier name is longer than the maximum.\n"
           "All characters greater than the maximum of 256 have been truncated.";
      break;
    case 6:
      v3 = "The expression has no side effects so it does not seem useful as a statement\n"
           "on its own [not used as an argument or result (last expression) of a code block].";
      break;
    case 7:
      v3 = "The expression has only sub-expressions with side effects - it does not seem\n"
           "useful as a statement on its own [not used as an argument or result (last\n"
           "expression) of a code block].";
      break;
    case 9:
      v3 = "Expected a digit or letter [depending on the radix/base] but did not receive one.";
      break;
    case 10:
      v3 = "A binding must begin with a colon ':'.";
      break;
    case 11:
      v3 = "Expected a code block [ ], but did not find one.";
      break;
    case 12:
      v3 = "Expected the class cast operator '<>', but it was not found.";
      break;
    case 13:
      v3 = "A character escape sequence must begin with a backslash character '\\'.";
      break;
    case 14:
      v3 = "A character escape sequence that uses a number must have ASCII value between 0 and 255.";
      break;
    case 15:
      v3 = "Class name must begin with an uppercase letter.";
      break;
    case 16:
      v3 = "Expected class, list-class, invoke class, metaclass or class union and did not find one.";
      break;
    case 17:
      v3 = "A List class descriptor must follow the list class type with braces/curly brackets '{}' optionally enclosed a"
           "round an item type.";
      break;
    case 18:
      v3 = "A List class descriptor must end with a closing brace/curly bracket '}'.";
      break;
    case 19:
      v3 = "Expected a class, list-class or invoke class and did not find one.";
      break;
    case 20:
      v3 = "A metaclass descriptor must begin with an angle bracket '<'.";
      break;
    case 21:
      v3 = "A metaclass descriptor must end with a closing angle bracket '>'.";
      break;
    case 22:
      v3 = "A class union descriptor must begin with an opening angle bracket '<'.";
      break;
    case 23:
      v3 = "A class union descriptor must end with a closing angle bracket '>'.";
      break;
    case 24:
      v3 = "Expected a clause code block [ ], but did not receive one.";
      break;
    case 25:
      v3 = "A code block must start with an opening square bracket '['.";
      break;
    case 26:
      v3 = "Multiple line comment missing closing delimiters '*//' .";
      break;
    case 27:
      v3 = "Expected the class conversion operator '>>', but it was not found.";
      break;
    case 28:
      v3 = "A data definition statement must start with an exclamation mark '!'.";
      break;
    case 29:
      v3 = "Expected a digit, but did not receive one.";
      break;
    case 30:
      v3 = "Expected an expression, but did not find one.";
      break;
    case 31:
      v3 = "A group parameter specification must begin with an opening brace '{'.";
      break;
    case 32:
      v3 = "Instance name must begin with a lowercase letter.";
      break;
    case 33:
      v3 = "Expected a negative sign '-' or a digit, but received neither.";
      break;
    case 34:
      v3 = "An invocation apply must begin with a percent sign '%' character.";
      break;
    case 35:
      v3 = "An invocation argument list must begin with an opening parenthesis (bracket) '('.\n[Missing a period?]";
      break;
    case 36:
      v3 = "An argument in an invocation argument list must be followed by a comma ',' argument delimiter, semi-colon ';'"
           " return argument delimiter or an ending parenthesis (bracket) ')'.";
      break;
    case 37:
      v3 = "An invocation return argument list must begin with an opening brace '{'.";
      break;
    case 38:
      v3 = "Expected cascaded invocations - i.e. a receiver followed by '.' then '[' then two or more invocations and end"
           "ing in ']' and did not find any.";
      break;
    case 39:
      v3 = "Expected cascaded invocations - i.e. a receiver followed '.' then '[' then two or more invocations and ending"
           " in ']' and only found one invocation.\n"
           "[If only one invocation is desired, then just use '.' - i.e. receiver.invoke()].\n";
      break;
    case 40:
      v3 = "Expected an invocation selector - i.e. a method call or coroutine call,\nbut found neither.";
      break;
    case 41:
      v3 = "Expected an invocation selector - i.e. a method call, an operator call\n"
           "or coroutine call, but found neither.";
      break;
    case 42:
      v3 = "A character literal must begin with an accent [`] character - the one beneath the tilde '~'.";
      break;
    case 43:
      v3 = "Expected a List literal opening brace/curly bracket '{', but did not receive one.";
      break;
    case 44:
      v3 = "An item delimiter ',' or a closing brace/curly bracket '}' was expected while parsing a List literal, but did"
           " not receive either.";
      break;
    case 45:
      v3 = "A string literal must begin with a double quote [\"]";
      break;
    case 46:
      v3 = "A symbol literal must begin with a single quote ['].";
      break;
    case 47:
      v3 = "A symbol literal must end with a single quote ['].";
      break;
    case 48:
      v3 = "Expected a loop code block [ ], but did not receive one.";
      break;
    case 49:
      v3 = "A loop exit must begin with 'exit'.";
      break;
    case 50:
      v3 = "Expected a class meta key name (demand_load or object_id_lookup).";
      break;
    case 52:
      v3 = "A constructor method name must begin with an exclamation mark '!' and be optionally followed by an identifier"
           " starting with a lowercase letter.";
      break;
    case 53:
      v3 = "A method name must begin with a lowercase letter or an exclamation mark '!'";
      break;
    case 54:
      v3 = "Expected a named argument specifier (arg_name#) and did not find one.";
      break;
    case 55:
      v3 = "Expected an operator method call, but did not find one.";
      break;
    case 56:
      v3 = "Expected an operator id, but did not find the '@' or '@?' symbols.";
      break;
    case 57:
      v3 = "A parameter list must start with an opening parenthesis (bracket) '('.";
      break;
    case 58:
      v3 = "Argument descriptors must be named and no name was found.";
      break;
    case 59:
      v3 = "Expected a 'race' code block [ ], but did not find one.";
      break;
    case 60:
      v3 = "While parsing a real number, expected a fractional part ('.' digit {digit}),\n"
           "an exponent part ('E' | 'e' ['-'] digits), or both, but received neither.";
      break;
    case 61:
      v3 = "A script name must begin with an underscore '_' and then a lowercase letter.";
      break;
    case 62:
      v3 = "Expected a scope resolution operator to follow the given class scope.";
      break;
    case 63:
      v3 = "String literal missing closing double quotation mark '\"'.";
      break;
    case 64:
      v3 = "A strategy name must begin with a dollar sign '$' and then a lowercase letter.";
      break;
    case 65:
      v3 = "String literal missing closing quotation mark (').";
      break;
    case 66:
      v3 = "A create temporary variable statement must start with an exclamation mark '!'.";
      break;
    case 67:
      v3 = "Expected a 'sync' code block [ ], but did not find one.";
      break;
    case 68:
      v3 = "Whitespace required - expected some combination of whitespace characters and/or comments.";
      break;
    case 69:
      v3 = "Invocation expected ',' ')' or an expression.";
      break;
    case 70:
      v3 = "A variable rebind to an instance may only be applied to an identifier.";
      break;
    case 71:
      v3 = "A concurrent branch only makes sense when used on an expression that is not immediate\n"
           "and may take more than one frame to execute such as a coroutine call.";
      break;
    case 72:
      v3 = "While parsing for a 'create temporary variable statement', a constructor or a destructor call was found instead.";
      break;
    case 73:
      v3 = "Expected a particular character or type of character, but did not receive it.";
      break;
    case 74:
      v3 = "The metaclass '<Object>' should be used instead of the class instance 'Class'.";
      break;
    case 75:
      v3 = "Group parameter descriptor expected a class name or '}', but neither were found.";
      break;
    case 76:
      v3 = "Found a trailing concurrency delimiter ',' at the end of a code block.\n"
           "A concurrency delimiter is valid only when it is between two statements.";
      break;
    case 79:
      v3 = "A divert only makes sense when used on expressions that are durational / non-immediate\n"
           "such as coroutine calls that may take more than one frame to execute and thereforerequire update calls.";
      break;
    case 80:
      v3 = "An else / default clause may not be the sole clause - there must be at least one more prior to it.";
      break;
    case 81:
      v3 = "Found an 'else' without a matching 'if' or 'case'.";
      break;
    case 82:
      v3 = "Hit end of file prior to the completion of a parse.\n[Mismatched brackets [] {} ()?]";
      break;
    case 83:
      v3 = "Found a loop exit in an invalid location.";
      break;
    case 84:
      v3 = "Operator calls may not be used with an implicit 'this' - otherwise it is more error\n"
           "prone and even when used correctly code is more difficult to understand.";
      break;
    case 85:
      v3 = "[A named specifier must appear before an argument rather than after - arg_name#arg.]\n"
           "An argument in an invocation argument list must be followed by a comma ',' argument delimiter, semi-colon ';'"
           " return argument delimiter or an ending parenthesis (bracket) ')'.";
      break;
    case 86:
      v3 = "Found an object-identifier when a closure was expected.";
      break;
    case 87:
      v3 = "The parameter list expected ',' or ')', but neither were found.";
      break;
    case 88:
      v3 = "The parameter list did not expect an extra semi-colon ';'!  Return parameters already started.";
      break;
    case 90:
      v3 = "The code block expected another statement or the end of the code block ']'.";
      break;
    case 91:
      v3 = "A class union descriptor must union two or more classes.";
      break;
    case 92:
      AString::AString(
        result,
        0x100u,
        "The group parameter descriptor contained too many classes.\n"
        "There may not be more than %i classes in the pattern.",
        63i64,
        v5,
        -2i64);
      return v2;
    case 93:
      v3 = "Radix too large - it must be between 2 and 36 inclusively.";
      break;
    case 94:
      v3 = "Radix too small - it must be between 2 and 36 inclusively.";
      break;
    case 95:
      v3 = "An identifier may be no more than 255 characters long.";
      break;
    case 96:
      v3 = "A symbol literal may be no more than 255 characters long.";
      break;
    case 97:
      v3 = "The case comparison expression must resolve to a class type that has an equals operator '='.";
      break;
    case 98:
      v3 = "A conversion method may not have any parameters [this may change in the future].";
      break;
    case 99:
      v3 = "This data member name is a duplicate of one already existing in this class.";
      break;
    case 100:
      v3 = "This data member name is a duplicate of one already existing in a superclass of this class.";
      break;
    case 101:
      v3 = "This data member name is a duplicate of one already existing in a subclass of this class.";
      break;
    case 102:
      v3 = "Argument with the same name already present in the parameter list.";
      break;
    case 103:
      v3 = "Argument with the same name already present in the return parameter list.";
      break;
    case 105:
      v3 = "Expected the end of the invocation list ')', but did not find it.\n[Too many arguments supplied?]";
      break;
    case 110:
      v3 = "Once a named argument is used, any following arguments must also be named.";
      break;
    case 111:
      v3 = "The specified constructor method requires one or more arguments.";
      break;
    case 112:
      v3 = "A class with the specified name does not exist - ensure that it is registered prior to this parse.";
      break;
    case 119:
      v3 = "A deferred statement (such as a coroutine) was found where an immediate statement (such as a method) was expected.";
      break;
    case 120:
      v3 = "An immediate statement (such as a method) was found where a deferred statement (such as a coroutine) was expected.";
      break;
    case 121:
      v3 = "A concurrent block (sync or race) should have at least two durational expressions or running concurrently is redundant.";
      break;
    case 122:
      v3 = "Expected an Actor class or subclass, but given a non-actor class.";
      break;
    case 123:
      v3 = "The class scope for coroutines and strategies must be an Actor class or an Actor subclass.";
      break;
    case 126:
      v3 = "The result class type of a case test expression must be compatible as an operand to the equals operator '=' o"
           "f the comparison expression.";
      break;
    case 128:
      v3 = "Generic types are not supported in closure parameter lists and might never be - too many levels of indirectio"
           "n to wrap your head around";
      break;
    case 129:
      v3 = "The result type of a conditional test expression must be a Boolean class.";
      break;
    case 130:
      v3 = "The result type of a conversion method must be of the same type as or a subclass of the method name.";
      break;
    case 131:
      v3 = "The result type of the default expression was not compatible with the specified parameter type.";
      break;
    case 133:
      v3 = "Cannot do an invoke apply [receiver%invocation()] on a receiver that is guaranteed to be nil.";
      break;
    case 134:
      v3 = "Expected a List class or subclass, but given a non-list class.";
      break;
    case 135:
      v3 = "Supplied list item is not of the specified desired class type.";
      break;
    case 138:
      v3 = "The specified class scope qualifier is not the same class or a superclass of the class of the receiver expres"
           "sion (or implied 'this').  Note that a NilClass may only have a scope qualifier of 'Object'.";
      break;
    case 139:
      v3 = "This class union descriptor is trivial.\n"
           "It is lexically correct, but it can be represented more simply as a single class instance or metaclass.";
      break;
    default:
      v3 = a_cstr_format("Parse error: #%u.\n[Use a build with additional error checking (SS_CODE_OUT defined) for more context.]");
      break;
  }
  AString::AString(v2, v3);
  return v2;
}

// File Line: 11548
// RVA: 0x11A870
void SSParser::initialize_pre_load(void)
{
  unsigned int v0; // eax
  ASymbol **v1; // rbx
  unsigned int v2; // eax
  AString **v3; // rbx
  __int64 v4; // rbx
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
        v1 = SSParser::c_reserved_word_syms.i_array_p;
        SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v0);
        memmove(SSParser::c_reserved_word_syms.i_array_p, v1, 8i64 * SSParser::c_reserved_word_syms.i_count);
        AMemory::c_free_func(v1);
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
    v4 = SSParser::c_reserved_word_syms.i_count;
    if ( SSParser::c_reserved_word_syms.i_size < SSParser::c_reserved_word_syms.i_count + 1 )
    {
      v5 = SSParser::c_reserved_word_syms.i_array_p;
      if ( SSParser::c_reserved_word_syms.i_count == -1 )
        v6 = 0;
      else
        v6 = AMemory::c_req_byte_size_func(8 * (SSParser::c_reserved_word_syms.i_count & 0xFFFFFFFC) + 32) >> 3;
      SSParser::c_reserved_word_syms.i_size = v6;
      SSParser::c_reserved_word_syms.i_array_p = APArrayBase<ASymbol>::alloc_array(v6);
      memmove(SSParser::c_reserved_word_syms.i_array_p, v5, 8 * v4);
      AMemory::c_free_func(v5);
    }
    SSParser::c_reserved_word_syms.i_array_p[v4] = &ASymbol_branch;
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v49,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v51,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v53,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v55,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v57,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v59,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v61,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v63,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v65,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v67,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v69,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v71,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v73,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v75,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_reserved_word_strs.i_count,
      v77,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_operator_word_strs.i_count,
      v81,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_operator_word_strs.i_count,
      v83,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_operator_word_strs.i_count,
      v85,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_operator_word_strs.i_count,
      v87,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_operator_word_strs.i_count,
      v89,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_operator_word_strs.i_count,
      v91,
      0i64);
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
    APSorted<AString,AString,ACompareLogical<AString>>::append(
      (APSorted<AString,AString,ACompareLogical<AString> > *)&SSParser::c_operator_word_strs.i_count,
      v93,
      0i64);
  }
}

// File Line: 11920
// RVA: 0x13C9E0
SSParser::string_to_esacpe_string

// File Line: 12057
// RVA: 0x12E480
void __fastcall SSParser::parse_name_symbol(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, ASymbol *name_p)
{
  unsigned int v4; // er11
  unsigned int v5; // ebp
  ASymbol *v6; // rsi
  unsigned int *v7; // rbx
  SSParser *v8; // rdi
  ASymbol result; // [rsp+40h] [rbp+8h]

  v4 = *end_pos_p;
  v5 = start_pos;
  v6 = name_p;
  v7 = end_pos_p;
  *end_pos_p = this->i_str_ref_p->i_length;
  v8 = this;
  AString::find((AString *)&this->i_str_ref_p, ACharMatch_not_identifier, 1u, end_pos_p, v4, 0xFFFFFFFF);
  if ( v6 )
    v6->i_uid = SSParser::as_symbol(v8, &result, v5, *v7)->i_uid;
}

// File Line: 12087
// RVA: 0x129C30
SSDivert *__fastcall SSParser::parse_divert_block(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // rbx
  SSParser *v3; // rdi
  SSParser::eResult v4; // eax
  SSCode *v5; // rax
  SSCode *v6; // rsi
  SSDivert *v7; // rdi
  SSDivert *v8; // rax
  SSDivert *result; // rax
  unsigned int end_pos_p; // [rsp+40h] [rbp+8h]

  v2 = args;
  v3 = this;
  args->i_result = 82;
  LODWORD(args) = args->i_start_pos;
  end_pos_p = (unsigned int)args;
  if ( this->i_str_ref_p->i_length - (unsigned int)args < 2
    || (v4 = SSParser::parse_ws_any(this, (unsigned int)args, &end_pos_p),
        v2->i_result = v4,
        args = (SSParser::Args *)end_pos_p,
        v2->i_end_pos = end_pos_p,
        v4)
    || (v2->i_result = 11, *((_BYTE *)&args->i_start_pos + (unsigned __int64)v3->i_str_ref_p->i_cstr_p) != 91) )
  {
    v2->i_end_pos = (unsigned int)args;
    result = 0i64;
  }
  else
  {
    v2->i_start_pos = (unsigned int)args;
    v5 = SSParser::parse_code_block_optimized(v3, v2, SSInvokeTime_any, ResultDesired_true);
    v6 = v5;
    v7 = 0i64;
    if ( v2->i_result == Result_ok && v5 )
    {
      v8 = (SSDivert *)AMemory::c_malloc_func(0x10ui64, "SSDivert");
      *(_QWORD *)&end_pos_p = v8;
      if ( v8 )
      {
        v8->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
        v8->vfptr = (SSExpressionBaseVtbl *)&SSDivert::`vftable';
        v8->i_statement_p = (SSExpressionBase *)&v6->vfptr;
        v7 = v8;
      }
    }
    result = v7;
  }
  return result;
}

// File Line: 12147
// RVA: 0x12E6A0
ASymbol *__fastcall SSParser::parse_object_id_tail(SSParser *this, SSParser::Args *args, SSClass *class_p)
{
  SSActorClass *v3; // rsi
  SSParser::Args *v4; // rbx
  SSParser *v5; // r14
  __int64 v6; // rdx
  char *v7; // r8
  unsigned int v8; // edx
  ASymbol *v9; // rdi
  char v10; // cl
  SSParser::eResult v11; // eax
  __int64 v12; // r8
  SSClass *v13; // rax
  ASymbol *v14; // rax
  ASymbol *v15; // rdx
  void **v17; // [rsp+28h] [rbp-50h]
  ASymbol sym_p; // [rsp+30h] [rbp-48h]
  SSActorClass *v19; // [rsp+38h] [rbp-40h]
  __int64 v20; // [rsp+40h] [rbp-38h]
  unsigned int v21; // [rsp+48h] [rbp-30h]
  unsigned int v22; // [rsp+50h] [rbp-28h]

  v3 = (SSActorClass *)class_p;
  v4 = args;
  v5 = this;
  v6 = args->i_start_pos;
  v7 = this->i_str_ref_p->i_cstr_p;
  if ( (unsigned int)v6 < this->i_str_ref_p->i_length && v7[v6] == 64 )
  {
    v8 = v6 + 1;
    v17 = &SSObjectId::`vftable';
    sym_p.i_uid = -1;
    v9 = 0i64;
    v19 = 0i64;
    v20 = 0i64;
    v21 = 0;
    v22 = 0;
    if ( !v3 )
      v3 = SSBrain::c_actor_class_p;
    v19 = v3;
    v10 = v7[v8];
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
    v11 = (unsigned int)SSParser::parse_literal_symbol(v5, v8, &v4->i_end_pos, &sym_p);
    v4->i_result = v11;
    if ( v11 == Result_ok )
    {
      if ( (v3->i_flags >> 4) & 1 )
      {
        v12 = v5->i_flags.i_flagset >> 8;
        LOBYTE(v12) = (LOWORD(v5->i_flags.i_flagset) >> 8) & 1;
        v13 = (SSClass *)((__int64 (__fastcall *)(SSActorClass *, void ***, __int64))v19->vfptr[1].is_actor_instance)(
                           v19,
                           &v17,
                           v12);
        if ( v13 )
        {
          if ( v22 & 2 )
            v13 = SSBrain::c_symbol_class_p;
          v4->i_type_p = (SSClassDescBase *)&v13->vfptr;
          if ( !(v4->i_flags & 1) )
            goto LABEL_24;
          v14 = (ASymbol *)AMemory::c_malloc_func(0x30ui64, "SSObjectId");
          v15 = v14;
          if ( v14 )
          {
            *(_QWORD *)&v14->i_uid = &SSExpressionBase::`vftable';
            *(_QWORD *)&v14->i_uid = &SSObjectId::`vftable';
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
LABEL_23:
          v9 = v15;
LABEL_24:
          v17 = &SSExpressionBase::`vftable';
          return v9;
        }
        v4->i_result = 118;
      }
      else
      {
        v4->i_result = 117;
      }
    }
    v15 = 0i64;
    goto LABEL_23;
  }
  v4->i_result = 56;
  return 0i64;
}

// File Line: 12264
// RVA: 0x12FB70
SSInvocation *__fastcall SSParser::parse_prefix_operator_expr(SSParser *this, ASymbol *op_name, SSParser::Args *args)
{
  SSParser::Args *v3; // rbx
  ASymbol *v4; // r14
  SSParser *v5; // rbp
  SSParser::eResult v6; // eax
  SSLiteralList *v7; // rsi
  SSClassDescBase *v8; // rdi
  __int64 v9; // rax
  _QWORD *v11; // rbx
  _QWORD *v12; // rdi
  ASymbol *v13; // rax

  v3 = args;
  v4 = op_name;
  v5 = this;
  v6 = SSParser::parse_ws_any(this, args->i_start_pos, &args->i_end_pos);
  v3->i_result = v6;
  if ( v6 )
    return 0i64;
  v3->i_start_pos = v3->i_end_pos;
  v7 = SSParser::parse_expression(v5, v3, 1i64);
  if ( v3->i_result )
    return 0i64;
  v8 = v3->i_type_p;
  if ( v5->i_flags.i_flagset & 1 )
  {
    v9 = (__int64)v8->vfptr->get_method_inherited(v3->i_type_p, v4);
    if ( !v9 )
    {
      v3->i_result = 115;
      if ( v7 )
        v7->vfptr->__vecDelDtor((SSExpressionBase *)&v7->vfptr, 1u);
      return 0i64;
    }
    (*(void (__fastcall **)(_QWORD, SSClassDescBase *))(**(_QWORD **)(*(_QWORD *)(v9 + 24) + 40i64) + 32i64))(
      *(_QWORD *)(*(_QWORD *)(v9 + 24) + 40i64),
      v8);
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
        v13[2].i_uid = v4->i_uid;
        *(_QWORD *)&v13[4].i_uid = 0i64;
        *(_QWORD *)&v13->i_uid = &SSInvokeBase::`vftable';
        v13[6].i_uid = 0;
        *(_QWORD *)&v13[8].i_uid = 0i64;
        v13[10].i_uid = 0;
        *(_QWORD *)&v13[12].i_uid = 0i64;
        *(_QWORD *)&v13->i_uid = &SSMethodCall::`vftable';
      }
      else
      {
        v13 = 0i64;
      }
      *v12 = &SSExpressionBase::`vftable';
      *v12 = &SSInvocation::`vftable';
      v12[1] = v7;
      v12[2] = v13;
      v11 = v12;
    }
  }
  return (SSInvocation *)v11;
}

// File Line: 12342
// RVA: 0x1291D0
SSConcurrentBranch *__fastcall SSParser::parse_concurrent_branch_block(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // rbx
  SSParser *v3; // rdi
  SSParser::eResult v4; // eax
  SSConcurrentBranch *v5; // rsi
  SSCode *v6; // rax
  SSCode *v7; // rdi
  SSConcurrentBranch *v8; // rax
  SSConcurrentBranch *result; // rax
  unsigned int end_pos_p; // [rsp+40h] [rbp+8h]

  v2 = args;
  v3 = this;
  args->i_result = 82;
  LODWORD(args) = args->i_start_pos;
  end_pos_p = (unsigned int)args;
  if ( this->i_str_ref_p->i_length - (unsigned int)args < 2
    || (v4 = SSParser::parse_ws_any(this, (unsigned int)args, &end_pos_p),
        v2->i_result = v4,
        args = (SSParser::Args *)end_pos_p,
        v2->i_end_pos = end_pos_p,
        v4)
    || (v2->i_result = 11, *((_BYTE *)&args->i_start_pos + (unsigned __int64)v3->i_str_ref_p->i_cstr_p) != 91) )
  {
    v2->i_end_pos = (unsigned int)args;
    result = 0i64;
  }
  else
  {
    v2->i_start_pos = (unsigned int)args;
    v5 = 0i64;
    v6 = SSParser::parse_code_block_optimized(v3, v2, SSInvokeTime_any, 0);
    v7 = v6;
    if ( v2->i_result == Result_ok )
    {
      if ( v6 && v6->vfptr->is_immediate((SSExpressionBase *)&v6->vfptr, 0i64) )
      {
        v2->i_result = 71;
        v7->vfptr->__vecDelDtor((SSExpressionBase *)&v7->vfptr, 1u);
      }
      else
      {
        v2->i_type_p = (SSClassDescBase *)&SSBrain::c_none_class_p->vfptr;
        if ( v7 )
        {
          v8 = (SSConcurrentBranch *)AMemory::c_malloc_func(0x10ui64, "SSConcurrentBranch");
          *(_QWORD *)&end_pos_p = v8;
          if ( v8 )
          {
            v8->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
            v8->vfptr = (SSExpressionBaseVtbl *)&SSConcurrentBranch::`vftable';
            v8->i_statement_p = (SSExpressionBase *)&v7->vfptr;
            v5 = v8;
          }
        }
      }
    }
    result = v5;
  }
  return result;
}

// File Line: 12415
// RVA: 0x129420
SSConcurrentSync *__fastcall SSParser::parse_concurrent_sync_block(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // rbx
  SSParser *v3; // rdi
  SSParser::eResult v4; // eax
  SSCode *v5; // rax
  SSCode *v6; // rdi
  SSConcurrentSync *v7; // rsi
  SSConcurrentSync *v8; // r8
  signed __int64 v9; // rdx
  SSExpressionBase **v10; // rcx
  SSConcurrentSync *result; // rax
  unsigned int end_pos_p; // [rsp+40h] [rbp+8h]
  __int64 v13; // [rsp+48h] [rbp+10h]

  v2 = args;
  v3 = this;
  args->i_result = 82;
  LODWORD(args) = args->i_start_pos;
  end_pos_p = (unsigned int)args;
  if ( this->i_str_ref_p->i_length - (unsigned int)args < 2
    || (v4 = SSParser::parse_ws_any(this, (unsigned int)args, &end_pos_p),
        v2->i_result = v4,
        args = (SSParser::Args *)end_pos_p,
        v2->i_end_pos = end_pos_p,
        v4)
    || (v2->i_result = 67, *((_BYTE *)&args->i_start_pos + (unsigned __int64)v3->i_str_ref_p->i_cstr_p) != 91) )
  {
    v2->i_end_pos = (unsigned int)args;
    result = 0i64;
  }
  else
  {
    v2->i_start_pos = (unsigned int)args;
    v5 = SSParser::parse_code_block(v3, v2, SSInvokeTime_durational, 0);
    v6 = v5;
    v7 = 0i64;
    if ( v2->i_result == Result_ok )
    {
      v2->i_type_p = (SSClassDescBase *)&SSBrain::c_none_class_p->vfptr;
      if ( v5 )
      {
        if ( v5->i_statements.i_count < 2 )
        {
          v2->i_result = 121;
        }
        else
        {
          v8 = (SSConcurrentSync *)AMemory::c_malloc_func(0x18ui64, "SSConcurrentSync");
          *(_QWORD *)&end_pos_p = v8;
          if ( v8 )
          {
            v8->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
            v8->vfptr = (SSExpressionBaseVtbl *)&SSConcurrentSync::`vftable';
            v9 = (signed __int64)&v8->i_exprs;
            v13 = v9;
            v10 = v6->i_statements.i_array_p;
            *(_DWORD *)v9 = v6->i_statements.i_count;
            *(_QWORD *)(v9 + 8) = v10;
            v6->i_statements.i_count = 0;
            v6->i_statements.i_array_p = 0i64;
            v7 = v8;
          }
        }
        v6->vfptr->__vecDelDtor((SSExpressionBase *)&v6->vfptr, 1u);
      }
    }
    result = v7;
  }
  return result;
}

// File Line: 12488
// RVA: 0x1292F0
SSConcurrentRace *__fastcall SSParser::parse_concurrent_race_block(SSParser *this, SSParser::Args *args)
{
  SSParser::Args *v2; // rbx
  SSParser *v3; // rdi
  SSParser::eResult v4; // eax
  SSCode *v5; // rax
  SSCode *v6; // rdi
  SSConcurrentRace *v7; // rsi
  SSConcurrentRace *v8; // r8
  signed __int64 v9; // rdx
  SSExpressionBase **v10; // rcx
  SSConcurrentRace *result; // rax
  unsigned int end_pos_p; // [rsp+40h] [rbp+8h]
  __int64 v13; // [rsp+48h] [rbp+10h]

  v2 = args;
  v3 = this;
  args->i_result = 82;
  LODWORD(args) = args->i_start_pos;
  end_pos_p = (unsigned int)args;
  if ( this->i_str_ref_p->i_length - (unsigned int)args < 2
    || (v4 = SSParser::parse_ws_any(this, (unsigned int)args, &end_pos_p),
        v2->i_result = v4,
        args = (SSParser::Args *)end_pos_p,
        v2->i_end_pos = end_pos_p,
        v4)
    || (v2->i_result = 59, *((_BYTE *)&args->i_start_pos + (unsigned __int64)v3->i_str_ref_p->i_cstr_p) != 91) )
  {
    v2->i_end_pos = (unsigned int)args;
    result = 0i64;
  }
  else
  {
    v2->i_start_pos = (unsigned int)args;
    v5 = SSParser::parse_code_block(v3, v2, SSInvokeTime_durational, 0);
    v6 = v5;
    v7 = 0i64;
    if ( v2->i_result == Result_ok )
    {
      v2->i_type_p = (SSClassDescBase *)&SSBrain::c_none_class_p->vfptr;
      if ( v5 )
      {
        if ( v5->i_statements.i_count < 2 )
        {
          v2->i_result = 121;
        }
        else
        {
          v8 = (SSConcurrentRace *)AMemory::c_malloc_func(0x18ui64, "SSConcurrentRace");
          *(_QWORD *)&end_pos_p = v8;
          if ( v8 )
          {
            v8->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
            v8->vfptr = (SSExpressionBaseVtbl *)&SSConcurrentRace::`vftable';
            v9 = (signed __int64)&v8->i_exprs;
            v13 = v9;
            v10 = v6->i_statements.i_array_p;
            *(_DWORD *)v9 = v6->i_statements.i_count;
            *(_QWORD *)(v9 + 8) = v10;
            v6->i_statements.i_count = 0;
            v6->i_statements.i_array_p = 0i64;
            v7 = v8;
          }
        }
        v6->vfptr->__vecDelDtor((SSExpressionBase *)&v6->vfptr, 1u);
      }
    }
    result = v7;
  }
  return result;
}

// File Line: 12577
// RVA: 0x12EEC0
SSParser::eResult __fastcall SSParser::parse_param_append(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSParameters *params_p)
{
  SSParameters *v4; // rdi
  unsigned int *v5; // rbx
  SSParser::eResult result; // eax
  SSParser::eResult v7; // ebx
  unsigned int v8; // er8
  unsigned int v9; // ecx
  SSParameterBase **v10; // rdx
  unsigned __int64 i; // r10
  SSParameterBase *param_new_pp; // [rsp+58h] [rbp+20h]

  v4 = params_p;
  v5 = end_pos_p;
  if ( params_p )
  {
    result = SSParser::parse_parameter(this, start_pos, end_pos_p, &param_new_pp);
    v7 = result;
    if ( result )
      return result;
    v8 = 0;
    v9 = v4->i_params.i_count;
    if ( v9 )
    {
      v10 = v4->i_params.i_array_p;
      for ( i = (unsigned __int64)&v10[v9 - 1]; (unsigned __int64)v10 <= i; ++v10 )
      {
        if ( param_new_pp->i_name.i_uid == (*v10)->i_name.i_uid )
        {
          if ( v8 < 2 )
          {
            param_new_pp->vfptr->__vecDelDtor(param_new_pp, 1u);
            return 102;
          }
          --v8;
        }
      }
    }
    APCompactArray<SSParameterBase,ASymbol,ACompareLogical<ASymbol>>::append(
      (APCompactArray<SSParameterBase,ASymbol,ACompareLogical<ASymbol> > *)&v4->i_params.i_count,
      param_new_pp);
    result = v7;
  }
  else
  {
    if ( this->i_str_ref_p->i_cstr_p[start_pos] == 123 )
      result = SSParser::parse_parameter_group(this, start_pos, (unsigned int *)&param_new_pp, 0i64);
    else
      result = SSParser::parse_parameter_unary(this, start_pos, (unsigned int *)&param_new_pp, 0i64);
    if ( v5 )
      *v5 = (unsigned int)param_new_pp;
  }
  return result;
}

// File Line: 12635
// RVA: 0x12EFA0
SSParser::eResult __fastcall SSParser::parse_param_return_append(SSParser *this, unsigned int start_pos, unsigned int *end_pos_p, SSParameters *params_p, unsigned int param_flags)
{
  SSParameters *v5; // rbx
  unsigned int *v6; // rdi
  unsigned int v7; // esi
  SSParser *v8; // r14
  SSParser::eResult v9; // ebp
  SSClassDescBase *v10; // rdi
  unsigned int v11; // edx
  APCompactArray<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *v12; // r15
  unsigned int v13; // eax
  unsigned int v14; // esi
  SSTypedName **v15; // rcx
  unsigned __int64 i; // r8
  SSTypedName *v17; // rax
  SSTypedName *v18; // rbx
  SSTypedName tname_p; // [rsp+38h] [rbp-30h]

  v5 = params_p;
  v6 = end_pos_p;
  v7 = start_pos;
  v8 = this;
  if ( !params_p )
    return SSParser::parse_parameter_specifier(this, start_pos, end_pos_p, 0i64, param_flags);
  tname_p.i_name = (ASymbol)ASymbol::get_null()->i_uid;
  tname_p.i_type_p.i_obj_p = 0i64;
  v9 = SSParser::parse_parameter_specifier(v8, v7, v6, &tname_p, param_flags);
  v10 = tname_p.i_type_p.i_obj_p;
  if ( v9 == Result_ok )
  {
    v9 = 103;
    v11 = 0;
    v12 = (APCompactArray<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v5->i_return_params.i_count;
    v13 = v5->i_return_params.i_count;
    v14 = tname_p.i_name.i_uid;
    if ( v13 )
    {
      v15 = v5->i_return_params.i_array_p;
      for ( i = (unsigned __int64)&v15[v13 - 1]; (unsigned __int64)v15 <= i; ++v15 )
      {
        if ( tname_p.i_name.i_uid == (*v15)->i_name.i_uid )
        {
          if ( v11 < 2 )
            goto LABEL_16;
          --v11;
        }
      }
    }
    v9 = 0;
    v17 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
    v18 = v17;
    if ( v17 )
    {
      v17->i_name.i_uid = v14;
      v17->i_type_p.i_obj_p = v10;
      if ( v10 )
        (*(void (__fastcall **)(SSClassDescBase *))v10->vfptr->gap8)(v10);
    }
    else
    {
      v18 = 0i64;
    }
    APCompactArray<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(v12, v18);
    if ( v8->i_flags.i_flagset & 1 )
      SSTypeContext::append_local(&v8->i_context, &tname_p.i_name, (SSClassDescBase *)&SSBrain::c_none_class_p->vfptr);
  }
LABEL_16:
  if ( v10 )
    (*(void (__fastcall **)(SSClassDescBase *))&v10->vfptr->gap8[8])(v10);
  return v9;
}

// File Line: 12698
// RVA: 0x12FF40
char __fastcall SSParser::parse_temporary_append(SSParser *this, SSParser::Args *args, SSCode *code_p)
{
  SSCode *v3; // rbp
  SSParser::Args *v4; // rdi
  SSParser *v5; // rsi
  SSClassDescBase *v6; // rdi
  SSTypedName *v7; // rbx
  SSExpressionBase *v8; // rdi
  SSExpressionBase *v9; // rax
  SSExpressionBaseVtbl *v10; // rbx
  SSExpressionBase *v11; // rax
  ASymbol ident_p; // [rsp+58h] [rbp+10h]
  SSExpressionBase *expr_pp; // [rsp+68h] [rbp+20h]

  v3 = code_p;
  v4 = args;
  v5 = this;
  ident_p.i_uid = -1;
  expr_pp = 0i64;
  if ( !SSParser::parse_temporary(this, args, &ident_p, &expr_pp) )
    return 0;
  AVCompactSorted<ASymbol,ASymbol,ACompareLogical<ASymbol>>::append(
    (AVCompactSorted<ASymbol,ASymbol,ACompareLogical<ASymbol> > *)&v3->i_temp_vars.i_count,
    &ident_p,
    0i64);
  if ( v5->i_flags.i_flagset & 1 )
  {
    v6 = v4->i_type_p;
    v7 = (SSTypedName *)AMemory::c_malloc_func(0x10ui64, "SSTypedName");
    if ( v7 )
    {
      v7->i_name = ident_p;
      v7->i_type_p.i_obj_p = v6;
      if ( v6 )
        (*(void (__fastcall **)(SSClassDescBase *))v6->vfptr->gap8)(v6);
    }
    else
    {
      v7 = 0i64;
    }
    APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol>>::append(
      (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&v5->i_context.i_current_scope_p->i_count,
      v7,
      0i64);
  }
  v8 = expr_pp;
  if ( expr_pp )
  {
    v9 = (SSExpressionBase *)AMemory::c_malloc_func(0x10ui64, "SSIdentifier");
    v10 = (SSExpressionBaseVtbl *)v9;
    expr_pp = v9;
    if ( v9 )
    {
      v9->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
      v9->vfptr = (SSExpressionBaseVtbl *)&SSIdentifier::`vftable';
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
      v11->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
      v11->vfptr = (SSExpressionBaseVtbl *)&SSBind::`vftable';
      v11[1].vfptr = v10;
      v11[2].vfptr = (SSExpressionBaseVtbl *)v8;
    }
    APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
      (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *)&v3->i_statements.i_count,
      v11);
  }
  return 1;
}

// File Line: 12761
// RVA: 0x12FCC0
bool __fastcall SSParser::parse_statement_append(SSParser *this, SSParser::Args *args, SSCode *code_p, eSSInvokeTime desired_exec_time)
{
  __int64 v4; // r15
  SSParser *v5; // r14
  eSSInvokeTime v6; // er13
  char v7; // cl
  SSCode *v8; // rsi
  SSParser::Args *v9; // rbx
  SSExpressionBase *v10; // rdi
  SSLoopExit *v11; // rax
  bool v12; // r12
  unsigned int v13; // eax
  SSLiteralList *v14; // rax
  unsigned int v15; // esi

  v4 = args->i_start_pos;
  v5 = this;
  v6 = desired_exec_time;
  v7 = this->i_str_ref_p->i_cstr_p[v4];
  v8 = code_p;
  v9 = args;
  v10 = 0i64;
  if ( v7 == 33 )
  {
    if ( args->i_flags & 1 )
    {
      if ( SSParser::parse_temporary_append(v5, args, code_p) )
      {
        v13 = v8->i_statements.i_count;
        if ( v13 )
          v10 = v8->i_statements.i_array_p[v13 - 1];
      }
    }
    else
    {
      SSParser::parse_temporary(v5, args, 0i64, 0i64);
    }
    v12 = v9->i_end_pos != (_DWORD)v4;
  }
  else
  {
    if ( v7 != 101 )
      goto LABEL_12;
    v11 = SSParser::parse_loop_exit(v5, args);
    v12 = v9->i_end_pos != (_DWORD)v4;
    v10 = (SSExpressionBase *)&v11->vfptr;
    if ( v11 )
      APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
        (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *)&v8->i_statements.i_count,
        (SSExpressionBase *)&v11->vfptr);
  }
  if ( !v12 )
  {
LABEL_12:
    v14 = SSParser::parse_expression(v5, v9, (unsigned int)v6);
    if ( v14 )
      APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase>>::append(
        (APCompactArray<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *)&v8->i_statements.i_count,
        (SSExpressionBase *)&v14->vfptr);
    return v9->i_result == 0;
  }
  v15 = v9->i_end_pos;
  if ( v10 && !SSParser::ensure_exec_time(v5, v10, v9, v6) )
  {
    v9->i_start_pos = v4;
    v9->i_end_pos = v15;
  }
  return v9->i_result == 0;
}

// File Line: 12848
// RVA: 0x13E8D0
char __fastcall SSParser::typecheck_parameters(SSParser *this, SSParser::Args *args, SSParameters *params_p, bool check_result)
{
  SSParameters *v4; // rdi
  SSParser::Args *v5; // r14
  SSParser *v6; // rsi
  char result; // al
  SSClass *v8; // rcx
  SSClassDescBase *v9; // rbx
  SSClassDescBase *v10; // rcx
  __int64 v11; // rax
  ASymbol **v12; // rdi
  unsigned __int64 v13; // r15
  SSTypeContext *v14; // r12
  ASymbol *v15; // rsi
  SSClass *v16; // rax
  SSClass *v17; // rcx
  SSClass *v18; // rbx
  __int64 v19; // rcx
  __int64 v20; // rax
  __int64 v21; // rax

  v4 = params_p;
  v5 = args;
  v6 = this;
  if ( !(this->i_flags.i_flagset & 1) )
  {
    args->i_result = 0;
    return 1;
  }
  if ( check_result )
  {
    v8 = (SSClass *)params_p->i_result_type_p.i_obj_p;
    if ( v8 == SSBrain::c_auto_class_p )
    {
      v9 = args->i_type_p;
      if ( v8 != (SSClass *)v9 )
      {
        if ( v9 )
          (*(void (__fastcall **)(SSClassDescBase *))v9->vfptr->gap8)(args->i_type_p);
        v10 = v4->i_result_type_p.i_obj_p;
        if ( v10 )
          (*(void (**)(void))&v10->vfptr->gap8[8])();
        v4->i_result_type_p.i_obj_p = v9;
      }
    }
    else
    {
      if ( v8 )
        v20 = (__int64)v8->vfptr->as_finalized_generic(
                         (SSClassDescBase *)&v8->vfptr,
                         (SSClassDescBase *)&v6->i_context.i_obj_scope_p->vfptr);
      else
        v20 = 0i64;
      result = v5->i_type_p->vfptr->is_class_type(v5->i_type_p, (SSClassDescBase *)v20);
      if ( !result )
      {
        v5->i_result = 124;
        return result;
      }
    }
  }
  v5->i_result = 0;
  v11 = v4->i_return_params.i_count;
  if ( !(_DWORD)v11
    || (v12 = (ASymbol **)v4->i_return_params.i_array_p, v13 = (unsigned __int64)&v12[v11], (unsigned __int64)v12 >= v13) )
  {
LABEL_32:
    v5->i_result = 0;
    return 1;
  }
  v14 = &v6->i_context;
  while ( 1 )
  {
    v15 = *v12;
    v16 = (SSClass *)SSTypeContext::get_variable_type(v14, *v12, 0);
    v17 = *(SSClass **)&v15[2].i_uid;
    v18 = v16;
    if ( v17 != SSBrain::c_auto_class_p )
      break;
    if ( v16 == SSBrain::c_none_class_p )
      goto LABEL_34;
    if ( v17 != v16 )
    {
      if ( v16 )
        (*(void (__fastcall **)(SSClass *))v16->vfptr->gap8)(v16);
      v19 = *(_QWORD *)&v15[2].i_uid;
      if ( v19 )
        (*(void (**)(void))(*(_QWORD *)v19 + 16i64))();
      *(_QWORD *)&v15[2].i_uid = v18;
    }
LABEL_31:
    ++v12;
    if ( (unsigned __int64)v12 >= v13 )
      goto LABEL_32;
  }
  if ( v17 )
    v21 = (__int64)v17->vfptr->as_finalized_generic(
                     (SSClassDescBase *)&v17->vfptr,
                     (SSClassDescBase *)&v14->i_obj_scope_p->vfptr);
  else
    v21 = 0i64;
  if ( v18->vfptr->is_class_type((SSClassDescBase *)&v18->vfptr, (SSClassDescBase *)v21) )
    goto LABEL_31;
LABEL_34:
  v5->i_result = 125;
  return 0;
}

// File Line: 13022
// RVA: 0x13EC50
signed __int64 __fastcall SSParser::validate_bind_type(SSParser *this, SSIdentifier *identifier_p, SSClassDescBase *old_type_p, SSClassDescBase *new_type_p)
{
  SSClassDescBase *v4; // rdi
  SSClassDescBase *v5; // rsi
  SSIdentifier *v6; // rbx
  SSParser *v7; // rbp

  v4 = new_type_p;
  v5 = old_type_p;
  v6 = identifier_p;
  v7 = this;
  if ( this->i_flags.i_flagset & 1 && new_type_p != old_type_p )
  {
    if ( identifier_p->vfptr->get_type((SSExpressionBase *)identifier_p) != 1 && !v4->vfptr->is_class_type(v4, v5) )
      return 137i64;
    if ( ((unsigned __int8 (__fastcall *)(SSIdentifier *))v6->vfptr[1].__vecDelDtor)(v6) )
      SSTypeContext::change_variable_type(&v7->i_context, &v6->i_ident_name, v4);
  }
  return 0i64;
}

// File Line: 13070
// RVA: 0x1180C0
SSMethodBase *__fastcall SSParser::get_method_inherited(SSParser *this, SSClassDescBase *class_p, ASymbol *method_name)
{
  ASymbol *v3; // rdi
  SSClassUnion *v4; // rbx

  v3 = method_name;
  v4 = (SSClassUnion *)class_p;
  if ( (this->i_flags.i_flagset >> 1) & 1 && method_name->i_uid == ASymbol_String.i_uid )
  {
    if ( class_p->vfptr->get_class_type(class_p) == 4 )
    {
      if ( SSClassUnion::is_class_maybe(v4, (SSClassDescBase *)&SSBrain::c_symbol_class_p->vfptr) )
        return 0i64;
    }
    else if ( v4->vfptr->is_class_type(
                (SSClassDescBase *)&v4->vfptr,
                (SSClassDescBase *)&SSBrain::c_symbol_class_p->vfptr) )
    {
      return 0i64;
    }
  }
  return (SSMethodBase *)v4->vfptr->get_method_inherited((SSClassDescBase *)&v4->vfptr, v3);
}

