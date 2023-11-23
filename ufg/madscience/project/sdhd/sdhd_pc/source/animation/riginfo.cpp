// File Line: 23
// RVA: 0x14B99B0
__int64 dynamic_initializer_for__SkeletonInfoDataBase::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SkeletonInfoDataBase", 0xFFFFFFFF);
  SkeletonInfoDataBase::sClassNameUID = result;
  return result;
}

// File Line: 138
// RVA: 0x14BF450
const char *dynamic_initializer_for__sBoneInfoList__()
{
  const char *result; // rax

  result = BoneInfo::sClassName;
  sBoneInfoList[0].mClassName = BoneInfo::sClassName;
  return result;
}

// File Line: 144
// RVA: 0x14BCF90
__int64 dynamic_initializer_for__gBoneInfoFactory__()
{
  Expression::MemberMapFactory::MemberMapFactory(&gBoneInfoFactory, sBoneInfoList, sBoneInfoListNum);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__gBoneInfoFactory__);
}

// File Line: 146
// RVA: 0x14B9990
__int64 dynamic_initializer_for__SkeletonInfo::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("SkeletonInfo", 0xFFFFFFFF);
  SkeletonInfo::sClassNameUID = result;
  return result;
}

// File Line: 156
// RVA: 0x14B9750
__int64 dynamic_initializer_for__BoneInfo::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("BoneInfo", 0xFFFFFFFF);
  BoneInfo::sClassNameUID = result;
  return result;
}

// File Line: 166
// RVA: 0x14B9930
__int64 dynamic_initializer_for__RigInfoDataBase::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RigInfoDataBase", 0xFFFFFFFF);
  RigInfoDataBase::sClassNameUID = result;
  return result;
}

