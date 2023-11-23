// File Line: 50
// RVA: 0x15BE0D0
__int64 dynamic_initializer_for__CAkSinkXAudio2::s_XAudio2List__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__CAkSinkXAudio2::s_XAudio2List__);
}

// File Line: 66
// RVA: 0xA94960
void __fastcall CAkSinkXAudio2::CAkSinkXAudio2(CAkSinkXAudio2 *this)
{
  CAkSink::CAkSink(this, AkSink_Main_XAudio2);
  this->CAkSink::vfptr = (CAkSinkVtbl *)&CAkSinkXAudio2::`vftable{for `CAkSink};
  this->IXAudio2EngineCallback::vfptr = (IXAudio2EngineCallbackVtbl *)&CAkSinkXAudio2::`vftable{for `IXAudio2EngineCallback};
  this->IXAudio2VoiceCallback::vfptr = (IXAudio2VoiceCallbackVtbl *)&CAkSinkXAudio2::`vftable{for `IXAudio2VoiceCallback};
  this->pNextLightItem = 0i64;
  this->m_ulNumChannels = 0;
  this->m_pXAudio2 = 0i64;
  this->m_pMasteringVoice = 0i64;
  this->m_pSourceVoice = 0i64;
  this->m_pvAudioBuffer = 0i64;
  *(_DWORD *)&this->m_uWriteBufferIndex = 0;
  *(_DWORD *)&this->m_usBlockAlign = 0;
  this->m_uNbBuffersRB = 0;
  this->m_ppvRingBuffer[0] = 0i64;
  this->m_ppvRingBuffer[1] = 0i64;
  this->m_ppvRingBuffer[2] = 0i64;
  this->m_ppvRingBuffer[3] = 0i64;
  this->m_ppvRingBuffer[4] = 0i64;
  this->m_ppvRingBuffer[5] = 0i64;
  this->m_ppvRingBuffer[6] = 0i64;
  this->m_ppvRingBuffer[7] = 0i64;
}

