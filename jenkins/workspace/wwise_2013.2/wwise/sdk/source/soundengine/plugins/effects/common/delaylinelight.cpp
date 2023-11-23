// File Line: 29
// RVA: 0xAEB460
__int64 __fastcall DSP::CDelayLight::Init(
        DSP::CDelayLight *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_uDelayLineLength)
{
  unsigned int v3; // r8d
  float *v5; // rax

  v3 = in_uDelayLineLength & 0xFFFFFFFC;
  this->m_uDelayLineLength = v3;
  if ( v3 )
  {
    v5 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 4i64 * v3);
    this->m_pfDelay = v5;
    if ( !v5 )
      return 52i64;
  }
  this->m_uCurrOffset = 0;
  return 1i64;
}

// File Line: 43
// RVA: 0xAEB4C0
void __fastcall DSP::CDelayLight::Term(DSP::CDelayLight *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  if ( this->m_pfDelay )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    this->m_pfDelay = 0i64;
    this->m_uDelayLineLength = 0;
  }
  else
  {
    this->m_uDelayLineLength = 0;
  }
}

// File Line: 53
// RVA: 0xAEB500
void __fastcall DSP::CDelayLight::Reset(DSP::CDelayLight *this)
{
  float *m_pfDelay; // rcx

  m_pfDelay = this->m_pfDelay;
  if ( m_pfDelay )
    memset(m_pfDelay, 0, 4 * this->m_uDelayLineLength);
  this->m_uCurrOffset = 0;
}

// File Line: 61
// RVA: 0xAEB540
void __fastcall DSP::CDelayLight::ProcessBuffer(
        DSP::CDelayLight *this,
        float *io_pfInOutBuf,
        unsigned int in_uNumFrames)
{
  float *m_pfDelay; // rbx
  __int64 m_uCurrOffset; // r10
  unsigned int m_uDelayLineLength; // r11d
  float *v7; // rax
  unsigned int v8; // r9d
  __int64 v9; // rcx
  __int128 v10; // xmm1
  __int128 v11; // xmm0
  unsigned int v12; // r8d
  unsigned int v13; // r9d
  unsigned int i; // ecx
  __int128 v15; // xmm1
  __int128 v16; // xmm0

  m_pfDelay = this->m_pfDelay;
  if ( m_pfDelay )
  {
    m_uCurrOffset = this->m_uCurrOffset;
    m_uDelayLineLength = this->m_uDelayLineLength;
    v7 = &m_pfDelay[m_uCurrOffset];
    v8 = this->m_uDelayLineLength - m_uCurrOffset;
    if ( v8 <= in_uNumFrames )
    {
      v12 = in_uNumFrames >> 2;
      v13 = v8 >> 2;
      if ( v12 )
      {
        do
        {
          if ( v12 < v13 )
            v13 = v12;
          for ( i = v13; i; --i )
          {
            v15 = *(_OWORD *)v7;
            v16 = *(_OWORD *)io_pfInOutBuf;
            v7 += 4;
            io_pfInOutBuf += 4;
            *((_OWORD *)v7 - 1) = v16;
            *((_OWORD *)io_pfInOutBuf - 1) = v15;
          }
          LODWORD(m_uCurrOffset) = m_uCurrOffset + 4 * v13;
          if ( (_DWORD)m_uCurrOffset == m_uDelayLineLength )
          {
            v7 = m_pfDelay;
            LODWORD(m_uCurrOffset) = 0;
          }
          v12 -= v13;
          v13 = (m_uDelayLineLength - (unsigned int)m_uCurrOffset) >> 2;
        }
        while ( v12 );
        this->m_uCurrOffset = m_uCurrOffset;
      }
    }
    else
    {
      v9 = in_uNumFrames >> 2;
      if ( (_DWORD)v9 )
      {
        do
        {
          v10 = *(_OWORD *)v7;
          v11 = *(_OWORD *)io_pfInOutBuf;
          v7 += 4;
          io_pfInOutBuf += 4;
          *((_OWORD *)v7 - 1) = v11;
          *((_OWORD *)io_pfInOutBuf - 1) = v10;
          --v9;
        }
        while ( v9 );
      }
      this->m_uCurrOffset = m_uCurrOffset + in_uNumFrames;
    }
  }
}

// File Line: 121
// RVA: 0xAEB620
void __fastcall DSP::CDelayLight::ProcessBuffer(
        DSP::CDelayLight *this,
        float *in_pfInBuf,
        float *out_pfOutBuf,
        unsigned int in_uNumFrames)
{
  float *m_pfDelay; // rsi
  __int64 m_uCurrOffset; // r10
  unsigned int m_uDelayLineLength; // edi
  float *v9; // rax
  unsigned int v10; // edx
  __int64 v11; // rcx
  char *v12; // r11
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  unsigned int v15; // r9d
  unsigned int v16; // edx
  unsigned int i; // ebx
  __int128 v18; // xmm1
  __int128 v19; // xmm0

  m_pfDelay = this->m_pfDelay;
  if ( m_pfDelay )
  {
    m_uCurrOffset = this->m_uCurrOffset;
    m_uDelayLineLength = this->m_uDelayLineLength;
    v9 = &m_pfDelay[m_uCurrOffset];
    v10 = this->m_uDelayLineLength - m_uCurrOffset;
    if ( v10 <= in_uNumFrames )
    {
      v15 = in_uNumFrames >> 2;
      v16 = v10 >> 2;
      if ( v15 )
      {
        do
        {
          if ( v15 < v16 )
            v16 = v15;
          for ( i = v16; i; --i )
          {
            v18 = *(_OWORD *)v9;
            v9 += 4;
            v19 = *(_OWORD *)in_pfInBuf;
            *(_OWORD *)out_pfOutBuf = v18;
            in_pfInBuf += 4;
            out_pfOutBuf += 4;
            *((_OWORD *)v9 - 1) = v19;
          }
          LODWORD(m_uCurrOffset) = m_uCurrOffset + 4 * v16;
          if ( (_DWORD)m_uCurrOffset == m_uDelayLineLength )
          {
            v9 = m_pfDelay;
            LODWORD(m_uCurrOffset) = 0;
          }
          v15 -= v16;
          v16 = (m_uDelayLineLength - (unsigned int)m_uCurrOffset) >> 2;
        }
        while ( v15 );
        this->m_uCurrOffset = m_uCurrOffset;
      }
    }
    else
    {
      v11 = in_uNumFrames >> 2;
      if ( (_DWORD)v11 )
      {
        v12 = (char *)((char *)in_pfInBuf - (char *)v9);
        do
        {
          v13 = *(_OWORD *)v9;
          v14 = *(_OWORD *)((char *)v9 + (_QWORD)v12);
          v9 += 4;
          out_pfOutBuf += 4;
          *((_OWORD *)v9 - 1) = v14;
          *((_OWORD *)out_pfOutBuf - 1) = v13;
          --v11;
        }
        while ( v11 );
      }
      this->m_uCurrOffset = m_uCurrOffset + in_uNumFrames;
    }
  }
}

