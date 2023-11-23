// File Line: 161
// RVA: 0x22F610
void __fastcall UFG::Event::Event(UFG::Event *this, const char *name)
{
  this->mPrev = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->mNext = &this->UFG::qNode<UFG::Event,UFG::Event>;
  this->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable;
  this->m_NamePTR = name;
  this->m_EventUID = UFG::qStringHash32(name, 0xFFFFFFFF);
}

