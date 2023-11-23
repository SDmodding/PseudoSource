// File Line: 39
// RVA: 0x106DB0
void __fastcall SSClosureInfoBase::~SSClosureInfoBase(SSClosureInfoBase *this)
{
  this->vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoBase::`vftable;
  AMemory::c_free_func(this->i_captured.i_array_p);
}

// File Line: 52
// RVA: 0x1046F0
void __fastcall SSClosureInfoBase::SSClosureInfoBase(SSClosureInfoBase *this, SSClosureInfoBase *closure_p)
{
  ASymbol *i_array_p; // rdi
  __int64 i_count; // rsi
  ASymbol *v5; // r8
  ASymbol *v6; // rdx
  ASymbol *v7; // r9
  AVCompactSortedLogical<ASymbol,ASymbol> *p_i_captured; // [rsp+80h] [rbp+18h]

  this->i_ref_count = 0;
  this->vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoBase::`vftable;
  i_array_p = closure_p->i_captured.i_array_p;
  i_count = closure_p->i_captured.i_count;
  closure_p->i_captured.i_count = 0;
  closure_p->i_captured.i_array_p = 0i64;
  p_i_captured = &this->i_captured;
  v5 = AVCompactArrayBase<ASymbol>::alloc_array(i_count);
  p_i_captured->i_count = i_count;
  this->i_captured.i_array_p = v5;
  if ( (_DWORD)i_count )
  {
    v6 = i_array_p;
    v7 = &i_array_p[i_count];
    if ( i_array_p < v7 )
    {
      do
      {
        if ( v5 )
          v5->i_uid = v6->i_uid;
        ++v5;
        ++v6;
      }
      while ( v6 < v7 );
    }
  }
  AMemory::c_free_func(i_array_p);
}

// File Line: 72
// RVA: 0x104650
void __fastcall SSClosureInfoBase::SSClosureInfoBase(SSClosureInfoBase *this, unsigned int **binary_pp)
{
  AVCompactSortedLogical<ASymbol,ASymbol> *p_i_captured; // rbx
  unsigned int v5; // edi
  ASymbol *v6; // rax
  AVCompactSortedLogical<ASymbol,ASymbol> *result; // [rsp+68h] [rbp+10h] BYREF
  AVCompactSortedLogical<ASymbol,ASymbol> *v8; // [rsp+70h] [rbp+18h]
  ASymbol *v9; // [rsp+78h] [rbp+20h]

  this->i_ref_count = 0;
  this->vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoBase::`vftable;
  p_i_captured = &this->i_captured;
  result = &this->i_captured;
  this->i_captured.i_count = 0;
  this->i_captured.i_array_p = 0i64;
  v5 = *(*binary_pp)++;
  AVCompactArrayBase<ASymbol>::empty_ensure_count_undef(&this->i_captured, v5);
  if ( v5 )
  {
    v8 = &this->i_captured;
    do
    {
      v6 = ASymbol::create_from_binary((ASymbol *)&result, (const void **)binary_pp);
      v9 = &this->i_captured.i_array_p[p_i_captured->i_count];
      if ( v9 )
        v9->i_uid = v6->i_uid;
      ++p_i_captured->i_count;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 215
// RVA: 0x1049D0
void __fastcall SSClosureInfoMethod::SSClosureInfoMethod(SSClosureInfoMethod *this, SSClosureInfoMethod *closure_p)
{
  SSParameters *i_obj_p; // r10
  SSExpressionBase *i_expr_p; // rcx
  SSClass *i_scope_p; // r8
  SSMethod *v7; // r9

  SSClosureInfoBase::SSClosureInfoBase(this, closure_p);
  i_obj_p = closure_p->i_params_p.i_obj_p;
  i_expr_p = closure_p->i_expr_p;
  i_scope_p = closure_p->i_scope_p;
  v7 = &this->SSMethod;
  this->i_name.i_uid = closure_p->i_name.i_uid;
  this->i_scope_p = i_scope_p;
  this->SSMethod::SSMethodBase::SSInvokableBase::vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
  this->i_params_p.i_obj_p = i_obj_p;
  if ( i_obj_p )
    ++i_obj_p->i_ref_count;
  v7->vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
  v7->vfptr = (SSInvokableBaseVtbl *)&SSMethod::`vftable;
  this->i_expr_p = i_expr_p;
  this->SSClosureInfoBase::vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoMethod::`vftable{for `SSClosureInfoBase};
  v7->vfptr = (SSInvokableBaseVtbl *)&SSClosureInfoMethod::`vftable{for `SSMethod};
  closure_p->i_expr_p = 0i64;
}

