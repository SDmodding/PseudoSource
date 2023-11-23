// File Line: 179
// RVA: 0xAA5F60
void __fastcall AK::StreamMgr::CAkDeviceBlocking::OnLowLevelTransferComplete(
        AK::StreamMgr::CAkDeviceBlocking *this,
        AK::StreamMgr::CAkStmMemView *in_pOwnerView,
        AKRESULT in_eResult,
        bool __formal)
{
  AK::StreamMgr::AkMemBlock *m_pBlock; // rdx

  EnterCriticalSection(&this->m_lockSems.m_csLock);
  m_pBlock = in_pOwnerView->m_pBlock;
  m_pBlock->pNextBlock = 0i64;
  if ( in_eResult != AK_Success && m_pBlock->fileID != -1 )
    AK::StreamMgr::CAkIOMemMgr::UntagBlock(&this->m_mgrMemIO, m_pBlock);
  LeaveCriticalSection(&this->m_lockSems.m_csLock);
}

