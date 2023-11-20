// File Line: 31
// RVA: 0x5C9130
void __fastcall UFG::DialogPopupEntry::~DialogPopupEntry(UFG::DialogPopupEntry *this)
{
  UFG::DialogPopupEntry *v1; // rbx
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *v2; // rdx
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *v3; // rcx
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *v4; // rax

  v1 = this;
  this->vfptr = (UFG::DialogPopupEntryVtbl *)&UFG::DialogPopupEntry::`vftable';
  UFG::qString::~qString(&this->mName);
  v2 = (UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
}

