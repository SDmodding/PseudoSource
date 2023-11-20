// File Line: 28
// RVA: 0x412470
void __fastcall UFG::GameStateLoadChallenge::OnUpdate(UFG::GameStateLoadChallenge *this, float fRealTimeDelta)
{
  UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateInGame_3);
}

