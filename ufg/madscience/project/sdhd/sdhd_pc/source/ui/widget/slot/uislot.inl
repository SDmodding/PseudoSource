// File Line: 24
// RVA: 0x5CE490
void __fastcall UFG::UISlot::~UISlot(UFG::UISlot *this)
{
  UFG::UISlot *v1; // rbx
  UFG::qNode<UFG::UISlot,UFG::UISlot> *v2; // rdx
  UFG::qNode<UFG::UISlot,UFG::UISlot> *v3; // rcx
  UFG::qNode<UFG::UISlot,UFG::UISlot> *v4; // rax

  v1 = this;
  this->vfptr = (UFG::UISlotVtbl *)&UFG::UISlot::`vftable';
  UFG::qString::~qString(&this->m_pathToSlot);
  v2 = (UFG::qNode<UFG::UISlot,UFG::UISlot> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
}

// File Line: 53
// RVA: 0x641740
void __fastcall UFG::UISlot::update(UFG::UISlot *this, UFG::UIItem *item)
{
  this->m_item = item;
}

