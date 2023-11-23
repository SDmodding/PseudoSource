// File Line: 32
// RVA: 0x4133A0
void __fastcall UFG::GameStateUnloadChallenge::OnUpdate(UFG::GameStateUnloadChallenge *this, float fRealTimeDelta)
{
  UFG::ProgressionTracker *v2; // rax

  v2 = UFG::ProgressionTracker::Instance();
  UFG::ProgressionTracker::SetMode(v2, ModeType_Normal);
  UFG::FlowController::RequestSetNewState(&UFG::gFlowController, uidGameStateRestoreCheckpoint_3);
}

