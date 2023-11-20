// File Line: 21
// RVA: 0x140CE0
void __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::~WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>(UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this)
{
  this->vfptr = (AK::StreamMgr::IAkFileLocationResolverVtbl *)&UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::`vftable'{for `AK::StreamMgr::IAkFileLocationResolver'};
  this->vfptr = (AK::StreamMgr::IAkLowLevelIOHookVtbl *)&UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::`vftable'{for `AK::StreamMgr::IAkIOHookDeferred'};
  this->vfptr = (UFG::WwiseFileLocationBaseVtbl *)&UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::`vftable'{for `UFG::WwiseFileLocationBase'};
  UFG::WwiseDefaultIOHookDeferred::~WwiseDefaultIOHookDeferred((UFG::WwiseDefaultIOHookDeferred *)&this->vfptr);
}

// File Line: 43
// RVA: 0x149B70
signed __int64 __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::Open(UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this, const wchar_t *in_pszFileName, AkOpenMode in_eOpenMode, AkFileSystemFlags *in_pFlags, bool *io_bSyncOpen, AkFileDesc *out_fileDesc)
{
  AkFileSystemFlags *v6; // rdi
  const wchar_t *v7; // rbp
  UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *v8; // rsi
  UFG::TidoFilePackage *v9; // rbx
  unsigned int v10; // eax

  v6 = in_pFlags;
  v7 = in_pszFileName;
  v8 = this;
  if ( in_eOpenMode )
    return 2i64;
  if ( !in_pFlags )
    return 2i64;
  if ( *(_QWORD *)&in_pFlags->uCompanyID )
    return 2i64;
  v9 = this->m_packages.m_pFirst;
  if ( !v9 )
    return 2i64;
  while ( 1 )
  {
    v10 = UFG::AudioFilePackageLUT::GetSoundBankID(&v9->lut, v7);
    if ( v10 != -1
      && (unsigned int)UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::FindPackagedFile(
                         v8,
                         v9,
                         v10,
                         v6,
                         out_fileDesc,
                         0) == 1 )
    {
      break;
    }
    v9 = v9->pNextItem;
    if ( !v9 )
      return 2i64;
  }
  *io_bSyncOpen = 1;
  return 1i64;
}

