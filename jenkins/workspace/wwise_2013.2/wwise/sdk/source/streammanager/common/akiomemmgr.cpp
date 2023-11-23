// File Line: 30
// RVA: 0xAA8700
void __fastcall AK::StreamMgr::CAkIOMemMgr::CAkIOMemMgr(AK::StreamMgr::CAkIOMemMgr *this)
{
  this->vfptr = (AK::StreamMgr::CAkIOMemMgrVtbl *)&AK::StreamMgr::CAkIOMemMgr::`vftable;
  this->m_pIOMemory = 0i64;
  this->m_pMemBlocks = 0i64;
  this->m_listFreeBuffers.m_ulNumListItems = 0;
  this->m_listFreeBuffers.m_pFirst = 0i64;
  this->m_listFreeBuffers.m_pLast = 0i64;
  this->m_arMemBlocks.m_pItems = 0i64;
  *(_QWORD *)&this->m_arMemBlocks.m_uLength = 0i64;
  this->m_uNumViewsAvail = 0;
  this->m_bUseCache = 0;
  this->m_streamIOPoolId = -1;
}

// File Line: 34
// RVA: 0xAA8740
void __fastcall AK::StreamMgr::CAkIOMemMgr::~CAkIOMemMgr(AK::StreamMgr::CAkIOMemMgr *this)
{
  this->vfptr = (AK::StreamMgr::CAkIOMemMgrVtbl *)&AK::StreamMgr::CAkIOMemMgr::`vftable;
}

// File Line: 40
// RVA: 0xAA8A30
__int64 __fastcall AK::StreamMgr::CAkIOMemMgr::Init(AK::StreamMgr::CAkIOMemMgr *this, AkDeviceSettings *in_settings)
{
  unsigned int uGranularity; // r10d
  unsigned int v5; // eax
  __int64 v6; // rsi
  unsigned int v7; // r10d
  hkEntitySelectorAll *m_streamIOPoolId; // rcx
  AK::StreamMgr::AkMemBlock *v9; // rax
  AK::StreamMgr::AkMemBlock *v10; // rcx
  __int64 result; // rax
  char *m_pIOMemory; // rdx
  AK::StreamMgr::AkMemBlock *v13; // r8
  unsigned __int16 v14; // di
  __int64 v15; // rax
  AK::StreamMgr::AkMemBlock *m_pLast; // rax
  unsigned __int16 *v17; // rax
  __int64 m_uLength; // rdx
  unsigned __int16 *v19; // r8
  unsigned int v20; // eax

  uGranularity = in_settings->uGranularity;
  v5 = in_settings->uIOMemorySize / uGranularity;
  v6 = v5;
  v7 = v5 * uGranularity;
  if ( v7 )
    this->m_streamIOPoolId = AK::MemoryMgr::CreatePool(
                               (char *)in_settings->pIOMemory,
                               v7,
                               v7,
                               in_settings->ePoolAttributes | 8u,
                               in_settings->uIOMemoryAlignment);
  m_streamIOPoolId = (hkEntitySelectorAll *)(unsigned int)this->m_streamIOPoolId;
  if ( (_DWORD)m_streamIOPoolId == -1 )
  {
    result = 2i64;
    if ( in_settings->uIOMemorySize )
      return result;
  }
  else
  {
    hkaReferencePoseAnimation::getNumOriginalFrames(m_streamIOPoolId, 0i64);
    this->m_pIOMemory = AK::MemoryMgr::GetBlock(this->m_streamIOPoolId);
    v9 = (AK::StreamMgr::AkMemBlock *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 40 * v6);
    v10 = v9;
    this->m_pMemBlocks = v9;
    if ( !v9 )
      return 2i64;
    m_pIOMemory = (char *)this->m_pIOMemory;
    v13 = &v9[v6];
    v14 = 0;
    do
    {
      if ( v10 )
      {
        v10->uPosition = 0i64;
        v10->pData = m_pIOMemory;
        v10->pNextBlock = 0i64;
        v10->uAvailableSize = 0;
        v10->fileID = -1;
        v10->uRefCount = 0;
      }
      v15 = in_settings->uGranularity;
      v10->pNextBlock = 0i64;
      m_pIOMemory += v15;
      m_pLast = this->m_listFreeBuffers.m_pLast;
      if ( m_pLast )
        m_pLast->pNextBlock = v10;
      else
        this->m_listFreeBuffers.m_pFirst = v10;
      ++this->m_listFreeBuffers.m_ulNumListItems;
      this->m_listFreeBuffers.m_pLast = v10++;
    }
    while ( v10 < v13 );
    if ( (_DWORD)v6 )
    {
      v17 = (unsigned __int16 *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 2 * v6);
      this->m_arMemBlocks.m_pItems = v17;
      if ( !v17 )
        return 2i64;
      this->m_arMemBlocks.m_ulReserved = v6;
      do
      {
        m_uLength = this->m_arMemBlocks.m_uLength;
        if ( (unsigned int)m_uLength < this->m_arMemBlocks.m_ulReserved )
        {
          v19 = &this->m_arMemBlocks.m_pItems[m_uLength];
          this->m_arMemBlocks.m_uLength = m_uLength + 1;
          if ( v19 )
            *v19 = v14;
        }
        ++v14;
      }
      while ( v14 < (unsigned int)v6 );
    }
    v20 = (int)(float)((float)((float)(int)v6 * in_settings->fMaxCacheRatio) + 0.5);
    if ( v20 < (unsigned int)v6 )
      v20 = v6;
    this->m_uNumViewsAvail = v20;
    this->m_bUseCache = in_settings->fMaxCacheRatio > 1.0;
  }
  return 1i64;
}

