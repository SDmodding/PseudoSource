// File Line: 25
// RVA: 0xA59BA0
void __fastcall CAkBusCallbackMgr::CAkBusCallbackMgr(CAkSegmentInfoRepository *this)
{
  CAkLock *p_m_lock; // rcx

  p_m_lock = &this->m_lock;
  p_m_lock[-1].m_csLock.LockSemaphore = 0i64;
  p_m_lock[-1].m_csLock.SpinCount = 0i64;
  InitializeCriticalSection(&p_m_lock->m_csLock);
}

// File Line: 29
// RVA: 0xA59BD0
void __fastcall CAkBusCallbackMgr::~CAkBusCallbackMgr(CAkBusCallbackMgr *this)
{
  MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *m_pItems; // rdx

  m_pItems = this->m_ListCallbacks.m_pItems;
  if ( this->m_ListCallbacks.m_pItems )
  {
    this->m_ListCallbacks.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pItems);
    this->m_ListCallbacks.m_pItems = 0i64;
    this->m_ListCallbacks.m_ulReserved = 0;
  }
  DeleteCriticalSection(&this->m_csLock.m_csLock);
}

// File Line: 59
// RVA: 0xA59C20
__int64 __fastcall CAkBusCallbackMgr::DoCallback(
        CAkBusCallbackMgr *this,
        AkSpeakerVolumeMatrixBusCallbackInfo *in_rCallbackInfo)
{
  CAkLock *p_m_csLock; // rbx
  MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *m_pItems; // rax
  MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *v6; // rcx
  void (__fastcall **p_item)(AkSpeakerVolumeMatrixBusCallbackInfo *); // rax
  unsigned __int8 v8; // di

  p_m_csLock = &this->m_csLock;
  EnterCriticalSection(&this->m_csLock.m_csLock);
  m_pItems = this->m_ListCallbacks.m_pItems;
  v6 = &this->m_ListCallbacks.m_pItems[this->m_ListCallbacks.m_uLength];
  if ( this->m_ListCallbacks.m_pItems == v6 )
    goto LABEL_7;
  do
  {
    if ( m_pItems->key == in_rCallbackInfo->busID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v6 );
  if ( m_pItems == v6 || (p_item = &m_pItems->item) == 0i64 )
  {
LABEL_7:
    v8 = 0;
  }
  else
  {
    (*p_item)(in_rCallbackInfo);
    v8 = 1;
  }
  LeaveCriticalSection(&p_m_csLock->m_csLock);
  return v8;
}

// File Line: 71
// RVA: 0xA59CA0
bool __fastcall CAkBusCallbackMgr::IsCallbackEnabled(CAkBusCallbackMgr *this, unsigned int in_busID)
{
  CAkLock *p_m_csLock; // rbx
  MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *m_pItems; // rax
  MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *v6; // rcx
  void (__fastcall **p_item)(AkSpeakerVolumeMatrixBusCallbackInfo *); // rdi

  p_m_csLock = &this->m_csLock;
  EnterCriticalSection(&this->m_csLock.m_csLock);
  m_pItems = this->m_ListCallbacks.m_pItems;
  v6 = &this->m_ListCallbacks.m_pItems[this->m_ListCallbacks.m_uLength];
  if ( this->m_ListCallbacks.m_pItems == v6 )
    goto LABEL_6;
  do
  {
    if ( m_pItems->key == in_busID )
      break;
    ++m_pItems;
  }
  while ( m_pItems != v6 );
  if ( m_pItems == v6 )
LABEL_6:
    p_item = 0i64;
  else
    p_item = &m_pItems->item;
  LeaveCriticalSection(&p_m_csLock->m_csLock);
  return p_item != 0i64;
}

