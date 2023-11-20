// File Line: 34
// RVA: 0x4D7960
void UFG::TSUI_HUD_ActionButton::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("ActionButton");
  SSClass::register_method_func(v0, "show", UFG::TSUI_HUD_ActionButton::MthdC_show, 1, 0);
  SSClass::register_method_func(v0, "hide", UFG::TSUI_HUD_ActionButton::MthdC_hide, 1, 0);
  SSClass::register_method_func(v0, "show_for_one_frame", UFG::TSUI_HUD_ActionButton::MthdC_show_for_one_frame, 1, 0);
  SSClass::register_method_func(
    v0,
    "refresh_for_one_frame",
    UFG::TSUI_HUD_ActionButton::MthdC_refresh_for_one_frame,
    1,
    0);
  SSClass::register_method_func(
    v0,
    "set_weapon_struggle_state",
    UFG::TSUI_HUD_ActionButton::MthdC_set_weapon_struggle_state,
    1,
    0);
}

// File Line: 46
// RVA: 0x4EF840
void __fastcall UFG::TSUI_HUD_ActionButton::MthdC_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  UFG::UI::eButtons v3; // ebx
  SSInstance *v4; // rsi
  SSInstance *v5; // r14
  SSInstance *v6; // rcx
  const char *v7; // rdi
  char v8; // al

  v2 = pScope->i_data.i_array_p;
  v3 = 4;
  v4 = (*v2)->i_data_p;
  v5 = v2[2]->i_data_p;
  v6 = v2[1]->i_data_p;
  v7 = *(const char **)v6->i_user_data;
  v8 = *v7;
  if ( *v7 != 121 )
  {
    switch ( v8 )
    {
      case 98:
        v3 = 2;
        break;
      case 120:
        v3 = 3;
        break;
      case 97:
        v3 = 1;
        break;
      case 108:
        v3 = 21;
        if ( (unsigned int)UFG::qStringCompare(*(const char **)v6->i_user_data, "l_stick_lr", -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare(v7, "l_stick_ud", -1) )
            v3 = 24;
        }
        else
        {
          v3 = 23;
        }
        break;
      case 114:
        v3 = 22;
        if ( (unsigned int)UFG::qStringCompare(*(const char **)v6->i_user_data, "r_stick_lr", -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare(v7, "r_stick_ud", -1) )
            v3 = 26;
        }
        else
        {
          v3 = 25;
        }
        break;
    }
  }
  UFG::UIHKActionButtonWidget::Show(
    UFG::UIHKScreenHud::ActionButton,
    *(const char **)v4->i_user_data,
    v3,
    *(const char **)v5->i_user_data);
}

// File Line: 91
// RVA: 0x4EFF80
void __fastcall UFG::TSUI_HUD_ActionButton::MthdC_show_for_one_frame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  UFG::UI::eButtons v3; // ebx
  SSInstance *v4; // rsi
  SSInstance *v5; // r14
  SSInstance *v6; // rcx
  const char *v7; // rdi
  char v8; // al

  v2 = pScope->i_data.i_array_p;
  v3 = 4;
  v4 = (*v2)->i_data_p;
  v5 = v2[2]->i_data_p;
  v6 = v2[1]->i_data_p;
  v7 = *(const char **)v6->i_user_data;
  v8 = *v7;
  if ( *v7 != 121 )
  {
    switch ( v8 )
    {
      case 98:
        v3 = 2;
        break;
      case 120:
        v3 = 3;
        break;
      case 97:
        v3 = 1;
        break;
      case 108:
        v3 = 21;
        if ( (unsigned int)UFG::qStringCompare(*(const char **)v6->i_user_data, "l_stick_lr", -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare(v7, "l_stick_ud", -1) )
            v3 = 24;
        }
        else
        {
          v3 = 23;
        }
        break;
      case 114:
        v3 = 22;
        if ( (unsigned int)UFG::qStringCompare(*(const char **)v6->i_user_data, "r_stick_lr", -1) )
        {
          if ( !(unsigned int)UFG::qStringCompare(v7, "r_stick_ud", -1) )
            v3 = 26;
        }
        else
        {
          v3 = 25;
        }
        break;
    }
  }
  UFG::UIHKActionButtonWidget::ShowOneFrame(
    UFG::UIHKScreenHud::ActionButton,
    *(const char **)v4->i_user_data,
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
void __fastcall UFG::TSUI_HUD_ActionButton::MthdC_set_weapon_struggle_state(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance *v2; // rsi
  unsigned int v3; // eax
  char v4; // di
  AStringRef *v5; // rbx
  bool v6; // zf
  AObjReusePool<AStringRef> *v7; // rax
  AObjBlock<AStringRef> *v8; // rcx
  unsigned __int64 v9; // rdx
  bool v10; // cf
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v11; // rcx
  unsigned int v12; // eax
  char v13; // di
  AStringRef *v14; // rbx
  AObjReusePool<AStringRef> *v15; // rax
  AObjBlock<AStringRef> *v16; // rcx
  unsigned __int64 v17; // rdx
  APArray<AStringRef,AStringRef,ACompareAddress<AStringRef> > *v18; // rcx
  AString str; // [rsp+50h] [rbp+8h]

  v2 = (*pScope->i_data.i_array_p)->i_data_p;
  v3 = AMemory::c_req_byte_size_func(9u);
  str.i_str_ref_p = AStringRef::pool_new("struggle", 8u, v3, 1u, 0, 1);
  v4 = AString::is_equal((AString *)&v2->i_user_data, &str);
  v5 = str.i_str_ref_p;
  v6 = str.i_str_ref_p->i_ref_count == 1;
  --v5->i_ref_count;
  if ( v6 )
  {
    if ( v5->i_deallocate )
      AMemory::c_free_func(v5->i_cstr_p);
    v7 = AStringRef::get_pool();
    v8 = v7->i_block_p;
    v9 = (unsigned __int64)v8->i_objects_a;
    if ( (unsigned __int64)v5 < v9 || (v10 = (unsigned __int64)v5 < v9 + 24i64 * v8->i_size, v11 = &v7->i_pool, !v10) )
      v11 = &v7->i_exp_pool;
    APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v11, v5);
  }
  if ( v4 )
  {
    UFG::UIHKActionButtonWidget::Show(UFG::UIHKScreenHud::ActionButton, "$HUD_STRUGGLE", BUTTON2_BUTTON, "mash");
  }
  else
  {
    v12 = AMemory::c_req_byte_size_func(5u);
    str.i_str_ref_p = AStringRef::pool_new("hide", 4u, v12, 1u, 0, 1);
    v13 = AString::is_equal((AString *)&v2->i_user_data, &str);
    v14 = str.i_str_ref_p;
    v6 = str.i_str_ref_p->i_ref_count == 1;
    --v14->i_ref_count;
    if ( v6 )
    {
      if ( v14->i_deallocate )
        AMemory::c_free_func(v14->i_cstr_p);
      v15 = AStringRef::get_pool();
      v16 = v15->i_block_p;
      v17 = (unsigned __int64)v16->i_objects_a;
      if ( (unsigned __int64)v14 < v17
        || (v10 = (unsigned __int64)v14 < v17 + 24i64 * v16->i_size, v18 = &v15->i_pool, !v10) )
      {
        v18 = &v15->i_exp_pool;
      }
      APArray<AStringRef,AStringRef,ACompareAddress<AStringRef>>::append(v18, v14);
    }
    if ( v13 )
      UFG::UIHKActionButtonWidget::Hide(UFG::UIHKScreenHud::ActionButton);
  }
}

