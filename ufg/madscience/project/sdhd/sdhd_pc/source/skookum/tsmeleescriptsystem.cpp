// File Line: 44
// RVA: 0x4D4430
void UFG::TSMeleeScriptSystem::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("MeleeScriptSystem");
  SSClass::register_method_func(
    v0,
    "get_active_gameslices",
    UFG::TSMeleeScriptSystem::Mthd_get_active_gameslices,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    v0,
    "get_spawn_group",
    UFG::TSMeleeScriptSystem::Mthd_get_spawn_group,
    SSBindFlag_instance_no_rebind);
  SSClass::register_method_func(
    v0,
    "get_start_trigger",
    UFG::TSMeleeScriptSystem::Mthd_get_start_trigger,
    SSBindFlag_instance_no_rebind);
}

// File Line: 57
// RVA: 0x4FB1E0
void __fastcall UFG::TSMeleeScriptSystem::Mthd_get_active_gameslices(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  int v5; // ebx
  UFG::SimObjectGame *vfptr; // rcx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  __int16 m_Flags; // dx
  signed int v9; // ebp
  SSList *v10; // rax
  SSList *v11; // rsi
  SSInstance **v12; // rax
  int v13; // ecx
  UFG::qNode<UFG::qString,UFG::qString> *i; // rax
  AString *v15; // rax
  SSInstance *v16; // rax
  AStringRef *i_str_ref_p; // rdi
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v22; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v28; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> list; // [rsp+28h] [rbp-30h] BYREF
  AString v30; // [rsp+68h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v5 = 0;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::SimObjectGame *)i_obj_p[13].vfptr;
    if ( vfptr )
    {
      m_Flags = vfptr->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(vfptr, UFG::MeleeScriptSystemComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(vfptr, UFG::MeleeScriptSystemComponent::_TypeUID);
    }
    else
    {
      ComponentOfTypeHK = 0i64;
    }
    list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
    list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
    v9 = UFG::qString::Tokenize((UFG::qString *)&ComponentOfTypeHK[1].m_SafePointerList.mNode.mNext, &list, ";", 0i64);
    v10 = (SSList *)AMemory::c_malloc_func(0x18ui64, "SSList(count)");
    v11 = v10;
    v30.i_str_ref_p = (AStringRef *)v10;
    if ( v10 )
    {
      v10->i_items.i_count = 0;
      v10->i_items.i_array_p = 0i64;
      v10->i_items.i_size = 0;
      if ( v9 )
      {
        v10->i_items.i_size = v9;
        v12 = APArrayBase<SSInstance>::alloc_array(v9);
      }
      else
      {
        v10->i_items.i_size = 0;
        v12 = (SSInstance **)AMemory::c_malloc_func(0i64, "APArrayBase.buffer");
      }
      v11->i_items.i_array_p = v12;
    }
    else
    {
      v11 = 0i64;
    }
    if ( v9 > 0 )
    {
      do
      {
        v13 = v5;
        for ( i = list.mNode.mNext; v13 > 0; i = i->mNext )
        {
          if ( i == (UFG::qNode<UFG::qString,UFG::qString> *)&list )
            break;
          --v13;
        }
        AString::AString(&v30, (const char *)i[1].mNext, 0);
        v16 = SSString::as_instance(v15);
        SSList::append(v11, v16, 1);
        i_str_ref_p = v30.i_str_ref_p;
        if ( v30.i_str_ref_p->i_ref_count-- == 1 )
        {
          if ( i_str_ref_p->i_deallocate )
            AMemory::c_free_func(i_str_ref_p->i_cstr_p);
          pool = AStringRef::get_pool();
          i_block_p = pool->i_block_p;
          i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
          if ( (unsigned __int64)i_str_ref_p < i_objects_a
            || (v22 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
                p_i_exp_pool = &pool->i_pool,
                !v22) )
          {
            p_i_exp_pool = &pool->i_exp_pool;
          }
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
        }
        ++v5;
      }
      while ( v5 < v9 );
    }
    *ppResult = SSList::as_instance(v11);
    for ( j = (UFG::qString *)list.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
          j = (UFG::qString *)list.mNode.mNext )
    {
      mPrev = j->mPrev;
      mNext = j->mNext;
      mPrev->mNext = mNext;
      mNext->mPrev = mPrev;
      j->mPrev = j;
      j->mNext = j;
      UFG::qString::~qString(j);
      operator delete[](j);
    }
    v27 = list.mNode.mPrev;
    v28 = list.mNode.mNext;
    list.mNode.mPrev->mNext = list.mNode.mNext;
    v28->mPrev = v27;
  }
}

