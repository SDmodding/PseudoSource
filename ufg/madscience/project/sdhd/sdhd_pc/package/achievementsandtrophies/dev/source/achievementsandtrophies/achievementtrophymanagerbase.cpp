// File Line: 17
// RVA: 0x151590
void __fastcall UFG::AchievementTrophyManagerBase::AchievementTrophyManagerBase(UFG::AchievementTrophyManagerBase *this)
{
  UFG::AchievementTrophyManagerBase *v1; // rdi
  UFG::qList<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode,1,0> *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (UFG::AchievementTrophyManagerBaseVtbl *)&UFG::AchievementTrophyManagerBase::`vftable;
  v2 = &this->mTrophyUnlockList;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  UFG::qThread::qThread(&this->mTrophyUnlockThread);
  UFG::qMutex::qMutex(&v1->mTrophyUnlockMutex, &customWorldMapCaption);
  v1->m_bProcessedUnlock = 0;
  UFG::gRunAchievementTrophyManagerThread = 1;
  UFG::qBaseNodeRB::SetUID((UFG::qBaseNodeRB *)&v1->mTrophyUnlockThread, 0x8000u);
  UFG::qThread::SetName((ANTLR3_TOKEN_STREAM_struct *)&v1->mTrophyUnlockThread, &unk_1416A5158);
  UFG::qThread::Start(&v1->mTrophyUnlockThread, UFG::AchievementTrophyManagerBase::UnlockTrophyThreadFunction, v1);
  UFG::qMemSet(v1->mTrophyUnlockedFlag, 0, 0x80u);
}

// File Line: 31
// RVA: 0x151660
void __fastcall UFG::AchievementTrophyManagerBase::~AchievementTrophyManagerBase(UFG::AchievementTrophyManagerBase *this)
{
  UFG::AchievementTrophyManagerBase *v1; // rbx
  _RTL_CRITICAL_SECTION *v2; // rsi
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *v3; // rdi
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v4; // rcx
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v5; // rdx
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v6; // rax
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v7; // rdx
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v8; // rax
  UFG::qThread *v9; // rbx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v10; // rcx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v11; // rax

  v1 = this;
  this->vfptr = (UFG::AchievementTrophyManagerBaseVtbl *)&UFG::AchievementTrophyManagerBase::`vftable;
  v2 = (_RTL_CRITICAL_SECTION *)&this->mTrophyUnlockMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTrophyUnlockMutex);
  v3 = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&v1->mTrophyUnlockList;
  while ( (UFG::qList<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode,1,0> *)v1->mTrophyUnlockList.mNode.mNext != &v1->mTrophyUnlockList )
  {
    v4 = v1->mTrophyUnlockList.mNode.mNext;
    v5 = v4->mPrev;
    v6 = v4->mNext;
    v5->mNext = v6;
    v6->mPrev = v5;
    v4->mPrev = v4;
    v4->mNext = v4;
    v7 = v4->mPrev;
    v8 = v4->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    v4->mPrev = v4;
    v4->mNext = v4;
    operator delete[](v4);
  }
  UFG::qMutex::Unlock(v2);
  UFG::gRunAchievementTrophyManagerThread = 0;
  v9 = &v1->mTrophyUnlockThread;
  UFG::qThread::WaitForCompletion(v9);
  UFG::qThread::Stop(v9);
  Scaleform::Lock::~Lock(v2);
  _((AMD_HD3D *)v9);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes(v3);
  v10 = v3->mNode.mPrev;
  v11 = v3->mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
}

// File Line: 50
// RVA: 0x151880
void __fastcall UFG::AchievementTrophyManagerBase::UnlockTrophyThreadFunction(void *param)
{
  UFG::AchievementTrophyManager *v1; // rdi
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v2; // rbx
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v3; // rcx
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v4; // rax
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v5; // rcx
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v6; // rax

  v1 = (UFG::AchievementTrophyManager *)param;
  while ( UFG::gRunAchievementTrophyManagerThread )
  {
    if ( v1 )
    {
      v2 = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mTrophyUnlockMutex);
      if ( (UFG::qList<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode,1,0> *)v1->mTrophyUnlockList.mNode.mNext != &v1->mTrophyUnlockList )
      {
        v2 = v1->mTrophyUnlockList.mNode.mNext;
        v3 = v2->mPrev;
        v4 = v2->mNext;
        v3->mNext = v4;
        v4->mPrev = v3;
        v2->mPrev = v2;
        v2->mNext = v2;
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mTrophyUnlockMutex);
      if ( v2 )
      {
        v1->m_bProcessedUnlock = 1;
        if ( !v1->vfptr->UnlockTrophyInternal((UFG::AchievementTrophyManagerBase *)v1, (int)v2[1].mPrev) )
        {
          UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mTrophyUnlockMutex);
          v1->m_bProcessedUnlock = 0;
          v1->mTrophyUnlockedFlag[SLODWORD(v2[1].mPrev)] = 0;
          UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mTrophyUnlockMutex);
        }
        v5 = v2->mPrev;
        v6 = v2->mNext;
        v5->mNext = v6;
        v6->mPrev = v5;
        v2->mPrev = v2;
        v2->mNext = v2;
        operator delete[](v2);
      }
      else
      {
        if ( v1->m_bProcessedUnlock )
        {
          UFG::qMutex::Lock((LPCRITICAL_SECTION)&v1->mTrophyUnlockMutex);
          v1->vfptr->UnlocksDone((UFG::AchievementTrophyManagerBase *)v1);
          UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v1->mTrophyUnlockMutex);
        }
        v1->m_bProcessedUnlock = 0;
      }
    }
    UFG::qSleep(0x32u);
  }
}

// File Line: 103
// RVA: 0x151790
char __fastcall UFG::AchievementTrophyManagerBase::UnlockTrophyBase(UFG::AchievementTrophyManagerBase *this, int type)
{
  __int64 v2; // rdi
  UFG::AchievementTrophyManagerBase *v3; // rsi
  UFG::qSymbol *v4; // rbx
  UFG::GameStatTracker *v5; // rax
  bool *v6; // rbx
  char *v7; // rax
  char *v8; // rdx
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v9; // rax
  char v10; // bl
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h]
  char *v13; // [rsp+60h] [rbp+18h]

  v2 = type;
  v3 = this;
  if ( type < 1 || type > this->mLastUnlockableTrophyID )
    return 0;
  v4 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, type);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, AchievementsCompleted, v4, 1);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&v3->mTrophyUnlockMutex);
  v6 = &v3->mTrophyUnlockedFlag[v2];
  if ( *v6 )
  {
    v10 = 0;
  }
  else
  {
    v7 = UFG::qMalloc(0x18ui64, "TrophyUnlockNode", 0i64);
    v8 = v7;
    v13 = v7;
    if ( v7 )
    {
      *(_QWORD *)v7 = v7;
      *((_QWORD *)v7 + 1) = v7;
    }
    else
    {
      v8 = 0i64;
    }
    *((_DWORD *)v8 + 4) = v2;
    *v6 = 1;
    v9 = v3->mTrophyUnlockList.mNode.mPrev;
    v9->mNext = (UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *)v8;
    *(_QWORD *)v8 = v9;
    *((_QWORD *)v8 + 1) = (char *)v3 + 136;
    v3->mTrophyUnlockList.mNode.mPrev = (UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *)v8;
    v10 = 1;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&v3->mTrophyUnlockMutex);
  return v10;
}

