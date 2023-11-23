// File Line: 45
// RVA: 0x4D2840
void UFG::TSCockfighting::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("Cockfighting");
  SSClass::register_method_func(v0, "get_fighter_index", UFG::TSCockfighting::MthdC_get_fighter_index, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "get_bet_amount", UFG::TSCockfighting::MthdC_get_bet_amount, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "is_ready", UFG::TSCockfighting::MthdC_is_ready, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "set_fight_over", UFG::TSCockfighting::MthdC_set_fight_over, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "set_bet_min_max", UFG::TSCockfighting::MthdC_set_bet_min_max, 1, rebindd);
}

// File Line: 63
// RVA: 0x4ED340
void __fastcall UFG::TSCockfighting::MthdC_set_bet_min_max(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  unsigned int i_user_data; // r9d
  unsigned int v4; // eax

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = i_array_p[2]->i_data_p->i_user_data;
  v4 = (*i_array_p)->i_data_p->i_user_data;
  UFG::UIHKScreenCockFight::mMaxBet = i_array_p[1]->i_data_p->i_user_data;
  UFG::UIHKScreenCockFight::mBetMultiple = i_user_data;
  UFG::UIHKScreenCockFight::mMinBet = v4;
}

// File Line: 71
// RVA: 0x4EDD40
void __fastcall UFG::TSCockfighting::MthdC_set_fight_over(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v3; // bl
  UFG::UIHKScreenCockFight *Screen; // rax

  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "CockFight") )
  {
    v3 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data != 0;
    Screen = (UFG::UIHKScreenCockFight *)UFG::UIScreenManagerBase::getScreen(
                                           UFG::UIScreenManager::s_instance,
                                           "CockFight");
    UFG::UIHKScreenCockFight::SetFightOver(Screen, v3);
  }
}

// File Line: 81
// RVA: 0x4E7860
void __fastcall UFG::TSCockfighting::MthdC_get_fighter_index(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Screen; // rax

  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "CockFight") )
  {
    if ( ppResult )
    {
      Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "CockFight");
      *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, *(unsigned int *)Screen[1].m_screenName);
    }
  }
}

// File Line: 92
// RVA: 0x4E71E0
void __fastcall UFG::TSCockfighting::MthdC_get_bet_amount(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Screen; // rax

  if ( ppResult )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "CockFight");
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, LODWORD(Screen[2].mPrev));
  }
}

// File Line: 99
// RVA: 0x4E9880
void __fastcall UFG::TSCockfighting::MthdC_is_ready(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Screen; // rax

  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "CockFight") )
  {
    if ( ppResult )
    {
      Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "CockFight");
      *ppResult = SSBoolean::pool_new(BYTE4(Screen[1].mNext));
    }
  }
}

