// File Line: 54
// RVA: 0x15417E0
__int64 UFG::ScriptCache::_dynamic_initializer_for__smScripts__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::ScriptCache::smScripts.mTree);
  return atexit((int (__fastcall *)())UFG::ScriptCache::_dynamic_atexit_destructor_for__smScripts__);
}

// File Line: 105
// RVA: 0x4E16C0
SSCode *__fastcall UFG::ScriptCache::GetScriptCode(UFG::ScriptCache::Script *script)
{
  if ( script )
    return script->mpScriptCode;
  else
    return 0i64;
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
UFG::qBaseTreeRB *__fastcall UFG::ScriptCache::GetScript(
        char *scriptContents,
        const char *classScope,
        const char *defaultScope,
        const char *dbg_name)
{
  SSClass *v8; // rsi
  AString *v9; // rax
  AStringRef *i_str_ref_p; // rbx
  bool v11; // zf
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v15; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  unsigned int i_cstr_p; // edi
  UFG::qBaseTreeRB *Next; // rbx
  SSCode *v19; // r14
  UFG::allocator::free_link *v20; // rax
  AString *v21; // rax
  AStringRef *v22; // rdi
  AObjReusePool<AStringRef> *v23; // rax
  AObjBlock<AStringRef> *v24; // rcx
  unsigned __int64 v25; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_pool; // rcx
  AStringRef *v27; // rdi
  AObjReusePool<AStringRef> *v28; // rax
  AObjBlock<AStringRef> *v29; // rcx
  unsigned __int64 v30; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v31; // rcx
  AObjReusePool<AStringRef> *v32; // rax
  AObjBlock<AStringRef> *v33; // rcx
  unsigned __int64 v34; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v35; // rcx
  unsigned int result_pos; // [rsp+1Ch] [rbp-7Dh]
  AString result; // [rsp+30h] [rbp-69h] BYREF
  SSParser result_start; // [rsp+38h] [rbp-61h] BYREF
  AString retaddr; // [rsp+118h] [rbp+7Fh] BYREF

  v8 = SSBrain::get_class(classScope);
  if ( !v8 )
  {
    v9 = a_str_format(&result, "%s is not a valid class, will assume its scope is %x", classScope, defaultScope);
    SSDebug::print_error(v9, 3);
    i_str_ref_p = result.i_str_ref_p;
    v11 = result.i_str_ref_p->i_ref_count-- == 1;
    if ( v11 )
    {
      if ( i_str_ref_p->i_deallocate )
        AMemory::c_free_func(i_str_ref_p->i_cstr_p);
      pool = AStringRef::get_pool();
      i_block_p = pool->i_block_p;
      i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
      if ( (unsigned __int64)i_str_ref_p < i_objects_a
        || (v15 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
            p_i_exp_pool = &pool->i_pool,
            !v15) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
    }
    v8 = SSBrain::get_class(defaultScope);
  }
  if ( retaddr.i_str_ref_p )
    i_cstr_p = (unsigned int)retaddr.i_str_ref_p->i_cstr_p;
  else
    i_cstr_p = UFG::qStringHash32(scriptContents, 0xFFFFFFFF);
  if ( !i_cstr_p )
  {
LABEL_19:
    Next = 0i64;
    goto LABEL_20;
  }
  Next = UFG::qBaseTreeRB::Get(&UFG::ScriptCache::smScripts.mTree, i_cstr_p);
  if ( Next )
  {
    while ( Next->mRoot.mUID == i_cstr_p )
    {
      if ( (SSClass *)Next->mNULL.mChild[1] == v8 )
        goto LABEL_50;
      Next = UFG::qBaseTreeRB::GetNext(&UFG::ScriptCache::smScripts.mTree, &Next->mRoot);
      if ( !Next )
        goto LABEL_20;
    }
    goto LABEL_19;
  }
LABEL_20:
  if ( !scriptContents || !*scriptContents )
    return 0i64;
  retaddr.i_str_ref_p = AStringRef::get_empty();
  ++retaddr.i_str_ref_p->i_ref_count;
  UFG::SkookumMgr::ConstructCodeBlockFromScript(&retaddr, scriptContents);
  SSParser::SSParser(&result_start, &retaddr);
  SSParser::set_class_scope(&result_start, v8);
  LODWORD(result_start.i_str_ref_p) = 0;
  *(AStringRef **)((char *)&result_start.i_str_ref_p + 4) = (AStringRef *)1;
  v19 = SSParser::parse_code_block(&result_start, (SSParser::Args *)&result_start, SSInvokeTime_any, ResultDesired_true);
  if ( v19 )
  {
    v20 = UFG::qMalloc(0x38ui64, "ScriptCache::Script", 0i64);
    Next = (UFG::qBaseTreeRB *)v20;
    result.i_str_ref_p = (AStringRef *)v20;
    if ( v20 )
    {
      v20->mNext = 0i64;
      v20[1].mNext = 0i64;
      v20[2].mNext = 0i64;
      LODWORD(v20[3].mNext) = i_cstr_p;
      LODWORD(v20[4].mNext) = 0;
      v20[5].mNext = 0i64;
      v20[6].mNext = 0i64;
    }
    else
    {
      Next = 0i64;
    }
    Next->mNULL.mChild[1] = (UFG::qBaseNodeRB *)v8;
    Next->mNULL.mChild[0] = (UFG::qBaseNodeRB *)v19;
    UFG::qBaseTreeRB::Add(&UFG::ScriptCache::smScripts.mTree, &Next->mRoot);
  }
  else
  {
    v21 = a_str_format(&result, "SkookumTrack in Node %s\n", dbg_name);
    SSDebug::print_error(
      (SSParser::eResult)result_start.i_flags.i_flagset,
      v21,
      &retaddr,
      result_pos,
      (unsigned int)result_start.i_str_ref_p,
      0);
    v22 = result.i_str_ref_p;
    v11 = result.i_str_ref_p->i_ref_count-- == 1;
    if ( v11 )
    {
      if ( v22->i_deallocate )
        AMemory::c_free_func(v22->i_cstr_p);
      v23 = AStringRef::get_pool();
      v24 = v23->i_block_p;
      v25 = (unsigned __int64)v24->i_objects_a;
      if ( (unsigned __int64)v22 < v25
        || (v15 = (unsigned __int64)v22 < v25 + 24i64 * v24->i_size, p_i_pool = &v23->i_pool, !v15) )
      {
        p_i_pool = &v23->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_pool, v22);
    }
    UFG::qPrintf("Skookum code in %s failed to parse: %s", dbg_name, retaddr.i_str_ref_p->i_cstr_p);
  }
  SSTypeContext::~SSTypeContext(&result_start.i_context);
  v27 = result_start.i_str_ref_p;
  v11 = result_start.i_str_ref_p->i_ref_count-- == 1;
  if ( v11 )
  {
    if ( v27->i_deallocate )
      AMemory::c_free_func(v27->i_cstr_p);
    v28 = AStringRef::get_pool();
    v29 = v28->i_block_p;
    v30 = (unsigned __int64)v29->i_objects_a;
    if ( (unsigned __int64)v27 < v30
      || (v15 = (unsigned __int64)v27 < v30 + 24i64 * v29->i_size, v31 = &v28->i_pool, !v15) )
    {
      v31 = &v28->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v31, v27);
  }
  v11 = retaddr.i_str_ref_p->i_ref_count-- == 1;
  if ( v11 )
  {
    if ( retaddr.i_str_ref_p->i_deallocate )
      AMemory::c_free_func(retaddr.i_str_ref_p->i_cstr_p);
    v32 = AStringRef::get_pool();
    v33 = v32->i_block_p;
    v34 = (unsigned __int64)v33->i_objects_a;
    if ( (unsigned __int64)retaddr.i_str_ref_p < v34
      || (v15 = (unsigned __int64)retaddr.i_str_ref_p < v34 + 24i64 * v33->i_size, v35 = &v32->i_pool, !v15) )
    {
      v35 = &v32->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v35, retaddr.i_str_ref_p);
  }
  if ( Next )
LABEL_50:
    ++LODWORD(Next->mNULL.mParent);
  return Next;
}

