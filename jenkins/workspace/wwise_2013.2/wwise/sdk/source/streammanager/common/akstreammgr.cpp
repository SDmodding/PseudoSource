// File Line: 36
// RVA: 0x15BE0E0
__int64 dynamic_initializer_for__AK::StreamMgr::CAkStreamMgr::m_arDevices__()
{
  return atexit(dynamic_atexit_destructor_for__AK::StreamMgr::CAkStreamMgr::m_arDevices__);
}

// File Line: 41
// RVA: 0x15BE0F0
__int64 dynamic_initializer_for__AK::StreamMgr::CAkStreamMgr::m_arLangChgObserver__()
{
  return atexit(dynamic_atexit_destructor_for__AK::StreamMgr::CAkStreamMgr::m_arLangChgObserver__);
}

// File Line: 62
// RVA: 0xAA1A50
AK::IAkStreamMgr *__fastcall AK::StreamMgr::Create(AkStreamMgrSettings *in_settings)
{
  AkStreamMgrSettings *v1; // rbx
  AK::IAkStreamMgr *result; // rax
  int v3; // eax

  v1 = in_settings;
  if ( !(unsigned __int8)AK::MemoryMgr::IsInitialized() )
    return 0i64;
  result = AK::IAkStreamMgr::m_pStreamMgr;
  if ( !AK::IAkStreamMgr::m_pStreamMgr )
  {
    v3 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
    m_szCurrentLanguage[0] = 0;
    if ( AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId == -1 )
    {
      v3 = AK::MemoryMgr::CreatePool(0i64, v1->uMemorySize, 0x20u, 1u, 0);
      AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId = v3;
      if ( v3 == -1 )
        return 0i64;
    }
    result = (AK::IAkStreamMgr *)AK::MemoryMgr::Malloc(v3, 8ui64);
    if ( result )
    {
      result->vfptr = (AK::IAkStreamMgrVtbl *)&AK::StreamMgr::CAkStreamMgr::`vftable';
      AK::IAkStreamMgr::m_pStreamMgr = result;
    }
    else
    {
      AK::MemoryMgr::DestroyPool(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId);
      result = AK::IAkStreamMgr::m_pStreamMgr;
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
  out_settings->ePoolAttributes = 2;
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
void __fastcall AK::StreamMgr::SetFileLocationResolver(AK::StreamMgr::IAkFileLocationResolver *in_pFileLocationResolver)
{
  AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver = in_pFileLocationResolver;
}

// File Line: 175
// RVA: 0xAA2040
signed __int64 __fastcall AK::StreamMgr::CreateDevice(AkDeviceSettings *in_settings, AK::StreamMgr::IAkLowLevelIOHook *in_pLowLevelHook)
{
  return AK::StreamMgr::CAkStreamMgr::CreateDevice(
           (AK::StreamMgr::CAkStreamMgr *)AK::IAkStreamMgr::m_pStreamMgr,
           in_settings,
           in_pLowLevelHook);
}

// File Line: 181
// RVA: 0xAA2420
signed __int64 __fastcall AK::StreamMgr::DestroyDevice(unsigned int in_deviceID)
{
  __int64 v1; // rbx
  AK::StreamMgr::CAkDeviceBase *v2; // rcx

  if ( in_deviceID >= AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
    return 31i64;
  v1 = in_deviceID;
  v2 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[v1];
  if ( !v2 )
    return 31i64;
  ((void (*)(void))v2->vfptr[1].PerformIO)();
  AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[v1] = 0i64;
  return 1i64;
}

// File Line: 234
// RVA: 0xAA19C0
AK::StreamMgr::AkDeferredOpenData *__fastcall AK::StreamMgr::AkDeferredOpenData::Create(const wchar_t *in_pszFileName, AkFileSystemFlags *in_pFSFlags, AkOpenMode in_eOpenMode)
{
  const wchar_t *v3; // rbp
  AkFileSystemFlags *v4; // rsi
  AkOpenMode v5; // edi
  AK::StreamMgr::AkDeferredOpenData *result; // rax
  AK::StreamMgr::AkDeferredOpenData *v7; // rbx

  v3 = in_pszFileName;
  v4 = in_pFSFlags;
  v5 = in_eOpenMode;
  result = (AK::StreamMgr::AkDeferredOpenData *)AK::MemoryMgr::Malloc(
                                                  AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                                  0x30ui64);
  v7 = result;
  if ( result )
  {
    if ( AK::StreamMgr::AkDeferredOpenData::Init(result, v3, v4, v5) == 1 )
    {
      result = v7;
    }
    else
    {
      if ( *((_BYTE *)v7 + 44) & 1 )
      {
        if ( v7->pszFileName )
          AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v7->pszFileName);
      }
      AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v7);
      result = 0i64;
    }
  }
  return result;
}

// File Line: 253
// RVA: 0xAA1930
AK::StreamMgr::AkDeferredOpenData *__fastcall AK::StreamMgr::AkDeferredOpenData::Create(unsigned int in_fileID, AkFileSystemFlags *in_pFSFlags, AkOpenMode in_eOpenMode)
{
  unsigned int v3; // esi
  AkFileSystemFlags *v4; // rbx
  AkOpenMode v5; // edi
  AK::StreamMgr::AkDeferredOpenData *result; // rax
  AK::StreamMgr::AkDeferredOpenData *v7; // r9
  int v8; // eax

  v3 = in_fileID;
  v4 = in_pFSFlags;
  v5 = in_eOpenMode;
  result = (AK::StreamMgr::AkDeferredOpenData *)AK::MemoryMgr::Malloc(
                                                  AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                                  0x30ui64);
  v7 = result;
  if ( result )
  {
    *((_DWORD *)result + 11) &= 0xFFFFFFFE;
    v8 = *((_DWORD *)result + 11);
    if ( v4 )
    {
      *((_DWORD *)v7 + 11) = v8 | 2;
      *(_QWORD *)&v7->flags.uCompanyID = *(_QWORD *)&v4->uCompanyID;
      *(_QWORD *)&v7->flags.uCustomParamSize = *(_QWORD *)&v4->uCustomParamSize;
      v7->flags.pCustomParam = v4->pCustomParam;
      *(_QWORD *)&v7->flags.bIsLanguageSpecific = *(_QWORD *)&v4->bIsLanguageSpecific;
    }
    else
    {
      *((_DWORD *)v7 + 11) = v8 & 0xFFFFFFFD;
    }
    v7->fileID = v3;
    v7->eOpenMode = v5;
    result = v7;
  }
  return result;
}

// File Line: 261
// RVA: 0xAA2370
void __fastcall AK::StreamMgr::AkDeferredOpenData::Destroy(AK::StreamMgr::AkDeferredOpenData *this)
{
  AK::StreamMgr::AkDeferredOpenData *v1; // rbx

  v1 = this;
  if ( *((_BYTE *)this + 44) & 1 && this->pszFileName )
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, this->pszFileName);
  AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v1);
}

// File Line: 318
// RVA: 0xAA2560
signed __int64 __fastcall AK::StreamMgr::AkDeferredOpenData::Init(AK::StreamMgr::AkDeferredOpenData *this, const wchar_t *in_pszFileName, AkFileSystemFlags *in_pFSFlags, AkOpenMode in_eOpenMode)
{
  int v4; // eax
  const wchar_t *v5; // rsi
  AK::StreamMgr::AkDeferredOpenData *v6; // rbx
  signed __int64 v7; // rdi
  unsigned __int64 v8; // rdi
  unsigned __int16 *v9; // r14
  unsigned __int64 v11; // rbx
  signed __int64 v12; // rax
  signed __int64 v13; // rbx

  *((_DWORD *)this + 11) |= 1u;
  v4 = *((_DWORD *)this + 11);
  v5 = in_pszFileName;
  v6 = this;
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
  v9 = (unsigned __int16 *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 2 * v8);
  v6->pszFileName = v9;
  if ( !v9 )
    return 2i64;
  v11 = v8 - 1;
  v12 = -1i64;
  do
    ++v12;
  while ( v5[v12] );
  if ( v11 >= v12 + 1 )
  {
    v13 = -1i64;
    do
      ++v13;
    while ( v5[v13] );
    v11 = v13 + 1;
  }
  wcsncpy_s(v9, v8, v5, v11);
  v9[v11] = 0;
  return 1i64;
}

// File Line: 379
// RVA: 0xAA23B0
void __fastcall AK::StreamMgr::CAkStreamMgr::Destroy(AK::StreamMgr::CAkStreamMgr *this)
{
  AK::StreamMgr::CAkStreamMgr *v1; // rdi
  bool v2; // al
  int v3; // ebx

  v1 = this;
  AK::StreamMgr::CAkStreamMgr::Term(this);
  v2 = AK::MemoryMgr::IsInitialized();
  v3 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
  if ( v2 && AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId != -1 && v1 )
  {
    v1->vfptr->__vecDelDtor((AK::IAkStreamMgr *)&v1->vfptr, 0);
    AK::MemoryMgr::Free(v3, v1);
    v3 = AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId;
  }
  AK::MemoryMgr::DestroyPool(v3);
  AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId = -1;
}

// File Line: 419
// RVA: 0xAA2660
void __fastcall AK::StreamMgr::CAkStreamMgr::Term(AK::StreamMgr::CAkStreamMgr *this)
{
  AK::StreamMgr::CAkDeviceBase **v1; // rdx
  unsigned int v2; // er8
  AK::StreamMgr::CAkDeviceBase **v3; // rbx

  v1 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems;
  v2 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
  AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver = 0i64;
  v3 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems;
  if ( AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems != &AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength] )
  {
    do
    {
      if ( *v3 )
      {
        ((void (*)(void))(*v3)->vfptr[1].PerformIO)();
        v2 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
        v1 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems;
      }
      ++v3;
    }
    while ( v3 != &v1[v2] );
  }
  if ( v1 )
  {
    AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength = 0;
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v1);
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
signed __int64 __fastcall AK::StreamMgr::CAkStreamMgr::CreateDevice(AK::StreamMgr::CAkStreamMgr *this, AkDeviceSettings *in_settings, AK::StreamMgr::IAkLowLevelIOHook *in_pLowLevelHook)
{
  unsigned int v3; // ecx
  AK::StreamMgr::CAkDeviceBase **v4; // rdi
  __int64 v5; // rbx
  AK::StreamMgr::IAkLowLevelIOHook *v6; // r14
  AkDeviceSettings *v7; // rbp
  AK::StreamMgr::CAkDeviceBase **v8; // rax
  unsigned int v9; // ebx
  unsigned __int64 v10; // rsi
  AK::StreamMgr::CAkDeviceBase **v11; // rdx
  unsigned __int64 v12; // r8
  unsigned __int64 v13; // rcx
  AK::StreamMgr::CAkDeviceBase *v14; // rax
  AK::StreamMgr::CAkDeviceBase **v15; // rdx
  unsigned int v16; // eax
  AK::StreamMgr::CAkDeviceBlocking *v17; // rax
  AK::StreamMgr::CAkDeviceBase *v18; // rax
  AK::StreamMgr::CAkDeviceDeferredLinedUp *v19; // rax
  AK::StreamMgr::CAkDeviceBase *v20; // rdi

  v3 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
  v4 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems;
  v5 = 0i64;
  v6 = in_pLowLevelHook;
  v7 = in_settings;
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
    v9 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_ulReserved;
    v10 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
    if ( AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength >= (unsigned __int64)AK::StreamMgr::CAkStreamMgr::m_arDevices.m_ulReserved )
    {
      v9 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_ulReserved + 1;
      v4 = (AK::StreamMgr::CAkDeviceBase **)AK::MemoryMgr::Malloc(
                                              AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                              8i64 * (AK::StreamMgr::CAkStreamMgr::m_arDevices.m_ulReserved + 1));
      if ( !v4 )
        return 0xFFFFFFFFi64;
      v11 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems;
      v3 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
      v12 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
      if ( AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems )
      {
        v13 = 0i64;
        if ( AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
        {
          do
          {
            v14 = v11[v13++];
            v4[v13 - 1] = v14;
            v11 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems;
          }
          while ( v13 < v12 );
        }
        AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v11);
        v3 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
      }
      AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems = v4;
      AK::StreamMgr::CAkStreamMgr::m_arDevices.m_ulReserved = v9;
    }
    if ( v10 >= v9 )
      return 0xFFFFFFFFi64;
    v15 = &v4[v3];
    AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength = v3 + 1;
    if ( !v15 )
      return 0xFFFFFFFFi64;
    *v15 = 0i64;
    v5 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength - 1;
    AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength - 1] = 0i64;
  }
  v16 = v7->uSchedulerTypeFlags;
  if ( v16 & 1 )
  {
    v17 = (AK::StreamMgr::CAkDeviceBlocking *)AK::MemoryMgr::Malloc(
                                                AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                                0x138ui64);
    if ( !v17 )
      return 0xFFFFFFFFi64;
    AK::StreamMgr::CAkDeviceBlocking::CAkDeviceBlocking(v17, v6);
  }
  else
  {
    if ( !(v16 & 2) )
      return 0xFFFFFFFFi64;
    v19 = (AK::StreamMgr::CAkDeviceDeferredLinedUp *)AK::MemoryMgr::Malloc(
                                                       AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId,
                                                       0x130ui64);
    if ( !v19 )
      return 0xFFFFFFFFi64;
    AK::StreamMgr::CAkDeviceDeferredLinedUp::CAkDeviceDeferredLinedUp(v19, v6);
  }
  v20 = v18;
  if ( v18 )
  {
    if ( ((unsigned int (__fastcall *)(AK::StreamMgr::CAkDeviceBase *, AkDeviceSettings *, _QWORD))v18->vfptr[1].__vecDelDtor)(
           v18,
           v7,
           (unsigned int)v5) == 1 )
    {
      AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[v5] = v20;
      return (unsigned int)v5;
    }
    v20->vfptr[1].PerformIO((AK::StreamMgr::CAkIOThread *)&v20->vfptr);
  }
  return 0xFFFFFFFFi64;
}

// File Line: 541
// RVA: 0xAA2480
void __fastcall AK::StreamMgr::CAkStreamMgr::ForceCleanup(AK::StreamMgr::CAkDeviceBase *in_pCallingDevice, char in_priority)
{
  unsigned int v2; // er9
  __int64 v3; // rbx
  char v4; // di
  AK::StreamMgr::CAkDeviceBase *v5; // rsi
  AK::StreamMgr::CAkDeviceBase *v6; // rcx

  v2 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
  v3 = 0i64;
  v4 = in_priority;
  v5 = in_pCallingDevice;
  if ( AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
  {
    do
    {
      v6 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[v3];
      if ( v6 )
      {
        AK::StreamMgr::CAkDeviceBase::ForceCleanup(v6, v5 == v6, v4);
        v2 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength;
      }
      v3 = (unsigned int)(v3 + 1);
    }
    while ( (unsigned int)v3 < v2 );
  }
}

// File Line: 565
// RVA: 0xAA21E0
signed __int64 __fastcall AK::StreamMgr::CAkStreamMgr::CreateStd(AK::StreamMgr::CAkStreamMgr *this, const wchar_t *in_pszFileName, AkFileSystemFlags *in_pFSFlags, AkOpenMode in_eOpenMode, AK::IAkStdStream **out_pStream, bool in_bSyncOpen)
{
  AkOpenMode v6; // er15
  AkFileSystemFlags *v7; // rsi
  const wchar_t *v8; // rbp
  AkFileDesc *v10; // rbx
  AKRESULT v11; // edi
  unsigned int v12; // eax
  AK::StreamMgr::CAkDeviceBase *v13; // r14
  __int64 v14; // rax
  _BYTE *v15; // rdi
  AK::IAkStdStream *v16; // [rsp+30h] [rbp-28h]
  bool v17; // [rsp+68h] [rbp+10h]

  v6 = in_eOpenMode;
  v7 = in_pFSFlags;
  v8 = in_pszFileName;
  if ( !in_pszFileName )
    return 31i64;
  if ( in_pFSFlags )
    in_pFSFlags->bIsAutomaticStream = 0;
  v10 = (AkFileDesc *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0x28ui64);
  if ( !v10 )
    return 2i64;
  v17 = in_bSyncOpen;
  v11 = (unsigned int)AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver->vfptr->Open(
                        AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver,
                        v8,
                        v6,
                        v7,
                        &v17,
                        v10);
  if ( v11 != 1 )
  {
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v10);
    return (unsigned int)v11;
  }
  v12 = v10->deviceID;
  if ( v12 >= AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
    goto LABEL_14;
  v13 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[v12];
  if ( !v13 )
    goto LABEL_14;
  v16 = 0i64;
  v14 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkDeviceBase *, AkFileDesc *, _QWORD, AK::IAkStdStream **))v13->vfptr[1].ClearStreams)(
          v13,
          v10,
          (unsigned int)v6,
          &v16);
  v15 = (_BYTE *)v14;
  if ( !v14 )
  {
    if ( v17 )
      v13->m_pLowLevelHook->vfptr->Close(v13->m_pLowLevelHook, v10);
LABEL_14:
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v10);
    return 2i64;
  }
  if ( v17 )
  {
    *(_BYTE *)(v14 + 117) |= 0x10u;
    *(_QWORD *)(v14 + 40) = v10;
  }
  else if ( AK::StreamMgr::CAkStmTask::SetDeferredFileOpen((AK::StreamMgr::CAkStmTask *)v14, v10, v8, v7, v6) != 1 )
  {
    v15[117] = v15[117] & 0xBF | 8;
    (*(void (__fastcall **)(_BYTE *))(*(_QWORD *)v15 + 16i64))(v15);
    return 2i64;
  }
  *out_pStream = v16;
  return 1i64;
}

// File Line: 665
// RVA: 0xAA2060
signed __int64 __fastcall AK::StreamMgr::CAkStreamMgr::CreateStd(AK::StreamMgr::CAkStreamMgr *this, unsigned int in_fileID, AkFileSystemFlags *in_pFSFlags, AkOpenMode in_eOpenMode, AK::IAkStdStream **out_pStream, bool in_bSyncOpen)
{
  AkOpenMode v6; // er14
  AkFileSystemFlags *v7; // rbp
  unsigned int v8; // er15
  AkFileDesc *v9; // rbx
  AKRESULT v11; // edi
  unsigned int v12; // eax
  AK::StreamMgr::CAkDeviceBase *v13; // rsi
  __int64 v14; // rax
  _BYTE *v15; // rdi
  AK::IAkStdStream *v16; // [rsp+30h] [rbp-28h]
  bool v17; // [rsp+70h] [rbp+18h]

  v6 = in_eOpenMode;
  v7 = in_pFSFlags;
  v8 = in_fileID;
  if ( in_pFSFlags )
    in_pFSFlags->bIsAutomaticStream = 0;
  v9 = (AkFileDesc *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0x28ui64);
  if ( !v9 )
    return 2i64;
  v17 = in_bSyncOpen;
  v11 = (unsigned int)AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver->vfptr->Open(
                        AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver,
                        v8,
                        v6,
                        v7,
                        &v17,
                        v9);
  if ( v11 != 1 )
  {
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v9);
    return (unsigned int)v11;
  }
  v12 = v9->deviceID;
  if ( v12 >= AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
    goto LABEL_12;
  v13 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[v12];
  if ( !v13 )
    goto LABEL_12;
  v16 = 0i64;
  v14 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkDeviceBase *, AkFileDesc *, _QWORD, AK::IAkStdStream **))v13->vfptr[1].ClearStreams)(
          v13,
          v9,
          (unsigned int)v6,
          &v16);
  v15 = (_BYTE *)v14;
  if ( !v14 )
  {
    if ( v17 )
      v13->m_pLowLevelHook->vfptr->Close(v13->m_pLowLevelHook, v9);
LABEL_12:
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v9);
    return 2i64;
  }
  if ( v17 )
  {
    *(_BYTE *)(v14 + 117) |= 0x10u;
    *(_QWORD *)(v14 + 40) = v9;
  }
  else if ( AK::StreamMgr::CAkStmTask::SetDeferredFileOpen((AK::StreamMgr::CAkStmTask *)v14, v9, v8, v7, v6) != 1 )
  {
    v15[117] = v15[117] & 0xBF | 8;
    (*(void (__fastcall **)(_BYTE *))(*(_QWORD *)v15 + 16i64))(v15);
    return 2i64;
  }
  *out_pStream = v16;
  return 1i64;
}

// File Line: 764
// RVA: 0xAA1CC0
signed __int64 __fastcall AK::StreamMgr::CAkStreamMgr::CreateAuto(AK::StreamMgr::CAkStreamMgr *this, const wchar_t *in_pszFileName, AkFileSystemFlags *in_pFSFlags, AkAutoStmHeuristics *in_heuristics, AkAutoStmBufSettings *in_pBufferSettings, AK::IAkAutoStream **out_pStream, bool in_bSyncOpen)
{
  AkAutoStmHeuristics *v7; // rdi
  AkFileSystemFlags *v8; // rsi
  const wchar_t *v9; // rbp
  unsigned int v11; // er15
  AkFileDesc *v12; // rbx
  AKRESULT v13; // er14
  unsigned int v14; // eax
  AK::StreamMgr::CAkDeviceBase *v15; // r14
  __int64 v16; // rax
  _BYTE *v17; // rdi
  AK::IAkAutoStream *v18; // [rsp+30h] [rbp-28h]
  bool v19; // [rsp+68h] [rbp+10h]

  v7 = in_heuristics;
  v8 = in_pFSFlags;
  v9 = in_pszFileName;
  if ( !in_pszFileName || in_heuristics->fThroughput < 0.0 || in_heuristics->priority > 0x64u )
    return 31i64;
  v11 = -1;
  if ( in_pFSFlags )
  {
    v11 = in_pFSFlags->uCacheID;
    in_pFSFlags->bIsAutomaticStream = 1;
  }
  v12 = (AkFileDesc *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0x28ui64);
  if ( !v12 )
    return 2i64;
  v19 = in_bSyncOpen;
  v13 = (unsigned int)AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver->vfptr->Open(
                        AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver,
                        v9,
                        0i64,
                        v8,
                        &v19,
                        v12);
  if ( v13 != 1 )
  {
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v12);
    return (unsigned int)v13;
  }
  v14 = v12->deviceID;
  if ( v14 >= AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
    goto LABEL_16;
  v15 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[v14];
  if ( !v15 )
    goto LABEL_16;
  v18 = 0i64;
  v16 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkDeviceBase *, AkFileDesc *, _QWORD, AkAutoStmHeuristics *, AkAutoStmBufSettings *, AK::IAkAutoStream **))v15->vfptr[1].OnThreadStart)(
          v15,
          v12,
          v11,
          v7,
          in_pBufferSettings,
          &v18);
  v17 = (_BYTE *)v16;
  if ( !v16 )
  {
    if ( v19 )
      v15->m_pLowLevelHook->vfptr->Close(v15->m_pLowLevelHook, v12);
LABEL_16:
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v12);
    return 2i64;
  }
  if ( v19 )
  {
    *(_BYTE *)(v16 + 117) |= 0x10u;
    *(_QWORD *)(v16 + 40) = v12;
  }
  else if ( AK::StreamMgr::CAkStmTask::SetDeferredFileOpen((AK::StreamMgr::CAkStmTask *)v16, v12, v9, v8, 0) != 1 )
  {
    v17[117] = v17[117] & 0xBF | 8;
    (*(void (__fastcall **)(_BYTE *))(*(_QWORD *)v17 + 16i64))(v17);
    return 2i64;
  }
  *out_pStream = v18;
  return 1i64;
}

// File Line: 871
// RVA: 0xAA1AF0
signed __int64 __fastcall AK::StreamMgr::CAkStreamMgr::CreateAuto(AK::StreamMgr::CAkStreamMgr *this, unsigned int in_fileID, AkFileSystemFlags *in_pFSFlags, AkAutoStmHeuristics *in_heuristics, AkAutoStmBufSettings *in_pBufferSettings, AK::IAkAutoStream **out_pStream, bool in_bSyncOpen)
{
  AkAutoStmHeuristics *v7; // rbp
  AkFileSystemFlags *v8; // rsi
  unsigned int v9; // er15
  unsigned int v10; // edi
  unsigned int v11; // eax
  AkFileDesc *v12; // rbx
  AKRESULT v14; // er14
  unsigned int v15; // eax
  AK::StreamMgr::CAkDeviceBase *v16; // r14
  __int64 v17; // rax
  _BYTE *v18; // rdi
  AK::IAkAutoStream *v19; // [rsp+30h] [rbp-28h]
  bool v20; // [rsp+78h] [rbp+20h]

  v7 = in_heuristics;
  v8 = in_pFSFlags;
  v9 = in_fileID;
  if ( in_heuristics->fThroughput < 0.0 || in_heuristics->priority > 0x64u )
    return 31i64;
  v10 = -1;
  if ( in_pFSFlags )
  {
    v11 = in_pFSFlags->uCacheID;
    in_pFSFlags->bIsAutomaticStream = 1;
    if ( v11 == -1 )
    {
      if ( !in_pFSFlags->uCompanyID )
        v10 = in_fileID;
    }
    else
    {
      v10 = v11;
    }
  }
  v12 = (AkFileDesc *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0x28ui64);
  if ( !v12 )
    return 2i64;
  v20 = in_bSyncOpen;
  v14 = (unsigned int)AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver->vfptr->Open(
                        AK::StreamMgr::CAkStreamMgr::m_pFileLocationResolver,
                        v9,
                        0i64,
                        v8,
                        &v20,
                        v12);
  if ( v14 != 1 )
  {
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v12);
    return (unsigned int)v14;
  }
  v15 = v12->deviceID;
  if ( v15 >= AK::StreamMgr::CAkStreamMgr::m_arDevices.m_uLength )
    goto LABEL_17;
  v16 = AK::StreamMgr::CAkStreamMgr::m_arDevices.m_pItems[v15];
  if ( !v16 )
    goto LABEL_17;
  v19 = 0i64;
  v17 = ((__int64 (__fastcall *)(AK::StreamMgr::CAkDeviceBase *, AkFileDesc *, _QWORD, AkAutoStmHeuristics *, AkAutoStmBufSettings *, AK::IAkAutoStream **))v16->vfptr[1].OnThreadStart)(
          v16,
          v12,
          v10,
          v7,
          in_pBufferSettings,
          &v19);
  v18 = (_BYTE *)v17;
  if ( !v17 )
  {
    if ( v20 )
      v16->m_pLowLevelHook->vfptr->Close(v16->m_pLowLevelHook, v12);
LABEL_17:
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v12);
    return 2i64;
  }
  if ( v20 )
  {
    *(_BYTE *)(v17 + 117) |= 0x10u;
    *(_QWORD *)(v17 + 40) = v12;
  }
  else if ( AK::StreamMgr::CAkStmTask::SetDeferredFileOpen((AK::StreamMgr::CAkStmTask *)v17, v12, v9, v8, 0) != 1 )
  {
    v18[117] = v18[117] & 0xBF | 8;
    (*(void (__fastcall **)(_BYTE *))(*(_QWORD *)v18 + 16i64))(v18);
    return 2i64;
  }
  *out_pStream = v19;
  return 1i64;
}

