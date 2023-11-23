// File Line: 33
// RVA: 0x4D7EF0
void UFG::TSUI_ListMenu::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("ListMenu");
  SSClass::register_method_func(v0, "private_push_screen", UFG::TSUI_ListMenu::MthdC_private_push_screen, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "add_item", UFG::TSUI_ListMenu::MthdC_add_item, 1, rebinda);
  SSClass::register_coroutine_func(
    v0,
    "_private_wait_until_screen_started",
    UFG::TSUI_ListMenu::Coro_private_wait_until_screen_started,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_private_wait_until_screen_finished",
    UFG::TSUI_ListMenu::Coro_private_wait_until_screen_finished,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "private_get_selected_value",
    UFG::TSUI_ListMenu::MthdC_private_get_selected_value,
    1,
    rebindb);
}

// File Line: 48
// RVA: 0x4EB5C0
void __fastcall UFG::TSUI_ListMenu::MthdC_private_push_screen(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( pScope )
    UFG::UIScreenManagerBase::queuePushScreen(UFG::UIScreenManager::s_instance, "ScriptableList", -1);
}

// File Line: 56
// RVA: 0x4E2FF0
void __fastcall UFG::TSUI_ListMenu::MthdC_add_item(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rax

  if ( pScope )
  {
    i_array_p = pScope->i_data.i_array_p;
    if ( (*i_array_p)->i_data_p != (SSInstance *)-32i64 )
      UFG::UIHKScreenScriptableList::AddItem(*(const char **)(*i_array_p)->i_data_p->i_user_data);
  }
}

// File Line: 69
// RVA: 0x4DCCB0
bool __fastcall UFG::TSUI_ListMenu::Coro_private_wait_until_screen_started(SSInvokedCoroutine *pScope)
{
  return UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "ScriptableList") != 0i64;
}

// File Line: 77
// RVA: 0x4DCC80
bool __fastcall UFG::TSUI_ListMenu::Coro_private_wait_until_screen_finished(SSInvokedCoroutine *pScope)
{
  return UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "ScriptableList") == 0i64;
}

// File Line: 85
// RVA: 0x4EB4E0
void __fastcall UFG::TSUI_ListMenu::MthdC_private_get_selected_value(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  char *mData; // rdi
  __int64 v4; // rbx
  unsigned int v5; // eax
  AStringRef *i_str_ref_p; // rbx
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v11; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  AString str; // [rsp+58h] [rbp+10h] BYREF

  if ( ppResult )
  {
    mData = UFG::UIHKScreenScriptableList::mSelectedValue.mData;
    v4 = -1i64;
    do
      ++v4;
    while ( UFG::UIHKScreenScriptableList::mSelectedValue.mData[v4] );
    v5 = AMemory::c_req_byte_size_func(v4 + 1);
    str.i_str_ref_p = AStringRef::pool_new(mData, v4, v5, 1u, 0, 1);
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
        || (v11 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
            p_i_exp_pool = &pool->i_pool,
            !v11) )
      {
        p_i_exp_pool = &pool->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
    }
  }
}