// File Line: 119
// RVA: 0xAA8F10
void __fastcall AK::StreamMgr::CAkIOMemMgr::Term(AK::StreamMgr::CAkIOMemMgr *this)
{
  unsigned __int16 *m_pItems; // rdx
  int m_streamIOPoolId; // ecx

  m_pItems = this->m_arMemBlocks.m_pItems;
  if ( m_pItems )
  {
    this->m_arMemBlocks.m_uLength = 0;
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, m_pItems);
    this->m_arMemBlocks.m_pItems = 0i64;
    this->m_arMemBlocks.m_ulReserved = 0;
  }
  if ( this->m_listFreeBuffers.m_pFirst )
  {
    this->m_listFreeBuffers.m_pFirst = 0i64;
    this->m_listFreeBuffers.m_pLast = 0i64;
    this->m_listFreeBuffers.m_ulNumListItems = 0;
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, this->m_pMemBlocks);
  }
  this->m_listFreeBuffers.m_pFirst = 0i64;
  this->m_listFreeBuffers.m_pLast = 0i64;
  this->m_listFreeBuffers.m_ulNumListItems = 0;
  m_streamIOPoolId = this->m_streamIOPoolId;
  if ( m_streamIOPoolId != -1 )
  {
    AK::MemoryMgr::ReleaseBlock(m_streamIOPoolId, (AkLinkedBuffer *)this->m_pIOMemory);
    AK::MemoryMgr::DestroyPool(this->m_streamIOPoolId);
    this->m_streamIOPoolId = -1;
  }
}

