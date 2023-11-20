// File Line: 51
// RVA: 0xA76670
void __fastcall CAkSink::CAkSink(CAkSink *this, AkSinkType in_eType)
{
  this->vfptr = (CAkSinkVtbl *)&CAkSink::`vftable';
  this->m_pCapture = 0i64;
  this->m_SpeakersConfig = 0;
  this->m_MasterOut.pData = 0i64;
  this->m_eType = in_eType;
}

// File Line: 63
// RVA: 0xA766C0
signed __int64 __fastcall CAkSink::AllocBuffer(CAkSink *this)
{
  unsigned int v1; // eax
  CAkSink *v2; // rbx
  int i; // er8
  size_t v4; // rsi
  void *v5; // rax
  void *v6; // rdi
  unsigned int v8; // eax

  v1 = this->m_SpeakersConfig;
  v2 = this;
  for ( i = 0; v1; v1 &= v1 - 1 )
    ++i;
  v4 = (unsigned int)(i << 12);
  v5 = AK::MemoryMgr::Malign(g_LEngineDefaultPoolId, (unsigned int)v4, 0x10u);
  v6 = v5;
  if ( !v5 )
    return 52i64;
  memset(v5, 0, v4);
  v2->m_MasterOut.pData = 0i64;
  *(_QWORD *)&v2->m_MasterOut.eState = 43i64;
  v8 = v2->m_SpeakersConfig;
  v2->m_MasterOut.pData = v6;
  *(_DWORD *)&v2->m_MasterOut.uMaxFrames = 1024;
  v2->m_MasterOut.uChannelMask = v8;
  return 1i64;
}

// File Line: 82
// RVA: 0xA76810
CAkSinkDummy *__fastcall CAkSink::CreateInternal(AkOutputSettings *in_settings, AkSinkType in_eType, unsigned int in_uInstance)
{
  AkSinkType v3; // ebp
  AkOutputSettings *v4; // rsi
  CAkSinkXAudio2 *v5; // rax
  CAkSinkDirectSound *v6; // rax
  CAkSinkDirectSound *v7; // rdi
  int v9; // ebx
  CAkSinkDirectSound *v10; // rax
  CAkSinkDirectSound *v11; // rax
  int v12; // ebx
  unsigned int v13; // ecx

  v3 = in_eType;
  v4 = in_settings;
  if ( (unsigned int)in_eType <= 1 )
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
           v4->uChannelMask,
           (unsigned int)v3) == 1 )
      return (CAkSinkDummy *)v7;
    v7->vfptr->Term((CAkSink *)&v7->vfptr);
    v9 = g_LEngineDefaultPoolId;
    v7->vfptr->__vecDelDtor((CAkSink *)&v7->vfptr, 0);
    AK::MemoryMgr::Free(v9, v7);
  }
  if ( !(v3 & 0xFFFFFFFD) )
  {
    v10 = (CAkSinkDirectSound *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x68ui64);
    if ( !v10 )
      return 0i64;
    CAkSinkDirectSound::CAkSinkDirectSound(v10);
    v7 = v11;
    if ( !v11 )
      return 0i64;
    if ( CAkSinkDirectSound::Init(v11, &g_PDSettings, v4->uChannelMask) == 1 )
      return (CAkSinkDummy *)v7;
    v7->vfptr->Term((CAkSink *)&v7->vfptr);
    v12 = g_LEngineDefaultPoolId;
    v7->vfptr->__vecDelDtor((CAkSink *)&v7->vfptr, 0);
    AK::MemoryMgr::Free(v12, v7);
  }
  if ( v3 != 3 )
    return 0i64;
  if ( !v4->uChannelMask )
  {
    if ( g_pAkSink )
    {
      v13 = g_pAkSink->m_SpeakersConfig;
      v4->uChannelMask = v13;
      return CAkSink::CreateDummy(v13);
    }
    v4->uChannelMask = 3;
  }
  return CAkSink::CreateDummy(v4->uChannelMask);
}

// File Line: 196
// RVA: 0xA76760
CAkSink *__fastcall CAkSink::Create(AkOutputSettings *in_settings, AkSinkType in_eType, unsigned int in_uInstance)
{
  return CAkSink::CreateInternal(in_settings, in_eType, in_uInstance);
}

// File Line: 209
// RVA: 0xA76770
CAkSinkDummy *__fastcall CAkSink::CreateDummy(unsigned int in_uChannelMask)
{
  unsigned int v1; // ebx
  CAkSinkDummy *result; // rax
  CAkSink *v3; // rdi
  int v4; // ebx

  v1 = in_uChannelMask;
  result = (CAkSinkDummy *)AK::MemoryMgr::Malloc(g_LEngineDefaultPoolId, 0x48ui64);
  v3 = (CAkSink *)&result->vfptr;
  if ( result )
  {
    result->m_pCapture = 0i64;
    result->m_SpeakersConfig = 0;
    result->m_MasterOut.pData = 0i64;
    result->m_eType = 3;
    result->vfptr = (CAkSinkVtbl *)&CAkSinkDummy::`vftable';
    if ( CAkSinkDummy::Init(result, v1) != 1 )
    {
      v3->vfptr->Term(v3);
      v4 = g_LEngineDefaultPoolId;
      v3->vfptr->__vecDelDtor(v3, 0);
      AK::MemoryMgr::Free(v4, v3);
      v3 = 0i64;
    }
    result = (CAkSinkDummy *)v3;
  }
  return result;
}

