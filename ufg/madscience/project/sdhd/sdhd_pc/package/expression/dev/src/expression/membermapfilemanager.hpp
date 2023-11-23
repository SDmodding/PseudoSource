// File Line: 48
// RVA: 0x152900
void __fastcall MemberMapFileNode::SetName(MemberMapFileNode *this, const char *name)
{
  UFG::qString::Set(&this->mName, name);
}

// File Line: 86
// RVA: 0x152340
const char *__fastcall MemberMapFileObject::GetClassname(MemberMapFileObject *this)
{
  return MemberMapFileObject::sClassName;
}

// File Line: 183
// RVA: 0x152190
MemberMapFileDependent *__fastcall MemberMapFileDependent::Create()
{
  MemberMapFileObject *v0; // rax
  MemberMapFileObject *v1; // rbx

  v0 = (MemberMapFileObject *)UFG::qMemoryPool2::Allocate(
                                &gActionTreeMemoryPool,
                                0xF0ui64,
                                "MemberMap::MemberMapFileDependent",
                                0i64,
                                1u);
  v1 = v0;
  if ( !v0 )
    return 0i64;
  MemberMapFileObject::MemberMapFileObject(v0);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileDependent::`vftable;
  return (MemberMapFileDependent *)v1;
}

// File Line: 203
// RVA: 0x1522D0
__int64 __fastcall MemberMapFileGroup::GetClassNameUID(MemberMapFileGroup *this)
{
  return MemberMapFileGroup::sClassNameUID;
}

// File Line: 229
// RVA: 0x152300
__int64 __fastcall MemberMapFileProject::GetClassNameUID(MemberMapFileProject *this)
{
  return MemberMapFileProject::sClassNameUID;
}

// File Line: 284
// RVA: 0x152330
const char *__fastcall MemberMapFileManager::GetClassname(MemberMapFileManager *this)
{
  return MemberMapFileManager::sClassName;
}

// File Line: 290
// RVA: 0x152360
MemberMapFileManager *__fastcall MemberMapFileManager::GetDataBaseRoot()
{
  return MemberMapFileManager::sMemberMapFileManager;
}

// File Line: 357
// RVA: 0x152B50
void __fastcall MemberMapFileNodeVisitor::Visit(Json::DefaultValueAllocator *this, char *memberName)
{
  this->vfptr->releaseStringValue(this, memberName);
}