// File Line: 157
// RVA: 0xAA8C80
__int64 __fastcall AK::StreamMgr::CAkIOMemMgr::ReleaseBlock(
        AK::StreamMgr::CAkIOMemMgr *this,
        AK::StreamMgr::AkMemBlock *in_pMemBlock)
{
  unsigned int v2; // r8d
  AK::StreamMgr::AkMemBlock *m_pLast; // rax
  AK::StreamMgr::AkMemBlock *m_pFirst; // rax

  v2 = --in_pMemBlock->uRefCount;
  if ( (_WORD)v2 )
  {
LABEL_10:
    ++this->m_uNumViewsAvail;
    return v2;
  }
  if ( in_pMemBlock->fileID == -1 )
  {
    m_pFirst = this->m_listFreeBuffers.m_pFirst;
    if ( !m_pFirst )
    {
      this->m_listFreeBuffers.m_pLast = in_pMemBlock;
      this->m_listFreeBuffers.m_pFirst = in_pMemBlock;
      in_pMemBlock->pNextBlock = 0i64;
      ++this->m_listFreeBuffers.m_ulNumListItems;
      ++this->m_uNumViewsAvail;
      return v2;
    }
    in_pMemBlock->pNextBlock = m_pFirst;
    this->m_listFreeBuffers.m_pFirst = in_pMemBlock;
    ++this->m_listFreeBuffers.m_ulNumListItems;
    goto LABEL_10;
  }
  in_pMemBlock->pNextBlock = 0i64;
  m_pLast = this->m_listFreeBuffers.m_pLast;
  if ( m_pLast )
    m_pLast->pNextBlock = in_pMemBlock;
  else
    this->m_listFreeBuffers.m_pFirst = in_pMemBlock;
  this->m_listFreeBuffers.m_pLast = in_pMemBlock;
  ++this->m_listFreeBuffers.m_ulNumListItems;
  ++this->m_uNumViewsAvail;
  return v2;
}

// File Line: 186
// RVA: 0xAA89E0
void __fastcall AK::StreamMgr::CAkIOMemMgr::GetOldestFreeBlock(
        AK::StreamMgr::CAkIOMemMgr *this,
        AK::StreamMgr::AkMemBlock **out_pMemBlock)
{
  AK::StreamMgr::AkMemBlock *m_pFirst; // rax
  AK::StreamMgr::AkMemBlock *v3; // rax
  AK::StreamMgr::AkMemBlock *pNextBlock; // rax

  m_pFirst = this->m_listFreeBuffers.m_pFirst;
  *out_pMemBlock = m_pFirst;
  if ( m_pFirst )
  {
    ++m_pFirst->uRefCount;
    v3 = this->m_listFreeBuffers.m_pFirst;
    if ( v3 )
    {
      if ( !v3->pNextBlock )
      {
        --this->m_listFreeBuffers.m_ulNumListItems;
        this->m_listFreeBuffers.m_pFirst = 0i64;
        this->m_listFreeBuffers.m_pLast = 0i64;
        --this->m_uNumViewsAvail;
        (*out_pMemBlock)->pNextBlock = 0i64;
        return;
      }
      pNextBlock = v3->pNextBlock;
      --this->m_listFreeBuffers.m_ulNumListItems;
      this->m_listFreeBuffers.m_pFirst = pNextBlock;
    }
    --this->m_uNumViewsAvail;
    (*out_pMemBlock)->pNextBlock = 0i64;
  }
}

