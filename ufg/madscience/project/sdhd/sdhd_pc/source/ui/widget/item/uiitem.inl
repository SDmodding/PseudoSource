// File Line: 21
// RVA: 0x5CDF60
void __fastcall UFG::UIItem::~UIItem(UFG::UIItem *this)
{
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v1; // rdx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v2; // rcx
  UFG::qNode<UFG::UIItem,UFG::UIItem> *v3; // rax

  this->vfptr = (UFG::UIItemVtbl *)&UFG::UIItem::`vftable';
  v1 = (UFG::qNode<UFG::UIItem,UFG::UIItem> *)&this->mPrev;
  v2 = this->mPrev;
  v3 = v1->mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mPrev = v1;
  v1->mNext = v1;
}

