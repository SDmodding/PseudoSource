// File Line: 28
// RVA: 0x1542F0
void __fastcall UFG::PartLoader::PartLoader(UFG::PartLoader *this)
{
  this->mPartsDirty = 0;
  *(_QWORD *)&this->mPartCount = 0i64;
  `eh vector constructor iterator(this->mTextureSets, 4ui64, 32, (void (__fastcall *)(void *))BackInfo::BackInfo);
  this->mRequestsLoadedFlags.mBits[0] = 0i64;
  this->mRequestsDispatchEventFlags.mBits[0] = 0i64;
  this->mPriority = Low;
  this->mOnLoadEventCallback = 0i64;
  this->mOnForceRemovedCallback = 0i64;
  this->mUserContext = 0i64;
}

// File Line: 32
// RVA: 0x155330
void __fastcall UFG::PartLoader::~PartLoader(UFG::PartLoader *this)
{
  UFG::PartLoader::Unload(this);
  `eh vector destructor iterator(this->mTextureSets, 4ui64, 32, (void (__fastcall *)(void *))_);
}

// File Line: 37
// RVA: 0x159520
char __fastcall UFG::PartLoader::IsLoaded(UFG::PartLoader *this)
{
  unsigned int mPartRequestCount; // r8d
  int v4; // ecx
  UFG::PartRequest **i; // rdx

  mPartRequestCount = this->mPartRequestCount;
  if ( mPartRequestCount )
  {
    v4 = 0;
    for ( i = this->mPartRequests; (*i)->mLoadStatus == Loaded; ++i )
    {
      if ( ++v4 >= mPartRequestCount )
        return 1;
    }
  }
  return 0;
}

// File Line: 52
// RVA: 0x158D40
UFG::PartDefinition *__fastcall UFG::PartLoader::GetPart(UFG::PartLoader *this, unsigned int index)
{
  return this->mParts[index];
}

// File Line: 58
// RVA: 0x158DA0
UFG::qSymbolUC *__fastcall UFG::PartLoader::GetPartTextureSet(UFG::PartLoader *this, unsigned int index)
{
  return &this->mTextureSets[index];
}

// File Line: 64
// RVA: 0x15AD40
void __fastcall UFG::PartLoader::SetCallbacks(
        UFG::PartLoader *this,
        void (__fastcall *loadCallback)(void *, UFG::PartRequest *, bool),
        void (__fastcall *removedCallback)(void *, UFG::PartRequest *),
        void *context)
{
  this->mOnLoadEventCallback = loadCallback;
  this->mOnForceRemovedCallback = removedCallback;
  this->mUserContext = context;
}

// File Line: 71
// RVA: 0x159E60
void __fastcall UFG::PartLoader::QueueLoad(UFG::PartLoader *this)
{
  __int64 i; // rdi
  UFG::PartRequest *Part; // rdx
  __int64 mPartRequestCount; // rax
  __int64 v5; // r8
  __int64 v6; // rax
  __int64 v7; // rdx
  __int64 v8; // r8
  __int64 v9; // rax

  for ( i = 0i64; (unsigned int)i < this->mPartCount; i = (unsigned int)(i + 1) )
  {
    Part = UFG::PartPool::RequestLoadPart(&UFG::PartDatabase::sInstance->mPool, this->mParts[i], this);
    if ( Part->mLoadStatus == Loaded )
    {
      mPartRequestCount = this->mPartRequestCount;
      v5 = 0i64;
      if ( (_DWORD)mPartRequestCount )
      {
        while ( this->mPartRequests[v5] != Part )
        {
          v5 = (unsigned int)(v5 + 1);
          if ( (unsigned int)v5 >= (unsigned int)mPartRequestCount )
            goto LABEL_6;
        }
        v6 = (__int64)(int)v5 >> 6;
        v7 = 1i64 << (v5 & 0x3F);
        this->mRequestsLoadedFlags.mBits[v6] |= v7;
        this->mRequestsDispatchEventFlags.mBits[v6] |= v7;
        this->mPartsDirty = 1;
        continue;
      }
LABEL_6:
      this->mPartRequests[mPartRequestCount] = Part;
      this->mRequestsLoadedFlags.mBits[(__int64)(int)this->mPartRequestCount >> 6] |= 1i64 << (this->mPartRequestCount & 0x3F);
      this->mRequestsDispatchEventFlags.mBits[(__int64)(int)this->mPartRequestCount >> 6] |= 1i64 << (this->mPartRequestCount & 0x3F);
      this->mPartsDirty = 1;
    }
    else
    {
      v8 = this->mPartRequestCount;
      v9 = 0i64;
      if ( (_DWORD)v8 )
      {
        while ( this->mPartRequests[v9] != Part )
        {
          v9 = (unsigned int)(v9 + 1);
          if ( (unsigned int)v9 >= (unsigned int)v8 )
            goto LABEL_11;
        }
        this->mRequestsLoadedFlags.mBits[(__int64)(int)v9 >> 6] &= ~(1i64 << (v9 & 0x3F));
        continue;
      }
LABEL_11:
      this->mPartRequests[v8] = Part;
      this->mRequestsLoadedFlags.mBits[(__int64)(int)this->mPartRequestCount >> 6] &= ~(1i64 << (this->mPartRequestCount & 0x3F));
    }
    ++this->mPartRequestCount;
  }
}

