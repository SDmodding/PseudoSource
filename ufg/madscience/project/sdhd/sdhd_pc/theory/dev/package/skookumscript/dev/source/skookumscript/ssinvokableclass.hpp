// File Line: 53
// RVA: 0x1053C0
void __fastcall SSInvokableClass::SSInvokableClass(SSInvokableClass *this, SSInvokableClass *iclass)
{
  SSClass *v2; // rax
  SSParameters *v3; // rax

  v2 = iclass->i_class_p;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassUnaryBase::`vftable;
  this->i_ref_count = 0;
  this->vfptr = (SSClassDescBaseVtbl *)&SSContextClassBase::`vftable;
  this->i_class_p = v2;
  this->vfptr = (SSClassDescBaseVtbl *)&SSInvokableClass::`vftable;
  this->i_params_p.i_obj_p = iclass->i_params_p.i_obj_p;
  v3 = iclass->i_params_p.i_obj_p;
  if ( v3 )
    ++v3->i_ref_count;
  this->i_invoke_type = iclass->i_invoke_type;
}

// File Line: 54
// RVA: 0x107150
void __fastcall SSInvokableClass::~SSInvokableClass(SSInvokableClass *this)
{
  SSInvokableClass *v1; // rdi
  SSParameters *v2; // rbx
  bool v3; // zf
  SSParameters *v4; // rbx

  v1 = this;
  this->vfptr = (SSClassDescBaseVtbl *)&SSInvokableClass::`vftable;
  v2 = this->i_params_p.i_obj_p;
  if ( v2 )
  {
    v3 = v2->i_ref_count-- == 1;
    if ( v3 )
    {
      v2->i_ref_count = 2147483648;
      SSParameters::~SSParameters(v2);
      AMemory::c_free_func(v2);
    }
    v1->i_params_p.i_obj_p = 0i64;
  }
  v4 = v1->i_params_p.i_obj_p;
  if ( v4 )
  {
    v3 = v4->i_ref_count-- == 1;
    if ( v3 )
    {
      v4->i_ref_count = 2147483648;
      SSParameters::~SSParameters(v4);
      AMemory::c_free_func(v4);
    }
  }
  v1->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
}

