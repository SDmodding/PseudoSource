// File Line: 43
// RVA: 0x106E50
void __fastcall SSCode::~SSCode(SSCode *this)
{
  APCompactArrayFree<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *p_i_statements; // rbx

  this->vfptr = (SSExpressionBaseVtbl *)&SSCode::`vftable;
  p_i_statements = &this->i_statements;
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&this->i_statements);
  AMemory::c_free_func(p_i_statements->i_array_p);
  AMemory::c_free_func(this->i_temp_vars.i_array_p);
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
}

// File Line: 65
// RVA: 0x1110A0
void __fastcall SSCode::assign_binary(SSCode *this, unsigned int **binary_pp)
{
  unsigned int v4; // esi
  AVCompactSortedLogical<ASymbol,ASymbol> *p_i_temp_vars; // rbx
  ASymbol *v6; // rax
  __int64 v7; // r14
  __int64 i_count; // r15
  SSExpressionBase **i_array_p; // rbx
  SSExpressionBase **i; // rsi
  SSExpressionBase **v11; // rcx
  SSExpressionBase **v12; // rbx
  SSExpressionBase **j; // rsi
  eSSExprType v14; // ecx
  unsigned int *v15; // rax
  SSExpressionBase *v16; // rax
  ASymbol result; // [rsp+60h] [rbp+8h] BYREF
  AVCompactSortedLogical<ASymbol,ASymbol> *v18; // [rsp+68h] [rbp+10h]
  ASymbol *v19; // [rsp+70h] [rbp+18h]

  v4 = *(*binary_pp)++;
  p_i_temp_vars = &this->i_temp_vars;
  AVCompactArrayBase<ASymbol>::empty_ensure_count_undef(&this->i_temp_vars, v4);
  if ( v4 )
  {
    v18 = p_i_temp_vars;
    do
    {
      v6 = ASymbol::create_from_binary(&result, (const void **)binary_pp);
      v19 = &p_i_temp_vars->i_array_p[p_i_temp_vars->i_count];
      if ( v19 )
        v19->i_uid = v6->i_uid;
      ++p_i_temp_vars->i_count;
      --v4;
    }
    while ( v4 );
  }
  v7 = *(*binary_pp)++;
  i_count = this->i_statements.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = this->i_statements.i_array_p;
    for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
    {
      if ( *i_array_p )
        (*i_array_p)->vfptr->__vecDelDtor(*i_array_p, 1u);
    }
  }
  if ( (_DWORD)i_count != (_DWORD)v7 )
  {
    this->i_statements.i_count = v7;
    v11 = this->i_statements.i_array_p;
    if ( v11 )
      AMemory::c_free_func(v11);
    this->i_statements.i_array_p = APArrayBase<SSExpressionBase>::alloc_array(v7);
  }
  v12 = this->i_statements.i_array_p;
  for ( j = &v12[v7]; v12 < j; ++v12 )
  {
    v14 = *(unsigned __int8 *)*binary_pp;
    v15 = (unsigned int *)((char *)*binary_pp + 1);
    *binary_pp = v15;
    if ( v14 )
    {
      *binary_pp = (unsigned int *)((char *)v15 + 2);
      v16 = SSExpressionBase::from_binary_new(v14, (const void **)binary_pp);
    }
    else
    {
      v16 = 0i64;
    }
    *v12 = v16;
  }
}

// File Line: 202
// RVA: 0x1154D0
SSCode *__fastcall SSCode::find_expr_last_no_side_effect(SSCode *this)
{
  unsigned int i_count; // eax
  SSExpressionBase *v2; // r8

  i_count = this->i_statements.i_count;
  if ( i_count && (v2 = this->i_statements.i_array_p[i_count - 1]) != 0i64 )
    return (SSCode *)v2->vfptr->find_expr_last_no_side_effect(v2);
  else
    return this;
}

// File Line: 221
// RVA: 0x119E90
signed __int64 __fastcall SSCode::get_side_effect(SSCode *this)
{
  __int64 i_count; // rax
  unsigned int v2; // edi
  SSExpressionBase **i_array_p; // rbx
  SSExpressionBase **i; // rsi
  eSSSideEffect v5; // eax

  i_count = this->i_statements.i_count;
  v2 = 0;
  if ( (_DWORD)i_count )
  {
    i_array_p = this->i_statements.i_array_p;
    for ( i = &i_array_p[i_count]; i_array_p < i; ++i_array_p )
    {
      v5 = (*i_array_p)->vfptr->get_side_effect(*i_array_p);
      if ( v5 == SSSideEffect_sub )
      {
        v2 = 1;
      }
      else if ( v5 == SSSideEffect_present )
      {
        return 2i64;
      }
    }
  }
  return v2;
}

// File Line: 431
// RVA: 0x11A000
__int64 __fastcall Scaleform::Render::DICommand_GetPixel32::GetType(hkpMoppDefaultAssembler *this)
{
  return 13i64;
}

// File Line: 449
// RVA: 0x11E260
char __fastcall SSCode::invoke_iterate(SSCode *this, SSInvokedExpression *iexpr_p, SSInstance **result_pp)
{
  unsigned int i_index; // eax
  SSExpressionBase **i_array_p; // r14
  bool v7; // r15
  unsigned int v8; // edi
  __int64 v9; // rcx
  SSObjectBase *i_obj_p; // rdx
  SSExpressionBase *v12; // rcx
  SSObjectBase *v13; // rdx
  __int64 v14; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v16; // rcx
  SSInvokedContextBase *v18; // rcx
  SSInstance *v19; // r8
  SSInvokedBase *v20; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // r8
  AListNode<SSInvokedBase,SSInvokedBase> *v22; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v23; // rax

  i_index = iexpr_p->i_index;
  i_array_p = this->i_statements.i_array_p;
  v7 = i_index == 0;
  v8 = this->i_statements.i_count - 1;
  v9 = 0i64;
  if ( i_index < v8 )
  {
    do
    {
      i_obj_p = iexpr_p->i_scope_p.i_obj_p;
      if ( !i_obj_p )
        break;
      if ( iexpr_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
        break;
      v12 = i_array_p[iexpr_p->i_index];
      v9 = (__int64)v12->vfptr->invoke(v12, i_obj_p, iexpr_p, 0i64);
      if ( v9 )
        break;
      ++iexpr_p->i_index;
    }
    while ( iexpr_p->i_index < v8 );
  }
  v13 = iexpr_p->i_scope_p.i_obj_p;
  if ( v13 )
  {
    if ( iexpr_p->i_scope_p.i_ptr_id == v13->i_ptr_id )
    {
      v14 = iexpr_p->i_index;
      if ( (_DWORD)v14 == v8 )
        v9 = (__int64)i_array_p[v14]->vfptr->invoke(i_array_p[v14], v13, iexpr_p, result_pp);
    }
  }
  if ( v9 )
  {
    i_prev_p = iexpr_p->i_calls.i_sentinel.i_prev_p;
    v16 = (AListNode<SSInvokedBase,SSInvokedBase> *)(v9 + 16);
    iexpr_p->i_calls.i_sentinel.i_prev_p = v16;
    i_prev_p->i_next_p = v16;
    v16->i_prev_p = i_prev_p;
    v16->i_next_p = &iexpr_p->i_calls.i_sentinel;
    ++iexpr_p->i_pending_count;
    return 0;
  }
  else
  {
    v18 = (SSInvokedContextBase *)iexpr_p->i_scope_p.i_obj_p;
    if ( v18 && iexpr_p->i_scope_p.i_ptr_id == v18->i_ptr_id )
    {
      if ( result_pp )
        v19 = *result_pp;
      else
        v19 = 0i64;
      SSInvokedContextBase::data_remove_vars(v18, &this->i_temp_vars, v19);
    }
    v20 = iexpr_p->i_caller_p.i_obj_p;
    if ( !v20 || iexpr_p->i_caller_p.i_ptr_id != v20->i_ptr_id )
      v20 = 0i64;
    if ( !v7 && v20 && v20->i_pending_count )
    {
      i_next_p = iexpr_p->i_next_p;
      v22 = &iexpr_p->AListNode<SSInvokedBase,SSInvokedBase>;
      if ( i_next_p != &iexpr_p->AListNode<SSInvokedBase,SSInvokedBase> )
      {
        v23 = iexpr_p->i_prev_p;
        i_next_p->i_prev_p = v23;
        v23->i_next_p = i_next_p;
        iexpr_p->i_prev_p = &iexpr_p->AListNode<SSInvokedBase,SSInvokedBase>;
        v22->i_next_p = v22;
      }
      LOBYTE(v22) = 1;
      v20->vfptr[1].get_data_by_name(v20, (ASymbol *)v22);
    }
    SSInvokedExpression::pool_delete(iexpr_p);
    return 1;
  }
}

// File Line: 548
// RVA: 0x11CAD0
SSInvokedExpression *__fastcall SSCode::invoke(
        SSCode *this,
        SSInvokedContextBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInvokedExpression *v9; // rbx

  if ( this->i_statements.i_count )
  {
    SSInvokedContextBase::data_append_vars(scope_p, &this->i_temp_vars);
    v9 = SSInvokedExpression::pool_new(this, caller_p, scope_p);
    if ( this->vfptr->invoke_iterate(this, v9, result_pp) )
      return 0i64;
    return v9;
  }
  else
  {
    if ( result_pp )
      *result_pp = SSBrain::c_nil_p;
    return 0i64;
  }
}

// File Line: 597
// RVA: 0x11E190
void __fastcall SSCode::invoke_exit(SSCode *this, SSInvokedExpression *iexpr_p, SSInvokedExpression *sub_exit_p)
{
  iexpr_p->i_index = this->i_statements.i_count;
}

// File Line: 618
// RVA: 0x11EEA0
char __fastcall SSCode::is_immediate(SSCode *this, unsigned int *durational_idx_p)
{
  SSExpressionBase **i_array_p; // rbx
  SSExpressionBase **v4; // rdi

  i_array_p = this->i_statements.i_array_p;
  v4 = &i_array_p[this->i_statements.i_count];
  if ( i_array_p >= v4 )
    return 1;
  while ( (*i_array_p)->vfptr->is_immediate(*i_array_p, durational_idx_p) )
  {
    if ( ++i_array_p >= v4 )
      return 1;
  }
  return 0;
}

// File Line: 642
// RVA: 0x13D700
void __fastcall SSCode::track_memory(SSCode *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase **i_array_p; // rbx
  SSExpressionBase **v3; // rdi
  unsigned int i; // r14d

  i_array_p = this->i_statements.i_array_p;
  v3 = &i_array_p[this->i_statements.i_count];
  for ( i = 4 * this->i_temp_vars.i_count; i_array_p < v3; ++i_array_p )
  {
    if ( *i_array_p )
      (*i_array_p)->vfptr->track_memory(*i_array_p, mem_stats_p);
  }
  AMemoryStats::track_memory(
    mem_stats_p,
    "SSCode",
    0x28u,
    8u,
    i + 8 * this->i_statements.i_count,
    i + 8 * this->i_statements.i_count,
    1u);
}

// File Line: 673
// RVA: 0x104BE0
void __fastcall SSConcurrentSync::SSConcurrentSync(SSConcurrentSync *this, const void **binary_pp)
{
  __int64 v4; // rdi
  SSExpressionBase **i_array_p; // rbx
  SSExpressionBase **i; // rdi
  eSSExprType v7; // ecx
  char *v8; // rax
  SSExpressionBase *v9; // rax

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSConcurrentSync::`vftable;
  this->i_exprs.i_count = 0;
  this->i_exprs.i_array_p = 0i64;
  v4 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  APCompactArrayBase<SSExpressionBase>::set_size_free(&this->i_exprs, v4);
  i_array_p = this->i_exprs.i_array_p;
  for ( i = &i_array_p[v4]; i_array_p < i; ++i_array_p )
  {
    v7 = *(unsigned __int8 *)*binary_pp;
    v8 = (char *)*binary_pp + 1;
    *binary_pp = v8;
    if ( v7 )
    {
      *binary_pp = v8 + 2;
      v9 = SSExpressionBase::from_binary_new(v7, binary_pp);
    }
    else
    {
      v9 = 0i64;
    }
    *i_array_p = v9;
  }
}

