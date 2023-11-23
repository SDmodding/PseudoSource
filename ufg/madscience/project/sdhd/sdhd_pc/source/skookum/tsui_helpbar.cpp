// File Line: 34
// RVA: 0x4D7E70
void UFG::TSUI_Helpbar::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("Helpbar");
  SSClass::register_method_func(v0, "show", UFG::TSUI_Helpbar::MthdC_show, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "show_for_one_frame", UFG::TSUI_Helpbar::MthdC_show_for_one_frame, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "hide", UFG::TSUI_Helpbar::MthdC_hide, 1, rebindb);
}

// File Line: 44
// RVA: 0x4EFBF0
void __fastcall UFG::TSUI_Helpbar::MthdC_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStatTracker *v3; // rax
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rbx
  SSInstance *v6; // rdi
  SSInstance *v7; // rsi
  SSInstance *v8; // rbp
  unsigned __int64 i_user_data; // rcx
  UFG::UI::eButtons button1; // r12d
  UFG::UI::eButtons button0; // r13d
  UFG::UI::eButtons button2; // r15d
  UFG::UI::eButtons button3; // r14d
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rcx
  const char *caption3; // rbx
  const char *caption2; // rdi
  const char *caption1; // rsi
  const char *caption0; // rbp
  UFG::UIHKHelpBarWidget *v21; // rax
  const char ***v22; // [rsp+80h] [rbp-48h]
  const char ***p_i_user_data; // [rsp+88h] [rbp-40h]
  const char ***v24; // [rsp+E0h] [rbp+18h]
  const char ***v25; // [rsp+E8h] [rbp+20h]

  v3 = UFG::GameStatTracker::Instance();
  if ( UFG::GameStatTracker::GetStat(v3, ContextHelp) )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    p_i_user_data = (const char ***)&i_array_p[1]->i_data_p->i_user_data;
    v6 = i_array_p[2]->i_data_p;
    v22 = (const char ***)&i_array_p[3]->i_data_p->i_user_data;
    v7 = i_array_p[4]->i_data_p;
    v25 = (const char ***)&i_array_p[5]->i_data_p->i_user_data;
    v8 = i_array_p[6]->i_data_p;
    v24 = (const char ***)&i_array_p[7]->i_data_p->i_user_data;
    if ( UFG::UIHKScreenGlobalOverlay::hasInstance() )
    {
      i_user_data = i_data_p->i_user_data;
      button1 = INVALID_BUTTON;
      button0 = INVALID_BUTTON;
      button2 = INVALID_BUTTON;
      button3 = INVALID_BUTTON;
      if ( *(_DWORD *)(i_user_data + 8) )
        button0 = UFG::UI::GetButton(*(const char **)i_user_data);
      v14 = v6->i_user_data;
      if ( *(_DWORD *)(v14 + 8) )
        button1 = UFG::UI::GetButton(*(const char **)v14);
      v15 = v7->i_user_data;
      if ( *(_DWORD *)(v15 + 8) )
        button2 = UFG::UI::GetButton(*(const char **)v15);
      v16 = v8->i_user_data;
      if ( *(_DWORD *)(v16 + 8) )
        button3 = UFG::UI::GetButton(*(const char **)v16);
      caption3 = **v24;
      caption2 = **v25;
      caption1 = **v22;
      caption0 = **p_i_user_data;
      v21 = UFG::UIHKHelpBarWidget::Get();
      UFG::UIHKHelpBarWidget::Show(
        v21,
        UI_HASH_TSHUD_15,
        PRIORITY_THREE,
        ALIGN_RIGHT,
        button0,
        caption0,
        button1,
        caption1,
        button2,
        caption2,
        button3,
        caption3,
        INVALID_BUTTON,
        &customCaption,
        INVALID_BUTTON,
        &customCaption);
    }
  }
}

// File Line: 81
// RVA: 0x4F0250
void __fastcall UFG::TSUI_Helpbar::MthdC_show_for_one_frame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameStatTracker *v3; // rax
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rbx
  SSInstance *v6; // rdi
  SSInstance *v7; // rsi
  SSInstance *v8; // rbp
  unsigned __int64 i_user_data; // rcx
  UFG::UI::eButtons v10; // r12d
  UFG::UI::eButtons Button; // r13d
  UFG::UI::eButtons button2; // r15d
  UFG::UI::eButtons button3; // r14d
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rcx
  const char *caption3; // rbx
  const char *caption2; // rdi
  const char *caption1; // rsi
  const char *v20; // rbp
  UFG::UIHKHelpBarWidget *v21; // rax
  const char ***v22; // [rsp+70h] [rbp-48h]
  const char ***p_i_user_data; // [rsp+78h] [rbp-40h]
  const char ***v24; // [rsp+D0h] [rbp+18h]
  const char ***v25; // [rsp+D8h] [rbp+20h]

  v3 = UFG::GameStatTracker::Instance();
  if ( UFG::GameStatTracker::GetStat(v3, ContextHelp) )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    p_i_user_data = (const char ***)&i_array_p[1]->i_data_p->i_user_data;
    v6 = i_array_p[2]->i_data_p;
    v22 = (const char ***)&i_array_p[3]->i_data_p->i_user_data;
    v7 = i_array_p[4]->i_data_p;
    v25 = (const char ***)&i_array_p[5]->i_data_p->i_user_data;
    v8 = i_array_p[6]->i_data_p;
    v24 = (const char ***)&i_array_p[7]->i_data_p->i_user_data;
    if ( UFG::UIHKScreenGlobalOverlay::hasInstance() )
    {
      i_user_data = i_data_p->i_user_data;
      v10 = INVALID_BUTTON;
      Button = INVALID_BUTTON;
      button2 = INVALID_BUTTON;
      button3 = INVALID_BUTTON;
      if ( *(_DWORD *)(i_user_data + 8) )
        Button = UFG::UI::GetButton(*(const char **)i_user_data);
      v14 = v6->i_user_data;
      if ( *(_DWORD *)(v14 + 8) )
        v10 = UFG::UI::GetButton(*(const char **)v14);
      v15 = v7->i_user_data;
      if ( *(_DWORD *)(v15 + 8) )
        button2 = UFG::UI::GetButton(*(const char **)v15);
      v16 = v8->i_user_data;
      if ( *(_DWORD *)(v16 + 8) )
        button3 = UFG::UI::GetButton(*(const char **)v16);
      caption3 = **v24;
      caption2 = **v25;
      caption1 = **v22;
      v20 = **p_i_user_data;
      v21 = UFG::UIHKHelpBarWidget::Get();
      UFG::UIHKHelpBarWidget::ShowOneFrame(
        v21,
        Button,
        v20,
        v10,
        caption1,
        button2,
        caption2,
        button3,
        caption3,
        INVALID_BUTTON,
        &customCaption,
        INVALID_BUTTON,
        &customCaption);
    }
  }
}

// File Line: 115
// RVA: 0x4E8E70
void __fastcall UFG::TSUI_Helpbar::MthdC_hide(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKHelpBarWidget *v2; // rax

  if ( UFG::UIHKScreenGlobalOverlay::hasInstance() )
  {
    v2 = UFG::UIHKHelpBarWidget::Get();
    UFG::UIHKHelpBarWidget::Hide(v2, UI_HASH_TSHUD_15);
  }
}

