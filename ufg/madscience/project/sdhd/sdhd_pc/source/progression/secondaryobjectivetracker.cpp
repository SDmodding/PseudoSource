// File Line: 20
// RVA: 0x4914A0
void __fastcall UFG::SecondaryObjectiveTracker::~SecondaryObjectiveTracker(UFG::SecondaryObjectiveTracker *this)
{
  `eh vector destructor iterator'(
    this,
    0x38ui64,
    2,
    (void (__fastcall *)(void *))UFG::SecondaryObjective::~SecondaryObjective);
}

// File Line: 49
// RVA: 0x493830
void __fastcall UFG::SecondaryObjectiveTracker::AddObjective(UFG::SecondaryObjectiveTracker *this, UFG::SecondaryObjective::eID uid, const char *caption, unsigned int progress, unsigned int maxProgress)
{
  unsigned int v5; // ebp
  const char *v6; // rdi
  UFG::SecondaryObjective *v7; // rsi
  UFG::UIHKScreenHud *v8; // rax
  UFG::UIHKScreenWorldMap *v9; // rax

  v5 = progress;
  v6 = caption;
  v7 = &this->mObjectives[uid];
  v7->mStatus = 0;
  UFG::qString::Set(&v7->mCaption, &customWorldMapCaption);
  UFG::qString::Set(&v7->mCaption, v6);
  v7->mStatus = 1;
  v7->mMaxProgress = maxProgress;
  v7->mProgress = v5;
  v8 = UFG::UIHKScreenHud::getInstance();
  if ( v8 )
    UFG::UIHKSecondaryObjectivesWidget::Refresh(&v8->SecondaryObjectives);
  v9 = (UFG::UIHKScreenWorldMap *)UFG::UIHKScreenWorldMap::Get();
  if ( v9 )
    UFG::UIHKScreenWorldMap::RefreshSecondaryObjectives(v9);
}

// File Line: 62
// RVA: 0x4B64D0
void __fastcall UFG::SecondaryObjectiveTracker::RemoveObjective(UFG::SecondaryObjectiveTracker *this, UFG::SecondaryObjective::eID uid)
{
  UFG::qString *v2; // rcx
  signed __int64 v3; // rax
  UFG::UIHKScreenHud *v4; // rax
  UFG::UIHKScreenWorldMap *v5; // rax

  v2 = &this->mObjectives[0].mCaption;
  v3 = 56i64 * (signed int)uid;
  *(_DWORD *)((char *)v2 + v3 - 8) = 0;
  UFG::qString::Set((UFG::qString *)((char *)v2 + v3), &customWorldMapCaption);
  v4 = UFG::UIHKScreenHud::getInstance();
  if ( v4 )
    UFG::UIHKSecondaryObjectivesWidget::Refresh(&v4->SecondaryObjectives);
  v5 = (UFG::UIHKScreenWorldMap *)UFG::UIHKScreenWorldMap::Get();
  if ( v5 )
    UFG::UIHKScreenWorldMap::RefreshSecondaryObjectives(v5);
}

// File Line: 71
// RVA: 0x4C5960
void __fastcall UFG::SecondaryObjectiveTracker::UpdateCaption(UFG::SecondaryObjectiveTracker *this, UFG::SecondaryObjective::eID uid, const char *caption, unsigned int progress, unsigned int maxProgress)
{
  unsigned int v5; // edi
  UFG::SecondaryObjective *v6; // rbx
  UFG::UIHKScreenHud *v7; // rax
  UFG::UIHKScreenWorldMap *v8; // rax

  v5 = progress;
  v6 = &this->mObjectives[uid];
  UFG::qString::Set(&v6->mCaption, caption);
  v6->mProgress = v5;
  v6->mMaxProgress = maxProgress;
  v7 = UFG::UIHKScreenHud::getInstance();
  if ( v7 )
    UFG::UIHKSecondaryObjectivesWidget::Refresh(&v7->SecondaryObjectives);
  v8 = (UFG::UIHKScreenWorldMap *)UFG::UIHKScreenWorldMap::Get();
  if ( v8 )
    UFG::UIHKScreenWorldMap::RefreshSecondaryObjectives(v8);
}

// File Line: 82
// RVA: 0x4C8A20
void __fastcall UFG::SecondaryObjectiveTracker::UpdateStatus(UFG::SecondaryObjectiveTracker *this, UFG::SecondaryObjective::eID uid, UFG::SecondaryObjective::eStatus status)
{
  UFG::UIHKScreenHud *v3; // rax
  UFG::UIHKScreenWorldMap *v4; // rax

  this->mObjectives[uid].mStatus = status;
  v3 = UFG::UIHKScreenHud::getInstance();
  if ( v3 )
    UFG::UIHKSecondaryObjectivesWidget::Refresh(&v3->SecondaryObjectives);
  v4 = (UFG::UIHKScreenWorldMap *)UFG::UIHKScreenWorldMap::Get();
  if ( v4 )
    UFG::UIHKScreenWorldMap::RefreshSecondaryObjectives(v4);
}

// File Line: 101
// RVA: 0x4A5A70
UFG::SecondaryObjective *__fastcall UFG::SecondaryObjectiveTracker::GetObjective(UFG::SecondaryObjectiveTracker *this, UFG::SecondaryObjective::eID uid)
{
  return (UFG::SecondaryObjective *)((char *)this + 56 * uid);
}

