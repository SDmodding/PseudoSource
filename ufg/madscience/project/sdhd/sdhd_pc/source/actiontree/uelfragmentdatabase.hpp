// File Line: 53
// RVA: 0x2AF670
void __fastcall UELFragmentNode::Create()
{
  char *v0; // rax

  v0 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x30ui64, "MemberMap::UELFragmentNode", 0i64, 1u);
  if ( v0 )
    UELFragmentNode::UELFragmentNode((UELFragmentNode *)v0);
}

// File Line: 73
// RVA: 0x2C2AF0
const char *__fastcall UELGroupNode::GetClassname(UELGroupNode *this)
{
  return UELGroupNode::sClassName;
}

// File Line: 127
// RVA: 0x2AF6C0
UELFragmentTable *__fastcall UELFragmentTable::Create()
{
  UELFragmentTable *result; // rax

  result = (UELFragmentTable *)UFG::qMemoryPool2::Allocate(
                                 &gActionTreeMemoryPool,
                                 0x20ui64,
                                 "MemberMap::UELFragmentTable",
                                 0i64,
                                 1u);
  if ( !result )
    return 0i64;
  result->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  result->mResourceOwner = 0i64;
  result->vfptr = (Expression::IMemberMapVtbl *)&UELFragmentTable::`vftable;
  result->mFragmentTable.mCount = 0;
  result->mFragmentTable.mData.mOffset = 0i64;
  return result;
}

