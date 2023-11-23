// File Line: 21
// RVA: 0x140CE0
void __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::~WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>(
        UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this)
{
  this->UFG::WwiseDefaultIOHookDeferred::UFG::WwiseDefaultIOHookDeferredBase::AK::StreamMgr::IAkFileLocationResolver::vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::`vftable{for `AK::StreamMgr::IAkFileLocationResolver};
  this->UFG::WwiseDefaultIOHookDeferred::UFG::WwiseDefaultIOHookDeferredBase::AK::StreamMgr::IAkIOHookDeferred::AK::StreamMgr::IAkLowLevelIOHook::vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::`vftable{for `AK::StreamMgr::IAkIOHookDeferred};
  this->UFG::WwiseDefaultIOHookDeferred::UFG::WwiseDefaultIOHookDeferredBase::UFG::WwiseFileLocationBase::vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::`vftable{for `UFG::WwiseFileLocationBase};
  UFG::WwiseDefaultIOHookDeferred::~WwiseDefaultIOHookDeferred(this);
}

// File Line: 43
// RVA: 0x149B70
signed __int64 __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::Open(
        UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this,
        const wchar_t *in_pszFileName,
        AkOpenMode in_eOpenMode,
        AkFileSystemFlags *in_pFlags,
        bool *io_bSyncOpen,
        AkFileDesc *out_fileDesc)
{
  UFG::TidoFilePackage *m_pFirst; // rbx
  unsigned int SoundBankID; // eax

  if ( in_eOpenMode )
    return 2i64;
  if ( !in_pFlags )
    return 2i64;
  if ( in_pFlags->uCompanyID )
    return 2i64;
  if ( in_pFlags->uCodecID )
    return 2i64;
  m_pFirst = this->m_packages.m_pFirst;
  if ( !m_pFirst )
    return 2i64;
  while ( 1 )
  {
    SoundBankID = UFG::AudioFilePackageLUT::GetSoundBankID(&m_pFirst->lut, in_pszFileName);
    if ( SoundBankID != -1
      && (unsigned int)UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::FindPackagedFile(
                         this,
                         m_pFirst,
                         SoundBankID,
                         in_pFlags,
                         out_fileDesc,
                         eFindPackagedFile_Open) == 1 )
    {
      break;
    }
    m_pFirst = m_pFirst->pNextItem;
    if ( !m_pFirst )
      return 2i64;
  }
  *io_bSyncOpen = 1;
  return 1i64;
}

