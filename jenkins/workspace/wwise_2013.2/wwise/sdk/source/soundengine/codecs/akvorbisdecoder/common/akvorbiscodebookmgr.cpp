// File Line: 23
// RVA: 0x15BE140
__int64 dynamic_initializer_for__g_VorbisCodebookMgr__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__g_VorbisCodebookMgr__);
}

// File Line: 45
// RVA: 0xABC7E0
CAkVorbisAllocator *__fastcall AkVorbisCodebookMgr::Decodebook(
        AkVorbisCodebookMgr *this,
        AkVorbisSourceState *in_VorbisState,
        CAkPBI *in_pPBI,
        ogg_packet *op)
{
  unsigned int uHashCodebook; // r10d
  AkVorbisCodebookMgr::Codebook *v8; // rax
  CAkVorbisAllocator *result; // rax
  CAkVorbisAllocator *v10; // rsi
  unsigned int uChannelMask; // ecx
  unsigned int dwDecodeX64AllocSize; // r14d
  int i; // edi
  char *v14; // rax
  codec_setup_info *v15; // rbp
  char *data; // rax
  unsigned int v17; // r8d
  __int64 v18; // r8
  void *v19; // rdx
  oggpack_buffer opb; // [rsp+20h] [rbp-48h] BYREF

  uHashCodebook = in_VorbisState->VorbisInfo.uHashCodebook;
  v8 = this->m_codebooks.m_table[uHashCodebook % 0x1F];
  if ( v8 )
  {
    while ( v8->key != uHashCodebook )
    {
      v8 = v8->pNextItem;
      if ( !v8 )
        goto LABEL_4;
    }
    ++v8->cRef;
    return &v8->allocator;
  }
  else
  {
LABEL_4:
    result = (CAkVorbisAllocator *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x30ui64);
    v10 = result;
    if ( result )
    {
      *(_QWORD *)&result->CurrentSize = 0i64;
      result[1].pStartAddress = 0i64;
      result[1].pCurrentAddress = 0i64;
      result[1].CurrentSize = 0;
      uChannelMask = in_VorbisState->TremorInfo.uChannelMask;
      dwDecodeX64AllocSize = in_VorbisState->VorbisInfo.dwDecodeX64AllocSize;
      for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
        ++i;
      v14 = (char *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, in_VorbisState->VorbisInfo.dwDecodeX64AllocSize);
      HIDWORD(v10[1].pCurrentAddress) = dwDecodeX64AllocSize;
      v15 = (codec_setup_info *)v14;
      *(_QWORD *)&v10->CurrentSize = v14;
      v10[1].pStartAddress = v14;
      if ( !v14
        || (LODWORD(v10[1].pCurrentAddress) + 72 > dwDecodeX64AllocSize
          ? (v15 = 0i64)
          : (codec_setup_info *)(v10[1].pStartAddress = v14 + 72, LODWORD(v10[1].pCurrentAddress) += 72),
            vorbis_info_init(
              v15,
              (unsigned __int8)in_VorbisState->VorbisInfo.uBlockSizes[0],
              (unsigned __int8)in_VorbisState->VorbisInfo.uBlockSizes[1])
         || (data = op->buffer.data,
             opb.headend = op->buffer.size,
             opb.headbit = 0,
             opb.headptr = data,
             vorbis_unpack_books(v15, i, &opb, (CAkVorbisAllocator *)&v10->CurrentSize))) )
      {
        v19 = *(void **)&v10->CurrentSize;
        if ( v19 )
        {
          AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v19);
          v10[1].pStartAddress = 0i64;
          v10[1].pCurrentAddress = 0i64;
          *(_QWORD *)&v10->CurrentSize = 0i64;
        }
        AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v10);
        return 0i64;
      }
      else
      {
        ++v10[1].CurrentSize;
        v17 = in_VorbisState->VorbisInfo.uHashCodebook;
        LODWORD(v10->pStartAddress) = v17;
        result = (CAkVorbisAllocator *)&v10->CurrentSize;
        v18 = v17 % 0x1F;
        v10->pCurrentAddress = (char *)this->m_codebooks.m_table[v18];
        this->m_codebooks.m_table[v18] = (AkVorbisCodebookMgr::Codebook *)v10;
        ++this->m_codebooks.m_uiSize;
      }
    }
  }
  return result;
}

// File Line: 132
// RVA: 0xABCA10
void __fastcall AkVorbisCodebookMgr::ReleaseCodebook(AkVorbisCodebookMgr *this, AkVorbisSourceState *in_VorbisState)
{
  unsigned int uHashCodebook; // r9d
  AkVorbisCodebookMgr::Codebook *v4; // rdx
  __int64 v5; // rcx
  AkVorbisCodebookMgr::Codebook **v6; // r10
  AkVorbisCodebookMgr::Codebook *v7; // rbx
  AkVorbisCodebookMgr::Codebook *pNextItem; // r9
  char *pStartAddress; // rdx

  uHashCodebook = in_VorbisState->VorbisInfo.uHashCodebook;
  v4 = 0i64;
  v5 = uHashCodebook % 0x1F;
  v6 = &this->m_codebooks.m_table[v5];
  v7 = *v6;
  if ( *v6 )
  {
    while ( v7->key != uHashCodebook )
    {
      v4 = v7;
      v7 = v7->pNextItem;
      if ( !v7 )
        return;
    }
    if ( --v7->cRef <= 0 )
    {
      pNextItem = v7->pNextItem;
      if ( !pNextItem )
      {
        do
          v5 = (unsigned int)(v5 + 1);
        while ( (unsigned int)v5 < 0x1F && !this->m_codebooks.m_table[v5] );
      }
      if ( v4 )
        v4->pNextItem = pNextItem;
      else
        *v6 = pNextItem;
      --this->m_codebooks.m_uiSize;
      pStartAddress = v7->allocator.pStartAddress;
      if ( pStartAddress )
      {
        AK::MemoryMgr::Free(g_LEngineDefaultPoolId, pStartAddress);
        v7->allocator.pCurrentAddress = 0i64;
        *(_QWORD *)&v7->allocator.CurrentSize = 0i64;
        v7->allocator.pStartAddress = 0i64;
      }
      AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v7);
    }
  }
}

