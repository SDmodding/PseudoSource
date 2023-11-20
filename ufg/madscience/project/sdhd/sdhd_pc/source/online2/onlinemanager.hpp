// File Line: 26
// RVA: 0x429360
void __fastcall UFG::OnlineManagerObserver::~OnlineManagerObserver(UFG::OnlineManagerObserver *this)
{
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v1; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v2; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v3; // rax

  this->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable';
  v1 = (UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 74
// RVA: 0x5E8B00
UFG::qString *__fastcall UFG::OnlineManager::GetRetreivedDisplayImage(UFG::OnlineManager *this, UFG::qString *result)
{
  UFG::qString *v2; // rbx

  v2 = result;
  UFG::qString::qString(result, &this->mRetreivedDisplayImage);
  return v2;
}

