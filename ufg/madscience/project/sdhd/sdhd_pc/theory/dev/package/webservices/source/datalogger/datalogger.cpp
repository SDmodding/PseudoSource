// File Line: 55
// RVA: 0x253E70
void __fastcall UFG::StringBuffer::~StringBuffer(UFG::StringBuffer *this)
{
  char *mBuffer; // rcx

  mBuffer = this->mBuffer;
  if ( mBuffer )
  {
    operator delete[](mBuffer);
    this->mBuffer = 0i64;
  }
}

// File Line: 148
// RVA: 0x253C60
void __fastcall UFG::Collection::Collection(UFG::Collection *this, const char *collectionName, unsigned int bufferSize)
{
  unsigned int v6; // eax
  char *v7; // rax

  v6 = UFG::qStringHashUpper32(collectionName, -1);
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v6;
  UFG::qString::qString(&this->mName, collectionName);
  *(_DWORD *)&this->mListOpen = 0;
  *(_WORD *)&this->mMetaDataOpen = 0;
  this->mIsBuffered = 0;
  UFG::qString::qString(&this->mCurrentEvent);
  this->mLastTransmission = 0i64;
  this->mBuffer.mBuffer = 0i64;
  this->mBuffer.mCurrentOffset = 0i64;
  this->mBuffer.mBufferSize = 0;
  this->mPerSessionMetaDataFunction = 0i64;
  this->mPerFrameMetaDataFunction = 0i64;
  v7 = (char *)UFG::qMalloc(bufferSize, "DataLogger::StringBuffer", 0i64);
  this->mBuffer.mBuffer = v7;
  this->mBuffer.mBufferSize = bufferSize;
  this->mBuffer.mCurrentOffset = v7;
  *v7 = 0;
}

// File Line: 267
// RVA: 0x1476070
__int64 dynamic_initializer_for__UFG::DataLogger::sSystemLogCollectionName__()
{
  UFG::qString::qString(&UFG::DataLogger::sSystemLogCollectionName, "SystemLog");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DataLogger::sSystemLogCollectionName__);
}

// File Line: 268
// RVA: 0x1476010
__int64 dynamic_initializer_for__UFG::DataLogger::sLogMessageURL__()
{
  UFG::qString::qString(&UFG::DataLogger::sLogMessageURL, "https://prod-triadwars.cloudapp.net/logging/api/v1/message");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DataLogger::sLogMessageURL__);
}

// File Line: 269
// RVA: 0x1476040
__int64 dynamic_initializer_for__UFG::DataLogger::sLogTelemetryURL__()
{
  UFG::qString::qString(&UFG::DataLogger::sLogTelemetryURL, "https://prod-triadwars.cloudapp.net/logging/api/v1/log");
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::DataLogger::sLogTelemetryURL__);
}

// File Line: 276
// RVA: 0x253D30
void __fastcall UFG::DataLogger::DataLogger(UFG::DataLogger *this)
{
  UFG::qTreeRB<UFG::Collection,UFG::Collection,1> *p_mCollections; // rsi
  char *mData; // rbx
  unsigned int v4; // eax
  UFG::allocator::free_link *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbx

  this->mActiveWebRequests = 0;
  this->mLastTransmissionSucceeded = 0;
  this->mCurrentCollection = 0i64;
  p_mCollections = &this->mCollections;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mCollections.mTree);
  UFG::qString::qString(&this->mModule);
  UFG::qString::qString(&this->mInstanceId);
  UFG::qString::qString(&this->mSessionId);
  UFG::qString::qString(&this->mCollectionId);
  this->mIsAttachedToSession = 0;
  mData = UFG::DataLogger::sSystemLogCollectionName.mData;
  v4 = UFG::qStringHashUpper32(UFG::DataLogger::sSystemLogCollectionName.mData, -1);
  if ( v4 )
    UFG::qBaseTreeRB::Get(&p_mCollections->mTree, v4);
  v5 = UFG::qMalloc(0xA8ui64, UFG::gGlobalNewName, 0i64);
  if ( v5 )
  {
    UFG::Collection::Collection((UFG::Collection *)v5, mData, 0x800u);
    v7 = v6;
  }
  else
  {
    v7 = 0i64;
  }
  *(_QWORD *)(v7 + 152) = 0i64;
  *(_QWORD *)(v7 + 160) = 0i64;
  *(_QWORD *)(v7 + 120) = UFG::qGetTicks();
  *(_BYTE *)(v7 + 78) = 0;
  UFG::qBaseTreeRB::Add(&p_mCollections->mTree, (UFG::qBaseNodeRB *)v7);
}

// File Line: 299
// RVA: 0x253F30
void UFG::DataLogger::Init(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::DataLogger *v1; // rax

  v0 = UFG::qMalloc(0x100ui64, UFG::gGlobalNewName, 0i64);
  if ( v0 )
  {
    UFG::DataLogger::DataLogger((UFG::DataLogger *)v0);
    UFG::DataLogger::sInstance = v1;
  }
  else
  {
    UFG::DataLogger::sInstance = 0i64;
  }
}

