// File Line: 36
// RVA: 0x15BE0E0
__int64 dynamic_initializer_for__AK::StreamMgr::CAkStreamMgr::m_arDevices__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__AK::StreamMgr::CAkStreamMgr::m_arDevices__);
}

// File Line: 41
// RVA: 0x15BE0F0
__int64 dynamic_initializer_for__AK::StreamMgr::CAkStreamMgr::m_arLangChgObserver__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__AK::StreamMgr::CAkStreamMgr::m_arLangChgObserver__);
}

// File Line: 62
// RVA: 0xAA1A50
AK::IAkStreamMgr *__fastcall AK::StreamMgr::Create(AkStreamMgrSettings *in_settings)
{
  AK::IAkStreamMgr *result; // rax
  int Pool; // eax

  if ( !AK::MemoryMgr::IsInitialized() )
    return 0i64;
  result = AK::IAkStreamMgr::m_pStreamMgr;
  if ( !AK::IAkStreamMgr::m_pStreamMgr )
  {
    Pool = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
    m_szCurrentLanguage[0] = 0;
    if ( AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId == -1 )
    {
      Pool = AK::MemoryMgr::CreatePool(0i64, in_settings->uMemorySize, 0x20u, 1u, 0);
      AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId = Pool;
      if ( Pool == -1 )
        return 0i64;
    }
    result = (AK::IAkStreamMgr *)AK::MemoryMgr::Malloc(Pool, 8ui64);
    if ( result )
    {
      result->vfptr = (AK::IAkStreamMgrVtbl *)&AK::StreamMgr::CAkStreamMgr::`vftable;
      AK::IAkStreamMgr::m_pStreamMgr = result;
    }
    else
    {
      AK::MemoryMgr::DestroyPool(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId);
      return AK::IAkStreamMgr::m_pStreamMgr;
    }
  }
  return result;
}

// File Line: 122
// RVA: 0xAA2540
void __fastcall AK::StreamMgr::GetDefaultSettings(AkStreamMgrSettings *out_settings)
{
  out_settings->uMemorySize = 0x10000;
}

// File Line: 129
// RVA: 0xAA24F0
void __fastcall AK::StreamMgr::GetDefaultDeviceSettings(AkDeviceSettings *out_settings)
{
  out_settings->uIOMemorySize = 0x200000;
  out_settings->uIOMemoryAlignment = 4;
  out_settings->ePoolAttributes = AkVirtualAlloc;
  out_settings->uGranularity = 0x4000;
  out_settings->uSchedulerTypeFlags = 1;
  out_settings->pIOMemory = 0i64;
  out_settings->threadProperties.uStackSize = 0x10000;
  *(_QWORD *)&out_settings->threadProperties.nPriority = 1i64;
  out_settings->fTargetAutoStmBufferLength = 380.0;
  out_settings->uMaxConcurrentIO = 8;
  out_settings->fMaxCacheRatio = 1.0;
}

// File Line: 150
// RVA: 0xAA2550
AK::StreamMgr::IAkFileLocationResolver *__fastcall AK::StreamMgr::GetFileLocationResolver()
{
  return AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver;
}

// File Line: 159
// RVA: 0xAA2650
void __fastcall AK::StreamMgr::SetFileLocationResolver(
        AK::StreamMgr::IAkFileLocationResolver *in_pFileLocationResolver)
{
  AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver = in_pFileLocationResolver;
}

// File Line: 175
// RVA: 0xAA2040
__int64 __fastcall AK::StreamMgr::CreateDevice(
        AkDeviceSettings *in_settings,
        AK::StreamMgr::IAkLowLevelIOHook *in_pLowLevelHook)
{
  return AK::StreamMgr::CAkStreamMgr::CreateDevice(
           (AK::StreamMgr::CAkStreamMgr *)AK::IAkStreamMgr::m_pStreamMgr,
           in_settings,
           in_pLowLevelHook);
}

// File Line: 181
// RVA: 0xAA2420
__int64 __fastcall AK::StreamMgr::DestroyDevice(unsigned int in_deviceID)
{
  __int64 v1; // rbx
  AK::StreamMgr::CAkDeviceBase *v2; // rcx

  if ( in_deviceID >= AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
    return 31i64;
  v1 = in_deviceID;
  v2 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[v1];
  if ( !v2 )
    return 31i64;
  v2->vfptr[1].PerformIO(v2);
  AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[v1] = 0i64;
  return 1i64;
}

// File Line: 234
// RVA: 0xAA19C0
AK::StreamMgr::AkDeferredOpenData *__fastcall AK::StreamMgr::AkDeferredOpenData::Create(
        const wchar_t *in_pszFileName,
        AkFileSystemFlags *in_pFSFlags,
        AkOpenMode in_eOpenMode)
{
  AK::StreamMgr::AkDeferredOpenData *result; // rax
  AK::StreamMgr::AkDeferredOpenData *v7; // rbx

  result = (AK::StreamMgr::AkDeferredOpenData *)AK::MemoryMgr::Malloc(
                                                  AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                                  0x30ui64);
  v7 = result;
  if ( result )
  {
    if ( AK::StreamMgr::AkDeferredOpenData::Init(result, in_pszFileName, in_pFSFlags, in_eOpenMode) == AK_Success )
    {
      return v7;
    }
    else
    {
      if ( (*((_BYTE *)v7 + 44) & 1) != 0 )
      {
        if ( v7->pszFileName )
          AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v7->pszFileName);
      }
      AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v7);
      return 0i64;
    }
  }
  return result;
}

// File Line: 253
// RVA: 0xAA1930
AK::StreamMgr::AkDeferredOpenData *__fastcall AK::StreamMgr::AkDeferredOpenData::Create(
        unsigned int in_fileID,
        AkFileSystemFlags *in_pFSFlags,
        AkOpenMode in_eOpenMode)
{
  AK::StreamMgr::AkDeferredOpenData *result; // rax
  AK::StreamMgr::AkDeferredOpenData *v7; // r9
  int v8; // eax

  result = (AK::StreamMgr::AkDeferredOpenData *)AK::MemoryMgr::Malloc(
                                                  AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                                  0x30ui64);
  v7 = result;
  if ( result )
  {
    *((_DWORD *)result + 11) &= ~1u;
    v8 = *((_DWORD *)result + 11);
    if ( in_pFSFlags )
    {
      *((_DWORD *)v7 + 11) = v8 | 2;
      *(_QWORD *)&v7->flags.uCompanyID = *(_QWORD *)&in_pFSFlags->uCompanyID;
      *(_QWORD *)&v7->flags.uCustomParamSize = *(_QWORD *)&in_pFSFlags->uCustomParamSize;
      v7->flags.pCustomParam = in_pFSFlags->pCustomParam;
      *(_QWORD *)&v7->flags.bIsLanguageSpecific = *(_QWORD *)&in_pFSFlags->bIsLanguageSpecific;
    }
    else
    {
      *((_DWORD *)v7 + 11) = v8 & 0xFFFFFFFD;
    }
    v7->fileID = in_fileID;
    v7->eOpenMode = in_eOpenMode;
    return v7;
  }
  return result;
}

// File Line: 261
// RVA: 0xAA2370
void __fastcall AK::StreamMgr::AkDeferredOpenData::Destroy(AK::StreamMgr::AkDeferredOpenData *this)
{
  if ( (*((_BYTE *)this + 44) & 1) != 0 && this->pszFileName )
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, this->pszFileName);
  AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, this);
}

// File Line: 318
// RVA: 0xAA2560
__int64 __fastcall AK::StreamMgr::AkDeferredOpenData::Init(
        AK::StreamMgr::AkDeferredOpenData *this,
        const wchar_t *in_pszFileName,
        AkFileSystemFlags *in_pFSFlags,
        AkOpenMode in_eOpenMode)
{
  int v4; // eax
  __int64 v7; // rdi
  unsigned __int64 v8; // rdi
  wchar_t *v9; // r14
  unsigned __int64 v11; // rbx
  __int64 v12; // rax
  __int64 v13; // rbx

  *((_DWORD *)this + 11) |= 1u;
  v4 = *((_DWORD *)this + 11);
  this->eOpenMode = in_eOpenMode;
  if ( in_pFSFlags )
  {
    *((_DWORD *)this + 11) = v4 | 2;
    this->flags = *in_pFSFlags;
  }
  else
  {
    *((_DWORD *)this + 11) = v4 & 0xFFFFFFFD;
  }
  v7 = -1i64;
  do
    ++v7;
  while ( in_pszFileName[v7] );
  v8 = v7 + 1;
  v9 = (wchar_t *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 2 * v8);
  this->pszFileName = v9;
  if ( !v9 )
    return 2i64;
  v11 = v8 - 1;
  v12 = -1i64;
  do
    ++v12;
  while ( in_pszFileName[v12] );
  if ( v11 >= v12 + 1 )
  {
    v13 = -1i64;
    do
      ++v13;
    while ( in_pszFileName[v13] );
    v11 = v13 + 1;
  }
  wcsncpy_s(v9, v8, in_pszFileName, v11);
  v9[v11] = 0;
  return 1i64;
}

// File Line: 379
// RVA: 0xAA23B0
void __fastcall AK::StreamMgr::CAkStreamMgr::Destroy(AK::StreamMgr::CAkStreamMgr *this)
{
  bool IsInitialized; // al
  int v3; // ebx

  AK::StreamMgr::CAkStreamMgr::Term(this);
  IsInitialized = AK::MemoryMgr::IsInitialized();
  v3 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
  if ( IsInitialized && AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId != -1 && this )
  {
    this->vfptr->__vecDelDtor(this, 0i64);
    AK::MemoryMgr::Free(v3, this);
    v3 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
  }
  AK::MemoryMgr::DestroyPool(v3);
  AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId = -1;
}

// File Line: 419
// RVA: 0xAA2660
void __fastcall AK::StreamMgr::CAkStreamMgr::Term(AK::StreamMgr::CAkStreamMgr *this)
{
  AK::StreamMgr::CAkDeviceBase **m_pItems; // rdx
  unsigned int m_uLength; // r8d
  AK::StreamMgr::CAkDeviceBase **v3; // rbx

  m_pItems = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems;
  m_uLength = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
  AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver = 0i64;
  v3 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems;
  if ( AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems != &AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength] )
  {
    do
    {
      if ( *v3 )
      {
        (*v3)->vfptr[1].PerformIO(*v3);
        m_uLength = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
        m_pItems = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems;
      }
      ++v3;
    }
    while ( v3 != &m_pItems[m_uLength] );
  }
  if ( m_pItems )
  {
    AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength = 0;
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, m_pItems);
    AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems = 0i64;
    AK::StreamMgr::CAkStreamMgr::m_arDevices.m_ulReserved = 0;
  }
  if ( AK::StreamMgr::CAkStreamMgr::m_arLangChgObserver.m_pItems )
  {
    AK::StreamMgr::CAkStreamMgr::m_arLangChgObserver.m_uLength = 0;
    AK::MemoryMgr::Free(
      AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
      AK::StreamMgr::CAkStreamMgr::m_arLangChgObserver.m_pItems);
    AK::StreamMgr::CAkStreamMgr::m_arLangChgObserver.m_pItems = 0i64;
    AK::StreamMgr::CAkStreamMgr::m_arLangChgObserver.m_ulReserved = 0;
  }
}

// File Line: 444
// RVA: 0xAA1E80
__int64 __fastcall AK::StreamMgr::CAkStreamMgr::CreateDevice(
        AK::StreamMgr::CAkStreamMgr *this,
        AkDeviceSettings *in_settings,
        AK::StreamMgr::IAkLowLevelIOHook *in_pLowLevelHook)
{
  unsigned int m_uLength; // ecx
  AK::StreamMgr::CAkDeviceBase **m_pItems; // rdi
  __int64 v5; // rbx
  AK::StreamMgr::CAkDeviceBase **v8; // rax
  unsigned int m_ulReserved; // ebx
  unsigned __int64 v10; // rsi
  AK::StreamMgr::CAkDeviceBase **v11; // rdx
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rcx
  AK::StreamMgr::CAkDeviceBase *v14; // rax
  AK::StreamMgr::CAkDeviceBase **v15; // rdx
  unsigned int uSchedulerTypeFlags; // eax
  AK::StreamMgr::CAkDeviceBlocking *v17; // rax
  AK::StreamMgr::CAkDeviceBase *v18; // rax
  AK::StreamMgr::CAkDeviceDeferredLinedUp *v19; // rax
  AK::StreamMgr::CAkDeviceBase *v20; // rdi

  m_uLength = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
  m_pItems = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems;
  v5 = 0i64;
  if ( !AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
    goto LABEL_7;
  v8 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems;
  while ( *v8 )
  {
    v5 = (unsigned int)(v5 + 1);
    ++v8;
    if ( (unsigned int)v5 >= AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
      goto LABEL_7;
  }
  if ( (_DWORD)v5 == -1 )
  {
LABEL_7:
    m_ulReserved = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_ulReserved;
    v10 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
    if ( AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength >= (unsigned __int64)AK::StreamMgr::CAkStreamMgr::m_arDevices.m_ulReserved )
    {
      m_ulReserved = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_ulReserved + 1;
      m_pItems = (AK::StreamMgr::CAkDeviceBase **)AK::MemoryMgr::Malloc(
                                                    AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                                    8i64 * (AK::StreamMgr::CAkStreamMgr::m_arDevices.m_ulReserved + 1));
      if ( !m_pItems )
        return 0xFFFFFFFFi64;
      v11 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems;
      m_uLength = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
      v12 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
      if ( AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems )
      {
        v13 = 0i64;
        if ( AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
        {
          do
          {
            v14 = v11[v13++];
            m_pItems[v13 - 1] = v14;
            v11 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems;
          }
          while ( v13 < v12 );
        }
        AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v11);
        m_uLength = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
      }
      AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems = m_pItems;
      AK::StreamMgr::CAkStreamMgr::m_arDevices.m_ulReserved = m_ulReserved;
    }
    if ( v10 >= m_ulReserved )
      return 0xFFFFFFFFi64;
    v15 = &m_pItems[m_uLength];
    AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength = m_uLength + 1;
    if ( !v15 )
      return 0xFFFFFFFFi64;
    *v15 = 0i64;
    v5 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength - 1;
    AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength - 1] = 0i64;
  }
  uSchedulerTypeFlags = in_settings->uSchedulerTypeFlags;
  if ( (uSchedulerTypeFlags & 1) != 0 )
  {
    v17 = (AK::StreamMgr::CAkDeviceBlocking *)AK::MemoryMgr::Malloc(
                                                AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                                0x138ui64);
    if ( !v17 )
      return 0xFFFFFFFFi64;
    AK::StreamMgr::CAkDeviceBlocking::CAkDeviceBlocking(v17, in_pLowLevelHook);
  }
  else
  {
    if ( (uSchedulerTypeFlags & 2) == 0 )
      return 0xFFFFFFFFi64;
    v19 = (AK::StreamMgr::CAkDeviceDeferredLinedUp *)AK::MemoryMgr::Malloc(
                                                       AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                                       0x130ui64);
    if ( !v19 )
      return 0xFFFFFFFFi64;
    AK::StreamMgr::CAkDeviceDeferredLinedUp::CAkDeviceDeferredLinedUp(v19, in_pLowLevelHook);
  }
  v20 = v18;
  if ( v18 )
  {
    if ( ((unsigned int (__fastcall *)(AK::StreamMgr::CAkDeviceBase *, AkDeviceSettings *, _QWORD))v18->vfptr[1].__vecDelDtor)(
           v18,
           in_settings,
           (unsigned int)v5) == 1 )
    {
      AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[v5] = v20;
      return (unsigned int)v5;
    }
    v20->vfptr[1].PerformIO(v20);
  }
  return 0xFFFFFFFFi64;
}

// File Line: 541
// RVA: 0xAA2480
void __fastcall AK::StreamMgr::CAkStreamMgr::ForceCleanup(
        AK::StreamMgr::CAkDeviceBase *in_pCallingDevice,
        char in_priority)
{
  unsigned int m_uLength; // r9d
  __int64 i; // rbx
  AK::StreamMgr::CAkDeviceBase *v6; // rcx

  m_uLength = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
  for ( i = 0i64; (unsigned int)i < m_uLength; i = (unsigned int)(i + 1) )
  {
    v6 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[i];
    if ( v6 )
    {
      AK::StreamMgr::CAkDeviceBase::ForceCleanup(v6, in_pCallingDevice == v6, in_priority);
      m_uLength = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
    }
  }
}

// File Line: 565
// RVA: 0xAA21E0
__int64 __fastcall AK::StreamMgr::CAkStreamMgr::CreateStd(
        AK::StreamMgr::CAkStreamMgr *this,
        const wchar_t *in_pszFileName,
        AkFileSystemFlags *in_pFSFlags,
        AkOpenMode in_eOpenMode,
        AK::IAkStdStream **out_pStream,
        bool in_bSyncOpen)
{
  AkFileDesc *v10; // rbx
  AKRESULT v11; // edi
  unsigned int deviceID; // eax
  AK::StreamMgr::CAkDeviceBase *v13; // r14
  __int64 v14; // rax
  _BYTE *v15; // rdi
  AK::IAkStdStream *v16; // [rsp+30h] [rbp-28h] BYREF
  bool v17; // [rsp+68h] [rbp+10h] BYREF

  if ( !in_pszFileName )
    return 31i64;
  if ( in_pFSFlags )
    in_pFSFlags->bIsAutomaticStream = 0;
  v10 = (AkFileDesc *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0x28ui64);
  if ( !v10 )
    return 2i64;
  v17 = in_bSyncOpen;
  v11 = AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver->vfptr->Open(
          AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver,
          in_pszFileName,
          in_eOpenMode,
          in_pFSFlags,
          &v17,
          v10);
  if ( v11 != AK_Success )
  {
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v10);
    return (unsigned int)v11;
  }
  deviceID = v10->deviceID;
  if ( deviceID < AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
  {
    v13 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[deviceID];
    if ( v13 )
    {
      v16 = 0i64;
      v14 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkDeviceBase *, AkFileDesc *, _QWORD, AK::IAkStdStream **))v13->vfptr[1].ClearStreams)(
              v13,
              v10,
              (unsigned int)in_eOpenMode,
              &v16);
      v15 = (_BYTE *)v14;
      if ( v14 )
      {
        if ( v17 )
        {
          *(_BYTE *)(v14 + 117) |= 0x10u;
          *(_QWORD *)(v14 + 40) = v10;
        }
        else if ( AK::StreamMgr::CAkStmTask::SetDeferredFileOpen(
                    (AK::StreamMgr::CAkStmTask *)v14,
                    v10,
                    in_pszFileName,
                    in_pFSFlags,
                    in_eOpenMode) != AK_Success )
        {
          v15[117] = v15[117] & 0xB7 | 8;
          (*(void (__fastcall **)(_BYTE *))(*(_QWORD *)v15 + 16i64))(v15);
          return 2i64;
        }
        *out_pStream = v16;
        return 1i64;
      }
      if ( v17 )
        v13->m_pLowLevelHook->vfptr->Close(v13->m_pLowLevelHook, v10);
    }
  }
  AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v10);
  return 2i64;
}

// File Line: 665
// RVA: 0xAA2060
__int64 __fastcall AK::StreamMgr::CAkStreamMgr::CreateStd(
        AK::StreamMgr::CAkStreamMgr *this,
        unsigned int in_fileID,
        AkFileSystemFlags *in_pFSFlags,
        AkOpenMode in_eOpenMode,
        AK::IAkStdStream **out_pStream,
        bool in_bSyncOpen)
{
  AkFileDesc *v9; // rbx
  AKRESULT v11; // edi
  unsigned int deviceID; // eax
  AK::StreamMgr::CAkDeviceBase *v13; // rsi
  __int64 v14; // rax
  _BYTE *v15; // rdi
  AK::IAkStdStream *v16; // [rsp+30h] [rbp-28h] BYREF
  bool v17; // [rsp+70h] [rbp+18h] BYREF

  if ( in_pFSFlags )
    in_pFSFlags->bIsAutomaticStream = 0;
  v9 = (AkFileDesc *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0x28ui64);
  if ( !v9 )
    return 2i64;
  v17 = in_bSyncOpen;
  v11 = AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver->vfptr->Open(
          AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver,
          in_fileID,
          in_eOpenMode,
          in_pFSFlags,
          &v17,
          v9);
  if ( v11 != AK_Success )
  {
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v9);
    return (unsigned int)v11;
  }
  deviceID = v9->deviceID;
  if ( deviceID < AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
  {
    v13 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[deviceID];
    if ( v13 )
    {
      v16 = 0i64;
      v14 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkDeviceBase *, AkFileDesc *, _QWORD, AK::IAkStdStream **))v13->vfptr[1].ClearStreams)(
              v13,
              v9,
              (unsigned int)in_eOpenMode,
              &v16);
      v15 = (_BYTE *)v14;
      if ( v14 )
      {
        if ( v17 )
        {
          *(_BYTE *)(v14 + 117) |= 0x10u;
          *(_QWORD *)(v14 + 40) = v9;
        }
        else if ( AK::StreamMgr::CAkStmTask::SetDeferredFileOpen(
                    (AK::StreamMgr::CAkStmTask *)v14,
                    v9,
                    in_fileID,
                    in_pFSFlags,
                    in_eOpenMode) != AK_Success )
        {
          v15[117] = v15[117] & 0xB7 | 8;
          (*(void (__fastcall **)(_BYTE *))(*(_QWORD *)v15 + 16i64))(v15);
          return 2i64;
        }
        *out_pStream = v16;
        return 1i64;
      }
      if ( v17 )
        v13->m_pLowLevelHook->vfptr->Close(v13->m_pLowLevelHook, v9);
    }
  }
  AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v9);
  return 2i64;
}

// File Line: 764
// RVA: 0xAA1CC0
signed __int64 __fastcall AK::StreamMgr::CAkStreamMgr::CreateAuto(
        AK::StreamMgr::CAkStreamMgr *this,
        const wchar_t *in_pszFileName,
        AkFileSystemFlags *in_pFSFlags,
        AkAutoStmHeuristics *in_heuristics,
        AkAutoStmBufSettings *in_pBufferSettings,
        AK::IAkAutoStream **out_pStream,
        bool in_bSyncOpen)
{
  unsigned int uCacheID; // r15d
  AkFileDesc *v12; // rbx
  AKRESULT v13; // r14d
  unsigned int deviceID; // eax
  AK::StreamMgr::CAkDeviceBase *v15; // r14
  __int64 v16; // rax
  _BYTE *v17; // rdi
  AK::IAkAutoStream *v18; // [rsp+30h] [rbp-28h] BYREF
  bool v19; // [rsp+68h] [rbp+10h] BYREF

  if ( !in_pszFileName || in_heuristics->fThroughput < 0.0 || in_heuristics->priority > 0x64u )
    return 31i64;
  uCacheID = -1;
  if ( in_pFSFlags )
  {
    uCacheID = in_pFSFlags->uCacheID;
    in_pFSFlags->bIsAutomaticStream = 1;
  }
  v12 = (AkFileDesc *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0x28ui64);
  if ( !v12 )
    return 2i64;
  v19 = in_bSyncOpen;
  v13 = AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver->vfptr->Open(
          AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver,
          in_pszFileName,
          AK_OpenModeRead,
          in_pFSFlags,
          &v19,
          v12);
  if ( v13 != AK_Success )
  {
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v12);
    return (unsigned int)v13;
  }
  deviceID = v12->deviceID;
  if ( deviceID < AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
  {
    v15 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[deviceID];
    if ( v15 )
    {
      v18 = 0i64;
      v16 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkDeviceBase *, AkFileDesc *, _QWORD, AkAutoStmHeuristics *, AkAutoStmBufSettings *, AK::IAkAutoStream **))v15->vfptr[1].OnThreadStart)(
              v15,
              v12,
              uCacheID,
              in_heuristics,
              in_pBufferSettings,
              &v18);
      v17 = (_BYTE *)v16;
      if ( v16 )
      {
        if ( v19 )
        {
          *(_BYTE *)(v16 + 117) |= 0x10u;
          *(_QWORD *)(v16 + 40) = v12;
        }
        else if ( AK::StreamMgr::CAkStmTask::SetDeferredFileOpen(
                    (AK::StreamMgr::CAkStmTask *)v16,
                    v12,
                    in_pszFileName,
                    in_pFSFlags,
                    AK_OpenModeRead) != AK_Success )
        {
          v17[117] = v17[117] & 0xB7 | 8;
          (*(void (__fastcall **)(_BYTE *))(*(_QWORD *)v17 + 16i64))(v17);
          return 2i64;
        }
        *out_pStream = v18;
        return 1i64;
      }
      if ( v19 )
        v15->m_pLowLevelHook->vfptr->Close(v15->m_pLowLevelHook, v12);
    }
  }
  AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v12);
  return 2i64;
}

// File Line: 871
// RVA: 0xAA1AF0
__int64 __fastcall AK::StreamMgr::CAkStreamMgr::CreateAuto(
        AK::StreamMgr::CAkStreamMgr *this,
        unsigned int in_fileID,
        AkFileSystemFlags *in_pFSFlags,
        AkAutoStmHeuristics *in_heuristics,
        AkAutoStmBufSettings *in_pBufferSettings,
        AK::IAkAutoStream **out_pStream,
        bool in_bSyncOpen)
{
  unsigned int v10; // edi
  unsigned int uCacheID; // eax
  AkFileDesc *v12; // rbx
  AKRESULT v14; // r14d
  unsigned int deviceID; // eax
  AK::StreamMgr::CAkDeviceBase *v16; // r14
  __int64 v17; // rax
  _BYTE *v18; // rdi
  AK::IAkAutoStream *v19; // [rsp+30h] [rbp-28h] BYREF
  bool v20; // [rsp+78h] [rbp+20h] BYREF

  if ( in_heuristics->fThroughput < 0.0 || in_heuristics->priority > 0x64u )
    return 31i64;
  v10 = -1;
  if ( in_pFSFlags )
  {
    uCacheID = in_pFSFlags->uCacheID;
    in_pFSFlags->bIsAutomaticStream = 1;
    if ( uCacheID == -1 )
    {
      if ( !in_pFSFlags->uCompanyID )
        v10 = in_fileID;
    }
    else
    {
      v10 = uCacheID;
    }
  }
  v12 = (AkFileDesc *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0x28ui64);
  if ( !v12 )
    return 2i64;
  v20 = in_bSyncOpen;
  v14 = AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver->vfptr->Open(
          AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver,
          in_fileID,
          AK_OpenModeRead,
          in_pFSFlags,
          &v20,
          v12);
  if ( v14 != AK_Success )
  {
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v12);
    return (unsigned int)v14;
  }
  deviceID = v12->deviceID;
  if ( deviceID < AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
  {
    v16 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[deviceID];
    if ( v16 )
    {
      v19 = 0i64;
      v17 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkDeviceBase *, AkFileDesc *, _QWORD, AkAutoStmHeuristics *, AkAutoStmBufSettings *, AK::IAkAutoStream **))v16->vfptr[1].OnThreadStart)(
              v16,
              v12,
              v10,
              in_heuristics,
              in_pBufferSettings,
              &v19);
      v18 = (_BYTE *)v17;
      if ( v17 )
      {
        if ( v20 )
        {
          *(_BYTE *)(v17 + 117) |= 0x10u;
          *(_QWORD *)(v17 + 40) = v12;
        }
        else if ( AK::StreamMgr::CAkStmTask::SetDeferredFileOpen(
                    (AK::StreamMgr::CAkStmTask *)v17,
                    v12,
                    in_fileID,
                    in_pFSFlags,
                    AK_OpenModeRead) != AK_Success )
        {
          v18[117] = v18[117] & 0xB7 | 8;
          (*(void (__fastcall **)(_BYTE *))(*(_QWORD *)v18 + 16i64))(v18);
          return 2i64;
        }
        *out_pStream = v19;
        return 1i64;
      }
      if ( v20 )
        v16->m_pLowLevelHook->vfptr->Close(v16->m_pLowLevelHook, v12);
    }
  }
  AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v12);
  return 2i64;
}

