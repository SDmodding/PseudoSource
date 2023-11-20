// File Line: 126
// RVA: 0x4FBD20
void __fastcall UFG::TSObjectiveHint::Mthd_get_caption(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  SSInstance *v3; // rbx
  UFG::ObjectiveTracker *v4; // rdi
  UFG::ObjectiveHint *v5; // rbx
  const char *v6; // rdi
  signed __int64 v7; // rbx
  unsigned int v8; // eax
  AStringRef *v9; // rbx
  bool v10; // zf
  AObjReusePool<AStringRef> *v11; // rax
  AObjBlock<AStringRef> *v12; // rcx
  unsigned __int64 v13; // rdx
  bool v14; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v15; // rcx
  UFG::qString identifier; // [rsp+38h] [rbp-30h]
  AString str; // [rsp+78h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = (*pScope->i_data.i_array_p)->i_data_p;
    v4 = &UFG::ProgressionTracker::Instance()->mObjectiveTracker;
    UFG::qString::qString(&identifier, *(const char **)v3->i_user_data);
    v5 = UFG::ObjectiveTracker::FindObjectiveHint(v4, &identifier);
    UFG::qString::~qString(&identifier);
    v6 = v5->mCaption.mData;
    v7 = -1i64;
    do
      ++v7;
    while ( v6[v7] );
    v8 = AMemory::c_req_byte_size_func(v7 + 1);
    str.i_str_ref_p = AStringRef::pool_new(v6, v7, v8, 1u, 0, 1);
    *v2 = SSString::as_instance(&str);
    v9 = str.i_str_ref_p;
    v10 = str.i_str_ref_p->i_ref_count == 1;
    --v9->i_ref_count;
    if ( v10 )
    {
      if ( v9->i_deallocate )
        AMemory::c_free_func(v9->i_cstr_p);
      v11 = AStringRef::get_pool();
      v12 = v11->i_block_p;
      v13 = (unsigned __int64)v12->i_objects_a;
      if ( (unsigned __int64)v9 < v13
        || (v14 = (unsigned __int64)v9 < v13 + 24i64 * v12->i_size, v15 = &v11->i_pool, !v14) )
      {
        v15 = &v11->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v15, v9);
    }
  }
}

