// File Line: 42
// RVA: 0xAD62B0
signed __int64 __fastcall CAkVelocityDelayLine::Init(CAkVelocityDelayLine *this, float in_fInitialVelocity, float in_fInitialVariability, float in_fInitialGustiness, float in_fBufferTime, AK::IAkPluginMemAlloc *in_pAllocator, unsigned int in_uDelayLineLength, float in_fMinVelocity)
{
  signed __int64 v8; // rdx
  CAkVelocityDelayLine *v9; // rdi
  float *v10; // rax
  __int64 v12; // rbx
  float v13; // xmm0_4

  v8 = in_uDelayLineLength;
  this->m_fMinVelocity = in_fMinVelocity;
  v9 = this;
  if ( in_uDelayLineLength < 1 )
    v8 = 1i64;
  this->uDelayLineLength = v8;
  v10 = (float *)in_pAllocator->vfptr->Malloc(in_pAllocator, 4 * v8);
  v9->pfDelay = v10;
  if ( !v10 )
    return 52i64;
  v12 = 0i64;
  v9->uCurOffset = 0;
  v9->m_GustManager.m_fGustTarget = v9->m_GustManager.m_fGustCurrent;
  if ( v9->uDelayLineLength )
  {
    do
    {
      v13 = CAkGustManager::ComputeInstantVelocity(
              &v9->m_GustManager,
              in_fInitialVelocity,
              in_fInitialVariability,
              in_fInitialGustiness,
              in_fBufferTime);
      if ( v13 <= v9->m_fMinVelocity )
        v13 = v9->m_fMinVelocity;
      v9->pfDelay[v12] = v13;
      v12 = (unsigned int)(v12 + 1);
    }
    while ( (unsigned int)v12 < v9->uDelayLineLength );
  }
  return 1i64;
}

// File Line: 72
// RVA: 0xAD63D0
void __fastcall CAkVelocityDelayLine::Term(CAkVelocityDelayLine *this, AK::IAkPluginMemAlloc *in_pAllocator)
{
  CAkVelocityDelayLine *v2; // rbx

  v2 = this;
  if ( this->pfDelay )
  {
    ((void (__fastcall *)(AK::IAkPluginMemAlloc *))in_pAllocator->vfptr->Free)(in_pAllocator);
    v2->pfDelay = 0i64;
    v2->uDelayLineLength = 0;
  }
  else
  {
    this->uDelayLineLength = 0;
  }
}

