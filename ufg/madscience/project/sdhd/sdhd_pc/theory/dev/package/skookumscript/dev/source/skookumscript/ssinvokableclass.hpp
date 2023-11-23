// File Line: 53
// RVA: 0x1053C0
void __fastcall SSInvokableClass::SSInvokableClass(SSInvokableClass *this, SSInvokableClass *iclass)
{
  SSClass *i_class_p; // rax
  SSParameters *i_obj_p; // rax

  i_class_p = iclass->i_class_p;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassUnaryBase::`vftable;
  this->i_ref_count = 0;
  this->vfptr = (SSClassDescBaseVtbl *)&SSContextClassBase::`vftable;
  this->i_class_p = i_class_p;
  this->vfptr = (SSClassDescBaseVtbl *)&SSInvokableClass::`vftable;
  this->i_params_p.i_obj_p = iclass->i_params_p.i_obj_p;
  i_obj_p = iclass->i_params_p.i_obj_p;
  if ( i_obj_p )
    ++i_obj_p->i_ref_count;
  this->i_invoke_type = iclass->i_invoke_type;
}

// File Line: 54
// RVA: 0x107150
void __fastcall SSInvokableClass::~SSInvokableClass(SSInvokableClass *this)
{
  SSParameters *i_obj_p; // rbx
  bool v3; // zf
  SSParameters *v4; // rbx

  this->vfptr = (SSClassDescBaseVtbl *)&SSInvokableClass::`vftable;
  i_obj_p = this->i_params_p.i_obj_p;
  if ( i_obj_p )
  {
    v3 = i_obj_p->i_ref_count-- == 1;
    if ( v3 )
    {
      i_obj_p->i_ref_count = 0x80000000;
      SSParameters::~SSParameters(i_obj_p);
      AMemory::c_free_func(i_obj_p);
    }
    this->i_params_p.i_obj_p = 0i64;
  }
  v4 = this->i_params_p.i_obj_p;
  if ( v4 )
  {
    v3 = v4->i_ref_count-- == 1;
    if ( v3 )
    {
      v4->i_ref_count = 0x80000000;
      SSParameters::~SSParameters(v4);
      AMemory::c_free_func(v4);
    }
  }
  this->vfptr = (SSClassDescBaseVtbl *)&SSClassDescBase::`vftable;
}

