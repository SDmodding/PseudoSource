// File Line: 160
// RVA: 0x11A050
SSActor *__fastcall SSExpressionBase::get_updater(SSExpressionBase *this, SSInvokedExpression *iexpr)
{
  SSInvokedBase *i_obj_p; // rcx

  i_obj_p = iexpr->i_caller_p.i_obj_p;
  if ( i_obj_p && iexpr->i_caller_p.i_ptr_id == i_obj_p->i_ptr_id )
    return (SSActor *)((__int64 (__fastcall *)(SSInvokedBase *))i_obj_p->vfptr[1].is_actor)(i_obj_p);
  else
    return 0i64;
}

// File Line: 220
// RVA: 0x11E3E0
char __fastcall SSExpressionBase::invoke_iterate(
        SSExpressionBase *this,
        SSInvokedExpression *iexpr_p,
        SSInstance **result_pp)
{
  SSInvokedBase *i_obj_p; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // r8
  AListNode<SSInvokedBase,SSInvokedBase> *v6; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax

  i_obj_p = iexpr_p->i_caller_p.i_obj_p;
  if ( i_obj_p && iexpr_p->i_caller_p.i_ptr_id == i_obj_p->i_ptr_id && i_obj_p->i_pending_count )
  {
    i_next_p = iexpr_p->i_next_p;
    v6 = &iexpr_p->AListNode<SSInvokedBase,SSInvokedBase>;
    if ( i_next_p != v6 )
    {
      i_prev_p = v6->i_prev_p;
      i_next_p->i_prev_p = i_prev_p;
      i_prev_p->i_next_p = i_next_p;
      v6->i_prev_p = v6;
      v6->i_next_p = v6;
    }
    LOBYTE(v6) = 1;
    i_obj_p->vfptr[1].get_data_by_name(i_obj_p, (ASymbol *)v6);
  }
  SSInvokedExpression::pool_delete(iexpr_p);
  return 1;
}

// File Line: 260
// RVA: 0x104C90
void __fastcall SSConditional::SSConditional(SSConditional *this, const void **binary_pp)
{
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSConditional::`vftable;
  this->i_clauses.i_count = 0;
  this->i_clauses.i_array_p = 0i64;
  SSConditional::assign_binary(this, binary_pp);
}

// File Line: 288
// RVA: 0x1042F0
void __fastcall SSCase::SSCase(SSCase *this, const void **binary_pp)
{
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSCase::`vftable;
  this->i_clauses.i_count = 0;
  this->i_clauses.i_array_p = 0i64;
  SSCase::assign_binary(this, binary_pp);
}

// File Line: 317
// RVA: 0x105ED0
void __fastcall SSLoop::SSLoop(SSLoop *this, const void **binary_pp)
{
  eSSExprType v4; // ecx
  char *v5; // rax
  SSExpressionBase *v6; // rax

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSLoop::`vftable;
  ASymbol::create_from_binary(&this->i_name, binary_pp);
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
  this->i_expr_p = v6;
}

// File Line: 345
// RVA: 0x105F40
void __fastcall SSLoopExit::SSLoopExit(SSLoopExit *this, const void **binary_pp)
{
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSLoopExit::`vftable;
  ASymbol::create_from_binary(&this->i_name, binary_pp);
}

// File Line: 385
// RVA: 0x104CE0
void __fastcall SSConversion::SSConversion(SSConversion *this, const void **binary_pp)
{
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSConversion::`vftable;
  this->i_type_p = 0i64;
  this->i_expr_p = 0i64;
  SSConversion::assign_binary(this, binary_pp);
}

// File Line: 408
// RVA: 0x104390
void __fastcall SSCast::SSCast(SSCast *this, SSClassDescBase *type_p, SSExpressionBase *expr_p)
{
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSCast::`vftable;
  this->i_type_p.i_obj_p = type_p;
  if ( type_p )
    (*(void (__fastcall **)(SSClassDescBase *))type_p->vfptr->gap8)(type_p);
  this->i_expr_p = expr_p;
}

// File Line: 426
// RVA: 0x104340
void __fastcall SSCast::SSCast(SSCast *this, const void **binary_pp)
{
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSCast::`vftable;
  this->i_type_p.i_obj_p = 0i64;
  this->i_expr_p = 0i64;
  SSCast::assign_binary(this, binary_pp);
}

