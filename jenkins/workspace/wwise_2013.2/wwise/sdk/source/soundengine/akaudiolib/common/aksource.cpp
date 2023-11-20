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
  CAkSource *v1; // rbx
  void *v2; // rdx

  v1 = this;
  if ( (*((_BYTE *)&this->m_sSrcTypeInfo.mediaInfo + 16) & 0x7C) == 4 )
  {
    v2 = this->m_sSrcTypeInfo.pInMemoryMedia;
    if ( v2 )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, v2);
      v1->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
    }
  }
  *((_DWORD *)&v1->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFF800;
  v1->m_sSrcTypeInfo.mediaInfo.sourceID = 0;
  v1->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
  *(_QWORD *)&v1->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  *((_DWORD *)&v1->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFFF7F;
  v1->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
}

// File Line: 66
// RVA: 0xA77C20
void __fastcall CAkSource::SetSource(CAkSource *this, unsigned int in_sourceID, unsigned int in_PluginID, const wchar_t *in_pszFilePath, unsigned int in_uCacheID, bool in_bIsFromRSX, bool in_bExternallySupplied)
{
  const wchar_t *v7; // rsi
  unsigned int v8; // edi
  unsigned int v9; // ebp
  CAkSource *v10; // rbx
  void *v11; // rdx
  signed __int64 v12; // rdi
  unsigned __int64 v13; // rdi
  wchar_t *v14; // rax

  v7 = in_pszFilePath;
  v8 = in_PluginID;
  v9 = in_sourceID;
  v10 = this;
  if ( (*((_BYTE *)&this->m_sSrcTypeInfo.mediaInfo + 16) & 0x7C) == 4 )
  {
    v11 = this->m_sSrcTypeInfo.pInMemoryMedia;
    if ( v11 )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, v11);
      v10->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
    }
  }
  *((_DWORD *)&v10->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFF800;
  v10->m_sSrcTypeInfo.mediaInfo.sourceID = 0;
  v10->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
  *(_QWORD *)&v10->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  *((_DWORD *)&v10->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFFF7F;
  v10->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
  v10->m_sSrcTypeInfo.dwID = v8;
  if ( v7 )
  {
    v12 = -1i64;
    do
      ++v12;
    while ( v7[v12] );
    v13 = v12 + 1;
    v14 = (wchar_t *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 2 * v13);
    v10->m_sSrcTypeInfo.pInMemoryMedia = v14;
    if ( v14 )
      AKPLATFORM::SafeStrCpy(v14, v7, v13);
  }
  *((_DWORD *)&v10->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFFC84;
  v10->m_sSrcTypeInfo.mediaInfo.uFileID = in_uCacheID;
  v10->m_sSrcTypeInfo.mediaInfo.sourceID = v9;
  *(_QWORD *)&v10->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  *((_DWORD *)&v10->m_sSrcTypeInfo.mediaInfo + 4) |= ((in_bExternallySupplied | 2 * in_bIsFromRSX) << 8) | 0x484;
}

// File Line: 92
// RVA: 0xA77DD0
void __fastcall CAkSource::SetSource(CAkSource *this, unsigned int in_PluginID, AkMediaInformation *in_MediaInfo)
{
  AkMediaInformation *v3; // rdi
  unsigned int v4; // esi
  CAkSource *v5; // rbx
  void *v6; // rdx

  v3 = in_MediaInfo;
  v4 = in_PluginID;
  v5 = this;
  if ( (*((_BYTE *)&this->m_sSrcTypeInfo.mediaInfo + 16) & 0x7C) == 4 )
  {
    v6 = this->m_sSrcTypeInfo.pInMemoryMedia;
    if ( v6 )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, v6);
      v5->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
    }
  }
  *((_DWORD *)&v5->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFF800;
  v5->m_sSrcTypeInfo.mediaInfo.sourceID = 0;
  *(_QWORD *)&v5->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  v5->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
  *((_DWORD *)&v5->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFFF7F;
  v5->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
  v5->m_sSrcTypeInfo.dwID = v4;
  v5->m_sSrcTypeInfo.mediaInfo.sourceID = v3->sourceID;
  v5->m_sSrcTypeInfo.mediaInfo.uFileID = v3->uFileID;
  v5->m_sSrcTypeInfo.mediaInfo.uFileOffset = v3->uFileOffset;
  v5->m_sSrcTypeInfo.mediaInfo.uInMemoryMediaSize = v3->uInMemoryMediaSize;
  *((_DWORD *)&v5->m_sSrcTypeInfo.mediaInfo + 4) = *((_DWORD *)v3 + 4);
  *((_DWORD *)&v5->m_sSrcTypeInfo.mediaInfo + 4) |= 0x80u;
}

// File Line: 101
// RVA: 0xA77D20
void __fastcall CAkSource::SetSource(CAkSource *this, unsigned int in_PluginID, void *in_pInMemoryMedia, AkMediaInformation *in_MediaInfo)
{
  AkMediaInformation *v4; // rdi
  void *v5; // rsi
  unsigned int v6; // ebp
  CAkSource *v7; // rbx
  void *v8; // rdx

  v4 = in_MediaInfo;
  v5 = in_pInMemoryMedia;
  v6 = in_PluginID;
  v7 = this;
  if ( (*((_BYTE *)&this->m_sSrcTypeInfo.mediaInfo + 16) & 0x7C) == 4 )
  {
    v8 = this->m_sSrcTypeInfo.pInMemoryMedia;
    if ( v8 )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, v8);
      v7->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
    }
  }
  v7->m_sSrcTypeInfo.mediaInfo.sourceID = 0;
  v7->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
  *(_QWORD *)&v7->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  *((_DWORD *)&v7->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFF800;
  v7->m_sSrcTypeInfo.dwID = v6;
  v7->m_sSrcTypeInfo.pInMemoryMedia = v5;
  v7->m_sSrcTypeInfo.mediaInfo.sourceID = v4->sourceID;
  v7->m_sSrcTypeInfo.mediaInfo.uFileID = v4->uFileID;
  v7->m_sSrcTypeInfo.mediaInfo.uFileOffset = v4->uFileOffset;
  v7->m_sSrcTypeInfo.mediaInfo.uInMemoryMediaSize = v4->uInMemoryMediaSize;
  *((_DWORD *)&v7->m_sSrcTypeInfo.mediaInfo + 4) = *((_DWORD *)v4 + 4);
  *((_DWORD *)&v7->m_sSrcTypeInfo.mediaInfo + 4) |= 0x80u;
}

// File Line: 113
// RVA: 0xA77B90
void __fastcall CAkSource::SetSource(CAkSource *this, unsigned int in_sourceID)
{
  unsigned int v2; // edi
  CAkSource *v3; // rbx
  void *v4; // rdx
  int v5; // eax

  v2 = in_sourceID;
  v3 = this;
  if ( (*((_BYTE *)&this->m_sSrcTypeInfo.mediaInfo + 16) & 0x7C) == 4 )
  {
    v4 = this->m_sSrcTypeInfo.pInMemoryMedia;
    if ( v4 )
    {
      AK::MemoryMgr::Free(g_DefaultPoolId, v4);
      v3->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
    }
  }
  *((_DWORD *)&v3->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFF800;
  v3->m_sSrcTypeInfo.mediaInfo.sourceID = 0;
  *(_QWORD *)&v3->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  v3->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
  *((_DWORD *)&v3->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFFF7F;
  v3->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
  v3->m_sSrcTypeInfo.dwID = -1;
  v5 = *((_DWORD *)&v3->m_sSrcTypeInfo.mediaInfo + 4);
  *(_QWORD *)&v3->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
  v3->m_sSrcTypeInfo.mediaInfo.sourceID = v2;
  v3->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
  *((_DWORD *)&v3->m_sSrcTypeInfo.mediaInfo + 4) = v5 & 0xFFFFF808 | 8;
}

// File Line: 145
// RVA: 0xA77B00
void __fastcall CAkSource::LockDataPtr(CAkSource *this, void **out_ppvBuffer, unsigned int *out_ulSize, CAkUsageSlot **out_rpSlot)
{
  unsigned int *v4; // rbx
  void **v5; // rdi
  AkMediaInfo result; // [rsp+20h] [rbp-18h]

  v4 = out_ulSize;
  v5 = out_ppvBuffer;
  if ( this->m_sSrcTypeInfo.pInMemoryMedia )
  {
    *out_ulSize = this->m_sSrcTypeInfo.mediaInfo.uInMemoryMediaSize;
    *out_ppvBuffer = this->m_sSrcTypeInfo.pInMemoryMedia;
  }
  else
  {
    CAkBankMgr::GetMedia(g_pBankManager, &result, this->m_sSrcTypeInfo.mediaInfo.sourceID, out_rpSlot);
    *v4 = result.uInMemoryDataSize;
    *v5 = result.pInMemoryData;
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
  signed __int64 result; // rax

  if ( !this->m_sSrcTypeInfo.mediaInfo.uInMemoryMediaSize || this->m_sSrcTypeInfo.pInMemoryMedia )
    result = 1i64;
  else
    result = CAkBankMgr::PrepareSingleMedia(g_pBankManager, &this->m_sSrcTypeInfo);
  return result;
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
  CAkSource *v1; // rbx
  CAkSource *result; // rax

  v1 = this;
  result = (CAkSource *)AK::MemoryMgr::Malloc(g_DefaultPoolId, 0x28ui64);
  if ( result )
  {
    result->m_sSrcTypeInfo.dwID = -1;
    result->m_sSrcTypeInfo.pInMemoryMedia = 0i64;
    *((_DWORD *)&result->m_sSrcTypeInfo.mediaInfo + 4) &= 0xFFFFF800;
    result->m_sSrcTypeInfo.mediaInfo.sourceID = 0;
    *(_QWORD *)&result->m_sSrcTypeInfo.mediaInfo.uFileOffset = 0i64;
    result->m_sSrcTypeInfo.mediaInfo.uFileID = -1;
    *(_QWORD *)&result->m_sSrcTypeInfo.mediaInfo.sourceID = *(_QWORD *)&v1->m_sSrcTypeInfo.mediaInfo.sourceID;
    *(_QWORD *)&result->m_sSrcTypeInfo.mediaInfo.uFileOffset = *(_QWORD *)&v1->m_sSrcTypeInfo.mediaInfo.uFileOffset;
    *((_QWORD *)&result->m_sSrcTypeInfo.mediaInfo + 2) = *((_QWORD *)&v1->m_sSrcTypeInfo.mediaInfo + 2);
    result->m_sSrcTypeInfo.pInMemoryMedia = v1->m_sSrcTypeInfo.pInMemoryMedia;
    *(_QWORD *)&result->m_sSrcTypeInfo.dwID = *(_QWORD *)&v1->m_sSrcTypeInfo.dwID;
  }
  return result;
}

