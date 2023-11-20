// File Line: 191
// RVA: 0x3FD3E0
void UFG::GameCheats::RestartMission(void)
{
  UFG::ProgressionTracker *v0; // rax
  UFG::ProgressionTracker *v1; // rbx
  UFG::GameSlice *v2; // rax

  v0 = UFG::ProgressionTracker::Instance();
  v1 = v0;
  v2 = UFG::ProgressionTracker::GetActiveMaster(v0);
  if ( v2 )
  {
    if ( v2->mType != 2 )
      UFG::ProgressionTracker::Restart(v1, v2);
  }
}

// File Line: 201
// RVA: 0x3FD420
void UFG::GameCheats::RestoreCheckpoint(void)
{
  UFG::GameSlice *v0; // rcx
  UFG::ProgressionTracker *v1; // rax

  v0 = UFG::ProgressionTracker::Instance()->mpLastCheckpoint;
  if ( v0 )
  {
    if ( v0->mType != 2 )
    {
      v1 = UFG::ProgressionTracker::Instance();
      UFG::ProgressionTracker::RestoreCheckpoint(v1);
    }
  }
}

// File Line: 211
// RVA: 0x3FC640
void UFG::GameCheats::CancelMission(void)
{
  UFG::ProgressionTracker *v0; // rax
  UFG::ProgressionTracker *v1; // rbx
  UFG::GameSlice *v2; // rax

  v0 = UFG::ProgressionTracker::Instance();
  v1 = v0;
  v2 = UFG::ProgressionTracker::GetActiveMaster(v0);
  if ( v2 )
  {
    if ( v2->mType != 2 )
      UFG::ProgressionTracker::CancelMission(v1, v2, 1, RestoreType_SafehouseFailure);
  }
}

