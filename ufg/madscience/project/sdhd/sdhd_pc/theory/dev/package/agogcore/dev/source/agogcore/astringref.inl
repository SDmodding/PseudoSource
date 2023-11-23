// File Line: 197
// RVA: 0xBB4C0
void __fastcall AStringRef::dereference(AStringRef *this)
{
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // r8
  bool v6; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx

  if ( this->i_ref_count-- == 1 )
  {
    if ( this->i_deallocate )
      AMemory::c_free_func(this->i_cstr_p);
    pool = AStringRef::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)this < i_objects_a
      || (v6 = (unsigned __int64)this < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v6) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, this);
  }
}

// File Line: 216
// RVA: 0xBB520
void __fastcall AStringRef::pool_delete(AStringRef *str_ref_p)
{
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // r8
  bool v5; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx

  if ( str_ref_p->i_deallocate )
    AMemory::c_free_func(str_ref_p->i_cstr_p);
  pool = AStringRef::get_pool();
  i_block_p = pool->i_block_p;
  i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
  if ( (unsigned __int64)str_ref_p < i_objects_a
    || (v5 = (unsigned __int64)str_ref_p < i_objects_a + 24i64 * i_block_p->i_size, p_i_exp_pool = &pool->i_pool, !v5) )
  {
    p_i_exp_pool = &pool->i_exp_pool;
  }
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, str_ref_p);
}

