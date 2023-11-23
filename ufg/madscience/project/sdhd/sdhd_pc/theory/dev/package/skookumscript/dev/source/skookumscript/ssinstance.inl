// File Line: 31
// RVA: 0x105280
void __fastcall SSInstance::SSInstance(SSInstance *this)
{
  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
  this->i_ref_count = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable;
}

// File Line: 86
// RVA: 0xBD560
void __fastcall SSInstance::~SSInstance(SSInstance *this)
{
  this->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable;
  this->i_ptr_id = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
}

// File Line: 125
// RVA: 0xCF090
void __fastcall SSInstance::on_no_references(SSInstance *this)
{
  SSInstance::call_destructor(this);
  this->vfptr[1].is_actor(this);
}

// File Line: 142
// RVA: 0xCF0B0
void __fastcall SSInstance::pool_delete(SSInstance *this)
{
  AObjReusePool<SSInstance> *pool; // rax
  AObjBlock<SSInstance> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // r9
  __int64 i_size; // rdx
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *p_i_exp_pool; // rcx

  this->i_ptr_id = 0;
  pool = SSInstance::get_pool();
  i_block_p = pool->i_block_p;
  i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
  if ( (unsigned __int64)this < i_objects_a
    || (i_size = i_block_p->i_size, p_i_exp_pool = &pool->i_pool, (unsigned __int64)this >= i_objects_a + 48 * i_size) )
  {
    p_i_exp_pool = &pool->i_exp_pool;
  }
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(p_i_exp_pool, this);
}

// File Line: 223
// RVA: 0x130D30
SSInstance *__fastcall SSInstance::pool_new(SSClass *class_p)
{
  AObjReusePool<SSInstance> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v4; // eax
  __int64 v5; // rcx
  SSInstance **i_array_p; // rax
  SSInstance *result; // rax
  unsigned int v8; // eax

  pool = SSInstance::get_pool();
  if ( pool->i_pool.i_count )
  {
    v8 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v8;
    v5 = v8;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<SSInstance>::append_block(pool, pool->i_expand_size);
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
  result->i_class_p = class_p;
  result->i_ref_count = 1;
  result->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  return result;
}

// File Line: 248
// RVA: 0x130E50
SSInstance *__fastcall SSInstance::pool_new(SSClass *class_p, unsigned __int64 user_data)
{
  AObjReusePool<SSInstance> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v6; // eax
  __int64 v7; // rcx
  SSInstance **i_array_p; // rax
  SSInstance *result; // rax
  unsigned int v10; // eax

  pool = SSInstance::get_pool();
  if ( pool->i_pool.i_count )
  {
    v10 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v10;
    v7 = v10;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<SSInstance>::append_block(pool, pool->i_expand_size);
  i_count = pool->i_exp_pool.i_count;
  if ( i_count )
  {
    v6 = i_count - 1;
    pool->i_exp_pool.i_count = v6;
    v7 = v6;
    i_array_p = pool->i_exp_pool.i_array_p;
LABEL_8:
    result = i_array_p[v7];
    goto LABEL_9;
  }
  result = 0i64;
LABEL_9:
  result->i_class_p = class_p;
  result->i_user_data = user_data;
  result->i_ref_count = 1;
  result->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  return result;
}

// File Line: 276
// RVA: 0x130DB0
SSInstance *__fastcall SSInstance::pool_new(SSClass *class_p, unsigned __int64 user_data, unsigned __int64 user_data2)
{
  AObjReusePool<SSInstance> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v8; // eax
  __int64 v9; // rcx
  SSInstance **i_array_p; // rax
  SSInstance *result; // rax
  unsigned int v12; // eax

  pool = SSInstance::get_pool();
  if ( pool->i_pool.i_count )
  {
    v12 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v12;
    v9 = v12;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<SSInstance>::append_block(pool, pool->i_expand_size);
  i_count = pool->i_exp_pool.i_count;
  if ( i_count )
  {
    v8 = i_count - 1;
    pool->i_exp_pool.i_count = v8;
    v9 = v8;
    i_array_p = pool->i_exp_pool.i_array_p;
LABEL_8:
    result = i_array_p[v9];
    goto LABEL_9;
  }
  result = 0i64;
LABEL_9:
  result->i_class_p = class_p;
  result->i_user_data = user_data;
  result->i_user_data2 = user_data2;
  result->i_ref_count = 1;
  result->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  return result;
}

// File Line: 393
// RVA: 0x126C60
void __fastcall SSInstanceUnreffed::on_no_references(SSInstanceUnreffed *this)
{
  this->i_ref_count = 1000000;
}

