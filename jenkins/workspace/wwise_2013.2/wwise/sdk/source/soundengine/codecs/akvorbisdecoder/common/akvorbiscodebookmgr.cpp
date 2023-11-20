// File Line: 23
// RVA: 0x15BE140
__int64 dynamic_initializer_for__g_VorbisCodebookMgr__()
{
  return atexit(dynamic_atexit_destructor_for__g_VorbisCodebookMgr__);
}

// File Line: 45
// RVA: 0xABC7E0
CAkVorbisAllocator *__fastcall AkVorbisCodebookMgr::Decodebook(AkVorbisCodebookMgr *this, AkVorbisSourceState *in_VorbisState, CAkPBI *in_pPBI, ogg_packet *op)
{
  unsigned int v4; // er10
  AkVorbisSourceState *v5; // r15
  ogg_packet *v6; // r13
  AkVorbisCodebookMgr *v7; // r12
  AkVorbisCodebookMgr::Codebook *v8; // rax
  CAkVorbisAllocator *result; // rax
  CAkVorbisAllocator *v10; // rsi
  unsigned int v11; // ecx
  unsigned int v12; // er14
  int i; // edi
  char *v14; // rax
  codec_setup_info *v15; // rbp
  char *v16; // rax
  unsigned int v17; // er8
  __int64 v18; // r8
  void *v19; // rdx
  oggpack_buffer opb; // [rsp+20h] [rbp-48h]

  v4 = in_VorbisState->VorbisInfo.uHashCodebook;
  v5 = in_VorbisState;
  v6 = op;
  v7 = this;
  v8 = this->m_codebooks.m_table[v4 % 0x1F];
  if ( !v8 )
    goto LABEL_4;
  while ( v8->key != v4 )
  {
    v8 = v8->pNextItem;
    if ( !v8 )
      goto LABEL_4;
  }
  if ( v8 )
  {
    ++v8->cRef;
    result = &v8->allocator;
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
      v11 = v5->TremorInfo.uChannelMask;
      v12 = v5->VorbisInfo.dwDecodeX64AllocSize;
      for ( i = 0; v11; v11 &= v11 - 1 )
        ++i;
      v14 = (char *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, v5->VorbisInfo.dwDecodeX64AllocSize);
      HIDWORD(v10[1].pCurrentAddress) = v12;
      v15 = (codec_setup_info *)v14;
      *(_QWORD *)&v10->CurrentSize = v14;
      v10[1].pStartAddress = v14;
      if ( !v14
        || (LODWORD(v10[1].pCurrentAddress) + 72 > v12 ? (v15 = 0i64) : (v10[1].pStartAddress = v14 + 72,
                                                                         LODWORD(v10[1].pCurrentAddress) += 72),
            vorbis_info_init(
              v15,
              (unsigned __int8)v5->VorbisInfo.uBlockSizes[0],
              (unsigned __int8)v5->VorbisInfo.uBlockSizes[1])
         || (v16 = v6->buffer.data,
             opb.headend = v6->buffer.size,
             opb.headbit = 0,
             opb.headptr = v16,
             vorbis_unpack_books(v15, i, &opb, (CAkVorbisAllocator *)((char *)v10 + 16)))) )
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
        result = 0i64;
      }
      else
      {
        ++v10[1].CurrentSize;
        v17 = v5->VorbisInfo.uHashCodebook;
        LODWORD(v10->pStartAddress) = v17;
        result = (CAkVorbisAllocator *)((char *)v10 + 16);
        v18 = v17 % 0x1F;
        v10->pCurrentAddress = (char *)v7->m_codebooks.m_table[v18];
        v7->m_codebooks.m_table[v18] = (AkVorbisCodebookMgr::Codebook *)v10;
        ++v7->m_codebooks.m_uiSize;
      }
    }
  }
  return result;
}

// File Line: 132
// RVA: 0xABCA10
void __fastcall AkVorbisCodebookMgr::ReleaseCodebook(AkVorbisCodebookMgr *this, AkVorbisSourceState *in_VorbisState)
{
  unsigned int v2; // er9
  AkVorbisCodebookMgr *v3; // r8
  AkVorbisCodebookMgr::Codebook *v4; // rdx
  __int64 v5; // rcx
  AkVorbisCodebookMgr::Codebook **v6; // r10
  AkVorbisCodebookMgr::Codebook *v7; // rbx
  AkVorbisCodebookMgr::Codebook *v8; // r9
  char *v9; // rdx

  v2 = in_VorbisState->VorbisInfo.uHashCodebook;
  v3 = this;
  v4 = 0i64;
  v5 = v2 % 0x1F;
  v6 = &v3->m_codebooks.m_table[v5];
  v7 = *v6;
  if ( *v6 )
  {
    while ( v7->key != v2 )
    {
      v4 = v7;
      v7 = v7->pNextItem;
      if ( !v7 )
        return;
    }
    if ( --v7->cRef <= 0 )
    {
      v8 = v7->pNextItem;
      if ( !v8 )
      {
        do
          v5 = (unsigned int)(v5 + 1);
        while ( (unsigned int)v5 < 0x1F && !v3->m_codebooks.m_table[v5] );
      }
      if ( v4 )
        v4->pNextItem = v8;
      else
        *v6 = v8;
      --v3->m_codebooks.m_uiSize;
      v9 = v7->allocator.pStartAddress;
      if ( v9 )
      {
        AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v9);
        v7->allocator.pCurrentAddress = 0i64;
        *(_QWORD *)&v7->allocator.CurrentSize = 0i64;
        v7->allocator.pStartAddress = 0i64;
      }
      AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v7);
    }
  }
}

