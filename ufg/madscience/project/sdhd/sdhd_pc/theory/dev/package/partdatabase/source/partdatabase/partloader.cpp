// File Line: 28
// RVA: 0x1542F0
void __fastcall UFG::PartLoader::PartLoader(UFG::PartLoader *this)
{
  UFG::PartLoader *v1; // rbx

  v1 = this;
  this->mPartsDirty = 0;
  *(_QWORD *)&this->mPartCount = 0i64;
  `eh vector constructor iterator(this->mTextureSets, 4ui64, 32, (void (__fastcall *)(void *))BackInfo::BackInfo);
  v1->mRequestsLoadedFlags.mBits[0] = 0i64;
  v1->mRequestsDispatchEventFlags.mBits[0] = 0i64;
  v1->mPriority = 4;
  v1->mOnLoadEventCallback = 0i64;
  v1->mOnForceRemovedCallback = 0i64;
  v1->mUserContext = 0i64;
}

// File Line: 32
// RVA: 0x155330
void __fastcall UFG::PartLoader::~PartLoader(UFG::PartLoader *this)
{
  UFG::PartLoader *v1; // rbx

  v1 = this;
  UFG::PartLoader::Unload(this);
  `eh vector destructor iterator(v1->mTextureSets, 4ui64, 32, (void (__fastcall *)(void *))_);
}

// File Line: 37
// RVA: 0x159520
char __fastcall UFG::PartLoader::IsLoaded(UFG::PartLoader *this)
{
  unsigned int v1; // er8
  UFG::PartLoader *v2; // rdx
  unsigned int v4; // ecx
  signed __int64 v5; // rdx

  v1 = this->mPartRequestCount;
  v2 = this;
  if ( !v1 )
    return 0;
  v4 = 0;
  if ( v1 )
  {
    v5 = (signed __int64)v2->mPartRequests;
    while ( *(_DWORD *)(*(_QWORD *)v5 + 80i64) == 3 )
    {
      ++v4;
      v5 += 8i64;
      if ( v4 >= v1 )
        return 1;
    }
    return 0;
  }
  return 1;
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
  return (UFG::qSymbolUC *)((char *)this + 4 * (index + 68i64));
}

// File Line: 64
// RVA: 0x15AD40
void __fastcall UFG::PartLoader::SetCallbacks(UFG::PartLoader *this, void (__fastcall *loadCallback)(void *, UFG::PartRequest *, bool), void (__fastcall *removedCallback)(void *, UFG::PartRequest *), void *context)
{
  this->mOnLoadEventCallback = loadCallback;
  this->mOnForceRemovedCallback = removedCallback;
  this->mUserContext = context;
}

// File Line: 71
// RVA: 0x159E60
void __fastcall UFG::PartLoader::QueueLoad(UFG::PartLoader *this)
{
  __int64 v1; // rdi
  UFG::PartLoader *v2; // rbx
  UFG::PartRequest *v3; // rdx
  __int64 v4; // rax
  __int64 v5; // r8
  signed __int64 v6; // rax
  signed __int64 v7; // rdx
  __int64 v8; // r8
  __int64 v9; // rax

  v1 = 0i64;
  v2 = this;
  if ( this->mPartCount )
  {
    do
    {
      v3 = UFG::PartPool::RequestLoadPart(&UFG::PartDatabase::sInstance->mPool, v2->mParts[v1], v2);
      if ( v3->mLoadStatus == 3 )
      {
        v4 = v2->mPartRequestCount;
        v5 = 0i64;
        if ( (_DWORD)v4 )
        {
          while ( v2->mPartRequests[v5] != v3 )
          {
            v5 = (unsigned int)(v5 + 1);
            if ( (unsigned int)v5 >= (unsigned int)v4 )
              goto LABEL_6;
          }
          v6 = (signed __int64)(signed int)v5 >> 6;
          v7 = 1i64 << (v5 & 0x3F);
          v2->mRequestsLoadedFlags.mBits[v6] |= v7;
          v2->mRequestsDispatchEventFlags.mBits[v6] |= v7;
          v2->mPartsDirty = 1;
          goto LABEL_13;
        }
LABEL_6:
        v2->mPartRequests[v4] = v3;
        v2->mRequestsLoadedFlags.mBits[(signed __int64)(signed int)v2->mPartRequestCount >> 6] |= 1i64 << (v2->mPartRequestCount & 0x3F);
        v2->mRequestsDispatchEventFlags.mBits[(signed __int64)(signed int)v2->mPartRequestCount >> 6] |= 1i64 << (v2->mPartRequestCount & 0x3F);
        v2->mPartsDirty = 1;
      }
      else
      {
        v8 = v2->mPartRequestCount;
        v9 = 0i64;
        if ( (_DWORD)v8 )
        {
          while ( v2->mPartRequests[v9] != v3 )
          {
            v9 = (unsigned int)(v9 + 1);
            if ( (unsigned int)v9 >= (unsigned int)v8 )
              goto LABEL_11;
          }
          v2->mRequestsLoadedFlags.mBits[(signed __int64)(signed int)v9 >> 6] &= ~(1i64 << (v9 & 0x3F));
          goto LABEL_13;
        }
LABEL_11:
        v2->mPartRequests[v8] = v3;
        v2->mRequestsLoadedFlags.mBits[(signed __int64)(signed int)v2->mPartRequestCount >> 6] &= ~(1i64 << (v2->mPartRequestCount & 0x3F));
      }
      ++v2->mPartRequestCount;
LABEL_13:
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->mPartCount );
  }
}

