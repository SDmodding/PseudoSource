// File Line: 80
// RVA: 0xAA0A30
void __fastcall AkMemPool::Init(AkMemPool *this)
{
  this->eAttributes = 1;
  *(_QWORD *)&this->ulNumBlocks = 0i64;
  this->pcAllocAddress = 0i64;
  this->pcMemAddress = 0i64;
  this->pTlsfPool = 0i64;
  *(_QWORD *)&this->ulAlign = 0i64;
  this->ulTotalAvailable = 0;
}

// File Line: 243
// RVA: 0xAA0A50
signed __int64 __fastcall AK::MemoryMgr::InitBase(int in_iNumPools)
{
  int v1; // ebp
  __int64 v2; // rsi
  AkMemPool *v3; // rax
  __int64 v5; // rdi
  AkMemPool *v6; // rbx

  v1 = in_iNumPools;
  v2 = in_iNumPools;
  v3 = (AkMemPool *)AK::AllocHook(112i64 * in_iNumPools);
  AK::MemoryMgr::s_pMemPools = v3;
  if ( !v3 )
    return 2i64;
  if ( v1 > 0 )
  {
    v5 = 0i64;
    do
    {
      v6 = &v3[v5];
      if ( &v3[v5] )
      {
        v6->listBuffers.m_pFirst = 0i64;
        v6->listBuffers.m_pLast = 0i64;
        InitializeCriticalSection(&v6->lock.m_csLock);
        *(_QWORD *)&v6->ulNumBlocks = 0i64;
        v6->pcAllocAddress = 0i64;
        v6->pcMemAddress = 0i64;
        v6->eAttributes = 1;
        v6->pTlsfPool = 0i64;
        *(_QWORD *)&v6->ulAlign = 0i64;
        v6->ulTotalAvailable = 0;
        v3 = AK::MemoryMgr::s_pMemPools;
      }
      ++v5;
      --v2;
    }
    while ( v2 );
  }
  AK::MemoryMgr::s_iMaxNumPools = v1;
  AK::MemoryMgr::s_iNumPools = 0;
  s_bInitialized_0 = 1;
  return 1i64;
}

// File Line: 273
// RVA: 0xAA0B20
_BOOL8 __fastcall AK::MemoryMgr::IsInitialized()
{
  return s_bInitialized_0;
}

// File Line: 280
// RVA: 0xAA0CA0
void __fastcall AK::MemoryMgr::Term(AK::MemoryMgr *this, unsigned __int64 a2, unsigned int a3)
{
  int v3; // ebx
  __int64 v4; // rdi
  AkMemPool *v5; // rsi

  if ( s_bInitialized_0 )
  {
    v3 = 0;
    if ( AK::MemoryMgr::s_iMaxNumPools > 0 )
    {
      v4 = 0i64;
      do
      {
        v5 = AK::MemoryMgr::s_pMemPools;
        if ( AK::MemoryMgr::s_pMemPools[v4].ulNumBlocks )
          AK::MemoryMgr::DestroyPool(v3);
        DeleteCriticalSection(&v5[v4].lock.m_csLock);
        ++v3;
        ++v4;
      }
      while ( v3 < AK::MemoryMgr::s_iMaxNumPools );
    }
    UFG::SurfaceBankNode::operator delete(AK::MemoryMgr::s_pMemPools, a2, a3);
    AK::MemoryMgr::s_iMaxNumPools = 0;
    AK::MemoryMgr::s_iNumPools = 0;
    AK::MemoryMgr::s_pMemPools = 0i64;
    s_bInitialized_0 = 0;
  }
}

// File Line: 383
// RVA: 0xAA09C0
__int64 __fastcall AK::MemoryMgr::GetPoolAttributes(int in_poolId)
{
  return AK::MemoryMgr::s_pMemPools[in_poolId].eAttributes;
}

// File Line: 415
// RVA: 0xAA0BC0
void *__fastcall AK::MemoryMgr::Malloc(int in_PoolId, unsigned __int64 in_ulSize)
{
  unsigned __int64 v2; // rsi
  AkMemPool *v4; // rdi
  unsigned int v5; // eax
  void *v6; // rcx
  void *v7; // rax
  void *v8; // rsi

  v2 = in_ulSize;
  if ( !in_ulSize )
    return 0i64;
  v4 = &AK::MemoryMgr::s_pMemPools[in_PoolId];
  EnterCriticalSection(&v4->lock.m_csLock);
  v5 = v4->ulAlign;
  v6 = v4->pTlsfPool;
  if ( v5 <= 4 )
    v7 = tlsf_malloc(v6, v2);
  else
    v7 = tlsf_memalign(v6, v5, v2);
  v8 = v7;
  if ( v7 )
    v4->ulUsed += tlsf_block_size(v7) + 8;
  LeaveCriticalSection(&v4->lock.m_csLock);
  return v8;
}

