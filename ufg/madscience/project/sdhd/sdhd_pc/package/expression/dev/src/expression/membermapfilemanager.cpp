// File Line: 33
// RVA: 0x151B60
void __fastcall MemberMapFileNode::MemberMapFileNode(MemberMapFileNode *this)
{
  MemberMapFileNode *v1; // rbx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v2; // rax
  UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
  this->mResourceOwner = 0i64;
  v2 = (UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileNode::`vftable';
  UFG::qString::qString(&this->mName);
  v3 = &v1->mChildren;
  v3->mNode.mPrev = &v3->mNode;
  v3->mNode.mNext = &v3->mNode;
  v1->mMemberMapFileProject = 0i64;
}

// File Line: 37
// RVA: 0x151DC0
void __fastcall MemberMapFileNode::~MemberMapFileNode(MemberMapFileNode *this)
{
  MemberMapFileNode *v1; // rbx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v2; // rdx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v3; // rcx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v4; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileNode::`vftable';
  UFG::qList<UFG::qTask,UFG::TaskPlat,0,0>::~qList<UFG::qTask,UFG::TaskPlat,0,0>(&this->mChildren);
  UFG::qString::~qString(&v1->mName);
  v2 = (UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 90
// RVA: 0x152370
void __fastcall MemberMapFileNode::GetResourcePath(MemberMapFileNode *this, char *path, int pathSize)
{
  int v3; // esi
  char *v4; // rbp
  MemberMapFileNode *v5; // rax
  signed int v6; // edi
  signed __int64 v7; // rbx
  int v8; // eax
  __int64 v9; // rdi
  __int64 v10; // rbx
  const char *v11; // rax
  UFG::qString v12; // [rsp+20h] [rbp-138h]
  __int64 v13; // [rsp+48h] [rbp-110h]
  __int64 v14[32]; // [rsp+50h] [rbp-108h]

  v13 = -2i64;
  v3 = pathSize;
  v4 = path;
  v5 = this;
  v6 = 0;
  v7 = 0i64;
  do
  {
    if ( !v5 )
      break;
    v14[v7] = (__int64)v5;
    ++v6;
    ++v7;
    v5 = (MemberMapFileNode *)v5->vfptr->GetResourceOwner((Expression::IMemberMap *)&v5->vfptr);
  }
  while ( v7 < 32 );
  UFG::qString::qString(&v12, "Global");
  if ( v6 > 2 )
  {
    v8 = v6 - 2;
    v9 = v6 - 2;
    if ( v8 >= 0 )
    {
      do
      {
        v10 = v14[v9];
        UFG::qString::operator+=(&v12, "\\");
        v11 = (const char *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 96i64))(v10);
        UFG::qString::operator+=(&v12, v11);
        --v9;
      }
      while ( v9 >= 0 );
    }
  }
  UFG::qSPrintf(v4, v3, v12.mData);
  UFG::qString::~qString(&v12);
}

// File Line: 128
// RVA: 0x14669C0
const char *dynamic_initializer_for__sMemberMapFileObjectList__()
{
  const char *result; // rax

  sMemberMapFileObjectList[0].mClassName = MemberMapFileObject::sClassName;
  result = MemberMapFileDependent::sClassName;
  sMemberMapFileObjectList[1].mClassName = MemberMapFileDependent::sClassName;
  return result;
}

// File Line: 134
// RVA: 0x1466960
__int64 dynamic_initializer_for__gMemberMapFileObjectFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gMemberMapFileObjectFactory,
    sMemberMapFileObjectList,
    sMemberMapFileObjectListNum);
  return atexit(dynamic_atexit_destructor_for__gMemberMapFileObjectFactory__);
}

// File Line: 136
// RVA: 0x14668C0
__int64 dynamic_initializer_for__MemberMapFileObject::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MemberMapFileObject", 0xFFFFFFFF);
  MemberMapFileObject::sClassNameUID = result;
  return result;
}