// File Line: 76
// RVA: 0xA94A40
__int64 __fastcall CAkSinkXAudio2::Init(
        CAkSinkXAudio2 *this,
        AkPlatformInitSettings *in_settings,
        __int64 in_uChannelMask,
        __int64 in_eType)
{
  IXAudio2 *pXAudio2; // rcx
  unsigned int v6; // esi
  IXAudio2 **p_m_pXAudio2; // rdi
  unsigned int v9; // eax
  unsigned int m_SpeakersConfig; // ecx
  unsigned int i; // edx
  unsigned int v12; // eax
  int v13; // esi
  unsigned int v14; // esi
  void *v15; // rax
  char *v16; // rcx
  unsigned int v17; // eax
  IXAudio2 *v18; // rcx
  __int64 v19; // rdx
  __int64 v20; // rax
  unsigned __int64 *p_uDeviceID; // rcx
  AkDevice *v22; // rcx
  CAkSink *pSink; // rdx
  volatile int v24; // edi
  volatile int pData; // eax
  __int16 v26; // [rsp+40h] [rbp-478h] BYREF
  __int16 m_ulNumChannels; // [rsp+42h] [rbp-476h]
  unsigned int v28; // [rsp+44h] [rbp-474h]
  unsigned int v29; // [rsp+48h] [rbp-470h]
  __int16 v30; // [rsp+4Ch] [rbp-46Ch]
  __int16 v31; // [rsp+4Eh] [rbp-46Ah]
  int v32; // [rsp+50h] [rbp-468h]
  unsigned int v33; // [rsp+54h] [rbp-464h]
  GUID v34; // [rsp+58h] [rbp-460h]
  char v35[1030]; // [rsp+70h] [rbp-448h] BYREF
  unsigned __int16 v36; // [rsp+476h] [rbp-42h]

  pXAudio2 = in_settings->pXAudio2;
  v6 = in_uChannelMask;
  p_m_pXAudio2 = &this->m_pXAudio2;
  if ( pXAudio2 )
  {
    *p_m_pXAudio2 = pXAudio2;
    ((void (__fastcall *)(IXAudio2 *, AkPlatformInitSettings *, __int64, __int64))pXAudio2->vfptr->AddRef)(
      pXAudio2,
      in_settings,
      in_uChannelMask,
      in_eType);
  }
  else if ( XAudio2Create(&this->m_pXAudio2, 0, XAUDIO2_ANY_PROCESSOR) )
  {
    return 2i64;
  }
  if ( ((int (__fastcall *)(IXAudio2 *, IXAudio2MasteringVoice **, _QWORD, _QWORD, _DWORD, _DWORD, _QWORD))(*p_m_pXAudio2)->vfptr[3].AddRef)(
         *p_m_pXAudio2,
         &this->m_pMasteringVoice,
         0i64,
         AkAudioLibSettings::g_pipelineCoreFrequency,
         0,
         0,
         0i64) < 0 )
    return 2i64;
  ((void (__fastcall *)(IXAudio2 *, IXAudio2EngineCallback *))(*p_m_pXAudio2)->vfptr[2].QueryInterface)(
    *p_m_pXAudio2,
    &this->IXAudio2EngineCallback);
  this->m_SpeakersConfig = v6;
  if ( !v6 )
  {
    if ( ((int (__fastcall *)(IXAudio2 *, _QWORD, char *))(*p_m_pXAudio2)->vfptr[1].AddRef)(*p_m_pXAudio2, 0i64, v35) < 0 )
      return 2i64;
    if ( v36 < 7u )
    {
      v9 = 3;
      if ( v36 >= 4u )
        v9 = 63;
      this->m_SpeakersConfig = v9;
    }
    else
    {
      this->m_SpeakersConfig = 1599;
    }
  }
  m_SpeakersConfig = this->m_SpeakersConfig;
  for ( i = 0; m_SpeakersConfig; m_SpeakersConfig &= m_SpeakersConfig - 1 )
    ++i;
  this->m_ulNumChannels = i;
  if ( (unsigned int)CAkSink::AllocBuffer(this) != 1 )
    return 2i64;
  v12 = this->m_SpeakersConfig;
  if ( v12 != 3 && v12 != 63 && v12 != 1599 )
    return 2i64;
  v13 = (unsigned __int16)(4 * LOWORD(this->m_ulNumChannels));
  this->m_usBlockAlign = v13;
  v14 = v13 << 10;
  v15 = AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 8 * v14);
  this->m_pvAudioBuffer = v15;
  if ( !v15 )
    return 2i64;
  memset(v15, 0, 8 * v14);
  this->m_ppvRingBuffer[0] = this->m_pvAudioBuffer;
  this->m_ppvRingBuffer[1] = (char *)this->m_pvAudioBuffer + v14;
  this->m_ppvRingBuffer[2] = (char *)this->m_pvAudioBuffer + 2 * v14;
  v31 = 32;
  v16 = (char *)this->m_pvAudioBuffer + 3 * v14;
  v32 = 2097174;
  this->m_ppvRingBuffer[3] = v16;
  this->m_ppvRingBuffer[4] = (char *)this->m_pvAudioBuffer + 4 * v14;
  this->m_ppvRingBuffer[5] = (char *)this->m_pvAudioBuffer + 5 * v14;
  this->m_ppvRingBuffer[6] = (char *)this->m_pvAudioBuffer + 6 * v14;
  this->m_ppvRingBuffer[7] = (char *)this->m_pvAudioBuffer + 7 * v14;
  v17 = this->m_SpeakersConfig;
  v26 = -2;
  v33 = v17;
  v34 = GUID_00000003_0000_0010_8000_00aa00389b71;
  v28 = AkAudioLibSettings::g_pipelineCoreFrequency;
  m_ulNumChannels = this->m_ulNumChannels;
  v30 = 4 * m_ulNumChannels;
  v18 = *p_m_pXAudio2;
  v29 = AkAudioLibSettings::g_pipelineCoreFrequency * (unsigned __int16)(4 * m_ulNumChannels);
  if ( ((int (__fastcall *)(IXAudio2 *, IXAudio2SourceVoice **, __int16 *, _QWORD, _DWORD, IXAudio2VoiceCallback *, _QWORD, _QWORD))v18->vfptr[2].Release)(
         v18,
         &this->m_pSourceVoice,
         &v26,
         0i64,
         (_DWORD)FLOAT_1_0,
         &this->IXAudio2VoiceCallback,
         0i64,
         0i64) < 0 )
    return 2i64;
  ((void (__fastcall *)(IXAudio2SourceVoice *, __int64, _QWORD))this->m_pSourceVoice->vfptr->SetVolume)(
    this->m_pSourceVoice,
    v19,
    0i64);
  v20 = 0i64;
  if ( CAkOutputMgr::m_Devices.m_uLength )
  {
    p_uDeviceID = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
    while ( *p_uDeviceID )
    {
      v20 = (unsigned int)(v20 + 1);
      p_uDeviceID += 10;
      if ( (unsigned int)v20 >= CAkOutputMgr::m_Devices.m_uLength )
        goto LABEL_34;
    }
    v22 = &CAkOutputMgr::m_Devices.m_pItems[v20];
    if ( v22 )
    {
      pSink = v22->pSink;
      if ( pSink )
      {
        if ( pSink->m_eType == AkSink_Main_XAudio2 )
        {
          v24 = 0;
          this->m_uWriteBufferIndex = (unsigned __int16)pSink[2].m_pCapture;
          pData = (volatile int)pSink[3].m_MasterOut.pData;
          this->m_uReadBufferIndex = 0;
          this->m_uNbBuffersRB = pData;
          if ( this->m_uNbBuffersRB > 0 )
          {
            do
            {
              CAkSinkXAudio2::SubmitPacketRB(this);
              ++v24;
            }
            while ( v24 < this->m_uNbBuffersRB );
          }
        }
      }
    }
  }
