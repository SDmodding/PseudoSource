// File Line: 17
// RVA: 0x151590
void __fastcall UFG::AchievementTrophyManagerBase::AchievementTrophyManagerBase(
        UFG::AchievementTrophyManagerBase *this)
{
  this->vfptr = (UFG::AchievementTrophyManagerBaseVtbl *)&UFG::AchievementTrophyManagerBase::`vftable;
  this->mTrophyUnlockList.mNode.mPrev = &this->mTrophyUnlockList.mNode;
  this->mTrophyUnlockList.mNode.mNext = &this->mTrophyUnlockList.mNode;
  UFG::qThread::qThread(&this->mTrophyUnlockThread);
  UFG::qMutex::qMutex(&this->mTrophyUnlockMutex, &customCaption);
  this->m_bProcessedUnlock = 0;
  UFG::gRunAchievementTrophyManagerThread = 1;
  UFG::qBaseNodeRB::SetUID((UFG::qBaseNodeRB *)&this->mTrophyUnlockThread, 0x8000u);
  UFG::qThread::SetName((ANTLR3_TOKEN_STREAM_struct *)&this->mTrophyUnlockThread, &unk_1416A5158);
  UFG::qThread::Start(&this->mTrophyUnlockThread, UFG::AchievementTrophyManagerBase::UnlockTrophyThreadFunction, this);
  UFG::qMemSet(this->mTrophyUnlockedFlag, 0, 0x80u);
}

// File Line: 31
// RVA: 0x151660
void __fastcall UFG::AchievementTrophyManagerBase::~AchievementTrophyManagerBase(
        UFG::AchievementTrophyManagerBase *this)
{
  _RTL_CRITICAL_SECTION *p_mTrophyUnlockMutex; // rsi
  UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *p_mTrophyUnlockList; // rdi
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *mNext; // rcx
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *mPrev; // rdx
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v6; // rax
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v7; // rdx
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *v8; // rax
  UFG::qThread *p_mTrophyUnlockThread; // rbx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v10; // rcx
  UFG::qNode<Render::DebugTriStrip,Render::DebugTriStrip> *v11; // rax

  this->vfptr = (UFG::AchievementTrophyManagerBaseVtbl *)&UFG::AchievementTrophyManagerBase::`vftable;
  p_mTrophyUnlockMutex = (_RTL_CRITICAL_SECTION *)&this->mTrophyUnlockMutex;
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTrophyUnlockMutex);
  p_mTrophyUnlockList = (UFG::qList<Render::DebugTriStrip,Render::DebugTriStrip,1,0> *)&this->mTrophyUnlockList;
  while ( (UFG::qList<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode,1,0> *)this->mTrophyUnlockList.mNode.mNext != &this->mTrophyUnlockList )
  {
    mNext = this->mTrophyUnlockList.mNode.mNext;
    mPrev = mNext->mPrev;
    v6 = mNext->mNext;
    mPrev->mNext = v6;
    v6->mPrev = mPrev;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    v7 = mNext->mPrev;
    v8 = mNext->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    mNext->mPrev = mNext;
    mNext->mNext = mNext;
    operator delete[](mNext);
  }
  UFG::qMutex::Unlock(p_mTrophyUnlockMutex);
  UFG::gRunAchievementTrophyManagerThread = 0;
  p_mTrophyUnlockThread = &this->mTrophyUnlockThread;
  UFG::qThread::WaitForCompletion(p_mTrophyUnlockThread);
  UFG::qThread::Stop(p_mTrophyUnlockThread);
  Scaleform::Lock::~Lock(p_mTrophyUnlockMutex);
  _((AMD_HD3D *)p_mTrophyUnlockThread);
  UFG::qList<UFG::InputMessage,UFG::InputMessage,1,0>::DeleteNodes(p_mTrophyUnlockList);
  v10 = p_mTrophyUnlockList->mNode.mPrev;
  v11 = p_mTrophyUnlockList->mNode.mNext;
  v10->mNext = v11;
  v11->mPrev = v10;
  p_mTrophyUnlockList->mNode.mPrev = &p_mTrophyUnlockList->mNode;
  p_mTrophyUnlockList->mNode.mNext = &p_mTrophyUnlockList->mNode;
}

// File Line: 50
// RVA: 0x151880
void __fastcall UFG::AchievementTrophyManagerBase::UnlockTrophyThreadFunction(char *param)
{
  __int64 *v2; // rbx
  __int64 v3; // rcx
  _QWORD *v4; // rax
  __int64 v5; // rcx
  _QWORD *v6; // rax

  while ( UFG::gRunAchievementTrophyManagerThread )
  {
    if ( param )
    {
      v2 = 0i64;
      UFG::qMutex::Lock((LPCRITICAL_SECTION)(param + 216));
      if ( *((char **)param + 18) != param + 136 )
      {
        v2 = (__int64 *)*((_QWORD *)param + 18);
        v3 = *v2;
        v4 = (_QWORD *)v2[1];
        *(_QWORD *)(v3 + 8) = v4;
        *v4 = v3;
        *v2 = (__int64)v2;
        v2[1] = (__int64)v2;
      }
      UFG::qMutex::Unlock((LPCRITICAL_SECTION)(param + 216));
      if ( v2 )
      {
        param[268] = 1;
        if ( !(*(unsigned __int8 (__fastcall **)(char *, _QWORD))(*(_QWORD *)param + 8i64))(
                param,
                *((unsigned int *)v2 + 4)) )
        {
          UFG::qMutex::Lock((LPCRITICAL_SECTION)(param + 216));
          param[268] = 0;
          param[*((int *)v2 + 4) + 8] = 0;
          UFG::qMutex::Unlock((LPCRITICAL_SECTION)(param + 216));
        }
        v5 = *v2;
        v6 = (_QWORD *)v2[1];
        *(_QWORD *)(v5 + 8) = v6;
        *v6 = v5;
        *v2 = (__int64)v2;
        v2[1] = (__int64)v2;
        operator delete[](v2);
      }
      else
      {
        if ( param[268] )
        {
          UFG::qMutex::Lock((LPCRITICAL_SECTION)(param + 216));
          (*(void (__fastcall **)(char *))(*(_QWORD *)param + 16i64))(param);
          UFG::qMutex::Unlock((LPCRITICAL_SECTION)(param + 216));
        }
        param[268] = 0;
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
  UFG::qSymbol *v4; // rbx
  UFG::GameStatTracker *v5; // rax
  bool *v6; // rbx
  char *v7; // rax
  char *v8; // rdx
  UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *mPrev; // rax
  char v10; // bl
  UFG::qWiseSymbol result; // [rsp+58h] [rbp+10h] BYREF
  char *v13; // [rsp+60h] [rbp+18h]

  v2 = type;
  if ( type < 1 || type > this->mLastUnlockableTrophyID )
    return 0;
  v4 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, type);
  v5 = UFG::GameStatTracker::Instance();
  UFG::GameStatTracker::SetStat(v5, AchievementsCompleted, v4, 1);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&this->mTrophyUnlockMutex);
  v6 = &this->mTrophyUnlockedFlag[v2];
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
    mPrev = this->mTrophyUnlockList.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *)v8;
    *(_QWORD *)v8 = mPrev;
    *((_QWORD *)v8 + 1) = &this->mTrophyUnlockList;
    this->mTrophyUnlockList.mNode.mPrev = (UFG::qNode<UFG::TrophyUnlockNode,UFG::TrophyUnlockNode> *)v8;
    v10 = 1;
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&this->mTrophyUnlockMutex);
  return v10;
}

