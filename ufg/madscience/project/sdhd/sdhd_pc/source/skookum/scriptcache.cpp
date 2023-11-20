// File Line: 54
// RVA: 0x15417E0
__int64 UFG::ScriptCache::_dynamic_initializer_for__smScripts__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::ScriptCache::smScripts.mTree);
  return atexit(UFG::ScriptCache::_dynamic_atexit_destructor_for__smScripts__);
}

// File Line: 105
// RVA: 0x4E16C0
SSCode *__fastcall UFG::ScriptCache::GetScriptCode(UFG::ScriptCache::Script *script)
{
  SSCode *result; // rax

  if ( script )
    result = script->mpScriptCode;
  else
    result = 0i64;
  return result;
}

// File Line: 110
// RVA: 0x50F610
void __fastcall UFG::ScriptCache::ReleaseScript(UFG::ScriptCache::Script *script)
{
  if ( script )
    --script->mRefCount;
}

// File Line: 118
// RVA: 0x4E1350
UFG::qBaseTreeRB *__fastcall UFG::ScriptCache::GetScript(const char *scriptContents, const char *classScope, const char *defaultScope, const char *dbg_name)
{
  const char *v4; // r15
  const char *v5; // rdi
  const char *v6; // rbx
  const char *v7; // r14
  SSClass *v8; // rsi
  AString *v9; // rax
  AStringRef *v10; // rbx
  bool v11; // zf
  AObjReusePool<AStringRef> *v12; // rax
  AObjBlock<AStringRef> *v13; // rcx
  unsigned __int64 v14; // rdx
  bool v15; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v16; // rcx
  unsigned int v17; // edi
  UFG::qBaseTreeRB *v18; // rbx
  SSCode *v19; // r14
  UFG::allocator::free_link *v20; // rax
  AString *v21; // rax
  unsigned int result_pos; // ST1C_4
  AStringRef *v23; // rdi
  AObjReusePool<AStringRef> *v24; // rax
  AObjBlock<AStringRef> *v25; // rcx
  unsigned __int64 v26; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v27; // rcx
  AStringRef *v28; // rdi
  AObjReusePool<AStringRef> *v29; // rax
  AObjBlock<AStringRef> *v30; // rcx
  unsigned __int64 v31; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v32; // rcx
  AObjReusePool<AStringRef> *v33; // rax
  AObjBlock<AStringRef> *v34; // rcx
  unsigned __int64 v35; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v36; // rcx
  AString result; // [rsp+30h] [rbp-69h]
  SSParser result_start; // [rsp+38h] [rbp-61h]
  AStringRef *retaddr; // [rsp+118h] [rbp+7Fh]

  v4 = dbg_name;
  v5 = defaultScope;
  v6 = classScope;
  v7 = scriptContents;
  v8 = SSBrain::get_class(classScope);
  if ( !v8 )
  {
    v9 = a_str_format(&result, "%s is not a valid class, will assume it's scope is %x", v6, v5);
    SSDebug::print_error(v9, AErrLevel_error);
    v10 = result.i_str_ref_p;
    v11 = result.i_str_ref_p->i_ref_count == 1;
    --v10->i_ref_count;
    if ( v11 )
    {
      if ( v10->i_deallocate )
        AMemory::c_free_func(v10->i_cstr_p);
      v12 = AStringRef::get_pool();
      v13 = v12->i_block_p;
      v14 = (unsigned __int64)v13->i_objects_a;
      if ( (unsigned __int64)v10 < v14
        || (v15 = (unsigned __int64)v10 < v14 + 24i64 * v13->i_size, v16 = &v12->i_pool, !v15) )
      {
        v16 = &v12->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v16, v10);
    }
    v8 = SSBrain::get_class(v5);
  }
  if ( retaddr )
    v17 = (unsigned int)retaddr->i_cstr_p;
  else
    v17 = UFG::qStringHash32(v7, 0xFFFFFFFF);
  if ( !v17 )
  {
LABEL_19:
    v18 = 0i64;
    goto LABEL_20;
  }
  v18 = UFG::qBaseTreeRB::Get(&UFG::ScriptCache::smScripts.mTree, v17);
  if ( v18 )
  {
    while ( v18->mRoot.mUID == v17 )
    {
      if ( (SSClass *)v18->mNULL.mChild[1] == v8 )
        goto LABEL_50;
      v18 = UFG::qBaseTreeRB::GetNext(&UFG::ScriptCache::smScripts.mTree, &v18->mRoot);
      if ( !v18 )
        goto LABEL_20;
    }
    goto LABEL_19;
  }
LABEL_20:
  if ( !v7 || !*v7 )
    return 0i64;
  retaddr = AStringRef::get_empty();
  ++retaddr->i_ref_count;
  UFG::SkookumMgr::ConstructCodeBlockFromScript((AString *)&retaddr, v7);
  SSParser::SSParser(&result_start, (AString *)&retaddr);
  SSParser::set_class_scope(&result_start, (SSClassUnaryBase *)&v8->vfptr);
  LODWORD(result_start.i_str_ref_p) = 0;
  *(AStringRef **)((char *)&result_start.i_str_ref_p + 4) = (AStringRef *)1;
  v19 = SSParser::parse_code_block(&result_start, (SSParser::Args *)&result_start, SSInvokeTime_any, ResultDesired_true);
  if ( v19 )
  {
    v20 = UFG::qMalloc(0x38ui64, "ScriptCache::Script", 0i64);
    v18 = (UFG::qBaseTreeRB *)v20;
    result.i_str_ref_p = (AStringRef *)v20;
    if ( v20 )
    {
      v20->mNext = 0i64;
      v20[1].mNext = 0i64;
      v20[2].mNext = 0i64;
      LODWORD(v20[3].mNext) = v17;
      LODWORD(v20[4].mNext) = 0;
      v20[5].mNext = 0i64;
      v20[6].mNext = 0i64;
    }
    else
    {
      v18 = 0i64;
    }
    v18->mNULL.mChild[1] = (UFG::qBaseNodeRB *)v8;
    v18->mNULL.mChild[0] = (UFG::qBaseNodeRB *)v19;
    UFG::qBaseTreeRB::Add(&UFG::ScriptCache::smScripts.mTree, &v18->mRoot);
  }
  else
  {
    v21 = a_str_format(&result, "SkookumTrack in Node %s\n", v4);
    SSDebug::print_error(
      (SSParser::eResult)result_start.i_flags.i_flagset,
      v21,
      (AString *)&retaddr,
      result_pos,
      (unsigned int)result_start.i_str_ref_p,
      0);
    v23 = result.i_str_ref_p;
    v11 = result.i_str_ref_p->i_ref_count == 1;
    --v23->i_ref_count;
    if ( v11 )
    {
      if ( v23->i_deallocate )
        AMemory::c_free_func(v23->i_cstr_p);
      v24 = AStringRef::get_pool();
      v25 = v24->i_block_p;
      v26 = (unsigned __int64)v25->i_objects_a;
      if ( (unsigned __int64)v23 < v26
        || (v15 = (unsigned __int64)v23 < v26 + 24i64 * v25->i_size, v27 = &v24->i_pool, !v15) )
      {
        v27 = &v24->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v27, v23);
    }
    UFG::qPrintf("Skookum code in %s failed to parse: %s", v4, retaddr->i_cstr_p);
  }
  SSTypeContext::~SSTypeContext(&result_start.i_context);
  v28 = result_start.i_str_ref_p;
  v11 = result_start.i_str_ref_p->i_ref_count == 1;
  --v28->i_ref_count;
  if ( v11 )
  {
    if ( v28->i_deallocate )
      AMemory::c_free_func(v28->i_cstr_p);
    v29 = AStringRef::get_pool();
    v30 = v29->i_block_p;
    v31 = (unsigned __int64)v30->i_objects_a;
    if ( (unsigned __int64)v28 < v31
      || (v15 = (unsigned __int64)v28 < v31 + 24i64 * v30->i_size, v32 = &v29->i_pool, !v15) )
    {
      v32 = &v29->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v32, v28);
  }
  v11 = retaddr->i_ref_count-- == 1;
  if ( v11 )
  {
    if ( retaddr->i_deallocate )
      AMemory::c_free_func(retaddr->i_cstr_p);
    v33 = AStringRef::get_pool();
    v34 = v33->i_block_p;
    v35 = (unsigned __int64)v34->i_objects_a;
    if ( (unsigned __int64)retaddr < v35
      || (v15 = (unsigned __int64)retaddr < v35 + 24i64 * v34->i_size, v36 = &v33->i_pool, !v15) )
    {
      v36 = &v33->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v36, retaddr);
  }
  if ( v18 )
LABEL_50:
    ++LODWORD(v18->mNULL.mParent);
  return v18;
}

