// File Line: 50
// RVA: 0x15BE0D0
__int64 dynamic_initializer_for__CAkSinkXAudio2::s_XAudio2List__()
{
  return atexit(dynamic_atexit_destructor_for__CAkSinkXAudio2::s_XAudio2List__);
}

// File Line: 66
// RVA: 0xA94960
void __fastcall CAkSinkXAudio2::CAkSinkXAudio2(CAkSinkXAudio2 *this)
{
  CAkSinkXAudio2 *v1; // rbx

  v1 = this;
  CAkSink::CAkSink((CAkSink *)&this->vfptr, AkSink_Main_XAudio2);
  v1->vfptr = (CAkSinkVtbl *)&CAkSinkXAudio2::`vftable'{for `CAkSink'};
  v1->vfptr = (IXAudio2EngineCallbackVtbl *)&CAkSinkXAudio2::`vftable'{for `IXAudio2EngineCallback'};
  v1->vfptr = (IXAudio2VoiceCallbackVtbl *)&CAkSinkXAudio2::`vftable'{for `IXAudio2VoiceCallback'};
  v1->pNextLightItem = 0i64;
  v1->m_ulNumChannels = 0;
  v1->m_pXAudio2 = 0i64;
  v1->m_pMasteringVoice = 0i64;
  v1->m_pSourceVoice = 0i64;
  v1->m_pvAudioBuffer = 0i64;
  *(_DWORD *)&v1->m_uWriteBufferIndex = 0;
  *(_DWORD *)&v1->m_usBlockAlign = 0;
  v1->m_uNbBuffersRB = 0;
  v1->m_ppvRingBuffer[0] = 0i64;
  v1->m_ppvRingBuffer[1] = 0i64;
  v1->m_ppvRingBuffer[2] = 0i64;
  v1->m_ppvRingBuffer[3] = 0i64;
  v1->m_ppvRingBuffer[4] = 0i64;
  v1->m_ppvRingBuffer[5] = 0i64;
  v1->m_ppvRingBuffer[6] = 0i64;
  v1->m_ppvRingBuffer[7] = 0i64;
}

