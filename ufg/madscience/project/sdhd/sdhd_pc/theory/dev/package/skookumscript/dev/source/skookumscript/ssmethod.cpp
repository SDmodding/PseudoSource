// File Line: 173
// RVA: 0x11E7C0
bool __fastcall SSMethodBase::is_class_member(SSMethodBase *this)
{
  return APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(&this->i_scope_p->i_class_methods, &this->i_name) == this;
}

// File Line: 187
// RVA: 0x1074C0
void __fastcall SSMethod::~SSMethod(SSMethod *this)
{
  SSExpressionBase *i_expr_p; // rcx
  SSParameters *i_obj_p; // rbx

  this->vfptr = (SSInvokableBaseVtbl *)&SSMethod::`vftable;
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

// File Line: 411
// RVA: 0x11DED0
SSInvokedBase *__fastcall SSMethod::invoke_deferred(
        SSMethod *this,
        SSInvokedMethod *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  return this->i_expr_p->vfptr->invoke(this->i_expr_p, scope_p, scope_p, result_pp);
}

// File Line: 457
// RVA: 0x13E4B0
void __fastcall SSMethod::track_memory(SSMethod *this, AMemoryStats *mem_stats_p)
{
  SSParameters *i_obj_p; // rbx
  __int64 i_count; // rax
  SSParameterBase **i_array_p; // rbx
  SSParameterBase **v7; // rdi

  AMemoryStats::track_memory(mem_stats_p, "SSMethod", 0x28u, 0, 0, 0, 1u);
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

// File Line: 557
// RVA: 0x11F260
bool __fastcall SSMethodFunc::is_placeholder(SSMethodFunc *this)
{
  return this->i_atomic_f == UFG::TSAudio::MthdC_get_named;
}

// File Line: 580
// RVA: 0x11DEE0
void __fastcall SSMethodFunc::invoke(
        SSMethodFunc *this,
        SSInvokedMethod *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  if ( result_pp )
    *result_pp = 0i64;
  this->i_atomic_f(scope_p, result_pp);
  if ( result_pp )
  {
    if ( !*result_pp )
      *result_pp = SSBrain::c_nil_p;
  }
}

// File Line: 631
// RVA: 0x125800
void __fastcall UFG::TSAudio::MthdC_get_named(SSInvokedMethod *scope_p, SSInstance **result_pp)
{
  if ( result_pp )
    *result_pp = SSBrain::c_nil_p;
}

// File Line: 646
// RVA: 0x13E620
void __fastcall SSMethodFunc::track_memory(SSMethodFunc *this, AMemoryStats *mem_stats_p)
{
  SSParameters *i_obj_p; // rbx
  __int64 i_count; // rax
  SSParameterBase **i_array_p; // rbx
  SSParameterBase **v7; // rdi

  AMemoryStats::track_memory(mem_stats_p, "SSMethodFunc", 0x30u, 0, 0, 0, 1u);
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

// File Line: 760
// RVA: 0x11DF20
void __fastcall SSMethodMthd::invoke(
        SSMethodMthd *this,
        SSInvokedMethod *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // r8

  i_obj_p = scope_p->i_scope_p.i_obj_p;
  if ( !i_obj_p || scope_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    i_obj_p = 0i64;
  if ( result_pp )
    *result_pp = 0i64;
  if ( i_obj_p )
    this->i_atomic_m((SSInstance *)((char *)i_obj_p + *((int *)&this->i_atomic_m + 2)), scope_p, result_pp);
  if ( result_pp )
  {
    if ( !*result_pp )
      *result_pp = SSBrain::c_nil_p;
  }
}

// File Line: 813
// RVA: 0x13E6C0
void __fastcall SSMethodMthd::track_memory(SSMethodMthd *this, AMemoryStats *mem_stats_p)
{
  SSParameters *i_obj_p; // rbx
  __int64 i_count; // rax
  SSParameterBase **i_array_p; // rbx
  SSParameterBase **v7; // rdi

  AMemoryStats::track_memory(mem_stats_p, "SSMethodMthd", 0x30u, 0, 0, 0, 1u);
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

