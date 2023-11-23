// File Line: 34
// RVA: 0x4D7750
void UFG::TSUI_FightTutorial::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]
  ASymbol rebindf; // [rsp+20h] [rbp-18h]
  ASymbol rebindg; // [rsp+20h] [rbp-18h]
  ASymbol rebindh; // [rsp+20h] [rbp-18h]
  ASymbol rebindi; // [rsp+20h] [rbp-18h]
  ASymbol rebindj; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("FightTutorial");
  SSClass::register_method_func(v0, "is_active", UFG::TSUI_FightTutorial::MthdC_is_active, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "start", UFG::TSUI_FightTutorial::MthdC_start, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "end", UFG::TSUI_FightTutorial::MthdC_end, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "set_sequence", UFG::TSUI_FightTutorial::MthdC_set_sequence, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "reset", UFG::TSUI_FightTutorial::MthdC_reset, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(v0, "hit_success", UFG::TSUI_FightTutorial::MthdC_hit_success, 1, rebinde);
  LOBYTE(rebindf.i_uid) = 0;
  SSClass::register_method_func(v0, "hit_failed", UFG::TSUI_FightTutorial::MthdC_hit_failed, 1, rebindf);
  LOBYTE(rebindg.i_uid) = 0;
  SSClass::register_method_func(v0, "is_success", UFG::TSUI_FightTutorial::MthdC_is_success, 1, rebindg);
  LOBYTE(rebindh.i_uid) = 0;
  SSClass::register_method_func(v0, "button_pressed", UFG::TSUI_FightTutorial::MthdC_button_pressed, 1, rebindh);
  LOBYTE(rebindi.i_uid) = 0;
  SSClass::register_method_func(v0, "button_held", UFG::TSUI_FightTutorial::MthdC_button_held, 1, rebindi);
  LOBYTE(rebindj.i_uid) = 0;
  SSClass::register_method_func(v0, "set_visible", UFG::TSUI_FightTutorial::MthdC_set_visible, 1, rebindj);
}

// File Line: 54
// RVA: 0x4E9270
void __fastcall UFG::TSUI_FightTutorial::MthdC_is_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult && UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "FightingTutorial") )
    *ppResult = SSBoolean::pool_new(1);
  else
    *ppResult = SSBoolean::pool_new(0);
}

// File Line: 65
// RVA: 0x4F22C0
void __fastcall UFG::TSUI_FightTutorial::MthdC_start(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreenTextureManager *v2; // rax

  if ( !UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "FightingTutorial") )
  {
    v2 = UFG::UIScreenTextureManager::Instance();
    UFG::UIScreenTextureManager::QueueLoadAndPush(v2, "FightingTutorial", 0i64);
  }
}

// File Line: 75
// RVA: 0x4E54E0
// attributes: thunk
void __fastcall UFG::TSUI_FightTutorial::MthdC_end(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenFightTutorial::Pop();
}

