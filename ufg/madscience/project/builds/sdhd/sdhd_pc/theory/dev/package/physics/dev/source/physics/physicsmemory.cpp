// File Line: 40
// RVA: 0xB87F0
void __fastcall HavokJobMemoryPoolTagger::onStartJob(
        HavokJobMemoryPoolTagger *this,
        hkJobType t,
        unsigned int m_jobSubType)
{
  __int64 v3; // r8
  int v4; // edx
  int v5; // edx
  bool v6; // zf
  char v7; // dl
  __int64 v8; // rax
  const char *v9; // rcx
  char v10; // cl

  v3 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  ++*(_BYTE *)(v3 + 80);
  v4 = t - 9;
  if ( !v4 )
  {
    v9 = "AI::StartJobPathing";
    goto LABEL_8;
  }
  v5 = v4 - 2;
  if ( !v5 )
  {
    v9 = "AI::StartJobDynamic";
LABEL_8:
    v7 = *(_BYTE *)(v3 + 80);
    v8 = v7;
    goto LABEL_9;
  }
  v6 = v5 == 1;
  v7 = *(_BYTE *)(v3 + 80);
  v8 = v7;
  if ( !v6 )
  {
    *(_DWORD *)(v3 + 4i64 * v7) = 3;
    v9 = "Physics::StartJob";
    goto LABEL_10;
  }
  v9 = "AI::StartJobLocal";
LABEL_9:
  *(_DWORD *)(v3 + 4 * v8) = 1;
LABEL_10:
  *(_QWORD *)(v3 + 8 * v8 + 16) = v9;
  *(_QWORD *)(v3 + 8 * v8 + 48) = 0i64;
  v10 = *(_BYTE *)(v3 + 81);
  if ( v7 > v10 )
    v10 = v7;
  *(_BYTE *)(v3 + 81) = v10;
}

// File Line: 69
// RVA: 0xB8070
void __fastcall CustomHavokMemoryAllocator::initDefaultPools(
        CustomHavokMemoryAllocator *this,
        unsigned int maxRigidBodies)
{
  signed int v3; // ebx
  char *v4; // rax
  char *v5; // rax

  this->m_pools[1] = &gAIMemoryPool;
  this->m_pools[2] = &gPhysicsMemoryPool;
  this->m_pools[3] = &gPhysicsMemoryPool;
  v3 = 720 * maxRigidBodies;
  v4 = UFG::qMalloc(0x2460ui64, "qMemoryPool", 0x800ui64);
  if ( v4 )
    UFG::qMemoryPool::qMemoryPool((UFG::qMemoryPool *)v4);
  this->m_pools[0] = (UFG::qMemoryPool *)v4;
  v5 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, v3, "hkpRigidBodyBuffer", 0i64, 1u);
  this->mRigidBodyBuffer = v5;
  UFG::qMemoryPool::Init(this->m_pools[0], "hkpRigidBodyPool", v5, v3, 0, 1, 1u, &gPhysicsMemoryPool, 1, 1);
}

// File Line: 101
// RVA: 0xB6C70
char *__fastcall CustomHavokMemoryAllocator::bufAlloc(CustomHavokMemoryAllocator *this, int *reqNumBytesInOut)
{
  const char *v3; // r8
  __int64 v4; // r10
  unsigned __int64 v5; // rdx
  __int64 v6; // r9
  const char *v7; // rax
  __int64 v8; // rcx
  unsigned __int64 v9; // r9
  UFG::qMemoryPool *v10; // rcx

  v3 = "UnknownHavokAllocation";
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = *reqNumBytesInOut;
  v6 = *(char *)(v4 + 80);
  v7 = *(const char **)(v4 + 8 * v6 + 16);
  v8 = *(int *)(v4 + 4 * v6);
  v9 = *(_QWORD *)(v4 + 8 * v6 + 48);
  v10 = this->m_pools[v8];
  if ( v7 )
    v3 = v7;
  return UFG::qMemoryPool::Allocate(v10, v5, v3, v9, 1u);
}

