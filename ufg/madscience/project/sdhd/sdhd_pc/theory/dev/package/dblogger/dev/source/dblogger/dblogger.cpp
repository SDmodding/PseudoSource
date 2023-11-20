// File Line: 13
// RVA: 0x151280
void __fastcall UFG::NameValueColumnType::~NameValueColumnType(UFG::NameValueColumnType *this)
{
  UFG::NameValueColumnType *v1; // rbx
  UFG::ColumnType v2; // eax
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v3; // rcx
  UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *v4; // rax

  v1 = this;
  v2 = this->mColumnType;
  if ( v2 == 3 || (unsigned int)(v2 - 7) <= 3 )
    operator delete[](this->mColumnValue.mString);
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v1->mPrev = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::NameValueColumnType,UFG::NameValueColumnType> *)&v1->mPrev;
}