// File Line: 150
// RVA: 0x151BD0
void __fastcall MemberMapFileObject::MemberMapFileObject(MemberMapFileObject *this)
{
  MemberMapFileObject *v1; // rbx

  v1 = this;
  MemberMapFileNode::MemberMapFileNode((MemberMapFileNode *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileObject::`vftable';
  v1->mFileTime = 0i64;
  UFG::qString::qString(&v1->mRelativeFilePath);
  UFG::qString::qString(&v1->mAbsoluteFilePath);
  v1->mMemberMapResource = 0i64;
  UFG::qString::qString(&v1->mResourcePath);
  *(_WORD *)&v1->mModified = 0;
}

// File Line: 154
// RVA: 0x151E20
void __fastcall MemberMapFileObject::~MemberMapFileObject(MemberMapFileObject *this)
{
  MemberMapFileObject *v1; // rbx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v2; // rdx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v3; // rcx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v4; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileObject::`vftable';
  UFG::qString::~qString(&this->mResourcePath);
  UFG::qString::~qString(&v1->mAbsoluteFilePath);
  UFG::qString::~qString(&v1->mRelativeFilePath);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileNode::`vftable';
  UFG::qList<UFG::qTask,UFG::TaskPlat,0,0>::~qList<UFG::qTask,UFG::TaskPlat,0,0>(&v1->mChildren);
  UFG::qString::~qString(&v1->mName);
  v2 = (UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 204
// RVA: 0x152920
void __fastcall MemberMapFileObject::UpdateDependentMembers(MemberMapFileObject *this)
{
  MemberMapFileObject *v1; // rbx
  char *v2; // rdx
  MemberMapFileProject *v3; // rdx
  UFG::qString *v4; // rax
  UFG::qString v5; // [rsp+30h] [rbp-88h]
  __int64 v6; // [rsp+58h] [rbp-60h]
  UFG::qString result; // [rsp+60h] [rbp-58h]
  UFG::qString v8; // [rsp+88h] [rbp-30h]

  v6 = -2i64;
  v1 = this;
  UFG::qString::qString(&v5);
  if ( v1->vfptr->GetClassNameUID((Expression::IMemberMap *)&v1->vfptr) == MemberMapFileProject::sClassNameUID )
  {
    v2 = MemberMapFileManager::sMemberMapFileManager->mStartupPath.mData;
  }
  else
  {
    v3 = v1->mMemberMapFileProject;
    if ( v3 )
      v2 = v3->mAbsoluteDataPath.mData;
    else
      v2 = MemberMapFileManager::sMemberMapFileManager->mActiveProject->mAbsoluteDataPath.mData;
  }
  UFG::qString::Set(&v5, v2);
  UFG::qMakeFullPath(&result, v5.mData, v1->mRelativeFilePath.mData);
  v4 = UFG::qString::GetFilename(&result, &v8);
  UFG::qString::Set(&v1->mName, v4->mData, v4->mLength, 0i64, 0);
  UFG::qString::~qString(&v8);
  UFG::qString::Set(&v1->mAbsoluteFilePath, result.mData);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v5);
}

// File Line: 330
// RVA: 0x152810
void __fastcall MemberMapFileObject::OnSubjectUpdate(MemberMapFileObject *this, const char *message)
{
  MemberMapFileObject *v2; // rbx

  v2 = this;
  if ( (!message || strcmp("ReadOnlyVarChange", message))
    && !v2->mIsLoading
    && !MemberMapFileProject::sLoadingFileObjects )
  {
    v2->mModified = 1;
  }
}

// File Line: 346
// RVA: 0x152800
void __fastcall MemberMapFileObject::OnSubjectDelete(MemberMapFileObject *this)
{
  this->mMemberMapResource = 0i64;
}

// File Line: 365
// RVA: 0x1466990
const char *dynamic_initializer_for__sMemberMapFileDependentList__()
{
  const char *result; // rax

  result = MemberMapFileDependent::sClassName;
  sMemberMapFileDependentList[0].mClassName = MemberMapFileDependent::sClassName;
  return result;
}

// File Line: 371
// RVA: 0x1466900
__int64 dynamic_initializer_for__gMemberMapFileDependentFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gMemberMapFileDependentFactory,
    sMemberMapFileDependentList,
    sMemberMapFileDependentListNum);
  return atexit(dynamic_atexit_destructor_for__gMemberMapFileDependentFactory__);
}

// File Line: 373
// RVA: 0x1466860
__int64 dynamic_initializer_for__MemberMapFileDependent::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MemberMapFileDependent", 0xFFFFFFFF);
  MemberMapFileDependent::sClassNameUID = result;
  return result;
}

// File Line: 408
// RVA: 0x14669A0
const char *dynamic_initializer_for__sMemberMapFileGroupList__()
{
  const char *result; // rax

  sMemberMapFileGroupList[0].mClassName = MemberMapFileGroup::sClassName;
  result = MemberMapFileObject::sClassName;
  sMemberMapFileGroupList[1].mClassName = MemberMapFileObject::sClassName;
  return result;
}

// File Line: 414
// RVA: 0x1466930
__int64 dynamic_initializer_for__gMemberMapFileGroupFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(
    &gMemberMapFileGroupFactory,
    sMemberMapFileGroupList,
    sMemberMapFileGroupListNum);
  return atexit(dynamic_atexit_destructor_for__gMemberMapFileGroupFactory__);
}

// File Line: 416
// RVA: 0x1466880
__int64 dynamic_initializer_for__MemberMapFileGroup::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MemberMapFileGroup", 0xFFFFFFFF);
  MemberMapFileGroup::sClassNameUID = result;
  return result;
}

// File Line: 427
// RVA: 0x151D50
void __fastcall MemberMapFileGroup::~MemberMapFileGroup(MemberMapFileGroup *this)
{
  MemberMapFileGroup *v1; // rbx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v2; // rdx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v3; // rcx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v4; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileGroup::`vftable';
  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileNode::`vftable';
  UFG::qList<UFG::qTask,UFG::TaskPlat,0,0>::~qList<UFG::qTask,UFG::TaskPlat,0,0>(&this->mChildren);
  UFG::qString::~qString(&v1->mName);
  v2 = (UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *)&v1->mPrev;
  v3 = v1->mPrev;
  v4 = v1->mNext;
  v3->mNext = v4;
  v4->mPrev = v3;
  v2->mPrev = v2;
  v2->mNext = v2;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

// File Line: 444
// RVA: 0x152180
void __fastcall ActionNodeFileReference::Accept(MemberMapFileGroup *this, MemberMapFileNodeVisitor *visitor)
{
  visitor->vfptr->Visit(visitor, this);
}

// File Line: 452
// RVA: 0x14668E0
__int64 dynamic_initializer_for__MemberMapFileProject::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MemberMapFileProject", 0xFFFFFFFF);
  MemberMapFileProject::sClassNameUID = result;
  return result;
}

// File Line: 464
// RVA: 0x151C40
void __fastcall MemberMapFileProject::MemberMapFileProject(MemberMapFileProject *this)
{
  MemberMapFileProject *v1; // rdi
  MemberMapFileManager *v2; // rbx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v3; // rcx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v4; // rax

  v1 = this;
  MemberMapFileObject::MemberMapFileObject((MemberMapFileObject *)&this->vfptr);
  v1->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileProject::`vftable';
  UFG::qString::qString(&v1->mRelativeDataPath);
  UFG::qString::qString(&v1->mAbsoluteDataPath);
  v1->mMemberMapResource = (Expression::IMemberMap *)&v1->vfptr;
  v2 = MemberMapFileManager::sMemberMapFileManager;
  MemberMapFileManager::sMemberMapFileManager->mActiveProject = v1;
  v1->vfptr->SetResourceOwner((Expression::IMemberMap *)&v1->vfptr, (Expression::IMemberMap *)&v2->vfptr);
  v3 = (UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *)&v1->mPrev;
  v4 = v2->mChildren.mNode.mPrev;
  v4->mNext = (UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *)&v1->mPrev;
  v3->mPrev = v4;
  v3->mNext = &v2->mChildren.mNode;
  v2->mChildren.mNode.mPrev = (UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *)&v1->mPrev;
}

// File Line: 477
// RVA: 0x152570
Expression::IMemberMap *__fastcall MemberMapFileProject::LoadMemberMapFileProject(const char *projectFileName)
{
  const char *v1; // rbx
  UFG::qString *v2; // rax
  void **v4; // [rsp+30h] [rbp-C8h]
  __int64 v5; // [rsp+38h] [rbp-C0h]
  __int64 v6; // [rsp+40h] [rbp-B8h]
  UFG::qString v7; // [rsp+48h] [rbp-B0h]
  UFG::qString result; // [rsp+70h] [rbp-88h]
  UFG::qString v9; // [rsp+98h] [rbp-60h]
  UFG::qString v10; // [rsp+C0h] [rbp-38h]
  void **v11; // [rsp+108h] [rbp+10h]

  v6 = -2i64;
  v1 = projectFileName;
  UFG::qString::qString(&v10);
  UFG::qMakeRelativePathFromDirToFile(&result, MemberMapFileManager::sMemberMapFileManager->mStartupPath.mData, v1);
  UFG::qString::Set((UFG::qString *)0x68, result.mData);
  MemberMapFileObject::UpdateDependentMembers(0i64);
  UFG::qString::Set((UFG::qString *)0xF0, MEMORY[0x108]);
  UFG::qString::GetFilePath((UFG::qString *)0x90, &v7);
  v2 = UFG::qMakeFullPath(&v9, v7.mData, MEMORY[0x108]);
  UFG::qString::Set((UFG::qString *)0x118, v2->mData, v2->mLength, 0i64, 0);
  UFG::qString::~qString(&v9);
  v11 = &MemberMapFileProjectResolveRelativePathsVisitor::`vftable';
  (*(void (__fastcall **)(_QWORD, void ***))(MEMORY[0] + 80))(0i64, &v11);
  UFG::qString::~qString(&v7);
  MemberMapFileProject::sLoadingFileObjects = 1;
  v4 = &MemberMapFileNodeLoadAllFileObjectsVisitor::`vftable';
  v5 = 0i64;
  (*(void (__fastcall **)(_QWORD, void ***))(MEMORY[0] + 80))(0i64, &v4);
  MemberMapFileProject::sLoadingFileObjects = 0;
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v10);
  return 0i64;
}

// File Line: 498
// RVA: 0x1526B0
Expression::IMemberMap *__fastcall MemberMapFileProject::NewMemberMapFileProject(const char *fileName, unsigned __int64 toolVersion)
{
  const char *v2; // rdi
  MemberMapFileProject *v3; // rax
  __int64 v4; // rax
  __int64 v5; // rbx
  UFG::qString *v6; // rax
  UFG::qString v8; // [rsp+38h] [rbp-80h]
  UFG::qString result; // [rsp+60h] [rbp-58h]
  UFG::qString v10; // [rsp+88h] [rbp-30h]
  void **v11; // [rsp+D0h] [rbp+18h]

  v2 = fileName;
  v3 = (MemberMapFileProject *)UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x140ui64, "IMemberMap", 0i64, 1u);
  v11 = (void **)&v3->vfptr;
  if ( v3 )
  {
    MemberMapFileProject::MemberMapFileProject(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::qMakeRelativePathFromDirToFile(&result, MemberMapFileManager::sMemberMapFileManager->mStartupPath.mData, v2);
  UFG::qString::Set((UFG::qString *)(v5 + 104), result.mData);
  MemberMapFileObject::UpdateDependentMembers((MemberMapFileObject *)v5);
  UFG::qString::Set((UFG::qString *)(v5 + 240), *(const char **)(v5 + 264));
  UFG::qString::GetFilePath((UFG::qString *)(v5 + 144), &v8);
  v6 = UFG::qMakeFullPath(&v10, v8.mData, *(const char **)(v5 + 264));
  UFG::qString::Set((UFG::qString *)(v5 + 280), v6->mData, v6->mLength, 0i64, 0);
  UFG::qString::~qString(&v10);
  v11 = &MemberMapFileProjectResolveRelativePathsVisitor::`vftable';
  (*(void (__fastcall **)(__int64, void ***))(*(_QWORD *)v5 + 80i64))(v5, &v11);
  UFG::qString::~qString(&v8);
  UFG::qString::~qString(&result);
  return (Expression::IMemberMap *)v5;
}

// File Line: 580
// RVA: 0x152BC0
void __fastcall MemberMapFileProjectResolveRelativePathsVisitor::Visit(MemberMapFileProjectResolveRelativePathsVisitor *this, MemberMapFileObject *memberMapFileObject)
{
  MemberMapFileProjectResolveRelativePathsVisitor *v2; // rsi
  MemberMapFileObject *v3; // rdi
  signed __int64 v4; // rdi
  __int64 v5; // rbx
  signed __int64 v6; // rdi
  _QWORD *i; // rbx

  v2 = this;
  v3 = memberMapFileObject;
  MemberMapFileObject::UpdateDependentMembers(memberMapFileObject);
  v4 = (signed __int64)&v3->mChildren;
  if ( v4 )
  {
    v5 = *(_QWORD *)(v4 + 8);
    v6 = v4 - 16;
    for ( i = (_QWORD *)(v5 - 16); i != (_QWORD *)v6; i = (_QWORD *)(i[3] - 16i64) )
      (*(void (__fastcall **)(_QWORD *, MemberMapFileProjectResolveRelativePathsVisitor *))(*i + 80i64))(i, v2);
  }
}

// File Line: 603
// RVA: 0x152A20
void __fastcall MemberMapFileNodeLoadAllFileObjectsVisitor::Visit(MemberMapFileNodeLoadAllFileObjectsVisitor *this, MemberMapFileObject *memberMapFileObject)
{
  MemberMapFileObject *v2; // rbx
  MemberMapFileNodeLoadAllFileObjectsVisitor *v3; // rsi
  signed __int64 v4; // rdi
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v5; // rbx
  signed __int64 i; // rdi
  UFG::qString result; // [rsp+28h] [rbp-30h]

  v2 = memberMapFileObject;
  v3 = this;
  UFG::qString::FormatEx(
    &result,
    "%s\\%s",
    this->mLoadingProject->mAbsoluteDataPath.mData,
    memberMapFileObject->mRelativeFilePath.mData,
    -2i64);
  v2->mIsLoading = 1;
  TargetVisibleInAIDataCondition::CreateClone((hkResourceHandle *)result.mData);
  v2->mIsLoading = 0;
  v4 = (signed __int64)&v2->mChildren;
  if ( v2 != (MemberMapFileObject *)-72i64 )
  {
    v5 = v2->mChildren.mNode.mNext - 1;
    for ( i = v4 - 16; v5 != (UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *)i; v5 = v5[1].mNext - 1 )
      ((void (__fastcall *)(UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *, MemberMapFileNodeLoadAllFileObjectsVisitor *))v5->mPrev[5].mPrev)(
        v5,
        v3);
  }
  UFG::qString::~qString(&result);
}

// File Line: 615
// RVA: 0x152B60
void __fastcall MemberMapFileNodeVisitor::Visit(MemberMapFileNodeVisitor *this, MemberMapFileNode *memberMapFileNode)
{
  MemberMapFileNodeVisitor *v2; // rsi
  char **v3; // rdi
  MemberMapFileNode *v4; // rbx

  v2 = this;
  if ( memberMapFileNode != (MemberMapFileNode *)-72i64 )
  {
    v3 = &memberMapFileNode->mName.mData;
    v4 = (MemberMapFileNode *)&memberMapFileNode->mChildren.mNode.mNext[-1];
    if ( v4 != (MemberMapFileNode *)&memberMapFileNode->mName.mData )
    {
      do
      {
        v4->vfptr[1].FindWithOldPath((Expression::IMemberMap *)&v4->vfptr, (const char *)v2);
        v4 = (MemberMapFileNode *)&v4->mNext[-1];
      }
      while ( v4 != (MemberMapFileNode *)v3 );
    }
  }
}

// File Line: 623
// RVA: 0x152AE0
void __fastcall MemberMapFileNodeLoadAllFileObjectsVisitor::Visit(MemberMapFileNodeLoadAllFileObjectsVisitor *this, MemberMapFileProject *memberMapFileProject)
{
  MemberMapFileNodeLoadAllFileObjectsVisitor *v2; // rdi
  UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *v3; // rdx
  signed __int64 v4; // rsi
  char *v5; // rbx

  v2 = this;
  if ( memberMapFileProject == this->mLoadingProject )
  {
    v3 = &memberMapFileProject->mChildren;
    if ( v3 )
    {
      v4 = (signed __int64)&v3[-1];
      v5 = (char *)&v3->mNode.mNext[-1];
      if ( v5 != (char *)&v3[-1] )
      {
        do
        {
          (*(void (__fastcall **)(char *, MemberMapFileNodeLoadAllFileObjectsVisitor *))(*(_QWORD *)v5 + 80i64))(v5, v2);
          v5 = (char *)(*((_QWORD *)v5 + 3) - 16i64);
        }
        while ( v5 != (char *)v4 );
      }
    }
  }
  else
  {
    ((void (*)(void))this->vfptr->Visit)();
  }
}

// File Line: 685
// RVA: 0x14668A0
__int64 dynamic_initializer_for__MemberMapFileManager::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("MemberMapFileManager", 0xFFFFFFFF);
  MemberMapFileManager::sClassNameUID = result;
  return result;
}

// File Line: 702
// RVA: 0x151AD0
void __fastcall MemberMapFileManager::MemberMapFileManager(MemberMapFileManager *this, const char *startupPath)
{
  const char *v2; // rdi
  MemberMapFileManager *v3; // rsi

  v2 = startupPath;
  v3 = this;
  MemberMapFileNode::MemberMapFileNode((MemberMapFileNode *)&this->vfptr);
  v3->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileGroup::`vftable';
  v3->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileManager::`vftable';
  v3->mActiveProject = 0i64;
  UFG::qString::qString(&v3->mStartupPath);
  v3->mOnNewProjectFileEntryCallback = 0i64;
  UFG::qString::Set(&v3->mName, "MemberMapFileManager");
  UFG::qString::Set(&v3->mStartupPath, v2);
}

// File Line: 739
// RVA: 0x152450
void __fastcall MemberMapFileManager::Init(const char *startupPath)
{
  const char *v1; // rbx
  MemberMapFileManager *v2; // rax
  MemberMapFileManager *v3; // rax
  char *v4; // rax
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *v5; // rcx
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *v6; // rax

  v1 = startupPath;
  if ( !MemberMapFileManager::sMemberMapFileManager )
  {
    v2 = (MemberMapFileManager *)UFG::qMemoryPool2::Allocate(
                                   &gActionTreeMemoryPool,
                                   0xB0ui64,
                                   "MemberMapFileManager",
                                   0i64,
                                   1u);
    if ( v2 )
      MemberMapFileManager::MemberMapFileManager(v2, v1);
    else
      v3 = 0i64;
    MemberMapFileManager::sMemberMapFileManager = v3;
    v4 = UFG::qMalloc(0x40ui64, "IMemberMapFileHandlerEntry", 0i64);
    v5 = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)v4;
    if ( v4 )
    {
      *(_QWORD *)v4 = v4;
      *((_QWORD *)v4 + 1) = v4;
      *((_QWORD *)v4 + 2) = 0i64;
      *((_QWORD *)v4 + 3) = 0i64;
      *((_QWORD *)v4 + 4) = 0i64;
      *((_QWORD *)v4 + 5) = 0i64;
      *((_QWORD *)v4 + 6) = 0i64;
      *((_QWORD *)v4 + 7) = 0i64;
    }
    else
    {
      v5 = 0i64;
    }
    v5[1].mPrev = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)"fpj";
    v5[1].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)"FreemanProjectFile";
    v5[2].mPrev = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)MemberMapFileProject::LoadMemberMapFileProject;
    v5[2].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)MemberMapFileProject::NewMemberMapFileProject;
    v5[3].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)MemberMapFileManager::GetDataBaseRoot;
    v6 = Expression::IMemberMap::smFileHandlers.mNode.mPrev;
    Expression::IMemberMap::smFileHandlers.mNode.mPrev->mNext = v5;
    v5->mPrev = v6;
    v5->mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)&Expression::IMemberMap::smFileHandlers;
    Expression::IMemberMap::smFileHandlers.mNode.mPrev = v5;
    Expression::IMemberMapFileHandlerEntry::sOnNewMemberMapFromFileCallback = (void (__fastcall *)(const char *, Expression::IMemberMap *, Expression::IMemberMap *))_;
  }
}

// File Line: 911
// RVA: 0x152850
void __fastcall MemberMapFileManager::RemoveProject(MemberMapFileManager *this, MemberMapFileProject *memberMapFileProject)
{
  MemberMapFileProject *v2; // r8
  MemberMapFileManager *v3; // rdi
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v4; // rdx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v5; // rax
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v6; // r8
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v7; // rbx

  v2 = this->mActiveProject;
  v3 = this;
  if ( v2 == memberMapFileProject )
  {
    v4 = v2->mPrev;
    v5 = v2->mNext;
    v6 = (UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *)&v2->mPrev;
    v4->mNext = v5;
    v5->mPrev = v4;
    v6->mPrev = v6;
    v6->mNext = v6;
    this->mActiveProject->vfptr->SetResourceOwner((Expression::IMemberMap *)this->mActiveProject, 0i64);
    v3->mActiveProject = 0i64;
  }
  if ( !v3->mActiveProject )
  {
    v7 = v3->mChildren.mNode.mNext - 1;
    if ( v7 != (UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *)&v3->mName.mData )
    {
      while ( ((unsigned int (__fastcall *)(UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *))v7->mPrev[2].mNext)(v7) != MemberMapFileProject::sClassNameUID )
      {
        v7 = v7[1].mNext - 1;
        if ( v7 == (UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *)&v3->mName.mData )
          return;
      }
      v3->mActiveProject = (MemberMapFileProject *)&v3->mChildren.mNode.mNext[-1];
    }
  }
}

// File Line: 1035
// RVA: 0x1522A0
char *__fastcall MemberMapFileManager::GetActiveProjectAbsoluteDataPath(MemberMapFileManager *this)
{
  MemberMapFileProject *v1; // rax
  char *result; // rax

  v1 = this->mActiveProject;
  if ( v1 )
    result = v1->mAbsoluteDataPath.mData;
  else
    result = this->mStartupPath.mData;
  return result;
}

