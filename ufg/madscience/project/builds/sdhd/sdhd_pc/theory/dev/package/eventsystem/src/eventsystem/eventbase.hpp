// File Line: 162
// RVA: 0x9C3B0
void __fastcall UFG::Event::~Event(UFG::Event *this)
{
  UFG::qNode<UFG::Event,UFG::Event> *v1; // rdx
  UFG::qNode<UFG::Event,UFG::Event> *v2; // rcx
  UFG::qNode<UFG::Event,UFG::Event> *v3; // rax

  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  v1 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

