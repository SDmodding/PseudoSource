// File Line: 73
// RVA: 0x104EC0
void __fastcall SSDataInstance::SSDataInstance(SSDataInstance *this)
{
  APSortedLogical<SSData,ASymbol> *v1; // [rsp+28h] [rbp+10h]

  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable';
  this->i_ref_count = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable';
  this->vfptr = (SSObjectBaseVtbl *)&SSDataInstance::`vftable';
  v1 = &this->i_data;
  v1->i_count = 0;
  v1->i_array_p = 0i64;
  v1->i_size = 0;
}

// File Line: 98
// RVA: 0x104F10
void __fastcall SSDataInstance::SSDataInstance(SSDataInstance *this, SSClass *class_p)
{
  APSortedLogical<SSData,ASymbol> *v2; // [rsp+48h] [rbp+10h]

  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable';
  this->i_ref_count = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable';
  this->i_class_p = class_p;
  this->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  this->vfptr = (SSObjectBaseVtbl *)&SSDataInstance::`vftable';
  v2 = &this->i_data;
  v2->i_count = 0;
  v2->i_array_p = 0i64;
  v2->i_size = 0;
  SSDataInstance::add_data_members(this);
}

