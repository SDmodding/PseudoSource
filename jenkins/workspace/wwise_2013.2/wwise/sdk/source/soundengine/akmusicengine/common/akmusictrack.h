// File Line: 67
// RVA: 0xAB37A0
signed __int64 __fastcall CAkClipAutomation::Set(CAkClipAutomation *this, unsigned int in_uClipIndex, AkClipAutomationType in_eAutoType, AkRTPCGraphPointBase<float> *in_arPoints, unsigned int in_uNumPoints)
{
  CAkConversionTable<AkRTPCGraphPointBase<float>,float> *v5; // rbx
  unsigned int v6; // er14
  unsigned int v7; // esi
  AkRTPCGraphPointBase<float> *v8; // rdx
  AkRTPCGraphPointBase<float> *v9; // r15
  AkClipAutomationType v10; // ebp
  CAkClipAutomation *v11; // rdi
  signed __int64 v12; // r9
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
  signed __int64 v24; // rcx
  __int64 v25; // r8
  double v26; // xmm1_8
  double v27; // xmm0_8

  v5 = &this->m_tableAutomation;
  v6 = in_uClipIndex;
  v7 = 0;
  v8 = this->m_tableAutomation.m_pArrayGraphPoints;
  v9 = in_arPoints;
  v10 = in_eAutoType;
  v11 = this;
  if ( v8 )
  {
    AK::MemoryMgr::Free(g_DefaultPoolId, v8);
    v5->m_pArrayGraphPoints = 0i64;
  }
  *(_QWORD *)&v5->m_ulArraySize = 0i64;
  v11->m_uClipIndex = v6;
  v11->m_eAutoType = v10;
  if ( in_uNumPoints
    && (unsigned int)CAkConversionTable<AkRTPCGraphPointBase<float>,float>::Set(v5, v9, in_uNumPoints, 0) == 1 )
  {
    v12 = 0i64;
    if ( (signed int)in_uNumPoints >= 4 )
    {
      v13 = 0i64;
      v14 = ((in_uNumPoints - 4) >> 2) + 1;
      v15 = v14;
      v7 = 4 * v14;
      v12 = 4i64 * v14;
      do
      {
        v16 = v5->m_pArrayGraphPoints[v13].From * (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
        if ( v16 <= 0.0 )
          v17 = DOUBLE_N0_5;
        else
          v17 = DOUBLE_0_5;
        v5->m_pArrayGraphPoints[v13].From = (float)(signed int)(v17 + v16);
        v18 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * v5->m_pArrayGraphPoints[v13 + 1].From;
        if ( v18 <= 0.0 )
          v19 = DOUBLE_N0_5;
        else
          v19 = DOUBLE_0_5;
        v5->m_pArrayGraphPoints[v13 + 1].From = (float)(signed int)(v19 + v18);
        v20 = v5->m_pArrayGraphPoints[v13 + 2].From * (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
        if ( v20 <= 0.0 )
          v21 = DOUBLE_N0_5;
        else
          v21 = DOUBLE_0_5;
        v5->m_pArrayGraphPoints[v13 + 2].From = (float)(signed int)(v21 + v20);
        v22 = v5->m_pArrayGraphPoints[v13 + 3].From * (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency;
        if ( v22 <= 0.0 )
          v23 = DOUBLE_N0_5;
        else
          v23 = DOUBLE_0_5;
        v13 += 4i64;
        v5->m_pArrayGraphPoints[v13 - 1].From = (float)(signed int)(v23 + v22);
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
        v26 = (double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency * v5->m_pArrayGraphPoints[v24].From;
        if ( v26 <= 0.0 )
          v27 = DOUBLE_N0_5;
        else
          v27 = DOUBLE_0_5;
        ++v24;
        v5->m_pArrayGraphPoints[v24 - 1].From = (float)(signed int)(v27 + v26);
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
  CAkClipAutomation *v1; // rax
  CAkMusicTrack::ClipAutomationArray *v2; // rsi
  signed __int64 v3; // rbx
  signed __int64 v4; // rdi

  v1 = this->m_pItems;
  v2 = this;
  if ( this->m_pItems )
  {
    v3 = (signed __int64)&v1[this->m_uLength];
    if ( v1 != (CAkClipAutomation *)v3 )
    {
      v4 = (signed __int64)&v1->m_tableAutomation;
      do
      {
        if ( *(_QWORD *)v4 )
        {
          AK::MemoryMgr::Free(g_DefaultPoolId, *(void **)v4);
          *(_QWORD *)v4 = 0i64;
        }
        *(_QWORD *)(v4 + 8) = 0i64;
        v4 += 24i64;
      }
      while ( v4 - 8 != v3 );
    }
    AK::MemoryMgr::Free(g_DefaultPoolId, v2->m_pItems);
    v2->m_pItems = 0i64;
    *(_QWORD *)&v2->m_uLength = 0i64;
  }
}

