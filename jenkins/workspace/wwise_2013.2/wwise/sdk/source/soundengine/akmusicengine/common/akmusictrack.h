// File Line: 67
// RVA: 0xAB37A0
__int64 __fastcall CAkClipAutomation::Set(
        CAkClipAutomation *this,
        unsigned int in_uClipIndex,
        AkClipAutomationType in_eAutoType,
        AkRTPCGraphPointBase<float> *in_arPoints,
        int in_uNumPoints)
{
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *p_m_tableAutomation; // rbx
  unsigned int v7; // esi
  AkRTPCGraphPointBase<float> *m_pArrayGraphPoints; // rdx
  __int64 v12; // r9
  __int64 v13; // rcx
  unsigned int v14; // eax
  __int64 v15; // r8
  double v16; // xmm1_8
  double v17; // xmm0_8
  double v18; // xmm1_8
  double v19; // xmm0_8
  double v20; // xmm1_8
  double v21; // xmm0_8
  double v22; // xmm1_8
  double v23; // xmm0_8
  __int64 v24; // rcx
  __int64 v25; // r8
  double v26; // xmm1_8
  double v27; // xmm0_8

  p_m_tableAutomation = &this->m_tableAutomation;
  v7 = 0;
  m_pArrayGraphPoints = this->m_tableAutomation.m_pArrayGraphPoints;
  if ( m_pArrayGraphPoints )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, m_pArrayGraphPoints);
    p_m_tableAutomation->m_pArrayGraphPoints = 0i64;
  }
  *(_QWORD *)&p_m_tableAutomation->m_ulArraySize = 0i64;
  this->m_uClipIndex = in_uClipIndex;
  this->m_eAutoType = in_eAutoType;
  if ( in_uNumPoints
    && (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(
                       p_m_tableAutomation,
                       in_arPoints,
                       in_uNumPoints,
                       AkCurveScaling_None) == 1 )
  {
    v12 = 0i64;
    if ( in_uNumPoints >= 4 )
    {
      v13 = 0i64;
      v14 = ((unsigned int)(in_uNumPoints - 4) >> 2) + 1;
      v15 = v14;
      v7 = 4 * v14;
      v12 = 4i64 * v14;
      do
      {
        v16 = p_m_tableAutomation->m_pArrayGraphPoints[v13].From
            * (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
        if ( v16 <= 0.0 )
          v17 = DOUBLE_N0_5;
        else
          v17 = DOUBLE_0_5;
        p_m_tableAutomation->m_pArrayGraphPoints[v13].From = (float)(int)(v17 + v16);
        v18 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency
            * p_m_tableAutomation->m_pArrayGraphPoints[v13 + 1].From;
        if ( v18 <= 0.0 )
          v19 = DOUBLE_N0_5;
        else
          v19 = DOUBLE_0_5;
        p_m_tableAutomation->m_pArrayGraphPoints[v13 + 1].From = (float)(int)(v19 + v18);
        v20 = p_m_tableAutomation->m_pArrayGraphPoints[v13 + 2].From
            * (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
        if ( v20 <= 0.0 )
          v21 = DOUBLE_N0_5;
        else
          v21 = DOUBLE_0_5;
        p_m_tableAutomation->m_pArrayGraphPoints[v13 + 2].From = (float)(int)(v21 + v20);
        v22 = p_m_tableAutomation->m_pArrayGraphPoints[v13 + 3].From
            * (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency;
        if ( v22 <= 0.0 )
          v23 = DOUBLE_N0_5;
        else
          v23 = DOUBLE_0_5;
        v13 += 4i64;
        p_m_tableAutomation->m_pArrayGraphPoints[v13 - 1].From = (float)(int)(v23 + v22);
        --v15;
      }
      while ( v15 );
    }
    if ( v7 < in_uNumPoints )
    {
      v24 = v12;
      v25 = in_uNumPoints - v7;
      do
      {
        v26 = (double)(int)AkAudioLibSettings::g_pipelineCoreFrequency
            * p_m_tableAutomation->m_pArrayGraphPoints[v24].From;
        if ( v26 <= 0.0 )
          v27 = DOUBLE_N0_5;
        else
          v27 = DOUBLE_0_5;
        p_m_tableAutomation->m_pArrayGraphPoints[v24++].From = (float)(int)(v27 + v26);
        --v25;
      }
      while ( v25 );
    }
  }
  return 1i64;
}

// File Line: 276
// RVA: 0xAB4020
void __fastcall CAkMusicTrack::ClipAutomationArray::Term(CAkMusicTrack::ClipAutomationArray *this)
{
  CAkClipAutomation *m_pItems; // rax
  CAkClipAutomation *v3; // rbx
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *p_m_tableAutomation; // rdi

  m_pItems = this->m_pItems;
  if ( this->m_pItems )
  {
    v3 = &m_pItems[this->m_uLength];
    if ( m_pItems != v3 )
    {
      p_m_tableAutomation = &m_pItems->m_tableAutomation;
      do
      {
        if ( p_m_tableAutomation->m_pArrayGraphPoints )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, p_m_tableAutomation->m_pArrayGraphPoints);
          p_m_tableAutomation->m_pArrayGraphPoints = 0i64;
        }
        *(_QWORD *)&p_m_tableAutomation->m_ulArraySize = 0i64;
        p_m_tableAutomation = (CAkConversionTable<AkRTPCGraphPointBase<float>,float> *)((char *)p_m_tableAutomation + 24);
      }
      while ( &p_m_tableAutomation[-1].m_ulArraySize != (unsigned int *)v3 );
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, this->m_pItems);
    this->m_pItems = 0i64;
    *(_QWORD *)&this->m_uLength = 0i64;
  }
}

