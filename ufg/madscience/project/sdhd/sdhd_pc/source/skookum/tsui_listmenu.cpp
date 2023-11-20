// File Line: 33
// RVA: 0x4D7EF0
void UFG::TSUI_ListMenu::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("ListMenu");
  SSClass::register_method_func(v0, "private_push_screen", UFG::TSUI_ListMenu::MthdC_private_push_screen, 1, 0);
  SSClass::register_method_func(v0, "add_item", UFG::TSUI_ListMenu::MthdC_add_item, 1, 0);
  SSClass::register_coroutine_func(
    v0,
    "_private_wait_until_screen_started",
    UFG::TSUI_ListMenu::Coro_private_wait_until_screen_started,
    0);
  SSClass::register_coroutine_func(
    v0,
    "_private_wait_until_screen_finished",
    UFG::TSUI_ListMenu::Coro_private_wait_until_screen_finished,
    0);
  SSClass::register_method_func(
    v0,
    "private_get_selected_value",
    UFG::TSUI_ListMenu::MthdC_private_get_selected_value,
    1,
    0);
}

// File Line: 48
// RVA: 0x4EB5C0
void __fastcall UFG::TSUI_ListMenu::MthdC_private_push_screen(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( pScope )
    UFG::UIScreenManagerBase::queuePushScreen(
      (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
      "ScriptableList",
      -1);
}

// File Line: 56
// RVA: 0x4E2FF0
void __fastcall UFG::TSUI_ListMenu::MthdC_add_item(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rax

  if ( pScope )
  {
    v2 = pScope->i_data.i_array_p;
    if ( (*v2)->i_data_p != (SSInstance *)-32i64 )
      UFG::UIHKScreenScriptableList::AddItem(*(const char **)(*v2)->i_data_p->i_user_data);
  }
}

// File Line: 69
// RVA: 0x4DCCB0
bool __fastcall UFG::TSUI_ListMenu::Coro_private_wait_until_screen_started(SSInvokedCoroutine *pScope)
{
  return UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "ScriptableList") != 0i64;
}

// File Line: 77
// RVA: 0x4DCC80
bool __fastcall UFG::TSUI_ListMenu::Coro_private_wait_until_screen_finished(SSInvokedCoroutine *pScope)
{
  return UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "ScriptableList") == 0i64;
}

// File Line: 85
// RVA: 0x4EB4E0
void __fastcall UFG::TSUI_ListMenu::MthdC_private_get_selected_value(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rsi
  char *v3; // rdi
  signed __int64 v4; // rbx
  unsigned int v5; // eax
  AStringRef *v6; // rbx
  bool v7; // zf
  AObjReusePool<AStringRef> *v8; // rax
  AObjBlock<AStringRef> *v9; // rcx
  unsigned __int64 v10; // rdx
  bool v11; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v12; // rcx
  AString str; // [rsp+58h] [rbp+10h]

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::UIHKScreenScriptableList::mSelectedValue.mData;
    v4 = -1i64;
    do
      ++v4;
    while ( UFG::UIHKScreenScriptableList::mSelectedValue.mData[v4] );
    v5 = AMemory::c_req_byte_size_func(v4 + 1);
    str.i_str_ref_p = AStringRef::pool_new(v3, v4, v5, 1u, 0, 1);
    *v2 = SSString::as_instance(&str);
    v6 = str.i_str_ref_p;
    v7 = str.i_str_ref_p->i_ref_count == 1;
    --v6->i_ref_count;
    if ( v7 )
    {
      if ( v6->i_deallocate )
        AMemory::c_free_func(v6->i_cstr_p);
      v8 = AStringRef::get_pool();
      v9 = v8->i_block_p;
      v10 = (unsigned __int64)v9->i_objects_a;
      if ( (unsigned __int64)v6 < v10
        || (v11 = (unsigned __int64)v6 < v10 + 24i64 * v9->i_size, v12 = &v8->i_pool, !v11) )
      {
        v12 = &v8->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v12, v6);
    }
  }
}

