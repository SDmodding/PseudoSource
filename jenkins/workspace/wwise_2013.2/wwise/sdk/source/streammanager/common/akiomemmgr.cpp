// File Line: 30
// RVA: 0xAA8700
void __fastcall AK::StreamMgr::CAkIOMemMgr::CAkIOMemMgr(AK::StreamMgr::CAkIOMemMgr *this)
{
  this->vfptr = (AK::StreamMgr::CAkIOMemMgrVtbl *)&AK::StreamMgr::CAkIOMemMgr::`vftable';
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
  this->vfptr = (AK::StreamMgr::CAkIOMemMgrVtbl *)&AK::StreamMgr::CAkIOMemMgr::`vftable';
}

// File Line: 40
// RVA: 0xAA8A30
signed __int64 __fastcall AK::StreamMgr::CAkIOMemMgr::Init(AK::StreamMgr::CAkIOMemMgr *this, AkDeviceSettings *in_settings)
{
  unsigned int v2; // er10
  AkDeviceSettings *v3; // r14
  AK::StreamMgr::CAkIOMemMgr *v4; // rbx
  unsigned int v5; // eax
  __int64 v6; // rsi
  unsigned int v7; // er10
  hkEntitySelectorAll *v8; // rcx
  AK::StreamMgr::AkMemBlock *v9; // rax
  AK::StreamMgr::AkMemBlock *v10; // rcx
  signed __int64 result; // rax
  char *v12; // rdx
  unsigned __int64 v13; // r8
  unsigned __int16 v14; // di
  __int64 v15; // rax
  AK::StreamMgr::AkMemBlock *v16; // rax
  unsigned __int16 *v17; // rax
  __int64 v18; // rdx
  unsigned __int16 *v19; // r8
  unsigned int v20; // eax

  v2 = in_settings->uGranularity;
  v3 = in_settings;
  v4 = this;
  v5 = in_settings->uIOMemorySize / v2;
  v6 = v5;
  v7 = v5 * v2;
  if ( v7 )
    this->m_streamIOPoolId = AK::MemoryMgr::CreatePool(
                               in_settings->pIOMemory,
                               v7,
                               v7,
                               in_settings->ePoolAttributes | 8u,
                               in_settings->uIOMemoryAlignment);
  v8 = (hkEntitySelectorAll *)(unsigned int)v4->m_streamIOPoolId;
  if ( (_DWORD)v8 == -1 )
  {
    result = 2i64;
    if ( v3->uIOMemorySize )
      return result;
  }
  else
  {
    hkaReferencePoseAnimation::getNumOriginalFrames(v8, 0i64);
    v4->m_pIOMemory = AK::MemoryMgr::GetBlock(v4->m_streamIOPoolId);
    v9 = (AK::StreamMgr::AkMemBlock *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 40 * v6);
    v10 = v9;
    v4->m_pMemBlocks = v9;
    if ( !v9 )
      return 2i64;
    v12 = (char *)v4->m_pIOMemory;
    v13 = (unsigned __int64)&v9[v6];
    v14 = 0;
    do
    {
      if ( v10 )
      {
        v10->uPosition = 0i64;
        v10->pData = v12;
        v10->pNextBlock = 0i64;
        v10->uAvailableSize = 0;
        v10->fileID = -1;
        v10->uRefCount = 0;
      }
      v15 = v3->uGranularity;
      v10->pNextBlock = 0i64;
      v12 += v15;
      v16 = v4->m_listFreeBuffers.m_pLast;
      if ( v16 )
        v16->pNextBlock = v10;
      else
        v4->m_listFreeBuffers.m_pFirst = v10;
      ++v4->m_listFreeBuffers.m_ulNumListItems;
      v4->m_listFreeBuffers.m_pLast = v10;
      ++v10;
    }
    while ( (unsigned __int64)v10 < v13 );
    if ( (_DWORD)v6 )
    {
      v17 = (unsigned __int16 *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 2 * v6);
      v4->m_arMemBlocks.m_pItems = v17;
      if ( !v17 )
        return 2i64;
      v4->m_arMemBlocks.m_ulReserved = v6;
      if ( (_DWORD)v6 )
      {
        do
        {
          v18 = v4->m_arMemBlocks.m_uLength;
          if ( (unsigned int)v18 < v4->m_arMemBlocks.m_ulReserved )
          {
            v19 = &v4->m_arMemBlocks.m_pItems[v18];
            v4->m_arMemBlocks.m_uLength = v18 + 1;
            if ( v19 )
              *v19 = v14;
          }
          ++v14;
        }
        while ( v14 < (unsigned int)v6 );
      }
    }
    v20 = (signed int)(float)((float)((float)(signed int)v6 * v3->fMaxCacheRatio) + 0.5);
    if ( v20 < (unsigned int)v6 )
      v20 = v6;
    v4->m_uNumViewsAvail = v20;
    v4->m_bUseCache = 1.0 < v3->fMaxCacheRatio;
  }
  return 1i64;
}

