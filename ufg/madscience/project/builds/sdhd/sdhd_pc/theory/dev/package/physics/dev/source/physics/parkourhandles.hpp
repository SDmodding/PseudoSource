// File Line: 272
// RVA: 0x3399D0
void __fastcall UFG::ParkourQuery::~ParkourQuery(UFG::ParkourQuery *this)
{
  UFG::ParkourQuery *v1; // rdi
  UFG::qSafePointer<UFG::ParkourHandle,UFG::ParkourHandle> *v2; // rcx
  UFG::ParkourHandle **v3; // rbx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v4; // rcx
  UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *v5; // rax

  v1 = this;
  v2 = this->handlesOut.p;
  if ( v2 )
  {
    v3 = &v2[-1].m_pPointer;
    `eh vector destructor iterator'(
      v2,
      0x18ui64,
      (int)v2[-1].m_pPointer,
      (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
    operator delete[](v3);
  }
  v1->handlesOut.p = 0i64;
  *(_QWORD *)&v1->handlesOut.size = 0i64;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::ParkourQuery,UFG::ParkourQuery> *)&v1->mPrev;
}

