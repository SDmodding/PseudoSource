// File Line: 31
// RVA: 0x104290
void __fastcall SSBoolean::SSBoolean(SSBoolean *this)
{
  SSClass *v1; // rax

  v1 = SSBrain::c_boolean_class_p;
  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
  this->i_ref_count = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable;
  this->i_class_p = v1;
  this->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  this->vfptr = (SSObjectBaseVtbl *)&SSBoolean::`vftable;
}

// File Line: 49
// RVA: 0x130AB0
SSBoolean *__fastcall SSBoolean::pool_new(bool bool_value)
{
  AObjReusePool<SSBoolean> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v4; // eax
  __int64 v5; // rcx
  SSBoolean **i_array_p; // rax
  SSBoolean *result; // rax
  unsigned int v8; // eax

  pool = SSBoolean::get_pool();
  if ( pool->i_pool.i_count )
  {
    v8 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v8;
    v5 = v8;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<SSBoolean>::append_block(pool, pool->i_expand_size);
  i_count = pool->i_exp_pool.i_count;
  if ( i_count )
  {
    v4 = i_count - 1;
    pool->i_exp_pool.i_count = v4;
    v5 = v4;
    i_array_p = pool->i_exp_pool.i_array_p;
LABEL_8:
    result = i_array_p[v5];
    goto LABEL_9;
  }
  result = 0i64;
LABEL_9:
  result->i_ref_count = 1;
  result->i_user_data = bool_value;
  result->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  return result;
}

// File Line: 71
// RVA: 0x130A30
SSBoolean *__fastcall SSBoolean::pool_new(unsigned __int64 bool_value)
{
  AObjReusePool<SSBoolean> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v4; // eax
  __int64 v5; // rcx
  SSBoolean **i_array_p; // rax
  SSBoolean *result; // rax
  unsigned int v8; // eax

  pool = SSBoolean::get_pool();
  if ( pool->i_pool.i_count )
  {
    v8 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v8;
    v5 = v8;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<SSBoolean>::append_block(pool, pool->i_expand_size);
  i_count = pool->i_exp_pool.i_count;
  if ( i_count )
  {
    v4 = i_count - 1;
    pool->i_exp_pool.i_count = v4;
    v5 = v4;
    i_array_p = pool->i_exp_pool.i_array_p;
LABEL_8:
    result = i_array_p[v5];
    goto LABEL_9;
  }
  result = 0i64;
LABEL_9:
  result->i_user_data = bool_value;
  result->i_ref_count = 1;
  result->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  return result;
}

