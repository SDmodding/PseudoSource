// File Line: 43
// RVA: 0x106E50
void __fastcall SSCode::~SSCode(SSCode *this)
{
  SSCode *v1; // rdi
  void **v2; // rbx

  v1 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSCode::`vftable';
  v2 = (void **)&this->i_statements;
  APCompactArrayBase<SSParameterBase>::free_all((APCompactArrayBase<SSParameterBase> *)&this->i_statements);
  AMemory::c_free_func(v2[1]);
  AMemory::c_free_func(v1->i_temp_vars.i_array_p);
  v1->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
}

// File Line: 65
// RVA: 0x1110A0
void __fastcall SSCode::assign_binary(SSCode *this, const void **binary_pp)
{
  const void **v2; // rdi
  SSCode *v3; // rbp
  unsigned int v4; // esi
  AVCompactSortedLogical<ASymbol,ASymbol> *v5; // rbx
  ASymbol *v6; // rax
  __int64 v7; // rdx
  ASymbol *v8; // rcx
  unsigned int *v9; // r8
  __int64 v10; // r14
  __int64 v11; // r15
  SSExpressionBase **v12; // rbx
  unsigned __int64 i; // rsi
  SSExpressionBase **v14; // rcx
  SSExpressionBase **v15; // rbx
  unsigned __int64 j; // rsi
  eSSExprType v17; // ecx
  signed __int64 v18; // rax
  SSExpressionBase *v19; // rax
  ASymbol result; // [rsp+60h] [rbp+8h]
  AVCompactSortedLogical<ASymbol,ASymbol> *v21; // [rsp+68h] [rbp+10h]
  ASymbol *v22; // [rsp+70h] [rbp+18h]

  v2 = binary_pp;
  v3 = this;
  v4 = *(_DWORD *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 4;
  v5 = &this->i_temp_vars;
  AVCompactArrayBase<ASymbol>::empty_ensure_count_undef((AVCompactArrayBase<ASymbol> *)&this->i_temp_vars.i_count, v4);
  if ( v4 )
  {
    v21 = v5;
    do
    {
      v6 = ASymbol::create_from_binary(&result, v2);
      v7 = v5->i_count;
      v8 = v5->i_array_p;
      v9 = &v8[v7].i_uid;
      v22 = &v8[v7];
      if ( v9 )
        *v9 = v6->i_uid;
      ++v5->i_count;
      --v4;
    }
    while ( v4 );
  }
  v10 = *(unsigned int *)*v2;
  *v2 = (char *)*v2 + 4;
  v11 = v3->i_statements.i_count;
  if ( (_DWORD)v11 )
  {
    v12 = v3->i_statements.i_array_p;
    for ( i = (unsigned __int64)&v12[v11]; (unsigned __int64)v12 < i; ++v12 )
    {
      if ( *v12 )
        (*v12)->vfptr->__vecDelDtor(*v12, 1u);
    }
  }
  if ( (_DWORD)v11 != (_DWORD)v10 )
  {
    v3->i_statements.i_count = v10;
    v14 = v3->i_statements.i_array_p;
    if ( v14 )
      AMemory::c_free_func(v14);
    v3->i_statements.i_array_p = APArrayBase<SSExpressionBase>::alloc_array(v10);
  }
  v15 = v3->i_statements.i_array_p;
  for ( j = (unsigned __int64)&v15[v10]; (unsigned __int64)v15 < j; ++v15 )
  {
    v17 = *(unsigned __int8 *)*v2;
    v18 = (signed __int64)*v2 + 1;
    *v2 = (const void *)v18;
    if ( v17 )
    {
      *v2 = (const void *)(v18 + 2);
      v19 = SSExpressionBase::from_binary_new(v17, v2);
    }
    else
    {
      v19 = 0i64;
    }
    *v15 = v19;
  }
}

// File Line: 202
// RVA: 0x1154D0
SSCode *__fastcall SSCode::find_expr_last_no_side_effect(SSCode *this)
{
  unsigned int v1; // eax
  SSExpressionBase *v2; // r8
  SSCode *result; // rax

  v1 = this->i_statements.i_count;
  if ( v1 && (v2 = this->i_statements.i_array_p[v1 - 1]) != 0i64 )
    result = (SSCode *)v2->vfptr->find_expr_last_no_side_effect(v2);
  else
    result = this;
  return result;
}

// File Line: 221
// RVA: 0x119E90
signed __int64 __fastcall SSCode::get_side_effect(SSCode *this)
{
  __int64 v1; // rax
  unsigned int v2; // edi
  SSExpressionBase **v3; // rbx
  unsigned __int64 i; // rsi
  int v5; // eax

  v1 = this->i_statements.i_count;
  v2 = 0;
  if ( (_DWORD)v1 )
  {
    v3 = this->i_statements.i_array_p;
    for ( i = (unsigned __int64)&v3[v1]; (unsigned __int64)v3 < i; ++v3 )
    {
      v5 = ((__int64 (*)(void))(*v3)->vfptr->get_side_effect)();
      if ( v5 == 1 )
      {
        v2 = 1;
      }
      else if ( v5 == 2 )
      {
        return 2i64;
      }
    }
  }
  return v2;
}

// File Line: 431
// RVA: 0x11A000
signed __int64 __fastcall Scaleform::Render::DICommand_GetPixel32::GetType(hkpMoppDefaultAssembler *this)
{
  return 13i64;
}

// File Line: 449
// RVA: 0x11E260
char __fastcall SSCode::invoke_iterate(SSCode *this, SSInvokedExpression *iexpr_p, SSInstance **result_pp)
{
  unsigned int v3; // eax
  SSCode *v4; // rbp
  SSInstance **v5; // rsi
  SSExpressionBase **v6; // r14
  bool v7; // r15
  unsigned int v8; // edi
  __int64 v9; // rcx
  SSInvokedExpression *v10; // rbx
  SSObjectBase *v11; // rdx
  SSExpressionBase *v12; // rcx
  SSObjectBase *v13; // rdx
  __int64 v14; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v15; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v16; // rcx
  char result; // al
  SSInvokedContextBase *v18; // rcx
  SSInstance *v19; // r8
  SSInvokedBase *v20; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v21; // r8
  AListNode<SSInvokedBase,SSInvokedBase> *v22; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v23; // rax

  v3 = iexpr_p->i_index;
  v4 = this;
  v5 = result_pp;
  v6 = this->i_statements.i_array_p;
  v7 = v3 == 0;
  v8 = this->i_statements.i_count - 1;
  v9 = 0i64;
  v10 = iexpr_p;
  if ( v3 < v8 )
  {
    do
    {
      v11 = v10->i_scope_p.i_obj_p;
      if ( !v11 )
        break;
      if ( v10->i_scope_p.i_ptr_id != v11->i_ptr_id )
        break;
      v12 = v6[v10->i_index];
      v9 = (__int64)v12->vfptr->invoke(v12, v11, (SSInvokedBase *)&v10->vfptr, 0i64);
      if ( v9 )
        break;
      ++v10->i_index;
    }
    while ( v10->i_index < v8 );
  }
  v13 = v10->i_scope_p.i_obj_p;
  if ( v13 )
  {
    if ( v10->i_scope_p.i_ptr_id == v13->i_ptr_id )
    {
      v14 = v10->i_index;
      if ( (_DWORD)v14 == v8 )
        v9 = (__int64)v6[v14]->vfptr->invoke(v6[v14], v13, (SSInvokedBase *)&v10->vfptr, v5);
    }
  }
  if ( v9 )
  {
    v15 = v10->i_calls.i_sentinel.i_prev_p;
    v16 = (AListNode<SSInvokedBase,SSInvokedBase> *)(v9 + 16);
    v10->i_calls.i_sentinel.i_prev_p = v16;
    v15->i_next_p = v16;
    v16->i_prev_p = v15;
    v16->i_next_p = &v10->i_calls.i_sentinel;
    ++v10->i_pending_count;
    result = 0;
  }
  else
  {
    v18 = (SSInvokedContextBase *)v10->i_scope_p.i_obj_p;
    if ( v18 && v10->i_scope_p.i_ptr_id == v18->i_ptr_id )
    {
      if ( v5 )
        v19 = *v5;
      else
        v19 = 0i64;
      SSInvokedContextBase::data_remove_vars(v18, (AVCompactArrayBase<ASymbol> *)&v4->i_temp_vars.i_count, v19);
    }
    v20 = v10->i_caller_p.i_obj_p;
    if ( !v20 || v10->i_caller_p.i_ptr_id != v20->i_ptr_id )
      v20 = 0i64;
    if ( !v7 && v20 && v20->i_pending_count )
    {
      v21 = v10->i_next_p;
      v22 = (AListNode<SSInvokedBase,SSInvokedBase> *)&v10->i_next_p;
      if ( v21 != (AListNode<SSInvokedBase,SSInvokedBase> *)&v10->i_next_p )
      {
        v23 = v10->i_prev_p;
        v21->i_prev_p = v23;
        v23->i_next_p = v21;
        v10->i_prev_p = (AListNode<SSInvokedBase,SSInvokedBase> *)&v10->i_next_p;
        v22->i_next_p = v22;
      }
      LOBYTE(v22) = 1;
      v20->vfptr[1].get_data_by_name((SSObjectBase *)&v20->vfptr, (ASymbol *)v22);
    }
    SSInvokedExpression::pool_delete(v10);
    result = 1;
  }
  return result;
}

// File Line: 548
// RVA: 0x11CAD0
SSInvokedExpression *__fastcall SSCode::invoke(SSCode *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInstance **v4; // rdi
  SSInvokedBase *v5; // rbp
  SSObjectBase *v6; // rbx
  SSCode *v7; // rsi
  SSInvokedExpression *result; // rax
  SSInvokedExpression *v9; // rbx

  v4 = result_pp;
  v5 = caller_p;
  v6 = scope_p;
  v7 = this;
  if ( this->i_statements.i_count )
  {
    SSInvokedContextBase::data_append_vars(
      (SSInvokedContextBase *)scope_p,
      (AVCompactArrayBase<ASymbol> *)&this->i_temp_vars.i_count);
    v9 = SSInvokedExpression::pool_new((SSExpressionBase *)&v7->vfptr, v5, v6);
    if ( v7->vfptr->invoke_iterate((SSExpressionBase *)&v7->vfptr, v9, v4) )
      v9 = 0i64;
    result = v9;
  }
  else
  {
    if ( result_pp )
      *result_pp = SSBrain::c_nil_p;
    result = 0i64;
  }
  return result;
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
  SSExpressionBase **v2; // rbx
  unsigned int *v3; // rsi
  unsigned __int64 v4; // rdi

  v2 = this->i_statements.i_array_p;
  v3 = durational_idx_p;
  v4 = (unsigned __int64)&v2[this->i_statements.i_count];
  if ( (unsigned __int64)v2 >= v4 )
    return 1;
  while ( (*v2)->vfptr->is_immediate(*v2, v3) )
  {
    ++v2;
    if ( (unsigned __int64)v2 >= v4 )
      return 1;
  }
  return 0;
}

// File Line: 642
// RVA: 0x13D700
void __fastcall SSCode::track_memory(SSCode *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase **v2; // rbx
  unsigned __int64 v3; // rdi
  unsigned int v4; // er14
  AMemoryStats *v5; // rsi
  SSCode *i; // rbp

  v2 = this->i_statements.i_array_p;
  v3 = (unsigned __int64)&v2[this->i_statements.i_count];
  v4 = 4 * this->i_temp_vars.i_count;
  v5 = mem_stats_p;
  for ( i = this; (unsigned __int64)v2 < v3; ++v2 )
  {
    if ( *v2 )
      (*v2)->vfptr->track_memory(*v2, v5);
  }
  AMemoryStats::track_memory(
    v5,
    "SSCode",
    0x28u,
    8u,
    v4 + 8 * i->i_statements.i_count,
    v4 + 8 * i->i_statements.i_count,
    1u);
}

// File Line: 673
// RVA: 0x104BE0
void __fastcall SSConcurrentSync::SSConcurrentSync(SSConcurrentSync *this, const void **binary_pp)
{
  const void **v2; // rsi
  SSConcurrentSync *v3; // r14
  __int64 v4; // rdi
  SSExpressionBase **v5; // rbx
  unsigned __int64 i; // rdi
  eSSExprType v7; // ecx
  signed __int64 v8; // rax
  SSExpressionBase *v9; // rax
  APCompactArrayFree<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v10; // [rsp+58h] [rbp+10h]

  v2 = binary_pp;
  v3 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSConcurrentSync::`vftable';
  v10 = &this->i_exprs;
  v10->i_count = 0;
  v10->i_array_p = 0i64;
  v4 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  APCompactArrayBase<SSExpressionBase>::set_size_free(
    (APCompactArrayBase<SSExpressionBase> *)&this->i_exprs.i_count,
    v4);
  v5 = v3->i_exprs.i_array_p;
  for ( i = (unsigned __int64)&v5[v4]; (unsigned __int64)v5 < i; ++v5 )
  {
    v7 = *(unsigned __int8 *)*v2;
    v8 = (signed __int64)*v2 + 1;
    *v2 = (const void *)v8;
    if ( v7 )
    {
      *v2 = (const void *)(v8 + 2);
      v9 = SSExpressionBase::from_binary_new(v7, v2);
    }
    else
    {
      v9 = 0i64;
    }
    *v5 = v9;
  }
}

