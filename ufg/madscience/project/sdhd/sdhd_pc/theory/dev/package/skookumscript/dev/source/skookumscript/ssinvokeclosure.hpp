// File Line: 125
// RVA: 0x105840
void __fastcall SSInvokeClosureMethod::SSInvokeClosureMethod(SSInvokeClosureMethod *this, const void **binary_pp)
{
  SSInvokeClosureMethod *v2; // rbx

  v2 = this;
  SSInvokeClosureBase::SSInvokeClosureBase((SSInvokeClosureBase *)&this->vfptr, binary_pp);
  v2->vfptr = (SSExpressionBaseVtbl *)&SSInvokeClosureMethod::`vftable';
}

// File Line: 155
// RVA: 0x105810
void __fastcall SSInvokeClosureCoroutine::SSInvokeClosureCoroutine(SSInvokeClosureCoroutine *this, const void **binary_pp)
{
  SSInvokeClosureCoroutine *v2; // rbx

  v2 = this;
  SSInvokeClosureBase::SSInvokeClosureBase((SSInvokeClosureBase *)&this->vfptr, binary_pp);
  v2->vfptr = (SSExpressionBaseVtbl *)&SSInvokeClosureCoroutine::`vftable';
}

