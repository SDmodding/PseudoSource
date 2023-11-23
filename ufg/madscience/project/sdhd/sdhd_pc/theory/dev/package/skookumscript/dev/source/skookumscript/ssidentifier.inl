// File Line: 53
// RVA: 0x105190
void __fastcall SSIdentifier::SSIdentifier(SSIdentifier *this, const void **binary_pp)
{
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSIdentifier::`vftable;
  ASymbol::create_from_binary(&this->i_ident_name, binary_pp);
}

// File Line: 98
// RVA: 0x105200
void __fastcall SSIdentifierMember::SSIdentifierMember(SSIdentifierMember *this, const void **binary_pp)
{
  eSSExprType v4; // ecx
  char *v5; // rax
  SSExpressionBase *v6; // rax

  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSIdentifier::`vftable;
  ASymbol::create_from_binary(&this->i_ident_name, binary_pp);
  this->vfptr = (SSExpressionBaseVtbl *)&SSIdentifierMember::`vftable;
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
  this->i_owner_p = v6;
}

// File Line: 143
// RVA: 0x1051D0
void __fastcall SSIdentifierClassMember::SSIdentifierClassMember(SSIdentifierClassMember *this, const void **binary_pp)
{
  SSIdentifierMember::SSIdentifierMember(this, binary_pp);
  this->vfptr = (SSExpressionBaseVtbl *)&SSIdentifierClassMember::`vftable;
}