LABEL_34:
  if ( CAkSinkXAudio2::s_XAudio2List.m_pFirst )
  {
    this->pNextLightItem = CAkSinkXAudio2::s_XAudio2List.m_pFirst;
    CAkSinkXAudio2::s_XAudio2List.m_pFirst = this;
  }
  else
  {
    CAkSinkXAudio2::s_XAudio2List.m_pFirst = this;
    this->pNextLightItem = 0i64;
  }
  return 1i64;
}

// File Line: 232
// RVA: 0xA952D0
void __fastcall CAkSinkXAudio2::Term(CAkSinkXAudio2 *this)
{
  void *pData; // rdx
  CAkSinkXAudio2 *v3; // rdi
  IXAudio2MasteringVoice *m_pMasteringVoice; // rcx
  IXAudio2 *m_pXAudio2; // rcx
  void *m_pvAudioBuffer; // rdx
  CAkSinkXAudio2 *m_pFirst; // rcx

  (*(void (__fastcall **)(CAkSinkXAudio2 *))this->CAkSink::vfptr[1].gap8)(this);
  pData = this->m_MasterOut.pData;
  v3 = 0i64;
  if ( pData )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, pData);
    this->m_MasterOut.pData = 0i64;
  }
  m_pMasteringVoice = this->m_pMasteringVoice;
  if ( m_pMasteringVoice )
  {
    m_pMasteringVoice->vfptr->DestroyVoice(m_pMasteringVoice);
    this->m_pMasteringVoice = 0i64;
  }
  m_pXAudio2 = this->m_pXAudio2;
  if ( m_pXAudio2 )
  {
    ((void (__fastcall *)(IXAudio2 *, IXAudio2EngineCallback *))m_pXAudio2->vfptr[2].AddRef)(
      m_pXAudio2,
      &this->IXAudio2EngineCallback);
    this->m_pXAudio2->vfptr->Release(this->m_pXAudio2);
    this->m_pXAudio2 = 0i64;
  }
  m_pvAudioBuffer = this->m_pvAudioBuffer;
  if ( m_pvAudioBuffer )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, m_pvAudioBuffer);
    this->m_pvAudioBuffer = 0i64;
  }
  CAkSink::StopOutputCapture(this);
  _((AMD_HD3D *)this);
  m_pFirst = CAkSinkXAudio2::s_XAudio2List.m_pFirst;
  if ( CAkSinkXAudio2::s_XAudio2List.m_pFirst )
  {
    while ( m_pFirst != this )
    {
      v3 = m_pFirst;
      m_pFirst = m_pFirst->pNextLightItem;
      if ( !m_pFirst )
        return;
    }
    if ( m_pFirst )
    {
      if ( m_pFirst == CAkSinkXAudio2::s_XAudio2List.m_pFirst )
        CAkSinkXAudio2::s_XAudio2List.m_pFirst = m_pFirst->pNextLightItem;
      else
        v3->pNextLightItem = m_pFirst->pNextLightItem;
    }
  }
}

