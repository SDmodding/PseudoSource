// File Line: 52
// RVA: 0x429130
void __fastcall UFG::OSuiteManagerObserver::~OSuiteManagerObserver(UFG::OSuiteManagerObserver *this)
{
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v1; // rdx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v2; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v3; // rax

  this->vfptr = (UFG::OSuiteManagerObserverVtbl *)&UFG::OSuiteManagerObserver::`vftable';
  v1 = (UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 63
// RVA: 0x4293A0
void __fastcall UFG::OsuiteGameConfig::~OsuiteGameConfig(UFG::OsuiteGameConfig *this)
{
  UFG::OsuiteGameConfig *v1; // rbx

  v1 = this;
  this->vfptr = (OSuite::IGameConfigVtbl *)&UFG::OsuiteGameConfig::`vftable';
  UFG::qString::~qString(&this->mGameVersion);
  UFG::qString::~qString(&v1->mBuildId);
}

// File Line: 114
// RVA: 0x429060
void __fastcall UFG::OSuiteManager::~OSuiteManager(UFG::OSuiteManager *this)
{
  UFG::OSuiteManager *v1; // rdi
  UFG::qList<UFG::qString,UFG::qString,1,0> *v2; // rbx
  UFG::qNode<UFG::qString,UFG::qString> *v3; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rax
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v5; // rcx
  UFG::qNode<UFG::OSuiteManagerObserver,UFG::OSuiteManagerObserver> *v6; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v7; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v8; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v9; // rax

  v1 = this;
  this->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OSuiteManager::`vftable';
  v2 = &this->m_FriendsToSend;
  UFG::qList<UFG::qString,UFG::qString,1,0>::DeleteNodes(&this->m_FriendsToSend);
  v3 = v2->mNode.mPrev;
  v4 = v2->mNode.mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mNode.mPrev = &v2->mNode;
  v2->mNode.mNext = &v2->mNode;
  v1->m_GameConfig.vfptr = (OSuite::IGameConfigVtbl *)&UFG::OsuiteGameConfig::`vftable';
  UFG::qString::~qString(&v1->m_GameConfig.mGameVersion);
  UFG::qString::~qString(&v1->m_GameConfig.mBuildId);
  UFG::qList<UFG::ConversationElementInterruption,UFG::ConversationElementInterruption,1,0>::DeleteNodes((UFG::qList<UFG::GUIObjectBase,UFG::GUIObjectBase,1,0> *)&v1->m_lOSuiteObservers);
  v5 = v1->m_lOSuiteObservers.mNode.mPrev;
  v6 = v1->m_lOSuiteObservers.mNode.mNext;
  v5->mNext = v6;
  v6->mPrev = v5;
  v1->m_lOSuiteObservers.mNode.mPrev = &v1->m_lOSuiteObservers.mNode;
  v1->m_lOSuiteObservers.mNode.mNext = &v1->m_lOSuiteObservers.mNode;
  v1->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable';
  v7 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&v1->mPrev;
  v8 = v1->mPrev;
  v9 = v1->mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v7->mPrev = v7;
  v7->mNext = v7;
}

