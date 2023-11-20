// File Line: 50
// RVA: 0x4D44A0
void UFG::TSMinigame::BindAtomics(void)
{
  SSClass *v0; // rbx

  v0 = SSBrain::get_class("Minigame");
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_minigame_started",
    UFG::TSMinigame::Coro_wait_until_minigame_started,
    0);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_minigame_finished",
    UFG::TSMinigame::Coro_wait_until_minigame_finished,
    0);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_poker_round_end",
    UFG::TSMinigame::Coro_wait_until_poker_round_end,
    0);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_poker_round_start",
    UFG::TSMinigame::Coro_wait_until_poker_round_start,
    0);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_poker_profit_reaches",
    UFG::TSMinigame::Coro_wait_until_poker_profit_reaches,
    0);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_phonetrace_loads",
    UFG::TSMinigame::Coro_wait_until_phonetrace_loads,
    0);
  SSClass::register_method_func(v0, "is_minigame_started", UFG::TSMinigame::MthdC_is_minigame_started, 1, 0);
  SSClass::register_method_func(v0, "is_in_minigame", UFG::TSMinigame::MthdC_is_in_minigame, 1, 0);
  SSClass::register_method_func(v0, "fail_minigame", UFG::TSMinigame::MthdC_fail_minigame, 1, 0);
}

// File Line: 73
// RVA: 0x4DF130
signed __int64 __fastcall UFG::TSMinigame::Coro_wait_until_phonetrace_loads(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *v1; // rax
  signed __int64 result; // rax

  v1 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "PhoneTraceMinigame");
  if ( v1 )
    result = LOBYTE(v1[1].mNext);
  else
    result = 1i64;
  return result;
}

// File Line: 92
// RVA: 0x4DEF80
bool __fastcall UFG::TSMinigame::Coro_wait_until_minigame_started(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *v1; // rax

  v1 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  if ( v1 )
  {
    UFG::TSMinigame::gbMinigameRunning = 1;
    LOBYTE(v1) = 1;
  }
  return (char)v1;
}

// File Line: 116
// RVA: 0x4DEF10
bool __fastcall UFG::TSMinigame::Coro_wait_until_minigame_finished(SSInvokedCoroutine *pScope)
{
  unsigned __int64 v1; // rcx
  _BYTE *v2; // rax
  unsigned __int64 v3; // r8
  char *v4; // rdx

  v1 = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v2 = *(_BYTE **)v1;
  v3 = *(unsigned int *)(v1 + 8) + *(_QWORD *)v1 + 1i64;
  if ( *(_QWORD *)v1 >= v3 )
    return UFG::UIScreenManagerBase::getScreen(
             (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
             "PhoneTraceMinigame") == 0i64;
  v4 = (char *)("PhoneTraceMinigame" - v2);
  while ( *v2 == v2[(_QWORD)v4] )
  {
    if ( (unsigned __int64)++v2 >= v3 )
      return UFG::UIScreenManagerBase::getScreen(
               (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
               "PhoneTraceMinigame") == 0i64;
  }
  return UFG::TSMinigame::gbMinigameRunning == 0;
}

// File Line: 146
// RVA: 0x4DF1C0
signed __int64 __fastcall UFG::TSMinigame::Coro_wait_until_poker_round_end(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *v1; // rax
  signed __int64 result; // rax

  v1 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "PokerDiceMinigame");
  if ( v1 )
    result = (unsigned __int8)v1[1].m_screenName[4];
  else
    result = 1i64;
  return result;
}

// File Line: 165
// RVA: 0x4DF1F0
signed __int64 __fastcall UFG::TSMinigame::Coro_wait_until_poker_round_start(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *v1; // rax
  signed __int64 result; // rax

  v1 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "PokerDiceMinigame");
  if ( v1 )
    result = (unsigned __int8)v1[1].m_screenName[5];
  else
    result = 1i64;
  return result;
}

// File Line: 184
// RVA: 0x4DF160
bool __fastcall UFG::TSMinigame::Coro_wait_until_poker_profit_reaches(SSInvokedCoroutine *pScope)
{
  SSInvokedCoroutine *v1; // rbx
  UFG::UIScreen *v2; // rax
  int v3; // edx
  bool result; // al

  v1 = pScope;
  v2 = UFG::UIScreenManagerBase::getScreen(
         (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
         "PokerDiceMinigame");
  if ( !v2 )
    return 1;
  v3 = (*v1->i_data.i_array_p)->i_data_p->i_user_data;
  if ( v3 <= 0 )
    result = *(_DWORD *)v2[1].m_screenName <= v3;
  else
    result = *(_DWORD *)v2[1].m_screenName >= v3;
  return result;
}

// File Line: 217
// RVA: 0x4E9610
void __fastcall UFG::TSMinigame::MthdC_is_minigame_started(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  SSInstance **v2; // rbx

  if ( ppResult )
  {
    v2 = ppResult;
    if ( UFG::UIScreenManagerBase::getScreen(
           (UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr,
           *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data) )
    {
      *v2 = (SSInstance *)SSBoolean::pool_new(1);
    }
    else
    {
      *v2 = (SSInstance *)SSBoolean::pool_new(0);
    }
  }
}

// File Line: 239
// RVA: 0x4E95A0
void __fastcall UFG::TSMinigame::MthdC_is_in_minigame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
  {
    if ( UFG::UIHKMinigameScreen::mNumMinigameScreens )
      *ppResult = (SSInstance *)SSBoolean::pool_new(1);
    else
      *ppResult = (SSInstance *)SSBoolean::pool_new(0);
  }
}

// File Line: 252
// RVA: 0x4E61D0
void __fastcall UFG::TSMinigame::MthdC_fail_minigame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **v2; // rax

  v2 = UFG::UIScreenManagerBase::getTopScreen((UFG::UIScreenManagerBase *)&UFG::UIScreenManager::s_instance->vfptr);
  if ( v2 )
    *((_BYTE *)v2 + 144) = 1;
}

