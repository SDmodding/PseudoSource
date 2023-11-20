// File Line: 39
// RVA: 0x106DB0
void __fastcall SSClosureInfoBase::~SSClosureInfoBase(SSClosureInfoBase *this)
{
  this->vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoBase::`vftable';
  AMemory::c_free_func(this->i_captured.i_array_p);
}

// File Line: 52
// RVA: 0x1046F0
void __fastcall SSClosureInfoBase::SSClosureInfoBase(SSClosureInfoBase *this, SSClosureInfoBase *closure_p)
{
  SSClosureInfoBase *v2; // r14
  ASymbol *v3; // rdi
  __int64 v4; // rsi
  AVCompactSortedLogical<ASymbol,ASymbol> *v5; // rbx
  ASymbol *v6; // r8
  ASymbol *v7; // rdx
  unsigned __int64 v8; // r9

  v2 = this;
  this->i_ref_count = 0;
  this->vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoBase::`vftable';
  v3 = closure_p->i_captured.i_array_p;
  v4 = closure_p->i_captured.i_count;
  closure_p->i_captured.i_count = 0;
  closure_p->i_captured.i_array_p = 0i64;
  v5 = &this->i_captured;
  v6 = AVCompactArrayBase<ASymbol>::alloc_array(v4);
  v5->i_count = v4;
  v2->i_captured.i_array_p = v6;
  if ( (_DWORD)v4 )
  {
    v7 = v3;
    v8 = (unsigned __int64)&v3[v4];
    if ( (unsigned __int64)v3 < v8 )
    {
      do
      {
        if ( v6 )
          v6->i_uid = v7->i_uid;
        ++v6;
        ++v7;
      }
      while ( (unsigned __int64)v7 < v8 );
    }
  }
  AMemory::c_free_func(v3);
}

// File Line: 72
// RVA: 0x104650
void __fastcall SSClosureInfoBase::SSClosureInfoBase(SSClosureInfoBase *this, const void **binary_pp)
{
  const void **v2; // r14
  SSClosureInfoBase *v3; // rsi
  AVCompactSortedLogical<ASymbol,ASymbol> *v4; // rbx
  unsigned int v5; // edi
  ASymbol *v6; // rax
  __int64 v7; // rdx
  ASymbol *v8; // rcx
  unsigned int *v9; // r8
  AVCompactSortedLogical<ASymbol,ASymbol> *result; // [rsp+68h] [rbp+10h]
  AVCompactSortedLogical<ASymbol,ASymbol> *v11; // [rsp+70h] [rbp+18h]
  ASymbol *v12; // [rsp+78h] [rbp+20h]

  v2 = binary_pp;
  v3 = this;
  this->i_ref_count = 0;
  this->vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoBase::`vftable';
  v4 = &this->i_captured;
  result = v4;
  v4->i_count = 0;
  v4->i_array_p = 0i64;
  v5 = *(_DWORD *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 4;
  AVCompactArrayBase<ASymbol>::empty_ensure_count_undef((AVCompactArrayBase<ASymbol> *)&this->i_captured.i_count, v5);
  if ( v5 )
  {
    v11 = &v3->i_captured;
    do
    {
      v6 = ASymbol::create_from_binary((ASymbol *)&result, v2);
      v7 = v4->i_count;
      v8 = v3->i_captured.i_array_p;
      v9 = &v8[v7].i_uid;
      v12 = &v8[v7];
      if ( v9 )
        *v9 = v6->i_uid;
      ++v4->i_count;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 215
// RVA: 0x1049D0
void __fastcall SSClosureInfoMethod::SSClosureInfoMethod(SSClosureInfoMethod *this, SSClosureInfoMethod *closure_p)
{
  SSClosureInfoMethod *v2; // rdi
  SSClosureInfoMethod *v3; // rbx
  SSParameters *v4; // r10
  SSExpressionBase *v5; // rcx
  SSClass *v6; // r8
  signed __int64 v7; // r9

  v2 = closure_p;
  v3 = this;
  SSClosureInfoBase::SSClosureInfoBase((SSClosureInfoBase *)&this->vfptr, (SSClosureInfoBase *)&closure_p->vfptr);
  v4 = v2->i_params_p.i_obj_p;
  v5 = v2->i_expr_p;
  v6 = v2->i_scope_p;
  v7 = (signed __int64)&v3->vfptr;
  *(_DWORD *)(v7 + 8) = v2->i_name.i_uid;
  *(_QWORD *)(v7 + 16) = v6;
  *(_QWORD *)v7 = &SSInvokableBase::`vftable';
  *(_QWORD *)(v7 + 24) = v4;
  if ( v4 )
    ++v4->i_ref_count;
  *(_QWORD *)v7 = &SSMethodBase::`vftable';
  *(_QWORD *)v7 = &SSMethod::`vftable';
  v3->i_expr_p = v5;
  v3->vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoMethod::`vftable'{for `SSClosureInfoBase'};
  *(_QWORD *)v7 = &SSClosureInfoMethod::`vftable'{for `SSMethod'};
  v2->i_expr_p = 0i64;
}