// File Line: 81
// RVA: 0x4EEA70
void __fastcall UFG::TSUI_FightTutorial::MthdC_set_sequence(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rcx
  UFG::UI::eButtons Button; // edi
  SSInstance *i_data_p; // rbp
  UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator5; // r13d
  SSInstance *v7; // rbx
  SSInstance *v8; // r12
  SSInstance *v9; // rsi
  SSInstance *v10; // r14
  SSInstance *v11; // r15
  SSData *v12; // rax
  unsigned __int64 i_user_data; // rcx
  unsigned __int64 v14; // rcx
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // rcx
  unsigned __int64 v17; // rcx
  unsigned __int64 v18; // rcx
  unsigned __int64 v19; // rcx
  UFG::UIHKScreenFightTutorial::eButtonAction buttonAction4; // r12d
  UFG::UIHKScreenFightTutorial::eButtonAction buttonAction5; // r15d
  UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator2; // r14d
  UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator3; // ebp
  UFG::UIHKScreenFightTutorial::eButtonSeperator buttonSeperator4; // esi
  const char *v25; // rbx
  UFG::UIHKScreenFightTutorial *Overlay; // rax
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
  const char ***p_i_user_data; // [rsp+E0h] [rbp-48h]
  UFG::UI::eButtons button5; // [rsp+140h] [rbp+18h]
  UFG::UI::eButtons button4; // [rsp+148h] [rbp+20h]

  if ( UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "FightingTutorial") )
  {
    i_array_p = pScope->i_data.i_array_p;
    Button = INVALID_BUTTON;
    p_i_user_data = (const char ***)&(*i_array_p)->i_data_p->i_user_data;
    button2 = INVALID_BUTTON;
    button3 = INVALID_BUTTON;
    i_data_p = i_array_p[2]->i_data_p;
    button4 = INVALID_BUTTON;
    button5 = INVALID_BUTTON;
    buttonAction1 = INVALID_ACTION;
    buttonAction2 = INVALID_ACTION;
    buttonAction3 = INVALID_ACTION;
    v36 = (const char ***)&i_array_p[3]->i_data_p->i_user_data;
    buttonSeperator5 = INVALID_SEPERATOR;
    v7 = i_array_p[4]->i_data_p;
    v8 = i_array_p[5]->i_data_p;
    v33 = (const char ***)&i_array_p[6]->i_data_p->i_user_data;
    v9 = i_array_p[7]->i_data_p;
    v34 = (const char ***)&i_array_p[8]->i_data_p->i_user_data;
    v35 = (const char ***)&i_array_p[9]->i_data_p->i_user_data;
    v10 = i_array_p[10]->i_data_p;
    v32 = (const char ***)&i_array_p[11]->i_data_p->i_user_data;
    v37 = (const char ***)&i_array_p[12]->i_data_p->i_user_data;
    v11 = i_array_p[13]->i_data_p;
    v12 = i_array_p[14];
    i_user_data = i_array_p[1]->i_data_p->i_user_data;
    v38 = (const char ***)&v12->i_data_p->i_user_data;
    if ( *(_DWORD *)(i_user_data + 8) )
      Button = UFG::UI::GetButton(*(const char **)i_user_data);
    v14 = v7->i_user_data;
    if ( *(_DWORD *)(v14 + 8) )
      button2 = UFG::UI::GetButton(*(const char **)v14);
    v15 = v9->i_user_data;
    if ( *(_DWORD *)(v15 + 8) )
      button3 = UFG::UI::GetButton(*(const char **)v15);
    v16 = v10->i_user_data;
    if ( *(_DWORD *)(v16 + 8) )
      button4 = UFG::UI::GetButton(*(const char **)v16);
    v17 = v11->i_user_data;
    if ( *(_DWORD *)(v17 + 8) )
      button5 = UFG::UI::GetButton(*(const char **)v17);
    v18 = i_data_p->i_user_data;
    if ( *(_DWORD *)(v18 + 8) )
      buttonAction1 = UFG::UIHKScreenFightTutorial::GetAction(*(const char **)v18);
    v19 = v8->i_user_data;
    if ( *(_DWORD *)(v19 + 8) )
      buttonAction2 = UFG::UIHKScreenFightTutorial::GetAction(*(const char **)v19);
    if ( *((_DWORD *)*v34 + 2) )
      buttonAction3 = UFG::UIHKScreenFightTutorial::GetAction(**v34);
    if ( *((_DWORD *)*v32 + 2) )
      buttonAction4 = UFG::UIHKScreenFightTutorial::GetAction(**v32);
    else
      buttonAction4 = INVALID_ACTION;
    if ( *((_DWORD *)*v38 + 2) )
      buttonAction5 = UFG::UIHKScreenFightTutorial::GetAction(**v38);
    else
      buttonAction5 = INVALID_ACTION;
    if ( *((_DWORD *)*v36 + 2) )
      buttonSeperator2 = UFG::UIHKScreenFightTutorial::GetSeperator(**v36);
    else
      buttonSeperator2 = INVALID_SEPERATOR;
    if ( *((_DWORD *)*v33 + 2) )
      buttonSeperator3 = UFG::UIHKScreenFightTutorial::GetSeperator(**v33);
    else
      buttonSeperator3 = INVALID_SEPERATOR;
    if ( *((_DWORD *)*v35 + 2) )
      buttonSeperator4 = UFG::UIHKScreenFightTutorial::GetSeperator(**v35);
    else
      buttonSeperator4 = INVALID_SEPERATOR;
    if ( *((_DWORD *)*v37 + 2) )
      buttonSeperator5 = UFG::UIHKScreenFightTutorial::GetSeperator(**v37);
    v25 = **p_i_user_data;
    Overlay = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                                UFG::UIScreenManager::s_instance,
                                                "FightingTutorial");
    UFG::UIHKScreenFightTutorial::SetSequence(
      Overlay,
      v25,
      Button,
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
  UFG::UIHKScreenFightTutorial *Overlay; // rax

  if ( UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "FightingTutorial") )
  {
    Overlay = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                                UFG::UIScreenManager::s_instance,
                                                "FightingTutorial");
    UFG::UIHKScreenFightTutorial::InitSequence(Overlay);
  }
}

