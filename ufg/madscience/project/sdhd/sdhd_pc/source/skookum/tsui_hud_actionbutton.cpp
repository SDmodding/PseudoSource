// File Line: 34
// RVA: 0x4D7960
void UFG::TSUI_HUD_ActionButton::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("ActionButton");
  SSClass::register_method_func(v0, "show", UFG::TSUI_HUD_ActionButton::MthdC_show, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "hide", UFG::TSUI_HUD_ActionButton::MthdC_hide, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "show_for_one_frame",
    UFG::TSUI_HUD_ActionButton::MthdC_show_for_one_frame,
    1,
    rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "refresh_for_one_frame",
    UFG::TSUI_HUD_ActionButton::MthdC_refresh_for_one_frame,
    1,
    rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(
    v0,
    "set_weapon_struggle_state",
    UFG::TSUI_HUD_ActionButton::MthdC_set_weapon_struggle_state,
    1,
    rebindd);
}

// File Line: 46
// RVA: 0x4EF840
void __fastcall UFG::TSUI_HUD_ActionButton::MthdC_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  UFG::UI::eButtons v3; // ebx
  SSInstance *i_data_p; // rsi
  SSInstance *v5; // r14
  SSInstance *v6; // rcx
  const char *v7; // rdi
  char v8; // al

  i_array_p = pScope->i_data.i_array_p;
  v3 = BUTTON2_BUTTON;
  i_data_p = (*i_array_p)->i_data_p;
  v5 = i_array_p[2]->i_data_p;
  v6 = i_array_p[1]->i_data_p;
  v7 = *(const char **)v6->i_user_data;
  v8 = *v7;
  if ( *v7 != 121 )
  {
    switch ( v8 )
    {
      case b:
        v3 = BACK_BUTTON;
        break;
      case x:
        v3 = BUTTON1_BUTTON;
        break;
      case a:
        v3 = ACCEPT_BUTTON;
        break;
      case l:
        v3 = L_STICK_BUTTON;
        if ( (unsigned int)UFG::qStringCompare(*(const char **)v6->i_user_data, "l_stick_lr", -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare(v7, "l_stick_ud", -1) )
            v3 = L_STICK_UD_BUTTON;
        }
        else
        {
          v3 = L_STICK_LR_BUTTON;
        }
        break;
      case r:
        v3 = R_STICK_BUTTON;
        if ( (unsigned int)UFG::qStringCompare(*(const char **)v6->i_user_data, "r_stick_lr", -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare(v7, "r_stick_ud", -1) )
            v3 = R_STICK_UD_BUTTON;
        }
        else
        {
          v3 = R_STICK_LR_BUTTON;
        }
        break;
    }
  }
  UFG::UIHKActionButtonWidget::Show(
    UFG::UIHKScreenHud::ActionButton,
    *(const char **)i_data_p->i_user_data,
    v3,
    *(const char **)v5->i_user_data);
}

// File Line: 91
// RVA: 0x4EFF80
void __fastcall UFG::TSUI_HUD_ActionButton::MthdC_show_for_one_frame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  UFG::UI::eButtons v3; // ebx
  SSInstance *i_data_p; // rsi
  SSInstance *v5; // r14
  SSInstance *v6; // rcx
  const char *v7; // rdi
  char v8; // al

  i_array_p = pScope->i_data.i_array_p;
  v3 = BUTTON2_BUTTON;
  i_data_p = (*i_array_p)->i_data_p;
  v5 = i_array_p[2]->i_data_p;
  v6 = i_array_p[1]->i_data_p;
  v7 = *(const char **)v6->i_user_data;
  v8 = *v7;
  if ( *v7 != 121 )
  {
    switch ( v8 )
    {
      case b:
        v3 = BACK_BUTTON;
        break;
      case x:
        v3 = BUTTON1_BUTTON;
        break;
      case a:
        v3 = ACCEPT_BUTTON;
        break;
      case l:
        v3 = L_STICK_BUTTON;
        if ( (unsigned int)UFG::qStringCompare(*(const char **)v6->i_user_data, "l_stick_lr", -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare(v7, "l_stick_ud", -1) )
            v3 = L_STICK_UD_BUTTON;
        }
        else
        {
          v3 = L_STICK_LR_BUTTON;
        }
        break;
      case r:
        v3 = R_STICK_BUTTON;
        if ( (unsigned int)UFG::qStringCompare(*(const char **)v6->i_user_data, "r_stick_lr", -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare(v7, "r_stick_ud", -1) )
            v3 = R_STICK_UD_BUTTON;
        }
        else
        {
          v3 = R_STICK_LR_BUTTON;
        }
        break;
    }
  }
  UFG::UIHKActionButtonWidget::ShowOneFrame(
    UFG::UIHKScreenHud::ActionButton,
    *(const char **)i_data_p->i_user_data,
    v3,
    *(const char **)v5->i_user_data);
}

