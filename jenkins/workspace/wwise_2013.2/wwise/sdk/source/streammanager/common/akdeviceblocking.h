// File Line: 179
// RVA: 0xAA5F60
void __fastcall AK::StreamMgr::CAkDeviceBlocking::OnLowLevelTransferComplete(AK::StreamMgr::CAkDeviceBlocking *this, AK::StreamMgr::CAkStmMemView *in_pOwnerView, AKRESULT in_eResult, bool __formal)
{
  AK::StreamMgr::CAkDeviceBlocking *v4; // rbp
  AKRESULT v5; // edi
  AK::StreamMgr::CAkStmMemView *v6; // rbx
  AK::StreamMgr::AkMemBlock *v7; // rdx

  v4 = this;
  v5 = in_eResult;
  v6 = in_pOwnerView;
  EnterCriticalSection(&this->m_lockSems.m_csLock);
  v7 = v6->m_pBlock;
  v7->pNextBlock = 0i64;
  if ( v5 != 1 && v7->fileID != -1 )
    AK::StreamMgr::CAkIOMemMgr::UntagBlock(&v4->m_mgrMemIO, v7);
  LeaveCriticalSection(&v4->m_lockSems.m_csLock);
}

