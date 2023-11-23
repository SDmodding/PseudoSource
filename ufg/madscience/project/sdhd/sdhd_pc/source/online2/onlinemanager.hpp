// File Line: 26
// RVA: 0x429360
void __fastcall UFG::OnlineManagerObserver::~OnlineManagerObserver(UFG::OnlineManagerObserver *this)
{
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *v1; // rdx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mPrev; // rcx
  UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver> *mNext; // rax

  this->vfptr = (UFG::OnlineManagerObserverVtbl *)&UFG::OnlineManagerObserver::`vftable;
  v1 = &this->UFG::qNode<UFG::OnlineManagerObserver,UFG::OnlineManagerObserver>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

// File Line: 74
// RVA: 0x5E8B00
UFG::qString *__fastcall UFG::OnlineManager::GetRetreivedDisplayImage(UFG::OnlineManager *this, UFG::qString *result)
{
  UFG::qString::qString(result, &this->mRetreivedDisplayImage);
  return result;
}

