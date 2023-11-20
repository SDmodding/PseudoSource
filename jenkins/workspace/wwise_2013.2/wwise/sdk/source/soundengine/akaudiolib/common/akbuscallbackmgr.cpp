// File Line: 25
// RVA: 0xA59BA0
void __fastcall CAkBusCallbackMgr::CAkBusCallbackMgr(CAkSegmentInfoRepository *this)
{
  _RTL_CRITICAL_SECTION *v1; // rcx

  v1 = &this->m_lock.m_csLock;
  v1[-1].LockSemaphore = 0i64;
  v1[-1].SpinCount = 0i64;
  InitializeCriticalSection(v1);
}

// File Line: 29
// RVA: 0xA59BD0
void __fastcall CAkBusCallbackMgr::~CAkBusCallbackMgr(CAkBusCallbackMgr *this)
{
  MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *v1; // rdx
  CAkBusCallbackMgr *v2; // rbx

  v1 = this->m_ListCallbacks.m_pItems;
  v2 = this;
  if ( this->m_ListCallbacks.m_pItems )
  {
    this->m_ListCallbacks.m_uLength = 0;
    AK::MemoryMgr::Free(g_DefaultPoolId, v1);
    v2->m_ListCallbacks.m_pItems = 0i64;
    v2->m_ListCallbacks.m_ulReserved = 0;
  }
  DeleteCriticalSection(&v2->m_csLock.m_csLock);
}

// File Line: 59
// RVA: 0xA59C20
__int64 __fastcall CAkBusCallbackMgr::DoCallback(CAkBusCallbackMgr *this, AkSpeakerVolumeMatrixBusCallbackInfo *in_rCallbackInfo)
{
  _RTL_CRITICAL_SECTION *v2; // rbx
  CAkBusCallbackMgr *v3; // rdi
  AkSpeakerVolumeMatrixBusCallbackInfo *v4; // rsi
  MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *v5; // rax
  signed __int64 v6; // rcx
  void (__fastcall **v7)(AkSpeakerVolumeMatrixBusCallbackInfo *); // rax
  unsigned __int8 v8; // di

  v2 = &this->m_csLock.m_csLock;
  v3 = this;
  v4 = in_rCallbackInfo;
  EnterCriticalSection(&this->m_csLock.m_csLock);
  v5 = v3->m_ListCallbacks.m_pItems;
  v6 = (signed __int64)&v3->m_ListCallbacks.m_pItems[v3->m_ListCallbacks.m_uLength];
  if ( v3->m_ListCallbacks.m_pItems == (MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *)v6 )
    goto LABEL_11;
  do
  {
    if ( v5->key == v4->busID )
      break;
    ++v5;
  }
  while ( v5 != (MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *)v6 );
  if ( v5 != (MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *)v6
    && (v7 = &v5->item) != 0i64 )
  {
    (*v7)(v4);
    v8 = 1;
  }
  else
  {
LABEL_11:
    v8 = 0;
  }
  LeaveCriticalSection(v2);
  return v8;
}

// File Line: 71
// RVA: 0xA59CA0
bool __fastcall CAkBusCallbackMgr::IsCallbackEnabled(CAkBusCallbackMgr *this, unsigned int in_busID)
{
  _RTL_CRITICAL_SECTION *v2; // rbx
  CAkBusCallbackMgr *v3; // rdi
  unsigned int v4; // esi
  MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *v5; // rax
  signed __int64 v6; // rcx
  signed __int64 v7; // rdi

  v2 = &this->m_csLock.m_csLock;
  v3 = this;
  v4 = in_busID;
  EnterCriticalSection(&this->m_csLock.m_csLock);
  v5 = v3->m_ListCallbacks.m_pItems;
  v6 = (signed __int64)&v3->m_ListCallbacks.m_pItems[v3->m_ListCallbacks.m_uLength];
  if ( v3->m_ListCallbacks.m_pItems == (MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *)v6 )
    goto LABEL_10;
  do
  {
    if ( v5->key == v4 )
      break;
    ++v5;
  }
  while ( v5 != (MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *)v6 );
  if ( v5 == (MapStruct<unsigned long,void (__cdecl*)(AkSpeakerVolumeMatrixBusCallbackInfo *)> *)v6 )
LABEL_10:
    v7 = 0i64;
  else
    v7 = (signed __int64)&v5->item;
  LeaveCriticalSection(v2);
  return v7 != 0;
}

