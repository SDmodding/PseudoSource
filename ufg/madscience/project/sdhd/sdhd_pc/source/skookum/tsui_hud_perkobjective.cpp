// File Line: 34
// RVA: 0x4D7D00
void UFG::TSUI_HUD_PerkObjective::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("PerkObjective");
  SSClass::register_method_func(v0, "show", UFG::TSUI_HUD_PerkObjective::MthdC_show, 1, 0);
  SSClass::register_method_func(v0, "hide", UFG::TSUI_HUD_PerkObjective::MthdC_hide, 1, 0);
  SSClass::register_method_func(v0, "update", UFG::TSUI_HUD_PerkObjective::MthdC_update, 1, 0);
  SSClass::register_method_func(v0, "set_success", UFG::TSUI_HUD_PerkObjective::MthdC_set_success, 1, 0);
}

// File Line: 45
// RVA: 0x4EFB60
void __fastcall UFG::TSUI_HUD_PerkObjective::MthdC_show(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  UFG::SecondaryObjective::eID v3; // edi
  SSInstance *v4; // r14
  unsigned int v5; // esi
  unsigned int maxProgress; // ebx
  UFG::ProgressionTracker *v7; // rax

  v2 = pScope->i_data.i_array_p;
  v3 = 0;
  v4 = v2[1]->i_data_p;
  v5 = v2[2]->i_data_p->i_user_data;
  maxProgress = v2[3]->i_data_p->i_user_data;
  if ( LODWORD((*v2)->i_data_p->i_user_data) == qSymbol_Triad_15.mUID )
    v3 = 1;
  v7 = UFG::ProgressionTracker::Instance();
  UFG::SecondaryObjectiveTracker::AddObjective(
    &v7->mSecondaryObjectiveTracker,
    v3,
    *(const char **)v4->i_user_data,
    v5,
    maxProgress);
}

// File Line: 63
// RVA: 0x4E8E30
void __fastcall UFG::TSUI_HUD_PerkObjective::MthdC_hide(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::SecondaryObjective::eID v2; // ebx
  UFG::ProgressionTracker *v3; // rax

  v2 = 0;
  if ( LODWORD((*pScope->i_data.i_array_p)->i_data_p->i_user_data) == qSymbol_Triad_15.mUID )
    v2 = 1;
  v3 = UFG::ProgressionTracker::Instance();
  UFG::SecondaryObjectiveTracker::RemoveObjective(&v3->mSecondaryObjectiveTracker, v2);
}

// File Line: 78
// RVA: 0x4F2C00
void __fastcall UFG::TSUI_HUD_PerkObjective::MthdC_update(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  UFG::SecondaryObjective::eID v3; // edi
  SSInstance *v4; // r14
  unsigned int v5; // esi
  unsigned int maxProgress; // ebx
  UFG::ProgressionTracker *v7; // rax

  v2 = pScope->i_data.i_array_p;
  v3 = 0;
  v4 = v2[1]->i_data_p;
  v5 = v2[2]->i_data_p->i_user_data;
  maxProgress = v2[3]->i_data_p->i_user_data;
  if ( LODWORD((*v2)->i_data_p->i_user_data) == qSymbol_Triad_15.mUID )
    v3 = 1;
  v7 = UFG::ProgressionTracker::Instance();
  UFG::SecondaryObjectiveTracker::UpdateCaption(
    &v7->mSecondaryObjectiveTracker,
    v3,
    *(const char **)v4->i_user_data,
    v5,
    maxProgress);
}

// File Line: 96
// RVA: 0x4EF250
void __fastcall UFG::TSUI_HUD_PerkObjective::MthdC_set_success(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  SSInstance *v3; // rbx
  bool v4; // di
  UFG::ProgressionTracker *v5; // rax
  UFG::SecondaryObjective::eID v6; // edx
  UFG::SecondaryObjective::eStatus v7; // er8

  v2 = pScope->i_data.i_array_p;
  v3 = (*v2)->i_data_p;
  v4 = v2[1]->i_data_p->i_user_data != 0;
  v5 = UFG::ProgressionTracker::Instance();
  v6 = 0;
  if ( LODWORD(v3->i_user_data) == qSymbol_Triad_15.mUID )
    v6 = 1;
  v7 = 3;
  if ( v4 )
    v7 = 2;
  UFG::SecondaryObjectiveTracker::UpdateStatus(&v5->mSecondaryObjectiveTracker, v6, v7);
}

