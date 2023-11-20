// File Line: 23
// RVA: 0x61F230
bool __fastcall UFG::UIFlow::changeState(UFG::UIFlow *this, UFG::UIFlow::eState new_state)
{
  UFG::UIFlow::eState v2; // esi
  UFG::UIFlow::eState v3; // edi
  UFG::UIFlow *v4; // rbx
  bool result; // al
  UFG::UIFlowVtbl *v6; // rax

  v2 = this->m_state;
  v3 = new_state;
  v4 = this;
  result = this->vfptr->canChangeState(this, this->m_state, new_state);
  if ( result )
  {
    v4->vfptr->handleExitState(v4, v2, v3);
    v6 = v4->vfptr;
    v4->m_state = v3;
    v4->m_time_elapsed_in_state = 0.0;
    v6->handleEnterState(v4, v2, v3);
    result = 1;
  }
  return result;
}

// File Line: 43
// RVA: 0x620670
void __fastcall UFG::UIFlow::flowUpdate(UFG::UIFlow *this, float elapsed)
{
  UFG::UIFlow *v2; // rcx

  this->m_time_elapsed_in_state = elapsed + this->m_time_elapsed_in_state;
  v2 = this->m_child_flow;
  if ( v2 )
    ((void (*)(void))v2->vfptr->flowUpdate)();
}

// File Line: 54
// RVA: 0x620280
bool __fastcall UFG::UIFlow::flowHandleMessage(UFG::UIFlow *this, unsigned int msg_id, UFG::UIMessage *msg)
{
  UFG::UIFlow *v3; // rbx
  UFG::UIFlow *v4; // rcx
  bool result; // al
  UFG::UIMessage *v6; // rsi
  unsigned int v7; // edi

  v3 = this;
  v4 = this->m_child_flow;
  result = 0;
  v6 = msg;
  v7 = msg_id;
  if ( !v4 || (result = ((__int64 (*)(void))v4->vfptr->flowHandleMessage)()) == 0 )
  {
    if ( v7 == UI_HASH_REQUEST_STATE_CHANGE_30 )
      result = v3->vfptr->changeState(v3, (UFG::UIFlow::eState)LODWORD(v6[1].vfptr));
  }
  return result;
}

// File Line: 150
// RVA: 0x1570030
__int64 UFG::_dynamic_initializer_for__qSymbol_StateInit__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_INIT", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateInit, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateInit__);
}

// File Line: 151
// RVA: 0x15701B0
__int64 UFG::_dynamic_initializer_for__qSymbol_StateNormal__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_NORMAL", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateNormal, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateNormal__);
}

// File Line: 152
// RVA: 0x15700B0
__int64 UFG::_dynamic_initializer_for__qSymbol_StateLoading__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_LOADING", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateLoading, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateLoading__);
}

// File Line: 153
// RVA: 0x156FFB0
__int64 UFG::_dynamic_initializer_for__qSymbol_StateIdle__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_IDLE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateIdle, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateIdle__);
}

// File Line: 154
// RVA: 0x1570070
__int64 UFG::_dynamic_initializer_for__qSymbol_StateIntro__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_INTRO", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateIntro, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateIntro__);
}

// File Line: 155
// RVA: 0x156FEB0
__int64 UFG::_dynamic_initializer_for__qSymbol_StateActive__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_ACTIVE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateActive, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateActive__);
}

// File Line: 156
// RVA: 0x15701F0
__int64 UFG::_dynamic_initializer_for__qSymbol_StateOutro__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_OUTRO", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateOutro, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateOutro__);
}

// File Line: 157
// RVA: 0x156FF30
__int64 UFG::_dynamic_initializer_for__qSymbol_StateExit__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_EXIT", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateExit, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateExit__);
}

// File Line: 158
// RVA: 0x15702B0
__int64 UFG::_dynamic_initializer_for__qSymbol_StateSleep__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_SLEEP", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateSleep, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateSleep__);
}

// File Line: 159
// RVA: 0x156FEF0
__int64 UFG::_dynamic_initializer_for__qSymbol_StateDialogPrompt__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_DIALOG_PROMPT", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateDialogPrompt, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateDialogPrompt__);
}

// File Line: 160
// RVA: 0x156FF70
__int64 UFG::_dynamic_initializer_for__qSymbol_StateFrontEnd__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_FRONT_END", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateFrontEnd, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateFrontEnd__);
}

// File Line: 161
// RVA: 0x156FFF0
__int64 UFG::_dynamic_initializer_for__qSymbol_StateInGame__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_IN_GAME", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateInGame, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateInGame__);
}

// File Line: 162
// RVA: 0x1570270
__int64 UFG::_dynamic_initializer_for__qSymbol_StateQuitGame__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_QUIT_GAME", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateQuitGame, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateQuitGame__);
}

// File Line: 163
// RVA: 0x15702F0
__int64 UFG::_dynamic_initializer_for__qSymbol_StateSplash__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_SPLASH", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateSplash, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateSplash__);
}

// File Line: 164
// RVA: 0x15700F0
__int64 UFG::_dynamic_initializer_for__qSymbol_StateMainMenu__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_MAIN_MENU", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateMainMenu, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateMainMenu__);
}

// File Line: 165
// RVA: 0x1570230
__int64 UFG::_dynamic_initializer_for__qSymbol_StatePauseMenu__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_PAUSE_MENU", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StatePauseMenu, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StatePauseMenu__);
}

// File Line: 166
// RVA: 0x1570130
__int64 UFG::_dynamic_initializer_for__qSymbol_StateNIS__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_NIS", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateNIS, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateNIS__);
}

// File Line: 167
// RVA: 0x1570170
__int64 UFG::_dynamic_initializer_for__qSymbol_StateNISPause__()
{
  unsigned int v0; // eax

  v0 = UFG::qStringHash32("STATE_NIS_PAUSE", 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)&qSymbol_StateNISPause, v0);
  return atexit(UFG::_dynamic_atexit_destructor_for__qSymbol_StateNISPause__);
}

