// File Line: 141
// RVA: 0x105350
void __fastcall SSInvocation::SSInvocation(SSInvocation *this, const void **binary_pp)
{
  const void **v2; // rdi
  SSInvocation *v3; // rbx
  eSSExprType v4; // ecx
  char *v5; // rax
  SSExpressionBase *v6; // rax

  v2 = binary_pp;
  v3 = this;
  this->vfptr = (SSExpressionBaseVtbl *)&SSExpressionBase::`vftable;
  this->vfptr = (SSExpressionBaseVtbl *)&SSInvocation::`vftable;
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
  v3->i_receiver_p = v6;
  v3->i_call_p = SSInvokeBase::from_binary_typed_new(v2);
}

