// File Line: 41
// RVA: 0x4E2CA0
void __fastcall UFG::TSUI_GameLog::MthdC_add(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **v2; // rdx
  unsigned int v3; // eax
  const char ***v4; // r8
  const char *v5; // rbx
  UFG::GameLogManager *v6; // rcx
  UFG::qSymbol log_type; // [rsp+40h] [rbp+8h]
  UFG::qSymbol *v8; // [rsp+50h] [rbp+18h]

  v2 = pScope->i_data.i_array_p;
  v3 = v2[1]->i_data_p->i_user_data;
  v4 = (const char ***)&(*v2)->i_data_p->i_user_data;
  if ( (*v2)->i_data_p != (SSInstance *)-32i64 )
  {
    v8 = &log_type;
    log_type.mUID = v3;
    v5 = **v4;
    v6 = UFG::GameLogManager::getInstance();
    UFG::GameLogManager::LogItem(v6, (UFG::qSymbol)&log_type, v5);
  }
}

// File Line: 53
// RVA: 0x4E4300
void __fastcall UFG::TSUI_GameLog::MthdC_clear(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameLogManager *v2; // rax

  v2 = UFG::GameLogManager::getInstance();
  UFG::GameLogManager::Clear(v2);
}

