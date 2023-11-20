// File Line: 69
// RVA: 0xA440D0
UserParams *__fastcall UserParams::operator=(UserParams *this, UserParams *in_rCopy)
{
  UserParams *v2; // rbx
  AkExternalSourceArray *v3; // rcx
  AkExternalSourceArray *v4; // rdi
  UserParams *result; // rax

  v2 = this;
  this->m_PlayingID = in_rCopy->m_PlayingID;
  this->m_CustomParam.customParam = in_rCopy->m_CustomParam.customParam;
  this->m_CustomParam.ui32Reserved = in_rCopy->m_CustomParam.ui32Reserved;
  v3 = this->m_CustomParam.pExternalSrcs;
  v4 = in_rCopy->m_CustomParam.pExternalSrcs;
  if ( v3 )
    AkExternalSourceArray::Release(v3);
  result = v2;
  if ( v4 )
    ++v4->m_cRefCount;
  v2->m_CustomParam.pExternalSrcs = v4;
  return result;
}

// File Line: 226
// RVA: 0xA75710
__int64 __fastcall AkTimeConv::MillisecondsToSamples(long double in_milliseconds)
{
  double v1; // xmm1_8
  __int64 result; // rax

  v1 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * in_milliseconds * 0.001;
  if ( v1 <= 0.0 )
    result = (unsigned int)(signed int)(v1 + -0.5);
  else
    result = (unsigned int)(signed int)(v1 + 0.5);
  return result;
}

// File Line: 246
// RVA: 0xA6E3F0
__int64 __fastcall AkTimeConv::SecondsToSamples(long double in_seconds)
{
  double v1; // xmm1_8
  __int64 result; // rax

  v1 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * in_seconds;
  if ( v1 <= 0.0 )
    result = (unsigned int)(signed int)(v1 + -0.5);
  else
    result = (unsigned int)(signed int)(v1 + 0.5);
  return result;
}

// File Line: 252
// RVA: 0xAB8EE0
__int64 __fastcall AkTimeConv::SamplesToMilliseconds(int in_samples)
{
  double v1; // xmm1_8
  __int64 result; // rax

  v1 = (double)in_samples * 1000.0 / (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
  if ( v1 <= 0.0 )
    result = (unsigned int)(signed int)(v1 + -0.5);
  else
    result = (unsigned int)(signed int)(v1 + 0.5);
  return result;
}

