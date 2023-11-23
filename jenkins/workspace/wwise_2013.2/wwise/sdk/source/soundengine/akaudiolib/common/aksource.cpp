// File Line: 40
// RVA: 0xA779F0
void __fastcall CAkSource::CAkSource(CAkSource *this)
{
  this->m_sSrcTypeInfo.dwID = -1;
  this->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFF800;
  this->m_sSrcTypeInfo.mediaInfo.sourceID = 0;
  *(_QWORD *)&this->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  this->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
}

// File Line: 53
// RVA: 0xA77A20
void __fastcall CAkSource::~CAkSource(CAkSource *this)
{
  void *pInMemoryMedia; // rdx

  if ( (*((_BYTE *)&this->m_sSrcTypeInfo.mediaInfo + 16) & 0x7C) == 4 )
  {
    pInMemoryMedia = this->m_sSrcTypeInfo.pInMemoryMedia;
    if ( pInMemoryMedia )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, pInMemoryMedia);
      this->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
    }
  }
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFF800;
  this->m_sSrcTypeInfo.mediaInfo.sourceID = 0;
  this->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
  *(_QWORD *)&this->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) &= ~0x80u;
  this->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
}

// File Line: 66
// RVA: 0xA77C20
void __fastcall CAkSource::SetSource(
        CAkSource *this,
        unsigned int in_sourceID,
        unsigned int in_PluginID,
        const wchar_t *in_pszFilePath,
        unsigned int in_uCacheID,
        bool in_bIsFromRSX,
        bool in_bExternallySupplied)
{
  void *pInMemoryMedia; // rdx
  __int64 v12; // rdi
  unsigned __int64 v13; // rdi
  void *v14; // rax

  if ( (*((_BYTE *)&this->m_sSrcTypeInfo.mediaInfo + 16) & 0x7C) == 4 )
  {
    pInMemoryMedia = this->m_sSrcTypeInfo.pInMemoryMedia;
    if ( pInMemoryMedia )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, pInMemoryMedia);
      this->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
    }
  }
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFF800;
  this->m_sSrcTypeInfo.mediaInfo.sourceID = 0;
  this->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
  *(_QWORD *)&this->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) &= ~0x80u;
  this->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
  this->m_sSrcTypeInfo.dwID = in_PluginID;
  if ( in_pszFilePath )
  {
    v12 = -1i64;
    do
      ++v12;
    while ( in_pszFilePath[v12] );
    v13 = v12 + 1;
    v14 = AK::MemoryMgr::Malloc(g_DefaultPoolId, 2 * v13);
    this->m_sSrcTypeInfo.pInMemoryMedia = v14;
    if ( v14 )
      AKPLATFORM::SafeStrCpy((wchar_t *)v14, in_pszFilePath, v13);
  }
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFFC84;
  this->m_sSrcTypeInfo.mediaInfo.uFileID = in_uCacheID;
  this->m_sSrcTypeInfo.mediaInfo.sourceID = in_sourceID;
  *(_QWORD *)&this->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) |= ((in_bExternallySupplied | (2 * in_bIsFromRSX)) << 8) | 0x484;
}

// File Line: 92
// RVA: 0xA77DD0
void __fastcall CAkSource::SetSource(CAkSource *this, unsigned int in_PluginID, AkMediaInformation *in_MediaInfo)
{
  void *pInMemoryMedia; // rdx

  if ( (*((_BYTE *)&this->m_sSrcTypeInfo.mediaInfo + 16) & 0x7C) == 4 )
  {
    pInMemoryMedia = this->m_sSrcTypeInfo.pInMemoryMedia;
    if ( pInMemoryMedia )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, pInMemoryMedia);
      this->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
    }
  }
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFF800;
  this->m_sSrcTypeInfo.mediaInfo.sourceID = 0;
  *(_QWORD *)&this->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  this->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) &= ~0x80u;
  this->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
  this->m_sSrcTypeInfo.dwID = in_PluginID;
  this->m_sSrcTypeInfo.mediaInfo.sourceID = in_MediaInfo->sourceID;
  this->m_sSrcTypeInfo.mediaInfo.uFileID = in_MediaInfo->uFileID;
  this->m_sSrcTypeInfo.mediaInfo.uFileOffset = in_MediaInfo->uFileOffset;
  this->m_sSrcTypeInfo.mediaInfo.uInMemoryMediaSize = in_MediaInfo->uInMemoryMediaSize;
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) = *((_DWORD *)in_MediaInfo + 4);
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) |= 0x80u;
}

// File Line: 101
// RVA: 0xA77D20
void __fastcall CAkSource::SetSource(
        CAkSource *this,
        unsigned int in_PluginID,
        void *in_pInMemoryMedia,
        AkMediaInformation *in_MediaInfo)
{
  void *pInMemoryMedia; // rdx

  if ( (*((_BYTE *)&this->m_sSrcTypeInfo.mediaInfo + 16) & 0x7C) == 4 )
  {
    pInMemoryMedia = this->m_sSrcTypeInfo.pInMemoryMedia;
    if ( pInMemoryMedia )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, pInMemoryMedia);
      this->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
    }
  }
  this->m_sSrcTypeInfo.mediaInfo.sourceID = 0;
  this->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
  *(_QWORD *)&this->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFF800;
  this->m_sSrcTypeInfo.dwID = in_PluginID;
  this->m_sSrcTypeInfo.pInMemoryMedia = in_pInMemoryMedia;
  this->m_sSrcTypeInfo.mediaInfo.sourceID = in_MediaInfo->sourceID;
  this->m_sSrcTypeInfo.mediaInfo.uFileID = in_MediaInfo->uFileID;
  this->m_sSrcTypeInfo.mediaInfo.uFileOffset = in_MediaInfo->uFileOffset;
  this->m_sSrcTypeInfo.mediaInfo.uInMemoryMediaSize = in_MediaInfo->uInMemoryMediaSize;
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) = *((_DWORD *)in_MediaInfo + 4);
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) |= 0x80u;
}

