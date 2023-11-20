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
  return atexit(dynamic_atexit_destructor_for__gBoneInfoFactory__);
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
  UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *v3; // rax
  UFG::qList<RigInfo,RigInfo,1,0> *v4; // [rsp+58h] [rbp+10h]

  v0 = (RigInfoDataBase *)UFG::qMemoryPool2::Allocate(&gActionTreeMemoryPool, 0x20ui64, "RigInfoDataBase", 0i64, 1u);
  if ( v0 )
  {
    v0->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
    v0->mResourceOwner = 0i64;
    v0->vfptr = (Expression::IMemberMapVtbl *)&RigInfoDataBase::`vftable';
    v4 = &v0->mRigInfos;
    v4->mNode.mPrev = &v4->mNode;
    v4->mNode.mNext = &v4->mNode;
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
  v3 = Expression::IMemberMap::smFileHandlers.mNode.mPrev;
  Expression::IMemberMap::smFileHandlers.mNode.mPrev->mNext = v2;
  v2->mPrev = v3;
  v2->mNext = (UFG::qNode<Expression::IMemberMapFileHandlerEntry,Expression::IMemberMapFileHandlerEntry> *)&Expression::IMemberMap::smFileHandlers;
  Expression::IMemberMap::smFileHandlers.mNode.mPrev = v2;
}

// File Line: 190
// RVA: 0x3AD210
void RigInfoDataBase::PreLoad(void)
{
  UFG::qString v0; // [rsp+28h] [rbp-30h]

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
  UFG::qNode<WeightSetGroup,WeightSetGroup> *v2; // rax
  UFG::qNode<WeightSetGroup,WeightSetGroup> *v3; // rdx
  UFG::qList<WeightSetGroup,WeightSetGroup,1,0> *v4; // rcx

  v2 = this->mWeightSetGroups.mNode.mPrev;
  v3 = (UFG::qNode<WeightSetGroup,WeightSetGroup> *)&weightSetGroup->mPrev;
  v4 = &this->mWeightSetGroups;
  v2->mNext = v3;
  v3->mPrev = v2;
  v3->mNext = &v4->mNode;
  v4->mNode.mPrev = v3;
}

// File Line: 238
// RVA: 0x3AE080
void __fastcall RigInfoDataBase::RemoveRigInfo(WeightSetDataBase *this, WeightSetGroup *weightSetGroup)
{
  UFG::qNode<WeightSetGroup,WeightSetGroup> *v2; // rcx
  UFG::qNode<WeightSetGroup,WeightSetGroup> *v3; // rax
  UFG::qNode<WeightSetGroup,WeightSetGroup> *v4; // rdx

  v2 = weightSetGroup->mPrev;
  v3 = weightSetGroup->mNext;
  v4 = (UFG::qNode<WeightSetGroup,WeightSetGroup> *)&weightSetGroup->mPrev;
  v2->mNext = v3;
  v3->mPrev = v2;
  v4->mPrev = v4;
  v4->mNext = v4;
}

// File Line: 260
// RVA: 0x3ABEE0
RigInfo *__fastcall RigInfoDataBase::NewMemberMap(const char *fileName, unsigned __int64 toolVersion)
{
  UFG::qString *v2; // rax
  RigInfo *v3; // rbx
  UFG::qString v5; // [rsp+28h] [rbp-60h]
  UFG::qString result; // [rsp+50h] [rbp-38h]

  UFG::qString::qString(&v5, fileName);
  v2 = UFG::qString::GetFilenameWithoutExtension(&v5, &result);
  v3 = RigInfoDataBase::CreateRigInfo(RigInfoDataBase::sRigInfoDataBase, v2->mData);
  UFG::qString::~qString(&result);
  UFG::qString::~qString(&v5);
  return v3;
}

// File Line: 266
// RVA: 0x3A6490
RigInfo *__fastcall RigInfoDataBase::CreateRigInfo(RigInfoDataBase *this, const char *rigInfoName)
{
  const char *v2; // rdi
  RigInfoDataBase *v3; // rsi
  char *v4; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  UFG::qNode<RigInfo,RigInfo> **v7; // rcx
  UFG::qNode<RigInfo,RigInfo> *v8; // rax

  v2 = rigInfoName;
  v3 = this;
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
    BinString::Set((BinString *)(v6 + 40), v2);
    *(_DWORD *)(v6 + 32) = UFG::qStringHashUpper32(v2, 0xFFFFFFFF);
    v7 = (UFG::qNode<RigInfo,RigInfo> **)(v6 + 16);
    v8 = v3->mRigInfos.mNode.mPrev;
    v8->mNext = (UFG::qNode<RigInfo,RigInfo> *)(v6 + 16);
    *v7 = v8;
    v7[1] = &v3->mRigInfos.mNode;
    v3->mRigInfos.mNode.mPrev = (UFG::qNode<RigInfo,RigInfo> *)(v6 + 16);
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
  IActionTreeSerializer *v2; // r14
  unsigned int v3; // ebx
  RigInfo *v4; // rsi
  __int64 v5; // rax
  signed __int64 v6; // rcx
  signed __int64 v7; // rdx
  __int64 v8; // rax
  void *v9; // rdi
  __int64 v10; // rax
  __int64 v11; // [rsp+28h] [rbp-30h]
  __int64 v12; // [rsp+30h] [rbp-28h]
  __int64 v13; // [rsp+40h] [rbp-18h]

  v2 = serializer;
  v3 = 0;
  v4 = this;
  if ( this->mPoseDrivers.mCount & 0x7FFFFFFF )
  {
    do
    {
      v5 = v4->mPoseDrivers.mData.mOffset;
      if ( v5 )
        v6 = (signed __int64)&v4->mPoseDrivers.mData + v5;
      else
        v6 = 0i64;
      v7 = v6 + 8i64 * v3;
      v8 = *(_QWORD *)(v6 + 8i64 * v3);
      if ( v8 )
      {
        v9 = (void *)(v8 + v7);
        if ( v8 + v7 )
        {
          v10 = (*(__int64 (__fastcall **)(void *))(*(_QWORD *)v9 + 32i64))(v9);
          LODWORD(v13) = -1;
          LODWORD(v12) = 0;
          LODWORD(v11) = 1;
          v2->vfptr->_PushObjectToSerialize(
            v2,
            v9,
            1u,
            (void (__fastcall *)(void *, unsigned int, IActionTreeSerializer *, const char *, unsigned int, void (__fastcall *)(IActionTreeSerializer *, void *)))_,
            (const char *)v10,
            (QUEUE_PRIORITY)v11,
            v12,
            0i64,
            v13,
            0i64);
        }
      }
      ++v3;
    }
    while ( v3 < (v4->mPoseDrivers.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 334
// RVA: 0x3A1B80
void __fastcall RigInfo::AddToCreature(RigInfo *this, Creature *creature)
{
  __int64 v2; // rbx
  Creature *v3; // rbp
  RigInfo *v4; // rsi
  char *v5; // r14
  __int64 v6; // rdi

  v2 = 0i64;
  v3 = creature;
  v4 = this;
  v5 = (char *)&this->mPoseDrivers.mData + this->mPoseDrivers.mData.mOffset;
  if ( this->mPoseDrivers.mCount & 0x7FFFFFFF )
  {
    do
    {
      v6 = (*(__int64 (**)(void))(*(_QWORD *)&v5[8 * v2 + *(_QWORD *)&v5[8 * v2]] + 16i64))();
      if ( !(*(unsigned __int8 (__fastcall **)(__int64, Creature *))(*(_QWORD *)v6 + 152i64))(v6, v3) )
        (*(void (__fastcall **)(__int64, signed __int64))(*(_QWORD *)v6 + 8i64))(v6, 1i64);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < (v4->mPoseDrivers.mCount & 0x7FFFFFFFu) );
  }
}

// File Line: 358
// RVA: 0x39F7A0
void __fastcall BoneInfo::~BoneInfo(BoneInfo *this)
{
  BoneInfo *v1; // rbx
  char *v2; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&BoneInfo::`vftable';
  if ( !(~LOBYTE(this->mName.mOffset) & 1) )
  {
    if ( this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v2 = (char *)&this->mName + (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v2 != BinString::sEmptyString )
        operator delete[](v2);
    }
  }
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable';
}