// File Line: 913
// RVA: 0x11CDB0
SSInvokedExpression *__fastcall SSConcurrentSync::invoke(
        SSConcurrentSync *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInvokedExpression *v7; // rax
  unsigned int i_count; // esi
  SSExpressionBase **i_array_p; // rdi
  SSInvokedExpression *i; // rbx
  SSExpressionBase *v11; // rcx
  __int64 v12; // rax
  AList<SSInvokedBase,SSInvokedBase> **v13; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax

  v7 = SSInvokedExpression::pool_new(this, caller_p, scope_p);
  i_count = this->i_exprs.i_count;
  i_array_p = this->i_exprs.i_array_p;
  for ( i = v7; i->i_index < i_count; ++i->i_index )
  {
    v11 = i_array_p[i->i_index];
    v12 = (__int64)v11->vfptr->invoke(v11, scope_p, i, 0i64);
    if ( v12 )
    {
      v13 = (AList<SSInvokedBase,SSInvokedBase> **)(v12 + 16);
      i_prev_p = i->i_calls.i_sentinel.i_prev_p;
      i->i_calls.i_sentinel.i_prev_p = (AListNode<SSInvokedBase,SSInvokedBase> *)v13;
      i_prev_p->i_next_p = (AListNode<SSInvokedBase,SSInvokedBase> *)v13;
      v13[1] = (AList<SSInvokedBase,SSInvokedBase> *)i_prev_p;
      *v13 = &i->i_calls;
      ++i->i_pending_count;
    }
  }
  if ( result_pp )
    *result_pp = SSBrain::c_nil_p;
  if ( i->i_pending_count )
    return i;
  SSInvokedExpression::pool_delete(i);
  return 0i64;
}

