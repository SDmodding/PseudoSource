// File Line: 137
// RVA: 0xABAFD0
__int64 __fastcall VorbisSeek(
        AkVorbisSourceState *in_vorbisState,
        unsigned int in_uDesiredSample,
        unsigned int *out_uSeekedSample,
        unsigned int *out_uFileOffset)
{
  AkVorbisSeekTableItem *pSeekTable; // rdx
  unsigned int dwSeekTableSize; // r14d
  unsigned int v11; // r9d
  int v12; // r11d
  unsigned int v13; // r10d
  unsigned int v14; // r8d
  unsigned int v15; // ecx
  int uPacketFileOffset; // eax

  if ( in_uDesiredSample )
  {
    pSeekTable = in_vorbisState->pSeekTable;
    dwSeekTableSize = in_vorbisState->VorbisInfo.dwSeekTableSize;
    v11 = dwSeekTableSize >> 2;
    if ( pSeekTable && v11 )
    {
      v12 = 0;
      v13 = 0;
      v14 = 0;
      do
      {
        v15 = v13 + pSeekTable->uPacketFrameOffset;
        if ( v15 > in_uDesiredSample )
          break;
        uPacketFileOffset = pSeekTable->uPacketFileOffset;
        ++v14;
        ++pSeekTable;
        v12 += uPacketFileOffset;
        v13 = v15;
      }
      while ( v14 < v11 );
      if ( v14 )
      {
        *out_uFileOffset = dwSeekTableSize + v12;
        *out_uSeekedSample = v13;
      }
      else
      {
        *out_uFileOffset = in_vorbisState->VorbisInfo.dwVorbisDataOffset;
        *out_uSeekedSample = 0;
      }
      return 1i64;
    }
    else
    {
      return 2i64;
    }
  }
  else
  {
    *out_uSeekedSample = 0;
    *out_uFileOffset = in_vorbisState->VorbisInfo.dwVorbisDataOffset;
    return 1i64;
  }
}