// File Line: 91
// RVA: 0x1499B0
__int64 __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::Open(
        UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this,
        unsigned int in_fileID,
        AkOpenMode in_eOpenMode,
        AkFileSystemFlags *in_pFlags,
        bool *io_bSyncOpen,
        AkFileDesc *out_fileDesc)
{
  UFG::TidoFilePackage *in_pPackage; // rbx
  unsigned int uCodecID; // r14d
  UFG::AudioFilePackageLUT::FileLUT *m_pSoundBanks; // r8
  UFG::AudioFilePackageLUT::FileLUT *v12; // rbp
  UFG::AudioFilePackageLUT::FileLUT *m_pStmFiles; // rax
  UFG::AudioFilePackageLUT::FileLUT *v14; // r10
  int v15; // r8d
  int v16; // r9d
  int v17; // eax
  unsigned int m_uNumFiles; // ecx
  WWiseOSFileWrapper::QUEUE_CLASS m_priority; // edi
  UFG::qBaseTreeRB *v20; // rax
  int *p_mCount; // rcx
  __int64 v22; // rax
  unsigned int v23; // edx
  unsigned int v24; // eax
  __int64 result; // rax
  char *v26; // rax

  if ( in_eOpenMode )
    return 2i64;
  if ( !in_pFlags )
    return 2i64;
  if ( in_pFlags->uCompanyID > 1 )
    return 2i64;
  in_pPackage = this->m_packages.m_pFirst;
  if ( !in_pPackage )
    return 2i64;
  while ( 2 )
  {
    uCodecID = in_pFlags->uCodecID;
    if ( !uCodecID )
    {
      m_pSoundBanks = in_pPackage->lut.m_pSoundBanks;
      if ( m_pSoundBanks )
      {
        if ( m_pSoundBanks->m_uNumFiles )
        {
          v12 = UFG::AudioFilePackageLUT::LookupFile(
                  &in_pPackage->lut,
                  in_fileID,
                  m_pSoundBanks,
                  in_pFlags->bIsLanguageSpecific);
          goto LABEL_18;
        }
      }
    }
    m_pStmFiles = in_pPackage->lut.m_pStmFiles;
    if ( !m_pStmFiles || !m_pStmFiles->m_uNumFiles )
    {
LABEL_17:
      v12 = 0i64;
      goto LABEL_18;
    }
    v14 = m_pStmFiles + 1;
    v15 = 0;
    v16 = m_pStmFiles->m_uNumFiles - 1;
    while ( 1 )
    {
      v17 = v15 + (v16 - v15) / 2;
      m_uNumFiles = v14[6 * v17].m_uNumFiles;
      if ( m_uNumFiles <= in_fileID )
        break;
      v16 = v17 - 1;
LABEL_16:
      if ( v15 > v16 )
        goto LABEL_17;
    }
    if ( m_uNumFiles < in_fileID )
    {
      v15 = v17 + 1;
      goto LABEL_16;
    }
    v12 = &v14[6 * v17];
LABEL_18:
    m_priority = this->m_priority;
    if ( !uCodecID )
    {
      if ( in_fileID
        && (v20 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, in_fileID)) != 0i64
        && (p_mCount = &v20[-1].mCount, v20 != (UFG::qBaseTreeRB *)8) )
      {
        v22 = *((_QWORD *)p_mCount + 15);
        v23 = p_mCount[20];
        if ( v22 )
        {
          v24 = *(_DWORD *)(v22 + 96);
          if ( v24 > v23 )
            v23 = v24;
        }
        if ( v23 >= 8 )
          m_priority = STREAM_AUDIO_HIGH_PRIORITY;
      }
      else
      {
        m_priority = STREAM_AUDIO_LOW_PRIORITY;
      }
    }
    if ( !v12 )
    {
      in_pPackage = in_pPackage->pNextItem;
      if ( !in_pPackage )
        return 2i64;
      continue;
    }
    break;
  }
  v26 = UFG::StreamFileWrapper::OnPackedAudioFileOpen(
          in_fileID,
          in_pPackage->m_hFile,
          *(_QWORD *)&v12[2].m_uNumFiles,
          v12[4].m_uNumFiles,
          in_pPackage);
  out_fileDesc->deviceID = this->m_WwiseDevice;
  out_fileDesc->hFile = v26;
  out_fileDesc->iFileSize = *(_QWORD *)&v12[2].m_uNumFiles;
  result = 1i64;
  out_fileDesc->uSector = v12[4].m_uNumFiles;
  out_fileDesc->pCustomParam = (void *)m_priority;
  out_fileDesc->uCustomParamSize = v12[1].m_uNumFiles;
  *io_bSyncOpen = 1;
  return result;
}

// File Line: 130
// RVA: 0x143CF0
AKRESULT __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::Close(
        UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this,
        AkFileDesc *in_fileDesc)
{
  if ( !in_fileDesc->uCustomParamSize )
    return UFG::WwiseDefaultIOHookDeferred::Close(this, in_fileDesc);
  UFG::StreamFileWrapper::OnPackedAudioFileClose(in_fileDesc->hFile);
  return 1;
}