// File Line: 293
// RVA: 0xAA8810
__int64 __fastcall AK::StreamMgr::CAkIOMemMgr::GetCachedBlock(
        AK::StreamMgr::CAkIOMemMgr *this,
        unsigned int in_fileID,
        unsigned __int64 in_uPosition,
        unsigned int in_uMinSize,
        unsigned int in_uRequiredAlign,
        bool in_bEof,
        unsigned int *io_uRequestedSize,
        AK::StreamMgr::AkMemBlock **out_pMemBlock)
{
  __int64 v8; // rbp
  __int64 result; // rax
  unsigned __int16 *m_pItems; // r11
  AK::StreamMgr::AkMemBlock *m_pMemBlocks; // r14
  signed int v15; // r8d
  signed int v16; // r9d
  __int64 v17; // rdx
  __int64 v18; // r12
  AK::StreamMgr::AkMemBlock *v19; // rcx
  unsigned int fileID; // eax
  AK::StreamMgr::AkMemBlock *v21; // rbx
  unsigned int v22; // edi
  unsigned int v23; // r9d

  v8 = in_uMinSize;
  *out_pMemBlock = 0i64;
  if ( this->m_uNumViewsAvail == this->m_listFreeBuffers.m_ulNumListItems )
    return 0i64;
  m_pItems = this->m_arMemBlocks.m_pItems;
  m_pMemBlocks = this->m_pMemBlocks;
  v15 = this->m_arMemBlocks.m_uLength - 1;
  v16 = 0;
  LODWORD(v17) = v15 / 2;
  while ( 1 )
  {
    v18 = (unsigned int)v17;
    v17 = (unsigned int)(v16 + (v15 - v16) / 2);
    v19 = &m_pMemBlocks[m_pItems[v17]];
    fileID = v19->fileID;
    if ( in_fileID < fileID )
    {
LABEL_9:
      v15 = v17 - 1;
      goto LABEL_10;
    }
    if ( in_fileID <= fileID )
    {
      if ( in_uPosition > v19->uPosition )
        goto LABEL_9;
      if ( in_uPosition >= v19->uPosition )
        break;
    }
    v16 = v17 + 1;
LABEL_10:
    if ( v16 > v15 )
      goto LABEL_14;
  }
  v21 = &m_pMemBlocks[m_pItems[v17]];
  if ( v21 && in_uPosition <= v21->uPosition + *io_uRequestedSize - v8 )
    goto LABEL_20;
LABEL_14:
  v21 = &m_pMemBlocks[m_pItems[v17]];
  if ( in_fileID != v21->fileID
    || in_uPosition < v21->uPosition
    || in_uPosition > v21->uPosition + v21->uAvailableSize - v8 )
  {
    v21 = &m_pMemBlocks[m_pItems[v18]];
    if ( in_fileID != v21->fileID
      || in_uPosition < v21->uPosition
      || in_uPosition > v21->uPosition + v21->uAvailableSize - v8 )
    {
      return 0i64;
    }
  }
LABEL_20:
  v22 = in_uPosition - LODWORD(v21->uPosition);
  v23 = v21->uAvailableSize - v22;
  if ( v23 > *io_uRequestedSize
    || v23 % in_uRequiredAlign && (!in_bEof || v23 != *io_uRequestedSize)
    || ((unsigned __int64)v21->pData + v22) % in_uRequiredAlign
    || v23 < (unsigned int)v8 )
  {
    return 0i64;
  }
  *io_uRequestedSize = v23;
  if ( !v21->uRefCount )
  {
    AkListBare<AK::StreamMgr::AkMemBlock,AK::StreamMgr::AkListBareNextMemBlock,AkCountPolicyWithCount>::Remove(
      &this->m_listFreeBuffers,
      v21);
    v21->pNextBlock = 0i64;
  }
  ++v21->uRefCount;
  --this->m_uNumViewsAvail;
  result = v22;
  *out_pMemBlock = v21;
  return result;
}