// File Line: 493
// RVA: 0xAA0B30
void *__fastcall AK::MemoryMgr::Malign(int in_poolId, unsigned __int64 in_uSize, unsigned int in_uAlignment)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // rsi
  AkMemPool *v6; // rdi
  void *v7; // rax
  void *v8; // rsi

  v3 = in_uAlignment;
  v4 = in_uSize;
  if ( !in_uSize )
    return 0i64;
  v6 = &AK::MemoryMgr::s_pMemPools[in_poolId];
  EnterCriticalSection(&v6->lock.m_csLock);
  v7 = tlsf_memalign(v6->pTlsfPool, v3, v4);
  v8 = v7;
  if ( v7 )
    v6->ulUsed += tlsf_block_size(v7) + 8;
  LeaveCriticalSection(&v6->lock.m_csLock);
  return v8;
}

// File Line: 556
// RVA: 0xAA08F0
signed __int64 __fastcall AK::MemoryMgr::Free(int in_PoolId, void *in_pvMemAddress)
{
  void *v2; // rsi
  AkMemPool *v3; // rdi
  int v4; // eax
  void *v5; // rcx

  v2 = in_pvMemAddress;
  if ( in_pvMemAddress )
  {
    v3 = &AK::MemoryMgr::s_pMemPools[in_PoolId];
    EnterCriticalSection(&v3->lock.m_csLock);
    v4 = tlsf_block_size(v2);
    v5 = v3->pTlsfPool;
    v3->ulUsed -= v4 + 8;
    tlsf_free(v5, v2);
    LeaveCriticalSection(&v3->lock.m_csLock);
  }
  return 1i64;
}

// File Line: 592
// RVA: 0xAA0960
AkLinkedBuffer *__fastcall AK::MemoryMgr::GetBlock(int in_poolId)
{
  AkMemPool *v1; // rax
  AkLinkedBuffer *v2; // rdx

  v1 = &AK::MemoryMgr::s_pMemPools[in_poolId];
  v2 = v1->listBuffers.m_pFirst;
  if ( v2 )
  {
    if ( !v2->pNextItem )
    {
      v1->listBuffers.m_pFirst = 0i64;
      v1->listBuffers.m_pLast = 0i64;
      v1->ulUsed += v1->ulBlockSize;
      return v2;
    }
    v1->listBuffers.m_pFirst = v2->pNextItem;
    v1->ulUsed += v1->ulBlockSize;
  }
  return v2;
}

// File Line: 617
// RVA: 0xAA0C50
signed __int64 __fastcall AK::MemoryMgr::ReleaseBlock(int in_PoolId, void *in_pvMemAddress)
{
  AkMemPool *v2; // r8
  AkLinkedBuffer *v3; // rax
  signed __int64 result; // rax

  v2 = &AK::MemoryMgr::s_pMemPools[in_PoolId];
  v2->ulUsed -= v2->ulBlockSize;
  *(_QWORD *)in_pvMemAddress = 0i64;
  v3 = v2->listBuffers.m_pLast;
  if ( v3 )
    v3->pNextItem = (AkLinkedBuffer *)in_pvMemAddress;
  else
    v2->listBuffers.m_pFirst = (AkLinkedBuffer *)in_pvMemAddress;
  result = 1i64;
  v2->listBuffers.m_pLast = (AkLinkedBuffer *)in_pvMemAddress;
  return result;
}

// File Line: 637
// RVA: 0xAA09A0
__int64 __fastcall AK::MemoryMgr::GetBlockSize(int in_poolId)
{
  return AK::MemoryMgr::s_pMemPools[in_poolId].ulBlockSize;
}

// File Line: 665
// RVA: 0xAA08C0
signed __int64 __fastcall AK::MemoryMgr::CheckPoolId(int in_PoolId)
{
  signed __int64 result; // rax

  if ( in_PoolId >= AK::MemoryMgr::s_iMaxNumPools || (result = 1i64, !AK::MemoryMgr::s_pMemPools[in_PoolId].ulNumBlocks) )
    result = 14i64;
  return result;
}

// File Line: 730
// RVA: 0xAA09E0
void __fastcall AK::MemoryMgr::GetPoolMemoryUsed(int in_poolId, AK::MemoryMgr::PoolMemInfo *out_memInfo)
{
  AK::MemoryMgr::PoolMemInfo *v2; // rsi
  AkMemPool *v3; // rdi

  v2 = out_memInfo;
  v3 = &AK::MemoryMgr::s_pMemPools[in_poolId];
  EnterCriticalSection(&v3->lock.m_csLock);
  v2->uUsed = v3->ulUsed;
  v2->uReserved = v3->ulTotalAvailable;
  LeaveCriticalSection(&v3->lock.m_csLock);
}

