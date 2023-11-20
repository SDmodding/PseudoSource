// File Line: 35
// RVA: 0x4D7680
void UFG::TSUI_FightClubUI::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("FightClubUI");
  SSClass::register_method_func(v0, "start", UFG::TSUI_FightClubUI::MthdC_start, 1, 0);
  SSClass::register_method_func(v0, "end", UFG::TSUI_FightClubUI::MthdC_end, 1, 0);
  SSClass::register_method_func(v0, "add_fighter", UFG::TSUI_FightClubUI::MthdC_add_fighter, 1, 0);
  SSClass::register_method_func(v0, "get_fighter_index", UFG::TSUI_FightClubUI::MthdC_get_fighter_index, 1, 0);
  SSClass::register_method_func(v0, "get_bet_amount", UFG::TSUI_FightClubUI::MthdC_get_bet_amount, 1, 0);
  SSClass::register_method_func(v0, "is_ready", UFG::TSUI_FightClubUI::MthdC_is_ready, 1, 0);
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
  UFG::UIHKScreenMartialArts *v2; // rax

  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "FightClub") )
  {
    v2 = (UFG::UIHKScreenMartialArts *)UFG::UIScreenManagerBase::getScreen(
                                         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                         "FightClub");
    UFG::UIHKScreenMartialArts::PopScreen(v2);
  }
}

// File Line: 63
// RVA: 0x4E2EA0
void __fastcall UFG::TSUI_FightClubUI::MthdC_add_fighter(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  SSData **v3; // r8
  SSInstance *v4; // r15
  SSInstance *v5; // rbx
  int v6; // er13
  int v7; // er12
  int v8; // er14
  int v9; // ebp
  UFG::qString *v10; // rax
  UFG::qString *v11; // rsi
  UFG::qString *v12; // rax
  UFG::qString *v13; // rdi
  UFG::qString *v14; // rax
  UFG::qString *v15; // rbx
  UFG::UIHKScreenFightClub *v16; // rcx
  UFG::qString v17; // [rsp+50h] [rbp-B8h]
  UFG::qString v18; // [rsp+78h] [rbp-90h]
  UFG::qString v19; // [rsp+A0h] [rbp-68h]

  v2 = pScope;
  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "FightClub") )
  {
    v3 = v2->i_data.i_array_p;
    v4 = (*v3)->i_data_p;
    v5 = v3[1]->i_data_p;
    v6 = v3[3]->i_data_p->i_user_data;
    v7 = v3[4]->i_data_p->i_user_data;
    v8 = v3[5]->i_data_p->i_user_data;
    v9 = v3[6]->i_data_p->i_user_data;
    UFG::qString::qString(&v17, *(const char **)v3[2]->i_data_p->i_user_data);
    v11 = v10;
    UFG::qString::qString(&v18, *(const char **)v5->i_user_data);
    v13 = v12;
    UFG::qString::qString(&v19, *(const char **)v4->i_user_data);
    v15 = v14;
    v16 = (UFG::UIHKScreenFightClub *)UFG::UIScreenManagerBase::getScreen(
                                        (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                        "FightClub");
    UFG::UIHKScreenFightClub::AddFigther(v16, v15, v13, v11, v6, v7, v8, v9);
  }
}

// File Line: 81
// RVA: 0x4E78C0
void __fastcall UFG::TSUI_FightClubUI::MthdC_get_fighter_index(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax

  v2 = ppResult;
  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "FightClub") )
  {
    v3 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "FightClub");
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, LODWORD(v3[1].mNext));
  }
}

// File Line: 90
// RVA: 0x4E7220
void __fastcall UFG::TSUI_FightClubUI::MthdC_get_bet_amount(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax

  v2 = ppResult;
  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "FightClub") )
  {
    v3 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "FightClub");
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, *(unsigned int *)&v3[1].m_screenName[24]);
  }
}

// File Line: 99
// RVA: 0x4E98D0
void __fastcall UFG::TSUI_FightClubUI::MthdC_is_ready(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax

  v2 = ppResult;
  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "FightClub") )
  {
    v3 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "FightClub");
    *v2 = (SSInstance *)SSBoolean::pool_new((bool)v3[1].mPrev);
  }
}

