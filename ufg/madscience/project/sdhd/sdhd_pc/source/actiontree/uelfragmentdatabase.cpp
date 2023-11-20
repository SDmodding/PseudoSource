// File Line: 32
// RVA: 0x29EF80
void __fastcall UELNode::~UELNode(UELNode *this)
{
  ActionNode *v1; // rbx
  __int64 v2; // rax
  __int64 v3; // rax
  BinPtrArray<ActionNode,0,0> *v4; // rcx
  char *v5; // rcx

  v1 = (ActionNode *)this;
  this->vfptr = (Expression::IMemberMapVtbl *)&UELNode::`vftable;
  v2 = this->mParent.mOffset;
  if ( v2 && (UFG::qOffset64<UELGroupNode *> *)((char *)&this->mParent + v2) )
  {
    v3 = this->mParent.mOffset;
    if ( v3 )
      v4 = (BinPtrArray<ActionNode,0,0> *)((char *)&this->mParent + v3);
    else
      v4 = 0i64;
    BinPtrArray<UELNode,0,0>::Remove(v4 + 2, v1);
    v1->mFirstCallback = 0i64;
    v1->mFirstCallback = 0i64;
  }
  if ( !(~LOBYTE(v1->mParent.mOffset) & 1) )
  {
    if ( v1->mParent.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v5 = (char *)&v1->mParent + (v1->mParent.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v5 != BinString::sEmptyString )
        operator delete[](v5);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 55
// RVA: 0x1494100
__int64 dynamic_initializer_for__UELFragmentNode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UELFragmentNode", 0xFFFFFFFF);
  UELFragmentNode::sClassNameUID = result;
  return result;
}

// File Line: 65
// RVA: 0x298D20
void __fastcall UELFragmentNode::UELFragmentNode(UELFragmentNode *this)
{
  UELFragmentNode *v1; // rbx
  BinString *v2; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&UELNode::`vftable;
  v2 = &this->mHeader;
  v2->mOffset = 1i64;
  BinString::Set(v2, &customWorldMapCaption);
  v1->mParent.mOffset = 0i64;
  v1->vfptr = (Expression::IMemberMapVtbl *)&UELFragmentNode::`vftable;
  v1->mBody.mOffset = 1i64;
  BinString::Set(&v1->mBody, &customWorldMapCaption);
  v1->mFragmentExpression.mOffset = 0i64;
}

// File Line: 69
// RVA: 0x29EEE0
void __fastcall UELFragmentNode::~UELFragmentNode(UELFragmentNode *this)
{
  UELFragmentNode *v1; // rbx
  __int64 v2; // rax
  __int64 v3; // rax
  char *v4; // rdi
  char *v5; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&UELFragmentNode::`vftable;
  v2 = this->mFragmentExpression.mOffset;
  if ( v2 && (UFG::qOffset64<UEL::FragmentExpression *> *)((char *)&this->mFragmentExpression + v2) )
  {
    v3 = this->mFragmentExpression.mOffset;
    if ( v3 )
    {
      v4 = (char *)&this->mFragmentExpression + v3;
      if ( v4 )
      {
        UEL::FragmentExpression::~FragmentExpression((UEL::FragmentExpression *)((char *)&this->mFragmentExpression + v3));
        operator delete[](v4);
      }
    }
    v1->mFragmentExpression.mOffset = 0i64;
  }
  if ( !(~LOBYTE(v1->mBody.mOffset) & 1) )
  {
    if ( v1->mBody.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v5 = (char *)&v1->mBody + (v1->mBody.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v5 != BinString::sEmptyString )
        operator delete[](v5);
    }
  }
  UELNode::~UELNode((UELNode *)&v1->vfptr);
}

// File Line: 120
// RVA: 0x1494A20
const char *dynamic_initializer_for__sUELGroupNodeList__()
{
  const char *result; // rax

  sUELGroupNodeList[0].mClassName = UELGroupNode::sClassName;
  result = UELFragmentNode::sClassName;
  sUELGroupNodeList[1].mClassName = UELFragmentNode::sClassName;
  return result;
}