// File Line: 81
// RVA: 0x4FE900
void __fastcall UFG::TSMeleeScriptSystem::Mthd_get_spawn_group(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  UFG::SimComponent *v5; // r8
  UFG::SimObjectGame *vfptr; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  char *mNext; // rdi
  __int64 v10; // rbx
  unsigned int v11; // eax
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v17; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString str; // [rsp+58h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v5 = 0i64;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::SimObjectGame *)i_obj_p[13].vfptr;
    if ( vfptr )
    {
      m_Flags = vfptr->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(vfptr, UFG::MeleeScriptSystemComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(vfptr, UFG::MeleeScriptSystemComponent::_TypeUID);
      v5 = ComponentOfTypeHK;
    }
    mNext = (char *)v5[2].m_SafePointerList.mNode.mNext;
    v10 = -1i64;
    do
      ++v10;
    while ( mNext[v10] );
    v11 = AMemory::c_req_byte_size_func(v10 + 1);
    str.i_str_ref_p = AStringRef::pool_new(mNext, v10, v11, 1u, 0, 1);
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
        || (v17 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
            p_i_exp_pool = &pool->i_pool,
            !v17) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
    }
  }
}

// File Line: 95
// RVA: 0x4FEC70
void __fastcall UFG::TSMeleeScriptSystem::Mthd_get_start_trigger(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSObjectBase *i_obj_p; // rcx
  UFG::SimComponent *v5; // r8
  UFG::SimObjectGame *vfptr; // rcx
  __int16 m_Flags; // dx
  UFG::SimComponent *ComponentOfTypeHK; // rax
  char *mNext; // rdi
  __int64 v10; // rbx
  unsigned int v11; // eax
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v17; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString str; // [rsp+58h] [rbp+10h] BYREF

  if ( ppResult )
  {
    i_obj_p = pScope->i_scope_p.i_obj_p;
    v5 = 0i64;
    if ( !i_obj_p || pScope->i_scope_p.i_ptr_id != i_obj_p->i_ptr_id )
      i_obj_p = 0i64;
    vfptr = (UFG::SimObjectGame *)i_obj_p[13].vfptr;
    if ( vfptr )
    {
      m_Flags = vfptr->m_Flags;
      if ( (m_Flags & 0x4000) != 0 || m_Flags < 0 || (m_Flags & 0x2000) != 0 || (m_Flags & 0x1000) != 0 )
        ComponentOfTypeHK = UFG::SimObjectGame::GetComponentOfTypeHK(vfptr, UFG::MeleeScriptSystemComponent::_TypeUID);
      else
        ComponentOfTypeHK = UFG::SimObject::GetComponentOfType(vfptr, UFG::MeleeScriptSystemComponent::_TypeUID);
      v5 = ComponentOfTypeHK;
    }
    mNext = (char *)v5[2].m_BoundComponentHandles.mNode.mNext;
    v10 = -1i64;
    do
      ++v10;
    while ( mNext[v10] );
    v11 = AMemory::c_req_byte_size_func(v10 + 1);
    str.i_str_ref_p = AStringRef::pool_new(mNext, v10, v11, 1u, 0, 1);
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
        || (v17 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
            p_i_exp_pool = &pool->i_pool,
            !v17) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
    }
  }
}