// File Line: 91
// RVA: 0x1499B0
signed __int64 __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::Open(UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this, unsigned int in_fileID, AkOpenMode in_eOpenMode, AkFileSystemFlags *in_pFlags, bool *io_bSyncOpen, AkFileDesc *out_fileDesc)
{
  AkFileSystemFlags *v6; // r15
  unsigned int v7; // esi
  UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *v8; // r13
  UFG::TidoFilePackage *in_pPackage; // rbx
  unsigned int v10; // er14
  UFG::AudioFilePackageLUT::FileLUT *v11; // r8
  UFG::AudioFilePackageLUT::FileLUT *v12; // rbp
  UFG::AudioFilePackageLUT::FileLUT *v13; // rax
  signed __int64 v14; // r10
  int v15; // er8
  int v16; // er9
  int v17; // eax
  unsigned int v18; // ecx
  signed int v19; // edi
  UFG::qBaseTreeRB *v20; // rax
  signed __int64 v21; // rcx
  __int64 v22; // rax
  unsigned int v23; // edx
  unsigned int v24; // eax
  signed __int64 result; // rax
  char *v26; // rax

  v6 = in_pFlags;
  v7 = in_fileID;
  v8 = this;
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
    v10 = v6->uCodecID;
    if ( !v10 )
    {
      v11 = in_pPackage->lut.m_pSoundBanks;
      if ( v11 )
      {
        if ( v11->m_uNumFiles > 0 )
        {
          v12 = UFG::AudioFilePackageLUT::LookupFile(&in_pPackage->lut, v7, v11, v6->bIsLanguageSpecific);
          goto LABEL_18;
        }
      }
    }
    v13 = in_pPackage->lut.m_pStmFiles;
    if ( !v13 || v13->m_uNumFiles <= 0 )
    {
LABEL_17:
      v12 = 0i64;
      goto LABEL_18;
    }
    v14 = (signed __int64)&v13[1];
    v15 = 0;
    v16 = v13->m_uNumFiles - 1;
    while ( 1 )
    {
      v17 = v15 + (v16 - v15) / 2;
      v18 = *(_DWORD *)(v14 + 24i64 * v17);
      if ( v18 <= v7 )
        break;
      v16 = v17 - 1;
LABEL_16:
      if ( v15 > v16 )
        goto LABEL_17;
    }
    if ( v18 < v7 )
    {
      v15 = v17 + 1;
      goto LABEL_16;
    }
    v12 = (UFG::AudioFilePackageLUT::FileLUT *)(v14 + 24i64 * v17);
LABEL_18:
    v19 = v8->m_priority;
    if ( !v10 )
    {
      if ( v7
        && (v20 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v7)) != 0i64
        && (v21 = (signed __int64)&v20[-1].mCount, v20 != (UFG::qBaseTreeRB *)8) )
      {
        v22 = *(_QWORD *)(v21 + 120);
        v23 = *(_DWORD *)(v21 + 80);
        if ( v22 )
        {
          v24 = *(_DWORD *)(v22 + 96);
          if ( v24 > v23 )
            v23 = v24;
        }
        if ( v23 >= 8 )
          v19 = 0;
      }
      else
      {
        v19 = 1;
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
          v7,
          in_pPackage->m_hFile,
          *(_QWORD *)&v12[2].m_uNumFiles,
          v12[4].m_uNumFiles,
          in_pPackage);
  out_fileDesc->deviceID = v8->m_WwiseDevice;
  out_fileDesc->hFile = v26;
  out_fileDesc->iFileSize = *(_QWORD *)&v12[2].m_uNumFiles;
  result = 1i64;
  out_fileDesc->uSector = v12[4].m_uNumFiles;
  out_fileDesc->pCustomParam = (void *)v19;
  out_fileDesc->uCustomParamSize = v12[1].m_uNumFiles;
  *io_bSyncOpen = 1;
  return result;
}

// File Line: 130
// RVA: 0x143CF0
AKRESULT __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::Close(UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this, AkFileDesc *in_fileDesc)
{
  if ( !in_fileDesc->uCustomParamSize )
    return UFG::WwiseDefaultIOHookDeferred::Close((UFG::WwiseDefaultIOHookDeferred *)&this->vfptr, in_fileDesc);
  UFG::StreamFileWrapper::OnPackedAudioFileClose(in_fileDesc->hFile);
  return 1;
}

