// File Line: 47
// RVA: 0x105F80
void __fastcall SSMethodCall::SSMethodCall(SSMethodCall *this, const void **binary_pp)
{
  const void **v2; // rbx
  SSMethodCall *v3; // rdi

  v2 = binary_pp;
  v3 = this;
  this->i_name = (ASymbol)ASymbol::get_null()->i_uid;
  v3->i_scope_p = 0i64;
  v3->vfptr = (SSInvokeBaseVtbl *)&SSInvokeBase::`vftable;
  v3->i_arguments.i_count = 0;
  v3->i_arguments.i_array_p = 0i64;
  v3->i_return_args.i_count = 0;
  v3->i_return_args.i_array_p = 0i64;
  v3->vfptr = (SSInvokeBaseVtbl *)&SSMethodCall::`vftable;
  SSInvokeBase::assign_binary((SSInvokeBase *)&v3->vfptr, v2);
}