// File Line: 913
// RVA: 0x11CDB0
SSInvokedExpression *__fastcall SSConcurrentSync::invoke(SSConcurrentSync *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSObjectBase *v4; // rbp
  SSInstance **v5; // r14
  SSConcurrentSync *v6; // rdi
  SSInvokedExpression *v7; // rax
  unsigned int v8; // esi
  SSExpressionBase **v9; // rdi
  SSInvokedExpression *i; // rbx
  SSExpressionBase *v11; // rcx
  __int64 v12; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v13; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v14; // rax

  v4 = scope_p;
  v5 = result_pp;
  v6 = this;
  v7 = SSInvokedExpression::pool_new((SSExpressionBase *)&this->vfptr, caller_p, scope_p);
  v8 = v6->i_exprs.i_count;
  v9 = v6->i_exprs.i_array_p;
  for ( i = v7; i->i_index < v8; ++i->i_index )
  {
    v11 = v9[i->i_index];
    v12 = (__int64)v11->vfptr->invoke(v11, v4, (SSInvokedBase *)&i->vfptr, 0i64);
    if ( v12 )
    {
      v13 = (AListNode<SSInvokedBase,SSInvokedBase> *)(v12 + 16);
      v14 = i->i_calls.i_sentinel.i_prev_p;
      i->i_calls.i_sentinel.i_prev_p = v13;
      v14->i_next_p = v13;
      v13->i_prev_p = v14;
      v13->i_next_p = &i->i_calls.i_sentinel;
      ++i->i_pending_count;
    }
  }
  if ( v5 )
    *v5 = SSBrain::c_nil_p;
  if ( i->i_pending_count )
    return i;
  SSInvokedExpression::pool_delete(i);
  return 0i64;
}

