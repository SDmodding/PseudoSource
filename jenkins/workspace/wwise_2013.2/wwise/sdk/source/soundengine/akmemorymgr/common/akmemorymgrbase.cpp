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
__int64 __fastcall AK::MemoryMgr::InitBase(int in_iNumPools)
{
  __int64 v2; // rsi
  AkMemPool *v3; // rax
  __int64 v5; // rdi
  AkMemPool *v6; // rbx

  v2 = in_iNumPools;
  v3 = (AkMemPool *)AK::AllocHook(112i64 * in_iNumPools);
  AK::MemoryMgr::s_pMemPools = v3;
  if ( !v3 )
    return 2i64;
  if ( in_iNumPools > 0 )
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
  AK::MemoryMgr::s_iMaxNumPools = in_iNumPools;
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
    UFG::SurfaceBankNode::operator delete((char *)AK::MemoryMgr::s_pMemPools, a2, a3);
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
  AkMemPool *v4; // rdi
  unsigned int ulAlign; // eax
  void *pTlsfPool; // rcx
  void *v7; // rax
  void *v8; // rsi

  if ( !in_ulSize )
    return 0i64;
  v4 = &AK::MemoryMgr::s_pMemPools[in_PoolId];
  EnterCriticalSection(&v4->lock.m_csLock);
  ulAlign = v4->ulAlign;
  pTlsfPool = v4->pTlsfPool;
  if ( ulAlign <= 4 )
    v7 = tlsf_malloc(pTlsfPool, in_ulSize);
  else
    v7 = tlsf_memalign(pTlsfPool, ulAlign, in_ulSize);
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
  AkMemPool *v6; // rdi
  void *v7; // rax
  void *v8; // rsi

  v3 = in_uAlignment;
  if ( !in_uSize )
    return 0i64;
  v6 = &AK::MemoryMgr::s_pMemPools[in_poolId];
  EnterCriticalSection(&v6->lock.m_csLock);
  v7 = tlsf_memalign(v6->pTlsfPool, v3, in_uSize);
  v8 = v7;
  if ( v7 )
    v6->ulUsed += tlsf_block_size(v7) + 8;
  LeaveCriticalSection(&v6->lock.m_csLock);
  return v8;
}

// File Line: 556
// RVA: 0xAA08F0
__int64 __fastcall AK::MemoryMgr::Free(int in_PoolId, void *in_pvMemAddress)
{
  AkMemPool *v3; // rdi
  int v4; // eax
  void *pTlsfPool; // rcx

  if ( in_pvMemAddress )
  {
    v3 = &AK::MemoryMgr::s_pMemPools[in_PoolId];
    EnterCriticalSection(&v3->lock.m_csLock);
    v4 = tlsf_block_size(in_pvMemAddress);
    pTlsfPool = v3->pTlsfPool;
    v3->ulUsed -= v4 + 8;
    tlsf_free(pTlsfPool, in_pvMemAddress);
    LeaveCriticalSection(&v3->lock.m_csLock);
  }
  return 1i64;
}

// File Line: 592
// RVA: 0xAA0960
AkLinkedBuffer *__fastcall AK::MemoryMgr::GetBlock(int in_poolId)
{
  AkMemPool *v1; // rax
  AkLinkedBuffer *m_pFirst; // rdx

  v1 = &AK::MemoryMgr::s_pMemPools[in_poolId];
  m_pFirst = v1->listBuffers.m_pFirst;
  if ( m_pFirst )
  {
    if ( !m_pFirst->pNextItem )
    {
      v1->listBuffers.m_pFirst = 0i64;
      v1->listBuffers.m_pLast = 0i64;
      v1->ulUsed += v1->ulBlockSize;
      return m_pFirst;
    }
    v1->listBuffers.m_pFirst = m_pFirst->pNextItem;
    v1->ulUsed += v1->ulBlockSize;
  }
  return m_pFirst;
}

// File Line: 617
// RVA: 0xAA0C50
__int64 __fastcall AK::MemoryMgr::ReleaseBlock(int in_PoolId, AkLinkedBuffer *in_pvMemAddress)
{
  AkMemPool *v2; // r8
  AkLinkedBuffer *m_pLast; // rax
  __int64 result; // rax

  v2 = &AK::MemoryMgr::s_pMemPools[in_PoolId];
  v2->ulUsed -= v2->ulBlockSize;
  in_pvMemAddress->pNextItem = 0i64;
  m_pLast = v2->listBuffers.m_pLast;
  if ( m_pLast )
    m_pLast->pNextItem = in_pvMemAddress;
  else
    v2->listBuffers.m_pFirst = in_pvMemAddress;
  result = 1i64;
  v2->listBuffers.m_pLast = in_pvMemAddress;
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
__int64 __fastcall AK::MemoryMgr::CheckPoolId(int in_PoolId)
{
  __int64 result; // rax

  if ( in_PoolId >= AK::MemoryMgr::s_iMaxNumPools )
    return 14i64;
  result = 1i64;
  if ( !AK::MemoryMgr::s_pMemPools[in_PoolId].ulNumBlocks )
    return 14i64;
  return result;
}

// File Line: 730
// RVA: 0xAA09E0
void __fastcall AK::MemoryMgr::GetPoolMemoryUsed(int in_poolId, AK::MemoryMgr::PoolMemInfo *out_memInfo)
{
  AkMemPool *v3; // rdi

  v3 = &AK::MemoryMgr::s_pMemPools[in_poolId];
  EnterCriticalSection(&v3->lock.m_csLock);
  out_memInfo->uUsed = v3->ulUsed;
  out_memInfo->uReserved = v3->ulTotalAvailable;
  LeaveCriticalSection(&v3->lock.m_csLock);
}

