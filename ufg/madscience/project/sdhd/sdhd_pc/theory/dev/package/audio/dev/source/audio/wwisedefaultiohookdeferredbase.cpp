// File Line: 25
// RVA: 0x14653B0
__int64 dynamic_initializer_for__UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo__);
}

// File Line: 26
// RVA: 0x14651F0
__int64 dynamic_initializer_for__UFG::WwiseDefaultIOHookDeferredBase::sm_ioTransferLock__()
{
  UFG::qMutex::qMutex(&UFG::WwiseDefaultIOHookDeferredBase::sm_ioTransferLock, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::WwiseDefaultIOHookDeferredBase::sm_ioTransferLock__);
}

// File Line: 27
// RVA: 0x1464FC0
__int64 dynamic_initializer_for__UFG::WwiseDefaultIOHookDeferredBase::sm_KillTransfersLock__()
{
  UFG::qMutex::qMutex(&UFG::WwiseDefaultIOHookDeferredBase::sm_KillTransfersLock, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__UFG::WwiseDefaultIOHookDeferredBase::sm_KillTransfersLock__);
}

// File Line: 35
// RVA: 0x140B20
void __fastcall UFG::WwiseDefaultIOHookDeferredBase::WwiseDefaultIOHookDeferredBase(UFG::WwiseDefaultIOHookDeferredBase *this)
{
  UFG::WwiseDefaultIOHookDeferredBase *v1; // rsi
  AK::StreamMgr::IAkIOHookDeferred *v2; // [rsp+48h] [rbp+10h]

  v1 = this;
  this->vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&AK::StreamMgr::IAkFileLocationResolver::`vftable';
  v2 = (AK::StreamMgr::IAkIOHookDeferred *)&this->vfptr;
  v2->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&AK::StreamMgr::IAkLowLevelIOHook::`vftable';
  v2->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&AK::StreamMgr::IAkIOHookDeferred::`vftable';
  UFG::WwiseFileLocationBase::WwiseFileLocationBase((UFG::WwiseFileLocationBase *)&this->vfptr);
  v1->vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&UFG::WwiseDefaultIOHookDeferredBase::`vftable'{for `AK::StreamMgr::IAkFileLocationResolver'};
  v2->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&UFG::WwiseDefaultIOHookDeferredBase::`vftable'{for `AK::StreamMgr::IAkIOHookDeferred'};
  v1->vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseDefaultIOHookDeferredBase::`vftable'{for `UFG::WwiseFileLocationBase'};
  v1->m_blockSize = 0;
  v1->m_WwiseDevice = -1;
  v1->m_bAsyncOpen = 0;
  v1->m_name.mUID = -1;
  v1->m_priority = 1;
}

