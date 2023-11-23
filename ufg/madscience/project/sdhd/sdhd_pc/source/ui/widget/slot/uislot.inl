// File Line: 24
// RVA: 0x5CE490
void __fastcall UFG::UISlot::~UISlot(UFG::UISlot *this)
{
  UFG::qNode<UFG::UISlot,UFG::UISlot> *mPrev; // rcx
  UFG::qNode<UFG::UISlot,UFG::UISlot> *mNext; // rax

  this->vfptr = (UFG::UISlotVtbl *)&UFG::UISlot::`vftable;
  UFG::qString::~qString(&this->m_pathToSlot);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::UISlot,UFG::UISlot>;
  this->mNext = &this->UFG::qNode<UFG::UISlot,UFG::UISlot>;
}

// File Line: 53
// RVA: 0x641740
void __fastcall UFG::UISlot::update(UFG::UISlot *this, UFG::UIItem *item)
{
  this->m_item = item;
}

