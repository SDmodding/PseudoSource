// File Line: 22
// RVA: 0x2BDD80
__int64 __fastcall BoneInfo::GetClassNameUID(BoneInfo *this)
{
  return BoneInfo::sClassNameUID;
}

// File Line: 174
// RVA: 0x39E470
void __fastcall RigInfo::RigInfo(RigInfo *this)
{
  RigInfo *v1; // rbx
  UFG::qNode<RigInfo,RigInfo> *v2; // rax
  BinString *v3; // rcx

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  v2 = (UFG::qNode<RigInfo,RigInfo> *)&this->mPrev;
  v2->mPrev = v2;
  v2->mNext = v2;
  this->vfptr = (Expression::IMemberMapVtbl *)&RigInfo::`vftable;
  this->mUID = -1;
  v3 = &this->mName;
  v3->mOffset = 1i64;
  BinString::Set(v3, &customWorldMapCaption);
  v1->mPoseDrivers.mCount = 0;
  v1->mPoseDrivers.mData.mOffset = 0i64;
}

// File Line: 176
// RVA: 0x29D910
void __fastcall RigInfo::~RigInfo(RigInfo *this)
{
  RigInfo *v1; // rbx
  __int64 v2; // rax
  char *v3; // rcx
  char *v4; // rcx
  UFG::qNode<RigInfo,RigInfo> *v5; // rdx
  UFG::qNode<RigInfo,RigInfo> *v6; // rcx
  UFG::qNode<RigInfo,RigInfo> *v7; // rax

  v1 = this;
  this->vfptr = (Expression::IMemberMapVtbl *)&RigInfo::`vftable;
  if ( this->mPoseDrivers.mCount >= 0 )
  {
    v2 = this->mPoseDrivers.mData.mOffset;
    if ( v2 )
    {
      v3 = (char *)&this->mPoseDrivers.mData + v2;
      if ( v3 )
        operator delete[](v3);
    }
    v1->mPoseDrivers.mData.mOffset = 0i64;
    v1->mPoseDrivers.mCount &= 0x80000000;
  }
  if ( !(~LOBYTE(v1->mName.mOffset) & 1) )
  {
    if ( v1->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64 )
    {
      v4 = (char *)&v1->mName + (v1->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
      if ( v4 != BinString::sEmptyString )
        operator delete[](v4);
    }
  }
  v5 = (UFG::qNode<RigInfo,RigInfo> *)&v1->mPrev;
  v6 = v1->mPrev;
  v7 = v1->mNext;
  v6->mNext = v7;
  v7->mPrev = v6;
  v5->mPrev = v5;
  v5->mNext = v5;
  v1->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
}

// File Line: 178
// RVA: 0x2C2240
const char *__fastcall RigInfo::GetClassname(RigInfo *this)
{
  return RigInfo::sClassName;
}

// File Line: 259
// RVA: 0x3A8EC0
RigInfoDataBase *__fastcall RigInfoDataBase::GetInstance()
{
  return RigInfoDataBase::sRigInfoDataBase;
}

// File Line: 261
// RVA: 0x3A7E30
const char *__fastcall RigInfoDataBase::GetClassname(RigInfoDataBase *this)
{
  return RigInfoDataBase::sClassName;
}

// File Line: 290
// RVA: 0x3AB650
Expression::IMemberMap *__fastcall RigInfoDataBase::LoadMemberMap(const char *fileName)
{
  UFG::qString v2; // [rsp+28h] [rbp-30h]

  UFG::qString::qString(&v2);
  UFG::qString::~qString(&v2);
  return 0i64;
}