// File Line: 994
// RVA: 0x11E1B0
void __fastcall SSConcurrentSync::invoke_exit(
        SSConcurrentSync *this,
        SSInvokedExpression *iexpr_p,
        SSInvokedExpression *sub_exit_p)
{
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v5; // rbx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v7; // rax

  iexpr_p->i_index = this->i_exprs.i_count;
  if ( sub_exit_p )
  {
    i_next_p = sub_exit_p->i_next_p;
    v5 = &sub_exit_p->AListNode<SSInvokedBase,SSInvokedBase>;
    if ( i_next_p == &sub_exit_p->AListNode<SSInvokedBase,SSInvokedBase> )
    {
      SSInvokedBase::abort_subcalls(iexpr_p, SSNotify_ignore);
    }
    else
    {
      i_prev_p = sub_exit_p->i_prev_p;
      i_next_p->i_prev_p = i_prev_p;
      i_prev_p->i_next_p = i_next_p;
      sub_exit_p->i_prev_p = &sub_exit_p->AListNode<SSInvokedBase,SSInvokedBase>;
      v5->i_next_p = v5;
      SSInvokedBase::abort_subcalls(iexpr_p, SSNotify_ignore);
      v7 = iexpr_p->i_calls.i_sentinel.i_prev_p;
      iexpr_p->i_calls.i_sentinel.i_prev_p = v5;
      v7->i_next_p = v5;
      v5->i_prev_p = v7;
      v5->i_next_p = &iexpr_p->i_calls.i_sentinel;
    }
  }
  else
  {
    SSInvokedBase::abort_subcalls(iexpr_p, SSNotify_success);
  }
}