// File Line: 76
// RVA: 0xA94A40
signed __int64 __fastcall CAkSinkXAudio2::Init(CAkSinkXAudio2 *this, AkPlatformInitSettings *in_settings, __int64 in_uChannelMask, __int64 in_eType)
{
  CAkSinkXAudio2 *v4; // rbx
  IXAudio2 *v5; // rcx
  unsigned int v6; // esi
  IXAudio2 **v7; // rdi
  signed int v9; // eax
  unsigned int v10; // ecx
  unsigned int i; // edx
  unsigned int v12; // eax
  int v13; // esi
  unsigned int v14; // esi
  void *v15; // rax
  char *v16; // rcx
  int v17; // eax
  IXAudio2 *v18; // rcx
  __int64 v19; // rdx
  __int64 v20; // rax
  unsigned __int64 *v21; // rcx
  AkDevice *v22; // rcx
  CAkSink *v23; // rdx
  volatile int v24; // edi
  volatile int v25; // eax
  __int64 v26; // [rsp+20h] [rbp-498h]
  __int16 v27; // [rsp+40h] [rbp-478h]
  __int16 v28; // [rsp+42h] [rbp-476h]
  unsigned int v29; // [rsp+44h] [rbp-474h]
  unsigned int v30; // [rsp+48h] [rbp-470h]
  __int16 v31; // [rsp+4Ch] [rbp-46Ch]
  __int16 v32; // [rsp+4Eh] [rbp-46Ah]
  int v33; // [rsp+50h] [rbp-468h]
  int v34; // [rsp+54h] [rbp-464h]
  GUID v35; // [rsp+58h] [rbp-460h]
  char v36; // [rsp+70h] [rbp-448h]
  unsigned __int16 v37; // [rsp+476h] [rbp-42h]

  v4 = this;
  v5 = in_settings->pXAudio2;
  v6 = in_uChannelMask;
  v7 = &v4->m_pXAudio2;
  if ( v5 )
  {
    *v7 = v5;
    ((void (__fastcall *)(IXAudio2 *, AkPlatformInitSettings *, __int64, __int64))v5->vfptr->AddRef)(
      v5,
      in_settings,
      in_uChannelMask,
      in_eType);
  }
  else if ( XAudio2Create(&v4->m_pXAudio2, 0, XAUDIO2_ANY_PROCESSOR) )
  {
    return 2i64;
  }
  if ( ((signed int (__fastcall *)(IXAudio2 *, IXAudio2MasteringVoice **, _QWORD, _QWORD, _DWORD, _DWORD, _QWORD))(*v7)->vfptr[3].AddRef)(
         *v7,
         &v4->m_pMasteringVoice,
         0i64,
         AkAudioLibSettings::g_pipelineCoreFrequency,
         0,
         0,
         0i64) < 0 )
    return 2i64;
  ((void (__fastcall *)(IXAudio2 *, IXAudio2EngineCallbackVtbl **))(*v7)->vfptr[2].QueryInterface)(*v7, &v4->vfptr);
  v4->m_SpeakersConfig = v6;
  if ( !v6 )
  {
    if ( ((signed int (__fastcall *)(IXAudio2 *, _QWORD, char *))(*v7)->vfptr[1].AddRef)(*v7, 0i64, &v36) < 0 )
      return 2i64;
    if ( v37 < 7u )
    {
      v9 = 3;
      if ( v37 >= 4u )
        v9 = 63;
      v4->m_SpeakersConfig = v9;
    }
    else
    {
      v4->m_SpeakersConfig = 1599;
    }
  }
  v10 = v4->m_SpeakersConfig;
  for ( i = 0; v10; v10 &= v10 - 1 )
    ++i;
  v4->m_ulNumChannels = i;
  if ( (unsigned int)CAkSink::AllocBuffer((CAkSink *)&v4->vfptr) != 1 )
    return 2i64;
  v12 = v4->m_SpeakersConfig;
  if ( v12 != 3 && v12 != 63 && v12 != 1599 )
    return 2i64;
  v13 = (unsigned __int16)(4 * LOWORD(v4->m_ulNumChannels));
  v4->m_usBlockAlign = v13;
  v14 = v13 << 10;
  v15 = AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 8 * v14);
  v4->m_pvAudioBuffer = v15;
  if ( !v15 )
    return 2i64;
  memset(v15, 0, 8 * v14);
  v4->m_ppvRingBuffer[0] = v4->m_pvAudioBuffer;
  v4->m_ppvRingBuffer[1] = (char *)v4->m_pvAudioBuffer + v14;
  v4->m_ppvRingBuffer[2] = (char *)v4->m_pvAudioBuffer + 2 * v14;
  v32 = 32;
  v16 = (char *)v4->m_pvAudioBuffer + 3 * v14;
  v33 = 2097174;
  v4->m_ppvRingBuffer[3] = v16;
  v4->m_ppvRingBuffer[4] = (char *)v4->m_pvAudioBuffer + 4 * v14;
  v4->m_ppvRingBuffer[5] = (char *)v4->m_pvAudioBuffer + 5 * v14;
  v4->m_ppvRingBuffer[6] = (char *)v4->m_pvAudioBuffer + 6 * v14;
  v4->m_ppvRingBuffer[7] = (char *)v4->m_pvAudioBuffer + 7 * v14;
  v17 = v4->m_SpeakersConfig;
  v27 = -2;
  v34 = v17;
  v35 = GUID_00000003_0000_0010_8000_00aa00389b71;
  v29 = AkAudioLibSettings::g_pipelineCoreFrequency;
  v28 = v4->m_ulNumChannels;
  v31 = 4 * v28;
  v18 = *v7;
  v30 = AkAudioLibSettings::g_pipelineCoreFrequency * (unsigned __int16)(4 * v28);
  LODWORD(v26) = (_DWORD)FLOAT_1_0;
  if ( ((signed int (__fastcall *)(IXAudio2 *, IXAudio2SourceVoice **, __int16 *, _QWORD, __int64, IXAudio2VoiceCallbackVtbl **, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))v18->vfptr[2].Release)(
         v18,
         &v4->m_pSourceVoice,
         &v27,
         0i64,
         v26,
         &v4->vfptr,
         0i64,
         0i64,
         *(_QWORD *)&v27,
         *(_QWORD *)&v30,
         *(_QWORD *)&v33,
         *(_QWORD *)&GUID_00000003_0000_0010_8000_00aa00389b71.Data1,
         *(_QWORD *)GUID_00000003_0000_0010_8000_00aa00389b71.Data4) < 0 )
    return 2i64;
  ((void (__fastcall *)(IXAudio2SourceVoice *, __int64, _QWORD))v4->m_pSourceVoice->vfptr->SetVolume)(
    v4->m_pSourceVoice,
    v19,
    0i64);
  v20 = 0i64;
  if ( CAkOutputMgr::m_Devices.m_uLength )
  {
    v21 = &CAkOutputMgr::m_Devices.m_pItems->uDeviceID;
    while ( *v21 )
    {
      v20 = (unsigned int)(v20 + 1);
      v21 += 10;
      if ( (unsigned int)v20 >= CAkOutputMgr::m_Devices.m_uLength )
        goto LABEL_34;
    }
    v22 = &CAkOutputMgr::m_Devices.m_pItems[v20];
    if ( v22 )
    {
      v23 = v22->pSink;
      if ( v23 )
      {
        if ( v23->m_eType == 1 )
        {
          v24 = 0;
          v4->m_uWriteBufferIndex = (unsigned __int16)v23[2].m_pCapture;
          v25 = (volatile int)v23[3].m_MasterOut.pData;
          v4->m_uReadBufferIndex = 0;
          v4->m_uNbBuffersRB = v25;
          if ( v4->m_uNbBuffersRB > 0 )
          {
            do
            {
              CAkSinkXAudio2::SubmitPacketRB(v4);
              ++v24;
            }
            while ( v24 < v4->m_uNbBuffersRB );
          }
        }
      }
    }
  }
