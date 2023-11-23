// File Line: 20
// RVA: 0x161660
void __fastcall UFG::qLogFile::qLogFile(UFG::qLogFile *this)
{
  UFG::qMutex::qMutex(&this->mLock, &customCaption);
  this->mLogFilename.mPrev = &this->mLogFilename;
  this->mLogFilename.mNext = &this->mLogFilename;
  this->mLogFilename.mMagic = 16909060;
  this->mLogFilename.mData = (char *)UFG::qString::sEmptyString;
  this->mLogFilename.mLength = 0;
  *(_QWORD *)&this->mLogFilename.mStringHash32 = -1i64;
  this->mAccumulatedLogFilename.mPrev = &this->mAccumulatedLogFilename;
  this->mAccumulatedLogFilename.mNext = &this->mAccumulatedLogFilename;
  this->mAccumulatedLogFilename.mMagic = 16909060;
  this->mAccumulatedLogFilename.mData = (char *)UFG::qString::sEmptyString;
  this->mAccumulatedLogFilename.mLength = 0;
  *(_QWORD *)&this->mAccumulatedLogFilename.mStringHash32 = -1i64;
  this->mFlags = 196608;
  this->mLogFile = 0i64;
  this->mAccumulatedLogFile = 0i64;
}

// File Line: 29
// RVA: 0x163E50
void __fastcall UFG::qLogFile::~qLogFile(UFG::qLogFile *this)
{
  UFG::qString *p_mAccumulatedLogFilename; // rbx
  char *mData; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *mNext; // rax
  UFG::qString *p_mLogFilename; // rbx
  char *v7; // rdx
  UFG::qNode<UFG::qString,UFG::qString> *v8; // rcx
  UFG::qNode<UFG::qString,UFG::qString> *v9; // rax

  UFG::qLogFile::End(this);
  p_mAccumulatedLogFilename = &this->mAccumulatedLogFilename;
  mData = this->mAccumulatedLogFilename.mData;
  if ( mData != UFG::qString::sEmptyString && mData )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, mData);
  this->mAccumulatedLogFilename.mMagic = 0;
  mPrev = p_mAccumulatedLogFilename->mPrev;
  mNext = this->mAccumulatedLogFilename.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_mAccumulatedLogFilename->mPrev = p_mAccumulatedLogFilename;
  this->mAccumulatedLogFilename.mNext = &this->mAccumulatedLogFilename;
  p_mLogFilename = &this->mLogFilename;
  v7 = this->mLogFilename.mData;
  if ( v7 != UFG::qString::sEmptyString && v7 )
    UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v7);
  this->mLogFilename.mMagic = 0;
  v8 = p_mLogFilename->mPrev;
  v9 = this->mLogFilename.mNext;
  v8->mNext = v9;
  v9->mPrev = v8;
  p_mLogFilename->mPrev = p_mLogFilename;
  this->mLogFilename.mNext = &this->mLogFilename;
  Scaleform::Lock::~Lock((LPCRITICAL_SECTION)this);
}

// File Line: 59
// RVA: 0x16D0E0
void __fastcall UFG::qLogFile::End(UFG::qLogFile *this)
{
  UFG::qFile *mLogFile; // rcx
  UFG::qFile *mAccumulatedLogFile; // rcx

  mLogFile = this->mLogFile;
  if ( mLogFile )
    UFG::qClose(mLogFile);
  mAccumulatedLogFile = this->mAccumulatedLogFile;
  if ( mAccumulatedLogFile )
    UFG::qClose(mAccumulatedLogFile);
  UFG::qString::Set(&this->mLogFilename, 0i64, 0, 0i64, 0);
  UFG::qString::Set(&this->mAccumulatedLogFilename, 0i64, 0, 0i64, 0);
  this->mLogFile = 0i64;
  this->mAccumulatedLogFile = 0i64;
}

