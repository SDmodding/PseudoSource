// File Line: 52
// RVA: 0x429130
void __fastcall UFG::OSuiteManagerObserver::~OSuiteManagerObserver(UFG::OSuiteManagerObserver *this)
{
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v1; // rdx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *mPrev; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *mNext; // rax

  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable;
  v1 = &this->UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 63
// RVA: 0x4293A0
void __fastcall UFG::OsuiteGameConfig::~OsuiteGameConfig(UFG::OsuiteGameConfig *this)
{
  this->vfptr = (OSuite::IGameConfigVtbl *)&UFG::OsuiteGameConfig::`vftable;
  UFG::qString::~qString(&this->mGameVersion);
  UFG::qString::~qString(&this->mBuildId);
}

// File Line: 114
// RVA: 0x429060
void __fastcall UFG::OSuiteManager::~OSuiteManager(UFG::OSuiteManager *this)
{
  UFG::qList<UFG::qString,UFG::qString,1,0> *p_m_FriendsToSend; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v5; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v6; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v7; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v8; // rax

  this->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OSuiteManager::`vftable;
  p_m_FriendsToSend = &this->m_FriendsToSend;
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&this->m_FriendsToSend);
  mPrev = p_m_FriendsToSend->mNode.mPrev;
  mNext = p_m_FriendsToSend->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_m_FriendsToSend->mNode.mPrev = &p_m_FriendsToSend->mNode;
  p_m_FriendsToSend->mNode.mNext = &p_m_FriendsToSend->mNode;
  this->m_GameConfig.vfptr = (OSuite::IGameConfigVtbl *)&UFG::OsuiteGameConfig::`vftable;
  UFG::qString::~qString(&this->m_GameConfig.mGameVersion);
  UFG::qString::~qString(&this->m_GameConfig.mBuildId);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&this->m_lOSuiteObservers);
  v5 = this->m_lOSuiteObservers.mNode.mPrev;
  v6 = this->m_lOSuiteObservers.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  this->m_lOSuiteObservers.mNode.mPrev = &this->m_lOSuiteObservers.mNode;
  this->m_lOSuiteObservers.mNode.mNext = &this->m_lOSuiteObservers.mNode;
  this->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  v7 = this->mPrev;
  v8 = this->mNext;
  v7->mNext = v8;
  v8->mPrev = v7;
  this->mPrev = &this->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  this->mNext = &this->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
}

