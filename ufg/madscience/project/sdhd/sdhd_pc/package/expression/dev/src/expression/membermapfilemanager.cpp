// File Line: 33
// RVA: 0x151B60
void __fastcall MemberMapFileNode::MemberMapFileNode(MemberMapFileNode *this)
{
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier>;
  this->mNext = &this->UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier>;
  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileNode::`vftable;
  UFG::qString::qString(&this->mName);
  this->mChildren.mNode.mPrev = &this->mChildren.mNode;
  this->mChildren.mNode.mNext = &this->mChildren.mNode;
  this->mMemberMapFileProject = 0i64;
}

// File Line: 37
// RVA: 0x151DC0
void __fastcall MemberMapFileNode::~MemberMapFileNode(MemberMapFileNode *this)
{
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *mPrev; // rcx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *mNext; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileNode::`vftable;
  UFG::qList<UFG::qTask,UFG::TaskPlat,0,0>::~qList<UFG::qTask,UFG::TaskPlat,0,0>(&this->mChildren);
  UFG::qString::~qString(&this->mName);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier>;
  this->mNext = &this->UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier>;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 90
// RVA: 0x152370
void __fastcall MemberMapFileNode::GetResourcePath(MemberMapFileNode *this, char *path, int pathSize)
{
  int v6; // edi
  __int64 i; // rbx
  int v8; // eax
  __int64 v9; // rdi
  __int64 v10; // rbx
  const char *v11; // rax
  UFG::qString v12; // [rsp+20h] [rbp-138h] BYREF
  __int64 v13; // [rsp+48h] [rbp-110h]
  __int64 v14[32]; // [rsp+50h] [rbp-108h]

  v13 = -2i64;
  v6 = 0;
  for ( i = 0i64; i < 32; ++i )
  {
    if ( !this )
      break;
    v14[i] = (__int64)this;
    ++v6;
    this = (MemberMapFileNode *)this->vfptr->GetResourceOwner(this);
  }
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
  UFG::qSPrintf(path, pathSize, v12.mData);
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gMemberMapFileObjectFactory__);
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
  MemberMapFileNode::MemberMapFileNode(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileObject::`vftable;
  this->mFileTime = 0i64;
  UFG::qString::qString(&this->mRelativeFilePath);
  UFG::qString::qString(&this->mAbsoluteFilePath);
  this->mMemberMapResource = 0i64;
  UFG::qString::qString(&this->mResourcePath);
  *(_WORD *)&this->mModified = 0;
}

// File Line: 154
// RVA: 0x151E20
void __fastcall MemberMapFileObject::~MemberMapFileObject(MemberMapFileObject *this)
{
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *mPrev; // rcx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *mNext; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileObject::`vftable;
  UFG::qString::~qString(&this->mResourcePath);
  UFG::qString::~qString(&this->mAbsoluteFilePath);
  UFG::qString::~qString(&this->mRelativeFilePath);
  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileNode::`vftable;
  UFG::qList<UFG::qTask,UFG::TaskPlat,0,0>::~qList<UFG::qTask,UFG::TaskPlat,0,0>(&this->mChildren);
  UFG::qString::~qString(&this->mName);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier>;
  this->mNext = &this->UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier>;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 204
// RVA: 0x152920
void __fastcall MemberMapFileObject::UpdateDependentMembers(MemberMapFileObject *this)
{
  char *mData; // rdx
  MemberMapFileProject *mMemberMapFileProject; // rdx
  UFG::qString *Filename; // rax
  UFG::qString v5; // [rsp+30h] [rbp-88h] BYREF
  __int64 v6; // [rsp+58h] [rbp-60h]
  UFG::qString result; // [rsp+60h] [rbp-58h] BYREF
  UFG::qString v8; // [rsp+88h] [rbp-30h] BYREF

  v6 = -2i64;
  UFG::qString::qString(&v5);
  if ( this->vfptr->GetClassNameUID(this) == MemberMapFileProject::sClassNameUID )
  {
    mData = MemberMapFileManager::sMemberMapFileManager->mStartupPath.mData;
  }
  else
  {
    mMemberMapFileProject = this->mMemberMapFileProject;
    if ( mMemberMapFileProject )
      mData = mMemberMapFileProject->mAbsoluteDataPath.mData;
    else
      mData = MemberMapFileManager::sMemberMapFileManager->mActiveProject->mAbsoluteDataPath.mData;
  }
  UFG::qString::Set(&v5, mData);
  UFG::qMakeFullPath(&result, v5.mData, this->mRelativeFilePath.mData);
  Filename = UFG::qString::GetFilename(&result, &v8);
  UFG::qString::Set(&this->mName, Filename->mData, Filename->mLength, 0i64, 0);
  UFG::qString::~qString(&v8);
  UFG::qString::Set(&this->mAbsoluteFilePath, result.mData);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v5);
}

// File Line: 330
// RVA: 0x152810
void __fastcall MemberMapFileObject::OnSubjectUpdate(MemberMapFileObject *this, const char *message)
{
  if ( (!message || strcmp("ReadOnlyVarChange", message))
    && !this->mIsLoading
    && !MemberMapFileProject::sLoadingFileObjects )
  {
    this->mModified = 1;
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gMemberMapFileDependentFactory__);
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
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gMemberMapFileGroupFactory__);
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
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *mPrev; // rcx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *mNext; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileGroup::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileNode::`vftable;
  UFG::qList<UFG::qTask,UFG::TaskPlat,0,0>::~qList<UFG::qTask,UFG::TaskPlat,0,0>(&this->mChildren);
  UFG::qString::~qString(&this->mName);
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier>;
  this->mNext = &this->UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier>;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  MemberMapFileManager *v2; // rbx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *mPrev; // rax

  MemberMapFileObject::MemberMapFileObject(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileProject::`vftable;
  UFG::qString::qString(&this->mRelativeDataPath);
  UFG::qString::qString(&this->mAbsoluteDataPath);
  this->mMemberMapResource = this;
  v2 = MemberMapFileManager::sMemberMapFileManager;
  MemberMapFileManager::sMemberMapFileManager->mActiveProject = this;
  this->vfptr->SetResourceOwner(this, v2);
  mPrev = v2->mChildren.mNode.MemberMapFileGroup::MemberMapFileNode::mPrev;
  mPrev->mNext = &this->UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier>;
  this->mPrev = mPrev;
  this->mNext = &v2->mChildren.mNode;
  v2->mChildren.mNode.MemberMapFileGroup::MemberMapFileNode::mPrev = &this->UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier>;
}

// File Line: 477
// RVA: 0x152570
Expression::IMemberMap *__fastcall MemberMapFileProject::LoadMemberMapFileProject(const char *projectFileName)
{
  UFG::qString *FullPath; // rax
  __int64 v4[3]; // [rsp+30h] [rbp-C8h] BYREF
  UFG::qString v5; // [rsp+48h] [rbp-B0h] BYREF
  UFG::qString result; // [rsp+70h] [rbp-88h] BYREF
  UFG::qString v7; // [rsp+98h] [rbp-60h] BYREF
  UFG::qString v8; // [rsp+C0h] [rbp-38h] BYREF
  void **v9; // [rsp+108h] [rbp+10h] BYREF

  v4[2] = -2i64;
  UFG::qString::qString(&v8);
  UFG::qMakeRelativePathFromDirToFile(
    &result,
    MemberMapFileManager::sMemberMapFileManager->mStartupPath.mData,
    projectFileName);
  UFG::qString::Set((UFG::qString *)0x68, result.mData);
  MemberMapFileObject::UpdateDependentMembers(0i64);
  UFG::qString::Set((UFG::qString *)0xF0, MEMORY[0x108]);
  UFG::qString::GetFilePath((UFG::qString *)0x90, &v5);
  FullPath = UFG::qMakeFullPath(&v7, v5.mData, MEMORY[0x108]);
  UFG::qString::Set((UFG::qString *)0x118, FullPath->mData, FullPath->mLength, 0i64, 0);
  UFG::qString::~qString(&v7);
  v9 = &MemberMapFileProjectResolveRelativePathsVisitor::`vftable;
  (*(void (__fastcall **)(_QWORD, void ***))(MEMORY[0] + 80))(0i64, &v9);
  UFG::qString::~qString(&v5);
  MemberMapFileProject::sLoadingFileObjects = 1;
  v4[0] = (__int64)&MemberMapFileNodeLoadAllFileObjectsVisitor::`vftable;
  v4[1] = 0i64;
  (*(void (__fastcall **)(_QWORD, __int64 *))(MEMORY[0] + 80))(0i64, v4);
  MemberMapFileProject::sLoadingFileObjects = 0;
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v8);
  return 0i64;
}

// File Line: 498
// RVA: 0x1526B0
Expression::IMemberMap *__fastcall MemberMapFileProject::NewMemberMapFileProject(
        const char *fileName,
        unsigned __int64 toolVersion)
{
  MemberMapFileProject *v3; // rax
  __int64 v4; // rax
  __int64 v5; // rbx
  UFG::qString *FullPath; // rax
  UFG::qString v8; // [rsp+38h] [rbp-80h] BYREF
  UFG::qString result; // [rsp+60h] [rbp-58h] BYREF
  UFG::qString v10; // [rsp+88h] [rbp-30h] BYREF
  void **p_vfptr; // [rsp+D0h] [rbp+18h] BYREF

  v3 = (MemberMapFileProject *)UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x140ui64, "IMemberMap", 0i64, 1u);
  p_vfptr = (void **)&v3->vfptr;
  if ( v3 )
  {
    MemberMapFileProject::MemberMapFileProject(v3);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  UFG::qMakeRelativePathFromDirToFile(
    &result,
    MemberMapFileManager::sMemberMapFileManager->mStartupPath.mData,
    fileName);
  UFG::qString::Set((UFG::qString *)(v5 + 104), result.mData);
  MemberMapFileObject::UpdateDependentMembers((MemberMapFileObject *)v5);
  UFG::qString::Set((UFG::qString *)(v5 + 240), *(const char **)(v5 + 264));
  UFG::qString::GetFilePath((UFG::qString *)(v5 + 144), &v8);
  FullPath = UFG::qMakeFullPath(&v10, v8.mData, *(const char **)(v5 + 264));
  UFG::qString::Set((UFG::qString *)(v5 + 280), FullPath->mData, FullPath->mLength, 0i64, 0);
  UFG::qString::~qString(&v10);
  p_vfptr = &MemberMapFileProjectResolveRelativePathsVisitor::`vftable;
  (*(void (__fastcall **)(__int64, void ***))(*(_QWORD *)v5 + 80i64))(v5, &p_vfptr);
  UFG::qString::~qString(&v8);
  UFG::qString::~qString(&result);
  return (Expression::IMemberMap *)v5;
}

// File Line: 580
// RVA: 0x152BC0
void __fastcall MemberMapFileProjectResolveRelativePathsVisitor::Visit(
        MemberMapFileProjectResolveRelativePathsVisitor *this,
        MemberMapFileObject *memberMapFileObject)
{
  UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *p_mChildren; // rdi
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *mNext; // rbx
  UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *v6; // rdi
  UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *i; // rbx

  MemberMapFileObject::UpdateDependentMembers(memberMapFileObject);
  p_mChildren = &memberMapFileObject->mChildren;
  if ( p_mChildren )
  {
    mNext = p_mChildren->mNode.mNext;
    v6 = p_mChildren - 1;
    for ( i = (UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *)&mNext[-1];
          i != v6;
          i = (UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *)&i[1].mNode.mNext[-1] )
    {
      ((void (__fastcall *)(UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *, MemberMapFileProjectResolveRelativePathsVisitor *))i->mNode.mPrev[5].mPrev)(
        i,
        this);
    }
  }
}

// File Line: 603
// RVA: 0x152A20
void __fastcall MemberMapFileNodeLoadAllFileObjectsVisitor::Visit(
        MemberMapFileNodeLoadAllFileObjectsVisitor *this,
        MemberMapFileObject *memberMapFileObject)
{
  UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *p_mChildren; // rdi
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v5; // rbx
  UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *i; // rdi
  UFG::qString result; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::FormatEx(
    &result,
    "%s\\%s",
    this->mLoadingProject->mAbsoluteDataPath.mData,
    memberMapFileObject->mRelativeFilePath.mData);
  memberMapFileObject->mIsLoading = 1;
  TargetVisibleInAIDataCondition::CreateClone((hkResourceHandle *)result.mData);
  memberMapFileObject->mIsLoading = 0;
  p_mChildren = &memberMapFileObject->mChildren;
  if ( memberMapFileObject != (MemberMapFileObject *)-72i64 )
  {
    v5 = memberMapFileObject->mChildren.mNode.mNext - 1;
    for ( i = p_mChildren - 1;
          v5 != (UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *)i;
          v5 = v5[1].mNext - 1 )
    {
      ((void (__fastcall *)(UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *, MemberMapFileNodeLoadAllFileObjectsVisitor *))v5->mPrev[5].mPrev)(
        v5,
        this);
    }
  }
  UFG::qString::~qString(&result);
}

// File Line: 615
// RVA: 0x152B60
void __fastcall MemberMapFileNodeVisitor::Visit(MemberMapFileNodeVisitor *this, MemberMapFileNode *memberMapFileNode)
{
  char **p_mData; // rdi
  MemberMapFileNode *v4; // rbx

  if ( memberMapFileNode != (MemberMapFileNode *)-72i64 )
  {
    p_mData = &memberMapFileNode->mName.mData;
    v4 = (MemberMapFileNode *)&memberMapFileNode->mChildren.mNode.mNext[-1];
    if ( v4 != (MemberMapFileNode *)&memberMapFileNode->mName.mData )
    {
      do
      {
        v4->vfptr[1].FindWithOldPath(v4, (const char *)this);
        v4 = (MemberMapFileNode *)&v4->mNext[-1];
      }
      while ( v4 != (MemberMapFileNode *)p_mData );
    }
  }
}

// File Line: 623
// RVA: 0x152AE0
void __fastcall MemberMapFileNodeLoadAllFileObjectsVisitor::Visit(
        MemberMapFileNodeLoadAllFileObjectsVisitor *this,
        MemberMapFileProject *memberMapFileProject)
{
  UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *p_mChildren; // rdx
  UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *v4; // rsi
  UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *v5; // rbx

  if ( memberMapFileProject == this->mLoadingProject )
  {
    p_mChildren = &memberMapFileProject->mChildren;
    if ( p_mChildren )
    {
      v4 = p_mChildren - 1;
      v5 = (UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *)&p_mChildren->mNode.mNext[-1];
      if ( v5 != &p_mChildren[-1] )
      {
        do
        {
          ((void (__fastcall *)(UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *, MemberMapFileNodeLoadAllFileObjectsVisitor *))v5->mNode.mPrev[5].mPrev)(
            v5,
            this);
          v5 = (UFG::qList<MemberMapFileNode,MemberMapFileNodeListIdentifier,0,0> *)&v5[1].mNode.mNext[-1];
        }
        while ( v5 != v4 );
      }
    }
  }
  else
  {
    ((void (__fastcall *)(MemberMapFileNodeLoadAllFileObjectsVisitor *))this->vfptr->Visit)(this);
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
  MemberMapFileNode::MemberMapFileNode(this);
  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileGroup::`vftable;
  this->vfptr = (Expression::IMemberMapVtbl *)&MemberMapFileManager::`vftable;
  this->mActiveProject = 0i64;
  UFG::qString::qString(&this->mStartupPath);
  this->mOnNewProjectFileEntryCallback = 0i64;
  UFG::qString::Set(&this->mName, "MemberMapFileManager");
  UFG::qString::Set(&this->mStartupPath, startupPath);
}

// File Line: 739
// RVA: 0x152450
void __fastcall MemberMapFileManager::Init(const char *startupPath)
{
  MemberMapFileManager *v2; // rax
  MemberMapFileManager *v3; // rax
  char *v4; // rax
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *v5; // rcx
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *mPrev; // rax

  if ( !MemberMapFileManager::sMemberMapFileManager )
  {
    v2 = (MemberMapFileManager *)UFG::qMemoryPool2::Allocate(
                                   &gActionTreeMemoryPool,
                                   0xB0ui64,
                                   "MemberMapFileManager",
                                   0i64,
                                   1u);
    if ( v2 )
      MemberMapFileManager::MemberMapFileManager(v2, startupPath);
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
    mPrev = Expression::IMemberMap::smFileHandlers.mNode.mPrev;
    Expression::IMemberMap::smFileHandlers.mNode.mPrev->mNext = v5;
    v5->mPrev = mPrev;
    v5->mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)&Expression::IMemberMap::smFileHandlers;
    Expression::IMemberMap::smFileHandlers.mNode.mPrev = v5;
    Expression::IMemberMapFileHandlerEntry::sOnNewMemberMapFromFileCallback = (void (__fastcall *)(const char *, Expression::IMemberMap *, Expression::IMemberMap *))_;
  }
}

// File Line: 911
// RVA: 0x152850
void __fastcall MemberMapFileManager::RemoveProject(
        MemberMapFileManager *this,
        MemberMapFileProject *memberMapFileProject)
{
  MemberMapFileProject *mActiveProject; // r8
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *mPrev; // rdx
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *mNext; // rax
  UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier> *v6; // r8
  MemberMapFileManager *v7; // rbx

  mActiveProject = this->mActiveProject;
  if ( mActiveProject == memberMapFileProject )
  {
    mPrev = mActiveProject->mPrev;
    mNext = mActiveProject->mNext;
    v6 = &mActiveProject->UFG::qNode<MemberMapFileNode,MemberMapFileNodeListIdentifier>;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    v6->mPrev = v6;
    v6->mNext = v6;
    this->mActiveProject->vfptr->SetResourceOwner(this->mActiveProject, 0i64);
    this->mActiveProject = 0i64;
  }
  if ( !this->mActiveProject )
  {
    v7 = (MemberMapFileManager *)&this->mChildren.mNode.mNext[-1];
    if ( v7 != (MemberMapFileManager *)&this->mName.mData )
    {
      while ( v7->vfptr->GetClassNameUID(v7) != MemberMapFileProject::sClassNameUID )
      {
        v7 = (MemberMapFileManager *)&v7->mNext[-1];
        if ( v7 == (MemberMapFileManager *)&this->mName.mData )
          return;
      }
      this->mActiveProject = (MemberMapFileProject *)&this->mChildren.mNode.mNext[-1];
    }
  }
}

// File Line: 1035
// RVA: 0x1522A0
char *__fastcall MemberMapFileManager::GetActiveProjectAbsoluteDataPath(MemberMapFileManager *this)
{
  MemberMapFileProject *mActiveProject; // rax

  mActiveProject = this->mActiveProject;
  if ( mActiveProject )
    return mActiveProject->mAbsoluteDataPath.mData;
  else
    return this->mStartupPath.mData;
}

