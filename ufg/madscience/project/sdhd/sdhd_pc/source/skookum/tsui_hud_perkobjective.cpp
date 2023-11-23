// File Line: 34
// RVA: 0x4D7D00
void UFG::TSUI_HUD_PerkObjective::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("PerkObjective");
  SSClass::register_method_func(v0, "show", UFG::TSUI_HUD_PerkObjective::MthdC_show, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "hide", UFG::TSUI_HUD_PerkObjective::MthdC_hide, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "update", UFG::TSUI_HUD_PerkObjective::MthdC_update, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "set_success", UFG::TSUI_HUD_PerkObjective::MthdC_set_success, 1, rebindc);
}

// File Line: 45
// RVA: 0x4EFB60
void __fastcall UFG::TSUI_HUD_PerkObjective::MthdC_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  UFG::SecondaryObjective::eID v3; // edi
  SSInstance *i_data_p; // r14
  unsigned int i_user_data; // esi
  unsigned int maxProgress; // ebx
  UFG::ProgressionTracker *v7; // rax

  i_array_p = pScope->i_data.i_array_p;
  v3 = ID_COP_OBJECTIVE;
  i_data_p = i_array_p[1]->i_data_p;
  i_user_data = i_array_p[2]->i_data_p->i_user_data;
  maxProgress = i_array_p[3]->i_data_p->i_user_data;
  if ( LODWORD((*i_array_p)->i_data_p->i_user_data) == qSymbol_Triad_15.mUID )
    v3 = ID_TRIAD_OBJECTIVE;
  v7 = UFG::ProgressionTracker::Instance();
  UFG::SecondaryObjectiveTracker::AddObjective(
    &v7->mSecondaryObjectiveTracker,
    v3,
    *(const char **)i_data_p->i_user_data,
    i_user_data,
    maxProgress);
}

// File Line: 63
// RVA: 0x4E8E30
void __fastcall UFG::TSUI_HUD_PerkObjective::MthdC_hide(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  int v2; // ebx
  UFG::ProgressionTracker *v3; // rax

  v2 = LODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data) == qSymbol_Triad_15.mUID;
  v3 = UFG::ProgressionTracker::Instance();
  UFG::SecondaryObjectiveTracker::RemoveObjective(&v3->mSecondaryObjectiveTracker, v2);
}

// File Line: 78
// RVA: 0x4F2C00
void __fastcall UFG::TSUI_HUD_PerkObjective::MthdC_update(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  UFG::SecondaryObjective::eID v3; // edi
  SSInstance *i_data_p; // r14
  unsigned int i_user_data; // esi
  unsigned int maxProgress; // ebx
  UFG::ProgressionTracker *v7; // rax

  i_array_p = pScope->i_data.i_array_p;
  v3 = ID_COP_OBJECTIVE;
  i_data_p = i_array_p[1]->i_data_p;
  i_user_data = i_array_p[2]->i_data_p->i_user_data;
  maxProgress = i_array_p[3]->i_data_p->i_user_data;
  if ( LODWORD((*i_array_p)->i_data_p->i_user_data) == qSymbol_Triad_15.mUID )
    v3 = ID_TRIAD_OBJECTIVE;
  v7 = UFG::ProgressionTracker::Instance();
  UFG::SecondaryObjectiveTracker::UpdateCaption(
    &v7->mSecondaryObjectiveTracker,
    v3,
    *(const char **)i_data_p->i_user_data,
    i_user_data,
    maxProgress);
}

// File Line: 96
// RVA: 0x4EF250
void __fastcall UFG::TSUI_HUD_PerkObjective::MthdC_set_success(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  SSInstance *i_data_p; // rbx
  bool v4; // di
  UFG::ProgressionTracker *v5; // rax
  UFG::SecondaryObjective::eStatus v6; // r8d

  i_array_p = pScope->i_data.i_array_p;
  i_data_p = (*i_array_p)->i_data_p;
  v4 = i_array_p[1]->i_data_p->i_user_data != 0;
  v5 = UFG::ProgressionTracker::Instance();
  v6 = STATUS_COMPLETED;
  if ( v4 )
    v6 = STATUS_HIGHLIGHT;
  UFG::SecondaryObjectiveTracker::UpdateStatus(
    &v5->mSecondaryObjectiveTracker,
    (UFG::SecondaryObjective::eID)(LODWORD(i_data_p->i_user_data) == qSymbol_Triad_15.mUID),
    v6);
}

