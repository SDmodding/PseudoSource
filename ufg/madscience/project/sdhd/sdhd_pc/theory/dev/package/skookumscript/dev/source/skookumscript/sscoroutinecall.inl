// File Line: 70
// RVA: 0x104DD0
void __fastcall SSCoroutineCall::SSCoroutineCall(SSCoroutineCall *this, const void **binary_pp)
{
  this->i_name = (ASymbol)ASymbol::get_null()->i_uid;
  this->i_scope_p = 0i64;
  this->vfptr = (SSInvokeBaseVtbl *)&SSInvokeBase::`vftable;
  this->i_arguments.i_count = 0;
  this->i_arguments.i_array_p = 0i64;
  this->i_return_args.i_count = 0;
  this->i_return_args.i_array_p = 0i64;
  this->vfptr = (SSInvokeBaseVtbl *)&SSCoroutineCall::`vftable;
  SSInvokeBase::assign_binary(this, binary_pp);
}

