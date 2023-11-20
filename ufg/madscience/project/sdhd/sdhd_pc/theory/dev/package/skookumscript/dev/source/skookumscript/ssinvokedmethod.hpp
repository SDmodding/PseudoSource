// File Line: 137
// RVA: 0x105990
void __fastcall SSInvokedDeferrableMethod::SSInvokedDeferrableMethod(SSInvokedDeferrableMethod *this, SSObjectBase *scope_p, SSMethodBase *method_p)
{
  AListNode<SSInvokedBase,SSInvokedBase> *v3; // rax
  unsigned int v4; // eax
  AList<SSInvokedBase,SSInvokedBase> *v5; // [rsp+28h] [rbp+10h]
  APArrayLogical<SSData,ASymbol> *v6; // [rsp+28h] [rbp+10h]

  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable';
  v3 = (AListNode<SSInvokedBase,SSInvokedBase> *)&this->i_next_p;
  v3->i_prev_p = v3;
  v3->i_next_p = v3;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedBase::`vftable';
  this->i_scope_p.i_obj_p = scope_p;
  if ( scope_p )
    v4 = scope_p->i_ptr_id;
  else
    v4 = 0;
  this->i_scope_p.i_ptr_id = v4;
  this->i_caller_p.i_obj_p = 0i64;
  this->i_caller_p.i_ptr_id = 0;
  v5 = &this->i_calls;
  v5->i_sentinel.i_prev_p = &v5->i_sentinel;
  v5->i_sentinel.i_next_p = &v5->i_sentinel;
  this->i_pending_count = 0;
  this->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedContextBase::`vftable';
  v6 = &this->i_data;
  v6->i_count = 0;
  v6->i_array_p = 0i64;
  v6->i_size = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedMethod::`vftable';
  this->i_method_p = method_p;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedDeferrableMethod::`vftable';
}

