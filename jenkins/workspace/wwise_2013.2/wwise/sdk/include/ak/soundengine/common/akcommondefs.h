// File Line: 300
// RVA: 0xA52450
__int64 __fastcall AkAudioBuffer::NumChannels(AkAudioBuffer *this)
{
  unsigned int v1; // ecx
  __int64 result; // rax

  v1 = this->uChannelMask;
  for ( result = 0i64; v1; v1 &= v1 - 1 )
    result = (unsigned int)(result + 1);
  return result;
}

// File Line: 372
// RVA: 0xACC120
float *__fastcall AkAudioBuffer::GetLFE(AkAudioBuffer *this)
{
  unsigned int v1; // eax
  int i; // edx

  v1 = this->uChannelMask;
  if ( !(v1 & 8) )
    return 0i64;
  for ( i = 0; v1; v1 &= v1 - 1 )
    ++i;
  return (float *)((char *)this->pData + 4 * this->uMaxFrames * (unsigned __int64)(unsigned int)(i - 1));
}

// File Line: 382
// RVA: 0xACC1E0
void __fastcall AkAudioBuffer::ZeroPadToMaxFrames(AkAudioBuffer *this)
{
  unsigned int v1; // eax
  __int64 v2; // rdi
  AkAudioBuffer *v3; // rbx
  unsigned int i; // er8
  int v5; // ecx
  __int64 v6; // rsi
  size_t v7; // rbp

  v1 = this->uChannelMask;
  v2 = 0i64;
  v3 = this;
  for ( i = 0; v1; v1 &= v1 - 1 )
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
        memset((char *)v3->pData + 4 * (v3->uValidFrames + v2++ * v3->uMaxFrames), 0, v7);
        --v6;
      }
      while ( v6 );
    }
    v3->uValidFrames = v3->uMaxFrames;
  }
}