// File Line: 994
// RVA: 0x11E1B0
void __fastcall SSConcurrentSync::invoke_exit(SSConcurrentSync *this, SSInvokedExpression *iexpr_p, SSInvokedExpression *sub_exit_p)
{
  SSInvokedExpression *v3; // rdi
  AListNode<SSInvokedBase,SSInvokedBase> *v4; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v5; // rbx
  AListNode<SSInvokedBase,SSInvokedBase> *v6; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v7; // rax

  v3 = iexpr_p;
  iexpr_p->i_index = this->i_exprs.i_count;
  if ( sub_exit_p )
  {
    v4 = sub_exit_p->i_next_p;
    v5 = (AListNode<SSInvokedBase,SSInvokedBase> *)&sub_exit_p->i_next_p;
    if ( v4 == (AListNode<SSInvokedBase,SSInvokedBase> *)&sub_exit_p->i_next_p )
    {
      SSInvokedBase::abort_subcalls((SSInvokedBase *)&iexpr_p->vfptr, 0);
    }
    else
    {
      v6 = sub_exit_p->i_prev_p;
      v4->i_prev_p = v6;
      v6->i_next_p = v4;
      sub_exit_p->i_prev_p = (AListNode<SSInvokedBase,SSInvokedBase> *)&sub_exit_p->i_next_p;
      v5->i_next_p = v5;
      SSInvokedBase::abort_subcalls((SSInvokedBase *)&iexpr_p->vfptr, 0);
      v7 = v3->i_calls.i_sentinel.i_prev_p;
      v3->i_calls.i_sentinel.i_prev_p = v5;
      v7->i_next_p = v5;
      v5->i_prev_p = v7;
      v5->i_next_p = &v3->i_calls.i_sentinel;
    }
  }
  else
  {
    SSInvokedBase::abort_subcalls((SSInvokedBase *)&iexpr_p->vfptr, SSNotify_success);
  }
}