// File Line: 448
// RVA: 0xAA8FA0
void __fastcall AK::StreamMgr::CAkIOMemMgr::UntagBlock(
        AK::StreamMgr::CAkIOMemMgr *this,
        AK::StreamMgr::AkMemBlock *in_pMemBlock)
{
  unsigned __int16 *m_pItems; // rbp
  AK::StreamMgr::AkMemBlock *m_pMemBlocks; // r14
  unsigned int fileID; // esi
  signed int v5; // r8d
  AK::StreamMgr::AkMemBlocksDictionnary *p_m_arMemBlocks; // r15
  signed int v7; // r11d
  signed int v9; // r9d
  signed int v10; // r10d
  __int64 v11; // rbx
  AK::StreamMgr::AkMemBlock *v12; // rdx
  unsigned int v13; // eax
  void *pData; // rax
  unsigned __int64 v15; // rcx
  unsigned __int64 uPosition; // r10
  void *v17; // r9
  __int64 v18; // rax
  AK::StreamMgr::AkMemBlock *v19; // rdx
  unsigned __int64 v20; // rcx

  m_pItems = this->m_arMemBlocks.m_pItems;
  m_pMemBlocks = this->m_pMemBlocks;
  fileID = in_pMemBlock->fileID;
  v5 = 0;
  p_m_arMemBlocks = &this->m_arMemBlocks;
  v7 = this->m_arMemBlocks.m_uLength - 1;
  v9 = 0;
  v10 = v7;
  do
  {
    v11 = (unsigned int)(v9 + (v10 - v9) / 2);
    v12 = &m_pMemBlocks[m_pItems[v11]];
    v13 = v12->fileID;
    if ( fileID >= v13 )
    {
      if ( fileID > v13 )
        goto LABEL_8;
      if ( in_pMemBlock->uPosition <= v12->uPosition )
      {
        if ( in_pMemBlock->uPosition < v12->uPosition )
          goto LABEL_8;
        pData = in_pMemBlock->pData;
        v15 = (unsigned __int64)v12->pData;
        if ( (unsigned __int64)pData >= v15 )
        {
          if ( (unsigned __int64)pData <= v15 )
            break;
LABEL_8:
          v9 = v11 + 1;
          continue;
        }
      }
    }
    v10 = v11 - 1;
  }
  while ( v9 <= v10 );
  uPosition = in_pMemBlock->uPosition;
  v17 = in_pMemBlock->pData;
  while ( 1 )
  {
    v18 = (unsigned int)(v5 + (v7 - v5) / 2);
    v19 = &m_pMemBlocks[m_pItems[v18]];
    if ( v19->fileID == -1 )
    {
      if ( uPosition > v19->uPosition )
        goto LABEL_18;
      if ( uPosition >= v19->uPosition )
      {
        v20 = (unsigned __int64)v19->pData;
        if ( (unsigned __int64)v17 < v20 )
        {
LABEL_18:
          v7 = v18 - 1;
          goto LABEL_19;
        }
        if ( (unsigned __int64)v17 <= v20 )
          break;
      }
    }
    v5 = v18 + 1;
LABEL_19:
    if ( v5 > v7 )
      goto LABEL_22;
  }
  v5 += (v7 - v5) / 2;
  v7 = v18;
LABEL_22:
  if ( v7 > v5 )
    v5 = v7;
  AK::StreamMgr::AkMemBlocksDictionnary::Move(p_m_arMemBlocks, v11, v5);
  in_pMemBlock->fileID = -1;
}

