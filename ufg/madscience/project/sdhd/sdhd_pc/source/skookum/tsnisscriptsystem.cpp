// File Line: 57
// RVA: 0x4FD7F0
void __fastcall UFG::TSNISScriptSystem::Mthd_get_nis_path(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  SSInvokedMethod *v3; // r9
  SSObjectBase *v4; // rcx
  UFG::SimComponent *v5; // r8
  UFG::SimObjectGame *v6; // rcx
  unsigned __int16 v7; // dx
  UFG::SimComponent *v8; // rax
  const char *v9; // rdi
  signed __int64 v10; // rbx
  unsigned int v11; // eax
  AStringRef *v12; // rbx
  bool v13; // zf
  AObjReusePool<AStringRef> *v14; // rax
  AObjBlock<AStringRef> *v15; // rcx
  unsigned __int64 v16; // rdx
  bool v17; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v18; // rcx
  AString str; // [rsp+58h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope;
    v4 = pScope->i_scope_p.i_obj_p;
    v5 = 0i64;
    if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v6 = (UFG::SimObjectGame *)v4[13].vfptr;
    if ( v6 )
    {
      v7 = v6->m_Flags;
      if ( (v7 >> 14) & 1 )
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NISScriptSystemComponent::_TypeUID);
      }
      else if ( (v7 & 0x8000u) == 0 )
      {
        if ( (v7 >> 13) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NISScriptSystemComponent::_TypeUID);
        }
        else if ( (v7 >> 12) & 1 )
        {
          v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NISScriptSystemComponent::_TypeUID);
        }
        else
        {
          v8 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::NISScriptSystemComponent::_TypeUID);
        }
      }
      else
      {
        v8 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NISScriptSystemComponent::_TypeUID);
      }
      v5 = v8;
    }
    v9 = (const char *)v5[1].m_pSimObject;
    v10 = -1i64;
    do
      ++v10;
    while ( v9[v10] );
    v11 = AMemory::c_req_byte_size_func(v10 + 1);
    str.i_str_ref_p = AStringRef::pool_new(v9, v10, v11, 1u, 0, 1);
    *v2 = SSString::as_instance(&str);
    v12 = str.i_str_ref_p;
    v13 = str.i_str_ref_p->i_ref_count == 1;
    --v12->i_ref_count;
    if ( v13 )
    {
      if ( v12->i_deallocate )
        AMemory::c_free_func(v12->i_cstr_p);
      v14 = AStringRef::get_pool();
      v15 = v14->i_block_p;
      v16 = (unsigned __int64)v15->i_objects_a;
      if ( (unsigned __int64)v12 < v16
        || (v17 = (unsigned __int64)v12 < v16 + 24i64 * v15->i_size, v18 = &v14->i_pool, !v17) )
      {
        v18 = &v14->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v18, v12);
    }
  }
}

// File Line: 71
// RVA: 0x4FB470
void __fastcall UFG::TSNISScriptSystem::Mthd_get_active_gameslices(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // r14
  SSInvokedMethod *v3; // r8
  SSObjectBase *v4; // rcx
  signed int v5; // ebx
  UFG::SimObjectGame *v6; // rcx
  UFG::SimComponent *v7; // rax
  unsigned __int16 v8; // dx
  signed int v9; // ebp
  SSList *v10; // rax
  SSList *v11; // rsi
  SSInstance **v12; // rax
  signed int v13; // ecx
  UFG::qNode<UFG::qString,UFG::qString> *i; // rax
  AString *v15; // rax
  SSInstance *v16; // rax
  AStringRef *v17; // rdi
  bool v18; // zf
  AObjReusePool<AStringRef> *v19; // rax
  AObjBlock<AStringRef> *v20; // rcx
  unsigned __int64 v21; // rdx
  bool v22; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v23; // rcx
  UFG::qString *j; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v25; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v26; // rax
  UFG::qNode<UFG::qString,UFG::qString> *v27; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v28; // rax
  UFG::qList<UFG::qString,UFG::qString,1,0> list; // [rsp+28h] [rbp-30h]
  AString v30; // [rsp+68h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = pScope;
    v4 = pScope->i_scope_p.i_obj_p;
    v5 = 0;
    if ( !v4 || v3->i_scope_p.i_ptr_id != v4->i_ptr_id )
      v4 = 0i64;
    v6 = (UFG::SimObjectGame *)v4[13].vfptr;
    if ( v6 )
    {
      v8 = v6->m_Flags;
      if ( (v8 >> 14) & 1 )
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NISScriptSystemComponent::_TypeUID);
      }
      else if ( (v8 & 0x8000u) == 0 )
      {
        if ( (v8 >> 13) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NISScriptSystemComponent::_TypeUID);
        }
        else if ( (v8 >> 12) & 1 )
        {
          v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NISScriptSystemComponent::_TypeUID);
        }
        else
        {
          v7 = UFG::SimObject::GetComponentOfType((UFG::SimObject *)&v6->vfptr, UFG::NISScriptSystemComponent::_TypeUID);
        }
      }
      else
      {
        v7 = UFG::SimObjectGame::GetComponentOfTypeHK(v6, UFG::NISScriptSystemComponent::_TypeUID);
      }
    }
    else
    {
      v7 = 0i64;
    }
    list.mNode.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
    list.mNode.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&list;
    v9 = UFG::qString::Tokenize((UFG::qString *)&v7[1].m_BoundComponentHandles.mNode.mNext, &list, ";", 0i64);
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
        v17 = v30.i_str_ref_p;
        v18 = v30.i_str_ref_p->i_ref_count == 1;
        --v17->i_ref_count;
        if ( v18 )
        {
          if ( v17->i_deallocate )
            AMemory::c_free_func(v17->i_cstr_p);
          v19 = AStringRef::get_pool();
          v20 = v19->i_block_p;
          v21 = (unsigned __int64)v20->i_objects_a;
          if ( (unsigned __int64)v17 < v21
            || (v22 = (unsigned __int64)v17 < v21 + 24i64 * v20->i_size, v23 = &v19->i_pool, !v22) )
          {
            v23 = &v19->i_exp_pool;
          }
          APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v23, v17);
        }
        ++v5;
      }
      while ( v5 < v9 );
    }
    *v2 = SSList::as_instance(v11);
    for ( j = (UFG::qString *)list.mNode.mNext;
          (UFG::qList<UFG::qString,UFG::qString,1,0> *)list.mNode.mNext != &list;
          j = (UFG::qString *)list.mNode.mNext )
    {
      v25 = j->mPrev;
      v26 = j->mNext;
      v25->mNext = v26;
      v26->mPrev = v25;
      j->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
      j->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&j->mPrev;
      UFG::qString::~qString(j);
      operator delete[](j);
    }
    v27 = list.mNode.mPrev;
    v28 = list.mNode.mNext;
    list.mNode.mPrev->mNext = list.mNode.mNext;
    v28->mPrev = v27;
  }
}

