// File Line: 63
// RVA: 0x429690
UFG::OSuiteLeaderboardData *__fastcall UFG::OSuiteLeaderboardData::operator=(UFG::OSuiteLeaderboardData *this, UFG::OSuiteLeaderboardData *other)
{
  UFG::OSuiteLeaderboardData *v2; // rbx
  UFG::OSuiteLeaderboardData *v3; // rdi

  v2 = other;
  v3 = this;
  UFG::qString::Set(&this->mCaption, other->mCaption.mData, other->mCaption.mLength, 0i64, 0);
  v3->mSliceName.mUID = v2->mSliceName.mUID;
  UFG::qString::Set(&v3->mSliceNameStr, v2->mSliceNameStr.mData, v2->mSliceNameStr.mLength, 0i64, 0);
  v3->mLeaderboardName.mUID = v2->mLeaderboardName.mUID;
  UFG::qString::Set(&v3->mLeaderboardNameStr, v2->mLeaderboardNameStr.mData, v2->mLeaderboardNameStr.mLength, 0i64, 0);
  UFG::qString::Set(&v3->mDesc, v2->mDesc.mData, v2->mDesc.mLength, 0i64, 0);
  v3->mLeaderboardId = v2->mLeaderboardId;
  v3->mLeaderboardLocalId = v2->mLeaderboardLocalId;
  UFG::qString::Set(&v3->mImage, v2->mImage.mData, v2->mImage.mLength, 0i64, 0);
  v3->mCategory = v2->mCategory;
  v3->mFormat = v2->mFormat;
  v3->mGold = v2->mGold;
  v3->mSilver = v2->mSilver;
  v3->mBronze = v2->mBronze;
  v3->mStartMs = v2->mStartMs;
  v3->mDeltaTime = v2->mDeltaTime;
  v3->mAttemptCount = v2->mAttemptCount;
  UFG::qString::Set(&v3->mRankDesc, v2->mRankDesc.mData, v2->mRankDesc.mLength, 0i64, 0);
  v3->mFlow.mUID = v2->mFlow.mUID;
  return v3;
}

// File Line: 144
// RVA: 0x4294F0
void __fastcall UFG::OSuiteLeaderboardManager::UpdateEvent::~UpdateEvent(UFG::OSuiteLeaderboardManager::UpdateEvent *this)
{
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v1; // rdx
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v2; // rcx
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v3; // rax

  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable';
  v1 = (UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 168
// RVA: 0x4293E0
void __fastcall UFG::OSuiteLeaderboardManager::Score::~Score(UFG::OSuiteLeaderboardManager::Score *this)
{
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v1; // rdx
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v2; // rcx
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v3; // rax

  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::Score::`vftable';
  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable';
  v1 = (UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 198
// RVA: 0x4288C0
void __fastcall UFG::OSuiteLeaderboardManager::RaceScore::RaceScore(UFG::OSuiteLeaderboardManager::RaceScore *this, UFG::OSuiteLeaderboardData *pLBD, int score, bool isWin, const char *carUsed, void (__fastcall *p)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteLeaderboardData *))
{
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v6; // rax

  v6 = (UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *)&this->mPrev;
  v6->mPrev = v6;
  v6->mNext = v6;
  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable';
  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::Score::`vftable';
  this->m_pLBD = pLBD;
  this->m_iScore = score;
  this->m_pCallback = p;
  this->m_eType = 3;
  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::RaceScore::`vftable';
  this->m_bIsWin = isWin;
  UFG::qString::qString(&this->m_sCarUsed, carUsed);
}

// File Line: 305
// RVA: 0x428F40
void __fastcall UFG::OSuiteLeaderboardManager::~OSuiteLeaderboardManager(UFG::OSuiteLeaderboardManager *this)
{
  UFG::OSuiteLeaderboardManager *v1; // rdi
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v2; // rsi
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v3; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v4; // rax
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v5; // rcx
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v6; // rax
  UFG::OSuiteLeaderboardData **v7; // rcx
  UFG::OSuiteLeaderboardData **v8; // rcx
  UFG::OSuiteLeaderboardData *v9; // rcx
  UFG::qSymbol *v10; // rbx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v11; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v12; // rax

  v1 = this;
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteLeaderboardManager::`vftable';
  UFG::OSuiteManager::Instance();
  v2 = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  _((AMD_HD3D *)&v1->m_cUpdateThread);
  UFG::qEvent::~qEvent(&v1->m_cThreadEvent);
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&v1->m_cMutex);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->m_updateEvents);
  v5 = v1->m_updateEvents.mNode.mPrev;
  v6 = v1->m_updateEvents.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->m_updateEvents.mNode.mPrev = &v1->m_updateEvents.mNode;
  v1->m_updateEvents.mNode.mNext = &v1->m_updateEvents.mNode;
  v7 = v1->mLeaderboardData_SortedByLeaderboardName.p;
  if ( v7 )
    operator delete[](v7);
  v1->mLeaderboardData_SortedByLeaderboardName.p = 0i64;
  *(_QWORD *)&v1->mLeaderboardData_SortedByLeaderboardName.size = 0i64;
  v8 = v1->mLeaderboardData_SortedBySliceName.p;
  if ( v8 )
    operator delete[](v8);
  v1->mLeaderboardData_SortedBySliceName.p = 0i64;
  *(_QWORD *)&v1->mLeaderboardData_SortedBySliceName.size = 0i64;
  v9 = v1->mLeaderboardData.p;
  if ( v9 )
  {
    v10 = &v9[-1].mFlow;
    `eh vector destructor iterator'(
      v9,
      0x138ui64,
      v9[-1].mFlow.mUID,
      (void (__fastcall *)(void *))UFG::OSuiteLeaderboardData::~OSuiteLeaderboardData);
    operator delete[](v10);
  }
  v1->mLeaderboardData.p = 0i64;
  *(_QWORD *)&v1->mLeaderboardData.size = 0i64;
  v1->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable';
  v11 = v2->mPrev;
  v12 = v1->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v2->mPrev = v2;
  v1->mNext = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&v1->mPrev;
}

