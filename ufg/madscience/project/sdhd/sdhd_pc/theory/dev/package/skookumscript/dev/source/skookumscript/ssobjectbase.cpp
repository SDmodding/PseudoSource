// File Line: 43
// RVA: 0x118A10
AObjReusePool<SSData> *__fastcall SSData::get_pool()
{
  unsigned int v0; // edi
  unsigned int v1; // ebx
  SSData **v2; // rax

  if ( _S9_2 & 1 )
    return &s_pool_5;
  _S9_2 |= 1u;
  v0 = Skookum::get_lib_vals()->i_pool_incr_data;
  v1 = Skookum::get_lib_vals()->i_pool_init_data;
  s_pool_5.i_pool.i_count = 0;
  *(_QWORD *)&dword_142175D48 = 0i64;
  unk_142175D50 = 0;
  if ( v1 )
  {
    unk_142175D50 = v1;
    v2 = APArrayBase<SSData>::alloc_array(v1);
  }
  else
  {
    unk_142175D50 = 0;
    v2 = (SSData **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
  }
  *(_QWORD *)&dword_142175D48 = v2;
  qword_142175D58 = 0i64;
  unk_142175D60 = 0;
  qword_142175D68 = 0i64;
  unk_142175D70 = 0;
  stru_142175D78.i_count = 0;
  stru_142175D78.i_array_p = 0i64;
  stru_142175D78.i_size = 0;
  unk_142175D90 = v0;
  AObjReusePool<SSData>::append_block(&s_pool_5, v1);
  atexit(SSData::get_pool_::_2_::_dynamic_atexit_destructor_for__s_pool__);
  return &s_pool_5;
}

// File Line: 68
// RVA: 0x113D00
void __fastcall SSData::empty_table(APSortedLogical<SSData,ASymbol> *table_p)
{
  SSData **v1; // rbx
  APSortedLogical<SSData,ASymbol> *v2; // r14
  unsigned __int64 v3; // rsi
  SSInstance *v4; // rax
  bool v5; // zf
  SSData *v6; // rdi
  AObjReusePool<SSData> *v7; // rax
  AObjBlock<SSData> *v8; // rcx
  unsigned __int64 v9; // rdx
  bool v10; // cf
  APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *v11; // rcx

  v1 = table_p->i_array_p;
  v2 = table_p;
  v3 = (unsigned __int64)&v1[table_p->i_count];
  if ( (unsigned __int64)v1 >= v3 )
  {
    table_p->i_count = 0;
  }
  else
  {
    do
    {
      v4 = (*v1)->i_data_p;
      v5 = v4->i_ref_count-- == 1;
      if ( v5 )
      {
        v4->i_ref_count = 2147483648;
        v4->vfptr[1].get_scope_context((SSObjectBase *)&v4->vfptr);
      }
      v6 = *v1;
      v7 = SSData::get_pool();
      v8 = v7->i_block_p;
      v9 = (unsigned __int64)v8->i_objects_a;
      if ( (unsigned __int64)v6 < v9
        || (v10 = (unsigned __int64)v6 < v9 + 16i64 * v8->i_size,
            v11 = (APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *)v7,
            !v10) )
      {
        v11 = (APArray<SSData,ASymbol,ACompareLogical<ASymbol> > *)&v7->i_exp_pool;
      }
      APArray<SSData,ASymbol,ACompareLogical<ASymbol>>::append(v11, v6);
      ++v1;
    }
    while ( (unsigned __int64)v1 < v3 );
    v2->i_count = 0;
  }
}

// File Line: 98
// RVA: 0x10F200
SSInstance *__fastcall SSObjectBase::as_instance(SSObjectBase *this)
{
  return SSBrain::c_nil_p;
}

