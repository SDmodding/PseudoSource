// File Line: 204
// RVA: 0x5EE820
bool __fastcall UFG::UIHKFaceLevelWidget::IsStandingDeltaGonnaCauseLevelUp()
{
  UFG::GameStatTracker *v0; // rdi
  float v1; // xmm6_4
  signed int v2; // ebx

  v0 = UFG::GameStatTracker::Instance();
  v1 = (float)(signed int)UFG::GameStatTracker::GetStat(v0, Standing);
  v2 = UFG::GameStatTracker::GetFaceLevelFromExperience(v0, (signed int)UFG::UIHKFaceLevelWidget::mPreviousStanding);
  return (signed int)UFG::GameStatTracker::GetFaceLevelFromExperience(v0, (signed int)v1) > v2;
}