// File Line: 156
// RVA: 0x4E9080
void __fastcall UFG::TSUI_FightTutorial::MthdC_hit_success(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int i_user_data; // ebx
  UFG::UIHKScreenFightTutorial *Overlay; // rax

  if ( UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "FightingTutorial") )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    Overlay = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                                UFG::UIScreenManager::s_instance,
                                                "FightingTutorial");
    UFG::UIHKScreenFightTutorial::HitSuccess(Overlay, i_user_data);
  }
}

// File Line: 167
// RVA: 0x4E9020
void __fastcall UFG::TSUI_FightTutorial::MthdC_hit_failed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int i_user_data; // ebx
  UFG::UIHKScreenFightTutorial *Overlay; // rax

  if ( UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "FightingTutorial") )
  {
    i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    Overlay = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                                UFG::UIScreenManager::s_instance,
                                                "FightingTutorial");
    UFG::UIHKScreenFightTutorial::HitFailed(Overlay, i_user_data);
  }
}

// File Line: 179
// RVA: 0x4E9AF0
void __fastcall UFG::TSUI_FightTutorial::MthdC_is_success(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenFightTutorial *Overlay; // rax
  bool IsSuccess; // al

  if ( ppResult )
  {
    if ( UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "FightingTutorial") )
    {
      Overlay = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                                  UFG::UIScreenManager::s_instance,
                                                  "FightingTutorial");
      IsSuccess = UFG::UIHKScreenFightTutorial::IsSuccess(Overlay);
      *ppResult = SSBoolean::pool_new(IsSuccess);
    }
  }
}

// File Line: 189
// RVA: 0x4E41E0
void __fastcall UFG::TSUI_FightTutorial::MthdC_button_pressed(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v3; // rbx
  UFG::UIHKScreenFightTutorial *Overlay; // rax

  if ( UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "FightingTutorial") )
  {
    v3 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    Overlay = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                                UFG::UIScreenManager::s_instance,
                                                "FightingTutorial");
    UFG::UIHKScreenFightTutorial::ButtonPressed(Overlay, v3);
  }
}

// File Line: 201
// RVA: 0x4E4180
void __fastcall UFG::TSUI_FightTutorial::MthdC_button_held(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  const char *v3; // rbx
  UFG::UIHKScreenFightTutorial *Overlay; // rax

  if ( UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "FightingTutorial") )
  {
    v3 = *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data;
    Overlay = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                                UFG::UIScreenManager::s_instance,
                                                "FightingTutorial");
    UFG::UIHKScreenFightTutorial::ButtonHeld(Overlay, v3);
  }
}

// File Line: 212
// RVA: 0x4EF450
void __fastcall UFG::TSUI_FightTutorial::MthdC_set_visible(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v3; // bl
  UFG::UIHKScreenFightTutorial *Overlay; // rax

  if ( UFG::UIScreenManagerBase::getOverlay(UFG::UIScreenManager::s_instance, "FightingTutorial") )
  {
    v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
    Overlay = (UFG::UIHKScreenFightTutorial *)UFG::UIScreenManagerBase::getOverlay(
                                                UFG::UIScreenManager::s_instance,
                                                "FightingTutorial");
    UFG::UIHKScreenFightTutorial::SetVisible(Overlay, v3);
  }
}

