// File Line: 34
// RVA: 0x4D7E70
void UFG::TSUI_Helpbar::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Helpbar");
  SSClass::register_method_func(v0, "show", UFG::TSUI_Helpbar::MthdC_show, 1, 0);
  SSClass::register_method_func(v0, "show_for_one_frame", UFG::TSUI_Helpbar::MthdC_show_for_one_frame, 1, 0);
  SSClass::register_method_func(v0, "hide", UFG::TSUI_Helpbar::MthdC_hide, 1, 0);
}

// File Line: 44
// RVA: 0x4EFBF0
void __fastcall UFG::TSUI_Helpbar::MthdC_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  SSData **v4; // rcx
  SSInstance *v5; // rbx
  SSInstance *v6; // rdi
  SSInstance *v7; // rsi
  SSInstance *v8; // rbp
  unsigned __int64 v9; // rcx
  UFG::UI::eButtons button1; // er12
  UFG::UI::eButtons button0; // er13
  UFG::UI::eButtons button2; // er15
  UFG::UI::eButtons button3; // er14
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rcx
  const char *caption3; // rbx
  const char *caption2; // rdi
  const char *caption1; // rsi
  const char *caption0; // rbp
  UFG::UIHKHelpBarWidget *v21; // rax
  const char ***v22; // [rsp+80h] [rbp-48h]
  const char ***v23; // [rsp+88h] [rbp-40h]
  const char ***v24; // [rsp+E0h] [rbp+18h]
  const char ***v25; // [rsp+E8h] [rbp+20h]

  v2 = pScope;
  v3 = UFG::GameStatTracker::Instance();
  if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v3, ContextHelp) )
  {
    v4 = v2->i_data.i_array_p;
    v5 = (*v4)->i_data_p;
    v23 = (const char ***)&v4[1]->i_data_p->i_user_data;
    v6 = v4[2]->i_data_p;
    v22 = (const char ***)&v4[3]->i_data_p->i_user_data;
    v7 = v4[4]->i_data_p;
    v25 = (const char ***)&v4[5]->i_data_p->i_user_data;
    v8 = v4[6]->i_data_p;
    v24 = (const char ***)&v4[7]->i_data_p->i_user_data;
    if ( UFG::UIHKScreenGlobalOverlay::hasInstance() )
    {
      v9 = v5->i_user_data;
      button1 = 0;
      button0 = 0;
      button2 = 0;
      button3 = 0;
      if ( *(_DWORD *)(v9 + 8) )
        button0 = UFG::UI::GetButton(*(const char **)v9);
      v14 = v6->i_user_data;
      if ( *(_DWORD *)(v14 + 8) > 0u )
        button1 = UFG::UI::GetButton(*(const char **)v14);
      v15 = v7->i_user_data;
      if ( *(_DWORD *)(v15 + 8) > 0u )
        button2 = UFG::UI::GetButton(*(const char **)v15);
      v16 = v8->i_user_data;
      if ( *(_DWORD *)(v16 + 8) > 0u )
        button3 = UFG::UI::GetButton(*(const char **)v16);
      caption3 = **v24;
      caption2 = **v25;
      caption1 = **v22;
      caption0 = **v23;
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
        0,
        &customWorldMapCaption,
        0,
        &customWorldMapCaption);
    }
  }
}

// File Line: 81
// RVA: 0x4F0250
void __fastcall UFG::TSUI_Helpbar::MthdC_show_for_one_frame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  UFG::GameStatTracker *v3; // rax
  SSData **v4; // rcx
  SSInstance *v5; // rbx
  SSInstance *v6; // rdi
  SSInstance *v7; // rsi
  SSInstance *v8; // rbp
  unsigned __int64 v9; // rcx
  UFG::UI::eButtons v10; // er12
  UFG::UI::eButtons v11; // er13
  UFG::UI::eButtons button2; // er15
  UFG::UI::eButtons button3; // er14
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rcx
  const char *caption3; // rbx
  const char *caption2; // rdi
  const char *caption1; // rsi
  const char *v20; // rbp
  UFG::UIHKHelpBarWidget *v21; // rax
  const char ***v22; // [rsp+70h] [rbp-48h]
  const char ***v23; // [rsp+78h] [rbp-40h]
  const char ***v24; // [rsp+D0h] [rbp+18h]
  const char ***v25; // [rsp+D8h] [rbp+20h]

  v2 = pScope;
  v3 = UFG::GameStatTracker::Instance();
  if ( (unsigned __int8)UFG::GameStatTracker::GetStat(v3, ContextHelp) )
  {
    v4 = v2->i_data.i_array_p;
    v5 = (*v4)->i_data_p;
    v23 = (const char ***)&v4[1]->i_data_p->i_user_data;
    v6 = v4[2]->i_data_p;
    v22 = (const char ***)&v4[3]->i_data_p->i_user_data;
    v7 = v4[4]->i_data_p;
    v25 = (const char ***)&v4[5]->i_data_p->i_user_data;
    v8 = v4[6]->i_data_p;
    v24 = (const char ***)&v4[7]->i_data_p->i_user_data;
    if ( UFG::UIHKScreenGlobalOverlay::hasInstance() )
    {
      v9 = v5->i_user_data;
      v10 = 0;
      v11 = 0;
      button2 = 0;
      button3 = 0;
      if ( *(_DWORD *)(v9 + 8) )
        v11 = UFG::UI::GetButton(*(const char **)v9);
      v14 = v6->i_user_data;
      if ( *(_DWORD *)(v14 + 8) > 0u )
        v10 = UFG::UI::GetButton(*(const char **)v14);
      v15 = v7->i_user_data;
      if ( *(_DWORD *)(v15 + 8) > 0u )
        button2 = UFG::UI::GetButton(*(const char **)v15);
      v16 = v8->i_user_data;
      if ( *(_DWORD *)(v16 + 8) > 0u )
        button3 = UFG::UI::GetButton(*(const char **)v16);
      caption3 = **v24;
      caption2 = **v25;
      caption1 = **v22;
      v20 = **v23;
      v21 = UFG::UIHKHelpBarWidget::Get();
      UFG::UIHKHelpBarWidget::ShowOneFrame(
        v21,
        v11,
        v20,
        v10,
        caption1,
        button2,
        caption2,
        button3,
        caption3,
        0,
        &customWorldMapCaption,
        0,
        &customWorldMapCaption);
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