// File Line: 269
// RVA: 0xA95190
__int64 __fastcall CAkSinkXAudio2::Play(CAkSinkXAudio2 *this)
{
  return (unsigned int)(((int (__fastcall *)(IXAudio2SourceVoice *, _QWORD, _QWORD))this->m_pSourceVoice->vfptr[1].GetVoiceDetails)(
                          this->m_pSourceVoice,
                          0i64,
                          0i64) < 0)
       + 1;
}

// File Line: 275
// RVA: 0xA951D0
void __fastcall CAkSinkXAudio2::Stop(CAkSinkXAudio2 *this)
{
  IXAudio2SourceVoice *m_pSourceVoice; // rcx

  m_pSourceVoice = this->m_pSourceVoice;
  if ( m_pSourceVoice )
  {
    m_pSourceVoice->vfptr->DestroyVoice(m_pSourceVoice);
    this->m_pSourceVoice = 0i64;
  }
  *(_DWORD *)&this->m_uWriteBufferIndex = 0;
  this->m_uNbBuffersRB = 0;
  this->m_ppvRingBuffer[0] = 0i64;
  this->m_ppvRingBuffer[1] = 0i64;
  this->m_ppvRingBuffer[2] = 0i64;
  this->m_ppvRingBuffer[3] = 0i64;
  this->m_ppvRingBuffer[4] = 0i64;
  this->m_ppvRingBuffer[5] = 0i64;
  this->m_ppvRingBuffer[6] = 0i64;
  this->m_ppvRingBuffer[7] = 0i64;
}

// File Line: 296
// RVA: 0xA94E40
_BOOL8 __fastcall CAkSinkXAudio2::IsStarved(CAkSinkXAudio2 *this)
{
  return this->m_bStarved;
}

// File Line: 301
// RVA: 0xA951C0
void __fastcall CAkSinkXAudio2::ResetStarved(CAkSinkXAudio2 *this)
{
  this->m_bStarved = 0;
}

// File Line: 311
// RVA: 0xA95250
void __fastcall CAkSinkXAudio2::SubmitPacketRB(CAkSinkXAudio2 *this)
{
  __int64 m_uReadBufferIndex; // rdx
  void *v2; // rax
  __int64 v3[7]; // [rsp+20h] [rbp-38h] BYREF

  memset(v3, 0, 44);
  m_uReadBufferIndex = this->m_uReadBufferIndex;
  HIDWORD(v3[0]) = this->m_usBlockAlign << 10;
  v2 = this->m_ppvRingBuffer[m_uReadBufferIndex];
  LOWORD(m_uReadBufferIndex) = m_uReadBufferIndex + 1;
  this->m_uReadBufferIndex = m_uReadBufferIndex;
  v3[1] = (__int64)v2;
  if ( (_WORD)m_uReadBufferIndex == 8 )
    this->m_uReadBufferIndex = 0;
  (*(void (__fastcall **)(IXAudio2SourceVoice *, __int64 *, _QWORD))&this->m_pSourceVoice->vfptr[1].gap8[8])(
    this->m_pSourceVoice,
    v3,
    0i64);
}

