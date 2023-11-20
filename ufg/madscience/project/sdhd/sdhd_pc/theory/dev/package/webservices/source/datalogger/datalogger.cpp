// File Line: 55
// RVA: 0x253E70
void __fastcall UFG::StringBuffer::~StringBuffer(UFG::StringBuffer *this)
{
  UFG::StringBuffer *v1; // rbx
  char *v2; // rcx

  v1 = this;
  v2 = this->mBuffer;
  if ( v2 )
  {
    operator delete[](v2);
    v1->mBuffer = 0i64;
  }
}

// File Line: 148
// RVA: 0x253C60
void __fastcall UFG::Collection::Collection(UFG::Collection *this, const char *collectionName, unsigned int bufferSize)
{
  unsigned int v3; // edi
  const char *v4; // rbx
  UFG::Collection *v5; // rsi
  unsigned int v6; // eax
  UFG::allocator::free_link *v7; // rax

  v3 = bufferSize;
  v4 = collectionName;
  v5 = this;
  v6 = UFG::qStringHashUpper32(collectionName, 0xFFFFFFFF);
  v5->mNode.mParent = 0i64;
  v5->mNode.mChild[0] = 0i64;
  v5->mNode.mChild[1] = 0i64;
  v5->mNode.mUID = v6;
  UFG::qString::qString(&v5->mName, v4);
  *(_DWORD *)&v5->mListOpen = 0;
  *(_WORD *)&v5->mMetaDataOpen = 0;
  v5->mIsBuffered = 0;
  UFG::qString::qString(&v5->mCurrentEvent);
  v5->mLastTransmission = 0i64;
  v5->mBuffer.mBuffer = 0i64;
  v5->mBuffer.mCurrentOffset = 0i64;
  v5->mBuffer.mBufferSize = 0;
  v5->mPerSessionMetaDataFunction = 0i64;
  v5->mPerFrameMetaDataFunction = 0i64;
  v7 = UFG::qMalloc(v3, "DataLogger::StringBuffer", 0i64);
  v5->mBuffer.mBuffer = (char *)v7;
  v5->mBuffer.mBufferSize = v3;
  v5->mBuffer.mCurrentOffset = (char *)v7;
  LOBYTE(v7->mNext) = 0;
}

// File Line: 267
// RVA: 0x1476070
__int64 dynamic_initializer_for__UFG::DataLogger::sSystemLogCollectionName__()
{
  UFG::qString::qString(&UFG::DataLogger::sSystemLogCollectionName, "SystemLog");
  return atexit(dynamic_atexit_destructor_for__UFG::DataLogger::sSystemLogCollectionName__);
}

// File Line: 268
// RVA: 0x1476010
__int64 dynamic_initializer_for__UFG::DataLogger::sLogMessageURL__()
{
  UFG::qString::qString(&UFG::DataLogger::sLogMessageURL, "https://prod-triadwars.cloudapp.net/logging/api/v1/message");
  return atexit(dynamic_atexit_destructor_for__UFG::DataLogger::sLogMessageURL__);
}

// File Line: 269
// RVA: 0x1476040
__int64 dynamic_initializer_for__UFG::DataLogger::sLogTelemetryURL__()
{
  UFG::qString::qString(&UFG::DataLogger::sLogTelemetryURL, "https://prod-triadwars.cloudapp.net/logging/api/v1/log");
  return atexit(dynamic_atexit_destructor_for__UFG::DataLogger::sLogTelemetryURL__);
}

// File Line: 276
// RVA: 0x253D30
void __fastcall UFG::DataLogger::DataLogger(UFG::DataLogger *this)
{
  UFG::DataLogger *v1; // rdi
  UFG::qBaseTreeRB *v2; // rsi
  char *v3; // rbx
  unsigned int v4; // eax
  UFG::allocator::free_link *v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbx

  v1 = this;
  this->mActiveWebRequests = 0;
  this->mLastTransmissionSucceeded = 0;
  this->mCurrentCollection = 0i64;
  v2 = &this->mCollections.mTree;
  UFG::qBaseTreeRB::qBaseTreeRB(&this->mCollections.mTree);
  UFG::qString::qString(&v1->mModule);
  UFG::qString::qString(&v1->mInstanceId);
  UFG::qString::qString(&v1->mSessionId);
  UFG::qString::qString(&v1->mCollectionId);
  v1->mIsAttachedToSession = 0;
  v3 = UFG::DataLogger::sSystemLogCollectionName.mData;
  v4 = UFG::qStringHashUpper32(UFG::DataLogger::sSystemLogCollectionName.mData, 0xFFFFFFFF);
  if ( v4 )
    UFG::qBaseTreeRB::Get(v2, v4);
  v5 = UFG::qMalloc(0xA8ui64, UFG::gGlobalNewName, 0i64);
  if ( v5 )
  {
    UFG::Collection::Collection((UFG::Collection *)v5, v3, 0x800u);
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
  UFG::qBaseTreeRB::Add(v2, (UFG::qBaseNodeRB *)v7);
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

