// File Line: 204
// RVA: 0x5EE820
bool __fastcall UFG::UIHKFaceLevelWidget::IsStandingDeltaGonnaCauseLevelUp()
{
  UFG::GameStatTracker *v0; // rdi
  float Stat; // xmm6_4
  int FaceLevelFromExperience; // ebx

  v0 = UFG::GameStatTracker::Instance();
  Stat = (float)(int)UFG::GameStatTracker::GetStat(v0, Standing);
  FaceLevelFromExperience = UFG::GameStatTracker::GetFaceLevelFromExperience(
                              v0,
                              (int)UFG::UIHKFaceLevelWidget::mPreviousStanding);
  return (int)UFG::GameStatTracker::GetFaceLevelFromExperience(v0, (int)Stat) > FaceLevelFromExperience;
}