// File Line: 150
// RVA: 0x1454D0
void *(__fastcall *__fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::FindFileSize(
        UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this,
        unsigned int in_fileID,
        AkFileSystemFlags *in_pFlags))(UFG::AudioFilePackageLUT *this, unsigned int)
{
  UFG::TidoFilePackage *m_pFirst; // rbx
  unsigned int uCodecID; // r11d
  UFG::AudioFilePackageLUT::FileLUT *m_pSoundBanks; // rax
  int v8; // r8d
  UFG::AudioFilePackageLUT::FileLUT *v9; // r10
  int v10; // r9d
  int v11; // eax
  unsigned int m_uNumFiles; // ecx
  UFG::AudioFilePackageLUT::AkFileEntry *v13; // rsi
  UFG::AudioFilePackageLUT::FileLUT *m_pStmFiles; // rax
  int v16; // r8d
  UFG::AudioFilePackageLUT::FileLUT *v17; // r10
  int v18; // r9d
  int v19; // eax
  unsigned int v20; // ecx

  m_pFirst = this->m_packages.m_pFirst;
  if ( !m_pFirst )
    return 0i64;
  while ( 2 )
  {
    uCodecID = in_pFlags->uCodecID;
    if ( !uCodecID )
    {
      m_pSoundBanks = m_pFirst->lut.m_pSoundBanks;
      if ( m_pSoundBanks )
      {
        if ( m_pSoundBanks->m_uNumFiles )
        {
          v8 = 0;
          v9 = m_pSoundBanks + 1;
          v10 = m_pSoundBanks->m_uNumFiles - 1;
          while ( 1 )
          {
            v11 = v8 + (v10 - v8) / 2;
            m_uNumFiles = v9[6 * v11].m_uNumFiles;
            if ( m_uNumFiles <= in_fileID )
            {
              if ( m_uNumFiles >= in_fileID )
              {
                v13 = (UFG::AudioFilePackageLUT::AkFileEntry *)&v9[6 * v11];
                goto LABEL_12;
              }
              v8 = v11 + 1;
            }
            else
            {
              v10 = v11 - 1;
            }
            if ( v8 > v10 )
              goto LABEL_11;
          }
        }
      }
    }
    m_pStmFiles = m_pFirst->lut.m_pStmFiles;
    if ( !m_pStmFiles || !m_pStmFiles->m_uNumFiles )
    {
LABEL_11:
      v13 = 0i64;
      goto LABEL_12;
    }
    v16 = 0;
    v17 = m_pStmFiles + 1;
    v18 = m_pStmFiles->m_uNumFiles - 1;
    while ( 1 )
    {
      v19 = v16 + (v18 - v16) / 2;
      v20 = v17[6 * v19].m_uNumFiles;
      if ( v20 <= in_fileID )
        break;
      v18 = v19 - 1;
LABEL_26:
      if ( v16 > v18 )
        goto LABEL_11;
    }
    if ( v20 < in_fileID )
    {
      v16 = v19 + 1;
      goto LABEL_26;
    }
    v13 = (UFG::AudioFilePackageLUT::AkFileEntry *)&v17[6 * v19];
LABEL_12:
    if ( !uCodecID )
    {
      if ( in_fileID )
        UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, in_fileID);
    }
    if ( !v13 )
    {
      m_pFirst = m_pFirst->pNextItem;
      if ( !m_pFirst )
        return 0i64;
      continue;
    }
    return (void *(__fastcall *)(UFG::AudioFilePackageLUT *, unsigned int))v13->iFileSize;
  }
}

// File Line: 181
// RVA: 0x145620
__int64 __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::FindFileSize(
        UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this,
        const wchar_t *in_pszFileName,
        AkFileSystemFlags *in_pFlags)
{
  UFG::TidoFilePackage *m_pFirst; // rbx
  unsigned int SoundBankID; // eax
  AkFileDesc out_fileDesc; // [rsp+30h] [rbp-38h] BYREF

  m_pFirst = this->m_packages.m_pFirst;
  if ( !m_pFirst )
    return 0i64;
  while ( 1 )
  {
    SoundBankID = UFG::AudioFilePackageLUT::GetSoundBankID(&m_pFirst->lut, in_pszFileName);
    if ( SoundBankID != -1
      && (unsigned int)UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::FindPackagedFile(
                         this,
                         m_pFirst,
                         SoundBankID,
                         in_pFlags,
                         &out_fileDesc,
                         eFindPackagedFile_GetInfo) == 1 )
    {
      break;
    }
    m_pFirst = m_pFirst->pNextItem;
    if ( !m_pFirst )
      return 0i64;
  }
  return out_fileDesc.iFileSize;
}

// File Line: 214
// RVA: 0x145C20
unsigned int __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::GetBlockSize(
        UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this,
        AkFileDesc *in_fileDesc)
{
  unsigned int result; // eax

  result = in_fileDesc->uCustomParamSize;
  if ( !result )
    return UFG::WwiseDefaultIOHookDeferred::GetBlockSize(this, in_fileDesc);
  return result;
}

