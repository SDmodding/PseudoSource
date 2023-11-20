// File Line: 45
// RVA: 0x4D2840
void UFG::TSCockfighting::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Cockfighting");
  SSClass::register_method_func(v0, "get_fighter_index", UFG::TSCockfighting::MthdC_get_fighter_index, 1, 0);
  SSClass::register_method_func(v0, "get_bet_amount", UFG::TSCockfighting::MthdC_get_bet_amount, 1, 0);
  SSClass::register_method_func(v0, "is_ready", UFG::TSCockfighting::MthdC_is_ready, 1, 0);
  SSClass::register_method_func(v0, "set_fight_over", UFG::TSCockfighting::MthdC_set_fight_over, 1, 0);
  SSClass::register_method_func(v0, "set_bet_min_max", UFG::TSCockfighting::MthdC_set_bet_min_max, 1, 0);
}

// File Line: 63
// RVA: 0x4ED340
void __fastcall UFG::TSCockfighting::MthdC_set_bet_min_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // r8
  unsigned int v3; // er9
  unsigned int v4; // eax

  v2 = pScope->i_data.i_array_p;
  v3 = v2[2]->i_data_p->i_user_data;
  v4 = (*v2)->i_data_p->i_user_data;
  UFG::UIHKScreenCockFight::mMaxBet = v2[1]->i_data_p->i_user_data;
  UFG::UIHKScreenCockFight::mBetMultiple = v3;
  UFG::UIHKScreenCockFight::mMinBet = v4;
}

// File Line: 71
// RVA: 0x4EDD40
void __fastcall UFG::TSCockfighting::MthdC_set_fight_over(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  bool v3; // bl
  UFG::UIHKScreenCockFight *v4; // rax

  v2 = pScope;
  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "CockFight") )
  {
    v3 = (*v2->i_data.i_array_p)->i_data_p->i_user_data != 0;
    v4 = (UFG::UIHKScreenCockFight *)UFG::UIScreenManagerBase::getScreen(
                                       (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                       "CockFight");
    UFG::UIHKScreenCockFight::SetFightOver(v4, v3);
  }
}

// File Line: 81
// RVA: 0x4E7860
void __fastcall UFG::TSCockfighting::MthdC_get_fighter_index(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax

  v2 = ppResult;
  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "CockFight") )
  {
    if ( v2 )
    {
      v3 = UFG::UIScreenManagerBase::getScreen(
             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
             "CockFight");
      *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, *(unsigned int *)v3[1].m_screenName);
    }
  }
}

// File Line: 92
// RVA: 0x4E71E0
void __fastcall UFG::TSCockfighting::MthdC_get_bet_amount(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "CockFight");
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, LODWORD(v3[2].mPrev));
  }
}

// File Line: 99
// RVA: 0x4E9880
void __fastcall UFG::TSCockfighting::MthdC_is_ready(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax

  v2 = ppResult;
  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "CockFight") )
  {
    if ( v2 )
    {
      v3 = UFG::UIScreenManagerBase::getScreen(
             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
             "CockFight");
      *v2 = (SSInstance *)SSBoolean::pool_new(BYTE4(v3[1].mNext));
    }
  }
}

