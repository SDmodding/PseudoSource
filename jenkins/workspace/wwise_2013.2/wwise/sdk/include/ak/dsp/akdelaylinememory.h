// File Line: 48
// RVA: 0xACC930
__int64 __fastcall AK::DSP::CAkDelayLineMemory<float,8>::Init(
        AK::DSP::CAkDelayLineMemory<float,8> *this,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_uDelayLineLength,
        unsigned int in_uNumChannels)
{
  int v4; // ebx
  float *v7; // rax

  v4 = 0;
  this->m_uNumChannels = in_uNumChannels;
  *(_QWORD *)&this->m_uDelayLineLength = (in_uDelayLineLength + 3) & 0xFFFFFFFC;
  if ( ((in_uDelayLineLength + 3) & 0xFFFFFFFC) == 0 || !in_uNumChannels )
    return 1i64;
  while ( 1 )
  {
    v7 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 4i64 * this->m_uDelayLineLength);
    this->m_pDelay[v4] = v7;
    if ( !v7 )
      break;
    if ( ++v4 >= this->m_uNumChannels )
      return 1i64;
  }
  return 52i64;
}

// File Line: 66
// RVA: 0xACCF20
void __fastcall AK::DSP::CAkDelayLineMemory<float,8>::Term(
        AK::DSP::CAkDelayLineMemory<float,8> *this,
        AK::IAkPluginMemAlloc *in_pAllocator)
{
  unsigned int v4; // ebx
  float **v5; // rsi

  v4 = 0;
  if ( this->m_uNumChannels )
  {
    do
    {
      v5 = &this->m_pDelay[v4];
      if ( *v5 )
      {
        ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
        *v5 = 0i64;
      }
      ++v4;
    }
    while ( v4 < this->m_uNumChannels );
    this->m_uDelayLineLength = 0;
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
  __int64 v2; // rdi
  float *v3; // rcx

  if ( this->m_uDelayLineLength )
  {
    v2 = 0i64;
    if ( this->m_uNumChannels )
    {
      do
      {
        v3 = this->m_pDelay[v2];
        if ( v3 )
          memset(v3, 0, 4 * this->m_uDelayLineLength);
        v2 = (unsigned int)(v2 + 1);
      }
      while ( (unsigned int)v2 < this->m_uNumChannels );
      this->m_uOffset = 0;
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