// File Line: 261
// RVA: 0x1459B0
signed __int64 __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::FindPackagedFile(
        UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this,
        UFG::TidoFilePackage *in_pPackage,
        unsigned int in_fileID,
        AkFileSystemFlags *in_pFlags,
        AkFileDesc *out_fileDesc,
        UFG::eFindPackagedFile_Mode mode)
{
  unsigned int uCodecID; // r14d
  char *v7; // rbp
  UFG::AudioFilePackageLUT::FileLUT *m_pSoundBanks; // r8
  UFG::AudioFilePackageLUT::FileLUT *v12; // rdi
  WWiseOSFileWrapper::QUEUE_CLASS m_priority; // ebx
  UFG::qBaseTreeRB *v14; // rax
  int *p_mCount; // rcx
  __int64 v16; // rax
  unsigned int v17; // edx
  unsigned int v18; // eax
  signed __int64 result; // rax

  uCodecID = in_pFlags->uCodecID;
  v7 = 0i64;
  if ( !uCodecID && (m_pSoundBanks = in_pPackage->lut.m_pSoundBanks) != 0i64 && m_pSoundBanks->m_uNumFiles
    || (m_pSoundBanks = in_pPackage->lut.m_pStmFiles) != 0i64 && m_pSoundBanks->m_uNumFiles )
  {
    v12 = UFG::AudioFilePackageLUT::LookupFile(
            &in_pPackage->lut,
            in_fileID,
            m_pSoundBanks,
            in_pFlags->bIsLanguageSpecific);
  }
  else
  {
    v12 = 0i64;
  }
  m_priority = this->m_priority;
  if ( !uCodecID )
  {
    if ( in_fileID
      && (v14 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, in_fileID)) != 0i64
      && (p_mCount = &v14[-1].mCount, v14 != (UFG::qBaseTreeRB *)8) )
    {
      v16 = *((_QWORD *)p_mCount + 15);
      v17 = p_mCount[20];
      if ( v16 )
      {
        v18 = *(_DWORD *)(v16 + 96);
        if ( v18 > v17 )
          v17 = v18;
      }
      if ( v17 >= 8 )
        m_priority = STREAM_AUDIO_HIGH_PRIORITY;
    }
    else
    {
      m_priority = STREAM_AUDIO_LOW_PRIORITY;
    }
  }
  if ( !v12 )
    return 66i64;
  if ( mode == eFindPackagedFile_Open )
    v7 = UFG::StreamFileWrapper::OnPackedAudioFileOpen(
           in_fileID,
           in_pPackage->m_hFile,
           *(_QWORD *)&v12[2].m_uNumFiles,
           v12[4].m_uNumFiles,
           in_pPackage);
  result = 1i64;
  out_fileDesc->deviceID = this->m_WwiseDevice;
  out_fileDesc->hFile = v7;
  out_fileDesc->iFileSize = *(_QWORD *)&v12[2].m_uNumFiles;
  out_fileDesc->uSector = v12[4].m_uNumFiles;
  out_fileDesc->pCustomParam = (void *)m_priority;
  out_fileDesc->uCustomParamSize = v12[1].m_uNumFiles;
  return result;
}

