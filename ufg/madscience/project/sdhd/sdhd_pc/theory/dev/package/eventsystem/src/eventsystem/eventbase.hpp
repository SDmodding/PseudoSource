// File Line: 161
// RVA: 0x22F610
void __fastcall UFG::Event::Event(UFG::Event *this, const char *name)
{
  UFG::qNode<UFG::Event,UFG::Event> *v2; // rax

  v2 = (UFG::qNode<UFG::Event,UFG::Event> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
  this->m_NamePTR = name;
  this->m_EventUID = UFG::qStringHash32(name, 0xFFFFFFFF);
}