LABEL_34:
  if ( CAkSinkXAudio2::s_XAudio2List.m_pFirst )
  {
    v4->pNextLightItem = CAkSinkXAudio2::s_XAudio2List.m_pFirst;
    CAkSinkXAudio2::s_XAudio2List.m_pFirst = v4;
  }
  else
  {
    CAkSinkXAudio2::s_XAudio2List.m_pFirst = v4;
    v4->pNextLightItem = 0i64;
  }
  return 1i64;
}

// File Line: 232
// RVA: 0xA952D0
void __fastcall CAkSinkXAudio2::Term(CAkSinkXAudio2 *this)
{
  CAkSinkXAudio2 *v1; // rbx
  void *v2; // rdx
  CAkSinkXAudio2 *v3; // rdi
  IXAudio2MasteringVoice *v4; // rcx
  IXAudio2 *v5; // rcx
  void *v6; // rdx
  CAkSinkXAudio2 *v7; // rcx

  v1 = this;
  (*(void (**)(void))this->vfptr[1].gap8)();
  v2 = v1->m_MasterOut.pData;
  v3 = 0i64;
  if ( v2 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v2);
    v1->m_MasterOut.pData = 0i64;
  }
  v4 = v1->m_pMasteringVoice;
  if ( v4 )
  {
    ((void (*)(void))v4->vfptr->DestroyVoice)();
    v1->m_pMasteringVoice = 0i64;
  }
  v5 = v1->m_pXAudio2;
  if ( v5 )
  {
    ((void (__fastcall *)(IXAudio2 *, IXAudio2EngineCallbackVtbl **))v5->vfptr[2].AddRef)(v5, &v1->vfptr);
    ((void (*)(void))v1->m_pXAudio2->vfptr->Release)();
    v1->m_pXAudio2 = 0i64;
  }
  v6 = v1->m_pvAudioBuffer;
  if ( v6 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v6);
    v1->m_pvAudioBuffer = 0i64;
  }
  CAkSink::StopOutputCapture((CAkSink *)&v1->vfptr);
  _((AMD_HD3D *)v1);
  v7 = CAkSinkXAudio2::s_XAudio2List.m_pFirst;
  if ( CAkSinkXAudio2::s_XAudio2List.m_pFirst )
  {
    while ( v7 != v1 )
    {
      v3 = v7;
      v7 = v7->pNextLightItem;
      if ( !v7 )
        return;
    }
    if ( v7 )
    {
      if ( v7 == CAkSinkXAudio2::s_XAudio2List.m_pFirst )
        CAkSinkXAudio2::s_XAudio2List.m_pFirst = v7->pNextLightItem;
      else
        v3->pNextLightItem = v7->pNextLightItem;
    }
  }
}

// File Line: 269
// RVA: 0xA95190
__int64 __fastcall CAkSinkXAudio2::Play(CAkSinkXAudio2 *this)
{
  return (unsigned int)(((signed int (__fastcall *)(IXAudio2SourceVoice *, _QWORD, _QWORD))this->m_pSourceVoice->vfptr[1].GetVoiceDetails)(
                          this->m_pSourceVoice,
                          0i64,
                          0i64) < 0)
       + 1;
}

