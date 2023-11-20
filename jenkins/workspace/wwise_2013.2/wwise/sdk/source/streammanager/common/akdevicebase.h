// File Line: 158
// RVA: 0xAA31C0
unsigned int __fastcall AK::StreamMgr::CAkDeviceBase::DestroyMemView(AK::StreamMgr::CAkDeviceBase *this, AK::StreamMgr::CAkStmMemView *in_pMemView)
{
  AK::StreamMgr::CAkStmMemView *v2; // rbx
  AK::StreamMgr::AkMemBlock *v3; // rdx
  unsigned int result; // eax
  AK::StreamMgr::CAkDeviceBase *v5; // rdi
  AK::StreamMgr::CAkStmMemView *v6; // rcx

  v2 = in_pMemView;
  v3 = in_pMemView->m_pBlock;
  result = 0;
  v5 = this;
  v2->m_pBlock = 0i64;
  if ( v3 )
    result = AK::StreamMgr::CAkIOMemMgr::ReleaseBlock(&this->m_mgrMemIO, v3);
  v6 = v5->m_poolStmMemView.m_pFirst;
  if ( v6 )
  {
    v2->pNextView = v6;
    v5->m_poolStmMemView.m_pFirst = v2;
  }
  else
  {
    v5->m_poolStmMemView.m_pFirst = v2;
    v2->pNextView = 0i64;
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
void __fastcall AK::StreamMgr::CAkAutoStmBase::DestroyBuffer(AK::StreamMgr::CAkAutoStmBase *this, AK::StreamMgr::CAkStmMemView *in_pMemView)
{
  AK::StreamMgr::AkMemBlock *v2; // r8
  __int64 v3; // r9
  AK::StreamMgr::CAkStmMemView *v4; // rbx
  unsigned __int64 v5; // r10
  unsigned __int64 v6; // rdx
  unsigned int v7; // edx
  AK::StreamMgr::CAkDeviceBase *v8; // rdi
  AK::StreamMgr::AkMemBlock *v9; // rdx
  AK::StreamMgr::CAkStmMemView *v10; // rax

  v2 = in_pMemView->m_pBlock;
  v3 = in_pMemView->m_uOffsetInBlock;
  v4 = in_pMemView;
  v5 = v2->uPosition;
  v6 = this->m_uLoopEnd;
  if ( v2->uPosition + v3 >= v6 || v5 + v2->uAvailableSize <= v6 )
    v7 = v2->uAvailableSize;
  else
    v7 = v6 - v5;
  v8 = this->m_pDevice;
  this->m_uVirtualBufferingSize -= v7 - v3;
  v9 = v4->m_pBlock;
  v4->m_pBlock = 0i64;
  if ( v9 )
    AK::StreamMgr::CAkIOMemMgr::ReleaseBlock(&v8->m_mgrMemIO, v9);
  v10 = v8->m_poolStmMemView.m_pFirst;
  if ( v10 )
  {
    v4->pNextView = v10;
    v8->m_poolStmMemView.m_pFirst = v4;
  }
  else
  {
    v8->m_poolStmMemView.m_pFirst = v4;
    v4->pNextView = 0i64;
  }
}

