// File Line: 73
// RVA: 0x104EC0
void __fastcall SSDataInstance::SSDataInstance(SSDataInstance *this)
{
  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
  this->i_ref_count = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable;
  this->vfptr = (SSObjectBaseVtbl *)&SSDataInstance::`vftable;
  this->i_data.i_count = 0;
  this->i_data.i_array_p = 0i64;
  this->i_data.i_size = 0;
}

// File Line: 98
// RVA: 0x104F10
void __fastcall SSDataInstance::SSDataInstance(SSDataInstance *this, SSClass *class_p)
{
  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
  this->i_ref_count = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable;
  this->i_class_p = class_p;
  this->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  this->vfptr = (SSObjectBaseVtbl *)&SSDataInstance::`vftable;
  this->i_data.i_count = 0;
  this->i_data.i_array_p = 0i64;
  this->i_data.i_size = 0;
  SSDataInstance::add_data_members(this);
}

