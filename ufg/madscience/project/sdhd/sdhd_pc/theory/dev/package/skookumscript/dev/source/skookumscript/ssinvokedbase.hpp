// File Line: 249
// RVA: 0x105A50
void __fastcall SSInvokedExpression::SSInvokedExpression(SSInvokedExpression *this)
{
  AListNode<SSInvokedBase,SSInvokedBase> *v1; // rax
  AList<SSInvokedBase,SSInvokedBase> *v2; // [rsp+28h] [rbp+10h]

  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
  v1 = (AListNode<SSInvokedBase,SSInvokedBase> *)&this->i_next_p;
  v1->i_prev_p = v1;
  v1->i_next_p = v1;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedBase::`vftable;
  this->i_scope_p.i_obj_p = 0i64;
  this->i_scope_p.i_ptr_id = 0;
  this->i_caller_p.i_obj_p = 0i64;
  this->i_caller_p.i_ptr_id = 0;
  v2 = &this->i_calls;
  v2->i_sentinel.i_prev_p = &v2->i_sentinel;
  v2->i_sentinel.i_next_p = &v2->i_sentinel;
  this->i_pending_count = 0;
  this->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedExpression::`vftable;
}

