// File Line: 34
// RVA: 0x4D7750
void UFG::TSUI_FightTutorial::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("FightTutorial");
  SSClass::register_method_func(v0, "is_active", UFG::TSUI_FightTutorial::MthdC_is_active, 1, 0);
  SSClass::register_method_func(v0, "start", UFG::TSUI_FightTutorial::MthdC_start, 1, 0);
  SSClass::register_method_func(v0, "end", UFG::TSUI_FightTutorial::MthdC_end, 1, 0);
  SSClass::register_method_func(v0, "set_sequence", UFG::TSUI_FightTutorial::MthdC_set_sequence, 1, 0);
  SSClass::register_method_func(v0, "reset", UFG::TSUI_FightTutorial::MthdC_reset, 1, 0);
  SSClass::register_method_func(v0, "hit_success", UFG::TSUI_FightTutorial::MthdC_hit_success, 1, 0);
  SSClass::register_method_func(v0, "hit_failed", UFG::TSUI_FightTutorial::MthdC_hit_failed, 1, 0);
  SSClass::register_method_func(v0, "is_success", UFG::TSUI_FightTutorial::MthdC_is_success, 1, 0);
  SSClass::register_method_func(v0, "button_pressed", UFG::TSUI_FightTutorial::MthdC_button_pressed, 1, 0);
  SSClass::register_method_func(v0, "button_held", UFG::TSUI_FightTutorial::MthdC_button_held, 1, 0);
  SSClass::register_method_func(v0, "set_visible", UFG::TSUI_FightTutorial::MthdC_set_visible, 1, 0);
}

// File Line: 54
// RVA: 0x4E9270
void __fastcall UFG::TSUI_FightTutorial::MthdC_is_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx

  v2 = ppResult;
  if ( ppResult
    && UFG::UIScreenManagerBase::getOverlay(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "FightingTutorial") )
  {
    *v2 = (SSInstance *)SSBoolean::pool_new(1);
  }
  else
  {
    *v2 = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 65
// RVA: 0x4F22C0
void __fastcall UFG::TSUI_FightTutorial::MthdC_start(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreenTextureManager *v2; // rax

  if ( !UFG::UIScreenManagerBase::getOverlay(
          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
          "FightingTutorial") )
  {
    v2 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v2, "FightingTutorial", 0i64);
  }
}

// File Line: 75
// RVA: 0x4E54E0
void __fastcall UFG::TSUI_FightTutorial::MthdC_end(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenFightTutorial::Pop();
}

