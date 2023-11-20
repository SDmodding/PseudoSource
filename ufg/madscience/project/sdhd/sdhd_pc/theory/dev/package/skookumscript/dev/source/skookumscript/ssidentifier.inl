// File Line: 53
// RVA: 0x105190
void __fastcall SSIdentifier::SSIdentifier(SSIdentifier *this, const void **binary_pp)
{
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSIdentifier::`vftable';
  ASymbol::create_from_binary(&this->i_ident_name, binary_pp);
}

// File Line: 98
// RVA: 0x105200
void __fastcall SSIdentifierMember::SSIdentifierMember(SSIdentifierMember *this, const void **binary_pp)
{
  const void **v2; // rdi
  SSIdentifierMember *v3; // rbx
  eSSExprType v4; // ecx
  signed __int64 v5; // rax
  SSExpressionBase *v6; // rax

  v2 = binary_pp;
  v3 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable';
  this->vfptr = (SSExpressionBaseVtbl *)&SSIdentifier::`vftable';
  ASymbol::create_from_binary(&this->i_ident_name, binary_pp);
  v3->vfptr = (SSExpressionBaseVtbl *)&SSIdentifierMember::`vftable';
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
  v3->i_owner_p = v6;
}

// File Line: 143
// RVA: 0x1051D0
void __fastcall SSIdentifierClassMember::SSIdentifierClassMember(SSIdentifierClassMember *this, const void **binary_pp)
{
  SSIdentifierClassMember *v2; // rbx

  v2 = this;
  SSIdentifierMember::SSIdentifierMember((SSIdentifierMember *)&this->vfptr, binary_pp);
  v2->vfptr = (SSExpressionBaseVtbl *)&SSIdentifierClassMember::`vftable';
}