// File Line: 350
// RVA: 0xA94F90
__int64 __fastcall CAkSinkXAudio2::PassData(CAkSinkXAudio2 *this)
{
  signed int v1; // r9d
  __m128 *v2; // r8
  __m128 *pData; // rax
  __m128 *v5; // rdx
  signed __int64 v6; // rcx
  unsigned __int64 v7; // rcx
  signed __int64 v8; // rcx
  void *v9; // rsp
  void *v10; // rsp
  unsigned __int64 v11; // r11
  char *p_in_pData; // r10
  __m128 *v13; // rcx
  __m128 v14; // xmm4
  __m128 v15; // xmm3
  __m128i v16; // xmm2
  __m128i v17; // xmm0
  char in_pData; // [rsp+20h] [rbp+0h] BYREF

  v1 = this->m_ulNumChannels * this->m_MasterOut.uValidFrames;
  v2 = (__m128 *)this->m_ppvRingBuffer[this->m_uWriteBufferIndex];
  pData = (__m128 *)this->m_MasterOut.pData;
  v5 = (__m128 *)((char *)pData + 4 * v1);
  if ( pData < v5 )
  {
    v6 = (char *)v2 - (char *)pData;
    do
    {
      ++pData;
      *(__m128 *)((char *)pData + v6 - 16) = _mm_max_ps(vkMin, _mm_min_ps(vkMax, pData[-1]));
    }
    while ( pData < v5 );
  }
  if ( this->m_pCapture )
  {
    v7 = 2i64 * v1 + 15;
    if ( v7 <= 2i64 * v1 )
      v7 = 0xFFFFFFFFFFFFFF0i64;
    v8 = v7 & 0xFFFFFFFFFFFFFFF0ui64;
    v9 = alloca(v8);
    v10 = alloca(v8);
    v11 = (unsigned __int64)v2->m128_u64 + 4 * v1;
    p_in_pData = &in_pData;
    if ( (unsigned __int64)v2 < v11 )
    {
      v13 = v2 + 3;
      do
      {
        p_in_pData += 32;
        v14 = _mm_mul_ps(v13[-1], (__m128)_xmm);
        v15 = *v13;
        v16 = _mm_cvtps_epi32(_mm_mul_ps(v13[-3], (__m128)_xmm));
        v17 = _mm_cvtps_epi32(_mm_mul_ps(v13[-2], (__m128)_xmm));
        v13 += 4;
        *((__m128i *)p_in_pData - 2) = _mm_packs_epi32(v16, v17);
        *((__m128i *)p_in_pData - 1) = _mm_packs_epi32(
                                         _mm_cvtps_epi32(v14),
                                         _mm_cvtps_epi32(_mm_mul_ps(v15, (__m128)_xmm)));
      }
      while ( (unsigned __int64)&v13[-3] < v11 );
    }
    AkCaptureFile::PassSampleData(this->m_pCapture, &in_pData, 2 * v1);
  }
  if ( ++this->m_uWriteBufferIndex == 8 )
    this->m_uWriteBufferIndex = 0;
  _InterlockedIncrement(&this->m_uNbBuffersRB);
  return 1i64;
}

// File Line: 404
// RVA: 0xA950E0
__int64 __fastcall CAkSinkXAudio2::PassSilence(CAkSinkXAudio2 *this)
{
  char *v2; // r9
  char *v3; // rcx
  AkCaptureFile *m_pCapture; // rcx

  v2 = (char *)this->m_ppvRingBuffer[this->m_uWriteBufferIndex];
  v3 = &v2[4 * (this->m_ulNumChannels << 10)];
  if ( v2 < v3 )
  {
    *(_OWORD *)v2 = 0i64;
    qmemcpy(v2 + 16, v2, 8 * (((unsigned __int64)(v3 - v2 - 1) >> 3) & 0x1FFFFFFFFFFFFFFEi64));
  }
  m_pCapture = this->m_pCapture;
  if ( m_pCapture )
    AkCaptureFile::PassSampleData(m_pCapture, v2, (this->m_usBlockAlign << 10) / 2);
  if ( ++this->m_uWriteBufferIndex == 8 )
    this->m_uWriteBufferIndex = 0;
  _InterlockedIncrement(&this->m_uNbBuffersRB);
  return 1i64;
}