// File Line: 174
// RVA: 0x3AAB00
void RigInfoDataBase::Init(void)
{
  RigInfoDataBase *v0; // rcx
  UFG::allocator::free_link *v1; // rax
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *v2; // rcx
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *mPrev; // rax

  v0 = (RigInfoDataBase *)UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "RigInfoDataBase", 0i64, 1u);
  if ( v0 )
  {
    v0->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
    v0->mResourceOwner = 0i64;
    v0->vfptr = (Expression::IMemberMapVtbl *)&RigInfoDataBase::`vftable;
    v0->mRigInfos.mNode.mPrev = &v0->mRigInfos.mNode;
    v0->mRigInfos.mNode.mNext = &v0->mRigInfos.mNode;
  }
  else
  {
    v0 = 0i64;
  }
  RigInfoDataBase::sRigInfoDataBase = v0;
  v1 = UFG::qMalloc(0x40ui64, "RigInfoDataBase", 0i64);
  v2 = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)v1;
  if ( v1 )
  {
    v1->mNext = v1;
    v1[1].mNext = v1;
    v1[2].mNext = 0i64;
    v1[3].mNext = 0i64;
    v1[4].mNext = 0i64;
    v1[5].mNext = 0i64;
    v1[6].mNext = 0i64;
    v1[7].mNext = 0i64;
  }
  else
  {
    v2 = 0i64;
  }
  v2[1].mPrev = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)"rig2";
  v2[1].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)"PoseDrivers";
  v2[2].mPrev = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)RigInfoDataBase::LoadMemberMap;
  v2[2].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)RigInfoDataBase::NewMemberMap;
  v2[3].mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)RigInfoDataBase::GetInstance;
  mPrev = Expression::IMemberMap::smFileHandlers.mNode.mPrev;
  Expression::IMemberMap::smFileHandlers.mNode.mPrev->mNext = v2;
  v2->mPrev = mPrev;
  v2->mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)&Expression::IMemberMap::smFileHandlers;
  Expression::IMemberMap::smFileHandlers.mNode.mPrev = v2;
}

// File Line: 190
// RVA: 0x3AD210
void RigInfoDataBase::PreLoad(void)
{
  UFG::qString v0; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::qString(&v0);
  UFG::qString::~qString(&v0);
  UFG::qString::qString(&v0);
  UFG::qString::~qString(&v0);
  UFG::qString::qString(&v0);
  UFG::qString::~qString(&v0);
  UFG::qString::qString(&v0);
  UFG::qString::~qString(&v0);
  UFG::qString::qString(&v0);
  UFG::qString::~qString(&v0);
}

// File Line: 233
// RVA: 0x3A14E0
void __fastcall WeightSetDataBase::AddWeightSetGroup(WeightSetDataBase *this, WeightSetGroup *weightSetGroup)
{
  UFG::qNode<WeightSetGroup,WeightSetGroup> *mPrev; // rax
  UFG::qNode<WeightSetGroup,WeightSetGroup> *v3; // rdx
  UFG::qList<WeightSetGroup,WeightSetGroup,1,0> *p_mWeightSetGroups; // rcx

  mPrev = this->mWeightSetGroups.mNode.mPrev;
  v3 = &weightSetGroup->UFG::qNode<WeightSetGroup,WeightSetGroup>;
  p_mWeightSetGroups = &this->mWeightSetGroups;
  mPrev->mNext = v3;
  v3->mPrev = mPrev;
  v3->mNext = &p_mWeightSetGroups->mNode;
  p_mWeightSetGroups->mNode.mPrev = v3;
}

// File Line: 238
// RVA: 0x3AE080
void __fastcall RigInfoDataBase::RemoveRigInfo(WeightSetDataBase *this, WeightSetGroup *weightSetGroup)
{
  UFG::qNode<WeightSetGroup,WeightSetGroup> *mPrev; // rcx
  UFG::qNode<WeightSetGroup,WeightSetGroup> *mNext; // rax
  UFG::qNode<WeightSetGroup,WeightSetGroup> *v4; // rdx

  mPrev = weightSetGroup->mPrev;
  mNext = weightSetGroup->mNext;
  v4 = &weightSetGroup->UFG::qNode<WeightSetGroup,WeightSetGroup>;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  v4->mPrev = v4;
  v4->mNext = v4;
}

// File Line: 260
// RVA: 0x3ABEE0
RigInfo *__fastcall RigInfoDataBase::NewMemberMap(const char *fileName, unsigned __int64 toolVersion)
{
  UFG::qString *FilenameWithoutExtension; // rax
  RigInfo *RigInfo; // rbx
  UFG::qString v5; // [rsp+28h] [rbp-60h] BYREF
  UFG::qString result; // [rsp+50h] [rbp-38h] BYREF

  UFG::qString::qString(&v5, fileName);
  FilenameWithoutExtension = UFG::qString::GetFilenameWithoutExtension(&v5, &result);
  RigInfo = RigInfoDataBase::CreateRigInfo(RigInfoDataBase::sRigInfoDataBase, FilenameWithoutExtension->mData);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v5);
  return RigInfo;
}

// File Line: 266
// RVA: 0x3A6490
RigInfo *__fastcall RigInfoDataBase::CreateRigInfo(RigInfoDataBase *this, char *rigInfoName)
{
  char *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  UFG::qNode<RigInfo,RigInfo> *mPrev; // rax

  v4 = UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x40ui64, "MemberMap::RigInfo", 0i64, 1u);
  if ( v4 )
  {
    RigInfo::RigInfo((RigInfo *)v4);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  if ( v6 )
  {
    BinString::Set((BinString *)(v6 + 40), rigInfoName);
    *(_DWORD *)(v6 + 32) = UFG::qStringHashUpper32(rigInfoName, -1);
    mPrev = this->mRigInfos.mNode.mPrev;
    mPrev->mNext = (UFG::qNode<RigInfo,RigInfo> *)(v6 + 16);
    *(_QWORD *)(v6 + 16) = mPrev;
    *(_QWORD *)(v6 + 24) = &this->mRigInfos;
    this->mRigInfos.mNode.mPrev = (UFG::qNode<RigInfo,RigInfo> *)(v6 + 16);
  }
  return (RigInfo *)v6;
}

// File Line: 312
// RVA: 0x14B9910
__int64 dynamic_initializer_for__RigInfo::sClassNameUID__()
{
  __int64 result; // rax

  result = UFG::qStringHash32("RigInfo", 0xFFFFFFFF);
  RigInfo::sClassNameUID = result;
  return result;
}

// File Line: 318
// RVA: 0x3AE8E0
void __fastcall RigInfo::Serialize(RigInfo *this, IActionTreeSerializer *serializer)
{
  unsigned int v3; // ebx
  __int64 mOffset; // rax
  char *v6; // rcx
  char *v7; // rdx
  __int64 v8; // rax
  char *v9; // rdi
  const char *v10; // rax

  v3 = 0;
  if ( (this->mPoseDrivers.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      mOffset = this->mPoseDrivers.mData.mOffset;
      if ( mOffset )
        v6 = (char *)&this->mPoseDrivers.mData + mOffset;
      else
        v6 = 0i64;
      v7 = &v6[8 * v3];
      v8 = *(_QWORD *)v7;
      if ( *(_QWORD *)v7 )
      {
        v9 = &v7[v8];
        if ( &v7[v8] )
        {
          v10 = (const char *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v9 + 32i64))(v9);
          serializer->vfptr->_PushObjectToSerialize(
            serializer,
            v9,
            1u,
            (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
            v10,
            PRIORITY_MEDIUM,
            0,
            0i64,
            -1u,
            0i64);
        }
      }
      ++v3;
    }
    while ( v3 < (this->mPoseDrivers.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 334
// RVA: 0x3A1B80
void __fastcall RigInfo::AddToCreature(RigInfo *this, Creature *creature)
{
  __int64 v2; // rbx
  char *v5; // r14
  __int64 v6; // rcx
  __int64 v7; // rdi

  v2 = 0i64;
  v5 = (char *)&this->mPoseDrivers.mData + this->mPoseDrivers.mData.mOffset;
  if ( (this->mPoseDrivers.mCount & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v6 = (__int64)&v5[8 * v2 + *(_QWORD *)&v5[8 * v2]];
      v7 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 16i64))(v6);
      if ( !(*(unsigned __int8 (__fastcall **)(__int64, Creature *))(*(_QWORD *)v7 + 152i64))(v7, creature) )
        (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v7 + 8i64))(v7, 1i64);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < (this->mPoseDrivers.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 358
// RVA: 0x39F7A0
void __fastcall BoneInfo::~BoneInfo(BoneInfo *this)
{
  char *v2; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&BoneInfo::`vftable;
  if ( (this->mName.mOffset & 1) != 0 && (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v2 = (char *)&this->mName + (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v2 != BinString::sEmptyString )
      operator delete[](v2);
  }
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

