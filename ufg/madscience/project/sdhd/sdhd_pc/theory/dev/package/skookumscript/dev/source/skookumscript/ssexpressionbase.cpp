// File Line: 75
// RVA: 0x106FC0
void __fastcall SSExpressionBase::~SSExpressionBase(SSExpressionBase *this)
{
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
}

// File Line: 219
// RVA: 0x116420
void __fastcall SSExpressionBase::from_binary_new(eSSExprType expr_type, const void **binary_pp)
{
  SSIdentifier *v4; // rax
  SSIdentifierMember *v5; // rax
  SSIdentifierClassMember *v6; // rax
  SSObjectId *v7; // rax
  SSLiteral *v8; // rax
  SSLiteralList *v9; // rax
  char *v10; // rax
  SSBind *v11; // rax
  SSCast *v12; // rax
  SSConversion *v13; // rax
  SSCode *v14; // rax
  SSConditional *v15; // rax
  SSCase *v16; // rax
  SSLoop *v17; // rax
  SSLoopExit *v18; // rax
  SSInvocation *v19; // rax
  SSInvokeSync *v20; // rax
  SSInvokeRace *v21; // rax
  SSInvokeCascade *v22; // rax
  SSInvokeClosureMethod *v23; // rax
  SSInvokeClosureCoroutine *v24; // rax
  SSInstantiate *v25; // rax
  SSConcurrentSync *v26; // rax
  SSConcurrentRace *v27; // rax
  SSConcurrentBranch *v28; // rax
  SSDivert *v29; // rax

  switch ( expr_type )
  {
    case SSExprType_identifier:
      v4 = (SSIdentifier *)AMemory::c_malloc_func(0x10ui64, "SSIdentifier");
      if ( v4 )
        SSIdentifier::SSIdentifier(v4, binary_pp);
      break;
    case SSExprType_identifier_member:
      v5 = (SSIdentifierMember *)AMemory::c_malloc_func(0x18ui64, "SSIdentifierMember");
      if ( v5 )
        SSIdentifierMember::SSIdentifierMember(v5, binary_pp);
      break;
    case SSExprType_identifier_class_member:
      v6 = (SSIdentifierClassMember *)AMemory::c_malloc_func(0x18ui64, "SSIdentifierClassMember");
      if ( v6 )
        SSIdentifierClassMember::SSIdentifierClassMember(v6, binary_pp);
      break;
    case SSExprType_object_id:
      v7 = (SSObjectId *)AMemory::c_malloc_func(0x30ui64, "SSObjectId");
      if ( v7 )
        SSObjectId::SSObjectId(v7, binary_pp);
      break;
    case SSExprType_literal:
      v8 = (SSLiteral *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
      if ( v8 )
        SSLiteral::SSLiteral(v8, binary_pp);
      break;
    case SSExprType_literal_list:
      v9 = (SSLiteralList *)AMemory::c_malloc_func(0x20ui64, "SSLiteralList");
      if ( v9 )
        SSLiteralList::SSLiteralList(v9, binary_pp);
      break;
    case SSExprType_closure_method:
    case SSExprType_closure_coroutine:
      v10 = UFG::qMalloc(0x18ui64, "SSLiteralClosure", 0i64);
      if ( v10 )
        SSLiteralClosure::SSLiteralClosure((SSLiteralClosure *)v10, binary_pp, expr_type);
      break;
    case SSExprType_bind:
      v11 = (SSBind *)AMemory::c_malloc_func(0x18ui64, "SSBind");
      if ( v11 )
        SSBind::SSBind(v11, binary_pp);
      break;
    case SSExprType_cast:
      v12 = (SSCast *)AMemory::c_malloc_func(0x18ui64, "SSCast");
      if ( v12 )
        SSCast::SSCast(v12, binary_pp);
      break;
    case SSExprType_conversion:
      v13 = (SSConversion *)AMemory::c_malloc_func(0x18ui64, "SSConversion");
      if ( v13 )
        SSConversion::SSConversion(v13, binary_pp);
      break;
    case SSExprType_code:
      v14 = (SSCode *)AMemory::c_malloc_func(0x28ui64, "SSCode");
      if ( v14 )
        SSCode::SSCode(v14, binary_pp);
      break;
    case SSExprType_conditional:
      v15 = (SSConditional *)AMemory::c_malloc_func(0x18ui64, "SSConditional");
      if ( v15 )
        SSConditional::SSConditional(v15, binary_pp);
      break;
    case SSExprType_case:
      v16 = (SSCase *)AMemory::c_malloc_func(0x20ui64, "SSCase");
      if ( v16 )
        SSCase::SSCase(v16, binary_pp);
      break;
    case SSExprType_loop:
      v17 = (SSLoop *)AMemory::c_malloc_func(0x18ui64, "SSLoop");
      if ( v17 )
        SSLoop::SSLoop(v17, binary_pp);
      break;
    case SSExprType_loop_exit:
      v18 = (SSLoopExit *)AMemory::c_malloc_func(0x10ui64, "SSLoopExit");
      if ( v18 )
        SSLoopExit::SSLoopExit(v18, binary_pp);
      break;
    case SSExprType_invoke:
      v19 = (SSInvocation *)AMemory::c_malloc_func(0x18ui64, "SSInvocation");
      if ( v19 )
        SSInvocation::SSInvocation(v19, binary_pp);
      break;
    case SSExprType_invoke_sync:
      v20 = (SSInvokeSync *)AMemory::c_malloc_func(0x18ui64, "SSInvokeSync");
      if ( v20 )
        SSInvokeSync::SSInvokeSync(v20, binary_pp);
      break;
    case SSExprType_invoke_race:
      v21 = (SSInvokeRace *)AMemory::c_malloc_func(0x18ui64, "SSInvokeRace");
      if ( v21 )
        SSInvokeRace::SSInvokeRace(v21, binary_pp);
      break;
    case SSExprType_invoke_cascade:
      v22 = (SSInvokeCascade *)AMemory::c_malloc_func(0x28ui64, "SSInvokeCascade");
      if ( v22 )
        SSInvokeCascade::SSInvokeCascade(v22, binary_pp);
      break;
    case SSExprType_invoke_closure_method:
      v23 = (SSInvokeClosureMethod *)AMemory::c_malloc_func(0x30ui64, "SSInvokeClosureMethod");
      if ( v23 )
        SSInvokeClosureMethod::SSInvokeClosureMethod(v23, binary_pp);
      break;
    case SSExprType_invoke_closure_coroutine:
      v24 = (SSInvokeClosureCoroutine *)AMemory::c_malloc_func(0x30ui64, "SSInvokeClosureCoroutine");
      if ( v24 )
        SSInvokeClosureCoroutine::SSInvokeClosureCoroutine(v24, binary_pp);
      break;
    case SSExprType_instantiate:
      v25 = (SSInstantiate *)AMemory::c_malloc_func(0x18ui64, "SSInstantiate");
      if ( v25 )
        SSInstantiate::SSInstantiate(v25, binary_pp);
      break;
    case SSExprType_concurrent_sync:
      v26 = (SSConcurrentSync *)AMemory::c_malloc_func(0x18ui64, "SSConcurrentSync");
      if ( v26 )
        SSConcurrentSync::SSConcurrentSync(v26, binary_pp);
      break;
    case SSExprType_concurrent_race:
      v27 = (SSConcurrentRace *)AMemory::c_malloc_func(0x18ui64, "SSConcurrentRace");
      if ( v27 )
        SSConcurrentRace::SSConcurrentRace(v27, binary_pp);
      break;
    case SSExprType_concurrent_branch:
      v28 = (SSConcurrentBranch *)AMemory::c_malloc_func(0x10ui64, "SSConcurrentBranch");
      if ( v28 )
        SSConcurrentBranch::SSConcurrentBranch(v28, binary_pp);
      break;
    case SSExprType_divert:
      v29 = (SSDivert *)AMemory::c_malloc_func(0x10ui64, "SSDivert");
      if ( v29 )
        SSDivert::SSDivert(v29, binary_pp);
      break;
    default:
      return;
  }
}

// File Line: 708
// RVA: 0x13D530
void __fastcall SSClause::track_memory(SSClause *this, AMemoryStats *mem_stats_p)
{
  SSExpressionBase *i_test_p; // rcx

  AMemoryStats::track_memory(mem_stats_p, "SSClause", 0x18u, 8u, 0, 0, 1u);
  i_test_p = this->i_test_p;
  if ( i_test_p )
    i_test_p->vfptr->track_memory(i_test_p, mem_stats_p);
  this->i_clause_p->vfptr->track_memory(this->i_clause_p, mem_stats_p);
}

// File Line: 748
// RVA: 0x1111C0
void __fastcall SSConditional::assign_binary(SSConditional *this, const void **binary_pp)
{
  __int64 v4; // rbx
  SSClause **i_array_p; // rdi
  SSClause **i; // rbp
  SSClause *v7; // rax
  SSClause *v8; // rbx
  eSSExprType v9; // ecx
  char *v10; // rax
  SSExpressionBase *v11; // rax
  eSSExprType v12; // ecx
  char *v13; // rax
  SSExpressionBase *v14; // rax

  v4 = *(unsigned int *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 4;
  APCompactArrayBase<SSClause>::set_size_free(&this->i_clauses, v4);
  i_array_p = this->i_clauses.i_array_p;
  for ( i = &i_array_p[v4]; i_array_p < i; ++i_array_p )
  {
    v7 = (SSClause *)AMemory::c_malloc_func(0x18ui64, "SSClause");
    v8 = v7;
    if ( v7 )
    {
      v7->vfptr = (SSClauseVtbl *)&SSClause::`vftable;
      v9 = *(unsigned __int8 *)*binary_pp;
      v10 = (char *)*binary_pp + 1;
      *binary_pp = v10;
      if ( v9 )
      {
        *binary_pp = v10 + 2;
        v11 = SSExpressionBase::from_binary_new(v9, binary_pp);
      }
      else
      {
        v11 = 0i64;
      }
      v8->i_test_p = v11;
      v12 = *(unsigned __int8 *)*binary_pp;
      v13 = (char *)*binary_pp + 1;
      *binary_pp = v13;
      if ( v12 )
      {
        *binary_pp = v13 + 2;
        v14 = SSExpressionBase::from_binary_new(v12, binary_pp);
      }
      else
      {
        v14 = 0i64;
      }
      v8->i_clause_p = v14;
    }
    else
    {
      v8 = 0i64;
    }
    *i_array_p = v8;
  }
}

// File Line: 834
// RVA: 0x115500
SSExpressionBase *__fastcall SSConditional::find_expr_last_no_side_effect(SSConditional *this)
{
  SSClause **i_array_p; // rbx
  SSClause **v2; // rsi
  __int64 v3; // rax
  __int64 v4; // rdi

  i_array_p = this->i_clauses.i_array_p;
  v2 = &i_array_p[this->i_clauses.i_count];
  if ( i_array_p >= v2 )
    return 0i64;
  while ( 1 )
  {
    v3 = (__int64)(*i_array_p)->i_clause_p->vfptr->find_expr_last_no_side_effect((*i_array_p)->i_clause_p);
    v4 = v3;
    if ( v3 )
    {
      if ( !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v3 + 80i64))(v3) )
        break;
    }
    if ( ++i_array_p >= v2 )
      return 0i64;
  }
  return (SSExpressionBase *)v4;
}

// File Line: 1017
// RVA: 0x11CE70
SSInvokedBase *__fastcall SSConditional::invoke(
        SSConditional *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSClause **i_array_p; // rbx
  SSClause **v6; // rsi
  SSClause *v9; // rax
  SSExpressionBase *i_test_p; // rcx
  _DWORD *v11; // rcx
  bool v12; // di
  SSExpressionBase *i_clause_p; // rcx
  __int64 v16; // [rsp+40h] [rbp+8h] BYREF

  i_array_p = this->i_clauses.i_array_p;
  v6 = &i_array_p[this->i_clauses.i_count];
  if ( i_array_p < v6 )
  {
    while ( 1 )
    {
      v9 = *i_array_p;
      i_test_p = (*i_array_p)->i_test_p;
      if ( !i_test_p )
        break;
      i_test_p->vfptr->invoke(i_test_p, scope_p, caller_p, (SSInstance **)&v16);
      v11 = (_DWORD *)v16;
      v12 = *(_QWORD *)(v16 + 32) != 0i64;
      if ( (*(_DWORD *)(v16 + 16))-- == 1 )
      {
        v11[4] = 0x80000000;
        (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v11 + 112i64))(v11);
      }
      if ( v12 )
      {
        v9 = *i_array_p;
        break;
      }
      if ( ++i_array_p >= v6 )
        goto LABEL_7;
    }
    i_clause_p = v9->i_clause_p;
    if ( i_clause_p )
      return i_clause_p->vfptr->invoke(i_clause_p, scope_p, caller_p, result_pp);
  }
LABEL_7:
  if ( result_pp )
    *result_pp = SSBrain::c_nil_p;
  return 0i64;
}

// File Line: 1089
// RVA: 0x11EF00
char __fastcall SSConditional::is_immediate(SSConditional *this, unsigned int *durational_idx_p)
{
  SSClause **i_array_p; // rbx
  SSClause **v4; // rdi

  i_array_p = this->i_clauses.i_array_p;
  v4 = &i_array_p[this->i_clauses.i_count];
  if ( i_array_p >= v4 )
    return 1;
  while ( (*i_array_p)->i_clause_p->vfptr->is_immediate((*i_array_p)->i_clause_p, durational_idx_p) )
  {
    if ( ++i_array_p >= v4 )
      return 1;
  }
  return 0;
}

// File Line: 1114
// RVA: 0x13D920
void __fastcall SSConditional::track_memory(SSConditional *this, AMemoryStats *mem_stats_p)
{
  SSClause **i_array_p; // rbx
  SSClause **i; // rdi

  AMemoryStats::track_memory(
    mem_stats_p,
    "SSConditional",
    0x18u,
    8u,
    8 * this->i_clauses.i_count,
    8 * this->i_clauses.i_count,
    1u);
  i_array_p = this->i_clauses.i_array_p;
  for ( i = &i_array_p[this->i_clauses.i_count]; i_array_p < i; ++i_array_p )
  {
    if ( *i_array_p )
      (*i_array_p)->vfptr->track_memory(*i_array_p, mem_stats_p);
  }
}

// File Line: 1138
// RVA: 0x106B60
void __fastcall SSCase::~SSCase(SSCase *this)
{
  SSExpressionBase *i_compare_expr_p; // rcx

  this->vfptr = (SSExpressionBaseVtbl *)&SSCase::`vftable;
  i_compare_expr_p = this->i_compare_expr_p;
  if ( i_compare_expr_p )
    i_compare_expr_p->vfptr->__vecDelDtor(i_compare_expr_p, 1u);
  APCompactArrayBase<SSClause>::free_all(&this->i_clauses);
  AMemory::c_free_func(this->i_clauses.i_array_p);
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
}

// File Line: 1159
// RVA: 0x10F9E0
void __fastcall SSCase::assign_binary(SSCase *this, const void **binary_pp)
{
  eSSExprType v4; // ecx
  char *v5; // rax
  SSExpressionBase *v6; // rax
  __int64 v7; // rbx
  SSClause **i_array_p; // rsi
  SSClause **i; // rbp
  SSClause *v10; // rax
  SSClause *v11; // rbx
  eSSExprType v12; // ecx
  char *v13; // rax
  SSExpressionBase *v14; // rax
  eSSExprType v15; // ecx
  char *v16; // rax
  SSExpressionBase *v17; // rax

  v4 = *(unsigned __int8 *)*binary_pp;
  v5 = (char *)*binary_pp + 1;
  *binary_pp = v5;
  if ( v4 )
  {
    *binary_pp = v5 + 2;
    v6 = SSExpressionBase::from_binary_new(v4, binary_pp);
  }
  else
  {
    v6 = 0i64;
  }
  this->i_compare_expr_p = v6;
  v7 = *(unsigned int *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 4;
  APCompactArrayBase<SSClause>::set_size_free(&this->i_clauses, v7);
  i_array_p = this->i_clauses.i_array_p;
  for ( i = &i_array_p[v7]; i_array_p < i; ++i_array_p )
  {
    v10 = (SSClause *)AMemory::c_malloc_func(0x18ui64, "SSClause");
    v11 = v10;
    if ( v10 )
    {
      v10->vfptr = (SSClauseVtbl *)&SSClause::`vftable;
      v12 = *(unsigned __int8 *)*binary_pp;
      v13 = (char *)*binary_pp + 1;
      *binary_pp = v13;
      if ( v12 )
      {
        *binary_pp = v13 + 2;
        v14 = SSExpressionBase::from_binary_new(v12, binary_pp);
      }
      else
      {
        v14 = 0i64;
      }
      v11->i_test_p = v14;
      v15 = *(unsigned __int8 *)*binary_pp;
      v16 = (char *)*binary_pp + 1;
      *binary_pp = v16;
      if ( v15 )
      {
        *binary_pp = v16 + 2;
        v17 = SSExpressionBase::from_binary_new(v15, binary_pp);
      }
      else
      {
        v17 = 0i64;
      }
      v11->i_clause_p = v17;
    }
    else
    {
      v11 = 0i64;
    }
    *i_array_p = v11;
  }
}

// File Line: 1255
// RVA: 0x115460
SSExpressionBase *__fastcall SSCase::find_expr_last_no_side_effect(SSCase *this)
{
  SSClause **i_array_p; // rbx
  SSClause **v2; // rsi
  __int64 v3; // rax
  __int64 v4; // rdi

  i_array_p = this->i_clauses.i_array_p;
  v2 = &i_array_p[this->i_clauses.i_count];
  if ( i_array_p >= v2 )
    return 0i64;
  while ( 1 )
  {
    v3 = (__int64)(*i_array_p)->i_clause_p->vfptr->find_expr_last_no_side_effect((*i_array_p)->i_clause_p);
    v4 = v3;
    if ( v3 )
    {
      if ( !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v3 + 80i64))(v3) )
        break;
    }
    if ( ++i_array_p >= v2 )
      return 0i64;
  }
  return (SSExpressionBase *)v4;
}

// File Line: 1422
// RVA: 0x119FF0
__int64 __fastcall Scaleform::Render::DICommand_Histogram::GetType(SSCase *this)
{
  return 15i64;
}

// File Line: 1446
// RVA: 0x11C820
SSInvokedBase *__fastcall SSCase::invoke(
        SSCase *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInstance **v5; // rbx
  SSInvokedBase *v6; // r12
  SSObjectBase *v7; // rbp
  SSMethodBase **v8; // rdx
  SSMethodBase **v9; // r8
  __int64 i_uid; // r9
  SSObjectBase *v11; // r15
  __int64 v12; // r11
  SSClause *i_clause_p; // rdi
  __int64 v14; // rax
  SSMethodBase **v15; // r10
  _BOOL8 v16; // rcx
  SSMethodBase *instance_method_inherited; // rsi
  SSInvokedMethod *v18; // rax
  SSParameters *i_obj_p; // rcx
  SSInvokedMethod *v20; // rbp
  ASymbol *v21; // rcx
  SSClass *v22; // rcx
  unsigned int i_count; // eax
  SSData *v24; // rax
  SSClause **i_array_p; // rbx
  SSClause **v26; // r13
  SSClause *v27; // rax
  SSExpressionBase *i_test_p; // rcx
  SSData **v29; // rax
  __int64 v30; // r12
  SSData *v31; // r14
  SSInstance *i_data_p; // rcx
  bool v33; // zf
  _DWORD *v34; // rcx
  bool v35; // r14
  __int64 v36; // rax
  __int64 v37; // rbx
  __int64 v39; // [rsp+20h] [rbp-58h] BYREF
  __int64 v40; // [rsp+28h] [rbp-50h] BYREF
  SSObjectBase *scope_pa; // [rsp+80h] [rbp+8h] BYREF
  SSObjectBase *v42; // [rsp+88h] [rbp+10h]
  SSInvokedBase *v43; // [rsp+90h] [rbp+18h]
  SSInstance **v44; // [rsp+98h] [rbp+20h]

  v44 = result_pp;
  v43 = caller_p;
  v42 = scope_p;
  v5 = result_pp;
  v6 = caller_p;
  v7 = scope_p;
  this->i_compare_expr_p->vfptr->invoke(this->i_compare_expr_p, scope_p, caller_p, (SSInstance **)&scope_pa);
  v11 = scope_pa;
  v12 = *(_QWORD *)&scope_pa[1].i_ptr_id;
  i_clause_p = 0i64;
  v14 = *(unsigned int *)(v12 + 112);
  if ( (_DWORD)v14 )
  {
    v9 = *(SSMethodBase ***)(v12 + 120);
    v15 = &v9[v14 - 1];
    while ( 1 )
    {
      while ( 1 )
      {
        v8 = &v9[((char *)v15 - (char *)v9) >> 4];
        i_uid = (*v8)->i_name.i_uid;
        if ( ASymbol_equals.i_uid >= (unsigned int)i_uid )
          break;
        if ( v9 == v8 )
          goto LABEL_12;
        v15 = v8 - 1;
      }
      v16 = ASymbol_equals.i_uid == (_DWORD)i_uid;
      i_uid = ASymbol_equals.i_uid != (_DWORD)i_uid;
      if ( v16 )
        break;
      if ( v15 == v8 )
        goto LABEL_12;
      v9 = v8 + 1;
    }
    instance_method_inherited = *v8;
    if ( *v8 )
      goto LABEL_10;
  }
  else
  {
LABEL_12:
    instance_method_inherited = 0i64;
  }
  v22 = *(SSClass **)(v12 + 16);
  if ( v22 )
    instance_method_inherited = SSClass::get_instance_method_inherited(v22, &ASymbol_equals);
  if ( instance_method_inherited )
  {
LABEL_10:
    v18 = SSInvokedMethod::pool_new(v6, v11, instance_method_inherited);
    i_obj_p = instance_method_inherited->i_params_p.i_obj_p;
    v20 = v18;
    if ( i_obj_p->i_params.i_count )
      v21 = (ASymbol *)*i_obj_p->i_params.i_array_p;
    else
      v21 = 0i64;
    v24 = SSData::pool_new(v21 + 2);
    APArray<SSData,ASymbol,ACompareLogical<ASymbol>>::append(&v20->i_data, v24);
    i_array_p = this->i_clauses.i_array_p;
    v26 = &i_array_p[this->i_clauses.i_count];
    if ( i_array_p < v26 )
    {
      while ( 1 )
      {
        v27 = *i_array_p;
        i_test_p = (*i_array_p)->i_test_p;
        if ( !i_test_p )
          break;
        i_test_p->vfptr->invoke(i_test_p, v42, v6, (SSInstance **)&v39);
        v29 = v20->i_data.i_array_p;
        v30 = v39;
        v31 = *v29;
        i_data_p = (*v29)->i_data_p;
        v33 = i_data_p->i_ref_count-- == 1;
        if ( v33 )
        {
          i_data_p->i_ref_count = 0x80000000;
          i_data_p->vfptr[1].get_scope_context(i_data_p);
        }
        v31->i_data_p = (SSInstance *)v30;
        v6 = v43;
        ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, SSInvokedBase *, __int64 *))instance_method_inherited->vfptr[1].get_custom_expr)(
          instance_method_inherited,
          v20,
          v43,
          &v40);
        v34 = (_DWORD *)v40;
        v35 = *(_QWORD *)(v40 + 32) != 0i64;
        v33 = (*(_DWORD *)(v40 + 16))-- == 1;
        if ( v33 )
        {
          v34[4] = 0x80000000;
          (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v34 + 112i64))(v34);
        }
        if ( v35 )
        {
          v27 = *i_array_p;
          break;
        }
        ++i_array_p;
        v20->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
        if ( i_array_p >= v26 )
          goto LABEL_32;
      }
      i_clause_p = (SSClause *)v27->i_clause_p;
    }
LABEL_32:
    SSInvokedMethod::pool_delete(v20);
    v5 = v44;
    v7 = v42;
    goto LABEL_33;
  }
  i_count = this->i_clauses.i_count;
  if ( i_count )
    i_clause_p = this->i_clauses.i_array_p[i_count - 1];
  if ( i_clause_p->i_test_p )
    goto LABEL_37;
  i_clause_p = (SSClause *)i_clause_p->i_clause_p;
LABEL_33:
  if ( i_clause_p )
  {
    v36 = ((__int64 (__fastcall *)(SSClause *, SSObjectBase *, SSInvokedBase *, SSInstance **))i_clause_p->vfptr[4].track_memory)(
            i_clause_p,
            v7,
            v6,
            v5);
    v33 = LODWORD(v11[1].vfptr)-- == 1;
    v37 = v36;
    if ( v33 )
    {
      LODWORD(v11[1].vfptr) = 0x80000000;
      v11->vfptr[1].get_scope_context(v11);
    }
    return (SSInvokedBase *)v37;
  }
LABEL_37:
  v33 = LODWORD(v11[1].vfptr)-- == 1;
  if ( v33 )
  {
    LODWORD(v11[1].vfptr) = 0x80000000;
    ((void (__fastcall *)(SSObjectBase *, SSMethodBase **, SSMethodBase **, __int64))v11->vfptr[1].get_scope_context)(
      v11,
      v8,
      v9,
      i_uid);
  }
  if ( v5 )
    *v5 = SSBrain::c_nil_p;
  return 0i64;
}

// File Line: 1580
// RVA: 0x11EE20
char __fastcall SSCase::is_immediate(SSCase *this, unsigned int *durational_idx_p)
{
  SSClause **i_array_p; // rbx
  SSClause **v4; // rdi

  i_array_p = this->i_clauses.i_array_p;
  v4 = &i_array_p[this->i_clauses.i_count];
  if ( i_array_p >= v4 )
    return 1;
  while ( (*i_array_p)->i_clause_p->vfptr->is_immediate((*i_array_p)->i_clause_p, durational_idx_p) )
  {
    if ( ++i_array_p >= v4 )
      return 1;
  }
  return 0;
}

// File Line: 1605
// RVA: 0x13D1C0
void __fastcall SSCase::track_memory(SSCase *this, AMemoryStats *mem_stats_p)
{
  SSClause **i_array_p; // rbx
  SSClause **i; // rdi

  AMemoryStats::track_memory(
    mem_stats_p,
    "SSCase",
    0x20u,
    8u,
    8 * this->i_clauses.i_count,
    8 * this->i_clauses.i_count,
    1u);
  this->i_compare_expr_p->vfptr->track_memory(this->i_compare_expr_p, mem_stats_p);
  i_array_p = this->i_clauses.i_array_p;
  for ( i = &i_array_p[this->i_clauses.i_count]; i_array_p < i; ++i_array_p )
  {
    if ( *i_array_p )
      (*i_array_p)->vfptr->track_memory(*i_array_p, mem_stats_p);
  }
}

// File Line: 1802
// RVA: 0x11E610
char __fastcall SSLoop::invoke_iterate(SSLoop *this, SSInvokedExpression *iexpr_p, SSInstance **result_pp)
{
  SSObjectBase *i_obj_p; // rdx
  SSInvokedBase *v6; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v7; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  SSInvokedBase *v10; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // r8
  AListNode<SSInvokedBase,SSInvokedBase> *v12; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v13; // rax

  while ( (iexpr_p->i_data & 1) != 0 )
  {
    i_obj_p = iexpr_p->i_scope_p.i_obj_p;
    if ( !i_obj_p || iexpr_p->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
    {
      iexpr_p->i_data &= ~1ui64;
      break;
    }
    v6 = this->i_expr_p->vfptr->invoke(this->i_expr_p, i_obj_p, iexpr_p, 0i64);
    if ( v6 )
    {
      v7 = &v6->AListNode<SSInvokedBase,SSInvokedBase>;
      i_prev_p = iexpr_p->i_calls.i_sentinel.i_prev_p;
      iexpr_p->i_calls.i_sentinel.i_prev_p = v7;
      i_prev_p->i_next_p = v7;
      v7->i_prev_p = i_prev_p;
      v7->i_next_p = &iexpr_p->i_calls.i_sentinel;
      ++iexpr_p->i_pending_count;
      return 0;
    }
  }
  v10 = iexpr_p->i_caller_p.i_obj_p;
  if ( !v10 || iexpr_p->i_caller_p.i_ptr_id != v10->i_ptr_id )
    v10 = 0i64;
  if ( (iexpr_p->i_data & 2) != 0 && v10 && v10->i_pending_count )
  {
    i_next_p = iexpr_p->i_next_p;
    v12 = &iexpr_p->AListNode<SSInvokedBase,SSInvokedBase>;
    if ( i_next_p != &iexpr_p->AListNode<SSInvokedBase,SSInvokedBase> )
    {
      v13 = iexpr_p->i_prev_p;
      i_next_p->i_prev_p = v13;
      v13->i_next_p = i_next_p;
      iexpr_p->i_prev_p = &iexpr_p->AListNode<SSInvokedBase,SSInvokedBase>;
      v12->i_next_p = v12;
    }
    LOBYTE(v12) = 1;
    v10->vfptr[1].get_data_by_name(v10, (ASymbol *)v12);
  }
  SSInvokedExpression::pool_delete(iexpr_p);
  return 1;
}

// File Line: 1870
// RVA: 0x11DD80
SSInvokedExpression *__fastcall SSLoop::invoke(
        SSLoop *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInvokedExpression *v7; // rax
  SSInvokedExpression *v8; // rbx

  v7 = SSInvokedExpression::pool_new(this, caller_p, scope_p);
  v8 = v7;
  v7->i_data = 1i64;
  if ( result_pp )
    *result_pp = SSBrain::c_nil_p;
  if ( this->vfptr->invoke_iterate(this, v7, 0i64) )
    return 0i64;
  if ( caller_p )
  {
    if ( v8->i_data == 1 )
      v8->i_data = 3i64;
  }
  return v8;
}

// File Line: 1912
// RVA: 0x11E250
void __fastcall SSLoop::invoke_exit(SSLoop *this, SSInvokedExpression *iexpr_p, SSInvokedExpression *sub_exit_p)
{
  iexpr_p->i_data &= ~1ui64;
}

// File Line: 1944
// RVA: 0x13E410
void __fastcall SSLoop::track_memory(SSLoop *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats::track_memory(mem_stats_p, "SSLoop", 0x18u, 8u, 0, 0, 1u);
  this->i_expr_p->vfptr->track_memory(this->i_expr_p, mem_stats_p);
}

// File Line: 2076
// RVA: 0x11DE10
SSInvokedBase *__fastcall SSLoopExit::invoke(
        SSLoopExit *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSInvokedBase *v6; // r15
  __int64 v7; // rax
  AIdPtr<SSInvokedBase> *p_i_caller_p; // rdx
  SSInvokedBase *v9; // rbp
  __int64 v10; // rsi
  char v11; // di
  unsigned int i_uid; // [rsp+40h] [rbp+8h] BYREF

  i_uid = this->i_name.i_uid;
  v6 = 0i64;
  do
  {
    if ( !caller_p )
      break;
    v7 = ((__int64 (__fastcall *)(SSInvokedBase *, SSObjectBase *))caller_p->vfptr[1].get_obj_type)(caller_p, scope_p);
    p_i_caller_p = &caller_p->i_caller_p;
    v9 = caller_p;
    caller_p = caller_p->i_caller_p.i_obj_p;
    v10 = v7;
    if ( !caller_p || p_i_caller_p->i_ptr_id != caller_p->i_ptr_id )
      caller_p = 0i64;
    v11 = (*(__int64 (__fastcall **)(__int64, unsigned int *))(*(_QWORD *)v7 + 64i64))(v7, &i_uid);
    (*(void (__fastcall **)(__int64, SSInvokedBase *, SSInvokedBase *))(*(_QWORD *)v10 + 104i64))(v10, v9, v6);
    v6 = v9;
  }
  while ( !v11 );
  if ( result_pp )
    *result_pp = SSBrain::c_nil_p;
  return 0i64;
}

// File Line: 2144
// RVA: 0x13E470
void __fastcall SSLoopExit::track_memory(SSLoopExit *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats::track_memory(mem_stats_p, "SSLoopExit", 0x10u, 8u, 0, 0, 1u);
}

// File Line: 2178
// RVA: 0x1112B0
void __fastcall SSConversion::assign_binary(SSConversion *this, const void **binary_pp)
{
  SSExpressionBase *i_expr_p; // rcx
  ASymbol *v5; // rax
  eSSExprType v6; // ecx
  char *v7; // rax
  ASymbol result; // [rsp+30h] [rbp+8h] BYREF

  i_expr_p = this->i_expr_p;
  if ( i_expr_p )
    i_expr_p->vfptr->__vecDelDtor(i_expr_p, 1u);
  v5 = ASymbol::create_from_binary(&result, binary_pp);
  this->i_type_p = SSBrain::get_class(v5);
  v6 = *(unsigned __int8 *)*binary_pp;
  v7 = (char *)*binary_pp + 1;
  *binary_pp = v7;
  if ( v6 )
  {
    *binary_pp = v7 + 2;
    this->i_expr_p = SSExpressionBase::from_binary_new(v6, binary_pp);
  }
  else
  {
    this->i_expr_p = 0i64;
  }
}

// File Line: 2387
// RVA: 0x11CF40
SSInvokedBase *__fastcall SSConversion::invoke(
        SSConversion *this,
        SSObjectBase *scope_p,
        SSInvokedBase *caller_p,
        SSInstance **result_pp)
{
  SSExpressionBase *i_expr_p; // rcx
  SSExpressionBaseVtbl *vfptr; // rax
  _DWORD *v10; // rbx
  SSClass *v11; // rcx
  SSClass *i_type_p; // rdi
  SSClass *i_superclass_p; // rcx
  __int64 v16[2]; // [rsp+30h] [rbp-68h] BYREF
  void **v17; // [rsp+40h] [rbp-58h] BYREF
  unsigned int i_uid; // [rsp+48h] [rbp-50h]
  __int64 v19; // [rsp+50h] [rbp-48h]
  APCompactArrayBase<SSParameterBase> v20; // [rsp+58h] [rbp-40h] BYREF
  APCompactArrayBase<SSParameterBase> v21; // [rsp+68h] [rbp-30h] BYREF
  SSInstance *v22; // [rsp+B8h] [rbp+20h] BYREF

  v16[1] = -2i64;
  i_expr_p = this->i_expr_p;
  vfptr = i_expr_p->vfptr;
  if ( result_pp )
  {
    vfptr->invoke(i_expr_p, scope_p, caller_p, (SSInstance **)v16);
    v10 = (_DWORD *)v16[0];
    v22 = (SSInstance *)v16[0];
    v11 = *(SSClass **)(v16[0] + 24);
    i_type_p = this->i_type_p;
    if ( i_type_p != v11 )
    {
      i_superclass_p = v11->i_superclass_p;
      if ( !i_superclass_p || !SSClass::is_class(i_superclass_p, i_type_p) )
      {
        i_uid = i_type_p->i_name.i_uid;
        v19 = 0i64;
        v20.i_count = 0;
        v20.i_array_p = 0i64;
        v21.i_count = 0;
        v21.i_array_p = 0i64;
        v17 = &SSMethodCall::`vftable;
        (*(void (__fastcall **)(_DWORD *, void ***, SSObjectBase *, SSInvokedBase *, SSInstance **))(*(_QWORD *)v10 + 96i64))(
          v10,
          &v17,
          scope_p,
          caller_p,
          &v22);
        v17 = &SSInvokeBase::`vftable;
        APCompactArrayBase<SSParameterBase>::free_all(&v20);
        APCompactArrayBase<SSParameterBase>::free_all(&v21);
        AMemory::c_free_func(v21.i_array_p);
        AMemory::c_free_func(v20.i_array_p);
        if ( v10[4]-- == 1 )
        {
          v10[4] = 0x80000000;
          (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v10 + 112i64))(v10);
        }
      }
    }
    *result_pp = v22;
  }
  else
  {
    ((void (*)(void))vfptr->invoke)();
  }
  return 0i64;
}

// File Line: 2451
// RVA: 0x13D9A0
void __fastcall SSConversion::track_memory(SSConversion *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats::track_memory(mem_stats_p, "SSConversion", 0x18u, 8u, 0, 0, 1u);
  this->i_expr_p->vfptr->track_memory(this->i_expr_p, mem_stats_p);
}

// File Line: 2487
// RVA: 0x10FB00
void __fastcall SSCast::assign_binary(SSCast *this, const void **binary_pp)
{
  SSExpressionBase *i_expr_p; // rcx
  eSSClassType v5; // ecx
  SSClassDescBase *v6; // rax
  SSClassDescBase *v7; // rsi
  SSClassDescBase *i_obj_p; // rcx
  char *v9; // rax
  eSSExprType v10; // ecx

  i_expr_p = this->i_expr_p;
  if ( i_expr_p )
    i_expr_p->vfptr->__vecDelDtor(i_expr_p, 1u);
  v5 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  v6 = SSClassDescBase::from_binary_ref(v5, binary_pp);
  v7 = v6;
  if ( this->i_type_p.i_obj_p != v6 )
  {
    if ( v6 )
      (*(void (__fastcall **)(SSClassDescBase *))v6->vfptr->gap8)(v6);
    i_obj_p = this->i_type_p.i_obj_p;
    if ( i_obj_p )
      (*(void (__fastcall **)(SSClassDescBase *))&i_obj_p->vfptr->gap8[8])(i_obj_p);
    this->i_type_p.i_obj_p = v7;
  }
  v9 = (char *)*binary_pp + 1;
  v10 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = v9;
  if ( v10 )
  {
    *binary_pp = v9 + 2;
    this->i_expr_p = SSExpressionBase::from_binary_new(v10, binary_pp);
  }
  else
  {
    this->i_expr_p = 0i64;
  }
}

// File Line: 2565
// RVA: 0x119F00
_BOOL8 __fastcall SSConversion::get_side_effect(SSIdentifierMember *this)
{
  SSExpressionBase *i_owner_p; // rcx

  i_owner_p = this->i_owner_p;
  return i_owner_p && i_owner_p->vfptr->get_side_effect(i_owner_p);
}

// File Line: 2733
// RVA: 0x126AF0
void __fastcall SSIdentifierMember::null_receiver(SSIdentifierMember *this, SSExpressionBase *receiver_p)
{
  SSExpressionBase *i_owner_p; // rcx

  i_owner_p = this->i_owner_p;
  if ( i_owner_p )
  {
    if ( i_owner_p == receiver_p )
      this->i_owner_p = 0i64;
    else
      ((void (__fastcall *)(SSExpressionBase *))i_owner_p->vfptr->null_receiver)(i_owner_p);
  }
}

// File Line: 2753
// RVA: 0x13D250
void __fastcall SSCast::track_memory(SSCast *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats::track_memory(mem_stats_p, "SSCast", 0x18u, 8u, 0, 0, 1u);
  this->i_expr_p->vfptr->track_memory(this->i_expr_p, mem_stats_p);
}