// File Line: 452
// RVA: 0xA94DC0
__int64 __fastcall CAkSinkXAudio2::IsDataNeeded(CAkSinkXAudio2 *this, unsigned int *out_uBuffersNeeded)
{
  CAkSinkXAudio2 *i; // rax
  unsigned int v3; // r10d

  *out_uBuffersNeeded = 1000;
  for ( i = CAkSinkXAudio2::s_XAudio2List.m_pFirst; i; i = i->pNextLightItem )
  {
    v3 = *out_uBuffersNeeded;
    if ( *out_uBuffersNeeded >= (unsigned __int16)(g_PDSettings.uNumRefillsInVoice - i->m_uNbBuffersRB) )
      v3 = (unsigned __int16)(g_PDSettings.uNumRefillsInVoice - i->m_uNbBuffersRB);
    *out_uBuffersNeeded = v3;
  }
  return (unsigned int)this->m_bCriticalError + 1;
}

// File Line: 477
// RVA: 0xA94E70
void __fastcall CAkSinkXAudio2::OnCriticalError(CAkSinkXAudio2 *this, HRESULT Error)
{
  HIBYTE(this->m_ppvRingBuffer[1]) = 1;
  CAkAudioThread::WakeupEventsConsumer(&g_pAudioMgr->m_audioThread);
}

// File Line: 488
// RVA: 0xA94E90
void __fastcall CAkSinkXAudio2::OnVoiceProcessingPassStart(CAkSinkXAudio2 *this, unsigned int BytesRequired)
{
  unsigned int i; // ecx
  __int64 v4; // rcx
  __int64 v5; // rax
  char v6[8]; // [rsp+20h] [rbp-58h] BYREF
  unsigned int v7; // [rsp+28h] [rbp-50h]
  __int64 v8; // [rsp+2Ch] [rbp-4Ch]
  __int64 v9[8]; // [rsp+38h] [rbp-40h] BYREF

  (*(void (__fastcall **)(_QWORD, char *))(**(_QWORD **)&this->m_MasterOut.uMaxFrames + 200i64))(
    *(_QWORD *)&this->m_MasterOut.uMaxFrames,
    v6);
  if ( v7 < g_PDSettings.uNumRefillsInVoice )
  {
    if ( !v7 && v8 )
      BYTE6(this->m_ppvRingBuffer[0]) = 1;
    for ( i = v7; LODWORD(this->m_ppvRingBuffer[0]) != v7; i = v7 )
    {
      memset(v9, 0, 44);
      v4 = WORD1(this->IXAudio2EngineCallback::vfptr);
      HIDWORD(v9[0]) = WORD2(this->m_ppvRingBuffer[0]) << 10;
      v5 = *((_QWORD *)&this->IXAudio2VoiceCallback::vfptr + v4);
      LOWORD(v4) = v4 + 1;
      WORD1(this->IXAudio2EngineCallback::vfptr) = v4;
      v9[1] = v5;
      if ( (_WORD)v4 == 8 )
        WORD1(this->IXAudio2EngineCallback::vfptr) = 0;
      (*(void (__fastcall **)(_QWORD, __int64 *, _QWORD))(**(_QWORD **)&this->m_MasterOut.uMaxFrames + 168i64))(
        *(_QWORD *)&this->m_MasterOut.uMaxFrames,
        v9,
        0i64);
      ++v7;
    }
    if ( i < g_PDSettings.uNumRefillsInVoice )
      CAkAudioThread::WakeupEventsConsumer(&g_pAudioMgr->m_audioThread);
  }
}

// File Line: 532
// RVA: 0xA94E50
void __fastcall CAkSinkXAudio2::OnBufferEnd(CAkSinkXAudio2 *this, void *pBufferContext)
{
  _InterlockedDecrement((volatile signed __int32 *)this->m_ppvRingBuffer);
  CAkAudioThread::WakeupEventsConsumer(&g_pAudioMgr->m_audioThread);
}