// File Line: 80
// RVA: 0x15B0D0
void __fastcall UFG::PartLoader::Unload(UFG::PartLoader *this)
{
  __int64 v2; // rdi
  void (__fastcall *mOnLoadEventCallback)(void *, UFG::PartRequest *, bool); // rax
  UFG::PartRequest *v4; // rsi

  if ( this->mPartRequestCount )
  {
    v2 = 0i64;
    do
    {
      mOnLoadEventCallback = this->mOnLoadEventCallback;
      v4 = this->mPartRequests[v2];
      if ( mOnLoadEventCallback )
        mOnLoadEventCallback(this->mUserContext, this->mPartRequests[v2], 0);
      UFG::PartPool::RequestUnLoadPart(
        &UFG::PartDatabase::sInstance->mPool,
        (UFG::PartDefinition *)v4->mPartDefHandle.mData,
        this);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < this->mPartRequestCount );
    this->mRequestsLoadedFlags.mBits[0] = 0i64;
    this->mRequestsDispatchEventFlags.mBits[0] = 0i64;
    this->mPartRequestCount = 0;
  }
}

// File Line: 97
// RVA: 0x159DD0
void __fastcall UFG::PartLoader::PropagatePartEvents(UFG::PartLoader *this, __int64 a2, _BOOL8 a3)
{
  __int64 i; // rdi
  __int64 v5; // rax
  __int64 v6; // rdx
  void (__fastcall *mOnLoadEventCallback)(void *, UFG::PartRequest *, bool); // r9

  if ( this->mPartsDirty )
  {
    for ( i = 0i64; (unsigned int)i < this->mPartRequestCount; i = (unsigned int)(i + 1) )
    {
      v5 = (__int64)(int)i >> 6;
      v6 = 1i64 << (i & 0x3F);
      if ( (v6 & this->mRequestsDispatchEventFlags.mBits[v5]) != 0 )
      {
        mOnLoadEventCallback = this->mOnLoadEventCallback;
        if ( mOnLoadEventCallback )
        {
          LOBYTE(a3) = (v6 & this->mRequestsLoadedFlags.mBits[v5]) != 0;
          mOnLoadEventCallback(this->mUserContext, this->mPartRequests[i], a3);
        }
      }
    }
    this->mRequestsDispatchEventFlags.mBits[0] = 0i64;
    this->mPartsDirty = 0;
  }
}

// File Line: 113
// RVA: 0x1562A0
void __fastcall UFG::PartLoader::AddPart(UFG::PartLoader *this, UFG::PartDefinition *part, UFG::qSymbolUC *textureSet)
{
  this->mParts[this->mPartCount] = part;
  this->mTextureSets[this->mPartCount++] = (UFG::qSymbolUC)textureSet->mUID;
}

// File Line: 149
// RVA: 0x15A850
void __fastcall UFG::PartLoader::Reset(UFG::PartLoader *this)
{
  UFG::PartLoader::Unload(this);
  this->mPartCount = 0;
}

