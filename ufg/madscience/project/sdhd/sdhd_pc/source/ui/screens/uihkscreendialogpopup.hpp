// File Line: 31
// RVA: 0x5C9130
void __fastcall UFG::DialogPopupEntry::~DialogPopupEntry(UFG::DialogPopupEntry *this)
{
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *mPrev; // rcx
  UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry> *mNext; // rax

  this->vfptr = (UFG::DialogPopupEntryVtbl *)&UFG::DialogPopupEntry::`vftable;
  UFG::qString::~qString(&this->mName);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry>;
  this->mNext = &this->UFG::qNode<UFG::DialogPopupEntry,UFG::DialogPopupEntry>;
}

