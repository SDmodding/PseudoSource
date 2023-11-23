// File Line: 43
// RVA: 0x118A10
AObjReusePool<SSData> *__fastcall SSData::get_pool()
{
  unsigned int i_pool_incr_data; // edi
  unsigned int i_pool_init_data; // ebx
  SSData **v2; // rax

  if ( (_S9_2 & 1) != 0 )
    return &s_pool_5;
  _S9_2 |= 1u;
  i_pool_incr_data = Skookum::get_lib_vals()->i_pool_incr_data;
  i_pool_init_data = Skookum::get_lib_vals()->i_pool_init_data;
  s_pool_5.i_pool.i_count = 0;
  unk_142175D48 = 0i64;
  unk_142175D50 = 0;
  if ( i_pool_init_data )
  {
    unk_142175D50 = i_pool_init_data;
    v2 = APArrayBase<SSData>::alloc_array(i_pool_init_data);
  }
  else
  {
    unk_142175D50 = 0;
    v2 = (SSData **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  unk_142175D48 = v2;
  qword_142175D58 = 0i64;
  unk_142175D60 = 0;
  qword_142175D68 = 0i64;
  unk_142175D70 = 0;
  stru_142175D78.i_count = 0;
  stru_142175D78.i_array_p = 0i64;
  stru_142175D78.i_size = 0;
  unk_142175D90 = i_pool_incr_data;
  AObjReusePool<SSData>::append_block(&s_pool_5, i_pool_init_data);
  atexit(SSData::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_5;
}

// File Line: 68
// RVA: 0x113D00
void __fastcall SSData::empty_table(APSortedLogical<SSData,ASymbol> *table_p)
{
  SSData **i_array_p; // rbx
  SSData **v3; // rsi
  SSInstance *i_data_p; // rax
  SSData *v6; // rdi
  AObjReusePool<SSData> *pool; // rax
  AObjBlock<SSData> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v10; // cf
  APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *p_i_exp_pool; // rcx

  i_array_p = table_p->i_array_p;
  v3 = &i_array_p[table_p->i_count];
  if ( i_array_p >= v3 )
  {
    table_p->i_count = 0;
  }
  else
  {
    do
    {
      i_data_p = (*i_array_p)->i_data_p;
      if ( i_data_p->i_ref_count-- == 1 )
      {
        i_data_p->i_ref_count = 0x80000000;
        i_data_p->vfptr[1].get_scope_context(i_data_p);
      }
      v6 = *i_array_p;
      pool = SSData::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)v6 < i_objects_a
        || (v10 = (unsigned __int64)v6 < i_objects_a + 16i64 * i_block_p->i_size,
            p_i_exp_pool = (APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *)pool,
            !v10) )
      {
        p_i_exp_pool = (APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *)&pool->i_exp_pool;
      }
      APArray<SSData,ASymbol,ACompareLogical<ASymbol>>::append(p_i_exp_pool, v6);
      ++i_array_p;
    }
    while ( i_array_p < v3 );
    table_p->i_count = 0;
  }
}

// File Line: 98
// RVA: 0x10F200
SSInstance *__fastcall SSObjectBase::as_instance(SSObjectBase *this)
{
  return SSBrain::c_nil_p;
}

