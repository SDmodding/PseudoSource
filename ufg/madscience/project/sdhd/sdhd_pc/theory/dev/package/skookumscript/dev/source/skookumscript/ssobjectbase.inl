// File Line: 39
// RVA: 0x130C30
SSData *__fastcall SSData::pool_new(ASymbol *name)
{
  ASymbol *v1; // rdi
  AObjReusePool<SSData> *v2; // rax
  AObjReusePool<SSData> *v3; // rbx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  __int64 v7; // rcx
  SSData **v8; // rax
  SSData *result; // rax
  unsigned int v10; // eax

  v1 = name;
  v2 = SSData::get_pool();
  v3 = v2;
  v4 = v2->i_pool.i_count;
  if ( v4 )
  {
    v10 = v4 - 1;
    v3->i_pool.i_count = v10;
    v7 = v10;
    v8 = v3->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !v3->i_exp_pool.i_count )
    AObjReusePool<SSData>::append_block(v3, v3->i_expand_size);
  v5 = v3->i_exp_pool.i_count;
  if ( v5 )
  {
    v6 = v5 - 1;
    v3->i_exp_pool.i_count = v6;
    v7 = v6;
    v8 = v3->i_exp_pool.i_array_p;
LABEL_8:
    result = v8[v7];
    goto LABEL_9;
  }
  result = 0i64;
LABEL_9:
  result->i_name = (ASymbol)v1->i_uid;
  result->i_data_p = SSBrain::c_nil_p;
  return result;
}