// File Line: 301
// RVA: 0xA76C30
void __fastcall CAkSink::StartOutputCapture(CAkSink *this, const wchar_t *in_CaptureFileName)
{
  const wchar_t *v2; // rsi
  CAkSink *v3; // rdi
  unsigned int v4; // eax
  unsigned __int16 i; // r8
  unsigned int v6; // ebx
  AkCaptureMgr *v7; // rax

  v2 = in_CaptureFileName;
  v3 = this;
  if ( !this->m_pCapture )
  {
    v4 = this->m_SpeakersConfig;
    for ( i = 0; v4; v4 &= v4 - 1 )
      ++i;
    v6 = i;
    v7 = AkCaptureMgr::Instance();
    v3->m_pCapture = AkCaptureMgr::StartCapture(v7, v2, v6, AkAudioLibSettings::g_pipelineCoreFrequency, 0x10u, Int16);
  }
}

// File Line: 319
// RVA: 0xA76CB0
void __fastcall CAkSink::StopOutputCapture(CAkSink *this)
{
  CAkSink *v1; // rbx
  AkCaptureFile *v2; // rcx

  v1 = this;
  v2 = this->m_pCapture;
  if ( v2 )
  {
    AkCaptureFile::StopCapture(v2);
    v1->m_pCapture = 0i64;
  }
}

// File Line: 336
// RVA: 0xA76960
signed __int64 __fastcall CAkSinkDummy::Init(CAkSinkDummy *this, unsigned int in_uChannels)
{
  unsigned int v2; // ebx
  CAkSinkDummy *v3; // rdi
  unsigned int v4; // edx
  __int16 v5; // cx
  int i; // ecx
  unsigned __int64 v7; // rsi
  void *v8; // rax
  void *v9; // rbx
  unsigned int v11; // eax

  v2 = in_uChannels;
  v3 = this;
  this->m_Timer = GetTickCount();
  v3->m_SpeakersConfig = v2;
  v4 = v2;
  v5 = 0;
  for ( v3->m_dwMSPerBuffer = (signed int)(1000.0
                                         / ((double)(signed int)AkAudioLibSettings::g_pipelineCoreFrequency
                                          * 0.0009765625)); v4; v4 &= v4 - 1 )
    ++v5;
  v3->m_usBlockAlign = 2 * v5;
  for ( i = 0; v2; v2 &= v2 - 1 )
    ++i;
  v7 = (unsigned int)(i << 12);
  v8 = AK::MemoryMgr::Malign(g_LEngineDefaultPoolId, v7, 0x10u);
  v9 = v8;
  if ( !v8 )
    return 52i64;
  memset(v8, 0, v7);
  v3->m_MasterOut.pData = 0i64;
  *(_QWORD *)&v3->m_MasterOut.eState = 43i64;
  v11 = v3->m_SpeakersConfig;
  v3->m_MasterOut.pData = v9;
  *(_DWORD *)&v3->m_MasterOut.uMaxFrames = 1024;
  v3->m_MasterOut.uChannelMask = v11;
  return 1i64;
}