// File Line: 136
// RVA: 0x4EBC10
void __fastcall UFG::TSUI_HUD_ActionButton::MthdC_refresh_for_one_frame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKActionButtonWidget::RefreshOneFrame(UFG::UIHKScreenHud::ActionButton);
}

// File Line: 142
// RVA: 0x4E8E00
void __fastcall UFG::TSUI_HUD_ActionButton::MthdC_hide(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKActionButtonWidget::Hide(UFG::UIHKScreenHud::ActionButton);
}

// File Line: 148
// RVA: 0x4EF500
void __fastcall UFG::TSUI_HUD_ActionButton::MthdC_set_weapon_struggle_state(
        SSInvokedMethod *pScope,
        SSInstance **ppResult)
{
  SSInstance *i_data_p; // rsi
  unsigned int v3; // eax
  char is_equal; // di
  AStringRef *i_str_ref_p; // rbx
  bool v6; // zf
  AObjReusePool<AStringRef> *pool; // rax
  AObjBlock<AStringRef> *i_block_p; // rcx
  unsigned __int64 i_objects_a; // rdx
  bool v10; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_exp_pool; // rcx
  unsigned int v12; // eax
  char v13; // di
  AStringRef *v14; // rbx
  AObjReusePool<AStringRef> *v15; // rax
  AObjBlock<AStringRef> *v16; // rcx
  unsigned __int64 v17; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *p_i_pool; // rcx
  AString str; // [rsp+50h] [rbp+8h] BYREF

  i_data_p = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = AMemory::c_req_byte_size_func(9u);
  str.i_str_ref_p = AStringRef::pool_new("struggle", 8u, v3, 1u, 0, 1);
  is_equal = AString::is_equal((AString *)&i_data_p->i_user_data, &str);
  i_str_ref_p = str.i_str_ref_p;
  v6 = str.i_str_ref_p->i_ref_count-- == 1;
  if ( v6 )
  {
    if ( i_str_ref_p->i_deallocate )
      AMemory::c_free_func(i_str_ref_p->i_cstr_p);
    pool = AStringRef::get_pool();
    i_block_p = pool->i_block_p;
    i_objects_a = (unsigned __int64)i_block_p->i_objects_a;
    if ( (unsigned __int64)i_str_ref_p < i_objects_a
      || (v10 = (unsigned __int64)i_str_ref_p < i_objects_a + 24i64 * i_block_p->i_size,
          p_i_exp_pool = &pool->i_pool,
          !v10) )
    {
      p_i_exp_pool = &pool->i_exp_pool;
    }
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_exp_pool, i_str_ref_p);
  }
  if ( is_equal )
  {
    UFG::UIHKActionButtonWidget::Show(UFG::UIHKScreenHud::ActionButton, "$HUD_STRUGGLE", BUTTON2_BUTTON, "mash");
  }
  else
  {
    v12 = AMemory::c_req_byte_size_func(5u);
    str.i_str_ref_p = AStringRef::pool_new("hide", 4u, v12, 1u, 0, 1);
    v13 = AString::is_equal((AString *)&i_data_p->i_user_data, &str);
    v14 = str.i_str_ref_p;
    v6 = str.i_str_ref_p->i_ref_count-- == 1;
    if ( v6 )
    {
      if ( v14->i_deallocate )
        AMemory::c_free_func(v14->i_cstr_p);
      v15 = AStringRef::get_pool();
      v16 = v15->i_block_p;
      v17 = (unsigned __int64)v16->i_objects_a;
      if ( (unsigned __int64)v14 < v17
        || (v10 = (unsigned __int64)v14 < v17 + 24i64 * v16->i_size, p_i_pool = &v15->i_pool, !v10) )
      {
        p_i_pool = &v15->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(p_i_pool, v14);
    }
    if ( v13 )
      UFG::UIHKActionButtonWidget::Hide(UFG::UIHKScreenHud::ActionButton);
  }
}

