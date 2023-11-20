// File Line: 34
// RVA: 0x4D7FA0
void UFG::TSUI_MartialArts::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("MartialArts");
  SSClass::register_method_func(v0, "start", UFG::TSUI_MartialArts::MthdC_start, 1, 0);
  SSClass::register_method_func(v0, "end", UFG::TSUI_MartialArts::MthdC_end, 1, 0);
  SSClass::register_method_func(v0, "add_move", UFG::TSUI_MartialArts::MthdC_add_move, 1, 0);
  SSClass::register_method_func(v0, "get_move_index", UFG::TSUI_MartialArts::MthdC_get_move_index, 1, 0);
  SSClass::register_method_func(v0, "is_ready", UFG::TSUI_MartialArts::MthdC_is_ready, 1, 0);
  SSClass::register_method_func(v0, "is_hud_active", UFG::TSUI_MartialArts::MthdC_is_hud_active, 1, 0);
}

// File Line: 47
// RVA: 0x4E9500
void __fastcall UFG::TSUI_MartialArts::MthdC_is_hud_active(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax
  bool v4; // cl

  if ( ppResult )
  {
    v2 = ppResult;
    v3 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "MartialArts");
    v4 = 1;
    if ( !v3 )
      v4 = 0;
    *v2 = (SSInstance *)SSBoolean::pool_new(v4);
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
  UFG::UIHKScreenMartialArts *v2; // rax

  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "MartialArts") )
  {
    v2 = (UFG::UIHKScreenMartialArts *)UFG::UIScreenManagerBase::getScreen(
                                         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                         "MartialArts");
    UFG::UIHKScreenMartialArts::PopScreen(v2);
  }
}

// File Line: 76
// RVA: 0x4E3020
void __fastcall UFG::TSUI_MartialArts::MthdC_add_move(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInvokedMethod *v2; // rbx
  SSData **v3; // rcx
  SSInstance *v4; // rbx
  bool v5; // si
  UFG::qString *v6; // rax
  UFG::qString *v7; // rdi
  UFG::qString *v8; // rax
  UFG::qString *v9; // rbx
  UFG::UIHKScreenMartialArts *v10; // rcx
  UFG::qString v11; // [rsp+28h] [rbp-60h]
  UFG::qString v12; // [rsp+50h] [rbp-38h]

  v2 = pScope;
  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "MartialArts") )
  {
    v3 = v2->i_data.i_array_p;
    v4 = (*v3)->i_data_p;
    v5 = v3[2]->i_data_p->i_user_data != 0;
    UFG::qString::qString(&v11, *(const char **)v3[1]->i_data_p->i_user_data);
    v7 = v6;
    UFG::qString::qString(&v12, *(const char **)v4->i_user_data);
    v9 = v8;
    v10 = (UFG::UIHKScreenMartialArts *)UFG::UIScreenManagerBase::getScreen(
                                          (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
                                          "MartialArts");
    UFG::UIHKScreenMartialArts::AddMove(v10, v9, v7, v5);
  }
}

// File Line: 90
// RVA: 0x4E8120
void __fastcall UFG::TSUI_MartialArts::MthdC_get_move_index(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax

  v2 = ppResult;
  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "MartialArts") )
  {
    v3 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "MartialArts");
    *v2 = SSInstance::pool_new(SSBrain::c_integer_class_p, LODWORD(v3[1].mPrev));
  }
}

// File Line: 100
// RVA: 0x4E9920
void __fastcall UFG::TSUI_MartialArts::MthdC_is_ready(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx
  UFG::UIScreen *v3; // rax

  v2 = ppResult;
  if ( UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "MartialArts") )
  {
    v3 = UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           "MartialArts");
    *v2 = (SSInstance *)SSBoolean::pool_new(BYTE4(v3[1].vfptr));
  }
}

