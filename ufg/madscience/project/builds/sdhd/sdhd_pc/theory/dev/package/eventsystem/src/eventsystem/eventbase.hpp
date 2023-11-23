// File Line: 162
// RVA: 0x9C3B0
void __fastcall UFG::Event::~Event(UFG::Event *this)
{
  UFG::qNode<UFG::Event,UFG::Event> *v1; // rdx
  UFG::qNode<UFG::Event,UFG::Event> *mPrev; // rcx
  UFG::qNode<UFG::Event,UFG::Event> *mNext; // rax

  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  v1 = &this->UFG::qNode<UFG::Event,UFG::Event>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

