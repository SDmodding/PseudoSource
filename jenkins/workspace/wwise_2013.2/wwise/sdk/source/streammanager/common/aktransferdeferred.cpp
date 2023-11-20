// File Line: 36
// RVA: 0xAA90E0
void __fastcall AK::StreamMgr::CAkStmMemViewDeferred::Cancel(AK::StreamMgr::CAkStmMemViewDeferred *this, AK::StreamMgr::IAkIOHookDeferred *in_pLowLevelHook, bool in_bCallLowLevelIO, bool in_bAllCancelled)
{
  AK::StreamMgr::CAkStmMemViewDeferred *v4; // rbx
  bool v5; // r14
  AK::StreamMgr::CAkDeviceBase *v6; // rbp
  AK::StreamMgr::IAkIOHookDeferred *v7; // rdi
  AK::StreamMgr::AkMemBlock *v8; // rdx
  AK::StreamMgr::AkMemBlock *v9; // rbx
  AK::StreamMgr::AkMemBlock *v10; // rcx
  bool v11; // [rsp+58h] [rbp+20h]

  v11 = in_bAllCancelled;
  v4 = this;
  v5 = in_bCallLowLevelIO;
  v6 = this->m_pOwner->m_pDevice;
  v7 = in_pLowLevelHook;
  EnterCriticalSection(&v6->m_lockSems.m_csLock);
  v8 = v4->m_pBlock;
  v9 = v8->pNextBlock;
  if ( v9 )
  {
    v10 = v9[1].pNextBlock;
    if ( *(_QWORD *)&v10->uAvailableSize || *(_QWORD *)&v10->uRefCount != *(_QWORD *)&v9[1].uAvailableSize )
    {
      v9 = 0i64;
    }
    else if ( v8->fileID != -1 )
    {
      AK::StreamMgr::CAkIOMemMgr::UntagBlock(&v6->m_mgrMemIO, v8);
    }
  }
  LeaveCriticalSection(&v6->m_lockSems.m_csLock);
  if ( v9 )
  {
    if ( v5 )
    {
      if ( v9[1].uRefCount & 1 )
        v11 = 0;
      else
        ((void (__fastcall *)(AK::StreamMgr::IAkIOHookDeferred *, _QWORD, void **, bool *))v7->vfptr[1].GetBlockSize)(
          v7,
          *(_QWORD *)(*(_QWORD *)&v9[1].uAvailableSize + 40i64),
          &v9->pData,
          &v11);
    }
    *(_DWORD *)&v9[1].uRefCount |= 1u;
  }
}

// File Line: 79
// RVA: 0xAA9220
void __fastcall AK::StreamMgr::CAkLowLevelTransferDeferred::LLIOCallback(AkAsyncIOTransferInfo *in_pTransferInfo, AKRESULT in_eResult)
{
  AK::StreamMgr::CAkLowLevelTransferDeferred *v2; // rcx

  v2 = (AK::StreamMgr::CAkLowLevelTransferDeferred *)in_pTransferInfo->pCookie;
  if ( in_eResult != 1 )
    in_eResult = 2;
  AK::StreamMgr::CAkLowLevelTransferDeferred::Update(v2, in_eResult);
}

// File Line: 103
// RVA: 0xAA9240
void __fastcall AK::StreamMgr::CAkLowLevelTransferDeferred::Update(AK::StreamMgr::CAkLowLevelTransferDeferred *this, AKRESULT in_eResult)
{
  AKRESULT v2; // er14
  AK::StreamMgr::CAkDeviceBase *v3; // rbp
  __int64 v4; // rbx
  __m128i v5; // di
  AK::StreamMgr::AkMemBlock *v6; // rdx
  AK::StreamMgr::CAkIOThreadVtbl *v7; // rcx
  AK::StreamMgr::AkMemBlock *v8; // rax
  __int64 v9; // r9
  __int64 i; // rdx
  __int64 *v11; // rcx
  __int64 v12; // rax
  __m128i v13; // [rsp+30h] [rbp-28h]

  v5.m128i_i64[0] = (__int64)this;
  v2 = in_eResult;
  v3 = this->m_pOwner->m_pDevice;
  EnterCriticalSection(&v3->m_lockSems.m_csLock);
  v4 = *(_QWORD *)(v5.m128i_i64[0] + 56);
  v5 = (__m128i)v5.m128i_u64[0];
  *(_QWORD *)(v5.m128i_i64[0] + 56) = 0i64;
  v6 = *(AK::StreamMgr::AkMemBlock **)(v4 + 8);
  v7 = v3[1].vfptr;
  v8 = v6->pNextBlock;
  if ( v7 )
  {
    v8->uPosition = (unsigned __int64)v7;
    v3[1].vfptr = (AK::StreamMgr::CAkIOThreadVtbl *)v8;
  }
  else
  {
    v3[1].vfptr = (AK::StreamMgr::CAkIOThreadVtbl *)v8;
    v8->uPosition = 0i64;
  }
  v6->pNextBlock = 0i64;
  if ( v2 != 1 && v6->fileID != -1 )
    AK::StreamMgr::CAkIOMemMgr::UntagBlock(&v3->m_mgrMemIO, v6);
  LeaveCriticalSection(&v3->m_lockSems.m_csLock);
  LOBYTE(v9) = 1;
  for ( i = v4; ; i = v13.m128i_i64[0] )
  {
    v5.m128i_i64[0] = *(_QWORD *)(i + 24);
    if ( i == v4 )
      v4 = *(_QWORD *)(i + 24);
    else
      *(_QWORD *)(v5.m128i_i64[1] + 24) = v5.m128i_i64[0];
    v11 = *(__int64 **)(i + 32);
    v12 = *v11;
    _mm_store_si128(&v13, v5);
    (*(void (__fastcall **)(__int64 *, __int64, _QWORD, __int64))(v12 + 40))(v11, i, (unsigned int)v2, v9);
    LOBYTE(v9) = 0;
    if ( !v5.m128i_i64[0] )
      break;
    v5.m128i_i64[1] = v13.m128i_i64[1];
  }
}

// File Line: 146
// RVA: 0xAA91B0
__int64 __fastcall AK::StreamMgr::CAkLowLevelTransferDeferred::Execute(AK::StreamMgr::CAkLowLevelTransferDeferred *this, AK::StreamMgr::IAkIOHookDeferred *in_pLowLevelHook, AkFileDesc *in_pFileDesc, AkIoHeuristics *in_heuristics, bool in_bWriteOp)
{
  AkIoHeuristics *v5; // r11
  AK::StreamMgr::CAkLowLevelTransferDeferred *v6; // rbx
  AK::StreamMgr::IAkLowLevelIOHookVtbl *v7; // rax
  char *v8; // r9
  __int64 result; // rax

  v5 = in_heuristics;
  v6 = this;
  if ( *((_BYTE *)this + 72) & 2 )
    return 1i64;
  v7 = in_pLowLevelHook->vfptr;
  v8 = (char *)&this->info;
  if ( in_bWriteOp )
    result = ((__int64 (__fastcall *)(AK::StreamMgr::IAkIOHookDeferred *, AkFileDesc *, AkIoHeuristics *, char *))v7[1].Close)(
               in_pLowLevelHook,
               in_pFileDesc,
               v5,
               v8);
  else
    result = ((__int64 (__fastcall *)(AK::StreamMgr::IAkIOHookDeferred *, AkFileDesc *, AkIoHeuristics *, char *))v7[1].__vecDelDtor)(
               in_pLowLevelHook,
               in_pFileDesc,
               v5,
               v8);
  *((_DWORD *)v6 + 18) |= 2u;
  return result;
}

