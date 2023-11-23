// File Line: 65
// RVA: 0x254100
void __fastcall UFG::CookieJar::~CookieJar(UFG::CookieJar *this)
{
  UFG::qNode<UFG::DomainContainer,UFG::DomainContainer> *mPrev; // rdx
  UFG::qNode<UFG::DomainContainer,UFG::DomainContainer> *mNext; // rax

  UFG::qList<UFG::DomainContainer,UFG::DomainContainer,1,0>::DeleteNodes(&this->mDomainList);
  mPrev = this->mDomainList.mNode.mPrev;
  mNext = this->mDomainList.mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mDomainList.mNode.mPrev = &this->mDomainList.mNode;
  this->mDomainList.mNode.mNext = &this->mDomainList.mNode;
}

