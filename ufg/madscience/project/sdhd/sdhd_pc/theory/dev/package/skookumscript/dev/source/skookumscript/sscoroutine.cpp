// File Line: 58
// RVA: 0x104D30
void __fastcall SSCoroutineBase::SSCoroutineBase(
        SSCoroutineBase *this,
        ASymbol *name,
        SSClass *scope_p,
        const void **binary_pp)
{
  SSParameters *v5; // rax
  SSParameters *v6; // rsi
  SSParameters *i_obj_p; // rbx

  this->i_name = (ASymbol)name->i_uid;
  this->i_scope_p = scope_p;
  this->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
  this->i_params_p.i_obj_p = 0i64;
  this->vfptr = (SSInvokableBaseVtbl *)&SSCoroutineBase::`vftable;
  v5 = SSParameters::get_or_create(binary_pp);
  v6 = v5;
  if ( this->i_params_p.i_obj_p != v5 )
  {
    if ( v5 )
      ++v5->i_ref_count;
    i_obj_p = this->i_params_p.i_obj_p;
    if ( i_obj_p )
    {
      if ( i_obj_p->i_ref_count-- == 1 )
      {
        i_obj_p->i_ref_count = 0x80000000;
        SSParameters::~SSParameters(i_obj_p);
        AMemory::c_free_func(i_obj_p);
      }
    }
    this->i_params_p.i_obj_p = v6;
  }
}

// File Line: 75
// RVA: 0x1115B0
void __fastcall SSCoroutineBase::assign_binary(SSMethodBase *this, const void **binary_pp)
{
  SSParameters *v3; // rdi
  SSParameters *i_obj_p; // rbx
  SSParameters params_p; // [rsp+28h] [rbp-40h] BYREF

  SSParameters::SSParameters(&params_p, binary_pp);
  v3 = SSParameters::get_or_create(&params_p);
  SSParameters::~SSParameters(&params_p);
  if ( this->i_params_p.i_obj_p != v3 )
  {
    if ( v3 )
      ++v3->i_ref_count;
    i_obj_p = this->i_params_p.i_obj_p;
    if ( i_obj_p )
    {
      if ( i_obj_p->i_ref_count-- == 1 )
      {
        i_obj_p->i_ref_count = 0x80000000;
        SSParameters::~SSParameters(i_obj_p);
        AMemory::c_free_func(i_obj_p);
      }
    }
    this->i_params_p.i_obj_p = v3;
  }
}

// File Line: 161
// RVA: 0x106EE0
void __fastcall SSCoroutine::~SSCoroutine(SSCoroutine *this)
{
  SSExpressionBase *i_expr_p; // rcx
  SSParameters *i_obj_p; // rbx

  this->vfptr = (SSInvokableBaseVtbl *)&SSCoroutine::`vftable;
  i_expr_p = this->i_expr_p;
  if ( i_expr_p )
    i_expr_p->vfptr->__vecDelDtor(i_expr_p, 1u);
  this->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
  i_obj_p = this->i_params_p.i_obj_p;
  if ( i_obj_p )
  {
    if ( i_obj_p->i_ref_count-- == 1 )
    {
      i_obj_p->i_ref_count = 0x80000000;
      SSParameters::~SSParameters(i_obj_p);
      AMemory::c_free_func(i_obj_p);
    }
  }
}

// File Line: 208
// RVA: 0x111550
void __fastcall SSMethod::assign_binary(SSMethod *this, const void **binary_pp)
{
  char *v4; // rax
  eSSExprType v5; // ecx

  SSCoroutineBase::assign_binary(this, binary_pp);
  v4 = (char *)*binary_pp + 1;
  v5 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = v4;
  if ( v5 )
  {
    *binary_pp = v4 + 2;
    this->i_expr_p = SSExpressionBase::from_binary_new(v5, binary_pp);
  }
  else
  {
    this->i_expr_p = 0i64;
  }
}

// File Line: 363
// RVA: 0x11E720
_BOOL8 __fastcall SSMethodFunc::is_bound(SSMethodMthd *this)
{
  return this->i_atomic_m != 0i64;
}

// File Line: 379
// RVA: 0x126F30
char __fastcall SSCoroutine::on_update(SSCoroutine *this, SSInvokedCoroutine *scope_p)
{
  SSInvokedBase *v3; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v4; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax

  v3 = this->i_expr_p->vfptr->invoke(this->i_expr_p, scope_p, scope_p, 0i64);
  if ( !v3 )
    return 1;
  v4 = &v3->AListNode<SSInvokedBase,SSInvokedBase>;
  i_prev_p = scope_p->i_calls.i_sentinel.i_prev_p;
  scope_p->i_calls.i_sentinel.i_prev_p = v4;
  i_prev_p->i_next_p = v4;
  v4->i_prev_p = i_prev_p;
  v4->i_next_p = &scope_p->i_calls.i_sentinel;
  ++scope_p->i_pending_count;
  return 0;
}

// File Line: 404
// RVA: 0x13DA00
void __fastcall SSCoroutine::track_memory(SSCoroutine *this, AMemoryStats *mem_stats_p)
{
  SSParameters *i_obj_p; // rbx
  __int64 i_count; // rax
  SSParameterBase **i_array_p; // rbx
  SSParameterBase **v7; // rdi

  AMemoryStats::track_memory(mem_stats_p, "SSCoroutine", 0x28u, 0, 0, 0, 1u);
  this->i_expr_p->vfptr->track_memory(this->i_expr_p, mem_stats_p);
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

// File Line: 511
// RVA: 0x126F90
char __fastcall SSCoroutineMthd::on_update(SSCoroutineMthd *this, SSInvokedCoroutine *scope_p)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( i_obj_p && scope_p->i_scope_p.i_ptr_id == i_obj_p->i_ptr_id )
    return ((__int64 (__fastcall *)(char *))this->i_update_m)((char *)i_obj_p + *((int *)&this->i_update_m + 2));
  else
    return 1;
}

// File Line: 549
// RVA: 0x13DC10
void __fastcall SSCoroutineMthd::track_memory(SSCoroutineMthd *this, AMemoryStats *mem_stats_p)
{
  SSParameters *i_obj_p; // rbx
  __int64 i_count; // rax
  SSParameterBase **i_array_p; // rbx
  SSParameterBase **v7; // rdi

  AMemoryStats::track_memory(mem_stats_p, "SSCoroutineMthd", 0x30u, 0, 0, 0, 1u);
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

// File Line: 648
// RVA: 0x11F250
bool __fastcall SSCoroutineFunc::is_placeholder(SSCoroutineFunc *this)
{
  return this->i_update_f == (bool (__fastcall *)(SSInvokedCoroutine *))Track<TriggerRecoilPostEffectTask>::DeleteTaskWhenItReturnsFalse;
}

// File Line: 665
// RVA: 0x126F80
__int64 __fastcall SSCoroutineFunc::on_update(SSCoroutineFunc *this, SSInvokedCoroutine *scope_p)
{
  return ((__int64 (__fastcall *)(SSInvokedCoroutine *))this->i_update_f)(scope_p);
}

// File Line: 709
// RVA: 0x13DB70
void __fastcall SSCoroutineFunc::track_memory(SSCoroutineFunc *this, AMemoryStats *mem_stats_p)
{
  SSParameters *i_obj_p; // rbx
  __int64 i_count; // rax
  SSParameterBase **i_array_p; // rbx
  SSParameterBase **v7; // rdi

  AMemoryStats::track_memory(mem_stats_p, "SSCoroutineFunc", 0x30u, 0, 0, 0, 1u);
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