// File Line: 1026
// RVA: 0x13D890
void __fastcall SSConcurrentSync::track_memory(SSConcurrentSync *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase **v2; // rbx
  AMemoryStats *v3; // rsi
  unsigned __int64 v4; // rdi
  SSConcurrentSync *i; // rbp

  v2 = this->i_exprs.i_array_p;
  v3 = mem_stats_p;
  v4 = (unsigned __int64)&v2[this->i_exprs.i_count];
  for ( i = this; (unsigned __int64)v2 < v4; ++v2 )
  {
    if ( *v2 )
      (*v2)->vfptr->track_memory(*v2, v3);
  }
  AMemoryStats::track_memory(v3, "SSConcurrentSync", 0x18u, 8u, 8 * i->i_exprs.i_count, 8 * i->i_exprs.i_count, 1u);
}

// File Line: 1054
// RVA: 0x104B30
void __fastcall SSConcurrentRace::SSConcurrentRace(SSConcurrentRace *this, const void **binary_pp)
{
  const void **v2; // rsi
  SSConcurrentRace *v3; // r14
  __int64 v4; // rdi
  SSExpressionBase **v5; // rbx
  unsigned __int64 i; // rdi
  eSSExprType v7; // ecx
  signed __int64 v8; // rax
  SSExpressionBase *v9; // rax
  APCompactArrayFree<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v10; // [rsp+58h] [rbp+10h]

  v2 = binary_pp;
  v3 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSConcurrentRace::`vftable';
  v10 = &this->i_exprs;
  v10->i_count = 0;
  v10->i_array_p = 0i64;
  v4 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  APCompactArrayBase<SSExpressionBase>::set_size_free(
    (APCompactArrayBase<SSExpressionBase> *)&this->i_exprs.i_count,
    v4);
  v5 = v3->i_exprs.i_array_p;
  for ( i = (unsigned __int64)&v5[v4]; (unsigned __int64)v5 < i; ++v5 )
  {
    v7 = *(unsigned __int8 *)*v2;
    v8 = (signed __int64)*v2 + 1;
    *v2 = (const void *)v8;
    if ( v7 )
    {
      *v2 = (const void *)(v8 + 2);
      v9 = SSExpressionBase::from_binary_new(v7, v2);
    }
    else
    {
      v9 = 0i64;
    }
    *v5 = v9;
  }
}

// File Line: 1294
// RVA: 0x11CC00
SSInvokedExpression *__fastcall SSConcurrentRace::invoke(SSConcurrentRace *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSExpressionBase **v4; // rdi
  SSObjectBase *v5; // rbp
  unsigned __int64 v6; // rsi
  SSInstance **v7; // r15
  char v8; // r14
  SSInvokedExpression *v9; // rbx
  __int64 v10; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v11; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v12; // rax
  unsigned int v13; // eax
  signed int v14; // esi
  AList<SSInvokedBase,SSInvokedBase> *i; // rdi
  AListNode<SSInvokedBase,SSInvokedBase> *v16; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v17; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v18; // rax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  AListNode<SSInvokedBase,SSInvokedBase> *v22; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v23; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v24; // rdx
  AObjReusePool<SSInvokedExpression> *v25; // rax
  AObjBlock<SSInvokedExpression> *v26; // rcx
  unsigned __int64 v27; // rdx
  bool v28; // cf
  APArray<SSInvokedExpression,SSInvokedExpression,ACompareAddress<SSInvokedExpression> > *v29; // rcx
  SSInvokedExpression *result; // rax
  unsigned __int64 v31; // rax

  v4 = this->i_exprs.i_array_p;
  v5 = scope_p;
  v6 = (unsigned __int64)&v4[this->i_exprs.i_count];
  v7 = result_pp;
  v8 = 0;
  v9 = SSInvokedExpression::pool_new((SSExpressionBase *)&this->vfptr, caller_p, scope_p);
  if ( (unsigned __int64)v4 < v6 )
  {
    while ( 1 )
    {
      v10 = (__int64)(*v4)->vfptr->invoke(*v4, v5, (SSInvokedBase *)&v9->vfptr, 0i64);
      if ( !v10 )
        break;
      v11 = (AListNode<SSInvokedBase,SSInvokedBase> *)(v10 + 16);
      v12 = v9->i_calls.i_sentinel.i_prev_p;
      v9->i_calls.i_sentinel.i_prev_p = v11;
      v12->i_next_p = v11;
      ++v4;
      v11->i_prev_p = v12;
      v11->i_next_p = &v9->i_calls.i_sentinel;
      ++v9->i_pending_count;
      if ( (unsigned __int64)v4 >= v6 )
        goto LABEL_6;
    }
    v8 = 1;
  }
LABEL_6:
  if ( v7 )
    *v7 = SSBrain::c_nil_p;
  if ( v8 )
  {
    v13 = v9->i_ptr_id;
    if ( v13 && v13 <= SSObjectBase::c_ptr_id_prev )
    {
      v14 = v9->i_pending_count;
      for ( i = &v9->i_calls; (AList<SSInvokedBase,SSInvokedBase> *)i->i_sentinel.i_next_p != i; --v14 )
      {
        v16 = i->i_sentinel.i_next_p;
        v17 = i->i_sentinel.i_next_p->i_next_p;
        v18 = i->i_sentinel.i_next_p->i_prev_p;
        v17->i_prev_p = v18;
        v18->i_next_p = v17;
        v16->i_prev_p = v16;
        v16->i_next_p = v16;
        v19 = (unsigned int)v16[-1].i_prev_p;
        if ( v19 && v19 <= SSObjectBase::c_ptr_id_prev )
          ((void (__fastcall *)(AListNode<SSInvokedBase,SSInvokedBase> **, _QWORD, signed __int64))v16[-1].i_next_p[5].i_prev_p)(
            &v16[-1].i_next_p,
            0i64,
            1i64);
      }
      v20 = 0;
      if ( v14 > 0 )
        v20 = v14;
      v9->i_pending_count = v20;
    }
    v21 = v9->i_ptr_id;
    if ( v21 && v21 <= SSObjectBase::c_ptr_id_prev )
    {
      v22 = v9->i_next_p;
      v23 = v9->i_prev_p;
      v24 = (AListNode<SSInvokedBase,SSInvokedBase> *)&v9->i_next_p;
      v22->i_prev_p = v23;
      v23->i_next_p = v22;
      v24->i_prev_p = v24;
      v24->i_next_p = v24;
      v9->i_ptr_id = 0;
      v25 = SSInvokedExpression::get_pool();
      v26 = v25->i_block_p;
      v27 = (unsigned __int64)v26->i_objects_a;
      if ( (unsigned __int64)v9 < v27
        || (v28 = (unsigned __int64)v9 < v27 + 112i64 * v26->i_size, v29 = &v25->i_pool, !v28) )
      {
        v29 = &v25->i_exp_pool;
      }
      APArray<SSInvokedExpression,SSInvokedExpression,ACompareAddress<SSInvokedExpression>>::append(v29, v9);
    }
    result = 0i64;
  }
  else
  {
    v31 = v9->i_pending_count;
    v9->i_pending_count = 1;
    v9->i_data = v31;
    result = v9;
  }
  return result;
}

// File Line: 1359
// RVA: 0x11E1A0
void __fastcall SSConcurrentRace::invoke_exit(SSConcurrentRace *this, SSInvokedExpression *iexpr_p, SSInvokedExpression *sub_exit_p)
{
  if ( !sub_exit_p )
    ((void (__fastcall *)(SSConcurrentRace *, SSInvokedExpression *))this->vfptr->invoke_iterate)(this, iexpr_p);
}

// File Line: 1380
// RVA: 0x11E5D0
char __fastcall SSInvokeRace::invoke_iterate(SSInvokeRace *this, SSInvokedExpression *iexpr_p, SSInstance **result_pp)
{
  int v3; // eax
  SSInvokedExpression *v4; // rbx

  v3 = iexpr_p->i_data;
  v4 = iexpr_p;
  if ( v3 )
  {
    iexpr_p->i_data = 0i64;
    iexpr_p->i_pending_count += v3 - 1;
    SSInvokedBase::abort_subcalls((SSInvokedBase *)&iexpr_p->vfptr, SSNotify_success);
    SSInvokedExpression::pool_delete(v4);
  }
  return 1;
}

// File Line: 1434
// RVA: 0x13D800
void __fastcall SSConcurrentRace::track_memory(SSConcurrentRace *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase **v2; // rbx
  AMemoryStats *v3; // rsi
  unsigned __int64 v4; // rdi
  SSConcurrentRace *i; // rbp

  v2 = this->i_exprs.i_array_p;
  v3 = mem_stats_p;
  v4 = (unsigned __int64)&v2[this->i_exprs.i_count];
  for ( i = this; (unsigned __int64)v2 < v4; ++v2 )
  {
    if ( *v2 )
      (*v2)->vfptr->track_memory(*v2, v3);
  }
  AMemoryStats::track_memory(v3, "SSConcurrentRace", 0x18u, 8u, 8 * i->i_exprs.i_count, 8 * i->i_exprs.i_count, 1u);
}

// File Line: 1607
// RVA: 0x11CB60
SSInvokedBase *__fastcall SSConcurrentBranch::invoke(SSConcurrentBranch *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSObjectBase *v4; // rdi
  SSInstance **v5; // r14
  SSConcurrentBranch *v6; // rbx
  SSInvokedExpression *v7; // rax
  SSInvokedExpression *v8; // rsi
  __int64 v9; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v10; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v11; // rax

  v4 = scope_p;
  v5 = result_pp;
  v6 = this;
  v7 = SSInvokedExpression::pool_new((SSExpressionBase *)&this->vfptr, caller_p, scope_p);
  v8 = v7;
  v9 = (__int64)v6->i_statement_p->vfptr->invoke(v6->i_statement_p, v4, (SSInvokedBase *)&v7->vfptr, 0i64);
  if ( v9 )
  {
    v10 = (AListNode<SSInvokedBase,SSInvokedBase> *)(v9 + 16);
    v11 = v8->i_calls.i_sentinel.i_prev_p;
    v8->i_calls.i_sentinel.i_prev_p = v10;
    v11->i_next_p = v10;
    v10->i_prev_p = v11;
    v10->i_next_p = &v8->i_calls.i_sentinel;
    ++v8->i_pending_count;
  }
  else
  {
    SSInvokedExpression::pool_delete(v8);
  }
  if ( v5 )
    *v5 = SSBrain::c_nil_p;
  return 0i64;
}

// File Line: 1653
// RVA: 0x11E3C0
char __fastcall SSConcurrentBranch::invoke_iterate(SSConcurrentBranch *this, SSInvokedExpression *iexpr_p, SSInstance **result_pp)
{
  SSInvokedExpression::pool_delete(iexpr_p);
  return 1;
}

// File Line: 1666
// RVA: 0x13D7A0
void __fastcall SSConcurrentBranch::track_memory(SSConcurrentBranch *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rdi
  SSConcurrentBranch *v3; // rbx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSConcurrentBranch", 0x10u, 8u, 0, 0, 1u);
  v3->i_statement_p->vfptr->track_memory(v3->i_statement_p, v2);
}

// File Line: 1749
// RVA: 0x115570
SSExpressionBase *__fastcall UFG::NavAvoidanceManager::SetLocalModuleFor(SSDivert *this)
{
  return (SSExpressionBase *)((__int64 (*)(void))this->i_statement_p->vfptr->find_expr_last_no_side_effect)();
}

// File Line: 1877
// RVA: 0x11D090
SSInvokedExpression *__fastcall SSDivert::invoke(SSDivert *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSObjectBase *v4; // rsi
  SSInstance **v5; // rdi
  SSDivert *v6; // rbx
  SSInvokedExpression *v7; // rax
  SSInvokedExpression *v8; // rbp
  __int64 v9; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v10; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v11; // rax
  SSInvokedExpression *result; // rax

  v4 = scope_p;
  v5 = result_pp;
  v6 = this;
  v7 = SSInvokedExpression::pool_new((SSExpressionBase *)&this->vfptr, caller_p, scope_p);
  v8 = v7;
  v9 = (__int64)v6->i_statement_p->vfptr->invoke(v6->i_statement_p, v4, (SSInvokedBase *)&v7->vfptr, v5);
  if ( v9 )
  {
    v10 = (AListNode<SSInvokedBase,SSInvokedBase> *)(v9 + 16);
    v11 = v8->i_calls.i_sentinel.i_prev_p;
    v8->i_calls.i_sentinel.i_prev_p = v10;
    v11->i_next_p = v10;
    v10->i_prev_p = v11;
    v10->i_next_p = &v8->i_calls.i_sentinel;
    ++v8->i_pending_count;
    result = v8;
  }
  else
  {
    SSInvokedExpression::pool_delete(v8);
    result = 0i64;
  }
  return result;
}

// File Line: 1915
// RVA: 0x11EF80
__int64 __fastcall SSDivert::is_immediate(SSDivert *this, unsigned int *durational_idx_p)
{
  return this->i_statement_p->vfptr->is_immediate(this->i_statement_p, durational_idx_p);
}

// File Line: 1925
// RVA: 0x13DCB0
void __fastcall SSDivert::track_memory(SSDivert *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rdi
  SSDivert *v3; // rbx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSDivert", 0x10u, 8u, 0, 0, 1u);
  v3->i_statement_p->vfptr->track_memory(v3->i_statement_p, v2);
}

// File Line: 2163
// RVA: 0x11C780
SSInvokedBase *__fastcall SSBind::invoke(SSBind *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSBind *v4; // rbx
  SSExpressionBase *v5; // rcx
  SSInstance **v6; // r14
  SSInvokedBase *v7; // rdi
  SSObjectBase *v8; // rsi
  bool v9; // ST20_1
  __int64 v10; // rbp
  SSInstance *v11; // rcx
  bool v12; // zf
  SSInstance *v14; // [rsp+50h] [rbp+8h]

  v4 = this;
  v5 = this->i_expr_p;
  v14 = SSBrain::c_nil_p;
  v6 = result_pp;
  v7 = caller_p;
  v8 = scope_p;
  v9 = result_pp != 0i64;
  v10 = (__int64)v5->vfptr->invoke(v5, scope_p, caller_p, &v14);
  (*((void (__fastcall **)(SSIdentifier *, SSInstance *, SSObjectBase *, SSInvokedBase *, bool))&v4->i_ident_p->vfptr[1].__vecDelDtor
   + 1))(
    v4->i_ident_p,
    v14,
    v8,
    v7,
    v9);
  v11 = v14;
  if ( v6 )
  {
    *v6 = v14;
  }
  else
  {
    v12 = v14->i_ref_count-- == 1;
    if ( v12 )
    {
      v11->i_ref_count = 2147483648;
      ((void (*)(void))v11->vfptr[1].get_scope_context)();
    }
  }
  return (SSInvokedBase *)v10;
}

// File Line: 2205
// RVA: 0x11F010
__int64 __fastcall Scaleform::DelegatedFile::Write(SSLoop *this, unsigned int *durational_idx_p)
{
  return this->i_expr_p->vfptr->is_immediate(this->i_expr_p, durational_idx_p);
}

// File Line: 2215
// RVA: 0x13D160
void __fastcall SSBind::track_memory(SSBind *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rdi
  SSBind *v3; // rbx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSBind", 0x18u, 8u, 0, 0, 1u);
  v3->i_ident_p->vfptr->track_memory((SSExpressionBase *)&v3->i_ident_p->vfptr, v2);
  v3->i_expr_p->vfptr->track_memory(v3->i_expr_p, v2);
}