// File Line: 116
// RVA: 0xB6D20
char *__fastcall CustomHavokMemoryAllocator::bufRealloc(
        CustomHavokMemoryAllocator *this,
        char *pold,
        __int64 oldNumBytes,
        int *reqNumBytesInOut)
{
  unsigned __int64 v6; // r9
  __int64 v8; // rdx
  UFG::qMemoryPool **i; // r8

  v6 = (int)oldNumBytes;
  if ( !pold )
    return (char *)((__int64 (__fastcall *)(CustomHavokMemoryAllocator *, int *, __int64, _QWORD))this->vfptr->bufAlloc)(
                     this,
                     reqNumBytesInOut,
                     oldNumBytes,
                     (int)oldNumBytes);
  v8 = 0i64;
  for ( i = this->m_pools; pold >= (*i)->mEnd || pold < (*i)->mStart; ++i )
  {
    if ( ++v8 >= 4 )
      return 0i64;
  }
  return UFG::qMemoryPool::Realloc(*i, pold, *reqNumBytesInOut, v6, "realloc2", 0i64);
}

// File Line: 180
// RVA: 0xB6710
char *__fastcall CustomHavokMemoryAllocator::blockAlloc(CustomHavokMemoryAllocator *this, int numBytes)
{
  _QWORD *v2; // rax
  __int64 v4; // r10
  const char *v5; // r8
  __int64 v6; // r9
  const char *v7; // rax
  __int64 v8; // rcx
  unsigned __int64 v9; // r9
  UFG::qMemoryPool *v10; // rcx

  v2 = NtCurrentTeb()->Reserved1[11];
  v4 = v2[tls_index] + 16i64;
  v5 = "UnknownHavokAllocation";
  v6 = *(char *)(v2[tls_index] + 96i64);
  v7 = *(const char **)(v4 + 8 * v6 + 16);
  v8 = *(int *)(v4 + 4 * v6);
  v9 = *(_QWORD *)(v4 + 8 * v6 + 48);
  v10 = this->m_pools[v8];
  if ( v7 )
    v5 = v7;
  return UFG::qMemoryPool::Allocate(v10, numBytes, v5, v9, 1u);
}

// File Line: 205
// RVA: 0xB67A0
void __fastcall CustomHavokMemoryAllocator::blockFree(CustomHavokMemoryAllocator *this, char *p, int numBytes)
{
  __int64 v3; // rax
  UFG::qMemoryPool **i; // r9

  if ( p )
  {
    v3 = 0i64;
    for ( i = this->m_pools; p >= (*i)->mEnd || p < (*i)->mStart; ++i )
    {
      if ( ++v3 >= 4 )
      {
        operator delete[](p);
        return;
      }
    }
    UFG::qMemoryPool::Free(*i, p);
  }
}

// File Line: 232
// RVA: 0xB7F50
unsigned __int64 __fastcall CustomHavokMemoryAllocator::getAllocatedSize(
        CustomHavokMemoryAllocator *this,
        char *obj,
        int nbytes)
{
  __int64 v3; // rax
  UFG::qMemoryPool **i; // r9

  v3 = 0i64;
  for ( i = this->m_pools; obj >= (*i)->mEnd || obj < (*i)->mStart; ++i )
  {
    if ( ++v3 >= 4 )
      return 0i64;
  }
  return UFG::qMemoryPool::Size(*i, obj);
}

// File Line: 254
// RVA: 0xB6CE0
char *__fastcall HavokTempMemoryAllocator::bufAlloc(HavokTempMemoryAllocator *this, int *reqNumBytesInOut)
{
  return UFG::qMemoryPool::Allocate(this->mPool, *reqNumBytesInOut, &customCaption, 0i64, 1u);
}

// File Line: 269
// RVA: 0xB6DB0
char *__fastcall HavokTempMemoryAllocator::bufRealloc(
        HavokTempMemoryAllocator *this,
        void *pold,
        int oldNumBytes,
        int *reqNumBytesInOut)
{
  if ( pold )
    return UFG::qMemoryPool::Realloc(this->mPool, pold, *reqNumBytesInOut, oldNumBytes, "realloc3", 0i64);
  else
    return 0i64;
}