// File Line: 125
// RVA: 0x1494470
__int64 dynamic_initializer_for__gUELGroupNodeFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(&gUELGroupNodeFactory, sUELGroupNodeList, sUELGroupNodeListNum);
  return atexit(dynamic_atexit_destructor_for__gUELGroupNodeFactory__);
}

// File Line: 127
// RVA: 0x1494140
__int64 dynamic_initializer_for__UELGroupNode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UELGroupNode", 0xFFFFFFFF);
  UELGroupNode::sClassNameUID = result;
  return result;
}

// File Line: 135
// RVA: 0x298DB0
void __fastcall UELGroupNode::UELGroupNode(UELGroupNode *this)
{
  UELGroupNode *v1; // rbx
  BinString *v2; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->vfptr = (Expression::IMemberMapVtbl *)&UELNode::`vftable;
  v2 = &this->mHeader;
  v2->mOffset = 1i64;
  BinString::Set(v2, &customWorldMapCaption);
  v1->mParent.mOffset = 0i64;
  v1->vfptr = (Expression::IMemberMapVtbl *)&UELGroupNode::`vftable;
  v1->mChildren.mCount = 0;
  v1->mChildren.mData.mOffset = 0i64;
}

// File Line: 187
// RVA: 0x2DC940
void __fastcall ConditionGroup::Serialize(ConditionGroup *this, IActionTreeSerializer *serializer)
{
  IActionTreeSerializer *v2; // r15
  ConditionGroup *v3; // rsi
  unsigned int v4; // ebx
  char *v5; // r14
  char *v6; // rcx
  char *v7; // rdi
  __int64 v8; // rax
  __int64 v9; // [rsp+28h] [rbp-40h]
  __int64 v10; // [rsp+30h] [rbp-38h]
  __int64 v11; // [rsp+40h] [rbp-28h]

  v2 = serializer;
  v3 = this;
  v4 = 0;
  v5 = (char *)&this->mConditions.mData + this->mConditions.mData.mOffset;
  if ( this->mConditions.mCount & 0x7FFFFFFF )
  {
    do
    {
      v6 = &v5[8 * v4];
      v7 = &v6[*(_QWORD *)v6];
      if ( v7 )
      {
        v8 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v7 + 32i64))(&v6[*(_QWORD *)v6]);
        LODWORD(v11) = -1;
        LODWORD(v10) = 0;
        LODWORD(v9) = 1;
        v2->vfptr->_PushObjectToSerialize(
          v2,
          v7,
          1u,
          (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
          (const char *)v8,
          (QUEUE_PRIORITY)v9,
          v10,
          0i64,
          v11,
          0i64);
      }
      ++v4;
    }
    while ( v4 < (v3->mConditions.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 207
// RVA: 0x14940C0
__int64 dynamic_initializer_for__UELFileNode::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UELFileNode", 0xFFFFFFFF);
  UELFileNode::sClassNameUID = result;
  return result;
}

// File Line: 295
// RVA: 0x1494120
__int64 dynamic_initializer_for__UELFragmentTable::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UELFragmentTable", 0xFFFFFFFF);
  UELFragmentTable::sClassNameUID = result;
  return result;
}

// File Line: 319
// RVA: 0x1494A10
const char *dynamic_initializer_for__sUELFragmentDatabaseList__()
{
  const char *result; // rax

  result = UELFragmentTable::sClassName;
  sUELFragmentDatabaseList[0].mClassName = UELFragmentTable::sClassName;
  return result;
}

// File Line: 324
// RVA: 0x14943E0
__int64 dynamic_initializer_for__gUELFragmentDatabaseFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gUELFragmentDatabaseFactory,
    sUELFragmentDatabaseList,
    sUELFragmentDatabaseListNum);
  return atexit(dynamic_atexit_destructor_for__gUELFragmentDatabaseFactory__);
}

// File Line: 326
// RVA: 0x14940E0
__int64 dynamic_initializer_for__UELFragmentDatabase::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("UELFragmentDatabase", 0xFFFFFFFF);
  UELFragmentDatabase::sClassNameUID = result;
  return result;
}

// File Line: 331
// RVA: 0x2DC4F0
void UELFragmentDatabase::Quit(void)
{
  UELFragmentDatabase::msUELFragmentDatabase = 0i64;
}