// File Line: 150
// RVA: 0x1454D0
void *(__fastcall *__fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::FindFileSize(UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this, unsigned int in_fileID, AkFileSystemFlags *in_pFlags))(UFG::AudioFilePackageLUT *this, unsigned int)
{
  UFG::TidoFilePackage *v3; // rbx
  AkFileSystemFlags *v4; // rbp
  unsigned int v5; // edi
  unsigned int v6; // er11
  UFG::AudioFilePackageLUT::FileLUT *v7; // rax
  int v8; // er8
  signed __int64 v9; // r10
  int v10; // er9
  int v11; // eax
  unsigned int v12; // ecx
  UFG::AudioFilePackageLUT::AkFileEntry *v13; // rsi
  UFG::AudioFilePackageLUT::FileLUT *v15; // rax
  int v16; // er8
  signed __int64 v17; // r10
  int v18; // er9
  int v19; // eax
  unsigned int v20; // ecx

  v3 = this->m_packages.m_pFirst;
  v4 = in_pFlags;
  v5 = in_fileID;
  if ( !v3 )
    return 0i64;
  while ( 2 )
  {
    v6 = v4->uCodecID;
    if ( !v6 )
    {
      v7 = v3->lut.m_pSoundBanks;
      if ( v7 )
      {
        if ( v7->m_uNumFiles > 0 )
        {
          v8 = 0;
          v9 = (signed __int64)&v7[1];
          v10 = v7->m_uNumFiles - 1;
          while ( 1 )
          {
            v11 = v8 + (v10 - v8) / 2;
            v12 = *(_DWORD *)(v9 + 24i64 * v11);
            if ( v12 <= v5 )
            {
              if ( v12 >= v5 )
              {
                v13 = (UFG::AudioFilePackageLUT::AkFileEntry *)(v9 + 24i64 * v11);
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
    v15 = v3->lut.m_pStmFiles;
    if ( !v15 || !v15->m_uNumFiles )
    {
LABEL_11:
      v13 = 0i64;
      goto LABEL_12;
    }
    v16 = 0;
    v17 = (signed __int64)&v15[1];
    v18 = v15->m_uNumFiles - 1;
    while ( 1 )
    {
      v19 = v16 + (v18 - v16) / 2;
      v20 = *(_DWORD *)(v17 + 24i64 * v19);
      if ( v20 <= v5 )
        break;
      v18 = v19 - 1;
LABEL_27:
      if ( v16 > v18 )
        goto LABEL_11;
    }
    if ( v20 < v5 )
    {
      v16 = v19 + 1;
      goto LABEL_27;
    }
    v13 = (UFG::AudioFilePackageLUT::AkFileEntry *)(v17 + 24i64 * v19);
LABEL_12:
    if ( !v6 )
    {
      if ( v5 )
        UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v5);
    }
    if ( !v13 )
    {
      v3 = v3->pNextItem;
      if ( !v3 )
        return 0i64;
      continue;
    }
    return (void *(__fastcall *)(UFG::AudioFilePackageLUT *, unsigned int))v13->iFileSize;
  }
}

// File Line: 181
// RVA: 0x145620
__int64 __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::FindFileSize(UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this, const wchar_t *in_pszFileName, AkFileSystemFlags *in_pFlags)
{
  UFG::TidoFilePackage *v3; // rbx
  AkFileSystemFlags *v4; // rbp
  const wchar_t *v5; // rdi
  UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *v6; // rsi
  unsigned int v7; // eax
  AkFileDesc out_fileDesc; // [rsp+30h] [rbp-38h]

  v3 = this->m_packages.m_pFirst;
  v4 = in_pFlags;
  v5 = in_pszFileName;
  v6 = this;
  if ( !v3 )
    return 0i64;
  while ( 1 )
  {
    v7 = UFG::AudioFilePackageLUT::GetSoundBankID(&v3->lut, v5);
    if ( v7 != -1
      && (unsigned int)UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::FindPackagedFile(
                         v6,
                         v3,
                         v7,
                         v4,
                         &out_fileDesc,
                         eFindPackagedFile_GetInfo) == 1 )
    {
      break;
    }
    v3 = v3->pNextItem;
    if ( !v3 )
      return 0i64;
  }
  return out_fileDesc.iFileSize;
}

// File Line: 214
// RVA: 0x145C20
__int64 __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::GetBlockSize(UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this, AkFileDesc *in_fileDesc)
{
  __int64 result; // rax

  result = in_fileDesc->uCustomParamSize;
  JUMPOUT(result, 0, UFG::WwiseDefaultIOHookDeferred::GetBlockSize);
  return result;
}

// File Line: 261
// RVA: 0x1459B0
signed __int64 __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::FindPackagedFile(UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this, UFG::TidoFilePackage *in_pPackage, unsigned int in_fileID, AkFileSystemFlags *in_pFlags, AkFileDesc *out_fileDesc, UFG::eFindPackagedFile_Mode mode)
{
  unsigned int v6; // er14
  char *v7; // rbp
  UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *v8; // r15
  unsigned int v9; // esi
  UFG::TidoFilePackage *v10; // r13
  UFG::AudioFilePackageLUT *v11; // rcx
  UFG::AudioFilePackageLUT::FileLUT *v12; // r8
  UFG::AudioFilePackageLUT::FileLUT *v13; // rdi
  UFG::AudioFilePackageLUT::FileLUT *v14; // r8
  signed int v15; // ebx
  UFG::qBaseTreeRB *v16; // rax
  signed __int64 v17; // rcx
  __int64 v18; // rax
  unsigned int v19; // edx
  unsigned int v20; // eax
  signed __int64 result; // rax

  v6 = in_pFlags->uCodecID;
  v7 = 0i64;
  v8 = this;
  v9 = in_fileID;
  v10 = in_pPackage;
  v11 = &in_pPackage->lut;
  if ( v6 || (v12 = in_pPackage->lut.m_pSoundBanks) == 0i64 || v12->m_uNumFiles <= 0 )
  {
    v14 = in_pPackage->lut.m_pStmFiles;
    if ( v14 && v14->m_uNumFiles > 0 )
      v13 = UFG::AudioFilePackageLUT::LookupFile(v11, v9, v14, in_pFlags->bIsLanguageSpecific);
    else
      v13 = 0i64;
  }
  else
  {
    v13 = UFG::AudioFilePackageLUT::LookupFile(v11, v9, v12, in_pFlags->bIsLanguageSpecific);
  }
  v15 = v8->m_priority;
  if ( !v6 )
  {
    if ( v9
      && (v16 = UFG::qBaseTreeRB::Get(&UFG::SoundBankManager::sm_soundBank_Tree.mTree, v9)) != 0i64
      && (v17 = (signed __int64)&v16[-1].mCount, v16 != (UFG::qBaseTreeRB *)8) )
    {
      v18 = *(_QWORD *)(v17 + 120);
      v19 = *(_DWORD *)(v17 + 80);
      if ( v18 )
      {
        v20 = *(_DWORD *)(v18 + 96);
        if ( v20 > v19 )
          v19 = v20;
      }
      if ( v19 >= 8 )
        v15 = 0;
    }
    else
    {
      v15 = 1;
    }
  }
  if ( !v13 )
    return 66i64;
  if ( mode == eFindPackagedFile_Open )
    v7 = UFG::StreamFileWrapper::OnPackedAudioFileOpen(
           v9,
           v10->m_hFile,
           *(_QWORD *)&v13[2].m_uNumFiles,
           v13[4].m_uNumFiles,
           v10);
  result = 1i64;
  out_fileDesc->deviceID = v8->m_WwiseDevice;
  out_fileDesc->hFile = v7;
  out_fileDesc->iFileSize = *(_QWORD *)&v13[2].m_uNumFiles;
  out_fileDesc->uSector = v13[4].m_uNumFiles;
  out_fileDesc->pCustomParam = (void *)v15;
  out_fileDesc->uCustomParamSize = v13[1].m_uNumFiles;
  return result;
}

// File Line: 312
// RVA: 0x148730
__int64 __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::LoadFilePackage(UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this, const wchar_t *in_pszFilePackageName, unsigned int *out_uPackageID, UFG::WwiseFilePackageType filePackageType)
{
  const wchar_t *v4; // rsi
  UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *v5; // rdi
  char v6; // al
  AKRESULT v7; // ebx
  unsigned int v8; // er8
  unsigned __int64 v9; // rax
  void *v10; // rsp
  char *v11; // r14
  unsigned int *v12; // r12
  int v13; // eax
  unsigned int v14; // ebx
  unsigned int v15; // eax
  UFG::TidoFilePackage *v16; // rsi
  char *v17; // r13
  unsigned int v18; // er15
  unsigned int v19; // ebx
  unsigned int v20; // er8
  UFG::TidoFilePackage *v21; // rax
  char v23; // [rsp+40h] [rbp-10h]
  UFG::BIGFileSize v24; // [rsp+50h] [rbp+0h]
  UFG::BIGFileSize fileSize; // [rsp+60h] [rbp+10h]
  AkFileDesc __formal; // [rsp+70h] [rbp+20h]
  UFG::WwiseDefaultIOHookDeferred *v27; // [rsp+98h] [rbp+48h]
  char *out_pHeaderBuffer; // [rsp+A0h] [rbp+50h]
  AkFileSystemFlags in_pFlags; // [rsp+A8h] [rbp+58h]
  __int64 v30; // [rsp+C8h] [rbp+78h]
  UFG::qString out_FullFilePath; // [rsp+D0h] [rbp+80h]
  bool io_bSyncOpen; // [rsp+150h] [rbp+100h]
  unsigned int *v33; // [rsp+160h] [rbp+110h]
  char v34; // [rsp+168h] [rbp+118h]

  v33 = out_uPackageID;
  v30 = -2i64;
  v4 = in_pszFilePackageName;
  v5 = this;
  in_pFlags.uCacheID = -1;
  *(_QWORD *)&in_pFlags.uCompanyID = 0i64;
  in_pFlags.bIsLanguageSpecific = 0;
  v6 = 0;
  if ( filePackageType == 1 )
    v6 = 1;
  v34 = v6;
  in_pFlags.uCustomParamSize = 1;
  in_pFlags.pCustomParam = &v34;
  UFG::qString::qString(&out_FullFilePath);
  v7 = (unsigned int)UFG::WwiseFileLocationBase::BuildFilePath(
                       (UFG::WwiseFileLocationBase *)&v5->vfptr,
                       v4,
                       &in_pFlags,
                       &out_FullFilePath);
  if ( v7 == 1 )
  {
    io_bSyncOpen = 1;
    v7 = (unsigned int)UFG::WwiseDefaultIOHookDeferred::Open(
                         (UFG::WwiseDefaultIOHookDeferred *)&v5->vfptr,
                         v4,
                         0,
                         &in_pFlags,
                         &io_bSyncOpen,
                         &__formal);
    if ( v7 != 1 )
    {
      UFG::WwiseDefaultIOHookDeferred::Close((UFG::WwiseDefaultIOHookDeferred *)&v5->vfptr, &__formal.hFile);
      goto LABEL_30;
    }
    v8 = v5->m_blockSize;
    if ( 8ui64 % v5->m_blockSize )
    {
      v9 = 2 * v8 + 15i64;
      if ( v9 <= 2 * v8 )
        v9 = 0xFFFFFFFFFFFFFF0i64;
      v10 = alloca(v9);
      v11 = (char *)&v24 + v8 - v24.load_offset % v8;
    }
    else
    {
      v11 = &v23;
      v8 = 8;
    }
    fileSize.load_offset = 0;
    fileSize.compressed_size = v8;
    fileSize.uncompressed_size = v8;
    fileSize.compressed_extra = 0;
    *(_QWORD *)&v24.load_offset = UFG::StreamFileWrapper::Read(
                                    __formal.hFile,
                                    STREAM_AUDIO_LOW_PRIORITY,
                                    v11,
                                    &fileSize,
                                    0i64,
                                    0,
                                    0i64,
                                    0i64,
                                    0);
    if ( v24.load_offset < 8
      || *(_DWORD *)v11 != 0x4B504B41
      || (v12 = (unsigned int *)(v11 + 4), (v13 = *((_DWORD *)v11 + 1)) == 0)
      || (v14 = v5->m_blockSize * ((v5->m_blockSize + v13 + 7) / v5->m_blockSize),
          v27 = (UFG::WwiseDefaultIOHookDeferred *)&v5->vfptr,
          v15 = UFG::WwiseDefaultIOHookDeferred::GetBlockSize((UFG::WwiseDefaultIOHookDeferred *)&v5->vfptr, &__formal),
          (v16 = UFG::TidoFilePackage::Create(&__formal.hFile, v4, v14, v15, &out_pHeaderBuffer)) == 0i64)
      || (v17 = out_pHeaderBuffer) == 0i64 )
    {
      UFG::WwiseDefaultIOHookDeferred::Close((UFG::WwiseDefaultIOHookDeferred *)&v5->vfptr, &__formal.hFile);
      goto LABEL_29;
    }
    v18 = *v12;
    if ( v24.load_offset <= 8 )
    {
      v20 = 8;
    }
    else
    {
      v19 = v24.load_offset - 8;
      memmove(out_pHeaderBuffer + 8, v11 + 8, v24.load_offset - 8);
      v20 = v19 + 8;
      v18 = v5->m_blockSize * ((v18 + v5->m_blockSize - v19 - 1) / v5->m_blockSize);
    }
    if ( v18 )
    {
      v24.load_offset = 0;
      v24.compressed_size = v18;
      v24.uncompressed_size = v18;
      v24.compressed_extra = 0;
      if ( (unsigned int)UFG::StreamFileWrapper::Read(
                           __formal.hFile,
                           STREAM_AUDIO_LOW_PRIORITY,
                           &v17[v20],
                           &v24,
                           v20,
                           0,
                           0i64,
                           0i64,
                           0) < v18 )
      {
        UFG::WwiseDefaultIOHookDeferred::Close((UFG::WwiseDefaultIOHookDeferred *)&v5->vfptr, &__formal.hFile);
        UFG::WwiseDefaultIOHookDeferred::Close((UFG::WwiseDefaultIOHookDeferred *)&v5->vfptr, &__formal);
        UFG::TidoFilePackage::Destroy(v16);
LABEL_29:
        v7 = 2;
        goto LABEL_30;
      }
    }
    v7 = (unsigned int)UFG::AudioFilePackageLUT::Setup(&v16->lut, v17, *v12 + 8);
    if ( v7 == 1 )
    {
      v21 = v5->m_packages.m_pFirst;
      if ( v21 )
      {
        v16->pNextItem = v21;
        v5->m_packages.m_pFirst = v16;
      }
      else
      {
        v5->m_packages.m_pFirst = v16;
        v16->pNextItem = 0i64;
      }
      *v33 = v16->m_uPackageID;
      v7 = UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::SetLanguageLUT(v5, v16);
    }
    else
    {
      UFG::WwiseDefaultIOHookDeferred::Close(v27, &__formal);
      UFG::TidoFilePackage::Destroy(v16);
    }
  }
LABEL_30:
  UFG::qString::~qString(&out_FullFilePath);
  return (unsigned int)v7;
}

// File Line: 527
// RVA: 0x14CD90
void __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::UnloadAllFilePackages(UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this)
{
  UFG::TidoFilePackage *v1; // rbx
  __int64 v2; // rax
  UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *v3; // rbp
  UFG::TidoFilePackage *v4; // rdi
  int v5; // esi
  void *v6; // r14
  __m128i v7; // [rsp+20h] [rbp-28h]
  __m128i v8; // [rsp+30h] [rbp-18h]

  v1 = this->m_packages.m_pFirst;
  v2 = 0i64;
  v3 = this;
  if ( v1 )
  {
    while ( 1 )
    {
      v4 = v1->pNextItem;
      v7.m128i_i64[1] = v2;
      v7.m128i_i64[0] = (__int64)v1->pNextItem;
      if ( v1 == v3->m_packages.m_pFirst )
        v3->m_packages.m_pFirst = v4;
      else
        *(_QWORD *)(v2 + 8) = v4;
      _mm_store_si128(&v8, v7);
      UFG::WwiseDefaultIOHookDeferred::Close((UFG::WwiseDefaultIOHookDeferred *)&v3->vfptr, &v1->m_hFile);
      v5 = v1->m_poolID;
      v6 = v1->m_pToRelease;
      v1->vfptr->__vecDelDtor(v1, 0);
      if ( v5 != -1 )
      {
        if ( v6 )
          AK::MemoryMgr::ReleaseBlock(v5, v6);
        AK::MemoryMgr::DestroyPool(v5);
      }
      if ( !v4 )
        break;
      v2 = v8.m128i_i64[1];
      v1 = (UFG::TidoFilePackage *)v8.m128i_i64[0];
    }
  }
}

// File Line: 553
// RVA: 0x14BF40
signed __int64 __fastcall UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::SetLanguageLUT(UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred> *this, UFG::TidoFilePackage *in_pPackage)
{
  UFG::TidoFilePackage *v2; // rbx
  const wchar_t *v3; // rax
  UFG::AudioFilePackageLUT::StringMap *v4; // rcx
  unsigned __int16 v5; // ax

  v2 = in_pPackage;
  if ( this->m_WwiseLangPath.mLength <= 0 )
  {
    in_pPackage->lut.m_curLangID = 0;
    return 1i64;
  }
  v3 = UFG::qString::GetWideName(&this->m_WwiseLangPath);
  v2->lut.m_curLangID = 0;
  v4 = v2->lut.m_pLangMap;
  if ( !v4 || !v3 )
    return 1i64;
  v5 = UFG::AudioFilePackageLUT::StringMap::GetID(v4, v3);
  if ( !v5 )
    return 22i64;
  v2->lut.m_curLangID = v5;
  return 1i64;
}

