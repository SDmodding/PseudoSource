// File Line: 31
// RVA: 0x104290
void __fastcall SSBoolean::SSBoolean(SSBoolean *this)
{
  SSClass *v1; // rax

  v1 = SSBrain::c_boolean_class_p;
  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable';
  this->i_ref_count = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable';
  this->i_class_p = v1;
  this->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  this->vfptr = (SSObjectBaseVtbl *)&SSBoolean::`vftable';
}

// File Line: 49
// RVA: 0x130AB0
SSBoolean *__fastcall SSBoolean::pool_new(bool bool_value)
{
  bool v1; // di
  AObjReusePool<SSBoolean> *v2; // rax
  AObjReusePool<SSBoolean> *v3; // rbx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  __int64 v7; // rcx
  SSBoolean **v8; // rax
  SSBoolean *result; // rax
  unsigned int v10; // eax

  v1 = bool_value;
  v2 = SSBoolean::get_pool();
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
    AObjReusePool<SSBoolean>::append_block(v3, v3->i_expand_size);
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
  result->i_ref_count = 1;
  result->i_user_data = v1;
  result->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  return result;
}

// File Line: 71
// RVA: 0x130A30
SSBoolean *__fastcall SSBoolean::pool_new(unsigned __int64 bool_value)
{
  unsigned __int64 v1; // rdi
  AObjReusePool<SSBoolean> *v2; // rax
  AObjReusePool<SSBoolean> *v3; // rbx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  __int64 v7; // rcx
  SSBoolean **v8; // rax
  SSBoolean *result; // rax
  unsigned int v10; // eax

  v1 = bool_value;
  v2 = SSBoolean::get_pool();
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
    AObjReusePool<SSBoolean>::append_block(v3, v3->i_expand_size);
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
  result->i_user_data = v1;
  result->i_ref_count = 1;
  result->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  return result;
}