// File Line: 113
// RVA: 0xA77B90
void __fastcall CAkSource::SetSource(CAkSource *this, unsigned int in_sourceID)
{
  void *pInMemoryMedia; // rdx
  int v5; // eax

  if ( (*((_BYTE *)&this->m_sSrcTypeInfo.mediaInfo + 16) & 0x7C) == 4 )
  {
    pInMemoryMedia = this->m_sSrcTypeInfo.pInMemoryMedia;
    if ( pInMemoryMedia )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, pInMemoryMedia);
      this->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
    }
  }
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFF800;
  this->m_sSrcTypeInfo.mediaInfo.sourceID = 0;
  *(_QWORD *)&this->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  this->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) &= ~0x80u;
  this->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
  this->m_sSrcTypeInfo.dwID = -1;
  v5 = *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4);
  *(_QWORD *)&this->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  this->m_sSrcTypeInfo.mediaInfo.sourceID = in_sourceID;
  this->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
  *((_DWORD *)&this->m_sSrcTypeInfo.mediaInfo + 4) = v5 & 0xFFFFF800 | 8;
}

// File Line: 145
// RVA: 0xA77B00
void __fastcall CAkSource::LockDataPtr(
        CAkSource *this,
        void **out_ppvBuffer,
        unsigned int *out_ulSize,
        CAkUsageSlot **out_rpSlot)
{
  AkMediaInfo result; // [rsp+20h] [rbp-18h] BYREF

  if ( this->m_sSrcTypeInfo.pInMemoryMedia )
  {
    *out_ulSize = this->m_sSrcTypeInfo.mediaInfo.uInMemoryMediaSize;
    *out_ppvBuffer = this->m_sSrcTypeInfo.pInMemoryMedia;
  }
  else
  {
    CAkBankMgr::GetMedia(g_pBankManager, &result, this->m_sSrcTypeInfo.mediaInfo.sourceID, out_rpSlot);
    *out_ulSize = result.uInMemoryDataSize;
    *out_ppvBuffer = result.pInMemoryData;
  }
}

// File Line: 161
// RVA: 0xA77E70
void __fastcall CAkSource::UnLockDataPtr(CAkSource *this)
{
  if ( !this->m_sSrcTypeInfo.pInMemoryMedia )
    CAkBankMgr::ReleaseMedia(g_pBankManager, this->m_sSrcTypeInfo.mediaInfo.sourceID);
}

// File Line: 167
// RVA: 0xA77B60
signed __int64 __fastcall CAkSource::PrepareData(CAkSource *this)
{
  if ( !this->m_sSrcTypeInfo.mediaInfo.uInMemoryMediaSize || this->m_sSrcTypeInfo.pInMemoryMedia )
    return 1i64;
  else
    return CAkBankMgr::PrepareSingleMedia(g_pBankManager, &this->m_sSrcTypeInfo);
}

// File Line: 179
// RVA: 0xA77E90
void __fastcall CAkSource::UnPrepareData(CAkSource *this)
{
  if ( this->m_sSrcTypeInfo.mediaInfo.uInMemoryMediaSize )
  {
    if ( !this->m_sSrcTypeInfo.pInMemoryMedia )
      CAkBankMgr::UnprepareSingleMedia(g_pBankManager, this->m_sSrcTypeInfo.mediaInfo.sourceID);
  }
}

// File Line: 187
// RVA: 0xA77A80
CAkSource *__fastcall CAkSource::Clone(CAkSource *this)
{
  CAkSource *result; // rax

  result = (CAkSource *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
  if ( result )
  {
    result->m_sSrcTypeInfo.dwID = -1;
    result->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
    *((_DWORD *)&result->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFF800;
    result->m_sSrcTypeInfo.mediaInfo.sourceID = 0;
    *(_QWORD *)&result->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
    result->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
    *(_QWORD *)&result->m_sSrcTypeInfo.mediaInfo.sourceID = *(_QWORD *)&this->m_sSrcTypeInfo.mediaInfo.sourceID;
    *(_QWORD *)&result->m_sSrcTypeInfo.mediaInfo.uFileOffset = *(_QWORD *)&this->m_sSrcTypeInfo.mediaInfo.uFileOffset;
    *((_QWORD *)&result->m_sSrcTypeInfo.mediaInfo + 2) = *((_QWORD *)&this->m_sSrcTypeInfo.mediaInfo + 2);
    result->m_sSrcTypeInfo.pInMemoryMedia = this->m_sSrcTypeInfo.pInMemoryMedia;
    *(_QWORD *)&result->m_sSrcTypeInfo.dwID = *(_QWORD *)&this->m_sSrcTypeInfo.dwID;
  }
  return result;
}