// File Line: 544
// RVA: 0xAA8D60
void __fastcall AK::StreamMgr::CAkIOMemMgr::TagBlock(
        AK::StreamMgr::CAkIOMemMgr *this,
        AK::StreamMgr::AkMemBlock *in_pMemBlock,
        AK::StreamMgr::AkMemBlock *in_pTransfer,
        unsigned int in_fileID,
        unsigned __int64 in_uPosition,
        unsigned int in_uDataSize)
{
  unsigned int fileID; // esi
  signed int v10; // r8d
  unsigned __int16 *m_pItems; // r14
  AK::StreamMgr::AkMemBlocksDictionnary *p_m_arMemBlocks; // r13
  signed int v13; // r11d
  AK::StreamMgr::AkMemBlock *m_pMemBlocks; // r15
  signed int v15; // r10d
  signed int v16; // r9d
  __int64 v17; // rdi
  AK::StreamMgr::AkMemBlock *v18; // rdx
  unsigned int v19; // eax
  void *pData; // rax
  unsigned __int64 v21; // rcx
  void *v22; // r9
  __int64 v23; // rax
  AK::StreamMgr::AkMemBlock *v24; // rdx
  unsigned int v25; // ecx
  unsigned __int64 v26; // rcx

  if ( !this->m_bUseCache )
  {
    in_pMemBlock->pNextBlock = in_pTransfer;
    in_pMemBlock->uPosition = in_uPosition;
    in_pMemBlock->uAvailableSize = in_uDataSize;
    return;
  }
  fileID = in_pMemBlock->fileID;
  v10 = 0;
  m_pItems = this->m_arMemBlocks.m_pItems;
  p_m_arMemBlocks = &this->m_arMemBlocks;
  v13 = this->m_arMemBlocks.m_uLength - 1;
  m_pMemBlocks = this->m_pMemBlocks;
  v15 = v13;
  v16 = 0;
  do
  {
    v17 = (unsigned int)(v16 + (v15 - v16) / 2);
    v18 = &m_pMemBlocks[m_pItems[v17]];
    v19 = v18->fileID;
    if ( fileID >= v19 )
    {
      if ( fileID > v19 )
        goto LABEL_10;
      if ( in_pMemBlock->uPosition <= v18->uPosition )
      {
        if ( in_pMemBlock->uPosition < v18->uPosition )
          goto LABEL_10;
        pData = in_pMemBlock->pData;
        v21 = (unsigned __int64)v18->pData;
        if ( (unsigned __int64)pData >= v21 )
        {
          if ( (unsigned __int64)pData <= v21 )
            break;
LABEL_10:
          v16 = v17 + 1;
          continue;
        }
      }
    }
    v15 = v17 - 1;
  }
  while ( v16 <= v15 );
  v22 = in_pMemBlock->pData;
  while ( 1 )
  {
    v23 = (unsigned int)(v10 + (v13 - v10) / 2);
    v24 = &m_pMemBlocks[m_pItems[v23]];
    v25 = v24->fileID;
    if ( in_fileID < v25 )
    {
LABEL_21:
      v13 = v23 - 1;
      goto LABEL_22;
    }
    if ( in_fileID <= v25 )
    {
      if ( in_uPosition > v24->uPosition )
        goto LABEL_21;
      if ( in_uPosition >= v24->uPosition )
      {
        v26 = (unsigned __int64)v24->pData;
        if ( (unsigned __int64)v22 < v26 )
          goto LABEL_21;
        if ( (unsigned __int64)v22 <= v26 )
          break;
      }
    }
    v10 = v23 + 1;
LABEL_22:
    if ( v10 > v13 )
      goto LABEL_25;
  }
  v10 += (v13 - v10) / 2;
  v13 = v23;
LABEL_25:
  if ( v13 > v10 )
    v10 = v13;
  AK::StreamMgr::AkMemBlocksDictionnary::Move(p_m_arMemBlocks, v17, v10);
  in_pMemBlock->uPosition = in_uPosition;
  in_pMemBlock->uAvailableSize = in_uDataSize;
  in_pMemBlock->fileID = in_fileID;
  in_pMemBlock->pNextBlock = in_pTransfer;
}

// File Line: 637
// RVA: 0xAA8780
void __fastcall AK::StreamMgr::CAkIOMemMgr::CloneTempBlock(
        AK::StreamMgr::CAkIOMemMgr *this,
        AK::StreamMgr::AkMemBlock *in_pMemBlockBase,
        AK::StreamMgr::AkMemBlock **out_pMemBlock)
{
  AK::StreamMgr::AkMemBlock *v5; // rax
  void *pData; // rcx

  v5 = (AK::StreamMgr::AkMemBlock *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0x28ui64);
  *out_pMemBlock = v5;
  if ( v5 )
  {
    pData = in_pMemBlockBase->pData;
    v5->fileID = -1;
    v5->uPosition = 0i64;
    v5->pNextBlock = 0i64;
    v5->uAvailableSize = 0;
    v5->pData = pData;
    v5->uRefCount = 0;
    (*out_pMemBlock)->uAvailableSize = in_pMemBlockBase->uAvailableSize;
    (*out_pMemBlock)->uPosition = in_pMemBlockBase->uPosition;
  }
}

// File Line: 652
// RVA: 0xAA87F0
void __fastcall AK::StreamMgr::CAkIOMemMgr::DestroyTempBlock(
        AK::StreamMgr::CAkIOMemMgr *this,
        AK::StreamMgr::AkMemBlock *in_pMemBlockBase,
        AK::StreamMgr::AkMemBlock *in_pMemBlock)
{
  if ( in_pMemBlock != in_pMemBlockBase )
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, in_pMemBlock);
}