// File Line: 119
// RVA: 0xAA8F10
void __fastcall AK::StreamMgr::CAkIOMemMgr::Term(AK::StreamMgr::CAkIOMemMgr *this)
{
  unsigned __int16 *v1; // rdx
  AK::StreamMgr::CAkIOMemMgr *v2; // rbx
  int v3; // ecx

  v1 = this->m_arMemBlocks.m_pItems;
  v2 = this;
  if ( v1 )
  {
    this->m_arMemBlocks.m_uLength = 0;
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v1);
    v2->m_arMemBlocks.m_pItems = 0i64;
    v2->m_arMemBlocks.m_ulReserved = 0;
  }
  if ( v2->m_listFreeBuffers.m_pFirst )
  {
    v2->m_listFreeBuffers.m_pFirst = 0i64;
    v2->m_listFreeBuffers.m_pLast = 0i64;
    v2->m_listFreeBuffers.m_ulNumListItems = 0;
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, v2->m_pMemBlocks);
  }
  v2->m_listFreeBuffers.m_pFirst = 0i64;
  v2->m_listFreeBuffers.m_pLast = 0i64;
  v2->m_listFreeBuffers.m_ulNumListItems = 0;
  v3 = v2->m_streamIOPoolId;
  if ( v3 != -1 )
  {
    AK::MemoryMgr::ReleaseBlock(v3, v2->m_pIOMemory);
    AK::MemoryMgr::DestroyPool(v2->m_streamIOPoolId);
    v2->m_streamIOPoolId = -1;
  }
}

// File Line: 157
// RVA: 0xAA8C80
__int64 __fastcall AK::StreamMgr::CAkIOMemMgr::ReleaseBlock(AK::StreamMgr::CAkIOMemMgr *this, AK::StreamMgr::AkMemBlock *in_pMemBlock)
{
  unsigned int v2; // er8
  AK::StreamMgr::AkMemBlock *v3; // rax
  AK::StreamMgr::AkMemBlock *v5; // rax

  v2 = --in_pMemBlock->uRefCount;
  if ( (_WORD)v2 )
  {
LABEL_10:
    ++this->m_uNumViewsAvail;
    return v2;
  }
  if ( in_pMemBlock->fileID == -1 )
  {
    v5 = this->m_listFreeBuffers.m_pFirst;
    if ( !v5 )
    {
      this->m_listFreeBuffers.m_pLast = in_pMemBlock;
      this->m_listFreeBuffers.m_pFirst = in_pMemBlock;
      in_pMemBlock->pNextBlock = 0i64;
      ++this->m_listFreeBuffers.m_ulNumListItems;
      ++this->m_uNumViewsAvail;
      return v2;
    }
    in_pMemBlock->pNextBlock = v5;
    this->m_listFreeBuffers.m_pFirst = in_pMemBlock;
    ++this->m_listFreeBuffers.m_ulNumListItems;
    goto LABEL_10;
  }
  in_pMemBlock->pNextBlock = 0i64;
  v3 = this->m_listFreeBuffers.m_pLast;
  if ( v3 )
    v3->pNextBlock = in_pMemBlock;
  else
    this->m_listFreeBuffers.m_pFirst = in_pMemBlock;
  this->m_listFreeBuffers.m_pLast = in_pMemBlock;
  ++this->m_listFreeBuffers.m_ulNumListItems;
  ++this->m_uNumViewsAvail;
  return v2;
}

// File Line: 186
// RVA: 0xAA89E0
void __fastcall AK::StreamMgr::CAkIOMemMgr::GetOldestFreeBlock(AK::StreamMgr::CAkIOMemMgr *this, AK::StreamMgr::AkMemBlock **out_pMemBlock)
{
  AK::StreamMgr::AkMemBlock *v2; // rax
  AK::StreamMgr::AkMemBlock *v3; // rax
  AK::StreamMgr::AkMemBlock *v4; // rax

  v2 = this->m_listFreeBuffers.m_pFirst;
  *out_pMemBlock = v2;
  if ( v2 )
  {
    ++v2->uRefCount;
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
      v4 = v3->pNextBlock;
      --this->m_listFreeBuffers.m_ulNumListItems;
      this->m_listFreeBuffers.m_pFirst = v4;
    }
    --this->m_uNumViewsAvail;
    (*out_pMemBlock)->pNextBlock = 0i64;
  }
}