// File Line: 81
// RVA: 0x4EEA70
void __fastcall UFG::TSUI_FightTutorial::MthdC_set_sequence(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  SSData **v3; // rcx
  UFG::UI::eButtons v4; // edi
  SSInstance *v5; // rbp
  UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator5; // er13
  SSInstance *v7; // rbx
  SSInstance *v8; // r12
  SSInstance *v9; // rsi
  SSInstance *v10; // r14
  SSInstance *v11; // r15
  SSData *v12; // rax
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // rcx
  unsigned __int64 v18; // rcx
  unsigned __int64 v19; // rcx
  UFG::UIHKScreenFightTutorial::eButtonAction buttonAction4; // er12
  UFG::UIHKScreenFightTutorial::eButtonAction buttonAction5; // er15
  UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator2; // er14
  UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator3; // ebp
  UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator4; // esi
  const char *v25; // rbx
  UFG::UIHKScreenFightTutorial *v26; // rax
  UFG::UIHKScreenFightTutorial::eButtonAction buttonAction2; // [rsp+80h] [rbp-A8h]
  UFG::UIHKScreenFightTutorial::eButtonAction buttonAction3; // [rsp+84h] [rbp-A4h]
  UFG::UI::eButtons button2; // [rsp+88h] [rbp-A0h]
  UFG::UI::eButtons button3; // [rsp+8Ch] [rbp-9Ch]
  UFG::UIHKScreenFightTutorial::eButtonAction buttonAction1; // [rsp+90h] [rbp-98h]
  const char ***v32; // [rsp+A8h] [rbp-80h]
  const char ***v33; // [rsp+B0h] [rbp-78h]
  const char ***v34; // [rsp+B8h] [rbp-70h]
  const char ***v35; // [rsp+C0h] [rbp-68h]
  const char ***v36; // [rsp+C8h] [rbp-60h]
  const char ***v37; // [rsp+D0h] [rbp-58h]
  const char ***v38; // [rsp+D8h] [rbp-50h]
  const char ***v39; // [rsp+E0h] [rbp-48h]
  UFG::UI::eButtons button5; // [rsp+140h] [rbp+18h]
  UFG::UI::eButtons button4; // [rsp+148h] [rbp+20h]

  v2 = pScope;
  if ( UFG::UIScreenManagerBase::getOverlay(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "FightingTutorial") )
  {
    v3 = v2->i_data.i_array_p;
    v4 = 0;
    v39 = (const char ***)&(*v3)->i_data_p->i_user_data;
    button2 = 0;
    button3 = 0;
    v5 = v3[2]->i_data_p;
    button4 = 0;
    button5 = 0;
    buttonAction1 = 0;
    buttonAction2 = 0;
    buttonAction3 = 0;
    v36 = (const char ***)&v3[3]->i_data_p->i_user_data;
    buttonSeperator5 = 0;
    v7 = v3[4]->i_data_p;
    v8 = v3[5]->i_data_p;
    v33 = (const char ***)&v3[6]->i_data_p->i_user_data;
    v9 = v3[7]->i_data_p;
    v34 = (const char ***)&v3[8]->i_data_p->i_user_data;
    v35 = (const char ***)&v3[9]->i_data_p->i_user_data;
    v10 = v3[10]->i_data_p;
    v32 = (const char ***)&v3[11]->i_data_p->i_user_data;
    v37 = (const char ***)&v3[12]->i_data_p->i_user_data;
    v11 = v3[13]->i_data_p;
    v12 = v3[14];
    v13 = v3[1]->i_data_p->i_user_data;
    v38 = (const char ***)&v12->i_data_p->i_user_data;
    if ( *(_DWORD *)(v13 + 8) )
      v4 = UFG::UI::GetButton(*(const char **)v13);
    v14 = v7->i_user_data;
    if ( *(_DWORD *)(v14 + 8) > 0u )
      button2 = UFG::UI::GetButton(*(const char **)v14);
    v15 = v9->i_user_data;
    if ( *(_DWORD *)(v15 + 8) > 0u )
      button3 = UFG::UI::GetButton(*(const char **)v15);
    v16 = v10->i_user_data;
    if ( *(_DWORD *)(v16 + 8) > 0u )
      button4 = UFG::UI::GetButton(*(const char **)v16);
    v17 = v11->i_user_data;
    if ( *(_DWORD *)(v17 + 8) > 0u )
      button5 = UFG::UI::GetButton(*(const char **)v17);
    v18 = v5->i_user_data;
    if ( *(_DWORD *)(v18 + 8) > 0u )
      buttonAction1 = UFG::UIHKScreenFightTutorial::GetAction(*(const char **)v18);
    v19 = v8->i_user_data;
    if ( *(_DWORD *)(v19 + 8) > 0u )
      buttonAction2 = UFG::UIHKScreenFightTutorial::GetAction(*(const char **)v19);
    if ( *((_DWORD *)*v34 + 2) > 0u )
      buttonAction3 = UFG::UIHKScreenFightTutorial::GetAction(**v34);
    if ( *((_DWORD *)*v32 + 2) <= 0u )
      buttonAction4 = 0;
    else
      buttonAction4 = UFG::UIHKScreenFightTutorial::GetAction(**v32);
    if ( *((_DWORD *)*v38 + 2) <= 0u )
      buttonAction5 = 0;
    else
      buttonAction5 = UFG::UIHKScreenFightTutorial::GetAction(**v38);
    if ( *((_DWORD *)*v36 + 2) <= 0u )
      buttonSeperator2 = 0;
    else
      buttonSeperator2 = UFG::UIHKScreenFightTutorial::GetSeperator(**v36);
    if ( *((_DWORD *)*v33 + 2) <= 0u )
      buttonSeperator3 = 0;
    else
      buttonSeperator3 = UFG::UIHKScreenFightTutorial::GetSeperator(**v33);
    if ( *((_DWORD *)*v35 + 2) <= 0u )
      buttonSeperator4 = 0;
    else
      buttonSeperator4 = UFG::UIHKScreenFightTutorial::GetSeperator(**v35);
    if ( *((_DWORD *)*v37 + 2) > 0u )
      buttonSeperator5 = UFG::UIHKScreenFightTutorial::GetSeperator(**v37);
    v25 = **v39;
    v26 = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                            (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                            "FightingTutorial");
    UFG::UIHKScreenFightTutorial::SetSequence(
      v26,
      v25,
      v4,
      buttonAction1,
      button2,
      buttonAction2,
      buttonSeperator2,
      button3,
      buttonAction3,
      buttonSeperator3,
      button4,
      buttonAction4,
      buttonSeperator4,
      button5,
      buttonAction5,
      buttonSeperator5);
  }
}

