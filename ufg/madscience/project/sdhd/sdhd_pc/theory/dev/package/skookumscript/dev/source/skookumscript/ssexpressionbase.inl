// File Line: 160
// RVA: 0x11A050
SSActor *__fastcall SSExpressionBase::get_updater(SSExpressionBase *this, SSInvokedExpression *iexpr)
{
  SSInvokedBase *v2; // rcx
  SSActor *result; // rax

  v2 = iexpr->i_caller_p.i_obj_p;
  if ( v2 && iexpr->i_caller_p.i_ptr_id == v2->i_ptr_id )
    result = (SSActor *)((__int64 (*)(void))v2->vfptr[1].is_actor)();
  else
    result = 0i64;
  return result;
}

// File Line: 220
// RVA: 0x11E3E0
char __fastcall SSExpressionBase::invoke_iterate(SSExpressionBase *this, SSInvokedExpression *iexpr_p, SSInstance **result_pp)
{
  SSInvokedBase *v3; // rcx
  SSInvokedExpression *v4; // rbx
  AListNode<SSInvokedBase,SSInvokedBase> *v5; // r8
  AListNode<SSInvokedBase,SSInvokedBase> *v6; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v7; // rax

  v3 = iexpr_p->i_caller_p.i_obj_p;
  v4 = iexpr_p;
  if ( v3 && iexpr_p->i_caller_p.i_ptr_id == v3->i_ptr_id && v3->i_pending_count )
  {
    v5 = iexpr_p->i_next_p;
    v6 = (AListNode<SSInvokedBase,SSInvokedBase> *)&iexpr_p->i_next_p;
    if ( v5 != v6 )
    {
      v7 = v6->i_prev_p;
      v5->i_prev_p = v7;
      v7->i_next_p = v5;
      v6->i_prev_p = v6;
      v6->i_next_p = v6;
    }
    LOBYTE(v6) = 1;
    v3->vfptr[1].get_data_by_name((SSObjectBase *)&v3->vfptr, (ASymbol *)v6);
  }
  SSInvokedExpression::pool_delete(v4);
  return 1;
}

// File Line: 260
// RVA: 0x104C90
void __fastcall SSConditional::SSConditional(SSConditional *this, const void **binary_pp)
{
  APCompactArrayFree<SSClause,SSClause,ACompareAddress<SSClause> > *v2; // [rsp+50h] [rbp+18h]

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSConditional::`vftable';
  v2 = &this->i_clauses;
  v2->i_count = 0;
  v2->i_array_p = 0i64;
  SSConditional::assign_binary(this, binary_pp);
}

// File Line: 288
// RVA: 0x1042F0
void __fastcall SSCase::SSCase(SSCase *this, const void **binary_pp)
{
  APCompactArrayFree<SSClause,SSClause,ACompareAddress<SSClause> > *v2; // [rsp+50h] [rbp+18h]

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSCase::`vftable';
  v2 = &this->i_clauses;
  v2->i_count = 0;
  v2->i_array_p = 0i64;
  SSCase::assign_binary(this, binary_pp);
}

// File Line: 317
// RVA: 0x105ED0
void __fastcall SSLoop::SSLoop(SSLoop *this, const void **binary_pp)
{
  const void **v2; // rdi
  SSLoop *v3; // rbx
  eSSExprType v4; // ecx
  signed __int64 v5; // rax
  SSExpressionBase *v6; // rax

  v2 = binary_pp;
  v3 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSLoop::`vftable';
  ASymbol::create_from_binary(&this->i_name, binary_pp);
  v4 = *(unsigned __int8 *)*v2;
  v5 = (signed __int64)*v2 + 1;
  *v2 = (const void *)v5;
  if ( v4 )
  {
    *v2 = (const void *)(v5 + 2);
    v6 = SSExpressionBase::from_binary_new(v4, v2);
  }
  else
  {
    v6 = 0i64;
  }
  v3->i_expr_p = v6;
}

// File Line: 345
// RVA: 0x105F40
void __fastcall SSLoopExit::SSLoopExit(SSLoopExit *this, const void **binary_pp)
{
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSLoopExit::`vftable';
  ASymbol::create_from_binary(&this->i_name, binary_pp);
}

// File Line: 385
// RVA: 0x104CE0
void __fastcall SSConversion::SSConversion(SSConversion *this, const void **binary_pp)
{
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSConversion::`vftable';
  this->i_type_p = 0i64;
  this->i_expr_p = 0i64;
  SSConversion::assign_binary(this, binary_pp);
}

// File Line: 408
// RVA: 0x104390
void __fastcall SSCast::SSCast(SSCast *this, SSClassDescBase *type_p, SSExpressionBase *expr_p)
{
  SSExpressionBase *v3; // rdi
  SSCast *v4; // rbx

  v3 = expr_p;
  v4 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSCast::`vftable';
  this->i_type_p.i_obj_p = type_p;
  if ( type_p )
    (*(void (__fastcall **)(SSClassDescBase *))type_p->vfptr->gap8)(type_p);
  v4->i_expr_p = v3;
}

// File Line: 426
// RVA: 0x104340
void __fastcall SSCast::SSCast(SSCast *this, const void **binary_pp)
{
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSCast::`vftable';
  this->i_type_p.i_obj_p = 0i64;
  this->i_expr_p = 0i64;
  SSCast::assign_binary(this, binary_pp);
}

