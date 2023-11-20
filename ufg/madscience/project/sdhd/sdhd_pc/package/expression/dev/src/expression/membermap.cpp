// File Line: 206
// RVA: 0x1466840
__int64 dynamic_initializer_for__Expression::IMemberMap::smFileHandlers__()
{
  return atexit(dynamic_atexit_destructor_for__Expression::IMemberMap::smFileHandlers__);
}

// File Line: 212
// RVA: 0x1519D0
void __fastcall Expression::MemberMapFactory::MemberMapFactory(Expression::MemberMapFactory *this, Expression::IMemberMapConstuctionEntry *factoryList, int factoryListSize)
{
  Expression::MemberMapFactory *v3; // rbx
  UFG::qList<Expression::MemberMapFactory,Expression::MemberMapFactory,1,0> *v4; // rdx
  char *v5; // rax
  UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *v6; // rax

  v3 = this;
  this->mPrev = (UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *)&this->mPrev;
  this->mNext = (UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *)&this->mPrev;
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
  v6 = v4->mNode.mPrev;
  v6->mNext = (UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *)&v3->mPrev;
  v3->mPrev = v6;
  v3->mNext = &v4->mNode;
  v4->mNode.mPrev = (UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *)&v3->mPrev;
}

// File Line: 221
// RVA: 0x151A50
void __fastcall Expression::MemberMapFactory::~MemberMapFactory(Expression::MemberMapFactory *this)
{
  Expression::MemberMapFactory *v1; // r8
  UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *v2; // rdx
  UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *v3; // rax
  UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *v4; // rcx
  UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *v5; // rax

  v1 = this;
  if ( Expression::MemberMapFactory::smMemberMapFactories )
  {
    v2 = this->mPrev;
    v3 = this->mNext;
    v2->mNext = v3;
    v3->mPrev = v2;
    this->mPrev = (UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *)&this->mPrev;
    this->mNext = (UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *)&this->mPrev;
  }
  v4 = this->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<Expression::MemberMapFactory,Expression::MemberMapFactory> *)&v1->mPrev;
}

// File Line: 965
// RVA: 0x151AA0
void __fastcall Expression::IMemberMap::GetResourcePath(Expression::IMemberMap *this, char *path, int pathSize)
{
  int v3; // ebx
  char *v4; // rdi
  const char *v5; // rax

  v3 = pathSize;
  v4 = path;
  v5 = (const char *)((__int64 (*)(void))this->vfptr->GetClassname)();
  UFG::qSPrintf(v4, v3, v5);
}

