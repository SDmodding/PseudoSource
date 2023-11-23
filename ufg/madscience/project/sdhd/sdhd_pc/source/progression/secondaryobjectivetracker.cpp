// File Line: 20
// RVA: 0x4914A0
void __fastcall UFG::SecondaryObjectiveTracker::~SecondaryObjectiveTracker(UFG::SecondaryObjectiveTracker *this)
{
  `eh vector destructor iterator(
    this,
    0x38ui64,
    2,
    (void (__fastcall *)(void *))UFG::SecondaryObjective::~SecondaryObjective);
}

// File Line: 49
// RVA: 0x493830
void __fastcall UFG::SecondaryObjectiveTracker::AddObjective(
        UFG::SecondaryObjectiveTracker *this,
        UFG::SecondaryObjective::eID uid,
        const char *caption,
        unsigned int progress,
        unsigned int maxProgress)
{
  UFG::SecondaryObjective *v7; // rsi
  UFG::UIHKScreenHud *Instance; // rax
  UFG::UIHKScreenWorldMap *v9; // rax

  v7 = &this->mObjectives[uid];
  v7->mStatus = STATUS_INACTIVE;
  UFG::qString::Set(&v7->mCaption, &customCaption);
  UFG::qString::Set(&v7->mCaption, caption);
  v7->mStatus = STATUS_ACTIVE;
  v7->mMaxProgress = maxProgress;
  v7->mProgress = progress;
  Instance = UFG::UIHKScreenHud::getInstance();
  if ( Instance )
    UFG::UIHKSecondaryObjectivesWidget::Refresh(&Instance->SecondaryObjectives);
  v9 = (UFG::UIHKScreenWorldMap *)UFG::UIHKScreenWorldMap::Get();
  if ( v9 )
    UFG::UIHKScreenWorldMap::RefreshSecondaryObjectives(v9);
}

// File Line: 62
// RVA: 0x4B64D0
void __fastcall UFG::SecondaryObjectiveTracker::RemoveObjective(UFG::SecondaryObjectiveTracker *this, int uid)
{
  UFG::qString *p_mCaption; // rcx
  __int64 v3; // rax
  UFG::UIHKScreenHud *Instance; // rax
  UFG::UIHKScreenWorldMap *v5; // rax

  p_mCaption = &this->mObjectives[0].mCaption;
  v3 = 56i64 * uid;
  *(_DWORD *)((char *)p_mCaption + v3 - 8) = 0;
  UFG::qString::Set((UFG::qString *)((char *)p_mCaption + v3), &customCaption);
  Instance = UFG::UIHKScreenHud::getInstance();
  if ( Instance )
    UFG::UIHKSecondaryObjectivesWidget::Refresh(&Instance->SecondaryObjectives);
  v5 = (UFG::UIHKScreenWorldMap *)UFG::UIHKScreenWorldMap::Get();
  if ( v5 )
    UFG::UIHKScreenWorldMap::RefreshSecondaryObjectives(v5);
}

// File Line: 71
// RVA: 0x4C5960
void __fastcall UFG::SecondaryObjectiveTracker::UpdateCaption(
        UFG::SecondaryObjectiveTracker *this,
        UFG::SecondaryObjective::eID uid,
        const char *caption,
        unsigned int progress,
        unsigned int maxProgress)
{
  UFG::SecondaryObjective *v6; // rbx
  UFG::UIHKScreenHud *Instance; // rax
  UFG::UIHKScreenWorldMap *v8; // rax

  v6 = &this->mObjectives[uid];
  UFG::qString::Set(&v6->mCaption, caption);
  v6->mProgress = progress;
  v6->mMaxProgress = maxProgress;
  Instance = UFG::UIHKScreenHud::getInstance();
  if ( Instance )
    UFG::UIHKSecondaryObjectivesWidget::Refresh(&Instance->SecondaryObjectives);
  v8 = (UFG::UIHKScreenWorldMap *)UFG::UIHKScreenWorldMap::Get();
  if ( v8 )
    UFG::UIHKScreenWorldMap::RefreshSecondaryObjectives(v8);
}

// File Line: 82
// RVA: 0x4C8A20
void __fastcall UFG::SecondaryObjectiveTracker::UpdateStatus(
        UFG::SecondaryObjectiveTracker *this,
        UFG::SecondaryObjective::eID uid,
        UFG::SecondaryObjective::eStatus status)
{
  UFG::UIHKScreenHud *Instance; // rax
  UFG::UIHKScreenWorldMap *v4; // rax

  this->mObjectives[uid].mStatus = status;
  Instance = UFG::UIHKScreenHud::getInstance();
  if ( Instance )
    UFG::UIHKSecondaryObjectivesWidget::Refresh(&Instance->SecondaryObjectives);
  v4 = (UFG::UIHKScreenWorldMap *)UFG::UIHKScreenWorldMap::Get();
  if ( v4 )
    UFG::UIHKScreenWorldMap::RefreshSecondaryObjectives(v4);
}

// File Line: 101
// RVA: 0x4A5A70
UFG::SecondaryObjectiveTracker *__fastcall UFG::SecondaryObjectiveTracker::GetObjective(
        UFG::SecondaryObjectiveTracker *this,
        UFG::SecondaryObjective::eID uid)
{
  return (UFG::SecondaryObjectiveTracker *)((char *)this + 56 * uid);
}

