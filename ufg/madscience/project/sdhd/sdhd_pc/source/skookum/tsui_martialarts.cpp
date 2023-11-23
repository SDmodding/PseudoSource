// File Line: 34
// RVA: 0x4D7FA0
void UFG::TSUI_MartialArts::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]
  ASymbol rebindc; // [rsp+20h] [rbp-18h]
  ASymbol rebindd; // [rsp+20h] [rbp-18h]
  ASymbol rebinde; // [rsp+20h] [rbp-18h]

  LOBYTE(rebind.i_uid) = 0;
  v0 = SSBrain::get_class("MartialArts");
  SSClass::register_method_func(v0, "start", UFG::TSUI_MartialArts::MthdC_start, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "end", UFG::TSUI_MartialArts::MthdC_end, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "add_move", UFG::TSUI_MartialArts::MthdC_add_move, 1, rebindb);
  LOBYTE(rebindc.i_uid) = 0;
  SSClass::register_method_func(v0, "get_move_index", UFG::TSUI_MartialArts::MthdC_get_move_index, 1, rebindc);
  LOBYTE(rebindd.i_uid) = 0;
  SSClass::register_method_func(v0, "is_ready", UFG::TSUI_MartialArts::MthdC_is_ready, 1, rebindd);
  LOBYTE(rebinde.i_uid) = 0;
  SSClass::register_method_func(v0, "is_hud_active", UFG::TSUI_MartialArts::MthdC_is_hud_active, 1, rebinde);
}

// File Line: 47
// RVA: 0x4E9500
void __fastcall UFG::TSUI_MartialArts::MthdC_is_hud_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  bool v3; // cl

  if ( ppResult )
  {
    v3 = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "MartialArts") != 0i64;
    *ppResult = SSBoolean::pool_new(v3);
  }
}

// File Line: 60
// RVA: 0x4F2300
void __fastcall UFG::TSUI_MartialArts::MthdC_start(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreenTextureManager *v2; // rax

  v2 = UFG::UIScreenTextureManager::Instance();
  UFG::UIScreenTextureManager::QueueLoadAndPush(v2, "MartialArts", 0i64);
}

// File Line: 67
// RVA: 0x4E54F0
void __fastcall UFG::TSUI_MartialArts::MthdC_end(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenMartialArts *Screen; // rax

  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "MartialArts") )
  {
    Screen = (UFG::UIHKScreenMartialArts *)UFG::UIScreenManagerBase::getScreen(
                                             UFG::UIScreenManager::s_instance,
                                             "MartialArts");
    UFG::UIHKScreenMartialArts::PopScreen(Screen);
  }
}

// File Line: 76
// RVA: 0x4E3020
void __fastcall UFG::TSUI_MartialArts::MthdC_add_move(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rcx
  SSInstance *i_data_p; // rbx
  bool v5; // si
  UFG::qString *v6; // rax
  UFG::qString *v7; // rdi
  UFG::qString *v8; // rax
  UFG::qString *v9; // rbx
  UFG::UIHKScreenMartialArts *Screen; // rcx
  UFG::qString v11; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString v12; // [rsp+50h] [rbp-38h] BYREF

  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "MartialArts") )
  {
    i_array_p = pScope->i_data.i_array_p;
    i_data_p = (*i_array_p)->i_data_p;
    v5 = i_array_p[2]->i_data_p->i_user_data != 0;
    UFG::qString::qString(&v11, *(const char **)i_array_p[1]->i_data_p->i_user_data);
    v7 = v6;
    UFG::qString::qString(&v12, *(const char **)i_data_p->i_user_data);
    v9 = v8;
    Screen = (UFG::UIHKScreenMartialArts *)UFG::UIScreenManagerBase::getScreen(
                                             UFG::UIScreenManager::s_instance,
                                             "MartialArts");
    UFG::UIHKScreenMartialArts::AddMove(Screen, v9, v7, v5);
  }
}

// File Line: 90
// RVA: 0x4E8120
void __fastcall UFG::TSUI_MartialArts::MthdC_get_move_index(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Screen; // rax

  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "MartialArts") )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "MartialArts");
    *ppResult = SSInstance::pool_new(SSBrain::c_integer_class_p, LODWORD(Screen[1].mPrev));
  }
}

// File Line: 100
// RVA: 0x4E9920
void __fastcall UFG::TSUI_MartialArts::MthdC_is_ready(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIScreen *Screen; // rax

  if ( UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "MartialArts") )
  {
    Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "MartialArts");
    *ppResult = SSBoolean::pool_new(BYTE4(Screen[1].vfptr));
  }
}

