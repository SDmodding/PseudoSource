// File Line: 41
// RVA: 0x4E2CA0
void __fastcall UFG::TSUI_GameLog::MthdC_add(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSData **i_array_p; // rdx
  unsigned int i_user_data; // eax
  const char ***p_i_user_data; // r8
  const char *v5; // rbx
  UFG::GameLogManager *Instance; // rcx
  UFG::qSymbol log_type; // [rsp+40h] [rbp+8h] BYREF
  UFG::qSymbol *p_log_type; // [rsp+50h] [rbp+18h]

  i_array_p = pScope->i_data.i_array_p;
  i_user_data = i_array_p[1]->i_data_p->i_user_data;
  p_i_user_data = (const char ***)&(*i_array_p)->i_data_p->i_user_data;
  if ( (*i_array_p)->i_data_p != (SSInstance *)-32i64 )
  {
    p_log_type = &log_type;
    log_type.mUID = i_user_data;
    v5 = **p_i_user_data;
    Instance = UFG::GameLogManager::getInstance();
    UFG::GameLogManager::LogItem(Instance, (UFG::qSymbol)&log_type, v5);
  }
}

// File Line: 53
// RVA: 0x4E4300
void __fastcall UFG::TSUI_GameLog::MthdC_clear(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::GameLogManager *Instance; // rax

  Instance = UFG::GameLogManager::getInstance();
  UFG::GameLogManager::Clear(Instance);
}

