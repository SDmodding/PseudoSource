// File Line: 51
// RVA: 0xA76670
void __fastcall CAkSink::CAkSink(CAkSink *this, AkSinkType in_eType)
{
  this->vfptr = (CAkSinkVtbl *)&CAkSink::`vftable;
  this->m_pCapture = 0i64;
  this->m_SpeakersConfig = 0;
  this->m_MasterOut.pData = 0i64;
  this->m_eType = in_eType;
}

// File Line: 63
// RVA: 0xA766C0
__int64 __fastcall CAkSink::AllocBuffer(CAkSink *this)
{
  unsigned int m_SpeakersConfig; // eax
  int i; // r8d
  size_t v4; // rsi
  void *v5; // rax
  void *v6; // rdi
  unsigned int v8; // eax

  m_SpeakersConfig = this->m_SpeakersConfig;
  for ( i = 0; m_SpeakersConfig; m_SpeakersConfig &= m_SpeakersConfig - 1 )
    ++i;
  v4 = (unsigned int)(i << 12);
  v5 = AK::MemoryMgr::Malign(g_LEngineDefaultPoolId, (unsigned int)v4, 0x10u);
  v6 = v5;
  if ( !v5 )
    return 52i64;
  memset(v5, 0, v4);
  this->m_MasterOut.pData = 0i64;
  *(_QWORD *)&this->m_MasterOut.eState = 43i64;
  v8 = this->m_SpeakersConfig;
  this->m_MasterOut.pData = v6;
  *(_DWORD *)&this->m_MasterOut.uMaxFrames = 1024;
  this->m_MasterOut.uChannelMask = v8;
  return 1i64;
}

// File Line: 82
// RVA: 0xA76810
CAkSinkDummy *__fastcall CAkSink::CreateInternal(
        AkOutputSettings *in_settings,
        unsigned int in_eType,
        unsigned int in_uInstance)
{
  CAkSinkXAudio2 *v5; // rax
  CAkSinkDirectSound *v6; // rax
  CAkSinkDirectSound *v7; // rdi
  int v9; // ebx
  CAkSinkDirectSound *v10; // rax
  CAkSinkDirectSound *v11; // rax
  int v12; // ebx
  unsigned int m_SpeakersConfig; // ecx

  if ( in_eType <= 1 )
  {
    v5 = (CAkSinkXAudio2 *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0xC8ui64);
    if ( !v5 )
      return 0i64;
    CAkSinkXAudio2::CAkSinkXAudio2(v5);
    v7 = v6;
    if ( !v6 )
      return 0i64;
    if ( ((unsigned int (__fastcall *)(CAkSinkDirectSound *, AkPlatformInitSettings *, _QWORD, _QWORD))v6->vfptr[1].__vecDelDtor)(
           v6,
           &g_PDSettings,
           in_settings->uChannelMask,
           in_eType) == 1 )
      return (CAkSinkDummy *)v7;
    v7->vfptr->Term(v7);
    v9 = g_LEngineDefaultPoolId;
    v7->vfptr->__vecDelDtor(v7, 0);
    AK::MemoryMgr::Free(v9, v7);
  }
  if ( (in_eType & 0xFFFFFFFD) == 0 )
  {
    v10 = (CAkSinkDirectSound *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x68ui64);
    if ( !v10 )
      return 0i64;
    CAkSinkDirectSound::CAkSinkDirectSound(v10);
    v7 = v11;
    if ( !v11 )
      return 0i64;
    if ( CAkSinkDirectSound::Init(v11, &g_PDSettings, in_settings->uChannelMask) == AK_Success )
      return (CAkSinkDummy *)v7;
    v7->vfptr->Term(v7);
    v12 = g_LEngineDefaultPoolId;
    v7->vfptr->__vecDelDtor(v7, 0);
    AK::MemoryMgr::Free(v12, v7);
  }
  if ( in_eType != 3 )
    return 0i64;
  if ( !in_settings->uChannelMask )
  {
    if ( g_pAkSink )
    {
      m_SpeakersConfig = g_pAkSink->m_SpeakersConfig;
      in_settings->uChannelMask = m_SpeakersConfig;
      return CAkSink::CreateDummy(m_SpeakersConfig);
    }
    in_settings->uChannelMask = 3;
  }
  return CAkSink::CreateDummy(in_settings->uChannelMask);
}

// File Line: 196
// RVA: 0xA76760
// attributes: thunk
CAkSink *__fastcall CAkSink::Create(AkOutputSettings *in_settings, AkSinkType in_eType, unsigned int in_uInstance)
{
  return CAkSink::CreateInternal(in_settings, in_eType, in_uInstance);
}

// File Line: 209
// RVA: 0xA76770
CAkSinkDummy *__fastcall CAkSink::CreateDummy(unsigned int in_uChannelMask)
{
  CAkSinkDummy *result; // rax
  CAkSink *v3; // rdi
  int v4; // ebx

  result = (CAkSinkDummy *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x48ui64);
  v3 = result;
  if ( result )
  {
    result->m_pCapture = 0i64;
    result->m_SpeakersConfig = 0;
    result->m_MasterOut.pData = 0i64;
    result->m_eType = AkSink_Dummy;
    result->vfptr = (CAkSinkVtbl *)&CAkSinkDummy::`vftable;
    if ( CAkSinkDummy::Init(result, in_uChannelMask) != AK_Success )
    {
      v3->vfptr->Term(v3);
      v4 = g_LEngineDefaultPoolId;
      v3->vfptr->__vecDelDtor(v3, 0);
      AK::MemoryMgr::Free(v4, v3);
      return 0i64;
    }
    return (CAkSinkDummy *)v3;
  }
  return result;
}

