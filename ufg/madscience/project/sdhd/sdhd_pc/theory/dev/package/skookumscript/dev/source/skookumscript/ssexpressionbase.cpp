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
  const void **v2; // rbx
  eSSExprType v3; // edi
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

  v2 = binary_pp;
  v3 = expr_type;
  switch ( expr_type )
  {
    case 1:
      v4 = (SSIdentifier *)AMemory::c_malloc_func(0x10ui64, "SSIdentifier");
      if ( v4 )
        SSIdentifier::SSIdentifier(v4, v2);
      break;
    case 2:
      v5 = (SSIdentifierMember *)AMemory::c_malloc_func(0x18ui64, "SSIdentifierMember");
      if ( v5 )
        SSIdentifierMember::SSIdentifierMember(v5, v2);
      break;
    case 3:
      v6 = (SSIdentifierClassMember *)AMemory::c_malloc_func(0x18ui64, "SSIdentifierClassMember");
      if ( v6 )
        SSIdentifierClassMember::SSIdentifierClassMember(v6, v2);
      break;
    case 4:
      v7 = (SSObjectId *)AMemory::c_malloc_func(0x30ui64, "SSObjectId");
      if ( v7 )
        SSObjectId::SSObjectId(v7, v2);
      break;
    case 5:
      v8 = (SSLiteral *)AMemory::c_malloc_func(0x18ui64, "SSLiteral");
      if ( v8 )
        SSLiteral::SSLiteral(v8, v2);
      break;
    case 6:
      v9 = (SSLiteralList *)AMemory::c_malloc_func(0x20ui64, "SSLiteralList");
      if ( v9 )
        SSLiteralList::SSLiteralList(v9, v2);
      break;
    case 7:
    case 8:
      v10 = UFG::qMalloc(0x18ui64, "SSLiteralClosure", 0i64);
      if ( v10 )
        SSLiteralClosure::SSLiteralClosure((SSLiteralClosure *)v10, v2, v3);
      break;
    case 10:
      v11 = (SSBind *)AMemory::c_malloc_func(0x18ui64, "SSBind");
      if ( v11 )
        SSBind::SSBind(v11, v2);
      break;
    case 11:
      v12 = (SSCast *)AMemory::c_malloc_func(0x18ui64, "SSCast");
      if ( v12 )
        SSCast::SSCast(v12, v2);
      break;
    case 12:
      v13 = (SSConversion *)AMemory::c_malloc_func(0x18ui64, "SSConversion");
      if ( v13 )
        SSConversion::SSConversion(v13, v2);
      break;
    case 13:
      v14 = (SSCode *)AMemory::c_malloc_func(0x28ui64, "SSCode");
      if ( v14 )
        SSCode::SSCode(v14, v2);
      break;
    case 14:
      v15 = (SSConditional *)AMemory::c_malloc_func(0x18ui64, "SSConditional");
      if ( v15 )
        SSConditional::SSConditional(v15, v2);
      break;
    case 15:
      v16 = (SSCase *)AMemory::c_malloc_func(0x20ui64, "SSCase");
      if ( v16 )
        SSCase::SSCase(v16, v2);
      break;
    case 16:
      v17 = (SSLoop *)AMemory::c_malloc_func(0x18ui64, "SSLoop");
      if ( v17 )
        SSLoop::SSLoop(v17, v2);
      break;
    case 17:
      v18 = (SSLoopExit *)AMemory::c_malloc_func(0x10ui64, "SSLoopExit");
      if ( v18 )
        SSLoopExit::SSLoopExit(v18, v2);
      break;
    case 18:
      v19 = (SSInvocation *)AMemory::c_malloc_func(0x18ui64, "SSInvocation");
      if ( v19 )
        SSInvocation::SSInvocation(v19, v2);
      break;
    case 19:
      v20 = (SSInvokeSync *)AMemory::c_malloc_func(0x18ui64, "SSInvokeSync");
      if ( v20 )
        SSInvokeSync::SSInvokeSync(v20, v2);
      break;
    case 20:
      v21 = (SSInvokeRace *)AMemory::c_malloc_func(0x18ui64, "SSInvokeRace");
      if ( v21 )
        SSInvokeRace::SSInvokeRace(v21, v2);
      break;
    case 21:
      v22 = (SSInvokeCascade *)AMemory::c_malloc_func(0x28ui64, "SSInvokeCascade");
      if ( v22 )
        SSInvokeCascade::SSInvokeCascade(v22, v2);
      break;
    case 22:
      v23 = (SSInvokeClosureMethod *)AMemory::c_malloc_func(0x30ui64, "SSInvokeClosureMethod");
      if ( v23 )
        SSInvokeClosureMethod::SSInvokeClosureMethod(v23, v2);
      break;
    case 23:
      v24 = (SSInvokeClosureCoroutine *)AMemory::c_malloc_func(0x30ui64, "SSInvokeClosureCoroutine");
      if ( v24 )
        SSInvokeClosureCoroutine::SSInvokeClosureCoroutine(v24, v2);
      break;
    case 24:
      v25 = (SSInstantiate *)AMemory::c_malloc_func(0x18ui64, "SSInstantiate");
      if ( v25 )
        SSInstantiate::SSInstantiate(v25, v2);
      break;
    case 25:
      v26 = (SSConcurrentSync *)AMemory::c_malloc_func(0x18ui64, "SSConcurrentSync");
      if ( v26 )
        SSConcurrentSync::SSConcurrentSync(v26, v2);
      break;
    case 26:
      v27 = (SSConcurrentRace *)AMemory::c_malloc_func(0x18ui64, "SSConcurrentRace");
      if ( v27 )
        SSConcurrentRace::SSConcurrentRace(v27, v2);
      break;
    case 27:
      v28 = (SSConcurrentBranch *)AMemory::c_malloc_func(0x10ui64, "SSConcurrentBranch");
      if ( v28 )
        SSConcurrentBranch::SSConcurrentBranch(v28, v2);
      break;
    case 28:
      v29 = (SSDivert *)AMemory::c_malloc_func(0x10ui64, "SSDivert");
      if ( v29 )
        SSDivert::SSDivert(v29, v2);
      break;
    default:
      return;
  }
}

