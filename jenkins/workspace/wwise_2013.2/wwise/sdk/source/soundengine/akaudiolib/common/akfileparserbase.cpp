// File Line: 61
// RVA: 0xA9ED50
AKRESULT __fastcall AkFileParser::Parse(const void *in_pvBuffer, unsigned int in_ulBufferSize, AkFileParser::FormatInfo *out_pFormatInfo, CAkMarkers *out_pMarkers, unsigned int *out_pulLoopStart, unsigned int *out_pulLoopEnd, unsigned int *out_pulDataSize, unsigned int *out_pulDataOffset, AkFileParser::AnalysisDataChunk *out_pAnalysisData, AkFileParser::SeekInfo *out_pSeekTableInfo)
{
  char v10; // di
  CAkMarkers *v11; // rsi
  AkFileParser::FormatInfo *v12; // r12
  int v13; // er13
  unsigned int *v14; // r8
  unsigned int *v15; // r9
  char *v16; // rbp
  int v17; // eax
  char *v18; // rbx
  unsigned int v19; // ecx
  __int64 v20; // rax
  _DWORD *v21; // rbx
  AKRESULT result; // eax
  unsigned int *v23; // r8
  unsigned int v24; // er9
  unsigned int v25; // eax
  signed __int64 v26; // rdx
  __int64 v27; // rcx
  unsigned int v28; // edx
  AkAudioMarker *v29; // rax
  __int64 v30; // [rsp+50h] [rbp+8h]

  v10 = 0;
  v11 = out_pMarkers;
  v12 = out_pFormatInfo;
  v13 = (signed int)in_pvBuffer;
  if ( !in_pvBuffer || !in_ulBufferSize )
    return 31;
  v14 = out_pulLoopStart;
  v15 = out_pulLoopEnd;
  v16 = (char *)in_pvBuffer + in_ulBufferSize;
  *out_pulLoopStart = 0;
  *out_pulLoopEnd = 0;
  if ( (char *)in_pvBuffer + 12 > v16 )
    return 7;
  if ( *(_DWORD *)in_pvBuffer != 1179011410 )
    return 7;
  v17 = *((_DWORD *)in_pvBuffer + 2);
  if ( v17 != 1163280727 && v17 != 1095587672 )
    return 7;
  v18 = (char *)in_pvBuffer + 12;
  v19 = in_ulBufferSize - 12;
  if ( in_ulBufferSize - 12 >= 8 )
  {
    while ( 1 )
    {
      v20 = *(_QWORD *)v18;
      v21 = v18 + 8;
      v30 = v20;
      if ( v19 - 8 < HIDWORD(v20) && (_DWORD)v20 != 1635017060 )
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
            if ( v10 & 4 )
            {
              if ( v11 )
              {
                v28 = 0;
                if ( v11->m_hdrMarkers.uNumMarkers )
                {
                  v29 = v11->m_pMarkers;
                  while ( v29->dwIdentifier != *v21 )
                  {
                    ++v28;
                    ++v29;
                    if ( v28 >= v11->m_hdrMarkers.uNumMarkers )
                      goto LABEL_45;
                  }
                  CAkMarkers::SetLabel(v11, v28, (char *)v21 + 4, HIDWORD(v30) - 4);
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
            if ( v10 & 1 )
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
            if ( !(v10 & 1) )
              return 7;
            if ( !(v10 & 4) && v11 )
            {
              if ( *v21 )
              {
                result = CAkMarkers::Allocate(v11, *v21);
                if ( result != 1 )
                  return result;
                v23 = v21 + 1;
                v24 = 0;
                if ( v11->m_hdrMarkers.uNumMarkers )
                {
                  do
                  {
                    v25 = *v23;
                    v26 = v24++;
                    v23 += 6;
                    v11->m_pMarkers[v26].dwIdentifier = v25;
                    v11->m_pMarkers[v26].dwPosition = *(v23 - 5);
                    v11->m_pMarkers[v26].strLabel = 0i64;
                  }
                  while ( v24 < v11->m_hdrMarkers.uNumMarkers );
                }
              }
              v10 |= 4u;
            }
            break;
          case 0x20746D66:
            if ( !(v10 & 1) )
            {
              v12->pFormat = (WaveFormatExtensible *)v21;
              v10 |= 1u;
              v12->uFormatSize = HIDWORD(v20);
            }
            break;
          case 0x5453494C:
            HIDWORD(v30) = 4;
            break;
        }
      }
LABEL_45:
      v18 = (char *)v21 + HIDWORD(v30);
      if ( v30 & 0x100000000i64 )
      {
        if ( !*v18 && ++v18 > v16 )
          return 7;
      }
      v19 = (_DWORD)v16 - (_DWORD)v18;
      if ( (unsigned int)((_DWORD)v16 - (_DWORD)v18) < 8 )
        return 8;
      v14 = out_pulLoopStart;
      v15 = out_pulLoopEnd;
    }
  }
  return 8;
}