// File Line: 224
// RVA: 0x106DF0
void __fastcall SSClosureInfoMethod::~SSClosureInfoMethod(SSClosureInfoMethod *this)
{
  SSMethod *v2; // rcx

  this->SSClosureInfoBase::vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoMethod::`vftable{for `SSClosureInfoBase};
  v2 = &this->SSMethod;
  v2->vfptr = (SSInvokableBaseVtbl *)&SSClosureInfoMethod::`vftable{for `SSMethod};
  SSMethod::~SSMethod(v2);
  this->SSClosureInfoBase::vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoBase::`vftable;
  AMemory::c_free_func(this->i_captured.i_array_p);
}

// File Line: 250
// RVA: 0x104910
void __fastcall SSClosureInfoMethod::SSClosureInfoMethod(SSClosureInfoMethod *this, unsigned int **binary_pp)
{
  SSExpressionBase *v4; // rdi
  eSSExprType v5; // ecx
  unsigned int *v6; // rax

  SSClosureInfoBase::SSClosureInfoBase(this, binary_pp);
  this->i_name = ASymbol_closure;
  v4 = 0i64;
  this->i_scope_p = 0i64;
  this->SSMethod::SSMethodBase::SSInvokableBase::vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
  this->i_params_p.i_obj_p = 0i64;
  this->SSMethod::SSMethodBase::SSInvokableBase::vfptr = (SSInvokableBaseVtbl *)&SSMethodBase::`vftable;
  this->SSMethod::SSMethodBase::SSInvokableBase::vfptr = (SSInvokableBaseVtbl *)&SSMethod::`vftable;
  this->i_expr_p = 0i64;
  this->SSClosureInfoBase::vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoMethod::`vftable{for `SSClosureInfoBase};
  this->SSMethod::SSMethodBase::SSInvokableBase::vfptr = (SSInvokableBaseVtbl *)&SSClosureInfoMethod::`vftable{for `SSMethod};
  SSCoroutineBase::assign_binary(&this->SSMethod, (const void **)binary_pp);
  v5 = *(unsigned __int8 *)*binary_pp;
  v6 = (unsigned int *)((char *)*binary_pp + 1);
  *binary_pp = v6;
  if ( v5 )
  {
    *binary_pp = (unsigned int *)((char *)v6 + 2);
    v4 = SSExpressionBase::from_binary_new(v5, (const void **)binary_pp);
  }
  this->i_expr_p = v4;
}

// File Line: 268
// RVA: 0x13D650
void __fastcall SSClosureInfoMethod::track_memory(SSClosureInfoMethod *this, AMemoryStats *mem_stats_p)
{
  SSParameters *i_obj_p; // rbx
  __int64 i_count; // rax
  SSParameterBase **i_array_p; // rbx
  SSParameterBase **v7; // rdi

  AMemoryStats::track_memory(mem_stats_p, "SSClosureInfoMethod", 0x48u, 0, 0, 0, 1u);
  this->i_expr_p->SSMethod::vfptr->track_memory(this->i_expr_p, mem_stats_p);
  i_obj_p = this->i_params_p.i_obj_p;
  i_count = i_obj_p->i_params.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = i_obj_p->i_params.i_array_p;
    v7 = &i_array_p[i_count];
    if ( i_array_p < v7 )
    {
      while ( !(*i_array_p)->vfptr->is_defaultable(*i_array_p) )
      {
        if ( ++i_array_p >= v7 )
          return;
      }
      SSParameters::track_memory(this->i_params_p.i_obj_p, mem_stats_p);
    }
  }
}

// File Line: 314
// RVA: 0x104860
void __fastcall SSClosureInfoCoroutine::SSClosureInfoCoroutine(
        SSClosureInfoCoroutine *this,
        SSClosureInfoMethod *closure_p)
{
  SSParameters *i_obj_p; // rdi
  SSClass *i_scope_p; // rbx
  SSExpressionBase *v6; // rax
  SSCoroutine *v7; // rdx

  SSClosureInfoBase::SSClosureInfoBase(this, closure_p);
  i_obj_p = closure_p->i_params_p.i_obj_p;
  i_scope_p = closure_p->i_scope_p;
  v6 = closure_p->SSMethod::SSMethodBase::SSInvokableBase::vfptr->get_custom_expr(&closure_p->SSMethod);
  v7 = &this->SSCoroutine;
  this->i_name.i_uid = closure_p->i_name.i_uid;
  this->i_scope_p = i_scope_p;
  this->SSCoroutine::SSCoroutineBase::SSInvokableBase::vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
  this->i_params_p.i_obj_p = i_obj_p;
  if ( i_obj_p )
    ++i_obj_p->i_ref_count;
  v7->vfptr = (SSInvokableBaseVtbl *)&SSCoroutineBase::`vftable;
  v7->vfptr = (SSInvokableBaseVtbl *)&SSCoroutine::`vftable;
  this->i_expr_p = v6;
  this->SSClosureInfoBase::vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoCoroutine::`vftable{for `SSClosureInfoBase};
  v7->vfptr = (SSInvokableBaseVtbl *)&SSClosureInfoCoroutine::`vftable{for `SSCoroutine};
  closure_p->i_expr_p = 0i64;
}

// File Line: 348
// RVA: 0x1047A0
void __fastcall SSClosureInfoCoroutine::SSClosureInfoCoroutine(SSClosureInfoCoroutine *this, unsigned int **binary_pp)
{
  SSExpressionBase *v4; // rdi
  eSSExprType v5; // ecx
  unsigned int *v6; // rax

  SSClosureInfoBase::SSClosureInfoBase(this, binary_pp);
  this->i_name = ASymbol__closure;
  v4 = 0i64;
  this->i_scope_p = 0i64;
  this->SSCoroutine::SSCoroutineBase::SSInvokableBase::vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
  this->i_params_p.i_obj_p = 0i64;
  this->SSCoroutine::SSCoroutineBase::SSInvokableBase::vfptr = (SSInvokableBaseVtbl *)&SSCoroutineBase::`vftable;
  this->SSCoroutine::SSCoroutineBase::SSInvokableBase::vfptr = (SSInvokableBaseVtbl *)&SSCoroutine::`vftable;
  this->i_expr_p = 0i64;
  this->SSClosureInfoBase::vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoCoroutine::`vftable{for `SSClosureInfoBase};
  this->SSCoroutine::SSCoroutineBase::SSInvokableBase::vfptr = (SSInvokableBaseVtbl *)&SSClosureInfoCoroutine::`vftable{for `SSCoroutine};
  SSCoroutineBase::assign_binary((SSMethodBase *)&this->SSCoroutine, (const void **)binary_pp);
  v5 = *(unsigned __int8 *)*binary_pp;
  v6 = (unsigned int *)((char *)*binary_pp + 1);
  *binary_pp = v6;
  if ( v5 )
  {
    *binary_pp = (unsigned int *)((char *)v6 + 2);
    v4 = SSExpressionBase::from_binary_new(v5, (const void **)binary_pp);
  }
  this->i_expr_p = v4;
}

// File Line: 366
// RVA: 0x13D5A0
void __fastcall SSClosureInfoCoroutine::track_memory(SSClosureInfoCoroutine *this, AMemoryStats *mem_stats_p)
{
  SSParameters *i_obj_p; // rbx
  __int64 i_count; // rax
  SSParameterBase **i_array_p; // rbx
  SSParameterBase **v7; // rdi

  AMemoryStats::track_memory(mem_stats_p, "SSClosureInfoCoroutine", 0x48u, 0, 0, 0, 1u);
  this->i_expr_p->SSCoroutine::vfptr->track_memory(this->i_expr_p, mem_stats_p);
  i_obj_p = this->i_params_p.i_obj_p;
  i_count = i_obj_p->i_params.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = i_obj_p->i_params.i_array_p;
    v7 = &i_array_p[i_count];
    if ( i_array_p < v7 )
    {
      while ( !(*i_array_p)->vfptr->is_defaultable(*i_array_p) )
      {
        if ( ++i_array_p >= v7 )
          return;
      }
      SSParameters::track_memory(this->i_params_p.i_obj_p, mem_stats_p);
    }
  }
}

// File Line: 406
// RVA: 0x1073F0
void __fastcall SSLiteralClosure::~SSLiteralClosure(SSLiteralClosure *this)
{
  SSExpressionBase *i_receiver_p; // rcx
  SSClosureInfoBase *i_obj_p; // rax

  this->vfptr = (SSExpressionBaseVtbl *)&SSLiteralClosure::`vftable;
  i_receiver_p = this->i_receiver_p;
  if ( i_receiver_p )
    i_receiver_p->vfptr->__vecDelDtor(i_receiver_p, 1u);
  i_obj_p = this->i_info_p.i_obj_p;
  if ( i_obj_p )
  {
    if ( i_obj_p->i_ref_count-- == 1 )
    {
      i_obj_p->i_ref_count = 0x80000000;
      if ( i_obj_p != (SSClosureInfoBase *)-8i64 )
        i_obj_p->vfptr->__vecDelDtor(i_obj_p, 1u);
    }
  }
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
}

// File Line: 422
// RVA: 0x105CA0
void __fastcall SSLiteralClosure::SSLiteralClosure(
        SSLiteralClosure *this,
        SSLiteralClosure *closure_method_p,
        eSSExprType type)
{
  SSClosureInfoMethod *i_obj_p; // rbx
  SSClosureInfoMethod *v6; // rax
  SSClosureInfoBase *v7; // rax
  SSClosureInfoBase *v8; // rbx
  SSClosureInfoCoroutine *v9; // rax
  SSClosureInfoBase *v10; // rax
  SSClosureInfoBase *v11; // rax
  bool v12; // zf
  SSClosureInfoBase *v13; // rax

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSLiteralClosure::`vftable;
  this->i_receiver_p = closure_method_p->i_receiver_p;
  this->i_info_p.i_obj_p = 0i64;
  i_obj_p = (SSClosureInfoMethod *)closure_method_p->i_info_p.i_obj_p;
  if ( type == SSExprType_closure_method )
  {
    v6 = (SSClosureInfoMethod *)AMemory::c_malloc_func(0x48ui64, "SSClosureInfoMethod");
    if ( v6 )
    {
      SSClosureInfoMethod::SSClosureInfoMethod(v6, i_obj_p);
      v8 = v7;
    }
    else
    {
      v8 = 0i64;
    }
  }
  else
  {
    v9 = (SSClosureInfoCoroutine *)AMemory::c_malloc_func(0x48ui64, "SSClosureInfoCoroutine");
    if ( v9 )
    {
      SSClosureInfoCoroutine::SSClosureInfoCoroutine(v9, i_obj_p);
      v8 = v10;
    }
    else
    {
      v8 = 0i64;
    }
  }
  if ( this->i_info_p.i_obj_p != v8 )
  {
    if ( v8 )
      ++v8->i_ref_count;
    v11 = this->i_info_p.i_obj_p;
    if ( v11 )
    {
      v12 = v11->i_ref_count-- == 1;
      if ( v12 )
      {
        v11->i_ref_count = 0x80000000;
        if ( v11 != (SSClosureInfoBase *)-8i64 )
          v11->vfptr->__vecDelDtor(v11, 1u);
      }
    }
    this->i_info_p.i_obj_p = v8;
  }
  closure_method_p->i_receiver_p = 0i64;
  v13 = closure_method_p->i_info_p.i_obj_p;
  if ( v13 )
  {
    v12 = v13->i_ref_count-- == 1;
    if ( v12 )
    {
      v13->i_ref_count = 0x80000000;
      if ( v13 != (SSClosureInfoBase *)-8i64 )
        v13->vfptr->__vecDelDtor(v13, 1u);
    }
    closure_method_p->i_info_p.i_obj_p = 0i64;
  }
}

// File Line: 455
// RVA: 0x105B90
void __fastcall SSLiteralClosure::SSLiteralClosure(SSLiteralClosure *this, const void **binary_pp, eSSExprType type)
{
  eSSExprType v6; // ecx
  char *v7; // rax
  SSClosureInfoBase *v8; // rbx
  SSExpressionBase *v9; // rax
  SSClosureInfoMethod *v10; // rax
  SSClosureInfoBase *v11; // rax
  SSClosureInfoCoroutine *v12; // rax
  SSClosureInfoBase *v13; // rax
  SSClosureInfoBase *i_obj_p; // rax

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSLiteralClosure::`vftable;
  v6 = *(unsigned __int8 *)*binary_pp;
  v7 = (char *)*binary_pp + 1;
  *binary_pp = v7;
  v8 = 0i64;
  if ( v6 )
  {
    *binary_pp = v7 + 2;
    v9 = SSExpressionBase::from_binary_new(v6, binary_pp);
  }
  else
  {
    v9 = 0i64;
  }
  this->i_receiver_p = v9;
  this->i_info_p.i_obj_p = 0i64;
  if ( type == SSExprType_closure_method )
  {
    v10 = (SSClosureInfoMethod *)AMemory::c_malloc_func(0x48ui64, "SSClosureInfoMethod");
    if ( v10 )
    {
      SSClosureInfoMethod::SSClosureInfoMethod(v10, (unsigned int **)binary_pp);
      v8 = v11;
    }
  }
  else
  {
    v12 = (SSClosureInfoCoroutine *)AMemory::c_malloc_func(0x48ui64, "SSClosureInfoCoroutine");
    if ( v12 )
    {
      SSClosureInfoCoroutine::SSClosureInfoCoroutine(v12, (unsigned int **)binary_pp);
      v8 = v13;
    }
  }
  if ( this->i_info_p.i_obj_p != v8 )
  {
    if ( v8 )
      ++v8->i_ref_count;
    i_obj_p = this->i_info_p.i_obj_p;
    if ( i_obj_p )
    {
      if ( i_obj_p->i_ref_count-- == 1 )
      {
        i_obj_p->i_ref_count = 0x80000000;
        if ( i_obj_p != (SSClosureInfoBase *)-8i64 )
          i_obj_p->vfptr->__vecDelDtor(i_obj_p, 1u);
      }
    }
    this->i_info_p.i_obj_p = v8;
  }
}

// File Line: 531
// RVA: 0x119F30
_BOOL8 __fastcall SSLiteralClosure::get_side_effect(SSLiteralClosure *this)
{
  SSExpressionBase *i_receiver_p; // rcx

  i_receiver_p = this->i_receiver_p;
  return i_receiver_p && i_receiver_p->vfptr->get_side_effect(i_receiver_p);
}

// File Line: 767
// RVA: 0x11DA90
SSInvokedBase *__fastcall SSLiteralClosure::invoke(
        SSLiteralClosure *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSClosure **result_pp)
{
  SSClosureInfoBase *i_obj_p; // rsi
  SSExpressionBase *i_receiver_p; // rcx
  SSInstance *v9; // rdi
  SSClosure *v10; // rax
  __int64 i_count; // rcx
  ASymbol *i_array_p; // rsi
  SSClosure *v13; // rbx
  unsigned __int64 v14; // rbp
  SSInstance *v15; // rax
  SSInstance *receiver_p; // [rsp+40h] [rbp+8h] BYREF

  i_obj_p = this->i_info_p.i_obj_p;
  i_receiver_p = this->i_receiver_p;
  if ( i_receiver_p )
  {
    i_receiver_p->vfptr->invoke(i_receiver_p, scope_p, caller_p, &receiver_p);
    v9 = receiver_p;
  }
  else
  {
    v9 = scope_p->vfptr->get_topmost_scope(scope_p);
  }
  if ( result_pp )
  {
    v10 = SSClosure::pool_new(i_obj_p, v9);
    *result_pp = v10;
    i_count = i_obj_p->i_captured.i_count;
    if ( (_DWORD)i_count )
    {
      i_array_p = i_obj_p->i_captured.i_array_p;
      v13 = v10 + 1;
      v14 = (unsigned __int64)&v10[1] + 8 * i_count;
      if ( (unsigned __int64)&v10[1] < v14 )
      {
        do
        {
          v15 = scope_p->vfptr->get_data_by_name(scope_p, i_array_p);
          v13 = (SSClosure *)((char *)v13 + 8);
          ++i_array_p;
          v13[-1].i_user_data2 = (unsigned __int64)v15;
          ++v15->i_ref_count;
        }
        while ( (unsigned __int64)v13 < v14 );
      }
    }
  }
  if ( this->i_receiver_p )
  {
    if ( v9->i_ref_count-- == 1 )
    {
      v9->i_ref_count = 0x80000000;
      v9->vfptr[1].get_scope_context(v9);
    }
  }
  return 0i64;
}

// File Line: 844
// RVA: 0x13E300
void __fastcall SSLiteralClosure::track_memory(SSLiteralClosure *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase *i_receiver_p; // rcx
  SSClosureInfoBase *i_obj_p; // rcx

  AMemoryStats::track_memory(mem_stats_p, "SSLiteralClosure", 0x18u, 8u, 0, 0, 1u);
  i_receiver_p = this->i_receiver_p;
  if ( i_receiver_p )
    i_receiver_p->vfptr->track_memory(i_receiver_p, mem_stats_p);
  i_obj_p = this->i_info_p.i_obj_p;
  if ( i_obj_p )
    i_obj_p->vfptr->track_memory(i_obj_p, mem_stats_p);
}

