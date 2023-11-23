// File Line: 39
// RVA: 0x130C30
SSData *__fastcall SSData::pool_new(ASymbol *name)
{
  AObjReusePool<SSData> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v4; // eax
  __int64 v5; // rcx
  SSData **i_array_p; // rax
  SSData *result; // rax
  unsigned int v8; // eax

  pool = SSData::get_pool();
  if ( pool->i_pool.i_count )
  {
    v8 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v8;
    v5 = v8;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<SSData>::append_block(pool, pool->i_expand_size);
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
  result->i_name = (ASymbol)name->i_uid;
  result->i_data_p = SSBrain::c_nil_p;
  return result;
}

