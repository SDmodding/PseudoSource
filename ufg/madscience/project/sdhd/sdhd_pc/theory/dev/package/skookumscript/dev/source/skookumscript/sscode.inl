// File Line: 42
// RVA: 0x104A70
void __fastcall SSCode::SSCode(SSCode *this, const void **binary_pp)
{
  AVCompactSortedLogical<ASymbol,ASymbol> *v2; // [rsp+50h] [rbp+18h]
  APCompactArrayFree<SSExpressionBase,SSExpressionBase,ACompareAddress<SSExpressionBase> > *v3; // [rsp+50h] [rbp+18h]

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSCode::`vftable';
  v2 = &this->i_temp_vars;
  v2->i_count = 0;
  v2->i_array_p = 0i64;
  v3 = &this->i_statements;
  v3->i_count = 0;
  v3->i_array_p = 0i64;
  SSCode::assign_binary(this, binary_pp);
}

// File Line: 139
// RVA: 0x104AD0
void __fastcall SSConcurrentBranch::SSConcurrentBranch(SSConcurrentBranch *this, const void **binary_pp)
{
  SSConcurrentBranch *v2; // rbx
  eSSExprType v3; // ecx
  char *v4; // rax
  SSExpressionBase *v5; // rax

  v2 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSConcurrentBranch::`vftable';
  v3 = *(unsigned __int8 *)*binary_pp;
  v4 = (char *)*binary_pp + 1;
  *binary_pp = v4;
  if ( v3 )
  {
    *binary_pp = v4 + 2;
    v5 = SSExpressionBase::from_binary_new(v3, binary_pp);
  }
  else
  {
    v5 = 0i64;
  }
  v2->i_statement_p = v5;
}

// File Line: 178
// RVA: 0x104F90
void __fastcall SSDivert::SSDivert(SSDivert *this, const void **binary_pp)
{
  SSDivert *v2; // rbx
  eSSExprType v3; // ecx
  char *v4; // rax
  SSExpressionBase *v5; // rax

  v2 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSDivert::`vftable';
  v3 = *(unsigned __int8 *)*binary_pp;
  v4 = (char *)*binary_pp + 1;
  *binary_pp = v4;
  if ( v3 )
  {
    *binary_pp = v4 + 2;
    v5 = SSExpressionBase::from_binary_new(v3, binary_pp);
  }
  else
  {
    v5 = 0i64;
  }
  v2->i_statement_p = v5;
}

// File Line: 236
// RVA: 0x1041F0
void __fastcall SSBind::SSBind(SSBind *this, const void **binary_pp)
{
  const void **v2; // rdi
  SSBind *v3; // rbx
  eSSExprType v4; // ecx
  char *v5; // rax
  SSExpressionBase *v6; // rsi
  SSExpressionBase *v7; // rax
  eSSExprType v8; // ecx
  signed __int64 v9; // rax

  v2 = binary_pp;
  v3 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSBind::`vftable';
  v4 = *(unsigned __int8 *)*binary_pp;
  v5 = (char *)*binary_pp + 1;
  *binary_pp = v5;
  v6 = 0i64;
  if ( v4 )
  {
    *binary_pp = v5 + 2;
    v7 = SSExpressionBase::from_binary_new(v4, binary_pp);
  }
  else
  {
    v7 = 0i64;
  }
  v3->i_ident_p = (SSIdentifier *)v7;
  v8 = *(unsigned __int8 *)*v2;
  v9 = (signed __int64)*v2 + 1;
  *v2 = (const void *)v9;
  if ( v8 )
  {
    *v2 = (const void *)(v9 + 2);
    v6 = SSExpressionBase::from_binary_new(v8, v2);
  }
  v3->i_expr_p = v6;
}

