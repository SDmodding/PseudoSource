// File Line: 197
// RVA: 0xBB4C0
void __fastcall AStringRef::dereference(AStringRef *this)
{
  AStringRef *v1; // rbx
  bool v2; // zf
  AObjReusePool<AStringRef> *v3; // rax
  AObjBlock<AStringRef> *v4; // rcx
  unsigned __int64 v5; // r8
  bool v6; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v7; // rcx

  v1 = this;
  v2 = this->i_ref_count-- == 1;
  if ( v2 )
  {
    if ( this->i_deallocate )
      AMemory::c_free_func(this->i_cstr_p);
    v3 = AStringRef::get_pool();
    v4 = v3->i_block_p;
    v5 = (unsigned __int64)v4->i_objects_a;
    if ( (unsigned __int64)v1 < v5 || (v6 = (unsigned __int64)v1 < v5 + 24i64 * v4->i_size, v7 = &v3->i_pool, !v6) )
      v7 = &v3->i_exp_pool;
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v7, v1);
  }
}

// File Line: 216
// RVA: 0xBB520
void __fastcall AStringRef::pool_delete(AStringRef *str_ref_p)
{
  AStringRef *v1; // rbx
  AObjReusePool<AStringRef> *v2; // rax
  AObjBlock<AStringRef> *v3; // rcx
  unsigned __int64 v4; // r8
  bool v5; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v6; // rcx

  v1 = str_ref_p;
  if ( str_ref_p->i_deallocate )
    AMemory::c_free_func(str_ref_p->i_cstr_p);
  v2 = AStringRef::get_pool();
  v3 = v2->i_block_p;
  v4 = (unsigned __int64)v3->i_objects_a;
  if ( (unsigned __int64)v1 < v4 || (v5 = (unsigned __int64)v1 < v4 + 24i64 * v3->i_size, v6 = &v2->i_pool, !v5) )
    v6 = &v2->i_exp_pool;
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v6, v1);
}