// File Line: 224
// RVA: 0x106DF0
void __fastcall SSClosureInfoMethod::~SSClosureInfoMethod(SSClosureInfoMethod *this)
{
  SSClosureInfoMethod *v1; // rbx
  SSMethod *v2; // rcx

  v1 = this;
  this->vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoMethod::`vftable'{for `SSClosureInfoBase'};
  v2 = (SSMethod *)&this->vfptr;
  v2->vfptr = (SSInvokableBaseVtbl *)&SSClosureInfoMethod::`vftable'{for `SSMethod'};
  SSMethod::~SSMethod(v2);
  v1->vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoBase::`vftable';
  AMemory::c_free_func(v1->i_captured.i_array_p);
}

// File Line: 250
// RVA: 0x104910
void __fastcall SSClosureInfoMethod::SSClosureInfoMethod(SSClosureInfoMethod *this, const void **binary_pp)
{
  const void **v2; // rsi
  SSClosureInfoMethod *v3; // r14
  SSExpressionBase *v4; // rdi
  eSSExprType v5; // ecx
  signed __int64 v6; // rax
  signed __int64 v7; // [rsp+58h] [rbp+10h]

  v2 = binary_pp;
  v3 = this;
  SSClosureInfoBase::SSClosureInfoBase((SSClosureInfoBase *)&this->vfptr, binary_pp);
  v7 = (signed __int64)&v3->vfptr;
  *(ASymbol *)(v7 + 8) = ASymbol_closure;
  v4 = 0i64;
  *(_QWORD *)(v7 + 16) = 0i64;
  *(_QWORD *)v7 = &SSInvokableBase::`vftable';
  *(_QWORD *)(v7 + 24) = 0i64;
  *(_QWORD *)v7 = &SSMethodBase::`vftable';
  *(_QWORD *)v7 = &SSMethod::`vftable';
  v3->i_expr_p = 0i64;
  v3->vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoMethod::`vftable'{for `SSClosureInfoBase'};
  *(_QWORD *)v7 = &SSClosureInfoMethod::`vftable'{for `SSMethod'};
  SSCoroutineBase::assign_binary((SSMethodBase *)&v3->vfptr, v2);
  v5 = *(unsigned __int8 *)*v2;
  v6 = (signed __int64)*v2 + 1;
  *v2 = (const void *)v6;
  if ( v5 )
  {
    *v2 = (const void *)(v6 + 2);
    v4 = SSExpressionBase::from_binary_new(v5, v2);
  }
  v3->i_expr_p = v4;
}

