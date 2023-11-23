// File Line: 42
// RVA: 0x104A70
void __fastcall SSCode::SSCode(SSCode *this, const void **binary_pp)
{
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSCode::`vftable;
  this->i_temp_vars.i_count = 0;
  this->i_temp_vars.i_array_p = 0i64;
  this->i_statements.i_count = 0;
  this->i_statements.i_array_p = 0i64;
  SSCode::assign_binary(this, binary_pp);
}

// File Line: 139
// RVA: 0x104AD0
void __fastcall SSConcurrentBranch::SSConcurrentBranch(SSConcurrentBranch *this, const void **binary_pp)
{
  eSSExprType v3; // ecx
  char *v4; // rax
  SSExpressionBase *v5; // rax

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSConcurrentBranch::`vftable;
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
  this->i_statement_p = v5;
}

// File Line: 178
// RVA: 0x104F90
void __fastcall SSDivert::SSDivert(SSDivert *this, const void **binary_pp)
{
  eSSExprType v3; // ecx
  char *v4; // rax
  SSExpressionBase *v5; // rax

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSDivert::`vftable;
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
  this->i_statement_p = v5;
}

// File Line: 236
// RVA: 0x1041F0
void __fastcall SSBind::SSBind(SSBind *this, const void **binary_pp)
{
  eSSExprType v4; // ecx
  char *v5; // rax
  SSExpressionBase *v6; // rsi
  SSIdentifier *v7; // rax
  eSSExprType v8; // ecx
  char *v9; // rax

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSBind::`vftable;
  v4 = *(unsigned __int8 *)*binary_pp;
  v5 = (char *)*binary_pp + 1;
  *binary_pp = v5;
  v6 = 0i64;
  if ( v4 )
  {
    *binary_pp = v5 + 2;
    v7 = (SSIdentifier *)SSExpressionBase::from_binary_new(v4, binary_pp);
  }
  else
  {
    v7 = 0i64;
  }
  this->i_ident_p = v7;
  v8 = *(unsigned __int8 *)*binary_pp;
  v9 = (char *)*binary_pp + 1;
  *binary_pp = v9;
  if ( v8 )
  {
    *binary_pp = v9 + 2;
    v6 = SSExpressionBase::from_binary_new(v8, binary_pp);
  }
  this->i_expr_p = v6;
}

