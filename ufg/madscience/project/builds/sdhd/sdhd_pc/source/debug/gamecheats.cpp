// File Line: 191
// RVA: 0x3FD3E0
void UFG::GameCheats::RestartMission(void)
{
  UFG::ProgressionTracker *v0; // rbx
  UFG::GameSlice *ActiveMaster; // rax

  v0 = UFG::ProgressionTracker::Instance();
  ActiveMaster = UFG::ProgressionTracker::GetActiveMaster(v0);
  if ( ActiveMaster )
  {
    if ( ActiveMaster->mType != NUM_TYPES )
      UFG::ProgressionTracker::Restart(v0, ActiveMaster);
  }
}

// File Line: 201
// RVA: 0x3FD420
void UFG::GameCheats::RestoreCheckpoint(void)
{
  UFG::GameSlice *mpLastCheckpoint; // rcx
  UFG::ProgressionTracker *v1; // rax

  mpLastCheckpoint = UFG::ProgressionTracker::Instance()->mpLastCheckpoint;
  if ( mpLastCheckpoint )
  {
    if ( mpLastCheckpoint->mType != NUM_TYPES )
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
  UFG::ProgressionTracker *v0; // rbx
  UFG::GameSlice *ActiveMaster; // rax

  v0 = UFG::ProgressionTracker::Instance();
  ActiveMaster = UFG::ProgressionTracker::GetActiveMaster(v0);
  if ( ActiveMaster )
  {
    if ( ActiveMaster->mType != NUM_TYPES )
      UFG::ProgressionTracker::CancelMission(v0, ActiveMaster, 1, RestoreType_SafehouseFailure);
  }
}

