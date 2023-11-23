// File Line: 38
// RVA: 0x107100
void __fastcall SSInvokableBase::~SSInvokableBase(SSInvokableBase *this)
{
  SSParameters *i_obj_p; // rbx

  this->vfptr = (SSInvokableBaseVtbl *)&SSInvokableBase::`vftable;
  i_obj_p = this->i_params_p.i_obj_p;
  if ( i_obj_p )
  {
    if ( i_obj_p->i_ref_count-- == 1 )
    {
      i_obj_p->i_ref_count = 0x80000000;
      SSParameters::~SSParameters(i_obj_p);
      AMemory::c_free_func(i_obj_p);
    }
  }
}

