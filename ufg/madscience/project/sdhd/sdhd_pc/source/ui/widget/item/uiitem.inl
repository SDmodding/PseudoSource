// File Line: 21
// RVA: 0x5CDF60
void __fastcall UFG::UIItem::~UIItem(UFG::UIItem *this)
{
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v1; // rdx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *mPrev; // rcx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *mNext; // rax

  this->vfptr = (UFG::UIItemVtbl *)&UFG::UIItem::`vftable;
  v1 = &this->UFG::qNode<UFG::UIItem,UFG::UIItem>;
  mPrev = this->mPrev;
  mNext = v1->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
}