// File Line: 80
// RVA: 0x15B0D0
void __fastcall UFG::PartLoader::Unload(UFG::PartLoader *this)
{
  unsigned int v1; // eax
  UFG::PartLoader *v2; // rbx
  __int64 v3; // rdi
  void (__fastcall *v4)(void *, UFG::PartRequest *, bool); // rax
  UFG::PartRequest *v5; // rsi

  v1 = this->mPartRequestCount;
  v2 = this;
  if ( v1 )
  {
    v3 = 0i64;
    if ( v1 )
    {
      do
      {
        v4 = v2->mOnLoadEventCallback;
        v5 = v2->mPartRequests[v3];
        if ( v4 )
          v4(v2->mUserContext, v2->mPartRequests[v3], 0);
        UFG::PartPool::RequestUnLoadPart(
          &UFG::PartDatabase::sInstance->mPool,
          (UFG::PartDefinition *)v5->mPartDefHandle.mData,
          v2);
        v3 = (unsigned int)(v3 + 1);
      }
      while ( (unsigned int)v3 < v2->mPartRequestCount );
    }
    v2->mRequestsLoadedFlags.mBits[0] = 0i64;
    v2->mRequestsDispatchEventFlags.mBits[0] = 0i64;
    v2->mPartRequestCount = 0;
  }
}

// File Line: 97
// RVA: 0x159DD0
void __fastcall UFG::PartLoader::PropagatePartEvents(UFG::PartLoader *this, __int64 a2, _BOOL8 a3)
{
  UFG::PartLoader *v3; // rbx
  __int64 v4; // rdi
  signed __int64 v5; // rax
  signed __int64 v6; // rdx
  void (__fastcall *v7)(void *, UFG::PartRequest *, bool); // r9

  v3 = this;
  if ( this->mPartsDirty )
  {
    v4 = 0i64;
    if ( this->mPartRequestCount )
    {
      do
      {
        v5 = (signed __int64)(signed int)v4 >> 6;
        v6 = 1i64 << (v4 & 0x3F);
        if ( v6 & v3->mRequestsDispatchEventFlags.mBits[v5] )
        {
          v7 = v3->mOnLoadEventCallback;
          if ( v7 )
          {
            LOBYTE(a3) = (v6 & v3->mRequestsLoadedFlags.mBits[v5]) != 0;
            v7(v3->mUserContext, v3->mPartRequests[v4], a3);
          }
        }
        v4 = (unsigned int)(v4 + 1);
      }
      while ( (unsigned int)v4 < v3->mPartRequestCount );
    }
    v3->mRequestsDispatchEventFlags.mBits[0] = 0i64;
    v3->mPartsDirty = 0;
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
  UFG::PartLoader *v1; // rbx

  v1 = this;
  UFG::PartLoader::Unload(this);
  v1->mPartCount = 0;
}