// File Line: 268
// RVA: 0x13D650
void __fastcall SSClosureInfoMethod::track_memory(SSClosureInfoMethod *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rsi
  SSClosureInfoMethod *v3; // rbp
  SSParameters *v4; // rbx
  __int64 v5; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdi

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSClosureInfoMethod", 0x48u, 0, 0, 0, 1u);
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

// File Line: 314
// RVA: 0x104860
void __fastcall SSClosureInfoCoroutine::SSClosureInfoCoroutine(SSClosureInfoCoroutine *this, SSClosureInfoMethod *closure_p)
{
  SSClosureInfoMethod *v2; // rbp
  SSClosureInfoCoroutine *v3; // rsi
  SSParameters *v4; // rdi
  SSClass *v5; // rbx
  __int64 v6; // rax
  signed __int64 v7; // rdx

  v2 = closure_p;
  v3 = this;
  SSClosureInfoBase::SSClosureInfoBase((SSClosureInfoBase *)&this->vfptr, (SSClosureInfoBase *)&closure_p->vfptr);
  v4 = v2->i_params_p.i_obj_p;
  v5 = v2->i_scope_p;
  v6 = ((__int64 (__cdecl *)(SSInvokableBaseVtbl **))v2->vfptr->get_custom_expr)(&v2->vfptr);
  v7 = (signed __int64)&v3->vfptr;
  *(_DWORD *)(v7 + 8) = v2->i_name.i_uid;
  *(_QWORD *)(v7 + 16) = v5;
  *(_QWORD *)v7 = &SSInvokableBase::`vftable';
  *(_QWORD *)(v7 + 24) = v4;
  if ( v4 )
    ++v4->i_ref_count;
  *(_QWORD *)v7 = &SSCoroutineBase::`vftable';
  *(_QWORD *)v7 = &SSCoroutine::`vftable';
  v3->i_expr_p = (SSExpressionBase *)v6;
  v3->vfptr = (SSClosureInfoBaseVtbl *)&SSClosureInfoCoroutine::`vftable'{for `SSClosureInfoBase'};
  *(_QWORD *)v7 = &SSClosureInfoCoroutine::`vftable'{for `SSCoroutine'};
  v2->i_expr_p = 0i64;
}

// File Line: 348
// RVA: 0x1047A0
void __fastcall SSClosureInfoCoroutine::SSClosureInfoCoroutine(SSClosureInfoCoroutine *this, const void **binary_pp)
{
  const void **v2; // rsi
  SSMethodBase *v3; // r14
  SSExpressionBase *v4; // rdi
  eSSExprType v5; // ecx
  signed __int64 v6; // rax
  signed __int64 v7; // [rsp+58h] [rbp+10h]

  v2 = binary_pp;
  v3 = (SSMethodBase *)this;
  SSClosureInfoBase::SSClosureInfoBase((SSClosureInfoBase *)&this->vfptr, binary_pp);
  v7 = (signed __int64)&v3[1];
  *(ASymbol *)(v7 + 8) = ASymbol__closure;
  v4 = 0i64;
  *(_QWORD *)(v7 + 16) = 0i64;
  *(_QWORD *)v7 = &SSInvokableBase::`vftable';
  *(_QWORD *)(v7 + 24) = 0i64;
  *(_QWORD *)v7 = &SSCoroutineBase::`vftable';
  *(_QWORD *)v7 = &SSCoroutine::`vftable';
  v3[2].vfptr = 0i64;
  v3->vfptr = (SSInvokableBaseVtbl *)&SSClosureInfoCoroutine::`vftable'{for `SSClosureInfoBase'};
  *(_QWORD *)v7 = &SSClosureInfoCoroutine::`vftable'{for `SSCoroutine'};
  SSCoroutineBase::assign_binary(v3 + 1, v2);
  v5 = *(unsigned __int8 *)*v2;
  v6 = (signed __int64)*v2 + 1;
  *v2 = (const void *)v6;
  if ( v5 )
  {
    *v2 = (const void *)(v6 + 2);
    v4 = SSExpressionBase::from_binary_new(v5, v2);
  }
  v3[2].vfptr = (SSInvokableBaseVtbl *)v4;
}

