// File Line: 249
// RVA: 0x105A50
void __fastcall SSInvokedExpression::SSInvokedExpression(SSInvokedExpression *this)
{
  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
  this->i_prev_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
  this->i_next_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedBase::`vftable;
  this->i_scope_p.i_obj_p = 0i64;
  this->i_scope_p.i_ptr_id = 0;
  this->i_caller_p.i_obj_p = 0i64;
  this->i_caller_p.i_ptr_id = 0;
  this->i_calls.i_sentinel.i_prev_p = &this->i_calls.i_sentinel;
  this->i_calls.i_sentinel.SSInvokedBase::i_next_p = &this->i_calls.i_sentinel;
  this->i_pending_count = 0;
  this->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedExpression::`vftable;
}

