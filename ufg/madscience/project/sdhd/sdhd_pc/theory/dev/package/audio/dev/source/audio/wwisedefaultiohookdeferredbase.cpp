// File Line: 25
// RVA: 0x14653B0
__int64 dynamic_initializer_for__UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo__);
}

// File Line: 26
// RVA: 0x14651F0
__int64 dynamic_initializer_for__UFG::WwiseDefaultIOHookDeferredBase::sm_ioTransferLock__()
{
  UFG::qMutex::qMutex(&UFG::WwiseDefaultIOHookDeferredBase::sm_ioTransferLock, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WwiseDefaultIOHookDeferredBase::sm_ioTransferLock__);
}

// File Line: 27
// RVA: 0x1464FC0
__int64 dynamic_initializer_for__UFG::WwiseDefaultIOHookDeferredBase::sm_KillTransfersLock__()
{
  UFG::qMutex::qMutex(&UFG::WwiseDefaultIOHookDeferredBase::sm_KillTransfersLock, &customCaption);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::WwiseDefaultIOHookDeferredBase::sm_KillTransfersLock__);
}

// File Line: 35
// RVA: 0x140B20
void __fastcall UFG::WwiseDefaultIOHookDeferredBase::WwiseDefaultIOHookDeferredBase(
        UFG::WwiseDefaultIOHookDeferredBase *this)
{
  AK::StreamMgr::IAkIOHookDeferred *v2; // rdi

  this->AK::StreamMgr::IAkFileLocationResolver::vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&AK::StreamMgr::IAkFileLocationResolver::`vftable;
  v2 = &this->AK::StreamMgr::IAkIOHookDeferred;
  this->AK::StreamMgr::IAkIOHookDeferred::AK::StreamMgr::IAkLowLevelIOHook::vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&AK::StreamMgr::IAkLowLevelIOHook::`vftable;
  this->AK::StreamMgr::IAkIOHookDeferred::AK::StreamMgr::IAkLowLevelIOHook::vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&AK::StreamMgr::IAkIOHookDeferred::`vftable;
  UFG::WwiseFileLocationBase::WwiseFileLocationBase(&this->UFG::WwiseFileLocationBase);
  this->AK::StreamMgr::IAkFileLocationResolver::vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&UFG::WwiseDefaultIOHookDeferredBase::`vftable{for `AK::StreamMgr::IAkFileLocationResolver};
  v2->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&UFG::WwiseDefaultIOHookDeferredBase::`vftable{for `AK::StreamMgr::IAkIOHookDeferred};
  this->UFG::WwiseFileLocationBase::vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseDefaultIOHookDeferredBase::`vftable{for `UFG::WwiseFileLocationBase};
  this->m_blockSize = 0;
  this->m_WwiseDevice = -1;
  this->m_bAsyncOpen = 0;
  this->m_name.mUID = -1;
  this->m_priority = STREAM_AUDIO_LOW_PRIORITY;
}

// File Line: 39
// RVA: 0x141790
void __fastcall UFG::WwiseDefaultIOHookDeferredBase::~WwiseDefaultIOHookDeferredBase(
        UFG::WwiseDefaultIOHookDeferredBase *this)
{
  AK::StreamMgr::IAkIOHookDeferred *v2; // rbx
  UFG::WwiseFileLocationBase *v3; // rcx

  this->AK::StreamMgr::IAkFileLocationResolver::vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&UFG::WwiseDefaultIOHookDeferredBase::`vftable{for `AK::StreamMgr::IAkFileLocationResolver};
  v2 = &this->AK::StreamMgr::IAkIOHookDeferred;
  this->AK::StreamMgr::IAkIOHookDeferred::AK::StreamMgr::IAkLowLevelIOHook::vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&UFG::WwiseDefaultIOHookDeferredBase::`vftable{for `AK::StreamMgr::IAkIOHookDeferred};
  v3 = &this->UFG::WwiseFileLocationBase;
  v3->vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseDefaultIOHookDeferredBase::`vftable{for `UFG::WwiseFileLocationBase};
  UFG::WwiseFileLocationBase::~WwiseFileLocationBase(v3);
  v2->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&AK::StreamMgr::IAkIOHookDeferred::`vftable;
  v2->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&AK::StreamMgr::IAkLowLevelIOHook::`vftable;
  this->AK::StreamMgr::IAkFileLocationResolver::vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&AK::StreamMgr::IAkFileLocationResolver::`vftable;
}

// File Line: 50
// RVA: 0x147D60
void __fastcall UFG::WwiseDefaultIOHookDeferredBase::KillAllTransfers(UFG::WwiseDefaultIOHookDeferredBase *this)
{
  UFG::qList<UFG::AudioTransferInfo,UFG::AudioTransferInfo,1,0> *mNext; // rbx
  UFG::qNode<UFG::AudioTransferInfo,UFG::AudioTransferInfo> *i; // rbx
  UFG::qNode<UFG::AudioTransferInfo,UFG::AudioTransferInfo> *mPrev; // rcx
  UFG::qNode<UFG::AudioTransferInfo,UFG::AudioTransferInfo> *v4; // rax
  UFG::qNode<UFG::AudioTransferInfo,UFG::AudioTransferInfo> *v5; // rdx
  UFG::qNode<UFG::AudioTransferInfo,UFG::AudioTransferInfo> *v6; // rax

  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::WwiseDefaultIOHookDeferredBase::sm_KillTransfersLock);
  UFG::WwiseDefaultIOHookDeferredBase::sm_bKillTransfers = 1;
  UFG::qMutex::Unlock((LPCRITICAL_SECTION)&UFG::WwiseDefaultIOHookDeferredBase::sm_KillTransfersLock);
  UFG::qMutex::Lock((LPCRITICAL_SECTION)&UFG::WwiseDefaultIOHookDeferredBase::sm_ioTransferLock);
  mNext = (UFG::qList<UFG::AudioTransferInfo,UFG::AudioTransferInfo,1,0> *)UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo.mNode.mNext;
  if ( (UFG::qList<UFG::AudioTransferInfo,UFG::AudioTransferInfo,1,0> *)UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo.mNode.mNext != &UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo )
  {
    do
    {
      ((void (__fastcall *)(UFG::qNode<UFG::AudioTransferInfo,UFG::AudioTransferInfo> *, __int64))mNext[1].mNode.mPrev[1].mNext)(
        mNext[1].mNode.mPrev,
        2i64);
      mNext = (UFG::qList<UFG::AudioTransferInfo,UFG::AudioTransferInfo,1,0> *)mNext->mNode.mNext;
    }
    while ( mNext != &UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo );
    for ( i = UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo.mNode.mNext;
          (UFG::qList<UFG::AudioTransferInfo,UFG::AudioTransferInfo,1,0> *)UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo.mNode.mNext != &UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo;
          i = UFG::WwiseDefaultIOHookDeferredBase::sm_transInfo.mNode.mNext )
    {
      mPrev = i->mPrev;
      v4 = i->mNext;
      mPrev->mNext = v4;
      v4->mPrev = mPrev;
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
__int64 __fastcall UFG::WwiseDefaultIOHookDeferredBase::DetermineStreamPriority(
        UFG::WwiseDefaultIOHookDeferredBase *this,
        const wchar_t *in_pszFileName,
        AkFileSystemFlags *in_pFlags)
{
  return (unsigned int)this->m_priority;
}

// File Line: 192
// RVA: 0x144A40
__int64 __fastcall UFG::WwiseDefaultIOHookDeferredBase::DetermineStreamPriority(
        UFG::WwiseDefaultIOHookDeferredBase *this,
        unsigned int in_fileID,
        AkFileSystemFlags *in_pFlags)
{
  WWiseOSFileWrapper::QUEUE_CLASS m_priority; // ebx
  UFG::qBaseTreeRB *v4; // rax
  int *p_mCount; // rcx
  __int64 v6; // rax
  unsigned int v7; // edx
  unsigned int v8; // eax

  m_priority = this->m_priority;
  if ( in_pFlags->uCodecID )
    return (unsigned int)m_priority;
  if ( !in_fileID )
    return 1;
  if ( (v4 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, in_fileID)) == 0i64 )
    return 1;
  p_mCount = &v4[-1].mCount;
  if ( v4 == (UFG::qBaseTreeRB *)8 )
    return 1;
  v6 = *((_QWORD *)p_mCount + 15);
  v7 = p_mCount[20];
  if ( v6 )
  {
    v8 = *(_DWORD *)(v6 + 96);
    if ( v8 > v7 )
      v7 = v8;
  }
  if ( v7 >= 8 )
    return 0;
  return (unsigned int)m_priority;
}

// File Line: 205
// RVA: 0x144A20
_BOOL8 __fastcall UFG::WwiseDefaultIOHookDeferredBase::DetermineStreamPriority(
        UFG::WwiseDefaultIOHookDeferredBase *this,
        AkIoHeuristics *in_heuristics,
        WWiseOSFileWrapper::QUEUE_CLASS priority)
{
  return priority && (float)in_heuristics->priority < 80.0;
}