// File Line: 275
// RVA: 0xA951D0
void __fastcall CAkSinkXAudio2::Stop(CAkSinkXAudio2 *this)
{
  CAkSinkXAudio2 *v1; // rbx
  IXAudio2SourceVoice *v2; // rcx

  v1 = this;
  v2 = this->m_pSourceVoice;
  if ( v2 )
  {
    ((void (*)(void))v2->vfptr->DestroyVoice)();
    v1->m_pSourceVoice = 0i64;
  }
  *(_DWORD *)&v1->m_uWriteBufferIndex = 0;
  v1->m_uNbBuffersRB = 0;
  v1->m_ppvRingBuffer[0] = 0i64;
  v1->m_ppvRingBuffer[1] = 0i64;
  v1->m_ppvRingBuffer[2] = 0i64;
  v1->m_ppvRingBuffer[3] = 0i64;
  v1->m_ppvRingBuffer[4] = 0i64;
  v1->m_ppvRingBuffer[5] = 0i64;
  v1->m_ppvRingBuffer[6] = 0i64;
  v1->m_ppvRingBuffer[7] = 0i64;
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
  CAkSinkXAudio2 *v1; // rbx
  __int64 v2; // rdx
  __int64 v3; // rax
  int v4; // [rsp+20h] [rbp-38h]
  int Dst; // [rsp+24h] [rbp-34h]
  __int64 v6; // [rsp+28h] [rbp-30h]

  v1 = this;
  v4 = 0;
  memset(&Dst, 0, 0x28ui64);
  v2 = v1->m_uReadBufferIndex;
  Dst = v1->m_usBlockAlign << 10;
  v3 = (__int64)v1->m_ppvRingBuffer[v2];
  LOWORD(v2) = v2 + 1;
  v1->m_uReadBufferIndex = v2;
  v6 = v3;
  if ( (_WORD)v2 == 8 )
    v1->m_uReadBufferIndex = 0;
  (*(void (__fastcall **)(IXAudio2SourceVoice *, int *, _QWORD))&v1->m_pSourceVoice->vfptr[1].gap8[8])(
    v1->m_pSourceVoice,
    &v4,
    0i64);
}

// File Line: 350
// RVA: 0xA94F90
signed __int64 __fastcall CAkSinkXAudio2::PassData(CAkSinkXAudio2 *this)
{
  signed int v1; // er9
  __m128 *v2; // r8
  __m128 *v3; // rax
  CAkSinkXAudio2 *v4; // rbx
  unsigned __int64 v5; // rdx
  signed __int64 v6; // rcx
  unsigned __int64 v7; // rcx
  signed __int64 v8; // rcx
  void *v9; // rsp
  void *v10; // rsp
  unsigned __int64 v11; // r11
  char *v12; // r10
  __m128 *v13; // rcx
  __m128 v14; // xmm4
  __m128 v15; // xmm3
  __m128i v16; // xmm2
  __m128i v17; // xmm0
  char in_pData; // [rsp+20h] [rbp+0h]

  v1 = this->m_ulNumChannels * this->m_MasterOut.uValidFrames;
  v2 = (__m128 *)this->m_ppvRingBuffer[this->m_uWriteBufferIndex];
  v3 = (__m128 *)this->m_MasterOut.pData;
  v4 = this;
  v5 = (unsigned __int64)v3->m128_u64 + 4 * v1;
  if ( (unsigned __int64)v3 < v5 )
  {
    v6 = (char *)v2 - (char *)v3;
    do
    {
      ++v3;
      *(__m128 *)((char *)v3 + v6 - 16) = _mm_max_ps(vkMin, _mm_min_ps(vkMax, v3[-1]));
    }
    while ( (unsigned __int64)v3 < v5 );
  }
  if ( v4->m_pCapture )
  {
    v7 = 2i64 * v1 + 15;
    if ( v7 <= 2i64 * v1 )
      v7 = 1152921504606846960i64;
    v8 = v7 & 0xFFFFFFFFFFFFFFF0ui64;
    v9 = alloca(v8);
    v10 = alloca(v8);
    v11 = (unsigned __int64)v2->m128_u64 + 4 * v1;
    v12 = &in_pData;
    if ( (unsigned __int64)v2 < v11 )
    {
      v13 = v2 + 3;
      do
      {
        v12 += 32;
        v14 = _mm_mul_ps(v13[-1], (__m128)_xmm);
        v15 = *v13;
        v16 = _mm_cvtps_epi32(_mm_mul_ps(v13[-3], (__m128)_xmm));
        v17 = _mm_cvtps_epi32(_mm_mul_ps(v13[-2], (__m128)_xmm));
        v13 += 4;
        _mm_storeu_si128((__m128i *)v12 - 2, _mm_packs_epi32(v16, v17));
        _mm_storeu_si128(
          (__m128i *)v12 - 1,
          _mm_packs_epi32(_mm_cvtps_epi32(v14), _mm_cvtps_epi32(_mm_mul_ps(v15, (__m128)_xmm))));
      }
      while ( (unsigned __int64)&v13[-3] < v11 );
    }
    AkCaptureFile::PassSampleData(v4->m_pCapture, &in_pData, 2 * v1);
  }
  if ( ++v4->m_uWriteBufferIndex == 8 )
    v4->m_uWriteBufferIndex = 0;
  _InterlockedIncrement(&v4->m_uNbBuffersRB);
  return 1i64;
}

