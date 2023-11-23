// File Line: 7
// RVA: 0x42E650
UFG::OnlineManager *__fastcall UFG::OnlineManager::Instance()
{
  if ( (_S5_9 & 1) == 0 )
  {
    _S5_9 |= 1u;
    instance.vfptr = (UFG::OnlineManagerVtbl *)&UFG::OnlineManager::`vftable;
    unk_1424011B8 = 0;
    stru_1424011C0.mNode.mPrev = (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *)&stru_1424011C0;
    stru_1424011C0.mNode.mNext = (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *)&stru_1424011C0;
    UFG::qString::qString(&stru_1424011D0);
    atexit(UFG::OnlineManager::Instance_::_2_::_dynamic_atexit_destructor_for__instance__);
  }
  return &instance;
}

// File Line: 14
// RVA: 0x42E6F0
bool __fastcall UFG::OnlineManager::IsNetworkSignedIn(UFG::OnlineManager *this)
{
  return UFG::OnlineManager::IsNetworkAvailable(this) && UFG::OnlineManager::IsNetworkAvailable(this);
}

// File Line: 20
// RVA: 0x42F900
void __fastcall UFG::OnlineManager::RegisterObserver(UFG::OnlineManager *this, UFG::OnlineManagerObserver *p)
{
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mNext; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v3; // rdx
  UFG::qList<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver,1,0> *p_m_lObservers; // rcx

  mNext = this->m_lObservers.mNode.mNext;
  v3 = &p->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  p_m_lObservers = &this->m_lObservers;
  p_m_lObservers->mNode.mNext = v3;
  v3->mNext = mNext;
  v3->mPrev = &p_m_lObservers->mNode;
  mNext->mPrev = v3;
}

// File Line: 32
// RVA: 0x431640
void __fastcall UFG::OnlineManager::UpdateObservers(UFG::OnlineManager *this)
{
  bool v2; // si
  UFG::OnlineManager *j; // rbx
  UFG::OnlineManager *i; // rbx

  v2 = UFG::OnlineManager::IsNetworkAvailable(this) && UFG::OnlineManager::IsNetworkAvailable(this);
  if ( this->m_bSignedIn )
  {
    if ( !v2 )
    {
      for ( i = (UFG::OnlineManager *)&this->m_lObservers.mNode.mNext[-1].mNext;
            i != (UFG::OnlineManager *)&this->m_bInitialized;
            i = (UFG::OnlineManager *)&i->m_lObservers.mNode.mPrev[-1].mNext )
      {
        ((void (__fastcall *)(UFG::OnlineManager *))i->vfptr[1].RetreivePlayerDisplayImage)(i);
      }
    }
  }
  else if ( v2 )
  {
    for ( j = (UFG::OnlineManager *)&this->m_lObservers.mNode.mNext[-1].mNext;
          j != (UFG::OnlineManager *)&this->m_bInitialized;
          j = (UFG::OnlineManager *)&j->m_lObservers.mNode.mPrev[-1].mNext )
    {
      j->vfptr->~OnlineManager(j);
    }
  }
  this->m_bSignedIn = v2;
}

