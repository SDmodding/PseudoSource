// File Line: 69
// RVA: 0xA440D0
UserParams *__fastcall UserParams::operator=(UserParams *this, UserParams *in_rCopy)
{
  AkExternalSourceArray *pExternalSrcs; // rcx
  AkExternalSourceArray *v4; // rdi
  UserParams *result; // rax

  this->m_PlayingID = in_rCopy->m_PlayingID;
  this->m_CustomParam.customParam = in_rCopy->m_CustomParam.customParam;
  this->m_CustomParam.ui32Reserved = in_rCopy->m_CustomParam.ui32Reserved;
  pExternalSrcs = this->m_CustomParam.pExternalSrcs;
  v4 = in_rCopy->m_CustomParam.pExternalSrcs;
  if ( pExternalSrcs )
    AkExternalSourceArray::Release(pExternalSrcs);
  result = this;
  if ( v4 )
    ++v4->m_cRefCount;
  this->m_CustomParam.pExternalSrcs = v4;
  return result;
}

// File Line: 226
// RVA: 0xA75710
__int64 __fastcall AkTimeConv::MillisecondsToSamples(long double in_milliseconds)
{
  double v1; // xmm1_8

  v1 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * in_milliseconds * 0.001;
  if ( v1 <= 0.0 )
    return (unsigned int)(int)(v1 + -0.5);
  else
    return (unsigned int)(int)(v1 + 0.5);
}

// File Line: 246
// RVA: 0xA6E3F0
__int64 __fastcall AkTimeConv::SecondsToSamples(long double in_seconds)
{
  double v1; // xmm1_8

  v1 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * in_seconds;
  if ( v1 <= 0.0 )
    return (unsigned int)(int)(v1 + -0.5);
  else
    return (unsigned int)(int)(v1 + 0.5);
}

// File Line: 252
// RVA: 0xAB8EE0
__int64 __fastcall AkTimeConv::SamplesToMilliseconds(int in_samples)
{
  double v1; // xmm1_8

  v1 = (double)in_samples * 1000.0 / (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
  if ( v1 <= 0.0 )
    return (unsigned int)(int)(v1 + -0.5);
  else
    return (unsigned int)(int)(v1 + 0.5);
}

