// File Line: 158
// RVA: 0xAA31C0
unsigned int __fastcall AK::StreamMgr::CAkDeviceBase::DestroyMemView(
        AK::StreamMgr::CAkDeviceBase *this,
        AK::StreamMgr::CAkStmMemView *in_pMemView)
{
  AK::StreamMgr::AkMemBlock *m_pBlock; // rdx
  unsigned int result; // eax
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rcx

  m_pBlock = in_pMemView->m_pBlock;
  result = 0;
  in_pMemView->m_pBlock = 0i64;
  if ( m_pBlock )
    result = AK::StreamMgr::CAkIOMemMgr::ReleaseBlock(&this->m_mgrMemIO, m_pBlock);
  m_pFirst = this->m_poolStmMemView.m_pFirst;
  if ( m_pFirst )
  {
    in_pMemView->pNextView = m_pFirst;
    this->m_poolStmMemView.m_pFirst = in_pMemView;
  }
  else
  {
    this->m_poolStmMemView.m_pFirst = in_pMemView;
    in_pMemView->pNextView = 0i64;
  }
  return result;
}

// File Line: 381
// RVA: 0xAA4090
void __fastcall AK::StreamMgr::CAkStmTask::OnFileDeferredOpen(AK::StreamMgr::CAkStmTask *this)
{
  *((_BYTE *)this + 117) |= 0x10u;
}

// File Line: 796
// RVA: 0xAA3A60
wchar_t *__fastcall AK::StreamMgr::CAkAutoStmBase::GetFileDescriptor(AK::StreamMgr::CAkStdStmBase *this)
{
  return this[-1].m_pszStreamName;
}

// File Line: 1015
// RVA: 0xAA3120
void __fastcall AK::StreamMgr::CAkAutoStmBase::DestroyBuffer(
        AK::StreamMgr::CAkAutoStmBase *this,
        AK::StreamMgr::CAkStmMemView *in_pMemView)
{
  AK::StreamMgr::AkMemBlock *m_pBlock; // r8
  __int64 m_uOffsetInBlock; // r9
  unsigned __int64 uPosition; // r10
  unsigned __int64 m_uLoopEnd; // rdx
  unsigned int uAvailableSize; // edx
  AK::StreamMgr::CAkDeviceBase *m_pDevice; // rdi
  AK::StreamMgr::AkMemBlock *v9; // rdx
  AK::StreamMgr::CAkStmMemView *m_pFirst; // rax

  m_pBlock = in_pMemView->m_pBlock;
  m_uOffsetInBlock = in_pMemView->m_uOffsetInBlock;
  uPosition = m_pBlock->uPosition;
  m_uLoopEnd = this->m_uLoopEnd;
  if ( m_pBlock->uPosition + m_uOffsetInBlock >= m_uLoopEnd || uPosition + m_pBlock->uAvailableSize <= m_uLoopEnd )
    uAvailableSize = m_pBlock->uAvailableSize;
  else
    uAvailableSize = m_uLoopEnd - uPosition;
  m_pDevice = this->m_pDevice;
  this->m_uVirtualBufferingSize -= uAvailableSize - m_uOffsetInBlock;
  v9 = in_pMemView->m_pBlock;
  in_pMemView->m_pBlock = 0i64;
  if ( v9 )
    AK::StreamMgr::CAkIOMemMgr::ReleaseBlock(&m_pDevice->m_mgrMemIO, v9);
  m_pFirst = m_pDevice->m_poolStmMemView.m_pFirst;
  if ( m_pFirst )
  {
    in_pMemView->pNextView = m_pFirst;
    m_pDevice->m_poolStmMemView.m_pFirst = in_pMemView;
  }
  else
  {
    m_pDevice->m_poolStmMemView.m_pFirst = in_pMemView;
    in_pMemView->pNextView = 0i64;
  }
}

