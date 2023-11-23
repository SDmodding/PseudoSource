// File Line: 44
// RVA: 0xAE7FF0
__int64 __fastcall DSP::DelayLine::Init(
        DSP::DelayLine *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_uDelayLineLength)
{
  float *v4; // rax

  if ( in_uDelayLineLength < 4 )
    in_uDelayLineLength = 4;
  this->uDelayLineLength = in_uDelayLineLength;
  v4 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 4 * ((in_uDelayLineLength + 3) & 0xFFFFFFFC));
  this->pfDelay = v4;
  if ( !v4 )
    return 52i64;
  this->uCurOffset = 0;
  return 1i64;
}

// File Line: 70
// RVA: 0xAE8050
void __fastcall DSP::DelayLine::Term(DSP::DelayLine *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this->pfDelay )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    this->pfDelay = 0i64;
    this->uDelayLineLength = 0;
  }
  else
  {
    this->uDelayLineLength = 0;
  }
}

// File Line: 84
// RVA: 0xAE8090
void __fastcall DSP::DelayLine::Reset(DSP::DelayLine *this)
{
  if ( this->pfDelay )
    memset(this->pfDelay, 0, 4 * this->uDelayLineLength);
}

// File Line: 95
// RVA: 0xAE80C0
void __fastcall DSP::DelayLine::ProcessBuffer(DSP::DelayLine *this, float *io_pfBuffer, unsigned int in_uNumFrames)
{
  __int64 uCurOffset; // r10
  float *pfDelay; // rdi
  unsigned int uDelayLineLength; // ebx
  unsigned int v6; // r11d
  float *v8; // r9
  unsigned int v9; // r8d
  __int64 v10; // rax
  __int64 v11; // rcx
  __int128 v12; // xmm1
  __int128 v13; // xmm0
  int v14; // xmm0_4

  if ( in_uNumFrames )
  {
    uCurOffset = this->uCurOffset;
    pfDelay = this->pfDelay;
    uDelayLineLength = this->uDelayLineLength;
    v6 = in_uNumFrames;
    v8 = &pfDelay[uCurOffset];
    do
    {
      v9 = uDelayLineLength - uCurOffset;
      if ( v6 < uDelayLineLength - (unsigned int)uCurOffset )
        v9 = v6;
      v10 = v9 >> 2;
      v11 = v9 & 3;
      if ( (_DWORD)v10 )
      {
        do
        {
          v12 = *(_OWORD *)v8;
          v13 = *(_OWORD *)io_pfBuffer;
          v8 += 4;
          io_pfBuffer += 4;
          *((_OWORD *)v8 - 1) = v13;
          *((_OWORD *)io_pfBuffer - 1) = v12;
          --v10;
        }
        while ( v10 );
      }
      if ( (v9 & 3) != 0 )
      {
        do
        {
          v14 = *(_DWORD *)v8++;
          *(v8 - 1) = *io_pfBuffer;
          *(_DWORD *)io_pfBuffer++ = v14;
          --v11;
        }
        while ( v11 );
      }
      LODWORD(uCurOffset) = v9 + uCurOffset;
      if ( (_DWORD)uCurOffset == uDelayLineLength )
      {
        v8 = pfDelay;
        LODWORD(uCurOffset) = 0;
      }
      v6 -= v9;
    }
    while ( v6 );
    this->uCurOffset = uCurOffset;
  }
}

// File Line: 141
// RVA: 0xAE8180
void __fastcall DSP::DelayLine::ProcessBuffer(
        DSP::DelayLine *this,
        float *in_pfInBuffer,
        float *out_pfOutBuffer,
        unsigned int in_uNumFrames)
{
  __int64 uCurOffset; // r11
  float *pfDelay; // rsi
  unsigned int uDelayLineLength; // edi
  unsigned int v7; // ebx
  float *v9; // r10
  unsigned int v10; // r9d
  __int64 v11; // rax
  __int64 v12; // rcx
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  int v15; // xmm0_4

  if ( in_uNumFrames )
  {
    uCurOffset = this->uCurOffset;
    pfDelay = this->pfDelay;
    uDelayLineLength = this->uDelayLineLength;
    v7 = in_uNumFrames;
    v9 = &pfDelay[uCurOffset];
    do
    {
      v10 = uDelayLineLength - uCurOffset;
      if ( v7 < uDelayLineLength - (unsigned int)uCurOffset )
        v10 = v7;
      v11 = v10 >> 2;
      v12 = v10 & 3;
      if ( (_DWORD)v11 )
      {
        do
        {
          v13 = *(_OWORD *)v9;
          v14 = *(_OWORD *)in_pfInBuffer;
          v9 += 4;
          out_pfOutBuffer += 4;
          in_pfInBuffer += 4;
          *((_OWORD *)v9 - 1) = v14;
          *((_OWORD *)out_pfOutBuffer - 1) = v13;
          --v11;
        }
        while ( v11 );
      }
      if ( (v10 & 3) != 0 )
      {
        do
        {
          v15 = *(_DWORD *)v9++;
          *(v9 - 1) = *in_pfInBuffer;
          *(_DWORD *)out_pfOutBuffer = v15;
          ++in_pfInBuffer;
          ++out_pfOutBuffer;
          --v12;
        }
        while ( v12 );
      }
      LODWORD(uCurOffset) = v10 + uCurOffset;
      if ( (_DWORD)uCurOffset == uDelayLineLength )
      {
        v9 = pfDelay;
        LODWORD(uCurOffset) = 0;
      }
      v7 -= v10;
    }
    while ( v7 );
    this->uCurOffset = uCurOffset;
  }
}

