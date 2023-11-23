// File Line: 63
// RVA: 0x429690
UFG::OSuiteLeaderboardData *__fastcall UFG::OSuiteLeaderboardData::operator=(
        UFG::OSuiteLeaderboardData *this,
        UFG::OSuiteLeaderboardData *other)
{
  UFG::qString::Set(&this->mCaption, other->mCaption.mData, other->mCaption.mLength, 0i64, 0);
  this->mSliceName.mUID = other->mSliceName.mUID;
  UFG::qString::Set(&this->mSliceNameStr, other->mSliceNameStr.mData, other->mSliceNameStr.mLength, 0i64, 0);
  this->mLeaderboardName.mUID = other->mLeaderboardName.mUID;
  UFG::qString::Set(
    &this->mLeaderboardNameStr,
    other->mLeaderboardNameStr.mData,
    other->mLeaderboardNameStr.mLength,
    0i64,
    0);
  UFG::qString::Set(&this->mDesc, other->mDesc.mData, other->mDesc.mLength, 0i64, 0);
  this->mLeaderboardId = other->mLeaderboardId;
  this->mLeaderboardLocalId = other->mLeaderboardLocalId;
  UFG::qString::Set(&this->mImage, other->mImage.mData, other->mImage.mLength, 0i64, 0);
  this->mCategory = other->mCategory;
  this->mFormat = other->mFormat;
  this->mGold = other->mGold;
  this->mSilver = other->mSilver;
  this->mBronze = other->mBronze;
  this->mStartMs = other->mStartMs;
  this->mDeltaTime = other->mDeltaTime;
  this->mAttemptCount = other->mAttemptCount;
  UFG::qString::Set(&this->mRankDesc, other->mRankDesc.mData, other->mRankDesc.mLength, 0i64, 0);
  this->mFlow.mUID = other->mFlow.mUID;
  return this;
}

// File Line: 144
// RVA: 0x4294F0
void __fastcall UFG::OSuiteLeaderboardManager::UpdateEvent::~UpdateEvent(
        UFG::OSuiteLeaderboardManager::UpdateEvent *this)
{
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v1; // rdx
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *mPrev; // rcx
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *mNext; // rax

  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
  v1 = &this->UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 168
// RVA: 0x4293E0
void __fastcall UFG::OSuiteLeaderboardManager::Score::~Score(UFG::OSuiteLeaderboardManager::Score *this)
{
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v1; // rdx
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *mPrev; // rcx
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *mNext; // rax

  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::Score::`vftable;
  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
  v1 = &this->UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 198
// RVA: 0x4288C0
void __fastcall UFG::OSuiteLeaderboardManager::RaceScore::RaceScore(
        UFG::OSuiteLeaderboardManager::RaceScore *this,
        UFG::OSuiteLeaderboardData *pLBD,
        int score,
        bool isWin,
        const char *carUsed,
        void (__fastcall *p)(OSuite::SCallbackData *, OSuite::ZWebServiceClient *, UFG::OSuiteLeaderboardData *))
{
  this->mPrev = &this->UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent>;
  this->mNext = &this->UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent>;
  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::UpdateEvent::`vftable;
  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::Score::`vftable;
  this->m_pLBD = pLBD;
  this->m_iScore = score;
  this->m_pCallback = p;
  this->m_eType = Update_Race;
  this->vfptr = (UFG::OSuiteLeaderboardManager::UpdateEventVtbl *)&UFG::OSuiteLeaderboardManager::RaceScore::`vftable;
  this->m_bIsWin = isWin;
  UFG::qString::qString(&this->m_sCarUsed, carUsed);
}

// File Line: 305
// RVA: 0x428F40
void __fastcall UFG::OSuiteLeaderboardManager::~OSuiteLeaderboardManager(UFG::OSuiteLeaderboardManager *this)
{
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v2; // rsi
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *mPrev; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *mNext; // rax
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v5; // rcx
  UFG::qNode<UFG::OSuiteLeaderboardManager::UpdateEvent,UFG::OSuiteLeaderboardManager::UpdateEvent> *v6; // rax
  UFG::OSuiteLeaderboardData **p; // rcx
  UFG::OSuiteLeaderboardData **v8; // rcx
  UFG::OSuiteLeaderboardData *v9; // rcx
  UFG::qSymbol *p_mFlow; // rbx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v11; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v12; // rax

  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteLeaderboardManager::`vftable;
  UFG::OSuiteManager::Instance();
  v2 = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  this->mNext = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  _((AMD_HD3D *)&this->m_cUpdateThread);
  UFG::qEvent::~qEvent(&this->m_cThreadEvent);
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)&this->m_cMutex);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_updateEvents);
  v5 = this->m_updateEvents.mNode.mPrev;
  v6 = this->m_updateEvents.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->m_updateEvents.mNode.mPrev = &this->m_updateEvents.mNode;
  this->m_updateEvents.mNode.mNext = &this->m_updateEvents.mNode;
  p = this->mLeaderboardData_SortedByLeaderboardName.p;
  if ( p )
    operator delete[](p);
  this->mLeaderboardData_SortedByLeaderboardName.p = 0i64;
  *(_QWORD *)&this->mLeaderboardData_SortedByLeaderboardName.size = 0i64;
  v8 = this->mLeaderboardData_SortedBySliceName.p;
  if ( v8 )
    operator delete[](v8);
  this->mLeaderboardData_SortedBySliceName.p = 0i64;
  *(_QWORD *)&this->mLeaderboardData_SortedBySliceName.size = 0i64;
  v9 = this->mLeaderboardData.p;
  if ( v9 )
  {
    p_mFlow = &v9[-1].mFlow;
    `eh vector destructor iterator(
      v9,
      0x138ui64,
      v9[-1].mFlow.mUID,
      (void (__fastcall *)(void *))UFG::OSuiteLeaderboardData::~OSuiteLeaderboardData);
    operator delete[](p_mFlow);
  }
  this->mLeaderboardData.p = 0i64;
  *(_QWORD *)&this->mLeaderboardData.size = 0i64;
  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable;
  v11 = v2->mPrev;
  v12 = this->mNext;
  v11->mNext = v12;
  v12->mPrev = v11;
  v2->mPrev = v2;
  this->mNext = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
}