// File Line: 369
// RVA: 0xA76CE0
void __fastcall CAkSinkDummy::Term(CAkSinkDummy *this)
{
  void *v1; // rdx
  CAkSinkDummy *v2; // rbx
  AkCaptureFile *v3; // rcx

  v1 = this->m_MasterOut.pData;
  v2 = this;
  if ( v1 )
  {
    AK::MemoryMgr::Free(g_LEngineDefaultPoolId, v1);
    v2->m_MasterOut.pData = 0i64;
  }
  v3 = v2->m_pCapture;
  if ( v3 )
  {
    AkCaptureFile::StopCapture(v3);
    v2->m_pCapture = 0i64;
  }
}

// File Line: 396
// RVA: 0xA76A50
signed __int64 __fastcall CAkSinkDummy::IsDataNeeded(CAkSinkDummy *this, unsigned int *out_uBuffersNeeded)
{
  unsigned int *v2; // rdi
  CAkSinkDummy *v3; // rbx
  DWORD v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // ecx
  signed __int64 result; // rax
  unsigned int v8; // eax

  v2 = out_uBuffersNeeded;
  v3 = this;
  v4 = GetTickCount();
  v5 = v3->m_Timer;
  v6 = v4;
  if ( v4 >= v5 )
  {
    v8 = (v4 - v5) / v3->m_dwMSPerBuffer;
    *v2 = v8;
    if ( v8 )
      v3->m_Timer = v6;
    result = 1i64;
  }
  else
  {
    *v2 = 1;
    v3->m_Timer = v4;
    result = 1i64;
  }
  return result;
}

// File Line: 418
// RVA: 0xA76AB0
signed __int64 __fastcall CAkSinkDummy::PassData(CAkSinkDummy *this)
{
  unsigned int v1; // edx
  __m128 *v2; // rbx
  int v3; // er8
  CAkSinkDummy *i; // r9
  int v5; // edx
  __int64 v6; // r8
  signed __int64 v7; // rcx
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

  v1 = this->m_MasterOut.uChannelMask;
  v2 = (__m128 *)this->m_MasterOut.pData;
  v3 = 0;
  for ( i = this; v1; v1 &= v1 - 1 )
    ++v3;
  v5 = v3 * this->m_MasterOut.uValidFrames;
  v6 = (unsigned int)(2 * v5);
  if ( this->m_pCapture )
  {
    v7 = v6 + 15;
    if ( v6 + 15 <= (unsigned __int64)(unsigned int)v6 )
      v7 = 1152921504606846960i64;
    v8 = v7 & 0xFFFFFFFFFFFFFFF0ui64;
    v9 = alloca(v8);
    v10 = alloca(v8);
    v11 = (unsigned __int64)v2->m128_u64 + 4 * v5;
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
    AkCaptureFile::PassSampleData(i->m_pCapture, &in_pData, v6);
  }
  return 1i64;
}

// File Line: 440
// RVA: 0xA76BB0
signed __int64 __fastcall CAkSinkDummy::PassSilence(CAkSinkDummy *this)
{
  CAkSinkDummy *v1; // rsi
  __int64 v2; // rdi
  signed __int64 v3; // rax
  void *v4; // rsp
  char Dst; // [rsp+20h] [rbp+0h]

  v1 = this;
  v2 = (unsigned int)this->m_usBlockAlign << 10;
  if ( this->m_pCapture )
  {
    v3 = v2 + 15;
    if ( v2 + 15 <= (unsigned __int64)(unsigned int)v2 )
      v3 = 1152921504606846960i64;
    v4 = alloca(v3);
    memset(&Dst, 0, (unsigned int)v2);
    AkCaptureFile::PassSampleData(v1->m_pCapture, &Dst, v2);
  }
  return 1i64;
}