// File Line: 292
// RVA: 0x98BC0
void __fastcall HavokTempMemoryAllocator::HavokTempMemoryAllocator(HavokTempMemoryAllocator *this)
{
  char *v2; // rax
  char *v3; // rax

  this->vfptr = (hkMemoryAllocatorVtbl *)&hkMemoryAllocator::`vftable;
  this->vfptr = (hkMemoryAllocatorVtbl *)&HavokTempMemoryAllocator::`vftable;
  v2 = UFG::qMalloc(9312ui64, "qMemoryPool", 2048ui64);
  if ( v2 )
    UFG::qMemoryPool::qMemoryPool((UFG::qMemoryPool *)v2);
  this->mPool = (UFG::qMemoryPool *)v2;
  v3 = UFG::qMemoryPool::Allocate(UFG::gMainMemoryPool, 0x300000ui64, "HavokTempMemoryAllocator", 0i64, 1u);
  this->mBuffer = v3;
  UFG::qMemoryPool::Init(this->mPool, "HavokTmpPool", v3, 0x300000i64, 0x100000, 1, 1u, UFG::gMainMemoryPool, 1, 1);
}

// File Line: 313
// RVA: 0x9C4D0
void __fastcall HavokTempMemoryAllocator::~HavokTempMemoryAllocator(HavokTempMemoryAllocator *this)
{
  UFG::qMemoryPool *mPool; // rcx
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *mPrev; // rdx
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *mNext; // rax

  this->vfptr = (hkMemoryAllocatorVtbl *)&HavokTempMemoryAllocator::`vftable;
  UFG::qMemoryPool::Close(this->mPool);
  mPool = this->mPool;
  if ( mPool )
  {
    mPrev = mPool->mPrev;
    mNext = mPool->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    mPool->mPrev = mPool;
    mPool->mNext = mPool;
    operator delete[](mPool);
  }
  UFG::qMemoryPool::Free(UFG::gMainMemoryPool, this->mBuffer);
  hkMemoryAllocator::~hkMemoryAllocator(this);
}

// File Line: 324
// RVA: 0xB6770
char *__fastcall HavokTempMemoryAllocator::blockAlloc(HavokTempMemoryAllocator *this, int numBytes)
{
  return UFG::qMemoryPool::Allocate(this->mPool, numBytes, &customCaption, 0i64, 1u);
}

// File Line: 335
// RVA: 0xB6D10
void __fastcall HavokTempMemoryAllocator::blockFree(HavokTempMemoryAllocator *this, void *p, int numBytes)
{
  if ( p )
    UFG::qMemoryPool::Free(this->mPool, p);
}

// File Line: 348
// RVA: 0xB7FA0
unsigned __int64 __fastcall HavokTempMemoryAllocator::getAllocatedSize(
        HavokTempMemoryAllocator *this,
        void *obj,
        int nbytes)
{
  return UFG::qMemoryPool::Size(this->mPool, obj);
}

// File Line: 358
// RVA: 0x98770
void __fastcall CustomHavokMemorySystem::CustomHavokMemorySystem(CustomHavokMemorySystem *this)
{
  this->vfptr = (hkMemorySystemVtbl *)&hkMemorySystem::`vftable;
  this->vfptr = (hkMemorySystemVtbl *)&CustomHavokMemorySystem::`vftable;
  this->m_frameInfo = 0i64;
  this->m_allocator = 0i64;
  hkMemoryRouter::hkMemoryRouter(&this->m_mainRouter);
  hkSolverAllocator::hkSolverAllocator(&this->m_solverAllocator);
  HavokTempMemoryAllocator::HavokTempMemoryAllocator(&this->m_tempAllocator);
  CustomHavokMemorySystem::mInstance = this;
}

// File Line: 371
// RVA: 0xB8550
hkMemoryRouter *__fastcall CustomHavokMemorySystem::mainInit(
        CustomHavokMemorySystem *this,
        hkMemorySystem::FrameInfo *info,
        hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  __int64 v5; // rdi
  char v6; // r8
  char v7; // cl
  char *v8; // rax
  char m_storage; // al
  unsigned int m_solverBufferSize; // esi
  void *v11; // rax
  char v12; // al

  v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v6 = ++*(_BYTE *)(v5 + 80);
  *(_DWORD *)(v5 + 4i64 * v6) = 3;
  *(_QWORD *)(v5 + 8i64 * v6 + 16) = "HavokMemorySystem::mainInit";
  *(_QWORD *)(v5 + 8i64 * v6 + 48) = 0i64;
  v7 = *(_BYTE *)(v5 + 81);
  if ( v6 > v7 )
    v7 = v6;
  *(_BYTE *)(v5 + 81) = v7;
  v8 = UFG::qMalloc(4ui64, "FrameInfo", 0i64);
  if ( v8 )
    hkMemorySystem::FrameInfo::FrameInfo((hkMemorySystem::FrameInfo *)v8, info->m_solverBufferSize);
  this->m_frameInfo = (hkMemorySystem::FrameInfo *)v8;
  m_storage = flags.m_storage;
  if ( (flags.m_storage & 1) != 0 )
  {
    ((void (__fastcall *)(CustomHavokMemorySystem *, hkMemoryRouter *, const char *, _QWORD, __int64))this->vfptr->threadInit)(
      this,
      &this->m_mainRouter,
      "main",
      (unsigned int)flags.m_storage,
      -2i64);
    m_storage = flags.m_storage;
  }
  if ( (m_storage & 2) != 0 )
  {
    m_solverBufferSize = this->m_frameInfo->m_solverBufferSize;
    if ( m_solverBufferSize )
    {
      v11 = (void *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&this->m_allocator->vfptr->__vecDelDtor + 1))(
                      this->m_allocator,
                      m_solverBufferSize);
      hkSolverAllocator::setBuffer(&this->m_solverAllocator, v11, m_solverBufferSize);
    }
  }
  v12 = *(_BYTE *)(v5 + 80);
  if ( v12 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v12 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  return &this->m_mainRouter;
}

// File Line: 398
// RVA: 0xB8680
hkResult *__fastcall CustomHavokMemorySystem::mainQuit(
        CustomHavokMemorySystem *this,
        hkResult *result,
        hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  int v5; // edx
  char m_storage; // [rsp+40h] [rbp+18h]

  m_storage = flags.m_storage;
  if ( (flags.m_storage & 2) != 0 )
  {
    v5 = LODWORD(this->m_solverAllocator.m_bufferEnd) - LODWORD(this->m_solverAllocator.m_bufferStart);
    if ( v5 )
    {
      this->m_allocator->vfptr->blockFree(this->m_allocator, this->m_solverAllocator.m_bufferStart, v5);
      hkSolverAllocator::setBuffer(&this->m_solverAllocator, 0i64, 0);
      LOBYTE(flags.m_storage) = m_storage;
    }
  }
  if ( (flags.m_storage & 1) != 0 )
  {
    ((void (__fastcall *)(CustomHavokMemorySystem *, hkMemoryRouter *))this->vfptr->threadQuit)(
      this,
      &this->m_mainRouter);
    this->m_allocator = 0i64;
  }
  result->m_enum = HK_SUCCESS;
  return result;
}

// File Line: 419
// RVA: 0xB8D20
void __fastcall CustomHavokMemorySystem::threadInit(
        CustomHavokMemorySystem *this,
        hkMemoryRouter *router,
        const char *name,
        hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  hkMemoryAllocator *m_allocator; // rax

  if ( (flags.m_storage & 1) != 0 )
  {
    router->m_temp = 0i64;
    router->m_heap = this->m_allocator;
    m_allocator = this->m_allocator;
    router->m_solver = 0i64;
    router->m_debug = m_allocator;
  }
  if ( (flags.m_storage & 2) != 0 )
  {
    hkLifoAllocator::init(&router->m_stack, this->m_allocator, this->m_allocator, this->m_allocator);
    router->m_temp = &this->m_tempAllocator;
    router->m_solver = &this->m_solverAllocator;
  }
}

// File Line: 440
// RVA: 0xB8D90
void __fastcall CustomHavokMemorySystem::threadQuit(
        CustomHavokMemorySystem *this,
        hkMemoryRouter *router,
        hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  char m_storage; // [rsp+40h] [rbp+18h]

  m_storage = flags.m_storage;
  if ( (flags.m_storage & 2) != 0 )
  {
    router->m_temp = 0i64;
    router->m_solver = 0i64;
    hkLifoAllocator::quit(&router->m_stack, 0i64);
    LOBYTE(flags.m_storage) = m_storage;
  }
  if ( (flags.m_storage & 1) != 0 )
    hkMemUtil::memSet(router, 0, 128);
}

// File Line: 477
// RVA: 0xB8980
void __fastcall CustomHavokMemorySystem::printStatistics(CustomHavokMemorySystem *this, hkOstream *ostr)
{
  hkMemoryAllocator *m_allocator; // rcx
  _BYTE v3[56]; // [rsp+20h] [rbp-38h] BYREF

  m_allocator = this->m_allocator;
  memset(v3, 255, 48);
  m_allocator->vfptr->getMemoryStatistics(m_allocator, (hkMemoryAllocator::MemoryStatistics *)v3);
}

