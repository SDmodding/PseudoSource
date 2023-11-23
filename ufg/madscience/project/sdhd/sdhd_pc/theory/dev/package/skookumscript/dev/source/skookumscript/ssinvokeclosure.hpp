// File Line: 125
// RVA: 0x105840
void __fastcall SSInvokeClosureMethod::SSInvokeClosureMethod(SSInvokeClosureMethod *this, const void **binary_pp)
{
  SSInvokeClosureBase::SSInvokeClosureBase(this, binary_pp);
  this->vfptr = (SSExpressionBaseVtbl *)&SSInvokeClosureMethod::`vftable;
}

// File Line: 155
// RVA: 0x105810
void __fastcall SSInvokeClosureCoroutine::SSInvokeClosureCoroutine(
        SSInvokeClosureCoroutine *this,
        const void **binary_pp)
{
  SSInvokeClosureBase::SSInvokeClosureBase(this, binary_pp);
  this->vfptr = (SSExpressionBaseVtbl *)&SSInvokeClosureCoroutine::`vftable;
}

