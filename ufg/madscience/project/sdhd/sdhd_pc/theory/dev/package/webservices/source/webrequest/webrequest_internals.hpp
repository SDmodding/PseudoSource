// File Line: 65
// RVA: 0x254100
void __fastcall UFG::CookieJar::~CookieJar(UFG::CookieJar *this)
{
  UFG::CookieJar *v1; // rbx
  UFG::qNode<UFG::DomainContainer,UFG::DomainContainer> *v2; // rdx
  UFG::qNode<UFG::DomainContainer,UFG::DomainContainer> *v3; // rax

  v1 = this;
  UFG::qList<UFG::DomainContainer,UFG::DomainContainer,1,0>::DeleteNodes(&this->mDomainList);
  v2 = v1->mDomainList.mNode.mPrev;
  v3 = v1->mDomainList.mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mDomainList.mNode.mPrev = &v1->mDomainList.mNode;
  v1->mDomainList.mNode.mNext = &v1->mDomainList.mNode;
}

