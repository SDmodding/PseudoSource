// File Line: 29
// RVA: 0xAEB460
signed __int64 __fastcall DSP::CDelayLight::Init(DSP::CDelayLight *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_uDelayLineLength)
{
  unsigned int v3; // er8
  DSP::CDelayLight *v4; // rbx
  float *v5; // rax

  v3 = in_uDelayLineLength & 0xFFFFFFFC;
  v4 = this;
  this->m_uDelayLineLength = v3;
  if ( v3 )
  {
    v5 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 4i64 * v3);
    v4->m_pfDelay = v5;
    if ( !v5 )
      return 52i64;
  }
  v4->m_uCurrOffset = 0;
  return 1i64;
}

// File Line: 43
// RVA: 0xAEB4C0
void __fastcall DSP::CDelayLight::Term(DSP::CDelayLight *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  DSP::CDelayLight *v2; // rbx

  v2 = this;
  if ( this->m_pfDelay )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v2->m_pfDelay = 0i64;
    v2->m_uDelayLineLength = 0;
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
  DSP::CDelayLight *v1; // rbx
  float *v2; // rcx

  v1 = this;
  v2 = this->m_pfDelay;
  if ( v2 )
    memset(v2, 0, 4 * v1->m_uDelayLineLength);
  v1->m_uCurrOffset = 0;
}

// File Line: 61
// RVA: 0xAEB540
void __fastcall DSP::CDelayLight::ProcessBuffer(DSP::CDelayLight *this, float *io_pfInOutBuf, unsigned int in_uNumFrames)
{
  float *v3; // rbx
  DSP::CDelayLight *v4; // rdi
  __int64 v5; // r10
  unsigned int v6; // er11
  float *v7; // rax
  unsigned int v8; // er9
  __int64 v9; // rcx
  __int128 v10; // xmm1
  __int128 v11; // xmm0
  unsigned int v12; // er8
  unsigned int v13; // er9
  unsigned int i; // ecx
  __int128 v15; // xmm1
  __int128 v16; // xmm0

  v3 = this->m_pfDelay;
  v4 = this;
  if ( v3 )
  {
    v5 = this->m_uCurrOffset;
    v6 = this->m_uDelayLineLength;
    v7 = &v3[v5];
    v8 = this->m_uDelayLineLength - v5;
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
          LODWORD(v5) = v5 + 4 * v13;
          if ( (_DWORD)v5 == v6 )
          {
            v7 = v3;
            LODWORD(v5) = 0;
          }
          v12 -= v13;
          v13 = (v6 - (unsigned int)v5) >> 2;
        }
        while ( v12 );
        v4->m_uCurrOffset = v5;
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
      v4->m_uCurrOffset = v5 + in_uNumFrames;
    }
  }
}

// File Line: 121
// RVA: 0xAEB620
void __fastcall DSP::CDelayLight::ProcessBuffer(DSP::CDelayLight *this, float *in_pfInBuf, float *out_pfOutBuf, unsigned int in_uNumFrames)
{
  float *v4; // rsi
  float *v5; // r11
  DSP::CDelayLight *v6; // r14
  __int64 v7; // r10
  unsigned int v8; // edi
  char *v9; // rax
  unsigned int v10; // edx
  __int64 v11; // rcx
  signed __int64 v12; // r11
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  unsigned int v15; // er9
  unsigned int v16; // edx
  unsigned int i; // ebx
  __int128 v18; // xmm1
  __int128 v19; // xmm0

  v4 = this->m_pfDelay;
  v5 = in_pfInBuf;
  v6 = this;
  if ( v4 )
  {
    v7 = this->m_uCurrOffset;
    v8 = this->m_uDelayLineLength;
    v9 = (char *)&v4[v7];
    v10 = this->m_uDelayLineLength - v7;
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
            v9 += 16;
            v19 = *(_OWORD *)v5;
            *(_OWORD *)out_pfOutBuf = v18;
            v5 += 4;
            out_pfOutBuf += 4;
            *((_OWORD *)v9 - 1) = v19;
          }
          LODWORD(v7) = v7 + 4 * v16;
          if ( (_DWORD)v7 == v8 )
          {
            v9 = (char *)v4;
            LODWORD(v7) = 0;
          }
          v15 -= v16;
          v16 = (v8 - (unsigned int)v7) >> 2;
        }
        while ( v15 );
        this->m_uCurrOffset = v7;
      }
    }
    else
    {
      v11 = in_uNumFrames >> 2;
      if ( (_DWORD)v11 )
      {
        v12 = (char *)v5 - v9;
        do
        {
          v13 = *(_OWORD *)v9;
          v14 = *(_OWORD *)&v9[v12];
          v9 += 16;
          out_pfOutBuf += 4;
          *((_OWORD *)v9 - 1) = v14;
          *((_OWORD *)out_pfOutBuf - 1) = v13;
          --v11;
        }
        while ( v11 );
      }
      v6->m_uCurrOffset = v7 + in_uNumFrames;
    }
  }
}

