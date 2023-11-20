// File Line: 230
// RVA: 0x1058A0
void __fastcall SSInvokeSync::SSInvokeSync(SSInvokeSync *this, const void **binary_pp)
{
  SSInvokeSync *v2; // rbx

  v2 = this;
  SSInvocation::SSInvocation((SSInvocation *)&this->vfptr, binary_pp);
  v2->vfptr = (SSExpressionBaseVtbl *)&SSInvokeSync::`vftable;
}

// File Line: 241
// RVA: 0x11A020
signed __int64 __fastcall SSInvokeSync::get_type(SSInvokeSync *this)
{
  return 19i64;
}

// File Line: 288
// RVA: 0x105870
void __fastcall SSInvokeRace::SSInvokeRace(SSInvokeRace *this, const void **binary_pp)
{
  SSInvokeRace *v2; // rbx

  v2 = this;
  SSInvocation::SSInvocation((SSInvocation *)&this->vfptr, binary_pp);
  v2->vfptr = (SSExpressionBaseVtbl *)&SSInvokeRace::`vftable;
}

// File Line: 299
// RVA: 0x11A010
signed __int64 __fastcall UFG::SocialLogData_NewHighScore::VariableBindingListSize()
{
  return 20i64;
}

