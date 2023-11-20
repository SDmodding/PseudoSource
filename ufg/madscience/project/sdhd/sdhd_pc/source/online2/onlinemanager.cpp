// File Line: 7
// RVA: 0x42E650
UFG::OnlineManager *__fastcall UFG::OnlineManager::Instance()
{
  if ( !(_S5_9 & 1) )
  {
    _S5_9 |= 1u;
    instance.vfptr = (UFG::OnlineManagerVtbl *)&UFG::OnlineManager::`vftable';
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
  UFG::OnlineManager *v1; // rbx

  v1 = this;
  return (unsigned __int8)UFG::OnlineManager::IsNetworkAvailable(this)
      && (unsigned __int8)UFG::OnlineManager::IsNetworkAvailable(v1);
}

// File Line: 20
// RVA: 0x42F900
void __fastcall UFG::OnlineManager::RegisterObserver(UFG::OnlineManager *this, UFG::OnlineManagerObserver *p)
{
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v2; // rax
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v3; // rdx
  UFG::qList<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver,1,0> *v4; // rcx

  v2 = this->m_lObservers.mNode.mNext;
  v3 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&p->mPrev;
  v4 = &this->m_lObservers;
  v4->mNode.mNext = v3;
  v3->mNext = v2;
  v3->mPrev = &v4->mNode;
  v2->mPrev = v3;
}

// File Line: 32
// RVA: 0x431640
void __fastcall UFG::OnlineManager::UpdateObservers(UFG::OnlineManager *this)
{
  UFG::OnlineManager *v1; // rdi
  bool v2; // si
  bool *j; // rbx
  bool *i; // rbx

  v1 = this;
  v2 = (unsigned __int8)UFG::OnlineManager::IsNetworkAvailable(this)
    && (unsigned __int8)UFG::OnlineManager::IsNetworkAvailable(v1);
  if ( v1->m_bSignedIn )
  {
    if ( !v2 )
    {
      for ( i = (bool *)&v1->m_lObservers.mNode.mNext[-1].mNext;
            i != &v1->m_bInitialized;
            i = (bool *)(*((_QWORD *)i + 2) - 8i64) )
      {
        (*(void (__fastcall **)(bool *))(*(_QWORD *)i + 16i64))(i);
      }
    }
  }
  else if ( v2 )
  {
    for ( j = (bool *)&v1->m_lObservers.mNode.mNext[-1].mNext;
          j != &v1->m_bInitialized;
          j = (bool *)(*((_QWORD *)j + 2) - 8i64) )
    {
      (*(void (__fastcall **)(bool *))(*(_QWORD *)j + 8i64))(j);
    }
  }
  v1->m_bSignedIn = v2;
}

