// File Line: 137
// RVA: 0xABAFD0
signed __int64 __fastcall VorbisSeek(AkVorbisSourceState *in_vorbisState, unsigned int in_uDesiredSample, unsigned int *out_uSeekedSample, unsigned int *out_uFileOffset)
{
  unsigned int *v4; // rdi
  unsigned int *v5; // rsi
  unsigned int v6; // ebp
  AkVorbisSourceState *v7; // rbx
  signed __int64 result; // rax
  AkVorbisSeekTableItem *v9; // rdx
  unsigned int v10; // er14
  unsigned int v11; // er9
  int v12; // er11
  unsigned int v13; // er10
  unsigned int v14; // er8
  unsigned int v15; // ecx
  int v16; // eax

  v4 = out_uFileOffset;
  v5 = out_uSeekedSample;
  v6 = in_uDesiredSample;
  v7 = in_vorbisState;
  if ( in_uDesiredSample )
  {
    v9 = in_vorbisState->pSeekTable;
    v10 = in_vorbisState->VorbisInfo.dwSeekTableSize;
    v11 = in_vorbisState->VorbisInfo.dwSeekTableSize >> 2;
    if ( v9 && v11 )
    {
      v12 = 0;
      v13 = 0;
      v14 = 0;
      if ( !v11 )
        goto LABEL_14;
      do
      {
        v15 = v13 + v9->uPacketFrameOffset;
        if ( v15 > v6 )
          break;
        v16 = v9->uPacketFileOffset;
        ++v14;
        ++v9;
        v12 += v16;
        v13 = v15;
      }
      while ( v14 < v11 );
      if ( v14 )
      {
        *v4 = v10 + v12;
        *v5 = v13;
        result = 1i64;
      }
      else
      {
LABEL_14:
        *v4 = v7->VorbisInfo.dwVorbisDataOffset;
        *v5 = 0;
        result = 1i64;
      }
    }
    else
    {
      result = 2i64;
    }
  }
  else
  {
    *out_uSeekedSample = 0;
    *out_uFileOffset = in_vorbisState->VorbisInfo.dwVorbisDataOffset;
    result = 1i64;
  }
  return result;
}

