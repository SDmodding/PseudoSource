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
  BinString *p_mName; // rcx

  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
  this->mResourceOwner = 0i64;
  this->mPrev = &this->UFG::qNode<RigInfo,RigInfo>;
  this->mNext = &this->UFG::qNode<RigInfo,RigInfo>;
  this->vfptr = (Expression::IMemberMapVtbl *)&RigInfo::`vftable;
  this->mUID = -1;
  p_mName = &this->mName;
  p_mName->mOffset = 1i64;
  BinString::Set(p_mName, &customCaption);
  this->mPoseDrivers.mCount = 0;
  this->mPoseDrivers.mData.mOffset = 0i64;
}

// File Line: 176
// RVA: 0x29D910
void __fastcall RigInfo::~RigInfo(RigInfo *this)
{
  __int64 mOffset; // rax
  char *v3; // rcx
  char *v4; // rcx
  UFG::qNode<RigInfo,RigInfo> *mPrev; // rcx
  UFG::qNode<RigInfo,RigInfo> *mNext; // rax

  this->vfptr = (Expression::IMemberMapVtbl *)&RigInfo::`vftable;
  if ( this->mPoseDrivers.mCount >= 0 )
  {
    mOffset = this->mPoseDrivers.mData.mOffset;
    if ( mOffset )
    {
      v3 = (char *)&this->mPoseDrivers.mData + mOffset;
      if ( v3 )
        operator delete[](v3);
    }
    this->mPoseDrivers.mData.mOffset = 0i64;
    this->mPoseDrivers.mCount &= 0x80000000;
  }
  if ( (this->mName.mOffset & 1) != 0 && (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64) != 0 )
  {
    v4 = (char *)&this->mName + (this->mName.mOffset & 0xFFFFFFFFFFFFFFFEui64);
    if ( v4 != BinString::sEmptyString )
      operator delete[](v4);
  }
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = &this->UFG::qNode<RigInfo,RigInfo>;
  this->mNext = &this->UFG::qNode<RigInfo,RigInfo>;
  this->vfptr = (Expression::IMemberMapVtbl *)&Expression::IMemberMap::`vftable;
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
  UFG::qString v2; // [rsp+28h] [rbp-30h] BYREF

  UFG::qString::qString(&v2);
  UFG::qString::~qString(&v2);
  return 0i64;
}

