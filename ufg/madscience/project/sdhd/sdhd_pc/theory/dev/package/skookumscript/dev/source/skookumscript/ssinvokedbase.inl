// File Line: 50
// RVA: 0xBD5A0
void __fastcall SSInvokedBase::~SSInvokedBase(SSInvokedBase *this)
{
  AList<SSInvokedBase,SSInvokedBase> *p_i_calls; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *i_next_p; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *v4; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v5; // rcx
  AListNode<SSInvokedBase,SSInvokedBase> *i_prev_p; // rax
  AListNode<SSInvokedBase,SSInvokedBase> *v7; // rdx
  AListNode<SSInvokedBase,SSInvokedBase> *v8; // rax

  this->vfptr = (SSObjectBaseVtbl *)&SSInvokedBase::`vftable;
  this->i_ptr_id = 0;
  p_i_calls = &this->i_calls;
  i_next_p = this->i_calls.i_sentinel.i_next_p;
  if ( (AList<SSInvokedBase,SSInvokedBase> *)p_i_calls->i_sentinel.i_next_p != p_i_calls )
  {
    do
    {
      v4 = i_next_p;
      i_next_p = i_next_p->i_next_p;
      v4->i_next_p = v4;
      v4->i_prev_p = v4;
    }
    while ( i_next_p != (AListNode<SSInvokedBase,SSInvokedBase> *)p_i_calls );
    p_i_calls->i_sentinel.i_next_p = &p_i_calls->i_sentinel;
    p_i_calls->i_sentinel.i_prev_p = &p_i_calls->i_sentinel;
  }
  v5 = p_i_calls->i_sentinel.i_next_p;
  if ( (AList<SSInvokedBase,SSInvokedBase> *)p_i_calls->i_sentinel.i_next_p != p_i_calls )
  {
    i_prev_p = p_i_calls->i_sentinel.i_prev_p;
    v5->i_prev_p = i_prev_p;
    i_prev_p->i_next_p = v5;
    p_i_calls->i_sentinel.i_prev_p = &p_i_calls->i_sentinel;
    p_i_calls->i_sentinel.i_next_p = &p_i_calls->i_sentinel;
  }
  v7 = this->i_next_p;
  if ( v7 != &this->AListNode<SSInvokedBase,SSInvokedBase> )
  {
    v8 = this->i_prev_p;
    v7->i_prev_p = v8;
    v8->i_next_p = v7;
    this->i_prev_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
    this->i_next_p = &this->AListNode<SSInvokedBase,SSInvokedBase>;
  }
  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
}

// File Line: 59
// RVA: 0xCF070
SSActor *__fastcall SSInvokedBase::get_updater(SSInvokedBase *this)
{
  SSInvokedBase *i_obj_p; // rcx

  i_obj_p = this->i_caller_p.i_obj_p;
  if ( i_obj_p && this->i_caller_p.i_ptr_id == i_obj_p->i_ptr_id )
    return (SSActor *)((__int64 (__fastcall *)(SSInvokedBase *))i_obj_p->vfptr[1].is_actor)(i_obj_p);
  else
    return 0i64;
}

// File Line: 160
// RVA: 0x130FD0
SSInvokedExpression *__fastcall SSInvokedExpression::pool_new(
        SSExpressionBase *expr,
        SSInvokedBase *caller_p,
        SSObjectBase *scope_p)
{
  AObjReusePool<SSInvokedExpression> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v8; // eax
  __int64 v9; // rcx
  SSInvokedExpression **i_array_p; // rax
  SSInvokedExpression *result; // rax
  unsigned int v12; // eax
  unsigned int i_ptr_id; // ecx
  unsigned int v14; // ecx

  pool = SSInvokedExpression::get_pool();
  if ( pool->i_pool.i_count )
  {
    v12 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v12;
    v9 = v12;
    i_array_p = pool->i_pool.i_array_p;
  }
  else
  {
    if ( !pool->i_exp_pool.i_count )
      AObjReusePool<SSInvokedExpression>::append_block(pool, pool->i_expand_size);
    i_count = pool->i_exp_pool.i_count;
    if ( !i_count )
    {
      result = 0i64;
      goto LABEL_9;
    }
    v8 = i_count - 1;
    pool->i_exp_pool.i_count = v8;
    v9 = v8;
    i_array_p = pool->i_exp_pool.i_array_p;
  }
  result = i_array_p[v9];
LABEL_9:
  result->i_expr_p = expr;
  result->i_caller_p.i_obj_p = caller_p;
  if ( caller_p )
    i_ptr_id = caller_p->i_ptr_id;
  else
    i_ptr_id = 0;
  result->i_caller_p.i_ptr_id = i_ptr_id;
  result->i_scope_p.i_obj_p = scope_p;
  if ( scope_p )
    v14 = scope_p->i_ptr_id;
  else
    v14 = 0;
  result->i_scope_p.i_ptr_id = v14;
  result->i_pending_count = 0;
  result->i_index = 0;
  result->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  return result;
}

// File Line: 178
// RVA: 0x11A140
SSActor *__fastcall SSInvokedExpression::get_updater(SSInvokedExpression *this)
{
  return this->i_expr_p->vfptr->get_updater(this->i_expr_p, this);
}

// File Line: 269
// RVA: 0x13C2D0
void __fastcall SSInvokedContextBase::set_arg(SSInvokedContextBase *this, unsigned int pos, SSInstance *obj_p)
{
  SSData *v4; // rbx
  SSInstance *i_data_p; // rcx

  v4 = this->i_data.i_array_p[pos];
  i_data_p = v4->i_data_p;
  if ( i_data_p->i_ref_count-- == 1 )
  {
    i_data_p->i_ref_count = 0x80000000;
    i_data_p->vfptr[1].get_scope_context(i_data_p);
    v4->i_data_p = obj_p;
  }
  else
  {
    v4->i_data_p = obj_p;
  }
}

