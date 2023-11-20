// File Line: 50
// RVA: 0xBD5A0
void __fastcall SSInvokedBase::~SSInvokedBase(SSInvokedBase *this)
{
  SSInvokedBase *v1; // r8
  AList<SSInvokedBase,SSInvokedBase> *v2; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v3; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v4; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v5; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v6; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v7; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v8; // rax

  v1 = this;
  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedBase::`vftable';
  this->i_ptr_id = 0;
  v2 = &this->i_calls;
  v3 = this->i_calls.i_sentinel.i_next_p;
  if ( (AList<SSInvokedBase,SSInvokedBase> *)v2->i_sentinel.i_next_p != v2 )
  {
    do
    {
      v4 = v3;
      v3 = v3->i_next_p;
      v4->i_next_p = v4;
      v4->i_prev_p = v4;
    }
    while ( v3 != (AListNode<SSInvokedBase,SSInvokedBase> *)v2 );
    v2->i_sentinel.i_next_p = &v2->i_sentinel;
    v2->i_sentinel.i_prev_p = &v2->i_sentinel;
  }
  v5 = v2->i_sentinel.i_next_p;
  if ( (AList<SSInvokedBase,SSInvokedBase> *)v2->i_sentinel.i_next_p != v2 )
  {
    v6 = v2->i_sentinel.i_prev_p;
    v5->i_prev_p = v6;
    v6->i_next_p = v5;
    v2->i_sentinel.i_prev_p = &v2->i_sentinel;
    v2->i_sentinel.i_next_p = &v2->i_sentinel;
  }
  v7 = v1->i_next_p;
  if ( v7 != (AListNode<SSInvokedBase,SSInvokedBase> *)&v1->i_next_p )
  {
    v8 = v1->i_prev_p;
    v7->i_prev_p = v8;
    v8->i_next_p = v7;
    v1->i_prev_p = (AListNode<SSInvokedBase,SSInvokedBase> *)&v1->i_next_p;
    v1->i_next_p = (AListNode<SSInvokedBase,SSInvokedBase> *)&v1->i_next_p;
  }
  v1->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable';
}

// File Line: 59
// RVA: 0xCF070
SSActor *__fastcall SSInvokedBase::get_updater(SSInvokedBase *this)
{
  SSInvokedBase *v1; // rdx
  SSInvokedBase *v2; // rcx
  SSActor *result; // rax

  v1 = this;
  v2 = this->i_caller_p.i_obj_p;
  if ( v2 && v1->i_caller_p.i_ptr_id == v2->i_ptr_id )
    result = (SSActor *)((__int64 (*)(void))v2->vfptr[1].is_actor)();
  else
    result = 0i64;
  return result;
}

// File Line: 160
// RVA: 0x130FD0
SSInvokedExpression *__fastcall SSInvokedExpression::pool_new(SSExpressionBase *expr, SSInvokedBase *caller_p, SSObjectBase *scope_p)
{
  SSObjectBase *v3; // rsi
  SSInvokedBase *v4; // rdi
  SSExpressionBase *v5; // rbp
  AObjReusePool<SSInvokedExpression> *v6; // rax
  AObjReusePool<SSInvokedExpression> *v7; // rbx
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  __int64 v11; // rcx
  SSInvokedExpression **v12; // rax
  SSInvokedExpression *result; // rax
  unsigned int v14; // eax
  unsigned int v15; // ecx
  unsigned int v16; // ecx

  v3 = scope_p;
  v4 = caller_p;
  v5 = expr;
  v6 = SSInvokedExpression::get_pool();
  v7 = v6;
  v8 = v6->i_pool.i_count;
  if ( v8 )
  {
    v14 = v8 - 1;
    v7->i_pool.i_count = v14;
    v11 = v14;
    v12 = v7->i_pool.i_array_p;
  }
  else
  {
    if ( !v7->i_exp_pool.i_count )
      AObjReusePool<SSInvokedExpression>::append_block(v7, v7->i_expand_size);
    v9 = v7->i_exp_pool.i_count;
    if ( !v9 )
    {
      result = 0i64;
      goto LABEL_9;
    }
    v10 = v9 - 1;
    v7->i_exp_pool.i_count = v10;
    v11 = v10;
    v12 = v7->i_exp_pool.i_array_p;
  }
  result = v12[v11];
LABEL_9:
  result->i_expr_p = v5;
  result->i_caller_p.i_obj_p = v4;
  if ( v4 )
    v15 = v4->i_ptr_id;
  else
    v15 = 0;
  result->i_caller_p.i_ptr_id = v15;
  result->i_scope_p.i_obj_p = v3;
  if ( v3 )
    v16 = v3->i_ptr_id;
  else
    v16 = 0;
  result->i_scope_p.i_ptr_id = v16;
  result->i_pending_count = 0;
  result->i_index = 0;
  result->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  return result;
}

// File Line: 178
// RVA: 0x11A140
SSActor *__fastcall SSInvokedExpression::get_updater(SSInvokedExpression *this)
{
  return (SSActor *)this->i_expr_p->vfptr->get_updater(this->i_expr_p, this);
}

// File Line: 269
// RVA: 0x13C2D0
void __fastcall SSInvokedContextBase::set_arg(SSInvokedContextBase *this, unsigned int pos, SSInstance *obj_p)
{
  SSInstance *v3; // rdi
  SSData *v4; // rbx
  SSInstance *v5; // rcx
  bool v6; // zf

  v3 = obj_p;
  v4 = this->i_data.i_array_p[pos];
  v5 = v4->i_data_p;
  v6 = v5->i_ref_count-- == 1;
  if ( v6 )
  {
    v5->i_ref_count = 2147483648;
    ((void (*)(void))v5->vfptr[1].get_scope_context)();
    v4->i_data_p = v3;
  }
  else
  {
    v4->i_data_p = obj_p;
  }
}