// File Line: 366
// RVA: 0x13D5A0
void __fastcall SSClosureInfoCoroutine::track_memory(SSClosureInfoCoroutine *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rsi
  SSClosureInfoCoroutine *v3; // rbp
  SSParameters *v4; // rbx
  __int64 v5; // rax
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdi

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSClosureInfoCoroutine", 0x48u, 0, 0, 0, 1u);
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

// File Line: 406
// RVA: 0x1073F0
void __fastcall SSLiteralClosure::~SSLiteralClosure(SSLiteralClosure *this)
{
  SSLiteralClosure *v1; // rbx
  SSExpressionBase *v2; // rcx
  SSClosureInfoBase *v3; // rax
  bool v4; // zf

  v1 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSLiteralClosure::`vftable';
  v2 = this->i_receiver_p;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  v3 = v1->i_info_p.i_obj_p;
  if ( v3 )
  {
    v4 = v3->i_ref_count-- == 1;
    if ( v4 )
    {
      v3->i_ref_count = 2147483648;
      if ( v3 != (SSClosureInfoBase *)-8i64 && &v3->i_ref_count != (unsigned int *)8 )
        v3->vfptr->__vecDelDtor(v3, 1u);
    }
  }
  v1->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
}

// File Line: 422
// RVA: 0x105CA0
void __fastcall SSLiteralClosure::SSLiteralClosure(SSLiteralClosure *this, SSLiteralClosure *closure_method_p, eSSExprType type)
{
  SSLiteralClosure *v3; // rsi
  SSLiteralClosure *v4; // rdi
  SSClosureInfoMethod *v5; // rbx
  SSClosureInfoMethod *v6; // rax
  SSClosureInfoBase *v7; // rax
  SSClosureInfoBase *v8; // rbx
  SSClosureInfoCoroutine *v9; // rax
  SSClosureInfoBase *v10; // rax
  SSClosureInfoBase *v11; // rax
  bool v12; // zf
  SSClosureInfoBase *v13; // rax

  v3 = closure_method_p;
  v4 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSLiteralClosure::`vftable';
  this->i_receiver_p = closure_method_p->i_receiver_p;
  this->i_info_p.i_obj_p = 0i64;
  v5 = (SSClosureInfoMethod *)closure_method_p->i_info_p.i_obj_p;
  if ( type == 7 )
  {
    v6 = (SSClosureInfoMethod *)AMemory::c_malloc_func(0x48ui64, "SSClosureInfoMethod");
    if ( v6 )
    {
      SSClosureInfoMethod::SSClosureInfoMethod(v6, v5);
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
      SSClosureInfoCoroutine::SSClosureInfoCoroutine(v9, v5);
      v8 = v10;
    }
    else
    {
      v8 = 0i64;
    }
  }
  if ( v4->i_info_p.i_obj_p != v8 )
  {
    if ( v8 )
      ++v8->i_ref_count;
    v11 = v4->i_info_p.i_obj_p;
    if ( v11 )
    {
      v12 = v11->i_ref_count-- == 1;
      if ( v12 )
      {
        v11->i_ref_count = 2147483648;
        if ( v11 != (SSClosureInfoBase *)-8i64 && &v11->i_ref_count != (unsigned int *)8 )
          v11->vfptr->__vecDelDtor(v11, 1u);
      }
    }
    v4->i_info_p.i_obj_p = v8;
  }
  v3->i_receiver_p = 0i64;
  v13 = v3->i_info_p.i_obj_p;
  if ( v13 )
  {
    v12 = v13->i_ref_count-- == 1;
    if ( v12 )
    {
      v13->i_ref_count = 2147483648;
      if ( v13 != (SSClosureInfoBase *)-8i64 && &v13->i_ref_count != (unsigned int *)8 )
        v13->vfptr->__vecDelDtor(v13, 1u);
    }
    v3->i_info_p.i_obj_p = 0i64;
  }
}

// File Line: 455
// RVA: 0x105B90
void __fastcall SSLiteralClosure::SSLiteralClosure(SSLiteralClosure *this, const void **binary_pp, eSSExprType type)
{
  eSSExprType v3; // ebp
  const void **v4; // rsi
  SSLiteralClosure *v5; // rdi
  eSSExprType v6; // ecx
  char *v7; // rax
  SSClosureInfoBase *v8; // rbx
  SSExpressionBase *v9; // rax
  SSClosureInfoMethod *v10; // rax
  SSClosureInfoBase *v11; // rax
  SSClosureInfoCoroutine *v12; // rax
  SSClosureInfoBase *v13; // rax
  SSClosureInfoBase *v14; // rax
  bool v15; // zf

  v3 = type;
  v4 = binary_pp;
  v5 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSLiteralClosure::`vftable';
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
  v5->i_receiver_p = v9;
  v5->i_info_p.i_obj_p = 0i64;
  if ( v3 == 7 )
  {
    v10 = (SSClosureInfoMethod *)AMemory::c_malloc_func(0x48ui64, "SSClosureInfoMethod");
    if ( v10 )
    {
      SSClosureInfoMethod::SSClosureInfoMethod(v10, v4);
      v8 = v11;
    }
  }
  else
  {
    v12 = (SSClosureInfoCoroutine *)AMemory::c_malloc_func(0x48ui64, "SSClosureInfoCoroutine");
    if ( v12 )
    {
      SSClosureInfoCoroutine::SSClosureInfoCoroutine(v12, v4);
      v8 = v13;
    }
  }
  if ( v5->i_info_p.i_obj_p != v8 )
  {
    if ( v8 )
      ++v8->i_ref_count;
    v14 = v5->i_info_p.i_obj_p;
    if ( v14 )
    {
      v15 = v14->i_ref_count-- == 1;
      if ( v15 )
      {
        v14->i_ref_count = 2147483648;
        if ( v14 != (SSClosureInfoBase *)-8i64 && &v14->i_ref_count != (unsigned int *)8 )
          v14->vfptr->__vecDelDtor(v14, 1u);
      }
    }
    v5->i_info_p.i_obj_p = v8;
  }
}

// File Line: 531
// RVA: 0x119F30
_BOOL8 __fastcall SSLiteralClosure::get_side_effect(SSLiteralClosure *this)
{
  SSExpressionBase *v1; // rcx

  v1 = this->i_receiver_p;
  return v1 && ((unsigned int (*)(void))v1->vfptr->get_side_effect)();
}

// File Line: 767
// RVA: 0x11DA90
SSInvokedBase *__fastcall SSLiteralClosure::invoke(SSLiteralClosure *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSClosureInfoBase *v4; // rsi
  SSLiteralClosure *v5; // r15
  SSExpressionBase *v6; // rcx
  SSInstance **v7; // rbx
  SSObjectBase *v8; // r14
  SSInstance *v9; // rdi
  SSClosure *v10; // rax
  __int64 v11; // rcx
  ASymbol *v12; // rsi
  unsigned __int64 v13; // rbx
  unsigned __int64 v14; // rbp
  __int64 v15; // rax
  bool v16; // zf
  SSInstance *receiver_p; // [rsp+40h] [rbp+8h]

  v4 = this->i_info_p.i_obj_p;
  v5 = this;
  v6 = this->i_receiver_p;
  v7 = result_pp;
  v8 = scope_p;
  if ( v6 )
  {
    v6->vfptr->invoke(v6, scope_p, caller_p, &receiver_p);
    v9 = receiver_p;
  }
  else
  {
    v9 = (SSInstance *)((__int64 (__fastcall *)(SSObjectBase *, SSObjectBase *, SSInvokedBase *))scope_p->vfptr->get_topmost_scope)(
                         scope_p,
                         scope_p,
                         caller_p);
  }
  if ( v7 )
  {
    v10 = SSClosure::pool_new(v4, v9);
    *v7 = (SSInstance *)&v10->vfptr;
    v11 = v4->i_captured.i_count;
    if ( (_DWORD)v11 )
    {
      v12 = v4->i_captured.i_array_p;
      v13 = (unsigned __int64)&v10[1];
      v14 = (unsigned __int64)&v10[1] + 8 * v11;
      if ( (unsigned __int64)&v10[1] < v14 )
      {
        do
        {
          v15 = (__int64)v8->vfptr->get_data_by_name(v8, v12);
          v13 += 8i64;
          ++v12;
          *(_QWORD *)(v13 - 8) = v15;
          ++*(_DWORD *)(v15 + 16);
        }
        while ( v13 < v14 );
      }
    }
  }
  if ( v5->i_receiver_p )
  {
    v16 = v9->i_ref_count-- == 1;
    if ( v16 )
    {
      v9->i_ref_count = 2147483648;
      v9->vfptr[1].get_scope_context((SSObjectBase *)&v9->vfptr);
    }
  }
  return 0i64;
}

// File Line: 844
// RVA: 0x13E300
void __fastcall SSLiteralClosure::track_memory(SSLiteralClosure *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rbx
  SSLiteralClosure *v3; // rdi
  SSExpressionBase *v4; // rcx
  SSClosureInfoBase *v5; // rcx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSLiteralClosure", 0x18u, 8u, 0, 0, 1u);
  v4 = v3->i_receiver_p;
  if ( v4 )
    v4->vfptr->track_memory(v4, v2);
  v5 = v3->i_info_p.i_obj_p;
  if ( v5 )
    v5->vfptr->track_memory(v5, v2);
}

