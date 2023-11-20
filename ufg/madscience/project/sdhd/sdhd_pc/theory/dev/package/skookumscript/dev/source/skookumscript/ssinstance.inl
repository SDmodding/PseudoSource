// File Line: 31
// RVA: 0x105280
void __fastcall SSInstance::SSInstance(SSInstance *this)
{
  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable';
  this->i_ref_count = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable';
}

// File Line: 86
// RVA: 0xBD560
void __fastcall SSInstance::~SSInstance(SSInstance *this)
{
  this->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable';
  this->i_ptr_id = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable';
}

// File Line: 125
// RVA: 0xCF090
void __fastcall SSInstance::on_no_references(SSInstance *this)
{
  SSInstance *v1; // rbx

  v1 = this;
  SSInstance::call_destructor(this);
  v1->vfptr[1].is_actor((SSObjectBase *)&v1->vfptr);
}

// File Line: 142
// RVA: 0xCF0B0
void __fastcall SSInstance::pool_delete(SSInstance *this)
{
  SSInstance *v1; // rbx
  AObjReusePool<SSInstance> *v2; // rax
  AObjBlock<SSInstance> *v3; // rcx
  unsigned __int64 v4; // r9
  __int64 v5; // rdx
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance> > *v6; // rcx

  v1 = this;
  this->i_ptr_id = 0;
  v2 = SSInstance::get_pool();
  v3 = v2->i_block_p;
  v4 = (unsigned __int64)v3->i_objects_a;
  if ( (unsigned __int64)v1 < v4 || (v5 = v3->i_size, v6 = &v2->i_pool, (unsigned __int64)v1 >= v4 + 48 * v5) )
    v6 = &v2->i_exp_pool;
  APArray<SSInstance,SSInstance,ACompareAddress<SSInstance>>::append(v6, v1);
}

// File Line: 223
// RVA: 0x130D30
SSInstance *__fastcall SSInstance::pool_new(SSClass *class_p)
{
  SSClass *v1; // rdi
  AObjReusePool<SSInstance> *v2; // rax
  AObjReusePool<SSInstance> *v3; // rbx
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  __int64 v7; // rcx
  SSInstance **v8; // rax
  SSInstance *result; // rax
  unsigned int v10; // eax

  v1 = class_p;
  v2 = SSInstance::get_pool();
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
    AObjReusePool<SSInstance>::append_block(v3, v3->i_expand_size);
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
  result->i_class_p = v1;
  result->i_ref_count = 1;
  result->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  return result;
}

// File Line: 248
// RVA: 0x130E50
SSInstance *__fastcall SSInstance::pool_new(SSClass *class_p, unsigned __int64 user_data)
{
  unsigned __int64 v2; // rdi
  SSClass *v3; // rsi
  AObjReusePool<SSInstance> *v4; // rax
  AObjReusePool<SSInstance> *v5; // rbx
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  __int64 v9; // rcx
  SSInstance **v10; // rax
  SSInstance *result; // rax
  unsigned int v12; // eax

  v2 = user_data;
  v3 = class_p;
  v4 = SSInstance::get_pool();
  v5 = v4;
  v6 = v4->i_pool.i_count;
  if ( v6 )
  {
    v12 = v6 - 1;
    v5->i_pool.i_count = v12;
    v9 = v12;
    v10 = v5->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !v5->i_exp_pool.i_count )
    AObjReusePool<SSInstance>::append_block(v5, v5->i_expand_size);
  v7 = v5->i_exp_pool.i_count;
  if ( v7 )
  {
    v8 = v7 - 1;
    v5->i_exp_pool.i_count = v8;
    v9 = v8;
    v10 = v5->i_exp_pool.i_array_p;
LABEL_8:
    result = v10[v9];
    goto LABEL_9;
  }
  result = 0i64;
LABEL_9:
  result->i_class_p = v3;
  result->i_user_data = v2;
  result->i_ref_count = 1;
  result->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  return result;
}

// File Line: 276
// RVA: 0x130DB0
SSInstance *__fastcall SSInstance::pool_new(SSClass *class_p, unsigned __int64 user_data, unsigned __int64 user_data2)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rsi
  SSClass *v5; // rbp
  AObjReusePool<SSInstance> *v6; // rax
  AObjReusePool<SSInstance> *v7; // rbx
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  __int64 v11; // rcx
  SSInstance **v12; // rax
  SSInstance *result; // rax
  unsigned int v14; // eax

  v3 = user_data2;
  v4 = user_data;
  v5 = class_p;
  v6 = SSInstance::get_pool();
  v7 = v6;
  v8 = v6->i_pool.i_count;
  if ( v8 )
  {
    v14 = v8 - 1;
    v7->i_pool.i_count = v14;
    v11 = v14;
    v12 = v7->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !v7->i_exp_pool.i_count )
    AObjReusePool<SSInstance>::append_block(v7, v7->i_expand_size);
  v9 = v7->i_exp_pool.i_count;
  if ( v9 )
  {
    v10 = v9 - 1;
    v7->i_exp_pool.i_count = v10;
    v11 = v10;
    v12 = v7->i_exp_pool.i_array_p;
LABEL_8:
    result = v12[v11];
    goto LABEL_9;
  }
  result = 0i64;
LABEL_9:
  result->i_class_p = v5;
  result->i_user_data = v4;
  result->i_user_data2 = v3;
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