// File Line: 404
// RVA: 0xA950E0
signed __int64 __fastcall CAkSinkXAudio2::PassSilence(CAkSinkXAudio2 *this)
{
  CAkSinkXAudio2 *v1; // rbx
  _OWORD *v2; // r9
  unsigned __int64 v3; // rcx
  AkCaptureFile *v4; // rcx

  v1 = this;
  v2 = this->m_ppvRingBuffer[this->m_uWriteBufferIndex];
  v3 = (unsigned __int64)v2 + 4 * (signed int)(this->m_ulNumChannels << 10);
  if ( (unsigned __int64)v2 < v3 )
  {
    *v2 = 0i64;
    qmemcpy(v2 + 1, v2, 8 * (((v3 - (unsigned __int64)v2 - 1) >> 3) & 0x1FFFFFFFFFFFFFFEi64));
  }
  v4 = v1->m_pCapture;
  if ( v4 )
    AkCaptureFile::PassSampleData(v4, v2, (v1->m_usBlockAlign << 10) / 2);
  if ( ++v1->m_uWriteBufferIndex == 8 )
    v1->m_uWriteBufferIndex = 0;
  _InterlockedIncrement(&v1->m_uNbBuffersRB);
  return 1i64;
}

// File Line: 452
// RVA: 0xA94DC0
__int64 __fastcall CAkSinkXAudio2::IsDataNeeded(CAkSinkXAudio2 *this, unsigned int *out_uBuffersNeeded)
{
  CAkSinkXAudio2 *v2; // rax
  unsigned int v3; // er10

  *out_uBuffersNeeded = 1000;
  v2 = CAkSinkXAudio2::s_XAudio2List.m_pFirst;
  if ( CAkSinkXAudio2::s_XAudio2List.m_pFirst )
  {
    do
    {
      v3 = *out_uBuffersNeeded;
      if ( *out_uBuffersNeeded >= (unsigned __int16)(g_PDSettings.uNumRefillsInVoice - v2->m_uNbBuffersRB) )
        v3 = (unsigned __int16)(g_PDSettings.uNumRefillsInVoice - v2->m_uNbBuffersRB);
      *out_uBuffersNeeded = v3;
      v2 = v2->pNextLightItem;
    }
    while ( v2 );
  }
  return (unsigned int)(this->m_bCriticalError != 0) + 1;
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
  CAkSinkXAudio2 *v2; // rbx
  unsigned int i; // ecx
  __int64 v4; // rcx
  __int64 v5; // rax
  char v6; // [rsp+20h] [rbp-58h]
  unsigned int v7; // [rsp+28h] [rbp-50h]
  __int64 v8; // [rsp+2Ch] [rbp-4Ch]
  int v9; // [rsp+38h] [rbp-40h]
  int Dst; // [rsp+3Ch] [rbp-3Ch]
  __int64 v11; // [rsp+40h] [rbp-38h]

  v2 = this;
  (*(void (__fastcall **)(_QWORD, char *))(**(_QWORD **)&this->m_MasterOut.uMaxFrames + 200i64))(
    *(_QWORD *)&this->m_MasterOut.uMaxFrames,
    &v6);
  if ( v7 < g_PDSettings.uNumRefillsInVoice )
  {
    if ( !v7 && v8 )
      BYTE6(v2->m_ppvRingBuffer[0]) = 1;
    for ( i = v7; LODWORD(v2->m_ppvRingBuffer[0]) != v7; i = v7 )
    {
      v9 = 0;
      memset(&Dst, 0, 0x28ui64);
      v4 = WORD1(v2->vfptr);
      Dst = WORD2(v2->m_ppvRingBuffer[0]) << 10;
      v5 = *((_QWORD *)&v2->vfptr + v4);
      LOWORD(v4) = v4 + 1;
      WORD1(v2->vfptr) = v4;
      v11 = v5;
      if ( (_WORD)v4 == 8 )
        WORD1(v2->vfptr) = 0;
      (*(void (__fastcall **)(_QWORD, int *, _QWORD))(**(_QWORD **)&v2->m_MasterOut.uMaxFrames + 168i64))(
        *(_QWORD *)&v2->m_MasterOut.uMaxFrames,
        &v9,
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

