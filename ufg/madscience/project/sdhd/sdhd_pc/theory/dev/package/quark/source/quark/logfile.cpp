// File Line: 20
// RVA: 0x161660
void __fastcall UFG::qLogFile::qLogFile(UFG::qLogFile *this)
{
  UFG::qLogFile *v1; // rbx
  UFG::qString *v2; // [rsp+48h] [rbp+10h]
  UFG::qString *v3; // [rsp+48h] [rbp+10h]

  v1 = this;
  UFG::qMutex::qMutex(&this->mLock, &customWorldMapCaption);
  v2 = &v1->mLogFilename;
  v2->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
  v2->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
  v1->mLogFilename.mMagic = 16909060;
  v1->mLogFilename.mData = (char *)UFG::qString::sEmptyString;
  v1->mLogFilename.mLength = 0;
  *(_QWORD *)&v1->mLogFilename.mStringHash32 = -1i64;
  v3 = &v1->mAccumulatedLogFilename;
  v3->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v3->mPrev;
  v3->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v3->mPrev;
  v1->mAccumulatedLogFilename.mMagic = 16909060;
  v1->mAccumulatedLogFilename.mData = (char *)UFG::qString::sEmptyString;
  v1->mAccumulatedLogFilename.mLength = 0;
  *(_QWORD *)&v1->mAccumulatedLogFilename.mStringHash32 = -1i64;
  v1->mFlags = 196608;
  v1->mLogFile = 0i64;
  v1->mAccumulatedLogFile = 0i64;
}

// File Line: 29
// RVA: 0x163E50
void __fastcall UFG::qLogFile::~qLogFile(UFG::qLogFile *this)
{
  UFG::qLogFile *v1; // rdi
  UFG::qString *v2; // rbx
  char *v3; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v4; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v5; // rax
  UFG::qString *v6; // rbx
  char *v7; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax

  v1 = this;
  UFG::qLogFile::End(this);
  v2 = &v1->mAccumulatedLogFilename;
  v3 = v1->mAccumulatedLogFilename.mData;
  if ( v3 != UFG::qString::sEmptyString && v3 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v3);
  v1->mAccumulatedLogFilename.mMagic = 0;
  v4 = v2->mPrev;
  v5 = v1->mAccumulatedLogFilename.mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v2->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v2->mPrev;
  v1->mAccumulatedLogFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v1->mAccumulatedLogFilename.mPrev;
  v6 = &v1->mLogFilename;
  v7 = v1->mLogFilename.mData;
  if ( v7 != UFG::qString::sEmptyString && v7 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v7);
  v1->mLogFilename.mMagic = 0;
  v8 = v6->mPrev;
  v9 = v1->mLogFilename.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  v6->mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&v6->mPrev;
  v1->mLogFilename.mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&v1->mLogFilename.mPrev;
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)v1);
}

// File Line: 59
// RVA: 0x16D0E0
void __fastcall UFG::qLogFile::End(UFG::qLogFile *this)
{
  UFG::qLogFile *v1; // rbx
  UFG::qFile *v2; // rcx
  UFG::qFile *v3; // rcx

  v1 = this;
  v2 = this->mLogFile;
  if ( v2 )
    UFG::qClose(v2);
  v3 = v1->mAccumulatedLogFile;
  if ( v3 )
    UFG::qClose(v3);
  UFG::qString::Set(&v1->mLogFilename, 0i64, 0, 0i64, 0);
  UFG::qString::Set(&v1->mAccumulatedLogFilename, 0i64, 0, 0i64, 0);
  v1->mLogFile = 0i64;
  v1->mAccumulatedLogFile = 0i64;
}

