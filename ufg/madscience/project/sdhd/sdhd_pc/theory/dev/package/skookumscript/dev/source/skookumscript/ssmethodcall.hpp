// File Line: 47
// RVA: 0x105F80
void __fastcall SSMethodCall::SSMethodCall(SSMethodCall *this, const void **binary_pp)
{
  this->i_name = (ASymbol)ASymbol::get_null()->i_uid;
  this->i_scope_p = 0i64;
  this->vfptr = (SSInvokeBaseVtbl *)&SSInvokeBase::`vftable;
  this->i_arguments.i_count = 0;
  this->i_arguments.i_array_p = 0i64;
  this->i_return_args.i_count = 0;
  this->i_return_args.i_array_p = 0i64;
  this->vfptr = (SSInvokeBaseVtbl *)&SSMethodCall::`vftable;
  SSInvokeBase::assign_binary(this, binary_pp);
}

