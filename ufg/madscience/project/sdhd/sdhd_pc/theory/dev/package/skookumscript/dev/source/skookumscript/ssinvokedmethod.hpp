// File Line: 137
// RVA: 0x105990
void __fastcall SSInvokedDeferrableMethod::SSInvokedDeferrableMethod(
        SSInvokedDeferrableMethod *this,
        SSObjectBase *scope_p,
        SSMethodBase *method_p)
{
  unsigned int i_ptr_id; // eax

  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
  this->i_prev_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
  this->i_next_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedBase::`vftable;
  this->i_scope_p.i_obj_p = scope_p;
  if ( scope_p )
    i_ptr_id = scope_p->i_ptr_id;
  else
    i_ptr_id = 0;
  this->i_scope_p.i_ptr_id = i_ptr_id;
  this->i_caller_p.i_obj_p = 0i64;
  this->i_caller_p.i_ptr_id = 0;
  this->i_calls.i_sentinel.i_prev_p = &this->i_calls.i_sentinel;
  this->i_calls.i_sentinel.SSInvokedMethod::SSInvokedContextBase::SSInvokedBase::i_next_p = &this->i_calls.i_sentinel;
  this->i_pending_count = 0;
  this->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedContextBase::`vftable;
  this->i_data.i_count = 0;
  this->i_data.i_array_p = 0i64;
  this->i_data.i_size = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedMethod::`vftable;
  this->i_method_p = method_p;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedDeferrableMethod::`vftable;
}

