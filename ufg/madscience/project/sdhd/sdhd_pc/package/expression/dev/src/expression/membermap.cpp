// File Line: 206
// RVA: 0x1466840
__int64 dynamic_initializer_for__Expression::IMemberMap::smFileHandlers__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Expression::IMemberMap::smFileHandlers__);
}

// File Line: 212
// RVA: 0x1519D0
void __fastcall Expression::MemberMapFactory::MemberMapFactory(
        Expression::MemberMapFactory *this,
        Expression::IMemberMapConstuctionEntry *factoryList,
        int factoryListSize)
{
  UFG::qList<Expression::MemberMapFactory,Expression::MemberMapFactory,1,0> *v4; // rdx
  char *v5; // rax
  UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *mPrev; // rax

  this->mPrev = this;
  this->mNext = this;
  this->mFactoryList = factoryList;
  this->mFactoryListSize = factoryListSize;
  v4 = Expression::MemberMapFactory::smMemberMapFactories;
  if ( !Expression::MemberMapFactory::smMemberMapFactories )
  {
    v5 = UFG::qMalloc(0x10ui64, UFG::gGlobalNewName, 0i64);
    v4 = (UFG::qList<Expression::MemberMapFactory,Expression::MemberMapFactory,1,0> *)v5;
    if ( v5 )
    {
      *(_QWORD *)v5 = v5;
      *((_QWORD *)v5 + 1) = v5;
    }
    else
    {
      v4 = 0i64;
    }
    Expression::MemberMapFactory::smMemberMapFactories = v4;
  }
  mPrev = v4->mNode.mPrev;
  mPrev->mNext = this;
  this->mPrev = mPrev;
  this->mNext = &v4->mNode;
  v4->mNode.mPrev = this;
}

// File Line: 221
// RVA: 0x151A50
void __fastcall Expression::MemberMapFactory::~MemberMapFactory(Expression::MemberMapFactory *this)
{
  UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *mPrev; // rdx
  UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *mNext; // rax
  UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *v4; // rcx
  UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *v5; // rax

  if ( Expression::MemberMapFactory::smMemberMapFactories )
  {
    mPrev = this->mPrev;
    mNext = this->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    this->mPrev = this;
    this->mNext = this;
  }
  v4 = this->mPrev;
  v5 = this->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  this->mPrev = this;
  this->mNext = this;
}

// File Line: 965
// RVA: 0x151AA0
void __fastcall Expression::IMemberMap::GetResourcePath(Expression::IMemberMap *this, char *path, int pathSize)
{
  const char *v5; // rax

  v5 = this->vfptr->GetClassname(this);
  UFG::qSPrintf(path, pathSize, v5);
}