// File Line: 301
// RVA: 0xA76C30
void __fastcall CAkSink::StartOutputCapture(CAkSink *this, const wchar_t *in_CaptureFileName)
{
  unsigned int m_SpeakersConfig; // eax
  unsigned __int16 i; // r8
  unsigned int v6; // ebx
  AkCaptureMgr *v7; // rax

  if ( !this->m_pCapture )
  {
    m_SpeakersConfig = this->m_SpeakersConfig;
    for ( i = 0; m_SpeakersConfig; m_SpeakersConfig &= m_SpeakersConfig - 1 )
      ++i;
    v6 = i;
    v7 = AkCaptureMgr::Instance();
    this->m_pCapture = AkCaptureMgr::StartCapture(
                         v7,
                         in_CaptureFileName,
                         v6,
                         AkAudioLibSettings::g_pipelineCoreFrequency,
                         0x10u,
                         Int16);
  }
}

// File Line: 319
// RVA: 0xA76CB0
void __fastcall CAkSink::StopOutputCapture(CAkSink *this)
{
  AkCaptureFile *m_pCapture; // rcx

  m_pCapture = this->m_pCapture;
  if ( m_pCapture )
  {
    AkCaptureFile::StopCapture(m_pCapture);
    this->m_pCapture = 0i64;
  }
}

// File Line: 336
// RVA: 0xA76960
__int64 __fastcall CAkSinkDummy::Init(CAkSinkDummy *this, unsigned int in_uChannels)
{
  unsigned int v4; // edx
  __int16 v5; // cx
  int i; // ecx
  unsigned __int64 v7; // rsi
  void *v8; // rax
  void *v9; // rbx
  unsigned int m_SpeakersConfig; // eax

  this->m_Timer = GetTickCount();
  this->m_SpeakersConfig = in_uChannels;
  v4 = in_uChannels;
  v5 = 0;
  for ( this->m_dwMSPerBuffer = (int)(1000.0 / ((double)(int)AkAudioLibSettings::g_pipelineCoreFrequency * 0.0009765625));
        v4;
        v4 &= v4 - 1 )
  {
    ++v5;
  }
  this->m_usBlockAlign = 2 * v5;
  for ( i = 0; in_uChannels; in_uChannels &= in_uChannels - 1 )
    ++i;
  v7 = (unsigned int)(i << 12);
  v8 = AK::MemoryMgr::Malign(g_LEngineDefaultPoolId, v7, 0x10u);
  v9 = v8;
  if ( !v8 )
    return 52i64;
  memset(v8, 0, v7);
  this->m_MasterOut.pData = 0i64;
  *(_QWORD *)&this->m_MasterOut.eState = 43i64;
  m_SpeakersConfig = this->m_SpeakersConfig;
  this->m_MasterOut.pData = v9;
  *(_DWORD *)&this->m_MasterOut.uMaxFrames = 1024;
  this->m_MasterOut.uChannelMask = m_SpeakersConfig;
  return 1i64;
}