// File Line: 708
// RVA: 0x13D530
void __fastcall SSClause::track_memory(SSClause *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rbx
  SSClause *v3; // rdi
  SSExpressionBase *v4; // rcx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSClause", 0x18u, 8u, 0, 0, 1u);
  v4 = v3->i_test_p;
  if ( v4 )
    v4->vfptr->track_memory(v4, v2);
  v3->i_clause_p->vfptr->track_memory(v3->i_clause_p, v2);
}

// File Line: 748
// RVA: 0x1111C0
void __fastcall SSConditional::assign_binary(SSConditional *this, const void **binary_pp)
{
  const void **v2; // rsi
  SSConditional *v3; // rdi
  __int64 v4; // rbx
  SSClause **v5; // rdi
  unsigned __int64 i; // rbp
  SSClause *v7; // rax
  SSClause *v8; // rbx
  eSSExprType v9; // ecx
  signed __int64 v10; // rax
  SSExpressionBase *v11; // rax
  eSSExprType v12; // ecx
  signed __int64 v13; // rax
  SSExpressionBase *v14; // rax

  v2 = binary_pp;
  v3 = this;
  v4 = *(unsigned int *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 4;
  APCompactArrayBase<SSClause>::set_size_free((APCompactArrayBase<SSClause> *)&this->i_clauses.i_count, v4);
  v5 = v3->i_clauses.i_array_p;
  for ( i = (unsigned __int64)&v5[v4]; (unsigned __int64)v5 < i; ++v5 )
  {
    v7 = (SSClause *)AMemory::c_malloc_func(0x18ui64, "SSClause");
    v8 = v7;
    if ( v7 )
    {
      v7->vfptr = (SSClauseVtbl *)&SSClause::`vftable;
      v9 = *(unsigned __int8 *)*v2;
      v10 = (signed __int64)*v2 + 1;
      *v2 = (const void *)v10;
      if ( v9 )
      {
        *v2 = (const void *)(v10 + 2);
        v11 = SSExpressionBase::from_binary_new(v9, v2);
      }
      else
      {
        v11 = 0i64;
      }
      v8->i_test_p = v11;
      v12 = *(unsigned __int8 *)*v2;
      v13 = (signed __int64)*v2 + 1;
      *v2 = (const void *)v13;
      if ( v12 )
      {
        *v2 = (const void *)(v13 + 2);
        v14 = SSExpressionBase::from_binary_new(v12, v2);
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
    *v5 = v8;
  }
}

// File Line: 834
// RVA: 0x115500
SSExpressionBase *__fastcall SSConditional::find_expr_last_no_side_effect(SSConditional *this)
{
  SSClause **v1; // rbx
  unsigned __int64 v2; // rsi
  __int64 v3; // rax
  __int64 v4; // rdi

  v1 = this->i_clauses.i_array_p;
  v2 = (unsigned __int64)&v1[this->i_clauses.i_count];
  if ( (unsigned __int64)v1 >= v2 )
    return 0i64;
  while ( 1 )
  {
    v3 = ((__int64 (*)(void))(*v1)->i_clause_p->vfptr->find_expr_last_no_side_effect)();
    v4 = v3;
    if ( v3 )
    {
      if ( !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v3 + 80i64))(v3) )
        break;
    }
    ++v1;
    if ( (unsigned __int64)v1 >= v2 )
      return 0i64;
  }
  return (SSExpressionBase *)v4;
}

// File Line: 1017
// RVA: 0x11CE70
SSInvokedBase *__fastcall SSConditional::invoke(SSConditional *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSClause **v4; // rbx
  SSInstance **v5; // r14
  unsigned __int64 v6; // rsi
  SSInvokedBase *v7; // rbp
  SSObjectBase *v8; // r15
  SSClause *v9; // rax
  SSExpressionBase *v10; // rcx
  _DWORD *v11; // rcx
  bool v12; // di
  bool v13; // zf
  SSExpressionBase *v15; // rcx
  __int64 v16; // [rsp+40h] [rbp+8h]

  v4 = this->i_clauses.i_array_p;
  v5 = result_pp;
  v6 = (unsigned __int64)&v4[this->i_clauses.i_count];
  v7 = caller_p;
  v8 = scope_p;
  if ( (unsigned __int64)v4 < v6 )
  {
    while ( 1 )
    {
      v9 = *v4;
      v10 = (*v4)->i_test_p;
      if ( !v10 )
        break;
      v10->vfptr->invoke(v10, v8, v7, (SSInstance **)&v16);
      v11 = (_DWORD *)v16;
      v12 = *(_QWORD *)(v16 + 32) != 0i64;
      v13 = *(_DWORD *)(v16 + 16) == 1;
      --v11[4];
      if ( v13 )
      {
        v11[4] = 2147483648;
        (*(void (**)(void))(*(_QWORD *)v11 + 112i64))();
      }
      if ( v12 )
      {
        v9 = *v4;
        break;
      }
      ++v4;
      if ( (unsigned __int64)v4 >= v6 )
        goto LABEL_7;
    }
    v15 = v9->i_clause_p;
    if ( v15 )
      return (SSInvokedBase *)v15->vfptr->invoke(v15, v8, v7, v5);
  }
LABEL_7:
  if ( v5 )
    *v5 = SSBrain::c_nil_p;
  return 0i64;
}

// File Line: 1089
// RVA: 0x11EF00
char __fastcall SSConditional::is_immediate(SSConditional *this, unsigned int *durational_idx_p)
{
  SSClause **v2; // rbx
  unsigned int *v3; // rsi
  unsigned __int64 v4; // rdi

  v2 = this->i_clauses.i_array_p;
  v3 = durational_idx_p;
  v4 = (unsigned __int64)&v2[this->i_clauses.i_count];
  if ( (unsigned __int64)v2 >= v4 )
    return 1;
  while ( (*v2)->i_clause_p->vfptr->is_immediate((*v2)->i_clause_p, v3) )
  {
    ++v2;
    if ( (unsigned __int64)v2 >= v4 )
      return 1;
  }
  return 0;
}

// File Line: 1114
// RVA: 0x13D920
void __fastcall SSConditional::track_memory(SSConditional *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rsi
  SSConditional *v3; // rdi
  SSClause **v4; // rbx
  unsigned __int64 i; // rdi

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(
    mem_stats_p,
    "SSConditional",
    0x18u,
    8u,
    8 * this->i_clauses.i_count,
    8 * this->i_clauses.i_count,
    1u);
  v4 = v3->i_clauses.i_array_p;
  for ( i = (unsigned __int64)&v4[v3->i_clauses.i_count]; (unsigned __int64)v4 < i; ++v4 )
  {
    if ( *v4 )
      (*v4)->vfptr->track_memory(*v4, v2);
  }
}

// File Line: 1138
// RVA: 0x106B60
void __fastcall SSCase::~SSCase(SSCase *this)
{
  SSCase *v1; // rdi
  SSExpressionBase *v2; // rcx

  v1 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSCase::`vftable;
  v2 = this->i_compare_expr_p;
  if ( v2 )
    v2->vfptr->__vecDelDtor(v2, 1u);
  APCompactArrayBase<SSClause>::free_all((APCompactArrayBase<SSClause> *)&v1->i_clauses.i_count);
  AMemory::c_free_func(v1->i_clauses.i_array_p);
  v1->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
}

// File Line: 1159
// RVA: 0x10F9E0
void __fastcall SSCase::assign_binary(SSCase *this, const void **binary_pp)
{
  const void **v2; // rdi
  SSCase *v3; // rsi
  eSSExprType v4; // ecx
  char *v5; // rax
  SSExpressionBase *v6; // rax
  __int64 v7; // rbx
  SSClause **v8; // rsi
  unsigned __int64 i; // rbp
  SSClause *v10; // rax
  SSClause *v11; // rbx
  eSSExprType v12; // ecx
  signed __int64 v13; // rax
  SSExpressionBase *v14; // rax
  eSSExprType v15; // ecx
  signed __int64 v16; // rax
  SSExpressionBase *v17; // rax

  v2 = binary_pp;
  v3 = this;
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
  v3->i_compare_expr_p = v6;
  v7 = *(unsigned int *)*v2;
  *v2 = (char *)*v2 + 4;
  APCompactArrayBase<SSClause>::set_size_free((APCompactArrayBase<SSClause> *)&v3->i_clauses.i_count, v7);
  v8 = v3->i_clauses.i_array_p;
  for ( i = (unsigned __int64)&v8[v7]; (unsigned __int64)v8 < i; ++v8 )
  {
    v10 = (SSClause *)AMemory::c_malloc_func(0x18ui64, "SSClause");
    v11 = v10;
    if ( v10 )
    {
      v10->vfptr = (SSClauseVtbl *)&SSClause::`vftable;
      v12 = *(unsigned __int8 *)*v2;
      v13 = (signed __int64)*v2 + 1;
      *v2 = (const void *)v13;
      if ( v12 )
      {
        *v2 = (const void *)(v13 + 2);
        v14 = SSExpressionBase::from_binary_new(v12, v2);
      }
      else
      {
        v14 = 0i64;
      }
      v11->i_test_p = v14;
      v15 = *(unsigned __int8 *)*v2;
      v16 = (signed __int64)*v2 + 1;
      *v2 = (const void *)v16;
      if ( v15 )
      {
        *v2 = (const void *)(v16 + 2);
        v17 = SSExpressionBase::from_binary_new(v15, v2);
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
    *v8 = v11;
  }
}

// File Line: 1255
// RVA: 0x115460
SSExpressionBase *__fastcall SSCase::find_expr_last_no_side_effect(SSCase *this)
{
  SSClause **v1; // rbx
  unsigned __int64 v2; // rsi
  __int64 v3; // rax
  __int64 v4; // rdi

  v1 = this->i_clauses.i_array_p;
  v2 = (unsigned __int64)&v1[this->i_clauses.i_count];
  if ( (unsigned __int64)v1 >= v2 )
    return 0i64;
  while ( 1 )
  {
    v3 = ((__int64 (*)(void))(*v1)->i_clause_p->vfptr->find_expr_last_no_side_effect)();
    v4 = v3;
    if ( v3 )
    {
      if ( !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v3 + 80i64))(v3) )
        break;
    }
    ++v1;
    if ( (unsigned __int64)v1 >= v2 )
      return 0i64;
  }
  return (SSExpressionBase *)v4;
}

// File Line: 1422
// RVA: 0x119FF0
signed __int64 __fastcall Scaleform::Render::DICommand_Histogram::GetType(SSCase *this)
{
  return 15i64;
}

// File Line: 1446
// RVA: 0x11C820
SSInvokedBase *__fastcall SSCase::invoke(SSCase *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSCase *v4; // r14
  SSInstance **v5; // rbx
  SSInvokedBase *v6; // r12
  SSObjectBase *v7; // rbp
  signed __int64 v8; // rdx
  signed __int64 v9; // r8
  __int64 v10; // r9
  SSObjectBase *v11; // r15
  __int64 v12; // r11
  SSClause *v13; // rdi
  __int64 v14; // rax
  signed __int64 v15; // r10
  _BOOL8 v16; // rcx
  SSMethodBase *v17; // rsi
  SSInvokedMethod *v18; // rax
  SSParameters *v19; // rcx
  SSInvokedMethod *v20; // rbp
  ASymbol *v21; // rcx
  SSClass *v22; // rcx
  unsigned int v23; // eax
  SSData *v24; // rax
  SSClause **v25; // rbx
  unsigned __int64 v26; // r13
  SSClause *v27; // rax
  SSExpressionBase *v28; // rcx
  SSData **v29; // rax
  __int64 v30; // r12
  SSData *v31; // r14
  SSInstance *v32; // rcx
  bool v33; // zf
  _DWORD *v34; // rcx
  bool v35; // r14
  __int64 v36; // rax
  SSInvokedBase *v37; // rbx
  SSInvokedBase *result; // rax
  __int64 v39; // [rsp+20h] [rbp-58h]
  __int64 v40; // [rsp+28h] [rbp-50h]
  SSObjectBase *scope_pa; // [rsp+80h] [rbp+8h]
  SSObjectBase *v42; // [rsp+88h] [rbp+10h]
  SSInvokedBase *v43; // [rsp+90h] [rbp+18h]
  SSInstance **v44; // [rsp+98h] [rbp+20h]

  v44 = result_pp;
  v43 = caller_p;
  v42 = scope_p;
  v4 = this;
  v5 = result_pp;
  v6 = caller_p;
  v7 = scope_p;
  this->i_compare_expr_p->vfptr->invoke(this->i_compare_expr_p, scope_p, caller_p, (SSInstance **)&scope_pa);
  v11 = scope_pa;
  v12 = *(_QWORD *)&scope_pa[1].i_ptr_id;
  v13 = 0i64;
  v14 = *(unsigned int *)(v12 + 112);
  if ( !(_DWORD)v14 )
  {
LABEL_13:
    v17 = 0i64;
    goto LABEL_14;
  }
  v9 = *(_QWORD *)(v12 + 120);
  v15 = v9 + 8 * (v14 - 1);
  while ( 1 )
  {
    v8 = v9 + 8 * ((v15 - v9) >> 4);
    v10 = *(unsigned int *)(*(_QWORD *)v8 + 8i64);
    if ( ASymbol_equals.i_uid < (unsigned int)v10 )
      goto LABEL_8;
    v16 = ASymbol_equals.i_uid == (_DWORD)v10;
    v10 = ASymbol_equals.i_uid != (_DWORD)v10;
    if ( v16 == 1 )
      break;
    if ( v10 < 0 )
    {
LABEL_8:
      if ( v9 == v8 )
        goto LABEL_13;
      v15 = v8 - 8;
    }
    else
    {
      if ( v15 == v8 )
        goto LABEL_13;
      v9 = v8 + 8;
    }
  }
  v17 = *(SSMethodBase **)v8;
  if ( *(_QWORD *)v8 )
    goto LABEL_11;
LABEL_14:
  v22 = *(SSClass **)(v12 + 16);
  if ( v22 )
    v17 = SSClass::get_instance_method_inherited(v22, &ASymbol_equals);
  if ( !v17 )
  {
    v23 = v4->i_clauses.i_count;
    if ( v23 )
      v13 = v4->i_clauses.i_array_p[v23 - 1];
    if ( !v13->i_test_p )
    {
      v13 = (SSClause *)v13->i_clause_p;
      goto LABEL_34;
    }
    goto LABEL_38;
  }
LABEL_11:
  v18 = SSInvokedMethod::pool_new(v6, v11, v17);
  v19 = v17->i_params_p.i_obj_p;
  v20 = v18;
  if ( v19->i_params.i_count )
    v21 = (ASymbol *)*v19->i_params.i_array_p;
  else
    v21 = 0i64;
  v24 = SSData::pool_new(v21 + 2);
  APArray<SSData,ASymbol,ACompareLogical<ASymbol>>::append(
    (APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *)&v20->i_data.i_count,
    v24);
  v25 = v4->i_clauses.i_array_p;
  v26 = (unsigned __int64)&v25[v4->i_clauses.i_count];
  if ( (unsigned __int64)v25 < v26 )
  {
    while ( 1 )
    {
      v27 = *v25;
      v28 = (*v25)->i_test_p;
      if ( !v28 )
        break;
      v28->vfptr->invoke(v28, v42, v6, (SSInstance **)&v39);
      v29 = v20->i_data.i_array_p;
      v30 = v39;
      v31 = *v29;
      v32 = (*v29)->i_data_p;
      v33 = v32->i_ref_count-- == 1;
      if ( v33 )
      {
        v32->i_ref_count = 2147483648;
        ((void (*)(void))v32->vfptr[1].get_scope_context)();
      }
      v31->i_data_p = (SSInstance *)v30;
      v6 = v43;
      ((void (__fastcall *)(SSMethodBase *, SSInvokedMethod *, SSInvokedBase *, __int64 *))v17->vfptr[1].get_custom_expr)(
        v17,
        v20,
        v43,
        &v40);
      v34 = (_DWORD *)v40;
      v35 = *(_QWORD *)(v40 + 32) != 0i64;
      v33 = *(_DWORD *)(v40 + 16) == 1;
      --v34[4];
      if ( v33 )
      {
        v34[4] = 2147483648;
        (*(void (**)(void))(*(_QWORD *)v34 + 112i64))();
      }
      if ( v35 )
      {
        v27 = *v25;
        break;
      }
      ++v25;
      v20->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
      if ( (unsigned __int64)v25 >= v26 )
        goto LABEL_33;
    }
    v13 = (SSClause *)v27->i_clause_p;
  }
LABEL_33:
  SSInvokedMethod::pool_delete(v20);
  v5 = v44;
  v7 = v42;
LABEL_34:
  if ( v13 )
  {
    v36 = ((__int64 (__fastcall *)(SSClause *, SSObjectBase *, SSInvokedBase *, SSInstance **))v13->vfptr[4].track_memory)(
            v13,
            v7,
            v6,
            v5);
    v33 = LODWORD(v11[1].vfptr)-- == 1;
    v37 = (SSInvokedBase *)v36;
    if ( v33 )
    {
      LODWORD(v11[1].vfptr) = 2147483648;
      v11->vfptr[1].get_scope_context(v11);
    }
    result = v37;
  }
  else
  {
LABEL_38:
    v33 = LODWORD(v11[1].vfptr)-- == 1;
    if ( v33 )
    {
      LODWORD(v11[1].vfptr) = 2147483648;
      ((void (__fastcall *)(SSObjectBase *, signed __int64, signed __int64, __int64))v11->vfptr[1].get_scope_context)(
        v11,
        v8,
        v9,
        v10);
    }
    if ( v5 )
      *v5 = SSBrain::c_nil_p;
    result = 0i64;
  }
  return result;
}

// File Line: 1580
// RVA: 0x11EE20
char __fastcall SSCase::is_immediate(SSCase *this, unsigned int *durational_idx_p)
{
  SSClause **v2; // rbx
  unsigned int *v3; // rsi
  unsigned __int64 v4; // rdi

  v2 = this->i_clauses.i_array_p;
  v3 = durational_idx_p;
  v4 = (unsigned __int64)&v2[this->i_clauses.i_count];
  if ( (unsigned __int64)v2 >= v4 )
    return 1;
  while ( (*v2)->i_clause_p->vfptr->is_immediate((*v2)->i_clause_p, v3) )
  {
    ++v2;
    if ( (unsigned __int64)v2 >= v4 )
      return 1;
  }
  return 0;
}

// File Line: 1605
// RVA: 0x13D1C0
void __fastcall SSCase::track_memory(SSCase *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rsi
  SSCase *v3; // rdi
  SSClause **v4; // rbx
  unsigned __int64 i; // rdi

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(
    mem_stats_p,
    "SSCase",
    0x20u,
    8u,
    8 * this->i_clauses.i_count,
    8 * this->i_clauses.i_count,
    1u);
  v3->i_compare_expr_p->vfptr->track_memory(v3->i_compare_expr_p, v2);
  v4 = v3->i_clauses.i_array_p;
  for ( i = (unsigned __int64)&v4[v3->i_clauses.i_count]; (unsigned __int64)v4 < i; ++v4 )
  {
    if ( *v4 )
      (*v4)->vfptr->track_memory(*v4, v2);
  }
}

// File Line: 1802
// RVA: 0x11E610
char __fastcall SSLoop::invoke_iterate(SSLoop *this, SSInvokedExpression *iexpr_p, SSInstance **result_pp)
{
  SSInvokedExpression *v3; // rbx
  SSLoop *v4; // rdi
  SSObjectBase *v5; // rdx
  __int64 v6; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v7; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v8; // rax
  SSInvokedBase *v10; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v11; // r8
  AListNode<SSInvokedBase,SSInvokedBase> *v12; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v13; // rax

  v3 = iexpr_p;
  v4 = this;
  while ( v3->i_data & 1 )
  {
    v5 = v3->i_scope_p.i_obj_p;
    if ( !v5 || v3->i_scope_p.i_ptr_id != v5->i_ptr_id )
    {
      v3->i_data &= 0xFFFFFFFFFFFFFFFEui64;
      break;
    }
    v6 = (__int64)v4->i_expr_p->vfptr->invoke(v4->i_expr_p, v5, (SSInvokedBase *)&v3->vfptr, 0i64);
    if ( v6 )
    {
      v7 = (AListNode<SSInvokedBase,SSInvokedBase> *)(v6 + 16);
      v8 = v3->i_calls.i_sentinel.i_prev_p;
      v3->i_calls.i_sentinel.i_prev_p = v7;
      v8->i_next_p = v7;
      v7->i_prev_p = v8;
      v7->i_next_p = &v3->i_calls.i_sentinel;
      ++v3->i_pending_count;
      return 0;
    }
  }
  v10 = v3->i_caller_p.i_obj_p;
  if ( !v10 || v3->i_caller_p.i_ptr_id != v10->i_ptr_id )
    v10 = 0i64;
  if ( v3->i_data & 2 && v10 && v10->i_pending_count )
  {
    v11 = v3->i_next_p;
    v12 = (AListNode<SSInvokedBase,SSInvokedBase> *)&v3->i_next_p;
    if ( v11 != (AListNode<SSInvokedBase,SSInvokedBase> *)&v3->i_next_p )
    {
      v13 = v3->i_prev_p;
      v11->i_prev_p = v13;
      v13->i_next_p = v11;
      v3->i_prev_p = (AListNode<SSInvokedBase,SSInvokedBase> *)&v3->i_next_p;
      v12->i_next_p = v12;
    }
    LOBYTE(v12) = 1;
    v10->vfptr[1].get_data_by_name((SSObjectBase *)&v10->vfptr, (ASymbol *)v12);
  }
  SSInvokedExpression::pool_delete(v3);
  return 1;
}

// File Line: 1870
// RVA: 0x11DD80
SSInvokedExpression *__fastcall SSLoop::invoke(SSLoop *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInvokedBase *v4; // rsi
  SSInstance **v5; // r14
  SSLoop *v6; // rdi
  SSInvokedExpression *v7; // rax
  SSInvokedExpression *v8; // rbx

  v4 = caller_p;
  v5 = result_pp;
  v6 = this;
  v7 = SSInvokedExpression::pool_new((SSExpressionBase *)&this->vfptr, caller_p, scope_p);
  v8 = v7;
  v7->i_data = 1i64;
  if ( v5 )
    *v5 = SSBrain::c_nil_p;
  if ( v6->vfptr->invoke_iterate((SSExpressionBase *)&v6->vfptr, v7, 0i64) )
    return 0i64;
  if ( v4 )
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
  iexpr_p->i_data &= 0xFFFFFFFFFFFFFFFEui64;
}

// File Line: 1944
// RVA: 0x13E410
void __fastcall SSLoop::track_memory(SSLoop *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rdi
  SSLoop *v3; // rbx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSLoop", 0x18u, 8u, 0, 0, 1u);
  v3->i_expr_p->vfptr->track_memory(v3->i_expr_p, v2);
}

// File Line: 2076
// RVA: 0x11DE10
SSInvokedBase *__fastcall SSLoopExit::invoke(SSLoopExit *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInstance **v4; // r14
  SSInvokedBase *v5; // rbx
  SSInvokedBase *v6; // r15
  __int64 v7; // rax
  signed __int64 v8; // rdx
  SSInvokedBase *v9; // rbp
  __int64 v10; // rsi
  __int64 v11; // rdi
  unsigned int v13; // [rsp+40h] [rbp+8h]

  v4 = result_pp;
  v13 = this->i_name.i_uid;
  v5 = caller_p;
  v6 = 0i64;
  do
  {
    if ( !v5 )
      break;
    v7 = ((__int64 (__fastcall *)(SSInvokedBase *, SSObjectBase *))v5->vfptr[1].get_obj_type)(v5, scope_p);
    v8 = (signed __int64)&v5->i_caller_p;
    v9 = v5;
    v5 = v5->i_caller_p.i_obj_p;
    v10 = v7;
    if ( !v5 || *(_DWORD *)(v8 + 8) != v5->i_ptr_id )
      v5 = 0i64;
    v11 = (*(unsigned __int8 (__fastcall **)(__int64, unsigned int *))(*(_QWORD *)v7 + 64i64))(v7, &v13);
    (*(void (__fastcall **)(__int64, SSInvokedBase *, SSInvokedBase *))(*(_QWORD *)v10 + 104i64))(v10, v9, v6);
    v6 = v9;
  }
  while ( !(_BYTE)v11 );
  if ( v4 )
    *v4 = SSBrain::c_nil_p;
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
  SSConversion *v2; // rbx
  SSExpressionBase *v3; // rcx
  const void **v4; // rdi
  ASymbol *v5; // rax
  eSSExprType v6; // ecx
  signed __int64 v7; // rax
  ASymbol result; // [rsp+30h] [rbp+8h]

  v2 = this;
  v3 = this->i_expr_p;
  v4 = binary_pp;
  if ( v3 )
    v3->vfptr->__vecDelDtor(v3, 1u);
  v5 = ASymbol::create_from_binary(&result, v4);
  v2->i_type_p = SSBrain::get_class(v5);
  v6 = *(unsigned __int8 *)*v4;
  v7 = (signed __int64)*v4 + 1;
  *v4 = (const void *)v7;
  if ( v6 )
  {
    *v4 = (const void *)(v7 + 2);
    v2->i_expr_p = SSExpressionBase::from_binary_new(v6, v4);
  }
  else
  {
    v2->i_expr_p = 0i64;
  }
}

// File Line: 2387
// RVA: 0x11CF40
SSInvokedBase *__fastcall SSConversion::invoke(SSConversion *this, SSObjectBase *scope_p, SSInvokedBase *caller_p, SSInstance **result_pp)
{
  SSInstance **v4; // rsi
  SSInvokedBase *v5; // rbp
  SSObjectBase *v6; // r14
  SSConversion *v7; // rdi
  SSExpressionBase *v8; // rcx
  SSExpressionBaseVtbl *v9; // rax
  _DWORD *v10; // rbx
  SSClass *v11; // rcx
  SSClass *v12; // rdi
  SSClass *v13; // rcx
  bool v14; // zf
  __int64 v16; // [rsp+30h] [rbp-68h]
  __int64 v17; // [rsp+38h] [rbp-60h]
  void **v18; // [rsp+40h] [rbp-58h]
  unsigned int v19; // [rsp+48h] [rbp-50h]
  __int64 v20; // [rsp+50h] [rbp-48h]
  APCompactArrayBase<SSParameterBase> v21; // [rsp+58h] [rbp-40h]
  APCompactArrayBase<SSParameterBase> v22; // [rsp+68h] [rbp-30h]
  SSInstance *v23; // [rsp+B8h] [rbp+20h]

  v17 = -2i64;
  v4 = result_pp;
  v5 = caller_p;
  v6 = scope_p;
  v7 = this;
  v8 = this->i_expr_p;
  v9 = v8->vfptr;
  if ( result_pp )
  {
    v9->invoke(v8, scope_p, caller_p, (SSInstance **)&v16);
    v10 = (_DWORD *)v16;
    v23 = (SSInstance *)v16;
    v11 = *(SSClass **)(v16 + 24);
    v12 = v7->i_type_p;
    if ( v12 != v11 )
    {
      v13 = v11->i_superclass_p;
      if ( !v13 || !SSClass::is_class(v13, v12) )
      {
        v19 = v12->i_name.i_uid;
        v20 = 0i64;
        v21.i_count = 0;
        v21.i_array_p = 0i64;
        v22.i_count = 0;
        v22.i_array_p = 0i64;
        v18 = &SSMethodCall::`vftable;
        (*(void (__fastcall **)(_DWORD *, void ***, SSObjectBase *, SSInvokedBase *, SSInstance **))(*(_QWORD *)v10 + 96i64))(
          v10,
          &v18,
          v6,
          v5,
          &v23);
        v18 = &SSInvokeBase::`vftable;
        APCompactArrayBase<SSParameterBase>::free_all(&v21);
        APCompactArrayBase<SSParameterBase>::free_all(&v22);
        AMemory::c_free_func(v22.i_array_p);
        AMemory::c_free_func(v21.i_array_p);
        v14 = v10[4]-- == 1;
        if ( v14 )
        {
          v10[4] = 2147483648;
          (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v10 + 112i64))(v10);
        }
      }
    }
    *v4 = v23;
  }
  else
  {
    ((void (*)(void))v9->invoke)();
  }
  return 0i64;
}

// File Line: 2451
// RVA: 0x13D9A0
void __fastcall SSConversion::track_memory(SSConversion *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rdi
  SSConversion *v3; // rbx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSConversion", 0x18u, 8u, 0, 0, 1u);
  v3->i_expr_p->vfptr->track_memory(v3->i_expr_p, v2);
}

// File Line: 2487
// RVA: 0x10FB00
void __fastcall SSCast::assign_binary(SSCast *this, const void **binary_pp)
{
  SSCast *v2; // rbx
  SSExpressionBase *v3; // rcx
  const void **v4; // rdi
  eSSClassType v5; // ecx
  SSClassDescBase *v6; // rax
  SSClassDescBase *v7; // rsi
  SSClassDescBase *v8; // rcx
  signed __int64 v9; // rax
  eSSExprType v10; // ecx

  v2 = this;
  v3 = this->i_expr_p;
  v4 = binary_pp;
  if ( v3 )
    v3->vfptr->__vecDelDtor(v3, 1u);
  v5 = *(unsigned __int8 *)*v4;
  *v4 = (char *)*v4 + 1;
  v6 = SSClassDescBase::from_binary_ref(v5, v4);
  v7 = v6;
  if ( v2->i_type_p.i_obj_p != v6 )
  {
    if ( v6 )
      (*(void (__fastcall **)(SSClassDescBase *))v6->vfptr->gap8)(v6);
    v8 = v2->i_type_p.i_obj_p;
    if ( v8 )
      (*(void (**)(void))&v8->vfptr->gap8[8])();
    v2->i_type_p.i_obj_p = v7;
  }
  v9 = (signed __int64)*v4 + 1;
  v10 = *(unsigned __int8 *)*v4;
  *v4 = (const void *)v9;
  if ( v10 )
  {
    *v4 = (const void *)(v9 + 2);
    v2->i_expr_p = SSExpressionBase::from_binary_new(v10, v4);
  }
  else
  {
    v2->i_expr_p = 0i64;
  }
}

// File Line: 2565
// RVA: 0x119F00
_BOOL8 __fastcall SSConversion::get_side_effect(SSIdentifierMember *this)
{
  SSExpressionBase *v1; // rcx

  v1 = this->i_owner_p;
  return v1 && ((unsigned int (*)(void))v1->vfptr->get_side_effect)();
}

// File Line: 2733
// RVA: 0x126AF0
void __fastcall SSIdentifierMember::null_receiver(SSIdentifierMember *this, SSExpressionBase *receiver_p)
{
  SSIdentifierMember *v2; // rax
  SSExpressionBase *v3; // rcx

  v2 = this;
  v3 = this->i_owner_p;
  if ( v3 )
  {
    if ( v3 == receiver_p )
      v2->i_owner_p = 0i64;
    else
      ((void (*)(void))v3->vfptr->null_receiver)();
  }
}

// File Line: 2753
// RVA: 0x13D250
void __fastcall SSCast::track_memory(SSCast *this, AMemoryStats *mem_stats_p)
{
  AMemoryStats *v2; // rdi
  SSCast *v3; // rbx

  v2 = mem_stats_p;
  v3 = this;
  AMemoryStats::track_memory(mem_stats_p, "SSCast", 0x18u, 8u, 0, 0, 1u);
  v3->i_expr_p->vfptr->track_memory(v3->i_expr_p, v2);
}

