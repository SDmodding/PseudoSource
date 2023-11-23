// File Line: 50
// RVA: 0x4D44A0
void UFG::TSMinigame::BindAtomics(void)
{
  SSClass *v0; // rbx
  ASymbol rebind; // [rsp+20h] [rbp-18h]
  ASymbol rebinda; // [rsp+20h] [rbp-18h]
  ASymbol rebindb; // [rsp+20h] [rbp-18h]

  v0 = SSBrain::get_class("Minigame");
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_minigame_started",
    UFG::TSMinigame::Coro_wait_until_minigame_started,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_minigame_finished",
    UFG::TSMinigame::Coro_wait_until_minigame_finished,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_poker_round_end",
    UFG::TSMinigame::Coro_wait_until_poker_round_end,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_poker_round_start",
    UFG::TSMinigame::Coro_wait_until_poker_round_start,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_poker_profit_reaches",
    UFG::TSMinigame::Coro_wait_until_poker_profit_reaches,
    SSBindFlag_instance_no_rebind);
  SSClass::register_coroutine_func(
    v0,
    "_wait_until_phonetrace_loads",
    UFG::TSMinigame::Coro_wait_until_phonetrace_loads,
    SSBindFlag_instance_no_rebind);
  LOBYTE(rebind.i_uid) = 0;
  SSClass::register_method_func(v0, "is_minigame_started", UFG::TSMinigame::MthdC_is_minigame_started, 1, rebind);
  LOBYTE(rebinda.i_uid) = 0;
  SSClass::register_method_func(v0, "is_in_minigame", UFG::TSMinigame::MthdC_is_in_minigame, 1, rebinda);
  LOBYTE(rebindb.i_uid) = 0;
  SSClass::register_method_func(v0, "fail_minigame", UFG::TSMinigame::MthdC_fail_minigame, 1, rebindb);
}

// File Line: 73
// RVA: 0x4DF130
__int64 __fastcall UFG::TSMinigame::Coro_wait_until_phonetrace_loads(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *Screen; // rax

  Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "PhoneTraceMinigame");
  if ( Screen )
    return LOBYTE(Screen[1].mNext);
  else
    return 1i64;
}

// File Line: 92
// RVA: 0x4DEF80
bool __fastcall UFG::TSMinigame::Coro_wait_until_minigame_started(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *Screen; // rax

  Screen = UFG::UIScreenManagerBase::getScreen(
             UFG::UIScreenManager::s_instance,
             *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data);
  if ( Screen )
  {
    UFG::TSMinigame::gbMinigameRunning = 1;
    LOBYTE(Screen) = 1;
  }
  return (char)Screen;
}

// File Line: 116
// RVA: 0x4DEF10
bool __fastcall UFG::TSMinigame::Coro_wait_until_minigame_finished(SSInvokedCoroutine *pScope)
{
  unsigned __int64 i_user_data; // rcx
  _BYTE *v2; // rax
  unsigned __int64 v3; // r8
  char *v4; // rdx

  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  v2 = *(_BYTE **)i_user_data;
  v3 = *(unsigned int *)(i_user_data + 8) + *(_QWORD *)i_user_data + 1i64;
  if ( *(_QWORD *)i_user_data >= v3 )
    return UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "PhoneTraceMinigame") == 0i64;
  v4 = (char *)("PhoneTraceMinigame" - v2);
  while ( *v2 == v2[(_QWORD)v4] )
  {
    if ( (unsigned __int64)++v2 >= v3 )
      return UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "PhoneTraceMinigame") == 0i64;
  }
  return !UFG::TSMinigame::gbMinigameRunning;
}

// File Line: 146
// RVA: 0x4DF1C0
__int64 __fastcall UFG::TSMinigame::Coro_wait_until_poker_round_end(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *Screen; // rax

  Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "PokerDiceMinigame");
  if ( Screen )
    return (unsigned __int8)Screen[1].m_screenName[4];
  else
    return 1i64;
}

// File Line: 165
// RVA: 0x4DF1F0
__int64 __fastcall UFG::TSMinigame::Coro_wait_until_poker_round_start(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *Screen; // rax

  Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "PokerDiceMinigame");
  if ( Screen )
    return (unsigned __int8)Screen[1].m_screenName[5];
  else
    return 1i64;
}

// File Line: 184
// RVA: 0x4DF160
char __fastcall UFG::TSMinigame::Coro_wait_until_poker_profit_reaches(SSInvokedCoroutine *pScope)
{
  UFG::UIScreen *Screen; // rax
  int i_user_data; // edx

  Screen = UFG::UIScreenManagerBase::getScreen(UFG::UIScreenManager::s_instance, "PokerDiceMinigame");
  if ( !Screen )
    return 1;
  i_user_data = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
  if ( i_user_data <= 0 )
    return *(_DWORD *)Screen[1].m_screenName <= i_user_data;
  else
    return *(_DWORD *)Screen[1].m_screenName >= i_user_data;
}

// File Line: 217
// RVA: 0x4E9610
void __fastcall UFG::TSMinigame::MthdC_is_minigame_started(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
  {
    if ( UFG::UIScreenManagerBase::getScreen(
           UFG::UIScreenManager::s_instance,
           *(const char **)(*pScope->i_data.i_array_p)->i_data_p->i_user_data) )
    {
      *ppResult = SSBoolean::pool_new(1);
    }
    else
    {
      *ppResult = SSBoolean::pool_new(0);
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
      *ppResult = SSBoolean::pool_new(1);
    else
      *ppResult = SSBoolean::pool_new(0);
  }
}

// File Line: 252
// RVA: 0x4E61D0
void __fastcall UFG::TSMinigame::MthdC_fail_minigame(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::qNode<UFG::UIScreen,UFG::UIScreen> **TopScreen; // rax

  TopScreen = UFG::UIScreenManagerBase::getTopScreen(UFG::UIScreenManager::s_instance);
  if ( TopScreen )
    *((_BYTE *)TopScreen + 144) = 1;
}