// File Line: 369
// RVA: 0xA76CE0
void __fastcall CAkSinkDummy::Term(CAkSinkDummy *this)
{
  void *pData; // rdx
  AkCaptureFile *m_pCapture; // rcx

  pData = this->m_MasterOut.pData;
  if ( pData )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, pData);
    this->m_MasterOut.pData = 0i64;
  }
  m_pCapture = this->m_pCapture;
  if ( m_pCapture )
  {
    AkCaptureFile::StopCapture(m_pCapture);
    this->m_pCapture = 0i64;
  }
}

// File Line: 396
// RVA: 0xA76A50
__int64 __fastcall CAkSinkDummy::IsDataNeeded(CAkSinkDummy *this, unsigned int *out_uBuffersNeeded)
{
  unsigned int TickCount; // eax
  unsigned int m_Timer; // edx
  unsigned int v6; // ecx
  unsigned int v8; // eax

  TickCount = GetTickCount();
  m_Timer = this->m_Timer;
  v6 = TickCount;
  if ( TickCount >= m_Timer )
  {
    v8 = (TickCount - m_Timer) / this->m_dwMSPerBuffer;
    *out_uBuffersNeeded = v8;
    if ( v8 )
      this->m_Timer = v6;
    return 1i64;
  }
  else
  {
    *out_uBuffersNeeded = 1;
    this->m_Timer = TickCount;
    return 1i64;
  }
}

// File Line: 418
// RVA: 0xA76AB0
__int64 __fastcall CAkSinkDummy::PassData(CAkSinkDummy *this)
{
  unsigned int uChannelMask; // edx
  __m128 *pData; // rbx
  int i; // r8d
  int v5; // edx
  __int64 v6; // r8
  __int64 v7; // rcx
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

  uChannelMask = this->m_MasterOut.uChannelMask;
  pData = (__m128 *)this->m_MasterOut.pData;
  for ( i = 0; uChannelMask; uChannelMask &= uChannelMask - 1 )
    ++i;
  v5 = i * this->m_MasterOut.uValidFrames;
  v6 = (unsigned int)(2 * v5);
  if ( this->m_pCapture )
  {
    v7 = v6 + 15;
    if ( v6 + 15 <= (unsigned __int64)(unsigned int)v6 )
      v7 = 0xFFFFFFFFFFFFFF0i64;
    v8 = v7 & 0xFFFFFFFFFFFFFFF0ui64;
    v9 = alloca(v8);
    v10 = alloca(v8);
    v11 = (unsigned __int64)pData->m128_u64 + 4 * v5;
    p_in_pData = &in_pData;
    if ( (unsigned __int64)pData < v11 )
    {
      v13 = pData + 3;
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
    AkCaptureFile::PassSampleData(this->m_pCapture, &in_pData, v6);
  }
  return 1i64;
}

// File Line: 440
// RVA: 0xA76BB0
__int64 __fastcall CAkSinkDummy::PassSilence(CAkSinkDummy *this)
{
  __int64 v2; // rdi
  __int64 v3; // rax
  void *v4; // rsp
  char Dst; // [rsp+20h] [rbp+0h] BYREF

  v2 = this->m_usBlockAlign << 10;
  if ( this->m_pCapture )
  {
    v3 = v2 + 15;
    if ( v2 + 15 <= (unsigned __int64)(unsigned int)v2 )
      v3 = 0xFFFFFFFFFFFFFF0i64;
    v4 = alloca(v3 & 0xFFFFFFFFFFFFFFF0ui64);
    memset(&Dst, 0, (unsigned int)v2);
    AkCaptureFile::PassSampleData(this->m_pCapture, &Dst, v2);
  }
  return 1i64;
}

