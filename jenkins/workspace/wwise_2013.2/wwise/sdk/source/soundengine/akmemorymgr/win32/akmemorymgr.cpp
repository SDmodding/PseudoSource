// File Line: 40
// RVA: 0xAA1020
__int64 __fastcall AK::MemoryMgr::Init(AkMemSettings *in_pSettings)
{
  if ( AK::MemoryMgr::IsInitialized() || !in_pSettings )
    return 2i64;
  else
    return AK::MemoryMgr::InitBase(in_pSettings->uMaxNumPools);
}

// File Line: 78
// RVA: 0xAA0D50
signed __int64 __fastcall AK::MemoryMgr::CreatePool(
        char *in_pvMemAddress,
        unsigned int in_ulMemSize,
        unsigned int in_ulBlockSize,
        unsigned int in_eAttributes,
        unsigned int in_ulBlockAlign)
{
  __int64 v6; // r13
  unsigned int v9; // ebp
  AkMemPool *v11; // rbx
  int v12; // esi
  CAkLock *i; // rdi
  unsigned int v14; // edi
  char *v15; // rax
  char *v16; // rcx
  AkLinkedBuffer *pcMemAddress; // rax
  AkLinkedBuffer *j; // rdx
  AkLinkedBuffer *m_pLast; // rcx
  void *v20; // rax
  unsigned __int64 v21; // rdx
  unsigned int v22; // r8d
  char *pcAllocAddress; // rcx

  v6 = in_ulBlockSize;
  v9 = in_eAttributes & 3;
  if ( (in_eAttributes & 3) != 0 )
  {
    if ( v9 - 1 > 1 )
      return 0xFFFFFFFFi64;
  }
  else if ( !in_pvMemAddress )
  {
    return 0xFFFFFFFFi64;
  }
  if ( AK::MemoryMgr::s_iNumPools >= AK::MemoryMgr::s_iMaxNumPools )
    return 0xFFFFFFFFi64;
  v11 = AK::MemoryMgr::s_pMemPools;
  v12 = 0;
  if ( AK::MemoryMgr::s_iMaxNumPools <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = &AK::MemoryMgr::s_pMemPools->lock; ; i = (CAkLock *)((char *)i + 112) )
  {
    EnterCriticalSection(&i->m_csLock);
    if ( !v11->ulNumBlocks )
      break;
    LeaveCriticalSection(&i->m_csLock);
    ++v12;
    ++v11;
    if ( v12 >= AK::MemoryMgr::s_iMaxNumPools )
      return 0xFFFFFFFFi64;
  }
  if ( v12 >= AK::MemoryMgr::s_iMaxNumPools )
    return 0xFFFFFFFFi64;
  v14 = v6 * (in_ulMemSize / (unsigned int)v6);
  if ( in_pvMemAddress )
  {
    *((_DWORD *)v11 + 11) &= ~1u;
    v11->pcMemAddress = in_pvMemAddress;
LABEL_26:
    v11->eAttributes = in_eAttributes;
    v11->ulTotalAvailable = v14;
    if ( (in_eAttributes & 8) != 0 )
    {
      pcMemAddress = (AkLinkedBuffer *)v11->pcMemAddress;
      for ( j = (AkLinkedBuffer *)((char *)pcMemAddress + v14);
            pcMemAddress != j;
            pcMemAddress = (AkLinkedBuffer *)((char *)pcMemAddress + v6) )
      {
        pcMemAddress->pNextItem = 0i64;
        m_pLast = v11->listBuffers.m_pLast;
        if ( m_pLast )
          m_pLast->pNextItem = pcMemAddress;
        else
          v11->listBuffers.m_pFirst = pcMemAddress;
        v11->listBuffers.m_pLast = pcMemAddress;
      }
      goto LABEL_40;
    }
    v20 = tlsf_create(v11->pcMemAddress, v14);
    v11->pTlsfPool = v20;
    if ( v20 )
    {
      v11->ulTotalAvailable -= tlsf_overhead();
LABEL_40:
      v11->ulBlockSize = v6;
      v11->ulAlign = in_ulBlockAlign;
      v11->ulNumBlocks = in_ulMemSize / (unsigned int)v6;
      ++AK::MemoryMgr::s_iNumPools;
      LeaveCriticalSection(&v11->lock.m_csLock);
      return (unsigned int)v12;
    }
    pcAllocAddress = v11->pcAllocAddress;
    if ( (v11->eAttributes & 3) == 2 )
      UFG::SurfaceBankNode::operator delete(pcAllocAddress, 0i64, 0x8000u);
    else
      UFG::SurfaceBankNode::operator delete(pcAllocAddress, v21, v22);
    v11->pcAllocAddress = 0i64;
    v11->pcMemAddress = 0i64;
    goto LABEL_38;
  }
  if ( v9 == 2 )
  {
    if ( !(v14 + in_ulBlockAlign) )
      goto LABEL_20;
    v15 = AK::VirtualAllocHook(0i64, v14 + in_ulBlockAlign, 0x1000u, 4u);
  }
  else
  {
    if ( !(v14 + in_ulBlockAlign) )
      goto LABEL_20;
    v15 = AK::AllocHook(v14 + in_ulBlockAlign);
  }
  v11->pcAllocAddress = v15;
LABEL_20:
  v16 = v11->pcAllocAddress;
  v11->pcMemAddress = v16;
  if ( v16 )
  {
    if ( in_ulBlockAlign && (unsigned __int64)v16 % in_ulBlockAlign )
      v11->pcMemAddress = &v16[in_ulBlockAlign - (unsigned __int64)v16 % in_ulBlockAlign];
    *((_DWORD *)v11 + 11) |= 1u;
    goto LABEL_26;
  }
LABEL_38:
  LeaveCriticalSection(&v11->lock.m_csLock);
  return 0xFFFFFFFFi64;
}

// File Line: 240
// RVA: 0xAA0F60
__int64 __fastcall AK::MemoryMgr::DestroyPool(int in_PoolId)
{
  __int64 v1; // rbx
  __int64 result; // rax
  AkMemPool *v3; // rdi
  unsigned __int64 v4; // rdx
  unsigned int v5; // r8d
  char *pcAllocAddress; // rcx

  v1 = in_PoolId;
  result = AK::MemoryMgr::CheckPoolId(in_PoolId);
  if ( (_DWORD)result == 1 )
  {
    v3 = &AK::MemoryMgr::s_pMemPools[v1];
    EnterCriticalSection(&v3->lock.m_csLock);
    if ( (v3->eAttributes & 8) != 0 )
    {
      v3->listBuffers.m_pFirst = 0i64;
      v3->listBuffers.m_pLast = 0i64;
    }
    else
    {
      _((AMD_HD3D *)v3->pTlsfPool);
    }
    if ( (*((_BYTE *)v3 + 44) & 1) != 0 )
    {
      pcAllocAddress = v3->pcAllocAddress;
      if ( (v3->eAttributes & 3) == 2 )
        UFG::SurfaceBankNode::operator delete(pcAllocAddress, 0i64, 0x8000u);
      else
        UFG::SurfaceBankNode::operator delete(pcAllocAddress, v4, v5);
      v3->pcAllocAddress = 0i64;
      v3->pcMemAddress = 0i64;
    }
    AkMemPool::Init(v3);
    --AK::MemoryMgr::s_iNumPools;
    LeaveCriticalSection(&v3->lock.m_csLock);
    return 1i64;
  }
  return result;
}