// File Line: 312
// RVA: 0x148730
__int64 __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::LoadFilePackage(
        UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this,
        const wchar_t *in_pszFilePackageName,
        unsigned int *out_uPackageID,
        UFG::WwiseFilePackageType filePackageType)
{
  AKRESULT v6; // ebx
  unsigned int m_blockSize; // r8d
  unsigned __int64 v8; // rax
  void *v9; // rsp
  char *v10; // r14
  unsigned int *v11; // r12
  int v12; // eax
  unsigned int v13; // ebx
  unsigned int BlockSize; // eax
  UFG::TidoFilePackage *v15; // rsi
  char *v16; // r13
  unsigned int v17; // r15d
  unsigned int v18; // ebx
  unsigned int v19; // r8d
  UFG::TidoFilePackage *m_pFirst; // rax
  char v22; // [rsp+40h] [rbp-10h] BYREF
  UFG::BIGFileSize v23; // [rsp+50h] [rbp+0h] BYREF
  UFG::BIGFileSize fileSize; // [rsp+60h] [rbp+10h] BYREF
  AkFileDesc __formal; // [rsp+70h] [rbp+20h] BYREF
  UFG::WwiseDefaultIOHookDeferred *v26; // [rsp+98h] [rbp+48h]
  char *out_pHeaderBuffer; // [rsp+A0h] [rbp+50h] BYREF
  AkFileSystemFlags in_pFlags; // [rsp+A8h] [rbp+58h] BYREF
  __int64 v29; // [rsp+C8h] [rbp+78h]
  UFG::qString out_FullFilePath; // [rsp+D0h] [rbp+80h] BYREF
  bool io_bSyncOpen; // [rsp+150h] [rbp+100h] BYREF
  unsigned int *v32; // [rsp+160h] [rbp+110h]
  bool v33; // [rsp+168h] [rbp+118h] BYREF

  v32 = out_uPackageID;
  v29 = -2i64;
  in_pFlags.uCacheID = -1;
  *(_QWORD *)&in_pFlags.uCompanyID = 0i64;
  in_pFlags.bIsLanguageSpecific = 0;
  v33 = filePackageType == eWwiseFilePackageType_DLC;
  in_pFlags.uCustomParamSize = 1;
  in_pFlags.pCustomParam = &v33;
  UFG::qString::qString(&out_FullFilePath);
  v6 = (unsigned int)UFG::WwiseFileLocationBase::BuildFilePath(
                       &this->UFG::WwiseFileLocationBase,
                       in_pszFilePackageName,
                       &in_pFlags,
                       &out_FullFilePath);
  if ( v6 == AK_Success )
  {
    io_bSyncOpen = 1;
    v6 = (unsigned int)UFG::WwiseDefaultIOHookDeferred::Open(
                         this,
                         in_pszFilePackageName,
                         AK_OpenModeRead,
                         &in_pFlags,
                         &io_bSyncOpen,
                         &__formal);
    if ( v6 != AK_Success )
    {
      UFG::WwiseDefaultIOHookDeferred::Close(this, &__formal.hFile);
      goto LABEL_28;
    }
    m_blockSize = this->m_blockSize;
    if ( 8ui64 % m_blockSize )
    {
      v8 = 2 * m_blockSize + 15i64;
      if ( v8 <= 2 * m_blockSize )
        v8 = 0xFFFFFFFFFFFFFF0i64;
      v9 = alloca(v8 & 0xFFFFFFFFFFFFFFF0ui64);
      v10 = (char *)&v23 + m_blockSize - v23.load_offset % m_blockSize;
    }
    else
    {
      v10 = &v22;
      m_blockSize = 8;
    }
    fileSize.load_offset = 0;
    fileSize.compressed_size = m_blockSize;
    fileSize.uncompressed_size = m_blockSize;
    fileSize.compressed_extra = 0;
    *(_QWORD *)&v23.load_offset = UFG::StreamFileWrapper::Read(
                                    __formal.hFile,
                                    STREAM_AUDIO_LOW_PRIORITY,
                                    v10,
                                    &fileSize,
                                    0i64,
                                    QSEEK_SET,
                                    0i64,
                                    0i64,
                                    0);
    if ( v23.load_offset < 8
      || *(_DWORD *)v10 != 0x4B504B41
      || (v11 = (unsigned int *)(v10 + 4), (v12 = *((_DWORD *)v10 + 1)) == 0)
      || (v13 = this->m_blockSize * ((this->m_blockSize + v12 + 7) / this->m_blockSize),
          v26 = (UFG::WwiseDefaultIOHookDeferred *)&this->AK::StreamMgr::IAkIOHookDeferred,
          BlockSize = UFG::WwiseDefaultIOHookDeferred::GetBlockSize(
                        (UFG::WwiseDefaultIOHookDeferred *)&this->AK::StreamMgr::IAkIOHookDeferred,
                        &__formal),
          (v15 = UFG::TidoFilePackage::Create(
                   &__formal.hFile,
                   in_pszFilePackageName,
                   v13,
                   BlockSize,
                   &out_pHeaderBuffer)) == 0i64)
      || (v16 = out_pHeaderBuffer) == 0i64 )
    {
      UFG::WwiseDefaultIOHookDeferred::Close(this, &__formal.hFile);
      goto LABEL_27;
    }
    v17 = *v11;
    if ( v23.load_offset <= 8 )
    {
      v19 = 8;
    }
    else
    {
      v18 = v23.load_offset - 8;
      memmove(out_pHeaderBuffer + 8, v10 + 8, v23.load_offset - 8);
      v19 = v18 + 8;
      v17 = this->m_blockSize * ((v17 + this->m_blockSize - v18 - 1) / this->m_blockSize);
    }
    if ( v17 )
    {
      v23.load_offset = 0;
      v23.compressed_size = v17;
      v23.uncompressed_size = v17;
      v23.compressed_extra = 0;
      if ( (unsigned int)UFG::StreamFileWrapper::Read(
                           __formal.hFile,
                           STREAM_AUDIO_LOW_PRIORITY,
                           &v16[v19],
                           &v23,
                           v19,
                           QSEEK_SET,
                           0i64,
                           0i64,
                           0) < v17 )
      {
        UFG::WwiseDefaultIOHookDeferred::Close(this, &__formal.hFile);
        UFG::WwiseDefaultIOHookDeferred::Close(
          (UFG::WwiseDefaultIOHookDeferred *)&this->AK::StreamMgr::IAkIOHookDeferred,
          &__formal);
        UFG::TidoFilePackage::Destroy(v15);
LABEL_27:
        v6 = AK_Fail;
        goto LABEL_28;
      }
    }
    v6 = (unsigned int)UFG::AudioFilePackageLUT::Setup(&v15->lut, v16, *v11 + 8);
    if ( v6 == AK_Success )
    {
      m_pFirst = this->m_packages.m_pFirst;
      if ( m_pFirst )
      {
        v15->pNextItem = m_pFirst;
        this->m_packages.m_pFirst = v15;
      }
      else
      {
        this->m_packages.m_pFirst = v15;
        v15->pNextItem = 0i64;
      }
      *v32 = v15->m_uPackageID;
      v6 = UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::SetLanguageLUT(this, v15);
    }
    else
    {
      UFG::WwiseDefaultIOHookDeferred::Close(v26, &__formal);
      UFG::TidoFilePackage::Destroy(v15);
    }
  }
LABEL_28:
  UFG::qString::~qString(&out_FullFilePath);
  return (unsigned int)v6;
}