// File Line: 1026
// RVA: 0x13D890
void __fastcall SSConcurrentSync::track_memory(SSConcurrentSync *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase **i_array_p; // rbx
  SSExpressionBase **i; // rdi

  i_array_p = this->i_exprs.i_array_p;
  for ( i = &i_array_p[this->i_exprs.i_count]; i_array_p < i; ++i_array_p )
  {
    if ( *i_array_p )
      (*i_array_p)->vfptr->track_memory(*i_array_p, mem_stats_p);
  }
  AMemoryStats::track_memory(
    mem_stats_p,
    "SSConcurrentSync",
    0x18u,
    8u,
    8 * this->i_exprs.i_count,
    8 * this->i_exprs.i_count,
    1u);
}

// File Line: 1054
// RVA: 0x104B30
void __fastcall SSConcurrentRace::SSConcurrentRace(SSConcurrentRace *this, const void **binary_pp)
{
  __int64 v4; // rdi
  SSExpressionBase **i_array_p; // rbx
  SSExpressionBase **i; // rdi
  eSSExprType v7; // ecx
  char *v8; // rax
  SSExpressionBase *v9; // rax

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSConcurrentRace::`vftable;
  this->i_exprs.i_count = 0;
  this->i_exprs.i_array_p = 0i64;
  v4 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  APCompactArrayBase<SSExpressionBase>::set_size_free(&this->i_exprs, v4);
  i_array_p = this->i_exprs.i_array_p;
  for ( i = &i_array_p[v4]; i_array_p < i; ++i_array_p )
  {
    v7 = *(unsigned __int8 *)*binary_pp;
    v8 = (char *)*binary_pp + 1;
    *binary_pp = v8;
    if ( v7 )
    {
      *binary_pp = v8 + 2;
      v9 = SSExpressionBase::from_binary_new(v7, binary_pp);
    }
    else
    {
      v9 = 0i64;
    }
    *i_array_p = v9;
  }
}

// File Line: 1294
// RVA: 0x11CC00
SSInvokedExpression *__fastcall SSConcurrentRace::invoke(
        SSConcurrentRace *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSExpressionBase **i_array_p; // rdi
  SSExpressionBase **v6; // rsi
  char v8; // r14
  SSInvokedExpression *v9; // rbx
  __int64 v10; // rax
  AList<SSInvokedBase,SSInvokedBase> **v11; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  unsigned int i_ptr_id; // eax
  int i_pending_count; // esi
  AList<SSInvokedBase,SSInvokedBase> *i; // rdi
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v17; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v18; // rax
  unsigned int v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  AListNode<SSInvokedBase,SSInvokedBase> *v22; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v23; // rax
  AObjReusePool<SSInvokedExpression> *pool; // rax
  AObjBlock<SSInvokedExpression> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v27; // cf
  APArray<SSInvokedExpression,SSInvokedExpression,ACompareAddress<SSInvokedExpression> > *p_i_exp_pool; // rcx
  unsigned __int64 v30; // rax

  i_array_p = this->i_exprs.i_array_p;
  v6 = &i_array_p[this->i_exprs.i_count];
  v8 = 0;
  v9 = SSInvokedExpression::pool_new(this, caller_p, scope_p);
  if ( i_array_p < v6 )
  {
    while ( 1 )
    {
      v10 = (__int64)(*i_array_p)->vfptr->invoke(*i_array_p, scope_p, v9, 0i64);
      if ( !v10 )
        break;
      v11 = (AList<SSInvokedBase,SSInvokedBase> **)(v10 + 16);
      i_prev_p = v9->i_calls.i_sentinel.i_prev_p;
      v9->i_calls.i_sentinel.i_prev_p = (AListNode<SSInvokedBase,SSInvokedBase> *)v11;
      i_prev_p->i_next_p = (AListNode<SSInvokedBase,SSInvokedBase> *)v11;
      ++i_array_p;
      v11[1] = (AList<SSInvokedBase,SSInvokedBase> *)i_prev_p;
      *v11 = &v9->i_calls;
      ++v9->i_pending_count;
      if ( i_array_p >= v6 )
        goto LABEL_6;
    }
    v8 = 1;
  }
LABEL_6:
  if ( result_pp )
    *result_pp = SSBrain::c_nil_p;
  if ( v8 )
  {
    i_ptr_id = v9->i_ptr_id;
    if ( i_ptr_id && i_ptr_id <= SSObjectBase::c_ptr_id_prev )
    {
      i_pending_count = v9->i_pending_count;
      for ( i = &v9->i_calls; (AList<SSInvokedBase,SSInvokedBase> *)i->i_sentinel.i_next_p != i; --i_pending_count )
      {
        i_next_p = i->i_sentinel.i_next_p;
        v17 = i->i_sentinel.i_next_p->i_next_p;
        v18 = i->i_sentinel.i_next_p->i_prev_p;
        v17->i_prev_p = v18;
        v18->i_next_p = v17;
        i_next_p->i_prev_p = i_next_p;
        i_next_p->i_next_p = i_next_p;
        v19 = (unsigned int)i_next_p[-1].i_prev_p;
        if ( v19 && v19 <= SSObjectBase::c_ptr_id_prev )
          ((void (__fastcall *)(AListNode<SSInvokedBase,SSInvokedBase> **, _QWORD, __int64))i_next_p[-1].i_next_p[5].i_prev_p)(
            &i_next_p[-1].i_next_p,
            0i64,
            1i64);
      }
      v20 = 0;
      if ( i_pending_count > 0 )
        v20 = i_pending_count;
      v9->i_pending_count = v20;
    }
    v21 = v9->i_ptr_id;
    if ( v21 && v21 <= SSObjectBase::c_ptr_id_prev )
    {
      v22 = v9->i_next_p;
      v23 = v9->i_prev_p;
      v22->i_prev_p = v23;
      v23->i_next_p = v22;
      v9->i_prev_p = &v9->AListNode<SSInvokedBase,SSInvokedBase>;
      v9->i_next_p = &v9->AListNode<SSInvokedBase,SSInvokedBase>;
      v9->i_ptr_id = 0;
      pool = SSInvokedExpression::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v9 < i_objects_a
        || (v27 = (unsigned __int64)v9 < i_objects_a + 112i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v27) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<SSInvokedExpression,SSInvokedExpression,ACompareAddress<SSInvokedExpression>>::append(p_i_exp_pool, v9);
    }
    return 0i64;
  }
  else
  {
    v30 = v9->i_pending_count;
    v9->i_pending_count = 1;
    v9->i_data = v30;
    return v9;
  }
}
  {
    v30 = v9->i_pending_count;
    v9->i_pending_coun

// File Line: 1359
// RVA: 0x11E1A0
void __fastcall SSConcurrentRace::invoke_exit(
        SSConcurrentRace *this,
        SSInvokedExpression *iexpr_p,
        SSInvokedExpression *sub_exit_p)
{
  if ( !sub_exit_p )
    ((void (__fastcall *)(SSConcurrentRace *, SSInvokedExpression *))this->vfptr->invoke_iterate)(this, iexpr_p);
}

// File Line: 1380
// RVA: 0x11E5D0
char __fastcall SSInvokeRace::invoke_iterate(SSInvokeRace *this, SSInvokedExpression *iexpr_p, SSInstance **result_pp)
{
  int i_data; // eax

  i_data = iexpr_p->i_data;
  if ( i_data )
  {
    iexpr_p->i_data = 0i64;
    iexpr_p->i_pending_count += i_data - 1;
    SSInvokedBase::abort_subcalls(iexpr_p, SSNotify_success);
    SSInvokedExpression::pool_delete(iexpr_p);
  }
  return 1;
}

// File Line: 1434
// RVA: 0x13D800
void __fastcall SSConcurrentRace::track_memory(SSConcurrentRace *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase **i_array_p; // rbx
  SSExpressionBase **i; // rdi

  i_array_p = this->i_exprs.i_array_p;
  for ( i = &i_array_p[this->i_exprs.i_count]; i_array_p < i; ++i_array_p )
  {
    if ( *i_array_p )
      (*i_array_p)->vfptr->track_memory(*i_array_p, mem_stats_p);
  }
  AMemoryStats::track_memory(
    mem_stats_p,
    "SSConcurrentRace",
    0x18u,
    8u,
    8 * this->i_exprs.i_count,
    8 * this->i_exprs.i_count,
    1u);
}

// File Line: 1607
// RVA: 0x11CB60
SSInvokedBase *__fastcall SSConcurrentBranch::invoke(
        SSConcurrentBranch *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInvokedExpression *v7; // rsi
  SSInvokedBase *v8; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v9; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax

  v7 = SSInvokedExpression::pool_new(this, caller_p, scope_p);
  v8 = this->i_statement_p->vfptr->invoke(this->i_statement_p, scope_p, v7, 0i64);
  if ( v8 )
  {
    v9 = &v8->AListNode<SSInvokedBase,SSInvokedBase>;
    i_prev_p = v7->i_calls.i_sentinel.i_prev_p;
    v7->i_calls.i_sentinel.i_prev_p = v9;
    i_prev_p->i_next_p = v9;
    v9->i_prev_p = i_prev_p;
    v9->i_next_p = &v7->i_calls.i_sentinel;
    ++v7->i_pending_count;
  }
  else
  {
    SSInvokedExpression::pool_delete(v7);
  }
  if ( result_pp )
    *result_pp = SSBrain::c_nil_p;
  return 0i64;
}

// File Line: 1653
// RVA: 0x11E3C0
char __fastcall SSConcurrentBranch::invoke_iterate(
        SSConcurrentBranch *this,
        SSInvokedExpression *iexpr_p,
        SSInstance **result_pp)
{
  SSInvokedExpression::pool_delete(iexpr_p);
  return 1;
}

// File Line: 1666
// RVA: 0x13D7A0
void __fastcall SSConcurrentBranch::track_memory(SSConcurrentBranch *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats::track_memory(mem_stats_p, "SSConcurrentBranch", 0x10u, 8u, 0, 0, 1u);
  this->i_statement_p->vfptr->track_memory(this->i_statement_p, mem_stats_p);
}

// File Line: 1749
// RVA: 0x115570
SSExpressionBase *__fastcall UFG::NavAvoidanceManager::SetLocalModuleFor(SSDivert *this)
{
  return this->i_statement_p->vfptr->find_expr_last_no_side_effect(this->i_statement_p);
}

// File Line: 1877
// RVA: 0x11D090
SSInvokedExpression *__fastcall SSDivert::invoke(
        SSDivert *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInvokedExpression *v7; // rbp
  SSInvokedBase *v8; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v9; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax

  v7 = SSInvokedExpression::pool_new(this, caller_p, scope_p);
  v8 = this->i_statement_p->vfptr->invoke(this->i_statement_p, scope_p, v7, result_pp);
  if ( v8 )
  {
    v9 = &v8->AListNode<SSInvokedBase,SSInvokedBase>;
    i_prev_p = v7->i_calls.i_sentinel.i_prev_p;
    v7->i_calls.i_sentinel.i_prev_p = v9;
    i_prev_p->i_next_p = v9;
    v9->i_prev_p = i_prev_p;
    v9->i_next_p = &v7->i_calls.i_sentinel;
    ++v7->i_pending_count;
    return v7;
  }
  else
  {
    SSInvokedExpression::pool_delete(v7);
    return 0i64;
  }
}

// File Line: 1915
// RVA: 0x11EF80
__int64 __fastcall SSDivert::is_immediate(SSDivert *this, unsigned int *durational_idx_p)
{
  return ((__int64 (__fastcall *)(SSExpressionBase *, unsigned int *))this->i_statement_p->vfptr->is_immediate)(
           this->i_statement_p,
           durational_idx_p);
}

// File Line: 1925
// RVA: 0x13DCB0
void __fastcall SSDivert::track_memory(SSDivert *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats::track_memory(mem_stats_p, "SSDivert", 0x10u, 8u, 0, 0, 1u);
  this->i_statement_p->vfptr->track_memory(this->i_statement_p, mem_stats_p);
}

// File Line: 2163
// RVA: 0x11C780
SSInvokedBase *__fastcall SSBind::invoke(
        SSBind *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSExpressionBase *i_expr_p; // rcx
  __int64 v9; // rbp
  SSInstance *v10; // rcx
  bool v13; // [rsp+20h] [rbp-28h]
  SSInstance *v14; // [rsp+50h] [rbp+8h] BYREF

  i_expr_p = this->i_expr_p;
  v14 = SSBrain::c_nil_p;
  v13 = result_pp != 0i64;
  v9 = (__int64)i_expr_p->vfptr->invoke(i_expr_p, scope_p, caller_p, &v14);
  (*((void (__fastcall **)(SSIdentifier *, SSInstance *, SSObjectBase *, SSInvokedBase *, bool))&this->i_ident_p->vfptr[1].__vecDelDtor
   + 1))(
    this->i_ident_p,
    v14,
    scope_p,
    caller_p,
    v13);
  v10 = v14;
  if ( result_pp )
  {
    *result_pp = v14;
  }
  else if ( v14->i_ref_count-- == 1 )
  {
    v10->i_ref_count = 0x80000000;
    v10->vfptr[1].get_scope_context(v10);
  }
  return (SSInvokedBase *)v9;
}

// File Line: 2205
// RVA: 0x11F010
__int64 __fastcall Scaleform::DelegatedFile::Write(SSLoop *this, unsigned int *durational_idx_p)
{
  return ((__int64 (__fastcall *)(SSExpressionBase *, unsigned int *))this->i_expr_p->vfptr->is_immediate)(
           this->i_expr_p,
           durational_idx_p);
}

// File Line: 2215
// RVA: 0x13D160
void __fastcall SSBind::track_memory(SSBind *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats::track_memory(mem_stats_p, "SSBind", 0x18u, 8u, 0, 0, 1u);
  this->i_ident_p->vfptr->track_memory(this->i_ident_p, mem_stats_p);
  this->i_expr_p->vfptr->track_memory(this->i_expr_p, mem_stats_p);
}

