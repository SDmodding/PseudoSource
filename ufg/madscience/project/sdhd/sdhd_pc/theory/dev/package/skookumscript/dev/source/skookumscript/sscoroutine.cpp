// File Line: 58
// RVA: 0x104D30
void __fastcall SSCoroutineBase::SSCoroutineBase(SSCoroutineBase *this, ASymbol *name, SSClass *scope_p, const void **binary_pp)
{
  SSCoroutineBase *v4; // rdi
  SSParameters *v5; // rax
  SSParameters *v6; // rsi
  SSParameters *v7; // rbx
  bool v8; // zf

  v4 = this;
  this->i_name = (ASymbol)name->i_uid;
  this->i_scope_p = scope_p;
  this->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
  this->i_params_p.i_obj_p = 0i64;
  this->vfptr = (SSInvokableBaseVtbl *)&SSCoroutineBase::`vftable;
  v5 = SSParameters::get_or_create(binary_pp);
  v6 = v5;
  if ( v4->i_params_p.i_obj_p != v5 )
  {
    if ( v5 )
      ++v5->i_ref_count;
    v7 = v4->i_params_p.i_obj_p;
    if ( v7 )
    {
      v8 = v7->i_ref_count-- == 1;
      if ( v8 )
      {
        v7->i_ref_count = 2147483648;
        SSParameters::~SSParameters(v7);
        AMemory::c_free_func(v7);
      }
    }
    v4->i_params_p.i_obj_p = v6;
  }
}

// File Line: 75
// RVA: 0x1115B0
void __fastcall SSCoroutineBase::assign_binary(SSMethodBase *this, const void **binary_pp)
{
  SSMethodBase *v2; // rsi
  SSParameters *v3; // rdi
  SSParameters *v4; // rbx
  bool v5; // zf
  SSParameters params_p; // [rsp+28h] [rbp-40h]

  v2 = this;
  SSParameters::SSParameters(&params_p, binary_pp);
  v3 = SSParameters::get_or_create(&params_p);
  SSParameters::~SSParameters(&params_p);
  if ( v2->i_params_p.i_obj_p != v3 )
  {
    if ( v3 )
      ++v3->i_ref_count;
    v4 = v2->i_params_p.i_obj_p;
    if ( v4 )
    {
      v5 = v4->i_ref_count-- == 1;
      if ( v5 )
      {
        v4->i_ref_count = 2147483648;
        SSParameters::~SSParameters(v4);
        AMemory::c_free_func(v4);
      }
    }
    v2->i_params_p.i_obj_p = v3;
  }
}

// File Line: 161
// RVA: 0x106EE0
void __fastcall SSCoroutine::~SSCoroutine(SSCoroutine *this)
{
  SSCoroutine *v1; // rbx
  SSExpressionBase *v2; // rcx
  SSParameters *v3; // rbx
  bool v4; // zf

  v1 = this;
  this->vfptr = (SSInvokableBaseVtbl *)&SSCoroutine::`vftable;
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

// File Line: 208
// RVA: 0x111550
void __fastcall SSMethod::assign_binary(SSMethod *this, const void **binary_pp)
{
  const void **v2; // rbx
  SSMethod *v3; // rdi
  signed __int64 v4; // rax
  eSSExprType v5; // ecx

  v2 = binary_pp;
  v3 = this;
  SSCoroutineBase::assign_binary((SSMethodBase *)&this->vfptr, binary_pp);
  v4 = (signed __int64)*v2 + 1;
  v5 = *(unsigned __int8 *)*v2;
  *v2 = (const void *)v4;
  if ( v5 )
  {
    *v2 = (const void *)(v4 + 2);
    v3->i_expr_p = SSExpressionBase::from_binary_new(v5, v2);
  }
  else
  {
    v3->i_expr_p = 0i64;
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
  SSInvokedCoroutine *v2; // rbx
  SSInvokedBase *v3; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v4; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v5; // rax

  v2 = scope_p;
  v3 = this->i_expr_p->vfptr->invoke(this->i_expr_p, (SSObjectBase *)scope_p, (SSInvokedBase *)scope_p, 0i64);
  if ( !v3 )
    return 1;
  v4 = (AListNode<SSInvokedBase,SSInvokedBase> *)&v3->i_next_p;
  v5 = v2->i_calls.i_sentinel.i_prev_p;
  v2->i_calls.i_sentinel.i_prev_p = v4;
  v5->i_next_p = v4;
  v4->i_prev_p = v5;
  v4->i_next_p = &v2->i_calls.i_sentinel;
  ++v2->i_pending_count;
  return 0;
}

// File Line: 404
// RVA: 0x13DA00
void __fastcall SSCoroutine::track_memory(SSCoroutine *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rsi
  SSCoroutine *v3; // rbp
  SSParameters *v4; // rbx
  __int64 v5; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdi

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSCoroutine", 0x28u, 0, 0, 0, 1u);
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

// File Line: 511
// RVA: 0x126F90
char __fastcall SSCoroutineMthd::on_update(SSCoroutineMthd *this, SSInvokedCoroutine *scope_p)
{
  SSObjectBase *v2; // r8
  char result; // al

  v2 = scope_p->i_scope_p.i_obj_p;
  if ( v2 && scope_p->i_scope_p.i_ptr_id == v2->i_ptr_id )
    result = ((__int64 (__fastcall *)(char *))this->i_update_m)((char *)v2 + *((signed int *)&this->i_update_m + 2));
  else
    result = 1;
  return result;
}

// File Line: 549
// RVA: 0x13DC10
void __fastcall SSCoroutineMthd::track_memory(SSCoroutineMthd *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rsi
  SSCoroutineMthd *v3; // rbp
  SSParameters *v4; // rbx
  __int64 v5; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdi

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSCoroutineMthd", 0x30u, 0, 0, 0, 1u);
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
  return this->i_update_f(scope_p);
}

// File Line: 709
// RVA: 0x13DB70
void __fastcall SSCoroutineFunc::track_memory(SSCoroutineFunc *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rsi
  SSCoroutineFunc *v3; // rbp
  SSParameters *v4; // rbx
  __int64 v5; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdi

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSCoroutineFunc", 0x30u, 0, 0, 0, 1u);
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