// File Line: 527
// RVA: 0x14CD90
void __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::UnloadAllFilePackages(
        UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this)
{
  UFG::TidoFilePackage *m_pFirst; // rbx
  __int64 v2; // rax
  UFG::TidoFilePackage *pNextItem; // rdi
  int m_poolID; // esi
  void *m_pToRelease; // r14
  __int64 v7; // [rsp+28h] [rbp-20h]

  m_pFirst = this->m_packages.m_pFirst;
  v2 = 0i64;
  if ( m_pFirst )
  {
    while ( 1 )
    {
      pNextItem = m_pFirst->pNextItem;
      v7 = v2;
      if ( m_pFirst == this->m_packages.m_pFirst )
        this->m_packages.m_pFirst = pNextItem;
      else
        *(_QWORD *)(v2 + 8) = pNextItem;
      UFG::WwiseDefaultIOHookDeferred::Close(this, &m_pFirst->m_hFile);
      m_poolID = m_pFirst->m_poolID;
      m_pToRelease = m_pFirst->m_pToRelease;
      m_pFirst->vfptr->__vecDelDtor(m_pFirst, 0);
      if ( m_poolID != -1 )
      {
        if ( m_pToRelease )
          AK::MemoryMgr::ReleaseBlock(m_poolID, m_pToRelease);
        AK::MemoryMgr::DestroyPool(m_poolID);
      }
      if ( !pNextItem )
        break;
      v2 = v7;
      m_pFirst = pNextItem;
    }
  }
}

// File Line: 553
// RVA: 0x14BF40
__int64 __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::SetLanguageLUT(
        UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this,
        UFG::TidoFilePackage *in_pPackage)
{
  const wchar_t *WideName; // rax
  UFG::AudioFilePackageLUT::StringMap *m_pLangMap; // rcx
  unsigned __int16 ID; // ax

  if ( this->m_WwiseLangPath.mLength <= 0 )
  {
    in_pPackage->lut.m_curLangID = 0;
    return 1i64;
  }
  WideName = UFG::qString::GetWideName(&this->m_WwiseLangPath);
  in_pPackage->lut.m_curLangID = 0;
  m_pLangMap = in_pPackage->lut.m_pLangMap;
  if ( !m_pLangMap || !WideName )
    return 1i64;
  ID = UFG::AudioFilePackageLUT::StringMap::GetID(m_pLangMap, WideName);
  if ( !ID )
    return 22i64;
  in_pPackage->lut.m_curLangID = ID;
  return 1i64;
}

