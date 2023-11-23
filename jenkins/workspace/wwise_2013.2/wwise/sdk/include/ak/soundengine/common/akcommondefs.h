// File Line: 300
// RVA: 0xA52450
__int64 __fastcall AkAudioBuffer::NumChannels(AkAudioBuffer *this)
{
  unsigned int uChannelMask; // ecx
  __int64 result; // rax

  uChannelMask = this->uChannelMask;
  for ( result = 0i64; uChannelMask; uChannelMask &= uChannelMask - 1 )
    result = (unsigned int)(result + 1);
  return result;
}

// File Line: 372
// RVA: 0xACC120
float *__fastcall AkAudioBuffer::GetLFE(AkAudioBuffer *this)
{
  unsigned int uChannelMask; // eax
  int i; // edx

  uChannelMask = this->uChannelMask;
  if ( (uChannelMask & 8) == 0 )
    return 0i64;
  for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
    ++i;
  return (float *)((char *)this->pData + 4 * this->uMaxFrames * (unsigned __int64)(unsigned int)(i - 1));
}

// File Line: 382
// RVA: 0xACC1E0
void __fastcall AkAudioBuffer::ZeroPadToMaxFrames(AkAudioBuffer *this)
{
  unsigned int uChannelMask; // eax
  __int64 v2; // rdi
  unsigned int i; // r8d
  int v5; // ecx
  __int64 v6; // rsi
  size_t v7; // rbp

  uChannelMask = this->uChannelMask;
  v2 = 0i64;
  for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
    ++i;
  v5 = this->uMaxFrames - this->uValidFrames;
  if ( v5 )
  {
    if ( i )
    {
      v6 = i;
      v7 = (unsigned int)(4 * v5);
      do
      {
        memset((char *)this->pData + 4 * this->uValidFrames + 4 * v2 * this->uMaxFrames, 0, v7);
        ++v2;
        --v6;
      }
      while ( v6 );
    }
    this->uValidFrames = this->uMaxFrames;
  }
}

