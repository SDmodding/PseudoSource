// File Line: 40
// RVA: 0xAA1020
signed __int64 __fastcall AK::MemoryMgr::Init(AkMemSettings *in_pSettings)
{
  AkMemSettings *v1; // rbx
  signed __int64 result; // rax

  v1 = in_pSettings;
  if ( (unsigned __int8)AK::MemoryMgr::IsInitialized() || !v1 )
    result = 2i64;
  else
    result = AK::MemoryMgr::InitBase(v1->uMaxNumPools);
  return result;
}

// File Line: 78
// RVA: 0xAA0D50
signed __int64 __fastcall AK::MemoryMgr::CreatePool(void *in_pvMemAddress, unsigned int in_ulMemSize, unsigned int in_ulBlockSize, unsigned int in_eAttributes, unsigned int in_ulBlockAlign)
{
  unsigned int v5; // er12
  __int64 v6; // r13
  unsigned int v7; // er15
  char *v8; // r14
  unsigned int v9; // ebp
  AkMemPool *v11; // rbx
  int v12; // esi
  _RTL_CRITICAL_SECTION *v13; // rdi
  unsigned int v14; // edi
  char *v15; // rax
  char *v16; // rcx
  AkLinkedBuffer *v17; // rax
  AkLinkedBuffer *i; // rdx
  AkLinkedBuffer *v19; // rcx
  void *v20; // rax
  unsigned __int64 v21; // rdx
  unsigned int v22; // er8
  char *v23; // rcx

  v5 = in_eAttributes;
  v6 = in_ulBlockSize;
  v7 = in_ulMemSize;
  v8 = (char *)in_pvMemAddress;
  v9 = in_eAttributes & 3;
  if ( in_eAttributes & 3 )
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
  v13 = &AK::MemoryMgr::s_pMemPools->lock.m_csLock;
  while ( 1 )
  {
    EnterCriticalSection(v13);
    if ( !v11->ulNumBlocks )
      break;
    LeaveCriticalSection(v13);
    ++v12;
    ++v11;
    v13 = (_RTL_CRITICAL_SECTION *)((char *)v13 + 112);
    if ( v12 >= AK::MemoryMgr::s_iMaxNumPools )
      return 0xFFFFFFFFi64;
  }
  if ( v12 >= AK::MemoryMgr::s_iMaxNumPools )
    return 0xFFFFFFFFi64;
  v14 = v6 * (v7 / (unsigned int)v6);
  if ( v8 )
  {
    *((_DWORD *)v11 + 11) &= 0xFFFFFFFE;
    v11->pcMemAddress = v8;
    goto LABEL_26;
  }
  if ( v9 == 2 )
  {
    if ( v14 + in_ulBlockAlign )
    {
      v15 = AK::VirtualAllocHook(0i64, v14 + in_ulBlockAlign, 0x1000u, 4u);
LABEL_19:
      v11->pcAllocAddress = v15;
      goto LABEL_20;
    }
  }
  else if ( v14 + in_ulBlockAlign )
  {
    v15 = AK::AllocHook(v14 + in_ulBlockAlign);
    goto LABEL_19;
  }
LABEL_20:
  v16 = v11->pcAllocAddress;
  v11->pcMemAddress = v16;
  if ( !v16 )
  {
LABEL_38:
    LeaveCriticalSection(&v11->lock.m_csLock);
    return 0xFFFFFFFFi64;
  }
  if ( in_ulBlockAlign && (unsigned __int64)v16 % in_ulBlockAlign )
    v11->pcMemAddress = &v16[in_ulBlockAlign - (unsigned __int64)v16 % in_ulBlockAlign];
  *((_DWORD *)v11 + 11) |= 1u;
LABEL_26:
  v11->eAttributes = v5;
  v11->ulTotalAvailable = v14;
  if ( v5 & 8 )
  {
    v17 = (AkLinkedBuffer *)v11->pcMemAddress;
    for ( i = (AkLinkedBuffer *)((char *)v17 + v14); v17 != i; v17 = (AkLinkedBuffer *)((char *)v17 + v6) )
    {
      v17->pNextItem = 0i64;
      v19 = v11->listBuffers.m_pLast;
      if ( v19 )
        v19->pNextItem = v17;
      else
        v11->listBuffers.m_pFirst = v17;
      v11->listBuffers.m_pLast = v17;
    }
    goto LABEL_40;
  }
  v20 = tlsf_create(v11->pcMemAddress, v14);
  v11->pTlsfPool = v20;
  if ( !v20 )
  {
    v23 = v11->pcAllocAddress;
    if ( (v11->eAttributes & 3) == 2 )
      UFG::SurfaceBankNode::operator delete(v23, 0i64, 0x8000u);
    else
      UFG::SurfaceBankNode::operator delete(v23, v21, v22);
    v11->pcAllocAddress = 0i64;
    v11->pcMemAddress = 0i64;
    goto LABEL_38;
  }
  v11->ulTotalAvailable -= tlsf_overhead();
LABEL_40:
  v11->ulBlockSize = v6;
  v11->ulAlign = in_ulBlockAlign;
  v11->ulNumBlocks = v7 / (unsigned int)v6;
  ++AK::MemoryMgr::s_iNumPools;
  LeaveCriticalSection(&v11->lock.m_csLock);
  return (unsigned int)v12;
}

// File Line: 240
// RVA: 0xAA0F60
signed __int64 __fastcall AK::MemoryMgr::DestroyPool(int in_PoolId)
{
  __int64 v1; // rbx
  signed __int64 result; // rax
  unsigned int v3; // esi
  AkMemPool *v4; // rdi
  unsigned __int64 v5; // rdx
  unsigned int v6; // er8
  char *v7; // rcx

  v1 = in_PoolId;
  result = AK::MemoryMgr::CheckPoolId(in_PoolId);
  v3 = result;
  if ( (_DWORD)result == 1 )
  {
    v4 = &AK::MemoryMgr::s_pMemPools[v1];
    EnterCriticalSection(&v4->lock.m_csLock);
    if ( v4->eAttributes & 8 )
    {
      v4->listBuffers.m_pFirst = 0i64;
      v4->listBuffers.m_pLast = 0i64;
    }
    else
    {
      _((AMD_HD3D *)v4->pTlsfPool);
    }
    if ( *((_BYTE *)v4 + 44) & 1 )
    {
      v7 = v4->pcAllocAddress;
      if ( (v4->eAttributes & 3) == 2 )
        UFG::SurfaceBankNode::operator delete(v7, 0i64, 0x8000u);
      else
        UFG::SurfaceBankNode::operator delete(v7, v5, v6);
      v4->pcAllocAddress = 0i64;
      v4->pcMemAddress = 0i64;
    }
    AkMemPool::Init(v4);
    --AK::MemoryMgr::s_iNumPools;
    LeaveCriticalSection(&v4->lock.m_csLock);
    result = v3;
  }
  return result;
}

