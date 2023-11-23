// File Line: 34
// RVA: 0x106F50
void __fastcall SSDataInstance::~SSDataInstance(SSDataInstance *this)
{
  APSortedLogical<SSData,ASymbol> *p_i_data; // rbx

  this->vfptr = (SSObjectBaseVtbl *)&SSDataInstance::`vftable;
  p_i_data = &this->i_data;
  SSData::empty_table(&this->i_data);
  AMemory::c_free_func(p_i_data->i_array_p);
  this->vfptr = (SSObjectBaseVtbl *)&SSInstance::`vftable;
  this->i_ptr_id = 0;
  this->vfptr = (SSObjectBaseVtbl *)&SSObjectBase::`vftable;
}

// File Line: 42
// RVA: 0x1097D0
void __fastcall SSDataInstance::add_data_members(SSDataInstance *this)
{
  SSClass *i_class_p; // rdi
  __int64 i_count; // rax
  SSTypedName **i_array_p; // rdi
  SSTypedName **v4; // rbp
  APSortedLogical<SSData,ASymbol> *p_i_data; // r14
  unsigned int *v6; // rsi
  AObjReusePool<SSData> *pool; // rbx
  unsigned int v8; // eax
  unsigned int v9; // eax
  __int64 v10; // rcx
  SSData **v11; // rax
  SSData *v12; // rdx
  unsigned int v13; // eax

  i_class_p = this->i_class_p;
  i_count = i_class_p->i_data_table.i_count;
  if ( (_DWORD)i_count )
  {
    i_array_p = i_class_p->i_data_table.i_array_p;
    v4 = &i_array_p[i_count];
    if ( i_array_p < v4 )
    {
      p_i_data = &this->i_data;
      while ( 1 )
      {
        v6 = (unsigned int *)*i_array_p;
        pool = SSData::get_pool();
        if ( pool->i_pool.i_count )
          break;
        if ( !pool->i_exp_pool.i_count )
          AObjReusePool<SSData>::append_block(pool, pool->i_expand_size);
        v8 = pool->i_exp_pool.i_count;
        if ( v8 )
        {
          v9 = v8 - 1;
          pool->i_exp_pool.i_count = v9;
          v10 = v9;
          v11 = pool->i_exp_pool.i_array_p;
LABEL_11:
          v12 = v11[v10];
          goto LABEL_12;
        }
        v12 = 0i64;
LABEL_12:
        v12->i_name.i_uid = *v6;
        v12->i_data_p = SSBrain::c_nil_p;
        APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::append(p_i_data, v12, 0i64);
        if ( ++i_array_p >= v4 )
          return;
      }
      v13 = pool->i_pool.i_count - 1;
      pool->i_pool.i_count = v13;
      v10 = v13;
      v11 = pool->i_pool.i_array_p;
      goto LABEL_11;
    }
  }
}

// File Line: 68
// RVA: 0x1177A0
SSClassDescBase *__fastcall SSDataInstance::get_data_by_name(SSDataInstance *this, ASymbol *name)
{
  SSTypedName *v4; // rax
  SSMetaClass *v6; // rax

  v4 = APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&this->i_data,
         name);
  if ( v4 )
    return v4->i_type_p.i_obj_p;
  v6 = this->i_class_p->SSInstance::vfptr->get_metaclass(this->i_class_p);
  return (SSClassDescBase *)v6->SSInstanceUnreffed::SSInstance::SSObjectBase::vfptr->get_data_by_name(
                              &v6->SSInstanceUnreffed,
                              name);
}

// File Line: 84
// RVA: 0x1176C0
SSData *__fastcall SSDataInstance::get_data_by_instance(SSDataInstance *this, SSInstance *obj)
{
  __int64 i_count; // rdx
  SSData **i_array_p; // rax
  SSData **v5; // rdx

  i_count = this->i_data.i_count;
  if ( !(_DWORD)i_count )
    return 0i64;
  i_array_p = this->i_data.i_array_p;
  v5 = &i_array_p[i_count];
  if ( i_array_p >= v5 )
    return 0i64;
  while ( obj != (*i_array_p)->i_data_p )
  {
    if ( ++i_array_p >= v5 )
      return 0i64;
  }
  return *i_array_p;
}

// File Line: 122
// RVA: 0x13C460
void __fastcall SSDataInstance::set_data_by_name(SSDataInstance *this, ASymbol *name, SSClassDescBase *obj_p)
{
  SSTypedName *v6; // rax
  SSTypedName *v7; // rdi
  SSClassDescBase *i_obj_p; // rcx
  SSMetaClass *v10; // rax

  v6 = APSorted<SSData,ASymbol,ACompareLogical<ASymbol>>::get(
         (APSorted<SSTypedName,ASymbol,ACompareLogical<ASymbol> > *)&this->i_data,
         name);
  v7 = v6;
  if ( v6 )
  {
    ++LODWORD(obj_p[2].vfptr);
    i_obj_p = v6->i_type_p.i_obj_p;
    if ( LODWORD(i_obj_p[2].vfptr)-- == 1 )
    {
      LODWORD(i_obj_p[2].vfptr) = 0x80000000;
      i_obj_p->vfptr->get_item_type(i_obj_p);
    }
    v7->i_type_p.i_obj_p = obj_p;
  }
  else
  {
    v10 = this->i_class_p->SSInstance::vfptr->get_metaclass(this->i_class_p);
    v10->SSInstanceUnreffed::SSInstance::SSObjectBase::vfptr->set_data_by_name(
      &v10->SSInstanceUnreffed,
      name,
      (SSInstance *)obj_p);
  }
}

// File Line: 152
// RVA: 0x130CA0
SSDataInstance *__fastcall SSDataInstance::pool_new(SSClass *class_p)
{
  AObjReusePool<SSDataInstance> *pool; // rbx
  unsigned int i_count; // eax
  unsigned int v4; // eax
  __int64 v5; // rcx
  SSDataInstance **i_array_p; // rax
  SSDataInstance *v7; // rbx
  unsigned int v8; // eax

  pool = SSDataInstance::get_pool();
  if ( pool->i_pool.i_count )
  {
    v8 = pool->i_pool.i_count - 1;
    pool->i_pool.i_count = v8;
    v5 = v8;
    i_array_p = pool->i_pool.i_array_p;
    goto LABEL_8;
  }
  if ( !pool->i_exp_pool.i_count )
    AObjReusePool<SSDataInstance>::append_block(pool, pool->i_expand_size);
  i_count = pool->i_exp_pool.i_count;
  if ( i_count )
  {
    v4 = i_count - 1;
    pool->i_exp_pool.i_count = v4;
    v5 = v4;
    i_array_p = pool->i_exp_pool.i_array_p;
LABEL_8:
    v7 = i_array_p[v5];
    goto LABEL_9;
  }
  v7 = 0i64;
LABEL_9:
  v7->i_class_p = class_p;
  v7->i_ref_count = 1;
  v7->i_ptr_id = ++SSObjectBase::c_ptr_id_prev;
  SSDataInstance::add_data_members(v7);
  return v7;
}

// File Line: 174
// RVA: 0x130780
void __fastcall SSDataInstance::pool_delete(SSDataInstance *this)
{
  AObjReusePool<SSDataInstance> *pool; // rax
  AObjBlock<SSDataInstance> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // r9
  __int64 i_size; // rdx
  APArray<SSDataInstance,SSDataInstance,ACompareAddress<SSDataInstance> > *p_i_exp_pool; // rcx

  SSData::empty_table(&this->i_data);
  this->i_ptr_id = 0;
  pool = SSDataInstance::get_pool();
  i_block_p = pool->i_block_p;
  i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
  if ( (unsigned __int64)this < i_objects_a
    || (i_size = i_block_p->i_size, p_i_exp_pool = &pool->i_pool, (unsigned __int64)this >= i_objects_a + 72 * i_size) )
  {
    p_i_exp_pool = &pool->i_exp_pool;
  }
  APArray<SSDataInstance,SSDataInstance,ACompareAddress<SSDataInstance>>::append(p_i_exp_pool, this);
}

// File Line: 193
// RVA: 0x118B10
AObjReusePool<SSDataInstance> *__fastcall SSDataInstance::get_pool()
{
  unsigned int i_pool_incr_data_instance; // edi
  unsigned int i_pool_init_data_instance; // ebx
  SSDataInstance **v2; // rax

  if ( (_S4_3 & 1) != 0 )
    return &s_pool_0;
  _S4_3 |= 1u;
  i_pool_incr_data_instance = Skookum::get_lib_vals()->i_pool_incr_data_instance;
  i_pool_init_data_instance = Skookum::get_lib_vals()->i_pool_init_data_instance;
  s_pool_0.i_pool.i_count = 0;
  unk_142175B68 = 0i64;
  unk_142175B70 = 0;
  if ( i_pool_init_data_instance )
  {
    unk_142175B70 = i_pool_init_data_instance;
    v2 = APArrayBase<SSDataInstance>::alloc_array(i_pool_init_data_instance);
  }
  else
  {
    unk_142175B70 = 0;
    v2 = (SSDataInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  unk_142175B68 = v2;
  qword_142175B78 = 0i64;
  unk_142175B80 = 0;
  qword_142175B88 = 0i64;
  unk_142175B90 = 0;
  stru_142175B98.i_count = 0;
  stru_142175B98.i_array_p = 0i64;
  stru_142175B98.i_size = 0;
  unk_142175BB0 = i_pool_incr_data_instance;
  AObjReusePool<SSDataInstance>::append_block(&s_pool_0, i_pool_init_data_instance);
  atexit(SSDataInstance::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_0;
}

