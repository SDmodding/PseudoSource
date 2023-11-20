// File Line: 38
// RVA: 0x107100
void __fastcall SSInvokableBase::~SSInvokableBase(SSInvokableBase *this)
{
  SSParameters *v1; // rbx
  bool v2; // zf

  this->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
  v1 = this->i_params_p.i_obj_p;
  if ( v1 )
  {
    v2 = v1->i_ref_count-- == 1;
    if ( v2 )
    {
      v1->i_ref_count = 2147483648;
      SSParameters::~SSParameters(v1);
      AMemory::c_free_func(v1);
    }
  }
}