// File Line: 293
// RVA: 0xAA8810
__int64 __fastcall AK::StreamMgr::CAkIOMemMgr::GetCachedBlock(AK::StreamMgr::CAkIOMemMgr *this, unsigned int in_fileID, unsigned __int64 in_uPosition, unsigned int in_uMinSize, unsigned int in_uRequiredAlign, bool in_bEof, unsigned int *io_uRequestedSize, AK::StreamMgr::AkMemBlock **out_pMemBlock)
{
  __int64 v8; // rbp
  unsigned __int64 v9; // rdi
  unsigned int v10; // er10
  AK::StreamMgr::CAkIOMemMgr *v11; // rsi
  __int64 result; // rax
  unsigned __int16 *v13; // r11
  AK::StreamMgr::AkMemBlock *v14; // r14
  signed int v15; // er8
  signed int v16; // er9
  __int64 v17; // rdx
  __int64 v18; // r12
  AK::StreamMgr::AkMemBlock *v19; // rcx
  unsigned int v20; // eax
  AK::StreamMgr::AkMemBlock *v21; // rbx
  unsigned int v22; // edi
  unsigned int v23; // er9

  v8 = in_uMinSize;
  v9 = in_uPosition;
  *out_pMemBlock = 0i64;
  v10 = in_fileID;
  v11 = this;
  if ( this->m_uNumViewsAvail == this->m_listFreeBuffers.m_ulNumListItems )
    return 0i64;
  v13 = this->m_arMemBlocks.m_pItems;
  v14 = this->m_pMemBlocks;
  v15 = this->m_arMemBlocks.m_uLength - 1;
  v16 = 0;
  LODWORD(v17) = v15 / 2;
  while ( 1 )
  {
    v18 = (unsigned int)v17;
    v17 = (unsigned int)(v16 + (v15 - v16) / 2);
    v19 = &v14[v13[v17]];
    v20 = v14[v13[v17]].fileID;
    if ( v10 < v20 )
    {
LABEL_9:
      v15 = v17 - 1;
      goto LABEL_10;
    }
    if ( v10 <= v20 )
    {
      if ( v9 > v19->uPosition )
        goto LABEL_9;
      if ( v9 >= v19->uPosition )
        break;
    }
    v16 = v17 + 1;
LABEL_10:
    if ( v16 > v15 )
      goto LABEL_14;
  }
  v21 = &v14[v13[v17]];
  if ( v21 && v9 <= v21->uPosition + *io_uRequestedSize - v8 )
    goto LABEL_20;
LABEL_14:
  v21 = &v14[v13[v17]];
  if ( v10 != v21->fileID || v9 < v21->uPosition || v9 > v21->uPosition + v21->uAvailableSize - v8 )
  {
    v21 = &v14[v13[v18]];
    if ( v10 != v21->fileID || v9 < v21->uPosition || v9 > v21->uPosition + v21->uAvailableSize - v8 )
      return 0i64;
  }
LABEL_20:
  v22 = v9 - LODWORD(v21->uPosition);
  v23 = v21->uAvailableSize - v22;
  if ( v23 > *io_uRequestedSize
    || v23 % in_uRequiredAlign && (!in_bEof || v23 != *io_uRequestedSize)
    || (_QWORD)((_QWORD)v21->pData + v22) % in_uRequiredAlign
    || v23 < (unsigned int)v8 )
  {
    return 0i64;
  }
  *io_uRequestedSize = v23;
  if ( !v21->uRefCount )
  {
    AkListBare<AK::StreamMgr::AkMemBlock,AK::StreamMgr::AkListBareNextMemBlock,AkCountPolicyWithCount>::Remove(
      &v11->m_listFreeBuffers,
      v21);
    v21->pNextBlock = 0i64;
  }
  ++v21->uRefCount;
  --v11->m_uNumViewsAvail;
  result = v22;
  *out_pMemBlock = v21;
  return result;
}

