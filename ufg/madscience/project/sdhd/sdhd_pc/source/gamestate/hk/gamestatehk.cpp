// File Line: 37
// RVA: 0x40A0D0
void __fastcall UFG::CreateAndRegisterGameStates(UFG *this)
{
  UFG::allocator::free_link *v1; // rax
  UFG::GameStateFE *v2; // rbx
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rbx
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rbx
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rax
  UFG::allocator::free_link *v9; // rax
  UFG::allocator::free_link *v10; // rbx
  UFG::allocator::free_link *v11; // rax
  UFG::allocator::free_link *v12; // rbx
  UFG::allocator::free_link *v13; // rax
  UFG::GameStateUnloadGame *v14; // rbx
  UFG::allocator::free_link *v15; // rax
  UFG::allocator::free_link *v16; // rbx
  UFG::allocator::free_link *v17; // rax
  UFG::allocator::free_link *v18; // rbx
  UFG::allocator::free_link *v19; // rax
  UFG::allocator::free_link *v20; // rbx

  v1 = UFG::qMalloc(0x68ui64, "gamestate FE", 0i64);
  v2 = (UFG::GameStateFE *)v1;
  if ( v1 )
  {
    UFG::GameState::GameState((UFG::GameState *)v1, "FrontEnd", uidGameStateFE_3);
    v2->vfptr = (UFG::GameStateVtbl *)&GameStateHKBase::`vftable;
    v2->vfptr = (UFG::GameStateVtbl *)&UFG::GameStateFE::`vftable;
  }
  else
  {
    v2 = 0i64;
  }
  UFG::g_FE_GameStateObj = v2;
  v3 = UFG::qMalloc(0x70ui64, "load game gamestate", 0i64);
  v4 = v3;
  if ( v3 )
  {
    UFG::GameState::GameState((UFG::GameState *)v3, "Load Game", uidGameStateLoadGame_3);
    v4->mNext = (UFG::allocator::free_link *)&GameStateHKBase::`vftable;
    v4->mNext = (UFG::allocator::free_link *)&UFG::GameStateLoadGame::`vftable;
    LODWORD(v4[13].mNext) = 0;
  }
  else
  {
    v4 = 0i64;
  }
  UFG::g_LOAD_GAME_GameStateObj = (UFG::GameStateLoadGame *)v4;
  v5 = UFG::qMalloc(0x80ui64, "In game gamestate", 0i64);
  v6 = v5;
  if ( v5 )
  {
    UFG::GameState::GameState((UFG::GameState *)v5, "In Game", uidGameStateInGame_3);
    v6->mNext = (UFG::allocator::free_link *)&GameStateHKBase::`vftable;
    v6->mNext = (UFG::allocator::free_link *)&UFG::GameStateInGame::`vftable;
    LOBYTE(v6[13].mNext) = 1;
    *(UFG::allocator::free_link **)((char *)&v6[13].mNext + 4) = 0i64;
    v7 = UFG::qMalloc(0xB0ui64, "GameSetupStruct", 0i64);
    if ( v7 )
      UFG::GameSetup::GameSetup((UFG::GameSetup *)v7);
    else
      v8 = 0i64;
    v6[15].mNext = v8;
  }
  else
  {
    v6 = 0i64;
  }
  UFG::g_IN_GAME_GameStateObj = (UFG::GameStateInGame *)v6;
  v9 = UFG::qMalloc(0x70ui64, "Change location gamestate", 0i64);
  v10 = v9;
  if ( v9 )
  {
    UFG::GameState::GameState((UFG::GameState *)v9, "Change Location", uidGameStateChangeLocation_3);
    v10->mNext = (UFG::allocator::free_link *)&GameStateHKBase::`vftable;
    v10->mNext = (UFG::allocator::free_link *)&UFG::GameStateChangeLocation::`vftable;
    LODWORD(v10[13].mNext) = 0;
    BYTE4(v10[13].mNext) = 1;
  }
  else
  {
    v10 = 0i64;
  }
  UFG::g_CHANGE_LOCATION_GameStateObj = (UFG::GameStateChangeLocation *)v10;
  v11 = UFG::qMalloc(0x70ui64, "Restore gamestate", 0i64);
  v12 = v11;
  if ( v11 )
  {
    UFG::GameState::GameState((UFG::GameState *)v11, "Restore Checkpoint", uidGameStateRestoreCheckpoint_3);
    v12->mNext = (UFG::allocator::free_link *)&GameStateHKBase::`vftable;
    v12->mNext = (UFG::allocator::free_link *)&UFG::GameStateRestoreCheckpoint::`vftable;
    LODWORD(v12[13].mNext) = 0;
    BYTE4(v12[13].mNext) = 0;
  }
  else
  {
    v12 = 0i64;
  }
  UFG::g_RESTORE_CHECKPOINT_GameStateObj = (UFG::GameStateRestoreCheckpoint *)v12;
  v13 = UFG::qMalloc(0x68ui64, "Unload game gamestate", 0i64);
  v14 = (UFG::GameStateUnloadGame *)v13;
  if ( v13 )
  {
    UFG::GameState::GameState((UFG::GameState *)v13, "Restore Checkpoint", uidGameStateUnloadGame_3);
    v14->vfptr = (UFG::GameStateVtbl *)&GameStateHKBase::`vftable;
    v14->vfptr = (UFG::GameStateVtbl *)&UFG::GameStateUnloadGame::`vftable;
  }
  else
  {
    v14 = 0i64;
  }
  UFG::g_UNLOAD_GAME_GameStateObj = v14;
  v15 = UFG::qMalloc(0x70ui64, "Load game challenge", 0i64);
  v16 = v15;
  if ( v15 )
  {
    UFG::GameState::GameState((UFG::GameState *)v15, "Load Challenge", uidGameStateLoadChallenge_3);
    v16->mNext = (UFG::allocator::free_link *)&GameStateHKBase::`vftable;
    v16->mNext = (UFG::allocator::free_link *)&UFG::GameStateLoadChallenge::`vftable;
    LODWORD(v16[13].mNext) = 0;
  }
  else
  {
    v16 = 0i64;
  }
  UFG::g_LOAD_CHALLENGE_GameStateObj = (UFG::GameStateLoadChallenge *)v16;
  v17 = UFG::qMalloc(0x70ui64, "Unload game challenge", 0i64);
  v18 = v17;
  if ( v17 )
  {
    UFG::GameState::GameState((UFG::GameState *)v17, "Unload Challenge", uidGameStateUnloadChallenge_3);
    v18->mNext = (UFG::allocator::free_link *)&GameStateHKBase::`vftable;
    v18->mNext = (UFG::allocator::free_link *)&UFG::GameStateUnloadChallenge::`vftable;
    LODWORD(v18[13].mNext) = 0;
  }
  else
  {
    v18 = 0i64;
  }
  UFG::g_UNLOAD_CHALLENGE_GameStateObj = (UFG::GameStateUnloadChallenge *)v18;
  v19 = UFG::qMalloc(0x70ui64, "Load NIS gamestate", 0i64);
  v20 = v19;
  if ( v19 )
  {
    UFG::GameState::GameState((UFG::GameState *)v19, "Load NIS", uidGameStateLoadNIS_3);
    v20->mNext = (UFG::allocator::free_link *)&GameStateHKBase::`vftable;
    v20->mNext = (UFG::allocator::free_link *)&UFG::GameStateLoadNIS::`vftable;
    LODWORD(v20[13].mNext) = 1;
  }
  else
  {
    v20 = 0i64;
  }
  UFG::g_LOAD_NIS_GameStateObj = (UFG::GameStateLoadNIS *)v20;
  UFG::FlowController::RegisterGameState(&UFG::gFlowController, (UFG::GameState *)&UFG::g_FE_GameStateObj->vfptr);
  UFG::FlowController::RegisterGameState(&UFG::gFlowController, (UFG::GameState *)&UFG::g_LOAD_GAME_GameStateObj->vfptr);
  UFG::FlowController::RegisterGameState(&UFG::gFlowController, (UFG::GameState *)&UFG::g_IN_GAME_GameStateObj->vfptr);
  UFG::FlowController::RegisterGameState(
    &UFG::gFlowController,
    (UFG::GameState *)&UFG::g_CHANGE_LOCATION_GameStateObj->vfptr);
  UFG::FlowController::RegisterGameState(
    &UFG::gFlowController,
    (UFG::GameState *)&UFG::g_RESTORE_CHECKPOINT_GameStateObj->vfptr);
  UFG::FlowController::RegisterGameState(
    &UFG::gFlowController,
    (UFG::GameState *)&UFG::g_UNLOAD_GAME_GameStateObj->vfptr);
  UFG::FlowController::RegisterGameState(
    &UFG::gFlowController,
    (UFG::GameState *)&UFG::g_LOAD_CHALLENGE_GameStateObj->vfptr);
  UFG::FlowController::RegisterGameState(
    &UFG::gFlowController,
    (UFG::GameState *)&UFG::g_UNLOAD_CHALLENGE_GameStateObj->vfptr);
  UFG::FlowController::RegisterGameState(&UFG::gFlowController, (UFG::GameState *)&UFG::g_LOAD_NIS_GameStateObj->vfptr);
}

