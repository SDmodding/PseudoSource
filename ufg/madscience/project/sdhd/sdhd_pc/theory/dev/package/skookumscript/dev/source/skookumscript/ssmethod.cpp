// File Line: 173
// RVA: 0x11E7C0
bool __fastcall SSMethodBase::is_class_member(SSMethodBase *this)
{
  return APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol>>::get(
           (APSorted<SSMethodBase,ASymbol,ACompareLogical<ASymbol> > *)&this->i_scope_p->i_class_methods.i_count,
           &this->i_name) == this;
}

// File Line: 187
// RVA: 0x1074C0
void __fastcall SSMethod::~SSMethod(SSMethod *this)
{
  SSMethod *v1; // rbx
  SSExpressionBase *v2; // rcx
  SSParameters *v3; // rbx
  bool v4; // zf

  v1 = this;
  this->vfptr = (SSInvokableBaseVtbl *)&SSMethod::`vftable;
  v2 = this->i_expr_p;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  v1->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
  v3 = v1->i_params_p.i_obj_p;
  if ( v3 )
  {
    v4 = v3->i_ref_count-- == 1;
    if ( v4 )
    {
      v3->i_ref_count = 2147483648;
      SSParameters::~SSParameters(v3);
      AMemory::c_free_func(v3);
    }
  }
}

// File Line: 411
// RVA: 0x11DED0
SSInvokedBase *__fastcall SSMethod::invoke_deferred(SSMethod *this, SSInvokedMethod *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  return (SSInvokedBase *)this->i_expr_p->vfptr->invoke(
                            this->i_expr_p,
                            (SSObjectBase *)scope_p,
                            (SSInvokedBase *)scope_p,
                            result_pp);
}

// File Line: 457
// RVA: 0x13E4B0
void __fastcall SSMethod::track_memory(SSMethod *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rsi
  SSMethod *v3; // rbp
  SSParameters *v4; // rbx
  __int64 v5; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdi

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSMethod", 0x28u, 0, 0, 0, 1u);
  v3->i_expr_p->vfptr->track_memory(v3->i_expr_p, v2);
  v4 = v3->i_params_p.i_obj_p;
  v5 = v4->i_params.i_count;
  if ( (_DWORD)v5 )
  {
    v6 = (unsigned __int64)v4->i_params.i_array_p;
    v7 = v6 + 8 * v5;
    if ( v6 < v7 )
    {
      while ( !(*(unsigned __int8 (**)(void))(**(_QWORD **)v6 + 40i64))() )
      {
        v6 += 8i64;
        if ( v6 >= v7 )
          return;
      }
      SSParameters::track_memory(v3->i_params_p.i_obj_p, v2);
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
void __fastcall SSMethodFunc::invoke(SSMethodFunc *this, SSInvokedMethod *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInstance **v4; // rbx

  v4 = result_pp;
  if ( result_pp )
    *result_pp = 0i64;
  this->i_atomic_f(scope_p, result_pp);
  if ( v4 )
  {
    if ( !*v4 )
      *v4 = SSBrain::c_nil_p;
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
  AMemoryStats *v2; // rsi
  SSMethodFunc *v3; // rbp
  SSParameters *v4; // rbx
  __int64 v5; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdi

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSMethodFunc", 0x30u, 0, 0, 0, 1u);
  v4 = v3->i_params_p.i_obj_p;
  v5 = v4->i_params.i_count;
  if ( (_DWORD)v5 )
  {
    v6 = (unsigned __int64)v4->i_params.i_array_p;
    v7 = v6 + 8 * v5;
    if ( v6 < v7 )
    {
      while ( !(*(unsigned __int8 (**)(void))(**(_QWORD **)v6 + 40i64))() )
      {
        v6 += 8i64;
        if ( v6 >= v7 )
          return;
      }
      SSParameters::track_memory(v3->i_params_p.i_obj_p, v2);
    }
  }
}

// File Line: 760
// RVA: 0x11DF20
void __fastcall SSMethodMthd::invoke(SSMethodMthd *this, SSInvokedMethod *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSObjectBase *v4; // r8
  SSInstance **v5; // rbx

  v4 = scope_p->i_scope_p.i_obj_p;
  v5 = result_pp;
  if ( !v4 || scope_p->i_scope_p.i_ptr_id != v4->i_ptr_id )
    v4 = 0i64;
  if ( result_pp )
    *result_pp = 0i64;
  if ( v4 )
    this->i_atomic_m((SSInstance *)((char *)v4 + *((signed int *)&this->i_atomic_m + 2)), scope_p, result_pp);
  if ( v5 )
  {
    if ( !*v5 )
      *v5 = SSBrain::c_nil_p;
  }
}

// File Line: 813
// RVA: 0x13E6C0
void __fastcall SSMethodMthd::track_memory(SSMethodMthd *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rsi
  SSMethodMthd *v3; // rbp
  SSParameters *v4; // rbx
  __int64 v5; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdi

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSMethodMthd", 0x30u, 0, 0, 0, 1u);
  v4 = v3->i_params_p.i_obj_p;
  v5 = v4->i_params.i_count;
  if ( (_DWORD)v5 )
  {
    v6 = (unsigned __int64)v4->i_params.i_array_p;
    v7 = v6 + 8 * v5;
    if ( v6 < v7 )
    {
      while ( !(*(unsigned __int8 (**)(void))(**(_QWORD **)v6 + 40i64))() )
      {
        v6 += 8i64;
        if ( v6 >= v7 )
          return;
      }
      SSParameters::track_memory(v3->i_params_p.i_obj_p, v2);
    }
  }
}

