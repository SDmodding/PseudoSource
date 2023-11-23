// File Line: 272
// RVA: 0x3399D0
void __fastcall UFG::ParkourQuery::~ParkourQuery(UFG::ParkourQuery *this)
{
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *p; // rcx
  UFG::ParkourHandle **p_m_pPointer; // rbx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *mPrev; // rcx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *mNext; // rax

  p = this->handlesOut.p;
  if ( p )
  {
    p_m_pPointer = &p[-1].m_pPointer;
    `eh vector destructor iterator(
      p,
      0x18ui64,
      (int)p[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](p_m_pPointer);
  }
  this->handlesOut.p = 0i64;
  *(_QWORD *)&this->handlesOut.size = 0i64;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

