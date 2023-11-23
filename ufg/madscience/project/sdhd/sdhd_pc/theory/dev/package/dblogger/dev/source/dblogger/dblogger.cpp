// File Line: 13
// RVA: 0x151280
void __fastcall UFG::NameValueColumnType::~NameValueColumnType(UFG::NameValueColumnType *this)
{
  UFG::ColumnType mColumnType; // eax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *mPrev; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *mNext; // rax

  mColumnType = this->mColumnType;
  if ( mColumnType == DateTime || (unsigned int)(mColumnType - 7) <= 3 )
    operator delete[](this->mColumnValue.mString);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