// File Line: 39
// RVA: 0x141790
void __fastcall UFG::WwiseDefaultIOHookDeferredBase::~WwiseDefaultIOHookDeferredBase(UFG::WwiseDefaultIOHookDeferredBase *this)
{
  UFG::WwiseDefaultIOHookDeferredBase *v1; // rdi
  AK::StreamMgr::IAkIOHookDeferred *v2; // rbx
  UFG::WwiseFileLocationBase *v3; // rcx

  v1 = this;
  this->vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&UFG::WwiseDefaultIOHookDeferredBase::`vftable'{for `AK::StreamMgr::IAkFileLocationResolver'};
  v2 = (AK::StreamMgr::IAkIOHookDeferred *)&this->vfptr;
  this->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&UFG::WwiseDefaultIOHookDeferredBase::`vftable'{for `AK::StreamMgr::IAkIOHookDeferred'};
  v3 = (UFG::WwiseFileLocationBase *)&this->vfptr;
  v3->vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseDefaultIOHookDeferredBase::`vftable'{for `UFG::WwiseFileLocationBase'};
  UFG::WwiseFileLocationBase::~WwiseFileLocationBase(v3);
  v2->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&AK::StreamMgr::IAkIOHookDeferred::`vftable';
  v2->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&AK::StreamMgr::IAkLowLevelIOHook::`vftable';
  v1->vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&AK::StreamMgr::IAkFileLocationResolver::`vftable';
}

// File Line: 50
// RVA: 0x147D60
void __fastcall UFG::WwiseDefaultIOHookDeferredBase::KillAllTransfers(UFG::WwiseDefaultIOHookDeferredBase *this)
{
  UFG::qList<UFG::AudioTransferInfo,UFG::AudioTransferInfo,1,0> *v1; // rbx
  UFG::qNode<UFG::AudioTransferInfo,UFG::AudioTransferInfo> *i; // rbx
  UFG::qNode<UFG::AudioTransferInfo,UFG::AudioTransferInfo> *v3; // rcx
  UFG::qNode<UFG::AudioTransferInfo,UFG::AudioTransferInfo> *v4; // rax
  UFG::qNode<UFG::AudioTransferInfo,UFG::AudioTransferInfo> *v5; // rdx
  UFG::qNode<UFG::AudioTransferInfo,UFG::AudioTransferInfo> *v6; // rax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::WwiseDefaultIOHookDeferredBase::sm_KillTransfersLock);
  UFG::WwiseDefaultIOHookDeferredBase::sm_bKillTransfers = 1;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::WwiseDefaultIOHookDeferredBase::sm_KillTransfersLock);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::WwiseDefaultIOHookDeferredBase::sm_ioTransferLock);
  v1 = (UFG::qList<UFG::AudioTransferInfo,UFG::AudioTransferInfo,1,0> *)UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo.mNode.mNext;
  if ( (UFG::qList<UFG::AudioTransferInfo,UFG::AudioTransferInfo,1,0> *)UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo.mNode.mNext != &UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo )
  {
    do
    {
      ((void (__fastcall *)(UFG::qNode<UFG::AudioTransferInfo,UFG::AudioTransferInfo> *, signed __int64))v1[1].mNode.mPrev[1].mNext)(
        v1[1].mNode.mPrev,
        2i64);
      v1 = (UFG::qList<UFG::AudioTransferInfo,UFG::AudioTransferInfo,1,0> *)v1->mNode.mNext;
    }
    while ( v1 != &UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo );
    for ( i = UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo.mNode.mNext;
          (UFG::qList<UFG::AudioTransferInfo,UFG::AudioTransferInfo,1,0> *)UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo.mNode.mNext != &UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo;
          i = UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo.mNode.mNext )
    {
      v3 = i->mPrev;
      v4 = i->mNext;
      v3->mNext = v4;
      v4->mPrev = v3;
      i->mPrev = i;
      i->mNext = i;
      i[1].mPrev = 0i64;
      i[1].mNext = 0i64;
      LODWORD(i[2].mPrev) = 0;
      v5 = i->mPrev;
      v6 = i->mNext;
      v5->mNext = v6;
      v6->mPrev = v5;
      i->mPrev = i;
      i->mNext = i;
      operator delete[](i);
    }
  }
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::WwiseDefaultIOHookDeferredBase::sm_ioTransferLock);
}

// File Line: 178
// RVA: 0x144AB0
__int64 __fastcall UFG::WwiseDefaultIOHookDeferredBase::DetermineStreamPriority(UFG::WwiseDefaultIOHookDeferredBase *this, const wchar_t *in_pszFileName, AkFileSystemFlags *in_pFlags)
{
  return (unsigned int)this->m_priority;
}

// File Line: 192
// RVA: 0x144A40
__int64 __fastcall UFG::WwiseDefaultIOHookDeferredBase::DetermineStreamPriority(UFG::WwiseDefaultIOHookDeferredBase *this, unsigned int in_fileID, AkFileSystemFlags *in_pFlags)
{
  WWiseOSFileWrapper::QUEUE_CLASS v3; // ebx
  UFG::qBaseTreeRB *v4; // rax
  signed __int64 v5; // rcx
  __int64 v6; // rax
  unsigned int v7; // edx
  unsigned int v8; // eax

  v3 = this->m_priority;
  if ( in_pFlags->uCodecID )
    return (unsigned int)v3;
  if ( !in_fileID
    || (v4 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, in_fileID)) == 0i64
    || (v5 = (signed __int64)&v4[-1].mCount, v4 == (UFG::qBaseTreeRB *)8) )
  {
    return 1;
  }
  v6 = *(_QWORD *)(v5 + 120);
  v7 = *(_DWORD *)(v5 + 80);
  if ( v6 )
  {
    v8 = *(_DWORD *)(v6 + 96);
    if ( v8 > v7 )
      v7 = v8;
  }
  if ( v7 >= 8 )
    v3 = 0;
  return (unsigned int)v3;
}

// File Line: 205
// RVA: 0x144A20
_BOOL8 __fastcall UFG::WwiseDefaultIOHookDeferredBase::DetermineStreamPriority(UFG::WwiseDefaultIOHookDeferredBase *this, AkIoHeuristics *in_heuristics, WWiseOSFileWrapper::QUEUE_CLASS priority)
{
  _BOOL8 result; // rax

  if ( priority )
    result = (float)in_heuristics->priority < 80.0;
  else
    result = 0i64;
  return result;
}

