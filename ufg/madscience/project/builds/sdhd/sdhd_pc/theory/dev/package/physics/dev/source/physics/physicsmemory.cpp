// File Line: 40
// RVA: 0xB87F0
void __fastcall HavokJobMemoryPoolTagger::onStartJob(HavokJobMemoryPoolTagger *this, hkJobType t, unsigned int m_jobSubType)
{
  signed __int64 v3; // r8
  __int32 v4; // edx
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
void __fastcall CustomHavokMemoryAllocator::initDefaultPools(CustomHavokMemoryAllocator *this, unsigned int maxRigidBodies)
{
  CustomHavokMemoryAllocator *v2; // rdi
  signed int v3; // ebx
  char *v4; // rax
  char *v5; // rax

  v2 = this;
  this->m_pools[1] = &gAIMemoryPool;
  this->m_pools[2] = &gPhysicsMemoryPool;
  this->m_pools[3] = &gPhysicsMemoryPool;
  v3 = 720 * maxRigidBodies;
  v4 = UFG::qMalloc(0x2460ui64, "qMemoryPool", 0x800ui64);
  if ( v4 )
    UFG::qMemoryPool::qMemoryPool((UFG::qMemoryPool *)v4);
  v2->m_pools[0] = (UFG::qMemoryPool *)v4;
  v5 = UFG::qMemoryPool::Allocate(&gPhysicsMemoryPool, v3, "hkpRigidBodyBuffer", 0i64, 1u);
  v2->mRigidBodyBuffer = v5;
  UFG::qMemoryPool::Init(v2->m_pools[0], "hkpRigidBodyPool", v5, v3, 0, 1, 1u, &gPhysicsMemoryPool, 1, 1);
}

// File Line: 101
// RVA: 0xB6C70
char *__fastcall CustomHavokMemoryAllocator::bufAlloc(CustomHavokMemoryAllocator *this, int *reqNumBytesInOut)
{
  CustomHavokMemoryAllocator *v2; // rbx
  const char *v3; // r8
  signed __int64 v4; // r10
  unsigned __int64 v5; // rdx
  __int64 v6; // r9
  const char *v7; // rax
  __int64 v8; // rcx
  unsigned __int64 v9; // r9
  UFG::qMemoryPool *v10; // rcx

  v2 = this;
  v3 = "UnknownHavokAllocation";
  v4 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v5 = *reqNumBytesInOut;
  v6 = *(char *)(v4 + 80);
  v7 = *(const char **)(v4 + 8 * v6 + 16);
  v8 = *(signed int *)(v4 + 4 * v6);
  v9 = *(_QWORD *)(v4 + 8 * v6 + 48);
  v10 = v2->m_pools[v8];
  if ( v7 )
    v3 = v7;
  return UFG::qMemoryPool::Allocate(v10, v5, v3, v9, 1u);
}

// File Line: 116
// RVA: 0xB6D20
char *__fastcall CustomHavokMemoryAllocator::bufRealloc(CustomHavokMemoryAllocator *this, void *pold, __int64 oldNumBytes, int *reqNumBytesInOut)
{
  int *v4; // rbx
  char *v5; // r11
  unsigned __int64 v6; // r9
  signed __int64 v8; // rdx
  UFG::qMemoryPool **v9; // r8

  v4 = reqNumBytesInOut;
  v5 = (char *)pold;
  v6 = (signed int)oldNumBytes;
  if ( !pold )
    return (char *)((__int64 (__fastcall *)(CustomHavokMemoryAllocator *, int *, __int64, _QWORD))this->vfptr->bufAlloc)(
                     this,
                     v4,
                     oldNumBytes,
                     (signed int)oldNumBytes);
  v8 = 0i64;
  v9 = this->m_pools;
  while ( v5 >= (*v9)->mEnd || v5 < (*v9)->mStart )
  {
    ++v8;
    ++v9;
    if ( v8 >= 4 )
      return 0i64;
  }
  return UFG::qMemoryPool::Realloc(*v9, v5, *v4, v6, "realloc2", 0i64);
}

// File Line: 180
// RVA: 0xB6710
char *__fastcall CustomHavokMemoryAllocator::blockAlloc(CustomHavokMemoryAllocator *this, __int64 numBytes)
{
  _QWORD *v2; // rax
  CustomHavokMemoryAllocator *v3; // r11
  signed __int64 v4; // r10
  const char *v5; // r8
  __int64 v6; // r9
  const char *v7; // rax
  __int64 v8; // rcx
  unsigned __int64 v9; // r9
  UFG::qMemoryPool *v10; // rcx

  v2 = NtCurrentTeb()->Reserved1[11];
  v3 = this;
  numBytes = (signed int)numBytes;
  v4 = v2[tls_index] + 16i64;
  v5 = "UnknownHavokAllocation";
  v6 = *(char *)(v2[tls_index] + 96i64);
  v7 = *(const char **)(v4 + 8 * v6 + 16);
  v8 = *(signed int *)(v4 + 4 * v6);
  v9 = *(_QWORD *)(v4 + 8 * v6 + 48);
  v10 = v3->m_pools[v8];
  if ( v7 )
    v5 = v7;
  return UFG::qMemoryPool::Allocate(v10, numBytes, v5, v9, 1u);
}

// File Line: 205
// RVA: 0xB67A0
void __fastcall CustomHavokMemoryAllocator::blockFree(CustomHavokMemoryAllocator *this, void *p, int numBytes)
{
  signed __int64 v3; // rax
  UFG::qMemoryPool **v4; // r9

  if ( p )
  {
    v3 = 0i64;
    v4 = this->m_pools;
    while ( p >= (*v4)->mEnd || p < (*v4)->mStart )
    {
      ++v3;
      ++v4;
      if ( v3 >= 4 )
      {
        operator delete[](p);
        return;
      }
    }
    UFG::qMemoryPool::Free(*v4, p);
  }
}

// File Line: 232
// RVA: 0xB7F50
unsigned __int64 __fastcall CustomHavokMemoryAllocator::getAllocatedSize(CustomHavokMemoryAllocator *this, const void *obj, int nbytes)
{
  signed __int64 v3; // rax
  UFG::qMemoryPool **v4; // r9

  v3 = 0i64;
  v4 = this->m_pools;
  while ( obj >= (*v4)->mEnd || obj < (*v4)->mStart )
  {
    ++v3;
    ++v4;
    if ( v3 >= 4 )
      return 0i64;
  }
  return UFG::qMemoryPool::Size(*v4, (void *)obj);
}

// File Line: 254
// RVA: 0xB6CE0
char *__fastcall HavokTempMemoryAllocator::bufAlloc(HavokTempMemoryAllocator *this, int *reqNumBytesInOut)
{
  return UFG::qMemoryPool::Allocate(this->mPool, *reqNumBytesInOut, &customWorldMapCaption, 0i64, 1u);
}

// File Line: 269
// RVA: 0xB6DB0
char *__fastcall HavokTempMemoryAllocator::bufRealloc(HavokTempMemoryAllocator *this, void *pold, int oldNumBytes, int *reqNumBytesInOut)
{
  char *result; // rax

  if ( pold )
    result = UFG::qMemoryPool::Realloc(this->mPool, pold, *reqNumBytesInOut, oldNumBytes, "realloc3", 0i64);
  else
    result = 0i64;
  return result;
}

// File Line: 292
// RVA: 0x98BC0
void __fastcall HavokTempMemoryAllocator::HavokTempMemoryAllocator(HavokTempMemoryAllocator *this)
{
  HavokTempMemoryAllocator *v1; // rbx
  char *v2; // rax
  char *v3; // rax

  v1 = this;
  this->vfptr = (hkMemoryAllocatorVtbl *)&hkMemoryAllocator::`vftable;
  this->vfptr = (hkMemoryAllocatorVtbl *)&HavokTempMemoryAllocator::`vftable;
  v2 = UFG::qMalloc(9312ui64, "qMemoryPool", 2048ui64);
  if ( v2 )
    UFG::qMemoryPool::qMemoryPool((UFG::qMemoryPool *)v2);
  v1->mPool = (UFG::qMemoryPool *)v2;
  v3 = UFG::qMemoryPool::Allocate(UFG::gMainMemoryPool, 0x300000ui64, "HavokTempMemoryAllocator", 0i64, 1u);
  v1->mBuffer = v3;
  UFG::qMemoryPool::Init(v1->mPool, "HavokTmpPool", v3, 0x300000i64, 0x100000, 1, 1u, UFG::gMainMemoryPool, 1, 1);
}

// File Line: 313
// RVA: 0x9C4D0
void __fastcall HavokTempMemoryAllocator::~HavokTempMemoryAllocator(HavokTempMemoryAllocator *this)
{
  HavokTempMemoryAllocator *v1; // rbx
  UFG::qMemoryPool *v2; // rcx
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *v3; // rdx
  UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *v4; // rax

  v1 = this;
  this->vfptr = (hkMemoryAllocatorVtbl *)&HavokTempMemoryAllocator::`vftable;
  UFG::qMemoryPool::Close(this->mPool);
  v2 = v1->mPool;
  if ( v2 )
  {
    v3 = v2->mPrev;
    v4 = v2->mNext;
    v3->mNext = v4;
    v4->mPrev = v3;
    v2->mPrev = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&v2->mPrev;
    v2->mNext = (UFG::qNode<UFG::qMemoryPool,UFG::qMemoryPool> *)&v2->mPrev;
    operator delete[](v2);
  }
  UFG::qMemoryPool::Free(UFG::gMainMemoryPool, v1->mBuffer);
  hkMemoryAllocator::~hkMemoryAllocator((hkMemoryAllocator *)&v1->vfptr);
}

// File Line: 324
// RVA: 0xB6770
char *__fastcall HavokTempMemoryAllocator::blockAlloc(HavokTempMemoryAllocator *this, int numBytes)
{
  return UFG::qMemoryPool::Allocate(this->mPool, numBytes, &customWorldMapCaption, 0i64, 1u);
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
unsigned __int64 __fastcall HavokTempMemoryAllocator::getAllocatedSize(HavokTempMemoryAllocator *this, const void *obj, int nbytes)
{
  return UFG::qMemoryPool::Size(this->mPool, (void *)obj);
}

// File Line: 358
// RVA: 0x98770
void __fastcall CustomHavokMemorySystem::CustomHavokMemorySystem(CustomHavokMemorySystem *this)
{
  CustomHavokMemorySystem *v1; // rbx

  v1 = this;
  this->vfptr = (hkMemorySystemVtbl *)&hkMemorySystem::`vftable;
  this->vfptr = (hkMemorySystemVtbl *)&CustomHavokMemorySystem::`vftable;
  this->m_frameInfo = 0i64;
  this->m_allocator = 0i64;
  hkMemoryRouter::hkMemoryRouter(&this->m_mainRouter);
  hkSolverAllocator::hkSolverAllocator(&v1->m_solverAllocator);
  HavokTempMemoryAllocator::HavokTempMemoryAllocator(&v1->m_tempAllocator);
  CustomHavokMemorySystem::mInstance = v1;
}

// File Line: 371
// RVA: 0xB8550
hkMemoryRouter *__fastcall CustomHavokMemorySystem::mainInit(CustomHavokMemorySystem *this, hkMemorySystem::FrameInfo *info, hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  hkMemorySystem::FrameInfo *v3; // rsi
  CustomHavokMemorySystem *v4; // rbx
  signed __int64 v5; // rdi
  char v6; // r8
  __int64 v7; // rax
  char v8; // cl
  char *v9; // rax
  char v10; // al
  unsigned int v11; // esi
  void *v12; // rax
  char v13; // al
  unsigned int v15; // [rsp+50h] [rbp+18h]

  v15 = flags.m_storage;
  v3 = info;
  v4 = this;
  v5 = *((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 16i64;
  v6 = ++*(_BYTE *)(v5 + 80);
  v7 = v6;
  *(_DWORD *)(v5 + 4 * v7) = 3;
  *(_QWORD *)(v5 + 8 * v7 + 16) = "HavokMemorySystem::mainInit";
  *(_QWORD *)(v5 + 8 * v7 + 48) = 0i64;
  v8 = *(_BYTE *)(v5 + 81);
  if ( v6 > v8 )
    v8 = v6;
  *(_BYTE *)(v5 + 81) = v8;
  v9 = UFG::qMalloc(4ui64, "FrameInfo", 0i64);
  if ( v9 )
    hkMemorySystem::FrameInfo::FrameInfo((hkMemorySystem::FrameInfo *)v9, v3->m_solverBufferSize);
  v4->m_frameInfo = (hkMemorySystem::FrameInfo *)v9;
  v10 = v15;
  if ( v15 & 1 )
  {
    ((void (__fastcall *)(CustomHavokMemorySystem *, hkMemoryRouter *, const char *, _QWORD, signed __int64))v4->vfptr->threadInit)(
      v4,
      &v4->m_mainRouter,
      "main",
      v15,
      -2i64);
    v10 = v15;
  }
  if ( v10 & 2 )
  {
    v11 = v4->m_frameInfo->m_solverBufferSize;
    if ( v11 )
    {
      v12 = (void *)(*((__int64 (__fastcall **)(hkMemoryAllocator *, _QWORD))&v4->m_allocator->vfptr->__vecDelDtor + 1))(
                      v4->m_allocator,
                      v11);
      hkSolverAllocator::setBuffer(&v4->m_solverAllocator, v12, v11);
    }
  }
  v13 = *(_BYTE *)(v5 + 80);
  if ( v13 > 0 )
  {
    *(_BYTE *)(v5 + 80) = v13 - 1;
  }
  else
  {
    *(_BYTE *)(v5 + 80) = 0;
    *(_DWORD *)v5 = 3;
    *(_QWORD *)(v5 + 16) = 0i64;
    *(_QWORD *)(v5 + 48) = 0i64;
  }
  return &v4->m_mainRouter;
}

// File Line: 398
// RVA: 0xB8680
hkResult *__fastcall CustomHavokMemorySystem::mainQuit(CustomHavokMemorySystem *this, hkResult *result, hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  hkResult *v3; // rdi
  CustomHavokMemorySystem *v4; // rbx
  int v6; // [rsp+40h] [rbp+18h]

  v6 = flags.m_storage;
  v3 = result;
  v4 = this;
  if ( flags.m_storage & 2
    && LODWORD(this->m_solverAllocator.m_bufferEnd) != LODWORD(this->m_solverAllocator.m_bufferStart) )
  {
    this->m_allocator->vfptr->blockFree(
      this->m_allocator,
      this->m_solverAllocator.m_bufferStart,
      LODWORD(this->m_solverAllocator.m_bufferEnd) - LODWORD(this->m_solverAllocator.m_bufferStart));
    hkSolverAllocator::setBuffer(&v4->m_solverAllocator, 0i64, 0);
    LOBYTE(flags.m_storage) = v6;
  }
  if ( flags.m_storage & 1 )
  {
    ((void (__fastcall *)(CustomHavokMemorySystem *, hkMemoryRouter *))v4->vfptr->threadQuit)(v4, &v4->m_mainRouter);
    v4->m_allocator = 0i64;
  }
  v3->m_enum = 0;
  return v3;
}

// File Line: 419
// RVA: 0xB8D20
void __fastcall CustomHavokMemorySystem::threadInit(CustomHavokMemorySystem *this, hkMemoryRouter *router, const char *name, hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  hkMemoryRouter *v4; // rbx
  CustomHavokMemorySystem *v5; // rdi
  hkMemoryAllocator *v6; // rax

  v4 = router;
  v5 = this;
  if ( flags.m_storage & 1 )
  {
    router->m_temp = 0i64;
    router->m_heap = this->m_allocator;
    v6 = this->m_allocator;
    router->m_solver = 0i64;
    router->m_debug = v6;
  }
  if ( flags.m_storage & 2 )
  {
    hkLifoAllocator::init(&router->m_stack, this->m_allocator, this->m_allocator, this->m_allocator);
    v4->m_temp = (hkMemoryAllocator *)&v5->m_tempAllocator.vfptr;
    v4->m_solver = (hkMemoryAllocator *)&v5->m_solverAllocator.vfptr;
  }
}

// File Line: 440
// RVA: 0xB8D90
void __fastcall CustomHavokMemorySystem::threadQuit(CustomHavokMemorySystem *this, hkMemoryRouter *router, hkFlags<enum hkMemorySystem::FlagBits,int> flags)
{
  hkMemoryRouter *v3; // rbx
  int v4; // [rsp+40h] [rbp+18h]

  v4 = flags.m_storage;
  v3 = router;
  if ( flags.m_storage & 2 )
  {
    router->m_temp = 0i64;
    router->m_solver = 0i64;
    hkLifoAllocator::quit(&router->m_stack, 0i64);
    LOBYTE(flags.m_storage) = v4;
  }
  if ( flags.m_storage & 1 )
    hkMemUtil::memSet(v3, 0, 128);
}

// File Line: 477
// RVA: 0xB8980
void __fastcall CustomHavokMemorySystem::printStatistics(CustomHavokMemorySystem *this, hkOstream *ostr)
{
  hkMemoryAllocator *v2; // rcx
  __int64 v3; // [rsp+20h] [rbp-38h]
  __int64 v4; // [rsp+28h] [rbp-30h]
  __int64 v5; // [rsp+30h] [rbp-28h]
  __int64 v6; // [rsp+38h] [rbp-20h]
  __int64 v7; // [rsp+40h] [rbp-18h]
  __int64 v8; // [rsp+48h] [rbp-10h]

  v2 = this->m_allocator;
  v3 = -1i64;
  v4 = -1i64;
  v5 = -1i64;
  v6 = -1i64;
  v7 = -1i64;
  v8 = -1i64;
  v2->vfptr->getMemoryStatistics(v2, (hkMemoryAllocator::MemoryStatistics *)&v3);
}