// File Line: 149
// RVA: 0x4EC320
void __fastcall UFG::TSUI_FightTutorial::MthdC_reset(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenFightTutorial *v2; // rax

  if ( UFG::UIScreenManagerBase::getOverlay(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "FightingTutorial") )
  {
    v2 = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                           "FightingTutorial");
    UFG::UIHKScreenFightTutorial::InitSequence(v2);
  }
}

// File Line: 156
// RVA: 0x4E9080
void __fastcall UFG::TSUI_FightTutorial::MthdC_hit_success(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  int v3; // ebx
  UFG::UIHKScreenFightTutorial *v4; // rax

  v2 = pScope;
  if ( UFG::UIScreenManagerBase::getOverlay(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "FightingTutorial") )
  {
    v3 = (*v2->i_data.i_array_p)->i_data_p->i_user_data;
    v4 = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                           "FightingTutorial");
    UFG::UIHKScreenFightTutorial::HitSuccess(v4, v3);
  }
}

// File Line: 167
// RVA: 0x4E9020
void __fastcall UFG::TSUI_FightTutorial::MthdC_hit_failed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  int v3; // ebx
  UFG::UIHKScreenFightTutorial *v4; // rax

  v2 = pScope;
  if ( UFG::UIScreenManagerBase::getOverlay(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "FightingTutorial") )
  {
    v3 = (*v2->i_data.i_array_p)->i_data_p->i_user_data;
    v4 = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                           "FightingTutorial");
    UFG::UIHKScreenFightTutorial::HitFailed(v4, v3);
  }
}

// File Line: 179
// RVA: 0x4E9AF0
void __fastcall UFG::TSUI_FightTutorial::MthdC_is_success(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIHKScreenFightTutorial *v3; // rax
  bool v4; // al

  if ( ppResult )
  {
    v2 = ppResult;
    if ( UFG::UIScreenManagerBase::getOverlay(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "FightingTutorial") )
    {
      v3 = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                             "FightingTutorial");
      v4 = UFG::UIHKScreenFightTutorial::IsSuccess(v3);
      *v2 = (SSInstance *)SSBoolean::pool_new(v4);
    }
  }
}

// File Line: 189
// RVA: 0x4E41E0
void __fastcall UFG::TSUI_FightTutorial::MthdC_button_pressed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  const char *v3; // rbx
  UFG::UIHKScreenFightTutorial *v4; // rax

  v2 = pScope;
  if ( UFG::UIScreenManagerBase::getOverlay(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "FightingTutorial") )
  {
    v3 = *(const char **)(*v2->i_data.i_array_p)->i_data_p->i_user_data;
    v4 = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                           "FightingTutorial");
    UFG::UIHKScreenFightTutorial::ButtonPressed(v4, v3);
  }
}

// File Line: 201
// RVA: 0x4E4180
void __fastcall UFG::TSUI_FightTutorial::MthdC_button_held(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  const char *v3; // rbx
  UFG::UIHKScreenFightTutorial *v4; // rax

  v2 = pScope;
  if ( UFG::UIScreenManagerBase::getOverlay(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "FightingTutorial") )
  {
    v3 = *(const char **)(*v2->i_data.i_array_p)->i_data_p->i_user_data;
    v4 = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                           "FightingTutorial");
    UFG::UIHKScreenFightTutorial::ButtonHeld(v4, v3);
  }
}

// File Line: 212
// RVA: 0x4EF450
void __fastcall UFG::TSUI_FightTutorial::MthdC_set_visible(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  bool v3; // bl
  UFG::UIHKScreenFightTutorial *v4; // rax

  v2 = pScope;
  if ( UFG::UIScreenManagerBase::getOverlay(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "FightingTutorial") )
  {
    v3 = (*v2->i_data.i_array_p)->i_data_p->i_user_data != 0;
    v4 = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                           "FightingTutorial");
    UFG::UIHKScreenFightTutorial::SetVisible(v4, v3);
  }
}

