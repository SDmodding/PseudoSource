// File Line: 48
// RVA: 0xACC930
signed __int64 __fastcall AK::DSP::CAkDelayLineMemory<float,8>::Init(AK::DSP::CAkDelayLineMemory<float,8> *this, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_uDelayLineLength, unsigned int in_uNumChannels)
{
  int v4; // ebx
  AK::IAkPluginMemAlloc *v5; // rsi
  AK::DSP::CAkDelayLineMemory<float,8> *v6; // rdi
  __int64 v7; // rax

  v4 = 0;
  v5 = in_pAllocator;
  v6 = this;
  this->m_uNumChannels = in_uNumChannels;
  *(_QWORD *)&this->m_uDelayLineLength = (in_uDelayLineLength + 3) & 0xFFFFFFFC;
  if ( !((in_uDelayLineLength + 3) & 0xFFFFFFFC) || !in_uNumChannels )
    return 1i64;
  while ( 1 )
  {
    v7 = (__int64)v5->vfptr->Malloc(v5, 4i64 * v6->m_uDelayLineLength);
    v6->m_pDelay[v4] = (float *)v7;
    if ( !v7 )
      break;
    if ( ++v4 >= v6->m_uNumChannels )
      return 1i64;
  }
  return 52i64;
}

// File Line: 66
// RVA: 0xACCF20
void __fastcall AK::DSP::CAkDelayLineMemory<float,8>::Term(AK::DSP::CAkDelayLineMemory<float,8> *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  AK::IAkPluginMemAlloc *v2; // r14
  AK::DSP::CAkDelayLineMemory<float,8> *v3; // rdi
  unsigned int v4; // ebx
  float **v5; // rsi

  v2 = in_pAllocator;
  v3 = this;
  v4 = 0;
  if ( this->m_uNumChannels )
  {
    do
    {
      v5 = &v3->m_pDelay[v4];
      if ( *v5 )
      {
        ((void (__fastcall *)(AK::IAkPluginMemAlloc *))v2->vfptr->Free)(v2);
        *v5 = 0i64;
      }
      ++v4;
    }
    while ( v4 < v3->m_uNumChannels );
    v3->m_uDelayLineLength = 0;
  }
  else
  {
    this->m_uDelayLineLength = 0;
  }
}

// File Line: 79
// RVA: 0xACCE50
void __fastcall AK::DSP::CAkDelayLineMemory<float,8>::Reset(AK::DSP::CAkDelayLineMemory<float,8> *this)
{
  AK::DSP::CAkDelayLineMemory<float,8> *v1; // rbx
  __int64 v2; // rdi
  float *v3; // rcx

  v1 = this;
  if ( this->m_uDelayLineLength )
  {
    v2 = 0i64;
    if ( this->m_uNumChannels )
    {
      do
      {
        v3 = v1->m_pDelay[v2];
        if ( v3 )
          memset(v3, 0, 4 * v1->m_uDelayLineLength);
        v2 = (unsigned int)(v2 + 1);
      }
      while ( (unsigned int)v2 < v1->m_uNumChannels );
      v1->m_uOffset = 0;
    }
    else
    {
      this->m_uOffset = 0;
    }
  }
  else
  {
    this->m_uOffset = 0;
  }
}

