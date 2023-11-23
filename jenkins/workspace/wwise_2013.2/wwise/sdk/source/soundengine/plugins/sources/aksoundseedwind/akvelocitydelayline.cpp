// File Line: 42
// RVA: 0xAD62B0
__int64 __fastcall CAkVelocityDelayLine::Init(
        CAkVelocityDelayLine *this,
        float in_fInitialVelocity,
        float in_fInitialVariability,
        float in_fInitialGustiness,
        float in_fBufferTime,
        AK::IAkPluginMemAlloc *in_pAllocator,
        unsigned int in_uDelayLineLength,
        float in_fMinVelocity)
{
  __int64 v8; // rdx
  float *v10; // rax
  __int64 v12; // rbx
  float m_fMinVelocity; // xmm0_4

  v8 = in_uDelayLineLength;
  this->m_fMinVelocity = in_fMinVelocity;
  if ( !in_uDelayLineLength )
    v8 = 1i64;
  this->uDelayLineLength = v8;
  v10 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 4 * v8);
  this->pfDelay = v10;
  if ( !v10 )
    return 52i64;
  v12 = 0i64;
  this->uCurOffset = 0;
  for ( this->m_GustManager.m_fGustTarget = this->m_GustManager.m_fGustCurrent;
        (unsigned int)v12 < this->uDelayLineLength;
        v12 = (unsigned int)(v12 + 1) )
  {
    m_fMinVelocity = CAkGustManager::ComputeInstantVelocity(
                       &this->m_GustManager,
                       in_fInitialVelocity,
                       in_fInitialVariability,
                       in_fInitialGustiness,
                       in_fBufferTime);
    if ( m_fMinVelocity <= this->m_fMinVelocity )
      m_fMinVelocity = this->m_fMinVelocity;
    this->pfDelay[v12] = m_fMinVelocity;
  }
  return 1i64;
}

// File Line: 72
// RVA: 0xAD63D0
void __fastcall CAkVelocityDelayLine::Term(CAkVelocityDelayLine *this, AK::IAkPluginMemAlloc *in_pAllocator)
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

