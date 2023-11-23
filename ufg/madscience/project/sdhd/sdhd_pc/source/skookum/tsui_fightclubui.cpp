// File Line: 35
// RVA: 0x4D7680
void UFG::TSUI_FightClubUI::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("FightClubUI");
  SSClass::register_method_func(v0, "start", UFG::TSUI_FightClubUI::MthdC_start, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "end", UFG::TSUI_FightClubUI::MthdC_end, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "add_fighter", UFG::TSUI_FightClubUI::MthdC_add_fighter, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "get_fighter_index", UFG::TSUI_FightClubUI::MthdC_get_fighter_index, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "get_bet_amount", UFG::TSUI_FightClubUI::MthdC_get_bet_amount, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(v0, "is_ready", UFG::TSUI_FightClubUI::MthdC_is_ready, 1, rebinde);
}

// File Line: 48
// RVA: 0x4F22A0
void __fastcall UFG::TSUI_FightClubUI::MthdC_start(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreenTextureManager *v2; // rax

  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v2, "FightClub", 0i64);
}

// File Line: 54
// RVA: 0x4E54A0
void __fastcall UFG::TSUI_FightClubUI::MthdC_end(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenMartialArts *Screen; // rax

  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "FightClub") )
  {
    Screen = (UFG::UIHKScreenMartialArts *)UFG::UIScreenManagerBase::getScreen(
                                             UFG::UIScreenManager::s_instance,
                                             "FightClub");
    UFG::UIHKScreenMartialArts::PopScreen(Screen);
  }
}

// File Line: 63
// RVA: 0x4E2EA0
void __fastcall UFG::TSUI_FightClubUI::MthdC_add_fighter(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // r8
  SSInstance *i_data_p; // r15
  SSInstance *v5; // rbx
  int i_user_data; // r13d
  int v7; // r12d
  int v8; // r14d
  int v9; // ebp
  UFG::qString *v10; // rax
  UFG::qString *v11; // rsi
  UFG::qString *v12; // rax
  UFG::qString *v13; // rdi
  UFG::qString *v14; // rax
  UFG::qString *v15; // rbx
  UFG::UIHKScreenFightClub *Screen; // rcx
  UFG::qString v17; // [rsp+50h] [rbp-B8h] BYREF
  UFG::qString v18; // [rsp+78h] [rbp-90h] BYREF
  UFG::qString v19; // [rsp+A0h] [rbp-68h] BYREF

  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "FightClub") )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    v5 = i_array_p[1]->i_data_p;
    i_user_data = i_array_p[3]->i_data_p->i_user_data;
    v7 = i_array_p[4]->i_data_p->i_user_data;
    v8 = i_array_p[5]->i_data_p->i_user_data;
    v9 = i_array_p[6]->i_data_p->i_user_data;
    UFG::qString::qString(&v17, *(const char **)i_array_p[2]->i_data_p->i_user_data);
    v11 = v10;
    UFG::qString::qString(&v18, *(const char **)v5->i_user_data);
    v13 = v12;
    UFG::qString::qString(&v19, *(const char **)i_data_p->i_user_data);
    v15 = v14;
    Screen = (UFG::UIHKScreenFightClub *)UFG::UIScreenManagerBase::getScreen(
                                           UFG::UIScreenManager::s_instance,
                                           "FightClub");
    UFG::UIHKScreenFightClub::AddFigther(Screen, v15, v13, v11, i_user_data, v7, v8, v9);
  }
}

// File Line: 81
// RVA: 0x4E78C0
void __fastcall UFG::TSUI_FightClubUI::MthdC_get_fighter_index(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Screen; // rax

  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "FightClub") )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "FightClub");
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, LODWORD(Screen[1].mNext));
  }
}

// File Line: 90
// RVA: 0x4E7220
void __fastcall UFG::TSUI_FightClubUI::MthdC_get_bet_amount(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Screen; // rax

  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "FightClub") )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "FightClub");
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, *(unsigned int *)&Screen[1].m_screenName[24]);
  }
}

// File Line: 99
// RVA: 0x4E98D0
void __fastcall UFG::TSUI_FightClubUI::MthdC_is_ready(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Screen; // rax

  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "FightClub") )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "FightClub");
    *ppResult = SSBoolean::pool_new((bool)Screen[1].mPrev);
  }
}