// File Line: 448
// RVA: 0xAA8FA0
void __fastcall AK::StreamMgr::CAkIOMemMgr::UntagBlock(AK::StreamMgr::CAkIOMemMgr *this, AK::StreamMgr::AkMemBlock *in_pMemBlock)
{
  unsigned __int16 *v2; // rbp
  AK::StreamMgr::AkMemBlock *v3; // r14
  unsigned int v4; // esi
  signed int v5; // er8
  AK::StreamMgr::AkMemBlocksDictionnary *v6; // r15
  signed int v7; // er11
  AK::StreamMgr::AkMemBlock *v8; // rdi
  signed int v9; // er9
  signed int v10; // er10
  __int64 v11; // rbx
  signed __int64 v12; // rdx
  unsigned int v13; // eax
  void *v14; // rax
  unsigned __int64 v15; // rcx
  unsigned __int64 v16; // r10
  void *v17; // r9
  AK::StreamMgr::AkMemBlock *v18; // ST30_8
  __int64 v19; // ST38_8
  __int64 v20; // ST40_8
  __int64 v21; // rax
  AK::StreamMgr::AkMemBlock *v22; // rdx
  unsigned int v23; // ecx
  void *v24; // rcx

  v2 = this->m_arMemBlocks.m_pItems;
  v3 = this->m_pMemBlocks;
  v4 = in_pMemBlock->fileID;
  v5 = 0;
  v6 = &this->m_arMemBlocks;
  v7 = this->m_arMemBlocks.m_uLength - 1;
  v8 = in_pMemBlock;
  v9 = 0;
  v10 = this->m_arMemBlocks.m_uLength - 1;
  do
  {
    v11 = (unsigned int)(v9 + (v10 - v9) / 2);
    v12 = (signed __int64)&v3[v2[v11]];
    v13 = *(_DWORD *)(v12 + 28);
    if ( v4 >= v13 )
    {
      if ( v4 > v13 )
        goto LABEL_8;
      if ( v8->uPosition <= *(_QWORD *)v12 )
      {
        if ( v8->uPosition < *(_QWORD *)v12 )
          goto LABEL_8;
        v14 = v8->pData;
        v15 = *(_QWORD *)(v12 + 8);
        if ( (unsigned __int64)v14 >= v15 )
        {
          if ( (unsigned __int64)v14 <= v15 )
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
  v16 = v8->uPosition;
  v17 = v8->pData;
  v18 = v8->pNextBlock;
  v19 = *(_QWORD *)&v8->uAvailableSize;
  v20 = *(_QWORD *)&v8->uRefCount;
  while ( 1 )
  {
    v21 = (unsigned int)(v5 + (v7 - v5) / 2);
    v22 = &v3[v2[v21]];
    v23 = v3[v2[v21]].fileID;
    if ( v23 > 0xFFFFFFFF )
    {
LABEL_19:
      v7 = v21 - 1;
      goto LABEL_20;
    }
    if ( v23 >= 0xFFFFFFFF )
    {
      if ( v16 > v22->uPosition )
        goto LABEL_19;
      if ( v16 >= v22->uPosition )
      {
        v24 = v22->pData;
        if ( v17 < v24 )
          goto LABEL_19;
        if ( v17 <= v24 )
          break;
      }
    }
    v5 = v21 + 1;
LABEL_20:
    if ( v5 > v7 )
      goto LABEL_23;
  }
  v5 = v21;
  v7 = v21;
LABEL_23:
  if ( v7 > v5 )
    v5 = v7;
  AK::StreamMgr::AkMemBlocksDictionnary::Move(v6, v11, v5);
  v8->fileID = -1;
}

// File Line: 544
// RVA: 0xAA8D60
void __fastcall AK::StreamMgr::CAkIOMemMgr::TagBlock(AK::StreamMgr::CAkIOMemMgr *this, AK::StreamMgr::AkMemBlock *in_pMemBlock, AK::StreamMgr::CAkLowLevelTransfer *in_pTransfer, unsigned int in_fileID, unsigned __int64 in_uPosition, unsigned int in_uDataSize)
{
  unsigned int v6; // ebp
  AK::StreamMgr::CAkLowLevelTransfer *v7; // r12
  AK::StreamMgr::AkMemBlock *v8; // rbx
  unsigned int v9; // esi
  signed int v10; // er8
  unsigned __int16 *v11; // r14
  AK::StreamMgr::AkMemBlocksDictionnary *v12; // r13
  signed int v13; // er11
  AK::StreamMgr::AkMemBlock *v14; // r15
  signed int v15; // er10
  signed int v16; // er9
  __int64 v17; // rdi
  signed __int64 v18; // rdx
  unsigned int v19; // eax
  void *v20; // rax
  unsigned __int64 v21; // rcx
  void *v22; // r9
  unsigned __int64 v23; // ST20_8
  AK::StreamMgr::AkMemBlock *v24; // ST30_8
  __int64 v25; // ST38_8
  __int64 v26; // ST40_8
  __int64 v27; // rax
  AK::StreamMgr::AkMemBlock *v28; // rdx
  unsigned int v29; // ecx
  void *v30; // rcx

  v6 = in_fileID;
  v7 = in_pTransfer;
  v8 = in_pMemBlock;
  if ( !this->m_bUseCache )
  {
    in_pMemBlock->pNextBlock = (AK::StreamMgr::AkMemBlock *)in_pTransfer;
    in_pMemBlock->uPosition = in_uPosition;
    in_pMemBlock->uAvailableSize = in_uDataSize;
    return;
  }
  v9 = in_pMemBlock->fileID;
  v10 = 0;
  v11 = this->m_arMemBlocks.m_pItems;
  v12 = &this->m_arMemBlocks;
  v13 = this->m_arMemBlocks.m_uLength - 1;
  v14 = this->m_pMemBlocks;
  v15 = this->m_arMemBlocks.m_uLength - 1;
  v16 = 0;
  do
  {
    v17 = (unsigned int)(v16 + (v15 - v16) / 2);
    v18 = (signed __int64)&v14[v11[v17]];
    v19 = *(_DWORD *)(v18 + 28);
    if ( v9 >= v19 )
    {
      if ( v9 > v19 )
        goto LABEL_10;
      if ( v8->uPosition <= *(_QWORD *)v18 )
      {
        if ( v8->uPosition < *(_QWORD *)v18 )
          goto LABEL_10;
        v20 = v8->pData;
        v21 = *(_QWORD *)(v18 + 8);
        if ( (unsigned __int64)v20 >= v21 )
        {
          if ( (unsigned __int64)v20 <= v21 )
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
  v22 = v8->pData;
  v23 = v8->uPosition;
  v24 = v8->pNextBlock;
  v25 = *(_QWORD *)&v8->uAvailableSize;
  v26 = *(_QWORD *)&v8->uRefCount;
  while ( 1 )
  {
    v27 = (unsigned int)(v10 + (v13 - v10) / 2);
    v28 = &v14[v11[v27]];
    v29 = v14[v11[v27]].fileID;
    if ( v6 < v29 )
    {
LABEL_21:
      v13 = v27 - 1;
      goto LABEL_22;
    }
    if ( v6 <= v29 )
    {
      if ( in_uPosition > v28->uPosition )
        goto LABEL_21;
      if ( in_uPosition >= v28->uPosition )
      {
        v30 = v28->pData;
        if ( v22 < v30 )
          goto LABEL_21;
        if ( v22 <= v30 )
          break;
      }
    }
    v10 = v27 + 1;
LABEL_22:
    if ( v10 > v13 )
      goto LABEL_25;
  }
  v10 = v27;
  v13 = v27;
LABEL_25:
  if ( v13 > v10 )
    v10 = v13;
  AK::StreamMgr::AkMemBlocksDictionnary::Move(v12, v17, v10);
  v8->uPosition = in_uPosition;
  v8->uAvailableSize = in_uDataSize;
  v8->fileID = v6;
  v8->pNextBlock = (AK::StreamMgr::AkMemBlock *)v7;
}

// File Line: 637
// RVA: 0xAA8780
void __fastcall AK::StreamMgr::CAkIOMemMgr::CloneTempBlock(AK::StreamMgr::CAkIOMemMgr *this, AK::StreamMgr::AkMemBlock *in_pMemBlockBase, AK::StreamMgr::AkMemBlock **out_pMemBlock)
{
  AK::StreamMgr::AkMemBlock *v3; // rdi
  AK::StreamMgr::AkMemBlock **v4; // rbx
  AK::StreamMgr::AkMemBlock *v5; // rax
  void *v6; // rcx

  v3 = in_pMemBlockBase;
  v4 = out_pMemBlock;
  v5 = (AK::StreamMgr::AkMemBlock *)AK::MemoryMgr::Malloc(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, 0x28ui64);
  *v4 = v5;
  if ( v5 )
  {
    v6 = v3->pData;
    v5->fileID = -1;
    v5->uPosition = 0i64;
    v5->pNextBlock = 0i64;
    v5->uAvailableSize = 0;
    v5->pData = v6;
    v5->uRefCount = 0;
    (*v4)->uAvailableSize = v3->uAvailableSize;
    (*v4)->uPosition = v3->uPosition;
  }
}

// File Line: 652
// RVA: 0xAA87F0
void __fastcall AK::StreamMgr::CAkIOMemMgr::DestroyTempBlock(AK::StreamMgr::CAkIOMemMgr *this, AK::StreamMgr::AkMemBlock *in_pMemBlockBase, AK::StreamMgr::AkMemBlock *in_pMemBlock)
{
  if ( in_pMemBlock != in_pMemBlockBase )
    AK::MemoryMgr::Free(AK::StreamMgr::CAkStreamMgr::m_streamMgrPoolId, in_pMemBlock);
}

