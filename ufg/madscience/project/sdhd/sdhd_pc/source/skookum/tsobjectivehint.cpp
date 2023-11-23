// File Line: 126
// RVA: 0x4FBD20
void __fastcall UFG::TSObjectiveHint::Mthd_get_caption(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *i_data_p; // rbx
  UFG::ObjectiveTracker *p_mObjectiveTracker; // rdi
  UFG::ObjectiveHint *ObjectiveHint; // rbx
  char *mData; // rdi
  __int64 v7; // rbx
  unsigned int v8; // eax
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v14; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  UFG::qString identifier; // [rsp+38h] [rbp-30h] BYREF
  AString str; // [rsp+78h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
    p_mObjectiveTracker = &UFG::ProgressionTracker::Instance()->mObjectiveTracker;
    UFG::qString::qString(&identifier, *(const char **)i_data_p->i_user_data);
    ObjectiveHint = UFG::ObjectiveTracker::FindObjectiveHint(p_mObjectiveTracker, &identifier);
    UFG::qString::~qString(&identifier);
    mData = ObjectiveHint->mCaption.mData;
    v7 = -1i64;
    do
      ++v7;
    while ( mData[v7] );
    v8 = AMemory::c_req_byte_size_func(v7 + 1);
    str.i_str_ref_p = AStringRef::pool_new(mData, v7, v8, 1u, 0, 1);
    *ppResult = SSString::as_instance(&str);
    i_str_ref_p = str.i_str_ref_p;
    if ( str.i_str_ref_p->i_ref_count-- == 1 )
    {
      if ( i_str_ref_p->i_deallocate )
        AMemory::c_free_func(i_str_ref_p->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)i_str_ref_p < i_objects_a
        || (v14 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
            p_i_exp_pool = &pool->i_pool,
            !v14) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
    }
  }
}

