// File Line: 61
// RVA: 0xA9ED50
AKRESULT __fastcall AkFileParser::Parse(
        _DWORD *in_pvBuffer,
        unsigned int in_ulBufferSize,
        AkFileParser::FormatInfo *out_pFormatInfo,
        CAkMarkers *out_pMarkers,
        unsigned int *out_pulLoopStart,
        unsigned int *out_pulLoopEnd,
        unsigned int *out_pulDataSize,
        unsigned int *out_pulDataOffset,
        AkFileParser::AnalysisDataChunk *out_pAnalysisData,
        AkFileParser::SeekInfo *out_pSeekTableInfo)
{
  char v10; // di
  int v13; // r13d
  unsigned int *v14; // r8
  unsigned int *v15; // r9
  char *v16; // rbp
  int v17; // eax
  char *v18; // rbx
  int v19; // ecx
  __int64 v20; // rax
  _DWORD *v21; // rbx
  AKRESULT result; // eax
  unsigned int *v23; // r8
  unsigned int i; // r9d
  unsigned int v25; // eax
  __int64 v26; // rdx
  __int64 v27; // rcx
  unsigned int v28; // edx
  AkAudioMarker *m_pMarkers; // rax
  unsigned int v30; // [rsp+54h] [rbp+Ch]

  v10 = 0;
  v13 = (int)in_pvBuffer;
  if ( !in_pvBuffer || !in_ulBufferSize )
    return 31;
  v14 = out_pulLoopStart;
  v15 = out_pulLoopEnd;
  v16 = (char *)in_pvBuffer + in_ulBufferSize;
  *out_pulLoopStart = 0;
  *out_pulLoopEnd = 0;
  if ( in_pvBuffer + 3 > (_DWORD *)v16 )
    return 7;
  if ( *in_pvBuffer != 1179011410 )
    return 7;
  v17 = in_pvBuffer[2];
  if ( v17 != 1163280727 && v17 != 1095587672 )
    return 7;
  v18 = (char *)(in_pvBuffer + 3);
  v19 = in_ulBufferSize - 12;
  if ( in_ulBufferSize - 12 >= 8 )
  {
    while ( 1 )
    {
      v20 = *(_QWORD *)v18;
      v21 = v18 + 8;
      v30 = HIDWORD(v20);
      if ( (unsigned int)(v19 - 8) < HIDWORD(v20) && (_DWORD)v20 != 1635017060 )
        break;
      if ( (unsigned int)v20 > 0x61746164 )
      {
        switch ( (_DWORD)v20 )
        {
          case 0x6B656573:
            if ( out_pSeekTableInfo )
            {
              out_pSeekTableInfo->pSeekTable = v21;
              v10 |= 0x10u;
              out_pSeekTableInfo->uSeekChunkSize = HIDWORD(v20);
            }
            break;
          case 0x6C62616C:
            if ( (v10 & 4) != 0 )
            {
              if ( out_pMarkers )
              {
                v28 = 0;
                if ( out_pMarkers->m_hdrMarkers.uNumMarkers )
                {
                  m_pMarkers = out_pMarkers->m_pMarkers;
                  while ( m_pMarkers->dwIdentifier != *v21 )
                  {
                    ++v28;
                    ++m_pMarkers;
                    if ( v28 >= out_pMarkers->m_hdrMarkers.uNumMarkers )
                      goto LABEL_45;
                  }
                  CAkMarkers::SetLabel(out_pMarkers, v28, (char *)v21 + 4, v30 - 4);
                }
              }
            }
            break;
          case 0x6C706D73:
            if ( v21[7] )
            {
              v27 = (unsigned int)v21[8];
              *v14 = *(_DWORD *)((char *)v21 + v27 + 44);
              *v15 = *(_DWORD *)((char *)v21 + v27 + 48);
            }
            v10 |= 8u;
            break;
        }
      }
      else
      {
        switch ( (_DWORD)v20 )
        {
          case 0x61746164:
            if ( (v10 & 1) != 0 )
            {
              *out_pulDataSize = HIDWORD(v20);
              *out_pulDataOffset = (_DWORD)v21 - v13;
              return 1;
            }
            return 7;
          case 0x20646B61:
            if ( out_pAnalysisData )
            {
              out_pAnalysisData->pData = (AkFileParser::AnalysisData *)v21;
              out_pAnalysisData->uDataSize = HIDWORD(v20);
            }
            break;
          case 0x20657563:
            if ( (v10 & 1) == 0 )
              return 7;
            if ( (v10 & 4) == 0 && out_pMarkers )
            {
              if ( *v21 )
              {
                result = CAkMarkers::Allocate(out_pMarkers, *v21);
                if ( result != AK_Success )
                  return result;
                v23 = v21 + 1;
                for ( i = 0; i < out_pMarkers->m_hdrMarkers.uNumMarkers; out_pMarkers->m_pMarkers[v26].strLabel = 0i64 )
                {
                  v25 = *v23;
                  v26 = i++;
                  v23 += 6;
                  out_pMarkers->m_pMarkers[v26].dwIdentifier = v25;
                  out_pMarkers->m_pMarkers[v26].dwPosition = *(v23 - 5);
                }
              }
              v10 |= 4u;
            }
            break;
          case 0x20746D66:
            if ( (v10 & 1) == 0 )
            {
              out_pFormatInfo->pFormat = (WaveFormatExtensible *)v21;
              v10 |= 1u;
              out_pFormatInfo->uFormatSize = HIDWORD(v20);
            }
            break;
          case 0x5453494C:
            v30 = 4;
            break;
        }
      }
LABEL_45:
      v18 = (char *)v21 + v30;
      if ( (v30 & 1) != 0 && !*v18 && ++v18 > v16 )
        return 7;
      v19 = (_DWORD)v16 - (_DWORD)v18;
      if ( (unsigned int)((_DWORD)v16 - (_DWORD)v18) < 8 )
        return 8;
      v14 = out_pulLoopStart;
      v15 = out_pulLoopEnd;
    }
  }
  return 8;
}

